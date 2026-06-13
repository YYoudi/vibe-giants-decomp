// Giants Engine - Camera Selection
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── SelectCamera (FUN_00541690) ── PASS ──
// Selects active camera by index. Clamps index to valid range [0, max).
// Updates global camera state and recomputes viewport extents.
// 26 callers, 1 callee (ComputeViewportBounds FUN_005de3d0).
void SelectCamera(int cameraIndex);  // FUN_00541690

} // namespace Giants
