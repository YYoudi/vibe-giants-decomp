// Giants Engine - 2D Vector Angle Calculation Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "VectorAngle2D.h"
#include <cmath>

namespace Giants {

// ─── Shared globals ────────────────────────────────────────────
extern float DAT_0066c0a8;  // Angle scale factor — MathUtils.cpp

// ═══════════════════════════════════════════════════════════════════
// ComputeVectorAngle2D (FUN_00638a90) — 18 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Computes the atan2 angle between two 2D vectors.
// Steps:
//   1. Compute (v2.x - v1.x)² + (v2.y - v1.y)²
//   2. Take sqrt (using SSE2 precise sqrt)
//   3. If distance == 0 and Z-delta == 0, return 0
//   4. Otherwise, compute atan2 and scale by DAT_0066c0a8

float ComputeVectorAngle2D(const float* v1, const float* v2)
{
    double dx = static_cast<double>(v2[0] - v1[0]);
    double dy = static_cast<double>(v2[1] - v1[1]);
    double distSq = dx * dx + dy * dy;

    double dist;
    if (distSq < 0.0) {
        dist = 0.0;  // libm_sse2_sqrt_precise branch
    } else {
        dist = sqrt(distSq);
    }

    float fDist = static_cast<float>(dist);
    if (fDist == 0.0f && (v2[2] - v1[2]) == 0.0f) {
        return 0.0f;
    }

    // atan2 — in the original binary this uses x87 _CIatan2
    float angle = atan2f(v2[1] - v1[1], v2[0] - v1[0]);
    return angle * DAT_0066c0a8;
}

} // namespace Giants
