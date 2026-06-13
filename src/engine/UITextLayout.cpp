// Giants Engine - UI Text Layout Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "UITextLayout.h"
#include "CRTStubs.h"

namespace Giants {

// --- runtime state globals (were *reinterpret_cast derefs; engine-populated) ---
static float g_state_0074beb4 = 0.0f;  // was @0x0X0074BEB4
static int g_state_0074bed4 = 0;  // was @0x0X0074BED4

extern const char* GetUIString();              // FUN_00551ae0
extern void        CommitTextRender();         // FUN_0062c690
extern void        SetTextInterpolation(float t, int len);  // FUN_0062c420

// ═══════════════════════════════════════════════════════════════════
// LayoutUIText (FUN_005da8f0) — 23 callers — PASS
// ═══════════════════════════════════════════════════════════════════

uint32_t LayoutUIText(int param_1, int param_2, int param_3, int param_4)
{
    if (param_3 != 0)
        return 0xFFFFFF;

    const char* text = GetUIString();
    if (text == nullptr)
        return 0xFFFFFF;

    // Resolve buffer from param_4 via function pointer table
    auto vtableFn = reinterpret_cast<void*(__cdecl*)(uint32_t)>(
        *reinterpret_cast<void**>(0x00702d50));
    int* bufInfo = reinterpret_cast<int*>(vtableFn(*reinterpret_cast<uint32_t*>(param_4 + 4)));

    // Measure string length, store in bufInfo[2]
    const char* p = text;
    char c;
    do { c = *p; p++; } while (c != '\0');
    bufInfo[2] = static_cast<int>(p - text - 1);

    // Sentinel check
    if ((bufInfo[0] != 0) && (reinterpret_cast<int*>(bufInfo[1]) != nullptr) &&
        (*reinterpret_cast<int*>(bufInfo[1]) == 0))
    {
        *reinterpret_cast<char**>(0x007280cc) = reinterpret_cast<char*>(0x005423e0);
    }

    float endVal = *reinterpret_cast<float*>(param_2 + 0x48);
    float startVal = *reinterpret_cast<float*>(param_2 + 0x3c);
    int divisor = *reinterpret_cast<int*>(param_1 + 0x28);

    float progress;
    int strLen;
    float invProgress;

    uint32_t param4val = *reinterpret_cast<uint32_t*>(param_4 + 4);
    if (param4val == 0 || param4val == 0x15)
    {
        progress = (endVal - startVal) / static_cast<float>(divisor);

        const char* p2 = text;
        do { c = *p2; p2++; } while (c != '\0');

        CommitTextRender();

        strLen = static_cast<int>(p2 - text - 1);
        invProgress = 1.0f - endVal / static_cast<float>(divisor);
    }
    else
    {
        progress = (endVal - startVal) / static_cast<float>(divisor);

        const char* p2 = text;
        do { c = *p2; p2++; } while (c != '\0');
        strLen = static_cast<int>(p2 - text - 1);

        invProgress = 1.0f - endVal / static_cast<float>(divisor);
    }

    // Compute interpolation value
    float interp = invProgress + (progress / g_state_0074beb4) *
                   static_cast<float>(g_state_0074bed4);
    SetTextInterpolation(interp, strLen);

    *reinterpret_cast<char**>(0x007280cc) = nullptr;

    return 0xFFFFFF;
}

} // namespace Giants
