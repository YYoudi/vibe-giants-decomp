// Giants Engine - Audio System Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
//
// FUN_0062af40 — Sound Driver (SDV) DLL loader.
// The game uses a plugin architecture for audio: gs_*.dll exports SDV* functions.
#include <cstdlib>
#include <cstring>
#include "AudioSystem.h"
#include <cstdio>
#include <windows.h>

namespace Giants {

// ─── SDV function pointers (resolved at runtime) ──────────────
static FARPROC g_sdvInit = nullptr;
static FARPROC g_sdvFinit = nullptr;
static FARPROC g_sdvPause = nullptr;
static FARPROC g_sdvResume = nullptr;
static FARPROC g_sdvSilence = nullptr;
static FARPROC g_sdvProcess = nullptr;
static FARPROC g_sdvPreLoad = nullptr;
static FARPROC g_sdvUnLoad = nullptr;
static FARPROC g_sdvStopObject = nullptr;
static FARPROC g_sdvStopSample = nullptr;
static FARPROC g_sdvStopInstance = nullptr;

static uint32_t g_exitFlag = 0;              // DAT_007281e4

// ─── Helper: resolve SDV exports from a loaded module ──────────
static bool LoadSdvExports(HMODULE hModule)
{
    g_sdvInit = GetProcAddress(hModule, "SDVInit");
    if (g_sdvInit == nullptr) return (g_exitFlag != 0) ? true : false;

    g_sdvFinit = GetProcAddress(hModule, "SDVFinit");
    if (g_sdvFinit == nullptr) return (g_exitFlag != 0) ? true : false;

    g_sdvPause = GetProcAddress(hModule, "SDVPause");
    g_sdvResume = GetProcAddress(hModule, "SDVResume");
    g_sdvSilence = GetProcAddress(hModule, "SDVSilence");
    g_sdvProcess = GetProcAddress(hModule, "SDVProcess");
    g_sdvPreLoad = GetProcAddress(hModule, "SDVPreLoad");
    g_sdvUnLoad = GetProcAddress(hModule, "SDVUnLoad");
    g_sdvStopObject = GetProcAddress(hModule, "SDVStopObject");
    g_sdvStopSample = GetProcAddress(hModule, "SDVStopSample");
    g_sdvStopInstance = GetProcAddress(hModule, "SDVStopInstance");

    // ~10 more SDV* exports follow (SDVPlay, SDVSetVolume, etc.)
    // Ghidra shows ~20+ GetProcAddress calls in cascade
    return true;
}

// ─── InitAudioSystem (FUN_0062af40) — FAIL (usable ~60%) ───────

int InitAudioSystem(const char* path, uint32_t name)
{
    char dllName[512];

    // Try with path prefix first: "<path>\gs_<name>.dll"
    if (path != nullptr && *path != '\0')
    {
        sprintf(dllName, "%s\\gs_%s", path, reinterpret_cast<const char*>(name));
        HMODULE hModule = GetModuleHandleA(dllName);
        if (hModule == nullptr) {
            hModule = LoadLibraryA(dllName);
        }
        if (hModule != nullptr) {
            return LoadSdvExports(hModule) ? 1 : 0;
        }
    }

    // Fallback: try "gs_<name>.dll" without path
    sprintf(dllName, "gs_%s", reinterpret_cast<const char*>(name));
    HMODULE hModule = GetModuleHandleA(dllName);
    if (hModule == nullptr) {
        hModule = LoadLibraryA(dllName);
    }
    if (hModule == nullptr) return 0;

    return LoadSdvExports(hModule) ? 1 : 0;
}

} // namespace Giants
