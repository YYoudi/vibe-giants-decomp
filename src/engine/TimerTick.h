// Giants Engine - TimerTick / Input Mapping & Controller State
// Reverse engineered from GiantsMain.exe v1.520.59
//
// FUN_004ad640 — Called every frame by ProcessGameLogic (FUN_00524f30).
//   Reads controller state, maps input buttons to action codes, extracts
//   button bits from the DirectInput controller state, and manages
//   input accumulator reset on state transitions.

#pragma once

#include <cstdint>

namespace Giants {

// ─── Controller State Globals ────────────────────────────────────

// Controller object pointer (DirectInput gamepad array)
extern uint32_t* g_controllerState;         // DAT_00702774 — controller state struct ptr

// Controller type identifier
//   0 = none, 2 = gamepad (sets flag 0x100000), 3 = other (sets bit 3)
extern uint32_t  g_controllerType;          // offset 0x22C from controller struct (0x8b*4)

// Active controller index (0 = no controller, 1..13 valid range)
extern int       g_activeController;        // DAT_00702924
extern uint32_t  g_controllerEnabled;       // DAT_007029cc

// ─── Button Mapping Globals ──────────────────────────────────────

// Current mapped action character (0x00='A'..0x19='Z')
extern char      g_mappedAction;            // DAT_00702c00

// Button state flags extracted from controller state word DAT_00727e98
extern uint8_t   g_btnBit8;                // DAT_00702c52 — (state >> 8) & 1
extern uint8_t   g_btnBit10;               // DAT_00702c53 — state._2_1_ & 1
extern uint8_t   g_btnBit11;               // DAT_00702c54 — (state >> 11) & 1
extern uint8_t   g_btnBit13;               // DAT_00702c55 — (state >> 13) & 1
extern uint8_t   g_btnBit9;                // DAT_00702c56 — (state >> 9) & 1
extern uint8_t   g_btnBit17;               // DAT_00702c57 — (state >> 17) & 1

// Combined flag from multiple sources
extern uint8_t   g_btnCombinedFlag;        // DAT_00702c58 — from DAT_00727e80/_DAT_00727e90 bit 29
extern uint8_t   g_btnBit25;               // DAT_00702c59 — (DAT_00727ec0 >> 25) & 1

// Extended button flags from DAT_00727ec4 >> 24
extern uint8_t   g_extBtnBit3;             // DAT_00702c3a — (ext >> 3) & 1
extern uint8_t   g_extBtnBit4;             // DAT_00702c4f — (ext >> 4) & 1 (conditional)
extern uint8_t   g_extBtnBit5;             // DAT_00702c61 — (ext >> 5) & 1
extern uint8_t   g_extBtnBit6;             // DAT_00702c62 — (ext >> 6) & 1

// ─── Input Accumulator Reset Trigger ────────────────────────────

// When non-zero, indicates an active input state that prevents reset
extern uint32_t* g_inputActive;            // DAT_00702a48
extern int       g_inputState;             // DAT_00702a40 — 1 = active, 0 = reset done
extern float     g_inputTimer;             // DAT_00702a44 — countdown timer

// ─── Functions ────────────────────────────────────────────────────

/// Process input tick: map buttons, extract controller state, manage
/// input accumulator reset on state transitions.
/// Called once per frame by ProcessGameLogic (FUN_00524f30).
void TimerTick();                   // FUN_004ad640

// ─── ResetInputState (FUN_004adab0) ──────────────────────────────
// Resets the full input state buffer and extracts button/key bits
// from the raw keyboard/mouse/controller state arrays.
//
// Performs:
//   1. Clear 0x74 bytes at DAT_00702c00 (input state buffer)
//   2. If keyboard active (DAT_00702898): extract controller bits
//      from DAT_00727e84, DAT_00727e98, DAT_00727e80, DAT_00727e90
//      into individual byte flags at DAT_00702c2c..DAT_00702c39
//   3. Extract key bits from DAT_00727ed8 (arrows, modifiers)
//      into DAT_00702c01..DAT_00702c1a
//   4. Extract escape key (DAT_00702c08) with modifier check
//   5. Extract mouse button bits from DAT_00727fe0/fd8/fdc
//   6. Accumulate mouse position into DAT_00702c1c/c20 with clamping
//
// Ghidra: FUN_004adab0 (1 caller, 1 callee — memset)
void ResetInputState();             // FUN_004adab0

// ─── CheckKeyboardButton (FUN_004ae0c0) ─────────────────────────
// Keyboard-style button state check.
// Reads key state from indexed lookup tables: DAT_00745278 provides
// the DWORD index, DAT_0074527c provides the bit position.
//
// Mode (param_2):
//   0 = key NOT pressed  (bit clear in DAT_00727ea0 region)
//   1 = key pressed      (bit set in DAT_00727e80 region)
//   2 = key just pressed (bit set in DAT_00727ee0 region — edge detect)
//   3 = key held         (bit set in DAT_00727ec0 region — current state)
//
// @param param_1  Button code index into lookup tables
// @param param_2  Check mode (0=not pressed, 1=pressed, 2=edge, 3=held)
// @return true if the button matches the requested state
//
// Ghidra: FUN_004ae0c0 (3 callers, 0 callees)
bool CheckKeyboardButton(int param_1, uint32_t param_2);   // FUN_004ae0c0

// ─── CheckGamepadButton (FUN_004adfe0) ──────────────────────────
// Gamepad button / mouse scroll state check.
// Maps button codes 0x65..0x6c to bit masks (1,2,4,...,128) for
// 8 gamepad buttons. Codes 0x6d/0x6e check mouse scroll direction.
//
// Mode (param_2):
//   0 = button NOT pressed (bit clear in DAT_00727fd8 — current frame)
//   1 = button pressed     (bit set in DAT_00727fd8)
//   2 = button just pressed (bit set in DAT_00727fdc — previous frame edge)
//   3 = button held        (bit set in DAT_00727fe0 — held state)
//
// @param param_1  Button code (0x65..0x6e)
// @param param_2  Check mode
// @return true if the button matches the requested state
//
// Ghidra: FUN_004adfe0 (3 callers, 0 callees)
bool CheckGamepadButton(uint32_t param_1, uint32_t param_2);  // FUN_004adfe0

// ─── CheckAxisButton (FUN_004ade20) ─────────────────────────────
// Axis-style (analog) button check for joystick/controller axes.
// Handles two ranges:
//   - param_1 < 0xF0: Direct axis byte read from DAT_00727ef9/7f2d
//   - 0xF0..0xFE: PoV hat position ranges via DAT_00727f64/7f98
//
// The PoV hat uses quadrants with thresholds at 0x1194, 0x34bc,
// 0x57e4, 0x7b0c to map angular position to directional input.
//
// Mode (param_2):
//   0 = axis negative (analog < 0, or PoV in range)
//   1 = axis positive (analog >= 0, or PoV in range)
//   2 = axis changed  (uses both DAT_00727f64 and DAT_00727f98)
//   3 = axis center   (both axes neutral)
//
// @param param_1  Axis/button index
// @param param_2  Check mode
// @return true if the axis/button matches the requested state
//
// Ghidra: FUN_004ade20 (3 callers, 0 callees)
bool CheckAxisButton(int param_1, uint32_t param_2);        // FUN_004ade20

// ─── ProcessButtonMapping (FUN_004aeae0) ────────────────────────
// Post-scan button mapping: iterates 12 button mapping entries
// (indices 0..11) for a given controller type, dispatching to
// CheckKeyboardButton / CheckGamepadButton / CheckAxisButton based
// on button code range (<0x65, <0x6f, >=0x6f).
//
// Also processes PoV hat ranges into directional flags (DAT_0074c4a0,
// DAT_0074c49c) and writes thumbstick values to MoveCommand offsets.
//
// @param param_1  MoveCommand structure pointer
// @param param_2  Controller type index (0=other, 1=gamepad, 2=kb, 3=none)
//
// Ghidra: FUN_004aeae0 (1 caller, 5 callees)
void ProcessButtonMapping(int param_1, int param_2);         // FUN_004aeae0

// ─── ProcessAccumulatedInput (FUN_004aec80) ─────────────────────
// Processes controller axis inputs and maps them to movement commands.
// Called from TimerTick when input accumulator expires.
//
// Performs:
//   1. Determine controller type (0=none, 1=keyboard, 2=gamepad, 3=other)
//      from DAT_00702774 + 0x22c
//   2. If not in keyboard mode: scan 32 button mappings from
//      DAT_00745118 using controller-type-specific lookup
//      (dispatching to CheckKeyboardButton, CheckGamepadButton,
//       or CheckAxisButton based on button code range)
//   3. Call ProcessButtonMapping (FUN_004aeae0) for axis/PoV mapping
//   4. Process mouse X/Y/scroll axes: accumulate delta into floating
//      point accumulators (DAT_0074c498/94/90), convert to integer
//      with clamping to [-128, 127], then write to MoveCommand field
//      based on DAT_00702754/55/56 mapping (1=Turn, 2=Thrust, 3=Look, 4=Side)
//
// @param param_1  MoveCommand structure pointer (offset 0 = Turn, etc.)
//
// Ghidra: FUN_004aec80 (1 caller, 4 callees)
void ProcessAccumulatedInput(uint8_t* param_1);   // FUN_004aec80

} // namespace Giants
