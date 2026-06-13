// Giants Engine - Sound Emitter Check
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── CheckSoundEmitter (FUN_005b0f00) ── PASS ──
// Checks entity sound emitter state. If flag 0x200 is set, uses alternate path.
// Checks entity type (0x47) and scene graph. 13 callers, 1 callee.
void CheckSoundEmitter(int entity);  // FUN_005b0f00
} // namespace Giants
