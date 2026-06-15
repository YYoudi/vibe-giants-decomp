// Giants Engine - Text Rendering Pipeline
// Reverse engineered from GiantsMain.exe v1.520.59
//
// The text-render bridge: GDI renders glyphs into a monochrome DIB (created by
// InitDisplayMode / FUN_0062b9c0), FontMetricExtractGlyph (FUN_0062be70) extracts
// per-glyph metrics, then DrawTextExecute (FUN_0062c420) uploads the glyph atlas
// as a texture to the renderer (vtable[50]) and draws a textured quad per char.
//
// Renderer vtable calls (g_renderDevice = DAT_00702700):
//   vtable[50] (offset 0xC8) = UploadTexture(textureDesc*) — thiscall, arg=&DAT_0074bee0
//   vtable[ 9] (offset 0x24) = (begin text batch?) — thiscall, no args
//   device1 (DAT_0070270c) vtable[1] (offset 0x04) = DrawPrimitive — thiscall

#include <cstdint>
#include <cstdio>
#include <cstring>
#include <windows.h>
#include "DisplayMode.h"

namespace Giants {

// ─── Text-render globals (DAT_ addresses; some shared with DisplayMode.cpp) ──
static uint32_t DAT_0074bee0[16] = {0};   // glyph atlas texture descriptor (opaque)
static uint32_t DAT_0074bed0 = 0;         // texture dirty flag
extern void*    g_renderDevice;           // DAT_00702700 (EngineInit.cpp)

// FontMetricExtractChar = public per-glyph entry (forwards to FUN_0062be70 body).
extern void FontMetricExtractChar(int glyph);

// ─── DrawTextPrepare (FUN_0062c1b0) — REAL decompiled body ─────
// Ensures the GDI font is initialized and all glyph metrics for the string are
// extracted. SAFE: pure GDI, no renderer calls.
void DrawTextPrepare(char* str)
{
    InitDisplayMode();               // FUN_0062b9c0 — ensure font loaded
    char c = *str;
    while (c != '\0') {
        FontMetricExtractChar((int)(uint8_t)c);  // FUN_0062be70 — extract glyph metric
        str++;
        c = *str;
    }
}

// ─── DrawTextExecute (FUN_0062c420) — REAL decompiled body (structural) ─
// Draws a string of glyphs as textured quads. color = ARGB, str = bytes,
// yScale = Y position scale, len = length.
// The renderer vtable calls (upload texture vtable[50], begin batch vtable[9],
// device1 quad-draw vtable[1]) require the full engine-context protocol; left
// guarded until the renderer protocol is reconstructed.
void DrawTextExecute(uint32_t color, const char* str, float yScale, int len)
{
    extern FILE* g_traceLog;
    DrawTextPrepare(const_cast<char*>(str));   // FUN_0062c1b0 — GDI prepare + metrics

    if (g_renderDevice == nullptr) {
        if (g_traceLog) { fprintf(g_traceLog, "[TEXT-RENDER] no render device, skipping\n"); fflush(g_traceLog); }
        return;
    }

    void** vtable = *reinterpret_cast<void***>(g_renderDevice);
    if (g_traceLog) {
        fprintf(g_traceLog, "[TEXT-RENDER] device=%p vtable=%p slots[50]=%p [9]=%p — color=0x%08X str=\"%.*s\" len=%d yScale=%.2f\n",
                g_renderDevice, vtable, vtable ? vtable[50] : nullptr, vtable ? vtable[9] : nullptr,
                color, len > 32 ? 32 : len, str, len, yScale);
        fflush(g_traceLog);
    }

    // FINDING (tested 2026-06-15): calling renderer vtable[9] (begin text batch,
    // thiscall no-args) CRASHES at renderer+0x1DB3B. Even the simplest renderer
    // method crashes without the full engine-context protocol (UpCallsLoad + the
    // 22 engine→renderer callbacks + state). So text cannot display by calling the
    // real gg_dx9r.dll directly — the engine-context MUST be driven first, OR a
    // stub renderer must be substituted. The vtable slots ARE resolved (logged),
    // so the path is known; only the context-setup is missing.
    // typedef void (__attribute__((thiscall)) *PFN_BeginBatch)();
    // reinterpret_cast<PFN_BeginBatch>(vtable[9])();  // CRASHES — left disabled

    // ORIGINAL behavior (FUN_0062c420): if texture dirty, re-upload via vtable[50]
    // (thiscall, arg=&DAT_0074bee0); call vtable[9] (thiscall, no args); then per-char
    // quad dispatch via FUN_0062c1e0(x, y, charCode) using device1 vtable[1].
    // These renderer calls crash without the engine-context protocol — guarded out
    // until that's reconstructed. The vtable slots ARE resolved (logged above).
    if (DAT_0074bed0 != 0) {
        DAT_0074bed0 = 0;  // cleared on (would-be) upload
    }
    (void)vtable;
}

} // namespace Giants
