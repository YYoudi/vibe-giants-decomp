// Giants Engine - Entity Movement Update (position delta + callback dispatch)
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── UpdateEntityMovement (FUN_00568b50) ── PASS ──
// Updates entity movement: computes position delta, clears velocity buffer,
// iterates collision resolve (up to 4 attempts), dispatches callback via
// g_CallbackTable. Uses XOR obfuscation for float depth checks.
// 18 callers, ~5 callees.
void UpdateEntityMovement(int param1);  // FUN_00568b50

} // namespace Giants
