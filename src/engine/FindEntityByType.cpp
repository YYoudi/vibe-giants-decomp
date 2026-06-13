// Giants Engine - Find Entity By Type Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "FindEntityByType.h"
#include <cstdint>
namespace Giants {
extern uint32_t* DAT_007027b0;  // Entity linked list head

int FindEntityByType(int matchValue)
{
    uint32_t* node = DAT_007027b0;
    while (true) {
        if (node == nullptr) return 0;

        int entityData = reinterpret_cast<int*>(node)[3];  // +0xC
        uint32_t flags = *reinterpret_cast<uint32_t*>(entityData + 0x124);
        int type = *reinterpret_cast<int*>(entityData + 4);
        int field = *reinterpret_cast<int*>(entityData + 0x264);

        if (((flags & 0x8000) == 0) && (type == 0x3DF) && (field == matchValue)) {
            return reinterpret_cast<int>(node);
        }
        node = *reinterpret_cast<uint32_t**>(node);  // Next
    }
}
} // namespace Giants
