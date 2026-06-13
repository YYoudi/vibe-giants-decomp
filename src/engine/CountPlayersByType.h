// Giants Engine - Count Players By Type
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── CountPlayersByType (FUN_0045b2d0) ── PASS ──
// Counts players matching the given type byte. Iterates player array
// DAT_006ff8e8[type] vs param_1, checks DAT_006ff910[entry] != 0.
// 10 callers, 0 callees (self-contained).
int CountPlayersByType(uint32_t playerType);  // FUN_0045b2d0
} // namespace Giants
