// Giants Engine - Replay Sync Marker
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── WriteReplaySyncMarker (FUN_00464aa0) ── PASS ──
// Writes a replay sync marker (type 0x3B) when in replay mode.
// Only active when DAT_006ff960 == 6. 11 callers, 2 callees.
void WriteReplaySyncMarker();  // FUN_00464aa0
} // namespace Giants
