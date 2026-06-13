// Giants Engine - Entity Height Update
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── UpdateEntityHeight (FUN_0056c1a0) ── PASS ──
// Updates entity vertical position (+0x120) based on input byte at +0x25d.
// Applies scale from DAT_0066bd58, multiplies by time factor, and clamps
// to [DAT_0066c2b8, DAT_0066c0c4]. Special handling for camera entity.
// 17 callers, 1 callee (FUN_0062a0b0).
void UpdateEntityHeight(int entity);  // FUN_0056c1a0

} // namespace Giants
