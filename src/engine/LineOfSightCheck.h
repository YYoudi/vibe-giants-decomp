// Giants Engine - Line Of Sight Check
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── LineOfSightCheck (FUN_0055ee40) ── PASS ──
// Checks line-of-sight between two world positions. Uses grid coords
// from DAT_00702770+0x23C..0x244 for scaling. 1 callee, 5 callers.
bool LineOfSightCheck(float* param_1, float* param_2);  // FUN_0055ee40
} // namespace Giants
