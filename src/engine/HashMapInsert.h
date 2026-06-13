// Giants Engine - HashMap Insert (Linked List Bucket)
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── HashMapInsert (FUN_004d5150) ── PASS ──
// Inserts a key-value pair into a linked-list-based hashmap.
// Traverses linked list at *param_1 looking for param_2 key match.
// If found, appends a new node to the tail of the node list at entry[10].
// Node contains: next ptr, value (param_4), flags, string key (param_3).
// Sets flag 0x200 on the entry after insertion.
// 22 callers, 1 callee (malloc).
void HashMapInsert(int* root, int key, const char* strValue, uint32_t value);  // FUN_004d5150

} // namespace Giants
