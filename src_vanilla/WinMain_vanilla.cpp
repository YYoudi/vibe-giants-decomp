// Giants Vanilla-Native Recomp — entry point.
// Canonical target: vanilla 1.0 Giants.exe (2574 functions, DX7 renderer).
// This WinMain is the vanilla WinMain structure (FUN_005222c0, fused
// InitializeEngine + MainGameLoop in vanilla) adapted for the recomp.
// Callees are stubbed until ported from vanilla_decompiled/*.json.
#include <windows.h>
#include <cstdio>

// Vanilla globals (DAT_ addresses from vanilla binary, 0x5DXXXX = .data)
// Declared as named globals — will be populated as functions are ported.
static FILE* g_vTrace = nullptr;
static HWND  g_vHWnd = nullptr;
static HINSTANCE g_vHInst = nullptr;
static bool g_vRunning = true;

// ─── Vanilla WinMain (FUN_005222c0) — structure ported from decompiled ──
// The vanilla binary fuses InitializeEngine + MainGameLoop into this one
// function. In 1.5 they were split (InitializeEngine 0x62e1a0 + MainGameLoop
// 0x62d100). The vanilla version is 2339 bytes, 77 callees.
LRESULT CALLBACK VanillaWndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {
    return DefWindowProcA(hWnd, msg, wp, lp);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR lpCmdLine, int nCmdShow) {
    g_vTrace = fopen("vanilla_trace.log", "w");
    if (g_vTrace) { fprintf(g_vTrace, "[VANILLA] GiantsRE vanilla-native recomp — entry\n"); fflush(g_vTrace); }
    g_vHInst = hInstance;

    // ── RegisterClass (vanilla strings: AppAccel, AppIcon, AppMenu, "Giants") ──
    WNDCLASSA wc = {};
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = VanillaWndProc;
    wc.hInstance = hInstance;
    wc.hCursor = LoadCursorA(nullptr, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    wc.lpszClassName = "Giants";
    ATOM atom = RegisterClassA(&wc);
    if (!atom) { if (g_vTrace) { fprintf(g_vTrace, "[VANILLA] RegisterClass failed\n"); fflush(g_vTrace); } return 1; }

    // ── CreateWindow ──
    g_vHWnd = CreateWindowExA(0, "Giants", "Giants: Citizen Kabuto",
        WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 1280, 720,
        nullptr, nullptr, hInstance, nullptr);
    if (!g_vHWnd) { if (g_vTrace) { fprintf(g_vTrace, "[VANILLA] CreateWindow failed\n"); fflush(g_vTrace); } return 1; }
    ShowWindow(g_vHWnd, nCmdShow);
    if (g_vTrace) { fprintf(g_vTrace, "[VANILLA] Window created hwnd=%p\n", g_vHWnd); fflush(g_vTrace); }

    // ── Engine init (callees stubbed — port from vanilla_decompiled/*.json) ──
    // The vanilla WinMain (0x5222c0) calls ~50 functions here including:
    //   - Registry open (DefPlayer, MusicVolume, SoundVolume)
    //   - Renderer load (UpCallsLoad 21 callbacks + GDVSysCreate NULL engineCtx)
    //   - Audio init (gs_ds.dll)
    //   - DirectInput
    //   - Level load (intro_island)
    //   - Game loop (message pump + ProcessRawKeyboardInput + ProcessGameLogic)
    // Each callee ported cycle by cycle from vanilla_decompiled/.
    if (g_vTrace) { fprintf(g_vTrace, "[VANILLA] Engine init stubs (renderer/audio/input/level not yet ported)\n"); fflush(g_vTrace); }

    // ── Message pump (game loop) ──
    MSG msg;
    while (g_vRunning) {
        while (PeekMessageA(&msg, nullptr, 0, 0, PM_REMOVE)) {
            if (msg.message == WM_QUIT) { g_vRunning = false; break; }
            TranslateMessage(&msg);
            DispatchMessageA(&msg);
        }
        if (!g_vRunning) break;
        // Per-frame game logic (ProcessGameLogic etc.) — stubbed.
    }

    if (g_vTrace) { fprintf(g_vTrace, "[VANILLA] Exit\n"); fflush(g_vTrace); }
    return (int)msg.wParam;
}
