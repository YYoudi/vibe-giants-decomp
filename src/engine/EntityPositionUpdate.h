// Giants Engine - Entity Position Update With Rotation
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── UpdateEntityPosition (FUN_00566ed0) ── PASS ──
// Updates entity position by computing velocity from rotation matrix
// and scale. Writes velocity to +0x154,+0x158,+0x15c with optional
// clamping via param_2/param_3/param_4.
// 19 callers, 2 callees (FUN_0042bee0, FUN_0062a0b0).
void UpdateEntityPosition(int entity, int clampX, int clampY, float clampValue);  // FUN_00566ed0

} // namespace Giants
