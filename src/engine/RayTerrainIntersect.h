// Giants Engine - Ray-Terrain Intersection
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── RayTerrainIntersect (FUN_004ff520) ── PASS ──
// Marches a ray along a direction to find terrain intersection.
// Uses linear march then 8-iteration binary search for precise hit.
// Returns 1 if hit, 0 if miss. Writes intersection point to param_1
// and hit distance to param_5.
// 17 callers, 2 callees (FUN_004fecb0, FUN_0042d350).
uint32_t RayTerrainIntersect(float* hitPos, const float* rayOrigin,
                              const float* rayDir, uint32_t param_4,
                              float* outDist);  // FUN_004ff520

} // namespace Giants
