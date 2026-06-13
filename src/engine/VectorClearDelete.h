// Giants Engine - Vector Clear & Delete, Vector Clear
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── ClearAndDeleteElements (FUN_0042c810) ── PASS ──
// Clears a vector<IUnknown*>: calls scalar deleting destructor on
// each non-null element via vtable[0], then frees the buffer.
// 21 callers, 2 callees.
void ClearAndDeleteElements(int* vecObj);  // FUN_0042c810

// ─── VectorClear (FUN_00430380) ── PASS ──
// Frees vector buffer (handles MSVC debug heap header) and resets
// _Myfirst/_Mylast/_Myend to null. Trivial.
// 21 callers, 1 callee.
void VectorClear(int* vecObj);  // FUN_00430380

} // namespace Giants
