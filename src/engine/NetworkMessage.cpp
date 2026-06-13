// Giants Engine - Network Message Dispatch Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "NetworkMessage.h"
#include <cstring>

namespace Giants {

// ─── Globals ───────────────────────────────────────────────────
extern int g_gameState;          // DAT_006ff960 (6 = in-game)
static int g_entryCount = 0;     // entry array size
static int g_targetEntry = 0;    // target entry to find
static int* g_entryArray = nullptr;  // entry lookup array

extern void LogChatMessage();    // FUN_00453520
extern void DispatchPacket();    // FUN_00463430

// ═══════════════════════════════════════════════════════════════════
// SendIndexedMessage (FUN_00463750) — 32 callers — FAIL (usable ~85%)
// ═══════════════════════════════════════════════════════════════════
// Builds a network message packet with header encoding:
//   byte 0: '0' (packet type marker)
//   byte 1: entryIndex | 0x80 (high bit set)
//   byte 2: param_3 | (param_2 & 0xFF) | 0x80
//   byte 3: 0
// Then appends the message string and dispatches.

void SendIndexedMessage(const char* message, uint32_t param_2, uint8_t param_3)
{
    if (g_gameState != 6) {
        LogChatMessage();
        return;
    }

    // Search for target entry in array
    int iVar1 = 0;
    if (0 < g_entryCount) {
        while (g_entryArray[iVar1] != g_targetEntry) {
            iVar1++;
            if (g_entryCount <= iVar1) {
                return;
            }
        }

        // Bounds check
        if ((-1 < iVar1) && (iVar1 <= g_entryCount - 1)) {
            // Build packet header on stack
            char packet[512];
            memset(packet, 0, 0x1FC);

            packet[0] = '0';                            // type marker
            packet[1] = static_cast<uint8_t>(iVar1) | 0x80;  // index | 0x80
            packet[2] = param_3 | static_cast<uint8_t>(param_2) | 0x80;  // flags
            packet[3] = 0;

            // Append message text
            strncat(packet, message, 0x1FB);

            // Dispatch the packet
            DispatchPacket();
        }
    }
}

} // namespace Giants
