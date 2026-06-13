// Giants Engine - Vector Normalize
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── VectorNormalize (FUN_004da640) ── PASS ──
// Normalizes a 3D vector. If length != 1.0 (DAT_0066bce4), divides by length.
// Returns the squared length. Calls FUN_0042bee0 for sqrt check.
// 6 callers, 1 callee.
float VectorNormalize(float* out, float* in);  // FUN_004da640
} // namespace Giants
