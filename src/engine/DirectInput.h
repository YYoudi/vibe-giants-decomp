// Giants Engine - DirectInput Initialization
// Reverse engineered from GiantsMain.exe v1.520.59
//
// FUN_0062a420 — InitializeDirectInput
// Creates DirectInput8 interface, keyboard, mouse, and controller devices.
// Uses standard DI8 COM vtable dispatch (not Ansi variants).
//
// Global layout:
//   DAT_00727e58 = g_pControllers     — IDirectInputDevice8W*[100] array
//   DAT_00727e5c = g_pMouseDevice     — mouse IDirectInputDevice8W*
//   DAT_00727f20 = g_pDI              — IDirectInput8W* master interface
//   DAT_00727f24 = g_pGamepadDevice   — gamepad IDirectInputDevice8W*
//   DAT_00727f28 = g_dwMouseBufferSize — custom format size (0x2C = 44)
//   DAT_00702b04 = g_nControllerCount  — controller enable flag
//   DAT_007281d0 = g_lastResult       — last DI HRESULT
//   DAT_007281d8 = g_hWnd             — main window handle
//   DAT_007282c0 = g_bClipCursor      — cursor clip mode (0=clip, 1=capture)

#pragma once

#include <windows.h>
#include <dinput.h>

namespace Giants {

// ─── DirectInput Globals ──────────────────────────────────────

extern IDirectInput8W*        g_pDI;               // DAT_00727f20 — master DI8 interface
extern IDirectInputDevice8W*  g_pKeyboardDevice;    // DAT_00727e5c (created via DAT_00727f20 path)
extern IDirectInputDevice8W*  g_pMouseDevice;       // DAT_00727e5c (second device on same slot or separate)
extern IDirectInputDevice8W*  g_pGamepadDevice;     // DAT_00727f24 — gamepad device
extern IDirectInputDevice8W*  g_pControllers[100];  // DAT_00727e58 — device array (100 entries)
extern int    g_nControllerCount;                   // DAT_00702b04 — controller enable flag
extern DWORD  g_dwMouseBufferSize;                  // DAT_00727f28 — custom gamepad format obj size
extern int    g_bClipCursor;                        // DAT_007282c0 — 0=ClipCursor, 1=SetCapture
extern HRESULT g_lastResult;                        // DAT_007281d0 — last DI HRESULT
extern HWND   g_hWnd;                               // DAT_007281d8 — main window handle
extern BYTE   g_gamepadState[0x5CC];               // Gamepad state buffer (1484 bytes)
extern DIDATAFORMAT g_customGamepadFormat;          // Custom gamepad data format (17 objects)

// ─── Functions ────────────────────────────────────────────────

/// Initialize DirectInput8: create DI interface, keyboard, mouse, controllers.
/// Called by InitializeEngine during startup (FUN_0062e1a0).
/// @return 1 always (game continues even on partial failure)
int InitializeDirectInput();       // FUN_0062a420

/// Shutdown DirectInput: release all devices and DI interface.
void ShutdownDirectInput();        // FUN_00629a50

/// Show error dialog / log message (used by DI init failure path).
void ShowErrorDialog(const char* msg);  // FUN_0062edc0

} // namespace Giants
