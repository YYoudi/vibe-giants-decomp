// Giants Engine - Pool Node Release Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "PoolNodeRelease.h"
#include <cstdint>

namespace Giants {

// ─── Shared globals ────────────────────────────────────────────
extern int* g_FreeList;  // DAT_0074896c — EntityList.cpp

// ═══════════════════════════════════════════════════════════════════
// ReleasePoolNode (FUN_00523320) — 18 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Unlinks a node from a doubly-linked list (param_2) and pushes it
// onto the global free list. Walks the list to find the node, verifies
// its prev pointer matches, then performs standard unlink + free-list push.
//
// Node layout: [+0] next, [+4] prev, [+8..] data

void ReleasePoolNode(int** listHead, int* node)
{
    int* current = *reinterpret_cast<int**>(node);
    if (current == nullptr) {
        return;
    }

    // Walk list to find the node whose next->prev matches
    while (true) {
        int* prevNode = reinterpret_cast<int*>(current[3]);  // prev pointer
        if (prevNode == *listHead) {
            break;
        }
        current = *reinterpret_cast<int**>(current);
        if (current == nullptr) {
            return;
        }
    }

    // Unlink current from its list
    int* prevNode = reinterpret_cast<int*>(current[3]);
    *reinterpret_cast<int**>(prevNode[1]) = reinterpret_cast<int*>(prevNode[0]);
    if (prevNode[0] != 0) {
        *reinterpret_cast<int**>(prevNode[0] + 4) = reinterpret_cast<int*>(prevNode[1]);
    }

    // Push to free list
    prevNode[0] = reinterpret_cast<int>(g_FreeList);

    // Unlink node from its list
    *reinterpret_cast<int**>(current[1]) = reinterpret_cast<int*>(current[0]);
    if (current[0] != 0) {
        *reinterpret_cast<int**>(current[0] + 4) = reinterpret_cast<int*>(current[1]);
    }

    // Link node to freed prevNode and push to free list head
    current[0] = reinterpret_cast<int>(prevNode);
    g_FreeList = current;
}

} // namespace Giants
