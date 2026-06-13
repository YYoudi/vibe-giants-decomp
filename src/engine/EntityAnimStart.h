// Giants Engine - Entity Animation Start
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── EntityAnimStart (FUN_0051a590) ── PASS ──
// Starts entity animation: sets scale to 1.0 at +0xBC, initializes anim
// context at +0xB8, calls FUN_004e9cd0 for anim data. On dedicated server,
// plays sound effect via FUN_00469de0. 3 callees, 6 callers.
void EntityAnimStart(int param_1);  // FUN_0051a590
} // namespace Giants
