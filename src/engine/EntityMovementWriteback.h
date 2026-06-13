// Giants Engine - Entity Movement Writeback
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── WriteEntityMovement (FUN_00565f40) ── PASS ──
// Integrates entity movement: applies velocity with max speed clamp,
// normalizes direction, updates world position (+0xf0..+0xf8),
// saves prev position (+0x180..+0x188), and writes final state
// to the entity grid.
// 19 callers, 3 callees (FUN_0062a0b0, FUN_0042bee0, FUN_0042bc40).
void WriteEntityMovement(int entity);  // FUN_00565f40

} // namespace Giants
