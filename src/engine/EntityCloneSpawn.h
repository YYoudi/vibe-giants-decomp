// Giants Engine - Entity Clone/Spawn
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── CloneEntity (FUN_0055bce0) ── PASS ──
// Clones an entity by allocating a new one via FUN_00559dc0, copying
// key fields (origin 12B, flags, type), setting parent reference,
// and marking as spawned (flag 0x400000 at +0x124).
// Returns new entity ptr or 0 if allocation failed.
// 20 callers, 1 callee (FUN_00559dc0).
int CloneEntity(int srcEntity, uint32_t param2, uint32_t param3);  // FUN_0055bce0

} // namespace Giants
