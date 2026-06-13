// Giants Engine - Audio System (Sound Driver Loader)
// Reverse engineered from GiantsMain.exe v1.520.59
//
// FUN_0062af40 — Loads sound driver DLL (gs_*.dll) via GetProcAddress.
// NOT Miles Sound System — this is the game's SDV (Sound Driver) plugin interface.

#pragma once

#include <cstdint>
#include <windows.h>

namespace Giants {

// ─── SDV (Sound Driver) function pointer interface ─────────────
// All loaded via GetProcAddress from gs_*.dll

typedef int (__cdecl *SDVInitFunc)();
typedef int (__cdecl *SDVFinitFunc)();
typedef int (__cdecl *SDVPauseFunc)();
typedef int (__cdecl *SDVResumeFunc)();
typedef int (__cdecl *SDVSilenceFunc)();
typedef int (__cdecl *SDVProcessFunc)();
typedef int (__cdecl *SDVPreLoadFunc)(const char*);
typedef int (__cdecl *SDVUnLoadFunc)();
typedef int (__cdecl *SDVStopObjectFunc)(int);
typedef int (__cdecl *SDVStopSampleFunc)(int);
typedef int (__cdecl *SDVStopInstanceFunc)(int);

// ─── InitAudioSystem (FUN_0062af40) — FAIL (usable ~60%) ───────
// Loads a sound driver DLL (gs_<name>.dll) and resolves all SDV* exports.
// Falls back to loading without path prefix if first attempt fails.
// @param path  Optional DLL directory prefix (can be nullptr)
// @param name  Sound driver name (forms gs_<name>.dll)
// @return 1 on success, 0 on failure
int InitAudioSystem(const char* path, uint32_t name);  // FUN_0062af40

} // namespace Giants
