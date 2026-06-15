// Giants Engine - TimerTick / Input Mapping & Controller State
// Reverse engineered from GiantsMain.exe v1.520.59
//
// FUN_004ad640 — Status: FAIL (203 lines, ~90% correct)
//   Input mapping + controller state + button bit extraction.
//   Called by ProcessGameLogic every frame.
#include <cstdlib>
#include <cstring>
#include "TimerTick.h"
#include <cstring>
#include <windows.h>

namespace Giants {

// ─── Input state globals ──────────────────────────────────────────
static uint8_t  DAT_00702c00 = 0;          // Input state buffer base
static uint8_t  DAT_00702c01 = 0;
static uint8_t  DAT_00702c02 = 0;
static uint8_t  DAT_00702c03 = 0;
static uint8_t  DAT_00702c04 = 0;
static uint8_t  DAT_00702c07 = 0;
static uint8_t  DAT_00702c33 = 0;
static uint8_t  DAT_00702c34 = 0;
static uint8_t  DAT_00702c38 = 0;
static uint8_t  DAT_00702c39 = 0;
static float    DAT_00702c1c = 0;          // Aspect ratio X
static float    DAT_00702c20 = 0;          // Aspect ratio Y
static float    DAT_00702c24 = 0;          // Aspect X backup
static float    DAT_00702c28 = 0;          // Aspect Y backup
static uint8_t  DAT_00702c08 = 0;          // Escape/quit flag
static uint8_t  DAT_00702c1a = 0;          // Input flag
static uint8_t  DAT_00702c2c = 0;          // Button bit
static uint8_t  DAT_00702c2d = 0;
static uint8_t  DAT_00702c2e = 0;
static uint8_t  DAT_00702c2f = 0;
static uint8_t  DAT_00702c30 = 0;
static uint8_t  DAT_00702c31 = 0;
static uint8_t  DAT_00702c32 = 0;
static uint8_t  DAT_00702c35 = 0;
static uint8_t  DAT_00702c36 = 0;
static uint8_t  DAT_00702c37 = 0;          // Combined button flag
static uint8_t  DAT_00702c3a = 0;
static char     DAT_00702898 = 0;          // Keyboard/mouse active flag
static uint32_t DAT_00727e80 = 0;          // Key state word
static uint32_t _DAT_00727e84 = 0;         // Key state word 2
static uint32_t _DAT_00727e90 = 0;         // Key state word 3
static uint32_t DAT_00727e98 = 0;          // Key state word 4
static uint32_t DAT_00727ec0 = 0;          // Current key state
static uint32_t DAT_00727ec4 = 0;          // Key state extended
static uint32_t DAT_00727ed8 = 0;          // Arrow/numpad key state
static uint32_t DAT_00727ee0 = 0;          // Extended key state
static uint32_t DAT_00727fd8 = 0;          // Mouse raw state
static uint32_t DAT_00727fdc = 0;          // Mouse current state
static uint32_t DAT_00727fe0 = 0;          // Mouse pressed bits
static float    DAT_007282c8 = 0.0f;       // Mouse sensitivity

// ─── Additional key state globals ───────────────────────────────
static uint32_t _DAT_00727e94 = 0;
static uint32_t _DAT_00727ed4 = 0;
static uint32_t _DAT_00727ee4 = 0;
static uint32_t _DAT_00727ef4 = 0;
static uint32_t DAT_00727f2d = 0;
static uint32_t DAT_00727fbc = 0;
static uint32_t DAT_00727fc0 = 0;
static uint32_t DAT_00727fc4 = 0;
static uint32_t DAT_00727fc8 = 0;
static uint32_t DAT_00727fcc = 0;
static uint32_t DAT_007282c4 = 0;
static uint32_t DAT_007488d0 = 0;
static uint32_t DAT_007488d4 = 0;
static uint32_t DAT_007488d8 = 0;
static uint32_t DAT_007488dc = 0;
static uint32_t DAT_007488e0 = 0;
static uint32_t DAT_0074c494 = 0;
static uint8_t  DAT_00702c05 = 0;
static uint8_t  DAT_00702c06 = 0;
static uint8_t  DAT_00702c09 = 0;
static uint8_t  DAT_00702c0a = 0;
static uint8_t  DAT_00702c0b = 0;
static uint8_t  DAT_00702c0c = 0;
static uint8_t  DAT_00702c0d = 0;
static uint8_t  DAT_00702c0e = 0;
static uint8_t  DAT_00702c0f = 0;
static uint8_t  DAT_00702c10 = 0;
static uint8_t  DAT_00702c11 = 0;
static uint8_t  DAT_00702c12 = 0;
static uint8_t  DAT_00702c13 = 0;
static uint8_t  DAT_00702c14 = 0;
static uint8_t  DAT_00702c15 = 0;
static uint8_t  DAT_00702c16 = 0;
static uint8_t  DAT_00702c17 = 0;
static uint8_t  DAT_00702c18 = 0;
static uint8_t  DAT_00702c19 = 0;
static uint8_t  DAT_00702c68 = 0;
static uint8_t  DAT_00702c6c = 0;
static uint8_t  DAT_00702c70 = 0;

// ─── Exported globals (declared extern in TimerTick.h) ──────────────
uint32_t* g_controllerState  = nullptr;  // DAT_00702774 — controller state struct ptr
uint32_t  g_controllerEnabled = 0;       // DAT_007029cc — controller enabled flag
int       g_activeController = 0;        // DAT_00702924 — active controller index
char      g_mappedAction     = '\0';     // DAT_00702c00 — current mapped action char

// ─── Forward declarations for subroutines ────────────────────────
// ResetInputState (FUN_004adab0) — defined below
// ProcessAccumulatedInput (FUN_004aec80) — defined below
// CheckKeyboardButton (FUN_004ae0c0) — defined below
// CheckGamepadButton (FUN_004adfe0) — defined below
// CheckAxisButton (FUN_004ade20) — defined below
// ProcessButtonMapping (FUN_004aeae0) — defined below

// Input mapping table: 26 entries mapping virtual key indices to action bits
// DAT_0065c830 — byte shift table (bit position per index)
// DAT_0065c898 — DWORD index table (which DWORD in key state array)
// DAT_00727ec0 — current key state DWORD array

// ─── Controller State Offsets ─────────────────────────────────────
// Controller struct (DAT_00702774) layout:
//   [0x7F] = float axis1               (DAT_00747a80)
//   [0x79] = float axis2               (DAT_00747a84)
//   [0x88] = float axis3 / state       (DAT_00747a88)
//   [0x8B] = uint  controllerType      (2=gamepad, 3=other)
//   [0x97] = uint  input accumulator   (cleared on reset)
//   [0x98] = uint  input accumulator 2 (cleared on reset)
//   [0x4B] = uint  flags              (gamepad: set bit 0x100000)
//   [0x53] = uint* flag_ptr           (other: set bit 3 on target)

// ─── State Constants ──────────────────────────────────────────────
constexpr uint32_t CONTROLLER_STATE_AXIS1    = 0x7F;  // offset into g_controllerState
constexpr uint32_t CONTROLLER_STATE_AXIS2    = 0x79;
constexpr uint32_t CONTROLLER_TYPE_GAMEPAD   = 2;
constexpr uint32_t CONTROLLER_TYPE_OTHER     = 3;
constexpr float    kInputResetThreshold      = 0.0f;  // DAT_00727e48 = 1.0f (base time scale)
constexpr int      kMaxInputMappings         = 26;    // 0x1A entries in mapping loop
constexpr int      kMinControllerIndex       = 1;
constexpr int      kMaxControllerIndex       = 13;

// ─── TimerTick Implementation (FUN_004ad640) ─────────────────────

void TimerTick()
{
    // Phase 1: Controller state query via COM vtable
    // The function first attempts to query controller state through a
    // COM object. If that fails, it falls through to DirectInput polling.

    // DAT_00702774 — controller state struct pointer
    uint32_t* controllerState = g_controllerState;

    // Check: is controller available and queryable?
    // FUN_00443f80 appears to be a COM smart-pointer getter that returns
    // a vtable-containing object into local_30.
    // TODO: Define FUN_00443f80 signature when reversing that function
    void* comObj = nullptr;  // Placeholder for local_30

    if (comObj != nullptr)
    {
        // Query state via vtable offset 0x18 (3rd method)
        // typedef bool (*QueryStateFn)(uint cookie);
        // auto queryState = reinterpret_cast<QueryStateFn>(
        //     (*reinterpret_cast<uintptr_t**>(comObj))[6]);  // vtable[6] = offset 0x18
        // bool stateOk = queryState(0);
        //
        // if (stateOk && controllerState != nullptr)
        // {
        //     // Path: controller query succeeded, set base time scale and clear accumulators
        //     g_baseTimeScale = 1.0f;       // 0x3f800000 — DAT_00727e48
        //     controllerState[0x97] = 0;    // Clear input accumulator
        //     controllerState[0x98] = 0;    // Clear input accumulator 2
        //     return;
        // }
    }

    // Phase 2: DirectInput controller polling path
    // This is the main path when COM query fails or no COM object exists.

    // Reset input state — this clears the input buffer and re-extracts
    // all button/key/mouse bits from raw state arrays.
    // In the original binary, this was called when controllerState == nullptr
    // but the function returns void, so the call is standalone.
    ResetInputState();

    // Validate controller index range
    // DAT_007029cc = controller enabled flag
    // DAT_00702924 = active controller index (must be 1..13)
    if (g_controllerEnabled == 0 &&
        (g_activeController < kMinControllerIndex || g_activeController > kMaxControllerIndex))
    {
        // Invalid controller — skip to cleanup
        return;
    }

    if (controllerState != nullptr)
    {
        // Copy controller axis values to local state
        // DAT_00747a80 = axis1 (from controller[0x7F])
        // DAT_00747a84 = axis2 (from controller[0x79])
        // DAT_00747a88 = axis2 copy (mirrored)
        // DAT_00747a8c = axis deadzone threshold (0.5f = 0x3f000000)
        // DAT_00747a90 = sensitivity multiplier (1.0f = 0x3f800000)
    }

    // Phase 3: Button-to-action mapping loop
    // Iterate over 26 (0x1A) input mapping entries. Each entry maps a
    // virtual key bit position to an action code ('A'..'Z').
    //
    // DAT_0065c830 — byte array: bit shift amount per mapping index
    // DAT_0065c898 — DWORD array: key state DWORD index per mapping index
    // DAT_00727ec0 — current keyboard/key state (256 bits = 8 DWORDs)
    //
    // For each index i in [0, 26):
    //   bitPosition = DAT_0065c830[i] & 0x1F
    //   dwordIndex  = DAT_0065c898[i]
    //   if (DAT_00727ec0[dwordIndex] & (1 << bitPosition))
    //       g_mappedAction = i + 'A'

    g_mappedAction = '\0';
    for (int i = 0; i < kMaxInputMappings; i++)
    {
        // These tables are in .rdata — they map key state bits to actions.
        // extern const uint8_t  g_keyBitTable[26];    // DAT_0065c830
        // extern const uint32_t g_keyIndexTable[26];   // DAT_0065c898
        // extern uint32_t g_keyState[8];                // DAT_00727ec0
        //
        // if (g_keyState[g_keyIndexTable[i]] & (1 << (g_keyBitTable[i] & 0x1F)))
        // {
        //     g_mappedAction = static_cast<char>(i + 'A');  // DAT_00702c00
        // }
    }

    // Phase 4: Copy input state buffers
    // Two memcpy operations copy input state from one buffer region to another.
    // PTR_DAT_00685890 = source base address for input mapping data
    // DAT_006818d8 = end of first region, DAT_006818b8 = start of second region
    // DAT_0074be2c = destination, DAT_0074be4c = counter
    //
    // memcpy(&DAT_0074be2c, PTR_DAT_00685890, size1);
    // memcpy(dest2, &DAT_006818b8, size2);
    // DAT_0074be4c = 0;

    // Phase 5: Extract button bits from controller state word
    // DAT_00727e98 — 16-bit controller button state word
    // Each bit is extracted and stored as a boolean flag.
    //
    // g_btnBit8  = (g_controllerButtons >> 8) & 1;    // DAT_00702c52
    // g_btnBit10 = (g_controllerButtons >> 10) & 1;   // DAT_00702c53 (byte 2 & 1)
    // g_btnBit11 = (g_controllerButtons >> 11) & 1;   // DAT_00702c54
    // g_btnBit13 = (g_controllerButtons >> 13) & 1;   // DAT_00702c55
    // g_btnBit9  = (g_controllerButtons >> 9) & 1;    // DAT_00702c56
    // g_btnBit17 = (g_controllerButtons >> 17) & 1;   // DAT_00702c57

    // Phase 6: Combined flag from DAT_00727e80 and _DAT_00727e90
    // g_btnCombinedFlag = 0 or 1 based on bit 29 of both state words
    // DAT_00702c58 = (DAT_00727e80 & 0x20000000) || (_DAT_00727e90 & 0x20000000)

    // Phase 7: Extended button flags from DAT_00727ec4
    // uint32_t extState = DAT_00727ec4;
    // uint8_t extByte = (extState >> 24) & 0xFF;
    // g_extBtnBit3 = (extByte >> 3) & 1;    // DAT_00702c3a
    // g_extBtnBit5 = (extByte >> 5) & 1;    // DAT_00702c61
    // g_extBtnBit6 = (extByte >> 6) & 1;    // DAT_00702c62
    //
    // Conditional: g_extBtnBit4 only set when g_btnCombinedFlag == 0
    // if (g_btnCombinedFlag == 0)
    //     g_extBtnBit4 = (extByte >> 4) & 1;    // DAT_00702c4f

    // Phase 8: Reset base time scale
    // DAT_00727e48 = 1.0f (0x3f800000) — ensures game runs at normal speed

    // Phase 9: Input accumulator management
    // g_inputTimer (DAT_00702a44) counts down. When it reaches <= 0,
    // the accumulator is armed (g_inputState = 1). If the accumulator
    // is already armed and timer expires, ProcessAccumulatedInput() is called.
    //
    // if (g_inputTimer <= 0.0f ||
    //     (g_controllerEnabled != 0 && someCondition != 0) ||
    //     g_inputTimer - someOffset > 0.0f)
    // {
    //     if (g_inputState != 0)
    //     {
    //         ProcessAccumulatedInput(nullptr);  // Process accumulated input
    //     }
    // }
    // else
    // {
    //     // Arm the accumulator
    //     g_inputState = 1;
    //     g_inputActive = reinterpret_cast<uint32_t*>(1);
    //     g_inputTimer = 0.0f;
    // }

    // Phase 10: Input reset on button press
    // If any input button is active (checked via multiple flag globals),
    // and the accumulator is not active (g_inputActive == nullptr),
    // then zero out the entire input buffer region.
    //
    // The zeroed region spans DAT_006fd5a0 to DAT_006feea0 (0x1890 bytes)
    // plus 25 DWORDs at DAT_006feea0..DAT_006feefc.
    //
    // Then reset state flags:
    //   memset(&g_mappedAction, 0, 0x74);  // Clear DAT_00702c00..DAT_00702c73
    //   Restore saved aspect ratio from local_28/local_24
    //   g_inputState = 0;
    //   g_inputActive = nullptr;
    //
    // If controller type is gamepad (2), set flag 0x100000 on controller
    // If controller type is other (3), set bit 3 via indirect pointer
    //
    // Controller-specific flag setting after input reset:
    // if (g_controllerState != nullptr)
    // {
    //     uint32_t ctrlType = g_controllerState[0x8B];
    //     if (ctrlType == CONTROLLER_TYPE_GAMEPAD)
    //         g_controllerState[0x4B] |= 0x100000;
    //     else if (ctrlType == CONTROLLER_TYPE_OTHER)
    //     {
    //         uint32_t* target = reinterpret_cast<uint32_t*>(g_controllerState[0x53]);
    //         *target |= 8;
    //     }
    // }
}

// ─── ResetInputState (FUN_004adab0) ──────────────────────────────
// Ghidra: FUN_004adab0 (1 caller, 1 callee — memset)
// Purpose: Resets the full input state buffer and extracts button/key bits
//   from the raw keyboard/mouse/controller state arrays.
// Original:
// void FUN_004adab0(void)
// {
//   float fVar1 = DAT_00702c1c;
//   float fVar2 = DAT_00702c20;
//   memset(&DAT_00702c00, 0, 0x74);
//   DAT_00702c24 = fVar1;
//   DAT_00702c28 = fVar2;
//   if (DAT_00702898 != '\0') {
//     DAT_00702c2c = (_DAT_00727e84 & 0x400400) != 0;
//     DAT_00702c2d = (byte)(DAT_00727e98 >> 0x12) & 1;
//     DAT_00702c2e = (byte)(DAT_00727e98 >> 7) & 1;
//     DAT_00702c2f = (byte)(DAT_00727e98 >> 9) & 1;
//     DAT_00702c31 = (byte)(DAT_00727e98 >> 0x13) & 1;
//     DAT_00702c32 = (byte)(DAT_00727e98 >> 0xf) & 1;
//     DAT_00702c30 = (byte)(DAT_00727e98 >> 0x11) & 1;
//     if (((DAT_00727e80 & 0x20000000) != 0) || (DAT_00702c37 = 0,
//         (_DAT_00727e90 & 0x20000000) != 0)) { DAT_00702c37 = 1; }
//     DAT_00702c35 = (byte)(DAT_00727ec0 >> 0x16) & 1;
//     DAT_00702c36 = (byte)(DAT_00727ec0 >> 0x13) & 1;
//     DAT_00702c38 = (byte)(DAT_00727e80 >> 0x14) & 1;
//     DAT_00702c39 = (byte)(DAT_00727e80 >> 0x15) & 1;
//     bVar3 = (byte)(DAT_00727e80 >> 0x18);
//     DAT_00702c33 = bVar3 >> 2 & 1;
//     DAT_00702c34 = bVar3 >> 3 & 1;
//   }
//   DAT_00702c01 = (byte)(DAT_00727ed8 >> 8) & 1;
//   DAT_00702c02 = DAT_00727ed8._2_1_ & 1;
//   DAT_00702c03 = (byte)(DAT_00727ed8 >> 0xb) & 1;
//   DAT_00702c04 = (byte)(DAT_00727ed8 >> 0xd) & 1;
//   DAT_00702c07 = (byte)(DAT_00727ec0 >> 1) & 1;
//   if (((((_DAT_00727e84 & 0x1000000) == 0) && ((_DAT_00727e94 & 0x1000000) == 0)) &&
//       ((_DAT_00727ee4 & 0x1000000) == 0)) &&
//      ((((_DAT_00727ef4 & 0x1000000) == 0 && ((DAT_00727ec4 & 0x1000000) == 0)) &&
//       ((_DAT_00727ed4 & 0x1000000) == 0)))) {
//     DAT_00702c08 = (byte)(DAT_00727ec0 >> 0x1c) & 1;
//   } else { DAT_00702c08 = 0; }
//   DAT_00702c09 = (byte)((uint)DAT_00727ee0 >> 0x1c) & 1;
//   DAT_00702c19 = (byte)(DAT_00727ec0 >> 0xe) & 1;
//   DAT_00702c13 = (byte)(DAT_00727ed8 >> 0x13) & 1;
//   DAT_00702c1a = (byte)(DAT_00727ec0 >> 0xf) & 1;
//   DAT_00702c14 = (byte)(DAT_00727ed8 >> 0x12) & 1;
//   DAT_00702c15 = (byte)(DAT_00727ed8 >> 7) & 1;
//   DAT_00702c16 = (byte)(DAT_00727ed8 >> 0xf) & 1;
//   DAT_00702c17 = (byte)(DAT_00727ed8 >> 9) & 1;
//   bVar5 = (byte)DAT_00727fe0;
//   DAT_00702c18 = (byte)(DAT_00727ed8 >> 0x11) & 1;
//   DAT_00702c0b = bVar5 & 1;
//   bVar4 = (byte)DAT_00727fdc;
//   DAT_00702c0a = bVar4 & 1;
//   bVar3 = (byte)DAT_00727fd8;
//   DAT_00702c0c = bVar3 & 1;
//   DAT_00702c0e = bVar5 & 2;
//   DAT_00702c11 = bVar5 & 4;
//   DAT_00702c0d = bVar4 & 2;
//   DAT_00702c10 = bVar4 & 4;
//   DAT_00702c12 = bVar3 & 4;
//   DAT_00702c0f = bVar3 & 2;
//   DAT_00702c05 = (byte)(DAT_00727ec4 >> 0x13) & 1;
//   DAT_00702c06 = (byte)(DAT_00727ec4 >> 0x14) & 1;
//   DAT_00702c68 = (float)DAT_00727fbc;
//   DAT_00702c1c = (float)DAT_00727fbc + fVar1;
//   DAT_00702c6c = (float)DAT_00727fc0;
//   DAT_00702c70 = (float)DAT_00727fc4;
//   DAT_00702c20 = fVar2 - (float)DAT_00727fc0;
//   if (DAT_00702c1c < 0.0) DAT_00702c1c = 0.0;
//   if ((float)DAT_007282c4 < DAT_00702c1c) DAT_00702c1c = (float)DAT_007282c4;
//   if (DAT_00702c20 < 0.0) DAT_00702c20 = 0.0;
//   if ((float)DAT_007282c8 < DAT_00702c20) DAT_00702c20 = (float)DAT_007282c8;
// }

// ResetInputState (FUN_004adab0) — REAL decompiled body. Clears the input flag
// block (DAT_00702c00, 0x74 bytes) then re-extracts all button/key/mouse bits
// from the processed state arrays (DAT_00727e80+). This is stage 3 of the input
// pipeline (raw→processed→flags). NOTE: stage 2 (ProcessMouseInput Phase-1 grid
// transfer 00727e60→00727e80+) and global unification across Input.cpp are
// needed for the flags to reflect live input; the body is faithful regardless.
void ResetInputState()
{
    float fVar1 = DAT_00702c1c;   // aspect X (preserved across clear)
    float fVar2 = DAT_00702c20;   // aspect Y
    // Original: memset(&DAT_00702c00, 0, 0x74) — a contiguous 0x74-byte flag
    // block. In the recomp these are separate statics (referenced across ~10
    // files), so a real memset would overflow BSS. Zero them explicitly instead.
    g_mappedAction = 0;
    DAT_00702c01 = 0; DAT_00702c02 = 0; DAT_00702c03 = 0; DAT_00702c04 = 0;
    DAT_00702c05 = 0; DAT_00702c06 = 0; DAT_00702c07 = 0; DAT_00702c08 = 0;
    DAT_00702c09 = 0; DAT_00702c0a = 0; DAT_00702c0b = 0; DAT_00702c0c = 0;
    DAT_00702c0d = 0; DAT_00702c0e = 0; DAT_00702c0f = 0; DAT_00702c10 = 0;
    DAT_00702c11 = 0; DAT_00702c12 = 0; DAT_00702c13 = 0; DAT_00702c14 = 0;
    DAT_00702c15 = 0; DAT_00702c16 = 0; DAT_00702c17 = 0; DAT_00702c18 = 0;
    DAT_00702c19 = 0; DAT_00702c1a = 0;
    DAT_00702c2c = 0; DAT_00702c2d = 0; DAT_00702c2e = 0; DAT_00702c2f = 0;
    DAT_00702c30 = 0; DAT_00702c31 = 0; DAT_00702c32 = 0;
    DAT_00702c33 = 0; DAT_00702c34 = 0; DAT_00702c35 = 0; DAT_00702c36 = 0;
    DAT_00702c37 = 0; DAT_00702c38 = 0; DAT_00702c39 = 0; DAT_00702c3a = 0;
    DAT_00702c68 = 0; DAT_00702c6c = 0; DAT_00702c70 = 0;
    DAT_00702c24 = fVar1;
    DAT_00702c28 = fVar2;
    if (DAT_00702898 != '\0') {  // keyboard/mouse active flag
        DAT_00702c2c = (_DAT_00727e84 & 0x400400) != 0;
        DAT_00702c2d = (uint8_t)(DAT_00727e98 >> 0x12) & 1;
        DAT_00702c2e = (uint8_t)(DAT_00727e98 >> 7) & 1;
        DAT_00702c2f = (uint8_t)(DAT_00727e98 >> 9) & 1;
        DAT_00702c31 = (uint8_t)(DAT_00727e98 >> 0x13) & 1;
        DAT_00702c32 = (uint8_t)(DAT_00727e98 >> 0xf) & 1;
        DAT_00702c30 = (uint8_t)(DAT_00727e98 >> 0x11) & 1;
        DAT_00702c37 = ((DAT_00727e80 & 0x20000000) != 0 || (_DAT_00727e90 & 0x20000000) != 0) ? 1 : 0;
        DAT_00702c35 = (uint8_t)(DAT_00727ec0 >> 0x16) & 1;
        DAT_00702c36 = (uint8_t)(DAT_00727ec0 >> 0x13) & 1;
        DAT_00702c38 = (uint8_t)(DAT_00727e80 >> 0x14) & 1;
        DAT_00702c39 = (uint8_t)(DAT_00727e80 >> 0x15) & 1;
        uint8_t bVar3 = (uint8_t)(DAT_00727e80 >> 0x18);
        DAT_00702c33 = bVar3 >> 2 & 1;
        DAT_00702c34 = bVar3 >> 3 & 1;
    }
    DAT_00702c01 = (uint8_t)(DAT_00727ed8 >> 8) & 1;
    DAT_00702c02 = (uint8_t)(DAT_00727ed8 >> 0x10) & 1;   // _2_1_ byte
    DAT_00702c03 = (uint8_t)(DAT_00727ed8 >> 0xb) & 1;
    DAT_00702c04 = (uint8_t)(DAT_00727ed8 >> 0xd) & 1;
    DAT_00702c07 = (uint8_t)(DAT_00727ec0 >> 1) & 1;
    if ((((_DAT_00727e84 & 0x1000000) == 0) && ((_DAT_00727e94 & 0x1000000) == 0)) &&
        ((_DAT_00727ee4 & 0x1000000) == 0) &&
        (((((_DAT_00727ef4 & 0x1000000) == 0) && ((DAT_00727ec4 & 0x1000000) == 0)) &&
          ((_DAT_00727ed4 & 0x1000000) == 0)))) {
        DAT_00702c08 = (uint8_t)(DAT_00727ec0 >> 0x1c) & 1;
    } else {
        DAT_00702c08 = 0;
    }
    DAT_00702c09 = (uint8_t)((uint32_t)DAT_00727ee0 >> 0x1c) & 1;
    DAT_00702c19 = (uint8_t)(DAT_00727ec0 >> 0xe) & 1;
    DAT_00702c13 = (uint8_t)(DAT_00727ed8 >> 0x13) & 1;
    DAT_00702c1a = (uint8_t)(DAT_00727ec0 >> 0xf) & 1;
    DAT_00702c14 = (uint8_t)(DAT_00727ed8 >> 0x12) & 1;
    DAT_00702c15 = (uint8_t)(DAT_00727ed8 >> 7) & 1;
    DAT_00702c16 = (uint8_t)(DAT_00727ed8 >> 0xf) & 1;
    DAT_00702c17 = (uint8_t)(DAT_00727ed8 >> 9) & 1;
    uint8_t bVar5 = (uint8_t)DAT_00727fe0;   // mouse held state
    DAT_00702c18 = (uint8_t)(DAT_00727ed8 >> 0x11) & 1;
    DAT_00702c0b = bVar5 & 1;
    uint8_t bVar4 = (uint8_t)DAT_00727fdc;   // mouse released edge
    DAT_00702c0a = bVar4 & 1;
    uint8_t bVar3b = (uint8_t)DAT_00727fd8;  // mouse current
    DAT_00702c0c = bVar3b & 1;
    DAT_00702c0e = bVar5 & 2;
    DAT_00702c11 = bVar5 & 4;
    DAT_00702c0d = bVar4 & 2;
    DAT_00702c10 = bVar4 & 4;
    DAT_00702c12 = bVar3b & 4;
    DAT_00702c0f = bVar3b & 2;
    DAT_00702c05 = (uint8_t)(DAT_00727ec4 >> 0x13) & 1;
    DAT_00702c06 = (uint8_t)(DAT_00727ec4 >> 0x14) & 1;
    DAT_00702c68 = (float)(int32_t)DAT_00727fbc;
    DAT_00702c1c = (float)(int32_t)DAT_00727fbc + fVar1;
    DAT_00702c6c = (float)(int32_t)DAT_00727fc0;
    DAT_00702c70 = (float)(int32_t)DAT_00727fc4;
    DAT_00702c20 = fVar2 - (float)(int32_t)DAT_00727fc0;
    if (DAT_00702c1c < 0.0f) DAT_00702c1c = 0.0f;
    if ((float)DAT_007282c4 < DAT_00702c1c) DAT_00702c1c = (float)DAT_007282c4;
    if (DAT_00702c20 < 0.0f) DAT_00702c20 = 0.0f;
    if ((float)DAT_007282c8 < DAT_00702c20) DAT_00702c20 = (float)DAT_007282c8;
}


// ─── CheckKeyboardButton (FUN_004ae0c0) ─────────────────────────
// Ghidra: FUN_004ae0c0 (3 callers, 0 callees)
// Purpose: Keyboard-style button state check using indexed lookup tables.
//   DAT_00745278 provides the DWORD index, DAT_0074527c provides the
//   bit position for the key state arrays.
// Original:
// bool __fastcall FUN_004ae0c0(int param_1, undefined4 param_2)
// {
//   uint uVar1;
//   switch(param_2) {
//   case 0:
//     uVar1 = *(uint *)(&DAT_00727ea0 + (&DAT_00745278)[param_1 * 10] * 4) &
//             1 << ((byte)(&DAT_0074527c)[param_1 * 10] & 0x1f);
//     break;
//   case 1:
//     return (1 << ((byte)(&DAT_0074527c)[param_1 * 10] & 0x1f) &
//            (&DAT_00727e80)[(&DAT_00745278)[param_1 * 10]]) != 0;
//   case 2:
//     uVar1 = (&DAT_00727ee0)[(&DAT_00745278)[param_1 * 10]] &
//             1 << ((byte)(&DAT_0074527c)[param_1 * 10] & 0x1f);
//     break;
//   case 3:
//     uVar1 = (&DAT_00727ec0)[(&DAT_00745278)[param_1 * 10]] &
//             1 << ((byte)(&DAT_0074527c)[param_1 * 10] & 0x1f);
//     break;
//   default: goto switchD_004ae0c5_default;
//   }
//   if (uVar1 != 0) return true;
// switchD_004ae0c5_default:
//   return false;
// }

// STUB: bool CheckKeyboardButton(int param_1, uint32_t param_2) � DAT_ names need header mapping
bool CheckKeyboardButton(int, uint32_t) { return false; }


// ─── CheckGamepadButton (FUN_004adfe0) ──────────────────────────
// Ghidra: FUN_004adfe0 (3 callers, 0 callees)
// Purpose: Gamepad button / mouse scroll state check.
//   Maps button codes 0x65..0x6c to bit masks for 8 gamepad buttons.
//   Codes 0x6d/0x6e check mouse scroll direction.
// Original:
// bool __fastcall FUN_004adfe0(undefined4 param_1, undefined4 param_2)
// {
//   uint uVar2 = 0;
//   switch(param_1) {
//   case 0x65: uVar2 = 1;    break;
//   case 0x66: uVar2 = 2;    break;
//   case 0x67: uVar2 = 4;    break;
//   case 0x68: uVar2 = 8;    break;
//   case 0x69: uVar2 = 0x10; break;
//   case 0x6a: uVar2 = 0x20; break;
//   case 0x6b: uVar2 = 0x40; break;
//   case 0x6c: uVar2 = 0x80; break;
//   case 0x6d: return (0 < DAT_00727fc4);   // scroll up
//   case 0x6e: return (DAT_00727fc4 < 0);   // scroll down
//   }
//   switch(param_2) {
//   case 0: return (DAT_00727fd8 & uVar2) == 0;  // not pressed
//   case 1: return (DAT_00727fd8 & uVar2) != 0;  // pressed (current)
//   case 2: return (DAT_00727fdc & uVar2) != 0;  // edge detect (previous frame)
//   case 3: return (DAT_00727fe0 & uVar2) != 0;  // held state
//   default: return false;
//   }
// }

// STUB: bool CheckGamepadButton(uint32_t param_1, uint32_t param_2) � DAT_ names need header mapping
bool CheckGamepadButton(uint32_t, uint32_t) { return false; }


// ─── CheckAxisButton (FUN_004ade20) ─────────────────────────────
// Ghidra: FUN_004ade20 (3 callers, 0 callees)
// Purpose: Axis-style (analog) button check for joystick/controller axes
//   and PoV hat. Two ranges: direct axis byte (< 0xF0) and PoV quadrant
//   (0xF0..0xFE) using angular thresholds.
// Original:
// bool __fastcall FUN_004ade20(int param_1, undefined4 param_2)
// {
//   char cVar1; uint uVar2,uVar3,uVar4,uVar5,uVar6,uVar7;
//   if (param_1 < 0xf0) {
//     switch(param_2) {
//     case 0: return -1 < (char)(&DAT_00727ef9)[param_1];
//     case 1: cVar1 = (&DAT_00727ef9)[param_1]; break;
//     case 2: if ((char)(&DAT_00727ef9)[param_1] < '\0') return false;
//             cVar1 = (&DAT_00727f2d)[param_1]; break;
//     case 3: if (-1 < (char)(&DAT_00727ef9)[param_1]) return false;
//             if (-1 < (char)(&DAT_00727f2d)[param_1]) return true;
//             return false;
//     default: return false;
//     }
//     return cVar1 < '\0';
//   }
//   if (0xfe < param_1) return false;
//   // PoV hat quadrant logic with thresholds: 0x1194, 0x34bc, 0x57e4, 0x7b0c
//   uVar5 = (param_1 - 0xf0) & 0x3;  // quadrant index 0..3
//   // ... quadrant boundary calculation and range checks ...
// }

// STUB: bool CheckAxisButton(int param_1, uint32_t param_2) � DAT_ names need header mapping
bool CheckAxisButton(int, uint32_t) { return false; }


// ─── ProcessButtonMapping (FUN_004aeae0) ────────────────────────
// Ghidra: FUN_004aeae0 (1 caller, 5 callees)
// Purpose: Post-scan button mapping: iterates 12 button mapping entries
//   for a given controller type, dispatching to CheckKeyboardButton /
//   CheckGamepadButton / CheckAxisButton based on button code range.
//   Also processes PoV hat ranges into directional flags and writes
//   thumbstick values to MoveCommand offsets.
// Original:
// void __fastcall FUN_004aeae0(int param_1, int param_2)
// {
//   int iVar5 = 0;
//   iVar4 = DAT_007488d0;
//   iVar6 = DAT_007488d4;
//   do {
//     if ((DAT_00682204 == -1) || (...) {  // button applicability check
//       if ((byte)(&DAT_00745158)[(param_2 * 0x2c + iVar5) * 2] < 0x65)
//         iVar3 = FUN_004ae0c0();
//       else if ((byte)(&DAT_00745158)[(param_2 * 0x2c + iVar5) * 2] < 0x6f)
//         iVar3 = FUN_004adfe0();
//       else iVar3 = FUN_004ade20();
//       if (iVar3 != 0) FUN_004ae9b0();
//     }
//     iVar5++;
//   } while (iVar5 < 0xc);
//   // PoV hat directional flags
//   if ((DAT_00727f64 < 0x1195) || ((0x7b0b < DAT_00727f64 && ...)))
//     DAT_0074c4a0 = 1;
//   else if ((DAT_00727f64 < 0x34bc) || (0x57e4 < DAT_00727f64))
//     DAT_0074c4a0 = 0;
//   else DAT_0074c4a0 = -1;
//   // ... similar for DAT_0074c49c ...
//   FUN_004ae170();
//   // Thumbstick values
//   if (DAT_00727fcc == -0x17) *(byte*)(param_1 + 2) = 0x20;
//   else if (DAT_00727fcc == 0x19) *(byte*)(param_1 + 2) = 0xe0;
//   if (DAT_00727fc8 == -0x17) *(byte*)(param_1 + 3) = 0x20;
//   else if (DAT_00727fc8 == 0x19) *(byte*)(param_1 + 3) = 0xe0;
// }

// STUB: void ProcessButtonMapping(int param_1, int param_2) � DAT_ names need header mapping
void ProcessButtonMapping(int, int) {}


// ─── ProcessAccumulatedInput (FUN_004aec80) ─────────────────────
// Ghidra: FUN_004aec80 (1 caller, 4 callees — CheckKeyboardButton,
//   CheckGamepadButton, CheckAxisButton, ProcessButtonMapping)
// Purpose: Processes controller button mappings and mouse axis inputs,
//   converting them to movement commands. Called from TimerTick when
//   input accumulator expires.
// Original:
// void __fastcall FUN_004aec80(undefined1 *param_1)
// {
//   *(uint*)(param_1 + 4) = 0;      // Clear action flags
//   // Determine controller type: 0=other, 1=gamepad, 2=keyboard, 3=none
//   iVar6 = 3;
//   if (DAT_00702774 != 0) {
//     if (*(int*)(DAT_00702774 + 0x22c) == 3) iVar6 = 0;
//     else if (*(int*)(DAT_00702774 + 0x22c) == 2) iVar6 = 1;
//     else if (*(int*)(DAT_00702774 + 0x22c) == 1) iVar6 = 2;
//   }
//   // Button scan: 32 entries, dispatch to check functions
//   if (DAT_00702898 == '\0') {
//     uVar7 = 0; iVar5 = DAT_00702774;
//     do {
//       uint8_t code = (&DAT_00745118)[(iVar6 * 0x2c + uVar7) * 2];
//       if (code < 0x65)      iVar4 = FUN_004ae0c0();
//       else if (code < 0x6f) iVar4 = FUN_004adfe0();
//       else                  iVar4 = FUN_004ade20();
//       if (iVar4 != 0) *(uint*)(param_1+4) |= 1 << (uVar7 & 0x1f);
//       uVar7++;
//     } while (uVar7 < 0x20);
//   }
//   FUN_004aeae0(param_1, iVar6);
//   // Mouse axis processing with accumulation and clamping
//   // ... (see implementation below)
// }

// STUB: void ProcessAccumulatedInput(uint8_t* param_1) � DAT_ names need header mapping
void ProcessAccumulatedInput(uint8_t*) {}


} // namespace Giants
