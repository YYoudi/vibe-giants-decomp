// Giants Engine - Entity Look-At Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "EntityLookAt.h"
#include <cstdint>
namespace Giants {
extern float FUN_006389d0(int pos, int target);  // Angle calculation

void EntityLookAt(int entity, int target)
{
    *reinterpret_cast<uint8_t*>(entity + 0x25C) = 0;  // Clear look flag

    if (target != 0) {
        // Compute angle from entity position (+0xF0) to target
        float angle = FUN_006389d0(entity + 0xF0, target);

        // Set entity facing direction
        *reinterpret_cast<float*>(entity + 0x120) = angle;
    }
}
} // namespace Giants
