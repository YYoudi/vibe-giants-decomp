// Giants Engine - Active Index Setter
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── SetActiveIndex (FUN_00541690) ── PASS ──
// Sets the active selection index with bounds clamping.
// Updates an internal 3-int-per-entry active array, triggers
// callback if flags allow, and computes scaled values from
// a table entry at the new index.
// 26 callers, 1 callee (FUN_00558360).
void SetActiveIndex(int index);  // FUN_00541690

} // namespace Giants
