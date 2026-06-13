// Giants Engine - Debug Console & Command Dispatch Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
//
// Console input processing + network/local command dispatch.
// 6 functions decompiled from GiantsMain.exe v1.520.59.
// Note: ExecuteCommandSecondary (FUN_0045fcb0) moved to ChatSystem.cpp.
#include <cstdlib>
#include <cstring>
#include "ConsoleDebug.h"
#include "ChatSystem.h"     // ExecuteCommandSecondary
#include "StringUtils.h"

#include <cstring>

namespace Giants {

// ═══════════════════════════════════════════════════════════════════
// Global Data References
// ═══════════════════════════════════════════════════════════════════

// ─── Engine State ──────────────────────────────────────────────

// Engine state (6 = in-game, debug mode active)
static uint32_t DAT_006ff960 = 0;

// Multiplayer / network active flag
// 0 = single-player, non-zero = multiplayer session
static uint32_t DAT_00702964 = 0;

// Network subsystem ready flag
static uint32_t DAT_0073c944 = 0;

// Local host player ID
static int DAT_0073c940 = 0;

// Player count in network session
static int DAT_0070294c = 0;

// ─── Network Player Slots ──────────────────────────────────────
// Array of player IDs at DAT_006ff910. Each entry is a player ID
// or 0 for empty slot. Indexed 0..DAT_0070294c-1.
static int DAT_006ff910[16] = {};

// ─── Network Interface Objects ─────────────────────────────────
// Two network interface COM objects (DirectPlay and WinSock).
// Selected based on DAT_00702964 (session type).
static int* DAT_006ff9e0 = nullptr;   // DirectPlay interface object
static int* DAT_006ff9e4 = nullptr;   // WinSock interface object

// ─── Message Statistics (Primary) ──────────────────────────────
// Updated by ExecuteCommand (FUN_0045fc20)
static uint32_t DAT_006ff968 = 0;     // total messages sent
static uint32_t DAT_006ff96c = 0;     // total bytes sent
static uint32_t DAT_006ff970 = 0;     // total messages delivered
static uint32_t DAT_006ff974 = 0;     // total bytes delivered

// ─── Message Statistics (Secondary) ────────────────────────────
// Updated by ExecuteCommandSecondary (FUN_0045fcb0) — in ChatSystem.cpp
static uint32_t DAT_006ff988 = 0;     // secondary messages sent
static uint32_t DAT_006ff98c = 0;     // secondary bytes sent
static uint32_t DAT_006ff990 = 0;     // secondary messages delivered
static uint32_t DAT_006ff994 = 0;     // secondary bytes delivered

// ─── Per-Player Rate Limiting ──────────────────────────────────
// Array at DAT_0073c958, indexed by player slot * 0x1c (28 bytes each).
// Fields per entry:
//   [+0x18] = uint32_t enabled (1 = rate-limited)
//   [+0x19] = uint32_t* timestamp pointer
//   [+0x1a] = uint32_t last send time
static uint32_t DAT_0073c958[16 * 7] = {};  // 16 players * 7 uint32_t (28 bytes)

// ─── Console Buffer Pointers ───────────────────────────────────
// Primary buffer: base at 0x73d34c, cursor at DAT_0073d348
static char*    DAT_0073d348 = nullptr;
static char     DAT_0073d34c[0x400] = {};

// Secondary buffer: base at 0x73d754, cursor at DAT_0073d750
static char*    DAT_0073d750 = nullptr;
static char     DAT_0073d754[0x400] = {};

// ─── Timing ────────────────────────────────────────────────────
static float    DAT_00727e40 = 0;     // Current time
static float    DAT_0066bf74 = 0;     // Cooldown interval
static float    DAT_0073e76c = 0;     // Last console update time

// ═══════════════════════════════════════════════════════════════════
// ResetConsoleBuffers (FUN_00463020)
// ═══════════════════════════════════════════════════════════════════
// Ghidra: FUN_00463020 (3 callers, 1 callee — memset)
// Purpose: Clears all 6 console/network buffer regions and resets
// 6 cursor pointers to their buffer base addresses.
//
// Original:
//   void FUN_00463020(void)
//   {
//       memset(&DAT_0073d34c, 0, 0x400);    // primary console buffer
//       memset(&DAT_0073d754, 0, 0x400);    // secondary console buffer
//       memset(&DAT_0073db5c, 0, 0x400);    // network buffer 1
//       memset(&DAT_0073df64, 0, 0x400);    // network buffer 2
//       memset(&DAT_0073e36c, 0, 0x400);    // network buffer 3
//       memset(&DAT_006ffa34, 0, 0x2000);   // large buffer
//       DAT_0073d348 = &DAT_0073d34c;       // reset primary cursor
//       DAT_0073d750 = &DAT_0073d754;       // reset secondary cursor
//       DAT_0073db58 = &DAT_0073db5c;       // reset net cursor 1
//       DAT_0073df60 = &DAT_0073df64;       // reset net cursor 2
//       DAT_0073e368 = &DAT_0073e36c;       // reset net cursor 3
//       DAT_006ffa30 = &DAT_006ffa34;       // reset large buffer cursor
//   }

void ResetConsoleBuffers()
{
    // Clear primary console buffer (0x400 = 1024 bytes)
    memset(&DAT_0073d34c, 0, 0x400);

    // Clear secondary console buffer
    memset(&DAT_0073d754, 0, 0x400);

    // Clear network buffers (3 x 0x400 bytes)
    // memset(&DAT_0073db5c, 0, 0x400);
    // memset(&DAT_0073df64, 0, 0x400);
    // memset(&DAT_0073e36c, 0, 0x400);

    // Clear large buffer (0x2000 = 8192 bytes)
    // memset(&DAT_006ffa34, 0, 0x2000);

    // Reset all cursor pointers to buffer bases
    DAT_0073d348 = DAT_0073d34c;
    DAT_0073d750 = DAT_0073d754;
    // DAT_0073db58 = &DAT_0073db5c;
    // DAT_0073df60 = &DAT_0073df64;
    // DAT_0073e368 = &DAT_0073e36c;
    // DAT_006ffa30 = &DAT_006ffa34;
}

// ═══════════════════════════════════════════════════════════════════
// ProcessConsoleInput (FUN_0046ccf0)
// ═══════════════════════════════════════════════════════════════════
// Debug console command processor. Only active when engine state is 6
// (in-game debug mode).

void ProcessConsoleInput(uint32_t param_1)
{
    // Only process in debug state (engine state == 6)
    if (DAT_006ff960 != 6) {
        return;
    }

    // If network session, delegate to network console handler
    if (DAT_00702964 != 0) {
        // FUN_0046c800 — ResetConsoleState()
        return;
    }

    // Re-initialize cursors if they point back to buffer bases
    if (DAT_0073d348 == DAT_0073d34c &&
        DAT_0073d750 == DAT_0073d754)
    {
        // Rate-limit: skip if not enough time has elapsed
        if (DAT_00727e40 < DAT_0073e76c + DAT_0066bf74) {
            return;
        }

        // Reset secondary buffer (set first byte to 0x10, likely length prefix)
        DAT_0073d754[0] = '\x10';
        DAT_0073d750 = (char*)0x73d755;  // Advance cursor past header
    }

    // Null-terminate at current cursor position (end of input)
    *DAT_0073d348 = '\0';
    DAT_0073d348 = DAT_0073d348 + 1;

    *DAT_0073d750 = '\0';
    DAT_0073d750 = DAT_0073d750 + 1;

    // Dispatch primary buffer if it has content (>1 byte beyond base)
    int primaryLen = (int)(DAT_0073d348 - DAT_0073d34c);
    if (primaryLen > 1) {
        if (DAT_00702964 == 0) {
            // Local mode: execute if network subsystem is ready
            if (DAT_0073c944 != 0) {
                ExecuteCommand(reinterpret_cast<uint32_t>(static_cast<void*>(DAT_0073d34c)),
                               param_1, 0);
            }
        } else {
            // Network mode: send to remote players
            SendNetworkCommand(reinterpret_cast<int>(static_cast<void*>(DAT_0073d34c)), param_1);
        }
    }

    // Dispatch secondary buffer if it has content
    int secondaryLen = (int)(DAT_0073d750 - DAT_0073d754);
    if (secondaryLen > 1) {
        if (DAT_00702964 == 0) {
            if (DAT_0073c944 != 0) {
                ExecuteCommandSecondary(reinterpret_cast<int>(static_cast<void*>(DAT_0073d754)), 0);
            }
        } else {
            SendNetworkCommandSecondary(reinterpret_cast<int>(static_cast<void*>(DAT_0073d754)), 0);
        }
    }

    // Reset cursors back to buffer bases for next input cycle
    DAT_0073d348 = DAT_0073d34c;
    DAT_0073d750 = DAT_0073d754;
}

// ═══════════════════════════════════════════════════════════════════
// SendNetworkCommand (FUN_0045fe10)
// ═══════════════════════════════════════════════════════════════════
// Broadcast a command to all remote network players.
// Skips null entries, local host (DAT_0073c940), and sender (param_1).
//
// Ghidra decompilation:
//   void __thiscall FUN_0045fe10(int param_1, undefined4 param_2)
//   {
//       int iVar3 = 0;
//       int iVar2 = DAT_0070294c;
//       if (0 < DAT_0070294c) {
//           do {
//               int iVar1 = (&DAT_006ff910)[iVar3];
//               if (((iVar1 != 0) && (iVar1 != DAT_0073c940)) &&
//                   (iVar1 != param_1)) {
//                   FUN_0045fc20(param_2);     // ExecuteCommand
//                   iVar2 = DAT_0070294c;       // re-read (may change)
//               }
//               iVar3 = iVar3 + 1;
//           } while (iVar3 < iVar2);
//       }
//   }

void SendNetworkCommand(int param_1, uint32_t param_2)
{
    int slotIndex = 0;
    int playerCount = DAT_0070294c;

    if (playerCount <= 0) {
        return;
    }

    do {
        int playerId = DAT_006ff910[slotIndex];

        // Skip: null slot, local host, or sender
        if (playerId != 0 && playerId != DAT_0073c940 && playerId != param_1)
        {
            // Execute command for this remote player
            ExecuteCommand(param_2, 0, 0);

            // Re-read player count (may have changed during iteration)
            playerCount = DAT_0070294c;
        }

        slotIndex++;
    } while (slotIndex < playerCount);
}

// ═══════════════════════════════════════════════════════════════════
// SendNetworkCommandSecondary (FUN_0045fe70)
// ═══════════════════════════════════════════════════════════════════
// Ghidra: FUN_0045fe70 (2 callers, 1 callee)
// Purpose: Broadcast a secondary/echo command to all remote players.
// Same iteration pattern as SendNetworkCommand but calls
// ExecuteCommandSecondary (FUN_0045fcb0) instead.
//
// Original:
//   void __thiscall FUN_0045fe70(int param_1, undefined4 param_2)
//   {
//     int iVar1;
//     int iVar2;
//     int iVar3;
//
//     iVar3 = 0;
//     iVar2 = DAT_0070294c;
//     if (0 < DAT_0070294c) {
//       do {
//         iVar1 = (&DAT_006ff910)[iVar3];
//         if (((iVar1 != 0) && (iVar1 != DAT_0073c940)) && (iVar1 != param_1)) {
//           FUN_0045fcb0(param_2);
//           iVar2 = DAT_0070294c;
//         }
//         iVar3 = iVar3 + 1;
//       } while (iVar3 < iVar2);
//     }
//     return;
//   }

void SendNetworkCommandSecondary(int param_1, uint32_t param_2)
{
    int slotIndex = 0;
    int playerCount = DAT_0070294c;

    if (playerCount <= 0) {
        return;
    }

    do {
        int playerId = DAT_006ff910[slotIndex];

        // Skip: null slot, local host, or sender
        if (playerId != 0 && playerId != DAT_0073c940 && playerId != param_1)
        {
            // Execute secondary command for this remote player
            ExecuteCommandSecondary(static_cast<int>(param_2), 0);

            // Re-read player count
            playerCount = DAT_0070294c;
        }

        slotIndex++;
    } while (slotIndex < playerCount);
}

// ═══════════════════════════════════════════════════════════════════
// ExecuteCommand (FUN_0045fc20)
// ═══════════════════════════════════════════════════════════════════
// Execute a command locally via COM vtable dispatch.
// Updates primary message statistics and dispatches through the
// appropriate network interface.
//
// Ghidra decompilation:
//   undefined4 __fastcall FUN_0045fc20(undefined4 param_1, int param_2,
//                                       undefined4 param_3)
//   {
//       DAT_006ff968 = DAT_006ff968 + 1;
//       DAT_006ff96c = DAT_006ff96c + param_2;
//       DAT_006ff970 = DAT_006ff970 + 1;
//       DAT_006ff974 = DAT_006ff974 + param_2;
//       local_4 = param_3;
//       local_8 = param_2;
//       if (DAT_00702964 == 0) {               // DirectPlay path
//           if (DAT_006ff9e0 != (int *)0x0) {
//               return (**(code **)(*DAT_006ff9e0 + 0x20))
//                   (DAT_006ff9e0, &local_8, 1, 0, 0, &param_3, 0x28);
//           }
//       }
//       else if (DAT_006ff9e4 != (int *)0x0) { // WinSock path
//           return (**(code **)(*DAT_006ff9e4 + 0x38))
//               (DAT_006ff9e4, param_1, &local_8, 1, 0, 0, &param_3, 0x28);
//       }
//       return 0x80004005;                     // E_FAIL
//   }
//
// vtable offsets:
//   DirectPlay: +0x20 = vtable[8]  — Send (guaranteed delivery, size=0x28)
//   WinSock:    +0x38 = vtable[14] — SendTo (with destination, size=0x28)

uint32_t ExecuteCommand(uint32_t param_1, int param_2, uint32_t param_3)
{
    // Update primary message statistics
    DAT_006ff968 += 1;            // messages sent
    DAT_006ff96c += param_2;      // bytes sent
    DAT_006ff970 += 1;            // messages delivered
    DAT_006ff974 += param_2;      // bytes delivered

    // Build the send data structure on the stack
    // local_8 = param_2 (size field)
    // local_4 = param_3 (data/payload field)
    // In the binary: { int size; void* data; } passed as &local_8

    if (DAT_00702964 == 0)
    {
        // DirectPlay path — reliable send
        if (DAT_006ff9e0 != nullptr)
        {
            // vtable[8](interface, &sendData, count=1, flags=0, timeout=0,
            //           &payload, guaranteedSize=0x28)
            // return (**(code**)(*DAT_006ff9e0 + 0x20))
            //     (DAT_006ff9e0, &sendData, 1, 0, 0, &param_3, 0x28);
            return 0;  // S_OK stub
        }
    }
    else
    {
        // WinSock path — send with destination
        if (DAT_006ff9e4 != nullptr)
        {
            // vtable[14](interface, dest=param_1, &sendData, count=1, flags=0,
            //            timeout=0, &payload, guaranteedSize=0x28)
            // return (**(code**)(*DAT_006ff9e4 + 0x38))
            //     (DAT_006ff9e4, param_1, &sendData, 1, 0, 0, &param_3, 0x28);
            return 0;  // S_OK stub
        }
    }

    return 0x80004005;  // E_FAIL — no network interface available
}

// ═══════════════════════════════════════════════════════════════════
// SendErrorCommand (FUN_00464710)
// ═══════════════════════════════════════════════════════════════════
// Ghidra: FUN_00464710 (3 callers, 1 callee — ExecuteCommand)
// Purpose: Send an error notification command to the local player.
// Constructs a 4-byte command: [0x35, player_index, 0x00, error_code>>24].
// Only operates in single-player mode (DAT_00702964 == 0).
//
// Original:
//   void __fastcall FUN_00464710(undefined4 param_1)
//   {
//     int iVar1;
//     undefined1 local_4 [3];
//     undefined1 uStack_1;
//
//     if (DAT_00702964 == 0) {
//       iVar1 = 0;
//       if (0 < DAT_0070294c) {
//         do {
//           if ((&DAT_006ff910)[iVar1] == DAT_0073c940) {
//             if (iVar1 < DAT_0070294c) goto LAB_00464747;
//             break;
//           }
//           iVar1 = iVar1 + 1;
//         } while (iVar1 < DAT_0070294c);
//       }
//       iVar1 = DAT_0070294c + -1;
//   LAB_00464747:
//       uStack_1 = (undefined1)((uint)param_1 >> 0x18);
//       local_4 = (undefined1 [3])CONCAT12(0, CONCAT11((char)iVar1, 0x35));
//       if (DAT_0073c944 != 0) {
//         FUN_0045fc20(local_4);
//       }
//     }
//     return;
//   }

void SendErrorCommand(uint32_t param_1)
{
    // Only operates in single-player mode
    if (DAT_00702964 != 0) {
        return;
    }

    // Find the local host's slot index in the player array
    int playerSlot = 0;

    if (DAT_0070294c > 0)
    {
        do {
            if (DAT_006ff910[playerSlot] == DAT_0073c940)
            {
                if (playerSlot < DAT_0070294c) {
                    goto found;
                }
                break;
            }
            playerSlot++;
        } while (playerSlot < DAT_0070294c);
    }

    // Fallback: use last slot if not found
    playerSlot = DAT_0070294c - 1;

found:
    // Build the 4-byte error command header
    // Ghidra: local_4 = CONCAT12(0, CONCAT11((char)playerSlot, 0x35))
    //         uStack_1 = (uint)param_1 >> 0x18
    // Layout: [0x35, playerSlot, 0x00, error_type]
    uint8_t errorByte = (uint8_t)(param_1 >> 24);    // top byte = error type
    uint32_t commandData = 0;
    uint8_t* bytes = reinterpret_cast<uint8_t*>(&commandData);
    bytes[0] = 0x35;                                 // command code: error
    bytes[1] = static_cast<uint8_t>(playerSlot);     // player index
    bytes[2] = 0x00;                                 // reserved
    bytes[3] = errorByte;                             // error type (top byte)

    // Send the error command if network subsystem is ready
    if (DAT_0073c944 != 0) {
        ExecuteCommand(commandData, sizeof(commandData), 0);
    }
}

} // namespace Giants
