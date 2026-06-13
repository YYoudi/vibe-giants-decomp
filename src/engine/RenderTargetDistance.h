// Giants Engine - Render Target Distance
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── RenderTargetDistance (FUN_00500940) ── PASS ──
// Computes directional vector from entity param_2 to target param_3/param_4.
// If entity type in range [0x33..0x47], uses entity position +0xF0.
// Otherwise uses delta between +0xF0 and +0xFC. 3 callees, 6 callers.
void RenderTargetDistance(int type, int entity, int target, float* outPos);  // FUN_00500940
} // namespace Giants
