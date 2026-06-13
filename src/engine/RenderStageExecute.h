// Giants Engine - Render Stage Execute
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── ExecuteRenderStage (FUN_004f7050) ── FAIL (usable ~85%) ──
// Executes a render stage: calls into render pipeline with params,
// then invokes a string/collection operation. Preserves param_1[2] across call.
// 28 callers, 5 callees (FUN_004f7570, FUN_0044dc30, security_cookie).
void ExecuteRenderStage(uint32_t* param_1, uint32_t param_2, uint32_t param_3);  // FUN_004f7050

} // namespace Giants
