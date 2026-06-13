// Giants Engine - Entity State Clear Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
// re-agent verdict: FAIL (usable ~80%)
#include "EntityStateClear.h"
namespace Giants {

extern uint32_t DAT_006ff960;  // Platform ID (6 = network)
extern int  FUN_0045f460();     // Network check
extern void FUN_00502c30();     // Network mode dispatch
extern void FUN_00469d20(int a, int b); // Network message

void EntityStateClear(int* entity)
{
    if (entity == nullptr) return;

    int* controller = *reinterpret_cast<int**>(reinterpret_cast<uintptr_t>(entity) + 0x14c);
    uint32_t& statusFlags = *reinterpret_cast<uint32_t*>(reinterpret_cast<uintptr_t>(entity) + 300);

    if ((statusFlags & 0x800000) != 0)
    {
        if (DAT_006ff960 == 6)
        {
            int checkResult = FUN_0045f460();
            if (checkResult == 0)
            {
                int modeId = *reinterpret_cast<int*>(reinterpret_cast<uintptr_t>(controller) + 0x178);
                if (modeId != 0x11)
                    FUN_00502c30();
            }
        }

        // Reset controller state fields
        *reinterpret_cast<uint32_t*>(reinterpret_cast<uintptr_t>(controller) + 0x1e0) = 0;
        statusFlags &= ~0x800000u;

        if (DAT_006ff960 == 6)
        {
            int checkResult = FUN_0045f460();
            if (checkResult != 0)
                FUN_00469d20(0xf, 0);
        }
    }
}

} // namespace Giants
