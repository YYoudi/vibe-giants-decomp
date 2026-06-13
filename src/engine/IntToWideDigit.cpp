// Giants Engine - Integer to Wide Digit String Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "IntToWideDigit.h"
#include <cstdint>
namespace Giants {
extern uint16_t DAT_0065d910[];  // Digit pair lookup: [0]="00",[1]="10",...,[99]="99"

uint64_t IntToWideDigit(int buffer, uint32_t value, int offset)
{
    int16_t* writePos = reinterpret_cast<int16_t*>(buffer + offset * 2);
    int16_t* endPos = writePos;

    // Write digit pairs from right to left (groups of 100)
    while (value > 99) {
        writePos -= 2;
        writePos[0] = static_cast<int16_t>(reinterpret_cast<char*>(DAT_0065d910)[(value % 100) * 2]);
        writePos[1] = static_cast<int16_t>(reinterpret_cast<char*>(DAT_0065d910)[(value % 100) * 2 + 1]);
        value = value / 100;
    }

    if (value > 9) {
        // Two-digit remainder
        writePos -= 2;
        writePos[0] = static_cast<int16_t>(reinterpret_cast<char*>(DAT_0065d910)[value * 2]);
        writePos[1] = static_cast<int16_t>(reinterpret_cast<char*>(DAT_0065d910)[value * 2 + 1]);
    } else {
        // Single digit
        writePos -= 1;
        writePos[0] = static_cast<int16_t>(value + 0x30);
    }

    // Return {endPos, writePos} packed as uint64_t
    return (static_cast<uint64_t>(reinterpret_cast<uint32_t>(endPos)) << 32) |
            static_cast<uint64_t>(reinterpret_cast<uint32_t>(writePos));
}
} // namespace Giants
