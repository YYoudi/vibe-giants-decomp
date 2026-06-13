// Giants Engine - COM Object Release
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── ComObjectRelease (FUN_004ad590) ── PASS ──
// COM IUnknown::Release pattern: decrements strong ref, calls
// destructor if zero, then decrements weak ref and frees if zero.
// Uses LOCK/UNLOCK for thread safety.
// 16 callers, 0 callees (uses inline vtable calls).
void ComObjectRelease(int* obj);  // FUN_004ad590

} // namespace Giants
