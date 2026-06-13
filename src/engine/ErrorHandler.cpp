// Giants Engine - Error Dialog Handler Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
//
// FUN_0062edc0 — Error display with in-game rendering + MessageBox fallback.
// 104 callers, 21 callees. This is called whenever the game encounters
// a fatal/non-fatal error during gameplay.

#include "ErrorHandler.h"
#include "Input.h"
#include "Timer.h"
#include "TimerTick.h"
#include "ScenePipeline.h"

namespace Giants {

// ─── External data references ─────────────────────────────────

static char   DAT_00702bdd = 0;          // Some init check flag
static uint32_t DAT_006ff960 = 0;        // Game state (6 = running?)
static uint32_t DAT_00702964 = 0;        // Another state flag
static uint32_t DAT_00702924 = 0;        // Renderer mode (3..8 range)
static char    DAT_0074da60 = 0;         // Error exit requested flag
static char    DAT_0074da64 = 0;         // Error dialog active flag
static void*   DAT_007281d4 = nullptr;   // Window handle or similar
static uint32_t DAT_007281e4 = 0;        // Exit flag
static void*   DAT_007281d8 = nullptr;   // HWND of game window
static char    DAT_00702c07 = 0;         // Key pressed: Enter
static char    DAT_00702c08 = 0;         // Key pressed: Escape
static uint32_t DAT_0074bbb8 = 0;        // RenderDoc capture function ptr

// Font/glyph rendering data
static float   DAT_0066bd58 = 0;         // Font line height
static float   DAT_0066bdf4 = 0;         // Text Y start position
static float   DAT_0066bd98 = 0;         // Title text Y position
static float   DAT_0066bda8 = 0;         // Subtitle text Y position
static float   DAT_0066beec = 0;         // "Enter" text Y position
static float   DAT_0066befc = 0;         // "Escape" text Y position
static float   _DAT_0074beb4 = 0;        // Screen scale factor
static uint32_t DAT_0074bed4 = 0;        // Screen X offset
static uint32_t DAT_007028a4 = 0;        // Font scale multiplier
static uint8_t  DAT_0074bf0e[256 * 5] = {0}; // Glyph width table

// ─── Helper: Render text line with glyph width calculation ────
// Each character's width is looked up from DAT_0074bf0e at index (char*5).
// Text is positioned using screen scale factors.

static void RenderTextLine(const char* text, int maxChars, float yPosition)
{
    float charScale = ((float)DAT_007028a4 * DAT_0066bd58) / _DAT_0074beb4;
    float xAdvance = 0.0f;

    // FUN_0062c1b0 — set font/text rendering state
    // FUN_0062c420 — draw text at position with computed width

    for (int i = maxChars; i > 0; i--) {
        if (*text == '\0') break;
        if (xAdvance != 0.0f) {
            xAdvance += charScale;
        }
        int glyphIndex = (uint8_t)*text * 5;
        if (glyphIndex != 0x74bf0c - 0x74bf0e) {  // Skip missing glyph
            xAdvance += (float)DAT_0074bf0e[glyphIndex] * charScale;
        }
        text++;
    }

    // FUN_0062c420 — submit text draw call
    // (DAT_0066bd58 / _DAT_0074beb4 * DAT_0074bed4 + yPosition, charCount)
}

// ─── ShowErrorDialog (FUN_0062edc0) — FAIL (usable ~75%) ──────

void ShowErrorDialog(uint32_t param_1, uint32_t param_2)
{
    char local_1010[4096];  // Error message buffer
    local_1010[0] = '\0';

    // FUN_00462fc0 — format error message from param_1/param_2
    // Copies error string into local_1010

    // Guard: show error when game is NOT in normal running state
    // (DAT_00702bdd==0 || DAT_006ff960!=6 || DAT_00702964==0) means error condition
    bool errorCondition = (DAT_00702bdd == 0 || DAT_006ff960 != 6 || DAT_00702964 == 0);
    bool properMode = (DAT_00702924 - 3 > 8 || DAT_00702924 == 6);
    bool notAlreadyShown = (DAT_0074da60 == 0);

    if (errorCondition && properMode && notAlreadyShown) {

        if (DAT_0074da64 == 0 && DAT_007281d4 != 0) {
            DAT_0074da64 = 1;  // Mark dialog as active

            do {
                // Begin render frame
                // vtable[0xac](0) — renderer begin scene
                BeginScene();                  // FUN_004f7e60

                // FUN_005fa390 — setup 2D rendering state
                // FUN_004da6d0 — set shader constants (7 float values:
                //   0x3f7fbe77≈0.998, 0x3e0f5c29≈0.280, 0x3e19999a≈0.150,
                //   0x3f70a3d7≈0.940, 0x3f733333≈0.950, 0x3f2e147b≈0.680,
                //   0x3f333333≈0.700)

                // Render error message lines (word-wrapped from local_1010)
                // Each line is rendered via RenderTextLine pattern

                // Render title: "Giants: Citizen Kabuto" (22 chars)
                RenderTextLine("Giants: Citizen Kabuto", 0x16,
                    DAT_0066bd98);

                // Render subtitle: "Wintry Cool Game Error Screen" (29 chars)
                RenderTextLine("Wintry Cool Game Error Screen", 0x1d,
                    DAT_0066bda8);

                // Render prompt: "Enter  to Continue" (18 chars)
                RenderTextLine("Enter  to Continue", 0x12,
                    DAT_0066beec);

                // Render prompt: "Escape to Exit Game" (19 chars)
                RenderTextLine("Escape to Exit Game", 0x13,
                    DAT_0066befc);

                // End render frame
                ShutdownSubsystems(0);         // FUN_004f7f10

                // RenderDoc F12 capture check
                if (DAT_0074bbb8 != 0) {
                    uint16_t keyState = GetAsyncKeyState(0x7b);  // F12
                    if ((keyState & 1) != 0 && DAT_0074bbb8 != 0) {
                        // Trigger RenderDoc capture
                        auto captureFn = *(void(__cdecl**)(void))(DAT_0074bbb8 + 0x3c);
                        captureFn();
                        // FUN_00461f00 — debug log
                    }
                }

                // vtable[0xbc]() — renderer present/end frame

                // Poll input while waiting for user response
                ProcessRawKeyboardInput();     // FUN_0062aac0
                ProcessMouseInput();           // FUN_0062abe0
                TimerTick();                   // FUN_004ad640

                // Check if Escape was pressed → exit
                if (DAT_00702c08 != 0)
                    goto exit_error;

            } while (DAT_00702c07 == '\0');  // Loop until Enter pressed

            DAT_007281e4 = 1;   // Mark continue
            DAT_0074da60 = 1;   // Mark error handled

        exit_error:
            // Final render frame + RenderDoc check
            // vtable[0xac](0) — begin scene
            // vtable[0xbc]() — present
            ;
        }
        else {
            // Fallback: no renderer available, use MessageBoxA
            // FUN_0062ea10 — show/hide cursor
            SetWindowPos((HWND)DAT_007281d8, (HWND)0xfffffffe, 0, 0, 0, 0,
                         SWP_NOMOVE | SWP_NOSIZE);  // HWND_TOPMOST
            int result = MessageBoxA(nullptr, local_1010, "Giants Error",
                                      MB_ABORTRETRYIGNORE);
            SetWindowPos((HWND)DAT_007281d8, nullptr, 0, 0, 0, 0,
                         SWP_NOMOVE | SWP_NOSIZE);  // HWND_NOTOPMOST
            // FUN_0062ea10 — restore cursor

            if (result == IDCANCEL || result == IDABORT) {
                DAT_007281e4 = 1;   // Exit
                DAT_0074da60 = 1;
            }
        }
        DAT_0074da64 = 0;  // Clear dialog active flag
    }
}

// ═══════════════════════════════════════════════════════════════════
// DrawTextString (FUN_0062c690) — 69 callers, 33 lines
// ═══════════════════════════════════════════════════════════════════
// Renders a string of text characters one by one using glyph data.
// Uses glyph table at DAT_0074bf0e (5-byte entries per character),
// scales by display DPI (DAT_007028a4 / DAT_0074beb4).
// Calls FUN_0062c1b0 (SetFontState) to set rendering state, then
// advances horizontal cursor by glyph width for each character.

void DrawTextString(uint8_t* param_1, int param_2)
{
    // Compute character advance width from display scale
    float charWidth = (static_cast<float>(DAT_007028a4) * 0.0f /* in_XMM0 */) /
                      1.0f /* DAT_0074beb4 */;

    // FUN_0062c1b0() — SetFontState (set up text rendering state)

    float cursorX = 0.0f;
    while (true) {
        if (param_2 < 1) return;
        param_2--;

        if (*param_1 == 0) break;  // Null terminator

        if (cursorX != 0.0f) {
            cursorX += charWidth;  // Advance cursor
        }

        // Look up glyph data for this character
        int glyphIndex = static_cast<uint8_t>(*param_1) * 5;
        if (glyphIndex != -0x74bf0c) {  // Check for special character
            float glyphAdvance = static_cast<float>(DAT_0074bf0e[glyphIndex]) * charWidth;
            (void)glyphAdvance;
            // Render glyph at cursorX position
        }

        param_1++;
    }
}

} // namespace Giants
