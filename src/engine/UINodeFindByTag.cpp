// Giants Engine - UI Node Find By Tag Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "UINodeFindByTag.h"
#include <cstdint>
namespace Giants {
int UINodeFindByTag(int param_1, uint8_t* tagName, int* outIndex)
{
    int baseData = (param_1 != 0) ? *reinterpret_cast<int*>(param_1 + 0x14c) : 0;
    int* countPtr = reinterpret_cast<int*>(baseData + 0x49e0);
    int idx = 0;

    if (*countPtr > 0) {
        do {
            uint8_t* entryName = *reinterpret_cast<uint8_t**>(baseData + 0x1654);
            uint8_t* cmp1 = entryName;
            uint8_t* cmp2 = tagName;
            uint32_t cmpResult;

            do {
                uint8_t c1 = *cmp1;
                bool less = c1 < *cmp2;
                if (c1 != *cmp2) { cmpResult = less ? 0xFFFFFFFF : 1; break; }
                if (c1 == 0) { cmpResult = 0; break; }
                c1 = cmp1[1];
                less = c1 < cmp2[1];
                if (c1 != cmp2[1]) { cmpResult = less ? 0xFFFFFFFF : 1; break; }
                cmp1 += 2;
                cmp2 += 2;
            } while (true);

            if (cmpResult == 0) {
                *outIndex = idx;
                return baseData + 0x1650;
            }
            idx++;
            baseData += 0x108;
        } while (idx < *countPtr);
    }

    *outIndex = -1;
    return 0;
}
} // namespace Giants
