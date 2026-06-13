// Giants Engine - Camera Scroll Update
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── CameraScrollUpdate (FUN_0047bf50) ── PASS ──
// Updates camera scroll position and viewport bounds. Computes new
// position from delta, clamps to world bounds, updates scroll state.
// Calls FUN_0047c240 on completion. 6 callers, 1 callee.
void CameraScrollUpdate(float* param_1);  // FUN_0047bf50
} // namespace Giants
