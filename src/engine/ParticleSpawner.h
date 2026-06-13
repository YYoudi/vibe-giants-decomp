// Giants Engine - Particle Spawner
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── ParticleSpawner (FUN_00497ea0) ── PASS ──
// Spawns N particles with random position/velocity within bounds.
// Uses XOR depth key (DAT_0066c580), rand(), FloatDecompose.
// 3 callees, 6 callers.
void ParticleSpawner(uint32_t param_1, int minCount, int maxCount,
                     float xMin, float xMax, float yMin, float yMax,
                     float zMin, float zMax);  // FUN_00497ea0
} // namespace Giants
