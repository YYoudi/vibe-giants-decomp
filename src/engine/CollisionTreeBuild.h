// Giants Engine - Collision Tree Build / Particle Update
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── CollisionTreeBuild (FUN_0056d890) ── FAIL (usable ~75%) ──
// Complex collision tree traversal with particle/entity interaction.
// Iterates collision nodes at stride 0x18, computes intersection
// with physics volumes, applies impulse forces. Uses security cookie.
// 11 callers, ~6 callees.
void CollisionTreeBuild(int param_1, int* param_2, int param_3, int param_4);  // FUN_0056d890
} // namespace Giants
