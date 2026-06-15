// Giants Engine - Display Settings Initialization Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
//
// FUN_004f86c0 — InitDisplaySettings (4 callees)
// Queries the renderer COM object for display capabilities, applies windowed
// or fullscreen mode, sets viewport dimensions and FOV scaling.
//
// Renderer vtable layout (IDirect3D-style COM):
//   slot 53 (0xD4/4) = GetCapability(DWORD index) → DWORD
//   slot 19 (0x4C/4) = SetVSyncEnabled(bool)
//   slot 17 (0x44/4) = SetViewportDimensions(float[4])

#include "InitDisplaySettings.h"
#include "EngineInit.h"
#include <cstdio>

namespace Giants {

// ─── Display Settings State (definitions — DAT_ addresses from Ghidra) ──
DWORD g_displayInitialized = 0;    // DAT_007281d4
DWORD g_windowedModeFlag = 0;      // DAT_007282c0
DWORD g_screenWidth = 0;           // DAT_007028a0 / DAT_007282c4
DWORD g_screenHeight = 0;          // DAT_007028a4 / DAT_007282c8
DWORD g_displayCapsFlag = 0;       // DAT_007028a8
DWORD g_adapterIndex = 0;          // DAT_007028ac
DWORD g_playerDisplayBits = 0;     // DAT_007028b0
DWORD g_isWindowed = 0;            // DAT_007028b4
DWORD g_sampleCount = 0;           // DAT_00702b69
DWORD g_stereoFlag = 0;            // DAT_007028b8
DWORD g_highQualityFlag = 0;       // DAT_007028bc
float g_globalScale = 1.0f;        // DAT_0067f47c
float g_fovScale = 1.0f;           // DAT_00702ac4
DWORD g_fovExtra = 0;              // DAT_00702ac8
float g_viewportWidth = 0.0f;      // DAT_0074bb90
float g_viewportHeight = 0.0f;     // DAT_0074bb94
float g_viewportX = 0.0f;          // DAT_0074bb98
float g_viewportY = 0.0f;          // DAT_0074bb9c
BYTE  g_isWindowedByte = 0;        // DAT_00702b8e — isWindowed as byte
DWORD g_stereoModeFlag = 0;        // DAT_00702bd4 — stereo mode enabled

// ─── Renderer vtable helpers ──────────────────────────────────
// INIT-BEHAVIOR RECONSTRUCTION MODE: the real gg_dx9r.dll renderer requires a
// fully-built engine-context protocol (UpCalls + callbacks + state) that the
// recomp doesn't yet drive. Calling its COM vtable methods (thiscall, ECX=this)
// crashes deep inside the renderer (observed at vtable[3]=0x1001DB10) because
// the context isn't initialized. Per the project focus (reconstruct INIT
// BEHAVIOR, not visual rendering), we stub the renderer capability queries to
// return hardcoded defaults so the full init SEQUENCE runs and all display
// globals are populated. The real renderer query path is preserved as comments
// for when the engine-context protocol is reconstructed.

// Hardcoded display defaults (match the registry-resolved mode: 1280×720 windowed).
static DWORD g_dispDefaultWidth  = 1280;
static DWORD g_dispDefaultHeight = 720;

// Vtable slot 53 (0xD4/4) = GetCapability(index): returns DWORD
static DWORD RendererGetCapability(void* /*device*/, int index)
{
    // Real: (*(**PFN_GetCap)(device_vtable[0xD4/4]))(index) — thiscall.
    // Returns hardcoded defaults instead of querying the real renderer.
    switch (index) {
        case 0:  return 1;                      // windowed mode flag (1=windowed)
        case 1:  return g_dispDefaultWidth;     // screen width
        case 2:  return g_dispDefaultHeight;    // screen height
        case 6:  return 0;                      // adapter index
        case 7:  return 0;                      // player display settings bitmask
        case 8:  return 0;                      // sample count / quality
        default: return 0;
    }
}

// Vtable slot 19 (0x4C/4) = SetVSyncEnabled(bool)
static void RendererSetVSyncEnabled(void* /*device*/, bool /*enabled*/)
{
    // Real: thiscall vtable[0x4C/4](enabled). No-op stub (init-behavior mode).
}

// Vtable slot 17 (0x44/4) = SetViewportDimensions(float* dims)
static void RendererSetViewport(void* /*device*/, float* /*dims*/)
{
    // Real: thiscall vtable[0x44/4](dims). No-op stub (init-behavior mode).
}

// ─── InitDisplaySettings (FUN_004f86c0) ───────────────────────

void InitDisplaySettings()
{
    // 0x004f86c7: Mark display as initialized
    g_displayInitialized = 1;  // DAT_007281d4 = 1
    extern FILE* g_traceLog;
    if (g_traceLog) { fprintf(g_traceLog, "[IDS] enter, g_renderDevice=%p\n", g_renderDevice); fflush(g_traceLog); }

    // ── Query renderer capabilities via vtable ─────────────────
    // vtable[0xD4](0) → windowed mode flag
    g_windowedModeFlag = RendererGetCapability(g_renderDevice, 0);  // DAT_007282c0
    g_isWindowed = (g_windowedModeFlag == 0) ? 1 : 0;  // DAT_007028b4 — inverted logic
    // Note: 0 means fullscreen, nonzero means windowed. g_isWindowed inverts this:
    //   g_isWindowed = (g_windowedModeFlag == 0) ? 1 : 0;
    // So if windowedModeFlag=0 (fullscreen), isWindowed=1? That seems inverted.
    // Actually: DAT_007028b4 = (uint)(DAT_007282c0 == 0) — so:
    //   g_isWindowed = (g_windowedModeFlag == 0) — treat 0 as windowed=true
    // This might mean the renderer reports fullscreen capability, and 0 = can't fullscreen

    // vtable[0xD4](1) → screen width
    g_screenWidth = RendererGetCapability(g_renderDevice, 1);  // DAT_007028a0
    g_viewportWidth = static_cast<float>(g_screenWidth);        // DAT_007282c4

    // vtable[0xD4](2) → screen height
    g_screenHeight = RendererGetCapability(g_renderDevice, 2); // DAT_007028a4
    g_displayCapsFlag = 0x20;  // DAT_007028a8 = 0x20 (32) — fixed capability mask
    g_viewportHeight = static_cast<float>(g_screenHeight);      // DAT_007282c8

    // vtable[0xD4](6) → adapter index
    g_adapterIndex = RendererGetCapability(g_renderDevice, 6);  // DAT_007028ac

    // vtable[0xD4](7) → player display settings bitmask
    g_playerDisplayBits = RendererGetCapability(g_renderDevice, 7);  // DAT_007028b0

    // ── Derive settings from player display bitmask ────────────
    // Bit analysis of g_playerDisplayBits (DAT_007028b0):
    //   Bit 0: used for windowed mode check
    //   Bit 9: stereo flag
    //   Bit 10: high quality flag

    // 0x004f8724: isWindowed flag derived from g_windowedModeFlag
    // DAT_00702b8e — recomp-safe named global instead of the original's absolute address.
    extern BYTE g_isWindowedByte;  // DAT_00702b8e
    g_isWindowedByte = (g_isWindowed != 0) ? 1 : 0;

    // 0x004f8730: vtable[0xD4](8) → sample count / multisample quality
    DWORD sampleQuality = RendererGetCapability(g_renderDevice, 8);  // DAT_00702be4
    if (sampleQuality > 4)
    {
        g_sampleCount = 1;  // DAT_00702b69 — Enable high sample count
    }

    // 0x004f8747: Extract stereo flag (bit 9)
    g_stereoFlag = g_playerDisplayBits >> 9 & 1;  // DAT_007028b8

    // 0x004f8753: Set global scale based on stereo mode
    // DAT_0067f47c = g_globalScale (default 1.0f = 0x3F800000)
    g_globalScale = 1.0f;  // 0x3F800000
    extern DWORD g_stereoModeFlag;  // DAT_00702bd4 — stereo mode enabled
    if (g_stereoModeFlag != 0)
    {
        g_globalScale = 5.0f;  // 0x40A00000 — stereo magnification
    }

    // 0x004f8762: Extract high quality flag (bit 10)
    g_highQualityFlag = g_playerDisplayBits & 0x400;  // DAT_007028bc

    // 0x004f8770: Set FOV scale based on bit 4 of playerDisplayBits
    if ((g_playerDisplayBits & 0x10) == 0 || g_playerDisplayBits == 0)
    {
        g_fovScale = 4.0f;   // DAT_00702ac4 = 0x408000000 (4.0f — wide FOV)
    }
    else
    {
        g_fovScale = 1.0f;   // DAT_00702ac4 = 0x3F800000 (1.0f — normal FOV)
        g_fovExtra = 0x5000;  // _DAT_00702ac8
    }

    // ── Apply fullscreen or resize window ──────────────────────
    // 0x004f8784: If fullscreen mode, resize window to cover entire screen
    extern HWND g_hWnd;  // DAT_007281d8 (declared in EngineInit)
    if (g_windowedModeFlag != 0)
    {
        int cx = GetSystemMetrics(SM_CXSCREEN);  // 0 = SM_CXSCREEN
        int cy = GetSystemMetrics(SM_CYSCREEN);  // 1 = SM_CYSCREEN

        // SWP_NOMOVE = 0x100 — resize without moving
        SetWindowPos(
            g_hWnd,    // g_hWnd
            nullptr,     // HWND_TOP
            0, 0,
            cx, cy,
            0x100);      // SWP_NOMOVE
    }

    // ── Set VSync and viewport ─────────────────────────────────
    // 0x004f8762: vtable[0x4C] = SetVSyncEnabled(g_stereoFlag != 0)
    RendererSetVSyncEnabled(g_renderDevice, g_stereoFlag != 0);

    // 0x004f878a: Calculate viewport dimensions with aspect scale
    // DAT_0066be20 = g_aspectScale (float multiplier)
    float aspectScale = 0.5f;
    g_viewportWidth  = static_cast<float>(g_screenWidth) * aspectScale;   // DAT_0074bb90
    g_viewportHeight = static_cast<float>(g_screenHeight) * aspectScale;  // DAT_0074bb94
    g_viewportX = g_viewportWidth + 0.0f;   // DAT_0074bb98 (float add, possibly for rounding)
    g_viewportY = g_viewportHeight + 0.0f;  // DAT_0074bb9c

    // 0x004f878a: vtable[0x44] = SetViewportDimensions(&g_viewportWidth)
    RendererSetViewport(g_renderDevice, &g_viewportWidth);
    if (g_traceLog) { fprintf(g_traceLog, "[IDS] viewport set OK\n"); fflush(g_traceLog); }

    // ── Post-display callbacks ─────────────────────────────────
    // FUN_005de6b0 — unknown callback (possibly shader/resource init)
    PostDisplayInit();  // FUN_005de6b0
    if (g_traceLog) { fprintf(g_traceLog, "[IDS] PostDisplayInit OK\n"); fflush(g_traceLog); }

    // FUN_004e1cc0 — unknown callback (possibly UI/HUD init)
    PostDisplayInit2(); // FUN_004e1cc0
    if (g_traceLog) { fprintf(g_traceLog, "[IDS] PostDisplayInit2 OK\n"); fflush(g_traceLog); }
}

// ─── Post-display-init callbacks (FUN_005de6b0 / FUN_004e1cc0) ──
// Unknown shader/UI callbacks. Stubbed for now: their decompiled bodies make
// bare cdecl vtable calls on g_renderDevice (crash at vtable[3] without ECX
// set). Re-port with thiscall wrappers when their exact vtable slots are known.
void PostDisplayInit() {}
void PostDisplayInit2() {}

} // namespace Giants
