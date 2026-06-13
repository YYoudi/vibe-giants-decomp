// Giants Engine - Hash Lookup Multiply
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── HashLookupMultiply (FUN_0048cc40) ── PASS ──
// Hash table lookup using multiply-shift method. Probes slots until match.
// 7 callers, 0 callees (self-contained).
uint32_t HashLookupMultiply(uint32_t* table, uint32_t key, uint32_t tableSize);  // FUN_0048cc40
} // namespace Giants
