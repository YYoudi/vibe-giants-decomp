// Giants Engine - Shader Param Dispatch
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── DispatchShaderParam (FUN_005daac0) ── PASS ──
// Dispatches shader parameter setup based on render mode index.
// Reads shader data from param_2, computes transform/UV params.
// 11 callers, 4 callees.
uint32_t DispatchShaderParam(int param_1, uint32_t* param_2, int param_3, int param_4);  // FUN_005daac0
} // namespace Giants
