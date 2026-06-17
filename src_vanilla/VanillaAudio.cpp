// Giants Vanilla-Native Recomp — audio loader (FUN_0051f900 port). See VanillaAudio.h.
#include "VanillaAudio.h"
#include <cstdio>
#include <cstring>

extern FILE* g_vTrace;

static AudioExports g_audio = {};

static FARPROC resolve(HMODULE m, const char* name) {
    FARPROC p = GetProcAddress(m, name);
    if (!p) {
        if (g_vTrace) { fprintf(g_vTrace, "[VAUDIO] missing export: %s\n", name); fflush(g_vTrace); }
    }
    return p;
}

#define R(field, name) { FARPROC p = resolve(m, name); g_audio.totalCount++; if (p) { g_audio.field = p; g_audio.resolvedCount++; } else ok = false; }

namespace VanillaAudio {

bool Load(const char* backend) {
    char dll[64];
    snprintf(dll, sizeof(dll), "gs_%s.dll", backend);   // vanilla: "%s_gs_%s" with empty prefix → gs_<backend>.dll
    HMODULE m = GetModuleHandleA(dll);
    if (!m) m = LoadLibraryA(dll);
    if (!m) {
        if (g_vTrace) { fprintf(g_vTrace, "[VAUDIO] failed to load %s\n", dll); fflush(g_vTrace); }
        return false;
    }
    g_audio.module = m;
    g_audio.resolvedCount = 0;
    g_audio.totalCount = 0;
    bool ok = true;
    // Full export set resolved by FUN_0051f900 (vanilla_decompiled/0051f900.json). The
    // "Failed to load <name>" strings enumerate the exact names; resolve each faithfully.
    // Sound (SDV*)
    R(SDVCalcVolume,           "SDVCalcVolume");
    R(SDVDestroyOcclusionBox,  "SDVDestroyOcclusionBox");
    R(SDVDestroyOcclusionBoxSet,"SDVDestroyOcclusionBoxSet");
    R(SDVFinit,                "SDVFinit");
    R(SDVGetGlobalControlF,    "SDVGetGlobalControlF");
    R(SDVGetGlobalControlI,    "SDVGetGlobalControlI");
    R(SDVGetGlobalVolume,      "SDVGetGlobalVolume");
    R(SDVGetInstance,          "SDVGetInstance");
    R(SDVGetListenerPosition,  "SDVGetListenerPosition");
    R(SDVGetMinMaxDistances,   "SDVGetMinMaxDistances");
    R(SDVGetTime,              "SDVGetTime");
    R(SDVHWLoadWorld,          "SDVHWLoadWorld");
    R(SDVInit,                 "SDVInit");
    R(SDVOcclusionBox,         "SDVOcclusionBox");
    R(SDVOcclusionParms,       "SDVOcclusionParms");
    R(SDVPause,                "SDVPause");
    R(SDVPreLoad,              "SDVPreLoad");
    R(SDVProcess,              "SDVProcess");
    R(SDVResume,               "SDVResume");
    R(SDVSetGlobalControlF,    "SDVSetGlobalControlF");
    R(SDVSetGlobalControlI,    "SDVSetGlobalControlI");
    R(SDVSetGlobalVolume,      "SDVSetGlobalVolume");
    R(SDVSetVolPCTInstance,    "SDVSetVolPCTInstance");
    R(SDVSetVolumeInstance,    "SDVSetVolumeInstance");
    R(SDVSilence,              "SDVSilence");
    R(SDVSoundFastIsPlayingInst,"SDVSoundFastIsPlayingInst");
    R(SDVStart2DSample,        "SDVStart2DSample");
    R(SDVStart3DObj,           "SDVStart3DObj");
    R(SDVStart3DPos,           "SDVStart3DPos");
    R(SDVStopInstance,         "SDVStopInstance");
    R(SDVStopObject,           "SDVStopObject");
    R(SDVStopSample,           "SDVStopSample");
    R(SDVUnLoad,               "SDVUnLoad");
    R(SDVUpCallsLoad,          "SDVUpCallsLoad");
    R(SDVUpdateOcclusionBox,   "SDVUpdateOcclusionBox");
    R(SDVWantLoadOccludes,     "SDVWantLoadOccludes");
    // Music (MDV*)
    R(MDVFinit,                "MDVFinit");
    R(MDVGetGlobalControlF,    "MDVGetGlobalControlF");
    R(MDVGetGlobalControlI,    "MDVGetGlobalControlI");
    R(MDVGetGlobalVolume,      "MDVGetGlobalVolume");
    R(MDVGetPlayList,          "MDVGetPlayList");
    R(MDVGetSongPlaying,       "MDVGetSongPlaying");
    R(MDVInit,                 "MDVInit");
    R(MDVIsJumping,            "MDVIsJumping");
    R(MDVPlaySong,             "MDVPlaySong");
    R(MDVProcess,              "MDVProcess");
    R(MDVSetGlobalControlF,    "MDVSetGlobalControlF");
    R(MDVSetGlobalControlI,    "MDVSetGlobalControlI");
    R(MDVSetGlobalVolume,      "MDVSetGlobalVolume");
    R(MDVStopSong,             "MDVStopSong");
    // Streams (VDV*)
    R(VDVFinitStreams,         "VDVFinitStreams");
    R(VDVGetStreamSyncTime,    "VDVGetStreamSyncTime");
    R(VDVIsPlayingStream,      "VDVIsPlayingStream");
    R(VDVPlayStream,           "VDVPlayStream");
    R(VDVPlayStreamSync,       "VDVPlayStreamSync");
    R(VDVSetVolPCTStream,      "VDVSetVolPCTStream");
    R(VDVSilence,              "VDVSilence");
    R(VDVStopStream,           "VDVStopStream");
    // gs_<backend>'s own UpCallsLoad (engine→audio callback registration; FUN_00521a60 builds the table — ported later)
    R(UpCallsLoad,             "UpCallsLoad");

    if (g_vTrace) {
        fprintf(g_vTrace, "[VAUDIO] loaded %s: %d/%d exports resolved (UpCallsLoad=%p)\n",
                dll, g_audio.resolvedCount, g_audio.totalCount, (void*)g_audio.UpCallsLoad);
        fflush(g_vTrace);
    }
    return ok;
}

const AudioExports& Exports() { return g_audio; }

} // namespace VanillaAudio
