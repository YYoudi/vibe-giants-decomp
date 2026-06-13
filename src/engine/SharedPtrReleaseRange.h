// Giants Engine - Shared Pointer Release Range
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── SharedPtrReleaseRange (FUN_0044f870) ── PASS ──
// Iterates [param_1, param_2) with 8-byte stride. For each entry,
// if the shared ptr at +4 is non-null, decrements refcount (LOCK),
// calls vtable[0] destructor when refcount=0, decrements weak ref,
// calls vtable[1] deallocator when weak ref=0.
// 9 callers, 0 callees (self-contained).
void SharedPtrReleaseRange(int param_1, int param_2);  // FUN_0044f870
} // namespace Giants
