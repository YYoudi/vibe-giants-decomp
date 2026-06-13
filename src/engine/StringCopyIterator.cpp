// Giants Engine - String Copy Iterator Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "StringCopyIterator.h"
#include <cstdint>
namespace Giants {
char* StringCopyIterator(char* dest, const char* src)
{
    if (!dest || !src) return dest;
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return dest;  // pointer past null terminator
}
} // namespace Giants
