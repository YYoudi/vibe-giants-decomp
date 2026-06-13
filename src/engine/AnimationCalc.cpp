// Giants Engine - Animation Interval Calculation Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "AnimationCalc.h"
#include <cmath>
#include <cstring>

namespace Giants {

// ─── Globals ───────────────────────────────────────────────────
static int g_globalValue = 0;                // DAT_00701a3c — animation sequence base
extern float DAT_0066be90;                   // scale factor A (defined in another TU)
static float DAT_0066bec4 = 0.0f;            // scale factor B for mode 3
static float DAT_0066bdd4 = 0.0f;            // scale factor B for mode 5
static float _DAT_0066bf5c = 0.0f;           // scale factor A for mode 4

// ═══════════════════════════════════════════════════════════════════
// GetIntervalCount (FUN_0047dc00) — 35 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Complex interval count calculator for animation sequences.
// Base object at DAT_00701a3c contains:
//   +0x18  offset (float)
//   +0x8c  base scale (float)
//   +0x90  step scale (float)
//   +0x1458 + index*4  value for given index (float)
//
// Modes 3/4/5 compute: count = (value - offset - scaleA) / scaleB
// with different scaling factors per mode.

int GetIntervalCount(int index, int mode)
{
    int* base = &g_globalValue;
    float* fbase = reinterpret_cast<float*>(base);

    if (mode == 0) {
        return g_globalValue;
    }

    // Read the indexed float value
    float value = fbase[0x1458 / 4 + index];

    if (value < 0.0f) {
        if (mode != 2) {
            return g_globalValue;
        }
        // mode == 2: fall through to return g_globalValue
        return g_globalValue;
    }

    if (mode == 1) {
        // Bit-manipulation: pack float comparison flags into an integer
        // using CONCAT22/CONCAT11 byte-level construction
        unsigned int nanFlag = std::isnan(value) ? 1U : 0U;
        unsigned int flags = ((value == 0.0f) << 6)
                           | (nanFlag << 2)
                           | 2U
                           | (value < 0.0f);

        unsigned short lowWord = (static_cast<unsigned short>(flags) << 8)
                               | static_cast<unsigned char>(g_globalValue);
        unsigned short highWord = static_cast<unsigned short>(
            static_cast<unsigned int>(g_globalValue) >> 16);

        int result = (static_cast<int>(highWord) << 16) | static_cast<int>(lowWord);

        if (value == 0.0f) {
            return result;
        }
        return result;
    }

    if (mode == 3) {
        float offset = fbase[0x18 / 4];
        float scaleA = fbase[0x8c / 4] * DAT_0066be90;
        float scaleB = fbase[0x90 / 4] * DAT_0066bec4;

        if (value != 0.0f) {
            float adjusted = value - offset;
            if (adjusted < value) {
                if (0.0f < scaleB) {
                    int lowerIdx = (scaleA <= adjusted)
                        ? static_cast<int>((adjusted - scaleA) / scaleB)
                        : -1;
                    if (scaleA <= value) {
                        return static_cast<int>((value - scaleA) / scaleB) - lowerIdx;
                    }
                    return -1 - lowerIdx;
                }
                if ((adjusted < scaleA) && (scaleA <= value)) {
                    return 1;
                }
            }
            return 0;
        }
        return 1;
    }

    if (mode == 4) {
        float scaleA = fbase[0x8c / 4] * _DAT_0066bf5c;
        float scaleB = fbase[0x90 / 4] + fbase[0x90 / 4];  // doubled
        float offset = fbase[0x18 / 4];

        if (value != 0.0f) {
            float adjusted = value - offset;
            if (adjusted < value) {
                if (0.0f < scaleB) {
                    int lowerIdx = (scaleA <= adjusted)
                        ? static_cast<int>((adjusted - scaleA) / scaleB)
                        : -1;
                    if (scaleA <= value) {
                        return static_cast<int>((value - scaleA) / scaleB) - lowerIdx;
                    }
                    return -1 - lowerIdx;
                }
                if ((adjusted < scaleA) && (scaleA <= value)) {
                    return 1;
                }
            }
            return 0;
        }
        return 1;
    }

    if (mode == 5) {
        float scaleA = fbase[0x8c / 4] * DAT_0066be90;
        float scaleB = fbase[0x90 / 4] * DAT_0066bdd4;
        float offset = fbase[0x18 / 4];

        if (value != 0.0f) {
            float adjusted = value - offset;
            if (adjusted < value) {
                if (0.0f < scaleB) {
                    int lowerIdx = (scaleA <= adjusted)
                        ? static_cast<int>((adjusted - scaleA) / scaleB)
                        : -1;
                    if (scaleA <= value) {
                        return static_cast<int>((value - scaleA) / scaleB) - lowerIdx;
                    }
                    return -1 - lowerIdx;
                }
                if ((adjusted < scaleA) && (scaleA <= value)) {
                    return 1;
                }
            }
            return 0;
        }
        return 1;
    }

    return g_globalValue;
}

} // namespace Giants
