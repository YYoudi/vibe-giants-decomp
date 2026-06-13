// Giants Engine - Entity Sound Dispatch
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── EntitySoundDispatch (FUN_0048f710) ── PASS ──
// Dispatches sound effects for entity by iterating sound slots.
// Looks up sound data from entity array, computes pitch/volume,
// triggers playback via FUN_00483140. 6 callers, 1 callee.
int EntitySoundDispatch(int param_1, int param_2, int param_3);  // FUN_0048f710
} // namespace Giants
