// Giants Engine - Linked List Cleanup
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── LinkedListCleanup (FUN_0043e350) ── PASS ──
// Destroys a linked list of 0x38-byte nodes. Walks list, calls vtable[4]
// dtor on each node's sub-object, frees nodes via CRTFree. 6 callers, 1 callee.
void LinkedListCleanup(int* head);  // FUN_0043e350
} // namespace Giants
