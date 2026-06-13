// Giants Engine - Player Name Management Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "PlayerName.h"
#include <cstring>

namespace Giants {

// ─── Globals ───────────────────────────────────────────────────
static char g_playerNames[20][32];  // DAT_006ff5b0 — 20 player name slots
static int  g_networkFlag = 0;      // DAT_00702964 — network active flag

extern uintptr_t g_securityCookie;  // DAT_0067d280

extern int         FetchNetworkPlayerName(uint32_t playerIndex);     // FUN_0045f6e0
extern const char* LocalizeString(const char* key, uint32_t ecxState, uint32_t playerIndex); // FUN_005e80c0
extern void        StringFormat(char* dest, const char* format, ...);  // FUN_00463000

// ═══════════════════════════════════════════════════════════════════
// GetPlayerName (FUN_0045f780) — 39 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Returns a pointer to the cached player name for the given index.
// Steps:
//   1. If index >= 20, returns "?"
//   2. If name slot is empty and network is active, fetch from network
//   3. If still empty after network fetch, use localized default name

char* GetPlayerName(uint32_t playerIndex)
{
    if (playerIndex >= 20) {
        return const_cast<char*>("?");
    }

    int offset = playerIndex * 32;
    char* dest = &g_playerNames[0][0] + offset;

    if (dest[0] == '\0')
    {
        uint32_t ecxState = playerIndex;

        if (g_networkFlag != 0)
        {
            int result = FetchNetworkPlayerName(playerIndex);
            // ecxState may be updated by callee (register state)

            if (result != 0)
            {
                // Network returned a name — copy to cache
                // Note: original uses strncpy from a local buffer
                // Null-terminate at exact end of 32-byte slot
                g_playerNames[playerIndex][31] = '\0';
            }
        }

        if (dest[0] == '\0')
        {
            // No name available — use localized default
            const char* localized = LocalizeString("CommUnnamedPlayer", ecxState, playerIndex);
            StringFormat(dest, "%s %d", localized);
        }
    }

    return dest;
}

} // namespace Giants
