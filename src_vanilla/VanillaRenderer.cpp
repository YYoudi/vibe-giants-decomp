// Vanilla-Native Recomp — Renderer Loader
// Ported from vanilla FUN_0051eb70 (296 bytes). Loads gg_<name>.dll (e.g.
// gg_dx7r.dll) and resolves the 2 vanilla renderer exports: GDVSysCreate +
// UpCallsLoad. NO GFXGetCapabilities (that's a 1.5-era 3rd export).
#include <windows.h>
#include <cstdio>
#include <cstdint>
#include <cstring>
#include <vector>
#include "VanillaVFS.h"
#include "VanillaTGA.h"
#include "VanillaBoot.h"   // g_bootCfg (phase-jump flags)

// Input (for intro skip — click/space).
extern "C" bool VanillaInput_KeyDown(int dik);
extern "C" void VanillaInput_Poll(void);
extern "C" uint32_t VanillaInput_MouseButtons(void);   // bitmask: bit0=LMB
// The renderer's own per-frame entry (renderer method [0x20] = 0x7370): does the
// full D3D frame internally (BeginScene/Clear/scene-walk/EndScene/present).
extern "C" int VanillaRunFrame(int frameState);

// Vanilla globals (DAT_ addresses from vanilla binary):
static FARPROC g_GDVSysCreate = nullptr;   // DAT_005dc01c
static FARPROC g_UpCallsLoad = nullptr;     // DAT_005dc020
static HMODULE g_rendererModule = nullptr;

// FUN_0051eb70 — Load the renderer DLL by name.
// param_1: optional path prefix (can be null/empty)
// param_2: renderer name (e.g. "dx7r" → loads "gg_dx7r.dll")
// Returns: 1 on success, 0 on failure.
extern "C" int VanillaLoadRenderer(const char* pathPrefix, const char* rendererName) {
    extern FILE* g_vTrace;
    char dllPath[512];

    HMODULE hModule = nullptr;
    // Try with path prefix: "<prefix>\gg_<name>.dll"
    if (pathPrefix && *pathPrefix) {
        snprintf(dllPath, sizeof(dllPath), "%s\\gg_%s.dll", pathPrefix, rendererName);
        hModule = GetModuleHandleA(dllPath);
        if (!hModule) hModule = LoadLibraryA(dllPath);
    }
    // Fallback: "gg_<name>.dll" without path
    if (!hModule) {
        snprintf(dllPath, sizeof(dllPath), "gg_%s.dll", rendererName);
        hModule = GetModuleHandleA(dllPath);
        if (!hModule) hModule = LoadLibraryA(dllPath);
    }
    if (!hModule) {
        if (g_vTrace) { fprintf(g_vTrace, "[VRENDER] failed to load gg_%s.dll\n", rendererName); fflush(g_vTrace); }
        return 0;
    }
    g_rendererModule = hModule;

    // Resolve the 2 vanilla renderer exports (NO GFXGetCapabilities in vanilla).
    g_GDVSysCreate = GetProcAddress(hModule, "GDVSysCreate");
    if (!g_GDVSysCreate) {
        if (g_vTrace) { fprintf(g_vTrace, "[VRENDER] GDVSysCreate not found\n"); fflush(g_vTrace); }
        return 0;
    }
    g_UpCallsLoad = GetProcAddress(hModule, "UpCallsLoad");
    if (!g_UpCallsLoad) {
        if (g_vTrace) { fprintf(g_vTrace, "[VRENDER] UpCallsLoad not found\n"); fflush(g_vTrace); }
        return 0;
    }

    if (g_vTrace) {
        fprintf(g_vTrace, "[VRENDER] loaded %s: GDVSysCreate=%p UpCallsLoad=%p\n",
                dllPath, (void*)g_GDVSysCreate, (void*)g_UpCallsLoad);
        fflush(g_vTrace);
    }
    return 1;
}

// Accessors for the WinMain to call GDVSysCreate + UpCallsLoad.
extern "C" FARPROC VanillaGetGDVSysCreate() { return g_GDVSysCreate; }
extern "C" FARPROC VanillaGetUpCallsLoad() { return g_UpCallsLoad; }

// ─── 21 vanilla callbacks (cdecl stubs) ──────────────────────────
// The vanilla contract: UpCallsLoad(0x2775, 21, table). All 21 are cdecl
// engine→renderer service callbacks. Stubbed until ported from vanilla_decompiled/.
static void __cdecl Stub_Void() {}
static void* __cdecl Stub_Null() { return nullptr; }
static void* __cdecl Stub_EmptyStr() { return (void*)""; }
static void __cdecl Stub_Free(void* p) { free(p); }
// callback[18] = the engine ALLOCATOR (vanilla 0x521a20 → debug-heap malloc 0x53c810,
// signature alloc(a0, size, heap)). The renderer allocates its objects (incl. the
// 0x57c renderer obj in GDVSysCreate) through this. MUST return a real pointer —
// GDVSysCreate fails (returns NULL) if it can't allocate. Freed by callback[19]=free
// (same MinGW heap → consistent, no cross-CRT free).
static void* __cdecl Stub_Alloc(int /*a0*/, size_t size, void* /*heap*/) { return malloc(size); }

// callback[11] GetLocalizedString (vanilla 0x50d7f0): const char* (const char* key) →
// localized string. Returns a default ("") if key is null. The renderer calls this during
// scene render (0x71a0) and the menus use it for UI text. Wired to VanillaText::Lookup.
extern "C" const char* VanillaText_Lookup(const char* key);  // defined in VanillaText.cpp
static const char* __cdecl Stub_GetLocalizedString(const char* key) {
    if (!key) return "";
    return VanillaText_Lookup(key);
}

// callback[20] ScenePipelineEntry (vanilla 0x523aa0): checks g_ScenePipelineGate, if set
// drives the scene dispatch (FUN_00523700 loading/overlay frame + the entity/texture
// walks). Wired to the real port in VanillaSceneDispatch.cpp.
extern "C" void FUN_00523aa0(void);

// callback[7] SceneBegin: the renderer calls this at scene-render start (during its own
// frame, on the device's back-buffer render target, BEFORE the RT→presented-surface copy).
// Drawing here puts geometry on the surface that actually gets presented. We use it to
// inject the terrain heightfield (the manual frame driver skipped the copy → black screen).
extern "C" int VanillaTerrain_DrawX(const char*, const char*);  // namespace VanillaTerrain wrapper (added below)
static void __cdecl cbSceneBegin_DrawTerrain() {
    extern FILE* g_vTrace;
    static int s_n = 0;
    if (s_n < 2) { if (g_vTrace) { fprintf(g_vTrace, "[VRENDER] cbSceneBegin: drawing terrain in-renderer-frame\n"); fflush(g_vTrace); } }
    VanillaTerrain_DrawX("intro_island.gti", "Bin\\w_intro_island.gzp");
    s_n++;
}

// The renderer object returned by GDVSysCreate (vanilla global DAT_00654940). The
// engine drives its ~55 thiscall methods (see RE_docs/DX7_RENDER_RECIPE.md) to render.
extern "C" void* g_vRenderer = nullptr;   // DAT_00654940

// Build + call UpCallsLoad + GDVSysCreate with the vanilla contract.
extern "C" void* VanillaInitRenderer(HWND hWnd) {
    extern FILE* g_vTrace;
    if (!g_UpCallsLoad || !g_GDVSysCreate) return nullptr;

    // 21 callback stubs (vanilla contract, no 22nd ShowErrorDialog2).
    static void* callbacks[21] = {
        (void*)Stub_Void,     // 0  StringCopyHelper
        (void*)Stub_Void,     // 1  CleanupHandler
        (void*)Stub_Void,     // 2  DebugLogString
        (void*)Stub_Void,     // 3  ShowErrorDialog
        (void*)Stub_EmptyStr, // 4  ErrorStringAccessor
        (void*)Stub_Void,     // 5  SecurityCheck
        (void*)Stub_Void,     // 6  PostFrameCallback
        (void*)cbSceneBegin_DrawTerrain, // 7  SceneBegin (inject terrain draw in-renderer-frame)
        (void*)Stub_Void,     // 8  SceneEnd
        (void*)Stub_Void,     // 9  PreRenderCheck
        (void*)Stub_Void,     // 10 BufferDeallocator
        (void*)Stub_GetLocalizedString, // 11 GetLocalizedString (real: VanillaText lookup)
        (void*)Stub_Void,     // 12 TextureLoader
        (void*)Stub_Void,     // 13 SinCosLookup
        (void*)Stub_Void,     // 14 TimeAccessor
        (void*)Stub_Null,     // 15 VFSOpenFileVariant
        (void*)Stub_Null,     // 16 VFSOpenMusicFile
        (void*)Stub_Null,     // 17 VFSOpenFile
        (void*)Stub_Alloc,    // 18 EngineAllocator (malloc — GDVSysCreate allocs via this)
        (void*)Stub_Free,     // 19 CRT_free
        (void*)FUN_00523aa0,   // 20 ScenePipelineEntry (real: scene dispatch gate)
    };

    // UpCallsLoad(version=0x2775, count=21, table).
    typedef void (__cdecl *PFN_UpCallsLoad)(uint32_t, uint32_t, void**);
    reinterpret_cast<PFN_UpCallsLoad>(g_UpCallsLoad)(0x2775, 21, callbacks);
    if (g_vTrace) { fprintf(g_vTrace, "[VRENDER] UpCallsLoad(0x2775, 21) called\n"); fflush(g_vTrace); }

    // GDVSysCreate — vanilla DX7 signature captured via Frida (frida_gdvargs.js)
    // on the original Giants.exe → gg_dx7r.dll. The EXACT 9 args the original passes:
    //   GDVSysCreate(lpCmdLine, hWnd, 0, 0, bpp=32, 0, windowed=1, &ddDeviceGUID, &ddIID)
    // a2=0, a3=0 (NOT width/height — those come from the registry VideoWidth/Height
    // which GDVSysCreate reads internally). a4=32 (bpp). a6=1 (windowed).
    // a7/a8 are DirectDraw device + interface GUIDs (the EXACT bytes captured from
    // the original's .data at 0x631828/0x631838). GDVSysCreate's internal device-init
    // sub (0x10006520) calls DirectDrawCreateEx(a7, &lpDD, a8, NULL) and returns NULL
    // if it fails — so the GUIDs MUST be valid. (See disasm_gdvsyscreate.py +
    // reports/frida_gdvargs.txt.)
    static const GUID g_DD_DEVICE_GUID = {
        0xd7b71e3e, 0x41d5, 0x11cf, {0xf3,0x73,0x25,0xa2,0x0e,0xc2,0xcd,0x35} };
    static const GUID g_DD_IID = {
        0x84e63de0, 0x46aa, 0x11cf, {0x81,0x6f,0x00,0x00,0xc0,0x20,0x15,0x6e} };
    extern const char* __lpCmdLine;
    typedef void* (__cdecl *PFN_GDVSysCreate_9)(const char*, HWND, uint32_t, uint32_t,
                                                uint32_t, uint32_t, uint32_t, const GUID*, const GUID*);
    // Vanilla WinMain (FUN_005222c0): GDVSysCreate(cmdLine, hWnd, w, h, bpp, flags, windowed=1,
    // &GUID1, &GUID2). w/h come from registry globals DAT_00631818/1c (0 in the captured
    // run → renderer reads width/height from registry itself). On NULL, retry 640x480.
    void* device = reinterpret_cast<PFN_GDVSysCreate_9>(g_GDVSysCreate)(
        __lpCmdLine ? __lpCmdLine : "", hWnd, 0, 0, 32, 0, 1,
        &g_DD_DEVICE_GUID, &g_DD_IID);
    if (!device) {
        // Vanilla retry path: 0x280(640) x 0x1e0(480).
        device = reinterpret_cast<PFN_GDVSysCreate_9>(g_GDVSysCreate)(
            __lpCmdLine ? __lpCmdLine : "", hWnd, 0x280, 0x1e0, 32, 0, 1,
            &g_DD_DEVICE_GUID, &g_DD_IID);
        if (g_vTrace) { fprintf(g_vTrace, "[VRENDER] GDVSysCreate retry(640x480) -> device=%p\n", device); fflush(g_vTrace); }
    }
    if (g_vTrace) { fprintf(g_vTrace, "[VRENDER] GDVSysCreate(hWnd=%p, bpp=32 win) -> device=%p\n", hWnd, device); fflush(g_vTrace); }
    g_vRenderer = device;   // store as DAT_00654940
    return device;
}

// ─── Display-config getter (renderer method [0x1b] = obj+0x6c = RVA 0xc970) ───
// The vanilla WinMain (FUN_005222c0) calls this RIGHT after GDVSysCreate to read the
// current display mode into engine globals DAT_005dcb34/cb44. 0xc970 is a pure GETTER:
// copies 2×16-byte config blocks OUT of the renderer's D3D-framework sub-object
// (obj+0x284 → +0x830 and +0x8cc) into the caller's buffers. Harmless read.
//
// *** CALLING CONVENTION (disasm-confirmed 2026-06-16): vanilla DX7 renderer methods
// are __cdecl with `this` as the EXPLICIT FIRST STACK ARG (mov eax,[esp+4]; ... ret —
// NOT thiscall, NO ECX-this, NO callee stack cleanup). The engine calls them as
// (*obj[N])(obj, args). So we use a plain __cdecl fn-ptr with obj as arg0. ***
extern "C" void VanillaReadDisplayConfig() {
    extern FILE* g_vTrace;
    if (!g_vRenderer) return;
    // Engine globals matching the vanilla layout (DAT_005dcb34 / DAT_005dcb44 — the
    // 16-byte display-config buffers the WinMain reads into).
    static uint32_t g_dispCfg1[4] = {0};   // DAT_005dcb34
    static uint32_t g_dispCfg2[4] = {0};   // DAT_005dcb44
    // method[0x1b] at obj+0x6c. __cdecl: fn(this, &out1, &out2).
    void** tbl = (void**)g_vRenderer;
    void* method6c = tbl[0x6c / 4];
    typedef void (__cdecl *PFN_GetDispCfg)(void* self, void* out1, void* out2);
    if (method6c) {
        ((PFN_GetDispCfg)method6c)(g_vRenderer, g_dispCfg1, g_dispCfg2);
        if (g_vTrace) {
            fprintf(g_vTrace, "[VRENDER] ReadDisplayConfig cfg1=%08x/%08x/%08x/%08x cfg2=%08x/%08x/%08x/%08x\n",
                    g_dispCfg1[0], g_dispCfg1[1], g_dispCfg1[2], g_dispCfg1[3],
                    g_dispCfg2[0], g_dispCfg2[1], g_dispCfg2[2], g_dispCfg2[3]);
            fflush(g_vTrace);
        }
    }
}

// Dump the renderer's private wrapper object vtable (wrapper@obj+0x294) + key front-table
// slots, so the vertex-buffer lock + DrawPrimitive methods can be identified (the terrain
// draw crashes because slot+0x98 reads from a locked VB — we need the VB-lock slot).
extern "C" void VanillaDumpWrapperVtable() {
    extern FILE* g_vTrace;
    if (!g_vRenderer || !g_vTrace) return;
    uintptr_t obj = (uintptr_t)g_vRenderer;
    uintptr_t wrapper = *(uintptr_t*)(obj + 0x294);
    if (!wrapper) { fprintf(g_vTrace, "[VRENDER] wrapper@obj+0x294 = NULL\n"); fflush(g_vTrace); return; }
    uintptr_t vt = *(uintptr_t*)wrapper;
    fprintf(g_vTrace, "[VRENDER] wrapper=%08x vtable=%08x\n", (unsigned)wrapper, (unsigned)vt);
    fprintf(g_vTrace, "[VRENDER] wrapper vt slots:\n");
    for (int i = 0; i < 48; i++) {
        uintptr_t fn = *(uintptr_t*)(vt + i * 4);
        fprintf(g_vTrace, "   vt[%02x (+0x%02x)] = %08x\n", i, i * 4, (unsigned)fn);
    }
    // front-table slots
    fprintf(g_vTrace, "[VRENDER] front-table: ");
    int offs[] = {0x60, 0x90, 0x94, 0x98, 0x9c, 0xa0, 0xa4, 0xb0, 0xb4, 0xc0};
    for (int o : offs) fprintf(g_vTrace, "+%02x=%08x ", o, (unsigned)*(uintptr_t*)(obj + o));
    fprintf(g_vTrace, "\n"); fflush(g_vTrace);
}

// ─── Per-frame render entry (renderer method [0x20] = obj+0x80 = RVA 0x7370) ───
// The vanilla game loop's core: `frameState = (*obj[0x20])(obj, frameState)`.
// 0x7370 calls obj->[0x28c]->vtable[0x68] (a D3D/DDraw COM interface method, likely
// TestCooperativeLevel) and returns a status: 0=ok/rendered, 3=device state change,
// or handles DDERR_* (0x88760xxx). This is the FAITHFUL per-frame render driver.
// obj+0x28c must be a valid D3D interface (set during GDVSysCreate device-init).
extern "C" int VanillaRunFrame(int frameState) {
    extern FILE* g_vTrace;
    if (!g_vRenderer) return frameState;
    uint32_t* obj = (uint32_t*)g_vRenderer;
    void* iface28c = (void*)(uintptr_t)obj[0x28c / 4];
    void* method20 = ((void**)g_vRenderer)[0x80 / 4];
    static int s_loggedFields = 0;
    if (g_vTrace && !s_loggedFields) {
        s_loggedFields = 1;
        fprintf(g_vTrace, "[VRENDER] obj fields: +0x280=%08x +0x284=%08x +0x288=%08x +0x28c=%08x +0x290=%08x | method[0x20]=%p\n",
                obj[0x280/4], obj[0x284/4], obj[0x288/4], obj[0x28c/4], obj[0x290/4], method20);
        fflush(g_vTrace);
    }
    if (!iface28c || !method20) {
        if (g_vTrace && !s_loggedFields) { fprintf(g_vTrace, "[VRENDER] RunFrame: obj+0x28c or method[0x20] NULL — device not render-ready\n"); fflush(g_vTrace); }
        return frameState;
    }
    typedef int (__cdecl *PFN_RunFrame)(void* self, int state);
    int r = ((PFN_RunFrame)method20)(g_vRenderer, frameState);
    return r;
}

// ─── Manual frame driver: BeginScene → (draw hook) → EndScene → Present ───// The renderer's 0x7340 does the whole frame internally (no engine-draw injection point).
// To draw ENGINE geometry (terrain/objects) we drive the frame manually using the mapped
// renderer methods (DX7_METHOD_MAP.md): slot+0x90 (0x86a0)=BeginScene+Clear+scene-open,
// slot+0x94 (0x87a0)=EndScene, slot+0x60 (0xc880)=Present/Flip. The drawHook runs
// in-scene (between BeginScene and EndScene) so submitted geometry is visible.
// All renderer methods are __cdecl(this, args); ptrs read via single-indirection
// *(void**)(renderer+offset).
// Test if obj+0x288 (the presented surface) is VISIBLE by GetDC + FillRect (GDI). If the
// window turns the fill color, obj+0x288 is the on-screen surface → we can draw 2D content
// (intros/textures) there directly (bypassing the broken 3D present).
extern "C" void VanillaTestSurfaceVisible() {
    extern FILE* g_vTrace;
    if (!g_vRenderer) return;
    void** obj = (void**)g_vRenderer;
    // Diagnostic: compare device RT (obj+0x294 GetRenderTarget) with obj+0x28c (flipped by 0x7370).
    void* wrapper = obj[0x294 / 4];
    void** wvt = wrapper ? *(void***)wrapper : nullptr;
    void* rt = nullptr;
    if (wvt) { typedef long(__stdcall *PFN_GetRT)(void*, void**); PFN_GetRT grt = (PFN_GetRT)(uintptr_t)(wvt[0x24/4]); if (grt) grt(wrapper, &rt); }
    void* flipped = obj[0x28c / 4];
    if (g_vTrace) { fprintf(g_vTrace, "[VRENDER] device-RT=%p  obj+0x28c(flipped)=%p  obj+0x288=%p  match=%d\n",
        rt, flipped, obj[0x288/4], rt == flipped); fflush(g_vTrace); }
}
typedef void (__cdecl *PFN_RenderMethod0)(void* self);
typedef long (__stdcall *PFN_COM0)(void* self);          // (this) stdcall COM
typedef long (__stdcall *PFN_SetRT)(void* self, void* surf, uint32_t flags);
typedef long (__stdcall *PFN_Flip)(void* self, uint32_t flags);
extern "C" void VanillaDriveFrame(void (*drawHook)(void)) {
    extern FILE* g_vTrace;
    if (!g_vRenderer) return;
    void** obj = (void**)g_vRenderer;

    // ─── Boot state machine (user-confirmed original sequence) ───
    //   INTRO1 (Digital Mayhem / dmlarge000)
    //   → INTRO2 (PlanetMoon / planetmoon)
    //   → INTRO3 (Giants + legal FR / legalfrench)
    //   → LOADING (int_loadisland.tga)
    //   → MENU (real D3D frame; empty scene → black until obj+0x4f0 is fed).
    // Advance = mouse CLICK (edge) / SPACE / per-phase timeout. NO infinite loop.
    //
    // Anti-flicker: intros & loading draw DOUBLE-BUFFERED GDI (memory DC → single
    // BitBlt to screen). Combined with window hbrBackground=NULL + WM_ERASEBKGND
    // returning TRUE (no auto-erase), there is no erase/redraw tear → no flicker.
    enum BootPhase { BOOT_INTRO = 0, BOOT_LOADING = 1, BOOT_MENU = 2 };
    struct BootState {
        int phase = BOOT_INTRO;
        int introIdx = 0;                 // 0..2 during BOOT_INTRO
        uint32_t phaseStart = 0;          // GetTickCount at phase entry
        VanillaTGA::Image imgs[3];
        bool loaded = false;
        uint32_t prevMouse = 0;           // click edge-detect
        float fade = 0.f;
        std::vector<uint8_t> scratch;     // reuse for per-frame fade pixel work
    };
    static BootState st;
    static bool s_loggedPhase = false;
    static int s_lastLoggedPhase = -1;

    // One-time asset load: intro textures, DATA-DRIVEN from intros.bin (vanilla
    // FUN_00523b60 reads this plaintext file — see behavior_specs/intro_timings.md).
    // NOTE: there is NO loading screen between intros and menu in the vanilla boot
    // (behavior_specs/loading_screen.md). The recomp's former "LOAD ISLAND" screen was
    // an INVENTION — int_loadisland.tga is menu chrome, never shown standalone. Removed.
    if (!st.loaded) {
        char introNames[3][64] = { "dmlarge000.tga", "planetmoon.tga", "legalfrench.tga" };
        // Read the canonical intro list from Bin\intros.bin (loose plaintext, one name/line).
        FILE* f = fopen("Bin\\intros.bin", "rb");
        if (f) {
            char buf[256] = {0}; size_t n = fread(buf, 1, sizeof(buf) - 1, f); fclose(f);
            int idx = 0;
            for (char* line = strtok(buf, "\r\n"); line && idx < 3; line = strtok(nullptr, "\r\n")) {
                if (line[0]) {
                    snprintf(introNames[idx], sizeof(introNames[idx]), "%s.tga", line);
                    idx++;
                }
            }
            if (g_vTrace) { fprintf(g_vTrace, "[BOOT] intros.bin -> [%s, %s, %s]\n",
                introNames[0], introNames[1], introNames[2]); fflush(g_vTrace); }
        }
        // Each intros.bin name may live in different GZPs and under a locale variant
        // (e.g. "legal" → legal.tga or legalFrench.tga). Try candidates until one loads.
        const char* gzps[3]  = { "Bin\\xx_intro.gzp", "Bin\\xx_intro.gzp", "Bin\\VO_SfxFrench.gzp" };
        const char* gzpsAlt[3] = { "Bin\\VO_SfxFrench.gzp", "Bin\\VO_SfxFrench.gzp", "Bin\\xx_intro.gzp" };
        for (int i = 0; i < 3; i++) {
            char frName[80];
            // strip ".tga", build "<stem>French.tga" locale variant
            snprintf(frName, sizeof(frName), "%.*sFrench.tga", (int)(strlen(introNames[i]) - 4), introNames[i]);
            const char* candidates[3] = { introNames[i], frName, nullptr };
            const char* candidateGzps[3] = { gzps[i], gzps[i], gzpsAlt[i] };
            for (int c = 0; c < 3 && !st.imgs[i].ok; c++) {
                if (!candidates[c]) break;
                auto d = VanillaVFS::GzpReadFile(candidateGzps[c], candidates[c]);
                if (d.empty() && candidateGzps[c] != gzpsAlt[i]) d = VanillaVFS::GzpReadFile(gzpsAlt[i], candidates[c]);
                if (!d.empty()) {
                    st.imgs[i] = VanillaTGA::Parse(d.data(), d.size());
                    snprintf(introNames[i], sizeof(introNames[i]), "%s", candidates[c]);  // log the resolved name
                }
            }
            if (g_vTrace) { fprintf(g_vTrace, "[BOOT] intro[%d] %s: ok=%d %dx%d %dbp\n",
                i, introNames[i], st.imgs[i].ok ? 1 : 0, st.imgs[i].width, st.imgs[i].height, st.imgs[i].bitsPerPixel); fflush(g_vTrace); }
        }
        st.loaded = true;
        st.phaseStart = GetTickCount();
        // Phase-jump flags: skip intros / go straight to MENU (or later, level load).
        if (g_bootCfg.atMenu || g_bootCfg.skipIntros) {
            st.phase = BOOT_MENU;
            if (g_vTrace) { fprintf(g_vTrace, "[BOOT] phase-jump: starting at MENU (skipIntros=%d atMenu=%d)\n",
                (int)g_bootCfg.skipIntros, (int)g_bootCfg.atMenu); fflush(g_vTrace); }
        }
    }

    // ── MENU phase: manual D3D frame bracket + terrain + GDI RT-present ──
    // The renderer's own per-frame (0x7370 / method[0x20]) does NOT call callback[7]
    // (SceneBegin/DrawTerrain) with our empty scene, so we drive the scene manually:
    //   obj[0x90] = BeginScene + Clear   (renderer front-table, __cdecl(this))
    //   obj[0x94] = EndScene
    // Between them we draw the island heightfield on the device RT (in-scene), then
    // present via the PROVEN path (commit 495b269): GetDC(device RT) → BitBlt(RT → window).
    if (st.phase == BOOT_MENU) {
        if (s_lastLoggedPhase != BOOT_MENU) {
            if (g_vTrace) { fprintf(g_vTrace, "[BOOT] === MENU phase — manual bracket + terrain + GDI RT-present ===\n"); fflush(g_vTrace); }
            s_lastLoggedPhase = BOOT_MENU;
        }
        typedef void (__cdecl *PFN_Cdecl0)(void*);
        PFN_Cdecl0 m90 = (PFN_Cdecl0)(uintptr_t)obj[0x90 / 4];   // BeginScene + Clear
        PFN_Cdecl0 m94 = (PFN_Cdecl0)(uintptr_t)obj[0x94 / 4];   // EndScene
        if (m90) m90(g_vRenderer);                                // BeginScene + Clear (device RT)
        if (g_vTrace) { static int tm=0; if(tm<2){fprintf(g_vTrace,"[BOOT] MENU: terrain draw start\n");fflush(g_vTrace);} }
        cbSceneBegin_DrawTerrain();                               // draw island on device RT (in-scene)
        if (g_vTrace) { static int tm2=0; if(tm2<2){fprintf(g_vTrace,"[BOOT] MENU: terrain draw returned OK\n");fflush(g_vTrace);tm2++;} }
        if (m94) m94(g_vRenderer);                                // EndScene

        // Client rect for the BitBlt extent.
        RECT crc; GetClientRect((HWND)(uintptr_t)obj[0x26c / 4], &crc);
        int cw = crc.right - crc.left, ch = crc.bottom - crc.top;
        if (cw > 640) cw = 640;        // clamp to device RT (640x480)
        if (ch > 480) ch = 480;

        // GDI present: GetDC(device RT) → BitBlt(RT → window).
        void* wrapper2 = obj[0x294 / 4];
        void** wvt2 = wrapper2 ? *(void***)wrapper2 : nullptr;
        if (wrapper2 && wvt2) {
            typedef long (__stdcall *PFN_GetRT)(void*, void**);
            typedef long (__stdcall *PFN_SurfGetDC)(void*, void**);
            typedef long (__stdcall *PFN_SurfRelDC)(void*, void*);
            PFN_GetRT getRT = (PFN_GetRT)(uintptr_t)wvt2[0x24 / 4];
            void* rt = nullptr;
            if (getRT) getRT(wrapper2, &rt);
            if (rt) {
                void** rvt = *(void***)rt;
                PFN_SurfGetDC getDC = (PFN_SurfGetDC)(uintptr_t)(rvt ? rvt[0x44 / 4] : nullptr);
                PFN_SurfRelDC relDC = (PFN_SurfRelDC)(uintptr_t)(rvt ? rvt[0x68 / 4] : nullptr);
                void* rtHDC = nullptr;
                if (getDC && relDC && getDC(rt, &rtHDC) == 0 && rtHDC) {
                    HWND hw = (HWND)(uintptr_t)obj[0x26c / 4];
                    if (hw) {
                        void* winDC = GetDC(hw);
                        if (winDC) {
                            BitBlt((void*)winDC, 0, 0, cw, ch, (void*)rtHDC, 0, 0, 0xCC0020 /*SRCCOPY*/);
                            ReleaseDC(hw, (void*)winDC);
                        }
                    }
                    relDC(rt, rtHDC);
                }
            }
        }
        return;
    }

    // ── INTRO / LOADING: input + timing ──
    VanillaInput_Poll();
    uint32_t now = GetTickCount();
    uint32_t mb = VanillaInput_MouseButtons();
    bool click = (mb & 0x1) && !(st.prevMouse & 0x1);   // LMB rising edge
    bool space = VanillaInput_KeyDown(0x39);             // DIK_SPACE
    st.prevMouse = mb;

    // Per-phase timing — MEASURED from vanilla FUN_00523b60 .data globals
    // (behavior_specs/intro_timings.md): fade 0.2s, hold 12.0s, linear alpha.
    //   DAT_00552300=0.20 (fade s), DAT_005522b8=12.0 (hold s), DAT_00552358=5.0 (rate).
    // The former 600/3000/600 values were INVENTED — replaced with the real ones.
    const uint32_t FADE_IN = 200, HOLD = 12000, FADE_OUT = 200;   // ms
    uint32_t elapsed = now - st.phaseStart;

    if (elapsed < FADE_IN)                              st.fade = (float)elapsed / FADE_IN;
    else if (elapsed < FADE_IN + HOLD)                  st.fade = 1.0f;
    else if (elapsed < FADE_IN + HOLD + FADE_OUT)       st.fade = 1.0f - (float)(elapsed - FADE_IN - HOLD) / FADE_OUT;
    else                                                st.fade = 0.0f;
    bool phaseDone = (click || space || elapsed > FADE_IN + HOLD + FADE_OUT);

    // ── Phase transitions ──
    if (phaseDone) {
        if (st.phase == BOOT_INTRO) {
            st.introIdx++;
            if (st.introIdx >= 3) {
                // NO loading screen between intros and menu (behavior_specs/boot_sequence.md,
                // loading_screen.md). The real giants_loading.tga shows only during the async
                // level load (FUN_004913c0→FUN_0045a530), not yet ported. Go straight to MENU.
                st.phase = BOOT_MENU;
                if (g_vTrace) { fprintf(g_vTrace, "[BOOT] intros done → MENU (no fake loading screen)\n"); fflush(g_vTrace); }
            } else {
                if (g_vTrace) { fprintf(g_vTrace, "[BOOT] intro → next (%d)\n", st.introIdx); fflush(g_vTrace); }
            }
        } else { // BOOT_LOADING → BOOT_MENU (legacy branch; BOOT_LOADING no longer entered)
            st.phase = BOOT_MENU;
            if (g_vTrace) { fprintf(g_vTrace, "[BOOT] loading done → MENU phase\n"); fflush(g_vTrace); }
        }
        st.phaseStart = now;
        st.fade = 0.0f;
    }

    // ── Draw current phase (double-buffered GDI on the window DC) ──
    HWND hw = nullptr;
    void* hwndv = obj[0x26c / 4];
    if (hwndv) hw = (HWND)hwndv;
    if (!hw) return;
    HDC winDC = GetDC(hw);
    if (!winDC) return;

    RECT clientRect;
    GetClientRect(hw, &clientRect);
    int winW = clientRect.right - clientRect.left;
    int winH = clientRect.bottom - clientRect.top;

    // Memory DC (double buffer) — single atomic BitBlt to screen = no flicker.
    HDC memDC = CreateCompatibleDC(winDC);
    HBITMAP memBM = CreateCompatibleBitmap(winDC, winW, winH);
    HBITMAP oldBM = (HBITMAP)SelectObject(memDC, memBM);

    // Black background (letterbox + fade target).
    RECT rfull = { 0, 0, winW, winH };
    HBRUSH bb = CreateSolidBrush(0);
    FillRect(memDC, &rfull, bb);
    DeleteObject(bb);

    // Pick image for current phase.
    const VanillaTGA::Image* img = nullptr;
    if (st.phase == BOOT_INTRO) {
        if (st.introIdx >= 0 && st.introIdx < 3) img = &st.imgs[st.introIdx];
    }
    // (BOOT_LOADING removed — no fake loading screen. BOOT_MENU returns early above.)
    if (img && img->ok && !img->pixels.empty() && st.fade > 0.01f) {
        // Fade-to-black: darken a scratch copy by (fade).
        st.scratch.assign(img->pixels.begin(), img->pixels.end());
        int bpp = img->bitsPerPixel / 8;        // bytes per pixel
        int npx = img->width * img->height;
        uint8_t f = (uint8_t)(st.fade * 255.0f);
        for (int i = 0; i < npx; i++) {
            uint8_t* p = &st.scratch[(size_t)i * bpp];
            p[0] = (uint8_t)((p[0] * f) >> 8);   // B
            p[1] = (uint8_t)((p[1] * f) >> 8);   // G
            p[2] = (uint8_t)((p[2] * f) >> 8);   // R
            // alpha (if present) left as-is
        }
        BITMAPINFO bi = {};
        bi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
        bi.bmiHeader.biWidth = img->width;
        bi.bmiHeader.biHeight = img->height;     // positive = bottom-up (matches VanillaTGA)
        bi.bmiHeader.biPlanes = 1;
        bi.bmiHeader.biBitCount = img->bitsPerPixel;
        bi.bmiHeader.biCompression = 0;
        // Center + maintain aspect ratio.
        float sx = (float)winW / img->width, sy = (float)winH / img->height;
        float scale = sx < sy ? sx : sy;
        int dstW = (int)(img->width * scale);
        int dstH = (int)(img->height * scale);
        int dstX = (winW - dstW) / 2;
        int dstY = (winH - dstH) / 2;
        SetStretchBltMode(memDC, 3 /*HALFTONE*/);
        StretchDIBits(memDC, dstX, dstY, dstW, dstH, 0, 0, img->width, img->height,
                      st.scratch.data(), &bi, 0, 0xCC0020);
    }

    // Single atomic blit → no erase/redraw tear.
    BitBlt(winDC, 0, 0, winW, winH, memDC, 0, 0, 0xCC0020);
    SelectObject(memDC, oldBM);
    DeleteObject(memBM);
    DeleteDC(memDC);
    ReleaseDC(hw, winDC);
}
