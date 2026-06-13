// Giants Engine - State Switch Check Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "StateSwitchCheck.h"
#include <cstdint>
namespace Giants {
extern uint32_t DAT_00702bd0;  // Game state global
int StateSwitchCheck(uint32_t param_1)
{
    // Validate against global state
    if (DAT_00702bd0 == 0) return 0;

    switch (param_1) {
        case 0:  return 1;   // State active
        case 1:  return 2;   // State transitioning
        case 2:  return 4;   // State complete
        case 3:  return 8;   // State error
        default: return 0;   // Unknown state
    }
}
} // namespace Giants
