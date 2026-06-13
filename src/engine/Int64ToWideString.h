// Giants Engine - 64-bit Integer to Wide String
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── Int64ToWideString (FUN_0044c390) ── PASS ──
// Converts a 64-bit unsigned int (param_3:param_4) to a wide decimal string.
// Writes digits right-to-left into buffer at param_1, using division by 100
// with a lookup table (DAT_0065d910) for pairs of digits.
// Returns {bufferEnd, writePtr}. 17 callers, 0 callees.
uint64_t Int64ToWideString(int bufStart, int bufEnd, uint32_t lo, uint32_t hi);  // FUN_0044c390

} // namespace Giants
