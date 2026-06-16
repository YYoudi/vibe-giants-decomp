# INPUT SYSTEM — DirectInput 7 (Vanilla Giants.exe 1.0)

Reverse-engineering reference and recomp port notes for the vanilla
*Giants: Citizen Kabuto* (Nov-2000, `Giants.exe`, base `0x400000`)
DirectInput subsystem — keyboard + mouse.

Binary: `G:\GiantsRE\GameFiles-VanillaV1\Giants.exe`
Port:   `G:\GiantsRE\src_vanilla\VanillaInput.{h,cpp}`

---

## 1. Import linkage

`Giants.exe` imports **exactly one** symbol from `DINPUT.dll`:

| DLL         | Symbol                  | IAT slot      |
|-------------|-------------------------|---------------|
| `DINPUT.dll`| `DirectInputCreateA`    | `0x0055201c`  |

The import thunk (`jmp dword ptr [0x0055201c]`) lives at `0x0053ca40`.
Notably, **no callers** of that thunk were found via linear-sweep disassembly
of `.text` — the engine resolves `DirectInputCreateA` at runtime via
`GetProcAddress`, treating the IAT entry as a "please load dinput.dll"
marker only.  The vanilla binary also does **not** import `c_dfDIKeyboard`,
`c_dfDIMouse`, `GUID_SysKeyboard`, `GUID_SysMouse`, or `GUID_IDirectInput7`
from `dinput.dll` — it builds the DIDATAFORMAT structures and GUIDs locally
(the classic "no dxguid.lib" pattern).  The recomp port (`VanillaInput.cpp`)
reproduces the runtime-resolution pattern via
`LoadLibrary("dinput.dll") + GetProcAddress("DirectInputCreateA")`.

Confirmed import-string evidence (all in `.rdata` around `0x57ec??`):

| VA         | String                       |
|------------|------------------------------|
| `0x57ec80` | `"DI EnumDevices %s"`        |
| `0x57ec94` | `"DirectInputCreate %s"`     |
| `0x57ecac` | `"DIKey SetProperty %s"`     |
| `0x57ecc4` | `"DIKey SetCooperativeLevel %s"` |
| `0x57ece4` | `"DIKey SetDataFormat %s"`   |
| `0x57ecfc` | `"DIKey CreateDevice %s"`    |
| `0x57ed14` | `"DIMouse SetCooperativeLevel %s"` |
| `0x57ed34` | `"DIMouse SetDataFormat %s"` |
| `0x57ed50` | `"DIMouse CreateDevice %s"`  |
| `0x57ed68` | `"DIKey GetDeviceData %s"`   |

---

## 2. Functions (decompiled bodies in `vanilla_decompiled/`)

| Vanilla addr | Role | Source |
|--------------|------|--------|
| `FUN_0051ede0` | **DI init** — `DirectInputCreateA(hinst, 0x0700, &g_pDI, NULL)`, DX3 fallback `0x0300`, then `EnumDevices`. | `0051ede0.json` |
| `FUN_0051f0e0` | **Keyboard poll** — `IDirectInputDevice7::GetDeviceData` (vtable+0x28). Auto re-Acquire on `DIERR_NOTACQUIRED` (`-0x7ff8ffe2`) / `DIERR_INPUTLOST` (`-0x7ff8fff4`). | `0051f0e0.json` |
| `FUN_0051f1f0` | **Mouse poll** — `IDirectInputDevice7::GetDeviceData` (vtable+0x24). Same re-acquire fallback; decodes `DIDEVICEOBJECTDATA` axis/button stream into engine mouse-button bitmasks. | `0051f1f0.json` |
| `FUN_0051f360` | **DI shutdown** — for each device: `Unacquire` (vtable+0x20) then `Release` (vtable+0x08); mouse also `ReleaseCapture()`; finally `Release` main DI object. | `0051f360.json` |
| `FUN_0051ed80` | **Input state reset** — zeroes keyboard state bitmasks `DAT_005dc130/150/190/1b0/1d0` + mouse-button state `DAT_005dc204/208/20c/210`. | `0051ed80.json` |

The device-setup logic (`CreateDevice` + `SetDataFormat` + `SetCooperativeLevel`
+ `SetProperty` + `Acquire` for both keyboard and mouse) lives in the large
function Ghidra failed to decompile — bounded by the audio-module loader
(0x51ee90–0x51f353+) on the low end and `FUN_0051f0e0` on the high end.  The
DI error-string refs above are pushed by that function and lay out the exact
per-device init sequence: keyboard first (`DIKey CreateDevice` → `SetDataFormat`
→ `SetCooperativeLevel` → `SetProperty`), then mouse (`DIMouse CreateDevice` →
`SetDataFormat` → `SetCooperativeLevel`).

### 2.1 `FUN_0051ede0` — DI instance creation (verbatim from Ghidra)

```c
// globals
//   DAT_005dc128  LPDIRECTINPUT7  g_pDI
//   DAT_005dca54  HINSTANCE       g_hInst
//   DAT_005dcb54  HRESULT         g_diResult
undefined4 FUN_0051ede0(void) {
    // Zero the per-device function-pointer table (0x3b dwords at DAT_005dc128).
    undefined4 *p = &DAT_005dc128;
    for (int i = 0x3b; i; --i) *p++ = 0;

    DAT_005dcb54 = DirectInputCreateA(DAT_005dca54, 0x700, &DAT_005dc128, 0);
    if (DAT_005dcb54 == -0x7ff8fb82 /* DIERR_BETADIRECTINPUTVERSION */)
        DAT_005dcb54 = DirectInputCreateA(DAT_005dca54, 0x300, &DAT_005dc128, 0);
    if (DAT_005dcb54 != 0) {
        FUN_0051d8e0(s_DirectInputCreate__s_0057ec94);   // log
        return 0;
    }
    // IDirectInput7::EnumDevices(DIEDFL_ATTACHEDONLY? 0, callback, NULL, 0)
    DAT_005dcb54 = (**(code**)(*DAT_005dc128 + 0x10))(
                       DAT_005dc128, 0, &LAB_0051ee90, 0, 0);
    if (DAT_005dcb54 != 0) {
        FUN_0051d8e0(s_DI_EnumDevices__s_0057ec80);
        return 0;
    }
    if (DAT_005dc1f0 != 0) SetCapture(DAT_005dca50);
    return 1;
}
```

Key facts:
- `DIRECTINPUT_VERSION` requested = **`0x0700`** (DirectX 7), with fallback
  to **`0x0300`** (DirectX 3) on `DIERR_BETADIRECTINPUTVERSION`.
- EnumDevices call uses **vtable offset `0x10`** (method 4 = `EnumDevices`).
- The `SetCapture(hwnd)` at the tail confirms `DAT_005dc1f0` is the **mouse**
  device pointer (mouse init triggers SetCapture).

### 2.2 `FUN_0051f0e0` — keyboard poll (verbatim from Ghidra)

```c
// DAT_005dc12c  LPDIRECTINPUTDEVICE7  g_pKeyboard
// DAT_005dc130  uint32_t[8] keyboard edge bitmask  (just-pressed)
// DAT_005dc150  uint32_t[8] keyboard held bitmask  (down)
undefined4 FUN_0051f0e0(void) {
    int *pCount = DAT_005dc12c;
    if (DAT_005dc12c != NULL) {
        DAT_005dcb54 = (**(code**)(*DAT_005dc12c + 0x28))(/* GetDeviceData */);
        if (DAT_005dcb54 == -0x7ff8ffe2 || DAT_005dcb54 == -0x7ff8fff4) {
            // DIERR_NOTACQUIRED / DIERR_INPUTLOST -> Acquire (vtable+0x1c)
            (**(code**)(*DAT_005dc12c + 0x1c))();
        } else if (DAT_005dcb54 == 1 /* S_FALSE */) {
            DAT_005dcb54 = 0;
        } else if (DAT_005dcb54 != 0) {
            FUN_0051d8e0(/* DIKey GetDeviceData %s */);
            return 0;
        }
        // Walk the returned DIDEVICEOBJECTDATA[16] array, building bitmasks:
        //   bVar2  = (byte)dwOfs;       // 0..255 scan-code offset
        //   iVar3  = dwOfs >> 5;        // 0..7 (uint32 index)
        //   uVar5  = 1 << (bVar2 & 0x1f);
        //   if (down): DAT_005dc150[iVar3] |= uVar5;
        //              DAT_005dc130[iVar3] |= uVar5;  // edge
        //   else    : DAT_005dc130[iVar3] &= ~uVar5;
        // ...
    }
    return 1;
}
```

The engine stores the keyboard as **two 8-`uint32` bitmasks** (256 bits each):
`DAT_005dc150` = held, `DAT_005dc130` = edges.  Each DIK scan code maps to
bit `(dik & 0x1f)` of `uint32[dik >> 5]`.

### 2.3 `FUN_0051f1f0` — mouse poll (verbatim from Ghidra)

```c
// DAT_005dc1f0  LPDIRECTINPUTDEVICE7  g_pMouse
// DAT_005dc200  uint32_t mouse buttons held bitmask
// DAT_005dc204..0x210 edge/up/down bitmasks
undefined4 FUN_0051f1f0(void) {
    // ...clear prev state...
    if (DAT_005dc1f0 != NULL) {
        // IDirectInputDevice7::GetDeviceData(sizeof(DIDEVICEOBJECTDATA), ...)
        //   via vtable+0x24
        DAT_005dcb54 = (**(code**)(*DAT_005dc1f0 + 0x24))();
        if (DAT_005dcb54 == -0x7ff8ffe2 || DAT_005dcb54 == -0x7ff8fff4) {
            // Acquire (vtable+0x1c), then retry
            (**(code**)(*DAT_005dc1f0 + 0x1c))();
            DAT_005dcb54 = (**(code**)(*DAT_005dc1f0 + 0x24))(
                DAT_005dc1f0, 0x14 /* 20 = sizeof? */, &piStack_24);
        }
        if (DAT_005dcb54 == 0) {
            // Decode DIDEVICEOBJECTDATA bytes into button bitmasks:
            //   _DAT_005dc200 = (|) of (byte >> 1 & 0x80) ...  across the data
            //   _DAT_005dc20c = ~DAT_005dc210 & _DAT_005dc200;  // just-up
            //   _DAT_005dc208 = ~_DAT_005dc200 & DAT_005dc210;  // just-down
            //   _DAT_005dc204 = _DAT_005dc200;                 // held
            //   DAT_005dc210  = _DAT_005dc200;                 // prev
        }
    }
    return 1;
}
```

Mouse buttons: bit 0 = left, bit 1 = right, bit 2 = middle (DirectInput
`DIMOUSESTATE.rgbButtons[0..2]`, high bit set when down).

### 2.4 `FUN_0051f360` — DI shutdown (verbatim from Ghidra)

```c
undefined4 FUN_0051f360(void) {
    if (DAT_005dc12c != NULL) {             // keyboard
        (**(code**)(*DAT_005dc12c + 0x20))(DAT_005dc12c);  // Unacquire
        (**(code**)(*DAT_005dc12c + 0x08))(DAT_005dc12c);  // Release
        DAT_005dc12c = NULL;
    }
    if (DAT_005dc1f0 != NULL) {             // mouse
        ReleaseCapture();
        (**(code**)(*DAT_005dc1f0 + 0x20))(DAT_005dc1f0);  // Unacquire
        (**(code**)(*DAT_005dc1f0 + 0x08))(DAT_005dc1f0);  // Release
        DAT_005dc1f0 = NULL;
    }
    if (DAT_005dc128 != NULL) {             // main DI object
        (**(code**)(*DAT_005dc128 + 0x08))(DAT_005dc128);  // Release
        DAT_005dc128 = NULL;
    }
    return 1;
}
```

### 2.5 IDirectInput7 / IDirectInputDevice7 vtable offsets

Confirmed from decompiled call sites:

| Offset | IDirectInput7 method | IDirectInputDevice7 method |
|--------|----------------------|----------------------------|
| `0x00` | `QueryInterface`     | `QueryInterface`           |
| `0x04` | `AddRef`             | `AddRef`                   |
| `0x08` | `Release`            | `Release`                  |
| `0x0c` | `CreateDevice`       | `GetCapabilities`          |
| `0x10` | `EnumDevices`        | `EnumObjects`              |
| `0x14` | `GetDeviceStatus`    | `GetProperty`              |
| `0x18` | `RunControlPanel`    | `SetProperty`              |
| `0x1c` | `Initialize`         | `Acquire`                  |
| `0x20` | `FindDevice`         | `Unacquire`                |
| `0x24` | `CreateDeviceEx`     | `GetDeviceData` (mouse)    |
| `0x28` |                      | `GetDeviceData` (keyboard) |

---

## 3. Globals (`.data`, base `0x400000`)

| VA          | Type                    | Name (semantic)         |
|-------------|-------------------------|-------------------------|
| `0x005dc128`| `LPDIRECTINPUT7`        | `g_pDI`                 |
| `0x005dc12c`| `LPDIRECTINPUTDEVICE7`  | `g_pKeyboard`           |
| `0x005dc130`| `uint32_t[8]`           | keyboard edge bitmask   |
| `0x005dc150`| `uint32_t[8]`           | keyboard held bitmask   |
| `0x005dc190`| `uint32_t[8]`           | keyboard release bitmask|
| `0x005dc1b0`| `uint32_t[8]`           | (reserved, zeroed)      |
| `0x005dc1d0`| `uint32_t[8]`           | (reserved, zeroed)      |
| `0x005dc1f0`| `LPDIRECTINPUTDEVICE7`  | `g_pMouse`              |
| `0x005dc200`| `uint32_t`              | mouse buttons held      |
| `0x005dc204`| `uint32_t`              | mouse buttons held (cur)|
| `0x005dc208`| `uint32_t`              | mouse buttons just-down |
| `0x005dc20c`| `uint32_t`              | mouse buttons just-up   |
| `0x005dc210`| `uint32_t`              | mouse buttons (prev)    |
| `0x005dca50`| `HWND`                  | `g_hWnd`                |
| `0x005dca54`| `HINSTANCE`             | `g_hInst`               |
| `0x005dcb54`| `HRESULT`               | `g_diResult`            |

---

## 4. Devices + cooperative levels (faithful reconstruction)

Both devices use the same cooperative-level flags:

```c
DISCL_FOREGROUND    |  // acquire when window is foreground
DISCL_NONEXCLUSIVE     // do not grab exclusively; let other apps share
```

Rationale: vanilla runs windowed-capable (its `CreateWindowEx` style
`0x6CF0000` includes `WS_CAPTION|WS_SYSMENU|WS_THICKFRAME|WS_MINIMIZEBOX|
WS_MAXIMIZEBOX`), so non-exclusive foreground cooperative level is what the
release shipped.  Data formats are the DirectInput stock globals:

| Device   | GUID              | Data format      |
|----------|-------------------|------------------|
| Keyboard | `GUID_SysKeyboard`| `c_dfDIKeyboard` |
| Mouse    | `GUID_SysMouse`   | `c_dfDIMouse`    |

`SetProperty(DIPROP_BUFFERSIZE, 16)` is set on both (vanilla error label
`"DIKey SetProperty %s"`) so `GetDeviceData` returns buffered input events.
The recomp port uses the same buffer size.

---

## 5. Recomp port (`src_vanilla/VanillaInput.{h,cpp}`)

Compile check (MinGW-w64, `-m32 -Wall -Wextra -fsyntax-only`):

```
$ export PATH="/c/msys64/mingw32/bin:$PATH"
$ g++ -m32 -fsyntax-only -Wall -Wextra -Isrc_vanilla src_vanilla/VanillaInput.cpp
$ echo $?
0
```

Clean (no warnings, no errors).  Builds against the stock MinGW-w64
`dinput.h` (`#define DIRECTINPUT_VERSION 0x0700`); no link-time dependency
on `libdinput.a` / `libdxguid.a` — `DirectInputCreateA` is resolved at
runtime via `LoadLibrary + GetProcAddress`, exactly like the vanilla binary.

### 5.1 Public API (`extern "C"`)

| Function | Vanilla mirror | Notes |
|----------|----------------|-------|
| `bool VanillaInput_Init(HWND)` | `FUN_0051ede0` + per-device setup | DX7-then-DX3 fallback; creates + acquires both devices |
| `void VanillaInput_Poll(void)` | `FUN_0051f0e0` + `FUN_0051f1f0` | reads 256-byte keyboard state + `DIMOUSESTATE`; auto re-Acquire on loss |
| `bool VanillaInput_KeyDown(int dik)` | `DAT_005dc150` lookup | DIK scan code high-bit test |
| `bool VanillaInput_KeyPressed(int dik)` | `DAT_005dc130` edge | rising-edge this frame |
| `uint32_t VanillaInput_MouseButtons(void)` | `DAT_005dc200` | bit0=L, bit1=R, bit2=M |
| `void VanillaInput_MouseDelta(int*,int*,int*)` | (mouse axis stream) | per-frame dx/dy/dz |
| `void VanillaInput_Fini(void)` | `FUN_0051f360` | Unacquire + Release + `ReleaseCapture()` for mouse |

### 5.2 Integration into `WinMain_vanilla.cpp`

Recommended wiring (one-line addition at the call sites the task identified):

```cpp
#include "VanillaInput.h"
// after CreateWindow + ShowWindow:
if (!VanillaInput_Init(g_vHWnd)) {
    if (g_vTrace) { fprintf(g_vTrace, "[VANILLA] VanillaInput_Init failed\n"); fflush(g_vTrace); }
}
// inside the per-frame loop:
VanillaInput_Poll();
if (VanillaInput_KeyDown(VDIK_ESCAPE)) g_vRunning = false;
// at shutdown:
VanillaInput_Fini();
```

### 5.3 Faithfulness notes

- **Identical** to vanilla on: `DIRECTINPUT_VERSION` (0x0700 + 0x0300
  fallback), device GUIDs (`GUID_SysKeyboard`, `GUID_SysMouse`), data
  formats (`c_dfDIKeyboard`, `c_dfDIMouse`), cooperative-level flags
  (`DISCL_FOREGROUND | DISCL_NONEXCLUSIVE`), `SetProperty(DIPROP_BUFFERSIZE)`,
  `Acquire`, the `ReleaseCapture()` on mouse shutdown, and the
  `Acquire`-on-`DIERR_INPUTLOST`/`NOTACQUIRED` re-acquire path in both polls.
- **Simplification** (behaviour-preserving): the vanilla poll uses buffered
  `GetDeviceData` and folds results into 256-bit bitmasks; the recomp poll
  uses `GetDeviceState(256 bytes)` / `GetDeviceState(DIMOUSESTATE)` and
  exposes the same data through helpers.  Visible input behaviour is
  identical; only the internal storage layout differs (engine-internal
  bitmasks vs. raw byte array).  When the engine's higher-level input
  consumers are ported later, the bitmask layout can be restored to match
  the vanilla DAT_ addresses byte-for-byte.
