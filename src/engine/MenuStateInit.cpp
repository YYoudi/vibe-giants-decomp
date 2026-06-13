// Giants Engine - Menu/UI State Initializer Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
// re-agent verdict: PASS
#include "MenuStateInit.h"
#include <cstring>

namespace Giants {

// ─── Global state variables ────────────────────────────────────
extern uint32_t g_initialized;          // DAT_0074892c
extern uint32_t g_stateA;               // DAT_00748a40
extern uint32_t g_stateB;               // DAT_00748a30
extern uint32_t g_flagB48;              // DAT_00748b48
extern uint32_t g_stateD;               // DAT_00702d58
extern void*    g_callbackTable;        // DAT_00702d50
extern uint32_t g_stateE;               // DAT_00702d54
extern uint8_t  g_buffer[0x4b0];        // DAT_00748b50
extern uint32_t g_conditionFlag;        // DAT_00747d3c
extern uint32_t g_param2;               // DAT_0068298c
extern uint32_t g_resultFlag;           // DAT_00748b44
extern uint32_t g_param1;               // DAT_00682e98

// ─── External callees ──────────────────────────────────────────
extern void FUN_004e96b0();  // Menu callback dispatcher

void InitMenuState(uint32_t param1, uint32_t param2)
{
    g_initialized = 1;
    g_stateA = 0;
    g_stateB = 0;
    g_flagB48 = 0;
    g_stateD = 0;
    g_callbackTable = reinterpret_cast<void*>(0x005411e0);
    g_stateE = 0;
    memset(&g_buffer, 0, 0x4b0);

    if (g_conditionFlag == 0)
    {
        FUN_004e96b0();
        g_param2 = param2;
        g_resultFlag = 1;
        g_param1 = param1;
        return;
    }

    g_param1 = param1;
    g_param2 = param2;
    g_resultFlag = 0;
}

} // namespace Giants
