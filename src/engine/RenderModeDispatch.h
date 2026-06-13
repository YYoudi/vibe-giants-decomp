// Giants Engine - Render Mode Dispatch
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── RenderModeDispatch (FUN_005d9d20) ── PASS ──
// Dispatches render mode based on mode index. Handles modes 0,7,8,9,10,12,15,16.
// Calls render setup functions and computes view parameters. 17 callers, 5 callees.
uint32_t RenderModeDispatch(int param_1, uint32_t* param_2, int param_3, int param_4);  // FUN_005d9d20
} // namespace Giants
