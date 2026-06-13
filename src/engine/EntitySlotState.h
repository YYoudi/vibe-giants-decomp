// Giants Engine - Entity Slot State Check
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── CheckEntitySlotState (FUN_004a6650) ── PASS ──
// Checks if entity at slot param_2 of param_1's entity table
// is in a terminal state. Examines entity type (+0x22c) to determine
// comparison mode (0x20, 0x4a, 0x52, 0x53), then compares scale values.
// Returns true if entity scale matches reference (terminal state).
// 19 callers, 2 callees (FUN_00497350, FUN_00580930).
bool CheckEntitySlotState(int container, int slotIndex);  // FUN_004a6650

} // namespace Giants
