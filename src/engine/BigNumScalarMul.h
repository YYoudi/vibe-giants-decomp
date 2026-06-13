// Giants Engine - Big Number Scalar Multiply
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── BigNumScalarMul (FUN_00449150) ── PASS ──
// Multiplies big number (param_1) by scalar (param_2) with carry propagation.
// BigNum layout: param_1[0]=vtable, [1]=data, [2]=size, [3]=capacity.
// 9 callers, 0 callees (self-contained).
uint32_t* BigNumScalarMul(uint32_t* param_1, uint32_t param_2);  // FUN_00449150
} // namespace Giants
