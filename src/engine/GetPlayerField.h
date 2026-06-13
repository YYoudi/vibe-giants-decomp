// Giants Engine - Get Player Field
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── GetPlayerField (FUN_004771f0) ── PASS ──
// Reads a float value from player data array at DAT_00701a3c+0x458[param_1].
// Returns packed uint with float bits. 10 callers, 0 callees.
uint32_t GetPlayerField(int param_1);  // FUN_004771f0
} // namespace Giants
