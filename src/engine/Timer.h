// Giants Engine - Frame Timer / Time Management
// Reverse engineered from GiantsMain.exe v1.520.59
//
// FUN_00629f50 — Maintains frame delta time with exponential smoothing.
//   Uses GetTickCount(), applies pause/slow-motion/fixed-timestep modifiers.
//   Smoothing ramps up over first 6 frames to avoid spikes.

#pragma once

#include <cstdint>

namespace Giants {

// ─── Timing Globals ───────────────────────────────────────────

extern float  g_deltaTime;         // DAT_00727e40 — raw frame delta (seconds)
extern float  g_smoothedTime;      // DAT_00727e3c — exponentially smoothed delta
extern float  g_timeMultiplier;    // DAT_00727e38 — final time scale (applied to game logic)
extern float  g_baseTimeScale;     // DAT_00727e48 — base multiplier (typically 1.0)

extern uint32_t g_lastTick;        // DAT_0074da5c — last GetTickCount value
extern float  g_smoothingFactor;   // internal, ramps 0.0 → 0.75
extern int    g_frameCount;        // internal, counts first 6 frames

// ─── Pause / Slow-Motion Flags ────────────────────────────────

extern uint8_t g_isPaused;         // DAT_00702b1f — game paused
extern uint8_t g_isSlowMotion;     // DAT_00702b1e — slow motion active
extern uint8_t g_isFixedTimestep;  // DAT_00702be8 — force 1/60s delta

// ─── Timing Constants ─────────────────────────────────────────

constexpr double kTickToSeconds      = 0.001;   // DAT_0066bd08
constexpr float  kMaxSmoothing       = 0.75f;   // DAT_0066bea0
constexpr float  kFixedDelta         = 1.0f / 60.0f; // 0.016666668
constexpr double kAbsHelper[2]       = {0.0, -2.0};  // DAT_0066c510 (branchless abs)

// ─── Functions ────────────────────────────────────────────────

/// Update frame timing. Call once per frame before game logic.
/// Computes deltaTime, applies smoothing, handles pause/slowmo/fixed timestep.
void UpdateTime();                  // FUN_00629f50

/// Reset timer state (called on first frame or after device reset).
void ResetTimer();                  // FUN_00629e90

/// Get raw tick count (wraps GetTickCount).
uint32_t GetRawTickCount();         // FUN_00629e40

} // namespace Giants
