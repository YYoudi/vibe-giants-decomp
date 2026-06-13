// Giants Engine - Color Packing (Float → ARGB uint32)
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── PackColorToARGB (FUN_00472920) ── PASS ──
// Packs a float[4] {R,G,B,A} into a uint32 ARGB color.
// Each channel is clamped to [0.0, 1.0], scaled to [0, 255],
// then packed as 0xAARRGGBB. 34 callers, 0 callees.
uint32_t PackColorToARGB(const float* rgba);  // FUN_00472920

} // namespace Giants
