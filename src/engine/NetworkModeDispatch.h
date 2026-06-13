// Giants Engine - Network Mode Dispatch (complex game state machine)
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── NetworkModeDispatch (FUN_00504a20) ── FAIL (usable ~70%) ──
// Very complex network game mode state machine. 819 lines of decompiled
// code with mode transitions, entity spawning, network sync, UI updates.
// 10 callers, many callees.
void NetworkModeDispatch();  // FUN_00504a20
} // namespace Giants
