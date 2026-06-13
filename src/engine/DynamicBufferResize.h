// Giants Engine - Dynamic Buffer Resize
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>
#include <cstddef>

namespace Giants {

// ─── DynamicBufferResize (FUN_004830d0) ── PASS ──
// Resizes a dynamic buffer: {size, capacity, data_ptr}. If new capacity
// exceeds current, allocates new buffer, copies old data, frees old.
// Increments/decrements allocation counter at DAT_00701a3c+0x370.
// 15 callers, 3 callees (malloc, memcpy, free).
void DynamicBufferResize(size_t* bufDesc, size_t newCapacity);  // FUN_004830d0

} // namespace Giants
