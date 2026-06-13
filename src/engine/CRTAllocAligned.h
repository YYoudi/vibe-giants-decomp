// Giants Engine - CRT Alloc Aligned
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── CRTAllocAligned (FUN_006400e0) ── PASS ──
// CRT aligned allocation: calls allocator at DAT_006fd0a8, aligns to 16 bytes.
// Stores original offset in header for free. 6 callers, 0 callees.
uint32_t CRTAllocAligned(int size);  // FUN_006400e0
} // namespace Giants
