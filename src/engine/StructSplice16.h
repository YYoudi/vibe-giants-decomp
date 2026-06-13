// Giants Engine - 16-byte Struct Splice
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── SpliceStruct16 (FUN_004436c0) ── PASS ──
// Moves 16-byte struct entries from [param_1, param_2) to param_3,
// then zeros the source entries. Returns pointer past last written dest.
// Used for std::vector-style extract operations.
// 18 callers, 0 callees.
uint8_t* SpliceStruct16(uint8_t* begin, uint8_t* end, uint8_t* dest);  // FUN_004436c0

} // namespace Giants
