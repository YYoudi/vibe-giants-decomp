// Giants Engine - Entity Position Calculation
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── CalcEntityPosition (FUN_004a1f40) ── PASS ──
// Calculates entity position with float math. Checks speed==0 for static case,
// falls back to scene graph data. 12 callers, 1 callee.
void CalcEntityPosition(int entity);  // FUN_004a1f40
} // namespace Giants
