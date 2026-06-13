// Giants Engine - Memory Compare Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
// re-agent verdict: PASS
#include "MemoryCompare.h"
#include <cstring>

namespace Giants {

bool MemoryCompare(const uint8_t* lhs, uint32_t lhs_size, const uint8_t* rhs, uint32_t rhs_size)
{
    if (lhs_size != rhs_size)
        return false;

    if (lhs_size == 0)
        return true;

    uint32_t remaining;
    while ((remaining = lhs_size - 4, 3 < lhs_size))
    {
        if (*reinterpret_cast<const int32_t*>(lhs) != *reinterpret_cast<const int32_t*>(rhs))
            goto byte_compare;

        lhs += 4;
        rhs += 4;
        lhs_size = remaining;
    }

    if (remaining != 0xfffffffc)
    {
    byte_compare:
        bool is_less = *lhs < *rhs;
        if ((*lhs != *rhs) ||
            ((remaining != 0xfffffffd) &&
             ((is_less = lhs[1] < rhs[1], lhs[1] != rhs[1]) ||
              ((remaining != 0xfffffffe) &&
               ((is_less = lhs[2] < rhs[2], lhs[2] != rhs[2]) ||
                ((remaining != 0xffffffff) &&
                 (is_less = lhs[3] < rhs[3], lhs[3] != rhs[3])))))))
        {
            return (static_cast<uint32_t>(-is_less) | 1) == 0;
        }
    }

    return true;
}

} // namespace Giants
