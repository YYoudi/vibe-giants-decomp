// Giants Engine - Frustum Plane Check
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── FrustumPlaneCheck (FUN_005fa7f0) ── PASS ──
// Tests a point against 6 view frustum planes. Uses matrix at DAT_00685810
// to transform the point, then classifies against near/far and left/right
// planes. Returns bitmask of passed planes. 9 callers, 0 callees.
extern uint32_t DAT_0066c580;   // Depth XOR key
uint32_t FrustumPlaneCheck(float* point, float* param_2, float* param_3);  // FUN_005fa7f0
} // namespace Giants
