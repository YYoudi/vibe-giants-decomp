// Giants Vanilla-Native Recomp — audio subsystem loader (FUN_0051f900 port).
// Loads gs_<backend>.dll (e.g. gs_ds.dll = DirectSound) and resolves its full export set
// (SDV* sound, MDV* music, VDV* streams + UpCallsLoad) — the EXACT names FUN_0051f900
// resolves (from vanilla_decompiled/0051f900.json "Failed to load <name>" strings).
// Faithful port of FUN_0051f900's load+resolve phase. The engine stores these fn-ptrs in
// .data globals DAT_005dc24c..DAT_005dc330 and calls gs_ds's UpCallsLoad (table built by
// FUN_00521a60 — ported later) to register engine→audio callbacks.
#pragma once
#include <cstdint>
#include <windows.h>

struct AudioExports {
    HMODULE module;
    // SDV* (sound)
    FARPROC SDVCalcVolume, SDVDestroyOcclusionBox, SDVDestroyOcclusionBoxSet;
    FARPROC SDVFinit, SDVGetGlobalControlF, SDVGetGlobalControlI, SDVGetGlobalVolume;
    FARPROC SDVGetInstance, SDVGetListenerPosition, SDVGetMinMaxDistances, SDVGetTime;
    FARPROC SDVHWLoadWorld, SDVInit, SDVOcclusionBox, SDVOcclusionParms, SDVPause;
    FARPROC SDVPreLoad, SDVProcess, SDVResume, SDVSetGlobalControlF, SDVSetGlobalControlI;
    FARPROC SDVSetGlobalVolume, SDVSetVolPCTInstance, SDVSetVolumeInstance, SDVSilence;
    FARPROC SDVSoundFastIsPlayingInst, SDVStart2DSample, SDVStart3DObj, SDVStart3DPos;
    FARPROC SDVStopInstance, SDVStopObject, SDVStopSample, SDVUnLoad, SDVUpCallsLoad;
    FARPROC SDVUpdateOcclusionBox, SDVWantLoadOccludes;
    // MDV* (music)
    FARPROC MDVFinit, MDVGetGlobalControlF, MDVGetGlobalControlI, MDVGetGlobalVolume;
    FARPROC MDVGetPlayList, MDVGetSongPlaying, MDVInit, MDVIsJumping, MDVPlaySong;
    FARPROC MDVProcess, MDVSetGlobalControlF, MDVSetGlobalControlI, MDVSetGlobalVolume, MDVStopSong;
    // VDV* (streams)
    FARPROC VDVFinitStreams, VDVGetStreamSyncTime, VDVIsPlayingStream, VDVPlayStream;
    FARPROC VDVPlayStreamSync, VDVSetVolPCTStream, VDVSilence, VDVStopStream;
    // gs_<backend>'s own UpCallsLoad (engine→audio callback registration)
    FARPROC UpCallsLoad;
    int resolvedCount;
    int totalCount;
};

namespace VanillaAudio {
// Load gs_<backend>.dll + resolve the full export set. backend="ds" → gs_ds.dll.
bool Load(const char* backend);
const AudioExports& Exports();
} // namespace VanillaAudio
