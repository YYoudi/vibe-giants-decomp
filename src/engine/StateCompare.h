// Giants Engine - State Compare
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── StateCompare (FUN_004d6b30) ── PASS ──
// Compares entity render state with depth XOR. Checks 14 float fields
// against DAT_0066c560 mask and DAT_0066bcf4 epsilon. 1 callee, 5 callers.
uint32_t StateCompare(int param_1, float* param_2);  // FUN_004d6b30
} // namespace Giants
