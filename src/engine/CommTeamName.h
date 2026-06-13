// Giants Engine - Comm Team Name Builder
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── BuildCommTeamName (FUN_0045f4c0) ── FAIL (usable ~80%) ──
// Builds comm team name string: "CommTeamSpectator" for param 0x7F,
// or "CommTeamNo{N}" / "CommTeamNo{N}A" based on team number.
// TLS init pattern, SSO string ops, hash lookup.
// 17 callers, ~8 callees.
void* BuildCommTeamName(int param1);  // FUN_0045f4c0

} // namespace Giants
