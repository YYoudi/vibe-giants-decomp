// Giants Engine - Count Active Lanes Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "CountActiveLanes.h"
#include <cstdint>
namespace Giants {
extern uint32_t DAT_0066c5b0;
extern uint32_t DAT_0066c360;
extern uint8_t DAT_00702bdd;
extern uint32_t DAT_006ff960;
extern uint32_t DAT_00702964;

int CountActiveLanes()
{
    int sums[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    int offset = 0;
    int idx = 0;

    do {
        int* p0 = reinterpret_cast<int*>(0x6ff910 + offset);
        int* p1 = reinterpret_cast<int*>(0x6ff914 + offset);
        int* p2 = reinterpret_cast<int*>(0x6ff918 + offset);
        int* p3 = reinterpret_cast<int*>(0x6ff91c + offset);
        offset += 0x20;

        sums[0] += (*p0 != 0) ? DAT_0066c5b0 & DAT_0066c360 : 0;
        sums[1] += (*p1 != 0) ? DAT_0066c5b0 & DAT_0066c360 : 0;  // simplified
        sums[2] += (*p2 != 0) ? DAT_0066c5b0 & DAT_0066c360 : 0;
        sums[3] += (*p3 != 0) ? DAT_0066c5b0 & DAT_0066c360 : 0;

        int off2 = idx * 4;
        idx += 8;

        sums[4] += (*reinterpret_cast<int*>(0x6ff920 + off2) != 0) ? DAT_0066c5b0 & DAT_0066c360 : 0;
        sums[5] += (*reinterpret_cast<int*>(off2 + 0x6ff924) != 0) ? DAT_0066c5b0 & DAT_0066c360 : 0;
        sums[6] += (*reinterpret_cast<int*>(off2 + 0x6ff928) != 0) ? DAT_0066c5b0 & DAT_0066c360 : 0;
        sums[7] += (*reinterpret_cast<int*>(off2 + 0x6ff92c) != 0) ? DAT_0066c5b0 & DAT_0066c360 : 0;
    } while (idx < 0x10);

    int total = sums[0] + sums[1] + sums[2] + sums[3] + sums[4] + sums[5] + sums[6] + sums[7];

    // Extra slot check
    if (idx < 0x14) {
        int* extra = reinterpret_cast<int*>(0x6ff910 + idx);
        while (reinterpret_cast<int>(extra) < 0x6ff960) {
            if (*extra != 0) total++;
            extra++;
        }
    }

    // Conditional adjustment
    if (DAT_00702bdd != '\0' && DAT_006ff960 == 6 && DAT_00702964 != 0) {
        return total - 1;
    }
    return total;
}
} // namespace Giants
