// Giants Engine - Vtable Callback Dispatch
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── VtableCallbackDispatch (FUN_00631f00) ── PASS ──
// Generic vtable dispatch: if callback at +0x10 exists, call it;
// otherwise call alternate at +0x28. Returns -1 on error.
// 16 callers, 0 callees.
uint32_t VtableCallbackDispatch(int obj, uint32_t p2, uint32_t p3, int p4, uint32_t p5);  // FUN_00631f00

} // namespace Giants
