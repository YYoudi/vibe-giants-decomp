// Giants Engine - Entity Slot Init
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── EntitySlotInit (FUN_00494f10) ── PASS ──
// Initializes 26 entity slots (0x1C stride) at entity+0x34, then processes
// animation state via FUN_004a67b0. 3 callees, 6 callers.
void EntitySlotInit(int param_1);  // FUN_00494f10
} // namespace Giants
