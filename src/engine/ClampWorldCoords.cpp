// Giants Engine - Clamp World Coords Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "ClampWorldCoords.h"
#include <cstdint>
namespace Giants {
extern uint32_t DAT_00701a3c;  // Global scene/camera state
extern uint32_t DAT_0066bf2c;  // 1.0f constant

float* ClampWorldCoords(float* output, int param_2, float param_3, float param_4)
{
    uint32_t gState = DAT_00701a3c;
    float x = param_3, y = param_4;

    if (*reinterpret_cast<uint8_t*>(gState + 0x1af0) & 0x10) {
        float minX = *reinterpret_cast<float*>(gState + 0x1b2c);
        float minY = *reinterpret_cast<float*>(gState + 0x1b30);
        float maxX = *reinterpret_cast<float*>(gState + 0x1b34);
        float maxY = *reinterpret_cast<float*>(gState + 0x1b38);

        if (minX < 0.0f || maxX < 0.0f) minX = *reinterpret_cast<float*>(param_2 + 0x1c);
        else if (minX <= x && x <= maxX) x = x;
        if (minY < 0.0f || maxY < 0.0f) minY = *reinterpret_cast<float*>(param_2 + 0x20);
        else if (minY <= y && y <= maxY) y = y;

        x = static_cast<float>(static_cast<int>(x));
        y = static_cast<float>(static_cast<int>(y));
    }

    uint32_t flags = *reinterpret_cast<uint32_t*>(param_2 + 8);
    if ((flags & 0x1000040) == 0) {
        float camMinX = *reinterpret_cast<float*>(gState + 0x152c);
        float camMinY = *reinterpret_cast<float*>(gState + 0x1530);
        if (x < camMinX) x = camMinX;
        if (y < camMinY) y = camMinY;

        float scrollX = 0.0f, scrollY = 0.0f;
        if ((flags & 1) == 0) {
            scrollX = *reinterpret_cast<float*>(gState + 0x1934) *
                      *reinterpret_cast<float*>(param_2 + 0x270);
            int parent = *reinterpret_cast<int*>(param_2 + 0x318);
            if (parent != 0)
                scrollX *= *reinterpret_cast<float*>(parent + 0x270);
            scrollX += *reinterpret_cast<float*>(gState + 0x1554) * 2.0f;
        }
        if (flags & 0x400) {
            scrollY = *reinterpret_cast<float*>(gState + 0x1934) *
                      *reinterpret_cast<float*>(param_2 + 0x270);
            int parent = *reinterpret_cast<int*>(param_2 + 0x318);
            if (parent != 0)
                scrollY *= *reinterpret_cast<float*>(parent + 0x270);
            scrollY += *reinterpret_cast<float*>(param_2 + 0x148) +
                       *reinterpret_cast<float*>(gState + 0x1554) * 2.0f;
        }

        float baseY = *reinterpret_cast<float*>(gState + 0x1524) -
                      *reinterpret_cast<float*>(&DAT_0066bf2c);
        float clampedBase = (baseY > 0.0f) ? baseY : 0.0f;
        float totalY = clampedBase + scrollY + scrollX;
        if (y < totalY) y = totalY;
    }

    output[0] = x;
    output[1] = y;
    return output;
}
} // namespace Giants
