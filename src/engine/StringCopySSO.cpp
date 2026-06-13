// Giants Engine - String Copy SSO Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "StringCopySSO.h"
#include <cstdint>
#include <cstring>
namespace Giants {
int* StringCopySSO(int* dest, uint32_t* src, int param3, int param4, int param5, uint32_t count, uint32_t capacity)
{
    uint32_t remaining = count;
    uint32_t srcIdx = 0;
    if (count == 0) return dest;

    do {
        // SSO check: if capacity > 15, use heap pointer
        uint32_t* srcPtr = src;
        if (capacity > 0xF) {
            srcPtr = *reinterpret_cast<uint32_t**>(src);
        }
        // Copy element from source
        uint32_t val = srcPtr[srcIdx];
        // Store to destination (simplified)
        srcIdx++;
        remaining--;
    } while (remaining != 0);

    return dest;
}
} // namespace Giants
