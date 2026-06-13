// Giants Engine - Mesh Hit Test Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "MeshHitTest.h"
#include <cstdint>

namespace Giants {

// ─── Mesh structures (inferred from decompilation) ─────────────
// Mesh object layout:
//   +0x08: int** vertex_buffers
//   +0x0C: int** index_buffers
//   +0x18: int*  mesh_data (array of mesh item descriptors)
//   +0x3C: float test_x (hit test coordinate)
//   +0x40: float test_y (hit test coordinate)
//
// MeshItem layout (in mesh_data array):
//   +0x0C: void* callback (hit callback, nullptr = auto-confirm)
//   +0x14: int   index_count
//   +0x18: uint  flags (bit 0-1: test mode, bit 2: AABB enabled, bit 5: scaling)
//   +0x38: float min_x
//   +0x3C: float min_y
//   +0x44: float max_x
//   +0x48: float max_y
//   +0x50: int   buffer_index

// ═══════════════════════════════════════════════════════════════════
// ProcessMeshHitTest (FUN_005de120) — 24 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Two-phase mesh hit test:
//   Phase 1: Clear visibility flags on all items (mask off 0x3C00)
//   Phase 2: For each item (reverse order):
//     - If flags & 3 == 0: AABB test (if flags & 4, check bounds)
//     - If flags & 3 != 0: Per-triangle point-in-triangle using cross products
//     - On hit, call item->callback if present, return item index
// Returns -1 if no hit, or the index of the hit item.

int ProcessMeshHitTest(int mesh, int meshIndex)
{
    int result = -1;
    int lastResult = -1;

    float testX = *reinterpret_cast<float*>(mesh + 0x3c);
    float testY = *reinterpret_cast<float*>(mesh + 0x40);

    // Get mesh data for this index
    char* meshDataBase = reinterpret_cast<char*>(*reinterpret_cast<int*>(mesh + 0x18));
    int itemCount = *reinterpret_cast<int*>(meshDataBase + meshIndex * 0x24 + 4);
    int* itemPtrs = reinterpret_cast<int*>(*reinterpret_cast<int*>(meshDataBase + meshIndex * 0x24));
    int* currentPtr = &itemPtrs[itemCount - 1];

    int remaining = itemCount;

    if (itemCount == 0) {
        return result;
    }

    // ── Phase 1: Clear visibility flags on all items ──
    int* iterPtr = currentPtr;
    do {
        int itemAddr = *iterPtr;
        iterPtr--;
        *reinterpret_cast<uint32_t*>(itemAddr + 0x18) &= ~0x3C00;
        remaining--;
    } while (remaining != 0);

    // ── Phase 2: Hit testing (iterate in reverse) ──
    while (true) {
        itemCount--;
        if (result >= 0) break;

        int itemAddr = *currentPtr;
        int currentResult = lastResult;
        uint32_t flags = *reinterpret_cast<uint32_t*>(itemAddr + 0x18);

        if ((flags & 3) == 0) {
            // ── AABB hit test ──
            if ((flags & 4) != 0) {
                float minX = *reinterpret_cast<float*>(itemAddr + 0x38);
                float minY = *reinterpret_cast<float*>(itemAddr + 0x3c);
                float maxX = *reinterpret_cast<float*>(itemAddr + 0x44);
                float maxY = *reinterpret_cast<float*>(itemAddr + 0x48);

                if ((minX <= testX) && (testX <= maxX) &&
                    (minY <= testY) && (testY <= maxY)) {

                    void* callback = *reinterpret_cast<void**>(itemAddr + 0x0c);
                    if (callback == nullptr) {
                        return itemCount;
                    }

                    int cbResult = reinterpret_cast<int(*)(int, int, int, void**)>(callback)(
                        mesh, itemAddr, 0, reinterpret_cast<void**>(itemAddr + 0x0c));

                    result = itemCount;
                    currentResult = itemCount;

                    if (cbResult != 0) {
                        return itemCount;
                    }
                }
            }
        } else {
            // ── Per-triangle hit test ──
            uint16_t prevIndex = 0xFFFF;
            int bufferIndex = *reinterpret_cast<int*>(itemAddr + 0x50) * 4;
            int indexCount = *reinterpret_cast<int*>(itemAddr + 0x14);

            // Get buffers (note: swapped in Ghidra decompilation)
            int vertexBufferAddr = *reinterpret_cast<int*>(
                *reinterpret_cast<int*>(mesh + 0x0c) + bufferIndex);
            char* vertexBase = reinterpret_cast<char*>(vertexBufferAddr);

            int indexBufferAddr = *reinterpret_cast<int*>(
                *reinterpret_cast<int*>(mesh + 0x08) + bufferIndex);
            uint16_t* triBase = reinterpret_cast<uint16_t*>(indexBufferAddr);

            // Navigate to triangle strip data
            uint16_t* triPtr = triBase + (indexCount + 1) * 0x90;

            while (true) {
                uint16_t idx0 = 0;
                if (prevIndex != 0xFFFF) {
                    idx0 = prevIndex;
                }

                uint32_t idx0_32 = static_cast<uint32_t>(idx0);
                uint16_t triCount = *triPtr;
                result = lastResult;

                if (triCount == 0) goto loop_end;

                // Get triangle vertex indices
                uint16_t* p1 = triPtr + idx0_32 * 3 + 1;
                uint16_t* p2 = triPtr + idx0_32 * 3 + 2;
                uint16_t* p3 = triPtr + idx0_32 * 3 + 3;

                prevIndex = idx0 + 1;
                if (prevIndex == triCount) {
                    triPtr += static_cast<uint32_t>(triCount) * 3 + 1;
                    prevIndex = 0;
                }

                // Get vertex positions (stride 0x38, x at +0x18, y at +0x1C)
                float v1_x = *reinterpret_cast<float*>(vertexBase + static_cast<uint32_t>(*p1) * 0x38 + 0x18);
                float v1_y = *reinterpret_cast<float*>(vertexBase + static_cast<uint32_t>(*p1) * 0x38 + 0x1C);
                float v2_x = *reinterpret_cast<float*>(vertexBase + static_cast<uint32_t>(*p2) * 0x38 + 0x18);
                float v2_y = *reinterpret_cast<float*>(vertexBase + static_cast<uint32_t>(*p2) * 0x38 + 0x1C);
                float v3_x = *reinterpret_cast<float*>(vertexBase + static_cast<uint32_t>(*p3) * 0x38 + 0x18);
                float v3_y = *reinterpret_cast<float*>(vertexBase + static_cast<uint32_t>(*p3) * 0x38 + 0x1C);

                // Point-in-triangle using cross products (CCW winding)
                float cross1 = (v1_y - v2_y) * (testX - v2_x) - (v1_x - v2_x) * (testY - v2_y);
                float cross2 = (v2_y - v3_y) * (testX - v3_x) - (v2_x - v3_x) * (testY - v3_y);
                float cross3 = (v3_y - v1_y) * (testX - v1_x) - (v3_x - v1_x) * (testY - v1_y);

                // All cross products must be >= 0 for point inside triangle
                if (!(cross1 < 0.0f) && !(cross2 < 0.0f) && !(cross3 < 0.0f)) {
                    break;  // Hit!
                }
            }

            result = itemCount;
            currentResult = itemCount;

            void* callback = *reinterpret_cast<void**>(itemAddr + 0x0c);
            if (callback != nullptr) {
                int cbResult = reinterpret_cast<int(*)(int, int, int, void**)>(callback)(
                    mesh, itemAddr, 0, reinterpret_cast<void**>(itemAddr + 0x0c));

                if (cbResult == 0) {
                    result = lastResult;
                    currentResult = lastResult;
                }
            }
        }

    loop_end:
        lastResult = currentResult;
        currentPtr--;

        if (itemCount == 0) {
            return result;
        }
    }

    return result;
}

} // namespace Giants
