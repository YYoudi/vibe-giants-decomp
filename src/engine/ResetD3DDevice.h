// Giants Engine - D3D Device Reset
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── ResetD3DDevice (FUN_0045efd0) ── FAIL (usable ~75%) ──
// Resets Direct3D device with present parameters. Checks adapter count,
// gets container caps, builds present params, calls Reset.
// 20 callers, ~5 callees.
void ResetD3DDevice();  // FUN_0045efd0

} // namespace Giants
