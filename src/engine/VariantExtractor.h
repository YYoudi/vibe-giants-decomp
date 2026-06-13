// Giants Engine - Variant Type Extractor
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── ExtractVariantValue (FUN_004316b0) ── PASS ──
// Extracts a value from a variant/type-erased container based on type byte:
//   0x04 = bool, 0x05/0x06 = int/uint, 0x07 = float, 0x08 = double,
//   0x09 = string, 0x0A = pointer.
// Returns the extracted value as uint32_t.
// 15 callers, 6 callees.
uint32_t ExtractVariantValue(const char* variant);  // FUN_004316b0

} // namespace Giants
