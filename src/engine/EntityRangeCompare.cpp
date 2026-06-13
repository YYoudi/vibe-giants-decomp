// Giants Engine - Entity Range Compare Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "EntityRangeCompare.h"
#include <cstdint>
#include <cmath>
namespace Giants {
int EntityRangeCompare(float* entity1, float* entity2)
{
    // Compare distance values (stored at +0x10 offset in entity structs)
    float dist1 = entity1[4];   // +0x10 = 4th float
    float dist2 = entity2[4];   // +0x10 = 4th float

    // Return comparison for qsort-style ordering
    if (dist1 < dist2) return -1;
    if (dist1 > dist2) return 1;
    return 0;
}
} // namespace Giants
