// Giants Engine - Network Functions Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include <cstdlib>
#include <cstring>
#include "Network.h"
#include <cstring>

namespace Giants {

// ============================================================================
// Static globals from Ghidra DAT_ references
// ============================================================================

// DAT_006ff960 - Game session type (6 = multiplayer)
static uint32_t& g_sessionType = *reinterpret_cast<uint32_t*>(0x006ff960);

// DAT_006ff910 - Session player table base
static uint32_t* g_sessionPlayerTable = reinterpret_cast<uint32_t*>(0x006ff910);

// DAT_0070294c - Player count in current session
static int32_t& g_playerCount = *reinterpret_cast<int32_t*>(0x0070294c);

// DAT_0073c940 - Local player identifier
static uint32_t& g_localPlayerId = *reinterpret_cast<uint32_t*>(0x0073c940);

// DAT_0073d348 - Network send buffer write pointer
static int32_t*& g_sendBufferPtr = *reinterpret_cast<int32_t**>(0x0073d348);

// DAT_00661c1c - Error handler / logging target for master server
static uint32_t& g_masterServerErrorTarget = *reinterpret_cast<uint32_t*>(0x00661c1c);

// DAT_0073c924 - Master server connection context (COM-like ref-counted object)
static int32_t*& g_masterServerContext = *reinterpret_cast<int32_t**>(0x0073c924);


// ============================================================================
// NetworkPlayerCheck (0x0045f460) - FAIL
// ============================================================================
// Validates player ID against session table. 592 callers - multiplayer gate.
// In single-player (sessionType != 6), always returns true.
// In multiplayer, checks if the player's session slot matches the expected
// position in the player table, or falls back to the last valid slot.
//
// Raw Ghidra decompilation:
//   bool __fastcall FUN_0045f460(int param_1)
//   {
//     uint uVar1;
//     uint uVar2;
//     if (DAT_006ff960 != 6) {
//       return true;
//     }
//     uVar1 = 0;
//     uVar2 = *(uint *)(param_1 + 0x1d4) & 0xff;
//     if (0 < DAT_0070294c) {
//       while ((&DAT_006ff910)[uVar1] != DAT_0073c940) {
//         uVar1 = uVar1 + 1;
//         if (DAT_0070294c <= (int)uVar1) {
//           return uVar2 == (DAT_0070294c - 1U & 0xff);
//         }
//       }
//       if ((int)uVar1 < DAT_0070294c) goto LAB_0045f4b4;
//     }
//     uVar1 = DAT_0070294c - 1;
//   LAB_0045f4b4:
//     return uVar2 == (uVar1 & 0xff);
//   }

bool NetworkPlayerCheck(int playerId)
{
    // 0x0045f460
    // Single-player: always valid
    if (g_sessionType != 6)
    {
        return true;
    }

    uint32_t slotIndex = 0;
    // Extract player's session ID byte from entity struct at offset 0x1d4
    uint32_t playerSlot = *reinterpret_cast<uint32_t*>(playerId + 0x1d4) & 0xff;

    // Search player table for local player
    if (g_playerCount > 0)
    {
        while (g_sessionPlayerTable[slotIndex] != g_localPlayerId)
        {
            slotIndex++;
            if (static_cast<int>(slotIndex) >= g_playerCount)
            {
                // Not found: check against last slot
                return playerSlot == ((g_playerCount - 1) & 0xff);
            }
        }

        if (static_cast<int>(slotIndex) < g_playerCount)
        {
            return playerSlot == (slotIndex & 0xff);
        }
    }

    // Empty or fallback: use last valid slot
    slotIndex = g_playerCount - 1;
    return playerSlot == (slotIndex & 0xff);
}


// ============================================================================
// PacketSerializer (0x00469de0) - FAIL
// ============================================================================
// Writes type/size/data to network send buffer with memcpy. 209 callers.
// Central multiplayer packet write path. Only active when sessionType == 6.
// Layout written to buffer:
//   [1 byte]  packet type (7=normal, 0x14=reliable)
//   [4 bytes] total payload size
//   [4 bytes] player session ID (from entity+0x1d4)
//   [1 byte]  param5 (channel/flags)
//   [1 byte]  player byte from entity+0x22c
//   [N bytes] payload data via memcpy
//
// Calls FUN_0046ccf0() if buffer would overflow (flush/reset).
//
// Raw Ghidra decompilation:
//   void __fastcall FUN_00469de0(int param_1, int param_2, int param_3,
//       int param_4, undefined1 param_5, void *param_6, char param_7)
//   {
//     size_t _Size;
//     undefined1 uVar1;
//     if (DAT_006ff960 == 6) {
//       _Size = param_4 + (param_2 + param_3) * 4;
//       if (0x3ff < (int)((int)DAT_0073d348 + (_Size - 0x73d340))) {
//         FUN_0046ccf0();
//       }
//       uVar1 = 7;
//       if (param_7 != '\0') {
//         uVar1 = 0x14;
//       }
//       *(undefined1 *)DAT_0073d348 = uVar1;
//       DAT_0073d348 = (int *)((int)DAT_0073d348 + 1);
//       *DAT_0073d348 = _Size + 0xb;
//       DAT_0073d348 = DAT_0073d348 + 1;
//       *DAT_0073d348 = *(int *)(param_1 + 0x1d4);
//       DAT_0073d348 = DAT_0073d348 + 1;
//       *(undefined1 *)DAT_0073d348 = param_5;
//       DAT_0073d348 = (int *)((int)DAT_0073d348 + 1);
//       *(undefined1 *)DAT_0073d348 = *(undefined1 *)(param_1 + 0x22c);
//       DAT_0073d348 = (int *)((int)DAT_0073d348 + 1);
//       if (_Size != 0) {
//         memcpy(DAT_0073d348, param_6, _Size);
//       }
//       DAT_0073d348 = (int *)((int)DAT_0073d348 + _Size);
//     }
//     return;
//   }

// TODO: FUN_0046ccf0 - buffer flush/reset, needs reverse engineering
extern void NetworkBufferFlush();  // FUN_0046ccf0

void PacketSerializer(int param1, int param2, int param3, int param4,
                      uint8_t param5, void* param6, char param7)
{
    // 0x00469de0
    // Only serialize packets in multiplayer sessions
    if (g_sessionType != 6)
    {
        return;
    }

    // Calculate payload size: param4 + (param2 + param3) * 4
    size_t payloadSize = param4 + (param2 + param3) * 4;

    // Check buffer overflow: if write position + payload would exceed buffer end
    // Buffer base at 0x73d340, max 0x3ff (1023) bytes from that base
    if (reinterpret_cast<int>(g_sendBufferPtr) + static_cast<int>(payloadSize - 0x73d340) > 0x3ff)
    {
        // TODO: NetworkBufferFlush is FUN_0046ccf0 - flushes/resets send buffer
        NetworkBufferFlush();
    }

    // Write packet type: 7 = unreliable, 0x14 (20) = reliable/ordered
    uint8_t packetType = (param7 != 0) ? 0x14 : 7;
    *reinterpret_cast<uint8_t*>(g_sendBufferPtr) = packetType;
    g_sendBufferPtr = reinterpret_cast<int32_t*>(reinterpret_cast<int>(g_sendBufferPtr) + 1);

    // Write total size (payload + 11 bytes header)
    *g_sendBufferPtr = static_cast<int32_t>(payloadSize) + 0xb;
    g_sendBufferPtr++;

    // Write player session ID from entity struct offset 0x1d4
    *g_sendBufferPtr = *reinterpret_cast<int32_t*>(param1 + 0x1d4);
    g_sendBufferPtr++;

    // Write param5 (channel/flags byte)
    *reinterpret_cast<uint8_t*>(g_sendBufferPtr) = param5;
    g_sendBufferPtr = reinterpret_cast<int32_t*>(reinterpret_cast<int>(g_sendBufferPtr) + 1);

    // Write player byte from entity struct offset 0x22c
    *reinterpret_cast<uint8_t*>(g_sendBufferPtr) = *reinterpret_cast<uint8_t*>(param1 + 0x22c);
    g_sendBufferPtr = reinterpret_cast<int32_t*>(reinterpret_cast<int>(g_sendBufferPtr) + 1);

    // Copy payload data
    if (payloadSize != 0)
    {
        memcpy(g_sendBufferPtr, param6, payloadSize);
    }
    g_sendBufferPtr = reinterpret_cast<int32_t*>(reinterpret_cast<int>(g_sendBufferPtr) + payloadSize);
}


// ============================================================================
// MasterServerConnection (0x006036a0) - FAIL
// ============================================================================
// Reads "masterServerHostName" from config, builds API URL,
// creates HTTP request object for server list.
//
// Callees (10):
//   FUN_004bebd0 - Config/settings reader initialization
//   FUN_00442880 - Error logging
//   FUN_004bdc70 - Build request context / timestamp
//   operator_new - Heap allocation (0x30 = 48 bytes for request object)
//   FUN_00441d10 - Set request parameters
//   FUN_00470070 - (unknown)
//   FUN_00431ae0 - (unknown)
//   FUN_00443490 - (unknown)
//   FUN_004439b0 - Execute HTTP request / get result
//   __security_check_cookie - Stack protection
//
// Raw Ghidra decompilation:
//   int FUN_006036a0(void)
//   {
//     ... [see full decompilation in ghidra_exports/level4/006036a0.c]
//   }

// TODO: FUN_004bebd0 - Config reader initialization
extern void ConfigReaderInit(void** outReader);  // FUN_004bebd0

// TODO: FUN_00442880 - Error/state logging
extern void LogError(uint32_t* target, int count);  // FUN_00442880

// TODO: FUN_004bdc70 - Build request context
extern uint32_t BuildRequestContext();  // FUN_004bdc70

// TODO: FUN_00441d10 - Set request parameters
extern void SetRequestParams(uint32_t context);  // FUN_00441d10

// TODO: FUN_00470070 - Unknown helper
extern void Helper_00470070();  // FUN_00470070

// TODO: FUN_00431ae0 - Unknown helper
extern void Helper_00431ae0();  // FUN_00431ae0

// TODO: FUN_00443490 - Unknown helper
extern void Helper_00443490();  // FUN_00443490

// TODO: FUN_004439b0 - Execute request / get result
extern int ExecuteRequest();  // FUN_004439b0

int MasterServerConnection()
{
    // 0x006036a0
    //
    // High-level flow:
    // 1. Initialize config reader
    // 2. Read "masterServerHostName" from "network" section
    // 3. If hostname is empty or doesn't end with '/', log error
    // 4. Allocate HTTP request object (48 bytes)
    // 5. Set up vtable pointers and request parameters:
    //    - API version string: L"api-version=1.1"
    //    - API endpoint: L"/api/servers"
    // 6. Attach request to master server context
    // 7. Execute HTTP request and return result
    //
    // The function uses COM-like ref-counting with LOCK/UNLOCK pairs
    // for thread-safe management of the request object.

    // TODO: Full implementation requires reversing 8 callee functions.
    // The Ghidra decompilation shows the structure but many helpers
    // are unidentified. Key observations:
    //
    // - Config key: "network" / "masterServerHostName"
    // - API endpoint: "/api/servers" with version "api-version=1.1"
    // - Request object is 0x30 (48) bytes with two vtable pointers
    // - COM-like AddRef/Release pattern with interlocked increment/decrement

    return 0;  // TODO: Implement once callees are reversed
}


// ============================================================================
// WriteNetworkPacketSimple (FUN_00469d20) — 131 callers
// ============================================================================
// Simplified packet writer: writes type=7, size, entity ID, channel, entity byte, payload.
// Only active in multiplayer (sessionType == 6).
// Calls FUN_0046ccf0 (NetworkBufferFlush) on overflow.

void WriteNetworkPacketSimple(int entityPtr, size_t payloadSize,
                              uint8_t channel, void* payload)
{
    if (g_sessionType != 6)
        return;

    // Check buffer overflow
    if (reinterpret_cast<int>(g_sendBufferPtr) + static_cast<int>(payloadSize - 0x73d340) > 0x3ff)
    {
        NetworkBufferFlush();
    }

    // Write packet header: [type=7][size][entityID][channel][entityByte]
    *reinterpret_cast<uint8_t*>(g_sendBufferPtr) = 7;  // packet type
    g_sendBufferPtr = reinterpret_cast<int32_t*>(reinterpret_cast<int>(g_sendBufferPtr) + 1);

    *g_sendBufferPtr = static_cast<int32_t>(payloadSize + 0xb);  // total size
    g_sendBufferPtr = g_sendBufferPtr + 1;

    *g_sendBufferPtr = *reinterpret_cast<int32_t*>(entityPtr + 0x1d4);  // entity session ID
    g_sendBufferPtr = g_sendBufferPtr + 1;

    *reinterpret_cast<uint8_t*>(g_sendBufferPtr) = channel;
    g_sendBufferPtr = reinterpret_cast<int32_t*>(reinterpret_cast<int>(g_sendBufferPtr) + 1);

    *reinterpret_cast<uint8_t*>(g_sendBufferPtr) = *reinterpret_cast<uint8_t*>(entityPtr + 0x22c);
    g_sendBufferPtr = reinterpret_cast<int32_t*>(reinterpret_cast<int>(g_sendBufferPtr) + 1);

    // Copy payload
    if (payloadSize != 0)
    {
        memcpy(g_sendBufferPtr, payload, payloadSize);
    }
    g_sendBufferPtr = reinterpret_cast<int32_t*>(reinterpret_cast<int>(g_sendBufferPtr) + payloadSize);
}

} // namespace Giants
