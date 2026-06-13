// Giants Engine - Euler Angles to Rotation Matrix Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "EulerToMatrix.h"
#include <cstdint>
#include <cstring>
#include <cmath>

namespace Giants {

// ─── Globals ───────────────────────────────────────────────────
extern float _DAT_0066bd40;    // Degree-to-radian conversion factor
extern uint32_t DAT_0066c580;  // Depth XOR key (g_depthXorKey)

// ─── Function pointer table for sin/cos ────────────────────────
// PTR_FUN_0067d230 = sinf, PTR_FUN_0067d234 = cosf
static float (*SinfPtr)(float) = reinterpret_cast<float(*)(float)>(0x0067d230);
static float (*CosfPtr)(float) = reinterpret_cast<float(*)(float)>(0x0067d234);

// ═══════════════════════════════════════════════════════════════════
// BuildRotationFromEuler (FUN_0063e480) — 21 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Builds a rotation matrix from 3 Euler angles.
// Matrix layout (12 uint32_t slots = 3×3 + flags + depth XOR):
//   [+0]  flags (bit 0 set, bit 1 cleared → has rotation)
//   [+1]  m00, [+2] m01, [+3] m02
//   [+4]  unused (translation X placeholder)
//   [+5]  m10, [+6] m11, [+7] m12
//   [+8]  unused
//   [+9]  m20, [+10] m21, [+11] m22
// Angles are in game units, converted to radians via _DAT_0066bd40.
// Translation column XOR'd with g_depthXorKey for depth obfuscation.

void BuildRotationFromEuler(uint32_t* matrix, float pitch, float yaw, float roll)
{
    // Convert to radians
    float rx = pitch * _DAT_0066bd40;
    float cx = CosfPtr(rx);
    float sx = SinfPtr(rx);

    float ry = yaw * _DAT_0066bd40;
    float cy = CosfPtr(ry);
    float sy = SinfPtr(ry);

    float rz = roll * _DAT_0066bd40;
    float cz = CosfPtr(rz);
    float sz = SinfPtr(rz);

    // Helper: reinterpret float bits as uint32_t
    auto f2u = [](float f) -> uint32_t { uint32_t u; memcpy(&u, &f, 4); return u; };
    auto u2f = [](uint32_t u) -> float { float f; memcpy(&f, &u, 4); return f; };

    // XOR'd cos values for depth obfuscation
    float cx_xor = u2f(f2u(cx) ^ DAT_0066c580);
    float sy_xor = u2f(f2u(sy) ^ DAT_0066c580);

    // Build rotation matrix (R = Rz * Ry * Rx convention)
    // Row 0
    matrix[1] = f2u(sz * cy);   // m00
    matrix[2] = f2u(cx_xor * cy * sz - cz * sy);  // m01
    matrix[5] = f2u(cz * cy);   // m10
    matrix[3] = f2u(cz * sx - cy * sy * sz);      // m02

    // Row 1
    matrix[6] = f2u(sz * sy - cy * sx * cz);      // m11

    // Row 2
    matrix[9]  = f2u(cy);        // m20
    matrix[7]  = f2u(sy_xor * cy * cz - sz * cx); // m12
    matrix[10] = f2u(cz * sx);   // m21
    matrix[11] = f2u(cz * sy);   // m22

    // Set flags: bit 0 = has rotation, clear bit 1
    matrix[0] = (matrix[0] & 0xFFFFFFFD) | 1;
}

} // namespace Giants
