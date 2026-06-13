// Giants Engine - Main Entry Point (WinMain)
// Reverse engineered from FUN_00643daf (__scrt_common_main_seh)
//
// Call chain: entry @ 0x00643f2e -> FUN_00643daf -> FUN_0062cd40 -> FUN_0062d100

#include "Engine.h"
#include "CRTStubs.h"
#include "stubs.h"
#include "../renderer/RendererLoader.h"
#include "../vfs/VirtualFileSystem.h"
#include <cstdlib>

// MSVC CRT compatibility: these are declared/defined in stubs.h for MinGW
// For MSVC, they come from the CRT headers
extern "C" {
#ifndef __GNUC__
    // MSVC provides these via the CRT
    char  __scrt_initialize_crt(bool);
    void  __scrt_uninitialize_crt(bool, bool);
    int   __scrt_acquire_startup_lock();
    void  __scrt_release_startup_lock(int);
    void  __scrt_throw_runtime_error(int);
    char* get_narrow_winmain_command_line();
    extern void* __xc_a[];
    extern void* __xc_z[];
    extern void* __xi_a[];
    extern void* __xi_z[];
    // MSVC uses void** directly since arrays decay to pointers
    // Cast handled in function call below
    extern int   __scrt_current_native_startup_state;
    int  _initterm_e(void** begin, void** end);
    void _initterm(void** begin, void** end);
#endif
}

namespace Giants {

// CRT startup state
enum StartupState { UNINITIALIZED = 0, INITIALIZING = 1, INITIALIZED = 2 };

// The real WinMain equivalent (FUN_0062cd40)
// Signature matches WinMain: (HINSTANCE, HINSTANCE, LPSTR, int)
// Returns magic value 0x1234 on fatal localization error
int EngineInitializeImpl(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                         char* lpCmdLine, int nCmdShow);

// Main CRT entry point (FUN_00643daf)
int __scrt_common_main_seh()
{
    // CRT initialization
    char crtInit = __scrt_initialize_crt(true);
    if (crtInit == '\0') {
        __scrt_throw_runtime_error(7);
    }

    int lockState = __scrt_acquire_startup_lock();

    // State machine: UNINITIALIZED -> INITIALIZING -> INITIALIZED
    if (__scrt_current_native_startup_state == UNINITIALIZED) {
        __scrt_current_native_startup_state = INITIALIZING;
        if (_initterm_e((void**)&__xc_a[0], (void**)&__xc_z[0]) != 0) return 0xFF;
        _initterm((void**)&__xi_a[0], (void**)&__xi_z[0]);
        __scrt_current_native_startup_state = INITIALIZED;
    } else if (__scrt_current_native_startup_state == INITIALIZING) {
        __scrt_throw_runtime_error(7);
    }

    __scrt_release_startup_lock(lockState);

    // Invoke WinMain
    int nCmdShow = GetStartupShowCmd();  // FUN_0064458d
    char* cmdLine = get_narrow_winmain_command_line();
    int result = EngineInitializeImpl(
        reinterpret_cast<HINSTANCE>(0x400000), nullptr, cmdLine, nCmdShow);

    // _cexit equivalent: exit without cleanup in our stub context
    #ifdef _MSC_VER
    _cexit();
    #else
    // MinGW: the CRT handles cleanup; no explicit call needed
    #endif
    __scrt_uninitialize_crt(true, false);
    return result;
}

// ─── EngineInitializeImpl — FUN_0062cd40 (STUB) ──────────────────
// The real WinMain equivalent. In the original binary, this creates the
// game window, initializes subsystems, and enters MainGameLoop.
// Returns 0 on normal exit, 0x1234 on fatal localization error.
int EngineInitializeImpl(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                         char* lpCmdLine, int nCmdShow)
{
    // RE stub — TODO: implement window creation + MainGameLoop entry
    return 0;
}

} // namespace Giants
