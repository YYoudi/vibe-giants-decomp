// Giants Engine - Container Pair Move Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "ContainerPairMove.h"
#include <cstdint>
#include <cstring>
namespace Giants {
extern void VectorCleanupEnd(uint32_t* ptr);  // FUN_0042b650

uint32_t* ContainerPairMove(uint32_t* param_1, uint32_t* param_2, uint32_t* param_3)
{
    uint32_t* dst = param_3;
    for (uint32_t* src = param_1; src != param_2; src += 2) {
        // Zero destination pair
        dst[0] = 0;
        dst[1] = 0;

        // Move source pair to destination
        dst[0] = src[0];
        // Compute corresponding source[1] via offset math
        int offset = reinterpret_cast<int>(dst) + reinterpret_cast<int>(param_1) -
                     reinterpret_cast<int>(param_3);
        dst[1] = *reinterpret_cast<uint32_t*>(offset);

        // Zero source pair
        src[0] = 0;
        *reinterpret_cast<uint32_t*>(reinterpret_cast<int>(src) +
            reinterpret_cast<int>(param_1) - reinterpret_cast<int>(param_3) + 4) = 0;

        dst += 2;
    }

    VectorCleanupEnd(param_1);
    return dst;
}
} // namespace Giants
