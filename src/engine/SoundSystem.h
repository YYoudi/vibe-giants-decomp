// Giants Engine - Sound System
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── SoundEntry ────────────────────────────────────────────────
// Sound entry in the global sound array (0x2C stride).
struct SoundEntry {
    int      field_0x0;    // Active flag
    int      field_0x4;    // padding
    int      field_0x8;    // Valid/loaded flag
    int      field_0xc;    // padding
    int      field_0x10;   // padding
    int      field_0x14;   // padding
    int      field_0x18;   // padding
    int      field_0x1c;   // padding
    int      field_0x20;   // padding
    int      field_0x24;   // padding
    int      field_0x28;   // padding
};

// ─── Sound_Play (FUN_005582f0) ── PASS ──
// Plays a sound by index through the global sound array.
// Returns 0 if sound system disabled, entry inactive, or playback failed.
// 49 callers.
int Sound_Play(int index, uint32_t param_2, uint32_t param_3);  // FUN_005582f0

} // namespace Giants
