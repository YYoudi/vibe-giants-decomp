// Giants Engine - Wide Char Vector Push N Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "WideCharPushN.h"
#include <cstdint>
namespace Giants {
uint32_t* WideCharPushN(uint32_t* out, int count, uint32_t* container, const uint16_t* value)
{
    if (count < 1) {
        *out = reinterpret_cast<uint32_t>(container);
        return out;
    }
    do {
        // Grow if needed via vtable[0]
        if (container[3] < container[2] + 1) {
            reinterpret_cast<void(*)(uint32_t)>(*reinterpret_cast<uint32_t*>(container[0]))(container[2] + 1);
        }
        *reinterpret_cast<uint16_t*>(container[1] + container[2] * 2) = *value;
        container[2]++;
        count--;
    } while (count != 0);
    *out = reinterpret_cast<uint32_t>(container);
    return out;
}
} // namespace Giants
