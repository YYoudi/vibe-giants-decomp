// Giants Engine - Transform Point by Entity Matrix
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── TransformPointByEntity (FUN_005fade0) ── PASS ──
// Transforms a 3D point by an entity's local matrix.
// Two modes based on entity flags (+0x124 bit 5):
//   bit 5 clear: subtract entity origin, apply rotation matrix (FUN_005faab0)
//   bit 5 set:   apply full 4×4 matrix (translation included) via FUN_0067d20c
// 21 callers, 3 callees (FUN_005faab0, FUN_0067d20c, security_cookie).
void TransformPointByEntity(int entity, float* srcPoint, float* outPoint);  // FUN_005fade0

} // namespace Giants
