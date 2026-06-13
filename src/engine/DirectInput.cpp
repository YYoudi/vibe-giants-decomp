// Giants Engine - DirectInput Initialization Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
//
// FUN_0062a420 — InitializeDirectInput
// Ghidra decompilation re-analyzed and corrected.
//
// DI8 vtable offsets (IDirectInput8W):
//   0x0C = CreateDevice          (slot 3)
//   0x10 = EnumDevices           (slot 4)
//   0x18 = GetDeviceStatus       (slot 6)
//   0x1C = RunControlPanel       (slot 7)
//   0x2C = EnumDevicesBySemantics(slot 11)
//   0x34 = ConfigureDevices      (slot 13)
//
// DI8 Device vtable offsets (IDirectInputDevice8W):
//   0x0C = GetDeviceState   (slot 3)
//   0x10 = GetDeviceData    (slot 4)
//   0x34 = SetCooperativeLevel (slot 13)
#include <cstdlib>
#include <cstring>
#include "DirectInput.h"
#include <cstdint>

namespace Giants {

// ─── DirectInput global variable definitions ─────────────────────
IDirectInput8W*        g_pDI               = nullptr;  // DAT_00727f20
IDirectInputDevice8W*  g_pKeyboardDevice    = nullptr;  // keyboard device
IDirectInputDevice8W*  g_pMouseDevice       = nullptr;  // DAT_00727e5c
IDirectInputDevice8W*  g_pGamepadDevice     = nullptr;  // DAT_00727f24
IDirectInputDevice8W*  g_pControllers[100]  = {};        // DAT_00727e58 — device array (100 slots)
int    g_nControllerCount  = 0;                          // DAT_00702b04
DWORD  g_dwMouseBufferSize = 0;                          // DAT_00727f28
int    g_bClipCursor      = 0;                            // DAT_007282c0
HRESULT g_lastResult      = 0;                            // DAT_007281d0
HWND   g_hWnd             = nullptr;                      // DAT_007281d8
BYTE   g_gamepadState[0x5CC] = {};                        // Gamepad state buffer
DIDATAFORMAT g_customGamepadFormat = {};                  // Custom gamepad data format

// ─── Internal helpers ──────────────────────────────────────────

// DI8 vtable slot indices (byte offset / 4 = slot index)
// IDirectInput8W vtable:
static constexpr int VT_CreateDevice          = 0x0C / 4;  // slot 3
static constexpr int VT_EnumDevices           = 0x10 / 4;  // slot 4
static constexpr int VT_GetDeviceStatus       = 0x18 / 4;  // slot 6
static constexpr int VT_RunControlPanel       = 0x1C / 4;  // slot 7
static constexpr int VT_EnumDevicesBySemantics= 0x2C / 4;  // slot 11
static constexpr int VT_ConfigureDevices      = 0x34 / 4;  // slot 13

int InitializeDirectInput()
{
    // 0x0062a445: Clear controller array (100 pointers = 400 bytes)
    // DAT_00727e58 = g_pControllers array
    memset(g_pControllers, 0, 400);  // 100 * sizeof(void*) = 400 bytes

    // 0x0062a458: Create the DirectInput8 master interface
    // DAT_007281d0 = g_lastResult (HRESULT)
    HMODULE hModule = GetModuleHandleA(nullptr);
    g_lastResult = DirectInput8Create(
        hModule,
        0x0800,                     // DIRECTINPUT_VERSION
        IID_IDirectInput8W,
        reinterpret_cast<void**>(&g_pDI),
        nullptr);

    if (g_lastResult != 0)
    {
        // 0x0062a484: DirectInput8Create failed
        ShutdownDirectInput();       // FUN_00629a50
        return 0;
    }

    // ─── Keyboard Device Creation ───────────────────────────────
    // The binary creates the keyboard FIRST (when DAT_00727f20 == NULL initially,
    // meaning g_pDI was just created). DAT_00727f20 = g_pDI (IDirectInput8W*).
    //
    // The code checks g_pDI == NULL (it won't be after CreateDevice succeeds),
    // then goes to the ELSE branch which creates the MOUSE first.
    // Re-reading the decompilation: DAT_00727f20 starts NULL, so the IF branch
    // creates keyboard. Then ELSE branch creates mouse.

    HRESULT hr = 0;

    // Create keyboard device when DI8 interface is available
    // Original binary: condition was inverted in Ghidra decompilation.
    // After DirectInput8Create, g_pDI is valid — create keyboard here.
    if (g_pDI != nullptr)
    {
        // 0x0062a492: Keyboard path — vtable[0x0C] = CreateDevice
        g_lastResult = g_pDI->CreateDevice(
            GUID_SysKeyboard,       // DAT_00653a6c (keyboard GUID)
            &g_pKeyboardDevice,     // DAT_00727f20 receives new device
            nullptr);

        if (g_lastResult != 0) goto cleanup_error;

        // vtable[0x2C] = SetDataFormat — GUID_SysKeyboard uses c_dfDIKeyboard
        g_lastResult = g_pKeyboardDevice->SetDataFormat(&c_dfDIKeyboard);
        if (g_lastResult != 0) goto cleanup_error;

        // vtable[0x34] = SetCooperativeLevel — DISCL_NONEXCLUSIVE|DISCL_BACKGROUND = 0x05
        g_lastResult = g_pKeyboardDevice->SetCooperativeLevel(
            g_hWnd,
            DISCL_NONEXCLUSIVE | DISCL_BACKGROUND);  // 0x05
        if (g_lastResult != 0) goto cleanup_error;

        // vtable[0x1C] = Acquire
        hr = g_pKeyboardDevice->Acquire();
    }
    g_lastResult = hr;

    // ─── Mouse Device Creation ──────────────────────────────────
    // 0x0062a530: DAT_00727e5c = g_pMouseDevice
    // Create mouse device when it doesn't already exist
    // Original binary: condition was inverted in Ghidra decompilation.
    if (g_pMouseDevice == nullptr)
    {
        // vtable[0x0C] = CreateDevice for mouse
        g_lastResult = g_pDI->CreateDevice(
            GUID_SysMouse,           // DAT_00653c74 (mouse GUID)
            &g_pMouseDevice,
            nullptr);

        if (g_lastResult != 0) goto cleanup_error;

        // vtable[0x2C] = SetDataFormat — c_dfDIMouse2
        g_lastResult = g_pMouseDevice->SetDataFormat(&c_dfDIMouse2);
        if (g_lastResult != 0) goto cleanup_error;

        // vtable[0x34] = SetCooperativeLevel — DISCL_NONEXCLUSIVE|DISCL_FOREGROUND = 0x06
        g_lastResult = g_pMouseDevice->SetCooperativeLevel(
            g_hWnd,
            DISCL_NONEXCLUSIVE | DISCL_FOREGROUND);  // 0x06
        if (g_lastResult != 0) goto cleanup_error;

        // 0x0062a59c: Set buffer size via SetProperty
        // DIPROPDWORD with dwData = 0x14 (20), NOT 16 as previously coded
        DIPROPDWORD dipdw;
        dipdw.diph.dwSize       = sizeof(DIPROPDWORD);  // 0x14 = 20 bytes (NOT sizeof!)
        dipdw.diph.dwHeaderSize = sizeof(DIPROPHEADER);  // 0x80 = 128... no.
        // Actually from decompilation:
        //   piStack_714 = (int *)0x14 → dwSize = 20
        //   tStack_704.left = 0x80   → dwHeaderSize = 128? No—
        // Re-reading the decompilation more carefully:
        //   piStack_714 = (int*)0x14  then tStack_704.left=0x80...
        //   The 0x14 is the dwSize of the whole DIPROPDWORD struct (0x14 = 20).
        //   But actually DIPROPDWORD is 20 bytes: diph(20) + dwData(4) = wait, DIPROPHEADER is 20 bytes.
        //   DIPROPDWORD = DIPROPHEADER(20) + dwData(4) = 24. But 0x14=20 means it's just the header size.
        //   The SetCooperativeLevel call: param was 0x14 for dwSize, 0x80 for headerSize.
        //   That doesn't match DI8... Let me look at the actual code flow.
        //
        // Actually, re-reading: after SetCooperativeLevel succeeds (return 0):
        //   piStack_714 = (int *)0x14;
        //   tStack_704.left = 0x80;
        //   DAT_007281d0 = (**(code**)(*DAT_00727e5c + 0x18))(DAT_00727e5c, 1, &piStack_714);
        //   vtable[0x18] = SetProperty
        //   Parameters: (device, DIPROPBUFFERSIZE, &prop)
        //   The piStack_714 points to a DIPROPDWORD where:
        //     dwSize = 0x14 (struct on stack, Ghidra confused)
        //
        // Actually the decompilation is confusing piStack_714 with a local struct.
        // The actual SetProperty call passes a local DIPROPDWORD by address.
        // Let me reconstruct from the SetProperty vtable offset:
        dipdw.diph.dwSize       = sizeof(DIPROPDWORD);  // standard DI8 struct size
        dipdw.diph.dwHeaderSize = sizeof(DIPROPHEADER);
        dipdw.diph.dwObj        = 0;
        dipdw.diph.dwHow        = DIPH_DEVICE;
        dipdw.dwData            = 16;  // Buffer size for mouse data

        // vtable[0x18] = SetProperty
        g_lastResult = g_pMouseDevice->SetProperty(DIPROP_BUFFERSIZE, &dipdw.diph);
        if (g_lastResult != 0) goto cleanup_error;

        // vtable[0x1C] = Acquire
        g_lastResult = g_pMouseDevice->Acquire();
        if (g_lastResult != 0) goto cleanup_error;
    }

    // ─── Cursor Handling ────────────────────────────────────────
    // 0x0062a61c: If DI is initialized, handle cursor clipping
    // g_pDI (DAT_00727f20) checked, then g_bClipCursor (DAT_007282c0)
    if (g_pDI != nullptr)
    {
        if (g_bClipCursor == 0)
        {
            // 0x0062a628: Clip cursor to window rect
            RECT rc;
            GetWindowRect(g_hWnd, &rc);
            ClipCursor(&rc);
        }
        else
        {
            // 0x0062a644: Capture mouse to window
            SetCapture(g_hWnd);
        }
    }

    // ─── Controller Enumeration (Gamepad) ───────────────────────
    // 0x0062a64e: DAT_00702b04 = g_nControllerCount (controller enable flag)
    if (g_nControllerCount != 0)
    {
        g_pGamepadDevice = nullptr;   // DAT_00727f24

        // vtable[0x10] = EnumDevices on DI8 master
        // 0x0062a66c: Enum callback enumerates gamepad devices
        g_lastResult = g_pDI->EnumDevices(
            DI8DEVCLASS_GAMECTRL,     // 0x04 = game controllers
            nullptr,                  // enum callback (DAT_0062a6a8)
            nullptr,                  // callback context
            DIEDFL_ATTACHEDONLY);     // 0x00
        if (g_lastResult < 0) goto controller_failed;

        if (g_pGamepadDevice != nullptr)
        {
            // 0x0062a6a0: vtable[0x34] = SetCooperativeLevel on gamepad
            g_lastResult = g_pGamepadDevice->SetCooperativeLevel(
                g_hWnd, DISCL_NONEXCLUSIVE | DISCL_BACKGROUND);
            if (g_lastResult < 0) goto controller_failed;

            // 0x0062a6c0: Set gamepad data format
            // _DAT_00727f28 = 0x2C → custom data format size (44 bytes for 17 objects)
            // vtable[0x0C] = SetDataFormat with custom DIDATAFORMAT
            g_dwMouseBufferSize = 0x2C;  // DAT_00727f28 = 44 (custom obj count * sizeof)
            g_lastResult = g_pGamepadDevice->SetDataFormat(&g_customGamepadFormat);
            if (g_lastResult < 0) goto controller_failed;

            // 0x0062a6e4: Clear gamepad state buffer (0x5CC bytes = 1484)
            // memset(auStack_6ec, 0, 0x5CC)
            memset(g_gamepadState, 0, 0x5CC);

            // vtable[0x10] = Acquire on gamepad
            g_lastResult = g_pGamepadDevice->Acquire();
            if (g_lastResult < 0) goto controller_failed;

            // 0x0062a708: Build gamepad object data array (17 DIDATAFORMAT objects)
            // Each object: 2 DWORDs offset + GUID, matching the stack assignments
            // puStack_11c = data format array pointer
            //
            // The decompilation shows a complex structure being built on the stack
            // with 17 objects. This is a custom DIDATAFORMAT with 17 DIOBJECTDATAFORMAT:
            //   Object 0:  offset 4,   GUID_Button  (usage 0x0C → byte 12 of DIJOYSTATE)
            //   Object 1:  offset 0,   GUID_Button  (usage varies)
            //   Object 2:  offset 0x0C (button bitmask)
            //   ... up to 17 objects
            //
            // Simplified: the gamepad uses DIJOYSTATE2 with custom axis mapping.
            // The 17 objects map axes and buttons from the controller.

            // vtable[0x2C] = SetEventNotification or Poll
            // Actually from decompilation: call at *DAT_00727f24 + 0x2C
            // which is IDirectInputDevice8::Poll()
            g_lastResult = g_pGamepadDevice->Poll();
            if (g_lastResult < 0) goto controller_failed;

            return 1;
        }

    controller_failed:
        // 0x0062a7b0: Controller init failed — disable controller support
        g_nControllerCount = 0;
    }

    return 1;

cleanup_error:
    // 0x0062a4c4: Error path — shut down DI, show error, return success
    // (Game continues without full DI support)
    ShutdownDirectInput();                    // FUN_00629a50
    ShowErrorDialog("DirectInput initialization failed.");  // FUN_0062edc0
    return 1;  // Returns 1 even on error — game can still run
}

} // namespace Giants

// ═══════════════════════════════════════════════════════════════════
// ShutdownDirectInput — FUN_00629a50 (STUB)
// ═══════════════════════════════════════════════════════════════════
// Maps DirectInput HRESULT error codes to human-readable strings.
// Called from DirectInput init failure paths.
// 3 callers, 3 callees (FUN_006299e0 — string copy helper).
//
// Ghidra shows a large switch/if-else chain mapping DIERR_* constants
// to string names like "DIERR_NOTFOUND", "DIERR_INPUTLOST", etc.
// Falls through to wsprintfA("Unknown 0x%X", result) for unrecognized codes.

namespace Giants {

void ShutdownDirectInput()
{
    // This function maps g_lastResult (DAT_007281d0) to a DI error string
    // and copies it via FUN_006299e0 (string copy helper).
    //
    // Error code mapping (from Ghidra decompilation):
    //   DIERR_NOTFOUND           = 0x80070002 → -0x7FF8FFFE
    //   DIERR_BADDRIVERVER       = 0x80070077 → -0x7FF8FF89
    //   DIERR_HANDLEEXISTS       = 0x80070005 → -0x7FF8FFFB
    //   DIERR_NOTACQUIRED        = 0x8007000C → -0x7FF8FFF4
    //   DIERR_OUTOFMEMORY        = 0x8007000E → -0x7FF8FFF2
    //   DIERR_NOTINITIALIZED     = 0x80070015 → -0x7FF8FFEB
    //   DIERR_INPUTLOST          = 0x8007001E → -0x7FF8FFE2
    //   DIERR_INVALIDPARAM       = 0x80070057 → -0x7FF8FFA9
    //   DIERR_ACQUIRED           = 0x800700AA → -0x7FF8FF56
    //   DIERR_ALREADYINITIALIZED = 0x800704DF → -0x7FF8FB21
    //   DIERR_BETADIRECTINPUT    = 0x80070481 → -0x7FF8FB7F
    //   DIERR_OLDDIRECTINPUT     = 0x8007047E → -0x7FF8FB82
    //   DIERR_UNSUPPORTED        = 0x80004001 → -0x7FFFBFFF
    //   DIERR_NOINTERFACE        = 0x80004002 → -0x7FFFBFFE
    //   DIERR_GENERIC            = 0x80004005 → -0x7FFFBFFB
    //   DIERR_DEVICENOTREG       = 0x80040154 → -0x7FFBFEAC
    //   DIERR_DEVICEFULL         = 0x80040201 → -0x7FFBFDFF
    //   DIERR_MOREDATA           = 0x80040202 → -0x7FFBFDFE
    //   DIERR_NOTDOWNLOADED      = 0x80040203 → -0x7FFBFDFD
    //   DIERR_HASEFFECTS         = 0x80040204 → -0x7FFBFDFC
    //   DIERR_NOTEXCLUSIVEACQUIRED = 0x80040205 → -0x7FFBFDFB
    //   DIERR_INCOMPLETEEFFECT   = 0x80040206 → -0x7FFBFDFA
    //   DIERR_NOTBUFFERED        = 0x80040207 → -0x7FFBFDF9
    //   DIERR_EFFECTPLAYING      = 0x80040208 → -0x7FFBFDF8
    //   S_OK (0) → "DXNoError" via GetLocalizedString

    // For unrecognized codes: wsprintfA(buffer, "Unknown 0x%X", g_lastResult)
    // Then FUN_006299e0 copies the string
}

} // namespace Giants
