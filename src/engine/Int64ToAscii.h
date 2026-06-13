// Giants Engine - Int64 to ASCII Conversion
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── Int64ToAscii (FUN_0044c390) ── FAIL (usable ~75%) ──
// Converts a 64-bit unsigned integer to ASCII string. Uses reciprocal
// multiplication for division by 100, writes digit pairs from g_DigitPairs.
// Returns {buffer_end, write_start} pair.
// 17 callers, 0 callees (pure computation).
struct PtrPair { char* end; char* start; };
PtrPair Int64ToAscii(int buffer, int offset, uint32_t value_lo, uint32_t value_hi);  // FUN_0044c390

} // namespace Giants
