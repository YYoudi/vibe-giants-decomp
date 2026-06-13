// Giants Engine - Pool Node Release
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── ReleasePoolNode (FUN_00523320) ── PASS ──
// Unlinks a node from a doubly-linked list and pushes it onto the
// free list (DAT_0074896c). Used by the entity pool allocator.
// 18 callers, 0 callees.
void ReleasePoolNode(int** listHead, int* node);  // FUN_00523320

} // namespace Giants
