// Giants Engine - Vector Matrix Transform Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "VectorTransform.h"
#include <cstring>

namespace Giants {

// ═══════════════════════════════════════════════════════════════════
// TransformVectors (FUN_00639c00) — 23 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Transforms an array of 3D vectors by a 4×4 matrix.
// Vector stride: 12 bytes (3 floats = x, y, z).
// Matrix layout at param_4:
//   [+0]  flags (& 0xb for rotation, & 0x10 for translation)
//   [+1]  m00, [+2] m01, [+3] m02
//   [+4]  tx  (translation x, if flags & 0x10)
//   [+5]  m10, [+6] m11, [+7] m12
//   [+8]  ty  (translation y, if flags & 0x10)
//   [+9]  m20, [+10] m21, [+11] m22
//   [+12] tz  (translation z, if flags & 0x10)

void TransformVectors(uint64_t* dst, const uint64_t* src, int count, const uint32_t* matrix)
{
    uint32_t flags = *matrix;
    bool hasTranslation = (flags & 0x10) != 0;

    if (count == 0) return;

    if ((flags & 0xb) == 0) {
        // ── Identity: just copy vectors ──
        if (hasTranslation) {
            float tx = reinterpret_cast<const float&>(matrix[4]);
            float ty = reinterpret_cast<const float&>(matrix[8]);
            float tz = reinterpret_cast<const float&>(matrix[12]);
            const float* in = reinterpret_cast<const float*>(src) + 2;  // skip to first xyz
            float* out = reinterpret_cast<float*>(dst) + 2;
            do {
                out[-2] = in[-2] + tx;
                out[-1] = in[-1] + ty;
                *out = *in + tz;
                out += 3;
                in += 3;
                count--;
            } while (count != 0);
        } else {
            // Pure copy
            const uint32_t* in32 = reinterpret_cast<const uint32_t*>(src);
            uint32_t* out32 = reinterpret_cast<uint32_t*>(dst);
            do {
                out32[0] = in32[0];
                out32[1] = in32[1];
                out32[2] = in32[2];  // Ghidra shows copy via uint64 + uint32
                out32 += 3;
                in32 += 3;
                count--;
            } while (count != 0);
        }
        return;
    }

    // ── Matrix transform ──
    float m00 = reinterpret_cast<const float&>(matrix[1]);
    float m01 = reinterpret_cast<const float&>(matrix[2]);
    float m02 = reinterpret_cast<const float&>(matrix[3]);
    float m10 = reinterpret_cast<const float&>(matrix[5]);
    float m11 = reinterpret_cast<const float&>(matrix[6]);
    float m12 = reinterpret_cast<const float&>(matrix[7]);
    float m20 = reinterpret_cast<const float&>(matrix[9]);
    float m21 = reinterpret_cast<const float&>(matrix[10]);
    float m22 = reinterpret_cast<const float&>(matrix[12]);

    const float* in = reinterpret_cast<const float*>(src) + 2;  // skip padding
    float* out = reinterpret_cast<float*>(dst) + 2;

    if (!hasTranslation) {
        // Rotation only
        do {
            float x = in[-2], y = in[-1], z = *in;
            out[-2] = m00 * x + m01 * y + m02 * z;
            out[-1] = m10 * x + m11 * y + m12 * z;
            *out = m20 * x + m21 * y + m22 * z;
            out += 3;
            in += 3;
            count--;
        } while (count != 0);
    } else {
        // Rotation + translation
        float tx = reinterpret_cast<const float&>(matrix[4]);
        float ty = reinterpret_cast<const float&>(matrix[8]);
        float tz = reinterpret_cast<const float&>(matrix[12]);
        do {
            float x = in[-2], y = in[-1], z = *in;
            out[-2] = m00 * x + m01 * y + m02 * z + tx;
            out[-1] = m10 * x + m11 * y + m12 * z + ty;
            *out = m20 * x + m21 * y + m22 * z + tz;
            out += 3;
            in += 3;
            count--;
        } while (count != 0);
    }
}

} // namespace Giants
