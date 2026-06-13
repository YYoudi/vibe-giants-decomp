// Giants Engine - Render Material State
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── RenderMaterialState (FUN_005d7de0) ── PASS ──
// Sets up material/render state for a draw call: resolves texture,
// computes lighting colors, builds vertex buffer, submits to GPU.
// Uses vtable calls through renderer interface pointers.
// 26 callers, ~10 callees.
void RenderMaterialState(int param_1, int param_2);  // FUN_005d7de0

} // namespace Giants
