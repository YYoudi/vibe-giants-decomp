// Giants Engine - Menu Text Rendering Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
// re-agent verdict: FAIL (usable ~80%)
#include "MenuTextRender.h"
#include "CRTStubs.h"

namespace Giants {

// ─── Forward declarations for callees ──────────────────────────
extern void SelectFont(int fontId);           // FUN_005d9ee0
extern void SetTextPosition(int x, int y);    // FUN_005d9f60
extern void SetTextColor(uint32_t color);     // FUN_005d9fc0
extern void SetTextAlignment(int align);      // FUN_005da040
extern void DrawTextString(const char* text); // FUN_005da0b0
extern int  GetTextWidth(const char* text);   // FUN_005da120
extern int  GetTextHeight(const char* text);  // FUN_005da180
extern void ApplyTextEffect(int effect);      // FUN_005da220
extern void FlushTextBatch();                 // FUN_005da2e0
extern void ResetTextState();                 // FUN_005da340

// ═══════════════════════════════════════════════════════════════════
// RenderMenuText (FUN_005da470) — 27 callers — FAIL (usable ~80%)
// ═══════════════════════════════════════════════════════════════════
// Complex menu/UI text rendering. Selects font from menuObj,
// applies layout, color, alignment, then draws text string.
// 10 callees — partially reconstructed from FAIL output.

void RenderMenuText(int* menuObj, int textEntry, int x, int y)
{
    // Extract font ID from menu object
    int fontId = menuObj[2];
    SelectFont(fontId);

    // Get text string from textEntry
    const char* text = *reinterpret_cast<const char**>(textEntry + 0x08);
    if (text == nullptr)
        return;

    // Apply position
    SetTextPosition(x, y);

    // Apply color from menu object
    uint32_t color = *reinterpret_cast<uint32_t*>(menuObj + 3);
    SetTextColor(color);

    // Apply alignment from text entry
    int alignment = *reinterpret_cast<int*>(textEntry + 0x10);
    SetTextAlignment(alignment);

    // Apply text effect if present
    int effect = *reinterpret_cast<int*>(textEntry + 0x14);
    if (effect != 0)
    {
        ApplyTextEffect(effect);
    }

    // Draw the text
    DrawTextString(text);

    // Flush batch if menu flag set
    if ((menuObj[5] & 0x01) != 0)
    {
        FlushTextBatch();
    }

    ResetTextState();
}

} // namespace Giants
