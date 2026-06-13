// Giants Engine - Kabuto Message Handler
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── KabutoMessage (FUN_00509c00) ── PASS ──
// Handles Kabuto entity messages: validates entity type (1 or 0xF),
// checks message ID (0x4B7/0x4B8), processes Kabuto-specific logic
// including health check and message display. 7 callees, 6 callers.
void KabutoMessage(int param_1, int param_2, uint64_t* param_3,
                   uint64_t* param_4, uint32_t param_5, uint32_t param_6);  // FUN_00509c00
} // namespace Giants
