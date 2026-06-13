// Giants Engine - Network Joiner Command
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── SendJoinerCommand (FUN_0045e0a0) ── PASS ──
// Network command handler for joiner state changes.
// Sends "CommChgJoinersYes" or "CommChgJoinersNo" based on DAT_00702938.
// 15 callers, 5 callees.
void SendJoinerCommand();  // FUN_0045e0a0

} // namespace Giants
