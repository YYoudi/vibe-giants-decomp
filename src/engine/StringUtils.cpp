// Giants Engine - SSO String Utilities + Format/Debug Output Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
//
// FUN_004439b0 — ClearStdString: frees heap buffer if SSO string is
//   heap-allocated, then resets to empty inline state.
//
// FUN_00442eb0 — String::Assign: copies raw bytes into SSO string,
//   choosing inline vs heap storage based on length.
//
// FUN_00443110 — ThrowStringLengthError: std::_Xlength_error noreturn
// FUN_00443120 — AlignedNew: aligned operator new wrapper
// FUN_00443f80 — CreateSharedRef: COM-style ref-counted constructor
// FUN_0042bad0 — ThrowOverflowError: integer overflow exception (44 callers)
//
// FUN_00439240 — GetLocaleData: returns &DAT_006fd540 (4 callers)
// FUN_00463000 — FormatString: sprintf wrapper (527 callers)
// FUN_00462fc0 — FormatStringV: vsprintf base (7 callers)
// FUN_0043f440 — LogOutput: central log dispatcher (74 callers)
// FUN_00461f00 — DebugLog: debug log output (18 callers)

#include "StringUtils.h"
#include <cstdlib>
#include <cstring>

namespace Giants {

// ─── Internal CRT free helper ──────────────────────────────────────
// FUN_00643505 — CRT internal free path. Validated via _invoke_watson
// for heap corruption detection before freeing.

extern "C" {
    // CRT heap free (FUN_00643505) — internal free used by MSVC SSO strings.
    // Performs bounds checking before deallocation.
    void __cdecl CRT_InternalFree(void* ptr, uint32_t size);

    // Invalid parameter handler — called on heap corruption.
    // Does not return.
    void __cdecl _invoke_watson(void*, void*, void*, int, int);
}

// ═══════════════════════════════════════════════════════════════════
// SSO String Functions
// ═══════════════════════════════════════════════════════════════════

// ─── ClearStdString (FUN_004439b0) ─────────────────────────────────
// Clears an SSO string. If the string data is on the heap (capacity > 15),
// the heap buffer is validated and freed via CRT_InternalFree.
//
// Assembly note: param_1 is treated as int[6] by Ghidra because SSO fields
// are accessed as 4-byte slots:
//   param_1[0] = heapPtr/inlineBuf[0..3]
//   param_1[4] = length
//   param_1[5] = capacity

void ClearStdString(SsoString* str)
{
    uint32_t cap = str->capacity;           // param_1[5] — DAT: capacity field

    if (cap > 0xF)
    {
        // String is heap-allocated. Retrieve heap pointer.
        char* heapBuf = str->heapPtr;       // param_1[0] — DAT: heap pointer

        // Compute free size: length + 1 (for null terminator)
        uint32_t freeSize = cap + 1;        // uVar4 = uVar1 + 1

        // MSVC debug heap: if freeSize > 0xFFF, validate the heap block
        // by checking the block header at (heapPtr - 4).
        // If the block metadata is inconsistent, invoke Watson crash handler.
        if (freeSize > 0xFFF)
        {
            // DAT_00643505 internal: reads *(heapPtr - 4) for block size validation.
            // If the delta between heapPtr and block start exceeds 0x1F (31 bytes),
            // the heap is corrupted.
            char* blockStart = *(char**)(heapBuf - 4);   // iVar3 = *(iVar2 + -4)
            uint32_t adjustedSize = cap + 0x24;           // uVar4 = uVar1 + 0x24

            // Bounds check: if (heapBuf - blockStart - 4) > 31, heap corruption
            uint32_t blockDelta = (uint32_t)(heapBuf - blockStart) - 4;
            if (blockDelta > 0x1F)
            {
                // DAT: _invoke_watson — fatal crash, does not return
                std::abort();
            }

            // Free via CRT internal path
            CRT_InternalFree(blockStart, adjustedSize);
        }
        else
        {
            // Small heap block, free directly
            CRT_InternalFree(heapBuf, freeSize);
        }
    }

    // Reset to empty inline SSO state
    str->length   = 0;          // param_1[4] = 0
    str->capacity = 0xF;        // param_1[5] = 0xF — inline mode
    str->inlineBuf[0] = '\0';   // *param_1 = 0 — null terminator
}

// ─── StringAssign (FUN_00442eb0) ───────────────────────────────────
// Assigns a raw buffer into an SSO string. The function selects inline
// or heap storage based on the source length:
//   - count < 16: inline storage (SSO), capacity set to 15
//   - count >= 16: heap allocation, capacity = max(22, count | 0xF)
//
// Note: The original binary calls FUN_00443110 (ThrowStringLengthError)
// when count > 0x7FFFFFFF, and FUN_00443120 (AlignedNew) for heap alloc.

void StringAssign(SsoString* str, const void* src, uint32_t count)
{
    // Guard against absurd length — would throw std::length_error
    if (count > 0x7FFFFFFF)
    {
        // DAT: FUN_00443110 — std::length_error("string too long")
        // This path does not return in normal operation.
        abort();
    }

    if (count < 0x10)
    {
        // ── Inline SSO path ──────────────────────────────────────
        // Source fits in the 16-byte inline buffer.
        str->length   = count;        // param_1[4] = count
        str->capacity = 0xF;          // param_1[5] = 0xF — inline mode

        // Copy source data into inline buffer and null-terminate
        memcpy(str->inlineBuf, src, count);
        str->inlineBuf[count] = '\0';
        return;
    }

    // ── Heap allocation path ─────────────────────────────────────
    // Compute allocation capacity: max(count | 0xF, 0x16), capped at 0x7FFFFFFF.
    // This ensures a minimum capacity of 22 bytes for heap-allocated strings.

    uint32_t allocCap = count | 0xF;         // uVar1 = param_3 | 0xf

    if (allocCap < 0x80000000)
    {
        if (allocCap < 0x16)
        {
            allocCap = 0x16;                  // minimum heap capacity = 22 bytes
        }
    }
    else
    {
        allocCap = 0x7FFFFFFF;                // cap at INT_MAX
    }

    // Allocate heap buffer (count + 1 for null terminator via allocCap + 1)
    // DAT: FUN_00443120 — operator new(allocCap + 1)
    char* heapBuf = static_cast<char*>(malloc(allocCap + 1));

    // Store string metadata
    str->length   = count;          // param_1[4] = count
    str->heapPtr  = heapBuf;        // *param_1 = heapBuf
    str->capacity = allocCap;       // param_1[5] = allocCap

    // Copy data and null-terminate
    memcpy(heapBuf, src, count);
    heapBuf[count] = '\0';
}

// ═══════════════════════════════════════════════════════════════════
// CRT String Helpers
// ═══════════════════════════════════════════════════════════════════

// ─── ThrowStringLengthError (FUN_00443110) ─────────────────────────
// Throws std::length_error("string too long").
// Called when a string operation would exceed INT_MAX length.
// Ghidra decompilation shows direct call to std::_Xlength_error.

[[noreturn]] void ThrowStringLengthError()
{
    // DAT: std::_Xlength_error("string too long") — does not return
    abort();
}

// ─── AlignedNew (FUN_00443120) ─────────────────────────────────────
// Memory allocation with 32-byte alignment for blocks >= 0x1000 bytes.
//
// Behavior:
//   - size == 0: returns immediately (no allocation)
//   - size < 0x1000: delegates to standard operator new (no alignment)
//   - size >= 0x1000: allocates size + 0x23, aligns to 32-byte boundary,
//     stores original pointer at (aligned_addr - 4) for later free()
//
// Ghidra: FUN_00443120 (32 callers, 3 callees)
//   Callees: operator_new, FUN_0042bad0 (overflow check), _invoke_watson

void* AlignedNew(uint32_t size)
{
    if (size == 0)
    {
        return nullptr;
    }

    if (size < 0x1000)
    {
        // Small allocation: use standard operator new
        return operator new(size);
    }

    // Overflow check: if size + 0x23 wraps around, fatal error
    if (size + 0x23 <= size)
    {
        // DAT: FUN_0042bad0 — overflow handler, does not return
        abort();
    }

    // Allocate with alignment overhead
    void* rawPtr = operator new(size + 0x23);

    if (rawPtr == nullptr)
    {
        // DAT: _invoke_watson — allocation failure, does not return
        std::abort();
    }

    // Align to 32-byte boundary: (rawPtr + 0x23) & ~0x1F
    // Store original pointer at (aligned - 4) for deallocation
    uint32_t aligned = ((uint32_t)rawPtr + 0x23U) & 0xFFFFFFE0;
    *(void**)(aligned - 4) = rawPtr;

    return (void*)aligned;
}

// ─── CreateSharedRef (FUN_00443f80) ────────────────────────────────
// Creates a shared pointer / COM-style ref-counted object.
// Dispatches through a vtable entry to construct the object, then sets up
// a 2-field return struct: [object_ptr, refcount_ptr].
//
// Thread-safe: Uses LOCK/UNLOCK (InterlockedDecrement/Increment) for
// refcount management. Strong refcount at control_block[1], weak refcount
// at control_block[2]. When strong ref drops to 0, destructor (vtable[0])
// is called. When weak ref drops to 1, weak destructor (vtable[1]) is called.
//
// Ghidra: FUN_00443f80 (3 callers, 0 callees)
// Original:
//   int * __fastcall FUN_00443f80(uint param_1) {
//       (**(code **)(*(int *)(-(uint)(param_1 != 0xfffffffc) & param_1) + 8))
//           (local_8, &DAT_0065d154);
//       *piStack_4 = 0;
//       piStack_4[1] = 0;
//       if (unaff_EBX == 0) {
//           if (piStack_c != (int *)0x0) {
//               LOCK(); iVar2 = piStack_c[1] + -1; piStack_c[1] = iVar2; UNLOCK();
//               if (iVar2 == 0) {
//                   (**(code **)*piStack_c)();    // destroy object
//                   LOCK(); piVar1 = piStack_c + 2; iVar2 = *piVar1; *piVar1 -= 1; UNLOCK();
//                   if (iVar2 == 1) {
//                       (**(code **)(*piStack_c + 4))();  // destroy control block
//                   }
//               }
//           }
//       } else {
//           if (piStack_c != (int *)0x0) {
//               LOCK(); piStack_c[1] += 1; UNLOCK();    // increment strong ref
//           }
//           *piStack_4 = unaff_EBX;
//           piStack_4[1] = (int)piStack_c;
//           if (piStack_c != (int *)0x0) {
//               LOCK(); iVar2 = piStack_c[1] - 1; piStack_c[1] = iVar2; UNLOCK();
//               if (iVar2 == 0) {
//                   (**(code **)*piStack_c)();
//                   LOCK(); piVar1 = piStack_c + 2; iVar2 = *piVar1; *piVar1 -= 1; UNLOCK();
//                   if (iVar2 == 1) { (**(code **)(*piStack_c + 4))(); return piStack_4; }
//               }
//           }
//       }
//       return piStack_4;
//   }

int* CreateSharedRef(uint32_t param_1)
{
    // Vtable dispatch: select vtable by masking param_1
    // vtable = *(param_1 & -(param_1 != 0xFFFFFFFC))
    // Then call vtable[2] (offset +8) to construct the object
    uint32_t vtableSelector = -(uint32_t)(param_1 != 0xFFFFFFFC) & param_1;

    // Allocate return struct: [object_ptr, control_block_ptr]
    // The actual binary constructs via vtable dispatch to DAT_0065d154
    // and manages refcounts through LOCK/UNLOCK atomics.
    // Stub: return null pair for now.
    (void)vtableSelector;
    return nullptr;
}

// ═══════════════════════════════════════════════════════════════════
// Format/Output Functions
// ═══════════════════════════════════════════════════════════════════

// ─── GetLocaleData (FUN_00439240) ───────────────────────────────────
// Returns pointer to the internal locale/formatting data at DAT_006fd540.
// Trivial one-liner used by FormatStringV and other CRT formatting functions.
//
// Ghidra: FUN_00439240 (4 callers, 0 callees)
// Original:
//   undefined * FUN_00439240(void) {
//       return &DAT_006fd540;
//   }

uint32_t* GetLocaleData()
{
    return reinterpret_cast<uint32_t*>(0x006fd540);  // DAT_006fd540
}

// ─── FormatString (FUN_00463000) ───────────────────────────────────
// THE most-called function in the binary after CRT stubs.
// Thin wrapper that forwards to FormatStringV with the variadic
// arguments located at &stack0x0000000c (3 params above the call).
//
// Ghidra: FUN_00463000 (527 callers, 1 callee)
// Calling convention: __thiscall
//
// Decompilation:
//   void __thiscall FUN_00463000(undefined4 param_1, undefined4 param_2,
//                                undefined4 param_3)
//   {
//       FUN_00462fc0(param_3, param_1, &stack0x0000000c, param_1);
//       return;
//   }
//
// Note: The parameter mapping is non-standard. The this pointer (param_1)
// appears twice — once as the second arg to FormatStringV and once as
// the trailing param. This suggests the compiler reordered arguments
// for the variadic forwarding.

void FormatString(uint32_t context, uint32_t buffer, uint32_t format, ...)
{
    // Forward to FormatStringV with variadic args
    // In the binary: FUN_00462fc0(format, context, &varargs_start, context)
    va_list args;
    va_start(args, format);
    FormatStringV(format, context, reinterpret_cast<uint32_t>(args), buffer);
    va_end(args);
}

// ─── FormatStringV (FUN_00462fc0) ──────────────────────────────────
// Core vsprintf implementation. Calls GetLocaleData() to retrieve format
// options from DAT_006fd540, then invokes __stdio_common_vsprintf with
// the | 1 flag (null terminator enforced). Returns -1 on negative result.
//
// Ghidra: FUN_00462fc0 (7 callers, 2 callees)
//   Callees: FUN_00439240 (GetLocaleData), __stdio_common_vsprintf
//
// Original:
//   int __fastcall FUN_00462fc0(undefined4 param_1, undefined4 param_2,
//                                undefined4 param_3, undefined4 param_4,
//                                undefined4 param_5)
//   {
//       uint *puVar1 = (uint *)FUN_00439240(param_1, param_2, param_3, 0, param_5);
//       int iVar2 = __stdio_common_vsprintf(*puVar1 | 1, puVar1[1]);
//       if (iVar2 < 0) {
//           iVar2 = -1;
//       }
//       return iVar2;
//   }
//
// The locale data at DAT_006fd540 is accessed as:
//   [0] = format options (passed to vsprintf with | 1 for null-terminate)
//   [1] = locale handle / context

int FormatStringV(uint32_t format, uint32_t localeData, uint32_t argList, uint32_t buffer, ...)
{
    // Get locale/formatting data from DAT_006fd540
    // In the binary, GetLocaleData returns &DAT_006fd540 directly
    uint32_t* localePtr = GetLocaleData();

    // Call __stdio_common_vsprintf with null-terminate flag (| 1)
    // localePtr[0] = format options, localePtr[1] = locale context
    // The remaining params (format, argList, buffer, ...) are forwarded
    // to the CRT vsprintf implementation.
    int result = 0;  // Stub: would call __stdio_common_vsprintf

    // In the binary:
    //   result = __stdio_common_vsprintf(localePtr[0] | 1, localePtr[1], ...);
    if (result < 0)
    {
        result = -1;
    }

    return result;
}

// ─── DebugLog (FUN_00461f00) ───────────────────────────────────────
// Debug log output function. Formats a message using {fmt} and dispatches
// through the engine's logging subsystem.
//
// Ghidra: FUN_00461f00 (18 callers, 4 callees)
//   Callees: fmt::v9::vformat, FUN_0043f440 (LogOutput), ClearStdString,
//            __security_check_cookie
//
// Security cookie: DAT_0067d280
//
// Decompilation:
//   void FUN_00461f00(undefined4 param_1, undefined4 param_2)
//   {
//       local_34[24];   // format output buffer (stack)
//       local_1c[8];    // format args (stack)
//       fmt::v9::vformat(local_34, param_1, param_2, 0, 0, local_1c);
//       FUN_0043f440(6, 2, local_34);   // level=6, flags=2
//       FUN_004439b0(cookie);            // clear temp string
//   }
//
// The {fmt} library (fmt::v9) is statically linked into the binary.
// FUN_0043f440 is the log dispatch function with 74 callers total.
// Level 6 appears to be the debug/informational level.

void DebugLog(uint32_t param_1, uint32_t param_2)
{
    // Stack-allocated format output buffer (24 bytes)
    char formatBuffer[24];

    // Stack-allocated format arguments (8 bytes)
    char formatArgs[8];

    // DAT: fmt::v9::vformat — format the message using {fmt} library
    // fmt::v9::vformat(formatBuffer, param_1, param_2, 0, 0, formatArgs);

    // DAT: FUN_0043f440 — dispatch to logging subsystem
    // Parameters: (this=6, level=2, buffer=formatBuffer)
    // Level 6 = debug/informational output channel
    // FUN_0043f440(6, 2, formatBuffer);

    // DAT: FUN_004439b0 — clear the temporary format string
    // ClearStdString(reinterpret_cast<SsoString*>(formatBuffer));

    (void)formatBuffer;
    (void)formatArgs;
    (void)param_1;
    (void)param_2;
}

// ─── ThrowOverflowError (FUN_0042bad0) ─────────────────────────────
// Overflow handler. Builds a C++ exception object via FUN_0042b9a0,
// then throws it via _CxxThrowException with ThrowInfo at DAT_00677ef4.
// This is the standard MSVC overflow detection path — called when an
// integer addition wraps (e.g., size + overhead > INT_MAX).
//
// Ghidra: FUN_0042bad0 (44 callers, 2 callees) — noreturn
//   Callees: FUN_0042b9a0 (build exception), _CxxThrowException
//
// Original:
//   void FUN_0042bad0(void) {
//       undefined1 local_c [12];
//       FUN_0042b9a0();
//       _CxxThrowException(local_c, (ThrowInfo *)&DAT_00677ef4);
//   }

[[noreturn]] void ThrowOverflowError()
{
    // DAT: FUN_0042b9a0 — builds exception object on stack (12 bytes)
    // local_c[12] is the stack-allocated exception object.

    // DAT: _CxxThrowException — MSVC EH throw
    // ThrowInfo at DAT_00677ef4 describes the exception type for catch matching.
    // This path never returns.

    abort();  // Stub: unreachable
}

// ─── LogOutput (FUN_0043f440) ──────────────────────────────────────
// Central engine log dispatcher with 74 callers throughout the binary.
// Checks if the log channel is enabled (param_1+4 != 0), then dispatches
// to registered callback functions based on flags in param_2:
//   - flag 0x2: Hash-lookup dispatch with constant 0xEBEE7337
//   - flag 0x4: Hash-lookup dispatch with constant 0x0AE4F8D1
// Each flag path: FUN_0043dcd0 (hash table lookup) -> FUN_0043f360 (callback
// resolve) -> invoke std::function at vtable+8. If the function pointer at
// offset +0x24 is null, throws std::bad_function_call.
//
// Security: Uses cookie at DAT_0067d280 for /GS stack protection.
// Structured exception handling via local SEH chain (ExceptionList).
//
// Ghidra: FUN_0043f440 (74 callers, 3 callees)
//   Callees: FUN_0043dcd0 (hash lookup), FUN_0043f360 (callback resolve),
//            std::_Xbad_function_call
//
// Original:
//   void __thiscall FUN_0043f440(int param_1, uint param_2,
//                                 int param_3, undefined4 param_4) {
//       uVar1 = param_2;
//       ExceptionList = &local_10;
//       if (*(int *)(param_1 + 4) != 0) {
//           local_8 = 0; iVar4 = param_3; uVar5 = param_4; local_18 = param_1;
//           puVar2 = &uStack_28;
//           if ((param_2 & 2) != 0) {
//               param_2 = 2;
//               iVar3 = FUN_0043dcd0(&param_2, 0xebee7337,
//                           *(int *)(param_1 + 0x28) +
//                           (*(uint *)(param_1 + 0x10) & 0xebee7337) * 0x38);
//               if (iVar3 != 0) {
//                   param_2 = 2;
//                   iVar3 = FUN_0043f360(&param_2);
//                   if (*(int **)(iVar3 + 0x24) == (int *)0x0)
//                       std::_Xbad_function_call();
//                   (**(code **)(**(int **)(iVar3 + 0x24) + 8))(&param_3, param_4);
//               }
//           }
//           if ((uVar1 & 4) != 0) {
//               param_4 = 4;
//               iVar3 = FUN_0043dcd0(&param_4, 0xae4f8d1,
//                           *(int *)(local_18 + 0x28) +
//                           (*(uint *)(local_18 + 0x10) & 0xae4f8d1) * 0x38);
//               if (iVar3 != 0) {
//                   param_4 = 4;
//                   iVar3 = FUN_0043f360(&param_4);
//                   if (*(int **)(iVar3 + 0x24) == (int *)0x0)
//                       std::_Xbad_function_call();
//                   (**(code **)(**(int **)(iVar3 + 0x24) + 8))(&local_18, uVar5);
//               }
//           }
//       }
//       ExceptionList = local_10;
//       return;
//   }

void LogOutput(int param_1, uint32_t param_2, int param_3, uint32_t param_4)
{
    // Layout of log channel object (param_1):
    //   +0x04: enabled flag (int, must be non-zero to dispatch)
    //   +0x10: channel flags (used for hash computation)
    //   +0x28: base index (added to hash result for table lookup)

    // Check if this log channel is enabled
    int enabled = *(int*)(param_1 + 4);
    if (enabled == 0)
    {
        return;
    }

    int local_18 = param_1;
    int iVar4 = param_3;
    uint32_t uVar5 = param_4;
    uint32_t uVar1 = param_2;

    // ── Flag 0x2: callback type A ──────────────────────────────────
    if ((param_2 & 2) != 0)
    {
        // Hash table lookup with constant 0xEBEE7337
        // Table index = (param_1->base_index) + ((param_1->flags & 0xEBEE7337) * 0x38)
        // int hashResult = FUN_0043dcd0(2, 0xEBEE7337,
        //     *(int*)(param_1 + 0x28) + (*(uint32_t*)(param_1 + 0x10) & 0xEBEE7337) * 0x38);

        // if (hashResult != 0) {
        //     int callbackObj = FUN_0043f360(2);
        //     if (*(int**)(callbackObj + 0x24) == nullptr)
        //         std::_Xbad_function_call();  // no callable registered
        //     // Invoke the std::function at vtable+8
        //     (**(code**)(**(int**)(callbackObj + 0x24) + 8))(param_3, param_4);
        // }
    }

    // ── Flag 0x4: callback type B ──────────────────────────────────
    if ((uVar1 & 4) != 0)
    {
        // Hash table lookup with constant 0x0AE4F8D1
        // int hashResult = FUN_0043dcd0(4, 0x0AE4F8D1,
        //     *(int*)(local_18 + 0x28) + (*(uint32_t*)(local_18 + 0x10) & 0x0AE4F8D1) * 0x38);

        // if (hashResult != 0) {
        //     int callbackObj = FUN_0043f360(4);
        //     if (*(int**)(callbackObj + 0x24) == nullptr)
        //         std::_Xbad_function_call();
        //     (**(code**)(**(int**)(callbackObj + 0x24) + 8))(iVar4, uVar5);
        // }
    }

    (void)local_18;
    (void)iVar4;
    (void)uVar5;
    (void)uVar1;
}

} // namespace Giants
