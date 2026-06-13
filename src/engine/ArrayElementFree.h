// Giants Engine - Array Element Free
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── ArrayElementFree (FUN_00485e40) ── PASS ──
// Walks array, frees elements via vtable or free_exref.
// Checks param_1[0] for current index, param_1[2] for count. 1 callee, 5 callers.
void ArrayElementFree(int* param_1);  // FUN_00485e40
} // namespace Giants
