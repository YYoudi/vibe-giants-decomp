// Giants Engine - Get Application Version
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── GetApplicationVersion (FUN_005f0fe0) ── PASS ──
// Returns pointer to static version info (major, pad, patch, minor).
// Queries via GetFileVersionInfoSizeA/GetFileVersionInfoA/VerQueryValueA
// on first call, caches in globals. Uses security cookie.
// 12 callers, ~2 callees.
uint32_t* GetApplicationVersion();  // FUN_005f0fe0

} // namespace Giants
