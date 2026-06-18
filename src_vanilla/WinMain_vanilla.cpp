// Giants Vanilla-Native Recomp — entry point.
// Canonical target: vanilla 1.0 Giants.exe (2574 functions, DX7 renderer).
// This WinMain is the vanilla WinMain structure (FUN_005222c0, fused
// InitializeEngine + MainGameLoop in vanilla) adapted for the recomp.
// Callees are stubbed until ported from vanilla_decompiled/*.json.
#include <windows.h>
#include <cstdio>
#include <cstring>
#include <cctype>
#include "VanillaBoot.h"
#include "VanillaVFS.h"
#include "VanillaFileIO.h"
#include "VanillaAudio.h"
#include "VanillaGTI.h"
#include "VanillaGBS.h"
#include "VanillaBinLoader.h"
#include "VanillaBinLoaderFull.h"   // safe SelfTest (reads .bin + validates magic)
#include "VanillaText.h"
#include "VanillaTGA.h"
#include "VanillaLoadScreen.h"
#include "VanillaFeed.h"
#include "VanillaInput.h"
#include "VanillaTextureLoad.h"
#include "VanillaTerrain.h"
// Scene list-management ports (defined in VanillaSceneLists.cpp).
extern "C" void FUN_004b77f0(void);   // WorldList.bin reader → level table
extern "C" void FUN_004290f0(uint32_t);   // scene-pipeline gate activator (DAT_0058c15c)
extern "C" void* SpawnTestEntity(uint32_t typeId, float x, float y, float z); // test entity into g_PlacedObjectList
extern "C" int VanillaSceneLoad_SelfTest(void);   // FUN_004913c0 selector self-test (scan level table)
extern "C" void FUN_004b7c50(char* name, float a2, float a3);   // .BIN loader (VanillaBinLoaderFull.cpp)
extern "C" uint32_t DAT_006316ec;   // world_state ptr (defined in VanillaStubs.cpp)
// Registry settings (VanillaSettings.cpp — port of FUN_00483740/FUN_004a3900).
extern "C" uint32_t g_videoWidth, g_videoHeight, g_videoDepth, g_windowed, g_gameOptions;
extern "C" void VanillaSettings_EnsureDefaults(void);
extern "C" void VanillaSettings_Load(void);

// Vanilla globals (DAT_ addresses from vanilla binary, 0x5DXXXX = .data)
// Declared as named globals — will be populated as functions are ported.
FILE* g_vTrace = nullptr;
const char* __lpCmdLine = nullptr;
static HWND  g_vHWnd = nullptr;
static HINSTANCE g_vHInst = nullptr;
static bool g_vRunning = true;

// ─── Boot/CLI configuration (phase-jump + test flags) ───
VanillaBootConfig g_bootCfg;

// Minimal tokenizer: matches "-flag" and "-flag value" against the dev/test flag set.
// Tokens are whitespace-delimited. Comparison is case-insensitive on the leading "-".
void VanillaParseArgs(const char* cmdLine) {
    if (!cmdLine) return;
    const char* p = cmdLine;
    auto skipWs = [](const char* q) { while (*q && isspace((unsigned char)*q)) q++; return q; };
    auto ieq = [](const char* a, const char* b) {
        while (*a && *b) { if (tolower((unsigned char)*a) != tolower((unsigned char)*b)) return false; a++; b++; } return *a == *b; };
    while (*p) {
        p = skipWs(p);
        if (!*p) break;
        // extract one token
        const char* s = p;
        while (*p && !isspace((unsigned char)*p)) p++;
        size_t len = (size_t)(p - s);
        char tok[128] = {0};
        if (len >= sizeof(tok)) len = sizeof(tok) - 1;
        memcpy(tok, s, len); tok[len] = 0;
        // match
        if (tok[0] != '-' && tok[0] != '+') continue;
        if (ieq(tok, "-skip-intros") || ieq(tok, "-nointro") || ieq(tok, "+nointro")) {
            g_bootCfg.skipIntros = true;
        } else if (ieq(tok, "-at")) {
            // next token = phase
            p = skipWs(p);
            const char* v = p;
            while (*p && !isspace((unsigned char)*p)) p++;
            size_t vl = (size_t)(p - v);
            char val[64] = {0};
            if (vl >= sizeof(val)) vl = sizeof(val) - 1;
            memcpy(val, v, vl); val[vl] = 0;
            if (ieq(val, "menu")) g_bootCfg.atMenu = true;
            else if (vl > 6 && (ieq(val, "level:") || !strncmp(val, "level:", 6))) {
                g_bootCfg.atMenu = true;                 // skip intros + loading
                strncpy(g_bootCfg.level, val + 6, sizeof(g_bootCfg.level) - 1);
            }
        } else if (ieq(tok, "-frames")) {
            p = skipWs(p);
            g_bootCfg.frameLimit = atoi(p);
            while (*p && !isspace((unsigned char)*p)) p++;
        } else if (ieq(tok, "-no-audio")) {
            g_bootCfg.noAudio = true;
        }
    }
    if (g_vTrace) { fprintf(g_vTrace, "[BOOTCFG] skipIntros=%d atMenu=%d frameLimit=%d noAudio=%d level='%s'\n",
        (int)g_bootCfg.skipIntros, (int)g_bootCfg.atMenu, g_bootCfg.frameLimit, (int)g_bootCfg.noAudio, g_bootCfg.level); fflush(g_vTrace); }
}

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
    // Suppress background erase entirely. During boot (intros/loading) we draw
    // double-buffered GDI each frame; Windows' default WM_ERASEBKGND would fill
    // the window with the class brush BETWEEN our frames → visible black flash
    // (the flicker). Returning 1 (= "erased, do nothing") prevents that tear.
    if (msg == WM_ERASEBKGND) return 1;
    return DefWindowProcA(hWnd, msg, wp, lp);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR lpCmdLine, int nCmdShow) {
    __lpCmdLine = lpCmdLine;
    g_vTrace = fopen("vanilla_trace.log", "w");
    if (g_vTrace) { fprintf(g_vTrace, "[VANILLA] GiantsRE vanilla-native recomp — entry\n"); fflush(g_vTrace); }
    g_vHInst = hInstance;

    // ── Phase-jump / test flags (parsed before anything else) ──
    VanillaParseArgs(lpCmdLine);

    // ── RegisterClass (vanilla strings: AppAccel, AppIcon, AppMenu, "Giants") ──
    WNDCLASSA wc = {};
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = VanillaWndProc;
    wc.hInstance = hInstance;
    wc.hCursor = LoadCursorA(nullptr, IDC_ARROW);
    wc.hbrBackground = nullptr;   // NO auto-erase: boot draws double-buffered; avoids flicker
    wc.lpszClassName = "Example";  // vanilla: class name = "Example" (s_Example_0057fb64)
    ATOM atom = RegisterClassA(&wc);
    if (!atom) { if (g_vTrace) { fprintf(g_vTrace, "[VANILLA] RegisterClass failed\n"); fflush(g_vTrace); } return 1; }

    // ── CreateWindow ──
    // Vanilla: CreateWindowExA(0x40000, "Example", "Giants", 0x6CF0000, CW_USEDEFAULT, ...)
    // 0x6CF0000 = WS_CLIPSIBLINGS|WS_CLIPCHILDREN|WS_CAPTION|WS_SYSMENU|WS_THICKFRAME|WS_MINIMIZEBOX|WS_MAXIMIZEBOX
    // Size the window for the registry-configured CLIENT (g_videoWidth/Height, read from
    // HKCU\Software\PlanetMoon\Giants — vanilla FUN_00483740). The renderer sizes its device
    // to the same; matching client = no stretch → clean capture.
    RECT _rc = { 0, 0, (LONG)(g_videoWidth ? g_videoWidth : 640), (LONG)(g_videoHeight ? g_videoHeight : 480) };
    AdjustWindowRectEx(&_rc, 0x06CF0000, FALSE, 0x40000);
    g_vHWnd = CreateWindowExA(0x40000, "Example", "Giants",
        0x06CF0000, CW_USEDEFAULT, CW_USEDEFAULT, _rc.right - _rc.left, _rc.bottom - _rc.top,
        nullptr, nullptr, hInstance, nullptr);
    if (!g_vHWnd) { if (g_vTrace) { fprintf(g_vTrace, "[VANILLA] CreateWindow failed\n"); fflush(g_vTrace); } return 1; }
    ShowWindow(g_vHWnd, nCmdShow);
    if (g_vTrace) { fprintf(g_vTrace, "[VANILLA] Window created hwnd=%p\n", g_vHWnd); fflush(g_vTrace); }

    // ── Registry setup (vanilla init chain: FUN_004a3900 defaults + FUN_00483740 read) ──
    // The DX7 renderer reads HKCU\Software\PlanetMoon\Giants for VideoWidth/Height/Depth.
    // Ensure first-run defaults, then READ the real values into globals (the renderer +
    // window use the player's configured resolution, not a hardcoded 640x480).
    VanillaSettings_EnsureDefaults();
    VanillaSettings_Load();

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
            // Force the CLIENT to the registry resolution so the window matches the render
            // (the renderer resizes the window, stretching the render → capture blur).
            RECT rc = { 0, 0, (LONG)(g_videoWidth ? g_videoWidth : 640), (LONG)(g_videoHeight ? g_videoHeight : 480) };
            AdjustWindowRectEx(&rc, 0x06CF0000, FALSE, 0x40000);
            SetWindowPos(g_vHWnd, nullptr, 0, 0, rc.right - rc.left, rc.bottom - rc.top,
                         SWP_NOMOVE | SWP_NOZORDER);
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
    if (!g_bootCfg.noAudio) VanillaAudio::Load("ds");
    // ── GTI terrain parser self-test (parse intro_island.gti heightfield) ──
    VanillaGTI::SelfTest();
    // ── GBS model parser self-test (parse intro_1.gbs mesh) ──
    VanillaGBS::SelfTest();
    // ── TGA texture parser self-test (parse intro_sea.tga) ──
    VanillaTGA::SelfTest();
    // ── Loading-screen picker self-test (FUN_0045a530 port: intro_island -> giants_loading) ──
    VanillaLoadScreen::SelfTest();
    // ── Localized-text lookup (callback[11] GetLocalizedString: GTextEnglish.bin) ──
    if (VanillaText::Load("English")) {
        if (g_vTrace) { fprintf(g_vTrace, "[VANILLA] text lookup '$IDnew' = '%s'\n", VanillaText::Lookup("$IDnew")); fflush(g_vTrace); }
    }
    // ── WorldList reader (FUN_004b77f0: reads worldlist*.bin → level table) ──
    FUN_004b77f0();
    // ── Scene-selector self-test (FUN_004913c0 port: scan level table for intro_island) ──
    //   runs AFTER FUN_004b77f0 so g_LevelTable is populated.
    VanillaSceneLoad_SelfTest();
    // ── Boot step 4 / 14: load the MENU scene via the real .BIN loader (FUN_004b7c50).
    // W_Intro.bin = the menu background scene (island + sky + logo). This populates the
    // scene lists (textures/placements/makewrld) so the renderer's real scene walk renders
    // the actual scene. Heavily logged; diagnose the crash/stop point.
    if (g_vTrace) { fprintf(g_vTrace, "[BOOT] === invoking FUN_004b7c50 (loader) on W_Intro.bin ===\n"); fflush(g_vTrace); }
    // Allocate a world_state buffer (DAT_006316ec) so loader/makwrld derefs are safe
    // (zero-reads instead of null-deref crash). makewrld early-returns (FUN_0053a3e0 stubbed)
    // but the odef VM + sound loader deref world_state at many offsets — need valid memory.
    static char g_world_state[0x10000] = {0};   // 64KB — generous (sound writes +0x4554, makewrld +0x4ef8)
    DAT_006316ec = (uint32_t)(uintptr_t)g_world_state;
    FUN_004b7c50("W_Intro.bin", 1.0f, 0.0f);
    if (g_vTrace) { fprintf(g_vTrace, "[BOOT] === FUN_004b7c50 returned ===\n"); fflush(g_vTrace); }
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
    VanillaBinLoaderFull::SelfTest();   // safe: reads w_intro_island.bin + validates magic (full loader dormant)
    // ── Logo mesh test: parse xx_giants_logo_3d.gbs for the 3D menu logo ──
    {
        auto ld = VanillaVFS::GzpReadFile("Bin\\xx_giants_logo_3d.gzp", "xx_giants_logo_3d.gbs");
        if (ld.empty()) ld = VanillaVFS::GzpReadFile("Bin\\xx_giants_logo_3d.gzp", "Giants_logo_3d.gbs");
        if (!ld.empty()) {
            VanillaGBS::Model logo = VanillaGBS::Parse(ld.data(), ld.size());
            if (g_vTrace) { fprintf(g_vTrace, "[LOGO] gbs: ok=%d verts=%u subobjs=%u texNames=%u\n",
                logo.ok, logo.numVertices, logo.numSubObjects, (unsigned)logo.texNames.size()); fflush(g_vTrace); }
        } else if (g_vTrace) { fprintf(g_vTrace, "[LOGO] GBS not found in xx_giants_logo_3d.gzp\n"); fflush(g_vTrace); }
    }

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
        // Deterministic capture mode: exit cleanly after N MENU-phase frames.
        if (g_bootCfg.frameLimit > 0 && frameCount >= g_bootCfg.frameLimit) {
            if (g_vTrace) { fprintf(g_vTrace, "[VANILLA] frameLimit %d reached — clean exit\n", g_bootCfg.frameLimit); fflush(g_vTrace); }
            g_vRunning = false;
        }
    }

    if (g_vTrace) { fprintf(g_vTrace, "[VANILLA] Exit\n"); fflush(g_vTrace); }
    VanillaInput_Fini();
    return (int)msg.wParam;
}
