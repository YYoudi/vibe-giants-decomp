// Giants Engine - Exception List Build (CRT exception chain)
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── ExceptionListBuild (FUN_00441910) ── PASS ──
// Builds/extends exception handler list with SSO string nodes.
// Manages linked list of exception entries with ref counting,
// heap allocation and CRT validation. Uses security cookie.
// 10 callers, ~5 callees.
uint32_t* ExceptionListBuild(uint32_t* param_1, uint32_t param_2, uint32_t param_3);  // FUN_00441910
} // namespace Giants
