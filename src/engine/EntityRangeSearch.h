// Giants Engine - Entity Range Search
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── SearchEntityRange (FUN_004d3ab0) ── PASS ──
// Searches entity linked list for entity matching range criteria.
// Checks visibility flags, time range, and position bounds.
// Returns matching entity or 0. 11 callers, 0 callees (self-contained).
int SearchEntityRange(uint32_t* listHead);  // FUN_004d3ab0
} // namespace Giants
