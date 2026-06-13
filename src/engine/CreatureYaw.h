// Giants Engine - Creature Yaw Update
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── UpdateCreatureYaw (FUN_0056be60) ── PASS ──
// Updates creature yaw rotation (param_1+0x114) with clamped angular
// velocity, speed factor, and optional angle-to-target snapping.
// Uses random perturbation and wrap-around angle normalization.
// 23 callers, 2 callees (RandomFloat, GetAngleToTarget).
void UpdateCreatureYaw(int creaturePtr);  // FUN_0056be60

} // namespace Giants
