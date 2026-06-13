// Giants Engine - Replay Sync Marker Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "ReplaySyncMarker.h"
#include <cstdint>
namespace Giants {
extern int DAT_006ff960;       // Game mode (6 = replay)
extern int DAT_0073c940;       // Replay buffer state
extern int DAT_00702964;       // Network active flag
extern void FUN_0045fe10(void*); // Replay write function

void WriteReplaySyncMarker()
{
    uint8_t local_8;
    uint32_t local_7;
    uint8_t local_2 = 0;

    if (DAT_006ff960 == 6) {
        local_8 = 0x3B;  // Sync marker packet type
        local_7 = DAT_0073c940;
        if (DAT_00702964 != 0) {
            FUN_0045fe10(&local_8);
            return;
        }
    }
}
} // namespace Giants
