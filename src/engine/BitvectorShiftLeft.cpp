// Giants Engine - Bitvector Shift Left Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "BitvectorShiftLeft.h"
#include <cstdint>
namespace Giants {
void BitvectorShiftLeft(uint32_t* bitvector, int shiftBits)
{
    if (bitvector == nullptr || shiftBits <= 0) return;

    int wordShift = shiftBits / 32;
    int bitShift = shiftBits % 32;

    if (bitShift == 0) {
        // Simple word-aligned shift
        int i = 0;
        while (bitvector[i] != 0) {
            bitvector[i] = bitvector[i + wordShift];
            i++;
        }
    } else {
        // Bit-level shift with carry propagation
        int i = 0;
        uint32_t carry = 0;
        while (bitvector[i] != 0 || bitvector[i + wordShift] != 0) {
            uint32_t src = bitvector[i + wordShift];
            uint32_t newCarry = src >> (32 - bitShift);
            bitvector[i] = (src << bitShift) | carry;
            carry = newCarry;
            i++;
        }
    }
}
} // namespace Giants
