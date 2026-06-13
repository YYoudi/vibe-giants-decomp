// Giants Engine - Exception Copy Construct (FUN_00443010)
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── ExceptionCopyConstruct (FUN_00443010) ── PASS ──
// Copies exception object with SSO string. Handles vtable, ref counting,
// inner exception copy. Calls noreturn on allocation failure.
// 9 callers, ~3 callees.
void ExceptionCopyConstruct(uint32_t* dest, uint32_t* src);  // FUN_00443010
} // namespace Giants
