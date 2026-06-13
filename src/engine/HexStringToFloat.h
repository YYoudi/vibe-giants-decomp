// Giants Engine - Hex String to Float
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── HexStringToFloat (FUN_004532b0) ── PASS ──
// Parses a hex color string (optionally "0x" prefixed) into a float.
// Accepts up to 20 hex digits, builds mantissa, normalizes with pow(16, -digitCount).
// 15 callers, 2 callees (tolower, pow).
float HexStringToFloat(const char* hexStr);  // FUN_004532b0

} // namespace Giants
