// Giants Engine - Entity Link Match Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "EntityLinkMatch.h"
#include <cstdint>
namespace Giants {
extern uint32_t DAT_007027a8;  // Entity linked list head

void EntityLinkMatch(int param_1)
{
    int baseEntity = (param_1 != 0) ? *reinterpret_cast<int*>(param_1 + 0x14c) : 0;
    int matchId = 0x41c;  // Default building ID

    uint32_t* node = reinterpret_cast<uint32_t*>(DAT_007027a8);

    if (*reinterpret_cast<int*>(param_1 + 0x134) != 0x0B &&
        *reinterpret_cast<int*>(param_1 + 0x134) == 0x67) {
        matchId = 0x48A;  // Smartie ID
    }

    for (; node != nullptr; node = reinterpret_cast<uint32_t*>(*node)) {
        int entityData = node[3];  // +0xC entity data
        int spawnType = *reinterpret_cast<int*>(entityData + 0x22C);

        if (spawnType == 0x27) {
            // Player spawn — match by level ID
            if (*reinterpret_cast<int*>(*reinterpret_cast<int*>(entityData + 0x14C) + 0x14) ==
                *reinterpret_cast<int*>(baseEntity + 0x134)) {
                *reinterpret_cast<int*>(baseEntity + 0x6C) = entityData;
            }
        } else if (spawnType == 0x60 && *reinterpret_cast<int*>(entityData + 4) == matchId) {
            // Building spawn — match by position and type
            if (*reinterpret_cast<int*>(baseEntity + 0x134) == 0 &&
                *reinterpret_cast<int*>(entityData + 0x1C0) == 0 &&
                *reinterpret_cast<int*>(entityData + 0x134) ==
                static_cast<int>(*reinterpret_cast<float*>(param_1 + 0x144))) {
                *reinterpret_cast<int*>(baseEntity + 0x134) = entityData;
                *reinterpret_cast<int*>(baseEntity + 0x138) = -1;
                *reinterpret_cast<uint32_t*>(baseEntity + 0x140) =
                    *reinterpret_cast<uint32_t*>(entityData + 0x148);
            }
            if (*reinterpret_cast<float*>(baseEntity + 0x13C) == 0.0f &&
                *reinterpret_cast<int*>(entityData + 0x1C0) ==
                *reinterpret_cast<int*>(baseEntity + 0x60) &&
                *reinterpret_cast<int*>(entityData + 0x134) ==
                static_cast<int>(*reinterpret_cast<float*>(param_1 + 0x144))) {
                *reinterpret_cast<float*>(baseEntity + 0x13C) =
                    static_cast<float>(*reinterpret_cast<int*>(
                        *reinterpret_cast<int*>(entityData + 0x14C) + 0x50));
            }
        }
    }
}
} // namespace Giants
