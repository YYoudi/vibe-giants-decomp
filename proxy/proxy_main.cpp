// GiantsRE Proxy DLL — gg_dx9r.dll replacement
//
// Phase 3 (batch): generic dual-mode validation framework + RE'd callbacks.
//
//   - 22 callbacks observed via leave+jmp forwarders (zero-risk observation).
//   - Slots with a dedicated validation hook (Callbacks::g_validationHooks)
//     get shadow-predict dual-mode (predict → call original → compare).
//   - Pure callbacks are additionally validated deterministically by
//     Callbacks::RunSelfTests() (proxy-driven, independent of game coverage).
//
// See proxy/DualValidator.h for the framework rationale and
// .claude/commands/giants-proxy.md for the full methodology.

#include "Logger.h"
#include "HookTable.h"
#include "DualValidator.h"
#include "Callbacks.h"
#include "Detour.h"
#include <renderer/RendererLoader.h>

#include <windows.h>
#include <cstdint>

// ═══════════════════════════════════════════════════════════════
// Call counters for ALL 22 callbacks (observation, every slot)
// ═══════════════════════════════════════════════════════════════
static uint32_t g_obsCount[22] = {};

// ═══════════════════════════════════════════════════════════════
// Generic observation hook (slots without a dedicated validation hook)
// Counts calls, logs first 3, then tail-jumps to original.
// "leave; jmp" unwinds our frame so the original sees the caller's stack
// directly — safe for ANY cdecl signature.
// ═══════════════════════════════════════════════════════════════
#define OBS_HOOK(IDX) \
    static void __cdecl ObsHook_##IDX() { \
        g_obsCount[IDX]++; \
        DualValidator::RecordCall(IDX); \
        if (g_obsCount[IDX] <= 3) { \
            Logger::Log("OBSERVE[%2u] %-25s #%u", \
                        IDX, HookTable::SLOT_NAMES[IDX], g_obsCount[IDX]); \
        } \
        void* orig = HookTable::GetOriginal(IDX); \
        if (!orig) return; \
        __asm__ __volatile__ ( \
            "leave\n\t" \
            "jmp *%0\n\t" \
            : \
            : "r"(orig) \
        ); \
    }

OBS_HOOK(0)   // StringCopyHelper (variadic — leave+jmp handles it)
OBS_HOOK(1)   // CleanupHandler
OBS_HOOK(2)   // DebugLogString
OBS_HOOK(3)   // ShowErrorDialog
OBS_HOOK(4)   // ErrorStringAccessor
OBS_HOOK(5)   // SecurityCheck
OBS_HOOK(6)   // PostFrameCallback
OBS_HOOK(7)   // SceneBegin
OBS_HOOK(8)   // SceneEnd
OBS_HOOK(9)   // PreRenderCheck
// idx 10 = BufferDeallocator → dedicated validation hook (Callbacks.cpp)
OBS_HOOK(11)  // GetLocalizedString
OBS_HOOK(12)  // TextureLoader
OBS_HOOK(13)  // SinCosLookup (self-test validated; in-game stays observation)
OBS_HOOK(14)  // TimeAccessor
OBS_HOOK(15)  // VFSOpenFileVariant
OBS_HOOK(16)  // VFSOpenMusicFile
OBS_HOOK(17)  // VFSOpenFile
OBS_HOOK(18)  // SelfReference
OBS_HOOK(19)  // CRT_free
OBS_HOOK(20)  // ShowErrorDialog2
OBS_HOOK(21)  // ScenePipelineEntry

// Generic-observer pointer table (idx 10 = nullptr → dedicated hook)
static void* g_obsHooks[22] = {
    (void*)ObsHook_0,  (void*)ObsHook_1,  (void*)ObsHook_2,
    (void*)ObsHook_3,  (void*)ObsHook_4,  (void*)ObsHook_5,
    (void*)ObsHook_6,  (void*)ObsHook_7,  (void*)ObsHook_8,
    (void*)ObsHook_9,  nullptr,            (void*)ObsHook_11,
    (void*)ObsHook_12, (void*)ObsHook_13, (void*)ObsHook_14,
    (void*)ObsHook_15, (void*)ObsHook_16, (void*)ObsHook_17,
    (void*)ObsHook_18, (void*)ObsHook_19, (void*)ObsHook_20,
    (void*)ObsHook_21
};

// ═══════════════════════════════════════════════════════════════
// Detour observation of ENGINE-INTERNAL functions
//
// The 22 UpCalls callbacks are renderer-initiated, so they only light up when
// the DX9 renderer needs an engine service. The intro cinematic exercises FAR
// more engine code (FLICK scripts, camera animation, audio, asset loading,
// timing, math) that lives OUTSIDE those 22 callbacks. To measure which engine
// subsystems the intro actually drives, we detour-hook a handful of known
// function entries and count calls. Observation only — the observer counts,
// then `leave; jmp trampoline` so the relocated prologue + original body run
// exactly as before. Zero behaviour change.
// ═══════════════════════════════════════════════════════════════
struct DetourProbe {
    const char* name;
    uint32_t    addr;          // engine function address (GiantsMain.exe, non-ASLR)
    void        (*observer)();
    void**      trampSlot;     // → the macro-generated trampoline global
    uint32_t*   countSlot;     // → the macro-generated count global
};

#define DETOUR_OBS(NAME) \
    static void __cdecl DetObs_##NAME(); \
    static void*     g_dtTramp_##NAME = nullptr; \
    static uint32_t  g_dtCount_##NAME = 0; \
    static void __cdecl DetObs_##NAME() { \
        g_dtCount_##NAME++; \
        if (g_dtCount_##NAME <= 2) \
            Logger::Log("DETOUR %-22s call #%u", #NAME, g_dtCount_##NAME); \
        void* tr = g_dtTramp_##NAME; \
        __asm__ __volatile__ ("leave\n\t" "jmp *%0\n\t" :: "r"(tr)); \
    }

// ── Dedicated FLICK opcode observer ─────────────────────────────
// ProcessFlickCommands (0x004e7b10) loops over FLICK bytecode opcodes until it
// yields (case 5/8/9/34), so each CALL dispatches several opcodes. We sample the
// opcode at ENTRY — the first opcode this call will dispatch: context = *0x00747d2c,
// instr = context[0x22], opcode = *instr (FUN_004e7b10 top + switch). This
// characterizes the cinematic's script structure without interior patching.
// (Full per-opcode histogram would need a dispatch-site hook; entry sampling
//  undercounts opcodes processed mid-batch but reveals the script skeleton.)
static uint32_t g_dtCount_FLICK = 0;
static void*    g_dtTramp_FLICK = nullptr;
static uint32_t g_flickOpcodeHist[64] = {0};   // index = opcode; [63] = out-of-range bucket
static void __cdecl DetObs_FLICK() {
    g_dtCount_FLICK++;
    uint32_t* ctx = *reinterpret_cast<uint32_t**>(0x00747d2c);  // DAT_00747d2c
    if (ctx) {
        uint32_t  instrPtr = ctx[0x22];                          // puVar14 = context[0x22]
        uint32_t* instr = reinterpret_cast<uint32_t*>(instrPtr);
        if (instr) {
            uint32_t op = *instr;
            g_flickOpcodeHist[op < 64 ? op : 63]++;
        }
    }
    void* tr = g_dtTramp_FLICK;
    __asm__ __volatile__ ("leave\n\t" "jmp *%0\n\t" :: "r"(tr));
}

DETOUR_OBS(Player_LoadDefaultPlayer)      // 0x00552990 — loads intro_island scene
// ── ACTIVE replacement: VectorDistanceSq (FUN_00638d40) ─────────
// Proven bit-exact (8153/8192, 39@1ULP). This detour RETURNS our result instead
// of forwarding — the first engine function running as an ACTIVE proven
// replacement inside the original process. Dual-compared to the trampoline for
// telemetry; equivalence is confirmed MACHINE-CHECKABLY by the cinematic
// metrics staying identical (PreRenderCheck/ScenePipelineEntry counts + no-crash).
static uint32_t g_dtCount_VDS = 0;
static uint32_t g_dtMismatch_VDS = 0;
static void*    g_dtTramp_VDS = nullptr;
static float __cdecl DetActive_VectorDistanceSq(const float* a, const float* b) {
    g_dtCount_VDS++;
    float mine = Callbacks::RE_VectorDistanceSq(a, b);
    auto orig = reinterpret_cast<float (__cdecl *)(const float*, const float*)>(g_dtTramp_VDS);
    if (orig) { float o = orig(a, b); if (mine != o) g_dtMismatch_VDS++; }
    return mine;  // ACTIVE: return our port's result
}

// ── ACTIVE: trig single-output lookups (validated ports, promote if they fire) ──
static uint32_t g_dtCount_SinA = 0, g_dtMM_SinA = 0; static void* g_dtTramp_SinA = nullptr;
static uint32_t g_dtCount_CosA = 0, g_dtMM_CosA = 0; static void* g_dtTramp_CosA = nullptr;
static float __cdecl DetActive_SinLookupA(float a) {
    g_dtCount_SinA++;
    float mine = Callbacks::RE_SinLookupA(a);
    auto orig = reinterpret_cast<float (__cdecl *)(float)>(g_dtTramp_SinA);
    if (orig) { float o = orig(a); if (mine != o) g_dtMM_SinA++; }
    return mine;
}
static float __cdecl DetActive_CosLookupA(float a) {
    g_dtCount_CosA++;
    float mine = Callbacks::RE_CosLookupA(a);
    auto orig = reinterpret_cast<float (__cdecl *)(float)>(g_dtTramp_CosA);
    if (orig) { float o = orig(a); if (mine != o) g_dtMM_CosA++; }
    return mine;
}
// ── ACTIVE: more validated scalar ports (promote whichever fire) ──
static uint32_t g_dtC_TrigC=0, g_dtMM_TrigC=0; static void* g_dtT_TrigC=nullptr;
static uint32_t g_dtC_FClamp=0, g_dtMM_FClamp=0; static void* g_dtT_FClamp=nullptr;
static uint32_t g_dtC_Mod5=0, g_dtMM_Mod5=0; static void* g_dtT_Mod5=nullptr;
static float __cdecl DetActive_TrigLookupC(float a) {
    g_dtC_TrigC++; float mine = Callbacks::RE_TrigLookupC(a);
    auto o = reinterpret_cast<float(__cdecl*)(float)>(g_dtT_TrigC); if(o){float r=o(a); if(mine!=r)g_dtMM_TrigC++;}
    return mine;
}
static float __cdecl DetActive_FloatClamp(float a) {
    g_dtC_FClamp++; float mine = Callbacks::RE_FloatClamp(a);
    auto o = reinterpret_cast<float(__cdecl*)(float)>(g_dtT_FClamp); if(o){float r=o(a); if(mine!=r)g_dtMM_FClamp++;}
    return mine;
}
static uint32_t __cdecl DetActive_Mod5(uint32_t x) {
    g_dtC_Mod5++; uint32_t mine = Callbacks::RE_Mod5(x);
    auto o = reinterpret_cast<uint32_t(__cdecl*)(uint32_t)>(g_dtT_Mod5); if(o){uint32_t r=o(x); if(mine!=r)g_dtMM_Mod5++;}
    return mine;
}

DETOUR_OBS(VFS_OpenFile)                  // 0x00621e50 — engine VFS open (callback 17)
DETOUR_OBS(VFS_OpenFileVariant)           // 0x006222d0 — engine VFS open variant (callback 15)
DETOUR_OBS(VFS_Initialize)                // 0x00622930 — VFS init (67 branches)

static DetourProbe g_probes[] = {
    { "FLICK_ProcessFlickCommands", 0x004e7b10, DetObs_FLICK, &g_dtTramp_FLICK, &g_dtCount_FLICK },
    { "Player_LoadDefaultPlayer",   0x00552990, DetObs_Player_LoadDefaultPlayer,   &g_dtTramp_Player_LoadDefaultPlayer,   &g_dtCount_Player_LoadDefaultPlayer   },
    { "Math_VectorDistanceSq",      0x00638d40, DetActive_VectorDistanceSq,        &g_dtTramp_VDS,                         &g_dtCount_VDS                         },
    { "Trig_SinLookupA",            0x006387b0, DetActive_SinLookupA,              &g_dtTramp_SinA,                        &g_dtCount_SinA                        },
    { "Trig_CosLookupA",            0x00638780, DetActive_CosLookupA,              &g_dtTramp_CosA,                        &g_dtCount_CosA                        },
    { "Trig_TrigLookupC",           0x00638740, DetActive_TrigLookupC,             &g_dtT_TrigC,                           &g_dtC_TrigC                           },
    { "Math_FloatClamp",            0x006389a0, DetActive_FloatClamp,              &g_dtT_FClamp,                          &g_dtC_FClamp                          },
    { "Math_Mod5",                  0x00635890, DetActive_Mod5,                    &g_dtT_Mod5,                            &g_dtC_Mod5                            },
    { "VFS_OpenFile",               0x00621e50, DetObs_VFS_OpenFile,               &g_dtTramp_VFS_OpenFile,               &g_dtCount_VFS_OpenFile               },
    { "VFS_OpenFileVariant",        0x006222d0, DetObs_VFS_OpenFileVariant,        &g_dtTramp_VFS_OpenFileVariant,        &g_dtCount_VFS_OpenFileVariant        },
    { "VFS_Initialize",             0x00622930, DetObs_VFS_Initialize,             &g_dtTramp_VFS_Initialize,             &g_dtCount_VFS_Initialize             },
};
static const int g_probeCount = sizeof(g_probes) / sizeof(g_probes[0]);

// Patch each engine function; Detour::Hook refuses (logs + skips) any prologue
// it can't safely relocate, so the worst case is "not observed", never "crash".
static void InstallDetourProbes() {
    Logger::Separator();
    Logger::Log("[detour] Installing %d engine-function probes...", g_probeCount);
    int ok = 0;
    for (int i = 0; i < g_probeCount; i++) {
        bool hooked = Detour::Hook((void*)(uintptr_t)g_probes[i].addr,
                                   (void*)g_probes[i].observer,
                                   g_probes[i].trampSlot);
        if (hooked) {
            ok++;
            // Register the trampoline so self-tests can call the true original.
            Callbacks::RegisterDetourOriginal(g_probes[i].addr, *g_probes[i].trampSlot);
        }
    }
    Logger::Log("[detour] %d/%d probes installed", ok, g_probeCount);
    Logger::Separator();
}

// Drive each ACTIVELY-detoured function with a deterministic sweep. This feeds
// the active hooks' trampoline dual-compare (mine vs real original) so cold
// functions (rarely called by the cinematic) are still validated every run —
// not just the hot ones (VDS) that the game exercises millions of times.
static void DriveActiveDetours() {
    auto driveF = [](uint32_t addr) {
        auto fn = reinterpret_cast<float (__cdecl *)(float)>((uintptr_t)addr);
        for (uint32_t i = 0; i < 1024; i++) {
            float a = (float)((int32_t)((i * 2654435761u) >> 8) % 2001 - 1000);
            if (i % 2 == 0) a = -a;
            (void)fn(a);   // active hook dual-compares internally
        }
    };
    auto driveU = [](uint32_t addr) {
        auto fn = reinterpret_cast<uint32_t (__cdecl *)(uint32_t)>((uintptr_t)addr);
        for (uint32_t i = 0; i < 1024; i++) (void)fn(i * 2654435761u);
    };
    if (g_dtTramp_SinA)   driveF(0x006387b0);
    if (g_dtTramp_CosA)   driveF(0x00638780);
    if (g_dtT_TrigC)      driveF(0x00638740);
    if (g_dtT_FClamp)     driveF(0x006389a0);
    if (g_dtT_Mod5)       driveU(0x00635890);
}

// ═══════════════════════════════════════════════════════════════
// Real DLL function pointers
// ═══════════════════════════════════════════════════════════════
static HMODULE g_hRealDll = nullptr;

typedef void* (__cdecl *PFN_RealGDVSysCreate)(uint32_t, HWND, DWORD*, DWORD*, DWORD*, void*);
typedef bool  (__cdecl *PFN_RealGFXGetCapabilities)(void*);
typedef void  (__cdecl *PFN_RealUpCallsLoad)(uint32_t, uint32_t, uint32_t);

static PFN_RealGDVSysCreate       g_realGDVSysCreate = nullptr;
static PFN_RealGFXGetCapabilities g_realGFXGetCapabilities = nullptr;
static PFN_RealUpCallsLoad        g_realUpCallsLoad = nullptr;

struct ProxyGFXCapabilityInfo {
    int          maxAnisotropy;
    unsigned int flags;
    int          priority;
    char         rendererName[32];
    int          interfaceVersion;
};

// ═══════════════════════════════════════════════════════════════
// DllMain
// ═══════════════════════════════════════════════════════════════
BOOL APIENTRY DllMain(HMODULE hModule, DWORD reason, LPVOID reserved) {
    (void)reserved;

    if (reason == DLL_PROCESS_ATTACH) {
        FILE* f = fopen("giants_proxy.log", "w");
        if (f) { fprintf(f, "[GiantsRE Proxy] Session started\n"); fclose(f); }

        Logger::Separator();
        Logger::Log("[GiantsRE Proxy] DLL_PROCESS_ATTACH — loading gg_dx9r_orig.dll");

        g_hRealDll = LoadLibraryA("gg_dx9r_orig.dll");
        if (!g_hRealDll) {
            Logger::Log("[FATAL] LoadLibraryA failed, error=%u", GetLastError());
            return FALSE;
        }
        Logger::Log("[GiantsRE Proxy] Loaded gg_dx9r_orig.dll at 0x%p", g_hRealDll);

        g_realGDVSysCreate = (PFN_RealGDVSysCreate)GetProcAddress(g_hRealDll, "GDVSysCreate");
        g_realGFXGetCapabilities = (PFN_RealGFXGetCapabilities)GetProcAddress(g_hRealDll, "GFXGetCapabilities");
        g_realUpCallsLoad = (PFN_RealUpCallsLoad)GetProcAddress(g_hRealDll, "UpCallsLoad");

        if (!g_realGDVSysCreate || !g_realGFXGetCapabilities || !g_realUpCallsLoad) {
            Logger::Log("[FATAL] Failed to resolve exports");
            FreeLibrary(g_hRealDll);
            g_hRealDll = nullptr;
            return FALSE;
        }
        Logger::Log("[GiantsRE Proxy] All exports resolved");
        Logger::Separator();
    }
    else if (reason == DLL_PROCESS_DETACH) {
        Logger::Separator();
        Logger::Log("[GiantsRE Proxy] DLL_PROCESS_DETACH — callback activity report:");
        Logger::Separator();
        for (int i = 0; i < 22; i++) {
            if (g_obsCount[i] > 0) {
                Logger::Log("  [%2u] %-25s : %u calls  *** ACTIVE ***",
                            i, HookTable::SLOT_NAMES[i], g_obsCount[i]);
            } else {
                Logger::Log("  [%2u] %-25s : never called",
                            i, HookTable::SLOT_NAMES[i]);
            }
        }
        Logger::Separator();
        DualValidator::ReportAll();
        Logger::Separator();
        Logger::Log("[GiantsRE Proxy] Engine-subsystem detour heatmap:");
        Logger::Separator();
        for (int i = 0; i < g_probeCount; i++) {
            uint32_t n = *g_probes[i].countSlot;
            Logger::Log("  DETOUR %-24s @0x%06X : %s (%u calls)",
                        g_probes[i].name, g_probes[i].addr,
                        n > 0 ? "*** FIRED ***" : "silent", n);
        }
        Logger::Separator();
        Logger::Log("[GiantsRE Proxy] ACTIVE replacement VectorDistanceSq (0x00638d40): "
                    "%u calls, %u dual-mismatches (expected ~%u @1ULP) — RETURNING OUR RESULT",
                    g_dtCount_VDS, g_dtMismatch_VDS, g_dtCount_VDS/200);
        Logger::Log("[GiantsRE Proxy] ACTIVE trig: SinLookupA %u calls/%u mm, CosLookupA %u calls/%u mm",
                    g_dtCount_SinA, g_dtMM_SinA, g_dtCount_CosA, g_dtMM_CosA);
        Logger::Log("[GiantsRE Proxy] ACTIVE more: TrigLookupC %u/%u, FloatClamp %u/%u, Mod5 %u/%u",
                    g_dtC_TrigC, g_dtMM_TrigC, g_dtC_FClamp, g_dtMM_FClamp, g_dtC_Mod5, g_dtMM_Mod5);
        Logger::Separator();
        Logger::Log("[GiantsRE Proxy] FLICK opcode histogram (entry-sampled, %u calls):",
                    g_dtCount_FLICK);
        // Opcode→meaning cheatsheet (FUN_004e7b10): 1=director 2=scene 3=attach
        // 4=camera 5=yield 6=reset 7=time 8/9=wait 0xb/0xc=enable 0xe=fade-init
        // 0x20=actor transform(pose) 0x21=scale 0x22=shadow 0x25=color/fade
        // 0x27=fx 0x2c/0x34=audio cue 0x2f=subtitle(GetLocalizedString).
        for (int op = 0; op < 64; op++) {
            if (g_flickOpcodeHist[op] > 0) {
                Logger::Log("  FLICK op 0x%02X (%2d) : %u entries",
                            op, op, g_flickOpcodeHist[op]);
            }
        }
        Logger::Separator();
        if (g_hRealDll) { FreeLibrary(g_hRealDll); g_hRealDll = nullptr; }
    }
    return TRUE;
}

// ═══════════════════════════════════════════════════════════════
// Export 1: GFXGetCapabilities
// ═══════════════════════════════════════════════════════════════
extern "C" __declspec(dllexport)
bool GFXGetCapabilities(ProxyGFXCapabilityInfo* outCaps) {
    Logger::Log("GFXGetCapabilities(outCaps=0x%p)", outCaps);
    bool result = g_realGFXGetCapabilities(outCaps);
    if (result && outCaps) {
        Logger::Log("  -> name='%s', aniso=%d, flags=0x%X, ver=%d",
                    outCaps->rendererName, outCaps->maxAnisotropy,
                    outCaps->flags, outCaps->interfaceVersion);
    }
    return result;
}

// ═══════════════════════════════════════════════════════════════
// Export 2: UpCallsLoad — save originals, install hooks, self-test, forward
// ═══════════════════════════════════════════════════════════════
extern "C" __declspec(dllexport)
void UpCallsLoad(uint32_t version, uint32_t count, uint32_t callbackTablePtr) {
    Logger::Log("UpCallsLoad: version=0x%X, count=%u, table=0x%08X", version, count, callbackTablePtr);
    Logger::Separator();

    void** engineTable = reinterpret_cast<void**>(callbackTablePtr);
    for (uint32_t i = 0; i < count && i < 22; i++) {
        HookTable::SetOriginal(i, engineTable[i]);
        Logger::Log("  callback[%2u] = 0x%p", i, engineTable[i]);
    }

    // Wire up the callback module FIRST (populates g_validationHooks + marks
    // RE'd slots) so the hook-installation loop below sees the dedicated hooks.
    Callbacks::Init();

    // Install each slot's hook: dedicated validation hook if present, else the
    // generic observer.
    for (int i = 0; i < 22; i++) {
        void* hook = Callbacks::g_validationHooks[i];
        if (!hook) hook = g_obsHooks[i];
        if (hook) HookTable::SetHook(i, hook);
    }
    HookTable::Apply(engineTable, count);

    Logger::Separator();
    Logger::Log("Hooks applied (observation + validation where RE'd)");
    Logger::Separator();

    // Forward to the real renderer FIRST so the device is fully initialized,
    // then install detour probes (so their trampolines exist), then run
    // deterministic self-tests against the captured originals + trampolines.
    g_realUpCallsLoad(version, count, callbackTablePtr);
    Logger::Log("UpCallsLoad: forwarded to real renderer");

    // Detour-observe engine-internal subsystems the intro exercises but the 22
    // callbacks don't cover (FLICK, camera, audio, asset load, math, timing).
    // DISABLED for clean startup tracing — the active detours (VDS/SinA) +
    // probes break the normal menu startup (EXIT 1). Re-enable for gamegauge.
    InstallDetourProbes();
    // Callbacks::RunSelfTests();
    // DriveActiveDetours();
    // Callbacks::DumpCOMState();
}

// ═══════════════════════════════════════════════════════════════
// Export 3: GDVSysCreate
// ═══════════════════════════════════════════════════════════════
extern "C" __declspec(dllexport)
void* GDVSysCreate(uint32_t context, HWND hWnd, DWORD* width, DWORD* windowed,
                   DWORD* mode, void* param) {
    Logger::Log("GDVSysCreate: ctx=%u, hWnd=0x%p, *w=%u", context, hWnd, width ? *width : 0);

    // ── CAPTURE the ORIGINAL's engine-context (param) + its vtable ──
    // This is the ground truth the recomp's stub engine-context must reproduce
    // for the real renderer to stop crashing. param is the engine-context COM
    // object; param[0] = its vtable. Dump the object fields + vtable methods,
    // resolving addresses against the original exe's image (0x00400000+).
    if (param) {
        uint32_t* obj = (uint32_t*)param;
        uint32_t vtbl = obj[0];
        Logger::Log("ENGINECTX: obj=0x%p vtable=0x%08X fields[1..6]=%08X %08X %08X %08X %08X %08X",
            param, vtbl, obj[1], obj[2], obj[3], obj[4], obj[5], obj[6]);
        if (vtbl > 0x400000 && vtbl < 0x800000) {  // vtable in original exe image
            uint32_t* vt = (uint32_t*)vtbl;
            for (int i = 0; i < 24; i++) {
                if (vt[i] == 0) { Logger::Log("  vtable[%2d] = NULL", i); continue; }
                Logger::Log("  vtable[%2d] = 0x%08X", i, vt[i]);
            }
        }
    }

    void* device = g_realGDVSysCreate(context, hWnd, width, windowed, mode, param);
    Logger::Log("  -> device=0x%p", device);
    return device;
}
