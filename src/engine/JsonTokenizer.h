// Giants Engine - JSON Tokenizer (two variants)
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── JsonNextToken (FUN_004350a0) ── PASS ──
// JSON parser tokenizer (variant 2). Struct offsets: +0x38/+0x3C/+0x74.
// Handles BOM check, comment skipping, and token classification.
// 21 callers, 5 callees.
void JsonNextToken(int* parser);  // FUN_004350a0

// ─── JsonNextTokenAlt (FUN_0060b140) ── PASS ──
// JSON parser tokenizer (variant 1). Struct offsets: +0x50/+0x54/+0x8c.
// Identical logic to JsonNextToken but with different struct layout.
// 21 callers, 6 callees.
void JsonNextTokenAlt(int* parser);  // FUN_0060b140

} // namespace Giants
