// Giants Engine - Menu Text Rendering
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── RenderMenuText (FUN_005da470) ── FAIL (usable ~80%) ──
// Complex menu/UI text rendering with 10 callees.
// Handles font selection, text layout, color, alignment for UI.
// 27 callers, 10 callees.
void RenderMenuText(int* menuObj, int textEntry, int x, int y);  // FUN_005da470

} // namespace Giants
