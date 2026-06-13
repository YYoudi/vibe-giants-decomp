// Giants Engine - SSO String Move Init
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── StringMoveFromCStr (FUN_0043fe80) ── PASS ──
// Initializes an SSO std::string (24 bytes) from a C-string param_2.
// Measures string length, calls FUN_0043fcf0 to allocate/copy into a temp,
// then moves the 24-byte SSO data to param_1 and resets the source.
// 18 callers, 1 callee (FUN_0043fcf0).
uint32_t* StringMoveFromCStr(uint32_t* dest, const char* src);  // FUN_0043fe80

} // namespace Giants
