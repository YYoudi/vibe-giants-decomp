// Giants Engine - System Initialization & GPU Capabilities
// Reverse engineered from GiantsMain.exe v1.520.59
//
// SystemInit: Callback dispatch (108 entries), timer reset, world init.
// WaitForInit: Spin-loop until PerformInitialization completes.
// QueryRenderCapabilities: GPU caps query via vtable, feature flag config.

#pragma once

#include <cstdint>

namespace Giants {

// ─── WaitForInit (FUN_004e8c30) — PASS ─────────────────────────
// Synchronization spin-loop: blocks until PerformInitialization
// (FUN_004e8dd0) returns non-zero. Only runs when the FLICK system
// is active (DAT_00747d2c != 0).
// 7 callers, 1 callee.
void WaitForInit();  // FUN_004e8c30

// ─── SystemInit (FUN_004e8c70) — PASS ──────────────────────────
// Full system initialization: waits for FLICK init, then dispatches
// up to 108 callbacks from the object list (DAT_007027a8 linked list),
// resets timers and world state, loads the scene, and triggers the
// render pipeline initialization.
// 11 callers, 8 callees.
//
// Parameters:
//   param_1 — scene/level file path (null-terminated string)
// Returns: the initialization state (0 = success, or error code)
int SystemInit(const char* scenePath);  // FUN_004e8c70

// ─── QueryRenderCapabilities (FUN_004f8550) — PASS ─────────────
// Queries GPU capabilities via the renderer vtable (offset 0xd4),
// then configures feature flags for the rendering pipeline:
//   - DAT_00702b5c : stencil buffer support
//   - DAT_00702b64 : depth bias mode
//   - DAT_00702b5e : clip plane support
//   - DAT_00702b6c : shadow filter quality
//   - DAT_00702afc : render path index
//   - DAT_00702b18 : MSAA mode
//   - DAT_00702b24 : anisotropic filter level
//   - DAT_00702b70 : HDR flag
//   - DAT_00702b74 : bloom intensity (1.0f default)
// Falls back to software emulation if caps are missing.
// 4 callers, 3 callees.
void QueryRenderCapabilities();  // FUN_004f8550

} // namespace Giants
