// Giants Engine - Entity Multi-List Registration
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── Doubly-linked list node ──────────────────────────────────
struct ListNode {
    ListNode* next;
    ListNode* prev;
    ListNode* list_head;
    void*     data;
};

// ─── RegisterEntityInLists (FUN_005597d0) ─────────────────────
// Registers an entity into multiple category linked lists based on a bitmask.
// Each bit (0-14) corresponds to one of 15 global linked list heads.
// Creates two nodes per registration: one in the global list, one in the entity's list.
// 62 callers — core entity lifecycle management.
//
// @param entity   Entity pointer to register
// @param categoryMask  Bitmask of categories (bit 0=list[0], etc.)
//                      Special: 0x80000000 = auto-detect from ResetSpawnPosition
void RegisterEntityInLists(void* entity, uint32_t categoryMask);  // FUN_005597d0

// ─── AllocListNode (FUN_005232c0) ──────────────────────────────
// Pool allocator for ListNode objects. Uses slab allocation with
// a free-list. Each slab = 0xC84 bytes = header + 198 blocks of 16 bytes.
// 52 callers — called from RegisterEntityInLists and related functions.
ListNode* AllocListNode();  // FUN_005232c0

} // namespace Giants
