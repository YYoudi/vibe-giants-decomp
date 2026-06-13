// Giants Engine - Render State Apply Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "RenderStateApply.h"
#include <cstdint>
namespace Giants {
void RenderStateApply(int* param_1, int* param_2)
{
    // Query device capabilities via vtable
    auto queryCaps = reinterpret_cast<uint32_t(*)(int*)>(reinterpret_cast<int*>(param_1[0]) + 8);
    uint32_t caps = queryCaps(param_2);

    // Apply to device
    auto applyToDevice = reinterpret_cast<void(*)(int, uint32_t)>(reinterpret_cast<int*>(param_2[0]) + 0xC);
    applyToDevice(param_1[1], caps);

    // Release texture stages if set
    auto releaseStage = reinterpret_cast<void(*)(int, int)>(reinterpret_cast<int*>(param_1[1]) + 0x10);
    if (param_1[0x34] != 0) releaseStage(0, param_1[0x34]);
    if (param_1[0x35] != 0) releaseStage(1, param_1[0x35]);
    if (param_1[0x36] != 0) releaseStage(2, param_1[0x36]);

    // Update vertex processing flags
    uint32_t vertexFlags = param_1[0x14] & 0xF00;
    if (vertexFlags == 0x600 || vertexFlags == 0x700) {
        param_1[0x14] |= 0x50000;
    }

    // Apply vertex buffer if dirty
    if (reinterpret_cast<char*>(param_1[0x30]) != '\0') {
        auto applyVB = reinterpret_cast<void(*)(int*, int)>(reinterpret_cast<int*>(param_1[0x31]) + 0x10);
        applyVB(&param_1[8], 0xA0);
        *reinterpret_cast<char*>(&param_1[0x30]) = 0;
    }
}
} // namespace Giants
