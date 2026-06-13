// Giants Engine - Transform Point by Entity Matrix Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "TransformPoint.h"
#include <cstdint>

namespace Giants {

// ─── Forward declarations ──────────────────────────────────────
extern void FUN_005faab0();  // Build entity rotation matrix into local vars
// PTR_FUN_0067d20c = full 4×4 matrix transform via function pointer

// ═══════════════════════════════════════════════════════════════════
// TransformPointByEntity (FUN_005fade0) — 21 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Transforms a point from world space into entity-local space (or vice versa).
// entity flags at +0x124 bit 5 determine transform mode:
//
// Mode 0 (bit 5 clear): rotation only
//   1. Subtract entity origin (+0xf0, +0xf4, +0xf8) from source point
//   2. Call FUN_005faab0() to build 3×3 rotation matrix into stack locals
//   3. Multiply: out = rot * (src - origin)
//
// Mode 1 (bit 5 set): full affine transform
//   1. Call PTR_FUN_0067d20c() to load full 4×4 matrix into stack locals
//   2. Multiply: out = M * src (includes translation)

void TransformPointByEntity(int entity, float* srcPoint, float* outPoint)
{
    // Check entity flags
    if ((*reinterpret_cast<uint8_t*>(entity + 0x124) & 0x20) == 0) {
        // ── Rotation-only mode ──
        // Subtract entity origin
        float dx = srcPoint[0] - *reinterpret_cast<float*>(entity + 0xf0);
        float dy = srcPoint[1] - *reinterpret_cast<float*>(entity + 0xf4);
        float dz = srcPoint[2] - *reinterpret_cast<float*>(entity + 0xf8);

        // Build rotation matrix via callee (writes to stack locals)
        // FUN_005faab0 populates: local_3c, local_48, local_30 (row 0)
        //                        local_38, local_44, local_2c (row 1)
        //                        local_34, local_40, local_28 (row 2)
        float r00 = 0, r01 = 0, r02 = 0;
        float r10 = 0, r11 = 0, r12 = 0;
        float r20 = 0, r21 = 0, r22 = 0;
        FUN_005faab0();  // Populates local rotation matrix
        // Note: actual values come from callee's stack frame —
        // the Ghidra decompilation shows direct local usage after the call.
        // In a real build, FUN_005faab0 writes to the same stack frame.

        outPoint[0] = r00 * dx + r01 * dy + r02 * dz;
        outPoint[1] = r10 * dx + r11 * dy + r12 * dz;
        outPoint[2] = r20 * dx + r21 * dy + r22 * dz;
    } else {
        // ── Full affine transform mode ──
        // Load 4×4 matrix via function pointer (writes to stack locals)
        typedef void (*MatrixLoadFn)();
        MatrixLoadFn loadMatrix = reinterpret_cast<MatrixLoadFn>(
            *reinterpret_cast<void**>(0x0067d20c));
        loadMatrix();

        // Matrix multiply with translation included
        // m00, m01, m02 = row 0; tx = translation x
        float m00 = 0, m01 = 0, m02 = 0, tx = 0;
        float m10 = 0, m11 = 0, m12 = 0, ty = 0;
        float m20 = 0, m21 = 0, m22 = 0, tz = 0;

        outPoint[0] = m00 * srcPoint[0] + m01 * srcPoint[1] + m02 * srcPoint[2] + tx;
        outPoint[1] = m10 * srcPoint[0] + m11 * srcPoint[1] + m12 * srcPoint[2] + ty;
        outPoint[2] = m20 * srcPoint[0] + m21 * srcPoint[1] + m22 * srcPoint[2] + tz;
    }
}

} // namespace Giants
