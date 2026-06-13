// ============================================================================
// Giants: Citizen Kabuto — Unified Type Definitions (Ground Truth)
// ============================================================================
// Generated from Ghidra 12.1.2 exports (103 structs) + manual RE analysis
// Binary: GiantsMain.exe v1.520.59 (x86 32-bit, sizeof(void*) = 4)
// Engine: Amityville (Planet Moon Studios, 2000)
// ============================================================================
//
// Ghidra's auto-analysis captured only Win32/PE/CRT infrastructure types.
// Game-specific structs have been reconstructed from function RE and are
// organized below by module. Address annotations reference the Ghidra project.
//
// STRUCT INVENTORY:
//   Ghidra auto-detected : 103 (Win32/PE/CRT/EH -- not included here,
//                          use <windows.h> and standard headers instead)
//   Game-specific (manual):  7 (RenderState, GFXCapabilityInfo, VFSFileEntry,
//                          LightDir, DisplaySettings, PlayerProfile, RendererExports)
//   Global variable bindings: documented per-module
// ============================================================================

#pragma once

#include <cstdint>
#include <cmath>
#include <windows.h>
#include "../../stubs/stubs.h"

namespace Giants {

// ============================================================================
// Module: ENGINE — Core Engine Types
// ============================================================================

// ─── Render State Save/Restore ──────────────────────────────────────────────
// Used by ProcessGameLogic (FUN_00524f30) to save/restore 18 render-state
// registers across scene rendering. Fields encode target memory offsets.
// Total size: 0x58 bytes (88 bytes)
struct RenderState {
    int32_t  unk_c8;                // @ 0x00 — unknown control field
    int32_t  unk_c4;                // @ 0x04 — unknown control field
    uint8_t  pad1[4];               // @ 0x08 — alignment padding
    uint8_t  pad2[4];               // @ 0x0C — alignment padding
    uint32_t state_b4;              // @ 0x10 — render state for 0x006857b4
    uint32_t state_b0;              // @ 0x14 — render state for 0x006857b0
    uint32_t state_ac;              // @ 0x18 — render state for 0x006857ac
    uint32_t state_a8;              // @ 0x1C — render state for 0x006857a8
    uint32_t state_a4;              // @ 0x20 — render state for 0x006857a4
    uint32_t state_a0;              // @ 0x24 — render state for 0x006857a0
    uint32_t state_9c;              // @ 0x28 — render state for 0x0068579c
    uint32_t state_94;              // @ 0x2C — render state for 0x00685794
    uint32_t state_98;              // @ 0x30 — render state for 0x00685798
    uint32_t state_90;              // @ 0x34 — render state for 0x00685790
    uint32_t state_8c;              // @ 0x38 — render state for 0x0068578c
    uint32_t state_88;              // @ 0x3C — render state for 0x00685788
    uint32_t state_84;              // @ 0x40 — render state for 0x00685784
    uint32_t state_80;              // @ 0x44 — render state for 0x00685780
    uint32_t state_7c;              // @ 0x48 — render state for 0x0068577c
    uint32_t state_78;              // @ 0x4C — render state for 0x00685778
    uint32_t state_74;              // @ 0x50 — render state for 0x00685774
    uint32_t state_70;              // @ 0x54 — render state for 0x00685770
};
static_assert(sizeof(RenderState) == 0x58, "RenderState size mismatch");

// ─── Engine Global Variables ────────────────────────────────────────────────
// Bound to addresses in .data/.bss sections of GiantsMain.exe

// Timing (FUN_00629f50 — UpdateTime)
extern float    g_deltaTime;            // DAT_00727e40 — raw frame delta (seconds)
extern float    g_smoothedTime;         // DAT_00727e3c — exponentially smoothed delta
extern float    g_timeMultiplier;       // DAT_00727e38 — final time scale
extern float    g_baseTimeScale;        // DAT_00727e48 — base multiplier (1.0)
extern uint32_t g_lastTick;             // DAT_0074da5c — last GetTickCount value
extern uint8_t  g_isPaused;             // DAT_00702b1f — game paused
extern uint8_t  g_isSlowMotion;         // DAT_00702b1e — slow motion active
extern uint8_t  g_isFixedTimestep;      // DAT_00702be8 — force 1/60s delta

// Game Logic (FUN_00524f30 — ProcessGameLogic)
extern bool     g_frameActive;          // DAT_00702b1d — frame processing active
extern int      g_frameTimer;           // DAT_00702890 — accumulated time
extern int      g_frameCount2;          // DAT_00702894 — frame counter
extern int      g_countdownActive;      // DAT_0074bc18 — countdown running
extern bool     g_cutsceneMode;         // DAT_00702aec — cutscene mode
extern float    g_countdownTimer;       // DAT_0074bbbc — countdown remaining
extern int      g_renderMode;           // DAT_00702a58 — render target mode
extern int      g_sceneReady;           // DAT_00702770 — scene/renderer object
extern void*    g_rendererObj;          // DAT_00702700 — primary renderer COM
extern void*    g_renderCtx;            // DAT_00702714 — secondary render context
extern float    g_camX;                 // DAT_0074bb90 — camera X
extern float    g_camY;                 // DAT_0074bb94 — camera Y
extern float    g_camTargetX;           // DAT_0074bb98 — camera target X
extern float    g_camTargetY;           // DAT_0074bb9c — camera target Y

// Window (FUN_0062ea70 — WndProc)
extern BOOL     g_bClipCursor;          // DAT_007282c0 — fullscreen clip
extern BOOL     g_bActive;              // DAT_007282d0 — window active
extern BOOL     g_bRenderReady;         // DAT_007281d4 — renderer initialized
extern BOOL     g_bPaused;              // DAT_00702aed — app paused
extern HMONITOR g_hCurrentMonitor;      // DAT_0074c46c — current monitor

// Engine state
extern bool     g_initialized;          // DAT_007282bc — engine initialized
extern bool     g_rendererActive;       // DAT_00702bd0
extern char     g_rendererAvailable;    // DAT_00702b5a

// Timing constants (from .rdata) — defined in Timer.h to avoid duplication
// constexpr double kTickToSeconds    = 0.001;
// constexpr float  kMaxSmoothing     = 0.75f;
// constexpr float  kFixedDelta       = 1.0f / 60.0f;
// constexpr double kAbsHelper[2]     = {0.0, -2.0};


// ============================================================================
// Module: RENDERER — Graphics / Renderer Plugin Types
// ============================================================================

// ─── Renderer Plugin Interface ──────────────────────────────────────────────
// All gg_*.dll renderer plugins export these 3 functions:
//   GDVSysCreate       — Factory to create the GFX device/system object
//   GFXGetCapabilities — Query renderer caps (MSAA, flags, priority, name)
//   UpCallsLoad        — Register engine-to-renderer callbacks
//
// Renderer DLLs: gg_dx9r.dll, gg_dx11r.dll, gg_dx12r.dll
// Interface version tracked in GFXCapabilityInfo::interfaceVersion

typedef FARPROC (*PFN_GDVSysCreate)();
typedef FARPROC (*PFN_UpCallsLoad)(unsigned long, unsigned long, unsigned long);

// Renderer capability descriptor (48 bytes)
// Returned by the GFXGetCapabilities export from each renderer DLL
struct GFXCapabilityInfo {
    int          maxAnisotropy;      // @ 0x00 — max anisotropic filtering level
    unsigned int flags;              // @ 0x04 — RendererFlag bitmask
    int          priority;           // @ 0x08 — renderer load priority (higher = preferred)
    char         rendererName[32];   // @ 0x0C — human-readable name (e.g. "DX9 Renderer")
    int          interfaceVersion;   // @ 0x2C — interface version for ABI check
};
static_assert(sizeof(GFXCapabilityInfo) == 48, "GFXCapabilityInfo size mismatch");

// Resolved exports stored in .data section
struct RendererExports {
    PFN_GDVSysCreate  pGDVSysCreate;     // DAT_00727e50 — factory function
    PFN_UpCallsLoad   pUpCallsLoad;      // DAT_00727e4c — callback registration
    // NOTE: GFXGetCapabilities is resolved per-call, not stored globally
};

// ─── Renderer Global Variables ──────────────────────────────────────────────

extern FARPROC g_GDVSysCreate;          // DAT_00727e50
extern FARPROC g_UpCallsLoad;           // DAT_00727e4c
extern void*   g_renderDevice;          // DAT_00702700 — primary renderer COM object
extern void*   g_d3d9Device;            // IDirect3DDevice9* found inside renderer object
extern char    g_rendererName[32];      // DAT_007281f0 — renderer DLL name

// ─── Display Settings ───────────────────────────────────────────────────────
// Stored as individual DWORD globals at 0x00702b80–0x00702bac
// These are read from / written to the registry at
//   HKCU\Software\PlanetMoon\Giants\DisplaySettings

struct DisplaySettings {
    DWORD width;               // @ 0x00 — DAT_00702b80
    DWORD height;              // @ 0x04 — DAT_00702b84
    DWORD bitDepth;            // @ 0x08 — DAT_00702b88
    DWORD refreshRate;         // @ 0x0C — DAT_00702b8c
    DWORD backBufferCount;     // @ 0x10 — DAT_00702b8d (note: byte-sized in binary)
    DWORD multisampleType;     // @ 0x14 — DAT_00702b8e (note: word-sized in binary)
    DWORD windowed;            // @ 0x18 — DAT_00702b90
    DWORD vsync;               // @ 0x1C — DAT_00702b94
    DWORD adapterOrdinal;      // @ 0x20 — DAT_00702b98
    DWORD displayMode0;        // @ 0x24 — DAT_00702ba0 (mode comparison byte 0)
    DWORD displayMode1;        // @ 0x28 — DAT_00702ba4
    DWORD displayMode2;        // @ 0x2C — DAT_00702ba8
    DWORD displayMode3;        // @ 0x30 — DAT_00702bac
};
// NOTE: DisplaySettings fields are NOT contiguous in memory — each has its own
// address. This struct is for logical grouping only, not memory-mapped access.

// Display settings globals (individually addressed)
extern DWORD g_width;
extern DWORD g_height;
extern DWORD g_bitDepth;
extern DWORD g_refreshRate;
extern DWORD g_backBufferCount;
extern DWORD g_multisampleType;
extern DWORD g_windowed;
extern DWORD g_vsync;
extern DWORD g_adapterOrdinal;
extern DWORD g_displayMode0;
extern DWORD g_displayMode1;
extern DWORD g_displayMode2;
extern DWORD g_displayMode3;

// ─── Light Direction (Scene Pipeline) ───────────────────────────────────────
// Used in EndSceneDirectional (FUN_00524c10) for 6-pass directional light render
// Local struct, not persisted — created on stack per render pass

struct LightDir {
    float x;                   // @ 0x00 — direction vector X
    float y;                   // @ 0x04 — direction vector Y
    float z;                   // @ 0x08 — direction vector Z
    float w;                   // @ 0x0C — intensity
    float right;               // @ 0x10 — orientation right
    float up;                  // @ 0x14 — orientation up
    float forward;             // @ 0x18 — orientation forward (depth)
};
static_assert(sizeof(LightDir) == 28, "LightDir size mismatch");


// ============================================================================
// Module: VFS — Virtual File System Types
// ============================================================================

// GZP archive format constants
constexpr uint32_t GZP_MAGIC = 0x6608F101;   // GZP archive header magic
constexpr uint32_t ZIP_MAGIC = 0x4034B50;     // PK\x03\x04 (standard ZIP)

// File entry in a GZP archive index
// The archive index consists of these entries packed sequentially.
// fileName is a flexible array member (variable length, null-terminated).
struct VFSFileEntry {
    unsigned int compressedSize;    // @ 0x00 — compressed data size in bytes
    unsigned int uncompressedSize;  // @ 0x04 — original (decompressed) size
    unsigned int fileDate;          // @ 0x08 — DOS file datestamp
    unsigned int compressionType;   // @ 0x0C — compression algorithm (0=none, 1=LZ77)
    char         fileName[1];       // @ 0x10 — variable-length name (FAM)
};


// ============================================================================
// Module: INPUT — DirectInput Types
// ============================================================================

// ─── Keyboard State ─────────────────────────────────────────────────────────
// 256-bit key state = 8 x DWORD = 256 bits (one bit per virtual key)
// Updated by ProcessRawKeyboardInput (FUN_0062aac0)

struct KeyboardState {
    DWORD keys[8];             // @ 0x00 — 256-bit current key state
    DWORD latch[8];            // @ 0x20 — 256-bit press-event latch
};
// g_keyState[8]     @ DAT_00727e60 — current key state
// g_keyPressLatch[8] @ DAT_00727e80 — press event latch (OR'd on key-down)

extern DWORD g_keyState[8];
extern DWORD g_keyPressLatch[8];

// ─── Mouse State ────────────────────────────────────────────────────────────
// Updated by ProcessMouseInput (FUN_0062abe0)

struct MouseState {
    uint32_t xState;           // @ 0x00 — DAT_00727fbc
    uint32_t yState;           // @ 0x04 — DAT_00727fc0
    uint32_t scrollState;      // @ 0x08 — DAT_00727fc4
    uint32_t prevState;        // @ 0x0C — DAT_00727fd8
    uint32_t currState;        // @ 0x10 — DAT_00727fdc
    uint32_t pressedBits;      // @ 0x14 — DAT_00727fe0 (new & ~old)
    uint32_t prevRawState;     // @ 0x18 — DAT_00727fe4
};

// ─── DirectInput Device Globals ─────────────────────────────────────────────

extern IDirectInput8W*        g_pDI;                // DAT_00727f20
extern IDirectInputDevice8W*  g_pKeyboardDevice;     // DAT_00727e5c
extern IDirectInputDevice8W*  g_pMouseDevice;        // DAT_00727f24
extern IDirectInputDevice8W** g_pControllers;        // DAT_00727e58
extern int     g_nControllerCount;                   // DAT_00702b04
extern DWORD   g_dwMouseBufferSize;                  // DAT_00727f28
extern HRESULT g_lastResult;                         // DAT_007281d0

// Raw input
extern int*    g_rawInputDevice;                     // DAT_00727e5c
extern HRESULT g_rawInputResult;                     // DAT_007281d0


// ============================================================================
// Module: GAME — Player Profile / Registry Types
// ============================================================================

// ─── Player Profile ─────────────────────────────────────────────────────────
// Player data is stored in the registry at:
//   HKCU\Software\PlanetMoon\Giants\Players\<playerName>
// No single contiguous struct in the binary — data is read/written as individual
// registry values. This struct captures the logical grouping.

struct PlayerProfile {
    DWORD playerId;            // DAT_007028b0 — active player identifier
    DWORD playerId1;           // DAT_007028a0 — secondary player id
    DWORD playerId2;           // DAT_007028a4 — tertiary player id
    float aspectRatioX;        // DAT_00702c1c — display aspect ratio X
    float aspectRatioY;        // DAT_00702c20 — display aspect ratio Y
};

// Registry handles
extern HKEY  g_hKey;                    // DAT_0074be54 — Giants root key
extern HKEY  g_hPlayerKey;              // DAT_0074be5c — current player subkey
extern HKEY  g_hPlayerRootKey;          // DAT_0074be58 — players root key

// Player globals
extern DWORD g_playerId;                // DAT_007028b0
extern DWORD g_playerId1;               // DAT_007028a0
extern DWORD g_playerId2;               // DAT_007028a4
extern float g_aspectRatioX;            // DAT_00702c1c
extern float g_aspectRatioY;            // DAT_00702c20


// ============================================================================
// Module: GHIDRA — Win32/PE Infrastructure (Reference Only)
// ============================================================================
// The 103 structs from Ghidra auto-analysis are ALL standard Win32/PE/CRT/EH
// types. They are NOT game-specific and should be accessed through their
// standard Windows headers rather than redefined here.
//
// Full list of Ghidra-detected structs (for reference):
//
// Win32 System:
//   _BY_HANDLE_FILE_INFORMATION (52 bytes)
//   _CONSOLE_SCREEN_BUFFER_INFO (22 bytes)
//   _CONTEXT (716 bytes)
//   _COORD (4 bytes)
//   _EXCEPTION_POINTERS (8 bytes)
//   _EXCEPTION_RECORD (80 bytes)
//   _FILETIME (8 bytes)
//   _FLOATING_SAVE_AREA (112 bytes)
//   _GUID / GUID / IID / UUID (16 bytes)
//   _LARGE_INTEGER (8 bytes)
//   _LIST_ENTRY (8 bytes)
//   _MEMORYSTATUSEX (64 bytes)
//   _OVERLAPPED (20 bytes)
//   _RTL_CONDITION_VARIABLE (4 bytes)
//   _RTL_CRITICAL_SECTION (24 bytes)
//   _RTL_CRITICAL_SECTION_DEBUG (32 bytes)
//   _RTL_RUN_ONCE (4 bytes)
//   _RTL_SRWLOCK (4 bytes)
//   _SECURITY_ATTRIBUTES (12 bytes)
//   _SINGLE_LIST_ENTRY (4 bytes)
//   _SLIST_HEADER (8 bytes)
//   _SMALL_RECT (8 bytes)
//   _STARTUPINFOW (68 bytes)
//   _SYSTEMTIME (16 bytes)
//   _TIME_DYNAMIC_ZONE_INFORMATION (432 bytes)
//   _WIN32_FIND_DATAA (320 bytes)
//   _WIN32_FIND_DATAW (592 bytes)
//   CLIENT_ID (8 bytes)
//   tagBITMAPINFO (44 bytes)
//   tagBITMAPINFOHEADER (40 bytes)
//   tagCOMPOSITIONFORM (28 bytes)
//   tagLOGFONTA (60 bytes)
//   tagMONITORINFO (40 bytes)
//   tagMSG (28 bytes)
//   tagPOINT (8 bytes)
//   tagRECT (16 bytes)
//   tagRGBQUAD (4 bytes)
//   tagSIZE (8 bytes)
//   tagWNDCLASSA (40 bytes)
//   tm (36 bytes)
//
// PE/Executable Format:
//   IMAGE_DATA_DIRECTORY (8 bytes)
//   IMAGE_DEBUG_DIRECTORY (28 bytes)
//   IMAGE_DIRECTORY_ENTRY_EXPORT (40 bytes)
//   IMAGE_DOS_HEADER (128 bytes)
//   IMAGE_FILE_HEADER (20 bytes)
//   IMAGE_LOAD_CONFIG_CODE_INTEGRITY (12 bytes)
//   IMAGE_LOAD_CONFIG_DIRECTORY32 (160 bytes)
//   IMAGE_NT_HEADERS32 (248 bytes)
//   IMAGE_OPTIONAL_HEADER32 (224 bytes)
//   IMAGE_RESOURCE_DATA_ENTRY (16 bytes)
//   IMAGE_RESOURCE_DIRECTORY (16 bytes)
//   IMAGE_RESOURCE_DIRECTORY_ENTRY (8 bytes)
//   IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryStruct (4 bytes)
//   IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryUnion (4 bytes)
//   IMAGE_RESOURCE_DIRECTORY_ENTRY_NameStruct (4 bytes)
//   IMAGE_RESOURCE_DIRECTORY_ENTRY_NameUnion (4 bytes)
//   IMAGE_SECTION_HEADER (40 bytes)
//   IMAGE_THUNK_DATA32 (24 bytes)
//   DotNetPdbInfo (60 bytes)
//   StringFileInfo / StringInfo / StringTable (6 bytes each)
//   Var / VarFileInfo (6 bytes each)
//   VS_VERSION_INFO (92 bytes)
//   Misc (4 bytes)
//   SectionFlags (enum)
//   IMAGE_GUARD_FLAGS (enum)
//
// CRT / EH / RTTI:
//   _iobuf (32 bytes)
//   _s_CatchableType (28 bytes)
//   _s_CatchableTypeArray (4 bytes)
//   _s_ESTypeList (8 bytes)
//   _s_FuncInfo (36 bytes)
//   _s_HandlerType (16 bytes)
//   _s_ThrowInfo (16 bytes)
//   _s_TryBlockMapEntry (20 bytes)
//   _s_UnwindMapEntry (8 bytes)
//   _s__RTTIBaseClassDescriptor (28 bytes)
//   _s__RTTIClassHierarchyDescriptor (16 bytes)
//   _s__RTTICompleteObjectLocator (20 bytes)
//   TypeDescriptor (8 bytes)
//   PMD (12 bytes)
//   lconv (80 bytes)
//   IUnknown (4 bytes)
//   IUnknownVtbl (12 bytes)
//
// Handle Wrappers (4 bytes each):
//   HACCEL__, HBITMAP__, HBRUSH__, HDC__, HFONT__, HICON__,
//   HIMC__, HINSTANCE__, HKEY__, HMENU__, HMONITOR__, HWND__
//
// Internal Unions/Sub-structs:
//   _struct_19, _struct_20, _struct_299, _struct_519, _struct_531
//   _union_518, _union_530
//
// Enumerations:
//   _FILE_INFO_BY_HANDLE_CLASS, _FINDEX_INFO_LEVELS,
//   _FINDEX_SEARCH_OPS, _GET_FILEEX_INFO_LEVELS
//
// Typedefs (aliased to base types):
//   __ehstate_t, __int64, __time64_t, __uint64,
//   ACCESS_MASK, ATOM, BITMAPINFO, BITMAPINFOHEADER, BOOL, BOOLEAN, BYTE,
//   CHAR, COLORREF, CONTEXT, COORD, DWORD, DWORD_PTR, DWORDLONG,
//   errno_t, ESTypeList, EXCEPTION_RECORD, FARPROC, FILE,
//   FILE_INFO_BY_HANDLE_CLASS, FILETIME, FINDEX_INFO_LEVELS,
//   FINDEX_SEARCH_OPS, FLOATING_SAVE_AREA, fpos_t, FuncInfo,
//   GET_FILEEX_INFO_LEVELS, GUID, HACCEL, HANDLE, HandlerType,
//   HBITMAP, HBRUSH, HCURSOR, HDC, HFONT, HGDIOBJ, HGLOBAL, HICON,
//   HIMC, HINSTANCE, HKEY, HLOCAL, HMENU, HMODULE, HMONITOR, HRESULT,
//   HWND, IID, ImageBaseOffset32, LARGE_INTEGER, LCTYPE, LIST_ENTRY,
//   LOGFONTA, LONG, LONG_PTR, LONGLONG, LPARAM, LPBOOL,
//   LPBY_HANDLE_FILE_INFORMATION, LPBYTE, LPCOMPOSITIONFORM,
//   LPCRITICAL_SECTION, LPCSTR, LPCVOID, LPCWSTR, LPDWORD, LPFILETIME,
//   LPINIT_ONCE, LPMEMORYSTATUSEX, LPMONITORINFO, LPMSG, LPOVERLAPPED,
//   LPRECT, LPSECURITY_ATTRIBUTES, LPSIZE, LPSTARTUPINFOW, LPSTR,
//   LPSYSTEM_INFO, LPTOP_LEVEL_EXCEPTION_FILTER, LPUNKNOWN, LPVOID,
//   LPWIN32_FIND_DATAA, LPWIN32_FIND_DATAW, LPWSTR, LRESULT, LSTATUS,
//   MMRESULT, MSG, PBOOL, PCONDITION_VARIABLE, PCONSOLE_SCREEN_BUFFER_INFO,
//   PCONTEXT, PDYNAMIC_TIME_ZONE_INFORMATION, PEXCEPTION_RECORD,
//   PFILETIME, PHKEY, PLONG, PMFN, POINT, PRTL_CRITICAL_SECTION,
//   PRTL_CRITICAL_SECTION_DEBUG, PRTL_RUN_ONCE, PSLIST_HEADER, PSRWLOCK,
//   PTOP_LEVEL_EXCEPTION_FILTER, ptrdiff_t, PUINT, PVOID, RECT, REGSAM,
//   RGBQUAD, RPC_STATUS, RTL_CONDITION_VARIABLE, RTL_SRWLOCK,
//   RTTIBaseClassDescriptor, RTTIClassHierarchyDescriptor,
//   RTTICompleteObjectLocator, SHORT, SINGLE_LIST_ENTRY, SIZE_T, size_t,
//   SMALL_RECT, SYSTEMTIME, ThrowInfo, TryBlockMapEntry, UINT, UINT_PTR,
//   uintptr_t, ULONG, ULONG_PTR, ULONGLONG, UnwindMapEntry, UUID,
//   va_list, WCHAR, WNDCLASSA, WNDPROC, WORD, WPARAM

// ─── World Transform (DAT_0074bb60) ────────────────────────────
// Used by SetWorldTransform (FUN_005fa1a0) to pass world/view matrix
// to renderer via vtable calls.
struct WorldTransform {
    float tx, ty, tz;             // Translation components
    float m00, m01, m02;          // Column 0 (right)
    float m10, m11, m12;          // Column 1 (up)
    float m20, m21, m22;          // Column 2 (forward)
};
static_assert(sizeof(WorldTransform) == 48, "WorldTransform size mismatch");

// Global world transform (defined in ScenePipeline.cpp)
extern WorldTransform g_worldTransform;     // DAT_0074bb60


// ============================================================================
// Module: SDK-DERIVED — Types confirmed by community SDK (Patch 1.5)
// ============================================================================
// These types were discovered by cross-referencing the ncblakely Patch 1.5 SDK
// headers against the RE'd binary. They eliminate magic numbers, unify scattered
// float fields, and enable the next phase of reverse engineering.
//
// Tier 1: Confirms existing RE findings, eliminates magic numbers.
// Tier 2: Enables next phase of RE (input processing, culling, matrices).
// ============================================================================

// ─────────────── Tier 1 — Confirmed by SDK comparison ──────────────────────

// ─── Renderer Flags (explains GFXCapabilityInfo.flags and DisplaySettings) ──
enum class RendererFlag : uint32_t {
    None          = 0x0,
    Unused        = 0x1,
    MSAA2x        = 0x2,
    MSAA4x        = 0x4,
    MSAA8x        = 0x8,
    MSAA16x       = 0x10,
    VSync         = 0x20,
    TripleBuffer  = 0x40,
    Fullscreen    = 0x80,
};

// ─── P3D — Unified 3D point/vector (camera, light, transform) ───────────────
// Unifies scattered float triplets found throughout camera, light direction,
// and world transform code paths.
struct P3D {
    float x, y, z;
    float Length() const { return sqrtf(x*x + y*y + z*z); }
    float LengthSq() const { return x*x + y*y + z*z; }
    void Normalize() { float l = Length(); if (l > 0) { x/=l; y/=l; z/=l; } }
    static float Dot(const P3D& a, const P3D& b) { return a.x*b.x + a.y*b.y + a.z*b.z; }
    static P3D Cross(const P3D& a, const P3D& b) { return {a.y*b.z-a.z*b.y, a.z*b.x-a.x*b.z, a.x*b.y-a.y*b.x}; }
};

// ─── NetPlayerState (explains DAT_006866c4 state machine, 15 states) ────────
enum class NetPlayerState : int {
    None = 0, Setup = 1, HostConfiguring = 2, HostWaiting = 3,
    HostLoading = 4, HostPlaying = 5, ClientConfiguring = 6,
    ClientConnecting = 7, ClientWaiting = 8, ClientLoading = 9,
    ClientPlaying = 10, ClientSpectating = 11, ClientDownloading = 12,
    Disconnecting = 13, Active = 14
};

// ─── GameTeam — Team/game mode enumeration ───────────────────────────────────
enum class GameTeam : int {
    None = -1, MvM = 0, MvMvM = 1, RvR = 2, MvR = 3, MvRvK = 4, MvK = 5, RvK = 6
};

// ─── GBS/GB2 — Model file format constants ───────────────────────────────────
constexpr uint32_t GBS_VERSION    = 0xAA0100BE;
constexpr uint32_t GB2_VERSION    = 0xAA0100AB;
constexpr uint32_t GBS_FLAG_NORMALS = 0x0001;
constexpr uint32_t GBS_FLAG_UVS     = 0x0002;
constexpr uint32_t GBS_FLAG_RGBS    = 0x0004;
constexpr uint32_t GBS_FLAG_MAXLIT  = 0x80000000;

// ─── SDK Utility Macros ──────────────────────────────────────────────────────
#define GIANTS_PI 3.14159265358979f
#define FlagSet(b,f)    ((b) |= (f))
#define FlagClear(b,f)  ((b) &= ~(f))
#define FlagIsSet(b,f)  (((b) & (f)) != 0)
#define FlagFlip(b,f)   ((b) ^= (f))


// ─────────────── Tier 2 — Enables next RE phase ────────────────────────────

// ─── MoveCommand (key to TimerTick FUN_004ad640) ─────────────────────────────
struct MoveCommand {
    int8_t  Turn;          // yaw input (-128..+127)
    int8_t  LookUpDown;    // pitch input
    int8_t  Run;           // forward/backward
    int8_t  Side;          // strafe left/right
    int8_t  Thrust;        // vertical (jetpack)
    uint32_t Flags;        // modifier flags
    float   TurnGoal;      // target heading
    P3D     MoveGoal;      // movement target position
};
static_assert(sizeof(MoveCommand) == 28, "MoveCommand size mismatch");

// ─── BBOX — Axis-aligned bounding box (needed for SceneBegin culling) ────────
struct BBOX {
    P3D min, max;
};

// ─── M4X4 — Full 4x4 matrix ─────────────────────────────────────────────────
struct M4X4 {
    union {
        struct { float _11,_12,_13,_14, _21,_22,_23,_24, _31,_32,_33,_34, _41,_42,_43,_44; };
        float m[4][4];
        float f[16];
    };
};

// ─── VertRGB, UV — Model format vertex attributes ────────────────────────────
struct VertRGB { uint8_t r, g, b; };
struct UV { float u, v; };

} // namespace Giants
