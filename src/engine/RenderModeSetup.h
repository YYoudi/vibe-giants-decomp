// Giants Engine - Render Mode Setup
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── SetupRenderMode (FUN_005d8ab0) ── PASS ──
// Sets up render mode based on parameters. Reads shader config,
// computes UV transforms, dispatches to renderer. 10 callers, 2 callees.
uint32_t SetupRenderMode(int param_1, int param_2, int param_3, int param_4);  // FUN_005d8ab0
} // namespace Giants
