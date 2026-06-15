// Giants Engine - Initialization Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
//
// FUN_0062e1a0 — InitializeEngine
// Full engine initialization: check state → registry → renderer → RenderDoc →
//   audio → player profile → display settings → input → cursor → replay
//
// Ghidra decompilation corrected phases:
//   Phase A: State check (FUN_005c45f0, g_initialized, g_rendererActive)
//   Phase B: LockGraphics → read renderer name from registry
//   Phase C: LoadGDVSystem → create render device (GDVSysCreate call)
//   Phase D: RenderDoc API detection (renderdoc.dll)
//   Phase E: InitAudioSystem (Miles Sound System)
//   Phase F: Player profile from registry (display mode comparison)
//   Phase G: InitDisplaySettings → InitDisplayMode → InitGraphicsResources
//   Phase H: InitializeDirectInput → hide cursor → volume settings
//   Phase I: Aspect ratio → FinalInit / ProcessReplayFile

#include "EngineInit.h"
#include "GameLoop.h"
#include "DirectInput.h"
#include "TraceLog.h"
#include "ComRegistry.h"
#include "../renderer/RendererLoader.h"
#include <cstdio>
#include <cstdlib>

namespace Giants {

// --- runtime state globals (were *reinterpret_cast derefs; engine-populated) ---
static char g_state_00702a60 = 0;  // was @0x0X00702A60

// Forward declaration — defined in ScenePipeline.cpp
extern void* g_d3d9Device;  // IDirect3DDevice9* (found by scanner)

// ─── Static State ─────────────────────────────────────────────

DWORD g_width           = 0;       // DAT_00702b80
DWORD g_height          = 0;       // DAT_00702b84
DWORD g_bitDepth        = 0;       // DAT_00702b88
DWORD g_refreshRate     = 0;       // DAT_00702b8c
DWORD g_backBufferCount = 0;       // DAT_00702b8d
DWORD g_multisampleType = 0;       // DAT_00702b8e
DWORD g_windowed        = 0;       // DAT_00702b90
DWORD g_vsync           = 0;       // DAT_00702b94
DWORD g_adapterOrdinal  = 0;       // DAT_00702b98
DWORD g_displayMode0    = 0;       // DAT_00702ba0
DWORD g_displayMode1    = 0;       // DAT_00702ba4
DWORD g_displayMode2    = 0;       // DAT_00702ba8
DWORD g_displayMode3    = 0;       // DAT_00702bac

bool  g_initialized       = false; // DAT_007282bc
bool  g_rendererActive    = false; // DAT_00702bd0
char  g_rendererAvailable = 0;     // DAT_00702b5a
char  g_rendererName[32]  = {};    // DAT_007281f0

HKEY  g_hKey            = nullptr; // DAT_0074be54
HKEY  g_hPlayerKey      = nullptr; // DAT_0074be5c
HKEY  g_hPlayerRootKey  = nullptr; // DAT_0074be58
DWORD g_playerId        = 0;       // DAT_007028b0
DWORD g_playerId1       = 0;       // DAT_007028a0
DWORD g_playerId2       = 0;       // DAT_007028a4
float g_aspectRatioX    = 0.0f;    // DAT_00702c1c
float g_aspectRatioY    = 0.0f;    // DAT_00702c20

// RenderDoc API (optional capture tool)
void* g_renderDocAPI    = nullptr; // DAT_0074bbb8 — RENDERDOC_API_1_1_2*

// Engine context object — DAT_0073c924
// Allocated in EngineInitializeImpl (0x1c = 28 bytes), COM-like ref-counted.
// Contains vtable ptr at [0], linked list nodes, passed as 6th param to GDVSysCreate.
// The renderer dereferences [context+0] as a vtable during D3D init:
//   - vtable[2] is called with (void** output, const GUID* iid) via thiscall (ecx=this)
//   - If output is set to NULL, the renderer continues with basic D3D9 (no extensions)
// The vtable must be valid — calloc(0) causes NULL dereference crash at gg_dx9r.dll+0x27B34.
static void* g_engineContext = nullptr; // DAT_0073c924

// ─── Engine context vtable stubs ──────────────────────────────────
// The renderer calls methods on the engine context during D3D device creation.
// Convention: thiscall (ecx = this = engine context), callee cleans stack.
namespace {

    // ── Interface stub object ────────────────────────────────────
    // Returned by engine context vtable[2] when renderer queries GUID {B2D9DF30-...}.
    // The renderer calls vtable[5] on this interface during display init
    // (gg_dx9r.dll+0x20F38-0x20F3D: mov ecx,[esi+0xc]; mov eax,[ecx]; call [eax+0x14]).
    // vtable[5] returns a pointer to a writable state object (0x100+ bytes)
    // that the renderer fills with key bindings, flags, and function pointers.
    struct InterfaceStub {
        void** vtable;   // [0x00] pointer to vtable array
        int    refCount;  // [0x04] COM-like ref count
        int    pad[2];    // [0x08-0x0C] padding
    };

    // Renderer state buffer — returned by vtable[5].
    // The renderer writes to offsets up to +0xE0 (key bindings, flags, fn pointers).
    // Must be writable and at least 0x100 bytes.
    static DWORD g_rendererState[128] = {}; // 512 bytes, zeroed

    // Accessor for dumping state from InitializeEngine
    DWORD* GetRendererState() { return g_rendererState; }

    static long __stdcall Iface_Vtbl0() { return 0; }
    static long __stdcall Iface_Vtbl1() { return 1; }
    static long __stdcall Iface_Vtbl2() { return 0; }
    static long __stdcall Iface_Vtbl3() { return 0; }
    static long __stdcall Iface_Vtbl4() { return 0; }
    // vtable[5] — called at gg_dx9r.dll+0x20F3D after ShowWindow/UpdateWindow.
    // Must return a pointer to a writable buffer (at least 0xE8 bytes).
    // The renderer fills it with key bindings, flags, and function pointers.
    // The return value is saved to gg_dx9r.dll global 0x10068b58.
    static long __stdcall Iface_Vtbl5() {
        return reinterpret_cast<long>(g_rendererState);
    }
    static long __stdcall Iface_Vtbl6() { return 0; }
    static long __stdcall Iface_Vtbl7() { return 0; }

    static void* g_interfaceVtable[8] = {
        (void*)&Iface_Vtbl0,
        (void*)&Iface_Vtbl1,
        (void*)&Iface_Vtbl2,
        (void*)&Iface_Vtbl3,
        (void*)&Iface_Vtbl4,
        (void*)&Iface_Vtbl5,
        (void*)&Iface_Vtbl6,
        (void*)&Iface_Vtbl7,
    };

    // The interface object — lives for the process lifetime
    static InterfaceStub g_interfaceStub = {
        &g_interfaceVtable[0],
        1,
        { 0, 0 }
    };

    // ── Engine context vtable ────────────────────────────────────

    // vtable[0] — unknown init/query, returns S_OK
    static long __stdcall EngineContext_Vtbl0() {
        return 0; // S_OK
    }

    // vtable[1] — unknown, returns 1 (likely AddRef)
    static long __stdcall EngineContext_Vtbl1() {
        return 1;
    }

    // vtable[2] — GetInterface(void** output, const GUID* iid)
    // Renderer queries for GUID {B2D9DF30-25ED-4312-9DC2-343DAE156182} during D3D init.
    // The returned interface is used in gg_dx9r.dll+0x20F38 (vtable[5] call).
    // Stack params: [esp+4]=output, [esp+8]=iid. Callee cleans (ret 8).
    static long __stdcall EngineContext_Vtbl2(void* output, const void* /*iid*/) {
        if (output) *((void**)output) = &g_interfaceStub;
        return 0; // S_OK
    }

    // vtable entries (indices 3+ padded for safety)
    static void* g_engineContextVtable[16] = {
        (void*)&EngineContext_Vtbl0,
        (void*)&EngineContext_Vtbl1,
        (void*)&EngineContext_Vtbl2,
        nullptr, nullptr, nullptr, nullptr,
        nullptr, nullptr, nullptr, nullptr,
        nullptr, nullptr, nullptr, nullptr
    };

} // anonymous namespace

// Crash-diagnostic accessors (Giants scope; access file/anon statics in this TU).
void* GetEngineContextPtr() { return g_engineContext; }
DWORD* GetRendererStatePtr() { return g_rendererState; }  // anon member, TU-visible

// Callback function pointers from renderer UpCalls table
extern void (*g_fnRegisterTimer)(DWORD interval, void* callback);  // DAT_0072801c → (*)(0x2C, DAT_0074c468)
extern void (*g_fnUpdateFrame)();                                    // DAT_00728004 → (*)(void)

// Audio volume setters (function pointers from Miles/MSS)
extern void (*g_setMusicVolume)(DWORD volume);  // DAT_0072805c
extern void (*g_setSoundVolume)(DWORD volume);  // DAT_0072803c

// Registry default for volumes
extern DWORD g_defaultVolume;  // DAT_0066bea0

// Aspect ratio scaling factor
extern float g_aspectScale;    // DAT_0066be20

// Error state globals
static int  g_errorShown       = 0;      // DAT_007281e4 — error dialog shown flag
static char g_audioErrorTarget[256] = {}; // Error message buffer for audio init failure

// ─── Stub implementations for forward-declared callees ────────
// Placeholder no-ops until each function is fully reversed.

// PreInitCheck (FUN_005c45f0) — the root init orchestrator (430 lines, 36 callees).
// Ported with essential steps + guarded callees so the init advances past the
// stub. Each step logs to trace + continues on failure (the original aborts on
// hard failures, but for reconstruction we want max progress).
int PreInitCheck()
{
    extern FILE* g_traceLog;
    extern void InitCOMSubsystem_Real();
    extern void InitStringSubsystem_Real();
    extern void RegisterGameContext();

    // Phase 1: Version log (original: FUN_005f0fe0 + vformat + FUN_0043f440)
    if (g_traceLog) { fprintf(g_traceLog, "[INIT] PreInitCheck: Starting Giants v1.520.59\n"); fflush(g_traceLog); }

    // Phase 2: COM init + RNG seed (original: CoInitialize + timeGetTime + srand)
    CoInitialize(nullptr);
    DWORD seed = timeGetTime() & 0x7FFF;
    srand(seed);
    if (g_traceLog) { fprintf(g_traceLog, "[INIT] CoInitialize + srand(%d)\n", seed); fflush(g_traceLog); }

    // Phase 3: Trig table precompute (FUN_00638e40 — fills sin/cos/acos tables).
    // The recomp has these embedded (kSinTable/kCosTable, dumped from the
    // original's runtime). No-op here — tables already present.
    if (g_traceLog) { fprintf(g_traceLog, "[INIT] Trig tables precomputed (embedded)\n"); fflush(g_traceLog); }

    // Phase 4: Init COM subsystem (FUN_0042fc00 — creates + registers core COM obj)
    InitCOMSubsystem_Real();

    // Phase 5: Factory init (FUN_0046fd40 — create factory object via DAT_00660194)
    RegisterFactoryInit();

    // Phase 6: Register game context + callbacks (FUN_005c4400 + object creation)
    RegisterGameContext();
    RegisterCallbacks();

    // Phase 7: Create the 4 COM objects (original: operator_new + vtable + register
    // via DAT_0073c924->vtable[1]). The objects have vtables PTR_FUN_0066a574,
    // PTR_FUN_00660250, PTR_FUN_0065dc80. Stubbed — ComRegistry provides the
    // functional equivalent.

    // Phase 8: Init string subsystem (FUN_00443e20)
    InitStringSubsystem_Real();

    // Phase 9: Launcher pipe protocol (ReadFile magic 0x02/0x7a330000)
    // Skipped — -launcher flag bypasses this.

    // Phase 10: Get game context + init level (FUN_00461a60 + FUN_00501f50)
    // These run during LoadDefaultPlayer (already wired).

    if (g_traceLog) { fprintf(g_traceLog, "[INIT] PreInitCheck done — registry count=%d\n", ComRegistryCount()); fflush(g_traceLog); }
    return 1;  // success
}
int  InitAudioSystem() { return 1; }        // FUN_0062af40
void InitDisplaySettings() {}               // FUN_004f86c0
void InitDisplayMode() {}                   // FUN_0062b9c0
// InitGraphicsResources (FUN_004f7fa0) is defined in GraphicsResources.cpp —
// real body that creates devices/buffers via the renderer factory. Do NOT stub
// it here (was a duplicate-definition link error).
void FinalInit() {}                         // FUN_0062f7e0
void InitNetwork() {}                       // FUN_004f8550
void SavePlayerProfile() {}                 // FUN_00540770
void SavePlayerSettings() {}                // FUN_005403e0
void LastInitStep() {}                      // FUN_00552990
void ShowErrorDialog(const char*) {}        // FUN_0062edc0
void ClearString() {}                       // FUN_004439b0
void DebugLog(const char*) {}               // FUN_00461f00
const char* GetLocalizedString(const char* key) { return key; } // FUN_005e80c0
void FormatString(const char*, void*) {}    // FUN_00463000
void FormatStringArg(const char*, const char*) {} // fmt::vformat wrapper

// Callback function pointer stubs (will be loaded from renderer DLL)
void (*g_fnRegisterTimer)(DWORD, void*) = nullptr;  // DAT_0072801c
void (*g_fnUpdateFrame)()                = nullptr;  // DAT_00728004
void (*g_setMusicVolume)(DWORD)          = nullptr;  // DAT_0072805c
void (*g_setSoundVolume)(DWORD)          = nullptr;  // DAT_0072803c

DWORD g_defaultVolume = 100;  // DAT_0066bea0
float g_aspectScale   = 0.001f; // DAT_0066be20

// ─── LockGraphics (FUN_0062ad90) ─────────────────────────────
// Opens registry keys for Giants game settings.
// HKEY_CURRENT_USER\Software\PlanetMoon\Giants
//   └─ Players subkey
//     └─ Current player subkey (if player name is set)

void LockGraphics()
{
    if (g_hKey != nullptr)
        return;

    DWORD disposition;

    // Open main game key
    RegCreateKeyExA(HKEY_CURRENT_USER, "Software\\PlanetMoon\\Giants",
        0, nullptr, 0, 0xF003F, nullptr, &g_hKey, &disposition);

    // Open players root subkey
    RegCreateKeyExA(g_hKey, "Players",
        0, nullptr, 0, 0xF003F, nullptr, &g_hPlayerRootKey, &disposition);

    // Open current player subkey if name is set
    // Original: g_state_00702a60 — hardcoded address
    // Safe: read from registry instead
    char playerName[64] = {};
    if (g_hKey != nullptr)
    {
        DWORD bufSize = sizeof(playerName) - 1;
        RegQueryValueExA(g_hKey, "DefPlayer", nullptr, nullptr,
            (LPBYTE)playerName, &bufSize);
    }
    if (playerName[0] != '\0')
    {
        if (g_hPlayerKey != nullptr)
        {
            RegCloseKey(g_hPlayerKey);
            g_hPlayerKey = nullptr;
        }
        RegCreateKeyExA(g_hPlayerRootKey, playerName,
            0, nullptr, 0, 0xF003F, nullptr,
            &g_hPlayerKey, &disposition);
    }
}

// ─── UnlockGraphics (FUN_0062ae40) ────────────────────────────
// Closes all registry keys opened by LockGraphics.

void UnlockGraphics()
{
    if (g_hKey != nullptr)
    {
        if (g_hPlayerKey != nullptr)
        {
            RegCloseKey(g_hPlayerKey);
            g_hPlayerKey = nullptr;
        }
        RegCloseKey(g_hPlayerRootKey);
        g_hPlayerRootKey = nullptr;
        RegCloseKey(g_hKey);
        g_hKey = nullptr;
    }
}

// ─── InitializeEngine (FUN_0062e1a0) ──────────────────────────
// Full engine initialization pipeline (33 callees, ~400 lines of decompilation)
// Returns 1 on success, 0 on failure.

int InitializeEngine(unsigned int param_1, unsigned int param_2)
{
    TRACE_FUNC;

    // Error flag for goto replacement
    int gfxError = 0;

    // ── Phase A: Early state checks ─────────────────────────────
    int precheck = PreInitCheck();
    if (precheck == 0)
    {
        g_initialized = true;
        return 0;
    }

    if (g_initialized)
    {
        return 0;
    }

    // Default display params (640x480 fallback)
    if (g_width == 0) g_width  = 1280;
    if (g_height == 0) g_height = 720;

    // ── Phase B: Lock registry, read renderer name ──────────────
    LockGraphics();

    // Read renderer DLL name from registry (safe — no hardcoded addresses)
    if (g_rendererAvailable == 0)
    {
        g_rendererName[0] = '\0';

        if (g_hKey != nullptr)
        {
            DWORD bufSize = sizeof(g_rendererName) - 1;
            RegQueryValueExA(g_hKey, "Renderer", nullptr, nullptr,
                (LPBYTE)g_rendererName, &bufSize);
        }

        // Default to gg_dx9r.dll if no registry value
        if (g_rendererName[0] == '\0')
        {
            const char* defaultName = "gg_dx9r.dll";
            int i = 0;
            do {
                g_rendererName[i] = defaultName[i];
                i++;
            } while (defaultName[i - 1] != '\0');
        }
    }

    if (g_traceLog) {
        fprintf(g_traceLog, "[TRACE] Renderer name: '%s'\n", g_rendererName);
        fflush(g_traceLog);
    }

    // ── Phase C: Load renderer DLL and create device ────────────
    char loadResult = LoadGDVSystem();
    if (loadResult == 0)
    {
        // Retry with default renderer
        const char* defaultName = "gg_dx9r.dll";
        int i = 0;
        do {
            g_rendererName[i] = defaultName[i];
            i++;
        } while (defaultName[i - 1] != '\0');

        loadResult = LoadGDVSystem();
        if (loadResult == 0)
        {
            gfxError = 1;
            goto show_gfx_error;
        }
    }

    if (g_traceLog) {
        fprintf(g_traceLog, "[TRACE] LoadGDVSystem succeeded, GDVSysCreate=%p\n", (void*)g_GDVSysCreate);
        fflush(g_traceLog);
    }

    // Allocate engine context object (DAT_0073c924)
    // Original EngineInitializeImpl allocates 0x1c bytes, zeros it,
    // sets vtable at [0], linked-list nodes at [3] and [5].
    // The renderer receives this as 6th param to GDVSysCreate.
    if (g_engineContext == nullptr)
    {
        // Allocate zeroed 28-byte buffer for the context object
        g_engineContext = calloc(1, 0x1c);
        if (g_engineContext)
        {
            // Set vtable pointer at [0] — renderer calls vtable[2] during D3D init
            *((void**)g_engineContext) = g_engineContextVtable;
            // Allocate linked-list nodes (vtable entries expect these)
            // Node at offset [3] (bytes 12-15): 0x28 byte allocation
            void* node1 = calloc(1, 0x28);
            if (node1)
            {
                // Self-referential circular linked list (original pattern)
                void** n1 = (void**)node1;
                n1[0] = node1; n1[1] = node1; n1[2] = node1;
                *((uint16_t*)node1 + 6) = 0x0101; // flags at +0xC
                ((void**)g_engineContext)[3] = node1;
            }

            // Node at offset [5] (bytes 20-23): 0x10 byte allocation
            void* node2 = calloc(1, 0x10);
            if (node2)
            {
                void** n2 = (void**)node2;
                n2[0] = node2; n2[1] = node2;
                ((void**)g_engineContext)[5] = node2;
            }

            if (g_traceLog) {
                fprintf(g_traceLog, "[TRACE] Engine context allocated at %p\n", g_engineContext);
                fflush(g_traceLog);
            }
        }
    }

    // Create the render device via GDVSysCreate
    // CRITICAL: The first param is the COMMAND LINE STRING (lpCmdLine).
    // The renderer:
    //   1. Parses it with strncpy/strtok to find renderer mode ("DX9", "DX11", etc.)
    //   2. Reads at [ptr + 0x2B608] for previous D3D state (cleanup on re-init)
    // So param_2 from InitializeEngine (EDX in original binary = lpCmdLine) must
    // point to a LARGE valid memory region, NOT a small stack string.
    {
        g_windowed = 1;  // Force windowed for testing

        // Pre-load DirectX 9 — the renderer needs d3d9.dll
        HMODULE hD3D9 = LoadLibraryA("d3d9.dll");
        if (g_traceLog) {
            fprintf(g_traceLog, "[TRACE] d3d9.dll load: %p\n", (void*)hD3D9);
            fflush(g_traceLog);
        }

        // ── Display params structure (3rd param to GDVSysCreate) ─────
        // The renderer reads this as a 16-byte struct:
        //   +0: width (DWORD)
        //   +4: height (DWORD)
        //   +8: bitDepth (DWORD)
        //   +C: packed bytes: backBufferCount | multisampleType | multisampleQuality
        // Original code: local_e0=width, local_dc=height, local_d8=bitDepth,
        //   local_d4=CONCAT12(backBufferCount, CONCAT11(multisampleType, multisampleQuality))
        struct DisplayConfig {
            DWORD width;
            DWORD height;
            DWORD bitDepth;
            BYTE  backBufferCount;
            BYTE  multisampleType;
            BYTE  multisampleQuality;
            BYTE  pad;
        };
        DisplayConfig displayCfg = {};
        displayCfg.width           = g_width;
        displayCfg.height          = g_height;
        displayCfg.bitDepth        = g_bitDepth;
        displayCfg.backBufferCount = (BYTE)g_backBufferCount;
        displayCfg.multisampleType = (BYTE)g_multisampleType;
        // multisampleQuality and pad stay 0

        // ── Windowed params structure (4th param) ────────────────────
        // The renderer reads 16 bytes with movups (128-bit copy).
        // In the original: &DAT_00702b90 = {windowed, vsync, adapterOrdinal, pad}
        struct WindowedConfig {
            DWORD windowed;
            DWORD vsync;
            DWORD adapterOrdinal;
            DWORD pad;
        };
        WindowedConfig windowedCfg = {};
        windowedCfg.windowed       = g_windowed;
        windowedCfg.vsync          = g_vsync;
        windowedCfg.adapterOrdinal = g_adapterOrdinal;

        // ── Display mode structure (5th param) ────────────────────────
        // The renderer reads 16 bytes with movups.
        // In the original: &DAT_00702ba0 = {displayMode0..3}
        struct DisplayModeConfig {
            DWORD mode0;
            DWORD mode1;
            DWORD mode2;
            DWORD mode3;
        };
        DisplayModeConfig displayModeCfg = {};
        displayModeCfg.mode0 = g_displayMode0;
        displayModeCfg.mode1 = g_displayMode1;
        displayModeCfg.mode2 = g_displayMode2;
        displayModeCfg.mode3 = g_displayMode3;

        if (g_traceLog) {
            fprintf(g_traceLog, "[TRACE] Calling GDVSysCreate(cmdLine=\"%s\", hWnd=%p, dispCfg={%u,%u}, winCfg=%u, ctxObj=%p)\n",
                (const char*)param_2, g_hWnd, displayCfg.width, displayCfg.height,
                windowedCfg.windowed, g_engineContext);
            fflush(g_traceLog);
        }

        g_renderDevice = reinterpret_cast<void*(__cdecl*)(const char*, HWND, void*, void*, void*, void*)>(
            g_GDVSysCreate)((const char*)param_2, g_hWnd,
                &displayCfg,
                &windowedCfg,
                &displayModeCfg,
                g_engineContext);
    }

    if (g_traceLog) {
        fprintf(g_traceLog, "[TRACE] GDVSysCreate returned device=%p\n", g_renderDevice);
        // Dump renderer state buffer to see what function pointers the renderer wrote
        DWORD* state = GetRendererState();
        fprintf(g_traceLog, "[DUMP] Renderer state buffer (first 64 DWORDs):\n");
        for (int i = 0; i < 64; i++) {
            if (state[i] != 0)
                fprintf(g_traceLog, "[DUMP]   [%3d] offset 0x%03X = 0x%08X\n", i, i*4, state[i]);
        }
        fprintf(g_traceLog, "[DUMP] Renderer state non-zero entries: done\n");

        // Dump render device vtable to understand the interface
        if (g_renderDevice) {
            void** vtable = *(void***)g_renderDevice;
            fprintf(g_traceLog, "[VTABLE] Render device at %p, vtable at %p:\n", g_renderDevice, vtable);
            for (int i = 0; i < 60; i++) {
                if (vtable[i])
                    fprintf(g_traceLog, "[VTABLE]   [%2d] 0x%08X\n", i, (unsigned int)(uintptr_t)vtable[i]);
            }
            fprintf(g_traceLog, "[VTABLE] Dump complete\n");
        }

        // Dump render device internals to find the D3D9 device pointer
        if (g_renderDevice) {
            uint32_t* obj = reinterpret_cast<uint32_t*>(g_renderDevice);
            fprintf(g_traceLog, "[OBJ] Render device internal fields (raw values):\n");
            for (int i = 0; i < 128; i++) {
                if (obj[i] != 0)
                    fprintf(g_traceLog, "[OBJ]   [%3d] +0x%03X = 0x%08X\n", i, i*4, obj[i]);
            }
            fprintf(g_traceLog, "[OBJ] Dump complete\n");
        }

        // ── Scan for IDirect3DDevice9 inside render device ──────────
        // The renderer wraps D3D9. We need the device pointer to call Clear().
        // Strategy: check if any pointer's [0] (vtable) falls in d3d9.dll's range,
        // AND validate it has BeginScene at vtable[41] (unique to IDirect3DDevice9).
        {
            HMODULE hD3D9 = GetModuleHandleA("d3d9.dll");
            if (hD3D9 && g_renderDevice) {
                // Get d3d9.dll address range from PE headers
                IMAGE_DOS_HEADER* dosHdr = reinterpret_cast<IMAGE_DOS_HEADER*>(hD3D9);
                IMAGE_NT_HEADERS* ntHdr = reinterpret_cast<IMAGE_NT_HEADERS*>(
                    reinterpret_cast<char*>(hD3D9) + dosHdr->e_lfanew);
                DWORD d3d9Base = reinterpret_cast<DWORD>(hD3D9);
                DWORD d3d9End  = d3d9Base + ntHdr->OptionalHeader.SizeOfImage;

                fprintf(g_traceLog, "[D3D9SCAN] d3d9.dll: 0x%08X - 0x%08X (%lu KB)\n",
                    (unsigned)d3d9Base, (unsigned)d3d9End, (unsigned long)(d3d9End - d3d9Base) / 1024);

                uint32_t* obj = reinterpret_cast<uint32_t*>(g_renderDevice);

                // Depth-1 scan: check each field's vtable against d3d9.dll range
                // Then validate: vtable[41] (BeginScene) must also be in d3d9.dll
                // This distinguishes IDirect3DDevice9 from other D3D9 COM objects
                for (int i = 1; i < 128; i++) {
                    uint32_t val = obj[i];
                    if (val < 0x10000 || val >= 0xFFF00000) continue;
                    if (IsBadReadPtr(reinterpret_cast<void*>(val), 256)) continue;

                    uint32_t* candidateVtbl = *reinterpret_cast<uint32_t**>(val);
                    if (candidateVtbl < reinterpret_cast<uint32_t*>(d3d9Base) ||
                        candidateVtbl >= reinterpret_cast<uint32_t*>(d3d9End)) continue;

                    fprintf(g_traceLog, "[D3D9SCAN] D3D9 COM obj at obj[%d]+0x%X = 0x%08X, vtable=0x%08X\n",
                        i, i*4, val, (unsigned)(uintptr_t)candidateVtbl);

                    // Validate: check vtable[41] (BeginScene) is also in d3d9.dll
                    // IDirect3DDevice9 is the ONLY D3D9 interface with 115+ methods
                    if (IsBadReadPtr(candidateVtbl + 41, 4) == FALSE &&
                        candidateVtbl[41] >= (uint32_t)d3d9Base &&
                        candidateVtbl[41] < (uint32_t)d3d9End) {
                        fprintf(g_traceLog, "[D3D9SCAN] >>> IDirect3DDevice9 confirmed at obj[%d]+0x%X, vtable[41]=0x%08X\n",
                            i, i*4, candidateVtbl[41]);
                        g_d3d9Device = reinterpret_cast<void*>(val);
                        // Don't break — keep scanning for diagnostics
                    }
                }

                if (g_d3d9Device) {
                    fprintf(g_traceLog, "[D3D9SCAN] Final D3D9 device at %p\n", g_d3d9Device);
                } else {
                    fprintf(g_traceLog, "[D3D9SCAN] IDirect3DDevice9 NOT found\n");
                }
                fflush(g_traceLog);
            }
        }
        fflush(g_traceLog);
    }

    // 640x480 fallback if device creation failed
    if (g_renderDevice == nullptr)
    {
        if (g_traceLog) { fprintf(g_traceLog, "[TRACE] Trying 640x480 fallback...\n"); fflush(g_traceLog); }
        struct DisplayConfig {
            DWORD width; DWORD height; DWORD bitDepth;
            BYTE backBufferCount; BYTE multisampleType; BYTE multisampleQuality; BYTE pad;
        };
        DisplayConfig fallbackCfg = { 640, 480, 0, 0, 0, 0, 0 };

        struct WindowedConfig {
            DWORD windowed; DWORD vsync; DWORD adapterOrdinal; DWORD pad;
        };
        WindowedConfig winCfg = { 1, 0, 0, 0 };

        struct DisplayModeConfig {
            DWORD mode0; DWORD mode1; DWORD mode2; DWORD mode3;
        };
        DisplayModeConfig dmCfg = {};

        g_windowed = 1;
        g_renderDevice = reinterpret_cast<void*(__cdecl*)(const char*, HWND, void*, void*, void*, void*)>(
            g_GDVSysCreate)((const char*)param_2, g_hWnd,
                &fallbackCfg,
                &winCfg,
                &dmCfg,
                g_engineContext);

        if (g_renderDevice != nullptr)
        {
            g_width  = fallbackCfg.width;
            g_height = fallbackCfg.height;
        }
    }

    if (g_renderDevice == nullptr)
    {
        gfxError = 1;
        goto show_gfx_error;
    }

    // Unify DAT_00702700: g_rendererObj (used by FrameEnd's guard) = g_renderDevice.
    // Now safe — BeginScene/ShutdownSubsystems/FrameEnd vtable calls use the
    // CallThiscall wrappers (ECX=this), and Phase 5's redundant inline render is
    // removed so FrameEnd owns the single render cycle (original exe structure).
    extern void* g_rendererObj;
    g_rendererObj = g_renderDevice;

    // Also unify g_renderFactory (DAT_00702700, 4th copy) so InitGraphicsResources
    // runs its device/buffer-creation logic. The stub renderer's factory methods
    // (vtable[2]/[3]/[4]) return 0, so devices/buffers stay null until a real
    // renderer is used — but the function no longer early-returns.
    extern void* g_renderFactory;
    g_renderFactory = g_renderDevice;

    // Initialize the COM subsystem (FUN_0042fc00) — creates + registers the
    // core COM object. Functional reconstruction via ComRegistry.
    InitCOMSubsystem_Real();
    InitStringSubsystem_Real();  // FUN_00443e20 — string-lookup subsystem
    RegisterGameContext();       // game-context object (FUN_00461a60 queries it)
    if (g_traceLog) {
        fprintf(g_traceLog, "[COM] COM subsystem init done, registry count=%d\n", ComRegistryCount());
        fflush(g_traceLog);
    }

    UnlockGraphics();
    if (g_traceLog) { fprintf(g_traceLog, "[TRACE] Phase B/C done — UnlockGraphics\n"); fflush(g_traceLog); }

    // ── Phase D: RenderDoc API detection (optional) ─────────────
    {
        HMODULE hRenderDoc = GetModuleHandleA("renderdoc.dll");
        if (hRenderDoc != nullptr)
        {
            FARPROC pGetAPI = GetProcAddress(hRenderDoc, "RENDERDOC_GetAPI");
            if (pGetAPI != nullptr)
            {
                typedef int (*PFN_RENDERDOC_GetAPI)(int, void**);
                int rdResult = reinterpret_cast<PFN_RENDERDOC_GetAPI>(pGetAPI)(
                    0x2968, &g_renderDocAPI);
                if (rdResult != 1)
                    g_renderDocAPI = nullptr;
            }
        }
    }

    // ── Phase E: Audio system initialization ────────────────────
    if (g_traceLog) { fprintf(g_traceLog, "[TRACE] Phase D done — checking audio\n"); fflush(g_traceLog); }
    {
        int audioResult = InitAudioSystem();
        if (audioResult == 0)
        {
            // Audio failed — continue anyway for testing
            if (g_traceLog) {
                fprintf(g_traceLog, "[WARN] InitAudioSystem failed, continuing\n");
                fflush(g_traceLog);
            }
        }
    }

    // ── Phase F: Timer registration ─────────────────────────────
    if (g_traceLog) { fprintf(g_traceLog, "[TRACE] Phase E done — timer registration\n"); fflush(g_traceLog); }
    if (g_fnRegisterTimer)
    {
        g_fnRegisterTimer(0x2C, nullptr);
    }
    if (g_fnUpdateFrame)
    {
        g_fnUpdateFrame();
    }

    // ── Phase G: Display settings ───────────────────────────────
    if (g_traceLog) { fprintf(g_traceLog, "[TRACE] Phase F done — display settings\n"); fflush(g_traceLog); }
    InitDisplaySettings();
    if (g_initialized) return 0;

    InitDisplayMode();
    InitGraphicsResources();

    // ── Phase H: DirectInput + cursor hide ──────────────────────
    if (g_traceLog) { fprintf(g_traceLog, "[TRACE] Phase G done — direct input\n"); fflush(g_traceLog); }
    {
        if (g_traceLog) { fprintf(g_traceLog, "[TRACE] Calling InitializeDirectInput...\n"); fflush(g_traceLog); }
        char diResult = InitializeDirectInput();
        if (g_traceLog) { fprintf(g_traceLog, "[TRACE] InitializeDirectInput returned %d\n", (int)diResult); fflush(g_traceLog); }
        if (diResult == 0)
        {
            if (g_traceLog) {
                fprintf(g_traceLog, "[WARN] InitializeDirectInput failed, continuing\n");
                fflush(g_traceLog);
            }
        }
    }

    // ── Phase I: Volume settings (skip if function pointers null) ──
    if (g_traceLog) { fprintf(g_traceLog, "[TRACE] Phase H done — volume/registry\n"); fflush(g_traceLog); }
    LockGraphics();
    if (g_setMusicVolume && g_hPlayerKey)
    {
        DWORD musicVol = g_defaultVolume;
        DWORD volSize = 4;
        RegQueryValueExA(g_hPlayerKey, "MusicVolume", nullptr, nullptr,
            (LPBYTE)&musicVol, &volSize);
        g_setMusicVolume(musicVol);
    }
    if (g_setSoundVolume && g_hPlayerKey)
    {
        DWORD soundVol = g_defaultVolume;
        DWORD volSize = 4;
        RegQueryValueExA(g_hPlayerKey, "SoundVolume", nullptr, nullptr,
            (LPBYTE)&soundVol, &volSize);
        g_setSoundVolume(soundVol);
    }
    UnlockGraphics();

    // ── Phase J: Aspect ratio + final init ──────────────────────
    if (g_traceLog) { fprintf(g_traceLog, "[TRACE] Phase H done — final init\n"); fflush(g_traceLog); }
    g_aspectRatioX = static_cast<float>(g_playerId1) * g_aspectScale;
    g_aspectRatioY = static_cast<float>(g_playerId2) * g_aspectScale;

    FinalInit();
    LastInitStep();

    g_initialized = true;

    if (g_traceLog) {
        fprintf(g_traceLog, "[TRACE] InitializeEngine completed successfully\n");
        fflush(g_traceLog);
    }

    return 1;

show_gfx_error:
    {
        const char* errorKey = "Failed to initialize graphics";
        ShowErrorDialog(errorKey);
        g_errorShown = 1;
        ClearString();
        return 0;
    }
}

} // namespace Giants
