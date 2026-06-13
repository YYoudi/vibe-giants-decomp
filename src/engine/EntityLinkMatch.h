// Giants Engine - Entity Link Match
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── EntityLinkMatch (FUN_005ad340) ── PASS ──
// Walks entity linked list matching spawn type (0x27=player, 0x60=building).
// Links entities to the spawning entity by type. 6 callers, 0 callees.
void EntityLinkMatch(int param_1);  // FUN_005ad340
} // namespace Giants
