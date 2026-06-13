// Giants Engine - Syntax Error Message Builder
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── BuildSyntaxErrorMsg (FUN_00434a80) ── FAIL (usable ~75%) ──
// Builds syntax error message strings. Very similar to BuildParseError (FUN_0060ab30)
// but with different error type strings and context. Uses MSVC SSO string ops.
// 18 callers, ~12 callees.
char* BuildSyntaxErrorMsg(int param1, char* param2, int param3, uint32_t* param4);  // FUN_00434a80

} // namespace Giants
