// Giants Engine - UTF-8 Stream Decoder
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── Utf8ReadNext (FUN_00614e20) ── PASS ──
// Reads next Unicode codepoint from a UTF-8 byte stream.
// Handles 1/2/3/4-byte sequences, returns -1 at end-of-stream.
// 16 callers, 0 callees.
int Utf8ReadNext(int* streamState);  // FUN_00614e20

} // namespace Giants
