// Giants Engine - Replay Packet Write B Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "ReplayPacketWriteB.h"
#include <cstdint>
#include <cstring>
namespace Giants {
extern int    DAT_006ff960;       // Game mode (6 = replay recording)
extern int*   DAT_0073d750;       // Replay write buffer pointer
extern void   FUN_0046ccf0();     // Buffer overflow handler

void ReplayPacketWriteB(int entity, size_t payloadSize, uint8_t flag, void* payload)
{
    if (DAT_006ff960 != 6) return;  // Only in replay mode

    // Buffer bounds check
    if (reinterpret_cast<int>(DAT_0073d750) + static_cast<int>(payloadSize) -
        0x73D748 > 0x3FF) {
        FUN_0046ccf0();  // Flush/overflow handler
    }

    // Write packet header
    *reinterpret_cast<uint8_t*>(DAT_0073d750) = 8;  // Packet type
    DAT_0073d750 = reinterpret_cast<int*>(reinterpret_cast<int>(DAT_0073d750) + 1);
    *DAT_0073d750 = payloadSize + 0xB;  // Total packet size
    DAT_0073d750 = DAT_0073d750 + 1;
    *DAT_0073d750 = *reinterpret_cast<int*>(entity + 0x1D4);  // Entity ID
    DAT_0073d750 = DAT_0073d750 + 1;
    *reinterpret_cast<uint8_t*>(DAT_0073d750) = flag;
    DAT_0073d750 = reinterpret_cast<int*>(reinterpret_cast<int>(DAT_0073d750) + 1);
    *reinterpret_cast<uint8_t*>(DAT_0073d750) = *reinterpret_cast<uint8_t*>(entity + 0x22C);
    DAT_0073d750 = reinterpret_cast<int*>(reinterpret_cast<int>(DAT_0073d750) + 1);

    // Write payload
    memcpy(DAT_0073d750, payload, payloadSize);
    DAT_0073d750 = reinterpret_cast<int*>(reinterpret_cast<int>(DAT_0073d750) + payloadSize);
}
} // namespace Giants
