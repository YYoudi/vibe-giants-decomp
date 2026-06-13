// Giants Engine - State Machine SetState + Signal (ConCRT)
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── SetStateAndSignal (FUN_00613650) ── FAIL (usable ~80%) ──
// ConCRT state machine: sets state at +0xD0, locks primary mutex (+0x14),
// checks counters at +0x40 and +0xA4 for INT_MAX deadlock, broadcasts
// condition variable at +0x50, signals via secondary mutex at +0x78.
// 12 callers, ~4 callees.
void SetStateAndSignal(void* obj, uint8_t newState);  // FUN_00613650

} // namespace Giants
