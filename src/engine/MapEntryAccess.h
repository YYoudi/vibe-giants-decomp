// Giants Engine - Map/Container Entry Access
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── MapEntryAccess (FUN_004b7490) ── PASS ──
// Retrieves a 16-byte entry from a map/container by index.
// Handles tree traversal for negative depths, direct array access otherwise.
// 16 callers, 1 callee.
uint32_t* MapEntryAccess(int* container, uint32_t* output, int index);  // FUN_004b7490

} // namespace Giants
