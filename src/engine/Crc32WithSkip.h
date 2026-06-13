// Giants Engine - CRC32 with Skip Pattern
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── Crc32WithSkip (FUN_00472510) ── PASS ──
// Computes CRC32 of byte buffer with "###" skip pattern. When three
// consecutive 0x23 bytes are found, CRC is reset to initial value.
// Uses lookup table at DAT_00658738. param_3 = initial CRC (inverted).
// 9 callers, 0 callees (self-contained).
uint32_t Crc32WithSkip(uint8_t* data, uint32_t length, uint32_t initCrc);  // FUN_00472510
} // namespace Giants
