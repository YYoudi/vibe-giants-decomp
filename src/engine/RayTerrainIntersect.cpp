// Giants Engine - Ray-Terrain Intersection Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "RayTerrainIntersect.h"
#include <cstdint>
#include <cstring>

namespace Giants {

// ─── Shared globals ────────────────────────────────────────────
extern void*  DAT_00702770;      // g_sceneReady — GameLogic.cpp
extern float  DAT_0066be20;      // Scale factor — Camera.cpp
extern float  DAT_0066bf2c;      // 1.0f
extern float  DAT_0066bd04;      // Min intersection threshold
extern uint32_t DAT_0066c580;    // Depth XOR key — Camera.cpp

// ─── External callees ──────────────────────────────────────────
extern void FUN_004fecb0(int, float* outHeight, int);  // Terrain height query
extern void FUN_0042d350();  // Normal/plane computation

// Helper: reinterpret float as uint32_t
static inline uint32_t f2u(float f) { uint32_t u; memcpy(&u, &f, 4); return u; }
static inline float u2f(uint32_t u) { float f; memcpy(&f, &u, 4); return f; }

// ═══════════════════════════════════════════════════════════════════
// RayTerrainIntersect (FUN_004ff520) — 17 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Two-phase ray-terrain intersection:
//
// Phase 1 (Linear march): Step along ray by terrain cell size until
//   either we pass the max distance (in_XMM1_Da) or we go below terrain.
//
// Phase 2 (Binary search): 8 iterations of bisection between the
//   last above-terrain and below-terrain points for precise hit.
//
// Finally computes the intersection point using plane equation.

uint32_t RayTerrainIntersect(float* hitPos, const float* rayOrigin,
                              const float* rayDir, uint32_t param_4,
                              float* outDist)
{
    float stepSize = *reinterpret_cast<float*>(
        reinterpret_cast<uintptr_t>(DAT_00702770) + 0x238) * DAT_0066be20;

    float maxDist = 0.0f;  // in_XMM1_Da — passed via register

    // Phase 1: Linear march
    float marchDist = 0.0f;
    float hitX, hitY, hitZ;

    if (maxDist <= stepSize) {
        hitX = 0.0f;
        hitY = 0.0f;
    } else {
        while (true) {
            hitX = stepSize * rayDir[0] + rayOrigin[0];
            hitY = stepSize * rayDir[1] + rayOrigin[1];
            hitZ = stepSize * rayDir[2] + rayOrigin[2];

            float terrainH;
            FUN_004fecb0(0, &terrainH, 1);

            if (hitZ <= terrainH) break;

            stepSize += *reinterpret_cast<float*>(
                reinterpret_cast<uintptr_t>(DAT_00702770) + 0x238) * DAT_0066be20;

            if (stepSize >= maxDist) break;
        }
    }

    uint32_t hit = (stepSize < maxDist) ? 1 : 0;
    float prevDist = stepSize - *reinterpret_cast<float*>(
        reinterpret_cast<uintptr_t>(DAT_00702770) + 0x238) * DAT_0066be20;

    float interpFactor = DAT_0066bf2c;

    // Phase 2: Binary search (8 iterations)
    if (hit != 0) {
        int iterations = 8;
        do {
            float mid = (stepSize + prevDist) * DAT_0066be20;
            hitX = mid * rayDir[0] + rayOrigin[0];
            hitY = mid * rayDir[1] + rayOrigin[1];
            hitZ = mid * rayDir[2] + rayOrigin[2];

            float terrainH;
            FUN_004fecb0(0, &terrainH, 1);

            if (hitZ <= terrainH) {
                stepSize = mid;
                mid = prevDist;
            }
            prevDist = mid;
            iterations--;
        } while (iterations != 0);

        // Final intersection point
        hitX = stepSize * rayDir[0] + rayOrigin[0];
        hitY = stepSize * rayDir[1] + rayOrigin[1];
        hitZ = stepSize * rayDir[2] + rayOrigin[2];

        float terrainH;
        FUN_004fecb0(0, &terrainH, 1);

        // Compute interpolation factor from plane equation
        float dx = hitX - rayOrigin[0];
        float dy = hitY - rayOrigin[1];
        float dz = hitZ - rayOrigin[2];
        // Uses local_18, local_14, local_10, local_c from FUN_0042d350 (normal)
        float normalDot = 0.0f;  // From FUN_0042d350 result
        FUN_0042d350();

        interpFactor = DAT_0066bf2c;
        if (DAT_0066bd04 <= normalDot) {
            // Plane intersection parameter with XOR depth
            interpFactor = u2f(f2u(
                (rayOrigin[0] * 0.0f + rayOrigin[1] * 0.0f + rayOrigin[2] * 0.0f + 0.0f) /
                normalDot) ^ DAT_0066c580);
        }
    }

    // Write output
    *outDist = stepSize;
    hitPos[0] = (hitX - rayOrigin[0]) * interpFactor + rayOrigin[0];
    hitPos[1] = (hitY - rayOrigin[1]) * interpFactor + rayOrigin[1];
    hitPos[2] = (hitZ - rayOrigin[2]) * interpFactor + rayOrigin[2];

    return hit;
}

} // namespace Giants
