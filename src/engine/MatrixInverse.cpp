// Giants Engine - Matrix Inverse Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "MatrixInverse.h"
#include <cstring>

namespace Giants {

// ─── Globals ───────────────────────────────────────────────────
static const float ONE = 1.0f;  // DAT_0066bf2c
extern uint32_t g_depthXorKey;  // DAT_0066c580 — defined in Camera.cpp

// Helper to reinterpret uint as float
static inline float u2f(uint32_t u) { float f; memcpy(&f, &u, 4); return f; }
static inline uint32_t f2u(float f) { uint32_t u; memcpy(&u, &f, 4); return u; }

// ═══════════════════════════════════════════════════════════════════
// MatrixInvert (FUN_006392d0) — 27 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// 4×4 matrix inverse with flag-based dispatch.
// Matrix layout (row-major, as uint32_t array):
//   [+0] flags
//   [+1..+3]  row 0 (3 floats)
//   [+4]      row 0, col 3 (translation x)
//   [+5..+7]  row 1 (3 floats)
//   [+8]      row 1, col 3 (translation y)
//   [+9..+11] row 2 (3 floats)
//   [+12]     row 2, col 3 (translation z)
//   [+13..+15] row 3 (perspective, usually 0)
//   [+16]     row 3, col 3 (usually 1.0)

void MatrixInvert(uint32_t* dst, const uint32_t* src)
{
    uint32_t local[17];  // temp matrix for in-place operation
    uint32_t* out = (dst != src) ? dst : local;

    uint32_t flags = *src & 0xF;

    if (flags == 0) {
        // ── Identity matrix ──
        out[1]  = f2u(1.0f);  // [0][0]
        out[2]  = 0;          // [0][1]
        out[3]  = 0;          // [0][2]
        out[5]  = 0;          // [1][0]
        out[6]  = f2u(1.0f);  // [1][1]
        out[7]  = 0;          // [1][2]
        out[9]  = 0;          // [2][0]
        out[10] = 0;          // [2][1]
        out[11] = f2u(1.0f);  // [2][2]
    }
    else if ((flags & 6) == 0) {
        // ── Non-inverted: just copy the 3×3 rotation part ──
        out[1]  = src[1];
        out[2]  = src[2];
        out[3]  = src[3];
        out[5]  = src[5];
        out[6]  = src[6];
        out[7]  = src[7];
        out[9]  = src[9];
        out[10] = src[10];
        out[11] = src[11];
    }
    else {
        // ── Full inverse using cofactors ──
        float m00 = u2f(src[1]),  m01 = u2f(src[2]),  m02 = u2f(src[3]);
        float m10 = u2f(src[5]),  m11 = u2f(src[6]),  m12 = u2f(src[7]);
        float m20 = u2f(src[9]),  m21 = u2f(src[10]), m22 = u2f(src[11]);

        // Cofactor [2][2] × [0][0] - cofactor [2][0] × [0][2] + cofactor [2][1] × [0][1]
        float det = (m11 * m22 - m12 * m21) * m00
                  - (m10 * m22 - m12 * m20) * m01
                  + (m10 * m21 - m11 * m20) * m02;
        float invDet = ONE / det;

        // Row 0 of inverse
        float i00 = (m11 * m22 - m12 * m21) * invDet;
        out[1] = f2u(i00);

        float i01 = (m02 * m22 - m01 * m12) * invDet;  // was: (m22*m02 - m12*m20)... no
        // Ghidra: (param_2[10]*param_2[3] - param_2[0xb]*param_2[2]) * fVar5
        // = (m21*m02 - m22*m01) * invDet... actually let me use Ghidra directly:
        i01 = (u2f(src[10]) * u2f(src[3]) - u2f(src[11]) * u2f(src[2])) * invDet;
        out[2] = f2u(i01);

        float i02 = (u2f(src[7]) * u2f(src[2]) - u2f(src[6]) * u2f(src[3])) * invDet;
        out[3] = f2u(i02);

        // Row 1 of inverse
        float i10 = (u2f(src[9]) * u2f(src[7]) - u2f(src[11]) * u2f(src[5])) * invDet;
        out[5] = f2u(i10);

        float i11 = (u2f(src[11]) * u2f(src[1]) - u2f(src[9]) * u2f(src[3])) * invDet;
        out[6] = f2u(i11);

        float i12 = (u2f(src[5]) * u2f(src[3]) - u2f(src[1]) * u2f(src[7])) * invDet;
        out[7] = f2u(i12);

        // Row 2 of inverse
        float i20 = (u2f(src[10]) * u2f(src[5]) - u2f(src[6]) * u2f(src[9])) * invDet;
        out[9] = f2u(i20);

        float i21 = (u2f(src[9]) * u2f(src[2]) - u2f(src[10]) * u2f(src[1])) * invDet;
        out[10] = f2u(i21);

        float i22 = (u2f(src[6]) * u2f(src[1]) - u2f(src[5]) * u2f(src[2])) * invDet;
        out[11] = f2u(i22);
    }

    // ── Translation column ──
    float tX = 0.0f, tY = 0.0f, tZ = 0.0f;
    if ((*src & 0x10) == 0) {
        out[4] = 0;
        out[8] = 0;
    } else {
        // Apply depth XOR key to src[8], then compute inverse translation
        float xorKey = u2f(src[8] ^ g_depthXorKey);
        float i01 = u2f(out[2]);
        float i02 = u2f(out[3]);
        float i00 = u2f(out[1]);
        out[4] = f2u(xorKey * i01 - i00 * u2f(src[4]) - i02 * u2f(src[12]));

        float i11 = u2f(out[6]);
        float i10 = u2f(out[5]);
        float i12 = u2f(out[7]);
        out[8] = f2u(xorKey * i11 - i10 * u2f(src[4]) - i12 * u2f(src[12]));

        float i21 = u2f(out[10]);
        float i20 = u2f(out[9]);
        float i22 = u2f(out[11]);
        tZ = xorKey * i21 - i20 * u2f(src[4]) - i22 * u2f(src[12]);
    }
    out[12] = f2u(tZ);

    // Perspective row: always [0, 0, 0, 1]
    out[13] = 0;
    out[14] = 0;
    out[15] = 0;
    out[16] = f2u(1.0f);

    // Copy flags
    out[0] = *src;

    // If we used local buffer, copy to dst
    if (dst != src) {
        memcpy(dst, local, sizeof(local));
    }
}

} // namespace Giants
