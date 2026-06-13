// Giants Engine - Text Bounds Calculation Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "TextBounds.h"
#include "CRTStubs.h"
#include <cstring>

namespace Giants {

// ─── Globals ───────────────────────────────────────────────────
static float g_defaultScaleFactor = 1.0f;   // DAT_0066bd58
static float g_altScaleFactor = 1.0f;       // DAT_0066bd50
extern float g_one;                          // DAT_0066bf2c (1.0f)
extern float g_half;                         // DAT_0066be20 (0.5f)
static float g_invScreenHeight = 0.0f;      // DAT_0074beb4
static int   g_screenHeight = 0;            // DAT_0074bed4

extern void MeasureStringWidth(const char* text);  // FUN_0062c690

// ═══════════════════════════════════════════════════════════════════
// CalculateTextBounds (FUN_004d3dd0) — 38 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Text bounds calculation with alignment support.
// Processes string to compute width/height and applies alignment offsets.
//
// Struct layout (param_2):
//   +0x0C  flags (alignment, multi-line, scaling)
//   +0x10  x position
//   +0x14  y position
//   +0x18  output: top (adjusted Y)
//   +0x1C  output: left (adjusted X)
//   +0x20  output: right (X + text width)
//   +0x24  output: bottom (Y + text height)
//   +0x28  text string pointer
//   +0x30  line height

void CalculateTextBounds(uint32_t param_1, int param_2)
{
    char* text = *reinterpret_cast<char**>(param_2 + 0x28);
    uint32_t flags = *reinterpret_cast<uint32_t*>(param_2 + 0x0C);
    float lineHeight = *reinterpret_cast<float*>(param_2 + 0x30);
    float x = *reinterpret_cast<float*>(param_2 + 0x10);
    float y = *reinterpret_cast<float*>(param_2 + 0x14);
    float textWidth;
    float textHeight;
    float totalHeight = 0.0f;  // total text height (lines * lineHeight) for alignment

    if ((flags & 4) == 0)
    {
        // Single-line: measure string length via iteration
        char* ptr = text;
        char c;
        do
        {
            c = *ptr;
            ptr = ptr + 1;
        } while (c != '\0');

        textHeight = lineHeight;
        MeasureStringWidth(text);

        // Single-line text width comes from measurement
        textWidth = lineHeight;  // Ghidra artifact — reused register
    }
    else
    {
        // Multi-line: count newlines and track maximum width
        int lineCount = 0;
        float maxWidth = 0.0f;
        char* ptr = text;
        char* lastLineStart = text;
        float currentWidth = maxWidth;
        char c = *ptr;

        while (c != '\0')
        {
            ptr = ptr + 1;

            if (c == '\n')
            {
                float measuredWidth = *reinterpret_cast<float*>(param_2 + 0x30);
                MeasureStringWidth(text);

                if (measuredWidth <= currentWidth)
                {
                    measuredWidth = currentWidth;
                }

                maxWidth = measuredWidth;
                lineCount = lineCount + 1;
                lastLineStart = ptr;
            }

            currentWidth = maxWidth;
            c = *ptr;
        }

        // Measure final line
        float finalWidth = *reinterpret_cast<float*>(param_2 + 0x30);
        MeasureStringWidth(text);

        if (finalWidth <= currentWidth)
        {
            finalWidth = currentWidth;
        }

        textHeight = finalWidth;

        // If text ends with newline, don't count the trailing empty line
        if ((lastLineStart < ptr) && (ptr[-1] == '\n'))
        {
            lineCount = lineCount - 1;
        }

        // Total height = line count * line height
        totalHeight = static_cast<float>(lineCount) * *reinterpret_cast<float*>(param_2 + 0x30);
    }

    // Determine scale factor based on flags
    float scaleFactor = g_defaultScaleFactor;
    if ((flags & 0x1000000) != 0)
    {
        scaleFactor = g_altScaleFactor;
    }

    // Apply vertical scaling
    float adjustedY = y;
    if ((static_cast<int>(flags) < 0) && (y < 0.0f))
    {
        adjustedY = scaleFactor * y + g_one;
    }

    // Apply vertical alignment
    if ((flags & 0x10000000) == 0)
    {
        if ((flags & 0x20000000) == 0)
        {
            if ((flags & 0x40000000) != 0)
            {
                // Bottom-aligned: offset by screen height ratio
                adjustedY = adjustedY - (scaleFactor / g_invScreenHeight) * static_cast<float>(g_screenHeight);
            }
        }
        else
        {
            // Center-aligned vertically
            adjustedY = adjustedY - totalHeight * g_half;
        }
    }
    else
    {
        // Top-aligned (no offset needed beyond start)
        adjustedY = adjustedY - totalHeight;
    }

    // Apply horizontal alignment
    if ((flags & 0x4000000) == 0)
    {
        if ((flags & 0x8000000) != 0)
        {
            // Center-aligned horizontally
            x = x - textHeight * g_half;
        }
    }
    else
    {
        // Right-aligned
        x = x - textHeight;
    }

    // Store computed bounds
    *reinterpret_cast<float*>(param_2 + 0x18) = adjustedY;
    *reinterpret_cast<float*>(param_2 + 0x1C) = x;
    *reinterpret_cast<float*>(param_2 + 0x24) = adjustedY + totalHeight;
    *reinterpret_cast<float*>(param_2 + 0x20) = x + textHeight;
}

} // namespace Giants
