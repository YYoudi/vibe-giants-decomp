// Giants Engine - Collision Clip Check
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── CollisionClip (FUN_004856a0) ── PASS ──
// Collision/clip test between two points with flag-based axis checks.
// Uses DAT_0066be20/DAT_0066bf2c for axis weights, calls FUN_0042d350.
// 3 callees, 6 callers.
void CollisionClip(int param_1, float* posA, float* posB, float param_4);  // FUN_004856a0
} // namespace Giants
