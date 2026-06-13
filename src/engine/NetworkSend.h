// Giants Engine - Network Message Send
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── SendNetworkMessage (FUN_00463750) ── PASS ──
// Sends a network message packet. Looks up target in DAT_006ff910[],
// builds message header with player index, flags, and string payload.
// Only active when game state == 6. 32 callers, 5 callees.
void SendNetworkMessage(char* text, uint32_t flags, uint8_t param3);  // FUN_00463750

} // namespace Giants
