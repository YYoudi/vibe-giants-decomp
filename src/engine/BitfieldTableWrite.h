// Giants Engine - Bitfield Table Write
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── BitfieldTableWrite (FUN_0042b6a0) ── PASS ──
// Writes to memory-mapped table using bitfield index and shift.
// Used for flag/state tables. 7 callers, 0 callees.
void BitfieldTableWrite(uint32_t* table, uint32_t index, uint32_t value);  // FUN_0042b6a0
} // namespace Giants
