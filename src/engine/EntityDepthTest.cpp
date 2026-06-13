// Giants Engine - Entity Depth Test Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "EntityDepthTest.h"
#include <cstdint>
namespace Giants {
uint32_t DAT_0066c580 = 0;   // Depth XOR key
uint32_t DAT_0066bce4 = 0;   // Depth threshold
int DAT_00702774 = 0;        // Game state pointer

bool EntityDepthTest(int entity1, int entity2)
{
    // Type 0x59 entities never pass the test
    if (*reinterpret_cast<int*>(entity1 + 0x22c) == 0x59) {
        return false;
    }

    // Check visibility flag
    uint32_t visFlag = ~(*reinterpret_cast<uint32_t*>(entity1 + 0x214) >> 17) & 1;
    if ((*reinterpret_cast<uint32_t*>(entity1 + 0x124) & 0x4000c000) != 0) {
        visFlag = 1;
    }

    if (visFlag != 0) return false;

    // Check entity type 2 with flag 0x2000000
    if (*reinterpret_cast<int*>(entity1 + 0x22c) == 2) {
        if ((*reinterpret_cast<uint32_t*>(entity1 + 300) & 0x2000000) != 0) {
            return false;
        }
    }

    // Check if same player
    if (*reinterpret_cast<int*>(entity1 + 0x1d8) == *reinterpret_cast<int*>(DAT_00702774 + 0x1d8)) {
        return false;
    }

    // Compute depth test: dot product of (e1-e2) with e2's facing vector
    float dx = *reinterpret_cast<float*>(entity1 + 0xf0) - *reinterpret_cast<float*>(entity2 + 0xf0);
    float dy = *reinterpret_cast<float*>(entity1 + 0xf4) - *reinterpret_cast<float*>(entity2 + 0xf4);
    float dz = *reinterpret_cast<float*>(entity1 + 0xf8) - *reinterpret_cast<float*>(entity2 + 0xf8);

    // Depth components with XOR key
    float depthX = dx * static_cast<float>(*reinterpret_cast<uint32_t*>(entity2 + 0x2ec) ^ DAT_0066c580);
    float depthY = dy * *reinterpret_cast<float*>(entity2 + 0x2fc);
    float depthZ = dz * *reinterpret_cast<float*>(entity2 + 0x30c);

    return DAT_0066bce4 <= (depthX - depthY - depthZ);
}
} // namespace Giants
