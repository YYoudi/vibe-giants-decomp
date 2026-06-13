// Giants Engine - Entity Collision Update
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── UpdateEntityCollision (FUN_00498080) ── PASS ──
// Updates entity collision state. Reads entity system (DAT_007028f4+0x2c8),
// checks collision data, applies response. 10 callers, 2 callees.
void UpdateEntityCollision(int entity);  // FUN_00498080
} // namespace Giants
