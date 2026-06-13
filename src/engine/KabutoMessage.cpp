// Giants Engine - Kabuto Message Handler Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "KabutoMessage.h"
#include <cstdint>
namespace Giants {
extern uint32_t DAT_0066bf2c;  // 1.0f
extern uint32_t DAT_0066bfac;  // Health threshold
extern const char* StringLookup(const char* key);  // FUN_005e80c0
extern void FUN_004e95a0();     // Message dispatch

void KabutoMessage(int param_1, int param_2, uint64_t* param_3,
                   uint64_t* param_4, uint32_t param_5, uint32_t param_6)
{
    if (param_2 == 0) return;

    // Validate entity type: must be 1 (Mecc) or 0xF (Kabuto)
    int entity = param_1;
    if (param_1 == 0 ||
        (*reinterpret_cast<int*>(param_1 + 0x22C) != 1 &&
         (param_1 == 0 || *reinterpret_cast<int*>(param_1 + 0x22C) != 0xF))) {
        // Try parent entity at +0x2C4
        entity = *reinterpret_cast<int*>(param_1 + 0x2C4);
        if (entity == 0) return;
        if (*reinterpret_cast<int*>(entity + 0x22C) != 1) {
            if (entity == 0) return;
            if (*reinterpret_cast<int*>(entity + 0x22C) != 0xF) return;
        }
    }
    if (entity == 0) return;

    // Check message ID
    int msgId = *reinterpret_cast<int*>(param_2 + 4);
    float threshold = *reinterpret_cast<float*>(&DAT_0066bf2c);  // 1.0f
    if (msgId == 0x4B7) {
        threshold = *reinterpret_cast<float*>(&DAT_0066bfac);
    } else if (msgId != 0x4B8) {
        return;
    }

    // Check entity health at entityData+0x15C
    int entityData = *reinterpret_cast<int*>(entity + 0x14C);
    float health = *reinterpret_cast<float*>(entityData + 0x15C);
    if (health <= threshold && health != threshold) {
        // Show Kabuto message
        StringLookup("Kabutomessage1");
        FUN_004e95a0();
        return;
    }

    // Process message params (simplified — real code has more branches)
}
} // namespace Giants
