// Giants Engine - Animation Frame Delta
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── ComputeAnimFrameDelta (FUN_0047dc00) ── FAIL (usable ~90%) ──
// Computes the current animation frame delta based on mode:
//   Mode 0: Clamp — clamp to [0, frameCount-1]
//   Mode 1: Loop — wrap around via modulo
//   Mode 2: Oscillate — ping-pong between start and end
//   Mode 3: Reverse — clamp in reverse direction
//   Mode 4: Alt-loop — alternate loop direction
// Returns the computed frame delta as float.
// 35 callers, 2 callees.
float ComputeAnimFrameDelta(float currentTime, float frameCount, uint32_t mode);  // FUN_0047dc00

} // namespace Giants
