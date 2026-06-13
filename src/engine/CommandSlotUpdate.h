// Giants Engine - Command Slot Update
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── UpdateCommandSlot (FUN_004641b0) ── PASS ──
// Updates a command/action slot. Searches DAT_006ff910 array for
// DAT_0073c940 value, updates DAT_00702924 and slot array DAT_006ff8fc.
// If replay mode (DAT_006ff960==6), writes to replay buffer.
// 16 callers, 4 callees.
void UpdateCommandSlot(int commandId);  // FUN_004641b0

} // namespace Giants
