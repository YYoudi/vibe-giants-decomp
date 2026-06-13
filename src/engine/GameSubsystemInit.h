// Giants Engine - Game Subsystem Init
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── InitGameSubsystem (FUN_00540fe0) ── PASS ──
// Initializes/resets the game subsystem state. Clears entity tables,
// sets default callbacks, zeroes state block (0x4b0 bytes).
// If first init (DAT_00747d3c == 0), calls FUN_004e96b0 for audio/init.
// 21 callers, 2 callees (FUN_004e96b0, memset).
void InitGameSubsystem(uint32_t param_1, uint32_t param_2);  // FUN_00540fe0

} // namespace Giants
