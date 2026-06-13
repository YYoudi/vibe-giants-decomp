// Giants Engine - Entity Terrain Collision
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── ApplyTerrainCollision (FUN_005668b0) ── PASS ──
// Applies terrain collision response to entity velocity.
// Projects velocity onto terrain normal, applies damping from
// entity data (+0x34, +0x38), and normalizes if speed exceeds limit.
// 17 callers, 1 callee (FUN_0042bee0).
void ApplyTerrainCollision(int entity, int param_2);  // FUN_005668b0

} // namespace Giants
