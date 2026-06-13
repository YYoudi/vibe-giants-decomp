// Giants Engine - Type Info Lookup with Exception
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── LookupTypeInfoOrThrow (FUN_00603e80) ── PASS ──
// RTTI type_info lookup. If param_1[0] == 1, does direct vtable lookup
// via FUN_004318a0 and returns adjusted pointer. Otherwise constructs
// type_info object and throws via _CxxThrowException.
// 20 callers, 7 callees.
int LookupTypeInfoOrThrow(char* param_1);  // FUN_00603e80

} // namespace Giants
