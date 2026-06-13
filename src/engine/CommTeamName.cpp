// Giants Engine - Comm Team Name Builder Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
// re-agent verdict: FAIL (usable ~80%)
#include "CommTeamName.h"
#include <cstring>

namespace Giants {

// ─── Globals ────────────────────────────────────────────────────
extern int        DAT_0074dac0;     // TLS index
extern int        DAT_0070292c;     // Team number
extern uint32_t   DAT_0067d280;     // Security cookie
extern int        _DAT_006858c8;
extern int        _DAT_006858b8;
extern unsigned int uRam006858bc;
extern unsigned int uRam006858c0;
extern unsigned int uRam006858c4;
extern void*      ThreadLocalStoragePointer;

// ─── External callees ──────────────────────────────────────────
extern void  FUN_006435f8(int*, unsigned int);
extern void  FUN_0064389d(void*);
extern void  FUN_006435a7(int*);
extern void  FUN_0043cb70(const char*, int);
extern void* FUN_0044efd0(const char*, unsigned int);
extern void  FUN_004439b0();
extern char* FUN_005e80c0(void*);
extern void  FUN_00442eb0(const char*, int);
extern void  FUN_00643505(void*, unsigned int);

void* BuildCommTeamName(int param1)
{
    // SSO string local (24 bytes)
    char localStr[24];
    memset(localStr, 0, 24);
    *reinterpret_cast<uint32_t*>(localStr + 20) = 0xf; // capacity = 15

    uint32_t cookie = DAT_0067d280 ^ reinterpret_cast<uint32_t>(localStr);

    // TLS init pattern
    if ((*reinterpret_cast<int*>(*reinterpret_cast<int*>(ThreadLocalStoragePointer) + 4) < DAT_0074dac0) &&
        (FUN_006435f8(&DAT_0074dac0, cookie), DAT_0074dac0 == -1))
    {
        FUN_0064389d(reinterpret_cast<void*>(0x006513d0));
        FUN_006435a7(&DAT_0074dac0);
    }

    if (param1 == 0x7f)
    {
        FUN_0043cb70("CommTeamSpectator", 0x11);
    }
    else
    {
        const char* formatStr;
        unsigned int formatLen;

        switch (DAT_0070292c)
        {
        case 0: case 1: case 2:
            formatLen = 0xd;
            formatStr = "CommTeamNo{0}";
            break;
        case 3: case 4: case 5: case 6:
            formatLen = 0xe;
            formatStr = "CommTeamNo{0}A";
            break;
        default:
            goto finalize;
        }

        void* resultPtr = FUN_0044efd0(formatStr, formatLen);
        if (localStr != resultPtr)
        {
            FUN_004439b0();
            memcpy(localStr, resultPtr, 24);
            *reinterpret_cast<uint32_t*>(static_cast<char*>(resultPtr) + 16) = 0;
            *reinterpret_cast<uint32_t*>(static_cast<char*>(resultPtr) + 20) = 0xf;
        }
        FUN_004439b0();
    }

finalize:
    // Resolve SSO data pointer
    uint32_t capacity = *reinterpret_cast<uint32_t*>(localStr + 20);
    const char* strData = (capacity > 0xf) ? *reinterpret_cast<char**>(localStr) : localStr;

    char* endPtr = FUN_005e80c0(reinterpret_cast<void*>(const_cast<char*>(strData)));
    char* iter = endPtr;
    char c;
    do { c = *iter; iter++; } while (c != '\0');

    FUN_00442eb0(endPtr, static_cast<int>(reinterpret_cast<intptr_t>(iter) - reinterpret_cast<intptr_t>(endPtr + 1)));
    FUN_004439b0();

    // Clear global state
    _DAT_006858c8 = 0;
    _DAT_006858b8 =  0;
    uRam006858bc = 0;
    uRam006858c0 = 0;
    uRam006858c4 = 0;

    return &_DAT_006858b8;
}

} // namespace Giants
