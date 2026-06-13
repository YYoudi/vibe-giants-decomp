// Giants Engine - Entity Transform Matrix Setup Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "EntityTransformSetup.h"
#include <cstdint>
namespace Giants {

void EntityTransformSetup(int param_1, int param_2)
{
    // Check if transform update is needed
    if (*reinterpret_cast<int*>(param_1 + 0x278) == 0 &&
        (*reinterpret_cast<int*>(*reinterpret_cast<int*>(param_1 + 0x150)) & 0x68) == 0 &&
        param_2 == 0) {
        return;
    }

    // Check entity flags at +0x150
    uint8_t flags = *reinterpret_cast<uint8_t*>(*reinterpret_cast<int*>(param_1 + 0x150));
    if ((flags & 0x28) == 0 && param_2 == 0) {
        return;
    }

    // Read first transform row (+0x2E4..+0x2F0)
    uint32_t row1[4];
    row1[0] = *reinterpret_cast<uint32_t*>(param_1 + 0x2E4);
    row1[1] = *reinterpret_cast<uint32_t*>(param_1 + 0x2E8);
    row1[2] = *reinterpret_cast<uint32_t*>(param_1 + 0x2EC);
    row1[3] = *reinterpret_cast<uint32_t*>(param_1 + 0x2F0);

    // Read second transform row (+0x2F4..+0x304)
    uint32_t row2[4];
    row2[0] = *reinterpret_cast<uint32_t*>(param_1 + 0x2F4);
    row2[1] = *reinterpret_cast<uint32_t*>(param_1 + 0x2F8);
    row2[2] = *reinterpret_cast<uint32_t*>(param_1 + 0x2FC);
    row2[3] = *reinterpret_cast<uint32_t*>(param_1 + 0x300);

    // The real code builds a 4x3 matrix from these rows, applies rotation
    // and scaling, then stores the result. Simplified stub.
}
} // namespace Giants
