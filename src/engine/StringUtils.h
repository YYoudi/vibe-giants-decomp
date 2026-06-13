// Giants Engine - SSO String Utilities + Format/Debug Output
// Reverse engineered from GiantsMain.exe v1.520.59
//
// ─── SSO String Core ──────────────────────────────────────────────
// FUN_004439b0 — ClearStdString (PASS, trivial)
//   Clears an SSO (Small String Optimization) std::string, freeing heap
//   storage if the string exceeds the 16-byte inline buffer.
//   Called 434 times across the binary.
//
// FUN_00442eb0 — String::Assign (PASS, trivial)
//   Assigns a raw byte buffer into an SSO std::string. Strings <= 15 bytes
//   are stored inline; longer strings are heap-allocated with a capacity of
//   at least 22 bytes, capped at INT_MAX.
//   Called 88 times across the binary.
//
// ─── CRT String Helpers ───────────────────────────────────────────
// FUN_00443110 — std::_Xlength_error("string too long") — noreturn
//   29 callers. Thrown when string length exceeds INT_MAX.
//
// FUN_00443120 — Aligned operator new wrapper
//   32 callers. Allocates memory with 32-byte alignment for large blocks.
//
// FUN_00443f80 — Shared pointer / COM ref-count constructor
//   3 callers. Creates a ref-counted object via vtable dispatch.
//
// ─── Format/Output Functions ──────────────────────────────────────
// FUN_00463000 — Sprintf wrapper (527 callers, HIGHEST CALL COUNT)
//   Thin wrapper around vsprintf base. Formats a string with variadic args.
//
// FUN_00462fc0 — vsprintf base (7 callers)
//   Core formatted-output function using __stdio_common_vsprintf.
//
// FUN_00461f00 — Debug log output (18 callers)
//   Formats and outputs a debug message via the logging subsystem.
//
// SSO string layout (x86, MSVC):
//   Offset 0x00 (0..3) : union { char inlineBuf[16]; char* heapPtr; }
//   Offset 0x10 (4)    : uint32_t length
//   Offset 0x14 (5)    : uint32_t capacity (0xF = inline mode)
//   Total size: 24 bytes (0x18)

#pragma once

#include <cstdint>
#include <cstdarg>

namespace Giants {

// ─── SSO String Representation ────────────────────────────────────
// Matches MSVC x86 std::string internal layout.
// When capacity == 0xF (15), the string data is stored inline in the
// first 16 bytes. Otherwise, the first 4 bytes are a heap pointer.

struct SsoString {
    union {
        char    inlineBuf[16];    // @ 0x00 — inline storage (capacity <= 15)
        char*   heapPtr;          // @ 0x00 — heap pointer (capacity > 15)
    };
    uint32_t length;              // @ 0x10 — current string length
    uint32_t capacity;            // @ 0x14 — capacity (0xF = SSO inline mode)
};
static_assert(sizeof(SsoString) == 0x18, "SsoString size mismatch");

// ─── SSO String Functions ─────────────────────────────────────────

/// Clear an SSO string. If the string uses heap storage (capacity > 15),
/// the heap buffer is freed via the CRT internal free path (FUN_00643505).
/// After clearing: length=0, capacity=15, inlineBuf[0]='\0'.
///
/// Ghidra: FUN_004439b0 (434 callers)
/// Parameters:
///   str — pointer to the SsoString to clear
void ClearStdString(SsoString* str);

/// Assign a raw byte buffer into an SSO string.
/// If the source length < 16, data is stored inline.
/// Otherwise, a heap buffer is allocated with capacity >= max(22, length|0xF),
/// capped at 0x7FFFFFFF.
///
/// Ghidra: FUN_00442eb0 (88 callers)
/// Parameters:
///   str   — [this] pointer to the SsoString to assign into
///   src   — pointer to source data
///   count — number of bytes to copy
void StringAssign(SsoString* str, const void* src, uint32_t count);

// ─── CRT String Helpers ───────────────────────────────────────────

/// Throw std::length_error("string too long"). Does not return.
/// Called when string length exceeds INT_MAX (0x7FFFFFFF).
/// Ghidra: FUN_00443110 (29 callers, noreturn)
[[noreturn]] void ThrowStringLengthError();

/// Aligned memory allocation wrapper around operator new.
/// For allocations < 0x1000 bytes, delegates directly to operator new.
/// For larger allocations, adds 0x23 bytes of overhead for 32-byte alignment:
///   - Allocates size + 0x23 bytes
///   - Stores the original pointer at (aligned_addr - 4) for free()
///   - Calls _invoke_watson on allocation failure
/// Ghidra: FUN_00443120 (32 callers)
///
/// @param size  Number of bytes to allocate
/// @return      Pointer to allocated memory (32-byte aligned for large blocks)
void* AlignedNew(uint32_t size);

/// Shared pointer / COM-style ref-counted object constructor.
/// Dispatches via vtable to construct a ref-counted smart pointer.
/// The returned int* points to a 2-field struct: [object_ptr, refcount_ptr].
/// Uses LOCK/UNLOCK (InterlockedDecrement/Increment) for thread-safe refcount.
/// When strong refcount drops to 0, calls destructor via vtable[0].
/// When weak refcount drops to 1, calls weak destructor via vtable[1].
/// Ghidra: FUN_00443f80 (3 callers, 0 callees)
///
/// @param param_1  Type tag or flags controlling which vtable entry is called
/// @return         Pointer to ref-counted object pair [ptr, refcount]
int* CreateSharedRef(uint32_t param_1);

/// Overflow handler — throws a C++ exception via _CxxThrowException.
/// Called when an integer overflow is detected (e.g., size + overhead wraps).
/// First calls FUN_0042b9a0 to build the exception object, then throws.
/// Ghidra: FUN_0042bad0 (44 callers, 2 callees) — noreturn
[[noreturn]] void ThrowOverflowError();

/// Engine log output dispatcher. The central logging function with 74 callers.
/// Checks if the log channel is enabled (param_1+4 != 0), then dispatches
/// to registered callback functions based on flags in param_2:
///   - flag 0x2: calls FUN_0043dcd0 (hash lookup), then FUN_0043f360 to
///     invoke a std::function callback at vtable+8
///   - flag 0x4: same pattern with different hash constant
/// Uses security cookie at DAT_0067d280 for stack protection.
///
/// Ghidra: FUN_0043f440 (74 callers, 3 callees)
///   Callees: FUN_0043dcd0, FUN_0043f360, std::_Xbad_function_call
///
/// @param param_1  this/context pointer — log channel object (offset +4 = enabled,
///                 +0x10 = flags, +0x28 = base index)
/// @param param_2  Output flags bitmask (2 = callback type A, 4 = callback type B)
/// @param param_3  Message data / formatted string
/// @param param_4  Additional message parameter
void LogOutput(int param_1, uint32_t param_2, int param_3, uint32_t param_4);

// ─── Format/Output Functions ──────────────────────────────────────

/// Sprintf wrapper — the most-called utility function in the binary.
/// Thin wrapper around FormatStringV(). Formats a string into a buffer
/// using printf-style format specifiers with variadic arguments.
///
/// Ghidra: FUN_00463000 (527 callers, 1 callee — FormatStringV)
/// Calling convention: __thiscall
///   param_1 = this/context (unused, passed through)
///   param_2 = output buffer
///   param_3 = format string
///   ...     = variadic arguments (on stack at &stack0x0000000c)
///
/// @param context    Context pointer (typically unused / this ptr)
/// @param buffer     Output buffer for formatted string
/// @param format     printf-style format string
/// @param ...        Variadic arguments
void FormatString(uint32_t context, uint32_t buffer, uint32_t format, ...);

/// Core vsprintf implementation using MSVC __stdio_common_vsprintf.
/// Calls GetLocaleData() to retrieve format options and locale context from
/// DAT_006fd540, then invokes __stdio_common_vsprintf with the | 1 flag
/// (null terminator enforced). Returns -1 if the result is negative.
///
/// Ghidra: FUN_00462fc0 (7 callers, 2 callees)
///   Callees: FUN_00439240 (GetLocaleData), __stdio_common_vsprintf
///
/// @param format     printf-style format string
/// @param localeData Locale/formatting data (from DAT_006fd540)
/// @param argList    Start of variadic argument list
/// @param buffer     Output buffer
/// @param ...        Additional parameters
/// @return           Number of characters written, or -1 on error
int FormatStringV(uint32_t format, uint32_t localeData, uint32_t argList, uint32_t buffer, ...);

/// Returns pointer to the internal locale/formatting data at DAT_006fd540.
/// Trivial one-liner: return &DAT_006fd540.
/// Used by FormatStringV for locale-aware number formatting.
/// Ghidra: FUN_00439240 (4 callers, 0 callees)
uint32_t* GetLocaleData();

/// Debug log output function.
/// Formats a message using {fmt} library (fmt::v9::vformat) and dispatches
/// it through the engine's logging subsystem (FUN_0043f440 with level=6,
/// flags=2). The formatted string is built on the stack (local_34, 24 bytes).
///
/// Ghidra: FUN_00461f00 (18 callers, 4 callees)
/// Security: Uses __security_check_cookie with cookie at DAT_0067d280.
///
/// @param param_1  Format string or format context
/// @param param_2  Format arguments or message data
void DebugLog(uint32_t param_1, uint32_t param_2);

} // namespace Giants
