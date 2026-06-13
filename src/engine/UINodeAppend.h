// Giants Engine - UI Node Append
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── UINodeAppend (FUN_004d3d10) ── PASS ──
// Appends a 0x38-byte node to UI linked list (DAT_006fef88) with event ID,
// string "O1", and float params from XMM registers. Calls FUN_004d3dd0 refresh.
// 3 callees, 6 callers.
void UINodeAppend(uint32_t param_1, uint32_t eventId, uint32_t param_3,
                  uint32_t param_4, uint32_t param_5);  // FUN_004d3d10
} // namespace Giants
