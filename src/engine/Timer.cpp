// Giants Engine - Frame Timer Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
//
// FUN_00629f50 — UpdateTime (FAIL, code extracted — float vs double in abs helper)
// Uses GetTickCount() for timing, exponential smoothing over first 6 frames,
// supports pause, slow-motion, and fixed-timestep overrides.

#include "Timer.h"
#include <windows.h>

namespace Giants {

// ─── Static State ─────────────────────────────────────────────

float     g_deltaTime       = 0.0f;    // DAT_00727e40
// g_smoothedTime and g_timeMultiplier are defined in GameLogic.cpp (canonical)
float     g_baseTimeScale   = 1.0f;    // DAT_00727e48
uint32_t  g_lastTick        = 0;       // DAT_0074da5c
float     g_smoothingFactor = 0.0f;    // internal
int       g_frameCount      = 0;       // internal

uint8_t   g_isPaused        = 0;       // DAT_00702b1f
uint8_t   g_isSlowMotion    = 0;       // DAT_00702b1e
uint8_t   g_isFixedTimestep = 0;       // DAT_00702be8

// ─── GetRawTickCount (FUN_00629e40) ──────────────────────────

uint32_t GetRawTickCount()
{
    return GetTickCount();
}

// ─── ResetTimer (FUN_00629e90) ────────────────────────────────

void ResetTimer()
{
    // Called on first frame to initialize timer state
    // Stub — exact logic to be refined
}

// ─── UpdateTime (FUN_00629f50) ────────────────────────────────
// Status: FAIL (float vs double precision in abs helper)
// Maintains frame delta time with exponential smoothing.
//   g_deltaTime     = raw frame delta (seconds)
//   g_smoothedTime  = exponentially smoothed delta
//   g_timeMultiplier = final scaled value (baseTimeScale × smoothedDelta)
//     × pause (0.0), slow-motion (× factor), fixed (1/60)

void UpdateTime()
{
    uint32_t tick = GetTickCount();

    // Branchless absolute value: abs(tick) using kAbsHelper
    // kAbsHelper = {0.0, -2.0}; index = -(tick >> 31) → 0 if positive, 1 if negative
    g_deltaTime = static_cast<float>(
        (static_cast<double>(static_cast<int>(tick)) +
         kAbsHelper[-(static_cast<int>(tick) >> 31)]) * kTickToSeconds
    );

    // First frame initialization
    if (g_lastTick == 0)
    {
        ResetTimer();
        g_lastTick = tick;
        return;
    }

    // Handle tick count wraparound
    if (tick < g_lastTick)
    {
        g_lastTick = tick;
    }

    int32_t elapsed = tick - g_lastTick;
    float smoothedDelta = static_cast<float>(
        (static_cast<double>(elapsed) + kAbsHelper[-(elapsed >> 31)]) * kTickToSeconds
    );

    // Exponential smoothing ramp-up over first 6 frames
    if (g_frameCount < 6)
    {
        g_frameCount++;
        g_smoothedTime = smoothedDelta;
    }
    else
    {
        // EMA: smoothed = (1 - α) × delta + α × prevSmoothed
        g_smoothedTime = (1.0f - g_smoothingFactor) * smoothedDelta +
                          g_smoothedTime * g_smoothingFactor;

        // Ramp smoothing factor toward 0.75
        if (g_smoothingFactor < kMaxSmoothing)
        {
            g_smoothingFactor += 0.0f; // TODO: find actual ramp rate from DAT_0066bdac
            if (kMaxSmoothing < g_smoothingFactor)
            {
                g_smoothingFactor = kMaxSmoothing;
            }
        }
    }

    // Apply modifiers
    float finalDelta = g_smoothedTime;

    if (g_isPaused != 0)
    {
        finalDelta = 0.0f;  // kPausedTimeScale
    }

    if (g_isSlowMotion != 0)
    {
        finalDelta *= 0.0f; // TODO: find actual slow-motion scale from DAT_0066bd9c
    }

    g_timeMultiplier = g_baseTimeScale * finalDelta;

    // Clamp minimum time multiplier when not paused/slow
    if ((g_isSlowMotion == 0) && (g_isPaused == 0) &&
        0.25f > g_timeMultiplier) // kMinTimeMultiplier from DAT_0066bdc4
    {
        g_timeMultiplier = 0.25f;
    }

    // Fixed timestep override (debug/replay)
    if (g_isFixedTimestep != 0)
    {
        g_timeMultiplier = kFixedDelta;
    }

    g_lastTick += elapsed;
}

} // namespace Giants
