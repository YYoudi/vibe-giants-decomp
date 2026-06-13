// Giants Engine - Window Procedure
// Reverse engineered from GiantsMain.exe v1.520.59
//
// FUN_0062ea70 — WndProc (FAIL, code extracted at ~95%)
// Main window procedure for the GiantsWinClass window.
// Handles: WM_DESTROY, WM_ACTIVATE, WM_DISPLAYCHANGE, WM_CHAR,
//          WM_SETCURSOR, WM_GETMINMAXINFO, WM_MOVING, WM_SIZING,
//          WM_ENTERSIZEMOVE, WM_EXITSIZEMOVE, WM_SYSCOMMAND

#pragma once

#include <windows.h>
#include <cstdint>

namespace Giants {

/// Main window procedure registered with RegisterClassA("GiantsWinClass").
/// Dispatches Windows messages to engine subsystems.
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);  // FUN_0062ea70

// ─── OnDisplayChange (FUN_0062a2d0) — PASS ──────────────────────
// Zeroes all input/mouse/controller state globals (DAT_00727fdc..DAT_00727f1c).
// Called on WM_DISPLAYCHANGE to reset input state for new display mode.
// 9 callers, 0 callees — trivial memset-like function.
void OnDisplayChange();           // FUN_0062a2d0

// ─── OnActivateApp (FUN_0062ea10) — PASS ────────────────────────
// Handles WM_ACTIVATEAPP: updates activation counter DAT_007282b8,
// sets DAT_007282cc (zero when balanced), optionally calls vtable[0x88]
// (device lost handling), and triggers UpdateTime when balanced.
// 3 callers, 1 callee (UpdateTime).
uint32_t OnActivateApp(uint32_t isActivating);  // FUN_0062ea10

// ─── OnResize (FUN_004f8210) — PASS ────────────────────────────
// Handles WM_SIZE/WM_EXITSIZEMOVE: updates window mode globals,
// compares display settings (12-byte memcmp), calls InitDisplaySettings,
// reinitializes display mode and scene. 9 callees.
void OnResize(int fullscreen, int width, int height);  // FUN_004f8210

// Cursor clip state
extern BOOL  g_bClipCursor;       // DAT_007282c0 — fullscreen vs windowed
extern BOOL  g_bActive;           // DAT_007282d0 — window is active
extern BOOL  g_bRenderReady;      // DAT_007281d4 — renderer initialized
extern BOOL  g_bPaused;           // DAT_00702aed — app paused (WM_ACTIVATE)
extern HMONITOR g_hCurrentMonitor;// DAT_0074c46c — current monitor handle

} // namespace Giants
