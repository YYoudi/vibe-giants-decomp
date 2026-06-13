// Giants Engine - Integer to Wide Digit String
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── IntToWideDigit (FUN_004b8ed0) ── PASS ──
// Converts unsigned int to wide-char digits. Writes pairs of digits
// using lookup table at DAT_0065d910 (100 x 2-byte entries).
// Returns pointer range {end, write_pos}. 9 callers, 0 callees.
uint64_t IntToWideDigit(int buffer, uint32_t value, int offset);  // FUN_004b8ed0
} // namespace Giants
