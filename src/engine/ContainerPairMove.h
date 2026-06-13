// Giants Engine - Container Pair Move
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── ContainerPairMove (FUN_0042e0a0) ── PASS ──
// Moves key-value pairs from [param_1, param_2) to param_3, zeroing source.
// Calls FUN_0042b650 (vector cleanup) after loop. 6 callers, 1 callee.
uint32_t* ContainerPairMove(uint32_t* param_1, uint32_t* param_2, uint32_t* param_3);  // FUN_0042e0a0
} // namespace Giants
