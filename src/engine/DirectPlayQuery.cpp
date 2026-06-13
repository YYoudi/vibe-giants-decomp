// Giants Engine - DirectPlay Session Query Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "DirectPlayQuery.h"
#include <cstdint>
#include <cstdlib>
#include <cstring>

namespace Giants {

// ─── Shared globals ────────────────────────────────────────────
extern uint32_t DAT_0067d280;    // Security cookie — CRTStubs.cpp
extern void*    DAT_006ff960;    // Session state/type — Network.cpp
extern void**   DAT_006ff9e4;    // DirectPlay interface ptr — Network.cpp
extern uint32_t DAT_00702964;    // Session flags — Network.cpp
extern uint32_t DAT_0070294c;    // Session descriptor field — Network.cpp
extern void*    DAT_00702968;    // Session GUID buffer — Network.cpp

// ─── External callees ──────────────────────────────────────────
extern void FUN_0045ec20();      // Session descriptor init
extern void FUN_006328b0();      // GUID copy/initialize

// ═══════════════════════════════════════════════════════════════════
// QueryDirectPlaySession (FUN_0045efd0) — 20 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Queries DirectPlay for current session information.
// Only active when DAT_006ff960 == 6 (in-session) and
// DAT_00702964 != 0 (session data available).
//
// Flow:
//   1. Check preconditions (session type + flags)
//   2. Query session size via vtable[0x1c] (GetSessionDesc size query)
//   3. Allocate buffer of returned size
//   4. Zero 0x48 bytes, set header size
//   5. Fill descriptor via vtable[0x1c] (GetSessionDesc data fill)
//   6. Initialize local descriptor and copy session fields
//   7. Copy GUID via FUN_006328b0
//   8. Dispatch via vtable[0x30] (SetSessionDesc)
//   9. Free buffer

void QueryDirectPlaySession()
{
    if (reinterpret_cast<uintptr_t>(DAT_006ff960) != 6) {
        return;
    }
    if (DAT_00702964 == 0) {
        return;
    }

    // Query 1: get required buffer size
    size_t bufferSize = 0;
    int hr = reinterpret_cast<int(*)(void*, int, size_t*, int)>(
        *reinterpret_cast<void**>(*DAT_006ff9e4 + 0x1c))(
            DAT_006ff9e4, 0, &bufferSize, 0);

    if (hr != -0x7fea7f00) {  // DPERR_BUFFERTOOSMALL
        return;
    }

    // Allocate and fill descriptor
    uint32_t* desc = static_cast<uint32_t*>(malloc(bufferSize));
    memset(desc, 0, 0x48);
    desc[0] = 0x48;  // dwSize

    hr = reinterpret_cast<int(*)(void*, uint32_t*, size_t*, int)>(
        *reinterpret_cast<void**>(*DAT_006ff9e4 + 0x1c))(
            DAT_006ff9e4, desc, &bufferSize, 0);

    if (hr == 0) {  // DP_OK
        // Build local descriptor
        uint8_t localDesc[0x38];
        memset(localDesc, 0, 0x38);
        FUN_0045ec20();

        desc[0x11] = 0x38;
        desc[0x10] = reinterpret_cast<uint32_t>(localDesc);
        desc[10] = DAT_0070294c;

        uint8_t guidBuffer[0x100];
        FUN_006328b0();  // String copy — args handled internally
        desc[0xc] = reinterpret_cast<uint32_t>(guidBuffer);

        // Set session desc
        reinterpret_cast<int(*)(void*, uint32_t*, int)>(
            *reinterpret_cast<void**>(*DAT_006ff9e4 + 0x30))(
                DAT_006ff9e4, desc, 0);
    }

    free(desc);
}

} // namespace Giants
