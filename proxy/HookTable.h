#pragma once
// GiantsRE Proxy — Hook Table for Engine→Renderer Callbacks
//
// The engine passes 22 function pointers (UpCalls) to the renderer DLL.
// This table allows us to intercept and replace individual callbacks
// with our own RE'd implementations, one at a time.
//
// Upcall indices (from InitUpCallTable FUN_0062cc40):
//   0  StringCopyHelper      FUN_006299e0
//   1  CleanupHandler         LAB_0062f6d0
//   2  DebugLogString         FUN_004bf140
//   3  ShowErrorDialog        FUN_0062edc0
//   4  ErrorStringAccessor    LAB_006299c0
//   5  SecurityCheck          guard_check_icall
//   6  PostFrameCallback      LAB_0062f6f0
//   7  SceneBegin             LAB_0055e6b0
//   8  SceneEnd               LAB_0055e6d0
//   9  PreRenderCheck         LAB_0055990
//  10  BufferDeallocator      FUN_005e99a0
//  11  GetLocalizedString     FUN_005e80c0
//  12  TextureLoader          LAB_00499ff0
//  13  SinCosLookup           FUN_006387e0
//  14  TimeAccessor           LAB_00629f20
//  15  VFSOpenFileVariant     FUN_006222d0
//  16  VFSOpenMusicFile       FUN_00621fe0
//  17  VFSOpenFile            FUN_00621e50
//  18  SelfReference          LAB_0062cc30
//  19  CRT_free               free
//  20  ShowErrorDialog2       FUN_0062f610
//  21  ScenePipelineEntry     LAB_00522800

#include <cstdint>

namespace HookTable {

constexpr int MAX_HOOKS = 22;

struct HookEntry {
    void*       originalFunc;   // Pointer into GiantsMain.exe (saved from UpCallsLoad)
    void*       hookFunc;       // Our replacement function
    bool        active;         // Whether this hook is enabled
    const char* name;           // Human-readable name for logging
};

// Names for each upcall slot
inline constexpr const char* SLOT_NAMES[MAX_HOOKS] = {
    "StringCopyHelper",      // 0
    "CleanupHandler",         // 1
    "DebugLogString",         // 2
    "ShowErrorDialog",        // 3
    "ErrorStringAccessor",    // 4
    "SecurityCheck",          // 5
    "PostFrameCallback",      // 6
    "SceneBegin",             // 7
    "SceneEnd",               // 8
    "PreRenderCheck",         // 9
    "BufferDeallocator",      // 10
    "GetLocalizedString",     // 11
    "TextureLoader",          // 12
    "SinCosLookup",           // 13
    "TimeAccessor",           // 14
    "VFSOpenFileVariant",     // 15
    "VFSOpenMusicFile",       // 16
    "VFSOpenFile",            // 17
    "SelfReference",          // 18
    "CRT_free",               // 19
    "ShowErrorDialog2",       // 20
    "ScenePipelineEntry",     // 21
};

// ─── API ──────────────────────────────────────────────────────

// Save the original engine callback for slot index
void SetOriginal(int index, void* originalFunc);

// Register a hook function for slot index
void SetHook(int index, void* hookFunc);

// Get the original function pointer for a slot (to call through)
void* GetOriginal(int index);

// Apply all active hooks to the callback table
void Apply(void** callbackTable, uint32_t count);

// Check if a slot is hooked
bool IsHooked(int index);

// Count active hooks
int ActiveHookCount();

// Get the hook table entry (for inspection)
const HookEntry& GetEntry(int index);

} // namespace HookTable
