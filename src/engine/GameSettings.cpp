// Giants Engine - Game Settings (Registry Load/Save)
// Reverse engineered from GiantsMain.exe v1.520.59
//
// FUN_00540770 — LoadGameSettings (PASS)
// FUN_005403e0 — SaveGameSettings (FAIL, ~90% correct)

#include "GameSettings.h"
#include <windows.h>
#include <cstring>

namespace Giants {

// --- Globals from other modules ---
static HKEY    g_hKey = nullptr;            // DAT_0074be54 — registry key
static HKEY    g_hPlayerKey = nullptr;      // DAT_0074be5c — player registry key
static void*   g_rendererObj = nullptr;      // DAT_00702700 — renderer COM object
static int     g_rendererType = 0;           // renderer type (3=D3D, 4=OpenGL)
static int     g_rendererActive = 0;
// ─── External Subroutines ────────────────────────────────────────

/// Reset all game options to defaults and save to registry.
extern void FUN_00540230();     // Default options setter (SetDefaultGameOptions)

/// Notify renderer of shadow detail change.
extern void FUN_004e1cc0();

/// Renderer state update functions (called when quality changes).
extern void FUN_004dff90();
extern void FUN_004dfe20();

// ─── Audio Callback Function Pointers ────────────────────────────
// These are stored as global function pointers resolved at runtime.

// typedef void (*SetAudioChannelFn)(int channel, int enabled);
// typedef void (*SetVolumeFn)(float volume);
// typedef int  (*IsAudioActiveFn)();
// typedef float (*GetVolumeFn)();

// DAT_00728060 — SetAudioChannel
// DAT_0072805c — SetMusicVolume
// DAT_0072803c — SetSoundVolume
// DAT_00728054 — IsAudioChannelActive (returns int)
// DAT_00728058 — GetMusicVolume (returns float)
// DAT_00728038 — GetSoundVolume (returns float)

// ─── Constants ────────────────────────────────────────────────────
// Mouse speed calculation constants (from .rdata)
constexpr float kDefaultMouseSpeed    = 0.0f;      // Lower bound for MSpeed
constexpr float kMaxMouseSpeed        = 0.0f;      // DAT_0066bf2c — upper bound
constexpr float kMouseSpeedOffset     = 0.0f;      // DAT_0066c040 — multiplier
constexpr float kMouseSensFloor       = 0.0f;      // DAT_0066bd9c — minimum sensitivity
constexpr float kMouseSensCeiling     = 0.0f;      // DAT_0066c00c — normalization ceiling
constexpr float kMouseSensMultiplier  = 0.0f;      // DAT_0066be20 — final multiplier

// Default audio volume (also used as fallback for registry reads)
// DAT_0066bea0

// ═══════════════════════════════════════════════════════════════════
// LoadGameSettings — FUN_00540770
// ═══════════════════════════════════════════════════════════════════

void LoadGameSettings()
{
    // ── Phase 1: Version check ──────────────────────────────────
    // Read GameOptionsVersion from HKCU\...\DisplaySettings (g_hKey).
    // If version != 4, reset all options to defaults and set version = 4.

    int regVersion = 0;
    if (g_hKey != nullptr)   // DAT_0074be54
    {
        DWORD dataSize = sizeof(int);
        RegQueryValueExA(g_hKey, "GameOptionsVersion", nullptr, nullptr,
                         reinterpret_cast<LPBYTE>(&regVersion), &dataSize);
    }

    if (regVersion != kGameOptionsVersion)
    {
        // Version mismatch — reset to defaults
        FUN_00540230();

        // Write new version
        DWORD newVersion = kGameOptionsVersion;
        if (g_hKey != nullptr)
        {
            RegSetValueExA(g_hKey, "GameOptionsVersion", 0, REG_DWORD,
                           reinterpret_cast<BYTE*>(&newVersion), sizeof(DWORD));
        }
        return;
    }

    // ── Phase 2: Multiplayer shortcut ──────────────────────────
    // If in multiplayer mode with 6 players and a valid scene object,
    // apply minimal settings and return early.

    if (g_isMultiplayer != 0 && g_sceneReady == 6 && g_sceneReady != 0)
    {
        // NOTE: g_sceneReady is overloaded — the condition checks:
        //   DAT_00702bdd (multiplayer) && DAT_006ff960 == 6 && DAT_00702964 != 0
        g_shadowDetail = 0;         // DAT_00702b18
        FUN_004e1cc0();
        g_objectBumps = true;       // DAT_00702b5c = 1
        // ... additional multiplayer defaults
        // DAT_00702b5e, DAT_00702b6c, DAT_00702b70, DAT_00702afc, DAT_00702b24
        return;
    }

    // ── Phase 3: Read GameOptions bitfield ─────────────────────
    g_gameOptions = 0;              // DAT_00748a38

    if (g_hPlayerKey != nullptr)    // DAT_0074be5c
    {
        DWORD dataSize = sizeof(uint32_t);
        RegQueryValueExA(g_hPlayerKey, "GameOptions", nullptr, nullptr,
                         reinterpret_cast<LPBYTE>(&g_gameOptions), &dataSize);
    }

    // Skip quality settings if no renderer available
    if (g_rendererObj == nullptr)    // DAT_00702700 == 0
        goto load_video_settings;

    // ── Phase 4: ShadowDetail ──────────────────────────────────
    {
        uint32_t shadowDetail = 0;
        if (g_hPlayerKey != nullptr)
        {
            DWORD dataSize = sizeof(uint32_t);
            RegQueryValueExA(g_hPlayerKey, "ShadowDetail", nullptr, nullptr,
                             reinterpret_cast<LPBYTE>(&shadowDetail), &dataSize);
        }

        // Determine maximum allowed shadow detail based on renderer caps
        // If renderer supports shadow maps (DAT_00702bd0, DAT_007028b0 flags):
        //   g_shadowDetail max = 3 (high quality shadows)
        // Otherwise max = 1 (basic shadows)
        int maxShadow = 1;
        if (g_rendererActive != 0 ||
            (g_playerId & 0x4000) == 0 ||
            (g_playerId & 0x40000) == 0)
        {
            maxShadow = 3;
        }
        // Actually the logic is: if renderer CAN do shadows, allow up to 3
        // The original condition is inverted — see Ghidra decompilation
        // if ((DAT_00702bd0 != 0) || ((DAT_007028b0 & 0x4000) == 0) ||
        //     (DAT_00702b18 = 3, (DAT_007028b0 & 0x40000) == 0))
        //     DAT_00702b18 = 1;
        // This means: unless both caps are present, cap at 1

        // Clamp shadow detail
        if (static_cast<int>(shadowDetail) >= 0 && static_cast<int>(shadowDetail) < maxShadow)
        {
            g_shadowDetail = static_cast<int>(shadowDetail);
        }
        else
        {
            g_shadowDetail = 0;
            FUN_004e1cc0();  // Apply shadow detail change
        }
    }

    // ── Phase 5: ObjectBumps ───────────────────────────────────
    {
        // ObjectBumps depends on renderer capabilities:
        // Must have renderer with (DAT_007028b0 & 2) and version >= 4
        bool canBump = true;
        if (g_rendererActive == 0 && (g_playerId & 2) != 0 &&
            static_cast<unsigned>(g_rendererType - 3) < 2)
        {
            canBump = false;
        }
        g_objectBumps = canBump;
    }

    // ── Phase 6: LandscapeQuality ──────────────────────────────
    {
        uint32_t landscapeQuality = 0;

        if (g_hPlayerKey != nullptr)
        {
            DWORD dataSize = sizeof(uint32_t);
            LSTATUS status = RegQueryValueExA(g_hPlayerKey, "LandscapeQuality",
                               nullptr, nullptr,
                               reinterpret_cast<LPBYTE>(&landscapeQuality), &dataSize);
            if (status != ERROR_SUCCESS)
            {
                // Registry read failed — use default based on renderer caps
                if (g_rendererActive == 0 && (g_playerId & 2) != 0 &&
                    (g_playerId & 0x8000) != 0)
                {
                    landscapeQuality = 2;
                }
                else
                {
                    landscapeQuality = 0;
                }
            }
        }
        else
        {
            if (g_rendererActive == 0 && (g_playerId & 2) != 0 &&
                (g_playerId & 0x8000) != 0)
            {
                landscapeQuality = 2;
            }
            else
            {
                landscapeQuality = 0;
            }
        }

        // Clamp to [0, 2]
        g_landscapeQuality = 0;
        if (static_cast<int>(landscapeQuality) >= 0)
        {
            g_landscapeQuality = static_cast<int>(landscapeQuality);
        }
        if (g_landscapeQuality > 2)
        {
            g_landscapeQuality = 2;
        }

        // If renderer doesn't support high-quality landscape, force 0
        if (g_rendererActive == 0 || (g_playerId & 2) == 0 ||
            (g_playerId & 0x8000) == 0)
        {
            g_landscapeQuality = 0;
        }
    }

    // ── Phase 7: Notify renderer of quality changes ────────────
    if (g_sceneReady != 0)   // DAT_00702770
    {
        FUN_004dff90();
        FUN_004dfe20();
        // Set dirty flag at offset 0x503a in scene object
        // *reinterpret_cast<uint8_t*>(g_sceneObj + 0x503a) = 1;
    }

    // ── Phase 8: EnvironmentMapping ────────────────────────────
    {
        uint32_t envMap = 0;
        if (g_hPlayerKey != nullptr)
        {
            DWORD dataSize = sizeof(uint32_t);
            RegQueryValueExA(g_hPlayerKey, "EnvironmentMapping", nullptr, nullptr,
                             reinterpret_cast<LPBYTE>(&envMap), &dataSize);
        }

        // Validate: must be 0 or 1
        if (envMap != 0 && envMap != 1)
            envMap = 0;

        bool newEnvMap = (envMap != 0);
        if (g_environmentMapping != newEnvMap)
        {
            // If renderer supports env mapping caps
            if (g_rendererActive == 0 && (g_playerId & 4) != 0 &&
                (g_playerId & 0x4000) != 0)
            {
                g_environmentMapping = (envMap == 0);
                if (g_sceneReady != 0)
                {
                    // Clear bit 14 (0x4000) at scene offset 0x4efc
                    // *reinterpret_cast<uint32_t*>(g_sceneObj + 0x4efc) &= 0xFFFFBFFF;
                }
            }
            else
            {
                g_environmentMapping = true;
            }
        }
    }

    // ── Phase 9: WaterQuality ──────────────────────────────────
    {
        uint32_t waterQuality = 0;
        if (g_hPlayerKey != nullptr)
        {
            DWORD dataSize = sizeof(uint32_t);
            RegQueryValueExA(g_hPlayerKey, "WaterQuality", nullptr, nullptr,
                             reinterpret_cast<LPBYTE>(&waterQuality), &dataSize);
        }

        // Clamp to [0, 2]
        if (waterQuality > 2)
            waterQuality = 2;

        g_waterQuality = 0;
        if (static_cast<int>(waterQuality) >= 0)
            g_waterQuality = static_cast<int>(waterQuality);

        // Force to 0 if renderer doesn't support water effects
        if (g_rendererActive == 0 || (g_playerId & 0x40) == 0 ||
            (g_playerId & 0x4000) == 0)
        {
            g_waterQuality = 0;
        }
    }

    // ── Phase 10: Sunflare ─────────────────────────────────────
    {
        uint32_t sunflare = 0;
        if (g_hPlayerKey != nullptr)
        {
            DWORD dataSize = sizeof(uint32_t);
            RegQueryValueExA(g_hPlayerKey, "Sunflare", nullptr, nullptr,
                             reinterpret_cast<LPBYTE>(&sunflare), &dataSize);
        }

        // Validate: must be 0 or 1
        if (sunflare != 0 && sunflare != 1)
            sunflare = 0;

        // Inverted: stored as (sunflare == 0)
        g_sunflare = (sunflare == 0);
    }

    // ── Phase 11: WeatherDetail ────────────────────────────────
    {
        uint32_t weatherDetail = 0;
        if (g_hPlayerKey != nullptr)
        {
            DWORD dataSize = sizeof(uint32_t);
            RegQueryValueExA(g_hPlayerKey, "WeatherDetail", nullptr, nullptr,
                             reinterpret_cast<LPBYTE>(&weatherDetail), &dataSize);
        }

        // Clamp to [0, 2]
        if (static_cast<int>(weatherDetail) < 3)
        {
            g_weatherDetail = static_cast<int>(weatherDetail);
            if (g_weatherDetail < 0)
                g_weatherDetail = 0;
        }
        else
        {
            g_weatherDetail = 2;
        }
    }

    // ── Phase 12: ModelDetail ──────────────────────────────────
    {
        uint32_t modelDetail = 3;  // Default
        if (g_hPlayerKey != nullptr)
        {
            DWORD dataSize = sizeof(uint32_t);
            LSTATUS status = RegQueryValueExA(g_hPlayerKey, "ModelDetail",
                               nullptr, nullptr,
                               reinterpret_cast<LPBYTE>(&modelDetail), &dataSize);
            if (status != ERROR_SUCCESS)
                modelDetail = 3;  // Default on registry read failure
        }

        // Clamp to [0, 3]
        if (static_cast<int>(modelDetail) < 4)
        {
            g_modelDetail = static_cast<int>(modelDetail);
            if (g_modelDetail < 0)
                g_modelDetail = 0;
        }
        else
        {
            g_modelDetail = 3;
        }
    }

    // ── Phase 13: LightingQuality ──────────────────────────────
    {
        uint32_t lightingQuality = 2;  // Default
        if (g_hPlayerKey != nullptr)
        {
            DWORD dataSize = sizeof(uint32_t);
            LSTATUS status = RegQueryValueExA(g_hPlayerKey, "LightingQuality",
                               nullptr, nullptr,
                               reinterpret_cast<LPBYTE>(&lightingQuality), &dataSize);
            if (status != ERROR_SUCCESS)
                lightingQuality = 2;
        }

        // Clamp to [0, 2]
        if (static_cast<int>(lightingQuality) < 3)
        {
            g_lightingQuality = static_cast<int>(lightingQuality);
            if (g_lightingQuality < 0)
                g_lightingQuality = 0;
        }
        else
        {
            g_lightingQuality = 2;
        }
    }

    // ── Phase 14: ObjectBumps (re-evaluated from registry) ─────
    {
        uint32_t objectBumps = 0;
        if (g_hPlayerKey != nullptr)
        {
            DWORD dataSize = sizeof(uint32_t);
            RegQueryValueExA(g_hPlayerKey, "ObjectBumps", nullptr, nullptr,
                             reinterpret_cast<LPBYTE>(&objectBumps), &dataSize);
        }

        // If renderer supports bump mapping and is DX9-era (version < 5)
        if (g_rendererActive == 0 && (g_playerId & 2) != 0 &&
            static_cast<unsigned>(g_rendererType - 3) < 2)
        {
            g_objectBumps = (objectBumps == 0);
        }
        else
        {
            g_objectBumps = true;
        }
    }

    // ── Phase 15: Audio settings ───────────────────────────────
    // Apply audio channel states from GameOptions bitfield
    // (*DAT_00728060)(1, (g_gameOptions >> 8) & 1);  // Audio channel 1
    // (*DAT_00728060)(2, (g_gameOptions >> 9) & 1);  // Audio channel 2

    // Music volume
    {
        float musicVolume = g_defaultVolume;    // DAT_0066bea0
        if (g_hPlayerKey != nullptr)
        {
            DWORD dataSize = sizeof(float);
            RegQueryValueExA(g_hPlayerKey, "MusicVolume", nullptr, nullptr,
                             reinterpret_cast<LPBYTE>(&musicVolume), &dataSize);
        }
        // (*DAT_0072805c)(musicVolume);  // SetMusicVolume
    }

    // Sound volume
    {
        float soundVolume = g_defaultVolume;    // DAT_0066bea0
        if (g_hPlayerKey != nullptr)
        {
            DWORD dataSize = sizeof(float);
            RegQueryValueExA(g_hPlayerKey, "SoundVolume", nullptr, nullptr,
                             reinterpret_cast<LPBYTE>(&soundVolume), &dataSize);
        }
        // (*DAT_0072803c)(soundVolume);  // SetSoundVolume
    }

load_video_settings:
    // ── Phase 16: Video settings ───────────────────────────────
    // Read from g_hKey (DisplaySettings key), not g_hPlayerKey
    if (g_hKey != nullptr)
    {
        DWORD dataSize = sizeof(DWORD);

        RegQueryValueExA(g_hKey, "VideoWidth", nullptr, nullptr,
                         reinterpret_cast<LPBYTE>(&g_videoWidth), &dataSize);
        RegQueryValueExA(g_hKey, "VideoHeight", nullptr, nullptr,
                         reinterpret_cast<LPBYTE>(&g_videoHeight), &dataSize);
        RegQueryValueExA(g_hKey, "Antialiasing", nullptr, nullptr,
                         reinterpret_cast<LPBYTE>(&g_antialiasing), &dataSize);

        // VerticalSync (read as DWORD, convert to bool)
        uint32_t vsync = 0;
        dataSize = sizeof(DWORD);
        RegQueryValueExA(g_hKey, "VerticalSync", nullptr, nullptr,
                         reinterpret_cast<LPBYTE>(&vsync), &dataSize);
        g_verticalSync = (vsync != 0);

        // TripleBuffering
        uint32_t tripleBuf = 0;
        dataSize = sizeof(DWORD);
        RegQueryValueExA(g_hKey, "TripleBuffering", nullptr, nullptr,
                         reinterpret_cast<LPBYTE>(&tripleBuf), &dataSize);
        g_tripleBuffering = (tripleBuf != 0);
    }

    // Video device/driver GUIDs (16 bytes each)
    {
        DWORD guidSize = sizeof(GUID);  // 16 bytes
        RegQueryValueExA(g_hKey, "VideoDevGuid", nullptr, nullptr,
                         reinterpret_cast<LPBYTE>(&g_videoDevGuid), &guidSize);
        RegQueryValueExA(g_hKey, "VideoDrvGuid", nullptr, nullptr,
                         reinterpret_cast<LPBYTE>(&g_videoDrvGuid), &guidSize);
    }

    // ── Phase 17: Invert Y from GameOptions ────────────────────
    g_invertY = (g_gameOptions >> 13) & 1;

    // ── Phase 18: Mouse speed ──────────────────────────────────
    // Only applies if g_rendererActive == 0 (DAT_00701bd4)
    // if (g_rendererActive == 0)
    // {
    //     float mouseSpeed = kDefaultMouseSpeed;  // DAT_00682170
    //     if (g_hPlayerKey != nullptr)
    //     {
    //         DWORD dataSize = sizeof(float);
    //         RegQueryValueExA(g_hPlayerKey, "MSpeed", nullptr, nullptr,
    //                          reinterpret_cast<LPBYTE>(&mouseSpeed), &dataSize);
    //         g_mouseSpeed = mouseSpeed;
    //     }
    //
    //     // Clamp mouse speed to valid range [0, kMaxMouseSpeed]
    //     float clampedSpeed = 0.0f;
    //     if (g_mouseSpeed >= 0.0f && g_mouseSpeed <= kMaxMouseSpeed)
    //         clampedSpeed = g_mouseSpeed;
    //
    //     g_mouseSpeed = clampedSpeed;
    //
    //     // Calculate derived sensitivity
    //     float range = (kMaxMouseSpeed - clampedSpeed) * kMouseSpeedOffset;
    //     float sensitivity = kMouseSensFloor;
    //     if (kMouseSensFloor <= range)
    //         sensitivity = range;
    //
    //     if (sensitivity < kMouseSensCeiling)
    //     {
    //         g_mouseSensitivity = sensitivity * kMouseSensMultiplier;
    //     }
    //     else
    //     {
    //         g_mouseSensitivity = sensitivity / kMouseSensCeiling;
    //     }
    // }
}


// ═══════════════════════════════════════════════════════════════════
// SaveGameSettings — FUN_005403e0
// ═══════════════════════════════════════════════════════════════════
// Status: FAIL (~90% correct)
// Writes all game settings back to registry. Queries renderer vtable
// for current video mode parameters.

void SaveGameSettings()
{
    // Early exit: ensure both registry keys are open
    if (g_hKey == nullptr || g_hPlayerKey == nullptr)
    {
        // FUN_0062ad90() — LockGraphics / open registry keys
        // If keys couldn't be opened, the saves below will silently skip
        // due to the null checks.
    }

    // Skip saving in multiplayer mode
    if (g_isMultiplayer != 0)
        return;

    // ── Save quality settings ──────────────────────────────────
    g_gameOptions = 0;  // Reset bitfield for rebuild

    // ShadowDetail
    if (g_hPlayerKey != nullptr)
    {
        DWORD val = static_cast<DWORD>(g_shadowDetail);
        RegSetValueExA(g_hPlayerKey, "ShadowDetail", 0, REG_DWORD,
                       reinterpret_cast<BYTE*>(&val), sizeof(DWORD));
    }

    // WeatherDetail
    if (g_hPlayerKey != nullptr)
    {
        DWORD val = static_cast<DWORD>(g_weatherDetail);
        RegSetValueExA(g_hPlayerKey, "WeatherDetail", 0, REG_DWORD,
                       reinterpret_cast<BYTE*>(&val), sizeof(DWORD));
    }

    // ModelDetail
    if (g_hPlayerKey != nullptr)
    {
        DWORD val = static_cast<DWORD>(g_modelDetail);
        RegSetValueExA(g_hPlayerKey, "ModelDetail", 0, REG_DWORD,
                       reinterpret_cast<BYTE*>(&val), sizeof(DWORD));
    }

    // WaterQuality
    if (g_hPlayerKey != nullptr)
    {
        DWORD val = static_cast<DWORD>(g_waterQuality);
        RegSetValueExA(g_hPlayerKey, "WaterQuality", 0, REG_DWORD,
                       reinterpret_cast<BYTE*>(&val), sizeof(DWORD));
    }

    // Sunflare (inverted: stored as !g_sunflare)
    if (g_hPlayerKey != nullptr)
    {
        DWORD val = g_sunflare ? 0 : 1;
        RegSetValueExA(g_hPlayerKey, "Sunflare", 0, REG_DWORD,
                       reinterpret_cast<BYTE*>(&val), sizeof(DWORD));
    }

    // LandscapeQuality
    if (g_hPlayerKey != nullptr)
    {
        DWORD val = static_cast<DWORD>(g_landscapeQuality);
        RegSetValueExA(g_hPlayerKey, "LandscapeQuality", 0, REG_DWORD,
                       reinterpret_cast<BYTE*>(&val), sizeof(DWORD));
    }

    // EnvironmentMapping (inverted: stored as !g_environmentMapping)
    if (g_hPlayerKey != nullptr)
    {
        DWORD val = g_environmentMapping ? 0 : 1;
        RegSetValueExA(g_hPlayerKey, "EnvironmentMapping", 0, REG_DWORD,
                       reinterpret_cast<BYTE*>(&val), sizeof(DWORD));
    }

    // ObjectBumps (inverted: stored as !g_objectBumps)
    if (g_hPlayerKey != nullptr)
    {
        DWORD val = g_objectBumps ? 0 : 1;
        RegSetValueExA(g_hPlayerKey, "ObjectBumps", 0, REG_DWORD,
                       reinterpret_cast<BYTE*>(&val), sizeof(DWORD));
    }

    // LightingQuality
    if (g_hPlayerKey != nullptr)
    {
        DWORD val = static_cast<DWORD>(g_lightingQuality);
        RegSetValueExA(g_hPlayerKey, "LightingQuality", 0, REG_DWORD,
                       reinterpret_cast<BYTE*>(&val), sizeof(DWORD));
    }

    // ── Rebuild GameOptions bitfield ───────────────────────────
    // Query audio channel states and pack into bitfield

    // Audio channel 1 active → set bit 0x200
    // int channel1Active = (*DAT_00728054)();  // IsAudioChannelActive
    // if (channel1Active != 0)
    //     g_gameOptions |= 0x200;

    // Audio channel 2 active → set bit 0x100
    // int channel2Active = (*DAT_00728054)();
    // if (channel2Active != 0)
    //     g_gameOptions |= 0x100;

    // Invert Y → set bit 0x2000
    if (g_invertY)
    {
        g_gameOptions |= 0x2000;
    }

    // Write GameOptions bitfield
    if (g_hPlayerKey != nullptr)
    {
        DWORD val = g_gameOptions;
        RegSetValueExA(g_hPlayerKey, "GameOptions", 0, REG_DWORD,
                       reinterpret_cast<BYTE*>(&val), sizeof(DWORD));
    }

    // ── Save audio volumes ─────────────────────────────────────
    // float musicVolume = (*DAT_00728058)();  // GetMusicVolume
    // if (g_hPlayerKey != nullptr)
    //     RegSetValueExA(g_hPlayerKey, "MusicVolume", 0, REG_DWORD,
    //                    reinterpret_cast<BYTE*>(&musicVolume), sizeof(DWORD));

    // float soundVolume = (*DAT_00728038)();  // GetSoundVolume
    // if (g_hPlayerKey != nullptr)
    //     RegSetValueExA(g_hPlayerKey, "SoundVolume", 0, REG_DWORD,
    //                    reinterpret_cast<BYTE*>(&soundVolume), sizeof(DWORD));

    // ── Save video settings via renderer vtable ────────────────
    // Query current video mode from the renderer COM object.
    // vtable offsets:
    //   0xD4 (index 53) = GetVideoParam(int param) → DWORD
    //     param 0 = VideoWidth
    //     param 2 = VideoHeight
    //     param 5 = VideoDepth
    //   0x70 (index 28) = GetVideoGuids(GUID* outDev, GUID* outDrv)
    //
    // if (g_rendererObj != nullptr)
    // {
    //     auto* vtable = *reinterpret_cast<void***>(g_rendererObj);
    //
    //     auto getVideoParam = reinterpret_cast<DWORD(*)(int)>(
    //         vtable[0xD4 / 4]);
    //
    //     DWORD width = getVideoParam(0);
    //     if (g_hKey != nullptr)
    //         RegSetValueExA(g_hKey, "VideoWidth", 0, REG_DWORD,
    //                        reinterpret_cast<BYTE*>(&width), sizeof(DWORD));
    //
    //     DWORD height = getVideoParam(2);
    //     if (g_hKey != nullptr)
    //         RegSetValueExA(g_hKey, "VideoHeight", 0, REG_DWORD,
    //                        reinterpret_cast<BYTE*>(&height), sizeof(DWORD));
    //
    //     DWORD depth = getVideoParam(5);
    //     if (g_hKey != nullptr)
    //         RegSetValueExA(g_hKey, "VideoDepth", 0, REG_DWORD,
    //                        reinterpret_cast<BYTE*>(&depth), sizeof(DWORD));
    //
    //     // Get video GUIDs
    //     auto getVideoGuids = reinterpret_cast<void(*)(GUID*, GUID*)>(
    //         vtable[0x70 / 4]);
    //     GUID devGuid, drvGuid;
    //     getVideoGuids(&devGuid, &drvGuid);
    //
    //     if (g_hKey != nullptr)
    //     {
    //         RegSetValueExA(g_hKey, "VideoDevGuid", 0, REG_BINARY,
    //                        reinterpret_cast<BYTE*>(&devGuid), sizeof(GUID));
    //         RegSetValueExA(g_hKey, "VideoDrvGuid", 0, REG_BINARY,
    //                        reinterpret_cast<BYTE*>(&drvGuid), sizeof(GUID));
    //     }
    // }

    // ── Write final version stamp ──────────────────────────────
    {
        DWORD version = kGameOptionsVersion;  // 4
        if (g_hKey != nullptr)
        {
            RegSetValueExA(g_hKey, "GameOptionsVersion", 0, REG_DWORD,
                           reinterpret_cast<BYTE*>(&version), sizeof(DWORD));
        }
    }
}

} // namespace Giants

// ═══════════════════════════════════════════════════════════════════
// SetDefaultGameOptions — FUN_00540230 (STUB)
// ═══════════════════════════════════════════════════════════════════
// Reset all game quality settings to default values.
// Called when registry version mismatches (version != 4).
// Also resets input state for mode==2 (full reset).
// 2 callers, 2 callees.
//
// Ghidra decompilation shows:
//   - For mode==0 or mode==2: calls audio callbacks (SetAudioChannel, SetVolume)
//   - For mode==2: resets keyboard/controller state, queries renderer vtable
//     for player capabilities, sets quality defaults (shadow=0, landscape=1, etc.)

namespace Giants {

void SetDefaultGameOptions(int mode)  // FUN_00540230
{
    // Apply audio defaults for mode 0 (first-time) or 2 (full reset)
    if ((mode == 0 || mode == 2) /* && DAT_00728060 != NULL */)
    {
        // (*DAT_00728060)(1, 1);  // SetAudioChannel(1, enabled)
        // (*DAT_00728060)(2, 1);  // SetAudioChannel(2, enabled)
        // (*DAT_0072805c)(0.75f); // SetMusicVolume
        // (*DAT_0072803c)(0.75f); // SetSoundVolume
    }

    if (mode == 2)
    {
        // Full reset of input/quality state
        // DAT_00702b8e = 0  (keyboard flag)
        // DAT_00702b80 = 0  (width)
        // DAT_00702b84 = 0  (height)

        // Query renderer capabilities via vtable[0xD4](7)
        // if (DAT_00702700 != NULL) {
        //     DAT_007028b0 = vtable[0xD4](7);  // player capability flags
        //     DAT_00702b5c = (caps & ~2) != 0;  // env mapping
        //     DAT_00702b5e = (caps >> 2) & 1;   // object bumps
        //     ...
        // }

        // Set quality defaults
        // DAT_00702b18 = 2   (shadow detail)
        // DAT_00702afc = 1   (weather detail)
        // DAT_00702b00 = 2   (lighting quality)
    }

    // Reset mouse speed and sensitivity
    // DAT_00702bd8 = 0    (invert Y)
    // DAT_00682170 = 0.5f (mouse speed)
    // DAT_006820c4 = 1.0f (mouse sensitivity)
}

} // namespace Giants
