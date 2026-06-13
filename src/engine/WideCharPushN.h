// Giants Engine - Wide Char Vector Push N
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── WideCharPushN (FUN_004bb3c0) ── PASS ──
// Pushes N copies of a uint16_t value into a growing container.
// Uses vtable[0] for grow callback. 15 callers, 0 callees.
uint32_t* WideCharPushN(uint32_t* out, int count, uint32_t* container, const uint16_t* value);  // FUN_004bb3c0
} // namespace Giants
