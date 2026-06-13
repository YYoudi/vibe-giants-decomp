// Giants Engine - String Tokenizer Init
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── StringTokenizerInit (FUN_00441270) ── PASS ──
// Initializes a string tokenizer/parser state from source string.
// Sets up delimiter tracking and position pointers. 7 callers, 0 callees.
void StringTokenizerInit(uint32_t* state, char* source, char* delimiters);  // FUN_00441270
} // namespace Giants
