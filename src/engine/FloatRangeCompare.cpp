// Giants Engine - Float Range Compare Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "FloatRangeCompare.h"
#include <cstdint>
namespace Giants {
int FloatRangeCompare(float* mins, float* maxs, float* point, float* result)
{
    // Check X range
    int out = 0;
    if (point[0] < mins[0]) out |= 1;
    if (point[0] > maxs[0]) out |= 2;

    // Check Y range
    if (point[1] < mins[1]) out |= 4;
    if (point[1] > maxs[1]) out |= 8;

    // Check Z range
    if (point[2] < mins[2]) out |= 16;
    if (point[2] > maxs[2]) out |= 32;

    if (result) {
        result[0] = (out == 0) ? 1.0f : 0.0f;
    }

    return out;  // 0 = inside AABB
}
} // namespace Giants
