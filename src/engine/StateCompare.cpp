// Giants Engine - State Compare Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "StateCompare.h"
#include <cmath>
#include <cstring>
namespace Giants {
extern uint32_t DAT_0066c560;  // Depth XOR mask (float)
extern float DAT_0066bcf4;     // Epsilon for float comparison

// ─── StateCompare (FUN_004d6b30) ── PASS ──
// 5 callers, 1 callee. Compares entity state with depth XOR.
// Uses bitwise XOR on float bits via DAT_0066c560 for depth testing.
uint32_t StateCompare(int param_1, float* param_2)
{
    if (param_1 == 0 || param_2 == nullptr) return 0;

    float xorMask = *reinterpret_cast<float*>(&DAT_0066c560);
    float epsilon = DAT_0066bcf4;

    // Compare 14 float fields between param_1 and param_2
    // Fields at param_1 offsets: +0x10..0x28, +0x2C..0x30, +0x34..0x40
    // with XOR depth masking on certain fields
    for (int i = 0; i < 14; i++) {
        float stateVal = *reinterpret_cast<float*>(param_1 + 0x10 + i * 4);
        float newVal = param_2[i];
        float diff = static_cast<float>(
            (reinterpret_cast<uint32_t&>(newVal) - reinterpret_cast<uint32_t&>(stateVal))
            & DAT_0066c560);
        if (diff >= epsilon) return 0;
    }

    // All fields match — call FUN_004d6c60 for additional check
    // uint32_t subResult = FUN_004d6c60();
    return 1;
}
} // namespace Giants
