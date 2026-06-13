// Giants Engine - Hash Table Store
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── HashTableStore (FUN_00451460) ── PASS ──
// Stores a value into a hash table keyed by param_1 bits.
// Extracts 7-bit bucket from bits 13..19, 13-bit slot from bits 0..12.
// Validates via FUN_00451620 before writing.
// 17 callers, 1 callee.
void HashTableStore(uint32_t* key, uint32_t value, int slotOffset);  // FUN_00451460

} // namespace Giants
