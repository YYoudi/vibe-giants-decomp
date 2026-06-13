// Giants Engine - Entity Lookup
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── FindEntityById (FUN_0056e960) ── PASS ──
// Searches a container (vector of 8-byte entries at DAT_00749914..DAT_00749918)
// for an entity matching target_id. Entries: {int* obj} where obj[0]=id, obj[1]=flag.
// Game state (DAT_006ff960==6) affects match priority:
//   - mode!=6: returns first match where flag==0
//   - mode==6: returns first match where flag!=0, or stores last match where flag==0
// 35 callers, 0 callees.
int* FindEntityById(int targetId);  // FUN_0056e960

} // namespace Giants
