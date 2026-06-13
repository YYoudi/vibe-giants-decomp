// Giants Engine - Angle Difference
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── AngleDifference (FUN_00638820) ── PASS ──
// Computes angular difference (a-b), wraps to [0, max) range,
// then mirrors if > threshold. Returns positive angle difference.
// 13 callers, 0 callees.
float AngleDifference(float a, float b);  // FUN_00638820
} // namespace Giants
