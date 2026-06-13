// Giants Engine - Exception Dispatch (ConCRT continuation)
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── DispatchExceptionContinuation (FUN_0061cf60) ── PASS ──
// Constructs a task/functor wrapping std::exception_ptr, copies it into
// an ExceptionHolder (0x28 bytes, ref-counted), then invokes virtual
// dispatch via vtable+0x4. Handles ref counting with LOCK/UNLOCK.
// 16 callers, ~5 callees (ConCRT runtime).
uint8_t DispatchExceptionContinuation(int* param1, void* param2);  // FUN_0061cf60

} // namespace Giants
