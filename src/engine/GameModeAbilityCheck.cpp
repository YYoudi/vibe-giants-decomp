// Giants Engine - Game Mode Ability Check Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "GameModeAbilityCheck.h"
#include <cstdint>
namespace Giants {
extern int DAT_00702774;  // Current entity/player
extern uint8_t DAT_00745118[];  // Ability level table

// External ability checks
extern int FUN_004ae0c0();  // Low-level ability check
extern int FUN_004adfe0();  // Mid-level ability check
extern int FUN_004ade20();  // High-level ability check

bool GameModeAbilityCheck(uint32_t param_1, int param_2)
{
    // Determine offset based on entity type at +0x22C
    int offset = 0x84;  // Default offset
    if (DAT_00702774 != 0) {
        int entityType = *reinterpret_cast<int*>(DAT_00702774 + 0x22C);
        if (entityType == 3) {
            offset = 0;
        } else if (entityType == 2) {
            offset = 0x2C;
        } else if (entityType == 1) {
            offset = 0x58;
        }
        // else offset stays 0x84
    }

    // Look up ability level from table
    uint8_t level = DAT_00745118[(offset + param_2) * 2];

    int result;
    if (level < 0x65) {
        // Level < 101: low-level ability
        result = FUN_004ae0c0();
    } else if (level > 0x6E) {
        // Level > 110: high-level ability
        result = FUN_004ade20();
        return result != 0;
    } else {
        // Level 101-110: mid-level ability
        result = FUN_004adfe0();
    }

    return result != 0;
}
} // namespace Giants
