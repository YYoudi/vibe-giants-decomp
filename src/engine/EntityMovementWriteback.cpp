// Giants Engine - Entity Movement Writeback Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "EntityMovementWriteback.h"
#include <cstdint>
#include <cstring>

namespace Giants {

// ─── Globals ───────────────────────────────────────────────────
extern float DAT_0066bf2c;    // 1.0f
extern float DAT_0066be20;    // Scale factor

// ─── External callees ──────────────────────────────────────────
extern void FUN_0062a0b0();   // SSE2 sqrt/damping
extern void FUN_0042bee0();   // Sqrt/normalize helper
extern int  FUN_0042bc40();   // Entity grid lookup (RTTI based)

// ═══════════════════════════════════════════════════════════════════
// WriteEntityMovement (FUN_00565f40) — 19 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Full entity movement integration per frame.
//
// Phase 1 (if no parent at +0x264):
//   - Get speed from entity data at +0x150
//   - Clamp speed to max (at +0x2c)
//   - Save velocity to prev (+0x180..+0x188)
//   - Integrate: pos += direction * (1/duration) * speed
//   - Normalize if max distance (+0x28) set
//   - Apply scale factor (DAT_0066be20) to delta, add to world pos
//
// Phase 1b (if parent + flag 0x1000 clear):
//   - Zero velocity and prev velocity
//
// Phase 2: Clear direction in entity data
// Phase 3: Write final state to entity grid (cell lookup + copy 0x48 bytes)

void WriteEntityMovement(int entity)
{
    int entityData = *reinterpret_cast<int*>(entity + 0x150);

    if (*reinterpret_cast<int*>(entity + 0x264) == 0) {
        // ── Phase 1: Movement integration ──
        FUN_0062a0b0();
        float maxSpeed = *reinterpret_cast<float*>(entityData + 0x2c);
        float speed = 0.0f;  // in_XMM0_Da — passed via register
        float clampedSpeed = speed;

        *reinterpret_cast<float*>(entityData + 0x14) = speed;

        if (maxSpeed > 0.0f && speed > maxSpeed) {
            clampedSpeed = maxSpeed;
        } else {
            clampedSpeed = speed;
        }

        *reinterpret_cast<uint32_t*>(entityData + 0x2c) = 0;

        // Save prev velocity
        *reinterpret_cast<uint64_t*>(entity + 0x180) = *reinterpret_cast<uint64_t*>(entity + 0x174);
        *reinterpret_cast<uint32_t*>(entity + 0x188) = *reinterpret_cast<uint32_t*>(entity + 0x17c);

        // Integrate position
        float invDuration = DAT_0066bf2c / *reinterpret_cast<float*>(entityData + 8);
        float dirX = *reinterpret_cast<float*>(entityData + 0x18);
        float dirY = *reinterpret_cast<float*>(entityData + 0x1c);
        float dirZ = *reinterpret_cast<float*>(entityData + 0x20);

        float newVx = invDuration * dirX * clampedSpeed + *reinterpret_cast<float*>(entity + 0x174);
        *reinterpret_cast<float*>(entity + 0x174) = newVx;
        float newVy = invDuration * dirY * clampedSpeed + *reinterpret_cast<float*>(entity + 0x178);
        *reinterpret_cast<float*>(entity + 0x178) = newVy;
        float newVz = invDuration * dirZ * clampedSpeed + *reinterpret_cast<float*>(entity + 0x17c);
        *reinterpret_cast<float*>(entity + 0x17c) = newVz;

        // Normalize if max distance set
        if (*reinterpret_cast<float*>(entityData + 0x28) != 0.0f) {
            float distSq = newVy * newVy + newVx * newVx + newVz * newVz;
            FUN_0042bee0();
            if (distSq != 0.0f) {
                float maxDist = *reinterpret_cast<float*>(entityData + 0x28);
                float normFactor = DAT_0066bf2c;
                if (maxDist < distSq) {
                    normFactor = maxDist / distSq;
                }
                newVx *= normFactor;
                newVy *= normFactor;
                newVz *= normFactor;
                *reinterpret_cast<float*>(entity + 0x174) = newVx;
                *reinterpret_cast<float*>(entity + 0x178) = newVy;
                *reinterpret_cast<float*>(entity + 0x17c) = newVz;
            }
        }

        // Apply scale to delta and update world position
        float scaledX = (newVx + *reinterpret_cast<float*>(entity + 0x180)) * DAT_0066be20;
        float scaledY = (newVy + *reinterpret_cast<float*>(entity + 0x184)) * DAT_0066be20;
        float scaledZ = (newVz + *reinterpret_cast<float*>(entity + 0x188)) * DAT_0066be20;

        *reinterpret_cast<float*>(entity + 0xf0) = scaledX * speed + *reinterpret_cast<float*>(entity + 0xf0);
        *reinterpret_cast<float*>(entity + 0xf4) = scaledY * speed + *reinterpret_cast<float*>(entity + 0xf4);
        *reinterpret_cast<float*>(entity + 0xf8) = scaledZ * speed + *reinterpret_cast<float*>(entity + 0xf8);

    } else if ((*reinterpret_cast<uint32_t*>(entity + 0x128) & 0x1000) == 0) {
        // ── Zero velocity ──
        *reinterpret_cast<uint32_t*>(entity + 0x17c) = 0;
        *reinterpret_cast<uint32_t*>(entity + 0x178) = 0;
        *reinterpret_cast<uint32_t*>(entity + 0x174) = 0;
        *reinterpret_cast<uint32_t*>(entity + 0x188) = 0;
        *reinterpret_cast<uint32_t*>(entity + 0x184) = 0;
        *reinterpret_cast<uint32_t*>(entity + 0x180) = 0;
    }

    // Phase 2: Clear direction
    *reinterpret_cast<uint32_t*>(entityData + 0x20) = 0;
    *reinterpret_cast<uint32_t*>(entityData + 0x1c) = 0;
    *reinterpret_cast<uint32_t*>(entityData + 0x18) = 0;

    // Phase 3: Write to entity grid
    entityData = *reinterpret_cast<int*>(entity + 0x150);
    if (entityData != 0) {
        uint32_t gridKey = **reinterpret_cast<uint32_t**>(entity + 0x368);
        int gridContext = FUN_0042bc40();
        int cellIndex = *reinterpret_cast<int*>(
            *reinterpret_cast<int*>(*reinterpret_cast<int*>(gridContext + 4) +
                ((gridKey >> 13) & 0x7F) * 4) +
            (gridKey & 0x1FFF) * 4);
        int gridData = *reinterpret_cast<int*>(gridContext + 0x1c);

        // Copy entity state to grid cell (0x48 bytes per cell)
        *reinterpret_cast<uint64_t*>(gridData + cellIndex * 0x48) = *reinterpret_cast<uint64_t*>(entity + 0xf0);
        *reinterpret_cast<uint32_t*>(gridData + 8 + cellIndex * 0x48) = *reinterpret_cast<uint32_t*>(entity + 0xf8);
        *reinterpret_cast<uint64_t*>(gridData + 0xc + cellIndex * 0x48) = *reinterpret_cast<uint64_t*>(entity + 0xfc);
        *reinterpret_cast<uint32_t*>(gridData + 0x14 + cellIndex * 0x48) = *reinterpret_cast<uint32_t*>(entity + 0x104);
        *reinterpret_cast<uint64_t*>(gridData + 0x18 + cellIndex * 0x48) = *reinterpret_cast<uint64_t*>(entity + 0x174);
        *reinterpret_cast<uint32_t*>(gridData + 0x20 + cellIndex * 0x48) = *reinterpret_cast<uint32_t*>(entity + 0x17c);
        *reinterpret_cast<uint64_t*>(gridData + 0x24 + cellIndex * 0x48) = *reinterpret_cast<uint64_t*>(entity + 0x180);
        *reinterpret_cast<uint32_t*>(gridData + 0x2c + cellIndex * 0x48) = *reinterpret_cast<uint32_t*>(entity + 0x188);
        *reinterpret_cast<uint32_t*>(gridData + 0x30 + cellIndex * 0x48) = *reinterpret_cast<uint32_t*>(entity + 0x114);
        *reinterpret_cast<uint32_t*>(gridData + 0x34 + cellIndex * 0x48) = *reinterpret_cast<uint32_t*>(entityData + 0x24);
        *reinterpret_cast<uint32_t*>(gridData + 0x38 + cellIndex * 0x48) = *reinterpret_cast<uint32_t*>(entity + 0x158);
        *reinterpret_cast<uint64_t*>(gridData + 0x3c + cellIndex * 0x48) = *reinterpret_cast<uint64_t*>(entityData + 0x18);
        *reinterpret_cast<uint32_t*>(gridData + 0x44 + cellIndex * 0x48) = *reinterpret_cast<uint32_t*>(entityData + 0x20);
    }
}

} // namespace Giants
