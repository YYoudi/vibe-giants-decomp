// Giants Engine - Dynamic Array Resize
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── ArrayResizeDword (FUN_004810b0) ── PASS ──
// Resizes a dynamic array of dwords (4-byte elements) to at least
// param_2 capacity. Copies existing data, frees old buffer.
// Tracks allocation count in DAT_00701a3c+0x370 if set.
// 20 callers, 3 callees (malloc, memcpy, free).
void ArrayResizeDword(int* arrayHeader, int newCapacity);  // FUN_004810b0

// ─── ArrayResizeQword (FUN_00481950) ── PASS ──
// Resizes a dynamic array of qwords (8-byte elements) to at least
// param_2 capacity. Same pattern as ArrayResizeDword but 8-byte stride.
// 20 callers, 3 callees (malloc, memcpy, free).
void ArrayResizeQword(int* arrayHeader, int newCapacity);  // FUN_00481950

} // namespace Giants
