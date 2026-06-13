// Giants Engine - Mesh Hit Test
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── ProcessMeshHitTest (FUN_005de120) ── PASS ──
// Performs hit testing on a mesh: iterates mesh items, clears visibility
// flags, then tests each item using either AABB bounds or per-triangle
// point-in-triangle test with cross products. Calls optional callback
// on hit. Returns the index of the hit item or -1 if no hit.
// 24 callers, 0 callees (callback via item->callback).
int ProcessMeshHitTest(int mesh, int meshIndex);  // FUN_005de120

} // namespace Giants
