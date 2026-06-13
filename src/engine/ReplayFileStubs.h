// Giants Engine - Replay File & TGA Loading Stubs
// Reverse engineered from GiantsMain.exe v1.520.59
//
// FUN_00624b60 — OpenReplayFile: opens a file via VFS, returns HANDLE
// FUN_0062f700 — ReplayFrameTick: advance replay frame + RenderDoc capture
// FUN_005e9b20 — LoadTgaTexture: loads TGA file into tiled texture data

#pragma once

#include <cstdint>
#include <windows.h>

namespace Giants {

// ─── OpenReplayFile (FUN_00624b60) — PASS ───────────────────────
// Opens the Giants data file via VFS (FUN_00622930 + FUN_00624a10 + FUN_006242d0).
// The VFS path is built from a std::string, then passed to CreateFileA
// with GENERIC_READ, FILE_SHARE_READ, OPEN_EXISTING.
// Returns HANDLE on success, NULL on failure.
// 15 callers, 8 callees (VFS init, file open, string cleanup).
HANDLE OpenReplayFile();  // FUN_00624b60

// ─── ReplayFrameTick (FUN_0062f700) — PASS ──────────────────────
// Advances one replay frame: begins scene, executes replay command
// (FUN_004daaf0), ends scene, checks for RenderDoc F12 capture trigger.
// 6 callers, 5 callees.
void ReplayFrameTick(int param_1);  // FUN_0062f700

// ─── LoadTgaTexture (FUN_005e9b20) — FAIL (usable ~70%) ────────
// Loads a TGA image file from VFS, splits it into tiles of configurable
// size (max 128x128), and creates a tiled texture array.
// Supports TRUECOLOR (24bpp) with optional 8bpp alpha, and COLORMAPPED.
// Returns 1 on success, 0 on failure.
// 4 callers, 7 callees.
uint32_t LoadTgaTexture(
    uint32_t param_1,       // texture name/format
    uint32_t* outWidth,     // output: texture width
    uint32_t* outHeight,    // output: texture height
    uint32_t param_4,       // max tile width (from vtable[0xD4](3))
    uint32_t param_5        // max tile height (from vtable[0xD4](4))
);  // FUN_005e9b20

// ─── ReadFileFromVFS (FUN_00622400) — FAIL (usable ~65%) ────────
// Thread-safe VFS file reader with mutex. Handles both disk files
// and packed (compressed) files. Sets busy flag during I/O.
// 9 callers, 24 callees.
/// @param param_1  Cookie/security value
/// @param param_2  Output: buffer pointer (receives malloc'd data)
/// @param param_3  Output: data size
void ReadFileFromVFS(uint32_t param_1, uint32_t* param_2, DWORD* param_3);  // FUN_00622400

// ─── VFS_GetFileInfo (FUN_006242d0) — PASS ──────────────────────
// Resolves VFS file path by formatting "%s\%s" with VFS base path.
/// @param param_1  Output SSO string (6 uint32_t buffer)
/// @param param_2  Filename string context
/// @return param_1
uint32_t* VFS_GetFileInfo(uint32_t* param_1, int param_2);  // FUN_006242d0

// ─── VFS_LookupFile (FUN_00624910) — PASS ──────────────────────
// Looks up file in VFS by name. Copies to SSO string, queries twice.
/// @param param_1  Filename (null-terminated)
/// @return File info pointer, or 0 if not found
int VFS_LookupFile(char* param_1);  // FUN_00624910

// ─── VFS_FileExists (FUN_00624a10) — PASS ──────────────────────
// Checks VFS file existence via FNV-1a hash lookup. Normalizes path,
/// computes hash, searches table. Returns file data or 0.
/// @param param_1  Filename (null-terminated)
/// @return File data pointer (+0x20 offset), or 0 if not found
uint32_t VFS_FileExists(char* param_1);  // FUN_00624a10

// ─── ReplayCommandDispatch (FUN_004daaf0) — FAIL (usable ~60%) ──
// Renders replay frame tiles: queries max tile size, iterates 2D grid,
/// computes UV mapping with XOR depth obfuscation, submits quads.
/// @param param_1  Context/width parameter
/// @param param_2  Render flags
/// @param param_3  Tile data array (0 = skip)
void ReplayCommandDispatch(int param_1, uint32_t param_2, int param_3);  // FUN_004daaf0

} // namespace Giants
