// Giants Engine - Texture Hash Compute
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── TextureHashCompute (FUN_004f7910) ── PASS ──
// Computes texture hash from parameters using multiply-shift hashing.
// Uses magic constant 0xCD for distribution. 8 callers, 0 callees.
void TextureHashCompute(uint32_t* param_1, uint32_t param_2,
                        int param_3, int param_4, char param_5);  // FUN_004f7910
} // namespace Giants
