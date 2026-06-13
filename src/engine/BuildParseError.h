// Giants Engine - JSON Parse Error Builder
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── BuildParseError (FUN_0060ab30) ── FAIL (usable ~75%) ──
// Builds a syntax error message string for JSON parsing errors.
// Concatenates "while parsing " context, error type, and optional
// "; expected " suffix. Uses MSVC SSO string layout throughout.
// 18 callers, ~12 callees.
char* BuildParseError(int param1, char* param2, int param3, uint32_t* param4);  // FUN_0060ab30

} // namespace Giants
