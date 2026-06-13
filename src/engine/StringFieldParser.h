// Giants Engine - String Field Parser
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── ParseStringField (FUN_00453710) ── PASS ──
// Parses a string field: copies param_1 into local buffer (300 chars),
// then processes byte stream with field extraction.
// 15 callers, 5 callees.
void ParseStringField(const char* input, uint32_t param2);  // FUN_00453710

} // namespace Giants
