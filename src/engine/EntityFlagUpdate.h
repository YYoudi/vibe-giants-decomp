// Giants Engine - Entity Flag Update
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── UpdateEntityFlags (FUN_0055d6c0) ── PASS ──
// Updates entity flag bytes. Reads multiple flag bytes from entity data,
// applies state transitions. 10 callers, 1 callee.
void UpdateEntityFlags(int entity);  // FUN_0055d6c0
} // namespace Giants
