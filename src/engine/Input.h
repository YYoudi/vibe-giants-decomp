// Giants Engine - Input Processing
// DirectInput raw keyboard and mouse input handlers
// Reverse engineered from GiantsMain.exe v1.520.59
//
// FUN_0062aac0 — Keyboard: polls DirectInput device via vtable,
//   extracts RAWINPUT key events, maintains 256-bit key state + press latch
// FUN_0062abe0 — Mouse: polls mouse device, updates button/axis state,
//   then runs a bitwise grid operation (cellular automaton / collision map)

#pragma once

#include <cstdint>
#include <windows.h>

namespace Giants {

// ─── Keyboard Input (FUN_0062aac0) ────────────────────────────

// DirectInput device object (COM interface, vtable-based)
extern int*  g_rawInputDevice;     // DAT_00727e5c — IDirectInputDevice8*
extern HRESULT g_rawInputResult;   // DAT_007281d0 — last HRESULT

// 256-bit key state arrays (8 × DWORD = 256 bits)
extern DWORD g_keyState[8];        // DAT_00727e60 — current key state
extern DWORD g_keyPressLatch[8];   // DAT_00727e80 — press event latch (OR'd on key-down)

/// Poll DirectInput keyboard device.
/// Reads RAWINPUT events, updates g_keyState and g_keyPressLatch.
/// @return true on success, false on device error
bool ProcessRawKeyboardInput();    // FUN_0062aac0

// ─── Mouse Input (FUN_0062abe0) ───────────────────────────────

// Mouse button state globals
extern uint32_t DAT_00727fbc;      // Mouse X or button state
extern uint32_t DAT_00727fc0;      // Mouse Y or button state
extern uint32_t DAT_00727fc4;      // Scroll or axis state
extern uint32_t g_mousePrevState;  // DAT_00727fd8
extern uint32_t g_mouseCurrState;  // DAT_00727fdc
extern uint32_t DAT_00727fe0;      // Pressed bits (new & ~old)
extern uint32_t DAT_00727fe4;      // Previous raw mouse state

/// Poll mouse device and update button/axis globals.
/// Also runs a bitwise grid processing pass over arrays at 0x727ea0–0x727f00.
/// @return 1 always
uint32_t ProcessMouseInput();      // FUN_0062abe0

// ─── InputCommandSwitch (FUN_004ae9b0) — FAIL ─────────────────
// Handles camera mode, key bindings, controller state (cases 0x20-0x2B).
// 1 caller (FUN_004aeae0), 3 callees.
void InputCommandSwitch(int param1, uint32_t param2);  // FUN_004ae9b0

// ─── KeyBindingLoader (FUN_004b4130) — FAIL ───────────────────
// Reads KeyVersion from registry, loads key mapping file.
// 2 callers (FUN_00501a20, FUN_00541a50), 12 callees.
void KeyBindingLoader();  // FUN_004b4130

} // namespace Giants
