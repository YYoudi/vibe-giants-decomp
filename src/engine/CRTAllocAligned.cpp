// Giants Engine - CRT Alloc Aligned Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "CRTAllocAligned.h"
#include <cstdint>
namespace Giants {
extern uint32_t DAT_006fd0a8;  // Heap allocator function pointer

uint32_t CRTAllocAligned(int size)
{
    auto alloc = reinterpret_cast<uint32_t(*)(int)>(DAT_006fd0a8);
    uint32_t raw = alloc(size + 0x10);            // Extra 16 bytes for alignment
    uint32_t aligned = (raw + 0x10) & 0xFFFFFFF0; // Align up to 16
    *reinterpret_cast<uint32_t*>(aligned - 4) = raw & 0xF;  // Store offset for free
    return aligned;
}
} // namespace Giants
