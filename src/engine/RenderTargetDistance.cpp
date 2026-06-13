// Giants Engine - Render Target Distance Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "RenderTargetDistance.h"
#include <cstdint>
namespace Giants {
extern uint32_t DAT_0066be20;  // 0.5f constant
extern void FUN_005fac30(float* out);  // Transform helper

void RenderTargetDistance(int type, int entity, int target, float* outPos)
{
    float dx = 0.0f, dy = 0.0f, dz = 0.0f;

    if (static_cast<uint32_t>(type - 0x33) < 0x14) {
        // Type in [0x33..0x47]: use entity position
        if (outPos == nullptr && target != 0) {
            outPos = reinterpret_cast<float*>(target + 0xF0);
        }

        if (outPos != nullptr) {
            float* entityPos = reinterpret_cast<float*>(entity + 0xF0);
            int meshIdx = *reinterpret_cast<int*>(entity + 0x60);

            if (meshIdx != 0xFE) {
                int meshList = *reinterpret_cast<int*>(entity + 8);
                int meshData = *reinterpret_cast<int*>(meshList + 8 + meshIdx * 4);
                if (meshData != 0) {
                    // Compute bounding box center * 0.5
                    float sx = (*reinterpret_cast<float*>(meshData + 0x18) +
                                *reinterpret_cast<float*>(meshData + 0x0C)) *
                               *reinterpret_cast<float*>(&DAT_0066be20);
                    float sy = (*reinterpret_cast<float*>(meshData + 0x1C) +
                                *reinterpret_cast<float*>(meshData + 0x10)) *
                               *reinterpret_cast<float*>(&DAT_0066be20);
                    float sz = (*reinterpret_cast<float*>(meshData + 0x20) +
                                *reinterpret_cast<float*>(meshData + 0x14)) *
                               *reinterpret_cast<float*>(&DAT_0066be20);

                    float transformed[3];
                    FUN_005fac30(transformed);
                    entityPos = transformed;
                }
            }
            dx = entityPos[0] - outPos[0];
            dy = entityPos[1] - outPos[1];
            dz = entityPos[2] - outPos[2];
        }
    } else {
        // Other types: use delta between +0xF0 and +0xFC
        if (target == 0) target = entity;
        dx = *reinterpret_cast<float*>(target + 0xF0) - *reinterpret_cast<float*>(target + 0xFC);
        dy = *reinterpret_cast<float*>(target + 0xF4) - *reinterpret_cast<float*>(target + 0x100);
        dz = *reinterpret_cast<float*>(target + 0xF8) - *reinterpret_cast<float*>(target + 0x104);
    }
    // Results stored via XMM registers (caller reads them)
}
} // namespace Giants
