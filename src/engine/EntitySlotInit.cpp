// Giants Engine - Entity Slot Init Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "EntitySlotInit.h"
#include <cstdint>
namespace Giants {
extern int FUN_004a67b0();  // Animation state check

void EntitySlotInit(int param_1)
{
    // Get entity data pointer at +0x14C
    int entityData = 0;
    if (param_1 != 0) {
        entityData = *reinterpret_cast<int*>(param_1 + 0x14C);
    }

    // Zero 26 slots at stride 0x1C (7 uint32 per slot) starting at entityData+0x34
    uint32_t* slot = reinterpret_cast<uint32_t*>(entityData + 0x34);
    for (int i = 0x1A; i != 0; i--) {
        *slot = 0;
        slot += 7;  // stride = 0x1C bytes = 7 uint32
    }

    // Get entity state at +0x14C -> +0x20
    int statePtr = 0;
    if (param_1 != 0) {
        statePtr = *reinterpret_cast<int*>(param_1 + 0x14C);
    }
    int state = *reinterpret_cast<int*>(statePtr + 0x20);

    // Process animation state
    if (state == 0) {
        int anim1 = FUN_004a67b0();
        if (anim1 == 0) {
            int anim2 = FUN_004a67b0();
            if (anim2 != 0) return;

            // Check further entity state at +0x18C
            int entityData2 = 0;
            if (param_1 != 0) {
                entityData2 = *reinterpret_cast<int*>(param_1 + 0x14C);
            }
            if (*reinterpret_cast<int*>(entityData2 + 0x18C) == 0) {
                // Additional animation processing (simplified stub)
            }
        }
    }
}
} // namespace Giants
