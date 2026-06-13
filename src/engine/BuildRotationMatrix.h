// Giants Engine - Build Rotation Matrix
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── BuildRotationMatrix (FUN_0063e620) ── PASS ──
// Builds a 4x4 rotation matrix from Euler angles (yaw, pitch, roll).
// Converts degrees to radians, computes sin/cos via function pointers,
// fills 4x4 float matrix at param_1. 12 callers, 2 callees.
void BuildRotationMatrix(uint32_t* matrix, float yaw, float pitch, float roll, float unused);  // FUN_0063e620
} // namespace Giants
