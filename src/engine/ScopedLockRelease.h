// Giants Engine - Scoped Lock Release
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── ScopedLockRelease (FUN_0043c520) ── PASS ──
// Releases a scoped lock/mutex. Calls FUN_0043d690 (bitvector op)
// twice for cleanup, then processes entries if count > 0.
// 16 callers, 3 callees.
void ScopedLockRelease(int* lockState);  // FUN_0043c520

} // namespace Giants
