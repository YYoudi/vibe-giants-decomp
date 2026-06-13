// Giants Engine - Text Layout Measurement
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── MeasureTextLayout (FUN_004d3dd0) ── PASS ──
// Measures text bounding box for rendering. Handles multi-line text
// with newline processing, horizontal/vertical alignment flags.
// Writes computed bounds to param_2 (+0x18..+0x24).
// 38 callers, 1 callee.
void MeasureTextLayout(uint32_t param_1, int param_2);  // FUN_004d3dd0

} // namespace Giants
