// Giants Engine - Entity Sound Randomizer
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── EntitySoundRandomizer (FUN_005a1500) ── PASS ──
// Randomizes entity sound position: computes distance via FUN_006389d0,
// applies random offset, calls FUN_00638f10 for depth encoding.
// 3 callees, 6 callers.
void EntitySoundRandomizer(int param_1);  // FUN_005a1500
} // namespace Giants
