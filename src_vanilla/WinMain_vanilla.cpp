// Giants Vanilla-Native Recomp — entry point.
// Canonical target: vanilla 1.0 Giants.exe (2574 functions, DX7 renderer).
// This WinMain is the vanilla WinMain structure (FUN_005222c0, fused
// InitializeEngine + MainGameLoop in vanilla) adapted for the recomp.
// Callees are stubbed until ported from vanilla_decompiled/*.json.
#include <windows.h>
#include <cstdio>
#include "VanillaVFS.h"
#include "VanillaFileIO.h"
#include "VanillaAudio.h"
#include "VanillaGTI.h"
#include "VanillaGBS.h"
#include "VanillaBinLoader.h"
#include "VanillaText.h"
#include "VanillaTGA.h"
#include "VanillaFeed.h"
#include "VanillaInput.h"
#include "VanillaTextureLoad.h"
#include "VanillaTerrain.h"
// Scene list-management ports (defined in VanillaSceneLists.cpp).
extern "C" void FUN_004b77f0(void);   // WorldList.bin reader → level table
extern "C" void FUN_004290f0(uint32_t);   // scene-pipeline gate activator (DAT_0058c15c)
extern "C" void* SpawnTestEntity(uint32_t typeId, float x, float y, float z); // test entity into g_PlacedObjectList

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
extern "C" void VanillaDumpWrapperVtable(void);
extern "C" int VanillaRunFrame(int frameState);
extern "C" void VanillaDriveFrame(void (*drawHook)(void));   // manual BeginScene→hook→EndScene→Present
extern "C" void VanillaTestSurfaceVisible(void);              // GetDC(obj+0x288) + FillRect — surface visibility test

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
            VanillaDumpWrapperVtable();
        }
    }

    // ── DirectInput 7 init (FUN_0051ede0 port: keyboard + mouse, DI7 fallback DI3) ──
    {
        bool inOk = VanillaInput_Init(g_vHWnd);
        if (g_vTrace) { fprintf(g_vTrace, "[VANILLA] DirectInput7 init: %s\n", inOk ? "OK (keyboard+mouse acquired)" : "FAILED"); fflush(g_vTrace); }
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

    // ── VFS data-layer self-test (load a real GZP archive) ──
    // Validates the GZP reader (header parse + LZ decompress) against vanilla assets.
    VanillaVFS::SelfTest("Bin\\w_intro_island.gzp");
    // ── Engine file I/O self-test (open WorldList.bin loose + a GZP file) ──
    VanillaFileIO::SelfTest();
    // ── Audio subsystem loader (FUN_0051f900 port: load gs_ds.dll + resolve SDV/MDV/VDV exports) ──
    VanillaAudio::Load("ds");
    // ── GTI terrain parser self-test (parse intro_island.gti heightfield) ──
    VanillaGTI::SelfTest();
    // ── GBS model parser self-test (parse intro_1.gbs mesh) ──
    VanillaGBS::SelfTest();
    // ── TGA texture parser self-test (parse intro_sea.tga) ──
    VanillaTGA::SelfTest();
    // ── Localized-text lookup (callback[11] GetLocalizedString: GTextEnglish.bin) ──
    if (VanillaText::Load("English")) {
        if (g_vTrace) { fprintf(g_vTrace, "[VANILLA] text lookup '$IDnew' = '%s'\n", VanillaText::Lookup("$IDnew")); fflush(g_vTrace); }
    }
    // ── WorldList reader (FUN_004b77f0: reads worldlist*.bin → level table) ──
    FUN_004b77f0();
    // ── Activate the scene-pipeline gate (FUN_004290f0(1) → g_ScenePipelineGate=1).
    // The renderer's callback[20] (FUN_00523aa0) checks this gate each frame to drive
    // the scene dispatch. (Entities still need vtables via object_create_child to draw.)
    FUN_004290f0(1);
    // ── Spawn a test entity into g_PlacedObjectList (stub vtable) to prove the dispatch
    // walk is connected end-to-end (the stub Render logs when the renderer dispatches it).
    SpawnTestEntity(1, 0.0f, 0.0f, 0.0f);
    // ── .BIN level loader self-test (FUN_004b7c50 port: parse w_intro_island.bin) ──
    // NOTE: body alignment under fix by subagent; may loop on garbage count — last so it
    // doesn't block the other self-tests if it hangs.
    VanillaBinLoader::SelfTest();

    // ── Feed the level's texture list to the renderer (FUN_004b7c50 sub-path:
    //    SEEK header[1] name_list → FUN_0050d8f0 populates g_TextureEntityList →
    //    SceneWalk_Textures dispatches each entry to renderer slot +0xb4).
    //    This is the recipe from RE_docs/OBJECT_VTABLE_SYSTEM.md §7. After this
    //    the original gg_dx7r.dll should build its scene-entities internally.
    VanillaFeedTextures();

    // ── Load pixel data for every texture entry (FUN_0050dd20 port). After
    //    VanillaFeedTextures populates g_TextureEntityList, this parses each
    //    entry's .tga/.dds from the level GZP and stores the pixel buffer at
    //    entry+0x04 (+ format/mip fields). NOTE: this does NOT by itself create
    //    the renderer surface / link-node at entry+0x08 — that is done by the
    //    renderer's slot +0xb0 (driven by the per-entity texture-bind walk at
    //    VA 0x4f3c20). It DOES supply the pixel data that slot +0xb0 uploads.
    VanillaLoadAllTextures();
    // NOTE: terrain draw (VanillaTerrain_Draw) parses the GTI + builds a triangle grid OK,
    // but SEGFAULTS when submitted to renderer slot +0x98 standalone — the renderer must be
    // in-scene (BeginScene called). Must be injected INTO the renderer's frame cycle
    // (between BeginScene and Present, e.g. via the scene-walk callback) — TODO.

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
        // Per-frame input poll (DirectInput7 keyboard + mouse — FUN_0051f0e0/1f0 port).
        VanillaInput_Poll();
        // Manual frame driver with CORRECT present: SetRT(obj+0x28c) → BeginScene → draw → EndScene → Flip(obj+0x28c vt[0x68]).
        VanillaDriveFrame(nullptr);  // no draw hook for first test — just the present cycle
        int newState = 0;
        if (frameCount < 3) {
            if (g_vTrace) { fprintf(g_vTrace, "[VANILLA] frame %d: DriveFrame(SetRT+Flip)\n", frameCount); fflush(g_vTrace); }
        }
        frameCount++;
    }

    if (g_vTrace) { fprintf(g_vTrace, "[VANILLA] Exit\n"); fflush(g_vTrace); }
    VanillaInput_Fini();
    return (int)msg.wParam;
}
