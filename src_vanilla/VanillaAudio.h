// Giants Vanilla-Native Recomp — audio subsystem loader (FUN_0051f900 port).
// Loads gs_<backend>.dll (e.g. gs_ds.dll = DirectSound) and resolves its ~60 SDV/MDV/VDV
// exports + UpCallsLoad. Faithful port of FUN_0051f900's load+resolve phase. The engine
// stores these fn-ptrs in .data globals DAT_005dc24c..DAT_005dc330 and calls gs_ds's
// UpCallsLoad (built by FUN_00521a60 — ported later) to register engine→audio callbacks.
#pragma once
#include <cstdint>
#include <windows.h>

struct AudioExports {
    HMODULE module;
    FARPROC SDVInit, SDVFinit, SDVProcess, SDVPreLoad, SDVUnLoad;
    FARPROC SDVStart3DObj, SDVStart2DSample, SDVSetGlobalVolume, SDVGetListenerPosition;
    FARPROC SDVUpCallsLoad;
    FARPROC MDVInit, MDVFinit, MDVProcess, MDVPlaySong, MDVStopSong;
    FARPROC VDVFinitStreams;
    FARPROC UpCallsLoad;     // gs_ds's own UpCallsLoad (engine→audio callback registration)
    int resolvedCount;
};

namespace VanillaAudio {
// Load gs_<backend>.dll + resolve exports. backend="ds" → gs_ds.dll. Returns true on success.
bool Load(const char* backend);
const AudioExports& Exports();
} // namespace VanillaAudio
