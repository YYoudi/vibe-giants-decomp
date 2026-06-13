// Giants Engine - Initialization (InitializeEngine)
// Reverse engineered from GiantsMain.exe v1.520.59
//
// FUN_0062e1a0 — InitializeEngine
// Full engine initialization pipeline (33 callees, ~400 lines decompilation):
//   Phase A: Pre-condition check (FUN_005c45f0), bail if already initialized
//   Phase B: LockGraphics → read renderer DLL name from registry
//   Phase C: LoadGDVSystem → GDVSysCreate (create render device, fallback 640x480)
//   Phase D: RenderDoc API detection (renderdoc.dll, RENDERDOC_GetAPI)
//   Phase E: InitAudioSystem (Miles Sound System)
//   Phase F: Register timer, compare display mode, load player profile
//   Phase G: InitDisplaySettings → InitDisplayMode → InitGraphicsResources
//   Phase H: InitializeDirectInput → hide cursor
//   Phase I: Audio volume from registry → aspect ratio → FinalInit
//
// Key corrections from Ghidra decompilation:
//   - InitializeEngine takes 2 params (param_1 unused, param_2 = hWnd/context)
//   - LoadGDVSystem is called with no args (returns char)
//   - GDVSysCreate takes (param_2, hWnd, &displaySettings, &windowed, &displayMode, context)
//   - RenderDoc init was completely missing from prior stub
//   - Display mode comparison uses 12-byte custom memcmp, not memcmp()
//   - Phase ordering was wrong: display settings BEFORE DirectInput

#pragma once

#include <cstdint>
#include <windows.h>

namespace Giants {

// ─── Display Settings Globals ─────────────────────────────────

extern DWORD g_width;              // DAT_00702b80
extern DWORD g_height;             // DAT_00702b84
extern DWORD g_bitDepth;           // DAT_00702b88
extern DWORD g_refreshRate;        // DAT_00702b8c
extern DWORD g_backBufferCount;    // DAT_00702b8d
extern DWORD g_multisampleType;    // DAT_00702b8e
extern DWORD g_windowed;           // DAT_00702b90
extern DWORD g_vsync;              // DAT_00702b94
extern DWORD g_adapterOrdinal;     // DAT_00702b98

// Display mode comparison (12 bytes = 3 DWORDs)
extern DWORD g_displayMode0;       // DAT_00702ba0
extern DWORD g_displayMode1;       // DAT_00702ba4
extern DWORD g_displayMode2;       // DAT_00702ba8
extern DWORD g_displayMode3;       // DAT_00702bac

// ─── Renderer Globals ─────────────────────────────────────────

extern bool  g_initialized;        // DAT_007282bc — engine initialized flag
extern bool  g_rendererActive;     // DAT_00702bd0
extern char  g_rendererAvailable;  // DAT_00702b5a
extern char  g_rendererName[32];   // DAT_007281f0 — renderer DLL name
extern void* g_renderDevice;       // DAT_00702700 — primary renderer COM object
extern void* g_renderDocAPI;       // DAT_0074bbb8 — RENDERDOC_API_1_1_2* (optional)

// ─── Registry / Player Profile ────────────────────────────────

extern HKEY  g_hKey;               // DAT_0074be54 — Giants registry key
extern HKEY  g_hPlayerKey;         // DAT_0074be5c — current player subkey
extern HKEY  g_hPlayerRootKey;     // DAT_0074be58 — players root key
extern DWORD g_playerId;           // DAT_007028b0
extern DWORD g_playerId1;          // DAT_007028a0
extern DWORD g_playerId2;          // DAT_007028a4
extern float g_aspectRatioX;       // DAT_00702c1c
extern float g_aspectRatioY;       // DAT_00702c20

// ─── Functions ────────────────────────────────────────────────

/// Full engine initialization (renderer + audio + input + player profile).
/// Called once by MainGameLoop after window creation.
/// @param param_1  First parameter (hInstance or unused)
/// @param param_2  Command line string (lpCmdLine) — passed as 1st arg to GDVSysCreate.
///                 The renderer parses this with strtok to find renderer mode (DX9/DX11).
///                 IMPORTANT: The renderer reads at [param_2 + 0x2B608], so the pointer
///                 MUST point to a large valid memory region (not a small stack string).
/// @return 1 on success, 0 on failure (shows error dialog)
int InitializeEngine(unsigned int param_1, unsigned int param_2);  // FUN_0062e1a0

// Sub-functions called by InitializeEngine (33 callees)
int  PreInitCheck();                 // FUN_005c45f0 — precondition check
void LockGraphics();                 // FUN_0062ad90 — open registry keys
void UnlockGraphics();               // FUN_0062ae40 — close registry keys
int  InitAudioSystem();              // FUN_0062af40 — Miles Sound System init
void InitDisplaySettings();          // FUN_004f86c0 — vtable display query + fullscreen
void InitDisplayMode();              // FUN_0062b9c0 — display mode setup (14 callees)
void InitGraphicsResources();        // FUN_004f7fa0 — 4 devices, 9 buffers, 2 heaps
int InitializeDirectInput();         // FUN_0062a420 — DI8 keyboard+mouse+controller
void FinalInit();                    // FUN_0062f7e0 — replay record/playback
void InitNetwork();                  // FUN_004f8550
void SavePlayerProfile();            // FUN_00540770
void SavePlayerSettings();           // FUN_005403e0
void LastInitStep();                 // FUN_00552990
void ShowErrorDialog(const char*);   // FUN_0062edc0
void ClearString();                  // FUN_004439b0 — SSO string cleanup
void DebugLog(const char*);          // FUN_00461f00
const char* GetLocalizedString(const char* key);  // FUN_005e80c0
void FormatString(const char* fmt, void* out);    // FUN_00463000
void FormatStringArg(const char* fmt, const char* arg);  // fmt::vformat wrapper

// External renderer exports (from RendererLoader.h)
extern FARPROC g_GDVSysCreate;      // DAT_00727e50
extern FARPROC g_UpCallsLoad;       // DAT_00727e4c
bool LoadGDVSystem();               // FUN_0062a230
HMODULE LoadModuleHelper();         // FUN_0062a190

} // namespace Giants
