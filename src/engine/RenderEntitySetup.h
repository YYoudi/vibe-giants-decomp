// Giants Engine - Render Entity Setup
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── SetupRenderEntity (FUN_0048f450) ── PASS ──
// Sets up entity for rendering. If param_2 != 0xFE, calls render dispatch
// for both the entity and a default (0xFE) fallback. 11 callers, 1 callee.
void SetupRenderEntity(uint32_t param_1, int entityIndex);  // FUN_0048f450
} // namespace Giants
