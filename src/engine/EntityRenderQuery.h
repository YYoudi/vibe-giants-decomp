// Giants Engine - Entity Render Query
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── QueryEntityRender (FUN_004ab890) ── PASS ──
// Queries entity rendering parameters (distance, visibility, LOD).
// Iterates entity list, checks bounds, returns render handle.
// 11 callers, 1 callee.
uint32_t QueryEntityRender(float param_1, int param_2, int param_3, int param_4);  // FUN_004ab890
} // namespace Giants
