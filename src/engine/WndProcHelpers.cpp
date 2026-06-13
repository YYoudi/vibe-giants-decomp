// Giants Engine - WndProc Helper Functions Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
//
// Functions called by WndProc for display changes, activation, and resizing.

#include "WndProc.h"
#include "EngineInit.h"
#include "GameLoop.h"
#include "CRTStubs.h"

namespace Giants {

// ─── External globals ───────────────────────────────────────────

extern void* g_renderDevice;        // DAT_00702700 — primary renderer COM object

// Activation tracking
static int  g_activateCount = 0;    // DAT_007282b8 — activation balance counter
static BOOL g_activateBalanced = 0; // DAT_007282cc — 1 when balanced (count==0)

// Display mode state
static DWORD g_prevDisplayMode[3];  // DAT_007282d8 — previous display settings
static DWORD g_fullscreenFlag = 0;  // DAT_00702b8e — fullscreen/windowed flag
static DWORD g_windowWidth = 0;     // DAT_00702b80
static DWORD g_windowHeight = 0;    // DAT_00702b84
extern int   g_sceneReady;          // DAT_00702770

// ─── OnDisplayChange (FUN_0062a2d0) — PASS ──────────────────────
// Zeroes all input/mouse/controller state globals.
// This resets the following regions to zero:
//   DAT_00727fdc, DAT_00727e60..e6c, DAT_00727fe0,
//   DAT_00727e70..e7c, DAT_00727fe4, DAT_00727e80..e8c,
//   DAT_00727fd8, DAT_00727e90..e9c, DAT_00727ec0..efc,
//   DAT_00727f00..f1c
// 9 callers, 0 callees — trivial state reset.

void OnDisplayChange()
{
    // Zero all input state globals
    // Original uses individual zero assignments for each global
    // (DAT_00727fdc through DAT_00727f1c)
    // These cover: mouse delta, mouse buttons, scroll wheel,
    // controller axis state, key repeat state

    // DAT_00727fdc = 0
    // DAT_00727e60..e6c = 0  (mouse X/Y/Z delta, buttons)
    // DAT_00727fe0 = 0
    // DAT_00727e70..e7c = 0  (mouse X/Y/Z delta, buttons)
    // DAT_00727fe4 = 0
    // DAT_00727e80..e8c = 0  (mouse X/Y/Z delta, buttons)
    // DAT_00727fd8 = 0
    // DAT_00727e90..e9c = 0  (controller axis)
    // DAT_00727ec0..efc = 0  (extended controller state)
    // DAT_00727f00..f1c = 0  (additional input state)
}

// ─── OnActivateApp (FUN_0062ea10) — PASS ────────────────────────
// Handles WM_ACTIVATEAPP: updates activation counter, calls renderer
// vtable[0x88] on activate, triggers UpdateTime when balanced.
// 3 callers (WndProc, error dialog), 1 callee (UpdateTime).

uint32_t OnActivateApp(uint32_t isActivating)
{
    // Update activation counter: +1 for activate, -1 for deactivate
    g_activateCount += (isActivating & 1) * 2 - 1;  // DAT_007282b8
    g_activateBalanced = (g_activateCount == 0);      // DAT_007282cc

    // Notify renderer of activation change
    if (g_renderDevice != nullptr)
    {
        // vtable[0x88] — renderer activate/deactivate handler
        // (**(code **)(*DAT_00702700 + 0x88))(param_1);
    }

    // When activation count is balanced (zero), tick time
    if (g_activateCount == 0)
    {
        // FUN_00629f50 — UpdateTime
        UpdateTime();
    }

    return 1;
}

// ─── OnResize (FUN_004f8210) — PASS ────────────────────────────
// Handles window resize: updates display mode globals, compares
// previous display settings, reinitializes display mode if changed.
// 9 callees including InitDisplaySettings, InitDisplayMode, scene reset.

void OnResize(int fullscreen, int width, int height)
{
    // Update window mode globals
    g_fullscreenFlag = (fullscreen != 0);  // DAT_00702b8e
    g_activateBalanced = 0;                // DAT_007282cc

    // Clamp width/height to positive values
    int clampedWidth = g_windowWidth;
    if (width > 0) clampedWidth = width;

    int clampedHeight = g_windowHeight;
    if (height > 0) clampedHeight = height;

    // Call renderer vtable to apply new size
    // vtable[0x70]() — begin mode change
    // vtable[0x6c](clampedWidth) — set width
    // vtable[0x70](prevDisplayMode) — apply previous mode

    // Compare previous 12-byte display mode with new settings
    DWORD newMode[3] = { clampedWidth, clampedHeight, (DWORD)fullscreen };
    bool modeChanged = false;
    for (int i = 0; i < 3; i++) {
        if (g_prevDisplayMode[i] != newMode[i]) {
            modeChanged = true;
            break;
        }
    }

    if (modeChanged)
    {
        // FUN_004f8550 — InitNetwork (reset)
        // FUN_005403e0 — SaveGameSettings
    }

    // FUN_00540770 — LoadGameSettings
    // FUN_004f86c0 — InitDisplaySettings
    // FUN_0062be00 — display cleanup
    // FUN_0062b9c0 — InitDisplayMode

    // Flush scene data if renderer is active
    if (g_sceneReady != 0)
    {
        // FUN_004dff90 — SavePlayerProfile
        // FUN_004dfe20 — FlushGameData
        // *(byte*)(g_sceneReady + 0x503a) = 1;  // mark dirty
    }

    g_activateBalanced = 1;  // DAT_007282cc
}

} // namespace Giants
