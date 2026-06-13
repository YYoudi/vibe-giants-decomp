// Giants Engine - Entity Position Update With Rotation Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "EntityPositionUpdate.h"
#include <cstdint>
#include <cstring>

namespace Giants {

// ─── Globals ───────────────────────────────────────────────────
extern float    DAT_0066bf2c;    // 1.0f
extern float    DAT_0066be20;    // Scale factor
extern uint32_t DAT_0066c580;   // Depth XOR key
static float _DAT_0066bce4 = 0.0f;  // faithful @0x0066BCE4  // Scale threshold

// ─── External callees ──────────────────────────────────────────
extern void FUN_0042bee0();   // Sqrt/normalize helper
extern void FUN_0062a0b0();   // SSE2 sqrt/damping

// Helper: reinterpret float as uint32_t
static inline uint32_t f2u(float f) { uint32_t u; memcpy(&u, &f, 4); return u; }
static inline float u2f(uint32_t u) { float f; memcpy(&f, &u, 4); return f; }

// ═══════════════════════════════════════════════════════════════════
// UpdateEntityPosition (FUN_00566ed0) — 19 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Computes entity velocity vector from rotation matrix and scale,
// with optional per-axis clamping.
//
// Phase 1: Compute speed squared from velocity at +0x174..+0x17c
// Phase 2: If scale (+0x370) != threshold, compute rotation:
//   - Build rotation from XOR'd matrix entries at +0x2e8..+0x310
//   - Apply inverse scale to get direction vector
//   - Transform offset (+0xf0 - +0xfc) by rotation
//   - Write to +0x154 (Z), +0x158 (Y), +0x15c (X)
//   - Clamp each axis if param_2/param_3 != 0

void UpdateEntityPosition(int entity, int clampX, int clampY, float clampValue)
{
    // Phase 1: Speed squared
    float vx = *reinterpret_cast<float*>(entity + 0x174);
    float vy = *reinterpret_cast<float*>(entity + 0x178);
    float vz = *reinterpret_cast<float*>(entity + 0x17c);
    float speedSq = vx * vx + vy * vy + vz * vz;

    FUN_0042bee0();
    *reinterpret_cast<float*>(*reinterpret_cast<int*>(entity + 0x150) + 0x24) = speedSq;

    bool hasScale = *reinterpret_cast<float*>(entity + 0x370) != _DAT_0066bce4;

    // Clear velocity outputs
    *reinterpret_cast<uint32_t*>(entity + 0x154) = 0;
    *reinterpret_cast<uint32_t*>(entity + 0x15c) = 0;
    *reinterpret_cast<uint32_t*>(entity + 0x158) = 0;

    if (hasScale) {
        float invScale = DAT_0066bf2c / *reinterpret_cast<float*>(entity + 0x370);

        // Rotation matrix entries (some XOR'd with depth key)
        float r00 = *reinterpret_cast<float*>(entity + 0x2e8);
        float r01 = u2f(f2u(*reinterpret_cast<float*>(entity + 0x2ec)) ^ DAT_0066c580);
        float r10 = *reinterpret_cast<float*>(entity + 0x2f8);
        float r11 = u2f(f2u(*reinterpret_cast<float*>(entity + 0x2fc)) ^ DAT_0066c580);
        float r20 = *reinterpret_cast<float*>(entity + 0x308);
        float r21 = u2f(f2u(*reinterpret_cast<float*>(entity + 0x30c)) ^ DAT_0066c580);
        float r02 = *reinterpret_cast<float*>(entity + 0x2f0);
        float r12 = *reinterpret_cast<float*>(entity + 0x300);
        float scale310 = *reinterpret_cast<float*>(entity + 0x310);
        float scaledSpeed = invScale * scale310;

        float s310sq = scaledSpeed;
        FUN_0062a0b0();

        float dirX = 0.0f, dirY = 0.0f, dirZ = 0.0f;
        if (s310sq == 0.0f) {
            s310sq = 0.0f;
        } else {
            FUN_0062a0b0();
            float invS = DAT_0066bf2c / s310sq;
            dirX = (*reinterpret_cast<float*>(entity + 0xf0) - *reinterpret_cast<float*>(entity + 0xfc)) * invS;
            dirY = (*reinterpret_cast<float*>(entity + 0xf4) - *reinterpret_cast<float*>(entity + 0x100)) * invS;
            dirZ = (*reinterpret_cast<float*>(entity + 0xf8) - *reinterpret_cast<float*>(entity + 0x104)) * invS;
        }

        // X velocity: rotate direction by matrix row
        float velX = dirY * invScale * r10 + dirX * invScale * r00 + dirZ * invScale * r20;
        *reinterpret_cast<float*>(entity + 0x15c) = velX;

        // Clamp X axis
        if (clampY != 0) {
            if (clampY < 0) {
                clampValue = u2f(f2u(clampValue) ^ DAT_0066c580);
            }
            bool shouldClamp = (clampY < 0) ? (velX < clampValue) : (clampValue < velX);
            if (!shouldClamp && velX != clampValue) {
                *reinterpret_cast<float*>(entity + 0x15c) = clampValue;
            }
        }

        // Y velocity
        float velY = dirY * r11 * invScale + dirX * r01 * invScale + dirZ * r21 * invScale;
        *reinterpret_cast<float*>(entity + 0x158) = velY;

        // Clamp Y axis
        if (clampX != 0) {
            float clampYVal = 0.0f;  // in_XMM3_Da from register
            if (clampX < 0) {
                clampYVal = u2f(f2u(clampYVal) ^ DAT_0066c580);
            }
            bool shouldClamp = (clampX < 0) ? (velY < clampYVal) : (clampYVal < velY);
            if (!shouldClamp && velY != clampYVal) {
                *reinterpret_cast<float*>(entity + 0x158) = clampYVal;
            }
        }

        // Z velocity
        *reinterpret_cast<float*>(entity + 0x154) =
            dirY * invScale * r12 + dirX * invScale * r02 + dirZ * scaledSpeed;
    }
}

} // namespace Giants
