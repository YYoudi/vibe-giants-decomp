// Giants Engine - Buffer Equality Comparison Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "BufferCompare.h"
#include <cstdint>

namespace Giants {

// ═══════════════════════════════════════════════════════════════════
// BufferEqual (FUN_004c3280) — 17 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Fast byte buffer comparison. Early-out on length mismatch.
// Compares 4 bytes at a time, then handles 1-3 trailing bytes.

bool BufferEqual(const uint8_t* buf1, uint32_t len1, const uint8_t* buf2, uint32_t len2)
{
    if (len1 != len2) {
        return false;
    }
    if (len1 == 0) {
        return true;
    }

    // Compare 4 bytes at a time
    uint32_t remaining = len1;
    while (remaining > 3) {
        if (*reinterpret_cast<const uint32_t*>(buf1) != *reinterpret_cast<const uint32_t*>(buf2)) {
            goto byte_compare;
        }
        buf1 += 4;
        buf2 += 4;
        remaining -= 4;
    }

    // Handle trailing bytes (0-3 remaining)
    if (remaining == 0) {
        return true;
    }

byte_compare:
    // Byte-by-byte comparison for remainder or after mismatch
    for (uint32_t i = 0; i < len1; i++) {
        if (buf1[i] != buf2[i]) {
            return false;
        }
    }
    return true;
}

} // namespace Giants
