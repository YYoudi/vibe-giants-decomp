// Giants Engine - Entity Select Update Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "EntitySelectUpdate.h"
#include <cstdint>
namespace Giants {
extern int DAT_00701a3c;  // Game state pointer

void EntitySelectUpdate(int entity)
{
    int gameState = DAT_00701a3c;

    // Check if selection actually changed
    if (*reinterpret_cast<int*>(gameState + 0x1BC4) == entity) return;

    *reinterpret_cast<int*>(gameState + 0x1BC4) = entity;

    if ((entity == 0) || (*reinterpret_cast<char*>(gameState + 0x1C17) == '\0')) {
        *reinterpret_cast<uint8_t*>(gameState + 0x1C19) = 0;
        if (entity == 0) {
            // Deselected: clear UI fields
            *reinterpret_cast<uint32_t*>(gameState + 0x1BC8) = 0;
            return;
        }
        // Get entity data pointer
        uint32_t entityData = *reinterpret_cast<uint32_t*>(entity + 0x32C);
        *reinterpret_cast<uint32_t*>(gameState + 0x1BC8) = entityData;
    }
}
} // namespace Giants
