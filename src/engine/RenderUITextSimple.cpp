// Giants Engine - UI Text Rendering (Simple Variant) Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "RenderUITextSimple.h"
#include <cstdint>

namespace Giants {

// ─── Globals (shared) ───────────────────────────────────────────
extern uint32_t* DAT_00702d50;   // Resolve callback — GameCommand.cpp
extern float     DAT_0066bf2c;   // 1.0f constant — FlickInterpreter.cpp
extern float     _DAT_0074beb4;  // Font pixel size — DisplayMode.cpp
extern uint32_t  DAT_0074bed4;   // Screen X offset — ErrorHandler.cpp
extern void*     DAT_007280cc;   // Text renderer callback — GameCommand.cpp

// ─── External callees ───────────────────────────────────────────
extern char* FUN_00551ae0();     // Get entity display string
extern void  DrawTextPrepare();   // FUN_0062c690
extern void  DrawTextExecute(float x, int len);  // FUN_0062c420

// Placeholder for text render callback address
static void LAB_005423e0() {}

// ═══════════════════════════════════════════════════════════════════
// RenderUITextSimple (FUN_005da8f0) — 23 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Simplified version of RenderUIText (FUN_005da470).
// No mode 0/MH_Renderer path, no camera operations.
// 1. Get display string via FUN_00551ae0
// 2. Resolve mode descriptor via DAT_00702d50 callback
// 3. Compute text length
// 4. If callback has no value and descriptor exists, set text callback
// 5. Position calculation based on mode (0 or 0x15 vs other)
// 6. Draw via DrawTextPrepare + DrawTextExecute

uint32_t RenderUITextSimple(int param_1, int param_2, int param_3, int param_4)
{
    if (param_3 != 0) {
        return 0xFFFFFF;
    }

    char* text = FUN_00551ae0();
    if (text == nullptr) {
        return 0xFFFFFF;
    }

    // Resolve string descriptor for this mode
    typedef int* (*ResolveFn)(uint32_t);
    ResolveFn resolve = reinterpret_cast<ResolveFn>(reinterpret_cast<uintptr_t>(DAT_00702d50));
    int* desc = resolve(*reinterpret_cast<uint32_t*>(param_4 + 4));

    // Measure string length
    char* scan = text;
    char c;
    do { c = *scan; scan++; } while (c != '\0');
    desc[2] = static_cast<int>(scan - (text + 1));

    // Set text render callback if descriptor has no custom value
    if (desc[0] != 0 && reinterpret_cast<int*>(desc[1]) != nullptr &&
        *reinterpret_cast<int*>(desc[1]) == 0) {
        DAT_007280cc = reinterpret_cast<void*>(LAB_005423e0);
    }

    float xPos, yPos;
    int textLen;

    int mode = *reinterpret_cast<int*>(param_4 + 4);
    if (mode == 0 || mode == 0x15) {
        // Baseline position mode
        float bottom = *reinterpret_cast<float*>(param_2 + 0x48);
        int lineCount = *reinterpret_cast<int*>(param_1 + 0x28);
        xPos = (bottom - *reinterpret_cast<float*>(param_2 + 0x3C)) / static_cast<float>(lineCount);

        char* scan2 = text;
        char c2;
        do { c2 = *scan2; scan2++; } while (c2 != '\0');
        DrawTextPrepare();

        char* scan3 = text + 1;
        char* scan4 = text;
        do { c2 = *scan4; scan4++; } while (c2 != '\0');
        textLen = static_cast<int>(scan4 - scan3);
        yPos = DAT_0066bf2c - bottom / static_cast<float>(lineCount);
    } else {
        // Full range position mode
        char* scan5 = text + 1;
        xPos = (*reinterpret_cast<float*>(param_2 + 0x48) -
                *reinterpret_cast<float*>(param_2 + 0x3C)) /
               static_cast<float>(*reinterpret_cast<int*>(param_1 + 0x28));

        char* scan6 = text;
        char c3;
        do { c3 = *scan6; scan6++; } while (c3 != '\0');
        textLen = static_cast<int>(scan6 - scan5);
        yPos = DAT_0066bf2c -
               *reinterpret_cast<float*>(param_2 + 0x48) /
               static_cast<float>(*reinterpret_cast<int*>(param_1 + 0x28));
    }

    DrawTextExecute(yPos + (xPos / _DAT_0074beb4) * static_cast<float>(DAT_0074bed4), textLen);
    DAT_007280cc = nullptr;

    return 0xFFFFFF;
}

} // namespace Giants
