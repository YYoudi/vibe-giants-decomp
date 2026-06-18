// Giants vanilla DX7 capture proxy — gg_dx7r.dll replacement (C5 oracle).
// Deploys AS gg_dx7r.dll (rename the real one to gg_dx7r_orig.dll). Forwards the 2
// vanilla exports (GDVSysCreate, UpCallsLoad) to the real renderer and CAPTURES the
// 21 engine→renderer callbacks from UpCallsLoad(0x2775, 21, table) → giants_dx7_proxy.log.
// This is the ORACLE for bit-exact validation of the recomp's vanilla callback table
// (VanillaRenderer.cpp callbacks[]). Observe mode first (capture); dual-mode after.
#include <windows.h>
#include <cstdio>
#include <cstdint>

static HMODULE g_real = nullptr;
static FILE* g_log = nullptr;

static void Log(const char* fmt, ...) {
    if (!g_log) g_log = fopen("giants_dx7_proxy.log", "a");
    if (!g_log) return;
    va_list ap; va_start(ap, fmt); vfprintf(g_log, fmt, ap); va_end(ap);
    fputc('\n', g_log); fflush(g_log);
}

// Real exports (cdecl).
typedef void* (__cdecl *PFN_GDVSysCreate)(const char*, HWND, void*, void*, void*, void*);
typedef void  (__cdecl *PFN_UpCallsLoad)(uint32_t, uint32_t, void**);
static PFN_GDVSysCreate g_realGDVSysCreate = nullptr;
static PFN_UpCallsLoad  g_realUpCallsLoad  = nullptr;

BOOL APIENTRY DllMain(HMODULE, DWORD reason, LPVOID) {
    if (reason == DLL_PROCESS_ATTACH) {
        g_log = fopen("giants_dx7_proxy.log", "w");
        Log("[DX7PROXY] attach — loading gg_dx7r_orig.dll");
        g_real = LoadLibraryA("gg_dx7r_orig.dll");
        if (!g_real) { Log("[DX7PROXY] FAILED to load gg_dx7r_orig.dll"); return FALSE; }
        g_realGDVSysCreate = (PFN_GDVSysCreate)GetProcAddress(g_real, "GDVSysCreate");
        g_realUpCallsLoad  = (PFN_UpCallsLoad)GetProcAddress(g_real, "UpCallsLoad");
        Log("[DX7PROXY] resolved: GDVSysCreate=%p UpCallsLoad=%p",
            (void*)g_realGDVSysCreate, (void*)g_realUpCallsLoad);
        if (!g_realGDVSysCreate || !g_realUpCallsLoad) { Log("[DX7PROXY] missing export"); return FALSE; }
    } else if (reason == DLL_PROCESS_DETACH) {
        Log("[DX7PROXY] detach");
        if (g_log) { fflush(g_log); fclose(g_log); g_log = nullptr; }
    }
    return TRUE;
}

// Export 1: GDVSysCreate — forward to real (6 cdecl args: cmdLine, hWnd, disp, win, mode, engineCtx).
extern "C" __declspec(dllexport)
void* GDVSysCreate(const char* a, HWND b, void* c, void* d, void* e, void* f) {
    Log("[DX7PROXY] GDVSysCreate(cmdLine=\"%s\", hwnd=%p, ...)", a ? a : "(null)", (void*)b);
    void* r = g_realGDVSysCreate(a, b, c, d, e, f);
    Log("[DX7PROXY] GDVSysCreate -> renderer=%p", r);
    return r;
}

// Export 2: UpCallsLoad — CAPTURE the 21 callbacks, then forward.
extern "C" __declspec(dllexport)
void UpCallsLoad(uint32_t version, uint32_t count, void** table) {
    Log("[DX7PROXY] UpCallsLoad(version=0x%x, count=%u, table=%p)", version, count, (void*)table);
    if (table && count) {
        Log("[DX7PROXY] === 21 engine callbacks (ORACLE CAPTURE) ===");
        for (uint32_t i = 0; i < count && i < 32; i++) {
            Log("[DX7PROXY]   callback[%2u] = %p", i, table[i]);
        }
        Log("[DX7PROXY] === end capture ===");
    }
    g_realUpCallsLoad(version, count, table);
    Log("[DX7PROXY] UpCallsLoad forwarded");
}
