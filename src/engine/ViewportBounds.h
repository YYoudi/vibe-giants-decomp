// Giants Engine - Viewport Bounds Computation
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── ComputeViewportBounds (FUN_005de3d0) ── PASS ──
// Computes viewport extents from global camera/render state.
// Writes 7 floats to output: minX, minY, z1, z2, z3, scaleX, scaleY.
// Uses DAT_007488e8 (render active), DAT_007488f4 (camera bounds ptr),
// DAT_00702c1c/c20 (cached extents), DAT_00727fbc/c0/c4 (depth values).
// 24 callers, 0 callees — self-contained.
void ComputeViewportBounds(float* output, int width, int height);  // FUN_005de3d0

} // namespace Giants
