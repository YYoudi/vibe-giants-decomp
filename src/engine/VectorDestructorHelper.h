// Giants Engine - Vector Destructor Helper (FUN_0043f590)
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── VectorDestructorHelper (FUN_0043f590) ── PASS ──
// Calls destructor on each vector element then frees buffer.
// 9 callers, ~1 callee.
void VectorDestructorHelper(int* vecHeader);  // FUN_0043f590
} // namespace Giants
