// Giants Engine - Dialog Stack Pop Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "DialogStackPop.h"
#include <cstdint>
namespace Giants {
extern int    DAT_00682204;    // Dialog stack depth counter
extern uint32_t DAT_00747b74;  // Dialog stack base array
extern void   FUN_0062edc0(const char*);  // Error message function

void PopDialogStack(int dialogPtr)
{
    // Validate stack underflow
    if (DAT_00682204 < 0) {
        FUN_0062edc0("Underflow of dialog level stack");
        DAT_00682204 = 0;
    } else if (*reinterpret_cast<int*>(&DAT_00747b74 + DAT_00682204 * 6) != dialogPtr) {
        FUN_0062edc0("Pop mismatch");
        return;
    }

    // Clear stack entry
    if (*reinterpret_cast<uint32_t*>(&DAT_00747b74 + DAT_00682204 * 6) != 0) {
        // Clean up dialog at current stack level
        *reinterpret_cast<uint32_t*>(&DAT_00747b74 + DAT_00682204 * 6) = 0;
    }

    DAT_00682204--;
}
} // namespace Giants
