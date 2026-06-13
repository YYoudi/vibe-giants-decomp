// Giants Engine - Matrix Transform Dispatch
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── MatrixTransformDispatch (FUN_0063a030) ── PASS ──
// Applies transform based on bitfield in param_4. Dispatches to different
// matrix operations (translate, rotate, scale) based on flag bits.
// 11 callers, 0 callees (self-contained).
void MatrixTransformDispatch(uint32_t* out, uint32_t* in, int param_3, uint32_t* flags);  // FUN_0063a030
} // namespace Giants
