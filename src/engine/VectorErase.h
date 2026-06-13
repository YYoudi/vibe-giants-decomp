// Giants Engine - Vector Erase (std::vector::erase pattern)
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── VectorErase (FUN_0042df20) ── PASS ──
// std::vector::erase implementation: erases element at position,
// shifts remaining elements, handles SSO/heap buffer cleanup.
// 10 callers, ~3 callees.
uint32_t* VectorErase(int* vecHeader, void* pos, uint32_t* elem);  // FUN_0042df20
} // namespace Giants
