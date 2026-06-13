// Giants Engine - Render Error Display Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "RenderErrorDisplay.h"
#include <cstdint>

namespace Giants {

// ─── Shared globals ────────────────────────────────────────────
extern uint32_t DAT_00702a5c;    // Error state flag A
extern uint32_t DAT_00702a58;    // Error state flag B
extern uint32_t DAT_007028a4;    // Screen/text param
extern float    DAT_0066bd9c;    // Text scale — MathUtils.cpp
extern float    _DAT_0074beb4;   // Font pixel size — DisplayMode.cpp
extern float    DAT_0066be20;    // Scale/aspect — Camera.cpp
extern uint32_t DAT_0074bed4;    // Screen X offset — ErrorHandler.cpp
extern uint8_t  DAT_0074bf0e[];  // Glyph width table

// ─── External callees ──────────────────────────────────────────
extern void FUN_0059e180();      // Error dialog display
extern void FUN_0062c1b0();      // Text render begin
extern void FUN_0062c420(float x, int len);  // Text render execute

// ═══════════════════════════════════════════════════════════════════
// DisplayRenderError (FUN_00526be0) — 17 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Displays "Render Error" text on screen. Checks error state flags
// first — if DAT_00702a5c is set, clears it and returns. If
// DAT_00702a58 is set, delegates to error dialog. Otherwise renders
// the "Render Error" string character by character using glyph widths.

void DisplayRenderError()
{
    if (DAT_00702a5c != 0) {
        DAT_00702a5c = 0;
        return;
    }

    if (DAT_00702a58 != 0) {
        FUN_0059e180();
        return;
    }

    // Measure "Render Error" string width
    int remaining = 12;  // Max chars to process
    float charWidth = static_cast<float>(DAT_007028a4) * DAT_0066bd9c / _DAT_0074beb4;

    FUN_0062c1b0();

    float cursorX = 0.0f;
    const char* text = "Render Error";

    do {
        remaining--;
        if (*text == '\0') break;

        if (cursorX != 0.0f) {
            cursorX += charWidth;
        }

        int glyphIdx = static_cast<uint8_t>(*text) * 5;
        if (glyphIdx != -0x74BF0C) {
            cursorX += static_cast<float>(DAT_0074bf0e[glyphIdx]) * charWidth;
        }
        text++;
    } while (0 < remaining);

    // Render at fixed screen position
    FUN_0062c420(
        (DAT_0066bd9c / _DAT_0074beb4) * static_cast<float>(DAT_0074bed4) + DAT_0066be20,
        12);
}

} // namespace Giants
