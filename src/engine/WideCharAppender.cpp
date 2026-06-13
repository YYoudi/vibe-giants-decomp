// Giants Engine - Wide Char Appender Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "WideCharAppender.h"
#include <cstdint>
namespace Giants {
uint32_t* WideCharAppender(uint32_t* out, char* begin, char* end, uint32_t* bufState)
{
    while (begin != end) {
        char ch = *begin;
        begin++;

        // Check capacity: if bufState[3] (capacity) < bufState[2] (size) + 1
        if (bufState[3] < bufState[2] + 1) {
            // Grow via vtable callback
            auto grow = reinterpret_cast<void(*)(uint32_t)>(reinterpret_cast<uint32_t*>(bufState[0])[0]);
            grow(bufState[2] + 1);
        }

        // Write char as wide char (2 bytes)
        *reinterpret_cast<uint16_t*>(bufState[1] + bufState[2] * 2) = static_cast<uint16_t>(ch);
        bufState[2]++;
    }

    *out = reinterpret_cast<uint32_t>(bufState);
    return out;
}
} // namespace Giants
