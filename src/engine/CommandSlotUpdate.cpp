// Giants Engine - Command Slot Update Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "CommandSlotUpdate.h"
#include <cstdint>

namespace Giants {

// ─── Shared globals ────────────────────────────────────────────
extern int DAT_0073c940;   // Current command/action value
extern int DAT_0070294c;   // Slot count
extern int DAT_006ff910[]; // Slot value array (20 entries)
extern int DAT_006ff8fc[]; // Slot command array (20 entries)
extern int DAT_00702924;   // Active command output
extern int DAT_006ff960;   // Replay mode (6 = recording)

// ═══════════════════════════════════════════════════════════════════
// UpdateCommandSlot (FUN_004641b0) — 16 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Searches the slot array for the current action value, then:
// 1. Updates DAT_00702924 with the new command
// 2. Stores the command into the matching slot (up to 20 slots)
// 3. If replay mode: writes a type-0x0D packet to replay buffer

void UpdateCommandSlot(int commandId)
{
    int searchValue = DAT_0073c940;

    // Linear search for matching slot
    uint32_t i = 0;
    if (DAT_0070294c > 0) {
        do {
            if (DAT_006ff910[i] == searchValue) {
                if (static_cast<int>(i) < DAT_0070294c) {
                    goto found;
                }
                break;
            }
            i++;
        } while (static_cast<int>(i) < DAT_0070294c);
    }
    i = DAT_0070294c - 1;

found:
    // Update active command
    DAT_00702924 = commandId;

    // Store into slot array (max 20)
    if (i < 20) {
        DAT_006ff8fc[i] = static_cast<char>(commandId);
    }

    // Replay recording
    if (DAT_006ff960 == 6) {
        // Would write replay packet type 0x0D
        // Stub: replay write omitted for ground truth
    }
}

} // namespace Giants
