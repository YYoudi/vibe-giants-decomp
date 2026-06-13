// Giants Engine - 64-bit Integer to Wide String Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "Int64ToWideString.h"
#include <cstdint>

namespace Giants {

// ═══════════════════════════════════════════════════════════════════
// Int64ToWideString (FUN_0044c390) — 17 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Converts 64-bit int to wide-char decimal string.
// Uses fixed-point reciprocal of 100 (0xE147AE15 / 0x47AE147A)
// for fast division by 100, and DAT_0065d910 lookup table for
// digit pairs (00..99 → two wide chars).

// External: digit pair lookup table (200 wide chars for 0-99)
extern uint16_t DAT_0065d910[];  // Digit pair lookup table

uint64_t Int64ToWideString(int bufStart, int bufEnd, uint32_t lo, uint32_t hi)
{
    // Find highest set bit position
    int bitPos = 31;
    if (hi != 0) {
        while ((hi >> bitPos) == 0) bitPos--;
    }
    if (hi == 0) {
        bitPos = 31;
        if ((lo | 1) != 0) {
            while (((lo | 1) >> bitPos) == 0) bitPos--;
        }
    }

    auto* writePtr = reinterpret_cast<uint16_t*>(bufStart + bufEnd);
    auto* bufEndPtr = writePtr;

    // Divide by 100 repeatedly, extract digit pairs
    while ((hi != 0) || (lo > 99)) {
        writePtr--;

        // 64-bit division by 100 using fixed-point multiply
        // q = (hi:lo) / 100
        uint64_t mulHi = static_cast<uint64_t>(hi) * 0xE147AE15ULL +
                         (static_cast<uint64_t>(lo) * 0xE147AE15ULL >> 32);
        uint32_t qHi = static_cast<uint32_t>(mulHi >> 32);
        uint32_t carry = (static_cast<uint32_t>(static_cast<uint64_t>(lo) * 0x47AE147AULL >> 32)) +
                         static_cast<uint32_t>((static_cast<uint32_t>(mulHi) + qHi) < qHi);
        uint64_t qLo = static_cast<uint64_t>(hi) * 0x47AE147AULL +
                       (static_cast<uint64_t>(carry) << 32) + qHi;

        // Remainder adjustment
        uint32_t remAdjust = (hi - static_cast<uint32_t>(qLo >> 32)) -
                             static_cast<uint32_t>(lo < static_cast<uint32_t>(qLo));
        qLo += (static_cast<uint64_t>(remAdjust >> 1) << 32) |
               ((lo - static_cast<uint32_t>(qLo)) >> 1 | remAdjust * 0x80000000U);

        hi = static_cast<uint32_t>(qLo >> 32);
        uint32_t quotient = (static_cast<uint32_t>(qLo) >> 6) | (hi << 26);
        hi >>= 6;

        // Digit pair from lookup table
        *writePtr = DAT_0065d910[(lo + quotient * ~99u) * 2];  // (lo - quotient*100)
        lo = quotient;
    }

    // Final digit(s)
    if (lo > 9) {
        writePtr[-1] = DAT_0065d910[lo * 2];
        return (static_cast<uint64_t>(reinterpret_cast<uintptr_t>(bufEndPtr)) << 32) |
               reinterpret_cast<uintptr_t>(writePtr - 1);
    }

    *reinterpret_cast<char*>(writePtr - 1) = static_cast<char>(lo) + '0';
    return (static_cast<uint64_t>(reinterpret_cast<uintptr_t>(bufEndPtr)) << 32) |
           reinterpret_cast<uintptr_t>(reinterpret_cast<char*>(writePtr) - 1);
}

} // namespace Giants
