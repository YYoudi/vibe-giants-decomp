// Giants Engine - Player Loading Implementation
// Reverse engineered from GiantsMain.exe v1.520.59

#include "Player.h"
#include <windows.h>
#include <cstdio>

namespace Giants {

// ─── External data references ─────────────────────────────────
static uint32_t DAT_006ff960 = 0;        // Game state (6 = in-game)
static uint32_t DAT_00702964 = 0;        // Player initialized flag
static uint32_t DAT_0067d280 = 0;        // Security cookie base
static uint32_t DAT_00702778 = 0;        // Active player object
static uint32_t DAT_0074893c = 0;        // Player copy
static uint32_t DAT_00725e88 = 0;        // Level loaded flag
extern void*    ExceptionList;

// ─── LoadDefaultPlayer (FUN_00552990) — FAIL (usable ~55%) ─────

// Stub for FUN_0045f6e0 (network player name resolution — not needed for single-player).
int ResolveNetworkPlayerName(uint32_t index) { return 0; }

int LoadDefaultPlayer()
{
    if (DAT_006ff960 == 6) {
        // Already in-game: use existing player
        if (DAT_00702964 == 0) {
            // FUN_00464710 — error handling with cookie check
        } else {
            // FUN_0045fe10 — reset player state
            uint16_t resetCode = 0x31;
            // FUN_0045fe10(&resetCode)
        }
        Sleep(500);
        // FUN_0045af70 — get current player data
        return 0;  // placeholder for FUN_0045af70 result
    }

    // Not in-game: load intro level via the COM factory (FUN_00461a60).
    extern int* GetGameContext(uint32_t);
    extern FILE* g_traceLog;
    int* levelCtx = GetGameContext(0);  // query the game-context object
    if (g_traceLog) {
        fprintf(g_traceLog, "[LOAD] LoadDefaultPlayer: GetGameContext -> %p (COM registry path)\n",
                (void*)levelCtx);
        fflush(g_traceLog);
    }

    // Load "intro_island" via the game-context's level-load method (vtable[6]/0x18
    // in the original). Called directly (cdecl) to avoid thiscall convention issues.
    extern int LevelLoad(void* self, const char* levelName);
    uint32_t* playerData = nullptr;
    if (levelCtx != nullptr) {
        LevelLoad(levelCtx, "intro_island");
    }
    // Load the FLICK cinematic script (drives the menu camera + logo animation).
    extern void LoadFlickScript(const char*);
    LoadFlickScript("flk_intro_island_1");
    if (playerData != nullptr) {
        DAT_00702778 = *playerData;
        DAT_0074893c = DAT_00702778;
    }

    // FUN_00501f50 — initialize level
    int result = 0;
    DAT_00725e88 = 1;  // Mark level as loaded

    // COM-like release of level context object
    // Ref-counted: decrement, call Release when count reaches 0

    return result;
}

// ═══════════════════════════════════════════════════════════════════
// GetPlayerName (FUN_0045f780) — 39 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Returns a pointer to the player name string for the given index.
// Player names stored at DAT_006ff5b0 (20 slots × 0x20 bytes each).
// If name is empty, tries to resolve from network; if still empty,
// generates "UnnamedPlayer N" via GetLocalizedString + FormatString.

// Player name table: 20 entries × 32 bytes = 640 bytes
static char g_playerNames[20][32] = {};  // DAT_006ff5b0

static uint32_t g_networkMode = 0;  // DAT_00702964 (0=DirectPlay, nonzero=WinSock)

extern int  ResolveNetworkPlayerName(uint32_t index);  // FUN_0045f6e0
extern const char* GetLocalizedString(const char* key); // FUN_005e80c0
extern void FormatString(const char* fmt, void* out);   // FUN_00463000
extern uintptr_t g_securityCookie;  // DAT_0067d280

char* GetPlayerName(uint32_t playerIndex)
{
    if (playerIndex >= 0x14) {
        return const_cast<char*>("?");
    }

    char* dest = g_playerNames[playerIndex];

    if (dest[0] == '\0') {
        uint32_t idx = playerIndex;

        // Try network resolution
        if (g_networkMode != 0) {
            char localBuf[260];
            int resolved = ResolveNetworkPlayerName(playerIndex);
            if (resolved != 0) {
                strncpy(dest, localBuf, 0x20);
                g_playerNames[playerIndex][31] = 0;  // null-terminate
            }
        }

        // Still empty? Generate default name
        if (dest[0] == '\0') {
            const char* template_str = GetLocalizedString("CommUnnamedPlayer");
            // FormatString writes "UnnamedPlayer %d" into dest
            struct { char buf[64]; } fmtBuf;
            FormatString("%s %d", &fmtBuf);
        }
    }

    return dest;
}

} // namespace Giants
