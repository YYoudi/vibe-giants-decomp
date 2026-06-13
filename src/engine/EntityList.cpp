// Giants Engine - Entity Multi-List Registration Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "EntityList.h"
#include "CRTStubs.h"

namespace Giants {

// ─── Globals ──────────────────────────────────────────────────
// 15 linked list heads for entity categories (0x00 - 0x0E)
static ListNode* g_ListHeads[15] = {};

// External callees
extern uint32_t  ResetSpawnPosition();  // FUN_00559670 — returns default category mask
extern ListNode* AllocListNode();       // FUN_005232c0 — allocates a new ListNode

// ═══════════════════════════════════════════════════════════════════
// RegisterEntityInLists (FUN_005597d0) — 62 callers
// ═══════════════════════════════════════════════════════════════════
// Registers an entity into linked lists selected by categoryMask bitmask.
// For each set bit, appends the entity to the corresponding global list
// AND adds a back-link node to the entity's own list.
//
// Original code was 15 copy-pasted blocks (one per bit). Refactored
// into a loop for maintainability while preserving identical behavior.

void RegisterEntityInLists(void* entity, uint32_t categoryMask)
{
    // Special mask 0x80000000: auto-detect from game state
    if (categoryMask == 0x80000000) {
        categoryMask = ResetSpawnPosition();
    }

    // Process each bit (up to 15 categories)
    for (int i = 0; i < 15; i++) {
        uint32_t bit = 1u << i;
        if ((categoryMask & bit) == 0) continue;

        // ─── Append to global list ────────────────────────────
        // Find tail of global list i
        ListNode* tail = reinterpret_cast<ListNode*>(&g_ListHeads[i]);
        for (ListNode* curr = g_ListHeads[i]; curr != nullptr; curr = curr->next) {
            tail = curr;
        }

        // Create global list node
        ListNode* globalNode = AllocListNode();
        globalNode->prev = tail;
        globalNode->next = tail->next;
        globalNode->list_head = reinterpret_cast<ListNode*>(&g_ListHeads[i]);
        globalNode->data = entity;
        tail->next = globalNode;

        if (globalNode->next != nullptr) {
            globalNode->next->prev = globalNode;
        }

        // ─── Add back-link to entity's own list ──────────────
        ListNode* entityNode = AllocListNode();
        entityNode->prev = reinterpret_cast<ListNode*>(entity);
        entityNode->next = *reinterpret_cast<ListNode**>(entity);
        entityNode->list_head = reinterpret_cast<ListNode*>(entity);
        entityNode->data = globalNode;
        *reinterpret_cast<ListNode**>(entity) = entityNode;

        if (entityNode->next != nullptr) {
            entityNode->next->prev = entityNode;
        }
    }
}

// ═══════════════════════════════════════════════════════════════════
// AllocListNode (FUN_005232c0) — 52 callers
// ═══════════════════════════════════════════════════════════════════
// Slab allocator for ListNode objects. Maintains a free-list of 16-byte
// blocks. When empty, allocates a new slab of 198 blocks (0xC84 bytes).
// Slabs are tracked via a linked list of headers (g_Sentinel chain).

static int* g_FreeList = nullptr;   // DAT_0074896c — head of free block list
static int* g_Sentinel = nullptr;   // DAT_00748970 — slab header chain

ListNode* AllocListNode()
{
    if (g_FreeList == nullptr) {
        // Allocate new slab: 4-byte header + 198 × 16-byte blocks = 0xC84 bytes
        unsigned int* slab = static_cast<unsigned int*>(malloc(0xC84));
        int count = 0xc6;  // 198 blocks

        // Link slab header into sentinel chain
        g_FreeList = slab + 1;
        *slab = reinterpret_cast<unsigned int>(g_Sentinel);
        g_Sentinel = reinterpret_cast<int*>(slab);

        // Initialize free-list: each block points to next (stride = 4 ints = 16 bytes)
        int* block = g_FreeList;
        do {
            *block = reinterpret_cast<int>(block + 4);
            count = count - 1;
            block = block + 4;
        } while (count != 0);

        // Terminate last block
        slab[0x319] = 0;  // offset 0xC64 = last block's next pointer
    }

    // Pop first block from free-list
    int* result = g_FreeList;
    g_FreeList = reinterpret_cast<int*>(*g_FreeList);
    return reinterpret_cast<ListNode*>(result);
}

} // namespace Giants
