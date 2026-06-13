// Giants Engine - Object Pool Allocator Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "ObjectPoolAlloc.h"
#include <cstdlib>
#include <cstring>

namespace Giants {

// ─── Shared pool globals (defined in EntitySystem.cpp / GameContext.cpp) ──
extern uint32_t* DAT_007496bc;    // Free list head (alternate pool)
extern uint32_t* DAT_007496c0;    // Pool allocation chain head
extern uint32_t* DAT_007496c4;    // Active list head
extern uint32_t* DAT_007496c8;    // Active list tail
extern int       g_NextId;        // DAT_00685a5c — auto-increment ID
extern float     DAT_0066bf2c;    // 1.0f
extern int*      g_SomeGlobal;    // DAT_00702774 — entity comparison target

// ─── Module-local state ────────────────────────────────────────
static bool     g_PoolInitialized = false;  // DAT_00702bb8
static int*     g_PoolFreeList = nullptr;    // Local free list for 0x48 nodes

// ─── External callee ──────────────────────────────────────────
extern void FUN_005584d0();  // Object dedup notify

// ═══════════════════════════════════════════════════════════════════
// AllocatePoolObject (FUN_00558730) — 22 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Allocates a 0x48-byte node from a pool, initializes it, and links
// it into the active doubly-linked list.
//
// Pool: Each malloc(0x2D4) is split into 8 nodes of 0x48 bytes.
// The malloc header (+0) links to the pool chain. Nodes are:
//   node[0] = next free node
//   node[1..7] = 7 remaining sub-nodes linked via offset 0.
//
// Node layout (0x48 bytes = 18 int fields):
//   [+0x00] list_next, [+0x04] list_prev
//   [+0x08] param_1, [+0x0C] param_2
//   [+0x10] param_3, [+0x14] flags (param_6 & 1 ? 1.0f : 0)
//   [+0x18..+0x28] param_5 data (position/offset)
//   [+0x2C] has_param_5 flag
//   [+0x2C..+0x30] param_4 (parent entity)
//   [+0x34] param_4 duplicate
//   [+0x40] auto-increment ID, [+0x44] param_6 flags

int AllocatePoolObject(int param_1, int param_2, int param_3,
                       int param_4, uint64_t* param_5, uint32_t param_6)
{
    if (g_PoolInitialized) {
        return 0;
    }

    // Allocate from free list or create new pool block
    int* node = g_PoolFreeList;
    if (g_PoolFreeList == nullptr) {
        int* block = static_cast<int*>(malloc(0x2D4));
        node = block + 1;
        *reinterpret_cast<int**>(block) = reinterpret_cast<int*>(DAT_007496c0);
        DAT_007496c0 = reinterpret_cast<uint32_t*>(block);

        // Split block into 8 sub-nodes (0x48 bytes each, 0x12 ints)
        *reinterpret_cast<int**>(node) = block + 0x13;
        block[0x13] = reinterpret_cast<int>(block + 0x25);
        block[0x25] = reinterpret_cast<int>(block + 0x37);
        block[0x37] = reinterpret_cast<int>(block + 0x49);
        block[0x49] = reinterpret_cast<int>(block + 0x5B);
        block[0x5B] = reinterpret_cast<int>(block + 0x6D);
        block[0x6D] = reinterpret_cast<int>(block + 0x7F);
        block[0x7F] = 0;
    }

    g_PoolFreeList = *reinterpret_cast<int**>(node);
    memset(node, 0, 0x48);

    // Handle param_6 flag 2: walk parent chain to root
    if ((param_6 & 2) != 0) {
        if (param_4 != 0) {
            int parent = *reinterpret_cast<int*>(param_4 + 0x264);
            while (parent != 0) {
                param_4 = parent;
                parent = *reinterpret_cast<int*>(parent + 0x264);
            }
        }
        if (param_4 == reinterpret_cast<int>(g_SomeGlobal)) {
            param_5 = nullptr;
            goto LAB_init_fields;
        }
    }

    node[10] = param_4;

LAB_init_fields:
    node[2] = param_1;
    node[3] = param_2;
    node[0xB] = param_4;

    int resultId = g_NextId;
    int flagValue = 0;
    if ((param_6 & 1) != 0) {
        flagValue = static_cast<int>(DAT_0066bf2c);
    }

    node[0x11] = g_NextId;
    int nextId = g_NextId + 1;
    node[8] = flagValue;
    node[4] = param_3;
    node[0x10] = static_cast<int>(param_6);
    g_NextId = nextId;

    // Copy param_5 (position/offset) if present
    if (param_5 != nullptr) {
        *reinterpret_cast<uint64_t*>(&node[0xC]) = *param_5;
        node[0xE] = static_cast<int>(param_5[1]);
    }
    node[0xF] = static_cast<uint32_t>(param_5 != nullptr);

    // Link into doubly-linked list
    *reinterpret_cast<int**>(node) = nullptr;
    int* listHead = reinterpret_cast<int*>(DAT_007496c4);
    if (listHead == nullptr) {
        node[1] = 0;
        listHead = node;
        DAT_007496c4 = reinterpret_cast<uint32_t*>(node);
    } else {
        node[1] = reinterpret_cast<int>(DAT_007496c8);
        *reinterpret_cast<int*>(DAT_007496c8) = reinterpret_cast<int>(node);
    }
    DAT_007496c8 = reinterpret_cast<uint32_t*>(node);

    // Dedup check: walk list for matching (parent, param_1, param_2, param_3)
    if (node[0xB] != 0 && listHead != nullptr) {
        while (listHead == node ||
               listHead[0xB] != node[0xB] ||
               listHead[2] != node[2] ||
               listHead[3] != node[3] ||
               listHead[4] != node[4]) {
            listHead = *reinterpret_cast<int**>(listHead);
            if (listHead == nullptr) {
                return resultId;
            }
        }
        FUN_005584d0();
        nextId = g_NextId;
    }

    return resultId - 1;
}

} // namespace Giants
