// Giants Engine - Entity Motion Calculation
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── CalcEntityMotion (FUN_005a03f0) ── PASS ──
// Calculates entity motion/trajectory. Reads entity position data,
// applies physics with float math, updates velocity. 10 callers, 1 callee.
void CalcEntityMotion(int entity);  // FUN_005a03f0
} // namespace Giants
