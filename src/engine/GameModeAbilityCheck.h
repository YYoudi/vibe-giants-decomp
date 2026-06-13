// Giants Engine - Game Mode Ability Check
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── GameModeAbilityCheck (FUN_004af0d0) ── PASS ──
// Checks if ability at index param_2 is available for current game mode.
// Uses DAT_00702774 type (+0x22c) to select offset (0/0x2c/0x58/0x84),
// then checks level range in DAT_00745118 table. 3 callees, 6 callers.
bool GameModeAbilityCheck(uint32_t param_1, int param_2);  // FUN_004af0d0
} // namespace Giants
