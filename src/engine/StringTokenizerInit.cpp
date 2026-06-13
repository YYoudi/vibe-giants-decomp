// Giants Engine - String Tokenizer Init Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "StringTokenizerInit.h"
#include <cstdint>
#include <cstring>
namespace Giants {
void StringTokenizerInit(uint32_t* state, char* source, char* delimiters)
{
    // Store source pointer
    state[0] = reinterpret_cast<uint32_t>(source);

    // Store delimiters pointer
    state[1] = reinterpret_cast<uint32_t>(delimiters);

    // Initialize position to start of source
    state[2] = 0;  // current offset

    // Initialize token state
    state[3] = 0;  // token length
    state[4] = 0;  // flags (0 = not started)
}
} // namespace Giants
