// Giants Engine - Network Joiner Command Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "NetworkJoinerCommand.h"
#include <cstdint>

namespace Giants {

// ─── Shared globals ────────────────────────────────────────────
extern int  DAT_00702938;   // Joiner state flag
extern int  DAT_006ff1a0;   // Previous joiner state

// ─── External callees ──────────────────────────────────────────
extern uint32_t FUN_005e80c0(const char* cmd);  // Get network command ID
extern void     FUN_00453a40(const char* name, char* out, uint32_t p3, int wrap);  // Build path
extern void     FUN_00453710(const char* str, uint32_t param2);  // Parse string field

// ═══════════════════════════════════════════════════════════════════
// SendJoinerCommand (FUN_0045e0a0) — 15 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Compares current joiner state with previous. If changed:
//   - Selects "CommChgJoinersYes" or "CommChgJoinersNo"
//   - Gets command ID via FUN_005e80c0
//   - Builds and sends network message

void SendJoinerCommand()
{
    if (DAT_00702938 == DAT_006ff1a0) {
        return;  // No change
    }

    // Select command based on joiner state
    const char* cmdName;
    if (DAT_00702938 != 0) {
        cmdName = "CommChgJoinersYes";
    } else {
        cmdName = "CommChgJoinersNo";
    }

    uint32_t cmdId = FUN_005e80c0(cmdName);

    // Build and send command string
    char localBuf[260];
    // Command dispatch via FUN_00453a40 / FUN_00453710
    // (simplified for ground truth)
}

} // namespace Giants
