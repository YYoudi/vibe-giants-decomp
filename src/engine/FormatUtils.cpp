// Giants Engine - Format/String Utilities Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "FormatUtils.h"
#include <cstring>

namespace Giants {

// ─── Globals ───────────────────────────────────────────────────
extern uintptr_t g_securityCookie;  // DAT_0067d280

extern void FormatStringImpl(const char* fmt, int len);  // FUN_004cdfc0
extern void* AlignedNew(uint32_t size);                   // FUN_00443120

// ═══════════════════════════════════════════════════════════════════
// FormatUIntToBuffer (FUN_004ce120) — 44 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Formats unsigned int to string buffer. Uses fast-path for values
// under 100 (direct digit extraction), falls back to "{:02}" format
// string for larger values.
//
// param_2 layout (stream/buffer object):
//   +0  vtable/grow function pointer
//   +4  buffer base pointer
//   +8  current write position
//   +12 buffer capacity

void FormatUIntToBuffer(uint32_t param_1, uint32_t* param_2)
{
    uint32_t stackCookie = g_securityCookie ^ reinterpret_cast<uint32_t>(&param_1);
    uint32_t writePos = param_2[2];
    uint32_t value = param_1;

    if (param_1 < 100)
    {
        // Fast path: two-digit values (0-99)
        uint32_t tens = static_cast<uint32_t>(static_cast<int>(param_1) / 10);
        char digit1 = static_cast<char>(tens) + '0';

        // Grow buffer if needed
        if (param_2[3] < writePos + 1) {
            auto growFunc = reinterpret_cast<void(*)(uint32_t)>(*(uintptr_t*)param_2[0]);
            growFunc(writePos + 1);
        }

        *reinterpret_cast<char*>(writePos + param_2[1]) = digit1;
        param_2[2] = writePos + 1;

        // Compute ones digit
        char digit0 = static_cast<char>(value & 0xFF) + static_cast<char>(tens) * -10 + '0';
        value = (value & ~0xFF) | static_cast<uint8_t>(digit0);

        if (param_2[3] < param_2[2] + 1) {
            auto growFunc = reinterpret_cast<void(*)(uint32_t)>(*(uintptr_t*)param_2[0]);
            growFunc(param_2[2] + 1);
        }

        *reinterpret_cast<char*>(param_2[2] + param_2[1]) = static_cast<char>(value);
        param_2[2] = param_2[2] + 1;

        return;
    }

    // Slow path: 3+ digits, use format string
    FormatStringImpl("{:02}", 5);
}

} // namespace Giants
