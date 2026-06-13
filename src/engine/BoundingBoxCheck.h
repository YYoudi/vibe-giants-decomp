// Giants Engine - Bounding Box Check
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── BoundingBoxCheck (FUN_004a1be0) ── PASS ──
// Checks if point param_2 is inside bounding box. Calls FUN_0042d350 for axis data.
// Returns 0 if inside, non-zero if outside. 1 callee, 5 callers.
uint32_t BoundingBoxCheck(int param_1, float* param_2, int param_3, int param_4, int param_5);  // FUN_004a1be0
} // namespace Giants
