// Giants Engine - DWord Vector Push Back Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "DwordPushBack.h"
#include <cstdint>

namespace Giants {

// ─── Forward declarations ──────────────────────────────────────
extern void FUN_0042c4e0(uint32_t* endPtr, uint32_t* value);  // Vector grow + insert

// ═══════════════════════════════════════════════════════════════════
// PushDwordBack (FUN_004cfbe0) — 22 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// std::vector<uint32_t>::push_back equivalent.
// Container is a typical MSVC std::vector layout:
//   +0: _Myfirst (begin pointer)
//   +4: _Mylast  (end pointer)
//   +8: _Myend   (capacity pointer)
// If space available: store value directly and advance end ptr.
// If full: delegate to FUN_0042c4e0 for reallocation + insert.

void PushDwordBack(int container, uint32_t* value)
{
    uint32_t* endPtr = *reinterpret_cast<uint32_t**>(container + 4);
    uint32_t* capPtr = *reinterpret_cast<uint32_t**>(container + 8);

    if (endPtr != capPtr) {
        // Space available — store and advance
        uint32_t val = *value;
        *value = 0;  // MSVC move semantics: null out source
        *endPtr = val;
        *reinterpret_cast<int*>(container + 4) += 4;  // advance end ptr
        return;
    }

    // Need to grow — delegate to realloc helper
    FUN_0042c4e0(endPtr, value);
}

} // namespace Giants
