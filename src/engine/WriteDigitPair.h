// Giants Engine - Write Digit Pair
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── WriteDigitPair (FUN_004f7270) ── PASS ──
// Writes two decimal digits (param_2 % 100) into a container using
// lookup table DAT_0065d910. 15 callers, 0 callees.
void WriteDigitPair(int obj, uint32_t value);  // FUN_004f7270
} // namespace Giants
