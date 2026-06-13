// Giants Engine - Shader / Render State Constant Helpers
// Reverse engineered from GiantsMain.exe v1.520.59
//
// Thin wrappers around CRT math (sin/cos) and the renderer COM vtable
// for uploading shader float constants.  These are called from the
// projection setup and error-handler rendering paths.

#pragma once

#include <cstdint>

namespace Giants {

// ─── ComputeCos (FUN_00483140) — PASS ────────────────────────────
// Trivial wrapper: calls libm_sse2_cos_precise (SSE2 cos).
// 18 callers, 1 callee.  Used by SetupProjection and wave math.
//
// Ghidra decompiles this as a tail-call to the SSE2 cos implementation.
// The function takes its argument in XMM0 and returns in ST(0)/XMM0.
double ComputeCos(double angle);          // FUN_00483140

// ─── ComputeSin (FUN_00483160) — PASS ────────────────────────────
// Trivial wrapper: calls libm_sse2_sin_precise (SSE2 sin).
// 15 callers, 1 callee.  Used by SetupProjection and wave math.
//
// Same calling convention as ComputeCos.
double ComputeSin(double angle);          // FUN_00483160

// ─── SetShaderFloatConstant (FUN_004da6d0) — PASS (usable ~90%) ──
// Uploads a 7-element shader constant block via the renderer vtable.
// The constant data is a grid of 7 floats arranged as:
//
//   Layout (indices into the allocated constant buffer):
//     [0]  = playerScaleX * param1
//     [1]  = playerScaleY * param3
//     [4]  = param1
//     [7]  = playerScaleX * param2
//     [8]  = playerScaleY * param3
//     [11] = param1
//     [14] = playerScaleX * param2
//     [15] = playerScaleY * param2
//     [18] = param1
//     [22] = playerScaleY * param2
//
// Where:
//   param1, param2, param3 are function parameters (floats via XMM registers)
//   DAT_007028a0 = player scale X
//   DAT_007028a4 = player scale Y
//
// This function is called 7 times by ShowErrorDialog (FUN_0062edc0) to set
// the error screen background colors/positions as shader constants.
//
// @param param_1  (XMM1)  — first float constant value
// @param param_2  (XMM2)  — second float constant value
// @param param_3  (XMM3)  — third float constant value
void SetShaderFloatConstant(float param_1, float param_2, float param_3);  // FUN_004da6d0

} // namespace Giants
