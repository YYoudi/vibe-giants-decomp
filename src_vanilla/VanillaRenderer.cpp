// Vanilla-Native Recomp — Renderer Loader
// Ported from vanilla FUN_0051eb70 (296 bytes). Loads gg_<name>.dll (e.g.
// gg_dx7r.dll) and resolves the 2 vanilla renderer exports: GDVSysCreate +
// UpCallsLoad. NO GFXGetCapabilities (that's a 1.5-era 3rd export).
#include <windows.h>
#include <cstdio>
#include <cstdint>

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
        (void*)Stub_Void,     // 7  SceneBegin
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
typedef void (__cdecl *PFN_RenderMethod0)(void* self);   // (this) methods
extern "C" void VanillaDriveFrame(void (*drawHook)(void)) {
    extern FILE* g_vTrace;
    if (!g_vRenderer) return;
    void** obj = (void**)g_vRenderer;
    void* mBeginClear = obj[0x90 / 4];   // slot +0x90 = 0x86a0 (BeginScene + Clear + scene-open)
    void* mEndScene   = obj[0x94 / 4];   // slot +0x94 = 0x87a0 (EndScene)
    void* mPresent    = obj[0x60 / 4];   // slot +0x60 = 0xc880 (Present/Flip)
    if (!mBeginClear || !mEndScene || !mPresent) {
        if (g_vTrace) { fprintf(g_vTrace, "[VRENDER] DriveFrame: missing method (begin=%p end=%p present=%p)\n", mBeginClear, mEndScene, mPresent); fflush(g_vTrace); }
        return;
    }
    ((PFN_RenderMethod0)mBeginClear)(g_vRenderer);   // BeginScene + Clear
    if (drawHook) drawHook();                        // engine geometry (in-scene)
    ((PFN_RenderMethod0)mEndScene)(g_vRenderer);     // EndScene
    ((PFN_RenderMethod0)mPresent)(g_vRenderer);      // Present
}
