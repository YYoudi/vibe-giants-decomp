#pragma once
// Giants Engine - Shader Constants & Math Helpers
// Reverse engineered from FUN_00483140, FUN_00483160, FUN_0061f8f0

#include <cstdint>

namespace Giants {

// ─── ComputeCos / EndShaderBlock (FUN_00483140) ──────────────
// Ghidra: FUN_00483140 (18 callers, 1 callee)
// Purpose: SSE2 cosine wrapper — trampoline to libm_sse2_cos_precise.
//          Used as EndShaderBlock by the shader constant pipeline.
//          Passes the floating-point argument in x87/st(0) or XMM0
//          and returns cos(arg) the same way.
float ComputeCos(float angle);

// ─── ComputeSin / BeginShaderBlock (FUN_00483160) ────────────
// Ghidra: FUN_00483160 (15 callers, 1 callee)
// Purpose: SSE2 sine wrapper — trampoline to libm_sse2_sin_precise.
//          Used as BeginShaderBlock by the shader constant pipeline.
float ComputeSin(float angle);

// ─── SubmitShaderConstants (FUN_0061f8f0) ────────────────────
// Ghidra: FUN_0061f8f0 (11 callers, 1 callee)
// Purpose: Submits a 4-float constant vector + flags to the renderer
//          via vtable dispatch. Skips work if the values haven't changed
//          since the last call (dirty-check caching). Sets render state
//          on the device after submission.
void SubmitShaderConstants(float* constants, int index, uint32_t flags);

} // namespace Giants
