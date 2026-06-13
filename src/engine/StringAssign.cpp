// Giants Engine - String Assign Operation Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "StringAssign.h"
#include "CRTStubs.h"
#include <cstdlib>
#include <cstring>
#include <stdexcept>

namespace Giants {

// ─── External helpers ──────────────────────────────────────────
extern void StringAssignPrepare(char* src, int len);   // FUN_00442eb0
extern uint32_t StringMoveAssign(int* local);           // FUN_00432120
extern uint32_t StringAssignError1(uint32_t cookie);    // FUN_0043fc70
extern uint32_t StringAssignResize(uint32_t val);       // FUN_00442f40
extern uint32_t StringAssignError2(uint32_t val);       // FUN_0043fe80
extern void StringAssignError3(uint32_t val);            // FUN_0043fef0

extern uintptr_t g_securityCookie;  // DAT_0067d280

// ═══════════════════════════════════════════════════════════════════
// StringAssignFromPtr (FUN_0042fed0) — 30 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// MSVC std::string assignment from a C string pointer.
// The string object has a state byte at offset 0:
//   0 = uninitialized → initialize SSO string then assign
//   1 = active → assign the new string data
//   2+ = error state → throws exception

uint32_t StringAssignFromPtr(char* strObj, char* src)
{
    // Security cookie setup (SEH prolog)
    uintptr_t cookie = g_securityCookie ^ reinterpret_cast<uintptr_t>(&cookie);

    char* local_src = src;

    if (*strObj == '\0') {
        // State 0: Uninitialized — set up the string object
        *strObj = '\x01';
        // FUN_004409f0(1) — string push_back init
        // Store local frame pointers (Ghidra artifact)
    }

    if (*strObj == '\x01') {
        // State 1: Active — assign the string
        int local_3c[7] = {0, 0, 0, 0, 0, 0, 0};

        // Measure source string length
        char* pcVar5 = local_src;
        char cVar1;
        do {
            cVar1 = *pcVar5;
            pcVar5 = pcVar5 + 1;
        } while (cVar1 != '\0');

        // Prepare the string data
        StringAssignPrepare(local_src, static_cast<int>(pcVar5 - (local_src + 1)));

        // Move-assign from local to output
        uint32_t result = StringMoveAssign(local_3c);

        // Free old buffer if heap-allocated (capacity > 15)
        if (0xf < static_cast<uint32_t>(local_3c[5])) {
            uint32_t freeSize = local_3c[5] + 1;
            int freePtr = local_3c[0];

            if (0xfff < freeSize) {
                freePtr = *reinterpret_cast<int*>(local_3c[0] - 4);
                freeSize = local_3c[5] + 0x24;

                if (0x1f < static_cast<uint32_t>(local_3c[0] - freePtr) - 4) {
                    // _invoke_watson — heap corruption
                    std::abort();
                }
            }

            CRTFree(reinterpret_cast<void*>(freePtr));
        }

        return result;
    }

    // Invalid state: error path → throws
    uint32_t errVal = StringAssignError1(static_cast<uint32_t>(cookie));
    errVal = StringAssignResize(errVal);
    errVal = StringAssignError2(errVal);
    StringAssignError3(errVal);

    // _CxxThrowException — unreachable but present in original
    CxxThrowException(nullptr, nullptr);
    return 0;  // unreachable
}

} // namespace Giants
