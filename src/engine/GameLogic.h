// Giants Engine - Game Logic / Render Pipeline
// Reverse engineered from GiantsMain.exe v1.520.59
//
// FUN_00524f30 — Main per-frame game logic called from MainGameLoop.
//   Handles: timer accumulation, countdown timers, render state save/restore,
//   vtable dispatch to renderer objects, scene rendering, network checks,
//   and final cleanup.

#pragma once

#include <cstdint>
#include "GiantsTypes.h"

namespace Giants {

// ─── Forward declarations for called functions ────────────────

// These are the 18 callees of ProcessGameLogic, to be reversed later.
// Declared but not defined — stub implementations in GameLogic.cpp.
void FUN_00565480();   // Pre-frame setup
void FUN_004ad640();   // Timer tick update
void FUN_00490c50();   // Countdown expired callback
void FUN_004f7e60();   // Begin scene / setup render target
void FUN_005f9c10();   // Render pass helper
void FUN_0063e7f0(void* out); // Extract render stats
void FUN_005fa310();   // Post-render pass
void FUN_004ddf10();   // Scene render finalize
void FUN_00524c10();   // End scene / present
void FUN_005f9d00();   // Post-frame cleanup
void FUN_004f7f10();   // Restore render state
void FUN_004d0dd0();   // Frame end / network tick
void FUN_005253b0();   // Final frame flush
void FUN_00522310();   // Scene begin
int  FUN_004e8dd0();   // Network state check
int  FUN_005539d0();   // Game state update
void FUN_0049a040();   // Window/render target update
unsigned int FUN_00643f70();   // Random seed / hash helper

// ─── Game Logic Globals ───────────────────────────────────────

extern bool  g_frameActive;       // DAT_00702b1d — frame processing active
extern int   g_frameTimer;        // DAT_00702890 — accumulated time
extern int   g_frameCount2;       // DAT_00702894 — frame counter
extern int   g_countdownActive;   // DAT_0074bc18 — countdown timer running
extern bool  g_cutsceneMode;      // DAT_00702aec — cutscene / cinematic mode
extern float g_countdownTimer;    // DAT_0074bbbc — countdown remaining (seconds)
extern int   g_renderMode;        // DAT_00702a58 — render target mode (0=none, 1=active)
extern int   g_sceneReady;        // DAT_00702770 — scene/renderer object
extern void* g_rendererObj;       // DAT_00702700 — primary renderer COM object
extern void* g_renderCtx;         // DAT_00702714 — secondary render context

// Camera/render position
extern float g_camX;              // DAT_0074bb90
extern float g_camY;              // DAT_0074bb94
extern float g_camTargetX;        // DAT_0074bb98
extern float g_camTargetY;        // DAT_0074bb9c

// ─── Main Game Logic ─────────────────────────────────────────

/// Process one frame of game logic.
/// Called each frame by MainGameLoop after input/timing updates.
/// Handles render state, scene rendering, network sync, and frame cleanup.
/// @return 1 always
uint32_t ProcessGameLogic();       // FUN_00524f30

} // namespace Giants
