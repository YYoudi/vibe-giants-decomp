// Giants Engine - Game Context & Initialization Dispatch
// Reverse engineered from GiantsMain.exe v1.520.59
//
// FUN_00461a60 — GetGameContext (34 callers, 0 callees)
//   Returns a shared pointer / ref-counted game context object via vtable
//   dispatch. The returned int* is a [object_ptr, refcount_ptr] pair.
//   Used pervasively throughout the engine to access global state.
//
// FUN_0045af70 — GameInitDispatch (7 callers, 13 callees)
//   High-level game initialization/shutdown dispatcher. Coordinates scene
//   cleanup, network teardown, object destruction, and buffer resets.
//   Branches between single-player and multiplayer paths.
//
// FUN_00454bd0 — MPCleanup (3 callers, 2 callees)
//   Multiplayer session teardown. Releases WinSock COM objects, uninitializes
//   COM, and clears network player state arrays.
//
// FUN_00454cf0 — SPCleanup (6 callers, 2 callees)
//   Single-player session teardown. Releases DirectPlay COM objects,
//   uninitializes COM, and clears network player state arrays.
//
// FUN_005c2040 — FullRenderCleanup (4 callers, 27 callees)
//   Complete render pipeline and scene object teardown. Frees all GPU
//   resources, linked-list objects, texture arrays, and resets the renderer
//   to a clean state. The largest cleanup function in the dispatch chain.
//
// FUN_00501340 — PrimaryRenderReset (2 callers, 1 callee)
//   Reads game configuration from registry (PlayerTeam, GameTeam, SessionName,
//   GameType, etc.) and updates global game settings. Called before each
//   new game session to refresh settings.
//
// FUN_00501a20 — PartialRenderCleanup (11 callers, 3 callees)
//   Conditional render cleanup that checks game state flags and dispatches
//   to either full cleanup (FUN_00541a50) or incremental cleanup
//   (FUN_00501ab0) based on which state flags are set.
//
// FUN_0053b1d0 — MissionCleanup (10 callers, 4 callees)
//   Cleans up mission-specific game objects. Releases sound sources,
//   removes entities from the linked-list (DAT_007496c4), and unlinks
//   scene nodes. Only called when scene type == 2 (mission mode).
//
// FUN_00590950 — ReplaySpectatorCleanup (8 callers, 2 callees)
//   Cleans up replay/spectator mode objects. Releases replay sound sources
//   and removes spectator-linked entities from the object list.
//   Only called when scene type == 3 (replay/spectator mode).
//
// FUN_005dd760 — SecondaryRenderReset (2 callers, 5 callees)
//   Secondary render subsystem reset. Iterates the scene object list and
//   invokes cleanup on specific subsystems (audio, effects, particles,
//   collision) based on their active flags.
//
// FUN_004d1070 — PopDialogLevel (69 callers, 2 callees)
//   Pops a level from the dialog/UI stack. Validates stack underflow and
//   pop mismatch. Resets display configuration pointers and clears the
//   registry key reference. Used pervasively for UI state management.
//
// FUN_004d39d0 — FreeCommandList (16 callers, 1 callee)
//   Frees a linked list of command/message nodes. Each node has a type
//   field (0=string, 2=extra_data, 3=sub_list) and frees associated
//   payloads before freeing the node itself.
//
// FUN_005e9ff0 — CleanupCurrentScene (6 callers, 1 callee)
//   Deallocates a 2D grid of scene tile objects. Queries the renderer for
//   tile dimensions, iterates the grid, calls the renderer's destructor
//   vtable for each tile, frees tile memory, then frees the grid itself.

#pragma once

#include <cstdint>

namespace Giants {

// ─── GetGameContext (FUN_00461a60) ─────────────────────────────────
// Returns a shared pointer to the game context object.
// This is the central accessor for engine state — 34 callers across the
// binary use it to retrieve the active game context.
//
// The function performs COM-style ref-counted object creation via vtable
// dispatch. The vtable selector is computed from param_1:
//   vtable = *(int*)(-(param_1 != 0xFFFFFFFC) & param_1)
//   constructor = *(vtable + 8)
//
// The returned int* points to a 2-field struct:
//   [0] = object pointer (the actual game context)
//   [1] = control block pointer (holds ref counts)
//
// Thread-safe: uses LOCK/UNLOCK (InterlockedIncrement/Decrement) for
// reference counting. When strong refcount drops to 0, the destructor
// is called. When weak refcount drops to 1, the weak destructor fires.
//
// Ghidra: FUN_00461a60 (34 callers, 0 callees)
// Type info: DAT_0065f184
//
// @param param_1  Type tag or flags controlling vtable selection
// @return         Pointer to [object_ptr, refcount_block_ptr] pair
int* GetGameContext(uint32_t param_1);

// ─── GameInitDispatch (FUN_0045af70) ───────────────────────────────
// High-level game initialization and shutdown dispatcher.
// Coordinates cleanup of the current game state and prepares for
// scene transition or full shutdown.
//
// Ghidra: FUN_0045af70 (7 callers, 13 callees)
//
// @param param_1  Context parameter (passed to CleanupCurrentScene)
void GameInitDispatch(uint32_t param_1);

// ─── MPCleanup (FUN_00454bd0) ──────────────────────────────────────
// Multiplayer session teardown. Releases the WinSock COM interface
// (DAT_006ff9e4), its associated player address object (DAT_006ff9dc),
// and uninitializes COM. Clears all network player slots and statistics.
//
// Ghidra: FUN_00454bd0 (3 callers, 2 callees)
void MPCleanup();

// ─── SPCleanup (FUN_00454cf0) ──────────────────────────────────────
// Single-player session teardown. Releases the DirectPlay COM interface
// (DAT_006ff9e0), player address (DAT_006ff9d8), and SP provider
// (DAT_006ff9d4). Uninitializes COM and clears network state arrays.
//
// Ghidra: FUN_00454cf0 (6 callers, 2 callees)
void SPCleanup();

// ─── FullRenderCleanup (FUN_005c2040) ──────────────────────────────
// Complete render pipeline and scene object teardown. This is the
// heaviest cleanup function — frees all GPU resources, linked-list
// scene objects (type-specific for types 0x85, 0x248, 0x270, 0x349,
// 0x34a, 0x34b, 0x3b, 0x3b5, 0x42e, 0x42f, 0x4aa, 0x4ab, 0x4ac,
// 0x4ad, 1, 2, 3), texture arrays, particle systems, and resets
// DAT_00702770/DAT_00702774 to null.
//
// Ghidra: FUN_005c2040 (4 callers, 27 callees)
void FullRenderCleanup();

// ─── PrimaryRenderReset (FUN_00501340) ─────────────────────────────
// Reads game configuration values from the registry key DAT_0074be5c.
// Refreshes ~20 global settings: PlayerTeam, GameTeam, SessionName,
// GameType, GameBaseLevel, AllowJoiners, DamageTeammates, NoVimps,
// LockTeams, PointsPerKill, PointsPerCapture, CapturePreventTime,
// MaxPlayers, SmartieDifficulty, VimpMeatDifficulty, TimeLimit,
// PlayerScoreLimit, TeamScoreLimit, BaseComplete, Unavail1, Unavail2.
//
// Ghidra: FUN_00501340 (2 callers, 1 callee)
void PrimaryRenderReset();

// ─── PartialRenderCleanup (FUN_00501a20) ───────────────────────────
// Conditional render cleanup based on game state flags.
// If all flags (b30, b34, b50, be8) are zero, calls FUN_00541a50
// (lightweight cleanup). Otherwise calls FUN_004b4130 then
// FUN_00501ab0 (incremental cleanup).
//
// Ghidra: FUN_00501a20 (11 callers, 3 callees)
void PartialRenderCleanup();

// ─── MissionCleanup (FUN_0053b1d0) ─────────────────────────────────
// Cleans up mission-specific game objects. Releases sound sources at
// offsets 0x188 and 0x1f8, removes linked entities from DAT_007496c4,
// and unlinks scene nodes at offsets 0x1d8, 0x1d4, 0x1e4, 0x1e0.
//
// Ghidra: FUN_0053b1d0 (10 callers, 4 callees)
//
// @param param_1  Scene object pointer (accessed for type-specific data)
void MissionCleanup(int param_1);

// ─── ReplaySpectatorCleanup (FUN_00590950) ─────────────────────────
// Cleans up replay/spectator mode objects. Releases sound source at
// offset 0xfa8, removes replay entities from DAT_007496c4 at offsets
// 0xfa8 and 0xfac, and unlinks scene node at offset 0xfb0.
//
// Ghidra: FUN_00590950 (8 callers, 2 callees)
//
// @param param_1  Scene object pointer (accessed for replay data)
void ReplaySpectatorCleanup(int param_1);

// ─── SecondaryRenderReset (FUN_005dd760) ───────────────────────────
// Secondary render subsystem reset. Checks active subsystem flags
// (DAT_007488d0-d8-dc-e0) and invokes cleanup on each. Also iterates
// the scene object list to clean up type-0x2c (collision?) objects.
//
// Ghidra: FUN_005dd760 (2 callers, 5 callees)
void SecondaryRenderReset();

// ─── PopDialogLevel (FUN_004d1070) ─────────────────────────────────
// Pops a level from the dialog/UI stack (DAT_00682204). Validates
// underflow and pop mismatch. Resets display config pointers and
// clears the registry key reference (DAT_0074be50).
//
// Ghidra: FUN_004d1070 (69 callers, 2 callees)
//
// @param param_1  Expected dialog ID for mismatch validation
void PopDialogLevel(int param_1);

// ─── FreeCommandList (FUN_004d39d0) ────────────────────────────────
// Frees a linked list of command/message nodes. Walks the list,
// freeing type-specific payloads:
//   type 3: frees sub-list chain
//   type 0: frees string data (if flag bit 0 set)
//   type 2: frees extra data (if flag bit 0 set)
// Then frees each node.
//
// Ghidra: FUN_004d39d0 (16 callers, 1 callee)
//
// @param param_1  Head of the command list to free
void FreeCommandList(uint32_t* param_1);

// ─── CleanupCurrentScene (FUN_005e9ff0) ────────────────────────────
// Deallocates a 2D grid of scene tile objects. Queries the renderer
// vtable (DAT_00702700) for tile dimensions, clamps to 0x80, then
// iterates the grid calling the renderer destructor (vtable[50]) for
// each tile. Frees tile memory and the grid allocation.
//
// Ghidra: FUN_005e9ff0 (6 callers, 1 callee)
//
// @param param_1  Grid width in scene units
// @param param_2  Grid height in scene units
void CleanupCurrentScene(int param_1, int param_2);

} // namespace Giants
