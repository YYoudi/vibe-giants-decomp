// Giants Engine - String Find Char Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "StringFindChar.h"
#include <cstdint>
namespace Giants {
char* StringFindChar(char* str, char ch)
{
    if (!str) return nullptr;
    while (*str != '\0') {
        if (*str == ch) return str;
        str++;
    }
    return nullptr;
}
} // namespace Giants
