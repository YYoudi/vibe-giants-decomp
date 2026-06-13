// Giants Engine - Network State Reset
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── ResetNetworkState (FUN_00474060) ── PASS ──
// Clears network state fields in DAT_00701a3c (0x1AA4..0x1AC4).
// Sets bool flag if counter was non-zero. 14 callers, 0 callees.
void ResetNetworkState();  // FUN_00474060
} // namespace Giants
