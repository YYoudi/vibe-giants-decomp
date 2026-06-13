// Giants Engine - Struct Field Accessor
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── GetStructField (FUN_0056cd80) ── PASS ──
// Retrieves a struct field pair (12 bytes: uint64 + uint32) from
// param_1 at offsets 0xf0 and 0xf8. Validates param_2 bounds.
// Calls FUN_005fac30 on out-of-bounds.
// 24 callers, 1 callee.
void GetStructField(int param_1, int param_2, uint64_t* outField);  // FUN_0056cd80

} // namespace Giants
