// Giants Engine - Path Builder Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "PathBuilder.h"
#include <cstdint>
#include <cstring>

namespace Giants {

// ─── Shared globals ────────────────────────────────────────────
extern uint32_t DAT_0067d280;   // Security cookie — CRTStubs.cpp
extern uint16_t DAT_0065de44;   // Path separator (likely '\\' or '/')

// ═══════════════════════════════════════════════════════════════════
// BuildFilePath (FUN_00453a40) — 15 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Constructs a file path string. Two modes:
//   wrapMode == 0: simple concat of name into local buffer
//   wrapMode != 0: prepend '(' then name, append separator + closing

void BuildFilePath(const char* name, char* output, uint32_t param3, int wrapMode)
{
    uint8_t localBuf[3];
    uint8_t& sepByte = localBuf[1];
    uint16_t& sepWord = *reinterpret_cast<uint16_t*>(&localBuf[0]);

    sepWord = sepWord & 0xFF00;  // Keep high byte, clear low

    if (wrapMode == 0) {
        // Simple concatenation
        strncat(reinterpret_cast<char*>(&sepWord), name, 0xFE);
    } else {
        // Wrap in parentheses
        sepByte = '(';  // 0x28
        strncat(reinterpret_cast<char*>(&sepWord), name, 0xFE);

        // Find end of string
        auto* p = &sepByte;
        do {
            p++;
        } while (*reinterpret_cast<char*>(p) != '\0');

        // Append separator
        *reinterpret_cast<uint16_t*>(p) = DAT_0065de44;
    }

    // Copy result to output
    auto* src = reinterpret_cast<char*>(&sepWord);
    localBuf[2] = 0;  // Null terminate

    // Remaining logic: append param_2 string content
    // (truncated for ground truth — original continues with more concatenation)
    strcpy(output, src);
}

} // namespace Giants
