// Giants Engine - Get Application Version Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
// re-agent verdict: PASS
#include "GetAppVersion.h"
#include <cstring>

#ifdef _WIN32
#include <windows.h>
#endif

namespace Giants {

// ─── Globals ────────────────────────────────────────────────────
extern uint32_t DAT_0067d280;    // Security cookie

static uint32_t g_versionMajor = static_cast<uint32_t>(-1);  // DAT_00685774
static uint32_t g_versionPad1  = 0;                            // _DAT_00685778
static uint32_t g_versionPatch = 0;                            // _DAT_0068577c
static uint32_t g_versionMinor = 0;                            // _DAT_00685780

uint32_t* GetApplicationVersion()
{
    uint32_t cookie = DAT_0067d280 ^ reinterpret_cast<uint32_t>(&cookie);

    if (g_versionMajor == static_cast<uint32_t>(-1))
    {
#ifdef _WIN32
        char modulePath[260];
        GetModuleFileNameA(nullptr, modulePath, 0x103);

        uint32_t handle;
        uint32_t infoSize = GetFileVersionInfoSizeA(modulePath, reinterpret_cast<uint32_t*>(&handle));

        if (infoSize != 0)
        {
            void* versionData = malloc(infoSize);
            GetFileVersionInfoA(modulePath, 0, infoSize, versionData);

            void* versionBuffer = nullptr;
            unsigned int versionLength = 0;
            VerQueryValueA(versionData, "\\", &versionBuffer, &versionLength);

            auto* versionInfo = static_cast<uint8_t*>(versionBuffer);

            g_versionMajor = static_cast<uint32_t>(*reinterpret_cast<uint16_t*>(versionInfo + 10));
            g_versionPad1  = static_cast<uint32_t>(*reinterpret_cast<uint16_t*>(versionInfo + 8));
            g_versionPatch = static_cast<uint32_t>(*reinterpret_cast<uint16_t*>(versionInfo + 14));
            g_versionMinor = static_cast<uint32_t>(*reinterpret_cast<uint16_t*>(versionInfo + 12));

            free(versionData);
        }
#endif
    }

    return &g_versionMajor;
}

} // namespace Giants
