// Giants Engine - UTF-8 Stream Decoder Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "Utf8Decoder.h"
#include <cstdint>

namespace Giants {

// ═══════════════════════════════════════════════════════════════════
// Utf8ReadNext (FUN_00614e20) — 16 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Stream state layout (int* param_1):
//   [+0] = current read pointer (byte*)
//   [+1] = end pointer
//   [+2..+5] = decoded codepoint buffer
//   [+6] = read index into buffer
//   [+7] = end-of-stream flag (0=active, 1=eof)

int Utf8ReadNext(int* state)
{
    int readIdx = state[6];
    int endIdx = state[7];

    // Fast path: return buffered codepoint
    if (readIdx != endIdx) {
        state[6] = readIdx + 1;
        return state[readIdx + 2];
    }

    // Reset buffer
    state[6] = 0;

    auto* ptr = reinterpret_cast<uint16_t*>(state[0]);
    auto* end = reinterpret_cast<uint16_t*>(state[1]);

    // End of stream
    if (ptr == end) {
        state[2] = -1;
        state[7] = 1;
        int idx = state[6];
        state[6] = idx + 1;
        return state[idx + 2];
    }

    // Read first byte
    uint16_t byte1 = *ptr++;
    state[0] = reinterpret_cast<int>(ptr);

    // 1-byte sequence (0x00-0x7F)
    if (byte1 <= 0x7F) {
        state[2] = byte1;
    }
    // 2-byte sequence (0x80-0x7FF)
    else if (byte1 < 0x800) {
        state[2] = (byte1 >> 6) | 0xC0;   // high bits | marker
        state[3] = (byte1 & 0x3F) | 0x80; // low 6 bits | continuation
        state[7] = 2;  // 2 codepoints in buffer
    }
    // 3-byte sequence (0x800-0xFFFF)
    else if (byte1 < 0xD800 || byte1 >= 0xE000) {
        state[2] = (byte1 >> 12) | 0xE0;
        state[3] = ((byte1 >> 6) & 0x3F) | 0x80;
        state[4] = (byte1 & 0x3F) | 0x80;
        state[7] = 3;
    }
    // Surrogate pair (0xD800-0xDFFF) → 4-byte encoding
    else {
        uint16_t byte2 = *ptr++;
        state[0] = reinterpret_cast<int>(ptr);
        uint32_t codepoint = 0x10000 +
            ((static_cast<uint32_t>(byte1) & 0x3FF) << 10) +
            (static_cast<uint32_t>(byte2) & 0x3FF);

        state[2] = (codepoint >> 18) | 0xF0;
        state[3] = ((codepoint >> 12) & 0x3F) | 0x80;
        state[4] = ((codepoint >> 6) & 0x3F) | 0x80;
        state[5] = (codepoint & 0x3F) | 0x80;
        state[7] = 4;
    }

    int idx = state[6];
    state[6] = idx + 1;
    return state[idx + 2];
}

} // namespace Giants
