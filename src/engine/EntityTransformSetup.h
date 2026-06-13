// Giants Engine - Entity Transform Matrix Setup
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── EntityTransformSetup (FUN_00566c70) ── PASS ──
// Sets up entity transform matrix from position/rotation data. Reads
// entity state at +0x278, +0x150 (flags), builds transform from
// +0x2E4..+0x324 and +0x2F4..+0x304 matrix rows. 5 callees, 6 callers.
void EntityTransformSetup(int param_1, int param_2);  // FUN_00566c70
} // namespace Giants
