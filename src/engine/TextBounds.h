// Giants Engine - Text Bounds Calculation
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── CalculateTextBounds (FUN_004d3dd0) ── PASS ──
// Computes text bounding box with alignment support.
// Processes string to measure width/height, applies alignment offsets.
// Supports single-line and multi-line (newline-delimited) text.
// Flags: bit 2 = multi-line, bits 24-26 = horiz/vert alignment,
//        bit 28 = top-align, bit 29 = center-vert, bit 30 = bottom-vert.
// 38 callers, 4 callees.
void CalculateTextBounds(uint32_t param_1, int param_2);  // FUN_004d3dd0

} // namespace Giants
