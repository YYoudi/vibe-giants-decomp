// Giants Engine - Escape String with SSO
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── EscapeString (FUN_0060a930) ── PASS ──
// Escapes a byte range [param_1+0x38, param_1+0x3c) into an SSO string.
// Control chars (<0x20) formatted as "<U+XXXX>", printable chars copied.
// Full SSO grow/reallocation support.
// 23 callers, 6 callees.
uint32_t* EscapeString(int param_1, uint32_t* outStr);  // FUN_0060a930

} // namespace Giants
