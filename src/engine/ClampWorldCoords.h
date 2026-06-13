// Giants Engine - Clamp World Coords
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── ClampWorldCoords (FUN_00477710) ── PASS ──
// Clamps world coordinates against viewport bounds, applying scroll offset,
// scale factor, and camera limits. Returns clamped [x,y] in output.
// 6 callers, 0 callees.
float* ClampWorldCoords(float* output, int param_2, float param_3, float param_4);  // FUN_00477710
} // namespace Giants
