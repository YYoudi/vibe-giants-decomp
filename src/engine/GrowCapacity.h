// Giants Engine - Dynamic Array Grow Capacity
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── GrowCapacity (FUN_004810b0) ── PASS ──
// Grows a dynamic int array to newCapacity. Tracks allocation count
// via g_MemoryStats when present. Copies existing elements, frees old buffer.
// 20 callers, 0 callees (pure memory ops).
void GrowCapacity(int* vec, int newCapacity);  // FUN_004810b0

} // namespace Giants
