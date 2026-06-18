// Giants vanilla DX7 capture proxy — gg_dx7r.dll replacement (C5 oracle).
// Deploys AS gg_dx7r.dll (rename the real one to gg_dx7r_orig.dll). Forwards the 2
// vanilla exports (GDVSysCreate, UpCallsLoad) to the real renderer and CAPTURES the
// 21 engine→renderer callbacks from UpCallsLoad(0x2775, 21, table) → giants_dx7_proxy.log.
// This is the ORACLE for bit-exact validation of the recomp's vanilla callback table
// (VanillaRenderer.cpp callbacks[]). Observe mode first (capture); dual-mode after.
#include <windows.h>
#include <psapi.h>
#include <cstdio>
#include <cstdint>

static HMODULE g_real = nullptr;
static FILE* g_log = nullptr;

// D3D7 trace-hook state (forward-declared; defined/used in the hook section below).
static void** g_vtCopy = nullptr;
static void*  g_orig[88];
static void*  g_dev = nullptr;
static uint32_t c_setTex = 0, c_dp = 0, c_dpvb = 0, c_stss = 0, c_sr = 0, c_xform = 0, c_clear = 0;
static uint32_t c_dip = 0, c_dps = 0, c_dips = 0, c_dpvb6 = 0, c_dipvb8 = 0, c_mtx = 0;
static uint32_t g_frame = 0;
static uint32_t g_setTexLogged = 0;
static void InstallD3D7Hooks(void* wrapper);   // forward decl (defined in hook section)

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
        // Enumerate loaded modules to find which DLL contains the wrapper vtable (0x63xxxxx range).
        {
            HMODULE mods[256]; DWORD needed = 0;
            if (EnumProcessModules(GetCurrentProcess(), mods, sizeof(mods), &needed)) {
                int count = needed / sizeof(HMODULE);
                for (int i = 0; i < count; i++) {
                    char name[256] = {0};
                    GetModuleBaseNameA(GetCurrentProcess(), mods[i], name, sizeof(name)-1);
                    Log("[DX7PROXY] module: %p %s", (void*)mods[i], name);
                }
            }
        }
    } else if (reason == DLL_PROCESS_DETACH) {
        Log("[DX7PROXY] detach — total frames captured: %u", g_frame);
        Log("[DX7PROXY] last frame: SetTexture=%u DP=%u DIP=%u DPS=%u DIPS=%u DPVB=%u DIPVB=%u "
            "SetTSS=%u SetRS=%u SetXform=%u MulXform=%u Clear=%u",
            c_setTex, c_dp, c_dip, c_dps, c_dips, c_dpvb6, c_dipvb8, c_stss, c_sr, c_xform, c_mtx, c_clear);
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
    // Dump the wrapper@obj+0x294 vtable (all function addresses) for offline disasm.
    if (r) {
        char** obj = (char**)r;
        void* wrapper = *(void**)(obj + 0x294/sizeof(char*));
        if (wrapper) {
            void** vtbl = *(void***)wrapper;
            Log("[DX7PROXY] === WRAPPER VTABLE DUMP (obj+0x294=%p, vtbl=%p) ===", wrapper, vtbl);
            for (uint32_t off = 0; off < 0x160; off += 4) {
                void* fn = vtbl[off/4];
                if (!fn) continue;
                // Resolve which module owns this vtable slot (pinpoint DrawPrim/SetTexture DLL).
                HMODULE mfn = nullptr;
                char mnm[256] = {0};
                GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT,
                                   (LPCSTR)fn, &mfn);
                if (mfn) GetModuleBaseNameA(GetCurrentProcess(), mfn, mnm, sizeof(mnm)-1);
                unsigned offInMod = mfn ? (unsigned)((uintptr_t)fn - (uintptr_t)mfn) : 0;
                Log("[DX7PROXY]   wvt[0x%03x] = %p  [%s+0x%x]", off, fn, mnm[0] ? mnm : "?", offInMod);
            }
            Log("[DX7PROXY] === END WRAPPER VTABLE ===");
        }
        // Enumerate modules AFTER GDVSysCreate (all DLLs now loaded) to find which DLL
        // contains the wrapper vtable functions (0x63xxxxx range).
        HMODULE mods[512]; DWORD needed = 0;
        if (EnumProcessModules(GetCurrentProcess(), mods, sizeof(mods), &needed)) {
            int count = needed / sizeof(HMODULE);
            Log("[DX7PROXY] === MODULES (%d) ===", count);
            for (int i = 0; i < count; i++) {
                char nm[256] = {0};
                GetModuleBaseNameA(GetCurrentProcess(), mods[i], nm, sizeof(nm)-1);
                Log("[DX7PROXY]   mod: 0x%08x %s", (unsigned)(uintptr_t)mods[i], nm);
            }
            Log("[DX7PROXY] === END MODULES ===");
        }
        // Install per-object D3D7 trace hooks (SetTexture/DrawPrimitive/...).
        InstallD3D7Hooks(*(void**)((char**)r + 0x294/sizeof(char*)));
    }
    return r;
}

// ─── D3D7 call-trace hooks (per-object vtable-pointer replacement) ───────────
// Replace the wrapper IDirect3DDevice7 object's vtable pointer with a patched
// copy so calls go through our logging thunks (per-object: the shared D3DIM700
// system vtable is untouched). Each thunk logs/counts then forwards to original.
// Slots (byte/4): 0x14 BeginScene, 0x28 Clear, 0x2c SetTransform, 0x50 SetRenderState,
// 0x64 DrawPrimitive, 0x80 DrawIndexedPrimitiveVB, 0x8c SetTexture, 0x94 SetTextureStageState.
// per-frame counters + g_orig/g_dev/g_frame/g_vtCopy declared at file top (DllMain needs them).

typedef long  (__stdcall *PFN_BeginScene)(void*);
typedef long  (__stdcall *PFN_Clear)(void*, uint32_t, void*, uint32_t, uint32_t, float, uint32_t);
typedef long  (__stdcall *PFN_SetXform)(void*, uint32_t, const void*);
typedef long  (__stdcall *PFN_MulXform)(void*, uint32_t, const void*);
typedef long  (__stdcall *PFN_SetRS)(void*, uint32_t, uint32_t);
typedef long  (__stdcall *PFN_DP)(void*, uint32_t, uint32_t, const void*, uint32_t, uint32_t);
typedef long  (__stdcall *PFN_DIP)(void*, uint32_t, uint32_t, const void*, uint32_t, const void*, uint32_t, uint32_t);
typedef long  (__stdcall *PFN_DPS)(void*, uint32_t, uint32_t, void*, uint32_t, uint32_t);
typedef long  (__stdcall *PFN_DIPS)(void*, uint32_t, uint32_t, void*, uint32_t, const void*, uint32_t, uint32_t);
typedef long  (__stdcall *PFN_DPVB)(void*, uint32_t, void*, uint32_t, uint32_t, uint32_t);          // 0x7c DrawPrimitiveVB
typedef long  (__stdcall *PFN_DIPVB)(void*, uint32_t, void*, uint32_t, uint32_t, const void*, uint32_t, uint32_t); // 0x80
typedef long  (__stdcall *PFN_SetTex)(void*, uint32_t, void*);
typedef long  (__stdcall *PFN_STSS)(void*, uint32_t, uint32_t, uint32_t);

static long __stdcall H_BeginScene(void* t) {
    // New frame: emit previous frame's summary, reset counters.
    if (g_frame > 0 && (g_frame <= 8 || (g_frame % 60) == 0)) {
        Log("[DX7PROXY] frame %u: SetTexture=%u DP=%u DIP=%u DPS=%u DIPS=%u DPVB=%u DIPVB=%u "
            "SetTSS=%u SetRS=%u SetXform=%u MulXform=%u Clear=%u",
            g_frame, c_setTex, c_dp, c_dip, c_dps, c_dips, c_dpvb6, c_dipvb8,
            c_stss, c_sr, c_xform, c_mtx, c_clear);
    }
    g_frame++;
    c_setTex=c_dp=c_dip=c_dps=c_dips=c_dpvb6=c_dipvb8=c_stss=c_sr=c_xform=c_mtx=c_clear=0; g_setTexLogged=0;
    return ((PFN_BeginScene)g_orig[0x14/4])(t);
}
static long __stdcall H_Clear(void* t, uint32_t a, void* b, uint32_t c, uint32_t d, float e, uint32_t f) {
    c_clear++; if (g_frame <= 3) Log("[DX7PROXY]   Clear(flags=0x%x color=0x%08x)", c, d);
    return ((PFN_Clear)g_orig[0x28/4])(t, a, b, c, d, e, f);
}
static long __stdcall H_SetTransform(void* t, uint32_t state, const void* mat) {
    c_xform++; if (g_frame <= 2 && c_xform <= 20) Log("[DX7PROXY]   SetTransform(state=%u)", state);
    return ((PFN_SetXform)g_orig[0x2c/4])(t, state, mat);
}
static long __stdcall H_MultiplyTransform(void* t, uint32_t state, const void* mat) {
    c_mtx++; if (g_frame <= 2 && c_mtx <= 20) Log("[DX7PROXY]   MultiplyTransform(state=%u)", state);
    return ((PFN_MulXform)g_orig[0x38/4])(t, state, mat);
}
static long __stdcall H_SetRenderState(void* t, uint32_t s, uint32_t v) {
    c_sr++; if (g_frame <= 2 && c_sr <= 40) Log("[DX7PROXY]   SetRenderState(state=%u val=%u)", s, v);
    return ((PFN_SetRS)g_orig[0x50/4])(t, s, v);
}
static long __stdcall H_DP(void* t, uint32_t prim, uint32_t fvf, const void* verts, uint32_t cnt, uint32_t fl) {
    c_dp++; if (g_frame <= 2 && c_dp <= 20) Log("[DX7PROXY]   DrawPrimitive(prim=%u fvf=0x%x verts=%u)", prim, fvf, cnt);
    return ((PFN_DP)g_orig[0x64/4])(t, prim, fvf, verts, cnt, fl);
}
static long __stdcall H_DIP(void* t, uint32_t prim, uint32_t fvf, const void* v, uint32_t vc, const void* idx, uint32_t ic, uint32_t fl) {
    c_dip++; if (g_frame <= 2 && c_dip <= 20) Log("[DX7PROXY]   DrawIndexedPrimitive(prim=%u fvf=0x%x verts=%u idx=%u)", prim, fvf, vc, ic);
    return ((PFN_DIP)g_orig[0x68/4])(t, prim, fvf, v, vc, idx, ic, fl);
}
static long __stdcall H_DPS(void* t, uint32_t prim, uint32_t vt, void* strided, uint32_t vc, uint32_t fl) {
    c_dps++; if (g_frame <= 2 && c_dps <= 20) Log("[DX7PROXY]   DrawPrimitiveStrided(prim=%u vtype=0x%x verts=%u)", prim, vt, vc);
    return ((PFN_DPS)g_orig[0x74/4])(t, prim, vt, strided, vc, fl);
}
static long __stdcall H_DIPS(void* t, uint32_t prim, uint32_t vt, void* strided, uint32_t vc, const void* idx, uint32_t ic, uint32_t fl) {
    c_dips++; if (g_frame <= 2 && c_dips <= 20) Log("[DX7PROXY]   DrawIndexedPrimitiveStrided(prim=%u vtype=0x%x verts=%u idx=%u)", prim, vt, vc, ic);
    return ((PFN_DIPS)g_orig[0x78/4])(t, prim, vt, strided, vc, idx, ic, fl);
}
static long __stdcall H_DPVB(void* t, uint32_t prim, void* vb, uint32_t st, uint32_t cnt, uint32_t fl) {
    c_dpvb6++; if (g_frame <= 2 && c_dpvb6 <= 20) Log("[DX7PROXY]   DrawPrimitiveVB(prim=%u vb=%p start=%u verts=%u)", prim, vb, st, cnt);
    return ((PFN_DPVB)g_orig[0x7c/4])(t, prim, vb, st, cnt, fl);
}
static long __stdcall H_DIPVB(void* t, uint32_t prim, void* vb, uint32_t st, uint32_t cnt, const void* idx, uint32_t ic, uint32_t fl) {
    c_dipvb8++; if (g_frame <= 2 && c_dipvb8 <= 20) Log("[DX7PROXY]   DrawIndexedPrimitiveVB(prim=%u vb=%p start=%u verts=%u idx=%u)", prim, vb, st, cnt, ic);
    return ((PFN_DIPVB)g_orig[0x80/4])(t, prim, vb, st, cnt, idx, ic, fl);
}
static long __stdcall H_SetTexture(void* t, uint32_t stage, void* surf) {
    c_setTex++;
    if (g_frame <= 3 && g_setTexLogged < 40) { Log("[DX7PROXY]   SetTexture(stage=%u surf=%p)", stage, surf); g_setTexLogged++; }
    return ((PFN_SetTex)g_orig[0x8c/4])(t, stage, surf);
}
static long __stdcall H_STSS(void* t, uint32_t stage, uint32_t type, uint32_t val) {
    c_stss++;
    if (g_frame <= 2 && type == 1 /*COLOROP*/) Log("[DX7PROXY]   SetTSS(stage=%u COLOROP=%u)", stage, val);
    return ((PFN_STSS)g_orig[0x94/4])(t, stage, type, val);
}

static void InstallD3D7Hooks(void* wrapper) {
    if (!wrapper) return;
    g_dev = wrapper;
    void** oldvt = *(void***)wrapper;
    if (!oldvt) return;
    g_vtCopy = (void**)malloc(88 * sizeof(void*));
    if (!g_vtCopy) return;
    memcpy(g_vtCopy, oldvt, 88 * sizeof(void*));
    for (int i = 0; i < 88; i++) g_orig[i] = oldvt[i];
    g_vtCopy[0x14/4] = (void*)H_BeginScene;
    g_vtCopy[0x28/4] = (void*)H_Clear;
    g_vtCopy[0x2c/4] = (void*)H_SetTransform;
    g_vtCopy[0x38/4] = (void*)H_MultiplyTransform;
    g_vtCopy[0x50/4] = (void*)H_SetRenderState;
    g_vtCopy[0x64/4] = (void*)H_DP;       // DrawPrimitive
    g_vtCopy[0x68/4] = (void*)H_DIP;      // DrawIndexedPrimitive
    g_vtCopy[0x74/4] = (void*)H_DPS;      // DrawPrimitiveStrided
    g_vtCopy[0x78/4] = (void*)H_DIPS;     // DrawIndexedPrimitiveStrided
    g_vtCopy[0x7c/4] = (void*)H_DPVB;     // DrawPrimitiveVB (6 args)
    g_vtCopy[0x80/4] = (void*)H_DIPVB;    // DrawIndexedPrimitiveVB (8 args)
    g_vtCopy[0x8c/4] = (void*)H_SetTexture;
    g_vtCopy[0x94/4] = (void*)H_STSS;
    // Overwrite the object's vtable pointer (heap object → writable).
    DWORD oldp = 0;
    VirtualProtect(wrapper, sizeof(void*), PAGE_READWRITE, &oldp);
    *(void***)wrapper = g_vtCopy;
    DWORD tmp = 0; VirtualProtect(wrapper, sizeof(void*), oldp, &tmp);
    Log("[DX7PROXY] D3D7 trace hooks INSTALLED on device %p (vtable %p -> copy %p)", wrapper, oldvt, g_vtCopy);
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
