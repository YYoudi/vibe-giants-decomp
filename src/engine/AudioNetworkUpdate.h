// Giants Engine - Audio Network Update
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── AudioNetworkUpdate (FUN_004d9bf0) ── PASS ──
// Processes audio/network vtable calls: checks DAT_00701ce8 flag bit 0,
// calls vtable+4 (init), vtable+8 (get buffer), then cleanup via
// FUN_004e0b70, vtable+0x24, vtable+4. 3 callees, 6 callers.
void AudioNetworkUpdate();  // FUN_004d9bf0
} // namespace Giants
