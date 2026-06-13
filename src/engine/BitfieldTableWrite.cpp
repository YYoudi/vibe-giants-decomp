// Giants Engine - Bitfield Table Write Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "BitfieldTableWrite.h"
#include <cstdint>
namespace Giants {
void BitfieldTableWrite(uint32_t* table, uint32_t index, uint32_t value)
{
    // Compute slot and bit offset from linear index
    uint32_t slot = index >> 5;       // index / 32
    uint32_t shift = index & 0x1F;    // index % 32

    // Write value to the computed bitfield position
    uint32_t mask = 1u << shift;
    if (value)
        table[slot] |= mask;
    else
        table[slot] &= ~mask;
}
} // namespace Giants
