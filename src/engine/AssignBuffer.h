// Giants Engine - Assign Buffer (vector pointer update)
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── AssignBuffer (FUN_00443710) ── PASS ──
// Updates vector internal pointers (_Myfirst, _Mylast, _Myend) after
// reallocation. 9 callers, 0 callees (trivial).
void AssignBuffer(int* vecHeader, int param_2, int param_3, int param_4);  // FUN_00443710
} // namespace Giants
