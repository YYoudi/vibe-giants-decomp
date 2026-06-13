// Giants Engine - Matrix Inverse
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── MatrixInvert (FUN_006392d0) ── PASS ──
// Computes the inverse of a 4×4 matrix stored as uint32_t[17] (IEEE 754 floats).
// Dispatch based on flags (*src & 0xF):
//   0: Identity matrix
//   bits 1-2 == 0: Non-inverted (copy columns, no inverse needed)
//   else: Full cofactor-based inverse with determinant
// Result written to dst (17 uints = 4×4 matrix + flags).
// Uses DAT_0066bf2c (1.0f) and DAT_0066c580 (depth XOR key).
// 27 callers, 0 callees — pure math, self-contained.
void MatrixInvert(uint32_t* dst, const uint32_t* src);  // FUN_006392d0

} // namespace Giants
