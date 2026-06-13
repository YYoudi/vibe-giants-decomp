// Giants Engine - Entity State Clear / Network Status Reset
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── EntityStateClear (FUN_0053a400) ── FAIL (usable ~80%) ──
// Clears entity network state flag 0x800000, resets controller fields,
// dispatches network mode transitions based on platform (DAT_006ff960==6).
// 11 callers, ~5 callees.
void EntityStateClear(int* entity);  // FUN_0053a400
} // namespace Giants
