// Giants Engine - 2D Vector Angle Calculation
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── ComputeVectorAngle2D (FUN_00638a90) ── PASS ──
// Computes the 2D angle between two vectors using atan2.
// Returns 0 if distance is 0 and Z-delta is 0.
// Multiplies result by _DAT_0066c0a8 (radians-to-degrees scale).
// 18 callers, 2 callees (SQRT, _CIatan2).
float ComputeVectorAngle2D(const float* v1, const float* v2);  // FUN_00638a90

} // namespace Giants
