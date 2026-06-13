#pragma once
// Giants Engine - Renderer DLL Loader
// Reverse engineered from FUN_0062a230 (LoadGDVSystem)

#include <windows.h>
#include <cstdint>

namespace Giants {

// Renderer plugin interface - all gg_*.dll export these 3 functions:
//   GDVSysCreate      - Factory to create the GFX device/system
//   GFXGetCapabilities - Query renderer caps (MSAA, flags, priority, name)
//   UpCallsLoad        - Register engine-to-renderer callbacks

typedef FARPROC (*PFN_GDVSysCreate)();
typedef FARPROC (*PFN_UpCallsLoad)(unsigned long, unsigned long, unsigned long);

struct GFXCapabilityInfo {
    int maxAnisotropy;
    unsigned int flags;          // RendererFlag enum
    int priority;
    char rendererName[32];
    int interfaceVersion;
};

// Global renderer state (from .data section)
extern FARPROC g_GDVSysCreate;      // DAT_00727e50
extern FARPROC g_UpCallsLoad;       // DAT_00727e4c

// Load the renderer DLL and resolve exports
// Returns true if GDVSysCreate and UpCallsLoad were both found
bool LoadGDVSystem();

// Helper: load a DLL module with optional directory prefix (FUN_0062a190, PASS)
void LoadModule(const char* directory, const char* moduleName);

// ─── VFSOpenFile (FUN_00621e50) ──────────────────────────────
// Ghidra: FUN_00621e50 (1 caller, 8 callees)
// Purpose: Open a file through the VFS system. Initializes VFS if needed,
//          resolves the file path, then calls CreateFileA with read-only
//          access. Returns HANDLE or NULL on failure.
HANDLE VFSOpenFile(char* filePath);

// ─── VFSOpenMusicFile (FUN_00621fe0) ─────────────────────────
// Ghidra: FUN_00621fe0 (1 caller, 8 callees)
// Purpose: Open a music/sound file with search path fallback. Iterates up
//          to 4 search paths, builds full path, tries CreateFileA. Updates
//          the last-successful search path index on success.
//          Returns HANDLE or NULL.
HANDLE VFSOpenMusicFile(int fileId);

// ─── VFSOpenFileVariant (FUN_006222d0) ───────────────────────
// Ghidra: FUN_006222d0 (1 caller, 8 callees)
// Purpose: Open a file through the VFS system using alternate path
//          resolution functions (FUN_00624a10/FUN_006242d0 instead of
//          FUN_00623f00/FUN_00623dc0). Returns HANDLE or NULL.
HANDLE VFSOpenFileVariant();

// ─── BufferDeallocator (FUN_005e99a0) ────────────────────────
// Ghidra: FUN_005e99a0 (1 caller, 1 callee)
// Purpose: Release a renderer buffer. Checks if buffer data pointer is
//          non-null and the "owns memory" flag is set, then frees the
//          data and clears the ownership flag.
void BufferDeallocator(int* bufferDesc);

// ─── DebugLogString (FUN_004bf140) ───────────────────────────
// Ghidra: FUN_004bf140 (1 caller, 1 callee)
// Purpose: Print a debug/log string if the debug logging flag is enabled.
//          Computes string length, outputs it via the debug channel, and
//          increments the debug message counter.
void DebugLogString(char* message);

// ─── ShowErrorDialog (FUN_0062f610) ──────────────────────────
// Ghidra: FUN_0062f610 (1 caller, 5 callees)
// Purpose: Display a "Giants Error" dialog box. Formats a message into
//          a stack buffer, shows MessageBoxA with MB_ABORTRETRYIGNORE,
//          and sets the global abort flag if user picks Abort or Cancel.
void ShowErrorDialog(uint32_t param_1, uint32_t param_2);

// ─── StringCopyHelper (FUN_006299e0) ─────────────────────────
// Ghidra: FUN_006299e0 (28 callers, 4 callees)
// Purpose: Variadic error/status string logger. Formats a message via
//          wvsprintfA into a 256-byte stack buffer, appends "\r\n",
//          and copies the result to the global status string at DAT_007280d0.
void StringCopyHelper(const char* format, ...);

} // namespace Giants
