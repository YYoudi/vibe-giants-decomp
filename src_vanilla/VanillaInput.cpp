// VanillaInput.cpp — DirectInput 7 keyboard + mouse subsystem.
//
// Faithful port of the vanilla Giants.exe (1.0) input layer.  See VanillaInput.h
// for the full vanilla RE address map and design notes.
//
// What the vanilla binary does (confirmed from decompiled bodies in
// vanilla_decompiled/0051ede0.json, 0051f0e0.json, 0051f1f0.json, 0051f360.json):
//
//   FUN_0051ede0 (init):
//     HRESULT hr = DirectInputCreateA(g_hInst, 0x0700, &g_pDI, NULL);
//     if (hr == DIERR_BETADIRECTINPUTVERSION || DIERR_OLDDIRECTINPUTVERSION)
//         hr = DirectInputCreateA(g_hInst, 0x0300, &g_pDI, NULL);  // DX3 fallback
//     if (FAILED(hr)) { log("DirectInputCreate %s"); return false; }
//     g_pDI->EnumDevices(0, EnumDevicesCb, NULL, 0);   // vtable+0x10
//     // The callback (or a sibling function) calls CreateDevice for the
//     // keyboard (GUID_SysKeyboard) and mouse (GUID_SysMouse), then for each
//     // device: SetDataFormat(c_dfDI*) + SetCooperativeLevel(hwnd,
//     // DISCL_FOREGROUND|DISCL_NONEXCLUSIVE) + SetProperty(buffer size) +
//     // Acquire.
//
//   FUN_0051f0e0 (keyboard poll):  g_pKeyboard->GetDeviceData(...); on
//     DIERR_NOTACQUIRED/DIERR_INPUTLOST, g_pKeyboard->Acquire().
//
//   FUN_0051f1f0 (mouse poll):     g_pMouse->GetDeviceData(...); same
//     re-acquire fallback; decodes the per-axis DIDEVICEOBJECTDATA stream
//     into the engine's mouse-button bitmasks.
//
//   FUN_0051f360 (shutdown):       for each device: Unacquire (vtable+0x20)
//                                 then Release (vtable+0x08); for the mouse
//                                 also ReleaseCapture(); finally Release the
//                                 main DI object.
//
// This port reproduces that structure with the modern IDirectInput7 /
// IDirectInputDevice7A COM interfaces.  Because vanilla links dinput.dll
// dynamically (one IAT import: DirectInputCreateA), this port also resolves
// DirectInputCreateA via LoadLibrary+GetProcAddress — same pattern, no link
// dependency on libdinput.a / libdxguid.a required at build time.

#define DIRECTINPUT_VERSION 0x0700
#define INITGUID
#include <windows.h>

// dinput.h is provided by MinGW-w64 (mingw32/include/dinput.h).  It declares
// IDirectInput7A, IDirectInputDevice7A, GUID_SysKeyboard, GUID_SysMouse,
// c_dfDIKeyboard, c_dfDIMouse, DIDATAFormat, DIMOUSESTATE, DIPROPDWORD, etc.
// We guard the include so the build is self-contained.
#if __has_include(<dinput.h>)
#include <dinput.h>
#define VANILLA_DI_HAVE_DINPUT_H 1
#else
#error "dinput.h not found — install MinGW-w64 headers (mingw32/include/dinput.h)."
#endif

#include "VanillaInput.h"

// ── Globals mirroring the vanilla .data layout ──────────────────────────────
// (Vanilla DAT_ addresses in comments for cross-reference.)
static LPDIRECTINPUT7       g_pDI        = nullptr;   // DAT_005dc128
static LPDIRECTINPUTDEVICE7 g_pKeyboard  = nullptr;   // DAT_005dc12c
static LPDIRECTINPUTDEVICE7 g_pMouse     = nullptr;   // DAT_005dc1f0
static HWND                 g_hWnd       = nullptr;   // DAT_005dca50
static HINSTANCE            g_hInst      = nullptr;   // DAT_005dca54
static HRESULT              g_diResult   = S_OK;      // DAT_005dcb54

// Keyboard state — 256-byte scan-code array (one byte per DIK_*).  The
// vanilla engine derives 8-uint32 bitmasks from this; we keep the raw 256-byte
// buffer (simpler) plus the previous frame for edge detection.
static uint8_t  g_keyState[256]      = {0};
static uint8_t  g_keyStatePrev[256]  = {0};

// Mouse state — accumulated per-frame deltas + button bitmask.
// (Vanilla DAT_005dc200 = buttons-held bitmask; the engine also derives
// edge/up/down bitmasks at DAT_005dc204/208/20c.)
static int32_t  g_mouseDX = 0;
static int32_t  g_mouseDY = 0;
static int32_t  g_mouseDZ = 0;
static uint32_t g_mouseButtons     = 0;   // held this frame
static uint32_t g_mouseButtonsPrev = 0;

// Buffered-mode item count used by GetDeviceData (the vanilla SetProperty
// DIPROP_BUFFERSIZE).  16 is a safe default; vanilla uses buffered mode for
// both devices (FUN_0051f0e0 / FUN_0051f1f0 both call GetDeviceData).
static const DWORD kKeyboardBufferSize = 16;
static const DWORD kMouseBufferSize    = 16;

// ── DirectInputCreateA resolved dynamically (vanilla IAT pattern) ───────────
typedef HRESULT (WINAPI *PFN_DirectInputCreateA)(HINSTANCE, DWORD, LPVOID*, LPUNKNOWN);
static PFN_DirectInputCreateA g_pfnDirectInputCreateA = nullptr;

// ── Helpers ─────────────────────────────────────────────────────────────────
static const char* di_err(HRESULT hr) {
    switch (hr) {
        case DI_OK:               return "DI_OK";
        case DIERR_ALREADYINITIALIZED: return "DIERR_ALREADYINITIALIZED";
        case DIERR_BETADIRECTINPUTVERSION: return "DIERR_BETADIRECTINPUTVERSION";
        case DIERR_ACQUIRED:      return "DIERR_ACQUIRED";
        case DIERR_OLDDIRECTINPUTVERSION: return "DIERR_OLDDIRECTINPUTVERSION";
        case DIERR_BADDRIVERVER:  return "DIERR_BADDRIVERVER";
        case DIERR_OUTOFMEMORY:   return "DIERR_OUTOFMEMORY";
        case DIERR_NOTINITIALIZED:return "DIERR_NOTINITIALIZED";
        case DIERR_NOTACQUIRED:   return "DIERR_NOTACQUIRED";
        case DIERR_INVALIDPARAM:  return "DIERR_INVALIDPARAM";
        case DIERR_INPUTLOST:     return "DIERR_INPUTLOST";
        case DIERR_HANDLEEXISTS:  return "DIERR_HANDLEEXISTS";
        case DIERR_NOTFOUND:      return "DIERR_NOTFOUND";
        case (HRESULT)DIERR_NOTEXCLUSIVEACQUIRED: return "DIERR_NOTEXCLUSIVEACQUIRED";
        case DIERR_UNSUPPORTED:   return "DIERR_UNSUPPORTED";
        case DIERR_NOINTERFACE:   return "DIERR_NOINTERFACE";
        case DIERR_GENERIC:       return "DIERR_GENERIC";
        default:                  return "<unknown>";
    }
}

// Set the DIPROP_BUFFERSIZE property on a device — mirrors the vanilla
// "DIKey SetProperty" step.
static bool di_set_buffer_size(LPDIRECTINPUTDEVICE7 dev, DWORD count) {
    DIPROPDWORD dipdw;
    dipdw.diph.dwSize       = sizeof(DIPROPDWORD);
    dipdw.diph.dwHeaderSize = sizeof(DIPROPHEADER);
    dipdw.diph.dwObj        = 0;
    dipdw.diph.dwHow        = DIPH_DEVICE;
    dipdw.dwData            = count;
    HRESULT hr = dev->SetProperty(DIPROP_BUFFERSIZE, &dipdw.diph);
    return SUCCEEDED(hr);
}

// Create + configure one device.  Replicates the per-device step sequence
// the vanilla engine runs after CreateDevice:
//   SetDataFormat  -> SetCooperativeLevel -> SetProperty(bufsize) -> Acquire.
// IDirectInput7A::CreateDevice returns the base IDirectInputDeviceA*; we
// QueryInterface up to IDirectInputDevice7A for the v7 method set.
static bool di_create_device(LPDIRECTINPUT7 pDI, REFGUID rguid,
                             LPCDIDATAFORMAT fmt, DWORD coopFlags,
                             LPDIRECTINPUTDEVICE7* outDev, const char* label) {
    *outDev = nullptr;
    LPDIRECTINPUTDEVICE pDevBase = nullptr;
    HRESULT hr = pDI->CreateDevice(rguid, &pDevBase, nullptr);
    if (FAILED(hr) || !pDevBase) { g_diResult = hr; return false; }
    // QI up to v7 (the vanilla engine holds v7 device pointers: DAT_005dc12c/1f0).
    hr = pDevBase->QueryInterface(IID_IDirectInputDevice7, (LPVOID*)outDev);
    pDevBase->Release();   // owned by the QI'd ptr if it succeeded
    if (FAILED(hr) || !*outDev) { g_diResult = hr; return false; }

    hr = (*outDev)->SetDataFormat(fmt);
    if (FAILED(hr)) { g_diResult = hr; (*outDev)->Release(); *outDev = nullptr; return false; }
    hr = (*outDev)->SetCooperativeLevel(g_hWnd, coopFlags);
    if (FAILED(hr)) { g_diResult = hr; (*outDev)->Release(); *outDev = nullptr; return false; }
    // Set a modest buffer so GetDeviceData works (vanilla "DIKey SetProperty").
    di_set_buffer_size(*outDev, kKeyboardBufferSize);
    hr = (*outDev)->Acquire();
    // Acquire can return S_FALSE (already acquired) — treat as success.
    if (hr != DI_OK && hr != S_FALSE) {
        // Not fatal at init time: the device will be re-acquired on first poll.
    }
    (void)label;
    return true;
}

// ── Public API ──────────────────────────────────────────────────────────────

extern "C" bool VanillaInput_Init(HWND hwnd) {
    if (g_pDI) return true;            // already initialised
    g_hWnd  = hwnd;
    g_hInst = (HINSTANCE)GetWindowLongPtrA(hwnd, GWLP_HINSTANCE);

    // Vanilla IAT only imports DirectInputCreateA — resolve it dynamically.
    HMODULE hm = LoadLibraryA("dinput.dll");
    if (!hm) return false;
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wcast-function-type"
    g_pfnDirectInputCreateA = (PFN_DirectInputCreateA)
        GetProcAddress(hm, "DirectInputCreateA");
#pragma GCC diagnostic pop
    if (!g_pfnDirectInputCreateA) return false;

    // FUN_0051ede0: try DIRECTINPUT_VERSION 0x0700 first, then 0x0300 fallback
    // (vanilla does exactly this on DIERR_OLDDIRECTINPUTVERSION /
    //  DIERR_BETADIRECTINPUTVERSION).
    HRESULT hr = g_pfnDirectInputCreateA(g_hInst, 0x0700,
                                         (LPVOID*)&g_pDI, nullptr);
    if (hr == DIERR_OLDDIRECTINPUTVERSION || hr == DIERR_BETADIRECTINPUTVERSION) {
        hr = g_pfnDirectInputCreateA(g_hInst, 0x0300,
                                     (LPVOID*)&g_pDI, nullptr);
    }
    g_diResult = hr;
    if (FAILED(hr) || !g_pDI) return false;

    // Keyboard: GUID_SysKeyboard, c_dfDIKeyboard,
    //   DISCL_FOREGROUND | DISCL_NONEXCLUSIVE
    //   (vanilla error label: "DIKey CreateDevice/SetDataFormat/
    //    SetCooperativeLevel/SetProperty %s").
    if (!di_create_device(g_pDI, GUID_SysKeyboard, &c_dfDIKeyboard,
                          DISCL_FOREGROUND | DISCL_NONEXCLUSIVE,
                          &g_pKeyboard, "DIKey")) {
        VanillaInput_Fini();
        return false;
    }

    // Mouse: GUID_SysMouse, c_dfDIMouse,
    //   DISCL_FOREGROUND | DISCL_NONEXCLUSIVE
    //   (vanilla: "DIMouse CreateDevice/SetDataFormat/SetCooperativeLevel %s").
    if (!di_create_device(g_pDI, GUID_SysMouse, &c_dfDIMouse,
                          DISCL_FOREGROUND | DISCL_NONEXCLUSIVE,
                          &g_pMouse, "DIMouse")) {
        VanillaInput_Fini();
        return false;
    }

    // Clear state mirrors (vanilla FUN_0051ed80 zeroes these on reset).
    ZeroMemory(g_keyState, sizeof(g_keyState));
    ZeroMemory(g_keyStatePrev, sizeof(g_keyStatePrev));
    g_mouseDX = g_mouseDY = g_mouseDZ = 0;
    g_mouseButtons = g_mouseButtonsPrev = 0;
    return true;
}

extern "C" void VanillaInput_Poll(void) {
    // ── Keyboard ───────────────────────────────────────────────────────────
    // Vanilla FUN_0051f0e0 uses GetDeviceData; for key-down queries we use
    // GetDeviceState(256 bytes) which is simpler and equivalent.  Re-acquire
    // on DIERR_INPUTLOST / DIERR_NOTACQUIRED — exact vanilla behaviour.
    if (g_pKeyboard) {
        g_keyStatePrev[0] = g_keyState[0];   // touch (silences unused-warnings)
        // Save full prev frame for edge detection.
        CopyMemory(g_keyStatePrev, g_keyState, sizeof(g_keyState));
        HRESULT hr = g_pKeyboard->GetDeviceState(sizeof(g_keyState), g_keyState);
        if (hr == DIERR_INPUTLOST || hr == DIERR_NOTACQUIRED) {
            // Vanilla: call Acquire (vtable+0x1c) then retry.
            g_pKeyboard->Acquire();
            ZeroMemory(g_keyState, sizeof(g_keyState));
            hr = g_pKeyboard->GetDeviceState(sizeof(g_keyState), g_keyState);
        }
        if (FAILED(hr)) ZeroMemory(g_keyState, sizeof(g_keyState));
    }

    // ── Mouse ──────────────────────────────────────────────────────────────
    // Vanilla FUN_0051f1f0 uses buffered GetDeviceData and decodes the axis
    // stream.  For simplicity (and identical visible behaviour) we read
    // immediate mode via GetDeviceState(DIMOUSESTATE).  Re-acquire on loss.
    g_mouseButtonsPrev = g_mouseButtons;
    g_mouseDX = g_mouseDY = g_mouseDZ = 0;
    if (g_pMouse) {
        DIMOUSESTATE ms;
        ZeroMemory(&ms, sizeof(ms));
        HRESULT hr = g_pMouse->GetDeviceState(sizeof(ms), &ms);
        if (hr == DIERR_INPUTLOST || hr == DIERR_NOTACQUIRED) {
            g_pMouse->Acquire();
            ZeroMemory(&ms, sizeof(ms));
            hr = g_pMouse->GetDeviceState(sizeof(ms), &ms);
        }
        if (SUCCEEDED(hr)) {
            g_mouseDX = ms.lX;
            g_mouseDY = ms.lY;
            g_mouseDZ = ms.lZ;
            // Vanilla DAT_005dc200: bit0=left, bit1=right, bit2=middle.
            g_mouseButtons = (ms.rgbButtons[0] & 0x80 ? 0x1 : 0)
                           | (ms.rgbButtons[1] & 0x80 ? 0x2 : 0)
                           | (ms.rgbButtons[2] & 0x80 ? 0x4 : 0);
        } else {
            g_mouseButtons = 0;
        }
    }
}

extern "C" bool VanillaInput_KeyDown(int dik) {
    if (dik < 0 || dik >= 256) return false;
    return (g_keyState[dik] & 0x80) != 0;
}

extern "C" bool VanillaInput_KeyPressed(int dik) {
    if (dik < 0 || dik >= 256) return false;
    bool now  = (g_keyState[dik]     & 0x80) != 0;
    bool prev = (g_keyStatePrev[dik] & 0x80) != 0;
    return now && !prev;    // edge: just pressed this frame
}

extern "C" uint32_t VanillaInput_MouseButtons(void) {
    return g_mouseButtons;
}

extern void VanillaInput_MouseDelta_int(int* dx, int* dy, int* dz);  // fwd
extern "C" void VanillaInput_MouseDelta(int* dx, int* dy, int* dz) {
    if (dx) *dx = g_mouseDX;
    if (dy) *dy = g_mouseDY;
    if (dz) *dz = g_mouseDZ;
}
void VanillaInput_MouseDelta_int(int* dx, int* dy, int* dz) {
    VanillaInput_MouseDelta(dx, dy, dz);
}

extern "C" void VanillaInput_Fini(void) {
    // FUN_0051f360: Unacquire (vtable+0x20) then Release (vtable+0x08).
    if (g_pKeyboard) {
        g_pKeyboard->Unacquire();
        g_pKeyboard->Release();
        g_pKeyboard = nullptr;
    }
    if (g_pMouse) {
        // Vanilla also calls ReleaseCapture() for the mouse.
        ReleaseCapture();
        g_pMouse->Unacquire();
        g_pMouse->Release();
        g_pMouse = nullptr;
    }
    if (g_pDI) {
        g_pDI->Release();
        g_pDI = nullptr;
    }
    g_hWnd  = nullptr;
    g_hInst = nullptr;
    g_pfnDirectInputCreateA = nullptr;
}
