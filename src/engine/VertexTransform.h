// Giants Engine - Vertex Transform
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── TransformVertices (FUN_005d79a0) ── PASS ──
// Transforms mesh vertices with optional scaling, rotation, and offset.
// Two modes based on flags in param_2+0x18:
//   bit 0 set: indexed vertex transform (mesh data from arrays)
//   bit 0 clear, bit 2 set: scaled transform with multiplier/divisor
// Uses globals: g_ScaleFactor (DAT_0066be20), g_depthXorKey (DAT_0066c580),
// g_Divisor1/2 (DAT_0066c15c/c174), g_Multiplier1/2 (DAT_007028a0/a4).
// 30 callers, 2 callees.
void TransformVertices(int param_1, int param_2, uint32_t param_3,
                       float param_4, float param_5, float param_6);  // FUN_005d79a0

} // namespace Giants
