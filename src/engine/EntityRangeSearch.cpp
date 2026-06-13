// Giants Engine - Entity Range Search Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "EntityRangeSearch.h"
#include <cstdint>
namespace Giants {
extern float DAT_0066bf2c;  // 1.0f
extern float DAT_00702c20;  // Current time numerator
extern int   DAT_007028a4;  // Time denominator
extern float DAT_00702c1c;  // Range start
extern int   DAT_007028a0;  // Range denominator

int SearchEntityRange(uint32_t* listHead)
{
    uint32_t* node = *reinterpret_cast<uint32_t**>(listHead);  // First node
    float timeVal = DAT_0066bf2c - DAT_00702c20 / static_cast<float>(DAT_007028a4);

    while (true) {
        if (node == nullptr) {
            return 0;  // Not found
        }

        // Check visibility: node[2] != 0
        // Check active: node[1] != 0 OR (node[3] & 2)
        // Check time range: node[7] <= rangeStart AND rangeStart <= node[8]
        // Check position: node[6] <= timeVal AND timeVal <= node[9]
        bool visible = (node[2] != 0);
        bool active = (node[1] != 0) || ((*reinterpret_cast<uint8_t*>(node + 3) & 2) != 0);
        float rangeStart = DAT_00702c1c / static_cast<float>(DAT_007028a0);

        if (visible && active &&
            (reinterpret_cast<float*>(node)[7] <= rangeStart) &&
            (rangeStart <= reinterpret_cast<float*>(node)[8]) &&
            (reinterpret_cast<float*>(node)[6] <= timeVal) &&
            (timeVal <= reinterpret_cast<float*>(node)[9])) {
            return reinterpret_cast<int>(node);
        }

        node = *reinterpret_cast<uint32_t**>(node);  // Next node
    }
}
} // namespace Giants
