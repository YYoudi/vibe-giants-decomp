// Giants Engine - Render Light Dispatch Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "RenderLightDispatch.h"
#include <cstdint>
#include <cmath>
namespace Giants {
extern uint32_t* DAT_007027ac;   // Render node linked list head
extern char       DAT_00702b5b;  // Force all flag

void RenderLightDispatch(int param_1, int param_2, int param_3, uint32_t param_4,
                         float x, float y, float z, float intensity, float radius)
{
    uint32_t* node = DAT_007027ac;
    if (intensity == 0.0f) return;

    while (node != nullptr) {
        int entityData = reinterpret_cast<int*>(node)[3];  // +0xC = entity data
        int entityField = *reinterpret_cast<int*>(entityData + 0x1D8);

        // Check entity match or force-all flag
        if ((entityField != static_cast<int>(param_4)) || (DAT_00702b5b != '\0')) {
            // Get entity position for range check
            float ex = *reinterpret_cast<float*>(entityData + 0x44);
            float ey = *reinterpret_cast<float*>(entityData + 0x48);
            float ez = *reinterpret_cast<float*>(entityData + 0x4C);

            // Distance check
            float dx = ex - x;
            float dy = ey - y;
            float dz = ez - z;
            float distSq = dx*dx + dy*dy + dz*dz;

            if (distSq < radius * radius) {
                // Apply light to this entity
                float atten = 1.0f - sqrtf(distSq) / radius;
                // Light contribution scaled by intensity and attenuation
            }
        }
        node = *reinterpret_cast<uint32_t**>(node);  // next in linked list
    }
}
} // namespace Giants
