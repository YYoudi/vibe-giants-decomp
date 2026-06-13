// Giants Engine - Write Digit Pair Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "WriteDigitPair.h"
#include <cstdint>
namespace Giants {
extern uint16_t DAT_0065d910[];  // Digit pair lookup table (Int64ToWideString.cpp)
void WriteDigitPair(int obj, uint32_t value)
{
    int digitIdx = (value % 100) * 2;
    auto* container = *reinterpret_cast<uint32_t**>(obj + 8);
    // Write first digit
    if (container[3] < container[2] + 1) {
        reinterpret_cast<void(*)(uint32_t)>(*reinterpret_cast<uint32_t*>(container[0]))(container[2] + 1);
    }
    *reinterpret_cast<uint8_t*>(container[1] + container[2]) = DAT_0065d910[digitIdx];
    container[2]++;
    // Write second digit
    container = *reinterpret_cast<uint32_t**>(obj + 8);
    if (container[3] < container[2] + 1) {
        reinterpret_cast<void(*)(uint32_t)>(*reinterpret_cast<uint32_t*>(container[0]))(container[2] + 1);
    }
    *reinterpret_cast<uint8_t*>(container[1] + container[2]) = DAT_0065d910[digitIdx + 1];
    container[2]++;
}
} // namespace Giants
