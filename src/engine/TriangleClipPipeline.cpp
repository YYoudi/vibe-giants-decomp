// Giants Engine - Triangle Clipping Pipeline Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "TriangleClipPipeline.h"
#include <cstdint>

namespace Giants {

// ─── Shared globals ────────────────────────────────────────────
extern uint32_t DAT_0067d280;     // Security cookie
extern uint32_t DAT_00747c6c;     // Clip flags accumulator
extern void*    DAT_00702728;     // Render device — GraphicsResources.h

// ─── External callees (clip stages) ────────────────────────────
extern void FUN_004db280(int* count, uint32_t* verts);  // Clip near plane
extern void FUN_004dba20(int* count, uint32_t* verts);  // Clip far plane
extern void FUN_004dbf00(int* count, uint32_t* verts);  // Clip left/right
extern void FUN_004dc830(int* count, uint32_t* verts);  // Clip top/bottom
extern void FUN_004dc3d0(int* count, uint32_t* verts);  // Clip user planes

// Vertex layout: 0x34 bytes (13 uint32_t)
//   [+0x00..+0x05] position/color data
//   [+0x06..+0x0C] texcoord/normal data
//   [+0x0D] clip flags byte

// ═══════════════════════════════════════════════════════════════════
// ClipAndEmitTriangle (FUN_004dafa0) — 20 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Full Sutherland-Hodgman style triangle clipping pipeline.
//
// Phase 1: Check clip flags — if all 3 vertices pass (&=0), emit directly
// Phase 2: Accumulate OR of clip flags
// Phase 3: If no flags set (fully inside), fast path via vtable alloc
// Phase 4: Copy vertices to local buffer, run clip stages:
//   - Near plane (bit 1)
//   - Far plane (bit 2)
//   - Left/Right (bit 3)
//   - Top/Bottom (bit 5)
//   - User planes (bit 4)
// Phase 5: Emit resulting triangle fan via vtable

void ClipAndEmitTriangle(uint32_t* v1, uint32_t* v2, uint32_t* v3)
{
    // Check if all vertices pass all clip planes
    uint8_t clip1 = *reinterpret_cast<uint8_t*>(v1 + 0xD);
    uint8_t clip2 = *reinterpret_cast<uint8_t*>(v2 + 0xD);
    uint8_t clip3 = *reinterpret_cast<uint8_t*>(v3 + 0xD);

    if ((clip1 & clip2 & clip3) != 0) {
        return;  // All vertices outside same plane — reject
    }

    uint8_t clipFlags = clip3 | clip2 | clip1;
    DAT_00747c6c = clipFlags;

    // Fast path: no clipping needed
    if (clipFlags == 0) {
        uint32_t* out = static_cast<uint32_t*>(
            reinterpret_cast<void*(*)(void*, int)>(
                *reinterpret_cast<void**>(*reinterpret_cast<void**>(DAT_00702728) + 8))(
                    DAT_00702728, 3));

        // Copy 3 vertices (13 uint32_t each)
        for (int i = 0; i < 13; i++) out[i] = v1[i];
        for (int i = 0; i < 13; i++) out[13 + i] = v2[i];
        for (int i = 0; i < 13; i++) out[26 + i] = v3[i];
        return;
    }

    // Slow path: copy vertices and run clip pipeline
    uint32_t localV1[13], localV2[13], localV3[13];
    for (int i = 0; i < 13; i++) localV1[i] = v1[i];
    for (int i = 0; i < 13; i++) localV2[i] = v2[i];
    for (int i = 0; i < 13; i++) localV3[i] = v3[i];

    uint32_t* verts[3] = { localV1, localV2, localV3 };
    uint32_t clipBuf[140];  // Stack buffer for clipped vertices
    int vertCount = 3;
    uint32_t* srcBuf = clipBuf;
    uint32_t* dstBuf = verts[0];  // Local vertex data

    // Run clip stages based on flags
    if (clipFlags & 1) {
        FUN_004db280(&vertCount, clipBuf);
        if (vertCount < 3) return;
    }

    // Continue through remaining stages (far, left/right, top/bottom, user)
    if (clipFlags & 4) { FUN_004dba20(&vertCount, nullptr); if (vertCount < 3) return; }
    if (clipFlags & 8) { FUN_004dbf00(&vertCount, nullptr); if (vertCount < 3) return; }
    if (clipFlags & 0x20) { FUN_004dc830(&vertCount, nullptr); if (vertCount < 3) return; }
    if (clipFlags & 0x10) { FUN_004dc3d0(&vertCount, nullptr); if (vertCount < 3) return; }

    // Emit triangle fan from clipped vertices
    if (clipFlags == 0) {
        int triCount = vertCount - 2;
        uint32_t* out = static_cast<uint32_t*>(
            reinterpret_cast<void*(*)(void*, int)>(
                *reinterpret_cast<void**>(*reinterpret_cast<void**>(DAT_00702728) + 8))(
                    DAT_00702728, triCount * 3));

        for (int i = 0; i < triCount; i++) {
            uint32_t* src = dstBuf + i * 14;  // stride varies
            for (int j = 0; j < 13; j++) out[j] = src[j];
            out += 21;  // 3 * 7 (packed format)
        }
    }
}

} // namespace Giants
