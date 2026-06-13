// Giants Engine - Effect Resource Reset
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── ResetEffectResources (FUN_0058a270) ── PASS ──
// Resets effect resources by looking up effectId in a static table,
// cleaning up existing resources at offsets 0xfc0/0xfc4, and
// optionally creating new resources via factory.
// 24 callers, 3 callees.
void ResetEffectResources(int* context, int effectId);  // FUN_0058a270

} // namespace Giants
