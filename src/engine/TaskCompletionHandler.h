// Giants Engine - Task Completion Handler (ConCRT PPL)
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── TaskCompletionHandler (FUN_0061d450) ── FAIL (usable ~75%) ──
// Concurrency Runtime task completion: processes completed task,
// handles scheduler context callbacks, manages ref counting on
// task shared state, invokes continuation. Uses security cookie.
// 11 callers, ~5 callees.
int* TaskCompletionHandler(int* param_1, uint32_t* param_2, uint32_t param_3, uint32_t* param_4);  // FUN_0061d450
} // namespace Giants
