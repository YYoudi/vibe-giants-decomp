// Giants Engine - Euler Angles to Rotation Matrix
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── BuildRotationFromEuler (FUN_0063e480) ── PASS ──
// Builds a 3×3 rotation matrix from Euler angles (in game units).
// Angles are multiplied by _DAT_0066bd40 (deg→rad factor), then
// sin/cos computed via function pointers at 0x0067d230/0x0067d234.
// Matrix output at param_1[0..11]: 12 floats (3×3 + flags + depth XOR).
// 21 callers, 2 callees (sin, cos via function pointers).
void BuildRotationFromEuler(uint32_t* matrix, float pitch, float yaw, float roll);  // FUN_0063e480

} // namespace Giants
