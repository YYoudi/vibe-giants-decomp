// Giants Engine - Render Query Setup
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── SetupRenderQuery (FUN_005d8400) ── PASS ──
// Sets up a render query with viewport/scissor parameters.
// Computes bounds, validates state, dispatches query. 10 callers, 1 callee.
uint32_t SetupRenderQuery(uint32_t param_1, int param_2, int param_3, int param_4);  // FUN_005d8400
} // namespace Giants
