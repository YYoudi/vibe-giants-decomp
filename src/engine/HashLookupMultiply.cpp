// Giants Engine - Hash Lookup Multiply Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "HashLookupMultiply.h"
#include <cstdint>
namespace Giants {
uint32_t HashLookupMultiply(uint32_t* table, uint32_t key, uint32_t tableSize)
{
    // Multiply-shift hash: key * 0x9E3779B1 >> shift
    uint32_t hash = static_cast<uint32_t>(
        (static_cast<uint64_t>(key) * 0x9E3779B1ull) >> 32) % tableSize;

    // Linear probe for key match
    for (uint32_t i = 0; i < tableSize; i++) {
        uint32_t slot = (hash + i) % tableSize;
        uint32_t slotKey = table[slot * 2];  // key-value pairs
        if (slotKey == key) return table[slot * 2 + 1];  // return value
        if (slotKey == 0) return 0;  // empty slot = not found
    }
    return 0;  // table full, not found
}
} // namespace Giants
