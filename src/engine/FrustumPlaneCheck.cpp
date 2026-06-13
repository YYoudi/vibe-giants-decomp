// Giants Engine - Frustum Plane Check Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "FrustumPlaneCheck.h"
#include <cstdint>
namespace Giants {
// View-projection matrix constants (DAT_00685810..DAT_0068584c)
extern float DAT_00685810, DAT_00685814, DAT_0068581c;
extern float DAT_00685820, DAT_00685824, DAT_0068582c;
extern float DAT_00685830, DAT_00685834, DAT_0068583c;
extern float DAT_00685840, DAT_00685844, DAT_0068584c;
extern float DAT_0067f47c;  // Near plane threshold
extern float DAT_0067f0f4;  // Far plane threshold

uint32_t FrustumPlaneCheck(float* point, float* param_2, float* param_3)
{
    float px = point[0], py = point[1], pz = point[2];

    // Transform point by view-projection matrix
    float w = px * DAT_00685810 + py * DAT_00685820 + pz * DAT_00685830 + DAT_00685840;
    float z = px * DAT_0068581c + py * DAT_0068582c + pz * DAT_0068583c + DAT_0068584c;
    float y = px * DAT_00685814 + py * DAT_00685824 + pz * DAT_00685834 + DAT_00685844;

    // Z classification (near/far planes)
    uint32_t result = 0;
    if (z >= DAT_0067f47c) {
        result = (z > DAT_0067f0f4) ? 2 : 0;
    } else {
        result = 1;
    }

    // X classification (left/right planes) using XOR depth comparison
    float xorZ = static_cast<float>(reinterpret_cast<uint32_t&>(z) ^ DAT_0066c580);
    if (xorZ <= w) {
        if (z < w) {
            result = result | 8;
        }
    } else {
        result = result | 4;
    }

    // Y classification (top/bottom planes)
    if (y <= w) {
        if (y < w) {
            result = result | 0x20;
        }
    } else {
        result = result | 0x10;
    }

    return result;
}
} // namespace Giants
