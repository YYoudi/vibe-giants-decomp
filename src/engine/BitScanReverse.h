// Giants Engine - Bit Scan Reverse
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── BitScanReverse (FUN_004b7c50) ── PASS ──
// Finds position of highest set bit in param_4, then extracts bits
// from param_3 with shift. Returns 64-bit result.
// 10 callers, 0 callees (self-contained).
uint64_t BitScanReverse(int param_1, int param_2, uint32_t param_3, uint32_t param_4);  // FUN_004b7c50
} // namespace Giants
