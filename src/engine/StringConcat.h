// Giants Engine - String Concat (FUN_0043e5a0)
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── StringConcat (FUN_0043e5a0) ── PASS ──
// Concatenates two SSO strings. Handles inline/heap buffer transitions.
// 9 callers, ~2 callees.
void StringConcat(int* dest, uint32_t* src);  // FUN_0043e5a0
} // namespace Giants
