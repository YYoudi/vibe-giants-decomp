// Giants Engine - String Copy SSO
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── StringCopySSO (FUN_005e8ea0) ── PASS ──
// Copies N elements from source string/vector to destination with SSO check.
// If source capacity > 15, uses heap pointer; otherwise inline data.
// 14 callers, 1 callee.
int* StringCopySSO(int* dest, uint32_t* src, int param3, int param4, int param5, uint32_t count, uint32_t capacity);  // FUN_005e8ea0
} // namespace Giants
