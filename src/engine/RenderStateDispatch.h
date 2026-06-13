// Giants Engine - Render State Dispatch
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── DispatchRenderState (FUN_005067d0) ── PASS ──
// Dispatches render state based on parameters. Checks entity list
// (DAT_00749908), applies visibility/LOD rules, dispatches draw calls.
// 10 callers, 4 callees.
int DispatchRenderState(int param_1, int param_2, int param_3, uint32_t param_4,
                        uint32_t param_5, int param_6);  // FUN_005067d0
} // namespace Giants
