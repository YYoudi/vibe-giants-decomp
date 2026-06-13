// Giants Engine - Hash Table Store Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "HashTableStore.h"
#include <cstdint>

namespace Giants {

// ─── External callee ──────────────────────────────────────────
extern int FUN_00451620();  // Hash table context getter

// ═══════════════════════════════════════════════════════════════════
// HashTableStore (FUN_00451460) — 17 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Key layout (param_1 bits):
//   [31..20] unused
//   [19..13] bucket index (7 bits)
//   [12..0]  slot index (13 bits)
//
// Validates bucket < table_size, bucket pointer != NULL, and slot
// has a valid entry (0xFFFFF mask check) before writing.

void HashTableStore(uint32_t* key, uint32_t value, int slotOffset)
{
    uint32_t keyVal = *key;
    uint32_t bucket = (keyVal >> 13) & 0x7F;  // 7-bit bucket index

    int ctx = FUN_00451620();  // Get hash table context

    // Validate: bucket index < table range
    int tableStart = *reinterpret_cast<int*>(ctx + 4);
    int tableEnd = *reinterpret_cast<int*>(ctx + 8);
    if (bucket >= static_cast<uint32_t>((tableEnd - tableStart) >> 2)) {
        return;
    }

    // Validate: bucket has entries
    int bucketPtr = *reinterpret_cast<int*>(tableStart + bucket * 4);
    if (bucketPtr == 0) {
        return;
    }

    // Validate: slot has valid entry
    uint32_t slot = keyVal & 0x1FFF;  // 13-bit slot index
    if ((*reinterpret_cast<uint32_t*>(bucketPtr + slot * 4) & 0xFFFFF) == 0xFFFFF) {
        return;
    }

    // Write value: context -> bucket -> entry -> data array -> slot
    keyVal = *key;
    ctx = FUN_00451620();

    int entry = *reinterpret_cast<int*>(
        *reinterpret_cast<int*>(ctx + 4) + ((keyVal >> 13) & 0x7F) * 4);
    int dataIdx = *reinterpret_cast<int*>(entry + (keyVal & 0x1FFF) * 4);
    int dataBase = *reinterpret_cast<int*>(ctx + 0x1c);

    *reinterpret_cast<uint32_t*>(dataIdx * 0x20 + dataBase + slotOffset * 8) = value;
}

} // namespace Giants
