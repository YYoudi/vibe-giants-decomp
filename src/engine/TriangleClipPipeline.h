// Giants Engine - Triangle Clipping Pipeline
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── ClipAndEmitTriangle (FUN_004dafa0) ── PASS ──
// Processes 3 vertices through the clipping pipeline based on clip flags.
// Performs up to 5 clip stages (near, far, left/right, top/bottom, user),
// then emits resulting triangles via render device vtable.
// 20 callers, 6 callees (clip stage functions + vtable alloc).
void ClipAndEmitTriangle(uint32_t* v1, uint32_t* v2, uint32_t* v3);  // FUN_004dafa0

} // namespace Giants
