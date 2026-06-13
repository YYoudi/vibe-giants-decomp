// Giants Engine - Entity Animation Start Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "EntityAnimStart.h"
#include <cstdint>
namespace Giants {
extern int DAT_006ff960;  // Game mode (6 = dedicated)
extern int FUN_0045f460();  // Network check
extern void FUN_00469de0(int a, int b, int c, int d, int e);  // Sound effect
extern uint32_t FUN_004e9cd0(void* out);  // Anim data init

void EntityAnimStart(int param_1)
{
    int entityData = 0;
    if (param_1 != 0) {
        entityData = *reinterpret_cast<int*>(param_1 + 0x14C);
    }

    // Set animation active flag
    *reinterpret_cast<uint32_t*>(param_1 + 300) |= 1;

    // Set scale to 1.0
    *reinterpret_cast<uint32_t*>(entityData + 0xBC) = 0x3F800000;  // 1.0f

    // Save current anim time, set new time
    *reinterpret_cast<uint32_t*>(entityData + 0xB8) = *reinterpret_cast<uint32_t*>(param_1 + 0x370);
    *reinterpret_cast<uint32_t*>(param_1 + 0x370) = 0x3E99999A;  // 0.3f

    // Initialize animation context at +0xC0 if needed
    if (*reinterpret_cast<int*>(entityData + 0xC0) == 0) {
        uint8_t localBuf[16];
        uint32_t animData = FUN_004e9cd0(localBuf);
        *reinterpret_cast<uint32_t*>(entityData + 0xC0) = animData;
    }

    // Set entity scale to 1.0
    *reinterpret_cast<uint32_t*>(param_1 + 0x1D0) = 0x3F800000;  // 1.0f

    // Also set linked entity scale
    int linkedEntity = *reinterpret_cast<int*>(entityData + 0xAC);
    if (linkedEntity != 0) {
        *reinterpret_cast<uint32_t*>(linkedEntity + 0x1D0) = 0x3F800000;
    }

    // On dedicated server: play sound
    if (DAT_006ff960 == 6) {
        int netCheck = FUN_0045f460();
        if (netCheck != 0) {
            FUN_00469de0(0, 0, 10, 0, 0);
            *reinterpret_cast<uint32_t*>(entityData + 0xB4) = *reinterpret_cast<uint32_t*>(param_1 + 0x130);
            *reinterpret_cast<uint32_t*>(param_1 + 0x130) = 0xC;
        }
    }
}
} // namespace Giants
