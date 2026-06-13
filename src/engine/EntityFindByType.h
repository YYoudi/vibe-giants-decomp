// Giants Engine - Entity Find By Type
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── FindEntityByType (FUN_00463250) ── PASS ──
// Walks linked list at DAT_007027a8 looking for entity with matching
// type ID (+0x1d4) and not flagged as removed (flag 0x8000 at +0x124).
// Returns entity pointer or 0 if not found.
// 19 callers, 0 callees — pure linked list search.
int FindEntityByType(int typeId);  // FUN_00463250

// ─── EntityFindByTypeMatch (FUN_0047c9c0) ── PASS ──
// Searches entity list at DAT_00701a3c+0x1BAC for entity matching
// param_1's +0x31C field. Checks flag 0x1000000 at +8.
// 1 callee, 5 callers.
int EntityFindByTypeMatch(int param_1);  // FUN_0047c9c0

} // namespace Giants
