// Giants Engine - Game Path Cleanup
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── GamePathCleanup (FUN_005459f0) ── PASS ──
// Cleans up game path data at index DAT_00748a30. Frees waypoint array,
// calls FUN_004ea1b0 per waypoint, then FUN_005403e0 for final cleanup.
// 4 callees, 6 callers.
void GamePathCleanup();  // FUN_005459f0
} // namespace Giants
