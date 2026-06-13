// Giants Engine - Render Callback Dispatch Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "RenderCallbackDispatch.h"
#include <cstdint>
namespace Giants {
int RenderCallbackDispatch(int param_1, uint32_t param_2)
{
    // The function reads float parameters from registers (XMM0-XMM2)
    // and dispatches to a callback function pointer.
    // Simplified stub: original has complex float math for transform
    // before calling the callback.

    if (param_1 == 0) return 0;

    // Read callback from vtable
    int* vtable = *reinterpret_cast<int**>(param_1);
    auto callback = reinterpret_cast<int(*)(int, uint32_t)>(vtable[0]);

    return callback(param_1, param_2);
}
} // namespace Giants
