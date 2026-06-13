// Giants Engine - Memory Compare (equality check)
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── MemoryCompare (FUN_004c3280) ── PASS ──
// Compares two byte buffers for equality. Returns false if sizes differ,
// true if both empty. Otherwise compares in 4-byte chunks then byte-by-byte.
// 17 callers, 0 callees (pure comparison).
bool MemoryCompare(const uint8_t* lhs, uint32_t lhs_size, const uint8_t* rhs, uint32_t rhs_size);  // FUN_004c3280

} // namespace Giants
