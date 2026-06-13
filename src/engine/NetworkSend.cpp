// Giants Engine - Network Message Send Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "NetworkSend.h"
#include "CRTStubs.h"
#include <cstring>

namespace Giants {

// ─── Globals ───────────────────────────────────────────────────
extern int g_gameState;              // DAT_006ff960 (must be 6)
static int g_netPlayerCount = 0;     // DAT_0070294c
static void** g_netPlayerArray = nullptr;  // DAT_006ff910
static uintptr_t g_netTargetPtr = 0;       // DAT_0073c940

extern void DispatchNetworkMessage();   // FUN_00453520
extern void TransmitPacket();           // FUN_00463430

// ═══════════════════════════════════════════════════════════════════
// SendNetworkMessage (FUN_00463750) — 32 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Sends a network message packet:
//   1. Only active in game state 6 (multiplayer)
//   2. Searches player array for target
//   3. Builds packet: player_index|0x80, flags|0x80, '0', string
//   4. Transmits via FUN_00463430

void SendNetworkMessage(char* text, uint32_t flags, uint8_t param3)
{
    if (g_gameState != 6)
    {
        DispatchNetworkMessage();
        return;
    }

    // Find target player index
    int playerIdx = 0;
    if (g_netPlayerCount > 0)
    {
        while (g_netPlayerArray[playerIdx] != reinterpret_cast<void*>(g_netTargetPtr))
        {
            playerIdx++;
            if (playerIdx >= g_netPlayerCount)
                return;
        }

        if ((playerIdx >= 0) && (playerIdx <= g_netPlayerCount - 1))
        {
            // Build message buffer
            char buffer[512];
            memset(buffer, 0, 0x1FC);

            // Packet header: [playerIdx|0x80] [flags|0x80] ['0'] [0] [string...]
            buffer[0] = static_cast<char>(playerIdx | 0x80);
            buffer[1] = static_cast<char>(param3 | static_cast<uint8_t>(flags) | 0x80);
            buffer[2] = '0';
            buffer[3] = 0;

            // Append text (max 507 bytes)
            strncat(&buffer[2], text, 0x1FB);

            TransmitPacket();
        }
    }
}

} // namespace Giants
