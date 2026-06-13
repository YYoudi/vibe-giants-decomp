// Giants Engine - Vector Matrix Transform
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── TransformVectors (FUN_00639c00) ── PASS ──
// Transforms N vectors by a 4×4 matrix. Dispatch based on matrix flags:
//   flags & 0xb == 0: identity (just copy)
//   flags & 0x10 == 0: 3×3 rotation only (no translation)
//   flags & 0x10 != 0: 3×3 rotation + translation
// Matrix layout: 12 floats at param_4[1..11], translation at [4],[8],[12].
// Input vectors: stride 12 bytes (3 floats each). param_3 = count.
// 23 callers, 0 callees — pure math.
void TransformVectors(uint64_t* dst, const uint64_t* src, int count, const uint32_t* matrix);  // FUN_00639c00

} // namespace Giants
