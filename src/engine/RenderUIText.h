// Giants Engine - UI Text Rendering
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── RenderUIText (FUN_005da470) ── FAIL (usable ~85%) ──
// Renders UI text elements based on mode (param_4+4).
// Mode 0: MH_Renderer text with time value
// Mode 0x17, 0x19, 0x1A: special returns (camera/entity ops)
// Mode < 0xE: string lookup + position calculation
// Mode >= 0xE: default text rendering with fallback
// 27 callers, 10 callees.
uint32_t RenderUIText(int param_1, int param_2, int param_3, int param_4);  // FUN_005da470

} // namespace Giants
