// Giants Engine - DirectPlay Session Query
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── QueryDirectPlaySession (FUN_0045efd0) ── PASS ──
// Queries DirectPlay session info if session type == 6 and
// session pointer is valid. Allocates a 0x48-byte descriptor,
// fills it with session data via vtable callback, then dispatches.
// 20 callers, 6 callees (vtable calls, malloc, memset, FUN_0045ec20, FUN_006328b0, free).
void QueryDirectPlaySession();  // FUN_0045efd0

} // namespace Giants
