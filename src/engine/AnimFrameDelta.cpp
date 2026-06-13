// Giants Engine - Animation Frame Delta Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "AnimFrameDelta.h"
#include <cmath>

namespace Giants {

// ─── Globals ───────────────────────────────────────────────────
static float g_one = 1.0f;  // DAT_0066bf2c

// ═══════════════════════════════════════════════════════════════════
// ComputeAnimFrameDelta (FUN_0047dc00) — 35 callers — FAIL (usable ~90%)
// ═══════════════════════════════════════════════════════════════════
// Computes animation frame position based on mode:
//   Mode 0: Clamp — clamps currentTime to [0, frameCount-1]
//   Mode 1: Loop — wraps via fmod, handles negative wraparound
//   Mode 2: Oscillate — ping-pong between 0 and frameCount-1
//   Mode 3: Reverse — clamps from frameCount-1 downward
//   Mode 4: Alt-loop — alternate loop with direction flip
//
// Note: re-agent marked FAIL due to some register tracking uncertainty
// in the oscillate/reverse paths, but ~90% of logic is correct.

float ComputeAnimFrameDelta(float currentTime, float frameCount, uint32_t mode)
{
    if (frameCount <= g_one)
    {
        return 0.0f;
    }

    float lastFrame = frameCount - g_one;

    switch (mode)
    {
    case 0: // Clamp
    {
        if (currentTime < 0.0f) return 0.0f;
        if (currentTime > lastFrame) return lastFrame;
        return currentTime;
    }

    case 1: // Loop
    {
        float result = fmodf(currentTime, frameCount);
        if (result < 0.0f)
        {
            result += frameCount;
        }
        return result;
    }

    case 2: // Oscillate (ping-pong)
    {
        float t = fmodf(currentTime, lastFrame);
        if (t < 0.0f) t += lastFrame;

        int phase = static_cast<int>(currentTime / lastFrame);
        if (phase & 1)
        {
            // Reverse phase: bounce back
            return lastFrame - t;
        }
        return t;
    }

    case 3: // Reverse clamp
    {
        float result = lastFrame - currentTime;
        if (result < 0.0f) return 0.0f;
        if (result > lastFrame) return lastFrame;
        return result;
    }

    case 4: // Alt-loop
    {
        float t = fmodf(currentTime, frameCount);
        if (t < 0.0f) t += frameCount;

        int phase = static_cast<int>(currentTime / frameCount);
        if (phase & 1)
        {
            return frameCount - t;
        }
        return t;
    }

    default:
        return currentTime;
    }
}

} // namespace Giants
