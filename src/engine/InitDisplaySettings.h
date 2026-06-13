// Giants Engine - Display Settings Initialization
// Reverse engineered from GiantsMain.exe v1.520.59
//
// FUN_004f86c0 — InitDisplaySettings
// Queries the renderer COM object vtable for display capabilities and applies
// windowed/fullscreen mode. Called by InitializeEngine (FUN_0062e1a0) after
// the renderer device is created.
//
// Renderer vtable calls (g_renderDevice = DAT_00702700):
//   vtable[0xD4/4=53] = GetCapability(index) — returns DWORD
//     index 0: windowed mode flag (0=fullscreen, nonzero=windowed)
//     index 1: screen width
//     index 2: screen height
//     index 6: some capability flag
//     index 7: player display settings bitmask
//     index 8: sample count / quality level
//   vtable[0x4C/4=19] = SetVSyncEnabled(bool)
//   vtable[0x44/4=17] = SetViewportDimensions(float[4])
//
// 4 callees: GetSystemMetrics, SetWindowPos, FUN_005de6b0, FUN_004e1cc0

#pragma once

#include <cstdint>
#include <windows.h>

namespace Giants {

// ─── Display Settings State ───────────────────────────────────

extern DWORD g_displayInitialized;    // DAT_007281d4 — set to 1 on init
extern DWORD g_windowedModeFlag;      // DAT_007282c0 — from vtable[0xD4](0)
extern DWORD g_screenWidth;           // DAT_007028a0 / DAT_007282c4 — from vtable[0xD4](1)
extern DWORD g_screenHeight;          // DAT_007028a4 / DAT_007282c8 — from vtable[0xD4](2)
extern DWORD g_displayCapsFlag;       // DAT_007028a8 — set to 0x20
extern DWORD g_adapterIndex;          // DAT_007028ac — from vtable[0xD4](6)
extern DWORD g_playerDisplayBits;     // DAT_007028b0 — from vtable[0xD4](7)
extern DWORD g_isWindowed;            // DAT_007028b4 — 1 if windowed, 0 if fullscreen
extern DWORD g_sampleCount;           // DAT_00702b69 — set to 1 if quality > 4
extern DWORD g_stereoFlag;            // DAT_007028b8 — bit 9 of playerDisplayBits
extern DWORD g_highQualityFlag;       // DAT_007028bc — bit 10 of playerDisplayBits
extern float g_globalScale;           // DAT_0067f47c — 1.0 normal, 5.0 with stereo
extern float g_fovScale;              // DAT_00702ac4 — field of view scale factor
extern DWORD g_fovExtra;              // DAT_00702ac8 — extra FOV data (0x5000)
extern float g_viewportWidth;         // DAT_0074bb90
extern float g_viewportHeight;        // DAT_0074bb94
extern float g_viewportX;             // DAT_0074bb98
extern float g_viewportY;             // DAT_0074bb9c

// ─── Functions ────────────────────────────────────────────────

/// Query renderer capabilities and apply display settings.
/// Sets windowed/fullscreen mode, viewport dimensions, FOV, and stereo.
/// Called by InitializeEngine after renderer device creation.
void InitDisplaySettings();           // FUN_004f86c0

/// Post-display-init callback (FUN_005de6b0)
void PostDisplayInit();

/// Post-display-init callback 2 (FUN_004e1cc0)
void PostDisplayInit2();

} // namespace Giants
