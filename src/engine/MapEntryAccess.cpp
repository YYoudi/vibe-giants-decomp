// Giants Engine - Map/Container Entry Access Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "MapEntryAccess.h"
#include <cstdint>

namespace Giants {

// ─── External callee ──────────────────────────────────────────
extern uint32_t FUN_004b7340();  // Tree node traversal

// ═══════════════════════════════════════════════════════════════════
// MapEntryAccess (FUN_004b7490) — 16 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Container layout (int* param_1):
//   [+0] = tree depth / size indicator
//   [+1] = capacity / tree state
//   [+2] = data pointer (array of 16-byte entries)
//
// Two paths:
//   If depth < 1 and depth < 0: tree traversal via FUN_004b7340
//   If index < size: direct array access at index * 0x10

uint32_t* MapEntryAccess(int* container, uint32_t* output, int index)
{
    int depth = container[1];
    int size = container[0];

    output[2] = 0;  // Zero initialize third field

    // Tree path: depth < 1 and negative
    if ((depth < 1) && (depth < 0)) {
        // Direct array lookup
        if (index < size) {
            auto* src = reinterpret_cast<uint32_t*>(container[2] + index * 0x10);
            output[0] = src[0];
            output[1] = src[1];
            output[2] = src[2];
            output[3] = src[3];
            return output;
        }
    }

    // Tree traversal path
    if (depth < 0) {
        FUN_004b7340();  // Traverse tree to find entry
        return output;
    }

    // Positive depth: direct array access
    if (index < size) {
        auto* src = reinterpret_cast<uint32_t*>(container[2] + index * 0x10);
        output[0] = src[0];
        output[1] = src[1];
        output[2] = src[2];
        output[3] = src[3];
        return output;
    }

    return output;
}

} // namespace Giants
