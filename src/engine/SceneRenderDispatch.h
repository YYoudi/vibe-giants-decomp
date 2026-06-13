// Giants Engine - Scene Render Dispatch
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── SceneRenderDispatch (FUN_004fbc80) ── PASS ──
// Dispatches scene rendering for current frame. Selects render path
// based on entity type and visibility. 7 callers, 0 callees.
void SceneRenderDispatch(uint32_t* sceneData, uint32_t flags);  // FUN_004fbc80
} // namespace Giants
