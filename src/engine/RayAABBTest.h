// Giants Engine - Ray/AABB Intersection Test
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── TestRayIntersection (FUN_005c58d0) ── FAIL (usable ~75%) ──
// Tests ray segment against AABB of entities in a linked list.
// Computes segment min/max per axis, checks AABB overlap, then
// calls FUN_0055d2e0 for detailed intersection. Supports exclude list
// and distance threshold check.
// 12 callers, ~5 callees.
bool TestRayIntersection(const float* rayStart, const float* rayEnd,
                         int excludeCount, const int* excludeList, uint8_t flags);  // FUN_005c58d0

} // namespace Giants
