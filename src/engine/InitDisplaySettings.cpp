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

namespace Giants {

// ─── Renderer vtable helpers ──────────────────────────────────

// g_renderDevice (DAT_00702700) is a COM object with virtual dispatch
// Vtable slot 53 = GetCapability(index): returns DWORD
static DWORD RendererGetCapability(void* device, int index)
{
    // 0x004f86c0 uses: (**(code**)(*DAT_00702700 + 0xD4))(index)
    typedef DWORD (__cdecl *PFN_GetCapability)(int);
    return (*reinterpret_cast<PFN_GetCapability**>(device))[0xD4 / 4](index);
}

// Vtable slot 19 = SetVSyncEnabled(bool)
static void RendererSetVSyncEnabled(void* device, bool enabled)
{
    // 0x004f8762: (**(code**)(*DAT_00702700 + 0x4C))(DAT_007028b8 != 0)
    typedef void (__cdecl *PFN_SetVSyncEnabled)(int);
    (*reinterpret_cast<PFN_SetVSyncEnabled**>(device))[0x4C / 4](enabled ? 1 : 0);
}

// Vtable slot 17 = SetViewportDimensions(float* dims)
static void RendererSetViewport(void* device, float* dims)
{
    // 0x004f878a: (**(code**)(*DAT_00702700 + 0x44))(&DAT_0074bb90)
    typedef void (__cdecl *PFN_SetViewport)(float*);
    (*reinterpret_cast<PFN_SetViewport**>(device))[0x44 / 4](dims);
}

// ─── InitDisplaySettings (FUN_004f86c0) ───────────────────────

void InitDisplaySettings()
{
    // 0x004f86c7: Mark display as initialized
    g_displayInitialized = 1;  // DAT_007281d4 = 1

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
    // DAT_00702b8e = (DAT_007028b4 != 0) — store as byte
    *reinterpret_cast<BYTE*>(0x00702b8e) = (g_isWindowed != 0) ? 1 : 0;

    // 0x004f8730: vtable[0xD4](8) → sample count / multisample quality
    DWORD sampleQuality = RendererGetCapability(g_renderDevice, 8);  // DAT_00702be4
    if (sampleQuality > 4)
    {
        *reinterpret_cast<BYTE*>(0x00702b69) = 1;  // Enable high sample count
    }

    // 0x004f8747: Extract stereo flag (bit 9)
    g_stereoFlag = g_playerDisplayBits >> 9 & 1;  // DAT_007028b8

    // 0x004f8753: Set global scale based on stereo mode
    // DAT_0067f47c = g_globalScale (default 1.0f = 0x3F800000)
    g_globalScale = 1.0f;  // 0x3F800000
    if (*reinterpret_cast<DWORD*>(0x00702bd4) != 0)
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
        *reinterpret_cast<DWORD*>(0x00702ac8) = 0x5000;  // _DAT_00702ac8
    }

    // ── Apply fullscreen or resize window ──────────────────────
    // 0x004f8784: If fullscreen mode, resize window to cover entire screen
    if (g_windowedModeFlag != 0)
    {
        int cx = GetSystemMetrics(SM_CXSCREEN);  // 0 = SM_CXSCREEN
        int cy = GetSystemMetrics(SM_CYSCREEN);  // 1 = SM_CYSCREEN

        // SWP_NOMOVE = 0x100 — resize without moving
        SetWindowPos(
            *reinterpret_cast<HWND*>(0x007281d8),  // g_hWnd
            nullptr,                                  // HWND_TOP
            0, 0,
            cx, cy,
            0x100);                                   // SWP_NOMOVE
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

    // ── Post-display callbacks ─────────────────────────────────
    // FUN_005de6b0 — unknown callback (possibly shader/resource init)
    PostDisplayInit();  // FUN_005de6b0

    // FUN_004e1cc0 — unknown callback (possibly UI/HUD init)
    PostDisplayInit2(); // FUN_004e1cc0
}

} // namespace Giants
