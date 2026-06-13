// Giants Engine - Game Settings (Registry Load/Save)
// Reverse engineered from GiantsMain.exe v1.520.59
//
// FUN_00540770 — LoadGameSettings (PASS, 317 lines)
//   Full registry settings loader with validation/clamping.
//   Reads from HKCU\Software\PlanetMoon\Giants.
//
// FUN_005403e0 — SaveGameSettings (FAIL, 127 lines)
//   Registry settings saver, queries vtable for video GUIDs.

#pragma once

#include <cstdint>
#include <windows.h>

namespace Giants {

// ─── Registry Key Paths ──────────────────────────────────────────
// HKCU\Software\PlanetMoon\Giants\DisplaySettings  → g_hKey (DAT_0074be54)
// HKCU\Software\PlanetMoon\Giants\Players\<name>    → g_hPlayerKey (DAT_0074be5c)

// ─── Game Options Version ────────────────────────────────────────
constexpr int kGameOptionsVersion = 4;     // Expected registry version

// ─── Graphics Quality Settings ───────────────────────────────────
// All read/written as DWORD registry values under the player subkey.
// Valid range: see clamping logic in LoadGameSettings.

extern int  g_shadowDetail;                // DAT_00702b18 — ShadowDetail (0..3)
extern int  g_landscapeQuality;            // DAT_00702b64 — LandscapeQuality (0..2)
extern int  g_waterQuality;                // DAT_00702b6c — WaterQuality (0..2)
extern int  g_weatherDetail;               // DAT_00702afc — WeatherDetail (0..2)
extern int  g_modelDetail;                 // DAT_00702b24 — ModelDetail (0..3)
extern int  g_lightingQuality;             // DAT_00702b00 — LightingQuality (0..2)

// Boolean settings (stored as DWORD 0/1)
extern bool g_environmentMapping;          // DAT_00702b5e — EnvironmentMapping
extern bool g_objectBumps;                 // DAT_00702b5c — ObjectBumps (inverted on write)
extern bool g_sunflare;                    // DAT_00702b70 — Sunflare (inverted: 0=on)
extern bool g_invertY;                     // DAT_00702bd8 — inverted Y axis (bit 13 of GameOptions)

// ─── Game Options Bitfield ───────────────────────────────────────
// DAT_00748a38 — packed DWORD with multiple boolean flags:
//   bit  8 = audio channel 1 enabled
//   bit  9 = audio channel 2 enabled
//   bit 10 = (reserved)
//   bit 13 = invert Y axis
extern uint32_t g_gameOptions;             // DAT_00748a38

// ─── Video Settings ──────────────────────────────────────────────
extern DWORD g_videoWidth;                 // DAT_00702b80 — VideoWidth
extern DWORD g_videoHeight;                // DAT_00702b84 — VideoHeight
extern DWORD g_antialiasing;               // DAT_00702b88 — Antialiasing
extern bool  g_verticalSync;               // DAT_00702b8c — VerticalSync
extern bool  g_tripleBuffering;            // DAT_00702b8d — TripleBuffering

// Video device/driver GUIDs (16 bytes each)
extern GUID  g_videoDevGuid;               // DAT_00702ba0 — VideoDevGuid
extern GUID  g_videoDrvGuid;               // DAT_00702b90 — VideoDrvGuid

// ─── Mouse Speed ─────────────────────────────────────────────────
extern float g_mouseSpeed;                 // DAT_00682170 — MSpeed
extern float g_mouseSensitivity;           // DAT_006820c4 — derived from MSpeed

// ─── Audio Volume ────────────────────────────────────────────────
extern float g_defaultVolume;              // DAT_0066bea0 — default volume level

// ─── Renderer Capability Flags ───────────────────────────────────
extern int    g_rendererActive;            // DAT_00702bd0 — renderer type active
extern DWORD  g_playerId;                  // DAT_007028b0 — player capability flags
extern int    g_rendererType;              // DAT_00702be4 — renderer version (3=DX11+)
extern uint8_t g_isMultiplayer;            // DAT_00702bdd — multiplayer mode flag

// ─── Renderer Object ─────────────────────────────────────────────
extern int    g_sceneReady;                // DAT_00702770 — scene/renderer object

// ─── Audio Callbacks (function pointers) ─────────────────────────
// These are called to apply audio settings after loading from registry.
// DAT_00728060 — SetAudioChannel(channel, enabled)
// DAT_0072805c — SetMusicVolume(float)
// DAT_0072803c — SetSoundVolume(float)
// DAT_00728054 — IsAudioChannelActive(channel) → int
// DAT_00728058 — GetMusicVolume() → float
// DAT_00728038 — GetSoundVolume() → float

// ─── Functions ────────────────────────────────────────────────────

/// Load all game settings from the registry.
/// Reads quality settings, audio volumes, video mode, and mouse sensitivity.
/// Validates and clamps all values to valid ranges.
/// If registry version mismatches, calls defaults setter FUN_00540230.
void LoadGameSettings();                    // FUN_00540770

/// Save all game settings to the registry.
/// Writes quality settings, audio volumes, and queries the renderer
/// vtable for current video mode GUIDs.
void SaveGameSettings();                    // FUN_005403e0

} // namespace Giants
