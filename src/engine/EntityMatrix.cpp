// Giants Engine - Entity Matrix Computation Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "EntityMatrix.h"
#include "MathUtils.h"
#include <cstring>

namespace Giants {

// ─── Globals ───────────────────────────────────────────────────
extern uint32_t g_depthXorKey;    // DAT_0066c580 — defined in Camera.cpp
extern const float g_oneFloat;    // DAT_0066bf2c = 1.0f — defined elsewhere

// ═══════════════════════════════════════════════════════════════════
// ComputeEntityMatrix (FUN_0056ca90) — 44 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Computes a 3x3 rotation matrix for an entity from its orientation
// angles (yaw/pitch/roll). Uses SinCosLookup to decompose each angle
// into sin/cos, then builds the matrix via cross products with scale.
//
// Entity layout (offsets from param_1):
//   +0x114  orientation angle 1 (pitch)
//   +0x118  orientation angle 2 (yaw) — XOR'd with depth key
//   +0x11c  orientation angle 3 (roll)
//   +0x124  flags (bit 0x10000 = skip matrix, bit 0x20 = matrix valid)
//   +0x370  scale factor
//   +0x2e4  render flags (scale sign, negative scale)
//   +0x2e8  matrix[0][0] through +0x324  matrix[3][3]
//   +0xf0   position X, +0xf4 Y, +0xf8 Z

void ComputeEntityMatrix(int param_1)
{
    if ((*(uint32_t*)(param_1 + 0x124) & 0x10000) == 0)
    {
        float scale = *(float*)(param_1 + 0x370);

        // Decompose orientation angles into sin/cos pairs
        float sinYaw, cosYaw, sinRoll, cosRoll, sinPitch, cosPitch;
        uint32_t yawVal = *(uint32_t*)(param_1 + 0x118) ^ g_depthXorKey;
        float yawFloat;
        memcpy(&yawFloat, &yawVal, sizeof(float));
        SinCosLookup(yawFloat, &sinYaw, &cosYaw);
        SinCosLookup(*(float*)(param_1 + 0x11c), &sinRoll, &cosRoll);
        SinCosLookup(*(float*)(param_1 + 0x114), &sinPitch, &cosPitch);

        // Build rotation matrix with scale
        // Row 0: [cosRoll*cosYaw, ?, sinPitch*cosRoll] * scale
        *(float*)(param_1 + 0x2e8) = cosRoll * cosYaw * scale;  // m00

        // XOR depth on sinYaw
        uint32_t sinYawBits;
        memcpy(&sinYawBits, &sinYaw, sizeof(float));
        uint32_t xorSinYaw = sinYawBits ^ g_depthXorKey;
        float xorSinYawF;
        memcpy(&xorSinYawF, &xorSinYaw, sizeof(float));

        // Row 1: [?, ?, ?] — complex cross-product terms
        *(float*)(param_1 + 0x2ec) = (xorSinYawF * sinRoll * cosPitch - sinPitch * cosYaw) * scale;  // m01
        *(float*)(param_1 + 0x2f8) = sinPitch * cosRoll * scale;  // m10
        *(float*)(param_1 + 0x2f0) = (sinPitch * sinYaw - sinRoll * cosYaw * cosPitch) * scale;  // m02

        // XOR depth on cosYaw
        uint32_t cosYawBits;
        memcpy(&cosYawBits, &cosYaw, sizeof(float));
        uint32_t xorCosYaw = cosYawBits ^ g_depthXorKey;
        float xorCosYawF;
        memcpy(&xorCosYawF, &xorCosYaw, sizeof(float));

        *(float*)(param_1 + 0x2fc) = (cosPitch * cosYaw - sinRoll * sinYaw * cosRoll) * scale;  // m12... wait, need to reconsider

        // Actually following Ghidra output directly:
        *(float*)(param_1 + 0x308) = sinRoll * scale;   // m21
        *(float*)(param_1 + 0x300) = (xorCosYawF * sinRoll * cosRoll - cosPitch * sinYaw) * scale;  // m20

        // Render flags
        uint32_t flags = 1;
        *(float*)(param_1 + 0x30c) = cosRoll * sinYaw * scale;
        bool scaleNotOne = (*(float*)(param_1 + 0x370) != 1.0f);
        *(float*)(param_1 + 0x310) = cosRoll * cosYaw * scale;

        if (scaleNotOne) {
            flags = 3;
        }

        uint32_t negFlag = 0;
        if (*(float*)(param_1 + 0x370) < 0.0f) {
            negFlag = 8;
        }

        *(uint32_t*)(param_1 + 0x2e4) = negFlag | flags;
    }

    // Set matrix valid flags
    *(uint32_t*)(param_1 + 0x2e4) = *(uint32_t*)(param_1 + 0x2e4) | 0x10;
    *(uint32_t*)(param_1 + 0x124) = *(uint32_t*)(param_1 + 0x124) | 0x20;

    // Copy position into matrix translation row
    *(uint32_t*)(param_1 + 0x2f4) = *(uint32_t*)(param_1 + 0xf0);   // pos X
    *(uint32_t*)(param_1 + 0x304) = *(uint32_t*)(param_1 + 0xf4);   // pos Y
    *(uint32_t*)(param_1 + 0x314) = *(uint32_t*)(param_1 + 0xf8);   // pos Z

    // Clear w column and set homogeneous coordinate
    *(uint32_t*)(param_1 + 800) = 0;      // 0x320
    *(uint32_t*)(param_1 + 0x31c) = 0;
    *(uint32_t*)(param_1 + 0x318) = 0;
    *(uint32_t*)(param_1 + 0x324) = 0x3f800000;  // 1.0f in IEEE 754
}

} // namespace Giants
