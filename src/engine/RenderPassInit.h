// Giants Engine - Render Pass Init
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── RenderPassInit (FUN_004f9610) ── PASS ──
// Initializes render pass from bit flags. Sets up to 32 render targets
// from param_1 bits, stores in DAT_00748770/78. 1 callee, 5 callers.
void RenderPassInit(uint32_t param_1, uint32_t param_2);  // FUN_004f9610
} // namespace Giants
