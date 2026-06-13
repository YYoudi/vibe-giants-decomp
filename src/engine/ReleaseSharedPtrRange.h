// Giants Engine - Shared Pointer Range Release
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── ReleaseSharedPtrRange (FUN_0042b650) ── PASS ──
// Iterates [begin, end) with 8-byte stride, releasing COM refcounted
// objects. Decrements strong ref (LOCK), calls dtor if zero,
// decrements weak ref, calls dealloc if zero. 13 callers, 0 callees.
void ReleaseSharedPtrRange(int begin, int end);  // FUN_0042b650
} // namespace Giants
