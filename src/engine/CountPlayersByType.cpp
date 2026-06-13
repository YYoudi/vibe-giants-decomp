// Giants Engine - Count Players By Type Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "CountPlayersByType.h"
#include <cstdint>
namespace Giants {
extern char   DAT_00702bdd;   // Start index flag
extern int    DAT_0070294c;   // Player count
extern uint32_t DAT_006ff910[]; // Player active array
extern uint8_t DAT_006ff8e8[]; // Player type array

int CountPlayersByType(uint32_t playerType)
{
    int count = 0;
    uint32_t start = (DAT_00702bdd != '\0') ? 1u : 0u;

    for (uint32_t i = start; static_cast<int>(i) < DAT_0070294c; i++) {
        if ((static_cast<int>(i) >= 0) &&
            (DAT_006ff910[i] != 0) &&
            (DAT_006ff8e8[i] == static_cast<uint8_t>(playerType))) {
            count++;
        }
    }
    return count;
}
} // namespace Giants
