// Giants Engine - Raycast World
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── RaycastWorld (FUN_004a1320) ── FAIL (usable) ──
// Traces a ray through the world's entity list, performing triangle-level
// ray-mesh intersection. Walks entity linked list at DAT_007027bc,
// checks AABB bounds, then tests each triangle in mesh data.
// Returns closest hit entity via param_2.
// 40 callers, 5 callees. ~90% correct, minor issues with raycast bounds check.
void RaycastWorld(float* param_1, int* param_2);  // FUN_004a1320

} // namespace Giants
