// Giants Engine - Bitvector Shift Left
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── BitvectorShiftLeft (FUN_00448fd0) ── PASS ──
// Shifts bitvector left by param_2 bits with carry propagation across words.
// param_1 = pointer to bitvector array, param_2 = shift amount.
// 10 callers, 0 callees (self-contained).
void BitvectorShiftLeft(uint32_t* bitvector, int shiftBits);  // FUN_00448fd0
} // namespace Giants
