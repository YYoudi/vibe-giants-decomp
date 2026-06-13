// Giants Engine - Renderer DLL Loader
// Reverse engineered from FUN_0062a230 (LoadGDVSystem)
#include <cstdlib>
#include <cstring>
#include "RendererLoader.h"
#include "engine/TraceLog.h"
#include <cstdint>
#include <cstdio>

namespace Giants {

// ─── Renderer global variable definitions ─────────────────────────
FARPROC g_GDVSysCreate = nullptr;   // DAT_00727e50
FARPROC g_UpCallsLoad  = nullptr;   // DAT_00727e4c

// Forward declarations (defined later in this file or externally)
HMODULE LoadRendererDLL();           // FUN_0062a190 — defined below
void DebugLog(const char* message);  // FUN_0062edc0 — external

// Load failure flag
static int g_LoadFailed = 0;

// Initialize upcall table for engine->renderer callbacks
void InitUpCallTable(uint32_t* outParams);  // FUN_0062cc40

bool LoadGDVSystem()
{
    TRACE_FUNC;
    const char* errorMsg = nullptr;

    HMODULE hModule = LoadRendererDLL();
    if (hModule == nullptr)
    {
        if (g_traceLog) { fprintf(g_traceLog, "[TRACE] LoadRendererDLL returned NULL\n"); fflush(g_traceLog); }
        return false;
    }
    if (g_traceLog) { fprintf(g_traceLog, "[TRACE] LoadRendererDLL OK: module=%p\n", (void*)hModule); fflush(g_traceLog); }

    g_GDVSysCreate = GetProcAddress(hModule, "GDVSysCreate");
    if (g_GDVSysCreate == nullptr)
    {
        if (g_LoadFailed != 0) return false;
        errorMsg = "Failed to load GDVSysCreate";
    }
    else
    {
        if (g_traceLog) { fprintf(g_traceLog, "[TRACE] GDVSysCreate=%p\n", (void*)g_GDVSysCreate); fflush(g_traceLog); }

        FARPROC pUpCallsLoad = GetProcAddress(hModule, "UpCallsLoad");
        if (pUpCallsLoad != nullptr)
        {
            g_UpCallsLoad = pUpCallsLoad;
            if (g_traceLog) { fprintf(g_traceLog, "[TRACE] UpCallsLoad=%p\n", (void*)pUpCallsLoad); fflush(g_traceLog); }

            // Initialize the callback table (3 uint32_t: version, count, tablePtr)
            uint32_t callbacks[3] = {};
            InitUpCallTable(callbacks);

            if (g_traceLog) { fprintf(g_traceLog, "[TRACE] InitUpCallTable: ver=0x%X, count=%u, table=0x%08X\n",
                callbacks[0], callbacks[1], callbacks[2]); fflush(g_traceLog); }

            // UpCallsLoad signature: void(uint32_t version, uint32_t count, uint32_t tablePtr)
            // callbacks[0] = version (0x2775), callbacks[1] = count (22), callbacks[2] = table
            reinterpret_cast<void(*)(uint32_t, uint32_t, uint32_t)>(pUpCallsLoad)(
                callbacks[0], callbacks[1], callbacks[2]);

            if (g_traceLog) { fprintf(g_traceLog, "[TRACE] UpCallsLoad returned OK\n"); fflush(g_traceLog); }
            return true;
        }

        g_UpCallsLoad = nullptr;
        if (g_LoadFailed != 0) return false;
        errorMsg = "Failed to load UpCallsLoad";
    }

    DebugLog(errorMsg);
    g_LoadFailed = 1;
    return false;
}

} // namespace Giants

// ═══════════════════════════════════════════════════════════════════
// InitUpCallTable — FUN_0062cc40 (STUB)
// ═══════════════════════════════════════════════════════════════════
// Initializes the engine-to-renderer callback table.
// Fills a structure with function pointers that the renderer DLL
// calls back into the engine. Also sets version info.
// 2 callers, 0 callees — pure data initialization.
//
// The callback table (at DAT_0074c410) contains ~20 function pointers:
//   [0x00] FUN_006299e0    — string copy helper
//   [0x04] LAB_0062f6d0    — cleanup handler
//   [0x08] FUN_004bf140    — resource manager
//   [0x0C] FUN_0062edc0    — ShowErrorDialog
//   [0x10] LAB_006299c0    — error string accessor
//   [0x14] guard_check_icall — security check
//   [0x18] LAB_0062f6f0    — post-frame callback
//   [0x1C] LAB_0055e6b0    — scene begin
//   [0x20] LAB_0055e6d0    — scene end
//   [0x24] LAB_005e9990    — pre-render check
//   [0x28] FUN_005e99a0    — render dispatch
//   [0x2C] FUN_005e80c0    — GetLocalizedString
//   [0x30] LAB_00499ff0    — texture loader
//   [0x34] FUN_006387e0    — SinCosLookup
//   [0x38] LAB_00629f20    — time accessor
//   [0x3C] FUN_006222d0    — VFS open
//   [0x40] FUN_00621fe0    — VFS read
//   [0x44] FUN_00621e50    — VFS close
//   [0x48] LAB_0062cc30    — self-reference
//   [0x4C] free             — CRT free
//   [0x50] FUN_0062f610    — resource free
//   [0x54] LAB_00522800    — scene pipeline entry

namespace Giants {

// ─── Safe callback stubs for renderer upcall table ────────────
// These must be real cdecl functions (not lambdas) for MinGW.
// Return 0/nullptr to avoid crashes when renderer reads return values.
// Logging is suppressed after the first N calls to avoid log spam.

static volatile long g_cbLogCount = 0;
static const long CB_LOG_LIMIT = 200;  // Only log first 200 callback invocations total

static void*  __cdecl Stub_ReturnNull() {
    if (g_traceLog && InterlockedIncrement(&g_cbLogCount) <= CB_LOG_LIMIT) {
        fprintf(g_traceLog, "[CB] ReturnNull called (return addr: %p)\n",
            __builtin_return_address(0)); fflush(g_traceLog); }
    return nullptr;
}
static void   __cdecl Stub_NoOp() {
    if (g_traceLog && InterlockedIncrement(&g_cbLogCount) <= CB_LOG_LIMIT) {
        fprintf(g_traceLog, "[CB] NoOp called (return addr: %p)\n",
            __builtin_return_address(0)); fflush(g_traceLog); }
}
static void   __cdecl Stub_NoOpBuf(int* p) {
    if (g_traceLog && InterlockedIncrement(&g_cbLogCount) <= CB_LOG_LIMIT) {
        fprintf(g_traceLog, "[CB] NoOpBuf called, p=%p (return addr: %p)\n",
            (void*)p, __builtin_return_address(0)); fflush(g_traceLog); }
}
static void   __cdecl Stub_StringCopy(const char* fmt, ...) {
    if (g_traceLog && InterlockedIncrement(&g_cbLogCount) <= CB_LOG_LIMIT) {
        fprintf(g_traceLog, "[CB] StringCopy called, fmt='%s' (return addr: %p)\n",
            fmt ? fmt : "(null)", __builtin_return_address(0)); fflush(g_traceLog); }
}
static void   __cdecl Stub_NoOp2(uint32_t a, uint32_t b) {
    if (g_traceLog && InterlockedIncrement(&g_cbLogCount) <= CB_LOG_LIMIT) {
        fprintf(g_traceLog, "[CB] NoOp2(%u,%u) (return addr: %p)\n",
            a, b, __builtin_return_address(0)); fflush(g_traceLog); }
}
static char*  __cdecl Stub_ReturnEmptyStr() {
    if (g_traceLog && InterlockedIncrement(&g_cbLogCount) <= CB_LOG_LIMIT) {
        fprintf(g_traceLog, "[CB] ReturnEmptyStr called (return addr: %p)\n",
            __builtin_return_address(0)); fflush(g_traceLog); }
    return (char*)"";
}
static int    __cdecl Stub_Return0() { return 0; }

void InitUpCallTable(uint32_t* outParams)
{
    // Static callback table (22 entries)
    static void* s_callbackTable[22] = {};

    // Only initialize once
    static bool s_initialized = false;
    if (!s_initialized)
    {
        s_initialized = true;

        // Default: return nullptr (safe for pointer-returning callbacks)
        for (int i = 0; i < 22; i++)
            s_callbackTable[i] = (void*)&Stub_ReturnNull;

        // idx 0: StringCopyHelper (variadic) — void return
        s_callbackTable[0] = (void*)&Stub_StringCopy;
        // idx 1: CleanupHandler — void
        s_callbackTable[1] = (void*)&Stub_NoOp;
        // idx 2: DebugLogString(char*) — void
        s_callbackTable[2] = (void*)&Stub_NoOp;
        // idx 3: ShowErrorDialog — void
        s_callbackTable[3] = (void*)&Stub_NoOp;
        // idx 4: ErrorStringAccessor — returns char*
        s_callbackTable[4] = (void*)&Stub_ReturnEmptyStr;
        // idx 5: SecurityCheck — void
        s_callbackTable[5] = (void*)&Stub_NoOp;
        // idx 6: PostFrameCallback — void
        s_callbackTable[6] = (void*)&Stub_NoOp;
        // idx 7: SceneBegin — void
        s_callbackTable[7] = (void*)&Stub_NoOp;
        // idx 8: SceneEnd — void
        s_callbackTable[8] = (void*)&Stub_NoOp;
        // idx 9: PreRenderCheck — void
        s_callbackTable[9] = (void*)&Stub_NoOp;
        // idx 10: BufferDeallocator(int*) — void
        s_callbackTable[10] = (void*)&Stub_NoOpBuf;
        // idx 11: GetLocalizedString — returns const char*
        s_callbackTable[11] = (void*)&Stub_ReturnEmptyStr;
        // idx 12: TextureLoader — void
        s_callbackTable[12] = (void*)&Stub_NoOp;
        // idx 13: SinCosLookup — void
        s_callbackTable[13] = (void*)&Stub_NoOp;
        // idx 14: TimeAccessor — void
        s_callbackTable[14] = (void*)&Stub_NoOp;
        // idx 15: VFSOpenFileVariant — returns HANDLE (void*)
        s_callbackTable[15] = (void*)&Stub_ReturnNull;
        // idx 16: VFSOpenMusicFile — returns HANDLE (void*)
        s_callbackTable[16] = (void*)&Stub_ReturnNull;
        // idx 17: VFSOpenFile(char*) — returns HANDLE (void*)
        s_callbackTable[17] = (void*)&Stub_ReturnNull;
        // idx 18: SelfReference — returns void* (pointer to engine)
        s_callbackTable[18] = (void*)&Stub_ReturnNull;
        // idx 19: CRT_free(void*) — MUST use real free()
        s_callbackTable[19] = (void*)&free;
        // idx 20: ShowErrorDialog2(uint32_t, uint32_t) — void
        s_callbackTable[20] = (void*)&Stub_NoOp2;
        // idx 21: ScenePipelineEntry — void
        s_callbackTable[21] = (void*)&Stub_NoOp;

        if (g_traceLog) {
            fprintf(g_traceLog, "[TRACE] Callback table initialized with safe stubs\n");
            fflush(g_traceLog);
        }
    }

    outParams[0] = 0x2775;               // Engine version magic
    outParams[1] = 0x16;                 // 22 callbacks
    outParams[2] = (uint32_t)s_callbackTable;  // Table pointer
}

} // namespace Giants

// ═══════════════════════════════════════════════════════════════════
// Upcall table callback implementations
// ═══════════════════════════════════════════════════════════════════

namespace Giants {

// ─── VFSOpenFile (FUN_00621e50) ─────────────────────────────────
// Ghidra: FUN_00621e50 (1 caller, 8 callees)
// Purpose: Open a file through the Virtual File System. Initializes VFS
//          on first call, resolves the file path via VFS lookup, then opens
//          with CreateFileA (GENERIC_READ, FILE_SHARE_READ, OPEN_EXISTING).
//          Cleans up the temporary path string on return.
// Original:
// HANDLE FUN_00621e50(char *param_1)
// {
//   char cVar1;
//   int iVar2;
//   LPCSTR ***ppppCVar3;
//   HANDLE pvVar4;
//   uint uVar5;
//   int local_44;
//   uint local_30;
//   LPCSTR **local_2c;
//   LPCSTR *ppCStack_28;
//   LPCSTR *ppCStack_24;
//   LPCSTR *ppCStack_20;
//   undefined8 local_1c;
//   uint local_14;
//   void *local_10;
//   undefined1 *puStack_c;
//   undefined4 local_8;
//   puStack_c = &LAB_0064620d;
//   local_10 = ExceptionList;
//   local_14 = DAT_0067d280 ^ (uint)&stack0xfffffffc;
//   ExceptionList = &local_10;
//   ppCStack_28 = (LPCSTR *)0x0;
//   ppCStack_24 = (LPCSTR *)0x0;
//   ppCStack_20 = (LPCSTR *)0x0;
//   local_1c = 0xf00000000;
//   local_2c = (LPCSTR **)0x0;
//   local_8 = 0;
//   FUN_00622930(local_14);
//   cVar1 = *param_1;
//   while (cVar1 != '\0') {
//     param_1 = param_1 + 1;
//     cVar1 = *param_1;
//   }
//   iVar2 = FUN_00623f00();
//   if (iVar2 != 0) {
//     ppppCVar3 = (LPCSTR ***)FUN_00623dc0();
//     if (&local_2c != ppppCVar3) {
//       FUN_004439b0();
//       local_2c = *ppppCVar3;
//       ppCStack_28 = (LPCSTR *)ppppCVar3[1];
//       ppCStack_24 = (LPCSTR *)ppppCVar3[2];
//       ppCStack_20 = (LPCSTR *)ppppCVar3[3];
//       local_1c = *(undefined8 *)(ppppCVar3 + 4);
//       ppppCVar3[4] = (LPCSTR **)0x0;
//       ppppCVar3[5] = (LPCSTR **)0xf;
//       *(undefined1 *)ppppCVar3 = 0;
//     }
//     if (0xf < local_30) {
//       uVar5 = local_30 + 1;
//       iVar2 = local_44;
//       if (0xfff < uVar5) {
//         iVar2 = *(int *)(local_44 + -4);
//         uVar5 = local_30 + 0x24;
//         if (0x1f < (local_44 - iVar2) - 4U) {
//           _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
//         }
//       }
//       FUN_00643505(iVar2,uVar5);
//     }
//     ppppCVar3 = &local_2c;
//     if (0xf < local_1c._4_4_) {
//       ppppCVar3 = (LPCSTR ***)local_2c;
//     }
//     pvVar4 = CreateFileA((LPCSTR)ppppCVar3,0x80000000,1,(LPSECURITY_ATTRIBUTES)0x0,3,0x8000080,
//                          (HANDLE)0x0);
//     if (pvVar4 != (HANDLE)0xffffffff) goto LAB_00621f79;
//   }
//   pvVar4 = (HANDLE)0x0;
// LAB_00621f79:
//   if (0xf < local_1c._4_4_) {
//     uVar5 = local_1c._4_4_ + 1;
//     ppppCVar3 = (LPCSTR ***)local_2c;
//     if (0xfff < uVar5) {
//       ppppCVar3 = (LPCSTR ***)local_2c[-1];
//       uVar5 = local_1c._4_4_ + 0x24;
//       if ((LPCSTR)0x1f < (LPCSTR)((int)local_2c + (-4 - (int)ppppCVar3))) {
//         _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
//       }
//     }
//     FUN_00643505(ppppCVar3,uVar5);
//   }
//   ExceptionList = local_10;
//   return pvVar4;
// }
HANDLE VFSOpenFile(char* filePath)
{
    // Initialize VFS on first call
    // VFS_Initialize(cookie);

    // Skip to end of path string (compute length)
    // char* end = filePath;
    // while (*end) end++;

    // Resolve file through VFS
    // if (!FUN_00623f00()) return nullptr;

    // Get resolved path string via FUN_00623dc0()
    // This returns a std::string that we move into a local SSO string
    // LPCSTR*** resolvedPath = FUN_00623dc0();
    // Move string data: local_2c = resolved path SSO string

    // Open with CreateFileA
    // HANDLE hFile = CreateFileA(
    //     resolvedPathCString,
    //     GENERIC_READ,           // 0x80000000
    //     FILE_SHARE_READ,        // 1
    //     nullptr,                // no security
    //     OPEN_EXISTING,          // 3
    //     FILE_ATTRIBUTE_NORMAL | FILE_FLAG_RANDOM_ACCESS,  // 0x8000080
    //     nullptr);               // no template

    // Cleanup SSO string if heap-allocated (capacity > 15)
    // if (stringCapacity > 15) FUN_00643505(heapPtr, size);

    // return (hFile != INVALID_HANDLE_VALUE) ? hFile : nullptr;
    return nullptr;
}

// ─── VFSOpenMusicFile (FUN_00621fe0) ────────────────────────────
// Ghidra: FUN_00621fe0 (1 caller, 8 callees)
// Purpose: Open a music/sound file with search path fallback. Iterates
//          up to 4 search paths (indices 0-3), consulting the global
//          music search path table and flags. For each path, builds a
//          full file path, attempts CreateFileA. On success, remembers
//          which search path worked for future calls.
// Original:
// HANDLE FUN_00621fe0(int param_1)
// { ... (see Ghidra output — ~180 lines of search path iteration) }
HANDLE VFSOpenMusicFile(int fileId)
{
    // VFS_Initialize(cookie);

    // int lastPathIndex = 0;  // DAT_0074bc14
    // for (int attempt = 0; attempt <= 3; attempt++) {
    //     int pathIndex = (attempt == 0) ? s_lastSuccessfulPath : attempt;
    //     if (pathIndex == 0) {
    //         // Use empty path — current directory
    //     } else {
    //         switch (pathIndex) {
    //         case 1: searchPrefix = &DAT_0065d0b3; break;
    //         case 2: searchPrefix = s_MusicPath2; break;
    //         default: searchPrefix = s_MusicPath3; break;
    //         }
    //         if (*searchPrefix != '\0') {
    //             BuildSearchPath(searchPrefix);  // FUN_0057ce00
    //         } else {
    //             // Use music base path
    //         }
    //     }
    //
    //     if (searchPathValid) {
    //         // Build full path via FUN_00625490
    //         // Attempt CreateFileA
    //         HANDLE hFile = CreateFileA(fullPath, GENERIC_READ, FILE_SHARE_READ,
    //             nullptr, OPEN_EXISTING, 0x8000080, nullptr);
    //         if (hFile != INVALID_HANDLE_VALUE) {
    //             s_lastSuccessfulPath = pathIndex;  // DAT_0074bc14
    //             // Cleanup temp strings
    //             return hFile;
    //         }
    //     }
    // }
    // // Cleanup temp strings
    // return nullptr;
    return nullptr;
}

// ─── VFSOpenFileVariant (FUN_006222d0) ──────────────────────────
// Ghidra: FUN_006222d0 (1 caller, 8 callees)
// Purpose: Open a file through the VFS using alternate resolution functions.
//          Same pattern as VFSOpenFile but uses FUN_00624a10/FUN_006242d0
//          for path resolution instead of FUN_00623f00/FUN_00623dc0.
// Original:
// HANDLE FUN_006222d0(void)
// {
//   int iVar1;
//   LPCSTR ***ppppCVar2;
//   HANDLE pvVar3;
//   uint uVar4;
//   LPCSTR **local_2c;
//   LPCSTR *ppCStack_28;
//   LPCSTR *ppCStack_24;
//   LPCSTR *ppCStack_20;
//   undefined8 local_1c;
//   uint local_14;
//   void *local_10;
//   undefined1 *puStack_c;
//   undefined4 local_8;
//   puStack_c = &LAB_0064618d;
//   local_10 = ExceptionList;
//   local_14 = DAT_0067d280 ^ (uint)&stack0xfffffffc;
//   ExceptionList = &local_10;
//   ppCStack_28 = (LPCSTR *)0x0;
//   ppCStack_24 = (LPCSTR *)0x0;
//   ppCStack_20 = (LPCSTR *)0x0;
//   local_1c = 0xf00000000;
//   local_2c = (LPCSTR **)0x0;
//   local_8 = 0;
//   FUN_00622930(local_14);
//   iVar1 = FUN_00624a10();
//   if (iVar1 != 0) {
//     ppppCVar2 = (LPCSTR ***)FUN_006242d0();
//     if (&local_2c != ppppCVar2) {
//       FUN_004439b0();
//       local_2c = *ppppCVar2;
//       ppCStack_28 = (LPCSTR *)ppppCVar2[1];
//       ppCStack_24 = (LPCSTR *)ppppCVar2[2];
//       ppCStack_20 = (LPCSTR *)ppppCVar2[3];
//       local_1c = *(undefined8 *)(ppppCVar2 + 4);
//       ppppCVar2[4] = (LPCSTR **)0x0;
//       ppppCVar2[5] = (LPCSTR **)0xf;
//       *(undefined1 *)ppppCVar2 = 0;
//     }
//     FUN_004439b0();
//     ppppCVar2 = &local_2c;
//     if (0xf < local_1c._4_4_) {
//       ppppCVar2 = (LPCSTR ***)local_2c;
//     }
//     pvVar3 = CreateFileA((LPCSTR)ppppCVar2,0x80000000,1,(LPSECURITY_ATTRIBUTES)0x0,3,0x8000080,
//                          (HANDLE)0x0);
//     if (pvVar3 != (HANDLE)0xffffffff) goto LAB_0062239d;
//   }
//   pvVar3 = (HANDLE)0x0;
// LAB_0062239d:
//   if (0xf < local_1c._4_4_) {
//     uVar4 = local_1c._4_4_ + 1;
//     ppppCVar2 = (LPCSTR ***)local_2c;
//     if (0xfff < uVar4) {
//       ppppCVar2 = (LPCSTR ***)local_2c[-1];
//       uVar4 = local_1c._4_4_ + 0x24;
//       if ((LPCSTR)0x1f < (LPCSTR)((int)local_2c + (-4 - (int)ppppCVar2))) {
//         _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
//       }
//     }
//     FUN_00643505(ppppCVar2,uVar4);
//   }
//   ExceptionList = local_10;
//   return pvVar3;
// }
HANDLE VFSOpenFileVariant()
{
    // VFS_Initialize(cookie);

    // Resolve file via alternate VFS path functions
    // if (!FUN_00624a10()) return nullptr;
    // LPCSTR*** resolvedPath = FUN_006242d0();
    // Move resolved path string into local SSO string

    // Open with CreateFileA
    // HANDLE hFile = CreateFileA(
    //     resolvedPathCString,
    //     GENERIC_READ, FILE_SHARE_READ,
    //     nullptr, OPEN_EXISTING, 0x8000080, nullptr);

    // Cleanup SSO string if heap-allocated
    // return (hFile != INVALID_HANDLE_VALUE) ? hFile : nullptr;
    return nullptr;
}

// ─── BufferDeallocator (FUN_005e99a0) ──────────────────────────
// Ghidra: FUN_005e99a0 (1 caller, 1 callee)
// Purpose: Release a renderer buffer. The buffer descriptor has:
//   +0x04 (bytes): data pointer
//   +0x20 (bytes): ownership flags (bit 0 = buffer owns the memory)
// Original:
// void FUN_005e99a0(int param_1)
// {
//   if ((*(void **)(param_1 + 4) != (void *)0x0) && ((~*(uint *)(param_1 + 0x20) & 1) == 0)) {
//     free(*(void **)(param_1 + 4));
//     *(undefined4 *)(param_1 + 4) = 0;
//     *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xfffffffe;
//   }
//   return;
// }
void BufferDeallocator(int* bufferDesc)
{
    // Buffer descriptor layout (byte offsets):
    //   +0x04: data pointer
    //   +0x20: flags — bit 0 set = buffer owns memory
    uint8_t* bytes = reinterpret_cast<uint8_t*>(bufferDesc);
    void** dataPtr = reinterpret_cast<void**>(bytes + 4);
    uint32_t* flags = reinterpret_cast<uint32_t*>(bytes + 0x20);

    if (*dataPtr != nullptr && (~(*flags) & 1) == 0) {
        free(*dataPtr);
        *dataPtr = nullptr;
        *flags &= ~1u;  // Clear ownership bit
    }
}

// ─── DebugLogString (FUN_004bf140) ─────────────────────────────
// Ghidra: FUN_004bf140 (1 caller, 1 callee)
// Purpose: Output a debug/log string if the global debug flag is enabled.
//          Computes string length by scanning for null terminator, calls
//          the debug output function, and increments the message counter.
// Original:
// void FUN_004bf140(char *param_1)
// {
//   char cVar1;
//   char *pcVar2;
//   if (DAT_007283a4 != '\0') {
//     pcVar2 = param_1;
//     do {
//       cVar1 = *pcVar2;
//       pcVar2 = pcVar2 + 1;
//     } while (cVar1 != '\0');
//     FUN_00461f00(param_1,(int)pcVar2 - (int)(param_1 + 1));
//     DAT_00747b40 = DAT_00747b40 + 1;
//   }
//   return;
// }
void DebugLogString(char* message)
{
    // if (!s_debugLogEnabled) return;  // DAT_007283a4

    // Compute string length
    // char* end = message;
    // while (*end) end++;
    // int length = (int)(end - message) - 1;  // exclude null terminator

    // Output via debug channel
    // FUN_00461f00(message, length);

    // Increment debug message counter
    // s_debugMessageCount++;  // DAT_00747b40
}

// ─── ShowErrorDialog (FUN_0062f610) ────────────────────────────
// Ghidra: FUN_0062f610 (1 caller, 5 callees)
// Purpose: Display a "Giants Error" dialog box. Formats a variadic
//          message into a 4095-byte stack buffer, temporarily hides
//          the game window, shows MessageBoxA with MB_ABORTRETRYIGNORE,
//          and sets the global abort flag if user picks Abort or Cancel.
// Original:
// void __thiscall FUN_0062f610(undefined4 param_1,undefined4 param_2)
// {
//   int iVar1;
//   CHAR local_1004 [4095];
//   undefined1 local_5;
//   uint local_4;
//   local_4 = DAT_0067d280 ^ (uint)local_1004;
//   FUN_00462fc0(param_2,param_1,&stack0x00000008);
//   local_5 = 0;
//   SetWindowPos(DAT_007281d8,(HWND)0xfffffffe,0,0,0,0,3);
//   iVar1 = MessageBoxA((HWND)0x0,local_1004,"Giants Error",1);
//   SetWindowPos(DAT_007281d8,(HWND)0x0,0,0,0,0,3);
//   if ((iVar1 == 2) || (iVar1 == 3)) {
//     DAT_007281e4 = 1;
//   }
//   return;
// }
void ShowErrorDialog(uint32_t param_1, uint32_t param_2)
{
    // Format error message into stack buffer
    // char buffer[4095];
    // FUN_00462fc0(param_2, param_1, &va_args);  // vsprintf-like formatting

    // Hide game window behind dialog
    // HWND gameWnd = s_hMainWindow;  // DAT_007281d8
    // SetWindowPos(gameWnd, HWND_TOPMOST, 0, 0, 0, 0,
    //     SWP_NOMOVE | SWP_NOSIZE);  // flags = 3

    // Show modal error dialog
    // int result = MessageBoxA(nullptr, buffer, "Giants Error",
    //     MB_ABORTRETRYIGNORE);  // type = 1

    // Restore game window
    // SetWindowPos(gameWnd, nullptr, 0, 0, 0, 0,
    //     SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER);

    // Set abort flag if user chose Abort (3) or Cancel (2)
    // if (result == IDABORT || result == IDCANCEL) {
    //     s_abortFlag = 1;  // DAT_007281e4
    // }
}

// ─── StringCopyHelper (FUN_006299e0) ───────────────────────────
// Ghidra: FUN_006299e0 (28 callers, 4 callees)
// Purpose: Variadic error/status string logger. Formats a printf-style
//          message into a 256-byte stack buffer using wvsprintfA, appends
//          "\r\n", and copies the result to the global status string at
//          DAT_007280d0. Called from 28 locations across the engine.
// Original:
// void FUN_006299e0(LPCSTR param_1)
// {
//   CHAR local_104 [256];
//   uint local_4;
//   local_4 = DAT_0067d280 ^ (uint)local_104;
//   local_104[0] = '\0';
//   wvsprintfA(local_104,param_1,&stack0x00000008);
//   lstrcatA(local_104,"\r\n");
//   lstrcpyA(&DAT_007280d0,local_104);
//   return;
// }
void StringCopyHelper(const char* format, ...)
{
    // char buffer[256];
    // buffer[0] = '\0';

    // Format the variadic arguments
    // va_list args;
    // va_start(args, format);
    // wvsprintfA(buffer, format, args);
    // va_end(args);

    // Append CRLF
    // lstrcatA(buffer, "\r\n");

    // Copy to global status string
    // lstrcpyA(s_statusString, buffer);  // DAT_007280d0
}

} // namespace Giants

// ═══════════════════════════════════════════════════════════════════
// LoadRendererDLL — FUN_0062a190 (STUB)
// ═══════════════════════════════════════════════════════════════════
// Loads the renderer DLL specified in the registry.
// Returns the HMODULE of the loaded DLL, or nullptr on failure.
// In the original binary, this reads the renderer name from registry
// and calls LoadLibraryA.

namespace Giants {

HMODULE LoadRendererDLL()
{
    // Use the renderer name resolved by InitializeEngine (from registry or default)
    extern char g_rendererName[32];  // DAT_007281f0
    if (g_rendererName[0] == '\0') return nullptr;

    HMODULE hModule = LoadLibraryA(g_rendererName);
    return hModule;
}

} // namespace Giants

// ═══════════════════════════════════════════════════════════════════
// LoadModuleHelper — FUN_0062a190 (STUB)
// ═══════════════════════════════════════════════════════════════════
// Helper to load a DLL module. Used by EngineInit to load the renderer.

namespace Giants {

HMODULE LoadModuleHelper()
{
    // RE stub — delegates to LoadRendererDLL for now
    return LoadRendererDLL();
}

} // namespace Giants
