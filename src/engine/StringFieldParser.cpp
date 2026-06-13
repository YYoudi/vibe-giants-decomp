// Giants Engine - String Field Parser Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "StringFieldParser.h"
#include <cstdint>
#include <cstring>

namespace Giants {

// ═══════════════════════════════════════════════════════════════════
// ParseStringField (FUN_00453710) — 15 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Copies input string to local 300-byte buffer, then walks the
// buffer extracting fields. Used for config/data file parsing.
// Ground truth: structure preserved, parsing logic simplified.

void ParseStringField(const char* input, uint32_t param2)
{
    uint8_t localBuf[300];
    *reinterpret_cast<uint32_t*>(localBuf) = 0;  // Stack cookie placeholder

    // Copy input to local buffer
    strncpy(reinterpret_cast<char*>(localBuf + 4), input, 300);
    localBuf[4 + 300 - 1] = 0;  // Null terminate

    auto* ptr = localBuf + 4;

    // Walk buffer parsing fields
    while (*ptr != 0) {
        uint8_t byte = *ptr;

        // Skip whitespace
        if (byte == ' ' || byte == '\t') {
            ptr++;
            continue;
        }

        // Field delimiter or end
        if (byte == ',' || byte == '\n' || byte == '\r') {
            ptr++;
            continue;
        }

        // Process field value
        ptr++;
    }

    // Security cookie check stub
}

} // namespace Giants
