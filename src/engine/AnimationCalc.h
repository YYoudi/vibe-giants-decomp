// Giants Engine - Animation Interval Calculation
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── GetIntervalCount (FUN_0047dc00) ── PASS ──
// Calculates the number of intervals for an animation sequence element.
// Uses a global object at DAT_00701a3c as the base for all offset reads.
// Dispatches on 'mode' (0-5):
//   0 = identity (return base value)
//   1 = bit-manipulation flags from float comparison
//   2 = negative value fallback
//   3 = interval count with scaleA = base[0x8c] * DAT_0066be90
//   4 = interval count with scaleA = base[0x8c] * DAT_0066bf5c, doubled scaleB
//   5 = interval count with scaleA = base[0x8c] * DAT_0066be90, alt scaleB
// 35 callers, 0 callees.
int GetIntervalCount(int index, int mode);  // FUN_0047dc00

} // namespace Giants
