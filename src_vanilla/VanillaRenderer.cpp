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
        (void*)Stub_EmptyStr, // 11 GetLocalizedString
        (void*)Stub_Void,     // 12 TextureLoader
        (void*)Stub_Void,     // 13 SinCosLookup
        (void*)Stub_Void,     // 14 TimeAccessor
        (void*)Stub_Null,     // 15 VFSOpenFileVariant
        (void*)Stub_Null,     // 16 VFSOpenMusicFile
        (void*)Stub_Null,     // 17 VFSOpenFile
        (void*)Stub_Null,     // 18 SelfReference
        (void*)Stub_Free,     // 19 CRT_free
        (void*)Stub_Void,     // 20 ScenePipelineEntry
    };

    // UpCallsLoad(version=0x2775, count=21, table).
    typedef void (__cdecl *PFN_UpCallsLoad)(uint32_t, uint32_t, void**);
    reinterpret_cast<PFN_UpCallsLoad>(g_UpCallsLoad)(0x2775, 21, callbacks);
    if (g_vTrace) { fprintf(g_vTrace, "[VRENDER] UpCallsLoad(0x2775, 21) called\n"); fflush(g_vTrace); }

    // GDVSysCreate — vanilla DX7 has 9 params (NOT the 1.5's 6-param signature!):
    //   GDVSysCreate(lpCmdLine, configStruct, width, height, bpp, ?, windowed, &dispCfg, &modeCfg)
    // The vanilla WinMain (0x5222c0) calls it with width=0x1e0(480) initially,
    // retrying with 640x480 if it returns NULL. configStruct (DAT_005dca50) is a
    // zeroed 0x104-byte buffer (hWnd may be at offset 0 — testing). engineCtx=NULL
    // (no COM registry — the 1.5 6th param doesn't exist in vanilla).
    // GDVSysCreate param 2 = hWnd directly (DAT_005dca50 = CreateWindowExA return).
    uint32_t dispCfg[8] = {0};
    uint32_t modeCfg[8] = {0};
    extern const char* __lpCmdLine;
    typedef void* (__cdecl *PFN_GDVSysCreate_9)(const char*, HWND, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, void*, void*);
    void* device = reinterpret_cast<PFN_GDVSysCreate_9>(g_GDVSysCreate)(
        __lpCmdLine ? __lpCmdLine : "", hWnd, 640, 480, 16, 0, 1, dispCfg, modeCfg);
    if (g_vTrace) { fprintf(g_vTrace, "[VRENDER] GDVSysCreate(hWnd=%p, 640x480) -> device=%p\n", hWnd, device); fflush(g_vTrace); }
    return device;
}
