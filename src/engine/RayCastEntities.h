// Giants Engine - Ray Cast Entities
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── RayCastEntities (FUN_004ff8b0) ── PASS ──
// Performs ray cast against entity list, calls callback for each hit.
// Traverses entity tree, computes ray-AABB intersection, dispatches
// hit results via callback. 10 callers, ~4 callees.
int RayCastEntities(void* callback, uint32_t callbackData, void* param_3, int param_4);  // FUN_004ff8b0
} // namespace Giants
