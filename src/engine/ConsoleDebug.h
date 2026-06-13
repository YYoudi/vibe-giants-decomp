// Giants Engine - Debug Console & Command Dispatch
// Reverse engineered from GiantsMain.exe v1.520.59
//
// ─── Console Input ─────────────────────────────────────────────────
// FUN_0046ccf0 — ProcessConsoleInput (13 callers, 5 callees)
//   Processes debug console commands when engine is in debug mode (state==6).
//
// FUN_00463020 — ResetConsoleBuffers (3 callers, 1 callee)
//   Clears all 6 console/network buffer regions and resets cursor pointers.
//
// ─── Command Dispatch (Network) ────────────────────────────────────
// FUN_0045fe10 — SendNetworkCommand (53 callers, 1 callee)
//   Broadcasts a command to all network players EXCEPT self and local host.
//   Iterates DAT_0070294c player slots, skips null, self, and host entries.
//
// FUN_0045fe70 — SendNetworkCommandSecondary (2 callers, 1 callee)
//   Broadcasts a secondary/echo command to all network players.
//   Same iteration pattern as SendNetworkCommand but calls FUN_0045fcb0.
//
// ─── Command Dispatch (Local/Single-Player) ────────────────────────
// FUN_0045fc20 — ExecuteCommand (50 callers, 0 callees)
//   Executes a command locally via COM vtable dispatch.
//   Updates message counters (DAT_006ff968/96c/970/974).
//   Branches between DirectPlay (DAT_006ff9e0) and WinSock (DAT_006ff9e4).
//
// FUN_0045fcb0 — ExecuteCommandSecondary (5 callers, 0 callees)
//   Secondary command execution variant. Updates separate counters
//   (DAT_006ff988/98c/990/994). Also branches DirectPlay vs WinSock.
//   Includes rate-limiting via DAT_0073c958 timestamp array.
//
// ─── Error Handler ─────────────────────────────────────────────────
// FUN_00464710 — SendErrorCommand (3 callers, 1 callee)
//   Constructs and sends an error notification command.
//   Builds a 4-byte command header: [0x35, player_index, 0x00, error_byte].
//   Only operates in single-player mode (DAT_00702964 == 0).

#pragma once

#include <cstdint>

namespace Giants {

// ─── Console Input ─────────────────────────────────────────────────

/// Process debug console input. Only active when engine state is 6
/// (in-game debug mode). Manages two string buffers and dispatches
/// completed commands to network or local handlers.
///
/// Ghidra: FUN_0046ccf0 (13 callers, 5 callees)
/// @param param_1  Command parameter or context identifier
void ProcessConsoleInput(uint32_t param_1);

/// Reset all console and network communication buffer regions.
/// Clears 6 buffer regions (4 x 0x400 bytes, 1 x 0x2000 bytes) and
/// resets 6 cursor pointers to their buffer base addresses.
///
/// Buffer layout:
///   DAT_0073d34c / cursor DAT_0073d348  (0x400 bytes — primary console)
///   DAT_0073d754 / cursor DAT_0073d750  (0x400 bytes — secondary console)
///   DAT_0073db5c / cursor DAT_0073db58  (0x400 bytes — network buffer 1)
///   DAT_0073df64 / cursor DAT_0073df60  (0x400 bytes — network buffer 2)
///   DAT_0073e36c / cursor DAT_0073e368  (0x400 bytes — network buffer 3)
///   DAT_006ffa34 / cursor DAT_006ffa30  (0x2000 bytes — large buffer)
///
/// Ghidra: FUN_00463020 (3 callers, 1 callee — memset)
void ResetConsoleBuffers();

// ─── Network Command Dispatch ──────────────────────────────────────

/// Broadcast a command to all remote network players.
/// Iterates through DAT_0070294c player slots (DAT_006ff910 array).
/// Skips: null entries, DAT_0073c940 (local host), and param_1 (self).
/// For each valid remote player, calls ExecuteCommand (FUN_0045fc20).
///
/// Ghidra: FUN_0045fe10 (53 callers, 1 callee)
/// Calling convention: __thiscall
///
/// @param param_1  Sender's player ID (excluded from broadcast)
/// @param param_2  Command data to broadcast
void SendNetworkCommand(int param_1, uint32_t param_2);

/// Broadcast a secondary/echo command to all remote network players.
/// Same iteration pattern as SendNetworkCommand but calls
/// ExecuteCommandSecondary (FUN_0045fcb0) instead.
///
/// Ghidra: FUN_0045fe70 (2 callers, 1 callee)
/// Calling convention: __thiscall
///
/// @param param_1  Sender's player ID (excluded from broadcast)
/// @param param_2  Command data to broadcast
void SendNetworkCommandSecondary(int param_1, uint32_t param_2);

// ─── Local Command Execution ───────────────────────────────────────

/// Execute a command locally via COM vtable dispatch.
/// Updates message statistics counters:
///   DAT_006ff968 += 1 (total messages sent)
///   DAT_006ff96c += param_2 (total bytes sent)
///   DAT_006ff970 += 1 (total messages delivered)
///   DAT_006ff974 += param_2 (total bytes delivered)
///
/// Dispatches through:
///   - DirectPlay path (DAT_006ff9e0): vtable[8](context, &data, 1, 0, 0, &params, 0x28)
///   - WinSock path (DAT_006ff9e4): vtable[14](context, param_1, &data, 1, 0, 0, &params, 0x28)
///
/// Returns E_FAIL (0x80004005) if no network interface is available.
///
/// Ghidra: FUN_0045fc20 (50 callers, 0 callees)
///
/// @param param_1  Command type or destination identifier
/// @param param_2  Command data size
/// @param param_3  Command data / payload
/// @return         HRESULT from vtable dispatch, or 0x80004005 on failure
uint32_t ExecuteCommand(uint32_t param_1, int param_2, uint32_t param_3);

/// (Moved to ChatSystem.h — FUN_0045fcb0)
/// ExecuteCommandSecondary is now declared in ChatSystem.h as it is
/// primarily used by the chat display system for rendering secondary
/// text buffers.

// ─── Error Command ─────────────────────────────────────────────────

/// Send an error notification command to the local player.
/// Constructs a 4-byte command: [0x35, player_index, 0x00, error_code>>24].
/// Only operates in single-player mode (DAT_00702964 == 0).
///
/// The player index is found by searching DAT_006ff910 for DAT_0073c940
/// (local host). The error code's top byte is extracted via (param_1 >> 24).
///
/// Ghidra: FUN_00464710 (3 callers, 1 callee — ExecuteCommand)
///
/// @param param_1  Error code (top byte extracted as error type)
void SendErrorCommand(uint32_t param_1);

} // namespace Giants
