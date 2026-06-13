// Giants Engine - Object Pool Allocator
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── AllocatePoolObject (FUN_00558730) ── PASS ──
// Pool-based object allocator for 0x48-byte nodes.
// Allocates from free list (or malloc(0x2D4) split into 8 nodes if empty),
// initializes fields from params, links into doubly-linked list,
// and optionally deduplicates by walking the list.
// 22 callers, 3 callees (malloc, memset, FUN_005584d0).
int AllocatePoolObject(int param_1, int param_2, int param_3,
                       int param_4, uint64_t* param_5, uint32_t param_6);  // FUN_00558730

} // namespace Giants
