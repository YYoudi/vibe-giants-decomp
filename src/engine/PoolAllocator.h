// Giants Engine - Pool Allocator
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── AllocateNode (FUN_0048ef70) ── FAIL (usable ~90%) ──
// Pool allocator for fixed-size nodes (0x1F44 bytes each).
// Maintains a free list at DAT_0073e790. When empty, allocates a
// new block and initializes nodes using SSE2 pmulld for index calc.
// Uses config at DAT_0066c380..DAT_0066c3d0 for SSE grid layout.
// DAT_006fd52c >= 2 enables SSE initialization path.
// 34 callers, 1 callee (malloc).
int* AllocateNode();  // FUN_0048ef70

} // namespace Giants
