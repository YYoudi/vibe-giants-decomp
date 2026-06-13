// Giants Engine - Menu/UI State Initializer
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── InitMenuState (FUN_00540fe0) ── PASS ──
// Initializes menu/UI state: resets globals, sets callback table,
// zeroes 0x4b0 byte buffer. Dispatches via FUN_004e96b0 when
// condition flag is clear. Two uint32_t params stored to globals.
// 21 callers, 1 callee (FUN_004e96b0).
void InitMenuState(uint32_t param1, uint32_t param2);  // FUN_00540fe0

} // namespace Giants
