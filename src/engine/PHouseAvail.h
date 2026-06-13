// Giants Engine - Smartie House Availability UI (player house menu)
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── UpdatePHouseAvail (FUN_00562150) ── PASS ──
// Complex player house availability UI: handles smartie/item availability
// display, angle calculations, entity targeting, callback dispatch.
// Dispatches per sub-type (0=avail item, 1=avail count, 2=smartie avail).
// 19 callers, ~20 callees.
int UpdatePHouseAvail(int* param1, int param2, int param3, int param4);  // FUN_00562150

} // namespace Giants
