// Giants Engine - Pool Allocator Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "PoolAllocator.h"
#include <cstdlib>
#include <cstring>

namespace Giants {

// ─── Globals ───────────────────────────────────────────────────
static int* g_freeList = nullptr;           // DAT_0073e790 — free node list head
static int* g_freeListNext = nullptr;       // DAT_0073e794 — linked list of blocks
static int   g_sseThreshold = 0;            // DAT_006fd52c — >= 2 enables SSE path

// ═══════════════════════════════════════════════════════════════════
// AllocateNode (FUN_0048ef70) — 34 callers — FAIL (usable ~90%)
// ═══════════════════════════════════════════════════════════════════
// Fixed-size pool allocator (0x1F44 = 8004 bytes per block).
// Each block contains 198 (0xC6) nodes of 40 (0x28) bytes each.
//
// Two initialization paths:
//   1. SSE path (g_sseThreshold >= 2): uses pmulld for grid offsets
//   2. Simple path: links all nodes into singly-linked free list

int* AllocateNode()
{
    if (g_freeList != nullptr) {
        // Pop from free list
        int* node = g_freeList;
        g_freeList = reinterpret_cast<int*>(*node);
        *node = 0;
        node[1] = 0;
        node[2] = 0;
        node[3] = 0;
        node[4] = 0;
        node[5] = 0;
        node[6] = 0;
        node[7] = 0;
        *reinterpret_cast<int64_t*>(&node[8]) = 0;
        return node;
    }

    // Free list empty — allocate new block
    int* node = static_cast<int*>(malloc(0x1F44));
    *node = reinterpret_cast<int>(g_freeListNext);
    g_freeListNext = node;

    // SSE config values (from DAT_0066c380..DAT_0066c3d0)
    int iVar8 = 0;    // DAT_0066c38c
    int iVar7 = 0;    // DAT_0066c388
    int iVar13 = 0;   // DAT_0066c384
    int iVar6 = 0;    // DAT_0066c380
    int* puVar12 = node + 1;  // First node slot (after header)

    // SSE grid initialization config
    int iVar2 = 0;  // DAT_0066c3d0._0_4_
    int iVar3 = 0;  // DAT_0066c3d0._4_4_
    int iVar4 = 0;  // DAT_0066c3d0._8_4_
    int iVar5 = 0;  // DAT_0066c3d0._12_4_

    int iVar14 = 0;

    if (g_sseThreshold >= 2) {
        // SSE path: grid offset calculation with pmulld
        int* piVar11 = node + 0x15;

        do {
            int iVar1 = iVar14 + 4;

            // First set: compute 4 node offsets using SSE multiply
            // auVar15 = pmulld({iVar14+iVar6, iVar14+iVar13, iVar14+iVar7, iVar14+iVar8}, auVar9)
            // piVar11[-0x14] = puVar12 + iVar2 + result[0]
            // piVar11[-10]   = puVar12 + iVar3 + result[1]
            // *piVar11       = puVar12 + iVar4 + result[2]
            // piVar11[10]    = puVar12 + iVar5 + result[3]

            iVar14 = iVar14 + 8;

            // Second set: same pattern with iVar1 base
            // auVar16 = pmulld({iVar1+iVar6, iVar1+iVar13, iVar1+iVar7, iVar1+iVar8}, auVar9)
            // piVar11[0x14]..piVar11[0x32]

            piVar11 = piVar11 + 0x50;
        } while (iVar14 < 0xC0);
    }

    // Simple linked-list initialization (fallback or remaining)
    if (iVar14 < 0xC6) {
        int remaining = 0xC6 - iVar14;
        int* puVar10 = puVar12 + iVar14 * 10;
        iVar14 = 0xC6;
        do {
            *puVar10 = reinterpret_cast<int>(puVar10 + 10);
            remaining--;
            puVar10 = puVar10 + 10;
        } while (remaining != 0);
    }

    // Null-terminate last node
    puVar12[iVar14 * 10] = 0;

    // Pop from free list (now populated)
    g_freeList = reinterpret_cast<int*>(*node);
    *node = 0;
    node[1] = 0;
    node[2] = 0;
    node[3] = 0;
    node[4] = 0;
    node[5] = 0;
    node[6] = 0;
    node[7] = 0;
    *reinterpret_cast<int64_t*>(&node[8]) = 0;

    return node;
}

} // namespace Giants
