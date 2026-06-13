// Giants Engine - Entity Flag 0x1000000 Clear / Mode Reset
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── EntityFlag24Clear (FUN_0053a690) ── PASS ──
// Clears entity flag bit 24 (0x1000000), resets controller mode to 0x13,
// dispatches network messages for multiplayer. 11 callers, ~3 callees.
void EntityFlag24Clear(int entity);  // FUN_0053a690
} // namespace Giants
