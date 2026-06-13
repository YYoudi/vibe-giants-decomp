// Giants Engine - String Compare Multi Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "StringCompareMulti.h"
#include <cstdint>
namespace Giants {
int StringCompareMulti(uint32_t* param_1, char* param_2, uint32_t param_3)
{
    char* src = reinterpret_cast<char*>(*param_1);
    char c1 = *src;
    uint32_t i = 0;

    do {
        if (param_3 == 0) return 0;  // Match up to length
        char c2 = param_2[i];
        if (c1 < c2) return -1;
        if (c1 > c2) return 1;
        if (c1 == '\0') return 0;
        i++;
        param_3--;
        c1 = src[i];
    } while (true);
}
} // namespace Giants
