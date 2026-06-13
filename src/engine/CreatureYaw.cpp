// Giants Engine - Creature Yaw Update Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "CreatureYaw.h"
#include "CRTStubs.h"
#include <cmath>

namespace Giants {

// ─── Globals ───────────────────────────────────────────────────
extern int    DAT_007488ec;      // Skip flag
extern uint32_t DAT_00702774;    // Active entity ID
extern char   DAT_00702c45;      // Speed table flag
extern float  DAT_0066bf2c;      // 1.0f
extern float  DAT_0066bd58;      // Speed scale factor
extern float  DAT_0066be20;      // 0.5f
extern float  DAT_0066c14c;      // 2π (angle wrap)
extern float* DAT_0065c7d8;      // Speed table
extern int    DAT_00681dc4;      // Speed table index

extern float  RandomFloat();                       // FUN_0060b140 or similar
extern double GetAngleToTarget(uint32_t target, uint32_t current);  // FUN_00558360-ish

// ═══════════════════════════════════════════════════════════════════
// UpdateCreatureYaw (FUN_0056be60) — 23 callers — PASS
// ═══════════════════════════════════════════════════════════════════

void UpdateCreatureYaw(int c)
{
    // Skip check
    if (DAT_007488ec != 0 && c == DAT_00702774)
        return;

    // Compute speed factor
    float speedMul = DAT_0066bf2c;  // 1.0f
    if (DAT_00702c45 != '\0')
    {
        speedMul = *reinterpret_cast<float*>(reinterpret_cast<uintptr_t>(DAT_0065c7d8) + DAT_00681dc4 * 4);
    }

    float turnRate = speedMul * static_cast<float>(*reinterpret_cast<char*>(c + 0x25c)) * DAT_0066bd58;
    float velocity = turnRate * *reinterpret_cast<float*>(c + 0x1f0);
    float accel = velocity;
    RandomFloat();

    float yaw = *reinterpret_cast<float*>(c + 0x160);
    float delta = turnRate * *reinterpret_cast<float*>(c + 500);  // offset 0x1f4
    accel = accel * velocity;

    // Angular velocity clamping and acceleration
    if (delta > 0.0f)
    {
        if (yaw < 0.0f)
        {
            *reinterpret_cast<uint32_t*>(c + 0x160) = 0;
            yaw = 0.0f;
        }
        if (delta > yaw)
        {
            if (yaw < delta)
            {
                float maxVel = *reinterpret_cast<float*>(c + 0x1f8);
                float rnd = maxVel;
                RandomFloat();
                float newVel = delta - rnd * rnd;
                *reinterpret_cast<float*>(c + 0x160) = newVel;
                if (newVel < delta)
                    *reinterpret_cast<float*>(c + 0x160) = delta;
            }
        }
        else
        {
            yaw = yaw + accel;
            *reinterpret_cast<float*>(c + 0x160) = yaw;
            if (yaw > delta)
                *reinterpret_cast<float*>(c + 0x160) = delta;
        }
    }
    else if (delta < 0.0f)
    {
        if (yaw > 0.0f)
        {
            *reinterpret_cast<uint32_t*>(c + 0x160) = 0;
            yaw = 0.0f;
        }
        if (delta < yaw)
        {
            if (delta < yaw)
            {
                float maxVel = *reinterpret_cast<float*>(c + 0x1f8);
                float rnd = maxVel;
                RandomFloat();
                float newVel = maxVel * rnd + *reinterpret_cast<float*>(c + 0x160);
                *reinterpret_cast<float*>(c + 0x160) = newVel;
                if (newVel > delta)
                    *reinterpret_cast<float*>(c + 0x160) = delta;
            }
        }
        else
        {
            yaw = yaw + accel;
            *reinterpret_cast<float*>(c + 0x160) = yaw;
            if (yaw < delta)
                *reinterpret_cast<float*>(c + 0x160) = delta;
        }
    }
    else
    {
        // delta == 0.0f
        if (yaw <= 0.0f && yaw >= 0.0f)
            goto apply;  // yaw already 0
        if (yaw <= 0.0f)
        {
            float maxVel = *reinterpret_cast<float*>(c + 0x1f8);
            float rnd = maxVel;
            RandomFloat();
            float newVel = maxVel * rnd + yaw;
            *reinterpret_cast<float*>(c + 0x160) = newVel;
            if (newVel < 0.0f && newVel != 0.0f)
                *reinterpret_cast<uint32_t*>(c + 0x160) = 0;
        }
        else
        {
            float maxVel = *reinterpret_cast<float*>(c + 0x1f8);
            float rnd = maxVel;
            RandomFloat();
            float newVel = yaw - maxVel * rnd;
            *reinterpret_cast<float*>(c + 0x160) = newVel;
            if (newVel > 0.0f && newVel != 0.0f)
                *reinterpret_cast<uint32_t*>(c + 0x160) = 0;
        }
    }

apply:
    // Apply yaw change
    float halfDt = (*reinterpret_cast<float*>(c + 0x170) + *reinterpret_cast<float*>(c + 0x160)) * DAT_0066be20;
    float finalYaw = halfDt;
    RandomFloat();
    finalYaw = finalYaw * halfDt;

    // Optional: snap to target angle
    if ((*reinterpret_cast<uint32_t*>(c + 0x124) & 0x1000000) != 0)
    {
        double angleToTarget = GetAngleToTarget(
            *reinterpret_cast<uint32_t*>(c + 0x1a4),
            *reinterpret_cast<uint32_t*>(c + 0x114));
        float diff = static_cast<float>(angleToTarget);

        if (((diff > 0.0f) && (diff < finalYaw)) ||
            ((diff < 0.0f) && (finalYaw < diff)))
        {
            *reinterpret_cast<uint32_t*>(c + 0x170) = 0;
            *reinterpret_cast<uint32_t*>(c + 0x160) = 0;
            finalYaw = diff;
        }
    }

    // Add yaw to current and wrap to [0, 2π)
    float newAngle = finalYaw + *reinterpret_cast<float*>(c + 0x114);
    *reinterpret_cast<float*>(c + 0x114) = newAngle;

    if (newAngle >= DAT_0066c14c)
    {
        newAngle -= DAT_0066c14c;
        *reinterpret_cast<float*>(c + 0x114) = newAngle;
    }

    if (newAngle < 0.0f)
    {
        *reinterpret_cast<float*>(c + 0x114) = newAngle + DAT_0066c14c;
    }
}

} // namespace Giants
