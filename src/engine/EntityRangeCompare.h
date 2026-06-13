// Giants Engine - Entity Range Compare
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── EntityRangeCompare (FUN_004aaa20) ── PASS ──
// Compares two entities for range/distance sorting. Returns comparison result.
// Used in entity render sorting. 7 callers, 0 callees (self-contained).
int EntityRangeCompare(float* entity1, float* entity2);  // FUN_004aaa20
} // namespace Giants
