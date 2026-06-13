// Giants Engine - Replay Record/Playback System
// Reverse engineered from GiantsMain.exe v1.520.59
//
// FUN_0062f7e0 — ProcessReplayFile (FAIL, medium ~100 lines)
//   Reads a replay script file, parses token-based commands, and executes
//   each command as a timed replay frame. Supports RenderDoc capture trigger
//   via F12 (GetAsyncKeyState 0x7B). Each replay command is processed as:
//     1. Parse whitespace-delimited tokens from the file
//     2. For "legal" commands, initialize VFS and construct a path
//     3. Execute each command entry via FUN_005e9b20 (returns a handle)
//     4. For each entry, run a full game loop cycle:
//        a. Advance timer (FUN_00629f50)
//        b. Poll input (keyboard + mouse)
//        c. Tick game logic (FUN_004ad640)
//        d. Pump Windows messages
//        e. Wait for duration (DAT_0066bdb8) or early exit on quit signals
//     5. Finalize via FUN_005e9ff0
//
//   The replay system supports recording and playback of game sessions.
//   It is called from the engine initialization path (FinalInit).

#pragma once

#include <cstdint>
#include <windows.h>

namespace Giants {

// ─── Replay System Globals ─────────────────────────────────────────

// RenderDoc capture interface (COM object with vtable)
extern void*    g_renderDocObj;           // DAT_0074bbb8 — RenderDoc interface

// VFS base path (used for "legal" command path construction)
extern char*    g_vfsBasePath;            // DAT_0074be20 — base path string

// Timing globals used by replay playback loop
extern float    g_replayFrameDuration;    // DAT_0066bdb8 — per-command duration
extern float    g_replayCooldown;         // DAT_0066c01c — cooldown duration
extern float    g_replayTickStep;         // DAT_0066bd28 — tick interval

// Quit/exit signal flags (checked to break replay loop)
extern uint8_t  g_quitFlag0;              // DAT_00702c08
extern uint8_t  g_quitFlag1;              // DAT_00702c0b
extern uint8_t  g_quitFlag2;              // DAT_00702c0e
extern uint8_t  g_quitFlag3;              // DAT_00702c07

// Window globals (for message pump)
extern HWND     g_hWnd;                   // DAT_007281d8 — main window handle
extern HACCEL   g_hAccel;                 // DAT_007281e0 — accelerator table

// PeekMessageA function pointer (allows override for replay mode)
extern FARPROC  g_peekMessageFn;          // DAT_007282d0 / PeekMessageA_exref

// ─── Replay Entry (parsed from script file) ────────────────────────
// Each parsed command becomes one of these, stored in a stack array.
// Size: 0x94 bytes per entry. Array max = ~1 entry (0x5C8 / 0x94 ≈ 9).

struct ReplayEntry {
    uint32_t commandHandle;               // @ 0x00 — handle from FUN_005e9b20
    uint8_t  padding[0x8C];               // @ 0x04 — command data buffer
    uint32_t endHandle;                   // @ 0x90 — secondary handle
};
// static_assert(sizeof(ReplayEntry) == 0x94, "ReplayEntry size mismatch");

// ─── Functions ──────────────────────────────────────────────────────

/// Process a replay script file. Opens the file, parses token-based commands,
/// executes each command as a timed replay frame with full input/game logic
/// ticking. Triggers RenderDoc capture on F12 press.
///
/// Ghidra: FUN_0062f7e0 (1 caller — FinalInit)
/// Returns: 1 if replay file was processed, 0 if no file found.
uint32_t ProcessReplayFile();

// ─── FinalizeReplayCommand (FUN_005e9ff0) — PASS ────────────────
// Cleans up and finalizes a replay command segment. Releases all
// texture/surface resources associated with the replay entry grid,
// then frees the grid itself.
//
// The replay entry is organized as a 2D grid of 0x2c-byte (44-byte)
// cells. Grid dimensions are determined by querying the renderer
// vtable[0xd4/4] for caps values (clamped to max 0x80).
//
// For each cell in the grid:
//   1. Release surface via renderer vtable[0xc8/4] (200 decimal)
//   2. Free the cell's pixel data buffer
//   3. Zero the cell pointer
//
// After releasing all cells, the grid buffer itself is freed.
//
// @param param_1  Grid width in cells (from replay command)
// @param param_2  Grid height in cells (from replay command)
void FinalizeReplayCommand(int param_1, int param_2);   // FUN_005e9ff0

} // namespace Giants
