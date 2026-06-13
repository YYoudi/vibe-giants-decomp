// Giants Engine - String Search Compare Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "StringSearchCompare.h"
#include <cstdint>
namespace Giants {
int StringSearchCompare(char* haystack, char* needle)
{
    if (!haystack || !needle) return -1;
    if (*needle == '\0') return 0;

    char* hp = haystack;
    while (*hp != '\0') {
        char* h = hp;
        char* n = needle;
        while (*h != '\0' && *n != '\0' && *h == *n) {
            h++;
            n++;
        }
        if (*n == '\0') return static_cast<int>(hp - haystack);
        hp++;
    }
    return -1;
}
} // namespace Giants
