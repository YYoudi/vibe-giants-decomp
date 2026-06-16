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
