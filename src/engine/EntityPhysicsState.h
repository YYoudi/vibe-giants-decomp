// Giants Engine - Entity Physics State Check
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── CheckEntityPhysicsState (FUN_0055c730) ── PASS ──
// Checks entity physics state flag at +0x128. If active, applies
// velocity integration and updates position/collision.
// 10 callers, 3 callees.
void CheckEntityPhysicsState(int entity);  // FUN_0055c730
} // namespace Giants
