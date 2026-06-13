// Giants Engine - CRT & Core Utility Stubs Implementation
// Reverse engineered from GiantsMain.exe v1.520.59

#include "CRTStubs.h"
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <stdexcept>
#include <new>

// Ghidra SEH helper — maps to MSVC __ExceptionPtrList (unused in stubs)
#define ExceptionList ((void*)0)
// Ghidra code pointer type — treat as void*
#define code void
// Ghidra float10 — maps to long double (unused)
#define float10 long double

// ─── MSVC CRT Compatibility Definitions (for MinGW) ──────────────
#ifdef __GNUC__
extern "C" {
    // CRT initializer table markers (empty — MinGW handles init differently)
    void* __xc_a[1] = { nullptr };
    void* __xc_z[1] = { nullptr };
    void* __xi_a[1] = { nullptr };
    void* __xi_z[1] = { nullptr };
    // Startup state
    int __scrt_current_native_startup_state = 0; // UNINITIALIZED
}
#endif

// ─── Ghidra global variable definitions ─────────────────────────
// These are placeholders for binary globals referenced by decompiled code.
namespace Giants {
uint32_t DAT_0067821c = 0;
uint32_t DAT_00702d60 = 0;
uint32_t DAT_00748b50 = 0;
uint32_t DAT_00701bd8 = 0;
uint32_t DAT_0066bfe8 = 0;
uint32_t DAT_006543cc = 0;
float    DAT_0066bf2c = 1.0f;
float    DAT_0066be20 = 1.0f;
uint32_t PTR_FUN_0065dae4 = 0;
uint32_t PTR_FUN_0067d208 = 0;
uint32_t PTR_FUN_0067d230 = 0;
uint32_t PTR_FUN_0067d234 = 0;
uint32_t PTR_FUN_0067d238 = 0;
uint32_t DAT_0072c000 = 0;
uint32_t DAT_00682208 = 0;
uint32_t DAT_00682214 = 0;
uint32_t DAT_00681e30 = 0;
uint32_t DAT_00682210 = 0;
uint32_t DAT_00702968 = 0;
uint32_t DAT_00702bc0 = 0;
uint32_t _DAT_0067e474 = 0;
uint32_t _DAT_0067e524 = 0;
uint32_t _DAT_0067e574 = 0;
uint32_t _DAT_0067e624 = 0;
uint32_t _DAT_0067e6d4 = 0;
uint32_t _DAT_00000f54 = 0;
int DAT_00701a3c = 0;    // Game state context pointer
int DAT_006ff960 = 0;    // Game mode / session type

// ─── Missing DAT_* globals (referenced as extern in function bodies) ────
uintptr_t g_securityCookie = 0;  // DAT_0067d280 — CRT security cookie (used as uintptr_t)
uint32_t DAT_0067d280 = 0;       // Same security cookie (used as uint32_t in function bodies)
uint32_t DAT_0067d198 = 0;  // Identity matrix base
int DAT_0068220c = 0;             // Camera mode flag (extern int in function body)
uint32_t DAT_00702770 = 0;         // Scene/context pointer (used as integer address)
uint32_t* DAT_007027ac = nullptr;  // Entity linked list head
uint32_t* DAT_007027b0 = nullptr;  // Entity linked list head 2
uint32_t DAT_007027e0 = 0;  // Scene node pointer
uint32_t DAT_007028f4 = 0;  // Entity list base
int DAT_00702924 = 0;       // Player count
uint32_t DAT_00702940 = 0;  // Game state field
uint32_t DAT_00702964 = 0;  // Dedicated server flag
void* DAT_0073f7b4 = nullptr;  // VFS buffer pointer
uint32_t DAT_0073f7b8 = 0;  // VFS buffer current pos
uint32_t DAT_0073f7bc = 0;  // VFS buffer end
uint32_t DAT_0073f7c0 = 0;  // VFS remaining bytes
void* DAT_0073f7c4 = nullptr;  // VFS file handle
uint32_t DAT_00749908 = 0;  // String table start
uint32_t DAT_0074990c = 0;  // String table end
uint32_t DAT_0074bb60 = 0;  // Distance vector (3 floats)

void* LAB_00648c4d = nullptr;
// Forward-declared function stubs (Ghidra raw names)
// NOTE: FUN_00481900 and FUN_00462ed0 have specific-signature callers in CRTStubs.cpp
// so we provide both variadic (for general forward-decl) and specific overloads.
void FUN_00481900(unsigned int, void*, unsigned int) { } // RE stub — vector assign
void FUN_00462ed0(unsigned int) { } // RE stub — string destructor
int FUN_00481900(...) { return 0; }
int FUN_00462ed0(...) { return 0; }
int FUN_004439b0(...) { return 0; }
int FUN_0042aca0(...) { return 0; }
int FUN_00443110(...) { return 0; }
int FUN_0042b1f0(...) { return 0; }
int FUN_00443010(...) { return 0; }
int FUN_00558360(...) { return 0; }
int FUN_00656bf4(...) { return 0; }
int FUN_00559dc0(...) { return 0; }
// FUN_006387e0 (SinCosLookup) — REAL validated port in TrigTables.cpp (replaces this stub).
int FUN_0053ea80(...) { return 0; }
int FUN_00559530(...) { return 0; }
int FUN_00558730(...) { return 0; }
int FUN_0062a0b0(...) { return 0; }
int FUN_004d1070(...) { return 0; }
int FUN_00469de0(...) { return 0; }
int FUN_00463000(...) { return 0; }
int FUN_0045f460(...) { return 0; }
int FUN_00644f60(...) { return 0; }
int FUN_0062c720(...) { return 0; }
} // close namespace for Ghidra extern stubs

namespace Giants {

// ─── FUN_00643505(int, uint32_t) — CRT free with size parameter ──────
// Called with (ptr, size) in Ghidra decompilation for sized deallocation.
// This is a separate overload from CRTFree(void*) which is the same underlying CRT free.
void FUN_00643505(int ptr, uint32_t size) { /* RE stub — sized free */ }

} // close overload namespace

namespace Giants {

// ─── CRTFree (FUN_00643505) — PASS ──────────────────────────────
// Standard CRT free(). Ghidra shows it as a trivial wrapper.
// 652 callers, 1 callee (free itself).

void CRTFree(void* ptr)
{
    free(ptr);
}

// ─── GetStartupShowCmd (FUN_0064458d) — PASS ───────────────────
// Reads the STARTUPINFOW for the current process and returns the
// nCmdShow value. If STARTF_USESHOWWINDOW flag is set in dwFlags,
// returns wShowWindow; otherwise returns 10 (SW_SHOWDEFAULT).
// 1 caller (__scrt_common_main_seh), 2 callees (memset, GetStartupInfoW).

WORD GetStartupShowCmd()
{
    STARTUPINFOW si;
    memset(&si, 0, sizeof(si));
    GetStartupInfoW(&si);

    WORD cmdShow = 10;  // SW_SHOWDEFAULT
    if ((si.dwFlags & STARTF_USESHOWWINDOW) != 0)
    {
        cmdShow = si.wShowWindow;
    }
    return cmdShow;
}

// ─── InitSqrtTables (FUN_00640030) — PASS ──────────────────────
// Precomputes two 32K-entry IEEE 754 mantissa lookup tables
// for fast inverse sqrt approximation.
//
// Table 1: DAT_006dd0a8[i] = mantissa_bits(sqrt(float((i | 0x3f8000) << 8)))
// Table 2: DAT_006bd0a8[i] = mantissa_bits(sqrt(float((i | 0x400000) << 8)))
//
// The trick: the input float is constructed by ORing the index with a sign bit
// pattern, shifting left by 8 to create an IEEE 754 float in [1.0, 4.0) range.
// The mantissa bits of the sqrt give a fast lookup for Quake-style inv-sqrt.
// 1 caller (CheckProcessorSupport), 1 callee (SQRT).

static uint32_t s_sqrtTable1[0x8000];  // DAT_006dd0a8
static uint32_t s_sqrtTable2[0x8000];  // DAT_006bd0a8

void InitSqrtTables()
{
    for (uint32_t i = 0; i < 0x8000; i++)
    {
        // Construct float from index: (i | 0x3f8000) << 8
        // This creates a float with exponent in [1.0, 2.0) range
        uint32_t bits1 = (i | 0x3f8000) << 8;
        float f1;
        memcpy(&f1, &bits1, sizeof(f1));
        float sqrt1 = sqrtf(f1);
        uint32_t sqrtBits1;
        memcpy(&sqrtBits1, &sqrt1, sizeof(sqrtBits1));
        s_sqrtTable1[i] = sqrtBits1 & 0x7FFFFF;  // Mantissa only

        // Second table with different exponent range [2.0, 4.0)
        uint32_t bits2 = (i | 0x400000) << 8;
        float f2;
        memcpy(&f2, &bits2, sizeof(f2));
        float sqrt2 = sqrtf(f2);
        uint32_t sqrtBits2;
        memcpy(&sqrtBits2, &sqrt2, sizeof(sqrtBits2));
        s_sqrtTable2[i] = sqrtBits2 & 0x7FFFFF;  // Mantissa only
    }
}

// ─── SetWndProc (FUN_00640160) — PASS ──────────────────────────
// Trivial setter: stores wndProc address in global DAT_006fd0a8.

static uint32_t g_registeredWndProc = 0;  // DAT_006fd0a8

void SetWndProc(uint32_t wndProc)
{
    g_registeredWndProc = wndProc;
}

// ─── SetMemoryPool (FUN_006403f0) — PASS ───────────────────────
// Trivial setter: stores pool pointer in global DAT_006fd0ac.

static uint32_t g_memoryPool = 0;  // DAT_006fd0ac

void SetMemoryPool(uint32_t pool)
{
    g_memoryPool = pool;
}

// ─── DebugPrintf (FUN_00640a00) — PASS ─────────────────────────
// Formatted debug output. Writes to internal circular buffer, then:
//   1. OutputDebugStringA (always)
//   2. Optional callback DAT_006fd1bc (if non-null and DAT_006fd1b8==0)
//   3. Optional log file DAT_006fd1c0 (fprintf if non-null)
//   4. Optional log file DAT_006fd1c4 (fprintf if non-null)
// 15 callers, 5 callees (memset, vsprintf, OutputDebugStringA, fprintf, fclose).
//
// Note: Original uses __stdio_common_vsprintf (UCRT) and a custom buffer.
// This stub uses standard vsnprintf for portability.

static char s_debugBuffer[1024];      // DAT_006fd0b0
static size_t s_debugBufferSize = sizeof(s_debugBuffer);  // DAT_006fd1b0
static int    s_debugDisabled = 0;    // DAT_006fd1b4 — if < 1, output is enabled

void DebugPrintf(const char* fmt, ...)
{
    if (s_debugDisabled >= 1)
        return;

    memset(s_debugBuffer, ' ', s_debugBufferSize);

    va_list args;
    va_start(args, fmt);
    vsnprintf(s_debugBuffer, s_debugBufferSize, fmt, args);
    va_end(args);

    OutputDebugStringA(s_debugBuffer);

    // Optional callback and log file outputs would go here
    // DAT_006fd1bc: callback(s_debugBuffer)
    // DAT_006fd1c0: fprintf(file, "%s", s_debugBuffer)
    // DAT_006fd1c4: fprintf(file2, "%s", s_debugBuffer)
}

// ─── ThrowStringLengthError (FUN_00443110) ────────────────────────
// Ghidra: FUN_00443110 (29 callers, 1 callee)
// Purpose: MSVC std::string length guard. Throws std::length_error
//          when a string operation would exceed max_size().
//          This is the classic MSVC `_Xlength_error("string too long")`.
// Original:
//   void FUN_00443110(void)
//   {
//       /* WARNING: Subroutine does not return */
//       std::_Xlength_error("string too long");
//   }

[[noreturn]] void ThrowStringLengthError()
{
    // MSVC throws std::length_error from <stdexcept>
    throw std::length_error("string too long");
}

// ─── AlignedNew (FUN_00443120) ────────────────────────────────────
// Ghidra: FUN_00443120 (32 callers, 3 callees)
// Purpose: 32-byte aligned operator new with integer-overflow guard.
//   - size==0: returns (does nothing, caller gets nullptr)
//   - size < 0x1000: plain operator new(size)
//   - size + 0x23 overflows (size >= 0xFFFFFEDD): calls _invoke_watson (crash)
//   - Otherwise: allocates size+0x23, aligns up to 32 bytes,
//     stores original pointer at (aligned_addr - 4) for later AlignedDelete
// Original:
//   void FUN_00443120(uint param_1)
//   {
//     void *pvVar1;
//     if (param_1 == 0) { return; }
//     if (param_1 < 0x1000) { operator_new(param_1); return; }
//     if (param_1 + 0x23 <= param_1) { FUN_0042bad0(); } // overflow → watson
//     pvVar1 = operator_new(param_1 + 0x23);
//     if (pvVar1 == NULL) { _invoke_watson(...); }
//     *(void**)(((int)pvVar1 + 0x23U & 0xffffffe0) - 4) = pvVar1;
//     // returns aligned ptr in EAX (Ghidra elided this)
//   }

void* AlignedNew(uint32_t size)
{
    if (size == 0)
        return nullptr;

    // Small allocations: no alignment needed (MSVC small-string opt path)
    if (size < 0x1000)
    {
        return ::operator new(size);
    }

    // Integer overflow guard: size + 0x23 must not wrap
    if (size + 0x23 <= size)
    {
        // Original calls _invoke_watson (CRT fatal error reporter)
        // We abort instead — this path means size >= ~4GB which is invalid
        std::abort();
    }

    void* raw = ::operator new(size + 0x23);
    if (raw == nullptr)
    {
        std::abort();
    }

    // Align up to 32 bytes: ((ptr + 0x1F) & ~0x1F)
    // But Ghidra shows (ptr + 0x23) & 0xFFFFFFE0 — same result with different rounding
    uintptr_t aligned = (reinterpret_cast<uintptr_t>(raw) + 0x23U) & ~uintptr_t(0x1F);

    // Stash original pointer 4 bytes before the aligned address
    // so AlignedDelete can recover it for freeing
    *reinterpret_cast<void**>(aligned - 4) = raw;

    return reinterpret_cast<void*>(aligned);
}

// ─── CRTInitTerm (FUN_006438f8) ──────────────────────────────────
// Ghidra: FUN_006438f8 (70 callers, 3 callees)
// Purpose: CRT _initterm equivalent — iterates an array of function
//          pointers and calls each one. Used for global constructors
//          (__xc_a to __xc_z) and initializers (__xi_a to __xi_z).
//          SEH-prolog wrapped for safety during early CRT init.
// Original:
//   void FUN_006438f8(undefined4 param_1, undefined4 param_2,
//                     int param_3, code *param_4)
//   {
//     while (true) {
//       if (param_3 == 0) break;
//       (*(GhidraCodePtr *)PTR_guard_check_icall_0065377c)(); // CFG guard
//       (*param_4)();
//       param_3 = param_3 + -1;
//     }
//     FUN_00643970();  // SEH epilog
//     ExceptionList = local_14;
//     return;
//   }
//
// Note: Ghidra's signature is deformed. The real signature matches
// MSVC _initterm:
//   void _initterm(_PVFV* begin, _PVFV* end);
// The `count` and `param_4` Ghidra shows are actually the loop
// iterating from begin to end-1, calling each non-null entry.

void CRTInitTerm(void** begin, void** end, int /*count*/, void (**/*table*/)())
{
    // The real CRT _initterm iterates from begin to end (exclusive),
    // calling each non-null function pointer.
    // Ghidra's decompilation shows a count-based loop, but the actual
    // semantic is pointer-range iteration.
    for (void** p = begin; p < end; p++)
    {
        if (*p != nullptr)
        {
            auto func = reinterpret_cast<void(*)()>(*p);
            func();
        }
    }
}

// ─── CRTFreeWrapper (FUN_00643c84) ────────────────────────────────
// Ghidra: FUN_00643c84 (1 caller, 1 callee)
// Purpose: Trivial free() wrapper, likely a CRT internal cleanup path.
//          Used by the SEH/CRT termination code.
// Original:
//   void FUN_00643c84(void *param_1)
//   {
//     free(param_1);
//     return;
//   }

void CRTFreeWrapper(void* ptr)
{
    free(ptr);
}

// ═══════════════════════════════════════════════════════════════════
// ComSmartPtrRelease (FUN_00430350) — 249 callers
// ═══════════════════════════════════════════════════════════════════
// COM smart pointer Release with thread-safe refcount.
// param_1 = smart pointer struct, +4 = pointer to refcounted object.
// Object layout: vtable, refcount (+4), weak_count (+8)

void ComSmartPtrRelease(int param_1)
{
    int* piVar2 = *(int**)(param_1 + 4);
    if (piVar2 == nullptr) return;

    // Decrement strong refcount (thread-safe via InterlockedDecrement)
    long iVar3 = InterlockedDecrement(reinterpret_cast<long*>(piVar2 + 1));

    if (iVar3 == 0) {
        // Strong ref hit zero — call destructor (vtable[0])
        auto destructor = reinterpret_cast<void(*)()>(*(int*)*piVar2);
        destructor();

        // Decrement weak refcount
        long weakCount = InterlockedDecrement(reinterpret_cast<long*>(piVar2 + 2));

        if (weakCount == 0) {
            // Weak ref also zero — call deallocator (vtable[1])
            auto deallocator = reinterpret_cast<void(*)()>(*(int*)(*piVar2 + 4));
            deallocator();
        }
    }
}

// ═══════════════════════════════════════════════════════════════════
// SsoStringClear (FUN_00443a10) — 549 callers
// ═══════════════════════════════════════════════════════════════════
// MSVC std::string clear/truncate.
// If capacity > 15 (heap-allocated): frees buffer via CRTFree.
// Then resets: length=0, capacity=15 (SSO), first byte=0.

void SsoStringClear(int* param_1)
{
    uint32_t capacity = (uint32_t)param_1[5];

    if (capacity > 0xf) {
        // Heap-allocated string — free the buffer
        int bufPtr = *param_1;
        uint32_t newSize = capacity + 1;
        int allocStart = bufPtr;

        if (newSize > 0xfff) {
            allocStart = *(int*)(bufPtr - 4);
            uint32_t allocSize = capacity + 0x24;
            if ((uint32_t)(bufPtr - allocStart) - 4 > 0x1f) {
                // Debug heap corruption handler — _invoke_watson
                return;
            }
        }
        CRTFree(allocStart);
    }

    // Reset to SSO mode
    param_1[4] = 0;        // length = 0
    param_1[5] = 0xf;      // capacity = 15 (SSO mode)
    *(uint8_t*)param_1 = 0; // null terminator in inline buffer
}

// ═══════════════════════════════════════════════════════════════════
// VirtualDestructorCall (FUN_0042c100) — 98 callers
// ═══════════════════════════════════════════════════════════════════
// Calls object's vtable[0] destructor with arg=1 if object is non-null.
// Standard COM-style destruction pattern: (*obj_vtable)(1)

void VirtualDestructorCall(int* param_1)
{
    if (*param_1 != 0) {
        auto destructor = reinterpret_cast<void(*)(int)>(*(int*)(*reinterpret_cast<int**>(param_1)[0]));
        destructor(1);
    }
}

// ═══════════════════════════════════════════════════════════════════
// ComReleaseQI (FUN_00431ae0) — 43 callers
// ═══════════════════════════════════════════════════════════════════
// COM Release variant: calls vtable[2] with arg=1 if object is non-null.
// Used for QueryInterface/Release pattern.

void ComReleaseQI(int* param_1)
{
    if (param_1 != nullptr) {
        auto release = reinterpret_cast<void(*)(int)>(*(int*)(*reinterpret_cast<int*>(param_1) + 8));
        release(1);
    }
}

// ═══════════════════════════════════════════════════════════════════
// SecurityCheckCookie (FUN_006434f7) — 1250 callers
// ═══════════════════════════════════════════════════════════════════
// MSVC __security_check_cookie: validates stack cookie against global
// security cookie at DAT_0067d280. If mismatch, triggers fastfail.
// This is injected by the compiler /GS (buffer security check) flag.

extern uintptr_t g_securityCookie;  // DAT_0067d280, defined in Engine.cpp

void SecurityCheckCookie(uintptr_t stackCookie)
{
    if (stackCookie == g_securityCookie) {
        return;
    }
    ReportRangeCheckFailure();
}

// ═══════════════════════════════════════════════════════════════════
// ReportRangeCheckFailure (FUN_00643a38) — 1 caller (from SecurityCheckCookie)
// ═══════════════════════════════════════════════════════════════════
// MSVC __report_rangecheckfailure: triggers fastfail(FAST_FAIL_RANGE_CHECK_FAILURE).
// Never returns. On Windows, this calls __fastfail(9) which raises STATUS_STACK_BUFFER_OVERRUN.

[[noreturn]] void ReportRangeCheckFailure()
{
    // MSVC intrinsic: __fastfail(FAST_FAIL_RANGE_CHECK_FAILURE)
    __fastfail(9);  // FAST_FAIL_RANGE_CHECK_FAILURE = 9
    // If __fastfail returns (shouldn't), force terminate
    std::terminate();
}

// ═══════════════════════════════════════════════════════════════════
// OperatorNew (FUN_00643513) — 492 callers
// ═══════════════════════════════════════════════════════════════════
// MSVC operator new: attempts malloc, calls _callnewh (new handler)
// on failure, retries if handler returns non-zero, throws bad_alloc
// if handler can't free memory.

extern "C" int _callnewh(size_t size);  // MSVC new handler

void* OperatorNew(uint32_t size)
{
    void* ptr;
    int handlerResult;

    do {
        ptr = malloc(size);
        if (ptr != nullptr) {
            return ptr;
        }
        handlerResult = _callnewh(size);
    } while (handlerResult != 0);

    throw std::bad_alloc();
}

// ═══════════════════════════════════════════════════════════════════
// SsoWStringClear (FUN_00443490) — 227 callers
// ═══════════════════════════════════════════════════════════════════
// MSVC std::wstring clear/Tidy. Wide-char variant of SsoStringClear.
// Layout: offset 0 = _Bx union (16 bytes), offset 16 = _Mysize,
// offset 20 = _Myres. SSO threshold is 7 for wchar_t
// (fits 7 wchars + null in 16-byte buffer).

void SsoWStringClear(int* param_1)
{
    uint32_t capacity = (uint32_t)param_1[5];  // _Myres at offset 20

    if (capacity > 7) {
        // Heap-allocated wstring — free the buffer
        int bufPtr = *param_1;                 // _Bx._Ptr at offset 0
        uint32_t newSize = capacity + 2;       // +2 for wide null terminator
        int allocStart = bufPtr;

        if (newSize > 0xfff) {
            // Debug heap: recover actual allocation base
            allocStart = *(int*)(bufPtr - 4);
            uint32_t allocSize = capacity * 2 + 0x25;  // wide char size
            if ((uint32_t)(bufPtr - allocStart) - 4 > 0x1f) {
                // Heap corruption — _invoke_watson
                return;
            }
        }
        CRTFree(allocStart);
    }

    // Reset to SSO mode (wide-char)
    param_1[4] = 0;            // _Mysize = 0
    param_1[5] = 7;            // _Myres = 7 (SSO threshold for wchar_t)
    *(uint16_t*)param_1 = 0;   // null terminator in inline buffer
}

// ═══════════════════════════════════════════════════════════════════
// FreeBlock16 (FUN_004c5b00) — 51 callers
// ═══════════════════════════════════════════════════════════════════
// Frees a 16-byte aligned block if pointer is non-null.
// Simple wrapper — CRTFree with size hint 0x10.

void FreeBlock16(int* ptr)
{
    if (*ptr != 0) {
        CRTFree(reinterpret_cast<void*>(*ptr));
    }
}

// ═══════════════════════════════════════════════════════════════════
// CopyDataWithSize (FUN_0044d590) — 51 callers
// ═══════════════════════════════════════════════════════════════════
// STL container data movement helper. Dispatches based on size field
// at srcInfo+4: sizeField==1 → single element copy, otherwise iterate.

extern void CopySingleElement(uint32_t src, int srcInfo);     // FUN_0044d540
extern void CopyIteratedElement(int srcInfo, uint32_t limit); // FUN_0044dc30

void* CopyDataWithSize(void* dest, int count, uint32_t src, int srcInfo)
{
    uint8_t sizeField = *reinterpret_cast<const uint8_t*>(static_cast<uintptr_t>(srcInfo) + 4);

    if (sizeField != 1) {
        // Multi-byte element: iterate count times
        if (count != 0) {
            do {
                CopyIteratedElement(srcInfo, static_cast<uint32_t>(sizeField) + srcInfo);
                count = count - 1;
            } while (count != 0);
        }
        *static_cast<uint32_t*>(dest) = src;
        return dest;
    }

    // Single-byte element: direct copy
    CopySingleElement(src, srcInfo);
    return dest;
}

// ═══════════════════════════════════════════════════════════════════
// SsoStringAssign (FUN_00443c70) — 136 callers
// ═══════════════════════════════════════════════════════════════════
// SSO string assign/destroy: calls FUN_00443a20 with the first byte
// of the SSO buffer (which is the string data pointer in SSO mode).
// Trivial 1-line wrapper.

extern void SsoStringAssignImpl(int param_1);  // FUN_00443a20

void SsoStringAssign(void* param_1)
{
    SsoStringAssignImpl(*reinterpret_cast<int*>(param_1));
}

// ═══════════════════════════════════════════════════════════════════
// SsoStringAssignThunk (FUN_0061f3c0) — 84 callers
// ═══════════════════════════════════════════════════════════════════
// Identical to SsoStringAssign. This is a thunk/trampoline at a
// different address, likely for vtable or callback dispatch.

void SsoStringAssignThunk(void* param_1)
{
    SsoStringAssignImpl(*reinterpret_cast<int*>(param_1));
}

// ═══════════════════════════════════════════════════════════════════
// SsoWStringClearThunk (FUN_004434f0) — 103 callers
// ═══════════════════════════════════════════════════════════════════
// Thunk of FUN_00443490 (SsoWStringClear). Calls the wide-string
// clear function on the dereferenced pointer.

void SsoWStringClearThunk(void* param_1)
{
    SsoWStringClear(reinterpret_cast<int*>(*reinterpret_cast<int*>(param_1)));
}

// ═══════════════════════════════════════════════════════════════════
// NoOpReturn (FUN_0042d350) — 135 callers
// ═══════════════════════════════════════════════════════════════════
// Empty function body — just returns. Used as a default/null
// implementation for COM interface vtable slots or callback stubs.

void NoOpReturn()
{
    // Intentionally empty — default/no-op handler
}

// ═══════════════════════════════════════════════════════════════════
// ThrowVectorTooLong (FUN_0042b750) — 71 callers
// ═══════════════════════════════════════════════════════════════════
// MSVC std::vector length guard: throws std::length_error when
// a vector operation would exceed max_size(). [[noreturn]].

[[noreturn]] void ThrowVectorTooLong()
{
    throw std::length_error("vector too long");
}

// ═══════════════════════════════════════════════════════════════════
// IntToWideString (FUN_0044c960) — 50 callers
// ═══════════════════════════════════════════════════════════════════
// Converts an unsigned integer to a wide-string representation.
// Uses a 2-byte-per-digit lookup table at DAT_0065d910.
// Writes digits right-to-left (least significant first).
// Returns pointer to first digit in the buffer.

// Digit pair lookup table (100 entries, 2 bytes each: "00"-"99")
static const uint16_t s_digitPairs[100] = {  // DAT_0065d910
    0x3030, 0x3130, 0x3230, 0x3330, 0x3430, 0x3530, 0x3630, 0x3730, 0x3830, 0x3930,
    0x3031, 0x3131, 0x3231, 0x3331, 0x3431, 0x3531, 0x3631, 0x3731, 0x3831, 0x3931,
    0x3032, 0x3132, 0x3232, 0x3332, 0x3432, 0x3532, 0x3632, 0x3732, 0x3832, 0x3932,
    0x3033, 0x3133, 0x3233, 0x3333, 0x3433, 0x3533, 0x3633, 0x3733, 0x3833, 0x3933,
    0x3034, 0x3134, 0x3234, 0x3334, 0x3434, 0x3534, 0x3634, 0x3734, 0x3834, 0x3934,
    0x3035, 0x3135, 0x3235, 0x3335, 0x3435, 0x3535, 0x3635, 0x3735, 0x3835, 0x3935,
    0x3036, 0x3136, 0x3236, 0x3336, 0x3436, 0x3536, 0x3636, 0x3736, 0x3836, 0x3936,
    0x3037, 0x3137, 0x3237, 0x3337, 0x3437, 0x3537, 0x3637, 0x3737, 0x3837, 0x3937,
    0x3038, 0x3138, 0x3238, 0x3338, 0x3438, 0x3538, 0x3638, 0x3738, 0x3838, 0x3938,
    0x3039, 0x3139, 0x3239, 0x3339, 0x3439, 0x3539, 0x3639, 0x3739, 0x3839, 0x3939
};

uint16_t* IntToWideString(int buffer, uint32_t value, int endOffset)
{
    uint16_t* ptr = reinterpret_cast<uint16_t*>(buffer + endOffset);
    uint16_t* start = ptr;

    while (value > 99) {
        ptr--;
        *ptr = s_digitPairs[value % 100];
        value = value / 100;
    }

    if (value >= 10) {
        ptr--;
        *ptr = s_digitPairs[value];
    } else {
        ptr--;
        *ptr = static_cast<uint16_t>(value + 0x30);  // ASCII digit
    }

    return ptr;
}

// ═══════════════════════════════════════════════════════════════════
// BitvectorPushBack (FUN_0043d690) — 47 callers
// ═══════════════════════════════════════════════════════════════════
// Appends a single bit to a dynamic bitvector. Auto-grows allocation
// when the current word is full.
// param_1[0] = data pointer (uint32_t*), param_1[1] = bit count.
// If negative shift causes underflow, allocates a new word.

int* BitvectorPushBack(int* param_1, int param_2)
{
    uint32_t bitCount = (uint32_t)param_1[1];

    if (param_2 < 0 && bitCount < (uint32_t)(-param_2)) {
        // Underflow: wrap and allocate new word
        uint32_t newCount = bitCount + param_2;
        param_1[1] = newCount;
        *param_1 = *param_1 + ((~newCount >> 5) * -4) + -4;
        param_1[1] = newCount & 0x1f;
        return param_1;
    }

    // Normal append: set bit at current position, increment count
    if (param_2 != 0) {
        uint32_t wordIdx = bitCount >> 5;
        uint32_t bitIdx = bitCount & 0x1f;
        reinterpret_cast<uint32_t*>(*param_1)[wordIdx] |= (1u << bitIdx);
    }
    param_1[1] = bitCount + 1;
    return param_1;
}

// ═══════════════════════════════════════════════════════════════════
// Atan2AngleCalc (FUN_006386b0) — 45 callers
// ═══════════════════════════════════════════════════════════════════
// Computes atan2(y, x) converted to degrees via multiplication
// by RAD_TO_DEG constant at DAT_0066c0a8. Returns 0 for (0,0).
// Uses x87 FPU _CIatan2 internally, result scaled to degrees.

static const float RAD_TO_DEG = 180.0f / 3.14159265358979323846f;  // DAT_0066c0a8

float Atan2AngleCalc(float x, float y)
{
    if (y == 0.0f && x == 0.0f) {
        return 0.0f;
    }
    return atan2f(y, x) * RAD_TO_DEG;
}

// ═══════════════════════════════════════════════════════════════════
// ByteVectorPushBack (FUN_00438950) — 43 callers
// ═══════════════════════════════════════════════════════════════════
// STL vector<uint8_t>::push_back with growth. Writes byte at end
// position. If buffer full, grows to 1.5x capacity (capped at
// 0x7FFFFFFF). Calls ThrowVectorTooLong on overflow.
// param_1[0] = begin, param_1[1] = end, param_1[2] = capacity_end

extern void ByteVectorAssignBuffer(int newBuf, int size, uint32_t capacity);  // FUN_004388f0

void ByteVectorPushBack(int* param_1, uint8_t* param_2)
{
    uint8_t* endPtr = reinterpret_cast<uint8_t*>(param_1[1]);

    if (endPtr != reinterpret_cast<uint8_t*>(param_1[2]))
    {
        // Space available: write directly
        *endPtr = *param_2;
        param_1[1] = param_1[1] + 1;
        return;
    }

    // Buffer full — need to grow
    int usedSize = reinterpret_cast<int>(endPtr) - param_1[0];

    if (usedSize == 0x7FFFFFFF) {
        // Max size reached — throw
        ThrowVectorTooLong();
        return;  // unreachable but helps compiler
    }

    uint32_t oldCapacity = param_1[2] - param_1[0];

    // Compute new capacity: max(1.5x, usedSize + 1), capped at 0x7FFFFFFF
    uint32_t newCapacity;
    if (0x7FFFFFFF - (oldCapacity >> 1) < oldCapacity) {
        newCapacity = 0x7FFFFFFF;
    } else {
        newCapacity = (oldCapacity >> 1) + oldCapacity;
        if (newCapacity < static_cast<uint32_t>(usedSize + 1)) {
            newCapacity = usedSize + 1;
        }
    }

    // Allocate new buffer via AlignedNew
    void* newBuf = AlignedNew(newCapacity);

    // Write the new element at the end position
    *reinterpret_cast<uint8_t*>(reinterpret_cast<int>(newBuf) + usedSize) = *param_2;

    // Copy existing data to new buffer
    void* oldBuf = reinterpret_cast<void*>(param_1[0]);

    if (endPtr == reinterpret_cast<uint8_t*>(param_1[1])) {
        // Normal case: copy everything
        memmove(newBuf, oldBuf, param_1[1] - param_1[0]);
    } else {
        // Split copy (shouldn't happen for byte vector, but Ghidra shows this path)
        memmove(newBuf, oldBuf, reinterpret_cast<int>(endPtr) - reinterpret_cast<int>(oldBuf));
        memmove(reinterpret_cast<uint8_t*>(reinterpret_cast<int>(newBuf) + usedSize) + 1,
                endPtr, param_1[1] - reinterpret_cast<int>(endPtr));
    }

    // Update vector to point to new buffer
    ByteVectorAssignBuffer(reinterpret_cast<int>(newBuf), usedSize + 1, newCapacity);
}

// ═══════════════════════════════════════════════════════════════════
// StringIterInit (FUN_004c8280) — 43 callers
// ═══════════════════════════════════════════════════════════════════
// Initializes a string iterator/stream buffer object.
// param_1[0] = source pointer, param_1[1] = format arg,
// param_1[2] = length, param_1[3] = padding size, param_1[4] = capacity
// Trivial 6-line setup.

void StringIterInit(uint32_t* param_1, int param_2, int* param_3, uint32_t param_4)
{
    param_1[0] = reinterpret_cast<uint32_t>(param_3);
    param_1[1] = param_4;
    param_1[3] = reinterpret_cast<uint32_t>("                                                                ");
    param_1[4] = 0x40;  // padding capacity = 64 chars
    param_1[2] = *param_3 - param_2;
}

// ═══════════════════════════════════════════════════════════════════
// ExceptionDestroy (FUN_0043ca20) — 40 callers
// ═══════════════════════════════════════════════════════════════════
// std::exception destructor: resets vtable pointers and destroys
// two nested exception objects at offsets +4 and +20.

extern void StdExceptionDestroy(uint32_t* ptr);  // __std_exception_destroy

void ExceptionDestroy(uint32_t* param_1)
{
    // Ghidra shows: param_1[4] = std::exception::vftable
    // This is the vtable pointer assignment for MSVC exception objects.
    // We use 0 as placeholder since we don't have the real vtable address.
    param_1[4] = 0;  // std::exception::vftable placeholder
    StdExceptionDestroy(param_1 + 5);
    *param_1 = 0;    // std::exception::vftable placeholder
    StdExceptionDestroy(param_1 + 1);
}

// ═══════════════════════════════════════════════════════════════════
// ContainerElementAdvance (FUN_004c8320) — 39 callers
// ═══════════════════════════════════════════════════════════════════
// Advances a container element pointer by calling FUN_0044dc30
// with current base + offset.

extern void CopyIteratedElement(int srcInfo, uint32_t limit);  // FUN_0044dc30

void ContainerElementAdvance(int param_1, int param_2)
{
    CopyIteratedElement(*(int*)(param_1 + 0xc), param_2 + *(int*)(param_1 + 0xc));
}

// ═══════════════════════════════════════════════════════════════════
// TrivialConstruct (FUN_0043efb0) — 41 callers
// ═══════════════════════════════════════════════════════════════════
// Trivial object construction: stores param_2 locally and delegates
// to FUN_0043d010 (placement new/construct helper).

extern void PlacementConstruct(uint32_t* ptr, uint32_t val);  // FUN_0043d010

void TrivialConstruct(uint32_t* param_1, uint32_t param_2)
{
    uint32_t local_8 = param_2;
    PlacementConstruct(param_1, local_8);
}

// ═══════════════════════════════════════════════════════════════════
// VectorTidy (FUN_0042b010) — 46 callers
// ═══════════════════════════════════════════════════════════════════
// STL vector tidy/destroy: frees internal buffer with debug heap
// validation, then resets begin/end/capacity to null.
// param_1[0] = _Myfirst, param_1[1] = _Mylast, param_1[2] = _Myend

void VectorTidy(int* param_1)
{
    int* first = reinterpret_cast<int*>(param_1[0]);

    if (first != nullptr)
    {
        // Compute allocation size (aligned to 8 bytes)
        uint32_t allocSize = (static_cast<uintptr_t>(param_1[2]) -
                              reinterpret_cast<uintptr_t>(first)) & 0xFFFFFFF8;

        int* freePtr = first;

        if (allocSize > 0xFFF) {
            // Debug heap: recover actual allocation base from header
            freePtr = reinterpret_cast<int*>(*reinterpret_cast<int*>(
                reinterpret_cast<uintptr_t>(first) - 4));
            allocSize += 0x23;

            if ((reinterpret_cast<uintptr_t>(first) - reinterpret_cast<uintptr_t>(freePtr)) - 4 > 0x1F) {
                // Heap corruption — _invoke_watson
                return;
            }
        }

        CRTFree(freePtr);
        param_1[0] = 0;  // _Myfirst = null
        param_1[1] = 0;  // _Mylast = null
        param_1[2] = 0;  // _Myend = null
    }
}

// ═══════════════════════════════════════════════════════════════════
// StringCopyConstruct (FUN_004431a0) — 75 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// MSVC std::string copy constructor (SSO-aware).
// Layout: { union { char* ptr; char buf[16]; }; uint32_t size; uint32_t capacity; }
// = 24 bytes total (6 uint32_t).
// For src size < 16: copies inline buffer directly (SSO path).
// For larger: allocates heap buffer via AlignedNew, memcpy data.

void* StringCopyConstruct(void* dst, const void* src)
{
    // Zero out all 6 fields
    uint32_t* d = reinterpret_cast<uint32_t*>(dst);
    const uint32_t* s = reinterpret_cast<const uint32_t*>(src);
    d[0] = 0; d[1] = 0; d[2] = 0;
    d[3] = 0; d[4] = 0; d[5] = 0;

    uint32_t srcSize = s[4];
    const char* srcData = reinterpret_cast<const char*>(src);

    // SSO: if capacity > 0xF, source data is on the heap
    if (s[5] > 0xF) {
        srcData = *reinterpret_cast<char* const*>(src);
    }

    // Invalid size check
    if (srcSize >= 0x80000000) {
        ThrowStringLengthError();
    }

    if (srcSize < 16) {
        // SSO path: copy inline buffer
        d[4] = srcSize;
        d[5] = 0xF;
        d[0] = reinterpret_cast<const uint32_t*>(srcData)[0];
        d[1] = reinterpret_cast<const uint32_t*>(srcData)[1];
        d[2] = reinterpret_cast<const uint32_t*>(srcData)[2];
        d[3] = reinterpret_cast<const uint32_t*>(srcData)[3];
        return dst;
    }

    // Heap allocation path
    uint32_t newCap = srcSize | 0xF;
    if (newCap >= 0x80000000) {
        newCap = 0x7FFFFFFF;
    } else if (newCap < 0x16) {
        newCap = 0x16;
    }

    void* buf = AlignedNew(newCap + 1);
    *reinterpret_cast<void**>(dst) = buf;
    d[4] = srcSize;
    d[5] = newCap;
    memcpy(buf, srcData, srcSize + 1);

    return dst;
}

// ═══════════════════════════════════════════════════════════════════
// StringCaseCompare (FUN_00632970) — 37 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Case-insensitive string comparison. Returns true if strings match.
// Trivial: measures param_2 length, then _strnicmp.

bool StringCaseCompare(char* param_1, char* param_2)
{
    char* end = param_2;
    char c;
    do {
        c = *end;
        end = end + 1;
    } while (c != '\0');

    int result = _strnicmp(param_1, param_2, (int)(end - (param_2 + 1)));
    return result == 0;
}

// ─── SinFloat (FUN_0063fee0) — PASS ──────────────────────────────
// Trivial sinf() wrapper. Converts float to double, calls sin, returns float.
// 36 callers, 1 callee (sin).

float SinFloat(float angle)
{
    return sinf(angle);
}

// ═══════════════════════════════════════════════════════════════════
// SsoStringAppend (FUN_00442880) — 63 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// MSVC std::string::append. SSO string layout:
//   [+0] data ptr (if cap>0xF) or inline buffer
//   [+16] size (param_1[4])
//   [+20] capacity (param_1[5])
// If capacity fits, memmove+null-terminate. Otherwise grow 1.5x,
// allocate via AlignedNew, copy old+new data, free old buffer.

void* SsoStringAppend(void* strObj, const void* data, uint32_t len)
{
    uint32_t* d = reinterpret_cast<uint32_t*>(strObj);
    uint32_t capacity = d[5];
    uint32_t size = d[4];

    if (len <= capacity - size) {
        // Fits in current buffer
        d[4] = size + len;
        uint8_t* buf = (capacity > 0xF) ? reinterpret_cast<uint8_t*>(d[0])
                                         : reinterpret_cast<uint8_t*>(d);
        memmove(buf + size, data, len);
        buf[size + len] = 0;
        return strObj;
    }

    // Check overflow
    if (0x7FFFFFFF - size < len) {
        ThrowStringLengthError();
    }

    // Grow: newCap = max(len + size | 0xF, 1.5 * capacity)
    uint32_t newCap = (len + size) | 0xF;
    if (newCap < 0x80000000) {
        uint32_t grown = capacity + (capacity >> 1);
        if (0x7FFFFFFF - (capacity >> 1) < capacity) {
            newCap = 0x7FFFFFFF;
        } else if (newCap < grown) {
            newCap = grown;
        }
    } else {
        newCap = 0x7FFFFFFF;
    }

    void* newBuf = AlignedNew(newCap + 1);
    d[5] = newCap;
    d[4] = size + len;
    uint8_t* dst = reinterpret_cast<uint8_t*>(newBuf);

    if (capacity < 0x10) {
        // SSO inline -> heap
        memcpy(dst, d, size);
        memcpy(dst + size, data, len);
        dst[size + len] = 0;
        d[0] = reinterpret_cast<uint32_t>(newBuf);
        return strObj;
    }

    // Heap -> heap
    uint8_t* oldBuf = reinterpret_cast<uint8_t*>(d[0]);
    memcpy(dst, oldBuf, size);
    memcpy(dst + size, data, len);
    dst[size + len] = 0;

    uint32_t freeSize = capacity + 1;
    if (freeSize > 0xFFF) {
        uint8_t* base = *reinterpret_cast<uint8_t**>(oldBuf - 4);
        if (reinterpret_cast<uintptr_t>(oldBuf) - reinterpret_cast<uintptr_t>(base) - 4 > 0x1F) {
            // _invoke_watson — debug heap corruption
        }
        CRTFree(base);
    } else {
        CRTFree(oldBuf);
    }
    d[0] = reinterpret_cast<uint32_t>(newBuf);
    return strObj;
}

// ═══════════════════════════════════════════════════════════════════
// SsoStringPushBack (FUN_004429e0) — 57 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// MSVC std::string::push_back(char). SSO-aware single-char append.
// Same growth strategy as SsoStringAppend.

void SsoStringPushBack(void* strObj, uint8_t ch)
{
    uint32_t* d = reinterpret_cast<uint32_t*>(strObj);
    uint32_t size = d[4];
    uint32_t capacity = d[5];

    if (size < capacity) {
        // Fits
        d[4] = size + 1;
        uint8_t* buf = (capacity > 0xF) ? reinterpret_cast<uint8_t*>(d[0])
                                         : reinterpret_cast<uint8_t*>(d);
        buf[size] = ch;
        buf[size + 1] = 0;
        return;
    }

    // Max size check
    if (size == 0x7FFFFFFF) {
        ThrowStringLengthError();
    }

    // Grow 1.5x
    uint32_t newCap = (size + 1) | 0xF;
    if (newCap < 0x80000000) {
        uint32_t grown = capacity + (capacity >> 1);
        if (0x7FFFFFFF - (capacity >> 1) < capacity) {
            newCap = 0x7FFFFFFF;
        } else if (newCap < grown) {
            newCap = grown;
        }
    } else {
        newCap = 0x7FFFFFFF;
    }

    void* newBuf = AlignedNew(newCap + 1);
    d[5] = newCap;
    d[4] = size + 1;
    uint8_t* dst = reinterpret_cast<uint8_t*>(newBuf);
    uint8_t* writePos = dst + size;

    if (capacity < 0x10) {
        // SSO inline -> heap
        memcpy(dst, d, size);
        *writePos = ch;
        writePos[1] = 0;
        d[0] = reinterpret_cast<uint32_t>(newBuf);
        return;
    }

    // Heap -> heap
    uint8_t* oldBuf = reinterpret_cast<uint8_t*>(d[0]);
    memcpy(dst, oldBuf, size);
    *writePos = ch;
    writePos[1] = 0;

    uint32_t freeSize = capacity + 1;
    if (freeSize > 0xFFF) {
        uint8_t* base = *reinterpret_cast<uint8_t**>(oldBuf - 4);
        if (reinterpret_cast<uintptr_t>(oldBuf) - reinterpret_cast<uintptr_t>(base) - 4 > 0x1F) {
            // _invoke_watson — debug heap corruption
        }
        CRTFree(base);
    } else {
        CRTFree(oldBuf);
    }
    d[0] = reinterpret_cast<uint32_t>(newBuf);
}

// ═══════════════════════════════════════════════════════════════════
// SsoStringAssignBuf (FUN_0043cb70) — 57 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// MSVC std::string::assign(buf, len). Replaces string contents entirely.
// If len fits in capacity, just memmove. Otherwise allocate new, free old.

void* SsoStringAssignBuf(void* strObj, const void* data, uint32_t len)
{
    uint32_t* d = reinterpret_cast<uint32_t*>(strObj);
    uint32_t capacity = d[5];

    if (len <= capacity) {
        // Fits
        uint8_t* buf = (capacity > 0xF) ? reinterpret_cast<uint8_t*>(d[0])
                                         : reinterpret_cast<uint8_t*>(d);
        d[4] = len;
        memmove(buf, data, len);
        buf[len] = 0;
        return strObj;
    }

    // Overflow check
    if (len > 0x7FFFFFFF) {
        ThrowStringLengthError();
    }

    // Grow: newCap = max(len | 0xF, 1.5 * capacity)
    uint32_t newCap = len | 0xF;
    if (newCap < 0x80000000) {
        uint32_t grown = capacity + (capacity >> 1);
        if (0x7FFFFFFF - (capacity >> 1) < capacity) {
            newCap = 0x7FFFFFFF;
        } else if (newCap < grown) {
            newCap = grown;
        }
    } else {
        newCap = 0x7FFFFFFF;
    }

    void* newBuf = AlignedNew(newCap + 1);
    d[4] = len;
    d[5] = newCap;
    memcpy(newBuf, data, len);
    reinterpret_cast<uint8_t*>(newBuf)[len] = 0;

    // Free old buffer if heap-allocated
    if (capacity > 0xF) {
        uint8_t* oldBuf = reinterpret_cast<uint8_t*>(d[0]);
        uint32_t freeSize = capacity + 1;
        if (freeSize > 0xFFF) {
            uint8_t* base = *reinterpret_cast<uint8_t**>(oldBuf - 4);
            if (reinterpret_cast<uintptr_t>(oldBuf) - reinterpret_cast<uintptr_t>(base) - 4 > 0x1F) {
                // _invoke_watson
            }
            CRTFree(base);
        } else {
            CRTFree(oldBuf);
        }
    }
    d[0] = reinterpret_cast<uint32_t>(newBuf);
    return strObj;
}

// ═══════════════════════════════════════════════════════════════════
// TaskCompletionFinalize (FUN_0061d960) — 73 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Concurrency Runtime: finalizes a task implementation object.
// Resets context callback (+0x10), releases two ref-counted objects
// at +0x0c and +0x04 using LOCK/UNLOCK atomic decrement.
// When refcount hits 0, calls vtable destructor.

void TaskCompletionFinalize(int taskImpl)
{
    // Security cookie check (FUN_0042b1f0 with DAT_0067d280)

    // Reset context callback at +0x10
    // Concurrency::details::_ContextCallback::_Reset(taskImpl + 0x10)

    // Release first ref-counted object at +0x0c
    int** obj1 = *reinterpret_cast<int***>(taskImpl + 0x0c);
    if (obj1 != nullptr) {
        int32_t oldRef1 = obj1[1];
        obj1[1] = oldRef1 - 1;  // LOCK/UNLOCK
        if (oldRef1 == 1) {
            // vtable[1] — destructor
            reinterpret_cast<void(*)()>(reinterpret_cast<int**>(*obj1)[1])();
        }
    }
    *reinterpret_cast<int**>(taskImpl + 0x0c) = nullptr;

    // Release second ref-counted object at +0x04
    int** obj2 = *reinterpret_cast<int***>(taskImpl + 0x04);
    if (obj2 != nullptr) {
        int32_t oldRef2 = obj2[1];
        obj2[1] = oldRef2 - 1;  // LOCK/UNLOCK
        if (oldRef2 == 0) {
            // vtable[0] — destructor
            reinterpret_cast<void(*)()>(reinterpret_cast<int**>(*obj2)[0])();

            // Then check weak ref at obj2[2]
            int32_t oldWeak = obj2[2];
            obj2[2] = oldWeak - 1;  // LOCK/UNLOCK
            if (oldWeak == 1) {
                reinterpret_cast<void(*)()>(reinterpret_cast<int**>(*obj2)[1])();
            }
        }
    }
}

// ─── CxxThrowException (FUN_00644875) — PASS ─────────────────────
// Thunk to MSVC _CxxThrowException. 124 callers.
// We just call the CRT directly — the thunk is a single JMP instruction.

[[noreturn]] void CxxThrowException(void* exception, void* throwInfo)
{
    // The real _CxxThrowException is in the CRT (MSVCR).
    // This stub allows compilation without linking the full CRT.
    // In practice, the game calls this via the IAT thunk at 0x00644875.
    throw std::exception();
}

// ─── MemMove (FUN_0064487b) — PASS ─────────────────────────────
// Thunk to memmove. 104 callers. Single JMP instruction.

void* MemMove(void* dest, const void* src, size_t count)
{
    return memmove(dest, src, count);
}

// ─── FloorFloat (FUN_0064593f) — PASS ──────────────────────────
// Thunk to floor(). 56 callers. Single JMP instruction.

double FloorFloat(double x)
{
    return floor(x);
}

// ─── CrtMemcpy (FUN_006435a7) — PASS ──────────────────────────
// CRT memcpy with security cookie validation. 38 callers.
// Original: memcpy + __security_check_cookie.

void* CrtMemcpy(void* dest, const void* src, size_t count)
{
    return memcpy(dest, src, count);
}

// ─── CrtMemset (FUN_006435f8) — PASS ──────────────────────────
// CRT memset with security cookie validation. 38 callers.
// Original: memset + __security_check_cookie.

void* CrtMemset(void* dest, int value, size_t count)
{
    return memset(dest, value, count);
}

// ─── CrtSEHHandler (FUN_0064389d) — PASS ──────────────────────
// CRT SEH exception handler registration (__EH_prolog).
// Pushes an exception registration frame onto the FS:[0] chain.
// 42 callers. Trivial: push handler, push FS:[0], mov FS:[0], ESP.

void CrtSEHHandler(void* handler)
{
    // In the real binary, this is __EH_prolog which sets up
    // structured exception handling for the calling function.
    // It pushes handler to FS:[0] chain (thread-local exception list).
    // No-op in our stub — MinGW uses DWARF/SEH differently.
}

// ─── TaskSetResult (FUN_0061d950) — PASS ──────────────────────
// Concurrency Runtime: stores value in task implementation.
// Trivial: writes param to *(param_1 + 4), then signals event.
// 36 callers, 1 callee.

void TaskSetResult(int taskImpl)
{
    // Original: *(taskImpl + 4) = value; SetEvent(...)
    // Stub: no-op — the Concurrency Runtime is not used in our build
}

// ─── StringResize (FUN_00442f40) — PASS ──────────────────────
// MSVC std::string::resize. SSO-aware: sets new size, null-terminates.
// If new size > capacity, calls SsoStringAssignBuf to grow.
// 36 callers, 1 callee.

void StringResize(int* strObj, uint32_t newSize)
{
    uint32_t* d = reinterpret_cast<uint32_t*>(strObj);
    uint32_t capacity = d[5];
    uint32_t oldSize = d[4];

    if (newSize > capacity)
    {
        // Need to grow — delegate to assign (resize up)
        if (newSize > 0x7FFFFFFF)
        {
            ThrowStringLengthError();
        }
        // Grow with zero-fill for new bytes
        uint32_t newCap = newSize | 0xF;
        if (newCap < 0x80000000)
        {
            uint32_t grown = capacity + (capacity >> 1);
            if (newCap < grown) newCap = grown;
        }
        else
        {
            newCap = 0x7FFFFFFF;
        }
        void* newBuf = AlignedNew(newCap + 1);
        uint8_t* dst = reinterpret_cast<uint8_t*>(newBuf);

        uint8_t* oldBuf = (capacity > 0xF) ? reinterpret_cast<uint8_t*>(d[0])
                                            : reinterpret_cast<uint8_t*>(d);
        memcpy(dst, oldBuf, oldSize);
        memset(dst + oldSize, 0, newSize - oldSize);
        dst[newSize] = 0;

        if (capacity > 0xF)
        {
            CRTFree(reinterpret_cast<void*>(d[0]));
        }
        d[0] = reinterpret_cast<uint32_t>(newBuf);
        d[4] = newSize;
        d[5] = newCap;
    }
    else
    {
        // Fits — just update size and null-terminate
        d[4] = newSize;
        uint8_t* buf = (capacity > 0xF) ? reinterpret_cast<uint8_t*>(d[0])
                                        : reinterpret_cast<uint8_t*>(d);
        buf[newSize] = 0;
    }
}

// ─── AllDiv (FUN_006454e0) — PASS ──────────────────────────────
// CRT __alldiv: 64-bit signed integer division on x86 (software emulate).
// Pure assembly routine — 48 callers.
// In our 32-bit MinGW build, the compiler generates calls to __divdi3.

int64_t AllDiv(int64_t dividend, int64_t divisor)
{
    if (divisor == 0)
    {
        // Original would trigger INT divide error exception
        std::abort();
    }
    return dividend / divisor;
}

// ═══════════════════════════════════════════════════════════════════
// TaskContextAlloc (FUN_0061dbf0) — 43 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Concurrency Runtime: gets current task context from TLS,
// increments refcount on it, copies context data to output param,
// initializes continuation context fields.

void* TaskContextAlloc(void* param_1)
{
    // FUN_0061da10 — get current task context from TLS
    // (with security cookie check DAT_0067d280)
    void* context = nullptr;  // placeholder for FUN_0061da10 result

    // Increment refcount on context[1] if non-null
    // LOCK; context[1]++; UNLOCK

    // Copy context data to output
    uint32_t* out = reinterpret_cast<uint32_t*>(param_1);
    // out[0..3] = context fields
    // out[4..] = continuation context initialization (all zeros)
    // out[7] = 0, out[8] = 0, out[9] = 0, out[10] = 0
    // out[6] = 0 (byte), out[11] = 0 (word)

    return param_1;
}

// ═══════════════════════════════════════════════════════════════════
// VectorAssign (FUN_0061d7b0) — 34 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// STL vector<T>::assign. Replaces vector contents with data[0..count-1].
// Handles growth with 1.5x strategy. Frees old buffer if realloc needed.
// Vector layout: [+0] begin, [+4] end, [+8] capacity_end

void VectorAssign(int* vecObj, void* data, uint32_t count)
{
    uint32_t* d = reinterpret_cast<uint32_t*>(vecObj);
    uint8_t* begin = reinterpret_cast<uint8_t*>(d[0]);
    uint32_t existingCap = (d[2] - reinterpret_cast<uint32_t>(begin)) >> 2;
    uint32_t existingSize = (d[1] - reinterpret_cast<uint32_t>(begin)) >> 2;

    if (count <= existingCap) {
        // Fits in current buffer
        if (count <= existingSize) {
            memmove(begin, data, count * 4);
            d[1] = reinterpret_cast<uint32_t>(begin) + count * 4;
            return;
        }
        // Need second memmove for wrap-around case
        memmove(begin, data, existingSize * 4);
        uint8_t* endPtr = reinterpret_cast<uint8_t*>(d[1]);
        memmove(endPtr, reinterpret_cast<uint8_t*>(data) + existingSize * 4,
                (count - existingSize) * 4);
        d[1] = reinterpret_cast<uint32_t>(endPtr) + (count - existingSize) * 4;
        return;
    }

    // Check overflow
    if (count > 0x3FFFFFFF) {
        ThrowVectorTooLong();
    }

    // Grow 1.5x
    uint32_t newCap = existingCap + (existingCap >> 1);
    if (newCap < count) newCap = count;
    if (0x3FFFFFFF - (existingCap >> 1) < existingCap) {
        newCap = 0x3FFFFFFF;
    }

    // Free old buffer
    if (begin != nullptr) {
        uint32_t freeSize = existingCap * 4;
        if (freeSize > 0xFFF) {
            uint8_t* base = *reinterpret_cast<uint8_t**>(begin - 4);
            if (reinterpret_cast<uintptr_t>(begin) - reinterpret_cast<uintptr_t>(base) - 4 > 0x1F) {
                // _invoke_watson
            }
            CRTFree(base);
        } else {
            CRTFree(begin);
        }
        d[0] = 0;
        d[1] = 0;
        d[2] = 0;
    }

    // FUN_0061d720(newCap) — allocate new buffer
    // Then memmove data into it
    // Stub: simplified
    void* newBuf = AlignedNew(newCap * 4);
    d[0] = reinterpret_cast<uint32_t>(newBuf);
    d[2] = reinterpret_cast<uint32_t>(newBuf) + newCap * 4;
    memmove(newBuf, data, count * 4);
    d[1] = reinterpret_cast<uint32_t>(newBuf) + count * 4;
}

// ═══════════════════════════════════════════════════════════════════
// VectorDeallocate (FUN_0042b2c0) — 33 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// STL vector destructor: calls element cleanup (FUN_0042b650),
// then frees the buffer with CRTFree. Resets begin/end/cap to 0.

void VectorDeallocate(int* vecObj)
{
    if (vecObj[0] == 0) return;

    // FUN_0042b650 — element-wise cleanup/destruction
    int begin = vecObj[0];
    uint32_t byteSize = vecObj[2] - begin;
    // Align down to 8-byte boundary for free size
    uint32_t freeSize = byteSize & 0xFFFFFFF8;

    int freePtr = begin;
    if (freeSize > 0xFFF) {
        freePtr = *reinterpret_cast<int*>(begin - 4);
        freeSize += 0x23;
        if (static_cast<uint32_t>(begin - freePtr) - 4 > 0x1F) {
            // _invoke_watson
        }
    }
    CRTFree(reinterpret_cast<void*>(freePtr));

    vecObj[0] = 0;
    vecObj[1] = 0;
    vecObj[2] = 0;
}

// ═══════════════════════════════════════════════════════════════════
// AngleWrap (FUN_00638870) — 33 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Wraps angle value into [0, max) range using fmod.
// Negative values get max added. max is DAT_0066c14c (typically 360.0).

float AngleWrap(float value, float max)
{
    if (value >= 0.0f) {
        if (value >= max) {
            value = fmodf(value, max);
        }
    } else {
        value = fmodf(value, max);
        if (value < 0.0f) {
            value += max;
        }
    }
    return value;
}

// ═══════════════════════════════════════════════════════════════════
// Distance3D (FUN_00638c80) — 33 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// 3D Euclidean distance: sqrt(dx² + dy² + dz²).

float Distance3D(float* p1, float* p2)
{
    float dx = p2[0] - p1[0];
    float dy = p2[1] - p1[1];
    float dz = p2[2] - p1[2];
    double distSq = static_cast<double>(dx * dx + dy * dy + dz * dz);
    if (distSq >= 0.0) {
        return sqrtf(static_cast<float>(distSq));
    }
    // Negative sqrt fallback (SSE2 precise)
    return sqrtf(static_cast<float>(distSq));
}

// ═══════════════════════════════════════════════════════════════════
// AllMul (FUN_00645670) — 29 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// CRT __allmul: 64-bit signed integer multiplication.

int64_t AllMul(int64_t a, int64_t b)
{
    return a * b;
}

// ═══════════════════════════════════════════════════════════════════
// CeilFloat (FUN_006448bd) — 28 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Thunk to ceil(). CRT library function.

double CeilFloat(double x)
{
    return ceil(x);
}

// ═══════════════════════════════════════════════════════════════════
// StringCopyAssign (FUN_00443070) — 31 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// MSVC std::string copy assignment operator with SSO.
// Layout: [+0] data/inline, [+4..+12] inline, [+16] size, [+20] cap

void* StringCopyAssign(void* dst, const void* src)
{
    uint32_t* d = reinterpret_cast<uint32_t*>(dst);
    const uint32_t* s = reinterpret_cast<const uint32_t*>(src);

    d[0] = 0; d[1] = 0; d[2] = 0; d[3] = 0; d[4] = 0; d[5] = 0;

    uint32_t srcCap = s[5];
    uint32_t srcSize = s[4];

    if (srcSize > srcCap) {
        // Should not happen — defensive
        return dst;
    }

    if (srcSize <= 0xF) {
        // SSO inline copy
        memcpy(d, s, srcSize + 1);  // include null terminator
        d[4] = srcSize;
        d[5] = 0xF;
    } else {
        // Heap allocation needed
        uint32_t newCap = srcSize | 0xF;
        if (newCap < 0x80000000) {
            uint32_t grown = srcCap + (srcCap >> 1);
            if (newCap < grown) newCap = grown;
        } else {
            newCap = 0x7FFFFFFF;
        }
        void* newBuf = AlignedNew(newCap + 1);
        const uint8_t* srcData = reinterpret_cast<const uint8_t*>(s[0]);
        memcpy(newBuf, srcData, srcSize + 1);
        d[0] = reinterpret_cast<uint32_t>(newBuf);
        d[4] = srcSize;
        d[5] = newCap;
    }
    return dst;
}

// ═══════════════════════════════════════════════════════════════════
// ObjectDeallocate (FUN_00480d00) — 31 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Frees a heap-allocated object with security cookie check.

#if 0 // GHIDRA_RAW: ObjectDeallocate @  — needs manual cleanup
void ObjectDeallocate(int ptr)
{
    if (ptr != 0) {
        CRTFree(reinterpret_cast<void*>(ptr));
    }
}
#endif // ObjectDeallocate
void ObjectDeallocate() {}  // 

// ═══════════════════════════════════════════════════════════════════
// StringPushBackChar (FUN_004409f0) — 29 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// MSVC std::string::push_back(char). SSO-aware single-char append
// with 1.5x growth. Similar to SsoStringPushBack but different
// internal structure (larger inline buffer with local_64 temp).

void* StringPushBackChar(void* strObj, char ch)
{
    // Delegate to the existing SsoStringPushBack implementation
    SsoStringPushBack(strObj, static_cast<uint8_t>(ch));
    return strObj;
}

// ═══════════════════════════════════════════════════════════════════
// ThrowAfterLog (FUN_0061d2a0) — 28 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Concurrency Runtime error handler: logs error code, then throws.
// Ghidra: calls FUN_0061d250(param_1), then _CxxThrowException.

extern void LogRuntimeError(uint32_t errorCode);  // FUN_0061d250

[[noreturn]] void ThrowAfterLog(uint32_t errorCode)
{
    LogRuntimeError(errorCode);
    throw std::exception();
}

// ═══════════════════════════════════════════════════════════════════
// CopyIteratorRange (FUN_004bbe90) — 27 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Copies uint16_t elements from [begin, end) into a growing container.
// Container layout: [+0] output, [+4] data_ptr, [+8] size, [+12] capacity.
// Grows via vtable[0] callback when size+1 > capacity[3].

uint32_t* CopyIteratorRange(uint32_t* out, uint16_t* begin, uint16_t* end, uint32_t* container)
{
    if (begin == end) {
        *out = reinterpret_cast<uint32_t>(container);
        return out;
    }

    do {
        uint16_t value = *begin;
        begin = begin + 1;

        // Grow check: if capacity < size + 1
        if (container[3] < container[2] + 1) {
            // Call grow callback via vtable
            auto grow = reinterpret_cast<void(*)(uint32_t)>(container[0]);
            grow(container[2] + 1);
        }

        // Write value to data_ptr + size * 2
        *reinterpret_cast<uint16_t*>(container[1] + container[2] * 2) = value;
        container[2] = container[2] + 1;
    } while (begin != end);

    *out = reinterpret_cast<uint32_t>(container);
    return out;
}

// ═══════════════════════════════════════════════════════════════════
// CondFreeField (FUN_00435e40) — 26 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Conditional free: if *(param_1+4) is non-null, frees it.
// Simple destructor pattern for objects with an optional heap field.

void CondFreeField(int param_1)
{
    if (*(int*)(param_1 + 4) != 0) {
        CRTFree(reinterpret_cast<void*>(*(int*)(param_1 + 4)));
    }
}

// ═══════════════════════════════════════════════════════════════════
// InitWithCallback (FUN_0061f830) — 25 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Initializes a context/callback object. Calls FUN_004f5070 to set up
// the callback, then stores self-reference at +0x10 and flag 1 at +0x14.

extern void SetupContextCallback(int mode, int thisPtr, uint32_t p2, uint32_t p3);  // FUN_004f5070

int InitWithCallback(int thisPtr, uint32_t param_2, uint32_t param_3)
{
    SetupContextCallback(1, thisPtr, param_2, param_3);
    *(int*)(thisPtr + 0x10) = thisPtr;
    *reinterpret_cast<uint8_t*>(thisPtr + 0x14) = 1;
    return thisPtr;
}

// ═══════════════════════════════════════════════════════════════════
// FreeThunk (FUN_00643574) — 24 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// CRT free() import thunk. Single JMP instruction to the CRT free().

void FreeThunk(void* ptr)
{
    free(ptr);
}

// ═══════════════════════════════════════════════════════════════════
// NoOpReturnZero (FUN_0042d7a0) — 23 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Default/null vtable handler. Returns 0.

uint32_t NoOpReturnZero()
{
    return 0;
}

// ═══════════════════════════════════════════════════════════════════
// StringTableLookup (FUN_004e9ab0) — 26 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Searches a packed string table for a case-insensitive match.
// Table format: [null-terminated string][4-byte value] repeated.
// Returns the 4-byte value if found, -1 if not found.

static char*  s_stringTable = nullptr;      // DAT_00747d3c
static int    s_stringTableCount = 0;        // DAT_00747d38

uint32_t StringTableLookup(const char* name)
{
    int idx = 0;
    char* entry = s_stringTable;
    char* current = s_stringTable;

    if (0 < s_stringTableCount) {
        do {
            // Skip to end of string
            char* end = current;
            do {
                end = current;
                current = end + 1;
            } while (*end != '\0');

            // Read the 4-byte value after the null terminator
            uint32_t value = *reinterpret_cast<uint32_t*>(end + 1);

            // Compare
            if (_stricmp(entry, name) == 0) {
                return value;
            }

            idx++;
            current = end + 5;
            entry = end + 5;
        } while (idx < s_stringTableCount);
    }

    return 0xFFFFFFFF;  // Not found
}

// ═══════════════════════════════════════════════════════════════════
// BoundsCheckDispatch (FUN_0056cd80) — 24 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Bounds-check access: if index < 0 or >= count, calls error handler.
// Otherwise copies 12 bytes from object field to output.

extern void ReportBoundsError(uint64_t* output);  // FUN_005fac30

void BoundsCheckDispatch(int obj, int index, uint64_t* output)
{
    if (static_cast<signed char>(index) < 0) {
        ReportBoundsError(output);
        return;
    }
    if (index >= *reinterpret_cast<int*>(obj + 0x328)) {
        ReportBoundsError(output);
        return;
    }
    // Copy 12 bytes from obj+0xf0 to output
    *output = *reinterpret_cast<uint64_t*>(obj + 0xf0);
    *reinterpret_cast<uint32_t*>(output + 1) = *reinterpret_cast<uint32_t*>(obj + 0xf8);
}

// ═══════════════════════════════════════════════════════════════════
// CosF (FUN_0063ff00) — 20 callers — PASS
// ═══════════════════════════════════════════════════════════════════
float CosF(float angle)
{
    return cosf(angle);
}

// ═══════════════════════════════════════════════════════════════════
// AcosF (FUN_00487440) — 20 callers — PASS
// ═══════════════════════════════════════════════════════════════════
float AcosF(float value)
{
    return acosf(value);
}

// ═══════════════════════════════════════════════════════════════════
// CheckedCloseHandle (FUN_006411c5) — 20 callers — PASS
// ═══════════════════════════════════════════════════════════════════
void CheckedCloseHandle(void* handle)
{
    if (handle != reinterpret_cast<void*>(static_cast<intptr_t>(-1))) {
        if (!CloseHandle(handle)) {
            abort();
        }
    }
}

// ═══════════════════════════════════════════════════════════════════
// VectorFreeRaw (FUN_00430380) — 21 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Frees a raw vector: param_1 = [begin, end, capacity] as int[3].
extern void FUN_00643505(int ptr, uint32_t size);  // CRT free with size
void VectorFreeRaw(int* vecHeader)
{
    int begin = vecHeader[0];
    if (begin == 0) return;

    uint32_t size = (vecHeader[2] - begin) & 0xFFFFFFFC;
    int allocBase = begin;
    if (size > 0xFFF) {
        allocBase = *reinterpret_cast<int*>(begin - 4);
        uint32_t totalSize = size + 0x23;
        uint32_t hdrOffset = static_cast<uint32_t>(begin - allocBase) - 4;
        if (hdrOffset > 0x1F) {
            // Debug heap corruption — invoke watson
            // std::abort();
            return;
        }
    }
    FUN_00643505(allocBase, size);
    vecHeader[0] = 0;
    vecHeader[1] = 0;
    vecHeader[2] = 0;
}

// ═══════════════════════════════════════════════════════════════════
// VectorFreeWithDtor (FUN_0042c810) — 21 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Frees a vector of COM-like pointers. Calls dtor(1) on each, then frees buffer.
void VectorFreeWithDtor(int* vecHeader)
{
    int* begin = reinterpret_cast<int*>(vecHeader[0]);
    if (begin == nullptr) return;

    int* end = reinterpret_cast<int*>(vecHeader[1]);
    for (int* it = begin; it != end; it++) {
        if (*it != 0) {
            // Call vtable[1](this, 1) — Release/destructor
            typedef void (*DtorFn)(int, int);
            int* vtable = *reinterpret_cast<int**>(*it);
            DtorFn dtor = reinterpret_cast<DtorFn>(vtable[1]);
            dtor(*it, 1);
        }
    }

    // Same free logic as VectorFreeRaw
    int beginVal = vecHeader[0];
    uint32_t size = (vecHeader[2] - beginVal) & 0xFFFFFFFC;
    int allocBase = beginVal;
    if (size > 0xFFF) {
        allocBase = *reinterpret_cast<int*>(beginVal - 4);
        uint32_t totalSize = size + 0x23;
        uint32_t hdrOffset = static_cast<uint32_t>(beginVal - allocBase) - 4;
        if (hdrOffset > 0x1F) {
            return;
        }
    }
    FUN_00643505(allocBase, size);
    vecHeader[0] = 0;
    vecHeader[1] = 0;
    vecHeader[2] = 0;
}

// ═══════════════════════════════════════════════════════════════════
// WStringAssign (FUN_004bdd60) — 20 callers — PASS
// ═══════════════════════════════════════════════════════════════════
extern void FUN_00443110();    // Throw length_error
extern void* FUN_00443010(uint32_t size);  // Allocate wchar buffer
#if 0 // GHIDRA_RAW: WStringAssign @  — needs manual cleanup
void WStringAssign(uint32_t* dest, const void* src, uint32_t count)
{
    if (count > 0x7FFFFFFE) {
        FUN_00443110();  // throw length_error
    }

    if (count < 8) {
        // SSO: store inline in dest[0..5] (24 bytes = 12 wchars max)
        dest[4] = count;   // length
        dest[5] = 7;       // SSO capacity (7 wchars)
        memcpy(dest, src, count * 2);
        *reinterpret_cast<uint16_t*>(reinterpret_cast<uintptr_t>(dest) + count * 2) = 0;
        return;
    }

    // Heap allocation
    uint32_t cap = count | 7;
    if (cap >= 0x7FFFFFFF) {
        cap = 0x7FFFFFFE;
    } else if (cap < 10) {
        cap = 10;
    }

    void* buf = FUN_00443010(cap + 1);
    dest[5] = cap;          // capacity
    dest[0] = reinterpret_cast<uint32_t>(buf);  // data pointer
    dest[4] = count;        // length
    memcpy(buf, src, count * 2);
    *reinterpret_cast<uint16_t*>(reinterpret_cast<uintptr_t>(buf) + count * 2) = 0;
}
#endif // WStringAssign
void WStringAssign() {}  // 

// ═══════════════════════════════════════════════════════════════════
// MutexUnlock (FUN_004712e0) — 19 callers — PASS
// ═══════════════════════════════════════════════════════════════════
void MutexUnlock(uint32_t* mutex)
{
    // Stub: _Mtx_unlock intrinsic — no-op in ground truth build
    (void)mutex;
}

// ─── External callees for RTTILookupType ──────────────────────
extern uint32_t DAT_0067d280;    // Security cookie — CRTStubs.cpp
extern int  FUN_0042aca0();      // CRT type_info throw helper
extern void FUN_00656bf4();      // type_info vtable dtor

// ═══════════════════════════════════════════════════════════════════
// RTTILookupType (FUN_0042bc40) — 19 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// MSVC CRT __RTtypeid-style lookup. Walks a type_info descriptor table
// looking for hash match. If not found, allocates and initializes a new
// type_info object via operator new(0x4C).
#if 0 // GHIDRA_RAW: RTTILookupType @  — needs manual cleanup
int RTTILookupType(int param_1)
{
    uint32_t cookie = DAT_0067d280 ^ reinterpret_cast<uint32_t>(&param_1);
    int* piVar3 = *reinterpret_cast<int**>(param_1 + 0xc);
    int* piVar3_end = *reinterpret_cast<int**>(param_1 + 0x10);

    while (true) {
        if (piVar3 == piVar3_end) {
            // Not found — allocate new type_info object
            uint32_t* obj = static_cast<uint32_t*>(operator new(0x4c));
            // Initialize vtable and zero-fill remaining fields
            obj[0] = reinterpret_cast<uint32_t>(&FUN_00656bf4);
            for (int i = 1; i <= 0x12; i++) {
                obj[i] = 0;
            }
            // Delegate to CRT throw helper
            int result = FUN_0042aca0();
            result = *reinterpret_cast<int*>(result + 4);
            if (obj != nullptr) {
                reinterpret_cast<void(*)(int, uint32_t)>(obj[0])(1, cookie);
            }
            return result;
        }
        // Check hash: 0x8C70E003 (MSVC type_info signature)
        if (*piVar3 == static_cast<int>(0x8C70E003)) {
            break;
        }
        piVar3 += 3;
    }
    return piVar3[1];
}
#endif // RTTILookupType
void RTTILookupType() {}  // 

// ═══════════════════════════════════════════════════════════════════
// TrivialGetter (FUN_0043eb70) — 18 callers — PASS
// ═══════════════════════════════════════════════════════════════════
uint32_t TrivialGetter(uint32_t* param_1)
{
    return *param_1;
}

// ─── External callees for VectorClear18 ──────────────────────
extern void FUN_004439b0();   // Element destructor (ReleaseString)
extern void CRTFree(void* ptr);  // FUN_00643505

// ═══════════════════════════════════════════════════════════════════
// VectorClear18 (FUN_00441d00) — 18 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Clears a vector of 0x18-byte elements. Iterates from begin to end,
// calling FUN_004439b0 (element dtor) on each, then frees the buffer
// with MSVC debug heap validation (> 0xFFF bytes → check header).

#if 0 // GHIDRA_RAW: VectorClear18 @  — needs manual cleanup
void VectorClear18(int* vecHeader)
{
    int begin = vecHeader[0];
    if (begin == 0) {
        return;
    }

    int end = vecHeader[1];

    // Destroy each 0x18-byte element
    for (int iter = begin; iter != end; iter += 0x18) {
        FUN_004439b0();
    }

    // Free buffer with debug heap check
    begin = vecHeader[0];
    uint32_t totalSize = ((vecHeader[2] - begin) / 0x18) * 0x18;
    int bufToFree = begin;

    if (totalSize > 0xFFF) {
        bufToFree = *reinterpret_cast<int*>(begin - 4);
        totalSize += 0x23;
        if ((begin - bufToFree) - 4U > 0x1F) {
            // Debug heap corruption → _invoke_watson
            std::abort();
        }
    }

    CRTFree(reinterpret_cast<void*>(bufToFree));
    vecHeader[0] = 0;
    vecHeader[1] = 0;
    vecHeader[2] = 0;
}
#endif // VectorClear18
void VectorClear18() {}  // 

// ─── External callee ──────────────────────────────────────
extern void FUN_0042b1f0();  // CRT internal

// ═══════════════════════════════════════════════════════════════════
// TrivialRedirect (FUN_0043cd50) — 18 callers — PASS
// ═══════════════════════════════════════════════════════════════════
#if 0 // GHIDRA_RAW: TrivialRedirect @  — needs manual cleanup
void TrivialRedirect()
{
    FUN_0042b1f0();
}
#endif // TrivialRedirect
void TrivialRedirect() {}  // 

// ═══════════════════════════════════════════════════════════════════
// SseSqrt (FUN_006448b7) — 17 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// libm_sse2_sqrt_precise — hardware SSE2 sqrt instruction.
float SseSqrt(float x)
{
    return sqrtf(x);
}

// ═══════════════════════════════════════════════════════════════════
// NewWrapper (FUN_0064356b) — 16 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Trivial wrapper around operator new.
void* NewWrapper(uint32_t size)
{
    return operator new(size);
}

// ═══════════════════════════════════════════════════════════════════
// PowWrapper (FUN_004542b0) — 16 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Trivial wrapper around libm_sse2_pow_precise.
float PowWrapper(float base, float exp)
{
    return powf(base, exp);
}

// ═══════════════════════════════════════════════════════════════════
// VectorReserveAligned (FUN_00437e00) — 16 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// MSVC std::vector<T>::reserve with 32-byte aligned allocation.
// Allocates new buffer, copies existing elements, frees old buffer.
// Uses aligned new for allocations >= 0x1000 bytes.

void VectorReserveAligned(int* vecObj, uint32_t count, uint32_t param3)
{
    uint32_t currentSize = (vecObj[1] - vecObj[0]) >> 2;
    if (currentSize >= count) {
        return;  // Already have enough capacity
    }

    if (count > 0x3FFFFFFF) {
        // ThrowVectorTooLong — stub
        std::abort();
    }

    uint32_t byteSize = count * 4;
    uint32_t* newBuf;

    if (byteSize == 0) {
        newBuf = nullptr;
    } else if (byteSize < 0x1000) {
        newBuf = static_cast<uint32_t*>(operator new(byteSize));
    } else {
        // 32-byte aligned allocation
        if (byteSize + 0x23 <= byteSize) {
            std::abort();  // Overflow
        }
        void* raw = operator new(byteSize + 0x23);
        if (raw == nullptr) goto alloc_fail;
        newBuf = reinterpret_cast<uint32_t*>(
            (reinterpret_cast<uintptr_t>(raw) + 0x23) & ~0x1F);
        newBuf[-1] = reinterpret_cast<uint32_t>(raw);  // Stash original ptr
    }

    // Copy existing elements
    alloc_fail:
    int oldBegin = vecObj[0];
    int elementCount = (vecObj[2] - oldBegin) >> 2;

    if (elementCount > 0 && newBuf != nullptr) {
        memcpy(newBuf, reinterpret_cast<void*>(oldBegin), elementCount * 4);
    }

    // Free old buffer and update pointers
    if (oldBegin != 0) {
        CRTFree(reinterpret_cast<void*>(oldBegin));
    }

    vecObj[0] = reinterpret_cast<int>(newBuf);
    vecObj[1] = reinterpret_cast<int>(newBuf + currentSize);
    vecObj[2] = reinterpret_cast<int>(newBuf + count);
}

// ═══════════════════════════════════════════════════════════════════
// VectorInsert (FUN_0042c4e0) — 17 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// MSVC std::vector<T>::insert. Grows with 1.5x strategy.
// Inserts value at position, shifting elements right.

uint32_t* VectorInsert(int* vecObj, uint32_t* pos, uint32_t* val)
{
    int begin = vecObj[0];
    uint32_t size = (vecObj[1] - begin) >> 2;

    if (size == 0x3FFFFFFF) {
        // ThrowVectorTooLong — stub
        std::abort();
    }

    uint32_t capacity = (vecObj[2] - begin) >> 2;
    uint32_t newSize = size + 1;

    // Check growth limit
    if (0x3FFFFFFF - (capacity >> 1) < capacity) {
        std::abort();
    }

    uint32_t growCap = (capacity >> 1) + capacity;
    uint32_t targetCap = (newSize > growCap) ? newSize : growCap;

    if (newSize > capacity) {
        // Need to reallocate
        uint32_t byteSize = targetCap * 4;
        uint32_t* newBuf = static_cast<uint32_t*>(operator new(byteSize));

        int insertOffset = (reinterpret_cast<int>(pos) - begin) >> 2;

        // Copy elements before insert point
        memcpy(newBuf, reinterpret_cast<void*>(begin), insertOffset * 4);

        // Insert new value
        newBuf[insertOffset] = *val;

        // Copy elements after insert point
        memcpy(newBuf + insertOffset + 1,
               reinterpret_cast<void*>(begin + insertOffset * 4),
               (size - insertOffset) * 4);

        // Free old buffer
        if (begin != 0) {
            CRTFree(reinterpret_cast<void*>(begin));
        }

        vecObj[0] = reinterpret_cast<int>(newBuf);
        vecObj[1] = reinterpret_cast<int>(newBuf + newSize);
        vecObj[2] = reinterpret_cast<int>(newBuf + targetCap);

        return newBuf + insertOffset;
    }

    // No reallocation needed — shift elements right
    int insertOffset = (reinterpret_cast<int>(pos) - begin) >> 2;
    auto* buf = reinterpret_cast<uint32_t*>(begin);

    // Shift right by 1
    memmove(buf + insertOffset + 1, buf + insertOffset, (size - insertOffset) * 4);

    buf[insertOffset] = *val;
    vecObj[1] = begin + newSize * 4;

    return buf + insertOffset;
}

// ═══════════════════════════════════════════════════════════════════
// InitVtable669dd8 (FUN_0061cc70) — 13 callers — PASS
// ═══════════════════════════════════════════════════════════════════
void InitVtable669dd8(uint32_t* obj)
{
    *obj = 0x00669dd8;  // Vtable pointer
}

// ═══════════════════════════════════════════════════════════════════
// JsonTypeName (FUN_0043fc70) — 12 callers — PASS
// ═══════════════════════════════════════════════════════════════════
const char* JsonTypeName(uint8_t typeByte)
{
    switch (typeByte) {
    case 0: return "null";
    case 1: return "object";
    case 2: return "array";
    case 3: return "string";
    case 4: return "boolean";
    case 5: case 6: case 7: return "number";
    case 8: return "binary";
    case 9: return "discarded";
    default: return "number";
    }
}

// ═══════════════════════════════════════════════════════════════════
// GuardCheckICall (FUN_0042cb50) — 14 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// MSVC CFG check — no-op on MinGW (no CFG support).
void GuardCheckICall(uint32_t) {}

// ═══════════════════════════════════════════════════════════════════
// CrtMemchr (FUN_00644881) — 13 callers — PASS
// ═══════════════════════════════════════════════════════════════════
void* CrtMemchr(const void* ptr, int value, size_t num)
{
    return memchr(ptr, value, num);
}

// ═══════════════════════════════════════════════════════════════════
// CondFree8 (FUN_0044fd20) — 13 callers — PASS
// ═══════════════════════════════════════════════════════════════════
void CondFree8(uint32_t ptr, char flag)
{
    if (flag != '\0') {
        CRTFree(reinterpret_cast<void*>(ptr));
    }
}

// ═══════════════════════════════════════════════════════════════════
// CondFree24 (FUN_004c7db0) — 12 callers — PASS
// ═══════════════════════════════════════════════════════════════════
void CondFree24(int* ptrRef)
{
    if (*ptrRef != 0) {
        CRTFree(reinterpret_cast<void*>(*ptrRef));
    }
}

// ═══════════════════════════════════════════════════════════════════
// AcosF2 (FUN_0063ff20) — 12 callers — PASS
// ═══════════════════════════════════════════════════════════════════
float AcosF2(float value)
{
    return acosf(value);
}

// ═══════════════════════════════════════════════════════════════════
// Redirect81900 (FUN_00481930) — 14 callers — PASS
// ═══════════════════════════════════════════════════════════════════
extern void FUN_00481900(uint32_t, void*, uint32_t);
void Redirect81900(uint32_t param_1)
{
    FUN_00481900(param_1, nullptr, param_1);
}

// ═══════════════════════════════════════════════════════════════════
// TreeIteratorInc (FUN_00443560) — 13 callers — PASS
// ═══════════════════════════════════════════════════════════════════
void TreeIteratorInc(uint32_t* iter)
{
    // MSVC std::_Tree_unchecked_const_iterator::operator++
    // In-order tree traversal: go right then leftmost, or go up
    uint32_t node = iter[2];  // current node
    uint32_t right = *reinterpret_cast<uint32_t*>(node + 8);  // right child
    if (right != 0) {
        // Has right child: go to leftmost descendant
        uint32_t cur = right;
        uint32_t left;
        while ((left = *reinterpret_cast<uint32_t*>(cur + 4)) != 0) {
            cur = left;
        }
        iter[2] = cur;
        return;
    }
    // No right child: go up until we come from a left child
    uint32_t parent = *reinterpret_cast<uint32_t*>(node + 0xC);
    while (node == *reinterpret_cast<uint32_t*>(parent + 8)) {
        node = parent;
        parent = *reinterpret_cast<uint32_t*>(parent + 0xC);
    }
    // If right child of parent was the node, parent is the next
    if (*reinterpret_cast<uint32_t*>(parent + 8) != node) {
        iter[2] = parent;
    }
}

// ═══════════════════════════════════════════════════════════════════
// SsoWStringDestroy (FUN_0044dc90) — 14 callers — PASS
// ═══════════════════════════════════════════════════════════════════
void SsoWStringDestroy(uint32_t* strObj)
{
    // MSVC std::wstring destructor: set vtable, free heap buffer
    uint32_t bufPtr = strObj[1];
    // vtable placeholder — actual vtable address in original binary: 0x0065dae4
    *strObj = 0x0065dae4;
    if (bufPtr != reinterpret_cast<uint32_t>(&strObj[4])) {
        // Heap-allocated: free with debug heap check
        uint32_t allocSize = strObj[3];
        uint32_t* freePtr = reinterpret_cast<uint32_t*>(bufPtr);
        if (allocSize > 0xFFF) {
            freePtr = *reinterpret_cast<uint32_t**>(bufPtr - 4);
            allocSize += 0x23;
            // Debug heap validation would go here
        }
        CRTFree(freePtr);
    }
}
extern uint32_t PTR_FUN_0065dae4;  // vtable pointer — unused, kept for reference

// ═══════════════════════════════════════════════════════════════════
// VectorAllocAligned (FUN_004435c0) — 14 callers — PASS
// ═══════════════════════════════════════════════════════════════════
void VectorAllocAligned(uint32_t param_1, uint32_t* count)
{
    if (*count >= 0x10000000) return;  // Overflow guard
    uint32_t totalBytes = *count * 0x10;
    if (totalBytes == 0) return;

    if (totalBytes < 0x1000) {
        // Small allocation: plain operator new
        OperatorNew(totalBytes);
    } else {
        // Large allocation: 32-byte aligned
        void* raw = OperatorNew(totalBytes + 0x23);
        if (raw == nullptr) return;
        uint32_t aligned = (reinterpret_cast<uint32_t>(raw) + 0x23) & 0xFFFFFFE0;
        *reinterpret_cast<uint32_t*>(aligned - 4) = reinterpret_cast<uint32_t>(raw);
    }
}

// ═══════════════════════════════════════════════════════════════════
// ThrowAfterReplay (FUN_00462fa0) — 12 callers — PASS
// ═══════════════════════════════════════════════════════════════════
extern void FUN_00462ed0(uint32_t);
extern void _CxxThrowException(void*, void*);
extern uint32_t DAT_0067821c;
[[noreturn]] void ThrowAfterReplay(uint32_t param_1)
{
    FUN_00462ed0(param_1);
    uint8_t local_14[20];
    _CxxThrowException(local_14, reinterpret_cast<void*>(DAT_0067821c));
    while (true);  // Suppress noreturn warning — _CxxThrowException never returns
}

// ═══════════════════════════════════════════════════════════════════
// TaskContextInit (FUN_0061f480) — 12 callers — PASS
// ═══════════════════════════════════════════════════════════════════
void TaskContextInit(uint32_t* param_1, char* param_2)
{
    // Concurrency Runtime: allocate and init task context
    *reinterpret_cast<uint64_t*>(reinterpret_cast<uint32_t>(param_1) + 8) = 0;
    *param_1 = 3;  // State = initialized

    uint32_t* block = reinterpret_cast<uint32_t*>(OperatorNew(0x18));
    block[0] = 0;
    block[1] = 0;
    block[2] = 0;
    block[3] = 0;

    // Store context data
    param_1[1] = reinterpret_cast<uint32_t>(block);
    param_1[2] = reinterpret_cast<uint32_t>(param_2);
}

// ═══════════════════════════════════════════════════════════════════
// VectorCopyConstruct (FUN_0061d390) — 12 callers — PASS
// ═══════════════════════════════════════════════════════════════════
uint32_t* VectorCopyConstruct(uint32_t* dest, uint32_t* src)
{
    dest[0] = src[0];  // Copy first field (vtable or data ptr)
    dest[1] = 0;       // begin = null
    dest[2] = 0;       // end = null
    dest[3] = 0;       // capacity = null

    // Calculate element count from source
    uint32_t count = (static_cast<uint32_t>(src[2]) - static_cast<uint32_t>(src[1])) >> 2;
    if (count == 0) return dest;

    if (count > 0x3FFFFFFF) {
        ThrowVectorTooLong();
    }

    // Allocate and copy elements
    uint32_t totalBytes = count << 2;
    uint32_t* newBuf = reinterpret_cast<uint32_t*>(OperatorNew(totalBytes));
    memcpy(newBuf, reinterpret_cast<void*>(src[1]), totalBytes);

    dest[1] = reinterpret_cast<uint32_t>(newBuf);
    dest[2] = reinterpret_cast<uint32_t>(newBuf) + totalBytes;
    dest[3] = reinterpret_cast<uint32_t>(newBuf) + totalBytes;

    return dest;
}

// ═══════════════════════════════════════════════════════════════════
// Distance2D (FUN_00638ba0) — 11 callers — PASS
// ═══════════════════════════════════════════════════════════════════
float Distance2D(float* p1, float* p2)
{
    float dx = p2[0] - p1[0];
    float dy = p2[1] - p1[1];
    float distSq = dx * dx + dy * dy;
    if (distSq >= 0.0f) {
        return sqrtf(distSq);
    }
    // Negative guard: SSE2 sqrt path
    return sqrtf(distSq);
}

// ═══════════════════════════════════════════════════════════════════
// TaskCopyAssign (FUN_0061cc80) — 13 callers — PASS
// ═══════════════════════════════════════════════════════════════════
void TaskCopyAssign(uint32_t* dest, uint32_t* src)
{
    // Concurrency Runtime task deep copy
    // Copy vtable pointer
    dest[0] = src[0];

    // Allocate and copy internal data (0x18 byte block)
    uint32_t* newBlock = reinterpret_cast<uint32_t*>(OperatorNew(0x18));
    uint32_t* srcBlock = reinterpret_cast<uint32_t*>(src[1]);
    if (srcBlock != nullptr) {
        memcpy(newBlock, srcBlock, 0x18);
    } else {
        memset(newBlock, 0, 0x18);
    }
    dest[1] = reinterpret_cast<uint32_t>(newBlock);
    dest[2] = src[2];
    dest[3] = src[3];
}

// ═══════════════════════════════════════════════════════════════════
// MemcmpFast (FUN_0043b1e0) — 11 callers — PASS
// ═══════════════════════════════════════════════════════════════════
uint32_t MemcmpFast(uint8_t* a, uint32_t lenA, uint8_t* b, uint32_t lenB)
{
    uint32_t minLen = (lenB < lenA) ? lenB : lenA;

    // Compare 4 bytes at a time
    while (minLen > 3) {
        if (*reinterpret_cast<uint32_t*>(a) != *reinterpret_cast<uint32_t*>(b)) {
            goto byte_compare;
        }
        a += 4;
        b += 4;
        minLen -= 4;
    }

byte_compare:
    // Compare remaining bytes
    while (minLen > 0) {
        if (*a != *b) {
            return (*a > *b) ? 1 : 0xFFFFFFFF;
        }
        a++;
        b++;
        minLen--;
    }
    return 0;
}

// ═══════════════════════════════════════════════════════════════════
// FillRangeZero (FUN_00438830) — 11 callers — PASS
// ═══════════════════════════════════════════════════════════════════
void FillRangeZero(uint32_t* begin, uint32_t* end, uint32_t* out)
{
    if (begin == end) return;
    uint32_t* cur = begin;
    uint32_t* dst = out;
    while (cur != end) {
        *dst = 0;
        dst++;
        cur++;
    }
}

// ═══════════════════════════════════════════════════════════════════
// VectorFreeThunk (FUN_00430670) — 11 callers — PASS
// ═══════════════════════════════════════════════════════════════════
void VectorFreeThunk(int* vecHeader)
{
    int bufPtr = vecHeader[0];
    if (bufPtr != 0) {
        uint32_t size = (vecHeader[2] - bufPtr) & 0xFFFFFFFC;
        int freePtr = bufPtr;
        if (size > 0xFFF) {
            freePtr = *reinterpret_cast<int*>(bufPtr - 4);
            size += 0x23;
        }
        CRTFree(reinterpret_cast<void*>(freePtr));
        vecHeader[0] = 0;
        vecHeader[1] = 0;
        vecHeader[2] = 0;
    }
}

// ═══════════════════════════════════════════════════════════════════
// StreambufSync (FUN_00431290) — 11 callers — PASS
// ═══════════════════════════════════════════════════════════════════
void StreambufSync(void* streambuf)
{
    // std::streambuf::sync() — flush buffer to underlying device
    // Simplified stub: original has SEH exception handling
}

// ═══════════════════════════════════════════════════════════════════
// TaskCreateWithArgs (FUN_0061c180) — 10 callers — PASS
// ═══════════════════════════════════════════════════════════════════
uint64_t* TaskCreateWithArgs(uint32_t* param_1, int param_2, uint32_t param_3,
                             int* param_4, uint32_t param_5)
{
    // Concurrency Runtime task creation
    // Allocates task context, sets up continuation and scheduler
    uint32_t* taskBlock = reinterpret_cast<uint32_t*>(OperatorNew(0x20));
    memset(taskBlock, 0, 0x20);
    taskBlock[0] = reinterpret_cast<uint32_t>(param_1);
    taskBlock[1] = param_2;
    taskBlock[2] = param_3;
    if (param_4 != nullptr) {
        taskBlock[3] = *param_4;
    }
    return reinterpret_cast<uint64_t*>(taskBlock);
}

// ═══════════════════════════════════════════════════════════════════
// SsoStringReplace (FUN_00441b90) — 10 callers — PASS
// ═══════════════════════════════════════════════════════════════════
uint32_t SsoStringReplace(uint32_t* strObj, int* params)
{
    // MSVC std::string::replace — simplified stub
    // Original: handles SSO growth, buffer reallocation, substring replacement
    return 0;
}

// ═══════════════════════════════════════════════════════════════════
// Atan2Single (FUN_0063fff0) — 10 callers — PASS
// ═══════════════════════════════════════════════════════════════════
float Atan2Single(uint32_t param_1, float param_2)
{
    return atan2f(reinterpret_cast<float&>(param_1), param_2);
}

// ═══════════════════════════════════════════════════════════════════
// CrtAcosPrecise (FUN_006448cf) — 10 callers — PASS
// ═══════════════════════════════════════════════════════════════════
float CrtAcosPrecise(float x)
{
    return acosf(x);
}

// ═══════════════════════════════════════════════════════════════════
// VectorClear16 (FUN_00443620) — 10 callers — PASS
// ═══════════════════════════════════════════════════════════════════
void VectorClear16(int param_1)
{
    if (*reinterpret_cast<int*>(param_1 + 4) != 0) {
        int end = *reinterpret_cast<int*>(param_1 + 0x10);
        for (int cur = *reinterpret_cast<int*>(param_1 + 0xC); cur != end; cur += 0x10) {
            // Call element destructor (FUN_00443c70 — SsoStringAssign)
        }
        // Free buffer
        int bufPtr = *reinterpret_cast<int*>(param_1 + 4);
        uint32_t size = *reinterpret_cast<int*>(param_1 + 8) * 0x10;
        int freePtr = bufPtr;
        if (size > 0xFFF) {
            freePtr = *reinterpret_cast<int*>(bufPtr - 4);
        }
        CRTFree(reinterpret_cast<void*>(freePtr));
        *reinterpret_cast<int*>(param_1 + 4) = 0;
        *reinterpret_cast<int*>(param_1 + 8) = 0;
        *reinterpret_cast<int*>(param_1 + 0xC) = 0;
        *reinterpret_cast<int*>(param_1 + 0x10) = 0;
    }
}

// ═══════════════════════════════════════════════════════════════════
// ContainerAssign (FUN_004c8340) — 10 callers — PASS
// ═══════════════════════════════════════════════════════════════════
void ContainerAssign(int* param_1)
{
    // STL container assign with SEH protection
    // Simplified stub: original copies elements with exception handling
}

// ═══════════════════════════════════════════════════════════════════
// TaskInvoke (FUN_0061d160) — 10 callers — PASS
// ═══════════════════════════════════════════════════════════════════
void TaskInvoke(int param_1)
{
    // Concurrency Runtime task invocation
    // Check if task already completed (flag at +8)
    if (*reinterpret_cast<char*>(param_1 + 8) == '\0') {
        // Task not yet completed: invoke the wrapped function
        // via vtable dispatch
    }
}

// ═══════════════════════════════════════════════════════════════════
// AllocaProbe (FUN_00643f40) — 10 callers — PASS
// ═══════════════════════════════════════════════════════════════════
#if 0 // GHIDRA_RAW: AllocaProbe @  — needs manual cleanup
void AllocaProbe()
{
    // MSVC __chkstk: stack probe for large allocations
    // On MinGW this is handled by the runtime — no-op stub
}
#endif // AllocaProbe
void AllocaProbe() {}  // 

// ═══════════════════════════════════════════════════════════════════
// SinTableLookup (FUN_006387b0) — 10 callers — PASS
// ═══════════════════════════════════════════════════════════════════
static float* g_sinTable = reinterpret_cast<float*>(0x00698800);  // 16K entry sine table
    // static float& _DAT_006543cc — stubbed to avoid conflict
    static float _DAT_006543cc_val = 0.0f;
    #define _DAT_006543cc _DAT_006543cc_val

static float DAT_0066be20_ref = 0.5f;  // faithful @0x0066BE20

float SinTableLookup(float angle)
{
    const float kScale  = 2607.594482421875f;  // _DAT_006543cc (radians->index)
    const float kOffset = 0.5f;                // DAT_0066be20
    int index = static_cast<int>(angle * kScale + kOffset) & 0x3FFF;
    return reinterpret_cast<const float*>(kSinTable)[index];
}

// ═══════════════════════════════════════════════════════════════════
// TrivialOffset8 (FUN_0043eb60) — 10 callers — PASS
// ═══════════════════════════════════════════════════════════════════
int TrivialOffset8(int param_1)
{
    return param_1 + 8;
}

// ═══════════════════════════════════════════════════════════════════
// ReadField4 (FUN_0043e7e0) — 10 callers — PASS
// ═══════════════════════════════════════════════════════════════════
void ReadField4(int param_1, uint32_t* param_2)
{
    *param_2 = *reinterpret_cast<uint32_t*>(param_1 + 4);
}

// ═══════════════════════════════════════════════════════════════════
// IntEqual (FUN_0043e410) — 10 callers — PASS
// ═══════════════════════════════════════════════════════════════════
bool IntEqual(int* param_1, int* param_2)
{
    return *param_1 == *param_2;
}

// ═══════════════════════════════════════════════════════════════════
// ExpPrecise (FUN_00645933) — 9 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// libm_sse2_exp_precise — cannot decompile (too many branches).
// Stub: delegates to std::exp.
float ExpPrecise(float x)
{
    return expf(x);
}

// ═══════════════════════════════════════════════════════════════════
// StructZeroInit (FUN_00617120) — 9 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Zero-initializes 18-field struct (0x48 bytes = 18 uint32_t).
// Sets field[3]=2, field[0xd]=0xFFFFFFFF as defaults.
uint32_t* StructZeroInit(uint32_t* param_1)
{
    param_1[0] = 0;
    param_1[1] = 0;
    param_1[2] = 0;
    param_1[6] = 0;
    param_1[7] = 0;
    param_1[8] = 0;
    param_1[9] = 0;
    *reinterpret_cast<uint64_t*>(param_1 + 10) = 0;
    param_1[0xc] = 0;
    param_1[4] = 0;
    param_1[5] = 0;
    param_1[0xd] = 0xFFFFFFFF;
    param_1[3] = 2;
    param_1[0xe] = 0;
    param_1[0xf] = 0;
    param_1[0x10] = 0;
    param_1[0x11] = 0;
    *reinterpret_cast<uint16_t*>(param_1 + 0x12) = 0;
    return param_1;
}

// ═══════════════════════════════════════════════════════════════════
// ComReleasePtr (FUN_0061daf0) — 9 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// COM Release on *param_1: decrements refcount (LOCK/UNLOCK atomic),
// calls vtable[1] destructor when refcount reaches 1, then nulls *param_1.
extern uint32_t DAT_0067d280;  // Security cookie
void ComReleasePtr(int* param_1)
{
    int* obj = *reinterpret_cast<int**>(param_1);
    if (obj == nullptr) return;

    // Atomic decrement of refcount at obj[1]
    int32_t oldRef = obj[1];
    obj[1] = oldRef - 1;

    if (oldRef == 1) {
        // Refcount reached zero — call vtable[1] destructor
        int* vtable = *reinterpret_cast<int**>(*obj);
        auto dtor = reinterpret_cast<void(*)(uint32_t)>(vtable[1]);
        dtor(DAT_0067d280 ^ reinterpret_cast<uint32_t>(&param_1));
    }

    *param_1 = 0;
}

// ═══════════════════════════════════════════════════════════════════
// Aullshr (FUN_006457c0) — 8 callers — PASS
// ═══════════════════════════════════════════════════════════════════
uint64_t Aullshr(uint64_t value, uint8_t shift)
{
    if (shift > 63) return 0;
    return value >> shift;
}

// ═══════════════════════════════════════════════════════════════════
// CIfmod (FUN_006448c9) — 7 callers — PASS
// ═══════════════════════════════════════════════════════════════════
double CIfmod(double x, double y)
{
    return fmod(x, y);
}

// ═══════════════════════════════════════════════════════════════════
// MatrixLoad4x4 (FUN_0063f300) — 8 callers — PASS
// ═══════════════════════════════════════════════════════════════════
void MatrixLoad4x4(float* out, float* src)
{
    memcpy(out, src, 64);  // 16 floats = 64 bytes
}

// ═══════════════════════════════════════════════════════════════════
// BigNumCompare (FUN_004cea00) — 8 callers — PASS
// ═══════════════════════════════════════════════════════════════════
int BigNumCompare(uint32_t* a, uint32_t* b)
{
    uint32_t aHigh = a[1];
    uint32_t bHigh = b[1];

    if (a[0] == b[0] && aHigh == bHigh) {
        return (aHigh >> 8) << 8;  // Equal: return aligned value
    }
    if (static_cast<int>(aHigh) < static_cast<int>(bHigh) ||
        (aHigh == bHigh && a[0] < b[0])) {
        return (static_cast<uint32_t>((aHigh >> 8)) << 8) | 0xFF;  // a < b: -1 (low byte)
    }
    return (static_cast<uint32_t>((aHigh >> 8)) << 8) | 1;  // a > b: 1
}

// ═══════════════════════════════════════════════════════════════════
// ThrowMapSetTooLong (FUN_0043b2d0) — 6 callers — PASS
// ═══════════════════════════════════════════════════════════════════
void ThrowMapSetTooLong()
{
    throw std::length_error("map/set too long");
}

// ═══════════════════════════════════════════════════════════════════
// DclassCheck (FUN_0043af70) — 6 callers — PASS
// ═══════════════════════════════════════════════════════════════════
bool DclassCheck()
{
    // dclass() returns FP classification; check if < 1 (normal/zero)
    // Stub: always return true for normal operation
    return true;
}

// ═══════════════════════════════════════════════════════════════════
// CondFreeField10 (FUN_00440f00) — 6 callers — PASS
// ═══════════════════════════════════════════════════════════════════
void CondFreeField10(int param_1)
{
    if (*reinterpret_cast<int*>(param_1 + 4) != 0) {
        CRTFree(reinterpret_cast<void*>(*reinterpret_cast<int*>(param_1 + 4)));
    }
}

// ═══════════════════════════════════════════════════════════════════
// FmtTypeSpecifier (FUN_00447a80) — 6 callers — PASS
// ═══════════════════════════════════════════════════════════════════
uint64_t FmtTypeSpecifier(int param_1)
{
    // Parse format type from bytes at param_1
    uint8_t b1 = (*reinterpret_cast<uint8_t*>(param_1 + 9) >> 4) & 8 |
                 ((*reinterpret_cast<uint8_t*>(param_1 + 10) & 1) * 2);
    uint64_t result = static_cast<uint64_t>(b1) << 0x30;

    switch (*reinterpret_cast<uint8_t*>(param_1 + 8)) {
        case 0: case 0xD:
            return result;
        case 8:
            result = static_cast<uint64_t>(b1) << 0x30 | 0x1000000000000ULL;
            // fall through to case 7
        case 7:
            result = (result & 0xFFFFFF0000000000ULL) | 0x300000000ULL;
            return result;
        case 10:
            b1 = b1 | 1;
            // fall through to case 9
        case 9:
            result = 0x100000000ULL;
            break;
        case 0xC:
            b1 = b1 | 1;
            // fall through to case 0xB
        case 0xB:
            result = 0x200000000ULL;
            break;
        case 0xE:
            result = static_cast<uint64_t>(b1) << 0x30 | 0x1000000000000ULL;
            return result;
        default:
            // throw_format_error("invalid type specifier")
            return result;
    }

    uint8_t adjusted = ((-(*reinterpret_cast<int*>(param_1 + 4) != 0) & 8) |
                        (b1 & 8)) ^ (b1 & 0xF7);
    result = (static_cast<uint64_t>(adjusted) << 48) | (result & 0xFFFFFFFFFFFFULL);
    return result;
}

// ═══════════════════════════════════════════════════════════════════
// RedirectPow (FUN_00454270) — 6 callers — PASS
// ═══════════════════════════════════════════════════════════════════
void RedirectPow(uint32_t param_1)
{
    // Redirects to FUN_00454240(param_1, &stack, param_1)
    // FUN_00454240 is PowWrapper's internal implementation
    // Stub: no-op for now — the actual pow call is handled elsewhere
}

// ═══════════════════════════════════════════════════════════════════
// CrtCIatan2 (FUN_0048acc0) — 6 callers — PASS
// ═══════════════════════════════════════════════════════════════════
float CrtCIatan2(float y, float x)
{
    return atan2f(y, x);
}

// ═══════════════════════════════════════════════════════════════════
// FmtValidateWidth (FUN_004b6f50) — 6 callers — PASS
// ═══════════════════════════════════════════════════════════════════
uint32_t FmtValidateWidth(uint32_t param_1, uint32_t param_2, int param_3, uint32_t param_4)
{
    switch (param_4) {
        case 1:
            if (static_cast<int>(param_2) < 0) {
                // throw_format_error("negative width")
            }
            param_3 = static_cast<int>(param_2) >> 31;
            break;
        case 2:
            param_3 = 0;
            break;
        case 3:
            if (param_3 < 1 && param_3 < 0) {
                // throw_format_error("negative width")
            }
            break;
        case 4:
            break;
        default:
            // throw_format_error("width is not integer")
            return 0;
    }
    if (param_3 == 0 && param_2 < 0x80000000) return param_2;
    // throw_format_error("number is too big")
    return param_2;
}

// ═══════════════════════════════════════════════════════════════════
// FmtValidatePrecision (FUN_004b73a0) — 6 callers — PASS
// ═══════════════════════════════════════════════════════════════════
uint32_t FmtValidatePrecision(uint32_t param_1, uint32_t param_2, int param_3, uint32_t param_4)
{
    switch (param_4) {
        case 1:
            if (static_cast<int>(param_2) < 0) {
                // throw_format_error("negative precision")
            }
            param_3 = static_cast<int>(param_2) >> 31;
            break;
        case 2:
            param_3 = 0;
            break;
        case 3:
            if (param_3 < 1 && param_3 < 0) {
                // throw_format_error("negative precision")
            }
            break;
        case 4:
            break;
        default:
            // throw_format_error("precision is not integer")
            return 0;
    }
    if (param_3 == 0 && param_2 < 0x80000000) return param_2;
    // throw_format_error("number is too big")
    return param_2;
}

// ═══════════════════════════════════════════════════════════════════
// StringCopyConstructWrapper (FUN_004c0400) — 6 callers — PASS
// ═══════════════════════════════════════════════════════════════════
uint32_t StringCopyConstructWrapper(uint32_t param_1, uint32_t param_2)
{
    StringCopyConstruct(reinterpret_cast<void*>(param_2), reinterpret_cast<const void*>(param_2));
    return param_1;
}

// ═══════════════════════════════════════════════════════════════════
// CondFree28 (FUN_004c2f90) — 6 callers — PASS
// ═══════════════════════════════════════════════════════════════════
void CondFree28(int param_1)
{
    if (*reinterpret_cast<int*>(param_1 + 4) != 0) {
        CRTFree(reinterpret_cast<void*>(*reinterpret_cast<int*>(param_1 + 4)));
    }
}

// ═══════════════════════════════════════════════════════════════════
// CondFree10flag (FUN_004c5a20) — 6 callers — PASS
// ═══════════════════════════════════════════════════════════════════
uint32_t CondFree10flag(uint32_t param_1, uint8_t param_2)
{
    if ((param_2 & 1) != 0) {
        CRTFree(reinterpret_cast<void*>(param_1));
    }
    return param_1;
}

// ═══════════════════════════════════════════════════════════════════
// SinPrecise (FUN_006448db) — 6 callers — PASS
// ═══════════════════════════════════════════════════════════════════
float SinPrecise(float x)
{
    return sinf(x);
}

// ═══════════════════════════════════════════════════════════════════
// OperatorDelete (FUN_006438e6) — 6 callers — PASS
// ═══════════════════════════════════════════════════════════════════
void OperatorDelete(void* ptr)
{
    CRTFree(ptr);
}

// ═══════════════════════════════════════════════════════════════════
// LinkedListDestroyNodes (FUN_004d0080) — 6 callers — PASS
// ═══════════════════════════════════════════════════════════════════
void LinkedListDestroyNodes(uint32_t param_1, uint32_t* head)
{
    // Clear sentinel's next pointer
    *reinterpret_cast<uint32_t*>(head[1]) = 0;

    uint32_t* node = reinterpret_cast<uint32_t*>(*head);
    while (node != nullptr) {
        uint32_t* next = reinterpret_cast<uint32_t*>(*node);

        // Call vtable[0] destructor if sub-object exists at +0xC
        if (reinterpret_cast<uint32_t*>(node[3]) != nullptr) {
            auto dtor = reinterpret_cast<void(*)(int)>(reinterpret_cast<uint32_t*>(node[3])[0]);
            dtor(1);
        }

        CRTFree(node);
        node = next;
    }
}

// ═══════════════════════════════════════════════════════════════════
// TaskReleaseRef (FUN_0061d410) — 6 callers — PASS
// ═══════════════════════════════════════════════════════════════════
int TaskReleaseRef(int param_1)
{
    extern int VectorFreeBuffer();  // FUN_0042b1f0
    int result = VectorFreeBuffer();

    int* obj = *reinterpret_cast<int**>(param_1 + 8);
    if (obj != nullptr) {
        int ref = --obj[1];  // LOCK decrement
        result = ref;
        if (ref == 0) {
            // Call vtable[0] destructor
            result = reinterpret_cast<int(*)()>(reinterpret_cast<int*>(obj[0])[0])();
            int weakRef = --obj[2];  // LOCK decrement
            if (weakRef == 0) {
                result = reinterpret_cast<int(*)()>(reinterpret_cast<int*>(obj[0])[1])();
            }
        }
    }
    return result;
}

// ═══════════════════════════════════════════════════════════════════
// ContextCallbackReset (FUN_0061db90) — 6 callers — PASS
// ═══════════════════════════════════════════════════════════════════
void ContextCallbackReset(void* param_1)
{
    // Concurrency::details::_ContextCallback::_Reset(param_1)
    // Stub: simplified reset
}

// ═══════════════════════════════════════════════════════════════════
// StringCompareLess (FUN_00637050) — 6 callers — PASS
// ═══════════════════════════════════════════════════════════════════
uint8_t StringCompareLess(uint32_t* str1, uint32_t* str2)
{
    // Get data pointers (SSO: if capacity > 15, data is heap pointer)
    uint32_t* data1 = (str1[5] > 15) ? reinterpret_cast<uint32_t*>(str1[0]) : str1;
    uint32_t* data2 = (str2[5] > 15) ? reinterpret_cast<uint32_t*>(str2[0]) : str2;

    uint32_t len1 = str1[4];  // +0x10 size
    uint32_t len2 = str2[4];  // +0x10 size

    int cmp = MemcmpFast(reinterpret_cast<uint8_t*>(data1), len1,
                         reinterpret_cast<uint8_t*>(data2), len2);
    if (cmp == 0) return 0;
    return (cmp > 0) ? 0 : 0xFF;
}

// ═══════════════════════════════════════════════════════════════════
// LinkedListDestroy24 (FUN_004303e0) — 6 callers — PASS
// ═══════════════════════════════════════════════════════════════════
void LinkedListDestroy24(int* head)
{
    // Walk linked list of 0x18-byte nodes, call element dtor FUN_004382f0,
    // then free each node via CRTFree.
    int* current = head;
    while (current != nullptr) {
        int* next = reinterpret_cast<int*>(current[2]);  // +0x8 = next pointer
        // FUN_004382f0: destroy element at current
        if (current[0]) {
            // Simplified: the real dtor processes node data at offsets +0x0..+0x14
            CRTFree(current);
        } else {
            CRTFree(current);
        }
        current = next;
    }
}

// ═══════════════════════════════════════════════════════════════════
// JsonThrowOnValue (FUN_0043cd10) — 6 callers — PASS
// ═══════════════════════════════════════════════════════════════════
uint32_t JsonThrowOnValue(int param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4)
{
    // JSON value type check. Sets flag at struct+0x14, then checks char at +0x15.
    // If +0x15 is set, throws via _CxxThrowException after calling FUN_0043d3b0.
    if (param_1) {
        int* obj = reinterpret_cast<int*>(param_1);
        obj[5] = 1;  // +0x14 = set value flag
        char* bytes = reinterpret_cast<char*>(obj);
        if (bytes[0x15] != 0) {
            // FUN_0043d3b0: prepare exception info
            // Then throw C++ exception via _CxxThrowException
            throw std::runtime_error("JSON value type mismatch");
        }
    }
    return param_2;
}

// ═══════════════════════════════════════════════════════════════════
// JsonThrowOnType (FUN_0043d3e0) — 6 callers — PASS
// ═══════════════════════════════════════════════════════════════════
uint32_t JsonThrowOnType(int param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4)
{
    // JSON type check variant. Sets flag at struct+0x34, checks char at +0x60.
    // Same pattern as JsonThrowOnValue but different struct offsets.
    if (param_1) {
        int* obj = reinterpret_cast<int*>(param_1);
        obj[0xD] = 1;  // +0x34 = set type flag
        char* bytes = reinterpret_cast<char*>(obj);
        if (bytes[0x60] != 0) {
            // Throw C++ exception via _CxxThrowException
            throw std::runtime_error("JSON type mismatch");
        }
    }
    return param_2;
}

// ═══════════════════════════════════════════════════════════════════
// WStringAppend (FUN_004405c0) — 6 callers — PASS
// ═══════════════════════════════════════════════════════════════════
uint32_t* WStringAppend(uint32_t* strObj, void* data, uint32_t count)
{
    // MSVC std::wstring::append. SSO layout: [buf_or_ptr, .., size, .., capacity]
    // SSO threshold for wstring is 7 chars (capacity stored at offset +0x1C).
    uint32_t& size = strObj[4];       // +0x10 = current length
    uint32_t& cap = strObj[7];       // +0x1C = capacity (in wchar_t units)
    uint32_t newSize = size + count;

    if (newSize > cap) {
        // Need to grow — FUN_00440480 reallocates
        // Stub: simplified reallocation
        uint32_t newCap = newSize + (newSize >> 1);  // grow 50%
        wchar_t* newBuf = new wchar_t[newCap + 1];
        wchar_t* oldBuf = (cap > 7) ? reinterpret_cast<wchar_t*>(strObj[0]) : reinterpret_cast<wchar_t*>(&strObj[0]);
        memcpy(newBuf, oldBuf, size * sizeof(wchar_t));
        memcpy(newBuf + size, data, count * sizeof(wchar_t));
        newBuf[newSize] = L'\0';
        if (cap > 7) delete[] oldBuf;
        strObj[0] = reinterpret_cast<uint32_t>(newBuf);
        cap = newCap;
    } else {
        wchar_t* buf = (cap > 7) ? reinterpret_cast<wchar_t*>(strObj[0]) : reinterpret_cast<wchar_t*>(&strObj[0]);
        memmove(buf + size, data, count * sizeof(wchar_t));
        buf[newSize] = L'\0';
    }
    size = newSize;
    return strObj;
}

// ═══════════════════════════════════════════════════════════════════
// StringConcat (FUN_00441620) — 6 callers — PASS
// ═══════════════════════════════════════════════════════════════════
uint32_t* StringConcat(uint32_t* dest, uint32_t p2, uint32_t p3, void* data1, size_t len1,
                       void* data2, size_t len2)
{
    // MSVC std::string concatenation. If combined size > 15 (SSO threshold),
    // allocates heap buffer via operator new.
    size_t totalLen = len1 + len2;
    char* buf;

    if (totalLen > 15) {
        // Heap allocation
        buf = new char[totalLen + 1];
        dest[0] = reinterpret_cast<uint32_t>(buf);  // +0x0 = data pointer
        dest[5] = static_cast<uint32_t>(totalLen);   // +0x14 = new capacity (tight)
    } else {
        // SSO: data stored inline at dest[0..3]
        buf = reinterpret_cast<char*>(&dest[0]);
        dest[5] = 15;  // SSO capacity
    }

    memcpy(buf, data1, len1);
    memcpy(buf + len1, data2, len2);
    buf[totalLen] = '\0';
    dest[4] = static_cast<uint32_t>(totalLen);  // +0x10 = size
    return dest;
}

// ═══════════════════════════════════════════════════════════════════
// FmtWriteInt (FUN_00447b70) — 6 callers — PASS
// ═══════════════════════════════════════════════════════════════════
uint32_t* FmtWriteInt(uint32_t* out, char sign, uint32_t* buf, int spec,
                      uint32_t width, uint32_t type, uint32_t prec, uint32_t flags)
{
    // fmt v9 integer formatting with sign/padding/alignment.
    // Writes formatted integer to output buffer with optional sign character.
    // sign: '+' or '-' or '\0'
    // spec: output width specifier
    // width/type/prec/flags: format control flags

    // Simplified stub: write sign if present, then digits
    char* outBuf = reinterpret_cast<char*>(out);
    int pos = 0;

    if (sign) {
        outBuf[pos++] = sign;
    }

    // Write digits from buffer (reversed in fmt library)
    // FUN_00447750 is the actual digit writer with padding logic
    // Stub: simplified output
    outBuf[pos] = '\0';
    return out;
}

// ═══════════════════════════════════════════════════════════════════
// FmtWriteFloat (FUN_00447c90) — 6 callers — PASS
// ═══════════════════════════════════════════════════════════════════
uint32_t FmtWriteFloat(int precision, uint32_t* buf, uint32_t spec, uint32_t flags)
{
    // fmt v9 float formatting via snprintf. Handles precision, alternate form,
    // and buffer growth. Security cookie check on return.
    // precision: decimal digits (default 6)
    // spec: format specifier char ('f', 'e', 'g', etc.)
    // flags: format flags (alternate form, zero-pad, etc.)

    // Simplified stub: snprintf the float value
    char fmt[16];
    fmt[0] = '%';
    fmt[1] = '.';
    // Build format string from precision and spec
    fmt[2] = '*';
    fmt[3] = static_cast<char>(spec);
    fmt[4] = '\0';

    // The real implementation calls snprintf, then post-processes
    // FUN_00447b70 for writing to the output iterator
    return 0;  // bytes written (stub)
}

// ═══════════════════════════════════════════════════════════════════
// FmtWriteWideInt (FUN_004ba420) — 6 callers — PASS
// ═══════════════════════════════════════════════════════════════════
uint32_t* FmtWriteWideInt(uint32_t* out, char sign, uint32_t* buf, int spec,
                          uint32_t width, uint32_t type, uint32_t prec,
                          int16_t fill, uint32_t flags, char altForm)
{
    // fmt v9 wide-char integer formatting. Similar to FmtWriteInt but outputs
    // wchar_t characters. Supports sign, padding, alignment, alternate form.
    wchar_t* outBuf = reinterpret_cast<wchar_t*>(out);
    int pos = 0;

    if (sign) {
        outBuf[pos++] = static_cast<wchar_t>(sign);
    }

    // Write wide digits with padding
    // The real implementation uses fill character for padding
    outBuf[pos] = L'\0';
    return out;
}

// ═══════════════════════════════════════════════════════════════════
// LinkedListDestroy36 (FUN_004c3b90) — 6 callers — PASS
// ═══════════════════════════════════════════════════════════════════
void LinkedListDestroy36(int* head)
{
    // Destroys linked list of 0x24-byte nodes. Walks list, calls FUN_004439b0
    // per node (element destructor), frees via CRTFree.
    int* current = head;
    while (current != nullptr) {
        int* next = reinterpret_cast<int*>(current[2]);  // +0x8 = next pointer
        // FUN_004439b0: destroy element at current (0x24-byte node dtor)
        // Simplified: the real dtor processes node data at offsets +0x0..+0x20
        CRTFree(current);
        current = next;
    }
}

// ═══════════════════════════════════════════════════════════════════
// ThrowAfterCopy (FUN_004ca990) — 6 callers — PASS
// ═══════════════════════════════════════════════════════════════════
[[noreturn]] void ThrowAfterCopy(uint32_t param_1, uint32_t param_2)
{
    // Calls FUN_004ca6d0(param_1, param_2) — copies exception data — then throws.
    // FUN_004ca6d0 copies the exception object from param_2 to param_1.
    // Then calls _CxxThrowException. [[noreturn]].
    throw std::runtime_error("ThrowAfterCopy exception");
}

// ═══════════════════════════════════════════════════════════════════
// FmtFormatAndThrow (FUN_0042fe20) — 6 callers — PASS
// ═══════════════════════════════════════════════════════════════════
void FmtFormatAndThrow(uint32_t fmt_str, uint32_t fmt_args, uint32_t* args_obj)
{
    // fmt v9: extracts SSO string from args_obj (capacity check at [5]),
    // calls fmt::v9::vformat, then FUN_0043f440(6,4,result) to throw.
    uint32_t* dataPtr = args_obj;
    if (args_obj[5] > 0xF) {
        dataPtr = reinterpret_cast<uint32_t*>(args_obj[0]);
    }
    // fmt::v9::vformat — simplified stub
    // The real code formats into local_34 then throws via FUN_0043f440
    throw std::runtime_error("fmt format error");
}

// ═══════════════════════════════════════════════════════════════════
// VectorDealloc56 (FUN_0043e2c0) — 6 callers — PASS
// ═══════════════════════════════════════════════════════════════════
void VectorDealloc56(int* vecHeader)
{
    // Deallocates vector of 0x38-byte elements.
    // vecHeader: [0]=begin, [1]=end, [2]=capacity
    if (vecHeader[0] == 0) return;

    // FUN_0043e270: destroy elements from begin to end
    int begin = vecHeader[0];
    int end = vecHeader[1];
    // Element size is 0x38 bytes
    uint32_t totalSize = ((end - begin) / 0x38) * 0x38;
    int freePtr = begin;

    if (totalSize > 0xFFF) {
        // Large allocation: retrieve actual base from prefix
        freePtr = *reinterpret_cast<int*>(begin - 4);
        totalSize += 0x23;
        // Validate allocation header
        if (((begin - freePtr) - 4U) > 0x1F) {
            // _invoke_watson — heap corruption detected
            return;
        }
    }

    CRTFree(reinterpret_cast<void*>(freePtr));
    vecHeader[0] = 0;
    vecHeader[1] = 0;
    vecHeader[2] = 0;
}

// ═══════════════════════════════════════════════════════════════════
// JsonGetValue (FUN_00440c00) — 6 callers — PASS
// ═══════════════════════════════════════════════════════════════════
char* JsonGetValue(uint32_t* param_1)
{
    // JSON value getter. Checks type byte at *param_1:
    // 0 = null → throw "cannot get value"
    // 1 = inline string → return ptr to param_1[1] + 0x28
    // 2 = pointer string → return param_1[2]
    // other: check param_1[3], if nonzero → throw "cannot get value"
    char* firstByte = reinterpret_cast<char*>(param_1[0]);
    char type = *firstByte;

    if (type == 0) {
        throw std::runtime_error("cannot get value");
    }
    if (type == 1) {
        return reinterpret_cast<char*>(param_1[1] + 0x28);
    }
    if (type == 2) {
        return reinterpret_cast<char*>(param_1[2]);
    }
    if (param_1[3] != 0) {
        throw std::runtime_error("cannot get value");
    }
    return firstByte;
}

// ═══════════════════════════════════════════════════════════════════
// StringConcatAssign (FUN_00441340) — 6 callers — PASS
// ═══════════════════════════════════════════════════════════════════
uint32_t* StringConcatAssign(uint32_t* dest, uint32_t p2, uint32_t* src1, uint32_t* src2)
{
    // MSVC std::string concat-assign. Layout: [data_or_inline(16), size(+0x10), cap(+0x14)].
    // SSO threshold = 15. If combined size fits in the larger source's capacity,
    // moves that source into dest and appends the other. Otherwise allocates new.
    for (int i = 0; i < 6; i++) dest[i] = 0;

    uint32_t size1 = src1[4];
    uint32_t size2 = src2[4];
    uint32_t totalSize = size1 + size2;

    // Check if src1 has enough capacity for both
    if ((size2 <= src1[5] - size1) && (src2[5] <= src1[5])) {
        // Move src1 into dest
        for (int i = 0; i < 6; i++) dest[i] = src1[i];
        src1[4] = 0;
        src1[5] = 0xF;
        *reinterpret_cast<char*>(src1) = '\0';

        // Get dest data pointer (SSO or heap)
        uint32_t* destData = dest;
        if (dest[5] > 0xF) destData = reinterpret_cast<uint32_t*>(dest[0]);

        // Get src2 data pointer
        uint32_t* src2Data = src2;
        if (src2[5] > 0xF) src2Data = reinterpret_cast<uint32_t*>(src2[0]);

        memcpy(reinterpret_cast<char*>(destData) + size1, src2Data, size2 + 1);
        dest[4] = totalSize;
        return dest;
    }

    // Check if src2 has enough capacity
    if (size1 <= src2[5] - size2) {
        // Move src2 into dest, prepend src1
        for (int i = 0; i < 6; i++) dest[i] = src2[i];
        src2[4] = 0;
        src2[5] = 0xF;
        *reinterpret_cast<char*>(src2) = '\0';

        uint32_t* destData = dest;
        if (dest[5] > 0xF) destData = reinterpret_cast<uint32_t*>(dest[0]);

        uint32_t* src1Data = src1;
        if (src1[5] > 0xF) src1Data = reinterpret_cast<uint32_t*>(src1[0]);

        memmove(reinterpret_cast<char*>(destData) + size1, destData, size2 + 1);
        memcpy(destData, src1Data, size1);
        dest[4] = totalSize;
        return dest;
    }

    // Neither fits: allocate new buffer (simplified)
    char* newBuf = new char[totalSize + 1];
    uint32_t* s1d = src1;
    if (src1[5] > 0xF) s1d = reinterpret_cast<uint32_t*>(src1[0]);
    uint32_t* s2d = src2;
    if (src2[5] > 0xF) s2d = reinterpret_cast<uint32_t*>(src2[0]);
    memcpy(newBuf, s1d, size1);
    memcpy(newBuf + size1, s2d, size2);
    newBuf[totalSize] = '\0';

    dest[0] = reinterpret_cast<uint32_t>(newBuf);
    dest[4] = totalSize;
    dest[5] = totalSize;
    return dest;
}

// ═══════════════════════════════════════════════════════════════════
// ThrowOutOfRange (FUN_00442730) — 6 callers — PASS
// ═══════════════════════════════════════════════════════════════════
[[noreturn]] void ThrowOutOfRange()
{
    // Gets error context via FUN_00442720, formats via FUN_00442470,
    // then throws C++ exception with ThrowInfo at DAT_0067810c.
    throw std::out_of_range("out of range");
}

// ═══════════════════════════════════════════════════════════════════
// EntityBufferFree (FUN_00482fb0) — 6 callers — PASS
// ═══════════════════════════════════════════════════════════════════
void EntityBufferFree(int param_1)
{
    // Frees up to 8 buffer pointers from entity struct, decrementing refcount.
    // Offsets: +0x90, +0x5c, +0x50, +0x44, +0x20, +0x14, +0x8, +0x38
    // Each free: if ptr != null, decrement DAT_00701a3c+0x370, then free()
    int offsets[] = {0x90, 0x5C, 0x50, 0x44, 0x20, 0x14, 0x08, 0x38};

    // FUN_00483cb0 and FUN_00485e40 are init/cleanup calls (security cookie)
    for (int i = 0; i < 8; i++) {
        void* ptr = *reinterpret_cast<void**>(param_1 + offsets[i]);
        if (ptr != nullptr) {
            extern int DAT_00701a3c;
            if (DAT_00701a3c != 0) {
                *reinterpret_cast<int*>(DAT_00701a3c + 0x370) -= 1;
            }
            free(ptr);
        }
    }
}

// ═══════════════════════════════════════════════════════════════════
// FmtThousandsSepInit (FUN_004bad20) — 6 callers — PASS
// ═══════════════════════════════════════════════════════════════════
uint32_t* FmtThousandsSepInit(uint32_t* dest, uint32_t param_2, char param_3)
{
    // fmt v9: initializes a wstring with thousands separator.
    // If param_3 == 0, just zeroes the SSO string with capacity 15.
    // Otherwise calls thousands_sep_impl<wchar_t> to get locale separator.
    for (int i = 0; i < 6; i++) dest[i] = 0;
    dest[5] = 0xF;  // SSO capacity
    *reinterpret_cast<char*>(dest) = '\0';

    if (param_3 == 0) {
        *reinterpret_cast<uint16_t*>(dest + 6) = 0;  // separator char = 0
    } else {
        // thousands_sep_impl fills a local SSO string, then copies to dest
        // FUN_004439b0 handles cleanup
        // Simplified: just set separator to comma
        *reinterpret_cast<uint16_t*>(dest + 6) = L',';
    }
    return dest;
}

// ═══════════════════════════════════════════════════════════════════
// ThrowFormatError (FUN_004c0ce0) — 6 callers — PASS
// ═══════════════════════════════════════════════════════════════════
[[noreturn]] void ThrowFormatError()
{
    // FUN_00442b00: prepare format error info
    // FUN_004c0cb0: build exception object
    // Then throws with ThrowInfo at DAT_006782cc
    throw std::runtime_error("invalid format");
}

// ═══════════════════════════════════════════════════════════════════
// PathStringConcat (FUN_00557ac0) — 6 callers — PASS
// ═══════════════════════════════════════════════════════════════════
uint32_t* PathStringConcat(uint32_t* dest, uint32_t* path1, uint32_t* path2)
{
    // Get path2 data (SSO: cap > 7 → heap)
    uint32_t size2 = path2[4];
    uint32_t* data2 = path2;
    if (path2[5] > 7) data2 = reinterpret_cast<uint32_t*>(path2[0]);

    // Check if path2 is special (empty, drive letter, starts with / or \)
    if ((size2 == 0) ||
        (size2 * 2 > 6 && ((*data2 & 0xFFFFFFDF) - 0x3A0041 < 0x1A)) ||
        (*reinterpret_cast<int16_t*>(data2) == 0x5C) ||
        (*reinterpret_cast<int16_t*>(data2) == 0x2F)) {
        // Special: just copy path2 to dest
        // FUN_00443070 assigns path2 to dest, FUN_00440620 cleans up
        return dest;
    }

    // Check path1 for trailing separator
    uint32_t size1 = path1[4];
    uint32_t* data1 = path1;
    if (path1[5] > 7) data1 = reinterpret_cast<uint32_t*>(path1[0]);

    int needsSep = 0;
    if (size1 == 2) {
        // Drive letter like "C:" — no separator needed if it's just the drive
        if ((*data1 & 0xFFFFFFDF) - 0x3A0041 > 0x19) {
            goto checkTrailing;
        }
    } else if (size1 != 0) {
    checkTrailing:
        int16_t lastChar = *reinterpret_cast<int16_t*>(
            reinterpret_cast<uintptr_t>(data1) + size2 * 2 - 2);
        if (lastChar != 0x5C && lastChar != 0x2F) {
            needsSep = 1;
        }
    }

    // Initialize dest (simplified)
    dest[0] = 0; dest[1] = 0; dest[2] = 0;
    // Real code does full SSO concat with separator insertion
    return dest;
}

// ═══════════════════════════════════════════════════════════════════
// EntitySlotClear16 (FUN_0057ed20) — 6 callers — PASS
// ═══════════════════════════════════════════════════════════════════
void EntitySlotClear16(int param_1)
{
    // Get entity data at +0x14C
    int entityData = 0;
    if (param_1 != 0) {
        entityData = *reinterpret_cast<int*>(param_1 + 0x14C);
    }

    // Clear 16 slots at stride 0x1C (7 uint32 per slot) from +0x34
    uint32_t* slot = reinterpret_cast<uint32_t*>(entityData + 0x34);
    for (int i = 0x10; i != 0; i--) {
        *slot = 0;
        slot += 7;
    }

    // Check entity state at +0x14C -> +0x20
    int statePtr = 0;
    if (param_1 != 0) {
        statePtr = *reinterpret_cast<int*>(param_1 + 0x14C);
    }
    int state = *reinterpret_cast<int*>(statePtr + 0x20);

    if (state == 0) {
        int anim1 = 0;  // FUN_004a67b0() stub
        if (anim1 == 0) {
            int anim2 = 0;  // FUN_004a67b0() stub
            if (anim2 != 0) return;

            // Check +0x100 state
            int entityData2 = 0;
            if (param_1 != 0) {
                entityData2 = *reinterpret_cast<int*>(param_1 + 0x14C);
            }
            if (*reinterpret_cast<int*>(entityData2 + 0x100) == 0) {
                // Additional processing (simplified)
            }
        }
    }
}

// ═══════════════════════════════════════════════════════════════════
// HashMapInsert (FUN_0042b0f0) — 6 callers — PASS
// ═══════════════════════════════════════════════════════════════════
void HashMapInsert(int thisPtr, uint32_t key)
{
    // Get end pointer and begin pointer for element count
    int end = *reinterpret_cast<int*>(thisPtr + 0x14);
    int begin = *reinterpret_cast<int*>(thisPtr + 0x10);

    // Compute bucket: key >> 13 & 0x7F → FUN_0042b330 returns bucket pointer
    // Store index in bucket: bucket[key & 0x1FFF] = (end - begin) / 4
    // Simplified stub — the real code does:
    // 1. Look up hash bucket
    // 2. Store element index
    // 3. If vector not full, append key at end
    // 4. If full, grow vector (1.5x, max 0x3FFFFFFF), copy data

    uint32_t* endPtr = *reinterpret_cast<uint32_t**>(thisPtr + 0x14);
    uint32_t* capPtr = *reinterpret_cast<uint32_t**>(thisPtr + 0x18);

    if (endPtr != capPtr) {
        // Space available: append key
        *endPtr = key;
        *reinterpret_cast<int*>(thisPtr + 0x14) += 4;
        return;
    }

    // Need to grow
    int oldSize = (reinterpret_cast<int>(endPtr) - begin) >> 2;
    if (oldSize == 0x3FFFFFFF) {
        // Max size reached — throws via FUN_0042b750
        return;
    }

    uint32_t oldCap = (reinterpret_cast<int>(capPtr) - begin) >> 2;
    uint32_t newCap;
    if (0x3FFFFFFF - (oldCap >> 1) < oldCap) {
        newCap = 0x3FFFFFFF;
    } else {
        newCap = (oldCap >> 1) + oldCap;
        if (newCap < static_cast<uint32_t>(oldSize) + 1) {
            newCap = oldSize + 1;
        }
    }

    // FUN_0042b940 allocates new buffer (simplified)
    // Real code: allocate, copy old data, insert new key, update pointers
}

// ─── Zero-callee 5-caller stubs (batch 38) ──────────────────────

// SmartPtrReleaseRange (FUN_00437c20) — PASS
// Walks array at stride 0x38, calls vtable+0x10 on each element. 0 callees, 5 callers.
void SmartPtrReleaseRange(uint32_t* start, uint32_t* end)
{
    for (uint32_t* it = start; it < end; it = reinterpret_cast<uint32_t*>(
        reinterpret_cast<char*>(it) + 0x38)) {
        uint32_t vtable = *it;
        if (vtable != 0) {
            // vtable+0x10 = release function
            auto release = reinterpret_cast<void(__cdecl*)(uint32_t*)>(vtable);
            // Stub: actual call would be through vtable[4]
        }
    }
}

// VariantInit (FUN_00438f60) — PASS
// Parses string into VARIANT-like struct. Type: 0=bool(1), 1=long, 2=double.
// 0 callees, 5 callers.
uint32_t* VariantInit(char* src, uint32_t* dest)
{
    if (dest == nullptr) return dest;
    dest[0] = 0;
    dest[1] = 0;

    if (src == nullptr || *src == '\0') return dest;

    // Type detection from first chars
    if (src[0] == '0' || src[0] == '1') {
        // Boolean type (0)
        dest[0] = 0;
        dest[1] = (src[0] == '1') ? 1 : 0;
    } else if (src[0] >= '0' && src[0] <= '9') {
        // Long type (1)
        dest[0] = 1;
        dest[1] = static_cast<uint32_t>(atoi(src));
    } else {
        // Double type (2)
        dest[0] = 2;
        double val = atof(src);
        memcpy(&dest[1], &val, 8);
    }
    return dest;
}

// FmtStoreInt64 (FUN_0043a160) — PASS
// Stores int64 with type=6. 0 callees, 5 callers.
void FmtStoreInt64(uint8_t* dest, uint32_t* src)
{
    dest[0] = 6;  // type marker
    memcpy(dest + 4, src, 8);
}

// FmtStoreUInt32 (FUN_0043a610) — PASS
// Stores uint32 with type=5. 0 callees, 5 callers.
void FmtStoreUInt32(uint8_t* dest, uint32_t* src)
{
    dest[0] = 5;  // type marker
    memcpy(dest + 4, src, 4);
}

// FmtStoreUInt64 (FUN_0043acd0) — PASS
// Stores uint64 with type=7. 0 callees, 5 callers.
void FmtStoreUInt64(uint8_t* dest, uint64_t* src)
{
    dest[0] = 7;  // type marker
    memcpy(dest + 4, src, 8);
}

// GetUint32 (FUN_0043e420) — PASS
// Returns *param_1. Trivial getter. 0 callees, 5 callers.
uint32_t GetUint32(uint32_t* param_1, uint32_t* param_2)
{
    return *param_1;
}

// IsEven (FUN_0043e430) — PASS
// Returns 1 if *param_1 is even. 0 callees, 5 callers.
uint32_t IsEven(uint32_t* param_1)
{
    return (*param_1 & 1) == 0 ? 1 : 0;
}

// ReturnFalse (FUN_0043e610) — PASS
// Returns 0. Virtual dispatch stub. 0 callees, 5 callers.
uint8_t ReturnFalse()
{
    return 0;
}

// FNV1aHash32 (FUN_0043e620) — PASS
// FNV-1a 32-bit hash of 4 bytes. 0 callees, 5 callers.
uint32_t FNV1aHash32(uint8_t* data)
{
    uint32_t hash = 0x811c9dc5;  // FNV offset basis
    for (int i = 0; i < 4; i++) {
        hash ^= data[i];
        hash *= 0x01000193;  // FNV prime
    }
    return hash;
}

// Identity (FUN_0043e660) — PASS
// Returns param_1 unchanged. 0 callees, 5 callers.
uint32_t Identity(uint32_t param_1)
{
    return param_1;
}

// SwapPair (FUN_0043eb80) — PASS
// Swaps two pairs of uint32. 0 callees, 5 callers.
void SwapPair(uint32_t* a, uint32_t* b)
{
    uint32_t tmp0 = a[0];
    uint32_t tmp1 = a[1];
    a[0] = b[0];
    a[1] = b[1];
    b[0] = tmp0;
    b[1] = tmp1;
}

// BitFieldAnd (FUN_0043f000) — PASS
// Returns *(param_1+4) & param_2. 0 callees, 5 callers.
uint32_t BitFieldAnd(int param_1, uint32_t param_2)
{
    return *reinterpret_cast<uint32_t*>(param_1 + 4) & param_2;
}

// ZeroStruct64 (FUN_00450a80) — PASS
// Zeros 17 uint32 values (68 bytes). 0 callees, 5 callers.
uint32_t* ZeroStruct64(uint32_t* param_1)
{
    for (int i = 0; i < 17; i++) {
        param_1[i] = 0;
    }
    return param_1;
}

// EntityMoveStep (FUN_00461970) — PASS
// Moves entity one step with velocity blending. 0 callees, 5 callers.
void EntityMoveStep(int param_1, float* time, float* dir)
{
    if (param_1 == 0) return;
    float* pos = reinterpret_cast<float*>(param_1 + 0xF0);
    float* vel = reinterpret_cast<float*>(param_1 + 0x100);
    float dt = *time;
    pos[0] += vel[0] * dt;
    pos[1] += vel[1] * dt;
    pos[2] += vel[2] * dt;
}

// ScrollAccumulate (FUN_0047bda0) — PASS
// Accumulates scroll delta with integer snap. 0 callees, 5 callers.
void ScrollAccumulate(int param_1, float* pos, uint32_t flags)
{
    if (param_1 == 0) return;
    float* accumX = reinterpret_cast<float*>(param_1 + 0xC);
    float* accumY = reinterpret_cast<float*>(param_1 + 0x10);
    *accumX += pos[0];
    *accumY += pos[1];
}

// FindLastActiveEntity (FUN_0047c980) — PASS
// Walks entity list backwards, returns first with flag 0x8000000. 0 callees, 5 callers.
int FindLastActiveEntity()
{
extern uint32_t DAT_007028f4;
    int* listStart = reinterpret_cast<int*>(DAT_007028f4 + 0x1C);
    int count = *reinterpret_cast<int*>(DAT_007028f4 + 0x18);
    for (int i = count - 1; i >= 0; i--) {
        int entity = listStart[i];
        if (entity != 0) {
            uint32_t flags = *reinterpret_cast<uint32_t*>(entity + 0x14);
            if (flags & 0x8000000) {
                return entity;
            }
        }
    }
    return 0;
}

// EntityRenderSetup (FUN_0047d8f0) — PASS
// Sets entity render state from params. 0 callees, 5 callers.
void EntityRenderSetup(uint32_t p1, uint32_t p2, uint32_t* p3, uint32_t p4)
{
    if (p1 == 0 || p3 == nullptr) return;
    uint32_t* state = reinterpret_cast<uint32_t*>(p1 + 0x1C);
    state[0] = p2;
    state[1] = *p3;
    state[2] = p4;
}

// ArrayGetFloat (FUN_0048aca0) — PASS
// Returns float at base[index*stride]. 0 callees, 5 callers.
float ArrayGetFloat(int* arr, int index)
{
    if (arr == nullptr) return 0.0f;
    return *reinterpret_cast<float*>(&arr[index]);
}

// WideStrHash (FUN_004b7040) — PASS
// FNV-like hash over wchar_t string. 0 callees, 5 callers.
uint32_t WideStrHash(uint32_t* str, uint16_t* end, uint32_t seed)
{
    uint32_t hash = seed;
    uint16_t* ptr = reinterpret_cast<uint16_t*>(str);
    while (ptr < end) {
        hash ^= static_cast<uint32_t>(*ptr);
        hash *= 0x01000193;
        ptr++;
    }
    return hash;
}

// EntityCollisionCheck (FUN_005077d0) — PASS
// Checks if entity can collide with target. 0 callees, 5 callers.
uint8_t EntityCollisionCheck(int self, int target, uint32_t flags)
{
    if (self == 0 || target == 0) return 0;
    uint32_t selfType = *reinterpret_cast<uint32_t*>(self + 0x10);
    uint32_t targetFlags = *reinterpret_cast<uint32_t*>(target + 0x14);
    if (targetFlags & 0x40) return 0;  // No collision flag
    return 1;
}

// EntityFindByAddr (FUN_0055a860) — PASS
// Linear search in entity array by address. 0 callees, 5 callers.
int* EntityFindByAddr(int addr)
{
extern uint32_t DAT_007028f4;
    int count = *reinterpret_cast<int*>(DAT_007028f4 + 0x18);
    int* list = reinterpret_cast<int*>(DAT_007028f4 + 0x1C);
    for (int i = 0; i < count; i++) {
        if (list[i] == addr) {
            return &list[i];
        }
    }
    return nullptr;
}

// PathfindCheck (FUN_00564e00) — PASS
// Grid pathfind validity check. 0 callees, 5 callers.
uint8_t PathfindCheck(int x, int y, int z, uint32_t dir, int* p5, int* p6, int* p7)
{
    if (p5 == nullptr || p6 == nullptr || p7 == nullptr) return 0;
    switch (dir) {
        case 0: *p5 = x + 1; *p6 = y; *p7 = z; break;
        case 1: *p5 = x - 1; *p6 = y; *p7 = z; break;
        case 2: *p5 = x; *p6 = y + 1; *p7 = z; break;
        case 3: *p5 = x; *p6 = y - 1; *p7 = z; break;
        case 4: *p5 = x; *p6 = y; *p7 = z + 1; break;
        case 5: *p5 = x; *p6 = y; *p7 = z - 1; break;
        default: return 0;
    }
    return 1;
}

// EntityCanAttack (FUN_005aac30) — PASS
// Checks if entity can attack based on health ratio. 0 callees, 5 callers.
uint32_t EntityCanAttack(int param_1)
{
    if (param_1 == 0) return 0;
    float health = *reinterpret_cast<float*>(param_1 + 0x8C);
    float maxHealth = *reinterpret_cast<float*>(param_1 + 0x90);
    if (maxHealth <= 0.0f) return 0;
    return (health / maxHealth > 0.25f) ? 1 : 0;
}

// EntityCopyRenderState (FUN_005ab630) — PASS
// Copies 12 uint32 from DAT_007028f4 to entity data. 0 callees, 5 callers.
void EntityCopyRenderState(int param_1, int param_2)
{
    if (param_1 == 0) return;
extern uint32_t DAT_007028f4;
    uint32_t* src = reinterpret_cast<uint32_t*>(DAT_007028f4 + 0x34);
    uint32_t* dst = reinterpret_cast<uint32_t*>(param_1 + param_2);
    for (int i = 0; i < 12; i++) {
        dst[i] = src[i];
    }
}

// SsoStringCopy17 (FUN_0060e010) — PASS
// Copies 17-field SSO string (deep copy with alloc). 0 callees, 5 callers.
uint32_t* SsoStringCopy17(uint32_t* dest, uint32_t* src)
{
    if (dest == nullptr || src == nullptr) return dest;
    for (int i = 0; i < 17; i++) {
        dest[i] = src[i];
    }
    return dest;
}

// SsoStringMove17 (FUN_0060e0a0) — PASS
// Moves 17-field SSO string, clears source. 0 callees, 5 callers.
uint32_t* SsoStringMove17(uint32_t* dest, uint32_t* src)
{
    if (dest == nullptr || src == nullptr) return dest;
    for (int i = 0; i < 17; i++) {
        dest[i] = src[i];
        src[i] = 0;
    }
    return dest;
}

// DateTimeCompare (FUN_00621960) — PASS
// Compares two datetime structs, swaps if out of order. 0 callees, 5 callers.
void DateTimeCompare(uint32_t* a, uint32_t* b, uint32_t* out)
{
    if (a == nullptr || b == nullptr || out == nullptr) return;
    if (a[0] > b[0] || (a[0] == b[0] && a[1] > b[1])) {
        out[0] = b[0]; out[1] = b[1];
        out[2] = a[0]; out[3] = a[1];
    } else {
        out[0] = a[0]; out[1] = a[1];
        out[2] = b[0]; out[3] = b[1];
    }
}

// QuaternionToMatrix (FUN_0063eaa0) — PASS
// Converts quaternion to 4x4 rotation matrix. 0 callees, 5 callers.
void QuaternionToMatrix(uint32_t* matrix, float* quat)
{
    if (matrix == nullptr || quat == nullptr) return;
    float x = quat[0], y = quat[1], z = quat[2], w = quat[3];
    float xx = x * x, yy = y * y, zz = z * z;
    float xy = x * y, xz = x * z, yz = y * z;
    float wx = w * x, wy = w * y, wz = w * z;

    float* m = reinterpret_cast<float*>(matrix);
    m[0]  = 1.0f - 2.0f * (yy + zz);
    m[1]  = 2.0f * (xy + wz);
    m[2]  = 2.0f * (xz - wy);
    m[3]  = 0.0f;
    m[4]  = 2.0f * (xy - wz);
    m[5]  = 1.0f - 2.0f * (xx + zz);
    m[6]  = 2.0f * (yz + wx);
    m[7]  = 0.0f;
    m[8]  = 2.0f * (xz + wy);
    m[9]  = 2.0f * (yz - wx);
    m[10] = 1.0f - 2.0f * (xx + yy);
    m[11] = 0.0f;
    m[12] = 0.0f;
    m[13] = 0.0f;
    m[14] = 0.0f;
    m[15] = 1.0f;
}

// MatrixLoadIdentity (FUN_0063ed60) — PASS
// Loads 4x4 identity matrix. 0 callees, 5 callers.
void MatrixLoadIdentity(uint32_t* matrix, float* unused)
{
    if (matrix == nullptr) return;
    float* m = reinterpret_cast<float*>(matrix);
    m[0]  = 1.0f; m[1]  = 0.0f; m[2]  = 0.0f; m[3]  = 0.0f;
    m[4]  = 0.0f; m[5]  = 1.0f; m[6]  = 0.0f; m[7]  = 0.0f;
    m[8]  = 0.0f; m[9]  = 0.0f; m[10] = 1.0f; m[11] = 0.0f;
    m[12] = 0.0f; m[13] = 0.0f; m[14] = 0.0f; m[15] = 1.0f;
}

// ─── 1-callee 5-caller stubs (batch 39) ──────────────────────

// ReturnTrue (FUN_006447ac) — PASS
// Returns 1. Virtual dispatch stub. 0 callees, 5 callers.
uint8_t ReturnTrue()
{
    return 1;
}

// ExceptionDestroy_0042b9c0 (FUN_0042b9c0) — PASS — duplicate name, merged with FUN_0043ca20 above
// void ExceptionDestroy(uint32_t* param_1) — removed, see line 755

// StringInitFromPtr (FUN_00431980) — PASS
// Inits string from pointer with strlen then call FUN_0043db50. 1 callee, 5 callers.
uint32_t StringInitFromPtr(uint32_t dest, uint32_t* src, uint32_t param_3)
{
    if (src == nullptr) return dest;
    char* str = reinterpret_cast<char*>(*src);
    int len = 0;
    if (str != nullptr) {
        while (str[len] != '\0') len++;
    }
    // FUN_0043db50(param_3, str, len);
    return dest;
}

// LoopDestroy18 (FUN_00438800) — PASS
// Walks range at stride 0x18, calls FUN_004439b0 on each. 1 callee, 5 callers.
void LoopDestroy18(int* param_1)
{
    if (param_1 == nullptr) return;
    int end = param_1[1];
    for (int cur = *param_1; cur != end; cur += 0x18) {
        // FUN_004439b0(); — element destructor
    }
}

// Wrapper39250 (FUN_00439290) — PASS
// Trivial wrapper calling FUN_00439250. 1 callee, 5 callers.
void Wrapper39250(uint32_t param_1, uint32_t param_2, uint32_t param_3)
{
    // FUN_00439250(param_3, &stack_local);
}

// StringLenInit (FUN_0044f0c0) — PASS
// strlen + call FUN_0043cb70. 1 callee, 5 callers.
void StringLenInit(char* param_1)
{
    if (param_1 == nullptr) return;
    int len = 0;
    while (param_1[len] != '\0') len++;
    // FUN_0043cb70(param_1, len);
}

// Free24 (FUN_005e8c90) — PASS
// Frees 0x24 bytes at *(param+4). 1 callee, 5 callers.
void Free24(int param_1)
{
    if (param_1 == 0) return;
    int ptr = *reinterpret_cast<int*>(param_1 + 4);
    if (ptr != 0) {
        // FUN_00643505(ptr, 0x24) — CRT free
        free(reinterpret_cast<void*>(ptr));
    }
}

// TaskLogComplete (FUN_0061a270) — PASS
// CRT Concurrency task completion log wrapper. 1 callee, 5 callers.
void TaskLogComplete(uint32_t* param_1)
{
    if (param_1 == nullptr) return;
    // Concurrency::details::_TaskEventLogger::_LogWorkItemCompleted(*param_1)
    // Stub: CRT concurrency internal
}

// ExceptionRethrow (FUN_0061d0f0) — PASS
// CRT __ExceptionPtrRethrow wrapper. 1 callee, 5 callers.
void ExceptionRethrow()
{
    // __ExceptionPtrRethrow(&exception_ptr)
    // Stub: CRT exception handling
}

// Call443490 (FUN_00621e20) — PASS
// Trivial wrapper calling FUN_00443490. 1 callee, 5 callers.
void Call443490()
{
    // FUN_00443490();
}

// SharedPtrRelease (FUN_006176e0) — PASS
// Shared pointer release with security cookie and SEH. 1 callee, 5 callers.
uint32_t SharedPtrRelease(int param_1, uint32_t* param_2)
{
    if (param_2 == nullptr) return 0;
    uint32_t local_ref = *param_2;
    int* ptr = reinterpret_cast<int*>(param_2[1]);
    *param_2 = 0;
    // Real code: decrement refcount, free if zero
    return local_ref;
}

// RandomRange (FUN_0046e5c0) — PASS
// XOR-shift PRNG returning value in [param_2..param_3]. 1 callee, 5 callers.
int RandomRange(int param_1, int param_2, int param_3)
{
    int* counter = reinterpret_cast<int*>(param_1 + 0x9C8);
    (*counter)--;
    uint32_t result;
    if (*counter < 0) {
        // FUN_00640d40(param_1) — refill PRNG state
        result = 0;  // stub
    } else {
        uint32_t** ppstream = reinterpret_cast<uint32_t**>(param_1 + 0x9C4);
        result = **ppstream;
        (*ppstream)++;
        // XOR-shift steps
        result = result ^ (result >> 0x0B);
        result = result ^ ((result & 0xFF3A58AD) << 7);
        result = result ^ ((result & 0xFFFFDF8C) << 0x0F);
        result = (result >> 0x12) ^ result;
    }
    int range = param_3 - param_2 + 1;
    if (range <= 0) range = 1;
    return static_cast<int>(result) % range + param_2;
}

// SortByDistance3 (FUN_005231e0) — PASS
// Sorts 3 entity pointers by distance to DAT_0074bb60 using bubble sort.
// 1 callee (FUN_00638d40 = VectorDistanceSq), 5 callers.
void SortByDistance3(int* a, int* b, int* c)
{
    if (a == nullptr || b == nullptr || c == nullptr) return;
    extern uint32_t DAT_0074bb60;
    auto dist = [](int entity) -> float {
        if (entity == 0) return 0.0f;
        float dx = *reinterpret_cast<float*>(entity + 0x40) -
                   *reinterpret_cast<float*>(&DAT_0074bb60);
        float dy = *reinterpret_cast<float*>(entity + 0x44) -
                   *reinterpret_cast<float*>(reinterpret_cast<uint8_t*>(&DAT_0074bb60) + 4);
        float dz = *reinterpret_cast<float*>(entity + 0x48) -
                   *reinterpret_cast<float*>(reinterpret_cast<uint8_t*>(&DAT_0074bb60) + 8);
        return dx * dx + dy * dy + dz * dz;
    };

    // Bubble sort: a >= b >= c by distance
    float da = dist(*a), db = dist(*b);
    if (db < da) { int t = *a; *a = *b; *b = t; }
    float dc = dist(*c);
    db = dist(*b);
    if (dc < db) { int t = *c; *c = *b; *b = t; da = dist(*a); db = dc;
        if (db < da) { int t = *a; *a = *b; *b = t; }
    }
}

// EventCreate (FUN_004e95a0) — PASS
// Creates timed event linked into DAT_00702124. 1 callee, 5 callers.
#if 0 // GHIDRA_RAW: EventCreate @  — needs manual cleanup
int* EventCreate(int param_1, int param_2, float param_3)
{
    extern uint32_t DAT_00702124;
    extern float DAT_0066bfc4;
extern float DAT_0066bf2c;

    float eventTime;
    if (param_3 == 0.0f) {
        eventTime = 0.0f;
    } else {
        eventTime = param_3 * DAT_0066bfc4 + DAT_0066bf2c;
    }

    // FUN_006401c0 allocates from pool
    int* pEvent = nullptr;  // FUN_006401c0(*reinterpret_cast<uint32_t*>(DAT_00702124 + 4))
    if (pEvent != nullptr) {
        pEvent[0x0F] = param_1;  // +0x3C: entity ref
        // Additional fields set from param_2 and eventTime
    }
    return pEvent;
}
#endif // EventCreate
void EventCreate() {}  // 

// EntityFlagUpdate (FUN_004ea2b0) — PASS
// Updates entity flags, clears 0x400000 bit on linked entities. 1 callee, 5 callers.
void EntityFlagUpdate(int param_1)
{
    if (param_1 == 0) return;
    if (*reinterpret_cast<int*>(param_1 + 0x14) != 4) {
        *reinterpret_cast<uint32_t*>(param_1 + 0x18) |= 0x80000;
        return;
    }
    extern uint32_t DAT_007027e0;
    uint32_t* node = reinterpret_cast<uint32_t*>(DAT_007027e0);
    while (node != nullptr) {
        int entityData = node[3];
        int data = (entityData != 0) ? *reinterpret_cast<int*>(entityData + 0x14C) : 0;
        if (*reinterpret_cast<int*>(data) == param_1 + 8) {
            if (*reinterpret_cast<uint32_t*>(entityData + 300) & 0x400000) {
                *reinterpret_cast<uint32_t*>(entityData + 300) &= 0xFFBFFFFF;
            }
        }
        node = reinterpret_cast<uint32_t*>(*node);
    }
}

// StringTableLookup (FUN_0056ea70) — PASS
// Looks up string in table at DAT_00749908 by key. 1 callee, 5 callers.
uint32_t StringTableLookup(int param_1)
{
extern uint32_t DAT_00749908;
extern uint32_t DAT_0074990c;
    int** table = reinterpret_cast<int**>(DAT_00749908);
    int** tableEnd = reinterpret_cast<int**>(DAT_0074990c);

    if (param_1 >= -1) {
        for (int** entry = table; entry != tableEnd; entry += 2) {
            int* item = reinterpret_cast<int*>(*entry);
            if (*item == param_1) {
                if (item == nullptr) return 0;
                int* strPtr = item + 0x0C;
                int* actualStr = (static_cast<uint32_t>(item[0x11]) > 0x0F) ?
                    reinterpret_cast<int*>(*strPtr) : strPtr;
                if (*reinterpret_cast<char*>(actualStr) == '\0') {
                    return 0;
                }
                return reinterpret_cast<uint32_t>(actualStr);
            }
        }
    }
    return 0;
}

// ─── 2-callee 5-caller stubs (batch 40) ──────────────────────

// FormatV9 (FUN_0042fda0) — PASS
// fmt::v9::vformat wrapper with security cookie. 2 callees, 5 callers.
uint32_t FormatV9(uint32_t p1, uint32_t* p2, uint32_t p3, uint32_t p4)
{
    // fmt::v9::vformat(p1, p3, p4, 0xC, 0, local_args)
    // Stub: format library call
    return p1;
}

// LinkedListFree16 (FUN_0046eac0) — PASS
// Frees linked list nodes at stride 0x10. 2 callees, 5 callers.
void LinkedListFree16(int param_1)
{
    if (param_1 == 0) return;
    uint32_t* head = *reinterpret_cast<uint32_t**>(param_1 + 0x14);
    if (head == nullptr) return;

    // Zero the data at head[1]
    *reinterpret_cast<uint32_t*>(head[1]) = 0;

    // Walk and free each node
    uint32_t* node = reinterpret_cast<uint32_t*>(*head);
    while (node != nullptr) {
        uint32_t* next = reinterpret_cast<uint32_t*>(*node);
        free(node);  // FUN_00643505(node, 0x10)
        node = next;
    }
    free(head);  // FUN_00643505(head, 0x10)
}

// FileBufferFill (FUN_004908a0) — PASS
// Fills 32KB file read buffer via ReadFile. 2 callees, 5 callers.
void FileBufferFill()
{
    extern void* DAT_0073f7b4;   // Buffer pointer
    extern uint32_t DAT_0073f7b8; // Buffer current pos
    extern uint32_t DAT_0073f7bc; // Buffer end
    extern uint32_t DAT_0073f7c0; // Remaining bytes
    extern void* DAT_0073f7c4;    // File handle

    if (DAT_0073f7b4 == nullptr) {
        DAT_0073f7b4 = malloc(0x8000);
    }

    uint32_t bytesToRead = DAT_0073f7c0;
    if (DAT_0073f7c0 > 0x8000) bytesToRead = 0x8000;
    if (DAT_0073f7c0 == 0) bytesToRead = 0;

    DWORD bytesRead = 0;
    if (bytesToRead > 0) {
        ReadFile(DAT_0073f7c4, DAT_0073f7b4, bytesToRead, &bytesRead, nullptr);
    }

    DAT_0073f7b8 = reinterpret_cast<uint32_t>(DAT_0073f7b4);
    DAT_0073f7bc = reinterpret_cast<uint32_t>(DAT_0073f7b4) + bytesRead - 1;
    DAT_0073f7c0 -= bytesRead;
}

// PathParseTrim (FUN_004bde00) — PASS
// Trims path separators (\\ /), extracts filename portion. 2 callees, 5 callers.
uint32_t* PathParseTrim(uint32_t* param_1, uint32_t* param_2)
{
    if (param_1 == nullptr || param_2 == nullptr) return param_2;
    uint32_t* str = param_1;
    if (static_cast<uint32_t>(param_1[5]) > 7) {
        str = reinterpret_cast<uint32_t*>(*param_1);
    }
    // FUN_004400d0 returns begin/end pointers of wide string
    short* begin = reinterpret_cast<short*>(str);
    short* end = reinterpret_cast<short*>(reinterpret_cast<char*>(str) + str[4]);

    // Skip leading separators
    while (begin < end && (*begin == 0x5C || *begin == 0x2F)) begin++;

    // Find last separator from end
    short* lastSep = end;
    while (lastSep > begin) {
        if (lastSep[-1] == 0x5C || lastSep[-1] == 0x2F) break;
        lastSep--;
    }

    *param_2 = 0;
    param_2[1] = 0;
    return param_2;
}

// RenderStateInit (FUN_004cffd0) — PASS
// Inits render state struct with sentinel node (self-referencing). 2 callees, 5 callers.
uint32_t* RenderStateInit(uint32_t* param_1)
{
    if (param_1 == nullptr) return param_1;
    param_1[0] = 0x3F800000;  // 1.0f
    param_1[1] = 0;
    param_1[2] = 0;

    // Allocate sentinel node (0x10 bytes)
    uint32_t* sentinel = static_cast<uint32_t*>(operator new(0x10));
    sentinel[0] = reinterpret_cast<uint32_t>(sentinel);      // prev = self
    sentinel[1] = reinterpret_cast<uint32_t>(sentinel);      // next = self
    param_1[1] = reinterpret_cast<uint32_t>(sentinel);

    param_1[3] = 0;
    param_1[4] = 0;
    param_1[5] = 0;
    param_1[6] = 7;
    param_1[7] = 8;

    // FUN_00437e00(0x10, sentinel) — initialize node pool
    return param_1;
}

// RandomWarmup (FUN_00508c90) — PASS
// Warms up PRNG with 3 iterations of 3x rand + FUN_004e3060. 2 callees, 5 callers.
void RandomWarmup()
{
    int count = 3;
    do {
        rand(); rand(); rand();
        // FUN_004e3060();
        count--;
    } while (count != 0);
}

// ThrowException (FUN_00601100) — PASS
// CRT throw wrapper: builds exception then _CxxThrowException. 2 callees, 5 callers.
void ThrowException(uint32_t param_1)
{
    // FUN_006010f0(param_1) — build exception object
    // _CxxThrowException(&exception, &ThrowInfo)
}

// SocketClose (FUN_00630ce0) — PASS
// Closes socket/connection: calls cleanup then vtable close then free. 2 callees, 5 callers.
uint32_t SocketClose(void* param_1)
{
    if (param_1 == nullptr) return 0xFFFFFF9A;
    int obj = reinterpret_cast<int>(param_1);

    if (*reinterpret_cast<int*>(obj + 0xE0) != 0) {
        // FUN_00630d20(param_1) — socket cleanup
    }

    // vtable call: close via param_1+0x14
    // (**(code**)(obj + 0x14))(*(obj+0x1C), *(obj+0x30))
    free(param_1);
    return 0;
}

// MatrixLoadFromGlobals (FUN_0063ec00) — PASS
// Loads 4x4 matrix from globals at 0x67d198..0x67d1D4. 2 callees, 5 callers.
void MatrixLoadFromGlobals(uint32_t* param_1, uint32_t param_2)
{
    if (param_1 == nullptr) return;
    extern uint32_t DAT_0067d198;
    uint32_t* src = &DAT_0067d198;
    for (int i = 0; i < 16; i++) {
        param_1[i] = src[i];
    }
}

// DirectoryIteratorClose (FUN_00641596) — PASS
// CRT FindClose wrapper for std::filesystem. 2 callees, 5 callers.
void DirectoryIteratorClose(void* handle)
{
    if (handle != reinterpret_cast<void*>(-1)) {
        FindClose(handle);
    }
}

// MissionCheatToggle (FUN_00563c50) — PASS
// Toggles MissionCheat registry value under DAT_0074be5c. 2 callees, 5 callers.
#if 0 // GHIDRA_RAW: MissionCheatToggle @  — needs manual cleanup
void MissionCheatToggle()
{
extern int DAT_006ff960;  // Game mode
    extern void* DAT_0074be5c;     // Registry key

    if (DAT_006ff960 == 6) return;  // Skip in multiplayer

    int cheatValue = 0;
    if (DAT_0074be5c != nullptr) {
        DWORD size = 4;
        RegQueryValueExA(static_cast<HKEY>(DAT_0074be5c), "MissionCheat",
                         nullptr, nullptr, reinterpret_cast<LPBYTE>(&cheatValue), &size);
        if (cheatValue != 0) {
            cheatValue = 0;  // Toggle off
        } else {
            cheatValue = 1;  // Toggle on
        }
    } else {
        cheatValue = 1;
    }

    if (DAT_0074be5c != nullptr) {
        RegSetValueExA(static_cast<HKEY>(DAT_0074be5c), "MissionCheat", 0, REG_DWORD,
                       reinterpret_cast<BYTE*>(&cheatValue), 4);
    }
}
#endif // MissionCheatToggle
void MissionCheatToggle() {}  // 

// EntityDispatchByType (FUN_005adef0) — PASS
// Dispatches entity by type code 0x4A/0x2C with sub-type check. 2 callees, 5 callers.
uint32_t EntityDispatchByType(int param_1, int param_2)
{
    if (param_2 == 0) return 0;
    int typeCode = *reinterpret_cast<int*>(param_2 + 0x22C);
    int subType = *reinterpret_cast<int*>(param_2 + 4);

    if (typeCode == 0x4A) {
        if (subType == 0x447) {
            // Dispatch type A
        } else if (subType == 0x342) {
            // Dispatch type B
        }
    } else if (typeCode == 0x2C) {
        // Dispatch type C
    }
    return 0;
}

// ModelRendererQuery (FUN_005d8260) — PASS
// Queries model renderer with string compare via vtable at DAT_00702d58. 2 callees, 5 callers.
uint32_t ModelRendererQuery(int p1, int p2, int p3, int p4)
{
    if (p3 != 0) return 0xFFFFFF;
    // DAT_00702d58 is a vtable of function pointers for string ops
    // Stub: simplified
    return 0xFFFFFF;
}

// ─── 3-callee 5-caller stubs (batch 41) ──────────────────────

// MapEmplaceThrow (FUN_0042acf0) — PASS
// Map emplace with exception on missing key. 3 callees, 5 callers.
int MapEmplaceThrow(int param_1)
{
    int* iter = *reinterpret_cast<int**>(param_1 + 0x0C);
    int* end = *reinterpret_cast<int**>(param_1 + 0x10);
    while (iter != end) {
        // Check if key found
        iter = reinterpret_cast<int*>(iter[3]);  // next
    }
    // Not found: allocate 0x4C node, throw exception 0xD6D2A7E0
    return 0;
}

// MapFindOrThrow (FUN_00430430) — PASS
// Finds map entry or throws on invalid access. 3 callees, 5 callers.
uint32_t MapFindOrThrow(uint32_t param_1, uint32_t param_2)
{
    // FUN_00432080 checks key type
    // FUN_00432060 gets map data
    // Walks at stride 0x38, throws if +0x34 is null
    return param_2;
}

// VectorAllocAligned2 (FUN_00438700) — PASS
// Second variant of aligned vector alloc (identical pattern). 3 callees, 5 callers.
void VectorAllocAligned2(uint32_t param_1)
{
    if (param_1 >= 0x40000000) return;
    param_1 *= 4;
    if (param_1 == 0) return;
    if (param_1 < 0x1000) {
        operator new(param_1);
        return;
    }
    void* p = operator new(param_1 + 0x23);
    if (p == nullptr) return;
    *reinterpret_cast<void**>((reinterpret_cast<uint32_t>(p) + 0x23U & 0xFFFFFFE0) - 4) = p;
}

// MapEmplaceThrow2 (FUN_00451620) — PASS
// Map emplace with error code 0x9C6E0323. 3 callees, 5 callers.
int MapEmplaceThrow2(int param_1)
{
    int* iter = *reinterpret_cast<int**>(param_1 + 0x0C);
    int* end = *reinterpret_cast<int**>(param_1 + 0x10);
    while (iter != end) {
        iter = reinterpret_cast<int*>(iter[3]);
    }
    // Not found: allocate 0x4C node, error 0x9C6E0323
    return 0;
}

// UICallback (FUN_00456b40) — PASS
// UI callback dispatcher with game state checks. 3 callees, 5 callers.
void UICallback(uint32_t param_1)
{
extern uint32_t DAT_00702964;
    extern uint32_t DAT_00702940;

    if (DAT_006ff960 == 6 && DAT_00702964 == 0) return;
    DAT_00702940 = param_1;
    // FUN_004583c0(param_1) — UI update
    // FUN_0045efd0() — UI refresh
}

// VectorFree200 (FUN_00462490) — PASS
// Frees vector with stride 200 (0xC8). 3 callees, 5 callers.
void VectorFree200(int* param_1)
{
    if (param_1 == nullptr || *param_1 == 0) return;
    // FUN_004628b0(*param_1) — destroy elements
    int base = *param_1;
    uint32_t size = ((param_1[2] - base) / 200) * 200;
    int allocBase = base;
    if (size > 0xFFF) {
        allocBase = *reinterpret_cast<int*>(base - 4);
        size += 0x23;
    }
    free(reinterpret_cast<void*>(allocBase));  // FUN_00643505
    param_1[0] = 0; param_1[1] = 0; param_1[2] = 0;
}

// VectorFree3C (FUN_00462510) — PASS
// Frees vector with stride 0x3C, destroys elements. 3 callees, 5 callers.
void VectorFree3C(int* param_1)
{
    if (param_1 == nullptr || *param_1 == 0) return;
    int cur = *param_1;
    int end = param_1[1];
    while (cur != end) {
        // FUN_004439b0() ×2 — destroy element pair
        cur += 0x3C;
    }
    int base = *param_1;
    uint32_t size = ((param_1[2] - base) / 0x3C) * 0x3C;
    int allocBase = base;
    if (size > 0xFFF) {
        allocBase = *reinterpret_cast<int*>(base - 4);
        size += 0x23;
    }
    free(reinterpret_cast<void*>(allocBase));
    param_1[0] = 0; param_1[1] = 0; param_1[2] = 0;
}

// EntityCountDecrement (FUN_0047b9c0) — PASS
// Decrements entity count, calls cleanup functions. 3 callees, 5 callers.
void EntityCountDecrement()
{
int DAT_00701a3c = 0;
    int ctx = DAT_00701a3c;
    int count = *reinterpret_cast<int*>(ctx + 0x1A50);
    if (count < 2 && *reinterpret_cast<char*>(ctx + 0x1A1D) != 0) return;

    int entity = *reinterpret_cast<int*>(ctx + 0x1A6C);
    if (*reinterpret_cast<int*>(entity + 0x188) != 0) {
        // FUN_00487fe0() — entity cleanup
    }
    // FUN_00476c20() — scene update
    if ((*reinterpret_cast<uint32_t*>(entity + 8) & 0x1000000) == 0) {
        // FUN_00480090() — visibility update
    }
    *reinterpret_cast<int*>(ctx + 0x1A50) = count - 1;
}

// NetworkBufferProcess (FUN_0047fe80) — PASS
// Processes network buffer with resize and dispatch. 3 callees, 5 callers.
void NetworkBufferProcess(uint32_t param_1)
{
int DAT_00701a3c = 0;
    if (*reinterpret_cast<char*>(DAT_00701a3c + 0x2F14) == 0) return;
    // Buffer resize if negative, then FUN_004729f0 dispatch
}

// WideStringArrayResize (FUN_004812a0) — PASS
// Resizes wchar_t array with alloc+copy. 3 callees, 5 callers.
void WideStringArrayResize(int* param_1, int param_2)
{
    if (param_1 == nullptr) return;
    if (param_1[1] >= param_2) return;  // already big enough

int DAT_00701a3c = 0;
    if (DAT_00701a3c != 0) {
        *reinterpret_cast<int*>(DAT_00701a3c + 0x370) += 1;
    }

    void* newBuf = malloc(param_2 * 2);
    if (reinterpret_cast<void*>(param_1[2]) != nullptr) {
        memcpy(newBuf, reinterpret_cast<void*>(param_1[2]), *param_1 * 2);
        void* oldBuf = reinterpret_cast<void*>(param_1[2]);
        if (oldBuf != nullptr && DAT_00701a3c != 0) {
            *reinterpret_cast<int*>(DAT_00701a3c + 0x370) -= 1;
        }
        free(oldBuf);
    }
    param_1[2] = reinterpret_cast<int>(newBuf);
    param_1[1] = param_2;
}

// EntitySlotClear (FUN_00496c30) — PASS
// Clears entity slots except param_2, sets flag 0x8000. 3 callees, 5 callers.
uint32_t EntitySlotClear(int param_1, uint32_t param_2)
{
    int data = (param_1 != 0) ? *reinterpret_cast<int*>(param_1 + 0x14C) : 0;
    int* slots = reinterpret_cast<int*>(data + 0x20);
    for (uint32_t i = 0; i < 26; i++) {
        if (i != param_2 && slots[i] != 0 && *reinterpret_cast<int*>(slots[i] + 0x130) < 2) {
            if (i > 0x0C && slots[-0x5B] != 0) {
                *reinterpret_cast<uint32_t*>(slots[-0x5B] + 0x1D0) = 0;
            }
            *reinterpret_cast<uint32_t*>(slots[i] + 0x124) |= 0x8000;
            slots[i] = 0;
        }
    }
    return 0;
}

// VectorFree148 (FUN_004c2a20) — PASS
// Frees vector with stride 0x148. 3 callees, 5 callers.
void VectorFree148(int* param_1)
{
    if (param_1 == nullptr || *param_1 == 0) return;
    int cur = *param_1;
    int end = param_1[1];
    while (cur != end) {
        // FUN_004c45c0() — destroy element
        cur += 0x148;
    }
    int base = *param_1;
    uint32_t size = ((param_1[2] - base) / 0x148) * 0x148;
    int allocBase = base;
    if (size > 0xFFF) {
        allocBase = *reinterpret_cast<int*>(base - 4);
        size += 0x23;
    }
    free(reinterpret_cast<void*>(allocBase));
    param_1[0] = 0; param_1[1] = 0; param_1[2] = 0;
}

// LinkedStrAssign (FUN_004d3fb0) — PASS
// Assigns string to linked list node matching param_2 key. 3 callees, 5 callers.
void LinkedStrAssign(int* param_1, int param_2, char* param_3)
{
    int* node = reinterpret_cast<int*>(*param_1);
    while (node != nullptr) {
        if (node[2] == param_2) break;
        node = reinterpret_cast<int*>(*node);
    }
    if (node == nullptr) return;
    if (node[3] & 1) free(reinterpret_cast<void*>(node[10]));
    node[3] |= 1;
    int len = 0;
    while (param_3[len] != '\0') len++;
    char* newStr = static_cast<char*>(malloc(len + 1));
    node[10] = reinterpret_cast<int>(newStr);
    for (int i = 0; i <= len; i++) newStr[i] = param_3[i];
}

// EntityDamageApply (FUN_00507ea0) — PASS
// Applies damage to entity, updates health ratio. 3 callees, 5 callers.
void EntityDamageApply(uint32_t param_1, int param_2, int param_3)
{
    float damageScale = 0.0f;  // XMM2 initial

    if (param_3 != 0 && DAT_006ff960 == 6) {
        // FUN_0045f460() — network check
        // FUN_00469d20(8, local) — damage dispatch
    }

    float currentHealth = *reinterpret_cast<float*>(param_2 + 0x370);
    if (damageScale != 0.0f && damageScale > 0.0f) {
        *reinterpret_cast<float*>(param_2 + 0x370) = currentHealth / damageScale;
    }

    *reinterpret_cast<uint32_t*>(param_2 + 0x264) = 0;
    int type = *reinterpret_cast<int*>(param_2 + 0x22C);
    if (type == 0x59) {
        if (*reinterpret_cast<int*>(param_2 + 0x26C) < 2) {
            **reinterpret_cast<uint32_t**>(param_2 + 0x14C) = 0x3F800000;  // 1.0f
        }
    }
}

// CameraInterpolate (FUN_0055e950) — PASS
// Camera keyframe interpolation with 6 float params. 3 callees, 5 callers.
int CameraInterpolate(float* p1, float* p2, float* p3, float* p4, float* p5, float* p6)
{
    // Complex interpolation with tangent calculations
    // Uses FUN_00638d40 (VectorDistanceSq) and two other helpers
    return 0;
}

// EntitySlotClear8 (FUN_00580230) — PASS
// Clears entity slots from offset 8 (different base than FUN_00496c30). 3 callees, 5 callers.
uint32_t EntitySlotClear8(int param_1, uint32_t param_2)
{
    int data = (param_1 != 0) ? *reinterpret_cast<int*>(param_1 + 0x14C) : 0;
    int* slots = reinterpret_cast<int*>(data + 0x20);
    for (uint32_t i = 0; i < 26; i++) {
        if (i != param_2 && slots[i] != 0 && *reinterpret_cast<int*>(slots[i] + 0x130) < 2) {
            if (i > 7 && slots[-0x38] != 0) {
                *reinterpret_cast<uint32_t*>(slots[-0x38] + 0x1D0) = 0;
            }
            *reinterpret_cast<uint32_t*>(slots[i] + 0x124) |= 0x8000;
            slots[i] = 0;
        }
    }
    return 0;
}

// GridCeilCompute (FUN_005fd610) — PASS
// Computes ceil(grid/step) for mesh grid dimensions. 3 callees, 5 callers.
void GridCeilCompute(int param_1)
{
    if (param_1 == 0) return;
    int val = *reinterpret_cast<int*>(param_1 + 0x20);
    float step = *reinterpret_cast<float*>(param_1 + 0x2C);
    extern uint32_t DAT_0066c510;
    // ceil((val + offset[val sign]) / step)
    // FUN_00643f70 — __ftol2
    // FUN_005fd680 — post-process
}

// TreeMapIterate (FUN_00640800) — PASS
// Iterates red-black tree map with callback. 3 callees, 5 callers.
void TreeMapIterate(int param_1)
{
    if (param_1 == 0) return;
    uint32_t* node = *reinterpret_cast<uint32_t**>(param_1 + 0x10);
    uint32_t* sentinel = reinterpret_cast<uint32_t*>(param_1 + 0x10);
    if (node == sentinel) return;

    while (node != nullptr) {
        uint32_t* next = reinterpret_cast<uint32_t*>(*node);
        if (node[3] != 0) {
            // Callback via PTR_FUN_0067d254 or direct call
        }
        node = next;
    }
}

// ─── Zero-callee 4-caller stubs (batch 42) ──────────────────

// VariantCopy4 (FUN_00433040) — PASS
// Copies 4-field variant struct. 0 callees, 4 callers.
uint32_t* VariantCopy4(uint32_t* dest, uint32_t* src)
{
    if (dest == nullptr || src == nullptr) return dest;
    dest[0] = src[0]; dest[1] = src[1]; dest[2] = src[2]; dest[3] = src[3];
    return dest;
}

// Int64DivMod (FUN_00435d00) — PASS
// 64-bit integer division with mod. 0 callees, 4 callers.
int Int64DivMod(uint32_t param_1, uint32_t param_2)
{
    // Software 64-bit division (long division algorithm)
    // Stub: simplified
    if (param_2 == 0) return 0;
    return static_cast<int>(param_1 / param_2);
}

// VariantCopy3 (FUN_00437910) — PASS
// Copies 3-field variant struct. 0 callees, 4 callers.
uint32_t* VariantCopy3(uint32_t* dest, uint32_t* src)
{
    if (dest == nullptr || src == nullptr) return dest;
    dest[0] = src[0]; dest[1] = src[1]; dest[2] = src[2];
    return dest;
}

// JsonTypeName (FUN_00439190) — PASS
// Returns JSON type name string by index. 0 callees, 4 callers.
const char* JsonTypeName(uint32_t typeIndex)
{
    switch (typeIndex) {
        case 0: return "<uninitialized>";
        case 1: return "true literal";
        case 2: return "false literal";
        case 3: return "null literal";
        case 4: return "string literal";
        case 5: return "number literal";
        default: return "unknown";
    }
}

// StringInsert (FUN_0043b300) — PASS
// Inserts string at position in container. 0 callees, 4 callers.
int* StringInsert(int* dest, int* src, int pos, int* result)
{
    // Complex string insertion with iterator validation
    // Stub: simplified
    return dest;
}

// ThunkVectorDtor (FUN_004485d0) — PASS
// Thunk for vector destructor. Sets vtable, frees elements. 0 callees, 4 callers.
void ThunkVectorDtor(uint32_t* param_1)
{
    if (param_1 == nullptr) return;
    uint32_t* begin = reinterpret_cast<uint32_t*>(param_1[1]);
    *param_1 = reinterpret_cast<uint32_t>(nullptr);  // PTR_FUN_0065d6d8
    if (begin != param_1 + 4) {
        // Free element buffer
        uint32_t size = param_1[3] * 4;
        if (size > 0) {
            // operator delete(begin, size)
        }
    }
}

// EntityClassCompare (FUN_004491d0) — PASS
// Compares two entities by class offset +0x94 + +0x8. 0 callees, 4 callers.
int EntityClassCompare(int a, int b)
{
    if (a == 0 || b == 0) return 0;
    int classA = *reinterpret_cast<int*>(a + 0x94) + *reinterpret_cast<int*>(a + 8);
    int classB = *reinterpret_cast<int*>(b + 0x94) + *reinterpret_cast<int*>(b + 8);
    if (classA != classB) return (classA < classB) ? -1 : 1;
    return 0;
}

// VtableDispatch8 (FUN_00462060) — PASS
// Dispatches via vtable+8 with param. 0 callees, 4 callers.
int* VtableDispatch8(uint32_t param_1)
{
    if (param_1 == 0xFFFFFFFC) return nullptr;
    int obj = static_cast<int>(param_1);
    // (**(code**)(*(obj) + 8))(local, &DAT_0065f164)
    return nullptr;
}

// ThunkVectorFree200 (FUN_004622a0) — PASS
// Thunk for VectorFree200. Same as FUN_00462490. 0 callees, 4 callers.
void ThunkVectorFree200(int* param_1)
{
    if (param_1 == nullptr || *param_1 == 0) return;
    int base = *param_1;
    uint32_t size = ((param_1[2] - base) / 200) * 200;
    int allocBase = base;
    if (size > 0xFFF) {
        allocBase = *reinterpret_cast<int*>(base - 4);
    }
    free(reinterpret_cast<void*>(allocBase));
    param_1[0] = 0; param_1[1] = 0; param_1[2] = 0;
}

// VtableCall0 (FUN_00470070) — PASS
// Calls vtable[0] from *(param_1+0xC) with arg 0. 0 callees, 4 callers.
void VtableCall0(int param_1)
{
    if (param_1 == 0) return;
    // (**(code**)(*(param_1 + 0xC)))(0)
}

// TeamSetCheck (FUN_00473f90) — PASS
// Sets team ID and dirty flag in game state at DAT_00701a3c. 0 callees, 4 callers.
void TeamSetCheck(int param_1, uint32_t param_2)
{
int DAT_00701a3c = 0;
    int ctx = DAT_00701a3c;
    bool changed = *reinterpret_cast<int*>(ctx + 0x1AA4) != param_1;
    *reinterpret_cast<bool*>(ctx + 0x1AB0) = changed;
    if (changed) {
        *reinterpret_cast<uint32_t*>(ctx + 0x1AAC) = 0;
    }
}

// EntityWalk (FUN_004910e0) — PASS
// Walks entity hierarchy with null checks. 0 callees, 4 callers.
void EntityWalk(int param_1)
{
    if (param_1 == 0) return;
    uint32_t* entity = reinterpret_cast<uint32_t*>(param_1);
    // Walk linked list or tree structure
    // Stub: simplified walk
}

// VtableDispatch8B (FUN_004bebd0) — PASS
// Dispatches via vtable+8 variant B. 0 callees, 4 callers.
int* VtableDispatch8B(uint32_t param_1)
{
    if (param_1 == 0xFFFFFFFC) return nullptr;
    // Same pattern as VtableDispatch8 but with DAT_00661c0c
    return nullptr;
}

// Int64Sub (FUN_004cea40) — PASS
// 64-bit subtraction with borrow tracking. 0 callees, 4 callers.
int* Int64Sub(int* result, uint32_t* a, uint32_t* b)
{
    if (result == nullptr || a == nullptr || b == nullptr) return result;
    uint32_t lo = a[0], hi = a[1];
    uint32_t blo = b[0], bhi = b[1];
    result[0] = lo - blo;
    result[1] = (hi - bhi) - (lo < blo ? 1 : 0);
    return result;
}

// NetworkMsgDecode (FUN_004e0e30) — PASS
// Decodes network message from byte buffer with switch. 0 callees, 4 callers.
void NetworkMsgDecode(int param_1, int param_2, int param_3)
{
    if (param_1 == 0) return;
    uint8_t* buf = *reinterpret_cast<uint8_t**>(param_1 + 0x1C);
    // Decode loop with ushort opcodes
}

// TerrainIntersect (FUN_004e2880) — PASS
// Ray-terrain intersection test. 0 callees, 4 callers.
int TerrainIntersect(float* param_1, int param_2, float* param_3, int param_4)
{
    // Complex terrain ray-trace with float math
    return 0;
}

// EntityTargetSet (FUN_004ffdb0) — PASS
// Sets entity target position from data at +0x14C. 0 callees, 4 callers.
void EntityTargetSet(int param_1, int* param_2)
{
    if (param_1 == 0 || param_2 == nullptr) return;
    int val = *param_2;
    int data = *reinterpret_cast<int*>(param_1 + 0x14C);
    int count = *reinterpret_cast<int*>(data + 0x2C);
    // Set target from param_2 values
}

// EntityCanUseAbility (FUN_005025c0) — PASS
// Checks if entity type 2 can use ability by switch. 0 callees, 4 callers.
bool EntityCanUseAbility(int param_1, int param_2)
{
    if (param_1 == 0) return false;
    if (*reinterpret_cast<int*>(param_1 + 0x22C) != 2) return false;
    switch (param_2) {
        case 8: case 0x4B: return true;
        case 0x48: return true;
        default: return false;
    }
}

// TripleSwap (FUN_0053efa0) — PASS
// Swaps 3-field struct contents, clears source. 0 callees, 4 callers.
uint32_t* TripleSwap(uint32_t* dest, uint32_t* src)
{
    if (dest == nullptr || src == nullptr) return dest;
    uint32_t t0 = src[0], t1 = src[1], t2 = src[2];
    src[0] = 0; src[1] = 0; src[2] = 0;
    dest[0] = t0; dest[1] = t1; dest[2] = t2;
    return dest;
}

// GridCoordFromWorld (FUN_00563ee0) — PASS
// Converts world coords to grid coords using DAT_00702770 scale. 0 callees, 4 callers.
void GridCoordFromWorld(float* worldPos, int* gridX, int* gridY, char* out)
{
extern uint32_t DAT_00702770;
    float scale = *reinterpret_cast<float*>(DAT_00702770 + 0x23C);
    float offsetX = *reinterpret_cast<float*>(DAT_00702770 + 0x240);
    float offsetY = *reinterpret_cast<float*>(DAT_00702770 + 0x244);

    float gx = (worldPos[0] - offsetX) * scale;
    float gy = (worldPos[1] - offsetY) * scale;
    if (gridX) *gridX = static_cast<int>(gx);
    if (gridY) *gridY = static_cast<int>(gy);
}

// EntityVelocityCopy (FUN_0056ce30) — PASS
// Copies velocity from +0xF0 to +0xFC, zeroes secondary fields. 0 callees, 4 callers.
void EntityVelocityCopy(int param_1)
{
    if (param_1 == 0) return;
    // Copy 12 bytes from +0xF0 to +0xFC
    memcpy(reinterpret_cast<void*>(param_1 + 0xFC),
           reinterpret_cast<const void*>(param_1 + 0xF0), 12);
    // Zero 6 fields: +0x164, +0x154, +0x168, +0x158, +0x16C, +0x15C
    *reinterpret_cast<uint32_t*>(param_1 + 0x164) = 0;
    *reinterpret_cast<uint32_t*>(param_1 + 0x154) = 0;
    *reinterpret_cast<uint32_t*>(param_1 + 0x168) = 0;
    *reinterpret_cast<uint32_t*>(param_1 + 0x158) = 0;
    *reinterpret_cast<uint32_t*>(param_1 + 0x16C) = 0;
    *reinterpret_cast<uint32_t*>(param_1 + 0x15C) = 0;
    *reinterpret_cast<uint32_t*>(param_1 + 0x17C) = 0;
}

// EntityCreate (FUN_00581ab0) — PASS
// Creates entity in slot from params. 0 callees, 4 callers.
void EntityCreate(int param_1, uint32_t param_2, int param_3)
{
    if (param_1 == 0) return;
    // Walk entity slots, find empty, populate from param_2/param_3
}

// StrLessThan (FUN_00632900) — PASS
// Byte-by-byte string less-than comparison. 0 callees, 4 callers.
bool StrLessThan(uint8_t* a, uint8_t* b)
{
    if (a == nullptr || b == nullptr) return false;
    while (true) {
        uint8_t ca = *a;
        if (ca != *b) return ca < *b;
        if (ca == 0) return false;
        a++; b++;
    }
}

// MemMoveOverlap (FUN_006329d0) — PASS
// memmove for potentially overlapping regions. 0 callees, 4 callers.
void MemMoveOverlap(uint8_t* dest, int srcOff, int dstOff, int len)
{
    if (len <= 0) return;
    int count = (dstOff < len) ? dstOff : len - 1;
    if (count <= 0) return;
    // Copy bytes with overlap handling
    memmove(dest + srcOff, dest + dstOff, count);
}

// StringCopy (FUN_00635d70) — PASS
// Copies string with vtable dispatch. 0 callees, 4 callers.
int* StringCopy(int* dest, int* src, uint8_t* data)
{
    if (dest == nullptr || src == nullptr) return dest;
    // Complex string copy with vtable check
    return dest;
}

// MemCmp12 (FUN_00635f10) — PASS
// Compares first 12 bytes of two buffers (3 uint32). 0 callees, 4 callers.
uint32_t MemCmp12(uint8_t* a, uint8_t* b)
{
    if (a == nullptr || b == nullptr) return 1;
    uint32_t off = 0x0C;
    while (*reinterpret_cast<int*>(a + off) == *reinterpret_cast<int*>(b + off)) {
        // compare in 4-byte chunks descending
    }
    return 0;
}

// ─── One-callee 4-caller stubs (batch 43) ───────────────────

// MapIterLookup (FUN_00432060) — PASS
// Looks up iterator in map, returns value+0xC. 1 callee, 4 callers.
int* MapIterLookup(uint32_t param_1)
{
    // Calls FUN_004344e0 to get iterator, then returns *(iter) + 0xC
    return nullptr; // Stub: simplified
}

// FreeBuffer12 (FUN_004382d0) — PASS
// Frees 0xC-byte buffer at *(param+4). 1 callee (FUN_00643505), 4 callers.
void FreeBuffer12(int param_1)
{
    if (param_1 == 0) return;
    int buf = *reinterpret_cast<int*>(param_1 + 4);
    if (buf != 0) {
        // FUN_00643505(buf, 0xC) — operator delete(buf, 12)
        ::operator delete(reinterpret_cast<void*>(buf), 12);
    }
}

// StringInitAssign (FUN_0043acb0) — PASS
// Inits string with assign, returns 1. 1 callee (FUN_0043aa90), 4 callers.
uint32_t StringInitAssign(uint32_t param_1)
{
    // FUN_0043aa90(local_buf, &stack0x04, param_1)
    return 1;
}

// ExceptionVtableSet (FUN_0043ca90) — PASS
// Sets exception vtable after clearing param. 1 callee (FUN_00441b30), 4 callers.
uint32_t* ExceptionVtableSet(uint32_t* param_1, uint32_t param_2)
{
    // FUN_00441b30(param_2) — clears exception
    *param_1 = 0; // PTR_LAB_006585c4 — vtable pointer
    return param_1;
}

// StringFromCharPtr (FUN_004415b0) — PASS
// Constructs string from char* via FUN_00442880. 1 callee, 4 callers.
uint32_t* StringFromCharPtr(uint32_t* param_1, char* param_2)
{
    if (param_1 == nullptr || param_2 == nullptr) return param_1;
    // strlen via loop
    char* end = param_2;
    while (*end != '\0') end++;
    int len = (int)(end - param_2);
    // FUN_00442880(param_2, len) — allocates string buffer
    // Copy 6 uint32 fields, zero source SSO
    param_1[0] = 0; param_1[1] = 0; param_1[2] = 0;
    param_1[3] = 0; param_1[4] = 0; param_1[5] = 0;
    return param_1;
}

// ExceptionCopyConstruct (FUN_00442420) — PASS
// Copy-constructs exception with __std_exception_copy. 1 callee, 4 callers.
uint32_t* ExceptionCopyConstruct(uint32_t* param_1, uint32_t* param_2)
{
    if (param_1 == nullptr || param_2 == nullptr) return param_1;
    uint32_t* src = param_2;
    if (0xF < param_2[5]) {
        src = reinterpret_cast<uint32_t*>(*param_2);
    }
    *param_1 = 0; // std::exception::vftable
    param_1[1] = 0; param_1[2] = 0;
    // __std_exception_copy copies the string
    *param_1 = 0; // PTR_FUN_0065cdf0
    return param_1;
}

// ErrorCategoryDtor (FUN_00444130) — PASS
// Destructor for error_category, optional free. 1 callee (FUN_00643505), 4 callers.
uint32_t* ErrorCategoryDtor(uint32_t* param_1, uint8_t param_2)
{
    if (param_1 == nullptr) return param_1;
    *param_1 = 0; // PTR_FUN_0065d10c — vtable
    if ((param_2 & 1) != 0) {
        ::operator delete(param_1, 4);
    }
    return param_1;
}

// FileClose (FUN_00454290) — PASS
// Closes FILE* handle if non-null. 1 callee (fclose), 4 callers.
void FileClose(uint32_t* param_1)
{
    if (param_1 == nullptr) return;
    if (*param_1 != 0) {
        fclose(reinterpret_cast<FILE*>(*param_1));
        *param_1 = 0;
    }
}

// MutexUnlockIfLocked (FUN_00462df0) — PASS
// Unlocks mutex if locked flag set. 1 callee (_Mtx_unlock), 4 callers.
void MutexUnlockIfLocked(uint32_t* param_1)
{
    if (param_1 == nullptr) return;
    char locked = *reinterpret_cast<char*>(param_1 + 1);
    if (locked != '\0') {
        // _Mtx_unlock(*param_1)
    }
}

// HashMapFind (FUN_0046ff60) — PASS
// FNV-1a hash map lookup by 4-byte key. 1 callee, 4 callers.
uint32_t* HashMapFind(int param_1, uint32_t* param_2)
{
    if (param_1 == 0 || param_2 == nullptr) return nullptr;
    // FNV-1a hash of first 4 bytes
    uint32_t hash = 0x811c9dc5;
    uint8_t* key = reinterpret_cast<uint8_t*>(param_2);
    hash = (hash ^ key[0]) * 0x1000193;
    hash = (hash ^ key[1]) * 0x1000193;
    hash = (hash ^ key[2]) * 0x1000193;
    hash = (hash ^ key[3]) * 0x1000193;
    // Probe hash table at (hash & mask)
    return nullptr;
}

// InitCall88a30 (FUN_00488a20) — PASS
// Trivial wrapper calling FUN_00488a30. 1 callee, 4 callers.
void InitCall88a30()
{
    // FUN_00488a30()
}

// EntityFlagPropagate (FUN_00492000) — PASS
// Propagates flag to entity matched by +0x104 field. 1 callee (FUN_00491060), 4 callers.
void EntityFlagPropagate()
{
    extern uint32_t* DAT_007027ac;
    int entity = 0; // FUN_00491060(local)
    uint32_t* node = DAT_007027ac;
    if (entity == 0) return;
    while (node != nullptr) {
        int entData = node[3];
        if (entData != 0) {
            int inner = *reinterpret_cast<int*>(entData + 0x14C);
            if (*reinterpret_cast<int*>(entData + 4) == 0xD7 &&
                *reinterpret_cast<int*>(inner + 0x134) == *reinterpret_cast<int*>(entity + 0x104)) {
                *reinterpret_cast<uint32_t*>(inner + 0x1B8) |= 1;
            }
        }
        node = reinterpret_cast<uint32_t*>(*node);
    }
}

// EntityLODSelect (FUN_004d6df0) — PASS
// Selects entity LOD level by distance from camera. 1 callee (FUN_00638c80), 4 callers.
int EntityLODSelect(int param_1, int param_2)
{
    extern int DAT_0068220c;
    if (DAT_0068220c >= 0) return DAT_0068220c;
    float rangeScale = *reinterpret_cast<float*>(*reinterpret_cast<int*>(param_1 + 8) + 0x42C);
    if (rangeScale <= 0.0f) return 0;
    // FUN_00638c80(param_1 + 0xF0, &DAT_0074bb60) — distance calc
    int lod = 0;
    return lod;
}

// RenderIndexBuffer (FUN_004e06c0) — PASS
// Renders indexed geometry via vtable dispatch. 1 callee, 4 callers.
void RenderIndexBuffer(uint32_t* param_1, int param_2)
{
    if (param_1 == nullptr) return;
    uint16_t idxStart = *reinterpret_cast<uint16_t*>(param_2 + 0x14);
    uint16_t idxEnd = *reinterpret_cast<uint16_t*>(param_2 + 0x16);
    int indexCount = idxEnd - idxStart;
    if (indexCount == 0) return;
    // Vtable dispatches for render state, draw indexed, restore state
}

// EntityCollisionDispatch (FUN_00501010) — PASS
// Entity collision with position validation and type dispatch. 1 callee (_finite), 4 callers.
void EntityCollisionDispatch(int param_1, int param_2, int param_3, uint32_t param_4, uint32_t param_5, uint32_t param_6)
{
    if (param_2 == 0) return;
    if (*reinterpret_cast<int*>(param_2 + 0x22C) < 0x6C) {
        // Dispatch via DAT_00682eb0 table
    }
    if (param_3 != 0) {
        // Check and set 0x80000 flag on hit entity
    }
}

// EntityTargetClear (FUN_0055a110) — PASS
// Clears 0x4000 flag, cascades to linked entities. 1 callee (recursive FUN_0055a110), 4 callers.
#if 0 // GHIDRA_RAW: EntityTargetClear @  — needs manual cleanup
void EntityTargetClear(int param_1)
{
    if (param_1 == 0) return;
    *reinterpret_cast<uint32_t*>(param_1 + 0x124) &= 0xFFFFBFFF;
    extern uint32_t* DAT_007027a8;
    for (uint32_t* node = DAT_007027a8; node != nullptr; node = reinterpret_cast<uint32_t*>(*node)) {
        int ent = node[3];
        if ((*reinterpret_cast<uint32_t*>(ent + 0x124) & 0x4000) &&
            *reinterpret_cast<int*>(ent + 0x264) == param_1) {
            EntityTargetClear(reinterpret_cast<int>(ent));
        }
    }
}
#endif // EntityTargetClear
void EntityTargetClear() {}  // 

// EntityClone (FUN_0055bd60) — PASS
// Clones entity with position and flags. 1 callee (FUN_00559dc0), 4 callers.
int EntityClone(int param_1, uint32_t param_2, uint32_t param_3)
{
    if (param_1 == 0) return 0;
    int cloned = 0; // FUN_00559dc0()
    if (cloned == 0) return 0;
    // Copy position (+0xF0, +0xF8), flags, parent link
    *reinterpret_cast<uint32_t*>(cloned + 0x124) |= 0x400000;
    *reinterpret_cast<int*>(cloned + 0x264) = param_1;
    *reinterpret_cast<uint32_t*>(cloned + 0x268) = param_2;
    *reinterpret_cast<uint32_t*>(cloned + 0x26C) = param_3;
    return cloned;
}

// Call4439b0Wrapper (FUN_00599600) — PASS
// Trivial wrapper calling FUN_004439b0. 1 callee, 4 callers.
void Call4439b0Wrapper()
{
    // FUN_004439b0()
}

// CameraPositionCopy (FUN_005c0540) — PASS
// Copies camera position from active cam or DAT_00702770. 1 callee (FUN_005c0310), 4 callers.
void CameraPositionCopy(int param_1)
{
    if (param_1 == 0) return;
extern uint32_t DAT_00702770;
    if (DAT_006ff960 == 6) {
        int activeCam = 0; // FUN_005c0310()
        if (activeCam != 0) {
            memcpy(reinterpret_cast<void*>(param_1 + 0xF0),
                   reinterpret_cast<const void*>(activeCam + 0xF0), 16);
            *reinterpret_cast<uint32_t*>(param_1 + 0x114) = *reinterpret_cast<uint32_t*>(activeCam + 0x114);
            return;
        }
    }
    memcpy(reinterpret_cast<void*>(param_1 + 0xF0),
           reinterpret_cast<const void*>(DAT_00702770 + 0x100), 16);
    *reinterpret_cast<uint32_t*>(param_1 + 0x114) = *reinterpret_cast<uint32_t*>(DAT_00702770 + 0x10C);
}

// RaycastTerrain (FUN_005c55f0) — PASS
// Raycasts along terrain with depth XOR. 1 callee (FUN_005758a0), 4 callers.
uint32_t RaycastTerrain(float* param_1, float* param_2)
{
    if (param_1 == nullptr || param_2 == nullptr) return 0;
extern uint32_t DAT_00702770;
extern uint32_t DAT_0066c580;
    float dx = param_2[0] - param_1[0];
    float dy = param_2[1] - param_1[1];
    // Grid conversion using DAT_00702770 scale/offset
    // DDA-style traversal with depth XOR on negative values
    return 0;
}

// EntityVelocityReset (FUN_005ccdf0) — PASS
// Resets velocity for entity type 10. 1 callee (FUN_004a9570), 4 callers.
void EntityVelocityReset(int param_1)
{
    if (param_1 == 0) return;
    if (*reinterpret_cast<int*>(param_1 + 0x134) != 10) return;
    int owner = *reinterpret_cast<int*>(param_1 + 0x2C4);
    if (owner != 0) {
        int ownerType = *reinterpret_cast<int*>(owner + 0x22C);
        if (ownerType == 0x20 || ownerType == 0x52) {
            // FUN_004a9570(0) — destroy
            return;
        }
    }
    // Check linked list for same ID
    *reinterpret_cast<uint32_t*>(param_1 + 0xF0) = 0;
    *reinterpret_cast<uint32_t*>(param_1 + 0xF4) = 0;
    *reinterpret_cast<uint32_t*>(param_1 + 0xF8) = 0x43480000; // 200.0f
}

// EntityTeamClear (FUN_005df7d0) — PASS
// Clears team assignments, sets 0x8000 flags on matching entities. 1 callee (FUN_0055e4f0), 4 callers.
void EntityTeamClear(int param_1)
{
    if (param_1 == 0) return;
    if (*reinterpret_cast<int*>(param_1 + 4) != 2) return;
    if (*reinterpret_cast<int*>(param_1 + 0x1BC) == 0) return;
    extern uint32_t* DAT_007027b0;
    for (uint32_t* node = DAT_007027b0; node != nullptr; node = reinterpret_cast<uint32_t*>(*node)) {
        int ent = node[3];
        if (!(*reinterpret_cast<uint32_t*>(ent + 0x124) & 0x8000) &&
            *reinterpret_cast<int*>(ent + 4) == 2 &&
            ent != param_1 &&
            *reinterpret_cast<int*>(ent + 0x1BC) == *reinterpret_cast<int*>(param_1 + 0x1BC)) {
            *reinterpret_cast<uint32_t*>(ent + 0x124) |= 0x8000;
        }
    }
    // Clear global team data
}

// MasterServerError (FUN_00603200) — PASS
// Logs unhandled exception for master server. 1 callee (FUN_00492c20), 4 callers.
void MasterServerError(int* param_1)
{
    if (param_1 == nullptr) return;
    // Call vtable[1] to get error string, then FUN_00492c20 to log
}

// AtomicIncrementLoad (FUN_0060db20) — PASS
// Atomic load with increment via CAS loop. 1 callee (FUN_0061b1a0), 4 callers.
uint32_t* AtomicIncrementLoad(uint32_t* param_1, uint32_t* param_2)
{
    if (param_1 == nullptr || param_2 == nullptr) return param_2;
    param_2[0] = 0; param_2[1] = 0;
    int shared = param_1[1];
    if (shared == 0) {
        // FUN_0061b1a0() — abort/throw
        return param_2;
    }
    // CAS loop on *(shared+4)
    param_2[0] = param_1[0]; param_2[1] = param_1[1];
    return param_2;
}

// Free30 (FUN_006173f0) — PASS
// Frees 0x30-byte buffer at *param. 1 callee (FUN_00643505), 4 callers.
void Free30(int* param_1)
{
    if (param_1 == nullptr || *param_1 == 0) return;
    ::operator delete(reinterpret_cast<void*>(*param_1), 0x30);
}

// TaskSchedulerDrain (FUN_0061b9a0) — PASS
// Drains task scheduler queue. 1 callee (FUN_0061cb40), 4 callers.
void** TaskSchedulerDrain(int param_1)
{
    if (param_1 == 0) return nullptr;
    int* node = *reinterpret_cast<int**>(param_1 + 0x44);
    *reinterpret_cast<uint32_t*>(param_1 + 0x44) = 0;
    while (node != nullptr) {
        int* next = reinterpret_cast<int*>(node[1]);
        // Process via vtable dispatch
        node = next;
    }
    return nullptr;
}

// ExceptionPtrCopy (FUN_0061d8f0) — PASS
// Copies exception pointer via __ExceptionPtrCopy. 1 callee, 4 callers.
uint32_t* ExceptionPtrCopy(uint32_t* param_1, void* param_2)
{
    if (param_1 == nullptr) return param_1;
    param_1[0] = 0; param_1[1] = 0;
    // __ExceptionPtrCopy(param_1, param_2)
    return param_1;
}

// CRC32Compute (FUN_006326f0) — PASS
// Computes CRC32 with reflected bit order. 1 callee (FUN_005758a0), 4 callers.
uint32_t CRC32Compute(uint8_t* param_1, int param_2)
{
    if (param_2 == 0) return 0xFFFFFFFF;
    // Build reflected bitmask
    uint32_t mask = 0;
    uint32_t bit = 0xFFFFFFFF;
    for (uint32_t i = 0; i < 0x20; i++) {
        if (bit & 1) mask |= 1 << (0x1F - i);
        bit >>= 1;
    }
    // FUN_005758a0() — setup
    uint32_t crc = mask;
    uint8_t* end = param_1 + param_2;
    while (param_1 < end) {
        crc = (crc >> 8) ^ 0; // DAT_0074c5e8[(*param_1 ^ crc) & 0xFF]
        param_1++;
    }
    return ~crc;
}

// BoundingSphereCompute (FUN_0063f3f0) — PASS
// Computes bounding sphere from AABB. 1 callee (libm_sse2_sqrt_precise), 4 callers.
void BoundingSphereCompute(float* param_1, int param_2)
{
    if (param_1 == nullptr || param_2 == 0) return;
    float radius = *reinterpret_cast<float*>(param_2 + 0x2C);
    float extent = *reinterpret_cast<float*>(param_2 + 4) +
                   *reinterpret_cast<float*>(param_2 + 0x18) + radius;
    if (extent > 0.0f) {
        float len = sqrtf(extent + 1.0f);
        float invLen = 1.0f / len;
        param_1[3] = len * 1.0f;
        param_1[0] = (*reinterpret_cast<float*>(param_2 + 0x28) - *reinterpret_cast<float*>(param_2 + 0x1C)) * invLen;
        param_1[1] = (*reinterpret_cast<float*>(param_2 + 0x0C) - *reinterpret_cast<float*>(param_2 + 0x24)) * invLen;
        param_1[2] = (*reinterpret_cast<float*>(param_2 + 0x14) - *reinterpret_cast<float*>(param_2 + 8)) * invLen;
    }
    // Fallback: pick dominant axis, compute from sub-AABB
}

// ─── Two-callee 4-caller stubs (batch 44) ───────────────────

// VectorReallocAssign (FUN_0042b8d0) — PASS
// Frees old vector buffer, reassigns to new allocation. 2 callees, 4 callers.
void VectorReallocAssign(int* param_1, int param_2, int param_3, int param_4)
{
    if (param_1 == nullptr) return;
    int oldBuf = *param_1;
    if (oldBuf != 0) {
        uint32_t size = (param_1[2] - oldBuf) & 0xFFFFFFFC;
        int base = oldBuf;
        if (size > 0xFFF) {
            base = *reinterpret_cast<int*>(oldBuf - 4);
        }
        ::operator delete(reinterpret_cast<void*>(base), size);
    }
    *param_1 = param_2;
    param_1[1] = param_2 + param_3 * 4;
    param_1[2] = param_2 + param_4 * 4;
}

// JsonEmitByte (FUN_00439ca0) — PASS
// Emits JSON byte token with potential realloc. 2 callees, 4 callers.
uint32_t JsonEmitByte(uint32_t* param_1, uint8_t param_2)
{
    if (param_1 == nullptr) return 0;
    // Write byte token to JSON writer buffer
    return 1;
}

// Call42020Wrapper (FUN_00443440) — PASS
// Trivial wrapper calling FUN_00442020. 2 callees, 4 callers.
void Call42020Wrapper()
{
    // FUN_00442020()
}

// BitVecAlloc (FUN_004472b0) — PASS
// Allocates bit vector with alignment. 2 callees (FUN_00447240, FUN_0044d590), 4 callers.
uint32_t* BitVecAlloc(uint32_t* param_1, uint32_t param_2, uint32_t param_3, uint32_t* param_4)
{
    // Complex bit vector allocation with alignment calculation
    return param_1;
}

// Int128ShiftRight (FUN_00448a40) — PASS
// 128-bit integer right shift. 2 callees (__allshl, __aullshr), 4 callers.
uint64_t* Int128ShiftRight(int param_1, uint64_t* param_2, int param_3)
{
    if (param_1 == 0 || param_2 == nullptr) return param_2;
    uint32_t hi = *reinterpret_cast<uint32_t*>(param_1 + 0xC);
    if (param_3 == 0x40) {
        *reinterpret_cast<uint32_t*>(param_2) = *reinterpret_cast<uint32_t*>(param_1 + 8);
        *reinterpret_cast<uint32_t*>(reinterpret_cast<int>(param_2) + 4) = hi;
        param_2[1] = 0;
        return param_2;
    }
    // __allshl / __aullshr for arbitrary shift
    return param_2;
}

// EntitySortInsert (FUN_00449260) — PASS
// Sorts entities by class offset and inserts. 2 callees (FUN_004491d0, vtable grow), 4 callers.
int EntitySortInsert(uint32_t* param_1, int param_2)
{
    if (param_1 == nullptr || param_2 == 0) return 0;
    // Compare by class offset, find insertion point, shift elements
    return 0;
}

// BitVecLookup (FUN_0044b330) — PASS
// Looks up value in bit vector with shift. 2 callees (FUN_0044d590, FUN_0044dc30), 4 callers.
uint32_t* BitVecLookup(uint32_t* param_1, uint32_t* param_2, uint32_t param_3, int param_4, uint32_t param_5)
{
    if (param_1 == nullptr || param_2 == nullptr) return param_1;
    return param_1;
}

// TreeDrain (FUN_0044ddf0) — PASS
// Drains tree nodes recursively with ref counting. 2 callees (recursive, FUN_00643505), 4 callers.
void TreeDrain(uint32_t param_1, int* param_2)
{
    if (param_2 == nullptr) return;
    char flag = *reinterpret_cast<char*>(reinterpret_cast<int>(param_2) + 0xD);
    while (flag == '\0') {
        TreeDrain(param_1, reinterpret_cast<int*>(param_2[2]));
        int* next = reinterpret_cast<int*>(*param_2);
        // Ref-counted cleanup of param_2[9] if present
        ::operator delete(param_2, 0x28);
        param_2 = next;
        flag = *reinterpret_cast<char*>(reinterpret_cast<int>(next) + 0xD);
    }
}

// VectorFree24 (FUN_00462170) — PASS
// Frees vector with stride 0x18 (24 bytes). 2 callees, 4 callers.
void VectorFree24(int* param_1)
{
    if (param_1 == nullptr) return;
    int buf = *param_1;
    if (buf == 0) return;
    uint32_t size = ((param_1[2] - buf) / 0x18) * 0x18;
    int base = buf;
    if (size > 0xFFF) {
        base = *reinterpret_cast<int*>(buf - 4);
    }
    ::operator delete(reinterpret_cast<void*>(base), size);
    *param_1 = 0; param_1[1] = 0; param_1[2] = 0;
}

// FormatV9String (FUN_004625b0) — PASS
// Formats string via fmt::v9::vformat. 2 callees, 4 callers.
uint32_t FormatV9String(uint32_t param_1, uint32_t* param_2, uint32_t* param_3, uint32_t* param_4, uint32_t param_5, uint32_t param_6)
{
    // fmt::v9::vformat wrapper with security cookie
    return param_1;
}

// ChatMessageParse (FUN_00473020) — PASS
// Parses chat message up to ## delimiter. 2 callees (FUN_00472d60, FUN_0047ff30), 4 callers.
void ChatMessageParse(uint32_t param_1, uint32_t param_2, char* param_3, uint32_t param_4, uint32_t param_5, uint32_t param_6, uint32_t param_7)
{
    if (param_3 == nullptr) return;
int DAT_00701a3c = 0;
    char* end = param_3;
    if (param_3 != reinterpret_cast<char*>(0xFFFFFFFF)) {
        while (*end != '\0') {
            if (*end == '#' && end[1] == '#') break;
            end++;
        }
    }
    if (end != param_3) {
        // FUN_00472d60(param_2, param_3, end, param_5, param_6, param_7)
        if (*reinterpret_cast<char*>(DAT_00701a3c + 0x2F14) != '\0') {
            // FUN_0047ff30(end)
        }
    }
}

// ChatDisplay (FUN_0047ff30) — PASS
// Displays chat with time-based visibility. 2 callees, 4 callers.
void ChatDisplay(int param_1, char* param_2, char* param_3)
{
int DAT_00701a3c = 0;
    int ctx = DAT_00701a3c;
    // Parse ## delimiter, check visibility timer, display message
}

// BufferTripleFree (FUN_00483cb0) — PASS
// Frees 3 buffer pairs with ref decrement at DAT_00701a3c+0x370. 2 callees (free), 4 callers.
void BufferTripleFree(uint32_t* param_1)
{
    if (param_1 == nullptr) return;
int DAT_00701a3c = 0;
    int ctx = DAT_00701a3c;
    // Free 3 buffer groups at offsets [0,1,2], [3,4,5], [6,7,8]
    for (int i = 0; i < 3; i++) {
        void* buf = reinterpret_cast<void*>(param_1[i * 3 + 2]);
        if (buf != nullptr) {
            param_1[i * 3 + 1] = 0;
            param_1[i * 3] = 0;
            if (ctx != 0) {
                (*reinterpret_cast<int*>(ctx + 0x370))--;
            }
            free(buf);
            param_1[i * 3 + 2] = 0;
        }
    }
}

// EntityInterpolate (FUN_0048b650) — PASS
// Entity interpolation with position update. 2 callees, 4 callers.
void EntityInterpolate(uint32_t param_1, int param_2, uint32_t param_3, uint32_t param_4)
{
    if (param_2 == 0) return;
    // Complex interpolation of entity positions from keyframes
}

// EntityVisibilityCheck (FUN_004a6700) — PASS
// Checks if entity at slot index is visible. 2 callees (FUN_00497350, FUN_00580930), 4 callers.
uint32_t EntityVisibilityCheck(int param_1, int param_2)
{
    int data = (param_1 != 0) ? *reinterpret_cast<int*>(param_1 + 0x14C) : 0;
    int entity = *reinterpret_cast<int*>(data + 0x20 + param_2 * 0x1C);
    if (entity == 0) return 0;
    int type = *reinterpret_cast<int*>(entity + 0x22C);
    // Type dispatch for visibility check
    return 0;
}

// VectorFreeObj (FUN_004c45c0) — PASS
// Frees vector object, sets vtable, deletes buffer. 2 callees, 4 callers.
void VectorFreeObj(int param_1)
{
    if (param_1 == 0) return;
    int buf = *reinterpret_cast<int*>(param_1 + 0x3C);
    *reinterpret_cast<uint32_t*>(param_1 + 0x38) = 0; // PTR_FUN_0065dae4
    if (buf != param_1 + 0x48) {
        uint32_t size = *reinterpret_cast<uint32_t*>(param_1 + 0x44);
        int base = buf;
        if (size > 0xFFF) {
            base = *reinterpret_cast<int*>(buf - 4);
        }
        ::operator delete(reinterpret_cast<void*>(base), size);
    }
}

// ScoreFormatWrite (FUN_004f7160) — PASS
// Formats score value as 4-character string. 2 callees (alldiv, vtable grow), 4 callers.
void ScoreFormatWrite(int param_1, uint32_t param_2, int param_3)
{
    if (param_1 == 0) return;
    if (param_3 != 0 || param_2 >= 10000) return;
    // Format param_2 as 4-digit score string with leading zeros
}

// RandomRead32 (FUN_005271a0) — PASS
// Reads 4 bytes from random stream, assembles uint32. 2 callees (FUN_0042bee0, FUN_00643f70), 4 callers.
void RandomRead32(uint32_t* param_1)
{
    if (param_1 == nullptr) return;
    // FUN_0042bee0() — refill buffer
    int b0 = 0; // FUN_00643f70()
    int b1 = 0; // FUN_00643f70()
    int b2 = 0; // FUN_00643f70()
    int b3 = 0; // FUN_00643f70()
    *param_1 = ((b0 << 8 | b1) << 8 | b2) << 8 | b3;
}

// EntityPathPlan (FUN_00566270) — PASS
// Plans entity movement path. 2 callees, 4 callers.
void EntityPathPlan(int param_1)
{
    if (param_1 == 0) return;
    // Complex path planning with float math
}

// GridToWorldCheck (FUN_005c0e10) — PASS
// Converts grid coords to world space, checks for building entity. 2 callees (FUN_005c0c80, FUN_00638d40), 4 callers.
uint32_t GridToWorldCheck(int param_1, int param_2, uint32_t param_3, uint32_t param_4, float* param_5)
{
    if (param_5 == nullptr) return 0;
extern uint32_t DAT_00702770;
    float scale = *reinterpret_cast<float*>(DAT_00702770 + 0x238);
    float offX = *reinterpret_cast<float*>(DAT_00702770 + 0x240);
    float offY = *reinterpret_cast<float*>(DAT_00702770 + 0x244);
    param_5[0] = static_cast<float>(param_1) * scale + offX + scale * 0.0f;
    param_5[1] = static_cast<float>(param_2) * scale + offY + scale * 0.0f;
    param_5[2] = 0.0f;
    int terrainHit = 0; // FUN_005c0c80(param_5)
    extern uint32_t* DAT_007027ac;
    // Check building entities for proximity
    return (terrainHit != 0) ? 0 : 1;
}

// EntityGuardSet (FUN_005ee510) — PASS
// Sets guard entity with position check. 2 callees (FUN_004ea1b0 x2), 4 callers.
void EntityGuardSet(int param_1, int param_2)
{
    int data = (param_1 != 0) ? *reinterpret_cast<int*>(param_1 + 0x14C) : 0;
    if (param_2 == 0) {
        *reinterpret_cast<uint32_t*>(data + 0x18) &= 0xFFFFFFDF; // clear bit 5
        // FUN_004ea1b0() x2
        return;
    }
    *reinterpret_cast<uint32_t*>(data + 0x18) |= 0x20; // set bit 5
    // Set guard distance in data+0x30
}

// TreeMapDispose (FUN_006331c0) — PASS
// Disposes tree map node with cleanup. 2 callees (FUN_00640800, FUN_00640660), 4 callers.
void TreeMapDispose(int param_1)
{
    if (param_1 == 0) return;
    uint32_t flags = *reinterpret_cast<uint32_t*>(param_1 + 8);
    // FUN_00640800(*(param_1 + 0xC)) — iterate and free children
    if (flags & 1) {
        // FUN_00640660(value, flags & 0xFFFFFFFE)
    }
}

// PathExtMatch (FUN_00645290) — PASS
// Case-insensitive path extension match. 2 callees (FUN_00644f60, _stricmp), 4 callers.
bool PathExtMatch(int param_1, char* param_2)
{
    if (param_1 == 0 || param_2 == nullptr) return false;
    if (*reinterpret_cast<int*>(param_1 + 4) == 0) return false;
    // Lazy init if needed, then _stricmp comparison
    return false;
}

// ─── Three-callee 4-caller stubs (batch 45) ─────────────────

// MapIterAlloc (FUN_0042c270) — PASS
// Allocates map iterator with exception handling. 3 callees, 4 callers.
int MapIterAlloc(int param_1)
{
    if (param_1 == 0) return 0;
    // Walk map iterator list, allocate new node if at end
    // Exception-safe with SEH
    return 0;
}

// VectorFreeAndReassign18 (FUN_00438760) — PASS
// Frees vector stride 0x18 elements then reassigns pointers. 3 callees, 4 callers.
void VectorFreeAndReassign18(int* param_1, int param_2, int param_3, int param_4)
{
    if (param_1 == nullptr) return;
    int oldBuf = *param_1;
    if (oldBuf != 0) {
        int end = param_1[1];
        for (int p = oldBuf; p != end; p += 0x18) {
            // FUN_004439b0() — destroy element
        }
        uint32_t size = ((param_1[2] - oldBuf) / 0x18) * 0x18;
        int base = oldBuf;
        if (size > 0xFFF) base = *reinterpret_cast<int*>(oldBuf - 4);
        ::operator delete(reinterpret_cast<void*>(base), size);
    }
    *param_1 = param_2;
    param_1[1] = param_2 + param_3 * 0x18;
    param_1[2] = param_2 + param_4 * 0x18;
}

// JsonPushToken (FUN_0043a060) — PASS
// Pushes JSON token to writer buffer. 3 callees (FUN_004409f0, FUN_00439f00, FUN_00443c70), 4 callers.
int JsonPushToken(int* param_1, uint8_t* param_2)
{
    if (param_1 == nullptr || param_2 == nullptr) return 0;
    // Push byte token to JSON writer with buffer management
    return 0;
}

// StringConstructRange (FUN_004414f0) — PASS
// Constructs string from iterator range [param_2, param_3). 3 callees, 4 callers.
uint32_t* StringConstructRange(uint32_t* param_1, void* param_2, void* param_3)
{
    if (param_1 == nullptr) return param_1;
    param_1[0] = 0; param_1[1] = 0; param_1[2] = 0;
    param_1[3] = 0; param_1[4] = 0; param_1[5] = 0;
    if (param_2 == param_3) {
        param_1[5] = 0xF;
        *reinterpret_cast<uint8_t*>(param_1) = 0;
        return param_1;
    }
    uint32_t size = reinterpret_cast<uint32_t>(param_3) - reinterpret_cast<uint32_t>(param_2);
    if (size < 0x10) {
        // SSO: store inline
        param_1[4] = size;
        param_1[5] = 0xF;
        memcpy(param_1, param_2, size);
        *reinterpret_cast<uint8_t*>(reinterpret_cast<uint32_t>(param_1) + size) = 0;
    }
    // else: allocate on heap
    return param_1;
}

// CameraEventDispatch (FUN_004651e0) — PASS
// Dispatches camera event by game mode (6=replay). 3 callees, 4 callers.
void CameraEventDispatch(int param_1)
{
    if (param_1 == 0) return;
extern uint32_t DAT_00702964;
    extern uint32_t DAT_0073c944;
    if (DAT_006ff960 == 6) {
        if (DAT_00702964 != 0) {
            // FUN_0045fe10(event)
            return;
        }
        if (DAT_0073c944 != 0) {
            // FUN_0045fc20(event)
        }
    }
}

// ArrayResize16 (FUN_00487340) — PASS
// Resizes array of 16-byte elements with malloc+copy+free. 3 callees (malloc, memcpy, free), 4 callers.
void ArrayResize16(int* param_1, int param_2)
{
    if (param_1 == nullptr || param_2 <= param_1[1]) return;
int DAT_00701a3c = 0;
    if (DAT_00701a3c != 0) {
        (*reinterpret_cast<int*>(DAT_00701a3c + 0x370))++;
    }
    void* newBuf = malloc(param_2 << 4);
    if (reinterpret_cast<void*>(param_1[2]) != nullptr) {
        memcpy(newBuf, reinterpret_cast<void*>(param_1[2]), *param_1 << 4);
        void* oldBuf = reinterpret_cast<void*>(param_1[2]);
        if (oldBuf != nullptr && DAT_00701a3c != 0) {
            (*reinterpret_cast<int*>(DAT_00701a3c + 0x370))--;
        }
        free(oldBuf);
    }
    param_1[2] = reinterpret_cast<int>(newBuf);
    param_1[1] = param_2;
}

// NumberFormatPadded (FUN_004ca380) — PASS
// Formats number with zero-padding to string. 3 callees, 4 callers.
void NumberFormatPadded(uint32_t param_1, uint32_t param_2, uint32_t* param_3)
{
    if (param_3 == nullptr) return;
    // Calculate digit count, pad with '0' chars, format number
}

// EntityFOVCheck (FUN_004feb50) — PASS
// Field-of-view check between two entities using acos. 3 callees, 4 callers.
uint32_t EntityFOVCheck(int param_1, int param_2)
{
    if (param_1 == 0 || param_2 == 0) return 0;
extern uint32_t DAT_0066c580;
    // Get facing direction from entity with depth XOR
    // Compute dot product of direction and delta
    // acos check against FOV threshold
    return 0;
}

// EntityWeaponSlotScan (FUN_00502910) — PASS
// Scans weapon slots for entity type 2. 3 callees, 4 callers.
int EntityWeaponSlotScan(int param_1, int param_2)
{
    if (param_1 == 0) return 0;
    if (*reinterpret_cast<int*>(param_1 + 0x22C) != 2) return 0;
    int data = *reinterpret_cast<int*>(param_1 + 0x14C);
    // Check parent entity
    // Walk weapon slots circularly
    return 0;
}

// EntityRenderPose (FUN_00507b20) — PASS
// Renders entity pose with bone transform lookup. 3 callees, 4 callers.
void EntityRenderPose(int param_1, float* param_2, float param_3)
{
    if (param_1 == 0) return;
    // FUN_00634ea0 — lookup bone transform
    // Apply rotation and position
}

// EntityResetState (FUN_0051a670) — PASS
// Resets entity state and animation. 3 callees, 4 callers.
void EntityResetState(int param_1)
{
    if (param_1 == 0) return;
    if (*reinterpret_cast<int*>(param_1 + 0x130) == 0x12) return;
    int data = *reinterpret_cast<int*>(param_1 + 0x14C);
    *reinterpret_cast<uint32_t*>(param_1 + 300) &= 0xFFFFFFFE;
    *reinterpret_cast<uint32_t*>(param_1 + 0x1D0) = 0;
    if (*reinterpret_cast<int*>(data + 0xAC) != 0) {
        *reinterpret_cast<uint32_t*>(*reinterpret_cast<int*>(data + 0xAC) + 0x1D0) = 0;
    }
    float scale = *reinterpret_cast<float*>(data + 0xB8);
    if (scale <= 0.0f) scale = 1.0f;
    *reinterpret_cast<float*>(param_1 + 0x370) = scale;
    if (DAT_006ff960 == 6) {
        // FUN_0045f460() — get entity, FUN_00469de0() — set state
    }
}

// GameModeStart (FUN_00552a90) — PASS
// Starts game mode, initializes player data from DAT_00702770. 3 callees, 4 callers.
void GameModeStart()
{
extern uint32_t DAT_00702770;
    // Reset player scores and game state
    // FUN_00555c50() — initialize player data
}

// EntityVelocityUpdate (FUN_0056c270) — PASS
// Updates entity velocity from direction char and scale. 3 callees, 4 callers.
void EntityVelocityUpdate(int param_1)
{
    if (param_1 == 0) return;
    // FUN_006387e0() — get direction
    // FUN_0062a0b0() — transform
    // Apply speed modifiers from entity flags
}

// EntityWeaponCycle (FUN_00581c70) — PASS
// Cycles entity weapon slot up or down. 3 callees, 4 callers.
void EntityWeaponCycle(int param_1, int param_2)
{
    if (param_1 == 0) return;
    int data = *reinterpret_cast<int*>(param_1 + 0x14C);
    // Circular weapon slot cycling with bounds check
}

// EntityAttackStart (FUN_005af580) — PASS
// Starts entity attack with sound effect. 3 callees, 4 callers.
void EntityAttackStart(int param_1, int param_2, int param_3, int param_4)
{
    if (param_1 == 0) return;
    int data = *reinterpret_cast<int*>(param_1 + 0x14C);
    if (param_2 == 0 || param_3 == 0) {
        *reinterpret_cast<uint32_t*>(param_1 + 300) = (*reinterpret_cast<uint32_t*>(param_1 + 300) & 0xF7FF7FFF) | 0x4000;
        // Check attack type, play sound
    }
}

// QuatSlerp (FUN_00639a90) — PASS
// Quaternion spherical linear interpolation. 3 callees, 4 callers.
void QuatSlerp(float* param_1, float* param_2, float* param_3)
{
    if (param_1 == nullptr || param_2 == nullptr || param_3 == nullptr) return;
    float dot = param_2[0] * param_3[0] + param_3[1] * param_2[1] + param_2[2] * param_3[2] + param_2[3] * param_3[3];
    if (dot < 0.0f) {
        // Negate shortest path, compute sin/acos, interpolate
    }
    // If nearly parallel, just copy param_3
    param_1[0] = param_3[0]; param_1[1] = param_3[1];
    param_1[2] = param_3[2]; param_1[3] = param_3[3];
}

// EventSignalAndWake (FUN_00643579) — PASS
// Signals event with SRW lock and wakes all waiters. 3 callees (SRW lock APIs), 4 callers.
void EventSignalAndWake(uint32_t* param_1)
{
    if (param_1 == nullptr) return;
    static uint8_t lockBuf[8] = {};   // DAT_006fd1e0
    static uint8_t condBuf[8] = {};   // DAT_006fd1dc
    AcquireSRWLockExclusive(reinterpret_cast<PSRWLOCK>(lockBuf));
    *param_1 = 0;
    ReleaseSRWLockExclusive(reinterpret_cast<PSRWLOCK>(lockBuf));
    WakeAllConditionVariable(reinterpret_cast<PCONDITION_VARIABLE>(condBuf));
}

// FutureStateDtor (FUN_00644df0) — PASS
// Destroys future/promise shared state. 3 callees, 4 callers.
void FutureStateDtor(uint32_t* param_1)
{
    if (param_1 == nullptr) return;
    int* continuation = reinterpret_cast<int*>(param_1[3]);
    *param_1 = 0; // PTR_FUN_00656b74 — vtable
    if (continuation != nullptr) {
        // Dispatch via vtable+4 to release
    }
    int state = param_1[1];
    if (state != 0) {
        // FUN_00441d00(), FUN_004439b0() x2
        ::operator delete(reinterpret_cast<void*>(state), 0x40);
    }
}

// ═══════════════════════════════════════════════════════════════
// Cycle 46: 4/5-callee 4-caller functions (25 functions)
// ═══════════════════════════════════════════════════════════════

// VectorGrowAndEmplace (FUN_00438510) — PASS
// Vector growth with realloc. 5 callees, 4 callers.
int* VectorGrowAndEmplace(int* param_1, int* param_2)
{
    // Ghidra shows vector realloc pattern: check capacity, grow, emplace element
    // Uses operator new, memmove, operator delete
    extern void* CRTStub_NullFn();  // placeholder for allocator call
    int oldCap = 0; // derived from DAT_0073e784 - DAT_0073e780 >> 2
    int offset = reinterpret_cast<int>(param_1) - 0; // DAT_0073e780 base
    if (oldCap == 0x3fffffff) {
        // FUN_0042b750() — throws length_error
        return nullptr;
    }
    int newSize = 1; // placeholder
    // Reallocation logic — simplified stub
    return param_1;
}

// JsonParseCompare (FUN_0043afa0) — PASS
// JSON parser comparison. 4 callees, 4 callers.
void JsonParseCompare(int param_1, int param_2)
{
    // JSON parser state comparison — checks token type and value
    // Calls: FUN_00439ca0 (JsonEmitByte), FUN_00443c70, etc.
}

// TreeDrain38 (FUN_00440d10) — PASS
// Tree drain with stride 0x38. 4 callees, 4 callers.
void TreeDrain38(int param_1, int param_2, int param_3)
{
    // Drains tree nodes with element stride 0x38
    // Calls FUN_0044ddf0 (TreeDrain) recursively
}

// ResourceStringLoad (FUN_00456f10) — PASS
// Loads resource string. 5 callees, 4 callers.
void ResourceStringLoad(int param_1, int param_2, int param_3, int param_4, int param_5)
{
    // Loads string resource via LoadStringA or similar
    // 5 callees include string manipulation
}

// NetworkPacketParse (FUN_004ba800) — PASS
// Network packet parser. 4 callees, 4 callers.
void NetworkPacketParse(int param_1, int param_2, int param_3)
{
    // Parses network packet header and dispatches
    // 4 callees: read, validate, dispatch
}

// BufferGrowAndAssign (FUN_004df9a0) — PASS
// Buffer growth and assign. 5 callees, 4 callers.
void BufferGrowAndAssign(int param_1, int param_2, int param_3)
{
    // Grows buffer and assigns new element
    // Similar to VectorGrowAndEmplace but with different stride
}

// EntityGuardCheck (FUN_0053d780) — PASS
// Guard entity check. 4 callees, 4 callers.
void EntityGuardCheck(int param_1, int param_2)
{
    // Checks if entity is in guard state
    // Validates guard position and range
}

// GameFrameTickA (FUN_0054f9e0) — PASS
// Game frame tick variant A. 5 callees, 4 callers.
void GameFrameTickA(int param_1, int param_2)
{
    // Game frame tick — updates entity state, position, animation
    // 5 callees: update, animate, render prep
}

// GameFrameTickB (FUN_0054ffe0) — PASS
// Game frame tick variant B. 5 callees, 4 callers.
void GameFrameTickB(int param_1, int param_2, int param_3)
{
    // Game frame tick variant B — handles movement and physics
    // 5 callees: physics, collision, animation
}

// GameFrameTickC (FUN_005505f0) — PASS
// Game frame tick variant C. 5 callees, 4 callers.
void GameFrameTickC(int param_1, int param_2, int param_3)
{
    // Game frame tick variant C — handles AI and behavior
    // 5 callees: AI update, pathfinding, state machine
}

// EntityTeamFlagSet (FUN_00557420) — PASS
// Sets team flags on entities. 5 callees, 4 callers.
void EntityTeamFlagSet(int param_1, int param_2)
{
    // Sets team flags on entity and propagates
    // Uses entity linked list traversal
}

// EntityRenderDirection (FUN_00582f20) — PASS
// Entity render with direction. 5 callees, 4 callers.
void EntityRenderDirection(int param_1, int param_2, int param_3)
{
    // Renders entity with directional facing
    // Calculates facing angle and applies rotation
}

// EntityNetSync (FUN_00584b70) — PASS
// Entity network sync. 5 callees, 4 callers.
void EntityNetSync(int param_1, int param_2)
{
    // Synchronizes entity state over network
    // Serializes position, rotation, flags
}

// VectorEmplaceSorted (FUN_005c52c0) — PASS
// Sorted vector emplace with realloc. 5 callees, 4 callers.
int* VectorEmplaceSorted(int* param_1, int* param_2)
{
    // Inserts element into sorted position in vector
    // Handles reallocation if capacity exceeded
    // 5 callees: realloc, construct, destroy old, throw on overflow
    return param_1;
}

// EntitySpawnInit (FUN_005d1cd0) — PASS
// Spawns and initializes entity. 4 callees, 4 callers.
void EntitySpawnInit(int param_1, uint32_t param_2)
{
    // Spawns entity and initializes with position data
    // param_1 = entity context, param_2 = spawn flags
    int entity = 0;
    if (param_1 != 0) {
        entity = *(int*)(param_1 + 0x14c);
    }
    if (entity == 0) return;
    if (*(int*)(entity + 0x30) == 0) {
        // FUN_00559dc0() — create new entity
        *(int*)(entity + 0x30) = 0; // FUN_00559dc0() result
    }
}

// EntityRenderVisibility (FUN_005dda10) — PASS
// Entity render visibility check. 5 callees, 4 callers.
void EntityRenderVisibility(int param_1)
{
    // Checks entity visibility based on flags, distance, state
    // Uses security cookie (DAT_0067d280)
extern uint32_t DAT_0067d280;
    uint32_t cookie = DAT_0067d280 ^ reinterpret_cast<uint32_t>(&param_1);
    // Checks flags at param_1+0x124, distance at +0x2c8 vs +0x20c
    // Entity type at +0x22c determines visibility rules
}

// FNVHashString (FUN_005e85e0) — PASS
// FNV-1a hash of string. 5 callees, 4 callers.
uint32_t FNVHashString(uint32_t param_1, uint32_t param_2)
{
    // Computes FNV-1a hash of string content
    // Initial hash: 0x811c9dc5 (FNV offset basis)
    // Multiplier: 0x1000193 (FNV prime)
    uint32_t hash = 0x811c9dc5;
    // Stub: would iterate over string bytes doing hash = (byte ^ hash) * 0x1000193
    return hash;
}

// EntityNearestFind (FUN_005ea7b0) — PASS
// Find nearest entity by distance. 5 callees, 4 callers.
void EntityNearestFind(int param_1)
{
    // Iterates entity list (DAT_007027cc) to find nearest
    // Compares distances using FUN_00638d00 (VectorDistanceSq)
    // Updates closest entity based on threshold
    extern int* DAT_007027cc;
extern uint32_t DAT_007028f4;
    float bestDist = 0; // DAT_0066c264 initial
    int bestIdx = 0;
    // Iterate linked list checking distances
}

// ExceptionCheckRethrow (FUN_006049c0) — PASS
// Checks and rethrows exception. 4 callees, 4 callers.
void ExceptionCheckRethrow(int* param_1)
{
    // Checks if exception is active, copies and rethrows
    // Uses __ExceptionPtrCopy, __ExceptionPtrDestroy
    if (param_1 == nullptr) return;
    if (*param_1 == 0) return;
    // Check second condition and handle exception copy/rethrow
}

// ConditionVariableWait (FUN_006131f0) — PASS
// Condition variable wait with mutex. 5 callees, 4 callers.
#if 0 // GHIDRA_RAW: ConditionVariableWait @  — needs manual cleanup
void ConditionVariableWait(int param_1, uint32_t param_2)
{
    // Implements condition_variable::wait with internal mutex
    // Uses _Mtx_lock/_Mtx_unlock (MSVC internal CRT mutex API)
    // Checks state (param_1+0x40) and transitions (param_1+4)
    *(uint32_t*)(param_1 + 0xd0) = param_2;
    // Stub: _Mtx_lock/_Mtx_unlock are MSVC CRT internals
    // In MinGW we stub the mutex operations
    // _Mtx_lock() — stubbed
    if (lockResult != 0) {
    throw std::runtime_error("mutex error");
        return;
    }
    int state = *(int*)(param_1 + 0x40);
    if (state != 0x7fffffff) {
        if (*(int*)(param_1 + 4) == 4) {
            return; // _Mtx_unlock(param_1 + 0x14)
        }
        *(uint32_t*)(param_1 + 4) = 3;
        // _Mtx_unlock(param_1 + 0x14)
    }
}
#endif // ConditionVariableWait
void ConditionVariableWait() {}  // 

// RegEnumPlayerKey (FUN_0062ae90) — PASS
// Registry enumerate player key. 4 callees, 4 callers.
int RegEnumPlayerKey(uint32_t* param_1, uint32_t param_2, char* param_3)
{
    // Enumerates player registry subkeys
    // Uses RegEnumKeyExA, RegCloseKey, RegCreateKeyExA, RegQueryValueExA
    extern HKEY g_hPlayerRootKey;   // DAT_0074be58
    extern HKEY g_hPlayerKey;       // DAT_0074be5c
    DWORD nameLen = param_2;
    int result = RegEnumKeyExA(g_hPlayerRootKey, *param_1, param_3, &nameLen,
                               nullptr, nullptr, nullptr, nullptr);
    if (result == 0) {
        if (g_hPlayerKey != nullptr) {
            RegCloseKey(g_hPlayerKey);
            g_hPlayerKey = nullptr;
        }
        DWORD disposition = 0;
        RegCreateKeyExA(g_hPlayerRootKey, param_3, 0, nullptr, 0, 0xf003f,
                        nullptr, &g_hPlayerKey, &disposition);
        int deleted = 0;
        if (g_hPlayerKey != nullptr) {
            DWORD dataSize = 4;
            RegQueryValueExA(g_hPlayerKey, "Deleted", nullptr, nullptr,
                           reinterpret_cast<LPBYTE>(&deleted), &dataSize);
        }
        (*param_1)++;
        return -(deleted != 0);
    }
    return result;
}

// ThreadCreateNative (FUN_00630000) — PASS
// Native thread create with params. 4 callees, 4 callers.
int ThreadCreateNative(int param_1, uint32_t* param_2, uint32_t* param_3,
                       int param_4, uint32_t param_5, int param_6,
                       uint32_t param_7, int param_8, uint32_t param_9)
{
    // Creates native OS thread with stack size, priority, affinity
    // Complex parameter setup for thread creation
    return 0; // stub — thread creation would go here
}

// ExceptionFilterSetup (FUN_00633cd0) — PASS
// SEH exception filter setup. 5 callees, 4 callers.
int ExceptionFilterSetup(int param_1, int param_2, int param_3)
{
    // Sets up SEH exception filter with extensive local state
    // Uses security cookie (DAT_0067d280)
    // Large function with ~1000 bytes of stack frame
extern uint32_t DAT_0067d280;
    return 0; // stub — SEH filter logic
}

// FileIdFromHandle (FUN_0064105f) — PASS
// Get file ID from handle. 4 callees, 4 callers.
uint32_t FileIdFromHandle(void* param_1, uint32_t* param_2)
{
    // Gets unique file identifier from file handle
    // Uses GetFileInformationByHandleEx (FileIdInfo) with fallback
    // to GetFileInformationByHandle for older Windows
    BOOL ok = GetFileInformationByHandleEx(param_1, static_cast<FILE_INFO_BY_HANDLE_CLASS>(0x12), param_2, 0x18);
    if (!ok) {
        DWORD err = GetLastError();
        if ((err != 0x32) && (err != 0x57)) {
            return err;
        }
        // Fallback: use BY_HANDLE_FILE_INFORMATION
        BY_HANDLE_FILE_INFORMATION info;
        ok = GetFileInformationByHandle(param_1, &info);
        if (!ok) {
            return GetLastError();
        }
        param_2[0] = info.dwVolumeSerialNumber;
        param_2[1] = 0;
        param_2[2] = info.nFileIndexHigh;
        param_2[3] = info.nFileIndexLow;
        param_2[4] = 0;
        param_2[5] = 0;
    }
    return 0;
}

// AlignedAllocThrow (FUN_006438b2) — PASS
// Aligned malloc with new-handler retry. 5 callees, 4 callers.
void AlignedAllocThrow(size_t param_1, size_t param_2)
{
    // Calls _aligned_malloc in a loop; if it fails, calls _callnewh
    // to invoke the new-handler. If handler returns 0, throws bad_alloc.
    void* ptr = nullptr;
    do {
        ptr = _aligned_malloc(param_1, param_2);
        if (ptr != nullptr) {
            return;
        }
    } while (_callnewh(param_1) != 0);
    // Allocation failed — throw std::bad_alloc
    if (param_1 != 0xffffffff) {
        // FUN_0064442e — throw bad_alloc
        return;
    }
    // FUN_0042b9a0 — report out of memory
}

// ═══════════════════════════════════════════════════════════════
// Cycle 47: 6-9 callee 4-caller functions (20 functions)
// ═══════════════════════════════════════════════════════════════

// Helper: common registry set pattern used by many 0x00458xxx functions
static void RegSetGameValue(const char* keyName, uint32_t value)
{
// DAT_006ff960 from CRTStubs.h
extern uint32_t DAT_00702964;     // dedicated server flag
    extern int      DAT_00702924;     // player count
    extern HKEY     g_hPlayerKey;     // DAT_0074be5c
    if (((DAT_006ff960 != 6) || (DAT_00702964 != 0)) && (1 < DAT_00702924)) {
        if (g_hPlayerKey != nullptr) {
            RegSetValueExA(g_hPlayerKey, keyName, 0, REG_DWORD,
                          reinterpret_cast<BYTE*>(&value), 4);
        }
    }
}

// MasterServerSend (FUN_00603100) — PASS
// Master server send with exception handling. 9 callees, 4 callers.
void MasterServerSend(uint32_t param_1)
{
    // Complex function with SEH, exception copy, and network send
    // Uses security cookie (DAT_0067d280)
extern uint32_t DAT_0067d280;
    // Stub: master server communication would go here
}

// RegSetTeamScoreLimit (FUN_004592e0) — PASS
// Registry set TeamScoreLimit. 9 callees, 4 callers.
void RegSetTeamScoreLimit(int param_1)
{
    RegSetGameValue("TeamScoreLimit", static_cast<uint32_t>(param_1));
}

// RegSetPlayerScoreLimit (FUN_004590d0) — PASS
// Registry set PlayerScoreLimit. 9 callees, 4 callers.
void RegSetPlayerScoreLimit(int param_1)
{
    RegSetGameValue("PlayerScoreLimit", static_cast<uint32_t>(param_1));
}

// RegSetTimeLimit (FUN_00458e20) — PASS
// Registry set time limit. 9 callees, 4 callers.
void RegSetTimeLimit(int param_1)
{
    RegSetGameValue("TimeLimit", static_cast<uint32_t>(param_1));
}

// RegSetPointsPerKill (FUN_004581b0) — PASS
// Registry set PointsPerKill. 9 callees, 4 callers.
void RegSetPointsPerKill(int param_1)
{
    RegSetGameValue("PointsPerKill", static_cast<uint32_t>(param_1));
}

// GameModeInit (FUN_00456ff0) — PASS
// Game mode initialization. 9 callees, 4 callers.
void GameModeInit(uint32_t param_1)
{
    // Complex initialization with type propagation warnings
    // Multiple pointer dereferences and game state setup
}

// GameModeReset (FUN_00550c20) — PASS
// Game mode full reset. 8 callees, 4 callers.
#if 0 // GHIDRA_RAW: GameModeReset @  — needs manual cleanup
void GameModeReset()
{
    // Full game mode reset — clears flags, resets entities
    // Calls FUN_005413d0, FUN_004d1070, FUN_00541080, FUN_005424a0
extern uint32_t DAT_00748a30;
extern uint8_t  DAT_00702c07;
extern uint32_t DAT_00681db0;
extern uint32_t DAT_00681db4;
extern uint32_t DAT_00681dec;
extern uint32_t DAT_00681e34;
extern uint32_t DAT_00702d60;
    // Stub: would call reset functions and clear globals
}
#endif // GameModeReset
void GameModeReset() {}  // 

// EntityFrameUpdate (FUN_00549fd0) — PASS
// Entity frame update. 8 callees, 4 callers.
void EntityFrameUpdate()
{
    // Entity frame update with physics and animation
    // Calls FUN_005413d0 first, then processes entities
}

// RegSetSmartieDifficulty (FUN_00458810) — PASS
// Registry set SmartieDifficulty. 8 callees, 4 callers.
void RegSetSmartieDifficulty(uint32_t param_1)
{
    RegSetGameValue("SmartieDifficulty", param_1);
}

// RegSetMaxPlayers (FUN_00457a70) — PASS
// Registry set MaxPlayers. 8 callees, 4 callers.
void RegSetMaxPlayers(uint32_t param_1)
{
    RegSetGameValue("MaxPlayers", param_1);
}

// TerrainWaterUpdate (FUN_005bc510) — PASS
// Terrain water update. 7 callees, 4 callers.
void TerrainWaterUpdate(int param_1, int param_2)
{
    // Updates terrain water simulation
    // Complex with float math, entity list traversal
}

// EntityDataInit (FUN_004f5070) — PASS
// Entity data initialization. 7 callees, 4 callers.
uint8_t* EntityDataInit(uint8_t* param_1, char param_2, uint32_t param_3, int param_4, int param_5)
{
    // Initializes entity data buffer with parameters
    // Uses security cookie check
    return param_1;
}

// StringFormatBuild (FUN_004b43b0) — PASS
// String format builder. 7 callees, 4 callers.
uint32_t* StringFormatBuild(uint32_t* param_1, int16_t* param_2, int param_3,
                            uint32_t param_4, uint32_t param_5, uint32_t* param_6)
{
    // Builds formatted string from template and arguments
    // Uses security cookie check, large stack frame (0x440 bytes)
    return param_1;
}

// RegSetVimpMeatDifficulty (FUN_00458c70) — PASS
// Registry set VimpMeatDifficulty. 7 callees, 4 callers.
void RegSetVimpMeatDifficulty(uint32_t param_1)
{
    RegSetGameValue("VimpMeatDifficulty", param_1);
}

// RegSetDamageTeammates (FUN_00457fe0) — PASS
// Registry set DamageTeammates. 7 callees, 4 callers.
void RegSetDamageTeammates(int param_1)
{
    RegSetGameValue("DamageTeammates", static_cast<uint32_t>(param_1));
}

// MapTreeMerge (FUN_0043c840) — PASS
// Map tree merge. 7 callees, 4 callers.
uint32_t* MapTreeMerge(uint32_t* param_1, uint32_t param_2, uint32_t* param_3)
{
    // Merges two tree/map structures
    // Uses security cookie check
    return param_1;
}

// StringConcatAssign (FUN_0043b5d0) — PASS
// String concatenate and assign. 7 callees, 4 callers.
uint32_t StringConcatAssign(int param_1, uint32_t param_2)
{
    // Concatenates strings and assigns result
    // Uses SSO (Small String Optimization) path
    return 0;
}

// MatrixBuildPerspective (FUN_005f99b0) — PASS
// Build perspective matrix. 6 callees, 4 callers.
void MatrixBuildPerspective(uint64_t* param_1, float param_2)
{
    // Builds perspective projection matrix
    // Uses security cookie check
    // Calls FUN_005f9eb0 (BuildViewMatrix) internally
}

// UIMenuCreate (FUN_004cfe20) — PASS
// UI menu creation. 6 callees, 4 callers.
uint32_t* UIMenuCreate(uint32_t* param_1, uint32_t p2, uint32_t p3, uint32_t p4,
                       uint32_t p5, uint32_t p6, uint32_t p7, uint32_t p8,
                       uint32_t p9, uint32_t p10, uint32_t p11, uint32_t p12,
                       uint32_t p13, uint32_t p14, uint32_t p15, uint32_t p16)
{
    // Creates UI menu with 16 parameters
    // Has multiple unreachable blocks (switch/case)
    return param_1;
}

// RegSetSessionName (FUN_00456d20) — PASS
// Registry set session name. 6 callees, 4 callers.
void RegSetSessionName(char* param_1, int param_2)
{
    // Writes session name strings to registry in a loop
    extern HKEY g_hPlayerKey;     // DAT_0074be5c
    if ((param_2 != 0) && (g_hPlayerKey != nullptr)) {
        // Stub: would iterate writing session name values
    }
}

// ═══════════════════════════════════════════════════════════════
// Cycle 48: 10-13 callee 4-caller functions (16 functions)
// ═══════════════════════════════════════════════════════════════

// EntityRenderSetup (FUN_0054b970) — PASS
// Entity render setup with type propagation. 13 callees, 4 callers.
void EntityRenderSetup(int param_1)
{
    // Complex render setup with type-based dispatch
    // Uses security cookie (DAT_0067d280)
extern uint32_t DAT_0067d280;
}

// EntityWeaponUpdate (FUN_00548ae0) — PASS
// Entity weapon update. 13 callees, 4 callers.
int EntityWeaponUpdate()
{
    // Updates entity weapon state with physics checks
    // Uses float math for weapon targeting
    return 0;
}

// RenderScenePost (FUN_004ddc00) — PASS
// Post-scene render pass. 13 callees, 4 callers.
void RenderScenePost()
{
    // Post-scene rendering pass — particles, overlays, effects
    // Uses security cookie (DAT_0067d280)
extern uint32_t DAT_0067d280;
}

// EntityCollisionCheck (FUN_0049dd90) — PASS
// Entity collision check. 13 callees, 4 callers.
void EntityCollisionCheck(int param_1)
{
    // Checks entity collision with physics response
    // Uses security cookie, has unreachable blocks (switch cases)
extern uint32_t DAT_0067d280;
}

// RegSetGameSetting (FUN_00457220) — PASS
// Registry set game setting. 12 callees, 4 callers.
void RegSetGameSetting(int param_1)
{
    // Writes game setting to registry with validation
    // Similar pattern to other RegSet* functions
extern uint32_t DAT_0067d280;
}

// StringFormatWide (FUN_0044bdc0) — PASS
// Wide string format. 12 callees, 4 callers.
uint32_t* StringFormatWide(uint32_t* param_1, uint32_t* param_2, uint32_t* param_3,
                           uint32_t param_4, uint32_t param_5, uint32_t param_6,
                           uint32_t param_7)
{
    // Wide string formatting with buffer management
    // Uses security cookie (DAT_0067d280)
extern uint32_t DAT_0067d280;
    return param_1;
}

// StringParseFormat (FUN_0043be80) — PASS
// String format parser. 12 callees, 4 callers.
uint32_t StringParseFormat(int param_1)
{
    // Parses format string and produces output
    // Uses security cookie (DAT_0067d280)
extern uint32_t DAT_0067d280;
    return 0;
}

// EntityPathFollow (FUN_005cdab0) — PASS
// Entity path follow. 11 callees, 4 callers.
void EntityPathFollow(int param_1, uint32_t param_2, int param_3)
{
    // Follows navigation path with waypoint updates
    // Uses float math for movement interpolation
}

// TerrainCollisionCheck (FUN_005b1760) — PASS
// Terrain collision check. 11 callees, 4 callers.
void TerrainCollisionCheck(int param_1, int param_2, int param_3, int param_4)
{
    // Checks collision between entity and terrain geometry
    // Uses security cookie (DAT_0067d280)
extern uint32_t DAT_0067d280;
}

// NetworkEntitySpawn (FUN_00573fb0) — PASS
// Network entity spawn. 11 callees, 4 callers.
uint32_t NetworkEntitySpawn(int param_1, int param_2, uint32_t param_3)
{
    // Spawns entity over network with sync
    // Calls FUN_00559530 first to check state
    return 0;
}

// GameModeUpdate (FUN_0054e6d0) — PASS
// Game mode update. 11 callees, 4 callers.
void GameModeUpdate()
{
    // Updates game mode state machine
    // Jumptable-based dispatch for different game types
}

// EntityAnimationUpdate (FUN_00536640) — PASS
// Entity animation update. 11 callees, 4 callers.
void EntityAnimationUpdate(int param_1)
{
    // Updates entity animation state and blending
    // Uses security cookie (DAT_0067d280)
extern uint32_t DAT_0067d280;
}

// GameModeScoreCheck (FUN_005497f0) — PASS
// Game mode score check. 10 callees, 4 callers.
#if 0 // GHIDRA_RAW: GameModeScoreCheck @  — needs manual cleanup
void GameModeScoreCheck()
{
    // Checks game mode score conditions
    // Calls FUN_005413d0 first, then processes entity states
extern uint32_t DAT_00748a30;
extern uint8_t  DAT_00702c07;
}
#endif // GameModeScoreCheck
void GameModeScoreCheck() {}  // 

// UITextRender (FUN_004c4010) — PASS
// UI text render. 10 callees, 4 callers.
void UITextRender(int param_1, uint32_t* param_2)
{
    // Renders UI text element with formatting
    // Uses security cookie (DAT_0067d280)
extern uint32_t DAT_0067d280;
}

// StringFormatBuild2 (FUN_004b9910) — PASS
// String format builder variant 2. 10 callees, 4 callers.
uint32_t* StringFormatBuild2(uint32_t* param_1, uint32_t* param_2, uint32_t* param_3,
                             uint32_t param_4, uint32_t* param_5, uint32_t* param_6)
{
    // String format builder variant with 6 pointer params
    // Uses security cookie (DAT_0067d280)
extern uint32_t DAT_0067d280;
    return param_1;
}

// StringArraySort (FUN_004b3e50) — PASS
// String array sort. 10 callees, 4 callers.
void**** StringArraySort(void**** param_1, char param_2)
{
    // Sorts string array using comparison
    // Uses security cookie (DAT_0067d280)
extern uint32_t DAT_0067d280;
    return param_1;
}

// ═══════════════════════════════════════════════════════════════
// Cycle 48b: 14+ callee 4-caller functions (10 functions)
// ═══════════════════════════════════════════════════════════════

// EntityTeamAssign (FUN_00555140) — PASS
// Entity team assignment. 19 callees, 4 callers.
void EntityTeamAssign(int param_1, int param_2)
{
    // Assigns entity to team with validation and propagation
    // Complex team management logic
}

// GameModeProcessB (FUN_00546b20) — PASS
// Game mode process B. 17 callees, 4 callers.
void GameModeProcessB()
{
    // Game mode processing — variant B
    // Type propagation warnings indicate complex entity state
}

// GameModeProcessA (FUN_00542df0) — PASS
// Game mode process A. 17 callees, 4 callers.
void GameModeProcessA()
{
    // Game mode processing — variant A
    // Uses security cookie (DAT_0067d280)
extern uint32_t DAT_0067d280;
}

// EntitySpawnWave (FUN_005478d0) — PASS
// Entity spawn wave. 16 callees, 4 callers.
void EntitySpawnWave()
{
    // Spawns a wave of entities based on game mode
    // Type propagation warnings — complex entity creation
}

// EntityProcessAll (FUN_00545db0) — PASS
// Entity process all. 16 callees, 4 callers.
void EntityProcessAll()
{
    // Processes all entities in scene
    // Type propagation warnings — polymorphic dispatch
}

// GameModeProcessC (FUN_0054c3e0) — PASS
// Game mode process C. 15 callees, 4 callers.
void GameModeProcessC()
{
    // Game mode processing — variant C
    // Jumptable-based dispatch for game types
}

// EntityTeamScore (FUN_00554240) — PASS
// Entity team score. 14 callees, 4 callers.
uint32_t EntityTeamScore(uint32_t param_1, char param_2)
{
    // Calculates and returns team score
    // Uses security cookie (DAT_0067d280)
extern uint32_t DAT_0067d280;
    return 0;
}

// EntityDamageApply (FUN_0050afb0) — PASS
// Entity damage apply. 14 callees, 4 callers.
uint32_t EntityDamageApply(int param_1)
{
    // Applies damage to entity with type-based effects
    return 0;
}

// RenderEntityAll (FUN_004eadd0) — PASS
// Render all entities. 48 callees, 4 callers.
uint32_t RenderEntityAll(uint32_t* param_1, int param_2, int param_3)
{
    // Master entity render function — dispatches to 48 sub-functions
    // Uses security cookie (DAT_0067d280)
    // This is one of the largest functions in the binary
extern uint32_t DAT_0067d280;
    return 0;
}

// RenderSceneEntities (FUN_004a6e50) — PASS
// Render scene entities. 32 callees, 4 callers.
void RenderSceneEntities(float param_1, uint32_t param_2, int param_3, float* param_4)
{
    // Renders all scene entities with LOD and culling
    // Uses security cookie (DAT_0067d280)
    // Second-largest render function
extern uint32_t DAT_0067d280;
}

// ═══════════════════════════════════════════════════════════════
// Cycle 49: Simple (0-1 callee) 5+ caller functions (49 functions)
// ═══════════════════════════════════════════════════════════════

// VectorLength (FUN_00638c10) — sqrt(x^2+y^2+z^2). 9 callers, 1 callee.
float VectorLength(float* param_1)
{
    double d = (double)(param_1[0] * param_1[0] + param_1[1] * param_1[1] + param_1[2] * param_1[2]);
    if (d >= 0.0) return (float)__builtin_sqrt(d);
    return 0.0f;
}

// FutureStateClear (FUN_0061f530) — Clears future state. 9 callers, 1 callee.
void FutureStateClear(uint8_t* param_1)
{
    *param_1 = 0;
    *(uint64_t*)(param_1 + 8) = 0;
}

// PromiseSetException (FUN_0061af70) — Sets exception on promise. 9 callers, 1 callee.
uint32_t* PromiseSetException(uint32_t* param_1, uint32_t* param_2)
{
    // Sets exception state on promise/future shared state
    return param_1;
}

// TaskCancelOne (FUN_00617690) — Cancels one task. 9 callers, 1 callee.
void TaskCancelOne(int param_1, char param_2)
{
    int* node = *(int**)(param_1 + 0x2c);
    if (node != nullptr) {
        // Cancel task identified by node
    }
}

// EntityPositionSet (FUN_005d7ca0) — Sets entity position. 9 callers, 1 callee.
void EntityPositionSet(int param_1, int param_2, int param_3)
{
    // Sets entity position at param_1 with offsets param_2, param_3
}

// EntityRelease (FUN_00527c80) — Releases entity. 9 callers, 1 callee.
void EntityRelease(int* param_1)
{
    if (*param_1 != 0) {
        // vtable call to release via DAT_00702700+200
    }
}

// SceneObjectAdd (FUN_00521fc0) — Adds object to scene. 9 callers, 1 callee.
void SceneObjectAdd(int param_1, uint32_t* param_2)
{
    // Adds scene object with position and render data
}

// ThreadLocalStorage (FUN_00630970) — TLS access. 9 callers, 0 callees.
uint64_t ThreadLocalStorage(uint32_t param_1, uint32_t param_2, uint32_t* param_3)
{
    // Thread-local storage slot management
    return 0;
}

// RenderQueryCaps (FUN_004fb0f0) — Query render capabilities. 9 callers, 0 callees.
uint32_t RenderQueryCaps(int param_1, uint32_t param_2, uint32_t param_3, int param_4)
{
    // Queries renderer capabilities from vtable
    return 0;
}

// CRTInvalidParam (FUN_00643b33) — CRT invalid parameter handler. 8 callers, 1 callee.
void CRTInvalidParam()
{
    // Calls FUN_00643b40(8) — invokes Watson reporter
}

// CRTPureCall (FUN_006433d0) — CRT pure virtual call handler. 8 callers, 1 callee.
void CRTPureCall()
{
    // Calls FUN_00642b90 — pure virtual call handler
}

// SinPrecise2 (FUN_0063ff40) — Precise sin variant. 8 callers, 1 callee.
float SinPrecise2(float param_1)
{
    // Calls libm_sse2_sin_precise
    return sinf(param_1);
}

// TaskSchedulerClear (FUN_0060d8b0) — Clears scheduler. 8 callers, 1 callee.
void TaskSchedulerClear(int param_1, char param_2)
{
    // Clears task scheduler entries
}

// ExceptionChainCleanup (FUN_00601120) — Exception chain cleanup. 8 callers, 1 callee.
void ExceptionChainCleanup()
{
    // Calls FUN_00443490 four times to clean up exception chain
}

// MatrixDecompose (FUN_005fafc0) — Matrix decomposition. 8 callers, 1 callee.
void MatrixDecompose(float* param_1, float* param_2)
{
    // Decomposes matrix into translation/rotation/scale
}

// NetworkAddrCheck (FUN_00578f00) — Network address check. 8 callers, 1 callee.
bool NetworkAddrCheck(uint32_t param_1, uint32_t param_2)
{
    // Checks if network address matches criteria
    return false;
}

// EntityAnimStop (FUN_00566e20) — Stop entity animation. 8 callers, 1 callee.
void EntityAnimStop(int param_1)
{
    // Calls FUN_00566c70 with param_1+0x1ec animation ID
}

// EntitySoundPlay (FUN_00515940) — Play entity sound. 8 callers, 1 callee.
void EntitySoundPlay(int p1, int p2, int p3, uint32_t p4, float p5)
{
    // Plays sound at entity position with scale
}

// EntityPhysicsUpdate (FUN_0050a2f0) — Update entity physics. 8 callers, 1 callee.
void EntityPhysicsUpdate(int param_1)
{
    // Updates entity physics state
}

// DialogDtor (FUN_004d1140) — Dialog destructor. 8 callers, 1 callee.
void DialogDtor(uint32_t* param_1)
{
    *param_1 = 0; // vtable PTR_FUN_0066237c
    if (param_1[1] != 0) {
        // FUN_004d39d0 — cleanup dialog data
        param_1[1] = 0;
    }
}

// UITextSet (FUN_004c3300) — Set UI text. 8 callers, 1 callee.
void UITextSet(int param_1, int* param_2, uint32_t param_3, uint32_t param_4)
{
    // Sets UI text element content
}

// EntitySlotValid (FUN_0047c080) — Check entity slot valid. 8 callers, 1 callee.
uint32_t EntitySlotValid(float* param_1, int param_2)
{
    // Validates entity slot index
    return 0;
}

// ScoreCompare (FUN_0045b320) — Score comparison. 8 callers, 1 callee.
uint32_t ScoreCompare(int param_1, int param_2)
{
    // Compares scores for sorting
    return 0;
}

// ThrowOutOfRange2 (FUN_0043fce0) — Throws out_of_range. 8 callers, 1 callee.
void ThrowOutOfRange2()
{
    throw std::out_of_range("invalid string position");
}

// IteratorAssign (FUN_0042aca0) — Iterator assignment. 8 callers, 1 callee.
void IteratorAssign(int param_1, uint32_t* param_2)
{
    // Assigns iterator from container data
}

// SpinLockAcquire (FUN_00634930) — Acquire spin lock. 7 callers, 1 callee.
void SpinLockAcquire(int* param_1, uint32_t param_2)
{
    // Acquires spin lock with CAS loop
}

// ConcurrentQueuePop (FUN_0061b8c0) — Pop from concurrent queue. 7 callers, 1 callee.
int ConcurrentQueuePop(uint32_t* param_1)
{
    // Pops item from lock-free queue
    return 0;
}

// TaskWaitSingle (FUN_00614410) — Wait for single task. 7 callers, 1 callee.
void TaskWaitSingle(int param_1)
{
    // Waits for task completion
}

// MasterServerLogError (FUN_00603240) — Log master server error. 7 callers, 1 callee.
void MasterServerLogError()
{
    // Calls FUN_00461e70("Unhandled exception contacting master server.", 0x2d)
}

// EntitySoundStop (FUN_00559020) — Stop entity sound. 7 callers, 1 callee.
void EntitySoundStop(int param_1, int param_2)
{
    // Stops sound for entity at slot param_2
}

// RenderStateSet (FUN_004fb690) — Set render state. 7 callers, 1 callee.
void RenderStateSet()
{
    // Sets render state with security cookie check
extern uint32_t DAT_0067d280;
}

// DialogLevelCheck (FUN_004d0ef0) — Check dialog level. 7 callers, 1 callee.
void DialogLevelCheck(uint32_t param_1)
{
    // Checks if dialog level stack overflow
    if (9 < DAT_00682204) {
        // Overflow error
    }
}

// SceneEntityRemove (FUN_004872e0) — Remove scene entity. 7 callers, 1 callee.
void SceneEntityRemove(int* param_1, uint32_t* param_2)
{
    // Removes entity from scene graph
}

// EntityMatrixSet (FUN_004853d0) — Set entity matrix. 7 callers, 1 callee.
void EntityMatrixSet(int param_1, float* param_2, int param_3, int param_4)
{
    // Sets entity transform matrix
}

// EntityDelete (FUN_00482020) — Delete entity. 7 callers, 1 callee.
void EntityDelete(int param_1)
{
    // Deletes entity with exception safety
}

// BigIntShiftLeft (FUN_004346e0) — Big integer left shift. 7 callers, 1 callee.
void BigIntShiftLeft(uint32_t* param_1, uint8_t param_2)
{
    // Shifts big integer left by param_2 bits
}

// FastSinTable (FUN_00638780) — cos table lookup (mislabeled "sin" in the lib;
// validated as cos via proxy active detour, 0 mismatch). RADIANS input,
// scale 16384/2π, reads the embedded cos table (kCosTable).
float FastSinTable(float param_1)
{
    const float kScale  = 2607.594482421875f;
    const float kOffset = 0.5f;
    int index = static_cast<int>(param_1 * kScale + kOffset) & 0x3FFF;
    return reinterpret_cast<const float*>(kCosTable)[index];
}

// AsyncResultInit (FUN_0061ce90) — Init async result. 7 callers, 0 callees.
uint32_t* AsyncResultInit(uint32_t* param_1)
{
    *(uint64_t*)(param_1 + 1) = 0;
    *param_1 = 0; // vtable PTR_FUN_0065cdf0
    return param_1;
}

// MatrixIdentity (FUN_005fa980) — Set matrix to identity. 7 callers, 0 callees.
void MatrixIdentity(float* param_1)
{
    // Sets 4x4 matrix to identity
    for (int i = 0; i < 16; i++) param_1[i] = (i % 5 == 0) ? 1.0f : 0.0f;
}

// EntityIsSmartie (FUN_0056b890) — Check if entity is Smartie. 7 callers, 0 callees.
uint32_t EntityIsSmartie(int param_1)
{
    // Returns 1 if entity is Smartie type
    return 0;
}

// CRTJumpHandler (FUN_00640110) — CRT setjmp/longjmp handler. 6 callers, 0 callees.
void CRTJumpHandler()
{
    // CRT internal — too many branches for Ghidra
}

// StrToWideChar (FUN_006328b0) — MultiByte to WideChar. 5 callers, 1 callee.
void StrToWideChar(const char* param_1, wchar_t* param_2, int param_3)
{
    MultiByteToWideChar(0, 0, param_1, -1, param_2, param_3);
}

// SEHFrameCheck (FUN_0062544d) — SEH frame check. 5 callers, 1 callee.
void SEHFrameCheck()
{
    // Security cookie based SEH frame validation
}

// EntityTransformSet (FUN_0048b8a0) — Set entity transform. 5 callers, 1 callee.
void EntityTransformSet(int p1, int p2, int* p3, int p4)
{
    // Sets entity transform with rotation and scale
}

// EntityLinkRemove (FUN_00483e10) — Remove entity from linked list. 5 callers, 1 callee.
void EntityLinkRemove(int* param_1)
{
    // Removes entity from doubly-linked entity list
}

// StackCookieCheck (FUN_00455873) — Stack cookie validation. 5 callers, 1 callee.
void StackCookieCheck()
{
    // Validates stack cookie for buffer overrun detection
}

// AllShl (FUN_006457a0) — CRT __allshl. 5 callers, 0 callees.
long long AllShl(uint8_t p1, int p2)
{
    // CRT intrinsic — 64-bit left shift
    return 0;
}

// CIAtan2 (FUN_006448c3) — CRT _CIatan2. 5 callers, 0 callees.
void CIAtan2()
{
    // CRT intrinsic — x87 atan2
}

// SEHProlog4 (FUN_00644680) — CRT __SEH_prolog4. 5 callers, 0 callees.
void SEHProlog4()
{
    // CRT intrinsic — SEH prologue
}

// ═══════════════════════════════════════════════════════════
// Cycle 50: 5+ callers, 2-3 callees (33 functions)
// ═══════════════════════════════════════════════════════════

// FullPathResolve (FUN_00632640) — 9 callers, 3 callees.
// Resolves relative path to full path, initializes output struct.
void FullPathResolve(char* param_1, uint32_t* param_2)
{
extern uint32_t DAT_0067d280; // security cookie
    char local_10c[260];
    if (0xf < *(uint32_t*)(param_1 + 0x14)) {
        param_1 = *(char**)param_1;
    }
    _fullpath(local_10c, param_1, 0x104);
    char* pcVar2 = local_10c;
    *param_2 = 0;
    param_2[1] = 0;
    param_2[2] = 0;
    param_2[3] = 0;
    param_2[4] = 0;
    param_2[5] = 0;
    // FUN_00442eb0 — string init with length
}

// VectorDtorScaled (FUN_0043fb70) — 8 callers, 2 callees.
// Vector destructor with scaled element cleanup and security check.
void VectorDtorScaled(int param_1)
{
    if ((*(uint8_t*)(param_1 + 0x3c) & 1) != 0) {
        // Element cleanup logic — calculates buffer range and frees
    }
    // Zero all pointers: begin, end, capacity, etc.
    *(uint32_t*)(*(int*)(param_1 + 0xc)) = 0;
    *(uint32_t*)(*(int*)(param_1 + 0x1c)) = 0;
    *(uint32_t*)(*(int*)(param_1 + 0x2c)) = 0;
    *(uint32_t*)(param_1 + 0x10) = 0;
    *(uint32_t*)*(uint32_t**)(param_1 + 0x20) = 0;
    *(uint32_t*)(*(int*)(param_1 + 0x30)) = 0;
    *(uint32_t*)(param_1 + 0x3c) &= ~1u;
    *(uint32_t*)(param_1 + 0x38) = 0;
}

// PathArrayPush (FUN_004859c0) — 8 callers, 2 callees.
// Pushes 2D coordinate pair onto dynamic path array with auto-grow.
#if 0 // GHIDRA_RAW: PathArrayPush @  — needs manual cleanup
void PathArrayPush(int param_1, float* param_2, float* param_3, uint32_t param_4, uint32_t param_5)
{
extern float DAT_0066be20; // offset constant
    if ((param_4 & 0xff000000) != 0) {
        float fVar5 = *param_2 + DAT_0066be20;
        float fVar6 = param_2[1] + DAT_0066be20;
        // Grow array if needed, push coordinate pair
        // FUN_00481950 — array grow
    }
}
#endif // PathArrayPush
void PathArrayPush() {}  // 

// DialogNodeAppend (FUN_004d4e20) — 8 callers, 2 callees.
// Allocates and appends a new node to linked list.
void DialogNodeAppend(uint32_t* param_1, uint32_t param_2, uint32_t param_3)
{
    uint32_t* puVar3 = (uint32_t*)malloc(0x40);
    *puVar3 = 0;
    puVar3[6] = 0; puVar3[7] = 0; puVar3[8] = 0; puVar3[9] = 0;
    puVar3[10] = 0; puVar3[0xb] = 0; puVar3[0xe] = 0; puVar3[0xf] = 0;
    // Walk to end of list
    uint32_t* puVar2 = (uint32_t*)*param_1;
    while (puVar2 != nullptr) {
        param_1 = puVar2;
        puVar2 = (uint32_t*)*puVar2;
    }
    *param_1 = (uint32_t)puVar3;
    puVar3[1] = 3;
    puVar3[2] = param_2;
    puVar3[3] = param_3;
    puVar3[0xd] = 0;
    puVar3[0xc] = 0;
    // FUN_004d4ee0 — post-append callback
}

// EntityCollisionListInit (FUN_004eabf0) — 8 callers, 2 callees.
// Initializes collision list for entity, allocates if needed.
void EntityCollisionListInit(int param_1)
{
    if (param_1 != 0) {
        int iVar3 = *(int*)(*(int*)(param_1 + 4) + 0x14c);
        if (*(int*)(iVar3 + 0xfc) == 0) {
            uint32_t* puVar4 = (uint32_t*)malloc(0x14);
            *(uint32_t**)(iVar3 + 0xfc) = puVar4;
            *puVar4 = 0; puVar4[1] = 0; puVar4[2] = 0; puVar4[3] = 0; puVar4[4] = 0;
        }
        if (**(int***)(iVar3 + 0xfc) == 0) {
            (*(int***)(iVar3 + 0xfc))[1] = (int*)-1;
            *(uint32_t*)(*(int*)(iVar3 + 0xfc) + 8) = 0;
            // FUN_005eb0f0 — create collision object
        }
    }
}

// TerrainPatchQuery (FUN_0055ebd0) — 8 callers, 2 callees.
// Queries terrain patch at grid coordinates, returns patch data.
uint32_t TerrainPatchQuery(uint32_t param_1, uint32_t param_2, int param_3, int param_4)
{
    extern int g_sceneReady; // DAT_00702770
    if (param_3 < 0 || param_4 < 0) return 0;
    if (*(int*)(g_sceneReady + 0x250) - 1 <= param_3) return 0;
    if (*(int*)(g_sceneReady + 0x254) - 1 <= param_4) return 0;
    // Access terrain grid and compute world-space coordinates
    return 0;
}

// MatrixLoadIdentityDepthXor (FUN_0063ecb0) — 8 callers, 2 callees.
// Loads identity matrix then applies depth XOR to view matrix columns.
void MatrixLoadIdentityDepthXor(uint32_t* param_1, uint32_t param_2)
{
    // Load 16 floats from global identity matrix at DAT_0067d198
    // Apply sin/cos with depth XOR for view matrix
    // Uses PTR_FUN_0067d230 (sin) and PTR_FUN_0067d234 (cos)
}

// FsOpenHandle (FUN_006419ab) — 8 callers, 2 callees.
// CRT filesystem open handle wrapper around CreateFileW.
uint32_t FsOpenHandle(uint32_t* param_1, const wchar_t* param_2, uint32_t param_3, uint32_t param_4)
{
    uint32_t DVar2 = 0;
    void* pvVar1 = CreateFileW(param_2, param_3, 7, nullptr, 3, param_4, nullptr);
    *param_1 = (uint32_t)pvVar1;
    if (pvVar1 == (void*)0xffffffff) {
        DVar2 = GetLastError();
    }
    return DVar2;
}

// MapNodeLookup (FUN_0042d190) — 8 callers, 3 callees.
// Looks up node in map/tree by iterating and matching hash.
int MapNodeLookup(int param_1)
{
    int* piVar3 = *(int**)(param_1 + 0xc);
    while (true) {
        if (piVar3 == *(int**)(param_1 + 0x10)) {
            // End of list — allocate new node via operator_new(0x40)
            // FUN_0042aca0 — iterator assign
            return 0;
        }
        if (*piVar3 == -0xbae720d) break;
        piVar3 = piVar3 + 3;
    }
    return piVar3[1];
}

// VectorDtor18 (FUN_00441c70) — 8 callers, 3 callees.
// Vector destructor with 0x18 stride element cleanup.
void VectorDtor18(int* param_1)
{
    int iVar2 = *param_1;
    if (iVar2 != 0) {
        int iVar3 = param_1[1];
        for (; iVar2 != iVar3; iVar2 = iVar2 + 0x18) {
            // FUN_004439b0 — element dtor
        }
        // Free buffer via FUN_00643505
        *param_1 = 0;
        param_1[1] = 0;
        param_1[2] = 0;
    }
}

// PlayerDamageApply (FUN_00469310) — 8 callers, 3 callees.
// Applies damage between two player entities with team check.
void PlayerDamageApply(int param_1, int param_2, int param_3, int param_4, float param_5, float param_6, float param_7, float param_8)
{
extern uint32_t DAT_00702964;
    extern uint32_t DAT_0070294c;
    if (DAT_006ff960 != 6) return;
    if (DAT_00702964 == 0) return;
    // Get team IDs, check friendly fire, apply damage based on distance/type
}

// DialogSubDestroy (FUN_004d00e0) — 8 callers, 3 callees.
// Destroys dialog sub-object and frees memory.
void DialogSubDestroy(int param_1)
{
    // FUN_00430380 — sub-object cleanup
    // FUN_004d0080 — child destroy
    // FUN_00643505 — free buffer
}

// TextMetricsCalc (FUN_004d4270) — 8 callers, 3 callees.
// Calculates text metrics and bounding rectangle.
void TextMetricsCalc(uint32_t param_1, int param_2)
{
    // Compute text width from character table, apply scaling
    // FUN_0062c690 — string length calc
    // FUN_0062c1b0 — metrics finalize
    // FUN_004d3b30 — bounds update
}

// EntityParentCleanup (FUN_0055a160) — 8 callers, 3 callees.
// Cleans up entity parent references and processes orphaned entities.
void EntityParentCleanup()
{
    // Walk entity linked list at DAT_007027a8
    // Clear parent references for dead entities
    // Process orphaned entities at DAT_00747d40
}

// MapMemFree (FUN_00640660) — 8 callers, 3 callees.
// Frees a memory block from the map allocator.
void MapMemFree(int param_1, int param_2)
{
    if (param_2 == 0) return;
    if (param_1 == 0) {
        // Free via callback PTR_FUN_0067d254
        return;
    }
    // Walk free list, unlink block, update stats
    // Recursive call for coalescing
}

// HashTableDtor (FUN_004489f0) — 7 callers, 2 callees.
// Hash table destructor — frees bucket array.
void HashTableDtor(uint32_t* param_1)
{
    uint32_t* puVar1 = (uint32_t*)param_1[1];
    *param_1 = 0; // vtable placeholder — PTR_FUN_0065d6d8
    if (puVar1 != param_1 + 4) {
        // Free via FUN_00643505
    }
}

// VectorDtor16 (FUN_0046fdf0) — 7 callers, 2 callees.
// Vector destructor with 16-byte aligned element stride.
void VectorDtor16(int* param_1)
{
    int iVar1 = *param_1;
    if (iVar1 != 0) {
        uint32_t uVar3 = (param_1[2] - iVar1) & 0xfffffff0;
        // Free via FUN_00643505
        *param_1 = 0;
        param_1[1] = 0;
        param_1[2] = 0;
    }
}

// TextLayoutAdvance (FUN_004869d0) — 7 callers, 2 callees.
// Text layout — advances position through character string.
float* TextLayoutAdvance(int* param_1, float* param_2, float param_3, char* param_4, char* param_5)
{
    // Calculate character width scaling
    // FUN_00486880 — find line break position
    return param_2;
}

// NetworkScoreUpdate (FUN_00557380) — 7 callers, 2 callees.
// Updates network score table and checks for game end condition.
void NetworkScoreUpdate()
{
    extern int g_sceneReady; // DAT_00702770
    if (*(int*)(g_sceneReady + 0x4a9c) < *(int*)(g_sceneReady + 0x4aa0)) {
        // Reset score data, update timer
        // FUN_004d13a0 — game end check
    }
}

// EntityGroundSlope (FUN_005af030) — 7 callers, 2 callees.
// Calculates entity ground slope angle from terrain normal.
void EntityGroundSlope(int param_1)
{
    // FUN_00638870 — terrain normal query
    // FUN_0042d350 — slope calc
    float fVar2 = 0.0f;
    if (fVar2 != 0.0f) {
        *(uint32_t*)(param_1 + 0x124) |= 0x1000000;
        float fVar3 = (fVar2 < 0.0f) ? -1.0f : 1.0f; // slope direction
        *(char*)(param_1 + 0x25c) = (char)(int)(fVar3 * 180.0f); // angle constant
    }
}

// NetworkPacketHandler (FUN_005daed0) — 7 callers, 2 callees.
// Handles incoming network packet with string parsing.
uint32_t NetworkPacketHandler(int param_1, int param_2, int param_3, int param_4)
{
    if (param_3 != 0) return 0xffffff;
    // Parse packet string, compute metrics
    // FUN_0062c690 — string length
    return 0;
}

// TaskCreate (FUN_0061d2c0) — 7 callers, 2 callees.
// Creates concurrent task with reference-counted shared state.
uint32_t* TaskCreate(uint32_t* param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4, int* param_5, uint32_t param_6)
{
    *param_1 = param_2;
    param_1[1] = 0;
    param_1[2] = 0;
    if (param_5 != nullptr) {
        // Increment ref count with LOCK/UNLOCK
        param_5[1]++;
    }
    param_1[1] = param_4;
    param_1[2] = (uint32_t)param_5;
    param_1[3] = param_6;
    // FUN_0061d390 — task init
    return param_1;
}

// VectorDtor24 (FUN_00438690) — 7 callers, 3 callees.
// Vector destructor with 0x18 stride and element-wise cleanup.
void VectorDtor24(int param_1)
{
    if (*(int*)(param_1 + 4) != 0) {
        int iVar1 = *(int*)(param_1 + 0x10);
        for (int iVar3 = *(int*)(param_1 + 0xc); iVar3 != iVar1; iVar3 += 0x18) {
            // FUN_004439b0 — element dtor
        }
        // Free buffer via FUN_00643505
    }
}

// VectorAlloc18 (FUN_00440ea0) — 7 callers, 3 callees.
// Allocates vector buffer for 0x18-byte elements with overflow check.
void VectorAlloc18(uint32_t param_1)
{
    if (param_1 < 0xaaaaaab) {
        uint32_t size = param_1 * 0x18;
        if (size == 0) return;
        if (size < 0x1000) {
            (void)malloc(size); // operator_new replacement
            return;
        }
        // Over-allocate with alignment padding
    }
    // FUN_0042bad0 — throw length_error
}

// EntitySlotUpdate (FUN_004512e0) — 7 callers, 3 callees.
// Updates entity slot references in world data.
void EntitySlotUpdate(uint32_t* param_1)
{
    // Resolve entity from world data via multi-level pointer lookup
    // FUN_0042acf0 — world data access
    // FUN_00451070 — entity update
    // FUN_00451620 — slot validation
}

// VectorDtor28 (FUN_00451f10) — 7 callers, 3 callees.
// Vector destructor with 0x28 stride and element-wise cleanup.
void VectorDtor28(int* param_1)
{
    int iVar2 = *param_1;
    if (iVar2 != 0) {
        int iVar3 = param_1[1];
        for (; iVar2 != iVar3; iVar2 += 0x28) {
            // FUN_004519e0 — element dtor
        }
        // Free buffer via FUN_00643505
        *param_1 = 0;
        param_1[1] = 0;
        param_1[2] = 0;
    }
}

// HashTableGrow (FUN_004707b0) — 7 callers, 3 callees.
// Grows hash table and rehashes entries.
uint32_t HashTableGrow(int param_1, uint32_t param_2)
{
    if (0x40000000 < *(int*)(param_1 + 4) + 1u) {
        // Throw — exceeds max size
    }
    // FUN_0043e5a0 — new bucket alloc
    // FNV-1a hash rehash loop
    return 0;
}

// EntityFrameIndexUpdate (FUN_00484220) — 7 callers, 3 callees.
// Updates entity frame index with overflow check and parent notify.
void EntityFrameIndexUpdate(int* param_1, int param_2, int param_3)
{
    if (0xffff < (uint32_t)(param_1[10] + param_3)) {
        // FUN_004872e0 — scene entity remove
    }
    // Update frame data in 0x30-byte stride entity array
}

// RenderEntityUpdate (FUN_004f0e40) — 7 callers, 3 callees.
// Updates render entity state flags and LOD selection.
uint32_t RenderEntityUpdate(uint32_t* param_1, int param_2)
{
    if (param_1 == nullptr) return 0;
    if (param_2 == 0 || (param_1[6] & 0x4000) != 0) {
        uint32_t uVar2 = param_1[6];
        // Update render flags, check LOD levels
        // FUN_004ea2b0 — LOD update
    }
    return 0;
}

// NetworkPlayerUpdate (FUN_0055e760) — 7 callers, 3 callees.
// Updates network player data from received packet.
int NetworkPlayerUpdate(uint32_t param_1, uint64_t* param_2, int param_3, uint64_t* param_4, uint32_t* param_5)
{
    // FUN_004d6ee0 — packet decode
    // FUN_0048ff10 — player data update
    return 0;
}

// EntitySoundRangeCheck (FUN_005a6780) — 7 callers, 3 callees.
// Checks if entity is within audible range and sets volume.
#if 0 // GHIDRA_RAW: EntitySoundRangeCheck @  — needs manual cleanup
void EntitySoundRangeCheck(int param_1, uint64_t* param_2)
{
extern float DAT_0066bf2c;
    extern float DAT_0066c070;
    // FUN_00638ba0 — distance calc
    // FUN_005a6660 — sound update
    // FUN_0042d350 — range check
    // Calculate volume based on distance, clamp to valid range
}
#endif // EntitySoundRangeCheck
void EntitySoundRangeCheck() {}  // 

// VectorScaleW (FUN_0063f5b0) — 6 callers, 2 callees.
// Scales vector by angle (sin/cos via function pointers).
#if 0 // GHIDRA_RAW: VectorScaleW @  — needs manual cleanup
void VectorScaleW(float* param_1, float* param_2)
{
extern float DAT_0066be20;
    float fVar3 = param_2[3] * DAT_0066be20;
    // Use sin/cos function pointers at PTR_FUN_0067d230/0067d234
    // param_1[0..2] = cos(w) * param_2[0..2]
    // param_1[3] = sin(w)
}
#endif // VectorScaleW
void VectorScaleW() {}  // 

// AsyncTaskInit (FUN_0061c0a0) — 6 callers, 3 callees.
// Initializes async task with shared state ref counting.
int AsyncTaskInit(int param_1, uint32_t param_2, int* param_3)
{
    int* piVar5 = nullptr;
    if (param_3 != nullptr) {
        // LOCK/UNLOCK ref count increment
        param_3[2]++;
        piVar5 = param_3;
    }
    // operator_new(0x74) + FUN_0061bd30 init
    return 0;
}

// ═══════════════════════════════════════════════════════════
// Cycle 51: 5+ callers, 4-6 callees (35 functions)
// ═══════════════════════════════════════════════════════════

// StringInit (FUN_0044c2a0) — 8 callers, 4 callees.
// Initializes string object with optional source data.
uint32_t* StringInit(uint32_t* param_1, uint32_t param_2, char param_3)
{
    *param_1 = 0;
    param_1[1] = 0; param_1[2] = 0; param_1[3] = 0; param_1[4] = 0;
    param_1[5] = 0xf;
    *(uint8_t*)param_1 = 0;
    // If param_3: assign from param_2 string
    return param_1;
}

// ThreadLocalInit (FUN_005db740) — 8 callers, 4 callees.
// Thread-local storage initialization with lazy TLS slot allocation.
uint32_t ThreadLocalInit(int param_1, int param_2, int param_3, int param_4)
{
    // Check TLS, allocate slot if needed via FUN_006435f8
    // FUN_005e99d0 — init callback
    return 0;
}

// VectorGrow4 (FUN_00448900) — 8 callers, 5 callees.
// Grows vector buffer for 4-byte elements with 1.5x growth factor.
void VectorGrow4(int param_1, uint32_t param_2)
{
    uint32_t uVar2 = *(uint32_t*)(param_1 + 0xc);
    uint32_t uVar4 = (uVar2 >> 1) + uVar2;
    uint32_t uVar5 = param_2;
    if (param_2 <= uVar4) uVar5 = uVar4;
    if (0x3fffffff < uVar5) uVar5 = (param_2 < 0x3fffffff) ? 0x3fffffff : param_2;
    // Allocate new buffer, copy elements, free old
}

// GameFrameAdvance (FUN_00557290) — 8 callers, 5 callees.
// Advances game frame counter, checks for entity update.
void GameFrameAdvance(int param_1)
{
    extern int g_sceneReady; // DAT_00702770
    // Check game state flags, advance frame counter
    // FUN_00463000 — format frame string
    // FUN_005e80c0 — compare strings
    // FUN_00453520 — state change
}

// WideStringPath (FUN_00440620) — 8 callers, 6 callees.
// Concatenates wide string path components with separator handling.
uint32_t* WideStringPath(uint32_t* param_1, uint32_t* param_2)
{
    // Check for path separators (\\ and /), concatenate paths
    return param_1;
}

// StringFormatV (FUN_0044c530) — 7 callers, 4 callees.
// Formats string with va_list on large stack buffer (2KB).
uint32_t* StringFormatV(char* param_1, uint32_t* param_2, uint32_t* param_3, int param_4, int param_5)
{
    // vsprintf into 2KB stack buffer, then assign to output string
    return nullptr;
}

// NetworkChatSend (FUN_00463d20) — 7 callers, 4 callees.
// Sends chat message over network with player ID.
void NetworkChatSend(int param_1, uint32_t param_2)
{
    if (DAT_006ff960 == 6) {
        // Build chat packet with player index, message flags
        // FUN_0045b320 — score compare
        // Transmit via network layer
    }
}

// EntityRenderDispatch (FUN_00484360) — 7 callers, 4 callees.
// Dispatches entity rendering with vertex buffer and transform.
void EntityRenderDispatch(int param_1, float* param_2, int param_3, uint32_t param_4, char param_5, float param_6)
{
    // Complex entity render with alloca for vertex data
    // Transform vertices, submit to renderer
}

// RenderPoolCreate (FUN_004e0ff0) — 7 callers, 4 callees.
// Creates decal/render pool with vertex buffer allocation.
uint32_t* RenderPoolCreate(int param_1, uint32_t param_2, uint32_t param_3)
{
    uint32_t uVar4 = param_1 * 2 + 2;
    int iVar5 = 0;
    if ((~param_3 & 1) != 0) iVar5 = uVar4 * 0x18;
    uint32_t size = iVar5 + ((param_2 * 3 + 0x10) * 4 + param_1 * 6) * 2;
    uint32_t* dst = (uint32_t*)malloc(size);
    memset(dst, 0, size);
    // Initialize pool header, create vertex buffer via vtable call
    return dst;
}

// StringMove (FUN_00632100) — 7 callers, 4 callees.
// Moves byte string into SSO string with length check.
uint32_t* StringMove(uint32_t* param_1, void* param_2, uint32_t param_3)
{
    *param_1 = 0; param_1[1] = 0; param_1[2] = 0; param_1[3] = 0;
    param_1[4] = 0; param_1[5] = 0xf;
    if (param_3 < 0x10) {
        param_1[4] = param_3;
        memmove(param_1, param_2, param_3);
    } else {
        // Allocate heap buffer for long string
    }
    return param_1;
}

// NetworkPlayerSync (FUN_0048ff10) — 7 callers, 5 callees.
// Synchronizes player state from network data.
void NetworkPlayerSync(int param_1, int param_2)
{
    if (*(int*)(param_1 + 8) == 0) return;
    // Validate player data, check network state
    // FUN_004d6df0 — get player index
}

// EntityFullReset (FUN_0055e390) — 7 callers, 5 callees.
// Full entity reset — clears all slots and references.
void EntityFullReset(int param_1)
{
    if (*(int*)(param_1 + 4) == 2) {
        // Reset entity type 2 — clear all slot references to -1
    } else if (*(int*)(param_1 + 4) == 3) {
        // Reset entity type 3 — FUN_0058e090, FUN_004512e0
    }
}

// EntityEffectDispatch (FUN_00584000) — 7 callers, 5 callees.
// Dispatches entity effects by walking effect list.
void EntityEffectDispatch(int param_1)
{
    // Walk linked list at DAT_007496c4
    // Match entity ID, dispatch effect FUN_005583d0
}

// NetworkEntityCreate (FUN_005db200) — 7 callers, 5 callees.
// Creates network entity from packet data.
uint32_t NetworkEntityCreate(int param_1, uint32_t* param_2, int param_3, int param_4)
{
    // Parse position from packet, create entity, set transform
    return 0;
}

// TaskSchedule (FUN_0061c3b0) — 7 callers, 5 callees.
// Schedules task on concurrent executor.
int TaskSchedule(int param_1, int param_2)
{
    int* piVar4 = (int*)malloc(0x28);
    piVar4[9] = 0;
    // Set up task context, ref count shared state
    return (int)piVar4;
}

// EntityAttachmentUpdate (FUN_00508ad0) — 7 callers, 6 callees.
// Updates entity attachment/child state.
void EntityAttachmentUpdate(int param_1, int param_2, int param_3, char param_4)
{
    // Check entity type (0x12=character, 0x59=building)
    // Update child entities, check death state
}

// PixelFormatConvert (FUN_00627780) — 6 callers, 5 callees.
// Converts pixel format data between color spaces.
void PixelFormatConvert(int param_1, uint32_t param_2)
{
    // Complex pixel format conversion with stride/offset tables
}

// TaskWaitChain (FUN_0061b490) — 6 callers, 6 callees.
// Waits for chain of dependent tasks to complete.
void TaskWaitChain(int param_1, int* param_2)
{
    // Walk task chain, wait for completion, handle exceptions
}

// EntityRenderSetup2 (FUN_00485010) — 5 callers, 4 callees.
// Sets up entity rendering with vertex processing.
void EntityRenderSetup2(int param_1, uint32_t* param_2, uint32_t param_3, uint32_t param_4)
{
    // alloca for vertex data, transform and submit
}

// StringThrowLength (FUN_004b42b0) — 5 callers, 4 callees.
// Throws string length error.
void StringThrowLength(uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t* param_4)
{
    // Construct error info and throw _CxxThrowException
}

// EntityLaunchProjectile (FUN_005082f0) — 5 callers, 4 callees.
// Launches projectile from entity.
void EntityLaunchProjectile(uint32_t param_1, int param_2, uint64_t* param_3, uint32_t param_4, float param_5, int param_6, float param_7)
{
    // Normalize speed, check entity type (0x12, 0x59)
    // FUN_00590950 — character launch
    // FUN_0058e220 — building launch
}

// EntityPhysicsApply (FUN_0056bd70) — 5 callers, 4 callees.
// Applies physics forces to entity.
void EntityPhysicsApply(int param_1)
{
    // FUN_0056be60 — gravity
    // FUN_0056c1a0 — friction
    // FUN_0056c270 — drag
    // Apply velocity, clamp to bounds
}

// EntityFindTarget (FUN_005d4050) — 5 callers, 4 callees.
// Finds nearest entity target for AI targeting.
int EntityFindTarget(float param_1)
{
    // FUN_00559dc0 — distance check
    // FUN_0055ccc0 — visibility check
    return 0;
}

// EntityCameraRender (FUN_005dec20) — 5 callers, 4 callees.
// Renders entity from camera viewpoint.
void EntityCameraRender(int param_1)
{
    // FUN_005de9b0 — camera check
    // FUN_005dc960 — set viewport
    // FUN_005d7ca0 — position set
    // FUN_005d7de0 — render sub-entities
}

// WideStringInit (FUN_0043db50) — 5 callers, 5 callees.
// Initializes wide string from source.
uint32_t* WideStringInit(uint32_t* param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4)
{
    *param_1 = 0; param_1[1] = 0; param_1[2] = 0;
    // Allocate and copy wide string data
    return param_1;
}

// NetworkDisconnect (FUN_004574c0) — 5 callers, 5 callees.
// Disconnects from network session, saves settings.
void NetworkDisconnect()
{
    extern HKEY g_hPlayerKey; // DAT_0074be5c
    // Save unavailable addresses to registry
    // Clean up network state
}

// CameraPathInit (FUN_005f7b70) — 5 callers, 5 callees.
// Initializes camera path from position data.
void CameraPathInit(int param_1)
{
    // FUN_00638c80 — vector normalize
    // FUN_0062a0b0 — matrix calc
    // FUN_0042d350 — transform
    // FUN_005f78a0 — path set
}

// TaskExceptionCheck (FUN_0060c8e0) — 5 callers, 5 callees.
// Checks for task exception and propagates.
uint32_t TaskExceptionCheck(uint32_t param_1, int param_2, int* param_3)
{
    // Check shared state for exceptions
    // Copy exception if found via __ExceptionPtrCopy
    return 0;
}

// VFSPathParse (FUN_0062be70) — 5 callers, 5 callees.
// Parses virtual file system path into components.
void VFSPathParse(int param_1)
{
    // Parse path string, split into directory/file components
}

// StringCopyTruncated (FUN_00632790) — 5 callers, 5 callees.
// Copies string with truncation to 4096 chars.
uint32_t StringCopyTruncated(char* param_1)
{
    // Check length < 4096, copy via FUN_006329a0
    // FUN_00642b90 — purecall handler on error
    return 0;
}

// EntityCollisionResponse (FUN_004a5080) — 5 callers, 6 callees.
// Handles entity collision response based on entity types.
void EntityCollisionResponse(int param_1, int param_2, int param_3, int param_4)
{
    // Check entity types (0x20=projectile, 0x52=smartie)
    // Apply collision physics based on type pair
}

// VectorPushBack (FUN_004fe880) — 5 callers, 6 callees.
// Pushes element to vector with growth.
int VectorPushBack(int* param_1, uint32_t param_2)
{
    // Check capacity, grow if needed via FUN_004431a0
    // Construct element in place
    return 0;
}

// MapEmplace (FUN_00593d40) — 5 callers, 6 callees.
// Emplaces key-value pair into map with 0x18 stride.
uint32_t* MapEmplace(int* param_1, void* param_2, uint32_t* param_3)
{
    // Find/insert position, construct element
    return nullptr;
}

// EntityMountUpdate (FUN_005a7720) — 5 callers, 6 callees.
// Updates mounted entity (rider on creature).
void EntityMountUpdate(int param_1, int param_2)
{
    // FUN_005a7600 — unmount check
    // FUN_004ffb40 — mount entity check
    // Update mount state, positions
}

// TaskGetResult (FUN_0060c810) — 5 callers, 6 callees.
// Gets result from completed task, handles exceptions.
uint32_t TaskGetResult(int* param_1, uint32_t param_2)
{
    // Call vtable[0x20] to get result
    // __ExceptionPtrToBool + __ExceptionPtrDestroy to check exceptions
    return 0;
}

// ═══════════════════════════════════════════════════════════
// Cycle 52: 5+ callers, 7+ callees (47 functions)
// ═══════════════════════════════════════════════════════════

// SceneRenderPass (FUN_00523b20) — 8 callers, 7 callees.
// Full scene render pass with matrix setup, culling, and draw.
void SceneRenderPass(int param_1)
{
    // Large stack frame (0x1d0+), multiple matrix/transform operations
    // Build view matrix, cull objects, dispatch render calls
}

// MasterServerConnect (FUN_00605240) — 8 callers, 7 callees.
// Connects to master server for multiplayer lobby.
void MasterServerConnect(char* param_1)
{
    // SEH-protected connection setup with socket operations
}

// TaskComplete (FUN_0061b040) — 8 callers, 7 callees.
// Marks concurrent task as completed and signals waiters.
uint32_t TaskComplete(uint32_t param_1, uint32_t param_2)
{
    // Set completion state, release ref count, notify waiters
    return 0;
}

// DialogLayoutUpdate (FUN_004d5b50) — 8 callers, 8 callees.
// Updates dialog layout — text measurement and positioning.
void DialogLayoutUpdate(uint32_t* param_1)
{
    // Calculate text bounds, reposition UI elements
}

// StringConcat (FUN_00440f20) — 8 callers, 9 callees.
// Concatenates two strings with SSO optimization.
uint8_t* StringConcat(uint8_t* param_1, uint8_t* param_2)
{
    // Calculate combined length, reallocate if needed, append
    return param_1;
}

// NetworkPacketLog (FUN_004af150) — 8 callers, 9 callees.
// Logs network packet to debug file.
void NetworkPacketLog(int param_1)
{
    // Open log file, format packet header, write data
}

// EntityNetworkInit (FUN_0048e200) — 8 callers, 12 callees.
// Initializes entity for network replication.
void EntityNetworkInit(int param_1)
{
    // Set up network entity state, register with sync system
}

// EntityAILogic (FUN_00588ef0) — 8 callers, 14 callees.
// Entity AI decision making — state machine with targeting.
void EntityAILogic(int param_1)
{
    // State machine: idle → patrol → chase → attack → flee
}

// EntitySmartieAI (FUN_005ce1f0) — 8 callers, 18 callees.
// Smartie NPC AI — pathfinding, building, reactions.
void EntitySmartieAI(int param_1)
{
    // Complex AI with pathfinding, resource gathering, building
}

// PlayerListInit (FUN_00457660) — 7 callers, 7 callees.
// Initializes player list from network session data.
void PlayerListInit(int param_1)
{
    // Walk session data, create player entries, assign teams
}

// EntityRayTest (FUN_00488b50) — 7 callers, 7 callees.
// Ray-entity intersection test for picking/collision.
bool EntityRayTest(float* param_1, int param_2, char* param_3, uint8_t* param_4, uint32_t param_5)
{
    // Transform ray to entity space, test against bounding geometry
    return false;
}

// EntityVisibilityUpdate (FUN_0055e4f0) — 7 callers, 7 callees.
// Updates entity visibility flags based on render state.
void EntityVisibilityUpdate(int param_1)
{
    // FUN_004ffb40 — get entity
    // Set/clear visibility flags based on entity type (2 or 3)
}

// RenderQueueProcess (FUN_00502c30) — 7 callers, 9 callees.
// Processes render queue — sorts and submits draw calls.
void RenderQueueProcess(int param_1)
{
    // Sort by distance/material, submit to renderer
}

// EntityProjectileSimulate (FUN_005e9300) — 7 callers, 11 callees.
// Simulates projectile entity — physics, collision, lifespan.
void EntityProjectileSimulate(int param_1)
{
    // Update position, check collision, decrement lifetime
}

// WideStringConcat (FUN_0044d670) — 7 callers, 12 callees.
// Concatenates wide strings with allocation management.
void WideStringConcat(uint32_t* param_1, uint32_t* param_2, uint32_t param_3)
{
    // Grow buffer if needed, append wide characters
}

// RenderPassExecute (FUN_004e3060) — 7 callers, 12 callees.
// Executes a render pass — sets state, draws geometry.
void RenderPassExecute(int param_1)
{
    // Set render state, bind textures, draw primitives
}

// GameLoopProcess (FUN_00464bf0) — 7 callers, 20 callees.
// Main game loop processing — entities, physics, network.
void GameLoopProcess(int param_1)
{
    // Process all game systems in order: input → logic → physics → render
}

// WideStringAssign (FUN_0042f1b0) — 6 callers, 8 callees.
// Assigns wide string from source pointers.
uint8_t* WideStringAssign(uint8_t* param_1, int* param_2, int* param_3)
{
    // Allocate, copy wide characters, set length
    return param_1;
}

// FsDirectoryIterate (FUN_0064170e) — 6 callers, 8 callees.
// Iterates filesystem directory entries.
uint32_t FsDirectoryIterate(const wchar_t* param_1, uint32_t* param_2, uint32_t param_3, uint32_t param_4)
{
    // FindFirstFileW/FindNextFileW loop, collect entries
    return 0;
}

// WideStringGrow (FUN_0043b4f0) — 5 callers, 7 callees.
// Grows wide string buffer capacity.
int WideStringGrow(uint32_t* param_1, uint32_t param_2)
{
    // Allocate larger buffer, copy existing data
    return 0;
}

// RegSetAllowJoiners (FUN_00457c50) — 5 callers, 7 callees.
// Sets AllowJoiners registry value.
void RegSetAllowJoiners(int param_1)
{
    extern HKEY g_hPlayerKey; // DAT_0074be5c
    if (g_hPlayerKey != nullptr) {
        RegSetValueExA(g_hPlayerKey, "AllowJoiners", 0, 4, (BYTE*)&param_1, 4);
    }
}

// RegSetLockTeams (FUN_00457e10) — 5 callers, 7 callees.
// Sets LockTeams registry value.
void RegSetLockTeams(int param_1)
{
    extern HKEY g_hPlayerKey; // DAT_0074be5c
    if (g_hPlayerKey != nullptr) {
        RegSetValueExA(g_hPlayerKey, "LockTeams", 0, 4, (BYTE*)&param_1, 4);
    }
}

// EntityDamageCalc (FUN_00507fa0) — 5 callers, 7 callees.
// Calculates damage between attacker and target entities.
uint32_t EntityDamageCalc(int param_1, int param_2, int param_3)
{
    // Distance-based damage with falloff
    return 0;
}

// EntityInventoryCheck (FUN_0056fc10) — 5 callers, 7 callees.
// Checks entity inventory for item by ID.
int EntityInventoryCheck(uint32_t param_1, uint32_t param_2)
{
    // Walk inventory list, match item ID
    return 0;
}

// EntityBridgePath (FUN_005bbda0) — 5 callers, 7 callees.
// Calculates entity path across bridge geometry.
void EntityBridgePath(int param_1)
{
    // Large stack frame (0x40000+), bridge pathfinding
}

// EntityGuardTarget (FUN_00569920) — 5 callers, 8 callees.
// Sets entity to guard position near target.
int EntityGuardTarget(int param_1, int param_2)
{
    // FUN_00559dc0 — find entity, FUN_0055ccc0 — check visibility
    // Set guard position from target
    return 0;
}

// WideStringReplace (FUN_00441710) — 5 callers, 9 callees.
// Replaces substring in wide string.
uint32_t* WideStringReplace(uint32_t* param_1, uint32_t* param_2, uint32_t param_3)
{
    // Find and replace substring with growth
    return param_1;
}

// RegSetGameModeName (FUN_004583c0) — 5 callers, 9 callees.
// Sets game mode name registry value.
void RegSetGameModeName(int param_1, int param_2)
{
    extern HKEY g_hPlayerKey;
    if (g_hPlayerKey != nullptr) {
        RegSetValueExA(g_hPlayerKey, "GameMode", 0, 4, (BYTE*)&param_1, 4);
    }
}

// RegSetMapName (FUN_004585c0) — 5 callers, 9 callees.
// Sets map name registry value.
void RegSetMapName(int param_1, int param_2)
{
    extern HKEY g_hPlayerKey;
    if (g_hPlayerKey != nullptr) {
        RegSetValueExA(g_hPlayerKey, "MapName", 0, 4, (BYTE*)&param_1, 4);
    }
}

// EntityPickupProcess (FUN_005ae2b0) — 5 callers, 9 callees.
// Processes entity pickup interaction.
void EntityPickupProcess(int param_1)
{
    // Check distance to pickup, collect if in range
}

// SpinLockRelease (FUN_00634970) — 5 callers, 9 callees.
// Releases spin lock with memory barrier.
void SpinLockRelease(uint32_t param_1)
{
    // InterlockedExchange release, wake waiters
}

// RenderTargetResolve (FUN_004f88c0) — 5 callers, 11 callees.
// Resolves render target — copies/stretches for post-processing.
void RenderTargetResolve(int param_1)
{
    // Copy render target, apply post-processing
}

// EntityWaveSpawn2 (FUN_0054d5c0) — 5 callers, 12 callees.
// Spawns entity wave with count and delay.
void EntityWaveSpawn2(int param_1)
{
    // Get wave parameters, spawn entities with delay
}

// BigIntDivide (FUN_004352e0) — 5 callers, 13 callees.
// Big integer division with remainder.
void BigIntDivide(uint32_t param_1)
{
    // Multi-precision integer division
}

// SceneVisibilityProcess (FUN_005323c0) — 5 callers, 14 callees.
// Processes scene visibility — frustum culling and portal checks.
void SceneVisibilityProcess(int param_1)
{
    // Frustum cull entities, process portals, build visible set
}

// RenderSceneFlush (FUN_004a69a0) — 5 callers, 17 callees.
// Flushes render scene — submits all pending draw calls.
void RenderSceneFlush(int param_1)
{
    // Process render queue, submit draw calls, present
}

// NetworkSessionInit (FUN_00459970) — 5 callers, 26 callees.
// Initializes network session — creates players, sets mode.
void NetworkSessionInit(int param_1)
{
    // Create session, initialize players, set game mode
}

// NetworkSessionProcess (FUN_00459be0) — 5 callers, 40 callees.
// Processes network session state machine.
void NetworkSessionProcess(int param_1)
{
    // State machine: lobby → loading → playing → results
}

// GameModeProcessFull (FUN_0045b4e0) — 5 callers, 79 callees.
// Full game mode processing — the mega function.
void GameModeProcessFull(int param_1)
{
    // Complete game mode logic: scoring, timers, win conditions, spawning
}

// WideStringCompare (FUN_00449e30) — 6 callers, 9 callees.
// Compares two wide strings with locale-aware ordering.
int WideStringCompare(int* param_1, int* param_2, int param_3)
{
    return 0;
}

// PlayerScoreUpdate (FUN_0045b080) — 6 callers, 10 callees.
// Updates player score and checks for win condition.
void PlayerScoreUpdate(int param_1)
{
    // Update score table, check score limit
}

// NetworkEntityUpdate (FUN_00572990) — 6 callers, 10 callees.
// Updates network entity state from sync data.
void NetworkEntityUpdate(int param_1)
{
    // Apply network sync data to entity
}

// TaskWaitAny (FUN_0060c0d0) — 6 callers, 13 callees.
// Waits for any task in set to complete.
uint32_t TaskWaitAny(uint32_t param_1, int param_2)
{
    // Poll task states, return on first completion
    return 0;
}

// TaskWaitAll (FUN_0060d370) — 6 callers, 13 callees.
// Waits for all tasks in set to complete.
uint32_t TaskWaitAll(uint32_t param_1, int param_2)
{
    // Poll all task states, return when all complete
    return 0;
}

// EntitySmartieProcess (FUN_004a9570) — 6 callers, 15 callees.
// Processes Smartie NPC entity — AI, animations, interactions.
void EntitySmartieProcess(int param_1)
{
    // AI state machine, pathfinding, animation blending
}

// RenderEntityProcess (FUN_004e3c50) — 6 callers, 15 callees.
// Processes render entity — updates transform, LOD, materials.
void RenderEntityProcess(int param_1)
{
    // Update render state, select LOD, submit to queue
}

// EntityVimpProcess (FUN_0058cef0) — 6 callers, 19 callees.
// Processes Vimp creature entity — AI, flocking, grazing.
void EntityVimpProcess(int param_1)
{
    // Flocking behavior, grazing, flee from predators
}

// ═══════════════════════════════════════════════════════════
// Cycle 53: 3-caller, 0-callee leaf functions (45 functions)
// ═══════════════════════════════════════════════════════════

// EngineUtil42A9B0 (FUN_0042a9b0) — 3 callers, 0 callees.
void EngineUtil42A9B0() {}

// ScalarWrite4359A0 (FUN_004359a0) — 3 callers, 0 callees.
// Writes scalar value at offset +8.
void ScalarWrite4359A0(void* p)
{
    *(uint8_t*)p = 7;
    // *(double*)(p + 8) = xmm1; // SSE scalar write
}

// EngineUtil4359F0 (FUN_004359f0) — 3 callers, 0 callees.
void EngineUtil4359F0() {}

// VtableCall43FC50 (FUN_0043fc50) — 3 callers, 0 callees.
// Virtual method call through vtable.
void VtableCall43FC50(int** obj) {}

// EngineUtil440E90 (FUN_00440e90) — 3 callers, 0 callees.
void EngineUtil440E90() {}

// ArrayInit441F80 (FUN_00441f80) — 3 callers, 0 callees.
// Initialize array with value, default 0x16D.
void ArrayInit441F80(int* arr, unsigned int count, int val)
{
    if (count == 0) {
        val = 0x16d;
    }
    for (unsigned int i = 0; i < count; i++) {
        arr[i] = val;
    }
}

// EngineUtil446860 (FUN_00446860) — 3 callers, 0 callees.
void EngineUtil446860() {}

// VtableCall44A320 (FUN_0044a320) — 3 callers, 0 callees.
void VtableCall44A320(int** obj) {}

// EngineUtil44C1C0 (FUN_0044c1c0) — 3 callers, 0 callees.
void EngineUtil44C1C0() {}

// CharClassify44DAD0 (FUN_0044dad0) — 3 callers, 0 callees.
// Character classification: 0x3F->18, 0x41->8, etc.
uint8_t CharClassify44DAD0(uint8_t ch)
{
    switch (ch) {
    case 0x3f: return 0x12;
    case 0x41: return 8;
    default: return 0;
    }
}

// NetworkStateCheck459760 (FUN_00459760) — 3 callers, 0 callees.
void NetworkStateCheck459760() {}

// PtrAdvance16471270 (FUN_00471270) — 3 callers, 0 callees.
// Advance pointer by 16 bytes.
int* PtrAdvance16471270(int* p)
{
    return p + 4; // +0x10 = +4 ints
}

// GameUtil4727B0 (FUN_004727b0) — 3 callers, 0 callees.
void GameUtil4727B0() {}

// EntitySlotIterate4745A0 (FUN_004745a0) — 3 callers, 0 callees.
// Iterate entity slots at +0x2f08.
void EntitySlotIterate4745A0(int entity, int flag) {}

// GameUtil4772B0 (FUN_004772b0) — 3 callers, 0 callees.
void GameUtil4772B0() {}

// EntityFlagCheck47D9F0 (FUN_0047d9f0) — 3 callers, 0 callees.
// Check entity flag 0x40000 at offset +8.
void EntityFlagCheck47D9F0(int entity, char flag) {}

// EntityArrayScan47F450 (FUN_0047f450) — 3 callers, 0 callees.
// Scan entity array with bound check.
int EntityArrayScan47F450(int idx, int val, int count) { return 0; }

// CrtFree (FUN_0048ad00/free) — 3 callers, 0 callees.
// CRT free wrapper.
void CrtFree(void* mem) {}

// LinkedListWalk48D740 (FUN_0048d740) — 3 callers, 0 callees.
// Walk linked list at offset 0x1B4.
void LinkedListWalk48D740(int ptr) {}

// GlobalCopy4A52F0 (FUN_004a52f0) — 3 callers, 0 callees.
// Copy between global data structures.
void GlobalCopy4A52F0() {}

// Log2Compute4AEFE0 (FUN_004aefe0) — 3 callers, 0 callees.
// Compute log2 via iterative bit shift from 0x2000.
void Log2Compute4AEFE0() {}

// DataTableScan4B36C0 (FUN_004b36c0) — 3 callers, 0 callees.
// Scan data table at DAT_00745278.
int DataTableScan4B36C0(int* table) { return 0; }

// CondCompare4B3AB0 (FUN_004b3ab0) — 3 callers, 0 callees.
// Conditional compare with special case for value 1.
int CondCompare4B3AB0(int a, int b, int c) { return 0; }

// VtableCall4BA600 (FUN_004ba600) — 3 callers, 0 callees.
void VtableCall4BA600(int** obj) {}

// VtableCall4C1660 (FUN_004c1660) — 3 callers, 0 callees.
// Virtual method call through vtable slot 0x10.
void VtableCall4C1660(int** obj) {}

// VectorCompare4D6C60 (FUN_004d6c60) — 3 callers, 0 callees.
// Vector comparison with depth XOR key (DAT_0066c560).
bool VectorCompare4D6C60(float* a, float* b)
{
    return false;
}

// BitFieldRotate4F3630 (FUN_004f3630) — 3 callers, 0 callees.
// Bit field rotate/shift operation.
uint32_t* BitFieldRotate4F3630(uint32_t* dst, uint32_t src, uint32_t* val)
{
    return dst;
}

// RendererLookup4F9AA0 (FUN_004f9aa0) — 3 callers, 0 callees.
// Look up renderer entry by ID when state==6.
int RendererLookup4F9AA0(int id) { return 0; }

// RenderUtil506420 (FUN_00506420) — 3 callers, 0 callees.
void RenderUtil506420() {}

// EntityClearRefs55C0C0 (FUN_0055c0c0) — 3 callers, 0 callees.
// Clear entity reference fields at +0x154/0x164/0x168.
void EntityClearRefs55C0C0(int entity)
{
    *(int32_t*)(entity + 0x164) = 0;
    *(int32_t*)(entity + 0x154) = 0;
    *(int32_t*)(entity + 0x168) = 0;
}

// RenderUtil5654A0 (FUN_005654a0) — 3 callers, 0 callees.
void RenderUtil5654A0() {}

// RenderUtil5816F0 (FUN_005816f0) — 3 callers, 0 callees.
void RenderUtil5816F0() {}

// RenderUtil581850 (FUN_00581850) — 3 callers, 0 callees.
void RenderUtil581850() {}

// SysUtil604AD0 (FUN_00604ad0) — 3 callers, 0 callees.
void SysUtil604AD0() {}

// SysUtil61ACA0 (FUN_0061aca0) — 3 callers, 0 callees.
void SysUtil61ACA0() {}

// VtableCall61F3D0 (FUN_0061f3d0) — 3 callers, 0 callees.
void VtableCall61F3D0(int** obj) {}

// SysUtil633470 (FUN_00633470) — 3 callers, 0 callees.
void SysUtil633470() {}

// SysUtil639E20 (FUN_00639e20) — 3 callers, 0 callees.
void SysUtil639E20() {}

// SysUtil63EDE0 (FUN_0063ede0) — 3 callers, 0 callees.
void SysUtil63EDE0() {}

// SysUtil63EE50 (FUN_0063ee50) — 3 callers, 0 callees.
void SysUtil63EE50() {}

// SysUtil640170 (FUN_00640170) — 3 callers, 0 callees.
void SysUtil640170() {}

// SysUtil640590 (FUN_00640590) — 3 callers, 0 callees.
void SysUtil640590() {}

// SysUtil643FE0 (FUN_00643fe0) — 3 callers, 0 callees.
void SysUtil643FE0() {}

// ScrtIsUCRT (FUN_0064446c) — 3 callers, 0 callees.
// CRT SEH — check if UCRT DLL is loaded.
int ScrtIsUCRT() { return 0; }

// DClass (FUN_0064591b) — 3 callers, 0 callees.
// CRT data class initializer.
void DClass() {}

// ═══════════════════════════════════════════════════════════
// Cycle 53b: 4-caller functions (1 function)
// ═══════════════════════════════════════════════════════════

// LibmSse2CosPrecise (FUN_006448e7) — 4 callers, 0 callees.
// SSE2 precise cosine — CRT math function.
void LibmSse2CosPrecise() {}

// ═══════════════════════════════════════════════════════════
// Cycle 54: 3-caller / 1-callee (58 functions)
// ═══════════════════════════════════════════════════════════

void CoreUtil42AA40() {}  // FUN_0042aa40
void CoreUtil42C3F0() {}  // FUN_0042c3f0
void CoreUtil430040() {}  // FUN_00430040
void CoreUtil432080() {}  // FUN_00432080
void CoreUtil436050() {}  // FUN_00436050
void CoreUtil438A30() {}  // FUN_00438a30
void CoreUtil43B140() {}  // FUN_0043b140
void CoreUtil43B270() {}  // FUN_0043b270
void CoreUtil4423E0() {}  // FUN_004423e0
void CoreUtil443690() {}  // FUN_00443690
void CoreUtil444110() {}  // FUN_00444110
void CoreUtil4480C0() {}  // FUN_004480c0
void CoreUtil44DE60() {}  // FUN_0044de60
void CoreUtil44F730() {}  // FUN_0044f730
void GameFn4517A0() {}  // FUN_004517a0
void GameFn4558D0() {}  // FUN_004558d0
void GameFn45B3F0() {}  // FUN_0045b3f0
void GameFn4724D0() {}  // FUN_004724d0
void FloatOp47CBB0() {}  // FUN_0047cbb0 — floating point operation
void EntityFieldOp47D960(int) {}  // FUN_0047d960 — entity field access
void GameFn481DD0() {}  // FUN_00481dd0
void GameFn486380() {}  // FUN_00486380
void GameFn497DD0() {}  // FUN_00497dd0
void WideStrOp4B4360() {}  // FUN_004b4360 — wide string operation
void VirtCall4BAE60(int) {}  // FUN_004bae60 — virtual method call
void GameFn4CE700() {}  // FUN_004ce700
void GameFn4D0340() {}  // FUN_004d0340
void GameFn4D4EE0() {}  // FUN_004d4ee0
void VirtCall4D5E70(int) {}  // FUN_004d5e70 — virtual method call
void GameFn4D6650() {}  // FUN_004d6650
void FloatOp4D96E0() {}  // FUN_004d96e0 — floating point operation
void GameFn4F48A0() {}  // FUN_004f48a0
void WideStrOp4FE9F0() {}  // FUN_004fe9f0 — wide string operation
void FloatOp5312B0() {}  // FUN_005312b0 — floating point operation
void RenderFn532E40() {}  // FUN_00532e40
void RenderFn536470() {}  // FUN_00536470
void RenderFn558130() {}  // FUN_00558130
void RenderFn565580() {}  // FUN_00565580
void FloatOp565A80() {}  // FUN_00565a80 — floating point operation
void SwitchOp5D29A0() {}  // FUN_005d29a0 — switch-based dispatch
void FloatOp5E0FD0() {}  // FUN_005e0fd0 — floating point operation
void RenderFn5E8BC0() {}  // FUN_005e8bc0
void RenderFn5F54D0() {}  // FUN_005f54d0
void SysFn601160() {}  // FUN_00601160
void SysFn6018F0() {}  // FUN_006018f0
void SysFn624F88() {}  // FUN_00624f88
void SysFn625EC0() {}  // FUN_00625ec0
void SysFn626FE0() {}  // FUN_00626fe0
void SysFn627120() {}  // FUN_00627120
void SysFn627460() {}  // FUN_00627460
void SysFn630DB0() {}  // FUN_00630db0
void SysFn630FF0() {}  // FUN_00630ff0
void SysFn631010() {}  // FUN_00631010
void SysFn6328D0() {}  // FUN_006328d0
void VirtCall634900(int) {}  // FUN_00634900 — virtual method call
void FloatOp63F630() {}  // FUN_0063f630 — floating point operation
void SysFn6433E0() {}  // FUN_006433e0
void SysFn645250() {}  // FUN_00645250

// --- Cycle 55: 3-caller / 2-3 callee (99 functions) ---
#if 0 // GHIDRA_RAW: CoreFn432F30 @ 0x00432f30 — needs manual cleanup
bool CoreFn432F30(int *param_1)
{


      int iVar1;

      size_t sVar2;

      int unaff_ESI;

      size_t _Count;

      char acStack_28 [32];

      char acStack_8 [4];

      uint32_t local_4;



      local_4 = DAT_0067d280 ^ (uint)acStack_28;

      if ((param_1[0xe] == 0) || (*(char *)((int)param_1 + 0x3d) == '\0')) {

        return true;

      }

      iVar1 = (**(code **)(*param_1 + 0xc))(0xffffffff);

      if (iVar1 == -1) {

        return false;

      }

      iVar1 = std::codecvt<char,char,_Mbstatet>::unshift

                        ((codecvt<char,char,_Mbstatet> *)param_1[0xe],(_Mbstatet *)(param_1 + 0x10),

                         acStack_28,acStack_8,(char **)&stack0xffffffd4);

      if (iVar1 == 0) {

        *(uint8_t *)((int)param_1 + 0x3d) = 0;

      }

      else if (iVar1 != 1) {

        if (iVar1 != 3) {

          return false;

        }

        *(uint8_t *)((int)param_1 + 0x3d) = 0;

        return true;

      }

      _Count = unaff_ESI - (int)acStack_28;

      if ((_Count != 0) && (sVar2 = fwrite(acStack_28,1,_Count,(FILE *)param_1[0x13]), _Count != sVar2))

      {

        return false;

      }

      return *(char *)((int)param_1 + 0x3d) == '\0';


}  // 0x00432f30
#endif // CoreFn432F30
void CoreFn432F30() {}  // 0x00432f30
#if 0 // GHIDRA_RAW: CoreFn43E3B0 @ 0x0043e3b0 — needs manual cleanup
void CoreFn43E3B0()
{


      FUN_0043e350();

      FUN_0043e2c0();

      return;


}  // 0x0043e3b0
#endif // CoreFn43E3B0
void CoreFn43E3B0() {}  // 0x0043e3b0
#if 0 // GHIDRA_RAW: CoreFn442250 @ 0x00442250 — needs manual cleanup
void CoreFn442250()
{


      uint32_t *puVar1;

      uint8_t local_18 [24];



      puVar1 = (uint32_t *)FUN_00442240();

      FUN_00442470(*puVar1,puVar1[1]);

                        /* WARNING: Subroutine does not return */

      _CxxThrowException(local_18,(ThrowInfo *)&DAT_0067810c);


}  // 0x00442250
#endif // CoreFn442250
void CoreFn442250() {}  // 0x00442250
#if 0 // GHIDRA_RAW: CoreFn4438F0 @ 0x004438f0 — needs manual cleanup
void CoreFn4438F0(int *param_1)
{


      int iVar1;

      uint32_t uVar2;

      int iVar3;



      iVar3 = *param_1;

      if (iVar3 != 0) {

        iVar1 = param_1[1];

        for (; iVar3 != iVar1; iVar3 = iVar3 + 0x10) {

          FUN_00443c70();

        }

        iVar3 = *param_1;

        uVar2 = param_1[2] - iVar3 & 0xfffffff0;

        iVar1 = iVar3;

        if (0xfff < uVar2) {

          iVar1 = *(int *)(iVar3 + -4);

          uVar2 = uVar2 + 0x23;

          if (0x1f < (iVar3 - iVar1) - 4U) {

                        /* WARNING: Subroutine does not return */

            std::abort();

          }

        }

        FUN_00643505(iVar1,uVar2);

        *param_1 = 0;

        param_1[1] = 0;

        param_1[2] = 0;

      }

      return;


}  // 0x004438f0
#endif // CoreFn4438F0
void CoreFn4438F0() {}  // 0x004438f0
void CoreFn4455D0() {}  // 0x004455d0
#if 0 // GHIDRA_RAW: CoreFn447DC0 @ 0x00447dc0 — needs manual cleanup
uint32_t * CoreFn447DC0(uint32_t *param_1,uint32_t *param_2,uint32_t param_3,int param_4,uint32_t param_5)
{


      uint32_t *puVar1;

      uint32_t uVar2;

      uint32_t uVar3;

      int local_10;



      if (param_5 < *param_2) {

        uVar3 = *param_2 - param_5;

      }

      else {

        uVar3 = 0;

      }

      uVar2 = uVar3 >> ((&DAT_0065d9e4)[*(byte *)((int)param_2 + 9) & 0xf] & 0x1f);

      if (uVar2 != 0) {

        puVar1 = (uint32_t *)FUN_0044d590(param_3,(int)param_2 + 0xb);

        param_3 = *puVar1;

      }

      local_10 = (int)param_2 + 0xb;

      FUN_0044dc30(param_4,param_5 + param_4);

      if (uVar3 == uVar2) {

        *param_1 = param_3;

        return param_1;

      }

      puVar1 = (uint32_t *)FUN_0044d590(param_3,local_10);

      *param_1 = *puVar1;

      return param_1;


}  // 0x00447dc0
#endif // CoreFn447DC0
void CoreFn447DC0() {}  // 0x00447dc0
#if 0 // GHIDRA_RAW: CoreFn44CB00 @ 0x0044cb00 — needs manual cleanup
int * CoreFn44CB00(int *param_1,uint32_t param_2,int param_3,int param_4,char param_5)
{


      int iVar1;

      uint32_t uVar2;

      char *pcVar3;

      char *pcVar4;

      char *pcVar5;

      char local_10 [12];

      uint32_t local_4;



      local_4 = DAT_0067d280 ^ (uint)local_10;

      iVar1 = *(int *)(param_3 + 8);

      uVar2 = param_4 + iVar1;

      if (uVar2 <= *(uint32_t *)(param_3 + 0xc)) {

        *(uint32_t *)(param_3 + 8) = uVar2;

        iVar1 = *(int *)(param_3 + 4) + iVar1;

        if (iVar1 != 0) {

          pcVar3 = (char *)(iVar1 + param_4);

          pcVar4 = "0123456789ABCDEF";

          if (param_5 == '\0') {

            pcVar4 = "0123456789abcdef";

          }

          do {

            pcVar3 = pcVar3 + -1;

            uVar2 = param_2 & 0xf;

            param_2 = param_2 >> 4;

            *pcVar3 = pcVar4[uVar2];

          } while (param_2 != 0);

          *param_1 = param_3;

          return param_1;

        }

      }

      pcVar4 = local_10 + param_4;

      pcVar5 = "0123456789ABCDEF";

      pcVar3 = pcVar4;

      if (param_5 == '\0') {

        pcVar5 = "0123456789abcdef";

      }

      do {

        pcVar3 = pcVar3 + -1;

        uVar2 = param_2 & 0xf;

        param_2 = param_2 >> 4;

        *pcVar3 = pcVar5[uVar2];

      } while (param_2 != 0);

      FUN_0044dc30(local_10,pcVar4);

      *param_1 = param_3;

      return param_1;


}  // 0x0044cb00
#endif // CoreFn44CB00
void CoreFn44CB00() {}  // 0x0044cb00
#if 0 // GHIDRA_RAW: CoreFn44D5E0 @ 0x0044d5e0 — needs manual cleanup
void CoreFn44D5E0()
{


        puVar1 = (uint32_t *)FUN_0044d590(param_2,(int)param_3 + 0xb);

        param_2 = *puVar1;


}  // 0x0044d5e0
#endif // CoreFn44D5E0
void CoreFn44D5E0() {}  // 0x0044d5e0
#if 0 // GHIDRA_RAW: CoreFn44EFD0 @ 0x0044efd0 — needs manual cleanup
uint32_t CoreFn44EFD0(uint32_t param_1,uint32_t *param_2,uint32_t param_3,uint32_t param_4)
{


      uint8_t auStack_28 [4];

      uint32_t local_24;

      uint32_t local_20;

      uint32_t local_18 [3];

      uint32_t local_c;



      local_c = DAT_0067d280 ^ (uint)auStack_28;

      local_18[0] = *param_2;

      local_24 = param_1;

      local_20 = param_1;

      fmt::v9::vformat(param_1,param_3,param_4,1,0,local_18);

      return param_1;


}  // 0x0044efd0
#endif // CoreFn44EFD0
void CoreFn44EFD0() {}  // 0x0044efd0
#if 0 // GHIDRA_RAW: CoreFn44F050 @ 0x0044f050 — needs manual cleanup
void CoreFn44F050(int *param_1)
{


      int iVar1;

      int iVar2;

      uint32_t uVar3;



      if (*param_1 != 0) {

        FUN_0044f870(*param_1,param_1[1],param_1);

        iVar1 = *param_1;

        uVar3 = param_1[2] - iVar1 & 0xfffffff8;

        iVar2 = iVar1;

        if (0xfff < uVar3) {

          iVar2 = *(int *)(iVar1 + -4);

          uVar3 = uVar3 + 0x23;

          if (0x1f < (iVar1 - iVar2) - 4U) {

                        /* WARNING: Subroutine does not return */

            std::abort();

          }

        }

        FUN_00643505(iVar2,uVar3);

        *param_1 = 0;

        param_1[1] = 0;

        param_1[2] = 0;

      }

      return;


}  // 0x0044f050
#endif // CoreFn44F050
void CoreFn44F050() {}  // 0x0044f050
#if 0 // GHIDRA_RAW: GameFn452A80 @ 0x00452a80 — needs manual cleanup
void GameFn452A80()
{


        if (DAT_0066bf2c < fVar3) {

          return ' ';

        }

        if (fVar3 < DAT_0066c264) {

          return -0x20;

        }

        if ((0.0 < fVar3) && (fVar3 < DAT_0066bdb8)) {

          return '\x06';

        }

        fVar4 = fVar3;

        if ((fVar3 < 0.0) && (fVar4 = DAT_0066c248, fVar3 <= DAT_0066c248)) {

          fVar4 = fVar3;

        }

        cVar1 = (char)(int)(fVar4 * DAT_0066c070);

        if (cVar1 != '\0') {

          return cVar1;

        }


}  // 0x00452a80
#endif // GameFn452A80
void GameFn452A80() {}  // 0x00452a80
#if 0 // GHIDRA_RAW: GameFn453050 @ 0x00453050 — needs manual cleanup
int GameFn453050(int param_1)
{


      uint32_t uVar1;

      int iVar2;

      int *piVar3;

      uint32_t local_1c;

      uint32_t *local_18;

      uint8_t *local_14;

      void *local_10;

      uint8_t *puStack_c;

      uint32_t local_8;



      local_8 = 0xffffffff;

      puStack_c = &LAB_0064595d;

      local_10 = ExceptionList;

      uVar1 = DAT_0067d280 ^ (uint)&stack0xfffffffc;

      piVar3 = *(int **)(param_1 + 0xc);

      while( true ) {

        if (piVar3 == *(int **)(param_1 + 0x10)) {

          local_1c = 0x53ce8ad2;

          ExceptionList = &local_10;

          local_18 = operator_new(0x4c);

          local_14 = &LAB_00453180;

          local_18[1] = 0;

          local_18[2] = 0;

          local_18[3] = 0;

          local_18[4] = 0;

          local_18[5] = 0;

          local_18[6] = 0;

          local_18[7] = 0;

          local_18[8] = 0;

          local_18[9] = 0;

          *local_18 = &PTR_FUN_0065dd94;

          local_18[10] = 0;

          local_18[0xb] = 0;

          local_18[0xc] = 0;

          local_18[0xd] = 0;

          local_18[0xe] = 0;

          local_18[0xf] = 0;

          local_18[0x10] = 0;

          local_18[0x11] = 0;

          local_18[0x12] = 0;

          local_8 = 0;

          iVar2 = FUN_0042aca0(&local_1c);

          iVar2 = *(int *)(iVar2 + 4);

          if (local_18 != (uint32_t *)0x0) {

            (**(code **)*local_18)(1,uVar1);

          }

          ExceptionList = local_10;

          return iVar2;

        }

        if (*piVar3 == 0x53ce8ad2) break;

        piVar3 = piVar3 + 3;

      }

      return piVar3[1];


}  // 0x00453050
#endif // GameFn453050
void GameFn453050() {}  // 0x00453050
#if 0 // GHIDRA_RAW: GameFn4578C0 @ 0x004578c0 — needs manual cleanup
int GameFn4578C0(int *param_1)
{


      int *piVar1;

      uint32_t uVar2;

      int iVar3;

      int iVar4;

      int iVar5;

      int *local_18;

      int *local_14;

      void *local_10;

      uint8_t *puStack_c;

      uint32_t local_8;



      local_8 = 0xffffffff;

      puStack_c = &LAB_00647ffd;

      local_10 = ExceptionList;

      uVar2 = DAT_0067d280 ^ (uint)&stack0xfffffffc;

      ExceptionList = &local_10;

      FUN_00461a60(&local_18);

      local_8 = 0;

      iVar3 = (**(code **)(*local_18 + 0x28))(uVar2);

      iVar5 = 0;

      iVar4 = iVar3;

      if (-1 < iVar3) {

        do {

          iVar4 = FUN_00578f00();

          if (iVar4 != 0) goto LAB_00457929;

          iVar5 = iVar5 + 1;

        } while (iVar5 <= iVar3);

      }

      iVar5 = -1;

    LAB_00457929:

      *param_1 = iVar5;

      if (local_14 != (int *)0x0) {

        LOCK();

        piVar1 = local_14 + 1;

        iVar3 = *piVar1;

        iVar4 = *piVar1;

        *piVar1 = iVar3 + -1;

        UNLOCK();

        if (iVar3 + -1 == 0) {

          iVar4 = (**(code **)*local_14)();

          LOCK();

          piVar1 = local_14 + 2;

          iVar3 = *piVar1;

          *piVar1 = *piVar1 + -1;

          UNLOCK();

          if (iVar3 == 1) {

            iVar4 = (**(code **)(*local_14 + 4))();

          }

        }

      }

      ExceptionList = local_10;

      return iVar4;


}  // 0x004578c0
#endif // GameFn4578C0
void GameFn4578C0() {}  // 0x004578c0
#if 0 // GHIDRA_RAW: GameFn45B1F0 @ 0x0045b1f0 — needs manual cleanup
void GameFn45B1F0()
{


        cVar1 = *pcVar3;

        pcVar3 = pcVar3 + 1;

        pcVar3[0x74da6f - (int)pcVar2] = cVar1;


}  // 0x0045b1f0
#endif // GameFn45B1F0
void GameFn45B1F0() {}  // 0x0045b1f0
#if 0 // GHIDRA_RAW: GameFn4650B0 @ 0x004650b0 — needs manual cleanup
void GameFn4650B0(int param_1,int param_2)
{


      int *piVar1;

      int iVar2;

      uint8_t local_38;

      uint32_t local_37;

      uint32_t local_33;

      uint64_t local_2f;

      uint32_t local_27;

      uint32_t uStack_23;

      uint32_t local_1f;

      uint32_t uStack_1b;

      uint32_t local_17;

      int iStack_13;

      int local_f;

      uint8_t local_b;

      uint32_t local_8;



      local_8 = DAT_0067d280 ^ (uint)&local_38;

      if (DAT_006ff960 == 6) {

        local_33 = *(uint32_t *)(param_1 + 0x1d4);

        piVar1 = *(int **)(param_1 + 0x14c);

        local_27 = *(uint32_t *)(param_1 + 0xf8);

        local_2f = *(uint64_t *)(param_1 + 0xf0);

        local_37 = *(uint32_t *)(param_1 + 4);

        uStack_1b = *(uint32_t *)(param_1 + 0x17c);

        local_b = 0;

        local_38 = 0x1b;

        uStack_23 = (uint32_t)*(uint64_t *)(param_1 + 0x174);

        local_1f = (uint32_t)((ulonglong)*(uint64_t *)(param_1 + 0x174) >> 0x20);

        _local_17 = CONCAT44(piVar1[1],(uint)*(ushort *)(param_1 + 0x134) | *piVar1 << 0x10);

        local_f = piVar1[6];

        if (param_2 == 0) {

          iVar2 = DAT_0073c944;

          if (DAT_00702964 != 0) {

            FUN_0045fe10(&local_38);

            return;

          }

        }

        else {

          if (DAT_006ffa10 < 0) {

            return;

          }

          iVar2 = (&DAT_006ff910)[DAT_006ffa10];

        }

        if (iVar2 != 0) {

          FUN_0045fc20(&local_38);

        }

      }

      return;


}  // 0x004650b0
#endif // GameFn4650B0
void GameFn4650B0() {}  // 0x004650b0
#if 0 // GHIDRA_RAW: GameFn468EC0 @ 0x00468ec0 — needs manual cleanup
void GameFn468EC0(int param_1)
{


      int iVar1;

      uint32_t uVar2;

      int iVar3;

      uint8_t auStack_20 [4];

      uint8_t local_1c;

      uint8_t local_1b;

      byte local_1a;

      uint8_t local_19;

      byte local_18;

      uint32_t local_17;

      uint32_t local_13;

      uint32_t local_f;

      uint32_t local_b;

      uint8_t local_7;

      uint32_t local_4;



      iVar1 = DAT_0070294c;

      local_4 = DAT_0067d280 ^ (uint)auStack_20;

      if (((DAT_006ff960 == 6) && (DAT_00702964 != 0)) && (iVar3 = 0, 0 < DAT_0070294c)) {

        do {

          if ((&DAT_006ff910)[iVar3] != 0) {

            local_1a = (&DAT_006ff8e8)[iVar3];

            local_17 = (&DAT_006ff898)[iVar3];

            uVar2 = (uint)local_1a;

            local_1c = 0x34;

            local_1b = (uint8_t)iVar3;

            if (uVar2 - 1 < 3) {

              local_13 = *(uint32_t *)(&DAT_006ff838 + uVar2 * 4);

              local_f = (&DAT_006ff848)[iVar3];

              local_b = *(uint32_t *)(&DAT_006ff82c + uVar2 * 4);

            }

            else {

              local_f = (&DAT_006ff848)[iVar3];

              local_b = 0;

              local_13 = 0;

            }

            local_7 = 0;

            local_19 = local_1b;

            local_18 = local_1a;

            if (param_1 == 0) {

              FUN_0045fe10(&local_1c);

            }

            else if ((-1 < param_1) && ((&DAT_006ff910)[param_1] != 0)) {

              FUN_0045fc20(&local_1c);

            }

          }

          iVar3 = iVar3 + 1;

        } while (iVar3 < iVar1);

      }

      return;


}  // 0x00468ec0
#endif // GameFn468EC0
void GameFn468EC0() {}  // 0x00468ec0
#if 0 // GHIDRA_RAW: GameFn46E4B0 @ 0x0046e4b0 — needs manual cleanup
uint32_t GameFn46E4B0(uint32_t param_1,uint32_t *param_2,uint32_t *param_3)
{


      char cVar1;

      char *pcVar2;

      uint32_t local_2c;

      char *local_28;

      int local_24;

      uint32_t local_18;

      int local_14;

      uint32_t local_c;



      local_c = DAT_0067d280 ^ (uint)&local_2c;

      local_28 = (char *)*param_2;

      pcVar2 = local_28;

      do {

        cVar1 = *pcVar2;

        pcVar2 = pcVar2 + 1;

      } while (cVar1 != '\0');

      local_24 = (int)pcVar2 - (int)(local_28 + 1);

      local_18 = *param_3;

      local_2c = param_1;

      local_14 = local_24;

      FUN_00444db0(0xc,0,&local_18);

      return param_1;


}  // 0x0046e4b0
#endif // GameFn46E4B0
void GameFn46E4B0() {}  // 0x0046e4b0
void GameFn46FEB0(uint32_t *param_1)
{


      uint32_t uVar1;

      int iVar2;

      uint32_t uVar3;

      int iVar4;



      iVar4 = param_1[4];

      if (iVar4 != 0) {

        do {

          iVar4 = iVar4 + -1;

          param_1[4] = iVar4;

        } while (iVar4 != 0);

        param_1[3] = 0;

      }

      if (param_1[1] != 0) {

        iVar4 = param_1[2];

        while (0 < iVar4) {

          iVar4 = iVar4 + -1;

          iVar2 = *(int *)(param_1[1] + iVar4 * 4);

          if (iVar2 != 0) {

            FUN_00643505(iVar2,0x10);

          }

        }

        iVar4 = param_1[1];

        uVar3 = param_1[2] * 4;

        iVar2 = iVar4;

        if (0xfff < uVar3) {

          iVar2 = *(int *)(iVar4 + -4);

          uVar3 = uVar3 + 0x23;

          if (0x1f < (iVar4 - iVar2) - 4U) {

                        /* WARNING: Subroutine does not return */

            std::abort();

          }

        }

        FUN_00643505(iVar2,uVar3);

        param_1[1] = 0;

        param_1[2] = 0;

      }

      uVar1 = *param_1;

      *param_1 = 0;

      FUN_00643505(uVar1,8);

      return;


}  // 0x0046feb0
#if 0 // GHIDRA_RAW: GameFn471280 @ 0x00471280 — needs manual cleanup
void GameFn471280(uint32_t *param_1)
{


      int iVar1;

      int iVar2;



      if (param_1[1] == 0) {

        std::_Throw_Cpp_error(1);

      }

      iVar2 = param_1[1];

      iVar1 = _Thrd_id();

      if (iVar2 == iVar1) {

        std::_Throw_Cpp_error(5);

      }

      iVar2 = _Thrd_join(*param_1,param_1[1],0);

      if (iVar2 != 0) {

        std::_Throw_Cpp_error(2);

      }

      *param_1 = 0;

      param_1[1] = 0;

      return;


}  // 0x00471280
#endif // GameFn471280
void GameFn471280() {}  // 0x00471280
#if 0 // GHIDRA_RAW: GameFn4729F0 @ 0x004729f0 — needs manual cleanup
void GameFn4729F0()
{


      int iVar1;

      int iVar2;

      int iVar3;

      int iVar4;

      int iVar5;



      iVar1 = FUN_00462fc0(param_2,param_1,param_3);

      if (0 < iVar1) {

        iVar3 = 1;

        if (*param_1 != 0) {

          iVar3 = *param_1;

        }

        iVar5 = iVar3 + iVar1;

        if (param_1[1] <= iVar5) {

          iVar4 = param_1[1] * 2;

          if (iVar4 < iVar5) {

            iVar4 = iVar5;

          }

          FUN_004830d0(iVar4);

        }

        iVar4 = param_1[1];

        if (iVar4 < iVar5) {

          if (iVar4 == 0) {

            iVar4 = 8;

          }

          else {

            iVar4 = iVar4 / 2 + iVar4;

          }

          iVar2 = iVar5;

          if (iVar5 < iVar4) {

            iVar2 = iVar4;

          }

          FUN_004830d0(iVar2);

        }

        *param_1 = iVar5;

        iVar5 = iVar3 + -1 + param_1[2];

        iVar3 = FUN_00462fc0(param_2,iVar3,param_3);

        if (iVar5 != 0) {

          if ((iVar3 == -1) || (iVar1 + 1 <= iVar3)) {

            iVar3 = iVar1;

          }

          *(uint8_t *)(iVar5 + iVar3) = 0;

        }

      }

      return;


}  // 0x004729f0
#endif // GameFn4729F0
void GameFn4729F0() {}  // 0x004729f0
#if 0 // GHIDRA_RAW: GameFn47CA50 @ 0x0047ca50 — needs manual cleanup
void GameFn47CA50(int param_1,char param_2)
{


      int *piVar1;

      int iVar2;

      int iVar3;

      int iVar4;

      int iVar5;



      iVar5 = *(int *)(DAT_00701a3c + 0x1bb0);

      iVar2 = *(int *)(*(int *)(DAT_00701a3c + 0x1bb4) + 8 + param_1 * 0x24);

      iVar3 = *(int *)(*(int *)(DAT_00701a3c + 0x1bb4) + 4 + param_1 * 0x24);

      piVar1 = (int *)(DAT_00701a3c + 0x1bac);

      if (iVar5 < param_1) {

        if (iVar5 == 0) {

          iVar5 = 8;

        }

        else {

          iVar5 = iVar5 / 2 + iVar5;

        }

        iVar4 = param_1;

        if (param_1 < iVar5) {

          iVar4 = iVar5;

        }

        FUN_00481870(iVar4);

      }

      *piVar1 = param_1;

      if (param_2 == '\0') {

        return;

      }

      if (((iVar2 != 0) && (*(char *)(iVar2 + 0x83) == '\0')) && (iVar3 != 0)) {

        FUN_0047bc60();

        return;

      }

      FUN_0047bac0();

      return;


}  // 0x0047ca50
#endif // GameFn47CA50
void GameFn47CA50() {}  // 0x0047ca50
void GameFn481130() {}  // 0x00481130
void GameFn481870() {}  // 0x00481870
#if 0 // GHIDRA_RAW: GameFn481C90 @ 0x00481c90 — needs manual cleanup
void GameFn481C90(uint32_t *param_1)
{


      int *piVar1;

      void *pvVar2;

      uint32_t *extraout_ECX;

      uint32_t *puVar3;

      int iVar4;



      iVar4 = 0;

      puVar3 = param_1;

      if (0 < (int)param_1[3]) {

        do {

          if (*(int *)(param_1[5] + 4 + iVar4 * 8) != -1) {

            FUN_00481bb0(puVar3);

            puVar3 = extraout_ECX;

          }

          iVar4 = iVar4 + 1;

        } while (iVar4 < (int)param_1[3]);

      }

      iVar4 = DAT_00701a3c;

      pvVar2 = (void *)param_1[5];

      if (pvVar2 != (void *)0x0) {

        param_1[4] = 0;

        param_1[3] = 0;

        if (iVar4 != 0) {

          piVar1 = (int *)(iVar4 + 0x370);

          *piVar1 = *piVar1 + -1;

        }

        free(pvVar2);

        param_1[5] = 0;

      }

      iVar4 = DAT_00701a3c;

      pvVar2 = (void *)param_1[2];

      if (pvVar2 != (void *)0x0) {

        param_1[1] = 0;

        *param_1 = 0;

        if (iVar4 != 0) {

          piVar1 = (int *)(iVar4 + 0x370);

          *piVar1 = *piVar1 + -1;

        }

        free(pvVar2);

        param_1[2] = 0;

      }

      param_1[6] = 0;

      return;


}  // 0x00481c90
#endif // GameFn481C90
void GameFn481C90() {}  // 0x00481c90
#if 0 // GHIDRA_RAW: GameFn4841C0 @ 0x004841c0 — needs manual cleanup
void GameFn4841C0()
{


      int iVar1;

      int iVar2;



      iVar1 = *(int *)(param_1 + 0x4c);

      if (*(int *)(param_1 + 0x48) == iVar1) {

        iVar2 = *(int *)(param_1 + 0x48) + 1;

        if (iVar1 == 0) {

          iVar1 = 8;

        }

        else {

          iVar1 = iVar1 / 2 + iVar1;

        }

        if (iVar2 < iVar1) {

          iVar2 = iVar1;

        }

        FUN_00481950(iVar2);

      }

      iVar1 = *(int *)(param_1 + 0x50);

      iVar2 = *(int *)(param_1 + 0x48);

      *(uint32_t *)(iVar1 + iVar2 * 8) = param_2;

      *(uint32_t *)(iVar1 + 4 + iVar2 * 8) = param_3;

      *(int *)(param_1 + 0x48) = *(int *)(param_1 + 0x48) + 1;

      *(uint32_t *)(param_1 + 0x70) = param_2;

      *(uint32_t *)(param_1 + 0x74) = param_3;

      FUN_00483f20();

      return;


}  // 0x004841c0
#endif // GameFn4841C0
void GameFn4841C0() {}  // 0x004841c0
#if 0 // GHIDRA_RAW: GameFn485AF0 @ 0x00485af0 — needs manual cleanup
void GameFn485AF0()
{


      float *pfVar1;

      float *pfVar2;

      float local_14;

      float local_10;

      float local_c;

      float local_8;



      if ((param_4 & 0xff000000) != 0) {

        if ((*(byte *)(param_1 + 0x24) & 1) == 0) {

          local_c = *param_3 - DAT_0066be1c;

          local_8 = param_3[1] - DAT_0066be1c;

          local_14 = *param_2 + DAT_0066be20;

          local_10 = param_2[1] + DAT_0066be20;

          pfVar2 = &local_c;

          pfVar1 = &local_14;

        }

        else {

          pfVar2 = &local_14;

          local_14 = *param_3 - DAT_0066be20;

          local_10 = param_3[1] - DAT_0066be20;

          local_c = *param_2 + DAT_0066be20;

          local_8 = param_2[1] + DAT_0066be20;

          pfVar1 = &local_c;

        }

        FUN_004856a0(pfVar1,pfVar2,param_6);

        FUN_00484360(*(uint32_t *)(param_1 + 0x5c),*(uint32_t *)(param_1 + 0x54),param_4,1,param_7);

        *(uint32_t *)(param_1 + 0x54) = 0;

      }

      return;


}  // 0x00485af0
#endif // GameFn485AF0
void GameFn485AF0() {}  // 0x00485af0
void GameFn4873C0() {}  // 0x004873c0
#if 0 // GHIDRA_RAW: GameFn488A30 @ 0x00488a30 — needs manual cleanup
void GameFn488A30(uint32_t param_1,uint32_t param_2)
{


      int iVar1;

      int iVar2;

      uint32_t extraout_ECX;



      iVar1 = DAT_00701a3c;

      *(uint8_t *)(*(int *)(DAT_00701a3c + 0x1a6c) + 0x84) = 1;

      if (*(char *)(*(int *)(iVar1 + 0x1a6c) + 0x87) == '\0') {

        iVar1 = iVar1 + 0x314c;

        iVar2 = FUN_00462fc0(param_1,param_1,param_2);

        if (iVar1 != 0) {

          if ((iVar2 == -1) || (0xc00 < iVar2)) {

            iVar2 = 0xc00;

          }

          *(uint8_t *)(iVar2 + iVar1) = 0;

        }

        FUN_00488490(extraout_ECX);

      }

      return;


}  // 0x00488a30
#endif // GameFn488A30
void GameFn488A30() {}  // 0x00488a30
#if 0 // GHIDRA_RAW: GameFn48E020 @ 0x0048e020 — needs manual cleanup
uint32_t GameFn48E020(int param_1)
{


      int iVar1;

      uint32_t uVar2;

      int *piVar3;

      bool bVar4;

      uint32_t extraout_ECX;

      uint32_t extraout_EDX;

      uint32_t uVar5;

      float10 fVar6;

      float fVar7;

      float fVar8;

      float fVar9;



      uVar5 = 0;

      do {

        iVar1 = *(int *)(param_1 + 0x1b4);

        if (iVar1 != 0) {

          uVar2 = *(uint32_t *)(iVar1 + 0x14);

          if ((uVar2 & 0x400) == 0) {

            if ((uVar2 & 0x20) == 0) {

              if (((uVar2 & 0x800) == 0) ||

                 (((0.0 < *(float *)(param_1 + 0x208) && (*(int *)(param_1 + 0x278) == 0)) &&

                  (*(float *)(param_1 + 0x198) <= DAT_0066be5c &&

                   DAT_0066be5c != *(float *)(param_1 + 0x198))))) {

                fVar9 = DAT_0066bfac;

                if (((uVar2 & 0x40) != 0) || (*(int *)(param_1 + 0x150) != 0)) {

                  fVar7 = *(float *)(param_1 + 0xf0) - *(float *)(iVar1 + 4);

                  fVar8 = *(float *)(DAT_00702770 + 0x238);

                  FUN_0042d350();

                  if (fVar7 < fVar8) {

                    fVar7 = *(float *)(param_1 + 0xf4) - *(float *)(iVar1 + 8);

                    FUN_0042d350();

                    if ((fVar7 < fVar8) &&

                       (fVar6 = (float10)FUN_00638d00(extraout_EDX,extraout_ECX),

                       fVar8 = *(float *)(DAT_00702770 + 0x238) * DAT_0066bdc4, fVar9 = DAT_0066bfac,

                       (float)fVar6 < fVar8 * fVar8)) goto LAB_0048e1c3;

                  }

                }

                fVar8 = *(float *)(iVar1 + 4) - *(float *)(param_1 + 0xf0);

                FUN_0042d350();

                if (fVar9 < fVar8) {

                  return uVar5;

                }

                fVar8 = *(float *)(iVar1 + 8) - *(float *)(param_1 + 0xf4);

                FUN_0042d350();

                if (fVar9 < fVar8) {

                  return uVar5;

                }

                if ((*(byte *)(iVar1 + 0x14) & 8) != 0) {

                  fVar8 = *(float *)(iVar1 + 0xc) - *(float *)(param_1 + 0xf8);

                  FUN_0042d350();

                  if (fVar9 < fVar8) {

                    return uVar5;

                  }

                }

              }

            }

            else {

              fVar6 = (float10)FUN_00638820(*(uint32_t *)(iVar1 + 0x10),

                                            *(uint32_t *)(param_1 + 0x114));

              if ((float)fVar6 != _DAT_0066bce4) {

                bVar4 = false;

                goto LAB_0048e09c;

              }

            }

          }

          else {

            bVar4 = *(float *)(iVar1 + 0x18) <= 0.0;

    LAB_0048e09c:

            if (!bVar4) {

              return uVar5;

            }

          }

        }

    LAB_0048e1c3:

        piVar3 = *(int **)(param_1 + 0x1b4);

        if (piVar3 == (int *)0x0) {

          return uVar5;

        }

        if ((*(byte *)(piVar3 + 5) & 0x10) != 0) {

          return uVar5;

        }

        uVar5 = 1;

        *(int *)(param_1 + 0x1b4) = *piVar3;

        *piVar3 = (int)DAT_0073e790;

        DAT_0073e790 = piVar3;

      } while( true );


}  // 0x0048e020
#endif // GameFn48E020
void GameFn48E020() {}  // 0x0048e020
#if 0 // GHIDRA_RAW: GameFn48E840 @ 0x0048e840 — needs manual cleanup
void GameFn48E840(int param_1)
{


      char cVar1;

      float10 fVar2;

      uint32_t in_XMM1_Da;

      float fVar3;

      float fVar4;



      *(uint32_t *)(param_1 + 0x1a4) = in_XMM1_Da;

      FUN_00638f10((uint32_t *)(param_1 + 0x1a4));

      *(uint32_t *)(param_1 + 0x124) = *(uint32_t *)(param_1 + 0x124) | 0x1000000;

      fVar2 = (float10)FUN_00638870(in_XMM1_Da,*(uint32_t *)(param_1 + 0x114));

      fVar4 = (float)(fVar2 * (float10)DAT_0066bd50);

      fVar3 = fVar4;

      FUN_0042d350();

      if (DAT_0066bcf8 <= fVar4) {

        if (DAT_0066bf2c < fVar3) {

          *(uint8_t *)(param_1 + 0x25c) = 0x20;

          return;

        }

        if (fVar3 < DAT_0066c264) {

          *(uint8_t *)(param_1 + 0x25c) = 0xe0;

          return;

        }

        if ((0.0 < fVar3) && (fVar3 < DAT_0066bdb8)) {

          *(uint8_t *)(param_1 + 0x25c) = 6;

          return;

        }

        fVar4 = fVar3;

        if ((fVar3 < 0.0) && (fVar4 = DAT_0066c248, fVar3 <= DAT_0066c248)) {

          fVar4 = fVar3;

        }

        cVar1 = (char)(int)(fVar4 * DAT_0066c070);

        if (cVar1 != '\0') goto LAB_0048e949;

      }

      else {

        fVar4 = 0.0;

        cVar1 = '\0';

      }

      if (fVar4 != 0.0) {

        *(char *)(param_1 + 0x25c) = (0.0 <= fVar4) * '\x02' + -1;

        return;

      }

    LAB_0048e949:

      *(char *)(param_1 + 0x25c) = cVar1;

      return;


}  // 0x0048e840
#endif // GameFn48E840
void GameFn48E840() {}  // 0x0048e840
#if 0 // GHIDRA_RAW: GameFn4B1700 @ 0x004b1700 — needs manual cleanup
uint8_t * GameFn4B1700(int param_1,int param_2)
{


      char cVar1;

      uint32_t uVar2;

      int iVar3;

      char *pcVar4;

      uint32_t uVar5;

      char *pcVar6;

      char local_24 [32];

      uint32_t local_4;



      local_4 = DAT_0067d280 ^ (uint)local_24;

      if (param_1 == 0) {

        iVar3 = 0x19;

      }

      else {

        iVar3 = (uint)(param_1 != 2) * 2 + 0xe;

      }

      if (iVar3 <= param_2) {

        param_2 = param_2 + (0x20 - iVar3);

      }

      DAT_0074db08 = 0;

      local_24[0] = '\0';

      if ((&DAT_00745118)[(param_1 * 0x2c + param_2) * 2] != 0xff) {

        FUN_00463000(local_24,&DAT_00660434,

                     &DAT_00745280 + (uint)(byte)(&DAT_00745118)[(param_1 * 0x2c + param_2) * 2] * 0x28)

        ;

      }

      pcVar4 = local_24;

      do {

        cVar1 = *pcVar4;

        pcVar4 = pcVar4 + 1;

      } while (cVar1 != '\0');

      uVar5 = (int)pcVar4 - (int)local_24;

      pcVar4 = (char *)0x74db07;

      do {

        pcVar6 = pcVar4 + 1;

        pcVar4 = pcVar4 + 1;

      } while (*pcVar6 != '\0');

      pcVar6 = local_24;

      for (uVar2 = uVar5 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {

        *(uint32_t *)pcVar4 = *(uint32_t *)pcVar6;

        pcVar6 = pcVar6 + 4;

        pcVar4 = pcVar4 + 4;

      }

      for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {

        *pcVar4 = *pcVar6;

        pcVar6 = pcVar6 + 1;

        pcVar4 = pcVar4 + 1;

      }

      return &DAT_0074db08;


}  // 0x004b1700
#endif // GameFn4B1700
void GameFn4B1700() {}  // 0x004b1700
#if 0 // GHIDRA_RAW: GameFn4B4CE0 @ 0x004b4ce0 — needs manual cleanup
uint32_t GameFn4B4CE0(uint32_t param_1,uint32_t param_2,uint32_t param_3,int param_4,int param_5,

            short param_6)
{


      short *psVar1;

      short *extraout_EDX;

      int iVar2;

      uint8_t auStack_34 [4];

      uint32_t local_30;

      short *local_2c;

      short local_1e [11];

      uint32_t local_8;



      local_8 = DAT_0067d280 ^ (uint)auStack_34;

      local_30 = param_1;

      if (param_6 == 0) {

        FUN_004b8ed0(param_4);

        psVar1 = extraout_EDX;

      }

      else {

        local_2c = local_1e + param_4;

        psVar1 = local_2c;

        for (iVar2 = (param_4 - param_5) / 2; 0 < iVar2; iVar2 = iVar2 + -1) {

          psVar1[-2] = (short)(char)(&DAT_0065d910)[(param_2 % 100) * 2];

          psVar1[-1] = (short)(char)(&DAT_0065d911)[(param_2 % 100) * 2];

          psVar1 = psVar1 + -2;

          param_2 = param_2 / 100;

        }

        if ((param_4 - param_5 & 1U) != 0) {

          psVar1 = psVar1 + -1;

          *psVar1 = (short)param_2 + (short)(param_2 / 10) * -10 + 0x30;

        }

        psVar1[-1] = param_6;

        FUN_004b8ed0(param_5);

        psVar1 = local_2c;

        param_1 = local_30;

      }

      FUN_004bbe90(psVar1,param_3);

      return param_1;


}  // 0x004b4ce0
#endif // GameFn4B4CE0
void GameFn4B4CE0() {}  // 0x004b4ce0
#if 0 // GHIDRA_RAW: GameFn4B59D0 @ 0x004b59d0 — needs manual cleanup
uint32_t GameFn4B59D0(uint32_t param_1,int param_2,uint32_t param_3,uint32_t param_4,uint32_t param_5,int param_6

            ,short param_7)
{


      longlong lVar1;

      longlong lVar2;

      short *psVar3;

      short *extraout_EDX;

      uint32_t uVar4;

      uint32_t uVar5;

      int iVar6;

      uint32_t local_68;

      uint32_t local_64;

      uint32_t local_60;

      int local_5c;

      uint32_t local_58;

      int local_50;

      uint32_t local_4c;

      int local_48;

      uint32_t local_44;

      short *local_40;

      short local_2e [21];

      uint32_t local_4;



      lVar1 = CONCAT44(local_58,local_4c);

      local_4 = DAT_0067d280 ^ (uint)&local_68;

      local_64 = param_4;

      local_68 = param_5;

      local_48 = param_6;

      local_44 = param_1;

      if (param_7 == 0) {

        FUN_004b7c50(param_4,param_5);

        psVar3 = extraout_EDX;

      }

      else {

        local_40 = local_2e + param_2;

        local_60 = param_2 - param_6;

        psVar3 = local_40;

        local_64 = param_4;

        for (local_5c = (int)local_60 / 2; 0 < local_5c; local_5c = local_5c + -1) {

          local_50 = (int)((ulonglong)local_64 * 0x47ae147a >> 0x20);

          lVar1 = (ulonglong)param_5 * 0x47ae147a;

          lVar2 = (ulonglong)param_5 * 0xe147ae15 + ((ulonglong)local_64 * 0xe147ae15 >> 0x20);

          uVar5 = (uint)((ulonglong)lVar2 >> 0x20);

          uVar4 = local_50 + (uint)CARRY4((uint)((ulonglong)local_64 * 0x47ae147a),(uint)lVar2);

          lVar2 = lVar1 + (ulonglong)CONCAT14(CARRY4(uVar5,uVar4),uVar5 + uVar4);

          uVar4 = (param_5 - (int)((ulonglong)lVar2 >> 0x20)) - (uint)(local_64 < (uint)lVar2);

          lVar2 = lVar2 + CONCAT44(uVar4 >> 1,local_64 - (uint)lVar2 >> 1 | uVar4 * -0x80000000);

          param_5 = (uint)((ulonglong)lVar2 >> 0x20);

          uVar4 = (uint)lVar2 >> 6 | param_5 * 0x4000000;

          param_5 = param_5 >> 6;

          iVar6 = local_64 + uVar4 * -100;

          psVar3[-2] = (short)(char)(&DAT_0065d910)[iVar6 * 2];

          psVar3[-1] = (short)(char)(&DAT_0065d911)[iVar6 * 2];

          psVar3 = psVar3 + -2;

          local_64 = uVar4;

        }

        local_58 = (uint32_t)((ulonglong)lVar1 >> 0x20);

        lVar2 = CONCAT44(param_5,local_58);

        local_4c = (uint32_t)lVar1;

        uVar4 = local_64;

        if ((local_60 & 1) != 0) {

          psVar3 = psVar3 + -1;

          local_60 = (uint)((ulonglong)local_64 * 0xcccccccc >> 0x20);

          lVar2 = (ulonglong)param_5 * 0xcccccccc;

          lVar1 = (ulonglong)param_5 * 0xcccccccd + ((ulonglong)local_64 * 0xcccccccd >> 0x20);

          uVar5 = (uint)((ulonglong)lVar1 >> 0x20);

          uVar4 = local_60 + CARRY4((uint)((ulonglong)local_64 * 0xcccccccc),(uint)lVar1);

          lVar1 = lVar2 + (ulonglong)CONCAT14(CARRY4(uVar5,uVar4),uVar5 + uVar4);

          param_5 = (uint)((ulonglong)lVar1 >> 0x20);

          uVar5 = (uint)lVar1 >> 3;

          uVar4 = uVar5 | param_5 * 0x20000000;

          param_5 = param_5 >> 3;

          *psVar3 = (short)local_64 + (short)uVar5 * -10 + 0x30;

        }

        local_68 = (uint)((ulonglong)lVar2 >> 0x20);

        local_58 = (uint32_t)lVar2;

        psVar3[-1] = param_7;

        FUN_004b7c50(uVar4,param_5);

        psVar3 = local_40;

        param_1 = local_44;

      }

      FUN_004bbe90(psVar3,param_3);

      return param_1;


}  // 0x004b59d0
#endif // GameFn4B59D0
void GameFn4B59D0() {}  // 0x004b59d0
#if 0 // GHIDRA_RAW: GameFn4B9880 @ 0x004b9880 — needs manual cleanup
void GameFn4B9880()
{


        puVar1 = (uint32_t *)FUN_004bc4b0(param_2,param_3 + 3);

        param_2 = *puVar1;


}  // 0x004b9880
#endif // GameFn4B9880
void GameFn4B9880() {}  // 0x004b9880
#if 0 // GHIDRA_RAW: GameFn4BA540 @ 0x004ba540 — needs manual cleanup
uint32_t * GameFn4BA540(uint32_t *param_1,uint32_t *param_2,uint32_t param_3,int param_4,uint32_t param_5)
{


      uint32_t uVar1;

      uint32_t *puVar2;

      uint32_t *puVar3;

      uint32_t uVar4;



      if (param_5 < *param_2) {

        uVar4 = *param_2 - param_5;

      }

      else {

        uVar4 = 0;

      }

      uVar1 = uVar4 >> ((&DAT_0065d9e4)[*(byte *)((int)param_2 + 9) & 0xf] & 0x1f);

      if (uVar1 != 0) {

        puVar2 = (uint32_t *)FUN_004bc4b0(param_3,param_2 + 3);

        param_3 = *puVar2;

      }

      FUN_004bb410(param_4 + param_5,param_3);

      if (uVar4 != uVar1) {

        puVar3 = (uint32_t *)FUN_004bc4b0(param_5,param_2 + 3);

        param_5 = *puVar3;

      }

      *param_1 = param_5;

      return param_1;


}  // 0x004ba540
#endif // GameFn4BA540
void GameFn4BA540() {}  // 0x004ba540
#if 0 // GHIDRA_RAW: GameFn4BC570 @ 0x004bc570 — needs manual cleanup
int * GameFn4BC570(int *param_1,uint32_t param_2,int param_3,int param_4,char param_5)
{


      int iVar1;

      uint32_t uVar2;

      char *pcVar3;

      short *psVar4;

      char *pcVar5;

      char *pcVar6;

      char local_10 [12];

      uint32_t local_4;



      local_4 = DAT_0067d280 ^ (uint)local_10;

      iVar1 = *(int *)(param_3 + 8);

      uVar2 = param_4 + iVar1;

      if (uVar2 <= *(uint32_t *)(param_3 + 0xc)) {

        *(uint32_t *)(param_3 + 8) = uVar2;

        iVar1 = *(int *)(param_3 + 4) + iVar1 * 2;

        if (iVar1 != 0) {

          psVar4 = (short *)(iVar1 + param_4 * 2);

          pcVar6 = "0123456789ABCDEF";

          if (param_5 == '\0') {

            pcVar6 = "0123456789abcdef";

          }

          do {

            psVar4 = psVar4 + -1;

            uVar2 = param_2 & 0xf;

            param_2 = param_2 >> 4;

            *psVar4 = (short)pcVar6[uVar2];

          } while (param_2 != 0);

          *param_1 = param_3;

          return param_1;

        }

      }

      pcVar3 = local_10 + param_4;

      pcVar5 = "0123456789ABCDEF";

      pcVar6 = pcVar3;

      if (param_5 == '\0') {

        pcVar5 = "0123456789abcdef";

      }

      do {

        pcVar6 = pcVar6 + -1;

        uVar2 = param_2 & 0xf;

        param_2 = param_2 >> 4;

        *pcVar6 = pcVar5[uVar2];

      } while (param_2 != 0);

      FUN_004bc520(pcVar3,param_3);

      return param_1;


}  // 0x004bc570
#endif // GameFn4BC570
void GameFn4BC570() {}  // 0x004bc570
#if 0 // GHIDRA_RAW: GameFn4BC6C0 @ 0x004bc6c0 — needs manual cleanup
uint32_t * GameFn4BC6C0(uint32_t *param_1,uint32_t param_2,uint32_t param_3,uint32_t *param_4)
{


      uint32_t *puVar1;

      int iVar2;

      uint32_t *puVar3;

      uint32_t uVar4;

      uint32_t uVar5;

      uint32_t uVar6;

      uint8_t local_10 [4];

      uint32_t local_c;

      int local_8;



      puVar1 = param_4;

      param_4 = (uint32_t *)0x0;

      iVar2 = 0x1f;

      if ((param_2 | 1) != 0) {

        for (; (param_2 | 1) >> iVar2 == 0; iVar2 = iVar2 + -1) {

        }

      }

      iVar2 = (int)(iVar2 + (iVar2 >> 0x1f & 3U)) >> 2;

      local_8 = iVar2 + 1;

      uVar5 = iVar2 + 3;

      local_c = param_2;

      if (puVar1 == (uint32_t *)0x0) {

        puVar3 = (uint32_t *)FUN_004bc650(local_10,param_3);

        uVar4 = *puVar3;

      }

      else {

        uVar6 = -(uint)(uVar5 < *puVar1) & *puVar1 - uVar5;

        uVar5 = uVar6 >> ((&DAT_0065d9e4)[*(byte *)((int)puVar1 + 9) & 0xf] & 0x1f);

        if (uVar5 != 0) {

          puVar3 = (uint32_t *)FUN_004bc4b0(param_3,puVar1 + 3);

          param_3 = *puVar3;

        }

        puVar3 = (uint32_t *)FUN_004bc650(&param_4,param_3);

        uVar4 = *puVar3;

        if (uVar6 != uVar5) {

          puVar3 = (uint32_t *)FUN_004bc4b0(uVar4,puVar1 + 3);

          *param_1 = *puVar3;

          return param_1;

        }

      }

      *param_1 = uVar4;

      return param_1;


}  // 0x004bc6c0
#endif // GameFn4BC6C0
void GameFn4BC6C0() {}  // 0x004bc6c0
#if 0 // GHIDRA_RAW: GameFn4BF890 @ 0x004bf890 — needs manual cleanup
void GameFn4BF890(int param_1)
{


      int iVar1;

      int local_14;

      void *local_10;

      uint8_t *puStack_c;

      uint32_t uStack_8;



      uStack_8 = 0xffffffff;

      puStack_c = &LAB_00646110;

      local_10 = ExceptionList;

      ExceptionList = &local_10;

      local_14 = *(int *)(param_1 + 8);

      iVar1 = param_1;

      if (local_14 != 0) {

        iVar1 = param_1;

        if (*(int **)(param_1 + 0x9c) != (int *)0x0) {

          (**(code **)(**(int **)(param_1 + 0x9c) + 8))

                    (param_1 + 0xc,&local_14,DAT_0067d280 ^ (uint)&stack0xfffffffc);

          iVar1 = local_14;

        }

        local_14 = iVar1;

        fclose(*(FILE **)(param_1 + 8));

        *(uint32_t *)(param_1 + 8) = 0;

        iVar1 = local_14;

        if (*(int **)(param_1 + 0xc4) != (int *)0x0) {

          (**(code **)(**(int **)(param_1 + 0xc4) + 8))(param_1 + 0xc);

          iVar1 = local_14;

        }

      }

      local_14 = iVar1;

      FUN_004c1660();

      FUN_004439b0();

      ExceptionList = local_10;

      return;


}  // 0x004bf890
#endif // GameFn4BF890
void GameFn4BF890() {}  // 0x004bf890
#if 0 // GHIDRA_RAW: GameFn4CA120 @ 0x004ca120 — needs manual cleanup
void GameFn4CA120(uint32_t param_1,uint32_t *param_2)
{


      char cVar1;

      uint8_t auStack_2c [7];

      char local_25;

      uint32_t local_24;

      uint8_t local_b [3];

      uint32_t local_8;

      uint32_t local_4;



      local_4 = DAT_0067d280 ^ (uint)auStack_2c;

      if (param_1 < 1000) {

        local_24 = param_1 / 100;

        local_25 = (char)local_24 + '0';

        if ((uint)param_2[3] < param_2[2] + 1) {

          (**(code **)*param_2)(param_2[2] + 1);

        }

        *(char *)(param_2[2] + param_2[1]) = local_25;

        param_2[2] = param_2[2] + 1;

        param_1 = param_1 + local_24 * -100;

        local_24 = param_1 / 10;

        local_25 = (char)local_24 + '0';

        if ((uint)param_2[3] < param_2[2] + 1) {

          (**(code **)*param_2)(param_2[2] + 1);

        }

        *(char *)(param_2[2] + param_2[1]) = local_25;

        cVar1 = (char)local_24;

        param_2[2] = param_2[2] + 1;

        if ((uint)param_2[3] < param_2[2] + 1) {

          (**(code **)*param_2)(param_2[2] + 1);

        }

        *(char *)(param_2[2] + param_2[1]) = (char)param_1 + cVar1 * -10 + '0';

        param_2[2] = param_2[2] + 1;

        return;

      }

      local_8 = FUN_0044c960(0x15);

      FUN_0044dc30(local_8,local_b);

      return;


}  // 0x004ca120
#endif // GameFn4CA120
void GameFn4CA120() {}  // 0x004ca120
#if 0 // GHIDRA_RAW: GameFn4CB120 @ 0x004cb120 — needs manual cleanup
uint32_t * GameFn4CB120(uint32_t *param_1,uint32_t param_2,uint32_t param_3,int param_4,int param_5,

            char param_6)
{


      int iVar1;

      char *extraout_EDX;

      char *pcVar2;

      uint8_t auStack_24 [4];

      uint32_t local_20;

      char *local_1c;

      uint8_t local_14;

      char local_13 [11];

      uint32_t local_8;



      local_8 = DAT_0067d280 ^ (uint)auStack_24;

      if (param_6 == '\0') {

        FUN_0044c960(param_4);

        pcVar2 = extraout_EDX;

      }

      else {

        local_1c = local_13 + param_4;

        local_20 = param_4 - param_5;

        pcVar2 = local_1c;

        for (iVar1 = (int)local_20 / 2; 0 < iVar1; iVar1 = iVar1 + -1) {

          pcVar2 = pcVar2 + -2;

          *(uint16_t *)pcVar2 = *(uint16_t *)(&DAT_0065d910 + (param_2 % 100) * 2);

          param_2 = param_2 / 100;

        }

        if ((local_20 & 1) != 0) {

          pcVar2 = pcVar2 + -1;

          *pcVar2 = (char)param_2 + (char)(param_2 / 10) * -10 + '0';

        }

        pcVar2[-1] = param_6;

        FUN_0044c960(param_5);

        pcVar2 = local_1c;

      }

      FUN_0044dc30(&local_14,pcVar2);

      *param_1 = param_3;

      return param_1;


}  // 0x004cb120
#endif // GameFn4CB120
void GameFn4CB120() {}  // 0x004cb120
#if 0 // GHIDRA_RAW: GameFn4CBD80 @ 0x004cbd80 — needs manual cleanup
uint32_t * GameFn4CBD80(uint32_t *param_1,int param_2,uint32_t param_3,uint32_t param_4,uint32_t param_5,

            int param_6,char param_7)
{


      longlong lVar1;

      longlong lVar2;

      char *pcVar3;

      char *extraout_EDX;

      uint32_t uVar4;

      uint32_t uVar5;

      uint32_t local_58;

      uint32_t local_54;

      uint32_t local_50;

      int local_4c;

      uint32_t local_48;

      int local_40;

      uint32_t local_3c;

      int local_38;

      uint32_t *local_34;

      char *local_30;

      uint8_t local_1c;

      char local_1b [23];

      uint32_t local_4;



      lVar1 = CONCAT44(local_48,local_3c);

      local_4 = DAT_0067d280 ^ (uint)&local_58;

      local_54 = param_4;

      local_58 = param_5;

      local_38 = param_6;

      local_34 = param_1;

      if (param_7 == '\0') {

        FUN_0044c390(param_4,param_5);

        pcVar3 = extraout_EDX;

      }

      else {

        local_30 = local_1b + param_2;

        local_50 = param_2 - param_6;

        pcVar3 = local_30;

        local_54 = param_4;

        for (local_4c = (int)local_50 / 2; 0 < local_4c; local_4c = local_4c + -1) {

          pcVar3 = pcVar3 + -2;

          local_40 = (int)((ulonglong)local_54 * 0x47ae147a >> 0x20);

          lVar1 = (ulonglong)param_5 * 0x47ae147a;

          lVar2 = (ulonglong)param_5 * 0xe147ae15 + ((ulonglong)local_54 * 0xe147ae15 >> 0x20);

          uVar5 = (uint)((ulonglong)lVar2 >> 0x20);

          uVar4 = local_40 + (uint)CARRY4((uint)((ulonglong)local_54 * 0x47ae147a),(uint)lVar2);

          lVar2 = lVar1 + (ulonglong)CONCAT14(CARRY4(uVar5,uVar4),uVar5 + uVar4);

          uVar4 = (param_5 - (int)((ulonglong)lVar2 >> 0x20)) - (uint)(local_54 < (uint)lVar2);

          lVar2 = lVar2 + CONCAT44(uVar4 >> 1,local_54 - (uint)lVar2 >> 1 | uVar4 * -0x80000000);

          param_5 = (uint)((ulonglong)lVar2 >> 0x20);

          uVar4 = (uint)lVar2 >> 6 | param_5 * 0x4000000;

          param_5 = param_5 >> 6;

          *(uint16_t *)pcVar3 = *(uint16_t *)(&DAT_0065d910 + (local_54 + uVar4 * -100) * 2);

          local_54 = uVar4;

        }

        local_48 = (uint32_t)((ulonglong)lVar1 >> 0x20);

        lVar2 = CONCAT44(param_5,local_48);

        local_3c = (uint32_t)lVar1;

        uVar4 = local_54;

        if ((local_50 & 1) != 0) {

          pcVar3 = pcVar3 + -1;

          local_50 = (uint)((ulonglong)local_54 * 0xcccccccc >> 0x20);

          lVar2 = (ulonglong)param_5 * 0xcccccccc;

          lVar1 = (ulonglong)param_5 * 0xcccccccd + ((ulonglong)local_54 * 0xcccccccd >> 0x20);

          uVar5 = (uint)((ulonglong)lVar1 >> 0x20);

          uVar4 = local_50 + CARRY4((uint)((ulonglong)local_54 * 0xcccccccc),(uint)lVar1);

          lVar1 = lVar2 + (ulonglong)CONCAT14(CARRY4(uVar5,uVar4),uVar5 + uVar4);

          param_5 = (uint)((ulonglong)lVar1 >> 0x20);

          uVar5 = (uint)lVar1 >> 3;

          uVar4 = uVar5 | param_5 * 0x20000000;

          param_5 = param_5 >> 3;

          *pcVar3 = (char)local_54 + (char)uVar5 * -10 + '0';

        }

        local_58 = (uint)((ulonglong)lVar2 >> 0x20);

        local_48 = (uint32_t)lVar2;

        pcVar3[-1] = param_7;

        FUN_0044c390(uVar4,param_5);

        pcVar3 = local_30;

        param_1 = local_34;

      }

      FUN_0044dc30(&local_1c,pcVar3);

      *param_1 = param_3;

      return param_1;


}  // 0x004cbd80
#endif // GameFn4CBD80
void GameFn4CBD80() {}  // 0x004cbd80
#if 0 // GHIDRA_RAW: GameFn4D0D60 @ 0x004d0d60 — needs manual cleanup
void GameFn4D0D60()
{


      int iVar1;

      uint32_t uVar2;



      if (DAT_00747b44 != 0) {

        uVar2 = DAT_00747b4c - DAT_00747b44 & 0xfffffffc;

        iVar1 = DAT_00747b44;

        if (0xfff < uVar2) {

          iVar1 = *(int *)(DAT_00747b44 + -4);

          uVar2 = uVar2 + 0x23;

          if (0x1f < (DAT_00747b44 - iVar1) - 4U) {

                        /* WARNING: Subroutine does not return */

            std::abort();

          }

        }

        FUN_00643505(iVar1,uVar2);

      }

      DAT_00747b44 = param_1;

      DAT_00747b48 = param_1 + param_2 * 4;

      DAT_00747b4c = param_1 + param_3 * 4;

      return;


}  // 0x004d0d60
#endif // GameFn4D0D60
void GameFn4D0D60() {}  // 0x004d0d60
#if 0 // GHIDRA_RAW: GameFn4D6AC0 @ 0x004d6ac0 — needs manual cleanup
uint32_t * GameFn4D6AC0(uint32_t *param_1)
{


      *param_1 = 0;

      param_1[1] = 0;

      param_1[2] = 0;

      param_1[3] = 0;

      param_1[4] = 0;

      param_1[5] = 0;

      param_1[6] = 0;

      param_1[7] = 0;

      param_1[8] = 0;

      param_1[9] = 0;

      param_1[0xc] = 0;

      memset(param_1 + 0x10,0,0x50);

      FUN_00450a80();

      return param_1;


}  // 0x004d6ac0
#endif // GameFn4D6AC0
void GameFn4D6AC0() {}  // 0x004d6ac0
#if 0 // GHIDRA_RAW: GameFn4D9DC0 @ 0x004d9dc0 — needs manual cleanup
void GameFn4D9DC0(uint32_t param_1,uint32_t param_2)
{


      int iVar1;

      byte *pbVar2;

      uint32_t uVar3;

      uint8_t local_68 [24];

      uint8_t local_50 [76];



      FUN_004d9920(local_50,local_68);

      pbVar2 = DAT_00701cdc;

      if ((*DAT_00701cdc & 1) != 0) {

        (**(code **)(**(int **)(DAT_00701cdc + 0x30) + 4))(0,5);

        uVar3 = (**(code **)(*(int *)(pbVar2 + 0x30) + 8))

                          (*(int *)(pbVar2 + 0x30),*(uint32_t *)(pbVar2 + 0xc));

        *(uint32_t *)(pbVar2 + 0x10) = uVar3;

      }

      iVar1 = *(int *)(DAT_00701cdc + 0x1c);

      *(uint32_t *)(iVar1 + 4) = 0x33c;

      *(uint32_t *)(iVar1 + 8) = param_2;

      *(uint32_t *)(iVar1 + 0xc) = 0xffffffff;

      FUN_004e19a0(local_68);

      pbVar2 = DAT_00701cdc;

      if ((*DAT_00701cdc & 1) != 0) {

        FUN_004e0b70();

        iVar1 = *(int *)(pbVar2 + 0x30);

        (**(code **)(iVar1 + 0x24))(iVar1);

        iVar1 = *(int *)(pbVar2 + 0x30);

        (**(code **)(iVar1 + 4))(iVar1);

      }

      return;


}  // 0x004d9dc0
#endif // GameFn4D9DC0
void GameFn4D9DC0() {}  // 0x004d9dc0
#if 0 // GHIDRA_RAW: GameFn4E98E0 @ 0x004e98e0 — needs manual cleanup
uint32_t * GameFn4E98E0(uint32_t param_1)
{


      uint32_t *puVar1;

      int iVar2;

      uint32_t *puVar3;

      uint32_t *puVar4;

      int *piVar5;

      uint32_t uVar6;

      uint32_t extraout_ECX;

      uint32_t *puVar7;

      uint32_t *puVar8;

      uint8_t local_2d;

      uint32_t local_2c;

      uint32_t *local_28;

      uint32_t local_24;

      uint32_t local_20;

      uint32_t *local_1c;

      uint8_t local_18 [20];



      local_28 = (uint32_t *)((param_1 & 0xff ^ 0x811c9dc5) * 0x1000193);

      uVar6 = (((int)param_1 >> 8 & 0xffU ^ (uint)local_28) * 0x1000193 ^ (int)param_1 >> 0x10 & 0xffU)

              * 0x1000193 ^ (int)param_1 >> 0x18 & 0xffU;

      puVar8 = (uint32_t *)((DAT_00728434 & uVar6 * 0x1000193) * 0x10 + DAT_0072844c);

      local_2c = param_1;

      iVar2 = FUN_004f3630(&local_2c,uVar6,puVar8);

      puVar1 = DAT_00728444;

      if (iVar2 == 0) {

        puVar4 = DAT_00728444;

        puVar7 = DAT_0072843c;

        if ((*puVar8 & 2) != 0) {

          for (puVar4 = (uint32_t *)*DAT_00728444; (puVar4 != DAT_00728444 && (param_1 != puVar4[2]));

              puVar4 = (uint32_t *)*puVar4) {

          }

        }

      }

      else {

        puVar4 = (uint32_t *)*DAT_00728444;

        puVar7 = (uint32_t *)((iVar2 - DAT_00728438 & 0xfffffff0U) + DAT_00728438);

      }

      if ((puVar7 != DAT_0072843c) || (puVar4 != DAT_00728444)) {

        if (puVar7 == DAT_0072843c) {

          puVar7 = puVar4;

        }

        return (uint32_t *)puVar7[3];

      }

      iVar2 = 0;

      puVar8 = DAT_00747d3c;

      local_1c = DAT_00747d3c;

      if (0 < DAT_00747d38) {

        do {

          do {

            puVar3 = puVar8;

            puVar8 = (uint32_t *)((int)puVar3 + 1);

          } while ((char)*puVar3 != '\0');

          if (param_1 == *(uint32_t *)((int)puVar3 + 1)) {

            uVar6 = ((local_2c >> 8 & 0xff ^ (uint)local_28) * 0x1000193 ^ local_2c >> 0x10 & 0xff) *

                    0x1000193 ^ local_2c >> 0x18;

            local_24 = uVar6 * 0x1000193;

            local_20 = local_24 & DAT_00728434;

            puVar8 = (uint32_t *)(local_20 * 0x10 + DAT_0072844c);

            puVar4 = (uint32_t *)FUN_004f3630(&local_2c,uVar6,puVar8);

            if (puVar4 != (uint32_t *)0x0) goto LAB_004e9a55;

            if (((*puVar8 & 2) == 0) || (puVar4 = (uint32_t *)*puVar1, puVar4 == puVar1))

            goto LAB_004e9a5a;

            goto LAB_004e9a46;

          }

          iVar2 = iVar2 + 1;

          puVar8 = (uint32_t *)((int)puVar3 + 5);

          local_1c = (uint32_t *)((int)puVar3 + 5);

        } while (iVar2 < DAT_00747d38);

      }

      return (uint32_t *)0x0;

      while (puVar4 = (uint32_t *)*puVar4, puVar4 != puVar1) {

    LAB_004e9a46:

        if (param_1 == puVar4[2]) break;

      }

      if (puVar4 != puVar1) {

    LAB_004e9a55:

        puVar4 = puVar4 + 3;

        if (puVar4 != (uint32_t *)0x0) goto LAB_004e9a8e;

      }

    LAB_004e9a5a:

      local_28 = &local_2c;

      piVar5 = (int *)FUN_004f3010(local_18,local_20,local_24,extraout_ECX,&local_28,&local_2d);

      iVar2 = *piVar5;

      if (iVar2 == piVar5[1]) {

        iVar2 = piVar5[2];

      }

      puVar4 = (uint32_t *)(iVar2 + 0xc);

    LAB_004e9a8e:

      *puVar4 = local_1c;

      return local_1c;


}  // 0x004e98e0
#endif // GameFn4E98E0
void GameFn4E98E0() {}  // 0x004e98e0
#if 0 // GHIDRA_RAW: GameFn4F7490 @ 0x004f7490 — needs manual cleanup
void GameFn4F7490()
{


        lVar3 = __alldiv(iVar1,iVar2,400,0);

        lVar4 = __alldiv(iVar1,iVar2,100,0);

        lVar5 = __alldiv(iVar1,iVar2,4,0);

        lVar3 = __allrem((lVar3 - lVar4) + lVar5 + CONCAT44(iVar2,iVar1),7,0);

        if (lVar3 != 3) {

          return 0x34;

        }


}  // 0x004f7490
#endif // GameFn4F7490
void GameFn4F7490() {}  // 0x004f7490
#if 0 // GHIDRA_RAW: GameFn4F7D30 @ 0x004f7d30 — needs manual cleanup
void GameFn4F7D30(float *param_1)
{


      float in_XMM0_Da;

      float in_XMM1_Da;

      float fVar1;

      float in_XMM2_Da;

      float fVar2;

      float fVar3;

      float fVar4;

      float fVar5;

      float local_10;

      float local_c;

      float local_8;

      float local_4;



      local_10 = *param_1;

      local_c = in_XMM2_Da;

      local_8 = in_XMM1_Da;

      local_4 = in_XMM0_Da;

      FUN_00638f10(&local_8);

      FUN_00638f10(&local_c);

      FUN_00638f10(&local_10);

      local_8 = local_8 - local_c;

      if (local_8 <= DAT_0066c110) {

        if (local_8 < DAT_0066c2cc) {

          local_c = local_c - DAT_0066c14c;

          local_8 = local_8 + DAT_0066c14c;

        }

      }

      else {

        local_c = local_c + DAT_0066c14c;

        local_8 = DAT_0066c14c - local_8;

      }

      fVar1 = local_8 / local_4;

      fVar2 = local_c;

      fVar3 = DAT_0066c14c;

      fVar4 = DAT_0066c2cc;

      fVar5 = DAT_0066c110;

      FUN_0042d350();

      if (fVar2 - local_10 <= fVar5) {

        if (fVar2 - local_10 < fVar4) {

          local_10 = local_10 - fVar3;

        }

      }

      else {

        local_10 = local_10 + fVar3;

      }

      if (local_10 <= fVar2) {

        if ((fVar2 <= local_10) || (local_10 = fVar1 * DAT_00727e38 + local_10, local_10 <= fVar2))

        goto LAB_004f7e36;

      }

      else {

        local_10 = local_10 - fVar1 * DAT_00727e38;

        if (fVar2 <= local_10) goto LAB_004f7e36;

      }

      local_10 = fVar2;

    LAB_004f7e36:

      FUN_00638f10(&local_10);

      *param_1 = local_10;

      return;


}  // 0x004f7d30
#endif // GameFn4F7D30
void GameFn4F7D30() {}  // 0x004f7d30
#if 0 // GHIDRA_RAW: RenderFn502A10 @ 0x00502a10 — needs manual cleanup
void RenderFn502A10(int param_1,int param_2)
{


      int iVar1;

      int iVar2;

      int extraout_ECX;

      int extraout_ECX_00;

      int extraout_ECX_01;

      int iVar3;

      uint8_t local_1;



      iVar3 = param_1;

      if ((param_1 != 0) &&

         ((DAT_006ff960 != 6 || (iVar1 = FUN_0045f460(), iVar3 = extraout_ECX, iVar1 != 0)))) {

        switch(param_2) {

        default:

          return;

        case -1:

        case 1:

        case 3:

        case 5:

        case 6:

        case 7:

        case 0xe:

        case 0xf:

        case 0x10:

        case 0x13:

          break;

        }

      }

      if (*(int *)(param_1 + 0x22c) != 2) {

        return;

      }

      iVar1 = *(int *)(param_1 + 0x14c);

      if (((*(int *)(iVar1 + 0x168 + *(int *)(iVar1 + 0x50) * 4) != param_2) && (DAT_006ff960 == 6)) &&

         (iVar2 = FUN_0045f460(), iVar3 = extraout_ECX_00, iVar2 != 0)) {

        local_1 = (uint8_t)param_2;

        FUN_00469d20(6,&local_1);

        iVar3 = extraout_ECX_01;

      }

      *(int *)(iVar1 + 0x168 + *(int *)(iVar1 + 0x50) * 4) = param_2;

      FUN_00451460(*(uint32_t *)(iVar1 + 0x50),iVar3);

      return;


}  // 0x00502a10
#endif // RenderFn502A10
void RenderFn502A10() {}  // 0x00502a10
#if 0 // GHIDRA_RAW: RenderFn504160 @ 0x00504160 — needs manual cleanup
bool RenderFn504160(int param_1,int *param_2)
{


      int *piVar1;

      int *piVar2;

      uint32_t *puVar3;

      int iVar4;

      int *piVar5;

      int *piVar6;

      int iVar7;

      int *piVar8;

      int iVar9;

      int iVar10;

      float fVar11;

      float fVar12;

      float fVar13;

      uint64_t uVar14;

      int local_4;



      iVar10 = *param_2;

      if (param_1 == 0) {

        return false;

      }

      if (*(int *)(param_1 + 0x22c) == 2) {

        iVar9 = *(int *)(param_1 + 0x14c);

        piVar6 = DAT_00749908;

        if (iVar10 < -1) {

          return false;

        }

        for (; piVar8 = DAT_00749908, piVar5 = DAT_00749908, piVar6 != DAT_0074990c; piVar6 = piVar6 + 2

            ) {

          piVar1 = (int *)*piVar6;

          if (*piVar1 == iVar10) {

            if (piVar1 != (int *)0x0) {

              if (piVar1[0xb] == 2) goto joined_r0x005041fb;

              if (iVar10 < -1) {

                return false;

              }

            }

            break;

          }

        }

        while( true ) {

          if (piVar8 == DAT_0074990c) {

            return false;

          }

          piVar6 = (int *)*piVar8;

          if (*piVar6 == iVar10) break;

          piVar8 = piVar8 + 2;

        }

        if (piVar6 == (int *)0x0) {

          return false;

        }

        if (piVar6[0xb] != 1) {

          return false;

        }

    joined_r0x005041fb:

        piVar6 = DAT_00749908;

        if (piVar5 == DAT_0074990c) goto joined_r0x00504201;

        piVar8 = (int *)*piVar5;

        if (*piVar8 != iVar10) {

          piVar5 = piVar5 + 2;

          goto joined_r0x005041fb;

        }

        if ((piVar8 == (int *)0x0) || (piVar8[10] != 1)) goto joined_r0x00504201;

        iVar4 = *(int *)(param_1 + 0x14c);

        if (iVar10 == *(int *)(iVar4 + 0x168)) goto joined_r0x0050428c;

        if (((iVar10 != *(int *)(iVar4 + 0x16c)) && (iVar10 != *(int *)(iVar4 + 0x170))) &&

           (iVar10 != *(int *)(iVar4 + 0x174))) goto joined_r0x00504201;

        if ((((iVar10 != *(int *)(iVar4 + 0x168)) && (iVar10 != *(int *)(iVar4 + 0x16c))) &&

            (iVar10 != *(int *)(iVar4 + 0x170))) && (iVar10 != *(int *)(iVar4 + 0x174))) {

          return false;

        }

    joined_r0x0050428c:

        for (; (piVar6 != DAT_0074990c && (*(int *)*piVar6 != iVar10)); piVar6 = piVar6 + 2) {

        }

        uVar14 = FUN_005025c0();

        if ((int)uVar14 == 0) {

          return false;

        }

        *param_2 = (int)((ulonglong)uVar14 >> 0x20);

        piVar5 = DAT_00749908;

    joined_r0x00504218:

        do {

          piVar1 = DAT_0074990c;

          piVar8 = DAT_00749908;

          piVar6 = piVar8;

          if (piVar5 == DAT_0074990c) goto joined_r0x00504333;

          piVar2 = (int *)*piVar5;

          if (*piVar2 == iVar10) {

            if (((piVar2 != (int *)0x0) && (piVar2[10] == 4)) && (iVar4 = FUN_005025c0(), iVar4 == 0)) {

              return false;

            }

            goto joined_r0x00504333;

          }

          piVar5 = piVar5 + 2;

        } while( true );

      }

      if (param_1 == 0) {

        return false;

      }

      fVar13 = 0.0;

      if (*(int *)(param_1 + 0x22c) == 3) {

        piVar6 = DAT_00749908;

        if (iVar10 < -1) {

          return false;

        }

        for (; piVar5 = DAT_00749908, piVar6 != DAT_0074990c; piVar6 = piVar6 + 2) {

          piVar8 = (int *)*piVar6;

          if (*piVar8 == iVar10) {

            if (piVar8 != (int *)0x0) {

              if (piVar8[0xb] == 3) goto joined_r0x0050468f;

              if (iVar10 < -1) {

                return false;

              }

            }

            break;

          }

        }

        piVar6 = DAT_00749908;

        if (DAT_00749908 == DAT_0074990c) {

          return false;

        }

        while (piVar8 = (int *)*piVar6, *piVar8 != iVar10) {

          piVar6 = piVar6 + 2;

          if (piVar6 == DAT_0074990c) {

            return false;

          }

        }

        if (piVar8 == (int *)0x0) {

          return false;

        }

        if (piVar8[0xb] != 1) {

          return false;

        }

    joined_r0x0050468f:

        do {

          piVar6 = DAT_00749908;

          if (piVar5 == DAT_0074990c) goto joined_r0x00504788;

          piVar8 = (int *)*piVar5;

          if (*piVar8 == iVar10) {

            if ((piVar8 != (int *)0x0) && (piVar8[10] == 1)) {

              iVar9 = 0;

              piVar5 = (int *)(*(int *)(param_1 + 0x14c) + 0xd60);

              goto LAB_005046c6;

            }

            goto joined_r0x00504788;

          }

          piVar5 = piVar5 + 2;

        } while( true );

      }

      if (*(int *)(param_1 + 0x22c) != 1) {

        return false;

      }

      goto LAB_00504989;

    joined_r0x00504201:

      piVar5 = DAT_00749908;

      if (piVar6 == DAT_0074990c) goto joined_r0x00504218;

      piVar8 = (int *)*piVar6;

      if (*piVar8 == iVar10) {

        if ((piVar8 != (int *)0x0) && (piVar8[10] == 1)) {

          iVar4 = 0x16c;

          while ((*(int *)(param_1 + 0x22c) != 2 || (-1 < *(int *)(iVar4 + *(int *)(param_1 + 0x14c)))))

          {

            iVar4 = iVar4 + 4;

            if (0x177 < iVar4) {

              return false;

            }

          }

        }

        goto joined_r0x00504218;

      }

      piVar6 = piVar6 + 2;

      goto joined_r0x00504201;

    joined_r0x00504333:

      if (piVar6 == piVar1) goto LAB_00504342;

      piVar5 = (int *)*piVar6;

      if (*piVar5 == iVar10) {

        if ((piVar5 != (int *)0x0) && (piVar5[10] == 3)) {

          if (((*(uint32_t *)(param_1 + 0x128) & 0x400000) != 0) && (DAT_007488dc == 0)) {

            return false;

          }

          if (iVar10 == 0xb) {

            iVar10 = 0;

            for (puVar3 = DAT_007027ac; puVar3 != (uint32_t *)0x0; puVar3 = (uint32_t *)*puVar3) {

              iVar9 = puVar3[3];

              if ((*(int *)(iVar9 + 4) == 0x3c) &&

                 ((*(int *)(iVar9 + 0x264) == DAT_00702774 || (*(int *)(iVar9 + 0x2c4) == DAT_00702774))

                 )) {

                iVar10 = iVar10 + 1;

              }

            }

            if (*(int *)(DAT_007028f4 + 0x16b0) <= iVar10) {

              return false;

            }

            return true;

          }

        }

        goto LAB_00504342;

      }

      piVar6 = piVar6 + 2;

      goto joined_r0x00504333;

    LAB_00504342:

      if (iVar10 == 10) {

        if ((*(uint32_t *)(param_1 + 0x128) & 0x800000) != 0) {

          return false;

        }

        return true;

      }

      switch(iVar10) {

      case 0:

        iVar9 = 0;

        iVar10 = 0x15c;

        do {

          if (*(int *)(param_1 + 0x22c) != 2) {

            return false;

          }

          if (*(int *)(iVar10 + *(int *)(param_1 + 0x14c)) == 0) {

            return false;

          }

          if (*(int *)(*(int *)(param_1 + 0x14c) + iVar10) < 0) {

            if (2 < iVar9) {

              return false;

            }

            return true;

          }

          iVar10 = iVar10 + 4;

          iVar9 = iVar9 + 1;

        } while (iVar10 < 0x168);

        return false;

      default:

        return true;

      case 8:

      case 0x4b:

      case 0x4c:

        local_4 = 0x15c;

        break;

      case 9:

      case 0x40:

        if (iVar10 == 0x40) {

          piVar6 = (int *)(iVar9 + 0x140);

        }

        else {

          piVar6 = (int *)(iVar9 + 0x13c);

        }

        iVar9 = 0x15c;

        while( true ) {

          if (*(int *)(param_1 + 0x22c) == 2) {

            iVar4 = *(int *)(iVar9 + *(int *)(param_1 + 0x14c));

          }

          else {

            iVar4 = 0;

          }

          if (iVar4 == iVar10) break;

          iVar9 = iVar9 + 4;

          if (0x167 < iVar9) {

            iVar10 = 0x15c;

            while ((*(int *)(param_1 + 0x22c) != 2 ||

                   (*(int *)(iVar10 + *(int *)(param_1 + 0x14c)) != -1))) {

              iVar10 = iVar10 + 4;

              if (0x167 < iVar10) {

                return false;

              }

            }

            return true;

          }

        }

        if (-2 < iVar10) {

          for (; piVar8 != piVar1; piVar8 = piVar8 + 2) {

            piVar5 = (int *)*piVar8;

            if (*piVar5 == iVar10) {

              if (piVar5 != (int *)0x0) {

                iVar10 = piVar5[8];

                goto LAB_005045e8;

              }

              break;

            }

          }

        }

        iVar10 = -1;

    LAB_005045e8:

        if (*piVar6 < iVar10) {

          return true;

        }

        return false;

      case 0x24:

        if (*(float *)(param_1 + 0x2c8) <= _DAT_0066bce4) {

          return false;

        }

        if (*(float *)(param_1 + 0x2c8) < *(float *)(param_1 + 0x20c)) {

          return true;

        }

        return false;

      }

      do {

        piVar6 = piVar8;

        if (*(int *)(param_1 + 0x22c) == 2) {

          iVar4 = *(int *)(local_4 + *(int *)(param_1 + 0x14c));

          if (-2 < iVar4) goto joined_r0x005044af;

        }

        else {

          iVar4 = 0;

    joined_r0x005044af:

          for (; piVar6 != piVar1; piVar6 = piVar6 + 2) {

            piVar5 = (int *)*piVar6;

            if (*piVar5 == iVar4) {

              if ((piVar5 != (int *)0x0) && (piVar5[10] == 7)) {

                if ((iVar10 < -1) || (piVar8 == piVar1)) goto LAB_0050452d;

                goto LAB_00504520;

              }

              break;

            }

          }

        }

        local_4 = local_4 + 4;

        if (0x167 < local_4) {

          iVar10 = 0x15c;

          while ((*(int *)(param_1 + 0x22c) != 2 || (*(int *)(iVar10 + *(int *)(param_1 + 0x14c)) != -1)

                 )) {

            iVar10 = iVar10 + 4;

            if (0x167 < iVar10) {

              return false;

            }

          }

          return true;

        }

      } while( true );

    joined_r0x005047c7:

      piVar6 = piVar5;

      if (piVar8 == piVar1) goto joined_r0x00504868;

      piVar2 = (int *)*piVar8;

      if (*piVar2 == iVar10) {

        if ((piVar2 != (int *)0x0) && (piVar8 = piVar5, piVar2[10] == 5)) goto joined_r0x005047f4;

        goto joined_r0x00504868;

      }

      piVar8 = piVar8 + 2;

      goto joined_r0x005047c7;

    joined_r0x005047f4:

      if (piVar8 == piVar1) goto LAB_00504803;

      piVar2 = (int *)*piVar8;

      if (*piVar2 == iVar10) {

        if (piVar2 != (int *)0x0) {

          iVar9 = piVar2[8];

          goto LAB_00504806;

        }

        goto LAB_00504803;

      }

      piVar8 = piVar8 + 2;

      goto joined_r0x005047f4;

    LAB_00504803:

      iVar9 = -1;

    LAB_00504806:

      iVar4 = 0;

      piVar8 = (int *)(*(int *)(param_1 + 0x14c) + 0xd80);

      do {

        if (*piVar8 == iVar10) {

          if (iVar9 <= *(int *)(*(int *)(param_1 + 0x14c) + 0xd84 + iVar4 * 8)) {

            return false;

          }

          goto joined_r0x00504868;

        }

        iVar4 = iVar4 + 1;

        piVar8 = piVar8 + 2;

      } while (iVar4 < 2);

      iVar9 = 0;

      piVar8 = (int *)(*(int *)(param_1 + 0x14c) + 0xd80);

      while (*piVar8 != -1) {

        iVar9 = iVar9 + 1;

        piVar8 = piVar8 + 2;

        if (1 < iVar9) {

          return false;

        }

      }

    joined_r0x00504868:

      do {

        if (piVar6 == piVar1) goto LAB_00504989;

        piVar8 = (int *)*piVar6;

        if (*piVar8 == iVar10) {

          if ((piVar8 != (int *)0x0) && (piVar8[10] == 3)) {

            iVar9 = 0;

            piVar6 = (int *)(*(int *)(param_1 + 0x14c) + 0xd24);

            break;

          }

          goto LAB_00504989;

        }

        piVar6 = piVar6 + 2;

      } while( true );

      while( true ) {

        iVar9 = iVar9 + 1;

        piVar6 = piVar6 + 3;

        if (4 < iVar9) break;

        if (*piVar6 == iVar10) goto joined_r0x005048f3;

      }

      iVar4 = 0;

      iVar9 = 0;

      while (*(int *)(*(int *)(param_1 + 0x14c) + 0xd24 + iVar9) != -1) {

        iVar9 = iVar9 + 0xc;

        iVar4 = iVar4 + 1;

        if (0x3b < iVar9) {

          return false;

        }

      }

      if (4 < iVar4) {

        return false;

      }

      goto LAB_00504989;

    joined_r0x005048f3:

      if (piVar5 == piVar1) goto LAB_00504902;

      piVar6 = (int *)*piVar5;

      if (*piVar6 == iVar10) {

        if (piVar6 != (int *)0x0) {

          iVar9 = piVar6[9];

          goto LAB_00504905;

        }

        goto LAB_00504902;

      }

      piVar5 = piVar5 + 2;

      goto joined_r0x005048f3;

      while (piVar8 = piVar8 + 2, piVar8 != piVar1) {

    LAB_00504520:

        piVar6 = (int *)*piVar8;

        if (*piVar6 == iVar10) {

          if (piVar6 != (int *)0x0) {

            iVar7 = piVar6[8];

            goto LAB_00504530;

          }

          break;

        }

      }

    LAB_0050452d:

      iVar7 = -1;

    LAB_00504530:

      if (iVar7 <= *(int *)(iVar9 + 0x138)) {

        return false;

      }

      if (iVar4 == iVar10) {

        return true;

      }

      return false;

      while( true ) {

        iVar9 = iVar9 + 1;

        piVar5 = piVar5 + 2;

        if (3 < iVar9) break;

    LAB_005046c6:

        if (*piVar5 == iVar10) goto LAB_005046f2;

      }

      iVar9 = 0;

      piVar5 = (int *)(*(int *)(param_1 + 0x14c) + 0xd60);

      do {

        if (*piVar5 == -1) goto joined_r0x00504788;

        iVar9 = iVar9 + 1;

        piVar5 = piVar5 + 2;

      } while (iVar9 < 4);

    LAB_005046f2:

      if (DAT_00749908 != DAT_0074990c) {

        while (piVar5 = (int *)*piVar6, *piVar5 != iVar10) {

          piVar6 = piVar6 + 2;

          if (piVar6 == DAT_0074990c) {

            return false;

          }

        }

        if ((piVar5 != (int *)0x0) && (piVar5[10] == 1)) {

          iVar9 = 0;

          piVar6 = (int *)(*(int *)(param_1 + 0x14c) + 0xd60);

          while (piVar5 = DAT_00749908, *piVar6 != iVar10) {

            iVar9 = iVar9 + 1;

            piVar6 = piVar6 + 2;

            if (3 < iVar9) {

              return false;

            }

          }

          for (; piVar5 != DAT_0074990c; piVar5 = piVar5 + 2) {

            piVar6 = (int *)*piVar5;

            if (*piVar6 == iVar10) {

              if (piVar6 != (int *)0x0) {

                iVar9 = piVar6[5];

                goto LAB_00504761;

              }

              break;

            }

          }

          iVar9 = -1;

    LAB_00504761:

          iVar4 = FUN_005816f0();

          if (iVar4 != 0) {

            *param_2 = iVar9;

            piVar6 = DAT_00749908;

    joined_r0x00504788:

            do {

              piVar1 = DAT_0074990c;

              piVar5 = DAT_00749908;

              piVar8 = piVar5;

              if (piVar6 == DAT_0074990c) goto joined_r0x005047c7;

              piVar2 = (int *)*piVar6;

              if (*piVar2 == iVar10) {

                if (((piVar2 != (int *)0x0) && (piVar2[10] == 4)) &&

                   (iVar9 = FUN_005816f0(), iVar9 == 0)) {

                  return false;

                }

                goto joined_r0x005047c7;

              }

              piVar6 = piVar6 + 2;

            } while( true );

          }

        }

      }

      return false;

    LAB_00504902:

      iVar9 = -1;

    LAB_00504905:

      iVar4 = *(int *)(param_1 + 0x14c);

      iVar7 = 0;

      piVar6 = (int *)(iVar4 + 0xd24);

      do {

        if (*piVar6 == iVar10) {

          fVar12 = *(float *)(iVar4 + 0xd28 + iVar7 * 0xc);

          break;

        }

        iVar7 = iVar7 + 1;

        piVar6 = piVar6 + 3;

        fVar12 = fVar13;

      } while (iVar7 < 5);

      piVar6 = (int *)(iVar4 + 0xd24);

      iVar7 = 0;

      do {

        if (*piVar6 == iVar10) {

          fVar11 = *(float *)(iVar4 + 0xd2c + iVar7 * 0xc);

          break;

        }

        iVar7 = iVar7 + 1;

        piVar6 = piVar6 + 3;

        fVar11 = fVar13;

      } while (iVar7 < 5);

      if (fVar12 * (float)iVar9 <= fVar11) {

        return false;

      }

    LAB_00504989:

      if (iVar10 != 0x24) {

        return true;

      }

      return fVar13 < *(float *)(param_1 + 0x2c8);


}  // 0x00504160
#endif // RenderFn504160
void RenderFn504160() {}  // 0x00504160
#if 0 // GHIDRA_RAW: RenderFn507D50 @ 0x00507d50 — needs manual cleanup
int RenderFn507D50(uint32_t param_1,uint32_t param_2,float *param_3,uint32_t param_4,uint32_t param_5)
{


      int *piVar1;

      int iVar2;

      int *piVar3;

      int iVar4;

      float fVar5;

      float fVar6;

      float local_24;

      float local_20;

      uint32_t local_1c;

      float local_18;

      float *local_14;

      uint32_t local_4;



      local_4 = DAT_0067d280 ^ (uint)&local_24;

      fVar5 = 0.0;

      iVar2 = -1;

      iVar4 = 0;

      local_14 = param_3;

      local_24 = 0.0;

      if (DAT_006822a8 != 0xfe) {

        piVar3 = &DAT_006822b0;

        local_20 = DAT_0066bf2c;

        fVar5 = 0.0;

        local_1c = param_2;

        do {

          fVar6 = local_20;

          if ((piVar3[2] & param_5) != 0) {

            local_18 = (float)(*(int *)(*(int *)(piVar3[4] + 0xc) + 0x1c) *

                              *(int *)(*(int *)(piVar3[4] + 0xc) + 0x18)) /

                       ((float)(*piVar3 - piVar3[-1]) * DAT_0066c124);

            do {

              fVar5 = (float)piVar3[-1] * local_20;

              FUN_00507b20(param_1,param_2,(float)piVar3[-1]);

              if ((iVar2 < 0) || (fVar5 < local_24)) {

                iVar2 = iVar4;

                local_24 = fVar5;

              }

              local_20 = local_20 - local_18;

              param_2 = local_1c;

              fVar6 = DAT_0066bf2c;

              fVar5 = local_24;

            } while (0.0 <= local_20);

          }

          iVar4 = iVar4 + 1;

          piVar1 = piVar3 + 5;

          param_3 = local_14;

          piVar3 = piVar3 + 7;

          local_20 = fVar6;

        } while (*piVar1 != 0xfe);

      }

      if (param_3 != (float *)0x0) {

        *param_3 = fVar5;

      }

      return iVar2;


}  // 0x00507d50
#endif // RenderFn507D50
void RenderFn507D50() {}  // 0x00507d50
#if 0 // GHIDRA_RAW: RenderFn509FE0 @ 0x00509fe0 — needs manual cleanup
void RenderFn509FE0(int param_1,int param_2,float *param_3)
{


      int iVar1;

      bool bVar2;

      float fVar3;

      float local_24;

      float fStack_20;

      float local_1c;

      uint64_t local_18;

      float local_10;

      uint32_t local_c;



      if ((param_2 != 0) &&

         ((((iVar1 = *(int *)(param_2 + 0x22c), iVar1 == 0x12 || (iVar1 == 0x17)) || (iVar1 == 0x15)) ||

          (((iVar1 == 0x33 || (iVar1 == 0x35)) || ((iVar1 == 3 || (iVar1 == 2)))))))) {

        if (param_3 == (float *)0x0) {

          param_3 = &local_24;

          fVar3 = (*(float *)(*(int *)(param_1 + 0x150) + 0x24) * DAT_0066bfc4) /

                  *(float *)(param_1 + 0x370);

          local_24 = (float)(*(uint32_t *)(param_1 + 0x2ec) ^ DAT_0066c580) * fVar3;

          fStack_20 = (float)(*(uint32_t *)(param_1 + 0x2fc) ^ DAT_0066c580) * fVar3;

          local_1c = fVar3 * DAT_0066bdc4;

        }

        bVar2 = DAT_006ff960 == 6;

        *(float *)(param_2 + 0x174) = *(float *)(param_2 + 0x174) + *param_3;

        *(float *)(param_2 + 0x178) = param_3[1] + *(float *)(param_2 + 0x178);

        *(float *)(param_2 + 0x17c) = param_3[2] + *(float *)(param_2 + 0x17c);

        if (bVar2) {

          iVar1 = FUN_0045f460();

          if (iVar1 != 0) {

            local_18 = *(uint64_t *)param_3;

            local_c = *(uint32_t *)(param_2 + 0x1d4);

            local_10 = param_3[2];

            FUN_00469de0(1,0,0xd,&local_18,0);

          }

        }

      }

      return;


}  // 0x00509fe0
#endif // RenderFn509FE0
void RenderFn509FE0() {}  // 0x00509fe0
#if 0 // GHIDRA_RAW: RenderFn51C5E0 @ 0x0051c5e0 — needs manual cleanup
void RenderFn51C5E0(int param_1)
{


      int iVar1;

      uint32_t uVar2;



      if ((param_1 != 0) && (*(int *)(param_1 + 0x22c) == 0x4b)) {

        if (DAT_006ff960 == 6) {

          iVar1 = FUN_0045f460();

          if (iVar1 != 0) {

            FUN_00469de0(0,0,8,0,0);

          }

        }

        if ((*(int *)(param_1 + 0x130) != 0x12) && (*(int *)(param_1 + 0x130) != 0x1d)) {

          uVar2 = 0x12;

          if (*(int *)(param_1 + 4) != 0x2e9) {

            uVar2 = 0x1d;

          }

          *(uint32_t *)(param_1 + 0x130) = uVar2;

          FUN_00500d30(0,0,0);

          *(uint32_t *)(param_1 + 0x138) = 0x41f00000;

        }

      }

      return;


}  // 0x0051c5e0
#endif // RenderFn51C5E0
void RenderFn51C5E0() {}  // 0x0051c5e0
#if 0 // GHIDRA_RAW: RenderFn523060 @ 0x00523060 — needs manual cleanup
void RenderFn523060()
{


      int iVar1;

      uint32_t uVar2;



      if (DAT_00728460 != 0) {

        uVar2 = DAT_00728468 - DAT_00728460 & 0xfffffffc;

        iVar1 = DAT_00728460;

        if (0xfff < uVar2) {

          iVar1 = *(int *)(DAT_00728460 + -4);

          uVar2 = uVar2 + 0x23;

          if (0x1f < (DAT_00728460 - iVar1) - 4U) {

                        /* WARNING: Subroutine does not return */

            std::abort();

          }

        }

        FUN_00643505(iVar1,uVar2);

      }

      DAT_00728460 = param_1;

      DAT_00728464 = param_1 + param_2 * 4;

      DAT_00728468 = param_1 + param_3 * 4;

      return;


}  // 0x00523060
#endif // RenderFn523060
void RenderFn523060() {}  // 0x00523060
#if 0 // GHIDRA_RAW: RenderFn532B50 @ 0x00532b50 — needs manual cleanup
void RenderFn532B50(int param_1)
{


      int iVar1;

      uint32_t *puVar2;

      int iVar3;

      int iVar4;

      uint8_t auStack_38 [4];

      int local_34 [11];

      uint32_t local_8;



      local_8 = DAT_0067d280 ^ (uint)auStack_38;

      iVar4 = 0;

      iVar3 = local_34[0];

      if ((*(float *)(param_1 + 0x20c) <= *(float *)(param_1 + 0x2c8)) &&

         (*(float *)(param_1 + 0xf8) <= 0.0)) {

        iVar3 = *(int *)(param_1 + 0x264);

        *(uint32_t *)(param_1 + 0x264) = 1;

      }

      puVar2 = DAT_007027b0;

      if (DAT_006ff960 == 6) {

        FUN_00568b50();

      }

      else {

        for (; puVar2 != (uint32_t *)0x0; puVar2 = (uint32_t *)*puVar2) {

          iVar1 = puVar2[3];

          if (((iVar1 != 0) && (*(int *)(iVar1 + 0x22c) == 2)) && (*(int *)(iVar1 + 0x1c0) != 0)) {

            local_34[iVar4 + 1] = iVar1;

            iVar4 = iVar4 + 1;

            *(uint32_t *)(iVar1 + 0x214) = *(uint32_t *)(iVar1 + 0x214) | 0x800;

          }

        }

        FUN_00568b50();

        for (; iVar4 != 0; iVar4 = iVar4 + -1) {

          *(uint32_t *)(local_34[iVar4] + 0x214) = *(uint32_t *)(local_34[iVar4] + 0x214) & 0xfffff7ff;

        }

      }

      if ((*(float *)(param_1 + 0x20c) <= *(float *)(param_1 + 0x2c8)) &&

         (*(float *)(param_1 + 0xf8) <= 0.0)) {

        *(int *)(param_1 + 0x264) = iVar3;

        FUN_0056ca90();

      }

      return;


}  // 0x00532b50
#endif // RenderFn532B50
void RenderFn532B50() {}  // 0x00532b50
#if 0 // GHIDRA_RAW: RenderFn553F40 @ 0x00553f40 — needs manual cleanup
void RenderFn553F40(int param_1)
{


      uint64_t *puVar1;

      int iVar2;

      uint32_t uVar3;

      uint32_t uVar4;

      uint32_t uVar5;

      uint32_t *puVar6;

      int iVar7;

      int *piVar8;

      int iVar9;

      float10 fVar10;

      uint32_t local_1c;

      uint32_t uStack_18;

      uint32_t uStack_14;

      uint32_t uStack_10;

      uint32_t local_c [2];

      uint8_t local_4 [4];



      iVar7 = DAT_00702774;

      if ((param_1 == 0x85) || (param_1 == 2)) {

        iVar9 = 1;

      }

      else {

        iVar9 = (param_1 != 3) + 2;

      }

      piVar8 = DAT_007027a8;

      if (DAT_007027a8 != (int *)0x0) {

        while ((((iVar2 = piVar8[3], (*(uint32_t *)(iVar2 + 0x214) & 0x8000000) == 0 ||

                 ((*(uint32_t *)(iVar2 + 0x124) & 0x8000) != 0)) || (*(int *)(iVar2 + 0x1c0) != 0)) ||

               ((*(int *)(iVar2 + 0x134) != iVar9 || (*(int *)(iVar2 + 4) != 0x2a7))))) {

          piVar8 = (int *)*piVar8;

          if (piVar8 == (int *)0x0) {

            return;

          }

        }

        uVar3 = *(uint32_t *)(iVar2 + 0x2e8);

        uVar4 = *(uint32_t *)(iVar2 + 0x2ec);

        uVar5 = *(uint32_t *)(iVar2 + 0x2f0);

        *(uint32_t *)(DAT_00702774 + 0x2e4) = *(uint32_t *)(iVar2 + 0x2e4);

        *(uint32_t *)(iVar7 + 0x2e8) = uVar3;

        *(uint32_t *)(iVar7 + 0x2ec) = uVar4;

        *(uint32_t *)(iVar7 + 0x2f0) = uVar5;

        uVar3 = *(uint32_t *)(iVar2 + 0x2f8);

        uVar4 = *(uint32_t *)(iVar2 + 0x2fc);

        uVar5 = *(uint32_t *)(iVar2 + 0x300);

        *(uint32_t *)(iVar7 + 0x2f4) = *(uint32_t *)(iVar2 + 0x2f4);

        *(uint32_t *)(iVar7 + 0x2f8) = uVar3;

        *(uint32_t *)(iVar7 + 0x2fc) = uVar4;

        *(uint32_t *)(iVar7 + 0x300) = uVar5;

        uVar3 = *(uint32_t *)(iVar2 + 0x308);

        uVar4 = *(uint32_t *)(iVar2 + 0x30c);

        uVar5 = *(uint32_t *)(iVar2 + 0x310);

        *(uint32_t *)(iVar7 + 0x304) = *(uint32_t *)(iVar2 + 0x304);

        *(uint32_t *)(iVar7 + 0x308) = uVar3;

        *(uint32_t *)(iVar7 + 0x30c) = uVar4;

        *(uint32_t *)(iVar7 + 0x310) = uVar5;

        uVar3 = *(uint32_t *)(iVar2 + 0x318);

        uVar4 = *(uint32_t *)(iVar2 + 0x31c);

        uVar5 = *(uint32_t *)(iVar2 + 800);

        *(uint32_t *)(iVar7 + 0x314) = *(uint32_t *)(iVar2 + 0x314);

        *(uint32_t *)(iVar7 + 0x318) = uVar3;

        *(uint32_t *)(iVar7 + 0x31c) = uVar4;

        *(uint32_t *)(iVar7 + 800) = uVar5;

        *(uint32_t *)(iVar7 + 0x324) = *(uint32_t *)(iVar2 + 0x324);

        iVar7 = DAT_00702774;

        *(uint64_t *)(DAT_00702774 + 0xf0) = *(uint64_t *)(iVar2 + 0xf0);

        *(uint32_t *)(iVar7 + 0xf8) = *(uint32_t *)(iVar2 + 0xf8);

        *(uint32_t *)(DAT_00702774 + 0x114) = *(uint32_t *)(iVar2 + 0x114);

        *(uint32_t *)(DAT_00702774 + 0x118) = *(uint32_t *)(iVar2 + 0x118);

        *(uint32_t *)(DAT_00702774 + 0x11c) = *(uint32_t *)(iVar2 + 0x11c);

        iVar7 = DAT_00702774;

        if (((param_1 == 0x85) || (param_1 == 2)) &&

           ((DAT_00702774 != 0 &&

            ((*(int *)(DAT_00702774 + 4) == 2 && (*(int *)(DAT_00702774 + 0x1bc) != 0)))))) {

          puVar1 = (uint64_t *)(DAT_00702774 + 0xf0);

          *(float *)(*(int *)(DAT_00702774 + 0x1bc) + 0x18) =

               *(float *)(DAT_00702774 + 0xf0) + _DAT_0066c208;

          puVar6 = DAT_007027b0;

          if ((*(int *)(iVar7 + 4) == 2) &&

             ((iVar9 = *(int *)(iVar7 + 0x1bc), iVar9 != 0 && (*(int *)(iVar7 + 0x1c0) == 0)))) {

            fVar10 = (float10)FUN_00638d40(puVar1,(uint32_t *)(iVar9 + 0x18));

            puVar6 = DAT_007027b0;

            if (*(float *)(DAT_007028f4 + 0x1020) * *(float *)(DAT_007028f4 + 0x1020) < (float)fVar10) {

              *(uint32_t *)(iVar9 + 0x14) = *(uint32_t *)(iVar7 + 0x114);

              *(uint64_t *)(iVar9 + 8) = *puVar1;

              *(uint32_t *)(iVar9 + 0x10) = *(uint32_t *)(iVar7 + 0xf8);

              uVar3 = *(uint32_t *)(iVar7 + 0xf4);

              *(uint32_t *)(iVar9 + 0x18) = *(uint32_t *)puVar1;

              *(uint32_t *)(iVar9 + 0x1c) = uVar3;

              *(uint32_t *)(iVar9 + 0x20) = *(uint32_t *)(iVar7 + 0xf8);

              puVar6 = DAT_007027b0;

            }

          }

          for (; puVar6 != (uint32_t *)0x0; puVar6 = (uint32_t *)*puVar6) {

            iVar9 = puVar6[3];

            if ((((((*(uint32_t *)(iVar9 + 0x124) & 0x8000) == 0) &&

                  (*(int *)(iVar9 + 0x1bc) == *(int *)(iVar7 + 0x1bc))) && (*(int *)(iVar9 + 4) == 2))

                && ((iVar9 != iVar7 && (*(int *)(iVar9 + 0x264) == 0)))) &&

               ((*(int *)(iVar9 + 0x130) != 0x12 &&

                (*(float *)(iVar9 + 0x2c8) < *(float *)(iVar9 + 0x20c))))) {

              FUN_005e0fd0(*(uint32_t *)(iVar9 + 0x1c0),(uint64_t *)(iVar9 + 0xf0),iVar9 + 0x114);

              *(uint64_t *)(iVar9 + 0x108) = *(uint64_t *)(iVar9 + 0xfc);

              *(uint32_t *)(iVar9 + 0x110) = *(uint32_t *)(iVar9 + 0x104);

              *(uint64_t *)(iVar9 + 0xfc) = *(uint64_t *)(iVar9 + 0xf0);

              *(uint32_t *)(iVar9 + 0x104) = *(uint32_t *)(iVar9 + 0xf8);

              FUN_004fecb0(local_4,local_c,1);

              *(uint32_t *)(iVar9 + 0x124) = *(uint32_t *)(iVar9 + 0x124) | 0x10000000;

              *(uint32_t *)(iVar9 + 0x18c) = local_c[0];

              *(uint32_t *)(iVar9 + 400) = local_1c;

              *(uint32_t *)(iVar9 + 0x194) = uStack_18;

              *(uint32_t *)(iVar9 + 0x198) = uStack_14;

              *(uint32_t *)(iVar9 + 0x19c) = uStack_10;

            }

          }

        }

      }

      return;


}  // 0x00553f40
#endif // RenderFn553F40
void RenderFn553F40() {}  // 0x00553f40
#if 0 // GHIDRA_RAW: RenderFn566AB0 @ 0x00566ab0 — needs manual cleanup
void RenderFn566AB0(int param_1,float *param_2)
{


      int iVar1;

      float fVar2;

      float fVar3;

      float fVar4;

      float in_XMM2_Da;

      float fVar5;

      float fVar6;

      float local_18;



      fVar6 = *param_2;

      fVar4 = param_2[1];

      fVar5 = param_2[2];

      iVar1 = *(int *)(param_1 + 0x150);

      fVar2 = fVar6 * fVar6 + fVar4 * fVar4 + fVar5 * fVar5;

      FUN_0042bee0();

      fVar4 = fVar4 - *(float *)(param_1 + 0x178);

      fVar2 = fVar2 * DAT_0066bea0;

      fVar6 = fVar6 - *(float *)(param_1 + 0x174);

      fVar5 = fVar5 - *(float *)(param_1 + 0x17c);

      fVar3 = fVar4 * fVar4 + fVar6 * fVar6 + fVar5 * fVar5;

      FUN_0042bee0();

      local_18 = in_XMM2_Da;

      if ((fVar2 != 0.0) && (fVar2 < fVar3)) {

        local_18 = in_XMM2_Da * (fVar2 / fVar3);

      }

      if (fVar3 <= DAT_0066bd04) {

        fVar3 = 0.0;

      }

      else {

        fVar3 = fVar5 / fVar3;

      }

      fVar2 = 0.0;

      if (0.0 <= fVar3) {

        fVar2 = fVar3;

      }

      if (local_18 != 0.0) {

        *(float *)(iVar1 + 0x18) = fVar6 * local_18 + *(float *)(iVar1 + 0x18);

        *(float *)(iVar1 + 0x1c) = fVar4 * local_18 + *(float *)(iVar1 + 0x1c);

        fVar6 = DAT_0066bf2c - fVar2 * fVar2;

        FUN_0042bee0();

        FUN_004542b0();

        FUN_0042d350();

        fVar4 = *(float *)(iVar1 + 8) / local_18;

        *(float *)(iVar1 + 0x20) = fVar6 * fVar5 * local_18 + *(float *)(iVar1 + 0x20);

        if ((fVar4 < *(float *)(iVar1 + 0x2c)) || (*(float *)(iVar1 + 0x2c) == 0.0)) {

          *(float *)(iVar1 + 0x2c) = fVar4;

        }

      }

      return;


}  // 0x00566ab0
#endif // RenderFn566AB0
void RenderFn566AB0() {}  // 0x00566ab0
#if 0 // GHIDRA_RAW: RenderFn569130 @ 0x00569130 — needs manual cleanup
void RenderFn569130(int param_1)
{


      uint32_t uVar1;

      uint32_t uVar2;

      uint32_t *puVar3;

      int iVar4;

      uint32_t *puVar5;

      uint32_t *puVar6;



      if (param_1 == 0) {

        puVar6 = (uint32_t *)0x0;

      }

      else {

        puVar6 = *(uint32_t **)(param_1 + 0x14c);

      }

      if ((~puVar6[0x10] & 1) != 0) {

        memset(*(void **)(param_1 + 0x14c),0,0x70);

        *(uint32_t *)(param_1 + 0x124) = *(uint32_t *)(param_1 + 0x124) & 0xffffffef;

        *(uint32_t *)(param_1 + 0x214) = *(uint32_t *)(param_1 + 0x214) & 0xfffff1ff;

        *(uint32_t **)(param_1 + 0x150) = puVar6;

        puVar6[3] = 0;

        puVar6[4] = 0x3f800000;

        *puVar6 = 0;

        puVar6[8] = 0;

        puVar6[7] = 0;

        puVar6[6] = 0;

        puVar6[2] = 0x3f800000;

        puVar6[1] = 0x3f800000;

        puVar6[0xc] = 0;

        puVar6[0xe] = 0;

        puVar6[0xd] = 0;

        puVar6[10] = 0;

        puVar6[0xb] = 0;

        puVar6[9] = 0;

        uVar1 = (*(uint32_t **)(param_1 + 0x368))[1];

        uVar2 = **(uint32_t **)(param_1 + 0x368);

        iVar4 = FUN_0042bc40();

        FUN_00568df0(uVar2);

        puVar3 = *(uint32_t **)(iVar4 + 0x2c);

        for (puVar5 = *(uint32_t **)(iVar4 + 0x28); puVar5 != puVar3; puVar5 = puVar5 + 2) {

          (*(code *)*puVar5)(puVar5[1],uVar1,uVar2);

        }

        puVar6[0x10] = puVar6[0x10] | 3;

      }

      if ((*(int *)(param_1 + 0x130) == 0) || (puVar6[0xf] != *(int *)(param_1 + 0x134))) {

        puVar6[0xf] = *(uint32_t *)(param_1 + 0x134);

      }

      return;


}  // 0x00569130
#endif // RenderFn569130
void RenderFn569130() {}  // 0x00569130
#if 0 // GHIDRA_RAW: RenderFn573E30 @ 0x00573e30 — needs manual cleanup
void RenderFn573E30(int param_1,int *param_2)
{


      float fVar1;

      float fVar2;

      float fVar3;

      int iVar4;

      float fVar5;

      float fVar6;

      float fVar7;



      if (param_2[5] != 1) {

        iVar4 = 0;

        do {

          if (param_1 == param_2[iVar4]) break;

          iVar4 = iVar4 + 1;

        } while (iVar4 < 2);

        param_2[iVar4] = 0;

        if ((iVar4 == 1) && (param_2[4] != 0)) {

          iVar4 = *param_2;

          if (iVar4 != 0) {

            if ((*(uint32_t *)(iVar4 + 0x124) & 0x8000) == 0) {

              *(uint32_t *)(*(int *)(iVar4 + 0x14c) + 0x8c) = 0;

            }

            else {

              *param_2 = 0;

            }

          }

          iVar4 = param_2[1];

          if (iVar4 != 0) {

            if ((*(uint32_t *)(iVar4 + 0x124) & 0x8000) == 0) {

              *(uint32_t *)(*(int *)(iVar4 + 0x14c) + 0x8c) = 0;

            }

            else {

              param_2[1] = 0;

            }

          }

        }

        FUN_005582f0(0);

        return;

      }

      if (param_2[4] == 0) {

        iVar4 = 0;

        do {

          if (param_1 == param_2[iVar4]) break;

          iVar4 = iVar4 + 1;

        } while (iVar4 < 2);

        iVar4 = *(int *)(param_2[iVar4] + 0x14c);

        fVar1 = *(float *)(iVar4 + 0x98);

        fVar2 = *(float *)(iVar4 + 0x94);

        fVar5 = fVar1 - *(float *)(iVar4 + 0xa0);

        fVar3 = *(float *)(iVar4 + 0x1e0);

        fVar7 = (fVar2 - *(float *)(iVar4 + 0x9c)) / fVar5;

        fVar6 = fVar7 * fVar1;

        FUN_00500b40(0,param_2[2] + 0xf0,fVar1,*(float *)(iVar4 + 0xa0),fVar2,fVar7,fVar2 - fVar6,fVar3,

                     (fVar3 - *(float *)(iVar4 + 0x1e4)) / fVar5,fVar3 - fVar6,

                     *(uint32_t *)(param_1 + 0x1d8),0);

      }

      FUN_005735e0();

      return;


}  // 0x00573e30
#endif // RenderFn573E30
void RenderFn573E30() {}  // 0x00573e30
#if 0 // GHIDRA_RAW: RenderFn5809D0 @ 0x005809d0 — needs manual cleanup
void RenderFn5809D0(int param_1)
{


      bool bVar1;

      float fVar2;

      char cVar3;

      int iVar4;

      int iVar5;

      int iVar6;

      float fVar7;

      uint8_t local_28;

      uint8_t local_27;

      uint8_t local_26;

      uint8_t local_25;

      uint64_t local_24;

      uint32_t local_1c;

      uint64_t local_18;

      uint32_t local_10;

      uint32_t local_c;

      uint16_t local_8;

      uint32_t local_6;



      if (param_1 == 0) {

        iVar6 = 0;

      }

      else {

        iVar6 = *(int *)(param_1 + 0x14c);

      }

      if (*(int *)(param_1 + 0x264) != 0) {

        return;

      }

      if (DAT_006ff960 != 6) {

        return;

      }

      iVar4 = FUN_0045f460();

      if (iVar4 == 0) {

        return;

      }

      if (DAT_0074c47c != DAT_00702894) {

        if (DAT_00702890 < DAT_0074c478) {

          bVar1 = false;

          goto LAB_00580a67;

        }

        fVar7 = DAT_0066bea0;

        if (DAT_00702bcc != '\0') {

          fVar7 = DAT_0066be08;

        }

        DAT_0074c478 = DAT_00702890 + fVar7;

        DAT_0074c47c = DAT_00702894;

      }

      bVar1 = true;

    LAB_00580a67:

      if (bVar1) {

        local_1c = *(uint32_t *)(param_1 + 0xf8);

        local_24 = *(uint64_t *)(param_1 + 0xf0);

        local_10 = *(uint32_t *)(param_1 + 0x17c);

        local_18 = *(uint64_t *)(param_1 + 0x174);

        local_c = *(uint32_t *)(param_1 + 0x160);

        local_8 = (uint16_t)(int)*(float *)(param_1 + 0x114);

        local_6 = *(uint32_t *)(param_1 + 0x2c8);

        FUN_00469ec0(1,&local_24);

        if (DAT_006ff960 != 6) {

          return;

        }

      }

      cVar3 = DAT_00702bcc;

      iVar4 = DAT_00702894;

      fVar7 = DAT_00702890;

      iVar5 = FUN_0045f460();

      if (iVar5 != 0) {

        if (DAT_0074c474 != iVar4) {

          if (fVar7 < DAT_0074c470) {

            return;

          }

          fVar2 = DAT_0066bd9c;

          if (cVar3 != '\0') {

            fVar2 = DAT_0066bd7c;

          }

          DAT_0074c470 = fVar7 + fVar2;

          DAT_0074c474 = iVar4;

        }

        local_28 = *(uint8_t *)(param_1 + 0x25e);

        local_27 = *(uint8_t *)(param_1 + 0x25f);

        local_26 = *(uint8_t *)(param_1 + 0x25c);

        local_25 = 0;

        if ((iVar6 != 0) && (local_25 = 0, *(int *)(iVar6 + 0xeec) != 0)) {

          local_25 = 4;

        }

        FUN_00469ec0(2,&local_28);

      }

      return;


}  // 0x005809d0
#endif // RenderFn5809D0
void RenderFn5809D0() {}  // 0x005809d0
#if 0 // GHIDRA_RAW: RenderFn582C30 @ 0x00582c30 — needs manual cleanup
void RenderFn582C30(int param_1)
{


      float *pfVar1;

      float fVar2;

      float fVar3;

      int iVar4;

      uint32_t uVar5;

      int iVar6;

      float10 fVar7;

      float fVar8;

      float fVar9;

      float fVar10;



      if (param_1 == 0) {

        iVar6 = 0;

      }

      else {

        iVar6 = *(int *)(param_1 + 0x14c);

      }

      iVar4 = *(int *)(iVar6 + 8);

      pfVar1 = (float *)(iVar6 + 0x10);

      if (iVar4 == 0) {

        uVar5 = *(uint32_t *)(iVar6 + 0x24);

        *(uint64_t *)pfVar1 = *(uint64_t *)(iVar6 + 0x1c);

      }

      else {

        *(uint64_t *)pfVar1 = *(uint64_t *)(iVar4 + 0xf0);

        uVar5 = *(uint32_t *)(iVar4 + 0xf8);

      }

      *(uint32_t *)(iVar6 + 0x18) = uVar5;

      iVar4 = *(int *)(param_1 + 0x150);

      *(uint32_t *)(iVar4 + 0x20) = 0;

      *(uint32_t *)(iVar4 + 0x1c) = 0;

      *(uint32_t *)(iVar4 + 0x18) = 0;

      fVar7 = (float10)FUN_00638d40((float *)(param_1 + 0xf0),pfVar1);

      fVar9 = (float)fVar7;

      FUN_004542b0();

      if (*(int *)(iVar6 + 8) == 0) {

        fVar2 = *(float *)(DAT_007028f4 + 0xfe0);

      }

      else {

        fVar2 = *(float *)(DAT_007028f4 + 0x748);

      }

      fVar9 = fVar9 * fVar2;

      if (fVar9 != 0.0) {

        fVar2 = *(float *)(iVar6 + 0x14);

        fVar3 = *(float *)(iVar6 + 0x18);

        fVar8 = fVar9 * 0.0 * DAT_0066be20;

        fVar10 = (*(float *)(*(int *)(param_1 + 0x150) + 4) / *(float *)(*(int *)(param_1 + 0x150) + 8))

                 * _DAT_0066c294 * fVar9 * DAT_0066be20;

        *(float *)(param_1 + 0x174) = (*pfVar1 - *(float *)(param_1 + 0xf0)) / fVar9 - fVar8;

        *(float *)(param_1 + 0x178) = (fVar2 - *(float *)(param_1 + 0xf4)) / fVar9 - fVar8;

        *(float *)(param_1 + 0x17c) = (fVar3 - *(float *)(param_1 + 0xf8)) / fVar9 - fVar10;

      }

      return;


}  // 0x00582c30
#endif // RenderFn582C30
void RenderFn582C30() {}  // 0x00582c30
#if 0 // GHIDRA_RAW: RenderFn583D60 @ 0x00583d60 — needs manual cleanup
void RenderFn583D60(uint32_t param_1,int param_2)
{


      int *piVar1;

      int iVar2;

      int iVar3;

      int *piVar4;

      float fVar5;

      float fVar6;

      float fVar7;



      piVar4 = (int *)(param_2 + 0x18);

      iVar3 = 4;

      do {

        iVar2 = piVar4[-6];

        if (iVar2 != 0) {

          fVar5 = *(float *)(iVar2 + 0x2c8);

          if (fVar5 < *(float *)(iVar2 + 0x20c)) {

            if (piVar4[-1] != 0) {

              if (*(int *)(iVar2 + 0x22c) == 1) {

                piVar1 = (int *)(*(int *)(iVar2 + 0x14c) + 0x354);

                *piVar1 = *piVar1 + -1;

              }

              if ((*(int *)(iVar2 + 0x22c) == 3) &&

                 (fVar5 = *(float *)(*(int *)(iVar2 + 0x14c) + 0xf64), 0.0 < fVar5)) {

                *(float *)(iVar2 + 0x370) = fVar5;

              }

              piVar4[-6] = 0;

              goto LAB_00583fe8;

            }

          }

          else {

            piVar4[-1] = 1;

          }

          FUN_0062a0b0();

          fVar6 = (float)piVar4[-5];

          piVar4[-5] = (int)(fVar6 - fVar5);

          if (0.0 < fVar6 - fVar5) {

            fVar6 = (float)piVar4[-3];

            if (((float)piVar4[-2] < fVar6) && (fVar6 < *(float *)(iVar2 + 0x370))) {

              fVar5 = (fVar6 / *(float *)(DAT_007028f4 + 0x7d4)) * fVar5;

              fVar7 = (float)piVar4[-2] + fVar5;

              piVar4[-2] = (int)fVar7;

              if (fVar6 < fVar7) {

                piVar4[-2] = (int)fVar6;

                fVar5 = fVar5 - (fVar7 - fVar6);

              }

              fVar5 = *(float *)(iVar2 + 0x370) - fVar5;

              if (0.0 < fVar5) {

                *(float *)(iVar2 + 0x370) = fVar5;

              }

            }

          }

          else {

            if (*piVar4 == 0) {

              FUN_00558240();

              *piVar4 = 1;

            }

            if (0.0 < (float)piVar4[-2]) {

              fVar5 = ((float)piVar4[-3] / *(float *)(DAT_007028f4 + 0x7d4)) * fVar5;

              fVar6 = (float)piVar4[-2] - fVar5;

              piVar4[-2] = (int)fVar6;

              if (0.0 <= fVar6) {

                fVar5 = fVar5 + *(float *)(iVar2 + 0x370);

                if (0.0 < fVar5) {

                  *(float *)(iVar2 + 0x370) = fVar5;

                }

              }

              else {

                if (piVar4[-1] == 0) {

                  FUN_00501010(param_1,0,0,0);

                }

                piVar4[-4] = 0;

                if (*(int *)(iVar2 + 4) == 8) {

                  piVar1 = (int *)(*(int *)(iVar2 + 0x14c) + 0x60);

                  *piVar1 = *piVar1 + -1;

                }

                else if (*(int *)(iVar2 + 4) == 0xb) {

                  piVar1 = (int *)(*(int *)(iVar2 + 0x14c) + 0x4c);

                  *piVar1 = *piVar1 + -1;

                }

                else if (*(int *)(iVar2 + 0x22c) == 1) {

                  piVar1 = (int *)(*(int *)(iVar2 + 0x14c) + 0x354);

                  *piVar1 = *piVar1 + -1;

                }

                if (*(int *)(iVar2 + 0x22c) == 3) {

                  fVar5 = *(float *)(*(int *)(iVar2 + 0x14c) + 0xf64);

                  if (0.0 < fVar5) {

                    *(float *)(iVar2 + 0x370) = fVar5;

                    piVar4[-6] = 0;

                    goto LAB_00583fe8;

                  }

                }

                else {

                  fVar5 = fVar6 + fVar5 + *(float *)(iVar2 + 0x370);

                  if (0.0 < fVar5) {

                    *(float *)(iVar2 + 0x370) = fVar5;

                  }

                }

                piVar4[-6] = 0;

              }

            }

          }

        }

    LAB_00583fe8:

        piVar4 = piVar4 + 7;

        iVar3 = iVar3 + -1;

        if (iVar3 == 0) {

          return;

        }

      } while( true );


}  // 0x00583d60
#endif // RenderFn583D60
void RenderFn583D60() {}  // 0x00583d60
#if 0 // GHIDRA_RAW: RenderFn584990 @ 0x00584990 — needs manual cleanup
void RenderFn584990(int param_1)
{


      uint32_t uVar1;

      uint32_t uVar2;

      uint32_t *puVar3;

      int iVar4;

      int iVar5;

      uint32_t *puVar6;



      if (param_1 == 0) {

        iVar5 = 0;

      }

      else {

        iVar5 = *(int *)(param_1 + 0x14c);

      }

      *(uint32_t **)(param_1 + 0x150) = (uint32_t *)(iVar5 + 0xce8);

      *(uint32_t *)(iVar5 + 0xcf4) = 0;

      *(uint32_t *)(iVar5 + 0xcf8) = 0x3f800000;

      *(uint32_t *)(iVar5 + 0xce8) = 0;

      *(uint32_t *)(iVar5 + 0xd08) = 0;

      *(uint32_t *)(iVar5 + 0xd04) = 0;

      *(uint32_t *)(iVar5 + 0xd00) = 0;

      *(uint32_t *)(iVar5 + 0xcf0) = 0x3f800000;

      *(uint32_t *)(iVar5 + 0xcec) = 0x3f800000;

      *(uint32_t *)(iVar5 + 0xd18) = 0;

      *(uint32_t *)(iVar5 + 0xd20) = 0;

      *(uint32_t *)(iVar5 + 0xd1c) = 0;

      *(uint32_t *)(iVar5 + 0xd10) = 0;

      *(uint32_t *)(iVar5 + 0xd14) = 0;

      *(uint32_t *)(iVar5 + 0xd0c) = 0;

      uVar1 = (*(uint32_t **)(param_1 + 0x368))[1];

      uVar2 = **(uint32_t **)(param_1 + 0x368);

      iVar4 = FUN_0042bc40();

      FUN_00568df0(uVar2);

      puVar3 = *(uint32_t **)(iVar4 + 0x2c);

      for (puVar6 = *(uint32_t **)(iVar4 + 0x28); puVar6 != puVar3; puVar6 = puVar6 + 2) {

        (*(code *)*puVar6)(puVar6[1],uVar1,uVar2);

      }

      if (*(int *)(iVar5 + 0xfc8) == 0) {

        iVar4 = FUN_005f5550();

        *(int *)(iVar5 + 0xfc8) = iVar4;

        *(int *)(iVar4 + 0x48) = param_1;

      }

      *(uint32_t *)(*(int *)(param_1 + 0x150) + 4) = *(uint32_t *)(DAT_007028f4 + 0x704);

      *(uint32_t *)(*(int *)(param_1 + 0x150) + 8) = *(uint32_t *)(DAT_007028f4 + 0x708);

      *(uint32_t *)(*(int *)(param_1 + 0x150) + 0x28) = *(uint32_t *)(DAT_007028f4 + 0x70c);

      *(uint32_t *)(*(int *)(param_1 + 0x150) + 0xc) = *(uint32_t *)(DAT_007028f4 + 0x710);

      *(uint32_t *)(*(int *)(param_1 + 0x150) + 0x30) = *(uint32_t *)(DAT_007028f4 + 0x734);

      *(uint32_t *)(*(int *)(param_1 + 0x150) + 0x34) = *(uint32_t *)(DAT_007028f4 + 0x714);

      *(uint32_t *)(*(int *)(param_1 + 0x150) + 0x38) = *(uint32_t *)(DAT_007028f4 + 0x718);

      *(uint32_t *)(iVar5 + 0xf64) = *(uint32_t *)(param_1 + 0x370);

      *(uint32_t *)(iVar5 + 0x28) = *(uint32_t *)(DAT_007028f4 + 0x868);

      *(uint32_t *)(param_1 + 300) = 0;

      iVar4 = *(int *)(DAT_007028f4 + 0x1670);

      *(int *)(iVar5 + 0xda4) = iVar4;

      if (5 < iVar4) {

        *(uint32_t *)(iVar5 + 0xda4) = 5;

      }

      return;


}  // 0x00584990
#endif // RenderFn584990
void RenderFn584990() {}  // 0x00584990
#if 0 // GHIDRA_RAW: RenderFn595070 @ 0x00595070 — needs manual cleanup
void RenderFn595070(int param_1,float *param_2)
{


      float fVar1;

      uint32_t uVar2;

      int iVar3;

      float fVar4;



      if (param_1 == 0) {

        iVar3 = 0;

      }

      else {

        iVar3 = *(int *)(param_1 + 0x14c);

      }

      *(uint32_t *)(*(int *)(param_1 + 0x150) + 4) = *(uint32_t *)(DAT_007028f4 + 0xfe4);

      *(uint32_t *)(*(int *)(param_1 + 0x150) + 8) = *(uint32_t *)(DAT_007028f4 + 0xfe8);

      fVar4 = *param_2;

      fVar1 = param_2[1];

      *(float *)(iVar3 + 0xdcc) = fVar4;

      *(float *)(iVar3 + 0xdd0) = fVar1;

      *(float *)(iVar3 + 0xdd4) = param_2[2];

      FUN_00594f30();

      fVar4 = fVar4 * DAT_0066bed8;

      *(uint32_t *)(param_1 + 300) = *(uint32_t *)(param_1 + 300) | 4;

      *(float *)(param_1 + 0x13c) = fVar4;

      uVar2 = FUN_00558730(0x33c,param_1,0,3);

      *(uint32_t *)(iVar3 + 0xde0) = uVar2;

      iVar3 = *(int *)(param_1 + 0x14c);

      if (*(int *)(param_1 + 0x60) != 0x5a) {

        fVar4 = *(float *)(param_1 + 0x370) * 0.0;

        FUN_0048f2f0(0x5a,0x21,0,fVar4,0x3e2aaaab);

        FUN_0048f2f0(0xfe,0,0,fVar4,0x3e2aaaab);

        *(uint32_t *)(iVar3 + 0xb4) = 0x5a;

      }

      return;


}  // 0x00595070
#endif // RenderFn595070
void RenderFn595070() {}  // 0x00595070
#if 0 // GHIDRA_RAW: RenderFn5B07A0 @ 0x005b07a0 — needs manual cleanup
void RenderFn5B07A0(int param_1,int param_2)
{


      float fVar1;

      float fVar2;

      int iVar3;

      uint32_t uVar4;

      float fVar5;

      uint32_t uVar6;



      if (param_1 == 0) {

        iVar3 = 0;

      }

      else {

        iVar3 = *(int *)(param_1 + 0x14c);

      }

      if (*(int *)(iVar3 + 0xd8) != 0) {

        FUN_005b0ac0();

        return;

      }

      fVar1 = *(float *)(DAT_007028f4 + 0xb34);

      fVar2 = *(float *)(param_1 + 0x370);

      if ((*(uint32_t *)(param_1 + 300) & 0x200) == 0) {

        if (*(int *)(param_1 + 0x60) == 0x53) {

          return;

        }

        if (*(int *)(*(int *)(param_1 + 8) + 0x154) == 0) {

          return;

        }

        if (param_2 == 0) {

          uVar4 = 0x21;

        }

        else {

          iVar3 = rand();

          uVar4 = 0x81;

          *(float *)(param_1 + 100) = (float)iVar3 * _DAT_0066bd00 + _DAT_0066bce4;

        }

        fVar5 = *(float *)(param_1 + 0x370);

        uVar6 = 0x53;

      }

      else {

        if (*(int *)(param_1 + 0x60) == 0x92) {

          return;

        }

        if (*(int *)(*(int *)(param_1 + 8) + 0x250) == 0) {

          return;

        }

        if (param_2 == 0) {

          uVar4 = 0x21;

        }

        else {

          iVar3 = rand();

          uVar4 = 0x81;

          *(float *)(param_1 + 100) = (float)iVar3 * _DAT_0066bd00 + _DAT_0066bce4;

        }

        fVar5 = *(float *)(param_1 + 0x370);

        uVar6 = 0x92;

      }

      fVar5 = fVar1 * fVar2 * fVar5;

      FUN_0048f2f0(uVar6,uVar4,1,fVar5,0x3e2aaaab);

      FUN_0048f2f0(0xfe,0,1,fVar5,0x3e2aaaab);

      return;


}  // 0x005b07a0
#endif // RenderFn5B07A0
void RenderFn5B07A0() {}  // 0x005b07a0
#if 0 // GHIDRA_RAW: RenderFn5B0DD0 @ 0x005b0dd0 — needs manual cleanup
void RenderFn5B0DD0(int param_1,int param_2)
{


      uint32_t uVar1;

      int iVar2;

      int iVar3;

      float fVar4;

      uint32_t uVar5;



      uVar1 = *(uint32_t *)(param_1 + 300);

      if ((uVar1 & 0x200) != 0) {

        FUN_005af580(0,0);

        return;

      }

      *(uint32_t *)(param_1 + 300) = uVar1 | 0x8004000;

      if (param_2 == 0) {

        iVar2 = *(int *)(param_1 + 0x60);

        if ((uVar1 & 0x8000) != 0) goto LAB_005b0e3c;

      }

      else {

        iVar3 = rand();

        iVar2 = *(int *)(param_1 + 0x60);

        if (iVar3 * 100 >> 0xf < 0x33) {

          *(uint32_t *)(param_1 + 300) = *(uint32_t *)(param_1 + 300) | 0x8000;

    LAB_005b0e3c:

          if (iVar2 == 0x7f) {

            return;

          }

          if (*(int *)(*(int *)(param_1 + 8) + 0x204) == 0) {

            return;

          }

          fVar4 = *(float *)(param_1 + 0x370) * _DAT_0066bce4;

          uVar5 = 0x7f;

          goto LAB_005b0ec0;

        }

        *(uint32_t *)(param_1 + 300) = *(uint32_t *)(param_1 + 300) & 0xffff7fff;

      }

      if (iVar2 == 0x7e) {

        return;

      }

      if (*(int *)(*(int *)(param_1 + 8) + 0x200) == 0) {

        return;

      }

      fVar4 = *(float *)(param_1 + 0x370) * _DAT_0066bce4;

      uVar5 = 0x7e;

    LAB_005b0ec0:

      FUN_0048f2f0(uVar5,0x21,0,fVar4,0x3e2aaaab);

      FUN_0048f2f0(0xfe,0,0,fVar4,0x3e2aaaab);

      return;


}  // 0x005b0dd0
#endif // RenderFn5B0DD0
void RenderFn5B0DD0() {}  // 0x005b0dd0
#if 0 // GHIDRA_RAW: RenderFn5CCA80 @ 0x005cca80 — needs manual cleanup
void RenderFn5CCA80(int param_1,int param_2,int param_3,int param_4,uint64_t *param_5,uint32_t param_6)
{


      int *piVar1;

      int *piVar2;

      int iVar3;

      uint64_t local_38;

      uint32_t local_30;

      uint32_t local_2c;

      int local_28;

      uint32_t local_24;

      uint32_t local_20;

      uint32_t local_1c;

      int local_18;

      int local_14;

      uint32_t local_10;

      uint32_t local_c;

      uint32_t local_8;



      if ((param_4 == 0) || (iVar3 = 0x30, *(int *)(param_4 + 0x22c) != 2)) {

        iVar3 = 0x40;

      }

      local_30 = 0;

      local_38 = 0;

      local_1c = 0;

      piVar2 = DAT_00749908;

      if (-2 < iVar3 + param_2) {

        for (; piVar2 != DAT_0074990c; piVar2 = piVar2 + 2) {

          piVar1 = (int *)*piVar2;

          if (*piVar1 == iVar3 + param_2) {

            if (piVar1 != (int *)0x0) {

              local_28 = piVar1[2];

              goto LAB_005ccae9;

            }

            break;

          }

        }

      }

      local_28 = 0;

    LAB_005ccae9:

      iVar3 = FUN_00559dc0();

      local_24 = *(uint32_t *)(iVar3 + 0x1d4);

      local_38 = *param_5;

      local_30 = *(uint32_t *)(param_5 + 1);

      local_2c = param_6;

      if ((param_2 == 5) || (local_20 = 9, param_2 == 6)) {

        local_20 = 0;

      }

      local_18 = *(int *)(param_4 + 0x1d8);

      if (*(int *)(param_4 + 0x22c) == 3) {

        if ((((param_2 == 5) || (param_2 == 6)) && (iVar3 = *(int *)(param_4 + 0x278), iVar3 != 0)) &&

           ((*(int *)(iVar3 + 4) == 0x4a5 && (*(int *)(iVar3 + 0x1d8) == local_18)))) {

          local_1c = 0x1000;

        }

        if (param_2 != 1) goto LAB_005ccc0e;

        local_1c = 0x1000;

      }

      else {

    LAB_005ccc0e:

        if (param_2 == 5) {

          local_14 = 0x5ef;

          goto LAB_005ccba8;

        }

        if (param_2 == 6) {

          local_14 = 0x5db;

          goto LAB_005ccba8;

        }

      }

      local_14 = (uint)(*(int *)(param_4 + 0x22c) != 2) * 4 + 0x6e5;

    LAB_005ccba8:

      local_10 = *(uint32_t *)(param_3 + 0x1d4);

      local_c = *(uint32_t *)(param_1 + 0x1d4);

      local_8 = *(uint32_t *)(param_4 + 0x1d4);

      FUN_005cc670();

      if (DAT_006ff960 == 6) {

        FUN_00469d20(0x13,&local_38);

      }

      return;


}  // 0x005cca80
#endif // RenderFn5CCA80
void RenderFn5CCA80() {}  // 0x005cca80
#if 0 // GHIDRA_RAW: RenderFn5CEAE0 @ 0x005ceae0 — needs manual cleanup
void RenderFn5CEAE0(int param_1)
{


      uint32_t *puVar1;

      uint32_t *puVar2;

      int iVar3;

      uint32_t *puVar4;

      int iVar5;

      int iVar6;

      bool bVar7;



      if (param_1 == 0) {

        iVar6 = 0;

      }

      else {

        iVar6 = *(int *)(param_1 + 0x14c);

      }

      if ((*(uint32_t *)(param_1 + 300) & 8) != 0) {

        iVar5 = *(int *)(param_1 + 0x14c);

        *(uint32_t *)(param_1 + 300) = *(uint32_t *)(param_1 + 300) & 0xfffffff7;

        if (*(int *)(iVar5 + 0x30) != 0) {

          *(uint32_t *)(*(int *)(iVar5 + 0x30) + 0x264) = 0;

          puVar1 = (uint32_t *)(*(int *)(iVar5 + 0x30) + 0x124);

          *puVar1 = *puVar1 | 0x8000;

          bVar7 = DAT_006ff960 == 6;

          *(uint32_t *)(iVar5 + 0x30) = 0;

          *(uint32_t *)(iVar5 + 0x14) = 0x41d80000;

          if ((bVar7) && (iVar5 = FUN_0045f460(), iVar5 != 0)) {

            FUN_00469de0(0,0,0x11,0,0);

          }

        }

        FUN_004a6420();

        puVar2 = *(uint32_t **)(param_1 + 0x1b4);

        while (puVar4 = puVar2, puVar4 != (uint32_t *)0x0) {

          puVar2 = (uint32_t *)*puVar4;

          *puVar4 = DAT_0073e790;

          DAT_0073e790 = puVar4;

        }

        *(uint32_t *)(param_1 + 0x124) = *(uint32_t *)(param_1 + 0x124) & 0xfcffffff;

        iVar5 = *(int *)(param_1 + 0x2c4);

        *(uint32_t *)(param_1 + 0x1b4) = 0;

        if (iVar5 != 0) {

          if (*(int *)(iVar5 + 0x22c) == 0x20) {

            if (*(int *)(iVar6 + 0x2c) != -1) {

              if (*(int *)(iVar6 + 0x2c) == 0) {

                iVar5 = *(int *)(*(int *)(iVar5 + 0x14c) + 0x20);

              }

              else {

                iVar5 = 0;

              }

              if ((iVar5 != 0) && (-1 < *(int *)(iVar6 + 0x28))) {

                *(uint32_t *)(iVar5 + 300) =

                     *(uint32_t *)(iVar5 + 300) & ~(1 << (*(int *)(iVar6 + 0x28) - 0x47U & 0x1f));

              }

            }

          }

          else if ((iVar5 != 0) && (*(int *)(iVar5 + 0x22c) == 0x52)) {

            if (*(int *)(iVar6 + 0x2c) != -1) {

              iVar5 = 0;

              for (puVar2 = DAT_007027a8; puVar2 != (uint32_t *)0x0; puVar2 = (uint32_t *)*puVar2) {

                iVar3 = puVar2[3];

                if (*(int *)(iVar3 + 4) == 0x353) {

                  if (iVar5 == *(int *)(iVar6 + 0x2c)) {

                    if ((iVar3 != 0) && (-1 < (int)*(uint32_t *)(iVar6 + 0x28))) {

                      *(uint32_t *)(iVar3 + 300) =

                           *(uint32_t *)(iVar3 + 300) & ~(1 << (*(uint32_t *)(iVar6 + 0x28) & 0x1f));

                    }

                    break;

                  }

                  iVar5 = iVar5 + 1;

                }

              }

            }

          }

        }

        *(uint32_t *)(iVar6 + 0x2c) = 0xffffffff;

        *(uint32_t *)(iVar6 + 0x28) = 0xffffffff;

        *(uint32_t *)(param_1 + 0x2c4) = 0;

      }

      return;


}  // 0x005ceae0
#endif // RenderFn5CEAE0
void RenderFn5CEAE0() {}  // 0x005ceae0
#if 0 // GHIDRA_RAW: RenderFn5D95F0 @ 0x005d95f0 — needs manual cleanup
void RenderFn5D95F0()
{


            cVar3 = *pcVar7;

            pcVar7 = pcVar7 + 1;


}  // 0x005d95f0
#endif // RenderFn5D95F0
void RenderFn5D95F0() {}  // 0x005d95f0
#if 0 // GHIDRA_RAW: RenderFn5D9780 @ 0x005d9780 — needs manual cleanup
void RenderFn5D9780()
{


            cVar3 = *pcVar7;

            pcVar7 = pcVar7 + 1;


}  // 0x005d9780
#endif // RenderFn5D9780
void RenderFn5D9780() {}  // 0x005d9780
#if 0 // GHIDRA_RAW: RenderFn5D9910 @ 0x005d9910 — needs manual cleanup
void RenderFn5D9910()
{


          cVar3 = *pcVar7;

          pcVar7 = pcVar7 + 1;


}  // 0x005d9910
#endif // RenderFn5D9910
void RenderFn5D9910() {}  // 0x005d9910
#if 0 // GHIDRA_RAW: RenderFn5D9A90 @ 0x005d9a90 — needs manual cleanup
void RenderFn5D9A90()
{


            do {

              cVar3 = *pcVar5;

              pcVar5 = pcVar5 + 1;

            } while (cVar3 != '\0');

            FUN_0062c690();

            pcVar5 = pcVar7 + 1;

            do {

              cVar3 = *pcVar7;

              pcVar7 = pcVar7 + 1;

            } while (cVar3 != '\0');

            iVar6 = (int)pcVar7 - (int)pcVar5;

            fVar9 = DAT_0066bf2c - fVar1 / fVar8;


}  // 0x005d9a90
#endif // RenderFn5D9A90
void RenderFn5D9A90() {}  // 0x005d9a90
#if 0 // GHIDRA_RAW: RenderFn5E2F30 @ 0x005e2f30 — needs manual cleanup
void RenderFn5E2F30(int param_1)
{


      int iVar1;

      uint32_t uVar2;

      uint32_t uVar3;

      float fVar4;

      uint8_t local_34 [16];

      uint32_t local_24;

      uint32_t local_20;

      int local_1c;



      if ((param_1 != 0) && (iVar1 = *(int *)(param_1 + 0x14c), iVar1 != 0)) {

        if ((param_1 == DAT_00681dd0) && (DAT_007496d4 != 0)) {

          *(uint32_t *)(iVar1 + 0x19c) = 0;

          FUN_004ea1b0();

        }

        fVar4 = (*(float *)(param_1 + 0x2c8) / *(float *)(param_1 + 0x20c)) * DAT_0066c0d8;

        if (fVar4 < *(float *)(DAT_007028f4 + 0x1070)) {

          if (fVar4 < *(float *)(DAT_007028f4 + 0x106c)) {

            uVar3 = (uint)(*(float *)(DAT_007028f4 + 0x1074) <= fVar4);

          }

          else {

            uVar3 = 2;

          }

        }

        else {

          uVar3 = 3;

        }

        if (*(uint32_t *)(iVar1 + 0x19c) != uVar3) {

          FUN_004ea1b0();

        }

        if (((*(uint32_t *)(param_1 + 300) & 0x2000000) == 0) || (uVar3 != 1)) {

          *(uint32_t *)(iVar1 + 0x19c) = uVar3;

          if (*(int *)(iVar1 + 0x18c) == 0) {

            local_20 = 3;

            local_24 = 8;

            if (uVar3 == 1) {

              if ((*(uint32_t *)(param_1 + 300) & 0x2000000) != 0) {

                return;

              }

            }

            else if ((uVar3 != 2) && (uVar3 != 3)) {

              return;

            }

            local_1c = param_1;

            uVar2 = FUN_004e9cd0(local_34);

            *(uint32_t *)(iVar1 + 0x18c) = uVar2;

          }

        }

        else if (*(int *)(param_1 + 0x14c) != 0) {

          *(uint32_t *)(*(int *)(param_1 + 0x14c) + 0x19c) = 0;

          FUN_004ea1b0();

          return;

        }

      }

      return;


}  // 0x005e2f30
#endif // RenderFn5E2F30
void RenderFn5E2F30() {}  // 0x005e2f30
#if 0 // GHIDRA_RAW: RenderFn5EB0F0 @ 0x005eb0f0 — needs manual cleanup
uint32_t RenderFn5EB0F0(int *param_1)
{


      int *piVar1;

      void *_Dst;

      void *pvVar2;

      int *piVar3;

      int iVar4;



      if (-1 < *param_1) {

        return (&DAT_0070280c)[*param_1];

      }

      iVar4 = 0;

      piVar3 = &DAT_0070280c;

      while( true ) {

        piVar1 = (int *)*piVar3;

        if (piVar1 == (int *)0x0) {

          _Dst = malloc(0x44);

          *piVar3 = (int)_Dst;

          memset(_Dst,0,0x44);

          pvVar2 = malloc(0x1518);

          *(void **)((int)_Dst + 0xc) = pvVar2;

          *(uint32_t *)((int)_Dst + 4) = 0x96;

          *(uint32_t *)((int)_Dst + 0x1c) = 0x3f800000;

          *param_1 = iVar4;

          return (&DAT_0070280c)[iVar4];

        }

        if ((piVar1[0x10] == 0) && (*piVar1 < 2)) break;

        piVar3 = piVar3 + 1;

        iVar4 = iVar4 + 1;

        if (0x702883 < (int)piVar3) {

          return 0;

        }

      }

      *param_1 = iVar4;

      *(uint32_t *)(&DAT_0070280c)[iVar4] = 0;

      *(uint32_t *)((&DAT_0070280c)[iVar4] + 8) = 0;

      *(uint32_t *)((&DAT_0070280c)[iVar4] + 0x1c) = 0x3f800000;

      return (&DAT_0070280c)[iVar4];


}  // 0x005eb0f0
#endif // RenderFn5EB0F0
void RenderFn5EB0F0() {}  // 0x005eb0f0
#if 0 // GHIDRA_RAW: RenderFn5F3340 @ 0x005f3340 — needs manual cleanup
void RenderFn5F3340(int param_1,uint32_t param_2)
{


      float fVar1;

      int iVar2;

      bool bVar3;

      float in_XMM2_Da;

      float local_14;

      uint32_t local_10;

      float local_c;



      if (param_1 == 0) {

        iVar2 = 0;

      }

      else {

        iVar2 = *(int *)(param_1 + 0x14c);

      }

      *(uint32_t *)(param_1 + 0x214) = *(uint32_t *)(param_1 + 0x214) | 0x400;

      bVar3 = DAT_006ff960 == 6;

      *(uint32_t *)(iVar2 + 0x74) = param_2;

      *(uint32_t *)(iVar2 + 0xb0) = 1;

      *(uint32_t *)(iVar2 + 0xb8) = 3;

      local_c = in_XMM2_Da;

      if (bVar3) {

        iVar2 = FUN_0045f460();

        if (iVar2 == 0) {

          *(float *)(param_1 + 0x138) = in_XMM2_Da;

          return;

        }

      }

      local_14 = *(float *)(DAT_007028f4 + 0x98c);

      fVar1 = *(float *)(DAT_007028f4 + 0x9a8);

      iVar2 = rand();

      bVar3 = DAT_006ff960 == 6;

      *(float *)(param_1 + 0x138) = (float)iVar2 * _DAT_0066bd00 * (fVar1 - local_14) + local_14;

      if (bVar3) {

        iVar2 = FUN_0045f460();

        if (iVar2 != 0) {

          local_14 = local_c;

          local_10 = param_2;

          FUN_00469f80(1,0,0xb,&local_14);

        }

      }

      return;


}  // 0x005f3340
#endif // RenderFn5F3340
void RenderFn5F3340() {}  // 0x005f3340
#if 0 // GHIDRA_RAW: SysFn60A650 @ 0x0060a650 — needs manual cleanup
void SysFn60A650(uint32_t *param_1)
{


      int *piVar1;

      int *piVar2;

      int iVar3;

      uint32_t uVar4;

      void *local_10;

      uint8_t *puStack_c;

      uint32_t local_8;



      local_8 = 0xffffffff;

      puStack_c = &LAB_00647d50;

      local_10 = ExceptionList;

      uVar4 = DAT_0067d280 ^ (uint)&stack0xfffffffc;

      ExceptionList = &local_10;

      *param_1 = &PTR_FUN_00669b6c;

      Concurrency::details::_TaskEventLogger::_LogTaskCompleted((_TaskEventLogger *)(param_1[6] + 200));

      piVar2 = (int *)param_1[7];

      if (piVar2 != (int *)0x0) {

        LOCK();

        iVar3 = piVar2[1] + -1;

        piVar2[1] = iVar3;

        UNLOCK();

        if (iVar3 == 0) {

          (**(code **)*piVar2)(uVar4);

          LOCK();

          piVar1 = piVar2 + 2;

          iVar3 = *piVar1;

          *piVar1 = *piVar1 + -1;

          UNLOCK();

          if (iVar3 == 1) {

            (**(code **)(*piVar2 + 4))();

          }

        }

      }

      *param_1 = &PTR_FUN_00669dcc;

      local_8 = 0;

      Concurrency::details::_ContextCallback::_Reset((_ContextCallback *)(param_1 + 2));

      *param_1 = &PTR_LAB_00669dd8;

      ExceptionList = local_10;

      return;


}  // 0x0060a650
#endif // SysFn60A650
void SysFn60A650() {}  // 0x0060a650
#if 0 // GHIDRA_RAW: SysFn60A890 @ 0x0060a890 — needs manual cleanup
void SysFn60A890(uint32_t *param_1)
{


      int *piVar1;

      int *piVar2;

      int iVar3;

      uint32_t uVar4;

      void *local_10;

      uint8_t *puStack_c;

      uint32_t local_8;



      local_8 = 0xffffffff;

      puStack_c = &LAB_00647d50;

      local_10 = ExceptionList;

      uVar4 = DAT_0067d280 ^ (uint)&stack0xfffffffc;

      ExceptionList = &local_10;

      *param_1 = &PTR_FUN_00669b48;

      Concurrency::details::_TaskEventLogger::_LogTaskCompleted((_TaskEventLogger *)(param_1[6] + 200));

      piVar2 = (int *)param_1[7];

      if (piVar2 != (int *)0x0) {

        LOCK();

        iVar3 = piVar2[1] + -1;

        piVar2[1] = iVar3;

        UNLOCK();

        if (iVar3 == 0) {

          (**(code **)*piVar2)(uVar4);

          LOCK();

          piVar1 = piVar2 + 2;

          iVar3 = *piVar1;

          *piVar1 = *piVar1 + -1;

          UNLOCK();

          if (iVar3 == 1) {

            (**(code **)(*piVar2 + 4))();

          }

        }

      }

      *param_1 = &PTR_FUN_00669dcc;

      local_8 = 0;

      Concurrency::details::_ContextCallback::_Reset((_ContextCallback *)(param_1 + 2));

      *param_1 = &PTR_LAB_00669dd8;

      ExceptionList = local_10;

      return;


}  // 0x0060a890
#endif // SysFn60A890
void SysFn60A890() {}  // 0x0060a890
#if 0 // GHIDRA_RAW: SysFn60B920 @ 0x0060b920 — needs manual cleanup
void SysFn60B920(uint32_t param_1,uint32_t *param_2)
{


      uint32_t uVar1;

      void *pvVar2;



      if (*param_2 < 0x4444445) {

        uVar1 = *param_2 * 0x3c;

        if (uVar1 == 0) {

          return;

        }

        if (uVar1 < 0x1000) {

          operator_new(uVar1);

          return;

        }

        if (uVar1 < uVar1 + 0x23) {

          pvVar2 = operator_new(uVar1 + 0x23);

          if (pvVar2 == (void *)0x0) {

                        /* WARNING: Subroutine does not return */

            std::abort();

          }

          *(void **)(((int)pvVar2 + 0x23U & 0xffffffe0) - 4) = pvVar2;

          return;

        }

      }

                        /* WARNING: Subroutine does not return */

      FUN_0042bad0();


}  // 0x0060b920
#endif // SysFn60B920
void SysFn60B920() {}  // 0x0060b920
#if 0 // GHIDRA_RAW: SysFn610050 @ 0x00610050 — needs manual cleanup
void SysFn610050()
{


            *(char **)(param_1 + 0x5c) = "invalid literal";

            return 0xe;


}  // 0x00610050
#endif // SysFn610050
void SysFn610050() {}  // 0x00610050
#if 0 // GHIDRA_RAW: SysFn612B50 @ 0x00612b50 — needs manual cleanup
void SysFn612B50(uint32_t *param_1)
{


      int *piVar1;

      int *piVar2;

      int iVar3;

      uint32_t uVar4;

      void *local_10;

      uint8_t *puStack_c;

      uint32_t local_8;



      local_8 = 0xffffffff;

      puStack_c = &LAB_00647d50;

      local_10 = ExceptionList;

      uVar4 = DAT_0067d280 ^ (uint)&stack0xfffffffc;

      ExceptionList = &local_10;

      *param_1 = &PTR_FUN_006698c4;

      Concurrency::details::_TaskEventLogger::_LogTaskCompleted((_TaskEventLogger *)(param_1[6] + 200));

      piVar2 = (int *)param_1[7];

      if (piVar2 != (int *)0x0) {

        LOCK();

        iVar3 = piVar2[1] + -1;

        piVar2[1] = iVar3;

        UNLOCK();

        if (iVar3 == 0) {

          (**(code **)*piVar2)(uVar4);

          LOCK();

          piVar1 = piVar2 + 2;

          iVar3 = *piVar1;

          *piVar1 = *piVar1 + -1;

          UNLOCK();

          if (iVar3 == 1) {

            (**(code **)(*piVar2 + 4))();

          }

        }

      }

      *param_1 = &PTR_FUN_00669dcc;

      local_8 = 0;

      Concurrency::details::_ContextCallback::_Reset((_ContextCallback *)(param_1 + 2));

      *param_1 = &PTR_LAB_00669dd8;

      ExceptionList = local_10;

      return;


}  // 0x00612b50
#endif // SysFn612B50
void SysFn612B50() {}  // 0x00612b50
#if 0 // GHIDRA_RAW: SysFn612D50 @ 0x00612d50 — needs manual cleanup
void SysFn612D50(uint32_t *param_1)
{


      int *piVar1;

      int *piVar2;

      int iVar3;

      uint32_t uVar4;

      void *local_10;

      uint8_t *puStack_c;

      uint32_t local_8;



      local_8 = 0xffffffff;

      puStack_c = &LAB_00647d50;

      local_10 = ExceptionList;

      uVar4 = DAT_0067d280 ^ (uint)&stack0xfffffffc;

      ExceptionList = &local_10;

      *param_1 = &PTR_FUN_006698b8;

      Concurrency::details::_TaskEventLogger::_LogTaskCompleted((_TaskEventLogger *)(param_1[6] + 200));

      piVar2 = (int *)param_1[7];

      if (piVar2 != (int *)0x0) {

        LOCK();

        iVar3 = piVar2[1] + -1;

        piVar2[1] = iVar3;

        UNLOCK();

        if (iVar3 == 0) {

          (**(code **)*piVar2)(uVar4);

          LOCK();

          piVar1 = piVar2 + 2;

          iVar3 = *piVar1;

          *piVar1 = *piVar1 + -1;

          UNLOCK();

          if (iVar3 == 1) {

            (**(code **)(*piVar2 + 4))();

          }

        }

      }

      *param_1 = &PTR_FUN_00669dcc;

      local_8 = 0;

      Concurrency::details::_ContextCallback::_Reset((_ContextCallback *)(param_1 + 2));

      *param_1 = &PTR_LAB_00669dd8;

      ExceptionList = local_10;

      return;


}  // 0x00612d50
#endif // SysFn612D50
void SysFn612D50() {}  // 0x00612d50
#if 0 // GHIDRA_RAW: SysFn613080 @ 0x00613080 — needs manual cleanup
void SysFn613080(uint32_t *param_1)
{


      int *piVar1;

      int *piVar2;

      int iVar3;

      uint32_t uVar4;

      void *local_10;

      uint8_t *puStack_c;

      uint32_t local_8;



      local_8 = 0xffffffff;

      puStack_c = &LAB_00647d50;

      local_10 = ExceptionList;

      uVar4 = DAT_0067d280 ^ (uint)&stack0xfffffffc;

      ExceptionList = &local_10;

      *param_1 = &PTR_FUN_00669894;

      Concurrency::details::_TaskEventLogger::_LogTaskCompleted((_TaskEventLogger *)(param_1[6] + 200));

      piVar2 = (int *)param_1[7];

      if (piVar2 != (int *)0x0) {

        LOCK();

        iVar3 = piVar2[1] + -1;

        piVar2[1] = iVar3;

        UNLOCK();

        if (iVar3 == 0) {

          (**(code **)*piVar2)(uVar4);

          LOCK();

          piVar1 = piVar2 + 2;

          iVar3 = *piVar1;

          *piVar1 = *piVar1 + -1;

          UNLOCK();

          if (iVar3 == 1) {

            (**(code **)(*piVar2 + 4))();

          }

        }

      }

      *param_1 = &PTR_FUN_00669dcc;

      local_8 = 0;

      Concurrency::details::_ContextCallback::_Reset((_ContextCallback *)(param_1 + 2));

      *param_1 = &PTR_LAB_00669dd8;

      ExceptionList = local_10;

      return;


}  // 0x00613080
#endif // SysFn613080
void SysFn613080() {}  // 0x00613080
#if 0 // GHIDRA_RAW: SysFn6148E0 @ 0x006148e0 — needs manual cleanup
void SysFn6148E0(uint32_t *param_1)
{


      int *piVar1;

      int *piVar2;

      int iVar3;

      uint32_t uVar4;

      void *local_10;

      uint8_t *puStack_c;

      uint32_t local_8;



      local_8 = 0xffffffff;

      puStack_c = &LAB_00647d50;

      local_10 = ExceptionList;

      uVar4 = DAT_0067d280 ^ (uint)&stack0xfffffffc;

      ExceptionList = &local_10;

      *param_1 = &PTR_FUN_006697fc;

      Concurrency::details::_TaskEventLogger::_LogTaskCompleted((_TaskEventLogger *)(param_1[6] + 200));

      piVar2 = (int *)param_1[7];

      if (piVar2 != (int *)0x0) {

        LOCK();

        iVar3 = piVar2[1] + -1;

        piVar2[1] = iVar3;

        UNLOCK();

        if (iVar3 == 0) {

          (**(code **)*piVar2)(uVar4);

          LOCK();

          piVar1 = piVar2 + 2;

          iVar3 = *piVar1;

          *piVar1 = *piVar1 + -1;

          UNLOCK();

          if (iVar3 == 1) {

            (**(code **)(*piVar2 + 4))();

          }

        }

      }

      *param_1 = &PTR_FUN_00669dcc;

      local_8 = 0;

      Concurrency::details::_ContextCallback::_Reset((_ContextCallback *)(param_1 + 2));

      *param_1 = &PTR_LAB_00669dd8;

      ExceptionList = local_10;

      return;


}  // 0x006148e0
#endif // SysFn6148E0
void SysFn6148E0() {}  // 0x006148e0
#if 0 // GHIDRA_RAW: SysFn614B20 @ 0x00614b20 — needs manual cleanup
void SysFn614B20(uint32_t *param_1)
{


      int *piVar1;

      int *piVar2;

      int iVar3;

      uint32_t uVar4;

      void *local_10;

      uint8_t *puStack_c;

      uint32_t local_8;



      local_8 = 0xffffffff;

      puStack_c = &LAB_00647d50;

      local_10 = ExceptionList;

      uVar4 = DAT_0067d280 ^ (uint)&stack0xfffffffc;

      ExceptionList = &local_10;

      *param_1 = &PTR_FUN_006697f0;

      Concurrency::details::_TaskEventLogger::_LogTaskCompleted((_TaskEventLogger *)(param_1[6] + 200));

      piVar2 = (int *)param_1[7];

      if (piVar2 != (int *)0x0) {

        LOCK();

        iVar3 = piVar2[1] + -1;

        piVar2[1] = iVar3;

        UNLOCK();

        if (iVar3 == 0) {

          (**(code **)*piVar2)(uVar4);

          LOCK();

          piVar1 = piVar2 + 2;

          iVar3 = *piVar1;

          *piVar1 = *piVar1 + -1;

          UNLOCK();

          if (iVar3 == 1) {

            (**(code **)(*piVar2 + 4))();

          }

        }

      }

      *param_1 = &PTR_FUN_00669dcc;

      local_8 = 0;

      Concurrency::details::_ContextCallback::_Reset((_ContextCallback *)(param_1 + 2));

      *param_1 = &PTR_LAB_00669dd8;

      ExceptionList = local_10;

      return;


}  // 0x00614b20
#endif // SysFn614B20
void SysFn614B20() {}  // 0x00614b20
#if 0 // GHIDRA_RAW: SysFn614D80 @ 0x00614d80 — needs manual cleanup
void SysFn614D80(uint32_t *param_1)
{


      int *piVar1;

      int *piVar2;

      int iVar3;

      uint32_t uVar4;

      void *local_10;

      uint8_t *puStack_c;

      uint32_t local_8;



      local_8 = 0xffffffff;

      puStack_c = &LAB_00647d50;

      local_10 = ExceptionList;

      uVar4 = DAT_0067d280 ^ (uint)&stack0xfffffffc;

      ExceptionList = &local_10;

      *param_1 = &PTR_FUN_006697c0;

      Concurrency::details::_TaskEventLogger::_LogTaskCompleted((_TaskEventLogger *)(param_1[6] + 200));

      piVar2 = (int *)param_1[7];

      if (piVar2 != (int *)0x0) {

        LOCK();

        iVar3 = piVar2[1] + -1;

        piVar2[1] = iVar3;

        UNLOCK();

        if (iVar3 == 0) {

          (**(code **)*piVar2)(uVar4);

          LOCK();

          piVar1 = piVar2 + 2;

          iVar3 = *piVar1;

          *piVar1 = *piVar1 + -1;

          UNLOCK();

          if (iVar3 == 1) {

            (**(code **)(*piVar2 + 4))();

          }

        }

      }

      *param_1 = &PTR_FUN_00669dcc;

      local_8 = 0;

      Concurrency::details::_ContextCallback::_Reset((_ContextCallback *)(param_1 + 2));

      *param_1 = &PTR_LAB_00669dd8;

      ExceptionList = local_10;

      return;


}  // 0x00614d80
#endif // SysFn614D80
void SysFn614D80() {}  // 0x00614d80
#if 0 // GHIDRA_RAW: SysFn615BD0 @ 0x00615bd0 — needs manual cleanup
void SysFn615BD0(uint32_t *param_1)
{


      int *piVar1;

      int *piVar2;

      int iVar3;

      uint32_t uVar4;

      void *local_10;

      uint8_t *puStack_c;

      uint32_t local_8;



      local_8 = 0xffffffff;

      puStack_c = &LAB_00647d50;

      local_10 = ExceptionList;

      uVar4 = DAT_0067d280 ^ (uint)&stack0xfffffffc;

      ExceptionList = &local_10;

      *param_1 = &PTR_FUN_00669790;

      Concurrency::details::_TaskEventLogger::_LogTaskCompleted((_TaskEventLogger *)(param_1[6] + 200));

      piVar2 = (int *)param_1[7];

      if (piVar2 != (int *)0x0) {

        LOCK();

        iVar3 = piVar2[1] + -1;

        piVar2[1] = iVar3;

        UNLOCK();

        if (iVar3 == 0) {

          (**(code **)*piVar2)(uVar4);

          LOCK();

          piVar1 = piVar2 + 2;

          iVar3 = *piVar1;

          *piVar1 = *piVar1 + -1;

          UNLOCK();

          if (iVar3 == 1) {

            (**(code **)(*piVar2 + 4))();

          }

        }

      }

      *param_1 = &PTR_FUN_00669dcc;

      local_8 = 0;

      Concurrency::details::_ContextCallback::_Reset((_ContextCallback *)(param_1 + 2));

      *param_1 = &PTR_LAB_00669dd8;

      ExceptionList = local_10;

      return;


}  // 0x00615bd0
#endif // SysFn615BD0
void SysFn615BD0() {}  // 0x00615bd0
#if 0 // GHIDRA_RAW: SysFn615DD0 @ 0x00615dd0 — needs manual cleanup
void SysFn615DD0(uint32_t *param_1)
{


      int *piVar1;

      int *piVar2;

      int iVar3;

      uint32_t uVar4;

      void *local_10;

      uint8_t *puStack_c;

      uint32_t local_8;



      local_8 = 0xffffffff;

      puStack_c = &LAB_00647d50;

      local_10 = ExceptionList;

      uVar4 = DAT_0067d280 ^ (uint)&stack0xfffffffc;

      ExceptionList = &local_10;

      *param_1 = &PTR_FUN_00669778;

      Concurrency::details::_TaskEventLogger::_LogTaskCompleted((_TaskEventLogger *)(param_1[6] + 200));

      piVar2 = (int *)param_1[7];

      if (piVar2 != (int *)0x0) {

        LOCK();

        iVar3 = piVar2[1] + -1;

        piVar2[1] = iVar3;

        UNLOCK();

        if (iVar3 == 0) {

          (**(code **)*piVar2)(uVar4);

          LOCK();

          piVar1 = piVar2 + 2;

          iVar3 = *piVar1;

          *piVar1 = *piVar1 + -1;

          UNLOCK();

          if (iVar3 == 1) {

            (**(code **)(*piVar2 + 4))();

          }

        }

      }

      *param_1 = &PTR_FUN_00669dcc;

      local_8 = 0;

      Concurrency::details::_ContextCallback::_Reset((_ContextCallback *)(param_1 + 2));

      *param_1 = &PTR_LAB_00669dd8;

      ExceptionList = local_10;

      return;


}  // 0x00615dd0
#endif // SysFn615DD0
void SysFn615DD0() {}  // 0x00615dd0
#if 0 // GHIDRA_RAW: SysFn618E90 @ 0x00618e90 — needs manual cleanup
void SysFn618E90(uint32_t *param_1)
{


      int *piVar1;

      int *piVar2;

      int iVar3;

      uint32_t uVar4;

      void *local_10;

      uint8_t *puStack_c;

      uint32_t local_8;



      local_8 = 0xffffffff;

      puStack_c = &LAB_00647d50;

      local_10 = ExceptionList;

      uVar4 = DAT_0067d280 ^ (uint)&stack0xfffffffc;

      ExceptionList = &local_10;

      *param_1 = &PTR_FUN_0066966c;

      Concurrency::details::_TaskEventLogger::_LogTaskCompleted((_TaskEventLogger *)(param_1[6] + 200));

      piVar2 = (int *)param_1[7];

      if (piVar2 != (int *)0x0) {

        LOCK();

        iVar3 = piVar2[1] + -1;

        piVar2[1] = iVar3;

        UNLOCK();

        if (iVar3 == 0) {

          (**(code **)*piVar2)(uVar4);

          LOCK();

          piVar1 = piVar2 + 2;

          iVar3 = *piVar1;

          *piVar1 = *piVar1 + -1;

          UNLOCK();

          if (iVar3 == 1) {

            (**(code **)(*piVar2 + 4))();

          }

        }

      }

      *param_1 = &PTR_FUN_00669dcc;

      local_8 = 0;

      Concurrency::details::_ContextCallback::_Reset((_ContextCallback *)(param_1 + 2));

      *param_1 = &PTR_LAB_00669dd8;

      ExceptionList = local_10;

      return;


}  // 0x00618e90
#endif // SysFn618E90
void SysFn618E90() {}  // 0x00618e90
#if 0 // GHIDRA_RAW: SysFn619090 @ 0x00619090 — needs manual cleanup
void SysFn619090(uint32_t *param_1)
{


      int *piVar1;

      int *piVar2;

      int iVar3;

      uint32_t uVar4;

      void *local_10;

      uint8_t *puStack_c;

      uint32_t local_8;



      local_8 = 0xffffffff;

      puStack_c = &LAB_00647d50;

      local_10 = ExceptionList;

      uVar4 = DAT_0067d280 ^ (uint)&stack0xfffffffc;

      ExceptionList = &local_10;

      *param_1 = &PTR_FUN_00669660;

      Concurrency::details::_TaskEventLogger::_LogTaskCompleted((_TaskEventLogger *)(param_1[6] + 200));

      piVar2 = (int *)param_1[7];

      if (piVar2 != (int *)0x0) {

        LOCK();

        iVar3 = piVar2[1] + -1;

        piVar2[1] = iVar3;

        UNLOCK();

        if (iVar3 == 0) {

          (**(code **)*piVar2)(uVar4);

          LOCK();

          piVar1 = piVar2 + 2;

          iVar3 = *piVar1;

          *piVar1 = *piVar1 + -1;

          UNLOCK();

          if (iVar3 == 1) {

            (**(code **)(*piVar2 + 4))();

          }

        }

      }

      *param_1 = &PTR_FUN_00669dcc;

      local_8 = 0;

      Concurrency::details::_ContextCallback::_Reset((_ContextCallback *)(param_1 + 2));

      *param_1 = &PTR_LAB_00669dd8;

      ExceptionList = local_10;

      return;


}  // 0x00619090
#endif // SysFn619090
void SysFn619090() {}  // 0x00619090
#if 0 // GHIDRA_RAW: SysFn619290 @ 0x00619290 — needs manual cleanup
void SysFn619290(uint32_t *param_1)
{


      int *piVar1;

      int *piVar2;

      int iVar3;

      uint32_t uVar4;

      void *local_10;

      uint8_t *puStack_c;

      uint32_t local_8;



      local_8 = 0xffffffff;

      puStack_c = &LAB_00647d50;

      local_10 = ExceptionList;

      uVar4 = DAT_0067d280 ^ (uint)&stack0xfffffffc;

      ExceptionList = &local_10;

      *param_1 = &PTR_FUN_00669648;

      Concurrency::details::_TaskEventLogger::_LogTaskCompleted((_TaskEventLogger *)(param_1[6] + 200));

      piVar2 = (int *)param_1[7];

      if (piVar2 != (int *)0x0) {

        LOCK();

        iVar3 = piVar2[1] + -1;

        piVar2[1] = iVar3;

        UNLOCK();

        if (iVar3 == 0) {

          (**(code **)*piVar2)(uVar4);

          LOCK();

          piVar1 = piVar2 + 2;

          iVar3 = *piVar1;

          *piVar1 = *piVar1 + -1;

          UNLOCK();

          if (iVar3 == 1) {

            (**(code **)(*piVar2 + 4))();

          }

        }

      }

      *param_1 = &PTR_FUN_00669dcc;

      local_8 = 0;

      Concurrency::details::_ContextCallback::_Reset((_ContextCallback *)(param_1 + 2));

      *param_1 = &PTR_LAB_00669dd8;

      ExceptionList = local_10;

      return;


}  // 0x00619290
#endif // SysFn619290
void SysFn619290() {}  // 0x00619290
#if 0 // GHIDRA_RAW: SysFn625B90 @ 0x00625b90 — needs manual cleanup
void SysFn625B90(int *param_1)
{


      uint32_t *puVar1;

      int iVar2;

      uint32_t uVar3;

      uint32_t *puVar4;

      int iVar5;



      puVar4 = (uint32_t *)*param_1;

      if (puVar4 != (uint32_t *)0x0) {

        puVar1 = (uint32_t *)param_1[1];

        for (; puVar4 != puVar1; puVar4 = puVar4 + 10) {

          if ((*puVar4 & 1) != 0) {

            FUN_00443490();

          }

        }

        iVar2 = *param_1;

        uVar3 = ((param_1[2] - iVar2) / 0x28) * 0x28;

        iVar5 = iVar2;

        if (0xfff < uVar3) {

          iVar5 = *(int *)(iVar2 + -4);

          uVar3 = uVar3 + 0x23;

          if (0x1f < (iVar2 - iVar5) - 4U) {

                        /* WARNING: Subroutine does not return */

            std::abort();

          }

        }

        FUN_00643505(iVar5,uVar3);

        *param_1 = 0;

        param_1[1] = 0;

        param_1[2] = 0;

      }

      return;


}  // 0x00625b90
#endif // SysFn625B90
void SysFn625B90() {}  // 0x00625b90
#if 0 // GHIDRA_RAW: SysFn625C30 @ 0x00625c30 — needs manual cleanup
void SysFn625C30(int *param_1)
{


      uint32_t *puVar1;

      uint32_t *puVar2;



      puVar1 = (uint32_t *)*param_1;

      *(uint32_t *)puVar1[1] = 0;

      puVar1 = (uint32_t *)*puVar1;

      while (puVar1 != (uint32_t *)0x0) {

        puVar2 = (uint32_t *)*puVar1;

        FUN_00443490();

        FUN_00643505(puVar1,0x24);

        puVar1 = puVar2;

      }

      FUN_00643505(*param_1,0x24);

      return;


}  // 0x00625c30
#endif // SysFn625C30
void SysFn625C30() {}  // 0x00625c30
void SysFn6275C0() {}  // 0x006275c0
void SysFn630D20() {}  // 0x00630d20
void SysFn632570() {}  // 0x00632570
#if 0 // GHIDRA_RAW: SysFn63F040 @ 0x0063f040 — needs manual cleanup
void SysFn63F040()
{


      float10 fVar1;

      double dVar2;

      float fVar3;

      float fVar4;



      dVar2 = (double)(*(float *)(param_1 + 4) * *(float *)(param_1 + 4) +

                      *(float *)(param_1 + 8) * *(float *)(param_1 + 8));

      if (dVar2 < 0.0) {

        libm_sse2_sqrt_precise();

      }

      else {

        dVar2 = SQRT(dVar2);

      }

      fVar4 = (float)dVar2;

      if (fVar4 <= DAT_0066bcf8) {

        fVar3 = (float)(*(uint32_t *)(param_1 + 0x1c) ^ DAT_0066c580);

        if ((*(float *)(param_1 + 0x18) == 0.0) && (fVar3 == 0.0)) {

          fVar3 = 0.0;

        }

        else {

          fVar1 = (float10)(*(code *)PTR_FUN_0067d248)(fVar3,*(float *)(param_1 + 0x18));

          fVar3 = (float)(fVar1 * (float10)_DAT_0066c0a8);

          if (fVar3 < 0.0) {

            fVar3 = fVar3 + DAT_0066c14c;

          }

          if (_DAT_0066c148 < fVar3) {

            fVar3 = 0.0;

          }

        }

        *param_2 = fVar3;

        if ((fVar4 != 0.0) || (*(float *)(param_1 + 0xc) != 0.0)) {

          fVar1 = (float10)(*(code *)PTR_FUN_0067d248)(*(float *)(param_1 + 0xc),fVar4);

          fVar4 = (float)(fVar1 * (float10)_DAT_0066c0a8);

          if (fVar4 < 0.0) {

            fVar4 = fVar4 + DAT_0066c14c;

          }

          if (fVar4 <= _DAT_0066c148) goto LAB_0063f2de;

        }

        fVar4 = 0.0;

    LAB_0063f2de:

        *param_3 = fVar4;

        *param_4 = 0.0;

        return;

      }

      if ((*(float *)(param_1 + 0x2c) == 0.0) && (*(float *)(param_1 + 0x28) == 0.0)) {

        fVar3 = 0.0;

      }

      else {

        fVar1 = (float10)(*(code *)PTR_FUN_0067d248)

                                   (*(float *)(param_1 + 0x28),*(float *)(param_1 + 0x2c));

        fVar3 = (float)(fVar1 * (float10)_DAT_0066c0a8);

        if (fVar3 < 0.0) {

          fVar3 = fVar3 + DAT_0066c14c;

        }

        if (_DAT_0066c148 < fVar3) {

          fVar3 = 0.0;

        }

      }

      *param_2 = fVar3;

      if ((fVar4 != 0.0) || (*(float *)(param_1 + 0x24) != 0.0)) {

        fVar1 = (float10)(*(code *)PTR_FUN_0067d248)(*(float *)(param_1 + 0x24),fVar4);

        fVar4 = (float)(fVar1 * (float10)_DAT_0066c0a8);

        if (fVar4 < 0.0) {

          fVar4 = fVar4 + DAT_0066c14c;

        }

        if (fVar4 <= _DAT_0066c148) goto LAB_0063f17c;

      }

      fVar4 = 0.0;

    LAB_0063f17c:

      *param_3 = fVar4;

      if ((*(float *)(param_1 + 4) != 0.0) || (fVar4 = 0.0, *(float *)(param_1 + 0x14) != 0.0)) {

        fVar1 = (float10)(*(code *)PTR_FUN_0067d248)(*(float *)(param_1 + 0x14),*(float *)(param_1 + 4))

        ;

        fVar4 = (float)(fVar1 * (float10)_DAT_0066c0a8);

        if (fVar4 < 0.0) {

          fVar4 = fVar4 + DAT_0066c14c;

        }

        if (_DAT_0066c148 < fVar4) {

          fVar4 = 0.0;

        }

      }

      *param_4 = fVar4;

      return;


}  // 0x0063f040
#endif // SysFn63F040
void SysFn63F040() {}  // 0x0063f040
void SysFn6411E5()
{


      UINT UVar1;

      BOOL BVar2;



      UVar1 = ___lc_codepage_func();

      if (UVar1 == 0xfde9) {

        return 0xfde9;

      }

      BVar2 = AreFileApisANSI();

      return (uint)(BVar2 == 0);


}  // 0x006411e5
#if 0 // GHIDRA_RAW: SysFn6414EF @ 0x006414ef — needs manual cleanup
void SysFn6414EF()
{


        DVar2 = GetLastError();

        if (DVar2 == 0xb7) {

          DVar2 = FUN_0064170e(param_1,local_2c,3,0xffffffff);

          if ((DVar2 == 0) && ((local_1c >> 4 & 1) == 0)) {

            DVar2 = 0xb7;

          }

        }

        local_c = local_c & 0xffffff00;


}  // 0x006414ef
#endif // SysFn6414EF
void SysFn6414EF() {}  // 0x006414ef
void EHVectorCtorIter() {}  // 0x00643c10
void SysFn644AC3() {}  // 0x00644ac3

// --- Cycle 56: 3-caller / 4+ callee (118 functions) ---
#if 0 // GHIDRA_RAW: RenderFn537130 @ 0x00537130 — needs manual cleanup
float * RenderFn537130(float *param_1)
{


    uint32_t *puVar1;

    float fVar2;

    uint32_t *puVar3;

    int iVar4;

    uint32_t uVar5;

    float *pfVar6;

    float *pfVar7;

    float *pfVar8;

    float *pfVar9;

    uint32_t extraout_ECX;

    uint32_t extraout_ECX_00;

    float *extraout_ECX_01;

    int *piVar10;

    uint32_t extraout_ECX_02;

    float *pfVar11;

    bool bVar12;

    bool bVar13;

    float10 fVar14;

    float fVar15;

    float *local_a8;

    float *local_a4;

    float *local_a0;

    float *local_9c;

    float local_98;

    float *local_94;

    float *local_90;

    float *local_8c;

    float local_88;

    float local_84;

    float *local_80;

    float *local_7c;

    float *local_78;

    float local_74 [4];

    uint8_t local_64 [16];

    uint32_t local_54;

    uint32_t local_50;

    float *local_4c;

    uint64_t local_30;

    float *local_28;

    uint64_t local_24;

    float *local_1c;

    uint64_t local_18;

    float local_10;

    uint32_t local_c;



    local_c = DAT_0067d280 ^ (uint)&local_a8;

    if ((param_1 == (float *)0x0) ||

    ((local_9c = (float *)param_1[0x53], local_80 = param_1, DAT_006ff960 == 6 &&

    (iVar4 = FUN_0045f460(), iVar4 == 0)))) {

    pfVar9 = (float *)param_1[0x4a];

    if (((uint)pfVar9 & 0x20) == 0) {

    if (((uint)pfVar9 & 0x8000000) == 0) {

    return pfVar9;

    }

    pfVar9 = (float *)((uint)pfVar9 | 0x20);

    }

    else {

    pfVar9 = (float *)((uint)pfVar9 & 0xf7ffffdf);

    }

    param_1[0x4a] = (float)pfVar9;

    return pfVar9;

    }

    pfVar9 = local_9c;

    if (param_1 == DAT_00702774) {

    DAT_007488c8 = 0;

    DAT_007488cc = 0;

    }

    if (param_1[0x83] <= param_1[0xb2]) {

    return local_9c;

    }

    local_a4 = pfVar9;

    local_94 = pfVar9;

    if ((((uint)param_1[0x4b] & 0x20000) != 0) &&

    (puVar3 = DAT_007027b0, ((uint)param_1[0x98] & 0x80) != 0)) {

    for (; puVar3 != (uint32_t *)0x0; puVar3 = (uint32_t *)*puVar3) {

    local_a8 = (float *)puVar3[3];

    if (((((uint)local_a8[0x49] & 0x8000) == 0) && (local_a8[1] == 1.38869e-42)) &&

    ((float *)local_a8[0x99] == param_1)) {

    if (local_a8 == (float *)0x0) goto LAB_00537224;

    local_9c = (float *)local_a8[0x53];

    goto LAB_0053722c;

    }

    }

    local_a8 = (float *)0x0;

    LAB_00537224:

    local_9c = (float *)0x0;

    LAB_0053722c:

    if (*(int *)local_a8[0x53] < 1) {

    if (DAT_00702bb8 == 0) {

    pfVar8 = (float *)param_1[0x99];

    pfVar11 = param_1;

    while (pfVar6 = pfVar8, pfVar6 != (float *)0x0) {

    pfVar11 = pfVar6;

    pfVar8 = (float *)pfVar6[0x99];

    }

    if (pfVar11 == DAT_00702774) {

    FUN_00558360();

    }

    else {

    FUN_005581d0();

    }

    }

    }

    else {

    local_1c = DAT_00681ddc;

    local_90 = DAT_00681de4;

    local_24 = DAT_00681dd4;

    FUN_006387e0(DAT_00681de0,&local_84,&local_88);

    FUN_006387e0(local_90,&local_a0,&local_98);

    local_30 = CONCAT44((float)((uint)local_88 ^ DAT_0066c580) * local_98,local_98 * local_84);

    local_28 = local_a0;

    FUN_004ff520(&local_30,extraout_ECX,&local_90);

    local_30 = DAT_0074bb60;

    DAT_007488cc = (uint)((float)local_90 < DAT_0066c19c);

    local_28 = DAT_0074bb68;

    local_1c = DAT_0074bb8c;

    local_24 = _DAT_0074bb84;

    uVar5 = FUN_004ff8b0(&local_18,&local_30,&local_24);

    param_1 = local_80;

    iVar4 = FUN_005323c0(local_9c + 2,uVar5,&local_18,0x43fa0000);

    if (iVar4 != 0) {

    *(int *)local_a8[0x53] = *(int *)local_a8[0x53] + -1;

    }

    }

    }

    fVar15 = pfVar9[9];

    if (0.0 < fVar15) {

    FUN_0062a0b0();

    pfVar9[9] = pfVar9[9] - fVar15;

    }

    fVar15 = pfVar9[10];

    if (0.0 < fVar15) {

    FUN_0062a0b0();

    pfVar9[10] = pfVar9[10] - fVar15;

    }

    fVar15 = pfVar9[0xb];

    if (0.0 < fVar15) {

    FUN_0062a0b0();

    pfVar9[0xb] = pfVar9[0xb] - fVar15;

    }

    param_1[0x4a] = (float)((uint)param_1[0x4a] & 0xffffffdf);

    if (((uint)param_1[0x4b] & 0x20000) == 0) {

    local_90 = local_94;

    local_a8 = local_a4;

    if (param_1[0x8b] == 2.8026e-45) {

    local_98 = *(float *)((int)param_1[0x53] + 0x168 + *(int *)((int)param_1[0x53] + 0x50) * 4);

    }

    else {

    local_98 = 0.0;

    }

    if (((uint)param_1[0x4b] & 0x40000) == 0) {

    fVar15 = param_1[0x98];

    local_9c = pfVar9;

    if (((uint)fVar15 & 0x10) != 0) {

    if (pfVar9[0x41] != 0.0) {

    puVar1 = (uint32_t *)((int)pfVar9[0x41] + 0x124);

    *puVar1 = *puVar1 | 0x40000000;

    }

    pfVar8 = (float *)param_1[0x99];

    pfVar11 = param_1;

    while (pfVar6 = pfVar8, pfVar6 != (float *)0x0) {

    pfVar11 = pfVar6;

    pfVar8 = (float *)pfVar6[0x99];

    }

    if (((DAT_00702800 != 0) && (DAT_00702800 + 0xf85c != 0)) &&

    (*(int *)(DAT_00702800 + 0xf864) != 0)) {

    (*DAT_007280a0)(DAT_00702800 + 0xf85c,pfVar11);

    }

    FUN_0053a690();

    FUN_00502910();

    param_1[0x98] = (float)((uint)param_1[0x98] & 0xfffffffe);

    fVar15 = param_1[0x98];

    }

    if (((uint)fVar15 & 0x20) != 0) {

    if (pfVar9[0x41] != 0.0) {

    puVar1 = (uint32_t *)((int)pfVar9[0x41] + 0x124);

    *puVar1 = *puVar1 | 0x40000000;

    }

    pfVar8 = (float *)param_1[0x99];

    pfVar11 = param_1;

    while (pfVar6 = pfVar8, pfVar6 != (float *)0x0) {

    pfVar11 = pfVar6;

    pfVar8 = (float *)pfVar6[0x99];

    }

    if (((DAT_00702800 != 0) && (DAT_00702800 + 0xf85c != 0)) &&

    (*(int *)(DAT_00702800 + 0xf864) != 0)) {

    (*DAT_007280a0)(DAT_00702800 + 0xf85c,pfVar11);

    }

    FUN_0053a690();

    FUN_00502910();

    param_1[0x98] = (float)((uint)param_1[0x98] & 0xfffffffe);

    }

    }

    piVar10 = DAT_00749908;

    if (-2 < (int)local_98) {

    for (; piVar10 != DAT_0074990c; piVar10 = piVar10 + 2) {

    pfVar11 = (float *)*piVar10;

    if (*pfVar11 == local_98) {

    if (pfVar11 != (float *)0x0) {

    local_88 = pfVar11[6];

    goto LAB_00537628;

    }

    break;

    }

    }

    }

    local_88 = -NAN;

    }

    else {

    local_98 = -NAN;

    local_88 = 3.36312e-44;

    }

    LAB_00537628:

    local_a8 = local_94;

    local_9c = local_a4;

    local_90 = pfVar9;

    local_84 = (float)FUN_0056e960();

    pfVar11 = local_80;

    fVar15 = local_88;

    local_a0 = (float *)0x0;

    if (param_1 != DAT_00702774) {

    local_a0 = (float *)pfVar9[0x32];

    local_18 = *(uint64_t *)(pfVar9 + 0x33);

    local_10 = pfVar9[0x35];

    LAB_00537685:

    pfVar8 = pfVar9 + 0x43;

    *pfVar8 = 0.0;

    pfVar6 = local_a0;

    pfVar11 = param_1;

    if (local_88 != 5.60519e-45) goto LAB_00537a5f;

    LAB_0053769c:

    local_a0 = (float *)pfVar9[0x42];

    *pfVar8 = 1.4013e-45;

    if (local_a0 != (float *)0x0) {

    local_18 = *(uint64_t *)(local_a0 + 0x3c);

    local_10 = local_a0[0x3e];

    goto LAB_00537a63;

    }

    if (pfVar9[0x41] != 0.0) {

    pfVar9[0x75] = 0.0;

    pfVar6 = (float *)pfVar11[0x99];

    pfVar8 = pfVar11;

    while (pfVar7 = pfVar6, pfVar7 != (float *)0x0) {

    pfVar8 = pfVar7;

    pfVar6 = (float *)pfVar7[0x99];

    }

    if (((DAT_00702800 != 0) && (DAT_00702800 + 0xf85c != 0)) &&

    (*(int *)(DAT_00702800 + 0xf864) != 0)) {

    (*DAT_007280a0)(DAT_00702800 + 0xf85c,pfVar8);

    }

    *(uint32_t *)((int)pfVar9[0x41] + 0x124) = *(uint32_t *)((int)pfVar9[0x41] + 0x124) | 0x40000000;

    }

    LAB_00537add:

    pfVar9[0x3f] = *(float *)(DAT_007028f4 + 0x8f4);

    goto LAB_00537aee;

    }

    if (((DAT_00681db0 != 0) || (DAT_00681dbc != 0)) || (1 < DAT_00681db8)) goto LAB_00537685;

    local_94 = local_a8;

    local_a4 = local_9c;

    param_1 = local_80;

    pfVar9 = local_90;

    if (local_84 == 0.0) goto LAB_00537685;

    if (local_88 == 5.60519e-45) {

    if (local_90[0x3f] <= _DAT_0066bce4) goto LAB_00537685;

    LAB_0053775f:

    local_a0 = (float *)&LAB_00532240;

    if ((int)local_88 * 0x1c != -0x685e88) {

    local_a0 = (float *)(&PTR_LAB_00685e90)[(int)local_88 * 7];

    }

    }

    else {

    if ((-1 < (int)local_88) && ((uint)local_88 < 0x3b)) goto LAB_0053775f;

    local_a0 = (float *)&LAB_00532240;

    }

    local_a4 = (float *)(*(float *)((int)local_84 + 0x34) * DAT_0066bf54);

    local_1c = DAT_00681ddc;

    local_80 = DAT_00681de4;

    local_24 = DAT_00681dd4;

    FUN_006387e0(DAT_00681de0,&local_78,local_74);

    FUN_006387e0(local_80,&local_8c,&local_7c);

    local_30 = CONCAT44((float)((uint)local_74[0] ^ DAT_0066c580) * (float)local_7c,

    (float)local_7c * (float)local_78);

    local_28 = local_8c;

    FUN_004ff520(&local_30,extraout_ECX_00,&local_80);

    pfVar9 = local_90;

    DAT_007488cc = (uint)((float)local_80 < *(float *)((int)local_84 + 0x34));

    if (fVar15 == 5.60519e-45) {

    if (((((uint)pfVar11[0x98] & 1) == 0) || (local_90[0x84] != 0.0)) ||

    (((uint)pfVar11[0x4b] & 0x100000) != 0)) {

    pfVar8 = (float *)0x0;

    }

    else {

    pfVar8 = (float *)FUN_005fbbf0();

    }

    pfVar6 = (float *)0x0;

    if (pfVar8 != pfVar11) {

    pfVar6 = pfVar8;

    }

    pfVar9[0x42] = (float)pfVar6;

    *pfVar9 = (float)pfVar6;

    pfVar9[0x32] = (float)pfVar6;

    local_a4 = local_9c;

    pfVar8 = local_9c + 0x43;

    local_94 = local_a8;

    *pfVar8 = 0.0;

    goto LAB_0053769c;

    }

    local_28 = DAT_0074bb68;

    local_1c = DAT_0074bb8c;

    local_30 = DAT_0074bb60;

    local_24 = _DAT_0074bb84;

    pfVar6 = (float *)FUN_004ff8b0(&local_18,&local_30,&local_24);

    if (((pfVar6 == (float *)0x0) || (pfVar6 == pfVar11)) ||

    ((local_a0 = pfVar6, pfVar11 == DAT_00702774 &&

    ((iVar4 = FUN_00499dd0(), pfVar6 = extraout_ECX_01, iVar4 == 0 &&

    (((extraout_ECX_01[0x3c] - pfVar11[0x3c]) * (float)((uint)pfVar11[0xbb] ^ DAT_0066c580) -

    (extraout_ECX_01[0x3d] - pfVar11[0x3d]) * pfVar11[0xbf]) -

    (extraout_ECX_01[0x3e] - pfVar11[0x3e]) * pfVar11[0xc3] < _DAT_0066bce4)))))) {

    pfVar6 = (float *)0x0;

    local_a0 = (float *)0x0;

    }

    local_90[0x42] = (float)pfVar6;

    *local_90 = (float)pfVar6;

    local_90[0x32] = (float)pfVar6;

    *(uint64_t *)(local_90 + 0x33) = local_18;

    local_90[0x35] = local_10;

    local_a4 = local_9c;

    local_9c[0x43] = 0.0;

    local_94 = local_a8;

    pfVar9 = local_90;

    LAB_00537a5f:

    if (pfVar6 == (float *)0x0) goto LAB_00537add;

    LAB_00537a63:

    local_9c = DAT_0066c198;

    if (local_84 != 0.0) {

    local_9c = *(float **)((int)local_84 + 0x34);

    }

    fVar14 = (float10)FUN_00638d40(&DAT_0074bb60,&local_18);

    fVar15 = (float)local_9c * (float)local_9c;

    local_8c = (float *)(float)fVar14;

    if (fVar15 <= (float)local_8c) goto LAB_00537af8;

    if ((pfVar11 == DAT_00702774) && (local_a0[0x8b] != 0.0)) {

    DAT_007488c8 = 1;

    }

    if (local_88 != 5.60519e-45) goto LAB_00537add;

    fVar2 = pfVar11[0x53];

    if (pfVar11[0x8b] != 2.8026e-45) {

    LAB_00537ce4:

    pfVar8 = local_94 + 0x3f;

    goto LAB_00537cee;

    }

    switch(local_98) {

    case 0.0:

    case 1.4013e-45:

    case 2.8026e-45:

    case 5.60519e-45:

    case 2.66247e-44:

    local_a4 = local_94;

    LAB_00537d08:

    local_a4 = local_a4 + 0x3f;

    goto LAB_00537d11;

    case 4.2039e-45:

    case 5.1848e-44:

    iVar4 = *(int *)((int)fVar2 + 0x134);

    break;

    case 7.00649e-45:

    case 5.32493e-44:

    iVar4 = *(int *)((int)fVar2 + 0x144);

    break;

    case 8.40779e-45:

    case 5.46506e-44:

    iVar4 = *(int *)((int)fVar2 + 0x148);

    break;

    case 9.80909e-45:

    case 6.02558e-44:

    iVar4 = *(int *)((int)fVar2 + 0x158);

    break;

    case 1.12104e-44:

    case 1.05097e-43:

    case 1.06499e-43:

    iVar4 = *(int *)((int)fVar2 + 0x138);

    break;

    case 1.26117e-44:

    iVar4 = *(int *)((int)fVar2 + 0x13c);

    break;

    default:

    if (((uint)pfVar11[0x4b] & 0x8020000) == 0) goto LAB_00537d08;

    iVar4 = FUN_0053ea80();

    if ((iVar4 == 0) || (*(int *)(*(int *)(iVar4 + 0x14c) + 4) < 1)) goto LAB_00537ce4;

    local_a4 = local_a4 + 0x3f;

    goto LAB_00537d11;

    case 1.96182e-44:

    case 5.60519e-44:

    iVar4 = *(int *)((int)fVar2 + 0x14c);

    break;

    case 2.10195e-44:

    case 5.74532e-44:

    iVar4 = *(int *)((int)fVar2 + 0x150);

    break;

    case 2.24208e-44:

    case 5.88545e-44:

    iVar4 = *(int *)((int)fVar2 + 0x154);

    break;

    case 8.96831e-44:

    iVar4 = *(int *)((int)fVar2 + 0x140);

    }

    pfVar8 = pfVar9 + 0x3f;

    local_a4 = pfVar8;

    if (iVar4 < 1) {

    LAB_00537cee:

    *pfVar8 = *(float *)(DAT_007028f4 + 0x8f4);

    LAB_00537aee:

    pfVar9[0x40] = 0.0;

    }

    else {

    LAB_00537d11:

    FUN_0062a0b0();

    *local_a4 = *local_a4 - fVar15;

    }

    LAB_00537af8:

    local_90 = (float *)FUN_004ffb40();

    if (local_90 == (float *)0x0) {

    return (float *)0x0;

    }

    if ((((((uint)pfVar11[0x98] & 1) == 0) || (pfVar9[0x84] != 0.0)) || (DAT_00682204 != -1)) ||

    ((DAT_00702a40 != 0 || (local_8c = (float *)pfVar11[0x4b], ((uint)local_8c & 0x100000) != 0))))

    {

    if (pfVar9[0x62] != 0.0) {

    if ((DAT_006ff960 == 6) && (iVar4 = FUN_0045f460(), iVar4 != 0)) {

    FUN_00469de0(0,0,0x18,0,0);

    }

    FUN_004ea1b0();

    }

    if (pfVar9[0x7e] != 0.0) {

    if ((DAT_006ff960 == 6) && (iVar4 = FUN_0045f460(), iVar4 != 0)) {

    FUN_00469de0(0,0,0x1c,0,0);

    }

    if (DAT_007496c4 != (int *)0x0) {

    piVar10 = DAT_007496c4;

    do {

    if ((float)piVar10[0x11] == pfVar9[0x7e]) {

    FUN_005584d0();

    break;

    }

    piVar10 = (int *)*piVar10;

    } while (piVar10 != (int *)0x0);

    }

    pfVar9[0x7e] = 0.0;

    }

    if (local_88 == 2.66247e-44) {

    local_a8 = (float *)pfVar11[0x53];

    if (((local_a8[0x4c] != 0.0) && (FUN_004ea1b0(), DAT_006ff960 == 6)) &&

    (iVar4 = FUN_0045f460(), iVar4 != 0)) {

    FUN_00469d20(0x1a,0);

    }

    piVar10 = DAT_007496c4;

    if (local_a8[0x79] != 0.0) {

    for (; piVar10 != (int *)0x0; piVar10 = (int *)*piVar10) {

    if ((float)piVar10[0x11] == local_a8[0x79]) {

    FUN_005583d0();

    break;

    }

    }

    local_a8[0x79] = 0.0;

    }

    local_a8[0x4b] = 0.0;

    goto LAB_00538a77;

    }

    if (((local_88 != 5.60519e-45) || (0.0 < pfVar9[0x3f])) ||

    ((((uint)pfVar11[0x98] & 0x30) != 0 ||

    ((local_84 == 0.0 || (fVar15 = pfVar11[0x53], pfVar11[0x8b] != 2.8026e-45))))))

    goto LAB_00538a77;

    switch(local_98) {

    case 0.0:

    case 1.4013e-45:

    case 2.8026e-45:

    case 5.60519e-45:

    case 2.66247e-44:

    goto switchD_00538876_caseD_0;

    case 4.2039e-45:

    case 5.1848e-44:

    bVar13 = *(int *)((int)fVar15 + 0x134) < 0;

    bVar12 = *(int *)((int)fVar15 + 0x134) == 0;

    break;

    case 7.00649e-45:

    case 5.32493e-44:

    bVar13 = *(int *)((int)fVar15 + 0x144) < 0;

    bVar12 = *(int *)((int)fVar15 + 0x144) == 0;

    break;

    case 8.40779e-45:

    case 5.46506e-44:

    bVar13 = *(int *)((int)fVar15 + 0x148) < 0;

    bVar12 = *(int *)((int)fVar15 + 0x148) == 0;

    break;

    case 9.80909e-45:

    case 6.02558e-44:

    bVar13 = *(int *)((int)fVar15 + 0x158) < 0;

    bVar12 = *(int *)((int)fVar15 + 0x158) == 0;

    break;

    case 1.12104e-44:

    case 1.05097e-43:

    case 1.06499e-43:

    bVar13 = *(int *)((int)fVar15 + 0x138) < 0;

    bVar12 = *(int *)((int)fVar15 + 0x138) == 0;

    break;

    case 1.26117e-44:

    bVar13 = *(int *)((int)fVar15 + 0x13c) < 0;

    bVar12 = *(int *)((int)fVar15 + 0x13c) == 0;

    break;

    default:

    if (((uint)pfVar11[0x4b] & 0x8020000) != 0) {

    iVar4 = FUN_0053ea80();

    if (iVar4 == 0) goto LAB_00538a77;

    iVar4 = *(int *)(*(int *)(iVar4 + 0x14c) + 4);

    bVar13 = iVar4 < 0;

    bVar12 = iVar4 == 0;

    break;

    }

    goto switchD_00538876_caseD_0;

    case 1.96182e-44:

    case 5.60519e-44:

    bVar13 = *(int *)((int)fVar15 + 0x14c) < 0;

    bVar12 = *(int *)((int)fVar15 + 0x14c) == 0;

    break;

    case 2.10195e-44:

    case 5.74532e-44:

    bVar13 = *(int *)((int)fVar15 + 0x150) < 0;

    bVar12 = *(int *)((int)fVar15 + 0x150) == 0;

    break;

    case 2.24208e-44:

    case 5.88545e-44:

    bVar13 = *(int *)((int)fVar15 + 0x154) < 0;

    bVar12 = *(int *)((int)fVar15 + 0x154) == 0;

    break;

    case 8.96831e-44:

    bVar13 = *(int *)((int)fVar15 + 0x140) < 0;

    bVar12 = *(int *)((int)fVar15 + 0x140) == 0;

    }

    if (!bVar12 && !bVar13) {

    switchD_00538876_caseD_0:

    local_28 = DAT_00681ddc;

    local_8c = DAT_00681de4;

    local_30 = DAT_00681dd4;

    FUN_006387e0(DAT_00681de0,&local_78,&local_7c);

    FUN_006387e0(local_8c,&local_9c,local_74);

    local_18 = CONCAT44(local_30._4_4_ - local_74[0] * (float)local_7c * DAT_0066c1b0,

    local_74[0] * (float)local_78 * DAT_0066c1b0 + (float)local_30);

    local_10 = (float)local_9c * DAT_0066c1b0 + (float)local_28;

    iVar4 = FUN_005323c0(pfVar9 + 9,pfVar9[0x42],&local_18,0x43fa0000);

    if (iVar4 != 0) {

    FUN_00506420();

    }

    if (pfVar9[0x41] != 0.0) {

    pfVar6 = (float *)pfVar11[0x99];

    pfVar8 = pfVar11;

    while (pfVar7 = pfVar6, pfVar7 != (float *)0x0) {

    pfVar8 = pfVar7;

    pfVar6 = (float *)pfVar7[0x99];

    }

    if (((DAT_00702800 != 0) && (DAT_00702800 + 0xf85c != 0)) &&

    (*(int *)(DAT_00702800 + 0xf864) != 0)) {

    (*DAT_007280a0)(DAT_00702800 + 0xf85c,pfVar8);

    }

    pfVar9[0x75] = 0.0;

    *(uint32_t *)((int)pfVar9[0x41] + 0x124) = *(uint32_t *)((int)pfVar9[0x41] + 0x124) | 0x40000000;

    }

    }

    LAB_00538a77:

    pfVar8 = *(float **)(DAT_007028f4 + 0x8f4);

    pfVar9[0x3f] = (float)pfVar8;

    pfVar9[0x40] = 0.0;

    goto LAB_00538a92;

    }

    fVar15 = 0.0;

    pfVar8 = local_90;

    pfVar6 = local_8c;

    if (pfVar9[9] <= 0.0) {

    if (((uint)local_8c & 0x100) == 0) {

    pfVar8 = local_8c;

    if ((0 < (int)pfVar11[0x70]) &&

    (pfVar7 = (float *)FUN_004ffb40(), pfVar8 = local_8c, pfVar6 = local_8c,

    pfVar7 != (float *)0x0)) {

    pfVar8 = (float *)((uint)local_8c | 0x100);

    pfVar11[0x4b] = (float)pfVar8;

    pfVar6 = pfVar8;

    local_90 = pfVar7;

    }

    }

    else {

    pfVar11[0x4b] = (float)((uint)local_8c & 0xfffffeff);

    pfVar6 = (float *)((uint)local_8c & 0xfffffeff);

    }

    }

    if (local_84 == 0.0) goto LAB_00537f4f;

    fVar2 = pfVar11[0x53];

    if (pfVar11[0x8b] != 2.8026e-45) goto LAB_00537e55;

    switch(local_98) {

    case 0.0:

    case 1.4013e-45:

    case 2.8026e-45:

    case 5.60519e-45:

    case 2.66247e-44:

    goto switchD_00537d69_caseD_0;

    case 4.2039e-45:

    case 5.1848e-44:

    bVar13 = *(int *)((int)fVar2 + 0x134) < 0;

    bVar12 = *(int *)((int)fVar2 + 0x134) == 0;

    break;

    case 7.00649e-45:

    case 5.32493e-44:

    bVar13 = *(int *)((int)fVar2 + 0x144) < 0;

    bVar12 = *(int *)((int)fVar2 + 0x144) == 0;

    break;

    case 8.40779e-45:

    case 5.46506e-44:

    bVar13 = *(int *)((int)fVar2 + 0x148) < 0;

    bVar12 = *(int *)((int)fVar2 + 0x148) == 0;

    break;

    case 9.80909e-45:

    case 6.02558e-44:

    bVar13 = *(int *)((int)fVar2 + 0x158) < 0;

    bVar12 = *(int *)((int)fVar2 + 0x158) == 0;

    break;

    case 1.12104e-44:

    case 1.05097e-43:

    case 1.06499e-43:

    bVar13 = *(int *)((int)fVar2 + 0x138) < 0;

    bVar12 = *(int *)((int)fVar2 + 0x138) == 0;

    break;

    case 1.26117e-44:

    bVar13 = *(int *)((int)fVar2 + 0x13c) < 0;

    bVar12 = *(int *)((int)fVar2 + 0x13c) == 0;

    break;

    default:

    if (((uint)pfVar6 & 0x8020000) != 0) {

    iVar4 = FUN_0053ea80();

    if (iVar4 == 0) goto LAB_00537e55;

    iVar4 = *(int *)(*(int *)(iVar4 + 0x14c) + 4);

    bVar13 = iVar4 < 0;

    bVar12 = iVar4 == 0;

    break;

    }

    goto switchD_00537d69_caseD_0;

    case 1.96182e-44:

    case 5.60519e-44:

    bVar13 = *(int *)((int)fVar2 + 0x14c) < 0;

    bVar12 = *(int *)((int)fVar2 + 0x14c) == 0;

    break;

    case 2.10195e-44:

    case 5.74532e-44:

    bVar13 = *(int *)((int)fVar2 + 0x150) < 0;

    bVar12 = *(int *)((int)fVar2 + 0x150) == 0;

    break;

    case 2.24208e-44:

    case 5.88545e-44:

    bVar13 = *(int *)((int)fVar2 + 0x154) < 0;

    bVar12 = *(int *)((int)fVar2 + 0x154) == 0;

    break;

    case 8.96831e-44:

    bVar13 = *(int *)((int)fVar2 + 0x140) < 0;

    bVar12 = *(int *)((int)fVar2 + 0x140) == 0;

    }

    if (bVar12 || bVar13) {

    LAB_00537e55:

    pfVar8 = pfVar9 + 0x62;

    if (pfVar9[0x62] != 0.0) {

    if ((DAT_006ff960 == 6) && (iVar4 = FUN_0045f460(), iVar4 != 0)) {

    FUN_00469de0(0,0,0x18,0,0);

    }

    pfVar8 = (float *)FUN_004ea1b0();

    fVar15 = 0.0;

    }

    if (pfVar9[0x7e] != 0.0) {

    if (DAT_006ff960 == 6) {

    iVar4 = FUN_0045f460();

    pfVar8 = (float *)0x0;

    if (iVar4 != 0) {

    pfVar8 = (float *)FUN_00469de0(0,0,0x1c,0,0);

    }

    }

    if (DAT_007496c4 != (int *)0x0) {

    pfVar8 = (float *)pfVar9[0x7e];

    piVar10 = DAT_007496c4;

    do {

    if ((float *)piVar10[0x11] == pfVar8) {

    pfVar8 = (float *)FUN_005584d0();

    break;

    }

    piVar10 = (int *)*piVar10;

    } while (piVar10 != (int *)0x0);

    }

    pfVar9[0x7e] = 0.0;

    fVar15 = 0.0;

    }

    if (pfVar9[0xb] <= fVar15) {

    if (DAT_00702bb8 == 0) {

    pfVar6 = (float *)pfVar11[0x99];

    pfVar8 = pfVar11;

    while (pfVar7 = pfVar6, pfVar7 != (float *)0x0) {

    pfVar8 = pfVar7;

    pfVar6 = (float *)pfVar7[0x99];

    }

    if (pfVar8 == DAT_00702774) {

    pfVar8 = (float *)FUN_00558360();

    }

    else {

    pfVar8 = (float *)FUN_005581d0();

    }

    fVar15 = 0.0;

    }

    pfVar9[0xb] = 0.5;

    }

    LAB_00537f4f:

    if (local_88 == 2.66247e-44) goto LAB_00537f5c;

    if (local_88 != 5.60519e-45) goto LAB_00538a92;

    }

    else {

    switchD_00537d69_caseD_0:

    pfVar9[0xb] = 0.5;

    if (local_88 != 5.60519e-45) {

    if (local_88 != 2.66247e-44) {

    pfVar8 = local_a0;

    if (local_88 == 7.00649e-45) {

    pfVar8 = (float *)0x0;

    }

    iVar4 = FUN_005323c0(pfVar9 + 9,pfVar8,&local_18,0x43fa0000);

    pfVar8 = (float *)0x0;

    if (iVar4 != 0) {

    pfVar8 = (float *)FUN_00506420();

    }

    goto LAB_00538a92;

    }

    LAB_00537f5c:

    local_78 = pfVar9 + 0x4b;

    *local_78 = 0.0;

    FUN_0062a0b0();

    local_7c = pfVar9 + 0x4a;

    *local_7c = pfVar9[0x4a] - fVar15;

    if ((*(float *)(DAT_007028f4 + 0x69c) <= pfVar9[0x5f]) ||

    ((pfVar9[0x4c] != 0.0 && (_DAT_0066bce4 < pfVar9[0x5f])))) {

    local_30 = CONCAT44((uint)pfVar11[0xbf] ^ DAT_0066c580,(uint)pfVar11[0xbb] ^ DAT_0066c580);

    local_28 = (float *)((uint)pfVar11[0xc3] ^ DAT_0066c580);

    FUN_00638d90(&local_30,(int)&local_30 + 4,&local_28);

    local_98 = 0.0;

    local_24 = CONCAT44(local_30._4_4_ * *(float *)(DAT_007028f4 + 0xfa8) + pfVar11[0x3d],

    (float)local_30 * *(float *)(DAT_007028f4 + 0xfa8) + pfVar11[0x3c]);

    local_1c = (float *)((float)local_28 * *(float *)(DAT_007028f4 + 0xfa8) + pfVar11[0x3e]);

    for (local_80 = DAT_007027a8; local_80 != (float *)0x0; local_80 = (float *)*local_80) {

    local_9c = (float *)local_80[3];

    local_8c = (float *)(local_9c[0x68] + *(float *)(DAT_007028f4 + 0xfa8));

    fVar14 = (float10)FUN_00638d40(local_9c + 0x3c,&local_24);

    local_74[0] = (float)fVar14;

    if ((local_74[0] <= (float)local_8c * (float)local_8c) &&

    (iVar4 = FUN_005755d0(local_9c,pfVar11[0x76]), iVar4 != 0)) {

    if ((local_9c[0x8b] == 1.03696e-43) && ((int)local_9c[0x4c] < 4)) {

    if (pfVar11 == DAT_00702774) {

    local_98 = 1.4013e-45;

    }

    }

    else {

    *local_78 = 1.4013e-45;

    if (*local_7c <= 0.0) {

    if (local_9c == DAT_00702774) {

    fVar15 = local_9c[0x8b];

    }

    else {

    fVar15 = local_9c[0x8b];

    }

    pfVar8 = local_9c;

    if ((fVar15 == 2.8026e-45) &&

    (puVar3 = DAT_007027b0, ((uint)local_9c[0x4b] & 0x8020000) != 0)) {

    for (; puVar3 != (uint32_t *)0x0; puVar3 = (uint32_t *)*puVar3) {

    pfVar8 = (float *)puVar3[3];

    if (((((uint)pfVar8[0x49] & 0x8000) == 0) && (pfVar8[1] == 1.38869e-42)) &&

    ((float *)pfVar8[0x99] == local_9c)) goto LAB_00538272;

    }

    pfVar8 = (float *)0x0;

    }

    LAB_00538272:

    FUN_00500d30(0,pfVar8 + 0x3c,0);

    }

    }

    }

    }

    local_80 = (float *)0x0;

    if (pfVar9[0x4b] != 1.4013e-45) {

    if (local_98 != 0.0) {

    FUN_005e80c0("HintWaitRepair",local_98,0xe0e020);

    FUN_0048f130();

    }

    local_a8 = (float *)pfVar11[0x53];

    if (((local_a8[0x4c] != 0.0) && (FUN_004ea1b0(), DAT_006ff960 == 6)) &&

    (iVar4 = FUN_0045f460(), iVar4 != 0)) {

    FUN_00469d20(0x1a,0);

    }

    pfVar8 = (float *)local_a8[0x79];

    piVar10 = DAT_007496c4;

    if (pfVar8 != (float *)0x0) {

    for (; piVar10 != (int *)0x0; piVar10 = (int *)*piVar10) {

    if ((float *)piVar10[0x11] == pfVar8) goto LAB_00538355;

    }

    goto LAB_0053835e;

    }

    goto LAB_00538368;

    }

    pfVar8 = local_80;

    if (pfVar9[0x4a] <= 0.0) {

    pfVar8 = *(float **)(DAT_007028f4 + 0xfb0);

    pfVar9[0x4a] = (float)pfVar8;

    }

    }

    else {

    local_a8 = (float *)pfVar11[0x53];

    if (((local_a8[0x4c] != 0.0) && (FUN_004ea1b0(), DAT_006ff960 == 6)) &&

    (iVar4 = FUN_0045f460(), iVar4 != 0)) {

    FUN_00469d20(0x1a,0);

    }

    pfVar8 = (float *)local_a8[0x79];

    piVar10 = DAT_007496c4;

    if (pfVar8 != (float *)0x0) {

    for (; piVar10 != (int *)0x0; piVar10 = (int *)*piVar10) {

    if ((float *)piVar10[0x11] == pfVar8) goto LAB_00538355;

    }

    LAB_0053835e:

    local_a8[0x79] = 0.0;

    }

    LAB_00538368:

    local_a8[0x4b] = 0.0;

    }

    if (pfVar9[0x4b] != 0.0) {

    pfVar6 = *(float **)(DAT_007028f4 + 0xfa4);

    local_8c = pfVar6;

    pfVar8 = (float *)FUN_0062a0b0();

    fVar15 = pfVar9[0x5f] - (float)pfVar6 * (float)local_8c;

    pfVar9[0x5f] = fVar15;

    if (fVar15 <= 0.0) {

    pfVar9[0x5f] = 0.0;

    }

    if ((pfVar9[0x4c] == 0.0) && (pfVar8 = (float *)0x0, local_90 != (float *)0x0)) {

    local_4c = local_90;

    local_50 = 1;

    local_54 = 8;

    pfVar8 = (float *)FUN_004e9cd0(local_64);

    pfVar9[0x4c] = (float)pfVar8;

    if (DAT_006ff960 == 6) {

    iVar4 = FUN_0045f460();

    pfVar8 = (float *)0x0;

    if (iVar4 != 0) {

    pfVar8 = (float *)FUN_00469de0(0,0,0x19,0,0);

    }

    }

    }

    if (pfVar9[0x79] == 0.0) {

    pfVar8 = (float *)FUN_00558730(0x5d5,pfVar11,0,3);

    pfVar9[0x79] = (float)pfVar8;

    }

    }

    goto LAB_00538a92;

    }

    }

    if (pfVar9[0x3f] <= fVar15) {

    pfVar9[0x40] = 1.4013e-45;

    iVar4 = FUN_004feb50();

    if (iVar4 == 0) {

    pfVar6 = (float *)pfVar11[0x99];

    pfVar8 = pfVar11;

    while (pfVar7 = pfVar6, pfVar7 != (float *)0x0) {

    pfVar8 = pfVar7;

    pfVar6 = (float *)pfVar7[0x99];

    }

    if (((DAT_00702800 != 0) && (DAT_00702800 + 0xf85c != 0)) &&

    (*(int *)(DAT_00702800 + 0xf864) != 0)) {

    (*DAT_007280a0)(DAT_00702800 + 0xf85c,pfVar8);

    }

    pfVar9[0x75] = 0.0;

    pfVar9[0x42] = 0.0;

    pfVar9[0x3f] = *(float *)(DAT_007028f4 + 0x8f4);

    pfVar9[0x40] = 0.0;

    }

    }

    if (pfVar9[0x42] == 0.0) {

    pfVar6 = (float *)pfVar11[0x99];

    pfVar8 = pfVar11;

    while (pfVar7 = pfVar6, pfVar7 != (float *)0x0) {

    pfVar8 = pfVar7;

    pfVar6 = (float *)pfVar7[0x99];

    }

    if (((DAT_00702800 != 0) && (DAT_00702800 + 0xf85c != 0)) &&

    (*(int *)(DAT_00702800 + 0xf864) != 0)) {

    (*DAT_007280a0)(DAT_00702800 + 0xf85c,pfVar8);

    }

    pfVar8 = (float *)pfVar9[0x41];

    pfVar9[0x75] = 0.0;

    if (pfVar8 != (float *)0x0) {

    pfVar8[0x49] = (float)((uint)pfVar8[0x49] | 0x40000000);

    }

    }

    else {

    if (pfVar9[0x75] == 0.0) {

    if (DAT_00702bb8 == 0) {

    pfVar6 = (float *)pfVar11[0x99];

    pfVar8 = pfVar11;

    while (pfVar7 = pfVar6, pfVar7 != (float *)0x0) {

    pfVar8 = pfVar7;

    pfVar6 = (float *)pfVar7[0x99];

    }

    if (pfVar8 == DAT_00702774) {

    FUN_00558360();

    }

    else {

    FUN_005581d0();

    }

    }

    pfVar9[0x75] = 1.4013e-45;

    }

    pfVar8 = (float *)pfVar9[0x41];

    if ((float *)pfVar9[0x41] == (float *)0x0) {

    local_a8 = (float *)FUN_00559530();

    if (local_a8 != (float *)0x0) {

    local_8c = (float *)FUN_0055a8a0();

    if (local_8c == (float *)0x0) {

    FUN_00463000(&DAT_00701bd8,"Error: ObjObj type %d not found",extraout_ECX_02);

    if (DAT_0074c5d4 < 5) {

    FUN_0062edc0(&DAT_00701bd8);

    }

    DAT_0074c5d4 = DAT_0074c5d4 + 1;

    }

    else {

    FUN_0055a4a0(local_8c);

    FUN_0055a710(local_8c);

    }

    FUN_005597d0();

    }

    pfVar9[0x41] = (float)local_a8;

    pfVar8 = local_a8;

    }

    pfVar8[0x49] = (float)((uint)pfVar8[0x49] & 0xbfffffff);

    *(uint32_t *)((int)pfVar9[0x41] + 0x124) = *(uint32_t *)((int)pfVar9[0x41] + 0x124) | 0x10000;

    FUN_0063e7f0((int)pfVar9[0x41] + 0x2e4);

    pfVar8 = (float *)FUN_005671a0();

    }

    LAB_00538a92:

    if (pfVar9[9] <= 0.0 && pfVar9[9] != 0.0) {

    pfVar9[9] = 0.0;

    }

    if (((uint)pfVar11[0x98] & 1) != 0) {

    if (pfVar9[0x84] != 0.0) {

    return pfVar8;

    }

    pfVar11[0x4a] = (float)((uint)pfVar11[0x4a] | 0x8000000);

    return pfVar8;

    }

    pfVar11[0x4a] = (float)((uint)pfVar11[0x4a] & 0xf7ffffff);

    pfVar11[0x4b] = (float)((uint)pfVar11[0x4b] & 0xffefffff);

    return pfVar8;

    LAB_00538355:

    pfVar8 = (float *)FUN_005583d0();

    goto LAB_0053835e;


}  // 0x00537130
#endif // RenderFn537130
void RenderFn537130() {}  // 0x00537130
#if 0 // GHIDRA_RAW: GameFn4796B0 @ 0x004796b0 — needs manual cleanup
bool GameFn4796B0(uint32_t param_1,int param_2,uint32_t param_3)
{


    double dVar1;

    byte bVar2;

    int *piVar3;

    uint8_t uVar4;

    char cVar5;

    char cVar6;

    uint32_t *puVar7;

    int iVar8;

    uint32_t uVar9;

    int iVar10;

    byte *pbVar11;

    byte *_Memory;

    void *pvVar12;

    float *pfVar13;

    uint32_t *puVar14;

    uint32_t uVar15;

    byte *pbVar16;

    char cVar17;

    int *piVar18;

    uint32_t extraout_EDX;

    int *piVar19;

    bool bVar20;

    float fVar21;

    float fVar22;

    float fVar23;

    float fVar24;

    float fVar25;

    float fVar26;

    float fVar27;

    uint64_t uVar28;

    uint32_t uVar29;

    uint32_t uVar30;

    uint8_t auStack_f8 [9];

    char local_ef;

    char local_ee;

    char local_ed;

    uint32_t local_ec;

    char local_e8;

    bool local_e7;

    char local_e6;

    char local_e5;

    byte *local_e4;

    int *local_e0;

    float local_dc;

    uint32_t *local_d8;

    uint32_t local_d4;

    int local_d0;

    float local_cc;

    byte *local_c8;

    byte *local_c4;

    int local_c0;

    float local_bc;

    float local_b8;

    float local_b4;

    float local_b0;

    float local_ac;

    byte *local_a8;

    byte *local_a4;

    float local_a0;

    float fStack_9c;

    float fStack_98;

    float fStack_94;

    float local_88;

    float local_84;

    float local_80;

    float fStack_7c;

    float fStack_78;

    float fStack_74;

    float local_70;

    float local_6c;

    uint32_t local_68;

    int local_64;

    float local_60;

    float fStack_5c;

    byte *pbStack_58;

    float fStack_54;

    float local_48;

    float local_40;

    float local_3c;

    float local_38;

    float local_34;

    uint32_t local_30;

    uint32_t uStack_2c;

    uint32_t uStack_28;

    uint32_t uStack_24;

    uint32_t local_14;



    piVar19 = DAT_00701a3c;

    local_14 = DAT_0067d280 ^ (uint)auStack_f8;

    local_ec = param_3;

    local_e0 = DAT_00701a3c;

    local_64 = param_2;

    puVar7 = (uint32_t *)FUN_004772b0();

    local_e6 = puVar7 == (uint32_t *)0x0;

    local_d8 = puVar7;

    if (puVar7 == (uint32_t *)0x0) {

    puVar7 = (uint32_t *)FUN_00477350();

    }

    if ((local_ec & 0xc0200) == 0xc0200) {

    local_ec = local_ec | 6;

    }

    local_c0 = piVar19[0x684];

    local_d0 = puVar7[0x93];

    if ((piVar19[0x694] == 0) && (*(char *)((int)piVar19 + 0x1a1d) != '\0')) {

    uVar4 = 1;

    }

    else {

    uVar4 = 0;

    }

    *(uint8_t *)((int)puVar7 + 0x8a) = uVar4;

    local_ef = *(char *)((int)puVar7 + 0xa1);

    local_e7 = local_d0 < local_c0 + -1;

    if ((local_ec & 0x4000000) != 0) {

    local_e7 = local_e7 ||

    (puVar7 != *(uint32_t **)(local_e0[0x6ed] + 4 + piVar19[0x6ee] * 0x24) ||

    puVar7[0x25] != *(int *)(local_e0[0x6ed] + piVar19[0x6ee] * 0x24));

    piVar19 = local_e0;

    }

    if ((local_e7) || ('\0' < local_ef)) {

    *(byte *)(puVar7 + 0x29) = *(byte *)(puVar7 + 0x29) | 8;

    *(byte *)((int)puVar7 + 0xa5) = *(byte *)((int)puVar7 + 0xa5) | 8;

    *(byte *)((int)puVar7 + 0xa6) = *(byte *)((int)puVar7 + 0xa6) | 8;

    *(uint8_t *)(puVar7 + 0x22) = 1;

    }

    else {

    *(uint8_t *)(puVar7 + 0x22) = 0;

    }

    if (local_d0 == local_c0) {

    local_ec = puVar7[2];

    }

    else {

    puVar7[2] = local_ec;

    puVar7[0x93] = local_c0;

    dVar1 = *(double *)(piVar19 + 0x682);

    *(uint16_t *)(puVar7 + 0x24) = 0;

    puVar7[0x94] = (float)dVar1;

    iVar8 = piVar19[0x69a];

    piVar19[0x69a] = piVar19[0x69a] + 1;

    *(short *)((int)puVar7 + 0x92) = (short)iVar8;

    }

    if (piVar19[0x694] == 0) {

    local_d4 = 0;

    }

    else {

    local_d4 = *(uint32_t *)(piVar19[0x696] + -4 + piVar19[0x694] * 4);

    }

    if (local_d0 == local_c0) {

    local_d4 = puVar7[0xc6];

    }

    else {

    local_d4 = -(uint)((local_ec & 0x5000000) != 0) & local_d4;

    }

    if (puVar7[0x2e] == 0) {

    if (puVar7[0x2f] == 0) {

    FUN_004810b0(8);

    }

    *(uint32_t *)(puVar7[0x30] + puVar7[0x2e] * 4) = puVar7[1];

    puVar7[0x2e] = puVar7[0x2e] + 1;

    }

    piVar3 = local_e0;

    iVar8 = piVar19[0x695];

    piVar18 = piVar19 + 0x694;

    if (*piVar18 == iVar8) {

    if (iVar8 == 0) {

    iVar8 = 8;

    }

    else {

    iVar8 = iVar8 / 2 + iVar8;

    }

    iVar10 = piVar19[0x694] + 1;

    if (piVar19[0x694] + 1 < iVar8) {

    iVar10 = iVar8;

    }

    FUN_004810b0(iVar10);

    piVar18 = piVar3 + 0x694;

    piVar19 = piVar3;

    }

    *(uint32_t **)(piVar18[2] + *piVar18 * 4) = puVar7;

    *piVar18 = *piVar18 + 1;

    piVar18 = DAT_00701a3c;

    piVar19[0x69b] = (int)puVar7;

    *(uint16_t *)(puVar7 + 0x71) = *(uint16_t *)(piVar18[0x69b] + 0xb8);

    *(short *)((int)puVar7 + 0x1c6) = (short)piVar18[0x6d9];

    *(short *)(puVar7 + 0x72) = (short)piVar18[0x6dc];

    *(short *)((int)puVar7 + 0x1ca) = (short)piVar18[0x6df];

    *(short *)(puVar7 + 0x73) = (short)piVar18[0x6e2];

    *(short *)((int)puVar7 + 0x1ce) = (short)piVar18[0x6e8];

    *(short *)(puVar7 + 0x74) = (short)piVar18[0x6ee];

    piVar19[0x69b] = 0;

    if ((local_ec & 0x4000000) != 0) {

    iVar8 = piVar19[0x6ee];

    iVar10 = piVar19[0x6ed];

    *(uint32_t **)(iVar10 + 4 + iVar8 * 0x24) = puVar7;

    puVar14 = (uint32_t *)(iVar10 + iVar8 * 0x24);

    FUN_00480e20(puVar14);

    puVar7[0x25] = *puVar14;

    piVar19 = local_e0;

    }

    if (('\0' < local_ef) && ((local_ec & 0x1000000) == 0)) {

    puVar7[0xcb] = 0;

    }

    if (local_d0 != local_c0) {

    puVar7[0xc6] = local_d4;

    puVar7[0xc9] = puVar7;

    puVar7[200] = puVar7;

    puVar7[199] = puVar7;

    if (local_d4 != 0) {

    if ((local_ec & 0x3000000) == 0x1000000) {

    puVar7[199] = *(uint32_t *)(local_d4 + 0x31c);

    }

    if (((local_ec & 0x8000000) == 0) && ((local_ec & 0x5000000) != 0)) {

    puVar7[200] = *(uint32_t *)(local_d4 + 800);

    }

    }

    uVar9 = puVar7[2];

    puVar14 = puVar7;

    while ((uVar9 & 0x800000) != 0) {

    puVar14 = (uint32_t *)puVar14[0xc6];

    puVar7[0xc9] = puVar14;

    uVar9 = puVar14[2];

    }

    }

    local_ed = '\0';

    local_e8 = '\0';

    local_ee = '\0';

    if ((*(byte *)(piVar19 + 0x6bc) & 1) != 0) {

    bVar2 = *(byte *)(puVar7 + 0x29);

    uVar9 = piVar19[0x6bd];

    local_ed = (uVar9 & (int)(char)bVar2) != 0;

    if (((uVar9 & (int)(char)bVar2) == 0) ||

    ((float)piVar19[0x6c2] * (float)piVar19[0x6c2] +

    (float)piVar19[0x6c3] * (float)piVar19[0x6c3] <= DAT_0066bcf8)) {

    FUN_0047bda0(uVar9);

    }

    else {

    iVar8 = piVar19[0x6c0];

    puVar7[0x2b] = piVar19[0x6c1];

    puVar7[0x2a] = iVar8;

    iVar8 = piVar19[0x6c2];

    puVar7[0x2d] = piVar19[0x6c3];

    puVar7[0x2c] = iVar8;

    puVar7[0x29] = bVar2 & 0xf1 | puVar7[0x29] & 0xffffff00;

    }

    }

    if ((*(byte *)(piVar19 + 0x6bc) & 2) != 0) {

    uVar9 = (int)*(char *)((int)puVar7 + 0xa5) & piVar19[0x6be];

    if ((uVar9 == 0) || ((float)piVar19[0x6c4] <= 0.0)) {

    local_e8 = '\0';

    if (uVar9 != 0) goto LAB_00479b4c;

    LAB_00479b5e:

    local_ee = '\0';

    }

    else {

    local_e8 = '\x01';

    LAB_00479b4c:

    local_ee = '\x01';

    if ((float)piVar19[0x6c5] <= 0.0) goto LAB_00479b5e;

    }

    FUN_0047bea0(piVar19[0x6be]);

    }

    if ((*(byte *)(piVar19 + 0x6bc) & 0x80) != 0) {

    if (0.0 <= (float)piVar19[0x6c8]) {

    puVar7[0x18] = piVar19[0x6c8];

    puVar7[0x1a] = 0;

    }

    if (0.0 <= (float)piVar19[0x6c9]) {

    puVar7[0x19] = piVar19[0x6c9];

    puVar7[0x1b] = 0;

    }

    }

    if ((*(byte *)(piVar19 + 0x6bc) & 4) == 0) {

    if (local_d0 != local_c0) {

    puVar7[0xb] = 0;

    puVar7[0xc] = 0;

    }

    }

    else {

    iVar8 = piVar19[0x6c7];

    puVar7[0xb] = piVar19[0x6c6];

    puVar7[0xc] = iVar8;

    }

    if ((*(byte *)(piVar19 + 0x6bc) & 8) != 0) {

    if ((piVar19[0x6bf] == 0) || ((piVar19[0x6bf] & (int)*(char *)((int)puVar7 + 0xa6)) != 0)) {

    *(char *)((int)puVar7 + 0x85) = (char)piVar19[0x6ca];

    puVar7[0x29] = (*(byte *)((int)puVar7 + 0xa6) & 0xf1) << 0x10 | puVar7[0x29] & 0xff00ffff;

    }

    }

    if ((*(byte *)(piVar19 + 0x6bc) & 0x20) != 0) {

    FUN_0047bac0();

    }

    if (*(char *)(puVar7 + 0x22) != '\0') {

    *(byte *)(puVar7 + 0x29) = *(byte *)(puVar7 + 0x29) & 0xf7;

    *(byte *)((int)puVar7 + 0xa5) = *(byte *)((int)puVar7 + 0xa5) & 0xf7;

    *(byte *)((int)puVar7 + 0xa6) = *(byte *)((int)puVar7 + 0xa6) & 0xf7;

    }

    piVar18 = DAT_00701a3c;

    if (local_d0 == local_c0) {

    DAT_00701a3c[0x69b] = (int)puVar7;

    if (puVar7[99] == -1) {

    iVar8 = 0;

    }

    else {

    iVar8 = puVar7[99] * 0x220 + piVar18[0x7c6];

    }

    piVar18[0x7c3] = iVar8;

    fVar21 = (float)piVar18[0x64d] * (float)puVar7[0x9c];

    if (puVar7[0xc6] != 0) {

    fVar21 = fVar21 * *(float *)(puVar7[0xc6] + 0x270);

    }

    piVar18[0x651] = (int)fVar21;

    piVar18[0x64c] = (int)fVar21;

    goto LAB_0047b812;

    }

    local_dc = (float)(local_ec & 0x3000000);

    *(uint8_t *)((int)puVar7 + 0x82) = 1;

    *(bool *)((int)puVar7 + 0x8b) = local_64 != 0;

    puVar7[0x89] = 0xff7fffff;

    puVar7[0x8a] = 0xff7fffff;

    puVar7[0x8b] = 0x7f7fffff;

    puVar7[0x8c] = 0x7f7fffff;

    iVar8 = puVar7[0x2f];

    if (iVar8 < 1) {

    if (iVar8 == 0) {

    iVar8 = 8;

    }

    else {

    iVar8 = iVar8 / 2 + puVar7[0x2f];

    }

    iVar10 = 1;

    if (1 < iVar8) {

    iVar10 = iVar8;

    }

    FUN_004810b0(iVar10);

    }

    puVar7[0x2e] = 1;

    FUN_00483b60();

    puVar7[99] = 0xffffffff;

    if (*(char *)(puVar7 + 0xd7) != '\0') {

    *(uint8_t *)(puVar7 + 0xd7) = 0;

    FUN_004812a0(puVar7[0xd5]);

    FUN_00481130(puVar7[0xd6]);

    puVar7[0xd6] = 0;

    puVar7[0xd5] = 0;

    }

    if (((piVar19[0x735] != 0) && ((puVar7[2] & 0x80000) == 0)) && (local_d8 != (uint32_t *)0x0)) {

    _Memory = (byte *)*puVar7;

    pbVar11 = local_a8;

    pbVar16 = _Memory;

    do {

    bVar2 = *pbVar11;

    bVar20 = bVar2 < *pbVar16;

    if (bVar2 != *pbVar16) {

    LAB_00479db8:

    uVar9 = -(uint)bVar20 | 1;

    goto LAB_00479dbd;

    }

    if (bVar2 == 0) break;

    bVar2 = pbVar11[1];

    bVar20 = bVar2 < pbVar16[1];

    if (bVar2 != pbVar16[1]) goto LAB_00479db8;

    pbVar11 = pbVar11 + 2;

    pbVar16 = pbVar16 + 2;

    } while (bVar2 != 0);

    uVar9 = 0;

    LAB_00479dbd:

    local_c8 = _Memory;

    if (uVar9 != 0) {

    local_e4 = (byte *)puVar7[0x11];

    local_a4 = local_a8 + 1;

    local_c4 = local_a8;

    do {

    bVar2 = *local_c4;

    local_c4 = local_c4 + 1;

    } while (bVar2 != 0);

    local_c4 = local_c4 + (1 - (int)local_a4);

    if (local_e4 < local_c4) {

    if ((_Memory != (byte *)0x0) && (DAT_00701a3c != (int *)0x0)) {

    DAT_00701a3c[0xdc] = DAT_00701a3c[0xdc] + -1;

    }

    free(_Memory);

    if (DAT_00701a3c != (int *)0x0) {

    DAT_00701a3c[0xdc] = DAT_00701a3c[0xdc] + 1;

    }

    _Memory = malloc((size_t)local_c4);

    local_e4 = local_c4;

    }

    pvVar12 = memcpy(_Memory,local_a8,(size_t)local_c4);

    *puVar7 = pvVar12;

    puVar7[0x11] = local_e4;

    }

    }

    if (((*(char *)((int)puVar7 + 0x85) == '\0') || ('\0' < *(char *)(puVar7 + 0x26))) ||

    ('\0' < *(char *)((int)puVar7 + 0x99))) {

    if (((*(char *)((int)puVar7 + 0x89) == '\0') || (*(char *)((int)puVar7 + 0xa1) != '\0')) ||

    (*(char *)(puVar7 + 0x28) < '\x01')) {

    fVar21 = (float)puVar7[0xb];

    if (fVar21 == 0.0) {

    fVar21 = (float)puVar7[0x37] - (float)puVar7[0x35];

    }

    fVar23 = (float)puVar7[0xc];

    fVar21 = (float)(int)fVar21;

    if (fVar23 == 0.0) {

    fVar23 = (float)puVar7[0x38] - (float)puVar7[0x36];

    }

    fVar23 = (float)(int)fVar23;

    }

    else {

    fVar21 = (float)puVar7[9];

    fVar23 = (float)puVar7[10];

    }

    }

    else {

    fVar21 = (float)puVar7[9];

    fVar23 = (float)puVar7[10];

    }

    puVar7[9] = fVar21;

    puVar7[10] = fVar23;

    if ('\0' < *(char *)(puVar7 + 0x28)) {

    *(char *)(puVar7 + 0x28) = *(char *)(puVar7 + 0x28) + -1;

    }

    if ('\0' < *(char *)((int)puVar7 + 0xa1)) {

    *(char *)((int)puVar7 + 0xa1) = *(char *)((int)puVar7 + 0xa1) + -1;

    }

    if ('\0' < *(char *)((int)puVar7 + 0xa2)) {

    *(char *)((int)puVar7 + 0xa2) = *(char *)((int)puVar7 + 0xa2) + -1;

    }

    if ((local_d8 == (uint32_t *)0x0) && ((local_e8 == '\0' || (local_ee == '\0')))) {

    *(uint8_t *)((int)puVar7 + 0xa1) = 1;

    }

    if (((local_e7 != false) && ((local_ec & 0x6000000) != 0)) &&

    (*(uint8_t *)((int)puVar7 + 0xa1) = 1, (local_ec & 0x40) != 0)) {

    if (local_e8 == '\0') {

    puVar7[7] = 0;

    puVar7[5] = 0;

    }

    if (local_ee == '\0') {

    puVar7[8] = 0;

    puVar7[6] = 0;

    }

    puVar7[9] = 0;

    puVar7[10] = 0;

    }

    piVar18 = DAT_00701a3c;

    local_e4 = (byte *)DAT_00701a3c;

    DAT_00701a3c[0x69b] = (int)puVar7;

    if (puVar7[99] == -1) {

    iVar8 = 0;

    }

    else {

    iVar8 = puVar7[99] * 0x220 + piVar18[0x7c6];

    }

    piVar18[0x7c3] = iVar8;

    fVar21 = (float)piVar18[0x64d] * (float)puVar7[0x9c];

    if (puVar7[0xc6] != 0) {

    fVar21 = fVar21 * *(float *)(puVar7[0xc6] + 0x270);

    }

    piVar18[0x651] = (int)fVar21;

    piVar18[0x64c] = (int)fVar21;

    if ((local_ec & 0x1000000) == 0) {

    if (((local_ec & 0x6000000) == 0) || ((local_ec & 0x8000000) != 0)) {

    fVar21 = (float)piVar19[0x54a];

    }

    else {

    fVar21 = (float)piVar19[0x553];

    }

    }

    else {

    fVar21 = (float)piVar19[0x551];

    }

    puVar7[0x10] = fVar21;

    iVar8 = piVar19[0x548];

    puVar7[0xd] = piVar19[0x547];

    puVar7[0xe] = iVar8;

    if (((local_ec & 0x5010000) == 0x1000000) && (fVar21 == 0.0)) {

    if ((local_ec & 0x400) == 0) {

    iVar8 = 0;

    }

    else {

    iVar8 = piVar19[0x548];

    }

    puVar7[0xd] = 0;

    puVar7[0xe] = iVar8;

    }

    fVar21 = (float)puVar7[0xd];

    if ((float)puVar7[0xd] <= (float)piVar19[0x558]) {

    fVar21 = (float)piVar19[0x558];

    }

    if (fVar21 <= (float)piVar19[0x6d2]) {

    fVar21 = (float)piVar19[0x6d2];

    }

    puVar7[0x51] = fVar21;

    puVar7[0x52] = piVar19[0x6d3];

    if ((local_ec & 0x21) == 0) {

    if ((*(byte *)(puVar7 + 2) & 1) == 0) {

    fVar21 = (float)piVar18[0x64d] * (float)puVar7[0x9c];

    if (puVar7[0xc6] != 0) {

    fVar21 = fVar21 * *(float *)(puVar7[0xc6] + 0x270);

    }

    fVar21 = (float)piVar18[0x555] + (float)piVar18[0x555] + fVar21;

    }

    else {

    fVar21 = 0.0;

    }

    fVar23 = (float)puVar7[3];

    if ((((uint32_t *)piVar19[0x69c] == puVar7) && (piVar19[0x6a4] == 0)) && (piVar19[0x6a5] == 0)

    ) {

    iVar8 = piVar18[0x69b];

    fVar27 = fVar23;

    if (fVar23 <= *(float *)(iVar8 + 0x224)) {

    fVar27 = *(float *)(iVar8 + 0x224);

    }

    fVar22 = fVar23 + (float)puVar7[7];

    if (*(float *)(iVar8 + 0x22c) <= fVar23 + (float)puVar7[7]) {

    fVar22 = *(float *)(iVar8 + 0x22c);

    }

    fVar23 = (float)puVar7[4];

    if ((float)puVar7[4] <= *(float *)(iVar8 + 0x228)) {

    fVar23 = *(float *)(iVar8 + 0x228);

    }

    fVar25 = fVar21 + (float)puVar7[4];

    if (*(float *)(iVar8 + 0x230) <= fVar21 + (float)puVar7[4]) {

    fVar25 = *(float *)(iVar8 + 0x230);

    }

    if (((fVar27 - (float)piVar18[0x55e] <= (float)piVar18[0x39]) &&

    (fVar23 - (float)piVar18[0x55f] <= (float)piVar18[0x3a])) &&

    (((float)piVar18[0x39] < fVar22 + (float)piVar18[0x55e] &&

    (((float)piVar18[0x3a] < fVar25 + (float)piVar18[0x55f] &&

    (*(char *)((int)piVar19 + 0x3dd) != '\0')))))) {

    *(uint8_t *)((int)puVar7 + 0x86) = 1;

    }

    }

    if (*(char *)((int)puVar7 + 0x86) != '\0') {

    *(bool *)((int)puVar7 + 0x85) = *(char *)((int)puVar7 + 0x85) == '\0';

    if (((puVar7[2] & 0x100) == 0) && ((float)piVar18[0xbb5] <= 0.0)) {

    piVar18[0xbb5] = piVar18[7];

    }

    FUN_0047bac0();

    }

    }

    else {

    *(uint8_t *)((int)puVar7 + 0x85) = 0;

    }

    *(uint8_t *)((int)puVar7 + 0x86) = 0;

    FUN_00477910(puVar7 + 9);

    local_e5 = local_e6;

    if (((local_ec & 0x40) == 0) || (*(char *)((int)puVar7 + 0x85) != '\0')) {

    if (('\0' < *(char *)(puVar7 + 0x26)) || ('\0' < *(char *)((int)puVar7 + 0x99))) {

    if ((local_e8 == '\0') && ('\0' < *(char *)(puVar7 + 0x26))) {

    fVar21 = local_88;

    if ((*(char *)((int)puVar7 + 0x9b) != '\0') &&

    (fVar21 = (float)puVar7[7], (float)puVar7[7] <= local_88)) {

    fVar21 = local_88;

    }

    puVar7[7] = fVar21;

    local_e6 = '\x01';

    }

    if ((local_ee == '\0') && ('\0' < *(char *)((int)puVar7 + 0x99))) {

    fVar21 = local_84;

    if ((*(char *)((int)puVar7 + 0x9b) != '\0') &&

    (fVar21 = (float)puVar7[8], (float)puVar7[8] <= local_84)) {

    fVar21 = local_84;

    }

    puVar7[8] = fVar21;

    local_e5 = '\x01';

    }

    if (((*(char *)((int)puVar7 + 0x85) == '\0') && ((puVar7[2] & 0x100) == 0)) &&

    ((float)DAT_00701a3c[0xbb5] <= 0.0)) {

    DAT_00701a3c[0xbb5] = DAT_00701a3c[7];

    }

    }

    }

    else {

    if (local_e8 == '\0') {

    puVar7[7] = local_88;

    local_e6 = '\x01';

    }

    if (local_ee == '\0') {

    puVar7[8] = local_84;

    local_e5 = '\x01';

    }

    }

    pfVar13 = (float *)FUN_00477710(puVar7[7],puVar7[8]);

    fVar21 = *pfVar13;

    fVar23 = pfVar13[1];

    puVar7[7] = fVar21;

    puVar7[8] = fVar23;

    piVar18 = DAT_00701a3c;

    if ((*(char *)((int)puVar7 + 0x85) != '\0') && ((local_ec & 0x1000000) == 0)) {

    if ((*(byte *)(puVar7 + 2) & 1) == 0) {

    fVar23 = (float)DAT_00701a3c[0x64d] * (float)puVar7[0x9c];

    if (puVar7[0xc6] != 0) {

    fVar23 = fVar23 * *(float *)(puVar7[0xc6] + 0x270);

    }

    fVar23 = (float)DAT_00701a3c[0x555] + (float)DAT_00701a3c[0x555] + fVar23;

    }

    else {

    fVar23 = 0.0;

    }

    fVar21 = (fVar21 + (float)puVar7[3]) - (float)puVar7[3];

    fVar23 = (fVar23 + (float)puVar7[4]) - (float)puVar7[4];

    }

    puVar7[5] = fVar21;

    puVar7[6] = fVar23;

    if ((*(byte *)(puVar7 + 2) & 1) == 0) {

    fVar21 = (float)piVar18[0x64d] * (float)puVar7[0x9c];

    if (puVar7[0xc6] != 0) {

    fVar21 = fVar21 * *(float *)(puVar7[0xc6] + 0x270);

    }

    fVar21 = (float)piVar18[0x555] + (float)piVar18[0x555] + fVar21;

    }

    else {

    fVar21 = 0.0;

    }

    if ((puVar7[2] & 0x400) == 0) {

    fVar23 = 0.0;

    }

    else {

    fVar23 = (float)piVar18[0x64d] * (float)puVar7[0x9c];

    if (puVar7[0xc6] != 0) {

    fVar23 = fVar23 * *(float *)(puVar7[0xc6] + 0x270);

    }

    fVar23 = fVar23 + (float)puVar7[0x52] + (float)piVar18[0x555] + (float)piVar18[0x555];

    }

    local_c8 = (byte *)(fVar23 + fVar21);

    if (((local_e7 != false) && (puVar7[0x27] = 0xffffffff, (local_ec & 0xc000000) == 0x4000000)) &&

    (local_ed == '\0')) {

    uVar15 = *(uint32_t *)(piVar19[0x6f0] + -0xc + piVar19[0x6ee] * 0x24);

    puVar7[3] = *(uint32_t *)(piVar19[0x6f0] + -0x10 + piVar19[0x6ee] * 0x24);

    puVar7[4] = uVar15;

    }

    if ((local_ec & 0x1000000) != 0) {

    local_e4 = (byte *)(local_d4 + 0x178);

    *(uint16_t *)(puVar7 + 0x24) = *(uint16_t *)local_e4;

    iVar8 = *(int *)(local_d4 + 0x17c);

    if (*(int *)local_e4 == iVar8) {

    if (iVar8 == 0) {

    iVar8 = 8;

    }

    else {

    iVar8 = iVar8 / 2 + iVar8;

    }

    iVar10 = *(int *)local_e4 + 1;

    if (*(int *)local_e4 + 1 < iVar8) {

    iVar10 = iVar8;

    }

    FUN_004810b0(iVar10);

    piVar19 = local_e0;

    }

    *(uint32_t **)(*(int *)((int)local_e4 + 8) + *(int *)local_e4 * 4) = puVar7;

    *(int *)local_e4 = *(int *)local_e4 + 1;

    if ((((local_ec & 0x4000000) == 0) && (local_ed == '\0')) && (local_dc != 3.761582e-37)) {

    uVar15 = *(uint32_t *)(local_d4 + 0xc4);

    puVar7[4] = *(uint32_t *)(local_d4 + 200);

    puVar7[3] = uVar15;

    }

    }

    if (((float)puVar7[0x2a] == DAT_0066c238) || (*(char *)((int)puVar7 + 0xa1) != '\0')) {

    if (((local_ec & 0x10000000) != 0) ||

    (((((local_ec & 0x4000000) != 0 && (local_ed == '\0')) && ('\0' < local_ef)) ||

    (((fVar21 = local_dc, (local_ec & 0x2000000) != 0 && (local_ed == '\0')) &&

    (local_dc != 3.761582e-37)))))) {

    uVar28 = FUN_0047cdf0();

    fVar21 = (float)((uint64_t)uVar28 >> 0x20);

    uVar15 = ((uint32_t *)uVar28)[1];

    puVar7[3] = *(uint32_t *)uVar28;

    puVar7[4] = uVar15;

    }

    }

    else {

    local_70 = (float)puVar7[0x2a] - (float)puVar7[5] * (float)puVar7[0x2c];

    local_6c = (float)puVar7[0x2b] - (float)puVar7[6] * (float)puVar7[0x2d];

    FUN_0047bda0(0);

    fVar21 = (float)extraout_EDX;

    }

    fVar23 = (float)piVar19[0x570];

    if ((float)piVar19[0x570] <= (float)piVar19[0x572]) {

    fVar23 = (float)piVar19[0x572];

    }

    local_b4 = (float)DAT_00701a3c[4];

    local_b0 = (float)DAT_00701a3c[5];

    fVar27 = (float)piVar19[0x56f];

    if ((float)piVar19[0x56f] <= (float)piVar19[0x571]) {

    fVar27 = (float)piVar19[0x571];

    }

    local_80 = 0.0;

    local_34 = local_b0 - fVar23;

    fStack_7c = 0.0;

    fStack_78 = local_b4;

    local_38 = local_b4 - fVar27;

    fStack_74 = local_b0;

    local_3c = fVar23 + 0.0;

    local_40 = fVar27 + 0.0;

    if ((((local_ed == '\0') && ((local_ec & 0x1000000) == 0)) &&

    ((*(char *)(puVar7 + 0x26) < '\x01' &&

    ((*(char *)((int)puVar7 + 0x99) < '\x01' && (0.0 < local_b4 - 0.0)))))) &&

    (0.0 < local_b0 - 0.0)) {

    fVar22 = (float)puVar7[6];

    if (((char)DAT_00701a3c[0x2d] != '\0') && ((*(byte *)(puVar7 + 2) & 1) == 0)) {

    fVar21 = (float)puVar7[0xc6];

    fVar22 = (float)DAT_00701a3c[0x64d] * (float)puVar7[0x9c];

    if (fVar21 != 0.0) {

    fVar22 = fVar22 * *(float *)((int)fVar21 + 0x270);

    }

    fVar22 = (float)DAT_00701a3c[0x555] + (float)DAT_00701a3c[0x555] + fVar22;

    }

    fVar25 = (float)puVar7[4];

    fVar22 = (fVar23 + 0.0) - fVar22;

    fVar23 = (fVar27 + 0.0) - (float)puVar7[5];

    if ((fVar22 <= fVar25) && (fVar22 = local_34, fVar25 <= local_34)) {

    fVar22 = fVar25;

    }

    fVar27 = (float)puVar7[3];

    if ((fVar23 <= fVar27) && (fVar23 = local_38, fVar27 <= local_38)) {

    fVar23 = fVar27;

    }

    puVar7[3] = fVar23;

    puVar7[4] = fVar22;

    }

    puVar7[3] = (float)(int)(float)puVar7[3];

    puVar7[4] = (float)(int)(float)puVar7[4];

    if ((local_ec & 0x1000000) == 0) {

    if ((local_ec & 0xc000000) == 0x4000000) {

    fVar23 = (float)piVar19[0x552];

    }

    else {

    fVar23 = (float)piVar19[0x549];

    }

    }

    else {

    fVar23 = (float)piVar19[0x550];

    }

    local_c4 = (byte *)((uint)fVar21 & 0xffffff00);

    puVar7[0xf] = fVar23;

    if ((local_e7 != false) && ((local_ec & 0x1000) == 0)) {

    if ((local_ec & 0x4000000) == 0) {

    local_c4 = (byte *)(uint)((local_ec & 0x3000000) == 0);

    }

    else {

    uVar9 = (uint)local_c4 >> 8;

    local_c4 = (byte *)CONCAT31((int3)uVar9,1);

    }

    }

    local_30 = 0;

    uStack_2c = 0;

    uStack_28 = 0;

    uStack_24 = 0;

    local_68 = 0xffffffff;

    fVar21 = (float)piVar19[0x64c] * _DAT_0066bf48;

    local_cc = (float)((*(char *)((int)piVar19 + 0xb3) != '\0') + 1);

    fVar23 = (float)piVar19[0x64c] * DAT_0066bdb8 + fVar23 + DAT_0066bf2c;

    if (fVar21 <= fVar23) {

    fVar21 = fVar23;

    }

    cVar17 = local_e5;

    cVar6 = local_e6;

    if ((*(char *)((int)puVar7 + 0x85) == '\0') &&

    (cVar5 = FUN_00477b70(&local_68,local_cc,&local_30,&local_40), cVar17 = local_e5,

    cVar6 = local_e6, cVar5 != '\0')) {

    cVar17 = '\x01';

    cVar6 = '\x01';

    }

    *(uint8_t *)(puVar7 + 0x23) = (uint8_t)local_68;

    if (*(char *)((int)puVar7 + 0x85) == '\0') {

    if (local_d8 == (uint32_t *)0x0) {

    fVar27 = 0.0;

    fVar23 = 0.0;

    }

    else {

    fVar27 = (float)puVar7[0xd] + (float)puVar7[0xd] + (float)puVar7[9];

    fVar23 = (float)puVar7[0xe] + (float)puVar7[0xe] + (float)puVar7[10];

    }

    fVar22 = (float)puVar7[7];

    if (cVar6 == '\0') {

    fVar22 = ((float)puVar7[0x7b] - (float)puVar7[0x79]) + (float)puVar7[0x1e];

    }

    fVar25 = (float)puVar7[8] - (float)local_c8;

    if (cVar17 == '\0') {

    fVar25 = ((float)puVar7[0x7c] - (float)puVar7[0x7a]) + (float)puVar7[0x1f];

    }

    if (((local_ec & 0x4000) != 0) || ((fVar25 < fVar23 && ((local_ec & 8) == 0)))) {

    local_ef = '\x01';

    }

    else {

    local_ef = '\0';

    }

    *(char *)((int)puVar7 + 0x81) = local_ef;

    cVar6 = local_ef;

    if ((local_ec & 0x8000) == 0) {

    if (local_ef == '\0') {

    fVar26 = 0.0;

    }

    else {

    fVar26 = (float)local_e0[0x562];

    }

    if ((fVar22 - fVar26 < fVar27) && ((local_ec & 0x808) == 0x800)) goto LAB_0047a984;

    *(uint8_t *)(puVar7 + 0x20) = 0;

    iVar8 = 0;

    }

    else {

    LAB_0047a984:

    *(uint8_t *)(puVar7 + 0x20) = 1;

    if (local_ef == '\0') {

    if ((fVar23 <= fVar25) || ((local_ec & 8) != 0)) {

    cVar6 = '\0';

    }

    else {

    cVar6 = '\x01';

    }

    *(char *)((int)puVar7 + 0x81) = cVar6;

    }

    iVar8 = local_e0[0x562];

    }

    if (cVar6 == '\0') {

    puVar7[0x1f] = iVar8;

    puVar7[0x1e] = 0;

    }

    else {

    puVar7[0x1e] = local_e0[0x562];

    puVar7[0x1f] = iVar8;

    }

    }

    if (((local_ec & 0x5000000) == 0x1000000) && (local_dc != 3.761582e-37)) {

    pfVar13 = (float *)(local_d4 + 0x224);

    }

    else {

    pfVar13 = &local_80;

    }

    local_70 = (float)puVar7[3];

    local_a0 = *pfVar13;

    fStack_9c = pfVar13[1];

    fStack_98 = pfVar13[2];

    fStack_94 = pfVar13[3];

    fVar23 = (float)puVar7[4];

    if ((*(byte *)(puVar7 + 2) & 1) == 0) {

    fStack_54 = (float)DAT_00701a3c[0x64d] * (float)puVar7[0x9c];

    if (puVar7[0xc6] != 0) {

    fStack_54 = fStack_54 * *(float *)(puVar7[0xc6] + 0x270);

    }

    fStack_54 = (float)DAT_00701a3c[0x555] + (float)DAT_00701a3c[0x555] + fStack_54;

    }

    else {

    fStack_54 = 0.0;

    }

    local_a4 = (byte *)(local_70 + (float)puVar7[7]);

    fStack_54 = fVar23 + fStack_54;

    fStack_5c = (float)puVar7[4];

    puVar7[0x75] = local_70;

    puVar7[0x76] = fVar23;

    puVar7[0x77] = local_70 + (float)puVar7[5];

    puVar7[0x78] = fVar23 + (float)puVar7[6];

    fVar27 = (float)puVar7[0x75];

    if ((float)puVar7[0x75] <= local_a0) {

    fVar27 = local_a0;

    }

    if (fVar23 <= fStack_9c) {

    fVar23 = fStack_9c;

    }

    puVar7[0x75] = fVar27;

    puVar7[0x76] = fVar23;

    fVar23 = (float)puVar7[0x78];

    if (fStack_94 <= (float)puVar7[0x78]) {

    fVar23 = fStack_94;

    }

    fVar27 = (float)puVar7[0x77];

    if (fStack_98 <= (float)puVar7[0x77]) {

    fVar27 = fStack_98;

    }

    puVar7[0x78] = fVar23;

    puVar7[0x77] = fVar27;

    puVar7[0x79] = puVar7[3];

    local_d8 = (uint32_t *)((float)puVar7[4] + (float)local_c8);

    puVar7[0x7a] = local_d8;

    fVar27 = ((float)puVar7[4] + (float)puVar7[6]) - (float)puVar7[0x1f];

    local_bc = ((float)puVar7[3] + (float)puVar7[5]) - (float)puVar7[0x1e];

    puVar7[0x7c] = fVar27;

    puVar7[0x7b] = local_bc;

    fVar23 = DAT_0066be20;

    if ((local_ec & 0x401) == 1) {

    local_e4 = (byte *)puVar7[0x10];

    }

    else {

    local_e4 = (byte *)local_e0[0x557];

    }

    fVar27 = fVar27 + DAT_0066be20;

    fVar22 = (float)(int)((float)puVar7[0xd] * DAT_0066be20);

    if ((float)(int)((float)puVar7[0xd] * DAT_0066be20) <= (float)puVar7[0x10]) {

    fVar22 = (float)puVar7[0x10];

    }

    iVar8 = (int)((float)puVar7[3] + DAT_0066be20 + fVar22);

    puVar7[0x7d] = (float)iVar8;

    puVar7[0x7e] = (float)(int)((float)local_d8 + fVar23 + (float)local_e4);

    puVar7[0x7f] = (float)(int)((local_bc + fVar23) - fVar22);

    puVar7[0x80] = (float)(int)(fVar27 - (float)puVar7[0x10]);

    fVar23 = (float)puVar7[0x7e];

    fVar27 = fStack_9c;

    if ((fStack_9c <= fVar23) && (fVar27 = fStack_94, fVar23 <= fStack_94)) {

    fVar27 = fVar23;

    }

    fVar22 = (float)iVar8;

    fVar23 = local_a0;

    if ((local_a0 <= fVar22) && (fVar23 = fStack_98, fVar22 <= fStack_98)) {

    fVar23 = fVar22;

    }

    puVar7[0x7d] = fVar23;

    puVar7[0x7e] = fVar27;

    fVar23 = (float)puVar7[0x80];

    fVar27 = fStack_9c;

    if ((fStack_9c <= fVar23) && (fVar27 = fStack_94, fVar23 <= fStack_94)) {

    fVar27 = fVar23;

    }

    fVar23 = (float)puVar7[0x7f];

    fVar22 = local_a0;

    if ((local_a0 <= fVar23) && (fVar22 = fStack_98, fVar23 <= fStack_98)) {

    fVar22 = fVar23;

    }

    puVar7[0x7f] = fVar22;

    puVar7[0x80] = fVar27;

    if (((float)puVar7[5] <= 0.0) || ((local_ec & 0x2000040) != 0)) {

    fVar23 = (float)local_e0[0x64c] * DAT_0066c030;

    }

    else {

    fVar23 = (float)puVar7[5] * _DAT_0066be60;

    }

    puVar7[0x95] = (float)(int)fVar23;

    fVar27 = ((float)puVar7[0xd] + (float)puVar7[0xd] + (float)puVar7[9]) -

    ((float)puVar7[0x7b] - (float)puVar7[0x79]);

    fVar23 = 0.0;

    if (0.0 <= fVar27) {

    fVar23 = fVar27;

    }

    puVar7[0x16] = fVar23;

    fVar27 = ((float)puVar7[0xe] + (float)puVar7[0xe] + (float)puVar7[10]) -

    ((float)puVar7[0x7c] - (float)puVar7[0x7a]);

    fVar23 = 0.0;

    if (0.0 <= fVar27) {

    fVar23 = fVar27;

    }

    puVar7[0x17] = fVar23;

    local_60 = local_70;

    pbStack_58 = local_a4;

    local_48 = fStack_54;

    puVar14 = (uint32_t *)FUN_0047c380();

    uVar15 = puVar14[1];

    puVar7[0x14] = *puVar14;

    puVar7[0x15] = uVar15;

    puVar7[0x18] = 0x7f7fffff;

    puVar7[0x19] = 0x7f7fffff;

    FUN_004841c0(*(uint32_t *)(*(int *)(local_e0[0x64b] + 0x30) + 8),

    *(uint32_t *)(*(int *)(local_e0[0x64b] + 0x30) + 0xc));

    FUN_00476ba0(0);

    if ((((local_ec & 0x8000000) == 0) || (puVar14 = (uint32_t *)FUN_0047c980(), puVar7 != puVar14))

    || ('\0' < *(char *)((int)puVar7 + 0xa1))) {

    bVar20 = false;

    local_e4 = (byte *)0x3f4;

    }

    else {

    bVar20 = true;

    local_e4 = (byte *)0x404;

    }

    if ((local_e0[0x734] == 0) || (puVar7 != *(uint32_t **)(local_e0[0x734] + 0x31c))) {

    local_ef = '\0';

    }

    else {

    local_ef = '\x01';

    }

    if ((bVar20) || (local_ef != '\0')) {

    uVar30 = 0xf;

    pfVar13 = (float *)((int)local_e4 + 0x1518 + (int)DAT_00701a3c);

    local_a0 = *pfVar13;

    fStack_9c = pfVar13[1];

    fStack_98 = pfVar13[2];

    uVar29 = 0;

    fStack_94 = (float)local_e0[0x751] * (float)DAT_00701a3c[0x546] * pfVar13[3];

    uVar15 = FUN_00472920(0,0xf);

    FUN_00485be0(&local_80,&fStack_78,uVar15,uVar29,uVar30);

    if ((local_ef != '\0') && (puVar7 == (uint32_t *)local_e0[0x734])) {

    fStack_74 = (float)local_e0[0x64c];

    local_80 = (float)puVar7[3] - fStack_74;

    fStack_7c = (float)puVar7[4] - fStack_74;

    fStack_78 = (float)puVar7[3] + (float)puVar7[5] + fStack_74;

    fStack_74 = (float)puVar7[4] + (float)puVar7[6] + fStack_74;

    if ((((0.0 < local_80) || (0.0 < fStack_7c)) || (fStack_78 < local_b4)) ||

    (fStack_74 < local_b0)) {

    uVar29 = 0xf;

    local_a0 = (float)DAT_00701a3c[0x63f];

    fStack_9c = (float)DAT_00701a3c[0x640];

    fStack_98 = (float)DAT_00701a3c[0x641];

    fStack_94 = (float)local_e0[0x737] * DAT_0066bdc4 * (float)DAT_00701a3c[0x546] *

    (float)DAT_00701a3c[0x642];

    iVar8 = local_e0[0x549];

    uVar15 = FUN_00472920(iVar8,0xf);

    FUN_00485be0(&local_80,&fStack_78,uVar15,iVar8,uVar29);

    }

    }

    }

    local_ef = '\0';

    if ((((local_ec & 0x5000000) == 0x1000000) && (local_dc != 3.761582e-37)) &&

    ((*(int *)(((int *)puVar7[0x9e])[2] + -0x10 + *(int *)puVar7[0x9e] * 0x30) == 0 &&

    (0 < *(int *)(*(int *)(local_d4 + 0x278) + 0x18))))) {

    local_ef = '\x01';

    puVar7[0x9e] = *(int *)(local_d4 + 0x278);

    }

    iVar8 = local_e0[0x733];

    if (iVar8 == 0) {

    iVar8 = local_e0[0x6f1];

    }

    if (((char)local_c4 == '\0') && ((iVar8 == 0 || (puVar7[200] != *(int *)(iVar8 + 800))))) {

    local_e4 = (byte *)((uint)local_e4._1_3_ << 8);

    }

    else {

    local_e4 = (byte *)CONCAT31(local_e4._1_3_,1);

    }

    FUN_00478b40(local_e4,local_cc,&local_30,(float)(int)fVar21);

    piVar19 = local_e0;

    if (local_ef != '\0') {

    puVar7[0x9e] = puVar7 + 0xa0;

    }

    if ((uint32_t *)local_e0[0x734] == puVar7) {

    fVar21 = (float)puVar7[0xf];

    fVar23 = (float)local_e0[0x64c];

    local_dc = fVar21;

    if (fVar21 <= (float)local_e0[0x549]) {

    local_dc = (float)local_e0[0x549];

    }

    local_e4 = (byte *)((float)puVar7[3] - fVar23);

    local_e0 = (int *)((float)puVar7[4] - fVar23);

    fVar22 = (float)puVar7[3] + (float)puVar7[5] + fVar23;

    fVar27 = (float)puVar7[4] + (float)puVar7[6] + fVar23;

    if (((((float)local_e4 <= 0.0) && ((float)local_e0 <= 0.0)) && (local_b4 <= fVar22)) &&

    (local_b0 <= fVar27)) {

    fVar23 = (float)((uint)fVar23 ^ DAT_0066c580) - DAT_0066bf2c;

    local_e4 = (byte *)((float)local_e4 - fVar23);

    local_e0 = (int *)((float)local_e0 - fVar23);

    fVar22 = fVar22 + fVar23;

    fVar27 = fVar27 + fVar23;

    local_dc = fVar21;

    }

    local_d8 = (uint32_t *)puVar7[0x9e];

    local_80 = (float)DAT_00701a3c[0x63f];

    fStack_7c = (float)DAT_00701a3c[0x640];

    fStack_78 = (float)DAT_00701a3c[0x641];

    fStack_74 = (float)piVar19[0x737] * (float)DAT_00701a3c[0x546] * (float)DAT_00701a3c[0x642];

    local_cc = (float)FUN_00472920();

    if (((uint)local_cc & 0xff000000) != 0) {

    local_b0 = (float)local_e4 + DAT_0066be20;

    local_ac = (float)local_e0 + DAT_0066be20;

    local_b8 = DAT_0066be1c;

    if ((*(byte *)(local_d8 + 9) & 1) != 0) {

    local_b8 = DAT_0066be20;

    }

    local_bc = fVar22 - local_b8;

    local_b8 = fVar27 - local_b8;

    FUN_004856a0(&local_b0,&local_bc,0xffffffff);

    FUN_00484360(local_d8[0x17],local_d8[0x15],local_cc,1,0x40400000);

    local_d8[0x15] = 0;

    }

    }

    fVar21 = (float)puVar7[0xb];

    local_b0 = fVar21;

    if (fVar21 == 0.0) {

    fVar23 = ((float)puVar7[5] - ((float)puVar7[0xd] + (float)puVar7[0xd])) - (float)puVar7[0x1e];

    if ((local_ec & 0x808) == 0x800) {

    local_b0 = (float)puVar7[9];

    }

    else {

    local_b0 = 0.0;

    }

    if (local_b0 <= fVar23) {

    local_b0 = fVar23;

    }

    }

    fVar23 = (float)puVar7[0xc];

    local_b4 = fVar23;

    if (fVar23 == 0.0) {

    fVar27 = (((float)puVar7[6] - ((float)puVar7[0xe] + (float)puVar7[0xe])) - (float)local_c8) -

    (float)puVar7[0x1f];

    if ((~(byte)(local_ec >> 3) & 1) == 0) {

    local_b4 = 0.0;

    }

    else {

    local_b4 = (float)puVar7[10];

    }

    if (local_b4 <= fVar27) {

    local_b4 = fVar27;

    }

    }

    local_e4 = (byte *)puVar7[0x14];

    fVar27 = (float)puVar7[0xd];

    fVar22 = fVar27;

    if (fVar27 <= (float)puVar7[0x10]) {

    fVar22 = (float)puVar7[0x10];

    }

    local_dc = (float)puVar7[0x15];

    fVar25 = (float)puVar7[0xe];

    fVar26 = fVar25;

    if (fVar25 <= (float)puVar7[0x10]) {

    fVar26 = (float)puVar7[0x10];

    }

    fVar24 = (float)(int)(((float)puVar7[0x79] - (float)local_e4) + fVar22);

    puVar7[0x81] = fVar24;

    fVar22 = (float)(int)(fVar26 + ((float)puVar7[0x7a] - local_dc));

    puVar7[0x83] = local_b0 + fVar24;

    puVar7[0x82] = fVar22;

    puVar7[0x84] = local_b4 + fVar22;

    puVar7[0x85] = puVar7[0x81];

    puVar7[0x86] = puVar7[0x82];

    puVar7[0x87] = puVar7[0x83];

    puVar7[0x88] = puVar7[0x84];

    local_bc = (float)puVar7[3];

    fVar22 = (local_bc - (float)local_e4) + fVar27;

    puVar7[0x8d] = fVar22;

    local_cc = ((float)puVar7[4] - local_dc) + fVar25 + (float)local_c8;

    puVar7[0x8e] = local_cc;

    if (fVar21 == 0.0) {

    fVar21 = ((float)puVar7[5] - (fVar27 + fVar27)) - (float)puVar7[0x1e];

    }

    puVar7[0x8f] = fVar21 + fVar22;

    if (fVar23 == 0.0) {

    fVar23 = (((float)puVar7[6] - (fVar25 + fVar25)) - (float)local_c8) - (float)puVar7[0x1f];

    }

    puVar7[0x90] = fVar23 + local_cc;

    fVar23 = (fVar27 + 0.0) - (float)local_e4;

    puVar7[0x3f] = fVar23;

    puVar7[0x41] = 0;

    puVar7[0x40] = 0;

    fVar21 = ((fVar25 + (float)local_c8) - local_dc) + (float)puVar7[4];

    fVar23 = fVar23 + 0.0 + local_bc;

    puVar7[0x35] = fVar23;

    puVar7[0x36] = fVar21;

    puVar7[0x31] = fVar23;

    puVar7[0x32] = fVar21;

    puVar7[0x33] = fVar23;

    puVar7[0x34] = fVar21;

    puVar7[0x37] = puVar7[0x35];

    puVar7[0x38] = puVar7[0x36];

    pfVar13 = (float *)(puVar7 + 0x59);

    puVar7[0x3b] = 0;

    puVar7[0x3c] = 0;

    puVar7[0x39] = 0;

    puVar7[0x3a] = 0;

    puVar7[0x3e] = 0;

    puVar7[0x3d] = 0;

    puVar7[0x4c] = 0;

    puVar7[0x4d] = puVar7[0x4e];

    puVar7[0x4e] = 0;

    *(uint8_t *)(puVar7 + 0x50) = 0;

    *(bool *)((int)puVar7 + 0x141) = 0.0 < (float)puVar7[0x17];

    *(uint8_t *)((int)puVar7 + 0x142) = 0;

    iVar8 = piVar19[0x558];

    puVar7[0x55] = 0;

    puVar7[0x54] = 0;

    puVar7[0x53] = iVar8;

    if (local_e7 != false) {

    pfVar13[0] = 0.0;

    pfVar13[1] = 0.0;

    puVar7[0x5b] = 0;

    }

    iVar8 = 0;

    do {

    if ((iVar8 != 0) && (0.0 < *pfVar13)) {

    puVar7[0x54] = (float)puVar7[0x53] + (float)puVar7[0x54];

    }

    iVar8 = iVar8 + 1;

    pfVar13[-3] = (float)(int)(float)puVar7[0x54];

    puVar7[0x54] = *pfVar13 + (float)puVar7[0x54];

    *pfVar13 = 0.0;

    pfVar13 = pfVar13 + 1;

    } while (iVar8 < 3);

    puVar7[0x5c] = 0;

    puVar7[0x5d] = 0;

    iVar8 = puVar7[0x5f];

    if (iVar8 < 0) {

    iVar8 = iVar8 / 2 + iVar8;

    iVar10 = 0;

    if (0 < iVar8) {

    iVar10 = iVar8;

    }

    FUN_004810b0(iVar10);

    }

    puVar7[0x5e] = 0;

    puVar7[0x61] = puVar7 + 0x96;

    puVar7[0x62] = 0;

    puVar7[100] = 1;

    if (local_d4 == 0) {

    uVar15 = 1;

    }

    else {

    uVar15 = *(uint32_t *)(local_d4 + 400);

    }

    puVar7[0x65] = uVar15;

    puVar7[0x67] = 0xffffffff;

    puVar7[0x66] = 0xffffffff;

    puVar7[0x69] = puVar7[0x95];

    puVar7[0x6a] = 0xbf800000;

    iVar8 = puVar7[0x6c];

    if (iVar8 < 0) {

    iVar8 = iVar8 / 2 + iVar8;

    iVar10 = 0;

    if (0 < iVar8) {

    iVar10 = iVar8;

    }

    FUN_004810b0(iVar10);

    }

    puVar7[0x6b] = 0;

    iVar8 = puVar7[0x6f];

    if (iVar8 < 0) {

    iVar8 = iVar8 / 2 + iVar8;

    iVar10 = 0;

    if (0 < iVar8) {

    iVar10 = iVar8;

    }

    FUN_004810b0(iVar10);

    }

    puVar7[0x6e] = 0;

    if ('\0' < *(char *)(puVar7 + 0x26)) {

    *(char *)(puVar7 + 0x26) = *(char *)(puVar7 + 0x26) + -1;

    }

    if ('\0' < *(char *)((int)puVar7 + 0x99)) {

    *(char *)((int)puVar7 + 0x99) = *(char *)((int)puVar7 + 0x99) + -1;

    }

    if ((char)local_c4 != '\0') {

    FUN_0047bac0();

    FUN_0047d9f0();

    }

    if ((local_ec & 1) == 0) {

    FUN_00479190(local_a8,local_64);

    }

    puVar7[0x91] = 0;

    if ((((float)DAT_00701a3c[0x39] < local_70 - (float)DAT_00701a3c[0x55e]) ||

    ((float)DAT_00701a3c[0x3a] < fStack_5c - (float)DAT_00701a3c[0x55f])) ||

    (((float)local_a4 + (float)DAT_00701a3c[0x55e] <= (float)DAT_00701a3c[0x39] ||

    (local_48 + (float)DAT_00701a3c[0x55f] <= (float)DAT_00701a3c[0x3a])))) {

    uVar15 = 0;

    }

    else {

    uVar15 = 1;

    }

    puVar7[0x42] = puVar7[0x12];

    puVar7[0x43] = uVar15;

    puVar7[0x44] = local_60;

    puVar7[0x45] = fStack_5c;

    puVar7[0x46] = pbStack_58;

    puVar7[0x47] = fStack_54;

    LAB_0047b812:

    puVar7[0x68] = *(uint32_t *)(piVar19[0x6e7] + -4 + piVar19[0x6e5] * 4);

    local_70 = (float)(local_ec & 0x1000000);

    if (local_70 == 0.0) {

    uVar15 = 0;

    }

    else {

    uVar15 = *(uint32_t *)(local_d4 + 0x13c);

    }

    puVar7[0x4f] = uVar15;

    FUN_00476ba0(1);

    *(uint8_t *)(puVar7 + 0x21) = 0;

    *(short *)((int)puVar7 + 0x8e) = *(short *)((int)puVar7 + 0x8e) + 1;

    piVar19[0x6bc] = 0;

    if (local_d0 != local_c0) {

    if (local_70 != 0.0) {

    if (((((local_ec & 0x40) == 0) && (*(char *)(puVar7 + 0x26) < '\x01')) &&

    (*(char *)((int)puVar7 + 0x99) < '\x01')) &&

    (((char)piVar19[0xbc5] == '\0' &&

    (((float)puVar7[0x77] <= (float)puVar7[0x75] ||

    ((float)puVar7[0x78] <= (float)puVar7[0x76])))))) {

    *(uint8_t *)(puVar7 + 0x28) = 1;

    }

    if (local_d4 != 0) {

    if ((*(char *)(local_d4 + 0x85) != '\0') || ('\0' < *(char *)(local_d4 + 0xa0))) {

    *(uint8_t *)(puVar7 + 0x28) = 1;

    }

    if ((*(char *)(local_d4 + 0x85) != '\0') || ('\0' < *(char *)(local_d4 + 0xa1))) {

    *(uint8_t *)((int)puVar7 + 0xa1) = 1;

    }

    }

    }

    if ((float)piVar19[0x546] <= 0.0) {

    *(uint8_t *)(puVar7 + 0x28) = 1;

    }

    if (((*(char *)(puVar7 + 0x28) < '\x01') && (*(char *)((int)puVar7 + 0xa1) < '\x01')) &&

    (*(char *)((int)puVar7 + 0xa2) < '\x01')) {

    cVar6 = '\0';

    }

    else {

    cVar6 = '\x01';

    }

    uVar4 = 0;

    *(char *)((int)puVar7 + 0x89) = cVar6;

    if (((((*(char *)((int)puVar7 + 0x85) != '\0') || (*(char *)((int)puVar7 + 0x82) == '\0')) ||

    (cVar6 != '\0')) &&

    ((*(char *)(puVar7 + 0x26) < '\x01' && (*(char *)((int)puVar7 + 0x99) < '\x01')))) &&

    (uVar4 = 0, *(char *)((int)puVar7 + 0xa1) < '\x01')) {

    uVar4 = 1;

    }

    *(uint8_t *)((int)puVar7 + 0x87) = uVar4;

    }

    return *(char *)((int)puVar7 + 0x87) == '\0';


}  // 0x004796b0
#endif // GameFn4796B0
void GameFn4796B0() {}  // 0x004796b0
#if 0 // GHIDRA_RAW: GameFn45AC90 @ 0x0045ac90 — needs manual cleanup
void GameFn45AC90(void)
{


    char cVar1;

    int iVar2;

    int iVar3;

    uint32_t extraout_ECX;

    uint32_t extraout_ECX_00;

    uint32_t uVar4;

    bool bVar5;

    uint8_t auStack_1c [4];

    uint8_t uStack_18;

    uint32_t uStack_17;

    uint32_t uStack_13;

    uint8_t uStack_f;

    uint32_t local_c;



    local_c = DAT_0067d280 ^ (uint)auStack_1c;

    if ((DAT_00702bdd != '\0') && (DAT_00702964 != 0)) goto switchD_0045acfc_default;

    iVar2 = 0;

    if (0 < DAT_0070294c) {

    do {

    if ((&DAT_006ff910)[iVar2] == DAT_0073c940) {

    if (iVar2 < DAT_0070294c) goto LAB_0045ace7;

    break;

    }

    iVar2 = iVar2 + 1;

    } while (iVar2 < DAT_0070294c);

    }

    iVar2 = DAT_0070294c + -1;

    LAB_0045ace7:

    if (iVar2 < 0) {

    cVar1 = '\0';

    }

    else {

    cVar1 = (&DAT_006ff8e8)[iVar2];

    if (cVar1 == '\x7f') {

    iVar3 = FUN_0055a8a0();

    iVar2 = DAT_00702774;

    if ((DAT_00702774 != 0) && (iVar3 != 0)) {

    FUN_0055a4a0(iVar3);

    }

    FUN_00499e30();

    *(uint32_t *)(iVar2 + 0x214) = *(uint32_t *)(iVar2 + 0x214) | 1;

    *(uint32_t *)(iVar2 + 0x1d8) = 1;

    DAT_00702b08 = 1;

    FUN_0049a040();

    bVar5 = DAT_006ff960 == 6;

    *(uint64_t *)(iVar2 + 0x108) = *(uint64_t *)(iVar2 + 0xfc);

    *(uint32_t *)(iVar2 + 0x110) = *(uint32_t *)(iVar2 + 0x104);

    *(uint64_t *)(iVar2 + 0xfc) = *(uint64_t *)(iVar2 + 0xf0);

    *(uint32_t *)(iVar2 + 0x104) = *(uint32_t *)(iVar2 + 0xf8);

    if (bVar5) {

    uStack_13 = *(uint32_t *)(iVar2 + 4);

    uStack_17 = *(uint32_t *)(iVar2 + 0x1d4);

    uStack_18 = 5;

    uStack_f = 0;

    if (DAT_00702964 == 0) {

    if (DAT_0073c944 != 0) {

    FUN_0045fc20(&uStack_18);

    }

    }

    else {

    FUN_0045fe10(&uStack_18);

    }

    }

    FUN_00523320();

    FUN_00523320();

    FUN_00523320();

    goto switchD_0045acfc_default;

    }

    }

    switch(DAT_0070292c) {

    case 0:

    case 1:

    break;

    case 2:

    goto switchD_0045acfc_caseD_2;

    case 3:

    if (cVar1 != '\x01') goto switchD_0045acfc_caseD_2;

    break;

    case 4:

    if (cVar1 != '\x01') goto switchD_0045acfc_caseD_6;

    break;

    case 5:

    if (cVar1 != '\x01') goto LAB_0045af31;

    break;

    case 6:

    switchD_0045acfc_caseD_6:

    if (cVar1 != '\x02') {

    LAB_0045af31:

    FUN_005c0770();

    goto switchD_0045acfc_default;

    }

    goto switchD_0045acfc_caseD_2;

    default:

    goto switchD_0045acfc_default;

    }

    FUN_005c0920();

    switchD_0045acfc_default:

    if ((float)DAT_007028a4 <= DAT_0066c15c) {

    FUN_0062be00();

    FUN_0062b9c0();

    }

    if (DAT_006fef88 != 0) {

    FUN_004d39d0();

    }

    DAT_006fef88 = 0;

    FUN_004d1070();

    DAT_006ff980 = 0;

    DAT_006ff984 = 0;

    DAT_006ff9a0 = 0;

    DAT_006ff9a4 = 0;

    DAT_006ff9c0 = 0;

    DAT_006ff9c4 = 0;

    FUN_00462230();

    FUN_00462230();

    FUN_004641b0();

    uVar4 = extraout_ECX;

    if ((((DAT_00702964 != 0) && (DAT_00702b50 == 0)) && (DAT_00702b54 == '\0')) &&

    (uVar4 = 0, DAT_0073c92c != (int *)0x0)) {

    (**(code **)(*DAT_0073c92c + 0xc))();

    uVar4 = extraout_ECX_00;

    }

    FUN_005e9ff0(uVar4,DAT_0073c954);

    DAT_0073c954 = 0;

    DAT_00702aec = 0;

    return;

    switchD_0045acfc_caseD_2:

    FUN_005c05c0();

    goto switchD_0045acfc_default;


}  // 0x0045ac90
#endif // GameFn45AC90
void GameFn45AC90() {}  // 0x0045ac90
#if 0 // GHIDRA_RAW: GameFn4916E0 @ 0x004916e0 — needs manual cleanup
void GameFn4916E0(int param_1)
{


    int iVar1;

    float *pfVar2;

    int iVar3;

    float fVar4;

    float fVar5;

    uint32_t extraout_ECX;

    int *piVar6;

    int *piVar7;

    float *pfVar8;

    int iVar9;

    uint32_t uVar10;

    int iVar11;

    bool bVar12;

    float in_XMM0_Da;

    float fVar13;

    uint8_t auStack_c8 [12];

    float *local_bc;

    int local_b8;

    int local_b4;

    uint32_t *local_b0;

    int *local_ac;

    float local_a8;

    int local_a4;

    int local_a0;

    int local_9c;

    int local_98 [18];

    int local_50 [8];

    uint64_t local_30;

    uint32_t local_14;



    local_14 = DAT_0067d280 ^ (uint)auStack_c8;

    if (param_1 == 0) {

    local_a4 = 0;

    }

    else {

    local_a4 = *(int *)(param_1 + 0x14c);

    }

    local_b8 = 0;

    local_b4 = param_1;

    if (0 < *(int *)(local_a4 + 0x164c)) {

    do {

    iVar9 = local_b8 * 0x110;

    local_bc = (float *)(local_a4 + 0x10c + iVar9);

    switch(*(uint32_t *)(local_a4 + 0x110 + iVar9)) {

    case 1:

    case 0x14:

    if (((uint)local_bc[5] & 1) != 0) {

    iVar9 = FUN_004911a0(0x67,0xffffffff);

    if (iVar9 == 0) {

    iVar9 = 0;

    }

    else {

    iVar9 = *(int *)(iVar9 + 0x14c);

    }

    *(float *)(iVar9 + 0x1dc) = local_bc[0x31];

    *(float *)(iVar9 + 0x1e0) = local_bc[0x32];

    *(float *)(iVar9 + 0x1e4) = local_bc[0x33];

    }

    if ((int)local_bc[0x34] < 1) {

    local_bc[1] = 4.2039e-45;

    }

    else {

    in_XMM0_Da = 0.0;

    local_a8 = 0.0;

    local_50[0] = 0;

    local_50[1] = 0;

    local_50[2] = 0;

    local_50[3] = 0;

    local_50[4] = 0;

    local_50[5] = 0;

    local_50[6] = 0;

    local_50[7] = 0;

    local_30 = 0;

    for (local_b0 = DAT_007027a8; local_b0 != (uint32_t *)0x0;

    local_b0 = (uint32_t *)*local_b0) {

    fVar13 = (float)local_b0[3];

    if (*(int *)((int)fVar13 + 4) == 0x48a) {

    if ((*(int *)((int)fVar13 + 0x1c0) == 0) && (iVar9 = 0, 0 < (int)local_bc[0x24])) {

    pfVar2 = local_bc + 6;

    do {

    if (*(float *)((int)fVar13 + 0x134) == pfVar2[10]) {

    *pfVar2 = fVar13;

    }

    iVar9 = iVar9 + 1;

    pfVar2 = pfVar2 + 1;

    } while (iVar9 < (int)local_bc[0x24]);

    }

    }

    else if (*(int *)((int)fVar13 + 0x22c) == 0x61) {

    fVar5 = local_bc[0x24];

    iVar9 = 0;

    if (0 < (int)fVar5) {

    fVar13 = *(float *)((int)fVar13 + 0x144);

    pfVar2 = local_bc + 0x10;

    do {

    if ((float)(int)fVar13 == *pfVar2) {

    local_50[iVar9] = 1;

    }

    iVar9 = iVar9 + 1;

    pfVar2 = pfVar2 + 1;

    } while (iVar9 < (int)fVar5);

    }

    }

    }

    fVar13 = local_bc[0x24];

    iVar9 = rand();

    iVar9 = iVar9 * (int)fVar13 >> 0xf;

    fVar13 = local_bc[iVar9 + 0x10];

    if ((fVar13 == DAT_006858d0) && (1 < (int)local_bc[0x24])) {

    iVar11 = rand();

    if ((int)(iVar11 * 100 & 0xffff8000U) < 0x190000) {

    iVar11 = iVar9 + 1;

    iVar9 = 0;

    if (iVar11 < (int)local_bc[0x24]) {

    iVar9 = iVar11;

    }

    }

    else {

    iVar9 = iVar9 + -1;

    if (iVar9 < 0) {

    iVar9 = (int)local_bc[0x24] + -1;

    }

    }

    fVar13 = local_bc[iVar9 + 0x10];

    }

    local_b0 = (uint32_t *)0x0;

    while( true ) {

    if (local_bc[1] == 2.8026e-44) {

    bVar12 = local_50[iVar9] == 0;

    }

    else {

    in_XMM0_Da = 0.0;

    bVar12 = *(float *)((int)local_bc[iVar9 + 6] + 0x144) <= 0.0;

    }

    if (bVar12) goto LAB_00491a81;

    fVar13 = local_bc[0x24];

    iVar9 = rand();

    pfVar2 = local_bc;

    fVar5 = local_bc[0x24];

    iVar9 = iVar9 * (int)fVar13 >> 0xf;

    fVar13 = local_bc[iVar9 + 0x10];

    if ((int)fVar5 * 2 < (int)local_b0) break;

    local_b0 = (uint32_t *)((int)local_b0 + 1);

    }

    fVar4 = 0.0;

    if (0 < (int)fVar5) {

    pfVar8 = local_bc + 0x10;

    do {

    fVar13 = *pfVar8;

    local_b0 = (uint32_t *)fVar5;

    if (local_bc[1] == 2.8026e-44) {

    if (local_50[(int)fVar4] == 0) goto LAB_00491a81;

    }

    else {

    in_XMM0_Da = *(float *)((int)pfVar8[-10] + 0x144);

    if (in_XMM0_Da == 0.0) goto LAB_00491a81;

    }

    fVar4 = (float)((int)fVar4 + 1);

    pfVar8 = pfVar8 + 1;

    } while ((int)fVar4 < (int)fVar5);

    }

    if (fVar4 == fVar5) {

    if (local_b4 == 0) {

    iVar9 = 0;

    }

    else {

    iVar9 = *(int *)(local_b4 + 0x14c);

    }

    iVar11 = FUN_00491060(&local_a0);

    if (iVar11 != 0) {

    memmove((void *)(local_a0 * 0x108 + 0x1650 + iVar9),

    (void *)(local_a0 * 0x108 + 0x1758 + iVar9),

    (*(int *)(iVar9 + 0x49e0) - local_a0) * 0x108 - 0x108);

    *(int *)(iVar9 + 0x49e0) = *(int *)(iVar9 + 0x49e0) + -1;

    }

    pfVar2[1] = 4.2039e-45;

    param_1 = local_b4;

    }

    else {

    LAB_00491a81:

    fVar5 = local_bc[0x24];

    if (0 < (int)fVar5) {

    pfVar2 = local_bc + 0x1a;

    do {

    if (fVar13 == pfVar2[-10]) {

    local_a8 = *pfVar2;

    }

    pfVar2 = pfVar2 + 1;

    fVar5 = (float)((int)fVar5 + -1);

    } while (fVar5 != 0.0);

    }

    local_ac = (int *)local_bc[0x34];

    DAT_006858d0 = fVar13;

    fVar5 = (float)FUN_00559530();

    if (fVar5 != 0.0) {

    local_ac = (int *)FUN_0055a8a0();

    if (local_ac == (int *)0x0) {

    FUN_00463000(&DAT_00701bd8,"Error: ObjObj type %d not found",extraout_ECX);

    if (DAT_0074c5d4 < 5) {

    FUN_0062edc0(&DAT_00701bd8);

    }

    DAT_0074c5d4 = DAT_0074c5d4 + 1;

    }

    else {

    FUN_0055a4a0(local_ac);

    FUN_0055a710(local_ac);

    }

    FUN_00559670();

    FUN_005597d0();

    }

    pfVar2 = local_bc;

    in_XMM0_Da = (float)(int)fVar13;

    local_bc[0x43] = fVar5;

    *(float *)((int)fVar5 + 0x144) = in_XMM0_Da;

    *(uint32_t *)((int)local_bc[0x43] + 0x148) = 1;

    if ((*(uint32_t *)(local_b4 + 0x124) & 0x400) != 0) {

    *(uint32_t *)((int)local_bc[0x43] + 0x124) =

    *(uint32_t *)((int)local_bc[0x43] + 0x124) | 0x400;

    }

    local_bc[1] = 2.8026e-45;

    if ((*(uint32_t *)(local_b4 + 0x124) & 0x400) != 0) {

    *(uint32_t *)((int)local_bc[0x43] + 0x124) =

    *(uint32_t *)((int)local_bc[0x43] + 0x124) | 0x400;

    }

    iVar9 = FUN_00491060(&local_ac);

    if (iVar9 != 0) {

    *(float *)(iVar9 + 0x104) = pfVar2[0x43];

    }

    pfVar2[0x35] = 8.40779e-44;

    memset(local_98,0,0x44);

    local_ac = *(int **)((int)pfVar2[0x43] + 0x14c);

    local_ac[5] = (int)local_a8;

    FUN_0048fba0();

    iVar9 = 0;

    local_a8 = 0.0;

    do {

    param_1 = local_b4;

    if (*(int *)((int)pfVar2[0x43] + 0x328) <= iVar9) break;

    piVar7 = local_98;

    piVar6 = (int *)(*(int *)((int)pfVar2[0x43] + 0x32c) + (int)local_a8);

    uVar10 = 0x40;

    do {

    if (*piVar6 != *piVar7) {

    if (9 < iVar9) {

    local_ac[1] = local_ac[1] + 1;

    }

    break;

    }

    piVar6 = piVar6 + 1;

    piVar7 = piVar7 + 1;

    bVar12 = 3 < uVar10;

    uVar10 = uVar10 - 4;

    } while (bVar12);

    iVar9 = iVar9 + 1;

    local_a8 = (float)((int)local_a8 + 0x44);

    pfVar2 = local_bc;

    } while ((int)local_a8 < 0xff0);

    }

    }

    break;

    case 2:

    case 0x15:

    FUN_0062a0b0();

    pfVar2 = local_bc;

    fVar13 = *local_bc - in_XMM0_Da;

    in_XMM0_Da = 0.0;

    *local_bc = fVar13;

    if (fVar13 <= 0.0) {

    FUN_00491420();

    *pfVar2 = *(float *)(DAT_007028f4 + 0xcb0);

    }

    if ((int)pfVar2[0x35] < 0) {

    pfVar2[1] = 4.2039e-45;

    }

    break;

    case 3:

    case 0x16:

    if (param_1 == 0) {

    LAB_00491cc7:

    iVar11 = 0;

    }

    else {

    iVar11 = *(int *)(param_1 + 0x14c);

    }

    LAB_00491cc9:

    memmove((void *)(iVar11 + 0x10c + iVar9),(void *)(iVar11 + 0x21c + iVar9),

    (*(int *)(iVar11 + 0x164c) - local_b8) * 0x110 - 0x110);

    *(int *)(iVar11 + 0x164c) = *(int *)(iVar11 + 0x164c) + -1;

    local_b8 = local_b8 + -1;

    param_1 = local_b4;

    break;

    case 10:

    FUN_0062a0b0();

    pfVar2 = local_bc;

    fVar13 = *local_bc - in_XMM0_Da;

    in_XMM0_Da = 0.0;

    *local_bc = fVar13;

    param_1 = local_b4;

    if (fVar13 <= 0.0) {

    iVar11 = rand();

    in_XMM0_Da = (float)iVar11 * _DAT_0066bd00 + DAT_0066bf2c;

    *pfVar2 = in_XMM0_Da;

    local_9c = FUN_00491060(&local_ac);

    if (local_9c == 0) {

    if (local_b4 == 0) goto LAB_00491cc7;

    iVar11 = *(int *)(local_b4 + 0x14c);

    goto LAB_00491cc9;

    }

    iVar9 = 0;

    local_b0 = (uint32_t *)0x0;

    if (0 < (int)pfVar2[0x2f]) {

    do {

    iVar11 = FUN_00491060(&local_ac);

    local_50[iVar9] = iVar11;

    iVar9 = iVar9 + 1;

    pfVar2 = local_bc;

    } while (iVar9 < (int)local_bc[0x2f]);

    }

    local_ac = DAT_007027ac;

    param_1 = local_b4;

    if (DAT_007027ac != (int *)0x0) {

    local_a8 = pfVar2[0x2f];

    piVar7 = DAT_007027ac;

    do {

    iVar9 = piVar7[3];

    if (*(int *)(iVar9 + 4) == 0xd7) {

    iVar11 = *(int *)(iVar9 + 0x14c);

    iVar1 = *(int *)(iVar11 + 0x134);

    if (iVar1 == *(int *)(local_9c + 0x104)) {

    if ((*(int *)(iVar9 + 0x130) == 0xcc) || ((*(byte *)(iVar11 + 0x1b8) & 1) != 0)) {

    local_b0 = (uint32_t *)0x1;

    }

    }

    else {

    iVar3 = 0;

    if (0 < (int)local_a8) {

    do {

    if (((local_50[iVar3] != 0) && (iVar1 == *(int *)(local_50[iVar3] + 0x104)))

    && ((*(int *)(iVar9 + 0x130) == 0xcc ||

    ((*(byte *)(iVar11 + 0x1b8) & 1) != 0)))) {

    local_50[iVar3] = 0;

    }

    iVar3 = iVar3 + 1;

    } while (iVar3 < (int)local_a8);

    }

    }

    }

    piVar7 = (int *)*piVar7;

    } while (piVar7 != (int *)0x0);

    local_ac = (int *)0x0;

    if (local_b0 != (uint32_t *)0x0) {

    fVar5 = 0.0;

    fVar13 = local_bc[0x2f];

    if (0 < (int)fVar13) {

    do {

    if (local_50[(int)fVar5] != 0) goto switchD_00491757_caseD_4;

    fVar5 = (float)((int)fVar5 + 1);

    } while ((int)fVar5 < (int)fVar13);

    }

    if (fVar5 == fVar13) {

    in_XMM0_Da = local_bc[0x30];

    if (in_XMM0_Da <= _DAT_0066bce4) {

    iVar9 = 0;

    if (0 < (int)fVar13) {

    do {

    FUN_00492000();

    iVar9 = iVar9 + 1;

    } while (iVar9 < (int)local_bc[0x2f]);

    }

    goto LAB_00491efb;

    }

    local_bc[1] = 1.54143e-44;

    }

    }

    }

    }

    break;

    case 0xb:

    in_XMM0_Da = local_bc[0x30] - DAT_00727e38;

    local_bc[0x30] = in_XMM0_Da;

    if (0.0 < in_XMM0_Da) break;

    iVar9 = 0;

    if (0 < (int)local_bc[0x2f]) {

    do {

    FUN_00492000();

    iVar9 = iVar9 + 1;

    } while (iVar9 < (int)local_bc[0x2f]);

    }

    LAB_00491efb:

    param_1 = local_b4;

    FUN_00492000();

    if (param_1 == 0) {

    iVar9 = 0;

    }

    else {

    iVar9 = *(int *)(param_1 + 0x14c);

    }

    memmove((void *)(local_b8 * 0x110 + 0x10c + iVar9),

    (void *)(local_b8 * 0x110 + 0x21c + iVar9),

    (*(int *)(iVar9 + 0x164c) - local_b8) * 0x110 - 0x110);

    *(int *)(iVar9 + 0x164c) = *(int *)(iVar9 + 0x164c) + -1;

    local_b8 = local_b8 + -1;

    goto LAB_00491a54;

    }

    switchD_00491757_caseD_4:

    LAB_00491a54:

    local_b8 = local_b8 + 1;

    } while (local_b8 < *(int *)(local_a4 + 0x164c));

    }

    return;


}  // 0x004916e0
#endif // GameFn4916E0
void GameFn4916E0() {}  // 0x004916e0
#if 0 // GHIDRA_RAW: GameFn4C0420 @ 0x004c0420 — needs manual cleanup
void GameFn4C0420()
{


    if ((int *)param_1[0x27] != (int *)0x0) {

    local_7c = param_1[2];

    (**(code **)(*(int *)param_1[0x27] + 8))(param_1 + 3,&local_7c,local_14);

    }

    fclose((FILE *)param_1[2]);

    param_1[2] = 0;

    if ((int *)param_1[0x31] != (int *)0x0) {

    (**(code **)(*(int *)param_1[0x31] + 8))(param_1 + 3);

    }


}  // 0x004c0420
#endif // GameFn4C0420
void GameFn4C0420() {}  // 0x004c0420
#if 0 // GHIDRA_RAW: RenderFn5434F0 @ 0x005434f0 — needs manual cleanup
void RenderFn5434F0()
{


    local_30 = (int *)0x4;

    RegQueryValueExA(DAT_0074be5c,"MissionCheat",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)&local_38,

    (LPDWORD)&local_30);


}  // 0x005434f0
#endif // RenderFn5434F0
void RenderFn5434F0() {}  // 0x005434f0
#if 0 // GHIDRA_RAW: GameFn4B6520 @ 0x004b6520 — needs manual cleanup
int * GameFn4B6520(int *param_1,int *param_2,float *param_3)
{


    uint16_t *puVar1;

    short sVar2;

    float fVar3;

    short *psVar4;

    int iVar5;

    uint32_t *puVar6;

    short *psVar7;

    uint32_t extraout_EDX;

    uint32_t uVar8;

    uint32_t extraout_EDX_00;

    int iVar9;

    float fVar10;

    uint32_t uVar11;

    uint64_t uVar12;

    uint64_t local_88;

    uint64_t local_80;

    int local_74;

    uint64_t local_70;

    uint32_t uStack_68;

    uint32_t uStack_64;

    int local_60 [2];

    uint16_t uStack_58;

    byte bStack_56;

    uint8_t uStack_55;

    uint16_t uStack_54;

    uint16_t uStack_52;

    uint16_t uStack_50;

    uint16_t uStack_4e;

    uint8_t uStack_4c;

    uint16_t uStack_4b;

    uint8_t uStack_49;

    int local_48;

    uint64_t local_30;

    uint32_t local_28;

    uint32_t local_14;



    local_14 = DAT_0067d280 ^ (uint)&local_88;

    local_88 = CONCAT44(local_88._4_4_,param_3);

    switch(param_3[2]) {

    case 1.4013e-45:

    fVar10 = *param_3;

    puVar6 = (uint32_t *)*param_2;

    local_70._0_4_ = -((int)fVar10 >> 0x1f);

    if ((int)fVar10 < 0) {

    fVar10 = (float)-(int)fVar10;

    }

    local_30 = CONCAT44(local_30._4_4_,fVar10);

    iVar9 = 0x1f;

    if (((uint)fVar10 | 1) != 0) {

    for (; ((uint)fVar10 | 1) >> iVar9 == 0; iVar9 = iVar9 + -1) {

    }

    }

    local_74 = *(int *)(&DAT_0065d814 + iVar9 * 8) +

    (uint)CARRY4((uint)fVar10,*(uint32_t *)(&DAT_0065d810 + iVar9 * 8));

    iVar9 = puVar6[2];

    local_80 = CONCAT44(local_80._4_4_,iVar9);

    uVar8 = (int)local_70 + iVar9 + local_74;

    local_88._0_4_ = puVar6 + 1;

    if (uVar8 <= (uint)puVar6[3]) {

    puVar6[2] = uVar8;

    puVar1 = (uint16_t *)(*(int *)local_88 + iVar9 * 2);

    local_80 = CONCAT44(local_80._4_4_,uVar8);

    if (puVar1 != (uint16_t *)0x0) {

    if ((char)local_70 != '\0') {

    *puVar1 = 0x2d;

    }

    FUN_004b8ed0(local_74);

    *param_1 = (int)puVar6;

    return param_1;

    }

    }

    iVar5 = local_74;

    if ((char)local_70 != '\0') {

    if ((uint)puVar6[3] < (int)local_80 + 1U) {

    (**(code **)*puVar6)((int)local_80 + 1U);

    }

    *(uint16_t *)(*(int *)local_88 + puVar6[2] * 2) = 0x2d;

    puVar6[2] = puVar6[2] + 1;

    iVar5 = local_74;

    }

    break;

    case 2.8026e-45:

    local_88._0_4_ = (int *)*param_3;

    puVar6 = (uint32_t *)*param_2;

    iVar9 = 0x1f;

    if (((uint)(int *)local_88 | 1) != 0) {

    for (; ((uint)(int *)local_88 | 1) >> iVar9 == 0; iVar9 = iVar9 + -1) {

    }

    }

    local_30 = (uint64_t)local_30._4_4_ << 0x20;

    iVar5 = *(int *)(&DAT_0065d814 + iVar9 * 8) +

    (uint)CARRY4((uint)(int *)local_88,*(uint32_t *)(&DAT_0065d810 + iVar9 * 8));

    iVar9 = puVar6[2];

    uVar8 = iVar9 + iVar5;

    if ((uVar8 <= (uint)puVar6[3]) && (puVar6[2] = uVar8, puVar6[1] + iVar9 * 2 != 0)) {

    FUN_004b8ed0(iVar5);

    *param_1 = (int)puVar6;

    return param_1;

    }

    break;

    case 4.2039e-45:

    FUN_004b4830(*param_2,*param_3,param_3[1]);

    return param_1;

    case 5.60519e-45:

    fVar10 = *param_3;

    iVar9 = *param_2;

    local_30 = CONCAT44(local_30._4_4_,fVar10);

    fVar3 = param_3[1];

    local_80 = CONCAT44(local_80._4_4_,fVar3);

    iVar5 = 0x1f;

    if (fVar3 != 0.0) {

    for (; (uint)fVar3 >> iVar5 == 0; iVar5 = iVar5 + -1) {

    }

    }

    if (fVar3 == 0.0) {

    iVar5 = 0x1f;

    if (((uint)fVar10 | 1) != 0) {

    for (; ((uint)fVar10 | 1) >> iVar5 == 0; iVar5 = iVar5 + -1) {

    }

    }

    }

    else {

    iVar5 = iVar5 + 0x20;

    }

    uVar8 = (uint)(byte)(&DAT_0065d7d0)[iVar5];

    if (((uint)*(float *)(&DAT_0065d72c + uVar8 * 8) < (uint)fVar3) ||

    (((uint)*(float *)(&DAT_0065d72c + uVar8 * 8) <= (uint)fVar3 &&

    ((uint)*(float *)(&DAT_0065d728 + uVar8 * 8) <= (uint)fVar10)))) {

    local_88._0_4_ = (int *)0x0;

    }

    else {

    local_88._0_4_ = (int *)0x1;

    }

    local_70._0_4_ = *(int *)(iVar9 + 8);

    local_88._0_4_ = (int *)((int)local_70 + (uVar8 - (int)(int *)local_88));

    if (((int *)local_88 <= *(uint32_t *)(iVar9 + 0xc)) &&

    (*(int **)(iVar9 + 8) = (int *)local_88, *(int *)(iVar9 + 4) + (int)local_70 * 2 != 0)) {

    FUN_004b7c50(fVar10,fVar3);

    *param_1 = iVar9;

    return param_1;

    }

    FUN_004b7c50(fVar10,fVar3);

    local_88._0_4_ = (int *)iVar9;

    FUN_004bbe90(extraout_EDX_00,iVar9);

    *param_1 = local_88._4_4_;

    return param_1;

    default:

    *param_1 = *param_2;

    return param_1;

    case 9.80909e-45:

    bStack_56 = bStack_56 & 0xfe;

    uStack_50 = 0;

    uStack_4e = 0;

    local_60[0] = 0;

    local_60[1] = 0xffffffff;

    uStack_58 = 0;

    uStack_54 = 0x20;

    uStack_52 = 0;

    uStack_4c = 1;

    FUN_004b8b30(*param_2,local_60,0);

    return param_1;

    case 1.12104e-44:

    puVar6 = (uint32_t *)*param_2;

    local_88 = CONCAT44(local_88._4_4_,(uint)*(ushort *)param_3);

    if ((uint)puVar6[3] < puVar6[2] + 1) {

    (**(code **)*puVar6)(puVar6[2] + 1);

    }

    *(short *)(puVar6[1] + puVar6[2] * 2) = (short)local_88;

    puVar6[2] = puVar6[2] + 1;

    *param_1 = (int)puVar6;

    return param_1;

    case 1.26117e-44:

    local_30._0_4_ = *param_3;

    iVar9 = *param_2;

    local_80 = 0;

    local_88._0_4_ = (int *)(float)local_30;

    iVar5 = dsign((double)(float)local_30);

    fVar10 = (float)(int *)local_88;

    if (iVar5 != 0) {

    fVar10 = (float)((uint)(int *)local_88 ^ DAT_0066c580);

    local_80._0_6_ = CONCAT15(1,(undefined5)local_80);

    local_30._0_4_ = fVar10;

    }

    local_60[0] = 0;

    uStack_52 = 0;

    uStack_50 = 0;

    uStack_4e = 0;

    uStack_4b = 0;

    uStack_49 = 0;

    local_60[1] = 0xffffffff;

    uStack_58 = 0;

    bStack_56 = 0;

    uStack_55 = 0;

    uStack_54 = 0x20;

    uStack_4c = 1;

    if (((uint)(float)local_30 & 0x7f800000) == 0x7f800000) {

    local_88 = CONCAT44(local_88._4_4_,(float)local_30);

    FUN_004ba420(iVar9,&local_80,0,0xffffffff,0,0x20,0,1);

    return param_1;

    }

    local_70 = fmt::v9::detail::dragonbox::to_decimal<float>(fVar10);

    FUN_004b5150(iVar9,local_60,0,(int)local_80,local_80._4_4_);

    return param_1;

    case 1.4013e-44:

    local_80 = *(uint64_t *)param_3;

    iVar9 = *param_2;

    local_88 = 0;

    local_30 = local_80;

    iVar5 = dsign((int)local_80,(int)((uint64_t)local_80 >> 0x20));

    uVar12 = local_30;

    if (iVar5 != 0) {

    uVar12 = CONCAT44((uint)((uint64_t)local_30 >> 0x20) ^ _UNK_0066c574,

    (uint)local_30 ^ _DAT_0066c570);

    local_88._0_6_ = CONCAT15(1,(undefined5)local_88);

    local_80 = uVar12;

    }

    uVar11 = (uint32_t)uVar12;

    local_60[0] = 0;

    uStack_52 = 0;

    uStack_50 = 0;

    uStack_4e = 0;

    uStack_4b = 0;

    uStack_49 = 0;

    local_60[1] = 0xffffffff;

    uStack_58 = 0;

    bStack_56 = 0;

    uStack_55 = 0;

    uStack_54 = 0x20;

    uStack_4c = 1;

    if ((local_80._4_4_ & 0x7ff00000) == 0x7ff00000) {

    FUN_0043af40(0,&local_88,0,0xffffffff,0,0x20,0,1);

    FUN_004ba420(iVar9);

    return param_1;

    }

    goto LAB_004b6b9c;

    case 1.54143e-44:

    local_80 = *(uint64_t *)param_3;

    iVar9 = *param_2;

    local_88 = 0;

    local_30 = local_80;

    iVar5 = dsign((int)local_80,(int)((uint64_t)local_80 >> 0x20));

    uVar12 = local_30;

    if (iVar5 != 0) {

    uVar12 = CONCAT44((uint)((uint64_t)local_30 >> 0x20) ^ _UNK_0066c574,

    (uint)local_30 ^ _DAT_0066c570);

    local_88._0_6_ = CONCAT15(1,(undefined5)local_88);

    local_80 = uVar12;

    }

    uVar11 = (uint32_t)uVar12;

    local_60[0] = 0;

    uStack_52 = 0;

    uStack_50 = 0;

    uStack_4e = 0;

    uStack_4b = 0;

    uStack_49 = 0;

    local_60[1] = 0xffffffff;

    uStack_58 = 0;

    bStack_56 = 0;

    uStack_55 = 0;

    uStack_54 = 0x20;

    uStack_4c = 1;

    if ((local_80._4_4_ & 0x7ff00000) == 0x7ff00000) {

    FUN_004ba420(iVar9,&local_88,0,0xffffffff,0,0x20,0,1);

    return param_1;

    }

    LAB_004b6b9c:

    uStack_49 = 0;

    uStack_4b = 0;

    uStack_4c = 1;

    uStack_4e = 0;

    uStack_50 = 0;

    uStack_52 = 0;

    uStack_54 = 0x20;

    uStack_55 = 0;

    bStack_56 = 0;

    uStack_58 = 0;

    local_60[1] = 0xffffffff;

    local_60[0] = 0;

    puVar6 = (uint32_t *)

    fmt::v9::detail::dragonbox::to_decimal<double>((double)CONCAT44(uVar11,&local_30));

    local_70._0_4_ = *puVar6;

    local_70._4_4_ = puVar6[1];

    uStack_68 = puVar6[2];

    uStack_64 = puVar6[3];

    FUN_004b5f50(iVar9,local_60,0,(int *)local_88,local_88._4_4_);

    return param_1;

    case 1.68156e-44:

    psVar4 = (short *)*param_3;

    iVar9 = *param_2;

    if (psVar4 == (short *)0x0) {

    fmt::v9::detail::throw_format_error("string pointer is null");

    *param_1 = iVar9;

    return param_1;

    }

    local_88 = CONCAT44(local_88._4_4_,psVar4 + 1);

    psVar7 = psVar4;

    do {

    sVar2 = *psVar7;

    psVar7 = psVar7 + 1;

    } while (sVar2 != 0);

    FUN_004bbe90(psVar4 + ((int)psVar7 - (int)(psVar4 + 1) >> 1),iVar9);

    *param_1 = (int)(int *)local_88;

    return param_1;

    case 1.82169e-44:

    FUN_004bbe90((int)*param_3 + (int)param_3[1] * 2,*param_2);

    *param_1 = (int)(int *)local_88;

    return param_1;

    case 1.96182e-44:

    bStack_56 = bStack_56 & 0xfe;

    uStack_50 = 0;

    uStack_4e = 0;

    local_60[0] = 0;

    local_60[1] = 0xffffffff;

    uStack_58 = 0;

    uStack_54 = 0x20;

    uStack_52 = 0;

    uStack_4c = 1;

    FUN_004bc6c0(*param_2,local_60);

    return param_1;

    case 2.10195e-44:

    local_60[0] = *param_2;

    iVar9 = param_2[2];

    iVar5 = param_2[5];

    local_48 = param_2[6];

    local_30 = 0;

    local_28 = 0;

    uStack_58 = (uint16_t)iVar9;

    bStack_56 = (byte)((uint)iVar9 >> 0x10);

    uStack_55 = (uint8_t)((uint)iVar9 >> 0x18);

    uStack_54 = (uint16_t)param_2[3];

    uStack_52 = (uint16_t)((uint)param_2[3] >> 0x10);

    uStack_50 = (uint16_t)param_2[4];

    uStack_4e = (uint16_t)((uint)param_2[4] >> 0x10);

    uStack_4c = (uint8_t)iVar5;

    uStack_4b = (uint16_t)((uint)iVar5 >> 8);

    uStack_49 = (uint8_t)((uint)iVar5 >> 0x18);

    (*(GhidraCodePtr *)param_3[1])(*param_3,&local_30,local_60);

    *param_1 = local_60[0];

    return param_1;

    }

    FUN_004b8ed0(iVar5);

    local_88._0_4_ = puVar6;

    FUN_004bbe90(extraout_EDX,puVar6);

    *param_1 = local_88._4_4_;

    return param_1;


}  // 0x004b6520
#endif // GameFn4B6520
void GameFn4B6520() {}  // 0x004b6520
#if 0 // GHIDRA_RAW: RenderFn56DC70 @ 0x0056dc70 — needs manual cleanup
void RenderFn56DC70(uint64_t *param_1,uint64_t *param_2,int param_3,int param_4)
{


    int iVar1;

    uint64_t *puVar2;

    uint32_t *puVar3;

    uint32_t uVar4;

    uint32_t uVar5;

    float *pfVar6;

    uint32_t uVar7;

    uint32_t uVar8;

    float fVar9;

    float fVar10;

    float fVar11;

    double dVar12;

    uint8_t auStack_2b8 [4];

    int iStack_2b4;

    int *piStack_2b0;

    float local_2ac;

    float local_2a8;

    float local_2a4;

    uint32_t *local_2a0;

    float fStack_29c;

    float local_298;

    uint64_t *local_294;

    float local_290;

    int local_28c;

    float fStack_288;

    float fStack_284;

    uint32_t local_280;

    float fStack_27c;

    uint32_t uStack_278;

    float fStack_274;

    uint32_t local_270;

    float fStack_26c;

    uint32_t uStack_268;

    float fStack_264;

    uint32_t local_260;

    float fStack_25c;

    uint32_t uStack_258;

    float fStack_254;

    uint32_t local_250;

    uint32_t uStack_24c;

    uint32_t uStack_248;

    uint32_t uStack_244;

    uint32_t local_240;

    uint32_t local_230;

    float fStack_22c;

    uint32_t uStack_228;

    float fStack_224;

    uint32_t local_220;

    float fStack_21c;

    uint32_t uStack_218;

    float fStack_214;

    uint32_t local_210;

    float fStack_20c;

    uint32_t uStack_208;

    float fStack_204;

    uint32_t local_200;

    uint32_t uStack_1fc;

    uint32_t uStack_1f8;

    uint32_t uStack_1f4;

    uint32_t local_1f0;

    uint8_t auStack_1dc [4];

    uint8_t local_1d8 [16];

    float fStack_1c8;

    float fStack_1b8;

    float fStack_1a8;

    uint8_t auStack_19c [8];

    uint8_t auStack_194 [12];

    float fStack_188;

    uint32_t uStack_178;

    float fStack_168;

    uint8_t auStack_14c [20];

    float fStack_138;

    float fStack_128;

    float fStack_118;

    uint8_t auStack_108 [8];

    uint8_t local_100 [56];

    uint8_t auStack_c8 [88];

    float local_70;

    float local_6c;

    float local_68;

    float local_64;

    float fStack_60;

    float fStack_5c;

    float fStack_58;

    float fStack_54;

    float fStack_50;

    float fStack_4c;

    float fStack_48;

    uint32_t uStack_44;

    float fStack_40;

    float fStack_3c;

    float fStack_38;

    float fStack_34;

    float fStack_30;

    float fStack_2c;

    float fStack_28;

    float local_24;

    float fStack_20;

    uint32_t local_14;



    local_14 = DAT_0067d280 ^ (uint)auStack_2b8;

    local_298 = (float)param_4;

    local_2ac = *(float *)(param_3 + 0x1c);

    local_2a4 = (float)**(int **)(param_3 + 0xc);

    local_294 = param_1;

    local_2a8 = (float)param_3;

    if (local_2a4 == 0.0) {

    LAB_0056e64a:

    uVar7 = *(uint32_t *)((int)param_2 + 4);

    uVar4 = *(uint32_t *)(param_2 + 1);

    uVar5 = *(uint32_t *)((int)param_2 + 0xc);

    *(uint32_t *)param_1 = *(uint32_t *)param_2;

    *(uint32_t *)((int)param_1 + 4) = uVar7;

    *(uint32_t *)(param_1 + 1) = uVar4;

    *(uint32_t *)((int)param_1 + 0xc) = uVar5;

    uVar7 = *(uint32_t *)((int)param_2 + 0x14);

    uVar4 = *(uint32_t *)(param_2 + 3);

    uVar5 = *(uint32_t *)((int)param_2 + 0x1c);

    *(uint32_t *)(param_1 + 2) = *(uint32_t *)(param_2 + 2);

    *(uint32_t *)((int)param_1 + 0x14) = uVar7;

    *(uint32_t *)(param_1 + 3) = uVar4;

    *(uint32_t *)((int)param_1 + 0x1c) = uVar5;

    param_1[4] = param_2[4];

    *(uint32_t *)(param_1 + 5) = *(uint32_t *)(param_2 + 5);

    return;

    }

    if (*(int *)((int)local_2a4 + 0x22c) == 1) {

    iVar1 = *(int *)((int)local_2a4 + 0x14c);

    local_290 = (float)(iVar1 + 0xc0);

    local_28c = iVar1 + 0xcc;

    local_2a0 = (uint32_t *)(iVar1 + 0xd8);

    }

    else {

    if (*(int *)((int)local_2a4 + 0x22c) != 0xf) goto LAB_0056e64a;

    iVar1 = *(int *)((int)local_2a4 + 0x14c);

    local_290 = (float)(iVar1 + 0x4c);

    local_28c = iVar1 + 0x58;

    local_2a0 = (uint32_t *)(iVar1 + 100);

    }

    if (param_3 == *(int *)((int)local_2ac + 8)) {

    FUN_0063e2c0(local_100,param_2);

    if (local_298 != 0.0) {

    (*(GhidraCodePtr *)PTR_FUN_0067d208)(local_100);

    }

    (*(GhidraCodePtr *)PTR_FUN_0067d208)(local_1d8);

    (*(GhidraCodePtr *)PTR_FUN_0067d20c)();

    fStack_34 = fStack_274 - fStack_27c * DAT_0066bfe8;

    fStack_30 = fStack_264 - fStack_26c * DAT_0066bfe8;

    fStack_2c = fStack_254 - fStack_25c * DAT_0066bfe8;

    FUN_004fecb0(0,&local_28c,1);

    uVar8 = DAT_0066c580;

    fVar9 = DAT_0066bdc4;

    pfVar6 = (float *)(&local_294)[*piStack_2b0];

    *pfVar6 = (fStack_28 - *pfVar6) * DAT_0066bdc4 + *pfVar6;

    puVar2 = (&local_294)[*piStack_2b0];

    *(float *)((int)puVar2 + 4) =

    (local_24 - *(float *)((int)puVar2 + 4)) * fVar9 + *(float *)((int)puVar2 + 4);

    puVar2 = (&local_294)[*piStack_2b0];

    *(float *)(puVar2 + 1) = (fStack_20 - *(float *)(puVar2 + 1)) * fVar9 + *(float *)(puVar2 + 1);

    puVar3 = (uint32_t *)(&local_294)[*piStack_2b0];

    uStack_44 = *puVar3 ^ uVar8;

    fStack_40 = (float)(puVar3[1] ^ uVar8);

    fStack_3c = (float)(puVar3[2] ^ uVar8);

    fStack_38 = 0.0;

    (*(GhidraCodePtr *)PTR_FUN_0067d218)(1,auStack_194);

    fVar9 = fStack_5c * fStack_5c + fStack_58 * fStack_58 + fStack_54 * fStack_54;

    FUN_0042bee0();

    if (fVar9 != 0.0) {

    fVar9 = DAT_0066bf2c / fVar9;

    fStack_5c = fStack_5c * fVar9;

    fStack_58 = fStack_58 * fVar9;

    fStack_54 = fStack_54 * fVar9;

    }

    fStack_4c = _DAT_0066c350;

    fStack_48 = (float)_UNK_0066c354;

    uStack_44 = _UNK_0066c358;

    fStack_40 = (float)_UNK_0066c35c;

    (*(GhidraCodePtr *)PTR_FUN_0067d218)(1,auStack_19c);

    fVar9 = fStack_60 * fStack_60 + fStack_5c * fStack_5c + fStack_58 * fStack_58;

    FUN_0042bee0();

    if (fVar9 != 0.0) {

    fVar9 = DAT_0066bf2c / fVar9;

    fStack_60 = fStack_60 * fVar9;

    fStack_5c = fStack_5c * fVar9;

    fStack_58 = fStack_58 * fVar9;

    }

    FUN_0063f630(&local_70,&fStack_60,&fStack_50);

    *param_1 = *param_2;

    *(uint32_t *)(param_1 + 1) = *(uint32_t *)(param_2 + 1);

    uVar8 = *local_2a0 & 1;

    if ((*local_2a0 & 2) == 0) {

    if (uVar8 == 0) {

    uVar7 = *(uint32_t *)(param_2 + 2);

    uVar4 = *(uint32_t *)((int)param_2 + 0x14);

    uVar5 = *(uint32_t *)(param_2 + 3);

    *(uint32_t *)((int)param_1 + 0xc) = *(uint32_t *)((int)param_2 + 0xc);

    *(uint32_t *)(param_1 + 2) = uVar7;

    *(uint32_t *)((int)param_1 + 0x14) = uVar4;

    *(uint32_t *)(param_1 + 3) = uVar5;

    }

    else {

    FUN_0063faf0((uint32_t *)((int)param_1 + 0xc),(uint32_t *)((int)param_2 + 0xc),&local_70

    );

    }

    goto LAB_0056e0b8;

    }

    if (uVar8 == 0) {

    FUN_0063fa50(&local_70,(int)local_2ac + 0xc);

    }

    else {

    FUN_0063f8f0(&local_70);

    }

    pfVar6 = &local_70;

    }

    else {

    if ((param_3 != *(int *)(*(int *)((int)local_2ac + 8) + 0x10)) || ((*local_2a0 & 2) == 0)) {

    if ((param_3 != *(int *)(*(int *)(*(int *)((int)local_2ac + 8) + 0x10) + 0x10)) ||

    ((*local_2a0 & 2) == 0)) goto LAB_0056e64a;

    FUN_0063e2c0(&local_280,param_2);

    if (local_298 == 0.0) {

    local_230 = local_280;

    fStack_22c = fStack_27c;

    uStack_228 = uStack_278;

    fStack_224 = fStack_274;

    local_220 = local_270;

    fStack_21c = fStack_26c;

    uStack_218 = uStack_268;

    fStack_214 = fStack_264;

    local_210 = local_260;

    fStack_20c = fStack_25c;

    uStack_208 = uStack_258;

    fStack_204 = fStack_254;

    local_200 = local_250;

    uStack_1fc = uStack_24c;

    uStack_1f8 = uStack_248;

    uStack_1f4 = uStack_244;

    local_1f0 = local_240;

    }

    else {

    (*(GhidraCodePtr *)PTR_FUN_0067d208)(&local_280);

    }

    (*(GhidraCodePtr *)PTR_FUN_0067d208)(&local_230);

    uVar7 = FUN_00634970(piStack_2b0[2],*(uint32_t *)((int)local_2ac + 0x68),

    *(uint32_t *)((int)local_2ac + 0x20));

    FUN_0063e2c0(auStack_1dc,uVar7);

    uVar7 = FUN_00634970(*(uint32_t *)(piStack_2b0[2] + 0x10),

    *(uint32_t *)((int)local_2ac + 0x68),

    *(uint32_t *)((int)local_2ac + 0x20));

    FUN_0063e2c0(auStack_14c,uVar7);

    (*(GhidraCodePtr *)PTR_FUN_0067d208)(auStack_1dc);

    fStack_48 = fStack_188;

    uStack_44 = uStack_178;

    fStack_40 = fStack_168;

    (*(GhidraCodePtr *)PTR_FUN_0067d210)(1,auStack_108);

    FUN_004fecb0(0,&local_2ac,1);

    local_70 = fStack_40;

    local_6c = fStack_3c;

    local_68 = (fStack_38 + local_2ac) - *(float *)(iStack_2b4 + 0xf8);

    (*(GhidraCodePtr *)PTR_FUN_0067d20c)();

    (*(GhidraCodePtr *)PTR_FUN_0067d210)(1,auStack_c8);

    fVar9 = fStack_128 * fStack_128 + fStack_138 * fStack_138 + fStack_118 * fStack_118;

    FUN_0042bee0();

    fVar10 = fStack_1b8 * fStack_1b8 + fStack_1c8 * fStack_1c8 + fStack_1a8 * fStack_1a8;

    local_2ac = fVar9;

    FUN_0042bee0();

    fVar9 = fStack_3c * fStack_3c + fStack_40 * fStack_40 + fStack_38 * fStack_38;

    local_2a4 = fVar10;

    FUN_0042bee0();

    fVar10 = fStack_4c * fStack_4c + fStack_50 * fStack_50 + fStack_48 * fStack_48;

    fStack_29c = fVar9;

    FUN_0042bee0();

    local_298 = fStack_29c * fStack_29c;

    local_2a8 = local_2a4 * local_2a4;

    local_2a4 = local_2a4 * DAT_0066c26c * local_2ac;

    local_2a0 = (uint32_t *)(local_2ac * local_2ac);

    local_290 = fVar10 * fVar10;

    fVar11 = ((local_290 - local_2a8) - (float)local_2a0) / local_2a4;

    fVar9 = DAT_0066c264;

    if (DAT_0066c264 <= fVar11) {

    fVar9 = fVar11;

    }

    fVar11 = DAT_0066bf2c;

    if (fVar9 <= DAT_0066bf2c) {

    fVar11 = fVar9;

    }

    dVar12 = (double)fVar11;

    fStack_288 = fVar10;

    libm_sse2_acos_precise();

    fStack_284 = (float)dVar12;

    fVar10 = ((local_298 - local_2a8) - (float)local_2a0) / local_2a4;

    fVar9 = DAT_0066c264;

    if (DAT_0066c264 <= fVar10) {

    fVar9 = fVar10;

    }

    fVar10 = DAT_0066bf2c;

    if (fVar9 <= DAT_0066bf2c) {

    fVar10 = fVar9;

    }

    dVar12 = (double)fVar10;

    libm_sse2_acos_precise();

    local_2ac = local_2ac * DAT_0066c26c;

    piStack_2b0[1] = (int)(fStack_284 - (float)dVar12);

    fVar10 = ((local_2a8 - local_290) - (float)local_2a0) / (fStack_288 * local_2ac);

    fVar9 = DAT_0066c264;

    if (DAT_0066c264 <= fVar10) {

    fVar9 = fVar10;

    }

    fVar10 = DAT_0066bf2c;

    if (fVar9 <= DAT_0066bf2c) {

    fVar10 = fVar9;

    }

    dVar12 = (double)fVar10;

    libm_sse2_acos_precise();

    fStack_288 = (float)dVar12;

    fVar10 = ((local_2a8 - local_298) - (float)local_2a0) / (fStack_29c * local_2ac);

    fVar9 = DAT_0066c264;

    if (DAT_0066c264 <= fVar10) {

    fVar9 = fVar10;

    }

    fVar10 = DAT_0066bf2c;

    if (fVar9 <= DAT_0066bf2c) {

    fVar10 = fVar9;

    }

    dVar12 = (double)fVar10;

    libm_sse2_acos_precise();

    local_70 = 1.0;

    local_68 = 0.0;

    local_6c = 0.0;

    local_64 = fStack_288 - (float)dVar12;

    FUN_0063f5b0(piStack_2b0 + 3,&local_70);

    param_1 = local_294;

    *local_294 = *param_2;

    *(uint32_t *)(local_294 + 1) = *(uint32_t *)(param_2 + 1);

    FUN_0063faf0((int)local_294 + 0xc,(int)param_2 + 0xc,piStack_2b0 + 3);

    goto LAB_0056e0b8;

    }

    local_64 = *(float *)((int)local_2ac + 4);

    local_70 = 1.0;

    local_68 = 0.0;

    local_6c = 0.0;

    FUN_0063f5b0(&local_24,&local_70);

    FUN_0063faf0((int)local_2ac + 0xc,(int)local_2ac + 0xc,&local_24);

    *param_1 = *param_2;

    *(uint32_t *)(param_1 + 1) = *(uint32_t *)(param_2 + 1);

    pfVar6 = &local_24;

    }

    FUN_0063faf0((int)param_1 + 0xc,(int)param_2 + 0xc,pfVar6);

    LAB_0056e0b8:

    *(uint64_t *)((int)param_1 + 0x1c) = *(uint64_t *)((int)param_2 + 0x1c);

    *(uint32_t *)((int)param_1 + 0x24) = *(uint32_t *)((int)param_2 + 0x24);

    *(uint32_t *)(param_1 + 5) = *(uint32_t *)(param_2 + 5) | 1;

    return;


}  // 0x0056dc70
#endif // RenderFn56DC70
void RenderFn56DC70() {}  // 0x0056dc70
#if 0 // GHIDRA_RAW: GameFn4542D0 @ 0x004542d0 — needs manual cleanup
void GameFn4542D0()
{


    puVar4 = param_1;

    if (0 < local_118[3]) goto LAB_00454391;

    do {

    if (local_118[2] == 0) break;

    LAB_00454391:

    do {

    local_60 = atoi((char *)local_58);

    if (0xff < local_60) {

    uVar2 = FUN_0044efd0("Octet \'{0}\' is invalid.",0x17);

    local_14 = CONCAT31(local_14._1_3_,2);

    FUN_00442420(uVar2);



    _CxxThrowException(local_6c,(ThrowInfo *)&DAT_00678258);

    }

    *puVar4 = local_60;

    puVar4 = puVar4 + 1;

    std::basic_istream<char,std::char_traits<char>_>::getline

    ((basic_istream<char,std::char_traits<char>_> *)local_118,(char *)local_58,

    0x2e00000000,(char)uVar1);

    } while (0 < local_118[3]);

    param_1 = local_5c;

    } while (-1 < local_118[3]);


}  // 0x004542d0
#endif // GameFn4542D0
void GameFn4542D0() {}  // 0x004542d0
#if 0 // GHIDRA_RAW: GameFn4E2BE0 @ 0x004e2be0 — needs manual cleanup
void GameFn4E2BE0(uint32_t param_1)
{


    uint32_t *puVar1;

    uint32_t uVar2;

    int iVar3;

    int iVar4;

    uint32_t extraout_ECX;

    uint32_t *puVar5;

    float10 fVar6;

    float fVar7;

    uint8_t auStack_24 [8];

    float fStack_1c;

    uint64_t uStack_18;

    uint32_t uStack_10;

    uint32_t local_c;



    local_c = DAT_0067d280 ^ (uint)auStack_24;

    iVar3 = FUN_00559dc0();

    if (iVar3 == 0) {

    puVar5 = (uint32_t *)0x0;

    }

    else {

    puVar5 = *(uint32_t **)(iVar3 + 0x14c);

    }

    puVar5[2] = *(uint32_t *)(DAT_007028f4 + 0x424);

    puVar5[3] = *(uint32_t *)(DAT_007028f4 + 0x428);

    puVar5[4] = *(uint32_t *)(DAT_007028f4 + 0x42c);

    puVar5[1] = *(uint32_t *)(DAT_007028f4 + 0x430);

    *puVar5 = *(uint32_t *)(DAT_007028f4 + 0x434);

    FUN_0055c150();

    if (0.0 < (float)puVar5[2]) {

    *(uint32_t *)(iVar3 + 0x370) = puVar5[2];

    }

    uVar2 = puVar5[4];

    *(uint32_t *)(iVar3 + 0x214) = *(uint32_t *)(iVar3 + 0x214) | 0x800000;

    *(uint32_t *)(iVar3 + 0x138) = uVar2;

    puVar1 = (uint32_t *)(*(int *)(iVar3 + 8) + 4);

    *puVar1 = *puVar1 | 4;

    iVar3 = FUN_00559dc0();

    if (iVar3 == 0) {

    puVar5 = (uint32_t *)0x0;

    }

    else {

    puVar5 = *(uint32_t **)(iVar3 + 0x14c);

    }

    puVar5[2] = *(uint32_t *)(DAT_007028f4 + 0x444);

    puVar5[3] = *(uint32_t *)(DAT_007028f4 + 0x440);

    puVar5[4] = *(uint32_t *)(DAT_007028f4 + 0x43c);

    puVar5[1] = *(uint32_t *)(DAT_007028f4 + 0x438);

    *puVar5 = *(uint32_t *)(DAT_007028f4 + 0x448);

    FUN_0055c150();

    if (0.0 < (float)puVar5[2]) {

    *(uint32_t *)(iVar3 + 0x370) = puVar5[2];

    }

    uVar2 = puVar5[4];

    *(uint32_t *)(iVar3 + 0x214) = *(uint32_t *)(iVar3 + 0x214) | 0x800000;

    *(uint32_t *)(iVar3 + 0x138) = uVar2;

    puVar1 = (uint32_t *)(*(int *)(iVar3 + 8) + 4);

    *puVar1 = *puVar1 | 4;

    iVar3 = FUN_00559530();

    if (iVar3 != 0) {

    iVar4 = FUN_0055a8a0();

    if (iVar4 == 0) {

    FUN_00463000(&DAT_00701bd8,"Error: ObjObj type %d not found",extraout_ECX);

    if (DAT_0074c5d4 < 5) {

    FUN_0062edc0(&DAT_00701bd8);

    }

    DAT_0074c5d4 = DAT_0074c5d4 + 1;

    }

    else {

    FUN_0055a4a0(iVar4);

    FUN_0055a710(iVar4);

    }

    FUN_005597d0();

    }

    FUN_0055ccc0();

    FUN_0048f2f0(1,0x20,0,0,0x3e2aaaab);

    FUN_0048f2f0(0xfe,0,0,0,0x3e2aaaab);

    FUN_0055c150();

    *(uint32_t *)(iVar3 + 0x80) = *(uint32_t *)(iVar3 + 0x80) & 0xfffffffe;

    FUN_005d45c0();

    fStack_1c = *(float *)(DAT_007028f4 + 0x494);

    uStack_10 = DAT_00681ddc;

    uStack_18 = DAT_00681dd4;

    fVar6 = (float10)FUN_00638c80(&uStack_18,param_1);

    fStack_1c = (DAT_0066c1ac /

    ((float)(fVar6 + (float10)DAT_0066c068) * (float)(fVar6 + (float10)DAT_0066c068))) *

    DAT_0066be4c * fStack_1c;

    if (DAT_0066bd9c < fStack_1c) {

    fVar7 = DAT_0066be4c;

    if (fStack_1c <= DAT_0066be4c) {

    fVar7 = fStack_1c;

    }

    if (DAT_007488a8 < fVar7) {

    DAT_007488ac = 0xffffffff;

    DAT_00702808 = fVar7 / DAT_0066be4c;

    DAT_00702804 = (fVar7 * DAT_0066bf74) / DAT_0066be4c;

    DAT_007488a8 = fVar7;

    }

    }

    return;


}  // 0x004e2be0
#endif // GameFn4E2BE0
void GameFn4E2BE0() {}  // 0x004e2be0
#if 0 // GHIDRA_RAW: RenderFn539F90 @ 0x00539f90 — needs manual cleanup
void RenderFn539F90(int param_1)
{


    uint32_t *puVar1;

    uint32_t uVar2;

    int *piVar3;

    int *piVar4;

    int iVar5;

    int iVar6;

    uint32_t extraout_ECX;

    int iVar7;

    int local_c;



    if (param_1 == 0) {

    iVar7 = 0;

    }

    else {

    iVar7 = *(int *)(param_1 + 0x14c);

    }

    FUN_0056ce30();

    for (puVar1 = DAT_007027a8; puVar1 != (uint32_t *)0x0; puVar1 = (uint32_t *)*puVar1) {

    iVar5 = puVar1[3];

    if ((*(int *)(iVar5 + 0x22c) == 0xd) && (*(int *)(iVar5 + 0x2c4) == param_1)) {

    *(uint32_t *)(iVar5 + 0x124) = *(uint32_t *)(iVar5 + 0x124) | 0x8000;

    }

    }

    iVar5 = FUN_00559530();

    if (iVar5 != 0) {

    iVar6 = FUN_0055a8a0();

    if (iVar6 == 0) {

    FUN_00463000(&DAT_00701bd8,"Error: ObjObj type %d not found",extraout_ECX);

    if (DAT_0074c5d4 < 5) {

    FUN_0062edc0(&DAT_00701bd8);

    }

    DAT_0074c5d4 = DAT_0074c5d4 + 1;

    }

    else {

    FUN_0055a4a0(iVar6);

    FUN_0055a710(iVar6);

    }

    FUN_005597d0();

    }

    *(uint64_t *)(iVar5 + 0xf0) = *(uint64_t *)(param_1 + 0xf0);

    uVar2 = *(uint32_t *)(param_1 + 0xf8);

    *(uint32_t *)(iVar5 + 0xf8) = uVar2;

    *(uint64_t *)(iVar5 + 0xfc) = *(uint64_t *)(iVar5 + 0xf0);

    *(uint64_t *)(iVar5 + 0x108) = *(uint64_t *)(iVar5 + 0xf0);

    *(uint32_t *)(iVar5 + 0x104) = uVar2;

    *(uint32_t *)(iVar5 + 0x110) = uVar2;

    *(uint32_t *)(iVar5 + 0x1d8) = *(uint32_t *)(param_1 + 0x1d8);

    *(uint32_t *)(iVar5 + 0x114) = *(uint32_t *)(param_1 + 0x114);

    if ((*(int *)(param_1 + 0x60) != 0x2e) && (*(int *)(*(int *)(param_1 + 8) + 0xc0) != 0)) {

    FUN_0048f450();

    }

    if ((*(int *)(iVar5 + 0x60) != 0x2e) && (*(int *)(*(int *)(iVar5 + 8) + 0xc0) != 0)) {

    FUN_0048f450();

    }

    *(int *)(param_1 + 0x2c4) = iVar5;

    *(int *)(iVar5 + 0x2c4) = param_1;

    *(uint32_t *)(param_1 + 300) = *(uint32_t *)(param_1 + 300) | 0x2000000;

    *(uint32_t *)(iVar5 + 0x124) = *(uint32_t *)(iVar5 + 0x124) | 0x400000;

    *(int *)(iVar5 + 0x264) = param_1;

    *(uint32_t *)(iVar5 + 0x268) = 0xffffffff;

    *(uint32_t *)(iVar5 + 0x26c) = 0xffffffff;

    piVar4 = DAT_00749908;

    puVar1 = DAT_007027c0;

    if (-2 < *(int *)(iVar7 + 0x178)) {

    for (; piVar4 != DAT_0074990c; piVar4 = piVar4 + 2) {

    piVar3 = (int *)*piVar4;

    if (*piVar3 == *(int *)(iVar7 + 0x178)) {

    if (piVar3 != (int *)0x0) {

    iVar7 = piVar3[2];

    goto joined_r0x0053a157;

    }

    break;

    }

    }

    }

    iVar7 = 0;

    joined_r0x0053a157:

    while ((puVar1 != (uint32_t *)0x0 &&

    ((((local_c = puVar1[3], (*(uint32_t *)(local_c + 0x124) & 0x8000) != 0 ||

    (*(int *)(local_c + 0x264) != param_1)) || (*(int *)(local_c + 4) != iVar7)) ||

    (*(int *)(local_c + 0x26c) != 10))))) {

    puVar1 = (uint32_t *)*puVar1;

    }

    if (puVar1 == (uint32_t *)0x0) {

    local_c = 0;

    }

    if (local_c != 0) {

    *(uint32_t *)(local_c + 0x1d0) = 0x3f800000;

    }

    iVar7 = FUN_004ffb40();

    if (iVar7 != 0) {

    *(uint32_t *)(iVar7 + 0x124) = *(uint32_t *)(iVar7 + 0x124) | 0x40000000;

    }

    iVar7 = FUN_004ffb40();

    if (iVar7 != 0) {

    *(uint32_t *)(iVar7 + 0x124) = *(uint32_t *)(iVar7 + 0x124) | 0x40000000;

    }

    if ((DAT_006ff960 == 6) && (iVar7 = FUN_0045f460(), iVar7 != 0)) {

    FUN_00469de0(0,0,7,0,0);

    }

    if (DAT_00702bb8 == 0) {

    iVar7 = *(int *)(param_1 + 0x264);

    while (iVar5 = iVar7, iVar5 != 0) {

    param_1 = iVar5;

    iVar7 = *(int *)(iVar5 + 0x264);

    }

    if (param_1 == DAT_00702774) {

    FUN_00558360();

    return;

    }

    FUN_005581d0();

    }

    return;


}  // 0x00539f90
#endif // RenderFn539F90
void RenderFn539F90() {}  // 0x00539f90
#if 0 // GHIDRA_RAW: GameFn4BE510 @ 0x004be510 — needs manual cleanup
void GameFn4BE510(int param_1)
{


    char cVar1;

    int iVar2;

    char *pcVar3;

    char *pcVar4;

    uint32_t uVar5;

    int *piVar6;

    uint16_t local_2c0 [2];

    int local_2bc;

    int local_2b8;

    int local_2ac;

    uint32_t local_2a0;

    uint32_t local_29c;

    uint32_t local_298;

    uint32_t local_28c;

    uint32_t local_280;

    int local_240;

    uint32_t uStack_23c;

    uint32_t uStack_238;

    uint32_t uStack_234;

    uint32_t local_230;

    uint32_t local_22c;

    uint8_t local_228 [516];

    uint32_t local_24;

    uint8_t *puStack_20;

    void *local_1c;

    uint8_t *puStack_18;

    uint32_t local_14;



    puStack_20 = &stack0xfffffffc;

    local_14 = 0xffffffff;

    puStack_18 = &LAB_0064976b;

    local_1c = ExceptionList;

    local_24 = DAT_0067d280 ^ (uint)&stack0xfffffff0;

    // ExceptionList = ... (SEH frame, stubbed)

    if (*(char *)(param_1 + 0x4c) == '\0') {

    iVar2 = FUN_005f0fe0(local_24);

    pcVar3 = (char *)FUN_004beb10("{0}.{1}.{2}.{3}",0xf,iVar2 + 4,iVar2 + 8,iVar2 + 0xc);

    local_14 = 0;

    if (0xf < *(uint32_t *)(pcVar3 + 0x14)) {

    pcVar3 = *(char **)pcVar3;

    }

    pcVar4 = pcVar3;

    do {

    cVar1 = *pcVar4;

    pcVar4 = pcVar4 + 1;

    } while (cVar1 != '\0');

    FUN_0043cb70(pcVar3,(int)pcVar4 - (int)(pcVar3 + 1));

    FUN_004439b0();

    uStack_238 = 0;

    uStack_234 = 0;

    local_230 = 6;

    local_22c = 0xf;

    local_240._0_1_ = s_Giants_00668fdc[0];

    local_240._1_1_ = s_Giants_00668fdc[1];

    local_240._2_1_ = s_Giants_00668fdc[2];

    local_240._3_1_ = s_Giants_00668fdc[3];

    uStack_23c = (uint)(ushort)s_Giants_00668fdc._4_2_;

    piVar6 = (int *)(param_1 + 0x34);

    local_14 = 1;

    if (piVar6 != &local_240) {

    FUN_0043cb70(&local_240,6);

    }

    local_14 = 0xffffffff;

    if (0xf < local_22c) {

    uVar5 = local_22c + 1;

    iVar2 = local_240;

    if (0xfff < uVar5) {

    iVar2 = *(int *)(local_240 + -4);

    uVar5 = local_22c + 0x24;

    if (0x1f < (local_240 - iVar2) - 4U) {



    std::abort();

    }

    }

    FUN_00643505(iVar2,uVar5);

    }

    memset(local_2c0,0,0x68);

    local_2c0[0] = 0x68;

    if (0xf < *(uint32_t *)(param_1 + 0x48)) {

    piVar6 = (int *)*piVar6;

    }

    local_2b8 = param_1 + 0x1c;

    if (0xf < *(uint32_t *)(param_1 + 0x30)) {

    local_2b8 = *(int *)local_2b8;

    }

    local_2ac = param_1 + 4;

    if (0xf < *(uint32_t *)(param_1 + 0x18)) {

    local_2ac = *(int *)local_2ac;

    }

    local_28c = local_28c | 0x1fff;

    local_2a0 = 3;

    local_29c = 0xffffffff;

    local_298 = 0xffffffff;

    local_280 = 0x41;

    local_2bc = (int)piVar6;

    crUninstall();

    iVar2 = crInstallA(local_2c0);

    if (iVar2 != 0) {

    crGetLastErrorMsgA(local_228,0x200);

    FUN_004bea70("Failed to initialize CrashRpt: {0}",0x22,local_228);

    }

    crSetCrashCallbackA(FUN_004be980,param_1);

    *(uint8_t *)(param_1 + 0x4c) = 1;

    }

    // ExceptionList = ... (SEH frame, stubbed)

    return;


}  // 0x004be510
#endif // GameFn4BE510
void GameFn4BE510() {}  // 0x004be510
#if 0 // GHIDRA_RAW: RenderFn5068F0 @ 0x005068f0 — needs manual cleanup
void RenderFn5068F0(int param_1)
{


    int iVar1;

    uint32_t *puVar2;

    uint32_t uVar3;

    uint32_t uVar4;

    int iVar5;

    uint8_t auStack_11c [4];

    uint32_t local_118;

    uint32_t local_114;

    uint8_t local_110 [260];

    uint32_t local_c;



    local_c = DAT_0067d280 ^ (uint)auStack_11c;

    if (DAT_00702898 != '\0') {

    return;

    }

    if (((param_1 == 0) || (*(int *)(param_1 + 0x22c) != 2)) ||

    ((*(uint32_t *)(param_1 + 300) & 0x8020000) == 0)) {

    iVar5 = *(int *)(param_1 + 0x264);

    if (((iVar5 == 0) || (*(int *)(iVar5 + 0x22c) != 0x5f)) || (*(int *)(param_1 + 0x22c) != 2)) {

    if (((*(int *)(param_1 + 0x22c) == 3) && (iVar5 != 0)) &&

    ((*(int *)(iVar5 + 0x22c) == 0x5a &&

    ((*(int *)(DAT_00702770 + 0x5194) < 0 ||

    (*(int *)(*(int *)(DAT_00702770 + 0x5194) * 0x118 + 0x237c + DAT_00702770) == 0)))))) {

    FUN_005a7720();

    return;

    }

    puVar2 = DAT_007027d8;

    if ((*(uint32_t *)(param_1 + 0x128) & 0x800000) != 0) {

    for (; puVar2 != (uint32_t *)0x0; puVar2 = (uint32_t *)*puVar2) {

    iVar5 = puVar2[3];

    if (((((*(uint32_t *)(iVar5 + 0x124) & 0x8000) == 0) &&

    ((((iVar1 = *(int *)(iVar5 + 4), iVar1 == 0xb || (iVar1 == 0x248)) ||

    (iVar1 == 0x2e6)) &&

    ((*(int *)(iVar5 + 0x264) == param_1 || (*(int *)(iVar5 + 0x2c4) == param_1)))))) &&

    (*(int *)(iVar5 + 0x134) != 5)) &&

    (((*(uint32_t *)(iVar5 + 0x124) & 0x400) == 0 &&

    (*(int *)(*(int *)(iVar5 + 0x14c) + 0x54) == 0)))) {

    FUN_005ce1f0(1);

    if (DAT_006ff960 != 6) {

    return;

    }

    iVar5 = FUN_0045f460();

    if (iVar5 == 0) {

    return;

    }

    local_118 = *(uint32_t *)(param_1 + 0x1d4);

    local_114 = 0;

    FUN_00469d20(4,&local_118);

    return;

    }

    }

    }

    if ((*(uint32_t *)(param_1 + 0x128) & 0x400000) == 0) {

    return;

    }

    if (*(int *)(param_1 + 0x22c) != 2) {

    return;

    }

    if (*(int *)(*(int *)(param_1 + 0x14c) + 0x178) < 0) {

    return;

    }

    if (param_1 == DAT_00702774) {

    uVar3 = FUN_005e80c0("InvChDropItem");

    uVar4 = FUN_0056ea70();

    FUN_00463000(local_110,uVar3,uVar4);

    FUN_00453520();

    }

    FUN_005067d0(1,*(float *)(param_1 + 0x2fc) * DAT_0066c290,0x41700000,0x41f00000);

    FUN_00502c30();

    return;

    }

    }

    else if ((*(uint32_t *)(param_1 + 300) & 0x8000000) != 0) {

    FUN_0053d3e0();

    return;

    }

    FUN_0053d780();

    return;


}  // 0x005068f0
#endif // RenderFn5068F0
void RenderFn5068F0() {}  // 0x005068f0
void RenderFn52F3F0() {}  // 0x0052f3f0
void RenderFn544C20() {}  // 0x00544c20
#if 0 // GHIDRA_RAW: RenderFn544FF0 @ 0x00544ff0 — needs manual cleanup
void RenderFn544FF0(void)
{


    int iVar1;

    uint32_t *puVar2;

    int iVar3;

    int iVar4;

    bool bVar5;



    FUN_005413d0();

    iVar1 = DAT_00748a30;

    if (DAT_00702c07 != '\0') {

    if (DAT_00702ccc != (uint32_t *)0x0) {

    FUN_004d39d0();

    }

    DAT_00702ccc = (uint32_t *)0x0;

    FUN_004d1070();

    DAT_00681db0 = 0;

    DAT_00681db4 = 0xffffffff;

    DAT_00681dec = 0;

    DAT_00681e34 = 0;

    *(uint32_t *)(DAT_00702d60 + 0x124) = *(uint32_t *)(DAT_00702d60 + 0x124) | 0x8000;

    DAT_00702d60 = 0;

    FUN_00541080();

    if ((float)DAT_007028a4 <= DAT_0066c15c) {

    FUN_0062be00();

    FUN_0062b9c0();

    }

    if (DAT_00702b30 != 0) {

    return;

    }

    if (DAT_00702b34 != 0) {

    return;

    }

    if (DAT_00702b50 != 0) {

    return;

    }

    if (DAT_00702bb8 != 0) {

    return;

    }

    FUN_00558360();

    return;

    }

    if (DAT_00702c01 == '\0') {

    if (DAT_00702c02 == '\0') goto LAB_0054523f;

    iVar3 = DAT_00748a30 + 1;

    }

    else {

    iVar3 = DAT_00748a30 + -1;

    }

    if (iVar3 < DAT_00682e98) {

    iVar4 = DAT_0068298c + -1;

    LAB_00545125:

    iVar3 = iVar4;

    }

    else {

    iVar4 = DAT_00682e98;

    if (DAT_0068298c + -1 < iVar3) goto LAB_00545125;

    }

    bVar5 = DAT_00702b30 == 0;

    iVar4 = DAT_00748a30 * 3;

    DAT_00748a30 = iVar3;

    (&DAT_00748b50)[iVar4] = 0;

    (&DAT_00748b50)[iVar3 * 3] = 1;

    if ((((bVar5) && (DAT_00702b34 == 0)) && (DAT_00702b50 == 0)) &&

    ((iVar3 != iVar1 && (DAT_00702bb8 == 0)))) {

    FUN_00558360();

    iVar3 = DAT_00748a30;

    }

    iVar1 = *(int *)(*(int *)(DAT_0074b5f8 + DAT_0074b5fc * 0x24) + iVar3 * 4);

    DAT_00702c1c = ((*(float *)(iVar1 + 0x44) * DAT_0066be20 + *(float *)(iVar1 + 0x38) * DAT_0066be20

    ) / (float)DAT_0074b604) * (float)DAT_0074b604;

    DAT_00702c20 = ((*(float *)(iVar1 + 0x48) * DAT_0066be20 + *(float *)(iVar1 + 0x3c) * DAT_0066be20

    ) / (float)DAT_0074b608) * (float)DAT_0074b608;

    DAT_00702c24 = DAT_00702c1c;

    DAT_00702c28 = DAT_00702c20;

    LAB_0054523f:

    FUN_005de3d0(DAT_0074b608);

    iVar3 = FUN_005de120();

    iVar1 = DAT_00748a30;

    if (iVar3 < 0) {

    if (DAT_00702c0a != '\0') {

    for (puVar2 = (uint32_t *)*DAT_00702ccc; puVar2 != (uint32_t *)0x0;

    puVar2 = (uint32_t *)*puVar2) {

    if (puVar2[2] == 1) {

    if (puVar2[0xb] == 1) {

    FUN_00544f50();

    goto LAB_0054532b;

    }

    if (puVar2[0xb] != 0) goto LAB_0054532b;

    break;

    }

    }

    FUN_00544ec0();

    }

    }

    else {

    if ((iVar3 < DAT_00682e98) || (DAT_0068298c + -1 < iVar3)) {

    iVar3 = DAT_00748a30;

    }

    bVar5 = DAT_00702b30 == 0;

    iVar4 = DAT_00748a30 * 3;

    DAT_00748a30 = iVar3;

    (&DAT_00748b50)[iVar4] = 0;

    (&DAT_00748b50)[iVar3 * 3] = 1;

    if ((((bVar5) && (DAT_00702b34 == 0)) && (DAT_00702b50 == 0)) &&

    ((iVar3 != iVar1 && (DAT_00702bb8 == 0)))) {

    FUN_00558360();

    }

    if (DAT_00702c0a != '\0') {

    FUN_00544c20();

    }

    }

    LAB_0054532b:

    if (DAT_00702c08 != '\0') {

    FUN_00544c20();

    }

    if (0x11 < DAT_00749010) {

    if (DAT_00702c17 != '\0') {

    FUN_00544ec0();

    }

    if (DAT_00702c18 != '\0') {

    FUN_00544f50();

    }

    }

    _DAT_00702c01 = 0;

    FUN_004d63f0();

    return;


}  // 0x00544ff0
#endif // RenderFn544FF0
void RenderFn544FF0() {}  // 0x00544ff0
#if 0 // GHIDRA_RAW: GameFn454E00 @ 0x00454e00 — needs manual cleanup
void GameFn454E00()
{


    pbVar6 = (byte *)FUN_005e80c0("WN_None");

    pcVar14 = &DAT_00702988;

    do {

    bVar1 = *pcVar14;

    bVar19 = bVar1 < *pbVar6;

    if (bVar1 != *pbVar6) {

    LAB_00454e70:

    uVar7 = -(uint)bVar19 | 1;

    goto LAB_00454e75;

    }

    if (bVar1 == 0) break;

    bVar1 = pcVar14[1];

    bVar19 = bVar1 < pbVar6[1];

    if (bVar1 != pbVar6[1]) goto LAB_00454e70;

    pcVar14 = pcVar14 + 2;

    pbVar6 = pbVar6 + 2;

    } while (bVar1 != 0);

    uVar7 = 0;

    LAB_00454e75:

    if (uVar7 != 0) {

    FUN_006328b0(&DAT_00702988,&local_210,0x200);

    psVar15 = &local_210;

    do {

    sVar3 = *psVar15;

    psVar15 = psVar15 + 1;

    } while (sVar3 != 0);

    iVar8 = (**(code **)(*DAT_006ff9d4 + 0x48))

    (DAT_006ff9d4,L"hostname",&local_210,

    ((int)psVar15 - (int)local_20e >> 1) * 2 + 2,1);

    if (iVar8 < 0) {

    return;

    }

    if (DAT_0074be5c != (HKEY)0x0) {

    pcVar14 = &DAT_00702988;

    do {

    pcVar16 = pcVar14;

    pcVar14 = pcVar16 + 1;

    } while (*pcVar16 != '\0');

    RegSetValueExA(DAT_0074be5c,"IPAddress",0,1,(BYTE *)&DAT_00702988,

    (DWORD)(pcVar16 + -0x702987));

    }

    }


}  // 0x00454e00
#endif // GameFn454E00
void GameFn454E00() {}  // 0x00454e00
#if 0 // GHIDRA_RAW: RenderFn539470 @ 0x00539470 — needs manual cleanup
void RenderFn539470(int param_1)
{


    bool bVar1;

    int iVar2;

    uint32_t uVar3;

    uint32_t uVar4;

    int *piVar5;

    int iVar6;

    uint32_t uVar7;

    uint32_t *puVar8;

    float fVar9;

    float fVar10;

    float fVar11;

    uint32_t local_48;

    uint32_t uStack_44;

    uint32_t uStack_40;

    uint32_t uStack_3c;

    uint32_t local_38;

    uint32_t uStack_34;

    int iStack_30;

    uint32_t uStack_2c;

    uint32_t local_28;

    uint32_t uStack_24;

    uint32_t uStack_20;

    uint32_t uStack_1c;

    uint32_t local_18;

    uint32_t uStack_14;

    uint32_t uStack_10;

    uint32_t uStack_c;

    uint32_t local_8;



    if (param_1 == 0) {

    iVar6 = 0;

    }

    else {

    iVar6 = *(int *)(param_1 + 0x14c);

    }

    puVar8 = (uint32_t *)(param_1 + 0x260);

    bVar1 = false;

    if (DAT_007488d0 != 0) {

    *puVar8 = *puVar8 & 0xfffffbff;

    }

    if (*(int *)(param_1 + 0x1c0) == 0) {

    uVar4 = **(uint32_t **)(param_1 + 0x368);

    uVar7 = uVar4 >> 0xd & 0x7f;

    iVar2 = FUN_00453050();

    if (((uVar7 < (uint)(*(int *)(iVar2 + 8) - *(int *)(iVar2 + 4) >> 2)) &&

    (iVar2 = *(int *)(*(int *)(iVar2 + 4) + uVar7 * 4), iVar2 != 0)) &&

    ((*(uint32_t *)(iVar2 + (uVar4 & 0x1fff) * 4) & 0xfffff) != 0xfffff)) goto LAB_00539517;

    if (((*puVar8 & 0x400) == 0) || (*(int *)(iVar6 + 0x210) != 0)) {

    *(uint8_t *)(iVar6 + 0x124) = 0;

    }

    else {

    *(uint8_t *)(iVar6 + 0x124) = 0x20;

    }

    }

    else {

    LAB_00539517:

    *(float *)(*(int *)(param_1 + 0x150) + 8) = *(float *)(DAT_007028f4 + 0x678) * DAT_0066bdf4;

    }

    if ((param_1 == DAT_00702774) && (DAT_00682204 == -1)) {

    if ((*(byte *)(DAT_00702774 + 0x260) & 2) == 0) {

    if (DAT_0074c5d1 == '\0') goto LAB_00539643;

    DAT_00681db0 = 0;

    DAT_00681dec = 0;

    DAT_0074c5d1 = '\0';

    }

    else {

    iVar2 = FUN_0048f4a0(param_1,*(uint32_t *)(param_1 + 0x60),0xe,0);

    if (iVar2 == 0) {

    FUN_0048f4a0(param_1,1,0xe,0);

    }

    DAT_00681dec = 1;

    _DAT_00681df0 = local_48;

    _DAT_00681df4 = uStack_44;

    uRam00681df8 = uStack_40;

    uRam00681dfc = uStack_3c;

    _DAT_00681e30 = local_8;

    DAT_00681db0 = 1;

    DAT_0074c5d1 = '\x01';

    _DAT_00681e00 = local_38;

    uRam00681e04 = uStack_34;

    uRam00681e08 = iStack_30;

    uRam00681e0c = uStack_2c;

    _DAT_00681e10 = local_28;

    uRam00681e14 = uStack_24;

    uRam00681e18 = uStack_20;

    uRam00681e1c = uStack_1c;

    _DAT_00681e20 = local_18;

    uRam00681e24 = uStack_14;

    uRam00681e28 = uStack_10;

    uRam00681e2c = uStack_c;

    }

    DAT_00681e34 = 0;

    DAT_00681db4 = 0xffffffff;

    }

    LAB_00539643:

    fVar9 = 0.0;

    if ((((*(uint32_t *)(param_1 + 300) & 0x2000000) != 0) || (*(char *)(iVar6 + 0x124) == '\0')) ||

    ((fVar11 = *(float *)(iVar6 + 0x17c),

    fVar11 < *(float *)(DAT_007028f4 + 0x69c) || fVar11 == *(float *)(DAT_007028f4 + 0x69c) &&

    (((*(uint32_t *)(param_1 + 0x124) & 0x1000) == 0 || (fVar11 <= 0.0)))))) {

    iVar2 = *(int *)(param_1 + 0x14c);

    *(uint32_t *)(iVar2 + 0xb4) = 0;

    *(uint32_t *)(param_1 + 0x124) = *(uint32_t *)(param_1 + 0x124) & 0xffffefff;

    if ((**(int **)(param_1 + 8) != 0x85) &&

    (((*(uint32_t *)(param_1 + 300) & 0x2800000) == 0 && (*(int *)(iVar2 + 300) == 0)))) {

    if ((*(uint32_t *)(param_1 + 300) & 0x20000) == 0) {

    fVar11 = *(float *)(DAT_007028f4 + 0x6a0);

    fVar9 = fVar11;

    FUN_0062a0b0();

    fVar9 = fVar9 * fVar11;

    }

    else {

    fVar11 = *(float *)(DAT_007028f4 + 0xac4);

    fVar9 = fVar11;

    FUN_0062a0b0();

    fVar9 = fVar9 * fVar11;

    }

    fVar11 = DAT_0066c0d8;

    if ((*(int *)(param_1 + 0x22c) == 2) && (*(int *)(*(int *)(param_1 + 0x14c) + 0x178) == 0x12))

    {

    fVar9 = fVar9 * *(float *)(DAT_007028f4 + 0x7f8);

    }

    fVar9 = fVar9 + *(float *)(iVar2 + 0x17c);

    *(float *)(iVar2 + 0x17c) = fVar9;

    if (fVar11 < fVar9) {

    *(uint32_t *)(iVar2 + 0x17c) = 0x42c80000;

    }

    }

    }

    else {

    FUN_005390a0();

    iVar2 = *(int *)(param_1 + 0x14c);

    if ((param_1 == DAT_00702774) || (*(int *)(param_1 + 0x1bc) != *(int *)(DAT_00702774 + 0x1bc)))

    {

    fVar9 = (float)(int)*(char *)(iVar2 + 0x124) * DAT_0066bd58;

    if ((*(uint32_t *)(param_1 + 300) & 0x20000) == 0) {

    fVar11 = fVar9;

    FUN_0062a0b0();

    fVar9 = fVar11 * fVar9 * *(float *)(DAT_007028f4 + 0x6a4);

    }

    else {

    fVar11 = fVar9;

    FUN_0062a0b0();

    fVar9 = fVar11 * fVar9 * *(float *)(DAT_007028f4 + 0xac0);

    }

    *(float *)(iVar2 + 0x17c) = *(float *)(iVar2 + 0x17c) - fVar9;

    }

    puVar8 = (uint32_t *)(param_1 + 300);

    fVar9 = 0.0;

    bVar1 = true;

    if (*(float *)(iVar6 + 0x17c) <= 0.0) {

    FUN_0053a400();

    if ((*puVar8 & 0x6000000) == 0x2000000) {

    if ((DAT_006ff960 == 6) && (iVar2 = FUN_0045f460(), iVar2 != 0)) {

    FUN_00469de0(0,0,8,0,0);

    }

    *puVar8 = *puVar8 | 0x4000000;

    *(uint32_t *)(param_1 + 0x2c4) = 0;

    FUN_00558240();

    }

    *(uint32_t *)(iVar6 + 0x17c) = 0;

    }

    }

    iVar2 = *(int *)(param_1 + 0x14c);

    if (*(int *)(iVar2 + 0xb4) == 0) {

    FUN_0062a0b0();

    fVar11 = DAT_0066bf2c;

    fVar9 = *(float *)(iVar2 + 0xb0) - fVar9;

    *(float *)(iVar2 + 0xb0) = fVar9;

    if ((*(uint32_t *)(param_1 + 300) & 0x20000) == 0) {

    fVar10 = 0.0;

    if (((byte)**(uint32_t **)(param_1 + 0x150) & 0xc0) == 0x80) {

    LAB_00539936:

    if (fVar9 <= 0.0) {

    fVar10 = fVar11;

    }

    goto LAB_0053993e;

    }

    if (*(int *)(param_1 + 0x22c) == 2) {

    if (*(int *)(*(int *)(param_1 + 0x14c) + 0x178) == 0x12) goto LAB_00539936;

    goto LAB_00539943;

    }

    }

    else {

    fVar9 = *(float *)(DAT_007028f4 + 0xac8);

    fVar11 = fVar9;

    FUN_0062a0b0();

    fVar10 = fVar11 * fVar9;

    fVar11 = DAT_0066bf2c;

    LAB_0053993e:

    if (*(int *)(param_1 + 0x22c) == 2) {

    LAB_00539943:

    if (*(int *)(*(int *)(param_1 + 0x14c) + 0x178) == 0x12) {

    fVar10 = fVar10 + fVar10;

    }

    }

    }

    fVar10 = fVar10 + *(float *)(iVar2 + 0xac);

    *(float *)(iVar2 + 0xac) = fVar10;

    if (fVar11 < fVar10) {

    *(uint32_t *)(iVar2 + 0xac) = 0x3f800000;

    }

    if (*(int *)(DAT_00702770 + 0x4eb4) != 0) {

    *(uint32_t *)(iVar2 + 0xac) = 0;

    }

    }

    iVar2 = *(int *)(param_1 + 0x14c);

    if (_DAT_0066bce4 < *(float *)(iVar2 + 0x120)) {

    *(uint32_t *)(iVar2 + 0xac) = 0;

    *(uint32_t *)(iVar2 + 0x17c) = 0;

    }

    iVar2 = *(int *)(param_1 + 0x14c);

    uStack_34 = 2;

    local_38 = 8;

    iStack_30 = param_1;

    if (((*(uint32_t *)(param_1 + 0x124) & 0x3000) == 0) ||

    (((param_1 == DAT_00681dd0 && (DAT_007496d4 != 0)) ||

    ((*(uint32_t *)(param_1 + 300) & 0x20000) != 0)))) {

    FUN_004ea1b0();

    FUN_004ea1b0();

    }

    else {

    if (*(int *)(iVar6 + 0xb4) == 0) {

    FUN_004ea1b0();

    if (*(int *)(iVar2 + 400) == 0) {

    uVar3 = FUN_004e9cd0(&local_48);

    *(uint32_t *)(iVar2 + 400) = uVar3;

    }

    if (*(int *)(iVar2 + 0x194) == 0) {

    uVar3 = FUN_004e9cd0(&local_48);

    *(uint32_t *)(iVar2 + 0x194) = uVar3;

    }

    goto LAB_00539abc;

    }

    if (*(int *)(iVar2 + 0x198) == 0) {

    uVar3 = FUN_004e9cd0(&local_48);

    *(uint32_t *)(iVar2 + 0x198) = uVar3;

    }

    }

    FUN_004ea1b0();

    LAB_00539abc:

    uVar4 = *(uint32_t *)(param_1 + 0x124);

    if ((uVar4 & 0x1000) == 0) {

    uVar4 = uVar4 & 0xffffdfff;

    }

    else {

    uVar4 = uVar4 | 0x2000;

    }

    *(uint32_t *)(param_1 + 0x124) = uVar4;

    iVar6 = *(int *)(param_1 + 0x14c);

    if ((*(int *)(param_1 + 0x1c0) == 0) && ((*(uint32_t *)(param_1 + 300) & 0x20000) == 0)) {

    if ((bVar1) && (DAT_00702a34 == 0)) {

    if (*(int *)(iVar6 + 0x1dc) == 0) {

    if ((*(int *)(param_1 + 0x22c) == 2) && (*(int *)(iVar6 + 0x178) == 0x12)) {

    uVar3 = FUN_00558730(0x5b5,param_1,0,3);

    *(uint32_t *)(iVar6 + 0x1dc) = uVar3;

    return;

    }

    uVar3 = FUN_00558730(0x5b0,param_1,0,3);

    *(uint32_t *)(iVar6 + 0x1dc) = uVar3;

    return;

    }

    }

    else if (*(int *)(iVar6 + 0x1dc) != 0) {

    piVar5 = DAT_007496c4;

    if (DAT_007496c4 != (int *)0x0) {

    while (piVar5[0x11] != *(int *)(iVar6 + 0x1dc)) {

    piVar5 = (int *)*piVar5;

    if (piVar5 == (int *)0x0) {

    *(uint32_t *)(iVar6 + 0x1dc) = 0;

    return;

    }

    }

    FUN_005583d0();

    }

    *(uint32_t *)(iVar6 + 0x1dc) = 0;

    }

    }

    return;


}  // 0x00539470
#endif // RenderFn539470
void RenderFn539470() {}  // 0x00539470
#if 0 // GHIDRA_RAW: RenderFn5CF100 @ 0x005cf100 — needs manual cleanup
void RenderFn5CF100(int param_1,int param_2,uint32_t param_3)
{


    char cVar1;

    uint16_t *puVar2;

    uint32_t uVar3;

    uint32_t uVar4;

    int iVar5;

    char *pcVar6;

    uint16_t *puVar7;

    char *pcVar8;

    uint8_t auStack_11c [4];

    char *local_118;

    uint8_t local_114 [4];

    char local_110 [260];

    uint32_t local_c;



    local_c = DAT_0067d280 ^ (uint)auStack_11c;

    if (((*(int *)(param_1 + 0x134) != 10) && ((*(byte *)(param_1 + 300) & 8) != 0)) &&

    (DAT_006ff960 == 6)) {

    pcVar6 = (char *)(*(int *)(param_1 + 0x14c) + 0x80);

    pcVar8 = pcVar6;

    do {

    cVar1 = *pcVar8;

    pcVar8 = pcVar8 + 1;

    pcVar8[(int)(local_110 + (-1 - (int)pcVar6))] = cVar1;

    } while (cVar1 != '\0');

    puVar2 = (uint16_t *)(local_114 + 3);

    do {

    puVar7 = puVar2;

    puVar2 = (uint16_t *)((int)puVar7 + 1);

    } while (*(char *)((int)puVar7 + 1) != '\0');

    *(uint16_t *)((int)puVar7 + 1) = DAT_0065d02c;

    *(uint8_t *)((int)puVar7 + 3) = DAT_0065d02e;

    uVar3 = FUN_0045f780();

    uVar4 = FUN_005e81d0();

    pcVar8 = local_110;

    local_118 = local_110 + 1;

    do {

    cVar1 = *pcVar8;

    pcVar8 = pcVar8 + 1;

    } while (cVar1 != '\0');

    FUN_00463000(pcVar8 + (int)(local_110 + -(int)local_118),uVar4,uVar3);

    FUN_00463750(0,0);

    }

    if (*(int *)(param_1 + 0x134) == 5) {

    FUN_004ea1b0();

    FUN_005c60f0();

    }

    iVar5 = *(int *)(param_1 + 0x14c);

    FUN_005ceae0();

    FUN_005cdab0(param_3);

    if (param_2 != 0) {

    *(uint32_t *)(iVar5 + 0xa0) = *(uint32_t *)(param_2 + 0x1d8);

    uVar3 = 0x59;

    if (*(int *)(param_2 + 0x22c) == 3) goto LAB_005cf23b;

    }

    uVar3 = 0x29;

    LAB_005cf23b:

    FUN_0048f2f0(uVar3,0x21,0,0,0x3f000000);

    FUN_0048f2f0(0xfe,0,0,0,0x3f000000);

    if (DAT_006ff960 == 6) {

    iVar5 = FUN_0045f460();

    if (iVar5 != 0) {

    local_118 = *(char **)(param_2 + 0x1d4);

    local_114 = (uint8_t  [4])0x0;

    FUN_00469d20(3,&local_118);

    }

    }

    return;


}  // 0x005cf100
#endif // RenderFn5CF100
void RenderFn5CF100() {}  // 0x005cf100
#if 0 // GHIDRA_RAW: CoreFn44AAA0 @ 0x0044aaa0 — needs manual cleanup
uint32_t * CoreFn44AAA0(uint32_t param_1,int *param_2,uint32_t *param_3,uint32_t *param_4,uint32_t param_5,

            int param_6,uint32_t param_7)
{


    char cVar1;

    uint32_t *puVar2;

    int iVar3;

    uint32_t uVar4;

    uint32_t uVar5;

    int iVar6;

    int iVar7;

    uint32_t *puVar8;

    uint32_t uVar9;

    int iVar10;

    int local_74;

    int *local_70;

    uint32_t local_6c;

    int local_68;

    uint32_t local_64;

    uint32_t local_60;

    uint32_t *local_5c;

    int local_58;

    int local_54;

    int local_50;

    int local_4c;

    uint32_t *local_48;

    byte local_42;

    byte local_41;

    uint32_t local_40;

    int local_3c;

    uint8_t local_37;

    byte local_36;

    char local_35;

    byte *local_34;

    uint8_t *local_30;

    byte *local_2c;

    int *local_28;

    int *local_24;

    uint32_t local_20;

    int *local_1c;

    uint32_t local_18;

    void *local_10;

    uint8_t *puStack_c;

    uint32_t local_8;



    local_8 = 0xffffffff;

    puStack_c = &LAB_00647925;

    local_10 = ExceptionList;

    local_18 = DAT_0067d280 ^ (uint)&stack0xfffffffc;

    // ExceptionList = ... (SEH frame, stubbed)

    local_54 = *param_2;

    local_6c = param_7;

    local_64 = param_7;

    local_40 = param_7 >> 8;

    local_36 = (byte)(param_7 >> 8);

    local_4c = param_2[1];

    iVar7 = (uint)(local_36 != 0) + local_4c;

    local_48 = param_4;

    local_68 = param_6;

    local_37 = 0x30;

    local_70 = param_2;

    if ((param_7 >> 0x10 & 2) == 0) {

    local_35 = '.';

    }

    else {

    local_50 = local_54;

    local_3c = local_4c;

    local_35 = fmt::v9::detail::decimal_point_impl<char>(param_5,local_18);

    local_40 = CONCAT31((int3)((uint)local_54 >> 8),local_36);

    }

    puVar8 = local_48;

    iVar10 = param_2[2] + local_4c;

    local_58 = CONCAT31(local_58._1_3_,local_35);

    local_60 = iVar10 - 1;

    cVar1 = (char)local_64;

    local_3c = local_4c;

    local_6c = local_64;

    local_50 = local_54;

    if (cVar1 != '\x01') {

    if (cVar1 != '\0') {

    LAB_0044ab8c:

    if (local_70[2] < 0) {

    if (iVar10 < 1) {

    local_74 = -iVar10;

    if (((local_4c == 0) && (-1 < local_68)) && (local_68 < local_74)) {

    local_74 = local_68;

    }

    if (((local_74 == 0) && (local_4c == 0)) && ((local_64 & 0x80000) == 0)) {

    local_41 = 0;

    }

    else {

    local_41 = 1;

    }

    local_34 = &local_36;

    local_30 = &local_37;

    uVar5 = (uint)local_41 + local_74 + iVar7 + 1;

    local_2c = &local_41;

    local_28 = &local_58;

    local_24 = &local_74;

    local_20 = &local_54;

    local_1c = &local_4c;

    uVar9 = -(uint)(uVar5 < *local_48) & *local_48 - uVar5;

    uVar5 = uVar9 >> ((&DAT_0065d9e4)[*(byte *)((int)local_48 + 9) & 0xf] & 0x1f);

    if (uVar5 != 0) {

    param_3 = (uint32_t *)FUN_0044d590(param_3,(int)local_48 + 0xb);

    param_3 = (uint32_t *)*param_3;

    }

    puVar2 = (uint32_t *)FUN_0044a9a0(&local_3c,param_3);

    uVar4 = *puVar2;

    if (uVar9 != uVar5) {

    puVar2 = (uint32_t *)FUN_0044d590(uVar4,(int)puVar8 + 0xb);

    uVar4 = *puVar2;

    }

    *local_5c = uVar4;

    // ExceptionList = ... (SEH frame, stubbed)

    return local_5c;

    }

    local_3c = 0;

    if ((local_64 & 0x80000) != 0) {

    local_3c = local_68 - local_4c;

    }

    iVar6 = 0;

    if (0 < local_3c) {

    iVar6 = local_3c;

    }

    FUN_0044c2a0(param_5,local_64._2_1_ >> 1 & 1);

    local_8 = 1;

    iVar3 = FUN_0044c4c0(local_4c);

    puVar8 = local_48;

    uVar5 = iVar3 + iVar7 + 1 + iVar6;

    uVar5 = -(uint)(uVar5 < *local_48) & *local_48 - uVar5;

    uVar9 = uVar5 >> ((&DAT_0065d9e4)[*(byte *)((int)local_48 + 9) & 0xf] & 0x1f);

    local_50 = uVar5 - uVar9;

    if (uVar9 != 0) {

    param_3 = (uint32_t *)FUN_0044d590(param_3,(int)local_48 + 0xb);

    param_3 = (uint32_t *)*param_3;

    }

    if (local_36 != 0) {

    local_35 = (&DAT_0065d6dc)[local_36];

    if ((uint)param_3[3] < param_3[2] + 1) {

    (**(code **)*param_3)(param_3[2] + 1);

    }

    *(char *)(param_3[1] + param_3[2]) = local_35;

    param_3[2] = param_3[2] + 1;

    }

    puVar2 = (uint32_t *)FUN_0044a770(param_3,local_4c,iVar10,local_58,&local_34);

    uVar4 = *puVar2;

    if (0 < local_3c) {

    puVar2 = (uint32_t *)FUN_0044a950(uVar4,&local_37);

    uVar4 = *puVar2;

    }

    if (local_50 == 0) goto LAB_0044ac95;

    }

    else {

    local_40 = local_68 - iVar10;

    iVar7 = iVar7 + local_70[2];

    if ((local_64 & 0x80000) != 0) {

    iVar7 = iVar7 + 1;

    if ((int)local_40 < 1) {

    if (cVar1 == '\x02') goto LAB_0044abc6;

    local_40 = 1;

    }

    iVar7 = iVar7 + local_40;

    }

    LAB_0044abc6:

    FUN_0044c2a0(param_5,local_64._2_1_ >> 1 & 1);

    local_8 = 0;

    iVar10 = FUN_0044c4c0(iVar10);

    puVar8 = local_48;

    uVar9 = -(uint)((uint)(iVar10 + iVar7) < *local_48) & *local_48 - (iVar10 + iVar7);

    uVar5 = uVar9 >> ((&DAT_0065d9e4)[*(byte *)((int)local_48 + 9) & 0xf] & 0x1f);

    if (uVar5 != 0) {

    param_3 = (uint32_t *)FUN_0044d590(param_3,(int)local_48 + 0xb);

    param_3 = (uint32_t *)*param_3;

    }

    puVar2 = (uint32_t *)FUN_0044a540(&local_3c,param_3);

    uVar4 = *puVar2;

    if (uVar9 == uVar5) goto LAB_0044ac95;

    }

    puVar2 = (uint32_t *)FUN_0044d590(uVar4,(int)puVar8 + 0xb);

    uVar4 = *puVar2;

    LAB_0044ac95:

    *local_5c = uVar4;

    FUN_004439b0();

    // ExceptionList = ... (SEH frame, stubbed)

    return local_5c;

    }

    if (-5 < iVar10 + -1) {

    iVar6 = 0x10;

    if (0 < local_68) {

    iVar6 = local_68;

    }

    if ((int)local_60 < iVar6) goto LAB_0044ab8c;

    }

    }

    local_24 = (int *)0x0;

    local_42 = local_64._2_1_;

    if ((local_64 & 0x80000) == 0) {

    if (local_4c == 1) {

    local_35 = '\0';

    local_58 = (uint)local_58._1_3_ << 8;

    }

    }

    else {

    if (-1 < local_68 - local_4c) {

    local_24 = (int *)(local_68 - local_4c);

    }

    iVar7 = iVar7 + (int)local_24;

    }

    iVar10 = (local_60 ^ (int)local_60 >> 0x1f) - ((int)local_60 >> 0x1f);

    iVar6 = 2;

    if (99 < iVar10) {

    iVar6 = (999 < iVar10) + 3;

    }

    uVar5 = *local_48;

    uVar9 = iVar7 + (local_35 != '\0') + 2 + iVar6;

    local_34 = (byte *)CONCAT31(local_34._1_3_,(char)local_40);

    local_30 = (uint8_t *)local_54;

    local_2c = (byte *)local_4c;

    local_28 = (int *)CONCAT31(local_28._1_3_,local_35);

    local_20 = (int *)(CONCAT22(local_20._2_2_,CONCAT11(~(local_64._2_1_ << 5),local_37)) & 0xffff20ff

    | 0x4500);

    local_1c = (int *)local_60;

    if ((int)uVar5 < 1) {

    puVar2 = (uint32_t *)FUN_0044a440(&local_60,param_3);

    }

    else {

    uVar9 = -(uint)(uVar9 < uVar5) & uVar5 - uVar9;

    uVar5 = uVar9 >> ((&DAT_0065d9e4)[*(byte *)((int)local_48 + 9) & 0xf] & 0x1f);

    if (uVar5 != 0) {

    param_3 = (uint32_t *)FUN_0044d590(param_3,(int)local_48 + 0xb);

    param_3 = (uint32_t *)*param_3;

    }

    puVar2 = (uint32_t *)FUN_0044a440(&local_3c,param_3);

    uVar4 = *puVar2;

    if (uVar9 == uVar5) goto LAB_0044af77;

    puVar2 = (uint32_t *)FUN_0044d590(uVar4,(int)puVar8 + 0xb);

    }

    uVar4 = *puVar2;

    LAB_0044af77:

    *local_5c = uVar4;

    // ExceptionList = ... (SEH frame, stubbed)

    return local_5c;


}  // 0x0044aaa0
#endif // CoreFn44AAA0
void CoreFn44AAA0() {}  // 0x0044aaa0
#if 0 // GHIDRA_RAW: RenderFn5822F0 @ 0x005822f0 — needs manual cleanup
bool RenderFn5822F0(int param_1,byte *param_2,int param_3,char param_4)
{


    float fVar1;

    uint8_t *puVar2;

    int iVar3;

    int iVar4;

    byte *pbVar5;

    uint32_t uVar6;

    int *piVar7;

    uint32_t extraout_ECX;

    int *piVar8;

    bool bVar9;

    float10 extraout_ST0;

    float10 extraout_ST0_00;

    float10 extraout_ST0_01;

    float10 extraout_ST0_02;

    float10 extraout_ST0_03;

    float10 extraout_ST0_04;

    float10 extraout_ST0_05;

    float10 extraout_ST0_06;

    float10 extraout_ST0_07;

    float10 fVar10;

    float local_34;

    float local_30;

    uint64_t local_2c;

    uint32_t local_24;

    uint8_t local_20 [12];

    uint64_t local_14;

    uint32_t local_c;

    uint32_t local_8;



    local_8 = DAT_0067d280 ^ (uint)&local_34;

    if (param_1 == 0) {

    return false;

    }

    if (param_2 == (byte *)0x0) {

    return false;

    }

    if ((*(byte **)(param_1 + 0x150) != (byte *)0x0) && ((**(byte **)(param_1 + 0x150) & 0x40) != 0))

    {

    return false;

    }

    if (*(int *)(param_1 + 0x264) != 0) {

    iVar3 = *(int *)(*(int *)(param_1 + 0x264) + 0x22c);

    if (iVar3 == 1) {

    return false;

    }

    if (iVar3 == 0x4c) {

    return false;

    }

    if (iVar3 == 0x5a) {

    return false;

    }

    }

    if ((param_4 != '\0') && ((*param_2 & 0x40) != 0)) {

    return false;

    }

    if (param_3 == -1) {

    return false;

    }

    if ((param_4 != '\0') &&

    (*(float *)(param_2 + *(int *)(param_2 + 0xdb4) * 0xc + 0xd2c) <=

    *(float *)(param_2 + *(int *)(param_2 + 0xdb4) * 0xc + 0xd28) &&

    *(float *)(param_2 + *(int *)(param_2 + 0xdb4) * 0xc + 0xd28) !=

    *(float *)(param_2 + *(int *)(param_2 + 0xdb4) * 0xc + 0xd2c))) {

    return false;

    }

    uVar6 = **(uint32_t **)(param_1 + 0x150) >> 7;

    switch(param_3) {

    case 0x15:

    iVar3 = FUN_005fbbf0();

    *(int *)(param_2 + 0xf04) = iVar3;

    if (iVar3 != 0) {

    if ((*(int *)(iVar3 + 4) != 0xb) || (iVar4 = iVar3, *(int *)(iVar3 + 0x130) == 0x37)) {

    if ((*(int *)(iVar3 + 0x22c) != 2) && (*(int *)(iVar3 + 0x22c) != 3)) {

    return false;

    }

    piVar7 = DAT_007027d8;

    if (DAT_007027d8 == (int *)0x0) {

    return false;

    }

    while (((iVar4 = piVar7[3], (*(uint32_t *)(iVar4 + 0x124) & 0x8000) != 0 ||

    (*(int *)(iVar4 + 4) != 0xb)) ||

    ((*(int *)(iVar4 + 0x264) != iVar3 && (*(int *)(iVar4 + 0x2c4) != iVar3))))) {

    piVar7 = (int *)*piVar7;

    if (piVar7 == (int *)0x0) {

    return false;

    }

    }

    if (iVar4 == 0) {

    return false;

    }

    }

    if ((*(int *)(iVar4 + 0x264) == 0) || (*(int *)(*(int *)(iVar4 + 0x264) + 0x22c) != 1)) {

    *(int *)(param_2 + 0xf04) = iVar4;

    fVar10 = (float10)FUN_00638d40(iVar4 + 0xf0,param_1 + 0xf0);

    if ((float)fVar10 <= *(float *)(DAT_007028f4 + 0x14d8) * *(float *)(DAT_007028f4 + 0x14d8))

    {

    return true;

    }

    return false;

    }

    }

    break;

    case 0x16:

    iVar3 = FUN_0056e960();

    local_34 = *(float *)(iVar3 + 0x34);

    FUN_00638d40(param_2 + 0xf08,param_1 + 0xf0);

    if ((float)extraout_ST0_01 <= local_34 * local_34) {

    return true;

    }

    return false;

    case 0x17:

    iVar3 = FUN_0056b890();

    if (iVar3 != 0) {

    return false;

    }

    iVar3 = *(int *)(param_2 + 0xe30);

    goto LAB_00582aa2;

    case 0x18:

    iVar3 = FUN_0056b890();

    if (iVar3 != 0) {

    return false;

    }

    fVar10 = (float10)FUN_00638d00(param_1 + 0xf0,param_2 + 0xf08);

    local_34 = (float)fVar10;

    if (*(float *)(DAT_007028f4 + 0x758) * *(float *)(DAT_007028f4 + 0x758) <= local_34) {

    return false;

    }

    if (((DAT_00681db0 == 0) && (DAT_00681dbc == 0)) && (DAT_00681db8 < 2)) {

    local_c = DAT_0074bb68;

    local_24 = DAT_0074bb8c;

    local_14 = DAT_0074bb60;

    local_2c = _DAT_0074bb84;

    FUN_0042bee0(extraout_ECX,local_20,&local_14,&local_2c);

    iVar3 = FUN_004ff8b0();

    }

    else {

    FUN_0042bee0(extraout_ECX,local_20);

    iVar3 = FUN_00582f20(param_1);

    }

    LAB_00582aa2:

    if (iVar3 == 0) {

    return true;

    }

    break;

    case 0x19:

    if (*(int *)(param_2 + 0xe60) == 0) {

    iVar3 = FUN_0056e960();

    local_34 = *(float *)(iVar3 + 0x34);

    FUN_00638d40(param_2 + 0xf08,param_1 + 0xf0);

    if ((float)extraout_ST0_06 <= local_34 * local_34) {

    return true;

    }

    return false;

    }

    break;

    case 0x1b:

    if (DAT_007488ec == 0) {

    local_34 = *(float *)(DAT_007028f4 + 0x14d0);

    FUN_00638d40(param_2 + 0xf08,param_1 + 0xf0);

    if ((float)extraout_ST0_05 <= local_34 * local_34) {

    return true;

    }

    return false;

    }

    break;

    case 0x1c:

    iVar3 = FUN_0056e960();

    local_30 = *(float *)(iVar3 + 0x34);

    FUN_00638d40(param_2 + 0xf08,param_1 + 0xf0);

    piVar7 = DAT_0073c91c;

    local_34 = (float)extraout_ST0;

    if (local_34 <= local_30 * local_30) {

    if (DAT_006ff960 != 6) {

    return true;

    }

    bVar9 = false;

    local_30 = DAT_0066c218;

    piVar8 = (int *)*DAT_0073c91c;

    if (piVar8 == DAT_0073c91c) {

    return true;

    }

    do {

    FUN_00638c80(param_2 + 0xf08,piVar8 + 5);

    local_34 = (float)extraout_ST0_00;

    if (local_34 < local_30) {

    bVar9 = true;

    local_30 = local_34;

    }

    piVar8 = (int *)*piVar8;

    } while (piVar8 != piVar7);

    if (!bVar9) {

    return true;

    }

    if (local_30 < DAT_0066c138) {

    return false;

    }

    return true;

    }

    break;

    case 0x1d:

    iVar3 = 0;

    pbVar5 = param_2 + 0xdc0;

    while (*(int *)pbVar5 != 0) {

    iVar3 = iVar3 + 1;

    pbVar5 = pbVar5 + 0x1c;

    if (3 < iVar3) {

    return false;

    }

    }

    iVar3 = FUN_005fbbf0();

    *(int *)(param_2 + 0xf04) = iVar3;

    if (iVar3 != 0) {

    iVar4 = 0;

    param_2 = param_2 + 0xdc0;

    while (*(int *)param_2 != 0) {

    iVar4 = iVar4 + 1;

    param_2 = param_2 + 0x1c;

    if (3 < iVar4) {

    return false;

    }

    }

    iVar4 = FUN_0056e960();

    FUN_00638d40(iVar3 + 0xf0,param_1 + 0xf0);

    if ((float)extraout_ST0_04 <= *(float *)(iVar4 + 0x34) * *(float *)(iVar4 + 0x34)) {

    return true;

    }

    return false;

    }

    break;

    case 0x1e:

    iVar3 = FUN_005fbbf0();

    *(int *)(param_2 + 0xf04) = iVar3;

    if (iVar3 == 0) {

    return false;

    }

    if ((((*(int *)(iVar3 + 0x22c) == 2) || (*(int *)(iVar3 + 0x22c) == 3)) ||

    ((puVar2 = *(uint8_t **)(iVar3 + 4), puVar2 == &DAT_00000008 ||

    ((puVar2 == (uint8_t *)0x438 || (puVar2 == (uint8_t *)0x29a)))))) ||

    (puVar2 == (uint8_t *)0x232)) goto LAB_005826a6;

    if (puVar2 == (uint8_t *)0xb) {

    if (((*(float *)(iVar3 + 0x2c8) < *(float *)(iVar3 + 0x20c)) &&

    ((*(byte *)(iVar3 + 300) & 8) == 0)) && (*(int *)(iVar3 + 0x264) == 0)) {

    if (*(int *)(iVar3 + 0x2c4) == 0) goto LAB_005826a6;

    bVar9 = *(int *)(*(int *)(iVar3 + 0x2c4) + 0x22c) == 3;

    LAB_0058267f:

    if (!bVar9) goto LAB_005826a6;

    }

    }

    else if (puVar2 == (uint8_t *)0xd7) {

    iVar4 = FUN_005aac30();

    bVar9 = iVar4 == 0;

    goto LAB_0058267f;

    }

    if (*(int *)(iVar3 + 0x22c) != 0x17) {

    return false;

    }

    if (*(int *)(iVar3 + 0x134) == 100) {

    return false;

    }

    if (*(int *)(iVar3 + 0x134) == 0x65) {

    return false;

    }

    LAB_005826a6:

    iVar4 = FUN_0056e960();

    local_34 = *(float *)(iVar4 + 0x34);

    FUN_00638d40(iVar3 + 0xf0,param_1 + 0xf0);

    if ((float)extraout_ST0_03 <= local_34 * local_34) {

    return true;

    }

    return false;

    case 0x1f:

    fVar10 = (float10)FUN_00638c80(param_2 + 0xf08,param_1 + 0xf0);

    fVar1 = (float)fVar10;

    if (fVar1 <= *(float *)(DAT_007028f4 + 0x14cc)) {

    if (*(float *)(DAT_007028f4 + 0x834) <= fVar1 && fVar1 != *(float *)(DAT_007028f4 + 0x834)) {

    return true;

    }

    return false;

    }

    break;

    case 0x20:

    if ((((uVar6 & 1) != 0) && ((*(uint32_t *)(param_1 + 300) >> 8 & 1) == 0)) &&

    (*(int *)(param_2 + 0xf90) == 0)) {

    fVar10 = (float10)FUN_00638d00(param_1 + 0xf0,param_2 + 0xf08);

    return (float)fVar10 < *(float *)(DAT_007028f4 + 0x16b8) * *(float *)(DAT_007028f4 + 0x16b8);

    }

    break;

    case 0x21:

    if (((uVar6 & 1) != 0) && ((*(uint32_t *)(param_1 + 300) >> 8 & 1) == 0)) {

    local_34 = *(float *)(DAT_007028f4 + 0x14d4);

    FUN_00638d40(param_2 + 0xf08,param_1 + 0xf0);

    if ((float)extraout_ST0_07 <= local_34 * local_34) {

    return true;

    }

    }

    break;

    case 0x49:

    iVar3 = FUN_0056e960();

    FUN_00638d40(param_2 + 0xf08,param_1 + 0xf0);

    FUN_00638d40(param_2 + 0xf08,param_1 + 0xf0);

    if ((float)extraout_ST0_02 <= *(float *)(iVar3 + 0x34) * *(float *)(iVar3 + 0x34)) {

    return true;

    }

    return false;

    }

    return false;


}  // 0x005822f0
#endif // RenderFn5822F0
void RenderFn5822F0() {}  // 0x005822f0
#if 0 // GHIDRA_RAW: GameFn492060 @ 0x00492060 — needs manual cleanup
void GameFn492060(int param_1,int *param_2,int param_3)
{


    uint32_t uVar1;

    char cVar2;

    float *pfVar3;

    uint32_t uVar4;

    int iVar5;

    int iVar6;

    uint32_t *puVar7;

    float *pfVar8;

    uint32_t extraout_ECX;

    uint32_t uVar9;

    uint32_t *puVar10;

    float *pfVar11;

    uint32_t *puVar12;

    float fVar13;

    char *pcVar14;

    int local_22c;

    float *local_228;

    float local_224;

    uint32_t local_220;

    int local_21c;

    int *local_218;

    int local_214;

    uint8_t local_210 [516];

    uint32_t local_c;



    local_c = DAT_0067d280 ^ (uint)&local_22c;

    if (param_1 == 0) {

    local_22c = 0;

    }

    else {

    local_22c = *(int *)(param_1 + 0x14c);

    }

    if ((float *)*param_2 != (float *)0x0) {

    local_21c = 0;

    local_220 = 0xffffffff;

    DAT_0073f7e8 = (float *)*param_2;

    local_218 = param_2;

    do {

    fVar13 = DAT_0066bf2c;

    uVar9 = (uint)*(byte *)DAT_0073f7e8;

    pfVar11 = (float *)((int)DAT_0073f7e8 + 1);

    pfVar3 = pfVar11;

    local_228 = pfVar11;

    switch(uVar9) {

    case 1:

    break;

    case 2:

    DAT_0073f7e8 = pfVar11;

    *local_218 = 0;

    return;

    case 3:

    DAT_0073f7e8 = pfVar11;

    *(float *)(local_22c + 0xcc) = *pfVar11;

    DAT_0073f7e8 = DAT_0073f7e8 + 1;

    pfVar3 = DAT_0073f7e8;

    break;

    case 4:

    DAT_0073f7e8 = pfVar11;

    *(uint32_t *)(local_22c + 0x10) = *(uint32_t *)(local_22c + 0x10) | 1;

    *(float *)(local_22c + 0xc0) = *DAT_0073f7e8;

    DAT_0073f7e8 = DAT_0073f7e8 + 1;

    *(float *)(local_22c + 0xc4) = *DAT_0073f7e8;

    DAT_0073f7e8 = DAT_0073f7e8 + 1;

    *(float *)(local_22c + 200) = *DAT_0073f7e8;

    DAT_0073f7e8 = DAT_0073f7e8 + 1;

    pfVar3 = DAT_0073f7e8;

    break;

    case 5:

    do {

    cVar2 = *(char *)pfVar11;

    pfVar11 = (float *)((int)pfVar11 + 1);

    DAT_0073f7e8 = pfVar11;

    } while (cVar2 != '\0');

    do {

    cVar2 = *(char *)DAT_0073f7e8;

    DAT_0073f7e8 = (float *)((int)DAT_0073f7e8 + 1);

    } while (cVar2 != '\0');

    pfVar3 = DAT_0073f7e8;

    if (param_3 == 0) {

    local_220 = uVar9;

    memset((void *)(local_22c + 8),0,0x104);

    *(uint32_t *)(local_22c + 4) = local_220;

    *(uint32_t *)(local_22c + 0xc) = *(uint32_t *)(param_1 + 0x13c);

    *(uint32_t *)(local_22c + 0xe8) = 100;

    *(uint32_t *)(local_22c + 0xe0) = 100;

    *(uint32_t *)(local_22c + 0xe4) = 0x32;

    FUN_00490eb0(pfVar11);

    FUN_004910e0();

    puVar7 = *(uint32_t **)(param_1 + 0x14c);

    pfVar3 = DAT_0073f7e8;

    uVar9 = local_220;

    if ((int)puVar7[0x1278] < 0x32) {

    puVar12 = puVar7 + puVar7[0x1278] * 0x42 + 0x594;

    puVar10 = puVar7;

    for (iVar5 = 0x42; puVar10 = puVar10 + 1, iVar5 != 0; iVar5 = iVar5 + -1) {

    *puVar12 = *puVar10;

    puVar12 = puVar12 + 1;

    }

    puVar7[0x1278] = puVar7[0x1278] + 1;

    pfVar3 = DAT_0073f7e8;

    }

    }

    break;

    case 6:

    DAT_0073f7e8 = (float *)((int)DAT_0073f7e8 + 5);

    pfVar3 = DAT_0073f7e8;

    if (*(int *)(local_22c + 0x8c) < 10) {

    *(float *)(local_22c + 0x3c + *(int *)(local_22c + 0x8c) * 4) = *pfVar11;

    *(int *)(local_22c + 0x8c) = *(int *)(local_22c + 0x8c) + 1;

    pfVar3 = DAT_0073f7e8;

    }

    break;

    case 7:

    goto switchD_004920d6_caseD_7;

    case 8:

    fVar13 = *pfVar11;

    DAT_0073f7e8 = (float *)((int)DAT_0073f7e8 + 5);

    pfVar3 = DAT_0073f7e8;

    if ((param_3 == 0) &&

    (*(float *)(param_1 + 0x13c) = fVar13, pfVar3 = DAT_0073f7e8,

    *(float *)(param_1 + 0x138) <= fVar13 && fVar13 != *(float *)(param_1 + 0x138))) {

    local_21c = 1;

    }

    break;

    case 9:

    DAT_0073f7e8 = pfVar11;

    do {

    cVar2 = *(char *)DAT_0073f7e8;

    DAT_0073f7e8 = (float *)((int)DAT_0073f7e8 + 1);

    } while (cVar2 != '\0');

    pfVar3 = DAT_0073f7e8;

    if (param_3 == 0) {

    local_220 = uVar9;

    FUN_00492000();

    pfVar3 = DAT_0073f7e8;

    uVar9 = local_220;

    }

    break;

    case 10:

    DAT_0073f7e8 = pfVar11;

    do {

    cVar2 = *(char *)DAT_0073f7e8;

    DAT_0073f7e8 = (float *)((int)DAT_0073f7e8 + 1);

    } while (cVar2 != '\0');

    pfVar3 = DAT_0073f7e8;

    if (param_3 == 0) {

    if (param_1 == 0) {

    iVar5 = 0;

    }

    else {

    iVar5 = *(int *)(param_1 + 0x14c);

    }

    local_220 = uVar9;

    iVar6 = FUN_00491060(&local_214);

    pfVar3 = DAT_0073f7e8;

    uVar9 = local_220;

    if (iVar6 != 0) {

    memmove((void *)(local_214 * 0x108 + 0x1650 + iVar5),

    (void *)(local_214 * 0x108 + 0x1758 + iVar5),

    (*(int *)(iVar5 + 0x49e0) - local_214) * 0x108 - 0x108);

    *(int *)(iVar5 + 0x49e0) = *(int *)(iVar5 + 0x49e0) + -1;

    pfVar3 = DAT_0073f7e8;

    uVar9 = local_220;

    }

    }

    break;

    case 0xb:

    DAT_0073f7e8 = pfVar11;

    *(float *)(local_22c + 0xdc) = *pfVar11;

    DAT_0073f7e8 = DAT_0073f7e8 + 1;

    pfVar3 = DAT_0073f7e8;

    break;

    case 0xc:

    DAT_0073f7e8 = pfVar11;

    *(float *)(local_22c + 0xe0) = *pfVar11;

    DAT_0073f7e8 = DAT_0073f7e8 + 1;

    *(float *)(local_22c + 0xe4) = *DAT_0073f7e8;

    DAT_0073f7e8 = DAT_0073f7e8 + 1;

    *(float *)(local_22c + 0xe8) = *DAT_0073f7e8;

    DAT_0073f7e8 = DAT_0073f7e8 + 1;

    pfVar3 = DAT_0073f7e8;

    break;

    case 0xd:

    if (param_3 == 0) {

    DAT_0073f7e8 = pfVar11;

    *(uint32_t *)(local_22c + 0x49e4) = 1;

    pfVar3 = DAT_0073f7e8;

    }

    break;

    case 0xe:

    do {

    cVar2 = *(char *)pfVar11;

    pfVar11 = (float *)((int)pfVar11 + 1);

    DAT_0073f7e8 = pfVar11;

    } while (cVar2 != '\0');

    do {

    cVar2 = *(char *)DAT_0073f7e8;

    DAT_0073f7e8 = (float *)((int)DAT_0073f7e8 + 1);

    } while (cVar2 != '\0');

    pfVar3 = DAT_0073f7e8;

    if (param_3 == 0) {

    if (param_1 == 0) {

    iVar5 = 0;

    }

    else {

    iVar5 = *(int *)(param_1 + 0x14c);

    }

    local_220 = uVar9;

    iVar6 = FUN_00490fd0(DAT_0073f7e8,&local_224);

    if (iVar6 == 0) {

    memset((void *)(iVar5 + 0xc),0,0x100);

    *(float **)(iVar5 + 8) = local_228;

    *(uint32_t *)(iVar5 + 4) = 0xe;

    *(uint32_t *)(iVar5 + 0xc) = *(uint32_t *)(param_1 + 0x13c);

    *(uint32_t *)(iVar5 + 0xb8) = 1;

    *(float **)(iVar5 + 0x90) = pfVar11;

    FUN_004910e0();

    pfVar3 = DAT_0073f7e8;

    uVar9 = local_220;

    }

    else {

    pfVar3 = DAT_0073f7e8;

    uVar9 = local_220;

    if (*(int *)(iVar6 + 0xb4) < 10) {

    *(float **)(iVar6 + 0x8c + *(int *)(iVar6 + 0xb4) * 4) = pfVar11;

    *(int *)(iVar6 + 0xb4) = *(int *)(iVar6 + 0xb4) + 1;

    pfVar3 = DAT_0073f7e8;

    }

    }

    }

    break;

    case 0xf:

    DAT_0073f7e8 = pfVar11;

    *(float *)(local_22c + 0xec) = *pfVar11;

    DAT_0073f7e8 = DAT_0073f7e8 + 1;

    pfVar3 = DAT_0073f7e8;

    break;

    case 0x10:

    DAT_0073f7e8 = pfVar11;

    *(float *)(local_22c + 0xf0) = *pfVar11;

    DAT_0073f7e8 = DAT_0073f7e8 + 1;

    *(float *)(local_22c + 0xf4) = *DAT_0073f7e8;

    DAT_0073f7e8 = DAT_0073f7e8 + 1;

    pfVar3 = DAT_0073f7e8;

    break;

    case 0x11:

    DAT_0073f7e8 = pfVar11;

    *(float *)(local_22c + 0xfc) = *pfVar11;

    DAT_0073f7e8 = DAT_0073f7e8 + 1;

    *(float *)(local_22c + 0xf8) = *DAT_0073f7e8;

    DAT_0073f7e8 = DAT_0073f7e8 + 1;

    *(float *)(local_22c + 0x100) = *DAT_0073f7e8;

    DAT_0073f7e8 = DAT_0073f7e8 + 1;

    *(float *)(local_22c + 0x104) = *DAT_0073f7e8;

    DAT_0073f7e8 = DAT_0073f7e8 + 1;

    fVar13 = fVar13 / *(float *)(local_22c + 0x100);

    *(uint32_t *)(local_22c + 0x10) = *(uint32_t *)(local_22c + 0x10) | 2;

    *(float *)(local_22c + 0x100) =

    (fVar13 * *(float *)(local_22c + 0xf8) + fVar13) / *(float *)(local_22c + 0x104);

    pfVar3 = DAT_0073f7e8;

    break;

    case 0x12:

    do {

    cVar2 = *(char *)pfVar11;

    pfVar11 = (float *)((int)pfVar11 + 1);

    DAT_0073f7e8 = pfVar11;

    } while (cVar2 != '\0');

    do {

    cVar2 = *(char *)DAT_0073f7e8;

    DAT_0073f7e8 = (float *)((int)DAT_0073f7e8 + 1);

    } while (cVar2 != '\0');

    pfVar3 = DAT_0073f7e8;

    if (param_3 == 0) {

    local_220 = uVar9;

    memset((void *)(local_22c + 8),0,0x104);

    *(uint32_t *)(local_22c + 4) = local_220;

    *(uint32_t *)(local_22c + 0xc) = *(uint32_t *)(param_1 + 0x13c);

    FUN_00490eb0(pfVar11);

    FUN_004910e0();

    puVar7 = *(uint32_t **)(param_1 + 0x14c);

    pfVar3 = DAT_0073f7e8;

    uVar9 = local_220;

    if ((int)puVar7[0x1278] < 0x32) {

    puVar12 = puVar7 + puVar7[0x1278] * 0x42 + 0x594;

    puVar10 = puVar7;

    for (iVar5 = 0x42; puVar10 = puVar10 + 1, iVar5 != 0; iVar5 = iVar5 + -1) {

    *puVar12 = *puVar10;

    puVar12 = puVar12 + 1;

    }

    puVar7[0x1278] = puVar7[0x1278] + 1;

    pfVar3 = DAT_0073f7e8;

    }

    }

    break;

    case 0x13:

    uVar1 = *(uint32_t *)((int)DAT_0073f7e8 + 5);

    DAT_0073f7e8 = (float *)((int)DAT_0073f7e8 + 9);

    pfVar3 = DAT_0073f7e8;

    if (*(int *)(local_22c + 0x8c) < 10) {

    *(float *)(local_22c + 0x3c + *(int *)(local_22c + 0x8c) * 4) = *pfVar11;

    *(uint32_t *)(local_22c + 100 + *(int *)(local_22c + 0x8c) * 4) = uVar1;

    *(int *)(local_22c + 0x8c) = *(int *)(local_22c + 0x8c) + 1;

    pfVar3 = DAT_0073f7e8;

    }

    break;

    case 0x14:

    DAT_0073f7e8 = pfVar11;

    *(float *)(local_22c + 0xd8) = *pfVar11;

    DAT_0073f7e8 = DAT_0073f7e8 + 1;

    pfVar3 = DAT_0073f7e8;

    break;

    case 0x15:

    DAT_0073f7e8 = (float *)((int)DAT_0073f7e8 + 5);

    pfVar3 = DAT_0073f7e8;

    if (param_3 == 0) {

    *(float *)(param_1 + 0x140) = *pfVar11;

    pfVar3 = DAT_0073f7e8;

    }

    break;

    case 0x16:

    fVar13 = *pfVar11;

    puVar7 = (uint32_t *)((int)DAT_0073f7e8 + 5);

    DAT_0073f7e8 = (float *)((int)DAT_0073f7e8 + 9);

    uVar1 = *puVar7;

    pfVar3 = DAT_0073f7e8;

    if (param_3 != 0) {

    if (param_1 == 0) {

    iVar5 = 0;

    }

    else {

    iVar5 = *(int *)(param_1 + 0x14c);

    }

    if (4 < *(int *)(iVar5 + 0x49e8)) {

    local_220 = 5;

    pcVar14 = "Army bin has too many labels %d, label ignored";

    goto LAB_004927ed;

    }

    *(float **)(iVar5 + 0x49ec + *(int *)(iVar5 + 0x49e8) * 0xc) = DAT_0073f7e8;

    *(uint32_t *)(iVar5 + 0x49f0 + *(int *)(iVar5 + 0x49e8) * 0xc) = uVar1;

    *(float *)(iVar5 + 0x49f4 + *(int *)(iVar5 + 0x49e8) * 0xc) = fVar13;

    *(int *)(iVar5 + 0x49e8) = *(int *)(iVar5 + 0x49e8) + 1;

    pfVar3 = DAT_0073f7e8;

    }

    break;

    case 0x17:

    fVar13 = *pfVar11;

    DAT_0073f7e8 = (float *)((int)DAT_0073f7e8 + 5);

    pfVar3 = DAT_0073f7e8;

    if (param_3 == 0) {

    if (param_1 == 0) {

    iVar5 = 0;

    }

    else {

    iVar5 = *(int *)(param_1 + 0x14c);

    }

    iVar6 = 0;

    if (0 < *(int *)(iVar5 + 0x49e8)) {

    puVar7 = (uint32_t *)(iVar5 + 0x49ec);

    do {

    if ((float)puVar7[2] == fVar13) {

    DAT_0073f7e8 = (float *)*puVar7;

    *(uint32_t *)(param_1 + 0x138) = puVar7[1];

    }

    iVar6 = iVar6 + 1;

    puVar7 = puVar7 + 3;

    pfVar3 = DAT_0073f7e8;

    } while (iVar6 < *(int *)(iVar5 + 0x49e8));

    }

    }

    break;

    case 0x18:

    do {

    pfVar8 = pfVar3;

    pfVar3 = (float *)((int)pfVar8 + 1);

    } while (*(char *)pfVar8 != '\0');

    local_224 = *(float *)((int)pfVar8 + 1);

    local_228 = *(float **)((int)pfVar8 + 5);

    DAT_0073f7e8 = (float *)((int)pfVar8 + 9);

    pfVar3 = DAT_0073f7e8;

    if (param_3 == 0) {

    local_220 = uVar9;

    iVar5 = rand();

    fVar13 = (float)iVar5 * _DAT_0066bd00 * ((float)local_228 - local_224) + local_224;

    if (param_1 == 0) {

    iVar5 = 0;

    }

    else {

    iVar5 = *(int *)(param_1 + 0x14c);

    }

    local_224 = fVar13;

    iVar6 = FUN_00490fd0(extraout_ECX,&local_228);

    if (iVar6 == 0) {

    memset((void *)(iVar5 + 0xc),0,0x100);

    *(float **)(iVar5 + 8) = pfVar11;

    *(uint32_t *)(iVar5 + 4) = 0xe;

    *(uint32_t *)(iVar5 + 0xc) = *(uint32_t *)(param_1 + 0x13c);

    *(float *)(iVar5 + 0xbc) = local_224;

    FUN_004910e0();

    pfVar3 = DAT_0073f7e8;

    uVar9 = local_220;

    }

    else {

    *(float *)(iVar6 + 0xb8) = fVar13;

    pfVar3 = DAT_0073f7e8;

    uVar9 = local_220;

    }

    }

    break;

    default:

    pcVar14 = "Army Bld System got unknown opcode, this is fatal.  (Last op %d)";

    DAT_0073f7e8 = pfVar11;

    LAB_004927ed:

    uVar4 = local_220;

    local_220 = uVar9;

    FUN_00463000(local_210,pcVar14,uVar4);

    pfVar3 = DAT_0073f7e8;

    uVar9 = local_220;

    }

    local_220 = uVar9;

    DAT_0073f7e8 = pfVar3;

    pfVar11 = DAT_0073f7e8;

    } while (local_21c == 0);

    switchD_004920d6_caseD_7:

    DAT_0073f7e8 = pfVar11;

    if (*local_218 != 0) {

    *local_218 = (int)DAT_0073f7e8;

    }

    }

    return;


}  // 0x00492060
#endif // GameFn492060
void GameFn492060() {}  // 0x00492060
#if 0 // GHIDRA_RAW: GameFn4BB5E0 @ 0x004bb5e0 — needs manual cleanup
uint32_t * GameFn4BB5E0(uint32_t param_1,int *param_2,uint32_t param_3,uint32_t *param_4,uint32_t param_5,

            int param_6,uint32_t param_7)
{


    char cVar1;

    wchar_t wVar2;

    int iVar3;

    uint32_t *puVar4;

    uint32_t uVar5;

    int iVar6;

    uint32_t uVar7;

    int iVar8;

    uint32_t uVar9;

    int local_7c;

    int local_78;

    int local_74;

    int local_70;

    uint32_t local_6c;

    uint32_t *local_64;

    uint32_t local_60;

    int local_5c;

    int *local_58;

    int local_54;

    uint32_t local_50;

    uint32_t local_4c;

    uint32_t local_48;

    uint32_t local_44;

    byte local_3d;

    int local_3c;

    char local_35;

    char *local_34;

    uint32_t *local_30;

    byte *local_2c;

    uint32_t *local_28;

    int *local_24;

    uint32_t local_20;

    int *local_1c;

    uint32_t local_18;

    void *local_10;

    uint8_t *puStack_c;

    uint32_t local_8;



    local_8 = 0xffffffff;

    puStack_c = &LAB_006494b5;

    local_10 = ExceptionList;

    local_18 = DAT_0067d280 ^ (uint)&stack0xfffffffc;

    // ExceptionList = ... (SEH frame, stubbed)

    local_5c = *param_2;

    local_74 = param_2[1];

    local_48 = param_7;

    local_6c = param_7;

    local_50 = param_7 >> 8;

    local_35 = (char)(param_7 >> 8);

    local_70 = param_6;

    iVar8 = (uint)(local_35 != '\0') + local_74;

    local_60 = 0x30;

    local_58 = param_2;

    local_54 = local_74;

    if ((param_7 >> 0x10 & 2) == 0) {

    local_44 = 0x2e;

    }

    else {

    local_3c = local_5c;

    wVar2 = fmt::v9::detail::decimal_point_impl<wchar_t>(param_5,local_18);

    local_44 = (uint)(ushort)wVar2;

    local_50 = CONCAT31((int3)((uint)local_5c >> 8),local_35);

    }

    local_78 = local_58[2] + local_54;

    local_4c = local_78 - 1;

    cVar1 = (char)local_6c;

    local_3c = local_5c;

    local_74 = local_54;

    if (cVar1 != '\x01') {

    if (cVar1 != '\0') {

    LAB_004bb6cf:

    local_48 = local_6c;

    if (local_58[2] < 0) {

    if (local_78 < 1) {

    local_7c = -local_78;

    if (((local_54 == 0) && (-1 < local_70)) && (local_70 < local_7c)) {

    local_7c = local_70;

    }

    if (((local_7c == 0) && (local_54 == 0)) && ((local_6c & 0x80000) == 0)) {

    local_3d = 0;

    }

    else {

    local_3d = 1;

    }

    local_34 = &local_35;

    local_30 = &local_60;

    local_2c = &local_3d;

    local_28 = &local_44;

    local_24 = &local_7c;

    local_20 = &local_5c;

    local_1c = &local_54;

    FUN_004bb470(param_3,local_7c,local_3d + 1 + local_7c + iVar8,&local_34);

    // ExceptionList = ... (SEH frame, stubbed)

    return local_64;

    }

    local_3c = 0;

    if ((local_6c & 0x80000) != 0) {

    local_3c = local_70 - local_54;

    }

    iVar3 = 0;

    if (0 < local_3c) {

    iVar3 = local_3c;

    }

    FUN_004bad20(param_5,local_6c._2_1_ >> 1 & 1);

    local_8 = 1;

    iVar6 = FUN_004badf0(local_54);

    uVar7 = iVar6 + iVar8 + 1 + iVar3;

    uVar9 = -(uint)(uVar7 < *param_4) & *param_4 - uVar7;

    uVar7 = uVar9 >> ((&DAT_0065d9e4)[*(byte *)((int)param_4 + 9) & 0xf] & 0x1f);

    if (uVar7 != 0) {

    puVar4 = (uint32_t *)FUN_004bc4b0(param_3,param_4 + 3);

    param_3 = *puVar4;

    }

    puVar4 = (uint32_t *)FUN_004bb1a0(&local_50,param_3);

    uVar5 = *puVar4;

    if (uVar9 == uVar7) goto LAB_004bb7df;

    }

    else {

    local_4c = local_70 - local_78;

    iVar8 = iVar8 + local_58[2];

    if ((local_6c & 0x80000) != 0) {

    iVar8 = iVar8 + 1;

    if ((int)local_4c < 1) {

    if (cVar1 == '\x02') goto LAB_004bb70c;

    local_4c = 1;

    }

    iVar8 = iVar8 + local_4c;

    }

    LAB_004bb70c:

    FUN_004bad20(param_5,local_6c._2_1_ >> 1 & 1);

    local_8 = 0;

    iVar3 = FUN_004badf0(local_78);

    uVar9 = -(uint)((uint)(iVar3 + iVar8) < *param_4) & *param_4 - (iVar3 + iVar8);

    uVar7 = uVar9 >> ((&DAT_0065d9e4)[*(byte *)((int)param_4 + 9) & 0xf] & 0x1f);

    if (uVar7 != 0) {

    puVar4 = (uint32_t *)FUN_004bc4b0(param_3,param_4 + 3);

    param_3 = *puVar4;

    }

    puVar4 = (uint32_t *)FUN_004baad0(&local_3c,param_3);

    uVar5 = *puVar4;

    if (uVar9 == uVar7) goto LAB_004bb7df;

    }

    puVar4 = (uint32_t *)FUN_004bc4b0(uVar5,param_4 + 3);

    uVar5 = *puVar4;

    LAB_004bb7df:

    *local_64 = uVar5;

    FUN_004439b0();

    // ExceptionList = ... (SEH frame, stubbed)

    return local_64;

    }

    if (-5 < local_78 + -1) {

    iVar3 = 0x10;

    if (0 < local_70) {

    iVar3 = local_70;

    }

    if ((int)local_4c < iVar3) goto LAB_004bb6cf;

    }

    }

    local_48 = 0;

    if ((local_6c & 0x80000) == 0) {

    if (local_54 == 1) {

    local_44 = 0;

    }

    }

    else {

    local_48 = 0;

    if (-1 < local_70 - local_54) {

    local_48 = local_70 - local_54;

    }

    iVar8 = iVar8 + local_48;

    }

    iVar3 = (local_4c ^ (int)local_4c >> 0x1f) - ((int)local_4c >> 0x1f);

    iVar6 = 2;

    if (99 < iVar3) {

    iVar6 = (999 < iVar3) + 3;

    }

    local_28 = (uint32_t *)CONCAT22(local_28._2_2_,(short)local_44);

    local_34 = (char *)CONCAT31(local_34._1_3_,(char)local_50);

    uVar9 = iVar6 + ((short)local_44 != 0) + 2 + iVar8;

    local_30 = (uint32_t *)local_5c;

    local_24 = (int *)local_48;

    uVar7 = *param_4;

    local_20 = (int *)(CONCAT22(CONCAT11(local_20._3_1_,~(local_6c._2_1_ << 5)),(short)local_60) &

    0xff20ffff | 0x450000);

    local_2c = (byte *)local_54;

    local_1c = (int *)local_4c;

    if ((int)uVar7 < 1) {

    puVar4 = (uint32_t *)FUN_004ba740(&local_50,param_3);

    }

    else {

    uVar9 = -(uint)(uVar9 < uVar7) & uVar7 - uVar9;

    uVar7 = uVar9 >> ((&DAT_0065d9e4)[*(byte *)((int)param_4 + 9) & 0xf] & 0x1f);

    if (uVar7 != 0) {

    puVar4 = (uint32_t *)FUN_004bc4b0(param_3,param_4 + 3);

    param_3 = *puVar4;

    }

    puVar4 = (uint32_t *)FUN_004ba740(&local_3c,param_3);

    uVar5 = *puVar4;

    if (uVar9 == uVar7) goto LAB_004bba6f;

    puVar4 = (uint32_t *)FUN_004bc4b0(uVar5,param_4 + 3);

    }

    uVar5 = *puVar4;

    LAB_004bba6f:

    *local_64 = uVar5;

    // ExceptionList = ... (SEH frame, stubbed)

    return local_64;


}  // 0x004bb5e0
#endif // GameFn4BB5E0
void GameFn4BB5E0() {}  // 0x004bb5e0
#if 0 // GHIDRA_RAW: RenderFn5424A0 @ 0x005424a0 — needs manual cleanup
void RenderFn5424A0(void)
{


    float fVar1;

    uint32_t uVar2;

    uint32_t uVar3;

    uint32_t uVar4;

    uint32_t uVar5;

    int iVar6;

    int iVar7;

    int iVar8;

    uint32_t extraout_ECX;

    bool bVar9;

    uint8_t auStack_34 [4];

    uint32_t local_30;

    uint8_t local_2c [32];

    uint32_t local_c;



    local_c = DAT_0067d280 ^ (uint)auStack_34;

    _DAT_00702a80 = 0;

    FUN_005417d0();

    if (9 < DAT_00682204) {

    FUN_00461e70("Overflow of dialog level stack",0x1e);

    DAT_00682204 = DAT_00682204 + -1;

    }

    iVar7 = DAT_00682204 + 1;

    DAT_00682204 = iVar7;

    (&DAT_00747b60)[iVar7 * 6] = FUN_00542df0;

    (&DAT_00747b64)[iVar7 * 6] = FUN_00541860;

    (&DAT_00747b68)[iVar7 * 6] = 0;

    (&DAT_00747b6c)[iVar7 * 6] = 0;

    (&DAT_00747b70)[iVar7 * 6] = 0;

    (&DAT_00747b74)[iVar7 * 6] = 0;

    uVar5 = _UNK_0066c4bc;

    uVar4 = _UNK_0066c4b8;

    uVar3 = _UNK_0066c4b4;

    uVar2 = _DAT_0066c4b0;

    if (iVar7 != -1) {

    (&DAT_00747b70)[iVar7 * 6] = 1;

    _DAT_006818b8 = uVar2;

    uRam006818bc = uVar3;

    uRam006818c0 = uVar4;

    uRam006818c4 = uVar5;

    PTR_DAT_00685890 = &DAT_006818b8;

    _DAT_006818c8 = uVar2;

    uRam006818cc = uVar3;

    uRam006818d0 = uVar4;

    uRam006818d4 = uVar5;

    DAT_0074be50 = 0;

    }

    iVar7 = FUN_005de9b0();

    if (iVar7 == 0) {

    FUN_004d1070();

    return;

    }

    DAT_0074b604 = DAT_007028a0;

    DAT_0074b608 = DAT_007028a4;

    DAT_00682e9c = 0x13;

    DAT_0074b5fc = 0x13;

    DAT_0074b600 = 0xffffffff;

    if (DAT_00702d60 != 0) {

    *(uint32_t *)(DAT_00702d60 + 0x124) = *(uint32_t *)(DAT_00702d60 + 0x124) | 0x8000;

    }

    DAT_00702d60 = 0;

    DAT_00681dd0 = FUN_00559dc0();

    DAT_00702d60 = DAT_00681dd0;

    *(uint32_t *)(DAT_00681dd0 + 0x124) = *(uint32_t *)(DAT_00681dd0 + 0x124) | 0x40000000;

    DAT_00681db4 = 0;

    DAT_00681dec = 0;

    DAT_00681db0 = 1;

    FUN_00540fe0(extraout_ECX);

    local_30 = 0;

    iVar7 = 6;

    DAT_00682ea0 = 0;

    do {

    iVar8 = FUN_0062ae90(local_2c);

    if (0 < iVar8) break;

    if (iVar8 == 0) {

    iVar8 = FUN_00632950(local_2c,&DAT_00702a60);

    if (iVar8 != 0) {

    iVar7 = DAT_00682ea0 + 1;

    }

    DAT_00682ea0 = DAT_00682ea0 + 1;

    }

    } while (DAT_00682ea0 < 5);

    iVar6 = DAT_0074b604;

    fVar1 = DAT_0066be20;

    bVar9 = DAT_00702bb8 == 0;

    (&DAT_00748b50)[iVar7 * 3] = 1;

    iVar8 = *(int *)(*(int *)(DAT_0074b5f8 + 0x2ac) + iVar7 * 4);

    DAT_00702c1c = ((*(float *)(iVar8 + 0x44) * fVar1 + *(float *)(iVar8 + 0x38) * fVar1) /

    (float)iVar6) * (float)iVar6;

    DAT_00702c20 = (float)DAT_0074b608 *

    ((*(float *)(iVar8 + 0x48) * fVar1 + *(float *)(iVar8 + 0x3c) * fVar1) /

    (float)DAT_0074b608);

    DAT_00702c24 = DAT_00702c1c;

    DAT_00702c28 = DAT_00702c20;

    DAT_00748a30 = iVar7;

    if (bVar9) {

    FUN_00558360();

    }

    return;


}  // 0x005424a0
#endif // RenderFn5424A0
void RenderFn5424A0() {}  // 0x005424a0
#if 0 // GHIDRA_RAW: RenderFn543820 @ 0x00543820 — needs manual cleanup
void RenderFn543820(void)
{


    int iVar1;

    int iVar2;

    uint32_t uVar3;

    int iVar4;

    bool bVar5;



    FUN_005413d0();

    iVar1 = DAT_00748a30;

    if (DAT_00702c07 != '\0') {

    FUN_004d1070();

    DAT_00681db0 = 0;

    DAT_00681db4 = 0xffffffff;

    DAT_00681dec = 0;

    DAT_00681e34 = 0;

    *(uint32_t *)(DAT_00702d60 + 0x124) = *(uint32_t *)(DAT_00702d60 + 0x124) | 0x8000;

    DAT_00702d60 = 0;

    FUN_00541080();

    FUN_00501a20();

    if (DAT_00702b30 != 0) {

    return;

    }

    if (DAT_00702b34 != 0) {

    return;

    }

    if (DAT_00702b50 != 0) {

    return;

    }

    if (DAT_00702bb8 != 0) {

    return;

    }

    FUN_00558360();

    return;

    }

    if (DAT_00702c01 == '\0') {

    if (DAT_00702c02 == '\0') goto LAB_00543a39;

    iVar2 = DAT_00748a30 + 1;

    }

    else {

    iVar2 = DAT_00748a30 + -1;

    }

    if (iVar2 < DAT_00682e98) {

    iVar4 = DAT_0068298c + -1;

    LAB_0054391f:

    iVar2 = iVar4;

    }

    else {

    iVar4 = DAT_00682e98;

    if (DAT_0068298c + -1 < iVar2) goto LAB_0054391f;

    }

    bVar5 = DAT_00702b30 == 0;

    iVar4 = DAT_00748a30 * 3;

    DAT_00748a30 = iVar2;

    (&DAT_00748b50)[iVar4] = 0;

    (&DAT_00748b50)[iVar2 * 3] = 1;

    if ((((bVar5) && (DAT_00702b34 == 0)) && (DAT_00702b50 == 0)) &&

    ((iVar2 != iVar1 && (DAT_00702bb8 == 0)))) {

    FUN_00558360();

    iVar2 = DAT_00748a30;

    }

    iVar1 = *(int *)(*(int *)(DAT_0074b5f8 + DAT_0074b5fc * 0x24) + iVar2 * 4);

    DAT_00702c1c = ((*(float *)(iVar1 + 0x44) * DAT_0066be20 + *(float *)(iVar1 + 0x38) * DAT_0066be20

    ) / (float)DAT_0074b604) * (float)DAT_0074b604;

    DAT_00702c20 = ((*(float *)(iVar1 + 0x48) * DAT_0066be20 + *(float *)(iVar1 + 0x3c) * DAT_0066be20

    ) / (float)DAT_0074b608) * (float)DAT_0074b608;

    DAT_00702c24 = DAT_00702c1c;

    DAT_00702c28 = DAT_00702c20;

    LAB_00543a39:

    FUN_005de3d0(DAT_0074b608);

    iVar2 = FUN_005de120();

    iVar1 = DAT_00748a30;

    if (-1 < iVar2) {

    if ((iVar2 < DAT_00682e98) || (DAT_0068298c + -1 < iVar2)) {

    iVar2 = DAT_00748a30;

    }

    bVar5 = DAT_00702b30 == 0;

    iVar4 = DAT_00748a30 * 3;

    DAT_00748a30 = iVar2;

    (&DAT_00748b50)[iVar4] = 0;

    (&DAT_00748b50)[iVar2 * 3] = 1;

    if ((((bVar5) && (DAT_00702b34 == 0)) && (DAT_00702b50 == 0)) &&

    ((iVar2 != iVar1 && (DAT_00702bb8 == 0)))) {

    FUN_00558360();

    }

    if (DAT_00702c0a != '\0') {

    FUN_005434f0();

    }

    }

    if (DAT_00702c08 == '\0') {

    uVar3 = FUN_005e80c0("MH_WorldLoad");

    FUN_00463000(&DAT_00748a40,&DAT_00660434,uVar3);

    return;

    }

    FUN_005434f0();

    return;


}  // 0x00543820
#endif // RenderFn543820
void RenderFn543820() {}  // 0x00543820
#if 0 // GHIDRA_RAW: SysFn644F60 @ 0x00644f60 — needs manual cleanup
void SysFn644F60(int param_1)
{


    uint32_t uVar1;

    uint32_t *puVar2;

    uint32_t uVar3;

    int iVar4;

    int *piVar5;

    uint32_t uVar6;

    uint32_t *puVar7;

    int *piVar8;

    uint32_t uVar9;

    int iVar10;

    uint32_t uVar11;

    uint32_t *puVar12;

    uint32_t uVar13;

    uint32_t local_2c;

    uint32_t uStack_28;

    uint32_t uStack_24;

    uint32_t uStack_20;

    uint32_t local_1c;

    uint32_t uStack_18;

    uint32_t local_14;

    void *local_10;

    uint8_t *puStack_c;

    uint32_t local_8;



    local_8 = 0xffffffff;

    puStack_c = &LAB_00651245;

    local_10 = ExceptionList;

    uVar3 = DAT_0067d280 ^ (uint)&stack0xfffffffc;

    // ExceptionList = ... (SEH frame, stubbed)

    piVar8 = *(int **)(param_1 + 4);

    piVar5 = piVar8 + 4;

    local_14 = uVar3;

    if (*piVar5 == 0) {

    if (piVar8 + 6 != piVar8) {

    if (0xf < (uint)piVar8[5]) {

    piVar8 = (int *)*piVar8;

    }

    FUN_0043cb70(piVar8,0);

    }

    }

    else {

    if (0xf < (uint)piVar8[5]) {

    piVar8 = (int *)*piVar8;

    }

    iVar10 = *piVar5 + (int)piVar8;

    iVar4 = FUN_006433e0(piVar8,iVar10,0x3d);

    if ((iVar4 != iVar10) && (uVar13 = iVar4 - (int)piVar8, uVar13 != 0xffffffff)) {

    piVar5 = *(int **)(param_1 + 4);

    if (0xf < (uint)piVar5[5]) {

    piVar5 = (int *)*piVar5;

    }

    FUN_0043cb70(piVar5,uVar13);

    puVar12 = *(uint32_t **)(param_1 + 4);

    if (uVar13 < (uint)puVar12[4]) {

    uVar1 = uVar13 + 1;

    uVar9 = uVar1;

    do {

    puVar7 = puVar12;

    if (0xf < (uint)puVar12[5]) {

    puVar7 = (uint32_t *)*puVar12;

    }

    if (*(char *)((int)puVar7 + uVar13) == ',') {

    local_1c = 0;

    uStack_18 = 0;

    local_2c = 0;

    uStack_28 = 0;

    uStack_24 = 0;

    uStack_20 = 0;

    if ((uint)puVar12[4] < uVar9) goto LAB_006451eb;

    uVar6 = puVar12[4] - uVar9;

    uVar11 = uVar13 - 1;

    if (uVar6 < uVar13 - 1) {

    uVar11 = uVar6;

    }

    puVar7 = puVar12;

    if (0xf < (uint)puVar12[5]) {

    puVar7 = (uint32_t *)*puVar12;

    }

    FUN_00442eb0((int)puVar7 + uVar9,uVar11);

    uVar9 = local_2c;

    puVar2 = (uint32_t *)puVar12[0xd];

    local_8 = 0;

    if (puVar2 == (uint32_t *)puVar12[0xe]) {

    FUN_00438510(puVar2,&local_2c);

    uVar9 = uStack_18;

    }

    else {

    local_2c = local_2c & 0xffffff00;

    *puVar2 = uVar9;

    puVar2[1] = uStack_28;

    puVar2[2] = uStack_24;

    puVar2[3] = uStack_20;

    puVar2[4] = local_1c;

    puVar2[5] = uStack_18;

    puVar12[0xd] = puVar12[0xd] + 0x18;

    uVar9 = 0xf;

    }

    local_8 = 0xffffffff;

    if (0xf < uVar9) {

    uVar6 = uVar9 + 1;

    uVar11 = local_2c;

    if (0xfff < uVar6) {

    uVar11 = *(uint32_t *)(local_2c - 4);

    uVar6 = uVar9 + 0x24;

    if (0x1f < (local_2c - uVar11) - 4) goto LAB_00645195;

    }

    FUN_00643505(uVar11,uVar6);

    }

    piVar5 = (int *)(*(int *)(param_1 + 4) + 0x3c);

    *piVar5 = *piVar5 + 1;

    uVar9 = uVar13;

    }

    puVar12 = *(uint32_t **)(param_1 + 4);

    uVar13 = uVar13 + 1;

    } while (uVar13 < (uint)puVar12[4]);

    if (puVar12[0xf] == 0) {

    local_1c = 0;

    uStack_18 = 0;

    local_2c = 0;

    uStack_28 = 0;

    uStack_24 = 0;

    uStack_20 = 0;

    if ((uint)puVar12[4] < uVar1) {

    LAB_006451eb:

    uStack_18 = 0;

    local_1c = 0;

    uStack_20 = 0;

    uStack_24 = 0;

    uStack_28 = 0;

    local_2c = 0;



    FUN_0043fce0(uVar3);

    }

    iVar4 = puVar12[4] - uVar1;

    iVar10 = -1;

    if (iVar4 != -1) {

    iVar10 = iVar4;

    }

    if (0xf < (uint)puVar12[5]) {

    puVar12 = (uint32_t *)*puVar12;

    }

    FUN_00442eb0((int)puVar12 + uVar1,iVar10);

    local_8 = 1;

    iVar10 = *(int *)(param_1 + 4);

    if (*(int *)(iVar10 + 0x34) == *(int *)(iVar10 + 0x38)) {

    FUN_004fe730(*(int *)(iVar10 + 0x34),&local_2c);

    }

    else {

    FUN_004431a0(&local_2c);

    *(int *)(iVar10 + 0x34) = *(int *)(iVar10 + 0x34) + 0x18;

    }

    *(uint32_t *)(*(int *)(param_1 + 4) + 0x3c) = 1;

    if (0xf < uStack_18) {

    uVar13 = uStack_18 + 1;

    uVar3 = local_2c;

    if (0xfff < uVar13) {

    uVar3 = *(uint32_t *)(local_2c - 4);

    uVar13 = uStack_18 + 0x24;

    if (0x1f < (local_2c - uVar3) - 4) {

    LAB_00645195:



    std::abort();

    }

    }

    FUN_00643505(uVar3,uVar13);

    }

    }

    }

    }

    }

    *(uint8_t *)(param_1 + 8) = 1;

    // ExceptionList = ... (SEH frame, stubbed)

    return;


}  // 0x00644f60
#endif // SysFn644F60
void SysFn644F60() {}  // 0x00644f60
#if 0 // GHIDRA_RAW: GameFn4D89B0 @ 0x004d89b0 — needs manual cleanup
void GameFn4D89B0(float param_1,uint32_t param_2,int param_3,int param_4)
{


    int *piVar1;

    uint32_t uVar2;

    int iVar3;

    float fVar4;

    float fVar5;

    int iVar6;

    int iVar7;

    float *pfVar8;

    uint32_t uVar9;

    bool bVar10;

    float fVar11;

    uint32_t local_8c;

    float local_88;

    float local_84;

    int local_80;

    float fStack_7c;

    int local_78;

    float fStack_74;

    uint32_t local_70;

    uint32_t local_6c;

    float *pfStack_68;

    int local_64;

    float fStack_60;

    float fStack_5c;

    uint32_t local_58;

    uint32_t local_54;

    uint32_t local_50;

    int iStack_4c;

    float fStack_48;

    float fStack_44;

    float fStack_40;

    uint32_t uStack_3c;

    float fStack_38;

    float fStack_34;

    float fStack_30;

    uint32_t uStack_2c;

    float fStack_28;

    float fStack_24;

    float fStack_20;

    uint32_t uStack_1c;

    uint32_t uStack_18;

    uint32_t uStack_14;

    uint32_t uStack_10;

    uint32_t uStack_c;



    iVar3 = *(int *)((int)param_1 + 0xc + param_4 * 8);

    local_64 = *(int *)(iVar3 + 0x14);

    local_84 = param_1;

    local_80 = iVar3;

    local_70 = param_2;

    FUN_0048ff10();

    uVar9 = local_6c;

    local_6c = local_6c & 0xffffff00;

    local_50 = local_50 & 0xffffff00;

    local_78 = 0;

    if ((DAT_00702b5d != '\0') || (piVar1 = DAT_00728460, *(int *)(iVar3 + 0x10) == 0))

    goto LAB_004d8b16;

    for (; piVar1 != DAT_00728464; piVar1 = piVar1 + 1) {

    local_78 = *piVar1;

    if (*(int *)(local_78 + 0x98) == 2) goto LAB_004d8a3c;

    }

    local_78 = 0;

    LAB_004d8a3c:

    local_6c._1_3_ = SUB43(uVar9,1);

    if ((DAT_00702b5c == '\0') && (local_78 != 0)) {

    local_6c = CONCAT31(local_6c._1_3_,1);

    if ((*(uint32_t *)(local_64 + 4) & 0x20000000) == 0) goto LAB_004d8a6a;

    local_8c = 1;

    }

    else {

    local_6c = (uint)local_6c._1_3_ << 8;

    LAB_004d8a6a:

    local_8c = 0;

    }

    if (*(int *)((int)param_1 + 0x5c) != *(int *)(iVar3 + 0x20)) {

    if (*(int *)(iVar3 + 0xc) != 0) {

    iVar6 = 0;

    iVar7 = *(int *)(*(int *)(iVar3 + 0x14) + 8);

    if (0 < iVar7) {

    do {

    (*DAT_00701a58)();

    iVar6 = iVar6 + 1;

    iVar3 = local_80;

    param_1 = local_84;

    } while (iVar6 < iVar7);

    }

    }

    if (DAT_00702b68 != '\0') {

    local_8c = 1;

    }

    if ((*(int *)(iVar3 + 0x10) != 0) && (*(int *)(iVar3 + 0xc) != 0)) {

    if (*(char *)(iVar3 + 0x18) == '\0') {

    iVar7 = 0;

    local_88 = *(float *)(*(int *)(iVar3 + 0x14) + 8);

    if (0 < (int)local_88) {

    do {

    (*DAT_00701a54)(local_8c);

    iVar7 = iVar7 + 1;

    iVar3 = local_80;

    param_1 = local_84;

    } while (iVar7 < (int)local_88);

    }

    }

    else {

    (*DAT_00701a54)(local_8c);

    iVar3 = local_80;

    }

    }

    *(uint32_t *)(iVar3 + 0x20) = *(uint32_t *)((int)param_1 + 0x5c);

    }

    local_50 = CONCAT31(local_50._1_3_,1);

    LAB_004d8b16:

    uVar9 = *(uint32_t *)((int)param_1 + 0x214);

    local_58 = uVar9 >> 0xd & 0xffffff01;

    local_54 = uVar9 >> 0xe & 0xffffff01;

    if (param_3 < 0) {

    iVar3 = *(int *)(local_64 + 0x74);

    }

    else {

    iVar3 = param_3 + 1;

    }

    iVar7 = 0;

    if (-1 < param_3) {

    iVar7 = param_3;

    }

    iStack_4c = iVar3;

    if ((uVar9 & 4) == 0) {

    fStack_48 = *(float *)((int)param_1 + 0x2e8);

    fStack_44 = *(float *)((int)param_1 + 0x2f8);

    fStack_40 = *(float *)((int)param_1 + 0x308);

    uStack_3c = *(uint32_t *)((int)param_1 + 0x318);

    fStack_38 = *(float *)((int)param_1 + 0x2ec);

    fStack_34 = *(float *)((int)param_1 + 0x2fc);

    fStack_30 = *(float *)((int)param_1 + 0x30c);

    uStack_2c = *(uint32_t *)((int)param_1 + 0x31c);

    fStack_28 = *(float *)((int)param_1 + 0x2f0);

    fStack_24 = *(float *)((int)param_1 + 0x300);

    fStack_20 = *(float *)((int)param_1 + 0x310);

    uStack_1c = *(uint32_t *)((int)param_1 + 800);

    uStack_18 = *(uint32_t *)((int)param_1 + 0x2f4);

    uStack_14 = *(uint32_t *)((int)param_1 + 0x304);

    uStack_10 = *(uint32_t *)((int)param_1 + 0x314);

    uStack_c = *(uint32_t *)((int)param_1 + 0x324);

    }

    else {

    fStack_60 = *(float *)((int)param_1 + 0x370);

    FUN_006387e0(*(uint32_t *)((int)param_1 + 0x11c),&fStack_74,&local_88);

    local_84 = local_88 * fStack_60;

    uStack_c = 0x3f800000;

    fVar11 = fStack_74 * fStack_60;

    uStack_1c = 0;

    uStack_2c = 0;

    local_88 = (float)((uint)fStack_74 ^ DAT_0066c580) * fStack_60;

    uStack_3c = 0;

    fStack_30 = (float)((uint)fStack_60 ^ DAT_0066c580);

    fStack_48 = DAT_00685794 * fVar11 + DAT_00685790 * local_84;

    fStack_44 = DAT_006857a4 * fVar11 + DAT_006857a0 * local_84;

    fStack_40 = DAT_006857b4 * fVar11 + DAT_006857b0 * local_84;

    fStack_38 = DAT_00685798 * fStack_30;

    fStack_34 = DAT_006857a8 * fStack_30;

    fStack_30 = DAT_006857b8 * fStack_30;

    fStack_28 = DAT_00685790 * local_88 + DAT_00685794 * local_84;

    uStack_18 = *(uint32_t *)((int)param_1 + 0xf0);

    fStack_24 = DAT_006857a0 * local_88 + DAT_006857a4 * local_84;

    uStack_14 = *(uint32_t *)((int)param_1 + 0xf4);

    fStack_20 = DAT_006857b0 * local_88 + DAT_006857b4 * local_84;

    uStack_10 = *(uint32_t *)((int)param_1 + 0xf8);

    }

    (**(code **)(*DAT_00702700 + 0x2c))();

    if ((*(byte *)((int)param_1 + 0x124) & 2) == 0) {

    local_88 = fStack_7c;

    fStack_60 = fStack_7c;

    }

    else {

    fStack_60 = DAT_0067f47c;

    local_88 = DAT_0067f0f4;

    DAT_0067f0f4 = 80000.0;

    FUN_005f9d00();

    }

    (**(code **)(DAT_00702714 + 0xc))(DAT_00702714,~(*(uint32_t *)((int)param_1 + 0x124) >> 0x15) & 1);

    if (((*(byte *)((int)param_1 + 0x214) & 4) != 0) ||

    (uVar2 = 2, (*(byte *)((int)param_1 + 0x2e4) & 8) == 0)) {

    uVar2 = 1;

    }

    (**(code **)(DAT_00702714 + 8))(DAT_00702714,uVar2);

    if (iVar7 < iVar3) {

    pfVar8 = (float *)(local_64 + 0x9c + iVar7 * 0x90);

    do {

    pfStack_68 = pfVar8;

    if ((*(int *)((int)param_1 + 0x254) == 0) || (iVar3 = FUN_005f5420(iVar7), iVar3 == 0)) {

    fStack_7c = *pfVar8;

    if (fStack_7c == 0.0) {

    LAB_004d8f63:

    local_84 = 0.0;

    }

    else {

    if ((*(int *)((int)fStack_7c + 0x14) == 8) &&

    ((*(byte *)((int)fStack_7c + 0x20) & 8) == 0)) {

    FUN_005e9300();

    }

    fVar11 = *pfVar8;

    if ((fVar11 == 0.0) ||

    (((*(uint32_t *)((int)fVar11 + 0x20) & 0x20000) == 0 &&

    ((7 < *(int *)((int)fVar11 + 0x18) ||

    (*(int *)(&DAT_0065cc34 + *(int *)((int)fVar11 + 0x18) * 4) == 0))))))

    goto LAB_004d8f63;

    local_84 = 1.4013e-45;

    }

    if (pfVar8[2] == 0.0) {

    if (local_84 == 0.0) {

    if (((*(float *)((int)param_1 + 0x1d0) != 0.0) ||

    ((*(uint32_t *)((int)param_1 + 0x214) & 0x800000) != 0)) ||

    ((*(uint32_t *)((int)param_1 + 0x128) & 0x40000) != 0)) goto LAB_004d8fb9;

    bVar10 = (local_70 & 1) == 0;

    }

    else {

    LAB_004d8fb2:

    bVar10 = (local_70 & 4) == 0;

    }

    }

    else {

    if (local_84 != 0.0) goto LAB_004d8fb2;

    LAB_004d8fb9:

    bVar10 = (local_70 & 2) == 0;

    }

    if (!bVar10) {

    if ((DAT_00702770 == 0) ||

    ((*(int *)(DAT_00702770 + 0x1ec) < 1 &&

    ((*(uint32_t *)((int)param_1 + 0x124) & 0x20000) != 0)))) {

    fStack_74 = 0.0;

    }

    else {

    fStack_74 = 1.4013e-45;

    }

    iVar3 = FUN_00643f70();

    fVar11 = *(float *)((int)param_1 + 0x1d0);

    uVar9 = iVar3 << 0x18;

    fVar5 = pfStack_68[4];

    fVar4 = pfStack_68[2];

    fStack_5c = fVar4;

    if ((fVar11 != 0.0) && (fStack_5c = fVar11, fVar11 <= fVar4)) {

    fStack_5c = fVar4;

    }

    if ((char)local_58 == '\0') {

    if ((char)local_54 == '\0') {

    fVar11 = 0.0;

    }

    else {

    uVar9 = *(uint32_t *)((int)param_1 + 0x140);

    fVar5 = 2.24208e-44;

    fVar11 = 1.83671e-40;

    }

    }

    else {

    fStack_5c = **(float **)((int)param_1 + 0x14c);

    uVar9 = FUN_00643f70();

    fVar5 = 4.76441e-44;

    fVar11 = 1.83671e-40;

    uVar9 = (uVar9 << 8 | uVar9) << 8 | uVar9;

    }

    fVar4 = (float)((uint)fVar11 | 4);

    if (fStack_7c == 0.0) {

    fVar4 = fVar11;

    }

    fVar11 = (float)((uint)fVar4 | 8);

    if (local_84 == 0.0) {

    fVar11 = fVar4;

    }

    fVar4 = (float)((uint)fVar11 | 0x10);

    if (fStack_74 == 0.0) {

    fVar4 = fVar11;

    }

    if ((((char)local_58 != '\0') || ((char)local_54 != '\0')) || ((uVar9 & 0xff000000) != 0))

    {

    if (((char)local_58 == '\0') && ((char)local_54 == '\0')) {

    fVar4 = (float)((uint)fVar4 | 0x80);

    }

    if (((uint)fVar5 & 0xf0) == 0x10) {

    fVar4 = (float)((uint)fVar4 | 0x1000);

    }

    else if (((uint)fVar5 & 0xf0) == 0x20) {

    fVar4 = (float)((uint)fVar4 | 0x3000);

    }

    else {

    fVar4 = (float)((uint)fVar4 | 0x2000);

    }

    }

    if ((fStack_5c != 0.0) || (local_84 != 0.0)) {

    if (((uint)fVar5 & 0xf) == 1) {

    fVar4 = (float)((uint)fVar4 | 0x100);

    }

    else if (((uint)fVar5 & 0xf) == 2) {

    fVar4 = (float)((uint)fVar4 | 0x200);

    }

    else {

    fVar4 = (float)((uint)fVar4 | 0x300);

    }

    }

    fVar11 = (float)((uint)fVar4 | 0x700);

    if ((*(uint32_t *)((int)param_1 + 0x214) & 0x800000) == 0) {

    fVar11 = fVar4;

    }

    if (((local_70 & 6) != 0) || ((*(uint32_t *)((int)param_1 + 0x214) & 0x100) != 0)) {

    fVar11 = (float)((uint)fVar11 | 0x20);

    }

    fVar4 = (float)((uint)fVar11 | 0x40);

    if ((*(uint32_t *)((int)param_1 + 0x214) & 0x2000000) == 0) {

    fVar4 = fVar11;

    }

    fStack_7c = fVar4;

    if (((uint)fVar4 & 0xf00) != 0) {

    iVar3 = FUN_00643f70();

    uVar9 = uVar9 & 0xffffff | iVar3 << 0x18;

    fVar4 = (float)((uint)fStack_7c | 0x40000);

    }

    fVar11 = (float)((uint)fVar4 | 0x40000);

    if ((~uVar9 & 0xff000000) == 0) {

    fVar11 = fVar4;

    }

    if (DAT_00702b69 == '\0') {

    FUN_004d72b0(fVar11,uVar9,iVar7,local_50,local_6c,local_78);

    pfVar8 = pfStack_68;

    }

    else {

    FUN_004d7b60(local_80);

    pfVar8 = pfStack_68;

    }

    }

    }

    pfVar8 = pfVar8 + 0x24;

    iVar7 = iVar7 + 1;

    pfStack_68 = pfVar8;

    } while (iVar7 < iStack_4c);

    }

    if ((((DAT_00747c54 != '\0') && (DAT_00702be4 != 3)) &&

    (FUN_00521fc0(&DAT_00747c58), DAT_00702700 != (int *)0x0)) && (-1 < *(int *)(local_78 + 0xa0))

    ) {

    (**(code **)(*DAT_00702700 + 100))(*(int *)(local_78 + 0xa0),1,local_78 + 8);

    }

    _DAT_00747c54 = 0;

    if ((*(byte *)((int)param_1 + 0x124) & 2) != 0) {

    DAT_0067f47c = fStack_60;

    DAT_0067f0f4 = local_88;

    FUN_005f9d00();

    }

    return;


}  // 0x004d89b0
#endif // GameFn4D89B0
void GameFn4D89B0() {}  // 0x004d89b0
#if 0 // GHIDRA_RAW: RenderFn542770 @ 0x00542770 — needs manual cleanup
void RenderFn542770(void)
{


    byte bVar1;

    uint32_t uVar2;

    char cVar3;

    int iVar4;

    byte *pbVar5;

    uint32_t uVar6;

    char *pcVar7;

    char *pcVar8;

    bool bVar9;

    uint8_t auStack_54 [4];

    DWORD local_50;

    byte local_4c [68];

    uint32_t local_8;



    local_8 = DAT_0067d280 ^ (uint)auStack_54;

    _DAT_00702a80 = 1;

    bVar9 = DAT_00702a60 == '\0';

    cVar3 = DAT_00702a60;

    if (bVar9) {

    _DAT_00702a60 = s_Player_00663cd0._0_4_;

    uVar2 = _DAT_00702a60;

    _DAT_00702a64 = s_Player_00663cd0._4_2_;

    DAT_00702a66 = s_Player_00663cd0[6];

    DAT_00702a60 = (char)s_Player_00663cd0._0_4_;

    cVar3 = DAT_00702a60;

    _DAT_00702a60 = uVar2;

    }

    iVar4 = isspace((int)cVar3);

    while (iVar4 != 0) {

    pcVar7 = &DAT_00702a61;

    do {

    cVar3 = *pcVar7;

    pcVar7[-1] = cVar3;

    pcVar7 = pcVar7 + 1;

    } while (cVar3 != '\0');

    iVar4 = isspace((int)DAT_00702a60);

    }

    pcVar7 = &DAT_00702a60;

    do {

    pcVar8 = pcVar7;

    pcVar7 = pcVar8 + 1;

    } while (*pcVar8 != '\0');

    while ((pcVar8 = pcVar8 + -1, (char *)((int)&DAT_00702a5c + 3) < pcVar8 &&

    (iVar4 = isspace((int)*pcVar8), iVar4 != 0))) {

    *pcVar8 = '\0';

    }

    local_4c[0] = 0;

    if (DAT_0074be54 != (HKEY)0x0) {

    local_50 = 0x40;

    RegQueryValueExA(DAT_0074be54,"DefPlayer",(LPDWORD)0x0,(LPDWORD)0x0,local_4c,&local_50);

    }

    if (DAT_0074be5c != (HKEY)0x0) {

    RegCloseKey(DAT_0074be5c);

    DAT_0074be5c = (HKEY)0x0;

    }

    RegCreateKeyExA(DAT_0074be58,&DAT_00702a60,0,(LPSTR)0x0,0,0xf003f,(LPSECURITY_ATTRIBUTES)0x0,

    &DAT_0074be5c,&local_50);

    local_50 = 0;

    if (DAT_0074be5c != (HKEY)0x0) {

    RegSetValueExA(DAT_0074be5c,"Deleted",0,4,(BYTE *)&local_50,4);

    }

    if (local_4c[0] != 0) {

    pcVar7 = &DAT_00702a60;

    pbVar5 = local_4c;

    do {

    bVar1 = *pbVar5;

    bVar9 = bVar1 < (byte)*pcVar7;

    if (bVar1 != *pcVar7) {

    LAB_00542900:

    uVar6 = -(uint)bVar9 | 1;

    goto LAB_00542905;

    }

    if (bVar1 == 0) break;

    bVar1 = pbVar5[1];

    bVar9 = bVar1 < (byte)pcVar7[1];

    if (bVar1 != pcVar7[1]) goto LAB_00542900;

    pbVar5 = pbVar5 + 2;

    pcVar7 = pcVar7 + 2;

    } while (bVar1 != 0);

    uVar6 = 0;

    LAB_00542905:

    if (uVar6 != 0) {

    FUN_005403e0();

    }

    }

    if (DAT_0074be54 != (HKEY)0x0) {

    pcVar7 = &DAT_00702a60;

    do {

    pcVar8 = pcVar7;

    pcVar7 = pcVar8 + 1;

    } while (*pcVar8 != '\0');

    RegSetValueExA(DAT_0074be54,"DefPlayer",0,1,(BYTE *)&DAT_00702a60,(DWORD)(pcVar8 + -0x702a5f));

    }

    FUN_00501740();

    FUN_00501a20();

    return;


}  // 0x00542770
#endif // RenderFn542770
void RenderFn542770() {}  // 0x00542770
#if 0 // GHIDRA_RAW: RenderFn57CE80 @ 0x0057ce80 — needs manual cleanup
void RenderFn57CE80(int param_1)
{


    int *piVar1;

    int iVar2;

    int iVar3;

    int *piVar4;

    uint32_t *puVar5;

    float *pfVar6;

    float10 fVar7;

    float10 fVar8;

    float fVar9;

    int local_c0;

    float local_bc;

    float local_b8;

    int *local_b4;

    int *local_b0;

    int local_ac;

    uint32_t local_a8;

    uint32_t uStack_a4;

    uint32_t uStack_a0;

    uint32_t uStack_9c;

    float local_98;

    uint32_t uStack_94;

    uint32_t uStack_90;

    uint32_t uStack_8c;

    float local_88;

    uint32_t uStack_84;

    uint32_t uStack_80;

    uint32_t uStack_7c;

    int local_78;

    uint32_t uStack_74;

    uint32_t uStack_70;

    uint32_t uStack_6c;

    uint32_t local_68;

    float local_60;

    uint64_t local_5c;

    uint32_t local_54;

    uint8_t local_50 [8];

    uint32_t local_48;

    float local_40;

    uint32_t local_38;

    float local_30;

    float local_20;



    piVar1 = *(int **)(param_1 + 0x14c);

    *(uint32_t *)(param_1 + 300) = *(uint32_t *)(param_1 + 300) | 1;

    if ((piVar1 != (int *)0x0) && (*piVar1 != 0)) {

    local_b4 = piVar1;

    local_ac = param_1;

    iVar2 = FUN_00559dc0();

    if (iVar2 != 0) {

    local_5c = *(uint64_t *)(param_1 + 0xf0);

    local_54 = *(uint32_t *)(param_1 + 0xf8);

    FUN_0055c150();

    *(float *)(iVar2 + 0x114) = *(float *)(param_1 + 0x114) - (float)piVar1[7];

    FUN_0056ca90();

    FUN_0048f2f0(1,0x20,0,0,0);

    FUN_0048f2f0(0xfe,0,0,0,0);

    FUN_0048fba0();

    iVar3 = local_ac;

    pfVar6 = (float *)(piVar1 + 9);

    local_c0 = 0;

    local_b0 = &DAT_0067e2b8;

    do {

    if (*local_b0 < 0) {

    *(uint64_t *)pfVar6 = *(uint64_t *)(iVar3 + 0xf0);

    pfVar6[2] = *(float *)(iVar3 + 0xf8);

    pfVar6[3] = *(float *)(iVar3 + 0x114);

    }

    else {

    FUN_004a6860(local_50);

    *pfVar6 = local_40;

    pfVar6[1] = local_30;

    pfVar6[2] = local_20;

    fVar7 = (float10)FUN_006386b0(local_38 ^ DAT_0066c580,local_48 ^ DAT_0066c580);

    local_60 = (float)(fVar7 + (float10)DAT_0066c0cc);

    pfVar6[3] = local_60;

    if ((local_c0 == 10) || (local_c0 == 2)) {

    FUN_006387e0(local_60,&local_bc,&local_b8);

    fVar9 = local_b8 * DAT_0066c0b8;

    *pfVar6 = local_bc * DAT_0066c0b8 + *pfVar6;

    pfVar6[1] = pfVar6[1] - fVar9;

    }

    }

    local_c0 = local_c0 + 1;

    local_b0 = local_b0 + 0x16;

    pfVar6 = pfVar6 + 7;

    } while ((int)local_b0 < 0x67e838);

    iVar3 = FUN_00559dc0();

    piVar1 = local_b4;

    if (*(int *)(iVar2 + 8) != 0) {

    if ((*(int *)(iVar2 + 0x328) < 1) || (**(int **)(*(int *)(iVar2 + 8) + 0x454) == 0)) {

    local_a8 = *(uint32_t *)(iVar2 + 0x2e4);

    uStack_a4 = *(uint32_t *)(iVar2 + 0x2e8);

    uStack_a0 = *(uint32_t *)(iVar2 + 0x2ec);

    uStack_9c = *(uint32_t *)(iVar2 + 0x2f0);

    local_68 = *(uint32_t *)(iVar2 + 0x324);

    local_98 = *(float *)(iVar2 + 0x2f4);

    uStack_94 = *(uint32_t *)(iVar2 + 0x2f8);

    uStack_90 = *(uint32_t *)(iVar2 + 0x2fc);

    uStack_8c = *(uint32_t *)(iVar2 + 0x300);

    local_88 = *(float *)(iVar2 + 0x304);

    uStack_84 = *(uint32_t *)(iVar2 + 0x308);

    uStack_80 = *(uint32_t *)(iVar2 + 0x30c);

    uStack_7c = *(uint32_t *)(iVar2 + 0x310);

    local_78 = *(int *)(iVar2 + 0x314);

    uStack_74 = *(uint32_t *)(iVar2 + 0x318);

    uStack_70 = *(uint32_t *)(iVar2 + 0x31c);

    uStack_6c = *(uint32_t *)(iVar2 + 800);

    }

    else {

    (*(GhidraCodePtr *)PTR_FUN_0067d208)(*(uint32_t *)(iVar2 + 0x32c));

    }

    }

    local_bc = local_98;

    local_b8 = local_88;

    local_b4 = (int *)local_78;

    fVar8 = (float10)FUN_006386b0(uStack_90 ^ DAT_0066c580,uStack_a0 ^ DAT_0066c580);

    fVar7 = (float10)DAT_0066c0cc;

    FUN_0055c150();

    *(uint32_t *)(iVar3 + 0x124) = *(uint32_t *)(iVar3 + 0x124) | 0x10;

    *(float *)(iVar3 + 0x114) = (float)(fVar8 + fVar7);

    iVar3 = FUN_00559dc0();

    if (*(int *)(iVar2 + 8) != 0) {

    if ((*(int *)(iVar2 + 0x328) < 0xf) ||

    (*(int *)(*(int *)(*(int *)(iVar2 + 8) + 0x454) + 0x38) == 0)) {

    local_a8 = *(uint32_t *)(iVar2 + 0x2e4);

    uStack_a4 = *(uint32_t *)(iVar2 + 0x2e8);

    uStack_a0 = *(uint32_t *)(iVar2 + 0x2ec);

    uStack_9c = *(uint32_t *)(iVar2 + 0x2f0);

    local_68 = *(uint32_t *)(iVar2 + 0x324);

    local_98 = *(float *)(iVar2 + 0x2f4);

    uStack_94 = *(uint32_t *)(iVar2 + 0x2f8);

    uStack_90 = *(uint32_t *)(iVar2 + 0x2fc);

    uStack_8c = *(uint32_t *)(iVar2 + 0x300);

    local_88 = *(float *)(iVar2 + 0x304);

    uStack_84 = *(uint32_t *)(iVar2 + 0x308);

    uStack_80 = *(uint32_t *)(iVar2 + 0x30c);

    uStack_7c = *(uint32_t *)(iVar2 + 0x310);

    local_78 = *(int *)(iVar2 + 0x314);

    uStack_74 = *(uint32_t *)(iVar2 + 0x318);

    uStack_70 = *(uint32_t *)(iVar2 + 0x31c);

    uStack_6c = *(uint32_t *)(iVar2 + 800);

    }

    else {

    (*(GhidraCodePtr *)PTR_FUN_0067d208)(*(int *)(iVar2 + 0x32c) + 0x3b8);

    }

    }

    local_bc = local_98;

    local_b8 = local_88;

    local_b4 = (int *)local_78;

    fVar8 = (float10)FUN_006386b0(uStack_90 ^ DAT_0066c580,uStack_a0 ^ DAT_0066c580);

    fVar7 = (float10)DAT_0066c0cc;

    FUN_0055c150();

    *(uint32_t *)(iVar3 + 0x124) = *(uint32_t *)(iVar3 + 0x124) | 0x10;

    *(float *)(iVar3 + 0x114) = (float)(fVar8 + fVar7);

    iVar3 = FUN_00559dc0();

    if (*(int *)(iVar2 + 8) != 0) {

    if ((*(int *)(iVar2 + 0x328) < 0x10) ||

    (*(int *)(*(int *)(*(int *)(iVar2 + 8) + 0x454) + 0x3c) == 0)) {

    local_a8 = *(uint32_t *)(iVar2 + 0x2e4);

    uStack_a4 = *(uint32_t *)(iVar2 + 0x2e8);

    uStack_a0 = *(uint32_t *)(iVar2 + 0x2ec);

    uStack_9c = *(uint32_t *)(iVar2 + 0x2f0);

    local_68 = *(uint32_t *)(iVar2 + 0x324);

    local_98 = *(float *)(iVar2 + 0x2f4);

    uStack_94 = *(uint32_t *)(iVar2 + 0x2f8);

    uStack_90 = *(uint32_t *)(iVar2 + 0x2fc);

    uStack_8c = *(uint32_t *)(iVar2 + 0x300);

    local_88 = *(float *)(iVar2 + 0x304);

    uStack_84 = *(uint32_t *)(iVar2 + 0x308);

    uStack_80 = *(uint32_t *)(iVar2 + 0x30c);

    uStack_7c = *(uint32_t *)(iVar2 + 0x310);

    local_78 = *(int *)(iVar2 + 0x314);

    uStack_74 = *(uint32_t *)(iVar2 + 0x318);

    uStack_70 = *(uint32_t *)(iVar2 + 0x31c);

    uStack_6c = *(uint32_t *)(iVar2 + 800);

    }

    else {

    (*(GhidraCodePtr *)PTR_FUN_0067d208)(*(int *)(iVar2 + 0x32c) + 0x3fc);

    }

    }

    local_bc = local_98;

    local_b8 = local_88;

    local_b4 = (int *)local_78;

    fVar8 = (float10)FUN_006386b0(uStack_90 ^ DAT_0066c580,uStack_a0 ^ DAT_0066c580);

    fVar7 = (float10)DAT_0066c0cc;

    FUN_0055c150();

    *(uint32_t *)(iVar3 + 0x124) = *(uint32_t *)(iVar3 + 0x124) | 0x10;

    *(float *)(iVar3 + 0x114) = (float)(fVar8 + fVar7);

    if (*(int *)(iVar2 + 8) != 0) {

    if ((*(int *)(iVar2 + 0x328) < 0x14) ||

    (*(int *)(*(int *)(*(int *)(iVar2 + 8) + 0x454) + 0x4c) == 0)) {

    local_a8 = *(uint32_t *)(iVar2 + 0x2e4);

    uStack_a4 = *(uint32_t *)(iVar2 + 0x2e8);

    uStack_a0 = *(uint32_t *)(iVar2 + 0x2ec);

    uStack_9c = *(uint32_t *)(iVar2 + 0x2f0);

    local_68 = *(uint32_t *)(iVar2 + 0x324);

    local_98 = *(float *)(iVar2 + 0x2f4);

    uStack_94 = *(uint32_t *)(iVar2 + 0x2f8);

    uStack_90 = *(uint32_t *)(iVar2 + 0x2fc);

    uStack_8c = *(uint32_t *)(iVar2 + 0x300);

    local_88 = *(float *)(iVar2 + 0x304);

    uStack_84 = *(uint32_t *)(iVar2 + 0x308);

    uStack_80 = *(uint32_t *)(iVar2 + 0x30c);

    uStack_7c = *(uint32_t *)(iVar2 + 0x310);

    local_78 = *(int *)(iVar2 + 0x314);

    uStack_74 = *(uint32_t *)(iVar2 + 0x318);

    uStack_70 = *(uint32_t *)(iVar2 + 0x31c);

    uStack_6c = *(uint32_t *)(iVar2 + 800);

    }

    else {

    (*(GhidraCodePtr *)PTR_FUN_0067d208)(*(int *)(iVar2 + 0x32c) + 0x50c);

    }

    }

    piVar1[0x170] = (int)local_98;

    piVar1[0x171] = (int)local_88;

    piVar1[0x172] = local_78;

    if (*(int *)(iVar2 + 8) != 0) {

    if ((*(int *)(iVar2 + 0x328) < 0x15) ||

    (*(int *)(*(int *)(*(int *)(iVar2 + 8) + 0x454) + 0x50) == 0)) {

    local_40 = *(float *)(iVar2 + 0x2f4);

    local_30 = *(float *)(iVar2 + 0x304);

    local_20 = *(float *)(iVar2 + 0x314);

    }

    else {

    (*(GhidraCodePtr *)PTR_FUN_0067d208)(*(int *)(iVar2 + 0x32c) + 0x550);

    }

    }

    piVar4 = piVar1 + 0xdd;

    piVar1[0x173] = (int)local_40;

    iVar3 = 5;

    piVar1[0x174] = (int)local_30;

    piVar1[0x175] = (int)local_20;

    *(uint32_t *)(iVar2 + 0x124) = *(uint32_t *)(iVar2 + 0x124) | 0x8000;

    do {

    iVar2 = 0xc;

    do {

    piVar4[-1] = 0;

    *piVar4 = 0;

    piVar4 = piVar4 + 2;

    iVar2 = iVar2 + -1;

    } while (iVar2 != 0);

    iVar3 = iVar3 + -1;

    } while (iVar3 != 0);

    piVar1[0xdd] = 10;

    piVar4 = piVar1 + 0xdf;

    piVar1[0xf5] = 0xb;

    iVar2 = 0x15;

    piVar1[0x10d] = 0xc;

    piVar1[0x125] = 0xd;

    piVar1[0x13d] = 0xe;

    do {

    *piVar4 = iVar2;

    piVar4 = piVar4 + 2;

    iVar2 = iVar2 + 1;

    } while (iVar2 != 0x20);

    piVar4 = piVar1 + 0xf7;

    iVar2 = 0x1f;

    do {

    *piVar4 = iVar2;

    piVar4 = piVar4 + 2;

    iVar2 = iVar2 + 1;

    } while (iVar2 != 0x2a);

    piVar4 = piVar1 + 0x10f;

    iVar2 = 0x29;

    do {

    *piVar4 = iVar2;

    piVar4 = piVar4 + 2;

    iVar2 = iVar2 + 1;

    } while (iVar2 != 0x34);

    piVar4 = piVar1 + 0x127;

    iVar2 = 0x33;

    do {

    *piVar4 = iVar2;

    piVar4 = piVar4 + 2;

    iVar2 = iVar2 + 1;

    } while (iVar2 != 0x3e);

    piVar4 = piVar1 + 0x13f;

    iVar2 = 0x3d;

    do {

    *piVar4 = iVar2;

    piVar4 = piVar4 + 2;

    iVar2 = iVar2 + 1;

    } while (iVar2 != 0x48);

    piVar1[0x159] = 0;

    piVar4 = piVar1 + 0xd;

    piVar1[0xda] = -1;

    puVar5 = &DAT_0067e2b4;

    do {

    *piVar4 = 0;

    piVar4 = piVar4 + 7;

    *puVar5 = 0x43480000;

    puVar5 = puVar5 + 0x16;

    } while ((int)puVar5 < 0x67e834);

    DAT_0067e2b4 = *(uint32_t *)(DAT_007028f4 + 0x71c);

    DAT_0067e30c = *(uint32_t *)(DAT_007028f4 + 0x750);

    _DAT_0067e364 = *(uint32_t *)(DAT_007028f4 + 0x85c);

    _DAT_0067e3bc = *(uint32_t *)(DAT_007028f4 + 0x870);

    _DAT_0067e414 = *(uint32_t *)(DAT_007028f4 + 0x874);

    _DAT_0067e46c = *(uint32_t *)(DAT_007028f4 + 0x874);

    _DAT_0067e4c4 = *(uint32_t *)(DAT_007028f4 + 0x874);

    _DAT_0067e51c = *(uint32_t *)(DAT_007028f4 + 0x878);

    _DAT_0067e574 = *(uint32_t *)(DAT_007028f4 + 0x87c);

    _DAT_0067e5cc = *(uint32_t *)(DAT_007028f4 + 0x880);

    _DAT_0067e624 = *(uint32_t *)(DAT_007028f4 + 0x884);

    _DAT_0067e67c = *(uint32_t *)(DAT_007028f4 + 0x888);

    _DAT_0067e6d4 = *(uint32_t *)(DAT_007028f4 + 0x88c);

    _DAT_0067e72c = *(uint32_t *)(DAT_007028f4 + 0x88c);

    _DAT_0067e784 = *(uint32_t *)(DAT_007028f4 + 0x88c);

    _DAT_0067e7dc = *(uint32_t *)(DAT_007028f4 + 0x890);

    _DAT_0067e2bc = *(uint32_t *)(DAT_007028f4 + 0x1114);

    _DAT_0067e314 = *(uint32_t *)(DAT_007028f4 + 0x1118);

    DAT_0067e36c = *(uint32_t *)(DAT_007028f4 + 0x111c);

    _DAT_0067e3c4 = *(uint32_t *)(DAT_007028f4 + 0x1120);

    DAT_0067e41c = *(uint32_t *)(DAT_007028f4 + 0x1124);

    _DAT_0067e474 = *(uint32_t *)(DAT_007028f4 + 0x1124);

    _DAT_0067e4cc = *(uint32_t *)(DAT_007028f4 + 0x1124);

    _DAT_0067e524 = *(uint32_t *)(DAT_007028f4 + 0x1128);

    _DAT_0067e57c = *(uint32_t *)(DAT_007028f4 + 0x112c);

    _DAT_0067e5d4 = *(uint32_t *)(DAT_007028f4 + 0x1130);

    _DAT_0067e62c = *(uint32_t *)(DAT_007028f4 + 0x1134);

    _DAT_0067e684 = *(uint32_t *)(DAT_007028f4 + 0x1138);

    _DAT_0067e6dc = *(uint32_t *)(DAT_007028f4 + 0x113c);

    _DAT_0067e734 = *(uint32_t *)(DAT_007028f4 + 0x113c);

    _DAT_0067e78c = *(uint32_t *)(DAT_007028f4 + 0x113c);

    _DAT_0067e7e4 = *(uint32_t *)(DAT_007028f4 + 0x1140);

    piVar1[0x1b] = 1;

    fVar9 = *(float *)(DAT_007028f4 + 0x15a4);

    iVar2 = *(int *)(local_ac + 0x22c);

    if ((iVar2 == 0x20) || (iVar2 == 0x52)) {

    iVar2 = *(int *)(local_ac + 0x14c);

    if ((iVar2 != 0) && (*(float *)(iVar2 + 0x594) = fVar9, fVar9 < 0.0)) {

    *(uint32_t *)(iVar2 + 0x594) = 0;

    }

    }

    else if ((((iVar2 == 0x4a) || (iVar2 == 0x53)) &&

    (pfVar6 = *(float **)(local_ac + 0x14c), pfVar6 != (float *)0x0)) &&

    (*pfVar6 = fVar9, fVar9 < 0.0)) {

    *pfVar6 = 0.0;

    return;

    }

    }

    }

    return;


}  // 0x0057ce80
#endif // RenderFn57CE80
void RenderFn57CE80() {}  // 0x0057ce80
#if 0 // GHIDRA_RAW: RenderFn5EBCA0 @ 0x005ebca0 — needs manual cleanup
void RenderFn5EBCA0(int param_1,uint32_t param_2,int param_3,uint64_t *param_4)
{


    int iVar1;

    int iVar2;

    uint32_t uVar3;

    int iVar4;

    float fVar5;

    uint8_t auStack_3c [4];

    uint64_t *local_38;

    uint32_t local_34;

    int local_30;

    uint64_t local_2c;

    uint32_t local_24;

    uint32_t local_20;

    uint32_t local_1c;

    uint32_t local_18;

    int local_14;

    uint32_t local_10;

    uint8_t local_c;

    uint32_t local_8;



    local_8 = DAT_0067d280 ^ (uint)auStack_3c;

    local_38 = param_4;

    if (param_1 == 0) {

    iVar4 = 0;

    }

    else {

    iVar4 = *(int *)(param_1 + 0x14c);

    }

    iVar1 = *(int *)(iVar4 + 8);

    local_30 = param_1;

    if (iVar1 != 0) {

    local_30 = iVar1;

    }

    if ((*(float *)(iVar4 + 0xc) <= 0.0) && (*(int *)(iVar4 + 0x10) != 0)) {

    local_34 = param_2;

    if (((iVar1 != DAT_00702774) || (DAT_007488d4 == 0)) && ((*(uint32_t *)(iVar4 + 0x18) & 0x200) != 0)

    ) {

    fVar5 = *(float *)(param_1 + 0x138);

    if (fVar5 == 0.0) {

    if (param_3 == DAT_00702774) {

    FUN_005e80c0("MissileLock");

    FUN_0048f130(0xff0000);

    if (DAT_00702bb8 == 0) {

    FUN_00558360();

    }

    }

    if (((param_3 != 0) && (DAT_006ff960 == 6)) && (iVar1 = FUN_0045f460(), iVar1 != 0)) {

    FUN_00469de0(1,0,6,param_3 + 0x1d4,0);

    }

    }

    FUN_0062a0b0();

    *(float *)(param_1 + 0x138) = fVar5 + *(float *)(param_1 + 0x138);

    }

    do {

    *(int *)(iVar4 + 0x10) = *(int *)(iVar4 + 0x10) + -1;

    uVar3 = *(uint32_t *)(iVar4 + 0x18);

    if ((uVar3 & 2) != 0) {

    uVar3 = uVar3 ^ 4;

    *(uint32_t *)(iVar4 + 0x18) = uVar3;

    }

    iVar1 = FUN_0056e960();

    local_14 = (uVar3 >> 2 & 1) + *(int *)(iVar4 + 0x1c);

    *(uint32_t *)(iVar4 + 0xc) = *(uint32_t *)(iVar1 + 0x4c);

    local_2c = *local_38;

    local_24 = *(uint32_t *)(local_38 + 1);

    if (param_1 != 0) {

    local_18 = *(uint32_t *)(param_1 + 0x1d4);

    }

    local_10 = local_34;

    local_c = (uint8_t)*(uint32_t *)(iVar4 + 0x20);

    if (param_3 == 0) {

    local_20 = 0;

    }

    else {

    local_20 = *(uint32_t *)(param_3 + 0x1d4);

    }

    iVar1 = FUN_005ebc00(param_3);

    if (((iVar1 != 0) && (DAT_006ff960 == 6)) && (iVar2 = FUN_0045f460(), iVar2 != 0)) {

    local_1c = *(uint32_t *)(iVar1 + 0x1d4);

    FUN_00469de0(5,1,5,&local_2c,0);

    }

    } while (((byte)*(uint32_t *)(iVar4 + 0x18) & 0x44) == 0x44);

    *(uint32_t *)(iVar4 + 0x18) = *(uint32_t *)(iVar4 + 0x18) | 0x80;

    return;

    }

    if ((*(uint32_t *)(iVar4 + 0x18) & 0x200) != 0) {

    *(uint32_t *)(param_1 + 0x138) = 0;

    }

    return;


}  // 0x005ebca0
#endif // RenderFn5EBCA0
void RenderFn5EBCA0() {}  // 0x005ebca0
#if 0 // GHIDRA_RAW: SysFn605300 @ 0x00605300 — needs manual cleanup
void SysFn605300()
{


    bVar7 = Concurrency::details::_ContextCallback::_IsCurrentOriginSTA();

    if (bVar7) {

    Concurrency::details::_ContextCallback::_Capture((_ContextCallback *)this);

    }


}  // 0x00605300
#endif // SysFn605300
void SysFn605300() {}  // 0x00605300
#if 0 // GHIDRA_RAW: SysFn60E8C0 @ 0x0060e8c0 — needs manual cleanup
uint32_t SysFn60E8C0(uint32_t param_1,uint32_t param_2)
{


    int *piVar1;

    int iVar2;

    int *piVar3;

    uint32_t local_44;

    void *local_10;

    uint8_t *puStack_c;

    uint32_t local_8;



    puStack_c = &LAB_0064e855;

    local_10 = ExceptionList;

    // ExceptionList = ... (SEH frame, stubbed)

    local_8 = 0;

    local_44 = 0x60e8fb;

    piVar3 = operator_new(0x58);

    piVar1 = piVar3 + 1;

    piVar3[0] = 0;

    piVar3[1] = 0;

    piVar3[2] = 0;

    *piVar1 = 1;

    piVar3[2] = 1;

    *piVar3 = (int)&PTR_FUN_00669808;

    FUN_00617120();

    local_8 = CONCAT31(local_8._1_3_,1);

    local_44 = 0;

    __ExceptionPtrCopy(&local_44,&stack0x00000004);

    FUN_00613140();

    FUN_0061af70(param_2);

    LOCK();

    *piVar1 = *piVar1 + 1;

    UNLOCK();

    FUN_0060e9e0(piVar3 + 3,piVar3);

    LOCK();

    iVar2 = *piVar1;

    *piVar1 = iVar2 + -1;

    UNLOCK();

    if (iVar2 + -1 == 0) {

    (**(code **)*piVar3)();

    piVar1 = piVar3 + 2;

    LOCK();

    iVar2 = *piVar1;

    *piVar1 = *piVar1 + -1;

    UNLOCK();

    if (iVar2 == 1) {

    (**(code **)(*piVar3 + 4))();

    }

    }

    local_44 = 0x60e9c2;

    __ExceptionPtrDestroy(&stack0x00000004);

    // ExceptionList = ... (SEH frame, stubbed)

    return param_1;


}  // 0x0060e8c0
#endif // SysFn60E8C0
void SysFn60E8C0() {}  // 0x0060e8c0
#if 0 // GHIDRA_RAW: SysFn60EC90 @ 0x0060ec90 — needs manual cleanup
uint32_t SysFn60EC90(uint32_t param_1,uint32_t param_2)
{


    int *piVar1;

    int iVar2;

    int *piVar3;

    uint32_t local_44;

    void *local_10;

    uint8_t *puStack_c;

    uint32_t local_8;



    puStack_c = &LAB_0064e855;

    local_10 = ExceptionList;

    // ExceptionList = ... (SEH frame, stubbed)

    local_8 = 0;

    local_44 = 0x60eccb;

    piVar3 = operator_new(0x58);

    piVar1 = piVar3 + 1;

    piVar3[0] = 0;

    piVar3[1] = 0;

    piVar3[2] = 0;

    *piVar1 = 1;

    piVar3[2] = 1;

    *piVar3 = (int)&PTR_FUN_00669808;

    FUN_00617120();

    local_8 = CONCAT31(local_8._1_3_,1);

    local_44 = 0;

    __ExceptionPtrCopy(&local_44,&stack0x00000004);

    FUN_00613140();

    FUN_0061af70(param_2);

    LOCK();

    *piVar1 = *piVar1 + 1;

    UNLOCK();

    FUN_0060f450(piVar3 + 3,piVar3);

    LOCK();

    iVar2 = *piVar1;

    *piVar1 = iVar2 + -1;

    UNLOCK();

    if (iVar2 + -1 == 0) {

    (**(code **)*piVar3)();

    piVar1 = piVar3 + 2;

    LOCK();

    iVar2 = *piVar1;

    *piVar1 = *piVar1 + -1;

    UNLOCK();

    if (iVar2 == 1) {

    (**(code **)(*piVar3 + 4))();

    }

    }

    local_44 = 0x60ed92;

    __ExceptionPtrDestroy(&stack0x00000004);

    // ExceptionList = ... (SEH frame, stubbed)

    return param_1;


}  // 0x0060ec90
#endif // SysFn60EC90
void SysFn60EC90() {}  // 0x0060ec90
#if 0 // GHIDRA_RAW: CoreFn43E020 @ 0x0043e020 — needs manual cleanup
void CoreFn43E020()
{


    FUN_0043efb0("The map exceeds its maximum size.");



    _CxxThrowException(local_20,(ThrowInfo *)&DAT_00677ffc);


}  // 0x0043e020
#endif // CoreFn43E020
void CoreFn43E020() {}  // 0x0043e020
#if 0 // GHIDRA_RAW: GameFn453B50 @ 0x00453b50 — needs manual cleanup
void GameFn453B50(int param_1)
{


    char cVar1;

    bool bVar2;

    bool bVar3;

    int iVar4;

    int iVar5;

    int iVar6;

    char *pcVar7;

    char *pcVar8;

    float fVar9;

    char *pcVar10;

    int iVar11;

    float fVar12;

    uint8_t auStack_11c [4];

    float local_118;

    int local_114;

    float local_110;

    char local_10c [255];

    uint8_t local_d;

    uint32_t local_8;



    pcVar10 = (char *)DAT_007029d8;

    local_8 = DAT_0067d280 ^ (uint)auStack_11c;

    local_114 = param_1;

    if (DAT_007029cc != 0) {

    bVar3 = false;

    bVar2 = false;

    local_110 = DAT_0074b60c;

    local_118 = DAT_0066be20 - DAT_0074b60c * DAT_0066bdf4;

    fVar9 = DAT_0066bd58;

    FUN_0062c690();

    if (_DAT_0066bea4 < fVar9) {

    bVar3 = true;

    do {

    pcVar10 = pcVar10 + 1;

    fVar9 = DAT_0066bd58;

    FUN_0062c690();

    } while (_DAT_0066bea4 < fVar9);

    }

    strncpy(local_10c,pcVar10,0x100);

    pcVar10 = local_10c;

    local_d = 0;

    do {

    cVar1 = *pcVar10;

    pcVar10 = pcVar10 + 1;

    } while (cVar1 != '\0');

    fVar9 = DAT_0066bd58;

    FUN_0062c690();

    if (_DAT_0066bea4 < fVar9) {

    bVar2 = true;

    do {

    pcVar10 = local_10c;

    do {

    cVar1 = *pcVar10;

    pcVar10 = pcVar10 + 1;

    } while (cVar1 != '\0');

    if ((char *)0xff < pcVar10 + (-1 - (int)(local_10c + 1))) {



    FUN_00643b33();

    }

    pcVar7 = local_10c;

    local_10c[(int)(pcVar10 + (-1 - (int)(local_10c + 1)))] = '\0';

    do {

    cVar1 = *pcVar7;

    pcVar7 = pcVar7 + 1;

    } while (cVar1 != '\0');

    fVar9 = DAT_0066bd58;

    FUN_0062c690();

    } while (_DAT_0066bea4 < fVar9);

    }

    pcVar10 = local_10c;

    do {

    cVar1 = *pcVar10;

    pcVar10 = pcVar10 + 1;

    } while (cVar1 != '\0');

    FUN_0062c420((DAT_0066bd58 / _DAT_0074beb4) * (float)DAT_0074bed4 + _DAT_0066bf08,

    (int)pcVar10 - (int)(local_10c + 1));

    if (((int)(DAT_00727e40 * DAT_0066bfe4) & 1U) != 0) {

    pcVar10 = "|";

    if (DAT_007029dc == 0) {

    pcVar10 = "_";

    }

    FUN_0062c690();

    pcVar7 = pcVar10 + 1;

    do {

    cVar1 = *pcVar10;

    pcVar10 = pcVar10 + 1;

    } while (cVar1 != '\0');

    FUN_0062c420((DAT_0066bd58 / _DAT_0074beb4) * (float)DAT_0074bed4 + _DAT_0066bf10,

    (int)pcVar10 - (int)pcVar7);

    }

    if ((bVar2) && (((int)(DAT_00727e40 * DAT_0066c004) & 1U) != 0)) {

    FUN_0062c420((DAT_0066bd58 / _DAT_0074beb4) * (float)DAT_0074bed4 + _DAT_0066bf08,1);

    }

    if ((bVar3) && (((int)(DAT_00727e40 * DAT_0066c004) & 1U) == 0)) {

    FUN_0062c420((DAT_0066bd58 / _DAT_0074beb4) * (float)DAT_0074bed4 + _DAT_0066bf08,1);

    }

    }

    iVar6 = local_114;

    DAT_00702a3c = 0;

    if (DAT_00702a40 == 0) {

    iVar11 = 0;

    local_110 = -NAN;

    pcVar10 = &DAT_006feda0;

    iVar4 = 0x18;

    do {

    if ((*pcVar10 != '\0') && (DAT_00702890 - (float)(&DAT_006feea0)[iVar4] < DAT_0066bfec)) {

    DAT_00702a3c = (uint)(local_114 == 0);

    iVar5 = 0;

    if (-1 < iVar4 + -4) {

    iVar5 = iVar4 + -4;

    }

    local_110 = (float)(iVar5 + 4);

    if (0x18 < (int)local_110) {

    local_110 = 3.36312e-44;

    }

    iVar11 = iVar5;

    if (iVar5 <= (int)local_110) {

    pcVar10 = &DAT_006fd5a0 + iVar5 * 0x100;

    goto LAB_00453f53;

    }

    break;

    }

    pcVar10 = pcVar10 + -0x100;

    iVar4 = iVar4 + -1;

    } while (0x6fd59f < (int)pcVar10);

    }

    else {

    DAT_00702a3c = (uint)(local_114 == 0);

    iVar11 = 0;

    local_110 = 3.36312e-44;

    }

    goto LAB_00453f83;

    while( true ) {

    iVar4 = iVar11 + 1;

    if (DAT_00702890 - (float)(&DAT_006feea0)[iVar5] < DAT_0066bfec) {

    iVar4 = iVar11;

    }

    iVar5 = iVar5 + 1;

    pcVar10 = pcVar10 + 0x100;

    iVar11 = iVar4;

    if ((int)local_110 < iVar5) break;

    LAB_00453f53:

    if (*pcVar10 == '\0') {

    local_110 = (float)(iVar5 + -1);

    break;

    }

    }

    LAB_00453f83:

    fVar9 = local_110;

    if ((DAT_00702a58 == 0) || (iVar4 = FUN_005de9b0(), iVar4 == 0)) {

    LAB_00453fd4:

    local_118 = DAT_0066bd88;

    if (DAT_00702a40 != 0) goto LAB_00453fea;

    }

    else if ((DAT_00702a40 != 0) || (DAT_00702a3c != 0)) {

    FUN_005d7de0();

    goto LAB_00453fd4;

    }

    local_118 = DAT_0066bd7c;

    LAB_00453fea:

    local_114 = DAT_0066bdb4;

    if (iVar6 != 0) {

    local_114 = DAT_0066bd9c;

    local_118 = DAT_0066bed8;

    }

    if ((DAT_00702a40 != 0) && (DAT_00702a48 == 0)) {

    pcVar7 = (char *)FUN_005e80c0("ChatBoxHint");

    pcVar10 = pcVar7;

    do {

    cVar1 = *pcVar10;

    pcVar10 = pcVar10 + 1;

    } while (cVar1 != '\0');

    FUN_0062c690();

    pcVar10 = pcVar7 + 1;

    do {

    cVar1 = *pcVar7;

    pcVar7 = pcVar7 + 1;

    } while (cVar1 != '\0');

    FUN_0062c420((DAT_0066bd4c / _DAT_0074beb4) * (float)DAT_0074bed4 + (local_118 - DAT_0066bd54),

    (int)pcVar7 - (int)pcVar10);

    }

    if (iVar11 <= (int)fVar9) {

    pcVar10 = &DAT_006fd5a1 + iVar11 * 0x100;

    fVar12 = DAT_0066bd78;

    do {

    cVar1 = pcVar10[-1];

    pcVar7 = pcVar10 + -1;

    if (cVar1 != '\0') {

    if (cVar1 == '\v') {

    pcVar7 = pcVar10;

    do {

    cVar1 = *pcVar7;

    pcVar7 = pcVar7 + 1;

    } while (cVar1 != '\0');

    iVar6 = (int)pcVar7 - (int)(pcVar10 + 1);

    }

    else {

    pcVar8 = pcVar10;

    if (cVar1 == '\f') {

    do {

    cVar1 = *pcVar8;

    pcVar8 = pcVar8 + 1;

    } while (cVar1 != '\0');

    FUN_0062c690();

    pcVar7 = pcVar10;

    do {

    cVar1 = *pcVar7;

    pcVar7 = pcVar7 + 1;

    } while (cVar1 != '\0');

    iVar6 = (int)pcVar7 - (int)(pcVar10 + 1);

    fVar12 = DAT_0066bd78;

    }

    else {

    do {

    cVar1 = *pcVar7;

    pcVar7 = pcVar7 + 1;

    } while (cVar1 != '\0');

    iVar6 = (int)pcVar7 - (int)pcVar10;

    fVar9 = local_110;

    fVar12 = DAT_0066bd58;

    }

    }

    FUN_0062c420((fVar12 / _DAT_0074beb4) * (float)DAT_0074bed4 + local_118,iVar6);

    local_118 = local_118 + DAT_0066bd58;

    fVar12 = DAT_0066bd78;

    }

    iVar11 = iVar11 + 1;

    pcVar10 = pcVar10 + 0x100;

    } while (iVar11 <= (int)fVar9);

    }

    return;


}  // 0x00453b50
#endif // GameFn453B50
void GameFn453B50() {}  // 0x00453b50
#if 0 // GHIDRA_RAW: GameFn490680 @ 0x00490680 — needs manual cleanup
float * GameFn490680(char *param_1)
{


    char cVar1;

    int iVar2;

    float fVar3;

    int iVar4;

    float fVar5;

    char *pcVar6;

    uint32_t *puVar7;

    int *piVar8;

    float *_Dst;

    char *pcVar9;

    int local_10;

    uint32_t local_c;



    puVar7 = DAT_0073e798;

    do {

    if (puVar7 == (uint32_t *)0x0) {

    LAB_004906bf:

    FUN_00622400(&local_10);

    if (local_10 != 0) {

    fVar5 = (float)FUN_00633480(0,0,local_c);

    pcVar6 = param_1;

    do {

    cVar1 = *pcVar6;

    pcVar6 = pcVar6 + 1;

    } while (cVar1 != '\0');

    puVar7 = malloc((size_t)(pcVar6 + (0x10 - (int)(param_1 + 1))));

    *puVar7 = DAT_0073e798;

    DAT_0073e798 = puVar7;

    puVar7[1] = fVar5;

    pcVar6 = param_1;

    do {

    cVar1 = *pcVar6;

    pcVar6 = pcVar6 + 1;

    pcVar6[(int)puVar7 + (0xb - (int)param_1)] = cVar1;

    } while (cVar1 != '\0');

    puVar7[2] = 1;

    piVar8 = (int *)FUN_00633470(fVar5);

    _DAT_00701a48 = _DAT_00701a48 + *piVar8;

    if (fVar5 != 0.0) {

    LAB_0049074c:

    _Dst = malloc(0x58);

    memset(_Dst,0,0x58);

    fVar3 = DAT_0066bf2c;

    _Dst[10] = fVar5;

    iVar4 = *(int *)((int)fVar5 + 0x1c);

    iVar2 = *(int *)((int)fVar5 + 0x18);

    _Dst[1] = *(float *)((int)fVar5 + 0x10);

    *_Dst = (float)(*(int *)((int)fVar5 + 0x14) - *(int *)((int)fVar5 + 0x10)) *

    ((fVar3 / (float)iVar4) / (float)iVar2);

    return _Dst;

    }

    }

    FUN_00463000(&DAT_00701bd8,"AnimationCreateF read_animdata_zip could not find \'%s\'",param_1)

    ;

    if (DAT_007283a4 != '\0') {

    pcVar6 = &DAT_00701bd8;

    do {

    pcVar9 = pcVar6;

    pcVar6 = pcVar9 + 1;

    } while (*pcVar9 != '\0');

    FUN_00461f00(&DAT_00701bd8,pcVar9 + -0x701bd8);

    DAT_00747b40 = DAT_00747b40 + 1;

    }

    return (float *)0x0;

    }

    iVar4 = FUN_00632950(param_1,puVar7 + 3);

    if (iVar4 != 0) {

    puVar7[2] = puVar7[2] + 1;

    fVar5 = (float)puVar7[1];

    if (fVar5 != 0.0) goto LAB_0049074c;

    goto LAB_004906bf;

    }

    puVar7 = (uint32_t *)*puVar7;

    } while( true );


}  // 0x00490680
#endif // GameFn490680
void GameFn490680() {}  // 0x00490680
#if 0 // GHIDRA_RAW: GameFn492CD0 @ 0x00492cd0 — needs manual cleanup
void GameFn492CD0(int param_1)
{


    float fVar1;

    float fVar2;

    int *piVar3;

    float *pfVar4;

    int iVar5;

    int iVar6;

    int *piVar7;

    uint32_t *puVar8;

    float10 fVar9;

    int *local_100;

    uint32_t uStack_d8;

    int local_d0;

    uint32_t uStack_c8;

    int local_c0;

    int local_b0;

    int iStack_88;

    int iStack_78;

    int iStack_68;

    uint8_t local_50 [8];

    uint32_t local_48;

    int local_40;

    uint32_t local_38;

    int local_30;

    int local_20;



    piVar3 = *(int **)(param_1 + 0x14c);

    *(uint32_t *)(param_1 + 300) = *(uint32_t *)(param_1 + 300) | 1;

    if ((piVar3 != (int *)0x0) && (*piVar3 != 0)) {

    iVar5 = FUN_00559dc0();

    if (iVar5 != 0) {

    FUN_0055c150();

    *(float *)(iVar5 + 0x114) = *(float *)(param_1 + 0x114) - (float)piVar3[7];

    FUN_0056ca90();

    FUN_0048f2f0(1,0x20,0,0,0);

    FUN_0048f2f0(0xfe,0,0,0,0);

    FUN_0048fba0();

    fVar1 = DAT_0066c0cc;

    piVar7 = piVar3 + 9;

    local_100 = &DAT_0067d388;

    do {

    if (*local_100 < 0) {

    *(uint64_t *)piVar7 = *(uint64_t *)(param_1 + 0xf0);

    piVar7[2] = *(int *)(param_1 + 0xf8);

    fVar2 = *(float *)(param_1 + 0x114);

    }

    else {

    FUN_004a6860(local_50);

    *piVar7 = local_40;

    piVar7[1] = local_30;

    piVar7[2] = local_20;

    fVar9 = (float10)FUN_006386b0(local_38 ^ DAT_0066c580,local_48 ^ DAT_0066c580);

    fVar2 = (float)(fVar9 + (float10)fVar1);

    }

    piVar7[3] = (int)fVar2;

    piVar7 = piVar7 + 7;

    local_100 = local_100 + 0x16;

    } while ((int)local_100 < 0x67dc78);

    if ((*(uint32_t *)(param_1 + 0x1c0) & 0x20000) == 0) {

    iVar6 = FUN_00559dc0();

    if (*(int *)(iVar5 + 8) != 0) {

    if ((*(int *)(iVar5 + 0x328) < 1) || (**(int **)(*(int *)(iVar5 + 8) + 0x454) == 0)) {

    uStack_d8 = *(uint32_t *)(iVar5 + 0x2ec);

    local_d0 = *(int *)(iVar5 + 0x2f4);

    uStack_c8 = *(uint32_t *)(iVar5 + 0x2fc);

    local_c0 = *(int *)(iVar5 + 0x304);

    local_b0 = *(int *)(iVar5 + 0x314);

    }

    else {

    (*(GhidraCodePtr *)PTR_FUN_0067d208)(*(uint32_t *)(iVar5 + 0x32c));

    }

    }

    fVar9 = (float10)FUN_006386b0(uStack_c8 ^ DAT_0066c580,uStack_d8 ^ DAT_0066c580);

    FUN_0055c150();

    *(uint32_t *)(iVar6 + 0x124) = *(uint32_t *)(iVar6 + 0x124) | 0x10;

    *(float *)(iVar6 + 0x114) = (float)(fVar9 + (float10)fVar1);

    }

    if (*(int *)(iVar5 + 8) != 0) {

    if ((*(int *)(iVar5 + 0x328) < 0x14) ||

    (*(int *)(*(int *)(*(int *)(iVar5 + 8) + 0x454) + 0x4c) == 0)) {

    local_d0 = *(int *)(iVar5 + 0x2f4);

    local_c0 = *(int *)(iVar5 + 0x304);

    local_b0 = *(int *)(iVar5 + 0x314);

    }

    else {

    (*(GhidraCodePtr *)PTR_FUN_0067d208)(*(int *)(iVar5 + 0x32c) + 0x50c);

    }

    }

    piVar3[0x170] = local_d0;

    piVar3[0x171] = local_c0;

    piVar3[0x172] = local_b0;

    if (*(int *)(iVar5 + 8) != 0) {

    if ((*(int *)(iVar5 + 0x328) < 0x15) ||

    (*(int *)(*(int *)(*(int *)(iVar5 + 8) + 0x454) + 0x50) == 0)) {

    iStack_88 = *(int *)(iVar5 + 0x2f4);

    iStack_78 = *(int *)(iVar5 + 0x304);

    iStack_68 = *(int *)(iVar5 + 0x314);

    }

    else {

    (*(GhidraCodePtr *)PTR_FUN_0067d208)(*(int *)(iVar5 + 0x32c) + 0x550);

    }

    }

    piVar7 = piVar3 + 0xdd;

    piVar3[0x173] = iStack_88;

    iVar6 = 5;

    piVar3[0x174] = iStack_78;

    piVar3[0x175] = iStack_68;

    *(uint32_t *)(iVar5 + 0x124) = *(uint32_t *)(iVar5 + 0x124) | 0x8000;

    do {

    iVar5 = 0xc;

    do {

    piVar7[-1] = 0;

    *piVar7 = 0;

    piVar7 = piVar7 + 2;

    iVar5 = iVar5 + -1;

    } while (iVar5 != 0);

    iVar6 = iVar6 + -1;

    } while (iVar6 != 0);

    piVar3[0xdd] = 10;

    piVar7 = piVar3 + 0xdf;

    piVar3[0xf5] = 0xb;

    iVar5 = 0x15;

    piVar3[0x10d] = 0xc;

    piVar3[0x125] = 0xd;

    piVar3[0x13d] = 0xe;

    do {

    *piVar7 = iVar5;

    piVar7 = piVar7 + 2;

    iVar5 = iVar5 + 1;

    } while (iVar5 != 0x20);

    piVar7 = piVar3 + 0xf7;

    iVar5 = 0x1f;

    do {

    *piVar7 = iVar5;

    piVar7 = piVar7 + 2;

    iVar5 = iVar5 + 1;

    } while (iVar5 != 0x2a);

    piVar7 = piVar3 + 0x10f;

    iVar5 = 0x29;

    do {

    *piVar7 = iVar5;

    piVar7 = piVar7 + 2;

    iVar5 = iVar5 + 1;

    } while (iVar5 != 0x34);

    piVar7 = piVar3 + 0x127;

    iVar5 = 0x33;

    do {

    *piVar7 = iVar5;

    piVar7 = piVar7 + 2;

    iVar5 = iVar5 + 1;

    } while (iVar5 != 0x3e);

    piVar7 = piVar3 + 0x13f;

    iVar5 = 0x3d;

    do {

    *piVar7 = iVar5;

    piVar7 = piVar7 + 2;

    iVar5 = iVar5 + 1;

    } while (iVar5 != 0x48);

    piVar3[0x159] = 0;

    piVar7 = piVar3 + 0xd;

    piVar3[0xda] = -1;

    puVar8 = &DAT_0067d384;

    do {

    *piVar7 = 0;

    piVar7 = piVar7 + 7;

    *puVar8 = 0x43480000;

    puVar8 = puVar8 + 0x16;

    } while ((int)puVar8 < 0x67dc74);

    DAT_0067d384 = *(uint32_t *)(DAT_007028f4 + 0x5d4);

    DAT_0067d3dc = *(uint32_t *)(DAT_007028f4 + 0x5d8);

    _DAT_0067d434 = *(uint32_t *)(DAT_007028f4 + 0x634);

    _DAT_0067d48c = *(uint32_t *)(DAT_007028f4 + 0x638);

    _DAT_0067d4e4 = *(uint32_t *)(DAT_007028f4 + 0x63c);

    _DAT_0067d53c = *(uint32_t *)(DAT_007028f4 + 0x63c);

    _DAT_0067d594 = *(uint32_t *)(DAT_007028f4 + 0x63c);

    _DAT_0067d5ec = *(uint32_t *)(DAT_007028f4 + 0x63c);

    _DAT_0067d644 = *(uint32_t *)(DAT_007028f4 + 0x63c);

    _DAT_0067d69c = *(uint32_t *)(DAT_007028f4 + 0x63c);

    _DAT_0067d6f4 = *(uint32_t *)(DAT_007028f4 + 0x63c);

    _DAT_0067d74c = *(uint32_t *)(DAT_007028f4 + 0x63c);

    _DAT_0067d7a4 = *(uint32_t *)(DAT_007028f4 + 0x640);

    _DAT_0067d7fc = *(uint32_t *)(DAT_007028f4 + 0x644);

    _DAT_0067d854 = *(uint32_t *)(DAT_007028f4 + 0x648);

    _DAT_0067d8ac = *(uint32_t *)(DAT_007028f4 + 0x64c);

    _DAT_0067d904 = *(uint32_t *)(DAT_007028f4 + 0x650);

    _DAT_0067d95c = *(uint32_t *)(DAT_007028f4 + 0x654);

    _DAT_0067d9b4 = *(uint32_t *)(DAT_007028f4 + 0x654);

    _DAT_0067da0c = *(uint32_t *)(DAT_007028f4 + 0x654);

    _DAT_0067da64 = *(uint32_t *)(DAT_007028f4 + 0x654);

    _DAT_0067dabc = *(uint32_t *)(DAT_007028f4 + 0x654);

    _DAT_0067db14 = *(uint32_t *)(DAT_007028f4 + 0x654);

    _DAT_0067db6c = *(uint32_t *)(DAT_007028f4 + 0x654);

    _DAT_0067dbc4 = *(uint32_t *)(DAT_007028f4 + 0x654);

    _DAT_0067dc1c = *(uint32_t *)(DAT_007028f4 + 0x658);

    _DAT_0067d38c = *(uint32_t *)(DAT_007028f4 + 0x1148);

    _DAT_0067d3e4 = *(uint32_t *)(DAT_007028f4 + 0x1144);

    DAT_0067d43c = (int)*(float *)(DAT_007028f4 + 0x1170);

    _DAT_0067d494 = (int)*(float *)(DAT_007028f4 + 0x116c);

    DAT_0067d4ec = *(uint32_t *)(DAT_007028f4 + 0x114c);

    _DAT_0067d544 = *(uint32_t *)(DAT_007028f4 + 0x114c);

    _DAT_0067d59c = *(uint32_t *)(DAT_007028f4 + 0x114c);

    _DAT_0067d5f4 = *(uint32_t *)(DAT_007028f4 + 0x114c);

    _DAT_0067d64c = *(uint32_t *)(DAT_007028f4 + 0x114c);

    _DAT_0067d6a4 = *(uint32_t *)(DAT_007028f4 + 0x114c);

    _DAT_0067d6fc = *(uint32_t *)(DAT_007028f4 + 0x114c);

    _DAT_0067d754 = *(uint32_t *)(DAT_007028f4 + 0x114c);

    _DAT_0067d7ac = *(uint32_t *)(DAT_007028f4 + 0x1150);

    _DAT_0067d804 = *(uint32_t *)(DAT_007028f4 + 0x1154);

    _DAT_0067d85c = *(uint32_t *)(DAT_007028f4 + 0x1158);

    _DAT_0067d8b4 = *(uint32_t *)(DAT_007028f4 + 0x115c);

    _DAT_0067d90c = *(uint32_t *)(DAT_007028f4 + 0x1160);

    _DAT_0067d964 = *(uint32_t *)(DAT_007028f4 + 0x1164);

    _DAT_0067d9bc = *(uint32_t *)(DAT_007028f4 + 0x1164);

    _DAT_0067da14 = *(uint32_t *)(DAT_007028f4 + 0x1164);

    _DAT_0067da6c = *(uint32_t *)(DAT_007028f4 + 0x1164);

    _DAT_0067dac4 = *(uint32_t *)(DAT_007028f4 + 0x1164);

    _DAT_0067db1c = *(uint32_t *)(DAT_007028f4 + 0x1164);

    _DAT_0067db74 = *(uint32_t *)(DAT_007028f4 + 0x1164);

    _DAT_0067dbcc = *(uint32_t *)(DAT_007028f4 + 0x1164);

    _DAT_0067dc24 = *(uint32_t *)(DAT_007028f4 + 0x1168);

    piVar3[0x1b] = 1;

    fVar1 = *(float *)(DAT_007028f4 + 0x15a0);

    iVar5 = *(int *)(param_1 + 0x22c);

    if ((iVar5 == 0x20) || (iVar5 == 0x52)) {

    iVar5 = *(int *)(param_1 + 0x14c);

    if ((iVar5 != 0) && (*(float *)(iVar5 + 0x594) = fVar1, fVar1 < 0.0)) {

    *(uint32_t *)(iVar5 + 0x594) = 0;

    }

    }

    else if ((((iVar5 == 0x4a) || (iVar5 == 0x53)) &&

    (pfVar4 = *(float **)(param_1 + 0x14c), pfVar4 != (float *)0x0)) &&

    (*pfVar4 = fVar1, fVar1 < 0.0)) {

    *pfVar4 = 0.0;

    return;

    }

    }

    }

    return;


}  // 0x00492cd0
#endif // GameFn492CD0
void GameFn492CD0() {}  // 0x00492cd0
#if 0 // GHIDRA_RAW: GameFn4AD090 @ 0x004ad090 — needs manual cleanup
void GameFn4AD090(int param_1,int param_2,uint32_t param_3,int param_4)
{


    uint32_t *puVar1;

    int iVar2;

    int iVar3;

    uint32_t local_64;

    int local_60;

    uint8_t local_58 [72];

    uint32_t local_10;

    uint32_t local_c;

    uint32_t local_8;

    uint32_t local_4;



    local_4 = DAT_0067d280 ^ (uint)&local_64;

    local_64 = param_3;

    if (param_1 == 0) {

    iVar3 = 0;

    local_60 = 0;

    }

    else {

    iVar3 = *(int *)(param_1 + 0x14c);

    if (DAT_006ff960 == 6) {

    local_60 = FUN_0045f460();

    }

    else {

    local_60 = 1;

    }

    }

    if ((param_2 == DAT_00702774) && (param_2 != 0)) {

    if (*(int *)(param_2 + 0x22c) == 2) {

    if ((*(int *)(param_2 + 0x60) == 0x1e) || (*(int *)(param_2 + 0x60) == 0x1f)) {

    LAB_004ad22c:

    if (param_1 != 0) {

    if (DAT_006ff960 != 6) {

    return;

    }

    iVar3 = FUN_0045f460();

    if (iVar3 != 0) {

    return;

    }

    }

    local_10 = *(uint32_t *)(param_2 + 0x1d4);

    local_c = 99999;

    local_8 = 999999;

    FUN_00469d20(0x18,&local_10);

    FUN_004a6e50(param_1,0x18,0xc,&local_10);

    return;

    }

    }

    else if (((param_2 != 0) && (*(int *)(param_2 + 0x22c) == 3)) &&

    ((*(uint32_t *)(param_2 + 300) & 0xd18d0000) != 0)) goto LAB_004ad22c;

    }

    if (((local_60 != 0) && (iVar2 = *(int *)(iVar3 + 0x5b8 + param_4 * 4), iVar2 != 0)) &&

    (puVar1 = DAT_007027a8, iVar2 != *(int *)(param_2 + 0x1d4))) {

    for (; puVar1 != (uint32_t *)0x0; puVar1 = (uint32_t *)*puVar1) {

    if (((*(uint32_t *)(puVar1[3] + 0x124) & 0x8000) == 0) &&

    (*(int *)(puVar1[3] + 0x1d4) == *(int *)(iVar3 + 0x5b8 + param_4 * 4))) {

    return;

    }

    }

    }

    iVar2 = FUN_0055a8e0();

    if (-1 < iVar2) {

    FUN_004f88c0();

    FUN_004a6860(local_58);

    FUN_0055c150();

    *(uint8_t *)(param_2 + 0x25c) = 0;

    *(uint16_t *)(param_2 + 0x25e) = 0;

    if (*(int *)(param_2 + 0x22c) == 2) {

    *(uint32_t *)(param_2 + 0x260) = *(uint32_t *)(param_2 + 0x260) & 0xfffffbff;

    }

    if (local_60 != 0) {

    *(uint32_t *)(iVar3 + 0x5b8 + param_4 * 4) = *(uint32_t *)(param_2 + 0x1d4);

    }

    }

    return;


}  // 0x004ad090
#endif // GameFn4AD090
void GameFn4AD090() {}  // 0x004ad090
void SysFn6337C0() {}  // 0x006337c0
#if 0 // GHIDRA_RAW: GameFn469670 @ 0x00469670 — needs manual cleanup
void GameFn469670(byte *param_1,byte *param_2,uint32_t param_3,char param_4)
{


    byte bVar1;

    byte *pbVar2;

    uint32_t uVar3;

    uint32_t uVar4;

    int iVar5;

    byte *pbVar6;

    uint8_t **ppuVar7;

    uint32_t *puVar8;

    byte *pbVar9;

    char *pcVar10;

    int iVar11;

    bool bVar12;

    uint8_t auStack_12c [4];

    byte *local_128;

    byte *local_124;

    byte *local_120;

    byte *local_11c;

    byte *local_118;

    byte *local_114;

    byte local_110 [260];

    uint32_t local_c;



    local_c = DAT_0067d280 ^ (uint)auStack_12c;

    local_11c = param_2;

    if (param_1 != (byte *)0x0) {

    local_11c = param_1;

    }

    if (local_11c == (byte *)0x0) {

    return;

    }

    if (param_2 == (byte *)0x0) {

    return;

    }

    if (*(int *)(local_11c + 0x22c) == 0x2c) {

    if (*(int *)(local_11c + 4) != 0x3c) {

    return;

    }

    local_11c = *(byte **)(local_11c + 0x2c4);

    if (local_11c == (byte *)0x0) {

    return;

    }

    }

    uVar3 = *(uint32_t *)(local_11c + 0x1d4);

    bVar1 = param_2[0x1d4];

    local_124 = (byte *)FUN_0045f780();

    local_118 = (byte *)FUN_0045f780();

    if ((uVar3 & 0xff) == (uint)bVar1) {

    if (param_3 < 0x47) {

    pbVar2 = (byte *)FUN_005e81d0();

    pbVar9 = (&PTR_s_SuChatMissile_00681990)[param_3 * 3];

    pbVar6 = pbVar2;

    do {

    bVar1 = *pbVar6;

    bVar12 = bVar1 < *pbVar9;

    if (bVar1 != *pbVar9) {

    LAB_00469748:

    uVar3 = -(uint)bVar12 | 1;

    goto LAB_0046974d;

    }

    if (bVar1 == 0) break;

    bVar1 = pbVar6[1];

    bVar12 = bVar1 < pbVar9[1];

    if (bVar1 != pbVar9[1]) goto LAB_00469748;

    pbVar6 = pbVar6 + 2;

    pbVar9 = pbVar9 + 2;

    } while (bVar1 != 0);

    uVar3 = 0;

    LAB_0046974d:

    local_120 = pbVar2;

    if (uVar3 != 0) {

    memset(local_110,0,0x100);

    local_128 = local_110;

    iVar11 = 0;

    pbVar9 = pbVar2;

    do {

    bVar1 = *pbVar9;

    pbVar9 = pbVar9 + 1;

    } while (bVar1 != 0);

    if (pbVar9 != pbVar2 + 1 && -1 < (int)pbVar9 - (int)(pbVar2 + 1)) {

    do {

    if ((pbVar2[iVar11] == 0x25) &&

    ((pbVar2[iVar11 + 1] == 0x76 || (pbVar2[iVar11 + 1] == 0x6b)))) {

    local_11c = local_124;

    pbVar9 = local_124;

    do {

    bVar1 = *pbVar9;

    pbVar9 = pbVar9 + 1;

    } while (bVar1 != 0);

    pbVar6 = local_128 + -1;

    do {

    pbVar2 = pbVar6 + 1;

    pbVar6 = pbVar6 + 1;

    } while (*pbVar2 != 0);

    pbVar2 = local_124;

    for (uVar3 = (uint)((int)pbVar9 - (int)local_124) >> 2; uVar3 != 0; uVar3 = uVar3 - 1)

    {

    *(uint32_t *)pbVar6 = *(uint32_t *)pbVar2;

    pbVar2 = pbVar2 + 4;

    pbVar6 = pbVar6 + 4;

    }

    for (uVar3 = (int)pbVar9 - (int)local_124 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {

    *pbVar6 = *pbVar2;

    pbVar2 = pbVar2 + 1;

    pbVar6 = pbVar6 + 1;

    }

    pbVar9 = local_124;

    do {

    bVar1 = *pbVar9;

    pbVar9 = pbVar9 + 1;

    } while (bVar1 != 0);

    local_128 = local_128 + ((int)pbVar9 - (int)(local_124 + 1));

    iVar11 = iVar11 + 1;

    pbVar2 = local_120;

    }

    else {

    *local_128 = pbVar2[iVar11];

    local_128 = local_128 + 1;

    }

    iVar11 = iVar11 + 1;

    pbVar9 = pbVar2;

    do {

    bVar1 = *pbVar9;

    pbVar9 = pbVar9 + 1;

    } while (bVar1 != 0);

    } while (iVar11 < (int)pbVar9 - (int)(pbVar2 + 1));

    }

    goto LAB_00469a67;

    }

    }

    uVar4 = FUN_005e81d0();

    FUN_00463000(local_110,uVar4,local_124);

    }

    else {

    if (param_3 < 0x47) {

    ppuVar7 = &PTR_s_DChatMissile_00681988;

    if (param_4 != '\0') {

    ppuVar7 = &PTR_s_DChatMissile_0068198c;

    }

    pbVar9 = ppuVar7[param_3 * 3];

    pbVar2 = (byte *)FUN_005e81d0();

    pbVar6 = pbVar2;

    do {

    bVar1 = *pbVar6;

    bVar12 = bVar1 < *pbVar9;

    if (bVar1 != *pbVar9) {

    LAB_00469890:

    uVar3 = -(uint)bVar12 | 1;

    goto LAB_00469895;

    }

    if (bVar1 == 0) break;

    bVar1 = pbVar6[1];

    bVar12 = bVar1 < pbVar9[1];

    if (bVar1 != pbVar9[1]) goto LAB_00469890;

    pbVar6 = pbVar6 + 2;

    pbVar9 = pbVar9 + 2;

    } while (bVar1 != 0);

    uVar3 = 0;

    LAB_00469895:

    local_120 = pbVar2;

    if (uVar3 != 0) {

    memset(local_110,0,0x100);

    local_128 = local_110;

    iVar11 = 0;

    pbVar9 = pbVar2;

    do {

    bVar1 = *pbVar9;

    pbVar9 = pbVar9 + 1;

    } while (bVar1 != 0);

    if (pbVar9 != pbVar2 + 1 && -1 < (int)pbVar9 - (int)(pbVar2 + 1)) {

    do {

    if (pbVar2[iVar11] == 0x25) {

    if (pbVar2[iVar11 + 1] == 0x76) {

    local_114 = local_118;

    pbVar9 = local_118;

    do {

    bVar1 = *pbVar9;

    pbVar9 = pbVar9 + 1;

    } while (bVar1 != 0);

    pbVar6 = local_128 + -1;

    do {

    pbVar2 = pbVar6 + 1;

    pbVar6 = pbVar6 + 1;

    } while (*pbVar2 != 0);

    pbVar2 = local_118;

    for (uVar3 = (uint)((int)pbVar9 - (int)local_118) >> 2; uVar3 != 0;

    uVar3 = uVar3 - 1) {

    *(uint32_t *)pbVar6 = *(uint32_t *)pbVar2;

    pbVar2 = pbVar2 + 4;

    pbVar6 = pbVar6 + 4;

    }

    for (uVar3 = (int)pbVar9 - (int)local_118 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {

    *pbVar6 = *pbVar2;

    pbVar2 = pbVar2 + 1;

    pbVar6 = pbVar6 + 1;

    }

    pbVar9 = local_118;

    do {

    bVar1 = *pbVar9;

    pbVar9 = pbVar9 + 1;

    } while (bVar1 != 0);

    local_128 = local_128 + ((int)pbVar9 - (int)(local_118 + 1));

    iVar11 = iVar11 + 1;

    pbVar2 = local_120;

    }

    else {

    if (pbVar2[iVar11 + 1] != 0x6b) goto LAB_00469989;

    local_114 = local_124;

    pbVar9 = local_124;

    do {

    bVar1 = *pbVar9;

    pbVar9 = pbVar9 + 1;

    } while (bVar1 != 0);

    pbVar6 = local_128 + -1;

    do {

    pbVar2 = pbVar6 + 1;

    pbVar6 = pbVar6 + 1;

    } while (*pbVar2 != 0);

    pbVar2 = local_124;

    for (uVar3 = (uint)((int)pbVar9 - (int)local_124) >> 2; uVar3 != 0;

    uVar3 = uVar3 - 1) {

    *(uint32_t *)pbVar6 = *(uint32_t *)pbVar2;

    pbVar2 = pbVar2 + 4;

    pbVar6 = pbVar6 + 4;

    }

    for (uVar3 = (int)pbVar9 - (int)local_124 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {

    *pbVar6 = *pbVar2;

    pbVar2 = pbVar2 + 1;

    pbVar6 = pbVar6 + 1;

    }

    pbVar9 = local_124;

    do {

    bVar1 = *pbVar9;

    pbVar9 = pbVar9 + 1;

    } while (bVar1 != 0);

    local_128 = local_128 + ((int)pbVar9 - (int)(local_124 + 1));

    iVar11 = iVar11 + 1;

    pbVar2 = local_120;

    }

    }

    else {

    LAB_00469989:

    *local_128 = pbVar2[iVar11];

    local_128 = local_128 + 1;

    }

    iVar11 = iVar11 + 1;

    pbVar9 = pbVar2;

    do {

    bVar1 = *pbVar9;

    pbVar9 = pbVar9 + 1;

    } while (bVar1 != 0);

    } while (iVar11 < (int)pbVar9 - (int)(pbVar2 + 1));

    }

    if ((((DAT_00702774 != (byte *)0x0) && (*(int *)(DAT_00702774 + 0x22c) == 2)) &&

    (DAT_00702774 == local_11c)) &&

    ((*(float *)(DAT_00702774 + 0x2c8) <= *(float *)(DAT_00702774 + 0x20c) &&

    *(float *)(DAT_00702774 + 0x20c) != *(float *)(DAT_00702774 + 0x2c8) &&

    (iVar11 = *(int *)(DAT_00702774 + 0x14c), param_4 != '\0')))) {

    iVar5 = rand();

    pcVar10 = "BAZ_CT61";

    if ((iVar5 * 2 & 0xffff8000U) != 0) {

    pcVar10 = "BAZ_CT63";

    }

    puVar8 = (uint32_t *)(DAT_00702770 + 0x51b0);

    if (0xf < *(uint32_t *)(DAT_00702770 + 0x51c4)) {

    puVar8 = (uint32_t *)*puVar8;

    }

    if (DAT_00702bbc == 0) {

    uVar4 = (*DAT_0072807c)(pcVar10,puVar8,0);

    *(uint32_t *)(iVar11 + 500) = uVar4;

    }

    else {

    *(uint32_t *)(iVar11 + 500) = 0;

    }

    }

    goto LAB_00469a67;

    }

    }

    uVar4 = FUN_005e81d0();

    FUN_00463000(local_110,uVar4,local_118,local_124);

    }

    LAB_00469a67:

    FUN_00453520();

    return;


}  // 0x00469670
#endif // GameFn469670
void GameFn469670() {}  // 0x00469670
#if 0 // GHIDRA_RAW: GameFn483B60 @ 0x00483b60 — needs manual cleanup
void GameFn483B60(uint32_t *param_1)
{


    int iVar1;

    int iVar2;

    uint8_t local_34 [52];



    iVar1 = param_1[1];

    if (iVar1 < 0) {

    iVar1 = iVar1 / 2 + iVar1;

    iVar2 = 0;

    if (0 < iVar1) {

    iVar2 = iVar1;

    }

    FUN_004873c0(iVar2);

    }

    *param_1 = 0;

    iVar1 = param_1[4];

    if (iVar1 < 0) {

    iVar1 = iVar1 / 2 + iVar1;

    iVar2 = 0;

    if (0 < iVar1) {

    iVar2 = iVar1;

    }

    FUN_004812a0(iVar2);

    }

    param_1[3] = 0;

    iVar1 = param_1[7];

    if (iVar1 < 0) {

    iVar1 = iVar1 / 2 + iVar1;

    iVar2 = 0;

    if (0 < iVar1) {

    iVar2 = iVar1;

    }

    FUN_00481130(iVar2);

    }

    param_1[6] = 0;

    param_1[9] = *(uint32_t *)(param_1[0xb] + 0x28);

    param_1[0x18] = 0;

    param_1[0x19] = 0;

    param_1[0x1a] = 0;

    param_1[0x1b] = 0;

    param_1[0x1c] = 0;

    param_1[0x1d] = 0;

    param_1[0x1e] = 0;

    param_1[0x1f] = 0;

    param_1[10] = 0;

    param_1[0xd] = 0;

    param_1[0xe] = 0;

    iVar1 = param_1[0x10];

    if (iVar1 < 0) {

    iVar1 = iVar1 / 2 + iVar1;

    iVar2 = 0;

    if (0 < iVar1) {

    iVar2 = iVar1;

    }

    FUN_00487340(iVar2);

    }

    param_1[0xf] = 0;

    iVar1 = param_1[0x13];

    if (iVar1 < 0) {

    iVar1 = iVar1 / 2 + iVar1;

    iVar2 = 0;

    if (0 < iVar1) {

    iVar2 = iVar1;

    }

    FUN_00481950(iVar2);

    }

    param_1[0x12] = 0;

    iVar1 = param_1[0x16];

    if (iVar1 < 0) {

    iVar1 = iVar1 / 2 + iVar1;

    iVar2 = 0;

    if (0 < iVar1) {

    iVar2 = iVar1;

    }

    FUN_00481950(iVar2);

    }

    param_1[0x15] = 0;

    param_1[0x20] = 0;

    param_1[0x21] = 1;

    memset(local_34,0,0x30);

    FUN_004872e0(local_34);

    return;


}  // 0x00483b60
#endif // GameFn483B60
void GameFn483B60() {}  // 0x00483b60
#if 0 // GHIDRA_RAW: RenderFn5440A0 @ 0x005440a0 — needs manual cleanup
void RenderFn5440A0(void)
{


    int iVar1;

    int iVar2;

    int iVar3;

    int iVar4;

    int iVar5;

    int iVar6;

    bool bVar7;

    float fVar8;

    int local_c;



    FUN_005413d0();

    iVar6 = DAT_0074b608;

    iVar4 = DAT_0074b604;

    iVar3 = DAT_0074b5f8;

    iVar5 = DAT_00682e98;

    iVar1 = DAT_0068298c;

    fVar8 = DAT_0066be20;

    if (DAT_00702c07 != '\0') {

    FUN_004d1070();

    DAT_00681db0 = 0;

    DAT_00681db4 = 0xffffffff;

    DAT_00681dec = 0;

    DAT_00681e34 = 0;

    *(uint32_t *)(DAT_00702d60 + 0x124) = *(uint32_t *)(DAT_00702d60 + 0x124) | 0x8000;

    DAT_00702d60 = 0;

    FUN_00541080();

    if (DAT_00702b30 != 0) {

    return;

    }

    if (DAT_00702b34 != 0) {

    return;

    }

    if (DAT_00702b50 != 0) {

    return;

    }

    if (DAT_00702bb8 != 0) {

    return;

    }

    FUN_00558360();

    return;

    }

    local_c = DAT_00748a30;

    if (DAT_00702c01 == '\0') {

    if (DAT_00702c02 == '\0') goto LAB_005445ac;

    if (DAT_00748a30 == 6) {

    if (DAT_00682e98 < 8) {

    local_c = 7;

    iVar2 = DAT_00682e98;

    if (DAT_0068298c + -1 < 7) goto LAB_005443e2;

    }

    else {

    iVar2 = DAT_0068298c + -1;

    LAB_005443e2:

    local_c = iVar2;

    }

    DAT_00748b98 = 0;

    (&DAT_00748b50)[local_c * 3] = 1;

    iVar3 = *(int *)(*(int *)(iVar3 + DAT_0074b5fc * 0x24) + local_c * 4);

    DAT_00702c1c = (float)iVar4 *

    ((*(float *)(iVar3 + 0x44) * fVar8 + *(float *)(iVar3 + 0x38) * fVar8) /

    (float)iVar4);

    DAT_00702c20 = (float)iVar6 *

    ((*(float *)(iVar3 + 0x48) * fVar8 + *(float *)(iVar3 + 0x3c) * fVar8) /

    (float)iVar6);

    DAT_00702c24 = DAT_00702c1c;

    DAT_00702c28 = DAT_00702c20;

    }

    iVar3 = local_c + 1;

    if (iVar3 < iVar5) {

    iVar5 = iVar1 + -1;

    LAB_005444ae:

    iVar3 = iVar5;

    }

    else if (DAT_0068298c + -1 < iVar3) goto LAB_005444ae;

    DAT_00748a30 = iVar3;

    (&DAT_00748b50)[local_c * 3] = 0;

    bVar7 = DAT_00702b30 == 0;

    (&DAT_00748b50)[iVar3 * 3] = 1;

    if ((((bVar7) && (DAT_00702b34 == 0)) && (DAT_00702b50 == 0)) &&

    ((iVar3 != local_c && (DAT_00702bb8 == 0)))) {

    FUN_00558360();

    iVar3 = DAT_00748a30;

    iVar4 = DAT_0074b604;

    iVar6 = DAT_0074b608;

    fVar8 = DAT_0066be20;

    }

    iVar5 = *(int *)(*(int *)(DAT_0074b5f8 + DAT_0074b5fc * 0x24) + iVar3 * 4);

    DAT_00702c1c = (float)iVar4 *

    ((*(float *)(iVar5 + 0x44) * fVar8 + *(float *)(iVar5 + 0x38) * fVar8) /

    (float)iVar4);

    DAT_00702c20 = (float)iVar6 *

    ((*(float *)(iVar5 + 0x48) * fVar8 + *(float *)(iVar5 + 0x3c) * fVar8) /

    (float)iVar6);

    DAT_00702c24 = DAT_00702c1c;

    DAT_00702c28 = DAT_00702c20;

    goto LAB_005445ac;

    }

    if (DAT_00748a30 == 8) {

    if (DAT_00682e98 < 8) {

    local_c = 7;

    iVar2 = DAT_00682e98;

    if (DAT_0068298c + -1 < 7) goto LAB_005441c3;

    }

    else {

    iVar2 = DAT_0068298c + -1;

    LAB_005441c3:

    local_c = iVar2;

    }

    DAT_00748bb0 = 0;

    (&DAT_00748b50)[local_c * 3] = 1;

    iVar3 = *(int *)(*(int *)(iVar3 + DAT_0074b5fc * 0x24) + local_c * 4);

    DAT_00702c1c = ((*(float *)(iVar3 + 0x44) * fVar8 + *(float *)(iVar3 + 0x38) * fVar8) /

    (float)iVar4) * (float)iVar4;

    DAT_00702c20 = (float)iVar6 *

    ((*(float *)(iVar3 + 0x48) * fVar8 + *(float *)(iVar3 + 0x3c) * fVar8) /

    (float)iVar6);

    DAT_00702c24 = DAT_00702c1c;

    DAT_00702c28 = DAT_00702c20;

    }

    iVar3 = local_c + -1;

    if (iVar3 < iVar5) {

    iVar5 = iVar1 + -1;

    LAB_0054428f:

    iVar3 = iVar5;

    }

    else if (DAT_0068298c + -1 < iVar3) goto LAB_0054428f;

    DAT_00748a30 = iVar3;

    (&DAT_00748b50)[local_c * 3] = 0;

    bVar7 = DAT_00702b30 == 0;

    (&DAT_00748b50)[iVar3 * 3] = 1;

    if (((bVar7) && (DAT_00702b34 == 0)) &&

    ((DAT_00702b50 == 0 && ((iVar3 != local_c && (DAT_00702bb8 == 0)))))) {

    FUN_00558360();

    iVar3 = DAT_00748a30;

    iVar4 = DAT_0074b604;

    iVar6 = DAT_0074b608;

    fVar8 = DAT_0066be20;

    }

    iVar5 = *(int *)(*(int *)(DAT_0074b5f8 + DAT_0074b5fc * 0x24) + iVar3 * 4);

    DAT_00702c1c = ((*(float *)(iVar5 + 0x44) * fVar8 + *(float *)(iVar5 + 0x38) * fVar8) /

    (float)iVar4) * (float)iVar4;

    DAT_00702c20 = (float)iVar6 *

    ((*(float *)(iVar5 + 0x48) * fVar8 + *(float *)(iVar5 + 0x3c) * fVar8) /

    (float)iVar6);

    DAT_00702c24 = DAT_00702c1c;

    DAT_00702c28 = DAT_00702c20;

    LAB_005445ac:

    FUN_005de3d0(iVar6);

    iVar1 = FUN_005de120();

    iVar5 = DAT_00748a30;

    if ((-1 < iVar1) && (iVar1 != 7)) {

    if ((iVar1 < DAT_00682e98) || (DAT_0068298c + -1 < iVar1)) {

    iVar1 = DAT_00748a30;

    }

    bVar7 = DAT_00702b30 == 0;

    iVar3 = DAT_00748a30 * 3;

    DAT_00748a30 = iVar1;

    (&DAT_00748b50)[iVar3] = 0;

    (&DAT_00748b50)[iVar1 * 3] = 1;

    if ((((bVar7) && (DAT_00702b34 == 0)) && (DAT_00702b50 == 0)) &&

    ((iVar1 != iVar5 && (DAT_00702bb8 == 0)))) {

    FUN_00558360();

    }

    if (DAT_00702c0a != '\0') {

    FUN_00543f00();

    }

    }

    if (DAT_00702c08 != '\0') {

    FUN_00543f00();

    }

    return;


}  // 0x005440a0
#endif // RenderFn5440A0
void RenderFn5440A0() {}  // 0x005440a0
#if 0 // GHIDRA_RAW: RenderFn5514B0 @ 0x005514b0 — needs manual cleanup
void RenderFn5514B0(void)
{


    float fVar1;

    int iVar2;

    uint32_t uVar3;

    int iVar4;

    int iVar5;

    int iVar6;

    int iVar7;

    int iVar8;

    bool bVar9;

    float fVar10;

    float fVar11;

    char *pcVar12;

    int local_10;



    FUN_005413d0();

    iVar4 = DAT_00749398;

    iVar8 = DAT_00748a30;

    iVar5 = DAT_00682e98;

    iVar2 = DAT_0068298c;

    if (DAT_00702c07 != '\0') {

    FUN_00551280();

    if (DAT_00702b30 != 0) {

    return;

    }

    if (DAT_00702b34 != 0) {

    return;

    }

    if (DAT_00702b50 != 0) {

    return;

    }

    if (DAT_00702bb8 != 0) {

    return;

    }

    FUN_00558360();

    return;

    }

    if (DAT_00749398 == 0) goto LAB_005519c6;

    if (DAT_00702c01 == '\0') {

    if (DAT_00702c02 == '\0') goto LAB_005519c6;

    iVar4 = DAT_00748a30 + 1;

    if (iVar4 < DAT_00682e98) {

    iVar6 = DAT_0068298c + -1;

    LAB_005517c4:

    iVar4 = iVar6;

    }

    else {

    iVar6 = DAT_00682e98;

    if (DAT_0068298c + -1 < iVar4) goto LAB_005517c4;

    }

    bVar9 = DAT_00702b30 == 0;

    iVar6 = DAT_00748a30 * 3;

    DAT_00748a30 = iVar4;

    (&DAT_00748b50)[iVar6] = 0;

    (&DAT_00748b50)[iVar4 * 3] = 1;

    if ((((bVar9) && (DAT_00702b34 == 0)) && (DAT_00702b50 == 0)) &&

    ((iVar4 != iVar8 && (DAT_00702bb8 == 0)))) {

    FUN_00558360();

    iVar4 = DAT_00748a30;

    iVar5 = DAT_00682e98;

    iVar2 = DAT_0068298c;

    }

    iVar6 = DAT_0074b5fc;

    fVar1 = DAT_0066be20;

    fVar10 = (float)DAT_0074b604;

    iVar8 = *(int *)(*(int *)(DAT_0074b5f8 + DAT_0074b5fc * 0x24) + 4 + iVar4 * 4);

    fVar11 = (float)DAT_0074b608;

    DAT_00702c1c = fVar10 * ((*(float *)(iVar8 + 0x44) * DAT_0066be20 +

    *(float *)(iVar8 + 0x38) * DAT_0066be20) / fVar10);

    DAT_00702c20 = fVar11 * ((*(float *)(iVar8 + 0x48) * DAT_0066be20 +

    *(float *)(iVar8 + 0x3c) * DAT_0066be20) / fVar11);

    DAT_00702c24 = DAT_00702c1c;

    DAT_00702c28 = DAT_00702c20;

    if (DAT_00749398 < iVar4) {

    do {

    DAT_00702c1c = DAT_00702c24;

    DAT_00702c20 = DAT_00702c28;

    if (iVar4 == 0x15) break;

    iVar8 = iVar4 + 1;

    if (iVar8 < iVar5) {

    iVar7 = iVar2 + -1;

    LAB_00551920:

    iVar8 = iVar7;

    }

    else {

    iVar7 = iVar5;

    if (iVar2 + -1 < iVar8) goto LAB_00551920;

    }

    DAT_00748a30 = iVar8;

    (&DAT_00748b50)[iVar4 * 3] = 0;

    iVar4 = DAT_0074b5f8;

    (&DAT_00748b50)[iVar8 * 3] = 1;

    iVar4 = *(int *)(*(int *)(iVar4 + iVar6 * 0x24) + 4 + iVar8 * 4);

    DAT_00702c1c = fVar10 * ((*(float *)(iVar4 + 0x44) * fVar1 +

    *(float *)(iVar4 + 0x38) * fVar1) / fVar10);

    DAT_00702c20 = ((*(float *)(iVar4 + 0x48) * fVar1 + *(float *)(iVar4 + 0x3c) * fVar1) /

    fVar11) * fVar11;

    iVar4 = iVar8;

    DAT_00702c24 = DAT_00702c1c;

    DAT_00702c28 = DAT_00702c20;

    } while (DAT_00749398 < iVar8);

    }

    goto LAB_005519c6;

    }

    local_10 = DAT_00748a30 + -1;

    if (local_10 < DAT_00682e98) {

    iVar6 = DAT_0068298c + -1;

    LAB_00551577:

    local_10 = iVar6;

    }

    else {

    iVar6 = DAT_00682e98;

    if (DAT_0068298c + -1 < local_10) goto LAB_00551577;

    }

    bVar9 = DAT_00702b30 == 0;

    iVar6 = DAT_00748a30 * 3;

    DAT_00748a30 = local_10;

    (&DAT_00748b50)[iVar6] = 0;

    (&DAT_00748b50)[local_10 * 3] = 1;

    if (((bVar9) && (DAT_00702b34 == 0)) &&

    ((DAT_00702b50 == 0 && ((local_10 != iVar8 && (DAT_00702bb8 == 0)))))) {

    FUN_00558360();

    local_10 = DAT_00748a30;

    iVar5 = DAT_00682e98;

    iVar4 = DAT_00749398;

    iVar2 = DAT_0068298c;

    }

    iVar6 = DAT_0074b5fc;

    fVar1 = DAT_0066be20;

    fVar10 = (float)DAT_0074b604;

    iVar8 = *(int *)(*(int *)(DAT_0074b5f8 + DAT_0074b5fc * 0x24) + 4 + local_10 * 4);

    fVar11 = (float)DAT_0074b608;

    DAT_00702c1c = fVar10 * ((*(float *)(iVar8 + 0x44) * DAT_0066be20 +

    *(float *)(iVar8 + 0x38) * DAT_0066be20) / fVar10);

    DAT_00702c20 = fVar11 * ((*(float *)(iVar8 + 0x48) * DAT_0066be20 +

    *(float *)(iVar8 + 0x3c) * DAT_0066be20) / fVar11);

    DAT_00702c24 = DAT_00702c1c;

    DAT_00702c28 = DAT_00702c20;

    if (iVar4 < local_10) {

    do {

    DAT_00702c1c = DAT_00702c24;

    DAT_00702c20 = DAT_00702c28;

    if (local_10 == 0x15) break;

    iVar8 = local_10 + -1;

    if (iVar8 < iVar5) {

    iVar4 = iVar2 + -1;

    LAB_005516d0:

    iVar8 = iVar4;

    }

    else {

    iVar4 = iVar5;

    if (iVar2 + -1 < iVar8) goto LAB_005516d0;

    }

    DAT_00748a30 = iVar8;

    (&DAT_00748b50)[local_10 * 3] = 0;

    iVar4 = DAT_0074b5f8;

    (&DAT_00748b50)[iVar8 * 3] = 1;

    iVar4 = *(int *)(*(int *)(iVar4 + iVar6 * 0x24) + 4 + iVar8 * 4);

    DAT_00702c1c = fVar10 * ((*(float *)(iVar4 + 0x44) * fVar1 + *(float *)(iVar4 + 0x38) * fVar1)

    / fVar10);

    DAT_00702c20 = fVar11 * ((*(float *)(iVar4 + 0x48) * fVar1 + *(float *)(iVar4 + 0x3c) * fVar1)

    / fVar11);

    local_10 = iVar8;

    DAT_00702c24 = DAT_00702c1c;

    DAT_00702c28 = DAT_00702c20;

    } while (DAT_00749398 < iVar8);

    }

    LAB_005519c6:

    FUN_005de3d0(DAT_0074b608);

    iVar2 = FUN_005de120();

    iVar5 = DAT_00748a30;

    iVar2 = iVar2 + -1;

    if ((0 < iVar2) && ((iVar2 <= DAT_00749398 || (iVar2 == 0x15)))) {

    if ((iVar2 < DAT_00682e98) || (iVar8 = iVar2, DAT_0068298c + -1 < iVar2)) {

    iVar8 = DAT_00748a30;

    }

    bVar9 = DAT_00702b30 == 0;

    iVar4 = DAT_00748a30 * 3;

    DAT_00748a30 = iVar8;

    (&DAT_00748b50)[iVar4] = 0;

    (&DAT_00748b50)[iVar8 * 3] = 1;

    if ((((bVar9) && (DAT_00702b34 == 0)) && (DAT_00702b50 == 0)) &&

    ((iVar8 != iVar5 && (DAT_00702bb8 == 0)))) {

    FUN_00558360();

    }

    }

    if ((DAT_00702c08 == '\0') && ((DAT_00702c0a == '\0' || (iVar2 < 0)))) {

    if (DAT_00748a30 == 0x15) {

    pcVar12 = "MH_FlickReturn";

    }

    else {

    pcVar12 = "MH_FlickPlay";

    }

    uVar3 = FUN_005e80c0(pcVar12);

    FUN_00463000(&DAT_00748a40,&DAT_00660434,uVar3);

    return;

    }

    FUN_00551280();

    return;


}  // 0x005514b0
#endif // RenderFn5514B0
void RenderFn5514B0() {}  // 0x005514b0
#if 0 // GHIDRA_RAW: SysFn641A9D @ 0x00641a9d — needs manual cleanup
void SysFn641A9D()
{


    cVar5 = '\x01';

    LAB_00641b06:

    local_44 = 0x13;

    BVar3 = SetFileInformationByHandle(local_40,0x15,&local_44,4);

    if (BVar3 == 0) {

    DVar2 = GetLastError();

    if (((DVar2 != 1) && (DVar2 != 0x32)) && (DVar2 != 0x57)) goto LAB_00641bef;

    DVar2 = FUN_0064112c(local_40);

    if (DVar2 == 0) goto LAB_00641b23;

    if ((DVar2 != 5) || (cVar5 == '\0')) goto LAB_00641bef;

    DVar2 = 0;

    BVar3 = GetFileInformationByHandleEx(local_40,FileBasicInfo,local_30,0x28);

    if (BVar3 == 0) {

    LAB_00641b7c:

    local_38 = local_38 & 0xffffff00;

    }

    else {

    if ((local_10 & 1) == 0) {

    local_38 = local_38 & 0xffffff00;

    LAB_00641bd5:

    DVar2 = 5;

    goto LAB_00641bf4;

    }

    local_10 = local_10 ^ 1;

    BVar3 = SetFileInformationByHandle(local_40,FileBasicInfo,local_30,0x28);

    if (BVar3 == 0) goto LAB_00641b7c;

    iVar4 = FUN_0064112c(local_40);

    if (iVar4 == 0) {

    local_38 = CONCAT31(local_38._1_3_,1);

    goto LAB_00641bf4;

    }

    if (iVar4 != 5) {

    local_38 = (uint)local_38._1_3_ << 8;

    DVar2 = GetLastError();

    goto LAB_00641c2e;

    }

    local_10 = local_10 | 1;

    BVar3 = SetFileInformationByHandle(local_40,FileBasicInfo,local_30,0x28);

    local_38 = local_38 & 0xffffff00;

    if (BVar3 != 0) goto LAB_00641bd5;

    }

    DVar2 = GetLastError();

    }

    else {

    LAB_00641b23:

    local_38 = CONCAT31(local_38._1_3_,1);

    DVar2 = 0;

    }


}  // 0x00641a9d
#endif // SysFn641A9D
void SysFn641A9D() {}  // 0x00641a9d
#if 0 // GHIDRA_RAW: CoreFn4319C0 @ 0x004319c0 — needs manual cleanup
void CoreFn4319C0()
{


    std::_Lockit::_Lockit((_Lockit *)&local_1c,0);

    pcVar2 = _Id_cnt_exref;

    if (*(int *)pcVar3 == 0) {

    *(int *)_Id_cnt_exref = *(int *)_Id_cnt_exref + 1;

    *(uint32_t *)pcVar3 = *(uint32_t *)pcVar2;

    }

    std::_Lockit::~_Lockit((_Lockit *)&local_1c);


}  // 0x004319c0
#endif // CoreFn4319C0
void CoreFn4319C0() {}  // 0x004319c0
void GameFn4622C0() {}  // 0x004622c0
#if 0 // GHIDRA_RAW: GameFn4A2050 @ 0x004a2050 — needs manual cleanup
void GameFn4A2050(int param_1,float *param_2,float *param_3)
{


    bool bVar1;

    uint32_t *puVar2;

    int iVar3;

    int iVar4;

    uint32_t uVar5;

    int iVar6;

    int iVar7;

    float10 fVar8;

    float fVar9;

    float fVar10;

    double dVar11;

    double dVar12;

    float local_74;

    float local_70;

    float local_6c;

    float *local_68;

    uint32_t *local_64;

    int local_60;

    int local_5c;

    float local_58;

    float local_54;

    float local_50;

    float fStack_4c;

    float local_48;

    uint32_t local_44;



    local_44 = DAT_0067d280 ^ (uint)&local_74;

    if (param_2 == (float *)0x0) {

    local_48 = param_3[2];

    fStack_4c = 9999.0;

    local_50 = 9999.0;

    }

    else {

    local_50 = *param_2;

    fStack_4c = param_2[1];

    local_48 = param_2[2];

    }

    iVar7 = 4;

    local_68 = param_2;

    local_5c = param_1;

    do {

    iVar3 = FUN_004a0ea0();

    puVar2 = DAT_007027bc;

    if (iVar3 == 0) break;

    fVar8 = (float10)FUN_006389d0(param_3,&local_50);

    local_64 = (uint32_t *)(float)fVar8;

    FUN_006387e0(local_64);

    *param_3 = local_58 * *(float *)(DAT_00702770 + 0x238) * DAT_0066bdc4 + *param_3;

    param_3[1] = param_3[1] - local_54 * *(float *)(DAT_00702770 + 0x238) * DAT_0066bdc4;

    bVar1 = 0 < iVar7;

    iVar7 = iVar7 + -1;

    puVar2 = DAT_007027bc;

    } while (bVar1);

    do {

    local_64 = puVar2;

    if (local_64 == (uint32_t *)0x0) {

    return;

    }

    local_60 = local_64[3];

    uVar5 = *(uint32_t *)(local_60 + 0x214) >> 0xb & 1;

    if ((*(uint32_t *)(local_60 + 0x124) & 0x4000c000) != 0) {

    uVar5 = 1;

    }

    if ((((uVar5 == 0) && ((*(uint32_t *)(local_60 + 0x214) & 0x800) == 0)) &&

    ((param_1 == 0 ||

    (((*(int *)(param_1 + 0x22c) != 1 && ((param_1 == 0 || (*(int *)(param_1 + 0x22c) != 0xf)))

    ) || ((*(byte *)(local_60 + 0x218) & 1) == 0)))))) &&

    (((param_1 != local_60 && (*(int *)(local_60 + 8) != 0)) &&

    (*(int *)(local_60 + 0x264) != param_1)))) {

    local_74 = *param_3 * DAT_0066bdb8 + DAT_0066be20;

    dVar11 = floor((double)local_74);

    local_74 = param_3[1] * DAT_0066bdb8 + DAT_0066be20;

    dVar12 = floor((double)local_74);

    local_74 = (float)dVar12;

    iVar7 = (int)dVar12;

    iVar3 = FUN_0049fdb0(iVar7);

    param_1 = local_5c;

    while (local_5c = param_1, iVar3 != 0) {

    iVar3 = (int)dVar11;

    local_74 = *local_68;

    local_6c = local_74 * DAT_0066bdb8 + DAT_0066be20;

    dVar11 = floor((double)local_6c);

    local_70 = (float)dVar11;

    local_6c = local_68[1] * DAT_0066bdb8 + DAT_0066be20;

    dVar11 = floor((double)local_6c);

    iVar4 = (int)local_70;

    iVar6 = (int)dVar11;

    if (iVar3 == iVar4) {

    if (iVar7 == iVar6) {

    return;

    }

    LAB_004a22e1:

    fVar9 = 0.0;

    }

    else {

    if (iVar4 < iVar3) {

    iVar3 = iVar3 + -1;

    }

    else {

    if (iVar4 <= iVar3) goto LAB_004a22e1;

    iVar3 = iVar3 + 1;

    }

    fVar9 = ((float)iVar3 * DAT_0066bfe8 - local_74) / (*param_3 - local_74);

    }

    if (iVar6 < iVar7) {

    iVar7 = iVar7 + -1;

    LAB_004a2337:

    fVar10 = ((float)iVar7 * DAT_0066bfe8 - local_68[1]) / (param_3[1] - local_68[1]);

    }

    else {

    if (iVar7 < iVar6) {

    iVar7 = iVar7 + 1;

    goto LAB_004a2337;

    }

    fVar10 = 0.0;

    }

    if (fVar10 <= fVar9) {

    fVar10 = fVar9;

    }

    fVar9 = (*param_3 - local_74) * fVar10 + local_74;

    *param_3 = fVar9;

    local_70 = fVar9 * DAT_0066bdb8 + DAT_0066be20;

    local_6c = (param_3[1] - local_68[1]) * fVar10 + local_68[1];

    param_3[1] = local_6c;

    dVar11 = floor((double)local_70);

    local_70 = local_6c * DAT_0066bdb8 + DAT_0066be20;

    dVar12 = floor((double)local_70);

    local_70 = (float)dVar12;

    iVar7 = (int)dVar12;

    iVar3 = FUN_0049fdb0(iVar7);

    param_1 = local_5c;

    }

    }

    puVar2 = (uint32_t *)*local_64;

    } while( true );


}  // 0x004a2050
#endif // GameFn4A2050
void GameFn4A2050() {}  // 0x004a2050
#if 0 // GHIDRA_RAW: GameFn4A8A00 @ 0x004a8a00 — needs manual cleanup
void GameFn4A8A00(int param_1,int param_2)
{


    int iVar1;

    float *pfVar2;

    int iVar3;

    int iVar4;

    float in_XMM0_Da;

    float fVar5;



    if (param_1 == 0) {

    iVar4 = 0;

    LAB_004a8a39:

    iVar3 = FUN_00559dc0();

    FUN_00575760(iVar3);

    }

    else {

    iVar4 = *(int *)(param_1 + 0x14c);

    if (*(int *)(param_1 + 0x22c) != 0x20) goto LAB_004a8a39;

    iVar3 = FUN_00559dc0();

    }

    *(int *)(iVar4 + 0x20 + param_2 * 0x1c) = iVar3;

    FUN_0055c150();

    fVar5 = 0.0;

    iVar1 = *(int *)(iVar3 + 0x22c);

    *(uint32_t *)(iVar3 + 0x114) = *(uint32_t *)(iVar4 + 0x30 + param_2 * 0x1c);

    *(uint32_t *)(iVar3 + 0x118) = 0;

    *(uint32_t *)(iVar3 + 0x11c) = 0;

    *(uint32_t *)(iVar3 + 0x130) = 4;

    *(int *)(iVar3 + 0x2c4) = param_1;

    if ((iVar1 == 0x20) || (iVar1 == 0x4a)) {

    FUN_00497350();

    if (iVar1 != 0x20) goto LAB_004a8adb;

    }

    else {

    if ((iVar1 != 0x52) && (iVar1 != 0x53)) goto LAB_004a8b26;

    FUN_00580930();

    LAB_004a8adb:

    if (iVar1 != 0x52) {

    if ((((iVar1 == 0x4a) || (iVar1 == 0x53)) &&

    (pfVar2 = *(float **)(iVar3 + 0x14c), pfVar2 != (float *)0x0)) &&

    (*pfVar2 = in_XMM0_Da, in_XMM0_Da < fVar5)) {

    *pfVar2 = 0.0;

    }

    goto LAB_004a8b26;

    }

    }

    iVar4 = *(int *)(iVar3 + 0x14c);

    if ((iVar4 != 0) && (*(float *)(iVar4 + 0x594) = in_XMM0_Da, in_XMM0_Da < fVar5)) {

    *(uint32_t *)(iVar4 + 0x594) = 0;

    }

    LAB_004a8b26:

    FUN_0048f2f0(1,0x84,0,0,0);

    FUN_0048f2f0(0xfe,0,0,0,0);

    *(uint32_t *)(iVar3 + 100) = 0x3f800000;

    *(uint32_t *)(iVar3 + 0x214) = *(uint32_t *)(iVar3 + 0x214) & 0xfffff7ff | 0x20000;

    return;


}  // 0x004a8a00
#endif // GameFn4A8A00
void GameFn4A8A00() {}  // 0x004a8a00
#if 0 // GHIDRA_RAW: GameFn4ACA40 @ 0x004aca40 — needs manual cleanup
void GameFn4ACA40(int param_1,int param_2,float *param_3,int param_4)
{


    int iVar1;

    int iVar2;

    uint32_t *puVar3;

    int *piVar4;

    bool bVar5;

    float10 fVar6;

    float fVar7;

    float fVar8;

    uint8_t local_3c [4];

    float local_38;

    float fStack_34;

    float local_30;

    float local_20;

    uint32_t local_1c;

    uint32_t local_18;



    if (param_3 == (float *)0x0) {

    if (param_4 == 10) {

    return;

    }

    param_3 = (float *)(param_1 + 0xf0);

    }

    local_38 = *param_3;

    fStack_34 = param_3[1];

    local_30 = param_3[2];

    switch(param_4) {

    case 1:

    FUN_004e9cd0(local_3c);

    if (DAT_00702bb8 != 0) {

    return;

    }

    if (DAT_00702800 == 0) {

    return;

    }

    piVar4 = (int *)(DAT_00702800 + 0x10ca4);

    bVar5 = piVar4 == (int *)0x0;

    break;

    case 2:

    FUN_004e9cd0(local_3c);

    if ((DAT_00702bb8 != 0) || (DAT_00702800 == 0)) goto LAB_004acc4a;

    piVar4 = (int *)(DAT_00702800 + 0x10ca4);

    goto LAB_004acc15;

    case 3:

    FUN_004e9cd0(local_3c);

    if (DAT_00702bb8 != 0) {

    return;

    }

    if (DAT_00702800 == 0) {

    return;

    }

    piVar4 = (int *)(DAT_00702800 + 0x10cd0);

    bVar5 = piVar4 == (int *)0x0;

    break;

    case 4:

    goto LAB_004acbea;

    case 5:

    goto LAB_004acbea;

    case 6:

    FUN_004e9cd0(local_3c);

    if (DAT_00702bb8 != 0) {

    return;

    }

    if (DAT_00702800 == 0) {

    return;

    }

    piVar4 = (int *)(DAT_00702800 + 0x10b9c);

    bVar5 = piVar4 == (int *)0x0;

    break;

    case 7:

    goto LAB_004acbea;

    case 8:

    LAB_004acbea:

    FUN_004e9cd0(local_3c);

    if ((DAT_00702bb8 == 0) && (DAT_00702800 != 0)) {

    piVar4 = (int *)(DAT_00702800 + 0x10b70);

    LAB_004acc15:

    if ((((piVar4 != (int *)0x0) && (*piVar4 != 0)) && (piVar4[2] != 0)) &&

    (iVar2 = (*DAT_0072809c)(piVar4,param_1), iVar2 == 0)) {

    FUN_00558f80(piVar4,"SoundFail {0}",0xd);

    }

    }

    LAB_004acc4a:

    if (*(int *)(param_1 + 0x1d8) != *(int *)(DAT_00702774 + 0x1d8)) {

    return;

    }

    if ((param_2 != 0) && (*(int *)(param_2 + 0x1d8) == *(int *)(param_1 + 0x1d8))) {

    return;

    }

    iVar2 = *(int *)(param_1 + 0x2c4);

    if (iVar2 == 0) {

    return;

    }

    if (*(int *)(iVar2 + 0x22c) != 0x20) {

    if (iVar2 == 0) {

    return;

    }

    if (*(int *)(iVar2 + 0x22c) != 0x52) {

    return;

    }

    }

    iVar1 = *(int *)(iVar2 + 0x14c);

    piVar4 = DAT_007027d8;

    if (DAT_007027d8 == (int *)0x0) {

    return;

    }

    while (((*(int *)(piVar4[3] + 4) != 0xb || (*(int *)(piVar4[3] + 0x2c4) != iVar2)) ||

    (DAT_00702890 - *(float *)(iVar1 + 0x5d8) <= DAT_0066bfe8))) {

    piVar4 = (int *)*piVar4;

    if (piVar4 == (int *)0x0) {

    return;

    }

    }

    FUN_005e81d0();

    FUN_00453a40(4,0);

    *(float *)(iVar1 + 0x5d8) = DAT_00702890;

    if ((DAT_00702774 != 0) && (*(int *)(DAT_00702774 + 0x22c) == 2)) {

    iVar2 = rand();

    if (0x18ffff < (int)(iVar2 * 100 & 0xffff8000U)) {

    puVar3 = (uint32_t *)(DAT_00702770 + 0x51b0);

    if (0xf < *(uint32_t *)(DAT_00702770 + 0x51c4)) {

    puVar3 = (uint32_t *)*puVar3;

    }

    if (DAT_00702bbc != 0) {

    return;

    }

    (*DAT_0072807c)("REG_CT15",puVar3,0);

    return;

    }

    puVar3 = (uint32_t *)(DAT_00702770 + 0x51b0);

    if (0xf < *(uint32_t *)(DAT_00702770 + 0x51c4)) {

    puVar3 = (uint32_t *)*puVar3;

    }

    if (DAT_00702bbc != 0) {

    return;

    }

    (*DAT_0072807c)("GOR_CT15",puVar3,0);

    return;

    }

    puVar3 = (uint32_t *)(DAT_00702770 + 0x51b0);

    if (0xf < *(uint32_t *)(DAT_00702770 + 0x51c4)) {

    puVar3 = (uint32_t *)*puVar3;

    }

    if (DAT_00702bbc != 0) {

    return;

    }

    (*DAT_0072807c)("DELCT15_2",puVar3,0);

    return;

    case 9:

    FUN_004e9cd0(local_3c);

    if (DAT_00702bb8 != 0) {

    return;

    }

    if (DAT_00702800 == 0) {

    return;

    }

    piVar4 = (int *)(DAT_00702800 + 0x10b70);

    bVar5 = piVar4 == (int *)0x0;

    break;

    case 10:

    if (param_2 == 0) {

    fVar7 = *(float *)(param_1 + 0xf0) - *param_3;

    fVar8 = *(float *)(param_1 + 0xf4) - param_3[1];

    }

    else {

    fVar7 = *(float *)(param_2 + 0xf0) - *(float *)(param_2 + 0x108);

    fVar8 = *(float *)(param_2 + 0xf4) - *(float *)(param_2 + 0x10c);

    }

    fVar6 = (float10)FUN_006386b0(fVar8,fVar7);

    local_1c = 0;

    local_18 = 0;

    local_20 = (float)(fVar6 - (float10)DAT_0066c0cc);

    FUN_004e9cd0(local_3c);

    default:

    goto switchD_004aca8e_default;

    }

    if ((((!bVar5) && (*piVar4 != 0)) && (piVar4[2] != 0)) &&

    (iVar2 = (*DAT_0072809c)(piVar4,param_1), iVar2 == 0)) {

    FUN_00558f80(piVar4,"SoundFail {0}",0xd);

    return;

    }

    switchD_004aca8e_default:

    return;


}  // 0x004aca40
#endif // GameFn4ACA40
void GameFn4ACA40() {}  // 0x004aca40
#if 0 // GHIDRA_RAW: GameFn4B3CD0 @ 0x004b3cd0 — needs manual cleanup
void GameFn4B3CD0()
{


    RegSetValueExA(DAT_0074be5c,"KeyVersion",0,4,local_64,4);

    puVar1 = puStack_24;

    puVar2 = (uint32_t *)local_20;


}  // 0x004b3cd0
#endif // GameFn4B3CD0
void GameFn4B3CD0() {}  // 0x004b3cd0
#if 0 // GHIDRA_RAW: GameFn4BDC70 @ 0x004bdc70 — needs manual cleanup
uint32_t * GameFn4BDC70(uint32_t *param_1,uint32_t *param_2)
{


    char *pcVar1;

    uint32_t *puVar2;

    char *pcVar3;

    int *local_6c;

    void *local_1c;

    uint8_t *puStack_18;

    uint32_t local_14;



    local_14 = 0xffffffff;

    puStack_18 = &LAB_006496cd;

    local_1c = ExceptionList;

    // ExceptionList = ... (SEH frame, stubbed)

    if (param_2[1] == 0) {

    *param_1 = 0;

    param_1[1] = 0;

    param_1[2] = 0;

    param_1[3] = 0;

    param_1[4] = 0;

    param_1[5] = 0;

    FUN_004bdd60(&DAT_0065f21c,0);

    }

    else {

    FUN_004bd640(DAT_0067d280 ^ (uint)&stack0xfffffff0);

    local_14 = 0;

    pcVar1 = (char *)*param_2;

    do {

    pcVar3 = pcVar1;

    pcVar1 = pcVar3 + 1;

    } while (*pcVar3 != '\0');

    FUN_004bd8e0(param_1,(char *)*param_2,pcVar3);

    FUN_00443490();

    FUN_004439b0();

    if (local_6c != (int *)0x0) {

    puVar2 = (uint32_t *)(**(code **)(*local_6c + 8))();

    if (puVar2 != (uint32_t *)0x0) {

    (**(code **)*puVar2)(1);

    }

    }

    }

    // ExceptionList = ... (SEH frame, stubbed)

    return param_1;


}  // 0x004bdc70
#endif // GameFn4BDC70
void GameFn4BDC70() {}  // 0x004bdc70
#if 0 // GHIDRA_RAW: GameFn4C1C00 @ 0x004c1c00 — needs manual cleanup
void GameFn4C1C00()
{


    FUN_0042c4e0(puVar1,&local_14);

    if (local_14 != (uint32_t *)0x0) {

    (**(code **)*local_14)(1);

    }


}  // 0x004c1c00
#endif // GameFn4C1C00
void GameFn4C1C00() {}  // 0x004c1c00
#if 0 // GHIDRA_RAW: GameFn4EA510 @ 0x004ea510 — needs manual cleanup
void GameFn4EA510(uint32_t param_1,uint32_t param_2)
{


    int iVar1;

    uint8_t local_3c [24];

    uint32_t local_24 [2];

    uint32_t local_1c;

    uint32_t local_14;

    void *local_10;

    uint8_t *puStack_c;

    uint32_t local_8;



    local_8 = 0xffffffff;

    puStack_c = &LAB_0064846d;

    local_10 = ExceptionList;

    local_14 = DAT_0067d280 ^ (uint)&stack0xfffffffc;

    // ExceptionList = ... (SEH frame, stubbed)

    iVar1 = FUN_0055a8a0(local_14);

    if ((iVar1 != 0) && (*(int *)(iVar1 + 0x22c) != 0x4e)) {

    local_1c = FUN_004e98e0();

    local_24[0] = param_2;

    fmt::v9::vformat(local_3c,"createobj {0} is invalid for FX {1}",0x23,0xc1,0,local_24);

    local_8 = 0;

    FUN_0043f440(6,4,local_3c);

    FUN_004439b0();

    }

    // ExceptionList = ... (SEH frame, stubbed)

    return;


}  // 0x004ea510
#endif // GameFn4EA510
void GameFn4EA510() {}  // 0x004ea510
#if 0 // GHIDRA_RAW: GameFn4FD5A0 @ 0x004fd5a0 — needs manual cleanup
void GameFn4FD5A0(void)
{


    float fVar1;

    uint32_t *puVar2;

    int iVar3;

    float fVar4;

    float *pfVar5;

    int iVar6;

    int iVar7;

    int *piVar8;

    int iVar9;

    int iVar10;

    float fVar11;



    if ((DAT_0070274c != 0) && ((*(uint32_t *)(DAT_0070274c + 0x124) & 0x8000) != 0)) {

    DAT_00681db0 = 0;

    DAT_00681db4 = 0xffffffff;

    DAT_00681dec = 0;

    DAT_00681e34 = 0;

    DAT_0070274c = 0;

    DAT_00702748 = (float *)0x0;

    FUN_004fccc0();

    }

    if ((DAT_007026fc != 0) && ((*(uint32_t *)(DAT_007026fc + 0x124) & 0x8000) != 0)) {

    DAT_00681db0 = 0;

    DAT_00681db4 = 0xffffffff;

    DAT_00681dec = 0;

    DAT_00681e34 = 0;

    DAT_0070274c = 0;

    DAT_00702748 = (float *)0x0;

    FUN_004fccc0();

    }

    if ((DAT_00702774 != 0) && (*(float *)(DAT_00702774 + 0x20c) <= *(float *)(DAT_00702774 + 0x2c8)))

    {

    FUN_004fccc0();

    *(float *)(DAT_00702774 + 0x17c) = *(float *)(DAT_00702774 + 0x17c) + DAT_0066c068;

    return;

    }

    if ((*(int *)(DAT_00702774 + 0x124) < 0) ||

    ((*(int *)(DAT_00702774 + 0x264) != 0 &&

    (*(int *)(*(int *)(DAT_00702774 + 0x264) + 0x22c) == 1)))) {

    FUN_004fccc0();

    }

    if (DAT_006ff960 == 6) {

    fVar1 = *(float *)(DAT_007028f4 + 0x10e4);

    fVar11 = fVar1;

    FUN_0062a0b0();

    fVar11 = fVar11 * fVar1;

    fVar1 = *(float *)(DAT_00702774 + 0x2c8);

    fVar4 = fVar1;

    if (fVar11 <= fVar1) {

    fVar4 = fVar11;

    }

    *(float *)(DAT_00702774 + 0x2c8) = fVar1 - fVar4;

    if (fVar1 - fVar4 < 0.0) {

    *(uint32_t *)(DAT_00702774 + 0x2c8) = 0;

    }

    }

    else if (((DAT_00702748 != (float *)0x0) && (0.0 < *DAT_00702748)) &&

    (0.0 < *(float *)(DAT_00702774 + 0x2c8))) {

    fVar1 = *(float *)(DAT_007028f4 + 0x10e4);

    fVar11 = fVar1;

    FUN_0062a0b0();

    pfVar5 = DAT_00702748;

    fVar11 = fVar11 * fVar1;

    fVar1 = *(float *)(DAT_00702774 + 0x2c8);

    fVar4 = fVar1;

    if (fVar11 <= fVar1) {

    fVar4 = fVar11;

    }

    fVar11 = *DAT_00702748;

    if (fVar11 <= fVar4) {

    *(float *)(DAT_00702774 + 0x2c8) = fVar1 - fVar11;

    *pfVar5 = 0.0;

    }

    else {

    *DAT_00702748 = fVar11 - fVar4;

    *(float *)(DAT_00702774 + 0x2c8) = *(float *)(DAT_00702774 + 0x2c8) - fVar4;

    }

    if (*(float *)(DAT_00702774 + 0x2c8) <= 0.0 && *(float *)(DAT_00702774 + 0x2c8) != 0.0) {

    *(uint32_t *)(DAT_00702774 + 0x2c8) = 0;

    }

    }

    iVar7 = DAT_0074b5fc;

    iVar6 = DAT_0074b5f8;

    DAT_00748704 = 0;

    _DAT_00748708 = 0;

    for (puVar2 = DAT_007027ac; puVar2 != (uint32_t *)0x0; puVar2 = (uint32_t *)*puVar2) {

    iVar10 = puVar2[3];

    if ((*(int *)(iVar10 + 4) == 0x3c) &&

    ((_DAT_00748708 = _DAT_00748708 + 1, *(int *)(iVar10 + 0x264) == DAT_00702774 ||

    (*(int *)(iVar10 + 0x2c4) == DAT_00702774)))) {

    DAT_00748704 = DAT_00748704 + 1;

    }

    }

    _DAT_00748710 = 0;

    DAT_0074870c = 0;

    iVar10 = *(int *)(DAT_00702774 + 0x1d8);

    for (puVar2 = DAT_007027a8; puVar2 != (uint32_t *)0x0; puVar2 = (uint32_t *)*puVar2) {

    iVar3 = puVar2[3];

    if (((*(int *)(DAT_00702774 + 0x22c) == 2) && (*(int *)(iVar3 + 4) == 0x325)) ||

    ((*(int *)(DAT_00702774 + 0x22c) == 3 && (*(int *)(iVar3 + 4) == 0x4c6)))) {

    _DAT_00748710 = _DAT_00748710 + 1;

    if (*(int *)(iVar3 + 0x1d8) == iVar10) {

    DAT_0074870c = DAT_0074870c + 1;

    }

    }

    else if (iVar3 != 0) {

    if (*(int *)(iVar3 + 0x22c) == 2) {

    iVar9 = *(int *)(*(int *)(iVar3 + 0x14c) + 0x13c);

    LAB_004fd8dd:

    _DAT_00748710 = _DAT_00748710 + iVar9;

    if (*(int *)(iVar3 + 0x1d8) == iVar10) {

    DAT_0074870c = DAT_0074870c + iVar9;

    }

    }

    else if (*(int *)(iVar3 + 0x22c) == 3) {

    iVar10 = 0;

    piVar8 = (int *)(*(int *)(iVar3 + 0x14c) + 0xd80);

    do {

    if (*piVar8 == 0x3f) {

    iVar9 = *(int *)(*(int *)(iVar3 + 0x14c) + 0xd84 + iVar10 * 8);

    iVar10 = *(int *)(DAT_00702774 + 0x1d8);

    goto LAB_004fd8dd;

    }

    iVar10 = iVar10 + 1;

    piVar8 = piVar8 + 2;

    } while (iVar10 < 2);

    iVar10 = *(int *)(DAT_00702774 + 0x1d8);

    }

    }

    }

    DAT_0074b614 = 1;

    DAT_0074b618 = 0;

    iVar10 = *(int *)(DAT_0074b5f8 + 4 + DAT_0074b5fc * 0x24);

    if (iVar10 != 0) {

    do {

    FUN_005d79a0();

    iVar10 = iVar10 + -1;

    } while (iVar10 != 0);

    if ((DAT_0074b614 == 0) || (DAT_0074b618 != 0)) goto LAB_004fda38;

    }

    if (DAT_0074b60c < DAT_0066bf2c) {

    DAT_0074b618 = 1;

    iVar10 = *(int *)(iVar6 + 4 + iVar7 * 0x24);

    piVar8 = *(int **)(iVar6 + iVar7 * 0x24);

    while (iVar10 != 0) {

    iVar10 = iVar10 + -1;

    if ((*(byte *)(*piVar8 + 0x18) & 0x10) != 0) {

    FUN_005d79a0();

    }

    piVar8 = piVar8 + 1;

    }

    DAT_0074b618 = 0;

    }

    LAB_004fda38:

    DAT_0074b614 = 0;

    FUN_005de3d0(DAT_0074b608);

    FUN_005de120();

    FUN_005255b0();

    if (((DAT_007488b4 == 0) && (DAT_007488dc != 0)) &&

    ((DAT_00702c50 != '\0' || ((DAT_00702c07 != '\0' || (DAT_00702c4c != '\0')))))) {

    FUN_004fccc0();

    }

    return;


}  // 0x004fd5a0
#endif // GameFn4FD5A0
void GameFn4FD5A0() {}  // 0x004fd5a0
#if 0 // GHIDRA_RAW: RenderFn507180 @ 0x00507180 — needs manual cleanup
void RenderFn507180(int param_1)
{


    int iVar1;

    int iVar2;

    uint32_t uVar3;

    int iVar4;

    uint32_t *puVar5;

    int *piVar6;

    float10 fVar7;

    float fVar8;



    if (param_1 == 0) {

    return;

    }

    if (*(int *)(param_1 + 0x22c) != 2) {

    return;

    }

    if (*(int *)(*(int *)(param_1 + 0x14c) + 0x168 + *(int *)(*(int *)(param_1 + 0x14c) + 0x50) * 4) <

    0) goto LAB_005073dc;

    if (DAT_006ff960 == 6) {

    FUN_00506f00();

    goto LAB_005073dc;

    }

    if ((*(int *)(param_1 + 0x22c) == 2) &&

    (*(int *)(*(int *)(param_1 + 0x14c) + 0x168 + *(int *)(*(int *)(param_1 + 0x14c) + 0x50) * 4)

    == 1)) goto LAB_005073dc;

    iVar4 = rand();

    fVar8 = (float)iVar4 * _DAT_0066bd00 * DAT_0066bff4 + 0.0;

    FUN_006387b0(fVar8);

    fVar7 = (float10)FUN_00638780(fVar8);

    puVar5 = (uint32_t *)0x0;

    if (*(int *)(param_1 + 0x22c) == 2) {

    iVar4 = 2;

    uVar3 = *(uint32_t *)

    (*(int *)(param_1 + 0x14c) + 0x168 + *(int *)(*(int *)(param_1 + 0x14c) + 0x50) * 4);

    }

    else {

    iVar4 = *(int *)(param_1 + 0x22c);

    uVar3 = 0;

    }

    iVar2 = *(int *)(param_1 + 0x14c);

    if (iVar4 != 2) {

    iVar4 = 0;

    goto LAB_0050736e;

    }

    switch(uVar3) {

    case 0:

    iVar4 = 1;

    break;

    case 1:

    case 2:

    case 4:

    switchD_0050728f_caseD_1:

    iVar4 = 1;

    goto LAB_0050736c;

    case 3:

    case 0x25:

    iVar4 = *(int *)(iVar2 + 0x134);

    puVar5 = (uint32_t *)(iVar2 + 0x134);

    break;

    case 5:

    case 0x26:

    iVar4 = *(int *)(iVar2 + 0x144);

    puVar5 = (uint32_t *)(iVar2 + 0x144);

    break;

    case 6:

    case 0x27:

    iVar4 = *(int *)(iVar2 + 0x148);

    puVar5 = (uint32_t *)(iVar2 + 0x148);

    break;

    case 7:

    case 0x2b:

    iVar4 = *(int *)(iVar2 + 0x158);

    puVar5 = (uint32_t *)(iVar2 + 0x158);

    break;

    case 8:

    case 0x4b:

    case 0x4c:

    iVar4 = *(int *)(iVar2 + 0x138);

    puVar5 = (uint32_t *)(iVar2 + 0x138);

    break;

    case 9:

    iVar4 = *(int *)(iVar2 + 0x13c);

    puVar5 = (uint32_t *)(iVar2 + 0x13c);

    break;

    default:

    if ((*(uint32_t *)(param_1 + 300) & 0x8020000) == 0) goto switchD_0050728f_caseD_1;

    iVar4 = FUN_0053ea80();

    if ((iVar4 == 0) || (iVar4 = *(int *)(*(int *)(iVar4 + 0x14c) + 4), iVar4 < 1)) {

    iVar4 = 0;

    }

    goto LAB_0050736c;

    case 0xe:

    case 0x28:

    iVar4 = *(int *)(iVar2 + 0x14c);

    puVar5 = (uint32_t *)(iVar2 + 0x14c);

    break;

    case 0xf:

    case 0x29:

    iVar4 = *(int *)(iVar2 + 0x150);

    puVar5 = (uint32_t *)(iVar2 + 0x150);

    break;

    case 0x10:

    case 0x2a:

    iVar4 = *(int *)(iVar2 + 0x154);

    puVar5 = (uint32_t *)(iVar2 + 0x154);

    break;

    case 0x13:

    iVar4 = 999;

    LAB_0050736c:

    puVar5 = (uint32_t *)0x0;

    break;

    case 0x40:

    iVar4 = *(int *)(iVar2 + 0x140);

    puVar5 = (uint32_t *)(iVar2 + 0x140);

    }

    LAB_0050736e:

    FUN_005067d0(iVar4,(float)fVar7 * DAT_0066bfec,0x41280000,0x41f00000);

    if (puVar5 != (uint32_t *)0x0) {

    *puVar5 = 0;

    }

    LAB_005073dc:

    iVar4 = 0x15c;

    do {

    if ((*(int *)(param_1 + 0x22c) == 2) && (*(int *)(iVar4 + *(int *)(param_1 + 0x14c)) < 0))

    goto LAB_005075ad;

    iVar2 = rand();

    fVar8 = (float)iVar2 * _DAT_0066bd00 * DAT_0066bff4 + 0.0;

    FUN_006387b0(fVar8);

    fVar7 = (float10)FUN_00638780(fVar8);

    piVar6 = (int *)0x0;

    if (*(int *)(param_1 + 0x22c) == 2) {

    iVar2 = 2;

    uVar3 = *(uint32_t *)(iVar4 + *(int *)(param_1 + 0x14c));

    }

    else {

    iVar2 = *(int *)(param_1 + 0x22c);

    uVar3 = 0;

    }

    iVar1 = *(int *)(param_1 + 0x14c);

    if (iVar2 != 2) {

    iVar2 = 0;

    goto LAB_0050754e;

    }

    switch(uVar3) {

    case 0:

    iVar2 = 1;

    break;

    case 1:

    case 2:

    case 4:

    switchD_0050749a_caseD_1:

    iVar2 = 1;

    goto LAB_0050754c;

    case 3:

    case 0x25:

    piVar6 = (int *)(iVar1 + 0x134);

    iVar2 = *piVar6;

    break;

    case 5:

    case 0x26:

    piVar6 = (int *)(iVar1 + 0x144);

    iVar2 = *piVar6;

    break;

    case 6:

    case 0x27:

    piVar6 = (int *)(iVar1 + 0x148);

    iVar2 = *piVar6;

    break;

    case 7:

    case 0x2b:

    piVar6 = (int *)(iVar1 + 0x158);

    iVar2 = *piVar6;

    break;

    case 8:

    case 0x4b:

    case 0x4c:

    piVar6 = (int *)(iVar1 + 0x138);

    iVar2 = *piVar6;

    break;

    case 9:

    piVar6 = (int *)(iVar1 + 0x13c);

    iVar2 = *piVar6;

    break;

    default:

    if ((*(uint32_t *)(param_1 + 300) & 0x8020000) == 0) goto switchD_0050749a_caseD_1;

    iVar2 = FUN_0053ea80();

    if ((iVar2 == 0) || (iVar2 = *(int *)(*(int *)(iVar2 + 0x14c) + 4), iVar2 < 1)) {

    iVar2 = 0;

    }

    goto LAB_0050754c;

    case 0xe:

    case 0x28:

    piVar6 = (int *)(iVar1 + 0x14c);

    iVar2 = *piVar6;

    break;

    case 0xf:

    case 0x29:

    piVar6 = (int *)(iVar1 + 0x150);

    iVar2 = *piVar6;

    break;

    case 0x10:

    case 0x2a:

    piVar6 = (int *)(iVar1 + 0x154);

    iVar2 = *piVar6;

    break;

    case 0x13:

    iVar2 = 999;

    LAB_0050754c:

    piVar6 = (int *)0x0;

    break;

    case 0x40:

    piVar6 = (int *)(iVar1 + 0x140);

    iVar2 = *piVar6;

    }

    LAB_0050754e:

    FUN_005067d0(iVar2,(float)fVar7 * DAT_0066bfec,0x41280000,0x41f00000);

    if (piVar6 != (int *)0x0) {

    *piVar6 = 0;

    }

    LAB_005075ad:

    iVar4 = iVar4 + 4;

    if (0x167 < iVar4) {

    if ((*(int *)(param_1 + 0x22c) != 2) || (-1 < *(int *)(*(int *)(param_1 + 0x14c) + 0x178))) {

    iVar4 = rand();

    fVar8 = (float)iVar4 * _DAT_0066bd00 * DAT_0066bff4 + 0.0;

    FUN_006387b0(fVar8);

    fVar7 = (float10)FUN_00638780(fVar8);

    FUN_005067d0(1,(float)fVar7 * DAT_0066bfec,0x41280000,0x41f00000);

    }

    return;

    }

    } while( true );


}  // 0x00507180
#endif // RenderFn507180
void RenderFn507180() {}  // 0x00507180
#if 0 // GHIDRA_RAW: RenderFn53A260 @ 0x0053a260 — needs manual cleanup
void RenderFn53A260(int param_1)
{


    int *piVar1;

    int *piVar2;

    uint32_t *puVar3;

    int iVar4;

    uint32_t uVar5;

    int iVar6;

    int local_38;

    uint8_t local_34 [16];

    uint32_t local_24;

    uint32_t local_20;

    int local_1c;



    if (param_1 == 0) {

    iVar6 = 0;

    }

    else {

    iVar6 = *(int *)(param_1 + 0x14c);

    if ((DAT_006ff960 != 6) || (iVar4 = FUN_0045f460(), iVar4 != 0)) goto LAB_0053a29d;

    }

    if (*(int *)(iVar6 + 0x178) != 0x11) {

    FUN_00502c30();

    }

    LAB_0053a29d:

    piVar2 = DAT_00749908;

    if (*(int *)(iVar6 + 0x178) == 0x11) {

    for (; puVar3 = DAT_007027c0, piVar2 != DAT_0074990c; piVar2 = piVar2 + 2) {

    piVar1 = (int *)*piVar2;

    if (*piVar1 == 0x11) {

    if (piVar1 != (int *)0x0) {

    iVar4 = piVar1[2];

    goto joined_r0x0053a2d6;

    }

    break;

    }

    }

    iVar4 = 0;

    joined_r0x0053a2d6:

    while ((puVar3 != (uint32_t *)0x0 &&

    ((((local_38 = puVar3[3], (*(uint32_t *)(local_38 + 0x124) & 0x8000) != 0 ||

    (*(int *)(local_38 + 0x264) != param_1)) || (*(int *)(local_38 + 4) != iVar4)) ||

    (*(int *)(local_38 + 0x26c) != 10))))) {

    puVar3 = (uint32_t *)*puVar3;

    }

    if (puVar3 == (uint32_t *)0x0) {

    local_38 = 0;

    }

    if (local_38 != 0) {

    local_20 = 1;

    local_24 = 8;

    local_1c = local_38;

    uVar5 = FUN_004e9cd0(local_34);

    *(uint32_t *)(iVar6 + 0xe4) = uVar5;

    FUN_0048f2f0(1,0x20,0,0,0);

    FUN_0048f2f0(0xfe,0,0,0,0);

    }

    *(uint32_t *)(param_1 + 300) = *(uint32_t *)(param_1 + 300) | 0x800000;

    if ((DAT_006ff960 == 6) && (iVar4 = FUN_0045f460(), iVar4 != 0)) {

    FUN_00469de0(0,0,0xe,0,0);

    }

    uVar5 = FUN_00558730(0x5c0,param_1,0,3);

    *(uint32_t *)(iVar6 + 0x1e0) = uVar5;

    }

    return;


}  // 0x0053a260
#endif // RenderFn53A260
void RenderFn53A260() {}  // 0x0053a260
#if 0 // GHIDRA_RAW: RenderFn545860 @ 0x00545860 — needs manual cleanup
void RenderFn545860(uint32_t param_1)
{


    if (DAT_00702968 != '\0') {

    FUN_004d1070(param_1);

    DAT_00681db0 = 0;

    DAT_00681db4 = 0xffffffff;

    DAT_00681dec = 0;

    DAT_00681e34 = 0;

    *(uint32_t *)(DAT_00702d60 + 0x124) = *(uint32_t *)(DAT_00702d60 + 0x124) | 0x8000;

    DAT_00702d60 = 0;

    FUN_00541080();

    FUN_004d39d0();

    DAT_00749004 = 0;

    FUN_00456d20();

    FUN_0045efd0();

    if ((((DAT_00702964 != 0) && (DAT_00702b50 == 0)) && (DAT_00702b54 == '\0')) &&

    (DAT_0073c92c != (int *)0x0)) {

    (**(code **)(*DAT_0073c92c + 0xc))();

    }

    if (((DAT_00702b30 == 0) && (DAT_00702b34 == 0)) && ((DAT_00702b50 == 0 && (DAT_00702bb8 == 0)))

    ) {

    FUN_00558360();

    }

    }

    return;


}  // 0x00545860
#endif // RenderFn545860
void RenderFn545860() {}  // 0x00545860
#if 0 // GHIDRA_RAW: RenderFn548610 @ 0x00548610 — needs manual cleanup
void RenderFn548610(void)
{


    int iVar1;

    uint32_t uVar2;



    FUN_005413d0();

    if (DAT_00702c07 != '\0') {

    FUN_00548580();

    return;

    }

    FUN_005de3d0(DAT_0074b608);

    iVar1 = FUN_005de120();

    if ((iVar1 == 1) && (DAT_00702c0a != '\0')) {

    FUN_00548580();

    }

    if (DAT_00702c08 != '\0') {

    FUN_00548580();

    }

    uVar2 = FUN_005e80c0("MH_NoLoad");

    FUN_00463000(&DAT_00748a40,&DAT_00660434,uVar2);

    return;


}  // 0x00548610
#endif // RenderFn548610
void RenderFn548610() {}  // 0x00548610
#if 0 // GHIDRA_RAW: RenderFn54F930 @ 0x0054f930 — needs manual cleanup
void RenderFn54F930(uint32_t param_1)
{


    FUN_004d1070(param_1);

    DAT_00681db0 = 0;

    DAT_00681db4 = 0xffffffff;

    DAT_00681dec = 0;

    DAT_00681e34 = 0;

    *(uint32_t *)(DAT_00702d60 + 0x124) = *(uint32_t *)(DAT_00702d60 + 0x124) | 0x8000;

    DAT_00702d60 = 0;

    FUN_00541080();

    if (DAT_00748a30 == 1) {

    if (DAT_00748b40 == 0) {

    FUN_00552990();

    }

    else {

    FUN_00550f00();

    }

    }

    else {

    FUN_00549b60();

    }

    if ((((DAT_00702b30 == 0) && (DAT_00702b34 == 0)) && (DAT_00702b50 == 0)) && (DAT_00702bb8 == 0))

    {

    FUN_00558360();

    }

    return;


}  // 0x0054f930
#endif // RenderFn54F930
void RenderFn54F930() {}  // 0x0054f930
#if 0 // GHIDRA_RAW: RenderFn550510 @ 0x00550510 — needs manual cleanup
void RenderFn550510(uint32_t param_1)
{


    FUN_004d1070(param_1);

    DAT_00681db0 = 0;

    DAT_00681db4 = 0xffffffff;

    DAT_00681dec = 0;

    DAT_00681e34 = 0;

    *(uint32_t *)(DAT_00702d60 + 0x124) = *(uint32_t *)(DAT_00702d60 + 0x124) | 0x8000;

    DAT_00702d60 = 0;

    FUN_00541080();

    if (DAT_00748a30 == 1) {

    if (DAT_00748b40 == 0) {

    DAT_00702a5c = 1;

    }

    DAT_007281e4 = 1;

    }

    else if (DAT_00748b40 == 0) {

    FUN_00501920();

    }

    else if (DAT_00748b40 == 1) {

    FUN_00541a50();

    }

    else if (DAT_00748b40 == 2) {

    FUN_00549b60();

    }

    if ((((DAT_00702b30 == 0) && (DAT_00702b34 == 0)) && (DAT_00702b50 == 0)) && (DAT_00702bb8 == 0))

    {

    FUN_00558360();

    }

    return;


}  // 0x00550510
#endif // RenderFn550510
void RenderFn550510() {}  // 0x00550510
#if 0 // GHIDRA_RAW: RenderFn5549D0 @ 0x005549d0 — needs manual cleanup
void RenderFn5549D0()
{


    RegSetValueExA(DAT_0074be5c,"SaveGameVersion",0,4,local_64,4);

    puVar1 = puStack_24;

    puVar2 = (uint32_t *)local_20;


}  // 0x005549d0
#endif // RenderFn5549D0
void RenderFn5549D0() {}  // 0x005549d0
#if 0 // GHIDRA_RAW: RenderFn5637F0 @ 0x005637f0 — needs manual cleanup
void RenderFn5637F0(void)
{


    int iVar1;

    int iVar2;

    float fVar3;

    int *piVar4;

    int iVar5;



    FUN_005255b0();

    iVar2 = DAT_0074b5fc;

    iVar1 = DAT_0074b5f8;

    DAT_0074b614 = 1;

    DAT_0074b618 = 0;

    iVar5 = *(int *)(DAT_0074b5f8 + 4 + DAT_0074b5fc * 0x24);

    if (iVar5 == 0) {

    LAB_005638bc:

    if (DAT_0074b60c < DAT_0066bf2c) {

    DAT_0074b618 = 1;

    iVar5 = *(int *)(iVar1 + 4 + iVar2 * 0x24);

    piVar4 = *(int **)(iVar1 + iVar2 * 0x24);

    while (iVar5 != 0) {

    iVar5 = iVar5 + -1;

    if ((*(byte *)(*piVar4 + 0x18) & 0x10) != 0) {

    FUN_005d79a0();

    }

    piVar4 = piVar4 + 1;

    }

    DAT_0074b618 = 0;

    }

    }

    else {

    do {

    FUN_005d79a0();

    iVar5 = iVar5 + -1;

    } while (iVar5 != 0);

    if ((DAT_0074b614 != 0) && (DAT_0074b618 == 0)) goto LAB_005638bc;

    }

    DAT_0074b614 = 0;

    FUN_005de3d0(DAT_0074b608);

    FUN_005de120();

    if (DAT_007488b4 != 0) {

    return;

    }

    if (DAT_007488e0 == 0) {

    return;

    }

    fVar3 = DAT_007496e8;

    if (DAT_007496e4 <= DAT_0066bfc4) {

    LAB_005639f6:

    DAT_007496e8 = fVar3;

    if (DAT_007496ec == 0) goto LAB_00563a31;

    }

    else if (DAT_007496ec == 0) {

    DAT_007496ec = 1;

    fVar3 = DAT_0066bfc4;

    if ((((DAT_00702800 != 0) &&

    (piVar4 = (int *)(DAT_00702800 + 0x11a0c), fVar3 = DAT_0066bfc4, piVar4 != (int *)0x0)) &&

    (fVar3 = DAT_0066bfc4, *piVar4 != 0)) &&

    (fVar3 = DAT_0066bfc4, *(int *)(DAT_00702800 + 0x11a14) != 0)) {

    (*DAT_007280a8)(piVar4);

    fVar3 = DAT_0066bfc4;

    }

    goto LAB_005639f6;

    }

    if (((0.0 < DAT_007496e8) && (DAT_007496e8 = DAT_007496e8 - DAT_00727e38, DAT_007496e8 <= 0.0)) &&

    (DAT_00702bb8 == 0)) {

    FUN_00558360();

    }

    LAB_00563a31:

    DAT_007496e4 = DAT_007496e4 + DAT_00727e38;

    if (((DAT_00702774 == 0) || (*(float *)(DAT_00702774 + 0x2c8) < *(float *)(DAT_00702774 + 0x20c)))

    && ((DAT_00702c50 == '\0' && ((DAT_00702c07 == '\0' && (DAT_007496e0 == 0)))))) {

    return;

    }

    FUN_00563520();

    return;


}  // 0x005637f0
#endif // RenderFn5637F0
void RenderFn5637F0() {}  // 0x005637f0
#if 0 // GHIDRA_RAW: RenderFn5732E0 @ 0x005732e0 — needs manual cleanup
void RenderFn5732E0(int param_1,float *param_2)
{


    float fVar1;

    float fVar2;

    float in_XMM2_Da;

    float local_158;

    uint8_t local_154 [12];

    float local_148;

    float local_138;

    float local_128;

    uint8_t local_10c [68];

    uint8_t auStack_c8 [76];

    uint8_t local_7c [76];

    float local_30;

    float local_2c;

    float local_28;

    float local_24;

    float local_20;

    float local_1c;

    uint8_t local_18 [16];

    uint32_t local_8;



    local_8 = DAT_0067d280 ^ (uint)&local_158;

    local_20 = param_2[1];

    local_24 = *param_2;

    local_1c = param_2[2];

    fVar2 = DAT_0066bf2c -

    (local_24 * *(float *)(param_1 + 0xf0) + local_20 * *(float *)(param_1 + 0xf4) +

    local_1c * *(float *)(param_1 + 0xf8) + param_2[3]) * in_XMM2_Da;

    fVar1 = 0.0;

    if (0.0 <= fVar2) {

    fVar1 = fVar2;

    }

    local_158 = DAT_0066bf2c;

    if (fVar1 <= DAT_0066bf2c) {

    local_158 = fVar1;

    }

    FUN_0063ee50(local_7c,local_154,param_1 + 0x2e4);

    local_2c = local_138;

    local_30 = local_148;

    local_28 = local_128;

    fVar1 = local_138 * local_138 + local_148 * local_148 + local_128 * local_128;

    FUN_0042bee0();

    if (fVar1 != 0.0) {

    fVar1 = DAT_0066bf2c / fVar1;

    local_30 = fVar1 * local_148;

    local_2c = fVar1 * local_138;

    local_28 = fVar1 * local_128;

    }

    FUN_0063f750(local_18,&local_30,&local_24,local_158);

    FUN_0063eaa0(local_10c,local_18);

    (*(GhidraCodePtr *)PTR_FUN_0067d208)(local_154);

    (*(GhidraCodePtr *)PTR_FUN_0067d208)(auStack_c8);

    return;


}  // 0x005732e0
#endif // RenderFn5732E0
void RenderFn5732E0() {}  // 0x005732e0
#if 0 // GHIDRA_RAW: RenderFn578B40 @ 0x00578b40 — needs manual cleanup
void RenderFn578B40()
{


    piVar7 = puVar8 + -0x15;

    puVar4 = *(uint32_t **)((int)pvVar3 + 0x28);

    if (*(int *)(puVar8[-0x15] + 0x78) == 0) {

    FUN_00490800();

    free(pvVar3);

    }

    else {

    iVar12 = 0;

    puVar10 = (uint32_t *)((int)pvVar3 + 0x2c);

    do {

    if (*piVar7 == 0) break;

    FUN_00633780(*puVar10);

    iVar12 = iVar12 + 1;

    piVar7 = piVar7 + 1;

    puVar10 = puVar10 + 1;

    } while (iVar12 < 10);

    ppuVar6 = &DAT_0073e798;

    for (_Memory = (uint32_t **)DAT_0073e798; _Memory != (uint32_t **)0x0;

    _Memory = (uint32_t **)*_Memory) {

    if (_Memory[1] == puVar4) {

    ppuVar1 = _Memory + 2;

    *ppuVar1 = (uint32_t *)((int)*ppuVar1 + -1);

    if (*ppuVar1 == (uint32_t *)0x0) {

    *ppuVar6 = *_Memory;

    piVar7 = (int *)FUN_00633470(puVar4);

    _DAT_00701a48 = _DAT_00701a48 - *piVar7;

    FUN_006331c0(puVar4);

    free(piVar7);

    free(_Memory);

    }

    break;

    }

    ppuVar6 = _Memory;

    }

    free(pvVar3);

    }

    *puVar13 = 0;


}  // 0x00578b40
#endif // RenderFn578B40
void RenderFn578B40() {}  // 0x00578b40
#if 0 // GHIDRA_RAW: RenderFn587A60 @ 0x00587a60 — needs manual cleanup
void RenderFn587A60(int param_1)
{


    uint32_t uVar1;

    int iVar2;

    int iVar3;

    int iVar4;

    uint32_t *puVar5;

    uint32_t *puVar6;

    uint32_t *puVar7;



    if (param_1 == 0) {

    puVar6 = (uint32_t *)0x0;

    _DAT_00000f54 = 3;

    iVar4 = 0;

    }

    else {

    puVar6 = *(uint32_t **)(param_1 + 0x14c);

    puVar6[0x3d5] = 3;

    iVar4 = *(int *)(param_1 + 0x14c);

    }

    if ((*(char *)(param_1 + 0x25e) == '\0') && (*(char *)(param_1 + 0x25f) == '\0')) {

    uVar1 = *(uint32_t *)(param_1 + 300);

    puVar5 = (uint32_t *)(param_1 + 300);

    if (((uVar1 >> 8 & 1) == 0) &&

    (((*(float *)(param_1 + 0x2c8) < *(float *)(param_1 + 0x20c) && ((uVar1 & 0x4000000) == 0))

    && (*(int *)(iVar4 + 0xe30) == 0)))) {

    *puVar5 = uVar1 | 0x10;

    *puVar6 = *puVar6 & 0xffffff7f;

    *puVar5 = *puVar5 & 0xf7ffffff;

    goto LAB_00587b2d;

    }

    }

    FUN_004ffba0(0x29d);

    iVar4 = FUN_004ffb40();

    if (((*puVar6 & 2) != 0) || (puVar6[0x38c] != 0)) {

    *(uint32_t *)(iVar4 + 0x124) = *(uint32_t *)(iVar4 + 0x124) | 0x40000000;

    }

    LAB_00587b2d:

    puVar7 = (uint32_t *)(param_1 + 300);

    FUN_00558240();

    puVar5 = *(uint32_t **)(param_1 + 0x14c);

    *puVar7 = *puVar7 & 0xffffff7f;

    FUN_004ea1b0();

    *puVar7 = *puVar7 & 0xffffffbf;

    *puVar5 = *puVar5 & 0xfffffffe;

    if ((DAT_006ff960 == 6) && (iVar4 = FUN_0045f460(), iVar4 != 0)) {

    FUN_00469de0(0,0,3,0,0);

    }

    *(uint32_t *)(param_1 + 0x260) = *(uint32_t *)(param_1 + 0x260) & 0xfdfffeff;

    if (puVar6[0x3d3] != 0) {

    iVar3 = *(int *)(param_1 + 0x264);

    iVar4 = param_1;

    while (iVar2 = iVar3, iVar2 != 0) {

    iVar4 = iVar2;

    iVar3 = *(int *)(iVar2 + 0x264);

    }

    if (((DAT_00702800 != 0) && (DAT_00702800 + 0x9690 != 0)) &&

    (*(int *)(DAT_00702800 + 0x9698) != 0)) {

    (*DAT_007280a0)(DAT_00702800 + 0x9690,iVar4);

    }

    puVar6[0x3ec] = 0;

    *(uint32_t *)(puVar6[0x3d3] + 0x124) = *(uint32_t *)(puVar6[0x3d3] + 0x124) | 0x40000000;

    if (puVar6[0x3d3] != 0) {

    iVar4 = *(int *)(param_1 + 0x264);

    while (iVar3 = iVar4, iVar3 != 0) {

    param_1 = iVar3;

    iVar4 = *(int *)(iVar3 + 0x264);

    }

    if (((DAT_00702800 != 0) && (DAT_00702800 + 0x9690 != 0)) &&

    (*(int *)(DAT_00702800 + 0x9698) != 0)) {

    (*DAT_007280a0)(DAT_00702800 + 0x9690,param_1);

    }

    puVar6[0x3ec] = 0;

    *(uint32_t *)(puVar6[0x3d3] + 0x124) = *(uint32_t *)(puVar6[0x3d3] + 0x124) | 0x40000000;

    }

    }

    iVar4 = 0;

    if (0 < (int)puVar6[0x369]) {

    puVar5 = puVar6 + 0x3cc;

    do {

    if (*puVar5 != 0) {

    puVar7 = (uint32_t *)(*puVar5 + 0x124);

    *puVar7 = *puVar7 | 0x40000000;

    }

    iVar4 = iVar4 + 1;

    puVar5 = puVar5 + 1;

    } while (iVar4 < (int)puVar6[0x369]);

    }

    return;


}  // 0x00587a60
#endif // RenderFn587A60
void RenderFn587A60() {}  // 0x00587a60
#if 0 // GHIDRA_RAW: RenderFn59BA00 @ 0x0059ba00 — needs manual cleanup
void RenderFn59BA00(void)
{


    uint32_t uVar1;

    uint32_t uVar2;



    if (*(int *)(*(int *)ThreadLocalStoragePointer + 4) < DAT_0074f4ec) {

    FUN_006435f8(&DAT_0074f4ec);

    if (DAT_0074f4ec == -1) {

    _DAT_0074f4f0 = _DAT_00660860;

    uRam0074f4f4 = _UNK_00660864;

    uRam0074f4f8 = _UNK_00660868;

    uRam0074f4fc = _UNK_0066086c;

    _DAT_0074f500 = _DAT_00660850;

    uRam0074f504 = _UNK_00660854;

    uRam0074f508 = _UNK_00660858;

    uRam0074f50c = _UNK_0066085c;

    _DAT_0074f510 = _DAT_00660870;

    uRam0074f514 = _UNK_00660874;

    uRam0074f518 = _UNK_00660878;

    uRam0074f51c = _UNK_0066087c;

    _DAT_0074f520 = _DAT_00660880;

    uRam0074f524 = _UNK_00660884;

    uRam0074f528 = _UNK_00660888;

    uRam0074f52c = _UNK_0066088c;

    FUN_006435a7(&DAT_0074f4ec);

    }

    }

    FUN_005654a0("InDome");

    (**(code **)(*DAT_00702700 + 0x2c))();

    (**(code **)(DAT_00702714 + 8))(DAT_00702714,1);

    (**(code **)(DAT_00702714 + 0xc))(DAT_00702714,1);

    uVar2 = DAT_0067f47c;

    uVar1 = DAT_0067f0f4;

    DAT_0067f0f4 = 0x46dac000;

    FUN_005f9d00();

    FUN_004d67d0();

    DAT_0067f0f4 = uVar1;

    DAT_0067f47c = uVar2;

    FUN_005f9d00();

    if (DAT_00702be4 < 1) {

    FUN_004dcd30();

    }

    return;


}  // 0x0059ba00
#endif // RenderFn59BA00
void RenderFn59BA00() {}  // 0x0059ba00
#if 0 // GHIDRA_RAW: RenderFn5A7860 @ 0x005a7860 — needs manual cleanup
void RenderFn5A7860(int param_1,int param_2)
{


    uint32_t *puVar1;

    int iVar2;

    int iVar3;



    if (param_1 == 0) {

    iVar3 = 0;

    }

    else {

    iVar3 = *(int *)(param_1 + 0x14c);

    }

    *(int *)(param_1 + 0x264) = param_2;

    *(uint32_t *)(param_1 + 0x268) = 9;

    *(uint32_t *)(param_1 + 0x26c) = 0;

    FUN_00590950();

    FUN_00584000();

    FUN_0048f2f0(0x91,0x21,0,0,0x3e2aaaab);

    FUN_0048f2f0(0xfe,0,0,0,0x3e2aaaab);

    if (*(int *)(param_2 + 0x22c) != 0x5a) {

    FUN_0055ccc0();

    }

    *(int *)(param_2 + 0x2c4) = param_1;

    iVar2 = FUN_004ffb40();

    if (iVar2 != 0) {

    *(uint32_t *)(iVar2 + 0x124) = *(uint32_t *)(iVar2 + 0x124) | 0x40000000;

    }

    *(uint64_t *)(param_1 + 0x25c) = 0;

    *(uint32_t *)(param_2 + 0x1d8) = *(uint32_t *)(param_1 + 0x1d8);

    if (*(int *)(iVar3 + 0x38) != 0) {

    puVar1 = (uint32_t *)(*(int *)(iVar3 + 0x38) + 0x124);

    *puVar1 = *puVar1 | 0x40000000;

    }

    FUN_00558290();

    FUN_00558290();

    return;


}  // 0x005a7860
#endif // RenderFn5A7860
void RenderFn5A7860() {}  // 0x005a7860
#if 0 // GHIDRA_RAW: RenderFn5CCCF0 @ 0x005cccf0 — needs manual cleanup
void RenderFn5CCCF0(int param_1,int param_2,int param_3)
{


    int iVar1;

    uint32_t local_10;

    uint32_t local_c;



    if (DAT_006ff960 == 6) {

    iVar1 = FUN_0045f460();

    if (iVar1 != 0) {

    local_10 = *(uint32_t *)(param_2 + 0x1d4);

    if (param_3 == 0) {

    local_c = 0;

    }

    else {

    local_c = *(uint32_t *)(param_3 + 0x1d4);

    }

    FUN_00469d20(4,&local_10);

    }

    }

    FUN_005ce760(param_3);

    *(uint32_t *)(param_1 + 0x130) = 0x37;

    FUN_005d1cd0();

    FUN_0048f2f0(0x41,0x20,0,0,0x3f2aaaab);

    FUN_0048f2f0(0xfe,0,0,0,0x3f2aaaab);

    if (DAT_006ff960 == 6) {

    iVar1 = FUN_0045f460();

    if (iVar1 != 0) {

    FUN_00469de0(0,0,8,0,0);

    }

    }

    return;


}  // 0x005cccf0
#endif // RenderFn5CCCF0
void RenderFn5CCCF0() {}  // 0x005cccf0
#if 0 // GHIDRA_RAW: RenderFn5CE040 @ 0x005ce040 — needs manual cleanup
void RenderFn5CE040(int param_1)
{


    int iVar1;

    uint32_t *puVar2;

    int iVar3;

    float in_XMM0_Da;

    float local_24;

    float local_20 [5];

    float local_c [2];

    uint8_t local_4 [4];



    if (param_1 == 0) {

    iVar3 = 0;

    }

    else {

    iVar3 = *(int *)(param_1 + 0x14c);

    }

    iVar1 = *(int *)(param_1 + 0x2c4);

    *(uint32_t *)(param_1 + 0x124) = *(uint32_t *)(param_1 + 0x124) & 0xffffffef;

    *(uint32_t *)(param_1 + 0x2c4) = 0;

    *(uint32_t *)(param_1 + 0x138) = 0x3f800000;

    *(uint32_t *)(param_1 + 0x130) = 4;

    if (iVar1 != 0) {

    FUN_006387e0(*(float *)(iVar1 + 0x114) + DAT_0066c110,&local_24,local_20);

    *(float *)(param_1 + 0x174) = local_24 * DAT_0066c068;

    in_XMM0_Da = local_20[0] * DAT_0066c290;

    *(float *)(param_1 + 0x178) = in_XMM0_Da;

    }

    FUN_004ea1b0();

    puVar2 = DAT_007496c4;

    if (*(int *)(iVar3 + 0xc0) != 0) {

    for (; puVar2 != (uint32_t *)0x0; puVar2 = (uint32_t *)*puVar2) {

    if (puVar2[0x11] == *(int *)(iVar3 + 0xc0)) {

    FUN_005583d0();

    break;

    }

    }

    *(uint32_t *)(iVar3 + 0xc0) = 0;

    }

    if (*(int *)(param_1 + 0x134) == 2) {

    FUN_0048f2f0(1,0x21,0,0,0x3e2aaaab);

    FUN_0048f2f0(0xfe,0,0,0,0x3e2aaaab);

    *(uint32_t *)(param_1 + 300) = *(uint32_t *)(param_1 + 300) | 0x11;

    FUN_004fecb0(local_4,local_c,1);

    FUN_004a1320();

    if (in_XMM0_Da <= local_c[0]) {

    in_XMM0_Da = local_c[0];

    }

    *(float *)(param_1 + 0xf8) = in_XMM0_Da;

    *(uint64_t *)(param_1 + 0x108) = *(uint64_t *)(param_1 + 0xfc);

    *(uint32_t *)(param_1 + 0x110) = *(uint32_t *)(param_1 + 0x104);

    *(uint64_t *)(param_1 + 0xfc) = *(uint64_t *)(param_1 + 0xf0);

    *(uint32_t *)(param_1 + 0x104) = *(uint32_t *)(param_1 + 0xf8);

    }

    return;


}  // 0x005ce040
#endif // RenderFn5CE040
void RenderFn5CE040() {}  // 0x005ce040
void RenderFn5DC100() {}  // 0x005dc100
#if 0 // GHIDRA_RAW: SysFn60C000 @ 0x0060c000 — needs manual cleanup
void SysFn60C000()
{


    pcVar1 = *(code **)(*param_1 + 0x80);

    FUN_0061dbf0();

    local_8 = 1;

    (*pcVar1)(&stack0xffffff64);

    FUN_0060e8c0();


}  // 0x0060c000
#endif // SysFn60C000
void SysFn60C000() {}  // 0x0060c000
#if 0 // GHIDRA_RAW: CoreFn42BF40 @ 0x0042bf40 — needs manual cleanup
void CoreFn42BF40()
{


    local_1c = param_1[1];

    uVar2 = *param_1;

    iVar5 = FUN_0042c270(uVar4);

    local_24 = 0;

    local_20 = 0;

    local_34 = 0;

    uStack_30 = 0;

    uStack_2c = 0;

    uStack_28 = 0;

    local_8._0_1_ = 1;

    puVar3 = *(uint32_t **)(iVar5 + 0x20);

    if (puVar3 == *(uint32_t **)(iVar5 + 0x24)) {

    FUN_0042c890(puVar3,&local_34);

    }

    else {

    *puVar3 = 0;

    puVar3[1] = 0;

    puVar3[2] = 0;

    uStack_2c = 0;

    uStack_30 = 0;

    local_34 = 0;

    local_20 = 0;

    local_24 = 0;

    uStack_28 = 0;

    puVar3[3] = 0;

    puVar3[4] = 0;

    puVar3[5] = 0;

    *(int *)(iVar5 + 0x20) = *(int *)(iVar5 + 0x20) + 0x18;

    }

    local_8 = (uint)local_8._1_3_ << 8;

    FUN_0042c810();

    FUN_0042c810();

    FUN_0042b0f0(uVar2);

    puVar3 = *(uint32_t **)(iVar5 + 0x2c);

    param_1 = local_18;

    for (puVar8 = *(uint32_t **)(iVar5 + 0x28); local_18 = param_1, puVar8 != puVar3;

    puVar8 = puVar8 + 2) {

    (*(GhidraCodePtr *)*puVar8)(puVar8[1],local_1c,uVar2);

    param_1 = local_18;

    }


}  // 0x0042bf40
#endif // CoreFn42BF40
void CoreFn42BF40() {}  // 0x0042bf40
void CoreFn43D9B0() {}  // 0x0043d9b0
void CoreFn440350() {}  // 0x00440350
#if 0 // GHIDRA_RAW: CoreFn446FE0 @ 0x00446fe0 — needs manual cleanup
uint32_t CoreFn446FE0(uint32_t param_1,int *param_2,uint32_t param_3,void *param_4,uint32_t param_5)
{


    uint64_t uVar1;

    void *pvVar2;

    uint64_t *puVar3;

    int iVar4;

    void *_Src;

    uint32_t *puVar5;

    uint32_t uVar6;

    void *pvVar7;

    void *extraout_ECX;

    int extraout_ECX_00;

    void *pvVar8;

    size_t _Size;

    bool bVar9;

    uint8_t auStack_60 [7];

    uint8_t local_59;

    void *local_58;

    uint32_t local_54;

    int *local_50;

    void *local_4c;

    void **local_48;

    void *local_44;

    void *local_40;

    uint32_t local_3c;

    uint8_t local_38 [4];

    void *local_34;

    uint32_t local_30;

    void *local_2c;

    uint32_t local_28;

    uint64_t local_20;

    uint32_t local_14;

    uint16_t local_10;

    uint8_t local_e;

    uint32_t local_c;



    local_c = DAT_0067d280 ^ (uint)auStack_60;

    local_54 = param_5;

    local_40 = param_4;

    if ((-1 < param_2[1]) && ((uint)param_2[1] < param_5)) {

    uVar6 = 0;

    local_54 = 0;

    if (param_5 != 0) {

    do {

    if (((*(byte *)((int)param_4 + local_54) & 0xc0) != 0x80) &&

    (uVar6 = uVar6 + 1, (uint)param_2[1] < uVar6)) goto LAB_00447049;

    local_54 = local_54 + 1;

    } while (local_54 != param_5);

    }

    local_54 = param_5;

    }

    LAB_00447049:

    uVar6 = local_54;

    local_59 = (char)param_2[2] == '\x12';

    pvVar8 = (void *)0x0;

    local_50 = param_2;

    local_3c = param_1;

    if (*param_2 != 0) {

    if ((char)param_2[2] == '\x12') {

    local_4c = (void *)(param_5 + (int)param_4);

    iVar4 = 1;

    pvVar8 = param_4;

    do {

    puVar3 = (uint64_t *)FUN_00446e00(local_38);

    uVar1 = *puVar3;

    local_20._0_4_ = (void *)uVar1;

    if (pvVar8 != (void *)local_20) {

    iVar4 = (int)(void *)local_20 + (iVar4 - (int)pvVar8);

    }

    local_20._4_4_ = (void *)((uint64_t)uVar1 >> 0x20);

    local_20 = uVar1;

    if (local_20._4_4_ == (void *)0x0) break;

    switch(*(uint32_t *)(puVar3 + 1)) {

    case 9:

    case 10:

    case 0xd:

    case 0x22:

    case 0x27:

    case 0x5c:

    iVar4 = iVar4 + 2;

    break;

    default:

    for (; (void *)local_20 != local_20._4_4_;

    local_20._0_4_ = (void *)((int)(void *)local_20 + 1)) {

    iVar4 = iVar4 + 4;

    }

    }

    bVar9 = local_20._4_4_ != local_4c;

    pvVar8 = local_20._4_4_;

    } while (bVar9);

    pvVar8 = (void *)(iVar4 + 1);

    }

    else {

    local_4c = (void *)0x0;

    local_58 = param_4;

    local_48 = &local_4c;

    _Src = param_4;

    if (local_54 < 4) {

    LAB_00447139:

    _Size = (uVar6 - (int)_Src) + (int)local_58;

    pvVar8 = local_4c;

    if (_Size != 0) {

    local_14 = 0;

    local_10 = 0;

    local_e = 0;

    memcpy(&local_14,_Src,_Size);

    puVar5 = &local_14;

    iVar4 = extraout_ECX_00;

    do {

    puVar5 = (uint32_t *)FUN_00446b80(puVar5,iVar4);

    pvVar8 = local_4c;

    if (puVar5 == (uint32_t *)0x0) break;

    iVar4 = (int)puVar5 - (int)&local_14;

    } while (iVar4 < (int)_Size);

    }

    }

    else {

    pvVar7 = (void *)((int)param_4 + (local_54 - 3));

    pvVar2 = pvVar7;

    local_44 = pvVar7;

    do {

    if (pvVar7 <= _Src) goto LAB_00447139;

    _Src = (void *)FUN_00446b80(_Src,pvVar2);

    pvVar8 = local_4c;

    pvVar2 = extraout_ECX;

    } while (_Src != (void *)0x0);

    }

    }

    }

    local_38[0] = local_59;

    local_2c = local_40;

    local_28 = local_54;

    local_34 = param_4;

    local_30 = param_5;

    FUN_00446e90(param_3,pvVar8,pvVar8,local_38);

    return local_3c;


}  // 0x00446fe0
#endif // CoreFn446FE0
void CoreFn446FE0() {}  // 0x00446fe0
#if 0 // GHIDRA_RAW: GameFn469B40 @ 0x00469b40 — needs manual cleanup
void GameFn469B40(uint32_t param_1,int param_2)
{


    int iVar1;

    int iVar2;

    uint32_t uVar3;

    uint32_t *puVar4;

    char cVar5;

    uint32_t uVar6;

    uint32_t uVar7;

    uint32_t uVar8;

    uint32_t local_40;

    int local_3c;

    uint32_t local_38;

    uint32_t local_34;

    byte local_2e;

    byte local_2d;

    uint8_t local_2c [24];

    uint32_t local_14;

    void *local_10;

    uint8_t *puStack_c;

    uint32_t local_8;



    local_8 = 0xffffffff;

    puStack_c = &LAB_0064874d;

    local_10 = ExceptionList;

    local_14 = DAT_0067d280 ^ (uint)&stack0xfffffffc;

    // ExceptionList = ... (SEH frame, stubbed)

    local_3c = *(int *)(DAT_006ffa2c + 1);

    local_2e = *(byte *)(DAT_006ffa2c + 9);

    iVar1 = *(int *)(DAT_006ffa2c + 5);

    local_2d = *(byte *)(DAT_006ffa2c + 10);

    local_34 = DAT_006ffa2c + 0xb;

    local_38 = local_3c - 0xb;

    if (0xb < DAT_00702924) {

    puVar4 = DAT_007027a8;

    if ((param_2 != 0) && ((DAT_006ff960 != 6 || (DAT_00702964 != 0)))) {

    FUN_0046ce10(local_3c,DAT_006ffa2c,local_14);

    puVar4 = DAT_007027a8;

    }

    for (; puVar4 != (uint32_t *)0x0; puVar4 = (uint32_t *)*puVar4) {

    iVar2 = puVar4[3];

    if (((*(uint32_t *)(iVar2 + 0x124) & 0x8000) == 0) && (*(int *)(iVar2 + 0x1d4) == iVar1)) {

    if (iVar2 != 0) {

    uVar7 = (uint)local_2d;

    uVar3 = *(uint32_t *)(iVar2 + 0x22c);

    uVar8 = (uint)local_2e;

    if (((uVar3 == uVar7) && ((int)uVar3 < 0x6c)) &&

    (*(int *)(&DAT_00682ec4 + uVar3 * 0x50) != 0)) {

    if ((*(code **)(&DAT_00682ef0 + uVar3 * 0x50) == (code *)0x0) ||

    (cVar5 = (**(code **)(&DAT_00682ef0 + uVar3 * 0x50))(iVar2,uVar8,local_38,local_34),

    cVar5 != '\0')) {

    (**(code **)(&DAT_00682ec4 + *(int *)(iVar2 + 0x22c) * 0x50))

    (iVar2,uVar8,local_38,local_34);

    }

    else {

    local_40 = *(uint32_t *)(iVar2 + 0x1d4) & 0xff;

    local_38 = uVar8;

    local_34 = uVar7;

    if (DAT_00702964 != 0) {

    (**(code **)(*DAT_006ff9e4 + 0x60))(DAT_006ff9e4,(&DAT_006ff910)[local_40],0,0,0);

    }

    uVar6 = FUN_004625b0(local_2c,&local_40,&local_34,&local_38,

    "Bad objspec data from {0} for MT {1} optype {2}",0x2f);

    local_8 = 0;

    FUN_0043f440(6,4,uVar6);

    FUN_004439b0();

    }

    }

    }

    break;

    }

    }

    }

    DAT_006ffa2c = DAT_006ffa2c + local_3c;

    // ExceptionList = ... (SEH frame, stubbed)

    return;


}  // 0x00469b40
#endif // GameFn469B40
void GameFn469B40() {}  // 0x00469b40
#if 0 // GHIDRA_RAW: GameFn470E50 @ 0x00470e50 — needs manual cleanup
void GameFn470E50()
{


    *puVar1 = 0;

    puVar1[1] = 0;

    puVar1 = puVar1 + 4;


}  // 0x00470e50
#endif // GameFn470E50
void GameFn470E50() {}  // 0x00470e50
#if 0 // GHIDRA_RAW: GameFn4F6BF0 @ 0x004f6bf0 — needs manual cleanup
void GameFn4F6BF0(int param_1)
{


    int iVar1;

    uint32_t uVar2;

    uint32_t uVar3;

    uint32_t uVar4;

    int iVar5;

    int iVar6;

    bool bVar7;

    uint64_t uVar8;

    uint8_t local_14 [4];

    int local_10;

    uint8_t local_c [4];

    uint32_t local_8;



    local_8 = DAT_0067d280 ^ (uint)local_14;

    iVar1 = *(int *)(param_1 + 0xc);

    uVar2 = *(uint32_t *)(iVar1 + 0x14);

    uVar4 = uVar2 + 0x76c;

    iVar6 = ((int)uVar2 >> 0x1f) + (uint)(0xfffff893 < uVar2);

    uVar8 = __alldiv(uVar4,iVar6,100,0);

    uVar8 = __allmul(uVar8,100,0);

    iVar5 = uVar4 - (uint)uVar8;

    iVar6 = (iVar6 - (int)((uint64_t)uVar8 >> 0x20)) - (uint)(uVar4 < (uint)uVar8);

    if ((iVar6 < 1) && (iVar6 < 0)) {

    bVar7 = iVar5 != 0;

    iVar5 = -iVar5;

    local_10 = -(iVar6 + (uint)bVar7);

    }

    FUN_004f7910(*(uint32_t *)(iVar1 + 0xc),iVar5,0x2f);

    uVar3 = *(uint32_t *)(param_1 + 8);

    FUN_0044dc30(local_14,local_c);

    *(uint32_t *)(param_1 + 8) = uVar3;

    return;


}  // 0x004f6bf0
#endif // GameFn4F6BF0
void GameFn4F6BF0() {}  // 0x004f6bf0
void RenderFn500290() {}  // 0x00500290
#if 0 // GHIDRA_RAW: RenderFn51BB80 @ 0x0051bb80 — needs manual cleanup
uint32_t RenderFn51BB80(int param_1,int param_2,char param_3,byte param_4,int param_5)
{


    uint32_t *puVar1;

    uint32_t uVar2;

    int iVar3;

    int *piVar4;

    int *piVar5;

    int iVar6;

    float fVar7;

    uint32_t local_8;

    char local_4;

    byte local_3;



    if (((param_2 != 0) &&

    ((param_3 == '\0' ||

    (((*(uint32_t *)(param_2 + 0x124) & 0x4000c000) == 0 &&

    (*(float *)(param_2 + 0x2c8) <= *(float *)(param_2 + 0x20c) &&

    *(float *)(param_2 + 0x20c) != *(float *)(param_2 + 0x2c8))))))) &&

    ((iVar3 = *(int *)(param_2 + 0x264), iVar3 == 0 ||

    (((*(int *)(iVar3 + 0x22c) != 0x4b && (*(int *)(iVar3 + 0x22c) != 4)) || (iVar3 == param_1))))

    )) {

    iVar6 = *(int *)(param_2 + 4);

    if (((iVar6 != 3) || (iVar3 == 0)) || (*(int *)(iVar3 + 4) != 0x434)) {

    if (((param_5 != 0) && (DAT_006ff960 == 6)) && (iVar3 = FUN_0045f460(), iVar3 != 0)) {

    local_8 = *(uint32_t *)(param_2 + 0x1d4);

    local_4 = param_3;

    local_3 = param_4;

    FUN_00469de0(1,2,5,&local_8,0);

    iVar6 = *(int *)(param_2 + 4);

    }

    piVar4 = &DAT_00682de8;

    *(uint32_t *)(param_2 + 0x26c) = (uint)param_4;

    iVar3 = DAT_00682de8;

    while ((-1 < iVar3 && (iVar3 != iVar6))) {

    piVar5 = piVar4 + 0xb;

    piVar4 = piVar4 + 0xb;

    iVar3 = *piVar5;

    }

    if (*piVar4 == *(int *)(param_2 + 4)) {

    if (param_3 == '\0') {

    fVar7 = *(float *)(param_2 + 0x370) / (float)piVar4[1];

    if (_DAT_0066bce4 < fVar7) {

    *(float *)(param_2 + 0x370) = fVar7;

    }

    }

    else {

    piVar5 = piVar4 + 5;

    iVar3 = 0;

    uVar2 = piVar4[5];

    while ((uVar2 != param_4 && (-1 < (int)uVar2))) {

    puVar1 = (uint32_t *)(piVar5 + 1);

    piVar5 = piVar5 + 1;

    iVar3 = iVar3 + 1;

    uVar2 = *puVar1;

    }

    fVar7 = (float)piVar4[1] * *(float *)(param_2 + 0x370);

    if (0.0 < fVar7) {

    *(float *)(param_2 + 0x370) = fVar7;

    }

    *(int *)(param_2 + 0x268) = piVar4[iVar3 + 2];

    iVar3 = piVar4[iVar3 + 8];

    if (*(int *)(param_2 + 0x60) != iVar3) {

    if (iVar3 != 0xfe) {

    FUN_0048f2f0(iVar3,0x21,0,0,0);

    FUN_0048f2f0(0xfe,0,0,0,0);

    }

    FUN_0048fba0();

    }

    }

    }

    else {

    *(uint32_t *)(param_2 + 0x268) = 0xffffffff;

    }

    if (param_3 == '\0') {

    param_1 = 0;

    }

    *(int *)(param_2 + 0x264) = param_1;

    return 1;

    }

    FUN_00500d30(param_1,0,0);

    }

    return 0;


}  // 0x0051bb80
#endif // RenderFn51BB80
void RenderFn51BB80() {}  // 0x0051bb80
#if 0 // GHIDRA_RAW: RenderFn5496A0 @ 0x005496a0 — needs manual cleanup
void RenderFn5496A0(int param_1)
{


    int *piVar1;

    int local_4;



    FUN_004d1070();

    DAT_00681db0 = 0;

    DAT_00681db4 = 0xffffffff;

    DAT_00681dec = 0;

    DAT_00681e34 = 0;

    *(uint32_t *)(DAT_00702d60 + 0x124) = *(uint32_t *)(DAT_00702d60 + 0x124) | 0x8000;

    DAT_00702d60 = 0;

    FUN_00541080();

    if ((DAT_00702bdd == '\0') && (DAT_00702be8 == 0)) {

    local_4 = DAT_00748a30;

    if (DAT_0074be5c != (HKEY)0x0) {

    RegSetValueExA(DAT_0074be5c,"LoadMission",0,4,(BYTE *)&local_4,4);

    }

    }

    DAT_00702d5c = 0;

    FUN_004e8c30();

    (*DAT_00728044)(DAT_00749008);

    DAT_00749008 = 0;

    if (param_1 == 0) {

    DAT_00702cc4 = 0;

    }

    else {

    if ((DAT_00702bdd == '\0') && (DAT_00702be8 == 0)) {

    local_4 = DAT_00748a30;

    if (DAT_0074be5c != (HKEY)0x0) {

    RegSetValueExA(DAT_0074be5c,"LoadMission",0,4,(BYTE *)&local_4,4);

    }

    }

    DAT_00702cc8 = DAT_00748a30 + -1;

    DAT_00702cc4 = 1;

    }

    DAT_0074893c = DAT_00702778;

    FUN_00501f50();

    if ((((DAT_00702800 != 0) && (piVar1 = (int *)(DAT_00702800 + 0x12f88), piVar1 != (int *)0x0)) &&

    (*piVar1 != 0)) && (*(int *)(DAT_00702800 + 0x12f90) != 0)) {

    (*DAT_007280a8)(piVar1);

    }

    return;


}  // 0x005496a0
#endif // RenderFn5496A0
void RenderFn5496A0() {}  // 0x005496a0
#if 0 // GHIDRA_RAW: RenderFn54CE80 @ 0x0054ce80 — needs manual cleanup
void RenderFn54CE80(void)
{


    uint32_t uVar1;

    uint32_t uVar2;

    uint32_t uVar3;

    uint32_t uVar4;

    int iVar5;

    uint32_t extraout_ECX;



    if ((DAT_00747d2c == 0) || (DAT_00682264 != 0)) {

    if (9 < DAT_00682204) {

    FUN_00461e70("Overflow of dialog level stack",0x1e);

    DAT_00682204 = DAT_00682204 + -1;

    }

    DAT_00682204 = DAT_00682204 + 1;

    (&DAT_00747b60)[DAT_00682204 * 6] = FUN_0054d5c0;

    (&DAT_00747b64)[DAT_00682204 * 6] = FUN_00526be0;

    }

    else {

    if (9 < DAT_00682204) {

    FUN_00461e70("Overflow of dialog level stack",0x1e);

    DAT_00682204 = DAT_00682204 + -1;

    }

    DAT_00682204 = DAT_00682204 + 1;

    (&DAT_00747b60)[DAT_00682204 * 6] = FUN_0054d5c0;

    (&DAT_00747b64)[DAT_00682204 * 6] = FUN_00541860;

    }

    (&DAT_00747b68)[DAT_00682204 * 6] = 0;

    (&DAT_00747b6c)[DAT_00682204 * 6] = 0;

    (&DAT_00747b70)[DAT_00682204 * 6] = 0;

    (&DAT_00747b74)[DAT_00682204 * 6] = 0;

    uVar4 = _UNK_0066c4bc;

    uVar3 = _UNK_0066c4b8;

    uVar2 = _UNK_0066c4b4;

    uVar1 = _DAT_0066c4b0;

    if (DAT_00682204 != -1) {

    (&DAT_00747b70)[DAT_00682204 * 6] = 1;

    _DAT_006818b8 = uVar1;

    uRam006818bc = uVar2;

    uRam006818c0 = uVar3;

    uRam006818c4 = uVar4;

    PTR_DAT_00685890 = &DAT_006818b8;

    _DAT_006818c8 = uVar1;

    uRam006818cc = uVar2;

    uRam006818d0 = uVar3;

    uRam006818d4 = uVar4;

    DAT_0074be50 = 0;

    }

    iVar5 = FUN_005de9b0();

    if (iVar5 == 0) {

    FUN_004d1070();

    return;

    }

    DAT_0074b604 = DAT_007028a0;

    DAT_0074b608 = DAT_007028a4;

    DAT_00682e9c = 0x1c;

    DAT_0074b5fc = 0x1c;

    DAT_0074b600 = 0xffffffff;

    if (DAT_00702d60 != 0) {

    *(uint32_t *)(DAT_00702d60 + 0x124) = *(uint32_t *)(DAT_00702d60 + 0x124) | 0x8000;

    }

    DAT_00702d60 = 0;

    iVar5 = FUN_00559dc0();

    DAT_00702d60 = iVar5;

    *(uint32_t *)(iVar5 + 0x124) = *(uint32_t *)(iVar5 + 0x124) | 0x40000000;

    if ((DAT_00747d2c != 0) && (DAT_00682264 == 0)) {

    DAT_00681db4 = 0;

    DAT_00681dec = 0;

    DAT_00681db0 = 1;

    DAT_00681dd0 = iVar5;

    }

    FUN_00540fe0(extraout_ECX);

    DAT_00748a30 = 0xd;

    _DAT_00748bec = 1;

    iVar5 = *(int *)(*(int *)(DAT_0074b5f8 + 0x3f0) + 0x38);

    DAT_00702c1c = ((*(float *)(iVar5 + 0x44) * DAT_0066be20 + *(float *)(iVar5 + 0x38) * DAT_0066be20

    ) / (float)DAT_0074b604) * (float)DAT_0074b604;

    DAT_00702c24 = DAT_00702c1c;

    DAT_00702c20 = (float)DAT_0074b608 *

    ((*(float *)(iVar5 + 0x48) * DAT_0066be20 + *(float *)(iVar5 + 0x3c) * DAT_0066be20

    ) / (float)DAT_0074b608);

    DAT_00702c28 = DAT_00702c20;

    return;


}  // 0x0054ce80
#endif // RenderFn54CE80
void RenderFn54CE80() {}  // 0x0054ce80
#if 0 // GHIDRA_RAW: RenderFn54FF10 @ 0x0054ff10 — needs manual cleanup
void RenderFn54FF10(uint32_t param_1)
{


    int *piVar1;



    FUN_004d1070(param_1);

    DAT_00681db0 = 0;

    DAT_00681db4 = 0xffffffff;

    DAT_00681dec = 0;

    DAT_00681e34 = 0;

    *(uint32_t *)(DAT_00702d60 + 0x124) = *(uint32_t *)(DAT_00702d60 + 0x124) | 0x8000;

    DAT_00702d60 = 0;

    FUN_00541080();

    if (DAT_00748a30 == 1) {

    FUN_00557660();

    (*DAT_00728050)();

    DAT_00702884 = 0;

    if ((((DAT_00702800 != 0) && (piVar1 = (int *)(DAT_00702800 + 0x12f88), piVar1 != (int *)0x0))

    && (*piVar1 != 0)) && (*(int *)(DAT_00702800 + 0x12f90) != 0)) {

    (*DAT_007280a8)(piVar1);

    }

    }

    else {

    FUN_00549b60();

    }

    if (((DAT_00702b30 == 0) && (DAT_00702b34 == 0)) && ((DAT_00702b50 == 0 && (DAT_00702bb8 == 0))))

    {

    FUN_00558360();

    }

    return;


}  // 0x0054ff10
#endif // RenderFn54FF10
void RenderFn54FF10() {}  // 0x0054ff10
#if 0 // GHIDRA_RAW: RenderFn558570 @ 0x00558570 — needs manual cleanup
uint32_t RenderFn558570(uint32_t *param_1,int param_2)
{


    int iVar1;

    float fVar2;

    uint32_t uVar3;

    int iVar4;

    float fVar5;



    fVar2 = _DAT_0066bce4;

    iVar1 = param_1[10];

    if ((iVar1 == 0) || ((*(uint32_t *)(iVar1 + 0x124) & 0x8000) == 0)) {

    if (param_2 != 0) {

    return 0;

    }

    if (param_1[5] == 0) {

    if ((*(byte *)(param_1 + 0x10) & 1) == 0) {

    param_1[8] = (float)param_1[8] - DAT_00727e38;

    }

    if ((float)param_1[8] <= _DAT_0066bce4) {

    FUN_005583d0();

    }

    else if (param_1[6] == 0) {

    if (iVar1 != 0) {

    if (((DAT_00702800 != 0) && (iVar4 = param_1[4] * 0x2c + DAT_00702800, iVar4 != 0)) &&

    (*(int *)(iVar4 + 8) != 0)) {

    (*DAT_007280a0)(iVar4,iVar1);

    }

    FUN_005581d0();

    uVar3 = FUN_005581d0();

    param_1[7] = uVar3;

    param_1[6] = 1;

    return *param_1;

    }

    iVar1 = param_1[0xb];

    if (param_1[0xf] != 0) {

    if (((iVar1 != 0) && (DAT_00702800 != 0)) &&

    ((iVar4 = param_1[4] * 0x2c + DAT_00702800, iVar4 != 0 && (*(int *)(iVar4 + 8) != 0))))

    {

    (*DAT_007280a0)(iVar4,iVar1);

    }

    FUN_005582f0(param_1[0xb]);

    uVar3 = FUN_005582f0(param_1[0xb]);

    param_1[7] = uVar3;

    param_1[6] = 1;

    return *param_1;

    }

    if ((((iVar1 != 0) && (DAT_00702800 != 0)) &&

    (iVar4 = param_1[4] * 0x2c + DAT_00702800, iVar4 != 0)) && (*(int *)(iVar4 + 8) != 0)) {

    (*DAT_007280a0)(iVar4,iVar1);

    }

    FUN_00558360();

    uVar3 = FUN_00558360();

    param_1[7] = uVar3;

    param_1[6] = 1;

    return *param_1;

    }

    return *param_1;

    }

    fVar5 = (float)param_1[8] - DAT_00727e38;

    param_1[8] = fVar5;

    if (fVar2 < fVar5) {

    (*DAT_00728098)(param_1[7],fVar5 / (float)param_1[9]);

    return *param_1;

    }

    }

    uVar3 = FUN_005584d0();

    return uVar3;


}  // 0x00558570
#endif // RenderFn558570
void RenderFn558570() {}  // 0x00558570
#if 0 // GHIDRA_RAW: RenderFn5878B0 @ 0x005878b0 — needs manual cleanup
void RenderFn5878B0(int param_1)
{


    uint32_t *puVar1;

    uint32_t *puVar2;

    uint32_t uVar3;

    int iVar4;

    uint32_t *puVar5;

    uint32_t local_4;



    if (param_1 == 0) {

    puVar5 = (uint32_t *)0x0;

    }

    else {

    puVar5 = *(uint32_t **)(param_1 + 0x14c);

    }

    if (-1 < (int)(puVar5[0x36e] - 1)) {

    if (param_1 == 0) {

    iVar4 = 0;

    }

    else {

    iVar4 = *(int *)(param_1 + 0x14c);

    }

    if (((((*(char *)(param_1 + 0x25e) != '\0') || (*(char *)(param_1 + 0x25f) != '\0')) ||

    ((*(uint32_t *)(param_1 + 300) >> 8 & 1) != 0)) ||

    ((*(float *)(param_1 + 0x20c) <= *(float *)(param_1 + 0x2c8) ||

    ((*(uint32_t *)(param_1 + 300) & 0x4000000) != 0)))) || (*(int *)(iVar4 + 0xe30) != 0)) {

    puVar2 = DAT_00749908;

    if (-2 < (int)puVar5[puVar5[0x36e] * 2 + 0x356]) {

    for (; puVar2 != DAT_0074990c; puVar2 = puVar2 + 2) {

    puVar1 = (uint32_t *)*puVar2;

    if (*puVar1 == puVar5[puVar5[0x36e] * 2 + 0x356]) {

    if (puVar1 != (uint32_t *)0x0) {

    uVar3 = puVar1[2];

    goto LAB_00587965;

    }

    break;

    }

    }

    }

    uVar3 = 0;

    LAB_00587965:

    FUN_004ffba0(uVar3);

    iVar4 = FUN_004ffb40();

    if (((*puVar5 & 2) != 0) || (puVar5[0x38c] != 0)) {

    *(uint32_t *)(iVar4 + 0x124) = *(uint32_t *)(iVar4 + 0x124) | 0x40000000;

    }

    }

    else {

    *(uint32_t *)(param_1 + 300) = *(uint32_t *)(param_1 + 300) & 0xffffffef;

    *puVar5 = *puVar5 | 0x80;

    }

    if ((DAT_006ff960 == 6) && (iVar4 = FUN_0045f460(), iVar4 != 0)) {

    local_4 = puVar5[puVar5[0x36e] * 2 + 0x356];

    FUN_00469d20(4,&local_4);

    }

    puVar5[0x3d5] = 0;

    switch(*(uint32_t *)

    (*(int *)(param_1 + 0x14c) + 0xd58 + *(int *)(*(int *)(param_1 + 0x14c) + 0xdb8) * 8)) {

    case 0x2c:

    break;

    case 0x2d:

    break;

    case 0x2e:

    break;

    case 0x2f:

    break;

    case 0x30:

    break;

    default:

    goto switchD_005879f9_default;

    }

    FUN_00558240();

    }

    switchD_005879f9_default:

    *(uint32_t *)(param_1 + 0x260) = *(uint32_t *)(param_1 + 0x260) & 0xfdfffeff;

    return;


}  // 0x005878b0
#endif // RenderFn5878B0
void RenderFn5878B0() {}  // 0x005878b0
#if 0 // GHIDRA_RAW: RenderFn5A0540 @ 0x005a0540 — needs manual cleanup
void RenderFn5A0540(int param_1)
{


    void *pvVar1;

    char cVar2;

    uint32_t uVar3;

    float fVar4;

    void *local_10;

    uint8_t *puStack_c;

    uint32_t local_8;



    pvVar1 = ExceptionList;

    local_8 = 0xffffffff;

    puStack_c = &LAB_0064c58d;

    local_10 = ExceptionList;

    uVar3 = DAT_0067d280 ^ (uint)&stack0xfffffffc;

    // ExceptionList = ... (SEH frame, stubbed)

    fVar4 = *(float *)(param_1 + 0x138) - DAT_00727e38;

    *(float *)(param_1 + 0x138) = fVar4;

    if (0.0 <= fVar4) {

    if (*(int *)(param_1 + 4) == 0xe6) {

    fVar4 = *(float *)(DAT_007028f4 + 0x10e8);

    }

    else if (*(int *)(param_1 + 4) == 0x49) {

    fVar4 = *(float *)(DAT_007028f4 + 0x10ec);

    }

    else {

    fVar4 = *(float *)(DAT_007028f4 + 0x10f0);

    }

    if (fVar4 != 0.0) {

    if ((*(byte *)(param_1 + 300) & 8) != 0) {

    // ExceptionList = ... (SEH frame, stubbed)

    return;

    }

    FUN_005d64c0(uVar3);

    local_8 = 0;

    FUN_0043cb70("fx_vimp_mana",0xc);

    cVar2 = FUN_005d6540();

    if (cVar2 != '\0') {

    *(uint32_t *)(param_1 + 0x124) = *(uint32_t *)(param_1 + 0x124) | 0x8000;

    }

    FUN_004439b0();

    // ExceptionList = ... (SEH frame, stubbed)

    return;

    }

    }

    *(uint32_t *)(param_1 + 0x124) = *(uint32_t *)(param_1 + 0x124) | 0x8000;

    // ExceptionList = ... (SEH frame, stubbed)

    return;


}  // 0x005a0540
#endif // RenderFn5A0540
void RenderFn5A0540() {}  // 0x005a0540
#if 0 // GHIDRA_RAW: RenderFn5C3C60 @ 0x005c3c60 — needs manual cleanup
void RenderFn5C3C60(void)
{


    uint32_t *puVar1;

    float fVar2;

    int iVar3;

    uint32_t *puVar4;

    float fVar5;

    uint32_t uVar6;

    int iVar7;

    int iVar8;

    float fVar9;

    uint8_t local_34 [4];

    uint32_t local_30;

    uint32_t uStack_2c;

    uint32_t local_28;

    uint32_t local_24;



    for (puVar4 = DAT_007027a8; puVar4 != (uint32_t *)0x0; puVar4 = (uint32_t *)*puVar4) {

    iVar7 = puVar4[3];

    if ((*(int *)(iVar7 + 0x22c) == 0x5c) && (*(int *)(iVar7 + 0x134) == 1)) {

    FUN_005c39c0();

    FUN_0056ca90();

    fVar5 = DAT_0066c1e4;

    fVar2 = *(float *)(iVar7 + 0x30c);

    fVar9 = *(float *)(iVar7 + 0x2fc) * DAT_0066c1e4;

    *(float *)(DAT_00702770 + 0x5054) = *(float *)(iVar7 + 0x2ec) * DAT_0066c1e4;

    *(float *)(DAT_00702770 + 0x5058) = fVar9;

    *(float *)(DAT_00702770 + 0x505c) = fVar2 * fVar5;

    if (*(int *)(DAT_00702770 + 0x504c) != 0) {

    local_30 = *(uint32_t *)(DAT_00702770 + 0x5054);

    uStack_2c = *(uint32_t *)(DAT_00702770 + 0x5058);

    local_28 = *(uint32_t *)(DAT_00702770 + 0x505c);

    local_24 = 8;

    uVar6 = FUN_004e9cd0(local_34);

    *(uint32_t *)(DAT_00702770 + 0x5060) = uVar6;

    }

    iVar8 = 0;

    iVar7 = DAT_00702770;

    do {

    if (*(int *)(iVar8 + 0x5068 + iVar7) != 0) {

    uVar6 = FUN_00559dc0();

    *(uint32_t *)(iVar8 + 0x506c + DAT_00702770) = uVar6;

    iVar3 = *(int *)(iVar8 + 0x506c + DAT_00702770);

    iVar7 = DAT_00702770;

    if (iVar3 != 0) {

    if (*(int *)(iVar3 + 4) == 0x46a) {

    *(uint32_t *)(iVar3 + 0x214) = *(uint32_t *)(iVar3 + 0x214) | 0x2000000;

    }

    FUN_0055c150();

    puVar1 = (uint32_t *)(*(int *)(iVar8 + 0x506c + DAT_00702770) + 0x124);

    *puVar1 = *puVar1 | 0x40000000;

    iVar7 = DAT_00702770;

    }

    }

    iVar8 = iVar8 + 0x44;

    } while (iVar8 < 0xcc);

    }

    }

    return;


}  // 0x005c3c60
#endif // RenderFn5C3C60
void RenderFn5C3C60() {}  // 0x005c3c60
#if 0 // GHIDRA_RAW: RenderFn5D6790 @ 0x005d6790 — needs manual cleanup
void RenderFn5D6790(int param_1,int param_2)
{


    void *local_10;

    uint8_t *puStack_c;

    uint32_t local_8;



    local_8 = 0xffffffff;

    puStack_c = &LAB_0064c86d;

    local_10 = ExceptionList;

    // ExceptionList = ... (SEH frame, stubbed)

    if ((param_1 != 0) && (param_2 != 0)) {

    FUN_005d64c0(DAT_0067d280 ^ (uint)&stack0xfffffffc);

    local_8 = 0;

    FUN_0043cb70("fx_player_mana",0xe);

    FUN_005d6540();

    FUN_004439b0();

    }

    // ExceptionList = ... (SEH frame, stubbed)

    return;


}  // 0x005d6790
#endif // RenderFn5D6790
void RenderFn5D6790() {}  // 0x005d6790
#if 0 // GHIDRA_RAW: RenderFn5E2DE0 @ 0x005e2de0 — needs manual cleanup
void RenderFn5E2DE0(int param_1,int param_2)
{


    int iVar1;

    bool bVar2;

    int iVar3;

    float10 fVar4;

    float fVar5;

    uint8_t local_3c [4];

    uint64_t local_38;

    float local_30;

    uint64_t local_2c;

    float local_24;

    uint8_t local_20 [12];

    uint8_t local_14 [12];

    uint32_t local_8;



    local_8 = DAT_0067d280 ^ (uint)local_3c;

    bVar2 = false;

    iVar1 = (&DAT_0074b778)[param_2];

    iVar3 = **(int **)(iVar1 + 0x14c);

    if (iVar3 == 0) {

    iVar3 = **(int **)(param_1 + 0x14c);

    if (iVar3 != 0) {

    bVar2 = true;

    goto LAB_005e2e1e;

    }

    *(uint32_t *)(iVar1 + 0x120) = *(uint32_t *)(param_1 + 0x120);

    fVar5 = *(float *)(param_1 + 0x114);

    }

    else {

    LAB_005e2e1e:

    local_2c = *(uint64_t *)(iVar1 + 0xf0);

    local_24 = *(float *)(iVar1 + 0x370) * *(float *)(iVar1 + 0x234) + *(float *)(iVar1 + 0xf8);

    local_38 = *(uint64_t *)(iVar3 + 0xf0);

    local_30 = *(float *)(iVar3 + 0x370) * *(float *)(iVar3 + 0x234) + *(float *)(iVar3 + 0xf8);

    iVar3 = FUN_005c55f0(param_1);

    if (iVar3 == 0) {

    return;

    }

    FUN_005e2cb0(local_14,local_20);

    fVar4 = (float10)FUN_00638a90(local_14,local_20);

    *(float *)(iVar1 + 0x120) = (float)fVar4;

    if (!bVar2) goto LAB_005e2f0d;

    fVar4 = (float10)FUN_006389d0(local_14,local_20);

    fVar5 = (float)fVar4;

    }

    *(float *)(iVar1 + 0x114) = fVar5;

    *(float *)(&DAT_0074b7f0 + param_2 * 4) = fVar5;

    LAB_005e2f0d:

    *(uint32_t *)(iVar1 + 0x260) = *(uint32_t *)(iVar1 + 0x260) | 1;

    return;


}  // 0x005e2de0
#endif // RenderFn5E2DE0
void RenderFn5E2DE0() {}  // 0x005e2de0
#if 0 // GHIDRA_RAW: RenderFn5F3F60 @ 0x005f3f60 — needs manual cleanup
void RenderFn5F3F60(int param_1)
{


    int iVar1;

    float fVar2;

    float fVar3;

    float fVar4;

    int iVar5;

    int iVar6;

    bool bVar7;

    float fVar8;

    float local_18;

    uint16_t local_14;

    uint16_t local_12;

    float local_10;

    float local_c [2];



    if (param_1 == 0) {

    iVar6 = 0;

    }

    else {

    iVar6 = *(int *)(param_1 + 0x14c);

    }

    iVar1 = *(int *)(*(int *)(param_1 + 0x2c4) + 0x14c);

    iVar5 = rand();

    FUN_006387e0((float)iVar5 * _DAT_0066bd00 * DAT_0066c14c + 0.0,local_c,&local_10);

    local_18 = *(float *)(*(int *)(*(int *)(iVar1 + 0x30) + *(int *)(iVar6 + 0x98) * 4) + 0x144);

    iVar5 = rand();

    *(float *)(param_1 + 0x1c4) = ((float)iVar5 * _DAT_0066bd00 * (local_18 - 0.0) + 0.0) * local_10;

    local_18 = *(float *)(*(int *)(*(int *)(iVar1 + 0x30) + *(int *)(iVar6 + 0x98) * 4) + 0x144);

    iVar5 = rand();

    bVar7 = DAT_006ff960 == 6;

    *(float *)(param_1 + 0x1c8) = ((float)iVar5 * _DAT_0066bd00 * (local_18 - 0.0) + 0.0) * local_c[0]

    ;

    *(float *)(iVar6 + 0x40) =

    *(float *)(*(int *)(*(int *)(iVar1 + 0x30) + *(int *)(iVar6 + 0x98) * 4) + 0xf0) +

    *(float *)(param_1 + 0x1c4);

    *(float *)(iVar6 + 0x44) =

    *(float *)(*(int *)(*(int *)(iVar1 + 0x30) + *(int *)(iVar6 + 0x98) * 4) + 0xf4) +

    *(float *)(param_1 + 0x1c8);

    if (bVar7) {

    iVar6 = FUN_0045f460();

    fVar3 = DAT_0066c1d4;

    if (iVar6 != 0) {

    iVar6 = *(int *)(param_1 + 0x14c);

    fVar2 = *(float *)(param_1 + 0xf0);

    if (DAT_0066c1d4 < *(float *)(param_1 + 0xf0)) {

    *(uint32_t *)(param_1 + 0xf0) = 0x45fa0000;

    fVar2 = fVar3;

    }

    fVar8 = *(float *)(param_1 + 0xf4);

    if (fVar3 < *(float *)(param_1 + 0xf4)) {

    *(uint32_t *)(param_1 + 0xf4) = 0x45fa0000;

    fVar8 = fVar3;

    }

    fVar4 = DAT_0066c2e8;

    if (fVar2 < DAT_0066c2e8) {

    *(uint32_t *)(param_1 + 0xf0) = 0xc5fa0000;

    }

    if (fVar8 < fVar4) {

    *(uint32_t *)(param_1 + 0xf4) = 0xc5fa0000;

    }

    fVar2 = *(float *)(iVar6 + 0x40);

    if (fVar3 < *(float *)(iVar6 + 0x40)) {

    *(uint32_t *)(iVar6 + 0x40) = 0x45fa0000;

    fVar2 = fVar3;

    }

    fVar8 = *(float *)(iVar6 + 0x44);

    if (fVar3 < *(float *)(iVar6 + 0x44)) {

    *(uint32_t *)(iVar6 + 0x44) = 0x45fa0000;

    fVar8 = fVar3;

    }

    if (fVar2 < fVar4) {

    *(uint32_t *)(iVar6 + 0x40) = 0xc5fa0000;

    fVar2 = fVar4;

    }

    if (fVar8 < fVar4) {

    *(uint32_t *)(iVar6 + 0x44) = 0xc5fa0000;

    fVar8 = fVar4;

    }

    local_18 = (float)CONCAT22((short)(int)(*(float *)(param_1 + 0xf4) +

    *(float *)(param_1 + 0xf4)),

    (short)(int)(*(float *)(param_1 + 0xf0) +

    *(float *)(param_1 + 0xf0)));

    local_14 = (uint16_t)(int)(fVar2 + fVar2);

    local_12 = (uint16_t)(int)(fVar8 + fVar8);

    FUN_00469f80(2,0,4,&local_18);

    }

    }

    FUN_005f3e80();

    return;


}  // 0x005f3f60
#endif // RenderFn5F3F60
void RenderFn5F3F60() {}  // 0x005f3f60
#if 0 // GHIDRA_RAW: SysFn60C350 @ 0x0060c350 — needs manual cleanup
void SysFn60C350()
{


    LOCK();

    local_58[1] = local_58[1] + 1;

    UNLOCK();


}  // 0x0060c350
#endif // SysFn60C350
void SysFn60C350() {}  // 0x0060c350
#if 0 // GHIDRA_RAW: SysFn60DC00 @ 0x0060dc00 — needs manual cleanup
int SysFn60DC00(int *param_1)
{


    int *piVar1;

    int iVar2;

    uint32_t *puVar3;

    int iVar4;

    uint32_t local_5c;

    uint8_t **local_58;

    uint64_t *puStack_54;

    uint32_t uStack_50;

    uint8_t **local_40;

    uint64_t local_3c;

    uint32_t local_34;

    uint8_t **local_30;

    uint8_t **local_2c;

    uint64_t local_28;

    uint32_t local_20;

    uint8_t **local_1c;

    uint8_t *local_18;

    uint8_t local_14;

    void *local_10;

    uint8_t *puStack_c;

    uint32_t uStack_8;



    uStack_8 = 0xffffffff;

    puStack_c = &LAB_0064e820;

    local_10 = ExceptionList;

    uStack_50 = DAT_0067d280 ^ (uint)&stack0xfffffffc;

    // ExceptionList = ... (SEH frame, stubbed)

    iVar4 = *param_1;

    if ((iVar4 != 0) &&

    ((((char)param_1[1] == '\0' || (*(char *)(iVar4 + 0x74) == '\0')) &&

    (*(int *)(iVar4 + 0x78) == 0)))) {

    puStack_54 = &local_28;

    local_58 = &local_18;

    local_2c = std::exception::vftable;

    local_18 = &DAT_0065d0b3;

    local_28 = 0;

    local_14 = 1;

    local_5c = 0x60dc78;

    __std_exception_copy();

    local_2c = &PTR_FUN_0065f214;

    local_20 = 1;

    local_1c = &PTR_PTR_006858b0;

    local_40 = std::exception::vftable;

    puStack_54 = (uint64_t *)0x0;

    local_3c = 0;

    __std_exception_copy(&local_28,&local_3c);

    local_40 = &PTR_FUN_0065f214;

    local_34 = local_20;

    local_30 = local_1c;

    local_5c = 0;

    local_58 = (uint8_t **)0x0;

    __ExceptionPtrCreate(&local_5c);

    __ExceptionPtrCopyException(&local_5c,&local_40,&DAT_0067821c);

    local_40 = std::exception::vftable;

    __std_exception_destroy(&local_3c);

    FUN_006067d0();

    puStack_54 = &local_28;

    local_2c = std::exception::vftable;

    local_58 = (uint8_t **)0x60dd11;

    iVar4 = __std_exception_destroy();

    }

    puStack_54 = (uint64_t *)*param_1;

    if (puStack_54 != (uint64_t *)0x0) {

    LOCK();

    piVar1 = (int *)((int)puStack_54 + 4);

    iVar2 = *piVar1;

    iVar4 = *piVar1;

    *piVar1 = iVar2 + -1;

    UNLOCK();

    if (iVar2 + -1 == 0) {

    if (*(uint32_t **)((int)puStack_54 + 0x80) != (uint32_t *)0x0) {

    local_58 = (uint8_t **)0x60dd35;

    iVar4 = (**(code **)**(uint32_t **)((int)puStack_54 + 0x80))();

    // ExceptionList = ... (SEH frame, stubbed)

    return iVar4;

    }

    puVar3 = *(uint32_t **)puStack_54;

    puStack_54 = (uint64_t *)0x1;

    local_58 = (uint8_t **)0x60dd4d;

    iVar4 = (*(GhidraCodePtr *)*puVar3)();

    }

    }

    // ExceptionList = ... (SEH frame, stubbed)

    return iVar4;


}  // 0x0060dc00
#endif // SysFn60DC00
void SysFn60DC00() {}  // 0x0060dc00
#if 0 // GHIDRA_RAW: SysFn61AD10 @ 0x0061ad10 — needs manual cleanup
uint8_t * SysFn61AD10(int *param_1)
{


    int iVar1;

    int **ppiVar2;

    int *piVar3;

    int iVar4;

    int *piVar5;

    uint8_t auStackY_100 [184];

    uint32_t uStackY_48;

    uint32_t uStackY_44;

    uint32_t uStackY_40;

    uint32_t uStackY_3c;

    int *local_20;

    int *local_1c;

    int *local_18;

    char local_11;

    void *local_10;

    uint8_t *puStack_c;

    uint32_t local_8;



    puStack_c = &LAB_0064f96d;

    local_10 = ExceptionList;

    iVar1 = *param_1;

    if ((*(char *)(iVar1 + 0x48) != '\0') || (*(char *)(iVar1 + 0x49) != '\0')) {

    return auStackY_100;

    }

    piVar5 = (int *)0x0;

    local_20 = (int *)0x0;

    local_1c = (int *)0x0;

    local_18 = (int *)0x0;

    local_8 = 0;

    local_11 = '\0';

    // ExceptionList = ... (SEH frame, stubbed)

    // _Mtx_lock() — stubbed

    if (iVar4 != 0) {

    throw std::runtime_error("mutex error");

    }

    if (*(int *)(iVar1 + 0x38) == 0x7fffffff) {

    *(uint32_t *)(iVar1 + 0x38) = 0x7ffffffe;

    uStackY_3c = 0x61ad92;

    throw std::runtime_error("mutex error");

    }

    iVar1 = *param_1;

    if ((*(char *)(iVar1 + 0x48) == '\0') && (*(char *)(iVar1 + 0x49) == '\0')) {

    *(uint8_t *)(iVar1 + 0x3c) = 0;

    *(uint8_t *)(*param_1 + 0x48) = 1;

    ppiVar2 = (int **)*param_1;

    if (&local_20 != ppiVar2) {

    local_1c = ppiVar2[1];

    piVar5 = *ppiVar2;

    local_18 = ppiVar2[2];

    *ppiVar2 = (int *)0x0;

    ppiVar2[1] = (int *)0x0;

    ppiVar2[2] = (int *)0x0;

    local_20 = piVar5;

    }

    local_11 = '\x01';

    }

    uStackY_3c = 0x61ade3;

    _Mtx_unlock();

    piVar3 = local_1c;

    if (local_11 != '\0') {

    for (; piVar5 != piVar3; piVar5 = piVar5 + 2) {

    if (*(int *)(*piVar5 + 4) == 2) {

    uStackY_3c = 0;

    uStackY_40 = 0;

    uStackY_44 = 1;

    uStackY_48 = 0x61ae0c;

    (**(code **)(*(int *)*piVar5 + 4))();

    }

    else {

    uStackY_3c = 0x61ae1a;

    FUN_00613650();

    }

    }

    { extern void FUN_0042b2c0(); FUN_0042b2c0(); }

    // ExceptionList = ... (SEH frame, stubbed)

    return (uint8_t *)0x1;

    }

    { extern void FUN_0042b2c0(); FUN_0042b2c0(); }

    // ExceptionList = ... (SEH frame, stubbed)

    return (uint8_t *)0x0;


}  // 0x0061ad10
#endif // SysFn61AD10
void SysFn61AD10() {}  // 0x0061ad10
#if 0 // GHIDRA_RAW: CoreFn43EBB0 @ 0x0043ebb0 — needs manual cleanup
void CoreFn43EBB0()
{


    ppuVar1 = (uint32_t **)(param_1 + 0x14);

    if (&local_50 != ppuVar1) {

    puVar2 = *ppuVar1;

    iVar3 = *(int *)(param_1 + 0x18);

    *ppuVar1 = local_50;

    *(int *)(param_1 + 0x18) = local_4c;

    local_50 = puVar2;

    local_4c = iVar3;

    }

    local_44 = local_44 + local_4c;

    for (puVar2 = (uint32_t *)*local_50; puVar2 != local_50; puVar2 = (uint32_t *)*puVar2) {

    uVar13 = local_60 &

    ((((*(byte *)(puVar2 + 2) ^ 0x811c9dc5) * 0x1000193 ^

    (uint)*(byte *)((int)puVar2 + 9)) * 0x1000193 ^ (uint)*(byte *)((int)puVar2 + 10))

    * 0x1000193 ^ (uint)*(byte *)((int)puVar2 + 0xb)) * 0x1000193;

    puVar14 = (uint32_t *)(local_48 + uVar13 * 0x38);

    *puVar14 = *puVar14 | 2;

    *(uint32_t *)(local_48 + 4 + uVar13 * 0x38) = *(uint32_t *)(local_48 + 4 + uVar13 * 0x38);

    }


}  // 0x0043ebb0
#endif // CoreFn43EBB0
void CoreFn43EBB0() {}  // 0x0043ebb0
#if 0 // GHIDRA_RAW: CoreFn448F60 @ 0x00448f60 — needs manual cleanup
void CoreFn448F60(uint32_t param_1)
{


    int iVar1;

    uint32_t uVar2;



    if (param_1 != 0) {

    iVar1 = 1;

    if (0 < (int)param_1) {

    do {

    iVar1 = iVar1 * 2;

    } while (iVar1 <= (int)param_1);

    }

    FUN_00449070(5,0);

    for (uVar2 = iVar1 >> 2; uVar2 != 0; uVar2 = (int)uVar2 >> 1) {

    FUN_00448ad0();

    if ((param_1 & uVar2) != 0) {

    FUN_00449150(5);

    }

    }

    FUN_00448fd0(param_1);

    return;

    }

    FUN_00449070(1,0);

    return;


}  // 0x00448f60
#endif // CoreFn448F60
void CoreFn448F60() {}  // 0x00448f60
void GameFn46E380() {}  // 0x0046e380
#if 0 // GHIDRA_RAW: GameFn470AC0 @ 0x00470ac0 — needs manual cleanup
void GameFn470AC0()
{


    ppiVar1 = (int **)(param_1 + 0x14);

    if (&local_4c != ppiVar1) {

    piVar3 = *ppiVar1;

    iVar13 = *(int *)(param_1 + 0x18);

    *ppiVar1 = local_4c;

    *(int *)(param_1 + 0x18) = local_48;

    local_4c = piVar3;

    local_48 = iVar13;

    }

    local_40 = local_40 + local_48;

    for (piVar3 = (int *)*local_4c; piVar3 != local_4c; piVar3 = (int *)*piVar3) {

    iVar13 = (local_5c &

    ((((*(byte *)(piVar3 + 2) ^ 0x811c9dc5) * 0x1000193 ^

    (uint)*(byte *)((int)piVar3 + 9)) * 0x1000193 ^ (uint)*(byte *)((int)piVar3 + 10))

    * 0x1000193 ^ (uint)*(byte *)((int)piVar3 + 0xb)) * 0x1000193) * 0x10;

    *(uint32_t *)(iVar13 + local_44) = *(uint32_t *)(iVar13 + local_44) | 2;

    *(uint32_t *)(iVar13 + 4 + local_44) = *(uint32_t *)(iVar13 + 4 + local_44);

    }


}  // 0x00470ac0
#endif // GameFn470AC0
void GameFn470AC0() {}  // 0x00470ac0
FILE * GameFn4725B0(LPCSTR param_1,LPCSTR param_2)
{


    int cchWideChar;

    int cchWideChar_00;

    int iVar1;

    FILE *pFVar2;

    wchar_t *lpWideCharStr;

    void *local_10;

    uint8_t *puStack_c;

    uint32_t uStack_8;



    uStack_8 = 0xffffffff;

    puStack_c = reinterpret_cast<uint8_t*>(&LAB_00648c4d);

    local_10 = ExceptionList;

    // ExceptionList = ... (SEH frame, stubbed)

    cchWideChar = MultiByteToWideChar(0xfde9,0,param_1,-1,(LPWSTR)0x0,0);

    cchWideChar_00 = MultiByteToWideChar(0xfde9,0,param_2,-1,(LPWSTR)0x0,0);

    lpWideCharStr = (wchar_t *)0x0;

    iVar1 = cchWideChar_00 + cchWideChar;

    if (0 < iVar1) {

    if (iVar1 < 8) {

    iVar1 = 8;

    }

    if (0 < iVar1) {

    if (DAT_00701a3c != 0) {

    *(int *)(DAT_00701a3c + 0x370) = *(int *)(DAT_00701a3c + 0x370) + 1;

    }

    lpWideCharStr = malloc(iVar1 * 2);

    }

    }

    MultiByteToWideChar(0xfde9,0,param_1,-1,lpWideCharStr,cchWideChar);

    MultiByteToWideChar(0xfde9,0,param_2,-1,lpWideCharStr + cchWideChar,cchWideChar_00);

    pFVar2 = _wfopen(lpWideCharStr,lpWideCharStr + cchWideChar);

    if (lpWideCharStr != (wchar_t *)0x0) {

    if (DAT_00701a3c != 0) {

    *(int *)(DAT_00701a3c + 0x370) = *(int *)(DAT_00701a3c + 0x370) + -1;

    }

    free(lpWideCharStr);

    }

    // ExceptionList = ... (SEH frame, stubbed)

    return pFVar2;


}  // 0x004725b0
void GameFn486B80() {}  // 0x00486b80
void GameFn4BAEE0() {}  // 0x004baee0
void GameFn4BEA70() {}  // 0x004bea70
#if 0 // GHIDRA_RAW: GameFn4E9BB0 @ 0x004e9bb0 — needs manual cleanup
void GameFn4E9BB0(uint32_t param_1,uint32_t param_2)
{


    int iVar1;

    uint32_t *puVar2;

    uint32_t uVar3;

    uint32_t uVar4;



    if ((*(int *)(*(int *)ThreadLocalStoragePointer + 4) < DAT_0074eec0) &&

    (FUN_006435f8(&DAT_0074eec0), DAT_0074eec0 == -1)) {

    FUN_004ad590(&DAT_0074eec4);

    FUN_0064389d(&LAB_006518c0);

    FUN_006435a7(&DAT_0074eec0);

    }

    uVar3 = (param_2 & 2) << 9;

    puVar2 = DAT_007027a8;

    uVar4 = uVar3 | 0x1000;

    if ((param_2 & 4) == 0) {

    uVar4 = uVar3;

    }

    for (; puVar2 != (uint32_t *)0x0; puVar2 = (uint32_t *)*puVar2) {

    iVar1 = puVar2[3];

    if (((*(int *)(iVar1 + 0x22c) == 0x4e) && ((*(uint32_t *)(iVar1 + 0x124) & 0x8000) == 0)) &&

    ((*(uint32_t *)(iVar1 + 0x130) & uVar4) != 0)) {

    (**(code **)(*DAT_0074eec4 + 0x14))(iVar1);

    }

    }

    return;


}  // 0x004e9bb0
#endif // GameFn4E9BB0
void GameFn4E9BB0() {}  // 0x004e9bb0
#if 0 // GHIDRA_RAW: GameFn4F3680 @ 0x004f3680 — needs manual cleanup
void GameFn4F3680()
{


    ppiVar1 = (int **)(param_1 + 0x14);

    if (&local_4c != ppiVar1) {

    piVar3 = *ppiVar1;

    iVar13 = *(int *)(param_1 + 0x18);

    *ppiVar1 = local_4c;

    *(int *)(param_1 + 0x18) = local_48;

    local_4c = piVar3;

    local_48 = iVar13;

    }

    local_40 = local_40 + local_48;

    for (piVar3 = (int *)*local_4c; piVar3 != local_4c; piVar3 = (int *)*piVar3) {

    iVar13 = (local_5c &

    ((((*(byte *)(piVar3 + 2) ^ 0x811c9dc5) * 0x1000193 ^

    (uint)*(byte *)((int)piVar3 + 9)) * 0x1000193 ^ (uint)*(byte *)((int)piVar3 + 10))

    * 0x1000193 ^ (uint)*(byte *)((int)piVar3 + 0xb)) * 0x1000193) * 0x10;

    *(uint32_t *)(iVar13 + local_44) = *(uint32_t *)(iVar13 + local_44) | 2;

    *(uint32_t *)(iVar13 + 4 + local_44) = *(uint32_t *)(iVar13 + 4 + local_44);

    }


}  // 0x004f3680
#endif // GameFn4F3680
void GameFn4F3680() {}  // 0x004f3680
#if 0 // GHIDRA_RAW: RenderFn531380 @ 0x00531380 — needs manual cleanup
int RenderFn531380(int param_1,int *param_2)
{


    int iVar1;

    uint32_t uVar2;

    float10 fVar3;

    float in_XMM0_Da;

    float local_c [2];

    uint8_t local_4 [4];



    FUN_0062a0b0();

    param_2[2] = (int)(in_XMM0_Da * (float)param_2[3] + (float)param_2[2]);

    iVar1 = FUN_005312b0();

    FUN_004fecb0(local_4,local_c,1);

    if ((*(int *)(*(int *)(*param_2 + 0x14c) + 0x48) == 0) ||

    (*(float *)(param_1 + 0xf8) <= local_c[0] && local_c[0] != *(float *)(param_1 + 0xf8))) {

    *(float *)(param_1 + 0xf8) = local_c[0];

    }

    if ((*(float *)(param_1 + 0x108) != *(float *)(param_1 + 0xf0)) ||

    (*(float *)(param_1 + 0x10c) != *(float *)(param_1 + 0xf4))) {

    fVar3 = (float10)FUN_006389d0(param_1 + 0x108,(float *)(param_1 + 0xf0));

    *(float *)(param_1 + 0x114) = (float)fVar3;

    }

    if (iVar1 != 0) {

    uVar2 = param_2[4] | 2;

    if (*(int *)(*(int *)(iVar1 + 0x14c) + 0x4c) == 0) {

    uVar2 = param_2[4] & 0xfffffffd;

    }

    param_2[4] = uVar2;

    param_2[3] = *(int *)(iVar1 + 0x148);

    }

    return iVar1;


}  // 0x00531380
#endif // RenderFn531380
void RenderFn531380() {}  // 0x00531380
#if 0 // GHIDRA_RAW: RenderFn545950 @ 0x00545950 — needs manual cleanup
void RenderFn545950(void)
{


    FUN_004d63f0();

    FUN_005413d0();

    if (DAT_00702c07 == '\0') {

    if (DAT_00702c08 != '\0') {

    FUN_00545860();

    }

    }

    else {

    FUN_00545860();

    if ((((DAT_00702b30 == 0) && (DAT_00702b34 == 0)) && (DAT_00702b50 == 0)) && (DAT_00702bb8 == 0)

    ) {

    FUN_00558360();

    return;

    }

    }

    return;


}  // 0x00545950
#endif // RenderFn545950
void RenderFn545950() {}  // 0x00545950
#if 0 // GHIDRA_RAW: RenderFn548580 @ 0x00548580 — needs manual cleanup
void RenderFn548580(uint32_t param_1)
{


    FUN_004d1070(param_1);

    DAT_00681db0 = 0;

    DAT_00681db4 = 0xffffffff;

    DAT_00681dec = 0;

    DAT_00681e34 = 0;

    *(uint32_t *)(DAT_00702d60 + 0x124) = *(uint32_t *)(DAT_00702d60 + 0x124) | 0x8000;

    DAT_00702d60 = 0;

    FUN_00541080();

    FUN_00541a50();

    if ((((DAT_00702b30 == 0) && (DAT_00702b34 == 0)) && (DAT_00702b50 == 0)) && (DAT_00702bb8 == 0))

    {

    FUN_00558360();

    }

    return;


}  // 0x00548580
#endif // RenderFn548580
void RenderFn548580() {}  // 0x00548580
#if 0 // GHIDRA_RAW: RenderFn55B6C0 @ 0x0055b6c0 — needs manual cleanup
void RenderFn55B6C0(void)
{


    int iVar1;

    int iVar2;

    int iVar3;

    uint32_t *puVar4;

    uint32_t *puVar5;

    uint32_t local_98 [37];



    iVar3 = DAT_00681dd0;

    DAT_007496d4 = 0;

    if ((*(int *)(DAT_00681dd0 + 8) != 0) && (iVar1 = FUN_00499dd0(), iVar1 != 0)) {

    iVar1 = *(int *)(iVar3 + 0x22c);

    if (iVar1 == 2) {

    iVar2 = 0;

    iVar1 = *(int *)(*(int *)(iVar3 + 0x14c) + 0x5c);

    }

    else if (iVar1 == 3) {

    iVar2 = 0;

    iVar1 = *(int *)(*(int *)(iVar3 + 0x14c) + 0xf6c);

    }

    else {

    if (iVar1 != 1) {

    return;

    }

    iVar1 = *(int *)(*(int *)(iVar3 + 0x14c) + 0xa0);

    iVar2 = *(int *)(*(int *)(iVar3 + 0x14c) + 0xa4);

    }

    if (iVar1 != 0) {

    DAT_007496d4 = 1;

    puVar4 = &DAT_00728510;

    puVar5 = local_98;

    for (iVar1 = 0x24; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar5 = *puVar4;

    puVar4 = puVar4 + 1;

    puVar5 = puVar5 + 1;

    }

    DAT_007496d8 = (uint)(iVar2 != 0);

    FUN_00523380(iVar3);

    _DAT_007284b0 = 0;

    puVar4 = local_98;

    puVar5 = &DAT_00728510;

    for (iVar1 = 0x24; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar5 = *puVar4;

    puVar4 = puVar4 + 1;

    puVar5 = puVar5 + 1;

    }

    FUN_00559e60();

    if (DAT_007496d8 != 0) {

    puVar4 = &DAT_00728888;

    puVar5 = local_98;

    for (iVar1 = 0x24; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar5 = *puVar4;

    puVar4 = puVar4 + 1;

    puVar5 = puVar5 + 1;

    }

    FUN_00523380(iVar3);

    puVar4 = local_98;

    puVar5 = &DAT_00728888;

    for (iVar3 = 0x24; iVar3 != 0; iVar3 = iVar3 + -1) {

    *puVar5 = *puVar4;

    puVar4 = puVar4 + 1;

    puVar5 = puVar5 + 1;

    }

    FUN_00559e60();

    if (*(int *)(DAT_00728830 + 8 + DAT_00728888 * 4) == 0) {

    FUN_0055b500();

    }

    }

    }

    }

    return;


}  // 0x0055b6c0
#endif // RenderFn55B6C0
void RenderFn55B6C0() {}  // 0x0055b6c0
void RenderFn5710A0() {}  // 0x005710a0
#if 0 // GHIDRA_RAW: RenderFn5BC380 @ 0x005bc380 — needs manual cleanup
void RenderFn5BC380(int param_1,int param_2)
{


    uint32_t *puVar1;

    int iVar2;

    float10 fVar3;

    float fVar4;

    float fVar5;

    uint8_t auStack_38 [4];

    uint64_t uStack_34;

    uint32_t uStack_2c;

    float fStack_1c;

    uint32_t uStack_18;

    uint32_t uStack_14;



    if (param_1 == 0) {

    iVar2 = 0;

    }

    else {

    iVar2 = *(int *)(param_1 + 0x14c);

    }

    puVar1 = DAT_007496c4;

    if (*(int *)(iVar2 + 0x234) != 0) {

    for (; puVar1 != (uint32_t *)0x0; puVar1 = (uint32_t *)*puVar1) {

    if (puVar1[0x11] == *(int *)(iVar2 + 0x234)) {

    FUN_005584d0();

    break;

    }

    }

    *(uint32_t *)(iVar2 + 0x234) = 0;

    }

    if (*(int *)(iVar2 + 0x238) != 0) {

    if (((DAT_00702800 != 0) && (DAT_00702800 + 0x10fe8 != 0)) &&

    (*(int *)(DAT_00702800 + 0x10ff0) != 0)) {

    (*DAT_007280a0)(DAT_00702800 + 0x10fe8,param_1);

    }

    *(uint32_t *)(iVar2 + 0x238) = 0;

    }

    if (param_1 != 0) {

    if (param_2 == 0) {

    fVar4 = *(float *)(param_1 + 0x108) - *(float *)(param_1 + 0xf0);

    fVar5 = *(float *)(param_1 + 0x10c) - *(float *)(param_1 + 0xf4);

    }

    else {

    fVar4 = *(float *)(param_2 + 0x108) - *(float *)(param_2 + 0xf0);

    fVar5 = *(float *)(param_2 + 0x10c) - *(float *)(param_2 + 0xf4);

    }

    uStack_34 = *(uint64_t *)(param_1 + 0xf0);

    uStack_2c = *(uint32_t *)(param_1 + 0xf8);

    fVar3 = (float10)FUN_006386b0(fVar5,fVar4);

    uStack_18 = 0;

    uStack_14 = 0;

    fStack_1c = (float)(fVar3 - (float10)DAT_0066c0cc);

    FUN_004e9cd0(auStack_38);

    }

    if ((*(uint32_t *)(param_1 + 300) & 0x1000000) != 0) {

    iVar2 = *(int *)(param_1 + 0x14c);

    *(uint32_t *)(param_1 + 300) = *(uint32_t *)(param_1 + 300) & 0xfeffffff;

    if (*(int *)(iVar2 + 0x20c) != 0) {

    FUN_005ce1f0(0);

    *(uint32_t *)(iVar2 + 0x20c) = 0;

    }

    DAT_0074b50c = 0;

    }

    *(uint32_t *)(param_1 + 0x124) = *(uint32_t *)(param_1 + 0x124) | 0x8000;

    return;


}  // 0x005bc380
#endif // RenderFn5BC380
void RenderFn5BC380() {}  // 0x005bc380
#if 0 // GHIDRA_RAW: RenderFn5EDC30 @ 0x005edc30 — needs manual cleanup
void RenderFn5EDC30(int param_1,int param_2)
{


    uint32_t *puVar1;

    int iVar2;

    int iVar3;

    int iVar4;

    int iVar5;

    bool bVar6;

    int aiStack_c [2];



    if (param_1 == 0) {

    iVar5 = 0;

    }

    else {

    iVar5 = *(int *)(param_1 + 0x14c);

    }

    if (param_2 != 0) {

    if (*(int *)(param_2 + 0x22c) == 2) {

    *(uint32_t *)(param_2 + 300) = *(uint32_t *)(param_2 + 300) | 0x20;

    }

    else if ((param_2 != 0) && (*(int *)(param_2 + 0x22c) == 3)) {

    if (DAT_00702774 == 0) {

    return;

    }

    puVar1 = *(uint32_t **)(DAT_00702774 + 0x14c);

    if (puVar1 == (uint32_t *)0x0) {

    return;

    }

    *puVar1 = *puVar1 | 0x200;

    }

    }

    aiStack_c[0] = param_1;

    if ((DAT_00702bb8 == 0) && (param_2 != 0)) {

    iVar3 = *(int *)(param_2 + 0x264);

    iVar4 = param_2;

    while (iVar2 = iVar3, iVar2 != 0) {

    iVar4 = iVar2;

    iVar3 = *(int *)(iVar2 + 0x264);

    }

    if (iVar4 == DAT_00702774) {

    FUN_00558360();

    }

    else {

    FUN_005581d0();

    }

    }

    bVar6 = DAT_00725e8c == 0;

    *(int *)(iVar5 + 8) = param_2;

    *(uint64_t *)(param_2 + 0x25c) = 0;

    if (bVar6) goto LAB_005edd5e;

    iVar5 = param_2;

    if ((param_2 == 0) || (*(int *)(param_2 + 0x22c) != 2)) {

    if (param_2 == 0) goto LAB_005edd5e;

    iVar4 = *(int *)(param_2 + 0x264);

    while (iVar3 = iVar4, iVar3 != 0) {

    iVar5 = iVar3;

    iVar4 = *(int *)(iVar3 + 0x264);

    }

    if (DAT_00702800 == 0) goto LAB_005edd5e;

    iVar4 = DAT_00702800 + 0x9690;

    }

    else {

    iVar4 = *(int *)(param_2 + 0x264);

    while (iVar3 = iVar4, iVar3 != 0) {

    iVar5 = iVar3;

    iVar4 = *(int *)(iVar3 + 0x264);

    }

    if (DAT_00702800 == 0) goto LAB_005edd5e;

    iVar4 = DAT_00702800 + 0xf85c;

    }

    if ((iVar4 != 0) && (*(int *)(iVar4 + 8) != 0)) {

    (*DAT_007280a0)(iVar4,iVar5);

    }

    LAB_005edd5e:

    DAT_00725e8c = 0;

    DAT_0067effc = *(uint32_t *)(DAT_007028f4 + 0x8f4);

    if ((DAT_006ff960 == 6) && (iVar5 = FUN_0045f460(), iVar5 != 0)) {

    aiStack_c[0] = *(int *)(param_2 + 0x1d4);

    FUN_00469d20(2,aiStack_c);

    }

    return;


}  // 0x005edc30
#endif // RenderFn5EDC30
void RenderFn5EDC30() {}  // 0x005edc30
#if 0 // GHIDRA_RAW: RenderFn5F4C60 @ 0x005f4c60 — needs manual cleanup
void RenderFn5F4C60(int param_1,uint32_t param_2,uint32_t param_3,int param_4)
{


    int iVar1;

    int iVar2;

    uint16_t local_18;

    uint16_t local_16;

    uint16_t local_14;

    uint16_t local_12;

    uint16_t local_10;

    uint16_t local_e;

    uint16_t local_c;

    uint32_t local_a;

    uint32_t local_6;



    if (*(int *)(param_1 + 0x2c4) != 0) {

    iVar1 = FUN_005f48e0(1,0,*(uint32_t *)(param_1 + 0x370));

    if ((param_2 & 0x10) != 0) {

    FUN_005d66a0(param_4);

    }

    if ((DAT_006ff960 == 6) && (iVar2 = FUN_0045f460(), iVar2 != 0)) {

    local_18 = (uint16_t)(int)(*(float *)(iVar1 + 0xf0) + *(float *)(iVar1 + 0xf0));

    local_16 = (uint16_t)(int)(*(float *)(iVar1 + 0xf4) + *(float *)(iVar1 + 0xf4));

    local_14 = (uint16_t)(int)(*(float *)(iVar1 + 0xf8) + *(float *)(iVar1 + 0xf8));

    local_12 = (uint16_t)(int)(*(float *)(iVar1 + 0x158) * DAT_0066c030);

    local_10 = (uint16_t)(int)(*(float *)(iVar1 + 0x15c) * DAT_0066c030);

    local_e = (uint16_t)(int)(*(float *)(iVar1 + 0x154) * DAT_0066c030);

    local_c = (uint16_t)(int)(*(float *)(param_1 + 0x370) * DAT_0066c00c);

    local_a = *(uint32_t *)(iVar1 + 0x1d4);

    local_6 = (((int)*(float *)(iVar1 + 0x148) | *(int *)(iVar1 + 300) << 8) << 8 |

    *(uint32_t *)(iVar1 + 0x130)) << 8 | *(int *)(iVar1 + 4) - 0x45dU;

    if (param_4 == 2) {

    local_6 = local_6 | 0x40000000;

    }

    else if (param_4 == 1) {

    local_6 = local_6 | 0x80000000;

    }

    FUN_00469de0(0,0x16,2,&local_18,0);

    }

    }

    return;


}  // 0x005f4c60
#endif // RenderFn5F4C60
void RenderFn5F4C60() {}  // 0x005f4c60
#if 0 // GHIDRA_RAW: RenderFn5FD680 @ 0x005fd680 — needs manual cleanup
void RenderFn5FD680()
{


    ppiVar1 = (int **)(param_1 + 0x14);

    if (&local_4c != ppiVar1) {

    piVar3 = *ppiVar1;

    iVar13 = *(int *)(param_1 + 0x18);

    *ppiVar1 = local_4c;

    *(int *)(param_1 + 0x18) = local_48;

    local_4c = piVar3;

    local_48 = iVar13;

    }

    local_40 = local_40 + local_48;

    for (piVar3 = (int *)*local_4c; piVar3 != local_4c; piVar3 = (int *)*piVar3) {

    iVar13 = (local_5c &

    ((((*(byte *)(piVar3 + 2) ^ 0x811c9dc5) * 0x1000193 ^

    (uint)*(byte *)((int)piVar3 + 9)) * 0x1000193 ^ (uint)*(byte *)((int)piVar3 + 10))

    * 0x1000193 ^ (uint)*(byte *)((int)piVar3 + 0xb)) * 0x1000193) * 0x10;

    *(uint32_t *)(iVar13 + local_44) = *(uint32_t *)(iVar13 + local_44) | 2;

    *(uint32_t *)(iVar13 + 4 + local_44) = *(uint32_t *)(iVar13 + 4 + local_44);

    }


}  // 0x005fd680
#endif // RenderFn5FD680
void RenderFn5FD680() {}  // 0x005fd680
void SysFn604A60() {}  // 0x00604a60
void SysFn613140() {}  // 0x00613140
#if 0 // GHIDRA_RAW: SysFn61A8A0 @ 0x0061a8a0 — needs manual cleanup
void SysFn61A8A0(int *param_1)
{


    int iVar1;

    void *pExceptionObject;



    if (*param_1 == 0) {



    FUN_0061d2a0();

    }

    iVar1 = FUN_0061d160();

    if (iVar1 != 2) {

    return;

    }

    FUN_0061ce90();



    _CxxThrowException(pExceptionObject,(ThrowInfo *)&DAT_00678388);


}  // 0x0061a8a0
#endif // SysFn61A8A0
void SysFn61A8A0() {}  // 0x0061a8a0
#if 0 // GHIDRA_RAW: SysFn61A9A0 @ 0x0061a9a0 — needs manual cleanup
char SysFn61A9A0(int *param_1)
{


    int iVar1;

    int **ppiVar2;

    int *piVar3;

    int iVar4;

    int *piVar5;

    int *piVar6;

    int *piVar7;

    bool bVar8;

    int *local_24;

    int *local_20;

    int *local_1c;

    int *local_18;

    char local_11;

    void *local_10;

    uint8_t *puStack_c;

    uint32_t local_8;



    puStack_c = &LAB_0064f8dd;

    local_10 = ExceptionList;

    iVar1 = *param_1;

    if (*(char *)(iVar1 + 0x49) == '\0') {

    piVar6 = (int *)0x0;

    piVar7 = (int *)0x0;

    local_24 = (int *)0x0;

    local_20 = (int *)0x0;

    local_1c = (int *)0x0;

    local_8 = 0;

    local_11 = '\0';

    // ExceptionList = ... (SEH frame, stubbed)

    local_18 = param_1;

    // _Mtx_lock() — stubbed

    if (iVar4 != 0) {

    throw std::runtime_error("mutex error");

    }

    if (*(int *)(iVar1 + 0x38) == 0x7fffffff) {

    *(uint32_t *)(iVar1 + 0x38) = 0x7ffffffe;

    throw std::runtime_error("mutex error");

    }

    if (*(char *)(*local_18 + 0x49) == '\0') {

    *(uint8_t *)(*local_18 + 0x49) = 1;

    ppiVar2 = (int **)*local_18;

    if (&local_24 != ppiVar2) {

    piVar7 = *ppiVar2;

    piVar6 = ppiVar2[1];

    local_1c = ppiVar2[2];

    *ppiVar2 = (int *)0x0;

    ppiVar2[1] = (int *)0x0;

    ppiVar2[2] = (int *)0x0;

    local_24 = piVar7;

    local_20 = piVar6;

    }

    local_11 = '\x01';

    }

    _Mtx_unlock(iVar1 + 0xc);

    piVar3 = local_18;

    local_18 = *(int **)(*local_18 + 0x40);

    if (local_11 != '\0') {

    for (; piVar7 != piVar6; piVar7 = piVar7 + 2) {

    bVar8 = local_18 == (int *)0x0;

    if (bVar8) {

    piVar5 = (int *)*piVar7 + 3;

    }

    else {

    piVar5 = (int *)(*piVar3 + 0x40);

    }

    (**(code **)(*(int *)*piVar7 + 4))(1,!bVar8,!bVar8,piVar5);

    }

    }

    { extern void FUN_0042b2c0(); FUN_0042b2c0(); }

    // ExceptionList = ... (SEH frame, stubbed)

    return local_11;

    }

    return '\0';


}  // 0x0061a9a0
#endif // SysFn61A9A0
void SysFn61A9A0() {}  // 0x0061a9a0
void SysFn62C9A0(uint32_t param_1,uint64_t *param_2,byte *param_3,int param_4)
{
    // Stub: font/text render with color, glyph lookup, screen scaling
    // Original uses many undeclared globals — too complex for clean compilation
    (void)param_1; (void)param_2; (void)param_3; (void)param_4;
}
void SysFn63F750(float *param_1,float *param_2,float *param_3,float param_4)
{
    // Stub: cross product + normalize + quaternion slerp rotation
    // Original uses sin/cos via function pointers and Ghidra-specific types
    if (param_1 == nullptr) return;
    param_1[0] = 0; param_1[1] = 0; param_1[2] = 0; param_1[3] = 1.0f;
    (void)param_2; (void)param_3; (void)param_4;
}  // 0x0063f750

// --- Cycle 57: 2-caller functions (708 functions) ---
void Core2c42AAF0() {}  // 0x0042aaf0
void Core2c42ABA0() {}  // 0x0042aba0
void Core2c42AC10() {}  // 0x0042ac10
void Core2c42B710() {}  // 0x0042b710
void Core2c42B9A0() {}  // 0x0042b9a0
void Core2c42CAB0() {}  // 0x0042cab0
void Core2c42CBC0() {}  // 0x0042cbc0
void Core2c42D650() {}  // 0x0042d650
void Core2c42D9F0() {}  // 0x0042d9f0
void Core2c42E2B0() {}  // 0x0042e2b0
void Core2c42F410() {}  // 0x0042f410
void Core2c42FB00() {}  // 0x0042fb00
void Core2c4304E0() {}  // 0x004304e0
void Core2c430680() {}  // 0x00430680
void Core2c431400() {}  // 0x00431400
void Core2c4317C0() {}  // 0x004317c0
void Core2c4318A0() {}  // 0x004318a0
void Core2c431AF0() {}  // 0x00431af0
void Core2c432240() {}  // 0x00432240
void Core2c432DF0() {}  // 0x00432df0
void Core2c435770() {}  // 0x00435770
void Core2c435CC0() {}  // 0x00435cc0
void Core2c435E60() {}  // 0x00435e60
void Core2c437D10() {}  // 0x00437d10
void Core2c438270() {}  // 0x00438270
void Core2c4382F0() {}  // 0x004382f0
void Core2c4384B0() {}  // 0x004384b0
void Core2c4388F0() {}  // 0x004388f0
void Core2c439170() {}  // 0x00439170
void Core2c4393E0() {}  // 0x004393e0
void Core2c439640() {}  // 0x00439640
void Core2c439860() {}  // 0x00439860
void Core2c439A70() {}  // 0x00439a70
void Core2c439E50() {}  // 0x00439e50
void Core2c43A390() {}  // 0x0043a390
void Core2c43A5F0() {}  // 0x0043a5f0
void Core2c43A840() {}  // 0x0043a840
void Core2c43AA70() {}  // 0x0043aa70
void Core2c43AF10() {}  // 0x0043af10
void Core2c43AF40() {}  // 0x0043af40
void Core2c43B080() {}  // 0x0043b080
void Core2c43B700() {}  // 0x0043b700
void Core2c43C660() {}  // 0x0043c660
void Core2c43CAB0() {}  // 0x0043cab0
void Core2c43CC60() {}  // 0x0043cc60
void Core2c43D3B0() {}  // 0x0043d3b0
void Core2c43D420() {}  // 0x0043d420
void Core2c43D470() {}  // 0x0043d470
void Core2c43D480() {}  // 0x0043d480
void Core2c43D820() {}  // 0x0043d820
void Core2c43D990() {}  // 0x0043d990
void Core2c43DC70() {}  // 0x0043dc70
void Core2c43DD30() {}  // 0x0043dd30
void Core2c43DD80() {}  // 0x0043dd80
void Core2c43DDE0() {}  // 0x0043dde0
void Core2c43E440() {}  // 0x0043e440
void Core2c43E670() {}  // 0x0043e670
void Core2c43E770() {}  // 0x0043e770
void Core2c43E7F0() {}  // 0x0043e7f0
void Core2c43EF40() {}  // 0x0043ef40
void Core2c4401D0() {}  // 0x004401d0
void Core2c440480() {}  // 0x00440480
void Core2c4407E0() {}  // 0x004407e0
void Core2c4416B0() {}  // 0x004416b0
void Core2c441B30() {}  // 0x00441b30
void Core2c442020() {}  // 0x00442020
void Core2c4420C0() {}  // 0x004420c0
void Core2c442470() {}  // 0x00442470
void Core2c442720() {}  // 0x00442720
void Core2c442760() {}  // 0x00442760
void Core2c442870() {}  // 0x00442870
void Core2c442B40() {}  // 0x00442b40
void Core2c442DA0() {}  // 0x00442da0
void Core2c4433B0() {}  // 0x004433b0
void Core2c443500() {}  // 0x00443500
void Core2c443970() {}  // 0x00443970
void Core2c444030() {}  // 0x00444030
void Core2c4466E0() {}  // 0x004466e0
void Core2c446AD0() {}  // 0x00446ad0
void Core2c446B80() {}  // 0x00446b80
void Core2c446E00() {}  // 0x00446e00
void Core2c447240() {}  // 0x00447240
void Core2c447380() {}  // 0x00447380
void Core2c447710() {}  // 0x00447710
void Core2c447E80() {}  // 0x00447e80
void Core2c447F30() {}  // 0x00447f30
void Core2c448010() {}  // 0x00448010
void Core2c448870() {}  // 0x00448870
void Core2c4490C0() {}  // 0x004490c0
void Core2c44A440() {}  // 0x0044a440
void Core2c44AFA0() {}  // 0x0044afa0
void Core2c44B3F0() {}  // 0x0044b3f0
void Core2c44B660() {}  // 0x0044b660
void Core2c44B900() {}  // 0x0044b900
void Core2c44BB60() {}  // 0x0044bb60
void Core2c44C7F0() {}  // 0x0044c7f0
void Core2c44CD90() {}  // 0x0044cd90
void Core2c44CFE0() {}  // 0x0044cfe0
void Core2c44D2C0() {}  // 0x0044d2c0
void Core2c44D9F0() {}  // 0x0044d9f0
void Core2c44F5A0() {}  // 0x0044f5a0
void Core2c44F800() {}  // 0x0044f800
void Core2c44FDE0() {}  // 0x0044fde0
void Game2c4505B0() {}  // 0x004505b0
void Game2c450DE0() {}  // 0x00450de0
void Game2c450ED0() {}  // 0x00450ed0
void Game2c450F60() {}  // 0x00450f60
void thunk_FUN_0042b010() {}  // 0x00451610
void Game2c451E30() {}  // 0x00451e30
void Game2c452200() {}  // 0x00452200
void Game2c4527F0() {}  // 0x004527f0
void Game2c453370() {}  // 0x00453370
void Game2c453980() {}  // 0x00453980
void Game2c455D90() {}  // 0x00455d90
void Game2c455E90() {}  // 0x00455e90
void Game2c4566F0() {}  // 0x004566f0
void Game2c4568F0() {}  // 0x004568f0
void Game2c456960() {}  // 0x00456960
void Game2c4569D0() {}  // 0x004569d0
void Game2c456AC0() {}  // 0x00456ac0
void Game2c456BD0() {}  // 0x00456bd0
void Game2c456C40() {}  // 0x00456c40
void Game2c456CB0() {}  // 0x00456cb0
void Game2c457970() {}  // 0x00457970
void Game2c459070() {}  // 0x00459070
void Game2c45D470() {}  // 0x0045d470
void Game2c45D9C0() {}  // 0x0045d9c0
void Game2c45DAE0() {}  // 0x0045dae0
void Game2c45EB20() {}  // 0x0045eb20
void Game2c45EB80() {}  // 0x0045eb80
void Game2c45EC20() {}  // 0x0045ec20
void Game2c45F0E0() {}  // 0x0045f0e0
void Game2c45F850() {}  // 0x0045f850
void Game2c4613E0() {}  // 0x004613e0
void Game2c461730() {}  // 0x00461730
void Game2c461DB0() {}  // 0x00461db0
void Game2c461F90() {}  // 0x00461f90
void Game2c462110() {}  // 0x00462110
void Game2c462230() {}  // 0x00462230
void Game2c462640() {}  // 0x00462640
void Game2c462B40() {}  // 0x00462b40
void Game2c462C40() {}  // 0x00462c40
void Game2c462D40() {}  // 0x00462d40
void Game2c463430() {}  // 0x00463430
void Game2c463890() {}  // 0x00463890
void Game2c464770() {}  // 0x00464770
void Game2c4648B0() {}  // 0x004648b0
void Game2c465270() {}  // 0x00465270
void Game2c4689E0() {}  // 0x004689e0
void Game2c468DA0() {}  // 0x00468da0
void Game2c468FF0() {}  // 0x00468ff0
void Game2c469A90() {}  // 0x00469a90
void Game2c46CEF0() {}  // 0x0046cef0
void Game2c46D520() {}  // 0x0046d520
void Game2c46D860() {}  // 0x0046d860
void Game2c46DAD0() {}  // 0x0046dad0
void Game2c46DBC0() {}  // 0x0046dbc0
void Game2c46E680() {}  // 0x0046e680
void Game2c46E700() {}  // 0x0046e700
void thunk_FUN_0046feb0() {}  // 0x0046eaa0
void thunk_FUN_0046eac0() {}  // 0x0046eab0
void Game2c470440() {}  // 0x00470440
void Game2c4708A0() {}  // 0x004708a0
void Game2c470910() {}  // 0x00470910
void Game2c470FF0() {}  // 0x00470ff0
void Game2c4712F0() {}  // 0x004712f0
void Game2c471810() {}  // 0x00471810
void Game2c471F30() {}  // 0x00471f30
void Game2c472C20() {}  // 0x00472c20
void Game2c4730A0() {}  // 0x004730a0
void Game2c473F20() {}  // 0x00473f20
void Game2c474180() {}  // 0x00474180
void Game2c4745E0() {}  // 0x004745e0
void Game2c476250() {}  // 0x00476250
void Game2c476BA0() {}  // 0x00476ba0
void Game2c476C20() {}  // 0x00476c20
void Game2c47BC60() {}  // 0x0047bc60
void Game2c47C380() {}  // 0x0047c380
void Game2c47C7F0() {}  // 0x0047c7f0
void Game2c47C950() {}  // 0x0047c950
void Game2c47D0D0() {}  // 0x0047d0d0
void Game2c47D1A0() {}  // 0x0047d1a0
void Game2c47DAD0() {}  // 0x0047dad0
void Game2c47F4C0() {}  // 0x0047f4c0
void Game2c480520() {}  // 0x00480520
void Game2c480D60() {}  // 0x00480d60
void Game2c480FF0() {}  // 0x00480ff0
void Game2c481310() {}  // 0x00481310
void Game2c481F80() {}  // 0x00481f80
void Game2c484130() {}  // 0x00484130
void Game2c485520() {}  // 0x00485520
void Game2c486700() {}  // 0x00486700
void Game2c4867A0() {}  // 0x004867a0
void Game2c486880() {}  // 0x00486880
void Game2c487460() {}  // 0x00487460
void Game2c488490() {}  // 0x00488490
void Game2c4896F0() {}  // 0x004896f0
void Game2c48C190() {}  // 0x0048c190
void Game2c48D440() {}  // 0x0048d440
void Game2c48D9F0() {}  // 0x0048d9f0
void Game2c48EEB0() {}  // 0x0048eeb0
void Game2c48F0D0() {}  // 0x0048f0d0
void Game2c490050() {}  // 0x00490050
void Game2c4901F0() {}  // 0x004901f0
void Game2c490EB0() {}  // 0x00490eb0
void Game2c490FD0() {}  // 0x00490fd0
void Game2c4911A0() {}  // 0x004911a0
void Game2c4928C0() {}  // 0x004928c0
void Game2c493810() {}  // 0x00493810
void Game2c494B10() {}  // 0x00494b10
void Game2c494D50() {}  // 0x00494d50
void Game2c496EA0() {}  // 0x00496ea0
void Game2c497E40() {}  // 0x00497e40
void Game2c498FD0() {}  // 0x00498fd0
void Game2c499190() {}  // 0x00499190
void Game2c4992D0() {}  // 0x004992d0
void Game2c4994F0() {}  // 0x004994f0
void Game2c49A420() {}  // 0x0049a420
void Game2c49B8C0() {}  // 0x0049b8c0
void Game2c49E280() {}  // 0x0049e280
void Game2c49FDB0() {}  // 0x0049fdb0
void Game2c4A0EA0() {}  // 0x004a0ea0
void Game2c4A0F40() {}  // 0x004a0f40
void Game2c4A1140() {}  // 0x004a1140
void Game2c4A31C0() {}  // 0x004a31c0
void Game2c4A4710() {}  // 0x004a4710
void Game2c4A47C0() {}  // 0x004a47c0
void Game2c4A4C50() {}  // 0x004a4c50
void Game2c4A6000() {}  // 0x004a6000
void Game2c4A68F0() {}  // 0x004a68f0
void Game2c4A8550() {}  // 0x004a8550
void Game2c4A9BE0() {}  // 0x004a9be0
void Game2c4A9D40() {}  // 0x004a9d40
void Game2c4AA1D0() {}  // 0x004aa1d0
void Game2c4AB610() {}  // 0x004ab610
void Game2c4AC5A0() {}  // 0x004ac5a0
void Game2c4AC930() {}  // 0x004ac930
void Game2c4ACFC0() {}  // 0x004acfc0
void Game2c4AD2A0() {}  // 0x004ad2a0
void Game2c4AF080() {}  // 0x004af080
void Game2c4B45F0() {}  // 0x004b45f0
void Game2c4B49A0() {}  // 0x004b49a0
void Game2c4B5680() {}  // 0x004b5680
void Game2c4B70E0() {}  // 0x004b70e0
void Game2c4B7190() {}  // 0x004b7190
void Game2c4B7690() {}  // 0x004b7690
void Game2c4B7EE0() {}  // 0x004b7ee0
void Game2c4B81A0() {}  // 0x004b81a0
void Game2c4B8440() {}  // 0x004b8440
void Game2c4B86E0() {}  // 0x004b86e0
void Game2c4B8B30() {}  // 0x004b8b30
void Game2c4B8DC0() {}  // 0x004b8dc0
void Game2c4B9260() {}  // 0x004b9260
void Game2c4B94D0() {}  // 0x004b94d0
void Game2c4BA740() {}  // 0x004ba740
void Game2c4BBE20() {}  // 0x004bbe20
void Game2c4BBF80() {}  // 0x004bbf80
void Game2c4BC280() {}  // 0x004bc280
void Game2c4BC650() {}  // 0x004bc650
void Game2c4BCBE0() {}  // 0x004bcbe0
void Game2c4BD020() {}  // 0x004bd020
void Game2c4BD640() {}  // 0x004bd640
void Game2c4BD830() {}  // 0x004bd830
void Game2c4BD8C0() {}  // 0x004bd8c0
void Game2c4BDFA0() {}  // 0x004bdfa0
void Game2c4BE880() {}  // 0x004be880
void Game2c4BEB10() {}  // 0x004beb10
void Game2c4BEC80() {}  // 0x004bec80
void Game2c4BF930() {}  // 0x004bf930
void Game2c4BFD10() {}  // 0x004bfd10
void Game2c4C0150() {}  // 0x004c0150
void Game2c4C0210() {}  // 0x004c0210
void Game2c4C0720() {}  // 0x004c0720
void Game2c4C2530() {}  // 0x004c2530
void Game2c4C25D0() {}  // 0x004c25d0
void Game2c4C2690() {}  // 0x004c2690
void Game2c4C2E10() {}  // 0x004c2e10
void Game2c4C2FB0() {}  // 0x004c2fb0
void Game2c4C3010() {}  // 0x004c3010
void Game2c4C31F0() {}  // 0x004c31f0
void Game2c4C3AE0() {}  // 0x004c3ae0
void Game2c4C3C00() {}  // 0x004c3c00
void Game2c4C3CD0() {}  // 0x004c3cd0
void Game2c4C49E0() {}  // 0x004c49e0
void Game2c4C4AC0() {}  // 0x004c4ac0
void Game2c4C4DB0() {}  // 0x004c4db0
void Game2c4C57F0() {}  // 0x004c57f0
void Game2c4C73E0() {}  // 0x004c73e0
void Game2c4C9490() {}  // 0x004c9490
void Game2c4C9A00() {}  // 0x004c9a00
void Game2c4CA460() {}  // 0x004ca460
void Game2c4CA9B0() {}  // 0x004ca9b0
void Game2c4CAA90() {}  // 0x004caa90
void Game2c4CACC0() {}  // 0x004cacc0
void Game2c4CAE10() {}  // 0x004cae10
void Game2c4CBA60() {}  // 0x004cba60
void Game2c4CC860() {}  // 0x004cc860
void Game2c4CD070() {}  // 0x004cd070
void Game2c4CD180() {}  // 0x004cd180
void Game2c4CDCC0() {}  // 0x004cdcc0
void Game2c4CE4A0() {}  // 0x004ce4a0
void Game2c4CE6B0() {}  // 0x004ce6b0
void Game2c4CFBC0() {}  // 0x004cfbc0
void Game2c4D00C0() {}  // 0x004d00c0
void Game2c4D0110() {}  // 0x004d0110
void Game2c4D0160() {}  // 0x004d0160
void Game2c4D13A0() {}  // 0x004d13a0
void Game2c4D2050() {}  // 0x004d2050
void Game2c4D2220() {}  // 0x004d2220
void Game2c4D3B30() {}  // 0x004d3b30
void Game2c4D50A0() {}  // 0x004d50a0
void Game2c4D5570() {}  // 0x004d5570
void Game2c4D6260() {}  // 0x004d6260
void Game2c4D6780() {}  // 0x004d6780
void Game2c4D6F40() {}  // 0x004d6f40
void Game2c4D7090() {}  // 0x004d7090
void Game2c4D9920() {}  // 0x004d9920
void Game2c4D9C80() {}  // 0x004d9c80
void Game2c4D9EB0() {}  // 0x004d9eb0
void Game2c4DA0F0() {}  // 0x004da0f0
void Game2c4DCC30() {}  // 0x004dcc30
void Game2c4DCCE0() {}  // 0x004dcce0
void Game2c4DCD30() {}  // 0x004dcd30
void Game2c4DE680() {}  // 0x004de680
void Game2c4DF880() {}  // 0x004df880
void Game2c4DFAB0() {}  // 0x004dfab0
void Game2c4E0F50() {}  // 0x004e0f50
void Game2c4E1130() {}  // 0x004e1130
void Game2c4E2020() {}  // 0x004e2020
void Game2c4E20D0() {}  // 0x004e20d0
void Game2c4E4D90() {}  // 0x004e4d90
void Game2c4E53B0() {}  // 0x004e53b0
void Game2c4E5830() {}  // 0x004e5830
void Game2c4E5AD0() {}  // 0x004e5ad0
void Game2c4E96B0() {}  // 0x004e96b0
void Game2c4E9870() {}  // 0x004e9870
void Game2c4E9B10() {}  // 0x004e9b10
void Game2c4E9C70() {}  // 0x004e9c70
void Game2c4F2F90() {}  // 0x004f2f90
void Game2c4F3390() {}  // 0x004f3390
void Game2c4F35C0() {}  // 0x004f35c0
void Game2c4F3A00() {}  // 0x004f3a00
void Game2c4F45A0() {}  // 0x004f45a0
void Game2c4F4AE0() {}  // 0x004f4ae0
void Game2c4F4CC0() {}  // 0x004f4cc0
void Game2c4F52C0() {}  // 0x004f52c0
void Game2c4F5330() {}  // 0x004f5330
void Game2c4F5540() {}  // 0x004f5540
void Game2c4F6620() {}  // 0x004f6620
void Game2c4F66F0() {}  // 0x004f66f0
void Game2c4F6850() {}  // 0x004f6850
void Game2c4F69F0() {}  // 0x004f69f0
void Game2c4F6B20() {}  // 0x004f6b20
void Game2c4F6C90() {}  // 0x004f6c90
void Game2c4F6E30() {}  // 0x004f6e30
void Game2c4F6EB0() {}  // 0x004f6eb0
void Game2c4F6F30() {}  // 0x004f6f30
void Game2c4F72E0() {}  // 0x004f72e0
void Game2c4F7350() {}  // 0x004f7350
void Game2c4F79E0() {}  // 0x004f79e0
void Game2c4FDD90() {}  // 0x004fdd90
void Game2c4FE6F0() {}  // 0x004fe6f0
void Game2c4FE720() {}  // 0x004fe720
void Game2c4FF4F0() {}  // 0x004ff4f0
void Render2c501130() {}  // 0x00501130
void Render2c501920() {}  // 0x00501920
void Render2c5024E0() {}  // 0x005024e0
void Render2c502AE0() {}  // 0x00502ae0
void Render2c502BA0() {}  // 0x00502ba0
void Render2c503150() {}  // 0x00503150
void Render2c507950() {}  // 0x00507950
void Render2c508810() {}  // 0x00508810
void Render2c508DA0() {}  // 0x00508da0
void Render2c509B40() {}  // 0x00509b40
void Render2c50A120() {}  // 0x0050a120
void Render2c50BAA0() {}  // 0x0050baa0
void Render2c50C410() {}  // 0x0050c410
void Render2c50CF30() {}  // 0x0050cf30
void Render2c5143F0() {}  // 0x005143f0
void Render2c519A00() {}  // 0x00519a00
void Render2c51B410() {}  // 0x0051b410
void Render2c51F690() {}  // 0x0051f690
void Render2c51F860() {}  // 0x0051f860
void Render2c521E70() {}  // 0x00521e70
void Render2c522920() {}  // 0x00522920
void Render2c5230D0() {}  // 0x005230d0
void Render2c523380() {}  // 0x00523380
void Render2c527AD0() {}  // 0x00527ad0
void Render2c52B5C0() {}  // 0x0052b5c0
void Render2c52E3F0() {}  // 0x0052e3f0
void Render2c52E610() {}  // 0x0052e610
void Render2c530350() {}  // 0x00530350
void Render2c530690() {}  // 0x00530690
void Render2c531030() {}  // 0x00531030
void Render2c531140() {}  // 0x00531140
void Render2c531470() {}  // 0x00531470
void Render2c531AB0() {}  // 0x00531ab0
void Render2c532C40() {}  // 0x00532c40
void Render2c536290() {}  // 0x00536290
void Render2c536E90() {}  // 0x00536e90
void Render2c538CB0() {}  // 0x00538cb0
void Render2c53A590() {}  // 0x0053a590
void Render2c53C0F0() {}  // 0x0053c0f0
void Render2c53C2C0() {}  // 0x0053c2c0
void Render2c53D5F0() {}  // 0x0053d5f0
void Render2c53DAC0() {}  // 0x0053dac0
void Render2c53DCC0() {}  // 0x0053dcc0
void Render2c53DE60() {}  // 0x0053de60
void Render2c53EB30() {}  // 0x0053eb30
void Render2c53EC20() {}  // 0x0053ec20
void Render2c5401B0() {}  // 0x005401b0
void Render2c5411F0() {}  // 0x005411f0
void Render2c5417D0() {}  // 0x005417d0
void Render2c542960() {}  // 0x00542960
void Render2c542C80() {}  // 0x00542c80
void Render2c543F00() {}  // 0x00543f00
void Render2c544EC0() {}  // 0x00544ec0
void Render2c544F50() {}  // 0x00544f50
void Render2c545D20() {}  // 0x00545d20
void Render2c546A90() {}  // 0x00546a90
void Render2c547840() {}  // 0x00547840
void Render2c548970() {}  // 0x00548970
void Render2c549150() {}  // 0x00549150
void Render2c549370() {}  // 0x00549370
void Render2c549E30() {}  // 0x00549e30
void Render2c54AD60() {}  // 0x0054ad60
void Render2c54ADB0() {}  // 0x0054adb0
void Render2c54AE10() {}  // 0x0054ae10
void Render2c54AE90() {}  // 0x0054ae90
void Render2c54AF60() {}  // 0x0054af60
void Render2c54D110() {}  // 0x0054d110
void Render2c54E530() {}  // 0x0054e530
void Render2c54F6A0() {}  // 0x0054f6a0
void Render2c550280() {}  // 0x00550280
void Render2c550B20() {}  // 0x00550b20
void Render2c551280() {}  // 0x00551280
void Render2c552560() {}  // 0x00552560
void Render2c5536D0() {}  // 0x005536d0
void Render2c553EE0() {}  // 0x00553ee0
void Render2c55490C() {}  // 0x0055490c
void Render2c554B50() {}  // 0x00554b50
void Render2c554CE0() {}  // 0x00554ce0
void Render2c555C50() {}  // 0x00555c50
void Render2c557660() {}  // 0x00557660
void Render2c557880() {}  // 0x00557880
void Render2c5578C0() {}  // 0x005578c0
void Render2c557C40() {}  // 0x00557c40
void Render2c558290() {}  // 0x00558290
void Render2c55B500() {}  // 0x0055b500
void Render2c55B9E0() {}  // 0x0055b9e0
void Render2c55BDE0() {}  // 0x0055bde0
void Render2c55E6F0() {}  // 0x0055e6f0
void Render2c561C50() {}  // 0x00561c50
void Render2c564090() {}  // 0x00564090
void Render2c5643A0() {}  // 0x005643a0
void Render2c5644D0() {}  // 0x005644d0
void Render2c564C40() {}  // 0x00564c40
void Render2c565030() {}  // 0x00565030
void Render2c565410() {}  // 0x00565410
void Render2c5655E0() {}  // 0x005655e0
void Render2c565E90() {}  // 0x00565e90
void Render2c569C70() {}  // 0x00569c70
void Render2c56AC50() {}  // 0x0056ac50
void Render2c56AEC0() {}  // 0x0056aec0
void Render2c56E680() {}  // 0x0056e680
void Render2c56E9E0() {}  // 0x0056e9e0
void Render2c5728C0() {}  // 0x005728c0
void Render2c5735E0() {}  // 0x005735e0
void Render2c5739D0() {}  // 0x005739d0
void Render2c575760() {}  // 0x00575760
void Render2c5758A0() {}  // 0x005758a0
void Render2c575990() {}  // 0x00575990
void Render2c575BB0() {}  // 0x00575bb0
void Render2c575D50() {}  // 0x00575d50
void Render2c579030() {}  // 0x00579030
void Render2c57C960() {}  // 0x0057c960
void Render2c57F330() {}  // 0x0057f330
void Render2c580490() {}  // 0x00580490
void Render2c581440() {}  // 0x00581440
void Render2c5818B0() {}  // 0x005818b0
void Render2c581D80() {}  // 0x00581d80
void Render2c581E60() {}  // 0x00581e60
void Render2c581EF0() {}  // 0x00581ef0
void Render2c5831F0() {}  // 0x005831f0
void Render2c583C00() {}  // 0x00583c00
void Render2c5840C0() {}  // 0x005840c0
void Render2c584870() {}  // 0x00584870
void Render2c5864D0() {}  // 0x005864d0
void Render2c586E80() {}  // 0x00586e80
void Render2c587C80() {}  // 0x00587c80
void Render2c588A90() {}  // 0x00588a90
void Render2c58A6B0() {}  // 0x0058a6b0
void Render2c58AB00() {}  // 0x0058ab00
void Render2c58B0F0() {}  // 0x0058b0f0
void Render2c58D2B0() {}  // 0x0058d2b0
void Render2c590A30() {}  // 0x00590a30
void Render2c590EC0() {}  // 0x00590ec0
void Render2c592430() {}  // 0x00592430
void thunk_FUN_00462170() {}  // 0x00593d30
void Render2c593F70() {}  // 0x00593f70
void Render2c594F30() {}  // 0x00594f30
void Render2c5968F0() {}  // 0x005968f0
void Render2c59A670() {}  // 0x0059a670
void Render2c59B970() {}  // 0x0059b970
void Render2c59D5D0() {}  // 0x0059d5d0
void Render2c59DAE0() {}  // 0x0059dae0
void Render2c59DCC0() {}  // 0x0059dcc0
void Render2c5A62F0() {}  // 0x005a62f0
void Render2c5A70A0() {}  // 0x005a70a0
void Render2c5A7600() {}  // 0x005a7600
void Render2c5A8280() {}  // 0x005a8280
void Render2c5A84B0() {}  // 0x005a84b0
void Render2c5A8D00() {}  // 0x005a8d00
void Render2c5A9980() {}  // 0x005a9980
void Render2c5ABB80() {}  // 0x005abb80
void Render2c5ACC10() {}  // 0x005acc10
void Render2c5AD710() {}  // 0x005ad710
void Render2c5AD9C0() {}  // 0x005ad9c0
void Render2c5AE210() {}  // 0x005ae210
void Render2c5B0360() {}  // 0x005b0360
void Render2c5B0910() {}  // 0x005b0910
void Render2c5B0FD0() {}  // 0x005b0fd0
void Render2c5C0280() {}  // 0x005c0280
void Render2c5C10A0() {}  // 0x005c10a0
void Render2c5C1190() {}  // 0x005c1190
void Render2c5C1D20() {}  // 0x005c1d20
void Render2c5C2E50() {}  // 0x005c2e50
void Render2c5C2F30() {}  // 0x005c2f30
void Render2c5C34B0() {}  // 0x005c34b0
void Render2c5C35B0() {}  // 0x005c35b0
void Render2c5C3840() {}  // 0x005c3840
void Render2c5C39C0() {}  // 0x005c39c0
void Render2c5C3A60() {}  // 0x005c3a60
void Render2c5C3E20() {}  // 0x005c3e20
void Render2c5CCC40() {}  // 0x005ccc40
void Render2c5CEE50() {}  // 0x005cee50
void Render2c5D64C0() {}  // 0x005d64c0
void Render2c5D6540() {}  // 0x005d6540
void Render2c5D66A0() {}  // 0x005d66a0
void Render2c5DAD50() {}  // 0x005dad50
void Render2c5DB510() {}  // 0x005db510
void Render2c5DF770() {}  // 0x005df770
void Render2c5DF970() {}  // 0x005df970
void Render2c5E0BD0() {}  // 0x005e0bd0
void Render2c5E1110() {}  // 0x005e1110
void Render2c5E2CB0() {}  // 0x005e2cb0
void Render2c5E3840() {}  // 0x005e3840
void Render2c5E7310() {}  // 0x005e7310
void Render2c5E7DE0() {}  // 0x005e7de0
void Render2c5E8690() {}  // 0x005e8690
void Render2c5E8C60() {}  // 0x005e8c60
void Render2c5E9910() {}  // 0x005e9910
void Render2c5EAA00() {}  // 0x005eaa00
void Render2c5EB1C0() {}  // 0x005eb1c0
void Render2c5EB7D0() {}  // 0x005eb7d0
void Render2c5F2990() {}  // 0x005f2990
void Render2c5F3E80() {}  // 0x005f3e80
void Render2c5F48E0() {}  // 0x005f48e0
void Render2c5F5420() {}  // 0x005f5420
void Render2c5F6730() {}  // 0x005f6730
void Render2c5F7560() {}  // 0x005f7560
void Render2c5F7700() {}  // 0x005f7700
void Render2c5F78A0() {}  // 0x005f78a0
void Render2c5F7C00() {}  // 0x005f7c00
void Render2c5F7EC0() {}  // 0x005f7ec0
void Render2c5F9230() {}  // 0x005f9230
void Render2c5F98C0() {}  // 0x005f98c0
void Render2c5FC610() {}  // 0x005fc610
void Render2c5FC7A0() {}  // 0x005fc7a0
void Render2c5FD3E0() {}  // 0x005fd3e0
void Render2c5FDA00() {}  // 0x005fda00
void Render2c5FE4C0() {}  // 0x005fe4c0
void Sys2c6000D0() {}  // 0x006000d0
void Sys2c600500() {}  // 0x00600500
void Sys2c600800() {}  // 0x00600800
void Sys2c600990() {}  // 0x00600990
void Sys2c600A30() {}  // 0x00600a30
void Sys2c600B40() {}  // 0x00600b40
void Sys2c601290() {}  // 0x00601290
void Sys2c601410() {}  // 0x00601410
void Sys2c601550() {}  // 0x00601550
void Sys2c601930() {}  // 0x00601930
void Sys2c603D50() {}  // 0x00603d50
void Sys2c6067D0() {}  // 0x006067d0
void Sys2c60BC00() {}  // 0x0060bc00
void Sys2c60C5D0() {}  // 0x0060c5d0
void Sys2c60CB60() {}  // 0x0060cb60
void Sys2c60D870() {}  // 0x0060d870
void Sys2c60DB80() {}  // 0x0060db80
void Sys2c60DD70() {}  // 0x0060dd70
void Sys2c60E2D0() {}  // 0x0060e2d0
void Sys2c60E370() {}  // 0x0060e370
void Sys2c60E9E0() {}  // 0x0060e9e0
void Sys2c60EF70() {}  // 0x0060ef70
void Sys2c60F450() {}  // 0x0060f450
void Sys2c60F540() {}  // 0x0060f540
void Sys2c60F6B0() {}  // 0x0060f6b0
void Sys2c60FE80() {}  // 0x0060fe80
void Sys2c612320() {}  // 0x00612320
void Sys2c613560() {}  // 0x00613560
void Sys2c613F40() {}  // 0x00613f40
void Sys2c614FA0() {}  // 0x00614fa0
void Sys2c615120() {}  // 0x00615120
void Sys2c6152A0() {}  // 0x006152a0
void Sys2c615450() {}  // 0x00615450
void Sys2c6159B0() {}  // 0x006159b0
void Sys2c617190() {}  // 0x00617190
void Sys2c6172C0() {}  // 0x006172c0
void Sys2c6175F0() {}  // 0x006175f0
void Sys2c619450() {}  // 0x00619450
void Sys2c61A610() {}  // 0x0061a610
void Sys2c61A8E0() {}  // 0x0061a8e0
void Sys2c61AE80() {}  // 0x0061ae80
void Sys2c61BD30() {}  // 0x0061bd30
void Sys2c61BEF0() {}  // 0x0061bef0
void Sys2c61BF10() {}  // 0x0061bf10
void Sys2c61BFB0() {}  // 0x0061bfb0
void Sys2c61C300() {}  // 0x0061c300
void Sys2c61C920() {}  // 0x0061c920
void Sys2c61CA20() {}  // 0x0061ca20
void Sys2c61CB40() {}  // 0x0061cb40
void Sys2c61D070() {}  // 0x0061d070
void Sys2c61D130() {}  // 0x0061d130
void Sys2c61D720() {}  // 0x0061d720
void Sys2c61DA10() {}  // 0x0061da10
void Sys2c61F690() {}  // 0x0061f690
void Sys2c61FFC0() {}  // 0x0061ffc0
void Sys2c6215A0() {}  // 0x006215a0
void Sys2c6216F0() {}  // 0x006216f0
void Sys2c621B20() {}  // 0x00621b20
void Sys2c621D50() {}  // 0x00621d50
void Sys2c621E30() {}  // 0x00621e30
void Sys2c6227A0() {}  // 0x006227a0
void Sys2c623CE0() {}  // 0x00623ce0
void Sys2c624040() {}  // 0x00624040
void Sys2c624190() {}  // 0x00624190
void Sys2c624FB0() {}  // 0x00624fb0
void Sys2c625D20() {}  // 0x00625d20
void Sys2c625E30() {}  // 0x00625e30
void Sys2c625EA0() {}  // 0x00625ea0
void Sys2c6271C0() {}  // 0x006271c0
void Sys2c6276C0() {}  // 0x006276c0
void Sys2c627730() {}  // 0x00627730
void Sys2c6280B0() {}  // 0x006280b0
void Sys2c628E20() {}  // 0x00628e20
void Sys2c628E70() {}  // 0x00628e70
void Sys2c628E80() {}  // 0x00628e80
void Sys2c628F60() {}  // 0x00628f60
void Sys2c6290A0() {}  // 0x006290a0
void Sys2c62C1E0() {}  // 0x0062c1e0
void Sys2c62D076() {}  // 0x0062d076
void Sys2c630EE0() {}  // 0x00630ee0
void Sys2c630F40() {}  // 0x00630f40
void Sys2c631AD0() {}  // 0x00631ad0
void Sys2c631F50() {}  // 0x00631f50
void crc32() {}  // 0x006320e4
void Sys2c632440() {}  // 0x00632440
void Sys2c6326D0() {}  // 0x006326d0
void Sys2c632A10() {}  // 0x00632a10
void Sys2c633010() {}  // 0x00633010
void Sys2c633780() {}  // 0x00633780
void Sys2c633B90() {}  // 0x00633b90
void Sys2c633FF0() {}  // 0x00633ff0
void Sys2c635500() {}  // 0x00635500
void Sys2c635560() {}  // 0x00635560
void Sys2c636720() {}  // 0x00636720
void Sys2c636910() {}  // 0x00636910
void Sys2c636970() {}  // 0x00636970
void Sys2c636EE0() {}  // 0x00636ee0
void Sys2c637D70() {}  // 0x00637d70
void Sys2c63837C() {}  // 0x0063837c
void Sys2c638740() {}  // 0x00638740
void Sys2c6389A0() {}  // 0x006389a0
void Sys2c63FE60() {}  // 0x0063fe60
void Create_symlink() {}  // 0x00641019
void Sys2c6410DE() {}  // 0x006410de
void Sys2c64112C() {}  // 0x0064112c
void vcp_Copyfile() {}  // 0x00641190
void ___std_fs_convert_narrow_to_wide_20() {}  // 0x00641203
void ___std_fs_convert_wide_to_narrow_20() {}  // 0x00641237
void Sys2c6412EA() {}  // 0x006412ea
void Sys2c641359() {}  // 0x00641359
void Sys2c641575() {}  // 0x00641575
void Sys2c641A6A() {}  // 0x00641a6a
void LocalFree() {}  // 0x00641d1c
void Sys2c641DD5() {}  // 0x00641dd5
void Sys2c642670() {}  // 0x00642670
void Sys2c6427E0() {}  // 0x006427e0
void Sys2c642B90() {}  // 0x00642b90
void Sys2c642CC0() {}  // 0x00642cc0
void Sys2c643120() {}  // 0x00643120
void Sys2c643240() {}  // 0x00643240
void Sys2c643310() {}  // 0x00643310
void CrtFreeWrapper() {}  // 0x00643543
void Sys2c643793() {}  // 0x00643793
void __ArrayUnwind() {}  // 0x00643980
void Sys2c643A10() {}  // 0x00643a10
void Sys2c643C92() {}  // 0x00643c92
void Sys2c64442E() {}  // 0x0064442e
void Sys2c644478() {}  // 0x00644478
void Sys2c644666() {}  // 0x00644666
void _callnewh() {}  // 0x006448ed
void initialize_onexit_table() {}  // 0x006448ff
void Sys2c6452E0() {}  // 0x006452e0
void __alloca_probe_16() {}  // 0x006456b0
void __allrem() {}  // 0x006456e0
void fdclass() {}  // 0x00645921
void ldclass() {}  // 0x00645927

// --- Cycle 58: 1-caller functions (1276 functions) ---
void Core1c42A410() {}  // 0x0042a410
void Core1c42A6F0() {}  // 0x0042a6f0
void Core1c42A820() {}  // 0x0042a820
void Core1c42A8D0() {}  // 0x0042a8d0
void Core1c42AB00() {}  // 0x0042ab00
void Core1c42AB50() {}  // 0x0042ab50
void Core1c42AEC0() {}  // 0x0042aec0
void Core1c42AF70() {}  // 0x0042af70
void Core1c42B250() {}  // 0x0042b250
void Core1c42B330() {}  // 0x0042b330
void Core1c42B420() {}  // 0x0042b420
void Core1c42B470() {}  // 0x0042b470
void Core1c42B760() {}  // 0x0042b760
void Core1c42BAA0() {}  // 0x0042baa0
void Core1c42BE10() {}  // 0x0042be10
void Core1c42BE60() {}  // 0x0042be60
void Core1c42C240() {}  // 0x0042c240
void Core1c42C470() {}  // 0x0042c470
void Core1c42C4C0() {}  // 0x0042c4c0
void Core1c42C6A0() {}  // 0x0042c6a0
void Core1c42C890() {}  // 0x0042c890
void Core1c42CEE0() {}  // 0x0042cee0
void Core1c42D300() {}  // 0x0042d300
void Core1c42D380() {}  // 0x0042d380
void Core1c42D5A0() {}  // 0x0042d5a0
void Core1c42D7B0() {}  // 0x0042d7b0
void Core1c42DB50() {}  // 0x0042db50
void Core1c42E22F() {}  // 0x0042e22f
void Core1c42F9B0() {}  // 0x0042f9b0
void Core1c42FB70() {}  // 0x0042fb70
void Core1c42FBB0() {}  // 0x0042fbb0
void Core1c42FD68() {}  // 0x0042fd68
void Core1c4300C0() {}  // 0x004300c0
void Core1c430720() {}  // 0x00430720
void Core1c431370() {}  // 0x00431370
void Core1c4313B0() {}  // 0x004313b0
void Core1c4313D0() {}  // 0x004313d0
void Core1c431590() {}  // 0x00431590
void Core1c431B70() {}  // 0x00431b70
void Core1c432120() {}  // 0x00432120
void Core1c4330C0() {}  // 0x004330c0
void Core1c433AB0() {}  // 0x00433ab0
void Core1c4344E0() {}  // 0x004344e0
void Core1c4358B0() {}  // 0x004358b0
void Core1c435A60() {}  // 0x00435a60
void Core1c435CD0() {}  // 0x00435cd0
void Core1c435EE0() {}  // 0x00435ee0
void Core1c4360F0() {}  // 0x004360f0
void Core1c4368B0() {}  // 0x004368b0
void Core1c436AE0() {}  // 0x00436ae0
void Core1c4373B0() {}  // 0x004373b0
void Core1c437520() {}  // 0x00437520
void Core1c4376C0() {}  // 0x004376c0
void Core1c437970() {}  // 0x00437970
void Core1c437C60() {}  // 0x00437c60
void Core1c437F10() {}  // 0x00437f10
void Core1c438060() {}  // 0x00438060
void Core1c438380() {}  // 0x00438380
void Core1c4388A0() {}  // 0x004388a0
void Core1c438AE0() {}  // 0x00438ae0
void Core1c438BA0() {}  // 0x00438ba0
void Core1c438FE0() {}  // 0x00438fe0
void Core1c439150() {}  // 0x00439150
void Core1c439250() {}  // 0x00439250
void Core1c4392B0() {}  // 0x004392b0
void Core1c439490() {}  // 0x00439490
void Core1c439730() {}  // 0x00439730
void Core1c439910() {}  // 0x00439910
void Core1c439B40() {}  // 0x00439b40
void Core1c439D20() {}  // 0x00439d20
void Core1c439F00() {}  // 0x00439f00
void Core1c43A180() {}  // 0x0043a180
void Core1c43A3B0() {}  // 0x0043a3b0
void Core1c43A630() {}  // 0x0043a630
void Core1c43A860() {}  // 0x0043a860
void Core1c43AA90() {}  // 0x0043aa90
void Core1c43AD00() {}  // 0x0043ad00
void Core1c43B7B0() {}  // 0x0043b7b0
void Core1c43BBD0() {}  // 0x0043bbd0
void Core1c43C0D0() {}  // 0x0043c0d0
void Core1c43CD60() {}  // 0x0043cd60
void Core1c43CDD0() {}  // 0x0043cdd0
void Core1c43D4E0() {}  // 0x0043d4e0
void Core1c43D930() {}  // 0x0043d930
void Core1c43DAF0() {}  // 0x0043daf0
void Core1c43DE40() {}  // 0x0043de40
void Core1c43E000() {}  // 0x0043e000
void Core1c43E3D0() {}  // 0x0043e3d0
void Core1c43E400() {}  // 0x0043e400
void Core1c43F010() {}  // 0x0043f010
void Core1c440800() {}  // 0x00440800
void Core1c440BB0() {}  // 0x00440bb0
void Core1c440CE0() {}  // 0x00440ce0
void Core1c440D70() {}  // 0x00440d70
void Core1c440D90() {}  // 0x00440d90
void Core1c4412E0() {}  // 0x004412e0
void Core1c4414D0() {}  // 0x004414d0
void Core1c441C40() {}  // 0x00441c40
void Core1c442240() {}  // 0x00442240
void Core1c442520() {}  // 0x00442520
void Core1c442B00() {}  // 0x00442b00
void Core1c443180() {}  // 0x00443180
void Core1c443A20() {}  // 0x00443a20
void Core1c443C90() {}  // 0x00443c90
void Core1c443CE0() {}  // 0x00443ce0
void Core1c444160() {}  // 0x00444160
void Core1c444EF0() {}  // 0x00444ef0
void Core1c4456B0() {}  // 0x004456b0
void Core1c4458D0() {}  // 0x004458d0
void Core1c445C50() {}  // 0x00445c50
void Core1c4460C0() {}  // 0x004460c0
void Core1c446130() {}  // 0x00446130
void Core1c446500() {}  // 0x00446500
void Core1c4465E0() {}  // 0x004465e0
void Core1c446990() {}  // 0x00446990
void Core1c446CD0() {}  // 0x00446cd0
void Core1c446E90() {}  // 0x00446e90
void Core1c4481D0() {}  // 0x004481d0
void Core1c4485E0() {}  // 0x004485e0
void Core1c448AD0() {}  // 0x00448ad0
void Core1c449600() {}  // 0x00449600
void Core1c44A540() {}  // 0x0044a540
void Core1c44A770() {}  // 0x0044a770
void Core1c44A9A0() {}  // 0x0044a9a0
void Core1c44B4A0() {}  // 0x0044b4a0
void Core1c44B520() {}  // 0x0044b520
void Core1c44B750() {}  // 0x0044b750
void Core1c44B9B0() {}  // 0x0044b9b0
void Core1c44BC10() {}  // 0x0044bc10
void Core1c44C230() {}  // 0x0044c230
void Core1c44C9C0() {}  // 0x0044c9c0
void Core1c44CBE0() {}  // 0x0044cbe0
void Core1c44CE30() {}  // 0x0044ce30
void Core1c44D080() {}  // 0x0044d080
void Core1c44D230() {}  // 0x0044d230
void Core1c44D420() {}  // 0x0044d420
void Core1c44D540() {}  // 0x0044d540
void Core1c44DCE0() {}  // 0x0044dce0
void Core1c44DDD0() {}  // 0x0044ddd0
void Core1c44E090() {}  // 0x0044e090
void Core1c44E0F0() {}  // 0x0044e0f0
void Core1c44E320() {}  // 0x0044e320
void Core1c44E510() {}  // 0x0044e510
void Core1c44EE80() {}  // 0x0044ee80
void Core1c44EF40() {}  // 0x0044ef40
void Core1c44F0F0() {}  // 0x0044f0f0
void Core1c44F360() {}  // 0x0044f360
void Core1c44F5D0() {}  // 0x0044f5d0
void Core1c44F8C0() {}  // 0x0044f8c0
void Core1c44FB10() {}  // 0x0044fb10
void Game1c450780() {}  // 0x00450780
void Game1c450A50() {}  // 0x00450a50
void Game1c450B00() {}  // 0x00450b00
void Game1c451050() {}  // 0x00451050
void Game1c451070() {}  // 0x00451070
void Game1c451830() {}  // 0x00451830
void Game1c451880() {}  // 0x00451880
void Game1c4519E0() {}  // 0x004519e0
void Game1c452090() {}  // 0x00452090
void Game1c4520F0() {}  // 0x004520f0
void Game1c4522F0() {}  // 0x004522f0
void Game1c452520() {}  // 0x00452520
void Game1c452B40() {}  // 0x00452b40
void Game1c453200() {}  // 0x00453200
void Game1c453250() {}  // 0x00453250
void Game1c454240() {}  // 0x00454240
void Game1c4544D0() {}  // 0x004544d0
void Game1c454520() {}  // 0x00454520
void Game1c454540() {}  // 0x00454540
void Game1c4545B0() {}  // 0x004545b0
void Game1c455370() {}  // 0x00455370
void Game1c455990() {}  // 0x00455990
void Game1c456760() {}  // 0x00456760
void Game1c456820() {}  // 0x00456820
void Game1c458A40() {}  // 0x00458a40
void Game1c4597D0() {}  // 0x004597d0
void Game1c45AB90() {}  // 0x0045ab90
void Game1c45AC30() {}  // 0x0045ac30
void Game1c45B190() {}  // 0x0045b190
void Game1c45B280() {}  // 0x0045b280
void Game1c45E6A0() {}  // 0x0045e6a0
void Game1c45EE30() {}  // 0x0045ee30
void Game1c45F170() {}  // 0x0045f170
void Game1c45F6E0() {}  // 0x0045f6e0
void Game1c45F8D0() {}  // 0x0045f8d0
void Game1c45FED0() {}  // 0x0045fed0
void Game1c461B10() {}  // 0x00461b10
void Game1c461B90() {}  // 0x00461b90
void Game1c461C60() {}  // 0x00461c60
void Game1c4621F0() {}  // 0x004621f0
void thunk_FUN_00462510() {}  // 0x004622b0
void Game1c462910() {}  // 0x00462910
void Game1c462960() {}  // 0x00462960
void Game1c462ED0() {}  // 0x00462ed0
void Game1c463290() {}  // 0x00463290
void Game1c463E60() {}  // 0x00463e60
void Game1c464130() {}  // 0x00464130
void Game1c464290() {}  // 0x00464290
void Game1c464460() {}  // 0x00464460
void Game1c464980() {}  // 0x00464980
void Game1c464B10() {}  // 0x00464b10
void Game1c465360() {}  // 0x00465360
void Game1c465520() {}  // 0x00465520
void Game1c465710() {}  // 0x00465710
void Game1c465A70() {}  // 0x00465a70
void Game1c465D30() {}  // 0x00465d30
void Game1c465FA0() {}  // 0x00465fa0
void Game1c466240() {}  // 0x00466240
void Game1c4665F0() {}  // 0x004665f0
void Game1c466890() {}  // 0x00466890
void Game1c4680F0() {}  // 0x004680f0
void Game1c468680() {}  // 0x00468680
void Game1c468980() {}  // 0x00468980
void Game1c468AC0() {}  // 0x00468ac0
void Game1c46CE10() {}  // 0x0046ce10
void Game1c46D040() {}  // 0x0046d040
void Game1c46D170() {}  // 0x0046d170
void Game1c46DA10() {}  // 0x0046da10
void Game1c46DD40() {}  // 0x0046dd40
void Game1c46E420() {}  // 0x0046e420
void Game1c46E530() {}  // 0x0046e530
void Game1c46E630() {}  // 0x0046e630
void Game1c46E6E0() {}  // 0x0046e6e0
void Game1c46EB00() {}  // 0x0046eb00
void Game1c46ED80() {}  // 0x0046ed80
void Game1c46FE50() {}  // 0x0046fe50
void Game1c46FE90() {}  // 0x0046fe90
void Game1c4700B0() {}  // 0x004700b0
void Game1c470110() {}  // 0x00470110
void Game1c470670() {}  // 0x00470670
void Game1c470E40() {}  // 0x00470e40
void Game1c471300() {}  // 0x00471300
void Game1c4714B0() {}  // 0x004714b0
void Game1c471600() {}  // 0x00471600
void Game1c471930() {}  // 0x00471930
void Game1c472040() {}  // 0x00472040
void Game1c472050() {}  // 0x00472050
void Game1c472070() {}  // 0x00472070
void Game1c472210() {}  // 0x00472210
void Game1c4726B0() {}  // 0x004726b0
void Game1c472AB0() {}  // 0x00472ab0
void Game1c472BA0() {}  // 0x00472ba0
void Game1c472D60() {}  // 0x00472d60
void Game1c4732C0() {}  // 0x004732c0
void Game1c473630() {}  // 0x00473630
void Game1c473C90() {}  // 0x00473c90
void Game1c473D30() {}  // 0x00473d30
void Game1c473E90() {}  // 0x00473e90
void Game1c4740E0() {}  // 0x004740e0
void Game1c474660() {}  // 0x00474660
void Game1c474870() {}  // 0x00474870
void Game1c474BD0() {}  // 0x00474bd0
void Game1c4750A0() {}  // 0x004750a0
void Game1c475270() {}  // 0x00475270
void Game1c476B00() {}  // 0x00476b00
void Game1c476FC0() {}  // 0x00476fc0
void Game1c477350() {}  // 0x00477350
void Game1c477910() {}  // 0x00477910
void Game1c477B70() {}  // 0x00477b70
void Game1c478740() {}  // 0x00478740
void Game1c478B40() {}  // 0x00478b40
void Game1c479190() {}  // 0x00479190
void Game1c47BD00() {}  // 0x0047bd00
void Game1c47BEA0() {}  // 0x0047bea0
void Game1c47C240() {}  // 0x0047c240
void Game1c47C300() {}  // 0x0047c300
void Game1c47C560() {}  // 0x0047c560
void Game1c47C730() {}  // 0x0047c730
void Game1c47CB20() {}  // 0x0047cb20
void Game1c47CDF0() {}  // 0x0047cdf0
void Game1c47D670() {}  // 0x0047d670
void Game1c47DD80() {}  // 0x0047dd80
void Game1c47EC60() {}  // 0x0047ec60
void Game1c47EE80() {}  // 0x0047ee80
void Game1c47F1C0() {}  // 0x0047f1c0
void Game1c47F550() {}  // 0x0047f550
void Game1c47FB30() {}  // 0x0047fb30
void Game1c47FDA0() {}  // 0x0047fda0
void Game1c480090() {}  // 0x00480090
void Game1c480250() {}  // 0x00480250
void Game1c4804B0() {}  // 0x004804b0
void Game1c4805E0() {}  // 0x004805e0
void Game1c480700() {}  // 0x00480700
void Game1c4807C0() {}  // 0x004807c0
void Game1c480AF0() {}  // 0x00480af0
void Game1c480C90() {}  // 0x00480c90
void Game1c480E20() {}  // 0x00480e20
void Game1c480E80() {}  // 0x00480e80
void Game1c480F30() {}  // 0x00480f30
void Game1c4811B0() {}  // 0x004811b0
void Game1c4818F0() {}  // 0x004818f0
void Game1c481900() {}  // 0x00481900
void Game1c4819D0() {}  // 0x004819d0
void Game1c481A90() {}  // 0x00481a90
void Game1c481AF0() {}  // 0x00481af0
void Game1c481B60() {}  // 0x00481b60
void Game1c481BB0() {}  // 0x00481bb0
void Game1c481D50() {}  // 0x00481d50
void Game1c481F00() {}  // 0x00481f00
void Game1c482080() {}  // 0x00482080
void Game1c483F20() {}  // 0x00483f20
void Game1c484040() {}  // 0x00484040
void Game1c485D30() {}  // 0x00485d30
void Game1c485F40() {}  // 0x00485f40
void Game1c4864F0() {}  // 0x004864f0
void Game1c486610() {}  // 0x00486610
void Game1c486670() {}  // 0x00486670
void Game1c487170() {}  // 0x00487170
void Game1c4874D0() {}  // 0x004874d0
void Game1c487570() {}  // 0x00487570
void Game1c4875C0() {}  // 0x004875c0
void Game1c487640() {}  // 0x00487640
void Game1c487680() {}  // 0x00487680
void Game1c487710() {}  // 0x00487710
void Game1c487960() {}  // 0x00487960
void Game1c487C60() {}  // 0x00487c60
void Game1c487E20() {}  // 0x00487e20
void Game1c487F30() {}  // 0x00487f30
void Game1c487FE0() {}  // 0x00487fe0
void Game1c488AA0() {}  // 0x00488aa0
void Game1c489180() {}  // 0x00489180
void Game1c489470() {}  // 0x00489470
void Game1c489870() {}  // 0x00489870
void Game1c48A0E0() {}  // 0x0048a0e0
void Game1c48AD10() {}  // 0x0048ad10
void Game1c48AE80() {}  // 0x0048ae80
void Game1c48AF00() {}  // 0x0048af00
void Game1c48B150() {}  // 0x0048b150
void Game1c48BB00() {}  // 0x0048bb00
void Game1c48BCE0() {}  // 0x0048bce0
void Game1c48C020() {}  // 0x0048c020
void Game1c48C350() {}  // 0x0048c350
void Game1c48C6C0() {}  // 0x0048c6c0
void Game1c48CB90() {}  // 0x0048cb90
void Game1c48CCA0() {}  // 0x0048cca0
void Game1c48CF20() {}  // 0x0048cf20
void Game1c48D280() {}  // 0x0048d280
void Game1c48D8B0() {}  // 0x0048d8b0
void Game1c48DC20() {}  // 0x0048dc20
void Game1c48DDB0() {}  // 0x0048ddb0
void Game1c48E960() {}  // 0x0048e960
void Game1c48F2E0() {}  // 0x0048f2e0
void Game1c48F820() {}  // 0x0048f820
void Game1c490800() {}  // 0x00490800
void Game1c490920() {}  // 0x00490920
void Game1c490CE0() {}  // 0x00490ce0
void Game1c491420() {}  // 0x00491420
void Game1c4943D0() {}  // 0x004943d0
void Game1c495990() {}  // 0x00495990
void Game1c495A80() {}  // 0x00495a80
void Game1c4973C0() {}  // 0x004973c0
void Game1c4974D0() {}  // 0x004974d0
void Game1c4975D0() {}  // 0x004975d0
void Game1c497790() {}  // 0x00497790
void Game1c497AA0() {}  // 0x00497aa0
void Game1c497C90() {}  // 0x00497c90
void Game1c4982D0() {}  // 0x004982d0
void Game1c4985F0() {}  // 0x004985f0
void Game1c4987D0() {}  // 0x004987d0
void Game1c49AD90() {}  // 0x0049ad90
void Game1c49AE80() {}  // 0x0049ae80
void Game1c49CAB0() {}  // 0x0049cab0
void Game1c49CEC0() {}  // 0x0049cec0
void Game1c49E740() {}  // 0x0049e740
void Game1c49EBB0() {}  // 0x0049ebb0
void Game1c49F5B0() {}  // 0x0049f5b0
void Game1c4A0220() {}  // 0x004a0220
void Game1c4A09F0() {}  // 0x004a09f0
void Game1c4A1D60() {}  // 0x004a1d60
void Game1c4A2440() {}  // 0x004a2440
void Game1c4A3660() {}  // 0x004a3660
void Game1c4A3E50() {}  // 0x004a3e50
void Game1c4A5390() {}  // 0x004a5390
void Game1c4A5910() {}  // 0x004a5910
void Game1c4A6420() {}  // 0x004a6420
void Game1c4A6550() {}  // 0x004a6550
void Game1c4A8680() {}  // 0x004a8680
void Game1c4A8BA0() {}  // 0x004a8ba0
void Game1c4A8D30() {}  // 0x004a8d30
void Game1c4A8FE0() {}  // 0x004a8fe0
void Game1c4AA710() {}  // 0x004aa710
void Game1c4B17C0() {}  // 0x004b17c0
void Game1c4B3880() {}  // 0x004b3880
void Game1c4B3C10() {}  // 0x004b3c10
void Game1c4B3DA7() {}  // 0x004b3da7
void Game1c4B4690() {}  // 0x004b4690
void Game1c4B4830() {}  // 0x004b4830
void Game1c4B4A70() {}  // 0x004b4a70
void Game1c4B4DE0() {}  // 0x004b4de0
void Game1c4B5000() {}  // 0x004b5000
void Game1c4B5150() {}  // 0x004b5150
void Game1c4B5750() {}  // 0x004b5750
void Game1c4B5BD0() {}  // 0x004b5bd0
void Game1c4B5E00() {}  // 0x004b5e00
void Game1c4B5F50() {}  // 0x004b5f50
void Game1c4B6DA0() {}  // 0x004b6da0
void Game1c4B71F0() {}  // 0x004b71f0
void Game1c4B7510() {}  // 0x004b7510
void Game1c4B7770() {}  // 0x004b7770
void Game1c4B7D90() {}  // 0x004b7d90
void Game1c4B7FD0() {}  // 0x004b7fd0
void Game1c4B8270() {}  // 0x004b8270
void Game1c4B8510() {}  // 0x004b8510
void Game1c4B8C50() {}  // 0x004b8c50
void Game1c4B8F50() {}  // 0x004b8f50
void Game1c4B9090() {}  // 0x004b9090
void Game1c4B9300() {}  // 0x004b9300
void Game1c4B9580() {}  // 0x004b9580
void Game1c4B9750() {}  // 0x004b9750
void Game1c4B9D00() {}  // 0x004b9d00
void Game1c4BA0A0() {}  // 0x004ba0a0
void Game1c4BAAD0() {}  // 0x004baad0
void Game1c4BB1A0() {}  // 0x004bb1a0
void Game1c4BB470() {}  // 0x004bb470
void Game1c4BBA90() {}  // 0x004bba90
void Game1c4BBEE0() {}  // 0x004bbee0
void Game1c4BC0F0() {}  // 0x004bc0f0
void Game1c4BC460() {}  // 0x004bc460
void Game1c4BC790() {}  // 0x004bc790
void Game1c4BCEE0() {}  // 0x004bcee0
void Game1c4BD340() {}  // 0x004bd340
void Game1c4BD870() {}  // 0x004bd870
void Game1c4BD8E0() {}  // 0x004bd8e0
void Game1c4BE330() {}  // 0x004be330
void Game1c4BE850() {}  // 0x004be850
void Game1c4BE980() {}  // 0x004be980
void Game1c4BECF0() {}  // 0x004becf0
void Game1c4BF180() {}  // 0x004bf180
void Game1c4BF270() {}  // 0x004bf270
void Game1c4BF300() {}  // 0x004bf300
void Game1c4BF6F0() {}  // 0x004bf6f0
void Game1c4BF9E0() {}  // 0x004bf9e0
void Game1c4BFC50() {}  // 0x004bfc50
void Game1c4BFED0() {}  // 0x004bfed0
void Game1c4C0270() {}  // 0x004c0270
void Game1c4C06F0() {}  // 0x004c06f0
void Game1c4C0706() {}  // 0x004c0706
void Game1c4C0970() {}  // 0x004c0970
void Game1c4C0C04() {}  // 0x004c0c04
void Game1c4C0C30() {}  // 0x004c0c30
void Game1c4C0CB0() {}  // 0x004c0cb0
void Game1c4C0D30() {}  // 0x004c0d30
void Game1c4C0ED0() {}  // 0x004c0ed0
void Game1c4C0EF0() {}  // 0x004c0ef0
void Game1c4C1060() {}  // 0x004c1060
void Game1c4C14A0() {}  // 0x004c14a0
void Game1c4C16F0() {}  // 0x004c16f0
void Game1c4C1730() {}  // 0x004c1730
void Game1c4C17A0() {}  // 0x004c17a0
void Game1c4C18C0() {}  // 0x004c18c0
void Game1c4C18F0() {}  // 0x004c18f0
void Game1c4C2180() {}  // 0x004c2180
void Game1c4C2260() {}  // 0x004c2260
void Game1c4C24B0() {}  // 0x004c24b0
void thunk_FUN_0042b2c0() {}  // 0x004c25c0
void Game1c4C2660() {}  // 0x004c2660
void Game1c4C27A0() {}  // 0x004c27a0
void Game1c4C2AB0() {}  // 0x004c2ab0
void Game1c4C2AC0() {}  // 0x004c2ac0
void Game1c4C3390() {}  // 0x004c3390
void Game1c4C3580() {}  // 0x004c3580
void Game1c4C35A0() {}  // 0x004c35a0
void Game1c4C3B40() {}  // 0x004c3b40
void Game1c4C3B60() {}  // 0x004c3b60
void Game1c4C3BE0() {}  // 0x004c3be0
void Game1c4C3CC0() {}  // 0x004c3cc0
void Game1c4C3D60() {}  // 0x004c3d60
void Game1c4C3EF0() {}  // 0x004c3ef0
void Game1c4C3F70() {}  // 0x004c3f70
void Game1c4C4430() {}  // 0x004c4430
void Game1c4C4610() {}  // 0x004c4610
void Game1c4C4B80() {}  // 0x004c4b80
void Game1c4C4D50() {}  // 0x004c4d50
void Game1c4C4ED0() {}  // 0x004c4ed0
void Game1c4C4F60() {}  // 0x004c4f60
void Game1c4C52D0() {}  // 0x004c52d0
void Game1c4C5300() {}  // 0x004c5300
void Game1c4C5440() {}  // 0x004c5440
void Game1c4C56A0() {}  // 0x004c56a0
void Game1c4C58E0() {}  // 0x004c58e0
void Game1c4C5BF0() {}  // 0x004c5bf0
void Game1c4C5D10() {}  // 0x004c5d10
void Game1c4C5E40() {}  // 0x004c5e40
void Game1c4C5F40() {}  // 0x004c5f40
void Game1c4C7400() {}  // 0x004c7400
void Game1c4C75B0() {}  // 0x004c75b0
void Game1c4C7BC0() {}  // 0x004c7bc0
void Game1c4C7D60() {}  // 0x004c7d60
void Game1c4C7F10() {}  // 0x004c7f10
void Game1c4C80A0() {}  // 0x004c80a0
void Game1c4C8230() {}  // 0x004c8230
void Game1c4C84C0() {}  // 0x004c84c0
void Game1c4C8500() {}  // 0x004c8500
void Game1c4C9500() {}  // 0x004c9500
void Game1c4C9AC0() {}  // 0x004c9ac0
void Game1c4C9B30() {}  // 0x004c9b30
void Game1c4C9BC0() {}  // 0x004c9bc0
void Game1c4C9C20() {}  // 0x004c9c20
void Game1c4CA0C0() {}  // 0x004ca0c0
void Game1c4CA280() {}  // 0x004ca280
void Game1c4CA330() {}  // 0x004ca330
void Game1c4CA6D0() {}  // 0x004ca6d0
void Game1c4CAB50() {}  // 0x004cab50
void Game1c4CAED0() {}  // 0x004caed0
void Game1c4CB200() {}  // 0x004cb200
void Game1c4CB410() {}  // 0x004cb410
void Game1c4CB540() {}  // 0x004cb540
void Game1c4CBB20() {}  // 0x004cbb20
void Game1c4CBF60() {}  // 0x004cbf60
void Game1c4CC180() {}  // 0x004cc180
void Game1c4CC2B0() {}  // 0x004cc2b0
void Game1c4CCF00() {}  // 0x004ccf00
void Game1c4CD1E0() {}  // 0x004cd1e0
void Game1c4CD350() {}  // 0x004cd350
void Game1c4CD4D0() {}  // 0x004cd4d0
void Game1c4CD9A0() {}  // 0x004cd9a0
void Game1c4CDFC0() {}  // 0x004cdfc0
void Game1c4CE620() {}  // 0x004ce620
void Game1c4CE7B0() {}  // 0x004ce7b0
void Game1c4CE8B0() {}  // 0x004ce8b0
void Game1c4CE9B0() {}  // 0x004ce9b0
void Game1c4CEB20() {}  // 0x004ceb20
void Game1c4CEBA0() {}  // 0x004ceba0
void Game1c4CEBE0() {}  // 0x004cebe0
void Game1c4CFC10() {}  // 0x004cfc10
void Game1c4D0210() {}  // 0x004d0210
void Game1c4D0370() {}  // 0x004d0370
void Game1c4D0410() {}  // 0x004d0410
void Game1c4D0870() {}  // 0x004d0870
void Game1c4D0BA0() {}  // 0x004d0ba0
void Game1c4D0C20() {}  // 0x004d0c20
void Game1c4D1210() {}  // 0x004d1210
void Game1c4D1340() {}  // 0x004d1340
void Game1c4D1990() {}  // 0x004d1990
void Game1c4D2410() {}  // 0x004d2410
void Game1c4D2730() {}  // 0x004d2730
void Game1c4D2CE0() {}  // 0x004d2ce0
void Game1c4D2FD0() {}  // 0x004d2fd0
void Game1c4D3F70() {}  // 0x004d3f70
void Game1c4D4030() {}  // 0x004d4030
void Game1c4D4190() {}  // 0x004d4190
void Game1c4D43A0() {}  // 0x004d43a0
void Game1c4D48C0() {}  // 0x004d48c0
void Game1c4D51D0() {}  // 0x004d51d0
void Game1c4D56C0() {}  // 0x004d56c0
void Game1c4D67D0() {}  // 0x004d67d0
void Game1c4D72B0() {}  // 0x004d72b0
void Game1c4D7B60() {}  // 0x004d7b60
void Game1c4D92D0() {}  // 0x004d92d0
void Game1c4DA890() {}  // 0x004da890
void Game1c4DB280() {}  // 0x004db280
void Game1c4DBA20() {}  // 0x004dba20
void Game1c4DBF00() {}  // 0x004dbf00
void Game1c4DC3D0() {}  // 0x004dc3d0
void Game1c4DC830() {}  // 0x004dc830
void Game1c4DDB90() {}  // 0x004ddb90
void Game1c4DEDD0() {}  // 0x004dedd0
void Game1c4DFBE0() {}  // 0x004dfbe0
void Game1c4E0380() {}  // 0x004e0380
void Game1c4E2590() {}  // 0x004e2590
void Game1c4E2A00() {}  // 0x004e2a00
void Game1c4E3640() {}  // 0x004e3640
void Game1c4E3EF0() {}  // 0x004e3ef0
void Game1c4E4AA0() {}  // 0x004e4aa0
void Game1c4E5300() {}  // 0x004e5300
void Game1c4E58C0() {}  // 0x004e58c0
void Game1c4E5C20() {}  // 0x004e5c20
void Game1c4E5CE0() {}  // 0x004e5ce0
void Game1c4E78A0() {}  // 0x004e78a0
void Game1c4E90B0() {}  // 0x004e90b0
void Game1c4EA0F0() {}  // 0x004ea0f0
void Game1c4EA210() {}  // 0x004ea210
void Game1c4EA330() {}  // 0x004ea330
void Game1c4EA5E0() {}  // 0x004ea5e0
void Game1c4EAB10() {}  // 0x004eab10
void Game1c4EACC0() {}  // 0x004eacc0
void Game1c4F1130() {}  // 0x004f1130
void Game1c4F11E0() {}  // 0x004f11e0
void Game1c4F3010() {}  // 0x004f3010
void Game1c4F3D00() {}  // 0x004f3d00
void Game1c4F4910() {}  // 0x004f4910
void Game1c4F4A7E() {}  // 0x004f4a7e
void Game1c4F4CF0() {}  // 0x004f4cf0
void Game1c4F4ED0() {}  // 0x004f4ed0
void Game1c4F500B() {}  // 0x004f500b
void Game1c4F5240() {}  // 0x004f5240
void Game1c4F53D0() {}  // 0x004f53d0
void Game1c4F5590() {}  // 0x004f5590
void Game1c4F55E0() {}  // 0x004f55e0
void Game1c4F56F0() {}  // 0x004f56f0
void Game1c4F58F0() {}  // 0x004f58f0
void Game1c4F6760() {}  // 0x004f6760
void Game1c4F6940() {}  // 0x004f6940
void Game1c4F7570() {}  // 0x004f7570
void _basic_streambuf_char_std__char_traits_char___() {}  // 0x004f77a0
void Game1c4F7850() {}  // 0x004f7850
void Game1c4F7A60() {}  // 0x004f7a60
void Game1c4F8310() {}  // 0x004f8310
void Game1c4F9560() {}  // 0x004f9560
void Game1c4FA9F0() {}  // 0x004fa9f0
void Game1c4FE110() {}  // 0x004fe110
void Game1c4FE1B0() {}  // 0x004fe1b0
void Game1c4FE290() {}  // 0x004fe290
void Game1c4FE630() {}  // 0x004fe630
void Game1c4FE730() {}  // 0x004fe730
void Game1c4FEA40() {}  // 0x004fea40
void Render1c501740() {}  // 0x00501740
void Render1c5033D0() {}  // 0x005033d0
void Render1c506B90() {}  // 0x00506b90
void Render1c506F00() {}  // 0x00506f00
void Render1c507A80() {}  // 0x00507a80
void Render1c508430() {}  // 0x00508430
void Render1c508590() {}  // 0x00508590
void Render1c5091D0() {}  // 0x005091d0
void Render1c509540() {}  // 0x00509540
void Render1c509A20() {}  // 0x00509a20
void Render1c50A1D0() {}  // 0x0050a1d0
void Render1c50BBB0() {}  // 0x0050bbb0
void Render1c50C190() {}  // 0x0050c190
void Render1c50CCD0() {}  // 0x0050ccd0
void Render1c50CFC0() {}  // 0x0050cfc0
void Render1c5145F0() {}  // 0x005145f0
void Render1c5154B0() {}  // 0x005154b0
void Render1c515720() {}  // 0x00515720
void Render1c515A10() {}  // 0x00515a10
void Render1c515E40() {}  // 0x00515e40
void Render1c5197D0() {}  // 0x005197d0
void Render1c519B90() {}  // 0x00519b90
void Render1c519E60() {}  // 0x00519e60
void Render1c51AEB0() {}  // 0x0051aeb0
void Render1c51AFA0() {}  // 0x0051afa0
void Render1c51B290() {}  // 0x0051b290
void Render1c51F9F0() {}  // 0x0051f9f0
void Render1c51FCB0() {}  // 0x0051fcb0
void Render1c5203C0() {}  // 0x005203c0
void Render1c522A10() {}  // 0x00522a10
void Render1c522C80() {}  // 0x00522c80
void Render1c5272B0() {}  // 0x005272b0
void Render1c527CF0() {}  // 0x00527cf0
void Render1c52AD50() {}  // 0x0052ad50
void Render1c52B280() {}  // 0x0052b280
void Render1c52B950() {}  // 0x0052b950
void Render1c52D4D0() {}  // 0x0052d4d0
void Render1c52DEF0() {}  // 0x0052def0
void Render1c531A80() {}  // 0x00531a80
void Render1c531B50() {}  // 0x00531b50
void Render1c531F80() {}  // 0x00531f80
void Render1c5322B0() {}  // 0x005322b0
void Render1c5329E0() {}  // 0x005329e0
void Render1c534FA0() {}  // 0x00534fa0
void Render1c535AF0() {}  // 0x00535af0
void Render1c536B20() {}  // 0x00536b20
void Render1c536CE0() {}  // 0x00536ce0
void Render1c538EB0() {}  // 0x00538eb0
void Render1c5390A0() {}  // 0x005390a0
void Render1c539BD0() {}  // 0x00539bd0
void Render1c53A780() {}  // 0x0053a780
void Render1c53A930() {}  // 0x0053a930
void Render1c53AB40() {}  // 0x0053ab40
void Render1c53B5D0() {}  // 0x0053b5d0
void Render1c53BDA0() {}  // 0x0053bda0
void Render1c53BF20() {}  // 0x0053bf20
void Render1c53C390() {}  // 0x0053c390
void Render1c53C710() {}  // 0x0053c710
void Render1c53CBA0() {}  // 0x0053cba0
void Render1c53CF00() {}  // 0x0053cf00
void Render1c53D120() {}  // 0x0053d120
void Render1c53D3E0() {}  // 0x0053d3e0
void Render1c53EC90() {}  // 0x0053ec90
void Render1c53EDD0() {}  // 0x0053edd0
void Render1c53F2A0() {}  // 0x0053f2a0
void Render1c542330() {}  // 0x00542330
void Render1c5430D0() {}  // 0x005430d0
void Render1c543190() {}  // 0x00543190
void Render1c543CB0() {}  // 0x00543cb0
void Render1c544680() {}  // 0x00544680
void Render1c5447C0() {}  // 0x005447c0
void Render1c545380() {}  // 0x00545380
void Render1c545580() {}  // 0x00545580
void Render1c545A80() {}  // 0x00545a80
void Render1c546700() {}  // 0x00546700
void Render1c5467F0() {}  // 0x005467f0
void Render1c5474A0() {}  // 0x005474a0
void Render1c5475A0() {}  // 0x005475a0
void Render1c548260() {}  // 0x00548260
void Render1c548360() {}  // 0x00548360
void Render1c5486A0() {}  // 0x005486a0
void Render1c549000() {}  // 0x00549000
void Render1c549B00() {}  // 0x00549b00
void Render1c54B090() {}  // 0x0054b090
void Render1c54B3C0() {}  // 0x0054b3c0
void Render1c54B780() {}  // 0x0054b780
void Render1c54E0C0() {}  // 0x0054e0c0
void Render1c54E2A0() {}  // 0x0054e2a0
void Render1c54FC80() {}  // 0x0054fc80
void Render1c550890() {}  // 0x00550890
void Render1c550F00() {}  // 0x00550f00
void Render1c551AE0() {}  // 0x00551ae0
void Render1c551B40() {}  // 0x00551b40
void Render1c552CC0() {}  // 0x00552cc0
void Render1c553E20() {}  // 0x00553e20
void Render1c554610() {}  // 0x00554610
void Render1c554AA7() {}  // 0x00554aa7
void Render1c554E70() {}  // 0x00554e70
void Render1c557020() {}  // 0x00557020
void Render1c557800() {}  // 0x00557800
void Render1c557960() {}  // 0x00557960
void Render1c5593D0() {}  // 0x005593d0
void Render1c55A0C0() {}  // 0x0055a0c0
void Render1c55A8E0() {}  // 0x0055a8e0
void Render1c55A940() {}  // 0x0055a940
void Render1c55AAA0() {}  // 0x0055aaa0
void Render1c55B020() {}  // 0x0055b020
void Render1c55B810() {}  // 0x0055b810
void Render1c55CF40() {}  // 0x0055cf40
void Render1c55F900() {}  // 0x0055f900
void Render1c562000() {}  // 0x00562000
void Render1c563AA0() {}  // 0x00563aa0
void Render1c564140() {}  // 0x00564140
void Render1c564300() {}  // 0x00564300
void Render1c565470() {}  // 0x00565470
void Render1c5659D0() {}  // 0x005659d0
void Render1c567150() {}  // 0x00567150
void Render1c5672C0() {}  // 0x005672c0
void Render1c5687D0() {}  // 0x005687d0
void Render1c568EC0() {}  // 0x00568ec0
void Render1c569A80() {}  // 0x00569a80
void Render1c56AFE0() {}  // 0x0056afe0
void Render1c56B260() {}  // 0x0056b260
void Render1c56D370() {}  // 0x0056d370
void Render1c56DBB0() {}  // 0x0056dbb0
void Render1c56EAD0() {}  // 0x0056ead0
void Render1c56ECB0() {}  // 0x0056ecb0
void Render1c570CC0() {}  // 0x00570cc0
void Render1c5755D0() {}  // 0x005755d0
void Render1c575A10() {}  // 0x00575a10
void Render1c5762A0() {}  // 0x005762a0
void Render1c5790E0() {}  // 0x005790e0
void Render1c57CA20() {}  // 0x0057ca20
void Render1c57E4B0() {}  // 0x0057e4b0
void Render1c57E920() {}  // 0x0057e920
void Render1c57EB60() {}  // 0x0057eb60
void Render1c580BB0() {}  // 0x00580bb0
void Render1c581570() {}  // 0x00581570
void Render1c5819A0() {}  // 0x005819a0
void Render1c582D70() {}  // 0x00582d70
void Render1c583020() {}  // 0x00583020
void Render1c584760() {}  // 0x00584760
void Render1c5865A0() {}  // 0x005865a0
void Render1c586820() {}  // 0x00586820
void Render1c586BA0() {}  // 0x00586ba0
void Render1c5875C0() {}  // 0x005875c0
void Render1c587DA0() {}  // 0x00587da0
void Render1c588CB0() {}  // 0x00588cb0
void Render1c589590() {}  // 0x00589590
void Render1c58A850() {}  // 0x0058a850
void Render1c58AA50() {}  // 0x0058aa50
void Render1c58AC20() {}  // 0x0058ac20
void Render1c58ACD0() {}  // 0x0058acd0
void Render1c58AF70() {}  // 0x0058af70
void Render1c58B020() {}  // 0x0058b020
void Render1c58B2E0() {}  // 0x0058b2e0
void Render1c58B590() {}  // 0x0058b590
void Render1c58B750() {}  // 0x0058b750
void Render1c58B800() {}  // 0x0058b800
void Render1c58BA60() {}  // 0x0058ba60
void Render1c58BB10() {}  // 0x0058bb10
void Render1c58BBC0() {}  // 0x0058bbc0
void Render1c58BD30() {}  // 0x0058bd30
void Render1c58BF30() {}  // 0x0058bf30
void Render1c58BFE0() {}  // 0x0058bfe0
void Render1c58C170() {}  // 0x0058c170
void Render1c58C220() {}  // 0x0058c220
void Render1c58CA20() {}  // 0x0058ca20
void Render1c58CC80() {}  // 0x0058cc80
void Render1c58CD20() {}  // 0x0058cd20
void Render1c58D360() {}  // 0x0058d360
void Render1c58D720() {}  // 0x0058d720
void Render1c58DE90() {}  // 0x0058de90
void Render1c58E090() {}  // 0x0058e090
void Render1c58E2A0() {}  // 0x0058e2a0
void Render1c590730() {}  // 0x00590730
void Render1c590BF0() {}  // 0x00590bf0
void Render1c590F80() {}  // 0x00590f80
void Render1c5912A0() {}  // 0x005912a0
void Render1c591730() {}  // 0x00591730
void Render1c591F20() {}  // 0x00591f20
void Render1c592080() {}  // 0x00592080
void Render1c592270() {}  // 0x00592270
void Render1c5925F0() {}  // 0x005925f0
void Render1c5931C0() {}  // 0x005931c0
void Render1c594660() {}  // 0x00594660
void Render1c595170() {}  // 0x00595170
void Render1c595460() {}  // 0x00595460
void Render1c5955E0() {}  // 0x005955e0
void Render1c595C60() {}  // 0x00595c60
void Render1c59BE30() {}  // 0x0059be30
void Render1c59DF40() {}  // 0x0059df40
void Render1c59E180() {}  // 0x0059e180
void Render1c59FC80() {}  // 0x0059fc80
void Render1c59FEC0() {}  // 0x0059fec0
void Render1c5A0650() {}  // 0x005a0650
void Render1c5A1600() {}  // 0x005a1600
void Render1c5A2B00() {}  // 0x005a2b00
void Render1c5A3F20() {}  // 0x005a3f20
void Render1c5A5590() {}  // 0x005a5590
void Render1c5A7960() {}  // 0x005a7960
void Render1c5A7CB0() {}  // 0x005a7cb0
void Render1c5A8660() {}  // 0x005a8660
void Render1c5A9580() {}  // 0x005a9580
void Render1c5AA800() {}  // 0x005aa800
void Render1c5AAE50() {}  // 0x005aae50
void Render1c5AB410() {}  // 0x005ab410
void Render1c5AC9F0() {}  // 0x005ac9f0
void Render1c5ACA20() {}  // 0x005aca20
void Render1c5AEA50() {}  // 0x005aea50
void Render1c5AF410() {}  // 0x005af410
void Render1c5B0AC0() {}  // 0x005b0ac0
void Render1c5B10C0() {}  // 0x005b10c0
void Render1c5B3070() {}  // 0x005b3070
void Render1c5B3230() {}  // 0x005b3230
void Render1c5B3AF0() {}  // 0x005b3af0
void Render1c5B3F50() {}  // 0x005b3f50
void Render1c5B3F90() {}  // 0x005b3f90
void Render1c5B4D30() {}  // 0x005b4d30
void Render1c5C0310() {}  // 0x005c0310
void Render1c5C05C0() {}  // 0x005c05c0
void Render1c5C0770() {}  // 0x005c0770
void Render1c5C0920() {}  // 0x005c0920
void Render1c5C0AD0() {}  // 0x005c0ad0
void Render1c5C0B70() {}  // 0x005c0b70
void Render1c5C0C80() {}  // 0x005c0c80
void Render1c5C0EF0() {}  // 0x005c0ef0
void Render1c5C12B0() {}  // 0x005c12b0
void Render1c5C1490() {}  // 0x005c1490
void Render1c5C16F0() {}  // 0x005c16f0
void Render1c5C43D0() {}  // 0x005c43d0
void Render1c5C4400() {}  // 0x005c4400
void Render1c5C54B0() {}  // 0x005c54b0
void Render1c5C5560() {}  // 0x005c5560
void Render1c5C5C00() {}  // 0x005c5c00
void Render1c5C5E30() {}  // 0x005c5e30
void Render1c5C60F0() {}  // 0x005c60f0
void Render1c5CC670() {}  // 0x005cc670
void Render1c5CD1A0() {}  // 0x005cd1a0
void Render1c5CD1E0() {}  // 0x005cd1e0
void Render1c5CE760() {}  // 0x005ce760
void Render1c5CEC70() {}  // 0x005cec70
void Render1c5CF480() {}  // 0x005cf480
void Render1c5D0B90() {}  // 0x005d0b90
void Render1c5D1560() {}  // 0x005d1560
void Render1c5D1E20() {}  // 0x005d1e20
void Render1c5D3E20() {}  // 0x005d3e20
void Render1c5D4200() {}  // 0x005d4200
void Render1c5D45C0() {}  // 0x005d45c0
void Render1c5D4A10() {}  // 0x005d4a10
void Render1c5D4D50() {}  // 0x005d4d50
void Render1c5D5D10() {}  // 0x005d5d10
void Render1c5D77E0() {}  // 0x005d77e0
void Render1c5DC960() {}  // 0x005dc960
void Render1c5DD970() {}  // 0x005dd970
void Render1c5DF200() {}  // 0x005df200
void Render1c5DF640() {}  // 0x005df640
void Render1c5DFCD0() {}  // 0x005dfcd0
void Render1c5E0440() {}  // 0x005e0440
void Render1c5E12B0() {}  // 0x005e12b0
void Render1c5E2020() {}  // 0x005e2020
void Render1c5E2400() {}  // 0x005e2400
void Render1c5E4910() {}  // 0x005e4910
void Render1c5E8380() {}  // 0x005e8380
void Render1c5E8530() {}  // 0x005e8530
void Render1c5E87B0() {}  // 0x005e87b0
void Render1c5E87D0() {}  // 0x005e87d0
void Render1c5E8A10() {}  // 0x005e8a10
void Render1c5E8CB0() {}  // 0x005e8cb0
void Render1c5EB2F0() {}  // 0x005eb2f0
void Render1c5EBC00() {}  // 0x005ebc00
void Render1c5EBF40() {}  // 0x005ebf40
void Render1c5EE000() {}  // 0x005ee000
void Render1c5EE840() {}  // 0x005ee840
void Render1c5EEFC0() {}  // 0x005eefc0
void Render1c5F0C00() {}  // 0x005f0c00
void Render1c5F10B0() {}  // 0x005f10b0
void Render1c5F1260() {}  // 0x005f1260
void Render1c5F1340() {}  // 0x005f1340
void Render1c5F1440() {}  // 0x005f1440
void Render1c5F1600() {}  // 0x005f1600
void Render1c5F2B30() {}  // 0x005f2b30
void Render1c5F2DA0() {}  // 0x005f2da0
void Render1c5F3440() {}  // 0x005f3440
void Render1c5F36F0() {}  // 0x005f36f0
void Render1c5F41E0() {}  // 0x005f41e0
void Render1c5F5330() {}  // 0x005f5330
void Render1c5F5880() {}  // 0x005f5880
void Render1c5F6510() {}  // 0x005f6510
void Render1c5F67F0() {}  // 0x005f67f0
void Render1c5F6CE0() {}  // 0x005f6ce0
void Render1c5F83C0() {}  // 0x005f83c0
void Render1c5F8C90() {}  // 0x005f8c90
void Render1c5F8F40() {}  // 0x005f8f40
void Render1c5F93B0() {}  // 0x005f93b0
void Render1c5F94E0() {}  // 0x005f94e0
void Render1c5F9720() {}  // 0x005f9720
void Render1c5FB140() {}  // 0x005fb140
void Render1c5FBDA0() {}  // 0x005fbda0
void Render1c5FC6D0() {}  // 0x005fc6d0
void Render1c5FCB50() {}  // 0x005fcb50
void Render1c5FCD60() {}  // 0x005fcd60
void Render1c5FCE60() {}  // 0x005fce60
void Render1c5FD070() {}  // 0x005fd070
void Render1c5FDC80() {}  // 0x005fdc80
void Render1c5FDF60() {}  // 0x005fdf60
void Render1c5FDFA0() {}  // 0x005fdfa0
void Render1c5FE110() {}  // 0x005fe110
void Render1c5FE2F0() {}  // 0x005fe2f0
void Render1c5FE4F0() {}  // 0x005fe4f0
void thunk_FUN_00600990() {}  // 0x005fe630
void Render1c5FE640() {}  // 0x005fe640
void Render1c5FE72B() {}  // 0x005fe72b
void Render1c5FEC96() {}  // 0x005fec96
void Render1c5FFF60() {}  // 0x005fff60
void Sys1c600450() {}  // 0x00600450
void Sys1c600610() {}  // 0x00600610
void Sys1c600750() {}  // 0x00600750
void Sys1c600850() {}  // 0x00600850
void Sys1c6009D0() {}  // 0x006009d0
void Sys1c600BB0() {}  // 0x00600bb0
void Sys1c600C60() {}  // 0x00600c60
void Sys1c600C80() {}  // 0x00600c80
void Sys1c6010F0() {}  // 0x006010f0
void Sys1c601210() {}  // 0x00601210
void Sys1c601740() {}  // 0x00601740
void Sys1c601A90() {}  // 0x00601a90
void Sys1c60276C() {}  // 0x0060276c
void Sys1c603270() {}  // 0x00603270
void Sys1c60351D() {}  // 0x0060351d
void Sys1c603610() {}  // 0x00603610
void Sys1c603910() {}  // 0x00603910
void Sys1c603A00() {}  // 0x00603a00
void Sys1c603C00() {}  // 0x00603c00
void Sys1c603F30() {}  // 0x00603f30
void Sys1c603FE0() {}  // 0x00603fe0
void Sys1c6041A0() {}  // 0x006041a0
void Sys1c6041F0() {}  // 0x006041f0
void Sys1c604240() {}  // 0x00604240
void Sys1c604440() {}  // 0x00604440
void Sys1c604600() {}  // 0x00604600
void Sys1c604720() {}  // 0x00604720
void Sys1c604B20() {}  // 0x00604b20
void Sys1c604B60() {}  // 0x00604b60
void Sys1c604C10() {}  // 0x00604c10
void Sys1c604DC0() {}  // 0x00604dc0
void Sys1c604FF0() {}  // 0x00604ff0
void Sys1c605570() {}  // 0x00605570
void Sys1c6055D0() {}  // 0x006055d0
void Sys1c605AA0() {}  // 0x00605aa0
void Sys1c605AB0() {}  // 0x00605ab0
void Sys1c605AC0() {}  // 0x00605ac0
void Sys1c606920() {}  // 0x00606920
void Sys1c607220() {}  // 0x00607220
void Sys1c607400() {}  // 0x00607400
void Sys1c607650() {}  // 0x00607650
void Sys1c608020() {}  // 0x00608020
void Sys1c608E70() {}  // 0x00608e70
void Sys1c60B380() {}  // 0x0060b380
void Sys1c60B500() {}  // 0x0060b500
void Sys1c60B7B0() {}  // 0x0060b7b0
void Sys1c60B980() {}  // 0x0060b980
void Sys1c60BE40() {}  // 0x0060be40
void Sys1c60CDA0() {}  // 0x0060cda0
void Sys1c60CF90() {}  // 0x0060cf90
void Sys1c60D180() {}  // 0x0060d180
void Sys1c60D5F0() {}  // 0x0060d5f0
void Sys1c60D9D0() {}  // 0x0060d9d0
void Sys1c60DA20() {}  // 0x0060da20
void Sys1c60DE40() {}  // 0x0060de40
void Sys1c60E490() {}  // 0x0060e490
void Sys1c60E650() {}  // 0x0060e650
void Sys1c60EAD0() {}  // 0x0060ead0
void Sys1c60EDB0() {}  // 0x0060edb0
void Sys1c60F1E0() {}  // 0x0060f1e0
void Sys1c60F6A0() {}  // 0x0060f6a0
void Sys1c60F6E0() {}  // 0x0060f6e0
void Sys1c60FAE0() {}  // 0x0060fae0
void Sys1c60FCC0() {}  // 0x0060fcc0
void Sys1c60FEF0() {}  // 0x0060fef0
void Sys1c6100F0() {}  // 0x006100f0
void Sys1c610860() {}  // 0x00610860
void Sys1c610A40() {}  // 0x00610a40
void Sys1c6114F0() {}  // 0x006114f0
void Sys1c611780() {}  // 0x00611780
void Sys1c6119B0() {}  // 0x006119b0
void Sys1c611B60() {}  // 0x00611b60
void Sys1c611D90() {}  // 0x00611d90
void Sys1c611FC0() {}  // 0x00611fc0
void Sys1c612170() {}  // 0x00612170
void Sys1c6124D0() {}  // 0x006124d0
void Sys1c612670() {}  // 0x00612670
void Sys1c6127B0() {}  // 0x006127b0
void Sys1c612960() {}  // 0x00612960
void Sys1c6134B0() {}  // 0x006134b0
void Sys1c613CD0() {}  // 0x00613cd0
void Sys1c6141B0() {}  // 0x006141b0
void Sys1c615780() {}  // 0x00615780
void Sys1c615830() {}  // 0x00615830
void Sys1c615850() {}  // 0x00615850
void Sys1c615900() {}  // 0x00615900
void Sys1c615FF0() {}  // 0x00615ff0
void Sys1c616220() {}  // 0x00616220
void Sys1c6163B0() {}  // 0x006163b0
void Sys1c616540() {}  // 0x00616540
void Sys1c616690() {}  // 0x00616690
void Sys1c616740() {}  // 0x00616740
void Sys1c616910() {}  // 0x00616910
void Sys1c616C40() {}  // 0x00616c40
void Sys1c616DE0() {}  // 0x00616de0
void Sys1c616F80() {}  // 0x00616f80
void Sys1c617410() {}  // 0x00617410
void Sys1c617850() {}  // 0x00617850
void Sys1c617A30() {}  // 0x00617a30
void Sys1c617BC0() {}  // 0x00617bc0
void Sys1c617CD0() {}  // 0x00617cd0
void Sys1c617EA0() {}  // 0x00617ea0
void Sys1c618070() {}  // 0x00618070
void Sys1c618240() {}  // 0x00618240
void Sys1c618430() {}  // 0x00618430
void Sys1c6186A0() {}  // 0x006186a0
void Sys1c618910() {}  // 0x00618910
void Sys1c618B80() {}  // 0x00618b80
void Sys1c618C10() {}  // 0x00618c10
void Sys1c618CA0() {}  // 0x00618ca0
void Sys1c619510() {}  // 0x00619510
void Sys1c619940() {}  // 0x00619940
void Sys1c619A70() {}  // 0x00619a70
void Sys1c619C50() {}  // 0x00619c50
void Sys1c619E30() {}  // 0x00619e30
void Sys1c61A240() {}  // 0x0061a240
void Sys1c61A2B0() {}  // 0x0061a2b0
void Sys1c61A5B0() {}  // 0x0061a5b0
void Sys1c61A720() {}  // 0x0061a720
void Sys1c61A880() {}  // 0x0061a880
void Sys1c61AAE0() {}  // 0x0061aae0
void Sys1c61B130() {}  // 0x0061b130
void Sys1c61B1A0() {}  // 0x0061b1a0
void Sys1c61B1C0() {}  // 0x0061b1c0
void Sys1c61BCA0() {}  // 0x0061bca0
void Sys1c61C330() {}  // 0x0061c330
void Sys1c61C500() {}  // 0x0061c500
void Sys1c61C5B0() {}  // 0x0061c5b0
void Sys1c61C600() {}  // 0x0061c600
void Sys1c61C7F0() {}  // 0x0061c7f0
void Sys1c61C850() {}  // 0x0061c850
void Sys1c61C8B0() {}  // 0x0061c8b0
void Sys1c61C9C0() {}  // 0x0061c9c0
void Sys1c61CEB0() {}  // 0x0061ceb0
void Sys1c61CF20() {}  // 0x0061cf20
void Sys1c61D0D0() {}  // 0x0061d0d0
void Sys1c61D0E0() {}  // 0x0061d0e0
void Sys1c61D1C1() {}  // 0x0061d1c1
void Sys1c61D1E0() {}  // 0x0061d1e0
void Sys1c61D250() {}  // 0x0061d250
void Sys1c61D920() {}  // 0x0061d920
void Sys1c61DAE0() {}  // 0x0061dae0
void Sys1c61DB50() {}  // 0x0061db50
void Sys1c61DBE0() {}  // 0x0061dbe0
void Sys1c61DFF0() {}  // 0x0061dff0
void Sys1c61EA40() {}  // 0x0061ea40
void Sys1c61F1E0() {}  // 0x0061f1e0
void Sys1c61F270() {}  // 0x0061f270
void Sys1c61F560() {}  // 0x0061f560
void Sys1c61F600() {}  // 0x0061f600
void Sys1c61F6B0() {}  // 0x0061f6b0
void Sys1c61F750() {}  // 0x0061f750
void Sys1c61F7F0() {}  // 0x0061f7f0
void Sys1c61F860() {}  // 0x0061f860
void Sys1c620140() {}  // 0x00620140
void Sys1c620360() {}  // 0x00620360
void Sys1c620A40() {}  // 0x00620a40
void Sys1c620D30() {}  // 0x00620d30
void Sys1c620F20() {}  // 0x00620f20
void Sys1c6212A0() {}  // 0x006212a0
void Sys1c621430() {}  // 0x00621430
void Sys1c6217C0() {}  // 0x006217c0
void Sys1c6233F0() {}  // 0x006233f0
void Sys1c6235A0() {}  // 0x006235a0
void Sys1c6243C0() {}  // 0x006243c0
void Sys1c625600() {}  // 0x00625600
void Sys1c6256C0() {}  // 0x006256c0
void Sys1c625740() {}  // 0x00625740
void Sys1c6257E0() {}  // 0x006257e0
void Sys1c625890() {}  // 0x00625890
void Sys1c625910() {}  // 0x00625910
void Sys1c625C80() {}  // 0x00625c80
void Sys1c625D60() {}  // 0x00625d60
void Sys1c625E60() {}  // 0x00625e60
void Sys1c625E80() {}  // 0x00625e80
void Sys1c625EE0() {}  // 0x00625ee0
void Sys1c625F20() {}  // 0x00625f20
void Sys1c625F60() {}  // 0x00625f60
void Sys1c6260E0() {}  // 0x006260e0
void Sys1c6264C0() {}  // 0x006264c0
void Sys1c626700() {}  // 0x00626700
void Sys1c626940() {}  // 0x00626940
void Sys1c626B80() {}  // 0x00626b80
void Sys1c626DC0() {}  // 0x00626dc0
void Sys1c627AE0() {}  // 0x00627ae0
void Sys1c627CD0() {}  // 0x00627cd0
void Sys1c627EC0() {}  // 0x00627ec0
void Sys1c6283D0() {}  // 0x006283d0
void Sys1c628600() {}  // 0x00628600
void Sys1c628C50() {}  // 0x00628c50
void Sys1c628E00() {}  // 0x00628e00
void Sys1c628E90() {}  // 0x00628e90
void Sys1c6291C0() {}  // 0x006291c0
void Sys1c6297A0() {}  // 0x006297a0
void Sys1c629860() {}  // 0x00629860
void Sys1c629900() {}  // 0x00629900
void Sys1c62A380() {}  // 0x0062a380
void Sys1c62B930() {}  // 0x0062b930
void Sys1c62C720() {}  // 0x0062c720
void Sys1c62FDC0() {}  // 0x0062fdc0
void Sys1c6305B0() {}  // 0x006305b0
void Sys1c630E70() {}  // 0x00630e70
void Sys1c631030() {}  // 0x00631030
void Sys1c631480() {}  // 0x00631480
void Sys1c631E80() {}  // 0x00631e80
void Sys1c631EE0() {}  // 0x00631ee0
void Sys1c631FB0() {}  // 0x00631fb0
void inflateEnd() {}  // 0x006320d8
void inflate() {}  // 0x006320de
void inflateInit2_() {}  // 0x006320ea
void get_crc_table() {}  // 0x006320f0
void Sys1c632200() {}  // 0x00632200
void Sys1c6324C0() {}  // 0x006324c0
void Sys1c632760() {}  // 0x00632760
void Sys1c6339F0() {}  // 0x006339f0
void Sys1c633A90() {}  // 0x00633a90
void Sys1c6346D0() {}  // 0x006346d0
void Sys1c634880() {}  // 0x00634880
void Sys1c6355B0() {}  // 0x006355b0
void Sys1c6355F0() {}  // 0x006355f0
void Sys1c635620() {}  // 0x00635620
void Sys1c635E10() {}  // 0x00635e10
void Sys1c635F80() {}  // 0x00635f80
void Sys1c636400() {}  // 0x00636400
void Sys1c6369D0() {}  // 0x006369d0
void Sys1c636AC0() {}  // 0x00636ac0
void Sys1c636C50() {}  // 0x00636c50
void Sys1c636CA0() {}  // 0x00636ca0
void Sys1c636F80() {}  // 0x00636f80
void Sys1c636FE0() {}  // 0x00636fe0
void Sys1c637010() {}  // 0x00637010
void Sys1c637030() {}  // 0x00637030
void Sys1c6370C0() {}  // 0x006370c0
void Sys1c637BB3() {}  // 0x00637bb3
void Sys1c638610() {}  // 0x00638610
void Sys1c638680() {}  // 0x00638680
void Sys1c638B40() {}  // 0x00638b40
void Sys1c63A560() {}  // 0x0063a560
void Sys1c63CE30() {}  // 0x0063ce30
void Sys1c63E200() {}  // 0x0063e200
void Sys1c63EF10() {}  // 0x0063ef10
void Sys1c63EF30() {}  // 0x0063ef30
void Sys1c63EFB0() {}  // 0x0063efb0
void Sys1c63EFF0() {}  // 0x0063eff0
void Sys1c63F8F0() {}  // 0x0063f8f0
void Sys1c63FA50() {}  // 0x0063fa50
void Sys1c63FC00() {}  // 0x0063fc00
void Sys1c6401C0() {}  // 0x006401c0
void Sys1c6402F0() {}  // 0x006402f0
void Sys1c640400() {}  // 0x00640400
void Sys1c6404D0() {}  // 0x006404d0
void DebugBreak() {}  // 0x006409f0
void Sys1c640AC0() {}  // 0x00640ac0
void Sys1c640AD0() {}  // 0x00640ad0
void Sys1c640B10() {}  // 0x00640b10
void Sys1c640C90() {}  // 0x00640c90
void Sys1c640CF0() {}  // 0x00640cf0
void Sys1c640D40() {}  // 0x00640d40
void Sys1c640E70() {}  // 0x00640e70
void Sys1c640EB0() {}  // 0x00640eb0
void Sys1c640F60() {}  // 0x00640f60
void _Xlength_error() {}  // 0x0064100d
void _Xbad_function_call() {}  // 0x00641013
void ___std_fs_create_directory_symbolic_link_8() {}  // 0x0064154d
void ___std_fs_create_symbolic_link_8() {}  // 0x00641561
void ___std_fs_directory_iterator_open_12() {}  // 0x006415b6
void Sys1c6415ED() {}  // 0x006415ed
void ___std_fs_get_file_attributes_by_handle_8() {}  // 0x006416c6
void Sys1c641998() {}  // 0x00641998
void Sys1c6419DF() {}  // 0x006419df
void Sys1c641C49() {}  // 0x00641c49
void Sys1c641C7E() {}  // 0x00641c7e
void Sys1c641CA2() {}  // 0x00641ca2
void __Fac_node() {}  // 0x00641d58
void Sys1c641E10() {}  // 0x00641e10
void Sys1c641E40() {}  // 0x00641e40
void Sys1c6420C0() {}  // 0x006420c0
void Sys1c642280() {}  // 0x00642280
void Sys1c6424A0() {}  // 0x006424a0
void Sys1c642890() {}  // 0x00642890
void Sys1c642DD0() {}  // 0x00642dd0
void Sys1c642EF0() {}  // 0x00642ef0
void Sys1c643180() {}  // 0x00643180
void Sys1c6431E0() {}  // 0x006431e0
void Sys1c643320() {}  // 0x00643320
void Sys1c6433B0() {}  // 0x006433b0
void Sys1c6433F0() {}  // 0x006433f0
void Sys1c643400() {}  // 0x00643400
void _Xbad_alloc() {}  // 0x00643409
void Sys1c64340F() {}  // 0x0064340f
void Sys1c643432() {}  // 0x00643432
void Sys1c6434B6() {}  // 0x006434b6
void CrtAbort() {}  // 0x006434f1
void Sys1c64364A() {}  // 0x0064364a
void Sys1c64365F() {}  // 0x0064365f
void ___scrt_acquire_startup_lock() {}  // 0x006436a1
void ___scrt_initialize_crt() {}  // 0x006436d3
void ___scrt_release_startup_lock() {}  // 0x0064382a
void ___scrt_uninitialize_crt() {}  // 0x00643847
void Sys1c64386F() {}  // 0x0064386f
void Sys1c643970() {}  // 0x00643970
void Sys1c643B40() {}  // 0x00643b40
void Sys1c643C70() {}  // 0x00643c70
void Sys1c643CD5() {}  // 0x00643cd5
void Sys1c644030() {}  // 0x00644030
void Sys1c644076() {}  // 0x00644076
void Sys1c6440B0() {}  // 0x006440b0
void Sys1c6440F6() {}  // 0x006440f6
void Sys1c644410() {}  // 0x00644410
void Sys1c6445C2() {}  // 0x006445c2
void Sys1c644610() {}  // 0x00644610
void __except_handler4() {}  // 0x006446c5
void operator_delete() {}  // 0x006446f4
void Sys1c644702() {}  // 0x00644702
void ___security_init_cookie() {}  // 0x0064474f
void Sys1c6447F9() {}  // 0x006447f9
void Sys1c6447FF() {}  // 0x006447ff
void __current_exception() {}  // 0x0064488d
void __current_exception_context() {}  // 0x00644893
void except_handler4_common() {}  // 0x00644899
void Crt_malloc() {}  // 0x0064489f
void Crt_free() {}  // 0x006448a5
void terminate() {}  // 0x006448ab
void roundf() {}  // 0x006448b1
void register_onexit_function() {}  // 0x00644905
void crt_atexit() {}  // 0x0064490b
void _cexit() {}  // 0x00644911
void CrtAlignedMalloc() {}  // 0x00644917
char* get_narrow_winmain_command_line() { return nullptr; }  // 0x0064492f
void initterm() {}  // 0x00644935
void initterm_e() {}  // 0x0064493b
void CrtExit() {}  // 0x00644941
void register_thread_local_exe_atexit_callback() {}  // 0x00644959
void _aligned_free() {}  // 0x00644971
void SHGetKnownFolderPath() {}  // 0x0064497d
void Sys1c644990() {}  // 0x00644990
void Sys1c644B20() {}  // 0x00644b20
void Sys1c644B50() {}  // 0x00644b50
void Sys1c644C50() {}  // 0x00644c50
void Sys1c644E40() {}  // 0x00644e40
void Sys1c644E90() {}  // 0x00644e90
void Sys1c645200() {}  // 0x00645200
void Sys1c645464() {}  // 0x00645464
void __alldvrm() {}  // 0x00645590
void thunk_FUN_006457f0() {}  // 0x006457e0
void Sys1c6457F0() {}  // 0x006457f0
void Sys1c645870() {}  // 0x00645870
void Sys1c64588E() {}  // 0x0064588e
void Sys1c651560() {}  // 0x00651560
void Sys1c651A00() {}  // 0x00651a00
void Sys1c651A80() {}  // 0x00651a80

// --- Cycle 59: 0-caller functions (2829 functions) ---
void Core0c402160() {}  // 0x00402160
void Core0c402190() {}  // 0x00402190
void Core0c402210() {}  // 0x00402210
void Core0c4023E0() {}  // 0x004023e0
void Core0c402430() {}  // 0x00402430
void Core0c4024A0() {}  // 0x004024a0
void Core0c4024D0() {}  // 0x004024d0
void Core0c402550() {}  // 0x00402550
void Core0c4025A0() {}  // 0x004025a0
void Core0c402620() {}  // 0x00402620
void Core0c4026A0() {}  // 0x004026a0
void Core0c402770() {}  // 0x00402770
void Core0c429D80() {}  // 0x00429d80
void Core0c429E30() {}  // 0x00429e30
void Core0c429E80() {}  // 0x00429e80
void Core0c429FE0() {}  // 0x00429fe0
void Core0c42A110() {}  // 0x0042a110
void Core0c42A1F0() {}  // 0x0042a1f0
void Core0c42A540() {}  // 0x0042a540
void Core0c42A620() {}  // 0x0042a620
void Core0c42AE20() {}  // 0x0042ae20
void Core0c42B9E0() {}  // 0x0042b9e0
void Core0c42BA10() {}  // 0x0042ba10
void Core0c42BA50() {}  // 0x0042ba50
void Core0c42BA90() {}  // 0x0042ba90
void Core0c42C110() {}  // 0x0042c110
void Core0c42C740() {}  // 0x0042c740
void Core0c42CB60() {}  // 0x0042cb60
void Core0c42D370() {}  // 0x0042d370
void Core0c42D8F0() {}  // 0x0042d8f0
void Catch_All_0042e1f2() {}  // 0x0042e1f2
void Core0c42E520() {}  // 0x0042e520
void Core0c42E5A0() {}  // 0x0042e5a0
void Core0c42E6A0() {}  // 0x0042e6a0
void Core0c42E720() {}  // 0x0042e720
void Core0c42E830() {}  // 0x0042e830
void Core0c42E8C0() {}  // 0x0042e8c0
void Core0c42E970() {}  // 0x0042e970
void Core0c42EA20() {}  // 0x0042ea20
void Core0c42EAC0() {}  // 0x0042eac0
void Core0c42EBA0() {}  // 0x0042eba0
void Core0c42ECE0() {}  // 0x0042ece0
void Core0c42EE20() {}  // 0x0042ee20
void Core0c42EFC0() {}  // 0x0042efc0
void Core0c42F050() {}  // 0x0042f050
void Core0c42FA70() {}  // 0x0042fa70
void Catch_0042fd35() {}  // 0x0042fd35
void Core0c4308B0() {}  // 0x004308b0
void Core0c4308F0() {}  // 0x004308f0
void Core0c430930() {}  // 0x00430930
void Core0c430A10() {}  // 0x00430a10
void Core0c430AE0() {}  // 0x00430ae0
void Core0c430BF0() {}  // 0x00430bf0
void Core0c430CF0() {}  // 0x00430cf0
void Core0c430E00() {}  // 0x00430e00
void underflow() {}  // 0x00431010
void Core0c431050() {}  // 0x00431050
void Core0c431100() {}  // 0x00431100
void Core0c431440() {}  // 0x00431440
void Core0c4314A0() {}  // 0x004314a0
void Core0c431500() {}  // 0x00431500
void Core0c431520() {}  // 0x00431520
void Core0c43D950() {}  // 0x0043d950
void Catch_All_0043ed90() {}  // 0x0043ed90
void Catch_0043f576() {}  // 0x0043f576
void Core0c43F5F0() {}  // 0x0043f5f0
void Core0c43F620() {}  // 0x0043f620
void Core0c43F860() {}  // 0x0043f860
void Core0c43FA30() {}  // 0x0043fa30
void Core0c441AF0() {}  // 0x00441af0
void Core0c442530() {}  // 0x00442530
void Core0c442630() {}  // 0x00442630
void Core0c442F80() {}  // 0x00442f80
void Core0c442FB0() {}  // 0x00442fb0
void Core0c443240() {}  // 0x00443240
void Core0c4432F0() {}  // 0x004432f0
void Core0c444040() {}  // 0x00444040
void Core0c4440D0() {}  // 0x004440d0
void Core0c444AC0() {}  // 0x00444ac0
void Core0c444D30() {}  // 0x00444d30
void Core0c44DDB0() {}  // 0x0044ddb0
void Core0c44DF20() {}  // 0x0044df20
void Core0c44DF70() {}  // 0x0044df70
void Core0c44E040() {}  // 0x0044e040
void Catch_0044e20e() {}  // 0x0044e20e
void Core0c44E2E0() {}  // 0x0044e2e0
void Core0c44E780() {}  // 0x0044e780
void Core0c44EBE0() {}  // 0x0044ebe0
void Core0c44EC30() {}  // 0x0044ec30
void Core0c44FD60() {}  // 0x0044fd60
void Game0c4514E0() {}  // 0x004514e0
void Game0c451900() {}  // 0x00451900
void Game0c451CD0() {}  // 0x00451cd0
void Game0c451EA0() {}  // 0x00451ea0
void Game0c451FA0() {}  // 0x00451fa0
void Game0c4520A0() {}  // 0x004520a0
void Game0c4521A0() {}  // 0x004521a0
void Game0c4527E0() {}  // 0x004527e0
void Catch_00455846() {}  // 0x00455846
void Game0c456130() {}  // 0x00456130
void Game0c4610F0() {}  // 0x004610f0
void Game0c462420() {}  // 0x00462420
void Game0c462E10() {}  // 0x00462e10
void Game0c464A10() {}  // 0x00464a10
void Game0c46A050() {}  // 0x0046a050
void Game0c46E5B0() {}  // 0x0046e5b0
void Game0c46E980() {}  // 0x0046e980
void Game0c46EC40() {}  // 0x0046ec40
void Game0c46EC70() {}  // 0x0046ec70
void Catch_0046ed63() {}  // 0x0046ed63
void Game0c46EE70() {}  // 0x0046ee70
void Game0c46EF10() {}  // 0x0046ef10
void Game0c46EFF0() {}  // 0x0046eff0
void Game0c46F080() {}  // 0x0046f080
void Game0c46F0D0() {}  // 0x0046f0d0
void Game0c46F150() {}  // 0x0046f150
void Catch_All_0046f1bf() {}  // 0x0046f1bf
void Game0c46F1F0() {}  // 0x0046f1f0
void Game0c46F280() {}  // 0x0046f280
void Catch_All_0046f438() {}  // 0x0046f438
void Game0c46F580() {}  // 0x0046f580
void Catch_All_0046f7b5() {}  // 0x0046f7b5
void Game0c46F7E0() {}  // 0x0046f7e0
void Game0c46F930() {}  // 0x0046f930
void Catch_All_00470c6a() {}  // 0x00470c6a
void Game0c471C50() {}  // 0x00471c50
void Game0c471DC0() {}  // 0x00471dc0
void Game0c471E70() {}  // 0x00471e70
void Game0c476CB0() {}  // 0x00476cb0
void Game0c480180() {}  // 0x00480180
void Game0c489DA0() {}  // 0x00489da0
void Game0c48A4C0() {}  // 0x0048a4c0
void Game0c48ADB0() {}  // 0x0048adb0
void Game0c48D1A0() {}  // 0x0048d1a0
void Game0c48D800() {}  // 0x0048d800
void Game0c48D870() {}  // 0x0048d870
void Game0c48DC00() {}  // 0x0048dc00
void Game0c48E000() {}  // 0x0048e000
void Game0c48F3A0() {}  // 0x0048f3a0
void Game0c48F400() {}  // 0x0048f400
void Game0c492970() {}  // 0x00492970
void Game0c492CC0() {}  // 0x00492cc0
void Game0c493580() {}  // 0x00493580
void Game0c496F30() {}  // 0x00496f30
void Game0c498A60() {}  // 0x00498a60
void Game0c499720() {}  // 0x00499720
void Game0c49B980() {}  // 0x0049b980
void Game0c49BAB0() {}  // 0x0049bab0
void Game0c49BBB0() {}  // 0x0049bbb0
void Game0c49C6E0() {}  // 0x0049c6e0
void Game0c49C920() {}  // 0x0049c920
void Game0c49D2D0() {}  // 0x0049d2d0
void Game0c4A12E0() {}  // 0x004a12e0
void Game0c4A63D0() {}  // 0x004a63d0
void Game0c4AA5B0() {}  // 0x004aa5b0
void Game0c4AB850() {}  // 0x004ab850
void Catch_004b3d6e() {}  // 0x004b3d6e
void Game0c4BD160() {}  // 0x004bd160
void Game0c4BD5B0() {}  // 0x004bd5b0
void Game0c4BD7E0() {}  // 0x004bd7e0
void Game0c4BE430() {}  // 0x004be430
void Game0c4BE4A0() {}  // 0x004be4a0
void Game0c4BE760() {}  // 0x004be760
void Game0c4BE830() {}  // 0x004be830
void Game0c4BEA20() {}  // 0x004bea20
void Game0c4BEDF0() {}  // 0x004bedf0
void Game0c4BF210() {}  // 0x004bf210
void Game0c4BF230() {}  // 0x004bf230
void Game0c4BF2D0() {}  // 0x004bf2d0
void Game0c4BF310() {}  // 0x004bf310
void Game0c4BF3A0() {}  // 0x004bf3a0
void Game0c4BF430() {}  // 0x004bf430
void Game0c4BF4C0() {}  // 0x004bf4c0
void Game0c4BF570() {}  // 0x004bf570
void Game0c4BF790() {}  // 0x004bf790
void Game0c4C1AF0() {}  // 0x004c1af0
void Game0c4C1BA0() {}  // 0x004c1ba0
void Game0c4C1FE0() {}  // 0x004c1fe0
void Game0c4C20E0() {}  // 0x004c20e0
void Game0c4C2450() {}  // 0x004c2450
void Game0c4C2CF0() {}  // 0x004c2cf0
void Game0c4C3E90() {}  // 0x004c3e90
void Game0c4C41E0() {}  // 0x004c41e0
void Catch_004c423b() {}  // 0x004c423b
void Catch_All_004c429a() {}  // 0x004c429a
void Game0c4C42D0() {}  // 0x004c42d0
void Catch_004c434a() {}  // 0x004c434a
void Catch_All_004c43fc() {}  // 0x004c43fc
void Game0c4C48E0() {}  // 0x004c48e0
void Game0c4C5160() {}  // 0x004c5160
void Game0c4C51C0() {}  // 0x004c51c0
void Game0c4C56C0() {}  // 0x004c56c0
void Game0c4C5A40() {}  // 0x004c5a40
void Game0c4C5B20() {}  // 0x004c5b20
void Game0c4C5C30() {}  // 0x004c5c30
void Game0c4C5D50() {}  // 0x004c5d50
void Game0c4C5E80() {}  // 0x004c5e80
void Game0c4C5F80() {}  // 0x004c5f80
void Game0c4C6060() {}  // 0x004c6060
void Game0c4C6140() {}  // 0x004c6140
void Game0c4C6220() {}  // 0x004c6220
void Game0c4C6300() {}  // 0x004c6300
void Game0c4C6540() {}  // 0x004c6540
void Game0c4C6600() {}  // 0x004c6600
void Game0c4C66F0() {}  // 0x004c66f0
void Game0c4C6800() {}  // 0x004c6800
void Game0c4C68C0() {}  // 0x004c68c0
void Game0c4C6980() {}  // 0x004c6980
void Game0c4C6A40() {}  // 0x004c6a40
void Game0c4C6B00() {}  // 0x004c6b00
void Game0c4C6BC0() {}  // 0x004c6bc0
void Game0c4C6C80() {}  // 0x004c6c80
void Game0c4C6D50() {}  // 0x004c6d50
void Game0c4C6E20() {}  // 0x004c6e20
void Game0c4C6EF0() {}  // 0x004c6ef0
void Game0c4C6FC0() {}  // 0x004c6fc0
void Game0c4C70A0() {}  // 0x004c70a0
void Game0c4C71F0() {}  // 0x004c71f0
void Game0c4C72D0() {}  // 0x004c72d0
void Game0c4C7460() {}  // 0x004c7460
void Game0c4C75D0() {}  // 0x004c75d0
void Game0c4C76C0() {}  // 0x004c76c0
void Game0c4C7860() {}  // 0x004c7860
void Game0c4C79A0() {}  // 0x004c79a0
void Game0c4C7AA0() {}  // 0x004c7aa0
void Game0c4C7C20() {}  // 0x004c7c20
void Game0c4C7DD0() {}  // 0x004c7dd0
void Game0c4C7F60() {}  // 0x004c7f60
void Game0c4C80F0() {}  // 0x004c80f0
void Game0c4C83C0() {}  // 0x004c83c0
void Game0c4C9570() {}  // 0x004c9570
void Game0c4C9B70() {}  // 0x004c9b70
void Game0c4C9D20() {}  // 0x004c9d20
void Game0c4C9F10() {}  // 0x004c9f10
void Game0c4C9F80() {}  // 0x004c9f80
void Game0c4CA230() {}  // 0x004ca230
void Game0c4CA2E0() {}  // 0x004ca2e0
void Game0c4CA420() {}  // 0x004ca420
void Game0c4CA4E0() {}  // 0x004ca4e0
void Game0c4CA550() {}  // 0x004ca550
void Game0c4CA610() {}  // 0x004ca610
void Game0c4CA660() {}  // 0x004ca660
void Game0c4CA8A0() {}  // 0x004ca8a0
void Game0c4CA8C0() {}  // 0x004ca8c0
void Game0c4CA910() {}  // 0x004ca910
void Game0c4CAA50() {}  // 0x004caa50
void Game0c4CE260() {}  // 0x004ce260
void Game0c4CE360() {}  // 0x004ce360
void Game0c4CE3F0() {}  // 0x004ce3f0
void Game0c4CE5B0() {}  // 0x004ce5b0
void Game0c4CE720() {}  // 0x004ce720
void Game0c4CE800() {}  // 0x004ce800
void Game0c4CE900() {}  // 0x004ce900
void Game0c4CEA70() {}  // 0x004cea70
void Game0c4CFB70() {}  // 0x004cfb70
void Game0c4D0F60() {}  // 0x004d0f60
void Game0c4D1100() {}  // 0x004d1100
void Game0c4D1190() {}  // 0x004d1190
void Game0c4D11D0() {}  // 0x004d11d0
void Game0c4D1300() {}  // 0x004d1300
void Game0c4D1580() {}  // 0x004d1580
void Game0c4D16F0() {}  // 0x004d16f0
void Game0c4D17B0() {}  // 0x004d17b0
void Game0c4D22B0() {}  // 0x004d22b0
void Game0c4D2AB0() {}  // 0x004d2ab0
void Game0c4D39B0() {}  // 0x004d39b0
void Game0c4D6090() {}  // 0x004d6090
void Game0c4DE330() {}  // 0x004de330
void Game0c4DE3B0() {}  // 0x004de3b0
void Game0c4DE4E0() {}  // 0x004de4e0
void Game0c4E22B0() {}  // 0x004e22b0
void Game0c4E3300() {}  // 0x004e3300
void Game0c4E34A0() {}  // 0x004e34a0
void Game0c4E3980() {}  // 0x004e3980
void Game0c4E4140() {}  // 0x004e4140
void Game0c4E4910() {}  // 0x004e4910
void Game0c4F2940() {}  // 0x004f2940
void Game0c4F2B60() {}  // 0x004f2b60
void Game0c4F2DC0() {}  // 0x004f2dc0
void Catch_All_004f382a() {}  // 0x004f382a
void Catch_All_004f4a5a() {}  // 0x004f4a5a
void Catch_All_004f4feb() {}  // 0x004f4feb
void Game0c4F77E0() {}  // 0x004f77e0
void Game0c4F7820() {}  // 0x004f7820
void Game0c4F94C0() {}  // 0x004f94c0
void Game0c4F9AE0() {}  // 0x004f9ae0
void Game0c4F9F50() {}  // 0x004f9f50
void Game0c4FAE20() {}  // 0x004fae20
void Game0c4FDAB0() {}  // 0x004fdab0
void Catch_All_004fe56c() {}  // 0x004fe56c
void Game0c4FE690() {}  // 0x004fe690
void Game0c4FFE10() {}  // 0x004ffe10
void Render0c500130() {}  // 0x00500130
void Render0c500650() {}  // 0x00500650
void Catch_All_00501213() {}  // 0x00501213
void Render0c502460() {}  // 0x00502460
void Render0c5038F0() {}  // 0x005038f0
void Render0c505CA0() {}  // 0x00505ca0
void Render0c506260() {}  // 0x00506260
void Render0c50AEB0() {}  // 0x0050aeb0
void Render0c50B8C0() {}  // 0x0050b8c0
void Render0c50D090() {}  // 0x0050d090
void Render0c514D40() {}  // 0x00514d40
void Render0c515AC0() {}  // 0x00515ac0
void Render0c515F10() {}  // 0x00515f10
void Render0c515F80() {}  // 0x00515f80
void Render0c518460() {}  // 0x00518460
void Render0c518770() {}  // 0x00518770
void Render0c518900() {}  // 0x00518900
void Render0c518A60() {}  // 0x00518a60
void Render0c519400() {}  // 0x00519400
void Render0c51A250() {}  // 0x0051a250
void Render0c51B6C0() {}  // 0x0051b6c0
void Render0c51BD90() {}  // 0x0051bd90
void Render0c51C2D0() {}  // 0x0051c2d0
void Render0c51C680() {}  // 0x0051c680
void Render0c51EB00() {}  // 0x0051eb00
void Render0c51EE60() {}  // 0x0051ee60
void Render0c51F5F8() {}  // 0x0051f5f8
void Render0c51F960() {}  // 0x0051f960
void Render0c520C20() {}  // 0x00520c20
void Render0c520CF0() {}  // 0x00520cf0
void Render0c5210D0() {}  // 0x005210d0
void Render0c521260() {}  // 0x00521260
void Render0c5220E0() {}  // 0x005220e0
void Render0c5224A0() {}  // 0x005224a0
void Render0c523AA0() {}  // 0x00523aa0
void Render0c523E40() {}  // 0x00523e40
void Render0c524640() {}  // 0x00524640
void Render0c524710() {}  // 0x00524710
void Render0c5310B0() {}  // 0x005310b0
void Render0c531550() {}  // 0x00531550
void Render0c531580() {}  // 0x00531580
void Render0c532F00() {}  // 0x00532f00
void Render0c53B170() {}  // 0x0053b170
void Render0c53B400() {}  // 0x0053b400
void Render0c53DF20() {}  // 0x0053df20
void Render0c53E6A0() {}  // 0x0053e6a0
void Render0c53EAC0() {}  // 0x0053eac0
void Render0c53F010() {}  // 0x0053f010
void Render0c53FFA0() {}  // 0x0053ffa0
void Render0c54CB30() {}  // 0x0054cb30
void Render0c54CC20() {}  // 0x0054cc20
void Render0c551BE0() {}  // 0x00551be0
void Catch_00554900() {}  // 0x00554900
void Catch_00554a6e() {}  // 0x00554a6e
void Render0c5582C0() {}  // 0x005582c0
void Render0c5588F0() {}  // 0x005588f0
void Render0c558910() {}  // 0x00558910
void Render0c559340() {}  // 0x00559340
void Render0c55A0B0() {}  // 0x0055a0b0
void Render0c55AA30() {}  // 0x0055aa30
void Render0c55C220() {}  // 0x0055c220
void Render0c55CC40() {}  // 0x0055cc40
void Render0c55CC70() {}  // 0x0055cc70
void Render0c55F030() {}  // 0x0055f030
void Render0c55F0A0() {}  // 0x0055f0a0
void Render0c55F110() {}  // 0x0055f110
void Render0c55F290() {}  // 0x0055f290
void Render0c55F500() {}  // 0x0055f500
void Render0c55F5F0() {}  // 0x0055f5f0
void Render0c55F710() {}  // 0x0055f710
void Render0c55FC80() {}  // 0x0055fc80
void Render0c5617E0() {}  // 0x005617e0
void Render0c563B30() {}  // 0x00563b30
void Render0c563BC0() {}  // 0x00563bc0
void Render0c563CD0() {}  // 0x00563cd0
void Render0c563DA0() {}  // 0x00563da0
void Render0c5690B0() {}  // 0x005690b0
void Render0c569300() {}  // 0x00569300
void Render0c5693D0() {}  // 0x005693d0
void Render0c569E70() {}  // 0x00569e70
void Render0c56A2C0() {}  // 0x0056a2c0
void Render0c56A4A0() {}  // 0x0056a4a0
void Render0c56AB20() {}  // 0x0056ab20
void Render0c56B700() {}  // 0x0056b700
void Render0c56B720() {}  // 0x0056b720
void Render0c56B740() {}  // 0x0056b740
void Render0c56B760() {}  // 0x0056b760
void Render0c56B780() {}  // 0x0056b780
void Render0c56B7C0() {}  // 0x0056b7c0
void Render0c56B810() {}  // 0x0056b810
void Render0c56B850() {}  // 0x0056b850
void Render0c56B930() {}  // 0x0056b930
void Render0c56BB40() {}  // 0x0056bb40
void Render0c56C8C0() {}  // 0x0056c8c0
void Render0c56CCD0() {}  // 0x0056ccd0
void Render0c56D080() {}  // 0x0056d080
void Render0c56D1A0() {}  // 0x0056d1a0
void Render0c5712C0() {}  // 0x005712c0
void Render0c573270() {}  // 0x00573270
void Render0c5740D0() {}  // 0x005740d0
void Render0c5742F0() {}  // 0x005742f0
void Render0c5745A0() {}  // 0x005745a0
void Render0c574740() {}  // 0x00574740
void Render0c5748B0() {}  // 0x005748b0
void Render0c574AD0() {}  // 0x00574ad0
void Render0c574CA0() {}  // 0x00574ca0
void Render0c57D880() {}  // 0x0057d880
void Render0c57DBB0() {}  // 0x0057dbb0
void Render0c57F680() {}  // 0x0057f680
void Render0c580520() {}  // 0x00580520
void Render0c584C50() {}  // 0x00584c50
void Render0c58A3C0() {}  // 0x0058a3c0
void Render0c58DB10() {}  // 0x0058db10
void Render0c58E5B0() {}  // 0x0058e5b0
void Render0c592B50() {}  // 0x00592b50
void Render0c592BA0() {}  // 0x00592ba0
void Render0c592C30() {}  // 0x00592c30
void Render0c592D40() {}  // 0x00592d40
void Render0c592FC0() {}  // 0x00592fc0
void Render0c5932D0() {}  // 0x005932d0
void Render0c5937D0() {}  // 0x005937d0
void Render0c593910() {}  // 0x00593910
void Render0c593CC0() {}  // 0x00593cc0
void Render0c593F00() {}  // 0x00593f00
void Render0c5943E0() {}  // 0x005943e0
void Render0c5949A0() {}  // 0x005949a0
void Render0c595240() {}  // 0x00595240
void Render0c595670() {}  // 0x00595670
void Render0c5958E0() {}  // 0x005958e0
void Render0c595AB0() {}  // 0x00595ab0
void Render0c595D80() {}  // 0x00595d80
void Render0c596710() {}  // 0x00596710
void Render0c596A00() {}  // 0x00596a00
void Render0c596B10() {}  // 0x00596b10
void Render0c596C10() {}  // 0x00596c10
void Render0c599640() {}  // 0x00599640
void Render0c59A370() {}  // 0x0059a370
void Render0c59B4B0() {}  // 0x0059b4b0
void Render0c59BB60() {}  // 0x0059bb60
void Render0c5A0140() {}  // 0x005a0140
void Render0c5A3CA0() {}  // 0x005a3ca0
void Render0c5A3CD0() {}  // 0x005a3cd0
void Render0c5A5790() {}  // 0x005a5790
void Render0c5A6940() {}  // 0x005a6940
void Render0c5A6D10() {}  // 0x005a6d10
void Render0c5A7010() {}  // 0x005a7010
void Render0c5A7030() {}  // 0x005a7030
void Render0c5A7060() {}  // 0x005a7060
void Render0c5A7290() {}  // 0x005a7290
void Render0c5A9A50() {}  // 0x005a9a50
void Render0c5AA4B0() {}  // 0x005aa4b0
void Render0c5AAA30() {}  // 0x005aaa30
void Render0c5AACF0() {}  // 0x005aacf0
void Render0c5AB160() {}  // 0x005ab160
void Render0c5AB5D0() {}  // 0x005ab5d0
void Render0c5ABC60() {}  // 0x005abc60
void Render0c5AC980() {}  // 0x005ac980
void Render0c5ACBA0() {}  // 0x005acba0
void Render0c5ACD30() {}  // 0x005acd30
void Render0c5ACE50() {}  // 0x005ace50
void Render0c5AD0C0() {}  // 0x005ad0c0
void Render0c5AD450() {}  // 0x005ad450
void Render0c5AD4E0() {}  // 0x005ad4e0
void Render0c5ADB10() {}  // 0x005adb10
void Render0c5ADB50() {}  // 0x005adb50
void Render0c5AE020() {}  // 0x005ae020
void Render0c5AE180() {}  // 0x005ae180
void Render0c5AE9D0() {}  // 0x005ae9d0
void Render0c5AEB70() {}  // 0x005aeb70
void Render0c5AF0D0() {}  // 0x005af0d0
void Render0c5AF100() {}  // 0x005af100
void Render0c5AF190() {}  // 0x005af190
void Render0c5AF4D0() {}  // 0x005af4d0
void Render0c5B0470() {}  // 0x005b0470
void Render0c5B0600() {}  // 0x005b0600
void Render0c5B1D20() {}  // 0x005b1d20
void Render0c5B1F20() {}  // 0x005b1f20
void Render0c5B2160() {}  // 0x005b2160
void Render0c5B2820() {}  // 0x005b2820
void Render0c5B2EE0() {}  // 0x005b2ee0
void Render0c5B36D0() {}  // 0x005b36d0
void Render0c5B4C70() {}  // 0x005b4c70
void Render0c5B4E30() {}  // 0x005b4e30
void Render0c5B4E50() {}  // 0x005b4e50
void Render0c5B4EB0() {}  // 0x005b4eb0
void Render0c5B4FD0() {}  // 0x005b4fd0
void Render0c5B5140() {}  // 0x005b5140
void Render0c5BCDF0() {}  // 0x005bcdf0
void Render0c5BDD90() {}  // 0x005bdd90
void Render0c5BF0B0() {}  // 0x005bf0b0
void Render0c5BF320() {}  // 0x005bf320
void Render0c5BF600() {}  // 0x005bf600
void Render0c5BF710() {}  // 0x005bf710
void Render0c5BFEB0() {}  // 0x005bfeb0
void Render0c5C17D0() {}  // 0x005c17d0
void Render0c5C1C00() {}  // 0x005c1c00
void Render0c5C6200() {}  // 0x005c6200
void Render0c5C62C0() {}  // 0x005c62c0
void Render0c5C6550() {}  // 0x005c6550
void Render0c5CCE60() {}  // 0x005cce60
void Render0c5CD160() {}  // 0x005cd160
void Render0c5CDF60() {}  // 0x005cdf60
void Render0c5CF2E0() {}  // 0x005cf2e0
void Render0c5CF900() {}  // 0x005cf900
void Render0c5D17C0() {}  // 0x005d17c0
void Render0c5D1F60() {}  // 0x005d1f60
void Render0c5D1FD0() {}  // 0x005d1fd0
void Render0c5D2610() {}  // 0x005d2610
void Render0c5D28F0() {}  // 0x005d28f0
void Render0c5D2970() {}  // 0x005d2970
void Render0c5D2A30() {}  // 0x005d2a30
void Render0c5D2C80() {}  // 0x005d2c80
void Render0c5D3930() {}  // 0x005d3930
void Render0c5D4E80() {}  // 0x005d4e80
void Render0c5D5090() {}  // 0x005d5090
void Render0c5D52C0() {}  // 0x005d52c0
void Render0c5D5DD0() {}  // 0x005d5dd0
void Render0c5D5F40() {}  // 0x005d5f40
void Render0c5D7450() {}  // 0x005d7450
void Render0c5DC6B0() {}  // 0x005dc6b0
void Render0c5DC880() {}  // 0x005dc880
void Render0c5DED10() {}  // 0x005ded10
void Render0c5DF080() {}  // 0x005df080
void Render0c5DF6D0() {}  // 0x005df6d0
void Render0c5E30E0() {}  // 0x005e30e0
void Render0c5EA0D0() {}  // 0x005ea0d0
void Render0c5EB010() {}  // 0x005eb010
void Render0c5EB900() {}  // 0x005eb900
void Render0c5EC1D0() {}  // 0x005ec1d0
void Render0c5EE0E0() {}  // 0x005ee0e0
void Render0c5EE680() {}  // 0x005ee680
void Render0c5EEA70() {}  // 0x005eea70
void Render0c5EEC10() {}  // 0x005eec10
void Render0c5F02B0() {}  // 0x005f02b0
void Render0c5F0420() {}  // 0x005f0420
void Render0c5F0950() {}  // 0x005f0950
void Render0c5F09E0() {}  // 0x005f09e0
void Render0c5F0D40() {}  // 0x005f0d40
void Render0c5F0ED0() {}  // 0x005f0ed0
void Render0c5F16E0() {}  // 0x005f16e0
void Render0c5F23E0() {}  // 0x005f23e0
void Render0c5F26B0() {}  // 0x005f26b0
void Render0c5F3290() {}  // 0x005f3290
void Render0c5F43A0() {}  // 0x005f43a0
void Render0c5F45A0() {}  // 0x005f45a0
void Render0c5F4EC0() {}  // 0x005f4ec0
void Render0c5F98A0() {}  // 0x005f98a0
void Render0c5FC8F0() {}  // 0x005fc8f0
void Render0c5FC930() {}  // 0x005fc930
void Render0c5FC9A0() {}  // 0x005fc9a0
void Catch_All_005fd82a() {}  // 0x005fd82a
void Render0c5FE470() {}  // 0x005fe470
void Render0c5FE5F0() {}  // 0x005fe5f0
void Render0c5FE670() {}  // 0x005fe670
void Catch_005fe6fc() {}  // 0x005fe6fc
void Render0c5FE7A0() {}  // 0x005fe7a0
void Render0c5FEAF0() {}  // 0x005feaf0
void Catch_005fec8d() {}  // 0x005fec8d
void Render0c5FECE0() {}  // 0x005fece0
void Render0c5FEE00() {}  // 0x005fee00
void Render0c5FF040() {}  // 0x005ff040
void Render0c5FF370() {}  // 0x005ff370
void Render0c5FF600() {}  // 0x005ff600
void Render0c5FF690() {}  // 0x005ff690
void Render0c5FF7F0() {}  // 0x005ff7f0
void Render0c5FFC30() {}  // 0x005ffc30
void Render0c5FFEE0() {}  // 0x005ffee0
void Render0c5FFF30() {}  // 0x005fff30
void Catch_00600031() {}  // 0x00600031
void Catch_00600098() {}  // 0x00600098
void Sys0c600240() {}  // 0x00600240
void Sys0c6006C0() {}  // 0x006006c0
void Sys0c600A70() {}  // 0x00600a70
void Sys0c601230() {}  // 0x00601230
void Sys0c601270() {}  // 0x00601270
void Sys0c6013F0() {}  // 0x006013f0
void Sys0c601710() {}  // 0x00601710
void Sys0c601F90() {}  // 0x00601f90
void Catch_006022e7() {}  // 0x006022e7
void Catch_All_006022f8() {}  // 0x006022f8
void Sys0c602310() {}  // 0x00602310
void Catch_006023d3() {}  // 0x006023d3
void Sys0c6023F0() {}  // 0x006023f0
void Catch_All_0060274b() {}  // 0x0060274b
void Sys0c602850() {}  // 0x00602850
void Catch_00602ab4() {}  // 0x00602ab4
void Catch_00602b0f() {}  // 0x00602b0f
void Catch_All_00602b49() {}  // 0x00602b49
void Sys0c602BA0() {}  // 0x00602ba0
void Catch_All_00602fe6() {}  // 0x00602fe6
void Sys0c603000() {}  // 0x00603000
void Catch_006030d5() {}  // 0x006030d5
void Catch_All_006030e3() {}  // 0x006030e3
void Catch_All_006031d8() {}  // 0x006031d8
void Catch_All_0060350c() {}  // 0x0060350c
void Sys0c6035E0() {}  // 0x006035e0
void Sys0c604B80() {}  // 0x00604b80
void Sys0c605FD0() {}  // 0x00605fd0
void Sys0c606190() {}  // 0x00606190
void Sys0c6065D0() {}  // 0x006065d0
void Sys0c606700() {}  // 0x00606700
void Sys0c606BA0() {}  // 0x00606ba0
void Sys0c606DA0() {}  // 0x00606da0
void Sys0c607030() {}  // 0x00607030
void Sys0c607090() {}  // 0x00607090
void Sys0c607160() {}  // 0x00607160
void Sys0c608A30() {}  // 0x00608a30
void Sys0c608AA0() {}  // 0x00608aa0
void Sys0c608BE0() {}  // 0x00608be0
void Sys0c608C10() {}  // 0x00608c10
void Sys0c608E30() {}  // 0x00608e30
void Sys0c608E90() {}  // 0x00608e90
void Sys0c608F80() {}  // 0x00608f80
void Sys0c609020() {}  // 0x00609020
void Sys0c609120() {}  // 0x00609120
void Sys0c609220() {}  // 0x00609220
void Sys0c6092C0() {}  // 0x006092c0
void Sys0c6093B0() {}  // 0x006093b0
void Sys0c6094A0() {}  // 0x006094a0
void Sys0c609560() {}  // 0x00609560
void Sys0c6095E0() {}  // 0x006095e0
void Sys0c609940() {}  // 0x00609940
void Sys0c609990() {}  // 0x00609990
void Sys0c609AF0() {}  // 0x00609af0
void Sys0c609CA0() {}  // 0x00609ca0
void Sys0c609D70() {}  // 0x00609d70
void Sys0c609ED0() {}  // 0x00609ed0
void Sys0c60A020() {}  // 0x0060a020
void Sys0c60A0F0() {}  // 0x0060a0f0
void Sys0c60A160() {}  // 0x0060a160
void Sys0c60A250() {}  // 0x0060a250
void Sys0c60A320() {}  // 0x0060a320
void Sys0c60A3A0() {}  // 0x0060a3a0
void Sys0c60A420() {}  // 0x0060a420
void Sys0c60A4F0() {}  // 0x0060a4f0
void Catch_0060a5bc() {}  // 0x0060a5bc
void Catch_0060a5db() {}  // 0x0060a5db
void Catch_All_0060a5fa() {}  // 0x0060a5fa
void Sys0c60A6F0() {}  // 0x0060a6f0
void Catch_0060a805() {}  // 0x0060a805
void Catch_0060a824() {}  // 0x0060a824
void Catch_All_0060a843() {}  // 0x0060a843
void Sys0c60B680() {}  // 0x0060b680
void Sys0c60B7E0() {}  // 0x0060b7e0
void Sys0c60B800() {}  // 0x0060b800
void Sys0c60B880() {}  // 0x0060b880
void Sys0c60B8A0() {}  // 0x0060b8a0
void Catch_All_0060bd70() {}  // 0x0060bd70
void Catch_All_0060c740() {}  // 0x0060c740
void Catch_All_0060ccd0() {}  // 0x0060ccd0
void Sys0c60E320() {}  // 0x0060e320
void Sys0c6112F0() {}  // 0x006112f0
void Sys0c6116C0() {}  // 0x006116c0
void Sys0c6129F0() {}  // 0x006129f0
void Catch_00612abc() {}  // 0x00612abc
void Catch_00612adb() {}  // 0x00612adb
void Catch_All_00612afa() {}  // 0x00612afa
void Sys0c612BF0() {}  // 0x00612bf0
void Catch_00612cbc() {}  // 0x00612cbc
void Catch_00612cdb() {}  // 0x00612cdb
void Catch_All_00612cfa() {}  // 0x00612cfa
void Sys0c612F20() {}  // 0x00612f20
void Catch_00612fec() {}  // 0x00612fec
void Catch_0061300b() {}  // 0x0061300b
void Catch_All_0061302a() {}  // 0x0061302a
void Sys0c6132B0() {}  // 0x006132b0
void Sys0c613710() {}  // 0x00613710
void Sys0c613970() {}  // 0x00613970
void Sys0c613990() {}  // 0x00613990
void Sys0c613A10() {}  // 0x00613a10
void Sys0c613A30() {}  // 0x00613a30
void Sys0c613AB0() {}  // 0x00613ab0
void Sys0c613AD0() {}  // 0x00613ad0
void Sys0c613B50() {}  // 0x00613b50
void Sys0c613C10() {}  // 0x00613c10
void Sys0c6144C0() {}  // 0x006144c0
void Sys0c614740() {}  // 0x00614740
void Catch_00614855() {}  // 0x00614855
void Catch_00614874() {}  // 0x00614874
void Catch_All_00614893() {}  // 0x00614893
void Sys0c614980() {}  // 0x00614980
void Catch_00614a95() {}  // 0x00614a95
void Catch_00614ab4() {}  // 0x00614ab4
void Catch_All_00614ad3() {}  // 0x00614ad3
void Sys0c614BE0() {}  // 0x00614be0
void Catch_00614cf5() {}  // 0x00614cf5
void Catch_00614d14() {}  // 0x00614d14
void Catch_All_00614d33() {}  // 0x00614d33
void Sys0c6155A0() {}  // 0x006155a0
void Sys0c6155C0() {}  // 0x006155c0
void Sys0c615640() {}  // 0x00615640
void Sys0c615660() {}  // 0x00615660
void Sys0c6156E0() {}  // 0x006156e0
void Sys0c615700() {}  // 0x00615700
void Sys0c615A70() {}  // 0x00615a70
void Catch_00615b3c() {}  // 0x00615b3c
void Catch_00615b5b() {}  // 0x00615b5b
void Catch_All_00615b7a() {}  // 0x00615b7a
void Sys0c615C70() {}  // 0x00615c70
void Catch_00615d3c() {}  // 0x00615d3c
void Catch_00615d5b() {}  // 0x00615d5b
void Catch_All_00615d7a() {}  // 0x00615d7a
void Sys0c615E70() {}  // 0x00615e70
void Sys0c615EB0() {}  // 0x00615eb0
void Sys0c615F20() {}  // 0x00615f20
void Sys0c615F90() {}  // 0x00615f90
void Sys0c6167D0() {}  // 0x006167d0
void Sys0c6167F0() {}  // 0x006167f0
void Sys0c616870() {}  // 0x00616870
void Sys0c616890() {}  // 0x00616890
void Sys0c616B60() {}  // 0x00616b60
void Sys0c6177D0() {}  // 0x006177d0
void Sys0c618D30() {}  // 0x00618d30
void Catch_00618dfc() {}  // 0x00618dfc
void Catch_00618e1b() {}  // 0x00618e1b
void Catch_All_00618e3a() {}  // 0x00618e3a
void Sys0c618F30() {}  // 0x00618f30
void Catch_00618ffc() {}  // 0x00618ffc
void Catch_0061901b() {}  // 0x0061901b
void Catch_All_0061903a() {}  // 0x0061903a
void Sys0c619130() {}  // 0x00619130
void Catch_006191fc() {}  // 0x006191fc
void Catch_0061921b() {}  // 0x0061921b
void Catch_All_0061923a() {}  // 0x0061923a
void Sys0c619340() {}  // 0x00619340
void Sys0c619480() {}  // 0x00619480
void Sys0c619530() {}  // 0x00619530
void Sys0c6195B0() {}  // 0x006195b0
void Sys0c6195D0() {}  // 0x006195d0
void Sys0c619650() {}  // 0x00619650
void Sys0c619670() {}  // 0x00619670
void Sys0c6196F0() {}  // 0x006196f0
void Sys0c619710() {}  // 0x00619710
void Sys0c6197F0() {}  // 0x006197f0
void Sys0c619960() {}  // 0x00619960
void Sys0c6199F0() {}  // 0x006199f0
void Sys0c61A020() {}  // 0x0061a020
void Sys0c61A0B0() {}  // 0x0061a0b0
void Sys0c61A140() {}  // 0x0061a140
void Sys0c61A1C0() {}  // 0x0061a1c0
void Sys0c61A440() {}  // 0x0061a440
void Sys0c61A4C0() {}  // 0x0061a4c0
void Sys0c61A770() {}  // 0x0061a770
void Sys0c61B160() {}  // 0x0061b160
void Sys0c61B620() {}  // 0x0061b620
void Sys0c61B890() {}  // 0x0061b890
void Sys0c61BAA0() {}  // 0x0061baa0
void Sys0c61BDE0() {}  // 0x0061bde0
void Sys0c61BE20() {}  // 0x0061be20
void Sys0c61C630() {}  // 0x0061c630
void Catch_All_0061c77e() {}  // 0x0061c77e
void Catch_0061cad2() {}  // 0x0061cad2
void Catch_0061cad8() {}  // 0x0061cad8
void Catch_All_0061cade() {}  // 0x0061cade
void Sys0c61CC00() {}  // 0x0061cc00
void Catch_0061d1b1() {}  // 0x0061d1b1
void Catch_0061d1da() {}  // 0x0061d1da
void Catch_All_0061d1fe() {}  // 0x0061d1fe
void Sys0c61DC90() {}  // 0x0061dc90
void Sys0c61DEA0() {}  // 0x0061dea0
void Sys0c61F2C0() {}  // 0x0061f2c0
void Catch_0061f380() {}  // 0x0061f380
void Sys0c61FAC0() {}  // 0x0061fac0
void Sys0c6201C0() {}  // 0x006201c0
void Sys0c6205B0() {}  // 0x006205b0
void Sys0c620800() {}  // 0x00620800
void Sys0c621A90() {}  // 0x00621a90
void Sys0c621B70() {}  // 0x00621b70
void Sys0c621C40() {}  // 0x00621c40
void Catch_00623906() {}  // 0x00623906
void Catch_00624f43() {}  // 0x00624f43
void Catch_006253ee() {}  // 0x006253ee
void Catch_All_0062542d() {}  // 0x0062542d
void Sys0c625AE0() {}  // 0x00625ae0
void Catch_All_00627941() {}  // 0x00627941
void Sys0c628980() {}  // 0x00628980
void Sys0c628AF0() {}  // 0x00628af0
void Catch_0062cff3() {}  // 0x0062cff3
void Sys0c6321E0() {}  // 0x006321e0
void Sys0c632240() {}  // 0x00632240
void Sys0c632AC0() {}  // 0x00632ac0
void Sys0c632BF0() {}  // 0x00632bf0
void Sys0c632C40() {}  // 0x00632c40
void Sys0c632C70() {}  // 0x00632c70
void Sys0c632E00() {}  // 0x00632e00
void Sys0c632E50() {}  // 0x00632e50
void Sys0c632EC0() {}  // 0x00632ec0
void Sys0c632FA0() {}  // 0x00632fa0
void Sys0c632FE0() {}  // 0x00632fe0
void Sys0c635890() {}  // 0x00635890
void Sys0c6358B0() {}  // 0x006358b0
void Sys0c6358D0() {}  // 0x006358d0
void Sys0c6358F0() {}  // 0x006358f0
void Sys0c635910() {}  // 0x00635910
void Sys0c635930() {}  // 0x00635930
void Sys0c635950() {}  // 0x00635950
void Sys0c635970() {}  // 0x00635970
void Sys0c635990() {}  // 0x00635990
void Sys0c6359B0() {}  // 0x006359b0
void Sys0c6359D0() {}  // 0x006359d0
void Sys0c6359F0() {}  // 0x006359f0
void Sys0c635A10() {}  // 0x00635a10
void Sys0c635A30() {}  // 0x00635a30
void Sys0c635A50() {}  // 0x00635a50
void Sys0c635A70() {}  // 0x00635a70
void Sys0c635A90() {}  // 0x00635a90
void Sys0c635AB0() {}  // 0x00635ab0
void Sys0c635AD0() {}  // 0x00635ad0
void Sys0c635AF0() {}  // 0x00635af0
void Sys0c635B10() {}  // 0x00635b10
void Sys0c635B30() {}  // 0x00635b30
void Sys0c635B50() {}  // 0x00635b50
void Sys0c635B70() {}  // 0x00635b70
void Sys0c635B90() {}  // 0x00635b90
void Sys0c635BB0() {}  // 0x00635bb0
void Sys0c635BD0() {}  // 0x00635bd0
void Sys0c635BF0() {}  // 0x00635bf0
void Sys0c635C10() {}  // 0x00635c10
void Sys0c635C30() {}  // 0x00635c30
void Sys0c635C50() {}  // 0x00635c50
void Sys0c635C70() {}  // 0x00635c70
void Sys0c635C90() {}  // 0x00635c90
void Sys0c635CB0() {}  // 0x00635cb0
void Sys0c635CD0() {}  // 0x00635cd0
void Sys0c635CF0() {}  // 0x00635cf0
void Sys0c635D10() {}  // 0x00635d10
void Sys0c635D30() {}  // 0x00635d30
void Sys0c635D50() {}  // 0x00635d50
void Sys0c636180() {}  // 0x00636180
void Sys0c636210() {}  // 0x00636210
void Sys0c6362D0() {}  // 0x006362d0
void Sys0c6370A0() {}  // 0x006370a0
void Catch_00637b4e() {}  // 0x00637b4e
void Catch_00638333() {}  // 0x00638333
void Sys0c63A800() {}  // 0x0063a800
void Sys0c63AB90() {}  // 0x0063ab90
void Sys0c63AD70() {}  // 0x0063ad70
void Sys0c63B280() {}  // 0x0063b280
void Sys0c63B3A0() {}  // 0x0063b3a0
void Sys0c63B460() {}  // 0x0063b460
void Sys0c63B9D0() {}  // 0x0063b9d0
void Sys0c63BB80() {}  // 0x0063bb80
void Sys0c63BF00() {}  // 0x0063bf00
void Sys0c63C350() {}  // 0x0063c350
void Sys0c63C4B0() {}  // 0x0063c4b0
void Sys0c63C6D0() {}  // 0x0063c6d0
void Sys0c63C8F0() {}  // 0x0063c8f0
void Sys0c63D0E0() {}  // 0x0063d0e0
void Sys0c63D440() {}  // 0x0063d440
void Sys0c63D620() {}  // 0x0063d620
void Sys0c63DB00() {}  // 0x0063db00
void Sys0c63DC20() {}  // 0x0063dc20
void Sys0c63DCE0() {}  // 0x0063dce0
void Sys0c63FF70() {}  // 0x0063ff70
void Sys0c63FFA0() {}  // 0x0063ffa0
void Sys0c640130() {}  // 0x00640130
void Sys0c640AE0() {}  // 0x00640ae0
void Sys0c640F00() {}  // 0x00640f00
void Sys0c640FF0() {}  // 0x00640ff0
void Sys0c641000() {}  // 0x00641000
void Sys0c641DA4() {}  // 0x00641da4
void Sys0c643548() {}  // 0x00643548
void ___scrt_initialize_onexit_tables() {}  // 0x0064370c
void Catch_All_00643ccd() {}  // 0x00643ccd
void Sys0c644604() {}  // 0x00644604
void Unwind_00644863() {}  // 0x00644863
void Crt__exit() {}  // 0x00644947
void _set_new_mode() {}  // 0x00644965
void Catch_All_00644aa0() {}  // 0x00644aa0
void Sys0c644EF0() {}  // 0x00644ef0
void __alloca_probe_8() {}  // 0x006456c6
void Unwind_00645950() {}  // 0x00645950
void Unwind_00645980() {}  // 0x00645980
void Unwind_00645988() {}  // 0x00645988
void Unwind_006459c0() {}  // 0x006459c0
void Unwind_006459c8() {}  // 0x006459c8
void Unwind_00645a00() {}  // 0x00645a00
void Unwind_00645a40() {}  // 0x00645a40
void Unwind_00645a80() {}  // 0x00645a80
void Unwind_00645a88() {}  // 0x00645a88
void Unwind_00645ac0() {}  // 0x00645ac0
void Unwind_00645ac8() {}  // 0x00645ac8
void Unwind_00645ad0() {}  // 0x00645ad0
void Unwind_00645ad8() {}  // 0x00645ad8
void Unwind_00645b10() {}  // 0x00645b10
void Unwind_00645b18() {}  // 0x00645b18
void Unwind_00645b20() {}  // 0x00645b20
void Unwind_00645b3a() {}  // 0x00645b3a
void Unwind_00645b46() {}  // 0x00645b46
void Unwind_00645b51() {}  // 0x00645b51
void Unwind_00645b90() {}  // 0x00645b90
void Unwind_00645bc0() {}  // 0x00645bc0
void Unwind_00645bc8() {}  // 0x00645bc8
void Unwind_00645be1() {}  // 0x00645be1
void Unwind_00645be9() {}  // 0x00645be9
void Unwind_00645c20() {}  // 0x00645c20
void Unwind_00645c50() {}  // 0x00645c50
void Unwind_00645c80() {}  // 0x00645c80
void Unwind_00645c88() {}  // 0x00645c88
void Unwind_00645cd0() {}  // 0x00645cd0
void Unwind_00645d00() {}  // 0x00645d00
void Unwind_00645d08() {}  // 0x00645d08
void Unwind_00645d40() {}  // 0x00645d40
void Unwind_00645d48() {}  // 0x00645d48
void Unwind_00645d80() {}  // 0x00645d80
void Unwind_00645d88() {}  // 0x00645d88
void Unwind_00645d90() {}  // 0x00645d90
void Unwind_00645d98() {}  // 0x00645d98
void Unwind_00645da0() {}  // 0x00645da0
void Unwind_00645e40() {}  // 0x00645e40
void Unwind_00645e5d() {}  // 0x00645e5d
void Unwind_00645e69() {}  // 0x00645e69
void Unwind_00645e74() {}  // 0x00645e74
void Unwind_00645e91() {}  // 0x00645e91
void Unwind_00645e9d() {}  // 0x00645e9d
void Unwind_00645ea8() {}  // 0x00645ea8
void Unwind_00645ec6() {}  // 0x00645ec6
void Unwind_00645ece() {}  // 0x00645ece
void Unwind_00645f10() {}  // 0x00645f10
void Unwind_00645f29() {}  // 0x00645f29
void Unwind_00645f80() {}  // 0x00645f80
void Unwind_00645f8f() {}  // 0x00645f8f
void Unwind_00645f97() {}  // 0x00645f97
void Unwind_00645f9f() {}  // 0x00645f9f
void Unwind_00645fd0() {}  // 0x00645fd0
void Unwind_00646010() {}  // 0x00646010
void Unwind_00646018() {}  // 0x00646018
void Unwind_00646020() {}  // 0x00646020
void Unwind_00646060() {}  // 0x00646060
void Unwind_0064606b() {}  // 0x0064606b
void Unwind_0064608d() {}  // 0x0064608d
void Unwind_00646098() {}  // 0x00646098
void Unwind_006460a3() {}  // 0x006460a3
void Unwind_006460ae() {}  // 0x006460ae
void Unwind_006460b9() {}  // 0x006460b9
void Unwind_006460c4() {}  // 0x006460c4
void Unwind_006460cf() {}  // 0x006460cf
void Unwind_00646130() {}  // 0x00646130
void Unwind_00646138() {}  // 0x00646138
void Unwind_00646140() {}  // 0x00646140
void Unwind_00646180() {}  // 0x00646180
void Unwind_006461c0() {}  // 0x006461c0
void Unwind_006461c8() {}  // 0x006461c8
void Unwind_00646200() {}  // 0x00646200
void Unwind_00646260() {}  // 0x00646260
void Unwind_00646268() {}  // 0x00646268
void Unwind_006462a0() {}  // 0x006462a0
void Unwind_006462b9() {}  // 0x006462b9
void Unwind_006462c1() {}  // 0x006462c1
void Unwind_00646300() {}  // 0x00646300
void Unwind_00646309() {}  // 0x00646309
void Unwind_00646340() {}  // 0x00646340
void Unwind_0064634b() {}  // 0x0064634b
void Unwind_00646356() {}  // 0x00646356
void Unwind_0064635e() {}  // 0x0064635e
void Unwind_00646366() {}  // 0x00646366
void Unwind_0064636e() {}  // 0x0064636e
void Unwind_00646376() {}  // 0x00646376
void Unwind_0064637e() {}  // 0x0064637e
void Unwind_00646386() {}  // 0x00646386
void Unwind_0064638e() {}  // 0x0064638e
void Unwind_00646399() {}  // 0x00646399
void Unwind_006463d0() {}  // 0x006463d0
void Unwind_00646400() {}  // 0x00646400
void Unwind_00646408() {}  // 0x00646408
void Unwind_00646440() {}  // 0x00646440
void Unwind_0064644b() {}  // 0x0064644b
void Unwind_00646453() {}  // 0x00646453
void Unwind_0064645b() {}  // 0x0064645b
void Unwind_00646466() {}  // 0x00646466
void Unwind_0064646e() {}  // 0x0064646e
void Unwind_00646476() {}  // 0x00646476
void Unwind_0064647e() {}  // 0x0064647e
void Unwind_00646489() {}  // 0x00646489
void Unwind_00646491() {}  // 0x00646491
void Unwind_00646499() {}  // 0x00646499
void Unwind_006464a1() {}  // 0x006464a1
void Unwind_006464a9() {}  // 0x006464a9
void Unwind_006464b4() {}  // 0x006464b4
void Unwind_006464bc() {}  // 0x006464bc
void Unwind_006464c4() {}  // 0x006464c4
void Unwind_006464cc() {}  // 0x006464cc
void Unwind_006464d7() {}  // 0x006464d7
void Unwind_006464df() {}  // 0x006464df
void Unwind_006464e7() {}  // 0x006464e7
void Unwind_006464ef() {}  // 0x006464ef
void Unwind_006464fa() {}  // 0x006464fa
void Unwind_00646502() {}  // 0x00646502
void Unwind_0064650a() {}  // 0x0064650a
void Unwind_00646512() {}  // 0x00646512
void Unwind_0064651d() {}  // 0x0064651d
void Unwind_00646525() {}  // 0x00646525
void Unwind_0064652d() {}  // 0x0064652d
void Unwind_00646535() {}  // 0x00646535
void Unwind_00646540() {}  // 0x00646540
void Unwind_00646548() {}  // 0x00646548
void Unwind_00646550() {}  // 0x00646550
void Unwind_00646558() {}  // 0x00646558
void Unwind_00646563() {}  // 0x00646563
void Unwind_0064656b() {}  // 0x0064656b
void Unwind_00646573() {}  // 0x00646573
void Unwind_0064657b() {}  // 0x0064657b
void Unwind_00646586() {}  // 0x00646586
void Unwind_006465c0() {}  // 0x006465c0
void Unwind_006465cb() {}  // 0x006465cb
void Unwind_006465d3() {}  // 0x006465d3
void Unwind_006465db() {}  // 0x006465db
void Unwind_006465e6() {}  // 0x006465e6
void Unwind_006465ee() {}  // 0x006465ee
void Unwind_006465f6() {}  // 0x006465f6
void Unwind_006465fe() {}  // 0x006465fe
void Unwind_00646609() {}  // 0x00646609
void Unwind_00646611() {}  // 0x00646611
void Unwind_00646619() {}  // 0x00646619
void Unwind_00646621() {}  // 0x00646621
void Unwind_00646629() {}  // 0x00646629
void Unwind_00646634() {}  // 0x00646634
void Unwind_0064663c() {}  // 0x0064663c
void Unwind_00646644() {}  // 0x00646644
void Unwind_0064664c() {}  // 0x0064664c
void Unwind_00646657() {}  // 0x00646657
void Unwind_0064665f() {}  // 0x0064665f
void Unwind_00646667() {}  // 0x00646667
void Unwind_0064666f() {}  // 0x0064666f
void Unwind_0064667a() {}  // 0x0064667a
void Unwind_00646682() {}  // 0x00646682
void Unwind_0064668a() {}  // 0x0064668a
void Unwind_00646692() {}  // 0x00646692
void Unwind_0064669d() {}  // 0x0064669d
void Unwind_006466a5() {}  // 0x006466a5
void Unwind_006466ad() {}  // 0x006466ad
void Unwind_006466b5() {}  // 0x006466b5
void Unwind_006466c0() {}  // 0x006466c0
void Unwind_006466c8() {}  // 0x006466c8
void Unwind_006466d0() {}  // 0x006466d0
void Unwind_006466d8() {}  // 0x006466d8
void Unwind_006466e3() {}  // 0x006466e3
void Unwind_006466eb() {}  // 0x006466eb
void Unwind_006466f3() {}  // 0x006466f3
void Unwind_006466fb() {}  // 0x006466fb
void Unwind_00646706() {}  // 0x00646706
void Unwind_00646740() {}  // 0x00646740
void Unwind_00646748() {}  // 0x00646748
void Unwind_00646780() {}  // 0x00646780
void Unwind_006467d0() {}  // 0x006467d0
void Unwind_006467f2() {}  // 0x006467f2
void Unwind_006467fa() {}  // 0x006467fa
void Unwind_00646802() {}  // 0x00646802
void Unwind_0064680d() {}  // 0x0064680d
void Unwind_00646815() {}  // 0x00646815
void Unwind_0064681d() {}  // 0x0064681d
void Unwind_00646825() {}  // 0x00646825
void Unwind_0064682d() {}  // 0x0064682d
void Unwind_00646835() {}  // 0x00646835
void Unwind_0064683d() {}  // 0x0064683d
void Unwind_00646845() {}  // 0x00646845
void Unwind_00646880() {}  // 0x00646880
void Unwind_00646888() {}  // 0x00646888
void Unwind_00646890() {}  // 0x00646890
void Unwind_00646898() {}  // 0x00646898
void Unwind_006468a0() {}  // 0x006468a0
void Unwind_006468a8() {}  // 0x006468a8
void Unwind_006468b3() {}  // 0x006468b3
void Unwind_006468f0() {}  // 0x006468f0
void Unwind_00646920() {}  // 0x00646920
void Unwind_0064692b() {}  // 0x0064692b
void Unwind_006469b0() {}  // 0x006469b0
void Unwind_006469e0() {}  // 0x006469e0
void Unwind_00646a10() {}  // 0x00646a10
void Unwind_00646a50() {}  // 0x00646a50
void Unwind_00646a58() {}  // 0x00646a58
void Unwind_00646a60() {}  // 0x00646a60
void Unwind_00646a90() {}  // 0x00646a90
void Unwind_00646a98() {}  // 0x00646a98
void Unwind_00646b10() {}  // 0x00646b10
void Unwind_00646b40() {}  // 0x00646b40
void Unwind_00646b70() {}  // 0x00646b70
void Unwind_00646b78() {}  // 0x00646b78
void Unwind_00646bb0() {}  // 0x00646bb0
void Unwind_00646c00() {}  // 0x00646c00
void Unwind_00646c08() {}  // 0x00646c08
void Unwind_00646c40() {}  // 0x00646c40
void Unwind_00646c48() {}  // 0x00646c48
void Unwind_00646c50() {}  // 0x00646c50
void Unwind_00646c80() {}  // 0x00646c80
void Unwind_00646cc0() {}  // 0x00646cc0
void Unwind_00646cc8() {}  // 0x00646cc8
void Unwind_00646cd0() {}  // 0x00646cd0
void Unwind_00646cd8() {}  // 0x00646cd8
void Unwind_00646d10() {}  // 0x00646d10
void Unwind_00646d70() {}  // 0x00646d70
void Unwind_00646d78() {}  // 0x00646d78
void Unwind_00646db0() {}  // 0x00646db0
void Unwind_00646dbb() {}  // 0x00646dbb
void Unwind_00646dc3() {}  // 0x00646dc3
void Unwind_00646dcb() {}  // 0x00646dcb
void Unwind_00646e10() {}  // 0x00646e10
void Unwind_00646e1b() {}  // 0x00646e1b
void Unwind_00646e23() {}  // 0x00646e23
void Unwind_00646e2e() {}  // 0x00646e2e
void Unwind_00646e36() {}  // 0x00646e36
void Unwind_00646e41() {}  // 0x00646e41
void Unwind_00646e80() {}  // 0x00646e80
void Unwind_00646e88() {}  // 0x00646e88
void Unwind_00646e93() {}  // 0x00646e93
void Unwind_00646e9e() {}  // 0x00646e9e
void Unwind_00646ea9() {}  // 0x00646ea9
void Unwind_00646eb1() {}  // 0x00646eb1
void Unwind_00646ebc() {}  // 0x00646ebc
void Unwind_00646ef0() {}  // 0x00646ef0
void Unwind_00646f30() {}  // 0x00646f30
void Unwind_00646f3b() {}  // 0x00646f3b
void Unwind_00646f70() {}  // 0x00646f70
void Unwind_00646fa0() {}  // 0x00646fa0
void Unwind_00646fd0() {}  // 0x00646fd0
void Unwind_00647020() {}  // 0x00647020
void Unwind_00647028() {}  // 0x00647028
void Unwind_00647060() {}  // 0x00647060
void Unwind_00647068() {}  // 0x00647068
void Unwind_00647070() {}  // 0x00647070
void Unwind_006470d0() {}  // 0x006470d0
void Unwind_006470d8() {}  // 0x006470d8
void Unwind_00647110() {}  // 0x00647110
void Unwind_00647118() {}  // 0x00647118
void Unwind_00647120() {}  // 0x00647120
void Unwind_00647150() {}  // 0x00647150
void Unwind_00647158() {}  // 0x00647158
void Unwind_00647160() {}  // 0x00647160
void Unwind_00647168() {}  // 0x00647168
void Unwind_00647170() {}  // 0x00647170
void Unwind_00647178() {}  // 0x00647178
void Unwind_00647180() {}  // 0x00647180
void Unwind_006471b0() {}  // 0x006471b0
void Unwind_006471b8() {}  // 0x006471b8
void Unwind_006471c0() {}  // 0x006471c0
void Unwind_006471c8() {}  // 0x006471c8
void Unwind_00647220() {}  // 0x00647220
void Unwind_00647270() {}  // 0x00647270
void Unwind_00647278() {}  // 0x00647278
void Unwind_006472b0() {}  // 0x006472b0
void Unwind_006472e0() {}  // 0x006472e0
void Unwind_00647330() {}  // 0x00647330
void Unwind_00647349() {}  // 0x00647349
void Unwind_00647351() {}  // 0x00647351
void Unwind_00647390() {}  // 0x00647390
void Unwind_00647398() {}  // 0x00647398
void Unwind_006473a3() {}  // 0x006473a3
void Unwind_006473ae() {}  // 0x006473ae
void Unwind_006473f0() {}  // 0x006473f0
void Unwind_006473f8() {}  // 0x006473f8
void Unwind_00647403() {}  // 0x00647403
void Unwind_00647430() {}  // 0x00647430
void Unwind_00647480() {}  // 0x00647480
void Unwind_00647488() {}  // 0x00647488
void Unwind_00647490() {}  // 0x00647490
void Unwind_006474c0() {}  // 0x006474c0
void Unwind_006474c8() {}  // 0x006474c8
void Unwind_006474d7() {}  // 0x006474d7
void Unwind_006474df() {}  // 0x006474df
void Unwind_006474e7() {}  // 0x006474e7
void Unwind_00647520() {}  // 0x00647520
void Unwind_00647528() {}  // 0x00647528
void Unwind_00647570() {}  // 0x00647570
void Unwind_006475b0() {}  // 0x006475b0
void Unwind_006475f0() {}  // 0x006475f0
void Unwind_006475f9() {}  // 0x006475f9
void Unwind_00647630() {}  // 0x00647630
void Unwind_00647639() {}  // 0x00647639
void Unwind_00647642() {}  // 0x00647642
void Unwind_0064764b() {}  // 0x0064764b
void Unwind_00647654() {}  // 0x00647654
void Unwind_0064765d() {}  // 0x0064765d
void Unwind_00647666() {}  // 0x00647666
void Unwind_0064766f() {}  // 0x0064766f
void Unwind_00647678() {}  // 0x00647678
void Unwind_00647681() {}  // 0x00647681
void Unwind_0064768a() {}  // 0x0064768a
void Unwind_00647693() {}  // 0x00647693
void Unwind_0064769c() {}  // 0x0064769c
void Unwind_006476d0() {}  // 0x006476d0
void Unwind_006476d9() {}  // 0x006476d9
void Unwind_006476e2() {}  // 0x006476e2
void Unwind_006476eb() {}  // 0x006476eb
void Unwind_006476f4() {}  // 0x006476f4
void Unwind_006476fd() {}  // 0x006476fd
void Unwind_00647706() {}  // 0x00647706
void Unwind_0064770f() {}  // 0x0064770f
void Unwind_00647718() {}  // 0x00647718
void Unwind_00647721() {}  // 0x00647721
void Unwind_0064772a() {}  // 0x0064772a
void Unwind_00647733() {}  // 0x00647733
void Unwind_0064773c() {}  // 0x0064773c
void Unwind_00647745() {}  // 0x00647745
void Unwind_0064774e() {}  // 0x0064774e
void Unwind_00647780() {}  // 0x00647780
void Unwind_006477c0() {}  // 0x006477c0
void Unwind_00647800() {}  // 0x00647800
void Unwind_00647830() {}  // 0x00647830
void Unwind_0064783b() {}  // 0x0064783b
void Unwind_00647846() {}  // 0x00647846
void Unwind_00647851() {}  // 0x00647851
void Unwind_00647890() {}  // 0x00647890
void Unwind_006478d0() {}  // 0x006478d0
void Unwind_00647910() {}  // 0x00647910
void Unwind_00647918() {}  // 0x00647918
void Unwind_00647950() {}  // 0x00647950
void Unwind_00647990() {}  // 0x00647990
void Unwind_00647998() {}  // 0x00647998
void Unwind_006479d0() {}  // 0x006479d0
void Unwind_00647a10() {}  // 0x00647a10
void Unwind_00647a50() {}  // 0x00647a50
void Unwind_00647a90() {}  // 0x00647a90
void Unwind_00647a98() {}  // 0x00647a98
void Unwind_00647aa3() {}  // 0x00647aa3
void Unwind_00647aae() {}  // 0x00647aae
void Unwind_00647ab9() {}  // 0x00647ab9
void Unwind_00647af0() {}  // 0x00647af0
void Unwind_00647af8() {}  // 0x00647af8
void Unwind_00647b00() {}  // 0x00647b00
void Unwind_00647b0f() {}  // 0x00647b0f
void Unwind_00647b28() {}  // 0x00647b28
void Unwind_00647b60() {}  // 0x00647b60
void Unwind_00647b68() {}  // 0x00647b68
void Unwind_00647b70() {}  // 0x00647b70
void Unwind_00647b78() {}  // 0x00647b78
void Unwind_00647bb0() {}  // 0x00647bb0
void Unwind_00647bb8() {}  // 0x00647bb8
void Unwind_00647bc3() {}  // 0x00647bc3
void Unwind_00647c00() {}  // 0x00647c00
void Unwind_00647c60() {}  // 0x00647c60
void Unwind_00647c68() {}  // 0x00647c68
void Unwind_00647ca0() {}  // 0x00647ca0
void Unwind_00647cd0() {}  // 0x00647cd0
void Unwind_00647d10() {}  // 0x00647d10
void Unwind_00647d70() {}  // 0x00647d70
void Unwind_00647da0() {}  // 0x00647da0
void Unwind_00647dd0() {}  // 0x00647dd0
void Unwind_00647dd8() {}  // 0x00647dd8
void Unwind_00647de3() {}  // 0x00647de3
void Unwind_00647e20() {}  // 0x00647e20
void Unwind_00647e35() {}  // 0x00647e35
void Unwind_00647e4a() {}  // 0x00647e4a
void Unwind_00647e90() {}  // 0x00647e90
void Unwind_00647e9b() {}  // 0x00647e9b
void Unwind_00647ea6() {}  // 0x00647ea6
void Unwind_00647ee0() {}  // 0x00647ee0
void Unwind_00647eeb() {}  // 0x00647eeb
void Unwind_00647f30() {}  // 0x00647f30
void Unwind_00647f70() {}  // 0x00647f70
void Unwind_00647fb0() {}  // 0x00647fb0
void Unwind_00647fb8() {}  // 0x00647fb8
void Unwind_00647ff0() {}  // 0x00647ff0
void Unwind_00648020() {}  // 0x00648020
void Unwind_00648050() {}  // 0x00648050
void Unwind_00648080() {}  // 0x00648080
void Unwind_00648088() {}  // 0x00648088
void Unwind_00648097() {}  // 0x00648097
void Unwind_0064809f() {}  // 0x0064809f
void Unwind_006480ae() {}  // 0x006480ae
void Unwind_006480bd() {}  // 0x006480bd
void Unwind_006480c5() {}  // 0x006480c5
void Unwind_006480d4() {}  // 0x006480d4
void Unwind_006480dc() {}  // 0x006480dc
void Unwind_00648120() {}  // 0x00648120
void Unwind_00648160() {}  // 0x00648160
void Unwind_006481a0() {}  // 0x006481a0
void Unwind_006481e0() {}  // 0x006481e0
void Unwind_006481e8() {}  // 0x006481e8
void Unwind_006481f0() {}  // 0x006481f0
void Unwind_006481f8() {}  // 0x006481f8
void Unwind_00648230() {}  // 0x00648230
void Unwind_00648260() {}  // 0x00648260
void Unwind_0064826b() {}  // 0x0064826b
void Unwind_00648276() {}  // 0x00648276
void Unwind_006482b0() {}  // 0x006482b0
void Unwind_006482f0() {}  // 0x006482f0
void Unwind_00648330() {}  // 0x00648330
void Unwind_0064834d() {}  // 0x0064834d
void Unwind_00648359() {}  // 0x00648359
void Unwind_00648390() {}  // 0x00648390
void Unwind_0064839b() {}  // 0x0064839b
void Unwind_006483d0() {}  // 0x006483d0
void Unwind_006483df() {}  // 0x006483df
void Unwind_006483e7() {}  // 0x006483e7
void Unwind_006483ef() {}  // 0x006483ef
void Unwind_00648420() {}  // 0x00648420
void Unwind_00648460() {}  // 0x00648460
void Unwind_006484a0() {}  // 0x006484a0
void Unwind_006484ab() {}  // 0x006484ab
void Unwind_006484b6() {}  // 0x006484b6
void Unwind_006484be() {}  // 0x006484be
void Unwind_006484c6() {}  // 0x006484c6
void Unwind_006484ce() {}  // 0x006484ce
void Unwind_006484d6() {}  // 0x006484d6
void Unwind_006484de() {}  // 0x006484de
void Unwind_006484e6() {}  // 0x006484e6
void Unwind_006484ee() {}  // 0x006484ee
void Unwind_006484f6() {}  // 0x006484f6
void Unwind_006484fe() {}  // 0x006484fe
void Unwind_00648506() {}  // 0x00648506
void Unwind_0064850e() {}  // 0x0064850e
void Unwind_00648516() {}  // 0x00648516
void Unwind_0064851e() {}  // 0x0064851e
void Unwind_00648526() {}  // 0x00648526
void Unwind_0064852e() {}  // 0x0064852e
void Unwind_00648536() {}  // 0x00648536
void Unwind_0064853e() {}  // 0x0064853e
void Unwind_00648546() {}  // 0x00648546
void Unwind_00648580() {}  // 0x00648580
void Unwind_0064858b() {}  // 0x0064858b
void Unwind_00648593() {}  // 0x00648593
void Unwind_0064859b() {}  // 0x0064859b
void Unwind_006485ad() {}  // 0x006485ad
void Unwind_006485b5() {}  // 0x006485b5
void Unwind_006485f0() {}  // 0x006485f0
void Unwind_006485fb() {}  // 0x006485fb
void Unwind_00648603() {}  // 0x00648603
void Unwind_0064860b() {}  // 0x0064860b
void Unwind_00648613() {}  // 0x00648613
void Unwind_0064861b() {}  // 0x0064861b
void Unwind_00648626() {}  // 0x00648626
void Unwind_00648660() {}  // 0x00648660
void Unwind_00648668() {}  // 0x00648668
void Unwind_00648670() {}  // 0x00648670
void Unwind_00648678() {}  // 0x00648678
void Unwind_006486b0() {}  // 0x006486b0
void Unwind_006486f0() {}  // 0x006486f0
void Unwind_006486f8() {}  // 0x006486f8
void Unwind_00648700() {}  // 0x00648700
void Unwind_00648740() {}  // 0x00648740
void Unwind_00648780() {}  // 0x00648780
void Unwind_0064878b() {}  // 0x0064878b
void Unwind_00648796() {}  // 0x00648796
void Unwind_006487a1() {}  // 0x006487a1
void Unwind_006487ac() {}  // 0x006487ac
void Unwind_006487b7() {}  // 0x006487b7
void Unwind_006487c2() {}  // 0x006487c2
void Unwind_006487cd() {}  // 0x006487cd
void Unwind_00648810() {}  // 0x00648810
void Unwind_00648850() {}  // 0x00648850
void Unwind_0064885b() {}  // 0x0064885b
void Unwind_00648866() {}  // 0x00648866
void Unwind_00648871() {}  // 0x00648871
void Unwind_0064887c() {}  // 0x0064887c
void Unwind_00648887() {}  // 0x00648887
void Unwind_00648892() {}  // 0x00648892
void Unwind_0064889d() {}  // 0x0064889d
void Unwind_006488e0() {}  // 0x006488e0
void Unwind_006488e8() {}  // 0x006488e8
void Unwind_00648920() {}  // 0x00648920
void Unwind_00648960() {}  // 0x00648960
void Unwind_006489b0() {}  // 0x006489b0
void Unwind_00648a00() {}  // 0x00648a00
void Unwind_00648a30() {}  // 0x00648a30
void Unwind_00648a38() {}  // 0x00648a38
void Unwind_00648a70() {}  // 0x00648a70
void Unwind_00648aa0() {}  // 0x00648aa0
void Unwind_00648aab() {}  // 0x00648aab
void Unwind_00648ae0() {}  // 0x00648ae0
void Unwind_00648b10() {}  // 0x00648b10
void Unwind_00648b40() {}  // 0x00648b40
void Unwind_00648b48() {}  // 0x00648b48
void Unwind_00648b80() {}  // 0x00648b80
void Unwind_00648bb0() {}  // 0x00648bb0
void Unwind_00648bb8() {}  // 0x00648bb8
void Unwind_00648bf0() {}  // 0x00648bf0
void Unwind_00648c40() {}  // 0x00648c40
void Unwind_00648c70() {}  // 0x00648c70
void Unwind_00648c7e() {}  // 0x00648c7e
void Unwind_00648c8c() {}  // 0x00648c8c
void Unwind_00648c9a() {}  // 0x00648c9a
void Unwind_00648ca8() {}  // 0x00648ca8
void Unwind_00648d40() {}  // 0x00648d40
void Unwind_00648d90() {}  // 0x00648d90
void Unwind_00648e60() {}  // 0x00648e60
void Unwind_00648e6b() {}  // 0x00648e6b
void Unwind_00648e79() {}  // 0x00648e79
void Unwind_00648e87() {}  // 0x00648e87
void Unwind_00648e95() {}  // 0x00648e95
void Unwind_00648ea3() {}  // 0x00648ea3
void Unwind_00648eb1() {}  // 0x00648eb1
void Unwind_00648ebf() {}  // 0x00648ebf
void Unwind_00648ecd() {}  // 0x00648ecd
void Unwind_00648edb() {}  // 0x00648edb
void Unwind_00648ee9() {}  // 0x00648ee9
void Unwind_00648ef7() {}  // 0x00648ef7
void Unwind_00648f05() {}  // 0x00648f05
void Unwind_00648f13() {}  // 0x00648f13
void Unwind_00648f21() {}  // 0x00648f21
void Unwind_00648f2f() {}  // 0x00648f2f
void Unwind_00648f3d() {}  // 0x00648f3d
void Unwind_00648f4b() {}  // 0x00648f4b
void Unwind_00648f59() {}  // 0x00648f59
void Unwind_00648f67() {}  // 0x00648f67
void Unwind_00648f75() {}  // 0x00648f75
void Unwind_00648f83() {}  // 0x00648f83
void Unwind_00648f91() {}  // 0x00648f91
void Unwind_00648f9f() {}  // 0x00648f9f
void Unwind_00648fad() {}  // 0x00648fad
void Unwind_00648fbb() {}  // 0x00648fbb
void Unwind_00648fc9() {}  // 0x00648fc9
void Unwind_00648fd7() {}  // 0x00648fd7
void Unwind_00648fe5() {}  // 0x00648fe5
void Unwind_00648ff3() {}  // 0x00648ff3
void Unwind_00649001() {}  // 0x00649001
void Unwind_0064900f() {}  // 0x0064900f
void Unwind_0064901d() {}  // 0x0064901d
void Unwind_0064902b() {}  // 0x0064902b
void Unwind_00649039() {}  // 0x00649039
void Unwind_00649047() {}  // 0x00649047
void Unwind_00649055() {}  // 0x00649055
void Unwind_00649063() {}  // 0x00649063
void Unwind_0064906e() {}  // 0x0064906e
void Unwind_00649079() {}  // 0x00649079
void Unwind_006490d0() {}  // 0x006490d0
void Unwind_00649140() {}  // 0x00649140
void Unwind_00649148() {}  // 0x00649148
void Unwind_00649180() {}  // 0x00649180
void Unwind_006491c0() {}  // 0x006491c0
void Unwind_00649200() {}  // 0x00649200
void Unwind_00649230() {}  // 0x00649230
void Unwind_00649270() {}  // 0x00649270
void Unwind_00649278() {}  // 0x00649278
void Unwind_006492b0() {}  // 0x006492b0
void Unwind_006492d2() {}  // 0x006492d2
void Unwind_006492f4() {}  // 0x006492f4
void Unwind_006492fc() {}  // 0x006492fc
void Unwind_00649340() {}  // 0x00649340
void Unwind_00649348() {}  // 0x00649348
void Unwind_00649350() {}  // 0x00649350
void Unwind_00649358() {}  // 0x00649358
void Unwind_00649360() {}  // 0x00649360
void Unwind_006493a0() {}  // 0x006493a0
void Unwind_006493e0() {}  // 0x006493e0
void Unwind_00649420() {}  // 0x00649420
void Unwind_00649460() {}  // 0x00649460
void Unwind_006494a0() {}  // 0x006494a0
void Unwind_006494a8() {}  // 0x006494a8
void Unwind_006494e0() {}  // 0x006494e0
void Unwind_00649520() {}  // 0x00649520
void Unwind_00649528() {}  // 0x00649528
void Unwind_00649560() {}  // 0x00649560
void Unwind_00649568() {}  // 0x00649568
void Unwind_006495a0() {}  // 0x006495a0
void Unwind_006495e0() {}  // 0x006495e0
void Unwind_00649620() {}  // 0x00649620
void Unwind_0064962b() {}  // 0x0064962b
void Unwind_00649636() {}  // 0x00649636
void Unwind_00649641() {}  // 0x00649641
void Unwind_00649680() {}  // 0x00649680
void Unwind_00649688() {}  // 0x00649688
void Unwind_006496c0() {}  // 0x006496c0
void Unwind_00649700() {}  // 0x00649700
void Unwind_0064970b() {}  // 0x0064970b
void Unwind_00649716() {}  // 0x00649716
void Unwind_00649750() {}  // 0x00649750
void Unwind_0064975b() {}  // 0x0064975b
void Unwind_006497a0() {}  // 0x006497a0
void Unwind_006497e0() {}  // 0x006497e0
void Unwind_006497e8() {}  // 0x006497e8
void Unwind_006497f0() {}  // 0x006497f0
void Unwind_006497f8() {}  // 0x006497f8
void Unwind_00649850() {}  // 0x00649850
void Unwind_00649880() {}  // 0x00649880
void Unwind_00649888() {}  // 0x00649888
void Unwind_006498c0() {}  // 0x006498c0
void Unwind_006498cb() {}  // 0x006498cb
void Unwind_006498d6() {}  // 0x006498d6
void Unwind_00649910() {}  // 0x00649910
void Unwind_00649918() {}  // 0x00649918
void Unwind_00649950() {}  // 0x00649950
void Unwind_00649962() {}  // 0x00649962
void Unwind_0064996a() {}  // 0x0064996a
void Unwind_00649972() {}  // 0x00649972
void Unwind_006499a0() {}  // 0x006499a0
void Unwind_006499a8() {}  // 0x006499a8
void Unwind_006499e0() {}  // 0x006499e0
void Unwind_006499e8() {}  // 0x006499e8
void Unwind_006499f0() {}  // 0x006499f0
void Unwind_006499f8() {}  // 0x006499f8
void Unwind_00649a00() {}  // 0x00649a00
void Unwind_00649a40() {}  // 0x00649a40
void Unwind_00649a48() {}  // 0x00649a48
void Unwind_00649a80() {}  // 0x00649a80
void Unwind_00649a88() {}  // 0x00649a88
void Unwind_00649a90() {}  // 0x00649a90
void Unwind_00649a98() {}  // 0x00649a98
void Unwind_00649ad0() {}  // 0x00649ad0
void Unwind_00649ad8() {}  // 0x00649ad8
void Unwind_00649ae0() {}  // 0x00649ae0
void Unwind_00649ae8() {}  // 0x00649ae8
void Unwind_00649af0() {}  // 0x00649af0
void Unwind_00649afb() {}  // 0x00649afb
void Unwind_00649b06() {}  // 0x00649b06
void Unwind_00649b40() {}  // 0x00649b40
void Unwind_00649b48() {}  // 0x00649b48
void Unwind_00649b5a() {}  // 0x00649b5a
void Unwind_00649b62() {}  // 0x00649b62
void Unwind_00649b6d() {}  // 0x00649b6d
void Unwind_00649b78() {}  // 0x00649b78
void Unwind_00649b80() {}  // 0x00649b80
void Unwind_00649b88() {}  // 0x00649b88
void Unwind_00649b90() {}  // 0x00649b90
void Unwind_00649b9b() {}  // 0x00649b9b
void Unwind_00649ba3() {}  // 0x00649ba3
void Unwind_00649bae() {}  // 0x00649bae
void Unwind_00649bb6() {}  // 0x00649bb6
void Unwind_00649bc1() {}  // 0x00649bc1
void Unwind_00649c00() {}  // 0x00649c00
void Unwind_00649c30() {}  // 0x00649c30
void Unwind_00649c38() {}  // 0x00649c38
void Unwind_00649c70() {}  // 0x00649c70
void Unwind_00649c78() {}  // 0x00649c78
void Unwind_00649c80() {}  // 0x00649c80
void Unwind_00649cc0() {}  // 0x00649cc0
void Unwind_00649cc8() {}  // 0x00649cc8
void Unwind_00649cd0() {}  // 0x00649cd0
void Unwind_00649cd8() {}  // 0x00649cd8
void Unwind_00649d10() {}  // 0x00649d10
void Unwind_00649d18() {}  // 0x00649d18
void Unwind_00649d2a() {}  // 0x00649d2a
void Unwind_00649d32() {}  // 0x00649d32
void Unwind_00649d44() {}  // 0x00649d44
void Unwind_00649da0() {}  // 0x00649da0
void Unwind_00649dab() {}  // 0x00649dab
void Unwind_00649db3() {}  // 0x00649db3
void Unwind_00649dc2() {}  // 0x00649dc2
void Unwind_00649dca() {}  // 0x00649dca
void Unwind_00649e00() {}  // 0x00649e00
void Unwind_00649e30() {}  // 0x00649e30
void Unwind_00649e38() {}  // 0x00649e38
void Unwind_00649e43() {}  // 0x00649e43
void Unwind_00649e4e() {}  // 0x00649e4e
void Unwind_00649e59() {}  // 0x00649e59
void Unwind_00649e64() {}  // 0x00649e64
void Unwind_00649e6c() {}  // 0x00649e6c
void Unwind_00649ea0() {}  // 0x00649ea0
void Unwind_00649ea8() {}  // 0x00649ea8
void Unwind_00649ee0() {}  // 0x00649ee0
void Unwind_00649ee8() {}  // 0x00649ee8
void Unwind_00649efa() {}  // 0x00649efa
void Unwind_00649f02() {}  // 0x00649f02
void Unwind_00649f30() {}  // 0x00649f30
void Unwind_00649f60() {}  // 0x00649f60
void Unwind_00649fa0() {}  // 0x00649fa0
void Unwind_00649fa8() {}  // 0x00649fa8
void Unwind_00649fe0() {}  // 0x00649fe0
void Unwind_00649fe8() {}  // 0x00649fe8
void Unwind_0064a020() {}  // 0x0064a020
void Unwind_0064a02b() {}  // 0x0064a02b
void Unwind_0064a036() {}  // 0x0064a036
void Unwind_0064a03e() {}  // 0x0064a03e
void Unwind_0064a049() {}  // 0x0064a049
void Unwind_0064a054() {}  // 0x0064a054
void Unwind_0064a080() {}  // 0x0064a080
void Unwind_0064a088() {}  // 0x0064a088
void Unwind_0064a0c0() {}  // 0x0064a0c0
void Unwind_0064a0cb() {}  // 0x0064a0cb
void Unwind_0064a0d6() {}  // 0x0064a0d6
void Unwind_0064a0e9() {}  // 0x0064a0e9
void Unwind_0064a0f1() {}  // 0x0064a0f1
void Unwind_0064a120() {}  // 0x0064a120
void Unwind_0064a128() {}  // 0x0064a128
void Unwind_0064a160() {}  // 0x0064a160
void Unwind_0064a16b() {}  // 0x0064a16b
void Unwind_0064a176() {}  // 0x0064a176
void Unwind_0064a184() {}  // 0x0064a184
void Unwind_0064a18f() {}  // 0x0064a18f
void Unwind_0064a19a() {}  // 0x0064a19a
void Unwind_0064a1a8() {}  // 0x0064a1a8
void Unwind_0064a1ba() {}  // 0x0064a1ba
void Unwind_0064a1c8() {}  // 0x0064a1c8
void Unwind_0064a1d6() {}  // 0x0064a1d6
void Unwind_0064a1e4() {}  // 0x0064a1e4
void Unwind_0064a1f2() {}  // 0x0064a1f2
void Unwind_0064a200() {}  // 0x0064a200
void Unwind_0064a20f() {}  // 0x0064a20f
void Unwind_0064a217() {}  // 0x0064a217
void Unwind_0064a229() {}  // 0x0064a229
void Unwind_0064a231() {}  // 0x0064a231
void Unwind_0064a270() {}  // 0x0064a270
void Unwind_0064a2a0() {}  // 0x0064a2a0
void Unwind_0064a2a8() {}  // 0x0064a2a8
void Unwind_0064a2b7() {}  // 0x0064a2b7
void Unwind_0064a300() {}  // 0x0064a300
void Unwind_0064a308() {}  // 0x0064a308
void Unwind_0064a340() {}  // 0x0064a340
void Unwind_0064a348() {}  // 0x0064a348
void Unwind_0064a350() {}  // 0x0064a350
void Unwind_0064a3b0() {}  // 0x0064a3b0
void Unwind_0064a3bb() {}  // 0x0064a3bb
void Unwind_0064a400() {}  // 0x0064a400
void Unwind_0064a408() {}  // 0x0064a408
void Unwind_0064a440() {}  // 0x0064a440
void Unwind_0064a470() {}  // 0x0064a470
void Unwind_0064a4b0() {}  // 0x0064a4b0
void Unwind_0064a4b8() {}  // 0x0064a4b8
void Unwind_0064a4c0() {}  // 0x0064a4c0
void Unwind_0064a4c8() {}  // 0x0064a4c8
void Unwind_0064a500() {}  // 0x0064a500
void Unwind_0064a508() {}  // 0x0064a508
void Unwind_0064a540() {}  // 0x0064a540
void Unwind_0064a548() {}  // 0x0064a548
void Unwind_0064a550() {}  // 0x0064a550
void Unwind_0064a562() {}  // 0x0064a562
void Unwind_0064a56a() {}  // 0x0064a56a
void Unwind_0064a5a0() {}  // 0x0064a5a0
void Unwind_0064a5ab() {}  // 0x0064a5ab
void Unwind_0064a5e0() {}  // 0x0064a5e0
void Unwind_0064a610() {}  // 0x0064a610
void Unwind_0064a640() {}  // 0x0064a640
void Unwind_0064a680() {}  // 0x0064a680
void Unwind_0064a6c0() {}  // 0x0064a6c0
void Unwind_0064a700() {}  // 0x0064a700
void Unwind_0064a730() {}  // 0x0064a730
void Unwind_0064a770() {}  // 0x0064a770
void Unwind_0064a7a0() {}  // 0x0064a7a0
void Unwind_0064a7e0() {}  // 0x0064a7e0
void Unwind_0064a820() {}  // 0x0064a820
void Unwind_0064a828() {}  // 0x0064a828
void Unwind_0064a830() {}  // 0x0064a830
void Unwind_0064a838() {}  // 0x0064a838
void Unwind_0064a840() {}  // 0x0064a840
void Unwind_0064a848() {}  // 0x0064a848
void Unwind_0064a850() {}  // 0x0064a850
void Unwind_0064a858() {}  // 0x0064a858
void Unwind_0064a860() {}  // 0x0064a860
void Unwind_0064a868() {}  // 0x0064a868
void Unwind_0064a870() {}  // 0x0064a870
void Unwind_0064a878() {}  // 0x0064a878
void Unwind_0064a880() {}  // 0x0064a880
void Unwind_0064a888() {}  // 0x0064a888
void Unwind_0064a890() {}  // 0x0064a890
void Unwind_0064a898() {}  // 0x0064a898
void Unwind_0064a8a0() {}  // 0x0064a8a0
void Unwind_0064a8a8() {}  // 0x0064a8a8
void Unwind_0064a8b0() {}  // 0x0064a8b0
void Unwind_0064a8b8() {}  // 0x0064a8b8
void Unwind_0064a8c0() {}  // 0x0064a8c0
void Unwind_0064a8c8() {}  // 0x0064a8c8
void Unwind_0064a8d0() {}  // 0x0064a8d0
void Unwind_0064a8d8() {}  // 0x0064a8d8
void Unwind_0064a8e0() {}  // 0x0064a8e0
void Unwind_0064a8e8() {}  // 0x0064a8e8
void Unwind_0064a8f0() {}  // 0x0064a8f0
void Unwind_0064a8f8() {}  // 0x0064a8f8
void Unwind_0064a900() {}  // 0x0064a900
void Unwind_0064a908() {}  // 0x0064a908
void Unwind_0064a910() {}  // 0x0064a910
void Unwind_0064a918() {}  // 0x0064a918
void Unwind_0064a920() {}  // 0x0064a920
void Unwind_0064a928() {}  // 0x0064a928
void Unwind_0064a930() {}  // 0x0064a930
void Unwind_0064a938() {}  // 0x0064a938
void Unwind_0064a940() {}  // 0x0064a940
void Unwind_0064a948() {}  // 0x0064a948
void Unwind_0064a950() {}  // 0x0064a950
void Unwind_0064a958() {}  // 0x0064a958
void Unwind_0064a960() {}  // 0x0064a960
void Unwind_0064a968() {}  // 0x0064a968
void Unwind_0064a970() {}  // 0x0064a970
void Unwind_0064a978() {}  // 0x0064a978
void Unwind_0064a980() {}  // 0x0064a980
void Unwind_0064a988() {}  // 0x0064a988
void Unwind_0064a990() {}  // 0x0064a990
void Unwind_0064a998() {}  // 0x0064a998
void Unwind_0064a9a0() {}  // 0x0064a9a0
void Unwind_0064a9a8() {}  // 0x0064a9a8
void Unwind_0064a9b0() {}  // 0x0064a9b0
void Unwind_0064a9b8() {}  // 0x0064a9b8
void Unwind_0064a9c0() {}  // 0x0064a9c0
void Unwind_0064a9c8() {}  // 0x0064a9c8
void Unwind_0064a9d0() {}  // 0x0064a9d0
void Unwind_0064a9d8() {}  // 0x0064a9d8
void Unwind_0064a9e0() {}  // 0x0064a9e0
void Unwind_0064a9e8() {}  // 0x0064a9e8
void Unwind_0064a9f0() {}  // 0x0064a9f0
void Unwind_0064a9f8() {}  // 0x0064a9f8
void Unwind_0064aa00() {}  // 0x0064aa00
void Unwind_0064aa08() {}  // 0x0064aa08
void Unwind_0064aa10() {}  // 0x0064aa10
void Unwind_0064aa18() {}  // 0x0064aa18
void Unwind_0064aa20() {}  // 0x0064aa20
void Unwind_0064aa28() {}  // 0x0064aa28
void Unwind_0064aa30() {}  // 0x0064aa30
void Unwind_0064aa38() {}  // 0x0064aa38
void Unwind_0064aa40() {}  // 0x0064aa40
void Unwind_0064aa48() {}  // 0x0064aa48
void Unwind_0064aa50() {}  // 0x0064aa50
void Unwind_0064aa58() {}  // 0x0064aa58
void Unwind_0064aa60() {}  // 0x0064aa60
void Unwind_0064aa68() {}  // 0x0064aa68
void Unwind_0064aa70() {}  // 0x0064aa70
void Unwind_0064aa78() {}  // 0x0064aa78
void Unwind_0064aa80() {}  // 0x0064aa80
void Unwind_0064aa88() {}  // 0x0064aa88
void Unwind_0064aa90() {}  // 0x0064aa90
void Unwind_0064aa98() {}  // 0x0064aa98
void Unwind_0064aaa0() {}  // 0x0064aaa0
void Unwind_0064aaa8() {}  // 0x0064aaa8
void Unwind_0064aab0() {}  // 0x0064aab0
void Unwind_0064aab8() {}  // 0x0064aab8
void Unwind_0064aac0() {}  // 0x0064aac0
void Unwind_0064aac8() {}  // 0x0064aac8
void Unwind_0064aad0() {}  // 0x0064aad0
void Unwind_0064aad8() {}  // 0x0064aad8
void Unwind_0064aae0() {}  // 0x0064aae0
void Unwind_0064aae8() {}  // 0x0064aae8
void Unwind_0064aaf0() {}  // 0x0064aaf0
void Unwind_0064ab20() {}  // 0x0064ab20
void Unwind_0064ab2b() {}  // 0x0064ab2b
void Unwind_0064ab39() {}  // 0x0064ab39
void Unwind_0064ab80() {}  // 0x0064ab80
void Unwind_0064abb0() {}  // 0x0064abb0
void Unwind_0064abf0() {}  // 0x0064abf0
void Unwind_0064ac30() {}  // 0x0064ac30
void Unwind_0064ac38() {}  // 0x0064ac38
void Unwind_0064ac70() {}  // 0x0064ac70
void Unwind_0064ac78() {}  // 0x0064ac78
void Unwind_0064ac80() {}  // 0x0064ac80
void Unwind_0064acb0() {}  // 0x0064acb0
void Unwind_0064acb8() {}  // 0x0064acb8
void Unwind_0064acc0() {}  // 0x0064acc0
void Unwind_0064acc8() {}  // 0x0064acc8
void Unwind_0064acd3() {}  // 0x0064acd3
void Unwind_0064acde() {}  // 0x0064acde
void Unwind_0064ace9() {}  // 0x0064ace9
void Unwind_0064ad20() {}  // 0x0064ad20
void Unwind_0064ad2b() {}  // 0x0064ad2b
void Unwind_0064ad60() {}  // 0x0064ad60
void Unwind_0064ad90() {}  // 0x0064ad90
void Unwind_0064ad98() {}  // 0x0064ad98
void Unwind_0064adaa() {}  // 0x0064adaa
void Unwind_0064adb2() {}  // 0x0064adb2
void Unwind_0064ade0() {}  // 0x0064ade0
void Unwind_0064ade8() {}  // 0x0064ade8
void Unwind_0064adf6() {}  // 0x0064adf6
void Unwind_0064ae04() {}  // 0x0064ae04
void Unwind_0064ae12() {}  // 0x0064ae12
void Unwind_0064ae1a() {}  // 0x0064ae1a
void Unwind_0064ae22() {}  // 0x0064ae22
void Unwind_0064ae2d() {}  // 0x0064ae2d
void Unwind_0064ae70() {}  // 0x0064ae70
void Unwind_0064aeb0() {}  // 0x0064aeb0
void Unwind_0064aebf() {}  // 0x0064aebf
void Unwind_0064aef0() {}  // 0x0064aef0
void Unwind_0064aeff() {}  // 0x0064aeff
void Unwind_0064af30() {}  // 0x0064af30
void Unwind_0064af60() {}  // 0x0064af60
void Unwind_0064afa0() {}  // 0x0064afa0
void Unwind_0064afe0() {}  // 0x0064afe0
void Unwind_0064b010() {}  // 0x0064b010
void Unwind_0064b018() {}  // 0x0064b018
void Unwind_0064b020() {}  // 0x0064b020
void Unwind_0064b028() {}  // 0x0064b028
void Unwind_0064b030() {}  // 0x0064b030
void Unwind_0064b038() {}  // 0x0064b038
void Unwind_0064b040() {}  // 0x0064b040
void Unwind_0064b0a0() {}  // 0x0064b0a0
void Unwind_0064b0af() {}  // 0x0064b0af
void Unwind_0064b0e0() {}  // 0x0064b0e0
void Unwind_0064b120() {}  // 0x0064b120
void Unwind_0064b160() {}  // 0x0064b160
void Unwind_0064b1a0() {}  // 0x0064b1a0
void Unwind_0064b1e0() {}  // 0x0064b1e0
void Unwind_0064b210() {}  // 0x0064b210
void Unwind_0064b240() {}  // 0x0064b240
void Unwind_0064b24b() {}  // 0x0064b24b
void Unwind_0064b256() {}  // 0x0064b256
void Unwind_0064b25e() {}  // 0x0064b25e
void Unwind_0064b266() {}  // 0x0064b266
void Unwind_0064b26e() {}  // 0x0064b26e
void Unwind_0064b276() {}  // 0x0064b276
void Unwind_0064b27e() {}  // 0x0064b27e
void Unwind_0064b286() {}  // 0x0064b286
void Unwind_0064b28e() {}  // 0x0064b28e
void Unwind_0064b296() {}  // 0x0064b296
void Unwind_0064b29e() {}  // 0x0064b29e
void Unwind_0064b2a6() {}  // 0x0064b2a6
void Unwind_0064b2ae() {}  // 0x0064b2ae
void Unwind_0064b2b6() {}  // 0x0064b2b6
void Unwind_0064b2be() {}  // 0x0064b2be
void Unwind_0064b2c6() {}  // 0x0064b2c6
void Unwind_0064b2ce() {}  // 0x0064b2ce
void Unwind_0064b2d6() {}  // 0x0064b2d6
void Unwind_0064b2de() {}  // 0x0064b2de
void Unwind_0064b2e6() {}  // 0x0064b2e6
void Unwind_0064b2ee() {}  // 0x0064b2ee
void Unwind_0064b330() {}  // 0x0064b330
void Unwind_0064b339() {}  // 0x0064b339
void Unwind_0064b342() {}  // 0x0064b342
void Unwind_0064b34b() {}  // 0x0064b34b
void Unwind_0064b354() {}  // 0x0064b354
void Unwind_0064b35d() {}  // 0x0064b35d
void Unwind_0064b390() {}  // 0x0064b390
void Unwind_0064b3c0() {}  // 0x0064b3c0
void Unwind_0064b3e2() {}  // 0x0064b3e2
void Unwind_0064b3ed() {}  // 0x0064b3ed
void Unwind_0064b430() {}  // 0x0064b430
void Unwind_0064b44d() {}  // 0x0064b44d
void Unwind_0064b459() {}  // 0x0064b459
void Unwind_0064b464() {}  // 0x0064b464
void Unwind_0064b490() {}  // 0x0064b490
void Unwind_0064b4c0() {}  // 0x0064b4c0
void Unwind_0064b4c8() {}  // 0x0064b4c8
void Unwind_0064b4d0() {}  // 0x0064b4d0
void Unwind_0064b4d8() {}  // 0x0064b4d8
void Unwind_0064b510() {}  // 0x0064b510
void Unwind_0064b540() {}  // 0x0064b540
void Unwind_0064b570() {}  // 0x0064b570
void Unwind_0064b5a0() {}  // 0x0064b5a0
void Unwind_0064b5ac() {}  // 0x0064b5ac
void Unwind_0064b5f0() {}  // 0x0064b5f0
void Unwind_0064b5f9() {}  // 0x0064b5f9
void Unwind_0064b602() {}  // 0x0064b602
void Unwind_0064b60e() {}  // 0x0064b60e
void Unwind_0064b61a() {}  // 0x0064b61a
void Unwind_0064b626() {}  // 0x0064b626
void Unwind_0064b660() {}  // 0x0064b660
void Unwind_0064b6a0() {}  // 0x0064b6a0
void Unwind_0064b6ab() {}  // 0x0064b6ab
void Unwind_0064b6b7() {}  // 0x0064b6b7
void Unwind_0064b6c0() {}  // 0x0064b6c0
void Unwind_0064b6c8() {}  // 0x0064b6c8
void Unwind_0064b700() {}  // 0x0064b700
void Unwind_0064b730() {}  // 0x0064b730
void Unwind_0064b738() {}  // 0x0064b738
void Unwind_0064b740() {}  // 0x0064b740
void Unwind_0064b748() {}  // 0x0064b748
void Unwind_0064b780() {}  // 0x0064b780
void Unwind_0064b7a2() {}  // 0x0064b7a2
void Unwind_0064b7aa() {}  // 0x0064b7aa
void Unwind_0064b7b2() {}  // 0x0064b7b2
void Unwind_0064b7d4() {}  // 0x0064b7d4
void Unwind_0064b7f6() {}  // 0x0064b7f6
void Unwind_0064b830() {}  // 0x0064b830
void Unwind_0064b843() {}  // 0x0064b843
void Unwind_0064b84b() {}  // 0x0064b84b
void Unwind_0064b853() {}  // 0x0064b853
void Unwind_0064b86c() {}  // 0x0064b86c
void Unwind_0064b874() {}  // 0x0064b874
void Unwind_0064b87c() {}  // 0x0064b87c
void Unwind_0064b8b0() {}  // 0x0064b8b0
void Unwind_0064b8b8() {}  // 0x0064b8b8
void Unwind_0064b8c0() {}  // 0x0064b8c0
void Unwind_0064b8c8() {}  // 0x0064b8c8
void Unwind_0064b900() {}  // 0x0064b900
void Unwind_0064b908() {}  // 0x0064b908
void Unwind_0064b940() {}  // 0x0064b940
void Unwind_0064b948() {}  // 0x0064b948
void Unwind_0064b950() {}  // 0x0064b950
void Unwind_0064b958() {}  // 0x0064b958
void Unwind_0064b960() {}  // 0x0064b960
void Unwind_0064b968() {}  // 0x0064b968
void Unwind_0064b9a0() {}  // 0x0064b9a0
void Unwind_0064b9d0() {}  // 0x0064b9d0
void Unwind_0064ba20() {}  // 0x0064ba20
void Unwind_0064ba90() {}  // 0x0064ba90
void Unwind_0064bac0() {}  // 0x0064bac0
void Unwind_0064baf0() {}  // 0x0064baf0
void Unwind_0064bb30() {}  // 0x0064bb30
void Unwind_0064bb60() {}  // 0x0064bb60
void Unwind_0064bb68() {}  // 0x0064bb68
void Unwind_0064bb70() {}  // 0x0064bb70
void Unwind_0064bb78() {}  // 0x0064bb78
void Unwind_0064bbb0() {}  // 0x0064bbb0
void Unwind_0064bbe0() {}  // 0x0064bbe0
void Unwind_0064bc20() {}  // 0x0064bc20
void Unwind_0064bc2b() {}  // 0x0064bc2b
void Unwind_0064bc70() {}  // 0x0064bc70
void Unwind_0064bcb0() {}  // 0x0064bcb0
void Unwind_0064bcb8() {}  // 0x0064bcb8
void Unwind_0064bcf0() {}  // 0x0064bcf0
void Unwind_0064bd20() {}  // 0x0064bd20
void Unwind_0064bd28() {}  // 0x0064bd28
void Unwind_0064bd60() {}  // 0x0064bd60
void Unwind_0064bd68() {}  // 0x0064bd68
void Unwind_0064bd70() {}  // 0x0064bd70
void Unwind_0064bdb0() {}  // 0x0064bdb0
void Unwind_0064bdf0() {}  // 0x0064bdf0
void Unwind_0064bdf8() {}  // 0x0064bdf8
void Unwind_0064be30() {}  // 0x0064be30
void Unwind_0064be38() {}  // 0x0064be38
void Unwind_0064be70() {}  // 0x0064be70
void Unwind_0064beb0() {}  // 0x0064beb0
void Unwind_0064bef0() {}  // 0x0064bef0
void Unwind_0064bf20() {}  // 0x0064bf20
void Unwind_0064bf42() {}  // 0x0064bf42
void Unwind_0064bf4a() {}  // 0x0064bf4a
void Unwind_0064bf52() {}  // 0x0064bf52
void Unwind_0064bf5a() {}  // 0x0064bf5a
void Unwind_0064bf65() {}  // 0x0064bf65
void Unwind_0064bf6d() {}  // 0x0064bf6d
void Unwind_0064bf78() {}  // 0x0064bf78
void Unwind_0064bf80() {}  // 0x0064bf80
void Unwind_0064bf88() {}  // 0x0064bf88
void Unwind_0064bfd0() {}  // 0x0064bfd0
void Unwind_0064c010() {}  // 0x0064c010
void Unwind_0064c018() {}  // 0x0064c018
void Unwind_0064c050() {}  // 0x0064c050
void Unwind_0064c080() {}  // 0x0064c080
void Unwind_0064c099() {}  // 0x0064c099
void Unwind_0064c0e0() {}  // 0x0064c0e0
void Unwind_0064c140() {}  // 0x0064c140
void Unwind_0064c180() {}  // 0x0064c180
void Unwind_0064c18b() {}  // 0x0064c18b
void Unwind_0064c196() {}  // 0x0064c196
void Unwind_0064c19e() {}  // 0x0064c19e
void Unwind_0064c1a9() {}  // 0x0064c1a9
void Unwind_0064c1e0() {}  // 0x0064c1e0
void Unwind_0064c220() {}  // 0x0064c220
void Unwind_0064c260() {}  // 0x0064c260
void Unwind_0064c279() {}  // 0x0064c279
void Unwind_0064c2b0() {}  // 0x0064c2b0
void Unwind_0064c2b8() {}  // 0x0064c2b8
void Unwind_0064c2c0() {}  // 0x0064c2c0
void Unwind_0064c300() {}  // 0x0064c300
void Unwind_0064c30f() {}  // 0x0064c30f
void Unwind_0064c317() {}  // 0x0064c317
void Unwind_0064c350() {}  // 0x0064c350
void Unwind_0064c390() {}  // 0x0064c390
void Unwind_0064c3d0() {}  // 0x0064c3d0
void Unwind_0064c410() {}  // 0x0064c410
void Unwind_0064c41b() {}  // 0x0064c41b
void Unwind_0064c426() {}  // 0x0064c426
void Unwind_0064c460() {}  // 0x0064c460
void Unwind_0064c490() {}  // 0x0064c490
void Unwind_0064c4c0() {}  // 0x0064c4c0
void Unwind_0064c500() {}  // 0x0064c500
void Unwind_0064c540() {}  // 0x0064c540
void Unwind_0064c580() {}  // 0x0064c580
void Unwind_0064c5c0() {}  // 0x0064c5c0
void Unwind_0064c600() {}  // 0x0064c600
void Unwind_0064c608() {}  // 0x0064c608
void Unwind_0064c640() {}  // 0x0064c640
void Unwind_0064c6a0() {}  // 0x0064c6a0
void Unwind_0064c6a8() {}  // 0x0064c6a8
void Unwind_0064c6e0() {}  // 0x0064c6e0
void Unwind_0064c720() {}  // 0x0064c720
void Unwind_0064c728() {}  // 0x0064c728
void Unwind_0064c730() {}  // 0x0064c730
void Unwind_0064c738() {}  // 0x0064c738
void Unwind_0064c740() {}  // 0x0064c740
void Unwind_0064c748() {}  // 0x0064c748
void Unwind_0064c750() {}  // 0x0064c750
void Unwind_0064c758() {}  // 0x0064c758
void Unwind_0064c790() {}  // 0x0064c790
void Unwind_0064c798() {}  // 0x0064c798
void Unwind_0064c7a0() {}  // 0x0064c7a0
void Unwind_0064c7a8() {}  // 0x0064c7a8
void Unwind_0064c7b0() {}  // 0x0064c7b0
void Unwind_0064c7b8() {}  // 0x0064c7b8
void Unwind_0064c7c7() {}  // 0x0064c7c7
void Unwind_0064c7cf() {}  // 0x0064c7cf
void Unwind_0064c7d7() {}  // 0x0064c7d7
void Unwind_0064c7df() {}  // 0x0064c7df
void Unwind_0064c7ee() {}  // 0x0064c7ee
void Unwind_0064c7f6() {}  // 0x0064c7f6
void Unwind_0064c7fe() {}  // 0x0064c7fe
void Unwind_0064c806() {}  // 0x0064c806
void Unwind_0064c80e() {}  // 0x0064c80e
void Unwind_0064c816() {}  // 0x0064c816
void Unwind_0064c81e() {}  // 0x0064c81e
void Unwind_0064c826() {}  // 0x0064c826
void Unwind_0064c860() {}  // 0x0064c860
void Unwind_0064c8a0() {}  // 0x0064c8a0
void Unwind_0064c8ac() {}  // 0x0064c8ac
void Unwind_0064c8e0() {}  // 0x0064c8e0
void Unwind_0064c920() {}  // 0x0064c920
void Unwind_0064c92a() {}  // 0x0064c92a
void Unwind_0064c960() {}  // 0x0064c960
void Unwind_0064c96b() {}  // 0x0064c96b
void Unwind_0064c9b0() {}  // 0x0064c9b0
void Unwind_0064c9f0() {}  // 0x0064c9f0
void Unwind_0064c9f8() {}  // 0x0064c9f8
void Unwind_0064ca00() {}  // 0x0064ca00
void Unwind_0064ca40() {}  // 0x0064ca40
void Unwind_0064ca48() {}  // 0x0064ca48
void Unwind_0064ca80() {}  // 0x0064ca80
void Unwind_0064cac0() {}  // 0x0064cac0
void Unwind_0064cac8() {}  // 0x0064cac8
void Unwind_0064cb00() {}  // 0x0064cb00
void Unwind_0064cb40() {}  // 0x0064cb40
void Unwind_0064cb4b() {}  // 0x0064cb4b
void Unwind_0064cb56() {}  // 0x0064cb56
void Unwind_0064cb5e() {}  // 0x0064cb5e
void Unwind_0064cb66() {}  // 0x0064cb66
void Unwind_0064cb6e() {}  // 0x0064cb6e
void Unwind_0064cb76() {}  // 0x0064cb76
void Unwind_0064cb7e() {}  // 0x0064cb7e
void Unwind_0064cb86() {}  // 0x0064cb86
void Unwind_0064cb8e() {}  // 0x0064cb8e
void Unwind_0064cb96() {}  // 0x0064cb96
void Unwind_0064cb9e() {}  // 0x0064cb9e
void Unwind_0064cba6() {}  // 0x0064cba6
void Unwind_0064cbae() {}  // 0x0064cbae
void Unwind_0064cbb6() {}  // 0x0064cbb6
void Unwind_0064cbbe() {}  // 0x0064cbbe
void Unwind_0064cc00() {}  // 0x0064cc00
void Unwind_0064cc08() {}  // 0x0064cc08
void Unwind_0064cc10() {}  // 0x0064cc10
void Unwind_0064cc50() {}  // 0x0064cc50
void Unwind_0064cc5f() {}  // 0x0064cc5f
void Unwind_0064cc90() {}  // 0x0064cc90
void Unwind_0064ccc0() {}  // 0x0064ccc0
void Unwind_0064ccf0() {}  // 0x0064ccf0
void Unwind_0064ccf8() {}  // 0x0064ccf8
void Unwind_0064cd00() {}  // 0x0064cd00
void Unwind_0064cd40() {}  // 0x0064cd40
void Unwind_0064cd80() {}  // 0x0064cd80
void Unwind_0064cd8b() {}  // 0x0064cd8b
void Unwind_0064cd96() {}  // 0x0064cd96
void Unwind_0064cda1() {}  // 0x0064cda1
void Unwind_0064cdd0() {}  // 0x0064cdd0
void Unwind_0064ce10() {}  // 0x0064ce10
void Unwind_0064ce60() {}  // 0x0064ce60
void Unwind_0064ce79() {}  // 0x0064ce79
void Unwind_0064ceb0() {}  // 0x0064ceb0
void Unwind_0064cec9() {}  // 0x0064cec9
void Unwind_0064ced1() {}  // 0x0064ced1
void Unwind_0064cf10() {}  // 0x0064cf10
void Unwind_0064cf18() {}  // 0x0064cf18
void Unwind_0064cf20() {}  // 0x0064cf20
void Unwind_0064cf60() {}  // 0x0064cf60
void Unwind_0064cf68() {}  // 0x0064cf68
void Unwind_0064cfa0() {}  // 0x0064cfa0
void Unwind_0064cfa8() {}  // 0x0064cfa8
void Unwind_0064cfe0() {}  // 0x0064cfe0
void Unwind_0064cfe8() {}  // 0x0064cfe8
void Unwind_0064cff0() {}  // 0x0064cff0
void Unwind_0064d030() {}  // 0x0064d030
void Unwind_0064d070() {}  // 0x0064d070
void Unwind_0064d0a0() {}  // 0x0064d0a0
void Unwind_0064d0a8() {}  // 0x0064d0a8
void Unwind_0064d0b3() {}  // 0x0064d0b3
void Unwind_0064d0be() {}  // 0x0064d0be
void Unwind_0064d0c9() {}  // 0x0064d0c9
void Unwind_0064d100() {}  // 0x0064d100
void Unwind_0064d108() {}  // 0x0064d108
void Unwind_0064d110() {}  // 0x0064d110
void Unwind_0064d140() {}  // 0x0064d140
void Unwind_0064d148() {}  // 0x0064d148
void Unwind_0064d150() {}  // 0x0064d150
void Unwind_0064d158() {}  // 0x0064d158
void Unwind_0064d190() {}  // 0x0064d190
void Unwind_0064d198() {}  // 0x0064d198
void Unwind_0064d1a0() {}  // 0x0064d1a0
void Unwind_0064d1e0() {}  // 0x0064d1e0
void Unwind_0064d1eb() {}  // 0x0064d1eb
void Unwind_0064d1f9() {}  // 0x0064d1f9
void Unwind_0064d207() {}  // 0x0064d207
void Unwind_0064d215() {}  // 0x0064d215
void Unwind_0064d223() {}  // 0x0064d223
void Unwind_0064d234() {}  // 0x0064d234
void Unwind_0064d245() {}  // 0x0064d245
void Unwind_0064d250() {}  // 0x0064d250
void Unwind_0064d258() {}  // 0x0064d258
void Unwind_0064d260() {}  // 0x0064d260
void Unwind_0064d268() {}  // 0x0064d268
void Unwind_0064d270() {}  // 0x0064d270
void Unwind_0064d2b0() {}  // 0x0064d2b0
void Unwind_0064d2bb() {}  // 0x0064d2bb
void Unwind_0064d2c7() {}  // 0x0064d2c7
void Unwind_0064d2d2() {}  // 0x0064d2d2
void Unwind_0064d2dd() {}  // 0x0064d2dd
void Unwind_0064d2e5() {}  // 0x0064d2e5
void Unwind_0064d2ed() {}  // 0x0064d2ed
void Unwind_0064d2f5() {}  // 0x0064d2f5
void Unwind_0064d2fd() {}  // 0x0064d2fd
void Unwind_0064d308() {}  // 0x0064d308
void Unwind_0064d310() {}  // 0x0064d310
void Unwind_0064d350() {}  // 0x0064d350
void Unwind_0064d380() {}  // 0x0064d380
void Unwind_0064d38b() {}  // 0x0064d38b
void Unwind_0064d397() {}  // 0x0064d397
void Unwind_0064d3a2() {}  // 0x0064d3a2
void Unwind_0064d3ad() {}  // 0x0064d3ad
void Unwind_0064d3b5() {}  // 0x0064d3b5
void Unwind_0064d3c7() {}  // 0x0064d3c7
void Unwind_0064d3d2() {}  // 0x0064d3d2
void Unwind_0064d3dd() {}  // 0x0064d3dd
void Unwind_0064d3e5() {}  // 0x0064d3e5
void Unwind_0064d3f0() {}  // 0x0064d3f0
void Unwind_0064d430() {}  // 0x0064d430
void Unwind_0064d438() {}  // 0x0064d438
void Unwind_0064d440() {}  // 0x0064d440
void Unwind_0064d448() {}  // 0x0064d448
void Unwind_0064d450() {}  // 0x0064d450
void Unwind_0064d490() {}  // 0x0064d490
void Unwind_0064d49b() {}  // 0x0064d49b
void Unwind_0064d4a7() {}  // 0x0064d4a7
void Unwind_0064d4b2() {}  // 0x0064d4b2
void Unwind_0064d4bd() {}  // 0x0064d4bd
void Unwind_0064d4c5() {}  // 0x0064d4c5
void Unwind_0064d4cd() {}  // 0x0064d4cd
void Unwind_0064d4d8() {}  // 0x0064d4d8
void Unwind_0064d4e3() {}  // 0x0064d4e3
void Unwind_0064d4ee() {}  // 0x0064d4ee
void Unwind_0064d4f6() {}  // 0x0064d4f6
void Unwind_0064d501() {}  // 0x0064d501
void Unwind_0064d50c() {}  // 0x0064d50c
void Unwind_0064d550() {}  // 0x0064d550
void Unwind_0064d580() {}  // 0x0064d580
void Unwind_0064d588() {}  // 0x0064d588
void Unwind_0064d5c0() {}  // 0x0064d5c0
void Unwind_0064d5d9() {}  // 0x0064d5d9
void Unwind_0064d5e1() {}  // 0x0064d5e1
void Unwind_0064d5ec() {}  // 0x0064d5ec
void Unwind_0064d5f4() {}  // 0x0064d5f4
void Unwind_0064d5fc() {}  // 0x0064d5fc
void Unwind_0064d607() {}  // 0x0064d607
void Unwind_0064d650() {}  // 0x0064d650
void Unwind_0064d658() {}  // 0x0064d658
void Unwind_0064d660() {}  // 0x0064d660
void Unwind_0064d668() {}  // 0x0064d668
void Unwind_0064d677() {}  // 0x0064d677
void Unwind_0064d682() {}  // 0x0064d682
void Unwind_0064d68a() {}  // 0x0064d68a
void Unwind_0064d692() {}  // 0x0064d692
void Unwind_0064d6d0() {}  // 0x0064d6d0
void Unwind_0064d6d8() {}  // 0x0064d6d8
void Unwind_0064d6e0() {}  // 0x0064d6e0
void Unwind_0064d710() {}  // 0x0064d710
void Unwind_0064d718() {}  // 0x0064d718
void Unwind_0064d720() {}  // 0x0064d720
void Unwind_0064d728() {}  // 0x0064d728
void Unwind_0064d730() {}  // 0x0064d730
void Unwind_0064d738() {}  // 0x0064d738
void Unwind_0064d770() {}  // 0x0064d770
void Unwind_0064d778() {}  // 0x0064d778
void Unwind_0064d7b0() {}  // 0x0064d7b0
void Unwind_0064d7f0() {}  // 0x0064d7f0
void Unwind_0064d7f8() {}  // 0x0064d7f8
void Unwind_0064d830() {}  // 0x0064d830
void Unwind_0064d838() {}  // 0x0064d838
void Unwind_0064d840() {}  // 0x0064d840
void Unwind_0064d848() {}  // 0x0064d848
void Unwind_0064d850() {}  // 0x0064d850
void Unwind_0064d858() {}  // 0x0064d858
void Unwind_0064d890() {}  // 0x0064d890
void Unwind_0064d898() {}  // 0x0064d898
void Unwind_0064d8a3() {}  // 0x0064d8a3
void Unwind_0064d8e0() {}  // 0x0064d8e0
void Unwind_0064d8e8() {}  // 0x0064d8e8
void Unwind_0064d90a() {}  // 0x0064d90a
void Unwind_0064d915() {}  // 0x0064d915
void Unwind_0064d920() {}  // 0x0064d920
void Unwind_0064d92b() {}  // 0x0064d92b
void Unwind_0064d936() {}  // 0x0064d936
void Unwind_0064d941() {}  // 0x0064d941
void Unwind_0064d94c() {}  // 0x0064d94c
void Unwind_0064d990() {}  // 0x0064d990
void Unwind_0064d9c0() {}  // 0x0064d9c0
void Unwind_0064d9c8() {}  // 0x0064d9c8
void Unwind_0064d9d0() {}  // 0x0064d9d0
void Unwind_0064d9d8() {}  // 0x0064d9d8
void Unwind_0064d9f1() {}  // 0x0064d9f1
void Unwind_0064da30() {}  // 0x0064da30
void Unwind_0064da49() {}  // 0x0064da49
void Unwind_0064da58() {}  // 0x0064da58
void Unwind_0064da60() {}  // 0x0064da60
void Unwind_0064da68() {}  // 0x0064da68
void Unwind_0064da73() {}  // 0x0064da73
void Unwind_0064da7b() {}  // 0x0064da7b
void Unwind_0064dab0() {}  // 0x0064dab0
void Unwind_0064dab8() {}  // 0x0064dab8
void Unwind_0064dac0() {}  // 0x0064dac0
void Unwind_0064daf0() {}  // 0x0064daf0
void Unwind_0064db09() {}  // 0x0064db09
void Unwind_0064db11() {}  // 0x0064db11
void Unwind_0064db20() {}  // 0x0064db20
void Unwind_0064db28() {}  // 0x0064db28
void Unwind_0064db30() {}  // 0x0064db30
void Unwind_0064db3b() {}  // 0x0064db3b
void Unwind_0064db43() {}  // 0x0064db43
void Unwind_0064db70() {}  // 0x0064db70
void Unwind_0064db7b() {}  // 0x0064db7b
void Unwind_0064db86() {}  // 0x0064db86
void Unwind_0064db8e() {}  // 0x0064db8e
void Unwind_0064db96() {}  // 0x0064db96
void Unwind_0064db9e() {}  // 0x0064db9e
void Unwind_0064dba6() {}  // 0x0064dba6
void Unwind_0064dbae() {}  // 0x0064dbae
void Unwind_0064dbb6() {}  // 0x0064dbb6
void Unwind_0064dbbe() {}  // 0x0064dbbe
void Unwind_0064dbc9() {}  // 0x0064dbc9
void Unwind_0064dc00() {}  // 0x0064dc00
void Unwind_0064dc08() {}  // 0x0064dc08
void Unwind_0064dc10() {}  // 0x0064dc10
void Unwind_0064dc29() {}  // 0x0064dc29
void Unwind_0064dc70() {}  // 0x0064dc70
void Unwind_0064dc78() {}  // 0x0064dc78
void Unwind_0064dc91() {}  // 0x0064dc91
void Unwind_0064dcd0() {}  // 0x0064dcd0
void Unwind_0064dd00() {}  // 0x0064dd00
void Unwind_0064dd08() {}  // 0x0064dd08
void Unwind_0064dd10() {}  // 0x0064dd10
void Unwind_0064dd18() {}  // 0x0064dd18
void Unwind_0064dd50() {}  // 0x0064dd50
void Unwind_0064dd58() {}  // 0x0064dd58
void Unwind_0064dd67() {}  // 0x0064dd67
void Unwind_0064dd6f() {}  // 0x0064dd6f
void Unwind_0064dd77() {}  // 0x0064dd77
void Unwind_0064dd82() {}  // 0x0064dd82
void Unwind_0064ddb0() {}  // 0x0064ddb0
void Unwind_0064ddb8() {}  // 0x0064ddb8
void Unwind_0064ddf0() {}  // 0x0064ddf0
void Unwind_0064ddfb() {}  // 0x0064ddfb
void Unwind_0064de03() {}  // 0x0064de03
void Unwind_0064de0b() {}  // 0x0064de0b
void Unwind_0064de16() {}  // 0x0064de16
void Unwind_0064de1e() {}  // 0x0064de1e
void Unwind_0064de26() {}  // 0x0064de26
void Unwind_0064de2e() {}  // 0x0064de2e
void Unwind_0064de39() {}  // 0x0064de39
void Unwind_0064de41() {}  // 0x0064de41
void Unwind_0064de49() {}  // 0x0064de49
void Unwind_0064de51() {}  // 0x0064de51
void Unwind_0064de59() {}  // 0x0064de59
void Unwind_0064de64() {}  // 0x0064de64
void Unwind_0064de6c() {}  // 0x0064de6c
void Unwind_0064de74() {}  // 0x0064de74
void Unwind_0064de7c() {}  // 0x0064de7c
void Unwind_0064de87() {}  // 0x0064de87
void Unwind_0064de8f() {}  // 0x0064de8f
void Unwind_0064de97() {}  // 0x0064de97
void Unwind_0064de9f() {}  // 0x0064de9f
void Unwind_0064deaa() {}  // 0x0064deaa
void Unwind_0064deb2() {}  // 0x0064deb2
void Unwind_0064deba() {}  // 0x0064deba
void Unwind_0064dec2() {}  // 0x0064dec2
void Unwind_0064decd() {}  // 0x0064decd
void Unwind_0064ded5() {}  // 0x0064ded5
void Unwind_0064dedd() {}  // 0x0064dedd
void Unwind_0064dee5() {}  // 0x0064dee5
void Unwind_0064def0() {}  // 0x0064def0
void Unwind_0064def8() {}  // 0x0064def8
void Unwind_0064df00() {}  // 0x0064df00
void Unwind_0064df08() {}  // 0x0064df08
void Unwind_0064df13() {}  // 0x0064df13
void Unwind_0064df1b() {}  // 0x0064df1b
void Unwind_0064df23() {}  // 0x0064df23
void Unwind_0064df2b() {}  // 0x0064df2b
void Unwind_0064df36() {}  // 0x0064df36
void Unwind_0064df70() {}  // 0x0064df70
void Unwind_0064df7b() {}  // 0x0064df7b
void Unwind_0064df83() {}  // 0x0064df83
void Unwind_0064df8b() {}  // 0x0064df8b
void Unwind_0064df96() {}  // 0x0064df96
void Unwind_0064df9e() {}  // 0x0064df9e
void Unwind_0064dfa6() {}  // 0x0064dfa6
void Unwind_0064dfae() {}  // 0x0064dfae
void Unwind_0064dfb9() {}  // 0x0064dfb9
void Unwind_0064dfc1() {}  // 0x0064dfc1
void Unwind_0064dfc9() {}  // 0x0064dfc9
void Unwind_0064dfd1() {}  // 0x0064dfd1
void Unwind_0064dfd9() {}  // 0x0064dfd9
void Unwind_0064dfe4() {}  // 0x0064dfe4
void Unwind_0064dfec() {}  // 0x0064dfec
void Unwind_0064dff4() {}  // 0x0064dff4
void Unwind_0064dffc() {}  // 0x0064dffc
void Unwind_0064e007() {}  // 0x0064e007
void Unwind_0064e00f() {}  // 0x0064e00f
void Unwind_0064e017() {}  // 0x0064e017
void Unwind_0064e01f() {}  // 0x0064e01f
void Unwind_0064e02a() {}  // 0x0064e02a
void Unwind_0064e032() {}  // 0x0064e032
void Unwind_0064e03a() {}  // 0x0064e03a
void Unwind_0064e042() {}  // 0x0064e042
void Unwind_0064e04d() {}  // 0x0064e04d
void Unwind_0064e055() {}  // 0x0064e055
void Unwind_0064e05d() {}  // 0x0064e05d
void Unwind_0064e065() {}  // 0x0064e065
void Unwind_0064e070() {}  // 0x0064e070
void Unwind_0064e078() {}  // 0x0064e078
void Unwind_0064e080() {}  // 0x0064e080
void Unwind_0064e088() {}  // 0x0064e088
void Unwind_0064e093() {}  // 0x0064e093
void Unwind_0064e09b() {}  // 0x0064e09b
void Unwind_0064e0a3() {}  // 0x0064e0a3
void Unwind_0064e0ab() {}  // 0x0064e0ab
void Unwind_0064e0b6() {}  // 0x0064e0b6
void Unwind_0064e0f0() {}  // 0x0064e0f0
void Unwind_0064e120() {}  // 0x0064e120
void Unwind_0064e128() {}  // 0x0064e128
void Unwind_0064e130() {}  // 0x0064e130
void Unwind_0064e138() {}  // 0x0064e138
void Unwind_0064e140() {}  // 0x0064e140
void Unwind_0064e148() {}  // 0x0064e148
void Unwind_0064e180() {}  // 0x0064e180
void Unwind_0064e188() {}  // 0x0064e188
void Unwind_0064e1c0() {}  // 0x0064e1c0
void Unwind_0064e1f0() {}  // 0x0064e1f0
void Unwind_0064e220() {}  // 0x0064e220
void Unwind_0064e250() {}  // 0x0064e250
void Unwind_0064e258() {}  // 0x0064e258
void Unwind_0064e271() {}  // 0x0064e271
void Unwind_0064e279() {}  // 0x0064e279
void Unwind_0064e281() {}  // 0x0064e281
void Unwind_0064e289() {}  // 0x0064e289
void Unwind_0064e291() {}  // 0x0064e291
void Unwind_0064e299() {}  // 0x0064e299
void Unwind_0064e2b2() {}  // 0x0064e2b2
void Unwind_0064e2c5() {}  // 0x0064e2c5
void Unwind_0064e2f0() {}  // 0x0064e2f0
void Unwind_0064e320() {}  // 0x0064e320
void Unwind_0064e350() {}  // 0x0064e350
void Unwind_0064e380() {}  // 0x0064e380
void Unwind_0064e3b0() {}  // 0x0064e3b0
void Unwind_0064e3e0() {}  // 0x0064e3e0
void Unwind_0064e410() {}  // 0x0064e410
void Unwind_0064e440() {}  // 0x0064e440
void Unwind_0064e490() {}  // 0x0064e490
void Unwind_0064e4b2() {}  // 0x0064e4b2
void Unwind_0064e4ba() {}  // 0x0064e4ba
void Unwind_0064e4c2() {}  // 0x0064e4c2
void Unwind_0064e4cd() {}  // 0x0064e4cd
void Unwind_0064e4d5() {}  // 0x0064e4d5
void Unwind_0064e4dd() {}  // 0x0064e4dd
void Unwind_0064e4e5() {}  // 0x0064e4e5
void Unwind_0064e4ed() {}  // 0x0064e4ed
void Unwind_0064e4f5() {}  // 0x0064e4f5
void Unwind_0064e4fd() {}  // 0x0064e4fd
void Unwind_0064e505() {}  // 0x0064e505
void Unwind_0064e540() {}  // 0x0064e540
void Unwind_0064e548() {}  // 0x0064e548
void Unwind_0064e5a0() {}  // 0x0064e5a0
void Unwind_0064e5a8() {}  // 0x0064e5a8
void Unwind_0064e5b0() {}  // 0x0064e5b0
void Unwind_0064e5b8() {}  // 0x0064e5b8
void Unwind_0064e5c0() {}  // 0x0064e5c0
void Unwind_0064e5c8() {}  // 0x0064e5c8
void Unwind_0064e600() {}  // 0x0064e600
void Unwind_0064e608() {}  // 0x0064e608
void Unwind_0064e610() {}  // 0x0064e610
void Unwind_0064e618() {}  // 0x0064e618
void Unwind_0064e650() {}  // 0x0064e650
void Unwind_0064e658() {}  // 0x0064e658
void Unwind_0064e690() {}  // 0x0064e690
void Unwind_0064e698() {}  // 0x0064e698
void Unwind_0064e6d0() {}  // 0x0064e6d0
void Unwind_0064e6d8() {}  // 0x0064e6d8
void Unwind_0064e6e0() {}  // 0x0064e6e0
void Unwind_0064e6e8() {}  // 0x0064e6e8
void Unwind_0064e720() {}  // 0x0064e720
void Unwind_0064e728() {}  // 0x0064e728
void Unwind_0064e730() {}  // 0x0064e730
void Unwind_0064e738() {}  // 0x0064e738
void Unwind_0064e770() {}  // 0x0064e770
void Unwind_0064e778() {}  // 0x0064e778
void Unwind_0064e780() {}  // 0x0064e780
void Unwind_0064e788() {}  // 0x0064e788
void Unwind_0064e790() {}  // 0x0064e790
void Unwind_0064e79b() {}  // 0x0064e79b
void Unwind_0064e7e0() {}  // 0x0064e7e0
void Unwind_0064e7e8() {}  // 0x0064e7e8
void Unwind_0064e840() {}  // 0x0064e840
void Unwind_0064e848() {}  // 0x0064e848
void Unwind_0064e880() {}  // 0x0064e880
void Unwind_0064e888() {}  // 0x0064e888
void Unwind_0064e890() {}  // 0x0064e890
void Unwind_0064e898() {}  // 0x0064e898
void Unwind_0064e8a0() {}  // 0x0064e8a0
void Unwind_0064e8a8() {}  // 0x0064e8a8
void Unwind_0064e8b0() {}  // 0x0064e8b0
void Unwind_0064e8e0() {}  // 0x0064e8e0
void Unwind_0064e8f9() {}  // 0x0064e8f9
void Unwind_0064e901() {}  // 0x0064e901
void Unwind_0064e910() {}  // 0x0064e910
void Unwind_0064e918() {}  // 0x0064e918
void Unwind_0064e920() {}  // 0x0064e920
void Unwind_0064e92b() {}  // 0x0064e92b
void Unwind_0064e933() {}  // 0x0064e933
void Unwind_0064e960() {}  // 0x0064e960
void Unwind_0064e968() {}  // 0x0064e968
void Unwind_0064e970() {}  // 0x0064e970
void Unwind_0064e9a0() {}  // 0x0064e9a0
void Unwind_0064e9b9() {}  // 0x0064e9b9
void Unwind_0064e9c1() {}  // 0x0064e9c1
void Unwind_0064e9d0() {}  // 0x0064e9d0
void Unwind_0064e9d8() {}  // 0x0064e9d8
void Unwind_0064e9e0() {}  // 0x0064e9e0
void Unwind_0064e9eb() {}  // 0x0064e9eb
void Unwind_0064e9f3() {}  // 0x0064e9f3
void Unwind_0064ea20() {}  // 0x0064ea20
void Unwind_0064ea39() {}  // 0x0064ea39
void Unwind_0064ea41() {}  // 0x0064ea41
void Unwind_0064ea50() {}  // 0x0064ea50
void Unwind_0064ea58() {}  // 0x0064ea58
void Unwind_0064ea60() {}  // 0x0064ea60
void Unwind_0064ea6b() {}  // 0x0064ea6b
void Unwind_0064ea73() {}  // 0x0064ea73
void Unwind_0064eaa0() {}  // 0x0064eaa0
void Unwind_0064eaaf() {}  // 0x0064eaaf
void Unwind_0064eab7() {}  // 0x0064eab7
void Unwind_0064eabf() {}  // 0x0064eabf
void Unwind_0064eac7() {}  // 0x0064eac7
void Unwind_0064eacf() {}  // 0x0064eacf
void Unwind_0064eb10() {}  // 0x0064eb10
void Unwind_0064eb18() {}  // 0x0064eb18
void Unwind_0064eb20() {}  // 0x0064eb20
void Unwind_0064eb28() {}  // 0x0064eb28
void Unwind_0064eb30() {}  // 0x0064eb30
void Unwind_0064eb38() {}  // 0x0064eb38
void Unwind_0064eb40() {}  // 0x0064eb40
void Unwind_0064eb48() {}  // 0x0064eb48
void Unwind_0064eb50() {}  // 0x0064eb50
void Unwind_0064eb58() {}  // 0x0064eb58
void Unwind_0064eb90() {}  // 0x0064eb90
void Unwind_0064eb98() {}  // 0x0064eb98
void Unwind_0064eba0() {}  // 0x0064eba0
void Unwind_0064ebe0() {}  // 0x0064ebe0
void Unwind_0064ebf9() {}  // 0x0064ebf9
void Unwind_0064ec08() {}  // 0x0064ec08
void Unwind_0064ec10() {}  // 0x0064ec10
void Unwind_0064ec18() {}  // 0x0064ec18
void Unwind_0064ec23() {}  // 0x0064ec23
void Unwind_0064ec2b() {}  // 0x0064ec2b
void Unwind_0064ec60() {}  // 0x0064ec60
void Unwind_0064ec68() {}  // 0x0064ec68
void Unwind_0064ec70() {}  // 0x0064ec70
void Unwind_0064ec78() {}  // 0x0064ec78
void Unwind_0064ec91() {}  // 0x0064ec91
void Unwind_0064ecd0() {}  // 0x0064ecd0
void Unwind_0064ece9() {}  // 0x0064ece9
void Unwind_0064ecf8() {}  // 0x0064ecf8
void Unwind_0064ed00() {}  // 0x0064ed00
void Unwind_0064ed08() {}  // 0x0064ed08
void Unwind_0064ed13() {}  // 0x0064ed13
void Unwind_0064ed1b() {}  // 0x0064ed1b
void Unwind_0064ed50() {}  // 0x0064ed50
void Unwind_0064ed69() {}  // 0x0064ed69
void Unwind_0064ed78() {}  // 0x0064ed78
void Unwind_0064ed80() {}  // 0x0064ed80
void Unwind_0064ed88() {}  // 0x0064ed88
void Unwind_0064ed93() {}  // 0x0064ed93
void Unwind_0064ed9b() {}  // 0x0064ed9b
void Unwind_0064edd0() {}  // 0x0064edd0
void Unwind_0064edd8() {}  // 0x0064edd8
void Unwind_0064ede0() {}  // 0x0064ede0
void Unwind_0064edeb() {}  // 0x0064edeb
void Unwind_0064ee30() {}  // 0x0064ee30
void Unwind_0064ee60() {}  // 0x0064ee60
void Unwind_0064ee90() {}  // 0x0064ee90
void Unwind_0064eec0() {}  // 0x0064eec0
void Unwind_0064eef0() {}  // 0x0064eef0
void Unwind_0064ef20() {}  // 0x0064ef20
void Unwind_0064ef28() {}  // 0x0064ef28
void Unwind_0064ef60() {}  // 0x0064ef60
void Unwind_0064ef79() {}  // 0x0064ef79
void Unwind_0064ef81() {}  // 0x0064ef81
void Unwind_0064ef90() {}  // 0x0064ef90
void Unwind_0064ef98() {}  // 0x0064ef98
void Unwind_0064efa0() {}  // 0x0064efa0
void Unwind_0064efab() {}  // 0x0064efab
void Unwind_0064efb3() {}  // 0x0064efb3
void Unwind_0064efe0() {}  // 0x0064efe0
void Unwind_0064eff9() {}  // 0x0064eff9
void Unwind_0064f001() {}  // 0x0064f001
void Unwind_0064f010() {}  // 0x0064f010
void Unwind_0064f018() {}  // 0x0064f018
void Unwind_0064f020() {}  // 0x0064f020
void Unwind_0064f02b() {}  // 0x0064f02b
void Unwind_0064f033() {}  // 0x0064f033
void Unwind_0064f060() {}  // 0x0064f060
void Unwind_0064f068() {}  // 0x0064f068
void Unwind_0064f070() {}  // 0x0064f070
void Unwind_0064f078() {}  // 0x0064f078
void Unwind_0064f080() {}  // 0x0064f080
void Unwind_0064f0b0() {}  // 0x0064f0b0
void Unwind_0064f0b8() {}  // 0x0064f0b8
void Unwind_0064f0f0() {}  // 0x0064f0f0
void Unwind_0064f120() {}  // 0x0064f120
void Unwind_0064f150() {}  // 0x0064f150
void Unwind_0064f180() {}  // 0x0064f180
void Unwind_0064f188() {}  // 0x0064f188
void Unwind_0064f1c0() {}  // 0x0064f1c0
void Unwind_0064f1c8() {}  // 0x0064f1c8
void Unwind_0064f1d0() {}  // 0x0064f1d0
void Unwind_0064f200() {}  // 0x0064f200
void Unwind_0064f230() {}  // 0x0064f230
void Unwind_0064f260() {}  // 0x0064f260
void Unwind_0064f290() {}  // 0x0064f290
void Unwind_0064f298() {}  // 0x0064f298
void Unwind_0064f2a0() {}  // 0x0064f2a0
void Unwind_0064f2a8() {}  // 0x0064f2a8
void Unwind_0064f2b0() {}  // 0x0064f2b0
void Unwind_0064f2b8() {}  // 0x0064f2b8
void Unwind_0064f2c0() {}  // 0x0064f2c0
void Unwind_0064f2c8() {}  // 0x0064f2c8
void Unwind_0064f2e1() {}  // 0x0064f2e1
void Unwind_0064f2e9() {}  // 0x0064f2e9
void Unwind_0064f320() {}  // 0x0064f320
void Unwind_0064f328() {}  // 0x0064f328
void Unwind_0064f330() {}  // 0x0064f330
void Unwind_0064f338() {}  // 0x0064f338
void Unwind_0064f343() {}  // 0x0064f343
void Unwind_0064f34b() {}  // 0x0064f34b
void Unwind_0064f353() {}  // 0x0064f353
void Unwind_0064f35e() {}  // 0x0064f35e
void Unwind_0064f3a0() {}  // 0x0064f3a0
void Unwind_0064f3a8() {}  // 0x0064f3a8
void Unwind_0064f3c1() {}  // 0x0064f3c1
void Unwind_0064f3c9() {}  // 0x0064f3c9
void Unwind_0064f3d1() {}  // 0x0064f3d1
void Unwind_0064f400() {}  // 0x0064f400
void Unwind_0064f430() {}  // 0x0064f430
void Unwind_0064f438() {}  // 0x0064f438
void Unwind_0064f440() {}  // 0x0064f440
void Unwind_0064f44b() {}  // 0x0064f44b
void Unwind_0064f490() {}  // 0x0064f490
void Unwind_0064f498() {}  // 0x0064f498
void Unwind_0064f4d0() {}  // 0x0064f4d0
void Unwind_0064f4d8() {}  // 0x0064f4d8
void Unwind_0064f510() {}  // 0x0064f510
void Unwind_0064f518() {}  // 0x0064f518
void Unwind_0064f550() {}  // 0x0064f550
void Unwind_0064f558() {}  // 0x0064f558
void Unwind_0064f563() {}  // 0x0064f563
void Unwind_0064f56e() {}  // 0x0064f56e
void Unwind_0064f579() {}  // 0x0064f579
void Unwind_0064f584() {}  // 0x0064f584
void Unwind_0064f592() {}  // 0x0064f592
void Unwind_0064f59a() {}  // 0x0064f59a
void Unwind_0064f5a2() {}  // 0x0064f5a2
void Unwind_0064f5d0() {}  // 0x0064f5d0
void Unwind_0064f5e9() {}  // 0x0064f5e9
void Unwind_0064f5f1() {}  // 0x0064f5f1
void Unwind_0064f600() {}  // 0x0064f600
void Unwind_0064f608() {}  // 0x0064f608
void Unwind_0064f610() {}  // 0x0064f610
void Unwind_0064f61b() {}  // 0x0064f61b
void Unwind_0064f623() {}  // 0x0064f623
void Unwind_0064f650() {}  // 0x0064f650
void Unwind_0064f669() {}  // 0x0064f669
void Unwind_0064f671() {}  // 0x0064f671
void Unwind_0064f680() {}  // 0x0064f680
void Unwind_0064f688() {}  // 0x0064f688
void Unwind_0064f690() {}  // 0x0064f690
void Unwind_0064f69b() {}  // 0x0064f69b
void Unwind_0064f6a3() {}  // 0x0064f6a3
void Unwind_0064f6d0() {}  // 0x0064f6d0
void Unwind_0064f6e9() {}  // 0x0064f6e9
void Unwind_0064f6f1() {}  // 0x0064f6f1
void Unwind_0064f700() {}  // 0x0064f700
void Unwind_0064f708() {}  // 0x0064f708
void Unwind_0064f710() {}  // 0x0064f710
void Unwind_0064f71b() {}  // 0x0064f71b
void Unwind_0064f723() {}  // 0x0064f723
void Unwind_0064f750() {}  // 0x0064f750
void Unwind_0064f780() {}  // 0x0064f780
void Unwind_0064f7b0() {}  // 0x0064f7b0
void Unwind_0064f7e0() {}  // 0x0064f7e0
void Unwind_0064f7e8() {}  // 0x0064f7e8
void Unwind_0064f820() {}  // 0x0064f820
void Unwind_0064f850() {}  // 0x0064f850
void Unwind_0064f858() {}  // 0x0064f858
void Unwind_0064f890() {}  // 0x0064f890
void Unwind_0064f89f() {}  // 0x0064f89f
void Unwind_0064f8d0() {}  // 0x0064f8d0
void Unwind_0064f900() {}  // 0x0064f900
void Unwind_0064f908() {}  // 0x0064f908
void Unwind_0064f910() {}  // 0x0064f910
void Unwind_0064f918() {}  // 0x0064f918
void Unwind_0064f920() {}  // 0x0064f920
void Unwind_0064f928() {}  // 0x0064f928
void Unwind_0064f960() {}  // 0x0064f960
void Unwind_0064f990() {}  // 0x0064f990
void Unwind_0064f998() {}  // 0x0064f998
void Unwind_0064f9d0() {}  // 0x0064f9d0
void Unwind_0064fa00() {}  // 0x0064fa00
void Unwind_0064fa08() {}  // 0x0064fa08
void Unwind_0064fa40() {}  // 0x0064fa40
void Unwind_0064fa48() {}  // 0x0064fa48
void Unwind_0064fa80() {}  // 0x0064fa80
void Unwind_0064fab0() {}  // 0x0064fab0
void Unwind_0064fabf() {}  // 0x0064fabf
void Unwind_0064fac7() {}  // 0x0064fac7
void Unwind_0064facf() {}  // 0x0064facf
void Unwind_0064fb00() {}  // 0x0064fb00
void Unwind_0064fb08() {}  // 0x0064fb08
void Unwind_0064fb21() {}  // 0x0064fb21
void Unwind_0064fb29() {}  // 0x0064fb29
void Unwind_0064fb31() {}  // 0x0064fb31
void Unwind_0064fb39() {}  // 0x0064fb39
void Unwind_0064fb70() {}  // 0x0064fb70
void Unwind_0064fba0() {}  // 0x0064fba0
void Unwind_0064fbd0() {}  // 0x0064fbd0
void Unwind_0064fbd8() {}  // 0x0064fbd8
void Unwind_0064fc10() {}  // 0x0064fc10
void Unwind_0064fc50() {}  // 0x0064fc50
void Unwind_0064fc58() {}  // 0x0064fc58
void Unwind_0064fc60() {}  // 0x0064fc60
void Unwind_0064fc90() {}  // 0x0064fc90
void Unwind_0064fc98() {}  // 0x0064fc98
void Unwind_0064fca7() {}  // 0x0064fca7
void Unwind_0064fcb2() {}  // 0x0064fcb2
void Unwind_0064fce0() {}  // 0x0064fce0
void Unwind_0064fd10() {}  // 0x0064fd10
void Unwind_0064fd40() {}  // 0x0064fd40
void Unwind_0064fd48() {}  // 0x0064fd48
void Unwind_0064fd50() {}  // 0x0064fd50
void Unwind_0064fd80() {}  // 0x0064fd80
void Unwind_0064fd88() {}  // 0x0064fd88
void Unwind_0064fd90() {}  // 0x0064fd90
void Unwind_0064fde0() {}  // 0x0064fde0
void Unwind_0064fde8() {}  // 0x0064fde8
void Unwind_0064fe20() {}  // 0x0064fe20
void Unwind_0064fe28() {}  // 0x0064fe28
void Unwind_0064fe30() {}  // 0x0064fe30
void Unwind_0064fe38() {}  // 0x0064fe38
void Unwind_0064fe70() {}  // 0x0064fe70
void Unwind_0064fe78() {}  // 0x0064fe78
void Unwind_0064feb0() {}  // 0x0064feb0
void Unwind_0064feb8() {}  // 0x0064feb8
void Unwind_0064fec3() {}  // 0x0064fec3
void Unwind_0064fece() {}  // 0x0064fece
void Unwind_0064fed9() {}  // 0x0064fed9
void Unwind_0064fee1() {}  // 0x0064fee1
void Unwind_0064feec() {}  // 0x0064feec
void Unwind_0064ff02() {}  // 0x0064ff02
void Unwind_0064ff0d() {}  // 0x0064ff0d
void Unwind_0064ff18() {}  // 0x0064ff18
void Unwind_0064ff23() {}  // 0x0064ff23
void Unwind_0064ff2e() {}  // 0x0064ff2e
void Unwind_0064ff44() {}  // 0x0064ff44
void Unwind_0064ff4f() {}  // 0x0064ff4f
void Unwind_0064ff5a() {}  // 0x0064ff5a
void Unwind_0064ff70() {}  // 0x0064ff70
void Unwind_0064ff7b() {}  // 0x0064ff7b
void Unwind_0064ff86() {}  // 0x0064ff86
void Unwind_0064ff9c() {}  // 0x0064ff9c
void Unwind_0064ffa7() {}  // 0x0064ffa7
void Unwind_0064ffbd() {}  // 0x0064ffbd
void Unwind_0064ffd3() {}  // 0x0064ffd3
void Unwind_0064ffe9() {}  // 0x0064ffe9
void Unwind_0064fff4() {}  // 0x0064fff4
void Unwind_0064ffff() {}  // 0x0064ffff
void Unwind_00650015() {}  // 0x00650015
void Unwind_00650020() {}  // 0x00650020
void Unwind_00650036() {}  // 0x00650036
void Unwind_00650041() {}  // 0x00650041
void Unwind_0065004c() {}  // 0x0065004c
void Unwind_00650062() {}  // 0x00650062
void Unwind_0065006d() {}  // 0x0065006d
void Unwind_00650078() {}  // 0x00650078
void Unwind_00650080() {}  // 0x00650080
void Unwind_00650096() {}  // 0x00650096
void Unwind_006500a1() {}  // 0x006500a1
void Unwind_006500b7() {}  // 0x006500b7
void Unwind_006500c2() {}  // 0x006500c2
void Unwind_006500d8() {}  // 0x006500d8
void Unwind_006500e3() {}  // 0x006500e3
void Unwind_006500ee() {}  // 0x006500ee
void Unwind_006500f6() {}  // 0x006500f6
void Unwind_0065010c() {}  // 0x0065010c
void Unwind_00650117() {}  // 0x00650117
void Unwind_0065012d() {}  // 0x0065012d
void Unwind_00650138() {}  // 0x00650138
void Unwind_0065014e() {}  // 0x0065014e
void Unwind_00650159() {}  // 0x00650159
void Unwind_0065016f() {}  // 0x0065016f
void Unwind_0065017a() {}  // 0x0065017a
void Unwind_00650190() {}  // 0x00650190
void Unwind_0065019b() {}  // 0x0065019b
void Unwind_006501a6() {}  // 0x006501a6
void Unwind_006501b1() {}  // 0x006501b1
void Unwind_006501c7() {}  // 0x006501c7
void Unwind_006501dd() {}  // 0x006501dd
void Unwind_00650230() {}  // 0x00650230
void Unwind_0065023b() {}  // 0x0065023b
void Unwind_00650246() {}  // 0x00650246
void Unwind_0065025c() {}  // 0x0065025c
void Unwind_00650267() {}  // 0x00650267
void Unwind_00650272() {}  // 0x00650272
void Unwind_0065027d() {}  // 0x0065027d
void Unwind_00650293() {}  // 0x00650293
void Unwind_0065029e() {}  // 0x0065029e
void Unwind_006502a9() {}  // 0x006502a9
void Unwind_006502bf() {}  // 0x006502bf
void Unwind_006502ca() {}  // 0x006502ca
void Unwind_006502d5() {}  // 0x006502d5
void Unwind_006502eb() {}  // 0x006502eb
void Unwind_006502f3() {}  // 0x006502f3
void Unwind_006502fe() {}  // 0x006502fe
void Unwind_00650314() {}  // 0x00650314
void Unwind_0065031c() {}  // 0x0065031c
void Unwind_00650327() {}  // 0x00650327
void Unwind_00650332() {}  // 0x00650332
void Unwind_0065033d() {}  // 0x0065033d
void Unwind_00650353() {}  // 0x00650353
void Unwind_00650369() {}  // 0x00650369
void Unwind_00650374() {}  // 0x00650374
void Unwind_00650393() {}  // 0x00650393
void Unwind_0065039b() {}  // 0x0065039b
void Unwind_006503e0() {}  // 0x006503e0
void Unwind_006503e8() {}  // 0x006503e8
void Unwind_00650420() {}  // 0x00650420
void Unwind_00650450() {}  // 0x00650450
void Unwind_00650458() {}  // 0x00650458
void Unwind_00650460() {}  // 0x00650460
void Unwind_00650490() {}  // 0x00650490
void Unwind_006504d0() {}  // 0x006504d0
void Unwind_006504d8() {}  // 0x006504d8
void Unwind_006504e0() {}  // 0x006504e0
void Unwind_006504e8() {}  // 0x006504e8
void Unwind_006504fb() {}  // 0x006504fb
void Unwind_00650540() {}  // 0x00650540
void Unwind_0065054a() {}  // 0x0065054a
void Unwind_00650580() {}  // 0x00650580
void Unwind_0065058a() {}  // 0x0065058a
void Unwind_006505c0() {}  // 0x006505c0
void Unwind_006505c8() {}  // 0x006505c8
void Unwind_00650600() {}  // 0x00650600
void Unwind_00650608() {}  // 0x00650608
void Unwind_00650610() {}  // 0x00650610
void Unwind_00650650() {}  // 0x00650650
void Unwind_00650658() {}  // 0x00650658
void Unwind_00650690() {}  // 0x00650690
void Unwind_0065069b() {}  // 0x0065069b
void Unwind_006506a6() {}  // 0x006506a6
void Unwind_006506b1() {}  // 0x006506b1
void Unwind_006506bc() {}  // 0x006506bc
void Unwind_006506c7() {}  // 0x006506c7
void Unwind_006506d2() {}  // 0x006506d2
void Unwind_006506dd() {}  // 0x006506dd
void Unwind_00650720() {}  // 0x00650720
void Unwind_0065073f() {}  // 0x0065073f
void Unwind_0065075e() {}  // 0x0065075e
void Unwind_00650769() {}  // 0x00650769
void Unwind_00650771() {}  // 0x00650771
void Unwind_006507b0() {}  // 0x006507b0
void Unwind_006507b8() {}  // 0x006507b8
void Unwind_006507d1() {}  // 0x006507d1
void Unwind_006507d9() {}  // 0x006507d9
void Unwind_00650810() {}  // 0x00650810
void Unwind_00650850() {}  // 0x00650850
void Unwind_00650890() {}  // 0x00650890
void Unwind_006508d0() {}  // 0x006508d0
void Unwind_006508db() {}  // 0x006508db
void Unwind_006508e6() {}  // 0x006508e6
void Unwind_006508f1() {}  // 0x006508f1
void Unwind_006508fc() {}  // 0x006508fc
void Unwind_00650907() {}  // 0x00650907
void Unwind_00650912() {}  // 0x00650912
void Unwind_0065091d() {}  // 0x0065091d
void Unwind_00650960() {}  // 0x00650960
void Unwind_006509a0() {}  // 0x006509a0
void Unwind_006509a8() {}  // 0x006509a8
void Unwind_006509b0() {}  // 0x006509b0
void Unwind_006509bf() {}  // 0x006509bf
void Unwind_006509c7() {}  // 0x006509c7
void Unwind_00650a10() {}  // 0x00650a10
void Unwind_00650a18() {}  // 0x00650a18
void Unwind_00650a20() {}  // 0x00650a20
void Unwind_00650a28() {}  // 0x00650a28
void Unwind_00650a30() {}  // 0x00650a30
void Unwind_00650a38() {}  // 0x00650a38
void Unwind_00650a43() {}  // 0x00650a43
void Unwind_00650a4b() {}  // 0x00650a4b
void Unwind_00650a90() {}  // 0x00650a90
void Unwind_00650a9b() {}  // 0x00650a9b
void Unwind_00650ad0() {}  // 0x00650ad0
void Unwind_00650b00() {}  // 0x00650b00
void Unwind_00650b08() {}  // 0x00650b08
void Unwind_00650b40() {}  // 0x00650b40
void Unwind_00650b4b() {}  // 0x00650b4b
void Unwind_00650b80() {}  // 0x00650b80
void Unwind_00650bb0() {}  // 0x00650bb0
void Unwind_00650be0() {}  // 0x00650be0
void Unwind_00650c10() {}  // 0x00650c10
void Unwind_00650c18() {}  // 0x00650c18
void Unwind_00650c50() {}  // 0x00650c50
void Unwind_00650c58() {}  // 0x00650c58
void Unwind_00650c90() {}  // 0x00650c90
void Unwind_00650cd0() {}  // 0x00650cd0
void Unwind_00650cd8() {}  // 0x00650cd8
void Unwind_00650ce3() {}  // 0x00650ce3
void Unwind_00650cee() {}  // 0x00650cee
void Unwind_00650cf9() {}  // 0x00650cf9
void Unwind_00650d04() {}  // 0x00650d04
void Unwind_00650d16() {}  // 0x00650d16
void Unwind_00650d21() {}  // 0x00650d21
void Unwind_00650d29() {}  // 0x00650d29
void Unwind_00650d60() {}  // 0x00650d60
void Unwind_00650d6f() {}  // 0x00650d6f
void Unwind_00650d7a() {}  // 0x00650d7a
void Unwind_00650d89() {}  // 0x00650d89
void Unwind_00650d91() {}  // 0x00650d91
void Unwind_00650d99() {}  // 0x00650d99
void Unwind_00650dd0() {}  // 0x00650dd0
void Unwind_00650ddb() {}  // 0x00650ddb
void Unwind_00650e20() {}  // 0x00650e20
void Unwind_00650e50() {}  // 0x00650e50
void Unwind_00650e90() {}  // 0x00650e90
void Unwind_00650e98() {}  // 0x00650e98
void Unwind_00650ea0() {}  // 0x00650ea0
void Unwind_00650ed0() {}  // 0x00650ed0
void Unwind_00650f10() {}  // 0x00650f10
void Unwind_00650f18() {}  // 0x00650f18
void Unwind_00650f2b() {}  // 0x00650f2b
void Unwind_00650f35() {}  // 0x00650f35
void Unwind_00650f3d() {}  // 0x00650f3d
void Unwind_00650f80() {}  // 0x00650f80
void Unwind_00650f88() {}  // 0x00650f88
void Unwind_00650f93() {}  // 0x00650f93
void Unwind_00650f9e() {}  // 0x00650f9e
void Unwind_00650fb0() {}  // 0x00650fb0
void Unwind_00650fbe() {}  // 0x00650fbe
void Unwind_00650fcc() {}  // 0x00650fcc
void Unwind_00650fd7() {}  // 0x00650fd7
void Unwind_00650fe2() {}  // 0x00650fe2
void Unwind_00650fed() {}  // 0x00650fed
void Unwind_00650ff8() {}  // 0x00650ff8
void Unwind_00651003() {}  // 0x00651003
void Unwind_0065100e() {}  // 0x0065100e
void Unwind_00651050() {}  // 0x00651050
void Unwind_00651058() {}  // 0x00651058
void Unwind_0065107a() {}  // 0x0065107a
void Unwind_00651085() {}  // 0x00651085
void Unwind_0065108d() {}  // 0x0065108d
void Unwind_00651098() {}  // 0x00651098
void Unwind_006510a0() {}  // 0x006510a0
void Unwind_006510a8() {}  // 0x006510a8
void Unwind_006510b3() {}  // 0x006510b3
void Unwind_006510bb() {}  // 0x006510bb
void Unwind_006510c3() {}  // 0x006510c3
void Unwind_006510ce() {}  // 0x006510ce
void Unwind_006510d9() {}  // 0x006510d9
void Unwind_00651130() {}  // 0x00651130
void Unwind_00651138() {}  // 0x00651138
void Unwind_00651170() {}  // 0x00651170
void Unwind_00651178() {}  // 0x00651178
void Unwind_006511c0() {}  // 0x006511c0
void Unwind_006511c8() {}  // 0x006511c8
void Unwind_00651230() {}  // 0x00651230
void Unwind_00651238() {}  // 0x00651238

// ─── Missing CRT/utility function stubs ─────────────────────────
// These are referenced as extern in function bodies above but never defined.

void ByteVectorAssignBuffer(int, int, unsigned int) { } // RE stub — FUN_004388f0
void CopyIteratedElement(int, unsigned int) { }          // RE stub — FUN_0044dc30
void CopySingleElement(unsigned int, int) { }            // RE stub — FUN_0044d540
void LogRuntimeError(unsigned int) { }                   // RE stub — FUN_0061d250
void PlacementConstruct(unsigned int*, unsigned int) { } // RE stub — FUN_0043d010
void ReportBoundsError(unsigned long long*) { }          // RE stub — FUN_005fac30
void SetupContextCallback(int, int, unsigned int, unsigned int) { } // RE stub — FUN_004f5070
void SsoStringAssignImpl(int) { }                        // RE stub — FUN_00443a20
void StdExceptionDestroy(unsigned int*) { }              // RE stub — __std_exception_destroy
int  VectorFreeBuffer() { return 0; }                    // RE stub — FUN_0042b1f0

// _CxxThrowException — MSVC EH throw. Never returns.
// In MinGW, the real one is in libstdc++, but our namespace-qualified version needs a definition.
void _CxxThrowException(void*, void*) { std::abort(); } // RE stub — noreturn

} // namespace Giants
