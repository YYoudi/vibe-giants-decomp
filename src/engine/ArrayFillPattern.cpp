// Giants Engine - Array Fill Pattern Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "ArrayFillPattern.h"
#include <cstdint>
namespace Giants {
void ArrayFillPattern(uint32_t* dest, uint32_t value, uint32_t count)
{
    for (uint32_t i = 0; i < count; i++) {
        dest[i] = value;
    }
}
} // namespace Giants
