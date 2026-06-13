// Giants Engine - Network Message Dispatch
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── SendIndexedMessage (FUN_00463750) ── FAIL (usable ~85%) ──
// Formats and sends a network message with index lookup.
// Searches entry array for target, builds header packet with
// index encoding (OR 0x80), then dispatches via FUN_00463430.
// 32 callers, 5 callees.
void SendIndexedMessage(const char* message, uint32_t param_2, uint8_t param_3);  // FUN_00463750

} // namespace Giants
