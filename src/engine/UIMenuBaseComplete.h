// Giants Engine - UI Menu Base Complete
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
#include <windows.h>
namespace Giants {
// ─── UIMenuBaseComplete (FUN_004594f0) ── PASS ──
// Toggles "BaseComplete" setting: writes to registry, updates linked list UI node
// with button text (ButtonYes/ButtonNo), event ID 0x1FA. 8 callees, 6 callers.
void UIMenuBaseComplete(int enable, int param_2);  // FUN_004594f0
} // namespace Giants
