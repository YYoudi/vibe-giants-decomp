// Giants Engine - UI Menu Vimps Toggle
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
#include <windows.h>
namespace Giants {
// ─── UIMenuVimps (FUN_00458a90) ── PASS ──
// Toggles "NoVimps" setting: writes to registry, updates linked list UI node
// with button text (ButtonYes/ButtonNo), event ID 0x1A4. 7 callees, 6 callers.
void UIMenuVimps(int enable);  // FUN_00458a90
} // namespace Giants
