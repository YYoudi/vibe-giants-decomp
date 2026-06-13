// Giants Engine - Wide Char Appender
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── WideCharAppender (FUN_004bc520) ── PASS ──
// Appends chars from [param_2, param_3) to a wide-char buffer in param_4.
// Grows buffer via vtable callback if needed. 6 callers, 0 callees.
uint32_t* WideCharAppender(uint32_t* out, char* begin, char* end, uint32_t* bufState);  // FUN_004bc520
} // namespace Giants
