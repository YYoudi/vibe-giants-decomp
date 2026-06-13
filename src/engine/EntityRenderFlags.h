// Giants Engine - Entity Render Flags
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── EntityRenderFlags (FUN_00559670) ── PASS ──
// Computes render flags from entity state. Checks flag bits at +0x214,
// +0x124, and dispatches on entity type (+0x22c) to set additional bits.
// 9 callers, 0 callees (self-contained).
uint32_t EntityRenderFlags(int entityPtr);  // FUN_00559670
} // namespace Giants
