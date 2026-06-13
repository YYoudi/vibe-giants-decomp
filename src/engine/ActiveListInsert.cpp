// Giants Engine - Active List Node Insert Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
// re-agent verdict: FAIL (usable ~85%)
#include "ActiveListInsert.h"
#include <cstdlib>
#include <cstring>

namespace Giants {

static int* g_freeList = nullptr;          // DAT_007496bc
static int* g_activeListHead = nullptr;    // DAT_007496c0
static int* g_listHead = nullptr;          // DAT_007496c4
static int* g_listTail = nullptr;          // DAT_007496c8
static int   g_nextId = 0;                 // DAT_00685a5c
static int   g_disabled = 0;               // DAT_00702bb8

extern void OnDuplicateFound();  // FUN_005584d0

int InsertActiveNode(int p1, int p2, int p3, int p4, uint64_t* p5, uint32_t flags)
{
    if (g_disabled != 0)
        return 0;

    int* node = g_freeList;

    if (node == nullptr)
    {
        // Allocate block of 9 nodes (0x48 bytes each = 0x2D4 total)
        int* block = static_cast<int*>(malloc(0x2D4));
        node = block + 1;

        // Link block header into active list head chain
        *reinterpret_cast<int**>(block) = g_activeListHead;
        g_activeListHead = block;

        // Chain 9 nodes: each node is 0x12 ints (0x48 bytes)
        for (int i = 0; i < 8; i++)
        {
            *reinterpret_cast<int**>(block + 1 + i * 0x12) = block + 1 + (i + 1) * 0x12;
        }
        *reinterpret_cast<int**>(block + 1 + 8 * 0x12) = nullptr;
    }

    // Pop from free list
    g_freeList = *reinterpret_cast<int**>(node);
    memset(node, 0, 0x48);

    // Handle flag bit 1: walk to end of linked list at p4+0x264
    if ((flags & 2) != 0)
    {
        if (p4 != 0)
        {
            int* walk = reinterpret_cast<int*>(*(int*)(p4 + 0x264));
            while (walk != nullptr)
            {
                p4 = reinterpret_cast<int>(walk);
                walk = reinterpret_cast<int*>(*(int*)(p4 + 0x264));
            }
        }

        if (p4 == 0x00702774)  // root node sentinel
        {
            p5 = nullptr;
            goto fill_fields;
        }
    }

    node[10] = p4;  // +0x28

fill_fields:
    node[2]  = p1;   // +0x08
    node[3]  = p2;   // +0x0C
    node[11] = p4;   // +0x2C

    int myId = g_nextId;
    int defaultVal = ((flags & 1) != 0) ? 1 : 0;

    node[17] = g_nextId;  // +0x44
    node[8]  = defaultVal; // +0x20
    node[4]  = p3;         // +0x10
    node[16] = static_cast<int>(flags);  // +0x40

    g_nextId = myId + 1;

    // Copy p5 data if present
    if (p5 != nullptr)
    {
        *reinterpret_cast<uint64_t*>(node + 12) = *p5;  // +0x30
        node[14] = static_cast<int>(*(p5 + 1));         // +0x38
    }
    node[15] = static_cast<int>(p5 != nullptr);  // +0x3C

    // Initialize next pointer
    *node = 0;

    // Insert at tail of active list
    if (g_listHead == nullptr)
    {
        node[1] = 0;
        g_listHead = node;
    }
    else
    {
        node[1] = reinterpret_cast<int>(g_listTail);
        *g_listTail = reinterpret_cast<int>(node);
    }
    g_listTail = node;

    // Check for duplicate in active list
    int* scan = g_listHead;
    if (node[11] != 0 && scan != nullptr)
    {
        while (true)
        {
            if (scan == node) goto next;
            if (scan[11] != node[11]) goto next;
            if (scan[2] != node[2]) goto next;
            if (scan[3] != node[3]) goto next;
            if (scan[4] == node[4]) break;
        next:
            scan = *reinterpret_cast<int**>(scan);
            if (scan == nullptr)
                return myId;
        }
        OnDuplicateFound();
    }

    return myId;
}

} // namespace Giants
