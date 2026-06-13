// Giants Engine - Setup Model Transform (render pipeline)
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── SetupModelTransform (FUN_00570390) ── PASS ──
// Sets up model transform matrix for rendering: copies 17 uint32 values
// from param3 to entity matrix (+0x2e4..+0x324), computes scale factors
// from XOR'd diagonal, updates model matrix cache, validates render targets.
// 15 callers, ~7 callees.
int SetupModelTransform(uint32_t param1, uint32_t param2, uint32_t* param3, uint32_t param4);  // FUN_00570390

} // namespace Giants
