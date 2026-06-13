// Giants Engine - Object Update Dispatch (game state + callbacks)
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── UpdateObjectState (FUN_005413d0) ── PASS ──
// Main game object state update: allocates/frees per-object arrays from a
// linked list or fixed table, dispatches game logic, calls callback tables
// (stride 0x50) for active objects. Handles timing, frame counting.
// 20 callers, ~12 callees.
void UpdateObjectState();  // FUN_005413d0

} // namespace Giants
