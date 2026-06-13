// Giants Engine - Matrix 3x4 Initializer
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── InitializeMatrix3x4 (FUN_00444db0) ── PASS ──
// Initializes a 6-float matrix (3x4 compressed), calls FUN_00444ef0
// with source data and params, then zeros the result and clears buffer.
// 23 callers, 2 callees.
void InitializeMatrix3x4(float* result, const float* source,
    uint32_t p3, uint32_t p4, uint32_t p5, uint32_t p6);  // FUN_00444db0

} // namespace Giants
