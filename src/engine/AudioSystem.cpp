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

// ─── SDV/MDV function pointers (resolved at runtime from gs_*.dll) ──
// Full export list extracted from FUN_0062af40 decompilation (37 SDV + 4 MDV).
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
static FARPROC g_sdvStart3DObj = nullptr;
static FARPROC g_sdvStart3DPos = nullptr;
static FARPROC g_sdvStart2DSample = nullptr;
static FARPROC g_sdvSetVolumeInstance = nullptr;
static FARPROC g_sdvSetVolPCTInstance = nullptr;
static FARPROC g_sdvSoundFastIsPlayingInst = nullptr;
static FARPROC g_sdvGetInstance = nullptr;
static FARPROC g_sdvGetMinMaxDistances = nullptr;
static FARPROC g_sdvSetGlobalVolume = nullptr;
static FARPROC g_sdvSetGlobalControlF = nullptr;
static FARPROC g_sdvSetGlobalControlI = nullptr;
static FARPROC g_sdvGetGlobalVolume = nullptr;
static FARPROC g_sdvGetGlobalControlF = nullptr;
static FARPROC g_sdvGetGlobalControlI = nullptr;
static FARPROC g_sdvGetListenerPosition = nullptr;
static FARPROC g_sdvGetTime = nullptr;
static FARPROC g_sdvCalcVolume = nullptr;
static FARPROC g_sdvWantLoadOccludes = nullptr;
static FARPROC g_sdvOcclusionBox = nullptr;
static FARPROC g_sdvDestroyOcclusionBox = nullptr;
static FARPROC g_sdvDestroyOcclusionBoxSet = nullptr;
static FARPROC g_sdvUpdateOcclusionBox = nullptr;
static FARPROC g_sdvOcclusionParms = nullptr;
static FARPROC g_sdvHWLoadWorld = nullptr;
static FARPROC g_sdvUpCallsLoad = nullptr;
// MDV (music driver) exports
static FARPROC g_mdvInit = nullptr;
static FARPROC g_mdvProcess = nullptr;
static FARPROC g_mdvPlaySong = nullptr;
static FARPROC g_mdvStopSong = nullptr;

static HMODULE g_audioModule = nullptr;     // handle to the loaded gs_*.dll
static uint32_t g_exitFlag = 0;              // DAT_007281e4

// ─── Helper: resolve SDV/MDV exports from a loaded module ──────
// Per FUN_0062af40: SDVInit + SDVFinit are mandatory (return false if either
// is missing, unless g_exitFlag is set). All other exports are resolved
// best-effort (may legitimately be absent in some driver variants).
static bool LoadSdvExports(HMODULE hModule)
{
    g_sdvInit = GetProcAddress(hModule, "SDVInit");
    if (g_sdvInit == nullptr) return (g_exitFlag != 0) ? true : false;

    g_sdvFinit = GetProcAddress(hModule, "SDVFinit");
    if (g_sdvFinit == nullptr) return (g_exitFlag != 0) ? true : false;

    // Best-effort resolution of the remaining exports.
    g_sdvPause                   = GetProcAddress(hModule, "SDVPause");
    g_sdvResume                  = GetProcAddress(hModule, "SDVResume");
    g_sdvSilence                 = GetProcAddress(hModule, "SDVSilence");
    g_sdvProcess                 = GetProcAddress(hModule, "SDVProcess");
    g_sdvPreLoad                 = GetProcAddress(hModule, "SDVPreLoad");
    g_sdvUnLoad                  = GetProcAddress(hModule, "SDVUnLoad");
    g_sdvStopObject              = GetProcAddress(hModule, "SDVStopObject");
    g_sdvStopSample              = GetProcAddress(hModule, "SDVStopSample");
    g_sdvStopInstance            = GetProcAddress(hModule, "SDVStopInstance");
    g_sdvStart3DObj              = GetProcAddress(hModule, "SDVStart3DObj");
    g_sdvStart3DPos              = GetProcAddress(hModule, "SDVStart3DPos");
    g_sdvStart2DSample           = GetProcAddress(hModule, "SDVStart2DSample");
    g_sdvSetVolumeInstance       = GetProcAddress(hModule, "SDVSetVolumeInstance");
    g_sdvSetVolPCTInstance       = GetProcAddress(hModule, "SDVSetVolPCTInstance");
    g_sdvSoundFastIsPlayingInst  = GetProcAddress(hModule, "SDVSoundFastIsPlayingInst");
    g_sdvGetInstance             = GetProcAddress(hModule, "SDVGetInstance");
    g_sdvGetMinMaxDistances      = GetProcAddress(hModule, "SDVGetMinMaxDistances");
    g_sdvSetGlobalVolume         = GetProcAddress(hModule, "SDVSetGlobalVolume");
    g_sdvSetGlobalControlF       = GetProcAddress(hModule, "SDVSetGlobalControlF");
    g_sdvSetGlobalControlI       = GetProcAddress(hModule, "SDVSetGlobalControlI");
    g_sdvGetGlobalVolume         = GetProcAddress(hModule, "SDVGetGlobalVolume");
    g_sdvGetGlobalControlF       = GetProcAddress(hModule, "SDVGetGlobalControlF");
    g_sdvGetGlobalControlI       = GetProcAddress(hModule, "SDVGetGlobalControlI");
    g_sdvGetListenerPosition     = GetProcAddress(hModule, "SDVGetListenerPosition");
    g_sdvGetTime                 = GetProcAddress(hModule, "SDVGetTime");
    g_sdvCalcVolume              = GetProcAddress(hModule, "SDVCalcVolume");
    g_sdvWantLoadOccludes        = GetProcAddress(hModule, "SDVWantLoadOccludes");
    g_sdvOcclusionBox            = GetProcAddress(hModule, "SDVOcclusionBox");
    g_sdvDestroyOcclusionBox     = GetProcAddress(hModule, "SDVDestroyOcclusionBox");
    g_sdvDestroyOcclusionBoxSet  = GetProcAddress(hModule, "SDVDestroyOcclusionBoxSet");
    g_sdvUpdateOcclusionBox      = GetProcAddress(hModule, "SDVUpdateOcclusionBox");
    g_sdvOcclusionParms          = GetProcAddress(hModule, "SDVOcclusionParms");
    g_sdvHWLoadWorld             = GetProcAddress(hModule, "SDVHWLoadWorld");
    g_sdvUpCallsLoad             = GetProcAddress(hModule, "SDVUpCallsLoad");
    // MDV (music driver) exports.
    g_mdvInit                    = GetProcAddress(hModule, "MDVInit");
    g_mdvProcess                 = GetProcAddress(hModule, "MDVProcess");
    g_mdvPlaySong                = GetProcAddress(hModule, "MDVPlaySong");
    g_mdvStopSong                = GetProcAddress(hModule, "MDVStopSong");

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
            g_audioModule = hModule;
            bool ok = LoadSdvExports(hModule);
            extern FILE* g_traceLog;
            if (g_traceLog) { fprintf(g_traceLog, "[AUDIO] loaded %s (SDVInit=%p exports %s)\n", dllName, (void*)g_sdvInit, ok ? "OK" : "PARTIAL"); fflush(g_traceLog); }
            return ok ? 1 : 0;
        }
    }

    // Fallback: try "gs_<name>.dll" without path
    sprintf(dllName, "gs_%s", reinterpret_cast<const char*>(name));
    HMODULE hModule = GetModuleHandleA(dllName);
    if (hModule == nullptr) {
        hModule = LoadLibraryA(dllName);
    }
    if (hModule == nullptr) {
        extern FILE* g_traceLog;
        if (g_traceLog) { fprintf(g_traceLog, "[AUDIO] FAILED to load %s\n", dllName); fflush(g_traceLog); }
        return 0;
    }

    g_audioModule = hModule;
    bool ok = LoadSdvExports(hModule);
    extern FILE* g_traceLog;
    if (g_traceLog) { fprintf(g_traceLog, "[AUDIO] loaded %s (SDVInit=%p exports %s)\n", dllName, (void*)g_sdvInit, ok ? "OK" : "PARTIAL"); fflush(g_traceLog); }
    return ok ? 1 : 0;
}

} // namespace Giants
