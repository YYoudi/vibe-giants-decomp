// Giants Engine - Vector Push Back
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── VectorPushBack (FUN_004cfbe0) ── PASS ──
// MSVC std::vector::push_back. If capacity available, moves element
// and increments _Mylast. Otherwise calls grow via FUN_0042c4e0.
// 22 callers, 1 callee.
void VectorPushBack(int* vecObj, uint32_t* element);  // FUN_004cfbe0

} // namespace Giants
