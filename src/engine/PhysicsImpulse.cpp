// Giants Engine - Physics Impulse Update Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "PhysicsImpulse.h"
#include <cstdint>
#include <cmath>
namespace Giants {
// ═══════════════════════════════════════════════════════════════════
// PhysicsImpulseUpdate (FUN_0055d110) — 14 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Processes velocity/impulse on an entity. Uses 3D vector math
// for direction and speed calculations. Ground truth: simplified
// stub preserving the float math structure.

void PhysicsImpulseUpdate(int param_1)
{
    float local_30 = 0.0f, local_28 = 0.0f, local_2c = 0.0f;
    int local_24 = 0, local_20 = 0, local_1c = 0;

    // Read entity velocity/mass data
    float fx = *reinterpret_cast<float*>(param_1 + 0x10);
    float fy = *reinterpret_cast<float*>(param_1 + 0x14);
    float fz = *reinterpret_cast<float*>(param_1 + 0x18);

    // Compute impulse magnitude
    float impulseScale = *reinterpret_cast<float*>(param_1 + 0x1C);
    if (impulseScale != 0.0f) {
        local_30 = fx * impulseScale;
        local_2c = fy * impulseScale;
        local_28 = fz * impulseScale;
    }

    // Apply to entity velocity
    *reinterpret_cast<float*>(param_1 + 0x20) += local_30;
    *reinterpret_cast<float*>(param_1 + 0x24) += local_2c;
    *reinterpret_cast<float*>(param_1 + 0x28) += local_28;
}
} // namespace Giants
