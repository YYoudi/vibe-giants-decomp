// Giants Engine - Format String Dispatch
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── FormatStringDispatch (FUN_004fc930) ── PASS ──
// Formats and dispatches a string for HUD/UI display. Checks scene state
// (DAT_00702774), builds formatted string, calls render text.
// 13 callers, 4 callees.
uint32_t FormatStringDispatch(int param_1, int param_2, int param_3, int param_4);  // FUN_004fc930
} // namespace Giants
