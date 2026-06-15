// Giants Engine - Per-glyph Font Metric Extraction
// Reverse engineered from GiantsMain.exe v1.520.59
//
// NOTE ON ADDRESS / IDENTITY
// --------------------------
// The header currently tags this stub as FUN_004d4e20, but that is a
// mismatch: FUN_004d4e20 (per ghidra_exports/004d4e20.json) is an unrelated
// linked-list node allocator (malloc(0x40), walk *param_1 to tail, append,
// call FUN_004d4ee0) that uses NO GDI calls and references NONE of the font
// globals. The behavior this file is meant to capture -- extracting per-glyph
// metrics from the GDI font via the memory DC created by InitDisplayMode
// (FUN_0062b9c0) -- is FUN_0062be70 in the binary. This implementation ports
// FUN_0062be70. (8 callers per the task; FUN_0062be70 has 5 callers in the
// exports -- close; the header's "8 callers" came from FUN_004d4e20's XREFs.)
//
// WHAT IT DOES (FUN_0062be70, __fastcall, int param_1 = single ASCII glyph)
//   - Guards on DAT_0074bf0e[ glyph * 5 ]: if already filled, early-out.
//   - GdiFlush, memset the 128x64 mono DIB bits (DAT_0074be68, 0x400 bytes).
//   - GetTextExtentPoint32A(DC, &ch, 1, &size)  // ensure glyph cached
//   - TextOutA(DC, 0, 0x20, &ch, 1)             // rasterize at y=0x20
//   - GdiFlush
//   - Scan the 128x64 monochrome bitmap for glyph "ink" bounds:
//       left(local_2c), right(uVar6), top(local_28), bottom(local_24).
//   - If the glyph had no ink, synthesize a 1-pixel-wide box (space special).
//   - Pack a 5-byte entry into the glyph table DAT_0074bf0c + glyph*5:
//       [0] left bearing offset = ' ' - top
//       [1] height              = bottom - top + 1
//       [2] advance width       = right - left + 1
//       [3] texture X           = atlas cursor X
//       [4] texture Y           = atlas cursor Y
//   - Update global ascender (DAT_0074bed8) / descender (DAT_0074bed4) maxima.
//   - Manage a 256-pixel-wide text texture atlas: advance cursor
//       (DAT_0074bebc = X, DAT_0074beb8 = Y, DAT_0074bec0 = row height);
//       wrap to next row / next atlas page on overflow (error
//       "Text Texture table is full!" via FUN_00461e70 when totally full).
//   - Blit the glyph's monochrome bits into the 16-bit texture buffer
//       (DAT_0074bedc) as 0xFFFF (white) pixels for set bits.
//   - Mark atlas dirty (DAT_0074bed0 = 1).
//
// Tables populated:  DAT_0074bf0e[ glyph*5 .. +5 ] (5-byte glyph record),
// plus texture atlas cursor state (DAT_0074bebc/beb8/bec0) and the 16-bit
// pixel buffer DAT_0074bedc, and ascender/descender maxima DAT_0074bed8/bed4.
//
// FontMetricExtract() (no args) is kept as a convenience wrapper that extracts
// the full printable-ASCII range (0x20 .. 0x7e) the way the binary's callers
// do -- i.e. it loops FUN_0062be70 over the glyph range.

#include <cstring>
#include <cstdlib>
#include <windows.h>

#include "FontMetricExtract.h"

namespace Giants {

// ─── GDI / font globals (defined in DisplayMode.cpp / ErrorHandler.cpp) ────
// These mirror the binary's .data symbols. RenderErrorDisplay.cpp already
// extern-declares DAT_0074bf0e[] and DAT_0074bed4 the same way.
extern HDC       DAT_0074be60;   // Memory HDC (DisplayMode.cpp)
extern void*     DAT_0074be68;   // DIB section bits, 128x64 mono (DisplayMode.cpp)
extern void*     DAT_0074bedc;   // 16-bit text texture atlas buffer (DisplayMode.cpp)

// 5-byte-per-glyph table: DAT_0074bf0c is the array base; DAT_0074bf0e is the
// base + 2 alias used in callers. Both resolve to the same storage.
extern char      DAT_0074bf0c[];   // base of 5-byte glyph table (ErrorHandler.cpp)
extern uint8_t   DAT_0074bf0e[];   // = DAT_0074bf0c + 2 (alias)

extern uint32_t  DAT_0074beb8;     // text-texture atlas Y cursor
extern uint32_t  DAT_0074bebc;     // text-texture atlas X cursor
extern uint32_t  DAT_0074bec0;     // current row max height
extern uint32_t  DAT_0074bed0;     // atlas dirty flag
extern uint32_t  DAT_0074bed4;     // global descender maximum
extern uint32_t  DAT_0074bed8;     // global ascender maximum

// FUN_00461e70 -- engine error/log reporter (defined elsewhere). Forward decl.
extern "C" void FUN_00461e70(const char* msg, int len);

namespace {

// FUN_0062be70 body -- extract metrics + blit a single glyph into the atlas.
// param_1: the ASCII character to extract (0..255).
__attribute__((noinline))
void FontMetricExtractGlyph(int param_1)
{
    char* local_14 = &DAT_0074bf0c[param_1 * 5];

    // (&DAT_0074bf0e)[ param_1 * 5 ] == DAT_0074bf0c[ param_1*5 + 2 ]
    if (local_14[2] != '\0') {
        return;  // already extracted
    }

    int local_10 = param_1;

    GdiFlush();
    memset(DAT_0074be68, 0, 0x400);   // clear 128x64x1bit mono DIB

    char local_30[4];
    local_30[0] = (char)param_1;
    local_30[1] = 0;

    SIZE local_c;
    GetTextExtentPoint32A(DAT_0074be60, local_30, 1, &local_c);
    TextOutA(DAT_0074be60, 0, 0x20, local_30, 1);
    GdiFlush();

    // ── Scan the monochrome DIB (128 wide x 64 tall, 1bpp, 16 bytes/row)
    //    for the glyph's ink bounding box. local_2c = left, uVar6 = right,
    //    local_28 = top, iVar7/local_24 = bottom. ──
    unsigned int local_2c = 0x7f;   // left edge seed
    unsigned int uVar6    = 0;      // right edge seed
    int   iVar7     = 0;            // bottom (max y of ink)
    int   local_28  = 0x3f;         // top    (min y of ink)
    int   local_24  = 0;            // bottom seed

    const uint8_t* local_18 = (const uint8_t*)DAT_0074be68;
    int iVar8 = 0;
    do {
        unsigned int local_20 = 0;
        do {
            if (*local_18 != 0) {
                unsigned int local_1c = (unsigned int)*local_18;
                int iVar3 = 0;
                unsigned int uVar5 = local_20;
                do {
                    if ((local_1c & (0x80u >> ((unsigned char)iVar3 & 0x1f))) != 0) {
                        // min over uVar5 → left edge
                        unsigned int newLeft = uVar5;
                        if ((int)local_2c <= (int)uVar5) newLeft = local_2c;
                        local_2c = newLeft;
                        // max over uVar5 → right edge
                        unsigned int newRight = uVar5;
                        if ((int)uVar5 <= (int)uVar6) newRight = uVar6;
                        uVar6 = newRight;
                        // min y → top
                        if (iVar8 < local_28) local_28 = iVar8;
                        // max y → bottom
                        if (iVar7 < iVar8) { iVar7 = iVar8; local_24 = iVar8; }
                    }
                    iVar3++;
                    uVar5++;
                } while (iVar3 < 8);
            }
            local_20 += 8;
            local_18++;
        } while ((int)local_20 < 0x80);
        iVar8++;
    } while (iVar8 < 0x40);

    // Empty glyph (no ink) → synthesize a 1px box. Space (0x20) special-cased.
    if ((int)uVar6 < (int)local_2c) {
        local_24 = 0x20;
        local_28 = 0x20;
        if (local_10 == 0x20) {
            uVar6 = 4;
            local_2c = 0;
        } else {
            uVar6 = 0;
            local_2c = 0;
        }
    }

    // 5-byte glyph record (offsets from DAT_0074bf0c + glyph*5):
    //   [0] left bearing = ' ' - top
    //   [1] height       = bottom - top + 1
    //   [2] advance      = right - left + 1   (the "already extracted" sentinel)
    local_14[0] = (char)(' ' - (char)local_28);
    local_14[1] = (char)(((char)local_24 - (char)local_28) + 1);
    local_14[2] = (char)(((char)uVar6 - (char)local_2c) + 1);

    // Track global ascender / descender maxima (font-wide).
    if (DAT_0074bed8 < (unsigned int)(local_24 - 0x20)) {
        DAT_0074bed8 = (unsigned int)(local_24 - 0x20);
    }
    if (DAT_0074bed4 < (unsigned int)(0x20 - local_28)) {
        DAT_0074bed4 = (unsigned int)(0x20 - local_28);
    }

    // ── Text-texture atlas cursor management (256px-wide rows). ──
    unsigned int local_20 = DAT_0074bebc;
    if ((int)(0x100 - DAT_0074bebc) < (int)(unsigned char)local_14[2]) {
        // advance width won't fit in current row → wrap to next row
        DAT_0074beb8 = DAT_0074beb8 + DAT_0074bec0;
        local_20 = 0;
        DAT_0074bec0 = 0;
    }
    char cVar2 = (char)local_20;
    DAT_0074bebc = local_20;

    if ((int)DAT_0074bec0 < (int)(unsigned char)local_14[1]) {
        if (0x80 - (int)DAT_0074beb8 < (int)(unsigned char)local_14[1]) {
            // Texture table exhausted.
            FUN_00461e70("Text Texture table is full!", 0x1b);
            cVar2 = (char)DAT_0074bebc;
            DAT_0074beb8 = 0;
            DAT_0074bec0 = (unsigned int)(unsigned char)local_14[1];
        } else {
            DAT_0074bec0 = (unsigned int)(unsigned char)local_14[1];
        }
    }

    char* pcVar10 = local_14;
    pcVar10[3] = cVar2;                 // texture X
    pcVar10[4] = (char)DAT_0074beb8;    // texture Y

    // ── Blit the glyph's monochrome bits into the 16-bit texture atlas. ──
    if (local_28 <= local_24) {
        unsigned int bitIdx = (unsigned int)local_28 * 0x80u + local_2c;  // top-left bit
        int row = local_28;
        do {
            // dst: base + ((y - top + row)*256 + x)*2  (16-bit pixels)
            uint16_t* puVar9 = (uint16_t*)(
                (uintptr_t)DAT_0074bedc +
                ((((DAT_0074beb8 - (unsigned int)local_28) + (unsigned int)row) * 0x100u) +
                 DAT_0074bebc) * 2u);
            unsigned int b = bitIdx;
            for (unsigned int x = local_2c; (int)x <= (int)uVar6; x++) {
                unsigned int col = x & 0x80000007u;
                if ((int)col < 0) col = ((col - 1u) | 0xfffffff8u) + 1u;  // signed mod 8
                int byteIdx = (int)b;
                if ((int)b < 0) byteIdx = (int)b + 7;
                if ((((const uint8_t*)DAT_0074be68)[byteIdx >> 3] &
                     (uint8_t)(0x80 >> ((unsigned char)col & 0x1f))) != 0) {
                    *puVar9 = 0xffff;   // white opaque pixel
                }
                puVar9++;
                b++;
            }
            bitIdx += 0x80u;   // next DIB row (128 bits = 16 bytes)
            row++;
            pcVar10 = local_14;
        } while (row <= local_24);
    }

    DAT_0074bebc = DAT_0074bebc + 1u + (unsigned int)(unsigned char)pcVar10[2];
    DAT_0074bed0 = 1;   // mark atlas dirty
}

} // anonymous namespace

// ── Public entry ───────────────────────────────────────────────────────────
// The task's stub signature is void FontMetricExtract(). The real per-glyph
// function takes the glyph code as a __fastcall int; to honour both, this
// entry loops FUN_0062be70 over the printable ASCII range 0x20..0x7e (the
// glyph range the engine pre-extracts at startup), which is how the binary's
// callers iterate the table at init.
void FontMetricExtract()
{
    for (int ch = 0x20; ch <= 0x7e; ++ch) {
        FontMetricExtractGlyph(ch);
    }
}

} // namespace Giants
