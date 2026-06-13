// Giants Engine - Hash Table Clear
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── HashTableClear (FUN_0043e270) ── PASS ──
// Clears 13-slot hash table entries. For each non-null slot, calls
// vtable[1] (destructor) then zeroes the entry.
// param_1 = pointer to hash table struct. 10 callers, 0 callees.
void HashTableClear(int hashTablePtr);  // FUN_0043e270
} // namespace Giants
