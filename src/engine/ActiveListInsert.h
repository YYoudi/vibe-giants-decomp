// Giants Engine - Active List Node Insert
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── InsertActiveNode (FUN_00558730) ── FAIL (usable ~85%) ──
// Pool allocator + active list insertion. Allocates from free list
// (or creates block of 9 nodes), fills fields from params, inserts
// at tail of active linked list, checks for duplicates.
// 22 callers, 2 callees.
int InsertActiveNode(int p1, int p2, int p3, int p4, uint64_t* p5, uint32_t flags);  // FUN_00558730

} // namespace Giants
