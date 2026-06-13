// Giants Engine - Terrain Vertex Process
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── ProcessTerrainVertex (FUN_004e9310) ── PASS ──
// Processes terrain vertex data: reads vertex bytes, applies height scaling,
// computes normals. 11 callers, 2 callees.
void ProcessTerrainVertex(uint32_t param_1, uint8_t* vertexData, float* output);  // FUN_004e9310
} // namespace Giants
