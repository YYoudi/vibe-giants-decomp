// Giants Engine - Entity Terrain Collision Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "EntityTerrainCollision.h"
#include <cstdint>

namespace Giants {

// ─── Shared globals ────────────────────────────────────────────
extern float DAT_0066bf2c;    // 1.0f
static float _DAT_0066c074 = 0.0f;  // Gravity/friction factor

// ─── External callees ──────────────────────────────────────────
extern void FUN_0042bee0();   // Sqrt/normalize helper

// ═══════════════════════════════════════════════════════════════════
// ApplyTerrainCollision (FUN_005668b0) — 17 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Applies terrain collision response to entity velocity vector.
//
// Phase 1: Apply gravity to Z component (+0x20)
// Phase 2: If param_2 != 0 and entity has collision flags (+0x68):
//   - Project velocity onto terrain normal (entity +0x190..+0x198)
//   - Remove negative component (ground plane constraint)
//   - Renormalize if speed exceeds limit at pbVar1+0x30
// Phase 3: Apply damping from +0x34 (XY) and +0x38 (Z)
// Phase 4: Update minimum time-to-live at +0x2c

void ApplyTerrainCollision(int entity, int param_2)
{
    uint8_t* pbVar1 = *reinterpret_cast<uint8_t**>(entity + 0x150);

    if ((*reinterpret_cast<uint8_t*>(entity + 0x124) & 0x10) != 0) {
        return;
    }

    // Phase 1: Apply gravity to Z velocity
    float vz = *reinterpret_cast<float*>(pbVar1 + 0x20) -
                *reinterpret_cast<float*>(pbVar1 + 4) * _DAT_0066c074;
    *reinterpret_cast<float*>(pbVar1 + 0x20) = vz;

    // Phase 2: Terrain normal projection
    if (param_2 != 0 && (*pbVar1 & 0x68) != 0) {
        float vx = *reinterpret_cast<float*>(pbVar1 + 0x18);
        float vy = *reinterpret_cast<float*>(pbVar1 + 0x1c);
        float nx = *reinterpret_cast<float*>(entity + 400);     // +0x190
        float ny = *reinterpret_cast<float*>(entity + 0x194);
        float nz = *reinterpret_cast<float*>(entity + 0x198);

        float dot = vy * ny + vx * nx + vz * nz;

        if (dot < 0.0f) {
            // Remove negative velocity component (ground constraint)
            vx -= nx * dot;
            vy -= ny * dot;
            vz -= nz * dot;

            // Renormalize if speed exceeds limit
            float speedSq = vx * vx + vy * vy + vz * vz;
            FUN_0042bee0();

            float limit = DAT_0066bf2c;
            if (*reinterpret_cast<float*>(pbVar1 + 0x30) < speedSq) {
                limit = *reinterpret_cast<float*>(pbVar1 + 0x30) / speedSq;
            }

            vx -= vx * limit;
            vy -= vy * limit;
            vz -= vz * limit;
            *reinterpret_cast<float*>(pbVar1 + 0x18) = vx;
            *reinterpret_cast<float*>(pbVar1 + 0x1c) = vy;
            *reinterpret_cast<float*>(pbVar1 + 0x20) = vz;
        }
    }

    // Phase 3: Apply damping
    float dampXY = *reinterpret_cast<float*>(pbVar1 + 0x34);
    float dampZ = *reinterpret_cast<float*>(pbVar1 + 0x38);
    float evx = *reinterpret_cast<float*>(entity + 0x174);
    float evy = *reinterpret_cast<float*>(entity + 0x178);
    float evz = *reinterpret_cast<float*>(entity + 0x17c);

    *reinterpret_cast<float*>(pbVar1 + 0x18) -= dampXY * evx;
    *reinterpret_cast<float*>(pbVar1 + 0x1c) -= dampXY * evy;
    *reinterpret_cast<float*>(pbVar1 + 0x20) = vz - dampZ * evz;

    // Phase 4: Update time-to-live estimates
    float duration = *reinterpret_cast<float*>(pbVar1 + 8);
    if (dampXY != 0.0f) {
        float ttl = duration / dampXY;
        if (ttl < *reinterpret_cast<float*>(pbVar1 + 0x2c) ||
            *reinterpret_cast<float*>(pbVar1 + 0x2c) == 0.0f) {
            *reinterpret_cast<float*>(pbVar1 + 0x2c) = ttl;
        }
    }
    if (dampZ != 0.0f) {
        float ttl = duration / dampZ;
        if (ttl < *reinterpret_cast<float*>(pbVar1 + 0x2c) ||
            *reinterpret_cast<float*>(pbVar1 + 0x2c) == 0.0f) {
            *reinterpret_cast<float*>(pbVar1 + 0x2c) = ttl;
        }
    }
}

} // namespace Giants
