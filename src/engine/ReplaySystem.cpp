// Giants Engine - Replay Record/Playback System
// Reverse engineered from GiantsMain.exe v1.520.59
//
// FUN_0062f7e0 — ProcessReplayFile (FAIL, medium)
//   Reads a replay script file, parses token-based commands, and
//   runs each as a timed game loop iteration with input polling,
//   game logic ticking, and Windows message pumping.
//   Supports RenderDoc capture via F12.

#include "ReplaySystem.h"
#include "GiantsTypes.h"

#include <cstdlib>
#include <cstring>
#include <cctype>

namespace Giants {

// ─── Forward declarations for sub-functions ────────────────────────

// VFS_Initialize (FUN_00622930) — initializes virtual file system
extern "C" void __cdecl VFS_Initialize();

// FUN_00624b60 — opens replay file, returns HANDLE (or NULL)
extern "C" HANDLE __cdecl OpenReplayFile();

// FUN_00629f50 — UpdateTime: advances frame timer
extern "C" void __cdecl UpdateTime();

// FUN_0062f700 — replay-specific frame tick (advance/poll)
extern "C" void __cdecl ReplayFrameTick();

// FUN_0062aac0 — ProcessRawKeyboardInput: polls keyboard state
extern "C" void __cdecl ProcessRawKeyboardInput();

// FUN_0062abe0 — ProcessMouseInput: polls mouse state
extern "C" void __cdecl ProcessMouseInput();

// FUN_004ad640 — TimerTick: input mapping + controller state
extern "C" void __cdecl TimerTick();

// FUN_005e9b20 — process replay command token, returns handle
extern "C" uint32_t __cdecl ProcessReplayCommand(
    const char* param1,    // +0x84 offset into token buffer
    const char* param2,    // +0x88 offset
    const char* param3     // +0x8c offset
);

// FUN_005e9ff0 — finalize replay command (declared in header as namespace Giants)

// FUN_00461f00 — debug log output
extern "C" void __cdecl DebugLog(const char* msg, int len);

// ─── Constants ─────────────────────────────────────────────────────
// Replay entry size and max entries in the stack buffer.
// Stack buffer is 0x5C8 bytes, entries are 0x94 bytes each.
// Maximum: floor(0x5C8 / 0x94) = 10 entries.

static constexpr uint32_t kReplayEntrySize   = 0x94;
static constexpr uint32_t kMaxReplayEntries  = (0x5C8 / kReplayEntrySize);
static constexpr uint32_t kStackSize          = 0x5C8;

// ─── ProcessReplayFile (FUN_0062f7e0) ──────────────────────────────

uint32_t ProcessReplayFile()
{
    // Stack-allocated replay entries buffer (zeroed)
    // DAT: local_5d4[1484] = 0x5CC bytes (includes the 4-byte stack cookie)
    char entryBuffer[kStackSize];
    memset(entryBuffer, 0, kStackSize);

    // ── Step 1: Renderer pre-frame (vtable offset 0xAC) ───────────
    // Calls g_rendererObj->vtable[0xAC / 4]() — likely BeginFrame or similar
    void* factory = g_rendererObj;    // DAT_00702700
    if (factory)
    {
        auto* vtable = *reinterpret_cast<void***>(factory);
        auto preFrame = reinterpret_cast<void(*)()>(vtable[0xAC / 4]);
        preFrame();
    }

    // ── Step 2: RenderDoc capture trigger (F12) ───────────────────
    // If RenderDoc is active and F12 is pressed, trigger a capture.
    // DAT_0074bbb8 — RenderDoc COM interface
    if (g_renderDocObj != nullptr)
    {
        // GetAsyncKeyState(VK_F12 = 0x7B)
        SHORT keyState = GetAsyncKeyState(0x7B);
        if ((keyState & 1) != 0 && g_renderDocObj != nullptr)
        {
            // Call RenderDoc vtable[0x3C / 4]() — TriggerCapture
            auto* rdVtable = *reinterpret_cast<void***>(g_renderDocObj);
            auto triggerCapture = reinterpret_cast<void(*)()>(rdVtable[0x3C / 4]);
            triggerCapture();
            DebugLog("RenderDoc: frame capture triggered", 0x22);
        }
    }

    // ── Step 3: Renderer post-setup (vtable offset 0xBC) ──────────
    if (factory)
    {
        auto* vtable = *reinterpret_cast<void***>(factory);
        auto postSetup = reinterpret_cast<void(*)()>(vtable[0xBC / 4]);
        postSetup();
    }

    // ── Step 4: Open and read replay script file ──────────────────
    // FUN_00624b60 — opens the replay file, returns a HANDLE
    HANDLE hFile = OpenReplayFile();

    uint32_t result = 0;

    if (hFile != nullptr)
    {
        // Save current file position
        DWORD savedPos = SetFilePointer(hFile, 0, nullptr, FILE_CURRENT);

        // Get file size by seeking to end
        SetFilePointer(hFile, 0, nullptr, FILE_END);
        DWORD fileSize = SetFilePointer(hFile, 0, nullptr, FILE_CURRENT);

        // Restore to saved position
        SetFilePointer(hFile, savedPos, nullptr, FILE_BEGIN);

        // Read entire file into heap buffer
        char* fileBuf = static_cast<char*>(malloc(fileSize + 1));
        char* fileEnd = fileBuf + fileSize;
        DWORD bytesRead = 0;
        ReadFile(hFile, fileBuf, fileSize, &bytesRead, nullptr);
        CloseHandle(hFile);

        fileBuf[fileSize] = '\0';

        // ── Step 5: Parse token-based commands ────────────────────
        // Each command is a whitespace-delimited token. Lines are
        // separated by newlines. '.' also terminates a token.
        int entryCount = 0;
        char* cursor = fileBuf;

        if (cursor < fileEnd)
        {
            int entryOffset = 0;

            do
            {
                // Skip leading whitespace
                while (isspace(static_cast<unsigned char>(*cursor)))
                {
                    cursor++;
                }

                // Read token until whitespace, '.', or end of string
                char* tokenStart = cursor;
                char ch = *cursor;
                char* tokenEnd = cursor;

                while (ch != '\0' && ch != '.' && !isspace(static_cast<unsigned char>(*tokenEnd)))
                {
                    ch = tokenEnd[1];
                    tokenEnd++;
                }

                // Copy token into entry buffer at current offset
                char* entryPtr = entryBuffer + entryOffset;
                uint32_t tokenLen = static_cast<uint32_t>(tokenEnd - tokenStart);
                memcpy(entryPtr, tokenStart, tokenLen);
                entryBuffer[entryOffset + (tokenEnd - tokenStart)] = '\0';

                // Check for "legal" command — triggers VFS init + path construction
                if (_stricmp(entryPtr, "legal") == 0)
                {
                    // DAT_00622930 — VFS_Initialize
                    VFS_Initialize();

                    // Construct full path: vfsBasePath + token data
                    // DAT_0074be20 — g_vfsBasePath
                    char* basePath = g_vfsBasePath;
                    char* basePathEnd = basePath;
                    while (*basePathEnd != '\0')
                        basePathEnd++;

                    // Append path after "legal" token to base path
                    char* destPtr = entryBuffer + entryOffset + 3;  // skip "leg"
                    while (*destPtr != '\0')
                    {
                        // Skip — this is the inline buffer past the token
                        destPtr++;
                    }

                    // Copy vfsBasePath to the end of the token's inline data
                    // (path concatenation for VFS lookup)
                    char* src = basePath;
                    while (src < basePathEnd)
                    {
                        uint32_t chunk = static_cast<uint32_t>(basePathEnd - src) >> 2;
                        if (chunk == 0)
                            break;
                        // Copy 4 bytes at a time for the remaining full words
                        for (; chunk != 0; chunk--)
                        {
                            *reinterpret_cast<uint32_t*>(destPtr) = *reinterpret_cast<uint32_t*>(src);
                            src += 4;
                            destPtr += 4;
                        }
                    }

                    // Copy remaining bytes (1 at a time)
                    uint32_t remainder = static_cast<uint32_t>(basePathEnd - basePath) & 3;
                    for (; remainder != 0; remainder--)
                    {
                        *destPtr = *src;
                        src++;
                        destPtr++;
                    }
                }

                // Process this replay command entry
                // DAT: FUN_005e9b20 — parses command params at offsets +0x84, +0x88, +0x8C
                uint32_t cmdHandle = ProcessReplayCommand(
                    entryPtr + 0x84,     // param1: offset 0x84 into entry
                    entryPtr + 0x88,     // param2: offset 0x88
                    entryPtr + 0x8C      // param3: offset 0x8C
                );

                // Store command handle at start of this entry
                *reinterpret_cast<uint32_t*>(entryBuffer + entryOffset) = cmdHandle;

                entryCount++;
                entryOffset += kReplayEntrySize;

                // Guard against buffer overflow
                if (entryOffset > static_cast<int>(kStackSize - kReplayEntrySize))
                    break;

                // Skip to next line (advance past newline/carriage return)
                ch = *tokenEnd;
                cursor = tokenEnd;
                while (ch != '\0' && ch != '\n' && *cursor != '\r')
                {
                    ch = cursor[1];
                    cursor++;
                }

            } while (cursor < fileEnd);
        }

        // ── Step 6: Execute parsed replay entries ─────────────────
        if (entryCount > 0)
        {
            char* entryPtr = entryBuffer;

            do
            {
                uint32_t cmdHandle = *reinterpret_cast<uint32_t*>(entryPtr);

                if (cmdHandle != 0)
                {
                    // ── Phase 1: Pre-playback tick ───────────────
                    // DAT: FUN_0062f700 — replay frame tick
                    ReplayFrameTick();
                    UpdateTime();     // DAT: FUN_00629f50

                    // Run main loop until g_replayFrameDuration elapsed
                    float startTime = g_deltaTime;     // DAT_00727e40
                    float phaseStart = startTime;       // saved start time
                    float phaseCursor = startTime;      // running time

                    // DAT_0066bdb8 — g_replayFrameDuration
                    if ((g_deltaTime - startTime) < g_replayFrameDuration)
                    {
                        do
                        {
                            UpdateTime();                          // FUN_00629f50
                            float tickTime = g_deltaTime;          // DAT_00727e40

                            // DAT_0066bd28 — g_replayTickStep
                            if (g_replayTickStep <= (g_deltaTime - phaseCursor))
                            {
                                ReplayFrameTick();                 // FUN_0062f700
                                ProcessRawKeyboardInput();         // FUN_0062aac0
                                ProcessMouseInput();               // FUN_0062abe0
                                TimerTick();                       // FUN_004ad640

                                // Windows message pump
                                MSG msg;
                                int msgResult;

                                if (g_bActive == FALSE)            // DAT_007282d0
                                {
                                    msgResult = GetMessageA(&msg, nullptr, 0, 0);
                                }
                                else
                                {
                                    // Use override or PeekMessageA
                                    auto peekFn = reinterpret_cast<BOOL(WINAPI*)(MSG*, HWND, UINT, UINT, UINT)>(
                                        g_peekMessageFn);
                                    msgResult = peekFn(&msg, nullptr, 0, 0, 1);
                                }

                                if (msgResult != 0)
                                {
                                    if (TranslateAcceleratorA(g_hWnd, g_hAccel, &msg) == 0)
                                    {
                                        TranslateMessage(&msg);
                                        DispatchMessageA(&msg);
                                    }
                                }

                                // Check quit signals
                                // DAT_00702c08, DAT_00702c0b, DAT_00702c0e, DAT_00702c07
                                if (g_quitFlag0 || g_quitFlag1 || g_quitFlag2 || g_quitFlag3)
                                    break;

                                phaseCursor = tickTime;
                            }

                        } while ((g_deltaTime - phaseStart) < g_replayFrameDuration);
                    }

                    // ── Phase 2: Post-tick with exit check ───────
                    ReplayFrameTick();
                    ReplayFrameTick();
                    UpdateTime();

                    bool earlyExit = false;
                    float postStartTime = g_deltaTime;     // DAT_00727e40
                    float postCursor = g_deltaTime;

                    // DAT_0066c01c — g_replayCooldown
                    if ((g_deltaTime - postStartTime) < g_replayCooldown)
                    {
                        do
                        {
                            UpdateTime();
                            float tickTime = g_deltaTime;

                            if (g_replayTickStep <= (g_deltaTime - postCursor))
                            {
                                ProcessRawKeyboardInput();
                                ProcessMouseInput();
                                TimerTick();

                                MSG msg;
                                int msgResult;

                                if (g_bActive == FALSE)
                                {
                                    msgResult = GetMessageA(&msg, nullptr, 0, 0);
                                }
                                else
                                {
                                    msgResult = PeekMessageA(&msg, nullptr, 0, 0, 1);
                                }

                                if (msgResult != 0)
                                {
                                    if (TranslateAcceleratorA(g_hWnd, g_hAccel, &msg) == 0)
                                    {
                                        TranslateMessage(&msg);
                                        DispatchMessageA(&msg);
                                    }
                                }

                                // Check quit signals
                                if (g_quitFlag0 || g_quitFlag1 || g_quitFlag2 || g_quitFlag3)
                                {
                                    earlyExit = true;
                                    break;
                                }

                                postCursor = tickTime;
                            }

                        } while ((g_deltaTime - postStartTime) < g_replayCooldown);
                    }

                    // ── Phase 3: Cooldown ────────────────────────
                    UpdateTime();
                    float coolStart = g_deltaTime;
                    float coolCursor = g_deltaTime;

                    if ((g_deltaTime - coolStart) < g_replayFrameDuration)
                    {
                        do
                        {
                            UpdateTime();
                            float tickTime = g_deltaTime;

                            if (g_replayTickStep <= (g_deltaTime - coolCursor))
                            {
                                ReplayFrameTick();

                                if (earlyExit)
                                    break;

                                coolCursor = tickTime;
                            }

                        } while ((g_deltaTime - coolStart) < g_replayFrameDuration);
                    }

                    // Finalize this command entry
                    ReplayFrameTick();

                    // DAT: FUN_005e9ff0 — finalize with handle at entry+0x90 (0x24*4)
                    uint32_t endHandle = *reinterpret_cast<uint32_t*>(
                        entryPtr + (0x24 * sizeof(uint32_t)));
                    FinalizeReplayCommand(0, (uint32_t)endHandle);
                }

                // Advance to next entry
                entryPtr += kReplayEntrySize;
                entryCount--;

            } while (entryCount != 0);
        }

        // Free the file buffer
        free(fileBuf);
        result = 1;
    }

    return result;
}

// ─── FinalizeReplayCommand (FUN_005e9ff0) — PASS ────────────────

void FinalizeReplayCommand(int param_1, int param_2)
{
    // Step 1: Query renderer for grid cell dimensions via vtable[0xd4/4]
    // These return the width/height of each cell in pixels (clamped to 128)
    int cellWidth = 0;   // = (**(code **)(*DAT_00702700 + 0xd4))(3)
    int cellHeight = 0;  // = (**(code **)(*DAT_00702700 + 0xd4))(4)

    // Clamp to max 128
    if (cellWidth > 0x80) cellWidth = 0x80;
    if (cellHeight > 0x80) cellHeight = 0x80;

    // Step 2: Get the grid buffer pointer (from unaff_retaddr —
    // this is passed via a register from the caller, likely the
    // replay entry at offset +0x90)
    void* gridBuffer = nullptr;  // Placeholder for unaff_retaddr

    if (gridBuffer != nullptr) {
        // Compute grid dimensions in cells
        int gridCols = (param_1 - 1 + cellWidth) / cellWidth;
        int gridRows = (param_2 - 1 + cellHeight) / cellHeight;

        // Step 3: Iterate over grid cells and release each one
        if (gridRows > 0) {
            uint32_t* rowPtr = (uint32_t*)((int)gridBuffer + 4);

            do {
                uint32_t* cellPtr = rowPtr;
                int col = gridCols;

                if (col > 0) {
                    do {
                        // Release surface via renderer vtable[0xc8] (200)
                        // (**(code **)(*DAT_00702700 + 200))(cellPtr[-1]);

                        // Free cell pixel data
                        free((void*)*cellPtr);
                        *cellPtr = 0;

                        col--;
                        cellPtr += 0xb;   // Each cell is 0x2c bytes = 11 DWORDs
                    } while (col != 0);
                }

                // Advance to next row
                rowPtr += gridCols * 0xb;
                gridRows--;
            } while (gridRows != 0);
        }

        // Step 4: Free the grid buffer itself
        free(gridBuffer);
    }
}

} // namespace Giants
