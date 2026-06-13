// Giants Engine - Entity Sound Randomizer Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "EntitySoundRandomizer.h"
#include <cstdlib>
#include <cstdint>
namespace Giants {
extern uint32_t DAT_007028f4;   // Entity system base
extern uint32_t _DAT_0066bd00;  // Float random scale constant
extern float FUN_006389d0(int a, int b);  // Vector distance
extern void FUN_00638f10(uint32_t* val);   // Depth encode

void EntitySoundRandomizer(int param_1)
{
    int entityData = 0;
    if (param_1 != 0) {
        entityData = *reinterpret_cast<int*>(param_1 + 0x14C);
    }

    uint32_t* data = reinterpret_cast<uint32_t*>(entityData);
    if (data[3] == 0) return;  // No linked entity

    // Compute distance from linked entity to this one
    float dist = FUN_006389d0(data[3] + 0xF0, param_1 + 0xF0);

    // Random position offset (param_1 passed via XMM1)
    float baseOffset = 0.0f;  // XMM1 initial value
    float range = static_cast<float>(dist) - baseOffset;
    int r = rand();
    float randomPos = static_cast<float>(r) *
        *reinterpret_cast<float*>(&_DAT_0066bd00) *
        ((dist + baseOffset) - range) + range;

    data[1] = *reinterpret_cast<uint32_t*>(&randomPos);
    FUN_00638f10(&data[1]);

    // Y-axis random offset from entity bounds
    float minY = *reinterpret_cast<float*>(DAT_007028f4 + 200);   // +0xC8
    float maxY = *reinterpret_cast<float*>(DAT_007028f4 + 0xCC);
    r = rand();
    float randomY = static_cast<float>(r) *
        *reinterpret_cast<float*>(&_DAT_0066bd00) * (maxY - minY) + minY;
    data[2] = *reinterpret_cast<uint32_t*>(&randomY);

    // Copy Z from entity system
    data[0] = *reinterpret_cast<uint32_t*>(DAT_007028f4 + 0xD0);
}
} // namespace Giants
