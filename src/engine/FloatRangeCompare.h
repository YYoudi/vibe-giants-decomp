// Giants Engine - Float Range Compare
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── FloatRangeCompare (FUN_0055d2e0) ── PASS ──
// Compares four float* parameters for range check (min/max AABB test).
// Returns 0 if inside range, nonzero otherwise. 7 callers, 0 callees.
int FloatRangeCompare(float* mins, float* maxs, float* point, float* result);  // FUN_0055d2e0
} // namespace Giants
