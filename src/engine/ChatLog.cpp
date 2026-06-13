// Giants Engine - Chat Log System Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "ChatLog.h"
#include <cstdio>
#include <cstring>
#include <ctime>

namespace Giants {

// ─── Constants ─────────────────────────────────────────────────
static constexpr int CHAT_LOG_MAX_ENTRIES = 25;       // 0x19
static constexpr int CHAT_LOG_ENTRY_SIZE = 256;        // 0x100
static constexpr int CHAT_LOG_SHIFT_SIZE = 24 * 256;   // 0x1800
static constexpr int CHAT_LOG_META_SIZE = 24 * 4;      // 0x60

// ─── Globals ───────────────────────────────────────────────────
static bool     s_chatLogEnabled = false;       // DAT_00702bdd
extern int      g_gameState;                    // DAT_006ff960
static int      s_networkFlag = 0;              // DAT_00702964
static int      s_altLogFlag = 0;               // DAT_00702be0

static char     s_chatLogMessages[25][256] = {};       // DAT_006fd5a0
static uint32_t s_chatLogColors[24] = {};              // DAT_006feea0
static uint32_t s_chatLogTimestamps[24] = {};          // DAT_006fef04
static uint8_t  s_chatLogCurrentIndex = 0;             // DAT_006feda0
static uint8_t  s_chatLogTimestampIndex = 0;           // DAT_006fef00
static uint8_t  s_chatLogExtraIndex = 0;               // DAT_006fef64
static uint32_t s_currentColor = 0;                    // DAT_00702890

extern void FilePrintf(FILE* f, const char* fmt, ...);  // FUN_00454270

// ═══════════════════════════════════════════════════════════════════
// AddChatLogEntry (FUN_00453520) — 31 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Adds a message to the circular chat log buffer. Optional file logging
// to chatlog.txt with timestamps. When buffer full (25 entries), shifts
// all entries up by one to make room.

void AddChatLogEntry(const char* message, uint32_t timestamp)
{
    // Optional file logging
    if ((s_chatLogEnabled && g_gameState == 6 && s_networkFlag != 0) || s_altLogFlag != 0) {
        FILE* file = nullptr;
        fopen_s(&file, "chatlog.txt", "at");
        if (file != nullptr) {
            time_t currentTime = time(nullptr);
            struct tm* localTime = localtime(&currentTime);
            char timeBuffer[68];
            strftime(timeBuffer, 64, "%m/%d/%Y %I:%M:%S %p", localTime);
            FilePrintf(file, "[%s] - %s\n", timeBuffer, message);
            fclose(file);
        }
    }

    // Find first empty slot in circular buffer
    int slotIndex = 0;
    char* entryPtr = &s_chatLogMessages[1][0];
    do {
        if (entryPtr[-0x100] == '\0') break;
        if (*entryPtr == '\0') { slotIndex++; break; }
        if (entryPtr[0x100] == '\0') { slotIndex += 2; break; }
        if (entryPtr[0x200] == '\0') { slotIndex += 3; break; }
        if (entryPtr[0x300] == '\0') { slotIndex += 4; break; }
        entryPtr += 0x500;
        slotIndex += 5;
    } while (reinterpret_cast<int>(entryPtr) < 0x006FEFA0);

    // Buffer full: shift everything up
    if (slotIndex == CHAT_LOG_MAX_ENTRIES) {
        memmove(&s_chatLogMessages[0], &s_chatLogMessages[1], CHAT_LOG_SHIFT_SIZE);
        memmove(&s_chatLogColors[0], &s_chatLogColors[1], CHAT_LOG_META_SIZE);
        memmove(&s_chatLogTimestamps[0], &s_chatLogTimestamps[1], CHAT_LOG_META_SIZE);
        s_chatLogCurrentIndex = 0;
        s_chatLogTimestampIndex = 0;
        slotIndex = 0x18;  // Use slot 24 (last)
        s_chatLogExtraIndex = 0;
    }

    // Store message
    if (message == nullptr || *message == '\0') {
        *reinterpret_cast<uint16_t*>(&s_chatLogMessages[slotIndex][0]) = 0x20;  // Space
    } else {
        strncpy(&s_chatLogMessages[slotIndex][0], message, 0xFF);
    }
    s_chatLogMessages[slotIndex][255] = '\0';

    // Store metadata
    s_chatLogColors[slotIndex] = s_currentColor;
    s_chatLogTimestamps[slotIndex] = timestamp;
}

} // namespace Giants
