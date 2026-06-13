// Giants Engine - Player Name Management
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── GetPlayerName (FUN_0045f780) ── PASS ──
// Returns player name string by index (0-19). Checks cached name
// in global table, fetches from network if needed, falls back to
// localized "Unnamed Player" string. 39 callers, 5 callees.
char* GetPlayerName(uint32_t playerIndex);  // FUN_0045f780

} // namespace Giants
