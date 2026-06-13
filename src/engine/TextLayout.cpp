// Giants Engine - Text Layout Measurement Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "TextLayout.h"
#include <cstring>

namespace Giants {

// ─── Globals ───────────────────────────────────────────────────
static float g_defaultScale = 1.0f;    // DAT_0066bd58
static float g_altScale = 1.0f;        // DAT_0066bd50
extern const float g_oneFloat;         // DAT_0066bf2c = 1.0f
static float g_halfFloat = 0.5f;       // DAT_0066be20 (used as 0.5 divisor)
static float g_screenWidth = 640.0f;   // _DAT_0074beb4
static int   g_screenHeight = 480;     // DAT_0074bed4

extern void MeasureStringWidth();       // FUN_0062c690

// ═══════════════════════════════════════════════════════════════════
// MeasureTextLayout (FUN_004d3dd0) — 38 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Calculates the bounding rectangle for a text string, supporting:
//   - Multi-line text (newline-delimited)
//   - Horizontal alignment (left/center/right via flags)
//   - Vertical alignment (top/middle/bottom via flags)
//   - Scale factor selection (flag bit 24)
//
// Layout struct at param_2:
//   +0x0c  flags (bit 2 = multiline, bit 24 = alt scale,
//                bit 26/27 = h-align, bit 28/29/30 = v-align)
//   +0x10  posX, +0x14  posY (input position)
//   +0x18  top,  +0x1c  left (output bounds)
//   +0x20  right, +0x24 bottom (output bounds)
//   +0x28  text pointer
//   +0x30  lineHeight

void MeasureTextLayout(uint32_t /*param_1*/, int param_2)
{
    char* text = *reinterpret_cast<char**>(param_2 + 0x28);
    uint32_t flags = *reinterpret_cast<uint32_t*>(param_2 + 0xc);
    float posX = *reinterpret_cast<float*>(param_2 + 0x10);
    float posY = *reinterpret_cast<float*>(param_2 + 0x14);
    float lineHeight = *reinterpret_cast<float*>(param_2 + 0x30);

    float textWidth;
    float totalHeight = 0.0f;

    if ((flags & 4) == 0) {
        // Single line: measure string length
        char* ptr = text;
        while (*ptr != '\0') ptr++;
        textWidth = lineHeight;
        MeasureStringWidth();
    } else {
        // Multi-line: process newlines and accumulate height
        int lineCount = 0;
        float maxWidth = 0.0f;
        char* ptr = text;
        char* lastLineStart = text;
        char c = *ptr;
        float runningMax = maxWidth;

        while (c != '\0') {
            ptr++;
            maxWidth = runningMax;

            if (c == '\n') {
                maxWidth = lineHeight;
                MeasureStringWidth();
                if (maxWidth <= runningMax) {
                    maxWidth = runningMax;
                }
                lineCount++;
                lastLineStart = ptr;
            }

            runningMax = maxWidth;
            c = *ptr;
        }

        textWidth = lineHeight;
        MeasureStringWidth();
        if (textWidth <= runningMax) {
            textWidth = runningMax;
        }

        // Adjust for trailing newline
        if ((lastLineStart < ptr) && (ptr[-1] == '\n')) {
            lineCount--;
        }

        totalHeight = static_cast<float>(lineCount) * lineHeight;
    }

    // Scale factor selection (flag bit 24)
    float scaleFactor = g_defaultScale;
    if ((flags & 0x1000000) != 0) {
        scaleFactor = g_altScale;
    }

    // Calculate adjusted Y position
    float adjustedY = posY;
    if ((static_cast<int>(flags) < 0) && (adjustedY = scaleFactor * posY, posY < 0.0f)) {
        adjustedY += 1.0f;  // DAT_0066bf2c
    }

    // Vertical alignment flags
    if ((flags & 0x10000000) == 0) {
        if ((flags & 0x20000000) == 0) {
            if ((flags & 0x40000000) != 0) {
                adjustedY -= (scaleFactor / g_screenWidth) * static_cast<float>(g_screenHeight);
            }
        } else {
            adjustedY -= totalHeight * g_halfFloat;
        }
    } else {
        adjustedY -= totalHeight;
    }

    // Horizontal alignment flags
    float adjustedX = posX;
    if ((flags & 0x4000000) == 0) {
        if ((flags & 0x8000000) != 0) {
            adjustedX -= textWidth * g_halfFloat;
        }
    } else {
        adjustedX -= textWidth;
    }

    // Store bounding box
    *reinterpret_cast<float*>(param_2 + 0x18) = adjustedY;                    // top
    *reinterpret_cast<float*>(param_2 + 0x1c) = adjustedX;                    // left
    *reinterpret_cast<float*>(param_2 + 0x20) = adjustedX + textWidth;        // right
    *reinterpret_cast<float*>(param_2 + 0x24) = adjustedY + totalHeight;      // bottom
}

} // namespace Giants
