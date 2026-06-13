// Giants Engine - Async Result Init
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── AsyncResultInit (FUN_0061b6e0) ── PASS ──
// Initializes async result/concurrency state object. Sets vtable, zeros fields,
// manages COM-style refcounting on param_4. 6 callers, 0 callees.
uint32_t* AsyncResultInit(uint32_t* param_1, int param_2, uint32_t param_3,
                          int* param_4, uint32_t param_5);  // FUN_0061b6e0
} // namespace Giants
