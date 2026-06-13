// Giants Engine - Container Emplace 0x48
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── EmplaceContainer48 (FUN_00568df0) ── PASS ──
// Emplaces a zero-initialized 0x48-byte entry into a container.
// If space available (end != capacity), zero-fills and advances pointer.
// Otherwise, calls grow helper FUN_00568ec0 to reallocate.
// 17 callers, 2 callees (FUN_0042b0f0, FUN_00568ec0).
void EmplaceContainer48(int container, uint32_t param_2);  // FUN_00568df0

} // namespace Giants
