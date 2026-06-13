// Giants Engine - Camera Scroll Update Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "CameraScrollUpdate.h"
#include <cstdint>
#include <cmath>
namespace Giants {
extern uint32_t DAT_00701a3c;  // Global scene state
extern void CameraScrollFinish();  // FUN_0047c240

void CameraScrollUpdate(float* param_1)
{
    uint32_t gState = DAT_00701a3c;
    int camPtr = *reinterpret_cast<int*>(gState + 0x1A6C);

    if (*reinterpret_cast<char*>(camPtr + 0x87) == '\0') {
        float delta = 0.0f;  // in_XMM1_Da - passed via register
        // Clamped delta: max(0, cameraMax - delta)
        if (0.0f <= delta) {
            float remaining = *reinterpret_cast<float*>(camPtr + 0xF4) - delta;
            if (0.0f <= remaining) {
                delta = remaining;  // Actually: clamped remaining
            }
        }

        float newX = param_1[0] + *reinterpret_cast<float*>(camPtr + 0xC4);
        float maxY = *reinterpret_cast<float*>(camPtr + 0xE8);
        float newY = delta + param_1[1];
        if (maxY <= newY) maxY = newY;

        // Update camera position state
        *reinterpret_cast<float*>(camPtr + 0xD0) = *reinterpret_cast<float*>(camPtr + 200);
        *reinterpret_cast<float*>(camPtr + 0xCC) = newX;
        *reinterpret_cast<float*>(camPtr + 0xC4) =
            static_cast<float>(static_cast<int>(
                *reinterpret_cast<float*>(camPtr + 0xFC) +
                *reinterpret_cast<float*>(camPtr + 0xC) +
                *reinterpret_cast<float*>(camPtr + 0x100)));

        float scrollSpeed = *reinterpret_cast<float*>(gState + 0x1564);
        float maxScrollX = *reinterpret_cast<float*>(camPtr + 0xDC);
        if (maxScrollX <= newX) maxScrollX = newX;
        *reinterpret_cast<float*>(camPtr + 0xDC) = maxScrollX;

        float totalY = static_cast<float>(static_cast<int>(
            *reinterpret_cast<float*>(camPtr + 200) + maxY + scrollSpeed));
        *reinterpret_cast<float*>(camPtr + 200) = totalY;

        totalY -= scrollSpeed;
        *reinterpret_cast<float*>(camPtr + 0xF0) = maxY;
        *reinterpret_cast<uint32_t*>(camPtr + 0xE8) = 0;

        float maxTotalY = *reinterpret_cast<float*>(camPtr + 0xE0);
        if (maxTotalY <= totalY) maxTotalY = totalY;
        *reinterpret_cast<float*>(camPtr + 0xE0) = maxTotalY;

        float maxDelta = *reinterpret_cast<float*>(camPtr + 0xF4);
        // Note: delta comes from register, simplified here
        *reinterpret_cast<uint32_t*>(camPtr + 0xF4) = 0;
        *reinterpret_cast<float*>(camPtr + 0xF8) = maxDelta;

        if (*reinterpret_cast<int*>(camPtr + 400) == 0) {
            CameraScrollFinish();
        }
    }
}
} // namespace Giants
