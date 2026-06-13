// Giants Engine - Entity Render Flags Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "EntityRenderFlags.h"
#include <cstdint>
namespace Giants {
uint32_t EntityRenderFlags(int entityPtr)
{
    uint32_t flags = *reinterpret_cast<uint32_t*>(entityPtr + 0x214);
    uint32_t result;

    if ((flags & 0x20000) == 0) {
        // Check visibility bit and entity type flags
        result = (flags >> 11) & 1;
        if ((*reinterpret_cast<uint32_t*>(entityPtr + 0x124) & 0x4000c000) != 0) {
            result = 1;
        }
        result = (-(uint32_t)(result != 0) & 0xFFFFFFF0) + 0x10;
    } else {
        result = 0x11;
    }

    // Dispatch on entity type for additional flag bits
    uint32_t entityType = *reinterpret_cast<uint32_t*>(entityPtr + 0x22c);
    switch (entityType) {
    case 6:
        result = result | 0x20;
        break;
    case 7:
        result = result | 1;
        break;
    case 8:
        result = result | 0x100;
        break;
    case 0x12:
        result = 0x811;
        break;
    case 0x15:
        result = result | 0x200;
        break;
    default:
        break;
    }

    return result;
}
} // namespace Giants
