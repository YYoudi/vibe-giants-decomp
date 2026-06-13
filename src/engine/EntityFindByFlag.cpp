// Giants Engine - Entity Find By Flag Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "EntityFindByFlag.h"
#include <cstdint>
namespace Giants {
extern uint32_t DAT_007027a8;  // Entity linked list head

int EntityFindByFlag(uint32_t entityType)
{
    uint32_t* node = reinterpret_cast<uint32_t*>(DAT_007027a8);
    while (true) {
        if (node == nullptr) return 0;
        int entityData = node[3];  // +0xC = entity data pointer
        if (entityData != 0 &&
            (*reinterpret_cast<uint8_t*>(entityData + 0x214) & 1) != 0 &&
            *reinterpret_cast<uint8_t*>(entityData + 0x1d4) == entityType) {
            return entityData;
        }
        node = reinterpret_cast<uint32_t*>(*node);  // next in linked list
    }
}
} // namespace Giants
