// Giants Engine - Entity Select Update
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── EntitySelectUpdate (FUN_0047bac0) ── PASS ──
// Updates the selected entity in the game state. If entity changed, updates
// UI (DAT_00701a3c+0x1bc4), clears flags, queries entity type and ID.
// 14 callers, 3 callees.
void EntitySelectUpdate(int entity);  // FUN_0047bac0
} // namespace Giants
