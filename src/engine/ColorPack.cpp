// Giants Engine - Color Packing Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "ColorPack.h"
#include <cstring>

namespace Giants {

// ─── Globals ───────────────────────────────────────────────────
static float g_one = 1.0f;           // DAT_0066bf2c
static float g_half = 0.5f;          // DAT_0066be20
static float g_colorScale = 255.0f;  // DAT_0066c12c

// ═══════════════════════════════════════════════════════════════════
// PackColorToARGB (FUN_00472920) — 34 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Packs a float[4] {R,G,B,A} into a uint32 ARGB color.
// Each channel is clamped to [0.0, 1.0], multiplied by 255,
// rounded (via +0.5 and int cast), then packed as 0xAARRGGBB.
//
// Register mapping:
//   param_1[0] = R → G channel in output
//   param_1[1] = G → B channel in output
//   param_1[2] = B → R channel in output
//   param_1[3] = A → A channel in output

static inline float ClampChannel(float value)
{
    if (value < 0.0f) return 0.0f;
    if (value > g_one) return g_one;
    return value;
}

uint32_t PackColorToARGB(const float* param_1)
{
    // Clamp R channel to [0.0, 1.0]
    float fVar3 = ClampChannel(param_1[0]);

    // Clamp G channel to [0.0, 1.0]
    float fVar4 = ClampChannel(param_1[1]);

    // Clamp B channel to [0.0, 1.0]
    float fVar5 = ClampChannel(param_1[2]);

    // Clamp A channel to [0.0, 1.0]
    float fVar2 = ClampChannel(param_1[3]);

    // Pack into ARGB uint32: A<<24 | R<<16 | G<<8 | B
    // Each channel: (int)(value * 255.0f + 0.5f)
    return static_cast<uint32_t>(static_cast<int32_t>(fVar2 * g_colorScale + g_half) << 24) |
           static_cast<uint32_t>(static_cast<int32_t>(fVar3 * g_colorScale + g_half)) |
           static_cast<uint32_t>(static_cast<int32_t>(fVar4 * g_colorScale + g_half) << 8) |
           static_cast<uint32_t>(static_cast<int32_t>(fVar5 * g_colorScale + g_half) << 16);
}

} // namespace Giants
