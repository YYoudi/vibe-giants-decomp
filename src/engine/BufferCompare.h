// Giants Engine - Buffer Equality Comparison
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── BufferEqual (FUN_004c3280) ── PASS ──
// Compares two byte buffers of given lengths. Returns true if equal.
// Optimized: compares 4 bytes at a time, then trailing bytes.
// 17 callers, 0 callees.
bool BufferEqual(const uint8_t* buf1, uint32_t len1, const uint8_t* buf2, uint32_t len2);  // FUN_004c3280

} // namespace Giants
