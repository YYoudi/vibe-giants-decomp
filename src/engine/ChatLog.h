// Giants Engine - Chat Log System
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── AddChatLogEntry (FUN_00453520) ── PASS ──
// Adds a message to the circular chat log buffer (25 entries × 256 bytes).
// Writes to chatlog.txt file if enabled. When buffer is full, shifts
// entries up and uses last slot. Stores color + timestamp metadata.
// 31 callers, 9 callees.
void AddChatLogEntry(const char* message, uint32_t timestamp);  // FUN_00453520

} // namespace Giants
