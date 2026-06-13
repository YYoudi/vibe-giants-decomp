// Giants Engine - Element Lookup by ID
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── FindElementById (FUN_0056e960) ── FAIL (usable ~90%) ──
// Searches global element list for an element matching targetId.
// In game state 6, prefers flagged elements but falls back to unflagged.
// In other states, prefers unflagged elements.
// 35 callers, 0 callees.
struct Element;
Element* FindElementById(int targetId);  // FUN_0056e960

} // namespace Giants
