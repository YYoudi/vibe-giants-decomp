// Giants Engine - String Assign Operation
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── StringAssignFromPtr (FUN_0042fed0) ── PASS ──
// MSVC std::string assignment from char pointer.
// State machine: 0=uninitialized, 1=active, 2+=error.
// Uninitialized: sets up SSO string, copies data.
// Active: delegates to assign helper.
// Invalid state: throws std::exception via _CxxThrowException.
// 30 callers, 11 callees. Uses security cookie (DAT_0067d280).
uint32_t StringAssignFromPtr(char* strObj, char* src);  // FUN_0042fed0

} // namespace Giants
