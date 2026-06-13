// Giants Engine - Terrain Color Mix
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── TerrainColorMix (FUN_004e0990) ── PASS ──
// Computes terrain color mixing from vertex positions and UV coords.
// Blends two colors based on height/position parameters.
// 8 callers, 0 callees (self-contained).
int TerrainColorMix(int param_1, int* param_2, int* param_3,
                    int* param_4, float* param_5, float* param_6);  // FUN_004e0990
} // namespace Giants
