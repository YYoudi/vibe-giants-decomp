// Giants Engine - Task Create Dispatch
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── TaskCreateDispatch (FUN_00461d00) ── PASS ──
// Concurrency Runtime task creation: allocates task via vtable dispatch,
// initializes fields, handles COM refcounting on result.
// 8 callers, 0 callees (self-contained).
int* TaskCreateDispatch(uint32_t param_1);  // FUN_00461d00
} // namespace Giants
