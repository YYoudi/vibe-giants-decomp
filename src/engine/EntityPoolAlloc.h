// Giants Engine - Entity Pool Allocator
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── EntityPoolAlloc (FUN_00498720) ── PASS ──
// Allocates a 0x48-byte entity from pool (DAT_007027f4 linked list).
// If free list (DAT_007027f8) available, reuse; otherwise walk to tail.
// Initializes entity fields with DAT_007028f4 context. 3 callees, 6 callers.
void EntityPoolAlloc(uint32_t param_1, int param_2);  // FUN_00498720
} // namespace Giants
