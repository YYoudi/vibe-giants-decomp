#include <cmath>
// Vanilla-Native Recomp — Renderer Loader
// Ported from vanilla FUN_0051eb70 (296 bytes). Loads gg_<name>.dll (e.g.
// gg_dx7r.dll) and resolves the 2 vanilla renderer exports: GDVSysCreate +
// UpCallsLoad. NO GFXGetCapabilities (that's a 1.5-era 3rd export).
#include <windows.h>
#include <ddraw.h>
#include <cstdio>
#include <cstdint>
#include <cstring>
#include <vector>
#include "VanillaVFS.h"
#include "VanillaTGA.h"
#include "VanillaBoot.h"   // g_bootCfg (phase-jump flags)
#include "VanillaLogo.h"   // VanillaLogo_Draw (-logo3d: menu 3D logo model render)
#include "VanillaGBS.h"    // 3D logo mesh parser
#include "VanillaVFSCallbacks.h"  // callbacks 15/16/17 (vanilla FUN_006222d0/00621fe0/00621e50)

// Input (for intro skip — click/space).
extern "C" bool VanillaInput_KeyDown(int dik);
extern "C" void VanillaInput_Poll(void);
extern "C" uint32_t VanillaInput_MouseButtons(void);   // bitmask: bit0=LMB
extern "C" void VanillaInput_MousePos(int* x, int* y); // absolute client-relative cursor pos
extern "C" void FUN_004913c0(void);   // boot step 14: intro_island selector (VanillaSceneLoad.cpp)
// The renderer's own per-frame entry (renderer method [0x20] = 0x7370): does the
// full D3D frame internally (BeginScene/Clear/scene-walk/EndScene/present).
extern "C" int VanillaRunFrame(int frameState);
// D3D7 texture creation + device SetTexture@0x8c (measured texturing mechanism).
extern "C" void VanillaD3D7_BindIntroGrnd(void* device);
// Canonical 2D tiled blitter (FUN_00433900 port) — see vanilla_2d_render_pipeline.md.
namespace VanillaBlit { struct TiledImage; TiledImage* Load(void*, const char*, const char*);
    void* FirstSurface(TiledImage*, int* imgW, int* imgH);
    void DrawFull(void* device, void* surf, int dstW, int dstH);
    void* LoadFullSurface(void* device, const char* gzp, const char* tgaName, int* outW, int* outH);
    int GetTileSurfaces(TiledImage*, int* imgW, int* imgH, void** outSurfs, int maxSurfs);
    void Draw(void*, TiledImage*, int, int, float);
    void DrawScaled(void*, TiledImage*, int, int, int, int, float); }
// Bitmap font (GiantFont_Eng) — FUN_0044a9c0 port; see menu_system_code.md.
namespace VanillaFont { struct Font; Font* Load(void*); void Draw(void*, Font*, const char*, int, int, int, uint32_t); }
// Device resolution (registry) — for DrawScaled intro/loading device-fit.
extern "C" uint32_t g_videoWidth, g_videoHeight;

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

// callback[12] = vanilla 0040d430 (rule-11: it's the CAMERA-STATE accessor, NOT "TextureLoader").
// Signature: void cb(float* p1, float* p2, float* p3, float* p4) where p1/p2/p3 = the 3 camera
// ANGLES (DAT_005561b0/b4/b8) and p4[0..2] = camera POSITION (DAT_005561a4/a8/ac). The renderer
// builds its view matrix from these. OBSERVED at the original's menu via Frida (scripts/
// frida_camglobals.js @ t~40s): pos=(-527.9, 499.4, 44.0), ang=(163.0, 0.0, 0.0). Faithful (measured,
// not guessed). TODO: animate/port the camera-update fns (FUN_0040d560/0040d9f0) for a live camera.
static float g_CamPos[3] = { -527.9f, 499.4f, 44.0f };
static float g_CamAng[3] = { 163.0f, 0.0f, 0.0f };
static void __cdecl cbCameraState(float* p1, float* p2, float* p3, float* p4) {
    if (p1) *p1 = g_CamAng[0];
    if (p2) *p2 = g_CamAng[1];
    if (p3) *p3 = g_CamAng[2];
    if (p4) { p4[0] = g_CamPos[0]; p4[1] = g_CamPos[1]; p4[2] = g_CamPos[2]; }
    extern FILE* g_vTrace;
    static int s_n = 0;
    if (g_vTrace && s_n < 2) { s_n++; fprintf(g_vTrace, "[CB12] camera-state called (pos %.1f,%.1f,%.1f ang %.1f,%.1f,%.1f)\n",
        g_CamPos[0],g_CamPos[1],g_CamPos[2], g_CamAng[0],g_CamAng[1],g_CamAng[2]); fflush(g_vTrace); }
}

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

// Shutdown: release the DX7 device + renderer so the adapter is freed for the NEXT launch.
// Without this the device leaks → the next process's GDVSysCreate hangs (DX7 device conflict)
// — the root cause of the "recomp crashes on repeated launch" flakiness. Mirrors the vanilla
// ShutdownSubsystems (0x004f7f10) ref-counted teardown: Release the wrapper IDirect3DDevice7
// (vtable 0x08) until gone, then release the renderer object's own ref.
extern "C" void VanillaRenderer_Shutdown(void) {
    if (!g_vRenderer) return;
    uint32_t* obj = (uint32_t*)g_vRenderer;
    void* wrapper = obj[0x294 / 4];
    if (wrapper) {
        void** wvt = *(void***)wrapper;
        typedef void (__stdcall *PFN_Release)(void*);
        PFN_Release rel = (PFN_Release)(uintptr_t)(wvt ? wvt[0x08 / 4] : nullptr);  // IUnknown::Release
        if (rel) { for (int i = 0; i < 8; i++) rel(wrapper); }   // drain ref-count
    }
    g_vRenderer = nullptr;
    Sleep(500);   // let the DX7 driver release the adapter before the process exits
}

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
        (void*)cbCameraState, // 12 CameraState accessor (vanilla 0040d430; OBSERVED menu camera)
        (void*)Stub_Void,     // 13 SinCosLookup
        (void*)Stub_Void,     // 14 TimeAccessor
        (void*)cbVFSOpenFileVariant, // 15 VFSOpenFileVariant (vanilla FUN_006222d0)
        (void*)cbVFSOpenMusicFile,   // 16 VFSOpenMusicFile   (vanilla FUN_00621fe0)
        (void*)cbVFSOpenFile,        // 17 VFSOpenFile        (vanilla FUN_00621e50)
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
        __lpCmdLine ? __lpCmdLine : "", hWnd, g_videoWidth ? g_videoWidth : 640,
        g_videoHeight ? g_videoHeight : 480, 32, 0, 1,
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
    // The renderer resizes the window to its display mode (e.g. 1024x720); force it back to the
    // device render size so GDI BitBlt is 1:1 (no StretchBlt/capdiff-resize blur).
    if (hWnd) {
        RECT rc = { 0, 0, (LONG)(g_videoWidth ? g_videoWidth : 640), (LONG)(g_videoHeight ? g_videoHeight : 480) };
        AdjustWindowRectEx(&rc, 0x06CF0000, FALSE, 0x40000);
        SetWindowPos(hWnd, nullptr, 0, 0, rc.right - rc.left, rc.bottom - rc.top,
                     SWP_NOMOVE | SWP_NOZORDER);
    }
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

// GDI present (the PROVEN path, commit 495b269): read the device render-target surface (where
// VanillaBlit D3D draws land) via GetDC, BitBlt it onto the window. Bypasses the renderer's
// broken +0xa8 Present (which needs a renderer-managed source the recomp can't produce).
// IDirectDrawSurface7 vtable: GetDC@0x44 (idx17), ReleaseDC@0x68 (idx26), Lock@0x64 (idx25).
static void VanillaGdiPresent(void* device, void* hwnd, int devW, int devH, FILE* tr) {
    if (!device || !hwnd) return;
    void** dvt = *(void***)device;
    typedef long (__stdcall *PFN_GetRT)(void*, void**);
    typedef long (__stdcall *PFN_SurfGetDC)(void*, void**);
    typedef long (__stdcall *PFN_SurfRelDC)(void*, void*);
    PFN_GetRT grt = (PFN_GetRT)(uintptr_t)dvt[0x24/4];
    void* rt = nullptr;
    if (grt) grt(device, &rt);
    if (!rt) return;
    void** svt = *(void***)rt;
    PFN_SurfGetDC surfGetDC = (PFN_SurfGetDC)(uintptr_t)svt[0x44/4];
    PFN_SurfRelDC surfRelDC = (PFN_SurfRelDC)(uintptr_t)svt[0x68/4];
    void* surfDCptr = nullptr;
    long hr = surfGetDC ? surfGetDC(rt, &surfDCptr) : -1;
    static int s_log = 0;
    if (tr && s_log < 2) { fprintf(tr, "[GDIPRES] GetDC(device-RT=%p) hr=0x%lx dc=%p\n", rt, (unsigned long)hr, surfDCptr); fflush(tr); s_log++; }
    if (hr != 0 || !surfDCptr) return;
    HDC surfDC = (HDC)(uintptr_t)surfDCptr;
    HDC winDC = GetDC((HWND)hwnd);
    if (winDC) {
        // The renderer resizes the window to its display mode (e.g. 1024x720) while the device
        // renders at devW x devH (640x480). StretchBlt the device-RT to fill the whole window
        // client so captures aren't distorted (BitBlt only filled the top-left devW x devH).
        RECT crc; GetClientRect((HWND)hwnd, &crc);
        int cW = crc.right - crc.left, cH = crc.bottom - crc.top;
        if (cW > 0 && cH > 0) StretchBlt(winDC, 0, 0, cW, cH, surfDC, 0, 0, devW, devH, SRCCOPY);
        else BitBlt(winDC, 0, 0, devW, devH, surfDC, 0, 0, SRCCOPY);
        ReleaseDC((HWND)hwnd, winDC);
    }
    if (surfRelDC) surfRelDC(rt, surfDCptr);
}

// Save the device render-target to a BMP file (clean fidelity check — no window/appsnap/chrome).
// Reusable verification: compare the saved BMP directly to the source TGA.
static bool VanillaSaveDeviceRT(void* device, const char* path, int devW, int devH) {
    if (!device || !path) return false;
    void** dvt = *(void***)device;
    typedef long (__stdcall *PFN_GetRT)(void*, void**);
    typedef long (__stdcall *PFN_SurfGetDC)(void*, void**);
    typedef long (__stdcall *PFN_SurfRelDC)(void*, void*);
    PFN_GetRT grt = (PFN_GetRT)(uintptr_t)dvt[0x24/4];
    void* rt = nullptr; if (grt) grt(device, &rt);
    if (!rt) return false;
    void** svt = *(void***)rt;
    PFN_SurfGetDC surfGetDC = (PFN_SurfGetDC)(uintptr_t)svt[0x44/4];
    PFN_SurfRelDC surfRelDC = (PFN_SurfRelDC)(uintptr_t)svt[0x68/4];
    void* dcptr = nullptr;
    long hr = surfGetDC ? surfGetDC(rt, &dcptr) : -1;
    if (hr != 0 || !dcptr) return false;
    HDC hdc = (HDC)(uintptr_t)dcptr;
    HDC mdc = CreateCompatibleDC(hdc);
    HBITMAP bmp = CreateCompatibleBitmap(hdc, devW, devH);
    HGDIOBJ old = SelectObject(mdc, bmp);
    BitBlt(mdc, 0, 0, devW, devH, hdc, 0, 0, SRCCOPY);
    // write BMP
    BITMAPINFOHEADER bi = { sizeof(BITMAPINFOHEADER), devW, devH, 1, 32, 0, devW*devH*4, 0, 0, 0, 0 };
    unsigned char* bits = (unsigned char*)malloc(devW * devH * 4);
    int got = GetDIBits(mdc, bmp, 0, devH, bits, (BITMAPINFO*)&bi, BI_RGB);
    FILE* f = nullptr;
    bool ok = false;
    if (got && bits && fopen_s(&f, path, "wb") == 0 && f) {
        int pad = 0, hdr = 54;
        BITMAPFILEHEADER bf = { 0x4D42, (DWORD)(hdr + devW*devH*4), 0, 0, (DWORD)hdr };
        fwrite(&bf, 1, sizeof(bf), f);
        fwrite(&bi, 1, sizeof(bi), f);
        fwrite(bits, 1, devW*devH*4, f);
        fclose(f);
        ok = true;
    }
    free(bits);
    SelectObject(mdc, old); DeleteObject(bmp); DeleteDC(mdc);
    if (surfRelDC) surfRelDC(rt, dcptr);
    return ok;
}
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
        char resolvedGzp[3][80] = {0};    // GZP that resolved each intro (for tiled load)
        char resolvedName[3][80] = {0};   // resolved intro TGA name (locale variant)
        bool tiledLoaded[3] = {false,false,false};
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
                    snprintf(st.resolvedGzp[i], sizeof(st.resolvedGzp[i]), "%s", candidateGzps[c]);
                    snprintf(st.resolvedName[i], sizeof(st.resolvedName[i]), "%s", candidates[c]);
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
        if (g_bootCfg.atLoading) {
            st.phase = BOOT_LOADING;          // -at loading: jump straight to the loading screen
            if (g_vTrace) { fprintf(g_vTrace, "[BOOT] phase-jump: starting at LOADING (giants_loading.tga)\n"); fflush(g_vTrace); }
        }
        if (g_bootCfg.atIntro >= 0) {
            st.phase = BOOT_INTRO;             // -at introN: jump to intro index, frozen for capture
            st.introIdx = g_bootCfg.atIntro;
            st.fade = 1.0f;                    // full-opacity (held state)
            if (g_vTrace) { fprintf(g_vTrace, "[BOOT] phase-jump: starting at INTRO[%d] (frozen)\n", g_bootCfg.atIntro); fflush(g_vTrace); }
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
        // -test3d: prove the D3D7 3D TRANSFORM PIPELINE works. Set perspective + view
        // matrices via SetTransform@0x2c, draw a 3D triangle (XYZ|DIFFUSE, NOT XYZRHW).
        // If perspective 3D appears, the device's transform pipeline is functional →
        // the foundation for faithful 3D reproduction exists.
        if (g_bootCfg.scene3d) {  // reuse the flag for now
            void* wrapper = obj[0x294 / 4];
            if (wrapper) {
                void** wvt = *(void***)wrapper;
                // SetTransform@0x2c, SetRenderState@0x50, DrawPrimitive@0x64, Clear@0x28
                typedef long (__stdcall *PFN_SetXform)(void*, uint32_t, const float*);
                typedef long (__stdcall *PFN_SR)(void*, uint32_t, uint32_t);
                typedef long (__stdcall *PFN_DP)(void*, uint32_t, uint32_t, const void*, uint32_t, uint32_t);
                typedef long (__stdcall *PFN_Clear)(void*, uint32_t, void*, uint32_t, uint32_t, float, uint32_t);
                PFN_SetXform sx = (PFN_SetXform)(uintptr_t)wvt[0x2c / 4];
                PFN_SR sr = (PFN_SR)(uintptr_t)wvt[0x50 / 4];
                PFN_DP dp = (PFN_DP)(uintptr_t)wvt[0x64 / 4];
                PFN_Clear clr = (PFN_Clear)(uintptr_t)wvt[0x28 / 4];
                // SetViewport@0x34 — required for 3D→screen mapping (DX7 needs a viewport).
                typedef long (__stdcall *PFN_SetVP)(void*, const void*);
                PFN_SetVP svp = (PFN_SetVP)(uintptr_t)wvt[0x34 / 4];
                struct VP7 { uint32_t sz, x, y, w, h; float minZ, maxZ; };
                VP7 vp = { sizeof(VP7), 0, 0, (uint32_t)(g_videoWidth?g_videoWidth:640), (uint32_t)(g_videoHeight?g_videoHeight:480), 0.0f, 1.0f };
                if (svp) svp(wrapper, &vp);
                // Perspective projection (fov=60°, aspect=4:3, znear=1, zfar=5000)
                float yS = 1.7320508f;  // cot(30°)
                float xS = yS * 0.75f;  // /aspect(640/480)
                float proj[16] = { xS,0,0,0, 0,yS,0,0, 0,0,1.0002f,1, 0,0,-1.0002f,0 };
                // View matrix: camera at (0,0,-200) looking toward +Z (origin). DX7 LEFT-HANDED:
                // +Z is INTO the screen. View translation = +200 puts world-origin at view-z=200 (in front).
                float view[16] = { 1,0,0,0, 0,1,0,0, 0,0,1,0, 0,0,200,1 };
                // World = identity
                float world[16] = { 1,0,0,0, 0,1,0,0, 0,0,1,0, 0,0,0,1 };
                // 3D triangle (XYZ|NORMAL|DIFFUSE FVF=0x52): DX7 lighting needs normals. Normal (0,0,1)
                // faces the camera (+Z); light dir (0,0,-1) travels toward -Z so it lights +Z faces.
                struct V3 { float x, y, z; float nx, ny, nz; uint32_t diff; };
                static float rot = 0; rot += 0.02f;
                float cr = cosf(rot), sv = sinf(rot);
                V3 tri[3] = {
                    { 0, 50, 0,  0,0,1, 0xFFFF0000 },                   // top, red
                    { cr * 50, -50, sv * 50,  0,0,1, 0xFF00FF00 },     // bottom-right, green
                    { -cr * 50, -50, -sv * 50,  0,0,1, 0xFF0000FF },   // bottom-left, blue
                };
                // Use the RENDERER's scene bracket (sets the correct render target surface —
                // the device's own Clear draws to the wrong surface that Present doesn't show).
                typedef void (__cdecl *PFN_Cdecl0)(void*);
                PFN_Cdecl0 m90 = (PFN_Cdecl0)(uintptr_t)obj[0x90 / 4];  // renderer BeginScene+Clear
                PFN_Cdecl0 m94 = (PFN_Cdecl0)(uintptr_t)obj[0x94 / 4];  // renderer EndScene
                PFN_Cdecl0 m_a8t = (PFN_Cdecl0)(uintptr_t)obj[0xa8 / 4]; // renderer Present
                if (m90) m90(g_vRenderer);  // BeginScene+Clear on the CORRECT surface
                // Clear the depth buffer too (device Clear@0x28, flags D3DCLEAR_TARGET=1|ZBUFFER=2=3)
                // so ZENABLE on works for proper 3D occlusion (m90 clears color only).
                if (clr) clr(wrapper, 0, nullptr, 3, 0xFF000000, 1.0f, 0);
                if (sx) { sx(wrapper, 256, world); sx(wrapper, 2, view); sx(wrapper, 3, proj); }
                if (sr) { sr(wrapper, 7, 1); sr(wrapper, 22, 1); sr(wrapper, 137, 0); sr(wrapper, 139, 0xFFFFFFFF); }  // ZENABLE ON(7=1), CULL_NONE(22), LIGHTING OFF(137), AMBIENT(139)
                // DX7 XYZ vertices ALWAYS go through lighting → set a light so the triangle isn't black.
                typedef long (__stdcall *PFN_SetLight)(void*, uint32_t, const void*);
                typedef long (__stdcall *PFN_LightEnable)(void*, uint32_t, uint32_t);
                PFN_SetLight sl = (PFN_SetLight)(uintptr_t)wvt[0x48 / 4];     // SetLight@idx18
                PFN_LightEnable le = (PFN_LightEnable)(uintptr_t)wvt[0xb0 / 4]; // LightEnable@idx44
                // D3DLIGHT7 directional: white diffuse, pointing -Z (toward the triangle from camera).
                struct D3DLIGHT7 { uint32_t type; float diff[3]; float diff_a; float spec[3]; float spec_a;
                    float amb[3]; float amb_a; float pos[3]; float dir[3]; float range; float falloff;
                    float a0,a1,a2; float theta,phi; };
                D3DLIGHT7 light = { 1 /*D3DLIGHT_DIRECTIONAL*/, {1,1,1},1, {0,0,0},0, {0.5f,0.5f,0.5f},1,
                    {0,0,-200},{0,0,-1}, 1000, 0, 1,0,0, 0,0 };
                if (sl) sl(wrapper, 0, &light);
                if (le) le(wrapper, 0, 1);  // enable light 0
                long hr = dp ? dp(wrapper, 4, 0x52, tri, 3, 0) : -1;
                if (g_vTrace) { static int ln=0; if(ln<2){fprintf(g_vTrace,"[TEST3D] renderer-bracket + SetTransform + DrawPrimitive hr=0x%lx\n",(unsigned long)hr);fflush(g_vTrace);ln++;} }
                if (m94) m94(g_vRenderer);  // EndScene
                obj[0x42c / 4] = (void*)1;
                // -saveframe (scene3d returns early, so save here).
                if (g_bootCfg.saveFrame[0]) { static bool s=false; if(!s){ VanillaSaveDeviceRT(wrapper, g_bootCfg.saveFrame, (int)(g_videoWidth?g_videoWidth:640), (int)(g_videoHeight?g_videoHeight:480)); s=true; } }
                // Present via GDI (device-RT -> window); the renderer's +0xa8 is broken (white).
                { extern void* g_vHWnd; if (g_vHWnd) VanillaGdiPresent(wrapper, g_vHWnd, (int)(g_videoWidth?g_videoWidth:640), (int)(g_videoHeight?g_videoHeight:480), g_vTrace); }
                return;
            }
        }
        if (g_bootCfg.scene3d) {
            if (s_lastLoggedPhase != BOOT_MENU) {
                if (g_vTrace) { fprintf(g_vTrace, "[BOOT] === MENU -scene3d: calling renderer scene walk (0x7370) ===\n"); fflush(g_vTrace); }
                s_lastLoggedPhase = BOOT_MENU;
            }
            VanillaRunFrame(0);
            return;
        }
        if (s_lastLoggedPhase != BOOT_MENU) {
            if (g_vTrace) { fprintf(g_vTrace, "[BOOT] === MENU phase — manual bracket + terrain (scene populated: 204 tex bound) ===\n"); fflush(g_vTrace); }
            s_lastLoggedPhase = BOOT_MENU;
        }
        typedef void (__cdecl *PFN_Cdecl0)(void*);
        typedef void (__cdecl *PFN_Cdecl1i)(void*, uint32_t);
        PFN_Cdecl0 m90 = (PFN_Cdecl0)(uintptr_t)obj[0x90 / 4];   // BeginScene + Clear
        PFN_Cdecl0 m94 = (PFN_Cdecl0)(uintptr_t)obj[0x94 / 4];   // EndScene
        // +0x98 = Clear/FillBackground (obj, ARGB color). The original menu has a dark
        // stormy sky + the 3D island scene behind the 2D overlays. Render the terrain
        // through the 3D pipeline (now proven functional) after BeginScene, before 2D.
        PFN_Cdecl1i m98 = (PFN_Cdecl1i)(uintptr_t)obj[0x98 / 4];
        if (m98) m98(g_vRenderer, 0xFF31243b);   // dark blue-gray sky
        if (m90) m90(g_vRenderer);
        // ── -logo3d: render the menu 3D logo MODEL (Giants_logo_3D.gbs + Giants_logo_512.tga)
        //    through the D3D7 3D pipeline. Observed asset (orig_logo3d_model.md): the menu
        //    centerpiece is this 3D model, NOT a flat 2D blit. Diagnostic path (camera iterated
        //    via capdiff) — replaces the terrain + 2D-blit paths for this flag.
        if (g_bootCfg.logo3d) {
            VanillaLogo_Draw();
        } else {
        // ── 3D island terrain through the D3D7 transform pipeline (perspective + lit + textured).
        VanillaTerrain_DrawX("intro_island.gti", "Bin\\w_intro_island.gzp");
        // ── Menu logo = Giants_logo_512.tga (a 2D image, NOT the xx_giants_logo_3d 3D mesh).
        //    The original menu renders the chrome "GIANTS / CITIZEN KABUTO" as a single 2D
        //    textured quad (one of the menu trace's 130 quads). Identified via GZP index
        //    (xx_giants_logo_3d.gzp). Rendered centered, device-fit, via the 2D blitter.
        {
            int devW = g_videoWidth ? (int)g_videoWidth : 640;
            int devH = g_videoHeight ? (int)g_videoHeight : 480;
            void* wrapper = obj[0x294 / 4];
            static VanillaBlit::TiledImage* s_logoImg = nullptr;
            static bool s_logoTried = false;
            if (wrapper && !s_logoTried) {
                s_logoTried = true;
                s_logoImg = VanillaBlit::Load(wrapper, "Bin\\xx_giants_logo_3d.gzp", "Giants_logo_512.tga");
            }
            if (wrapper && s_logoImg) {
                // Logo 512x256 (2:1), centered, ~75% of device width.
                int lw = (devW * 3) / 4;
                int lh = lw / 2;                       // keep 2:1 aspect
                int lx = (devW - lw) / 2;
                int ly = (devH - lh) / 2 - devH/8;     // slightly above center
                VanillaBlit::DrawScaled(wrapper, s_logoImg, lx, ly, lw, lh, 1.0f);
            }
        }
        }  // end else (non-logo3d: terrain + 2D logo blit)
        // ── Bitmap-font text (FUN_0044a9c0 port) — GiantFont_Eng via tx_lev1.gzp. Test
        //    render of the profile-select prompt (the menu's first text). Cell layout
        //    refined from the measured font sheet (see [FONT] trace).
        {
            void* wrapper = obj[0x294 / 4];
            static VanillaFont::Font* s_font = nullptr;
            static bool s_fontTried = false;
            if (wrapper && !s_fontTried) { s_fontTried = true; s_font = VanillaFont::Load(wrapper); }
            if (wrapper && s_font) {
                VanillaFont::Draw(wrapper, s_font, "QUI ETES VOUS?", 60, 40, 24, 0xFFFFFFFF);
                VanillaFont::Draw(wrapper, s_font, "Player", 120, 80, 24, 0xFFFF8060);
            }
        }
        // ── Custom mouse cursor (FUN_0042e450 port): "cursor00.tga" drawn as a quad at
        //    the mouse position via the 2D blitter. The original replaces the OS cursor
        //    with this textured quad at DAT_0063111c/1120 (mouse X/Y).
        {
            void* wrapper = obj[0x294 / 4];
            static VanillaBlit::TiledImage* s_cursor = nullptr;
            static bool s_cursorTried = false;
            if (wrapper && !s_cursorTried) {
                s_cursorTried = true;
                s_cursor = VanillaBlit::Load(wrapper, "Bin\\w_menus.gzp", "cursor00.tga");
            }
            if (wrapper && s_cursor) {
                int mx = 0, my = 0;
                VanillaInput_MousePos(&mx, &my);
                VanillaBlit::Draw(wrapper, s_cursor, mx, my, 1.0f);
            }
        }
        if (m94) m94(g_vRenderer);
        PFN_Cdecl0 m_a8 = (PFN_Cdecl0)(uintptr_t)obj[0xa8 / 4];   // Present
        obj[0x42c / 4] = (void*)1;
        if (m_a8) m_a8(g_vRenderer);
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
    // Phase timing: intros = 0.2s fade / 12s hold (DAT_00552300/005522b8). LOADING screen
    // shows during async level load (vanilla FUN_0045a530) — brief here (load is sync).
    const uint32_t FADE_IN = 200, HOLD = 12000, FADE_OUT = 200;   // ms (intros)
    const uint32_t LOAD_HOLD = (st.phase == BOOT_LOADING) ? 1800 : 0; // ms (loading screen)
    uint32_t ph_fadeIn = (st.phase == BOOT_LOADING) ? 300 : FADE_IN;
    uint32_t ph_hold   = (st.phase == BOOT_LOADING) ? LOAD_HOLD : HOLD;
    uint32_t ph_fadeOut= (st.phase == BOOT_LOADING) ? 300 : FADE_OUT;
    uint32_t elapsed = now - st.phaseStart;

    if (elapsed < ph_fadeIn)                                  st.fade = (float)elapsed / ph_fadeIn;
    else if (elapsed < ph_fadeIn + ph_hold)                   st.fade = 1.0f;
    else if (elapsed < ph_fadeIn + ph_hold + ph_fadeOut)      st.fade = 1.0f - (float)(elapsed - ph_fadeIn - ph_hold) / ph_fadeOut;
    else                                                      st.fade = 0.0f;
    bool phaseDone = (click || space || elapsed > ph_fadeIn + ph_hold + ph_fadeOut);

    // ── Phase transitions ──
    if (phaseDone && g_bootCfg.atIntro < 0) {   // -at introN freezes the intro for capture
        if (st.phase == BOOT_INTRO) {
            st.introIdx++;
            if (st.introIdx >= 3) {
                // Boot step 14: FUN_004913c0 selects intro_island + the LOADING screen
                // (vanilla FUN_0045a530) shows giants_loading.tga during the level load.
                FUN_004913c0();   // selector (declared at file scope)
                st.phase = BOOT_LOADING;   // intros → loading screen → menu
                if (g_vTrace) { fprintf(g_vTrace, "[BOOT] intros done → LOADING screen (giants_loading.tga)\n"); fflush(g_vTrace); }
            } else {
                if (g_vTrace) { fprintf(g_vTrace, "[BOOT] intro → next (%d)\n", st.introIdx); fflush(g_vTrace); }
            }
        } else if (st.phase == BOOT_LOADING && !g_bootCfg.atLoading) {   // loading screen done → menu
            st.phase = BOOT_MENU;
            if (g_vTrace) { fprintf(g_vTrace, "[BOOT] loading done → MENU phase\n"); fflush(g_vTrace); }
        }
        st.phaseStart = now;
        st.fade = 0.0f;
    }

    // ── Draw current intro phase via the CANONICAL 2D tiled blitter (FUN_00433900 port).
    //    Drives the D3D7 device like the original: +0x98 Clear(0=BLACK) → BeginScene →
    //    tiled blit(introTiles, fade) → EndScene → +0xa8 Present. Replaces the GDI BitBlt
    //    bracket (a fundamental deviation — see behavior_specs/vanilla_2d_render_pipeline.md).
    typedef void (__cdecl *PFN_Cdecl0)(void*);
    typedef void (__cdecl *PFN_Cdecl1i)(void*, uint32_t);
    PFN_Cdecl1i m98 = (PFN_Cdecl1i)(uintptr_t)obj[0x98 / 4];   // Clear/FillBackground
    PFN_Cdecl0  m90 = (PFN_Cdecl0)(uintptr_t)obj[0x90 / 4];    // BeginScene
    PFN_Cdecl0  m94 = (PFN_Cdecl0)(uintptr_t)obj[0x94 / 4];    // EndScene
    PFN_Cdecl0  m_a8 = (PFN_Cdecl0)(uintptr_t)obj[0xa8 / 4];   // Present
    void* device = obj[0x294 / 4];
    // Lazy-load the current intro as 128px tiled D3D7 textures (once per intro).
    static VanillaBlit::TiledImage* s_introTiles[3] = {nullptr,nullptr,nullptr};
    int ii = st.introIdx;
    if (device && st.phase == BOOT_INTRO && ii >= 0 && ii < 3
        && !st.tiledLoaded[ii] && st.resolvedName[ii][0]) {
        st.tiledLoaded[ii] = true;
        s_introTiles[ii] = VanillaBlit::Load(device, st.resolvedGzp[ii], st.resolvedName[ii]);
    }
    // LOADING screen (vanilla FUN_0045a530): giants_loading.tga tiled, shown while the
    // level loads. For the menu/intro level the player char is 'I' → giants_loading.
    static VanillaBlit::TiledImage* s_loadingTile = nullptr;
    static bool s_loadingTried = false;
    if (device && st.phase == BOOT_LOADING && !s_loadingTried) {
        s_loadingTried = true;
        s_loadingTile = VanillaBlit::Load(device, "Bin\\xx_giants_logo_3d.gzp", "giants_loading.tga");
    }
    if (m98) m98(g_vRenderer, 0xFF000000);   // Clear BLACK (vanilla +0x98 Clear(0))
    if (m90) m90(g_vRenderer);               // BeginScene
    if (device && g_vTrace) {
        typedef long (__stdcall *PFN_GetRT)(void*, void**);
        void** dvt = *(void***)device;
        PFN_GetRT grt = (PFN_GetRT)(uintptr_t)dvt[0x24/4];
        void* devRT = nullptr; if (grt) grt(device, &devRT);
        static int s_diag = 0;
        if (s_diag < 1) { fprintf(g_vTrace, "[RTDIAG] device-RT=%p obj+0x28c=%p obj+0x288=%p match28c=%d\n", devRT, obj[0x28c/4], obj[0x288/4], devRT==obj[0x28c/4]); fflush(g_vTrace); s_diag++; }
    }
    // Intro/loading TGAs are larger than the device (intros=1600x1200 vs 640x480 device) →
    // DrawScaled to the device res (vanilla device-fit). giants_loading is 640x480 (1:1).
    int devW = g_videoWidth ? (int)g_videoWidth : 640;
    int devH = g_videoHeight ? (int)g_videoHeight : 480;
    if (device && st.phase == BOOT_INTRO && st.fade > 0.01f
        && ii >= 0 && ii < 3 && s_introTiles[ii]) {
        VanillaBlit::DrawScaled(device, s_introTiles[ii], 0, 0, devW, devH, st.fade);
    }
    if (device && st.phase == BOOT_LOADING) {
        // Loading image as one full-size textured quad (avoids tiled multi-draw issues).
        static void* s_fullLoad = nullptr; static int s_flw=0, s_flh=0; static bool s_tried=false;
        if (!s_tried) { s_tried=true; s_fullLoad = VanillaBlit::LoadFullSurface(device, "Bin\\xx_giants_logo_3d.gzp", "giants_loading.tga", &s_flw, &s_flh); }
        if (s_fullLoad) VanillaBlit::DrawFull(device, s_fullLoad, devW, devH);
        else if (s_loadingTile) VanillaBlit::DrawScaled(device, s_loadingTile, 0, 0, devW, devH, 1.0f);
    }
    if (m94) m94(g_vRenderer);               // EndScene
    // -saveframe: dump the device-RT to a BMP once (clean fidelity check, no window/appsnap/chrome).
    if (device && g_bootCfg.saveFrame[0]) {
        static bool s_saved = false;
        if (!s_saved) {
            bool ok = VanillaSaveDeviceRT(device, g_bootCfg.saveFrame, devW, devH);
            if (g_vTrace) { fprintf(g_vTrace, "[SAVEFRAME] %s -> %s\n", g_bootCfg.saveFrame, ok ? "OK" : "FAIL"); fflush(g_vTrace); }
            s_saved = true;
        }
    }
    obj[0x42c / 4] = (void*)1;
    // Present. The renderer's +0xa8 Present needs a renderer-managed source the recomp can't
    // produce (broken -> white). For 2D phases (intro/loading) use the PROVEN GDI present:
    // BitBlt the device-RT (where VanillaBlit drew) onto the window.
    extern void* g_vHWnd;
    if ((st.phase == BOOT_INTRO || st.phase == BOOT_LOADING) && g_vHWnd) {
        VanillaGdiPresent(device, g_vHWnd, devW, devH, g_vTrace);
    } else if (m_a8) m_a8(g_vRenderer);             // Present (menu/3D phases)
    // NOTE: +0xa8 OBSERVED signature is (this, srcW, srcH, fade, srcSurface) — the renderer blits
    // a source surface + presents. A raw D3D7 tile surface draws at native size (verified: a 128px
    // tile appears top-left), but a full 640x480 surface doesn't fill correctly (texture-size limit
    // + the renderer composites tiled images via its MANAGED format, created by an unknown method,
    // not +0xd8). The recomp's m_a8(obj) with no source is wrong; full fix needs the managed source.
}
