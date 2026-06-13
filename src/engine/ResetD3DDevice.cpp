// Giants Engine - D3D Device Reset Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
// re-agent verdict: FAIL (usable ~75%)
#include "ResetD3DDevice.h"
#include <cstdlib>
#include <cstring>
#include <windows.h>
typedef long HRESULT;
#define S_OK ((HRESULT)0L)

namespace Giants {

extern int     g_adapterCount;     // DAT_006ff9e4
extern void*   g_pD3D9;           // DAT_006ff9e8
extern void*   g_pD3DDevice;      // DAT_006ff9ec
extern uint32_t g_creationParams;  // DAT

extern void BuildPresentParameters();  // FUN_0045e620

void ResetD3DDevice()
{
    if (g_adapterCount != 6 || g_pD3D9 == nullptr)
        return;

    // Get device caps/container size
    size_t capsSize = 0;
    auto getContainer = reinterpret_cast<HRESULT(__cdecl*)(void*, void*, size_t*, int)>(
        *reinterpret_cast<void**>(*reinterpret_cast<uintptr_t*>(g_pD3DDevice) + 0x70));

    HRESULT hr = getContainer(g_pD3DDevice, nullptr, &capsSize, 0);

    if (hr == static_cast<HRESULT>(0x80070600))  // specific error code
    {
        uint32_t* buf = static_cast<uint32_t*>(malloc(capsSize));
        memset(buf, 0, 0x48);
        buf[0] = 0x48;

        hr = getContainer(g_pD3DDevice, buf, &capsSize, 0);

        if (hr == S_OK)
        {
            uint8_t presentParams[56];
            memset(presentParams, 0, 0x38);

            BuildPresentParameters();

            buf[0x11] = 0x38;
            buf[0x10] = reinterpret_cast<uint32_t>(presentParams);
            buf[10] = g_creationParams;

            char deviceName[260];
            memset(deviceName, 0, 0x104);

            buf[0x0C] = reinterpret_cast<uint32_t>(deviceName);

            auto resetFn = reinterpret_cast<HRESULT(__cdecl*)(void*, uint32_t*, int)>(
                *reinterpret_cast<void**>(*reinterpret_cast<uintptr_t*>(g_pD3DDevice) + 0x40));
            resetFn(g_pD3DDevice, buf, 0);
        }

        free(buf);
    }
}

} // namespace Giants
