// Vanilla-Native Recomp — registry settings loader (port of FUN_00483740 / FUN_004a3900).
// See behavior_specs/loading_registry_cursor.md. The vanilla reads HKCU\Software\PlanetMoon
// \Giants at boot for VideoWidth/Height/Depth + GUIDs + GameOptions + volumes, into globals
// the renderer (gg_dx7r GDVSysCreate) uses for the device resolution. The recomp formerly
// HARDCODED 640x480; this reads the real registry values (defaulting if absent) so the
// renderer + window use the player's configured resolution — faithful to the vanilla init.
#include <windows.h>
#include <cstdio>
#include <cstdint>
#include <cstring>

extern "C" FILE* g_vTrace;

// Vanilla globals (DAT_ addresses) — the renderer reads these for device creation.
extern "C" uint32_t g_videoWidth  = 0;   // DAT_00631818
extern "C" uint32_t g_videoHeight = 0;   // DAT_0063181c
extern "C" uint32_t g_videoDepth  = 0;   // DAT_00631820
extern "C" uint32_t g_windowed    = 1;   // (Windowed flag)
extern "C" uint32_t g_gameOptions = 0;   // _DAT_0059df14 (GameOptions bitmask)
extern "C" float    g_musicVolume = 0.78f;  // (*DAT_005dc2f8 default ~0x3f400000=0.75)
extern "C" float    g_soundVolume = 0.78f;  // (*DAT_005dc298)

static HKEY openGiantsKey() {
    HKEY hKey = nullptr;
    if (RegCreateKeyExA(HKEY_CURRENT_USER, "Software\\PlanetMoon\\Giants", 0, nullptr, 0,
                        KEY_ALL_ACCESS, nullptr, &hKey, nullptr) != ERROR_SUCCESS)
        return nullptr;
    return hKey;
}

// FUN_0051f7a0 — read a REG_DWORD.
static uint32_t regDword(HKEY hKey, const char* name, uint32_t def) {
    DWORD v = def, sz = sizeof(v), type = 0;
    if (RegQueryValueExA(hKey, name, nullptr, &type, (BYTE*)&v, &sz) != ERROR_SUCCESS || type != REG_DWORD)
        return def;
    return v;
}
// FUN_0051f840 — read a REG_BINARY blob.
static bool regBinary(HKEY hKey, const char* name, void* out, uint32_t len) {
    DWORD sz = len, type = 0;
    return RegQueryValueExA(hKey, name, nullptr, &type, (BYTE*)out, &sz) == ERROR_SUCCESS && type == REG_BINARY;
}

// FUN_00483740 — read saved settings from registry into the globals.
extern "C" void VanillaSettings_Load(void) {
    HKEY hKey = openGiantsKey();
    if (!hKey) return;
    // GameOptionsVersion gate (vanilla checks ==1); read regardless, default to current.
    g_gameOptions = regDword(hKey, "GameOptions", 0);
    g_videoWidth  = regDword(hKey, "VideoWidth",  640);
    g_videoHeight = regDword(hKey, "VideoHeight", 480);
    g_videoDepth  = regDword(hKey, "VideoDepth",  16);
    g_windowed    = regDword(hKey, "Windowed",    1);
    // VideoDevGuid / VideoDrvGuid (16B each) — read into static buffers (renderer may use).
    static uint8_t devGuid[16], drvGuid[16];
    regBinary(hKey, "VideoDevGuid", devGuid, 16);
    regBinary(hKey, "VideoDrvGuid", drvGuid, 16);
    // Volumes (stored as float bits in registry; default 0x3f400000 = 0.75).
    DWORD mv = 0x3f400000, sv = 0x3f400000;
    DWORD sz = 4, type = 0;
    if (RegQueryValueExA(hKey, "MusicVolume", nullptr, &type, (BYTE*)&mv, &sz) == ERROR_SUCCESS)
        memcpy(&g_musicVolume, &mv, 4);
    if (RegQueryValueExA(hKey, "SoundVolume", nullptr, &type, (BYTE*)&sv, &sz) == ERROR_SUCCESS)
        memcpy(&g_soundVolume, &sv, 4);
    RegCloseKey(hKey);
    if (g_vTrace) { fprintf(g_vTrace, "[SETTINGS] registry: %ux%ux%u windowed=%u opts=0x%x music=%.2f sound=%.2f\n",
        g_videoWidth, g_videoHeight, g_videoDepth, g_windowed, g_gameOptions, g_musicVolume, g_soundVolume); fflush(g_vTrace); }
}

// FUN_004a3900 (default-write path) — ensure the registry has sane defaults for the
// renderer to find (first-run). Writes only if VideoWidth is absent.
extern "C" void VanillaSettings_EnsureDefaults(void) {
    HKEY hKey = openGiantsKey();
    if (!hKey) return;
    DWORD sz = 4, type = 0; DWORD existing = 0;
    if (RegQueryValueExA(hKey, "VideoWidth", nullptr, &type, (BYTE*)&existing, &sz) != ERROR_SUCCESS) {
        DWORD w = 640, h = 480, d = 16, win = 1;
        RegSetValueExA(hKey, "Renderer",   0, REG_SZ,   (BYTE*)"gg_dx7r.dll", 12);
        RegSetValueExA(hKey, "VideoWidth", 0, REG_DWORD, (BYTE*)&w, 4);
        RegSetValueExA(hKey, "VideoHeight",0, REG_DWORD, (BYTE*)&h, 4);
        RegSetValueExA(hKey, "VideoDepth", 0, REG_DWORD, (BYTE*)&d, 4);
        RegSetValueExA(hKey, "Windowed",   0, REG_DWORD, (BYTE*)&win, 4);
        if (g_vTrace) { fprintf(g_vTrace, "[SETTINGS] wrote first-run defaults (640x480x16 windowed)\n"); fflush(g_vTrace); }
    }
    RegCloseKey(hKey);
}
