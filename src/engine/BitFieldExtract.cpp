// Giants Engine - Bit Field Extract Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "BitFieldExtract.h"
#include <cstdint>
namespace Giants {
uint32_t BitFieldExtract(uint32_t value, uint8_t offset, uint8_t width)
{
    uint32_t mask = (1u << width) - 1;
    return (value >> offset) & mask;
}
} // namespace Giants
