// Giants Engine - Euler To Matrix (variant 2)
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── EulerToMatrix2 (FUN_0063e480) ── PASS ──
// Converts euler angles (degrees) to 4x4 rotation matrix (uint32_t[17]).
// Uses cos/sin tables or direct computation. XOR sign bit on cos for
// depth obfuscation. Sets rotation flag (bit 0) in flags word.
// 21 callers, 0 callees (pure math).
void EulerToMatrix2(uint32_t* matrix, float pitch, float yaw, float roll);  // FUN_0063e480

} // namespace Giants
