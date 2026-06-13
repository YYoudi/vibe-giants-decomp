// Giants Engine - Int64 to ASCII Conversion Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
// re-agent verdict: FAIL (usable ~75%)
#include "Int64ToAscii.h"
#include <cstring>

namespace Giants {

extern const char16_t g_DigitPairs[100]; // DAT_0065d910 — "00","01",...,"99"

PtrPair Int64ToAscii(int buffer, int offset, uint32_t value_lo, uint32_t value_hi)
{
    int bit_pos = 31;

    if (value_hi != 0)
    {
        while ((value_hi >> bit_pos) == 0)
            bit_pos--;
    }

    if ((value_hi == 0) && (bit_pos = 31, (value_lo | 1) != 0))
    {
        while (((value_lo | 1) >> bit_pos) == 0)
            bit_pos--;
    }

    char* buffer_end = reinterpret_cast<char*>(buffer + offset);
    char* write_ptr = buffer_end;
    uint32_t remainder = value_lo;

    while ((value_hi != 0) || (99 < remainder))
    {
        write_ptr -= 2;

        // 64-bit division by 100 via reciprocal multiplication
        uint64_t mul_hi = static_cast<uint64_t>(value_hi) * 0xe147ae15ULL +
                          (static_cast<uint64_t>(remainder) * 0xe147ae15ULL >> 32);
        uint32_t q_hi = static_cast<uint32_t>(mul_hi >> 32);

        uint64_t mul_lo = static_cast<uint64_t>(remainder) * 0x47ae147aULL;
        uint32_t carry = (static_cast<uint32_t>(mul_lo) + q_hi) < static_cast<uint32_t>(mul_lo) ? 1u : 0u;

        uint64_t combined = static_cast<uint64_t>(value_hi) * 0x47ae147aULL +
                            (static_cast<uint64_t>(carry) << 32) +
                            (static_cast<uint64_t>(q_hi) << 32 | static_cast<uint32_t>(mul_lo));

        uint32_t borrow = remainder < static_cast<uint32_t>(combined) ? 1u : 0u;
        uint32_t adj_hi = value_hi - static_cast<uint32_t>(combined >> 32) - borrow;

        uint32_t lo_sub = static_cast<uint32_t>(combined);
        uint64_t result = combined + (static_cast<uint64_t>(adj_hi >> 1) << 32 |
                           ((remainder - lo_sub) >> 1 | adj_hi * 0x80000000u));

        value_hi = static_cast<uint32_t>(result >> 32);
        uint32_t quotient = static_cast<uint32_t>(result) >> 6 | value_hi * 0x4000000u;
        value_hi >>= 6;

        // Write digit pair
        *reinterpret_cast<char16_t*>(write_ptr) = g_DigitPairs[remainder + quotient * static_cast<uint32_t>(-100)];
        remainder = quotient;
    }

    if (9 < remainder)
    {
        *reinterpret_cast<char16_t*>(write_ptr - 2) = g_DigitPairs[remainder];
        return {buffer_end, write_ptr - 2};
    }

    *(reinterpret_cast<char*>(write_ptr) - 1) = static_cast<char>(remainder) + '0';
    return {buffer_end, reinterpret_cast<char*>(write_ptr) - 1};
}

} // namespace Giants
