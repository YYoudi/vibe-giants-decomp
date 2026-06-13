// Giants Engine - Network State Reset Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "ResetNetworkState.h"
#include <cstdint>
#include <cstring>
namespace Giants {
extern int DAT_00701a3c;  // Network context pointer
void ResetNetworkState()
{
    int ctx = DAT_00701a3c;
    int* counter = reinterpret_cast<int*>(ctx + 0x1AA4);
    *reinterpret_cast<bool*>(ctx + 0x1AB0) = (*counter != 0);
    if (*counter != 0) {
        *reinterpret_cast<uint32_t*>(ctx + 0x1AAC) = 0;
        *reinterpret_cast<uint16_t*>(ctx + 0x1AB3) = 0;
    }
    *reinterpret_cast<uint32_t*>(ctx + 0x1AA4) = 0;
    *reinterpret_cast<uint16_t*>(ctx + 0x1AB1) = 0;
    *reinterpret_cast<uint32_t*>(ctx + 0x1AD0) = 0;
    *reinterpret_cast<uint16_t*>(ctx + 0x1AB5) = 0;
    *reinterpret_cast<uint32_t*>(ctx + 0x1AB8) = 0;
    *reinterpret_cast<uint32_t*>(ctx + 0x1ABC) = 0;
    *reinterpret_cast<uint32_t*>(ctx + 0x1AC0) = 0;
    *reinterpret_cast<uint32_t*>(ctx + 0x1AC4) = 0;
}
} // namespace Giants
