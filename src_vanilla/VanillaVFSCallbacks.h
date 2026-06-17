// Giants Vanilla-Native Recomp — Engine→Renderer VFS open callbacks (15/16/17).
//
// Ports the 3 vanilla engine VFS-open callbacks that the renderer receives via
// UpCallsLoad(0x2775, 21, table):
//
//   idx 15  VFSOpenFileVariant   FUN_006222d0  __cdecl HANDLE (char* path)
//   idx 16  VFSOpenMusicFile     FUN_00621fe0  __cdecl HANDLE (int  fileId)
//   idx 17  VFSOpenFile          FUN_00621e50  __cdecl HANDLE (char* path)
//
// AUTHORITY (anti-dérive): every global/DAT_ and callee address below is cited
// from the decompiled vanilla bodies preserved verbatim in
// `src/renderer/RendererLoader.cpp` lines 243-508 (Ghidra 12.1.2 decompile of
// GiantsMain.exe 1.520.59, cross-checked against the proxy detour table at
// proxy/proxy_main.cpp:201-216 which names the same 3 addresses). The vanilla
// decompiled JSONs for 0x62xxxx are NOT present in vanilla_decompiled/ (the
// exporter stopped at 0x551c50); these bodies are the authoritative source.
//
// CONTRACT: all three return a Win32 HANDLE from CreateFileA (GENERIC_READ,
// FILE_SHARE_READ, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL|FILE_FLAG_RANDOM_ACCESS
// = 0x8000080). The engine then reads the handle with the Win32 file API
// directly (ReadFile / SetFilePointer) — NOT the engine FUN_0051d7xx table.
// INVALID_HANDLE_VALUE (0xFFFFFFFF) is mapped to NULL on return, matching the
// vanilla `if (pvVar4 != (HANDLE)0xffffffff) goto ok; pvVar4 = (HANDLE)0x0;`
// pattern at 0x00621f6c / 0x00622390.
//
// GZP RESOLUTION: the vanilla resolver (FUN_00623f00 / FUN_00624a10) transparently
// serves files that live inside .gzp archives. We honor that by extracting the
// resolved GZP entry to a temp file and returning a real CreateFileA handle on
// it, so the engine's Win32 read path works unchanged. Loose files are opened
// in place (the vanilla behavior).
#pragma once
#include <cstdint>
#include <windows.h>

extern "C" {
    // callback[17] VFSOpenFile — vanilla FUN_00621e50.
    //   HANDLE FUN_00621e50(char* param_1)
    // Resolves `path` (loose file under Bin\, else any Bin\*.gzp entry by basename),
    // then CreateFileA on the resolved target. Returns NULL on failure.
    void* __cdecl cbVFSOpenFile(const char* path);

    // callback[16] VFSOpenMusicFile — vanilla FUN_00621fe0.
    //   HANDLE FUN_00621fe0(int param_1)
    // 4-iteration search-path loop over the music search-path table, CreateFileA
    // per candidate. `fileId` selects the music track (vanilla arg index 0).
    void* __cdecl cbVFSOpenMusicFile(int fileId);

    // callback[15] VFSOpenFileVariant — vanilla FUN_006222d0.
    //   HANDLE FUN_006222d0(char* path)   (decompiled body marks param unused,
    //   resolution pulls from a global via FUN_00624a10; we accept the path for
    //   symmetry with [17] and to be robust if the renderer actually passes one)
    // Same shape as cbVFSOpenFile but uses the alternate VFS resolver
    // (FUN_00624a10 / FUN_006242d0).
    void* __cdecl cbVFSOpenFileVariant(const char* path);
}

namespace VanillaVFSCallbacks {
// Self-test: open a known GZP-resident file ("dmlarge000.tga" in
// "Bin\xx_intro.gzp") through cbVFSOpenFile and ReadFile a few bytes to prove the
// returned HANDLE is a real readable Win32 handle. Logs to g_vTrace. Returns 1
// on success, 0 on failure.
int SelfTest();
} // namespace VanillaVFSCallbacks
