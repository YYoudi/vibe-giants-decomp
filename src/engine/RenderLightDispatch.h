// Giants Engine - Render Light Dispatch
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── RenderLightDispatch (FUN_00500b40) ── PASS ──
// Dispatches light rendering for scene objects. Iterates linked list of
// render nodes (DAT_007027ac), checks entity type and range, applies light.
// 14 callers, 2 callees.
void RenderLightDispatch(int param_1, int param_2, int param_3, uint32_t param_4,
                         float x, float y, float z, float intensity, float radius);  // FUN_00500b40
} // namespace Giants
