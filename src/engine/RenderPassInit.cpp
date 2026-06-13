// Giants Engine - Render Pass Init Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "RenderPassInit.h"
namespace Giants {
extern uint32_t DAT_00748770;  // Render pass flags
extern uint32_t DAT_00748778;  // Render pass config

// ─── RenderPassInit (FUN_004f9610) ── PASS ──
// 5 callers, 1 callee. Initializes render pass from bit flags.
void RenderPassInit(uint32_t param_1, uint32_t param_2)
{
    // FUN_004f9560(); — reset render state
    DAT_00748770 = param_1;

    uint32_t bit = 1;
    int passIndex = 0;
    do {
        if ((param_1 & bit) != 0) {
            switch (passIndex) {
                case 0: DAT_00748778 = 0x15; break;
                case 1: /* config for pass 1 */ break;
                case 2: /* config for pass 2 */ break;
                default: break;
            }
            passIndex++;
        }
        bit <<= 1;
    } while (bit != 0 && passIndex < 32);
}
} // namespace Giants
