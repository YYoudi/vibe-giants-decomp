// Giants Engine - Create Type Exception (JSON error)
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── CreateTypeException (FUN_0043fef0) ── FAIL (usable ~75%) ──
// Creates a type error exception with message string. Copies SSO string,
// initializes vtable pointers, copies exception_ptr. Error code at +0x0C.
// 13 callers, ~5 callees.
struct CustomException { void* vftable[2]; uint32_t unused[2]; uint32_t error_code; void* eptr[3]; };
CustomException* CreateTypeException(CustomException* result, uint32_t param2, uint32_t* param3);  // FUN_0043fef0

} // namespace Giants
