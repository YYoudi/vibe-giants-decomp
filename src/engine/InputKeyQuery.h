// Giants Engine - Input Key Query Functions
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── QueryInputKey2 (FUN_00630c40) ── PASS ──
// Reads 2 key/button states via vtable callbacks. Returns combined 16-bit state
// packed as two bytes: low byte = key1 state, high byte = key2 state.
// Each key read: vtable[2](context, keyIndex) → 0 or 1.
// 23 callers, 0 callees — pure input query.
uint32_t QueryInputKey2(int context, int key1Index, int key2Index);  // FUN_00630c40

// ─── QueryInputKey4 (FUN_00630840) ── PASS ──
// Reads 4 key/button states via vtable callbacks. Returns combined 32-bit state
// packed as four bytes: bits 0-7 = key1, bits 8-15 = key2, bits 16-23 = key3,
// bits 24-31 = key4. Each key read: vtable[2](context, keyIndex) → 0 or 1.
// 23 callers, 0 callees — pure input query.
uint32_t QueryInputKey4(int context, int key1Index, int key2Index, int key3Index, int key4Index);  // FUN_00630840

} // namespace Giants
