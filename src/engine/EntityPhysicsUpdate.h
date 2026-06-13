// Giants Engine - Entity Physics Velocity Update
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── EntityPhysicsUpdate (FUN_0055c2c0) ── PASS ──
// Updates entity velocity using physics: computes delta from position,
// applies damping at +0x250, updates acceleration at +0x174..+0x188.
// Uses DAT_0066be20 (0.5f) for time scaling. 5 callees, 6 callers.
void EntityPhysicsUpdate(int param_1);  // FUN_0055c2c0
} // namespace Giants
