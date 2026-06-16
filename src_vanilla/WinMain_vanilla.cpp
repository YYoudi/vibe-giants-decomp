// Giants Vanilla-Native Recomp — entry point.
// Canonical target: vanilla 1.0 Giants.exe (2574 functions, DX7 renderer).
// This WinMain is the vanilla WinMain structure (FUN_005222c0, fused
// InitializeEngine + MainGameLoop in vanilla) adapted for the recomp.
// Callees are stubbed until ported from vanilla_decompiled/*.json.
#include <windows.h>
#include <cstdio>

// Vanilla globals (DAT_ addresses from vanilla binary, 0x5DXXXX = .data)
// Declared as named globals — will be populated as functions are ported.
FILE* g_vTrace = nullptr;
const char* __lpCmdLine = nullptr;
static HWND  g_vHWnd = nullptr;
static HINSTANCE g_vHInst = nullptr;
static bool g_vRunning = true;

extern "C" int VanillaLoadRenderer(const char* pathPrefix, const char* rendererName);
extern "C" void* VanillaInitRenderer(HWND hWnd);
extern "C" void VanillaReadDisplayConfig();
extern "C" int VanillaRunFrame(int frameState);

// ─── Vanilla WinMain (FUN_005222c0) — structure ported from decompiled ──
// The vanilla binary fuses InitializeEngine + MainGameLoop into this one
// function. In 1.5 they were split (InitializeEngine 0x62e1a0 + MainGameLoop
// 0x62d100). The vanilla version is 2339 bytes, 77 callees.
LRESULT CALLBACK VanillaWndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {
    return DefWindowProcA(hWnd, msg, wp, lp);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR lpCmdLine, int nCmdShow) {
    __lpCmdLine = lpCmdLine;
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
    wc.lpszClassName = "Example";  // vanilla: class name = "Example" (s_Example_0057fb64)
    ATOM atom = RegisterClassA(&wc);
    if (!atom) { if (g_vTrace) { fprintf(g_vTrace, "[VANILLA] RegisterClass failed\n"); fflush(g_vTrace); } return 1; }

    // ── CreateWindow ──
    // Vanilla: CreateWindowExA(0x40000, "Example", "Giants", 0x6CF0000, CW_USEDEFAULT, ...)
    // 0x6CF0000 = WS_CLIPSIBLINGS|WS_CLIPCHILDREN|WS_CAPTION|WS_SYSMENU|WS_THICKFRAME|WS_MINIMIZEBOX|WS_MAXIMIZEBOX
    g_vHWnd = CreateWindowExA(0x40000, "Example", "Giants",
        0x06CF0000, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
        nullptr, nullptr, hInstance, nullptr);
    if (!g_vHWnd) { if (g_vTrace) { fprintf(g_vTrace, "[VANILLA] CreateWindow failed\n"); fflush(g_vTrace); } return 1; }
    ShowWindow(g_vHWnd, nCmdShow);
    if (g_vTrace) { fprintf(g_vTrace, "[VANILLA] Window created hwnd=%p\n", g_vHWnd); fflush(g_vTrace); }

    // ── Registry setup (the vanilla init chain does this before GDVSysCreate) ──
    // The DX7 renderer reads HKCU\Software\PlanetMoon\Giants for display settings.
    HKEY hKey;
    DWORD disp;
    if (RegCreateKeyExA(HKEY_CURRENT_USER, "Software\\PlanetMoon\\Giants", 0, nullptr, 0,
                        KEY_ALL_ACCESS, nullptr, &hKey, &disp) == ERROR_SUCCESS) {
        DWORD w = 640, h = 480, win = 1;
        RegSetValueExA(hKey, "Renderer", 0, REG_SZ, (BYTE*)"gg_dx7r.dll", 11);
        RegSetValueExA(hKey, "VideoWidth", 0, REG_DWORD, (BYTE*)&w, 4);
        RegSetValueExA(hKey, "VideoHeight", 0, REG_DWORD, (BYTE*)&h, 4);
        RegSetValueExA(hKey, "Windowed", 0, REG_DWORD, (BYTE*)&win, 4);
        RegCloseKey(hKey);
        if (g_vTrace) { fprintf(g_vTrace, "[VANILLA] Registry set (640x480 windowed)\n"); fflush(g_vTrace); }
    }

    // ── Engine init: load the DX7 renderer (FUN_0051eb70) ──
    int renderOk = VanillaLoadRenderer(nullptr, "dx7r");
    if (g_vTrace) { fprintf(g_vTrace, "[VANILLA] Renderer load: %s\n", renderOk ? "OK" : "FAILED"); fflush(g_vTrace); }
    if (renderOk) {
        void* device = VanillaInitRenderer(g_vHWnd);
        if (g_vTrace) { fprintf(g_vTrace, "[VANILLA] DX7 device: %p\n", device); fflush(g_vTrace); }
        if (device) {
            // Vanilla WinMain next step: read the current display config (method [0x1b]=0xc970).
            // Methods are __cdecl(this-as-first-arg) per disasm — VanillaReadDisplayConfig handles that.
            VanillaReadDisplayConfig();
        }
    }

    // Remaining init (callees stubbed — port from vanilla_decompiled/*.json):
    //   - Registry open (DefPlayer, MusicVolume, SoundVolume)
    //   - Renderer load (UpCallsLoad 21 callbacks + GDVSysCreate NULL engineCtx)
    //   - Audio init (gs_ds.dll)
    //   - DirectInput
    //   - Level load (intro_island)
    //   - Game loop (message pump + ProcessRawKeyboardInput + ProcessGameLogic)
    // Each callee ported cycle by cycle from vanilla_decompiled/.
    if (g_vTrace) { fprintf(g_vTrace, "[VANILLA] Engine init stubs (renderer/audio/input/level not yet ported)\n"); fflush(g_vTrace); }

    // ── Message pump (game loop) ──
    // Vanilla WinMain loop core: frameState = (*obj[0x20])(obj, frameState) per iteration
    // (renderer method 0x7370 = per-frame render entry). We reproduce it; frameState=1
    // (the "rendering" state). Limited logging to avoid spam.
    MSG msg;
    int frameState = 1;
    int frameCount = 0;
    while (g_vRunning) {
        while (PeekMessageA(&msg, nullptr, 0, 0, PM_REMOVE)) {
            if (msg.message == WM_QUIT) { g_vRunning = false; break; }
            TranslateMessage(&msg);
            DispatchMessageA(&msg);
        }
        if (!g_vRunning) break;
        // Per-frame render driver (vanilla method [0x20]).
        int newState = VanillaRunFrame(frameState);
        if (frameCount < 5) {
            if (g_vTrace) { fprintf(g_vTrace, "[VANILLA] frame %d: state %d -> %d\n", frameCount, frameState, newState); fflush(g_vTrace); }
        }
        frameState = newState;
        frameCount++;
    }

    if (g_vTrace) { fprintf(g_vTrace, "[VANILLA] Exit\n"); fflush(g_vTrace); }
    return (int)msg.wParam;
}
