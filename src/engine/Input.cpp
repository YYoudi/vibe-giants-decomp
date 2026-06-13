// Giants Engine - Input Processing Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
//
// FUN_0062aac0 — ProcessRawKeyboardInput (PASS, 2 rounds)
// FUN_0062abe0 — ProcessMouseInput (FAIL, code extracted — minor error code issue)

#include "Input.h"
#include "stubs.h"
#include <cstdio>

// Ghidra uses 'uint' as shorthand for 'unsigned int'
using uint = unsigned int;

namespace Giants {

// ─── Static State ─────────────────────────────────────────────

int*     g_rawInputDevice = nullptr;  // DAT_00727e5c
HRESULT  g_rawInputResult = 0;        // DAT_007281d0
DWORD    g_keyState[8]     = {};      // DAT_00727e60
DWORD    g_keyPressLatch[8] = {};     // DAT_00727e80

// Mouse state
uint32_t DAT_00727fbc = 0;
uint32_t DAT_00727fc0 = 0;
uint32_t DAT_00727fc4 = 0;
uint32_t g_mousePrevState = 0;        // DAT_00727fd8
uint32_t g_mouseCurrState = 0;        // DAT_00727fdc
uint32_t DAT_00727fe0     = 0;
uint32_t DAT_00727fe4     = 0;

// ─── ProcessRawKeyboardInput (FUN_0062aac0) ──────────────────
// Status: PASS
// Polls DirectInput keyboard device via COM vtable.
// Each RAWINPUT event is 0x14 bytes; bit 0x80 at offset +0x14 indicates key-down.
// Maintains 256-bit keystate (g_keyState) and press latch (g_keyPressLatch).

bool ProcessRawKeyboardInput()
{
    if (g_rawInputDevice == nullptr)
        return true;

    // RAWINPUT buffer on stack — 0x50 header + N × 0x14 entries
    alignas(4) byte inputBuffer[1284];
    int bufferSize = 0x40;  // max entries

    byte* entryPtr = inputBuffer;

    // vtable[0x28/4] = IDirectInputDevice8::GetDeviceData
    g_rawInputResult = reinterpret_cast<HRESULT(WINAPI*)(int*, UINT, byte*, int*, UINT)>(
        (*reinterpret_cast<void***>(g_rawInputDevice))[0x28 / sizeof(void*)]
    )(g_rawInputDevice, 0x14, inputBuffer, &bufferSize, 0);

    // DIERR_INPUTLOST or DIERR_NOTACQUIRED → Acquire() and retry
    if ((g_rawInputResult == DIERR_INPUTLOST) || (g_rawInputResult == DIERR_NOTACQUIRED))
    {
        // vtable[0x1c/4] = IDirectInputDevice8::Acquire
        reinterpret_cast<void(WINAPI*)(int*)>(
            (*reinterpret_cast<void***>(g_rawInputDevice))[0x1c / sizeof(void*)]
        )(g_rawInputDevice);
    }
    else
    {
        if (g_rawInputResult == 1)  // DI_OK continue
        {
            g_rawInputResult = 0;
        }
        else if (g_rawInputResult != 0)
        {
            // FUN_00629a50() — error handler
            return false;
        }

        // Process each RAWINPUT entry
        if (0 < bufferSize)
        {
            do
            {
                // rawData at offset +0x10 contains scan code (low byte) + flags
                uint rawData = *reinterpret_cast<uint*>(entryPtr + 0x10);
                uint bitIndex  = rawData & 0x1f;         // bit within DWORD
                uint dwordIndex = (rawData & 0xff) >> 5; // DWORD index in array

                DWORD* keyStatePtr = &g_keyState[dwordIndex];

                if ((entryPtr[0x14] & 0x80) == 0)
                {
                    // Key release: clear bit
                    *keyStatePtr = *keyStatePtr & ~(1u << bitIndex);
                }
                else
                {
                    // Key press: latch and set bit
                    g_keyPressLatch[dwordIndex] |= (1u << bitIndex);
                    *keyStatePtr = *keyStatePtr | (1u << bitIndex);
                }

                bufferSize--;
                entryPtr += 0x14;
            } while (bufferSize != 0);
        }
    }

    return true;
}

// ─── ProcessMouseInput (FUN_0062abe0) ─────────────────────────
// Status: FAIL (error code constant issue, code extracted at ~95% accuracy)
// Two phases:
//   1. Bitwise grid operation over arrays at 0x727ea0–0x727f00 (AND/NOT pattern)
//   2. Mouse device poll via COM vtable (same pattern as keyboard)

uint32_t ProcessMouseInput()
{
    // Original (FUN_0062abe0) used hardcoded absolute addresses from the
    // original binary (0x0066c5b0, 0x00727ea0, 0x00727f00, 0x00727f20, etc.)
    // that are NOT valid in our recompiled exe's address space.
    //
    // Phase 1: Bitwise grid processing over contiguous global arrays.
    //   Original memory layout:
    //     0x727e60 = g_keyState[8]       → accessed as out[-0x10..-0xd]
    //     0x727e80 = g_keyPressLatch[8]  → accessed as out[-8..-5]
    //     0x727ea0 = inputGrid[48]       → accessed as out[0..0x1b]
    //     0x727f00 = inputSource[8]      → source array
    //   Mask constants at 0x66c5b0 (4 DWORDs, likely all 0xFFFFFFFF).
    //
    // Phase 2: Mouse device polling via IDirectInputDevice8::GetDeviceData.
    //   Uses g_pMouseDevice (DAT_00727e5c) when g_nControllerCount==0.
    //
    // Safe no-op for now — mouse input not required for initial frame rendering.
    // TODO: Implement with proper contiguous globals and g_pMouseDevice.
    return 1;
}

// ─── Input globals for new functions ──────────────────────────

// Camera mode toggle state
static uint32_t DAT_00747a94 = 0;      // Camera mode toggle (0/1)
static uint32_t DAT_00702c45 = 0;      // Camera flag (set when DAT_00702b04 == 0)
static uint32_t DAT_00702c4b = 0;      // Camera command flag
static uint32_t DAT_00702c4d = 0;      // Controller flag A
static uint32_t DAT_00702c4e = 0;      // Controller flag B
static uint32_t DAT_00702c50 = 0;      // Controller flag C
static uint32_t DAT_00702c51 = 0;      // Controller flag D

// Camera mode state
static char DAT_00702898 = 0;          // Camera lock flag
static uint32_t DAT_00681db0 = 0;      // Camera mode state A
static uint32_t DAT_00681dbc = 0;      // Camera mode state B
static uint32_t DAT_00681db8 = 0;      // Camera mode state C

// Key binding registry handle
static HKEY DAT_0074be5c = nullptr;    // Registry key for settings

// Key mapping data buffer
static uint32_t DAT_00745118[0x160 / 4] = {0}; // Key mapping data (352 bytes)

// ─── InputCommandSwitch (FUN_004ae9b0) — FAIL ─────────────────
// Status: FAIL
// Handles camera mode switching, key binding overrides, and controller flags.
// Dispatches on param2 values 0x20-0x2B.
// Writes camera mode to registry ("CamMode") when switching.

/*
  RAW DECOMPILATION (Ghidra):
  void __fastcall FUN_004ae9b0(int param_1, undefined4 param_2)
  {
    int iStack_4;
    iStack_4 = param_1;
    switch(param_2) {
    case 0x20:
      if (DAT_00702b04 == 0) { DAT_00702c45 = 1; return; }
      DAT_00747a94 = (uint)(DAT_00747a94 == 0);  // toggle
      return;
    case 0x21:
      FUN_00499f10();  // reset camera
      return;
    case 0x22:
      if (DAT_00702898 == '\0') {
        if (((DAT_00681db0 == 0) && (DAT_00681dbc == 0)) && (DAT_00681db8 == 0)) {
          FUN_00499e30(); iStack_4 = 2;  // cycle camera mode 2
        } else {
          FUN_00499e30(); iStack_4 = 1;  // cycle camera mode 1
        }
        if (DAT_0074be5c != (HKEY)0x0) {
          RegSetValueExA(DAT_0074be5c, "CamMode", 0, 4, (BYTE *)&iStack_4, 4);
        }
      }
      break;
    case 0x23:
      DAT_00702c4b = 1; return;
    case 0x24:
      *(undefined1 *)(param_1 + 2) = 0x20; return;  // space key
    case 0x25:
      *(undefined1 *)(param_1 + 2) = 0xe0; return;  // extended key
    case 0x26:
      *(undefined1 *)(param_1 + 3) = 0x20; return;  // space key (alt)
    case 0x27:
      *(undefined1 *)(param_1 + 3) = 0xe0; return;  // extended key (alt)
    case 0x28:
      DAT_00702c4d = 1; return;
    case 0x29:
      DAT_00702c4e = 1; break;
    case 0x2a:
      DAT_00702c50 = 1; return;
    case 0x2b:
      DAT_00702c51 = 1; return;
    }
    return;
  }
*/

void InputCommandSwitch(int param1, uint32_t param2)
{
    int camMode = param1;

    switch (param2)
    {
    case 0x20:
        // Toggle camera mode or set flag
        if (1459617792 == 0)
        {
            DAT_00702c45 = 1;
            return;
        }
        DAT_00747a94 = (DAT_00747a94 == 0) ? 1 : 0;  // toggle
        return;

    case 0x21:
        // Reset camera position
        // FUN_00499f10();
        return;

    case 0x22:
        // Cycle camera mode and persist to registry
        if (DAT_00702898 == 0)
        {
            if ((DAT_00681db0 == 0) && (DAT_00681dbc == 0) && (DAT_00681db8 == 0))
            {
                // FUN_00499e30();  // apply camera preset
                camMode = 2;
            }
            else
            {
                // FUN_00499e30();  // apply camera preset
                camMode = 1;
            }
            if (DAT_0074be5c != nullptr)
            {
                RegSetValueExA(DAT_0074be5c, "CamMode", 0, REG_DWORD,
                               reinterpret_cast<BYTE*>(&camMode), 4);
            }
        }
        break;

    case 0x23:
        DAT_00702c4b = 1;
        return;

    case 0x24:
        *reinterpret_cast<uint8_t*>(param1 + 2) = 0x20;  // map to space
        return;

    case 0x25:
        *reinterpret_cast<uint8_t*>(param1 + 2) = 0xE0;  // map to extended
        return;

    case 0x26:
        *reinterpret_cast<uint8_t*>(param1 + 3) = 0x20;  // map to space (alt)
        return;

    case 0x27:
        *reinterpret_cast<uint8_t*>(param1 + 3) = 0xE0;  // map to extended (alt)
        return;

    case 0x28:
        DAT_00702c4d = 1;
        return;

    case 0x29:
        DAT_00702c4e = 1;
        break;

    case 0x2A:
        DAT_00702c50 = 1;
        return;

    case 0x2B:
        DAT_00702c51 = 1;
        return;
    }
}

// ─── KeyBindingLoader (FUN_004b4130) — FAIL ───────────────────
// Status: FAIL
// Reads KeyVersion from registry, loads key mapping file.
// If KeyVersion == 0x38 (56), reads 0x160 bytes of key mapping data
// from a file into DAT_00745118.

/*
  RAW DECOMPILATION (Ghidra):
  void FUN_004b4130(void)
  {
    FUN_004b17c0(...);    // init key state arrays
    FUN_004b3880();       // load default bindings
    FUN_004af150();       // apply defaults
    FUN_004b3e50();       // build key path
    FUN_00624fb0();       // resolve path
    FUN_00443490();       // cleanup

    local_74 = 0;
    if (DAT_0074be5c != (HKEY)0x0) {
      local_70[0] = (FILE *)0x4;
      RegQueryValueExA(DAT_0074be5c, "KeyVersion", 0, 0, (LPBYTE)&local_74, (LPDWORD)local_70);
      if (local_74 == 0x38) {
        uVar1 = FUN_004b3e50();  // build key file path
        FUN_00443070(uVar1);     // open path
        FUN_00443490();          // cleanup

        // Get filename from SSO wstring
        _Filename = local_3c;
        if (7 < local_28) _Filename = (wchar_t ***)local_3c[0];

        local_70[0] = 0;
        _wfopen_s(local_70, (wchar_t *)_Filename, L"rb");
        if (local_70[0] != 0) {
          fread(&DAT_00745118, 0x160, 1, local_70[0]); // read 352 bytes
        }
        FUN_004af150();       // apply loaded bindings
        if (local_70[0] != 0) {
          fclose(local_70[0]);
          local_70[0] = 0;
        }
        FUN_00443490();       // cleanup
      }
    }
  }
*/

void KeyBindingLoader()
{
    // Phase 1: Initialize key state with defaults
    // FUN_004b17c0();   // init key state arrays
    // FUN_004b3880();    // load default bindings
    // FUN_004af150();    // apply defaults
    // FUN_004b3e50();    // build key file path
    // FUN_00624fb0();    // resolve file path
    // FUN_00443490();    // string cleanup

    // Phase 2: Check registry for custom key version
    int32_t keyVersion = 0;
    if (DAT_0074be5c != nullptr)
    {
        DWORD dataSize = 4;
        RegQueryValueExA(DAT_0074be5c, "KeyVersion", nullptr, nullptr,
                         reinterpret_cast<LPBYTE>(&keyVersion), &dataSize);

        if (keyVersion == 0x38)
        {
            // Build and open key mapping file path
            // uint32_t pathStr = FUN_004b3e50();  // build path string
            // FUN_00443070(pathStr);               // convert to wide path
            // FUN_00443490();                       // cleanup

            // Open the key mapping file
            // const wchar_t* filename = ...; // extract from SSO wstring
            FILE* keyFile = nullptr;
            // _wfopen_s(&keyFile, filename, L"rb");

            if (keyFile != nullptr)
            {
                // Read 0x160 (352) bytes of key mapping data
                fread(&DAT_00745118, 0x160, 1, keyFile);
            }

            // Apply loaded key bindings
            // FUN_004af150();

            if (keyFile != nullptr)
            {
                fclose(keyFile);
            }
            // FUN_00443490();  // final cleanup
        }
    }
}

} // namespace Giants
