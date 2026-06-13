// Giants Engine - Bit Scan Reverse Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "BitScanReverse.h"
#include <cstdint>
namespace Giants {
uint64_t BitScanReverse(int param_1, int param_2, uint32_t param_3, uint32_t param_4)
{
    if (param_4 == 0) return 0;

    // Find highest set bit position
    int bitPos = 31;
    while ((param_4 >> bitPos) == 0) {
        bitPos--;
    }

    // Extract bits from param_3 with computed shift
    uint32_t lowBits = param_3 & ((1u << bitPos) - 1);
    return (static_cast<uint64_t>(param_4) << 32) | lowBits;
}
} // namespace Giants
