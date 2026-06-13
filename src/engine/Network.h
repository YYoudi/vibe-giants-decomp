// Giants Engine - Network Functions
// Reverse engineered from GiantsMain.exe v1.520.59

#pragma once

#include <cstdint>

namespace Giants {

// --- NetworkPlayerCheck (FUN_0045f460) - FAIL -------------------------
// Validates player ID against session table. 592 callers - multiplayer gate.
// Returns true if player is valid/active.
bool NetworkPlayerCheck(int playerId);  // FUN_0045f460

// --- PacketSerializer (FUN_00469de0) - FAIL ---------------------------
// Writes type/size/data to network buffer with memcpy. 209 callers.
// Central multiplayer packet write path.
void PacketSerializer(int param1, int param2, int param3, int param4,
                      uint8_t param5, void* param6, char param7);  // FUN_00469de0

// --- MasterServerConnection (FUN_006036a0) - FAIL ---------------------
// Reads "masterServerHostName" from config, builds API URL,
// creates HTTP request object for server list.
int MasterServerConnection();  // FUN_006036a0

// --- WriteNetworkPacketSimple (FUN_00469d20) - FAIL ------------------
// Simplified packet serializer. 131 callers. Only active in multiplayer.
void WriteNetworkPacketSimple(int entityPtr, size_t payloadSize,
                              uint8_t channel, void* payload);  // FUN_00469d20

} // namespace Giants
