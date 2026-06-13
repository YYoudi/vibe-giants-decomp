// Giants Engine - Entity Pool Cleanup
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── CleanupEntityPool (FUN_0048d780) ── PASS ──
// Frees all entities in a linked list pool. Walks list at entity+0x1b4,
// adds each node to free list (DAT_0073e790), clears flag bit 24.
// 11 callers, 1 callee.
void CleanupEntityPool(int entity, uint64_t* param_2);  // FUN_0048d780
} // namespace Giants
