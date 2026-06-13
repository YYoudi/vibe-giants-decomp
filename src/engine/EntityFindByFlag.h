// Giants Engine - Entity Find By Flag
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── EntityFindByFlag (FUN_00463850) ── PASS ──
// Walks entity linked list from DAT_007027a8, finds entity with flag bit 0x214 & 1
// set and matching byte at offset 0x1d4. 6 callers, 0 callees.
int EntityFindByFlag(uint32_t entityType);  // FUN_00463850
} // namespace Giants
