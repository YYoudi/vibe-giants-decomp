// Giants Engine - String Grow / Allocation (FUN_00442280)
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── StringGrow (FUN_00442280) ── PASS ──
// Grows std::string buffer with 1.5x strategy. Handles SSO inline
// to heap transition, CRT heap validation. Calls _Xlength_error on overflow.
// 9 callers, ~4 callees.
void StringGrow(uint32_t extra, uint32_t zero);  // FUN_00442280
} // namespace Giants
