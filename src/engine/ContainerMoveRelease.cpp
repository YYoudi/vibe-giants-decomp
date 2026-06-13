// Giants Engine - Container Move Release Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "ContainerMoveRelease.h"
#include <cstdint>
namespace Giants {
extern uint32_t* SharedPtrReleaseRangeImpl(uint32_t* a, uint32_t* b, uint32_t c);  // FUN_0044f870

uint32_t* ContainerMoveRelease(uint32_t* param_1, uint32_t* param_2,
                               uint32_t* param_3, uint32_t param_4)
{
    uint32_t* dst = param_3;
    for (uint32_t* src = param_1; src != param_2; src += 2) {
        // Zero destination pair
        dst[0] = 0;
        dst[1] = 0;

        // Move source pair to destination
        dst[0] = src[0];
        int offset = reinterpret_cast<int>(dst) + reinterpret_cast<int>(param_1) -
                     reinterpret_cast<int>(param_3);
        dst[1] = *reinterpret_cast<uint32_t*>(offset);

        // Zero source pair
        src[0] = 0;
        *reinterpret_cast<uint32_t*>(reinterpret_cast<int>(src) +
            reinterpret_cast<int>(param_1) - reinterpret_cast<int>(param_3) + 4) = 0;

        dst += 2;
    }

    SharedPtrReleaseRangeImpl(dst, dst, param_4);
    return dst;
}
} // namespace Giants
