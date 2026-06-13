// Giants Engine - Vector Insert with Grow (std::vector::insert pattern)
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── VectorInsertGrow (FUN_0042ddc0) ── PASS ──
// std::vector::insert implementation: inserts element at position, handles
// capacity growth with 1.5x strategy, moves elements, frees old buffer.
// Security cookie + CRT heap validation. 11 callers, ~4 callees.
uint32_t* VectorInsertGrow(int* vecHeader, void* pos, uint32_t* elem);  // FUN_0042ddc0
} // namespace Giants
