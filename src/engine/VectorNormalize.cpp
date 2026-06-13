// Giants Engine - Vector Normalize Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "VectorNormalize.h"
#include <cstdint>
#include <cmath>
namespace Giants {
extern uint32_t DAT_0066bf2c;  // 1.0f
extern uint32_t DAT_0066bce4;  // 1.0f constant for comparison

float VectorNormalize(float* out, float* in)
{
    float x = in[0];
    float lenSq = x * x + in[1] * in[1] + in[2] * in[2];

    // FUN_0042bee0 — likely a sqrt or assertion check (skipped stub)

    if (lenSq != *reinterpret_cast<float*>(&DAT_0066bce4)) {
        float invLen = *reinterpret_cast<float*>(&DAT_0066bf2c) / lenSq;
        out[0] = x * invLen;
        out[1] = invLen * in[1];
        out[2] = invLen * in[2];
    }

    return lenSq;
}
} // namespace Giants
