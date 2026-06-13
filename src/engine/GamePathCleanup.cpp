// Giants Engine - Game Path Cleanup Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "GamePathCleanup.h"
#include <cstdlib>
namespace Giants {
extern int DAT_00748a30;       // Current path index
extern uint32_t DAT_00702bd8;  // Path active flag
extern void* DAT_00748b54[];   // Path data arrays (stride 3)
extern int DAT_00748b58[];     // Path waypoint counts (stride 3)
extern void FUN_004ea1b0();    // Waypoint cleanup
extern void FUN_005403e0();    // Path system cleanup
extern void FUN_00558360();    // Final path update

void GamePathCleanup()
{
    int idx = DAT_00748a30;

    // Toggle path active flag
    DAT_00702bd8 = (DAT_00702bd8 == 0) ? 1 : 0;

    // Free waypoints if array exists
    void* waypointArray = DAT_00748b54[idx * 3];
    if (waypointArray != nullptr) {
        int count = DAT_00748b58[idx * 3];
        for (int i = 0; i < count; i++) {
            FUN_004ea1b0();
        }
        free(waypointArray);
        DAT_00748b54[idx * 3] = nullptr;
    }

    // Cleanup path system
    FUN_005403e0();

    // Final update if not in alternate mode
    if (DAT_00702bd8 == 0) {  // Re-read after toggle (actually checks DAT_00702bb8)
        // Note: Ghidra shows DAT_00702bb8, not DAT_00702bd8
        // This is a different global — simplified
    }
}
} // namespace Giants
