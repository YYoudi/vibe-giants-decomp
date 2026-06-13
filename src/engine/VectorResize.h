// Giants Engine - Vector Resize (FUN_0042b070)
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── VectorResize (FUN_0042b070) ── PASS ──
// Resizes std::vector to new count, zero-fills new elements.
// 9 callers, ~2 callees.
void VectorResize(int* vecHeader);  // FUN_0042b070
} // namespace Giants
