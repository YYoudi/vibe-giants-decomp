// Giants Engine - Set Sprite Attribute Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
// re-agent verdict: PASS
#include "SetSpriteAttribute.h"
#include <cstring>

namespace Giants {

extern int FUN_00451620();  // GetSpriteTableManager

void SetSpriteAttribute(uint32_t* spriteIdPtr, uint32_t value, int attributeIndex)
{
    uint32_t spriteId = *spriteIdPtr;
    uint32_t tableIndex = (spriteId >> 13) & 0x7f;

    int tableMgr = FUN_00451620();

    int* tablesBegin = *reinterpret_cast<int**>(tableMgr + 4);
    int* tablesEnd = *reinterpret_cast<int**>(tableMgr + 8);
    uint32_t tableCount = (reinterpret_cast<uint32_t>(tablesEnd) - reinterpret_cast<uint32_t>(tablesBegin)) >> 2;

    if (tableIndex < tableCount)
    {
        int tablePtr = *reinterpret_cast<int*>(reinterpret_cast<uint32_t>(tablesBegin) + tableIndex * 4);
        if (tablePtr != 0)
        {
            uint32_t localIndex = spriteId & 0x1fff;
            uint32_t entryValue = *reinterpret_cast<uint32_t*>(tablePtr + localIndex * 4) & 0xfffff;
            if (entryValue != 0xfffff)
            {
                spriteId = *spriteIdPtr;
                int tableMgr2 = FUN_00451620();

                int tablesBegin2 = *reinterpret_cast<int*>(tableMgr2 + 4);
                int tablePtr2 = *reinterpret_cast<int*>(tablesBegin2 + ((spriteId >> 13) & 0x7f) * 4);
                int entryOffset = *reinterpret_cast<int*>(tablePtr2 + (spriteId & 0x1fff) * 4);
                int dataBuffer = *reinterpret_cast<int*>(tableMgr2 + 0x1c);
                int dataEntry = *reinterpret_cast<int*>(entryOffset * 0x20 + dataBuffer);

                *reinterpret_cast<uint32_t*>(dataEntry + attributeIndex * 8) = value;
            }
        }
    }
}

} // namespace Giants
