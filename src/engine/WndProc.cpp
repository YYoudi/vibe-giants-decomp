// Giants Engine - Window Procedure Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
//
// FUN_0062ea70 — WndProc
// Original uses hardcoded memory addresses (0x0068xxxx, 0x0070xxxx).
// Standalone version uses our named globals instead.
//
// Phase 1: Minimal safe WndProc — handles basic messages without crashing.
//          Will be progressively replaced with RE'd logic as globals are mapped.

#include "WndProc.h"
#include "GameLoop.h"
#include "TraceLog.h"

#include <windows.h>

namespace Giants {

// ─── Global state ─────────────────────────────────────────────
// g_bClipCursor is defined in DirectInput.cpp (canonical)
BOOL     g_bActive         = 1;      // DAT_007282d0
BOOL     g_bRenderReady    = 0;      // DAT_007281d4
BOOL     g_bPaused         = 0;      // DAT_00702aed
HMONITOR g_hCurrentMonitor = nullptr;// DAT_0074c46c

// ─── Stub implementations for WndProc helpers ─────────────────
void OnDisplayChange() {}            // FUN_0062a2d0
uint32_t OnActivateApp(uint32_t) { return 0; } // FUN_0062ea10
void OnResize(int, int, int) {}      // FUN_004f8210

// ═══════════════════════════════════════════════════════════════
// WndProc — SAFE MINIMAL VERSION for standalone exe
// ═══════════════════════════════════════════════════════════════
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_GETMINMAXINFO:
    {
        MINMAXINFO* mmi = reinterpret_cast<MINMAXINFO*>(lParam);
        mmi->ptMinTrackSize.x = 300;
        mmi->ptMinTrackSize.y = 300;
        return 0;
    }

    case WM_DESTROY:
    {
        TRACE_FUNC;
        g_shutdownRequested = 1;
        PostQuitMessage(0);
        return 0;
    }

    case WM_SIZE:
        if (wParam == SIZE_MINIMIZED)
            g_bActive = 0;
        else
            g_bActive = 1;
        break;

    case WM_ACTIVATE:
    {
        TRACE_ENTER;
        // Only handle if renderer is ready
        if (!g_bRenderReady) break;
        // TODO: vtable dispatch to renderer when implemented
        break;
    }

    case WM_ACTIVATEAPP:
        TRACE_ENTER;
        g_bPaused = (wParam == 0);
        break;

    case WM_SETCURSOR:
        if (g_bActive && g_bClipCursor)
        {
            SetCursor(nullptr);
            return 1;
        }
        break;

    case WM_SYSCOMMAND:
        // Block screensaver / monitor off
        if (wParam == 0xf140 || wParam == 0xf170) // SC_SCREENSAVE, SC_MONITORPOWER
            return 1;
        break;

    case WM_CHAR:
        // TODO: keyboard ring buffer — needs global mapping
        break;

    case WM_SYSKEYDOWN:
        // Block ALT+Tab
        if (wParam == 0x12) return 1;
        break;
    }

    return DefWindowProcA(hWnd, msg, wParam, lParam);
}

} // namespace Giants
