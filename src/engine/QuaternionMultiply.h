// Giants Engine - Quaternion Multiply
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── QuaternionMultiply (FUN_0063faf0) ── PASS ──
// Hamilton product of two quaternions: q1 * q2.
// Handles aliasing when output == either input (uses temp buffer).
// Layout: [x, y, z, w] = [0,1,2,3]. 9 callers, 0 callees.
void QuaternionMultiply(float* out, float* q1, float* q2);  // FUN_0063faf0
} // namespace Giants
