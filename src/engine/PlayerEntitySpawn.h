// Giants Engine - Player Entity Spawn Check
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── PlayerEntitySpawn (FUN_00463c10) ── PASS ──
// Checks if player entity at index can spawn. Validates game mode (not dedicated),
// entity level ≥ 0xE, health/position checks. Spawns via FUN_0045fe10.
// 4 callees, 6 callers.
void PlayerEntitySpawn(unsigned int playerIndex, uint8_t param_2);  // FUN_00463c10
} // namespace Giants
