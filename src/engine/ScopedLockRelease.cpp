// Giants Engine - Scoped Lock Release Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "ScopedLockRelease.h"
#include <cstdint>
#include <cstdlib>

namespace Giants {

// ─── Shared globals ────────────────────────────────────────────
extern uint32_t DAT_0067d280;  // Security cookie — CRTStubs.cpp

// ─── External callees ──────────────────────────────────────────
extern int* BitvectorPushBack(int* bv, int bit);  // FUN_0043d690 — CRTStubs.h

// ═══════════════════════════════════════════════════════════════════
// ScopedLockRelease (FUN_0043c520) — 16 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Lock state layout (int* param_1):
//   [+0] = entry count / lock state
//   [+3] = bitvector data
//
// Cleanup: pushes bitvector entries for param_1[3] and 0xFFFFFFFF,
// then iterates remaining entries pushing them with value 0.

void ScopedLockRelease(int* lockState)
{
    uint32_t cookie = DAT_0067d280 ^ reinterpret_cast<uint32_t>(&lockState);

    int stateVal = lockState[0];

    // Release primary lock bitvector
    BitvectorPushBack(lockState + 3, lockState[3]);
    // Release sentinel
    BitvectorPushBack(lockState + 3, 0xFFFFFFFF);

    int count = 0;
    if (lockState[3] != 0) {
        BitvectorPushBack(lockState + 3, 0);
        // Iterate remaining entries
        for (int i = 0; i < lockState[3]; i++) {
            int* entry = reinterpret_cast<int*>(lockState[3]);
            if (entry != nullptr) {
                BitvectorPushBack(entry, 0);
                count++;
            }
        }
    }

    // Security cookie check
    if ((DAT_0067d280 ^ reinterpret_cast<uint32_t>(&lockState)) != cookie) {
        // __report_rangecheckfailure would be called here
        abort();
    }
}

} // namespace Giants
