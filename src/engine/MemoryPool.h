// Giants Engine - SIMD Memory Pool Allocator
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── AllocateFreeBlock (FUN_0048ef70) ── PASS ──
// Allocates a 40-byte block from a free-list pool with SIMD-optimized
// initialization. Pool blocks are 0x1F44 bytes (198 slots of 10 ints).
// Supports SSE2 SIMD path for faster free-list chain building.
// 34 callers, 3 callees.
uint32_t* AllocateFreeBlock();  // FUN_0048ef70

} // namespace Giants
