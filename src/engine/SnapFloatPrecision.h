// Giants Engine - Snap Float to Precision
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── SnapFloatPrecision (FUN_005fa940) ── PASS ──
// Rounds two floats to IEEE 754 precision by adding/subtracting a magic constant.
// Eliminates sub-normals and denormalized accumulation errors. 14 callers, 0 callees.
void SnapFloatPrecision(float* a, float* b);  // FUN_005fa940
} // namespace Giants
