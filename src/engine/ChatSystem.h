// Giants Engine - Multiplayer Chat/HUD Text Rendering
// Reverse engineered from GiantsMain.exe v1.520.59
//
// FUN_0046c800 — Processes chat messages and HUD text for display.
// Only active when game state == 6 (in-game). Manages text buffers
// with variable-length records and filters messages by player slot.

#pragma once

#include <cstdint>

namespace Giants {

// ─── ExecuteCommandSecondary (FUN_0045fcb0) ─────────────────────
// Secondary command execution with per-player rate-limiting.
// Dispatches through DirectPlay (vtable[9]) or WinSock (vtable[6])
// interface, then sends via vtable[8] or vtable[14] respectively.
//
// Ghidra: FUN_0045fcb0 (5 callers, 0 callees)
//   DirectPlay: vtable[9] for GetPlayerContext, vtable[8] for send
//   WinSock:    vtable[6] for GetPlayerContext, vtable[14] for send
//   Rate-limit: DAT_0073c958[playerSlot * 0x1c] tracks per-player state
//   Counters:   DAT_006ff988/98c/990/994
//   Send params: timeout=1000ms, guaranteedSize=0x22
//
// @param param_1  Player ID or destination identifier
// @param param_2  Command data size
// @return         HRESULT from vtable dispatch, or 0x80004005 on failure
uint32_t ExecuteCommandSecondary(int param_1, int param_2);

// ─── ProcessChatDisplay (FUN_0046c800) ──────────────────────────
// Processes and renders multiplayer chat/HUD messages for all active
// player slots. This function runs every frame when the game is in
// gameplay state (DAT_006ff960 == 6).
//
// Architecture:
//   The chat system uses variable-length text records stored in two
//   separate buffer regions (DAT_0073d34c and DAT_0073d754), each
//   with a 0x400-byte capacity. A third buffer (DAT_0073db5c) holds
//   record entries of the format: [playerSlot:1][length:2][data:length].
//
// Algorithm:
//   1. Count active player slots from DAT_006ff910[DAT_0070294c]
//   2. Find the local player slot index
//   3. For each remote player slot (skip local):
//      a. Calculate message counts from primary and secondary record buffers
//      b. If no messages and within time window, trigger default message
//      c. Filter records: skip entries for the current player slot
//      d. Copy remaining records into primary and secondary text buffers
//      e. If buffer has content, submit for rendering via FUN_0045fc20/FUN_0045fcb0
//      f. Also copy filtered records to a shared display buffer (DAT_0073e36c)
//
// Time window: messages are suppressed if current time (DAT_00727e40)
//              is before DAT_0073e76c + DAT_0066bf74
//
// Ghidra: FUN_0046c800 (1 caller, 3 callees — FUN_0045fc20, FUN_0045fcb0, memcpy)
void ProcessChatDisplay();   // FUN_0046c800

} // namespace Giants
