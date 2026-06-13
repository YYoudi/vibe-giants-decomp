// Giants Engine - Entity Physics Velocity Update Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "EntityPhysicsUpdate.h"
#include <cstdint>
namespace Giants {
extern uint32_t DAT_0066be20;  // 0.5f time scale
extern void FUN_0062a0b0();    // Physics time step

void EntityPhysicsUpdate(int param_1)
{
    // Compute velocity from position delta
    float dx = *reinterpret_cast<float*>(param_1 + 0xF0) - *reinterpret_cast<float*>(param_1 + 0xFC);
    float dy = *reinterpret_cast<float*>(param_1 + 0xF4) - *reinterpret_cast<float*>(param_1 + 0x100);
    float dz = *reinterpret_cast<float*>(param_1 + 0xF8) - *reinterpret_cast<float*>(param_1 + 0x104);

    if (*reinterpret_cast<int*>(param_1 + 0x150) == 0) {
        float dt = dz;  // Use dz as time base
        FUN_0062a0b0();

        float accX = *reinterpret_cast<float*>(param_1 + 0x174);
        float accY = *reinterpret_cast<float*>(param_1 + 0x178);
        float accZ = *reinterpret_cast<float*>(param_1 + 0x17C);
        float halfDt = *reinterpret_cast<float*>(&DAT_0066be20) * dt;

        dx += (accX + *reinterpret_cast<float*>(param_1 + 0x180)) * halfDt;
        dy += (accY + *reinterpret_cast<float*>(param_1 + 0x184)) * halfDt;
        dz += (accZ + *reinterpret_cast<float*>(param_1 + 0x188)) * halfDt;

        // Save old acceleration
        *reinterpret_cast<uint64_t*>(param_1 + 0x180) = *reinterpret_cast<uint64_t*>(param_1 + 0x174);
        *reinterpret_cast<uint32_t*>(param_1 + 0x188) = *reinterpret_cast<uint32_t*>(param_1 + 0x17C);

        // Apply damping to X axis
        float damping = *reinterpret_cast<float*>(param_1 + 0x250);
        if (accX > 0.0f) {
            accX -= dt * damping;
            *reinterpret_cast<float*>(param_1 + 0x174) = accX;
            if (accX < 0.0f) *reinterpret_cast<float*>(param_1 + 0x174) = 0.0f;
        } else if (accX < 0.0f) {
            accX = dt * damping + accX;
            *reinterpret_cast<float*>(param_1 + 0x174) = accX;
            if (accX > 0.0f) *reinterpret_cast<float*>(param_1 + 0x174) = 0.0f;
        }

        // Apply damping to Y axis
        if (accY > 0.0f) {
            accY -= dt * damping;
            *reinterpret_cast<float*>(param_1 + 0x178) = accY;
            if (accY < 0.0f) *reinterpret_cast<float*>(param_1 + 0x178) = 0.0f;
        } else if (accY < 0.0f) {
            accY = dt * damping + accY;
            *reinterpret_cast<float*>(param_1 + 0x178) = accY;
            if (accY > 0.0f) *reinterpret_cast<float*>(param_1 + 0x178) = 0.0f;
        }
    }
    // Final velocity stored via XMM registers
}
} // namespace Giants
