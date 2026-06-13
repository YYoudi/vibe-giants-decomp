// Giants Engine - Entity Matrix Computation
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── ComputeEntityMatrix (FUN_0056ca90) ── PASS ──
// Computes entity rotation/transform matrix from orientation data.
// Reads 3 orientation values via SinCosLookup, builds 3x3 rotation
// matrix with scale factor at offset 0x370. Applies XOR depth
// obfuscation via DAT_0066c580. Sets render flags at offset 0x2e4.
// 44 callers, 2 callees.
void ComputeEntityMatrix(int param_1);  // FUN_0056ca90

} // namespace Giants
