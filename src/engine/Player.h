// Giants Engine - Player Loading
// Reverse engineered from GiantsMain.exe v1.520.59
//
// FUN_00552990 — Default player initialization

#pragma once

#include <cstdint>

namespace Giants {

// ─── LoadDefaultPlayer (FUN_00552990) — FAIL (usable ~55%) ─────
// If in-game (state==6): uses current player data or resets.
// Otherwise: loads "intro_island" level via vtable dispatch.
// 5 callers, 6 callees.
// @return Result code from level load or player init
int LoadDefaultPlayer();    // FUN_00552990

// ─── GetPlayerName (FUN_0045f780) ── PASS ──
// Returns player name string for index (0-19). Falls back to
// "UnnamedPlayer N" if not set. 39 callers, 5 callees.
char* GetPlayerName(uint32_t playerIndex);  // FUN_0045f780

} // namespace Giants
