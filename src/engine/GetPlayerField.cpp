// Giants Engine - Get Player Field Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "GetPlayerField.h"
#include <cstdint>
#include <cstring>
namespace Giants {
extern int DAT_00701a3c;  // Game state pointer

uint32_t GetPlayerField(int param_1)
{
    if (param_1 < 0) return 0;

    // Read float from player data array at +0x458 indexed by param_1
    float value = *reinterpret_cast<float*>(DAT_00701a3c + 0x458 + param_1 * 4);
    uint32_t result;
    memcpy(&result, &value, sizeof(result));
    return result;
}
} // namespace Giants
