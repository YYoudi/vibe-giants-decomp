// Giants Engine - Entity Flag 0x1000000 Clear Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
// re-agent verdict: PASS
#include "EntityFlag24Clear.h"
namespace Giants {

extern uint32_t DAT_006ff960;  // Platform ID (6 = network)
extern int  FUN_0045f460();     // Network check
extern void FUN_00502a10();     // Mode reset dispatch
extern void FUN_00469d20(int a, int b); // Network message

void EntityFlag24Clear(int param_1)
{
    int iVar4 = 0;
    if (param_1 != 0)
        iVar4 = *reinterpret_cast<int*>(param_1 + 0x14c);

    if ((*reinterpret_cast<uint32_t*>(param_1 + 300) & 0x1000000) != 0)
    {
        if (iVar4 != 0)
        {
            int iVar1 = *reinterpret_cast<int*>(iVar4 + 0x1b4);
            if (iVar1 != 0)
            {
                *reinterpret_cast<uint32_t*>(iVar1 + 300) = 0;
                if (*reinterpret_cast<int*>(iVar4 + 0x178) == 0x13)
                {
                    FUN_00502a10();
                    *reinterpret_cast<uint32_t*>(iVar4 + 0xe8) = 0xffffffff;
                }
            }
        }

        *reinterpret_cast<uint32_t*>(param_1 + 300) &= 0xfeffffff;

        if (DAT_006ff960 == 6)
        {
            int checkResult = FUN_0045f460();
            if (checkResult != 0)
                FUN_00469d20(0x11, 0);
        }
    }
}

} // namespace Giants
