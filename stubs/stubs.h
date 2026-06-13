// Stub headers for GiantsRE compilation
// These provide minimal type declarations so reversed code compiles
// without requiring the full DirectX SDK or game-specific headers

#pragma once

// ─── Windows types already in <windows.h> ────────────────────
// HKEY, HWND, HINSTANCE, HMODULE, HRESULT, DWORD, etc.
#include <windows.h>

// ─── DirectInput 8 stubs ─────────────────────────────────────
#ifndef DIRECTINPUT_VERSION
#define DIRECTINPUT_VERSION 0x0800
#endif

// Minimal DInput types for compilation
#define DIERR_INPUTLOST    ((HRESULT)0x8007001EL)
#define DIERR_NOTACQUIRED  ((HRESULT)0x8007000CL)

#define DISCL_NONEXCLUSIVE  0x00000002
#define DISCL_FOREGROUND    0x00000001
#define DISCL_BACKGROUND    0x00000008
#define DIEDFL_ATTACHEDONLY 0x00000001
#define DI8DEVCLASS_GAMECTRL 4
#define DIPH_DEVICE         0

typedef struct IDirectInputDevice8W IDirectInputDevice8W;
typedef struct IDirectInput8W IDirectInput8W;

// Minimal DIDATAFORMAT for dinput8 linkage
typedef struct _DIOBJECTDATAFORMAT {
    const GUID* pguid;
    DWORD       dwOfs;
    DWORD       dwType;
    DWORD       dwFlags;
} DIOBJECTDATAFORMAT, *LPDIOBJECTDATAFORMAT;

typedef struct _DIDATAFORMAT {
    DWORD                   dwSize;
    DWORD                   dwObjSize;
    DWORD                   dwFlags;
    DWORD                   dwDataSize;
    DWORD                   dwNumObjs;
    LPDIOBJECTDATAFORMAT    rgodf;
} DIDATAFORMAT, *LPDIDATAFORMAT;

// External data format constants (provided by dinput8.lib)
extern const DIDATAFORMAT c_dfDIKeyboard;
extern const DIDATAFORMAT c_dfDIMouse2;

// DirectInput8 create function
HRESULT WINAPI DirectInput8Create(HINSTANCE, DWORD, REFIID, LPVOID*, LPUNKNOWN);

// ─── Ghidra helper stubs ────────────────────────────────────
// These replace Ghidra-specific constructs

// Security cookie (always succeeds in stub mode)
inline void security_check_cookie(uint32_t) {}

// __alldiv — 64-bit division intrinsic
extern "C" inline int64_t __alldiv(int32_t a1, int32_t a2, int32_t b1, int32_t b2) {
    int64_t a = (int64_t)a1 | ((int64_t)a2 << 32);
    int64_t b = (int64_t)b1 | ((int64_t)b2 << 32);
    return a / b;
}

// ─── Game-specific type stubs ────────────────────────────────
// These are filled in as we discover the real types

// Exception list (SEH)
extern void* ExceptionList;

// Thread-local storage pointer
extern void* ThreadLocalStoragePointer;

// LOCK/UNLOCK primitives (inline assembly for x86)
#define LOCK() __asm { }
#define UNLOCK() __asm { }

// Vector types (placeholder)
struct Vector3 {
    float x, y, z;
};

// ─── MSVC CRT Compatibility Stubs (for MinGW compilation) ─────
// These replace MSVC-specific CRT internals used in the reversed CRT startup code.
// When compiling with MSVC, these are provided by the CRT; MinGW needs stubs.

#ifdef __GNUC__
// __scrt_* functions (MSVC UCRT internals)
extern "C" {
    // CRT initialization (always succeeds in our stub)
    inline char __scrt_initialize_crt(bool) { return 1; }
    // CRT uninitialization (no-op stub)
    inline void __scrt_uninitialize_crt(bool, bool) {}
    // Startup lock (no-op stub)
    inline int  __scrt_acquire_startup_lock() { return 0; }
    inline void __scrt_release_startup_lock(int) {}
    // Runtime error handler (terminates)
    inline void __scrt_throw_runtime_error(int code) { ExitProcess(code); }
    // Command line helper
    inline char* get_narrow_winmain_command_line() { return GetCommandLineA(); }
}

// CRT initializer table markers (MSVC: __xc_a/__xc_z for C++ constructors,
// __xi_a/__xi_z for C initializers). MinGW doesn't use these tables.
// We provide dummy empty arrays. Using void*[] which decays to void**.
extern "C" {
    extern void* __xc_a[1];
    extern void* __xc_z[1];
    extern void* __xi_a[1];
    extern void* __xi_z[1];
}

// _initterm/_initterm_e: iterate initializer tables
// Parameter type matches MSVC signature (void** for array decay)
extern "C" {
    inline void _initterm(void** begin, void** end) {
        for (void** p = begin; p < end; ++p) {
            if (*p) reinterpret_cast<void(*)()>(*p)();
        }
    }
    inline int _initterm_e(void** begin, void** end) {
        for (void** p = begin; p < end; ++p) {
            if (*p) {
                int result = reinterpret_cast<int(*)()>(*p)();
                if (result != 0) return result;
            }
        }
        return 0;
    }
}

// Startup state variable
extern "C" int __scrt_current_native_startup_state;

#endif // __GNUC__
