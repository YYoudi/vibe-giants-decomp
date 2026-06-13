// Giants Engine - Menu Item Render Dispatch
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── RenderMenuItem (FUN_005d9d20) ── PASS ──
// Dispatches menu item rendering: resolves item name via string hash,
// handles special cases (indices 7/8/9/0xc/0xf/0x10), computes text
// position with screen scaling, calls render functions.
// 17 callers, ~8 callees.
int RenderMenuItem(int param1, uint32_t* param2, int param3, int param4);  // FUN_005d9d20

} // namespace Giants
