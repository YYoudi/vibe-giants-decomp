// Giants Engine - Bit Field Extract
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── BitFieldExtract (FUN_00470690) ── PASS ──
// Extracts a bit field from uint32 at given offset and width.
// 7 callers, 0 callees (self-contained).
uint32_t BitFieldExtract(uint32_t value, uint8_t offset, uint8_t width);  // FUN_00470690
} // namespace Giants
