// Giants Engine - Render Callback Dispatch
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── RenderCallbackDispatch (FUN_005fbbf0) ── PASS ──
// Dispatches render callback with float parameters (position/color).
// Calls vtable[0] with transformed parameters. 8 callers, 0 callees.
int RenderCallbackDispatch(int param_1, uint32_t param_2);  // FUN_005fbbf0
} // namespace Giants
