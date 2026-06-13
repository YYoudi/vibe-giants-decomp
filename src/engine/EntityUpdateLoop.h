// Giants Engine - Entity Update Loop
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── EntityUpdateLoop (FUN_004acee0) ── PASS ──
// Updates entities in range [param_2..param_3]. Checks entity type at +0x22C:
// type 0x20 → FUN_00496c30, else → FUN_00580230. Then walks linked list
// at DAT_007027dc processing type 0x4A entities matching param_1.
// 6 callees, 6 callers.
void EntityUpdateLoop(int param_1, int param_2, int param_3);  // FUN_004acee0
} // namespace Giants
