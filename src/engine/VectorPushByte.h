// Giants Engine - Byte Vector Push
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── PushByteToVector (FUN_0044a950) ── PASS ──
// Pushes N bytes from a source buffer into a growing byte vector.
// Vector layout: [+0] next*, [+4] data ptr, [+8] size, [+12] capacity.
// If size+1 > capacity, calls vtable[0] to grow. Returns vector pointer.
// 21 callers, 0 callees — pure container operation.
uint32_t* PushByteToVector(uint32_t* out, int count, uint32_t* vec, const uint8_t* src);  // FUN_0044a950

} // namespace Giants
