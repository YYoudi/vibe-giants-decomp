// Giants Engine - Entity Look-At
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── EntityLookAt (FUN_005a6660) ── PASS ──
// Orients entity to look at target. Computes angle from entity position
// to target using FUN_006389d0, sets facing direction.
// 11 callers, 3 callees.
void EntityLookAt(int entity, int target);  // FUN_005a6660
} // namespace Giants
