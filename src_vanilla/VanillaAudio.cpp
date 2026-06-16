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

#define R(field, name) { FARPROC p = resolve(m, name); if (p) { g_audio.field = p; g_audio.resolvedCount++; } else ok = false; }

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
    bool ok = true;
    // Sound (SDV*)
    R(SDVInit, "SDVInit"); R(SDVFinit, "SDVFinit"); R(SDVProcess, "SDVProcess");
    R(SDVPreLoad, "SDVPreLoad"); R(SDVUnLoad, "SDVUnLoad");
    R(SDVStart3DObj, "SDVStart3DObj"); R(SDVStart2DSample, "SDVStart2DSample");
    R(SDVSetGlobalVolume, "SDVSetGlobalVolume"); R(SDVGetListenerPosition, "SDVGetListenerPosition");
    R(SDVUpCallsLoad, "SDVUpCallsLoad");
    // Music (MDV*)
    R(MDVInit, "MDVInit"); R(MDVFinit, "MDVFinit"); R(MDVProcess, "MDVProcess");
    R(MDVPlaySong, "MDVPlaySong"); R(MDVStopSong, "MDVStopSong");
    // Streams (VDV*)
    R(VDVFinitStreams, "VDVFinitStreams");
    // gs_ds's own UpCallsLoad (engine→audio callback registration; FUN_00521a60 builds the table — ported later)
    R(UpCallsLoad, "UpCallsLoad");

    if (g_vTrace) {
        fprintf(g_vTrace, "[VAUDIO] loaded %s: %d/%d key exports resolved (UpCallsLoad=%p)\n",
                dll, g_audio.resolvedCount, 17, (void*)g_audio.UpCallsLoad);
        fflush(g_vTrace);
    }
    return ok;
}

const AudioExports& Exports() { return g_audio; }

} // namespace VanillaAudio
