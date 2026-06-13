// Giants Engine - Multiplayer Chat/HUD Text Rendering Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
//
// FUN_0045fcb0 — Secondary command execution with rate-limiting.
// FUN_0046c800 — Chat message filtering and display dispatch.
#include <cstdlib>
#include <cstring>
#include "ChatSystem.h"
#include "GiantsTypes.h"

#include <cstring>

namespace Giants {

// ─── External data references ─────────────────────────────────

// Game state
static uint32_t DAT_006ff960 = 0;              // Game state (6 = in-game)

// Multiplayer / network active flag
// 0 = single-player, non-zero = multiplayer session
static uint32_t DAT_00702964 = 0;

// Player slot table (array of player IDs)
static uint32_t DAT_006ff910[16] = {0};        // Player slot array
static uint32_t DAT_0070294c = 0;              // Number of player slots
static uint32_t DAT_0073c940 = 0;              // Local player ID

// Network Interface Objects
static int* DAT_006ff9e0 = nullptr;            // DirectPlay interface object
static int* DAT_006ff9e4 = nullptr;            // WinSock interface object

// Text buffer pointers (double-buffered for chat rendering)
// Each buffer has a 0x400 byte capacity
static uint8_t* DAT_0073d348 = nullptr;        // Primary buffer write cursor
static uint8_t  DAT_0073d34c[0x400] = {};      // Primary buffer base (0x400 bytes)
static uint8_t* DAT_0073d750 = nullptr;        // Secondary buffer write cursor
static uint8_t  DAT_0073d754[0x400] = {};      // Secondary buffer base (0x400 bytes)

// Record buffer (variable-length entries)
// Entry format: [playerSlot:1 byte][length:2 bytes LE][data:length bytes]
static uint8_t* DAT_0073db58 = nullptr;        // Primary record buffer end
static uint8_t  DAT_0073db5c[0x400] = {};      // Primary record buffer base
static uint8_t* DAT_0073df60 = nullptr;        // Secondary record buffer end
static uint8_t  DAT_0073df64[0x400] = {};      // Secondary record buffer base

// Shared display buffer
static uint8_t* DAT_0073e368 = nullptr;        // Shared display write cursor
static uint8_t  DAT_0073e36c[0x400] = {};      // Shared display buffer base (0x400 bytes)

// Timing
static float    DAT_00727e40 = 0;              // Current game time
static float    DAT_0066bf74 = 0;              // Message display duration
static uint32_t DAT_0073e76c = 0;              // Last message timestamp

// Per-Player Rate Limiting (for ExecuteCommandSecondary)
// Array at DAT_0073c958, indexed by player slot * 0x1c (28 bytes each).
// Fields per entry:
//   [+0x18] = uint32_t enabled (1 = rate-limited)
//   [+0x19] = uint32_t* timestamp pointer
//   [+0x1a] = uint32_t last send time
static uint32_t DAT_0073c958[16 * 7] = {};    // 16 players * 7 uint32_t (28 bytes)

// Secondary message statistics
static uint32_t DAT_006ff988 = 0;              // secondary messages sent
static uint32_t DAT_006ff98c = 0;              // secondary bytes sent
static uint32_t DAT_006ff990 = 0;              // secondary messages delivered
static uint32_t DAT_006ff994 = 0;              // secondary bytes delivered

// ─── ExecuteCommandSecondary (FUN_0045fcb0) ───────────────────
// Ghidra: FUN_0045fcb0 (5 callers, 0 callees)
// Purpose: Secondary command execution with per-player rate-limiting.
// Dispatches through DirectPlay or WinSock interface depending on
// DAT_00702964 (0=DirectPlay, nonzero=WinSock).
//
// Original:
//   undefined4 __fastcall FUN_0045fcb0(int param_1, int param_2)
//   {
//     int iVar1;
//     undefined4 uVar2;
//     undefined4 *puVar3;
//     undefined4 *puStack_28;
//     undefined4 local_14;
//     undefined4 local_10 [4];
//
//     local_10[0] = 0;
//     local_14 = 0;
//     if (DAT_00702964 == 0) {
//       if (DAT_006ff9e0 != (int *)0x0) {
//         (**(code **)(*DAT_006ff9e0 + 0x24))(DAT_006ff9e0, local_10);
//         puVar3 = &DAT_0073c958;
//   LAB_0045fda7:
//         puStack_28 = &local_14;
//         puVar3[0x19] = puStack_28;
//         puVar3[0x18] = 1;
//         puVar3[0x1a] = 0;
//         if (DAT_00727e40 < (float)puVar3[0x1a]) {
//           return 0;
//         }
//         goto LAB_0045fd11;
//       }
//     }
//     else if (DAT_006ff9e4 != (int *)0x0) {
//       (**(code **)(*DAT_006ff9e4 + 0x18))(DAT_006ff9e4, param_1, local_10);
//       iVar1 = 0;
//       if (0 < DAT_0070294c) {
//         do {
//           if ((&DAT_006ff910)[iVar1] == param_1) {
//             if ((-1 < iVar1) &&
//                 (puVar3 = &DAT_0073c958 + iVar1 * 0x1c, puVar3 != (undefined4 *)0x0))
//               goto LAB_0045fda7;
//             break;
//           }
//           iVar1 = iVar1 + 1;
//         } while (iVar1 < DAT_0070294c);
//       }
//   LAB_0045fd11:
//       DAT_006ff988 = DAT_006ff988 + 1;
//       DAT_006ff98c = DAT_006ff98c + param_2;
//       DAT_006ff990 = DAT_006ff990 + 1;
//       DAT_006ff994 = DAT_006ff994 + param_2;
//       if (DAT_00702964 != 0) {
//         uVar2 = (**(code **)(*DAT_006ff9e4 + 0x38))(DAT_006ff9e4, param_1);
//         return uVar2;
//       }
//       uVar2 = (**(code **)(*DAT_006ff9e0 + 0x20))
//                         (DAT_006ff9e0, &stack0xffffffe4, 1, 1000, 0,
//                          &stack0xffffffe0, 0x22);
//       return uVar2;
//     }
//     return 0x80004005;
//   }

uint32_t ExecuteCommandSecondary(int param_1, int param_2)
{
    uint32_t local_14 = 0;
    uint32_t local_10[4] = {};
    local_10[0] = 0;

    if (DAT_00702964 == 0)
    {
        // DirectPlay path: get player context, then rate-limit check
        if (DAT_006ff9e0 != nullptr)
        {
            // vtable[9](interface, &contextOut) — GetPlayerContext
            // (**(code**)(*DAT_006ff9e0 + 0x24))(DAT_006ff9e0, local_10);

            uint32_t* rateData = &DAT_0073c958[0];

            // Set up rate-limit data for player slot 0 (DirectPlay single-player)
            rateData[0x19] = reinterpret_cast<uint32_t>(&local_14); // timestamp pointer
            rateData[0x18] = 1;                                     // enabled
            rateData[0x1a] = 0;                                     // last send time = 0

            // Rate-limit check: if current time < last send time, skip
            if (DAT_00727e40 < *reinterpret_cast<float*>(&rateData[0x1a])) {
                return 0;
            }
            // Fall through to send
        }
    }
    else if (DAT_006ff9e4 != nullptr)
    {
        // WinSock path: get player context with destination ID
        // vtable[6](interface, player, &contextOut)
        // (**(code**)(*DAT_006ff9e4 + 0x18))(DAT_006ff9e4, param_1, local_10);

        // Search player slot array for matching player ID
        int slotIndex = 0;
        if (DAT_0070294c > 0)
        {
            do {
                if (DAT_006ff910[slotIndex] == param_1)
                {
                    if (slotIndex >= 0)
                    {
                        // Calculate rate-limit data at DAT_0073c958 + slotIndex * 0x1c
                        uint32_t* rateData = &DAT_0073c958[slotIndex * 7];

                        rateData[0x19] = reinterpret_cast<uint32_t>(&local_14);
                        rateData[0x18] = 1;
                        rateData[0x1a] = 0;

                        // Rate-limit check
                        if (DAT_00727e40 < *reinterpret_cast<float*>(&rateData[0x1a])) {
                            return 0;
                        }
                    }
                    break;
                }
                slotIndex++;
            } while (slotIndex < DAT_0070294c);
        }
    }

    // Update secondary message statistics
    DAT_006ff988 += 1;            // secondary messages sent
    DAT_006ff98c += param_2;      // secondary bytes sent
    DAT_006ff990 += 1;            // secondary messages delivered
    DAT_006ff994 += param_2;      // secondary bytes delivered

    if (DAT_00702964 != 0)
    {
        // WinSock send: vtable[14](interface, destination)
        // uVar2 = (**(code**)(*DAT_006ff9e4 + 0x38))(DAT_006ff9e4, param_1);
        // return uVar2;
        return 0;  // S_OK stub
    }

    // DirectPlay send: vtable[8](interface, &data, 1, timeout=1000, 0, &payload, size=0x22)
    // uVar2 = (**(code**)(*DAT_006ff9e0 + 0x20))
    //     (DAT_006ff9e0, &stack, 1, 1000, 0, &stack, 0x22);
    // return uVar2;
    if (DAT_006ff9e0 != nullptr) {
        return 0;  // S_OK stub
    }

    return 0x80004005;  // E_FAIL — no network interface available
}

// ─── Helper: count records for a player slot ──────────────────
// Iterates over variable-length record buffer, summing lengths
// of entries NOT belonging to the given player slot.

static int CountRecordsExcluding(uint8_t* bufferStart, uint8_t* bufferEnd, int excludeSlot)
{
    int totalSize = 0;
    uint8_t* ptr = bufferStart;

    if (bufferStart >= bufferEnd) return 0;

    do {
        uint16_t entryLen = *(uint16_t*)(ptr + 1);
        if (*ptr != excludeSlot) {
            totalSize += entryLen;
        }
        ptr += entryLen + 3;  // 1 byte slot + 2 bytes length + entryLen
    } while (ptr < bufferEnd);

    return totalSize;
}

// ─── ProcessChatDisplay (FUN_0046c800) ─────────────────────────
// Ghidra: FUN_0046c800 (1 caller, 3 callees)
// Purpose: Process and render multiplayer chat/HUD messages for all
// active player slots. Only runs when game state == 6 (in-game).
//
// Original:
//   void FUN_0046c800(void)
//   {
//     undefined1 *puVar1;
//     undefined1 *puVar2;
//     int iVar3;
//     undefined1 *puVar4;
//     int iVar5;
//     byte *pbVar6;
//     byte *pbVar7;
//     uint uVar8;
//     undefined1 *_Dst;
//     uint local_28;
//     int *local_24;
//     int local_20;
//     int local_1c;
//     uint local_18;
//     int local_14;
//
//     puVar2 = DAT_0073d750;
//     puVar1 = DAT_0073d348;
//     if (DAT_006ff960 == 6) {
//       iVar3 = 0;
//       local_14 = 0;
//       iVar5 = 0;
//       if (0 < DAT_0070294c) {
//         do {
//           local_14 = iVar3 + 1;
//           if ((&DAT_006ff910)[iVar3] == 0) {
//             local_14 = iVar5;
//           }
//           iVar3 = iVar3 + 1;
//           iVar5 = local_14;
//         } while (iVar3 < DAT_0070294c);
//       }
//       local_18 = 0;
//       if (0 < DAT_0070294c) {
//         do {
//           if ((&DAT_006ff910)[local_18] == DAT_0073c940) {
//             if ((int)local_18 < DAT_0070294c) goto LAB_0046c87f;
//             break;
//           }
//           local_18 = local_18 + 1;
//         } while ((int)local_18 < DAT_0070294c);
//       }
//       local_18 = DAT_0070294c - 1;
//   LAB_0046c87f:
//       local_28 = 0;
//       if (0 < local_14) {
//         local_24 = &DAT_006ff910;
//         pbVar7 = DAT_0073db58;
//         do {
//           if ((local_18 != local_28) && (*local_24 != 0)) {
//             local_20 = 0;
//             pbVar6 = DAT_0073db5c;
//             if (DAT_0073db5c < pbVar7) {
//               iVar5 = 0;
//               do {
//                 local_20 = (uint)*(ushort *)(pbVar6 + 1) + iVar5;
//                 if (*pbVar6 == local_28) {
//                   local_20 = iVar5;
//                 }
//                 pbVar6 = pbVar6 + *(ushort *)(pbVar6 + 1) + 3;
//                 iVar5 = local_20;
//               } while (pbVar6 < pbVar7);
//             }
//             pbVar6 = DAT_0073df64;
//             local_1c = 0;
//             if (DAT_0073df64 < DAT_0073df60) {
//               iVar5 = 0;
//               do {
//                 local_1c = (uint)*(ushort *)(pbVar6 + 1) + iVar5;
//                 if (*pbVar6 == local_28) {
//                   local_1c = iVar5;
//                 }
//                 pbVar6 = pbVar6 + *(ushort *)(pbVar6 + 1) + 3;
//                 pbVar7 = DAT_0073db58;
//                 iVar5 = local_1c;
//               } while (pbVar6 < DAT_0073df60);
//             }
//             DAT_0073d750 = puVar2;
//             if (((puVar1 == &DAT_0073d34c[0]) && (puVar2 == &DAT_0073d754[0])) &&
//                  (local_1c + local_20 == 0))
//             {
//               if (DAT_00727e40 < DAT_0073e76c + DAT_0066bf74) goto LAB_0046cca9;
//               DAT_0073d754 = 0x10;
//               DAT_0073d750 = (undefined1 *)0x73d755;
//               pbVar7 = DAT_0073db58;
//             }
//             puVar4 = puVar1;
//             DAT_0073d348 = puVar1;
//             if ((0 < local_20) &&
//                 ((int)(puVar1 + local_20 + -0x73d34b) < 0x400)) {
//               pbVar6 = DAT_0073db5c;
//               if (DAT_0073db5c < pbVar7) {
//                 do {
//                   uVar8 = (uint)*(ushort *)(pbVar6 + 1);
//                   if (*pbVar6 != local_28) {
//                     memcpy(puVar4, pbVar6 + 3, uVar8);
//                     puVar4 = DAT_0073d348 + uVar8;
//                     pbVar7 = DAT_0073db58;
//                     DAT_0073d348 = puVar4;
//                   }
//                   pbVar6 = pbVar6 + 3 + uVar8;
//                 } while (pbVar6 < pbVar7);
//               }
//               local_20 = 0;
//             }
//             if ((0 < local_1c) &&
//                 ((int)(DAT_0073d750 + local_1c + -0x73d753) < 0x400)) {
//               pbVar7 = DAT_0073df64;
//               _Dst = DAT_0073d750;
//               if (DAT_0073df64 < DAT_0073df60) {
//                 do {
//                   uVar8 = (uint)*(ushort *)(pbVar7 + 1);
//                   if (*pbVar7 != local_28) {
//                     memcpy(_Dst, pbVar7 + 3, uVar8);
//                     _Dst = DAT_0073d750 + uVar8;
//                     DAT_0073d750 = _Dst;
//                   }
//                   pbVar7 = pbVar7 + 3 + uVar8;
//                   puVar4 = DAT_0073d348;
//                 } while (pbVar7 < DAT_0073df60);
//               }
//               local_1c = 0;
//             }
//             *puVar4 = 0;
//             DAT_0073d348 = DAT_0073d348 + 1;
//             *DAT_0073d750 = 0;
//             DAT_0073d750 = DAT_0073d750 + 1;
//             if (1 < (int)(DAT_0073d348 + -0x73d34c)) {
//               FUN_0045fc20(&DAT_0073d34c[0]);
//             }
//             if (1 < (int)(DAT_0073d750 + -0x73d754)) {
//               FUN_0045fcb0(&DAT_0073d754[0]);
//             }
//             if (0 < local_20) {
//               pbVar6 = DAT_0073db5c;
//               puVar4 = DAT_0073e36c;
//               DAT_0073e368 = DAT_0073e36c;
//               pbVar7 = DAT_0073db58;
//               if (DAT_0073db5c < DAT_0073db58) {
//                 do {
//                   uVar8 = (uint)*(ushort *)(pbVar6 + 1);
//                   if (*pbVar6 != local_28) {
//                     if (0x3ff < (int)(puVar4 + (uVar8 - 0x73e36b))) {
//                       *puVar4 = 0;
//                       DAT_0073e368 = DAT_0073e368 + 1;
//                       FUN_0045fc20(DAT_0073e36c);
//                       puVar4 = DAT_0073e36c;
//                       DAT_0073e368 = DAT_0073e36c;
//                     }
//                     memcpy(puVar4, pbVar6 + 3, uVar8);
//                     puVar4 = DAT_0073e368 + uVar8;
//                     pbVar7 = DAT_0073db58;
//                     DAT_0073e368 = puVar4;
//                   }
//                   pbVar6 = pbVar6 + 3 + uVar8;
//                 } while (pbVar6 < pbVar7);
//               }
//               *puVar4 = 0;
//               DAT_0073e368 = DAT_0073e368 + 1;
//               FUN_0045fc20(DAT_0073e36c);
//             }
//             pbVar7 = DAT_0073db58;
//             if (0 < local_1c) {
//               pbVar6 = DAT_0073df64;
//               puVar4 = DAT_0073e36c;
//               DAT_0073e368 = DAT_0073e36c;
//               pbVar7 = DAT_0073df60;
//               if (DAT_0073df64 < DAT_0073df60) {
//                 do {
//                   uVar8 = (uint)*(ushort *)(pbVar6 + 1);
//                   if (*pbVar6 != local_28) {
//                     if (0x3ff < (int)(puVar4 + (uVar8 - 0x73e36b))) {
//                       *puVar4 = 0;
//                       DAT_0073e368 = DAT_0073e368 + 1;
//                       FUN_0045fcb0(DAT_0073e36c);
//                       puVar4 = DAT_0073e36c;
//                       DAT_0073e368 = DAT_0073e36c;
//                     }
//                     memcpy(puVar4, pbVar6 + 3, uVar8);
//                     puVar4 = DAT_0073e368 + uVar8;
//                     pbVar7 = DAT_0073df60;
//                     DAT_0073e368 = puVar4;
//                     }
//                   pbVar6 = pbVar6 + 3 + uVar8;
//                 } while (pbVar6 < pbVar7);
//               }
//               *puVar4 = 0;
//               DAT_0073e368 = DAT_0073e368 + 1;
//               FUN_0045fcb0(DAT_0073e36c);
//               pbVar7 = DAT_0073db58;
//             }
//           }
//     LAB_0046cca9:
//           local_28 = local_28 + 1;
//           local_24 = local_24 + 1;
//         } while ((int)local_28 < local_14);
//       }
//       DAT_0073d348 = &DAT_0073d34c[0];
//       DAT_0073d750 = &DAT_0073d754[0];
//       DAT_0073db58 = DAT_0073db5c;
//       DAT_0073df60 = DAT_0073df64;
//     }
//     return;
//   }

void ProcessChatDisplay()
{
    uint8_t* secondaryBuf = DAT_0073d750;
    uint8_t* primaryBuf = DAT_0073d348;

    // Only process when in active gameplay
    if (DAT_006ff960 != 6) return;

    // Step 1: Count active players
    // Ghidra: iterates DAT_006ff910, tracks highest non-zero slot + 1
    int activePlayers = 0;
    int count = 0;
    if (0 < (int)DAT_0070294c) {
        do {
            activePlayers = count + 1;
            if (DAT_006ff910[count] == 0) {
                activePlayers = count;  // Don't advance past empty slots
            }
            count++;
        } while (count < (int)DAT_0070294c);
    }

    // Step 2: Find local player slot index
    uint32_t localSlot = 0;
    if (0 < (int)DAT_0070294c) {
        do {
            if (DAT_006ff910[localSlot] == DAT_0073c940) {
                if ((int)localSlot < (int)DAT_0070294c) break;
            }
            localSlot++;
        } while ((int)localSlot < (int)DAT_0070294c);
    }
    // Fallback: use last slot if not found
    if (localSlot >= DAT_0070294c) {
        localSlot = DAT_0070294c - 1;
    }

    // Step 3: Process each remote player slot
    uint32_t currentSlot = 0;
    if (0 < activePlayers) {
        uint32_t* slotPtr = DAT_006ff910;
        uint8_t* recordEnd = DAT_0073db58;

        do {
            // Skip local player and empty slots
            if (localSlot != currentSlot && *slotPtr != 0) {
                // Accumulate message size from primary record buffer
                // Ghidra: sums *(ushort*)(ptr+1) for entries where *ptr != currentSlot
                int primaryMsgSize = 0;
                uint8_t* primaryRecPtr = DAT_0073db5c[0];
                if (primaryRecPtr < recordEnd) {
                    int accum = 0;
                    do {
                        int entrySize = (uint16_t)*(uint16_t*)(primaryRecPtr + 1);
                        primaryMsgSize = entrySize + accum;
                        if (*primaryRecPtr == currentSlot) {
                            primaryMsgSize = accum;  // Exclude current slot's entry
                        }
                        primaryRecPtr += *(uint16_t*)(primaryRecPtr + 1) + 3;
                        accum = primaryMsgSize;
                    } while (primaryRecPtr < recordEnd);
                }

                // Accumulate message size from secondary record buffer
                int secondaryMsgSize = 0;
                uint8_t* secondaryRecPtr = DAT_0073df64[0];
                if (secondaryRecPtr < DAT_0073df60) {
                    int accum = 0;
                    do {
                        int entrySize = (uint16_t)*(uint16_t*)(secondaryRecPtr + 1);
                        secondaryMsgSize = entrySize + accum;
                        if (*secondaryRecPtr == currentSlot) {
                            secondaryMsgSize = accum;
                        }
                        secondaryRecPtr += *(uint16_t*)(secondaryRecPtr + 1) + 3;
                        recordEnd = DAT_0073db58;  // Re-read after potential mutation
                        accum = secondaryMsgSize;
                    } while (secondaryRecPtr < DAT_0073df60);
                }

                // Step 4: Check if no messages — trigger default text if within time window
                // Ghidra: checks puVar1 == DAT_0073d34c && puVar2 == DAT_0073d754
                secondaryBuf = DAT_0073d750;
                if ((primaryBuf == &DAT_0073d34c[0]) &&
                    (secondaryBuf == &DAT_0073d754[0]) &&
                    (secondaryMsgSize + primaryMsgSize == 0))
                {
                    if (DAT_00727e40 < DAT_0073e76c + DAT_0066bf74) {
                        goto next_slot;  // LAB_0046cca9
                    }
                    // Set default message (0x10 prefix byte)
                    DAT_0073d754[0] = 0x10;
                    DAT_0073d750 = (uint8_t*)0x73d755;
                    recordEnd = DAT_0073db58;
                }

                // Step 5: Filter and copy primary records into primary text buffer
                uint8_t* writePtr = primaryBuf;
                DAT_0073d348 = primaryBuf;
                if (primaryMsgSize > 0 &&
                    (int)(writePtr + primaryMsgSize - 0x73d34b) < 0x400) {
                    uint8_t* readPtr = DAT_0073db5c[0];
                    if (readPtr < recordEnd) {
                        do {
                            uint32_t entryLen = (uint16_t)*(uint16_t*)(readPtr + 1);
                            if (*readPtr != currentSlot) {
                                memcpy(writePtr, readPtr + 3, entryLen);
                                writePtr = DAT_0073d348 + entryLen;
                                recordEnd = DAT_0073db58;
                                DAT_0073d348 = writePtr;
                            }
                            readPtr += entryLen + 3;
                        } while (readPtr < recordEnd);
                    }
                    primaryMsgSize = 0;
                }

                // Step 6: Filter and copy secondary records into secondary text buffer
                if (secondaryMsgSize > 0 &&
                    (int)(DAT_0073d750 + secondaryMsgSize - 0x73d753) < 0x400) {
                    uint8_t* secReadPtr = DAT_0073df64[0];
                    uint8_t* secWritePtr = DAT_0073d750;
                    if (secReadPtr < DAT_0073df60) {
                        do {
                            uint32_t entryLen = (uint16_t)*(uint16_t*)(secReadPtr + 1);
                            if (*secReadPtr != currentSlot) {
                                memcpy(secWritePtr, secReadPtr + 3, entryLen);
                                secWritePtr = DAT_0073d750 + entryLen;
                                DAT_0073d750 = secWritePtr;
                            }
                            secReadPtr += entryLen + 3;
                            writePtr = DAT_0073d348;
                        } while (secReadPtr < DAT_0073df60);
                    }
                    secondaryMsgSize = 0;
                }

                // Null-terminate both buffers
                *writePtr = 0;
                DAT_0073d348++;
                *DAT_0073d750 = 0;
                DAT_0073d750++;

                // Step 7: Submit for rendering if content exists
                // Ghidra: checks offset from buffer base > 1
                if (1 < (int)(DAT_0073d348 - &DAT_0073d34c[0])) {
                    // FUN_0045fc20(&DAT_0073d34c[0]) — render primary chat text
                }
                if (1 < (int)(DAT_0073d750 - &DAT_0073d754[0])) {
                    // FUN_0045fcb0(&DAT_0073d754[0]) — render secondary chat text
                }

                // Step 8: Copy filtered primary records to shared display buffer
                if (primaryMsgSize > 0) {
                    uint8_t* sharedReadPtr = DAT_0073db5c;
                    uint8_t* sharedWritePtr = DAT_0073e36c;
                    DAT_0073e368 = DAT_0073e36c;
                    recordEnd = DAT_0073db58;

                    if (sharedReadPtr < recordEnd) {
                        do {
                            uint32_t entryLen = (uint16_t)*(uint16_t*)(sharedReadPtr + 1);
                            if (*sharedReadPtr != currentSlot) {
                                // Overflow check: flush shared buffer if entry won't fit
                                if (0x3ff < (int)(sharedWritePtr + (entryLen - 0x73e36b))) {
                                    *sharedWritePtr = 0;
                                    DAT_0073e368++;
                                    // FUN_0045fc20(DAT_0073e36c) — render shared text
                                    sharedWritePtr = DAT_0073e36c;
                                    DAT_0073e368 = DAT_0073e36c;
                                }
                                memcpy(sharedWritePtr, sharedReadPtr + 3, entryLen);
                                sharedWritePtr = DAT_0073e368 + entryLen;
                                recordEnd = DAT_0073db58;
                                DAT_0073e368 = sharedWritePtr;
                            }
                            sharedReadPtr += entryLen + 3;
                        } while (sharedReadPtr < recordEnd);
                    }
                    *sharedWritePtr = 0;
                    DAT_0073e368++;
                    // FUN_0045fc20(DAT_0073e36c) — render shared text
                }

                // Copy filtered secondary records to shared display buffer
                recordEnd = DAT_0073db58;
                if (secondaryMsgSize > 0) {
                    uint8_t* secReadPtr2 = DAT_0073df64;
                    uint8_t* secWritePtr2 = DAT_0073e36c;
                    DAT_0073e368 = DAT_0073e36c;
                    recordEnd = DAT_0073df60;

                    if (secReadPtr2 < recordEnd) {
                        do {
                            uint32_t entryLen = (uint16_t)*(uint16_t*)(secReadPtr2 + 1);
                            if (*secReadPtr2 != currentSlot) {
                                // Overflow check
                                if (0x3ff < (int)(secWritePtr2 + (entryLen - 0x73e36b))) {
                                    *secWritePtr2 = 0;
                                    DAT_0073e368++;
                                    // FUN_0045fcb0(DAT_0073e36c) — render shared text
                                    secWritePtr2 = DAT_0073e36c;
                                    DAT_0073e368 = DAT_0073e36c;
                                }
                                memcpy(secWritePtr2, secReadPtr2 + 3, entryLen);
                                secWritePtr2 = DAT_0073e368 + entryLen;
                                recordEnd = DAT_0073df60;
                                DAT_0073e368 = secWritePtr2;
                            }
                            secReadPtr2 += entryLen + 3;
                        } while (secReadPtr2 < recordEnd);
                    }
                    *secWritePtr2 = 0;
                    DAT_0073e368++;
                    // FUN_0045fcb0(DAT_0073e36c) — render shared text
                    recordEnd = DAT_0073db58;
                }
            }

next_slot:
            currentSlot++;
            slotPtr++;
        } while ((int)currentSlot < activePlayers);
    }

    // Reset buffer cursors to base addresses
    DAT_0073d348 = &DAT_0073d34c[0];
    DAT_0073d750 = &DAT_0073d754[0];
    DAT_0073db58 = DAT_0073db5c;
    DAT_0073df60 = DAT_0073df64;
}

} // namespace Giants
