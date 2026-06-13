// Giants Engine - Entity Render Position Calc Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "EntityRenderPosition.h"
#include <cstdint>
namespace Giants {
extern uint32_t DAT_0066be20;  // 0.5f constant
extern void FUN_0063ed60(void* out, float* params);   // Transform build
extern void FUN_0063f300(void* out, float* position);  // Position apply

void EntityRenderPosition(uint32_t param_1, int param_2)
{
    if (param_2 == 0) return;

    // Compute scale: entity height * scale * 0.5
    float height = *reinterpret_cast<float*>(param_2 + 0x370);
    float scale = *reinterpret_cast<float*>(param_2 + 0x238);
    float halfScale = *reinterpret_cast<float*>(&DAT_0066be20);  // 0.5f
    float renderScale = height * scale * halfScale;

    // Check entity flags at +0x150
    uint32_t* flagPtr = *reinterpret_cast<uint32_t**>(param_2 + 0x150);
    if (flagPtr != nullptr && (*flagPtr & 0x200) != 0) {
        renderScale = 0.0f;
    }

    // Build transform params
    float params[3];
    params[0] = *reinterpret_cast<float*>(param_2 + 0x1A0);  // X offset
    params[1] = *reinterpret_cast<float*>(param_2 + 0x1A0);  // Same offset
    params[2] = renderScale;

    uint8_t transformBuf[68];
    FUN_0063ed60(transformBuf, params);

    // Build position from entity data
    float position[3];
    position[0] = *reinterpret_cast<float*>(param_2 + 0xF0);
    position[1] = *reinterpret_cast<float*>(param_2 + 0xF4);
    position[2] = renderScale + *reinterpret_cast<float*>(param_2 + 0xF8);

    uint8_t posBuf[68];
    FUN_0063f300(posBuf, position);

    // The real code then applies the transform via PTR_FUN_0067d208
    // (render device vtable call — simplified stub)
}
} // namespace Giants
