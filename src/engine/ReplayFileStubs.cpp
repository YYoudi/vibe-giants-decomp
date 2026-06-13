// Giants Engine - Replay File & TGA Loading Stubs Implementation
// Reverse engineered from GiantsMain.exe v1.520.59

#include "ReplayFileStubs.h"
#include "CRTStubs.h"

#include <cstdlib>
#include <cstring>

namespace Giants {

// ─── External globals ───────────────────────────────────────────

extern void* g_renderDevice;      // DAT_00702700 — primary renderer COM object
extern void* g_renderDocAPI;      // DAT_0074bbb8 — RenderDoc API pointer
extern int   g_sceneReady;        // DAT_00702770

// VFS function pointers
extern "C" void __cdecl VFS_Initialize();
extern "C" int  VFS_FileExists();       // FUN_00624a10
extern "C" void* VFS_GetFileInfo();     // FUN_006242d0

// ═══════════════════════════════════════════════════════════════════
// OpenReplayFile — FUN_00624b60
// ═══════════════════════════════════════════════════════════════════

HANDLE OpenReplayFile()
{
    // ── Step 1: Initialize VFS ──────────────────────────────────
    // FUN_00622930(cookie) — VFS initialize with security cookie

    // ── Step 2: Check if file exists ────────────────────────────
    // FUN_00624a10() — returns non-zero if file exists
    // If not found, return NULL

    // ── Step 3: Get file path from VFS ──────────────────────────
    // FUN_006242d0() — returns string info structure
    // Copy path into local SSO string (FUN_004439b0 + move semantics)
    // The path is a std::string with SSO (small string optimization)

    // ── Step 4: Open file ───────────────────────────────────────
    // CreateFileA(path, GENERIC_READ, FILE_SHARE_READ, NULL,
    //             OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL)
    // If returns INVALID_HANDLE_VALUE, set to NULL

    // ── Step 5: Cleanup local string ────────────────────────────
    // If string was heap-allocated (capacity > 15), free it
    // via CRT_InternalFree

    return nullptr;  // Stub
}

// ═══════════════════════════════════════════════════════════════════
// ReplayFrameTick — FUN_0062f700
// ═══════════════════════════════════════════════════════════════════

void ReplayFrameTick(int param_1)
{
    // ── Step 1: Begin scene ─────────────────────────────────────
    // vtable[0xAC](0) — renderer begin scene
    // FUN_004f7e60() — BeginScene (ref-counted)

    // ── Step 2: Execute replay command ──────────────────────────
    // FUN_004daaf0(local, *(param_1 + 0x90)) — replay command dispatch

    // ── Step 3: End scene ───────────────────────────────────────
    // FUN_004f7f10() — ShutdownSubsystems (ref-counted)

    // ── Step 4: RenderDoc capture check ─────────────────────────
    if (g_renderDocAPI != nullptr)
    {
        uint16_t keyState = GetAsyncKeyState(0x7B);  // F12
        if ((keyState & 1) != 0 && g_renderDocAPI != nullptr)
        {
            // Trigger RenderDoc capture
            // (*(code**)(g_renderDocAPI + 0x3C))()
            // FUN_00461f00("RenderDoc: frame capture triggered", 0x22)
        }
    }

    // ── Step 5: Present ─────────────────────────────────────────
    // vtable[0xBC]() — renderer present/end frame
    // (Ghidra: indirect jump — too many branches to recover)
}

// ═══════════════════════════════════════════════════════════════════
// LoadTgaTexture — FUN_005e9b20
// ═══════════════════════════════════════════════════════════════════
// Loads a TGA image and creates a tiled texture array.
// The tiling splits the image into blocks of at most (param_4 x param_5) pixels.

uint32_t LoadTgaTexture(
    uint32_t param_1,
    uint32_t* outWidth,
    uint32_t* outHeight,
    uint32_t param_4,
    uint32_t param_5)
{
    // ── Step 1: Query max tile size from renderer ───────────────
    // iVar2 = vtable[0xD4](3) — max tile width (clamped to 128)
    // iStack_100 = vtable[0xD4](4) — max tile height (clamped to 128)

    // ── Step 2: Build filename ──────────────────────────────────
    // FUN_00463000(buffer, "%s.tga", param_1) — format filename

    // ── Step 3: Open file via VFS ───────────────────────────────
    // FUN_00624910() — VFS file check
    // If not found: return 0

    // ── Step 4: Read TGA header ─────────────────────────────────
    // FUN_00622400() — read file into memory
    // Parse TGA header:
    //   byte 0: ID length
    //   byte 1: color map type
    //   byte 2: image type (2=TRUECOLOR, 1=COLORMAPPED)
    //   bytes 3-7: color map spec
    //   bytes 8-11: x/y origin
    //   bytes 12-15: width (uint16), height (uint16)
    //   byte 16: pixel depth (24 or 32 bpp)
    //   byte 17: image descriptor

    // ── Step 5: Validate format ─────────────────────────────────
    // Only supports TRUECOLOR (type 2) and COLORMAPPED (type 1)
    // Only supports 24bpp (RGB) with optional 8bpp alpha, or 32bpp (RGBA)
    // If unsupported: error message, DAT_007282bc = 1, return 0

    // ── Step 6: Decode pixel data ───────────────────────────────
    // Handle ID field skip, color map skip
    // For 24bpp: allocate width*height*3 buffer, memcpy
    // For 32bpp: allocate width*height*4 buffer, memcpy with alpha

    // ── Step 7: Tile the texture ────────────────────────────────
    // Compute tile grid: tilesX = (width + maxTileW - 1) / maxTileW
    //                     tilesY = (height + maxTileH - 1) / maxTileH
    // Allocate tile array: tilesX * tilesY * 0x2C bytes per tile
    // For each tile:
    //   Allocate pixel buffer (bytesPerPixel * tileW * tileH)
    //   Copy source pixels into tile buffer (row by row, flipped Y)
    //   Set tile metadata: width, height, format, alpha flag

    // ── Step 8: Output results ──────────────────────────────────
    // *outWidth = originalWidth
    // *outHeight = originalHeight
    // *outTilesCount = tilesX * tilesY
    // *outTileArray = tile data

    return 0;  // Stub: failure
}

// ═══════════════════════════════════════════════════════════════════
// ReadFileFromVFS — FUN_00622400
// ═══════════════════════════════════════════════════════════════════
// Thread-safe VFS file reader with mutex (DAT_00685860). Initializes VFS
// (FUN_00622930), queries file info (FUN_00624910), then either:
//   - Non-packed file: resolves path via FUN_00625570, CreateFileA, ReadFile
//   - Packed file: decompresses via FUN_00490b90/FUN_00490ae0
// Sets DAT_0074bbc0 during I/O (busy flag), DAT_0074bbbc = 4.0f (version?).
// On failure: logs error via FUN_0042fda0/FUN_0062edc0.
// 9 callers (all VFS readers), 24 callees.

void ReadFileFromVFS(uint32_t param_1, uint32_t* param_2, DWORD* param_3)
{
    // Original:
    // _Mtx_lock(&DAT_00685860);  // mutex acquire
    // FUN_00622930(cookie);       // VFS init
    // *param_3 = 0;               // out size = 0
    // DAT_0074bbbc = 0x41200000;  // 10.0f? version marker
    // *param_2 = 0;               // out buffer = null
    // DAT_0074bbc0 = 1;           // busy flag
    //
    // piVar2 = FUN_00624910();    // find file in VFS
    // if (piVar2 == NULL) { error; goto cleanup; }
    //
    // if (*piVar2 == 0) {  // non-packed: file on disk
    //     Resolve path via FUN_00625570
    //     hFile = CreateFileA(path, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, ...)
    //     SetFilePointer(hFile, 0, NULL, FILE_CURRENT) → save position
    //     SetFilePointer(hFile, 0, NULL, FILE_END) → get size
    //     Restore position, ReadFile entire content
    //     CloseHandle(hFile)
    // } else {  // packed file: decompress
    //     Ensure decompressor initialized (FUN_00490b90)
    //     Allocate buffer, decompress via FUN_00490ae0
    // }
    //
    // DAT_0074bbc0 = 0;  // clear busy flag
    // _Mtx_unlock(&DAT_00685860);  // mutex release
}

// ═══════════════════════════════════════════════════════════════════
// VFS_GetFileInfo — FUN_006242d0
// ═══════════════════════════════════════════════════════════════════
// Gets VFS file info for a filename string. Calls FUN_00623b00 to get VFS path,
// then formats full path as "%s\\%s" via FUN_00444db0. Returns SSO string
// in param_1 (6 uint32_t: inline buffer + capacity + size + flag).
// If path is empty, initializes empty SSO string. Falls back to FUN_004431a0
// for parent directory extraction.
// 3 callers (file open pipeline), 4 callees.

uint32_t* VFS_GetFileInfo(uint32_t* param_1, int param_2)
{
    // Original:
    // local_20 = FUN_00623b00();  // get VFS path
    // if (local_20 == NULL) {
    //     *param_1 = 0; param_1[1..4] = 0; param_1[5] = 0xf;
    //     return param_1;  // empty SSO string
    // }
    // local_18 = param_2 + 4;  // string pointer
    // if (*local_20 == '\0') { FUN_004431a0(local_18); return param_1; }
    // Format: "%s\\%s" with FUN_00444db0(0xCC, 0, &local_20)
    return param_1;
}

// ═══════════════════════════════════════════════════════════════════
// VFS_LookupFile — FUN_00624910
// ═══════════════════════════════════════════════════════════════════
// Looks up a file in VFS by name. Copies filename via FUN_00442eb0,
// then calls FUN_00625a30 twice (first attempt + retry). Returns pointer
// to file info structure or NULL. Some unreachable blocks from dead code.
// 6 callers (all VFS users), 5 callees.

int VFS_LookupFile(char* param_1)
{
    // Original:
    // pcVar4 = param_1;
    // do { cVar1 = *pcVar4++; } while (cVar1 != '\0');  // strlen
    // FUN_00442eb0(param_1, strlen);  // SSO string assign
    // iVar3 = FUN_00625a30(cookie);   // lookup attempt 1
    // if (iVar3 == 0) iVar3 = FUN_00625a30(cookie);  // retry
    // return iVar3;
    return 0;  // Stub
}

// ═══════════════════════════════════════════════════════════════════
// VFS_FileExists — FUN_00624a10
// ═══════════════════════════════════════════════════════════════════
// Checks if a file exists in VFS. Copies filename to SSO string (FUN_00442eb0),
// normalizes path (FUN_004431a0), computes FNV-1a hash over string data,
// looks up hash in table (FUN_00627080). Returns DAT_0073c8e0 sentinel
// if not found, otherwise returns the file data pointer (+0x20).
// 4 callers (file open pipeline), 8 callees.

uint32_t VFS_FileExists(char* param_1)
{
    // Original:
    // Initialize local_3c[7] SSO string (6 uint32_t + cookie)
    // Copy param_1 via FUN_00442eb0
    // Normalize path via FUN_004431a0
    // Compute FNV-1a hash: uVar7 = 0x811c9dc5; for each byte: hash = (byte ^ hash) * 0x1000193
    // FUN_00627080(hash) — lookup in hash table
    // if not found: return 0
    // else: return *(uint32_t*)(entry + 0x20)
    return 0;  // Stub
}

// ═══════════════════════════════════════════════════════════════════
// ReplayCommandDispatch — FUN_004daaf0
// ═══════════════════════════════════════════════════════════════════
// Dispatches replay render commands: queries renderer for max tile dimensions
// (vtable[0xD4](3) and vtable[0xD4](4), clamped to 128), then iterates a
// 2D grid of render tiles. For each tile, computes UV coordinates from
// world-space mapping, issues vtable calls to submit quads with texture coords.
// Uses XOR depth key (DAT_0066c580) for depth obfuscation.
// 3 callers (ReplayFrameTick, render pipeline), 1 callee.

void ReplayCommandDispatch(int param_1, uint32_t param_2, int param_3)
{
    // Original:
    // iVar1 = vtable[0xD4](3);  // max tile width
    // iVar2 = vtable[0xD4](4);  // max tile height
    // if (iVar1 > 0x80) iVar1 = 0x80;  // clamp to 128
    // if (iVar2 > 0x80) iVar2 = 0x80;
    // if (param_3 == 0) return;  // no data to render
    //
    // Compute grid: iVar3 = (param_1 - 1 + iVar1) / iVar1
    // Iterate grid: for each tile:
    //   Compute UV coords from world position + depth
    //   vtable[0x54](2, 0) — begin tile batch
    //   For each row/col in tile:
    //     Compute screen coords and UV mapping
    //     vtable[4](renderDev, 0x62064, tileData) — submit quad
    //     vtable[8](renderDev, 4) — get vertex buffer
    //     Write 6 vertices (2 triangles) with position + UV
    //     FUN_0061f8f0(tileData) — flush
    //   vtable[0x54](0, 0) — end tile batch
}

} // namespace Giants
