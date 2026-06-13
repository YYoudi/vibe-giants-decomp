// Giants Engine - Matrix Multiply 4x3
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── MatrixMultiply4x3 (FUN_005faab0) ── PASS ──
// Multiplies two 4x3 matrices with XOR depth key encoding.
// Uses FUN_006387e0 for float decomposition. Produces 9-element result.
// 6 callers, 1 callee.
void MatrixMultiply4x3(float* result);  // FUN_005faab0
} // namespace Giants
