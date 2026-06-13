// Giants Engine - Entity Depth Test
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── EntityDepthTest (FUN_00582210) ── PASS ──
// Tests if entity1 is behind entity2 relative to entity2's facing direction.
// Uses depth XOR key DAT_0066c580 for comparison. Checks visibility flags,
// entity types, and player ownership. 9 callers, 0 callees.
extern uint32_t DAT_0066c580;   // Depth XOR key
extern uint32_t DAT_0066bce4;   // Depth threshold
extern int DAT_00702774;        // Game state pointer
bool EntityDepthTest(int entity1, int entity2);  // FUN_00582210
} // namespace Giants
