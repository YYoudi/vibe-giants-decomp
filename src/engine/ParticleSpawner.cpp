// Giants Engine - Particle Spawner Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "ParticleSpawner.h"
#include <cstdlib>
#include <cstdint>
namespace Giants {
extern uint32_t DAT_0073f7f4;  // Particle config
extern uint32_t DAT_007028f4;  // Entity system base
extern uint32_t DAT_0066c580;  // Depth XOR key
extern uint32_t _DAT_0066bd00; // Float random scale constant
extern int FUN_00497dd0();      // Particle alloc
extern void FloatDecompose(uint32_t val, float* a, float* b);  // FUN_006387e0

static float RandFloat() {
    return static_cast<float>(rand()) * *reinterpret_cast<float*>(&_DAT_0066bd00);
}

void ParticleSpawner(uint32_t param_1, int minCount, int maxCount,
                     float xMin, float xMax, float yMin, float yMax,
                     float zMin, float zMax)
{
    float xBase = 0.0f;  // XMM3 initial
    int count = (rand() * (maxCount - minCount + 1) >> 15) + minCount;

    for (int i = 0; i < count; i++) {
        int particle = FUN_00497dd0();
        if (particle == 0) return;

        // Set particle fields
        *reinterpret_cast<uint32_t*>(particle + 4) = DAT_0073f7f4;
        // +0x08..+0x10: copy from local_8 context
        *reinterpret_cast<uint32_t*>(particle + 0x10) = 0;

        // Random position within entity bounds
        float entityZ1 = *reinterpret_cast<float*>(DAT_007028f4 + 0x2B4);
        float entityZ2 = *reinterpret_cast<float*>(DAT_007028f4 + 0x2B8);

        float pz = RandFloat() * (entityZ2 - entityZ1) + entityZ1;
        float px = RandFloat() * (xMax - xBase) + xBase;
        float py = RandFloat() * (yMax - yMin) + yMin;

        // Decompose with XOR depth
        float a, b;
        FloatDecompose(px, &a, &b);
        float depthVal = *reinterpret_cast<float*>(reinterpret_cast<uintptr_t>(&py) ^ static_cast<uintptr_t>(DAT_0066c580));


        *reinterpret_cast<float*>(particle + 0x20) = a * py;
        *reinterpret_cast<float*>(particle + 0x24) = depthVal * b;

        // Random velocity
        *reinterpret_cast<float*>(particle + 0x1C) = RandFloat() * (zMax - zMin) + zMin;

        // Base offset from entity
        *reinterpret_cast<float*>(particle + 0x2C) =
            *reinterpret_cast<float*>(DAT_007028f4 + 0x2A8) +
            *reinterpret_cast<float*>(DAT_007028f4 + 0x2A4);

        // Random initial speed + flag
        *reinterpret_cast<uint32_t*>(particle + 0x28) |= 4;
        *reinterpret_cast<float*>(particle + 0x18) = RandFloat();
    }
}
} // namespace Giants
