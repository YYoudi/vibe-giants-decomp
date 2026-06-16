// VanillaInput.h — DirectInput 7 keyboard + mouse subsystem for the
// vanilla-native recomp.
//
// Faithful port of the vanilla Giants.exe (1.0, Nov-2000, base 0x400000)
// DirectInput subsystem.  The vanilla engine links ONLY DirectInputCreateA
// from DINPUT.dll (one import; confirmed via IAT walk) and then drives the
// IDirectInput7 / IDirectInputDevice7 COM interfaces directly via vtables.
// No c_dfDIKeyboard / c_dfDIMouse / GUID_Sys* are imported — the engine
// builds them locally (the no-dxguid.lib pattern).  This port reproduces
// that exact layout.
//
// Vanilla RE addresses (base 0x400000):
//   FUN_0051ede0  DirectInputCreate + EnumDevices          (init)
//   FUN_0051f0e0  keyboard GetDeviceData poll              (per-frame)
//   FUN_0051f1f0  mouse    GetDeviceData poll              (per-frame)
//   FUN_0051f360  Unacquire + Release shutdown             (fini)
//   DAT_005dc128  LPDIRECTINPUT7         g_pDI
//   DAT_005dc12c  LPDIRECTINPUTDEVICE7   g_pKeyboard
//   DAT_005dc1f0  LPDIRECTINPUTDEVICE7   g_pMouse
//   DAT_005dca50  HWND                   g_hWnd
//   DAT_005dca54  HINSTANCE              g_hInst
//   DAT_005dcb54  HRESULT                g_diResult
//   DAT_005dc130  uint32_t[8] keyboard edge-bitmask  (key-just-pressed)
//   DAT_005dc150  uint32_t[8] keyboard held-bitmask  (key-down)
//   DAT_005dc190  uint32_t[8] keyboard released-bitmask (key-just-released)
//   DAT_005dc1b0  uint32_t[8] (reserved, cleared each reset)
//   DAT_005dc1d0  uint32_t[8] (reserved, cleared each reset)
//   DAT_005dc200  uint32_t mouse buttons held bitmask
//   DAT_005dc204..0x210 mouse edge/down/up bitmasks
//
// Public API is intentionally minimal and C-linkage so the recomp's WinMain
// (WinMain_vanilla.cpp) can wire it in directly:
//
//     VanillaInput_Init(hwnd);          // call after CreateWindow
//     ... per frame ...
//     VanillaInput_Poll();              // reads DI device state
//     if (VanillaInput_KeyDown(DIK_W)) { ... }
//
#pragma once
#include <stdint.h>
#include <windows.h>

#ifdef __cplusplus
extern "C" {
#endif

// ── Vanilla-true init/poll/fini ──────────────────────────────────────────────
// VanillaInput_Init: faithful reproduction of vanilla FUN_0051ede0 +
// the keyboard/mouse CreateDevice+SetDataFormat+SetCooperativeLevel+Acquire
// sequence.  Returns true on success.
//
// Like the vanilla binary, this resolves DirectInputCreateA dynamically via
// LoadLibrary("dinput.dll") + GetProcAddress — the vanilla IAT only contains
// that single symbol and the engine recovers the function pointer at runtime
// (the import-table entry exists purely so the loader maps dinput.dll).
extern bool VanillaInput_Init(HWND hwnd);

// VanillaInput_Poll: per-frame device read.
// Mirrors vanilla FUN_0051f0e0 (keyboard GetDeviceData) + FUN_0051f1f0 (mouse
// GetDeviceData).  If a device reports DIERR_NOTACQUIRED / DIERR_INPUTLOST
// it is re-Acquired automatically (the vanilla poll does exactly this via
// vtable+0x1c = Acquire).
extern void VanillaInput_Poll(void);

// VanillaInput_KeyDown: returns true if the given DIK_* scan code is currently
// held.  The vanilla engine stores the keyboard state as 256 bytes retrieved
// from GetDeviceData and folds it into 8 uint32 bitmasks (DAT_005dc150); this
// helper indexes into the same 256-byte buffer (simpler & equivalent).
extern bool VanillaInput_KeyDown(int dik);

// VanillaInput_KeyPressed: true on the frame the key transitioned to down
// (edge).  Matches vanilla DAT_005dc130 semantics.
extern bool VanillaInput_KeyPressed(int dik);

// VanillaInput_MouseButtons: returns the current mouse-button bitmask.
//   bit 0 = left, bit 1 = right, bit 2 = middle (vanilla DAT_005dc200).
extern uint32_t VanillaInput_MouseButtons(void);

// VanillaInput_MouseDelta: writes the per-frame mouse X/Y/Z deltas (vanilla
// decodes these from DIDEVICEOBJECTDATA in FUN_0051f1f0).
extern void VanillaInput_MouseDelta(int* dx, int* dy, int* dz);

// VanillaInput_Fini: Unacquire + Release every device + the DI object.
// Mirrors vanilla FUN_0051f360 exactly (vtable+0x20 = Unacquire,
// vtable+0x08 = Release, plus ReleaseCapture() for the mouse).
extern void VanillaInput_Fini(void);

// ── DIK_* scan codes (subset of the DirectInput keyboard scan codes) ────────
// Provided here so callers do not need to include dinput.h.  Values identical
// to the DirectInput DIK_* constants.
#define VDIK_ESCAPE          0x01
#define VDIK_1               0x02
#define VDIK_2               0x03
#define VDIK_3               0x04
#define VDIK_4               0x05
#define VDIK_5               0x06
#define VDIK_6               0x07
#define VDIK_7               0x08
#define VDIK_8               0x09
#define VDIK_9               0x0A
#define VDIK_0               0x0B
#define VDIK_MINUS           0x0C
#define VDIK_EQUALS          0x0D
#define VDIK_BACK            0x0E
#define VDIK_TAB             0x0F
#define VDIK_Q               0x10
#define VDIK_W               0x11
#define VDIK_E               0x12
#define VDIK_R               0x13
#define VDIK_T               0x14
#define VDIK_Y               0x15
#define VDIK_U               0x16
#define VDIK_I               0x17
#define VDIK_O               0x18
#define VDIK_P               0x19
#define VDIK_LBRACKET        0x1A
#define VDIK_RBRACKET        0x1B
#define VDIK_RETURN          0x1C
#define VDIK_LCONTROL        0x1D
#define VDIK_A               0x1E
#define VDIK_S               0x1F
#define VDIK_D               0x20
#define VDIK_F               0x21
#define VDIK_G               0x22
#define VDIK_H               0x23
#define VDIK_J               0x24
#define VDIK_K               0x25
#define VDIK_L               0x26
#define VDIK_SEMICOLON       0x27
#define VDIK_APOSTROPHE      0x28
#define VDIK_GRAVE           0x29
#define VDIK_LSHIFT          0x2A
#define VDIK_BACKSLASH       0x2B
#define VDIK_Z               0x2C
#define VDIK_X               0x2D
#define VDIK_C               0x2E
#define VDIK_V               0x2F
#define VDIK_B               0x30
#define VDIK_N               0x31
#define VDIK_M               0x32
#define VDIK_COMMA           0x33
#define VDIK_PERIOD          0x34
#define VDIK_SLASH           0x35
#define VDIK_RSHIFT          0x36
#define VDIK_MULTIPLY        0x37
#define VDIK_LMENU           0x38   // Left Alt
#define VDIK_SPACE           0x39
#define VDIK_CAPITAL         0x3A
#define VDIK_F1              0x3B
#define VDIK_F2              0x3C
#define VDIK_F3              0x3D
#define VDIK_F4              0x3E
#define VDIK_F5              0x3F
#define VDIK_F6              0x40
#define VDIK_F7              0x41
#define VDIK_F8              0x42
#define VDIK_F9              0x43
#define VDIK_F10             0x44
#define VDIK_NUMLOCK         0x45
#define VDIK_SCROLL          0x46
#define VDIK_NUMPAD7         0x47
#define VDIK_NUMPAD8         0x48
#define VDIK_NUMPAD9         0x49
#define VDIK_SUBTRACT        0x4A
#define VDIK_NUMPAD4         0x4B
#define VDIK_NUMPAD5         0x4C
#define VDIK_NUMPAD6         0x4D
#define VDIK_ADD             0x4E
#define VDIK_NUMPAD1         0x4F
#define VDIK_NUMPAD2         0x50
#define VDIK_NUMPAD3         0x51
#define VDIK_NUMPAD0         0x52
#define VDIK_DECIMAL         0x53
#define VDIK_F11             0x57
#define VDIK_F12             0x58
#define VDIK_RCONTROL        0x9D
#define VDIK_RMENU           0xB8   // Right Alt
#define VDIK_HOME            0xC7
#define VDIK_UP              0xC8
#define VDIK_PRIOR           0xC9   // Page Up
#define VDIK_LEFT            0xCB
#define VDIK_RIGHT           0xCD
#define VDIK_END             0xCF
#define VDIK_DOWN            0xD0
#define VDIK_NEXT            0xD1   // Page Down
#define VDIK_INSERT          0xD2
#define VDIK_DELETE          0xD3

#ifdef __cplusplus
} // extern "C"
#endif
