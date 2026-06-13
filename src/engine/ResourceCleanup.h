// Giants Engine - Game Resource Cleanup
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── ResetGameResources (FUN_00541080) ── PASS ──
// Full game resource cleanup: frees render buffers, iterates entity
// linked lists to release objects and apply flag changes, conditionally
// calls cleanup function, and partially resets game state while
// preserving specific memory fields (mem/size pairs).
// 34 callers, 5 callees.
void ResetGameResources();  // FUN_00541080

} // namespace Giants
