// Giants Engine - UI Text Rendering (Simple Variant)
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── RenderUITextSimple (FUN_005da8f0) ── PASS ──
// Simplified UI text rendering variant. Gets entity name string,
// resolves text mode from param_4+4, computes screen position
// based on layout rect, then draws via DrawTextPrepare/Execute.
// Two position modes: mode 0/0x15 (baseline) or default (full range).
// 23 callers, 3 callees (FUN_00551ae0, FUN_0062c690, FUN_0062c420).
uint32_t RenderUITextSimple(int param_1, int param_2, int param_3, int param_4);  // FUN_005da8f0

} // namespace Giants
