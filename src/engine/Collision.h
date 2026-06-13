// Giants Engine - Raycast/Collision System
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── RaycastWorld (FUN_004a1320) ── FAIL (usable) ──
// World-space raycast: walks collision grid objects, performs
// triangle-based hit testing with winding number algorithm.
// Uses grid coordinates, bounding box culling, submesh iteration.
// 40 callers, 5 callees. ~85% correct despite FAIL verdict.
void RaycastWorld(float* rayOrigin, int* outHitObject);  // FUN_004a1320

} // namespace Giants
