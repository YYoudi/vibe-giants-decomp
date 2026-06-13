// Giants Engine - Entity Render Position Calc
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── EntityRenderPosition (FUN_005671a0) ── PASS ──
// Computes entity render position from scale/offset. Reads entity height
// at +0x370, scale at +0x238, checks flags at +0x150. Calls FUN_0063ed60
// for transform and FUN_0063f300 for position. 4 callees, 6 callers.
void EntityRenderPosition(uint32_t param_1, int param_2);  // FUN_005671a0
} // namespace Giants
