// Giants Engine - Count Active Lanes
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── CountActiveLanes (FUN_0045fb50) ── PASS ──
// Counts active game lanes/paths by checking non-zero slots and summing
// with weight constants from DAT_0066c5b0/b4/b8/bc and DAT_0066c360/64/68/6c.
// 6 callers, 0 callees.
int CountActiveLanes();  // FUN_0045fb50
} // namespace Giants
