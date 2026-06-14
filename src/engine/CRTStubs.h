// Giants Engine - CRT & Core Utility Stubs
// Reverse engineered from GiantsMain.exe v1.520.59
//
// These are low-level CRT/system utility functions that don't belong
// to any specific engine subsystem. They are referenced from multiple files.

#pragma once

#include <cstdint>
#include <windows.h>
#include <cstdio>

// ─── Ghidra decompilation compatibility types ───────────────────
// These types appear in Ghidra's C output and need C++ equivalents.
typedef uint32_t uint;
typedef uint8_t  byte;
typedef long double float10;
typedef void (*GhidraCodePtr)();  // Ghidra function pointer type
struct ExceptionList { int dummy; };
#define CONCAT31(x,y) ((uint32_t)(((uint32_t)(x) << 1) | (y)))
#define SQRT(x) sqrt(x)
// Suppress unused-variable warnings in Ghidra-generated code
#define GHIDRA_UNUSED(x) ((void)(x))

namespace Giants {

// ─── Ghidra extern stubs: most-referenced FUN_ symbols ──────────
// These forward-declare functions that Ghidra references by raw name.
// As real implementations are added, these can be removed.
extern uint32_t DAT_0067821c;
extern uint32_t DAT_00702d60;
extern uint32_t DAT_00748b50;
extern uint32_t DAT_00701bd8;
extern uint32_t DAT_0066bfe8;
extern uint32_t DAT_006543cc;
extern uint32_t PTR_FUN_0065dae4;
extern uint32_t DAT_0072c000;
extern uint32_t DAT_00682208;
extern uint32_t DAT_00682214;
extern uint32_t DAT_00681e30;
extern uint32_t DAT_00682210;
extern uint32_t DAT_00702968;
extern uint32_t DAT_00702bc0;
extern uint32_t _DAT_0067e474;
extern uint32_t _DAT_0067e524;
extern uint32_t _DAT_0067e574;
extern uint32_t _DAT_0067e624;
extern uint32_t _DAT_0067e6d4;
extern uint32_t _DAT_00000f54;

// ─── Additional DAT_* globals referenced in function bodies ─────────
extern uintptr_t g_securityCookie;  // DAT_0067d280 — CRT security cookie
extern uint32_t DAT_0067d280;       // Same cookie, used as uint32_t in function bodies
extern uint32_t DAT_0067d198;      // Identity matrix base
extern int DAT_0068220c;            // Camera mode flag (extern int in function body)
extern uint32_t DAT_00702770;      // Scene/context pointer (used as integer address)
extern uint32_t* DAT_007027ac;     // Entity linked list head
extern uint32_t* DAT_007027b0;     // Entity linked list head 2
extern uint32_t DAT_007027e0;      // Scene node pointer
extern uint32_t DAT_007028f4;      // Entity list base
extern int DAT_00702924;           // Player count
extern uint32_t DAT_00702940;      // Game state field
extern uint32_t DAT_00702964;      // Dedicated server flag
extern void* DAT_0073f7b4;         // VFS buffer pointer
extern uint32_t DAT_0073f7b8;      // VFS buffer current pos
extern uint32_t DAT_0073f7bc;      // VFS buffer end
extern uint32_t DAT_0073f7c0;      // VFS remaining bytes
extern void* DAT_0073f7c4;         // VFS file handle
extern uint32_t DAT_00749908;      // String table start
extern uint32_t DAT_0074990c;      // String table end
extern uint32_t DAT_0074bb60;      // Distance vector (3 floats)

// Forward declarations for Ghidra-referenced functions
int FUN_00481900(...);
int FUN_00462ed0(...);
int FUN_004439b0(...);
int FUN_0042aca0(...);
int FUN_00443110(...);
int FUN_0042b1f0(...);
int FUN_00443010(...);
int FUN_00558360(...);
int FUN_00656bf4(...);
int FUN_00559dc0(...);
void FUN_006387e0(float angle, uint32_t* sinOut, uint32_t* cosOut);  // SinCosLookup — real port in TrigTables.cpp
int FUN_0053ea80(...);
int FUN_00559530(...);
int FUN_00558730(...);
int FUN_0062a0b0(...);
int FUN_004d1070(...);
int FUN_00469de0(...);
int FUN_00463000(...);
int FUN_0045f460(...);
int FUN_004ad640(...);
int FUN_0049a040(...);
int FUN_004f7e60(...);
int FUN_00524c10(...);
int FUN_00522310(...);
int FUN_005f9eb0(...);
int FUN_005fa1a0(...);
int FUN_0062c720(...);
int FUN_004e7b10(...);
int FUN_004d0dd0(...);
int FUN_005539d0(...);
int FUN_005253b0(...);
extern void* LAB_00648c4d;
extern int DAT_006ff960;
int FUN_00644f60(...);

// CRT function references
void CRTFree(void* ptr);
void* CrtAlignedMalloc(size_t alignment, size_t size);

// Ghidra math intrinsics

// ─── CRT Heap Free (FUN_00643505) — PASS ────────────────────────
// CRT internal free() path. Called 652 times across the binary.
// This is the standard MSVC CRT free() with heap validation.
// See also: StringUtils.cpp which documents the _invoke_watson path.
void CRTFree(void* ptr);  // FUN_00643505

// ─── GetStartupShowCmd (FUN_0064458d) — PASS ────────────────────
// Returns the nCmdShow value from STARTUPINFOW for the process.
// If STARTF_USESHOWWINDOW is set, returns wShowWindow; otherwise 10 (SW_SHOWDEFAULT).
// Called from __scrt_common_main_seh to pass nCmdShow to WinMain.
WORD GetStartupShowCmd();  // FUN_0064458d

// ─── InitSqrtTables (FUN_00640030) — PASS ───────────────────────
// Precomputes two 32K-entry lookup tables for fast sqrt approximation.
// Fills DAT_006dd0a8 and DAT_006bd0a8 with IEEE 754 mantissa bits
// computed from sqrt((i|0x3f8000)<<8) and sqrt((i|0x400000)<<8).
// Called once during engine startup.
void InitSqrtTables();  // FUN_00640030

// ─── SetWndProc (FUN_00640160) — PASS ───────────────────────────
// Stores a function pointer into DAT_006fd0a8 (the registered WndProc).
// Trivial 1-line setter. Called from MainGameLoop init.
void SetWndProc(uint32_t wndProc);  // FUN_00640160

// ─── SetMemoryPool (FUN_006403f0) — PASS ────────────────────────
// Stores a memory pool pointer into DAT_006fd0ac.
// Trivial 1-line setter. Called from MainGameLoop init.
void SetMemoryPool(uint32_t pool);  // FUN_006403f0

// ─── DebugPrintf (FUN_00640a00) — PASS ──────────────────────────
// Formatted debug output via OutputDebugStringA.
// Writes to internal buffer (DAT_006fd0b0, size DAT_006fd1b0),
// calls OutputDebugStringA, optional callback (DAT_006fd1bc),
// and optional log file (DAT_006fd1c0 / DAT_006fd1c4).
// Called 15 times across the binary.
void DebugPrintf(const char* fmt, ...);  // FUN_00640a00

// ─── ThrowStringLengthError (FUN_00443110) ─────────────────────
// Throws std::length_error("string too long"). Called 29 times.
// MSVC std::string internal length-check helper.
// [[noreturn]]
[[noreturn]] void ThrowStringLengthError();  // FUN_00443110

// ─── AlignedNew (FUN_00443120) ────────────────────────────────
// 32-byte aligned operator new with overflow guard.
// If size==0, returns nullptr. If size < 0x1000, plain new.
// Otherwise allocates size+0x23, aligns to 32 bytes, stashes
// the original pointer at (aligned - 4) for AlignedDelete.
// Called 32 times.
void* AlignedNew(uint32_t size);  // FUN_00443120

// ─── CRTInitTerm (FUN_006438f8) ──────────────────────────────
// CRT _initterm equivalent: iterates a table of function pointers
// from start to end (exclusive), calling each non-null entry.
// Wrapped in SEH prolog/epilog for safety during CRT init.
// 70 callers, 3 callees.
void CRTInitTerm(void** begin, void** end, int count, void (**table)());  // FUN_006438f8

// ─── CRTFreeWrapper (FUN_00643c84) ──────────────────────────
// Trivial free() wrapper. 1 caller (CRT cleanup path).
void CRTFreeWrapper(void* ptr);  // FUN_00643c84

// ─── ComSmartPtrRelease (FUN_00430350) ──────────────────────────
// COM smart pointer Release: decrements refcount (thread-safe via LOCK),
// calls destructor when refcount hits 0, decrements weak ref, calls
// deallocator when weak ref hits 0.
// 249 callers — core COM lifecycle.
void ComSmartPtrRelease(int param_1);  // FUN_00430350

// ─── SsoStringClear (FUN_00443a10) ──────────────────────────────
// SSO string clear/truncate: if capacity > 15 (heap-allocated), frees
// the buffer via CRTFree. Then resets to SSO mode (capacity=15, size=0).
// 549 callers — extremely hot path.
void SsoStringClear(int* param_1);  // FUN_00443a10

// ─── VirtualDestructorCall (FUN_0042c100) ────────────────────────
// Calls object's vtable[0] destructor with arg=1 if object is non-null.
// 98 callers — standard COM-style destructor dispatch.
void VirtualDestructorCall(int* param_1);  // FUN_0042c100

// ─── ComReleaseQI (FUN_00431ae0) ────────────────────────────────
// Calls vtable[2] with arg=1 if object is non-null (COM Release variant).
// 43 callers — standard COM QI/Release pattern.
void ComReleaseQI(int* param_1);  // FUN_00431ae0

// ─── SecurityCheckCookie (FUN_006434f7) ─────────────────────────
// MSVC __security_check_cookie: validates stack cookie against global.
// If mismatch, calls __report_rangecheckfailure (FUN_00643a38).
// 1250 callers — injected by compiler /GS flag. Inlined in most contexts.
void SecurityCheckCookie(uintptr_t stackCookie);  // FUN_006434f7

// ─── ReportRangeCheckFailure (FUN_00643a38) ────────────────────
// MSVC __report_rangecheckfailure: called on stack cookie mismatch.
// Triggers fastfail (0x9) / terminate. [[noreturn]].
// 1 callee of SecurityCheckCookie.
[[noreturn]] void ReportRangeCheckFailure();  // FUN_00643a38

// ─── OperatorNew (FUN_00643513) ──────────────────────────────────
// MSVC operator new: malloc with new handler retry loop.
// Calls _callnewh on failure, retries if handler returns non-zero.
// Throws std::bad_alloc on exhaustion. 492 callers.
void* OperatorNew(uint32_t size);  // FUN_00643513

// ─── SsoWStringClear (FUN_00443490) ─────────────────────────────
// MSVC std::wstring clear/Tidy. Wide-char variant of SsoStringClear.
// If capacity > 7 (heap-allocated wstring): frees buffer via CRTFree.
// Then resets: length=0, capacity=7 (SSO), first wchar=0.
// 227 callers.
void SsoWStringClear(int* param_1);  // FUN_00443490

// ─── FreeBlock16 (FUN_004c5b00) ────────────────────────────────
// Frees a 16-byte aligned block if pointer is non-null.
// Trivial 2-line wrapper around CRTFree. 51 callers.
void FreeBlock16(int* ptr);  // FUN_004c5b00

// ─── CopyDataWithSize (FUN_0044d590) ───────────────────────────
// Copies/moves data with size-field dispatch. If sizeField==1, calls
// single-element copy. Otherwise iterates count times calling FUN_0044dc30.
// 51 callers — STL container data movement helper.
void* CopyDataWithSize(void* dest, int count, uint32_t src, int srcInfo);  // FUN_0044d590

// ─── SsoStringAssign (FUN_00443c70) ────────────────────────────
// SSO string assign/destroy wrapper. Calls FUN_00443a20(*param_1).
// Trivial 1-line function. 136 callers.
void SsoStringAssign(void* param_1);  // FUN_00443c70

// ─── SsoStringAssignThunk (FUN_0061f3c0) ──────────────────────
// Thunk of FUN_00443c70. Same as SsoStringAssign. 84 callers.
void SsoStringAssignThunk(void* param_1);  // FUN_0061f3c0

// ─── SsoWStringClearThunk (FUN_004434f0) ──────────────────────
// Thunk of FUN_00443490 (SsoWStringClear). Calls SsoWStringClear on *param_1.
// 103 callers — wide string cleanup wrapper.
void SsoWStringClearThunk(void* param_1);  // FUN_004434f0

// ─── NoOpReturn (FUN_0042d350) ─────────────────────────────────
// Empty function: just returns. Used as default/null COM method slot.
// 135 callers — vtable placeholder or default handler.
void NoOpReturn();  // FUN_0042d350

// ─── ThrowVectorTooLong (FUN_0042b750) ─────────────────────────
// Throws std::length_error("vector too long"). [[noreturn]].
// 71 callers — MSVC std::vector length guard.
[[noreturn]] void ThrowVectorTooLong();  // FUN_0042b750

// ─── IntToWideString (FUN_0044c960) ───────────────────────────
// Converts unsigned int to wide string using 2-char lookup table.
// Writes digits right-to-left into buffer. 50 callers.
uint16_t* IntToWideString(int buffer, uint32_t value, int endOffset);  // FUN_0044c960

// ─── BitvectorPushBack (FUN_0043d690) ─────────────────────────
// Appends bits to a dynamic bitvector (auto-grows when needed).
// param_1 = {data_ptr, bit_count}, param_2 = new bit value.
// 47 callers — MSVC std::vector<bool> push_back.
int* BitvectorPushBack(int* param_1, int param_2);  // FUN_0043d690

// ─── Atan2AngleCalc (FUN_006386b0) ────────────────────────────
// Computes atan2(y, x) * RAD_TO_DEG with (0,0)->0 special case.
// Uses x87 _CIatan2 internally. 45 callers.
float Atan2AngleCalc(float x, float y);  // FUN_006386b0

// ─── ByteVectorPushBack (FUN_00438950) ────────────────────────
// STL vector<uint8_t>::push_back with growth. Writes byte to end,
// grows buffer (1.5x) if full. Calls ThrowVectorTooLong at max size.
// 43 callers — MSVC std::vector<unsigned char>::push_back.
void ByteVectorPushBack(int* param_1, uint8_t* param_2);  // FUN_00438950

// ─── StringIterInit (FUN_004c8280) ───────────────────────────
// Initializes a string iterator/buffer with range and padding.
// Trivial 6-line setup. 43 callers.
void StringIterInit(uint32_t* param_1, int param_2, int* param_3, uint32_t param_4);  // FUN_004c8280

// ─── ExceptionDestroy (FUN_0043ca20) ─────────────────────────
// std::exception destructor: destroys two sub-exceptions and resets vtable.
// Trivial 6-line function. 40 callers.
void ExceptionDestroy(uint32_t* param_1);  // FUN_0043ca20

// ─── ContainerElementAdvance (FUN_004c8320) ──────────────────
// Advances container element by calling FUN_0044dc30 with offset.
// Trivial 3-line wrapper. 39 callers.
void ContainerElementAdvance(int param_1, int param_2);  // FUN_004c8320

// ─── TrivialConstruct (FUN_0043efb0) ─────────────────────────
// Trivial object construction, delegates to FUN_0043d010.
// 5-line function. 41 callers.
void TrivialConstruct(uint32_t* param_1, uint32_t param_2);  // FUN_0043efb0

// ─── VectorTidy (FUN_0042b010) ───────────────────────────────
// STL vector tidy/destroy: frees buffer with debug heap check,
// resets begin/end/capacity to null. 46 callers.
void VectorTidy(int* param_1);  // FUN_0042b010

// ─── StringCopyConstruct (FUN_004431a0) ──────────────────────
// MSVC std::string copy constructor. SSO-aware: copies inline
// for size < 16, allocates heap otherwise. 75 callers, 3 callees.
void* StringCopyConstruct(void* dst, const void* src);  // FUN_004431a0

// ─── StringCaseCompare (FUN_00632970) ────────────────────────
// Case-insensitive string compare via _strnicmp. Returns true if equal.
// Trivial 8-line function. 37 callers.
bool StringCaseCompare(char* param_1, char* param_2);  // FUN_00632970

// ─── SsoStringAppend (FUN_00442880) ───────────────────────────
// MSVC std::string::append. SSO-aware: grows buffer with 1.5x strategy
// if capacity insufficient. Appends param_2 (data) of param_3 bytes.
// 63 callers, 6 callees.
void* SsoStringAppend(void* strObj, const void* data, uint32_t len);  // FUN_00442880

// ─── SsoStringPushBack (FUN_004429e0) ─────────────────────────
// MSVC std::string::push_back. SSO-aware single-char append.
// Grows buffer with 1.5x strategy if full. 57 callers, 5 callees.
void SsoStringPushBack(void* strObj, uint8_t ch);  // FUN_004429e0

// ─── SsoStringAssignBuf (FUN_0043cb70) ────────────────────────
// MSVC std::string::assign from external buffer. SSO-aware: replaces
// contents with param_2 of param_3 bytes. 57 callers, 6 callees.
void* SsoStringAssignBuf(void* strObj, const void* data, uint32_t len);  // FUN_0043cb70

// ─── TaskCompletionFinalize (FUN_0061d960) ────────────────────
// Concurrency Runtime task completion: resets context callback,
// releases two COM-like objects with ref-counted destruction.
// 73 callers, 2 callees.
void TaskCompletionFinalize(int taskImpl);  // FUN_0061d960

// ─── SinFloat (FUN_0063fee0) ──────────────────────────────────
// sinf() wrapper: converts float to double, calls SSE2 sin, returns float.
// Trivial 3-line function. 36 callers, 1 callee.
float SinFloat(float angle);  // FUN_0063fee0

// ─── CxxThrowException (FUN_00644875) ──────────────────────────
// Thunk to _CxxThrowException. Trivial CRT wrapper. 124 callers.
[[noreturn]] void CxxThrowException(void* exception, void* throwInfo);  // FUN_00644875

// ─── MemMove (FUN_0064487b) ──────────────────────────────────
// Thunk to memmove. Trivial CRT wrapper. 104 callers.
void* MemMove(void* dest, const void* src, size_t count);  // FUN_0064487b

// ─── FloorFloat (FUN_0064593f) ──────────────────────────────────
// Thunk to floor(). Trivial CRT wrapper. 56 callers.
double FloorFloat(double x);  // FUN_0064593f

// ─── CrtMemcpy (FUN_006435a7) ──────────────────────────────────
// CRT memcpy wrapper with security cookie check. 38 callers.
void* CrtMemcpy(void* dest, const void* src, size_t count);  // FUN_006435a7

// ─── CrtMemset (FUN_006435f8) ──────────────────────────────────
// CRT memset wrapper with security cookie check. 38 callers.
void* CrtMemset(void* dest, int value, size_t count);  // FUN_006435f8

// ─── CrtSEHHandler (FUN_0064389d) ──────────────────────────────
// CRT SEH exception handler registration (__EH_prolog/__register).
// Sets up structured exception handling for a function. 42 callers.
void CrtSEHHandler(void* handler);  // FUN_0064389d

// ─── TaskSetResult (FUN_0061d950) ──────────────────────────────
// Concurrency Runtime task set result: stores value and signals completion.
// Trivial 3-line function. 36 callers, 1 callee.
void TaskSetResult(int taskImpl);  // FUN_0061d950

// ─── StringResize (FUN_00442f40) ──────────────────────────────
// MSVC std::string::resize. SSO-aware: grows buffer if needed,
// null-terminates. 36 callers, 1 callee (ThrowStringLengthError).
void StringResize(int* strObj, uint32_t newSize);  // FUN_00442f40

// ─── AllDiv (FUN_006454e0) ──────────────────────────────────
// CRT __alldiv: 64-bit integer division (software emulate on x86).
// 48 callers, pure assembly routine.
int64_t AllDiv(int64_t dividend, int64_t divisor);  // FUN_006454e0

// ─── TaskContextAlloc (FUN_0061dbf0) ──────────────────────────
// Concurrency Runtime: allocates a task continuation context from
// thread-local storage, increments refcount on the context object.
// 43 callers, 2 callees.
void* TaskContextAlloc(void* param_1);  // FUN_0061dbf0

// ─── VectorAssign (FUN_0061d7b0) ──────────────────────────────
// STL vector<T>::assign with growth. Handles circular buffer case
// where data wraps around end. Grows with 1.5x strategy.
// 34 callers, 5 callees.
void VectorAssign(int* vecObj, void* data, uint32_t count);  // FUN_0061d7b0

// ─── VectorDeallocate (FUN_0042b2c0) ─────────────────────────
// STL vector destructor: calls FUN_0042b650 for element cleanup,
// then frees buffer via CRTFree. Resets begin/end/capacity to 0.
// 33 callers, 3 callees.
void VectorDeallocate(int* vecObj);  // FUN_0042b2c0

// ─── AngleWrap (FUN_00638870) ────────────────────────────────
// Wraps angle to [0, max) range using fmod. Handles negative
// values by adding max. 33 callers, 1 callee (fmod).
float AngleWrap(float value, float max);  // FUN_00638870

// ─── Distance3D (FUN_00638c80) ───────────────────────────────
// Computes 3D Euclidean distance: sqrt((x2-x1)² + (y2-y1)² + (z2-z1)²).
// 33 callers, 1 callee (sqrt).
float Distance3D(float* p1, float* p2);  // FUN_00638c80

// ─── AllMul (FUN_00645670) ───────────────────────────────────
// CRT __allmul: 64-bit integer multiplication (x86 software).
// 29 callers, pure assembly routine.
int64_t AllMul(int64_t a, int64_t b);  // FUN_00645670

// ─── CeilFloat (FUN_006448bd) ────────────────────────────────
// Thunk to ceil(). Trivial CRT wrapper. 28 callers.
double CeilFloat(double x);  // FUN_006448bd

// ─── StringCopyAssign (FUN_00443070) ─────────────────────────
// MSVC std::string copy assignment with SSO. Copies rhs to lhs,
// handles SSO inline vs heap buffer cases. 31 callers, 3 callees.
void* StringCopyAssign(void* dst, const void* src);  // FUN_00443070

// ─── ObjectDeallocate (FUN_00480d00) ─────────────────────────
// Frees a heap-allocated object with security cookie validation.
// 31 callers, 1 callee (free).
void ObjectDeallocate(int ptr);  // FUN_00480d00

// ─── StringPushBackChar (FUN_004409f0) ───────────────────────
// MSVC std::string::push_back(char) with SSO-aware growth.
// 29 callers, 5 callees.
void* StringPushBackChar(void* strObj, char ch);  // FUN_004409f0

// ─── ThrowAfterLog (FUN_0061d2a0) ────────────────────────────
// Logs error then throws C++ exception. [[noreturn]].
// Calls FUN_0061d250(param_1) then _CxxThrowException.
// 28 callers, 2 callees. Concurrency Runtime error handler.
[[noreturn]] void ThrowAfterLog(uint32_t errorCode);  // FUN_0061d2a0

// ─── CopyIteratorRange (FUN_004bbe90) ────────────────────────
// Copies elements from iterator range [param_2, param_3) into container param_4.
// Auto-grows container if needed via callback. Returns updated container.
// 27 callers, 0 callees (callback via param_4 vtable).
uint32_t* CopyIteratorRange(uint32_t* out, uint16_t* begin, uint16_t* end, uint32_t* container);  // FUN_004bbe90

// ─── CondFreeField (FUN_00435e40) ────────────────────────────
// Conditional free: if *(param_1+4) != 0, calls CRTFree with it.
// Simple 3-line destructor pattern. 26 callers, 1 callee.
void CondFreeField(int param_1);  // FUN_00435e40

// ─── InitWithCallback (FUN_0061f830) ─────────────────────────
// Initializes object with callback, sets self-reference at +0x10 and flag at +0x14.
// 25 callers, 1 callee. Concurrency Runtime context init.
int InitWithCallback(int thisPtr, uint32_t param_2, uint32_t param_3);  // FUN_0061f830

// ─── FreeThunk (FUN_00643574) ────────────────────────────────
// CRT free() import thunk. Single JMP instruction. 24 callers.
void FreeThunk(void* ptr);  // FUN_00643574

// ─── NoOpReturnZero (FUN_0042d7a0) ───────────────────────────
// Returns 0. Default/null vtable handler. 23 callers.
uint32_t NoOpReturnZero();  // FUN_0042d7a0

// ─── StringTableLookup (FUN_004e9ab0) ────────────────────────
// Searches a packed string table (DAT_00747d3c) for case-insensitive
// match. Returns associated 4-byte value or -1 if not found.
// 26 callers, 1 callee (_stricmp).
uint32_t StringTableLookup(const char* name);  // FUN_004e9ab0

// ─── BoundsCheckDispatch (FUN_0056cd80) ──────────────────────
// If index < 0 or index >= count(+0x328), calls error handler.
// Otherwise copies 12 bytes from object (+0xf0) to output param.
// 24 callers, 1 callee (FUN_005fac30).
void BoundsCheckDispatch(int obj, int index, uint64_t* output);  // FUN_0056cd80

// ─── CosF (FUN_0063ff00) ──────────────────────
// Thin wrapper around SSE2 cosf(). 20 callers, 1 callee (libm).
float CosF(float angle);  // FUN_0063ff00

// ─── AcosF (FUN_00487440) ──────────────────────
// Thin wrapper around SSE2 acosf(). 20 callers, 1 callee (libm).
float AcosF(float value);  // FUN_00487440

// ─── CheckedCloseHandle (FUN_006411c5) ─────────────────
// CloseHandle with abort on failure. Skips INVALID_HANDLE_VALUE.
// 20 callers, 2 callees (CloseHandle, abort).
void CheckedCloseHandle(void* handle);  // FUN_006411c5

// ─── VectorFreeRaw (FUN_00430380) ──────────────────────
// Frees a raw vector (begin/end/capacity triple). Validates debug
// heap header if > 0xFFF bytes, then calls FUN_00643505 (free).
// 21 callers, 2 callees (FUN_00643505, _invoke_watson).
void VectorFreeRaw(int* vecHeader);  // FUN_00430380

// ─── VectorFreeWithDtor (FUN_0042c810) ─────────────────
// Frees a vector of pointers, calling dtor(this,1) on each non-null
// entry, then frees the buffer (same pattern as VectorFreeRaw).
// 21 callers, 2 callees (FUN_00643505, _invoke_watson).
void VectorFreeWithDtor(int* vecHeader);  // FUN_0042c810

// ─── WStringAssign (FUN_004bdd60) ──────────────────────
// Assigns a wide string (wchar_t*) of length param_3 to an SSO string.
// Small strings (< 8 wchars) stored inline, large ones heap-allocated.
// 20 callers, 3 callees (FUN_00443110, FUN_00443010, memcpy).
void WStringAssign(uint32_t* dest, const void* src, uint32_t count);  // FUN_004bdd60

// ─── MutexUnlock (FUN_004712e0) ────────────────────────
// Thin wrapper around _Mtx_unlock(). 19 callers, 1 callee.
void MutexUnlock(uint32_t* mutex);  // FUN_004712e0

// ─── RTTILookupType (FUN_0042bc40) ────────────────────
// MSVC CRT __RTtypeid-style lookup. Walks a type_info table (param_1+0xc
// to param_1+0x10) searching for hash 0x8C70E003. If found, returns
// piVar3[1] (the type_info data). If not found, allocates 0x4C bytes,
// initializes a new type_info vtable, and delegates to FUN_0042aca0.
// 19 callers, 3 callees (operator_new, FUN_0042aca0, vtable dtor).
int RTTILookupType(int param_1);  // FUN_0042bc40

// ─── TrivialGetter (FUN_0043eb70) ──────────────────────
// Returns *param_1. Trivial accessor, 18 callers, 0 callees.
uint32_t TrivialGetter(uint32_t* param_1);  // FUN_0043eb70

// ─── VectorClear18 (FUN_00441d00) ─────────────────────
// Clears a vector of 0x18-byte elements. Calls dtor on each element,
// then frees the buffer with debug heap validation.
// 18 callers, callees: FUN_004439b0 (element dtor), FUN_00643505 (free).
void VectorClear18(int* vecHeader);  // FUN_00441d00

// ─── TrivialRedirect (FUN_0043cd50) ────────────────────
// Single-line wrapper that calls FUN_0042b1f0(). 18 callers, 1 callee.
void TrivialRedirect();  // FUN_0043cd50

// ─── SseSqrt (FUN_006448b7) ──────────────────────────────
// libm_sse2_sqrt_precise: SSE2 hardware sqrtf. 17 callers, 0 callees.
float SseSqrt(float x);  // FUN_006448b7

// ─── NewWrapper (FUN_0064356b) ──────────────────────────
// Trivial wrapper around operator new. 16 callers, 1 callee.
void* NewWrapper(uint32_t size);  // FUN_0064356b

// ─── PowWrapper (FUN_004542b0) ──────────────────────────
// Trivial wrapper around libm_sse2_pow_precise. 16 callers, 1 callee.
float PowWrapper(float base, float exp);  // FUN_004542b0

// ─── VectorReserveAligned (FUN_00437e00) ──────────────
// STL vector::reserve with 32-byte aligned allocation.
// Grows to param_2 elements. Uses aligned new for large allocations.
// 16 callers, 5 callees (operator_new, ThrowVectorTooLong, etc).
void VectorReserveAligned(int* vecObj, uint32_t count, uint32_t param3);  // FUN_00437e00

// ─── VectorInsert (FUN_0042c4e0) ──────────────────────
// STL vector::insert at position. Grows with 1.5x strategy.
// Validates size < max, handles reallocation with element copy.
// 17 callers, 5 callees.
uint32_t* VectorInsert(int* vecObj, uint32_t* pos, uint32_t* val);  // FUN_0042c4e0

// ─── InitVtable669dd8 (FUN_0061cc70) ──────────────────
// Trivial: sets *param_1 = vtable ptr 0x00669dd8. 13 callers, 0 callees.
void InitVtable669dd8(uint32_t* obj);  // FUN_0061cc70

// ─── JsonTypeName (FUN_0043fc70) ──────────────────────
// Returns type name string for JSON type byte: "null","object","array",
// "string","boolean","number","binary","discarded". 12 callers, 0 callees.
const char* JsonTypeName(uint8_t typeByte);  // FUN_0043fc70

// ─── GuardCheckICall (FUN_0042cb50) ───────────────────
// MSVC __guard_check_icall_fptr: CFG dispatch validation.
// 14 callers, 0 callees. Stub: no-op on MinGW.
void GuardCheckICall(uint32_t target);  // FUN_0042cb50

// ─── CrtMemchr (FUN_00644881) ─────────────────────────
// CRT memchr import thunk. 13 callers, 0 callees.
void* CrtMemchr(const void* ptr, int value, size_t num);  // FUN_00644881

// ─── CondFree8 (FUN_0044fd20) ──────────────────────────
// If param_2 != 0, calls CRTFree(param_1). Trivial conditional free.
// 13 callers, 1 callee.
void CondFree8(uint32_t ptr, char flag);  // FUN_0044fd20

// ─── CondFree24 (FUN_004c7db0) ─────────────────────────
// If *param_1 != 0, calls CRTFree(*param_1). Trivial conditional free.
// 12 callers, 1 callee.
void CondFree24(int* ptrRef);  // FUN_004c7db0

// ─── AcosF2 (FUN_0063ff20) ────────────────────────────
// Thin wrapper around libm_sse2_acos_precise. 12 callers, 1 callee.
float AcosF2(float value);  // FUN_0063ff20

// ─── Redirect81900 (FUN_00481930) ──────────────────────
// Trivial redirect to FUN_00481900(param_1, &stack, param_1). 14 callers.
void Redirect81900(uint32_t param_1);  // FUN_00481930

// ─── TreeIteratorInc (FUN_00443560) ──────────────────────
// MSVC std::_Tree_unchecked_const_iterator::operator++.
// Advances tree iterator to next node (in-order traversal).
// 13 callers, 0 callees (self-contained).
void TreeIteratorInc(uint32_t* iter);  // FUN_00443560

// ─── SsoWStringDestroy (FUN_0044dc90) ───────────────────
// MSVC std::wstring destructor. Sets vtable, frees heap buffer
// (capacity > 0xFFF → debug heap check). 14 callers, 2 callees.
void SsoWStringDestroy(uint32_t* strObj);  // FUN_0044dc90

// ─── VectorAllocAligned (FUN_004435c0) ──────────────────
// STL aligned allocator: allocates count*16 bytes. Uses aligned new
// for large allocations (> 4KB). 14 callers, 3 callees.
void VectorAllocAligned(uint32_t param_1, uint32_t* count);  // FUN_004435c0

// ─── ThrowAfterReplay (FUN_00462fa0) ────────────────────
// Calls FUN_00462ed0(param_1) then throws C++ exception. [[noreturn]].
// 12 callers, 2 callees (FUN_00462ed0, _CxxThrowException).
[[noreturn]] void ThrowAfterReplay(uint32_t param_1);  // FUN_00462fa0

// ─── TaskContextInit (FUN_0061f480) ─────────────────────
// Concurrency Runtime task context init: allocates 0x18 byte block,
// initializes fields, sets up exception handling. 12 callers, 2 callees.
void TaskContextInit(uint32_t* param_1, char* param_2);  // FUN_0061f480

// ─── VectorCopyConstruct (FUN_0061d390) ─────────────────
// STL vector copy constructor: copies source vector elements to new vector.
// Allocates new buffer, copies elements, sets begin/end/capacity.
// 12 callers, 3 callees.
uint32_t* VectorCopyConstruct(uint32_t* dest, uint32_t* src);  // FUN_0061d390

// ─── Distance2D (FUN_00638ba0) ──────────────────────────
// Computes 2D Euclidean distance: sqrt((x2-x1)^2 + (y2-y1)^2).
// Self-contained math function. 11 callers, 1 callee (sqrt).
float Distance2D(float* p1, float* p2);  // FUN_00638ba0

// ─── TaskCopyAssign (FUN_0061cc80) ─────────────────────
// Concurrency Runtime task copy/assign: deep copies task data with
// ref-counted allocation. Handles exception propagation.
// 13 callers, 4 callees.
void TaskCopyAssign(uint32_t* dest, uint32_t* src);  // FUN_0061cc80

// ─── MemcmpFast (FUN_0043b1e0) ──────────────────────────
// Fast memory compare with 4-byte stride then byte fallback.
// Compares min(param_2, param_4) bytes. Returns 0 if equal.
// 11 callers, 0 callees (self-contained).
uint32_t MemcmpFast(uint8_t* a, uint32_t lenA, uint8_t* b, uint32_t lenB);  // FUN_0043b1e0

// ─── FillRangeZero (FUN_00438830) ───────────────────────
// Fills range [param_1, param_2) with 0 via param_3 as output iterator.
// Trivial 8-line STL uninitialized_fill with zero. 11 callers, 0 callees.
void FillRangeZero(uint32_t* begin, uint32_t* end, uint32_t* out);  // FUN_00438830

// ─── VectorFreeThunk (FUN_00430670) ─────────────────────
// Thunk of FUN_0042b1f0: frees vector buffer with debug heap validation.
// 11 callers, 0 callees (inlines the free logic).
void VectorFreeThunk(int* vecHeader);  // FUN_00430670

// ─── StreambufSync (FUN_00431290) ───────────────────────
// std::streambuf sync/flush: calls virtual sync() on streambuf.
// Handles exception propagation via SEH. 11 callers, 4 callees.
void StreambufSync(void* streambuf);  // FUN_00431290

// ─── TaskCreateWithArgs (FUN_0061c180) ──────────────────
// Concurrency Runtime task creation with arguments and scheduler.
// Allocates task context, sets up continuation. 10 callers, 3 callees.
uint64_t* TaskCreateWithArgs(uint32_t* param_1, int param_2, uint32_t param_3,
                             int* param_4, uint32_t param_5);  // FUN_0061c180

// ─── SsoStringReplace (FUN_00441b90) ────────────────────
// MSVC std::string::replace with SSO. Replaces substring with new content.
// Handles growth and buffer reallocation. 10 callers, 4 callees.
uint32_t SsoStringReplace(uint32_t* strObj, int* params);  // FUN_00441b90

// ─── Atan2Single (FUN_0063fff0) ──────────────────────────
// Thin wrapper around x87 _CIatan2. Returns float.
// 10 callers, 1 callee.
float Atan2Single(uint32_t param_1, float param_2);  // FUN_0063fff0

// ─── CrtAcosPrecise (FUN_006448cf) ───────────────────────
// libm_sse2_acos_precise: SSE2 hardware acos. Trampoline to CRT.
// 10 callers, 0 callees. Stub: delegates to std::acos.
float CrtAcosPrecise(float x);  // FUN_006448cf

// ─── VectorClear16 (FUN_00443620) ────────────────────────
// Clears vector of 0x10-byte elements. Calls dtor on each element
// via FUN_00443c70, then frees buffer. 10 callers, 3 callees.
void VectorClear16(int param_1);  // FUN_00443620

// ─── ContainerAssign (FUN_004c8340) ─────────────────────
// STL container assign: copies elements from source with SEH protection.
// Handles buffer growth and element construction. 10 callers, 1 callee.
void ContainerAssign(int* param_1);  // FUN_004c8340

// ─── TaskInvoke (FUN_0061d160) ──────────────────────────
// Concurrency Runtime task invocation: checks completion flag at +8,
// calls wrapped function via vtable. SEH-protected. 10 callers, 2 callees.
void TaskInvoke(int param_1);  // FUN_0061d160

// ─── AllocaProbe (FUN_00643f40) ──────────────────────────
// MSVC __chkstk/__alloca_probe: stack allocation probe.
// Touches pages to commit stack memory. 10 callers, 0 callees.
void AllocaProbe();  // FUN_00643f40

// ─── Trig data (single source of truth — embedded real data, TrigTables.cpp) ──
// Used by SinTableLookup / FastSinTable / MathUtils SinCosLookup. NOT the
// original's hardcoded addresses (invalid in the recomp layout).
#include <cstdint>
extern const uint32_t kSinTable[16384];
extern const uint32_t kCosTable[16384];

// ─── SinTableLookup (FUN_006387b0) ──────────────────────
// Fast sine from precomputed 16K table. RADIANS input; scale = 16384/2π.
// 10 callers, 0 callees. Validated via proxy active detour (0 mismatch).
float SinTableLookup(float angle);  // FUN_006387b0

// ─── TrivialOffset8 (FUN_0043eb60) ──────────────────────
// Returns param_1 + 8. Trivial iterator advance. 10 callers, 0 callees.
int TrivialOffset8(int param_1);  // FUN_0043eb60

// ─── ReadField4 (FUN_0043e7e0) ──────────────────────────
// Reads *(param_1+4) into *param_2. Trivial getter. 10 callers, 0 callees.
void ReadField4(int param_1, uint32_t* param_2);  // FUN_0043e7e0

// ─── IntEqual (FUN_0043e410) ────────────────────────────
// Returns *param_1 == *param_2. Trivial comparison. 10 callers, 0 callees.
bool IntEqual(int* param_1, int* param_2);  // FUN_0043e410

// ─── ExpPrecise (FUN_00645933) ──────────────────────────
// libm_sse2_exp_precise: SSE2 expf. Cannot decompile (too many branches).
// 9 callers, 0 callees. Stub: delegates to std::exp.
float ExpPrecise(float x);  // FUN_00645933

// ─── StructZeroInit (FUN_00617120) ──────────────────────
// Zero-initializes 18-field struct (0x48 bytes). Sets field[3]=2, field[0xd]=-1.
// 9 callers, 0 callees (self-contained).
uint32_t* StructZeroInit(uint32_t* param_1);  // FUN_00617120

// ─── ComReleasePtr (FUN_0061daf0) ──────────────────────
// COM Release on *param_1: decrements refcount (thread-safe), calls dtor
// at vtable[1] when refcount hits 1. Then nulls *param_1.
// 9 callers, 0 callees (self-contained).
void ComReleasePtr(int* param_1);  // FUN_0061daf0

// ─── Aullshr (FUN_006457c0) ──────────────────────────
// CRT __aullshr: 64-bit unsigned right shift (x86 software).
// 8 callers, 0 callees. Stub: delegates to compiler builtin.
uint64_t Aullshr(uint64_t value, uint8_t shift);  // FUN_006457c0

// ─── CIfmod (FUN_006448c9) ───────────────────────────
// CRT _CIfmod: x87 fmod. 7 callers, 0 callees.
double CIfmod(double x, double y);  // FUN_006448c9

// ─── MatrixLoad4x4 (FUN_0063f300) ────────────────────
// Loads 4x4 matrix from DAT_0067d198 into output. 16 float copy.
// 8 callers, 0 callees (self-contained).
void MatrixLoad4x4(float* out, float* src);  // FUN_0063f300

// ─── BigNumCompare (FUN_004cea00) ───────────────────
// Compares two big numbers. Returns -1/0/1 based on magnitude.
// 8 callers, 0 callees (self-contained).
int BigNumCompare(uint32_t* a, uint32_t* b);  // FUN_004cea00

// ─── ThrowMapSetTooLong (FUN_0043b2d0) ───────────────────
// Throws std::length_error("map/set too long"). [[noreturn]].
// 6 callers, 1 callee (std::_Xlength_error). MSVC STL guard.
[[noreturn]] void ThrowMapSetTooLong();  // FUN_0043b2d0

// ─── DclassCheck (FUN_0043af70) ───────────────────
// Calls dclass() and returns result < 1. CRT classification check.
// 6 callers, 1 callee (dclass). Stub: delegates to fpclassify.
bool DclassCheck();  // FUN_0043af70

// ─── CondFreeField10 (FUN_00440f00) ───────────────────
// If *(param_1+4) != 0, calls CRTFree with it. Trivial conditional free.
// 6 callers, 1 callee (CRTFree).
void CondFreeField10(int param_1);  // FUN_00440f00

// ─── FmtTypeSpecifier (FUN_00447a80) ───────────────────
// fmt v9 format type specifier parser. Builds uint64 descriptor from
// format spec bytes. 6 callers, 1 callee (throw_format_error).
uint64_t FmtTypeSpecifier(int param_1);  // FUN_00447a80

// ─── RedirectPow (FUN_00454270) ───────────────────
// Trivial redirect to FUN_00454240(param_1, &stack, param_1). 6 callers.
void RedirectPow(uint32_t param_1);  // FUN_00454270

// ─── CrtCIatan2 (FUN_0048acc0) ───────────────────
// x87 _CIatan2 wrapper. Returns float result. 6 callers, 1 callee.
float CrtCIatan2(float y, float x);  // FUN_0048acc0

// ─── FmtValidateWidth (FUN_004b6f50) ───────────────────
// fmt v9 width validator. Switch on type: validates non-negative,
// checks overflow. Throws format_error on invalid. 6 callers, 1 callee.
uint32_t FmtValidateWidth(uint32_t param_1, uint32_t param_2, int param_3, uint32_t param_4);  // FUN_004b6f50

// ─── FmtValidatePrecision (FUN_004b73a0) ───────────────────
// fmt v9 precision validator. Same pattern as FmtValidateWidth but for precision.
// 6 callers, 1 callee.
uint32_t FmtValidatePrecision(uint32_t param_1, uint32_t param_2, int param_3, uint32_t param_4);  // FUN_004b73a0

// ─── StringCopyConstructWrapper (FUN_004c0400) ───────────────────
// Calls FUN_004431a0 (StringCopyConstruct) on param_2, returns param_1.
// Trivial 2-line wrapper. 6 callers, 1 callee.
uint32_t StringCopyConstructWrapper(uint32_t param_1, uint32_t param_2);  // FUN_004c0400

// ─── CondFree28 (FUN_004c2f90) ───────────────────
// If *(param_1+4) != 0, calls CRTFree(ptr, 0x28). Trivial conditional free.
// 6 callers, 1 callee.
void CondFree28(int param_1);  // FUN_004c2f90

// ─── CondFree10flag (FUN_004c5a20) ───────────────────
// If (param_2 & 1), calls CRTFree(param_1, 0x10). Trivial conditional free.
// 6 callers, 1 callee.
uint32_t CondFree10flag(uint32_t param_1, uint8_t param_2);  // FUN_004c5a20

// ─── SinPrecise (FUN_006448db) ───────────────────
// libm_sse2_sin_precise: SSE2 hardware sinf. Cannot decompile (assembly).
// 6 callers, 0 callees. Stub: delegates to std::sin.
float SinPrecise(float x);  // FUN_006448db

// ─── OperatorDelete (FUN_006438e6) ───────────────────
// CRT operator delete. Calls free via CRTFree. 6 callers, 1 callee.
void OperatorDelete(void* ptr);  // FUN_006438e6

// ─── LinkedListDestroyNodes (FUN_004d0080) ───────────────────
// Destroys linked list nodes: walks list, calls vtable[0] dtor on sub-object,
// frees each 0x10-byte node. 6 callers, 1 callee.
void LinkedListDestroyNodes(uint32_t param_1, uint32_t* head);  // FUN_004d0080

// ─── TaskReleaseRef (FUN_0061d410) ───────────────────
// Concurrency Runtime task release: gets value from FUN_0042b1f0, then
// decrements COM refcount on param_1+8. Calls vtable dtors when ref=0.
// 6 callers, 1 callee.
int TaskReleaseRef(int param_1);  // FUN_0061d410

// ─── ContextCallbackReset (FUN_0061db90) ───────────────────
// Concurrency Runtime _ContextCallback::_Reset wrapper.
// Trivial 3-line function. 6 callers, 1 callee.
void ContextCallbackReset(void* param_1);  // FUN_0061db90

// ─── StringCompareLess (FUN_00637050) ───────────────────
// Compares two SSO strings using FUN_0043b1e0 (MemcmpFast).
// Returns 0 if equal, -1/1 for less/greater. 6 callers, 1 callee.
uint8_t StringCompareLess(uint32_t* str1, uint32_t* str2);  // FUN_00637050

// ─── LinkedListDestroy24 (FUN_004303e0) ───────────────────
// Destroys linked list of 0x18-byte nodes. Walks list, calls FUN_004382f0
// per node, frees via CRTFree. 6 callers, 2 callees.
void LinkedListDestroy24(int* head);  // FUN_004303e0

// ─── JsonThrowOnValue (FUN_0043cd10) ───────────────────
// JSON value type check: sets flag at +0x14, throws if +0x15 is set.
// Calls FUN_0043d3b0 then _CxxThrowException. 6 callers, 2 callees.
uint32_t JsonThrowOnValue(int param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4);  // FUN_0043cd10

// ─── JsonThrowOnType (FUN_0043d3e0) ───────────────────
// JSON type check variant: sets flag at +0x34, throws if +0x60 is set.
// Same pattern as JsonThrowOnValue but different offsets. 6 callers, 2 callees.
uint32_t JsonThrowOnType(int param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4);  // FUN_0043d3e0

// ─── WStringAppend (FUN_004405c0) ───────────────────
// MSVC std::wstring::append. SSO-aware: memmove wchars, null-terminates.
// Grows via FUN_00440480 if capacity insufficient. 6 callers, 2 callees.
uint32_t* WStringAppend(uint32_t* strObj, void* data, uint32_t count);  // FUN_004405c0

// ─── StringConcat (FUN_00441620) ───────────────────
// MSVC std::string concatenation: creates new string from two sources.
// Allocates via AlignedNew if combined size > 15. 6 callers, 2 callees.
uint32_t* StringConcat(uint32_t* dest, uint32_t p2, uint32_t p3, void* data1, size_t len1,
                       void* data2, size_t len2);  // FUN_00441620

// ─── FmtWriteInt (FUN_00447b70) ───────────────────
// fmt v9 integer formatting with sign/padding. Writes formatted int to buffer.
// 6 callers, 2 callees.
uint32_t* FmtWriteInt(uint32_t* out, char sign, uint32_t* buf, int spec,
                      uint32_t width, uint32_t type, uint32_t prec, uint32_t flags);  // FUN_00447b70

// ─── FmtWriteFloat (FUN_00447c90) ───────────────────
// fmt v9 float formatting via snprintf. Writes formatted float to buffer.
// Handles precision, alternate form, buffer growth. 6 callers, 2 callees.
uint32_t FmtWriteFloat(int precision, uint32_t* buf, uint32_t spec, uint32_t flags);  // FUN_00447c90

// ─── FmtWriteWideInt (FUN_004ba420) ───────────────────
// fmt v9 wide-char integer formatting. Similar to FmtWriteInt but for wchar_t output.
// 6 callers, 2 callees.
uint32_t* FmtWriteWideInt(uint32_t* out, char sign, uint32_t* buf, int spec,
                          uint32_t width, uint32_t type, uint32_t prec,
                          int16_t fill, uint32_t flags, char altForm);  // FUN_004ba420

// ─── LinkedListDestroy36 (FUN_004c3b90) ───────────────────
// Destroys linked list of 0x24-byte nodes. Walks list, calls FUN_004439b0
// per node (element dtor), frees via CRTFree. 6 callers, 2 callees.
void LinkedListDestroy36(int* head);  // FUN_004c3b90

// ─── ThrowAfterCopy (FUN_004ca990) ───────────────────
// Calls FUN_004ca6d0(param_1, param_2) then throws C++ exception.
// [[noreturn]]. 6 callers, 2 callees.
[[noreturn]] void ThrowAfterCopy(uint32_t param_1, uint32_t param_2);  // FUN_004ca990

// ─── FmtFormatAndThrow (FUN_0042fe20) ───────────────────
// fmt v9: formats a string then calls FUN_0043f440(6,4,...) to throw.
// Security cookie, SSO string extraction. 6 callers, 4 callees.
void FmtFormatAndThrow(uint32_t fmt_str, uint32_t fmt_args, uint32_t* args_obj);  // FUN_0042fe20

// ─── VectorDealloc56 (FUN_0043e2c0) ───────────────────
// Deallocates a vector of 0x38-byte elements. Calls FUN_0043e270 to destroy
// elements, then CRTFree. Zeroes all 3 pointers after free. 6 callers, 3 callees.
void VectorDealloc56(int* vecHeader);  // FUN_0043e2c0

// ─── JsonGetValue (FUN_00440c00) ───────────────────
// JSON value getter: checks type byte at *param_1. Returns string pointer
// based on type (0=null→throw, 1=inline, 2=pointer, 3=error). 6 callers, 4 callees.
char* JsonGetValue(uint32_t* param_1);  // FUN_00440c00

// ─── StringConcatAssign (FUN_00441340) ───────────────────
// MSVC std::string concat-assign: concatenates two SSO strings into dest.
// Handles SSO inline vs heap, moves larger source. 6 callers, 4 callees.
uint32_t* StringConcatAssign(uint32_t* dest, uint32_t p2, uint32_t* src1, uint32_t* src2);  // FUN_00441340

// ─── ThrowOutOfRange (FUN_00442730) ───────────────────
// Gets error info via FUN_00442720, formats with FUN_00442470, then throws
// C++ exception with ThrowInfo at DAT_0067810c. [[noreturn]]. 6 callers, 3 callees.
[[noreturn]] void ThrowOutOfRange();  // FUN_00442730

// ─── EntityBufferFree (FUN_00482fb0) ───────────────────
// Frees up to 8 entity buffer pointers from struct at offsets +0x90, +0x5c,
// +0x50, +0x44, +0x20, +0x14, +0x8, +0x38. Decrements refcount at DAT_00701a3c+0x370.
// 6 callers, 3 callees.
void EntityBufferFree(int param_1);  // FUN_00482fb0

// ─── FmtThousandsSepInit (FUN_004bad20) ───────────────────
// fmt v9 thousands separator wstring init. Calls thousands_sep_impl<wchar_t>,
// copies SSO string result, handles cleanup. 6 callers, 3 callees.
uint32_t* FmtThousandsSepInit(uint32_t* dest, uint32_t param_2, char param_3);  // FUN_004bad20

// ─── ThrowFormatError (FUN_004c0ce0) ───────────────────
// Calls FUN_00442b00 (format error init) + FUN_004c0cb0, then throws
// C++ exception with ThrowInfo at DAT_006782cc. [[noreturn]]. 6 callers, 3 callees.
[[noreturn]] void ThrowFormatError();  // FUN_004c0ce0

// ─── PathStringConcat (FUN_00557ac0) ───────────────────
// Concatenates two SSO wstrings with path separator handling.
// Checks for drive letter (A-Z), leading slash/backslash, appends separator.
// 6 callers, 4 callees.
uint32_t* PathStringConcat(uint32_t* dest, uint32_t* path1, uint32_t* path2);  // FUN_00557ac0

// ─── EntitySlotClear16 (FUN_0057ed20) ───────────────────
// Clears 16 entity slots (0x1C stride) starting at entity+0x34, then
// processes animation state via FUN_004a67b0. Similar to EntitySlotInit.
// 6 callers, 3 callees.
void EntitySlotClear16(int param_1);  // FUN_0057ed20

// ─── HashMapInsert (FUN_0042b0f0) ───────────────────
// Inserts value into hash map: computes bucket via FUN_0042b330, stores
// index, grows vector if full (1.5x growth, max 0x3FFFFFFF). 6 callers, 5 callees.
void HashMapInsert(int thisPtr, uint32_t key);  // FUN_0042b0f0

// ─── Zero-callee 5-caller stubs (batch 38) ────────────────

// SmartPtrReleaseRange (FUN_00437c20) — Releases smart pointers in range [param_1..param_2).
// Walks at stride 0x38, calls vtable+0x10 on each. 5 callers, 0 callees.
void SmartPtrReleaseRange(uint32_t* start, uint32_t* end);  // FUN_00437c20

// VariantInit (FUN_00438f60) — Initializes VARIANT from string. Type 0=bool(1), 1=long, 2=double.
// 5 callers, 0 callees.
uint32_t* VariantInit(char* src, uint32_t* dest);  // FUN_00438f60

// FmtStoreInt64 (FUN_0043a160) — Stores int64 value with type=6. 5 callers, 0 callees.
void FmtStoreInt64(uint8_t* dest, uint32_t* src);  // FUN_0043a160

// FmtStoreUInt32 (FUN_0043a610) — Stores uint32 value with type=5. 5 callers, 0 callees.
void FmtStoreUInt32(uint8_t* dest, uint32_t* src);  // FUN_0043a610

// FmtStoreUInt64 (FUN_0043acd0) — Stores uint64 value with type=7. 5 callers, 0 callees.
void FmtStoreUInt64(uint8_t* dest, uint64_t* src);  // FUN_0043acd0

// GetUint32 (FUN_0043e420) — Returns *param_1. Trivial getter. 5 callers, 0 callees.
uint32_t GetUint32(uint32_t* param_1, uint32_t* param_2);  // FUN_0043e420

// IsEven (FUN_0043e430) — Returns 1 if *param_1 is even, 0 if odd. 5 callers, 0 callees.
uint32_t IsEven(uint32_t* param_1);  // FUN_0043e430

// ReturnFalse (FUN_0043e610) — Returns 0. Stub for virtual dispatch. 5 callers, 0 callees.
uint8_t ReturnFalse();  // FUN_0043e610

// FNV1aHash32 (FUN_0043e620) — FNV-1a 32-bit hash of 4 bytes. 5 callers, 0 callees.
uint32_t FNV1aHash32(uint8_t* data);  // FUN_0043e620

// Identity (FUN_0043e660) — Returns param_1 unchanged. 5 callers, 0 callees.
uint32_t Identity(uint32_t param_1);  // FUN_0043e660

// SwapPair (FUN_0043eb80) — Swaps two pairs of uint32. 5 callers, 0 callees.
void SwapPair(uint32_t* a, uint32_t* b);  // FUN_0043eb80

// BitFieldAnd (FUN_0043f000) — Returns *(param_1+4) & param_2. 5 callers, 0 callees.
uint32_t BitFieldAnd(int param_1, uint32_t param_2);  // FUN_0043f000

// ZeroStruct64 (FUN_00450a80) — Zeros 17 uint32 (68 bytes). 5 callers, 0 callees.
uint32_t* ZeroStruct64(uint32_t* param_1);  // FUN_00450a80

// EntityMoveStep (FUN_00461970) — Moves entity one step with velocity blending.
// Updates position at +0xF0 and velocity. 5 callers, 0 callees.
void EntityMoveStep(int param_1, float* time, float* dir);  // FUN_00461970

// ScrollAccumulate (FUN_0047bda0) — Accumulates scroll delta with integer snap.
// Updates +0xC/+0x10 from float params. 5 callers, 0 callees.
void ScrollAccumulate(int param_1, float* pos, uint32_t flags);  // FUN_0047bda0

// FindLastActiveEntity (FUN_0047c980) — Walks entity list backwards, returns first with flag 0x8000000. 5 callers, 0 callees.
int FindLastActiveEntity();  // FUN_0047c980

// EntityRenderSetup (FUN_0047d8f0) — Sets entity render state from params. 5 callers, 0 callees.
void EntityRenderSetup(uint32_t p1, uint32_t p2, uint32_t* p3, uint32_t p4);  // FUN_0047d8f0

// ArrayGetFloat (FUN_0048aca0) — Returns float at base[index*stride]. 5 callers, 0 callees.
float ArrayGetFloat(int* arr, int index);  // FUN_0048aca0

// WideStrHash (FUN_004b7040) — FNV-like hash over wchar_t string. 5 callers, 0 callees.
uint32_t WideStrHash(uint32_t* str, uint16_t* end, uint32_t seed);  // FUN_004b7040

// EntityCollisionCheck (FUN_005077d0) — Checks if entity can collide with target.
// Validates type, flags, team. 5 callers, 0 callees.
uint8_t EntityCollisionCheck(int self, int target, uint32_t flags);  // FUN_005077d0

// EntityFindByAddr (FUN_0055a860) — Linear search in entity array by address. 5 callers, 0 callees.
int* EntityFindByAddr(int addr);  // FUN_0055a860

// PathfindCheck (FUN_00564e00) — Grid pathfind validity check with switch on direction.
// 5 callers, 0 callees.
uint8_t PathfindCheck(int x, int y, int z, uint32_t dir, int* p5, int* p6, int* p7);  // FUN_00564e00

// EntityCanAttack (FUN_005aac30) — Checks if entity can attack based on health ratio and state.
// 5 callers, 0 callees.
uint32_t EntityCanAttack(int param_1);  // FUN_005aac30

// EntityCopyRenderState (FUN_005ab630) — Copies 12 uint32 from DAT_007028f4 to entity data. 5 callers, 0 callees.
void EntityCopyRenderState(int param_1, int param_2);  // FUN_005ab630

// SsoStringCopy17 (FUN_0060e010) — Copies 17-field SSO string (memcpy + assign). 5 callers, 0 callees.
uint32_t* SsoStringCopy17(uint32_t* dest, uint32_t* src);  // FUN_0060e010

// SsoStringMove17 (FUN_0060e0a0) — Moves 17-field SSO string, clears source. 5 callers, 0 callees.
uint32_t* SsoStringMove17(uint32_t* dest, uint32_t* src);  // FUN_0060e0a0

// DateTimeCompare (FUN_00621960) — Compares two datetime structs, swaps if out of order. 5 callers, 0 callees.
void DateTimeCompare(uint32_t* a, uint32_t* b, uint32_t* out);  // FUN_00621960

// QuaternionToMatrix (FUN_0063eaa0) — Converts quaternion to 4x4 rotation matrix. 5 callers, 0 callees.
void QuaternionToMatrix(uint32_t* matrix, float* quat);  // FUN_0063eaa0

// MatrixLoadIdentity (FUN_0063ed60) — Loads 4x4 identity matrix from globals. 5 callers, 0 callees.
void MatrixLoadIdentity(uint32_t* matrix, float* unused);  // FUN_0063ed60

// ─── 1-callee 5-caller stubs (batch 39) ────────────────────────

// ReturnTrue (FUN_006447ac) — Returns 1. Virtual dispatch stub. 5 callers, 0 callees.
uint8_t ReturnTrue();  // FUN_006447ac

// ExceptionDestroy (FUN_0042b9c0) — Sets vtable to std::exception, destroys inner. 5 callers, 1 callee.
void ExceptionDestroy(uint32_t* param_1);  // FUN_0042b9c0

// StringInitFromPtr (FUN_00431980) — Inits string from pointer with length calc. 5 callers, 1 callee.
uint32_t StringInitFromPtr(uint32_t dest, uint32_t* src, uint32_t param_3);  // FUN_00431980

// LoopDestroy18 (FUN_00438800) — Walks range at stride 0x18, destroys each. 5 callers, 1 callee.
void LoopDestroy18(int* param_1);  // FUN_00438800

// Wrapper39250 (FUN_00439290) — Trivial wrapper calling FUN_00439250. 5 callers, 1 callee.
void Wrapper39250(uint32_t param_1, uint32_t param_2, uint32_t param_3);  // FUN_00439290

// StringLenInit (FUN_0044f0c0) — strlen then call FUN_0043cb70. 5 callers, 1 callee.
void StringLenInit(char* param_1);  // FUN_0044f0c0

// Free24 (FUN_005e8c90) — Frees 0x24 bytes at *(param+4). 5 callers, 1 callee.
void Free24(int param_1);  // FUN_005e8c90

// TaskLogComplete (FUN_0061a270) — CRT Concurrency task completion log. 5 callers, 1 callee.
void TaskLogComplete(uint32_t* param_1);  // FUN_0061a270

// ExceptionRethrow (FUN_0061d0f0) — CRT __ExceptionPtrRethrow wrapper. 5 callers, 1 callee.
void ExceptionRethrow();  // FUN_0061d0f0

// Call443490 (FUN_00621e20) — Trivial wrapper calling FUN_00443490. 5 callers, 1 callee.
void Call443490();  // FUN_00621e20

// SharedPtrRelease (FUN_006176e0) — Shared pointer release with SEH. 5 callers, 1 callee.
uint32_t SharedPtrRelease(int param_1, uint32_t* param_2);  // FUN_006176e0

// RandomRange (FUN_0046e5c0) — XOR-shift PRNG returning value in [param_2..param_3]. 5 callers, 1 callee.
int RandomRange(int param_1, int param_2, int param_3);  // FUN_0046e5c0

// SortByDistance3 (FUN_005231e0) — Sorts 3 entity pointers by distance to DAT_0074bb60. 5 callers, 1 callee.
void SortByDistance3(int* a, int* b, int* c);  // FUN_005231e0

// EventCreate (FUN_004e95a0) — Creates timed event at DAT_00702124. 5 callers, 1 callee.
int* EventCreate(int param_1, int param_2, float param_3);  // FUN_004e95a0

// EntityFlagUpdate (FUN_004ea2b0) — Updates entity flags, clears 0x400000 bit. 5 callers, 1 callee.
void EntityFlagUpdate(int param_1);  // FUN_004ea2b0

// StringTableLookup (FUN_0056ea70) — Looks up string in table at DAT_00749908. 5 callers, 1 callee.
uint32_t StringTableLookup(int param_1);  // FUN_0056ea70

// ─── 2-callee 5-caller stubs (batch 40) ────────────────────────

// FormatV9 (FUN_0042fda0) — fmt::v9::vformat wrapper. 5 callers, 2 callees.
uint32_t FormatV9(uint32_t p1, uint32_t* p2, uint32_t p3, uint32_t p4);  // FUN_0042fda0

// LinkedListFree16 (FUN_0046eac0) — Frees linked list nodes at stride 0x10. 5 callers, 2 callees.
void LinkedListFree16(int param_1);  // FUN_0046eac0

// FileBufferFill (FUN_004908a0) — Fills file read buffer via ReadFile. 5 callers, 2 callees.
void FileBufferFill();  // FUN_004908a0

// PathParseTrim (FUN_004bde00) — Trims path separators, extracts filename. 5 callers, 2 callees.
uint32_t* PathParseTrim(uint32_t* param_1, uint32_t* param_2);  // FUN_004bde00

// RenderStateInit (FUN_004cffd0) — Inits render state with sentinel node. 5 callers, 2 callees.
uint32_t* RenderStateInit(uint32_t* param_1);  // FUN_004cffd0

// RandomWarmup (FUN_00508c90) — Warms up PRNG with 3x3 rand calls. 5 callers, 2 callees.
void RandomWarmup();  // FUN_00508c90

// ThrowException (FUN_00601100) — CRT throw wrapper. 5 callers, 2 callees.
void ThrowException(uint32_t param_1);  // FUN_00601100

// SocketClose (FUN_00630ce0) — Closes socket/connection object. 5 callers, 2 callees.
uint32_t SocketClose(void* param_1);  // FUN_00630ce0

// MatrixLoadFromGlobals (FUN_0063ec00) — Loads 4x4 matrix from globals at 0x67d198. 5 callers, 2 callees.
void MatrixLoadFromGlobals(uint32_t* param_1, uint32_t param_2);  // FUN_0063ec00

// DirectoryIteratorClose (FUN_00641596) — CRT FindClose wrapper. 5 callers, 2 callees.
void DirectoryIteratorClose(void* handle);  // FUN_00641596

// MissionCheatToggle (FUN_00563c50) — Toggles MissionCheat registry value. 5 callers, 2 callees.
void MissionCheatToggle();  // FUN_00563c50

// EntityDispatchByType (FUN_005adef0) — Dispatches entity by type 0x4A/0x2C. 5 callers, 2 callees.
uint32_t EntityDispatchByType(int param_1, int param_2);  // FUN_005adef0

// ModelRendererQuery (FUN_005d8260) — Queries model renderer with string compare. 5 callers, 2 callees.
uint32_t ModelRendererQuery(int p1, int p2, int p3, int p4);  // FUN_005d8260

// ─── 3-callee 5-caller stubs (batch 41) ────────────────────────

// MapEmplaceThrow (FUN_0042acf0) — Map emplace with exception on missing key. 5 callers, 3 callees.
int MapEmplaceThrow(int param_1);  // FUN_0042acf0

// VectorAllocAlignedB (FUN_0042b940) — Allocates aligned vector buffer (×4), variant B. 5 callers, 3 callees.
void VectorAllocAlignedB(uint32_t param_1, uint32_t* param_2);  // FUN_0042b940

// MapFindOrThrow (FUN_00430430) — Finds map entry or throws. 5 callers, 3 callees.
uint32_t MapFindOrThrow(uint32_t param_1, uint32_t param_2);  // FUN_00430430

// VectorAllocAligned2 (FUN_00438700) — Second variant of aligned vector alloc. 5 callers, 3 callees.
void VectorAllocAligned2(uint32_t param_1);  // FUN_00438700

// MapEmplaceThrow2 (FUN_00451620) — Map emplace with different error code. 5 callers, 3 callees.
int MapEmplaceThrow2(int param_1);  // FUN_00451620

// UICallback (FUN_00456b40) — UI callback dispatcher with game state checks. 5 callers, 3 callees.
void UICallback(uint32_t param_1);  // FUN_00456b40

// VectorFree200 (FUN_00462490) — Frees vector with stride 200 (0xC8). 5 callers, 3 callees.
void VectorFree200(int* param_1);  // FUN_00462490

// VectorFree3C (FUN_00462510) — Frees vector with stride 0x3C, destroys elements. 5 callers, 3 callees.
void VectorFree3C(int* param_1);  // FUN_00462510

// EntityCountDecrement (FUN_0047b9c0) — Decrements entity count, updates flags. 5 callers, 3 callees.
void EntityCountDecrement();  // FUN_0047b9c0

// NetworkBufferProcess (FUN_0047fe80) — Processes network buffer with resize. 5 callers, 3 callees.
void NetworkBufferProcess(uint32_t param_1);  // FUN_0047fe80

// WideStringArrayResize (FUN_004812a0) — Resizes wchar_t array with alloc+copy. 5 callers, 3 callees.
void WideStringArrayResize(int* param_1, int param_2);  // FUN_004812a0

// EntitySlotClear (FUN_00496c30) — Clears entity slots except param_2, sets flag 0x8000. 5 callers, 3 callees.
uint32_t EntitySlotClear(int param_1, uint32_t param_2);  // FUN_00496c30

// VectorFree148 (FUN_004c2a20) — Frees vector with stride 0x148. 5 callers, 3 callees.
void VectorFree148(int* param_1);  // FUN_004c2a20

// LinkedStrAssign (FUN_004d3fb0) — Assigns string to linked list node by key. 5 callers, 3 callees.
void LinkedStrAssign(int* param_1, int param_2, char* param_3);  // FUN_004d3fb0

// EntityDamageApply (FUN_00507ea0) — Applies damage to entity, updates health. 5 callers, 3 callees.
void EntityDamageApply(uint32_t param_1, int param_2, int param_3);  // FUN_00507ea0

// CameraInterpolate (FUN_0055e950) — Camera keyframe interpolation with 6 float params. 5 callers, 3 callees.
int CameraInterpolate(float* p1, float* p2, float* p3, float* p4, float* p5, float* p6);  // FUN_0055e950

// EntitySlotClear8 (FUN_00580230) — Clears entity slots from offset 8, sets 0x8000 flag. 5 callers, 3 callees.
uint32_t EntitySlotClear8(int param_1, uint32_t param_2);  // FUN_00580230

// GridCeilCompute (FUN_005fd610) — Computes ceil(grid/step) for mesh grid. 5 callers, 3 callees.
void GridCeilCompute(int param_1);  // FUN_005fd610

// TreeMapIterate (FUN_00640800) — Iterates tree map with callback. 5 callers, 3 callees.
void TreeMapIterate(int param_1);  // FUN_00640800

// ─── Zero-callee 4-caller stubs (batch 42) ────────────────────

// VariantCopy4 (FUN_00433040) — Copies 4-field variant struct. 4 callers, 0 callees.
uint32_t* VariantCopy4(uint32_t* dest, uint32_t* src);  // FUN_00433040

// Int64DivMod (FUN_00435d00) — 64-bit division with mod using long division. 4 callers, 0 callees.
int Int64DivMod(uint32_t param_1, uint32_t param_2);  // FUN_00435d00

// VariantCopy3 (FUN_00437910) — Copies 3-field variant struct. 4 callers, 0 callees.
uint32_t* VariantCopy3(uint32_t* dest, uint32_t* src);  // FUN_00437910

// JsonTypeName (FUN_00439190) — Returns JSON type name string by index. 4 callers, 0 callees.
const char* JsonTypeName(uint32_t typeIndex);  // FUN_00439190

// StringInsert (FUN_0043b300) — Inserts string at position in container. 4 callers, 0 callees.
int* StringInsert(int* dest, int* src, int pos, int* result);  // FUN_0043b300

// ThunkVectorDtor (FUN_004485d0) — Thunk for vector destructor (FUN_004489f0). 4 callers, 0 callees.
void ThunkVectorDtor(uint32_t* param_1);  // FUN_004485d0

// EntityClassCompare (FUN_004491d0) — Compares two entities by class offset. 4 callers, 0 callees.
int EntityClassCompare(int a, int b);  // FUN_004491d0

// VtableDispatch8 (FUN_00462060) — Dispatches via vtable+8 with param. 4 callers, 0 callees.
int* VtableDispatch8(uint32_t param_1);  // FUN_00462060

// ThunkVectorFree200 (FUN_004622a0) — Thunk for VectorFree200 (FUN_00462490). 4 callers, 0 callees.
void ThunkVectorFree200(int* param_1);  // FUN_004622a0

// VtableCall0 (FUN_00470070) — Calls vtable[0] from object at +0xC with arg 0. 4 callers, 0 callees.
void VtableCall0(int param_1);  // FUN_00470070

// TeamSetCheck (FUN_00473f90) — Sets team ID and dirty flag in game state. 4 callers, 0 callees.
void TeamSetCheck(int param_1, uint32_t param_2);  // FUN_00473f90

// EntityWalk (FUN_004910e0) — Walks entity hierarchy with null checks. 4 callers, 0 callees.
void EntityWalk(int param_1);  // FUN_004910e0

// VtableDispatch8B (FUN_004bebd0) — Dispatches via vtable+8 variant B. 4 callers, 0 callees.
int* VtableDispatch8B(uint32_t param_1);  // FUN_004bebd0

// Int64Sub (FUN_004cea40) — 64-bit subtraction with borrow. 4 callers, 0 callees.
int* Int64Sub(int* result, uint32_t* a, uint32_t* b);  // FUN_004cea40

// NetworkMsgDecode (FUN_004e0e30) — Decodes network message from byte buffer. 4 callers, 0 callees.
void NetworkMsgDecode(int param_1, int param_2, int param_3);  // FUN_004e0e30

// TerrainIntersect (FUN_004e2880) — Ray-terrain intersection test. 4 callers, 0 callees.
int TerrainIntersect(float* param_1, int param_2, float* param_3, int param_4);  // FUN_004e2880

// EntityTargetSet (FUN_004ffdb0) — Sets entity target position from data. 4 callers, 0 callees.
void EntityTargetSet(int param_1, int* param_2);  // FUN_004ffdb0

// EntityCanUseAbility (FUN_005025c0) — Checks if entity type 2 can use ability. 4 callers, 0 callees.
bool EntityCanUseAbility(int param_1, int param_2);  // FUN_005025c0

// TripleSwap (FUN_0053efa0) — Swaps 3-field struct contents. 4 callers, 0 callees.
uint32_t* TripleSwap(uint32_t* dest, uint32_t* src);  // FUN_0053efa0

// GridCoordFromWorld (FUN_00563ee0) — Converts world coords to grid coords. 4 callers, 0 callees.
void GridCoordFromWorld(float* worldPos, int* gridX, int* gridY, char* out);  // FUN_00563ee0

// EntityVelocityCopy (FUN_0056ce30) — Copies velocity from +0xF0 to +0xFC, zeroes fields. 4 callers, 0 callees.
void EntityVelocityCopy(int param_1);  // FUN_0056ce30

// EntityCreate (FUN_00581ab0) — Creates entity in slot from params. 4 callers, 0 callees.
void EntityCreate(int param_1, uint32_t param_2, int param_3);  // FUN_00581ab0

// StrEqual (FUN_00632900) — PROVEN equivalent (proxy self-test, 0 mismatch).
// String EQUALITY (true iff equal). Was mis-named StrLessThan from a Ghidra
// artifact; proxy oracle corrected the semantics. 4 callers, 0 callees.
bool StrEqual(const uint8_t* p1, const uint8_t* p2);  // FUN_00632900

// MemMoveOverlap (FUN_006329d0) — memmove for overlapping regions. 4 callers, 0 callees.
void MemMoveOverlap(uint8_t* dest, int srcOff, int dstOff, int len);  // FUN_006329d0

// StringCopy (FUN_00635d70) — Copies string with vtable dispatch. 4 callers, 0 callees.
int* StringCopy(int* dest, int* src, uint8_t* data);  // FUN_00635d70

// MemCmp12 (FUN_00635f10) — Compares first 12 bytes of two buffers. 4 callers, 0 callees.
uint32_t MemCmp12(uint8_t* a, uint8_t* b);  // FUN_00635f10

// Skip: libm_sse2_cos_precise (FUN_006448e7) — CRT intrinsic, skip

// ─── One-callee 4-caller stubs (batch 43) ───────────────────

// MapIterLookup (FUN_00432060) — Iterator lookup into map, returns value+0xC. 4 callers, 1 callee.
int* MapIterLookup(uint32_t param_1);  // FUN_00432060

// FreeBuffer12 (FUN_004382d0) — Frees 0xC-byte buffer at *(param+4). 4 callers, 1 callee.
void FreeBuffer12(int param_1);  // FUN_004382d0

// StringInitAssign (FUN_0043acb0) — Inits string with assign, returns 1. 4 callers, 1 callee.
uint32_t StringInitAssign(uint32_t param_1);  // FUN_0043acb0

// ExceptionVtableSet (FUN_0043ca90) — Sets exception vtable after clearing. 4 callers, 1 callee.
uint32_t* ExceptionVtableSet(uint32_t* param_1, uint32_t param_2);  // FUN_0043ca90

// StringFromCharPtr (FUN_004415b0) — Constructs string from char* via FUN_00442880. 4 callers, 1 callee.
uint32_t* StringFromCharPtr(uint32_t* param_1, char* param_2);  // FUN_004415b0

// ExceptionCopyConstruct (FUN_00442420) — Copy-constructs exception with __std_exception_copy. 4 callers, 1 callee.
uint32_t* ExceptionCopyConstruct(uint32_t* param_1, uint32_t* param_2);  // FUN_00442420

// ErrorCategoryDtor (FUN_00444130) — Destructor for error_category, optional free. 4 callers, 1 callee.
uint32_t* ErrorCategoryDtor(uint32_t* param_1, uint8_t param_2);  // FUN_00444130

// FileClose (FUN_00454290) — Closes FILE* handle if non-null. 4 callers, 1 callee.
void FileClose(uint32_t* param_1);  // FUN_00454290

// MutexUnlockIfLocked (FUN_00462df0) — Unlocks mutex if locked flag set. 4 callers, 1 callee.
void MutexUnlockIfLocked(uint32_t* param_1);  // FUN_00462df0

// HashMapFind (FUN_0046ff60) — FNV-1a hash map lookup by 4-byte key. 4 callers, 1 callee.
uint32_t* HashMapFind(int param_1, uint32_t* param_2);  // FUN_0046ff60

// InitCall88a30 (FUN_00488a20) — Trivial wrapper calling FUN_00488a30. 4 callers, 1 callee.
void InitCall88a30();  // FUN_00488a20

// EntityFlagPropagate (FUN_00492000) — Propagates flag to entity matched by +0x104 field. 4 callers, 1 callee.
void EntityFlagPropagate();  // FUN_00492000

// EntityLODSelect (FUN_004d6df0) — Selects entity LOD level by distance. 4 callers, 1 callee.
int EntityLODSelect(int param_1, int param_2);  // FUN_004d6df0

// RenderIndexBuffer (FUN_004e06c0) — Renders indexed geometry via vtable dispatch. 4 callers, 1 callee.
void RenderIndexBuffer(uint32_t* param_1, int param_2);  // FUN_004e06c0

// EntityCollisionDispatch (FUN_00501010) — Entity collision with position validation. 4 callers, 1 callee.
void EntityCollisionDispatch(int param_1, int param_2, int param_3, uint32_t param_4, uint32_t param_5, uint32_t param_6);  // FUN_00501010

// EntityTargetClear (FUN_0055a110) — Clears 0x4000 flag, cascades to linked entities. 4 callers, 1 callee.
void EntityTargetClear(int param_1);  // FUN_0055a110

// EntityClone (FUN_0055bd60) — Clones entity with position and flags. 4 callers, 1 callee.
int EntityClone(int param_1, uint32_t param_2, uint32_t param_3);  // FUN_0055bd60

// Call4439b0Wrapper (FUN_00599600) — Trivial wrapper calling FUN_004439b0. 4 callers, 1 callee.
void Call4439b0Wrapper();  // FUN_00599600

// CameraPositionCopy (FUN_005c0540) — Copies camera position from active cam or DAT_00702770. 4 callers, 1 callee.
void CameraPositionCopy(int param_1);  // FUN_005c0540

// RaycastTerrain (FUN_005c55f0) — Raycasts along terrain with depth XOR. 4 callers, 1 callee.
uint32_t RaycastTerrain(float* param_1, float* param_2);  // FUN_005c55f0

// EntityVelocityReset (FUN_005ccdf0) — Resets velocity for entity type 10. 4 callers, 1 callee.
void EntityVelocityReset(int param_1);  // FUN_005ccdf0

// EntityTeamClear (FUN_005df7d0) — Clears team assignments, sets 0x8000 flags. 4 callers, 1 callee.
void EntityTeamClear(int param_1);  // FUN_005df7d0

// MasterServerError (FUN_00603200) — Logs unhandled exception for master server. 4 callers, 1 callee.
void MasterServerError(int* param_1);  // FUN_00603200

// AtomicIncrementLoad (FUN_0060db20) — Atomic load with increment, CAS loop. 4 callers, 1 callee.
uint32_t* AtomicIncrementLoad(uint32_t* param_1, uint32_t* param_2);  // FUN_0060db20

// Free30 (FUN_006173f0) — Frees 0x30-byte buffer at *param. 4 callers, 1 callee.
void Free30(int* param_1);  // FUN_006173f0

// TaskSchedulerDrain (FUN_0061b9a0) — Drains task scheduler queue. 4 callers, 1 callee.
void** TaskSchedulerDrain(int param_1);  // FUN_0061b9a0

// ExceptionPtrCopy (FUN_0061d8f0) — Copies exception pointer. 4 callers, 1 callee.
uint32_t* ExceptionPtrCopy(uint32_t* param_1, void* param_2);  // FUN_0061d8f0

// CRC32Compute (FUN_006326f0) — Computes CRC32 with reflected bit order. 4 callers, 1 callee.
uint32_t CRC32Compute(uint8_t* param_1, int param_2);  // FUN_006326f0

// BoundingSphereCompute (FUN_0063f3f0) — Computes bounding sphere from AABB. 4 callers, 1 callee.
void BoundingSphereCompute(float* param_1, int param_2);  // FUN_0063f3f0

// ─── Two-callee 4-caller stubs (batch 44) ───────────────────

// VectorReallocAssign (FUN_0042b8d0) — Frees old vector, reassigns pointers. 4 callers, 2 callees.
void VectorReallocAssign(int* param_1, int param_2, int param_3, int param_4);  // FUN_0042b8d0

// JsonEmitByte (FUN_00439ca0) — Emits JSON byte token with realloc. 4 callers, 2 callees.
uint32_t JsonEmitByte(uint32_t* param_1, uint8_t param_2);  // FUN_00439ca0

// Call42020Wrapper (FUN_00443440) — Trivial wrapper calling FUN_00442020. 4 callers, 2 callees.
void Call42020Wrapper();  // FUN_00443440

// BitVecAlloc (FUN_004472b0) — Allocates bit vector with alignment. 4 callers, 2 callees.
uint32_t* BitVecAlloc(uint32_t* param_1, uint32_t param_2, uint32_t param_3, uint32_t* param_4);  // FUN_004472b0

// Int128ShiftRight (FUN_00448a40) — 128-bit integer right shift. 4 callers, 2 callees.
uint64_t* Int128ShiftRight(int param_1, uint64_t* param_2, int param_3);  // FUN_00448a40

// EntitySortInsert (FUN_00449260) — Sorts entities by class and inserts. 4 callers, 2 callees.
int EntitySortInsert(uint32_t* param_1, int param_2);  // FUN_00449260

// BitVecLookup (FUN_0044b330) — Looks up value in bit vector. 4 callers, 2 callees.
uint32_t* BitVecLookup(uint32_t* param_1, uint32_t* param_2, uint32_t param_3, int param_4, uint32_t param_5);  // FUN_0044b330

// TreeDrain (FUN_0044ddf0) — Drains tree nodes with ref counting. 4 callers, 2 callees.
void TreeDrain(uint32_t param_1, int* param_2);  // FUN_0044ddf0

// VectorFree24 (FUN_00462170) — Frees vector with stride 0x18. 4 callers, 2 callees.
void VectorFree24(int* param_1);  // FUN_00462170

// FormatV9String (FUN_004625b0) — Formats string via fmt::v9::vformat. 4 callers, 2 callees.
uint32_t FormatV9String(uint32_t param_1, uint32_t* param_2, uint32_t* param_3, uint32_t* param_4, uint32_t param_5, uint32_t param_6);  // FUN_004625b0

// ChatMessageParse (FUN_00473020) — Parses chat message up to ## delimiter. 4 callers, 2 callees.
void ChatMessageParse(uint32_t param_1, uint32_t param_2, char* param_3, uint32_t param_4, uint32_t param_5, uint32_t param_6, uint32_t param_7);  // FUN_00473020

// ChatDisplay (FUN_0047ff30) — Displays chat with time-based visibility. 4 callers, 2 callees.
void ChatDisplay(int param_1, char* param_2, char* param_3);  // FUN_0047ff30

// BufferTripleFree (FUN_00483cb0) — Frees 3 buffer pairs with ref decrement. 4 callers, 2 callees.
void BufferTripleFree(uint32_t* param_1);  // FUN_00483cb0

// EntityInterpolate (FUN_0048b650) — Entity interpolation with position update. 4 callers, 2 callees.
void EntityInterpolate(uint32_t param_1, int param_2, uint32_t param_3, uint32_t param_4);  // FUN_0048b650

// EntityVisibilityCheck (FUN_004a6700) — Checks if entity at slot is visible. 4 callers, 2 callees.
uint32_t EntityVisibilityCheck(int param_1, int param_2);  // FUN_004a6700

// VectorFreeObj (FUN_004c45c0) — Frees vector object with vtable set. 4 callers, 2 callees.
void VectorFreeObj(int param_1);  // FUN_004c45c0

// ScoreFormatWrite (FUN_004f7160) — Formats score as 4-char string. 4 callers, 2 callees.
void ScoreFormatWrite(int param_1, uint32_t param_2, int param_3);  // FUN_004f7160

// RandomRead32 (FUN_005271a0) — Reads 4 bytes from random stream. 4 callers, 2 callees.
void RandomRead32(uint32_t* param_1);  // FUN_005271a0

// EntityPathPlan (FUN_00566270) — Plans entity movement path. 4 callers, 2 callees.
void EntityPathPlan(int param_1);  // FUN_00566270

// GridToWorldCheck (FUN_005c0e10) — Converts grid coords to world, checks for building. 4 callers, 2 callees.
uint32_t GridToWorldCheck(int param_1, int param_2, uint32_t param_3, uint32_t param_4, float* param_5);  // FUN_005c0e10

// EntityGuardSet (FUN_005ee510) — Sets guard entity with position check. 4 callers, 2 callees.
void EntityGuardSet(int param_1, int param_2);  // FUN_005ee510

// TreeMapDispose (FUN_006331c0) — Disposes tree map node with cleanup. 4 callers, 2 callees.
void TreeMapDispose(int param_1);  // FUN_006331c0

// PathExtMatch (FUN_00645290) — Case-insensitive path extension match. 4 callers, 2 callees.
bool PathExtMatch(int param_1, char* param_2);  // FUN_00645290

// ─── Three-callee 4-caller stubs (batch 45) ─────────────────

// MapIterAlloc (FUN_0042c270) — Allocates map iterator with exception handling. 4 callers, 3 callees.
int MapIterAlloc(int param_1);  // FUN_0042c270

// VectorFreeAndReassign18 (FUN_00438760) — Frees vector stride 0x18 elements, reassigns. 4 callers, 3 callees.
void VectorFreeAndReassign18(int* param_1, int param_2, int param_3, int param_4);  // FUN_00438760

// JsonPushToken (FUN_0043a060) — Pushes JSON token to writer. 4 callers, 3 callees.
int JsonPushToken(int* param_1, uint8_t* param_2);  // FUN_0043a060

// StringConstructRange (FUN_004414f0) — Constructs string from iterator range. 4 callers, 3 callees.
uint32_t* StringConstructRange(uint32_t* param_1, void* param_2, void* param_3);  // FUN_004414f0

// CameraEventDispatch (FUN_004651e0) — Dispatches camera event by game mode. 4 callers, 3 callees.
void CameraEventDispatch(int param_1);  // FUN_004651e0

// ArrayResize16 (FUN_00487340) — Resizes array of 16-byte elements with malloc+copy. 4 callers, 3 callees.
void ArrayResize16(int* param_1, int param_2);  // FUN_00487340

// NumberFormatPadded (FUN_004ca380) — Formats number with zero-padding. 4 callers, 3 callees.
void NumberFormatPadded(uint32_t param_1, uint32_t param_2, uint32_t* param_3);  // FUN_004ca380

// EntityFOVCheck (FUN_004feb50) — Field-of-view check between entities. 4 callers, 3 callees.
uint32_t EntityFOVCheck(int param_1, int param_2);  // FUN_004feb50

// EntityWeaponSlotScan (FUN_00502910) — Scans weapon slots for entity type 2. 4 callers, 3 callees.
int EntityWeaponSlotScan(int param_1, int param_2);  // FUN_00502910

// EntityRenderPose (FUN_00507b20) — Renders entity pose with bone transform. 4 callers, 3 callees.
void EntityRenderPose(int param_1, float* param_2, float param_3);  // FUN_00507b20

// EntityResetState (FUN_0051a670) — Resets entity state and animation. 4 callers, 3 callees.
void EntityResetState(int param_1);  // FUN_0051a670

// GameModeStart (FUN_00552a90) — Starts game mode, initializes player data. 4 callers, 3 callees.
void GameModeStart();  // FUN_00552a90

// EntityVelocityUpdate (FUN_0056c270) — Updates entity velocity from direction and scale. 4 callers, 3 callees.
void EntityVelocityUpdate(int param_1);  // FUN_0056c270

// EntityWeaponCycle (FUN_00581c70) — Cycles entity weapon slot up/down. 4 callers, 3 callees.
void EntityWeaponCycle(int param_1, int param_2);  // FUN_00581c70

// EntityAttackStart (FUN_005af580) — Starts entity attack with sound. 4 callers, 3 callees.
void EntityAttackStart(int param_1, int param_2, int param_3, int param_4);  // FUN_005af580

// QuatSlerp (FUN_00639a90) — Quaternion spherical linear interpolation. 4 callers, 3 callees.
void QuatSlerp(float* param_1, float* param_2, float* param_3);  // FUN_00639a90

// EventSignalAndWake (FUN_00643579) — Signals event with SRW lock and wakes all. 4 callers, 3 callees.
void EventSignalAndWake(uint32_t* param_1);  // FUN_00643579

// FutureStateDtor (FUN_00644df0) — Destroys future/promise state. 4 callers, 3 callees.
void FutureStateDtor(uint32_t* param_1);  // FUN_00644df0

// ──── Cycle 46: 4/5-callee 4-caller functions (25 functions) ────

// VectorGrowAndEmplace (FUN_00438510) — Vector growth with realloc. 4 callers, 5 callees.
int* VectorGrowAndEmplace(int* param_1, int* param_2);  // FUN_00438510

// JsonParseCompare (FUN_0043afa0) — JSON parser comparison. 4 callers, 4 callees.
void JsonParseCompare(int param_1, int param_2);  // FUN_0043afa0

// TreeDrain38 (FUN_00440d10) — Tree drain with stride 0x38. 4 callers, 4 callees.
void TreeDrain38(int param_1, int param_2, int param_3);  // FUN_00440d10

// ResourceStringLoad (FUN_00456f10) — Loads resource string. 4 callers, 5 callees.
void ResourceStringLoad(int param_1, int param_2, int param_3, int param_4, int param_5);  // FUN_00456f10

// NetworkPacketParse (FUN_004ba800) — Network packet parser. 4 callers, 4 callees.
void NetworkPacketParse(int param_1, int param_2, int param_3);  // FUN_004ba800

// BufferGrowAndAssign (FUN_004df9a0) — Buffer growth and assign. 4 callers, 5 callees.
void BufferGrowAndAssign(int param_1, int param_2, int param_3);  // FUN_004df9a0

// EntityGuardCheck (FUN_0053d780) — Guard entity check. 4 callers, 4 callees.
void EntityGuardCheck(int param_1, int param_2);  // FUN_0053d780

// GameFrameTickA (FUN_0054f9e0) — Game frame tick variant A. 4 callers, 5 callees.
void GameFrameTickA(int param_1, int param_2);  // FUN_0054f9e0

// GameFrameTickB (FUN_0054ffe0) — Game frame tick variant B. 4 callers, 5 callees.
void GameFrameTickB(int param_1, int param_2, int param_3);  // FUN_0054ffe0

// GameFrameTickC (FUN_005505f0) — Game frame tick variant C. 4 callers, 5 callees.
void GameFrameTickC(int param_1, int param_2, int param_3);  // FUN_005505f0

// EntityTeamFlagSet (FUN_00557420) — Sets team flags on entities. 4 callers, 5 callees.
void EntityTeamFlagSet(int param_1, int param_2);  // FUN_00557420

// EntityRenderDirection (FUN_00582f20) — Entity render with direction. 4 callers, 5 callees.
void EntityRenderDirection(int param_1, int param_2, int param_3);  // FUN_00582f20

// EntityNetSync (FUN_00584b70) — Entity network sync. 4 callers, 5 callees.
void EntityNetSync(int param_1, int param_2);  // FUN_00584b70

// VectorEmplaceSorted (FUN_005c52c0) — Sorted vector emplace with realloc. 4 callers, 5 callees.
int* VectorEmplaceSorted(int* param_1, int* param_2);  // FUN_005c52c0

// EntitySpawnInit (FUN_005d1cd0) — Spawns and initializes entity. 4 callers, 4 callees.
void EntitySpawnInit(int param_1, uint32_t param_2);  // FUN_005d1cd0

// EntityRenderVisibility (FUN_005dda10) — Entity render visibility check. 4 callers, 5 callees.
void EntityRenderVisibility(int param_1);  // FUN_005dda10

// FNVHashString (FUN_005e85e0) — FNV-1a hash of string. 4 callers, 5 callees.
uint32_t FNVHashString(uint32_t param_1, uint32_t param_2);  // FUN_005e85e0

// EntityNearestFind (FUN_005ea7b0) — Find nearest entity by distance. 4 callers, 5 callees.
void EntityNearestFind(int param_1);  // FUN_005ea7b0

// ExceptionCheckRethrow (FUN_006049c0) — Checks and rethrows exception. 4 callers, 4 callees.
void ExceptionCheckRethrow(int* param_1);  // FUN_006049c0

// ConditionVariableWait (FUN_006131f0) — Condition variable wait with mutex. 4 callers, 5 callees.
void ConditionVariableWait(int param_1, uint32_t param_2);  // FUN_006131f0

// RegEnumPlayerKey (FUN_0062ae90) — Registry enumerate player key. 4 callers, 4 callees.
int RegEnumPlayerKey(uint32_t* param_1, uint32_t param_2, char* param_3);  // FUN_0062ae90

// ThreadCreateNative (FUN_00630000) — Native thread create with params. 4 callers, 4 callees.
int ThreadCreateNative(int param_1, uint32_t* param_2, uint32_t* param_3,
                       int param_4, uint32_t param_5, int param_6,
                       uint32_t param_7, int param_8, uint32_t param_9);  // FUN_00630000

// ExceptionFilterSetup (FUN_00633cd0) — SEH exception filter setup. 4 callers, 5 callees.
int ExceptionFilterSetup(int param_1, int param_2, int param_3);  // FUN_00633cd0

// FileIdFromHandle (FUN_0064105f) — Get file ID from handle. 4 callers, 4 callees.
uint32_t FileIdFromHandle(void* param_1, uint32_t* param_2);  // FUN_0064105f

// AlignedAllocThrow (FUN_006438b2) — Aligned malloc with new-handler retry. 4 callers, 5 callees.
void AlignedAllocThrow(size_t param_1, size_t param_2);  // FUN_006438b2

// ──── Cycle 47: 6-9 callee 4-caller functions (20 functions) ────

// MasterServerSend (FUN_00603100) — Master server send with exception handling. 4 callers, 9 callees.
void MasterServerSend(uint32_t param_1);  // FUN_00603100

// RegSetTeamScoreLimit (FUN_004592e0) — Registry set TeamScoreLimit. 4 callers, 9 callees.
void RegSetTeamScoreLimit(int param_1);  // FUN_004592e0

// RegSetPlayerScoreLimit (FUN_004590d0) — Registry set PlayerScoreLimit. 4 callers, 9 callees.
void RegSetPlayerScoreLimit(int param_1);  // FUN_004590d0

// RegSetTimeLimit (FUN_00458e20) — Registry set time limit. 4 callers, 9 callees.
void RegSetTimeLimit(int param_1);  // FUN_00458e20

// RegSetPointsPerKill (FUN_004581b0) — Registry set PointsPerKill. 4 callers, 9 callees.
void RegSetPointsPerKill(int param_1);  // FUN_004581b0

// GameModeInit (FUN_00456ff0) — Game mode initialization. 4 callers, 9 callees.
void GameModeInit(uint32_t param_1);  // FUN_00456ff0

// GameModeReset (FUN_00550c20) — Game mode full reset. 4 callers, 8 callees.
void GameModeReset();  // FUN_00550c20

// EntityFrameUpdate (FUN_00549fd0) — Entity frame update. 4 callers, 8 callees.
void EntityFrameUpdate();  // FUN_00549fd0

// RegSetSmartieDifficulty (FUN_00458810) — Registry set SmartieDifficulty. 4 callers, 8 callees.
void RegSetSmartieDifficulty(uint32_t param_1);  // FUN_00458810

// RegSetMaxPlayers (FUN_00457a70) — Registry set MaxPlayers. 4 callers, 8 callees.
void RegSetMaxPlayers(uint32_t param_1);  // FUN_00457a70

// TerrainWaterUpdate (FUN_005bc510) — Terrain water update. 4 callers, 7 callees.
void TerrainWaterUpdate(int param_1, int param_2);  // FUN_005bc510

// EntityDataInit (FUN_004f5070) — Entity data initialization. 4 callers, 7 callees.
uint8_t* EntityDataInit(uint8_t* param_1, char param_2, uint32_t param_3, int param_4, int param_5);  // FUN_004f5070

// StringFormatBuild (FUN_004b43b0) — String format builder. 4 callers, 7 callees.
uint32_t* StringFormatBuild(uint32_t* param_1, int16_t* param_2, int param_3,
                            uint32_t param_4, uint32_t param_5, uint32_t* param_6);  // FUN_004b43b0

// RegSetVimpMeatDifficulty (FUN_00458c70) — Registry set VimpMeatDifficulty. 4 callers, 7 callees.
void RegSetVimpMeatDifficulty(uint32_t param_1);  // FUN_00458c70

// RegSetDamageTeammates (FUN_00457fe0) — Registry set DamageTeammates. 4 callers, 7 callees.
void RegSetDamageTeammates(int param_1);  // FUN_00457fe0

// MapTreeMerge (FUN_0043c840) — Map tree merge. 4 callers, 7 callees.
uint32_t* MapTreeMerge(uint32_t* param_1, uint32_t param_2, uint32_t* param_3);  // FUN_0043c840

// StringConcatAssign (FUN_0043b5d0) — String concatenate and assign. 4 callers, 7 callees.
uint32_t StringConcatAssign(int param_1, uint32_t param_2);  // FUN_0043b5d0

// MatrixBuildPerspective (FUN_005f99b0) — Build perspective matrix. 4 callers, 6 callees.
void MatrixBuildPerspective(uint64_t* param_1, float param_2);  // FUN_005f99b0

// UIMenuCreate (FUN_004cfe20) — UI menu creation. 4 callers, 6 callees.
uint32_t* UIMenuCreate(uint32_t* param_1, uint32_t p2, uint32_t p3, uint32_t p4,
                       uint32_t p5, uint32_t p6, uint32_t p7, uint32_t p8,
                       uint32_t p9, uint32_t p10, uint32_t p11, uint32_t p12,
                       uint32_t p13, uint32_t p14, uint32_t p15, uint32_t p16);  // FUN_004cfe20

// RegSetSessionName (FUN_00456d20) — Registry set session name. 4 callers, 6 callees.
void RegSetSessionName(char* param_1, int param_2);  // FUN_00456d20

// ──── Cycle 48: 10-13 callee 4-caller functions (16 functions) ────

// EntityRenderSetup (FUN_0054b970) — Entity render setup. 4 callers, 13 callees.
void EntityRenderSetup(int param_1);  // FUN_0054b970

// EntityWeaponUpdate (FUN_00548ae0) — Entity weapon update. 4 callers, 13 callees.
int EntityWeaponUpdate();  // FUN_00548ae0

// RenderScenePost (FUN_004ddc00) — Post-scene render pass. 4 callers, 13 callees.
void RenderScenePost();  // FUN_004ddc00

// EntityCollisionCheck (FUN_0049dd90) — Entity collision check. 4 callers, 13 callees.
void EntityCollisionCheck(int param_1);  // FUN_0049dd90

// RegSetGameSetting (FUN_00457220) — Registry set game setting. 4 callers, 12 callees.
void RegSetGameSetting(int param_1);  // FUN_00457220

// StringFormatWide (FUN_0044bdc0) — Wide string format. 4 callers, 12 callees.
uint32_t* StringFormatWide(uint32_t* param_1, uint32_t* param_2, uint32_t* param_3,
                           uint32_t param_4, uint32_t param_5, uint32_t param_6,
                           uint32_t param_7);  // FUN_0044bdc0

// StringParseFormat (FUN_0043be80) — String format parser. 4 callers, 12 callees.
uint32_t StringParseFormat(int param_1);  // FUN_0043be80

// EntityPathFollow (FUN_005cdab0) — Entity path follow. 4 callers, 11 callees.
void EntityPathFollow(int param_1, uint32_t param_2, int param_3);  // FUN_005cdab0

// TerrainCollisionCheck (FUN_005b1760) — Terrain collision check. 4 callers, 11 callees.
void TerrainCollisionCheck(int param_1, int param_2, int param_3, int param_4);  // FUN_005b1760

// NetworkEntitySpawn (FUN_00573fb0) — Network entity spawn. 4 callers, 11 callees.
uint32_t NetworkEntitySpawn(int param_1, int param_2, uint32_t param_3);  // FUN_00573fb0

// GameModeUpdate (FUN_0054e6d0) — Game mode update. 4 callers, 11 callees.
void GameModeUpdate();  // FUN_0054e6d0

// EntityAnimationUpdate (FUN_00536640) — Entity animation update. 4 callers, 11 callees.
void EntityAnimationUpdate(int param_1);  // FUN_00536640

// GameModeScoreCheck (FUN_005497f0) — Game mode score check. 4 callers, 10 callees.
void GameModeScoreCheck();  // FUN_005497f0

// UITextRender (FUN_004c4010) — UI text render. 4 callers, 10 callees.
void UITextRender(int param_1, uint32_t* param_2);  // FUN_004c4010

// StringFormatBuild2 (FUN_004b9910) — String format builder variant 2. 4 callers, 10 callees.
uint32_t* StringFormatBuild2(uint32_t* param_1, uint32_t* param_2, uint32_t* param_3,
                             uint32_t param_4, uint32_t* param_5, uint32_t* param_6);  // FUN_004b9910

// StringArraySort (FUN_004b3e50) — String array sort. 4 callers, 10 callees.
void**** StringArraySort(void**** param_1, char param_2);  // FUN_004b3e50

// ──── Cycle 48b: 14+ callee 4-caller functions (10 functions) ────

// EntityTeamAssign (FUN_00555140) — Entity team assignment. 4 callers, 19 callees.
void EntityTeamAssign(int param_1, int param_2);  // FUN_00555140

// GameModeProcessB (FUN_00546b20) — Game mode process B. 4 callers, 17 callees.
void GameModeProcessB();  // FUN_00546b20

// GameModeProcessA (FUN_00542df0) — Game mode process A. 4 callers, 17 callees.
void GameModeProcessA();  // FUN_00542df0

// EntitySpawnWave (FUN_005478d0) — Entity spawn wave. 4 callers, 16 callees.
void EntitySpawnWave();  // FUN_005478d0

// EntityProcessAll (FUN_00545db0) — Entity process all. 4 callers, 16 callees.
void EntityProcessAll();  // FUN_00545db0

// GameModeProcessC (FUN_0054c3e0) — Game mode process C. 4 callers, 15 callees.
void GameModeProcessC();  // FUN_0054c3e0

// EntityTeamScore (FUN_00554240) — Entity team score. 4 callers, 14 callees.
uint32_t EntityTeamScore(uint32_t param_1, char param_2);  // FUN_00554240

// EntityDamageApply (FUN_0050afb0) — Entity damage apply. 4 callers, 14 callees.
uint32_t EntityDamageApply(int param_1);  // FUN_0050afb0

// RenderEntityAll (FUN_004eadd0) — Render all entities. 4 callers, 48 callees.
uint32_t RenderEntityAll(uint32_t* param_1, int param_2, int param_3);  // FUN_004eadd0

// RenderSceneEntities (FUN_004a6e50) — Render scene entities. 4 callers, 32 callees.
void RenderSceneEntities(float param_1, uint32_t param_2, int param_3, float* param_4);  // FUN_004a6e50

// ──── Cycle 49: Simple (0-1 callee) 5+ caller functions (49 functions) ────

float VectorLength(float* param_1);  // FUN_00638c10 — 9 callers
void FutureStateClear(uint8_t* param_1);  // FUN_0061f530 — 9 callers
uint32_t* PromiseSetException(uint32_t* param_1, uint32_t* param_2);  // FUN_0061af70 — 9 callers
void TaskCancelOne(int param_1, char param_2);  // FUN_00617690 — 9 callers
void EntityPositionSet(int param_1, int param_2, int param_3);  // FUN_005d7ca0 — 9 callers
void EntityRelease(int* param_1);  // FUN_00527c80 — 9 callers
void SceneObjectAdd(int param_1, uint32_t* param_2);  // FUN_00521fc0 — 9 callers
uint64_t ThreadLocalStorage(uint32_t param_1, uint32_t param_2, uint32_t* param_3);  // FUN_00630970 — 9 callers
uint32_t RenderQueryCaps(int param_1, uint32_t param_2, uint32_t param_3, int param_4);  // FUN_004fb0f0 — 9 callers
void CRTInvalidParam();  // FUN_00643b33 — 8 callers
void CRTPureCall();  // FUN_006433d0 — 8 callers
float SinPrecise2(float param_1);  // FUN_0063ff40 — 8 callers
void TaskSchedulerClear(int param_1, char param_2);  // FUN_0060d8b0 — 8 callers
void ExceptionChainCleanup();  // FUN_00601120 — 8 callers
void MatrixDecompose(float* param_1, float* param_2);  // FUN_005fafc0 — 8 callers
bool NetworkAddrCheck(uint32_t param_1, uint32_t param_2);  // FUN_00578f00 — 8 callers
void EntityAnimStop(int param_1);  // FUN_00566e20 — 8 callers
void EntitySoundPlay(int p1, int p2, int p3, uint32_t p4, float p5);  // FUN_00515940 — 8 callers
void EntityPhysicsUpdate(int param_1);  // FUN_0050a2f0 — 8 callers
void DialogDtor(uint32_t* param_1);  // FUN_004d1140 — 8 callers
void UITextSet(int param_1, int* param_2, uint32_t param_3, uint32_t param_4);  // FUN_004c3300 — 8 callers
uint32_t EntitySlotValid(float* param_1, int param_2);  // FUN_0047c080 — 8 callers
uint32_t ScoreCompare(int param_1, int param_2);  // FUN_0045b320 — 8 callers
void ThrowOutOfRange2();  // FUN_0043fce0 — 8 callers
void IteratorAssign(int param_1, uint32_t* param_2);  // FUN_0042aca0 — 8 callers
void SpinLockAcquire(int* param_1, uint32_t param_2);  // FUN_00634930 — 7 callers
int ConcurrentQueuePop(uint32_t* param_1);  // FUN_0061b8c0 — 7 callers
void TaskWaitSingle(int param_1);  // FUN_00614410 — 7 callers
void MasterServerLogError();  // FUN_00603240 — 7 callers
void EntitySoundStop(int param_1, int param_2);  // FUN_00559020 — 7 callers
void RenderStateSet();  // FUN_004fb690 — 7 callers
void DialogLevelCheck(uint32_t param_1);  // FUN_004d0ef0 — 7 callers
void SceneEntityRemove(int* param_1, uint32_t* param_2);  // FUN_004872e0 — 7 callers
void EntityMatrixSet(int param_1, float* param_2, int param_3, int param_4);  // FUN_004853d0 — 7 callers
void EntityDelete(int param_1);  // FUN_00482020 — 7 callers
void BigIntShiftLeft(uint32_t* param_1, uint8_t param_2);  // FUN_004346e0 — 7 callers
float FastSinTable(float param_1);  // FUN_00638780 — 7 callers
uint32_t* AsyncResultInit(uint32_t* param_1);  // FUN_0061ce90 — 7 callers
void MatrixIdentity(float* param_1);  // FUN_005fa980 — 7 callers
uint32_t EntityIsSmartie(int param_1);  // FUN_0056b890 — 7 callers
void CRTJumpHandler();  // FUN_00640110 — 6 callers
void StrToWideChar(const char* param_1, wchar_t* param_2, int param_3);  // FUN_006328b0 — 5 callers
void SEHFrameCheck();  // FUN_0062544d — 5 callers
void EntityTransformSet(int p1, int p2, int* p3, int p4);  // FUN_0048b8a0 — 5 callers
void EntityLinkRemove(int* param_1);  // FUN_00483e10 — 5 callers
void StackCookieCheck();  // FUN_00455873 — 5 callers
long long AllShl(uint8_t p1, int p2);  // FUN_006457a0 — 5 callers
void CIAtan2();  // FUN_006448c3 — 5 callers
void SEHProlog4();  // FUN_00644680 — 5 callers

// ─── Cycle 50: 5+ callers, 2-3 callees (33 functions) ───
void FullPathResolve(char* param_1, uint32_t* param_2);  // FUN_00632640 — 9 callers, 3 callees
void VectorDtorScaled(int param_1);  // FUN_0043fb70 — 8 callers, 2 callees
void PathArrayPush(int param_1, float* param_2, float* param_3, uint32_t param_4, uint32_t param_5);  // FUN_004859c0 — 8 callers, 2 callees
void DialogNodeAppend(uint32_t* param_1, uint32_t param_2, uint32_t param_3);  // FUN_004d4e20 — 8 callers, 2 callees
void EntityCollisionListInit(int param_1);  // FUN_004eabf0 — 8 callers, 2 callees
uint32_t TerrainPatchQuery(uint32_t param_1, uint32_t param_2, int param_3, int param_4);  // FUN_0055ebd0 — 8 callers, 2 callees
void MatrixLoadIdentityDepthXor(uint32_t* param_1, uint32_t param_2);  // FUN_0063ecb0 — 8 callers, 2 callees
uint32_t FsOpenHandle(uint32_t* param_1, const wchar_t* param_2, uint32_t param_3, uint32_t param_4);  // FUN_006419ab — 8 callers, 2 callees
int MapNodeLookup(int param_1);  // FUN_0042d190 — 8 callers, 3 callees
void VectorDtor18(int* param_1);  // FUN_00441c70 — 8 callers, 3 callees
void PlayerDamageApply(int param_1, int param_2, int param_3, int param_4, float param_5, float param_6, float param_7, float param_8);  // FUN_00469310 — 8 callers, 3 callees
void DialogSubDestroy(int param_1);  // FUN_004d00e0 — 8 callers, 3 callees
void TextMetricsCalc(uint32_t param_1, int param_2);  // FUN_004d4270 — 8 callers, 3 callees
void EntityParentCleanup();  // FUN_0055a160 — 8 callers, 3 callees
void MapMemFree(int param_1, int param_2);  // FUN_00640660 — 8 callers, 3 callees
void HashTableDtor(uint32_t* param_1);  // FUN_004489f0 — 7 callers, 2 callees
void VectorDtor16(int* param_1);  // FUN_0046fdf0 — 7 callers, 2 callees
float* TextLayoutAdvance(int* param_1, float* param_2, float param_3, char* param_4, char* param_5);  // FUN_004869d0 — 7 callers, 2 callees
void NetworkScoreUpdate();  // FUN_00557380 — 7 callers, 2 callees
void EntityGroundSlope(int param_1);  // FUN_005af030 — 7 callers, 2 callees
uint32_t NetworkPacketHandler(int param_1, int param_2, int param_3, int param_4);  // FUN_005daed0 — 7 callers, 2 callees
uint32_t* TaskCreate(uint32_t* param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4, int* param_5, uint32_t param_6);  // FUN_0061d2c0 — 7 callers, 2 callees
void VectorDtor24(int param_1);  // FUN_00438690 — 7 callers, 3 callees
void VectorAlloc18(uint32_t param_1);  // FUN_00440ea0 — 7 callers, 3 callees
void EntitySlotUpdate(uint32_t* param_1);  // FUN_004512e0 — 7 callers, 3 callees
void VectorDtor28(int* param_1);  // FUN_00451f10 — 7 callers, 3 callees
uint32_t HashTableGrow(int param_1, uint32_t param_2);  // FUN_004707b0 — 7 callers, 3 callees
void EntityFrameIndexUpdate(int* param_1, int param_2, int param_3);  // FUN_00484220 — 7 callers, 3 callees
uint32_t RenderEntityUpdate(uint32_t* param_1, int param_2);  // FUN_004f0e40 — 7 callers, 3 callees
int NetworkPlayerUpdate(uint32_t param_1, uint64_t* param_2, int param_3, uint64_t* param_4, uint32_t* param_5);  // FUN_0055e760 — 7 callers, 3 callees
void EntitySoundRangeCheck(int param_1, uint64_t* param_2);  // FUN_005a6780 — 7 callers, 3 callees
void VectorScaleW(float* param_1, float* param_2);  // FUN_0063f5b0 — 6 callers, 2 callees
int AsyncTaskInit(int param_1, uint32_t param_2, int* param_3);  // FUN_0061c0a0 — 6 callers, 3 callees

// ─── Cycle 51: 5+ callers, 4-6 callees (35 functions) ───
uint32_t* StringInit(uint32_t* param_1, uint32_t param_2, char param_3);  // FUN_0044c2a0 — 8c/4e
uint32_t ThreadLocalInit(int param_1, int param_2, int param_3, int param_4);  // FUN_005db740 — 8c/4e
void VectorGrow4(int param_1, uint32_t param_2);  // FUN_00448900 — 8c/5e
void GameFrameAdvance(int param_1);  // FUN_00557290 — 8c/5e
uint32_t* WideStringPath(uint32_t* param_1, uint32_t* param_2);  // FUN_00440620 — 8c/6e
uint32_t* StringFormatV(char* param_1, uint32_t* param_2, uint32_t* param_3, int param_4, int param_5);  // FUN_0044c530 — 7c/4e
void NetworkChatSend(int param_1, uint32_t param_2);  // FUN_00463d20 — 7c/4e
void EntityRenderDispatch(int param_1, float* param_2, int param_3, uint32_t param_4, char param_5, float param_6);  // FUN_00484360 — 7c/4e
uint32_t* RenderPoolCreate(int param_1, uint32_t param_2, uint32_t param_3);  // FUN_004e0ff0 — 7c/4e
uint32_t* StringMove(uint32_t* param_1, void* param_2, uint32_t param_3);  // FUN_00632100 — 7c/4e
void NetworkPlayerSync(int param_1, int param_2);  // FUN_0048ff10 — 7c/5e
void EntityFullReset(int param_1);  // FUN_0055e390 — 7c/5e
void EntityEffectDispatch(int param_1);  // FUN_00584000 — 7c/5e
uint32_t NetworkEntityCreate(int param_1, uint32_t* param_2, int param_3, int param_4);  // FUN_005db200 — 7c/5e
int TaskSchedule(int param_1, int param_2);  // FUN_0061c3b0 — 7c/5e
void EntityAttachmentUpdate(int param_1, int param_2, int param_3, char param_4);  // FUN_00508ad0 — 7c/6e
void PixelFormatConvert(int param_1, uint32_t param_2);  // FUN_00627780 — 6c/5e
void TaskWaitChain(int param_1, int* param_2);  // FUN_0061b490 — 6c/6e
void EntityRenderSetup2(int param_1, uint32_t* param_2, uint32_t param_3, uint32_t param_4);  // FUN_00485010 — 5c/4e
void StringThrowLength(uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t* param_4);  // FUN_004b42b0 — 5c/4e
void EntityLaunchProjectile(uint32_t param_1, int param_2, uint64_t* param_3, uint32_t param_4, float param_5, int param_6, float param_7);  // FUN_005082f0 — 5c/4e
void EntityPhysicsApply(int param_1);  // FUN_0056bd70 — 5c/4e
int EntityFindTarget(float param_1);  // FUN_005d4050 — 5c/4e
void EntityCameraRender(int param_1);  // FUN_005dec20 — 5c/4e
uint32_t* WideStringInit(uint32_t* param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4);  // FUN_0043db50 — 5c/5e
void NetworkDisconnect();  // FUN_004574c0 — 5c/5e
void CameraPathInit(int param_1);  // FUN_005f7b70 — 5c/5e
uint32_t TaskExceptionCheck(uint32_t param_1, int param_2, int* param_3);  // FUN_0060c8e0 — 5c/5e
void VFSPathParse(int param_1);  // FUN_0062be70 — 5c/5e
uint32_t StringCopyTruncated(char* param_1);  // FUN_00632790 — 5c/5e
void EntityCollisionResponse(int param_1, int param_2, int param_3, int param_4);  // FUN_004a5080 — 5c/6e
int VectorPushBack(int* param_1, uint32_t param_2);  // FUN_004fe880 — 5c/6e
uint32_t* MapEmplace(int* param_1, void* param_2, uint32_t* param_3);  // FUN_00593d40 — 5c/6e
void EntityMountUpdate(int param_1, int param_2);  // FUN_005a7720 — 5c/6e
uint32_t TaskGetResult(int* param_1, uint32_t param_2);  // FUN_0060c810 — 5c/6e

// ─── Cycle 52: 5+ callers, 7+ callees (47 functions) ───
void SceneRenderPass(int param_1);  // FUN_00523b20 — 8c/7e
void MasterServerConnect(char* param_1);  // FUN_00605240 — 8c/7e
uint32_t TaskComplete(uint32_t param_1, uint32_t param_2);  // FUN_0061b040 — 8c/7e
void DialogLayoutUpdate(uint32_t* param_1);  // FUN_004d5b50 — 8c/8e
uint8_t* StringConcat(uint8_t* param_1, uint8_t* param_2);  // FUN_00440f20 — 8c/9e
void NetworkPacketLog(int param_1);  // FUN_004af150 — 8c/9e
void EntityNetworkInit(int param_1);  // FUN_0048e200 — 8c/12e
void EntityAILogic(int param_1);  // FUN_00588ef0 — 8c/14e
void EntitySmartieAI(int param_1);  // FUN_005ce1f0 — 8c/18e
void PlayerListInit(int param_1);  // FUN_00457660 — 7c/7e
bool EntityRayTest(float* param_1, int param_2, char* param_3, uint8_t* param_4, uint32_t param_5);  // FUN_00488b50 — 7c/7e
void EntityVisibilityUpdate(int param_1);  // FUN_0055e4f0 — 7c/7e
void RenderQueueProcess(int param_1);  // FUN_00502c30 — 7c/9e
void EntityProjectileSimulate(int param_1);  // FUN_005e9300 — 7c/11e
void WideStringConcat(uint32_t* param_1, uint32_t* param_2, uint32_t param_3);  // FUN_0044d670 — 7c/12e
void RenderPassExecute(int param_1);  // FUN_004e3060 — 7c/12e
void GameLoopProcess(int param_1);  // FUN_00464bf0 — 7c/20e
uint8_t* WideStringAssign(uint8_t* param_1, int* param_2, int* param_3);  // FUN_0042f1b0 — 6c/8e
uint32_t FsDirectoryIterate(const wchar_t* param_1, uint32_t* param_2, uint32_t param_3, uint32_t param_4);  // FUN_0064170e — 6c/8e
int WideStringGrow(uint32_t* param_1, uint32_t param_2);  // FUN_0043b4f0 — 5c/7e
void RegSetAllowJoiners(int param_1);  // FUN_00457c50 — 5c/7e
void RegSetLockTeams(int param_1);  // FUN_00457e10 — 5c/7e
uint32_t EntityDamageCalc(int param_1, int param_2, int param_3);  // FUN_00507fa0 — 5c/7e
int EntityInventoryCheck(uint32_t param_1, uint32_t param_2);  // FUN_0056fc10 — 5c/7e
void EntityBridgePath(int param_1);  // FUN_005bbda0 — 5c/7e
int EntityGuardTarget(int param_1, int param_2);  // FUN_00569920 — 5c/8e
uint32_t* WideStringReplace(uint32_t* param_1, uint32_t* param_2, uint32_t param_3);  // FUN_00441710 — 5c/9e
void RegSetGameModeName(int param_1, int param_2);  // FUN_004583c0 — 5c/9e
void RegSetMapName(int param_1, int param_2);  // FUN_004585c0 — 5c/9e
void EntityPickupProcess(int param_1);  // FUN_005ae2b0 — 5c/9e
void SpinLockRelease(uint32_t param_1);  // FUN_00634970 — 5c/9e
void RenderTargetResolve(int param_1);  // FUN_004f88c0 — 5c/11e
void EntityWaveSpawn2(int param_1);  // FUN_0054d5c0 — 5c/12e
void BigIntDivide(uint32_t param_1);  // FUN_004352e0 — 5c/13e
void SceneVisibilityProcess(int param_1);  // FUN_005323c0 — 5c/14e
void RenderSceneFlush(int param_1);  // FUN_004a69a0 — 5c/17e
void NetworkSessionInit(int param_1);  // FUN_00459970 — 5c/26e
void NetworkSessionProcess(int param_1);  // FUN_00459be0 — 5c/40e
void GameModeProcessFull(int param_1);  // FUN_0045b4e0 — 5c/79e
int WideStringCompare(int* param_1, int* param_2, int param_3);  // FUN_00449e30 — 6c/9e
void PlayerScoreUpdate(int param_1);  // FUN_0045b080 — 6c/10e
void NetworkEntityUpdate(int param_1);  // FUN_00572990 — 6c/10e
uint32_t TaskWaitAny(uint32_t param_1, int param_2);  // FUN_0060c0d0 — 6c/13e
uint32_t TaskWaitAll(uint32_t param_1, int param_2);  // FUN_0060d370 — 6c/13e
void EntitySmartieProcess(int param_1);  // FUN_004a9570 — PS2 "smartie_move" (conf 1.0). 6c/15e
void RenderEntityProcess(int param_1);  // FUN_004e3c50 — PS2 "firewall_create_fire" (conf 0.9, MIS-NAMED by recomp). 6c/15e
void EntityVimpProcess(int param_1);  // FUN_0058cef0 — 6c/19e

// ═══════════════════════════════════════════════════════════
// Cycle 53: 3-caller, 0-callee leaf functions (45 functions)
// ═══════════════════════════════════════════════════════════
void EngineUtil42A9B0();  // FUN_0042a9b0 — 3c/0e
void ScalarWrite4359A0(void* p);  // FUN_004359a0 — 3c/0e
void EngineUtil4359F0();  // FUN_004359f0 — 3c/0e
void VtableCall43FC50(int** obj);  // FUN_0043fc50 — 3c/0e
void EngineUtil440E90();  // FUN_00440e90 — 3c/0e
void ArrayInit441F80(int* arr, unsigned int count, int val);  // FUN_00441f80 — 3c/0e
void EngineUtil446860();  // FUN_00446860 — 3c/0e
void VtableCall44A320(int** obj);  // FUN_0044a320 — 3c/0e
void EngineUtil44C1C0();  // FUN_0044c1c0 — 3c/0e
uint8_t CharClassify44DAD0(uint8_t ch);  // FUN_0044dad0 — 3c/0e
void NetworkStateCheck459760();  // FUN_00459760 — 3c/0e
int* PtrAdvance16471270(int* p);  // FUN_00471270 — 3c/0e
void GameUtil4727B0();  // FUN_004727b0 — 3c/0e
void EntitySlotIterate4745A0(int entity, int flag);  // FUN_004745a0 — 3c/0e
void GameUtil4772B0();  // FUN_004772b0 — 3c/0e
void EntityFlagCheck47D9F0(int entity, char flag);  // FUN_0047d9f0 — 3c/0e
int EntityArrayScan47F450(int idx, int val, int count);  // FUN_0047f450 — 3c/0e
void CrtFree(void* mem);  // FUN_0048ad00 (free) — 3c/0e
void LinkedListWalk48D740(int ptr);  // FUN_0048d740 — 3c/0e
void GlobalCopy4A52F0();  // FUN_004a52f0 — 3c/0e
void Log2Compute4AEFE0();  // FUN_004aefe0 — 3c/0e
int DataTableScan4B36C0(int* table);  // FUN_004b36c0 — 3c/0e
int CondCompare4B3AB0(int a, int b, int c);  // FUN_004b3ab0 — 3c/0e
void VtableCall4BA600(int** obj);  // FUN_004ba600 — 3c/0e
void VtableCall4C1660(int** obj);  // FUN_004c1660 — 3c/0e
bool VectorCompare4D6C60(float* a, float* b);  // FUN_004d6c60 — 3c/0e
uint32_t* BitFieldRotate4F3630(uint32_t* dst, uint32_t src, uint32_t* val);  // FUN_004f3630 — 3c/0e
int RendererLookup4F9AA0(int id);  // FUN_004f9aa0 — 3c/0e
void RenderUtil506420();  // FUN_00506420 — 3c/0e
void EntityClearRefs55C0C0(int entity);  // FUN_0055c0c0 — 3c/0e
void RenderUtil5654A0();  // FUN_005654a0 — 3c/0e
void RenderUtil5816F0();  // FUN_005816f0 — 3c/0e
void RenderUtil581850();  // FUN_00581850 — 3c/0e
void SysUtil604AD0();  // FUN_00604ad0 — 3c/0e
void SysUtil61ACA0();  // FUN_0061aca0 — 3c/0e
void VtableCall61F3D0(int** obj);  // FUN_0061f3d0 — 3c/0e
void SysUtil633470();  // FUN_00633470 — 3c/0e
void SysUtil639E20();  // FUN_00639e20 — 3c/0e
void SysUtil63EDE0();  // FUN_0063ede0 — 3c/0e
void SysUtil63EE50();  // FUN_0063ee50 — 3c/0e
void SysUtil640170();  // FUN_00640170 — 3c/0e
void SysUtil640590();  // FUN_00640590 — 3c/0e
void SysUtil643FE0();  // FUN_00643fe0 — 3c/0e
int ScrtIsUCRT();  // FUN_0064446c — 3c/0e
void DClass();  // FUN_0064591b — 3c/0e

// Cycle 53b: 4-caller functions (1 function)
void LibmSse2CosPrecise();  // FUN_006448e7 — 4c/0e

// --- Cycle 54: 3-caller / 1-callee (58 functions) ---
void CoreUtil42AA40();  // FUN_0042aa40 — 3c/1e
void CoreUtil42C3F0();  // FUN_0042c3f0 — 3c/1e
void CoreUtil430040();  // FUN_00430040 — 3c/1e
void CoreUtil432080();  // FUN_00432080 — 3c/1e
void CoreUtil436050();  // FUN_00436050 — 3c/1e
void CoreUtil438A30();  // FUN_00438a30 — 3c/1e
void CoreUtil43B140();  // FUN_0043b140 — 3c/1e
void CoreUtil43B270();  // FUN_0043b270 — 3c/1e
void CoreUtil4423E0();  // FUN_004423e0 — 3c/1e
void CoreUtil443690();  // FUN_00443690 — 3c/1e
void CoreUtil444110();  // FUN_00444110 — 3c/1e
void CoreUtil4480C0();  // FUN_004480c0 — 3c/1e
void CoreUtil44DE60();  // FUN_0044de60 — 3c/1e
void CoreUtil44F730();  // FUN_0044f730 — 3c/1e
void GameFn4517A0();  // FUN_004517a0 — 3c/1e
void GameFn4558D0();  // FUN_004558d0 — 3c/1e
void GameFn45B3F0();  // FUN_0045b3f0 — 3c/1e
void GameFn4724D0();  // FUN_004724d0 — 3c/1e
void FloatOp47CBB0();  // FUN_0047cbb0 — 3c/1e
void EntityFieldOp47D960(int e);  // FUN_0047d960 — 3c/1e
void GameFn481DD0();  // FUN_00481dd0 — 3c/1e
void GameFn486380();  // FUN_00486380 — 3c/1e
void GameFn497DD0();  // FUN_00497dd0 — 3c/1e
void WideStrOp4B4360();  // FUN_004b4360 — 3c/1e
void VirtCall4BAE60(int obj);  // FUN_004bae60 — 3c/1e
void GameFn4CE700();  // FUN_004ce700 — 3c/1e
void GameFn4D0340();  // FUN_004d0340 — 3c/1e
void GameFn4D4EE0();  // FUN_004d4ee0 — 3c/1e
void VirtCall4D5E70(int obj);  // FUN_004d5e70 — 3c/1e
void GameFn4D6650();  // FUN_004d6650 — 3c/1e
void FloatOp4D96E0();  // FUN_004d96e0 — 3c/1e
void GameFn4F48A0();  // FUN_004f48a0 — 3c/1e
void WideStrOp4FE9F0();  // FUN_004fe9f0 — 3c/1e
void FloatOp5312B0();  // FUN_005312b0 — 3c/1e
void RenderFn532E40();  // FUN_00532e40 — 3c/1e
void RenderFn536470();  // FUN_00536470 — 3c/1e
void RenderFn558130();  // FUN_00558130 — 3c/1e
void RenderFn565580();  // FUN_005654a0 — 3c/1e
void FloatOp565A80();  // FUN_00565a80 — 3c/1e
void SwitchOp5D29A0();  // FUN_005d29a0 — PS2 "mecc_special_weapon_logic" (conf 0.9). 3c/1e
void FloatOp5E0FD0();  // FUN_005e0fd0 — 3c/1e
void RenderFn5E8BC0();  // FUN_005e8bc0 — 3c/1e
void RenderFn5F54D0();  // FUN_005f54d0 — 3c/1e
void SysFn601160();  // FUN_00601160 — 3c/1e
void SysFn6018F0();  // FUN_006018f0 — 3c/1e
void SysFn624F88();  // FUN_00624f88 — 3c/1e
void SysFn625EC0();  // FUN_00625ec0 — 3c/1e
void SysFn626FE0();  // FUN_00626fe0 — 3c/1e
void SysFn627120();  // FUN_00627120 — 3c/1e
void SysFn627460();  // FUN_00627460 — 3c/1e
void SysFn630DB0();  // FUN_00630db0 — 3c/1e
void SysFn630FF0();  // FUN_00630ff0 — 3c/1e
void SysFn631010();  // FUN_00631010 — 3c/1e
void SysFn6328D0();  // FUN_006328d0 — 3c/1e
void VirtCall634900(int obj);  // FUN_00634900 — 3c/1e
void FloatOp63F630();  // FUN_0063f630 — 3c/1e
void SysFn6433E0();  // FUN_006433e0 — 3c/1e
void SysFn645250();  // FUN_00645250 — 3c/1e

// --- Cycle 55: 3-caller / 2-3 callee (99 functions) ---
bool CoreFn432F30(int *param_1);  // 0x00432f30
void CoreFn43E3B0();  // 0x0043e3b0
void CoreFn442250();  // 0x00442250
void CoreFn4438F0(int *param_1);  // 0x004438f0
void CoreFn4455D0();  // 0x004455d0
uint32_t * CoreFn447DC0(uint32_t *param_1,uint32_t *param_2,uint32_t param_3,int param_4,uint32_t param_5);  // 0x00447dc0
int * CoreFn44CB00(int *param_1,uint32_t param_2,int param_3,int param_4,char param_5);  // 0x0044cb00
void CoreFn44D5E0();  // 0x0044d5e0
uint32_t CoreFn44EFD0(uint32_t param_1,uint32_t *param_2,uint32_t param_3,uint32_t param_4);  // 0x0044efd0
void CoreFn44F050(int *param_1);  // 0x0044f050
void GameFn452A80();  // 0x00452a80
int GameFn453050(int param_1);  // 0x00453050
int GameFn4578C0(int *param_1);  // 0x004578c0
void GameFn45B1F0();  // 0x0045b1f0
void GameFn4650B0(int param_1,int param_2);  // 0x004650b0
void GameFn468EC0(int param_1);  // 0x00468ec0
uint32_t GameFn46E4B0(uint32_t param_1,uint32_t *param_2,uint32_t *param_3);  // 0x0046e4b0
void GameFn46FEB0(uint32_t *param_1);  // 0x0046feb0
void GameFn471280(uint32_t *param_1);  // 0x00471280
void GameFn4729F0();  // 0x004729f0
void GameFn47CA50(int param_1,char param_2);  // 0x0047ca50
void GameFn481130();  // 0x00481130
void GameFn481870();  // 0x00481870
void GameFn481C90(uint32_t *param_1);  // 0x00481c90
void GameFn4841C0();  // 0x004841c0
void GameFn485AF0();  // 0x00485af0
void GameFn4873C0();  // 0x004873c0
void GameFn488A30(uint32_t param_1,uint32_t param_2);  // 0x00488a30
uint32_t GameFn48E020(int param_1);  // 0x0048e020
void GameFn48E840(int param_1);  // 0x0048e840
uint8_t * GameFn4B1700(int param_1,int param_2);  // 0x004b1700
uint32_t GameFn4B4CE0(uint32_t param_1,uint32_t param_2,uint32_t param_3,int param_4,int param_5,

            short param_6);  // 0x004b4ce0
uint32_t GameFn4B59D0(uint32_t param_1,int param_2,uint32_t param_3,uint32_t param_4,uint32_t param_5,int param_6

            ,short param_7);  // 0x004b59d0
void GameFn4B9880();  // 0x004b9880
uint32_t * GameFn4BA540(uint32_t *param_1,uint32_t *param_2,uint32_t param_3,int param_4,uint32_t param_5);  // 0x004ba540
int * GameFn4BC570(int *param_1,uint32_t param_2,int param_3,int param_4,char param_5);  // 0x004bc570
uint32_t * GameFn4BC6C0(uint32_t *param_1,uint32_t param_2,uint32_t param_3,uint32_t *param_4);  // 0x004bc6c0
void GameFn4BF890(int param_1);  // 0x004bf890
void GameFn4CA120(uint32_t param_1,uint32_t *param_2);  // 0x004ca120
uint32_t * GameFn4CB120(uint32_t *param_1,uint32_t param_2,uint32_t param_3,int param_4,int param_5,

            char param_6);  // 0x004cb120
uint32_t * GameFn4CBD80(uint32_t *param_1,int param_2,uint32_t param_3,uint32_t param_4,uint32_t param_5,

            int param_6,char param_7);  // 0x004cbd80
void GameFn4D0D60();  // 0x004d0d60
uint32_t * GameFn4D6AC0(uint32_t *param_1);  // 0x004d6ac0
void GameFn4D9DC0(uint32_t param_1,uint32_t param_2);  // 0x004d9dc0
uint32_t * GameFn4E98E0(uint32_t param_1);  // 0x004e98e0
void GameFn4F7490();  // 0x004f7490
void GameFn4F7D30(float *param_1);  // 0x004f7d30
void RenderFn502A10(int param_1,int param_2);  // 0x00502a10
bool RenderFn504160(int param_1,int *param_2);  // 0x00504160
int RenderFn507D50(uint32_t param_1,uint32_t param_2,float *param_3,uint32_t param_4,uint32_t param_5);  // 0x00507d50
void RenderFn509FE0(int param_1,int param_2,float *param_3);  // 0x00509fe0
void RenderFn51C5E0(int param_1);  // 0x0051c5e0
void RenderFn523060();  // 0x00523060
void RenderFn532B50(int param_1);  // 0x00532b50
void RenderFn553F40(int param_1);  // 0x00553f40
void RenderFn566AB0(int param_1,float *param_2);  // 0x00566ab0
void RenderFn569130(int param_1);  // 0x00569130
void RenderFn573E30(int param_1,int *param_2);  // 0x00573e30
void RenderFn5809D0(int param_1);  // 0x005809d0
void RenderFn582C30(int param_1);  // 0x00582c30
void RenderFn583D60(uint32_t param_1,int param_2);  // 0x00583d60
void RenderFn584990(int param_1);  // 0x00584990
void RenderFn595070(int param_1,float *param_2);  // 0x00595070
void RenderFn5B07A0(int param_1,int param_2);  // 0x005b07a0
void RenderFn5B0DD0(int param_1,int param_2);  // 0x005b0dd0
void RenderFn5CCA80(int param_1,int param_2,int param_3,int param_4,uint64_t *param_5,uint32_t param_6);  // 0x005cca80
void RenderFn5CEAE0(int param_1);  // 0x005ceae0
void RenderFn5D95F0();  // 0x005d95f0
void RenderFn5D9780();  // 0x005d9780
void RenderFn5D9910();  // 0x005d9910
void RenderFn5D9A90();  // 0x005d9a90
void RenderFn5E2F30(int param_1);  // 0x005e2f30
uint32_t RenderFn5EB0F0(int *param_1);  // 0x005eb0f0
void RenderFn5F3340(int param_1,uint32_t param_2);  // 0x005f3340
void SysFn60A650(uint32_t *param_1);  // 0x0060a650
void SysFn60A890(uint32_t *param_1);  // 0x0060a890
void SysFn60B920(uint32_t param_1,uint32_t *param_2);  // 0x0060b920
void SysFn610050();  // 0x00610050
void SysFn612B50(uint32_t *param_1);  // 0x00612b50
void SysFn612D50(uint32_t *param_1);  // 0x00612d50
void SysFn613080(uint32_t *param_1);  // 0x00613080
void SysFn6148E0(uint32_t *param_1);  // 0x006148e0
void SysFn614B20(uint32_t *param_1);  // 0x00614b20
void SysFn614D80(uint32_t *param_1);  // 0x00614d80
void SysFn615BD0(uint32_t *param_1);  // 0x00615bd0
void SysFn615DD0(uint32_t *param_1);  // 0x00615dd0
void SysFn618E90(uint32_t *param_1);  // 0x00618e90
void SysFn619090(uint32_t *param_1);  // 0x00619090
void SysFn619290(uint32_t *param_1);  // 0x00619290
void SysFn625B90(int *param_1);  // 0x00625b90
void SysFn625C30(int *param_1);  // 0x00625c30
void SysFn6275C0();  // 0x006275c0
void SysFn630D20();  // 0x00630d20
void SysFn632570();  // 0x00632570
void SysFn63F040();  // 0x0063f040
void SysFn6411E5();  // 0x006411e5
void SysFn6414EF();  // 0x006414ef
void EHVectorCtorIter();  // 0x00643c10
void SysFn644AC3();  // 0x00644ac3

// --- Cycle 56: 3-caller / 4+ callee (118 functions) ---
float * RenderFn537130(float *param_1);  // 0x00537130
bool GameFn4796B0(uint32_t param_1,int param_2,uint32_t param_3);  // 0x004796b0
void GameFn45AC90(void);  // 0x0045ac90
void GameFn4916E0(int param_1);  // 0x004916e0
void GameFn4C0420();  // 0x004c0420
void RenderFn5434F0();  // 0x005434f0
int * GameFn4B6520(int *param_1,int *param_2,float *param_3);  // 0x004b6520
void RenderFn56DC70(uint64_t *param_1,uint64_t *param_2,int param_3,int param_4);  // 0x0056dc70
void GameFn4542D0();  // 0x004542d0
void GameFn4E2BE0(uint32_t param_1);  // 0x004e2be0
void RenderFn539F90(int param_1);  // 0x00539f90
void GameFn4BE510(int param_1);  // 0x004be510
void RenderFn5068F0(int param_1);  // 0x005068f0
void RenderFn52F3F0();  // 0x0052f3f0
void RenderFn544C20();  // 0x00544c20
void RenderFn544FF0(void);  // 0x00544ff0
void GameFn454E00();  // 0x00454e00
void RenderFn539470(int param_1);  // 0x00539470
void RenderFn5CF100(int param_1,int param_2,uint32_t param_3);  // 0x005cf100
uint32_t * CoreFn44AAA0(uint32_t param_1,int *param_2,uint32_t *param_3,uint32_t *param_4,uint32_t param_5,

            int param_6,uint32_t param_7);  // 0x0044aaa0
bool RenderFn5822F0(int param_1,byte *param_2,int param_3,char param_4);  // 0x005822f0
void GameFn492060(int param_1,int *param_2,int param_3);  // 0x00492060
uint32_t * GameFn4BB5E0(uint32_t param_1,int *param_2,uint32_t param_3,uint32_t *param_4,uint32_t param_5,

            int param_6,uint32_t param_7);  // 0x004bb5e0
void RenderFn5424A0(void);  // 0x005424a0
void RenderFn543820(void);  // 0x00543820
void SysFn644F60(int param_1);  // 0x00644f60
void GameFn4D89B0(float param_1,uint32_t param_2,int param_3,int param_4);  // 0x004d89b0
void RenderFn542770(void);  // 0x00542770
void RenderFn57CE80(int param_1);  // 0x0057ce80
void RenderFn5EBCA0(int param_1,uint32_t param_2,int param_3,uint64_t *param_4);  // 0x005ebca0
void SysFn605300();  // 0x00605300
uint32_t SysFn60E8C0(uint32_t param_1,uint32_t param_2);  // 0x0060e8c0
uint32_t SysFn60EC90(uint32_t param_1,uint32_t param_2);  // 0x0060ec90
void CoreFn43E020();  // 0x0043e020
void GameFn453B50(int param_1);  // 0x00453b50
float * GameFn490680(char *param_1);  // 0x00490680
void GameFn492CD0(int param_1);  // 0x00492cd0
void GameFn4AD090(int param_1,int param_2,uint32_t param_3,int param_4);  // 0x004ad090
void SysFn6337C0();  // 0x006337c0
void GameFn469670(byte *param_1,byte *param_2,uint32_t param_3,char param_4);  // 0x00469670
void GameFn483B60(uint32_t *param_1);  // 0x00483b60
void RenderFn5440A0(void);  // 0x005440a0
void RenderFn5514B0(void);  // 0x005514b0
void SysFn641A9D();  // 0x00641a9d
void CoreFn4319C0();  // 0x004319c0
void GameFn4622C0();  // 0x004622c0
void GameFn4A2050(int param_1,float *param_2,float *param_3);  // 0x004a2050
void GameFn4A8A00(int param_1,int param_2);  // 0x004a8a00
void GameFn4ACA40(int param_1,int param_2,float *param_3,int param_4);  // 0x004aca40
void GameFn4B3CD0();  // 0x004b3cd0
uint32_t * GameFn4BDC70(uint32_t *param_1,uint32_t *param_2);  // 0x004bdc70
void GameFn4C1C00();  // 0x004c1c00
void GameFn4EA510(uint32_t param_1,uint32_t param_2);  // 0x004ea510
void GameFn4FD5A0(void);  // 0x004fd5a0
void RenderFn507180(int param_1);  // 0x00507180
void RenderFn53A260(int param_1);  // 0x0053a260
void RenderFn545860(uint32_t param_1);  // 0x00545860
void RenderFn548610(void);  // 0x00548610
void RenderFn54F930(uint32_t param_1);  // 0x0054f930
void RenderFn550510(uint32_t param_1);  // 0x00550510
void RenderFn5549D0();  // 0x005549d0
void RenderFn5637F0(void);  // 0x005637f0
void RenderFn5732E0(int param_1,float *param_2);  // 0x005732e0
void RenderFn578B40();  // 0x00578b40
void RenderFn587A60(int param_1);  // 0x00587a60
void RenderFn59BA00(void);  // 0x0059ba00
void RenderFn5A7860(int param_1,int param_2);  // 0x005a7860
void RenderFn5CCCF0(int param_1,int param_2,int param_3);  // 0x005cccf0
void RenderFn5CE040(int param_1);  // 0x005ce040
void RenderFn5DC100();  // 0x005dc100
void SysFn60C000();  // 0x0060c000
void CoreFn42BF40();  // 0x0042bf40
void CoreFn43D9B0();  // 0x0043d9b0
void CoreFn440350();  // 0x00440350
uint32_t CoreFn446FE0(uint32_t param_1,int *param_2,uint32_t param_3,void *param_4,uint32_t param_5);  // 0x00446fe0
void GameFn469B40(uint32_t param_1,int param_2);  // 0x00469b40
void GameFn470E50();  // 0x00470e50
void GameFn4F6BF0(int param_1);  // 0x004f6bf0
void RenderFn500290();  // 0x00500290
uint32_t RenderFn51BB80(int param_1,int param_2,char param_3,byte param_4,int param_5);  // 0x0051bb80
void RenderFn5496A0(int param_1);  // 0x005496a0
void RenderFn54CE80(void);  // 0x0054ce80
void RenderFn54FF10(uint32_t param_1);  // 0x0054ff10
uint32_t RenderFn558570(uint32_t *param_1,int param_2);  // 0x00558570
void RenderFn5878B0(int param_1);  // 0x005878b0
void RenderFn5A0540(int param_1);  // 0x005a0540
void RenderFn5C3C60(void);  // 0x005c3c60
void RenderFn5D6790(int param_1,int param_2);  // 0x005d6790
void RenderFn5E2DE0(int param_1,int param_2);  // 0x005e2de0
void RenderFn5F3F60(int param_1);  // 0x005f3f60
void SysFn60C350();  // 0x0060c350
int SysFn60DC00(int *param_1);  // 0x0060dc00
uint8_t * SysFn61AD10(int *param_1);  // 0x0061ad10
void CoreFn43EBB0();  // 0x0043ebb0
void CoreFn448F60(uint32_t param_1);  // 0x00448f60
void GameFn46E380();  // 0x0046e380
void GameFn470AC0();  // 0x00470ac0
FILE * GameFn4725B0(LPCSTR param_1,LPCSTR param_2);  // 0x004725b0
void GameFn486B80();  // 0x00486b80
void GameFn4BAEE0();  // 0x004baee0
void GameFn4BEA70();  // 0x004bea70
void GameFn4E9BB0(uint32_t param_1,uint32_t param_2);  // 0x004e9bb0
void GameFn4F3680();  // 0x004f3680
int RenderFn531380(int param_1,int *param_2);  // 0x00531380
void RenderFn545950(void);  // 0x00545950
void RenderFn548580(uint32_t param_1);  // 0x00548580
void RenderFn55B6C0(void);  // 0x0055b6c0
void RenderFn5710A0();  // 0x005710a0
void RenderFn5BC380(int param_1,int param_2);  // 0x005bc380
void RenderFn5EDC30(int param_1,int param_2);  // 0x005edc30
void RenderFn5F4C60(int param_1,uint32_t param_2,uint32_t param_3,int param_4);  // 0x005f4c60
void RenderFn5FD680();  // 0x005fd680
void SysFn604A60();  // 0x00604a60
void SysFn613140();  // 0x00613140
void SysFn61A8A0(int *param_1);  // 0x0061a8a0
char SysFn61A9A0(int *param_1);  // 0x0061a9a0
void SysFn62C9A0(uint32_t param_1,uint64_t *param_2,byte *param_3,int param_4);  // 0x0062c9a0
void SysFn63F750(float *param_1,float *param_2,float *param_3,float param_4);  // 0x0063f750

// --- Cycle 57: 2-caller functions (708 functions) ---
void Core2c42AAF0();  // 0x0042aaf0
void Core2c42ABA0();  // 0x0042aba0
void Core2c42AC10();  // 0x0042ac10
void Core2c42B710();  // 0x0042b710
void Core2c42B9A0();  // 0x0042b9a0
void Core2c42CAB0();  // 0x0042cab0
void Core2c42CBC0();  // 0x0042cbc0
void Core2c42D650();  // 0x0042d650
void Core2c42D9F0();  // 0x0042d9f0
void Core2c42E2B0();  // 0x0042e2b0
void Core2c42F410();  // 0x0042f410
void Core2c42FB00();  // 0x0042fb00
void Core2c4304E0();  // 0x004304e0
void Core2c430680();  // 0x00430680
void Core2c431400();  // 0x00431400
void Core2c4317C0();  // 0x004317c0
void Core2c4318A0();  // 0x004318a0
void Core2c431AF0();  // 0x00431af0
void Core2c432240();  // 0x00432240
void Core2c432DF0();  // 0x00432df0
void Core2c435770();  // 0x00435770
void Core2c435CC0();  // 0x00435cc0
void Core2c435E60();  // 0x00435e60
void Core2c437D10();  // 0x00437d10
void Core2c438270();  // 0x00438270
void Core2c4382F0();  // 0x004382f0
void Core2c4384B0();  // 0x004384b0
void Core2c4388F0();  // 0x004388f0
void Core2c439170();  // 0x00439170
void Core2c4393E0();  // 0x004393e0
void Core2c439640();  // 0x00439640
void Core2c439860();  // 0x00439860
void Core2c439A70();  // 0x00439a70
void Core2c439E50();  // 0x00439e50
void Core2c43A390();  // 0x0043a390
void Core2c43A5F0();  // 0x0043a5f0
void Core2c43A840();  // 0x0043a840
void Core2c43AA70();  // 0x0043aa70
void Core2c43AF10();  // 0x0043af10
void Core2c43AF40();  // 0x0043af40
void Core2c43B080();  // 0x0043b080
void Core2c43B700();  // 0x0043b700
void Core2c43C660();  // 0x0043c660
void Core2c43CAB0();  // 0x0043cab0
void Core2c43CC60();  // 0x0043cc60
void Core2c43D3B0();  // 0x0043d3b0
void Core2c43D420();  // 0x0043d420
void Core2c43D470();  // 0x0043d470
void Core2c43D480();  // 0x0043d480
void Core2c43D820();  // 0x0043d820
void Core2c43D990();  // 0x0043d990
void Core2c43DC70();  // 0x0043dc70
void Core2c43DD30();  // 0x0043dd30
void Core2c43DD80();  // 0x0043dd80
void Core2c43DDE0();  // 0x0043dde0
void Core2c43E440();  // 0x0043e440
void Core2c43E670();  // 0x0043e670
void Core2c43E770();  // 0x0043e770
void Core2c43E7F0();  // 0x0043e7f0
void Core2c43EF40();  // 0x0043ef40
void Core2c4401D0();  // 0x004401d0
void Core2c440480();  // 0x00440480
void Core2c4407E0();  // 0x004407e0
void Core2c4416B0();  // 0x004416b0
void Core2c441B30();  // 0x00441b30
void Core2c442020();  // 0x00442020
void Core2c4420C0();  // 0x004420c0
void Core2c442470();  // 0x00442470
void Core2c442720();  // 0x00442720
void Core2c442760();  // 0x00442760
void Core2c442870();  // 0x00442870
void Core2c442B40();  // 0x00442b40
void Core2c442DA0();  // 0x00442da0
void Core2c4433B0();  // 0x004433b0
void Core2c443500();  // 0x00443500
void Core2c443970();  // 0x00443970
void Core2c444030();  // 0x00444030
void Core2c4466E0();  // 0x004466e0
void Core2c446AD0();  // 0x00446ad0
void Core2c446B80();  // 0x00446b80
void Core2c446E00();  // 0x00446e00
void Core2c447240();  // 0x00447240
void Core2c447380();  // 0x00447380
void Core2c447710();  // 0x00447710
void Core2c447E80();  // 0x00447e80
void Core2c447F30();  // 0x00447f30
void Core2c448010();  // 0x00448010
void Core2c448870();  // 0x00448870
void Core2c4490C0();  // 0x004490c0
void Core2c44A440();  // 0x0044a440
void Core2c44AFA0();  // 0x0044afa0
void Core2c44B3F0();  // 0x0044b3f0
void Core2c44B660();  // 0x0044b660
void Core2c44B900();  // 0x0044b900
void Core2c44BB60();  // 0x0044bb60
void Core2c44C7F0();  // 0x0044c7f0
void Core2c44CD90();  // 0x0044cd90
void Core2c44CFE0();  // 0x0044cfe0
void Core2c44D2C0();  // 0x0044d2c0
void Core2c44D9F0();  // 0x0044d9f0
void Core2c44F5A0();  // 0x0044f5a0
void Core2c44F800();  // 0x0044f800
void Core2c44FDE0();  // 0x0044fde0
void Game2c4505B0();  // 0x004505b0
void Game2c450DE0();  // 0x00450de0
void Game2c450ED0();  // 0x00450ed0
void Game2c450F60();  // 0x00450f60
void thunk_FUN_0042b010();  // 0x00451610
void Game2c451E30();  // 0x00451e30
void Game2c452200();  // 0x00452200
void Game2c4527F0();  // 0x004527f0
void Game2c453370();  // 0x00453370
void Game2c453980();  // 0x00453980
void Game2c455D90();  // 0x00455d90
void Game2c455E90();  // 0x00455e90
void Game2c4566F0();  // 0x004566f0
void Game2c4568F0();  // 0x004568f0
void Game2c456960();  // 0x00456960
void Game2c4569D0();  // 0x004569d0
void Game2c456AC0();  // 0x00456ac0
void Game2c456BD0();  // 0x00456bd0
void Game2c456C40();  // 0x00456c40
void Game2c456CB0();  // 0x00456cb0
void Game2c457970();  // 0x00457970
void Game2c459070();  // 0x00459070
void Game2c45D470();  // 0x0045d470
void Game2c45D9C0();  // 0x0045d9c0
void Game2c45DAE0();  // 0x0045dae0
void Game2c45EB20();  // 0x0045eb20
void Game2c45EB80();  // 0x0045eb80
void Game2c45EC20();  // 0x0045ec20
void Game2c45F0E0();  // 0x0045f0e0
void Game2c45F850();  // 0x0045f850
void Game2c4613E0();  // 0x004613e0
void Game2c461730();  // 0x00461730
void Game2c461DB0();  // 0x00461db0
void Game2c461F90();  // 0x00461f90
void Game2c462110();  // 0x00462110
void Game2c462230();  // 0x00462230
void Game2c462640();  // 0x00462640
void Game2c462B40();  // 0x00462b40
void Game2c462C40();  // 0x00462c40
void Game2c462D40();  // 0x00462d40
void Game2c463430();  // 0x00463430
void Game2c463890();  // 0x00463890
void Game2c464770();  // 0x00464770
void Game2c4648B0();  // 0x004648b0
void Game2c465270();  // 0x00465270
void Game2c4689E0();  // 0x004689e0
void Game2c468DA0();  // 0x00468da0
void Game2c468FF0();  // 0x00468ff0
void Game2c469A90();  // 0x00469a90
void Game2c46CEF0();  // 0x0046cef0
void Game2c46D520();  // 0x0046d520
void Game2c46D860();  // 0x0046d860
void Game2c46DAD0();  // 0x0046dad0
void Game2c46DBC0();  // 0x0046dbc0
void Game2c46E680();  // 0x0046e680
void Game2c46E700();  // 0x0046e700
void thunk_FUN_0046feb0();  // 0x0046eaa0
void thunk_FUN_0046eac0();  // 0x0046eab0
void Game2c470440();  // 0x00470440
void Game2c4708A0();  // 0x004708a0
void Game2c470910();  // 0x00470910
void Game2c470FF0();  // 0x00470ff0
void Game2c4712F0();  // 0x004712f0
void Game2c471810();  // 0x00471810
void Game2c471F30();  // 0x00471f30
void Game2c472C20();  // 0x00472c20
void Game2c4730A0();  // 0x004730a0
void Game2c473F20();  // 0x00473f20
void Game2c474180();  // 0x00474180
void Game2c4745E0();  // 0x004745e0
void Game2c476250();  // 0x00476250
void Game2c476BA0();  // 0x00476ba0
void Game2c476C20();  // 0x00476c20
void Game2c47BC60();  // 0x0047bc60
void Game2c47C380();  // 0x0047c380
void Game2c47C7F0();  // 0x0047c7f0
void Game2c47C950();  // 0x0047c950
void Game2c47D0D0();  // 0x0047d0d0
void Game2c47D1A0();  // 0x0047d1a0
void Game2c47DAD0();  // 0x0047dad0
void Game2c47F4C0();  // 0x0047f4c0
void Game2c480520();  // 0x00480520
void Game2c480D60();  // 0x00480d60
void Game2c480FF0();  // 0x00480ff0
void Game2c481310();  // 0x00481310
void Game2c481F80();  // 0x00481f80
void Game2c484130();  // 0x00484130
void Game2c485520();  // 0x00485520
void Game2c486700();  // 0x00486700
void Game2c4867A0();  // 0x004867a0
void Game2c486880();  // 0x00486880
void Game2c487460();  // 0x00487460
void Game2c488490();  // 0x00488490
void Game2c4896F0();  // 0x004896f0
void Game2c48C190();  // 0x0048c190
void Game2c48D440();  // 0x0048d440
void Game2c48D9F0();  // 0x0048d9f0
void Game2c48EEB0();  // 0x0048eeb0
void Game2c48F0D0();  // 0x0048f0d0
void Game2c490050();  // 0x00490050
void Game2c4901F0();  // 0x004901f0
void Game2c490EB0();  // 0x00490eb0
void Game2c490FD0();  // 0x00490fd0
void Game2c4911A0();  // 0x004911a0
void Game2c4928C0();  // 0x004928c0
void Game2c493810();  // 0x00493810
void Game2c494B10();  // 0x00494b10
void Game2c494D50();  // 0x00494d50
void Game2c496EA0();  // 0x00496ea0
void Game2c497E40();  // 0x00497e40
void Game2c498FD0();  // 0x00498fd0
void Game2c499190();  // 0x00499190
void Game2c4992D0();  // 0x004992d0
void Game2c4994F0();  // 0x004994f0
void Game2c49A420();  // 0x0049a420
void Game2c49B8C0();  // 0x0049b8c0
void Game2c49E280();  // 0x0049e280
void Game2c49FDB0();  // 0x0049fdb0
void Game2c4A0EA0();  // 0x004a0ea0
void Game2c4A0F40();  // 0x004a0f40
void Game2c4A1140();  // 0x004a1140
void Game2c4A31C0();  // 0x004a31c0
void Game2c4A4710();  // 0x004a4710
void Game2c4A47C0();  // 0x004a47c0
void Game2c4A4C50();  // 0x004a4c50
void Game2c4A6000();  // 0x004a6000
void Game2c4A68F0();  // 0x004a68f0
void Game2c4A8550();  // 0x004a8550
void Game2c4A9BE0();  // 0x004a9be0
void Game2c4A9D40();  // 0x004a9d40
void Game2c4AA1D0();  // 0x004aa1d0
void Game2c4AB610();  // 0x004ab610
void Game2c4AC5A0();  // 0x004ac5a0
void Game2c4AC930();  // 0x004ac930
void Game2c4ACFC0();  // 0x004acfc0
void Game2c4AD2A0();  // 0x004ad2a0
void Game2c4AF080();  // 0x004af080
void Game2c4B45F0();  // 0x004b45f0
void Game2c4B49A0();  // 0x004b49a0
void Game2c4B5680();  // 0x004b5680
void Game2c4B70E0();  // 0x004b70e0
void Game2c4B7190();  // 0x004b7190
void Game2c4B7690();  // 0x004b7690
void Game2c4B7EE0();  // 0x004b7ee0
void Game2c4B81A0();  // 0x004b81a0
void Game2c4B8440();  // 0x004b8440
void Game2c4B86E0();  // 0x004b86e0
void Game2c4B8B30();  // 0x004b8b30
void Game2c4B8DC0();  // 0x004b8dc0
void Game2c4B9260();  // 0x004b9260
void Game2c4B94D0();  // 0x004b94d0
void Game2c4BA740();  // 0x004ba740
void Game2c4BBE20();  // 0x004bbe20
void Game2c4BBF80();  // 0x004bbf80
void Game2c4BC280();  // 0x004bc280
void Game2c4BC650();  // 0x004bc650
void Game2c4BCBE0();  // 0x004bcbe0
void Game2c4BD020();  // 0x004bd020
void Game2c4BD640();  // 0x004bd640
void Game2c4BD830();  // 0x004bd830
void Game2c4BD8C0();  // 0x004bd8c0
void Game2c4BDFA0();  // 0x004bdfa0
void Game2c4BE880();  // 0x004be880
void Game2c4BEB10();  // 0x004beb10
void Game2c4BEC80();  // 0x004bec80
void Game2c4BF930();  // 0x004bf930
void Game2c4BFD10();  // 0x004bfd10
void Game2c4C0150();  // 0x004c0150
void Game2c4C0210();  // 0x004c0210
void Game2c4C0720();  // 0x004c0720
void Game2c4C2530();  // 0x004c2530
void Game2c4C25D0();  // 0x004c25d0
void Game2c4C2690();  // 0x004c2690
void Game2c4C2E10();  // 0x004c2e10
void Game2c4C2FB0();  // 0x004c2fb0
void Game2c4C3010();  // 0x004c3010
void Game2c4C31F0();  // 0x004c31f0
void Game2c4C3AE0();  // 0x004c3ae0
void Game2c4C3C00();  // 0x004c3c00
void Game2c4C3CD0();  // 0x004c3cd0
void Game2c4C49E0();  // 0x004c49e0
void Game2c4C4AC0();  // 0x004c4ac0
void Game2c4C4DB0();  // 0x004c4db0
void Game2c4C57F0();  // 0x004c57f0
void Game2c4C73E0();  // 0x004c73e0
void Game2c4C9490();  // 0x004c9490
void Game2c4C9A00();  // 0x004c9a00
void Game2c4CA460();  // 0x004ca460
void Game2c4CA9B0();  // 0x004ca9b0
void Game2c4CAA90();  // 0x004caa90
void Game2c4CACC0();  // 0x004cacc0
void Game2c4CAE10();  // 0x004cae10
void Game2c4CBA60();  // 0x004cba60
void Game2c4CC860();  // 0x004cc860
void Game2c4CD070();  // 0x004cd070
void Game2c4CD180();  // 0x004cd180
void Game2c4CDCC0();  // 0x004cdcc0
void Game2c4CE4A0();  // 0x004ce4a0
void Game2c4CE6B0();  // 0x004ce6b0
void Game2c4CFBC0();  // 0x004cfbc0
void Game2c4D00C0();  // 0x004d00c0
void Game2c4D0110();  // 0x004d0110
void Game2c4D0160();  // 0x004d0160
void Game2c4D13A0();  // 0x004d13a0
void Game2c4D2050();  // 0x004d2050
void Game2c4D2220();  // 0x004d2220
void Game2c4D3B30();  // 0x004d3b30
void Game2c4D50A0();  // 0x004d50a0
void Game2c4D5570();  // 0x004d5570
void Game2c4D6260();  // 0x004d6260
void Game2c4D6780();  // 0x004d6780
void Game2c4D6F40();  // 0x004d6f40
void Game2c4D7090();  // 0x004d7090
void Game2c4D9920();  // 0x004d9920
void Game2c4D9C80();  // 0x004d9c80
void Game2c4D9EB0();  // 0x004d9eb0
void Game2c4DA0F0();  // 0x004da0f0
void Game2c4DCC30();  // 0x004dcc30
void Game2c4DCCE0();  // 0x004dcce0
void Game2c4DCD30();  // 0x004dcd30
void Game2c4DE680();  // 0x004de680
void Game2c4DF880();  // 0x004df880
void Game2c4DFAB0();  // 0x004dfab0
void Game2c4E0F50();  // 0x004e0f50
void Game2c4E1130();  // 0x004e1130
void Game2c4E2020();  // 0x004e2020
void Game2c4E20D0();  // 0x004e20d0
void Game2c4E4D90();  // 0x004e4d90
void Game2c4E53B0();  // 0x004e53b0
void Game2c4E5830();  // 0x004e5830
void Game2c4E5AD0();  // 0x004e5ad0
void Game2c4E96B0();  // 0x004e96b0
void Game2c4E9870();  // 0x004e9870
void Game2c4E9B10();  // 0x004e9b10
void Game2c4E9C70();  // 0x004e9c70
void Game2c4F2F90();  // 0x004f2f90
void Game2c4F3390();  // 0x004f3390
void Game2c4F35C0();  // 0x004f35c0
void Game2c4F3A00();  // 0x004f3a00
void Game2c4F45A0();  // 0x004f45a0
void Game2c4F4AE0();  // 0x004f4ae0
void Game2c4F4CC0();  // 0x004f4cc0
void Game2c4F52C0();  // 0x004f52c0
void Game2c4F5330();  // 0x004f5330
void Game2c4F5540();  // 0x004f5540
void Game2c4F6620();  // 0x004f6620
void Game2c4F66F0();  // 0x004f66f0
void Game2c4F6850();  // 0x004f6850
void Game2c4F69F0();  // 0x004f69f0
void Game2c4F6B20();  // 0x004f6b20
void Game2c4F6C90();  // 0x004f6c90
void Game2c4F6E30();  // 0x004f6e30
void Game2c4F6EB0();  // 0x004f6eb0
void Game2c4F6F30();  // 0x004f6f30
void Game2c4F72E0();  // 0x004f72e0
void Game2c4F7350();  // 0x004f7350
void Game2c4F79E0();  // 0x004f79e0
void Game2c4FDD90();  // 0x004fdd90
void Game2c4FE6F0();  // 0x004fe6f0
void Game2c4FE720();  // 0x004fe720
void Game2c4FF4F0();  // 0x004ff4f0
void Render2c501130();  // 0x00501130
void Render2c501920();  // 0x00501920
void Render2c5024E0();  // 0x005024e0
void Render2c502AE0();  // 0x00502ae0
void Render2c502BA0();  // 0x00502ba0
void Render2c503150();  // 0x00503150
void Render2c507950();  // 0x00507950
void Render2c508810();  // 0x00508810
void Render2c508DA0();  // 0x00508da0
void Render2c509B40();  // 0x00509b40
void Render2c50A120();  // 0x0050a120
void Render2c50BAA0();  // 0x0050baa0
void Render2c50C410();  // 0x0050c410
void Render2c50CF30();  // 0x0050cf30
void Render2c5143F0();  // 0x005143f0
void Render2c519A00();  // 0x00519a00
void Render2c51B410();  // 0x0051b410
void Render2c51F690();  // 0x0051f690
void Render2c51F860();  // 0x0051f860
void Render2c521E70();  // 0x00521e70
void Render2c522920();  // 0x00522920
void Render2c5230D0();  // 0x005230d0
void Render2c523380();  // 0x00523380
void Render2c527AD0();  // 0x00527ad0
void Render2c52B5C0();  // 0x0052b5c0
void Render2c52E3F0();  // 0x0052e3f0
void Render2c52E610();  // 0x0052e610
void Render2c530350();  // 0x00530350
void Render2c530690();  // 0x00530690
void Render2c531030();  // 0x00531030
void Render2c531140();  // 0x00531140
void Render2c531470();  // 0x00531470
void Render2c531AB0();  // 0x00531ab0
void Render2c532C40();  // 0x00532c40
void Render2c536290();  // 0x00536290
void Render2c536E90();  // 0x00536e90
void Render2c538CB0();  // 0x00538cb0
void Render2c53A590();  // 0x0053a590
void Render2c53C0F0();  // 0x0053c0f0
void Render2c53C2C0();  // 0x0053c2c0
void Render2c53D5F0();  // 0x0053d5f0
void Render2c53DAC0();  // 0x0053dac0
void Render2c53DCC0();  // 0x0053dcc0
void Render2c53DE60();  // 0x0053de60
void Render2c53EB30();  // 0x0053eb30
void Render2c53EC20();  // 0x0053ec20
void Render2c5401B0();  // 0x005401b0
void Render2c5411F0();  // 0x005411f0
void Render2c5417D0();  // 0x005417d0
void Render2c542960();  // 0x00542960
void Render2c542C80();  // 0x00542c80
void Render2c543F00();  // 0x00543f00
void Render2c544EC0();  // 0x00544ec0
void Render2c544F50();  // 0x00544f50
void Render2c545D20();  // 0x00545d20
void Render2c546A90();  // 0x00546a90
void Render2c547840();  // 0x00547840
void Render2c548970();  // 0x00548970
void Render2c549150();  // 0x00549150
void Render2c549370();  // 0x00549370
void Render2c549E30();  // 0x00549e30
void Render2c54AD60();  // 0x0054ad60
void Render2c54ADB0();  // 0x0054adb0
void Render2c54AE10();  // 0x0054ae10
void Render2c54AE90();  // 0x0054ae90
void Render2c54AF60();  // 0x0054af60
void Render2c54D110();  // 0x0054d110
void Render2c54E530();  // 0x0054e530
void Render2c54F6A0();  // 0x0054f6a0
void Render2c550280();  // 0x00550280
void Render2c550B20();  // 0x00550b20
void Render2c551280();  // 0x00551280
void Render2c552560();  // 0x00552560
void Render2c5536D0();  // 0x005536d0
void Render2c553EE0();  // 0x00553ee0
void Render2c55490C();  // 0x0055490c
void Render2c554B50();  // 0x00554b50
void Render2c554CE0();  // 0x00554ce0
void Render2c555C50();  // 0x00555c50
void Render2c557660();  // 0x00557660
void Render2c557880();  // 0x00557880
void Render2c5578C0();  // 0x005578c0
void Render2c557C40();  // 0x00557c40
void Render2c558290();  // 0x00558290
void Render2c55B500();  // 0x0055b500
void Render2c55B9E0();  // 0x0055b9e0
void Render2c55BDE0();  // 0x0055bde0
void Render2c55E6F0();  // 0x0055e6f0
void Render2c561C50();  // 0x00561c50
void Render2c564090();  // 0x00564090
void Render2c5643A0();  // 0x005643a0
void Render2c5644D0();  // 0x005644d0
void Render2c564C40();  // 0x00564c40
void Render2c565030();  // 0x00565030
void Render2c565410();  // 0x00565410
void Render2c5655E0();  // 0x005655e0
void Render2c565E90();  // 0x00565e90
void Render2c569C70();  // 0x00569c70
void Render2c56AC50();  // 0x0056ac50
void Render2c56AEC0();  // 0x0056aec0
void Render2c56E680();  // 0x0056e680
void Render2c56E9E0();  // 0x0056e9e0
void Render2c5728C0();  // 0x005728c0
void Render2c5735E0();  // 0x005735e0
void Render2c5739D0();  // 0x005739d0
void Render2c575760();  // 0x00575760
void Render2c5758A0();  // 0x005758a0
void Render2c575990();  // 0x00575990
void Render2c575BB0();  // 0x00575bb0
void Render2c575D50();  // 0x00575d50
void Render2c579030();  // 0x00579030
void Render2c57C960();  // 0x0057c960
void Render2c57F330();  // 0x0057f330
void Render2c580490();  // 0x00580490
void Render2c581440();  // 0x00581440
void Render2c5818B0();  // 0x005818b0
void Render2c581D80();  // 0x00581d80
void Render2c581E60();  // 0x00581e60
void Render2c581EF0();  // 0x00581ef0
void Render2c5831F0();  // 0x005831f0
void Render2c583C00();  // 0x00583c00
void Render2c5840C0();  // 0x005840c0
void Render2c584870();  // 0x00584870
void Render2c5864D0();  // 0x005864d0
void Render2c586E80();  // 0x00586e80
void Render2c587C80();  // 0x00587c80
void Render2c588A90();  // 0x00588a90
void Render2c58A6B0();  // 0x0058a6b0
void Render2c58AB00();  // 0x0058ab00
void Render2c58B0F0();  // 0x0058b0f0
void Render2c58D2B0();  // 0x0058d2b0
void Render2c590A30();  // 0x00590a30
void Render2c590EC0();  // 0x00590ec0
void Render2c592430();  // 0x00592430
void thunk_FUN_00462170();  // 0x00593d30
void Render2c593F70();  // 0x00593f70
void Render2c594F30();  // 0x00594f30
void Render2c5968F0();  // 0x005968f0
void Render2c59A670();  // 0x0059a670
void Render2c59B970();  // 0x0059b970
void Render2c59D5D0();  // 0x0059d5d0
void Render2c59DAE0();  // 0x0059dae0
void Render2c59DCC0();  // 0x0059dcc0
void Render2c5A62F0();  // 0x005a62f0
void Render2c5A70A0();  // 0x005a70a0
void Render2c5A7600();  // 0x005a7600
void Render2c5A8280();  // 0x005a8280
void Render2c5A84B0();  // 0x005a84b0
void Render2c5A8D00();  // 0x005a8d00
void Render2c5A9980();  // 0x005a9980
void Render2c5ABB80();  // 0x005abb80
void Render2c5ACC10();  // 0x005acc10
void Render2c5AD710();  // 0x005ad710
void Render2c5AD9C0();  // 0x005ad9c0
void Render2c5AE210();  // 0x005ae210
void Render2c5B0360();  // 0x005b0360
void Render2c5B0910();  // 0x005b0910
void Render2c5B0FD0();  // 0x005b0fd0
void Render2c5C0280();  // 0x005c0280
void Render2c5C10A0();  // 0x005c10a0
void Render2c5C1190();  // 0x005c1190
void Render2c5C1D20();  // 0x005c1d20
void Render2c5C2E50();  // 0x005c2e50
void Render2c5C2F30();  // 0x005c2f30
void Render2c5C34B0();  // 0x005c34b0
void Render2c5C35B0();  // 0x005c35b0
void Render2c5C3840();  // 0x005c3840
void Render2c5C39C0();  // 0x005c39c0
void Render2c5C3A60();  // 0x005c3a60
void Render2c5C3E20();  // 0x005c3e20
void Render2c5CCC40();  // 0x005ccc40
void Render2c5CEE50();  // 0x005cee50
void Render2c5D64C0();  // 0x005d64c0
void Render2c5D6540();  // 0x005d6540
void Render2c5D66A0();  // 0x005d66a0
void Render2c5DAD50();  // 0x005dad50
void Render2c5DB510();  // 0x005db510
void Render2c5DF770();  // 0x005df770
void Render2c5DF970();  // 0x005df970
void Render2c5E0BD0();  // 0x005e0bd0
void Render2c5E1110();  // 0x005e1110
void Render2c5E2CB0();  // 0x005e2cb0
void Render2c5E3840();  // 0x005e3840
void Render2c5E7310();  // 0x005e7310
void Render2c5E7DE0();  // 0x005e7de0
void Render2c5E8690();  // 0x005e8690
void Render2c5E8C60();  // 0x005e8c60
void Render2c5E9910();  // 0x005e9910
void Render2c5EAA00();  // 0x005eaa00
void Render2c5EB1C0();  // 0x005eb1c0
void Render2c5EB7D0();  // 0x005eb7d0
void Render2c5F2990();  // 0x005f2990
void Render2c5F3E80();  // 0x005f3e80
void Render2c5F48E0();  // 0x005f48e0
void Render2c5F5420();  // 0x005f5420
void Render2c5F6730();  // 0x005f6730
void Render2c5F7560();  // 0x005f7560
void Render2c5F7700();  // 0x005f7700
void Render2c5F78A0();  // 0x005f78a0
void Render2c5F7C00();  // 0x005f7c00
void Render2c5F7EC0();  // 0x005f7ec0
void Render2c5F9230();  // 0x005f9230
void Render2c5F98C0();  // 0x005f98c0
void Render2c5FC610();  // 0x005fc610
void Render2c5FC7A0();  // 0x005fc7a0
void Render2c5FD3E0();  // 0x005fd3e0
void Render2c5FDA00();  // 0x005fda00
void Render2c5FE4C0();  // 0x005fe4c0
void Sys2c6000D0();  // 0x006000d0
void Sys2c600500();  // 0x00600500
void Sys2c600800();  // 0x00600800
void Sys2c600990();  // 0x00600990
void Sys2c600A30();  // 0x00600a30
void Sys2c600B40();  // 0x00600b40
void Sys2c601290();  // 0x00601290
void Sys2c601410();  // 0x00601410
void Sys2c601550();  // 0x00601550
void Sys2c601930();  // 0x00601930
void Sys2c603D50();  // 0x00603d50
void Sys2c6067D0();  // 0x006067d0
void Sys2c60BC00();  // 0x0060bc00
void Sys2c60C5D0();  // 0x0060c5d0
void Sys2c60CB60();  // 0x0060cb60
void Sys2c60D870();  // 0x0060d870
void Sys2c60DB80();  // 0x0060db80
void Sys2c60DD70();  // 0x0060dd70
void Sys2c60E2D0();  // 0x0060e2d0
void Sys2c60E370();  // 0x0060e370
void Sys2c60E9E0();  // 0x0060e9e0
void Sys2c60EF70();  // 0x0060ef70
void Sys2c60F450();  // 0x0060f450
void Sys2c60F540();  // 0x0060f540
void Sys2c60F6B0();  // 0x0060f6b0
void Sys2c60FE80();  // 0x0060fe80
void Sys2c612320();  // 0x00612320
void Sys2c613560();  // 0x00613560
void Sys2c613F40();  // 0x00613f40
void Sys2c614FA0();  // 0x00614fa0
void Sys2c615120();  // 0x00615120
void Sys2c6152A0();  // 0x006152a0
void Sys2c615450();  // 0x00615450
void Sys2c6159B0();  // 0x006159b0
void Sys2c617190();  // 0x00617190
void Sys2c6172C0();  // 0x006172c0
void Sys2c6175F0();  // 0x006175f0
void Sys2c619450();  // 0x00619450
void Sys2c61A610();  // 0x0061a610
void Sys2c61A8E0();  // 0x0061a8e0
void Sys2c61AE80();  // 0x0061ae80
void Sys2c61BD30();  // 0x0061bd30
void Sys2c61BEF0();  // 0x0061bef0
void Sys2c61BF10();  // 0x0061bf10
void Sys2c61BFB0();  // 0x0061bfb0
void Sys2c61C300();  // 0x0061c300
void Sys2c61C920();  // 0x0061c920
void Sys2c61CA20();  // 0x0061ca20
void Sys2c61CB40();  // 0x0061cb40
void Sys2c61D070();  // 0x0061d070
void Sys2c61D130();  // 0x0061d130
void Sys2c61D720();  // 0x0061d720
void Sys2c61DA10();  // 0x0061da10
void Sys2c61F690();  // 0x0061f690
void Sys2c61FFC0();  // 0x0061ffc0
void Sys2c6215A0();  // 0x006215a0
void Sys2c6216F0();  // 0x006216f0
void Sys2c621B20();  // 0x00621b20
void Sys2c621D50();  // 0x00621d50
void Sys2c621E30();  // 0x00621e30
void Sys2c6227A0();  // 0x006227a0
void Sys2c623CE0();  // 0x00623ce0
void Sys2c624040();  // 0x00624040
void Sys2c624190();  // 0x00624190
void Sys2c624FB0();  // 0x00624fb0
void Sys2c625D20();  // 0x00625d20
void Sys2c625E30();  // 0x00625e30
void Sys2c625EA0();  // 0x00625ea0
void Sys2c6271C0();  // 0x006271c0
void Sys2c6276C0();  // 0x006276c0
void Sys2c627730();  // 0x00627730
void Sys2c6280B0();  // 0x006280b0
void Sys2c628E20();  // 0x00628e20
void Sys2c628E70();  // 0x00628e70
void Sys2c628E80();  // 0x00628e80
void Sys2c628F60();  // 0x00628f60
void Sys2c6290A0();  // 0x006290a0
void Sys2c62C1E0();  // 0x0062c1e0
void Sys2c62D076();  // 0x0062d076
void Sys2c630EE0();  // 0x00630ee0
void Sys2c630F40();  // 0x00630f40
void Sys2c631AD0();  // 0x00631ad0
void Sys2c631F50();  // 0x00631f50
void crc32();  // 0x006320e4
void Sys2c632440();  // 0x00632440
void Sys2c6326D0();  // 0x006326d0
void Sys2c632A10();  // 0x00632a10
void Sys2c633010();  // 0x00633010
void Sys2c633780();  // 0x00633780
void Sys2c633B90();  // 0x00633b90
void Sys2c633FF0();  // 0x00633ff0
void Sys2c635500();  // 0x00635500
void Sys2c635560();  // 0x00635560
void Sys2c636720();  // 0x00636720
void Sys2c636910();  // 0x00636910
void Sys2c636970();  // 0x00636970
void Sys2c636EE0();  // 0x00636ee0
void Sys2c637D70();  // 0x00637d70
void Sys2c63837C();  // 0x0063837c
void Sys2c638740();  // 0x00638740
void Sys2c6389A0();  // 0x006389a0
void Sys2c63FE60();  // 0x0063fe60
void Create_symlink();  // 0x00641019
void Sys2c6410DE();  // 0x006410de
void Sys2c64112C();  // 0x0064112c
void vcp_Copyfile();  // 0x00641190
void ___std_fs_convert_narrow_to_wide_20();  // 0x00641203
void ___std_fs_convert_wide_to_narrow_20();  // 0x00641237
void Sys2c6412EA();  // 0x006412ea
void Sys2c641359();  // 0x00641359
void Sys2c641575();  // 0x00641575
void Sys2c641A6A();  // 0x00641a6a
void LocalFree();  // 0x00641d1c
void Sys2c641DD5();  // 0x00641dd5
void Sys2c642670();  // 0x00642670
void Sys2c6427E0();  // 0x006427e0
void Sys2c642B90();  // 0x00642b90
void Sys2c642CC0();  // 0x00642cc0
void Sys2c643120();  // 0x00643120
void Sys2c643240();  // 0x00643240
void Sys2c643310();  // 0x00643310
void CrtFreeWrapper();  // 0x00643543 (Ghidra: free)
void Sys2c643793();  // 0x00643793
void __ArrayUnwind();  // 0x00643980
void Sys2c643A10();  // 0x00643a10
void Sys2c643C92();  // 0x00643c92
void Sys2c64442E();  // 0x0064442e
void Sys2c644478();  // 0x00644478
void Sys2c644666();  // 0x00644666
void _callnewh();  // 0x006448ed
void initialize_onexit_table();  // 0x006448ff
void Sys2c6452E0();  // 0x006452e0
void __alloca_probe_16();  // 0x006456b0
void __allrem();  // 0x006456e0
void fdclass();  // 0x00645921
void ldclass();  // 0x00645927

// --- Cycle 58: 1-caller functions (1276 functions) ---
void Core1c42A410();  // 0x0042a410
void Core1c42A6F0();  // 0x0042a6f0
void Core1c42A820();  // 0x0042a820
void Core1c42A8D0();  // 0x0042a8d0
void Core1c42AB00();  // 0x0042ab00
void Core1c42AB50();  // 0x0042ab50
void Core1c42AEC0();  // 0x0042aec0
void Core1c42AF70();  // 0x0042af70
void Core1c42B250();  // 0x0042b250
void Core1c42B330();  // 0x0042b330
void Core1c42B420();  // 0x0042b420
void Core1c42B470();  // 0x0042b470
void Core1c42B760();  // 0x0042b760
void Core1c42BAA0();  // 0x0042baa0
void Core1c42BE10();  // 0x0042be10
void Core1c42BE60();  // 0x0042be60
void Core1c42C240();  // 0x0042c240
void Core1c42C470();  // 0x0042c470
void Core1c42C4C0();  // 0x0042c4c0
void Core1c42C6A0();  // 0x0042c6a0
void Core1c42C890();  // 0x0042c890
void Core1c42CEE0();  // 0x0042cee0
void Core1c42D300();  // 0x0042d300
void Core1c42D380();  // 0x0042d380
void Core1c42D5A0();  // 0x0042d5a0
void Core1c42D7B0();  // 0x0042d7b0
void Core1c42DB50();  // 0x0042db50
void Core1c42E22F();  // 0x0042e22f
void Core1c42F9B0();  // 0x0042f9b0
void Core1c42FB70();  // 0x0042fb70
void Core1c42FBB0();  // 0x0042fbb0
void Core1c42FD68();  // 0x0042fd68
void Core1c4300C0();  // 0x004300c0
void Core1c430720();  // 0x00430720
void Core1c431370();  // 0x00431370
void Core1c4313B0();  // 0x004313b0
void Core1c4313D0();  // 0x004313d0
void Core1c431590();  // 0x00431590
void Core1c431B70();  // 0x00431b70
void Core1c432120();  // 0x00432120
void Core1c4330C0();  // 0x004330c0
void Core1c433AB0();  // 0x00433ab0
void Core1c4344E0();  // 0x004344e0
void Core1c4358B0();  // 0x004358b0
void Core1c435A60();  // 0x00435a60
void Core1c435CD0();  // 0x00435cd0
void Core1c435EE0();  // 0x00435ee0
void Core1c4360F0();  // 0x004360f0
void Core1c4368B0();  // 0x004368b0
void Core1c436AE0();  // 0x00436ae0
void Core1c4373B0();  // 0x004373b0
void Core1c437520();  // 0x00437520
void Core1c4376C0();  // 0x004376c0
void Core1c437970();  // 0x00437970
void Core1c437C60();  // 0x00437c60
void Core1c437F10();  // 0x00437f10
void Core1c438060();  // 0x00438060
void Core1c438380();  // 0x00438380
void Core1c4388A0();  // 0x004388a0
void Core1c438AE0();  // 0x00438ae0
void Core1c438BA0();  // 0x00438ba0
void Core1c438FE0();  // 0x00438fe0
void Core1c439150();  // 0x00439150
void Core1c439250();  // 0x00439250
void Core1c4392B0();  // 0x004392b0
void Core1c439490();  // 0x00439490
void Core1c439730();  // 0x00439730
void Core1c439910();  // 0x00439910
void Core1c439B40();  // 0x00439b40
void Core1c439D20();  // 0x00439d20
void Core1c439F00();  // 0x00439f00
void Core1c43A180();  // 0x0043a180
void Core1c43A3B0();  // 0x0043a3b0
void Core1c43A630();  // 0x0043a630
void Core1c43A860();  // 0x0043a860
void Core1c43AA90();  // 0x0043aa90
void Core1c43AD00();  // 0x0043ad00
void Core1c43B7B0();  // 0x0043b7b0
void Core1c43BBD0();  // 0x0043bbd0
void Core1c43C0D0();  // 0x0043c0d0
void Core1c43CD60();  // 0x0043cd60
void Core1c43CDD0();  // 0x0043cdd0
void Core1c43D4E0();  // 0x0043d4e0
void Core1c43D930();  // 0x0043d930
void Core1c43DAF0();  // 0x0043daf0
void Core1c43DE40();  // 0x0043de40
void Core1c43E000();  // 0x0043e000
void Core1c43E3D0();  // 0x0043e3d0
void Core1c43E400();  // 0x0043e400
void Core1c43F010();  // 0x0043f010
void Core1c440800();  // 0x00440800
void Core1c440BB0();  // 0x00440bb0
void Core1c440CE0();  // 0x00440ce0
void Core1c440D70();  // 0x00440d70
void Core1c440D90();  // 0x00440d90
void Core1c4412E0();  // 0x004412e0
void Core1c4414D0();  // 0x004414d0
void Core1c441C40();  // 0x00441c40
void Core1c442240();  // 0x00442240
void Core1c442520();  // 0x00442520
void Core1c442B00();  // 0x00442b00
void Core1c443180();  // 0x00443180
void Core1c443A20();  // 0x00443a20
void Core1c443C90();  // 0x00443c90
void Core1c443CE0();  // 0x00443ce0
void Core1c444160();  // 0x00444160
void Core1c444EF0();  // 0x00444ef0
void Core1c4456B0();  // 0x004456b0
void Core1c4458D0();  // 0x004458d0
void Core1c445C50();  // 0x00445c50
void Core1c4460C0();  // 0x004460c0
void Core1c446130();  // 0x00446130
void Core1c446500();  // 0x00446500
void Core1c4465E0();  // 0x004465e0
void Core1c446990();  // 0x00446990
void Core1c446CD0();  // 0x00446cd0
void Core1c446E90();  // 0x00446e90
void Core1c4481D0();  // 0x004481d0
void Core1c4485E0();  // 0x004485e0
void Core1c448AD0();  // 0x00448ad0
void Core1c449600();  // 0x00449600
void Core1c44A540();  // 0x0044a540
void Core1c44A770();  // 0x0044a770
void Core1c44A9A0();  // 0x0044a9a0
void Core1c44B4A0();  // 0x0044b4a0
void Core1c44B520();  // 0x0044b520
void Core1c44B750();  // 0x0044b750
void Core1c44B9B0();  // 0x0044b9b0
void Core1c44BC10();  // 0x0044bc10
void Core1c44C230();  // 0x0044c230
void Core1c44C9C0();  // 0x0044c9c0
void Core1c44CBE0();  // 0x0044cbe0
void Core1c44CE30();  // 0x0044ce30
void Core1c44D080();  // 0x0044d080
void Core1c44D230();  // 0x0044d230
void Core1c44D420();  // 0x0044d420
void Core1c44D540();  // 0x0044d540
void Core1c44DCE0();  // 0x0044dce0
void Core1c44DDD0();  // 0x0044ddd0
void Core1c44E090();  // 0x0044e090
void Core1c44E0F0();  // 0x0044e0f0
void Core1c44E320();  // 0x0044e320
void Core1c44E510();  // 0x0044e510
void Core1c44EE80();  // 0x0044ee80
void Core1c44EF40();  // 0x0044ef40
void Core1c44F0F0();  // 0x0044f0f0
void Core1c44F360();  // 0x0044f360
void Core1c44F5D0();  // 0x0044f5d0
void Core1c44F8C0();  // 0x0044f8c0
void Core1c44FB10();  // 0x0044fb10
void Game1c450780();  // 0x00450780
void Game1c450A50();  // 0x00450a50
void Game1c450B00();  // 0x00450b00
void Game1c451050();  // 0x00451050
void Game1c451070();  // 0x00451070
void Game1c451830();  // 0x00451830
void Game1c451880();  // 0x00451880
void Game1c4519E0();  // 0x004519e0
void Game1c452090();  // 0x00452090
void Game1c4520F0();  // 0x004520f0
void Game1c4522F0();  // 0x004522f0
void Game1c452520();  // 0x00452520
void Game1c452B40();  // 0x00452b40
void Game1c453200();  // 0x00453200
void Game1c453250();  // 0x00453250
void Game1c454240();  // 0x00454240
void Game1c4544D0();  // 0x004544d0
void Game1c454520();  // 0x00454520
void Game1c454540();  // 0x00454540
void Game1c4545B0();  // 0x004545b0
void Game1c455370();  // 0x00455370
void Game1c455990();  // 0x00455990
void Game1c456760();  // 0x00456760
void Game1c456820();  // 0x00456820
void Game1c458A40();  // 0x00458a40
void Game1c4597D0();  // 0x004597d0
void Game1c45AB90();  // 0x0045ab90
void Game1c45AC30();  // 0x0045ac30
void Game1c45B190();  // 0x0045b190
void Game1c45B280();  // 0x0045b280
void Game1c45E6A0();  // 0x0045e6a0
void Game1c45EE30();  // 0x0045ee30
void Game1c45F170();  // 0x0045f170
void Game1c45F6E0();  // 0x0045f6e0
void Game1c45F8D0();  // 0x0045f8d0
void Game1c45FED0();  // 0x0045fed0
void Game1c461B10();  // 0x00461b10
void Game1c461B90();  // 0x00461b90
void Game1c461C60();  // 0x00461c60
void Game1c4621F0();  // 0x004621f0
void thunk_FUN_00462510();  // 0x004622b0
void Game1c462910();  // 0x00462910
void Game1c462960();  // 0x00462960
void Game1c462ED0();  // 0x00462ed0
void Game1c463290();  // 0x00463290
void Game1c463E60();  // 0x00463e60
void Game1c464130();  // 0x00464130
void Game1c464290();  // 0x00464290
void Game1c464460();  // 0x00464460
void Game1c464980();  // 0x00464980
void Game1c464B10();  // 0x00464b10
void Game1c465360();  // 0x00465360
void Game1c465520();  // 0x00465520
void Game1c465710();  // 0x00465710
void Game1c465A70();  // 0x00465a70
void Game1c465D30();  // 0x00465d30
void Game1c465FA0();  // 0x00465fa0
void Game1c466240();  // 0x00466240
void Game1c4665F0();  // 0x004665f0
void Game1c466890();  // 0x00466890
void Game1c4680F0();  // 0x004680f0
void Game1c468680();  // 0x00468680
void Game1c468980();  // 0x00468980
void Game1c468AC0();  // 0x00468ac0
void Game1c46CE10();  // 0x0046ce10
void Game1c46D040();  // 0x0046d040
void Game1c46D170();  // 0x0046d170
void Game1c46DA10();  // 0x0046da10
void Game1c46DD40();  // 0x0046dd40
void Game1c46E420();  // 0x0046e420
void Game1c46E530();  // 0x0046e530
void Game1c46E630();  // 0x0046e630
void Game1c46E6E0();  // 0x0046e6e0
void Game1c46EB00();  // 0x0046eb00
void Game1c46ED80();  // 0x0046ed80
void Game1c46FE50();  // 0x0046fe50
void Game1c46FE90();  // 0x0046fe90
void Game1c4700B0();  // 0x004700b0
void Game1c470110();  // 0x00470110
void Game1c470670();  // 0x00470670
void Game1c470E40();  // 0x00470e40
void Game1c471300();  // 0x00471300
void Game1c4714B0();  // 0x004714b0
void Game1c471600();  // 0x00471600
void Game1c471930();  // 0x00471930
void Game1c472040();  // 0x00472040
void Game1c472050();  // 0x00472050
void Game1c472070();  // 0x00472070
void Game1c472210();  // 0x00472210
void Game1c4726B0();  // 0x004726b0
void Game1c472AB0();  // 0x00472ab0
void Game1c472BA0();  // 0x00472ba0
void Game1c472D60();  // 0x00472d60
void Game1c4732C0();  // 0x004732c0
void Game1c473630();  // 0x00473630
void Game1c473C90();  // 0x00473c90
void Game1c473D30();  // 0x00473d30
void Game1c473E90();  // 0x00473e90
void Game1c4740E0();  // 0x004740e0
void Game1c474660();  // 0x00474660
void Game1c474870();  // 0x00474870
void Game1c474BD0();  // 0x00474bd0
void Game1c4750A0();  // 0x004750a0
void Game1c475270();  // 0x00475270
void Game1c476B00();  // 0x00476b00
void Game1c476FC0();  // 0x00476fc0
void Game1c477350();  // 0x00477350
void Game1c477910();  // 0x00477910
void Game1c477B70();  // 0x00477b70
void Game1c478740();  // 0x00478740
void Game1c478B40();  // 0x00478b40
void Game1c479190();  // 0x00479190
void Game1c47BD00();  // 0x0047bd00
void Game1c47BEA0();  // 0x0047bea0
void Game1c47C240();  // 0x0047c240
void Game1c47C300();  // 0x0047c300
void Game1c47C560();  // 0x0047c560
void Game1c47C730();  // 0x0047c730
void Game1c47CB20();  // 0x0047cb20
void Game1c47CDF0();  // 0x0047cdf0
void Game1c47D670();  // 0x0047d670
void Game1c47DD80();  // 0x0047dd80
void Game1c47EC60();  // 0x0047ec60
void Game1c47EE80();  // 0x0047ee80
void Game1c47F1C0();  // 0x0047f1c0
void Game1c47F550();  // 0x0047f550
void Game1c47FB30();  // 0x0047fb30
void Game1c47FDA0();  // 0x0047fda0
void Game1c480090();  // 0x00480090
void Game1c480250();  // 0x00480250
void Game1c4804B0();  // 0x004804b0
void Game1c4805E0();  // 0x004805e0
void Game1c480700();  // 0x00480700
void Game1c4807C0();  // 0x004807c0
void Game1c480AF0();  // 0x00480af0
void Game1c480C90();  // 0x00480c90
void Game1c480E20();  // 0x00480e20
void Game1c480E80();  // 0x00480e80
void Game1c480F30();  // 0x00480f30
void Game1c4811B0();  // 0x004811b0
void Game1c4818F0();  // 0x004818f0
void Game1c481900();  // 0x00481900
void Game1c4819D0();  // 0x004819d0
void Game1c481A90();  // 0x00481a90
void Game1c481AF0();  // 0x00481af0
void Game1c481B60();  // 0x00481b60
void Game1c481BB0();  // 0x00481bb0
void Game1c481D50();  // 0x00481d50
void Game1c481F00();  // 0x00481f00
void Game1c482080();  // 0x00482080
void Game1c483F20();  // 0x00483f20
void Game1c484040();  // 0x00484040
void Game1c485D30();  // 0x00485d30
void Game1c485F40();  // 0x00485f40
void Game1c4864F0();  // 0x004864f0
void Game1c486610();  // 0x00486610
void Game1c486670();  // 0x00486670
void Game1c487170();  // 0x00487170
void Game1c4874D0();  // 0x004874d0
void Game1c487570();  // 0x00487570
void Game1c4875C0();  // 0x004875c0
void Game1c487640();  // 0x00487640
void Game1c487680();  // 0x00487680
void Game1c487710();  // 0x00487710
void Game1c487960();  // 0x00487960
void Game1c487C60();  // 0x00487c60
void Game1c487E20();  // 0x00487e20
void Game1c487F30();  // 0x00487f30
void Game1c487FE0();  // 0x00487fe0
void Game1c488AA0();  // 0x00488aa0
void Game1c489180();  // 0x00489180
void Game1c489470();  // 0x00489470
void Game1c489870();  // 0x00489870
void Game1c48A0E0();  // 0x0048a0e0
void Game1c48AD10();  // 0x0048ad10
void Game1c48AE80();  // 0x0048ae80
void Game1c48AF00();  // 0x0048af00
void Game1c48B150();  // 0x0048b150
void Game1c48BB00();  // 0x0048bb00
void Game1c48BCE0();  // 0x0048bce0
void Game1c48C020();  // 0x0048c020
void Game1c48C350();  // 0x0048c350
void Game1c48C6C0();  // 0x0048c6c0
void Game1c48CB90();  // 0x0048cb90
void Game1c48CCA0();  // 0x0048cca0
void Game1c48CF20();  // 0x0048cf20
void Game1c48D280();  // 0x0048d280
void Game1c48D8B0();  // 0x0048d8b0
void Game1c48DC20();  // 0x0048dc20
void Game1c48DDB0();  // 0x0048ddb0
void Game1c48E960();  // 0x0048e960
void Game1c48F2E0();  // 0x0048f2e0
void Game1c48F820();  // 0x0048f820
void Game1c490800();  // 0x00490800
void Game1c490920();  // 0x00490920
void Game1c490CE0();  // 0x00490ce0
void Game1c491420();  // 0x00491420
void Game1c4943D0();  // 0x004943d0
void Game1c495990();  // 0x00495990
void Game1c495A80();  // 0x00495a80
void Game1c4973C0();  // 0x004973c0
void Game1c4974D0();  // 0x004974d0
void Game1c4975D0();  // 0x004975d0
void Game1c497790();  // 0x00497790
void Game1c497AA0();  // 0x00497aa0
void Game1c497C90();  // 0x00497c90
void Game1c4982D0();  // 0x004982d0
void Game1c4985F0();  // 0x004985f0
void Game1c4987D0();  // 0x004987d0
void Game1c49AD90();  // 0x0049ad90
void Game1c49AE80();  // 0x0049ae80
void Game1c49CAB0();  // 0x0049cab0
void Game1c49CEC0();  // 0x0049cec0
void Game1c49E740();  // 0x0049e740
void Game1c49EBB0();  // 0x0049ebb0
void Game1c49F5B0();  // 0x0049f5b0
void Game1c4A0220();  // 0x004a0220
void Game1c4A09F0();  // 0x004a09f0
void Game1c4A1D60();  // 0x004a1d60
void Game1c4A2440();  // 0x004a2440
void Game1c4A3660();  // 0x004a3660
void Game1c4A3E50();  // 0x004a3e50
void Game1c4A5390();  // 0x004a5390
void Game1c4A5910();  // 0x004a5910
void Game1c4A6420();  // 0x004a6420
void Game1c4A6550();  // 0x004a6550
void Game1c4A8680();  // 0x004a8680
void Game1c4A8BA0();  // 0x004a8ba0
void Game1c4A8D30();  // 0x004a8d30
void Game1c4A8FE0();  // 0x004a8fe0
void Game1c4AA710();  // 0x004aa710
void Game1c4B17C0();  // 0x004b17c0
void Game1c4B3880();  // 0x004b3880
void Game1c4B3C10();  // 0x004b3c10
void Game1c4B3DA7();  // 0x004b3da7
void Game1c4B4690();  // 0x004b4690
void Game1c4B4830();  // 0x004b4830
void Game1c4B4A70();  // 0x004b4a70
void Game1c4B4DE0();  // 0x004b4de0
void Game1c4B5000();  // 0x004b5000
void Game1c4B5150();  // 0x004b5150
void Game1c4B5750();  // 0x004b5750
void Game1c4B5BD0();  // 0x004b5bd0
void Game1c4B5E00();  // 0x004b5e00
void Game1c4B5F50();  // 0x004b5f50
void Game1c4B6DA0();  // 0x004b6da0
void Game1c4B71F0();  // 0x004b71f0
void Game1c4B7510();  // 0x004b7510
void Game1c4B7770();  // 0x004b7770
void Game1c4B7D90();  // 0x004b7d90
void Game1c4B7FD0();  // 0x004b7fd0
void Game1c4B8270();  // 0x004b8270
void Game1c4B8510();  // 0x004b8510
void Game1c4B8C50();  // 0x004b8c50
void Game1c4B8F50();  // 0x004b8f50
void Game1c4B9090();  // 0x004b9090
void Game1c4B9300();  // 0x004b9300
void Game1c4B9580();  // 0x004b9580
void Game1c4B9750();  // 0x004b9750
void Game1c4B9D00();  // 0x004b9d00
void Game1c4BA0A0();  // 0x004ba0a0
void Game1c4BAAD0();  // 0x004baad0
void Game1c4BB1A0();  // 0x004bb1a0
void Game1c4BB470();  // 0x004bb470
void Game1c4BBA90();  // 0x004bba90
void Game1c4BBEE0();  // 0x004bbee0
void Game1c4BC0F0();  // 0x004bc0f0
void Game1c4BC460();  // 0x004bc460
void Game1c4BC790();  // 0x004bc790
void Game1c4BCEE0();  // 0x004bcee0
void Game1c4BD340();  // 0x004bd340
void Game1c4BD870();  // 0x004bd870
void Game1c4BD8E0();  // 0x004bd8e0
void Game1c4BE330();  // 0x004be330
void Game1c4BE850();  // 0x004be850
void Game1c4BE980();  // 0x004be980
void Game1c4BECF0();  // 0x004becf0
void Game1c4BF180();  // 0x004bf180
void Game1c4BF270();  // 0x004bf270
void Game1c4BF300();  // 0x004bf300
void Game1c4BF6F0();  // 0x004bf6f0
void Game1c4BF9E0();  // 0x004bf9e0
void Game1c4BFC50();  // 0x004bfc50
void Game1c4BFED0();  // 0x004bfed0
void Game1c4C0270();  // 0x004c0270
void Game1c4C06F0();  // 0x004c06f0
void Game1c4C0706();  // 0x004c0706
void Game1c4C0970();  // 0x004c0970
void Game1c4C0C04();  // 0x004c0c04
void Game1c4C0C30();  // 0x004c0c30
void Game1c4C0CB0();  // 0x004c0cb0
void Game1c4C0D30();  // 0x004c0d30
void Game1c4C0ED0();  // 0x004c0ed0
void Game1c4C0EF0();  // 0x004c0ef0
void Game1c4C1060();  // 0x004c1060
void Game1c4C14A0();  // 0x004c14a0
void Game1c4C16F0();  // 0x004c16f0
void Game1c4C1730();  // 0x004c1730
void Game1c4C17A0();  // 0x004c17a0
void Game1c4C18C0();  // 0x004c18c0
void Game1c4C18F0();  // 0x004c18f0
void Game1c4C2180();  // 0x004c2180
void Game1c4C2260();  // 0x004c2260
void Game1c4C24B0();  // 0x004c24b0
void thunk_FUN_0042b2c0();  // 0x004c25c0
void Game1c4C2660();  // 0x004c2660
void Game1c4C27A0();  // 0x004c27a0
void Game1c4C2AB0();  // 0x004c2ab0
void Game1c4C2AC0();  // 0x004c2ac0
void Game1c4C3390();  // 0x004c3390
void Game1c4C3580();  // 0x004c3580
void Game1c4C35A0();  // 0x004c35a0
void Game1c4C3B40();  // 0x004c3b40
void Game1c4C3B60();  // 0x004c3b60
void Game1c4C3BE0();  // 0x004c3be0
void Game1c4C3CC0();  // 0x004c3cc0
void Game1c4C3D60();  // 0x004c3d60
void Game1c4C3EF0();  // 0x004c3ef0
void Game1c4C3F70();  // 0x004c3f70
void Game1c4C4430();  // 0x004c4430
void Game1c4C4610();  // 0x004c4610
void Game1c4C4B80();  // 0x004c4b80
void Game1c4C4D50();  // 0x004c4d50
void Game1c4C4ED0();  // 0x004c4ed0
void Game1c4C4F60();  // 0x004c4f60
void Game1c4C52D0();  // 0x004c52d0
void Game1c4C5300();  // 0x004c5300
void Game1c4C5440();  // 0x004c5440
void Game1c4C56A0();  // 0x004c56a0
void Game1c4C58E0();  // 0x004c58e0
void Game1c4C5BF0();  // 0x004c5bf0
void Game1c4C5D10();  // 0x004c5d10
void Game1c4C5E40();  // 0x004c5e40
void Game1c4C5F40();  // 0x004c5f40
void Game1c4C7400();  // 0x004c7400
void Game1c4C75B0();  // 0x004c75b0
void Game1c4C7BC0();  // 0x004c7bc0
void Game1c4C7D60();  // 0x004c7d60
void Game1c4C7F10();  // 0x004c7f10
void Game1c4C80A0();  // 0x004c80a0
void Game1c4C8230();  // 0x004c8230
void Game1c4C84C0();  // 0x004c84c0
void Game1c4C8500();  // 0x004c8500
void Game1c4C9500();  // 0x004c9500
void Game1c4C9AC0();  // 0x004c9ac0
void Game1c4C9B30();  // 0x004c9b30
void Game1c4C9BC0();  // 0x004c9bc0
void Game1c4C9C20();  // 0x004c9c20
void Game1c4CA0C0();  // 0x004ca0c0
void Game1c4CA280();  // 0x004ca280
void Game1c4CA330();  // 0x004ca330
void Game1c4CA6D0();  // 0x004ca6d0
void Game1c4CAB50();  // 0x004cab50
void Game1c4CAED0();  // 0x004caed0
void Game1c4CB200();  // 0x004cb200
void Game1c4CB410();  // 0x004cb410
void Game1c4CB540();  // 0x004cb540
void Game1c4CBB20();  // 0x004cbb20
void Game1c4CBF60();  // 0x004cbf60
void Game1c4CC180();  // 0x004cc180
void Game1c4CC2B0();  // 0x004cc2b0
void Game1c4CCF00();  // 0x004ccf00
void Game1c4CD1E0();  // 0x004cd1e0
void Game1c4CD350();  // 0x004cd350
void Game1c4CD4D0();  // 0x004cd4d0
void Game1c4CD9A0();  // 0x004cd9a0
void Game1c4CDFC0();  // 0x004cdfc0
void Game1c4CE620();  // 0x004ce620
void Game1c4CE7B0();  // 0x004ce7b0
void Game1c4CE8B0();  // 0x004ce8b0
void Game1c4CE9B0();  // 0x004ce9b0
void Game1c4CEB20();  // 0x004ceb20
void Game1c4CEBA0();  // 0x004ceba0
void Game1c4CEBE0();  // 0x004cebe0
void Game1c4CFC10();  // 0x004cfc10
void Game1c4D0210();  // 0x004d0210
void Game1c4D0370();  // 0x004d0370
void Game1c4D0410();  // 0x004d0410
void Game1c4D0870();  // 0x004d0870
void Game1c4D0BA0();  // 0x004d0ba0
void Game1c4D0C20();  // 0x004d0c20
void Game1c4D1210();  // 0x004d1210
void Game1c4D1340();  // 0x004d1340
void Game1c4D1990();  // 0x004d1990
void Game1c4D2410();  // 0x004d2410
void Game1c4D2730();  // 0x004d2730
void Game1c4D2CE0();  // 0x004d2ce0
void Game1c4D2FD0();  // 0x004d2fd0
void Game1c4D3F70();  // 0x004d3f70
void Game1c4D4030();  // 0x004d4030
void Game1c4D4190();  // 0x004d4190
void Game1c4D43A0();  // 0x004d43a0
void Game1c4D48C0();  // 0x004d48c0
void Game1c4D51D0();  // 0x004d51d0
void Game1c4D56C0();  // 0x004d56c0
void Game1c4D67D0();  // 0x004d67d0
void Game1c4D72B0();  // 0x004d72b0
void Game1c4D7B60();  // 0x004d7b60
void Game1c4D92D0();  // 0x004d92d0
void Game1c4DA890();  // 0x004da890
void Game1c4DB280();  // 0x004db280
void Game1c4DBA20();  // 0x004dba20
void Game1c4DBF00();  // 0x004dbf00
void Game1c4DC3D0();  // 0x004dc3d0
void Game1c4DC830();  // 0x004dc830
void Game1c4DDB90();  // 0x004ddb90
void Game1c4DEDD0();  // 0x004dedd0
void Game1c4DFBE0();  // 0x004dfbe0
void Game1c4E0380();  // 0x004e0380
void Game1c4E2590();  // 0x004e2590
void Game1c4E2A00();  // 0x004e2a00
void Game1c4E3640();  // 0x004e3640
void Game1c4E3EF0();  // 0x004e3ef0
void Game1c4E4AA0();  // 0x004e4aa0
void Game1c4E5300();  // 0x004e5300
void Game1c4E58C0();  // 0x004e58c0
void Game1c4E5C20();  // 0x004e5c20
void Game1c4E5CE0();  // 0x004e5ce0
void Game1c4E78A0();  // 0x004e78a0
void Game1c4E90B0();  // 0x004e90b0
void Game1c4EA0F0();  // 0x004ea0f0
void Game1c4EA210();  // 0x004ea210
void Game1c4EA330();  // 0x004ea330
void Game1c4EA5E0();  // 0x004ea5e0
void Game1c4EAB10();  // 0x004eab10
void Game1c4EACC0();  // 0x004eacc0
void Game1c4F1130();  // 0x004f1130
void Game1c4F11E0();  // 0x004f11e0
void Game1c4F3010();  // 0x004f3010
void Game1c4F3D00();  // 0x004f3d00
void Game1c4F4910();  // 0x004f4910
void Game1c4F4A7E();  // 0x004f4a7e
void Game1c4F4CF0();  // 0x004f4cf0
void Game1c4F4ED0();  // 0x004f4ed0
void Game1c4F500B();  // 0x004f500b
void Game1c4F5240();  // 0x004f5240
void Game1c4F53D0();  // 0x004f53d0
void Game1c4F5590();  // 0x004f5590
void Game1c4F55E0();  // 0x004f55e0
void Game1c4F56F0();  // 0x004f56f0
void Game1c4F58F0();  // 0x004f58f0
void Game1c4F6760();  // 0x004f6760
void Game1c4F6940();  // 0x004f6940
void Game1c4F7570();  // 0x004f7570
void _basic_streambuf_char_std__char_traits_char___();  // 0x004f77a0
void Game1c4F7850();  // 0x004f7850
void Game1c4F7A60();  // 0x004f7a60
void Game1c4F8310();  // 0x004f8310
void Game1c4F9560();  // 0x004f9560
void Game1c4FA9F0();  // 0x004fa9f0
void Game1c4FE110();  // 0x004fe110
void Game1c4FE1B0();  // 0x004fe1b0
void Game1c4FE290();  // 0x004fe290
void Game1c4FE630();  // 0x004fe630
void Game1c4FE730();  // 0x004fe730
void Game1c4FEA40();  // 0x004fea40
void Render1c501740();  // 0x00501740
void Render1c5033D0();  // 0x005033d0
void Render1c506B90();  // 0x00506b90
void Render1c506F00();  // 0x00506f00
void Render1c507A80();  // 0x00507a80
void Render1c508430();  // 0x00508430
void Render1c508590();  // 0x00508590
void Render1c5091D0();  // 0x005091d0
void Render1c509540();  // 0x00509540
void Render1c509A20();  // 0x00509a20
void Render1c50A1D0();  // 0x0050a1d0
void Render1c50BBB0();  // 0x0050bbb0
void Render1c50C190();  // 0x0050c190
void Render1c50CCD0();  // 0x0050ccd0
void Render1c50CFC0();  // 0x0050cfc0
void Render1c5145F0();  // 0x005145f0
void Render1c5154B0();  // 0x005154b0
void Render1c515720();  // 0x00515720
void Render1c515A10();  // 0x00515a10
void Render1c515E40();  // 0x00515e40
void Render1c5197D0();  // 0x005197d0
void Render1c519B90();  // 0x00519b90
void Render1c519E60();  // 0x00519e60
void Render1c51AEB0();  // 0x0051aeb0
void Render1c51AFA0();  // 0x0051afa0
void Render1c51B290();  // 0x0051b290
void Render1c51F9F0();  // 0x0051f9f0
void Render1c51FCB0();  // 0x0051fcb0
void Render1c5203C0();  // 0x005203c0
void Render1c522A10();  // 0x00522a10
void Render1c522C80();  // 0x00522c80
void Render1c5272B0();  // 0x005272b0
void Render1c527CF0();  // 0x00527cf0
void Render1c52AD50();  // 0x0052ad50
void Render1c52B280();  // 0x0052b280
void Render1c52B950();  // 0x0052b950
void Render1c52D4D0();  // 0x0052d4d0
void Render1c52DEF0();  // 0x0052def0
void Render1c531A80();  // 0x00531a80
void Render1c531B50();  // 0x00531b50
void Render1c531F80();  // 0x00531f80
void Render1c5322B0();  // 0x005322b0
void Render1c5329E0();  // 0x005329e0
void Render1c534FA0();  // 0x00534fa0
void Render1c535AF0();  // 0x00535af0
void Render1c536B20();  // 0x00536b20
void Render1c536CE0();  // 0x00536ce0
void Render1c538EB0();  // 0x00538eb0
void Render1c5390A0();  // 0x005390a0
void Render1c539BD0();  // 0x00539bd0
void Render1c53A780();  // 0x0053a780
void Render1c53A930();  // 0x0053a930
void Render1c53AB40();  // 0x0053ab40
void Render1c53B5D0();  // 0x0053b5d0
void Render1c53BDA0();  // 0x0053bda0
void Render1c53BF20();  // 0x0053bf20
void Render1c53C390();  // 0x0053c390
void Render1c53C710();  // 0x0053c710
void Render1c53CBA0();  // 0x0053cba0
void Render1c53CF00();  // 0x0053cf00
void Render1c53D120();  // 0x0053d120
void Render1c53D3E0();  // 0x0053d3e0
void Render1c53EC90();  // 0x0053ec90
void Render1c53EDD0();  // 0x0053edd0
void Render1c53F2A0();  // 0x0053f2a0
void Render1c542330();  // 0x00542330
void Render1c5430D0();  // 0x005430d0
void Render1c543190();  // 0x00543190
void Render1c543CB0();  // 0x00543cb0
void Render1c544680();  // 0x00544680
void Render1c5447C0();  // 0x005447c0
void Render1c545380();  // 0x00545380
void Render1c545580();  // 0x00545580
void Render1c545A80();  // 0x00545a80
void Render1c546700();  // 0x00546700
void Render1c5467F0();  // 0x005467f0
void Render1c5474A0();  // 0x005474a0
void Render1c5475A0();  // 0x005475a0
void Render1c548260();  // 0x00548260
void Render1c548360();  // 0x00548360
void Render1c5486A0();  // 0x005486a0
void Render1c549000();  // 0x00549000
void Render1c549B00();  // 0x00549b00
void Render1c54B090();  // 0x0054b090
void Render1c54B3C0();  // 0x0054b3c0
void Render1c54B780();  // 0x0054b780
void Render1c54E0C0();  // 0x0054e0c0
void Render1c54E2A0();  // 0x0054e2a0
void Render1c54FC80();  // 0x0054fc80
void Render1c550890();  // 0x00550890
void Render1c550F00();  // 0x00550f00
void Render1c551AE0();  // 0x00551ae0
void Render1c551B40();  // 0x00551b40
void Render1c552CC0();  // 0x00552cc0
void Render1c553E20();  // 0x00553e20
void Render1c554610();  // 0x00554610
void Render1c554AA7();  // 0x00554aa7
void Render1c554E70();  // 0x00554e70
void Render1c557020();  // 0x00557020
void Render1c557800();  // 0x00557800
void Render1c557960();  // 0x00557960
void Render1c5593D0();  // 0x005593d0
void Render1c55A0C0();  // 0x0055a0c0
void Render1c55A8E0();  // 0x0055a8e0
void Render1c55A940();  // 0x0055a940
void Render1c55AAA0();  // 0x0055aaa0
void Render1c55B020();  // 0x0055b020
void Render1c55B810();  // 0x0055b810
void Render1c55CF40();  // 0x0055cf40
void Render1c55F900();  // 0x0055f900
void Render1c562000();  // 0x00562000
void Render1c563AA0();  // 0x00563aa0
void Render1c564140();  // 0x00564140
void Render1c564300();  // 0x00564300
void Render1c565470();  // 0x00565470
void Render1c5659D0();  // 0x005659d0
void Render1c567150();  // 0x00567150
void Render1c5672C0();  // 0x005672c0
void Render1c5687D0();  // 0x005687d0
void Render1c568EC0();  // 0x00568ec0
void Render1c569A80();  // 0x00569a80
void Render1c56AFE0();  // 0x0056afe0
void Render1c56B260();  // 0x0056b260
void Render1c56D370();  // 0x0056d370
void Render1c56DBB0();  // 0x0056dbb0
void Render1c56EAD0();  // 0x0056ead0
void Render1c56ECB0();  // 0x0056ecb0
void Render1c570CC0();  // 0x00570cc0
void Render1c5755D0();  // 0x005755d0
void Render1c575A10();  // 0x00575a10
void Render1c5762A0();  // 0x005762a0
void Render1c5790E0();  // 0x005790e0
void Render1c57CA20();  // 0x0057ca20
void Render1c57E4B0();  // 0x0057e4b0
void Render1c57E920();  // 0x0057e920
void Render1c57EB60();  // 0x0057eb60
void Render1c580BB0();  // 0x00580bb0
void Render1c581570();  // 0x00581570
void Render1c5819A0();  // 0x005819a0
void Render1c582D70();  // 0x00582d70
void Render1c583020();  // 0x00583020
void Render1c584760();  // 0x00584760
void Render1c5865A0();  // 0x005865a0
void Render1c586820();  // 0x00586820
void Render1c586BA0();  // 0x00586ba0
void Render1c5875C0();  // 0x005875c0
void Render1c587DA0();  // 0x00587da0
void Render1c588CB0();  // 0x00588cb0
void Render1c589590();  // 0x00589590
void Render1c58A850();  // 0x0058a850
void Render1c58AA50();  // 0x0058aa50
void Render1c58AC20();  // 0x0058ac20
void Render1c58ACD0();  // 0x0058acd0
void Render1c58AF70();  // 0x0058af70
void Render1c58B020();  // 0x0058b020
void Render1c58B2E0();  // 0x0058b2e0
void Render1c58B590();  // 0x0058b590
void Render1c58B750();  // 0x0058b750
void Render1c58B800();  // 0x0058b800
void Render1c58BA60();  // 0x0058ba60
void Render1c58BB10();  // 0x0058bb10
void Render1c58BBC0();  // 0x0058bbc0
void Render1c58BD30();  // 0x0058bd30
void Render1c58BF30();  // 0x0058bf30
void Render1c58BFE0();  // 0x0058bfe0
void Render1c58C170();  // 0x0058c170
void Render1c58C220();  // 0x0058c220
void Render1c58CA20();  // 0x0058ca20
void Render1c58CC80();  // 0x0058cc80
void Render1c58CD20();  // 0x0058cd20
void Render1c58D360();  // 0x0058d360
void Render1c58D720();  // 0x0058d720
void Render1c58DE90();  // 0x0058de90
void Render1c58E090();  // 0x0058e090
void Render1c58E2A0();  // 0x0058e2a0
void Render1c590730();  // 0x00590730
void Render1c590BF0();  // 0x00590bf0
void Render1c590F80();  // 0x00590f80
void Render1c5912A0();  // 0x005912a0
void Render1c591730();  // 0x00591730
void Render1c591F20();  // 0x00591f20
void Render1c592080();  // 0x00592080
void Render1c592270();  // 0x00592270
void Render1c5925F0();  // 0x005925f0
void Render1c5931C0();  // 0x005931c0
void Render1c594660();  // 0x00594660
void Render1c595170();  // 0x00595170
void Render1c595460();  // 0x00595460
void Render1c5955E0();  // 0x005955e0
void Render1c595C60();  // 0x00595c60
void Render1c59BE30();  // 0x0059be30
void Render1c59DF40();  // 0x0059df40
void Render1c59E180();  // 0x0059e180
void Render1c59FC80();  // 0x0059fc80
void Render1c59FEC0();  // 0x0059fec0
void Render1c5A0650();  // 0x005a0650
void Render1c5A1600();  // 0x005a1600
void Render1c5A2B00();  // 0x005a2b00
void Render1c5A3F20();  // 0x005a3f20
void Render1c5A5590();  // 0x005a5590
void Render1c5A7960();  // 0x005a7960
void Render1c5A7CB0();  // 0x005a7cb0
void Render1c5A8660();  // 0x005a8660
void Render1c5A9580();  // 0x005a9580
void Render1c5AA800();  // 0x005aa800
void Render1c5AAE50();  // 0x005aae50
void Render1c5AB410();  // 0x005ab410
void Render1c5AC9F0();  // 0x005ac9f0
void Render1c5ACA20();  // 0x005aca20
void Render1c5AEA50();  // 0x005aea50
void Render1c5AF410();  // 0x005af410
void Render1c5B0AC0();  // 0x005b0ac0
void Render1c5B10C0();  // 0x005b10c0
void Render1c5B3070();  // 0x005b3070
void Render1c5B3230();  // 0x005b3230
void Render1c5B3AF0();  // 0x005b3af0
void Render1c5B3F50();  // 0x005b3f50
void Render1c5B3F90();  // 0x005b3f90
void Render1c5B4D30();  // 0x005b4d30
void Render1c5C0310();  // 0x005c0310
void Render1c5C05C0();  // 0x005c05c0
void Render1c5C0770();  // 0x005c0770
void Render1c5C0920();  // 0x005c0920
void Render1c5C0AD0();  // 0x005c0ad0
void Render1c5C0B70();  // 0x005c0b70
void Render1c5C0C80();  // 0x005c0c80
void Render1c5C0EF0();  // 0x005c0ef0
void Render1c5C12B0();  // 0x005c12b0
void Render1c5C1490();  // 0x005c1490
void Render1c5C16F0();  // 0x005c16f0
void Render1c5C43D0();  // 0x005c43d0
void Render1c5C4400();  // 0x005c4400
void Render1c5C54B0();  // 0x005c54b0
void Render1c5C5560();  // 0x005c5560
void Render1c5C5C00();  // 0x005c5c00
void Render1c5C5E30();  // 0x005c5e30
void Render1c5C60F0();  // 0x005c60f0
void Render1c5CC670();  // 0x005cc670
void Render1c5CD1A0();  // 0x005cd1a0
void Render1c5CD1E0();  // 0x005cd1e0
void Render1c5CE760();  // 0x005ce760
void Render1c5CEC70();  // 0x005cec70
void Render1c5CF480();  // 0x005cf480
void Render1c5D0B90();  // 0x005d0b90
void Render1c5D1560();  // 0x005d1560
void Render1c5D1E20();  // 0x005d1e20
void Render1c5D3E20();  // 0x005d3e20
void Render1c5D4200();  // 0x005d4200
void Render1c5D45C0();  // 0x005d45c0
void Render1c5D4A10();  // 0x005d4a10
void Render1c5D4D50();  // 0x005d4d50
void Render1c5D5D10();  // 0x005d5d10
void Render1c5D77E0();  // 0x005d77e0
void Render1c5DC960();  // 0x005dc960
void Render1c5DD970();  // 0x005dd970
void Render1c5DF200();  // 0x005df200
void Render1c5DF640();  // 0x005df640
void Render1c5DFCD0();  // 0x005dfcd0
void Render1c5E0440();  // 0x005e0440
void Render1c5E12B0();  // 0x005e12b0
void Render1c5E2020();  // 0x005e2020
void Render1c5E2400();  // 0x005e2400
void Render1c5E4910();  // 0x005e4910
void Render1c5E8380();  // 0x005e8380
void Render1c5E8530();  // 0x005e8530
void Render1c5E87B0();  // 0x005e87b0
void Render1c5E87D0();  // 0x005e87d0
void Render1c5E8A10();  // 0x005e8a10
void Render1c5E8CB0();  // 0x005e8cb0
void Render1c5EB2F0();  // 0x005eb2f0
void Render1c5EBC00();  // 0x005ebc00
void Render1c5EBF40();  // 0x005ebf40
void Render1c5EE000();  // 0x005ee000
void Render1c5EE840();  // 0x005ee840
void Render1c5EEFC0();  // 0x005eefc0
void Render1c5F0C00();  // 0x005f0c00
void Render1c5F10B0();  // 0x005f10b0
void Render1c5F1260();  // 0x005f1260
void Render1c5F1340();  // 0x005f1340
void Render1c5F1440();  // 0x005f1440
void Render1c5F1600();  // 0x005f1600
void Render1c5F2B30();  // 0x005f2b30
void Render1c5F2DA0();  // 0x005f2da0
void Render1c5F3440();  // 0x005f3440
void Render1c5F36F0();  // 0x005f36f0
void Render1c5F41E0();  // 0x005f41e0
void Render1c5F5330();  // 0x005f5330
void Render1c5F5880();  // 0x005f5880
void Render1c5F6510();  // 0x005f6510
void Render1c5F67F0();  // 0x005f67f0
void Render1c5F6CE0();  // 0x005f6ce0
void Render1c5F83C0();  // 0x005f83c0
void Render1c5F8C90();  // 0x005f8c90
void Render1c5F8F40();  // 0x005f8f40
void Render1c5F93B0();  // 0x005f93b0
void Render1c5F94E0();  // 0x005f94e0
void Render1c5F9720();  // 0x005f9720
void Render1c5FB140();  // 0x005fb140
void Render1c5FBDA0();  // 0x005fbda0
void Render1c5FC6D0();  // 0x005fc6d0
void Render1c5FCB50();  // 0x005fcb50
void Render1c5FCD60();  // 0x005fcd60
void Render1c5FCE60();  // 0x005fce60
void Render1c5FD070();  // 0x005fd070
void Render1c5FDC80();  // 0x005fdc80
void Render1c5FDF60();  // 0x005fdf60
void Render1c5FDFA0();  // 0x005fdfa0
void Render1c5FE110();  // 0x005fe110
void Render1c5FE2F0();  // 0x005fe2f0
void Render1c5FE4F0();  // 0x005fe4f0
void thunk_FUN_00600990();  // 0x005fe630
void Render1c5FE640();  // 0x005fe640
void Render1c5FE72B();  // 0x005fe72b
void Render1c5FEC96();  // 0x005fec96
void Render1c5FFF60();  // 0x005fff60
void Sys1c600450();  // 0x00600450
void Sys1c600610();  // 0x00600610
void Sys1c600750();  // 0x00600750
void Sys1c600850();  // 0x00600850
void Sys1c6009D0();  // 0x006009d0
void Sys1c600BB0();  // 0x00600bb0
void Sys1c600C60();  // 0x00600c60
void Sys1c600C80();  // 0x00600c80
void Sys1c6010F0();  // 0x006010f0
void Sys1c601210();  // 0x00601210
void Sys1c601740();  // 0x00601740
void Sys1c601A90();  // 0x00601a90
void Sys1c60276C();  // 0x0060276c
void Sys1c603270();  // 0x00603270
void Sys1c60351D();  // 0x0060351d
void Sys1c603610();  // 0x00603610
void Sys1c603910();  // 0x00603910
void Sys1c603A00();  // 0x00603a00
void Sys1c603C00();  // 0x00603c00
void Sys1c603F30();  // 0x00603f30
void Sys1c603FE0();  // 0x00603fe0
void Sys1c6041A0();  // 0x006041a0
void Sys1c6041F0();  // 0x006041f0
void Sys1c604240();  // 0x00604240
void Sys1c604440();  // 0x00604440
void Sys1c604600();  // 0x00604600
void Sys1c604720();  // 0x00604720
void Sys1c604B20();  // 0x00604b20
void Sys1c604B60();  // 0x00604b60
void Sys1c604C10();  // 0x00604c10
void Sys1c604DC0();  // 0x00604dc0
void Sys1c604FF0();  // 0x00604ff0
void Sys1c605570();  // 0x00605570
void Sys1c6055D0();  // 0x006055d0
void Sys1c605AA0();  // 0x00605aa0
void Sys1c605AB0();  // 0x00605ab0
void Sys1c605AC0();  // 0x00605ac0
void Sys1c606920();  // 0x00606920
void Sys1c607220();  // 0x00607220
void Sys1c607400();  // 0x00607400
void Sys1c607650();  // 0x00607650
void Sys1c608020();  // 0x00608020
void Sys1c608E70();  // 0x00608e70
void Sys1c60B380();  // 0x0060b380
void Sys1c60B500();  // 0x0060b500
void Sys1c60B7B0();  // 0x0060b7b0
void Sys1c60B980();  // 0x0060b980
void Sys1c60BE40();  // 0x0060be40
void Sys1c60CDA0();  // 0x0060cda0
void Sys1c60CF90();  // 0x0060cf90
void Sys1c60D180();  // 0x0060d180
void Sys1c60D5F0();  // 0x0060d5f0
void Sys1c60D9D0();  // 0x0060d9d0
void Sys1c60DA20();  // 0x0060da20
void Sys1c60DE40();  // 0x0060de40
void Sys1c60E490();  // 0x0060e490
void Sys1c60E650();  // 0x0060e650
void Sys1c60EAD0();  // 0x0060ead0
void Sys1c60EDB0();  // 0x0060edb0
void Sys1c60F1E0();  // 0x0060f1e0
void Sys1c60F6A0();  // 0x0060f6a0
void Sys1c60F6E0();  // 0x0060f6e0
void Sys1c60FAE0();  // 0x0060fae0
void Sys1c60FCC0();  // 0x0060fcc0
void Sys1c60FEF0();  // 0x0060fef0
void Sys1c6100F0();  // 0x006100f0
void Sys1c610860();  // 0x00610860
void Sys1c610A40();  // 0x00610a40
void Sys1c6114F0();  // 0x006114f0
void Sys1c611780();  // 0x00611780
void Sys1c6119B0();  // 0x006119b0
void Sys1c611B60();  // 0x00611b60
void Sys1c611D90();  // 0x00611d90
void Sys1c611FC0();  // 0x00611fc0
void Sys1c612170();  // 0x00612170
void Sys1c6124D0();  // 0x006124d0
void Sys1c612670();  // 0x00612670
void Sys1c6127B0();  // 0x006127b0
void Sys1c612960();  // 0x00612960
void Sys1c6134B0();  // 0x006134b0
void Sys1c613CD0();  // 0x00613cd0
void Sys1c6141B0();  // 0x006141b0
void Sys1c615780();  // 0x00615780
void Sys1c615830();  // 0x00615830
void Sys1c615850();  // 0x00615850
void Sys1c615900();  // 0x00615900
void Sys1c615FF0();  // 0x00615ff0
void Sys1c616220();  // 0x00616220
void Sys1c6163B0();  // 0x006163b0
void Sys1c616540();  // 0x00616540
void Sys1c616690();  // 0x00616690
void Sys1c616740();  // 0x00616740
void Sys1c616910();  // 0x00616910
void Sys1c616C40();  // 0x00616c40
void Sys1c616DE0();  // 0x00616de0
void Sys1c616F80();  // 0x00616f80
void Sys1c617410();  // 0x00617410
void Sys1c617850();  // 0x00617850
void Sys1c617A30();  // 0x00617a30
void Sys1c617BC0();  // 0x00617bc0
void Sys1c617CD0();  // 0x00617cd0
void Sys1c617EA0();  // 0x00617ea0
void Sys1c618070();  // 0x00618070
void Sys1c618240();  // 0x00618240
void Sys1c618430();  // 0x00618430
void Sys1c6186A0();  // 0x006186a0
void Sys1c618910();  // 0x00618910
void Sys1c618B80();  // 0x00618b80
void Sys1c618C10();  // 0x00618c10
void Sys1c618CA0();  // 0x00618ca0
void Sys1c619510();  // 0x00619510
void Sys1c619940();  // 0x00619940
void Sys1c619A70();  // 0x00619a70
void Sys1c619C50();  // 0x00619c50
void Sys1c619E30();  // 0x00619e30
void Sys1c61A240();  // 0x0061a240
void Sys1c61A2B0();  // 0x0061a2b0
void Sys1c61A5B0();  // 0x0061a5b0
void Sys1c61A720();  // 0x0061a720
void Sys1c61A880();  // 0x0061a880
void Sys1c61AAE0();  // 0x0061aae0
void Sys1c61B130();  // 0x0061b130
void Sys1c61B1A0();  // 0x0061b1a0
void Sys1c61B1C0();  // 0x0061b1c0
void Sys1c61BCA0();  // 0x0061bca0
void Sys1c61C330();  // 0x0061c330
void Sys1c61C500();  // 0x0061c500
void Sys1c61C5B0();  // 0x0061c5b0
void Sys1c61C600();  // 0x0061c600
void Sys1c61C7F0();  // 0x0061c7f0
void Sys1c61C850();  // 0x0061c850
void Sys1c61C8B0();  // 0x0061c8b0
void Sys1c61C9C0();  // 0x0061c9c0
void Sys1c61CEB0();  // 0x0061ceb0
void Sys1c61CF20();  // 0x0061cf20
void Sys1c61D0D0();  // 0x0061d0d0
void Sys1c61D0E0();  // 0x0061d0e0
void Sys1c61D1C1();  // 0x0061d1c1
void Sys1c61D1E0();  // 0x0061d1e0
void Sys1c61D250();  // 0x0061d250
void Sys1c61D920();  // 0x0061d920
void Sys1c61DAE0();  // 0x0061dae0
void Sys1c61DB50();  // 0x0061db50
void Sys1c61DBE0();  // 0x0061dbe0
void Sys1c61DFF0();  // 0x0061dff0
void Sys1c61EA40();  // 0x0061ea40
void Sys1c61F1E0();  // 0x0061f1e0
void Sys1c61F270();  // 0x0061f270
void Sys1c61F560();  // 0x0061f560
void Sys1c61F600();  // 0x0061f600
void Sys1c61F6B0();  // 0x0061f6b0
void Sys1c61F750();  // 0x0061f750
void Sys1c61F7F0();  // 0x0061f7f0
void Sys1c61F860();  // 0x0061f860
void Sys1c620140();  // 0x00620140
void Sys1c620360();  // 0x00620360
void Sys1c620A40();  // 0x00620a40
void Sys1c620D30();  // 0x00620d30
void Sys1c620F20();  // 0x00620f20
void Sys1c6212A0();  // 0x006212a0
void Sys1c621430();  // 0x00621430
void Sys1c6217C0();  // 0x006217c0
void Sys1c6233F0();  // 0x006233f0
void Sys1c6235A0();  // 0x006235a0
void Sys1c6243C0();  // 0x006243c0
void Sys1c625600();  // 0x00625600
void Sys1c6256C0();  // 0x006256c0
void Sys1c625740();  // 0x00625740
void Sys1c6257E0();  // 0x006257e0
void Sys1c625890();  // 0x00625890
void Sys1c625910();  // 0x00625910
void Sys1c625C80();  // 0x00625c80
void Sys1c625D60();  // 0x00625d60
void Sys1c625E60();  // 0x00625e60
void Sys1c625E80();  // 0x00625e80
void Sys1c625EE0();  // 0x00625ee0
void Sys1c625F20();  // 0x00625f20
void Sys1c625F60();  // 0x00625f60
void Sys1c6260E0();  // 0x006260e0
void Sys1c6264C0();  // 0x006264c0
void Sys1c626700();  // 0x00626700
void Sys1c626940();  // 0x00626940
void Sys1c626B80();  // 0x00626b80
void Sys1c626DC0();  // 0x00626dc0
void Sys1c627AE0();  // 0x00627ae0
void Sys1c627CD0();  // 0x00627cd0
void Sys1c627EC0();  // 0x00627ec0
void Sys1c6283D0();  // 0x006283d0
void Sys1c628600();  // 0x00628600
void Sys1c628C50();  // 0x00628c50
void Sys1c628E00();  // 0x00628e00
void Sys1c628E90();  // 0x00628e90
void Sys1c6291C0();  // 0x006291c0
void Sys1c6297A0();  // 0x006297a0
void Sys1c629860();  // 0x00629860
void Sys1c629900();  // 0x00629900
void Sys1c62A380();  // 0x0062a380
void Sys1c62B930();  // 0x0062b930
void Sys1c62C720();  // 0x0062c720
void Sys1c62FDC0();  // 0x0062fdc0
void Sys1c6305B0();  // 0x006305b0
void Sys1c630E70();  // 0x00630e70
void Sys1c631030();  // 0x00631030
void Sys1c631480();  // 0x00631480
void Sys1c631E80();  // 0x00631e80
void Sys1c631EE0();  // 0x00631ee0
void Sys1c631FB0();  // 0x00631fb0
void inflateEnd();  // 0x006320d8
void inflate();  // 0x006320de
void inflateInit2_();  // 0x006320ea
void get_crc_table();  // 0x006320f0
void Sys1c632200();  // 0x00632200
void Sys1c6324C0();  // 0x006324c0
void Sys1c632760();  // 0x00632760
void Sys1c6339F0();  // 0x006339f0
void Sys1c633A90();  // 0x00633a90
void Sys1c6346D0();  // 0x006346d0
void Sys1c634880();  // 0x00634880
void Sys1c6355B0();  // 0x006355b0
void Sys1c6355F0();  // 0x006355f0
void Sys1c635620();  // 0x00635620
void Sys1c635E10();  // 0x00635e10
void Sys1c635F80();  // 0x00635f80
void Sys1c636400();  // 0x00636400
void Sys1c6369D0();  // 0x006369d0
void Sys1c636AC0();  // 0x00636ac0
void Sys1c636C50();  // 0x00636c50
void Sys1c636CA0();  // 0x00636ca0
void Sys1c636F80();  // 0x00636f80
void Sys1c636FE0();  // 0x00636fe0
void Sys1c637010();  // 0x00637010
void Sys1c637030();  // 0x00637030
void Sys1c6370C0();  // 0x006370c0
void Sys1c637BB3();  // 0x00637bb3
void Sys1c638610();  // 0x00638610
void Sys1c638680();  // 0x00638680
void Sys1c638B40();  // 0x00638b40
void Sys1c63A560();  // 0x0063a560
void Sys1c63CE30();  // 0x0063ce30
void Sys1c63E200();  // 0x0063e200
void Sys1c63EF10();  // 0x0063ef10
void Sys1c63EF30();  // 0x0063ef30
void Sys1c63EFB0();  // 0x0063efb0
void Sys1c63EFF0();  // 0x0063eff0
void Sys1c63F8F0();  // 0x0063f8f0
void Sys1c63FA50();  // 0x0063fa50
void Sys1c63FC00();  // 0x0063fc00
void Sys1c6401C0();  // 0x006401c0
void Sys1c6402F0();  // 0x006402f0
void Sys1c640400();  // 0x00640400
void Sys1c6404D0();  // 0x006404d0
void DebugBreak();  // 0x006409f0
void Sys1c640AC0();  // 0x00640ac0
void Sys1c640AD0();  // 0x00640ad0
void Sys1c640B10();  // 0x00640b10
void Sys1c640C90();  // 0x00640c90
void Sys1c640CF0();  // 0x00640cf0
void Sys1c640D40();  // 0x00640d40
void Sys1c640E70();  // 0x00640e70
void Sys1c640EB0();  // 0x00640eb0
void Sys1c640F60();  // 0x00640f60
void _Xlength_error();  // 0x0064100d
void _Xbad_function_call();  // 0x00641013
void ___std_fs_create_directory_symbolic_link_8();  // 0x0064154d
void ___std_fs_create_symbolic_link_8();  // 0x00641561
void ___std_fs_directory_iterator_open_12();  // 0x006415b6
void Sys1c6415ED();  // 0x006415ed
void ___std_fs_get_file_attributes_by_handle_8();  // 0x006416c6
void Sys1c641998();  // 0x00641998
void Sys1c6419DF();  // 0x006419df
void Sys1c641C49();  // 0x00641c49
void Sys1c641C7E();  // 0x00641c7e
void Sys1c641CA2();  // 0x00641ca2
void __Fac_node();  // 0x00641d58
void Sys1c641E10();  // 0x00641e10
void Sys1c641E40();  // 0x00641e40
void Sys1c6420C0();  // 0x006420c0
void Sys1c642280();  // 0x00642280
void Sys1c6424A0();  // 0x006424a0
void Sys1c642890();  // 0x00642890
void Sys1c642DD0();  // 0x00642dd0
void Sys1c642EF0();  // 0x00642ef0
void Sys1c643180();  // 0x00643180
void Sys1c6431E0();  // 0x006431e0
void Sys1c643320();  // 0x00643320
void Sys1c6433B0();  // 0x006433b0
void Sys1c6433F0();  // 0x006433f0
void Sys1c643400();  // 0x00643400
void _Xbad_alloc();  // 0x00643409
void Sys1c64340F();  // 0x0064340f
void Sys1c643432();  // 0x00643432
void Sys1c6434B6();  // 0x006434b6
void CrtAbort();  // 0x006434f1 (Ghidra: abort)
void Sys1c64364A();  // 0x0064364a
void Sys1c64365F();  // 0x0064365f
void ___scrt_acquire_startup_lock();  // 0x006436a1
void ___scrt_initialize_crt();  // 0x006436d3
void ___scrt_release_startup_lock();  // 0x0064382a
void ___scrt_uninitialize_crt();  // 0x00643847
void Sys1c64386F();  // 0x0064386f
void Sys1c643970();  // 0x00643970
void Sys1c643B40();  // 0x00643b40
void Sys1c643C70();  // 0x00643c70
void Sys1c643CD5();  // 0x00643cd5
void Sys1c644030();  // 0x00644030
void Sys1c644076();  // 0x00644076
void Sys1c6440B0();  // 0x006440b0
void Sys1c6440F6();  // 0x006440f6
void Sys1c644410();  // 0x00644410
void Sys1c6445C2();  // 0x006445c2
void Sys1c644610();  // 0x00644610
void __except_handler4();  // 0x006446c5
void operator_delete();  // 0x006446f4
void Sys1c644702();  // 0x00644702
void ___security_init_cookie();  // 0x0064474f
void Sys1c6447F9();  // 0x006447f9
void Sys1c6447FF();  // 0x006447ff
void __current_exception();  // 0x0064488d
void __current_exception_context();  // 0x00644893
void except_handler4_common();  // 0x00644899
void Crt_malloc();  // 0x0064489f
void Crt_free();  // 0x006448a5
void terminate();  // 0x006448ab
void roundf();  // 0x006448b1
void libm_sse2_asin_precise();  // 0x006448d5
void libm_sse2_tan_precise();  // 0x006448e1
void register_onexit_function();  // 0x00644905
void crt_atexit();  // 0x0064490b
void _cexit();  // 0x00644911
void CrtAlignedMalloc();  // 0x00644917 (Ghidra: _aligned_malloc)
char* get_narrow_winmain_command_line();  // 0x0064492f
void initterm();  // 0x00644935
void initterm_e();  // 0x0064493b
void CrtExit();  // 0x00644941 (Ghidra: exit)
void register_thread_local_exe_atexit_callback();  // 0x00644959
void _aligned_free();  // 0x00644971
void SHGetKnownFolderPath();  // 0x0064497d
void Sys1c644990();  // 0x00644990
void Sys1c644B20();  // 0x00644b20
void Sys1c644B50();  // 0x00644b50
void Sys1c644C50();  // 0x00644c50
void Sys1c644E40();  // 0x00644e40
void Sys1c644E90();  // 0x00644e90
void Sys1c645200();  // 0x00645200
void Sys1c645464();  // 0x00645464
void __alldvrm();  // 0x00645590
void thunk_FUN_006457f0();  // 0x006457e0
void Sys1c6457F0();  // 0x006457f0
void Sys1c645870();  // 0x00645870
void Sys1c64588E();  // 0x0064588e
void libm_sse2_atan_precise();  // 0x0064592d
void libm_sse2_pow_precise();  // 0x00645939
void Sys1c651560();  // 0x00651560
void Sys1c651A00();  // 0x00651a00
void Sys1c651A80();  // 0x00651a80

// --- Cycle 59: 0-caller functions (2829 functions) ---
void Core0c402160();  // 0x00402160
void Core0c402190();  // 0x00402190
void Core0c402210();  // 0x00402210
void Core0c4023E0();  // 0x004023e0
void Core0c402430();  // 0x00402430
void Core0c4024A0();  // 0x004024a0
void Core0c4024D0();  // 0x004024d0
void Core0c402550();  // 0x00402550
void Core0c4025A0();  // 0x004025a0
void Core0c402620();  // 0x00402620
void Core0c4026A0();  // 0x004026a0
void Core0c402770();  // 0x00402770
void Core0c429D80();  // 0x00429d80
void Core0c429E30();  // 0x00429e30
void Core0c429E80();  // 0x00429e80
void Core0c429FE0();  // 0x00429fe0
void Core0c42A110();  // 0x0042a110
void Core0c42A1F0();  // 0x0042a1f0
void Core0c42A540();  // 0x0042a540
void Core0c42A620();  // 0x0042a620
void Core0c42AE20();  // 0x0042ae20
void Core0c42B9E0();  // 0x0042b9e0
void Core0c42BA10();  // 0x0042ba10
void Core0c42BA50();  // 0x0042ba50
void Core0c42BA90();  // 0x0042ba90
void Core0c42C110();  // 0x0042c110
void Core0c42C740();  // 0x0042c740
void Core0c42CB60();  // 0x0042cb60
void Core0c42D370();  // 0x0042d370
void Core0c42D8F0();  // 0x0042d8f0
void Catch_All_0042e1f2();  // 0x0042e1f2
void Core0c42E520();  // 0x0042e520
void Core0c42E5A0();  // 0x0042e5a0
void Core0c42E6A0();  // 0x0042e6a0
void Core0c42E720();  // 0x0042e720
void Core0c42E830();  // 0x0042e830
void Core0c42E8C0();  // 0x0042e8c0
void Core0c42E970();  // 0x0042e970
void Core0c42EA20();  // 0x0042ea20
void Core0c42EAC0();  // 0x0042eac0
void Core0c42EBA0();  // 0x0042eba0
void Core0c42ECE0();  // 0x0042ece0
void Core0c42EE20();  // 0x0042ee20
void Core0c42EFC0();  // 0x0042efc0
void Core0c42F050();  // 0x0042f050
void Core0c42FA70();  // 0x0042fa70
void Catch_0042fd35();  // 0x0042fd35
void Core0c4308B0();  // 0x004308b0
void Core0c4308F0();  // 0x004308f0
void Core0c430930();  // 0x00430930
void Core0c430A10();  // 0x00430a10
void Core0c430AE0();  // 0x00430ae0
void Core0c430BF0();  // 0x00430bf0
void Core0c430CF0();  // 0x00430cf0
void Core0c430E00();  // 0x00430e00
void underflow();  // 0x00431010
void Core0c431050();  // 0x00431050
void Core0c431100();  // 0x00431100
void Core0c431440();  // 0x00431440
void Core0c4314A0();  // 0x004314a0
void Core0c431500();  // 0x00431500
void Core0c431520();  // 0x00431520
void Core0c43D950();  // 0x0043d950
void Catch_All_0043ed90();  // 0x0043ed90
void Catch_0043f576();  // 0x0043f576
void Core0c43F5F0();  // 0x0043f5f0
void Core0c43F620();  // 0x0043f620
void Core0c43F860();  // 0x0043f860
void Core0c43FA30();  // 0x0043fa30
void Core0c441AF0();  // 0x00441af0
void Core0c442530();  // 0x00442530
void Core0c442630();  // 0x00442630
void Core0c442F80();  // 0x00442f80
void Core0c442FB0();  // 0x00442fb0
void Core0c443240();  // 0x00443240
void Core0c4432F0();  // 0x004432f0
void Core0c444040();  // 0x00444040
void Core0c4440D0();  // 0x004440d0
void Core0c444AC0();  // 0x00444ac0
void Core0c444D30();  // 0x00444d30
void Core0c44DDB0();  // 0x0044ddb0
void Core0c44DF20();  // 0x0044df20
void Core0c44DF70();  // 0x0044df70
void Core0c44E040();  // 0x0044e040
void Catch_0044e20e();  // 0x0044e20e
void Core0c44E2E0();  // 0x0044e2e0
void Core0c44E780();  // 0x0044e780
void Core0c44EBE0();  // 0x0044ebe0
void Core0c44EC30();  // 0x0044ec30
void Core0c44FD60();  // 0x0044fd60
void Game0c4514E0();  // 0x004514e0
void Game0c451900();  // 0x00451900
void Game0c451CD0();  // 0x00451cd0
void Game0c451EA0();  // 0x00451ea0
void Game0c451FA0();  // 0x00451fa0
void Game0c4520A0();  // 0x004520a0
void Game0c4521A0();  // 0x004521a0
void Game0c4527E0();  // 0x004527e0
void Catch_00455846();  // 0x00455846
void Game0c456130();  // 0x00456130
void Game0c4610F0();  // 0x004610f0
void Game0c462420();  // 0x00462420
void Game0c462E10();  // 0x00462e10
void Game0c464A10();  // 0x00464a10
void Game0c46A050();  // 0x0046a050
void Game0c46E5B0();  // 0x0046e5b0
void Game0c46E980();  // 0x0046e980
void Game0c46EC40();  // 0x0046ec40
void Game0c46EC70();  // 0x0046ec70
void Catch_0046ed63();  // 0x0046ed63
void Game0c46EE70();  // 0x0046ee70
void Game0c46EF10();  // 0x0046ef10
void Game0c46EFF0();  // 0x0046eff0
void Game0c46F080();  // 0x0046f080
void Game0c46F0D0();  // 0x0046f0d0
void Game0c46F150();  // 0x0046f150
void Catch_All_0046f1bf();  // 0x0046f1bf
void Game0c46F1F0();  // 0x0046f1f0
void Game0c46F280();  // 0x0046f280
void Catch_All_0046f438();  // 0x0046f438
void Game0c46F580();  // 0x0046f580
void Catch_All_0046f7b5();  // 0x0046f7b5
void Game0c46F7E0();  // 0x0046f7e0
void Game0c46F930();  // 0x0046f930
void Catch_All_00470c6a();  // 0x00470c6a
void Game0c471C50();  // 0x00471c50
void Game0c471DC0();  // 0x00471dc0
void Game0c471E70();  // 0x00471e70
void Game0c476CB0();  // 0x00476cb0
void Game0c480180();  // 0x00480180
void Game0c489DA0();  // 0x00489da0
void Game0c48A4C0();  // 0x0048a4c0
void Game0c48ADB0();  // 0x0048adb0
void Game0c48D1A0();  // 0x0048d1a0
void Game0c48D800();  // 0x0048d800
void Game0c48D870();  // 0x0048d870
void Game0c48DC00();  // 0x0048dc00
void Game0c48E000();  // 0x0048e000
void Game0c48F3A0();  // 0x0048f3a0
void Game0c48F400();  // 0x0048f400
void Game0c492970();  // 0x00492970
void Game0c492CC0();  // 0x00492cc0
void Game0c493580();  // 0x00493580
void Game0c496F30();  // 0x00496f30
void Game0c498A60();  // 0x00498a60
void Game0c499720();  // 0x00499720
void Game0c49B980();  // 0x0049b980
void Game0c49BAB0();  // 0x0049bab0
void Game0c49BBB0();  // 0x0049bbb0
void Game0c49C6E0();  // 0x0049c6e0
void Game0c49C920();  // 0x0049c920
void Game0c49D2D0();  // 0x0049d2d0
void Game0c4A12E0();  // 0x004a12e0
void Game0c4A63D0();  // 0x004a63d0
void Game0c4AA5B0();  // 0x004aa5b0
void Game0c4AB850();  // 0x004ab850
void Catch_004b3d6e();  // 0x004b3d6e
void Game0c4BD160();  // 0x004bd160
void Game0c4BD5B0();  // 0x004bd5b0
void Game0c4BD7E0();  // 0x004bd7e0
void Game0c4BE430();  // 0x004be430
void Game0c4BE4A0();  // 0x004be4a0
void Game0c4BE760();  // 0x004be760
void Game0c4BE830();  // 0x004be830
void Game0c4BEA20();  // 0x004bea20
void Game0c4BEDF0();  // 0x004bedf0
void Game0c4BF210();  // 0x004bf210
void Game0c4BF230();  // 0x004bf230
void Game0c4BF2D0();  // 0x004bf2d0
void Game0c4BF310();  // 0x004bf310
void Game0c4BF3A0();  // 0x004bf3a0
void Game0c4BF430();  // 0x004bf430
void Game0c4BF4C0();  // 0x004bf4c0
void Game0c4BF570();  // 0x004bf570
void Game0c4BF790();  // 0x004bf790
void Game0c4C1AF0();  // 0x004c1af0
void Game0c4C1BA0();  // 0x004c1ba0
void Game0c4C1FE0();  // 0x004c1fe0
void Game0c4C20E0();  // 0x004c20e0
void Game0c4C2450();  // 0x004c2450
void Game0c4C2CF0();  // 0x004c2cf0
void Game0c4C3E90();  // 0x004c3e90
void Game0c4C41E0();  // 0x004c41e0
void Catch_004c423b();  // 0x004c423b
void Catch_All_004c429a();  // 0x004c429a
void Game0c4C42D0();  // 0x004c42d0
void Catch_004c434a();  // 0x004c434a
void Catch_All_004c43fc();  // 0x004c43fc
void Game0c4C48E0();  // 0x004c48e0
void Game0c4C5160();  // 0x004c5160
void Game0c4C51C0();  // 0x004c51c0
void Game0c4C56C0();  // 0x004c56c0
void Game0c4C5A40();  // 0x004c5a40
void Game0c4C5B20();  // 0x004c5b20
void Game0c4C5C30();  // 0x004c5c30
void Game0c4C5D50();  // 0x004c5d50
void Game0c4C5E80();  // 0x004c5e80
void Game0c4C5F80();  // 0x004c5f80
void Game0c4C6060();  // 0x004c6060
void Game0c4C6140();  // 0x004c6140
void Game0c4C6220();  // 0x004c6220
void Game0c4C6300();  // 0x004c6300
void Game0c4C6540();  // 0x004c6540
void Game0c4C6600();  // 0x004c6600
void Game0c4C66F0();  // 0x004c66f0
void Game0c4C6800();  // 0x004c6800
void Game0c4C68C0();  // 0x004c68c0
void Game0c4C6980();  // 0x004c6980
void Game0c4C6A40();  // 0x004c6a40
void Game0c4C6B00();  // 0x004c6b00
void Game0c4C6BC0();  // 0x004c6bc0
void Game0c4C6C80();  // 0x004c6c80
void Game0c4C6D50();  // 0x004c6d50
void Game0c4C6E20();  // 0x004c6e20
void Game0c4C6EF0();  // 0x004c6ef0
void Game0c4C6FC0();  // 0x004c6fc0
void Game0c4C70A0();  // 0x004c70a0
void Game0c4C71F0();  // 0x004c71f0
void Game0c4C72D0();  // 0x004c72d0
void Game0c4C7460();  // 0x004c7460
void Game0c4C75D0();  // 0x004c75d0
void Game0c4C76C0();  // 0x004c76c0
void Game0c4C7860();  // 0x004c7860
void Game0c4C79A0();  // 0x004c79a0
void Game0c4C7AA0();  // 0x004c7aa0
void Game0c4C7C20();  // 0x004c7c20
void Game0c4C7DD0();  // 0x004c7dd0
void Game0c4C7F60();  // 0x004c7f60
void Game0c4C80F0();  // 0x004c80f0
void Game0c4C83C0();  // 0x004c83c0
void Game0c4C9570();  // 0x004c9570
void Game0c4C9B70();  // 0x004c9b70
void Game0c4C9D20();  // 0x004c9d20
void Game0c4C9F10();  // 0x004c9f10
void Game0c4C9F80();  // 0x004c9f80
void Game0c4CA230();  // 0x004ca230
void Game0c4CA2E0();  // 0x004ca2e0
void Game0c4CA420();  // 0x004ca420
void Game0c4CA4E0();  // 0x004ca4e0
void Game0c4CA550();  // 0x004ca550
void Game0c4CA610();  // 0x004ca610
void Game0c4CA660();  // 0x004ca660
void Game0c4CA8A0();  // 0x004ca8a0
void Game0c4CA8C0();  // 0x004ca8c0
void Game0c4CA910();  // 0x004ca910
void Game0c4CAA50();  // 0x004caa50
void Game0c4CE260();  // 0x004ce260
void Game0c4CE360();  // 0x004ce360
void Game0c4CE3F0();  // 0x004ce3f0
void Game0c4CE5B0();  // 0x004ce5b0
void Game0c4CE720();  // 0x004ce720
void Game0c4CE800();  // 0x004ce800
void Game0c4CE900();  // 0x004ce900
void Game0c4CEA70();  // 0x004cea70
void Game0c4CFB70();  // 0x004cfb70
void Game0c4D0F60();  // 0x004d0f60
void Game0c4D1100();  // 0x004d1100
void Game0c4D1190();  // 0x004d1190
void Game0c4D11D0();  // 0x004d11d0
void Game0c4D1300();  // 0x004d1300
void Game0c4D1580();  // 0x004d1580
void Game0c4D16F0();  // 0x004d16f0
void Game0c4D17B0();  // 0x004d17b0
void Game0c4D22B0();  // 0x004d22b0
void Game0c4D2AB0();  // 0x004d2ab0
void Game0c4D39B0();  // 0x004d39b0
void Game0c4D6090();  // 0x004d6090
void Game0c4DE330();  // 0x004de330
void Game0c4DE3B0();  // 0x004de3b0
void Game0c4DE4E0();  // 0x004de4e0
void Game0c4E22B0();  // 0x004e22b0
void Game0c4E3300();  // 0x004e3300
void Game0c4E34A0();  // 0x004e34a0
void Game0c4E3980();  // 0x004e3980
void Game0c4E4140();  // 0x004e4140
void Game0c4E4910();  // 0x004e4910
void Game0c4F2940();  // 0x004f2940
void Game0c4F2B60();  // 0x004f2b60
void Game0c4F2DC0();  // 0x004f2dc0
void Catch_All_004f382a();  // 0x004f382a
void Catch_All_004f4a5a();  // 0x004f4a5a
void Catch_All_004f4feb();  // 0x004f4feb
void Game0c4F77E0();  // 0x004f77e0
void Game0c4F7820();  // 0x004f7820
void Game0c4F94C0();  // 0x004f94c0
void Game0c4F9AE0();  // 0x004f9ae0
void Game0c4F9F50();  // 0x004f9f50
void Game0c4FAE20();  // 0x004fae20
void Game0c4FDAB0();  // 0x004fdab0
void Catch_All_004fe56c();  // 0x004fe56c
void Game0c4FE690();  // 0x004fe690
void Game0c4FFE10();  // 0x004ffe10
void Render0c500130();  // 0x00500130
void Render0c500650();  // 0x00500650
void Catch_All_00501213();  // 0x00501213
void Render0c502460();  // 0x00502460
void Render0c5038F0();  // 0x005038f0
void Render0c505CA0();  // 0x00505ca0
void Render0c506260();  // 0x00506260
void Render0c50AEB0();  // 0x0050aeb0
void Render0c50B8C0();  // 0x0050b8c0
void Render0c50D090();  // 0x0050d090
void Render0c514D40();  // 0x00514d40
void Render0c515AC0();  // 0x00515ac0
void Render0c515F10();  // 0x00515f10
void Render0c515F80();  // 0x00515f80
void Render0c518460();  // 0x00518460
void Render0c518770();  // 0x00518770
void Render0c518900();  // 0x00518900
void Render0c518A60();  // 0x00518a60
void Render0c519400();  // 0x00519400
void Render0c51A250();  // 0x0051a250
void Render0c51B6C0();  // 0x0051b6c0
void Render0c51BD90();  // 0x0051bd90
void Render0c51C2D0();  // 0x0051c2d0
void Render0c51C680();  // 0x0051c680
void Render0c51EB00();  // 0x0051eb00
void Render0c51EE60();  // 0x0051ee60
void Render0c51F5F8();  // 0x0051f5f8
void Render0c51F960();  // 0x0051f960
void Render0c520C20();  // 0x00520c20
void Render0c520CF0();  // 0x00520cf0
void Render0c5210D0();  // 0x005210d0
void Render0c521260();  // 0x00521260
void Render0c5220E0();  // 0x005220e0
void Render0c5224A0();  // 0x005224a0
void Render0c523AA0();  // 0x00523aa0
void Render0c523E40();  // 0x00523e40
void Render0c524640();  // 0x00524640
void Render0c524710();  // 0x00524710
void Render0c5310B0();  // 0x005310b0
void Render0c531550();  // 0x00531550
void Render0c531580();  // 0x00531580
void Render0c532F00();  // 0x00532f00
void Render0c53B170();  // 0x0053b170
void Render0c53B400();  // 0x0053b400
void Render0c53DF20();  // 0x0053df20
void Render0c53E6A0();  // 0x0053e6a0
void Render0c53EAC0();  // 0x0053eac0
void Render0c53F010();  // 0x0053f010
void Render0c53FFA0();  // 0x0053ffa0
void Render0c54CB30();  // 0x0054cb30
void Render0c54CC20();  // 0x0054cc20
void Render0c551BE0();  // 0x00551be0
void Catch_00554900();  // 0x00554900
void Catch_00554a6e();  // 0x00554a6e
void Render0c5582C0();  // 0x005582c0
void Render0c5588F0();  // 0x005588f0
void Render0c558910();  // 0x00558910
void Render0c559340();  // 0x00559340
void Render0c55A0B0();  // 0x0055a0b0
void Render0c55AA30();  // 0x0055aa30
void Render0c55C220();  // 0x0055c220
void Render0c55CC40();  // 0x0055cc40
void Render0c55CC70();  // 0x0055cc70
void Render0c55F030();  // 0x0055f030
void Render0c55F0A0();  // 0x0055f0a0
void Render0c55F110();  // 0x0055f110
void Render0c55F290();  // 0x0055f290
void Render0c55F500();  // 0x0055f500
void Render0c55F5F0();  // 0x0055f5f0
void Render0c55F710();  // 0x0055f710
void Render0c55FC80();  // 0x0055fc80
void Render0c5617E0();  // 0x005617e0
void Render0c563B30();  // 0x00563b30
void Render0c563BC0();  // 0x00563bc0
void Render0c563CD0();  // 0x00563cd0
void Render0c563DA0();  // 0x00563da0
void Render0c5690B0();  // 0x005690b0
void Render0c569300();  // 0x00569300
void Render0c5693D0();  // 0x005693d0
void Render0c569E70();  // 0x00569e70
void Render0c56A2C0();  // 0x0056a2c0
void Render0c56A4A0();  // 0x0056a4a0
void Render0c56AB20();  // 0x0056ab20
void Render0c56B700();  // 0x0056b700
void Render0c56B720();  // 0x0056b720
void Render0c56B740();  // 0x0056b740
void Render0c56B760();  // 0x0056b760
void Render0c56B780();  // 0x0056b780
void Render0c56B7C0();  // 0x0056b7c0
void Render0c56B810();  // 0x0056b810
void Render0c56B850();  // 0x0056b850
void Render0c56B930();  // 0x0056b930
void Render0c56BB40();  // 0x0056bb40
void Render0c56C8C0();  // 0x0056c8c0
void Render0c56CCD0();  // 0x0056ccd0
void Render0c56D080();  // 0x0056d080
void Render0c56D1A0();  // 0x0056d1a0
void Render0c5712C0();  // 0x005712c0
void Render0c573270();  // 0x00573270
void Render0c5740D0();  // 0x005740d0
void Render0c5742F0();  // 0x005742f0
void Render0c5745A0();  // 0x005745a0
void Render0c574740();  // 0x00574740
void Render0c5748B0();  // 0x005748b0
void Render0c574AD0();  // 0x00574ad0
void Render0c574CA0();  // 0x00574ca0
void Render0c57D880();  // 0x0057d880
void Render0c57DBB0();  // 0x0057dbb0
void Render0c57F680();  // 0x0057f680
void Render0c580520();  // 0x00580520
void Render0c584C50();  // 0x00584c50
void Render0c58A3C0();  // 0x0058a3c0
void Render0c58DB10();  // 0x0058db10
void Render0c58E5B0();  // 0x0058e5b0
void Render0c592B50();  // 0x00592b50
void Render0c592BA0();  // 0x00592ba0
void Render0c592C30();  // 0x00592c30
void Render0c592D40();  // 0x00592d40
void Render0c592FC0();  // 0x00592fc0
void Render0c5932D0();  // 0x005932d0
void Render0c5937D0();  // 0x005937d0
void Render0c593910();  // 0x00593910
void Render0c593CC0();  // 0x00593cc0
void Render0c593F00();  // 0x00593f00
void Render0c5943E0();  // 0x005943e0
void Render0c5949A0();  // 0x005949a0
void Render0c595240();  // 0x00595240
void Render0c595670();  // 0x00595670
void Render0c5958E0();  // 0x005958e0
void Render0c595AB0();  // 0x00595ab0
void Render0c595D80();  // 0x00595d80
void Render0c596710();  // 0x00596710
void Render0c596A00();  // 0x00596a00
void Render0c596B10();  // 0x00596b10
void Render0c596C10();  // 0x00596c10
void Render0c599640();  // 0x00599640
void Render0c59A370();  // 0x0059a370
void Render0c59B4B0();  // 0x0059b4b0
void Render0c59BB60();  // 0x0059bb60
void Render0c5A0140();  // 0x005a0140
void Render0c5A3CA0();  // 0x005a3ca0
void Render0c5A3CD0();  // 0x005a3cd0
void Render0c5A5790();  // 0x005a5790
void Render0c5A6940();  // 0x005a6940
void Render0c5A6D10();  // 0x005a6d10
void Render0c5A7010();  // 0x005a7010
void Render0c5A7030();  // 0x005a7030
void Render0c5A7060();  // 0x005a7060
void Render0c5A7290();  // 0x005a7290
void Render0c5A9A50();  // 0x005a9a50
void Render0c5AA4B0();  // 0x005aa4b0
void Render0c5AAA30();  // 0x005aaa30
void Render0c5AACF0();  // 0x005aacf0
void Render0c5AB160();  // 0x005ab160
void Render0c5AB5D0();  // 0x005ab5d0
void Render0c5ABC60();  // 0x005abc60
void Render0c5AC980();  // 0x005ac980
void Render0c5ACBA0();  // 0x005acba0
void Render0c5ACD30();  // 0x005acd30
void Render0c5ACE50();  // 0x005ace50
void Render0c5AD0C0();  // 0x005ad0c0
void Render0c5AD450();  // 0x005ad450
void Render0c5AD4E0();  // 0x005ad4e0
void Render0c5ADB10();  // 0x005adb10
void Render0c5ADB50();  // 0x005adb50
void Render0c5AE020();  // 0x005ae020
void Render0c5AE180();  // 0x005ae180
void Render0c5AE9D0();  // 0x005ae9d0
void Render0c5AEB70();  // 0x005aeb70
void Render0c5AF0D0();  // 0x005af0d0
void Render0c5AF100();  // 0x005af100
void Render0c5AF190();  // 0x005af190
void Render0c5AF4D0();  // 0x005af4d0
void Render0c5B0470();  // 0x005b0470
void Render0c5B0600();  // 0x005b0600
void Render0c5B1D20();  // 0x005b1d20
void Render0c5B1F20();  // 0x005b1f20
void Render0c5B2160();  // 0x005b2160
void Render0c5B2820();  // 0x005b2820
void Render0c5B2EE0();  // 0x005b2ee0
void Render0c5B36D0();  // 0x005b36d0
void Render0c5B4C70();  // 0x005b4c70
void Render0c5B4E30();  // 0x005b4e30
void Render0c5B4E50();  // 0x005b4e50
void Render0c5B4EB0();  // 0x005b4eb0
void Render0c5B4FD0();  // 0x005b4fd0
void Render0c5B5140();  // 0x005b5140
void Render0c5BCDF0();  // 0x005bcdf0
void Render0c5BDD90();  // 0x005bdd90
void Render0c5BF0B0();  // 0x005bf0b0
void Render0c5BF320();  // 0x005bf320
void Render0c5BF600();  // 0x005bf600
void Render0c5BF710();  // 0x005bf710
void Render0c5BFEB0();  // 0x005bfeb0
void Render0c5C17D0();  // 0x005c17d0
void Render0c5C1C00();  // 0x005c1c00
void Render0c5C6200();  // 0x005c6200
void Render0c5C62C0();  // 0x005c62c0
void Render0c5C6550();  // 0x005c6550
void Render0c5CCE60();  // 0x005cce60
void Render0c5CD160();  // 0x005cd160
void Render0c5CDF60();  // 0x005cdf60
void Render0c5CF2E0();  // 0x005cf2e0
void Render0c5CF900();  // 0x005cf900
void Render0c5D17C0();  // 0x005d17c0
void Render0c5D1F60();  // 0x005d1f60
void Render0c5D1FD0();  // 0x005d1fd0
void Render0c5D2610();  // 0x005d2610
void Render0c5D28F0();  // 0x005d28f0
void Render0c5D2970();  // 0x005d2970
void Render0c5D2A30();  // 0x005d2a30
void Render0c5D2C80();  // 0x005d2c80
void Render0c5D3930();  // 0x005d3930
void Render0c5D4E80();  // 0x005d4e80
void Render0c5D5090();  // 0x005d5090
void Render0c5D52C0();  // 0x005d52c0
void Render0c5D5DD0();  // 0x005d5dd0
void Render0c5D5F40();  // 0x005d5f40
void Render0c5D7450();  // 0x005d7450
void Render0c5DC6B0();  // 0x005dc6b0
void Render0c5DC880();  // 0x005dc880
void Render0c5DED10();  // 0x005ded10
void Render0c5DF080();  // 0x005df080
void Render0c5DF6D0();  // 0x005df6d0
void Render0c5E30E0();  // 0x005e30e0
void Render0c5EA0D0();  // 0x005ea0d0
void Render0c5EB010();  // 0x005eb010
void Render0c5EB900();  // 0x005eb900
void Render0c5EC1D0();  // 0x005ec1d0
void Render0c5EE0E0();  // 0x005ee0e0
void Render0c5EE680();  // 0x005ee680
void Render0c5EEA70();  // 0x005eea70
void Render0c5EEC10();  // 0x005eec10
void Render0c5F02B0();  // 0x005f02b0
void Render0c5F0420();  // 0x005f0420
void Render0c5F0950();  // 0x005f0950
void Render0c5F09E0();  // 0x005f09e0
void Render0c5F0D40();  // 0x005f0d40
void Render0c5F0ED0();  // 0x005f0ed0
void Render0c5F16E0();  // 0x005f16e0
void Render0c5F23E0();  // 0x005f23e0
void Render0c5F26B0();  // 0x005f26b0
void Render0c5F3290();  // 0x005f3290
void Render0c5F43A0();  // 0x005f43a0
void Render0c5F45A0();  // 0x005f45a0
void Render0c5F4EC0();  // 0x005f4ec0
void Render0c5F98A0();  // 0x005f98a0
void Render0c5FC8F0();  // 0x005fc8f0
void Render0c5FC930();  // 0x005fc930
void Render0c5FC9A0();  // 0x005fc9a0
void Catch_All_005fd82a();  // 0x005fd82a
void Render0c5FE470();  // 0x005fe470
void Render0c5FE5F0();  // 0x005fe5f0
void Render0c5FE670();  // 0x005fe670
void Catch_005fe6fc();  // 0x005fe6fc
void Render0c5FE7A0();  // 0x005fe7a0
void Render0c5FEAF0();  // 0x005feaf0
void Catch_005fec8d();  // 0x005fec8d
void Render0c5FECE0();  // 0x005fece0
void Render0c5FEE00();  // 0x005fee00
void Render0c5FF040();  // 0x005ff040
void Render0c5FF370();  // 0x005ff370
void Render0c5FF600();  // 0x005ff600
void Render0c5FF690();  // 0x005ff690
void Render0c5FF7F0();  // 0x005ff7f0
void Render0c5FFC30();  // 0x005ffc30
void Render0c5FFEE0();  // 0x005ffee0
void Render0c5FFF30();  // 0x005fff30
void Catch_00600031();  // 0x00600031
void Catch_00600098();  // 0x00600098
void Sys0c600240();  // 0x00600240
void Sys0c6006C0();  // 0x006006c0
void Sys0c600A70();  // 0x00600a70
void Sys0c601230();  // 0x00601230
void Sys0c601270();  // 0x00601270
void Sys0c6013F0();  // 0x006013f0
void Sys0c601710();  // 0x00601710
void Sys0c601F90();  // 0x00601f90
void Catch_006022e7();  // 0x006022e7
void Catch_All_006022f8();  // 0x006022f8
void Sys0c602310();  // 0x00602310
void Catch_006023d3();  // 0x006023d3
void Sys0c6023F0();  // 0x006023f0
void Catch_All_0060274b();  // 0x0060274b
void Sys0c602850();  // 0x00602850
void Catch_00602ab4();  // 0x00602ab4
void Catch_00602b0f();  // 0x00602b0f
void Catch_All_00602b49();  // 0x00602b49
void Sys0c602BA0();  // 0x00602ba0
void Catch_All_00602fe6();  // 0x00602fe6
void Sys0c603000();  // 0x00603000
void Catch_006030d5();  // 0x006030d5
void Catch_All_006030e3();  // 0x006030e3
void Catch_All_006031d8();  // 0x006031d8
void Catch_All_0060350c();  // 0x0060350c
void Sys0c6035E0();  // 0x006035e0
void Sys0c604B80();  // 0x00604b80
void Sys0c605FD0();  // 0x00605fd0
void Sys0c606190();  // 0x00606190
void Sys0c6065D0();  // 0x006065d0
void Sys0c606700();  // 0x00606700
void Sys0c606BA0();  // 0x00606ba0
void Sys0c606DA0();  // 0x00606da0
void Sys0c607030();  // 0x00607030
void Sys0c607090();  // 0x00607090
void Sys0c607160();  // 0x00607160
void Sys0c608A30();  // 0x00608a30
void Sys0c608AA0();  // 0x00608aa0
void Sys0c608BE0();  // 0x00608be0
void Sys0c608C10();  // 0x00608c10
void Sys0c608E30();  // 0x00608e30
void Sys0c608E90();  // 0x00608e90
void Sys0c608F80();  // 0x00608f80
void Sys0c609020();  // 0x00609020
void Sys0c609120();  // 0x00609120
void Sys0c609220();  // 0x00609220
void Sys0c6092C0();  // 0x006092c0
void Sys0c6093B0();  // 0x006093b0
void Sys0c6094A0();  // 0x006094a0
void Sys0c609560();  // 0x00609560
void Sys0c6095E0();  // 0x006095e0
void Sys0c609940();  // 0x00609940
void Sys0c609990();  // 0x00609990
void Sys0c609AF0();  // 0x00609af0
void Sys0c609CA0();  // 0x00609ca0
void Sys0c609D70();  // 0x00609d70
void Sys0c609ED0();  // 0x00609ed0
void Sys0c60A020();  // 0x0060a020
void Sys0c60A0F0();  // 0x0060a0f0
void Sys0c60A160();  // 0x0060a160
void Sys0c60A250();  // 0x0060a250
void Sys0c60A320();  // 0x0060a320
void Sys0c60A3A0();  // 0x0060a3a0
void Sys0c60A420();  // 0x0060a420
void Sys0c60A4F0();  // 0x0060a4f0
void Catch_0060a5bc();  // 0x0060a5bc
void Catch_0060a5db();  // 0x0060a5db
void Catch_All_0060a5fa();  // 0x0060a5fa
void Sys0c60A6F0();  // 0x0060a6f0
void Catch_0060a805();  // 0x0060a805
void Catch_0060a824();  // 0x0060a824
void Catch_All_0060a843();  // 0x0060a843
void Sys0c60B680();  // 0x0060b680
void Sys0c60B7E0();  // 0x0060b7e0
void Sys0c60B800();  // 0x0060b800
void Sys0c60B880();  // 0x0060b880
void Sys0c60B8A0();  // 0x0060b8a0
void Catch_All_0060bd70();  // 0x0060bd70
void Catch_All_0060c740();  // 0x0060c740
void Catch_All_0060ccd0();  // 0x0060ccd0
void Sys0c60E320();  // 0x0060e320
void Sys0c6112F0();  // 0x006112f0
void Sys0c6116C0();  // 0x006116c0
void Sys0c6129F0();  // 0x006129f0
void Catch_00612abc();  // 0x00612abc
void Catch_00612adb();  // 0x00612adb
void Catch_All_00612afa();  // 0x00612afa
void Sys0c612BF0();  // 0x00612bf0
void Catch_00612cbc();  // 0x00612cbc
void Catch_00612cdb();  // 0x00612cdb
void Catch_All_00612cfa();  // 0x00612cfa
void Sys0c612F20();  // 0x00612f20
void Catch_00612fec();  // 0x00612fec
void Catch_0061300b();  // 0x0061300b
void Catch_All_0061302a();  // 0x0061302a
void Sys0c6132B0();  // 0x006132b0
void Sys0c613710();  // 0x00613710
void Sys0c613970();  // 0x00613970
void Sys0c613990();  // 0x00613990
void Sys0c613A10();  // 0x00613a10
void Sys0c613A30();  // 0x00613a30
void Sys0c613AB0();  // 0x00613ab0
void Sys0c613AD0();  // 0x00613ad0
void Sys0c613B50();  // 0x00613b50
void Sys0c613C10();  // 0x00613c10
void Sys0c6144C0();  // 0x006144c0
void Sys0c614740();  // 0x00614740
void Catch_00614855();  // 0x00614855
void Catch_00614874();  // 0x00614874
void Catch_All_00614893();  // 0x00614893
void Sys0c614980();  // 0x00614980
void Catch_00614a95();  // 0x00614a95
void Catch_00614ab4();  // 0x00614ab4
void Catch_All_00614ad3();  // 0x00614ad3
void Sys0c614BE0();  // 0x00614be0
void Catch_00614cf5();  // 0x00614cf5
void Catch_00614d14();  // 0x00614d14
void Catch_All_00614d33();  // 0x00614d33
void Sys0c6155A0();  // 0x006155a0
void Sys0c6155C0();  // 0x006155c0
void Sys0c615640();  // 0x00615640
void Sys0c615660();  // 0x00615660
void Sys0c6156E0();  // 0x006156e0
void Sys0c615700();  // 0x00615700
void Sys0c615A70();  // 0x00615a70
void Catch_00615b3c();  // 0x00615b3c
void Catch_00615b5b();  // 0x00615b5b
void Catch_All_00615b7a();  // 0x00615b7a
void Sys0c615C70();  // 0x00615c70
void Catch_00615d3c();  // 0x00615d3c
void Catch_00615d5b();  // 0x00615d5b
void Catch_All_00615d7a();  // 0x00615d7a
void Sys0c615E70();  // 0x00615e70
void Sys0c615EB0();  // 0x00615eb0
void Sys0c615F20();  // 0x00615f20
void Sys0c615F90();  // 0x00615f90
void Sys0c6167D0();  // 0x006167d0
void Sys0c6167F0();  // 0x006167f0
void Sys0c616870();  // 0x00616870
void Sys0c616890();  // 0x00616890
void Sys0c616B60();  // 0x00616b60
void Sys0c6177D0();  // 0x006177d0
void Sys0c618D30();  // 0x00618d30
void Catch_00618dfc();  // 0x00618dfc
void Catch_00618e1b();  // 0x00618e1b
void Catch_All_00618e3a();  // 0x00618e3a
void Sys0c618F30();  // 0x00618f30
void Catch_00618ffc();  // 0x00618ffc
void Catch_0061901b();  // 0x0061901b
void Catch_All_0061903a();  // 0x0061903a
void Sys0c619130();  // 0x00619130
void Catch_006191fc();  // 0x006191fc
void Catch_0061921b();  // 0x0061921b
void Catch_All_0061923a();  // 0x0061923a
void Sys0c619340();  // 0x00619340
void Sys0c619480();  // 0x00619480
void Sys0c619530();  // 0x00619530
void Sys0c6195B0();  // 0x006195b0
void Sys0c6195D0();  // 0x006195d0
void Sys0c619650();  // 0x00619650
void Sys0c619670();  // 0x00619670
void Sys0c6196F0();  // 0x006196f0
void Sys0c619710();  // 0x00619710
void Sys0c6197F0();  // 0x006197f0
void Sys0c619960();  // 0x00619960
void Sys0c6199F0();  // 0x006199f0
void Sys0c61A020();  // 0x0061a020
void Sys0c61A0B0();  // 0x0061a0b0
void Sys0c61A140();  // 0x0061a140
void Sys0c61A1C0();  // 0x0061a1c0
void Sys0c61A440();  // 0x0061a440
void Sys0c61A4C0();  // 0x0061a4c0
void Sys0c61A770();  // 0x0061a770
void Sys0c61B160();  // 0x0061b160
void Sys0c61B620();  // 0x0061b620
void Sys0c61B890();  // 0x0061b890
void Sys0c61BAA0();  // 0x0061baa0
void Sys0c61BDE0();  // 0x0061bde0
void Sys0c61BE20();  // 0x0061be20
void Sys0c61C630();  // 0x0061c630
void Catch_All_0061c77e();  // 0x0061c77e
void Catch_0061cad2();  // 0x0061cad2
void Catch_0061cad8();  // 0x0061cad8
void Catch_All_0061cade();  // 0x0061cade
void Sys0c61CC00();  // 0x0061cc00
void Catch_0061d1b1();  // 0x0061d1b1
void Catch_0061d1da();  // 0x0061d1da
void Catch_All_0061d1fe();  // 0x0061d1fe
void Sys0c61DC90();  // 0x0061dc90
void Sys0c61DEA0();  // 0x0061dea0
void Sys0c61F2C0();  // 0x0061f2c0
void Catch_0061f380();  // 0x0061f380
void Sys0c61FAC0();  // 0x0061fac0
void Sys0c6201C0();  // 0x006201c0
void Sys0c6205B0();  // 0x006205b0
void Sys0c620800();  // 0x00620800
void Sys0c621A90();  // 0x00621a90
void Sys0c621B70();  // 0x00621b70
void Sys0c621C40();  // 0x00621c40
void Catch_00623906();  // 0x00623906
void Catch_00624f43();  // 0x00624f43
void Catch_006253ee();  // 0x006253ee
void Catch_All_0062542d();  // 0x0062542d
void Sys0c625AE0();  // 0x00625ae0
void Catch_All_00627941();  // 0x00627941
void Sys0c628980();  // 0x00628980
void Sys0c628AF0();  // 0x00628af0
void Catch_0062cff3();  // 0x0062cff3
void Sys0c6321E0();  // 0x006321e0
void Sys0c632240();  // 0x00632240
void Sys0c632AC0();  // 0x00632ac0
void Sys0c632BF0();  // 0x00632bf0
void Sys0c632C40();  // 0x00632c40
void Sys0c632C70();  // 0x00632c70
void Sys0c632E00();  // 0x00632e00
void Sys0c632E50();  // 0x00632e50
void Sys0c632EC0();  // 0x00632ec0
void Sys0c632FA0();  // 0x00632fa0
void Sys0c632FE0();  // 0x00632fe0
void Sys0c635890();  // 0x00635890
void Sys0c6358B0();  // 0x006358b0
void Sys0c6358D0();  // 0x006358d0
void Sys0c6358F0();  // 0x006358f0
void Sys0c635910();  // 0x00635910
void Sys0c635930();  // 0x00635930
void Sys0c635950();  // 0x00635950
void Sys0c635970();  // 0x00635970
void Sys0c635990();  // 0x00635990
void Sys0c6359B0();  // 0x006359b0
void Sys0c6359D0();  // 0x006359d0
void Sys0c6359F0();  // 0x006359f0
void Sys0c635A10();  // 0x00635a10
void Sys0c635A30();  // 0x00635a30
void Sys0c635A50();  // 0x00635a50
void Sys0c635A70();  // 0x00635a70
void Sys0c635A90();  // 0x00635a90
void Sys0c635AB0();  // 0x00635ab0
void Sys0c635AD0();  // 0x00635ad0
void Sys0c635AF0();  // 0x00635af0
void Sys0c635B10();  // 0x00635b10
void Sys0c635B30();  // 0x00635b30
void Sys0c635B50();  // 0x00635b50
void Sys0c635B70();  // 0x00635b70
void Sys0c635B90();  // 0x00635b90
void Sys0c635BB0();  // 0x00635bb0
void Sys0c635BD0();  // 0x00635bd0
void Sys0c635BF0();  // 0x00635bf0
void Sys0c635C10();  // 0x00635c10
void Sys0c635C30();  // 0x00635c30
void Sys0c635C50();  // 0x00635c50
void Sys0c635C70();  // 0x00635c70
void Sys0c635C90();  // 0x00635c90
void Sys0c635CB0();  // 0x00635cb0
void Sys0c635CD0();  // 0x00635cd0
void Sys0c635CF0();  // 0x00635cf0
void Sys0c635D10();  // 0x00635d10
void Sys0c635D30();  // 0x00635d30
void Sys0c635D50();  // 0x00635d50
void Sys0c636180();  // 0x00636180
void Sys0c636210();  // 0x00636210
void Sys0c6362D0();  // 0x006362d0
void Sys0c6370A0();  // 0x006370a0
void Catch_00637b4e();  // 0x00637b4e
void Catch_00638333();  // 0x00638333
void Sys0c63A800();  // 0x0063a800
void Sys0c63AB90();  // 0x0063ab90
void Sys0c63AD70();  // 0x0063ad70
void Sys0c63B280();  // 0x0063b280
void Sys0c63B3A0();  // 0x0063b3a0
void Sys0c63B460();  // 0x0063b460
void Sys0c63B9D0();  // 0x0063b9d0
void Sys0c63BB80();  // 0x0063bb80
void Sys0c63BF00();  // 0x0063bf00
void Sys0c63C350();  // 0x0063c350
void Sys0c63C4B0();  // 0x0063c4b0
void Sys0c63C6D0();  // 0x0063c6d0
void Sys0c63C8F0();  // 0x0063c8f0
void Sys0c63D0E0();  // 0x0063d0e0
void Sys0c63D440();  // 0x0063d440
void Sys0c63D620();  // 0x0063d620
void Sys0c63DB00();  // 0x0063db00
void Sys0c63DC20();  // 0x0063dc20
void Sys0c63DCE0();  // 0x0063dce0
void Sys0c63FF70();  // 0x0063ff70
void Sys0c63FFA0();  // 0x0063ffa0
void Sys0c640130();  // 0x00640130
void Sys0c640AE0();  // 0x00640ae0
void Sys0c640F00();  // 0x00640f00
void Sys0c640FF0();  // 0x00640ff0
void Sys0c641000();  // 0x00641000
void Sys0c641DA4();  // 0x00641da4
void Sys0c643548();  // 0x00643548
void ___scrt_initialize_onexit_tables();  // 0x0064370c
void Catch_All_00643ccd();  // 0x00643ccd
void Sys0c644604();  // 0x00644604
void Unwind_00644863();  // 0x00644863
void Crt__exit();  // 0x00644947
void _set_new_mode();  // 0x00644965
void Catch_All_00644aa0();  // 0x00644aa0
void Sys0c644EF0();  // 0x00644ef0
void __alloca_probe_8();  // 0x006456c6
void Unwind_00645950();  // 0x00645950
void Unwind_00645980();  // 0x00645980
void Unwind_00645988();  // 0x00645988
void Unwind_006459c0();  // 0x006459c0
void Unwind_006459c8();  // 0x006459c8
void Unwind_00645a00();  // 0x00645a00
void Unwind_00645a40();  // 0x00645a40
void Unwind_00645a80();  // 0x00645a80
void Unwind_00645a88();  // 0x00645a88
void Unwind_00645ac0();  // 0x00645ac0
void Unwind_00645ac8();  // 0x00645ac8
void Unwind_00645ad0();  // 0x00645ad0
void Unwind_00645ad8();  // 0x00645ad8
void Unwind_00645b10();  // 0x00645b10
void Unwind_00645b18();  // 0x00645b18
void Unwind_00645b20();  // 0x00645b20
void Unwind_00645b3a();  // 0x00645b3a
void Unwind_00645b46();  // 0x00645b46
void Unwind_00645b51();  // 0x00645b51
void Unwind_00645b90();  // 0x00645b90
void Unwind_00645bc0();  // 0x00645bc0
void Unwind_00645bc8();  // 0x00645bc8
void Unwind_00645be1();  // 0x00645be1
void Unwind_00645be9();  // 0x00645be9
void Unwind_00645c20();  // 0x00645c20
void Unwind_00645c50();  // 0x00645c50
void Unwind_00645c80();  // 0x00645c80
void Unwind_00645c88();  // 0x00645c88
void Unwind_00645cd0();  // 0x00645cd0
void Unwind_00645d00();  // 0x00645d00
void Unwind_00645d08();  // 0x00645d08
void Unwind_00645d40();  // 0x00645d40
void Unwind_00645d48();  // 0x00645d48
void Unwind_00645d80();  // 0x00645d80
void Unwind_00645d88();  // 0x00645d88
void Unwind_00645d90();  // 0x00645d90
void Unwind_00645d98();  // 0x00645d98
void Unwind_00645da0();  // 0x00645da0
void Unwind_00645e40();  // 0x00645e40
void Unwind_00645e5d();  // 0x00645e5d
void Unwind_00645e69();  // 0x00645e69
void Unwind_00645e74();  // 0x00645e74
void Unwind_00645e91();  // 0x00645e91
void Unwind_00645e9d();  // 0x00645e9d
void Unwind_00645ea8();  // 0x00645ea8
void Unwind_00645ec6();  // 0x00645ec6
void Unwind_00645ece();  // 0x00645ece
void Unwind_00645f10();  // 0x00645f10
void Unwind_00645f29();  // 0x00645f29
void Unwind_00645f80();  // 0x00645f80
void Unwind_00645f8f();  // 0x00645f8f
void Unwind_00645f97();  // 0x00645f97
void Unwind_00645f9f();  // 0x00645f9f
void Unwind_00645fd0();  // 0x00645fd0
void Unwind_00646010();  // 0x00646010
void Unwind_00646018();  // 0x00646018
void Unwind_00646020();  // 0x00646020
void Unwind_00646060();  // 0x00646060
void Unwind_0064606b();  // 0x0064606b
void Unwind_0064608d();  // 0x0064608d
void Unwind_00646098();  // 0x00646098
void Unwind_006460a3();  // 0x006460a3
void Unwind_006460ae();  // 0x006460ae
void Unwind_006460b9();  // 0x006460b9
void Unwind_006460c4();  // 0x006460c4
void Unwind_006460cf();  // 0x006460cf
void Unwind_00646130();  // 0x00646130
void Unwind_00646138();  // 0x00646138
void Unwind_00646140();  // 0x00646140
void Unwind_00646180();  // 0x00646180
void Unwind_006461c0();  // 0x006461c0
void Unwind_006461c8();  // 0x006461c8
void Unwind_00646200();  // 0x00646200
void Unwind_00646260();  // 0x00646260
void Unwind_00646268();  // 0x00646268
void Unwind_006462a0();  // 0x006462a0
void Unwind_006462b9();  // 0x006462b9
void Unwind_006462c1();  // 0x006462c1
void Unwind_00646300();  // 0x00646300
void Unwind_00646309();  // 0x00646309
void Unwind_00646340();  // 0x00646340
void Unwind_0064634b();  // 0x0064634b
void Unwind_00646356();  // 0x00646356
void Unwind_0064635e();  // 0x0064635e
void Unwind_00646366();  // 0x00646366
void Unwind_0064636e();  // 0x0064636e
void Unwind_00646376();  // 0x00646376
void Unwind_0064637e();  // 0x0064637e
void Unwind_00646386();  // 0x00646386
void Unwind_0064638e();  // 0x0064638e
void Unwind_00646399();  // 0x00646399
void Unwind_006463d0();  // 0x006463d0
void Unwind_00646400();  // 0x00646400
void Unwind_00646408();  // 0x00646408
void Unwind_00646440();  // 0x00646440
void Unwind_0064644b();  // 0x0064644b
void Unwind_00646453();  // 0x00646453
void Unwind_0064645b();  // 0x0064645b
void Unwind_00646466();  // 0x00646466
void Unwind_0064646e();  // 0x0064646e
void Unwind_00646476();  // 0x00646476
void Unwind_0064647e();  // 0x0064647e
void Unwind_00646489();  // 0x00646489
void Unwind_00646491();  // 0x00646491
void Unwind_00646499();  // 0x00646499
void Unwind_006464a1();  // 0x006464a1
void Unwind_006464a9();  // 0x006464a9
void Unwind_006464b4();  // 0x006464b4
void Unwind_006464bc();  // 0x006464bc
void Unwind_006464c4();  // 0x006464c4
void Unwind_006464cc();  // 0x006464cc
void Unwind_006464d7();  // 0x006464d7
void Unwind_006464df();  // 0x006464df
void Unwind_006464e7();  // 0x006464e7
void Unwind_006464ef();  // 0x006464ef
void Unwind_006464fa();  // 0x006464fa
void Unwind_00646502();  // 0x00646502
void Unwind_0064650a();  // 0x0064650a
void Unwind_00646512();  // 0x00646512
void Unwind_0064651d();  // 0x0064651d
void Unwind_00646525();  // 0x00646525
void Unwind_0064652d();  // 0x0064652d
void Unwind_00646535();  // 0x00646535
void Unwind_00646540();  // 0x00646540
void Unwind_00646548();  // 0x00646548
void Unwind_00646550();  // 0x00646550
void Unwind_00646558();  // 0x00646558
void Unwind_00646563();  // 0x00646563
void Unwind_0064656b();  // 0x0064656b
void Unwind_00646573();  // 0x00646573
void Unwind_0064657b();  // 0x0064657b
void Unwind_00646586();  // 0x00646586
void Unwind_006465c0();  // 0x006465c0
void Unwind_006465cb();  // 0x006465cb
void Unwind_006465d3();  // 0x006465d3
void Unwind_006465db();  // 0x006465db
void Unwind_006465e6();  // 0x006465e6
void Unwind_006465ee();  // 0x006465ee
void Unwind_006465f6();  // 0x006465f6
void Unwind_006465fe();  // 0x006465fe
void Unwind_00646609();  // 0x00646609
void Unwind_00646611();  // 0x00646611
void Unwind_00646619();  // 0x00646619
void Unwind_00646621();  // 0x00646621
void Unwind_00646629();  // 0x00646629
void Unwind_00646634();  // 0x00646634
void Unwind_0064663c();  // 0x0064663c
void Unwind_00646644();  // 0x00646644
void Unwind_0064664c();  // 0x0064664c
void Unwind_00646657();  // 0x00646657
void Unwind_0064665f();  // 0x0064665f
void Unwind_00646667();  // 0x00646667
void Unwind_0064666f();  // 0x0064666f
void Unwind_0064667a();  // 0x0064667a
void Unwind_00646682();  // 0x00646682
void Unwind_0064668a();  // 0x0064668a
void Unwind_00646692();  // 0x00646692
void Unwind_0064669d();  // 0x0064669d
void Unwind_006466a5();  // 0x006466a5
void Unwind_006466ad();  // 0x006466ad
void Unwind_006466b5();  // 0x006466b5
void Unwind_006466c0();  // 0x006466c0
void Unwind_006466c8();  // 0x006466c8
void Unwind_006466d0();  // 0x006466d0
void Unwind_006466d8();  // 0x006466d8
void Unwind_006466e3();  // 0x006466e3
void Unwind_006466eb();  // 0x006466eb
void Unwind_006466f3();  // 0x006466f3
void Unwind_006466fb();  // 0x006466fb
void Unwind_00646706();  // 0x00646706
void Unwind_00646740();  // 0x00646740
void Unwind_00646748();  // 0x00646748
void Unwind_00646780();  // 0x00646780
void Unwind_006467d0();  // 0x006467d0
void Unwind_006467f2();  // 0x006467f2
void Unwind_006467fa();  // 0x006467fa
void Unwind_00646802();  // 0x00646802
void Unwind_0064680d();  // 0x0064680d
void Unwind_00646815();  // 0x00646815
void Unwind_0064681d();  // 0x0064681d
void Unwind_00646825();  // 0x00646825
void Unwind_0064682d();  // 0x0064682d
void Unwind_00646835();  // 0x00646835
void Unwind_0064683d();  // 0x0064683d
void Unwind_00646845();  // 0x00646845
void Unwind_00646880();  // 0x00646880
void Unwind_00646888();  // 0x00646888
void Unwind_00646890();  // 0x00646890
void Unwind_00646898();  // 0x00646898
void Unwind_006468a0();  // 0x006468a0
void Unwind_006468a8();  // 0x006468a8
void Unwind_006468b3();  // 0x006468b3
void Unwind_006468f0();  // 0x006468f0
void Unwind_00646920();  // 0x00646920
void Unwind_0064692b();  // 0x0064692b
void Unwind_006469b0();  // 0x006469b0
void Unwind_006469e0();  // 0x006469e0
void Unwind_00646a10();  // 0x00646a10
void Unwind_00646a50();  // 0x00646a50
void Unwind_00646a58();  // 0x00646a58
void Unwind_00646a60();  // 0x00646a60
void Unwind_00646a90();  // 0x00646a90
void Unwind_00646a98();  // 0x00646a98
void Unwind_00646b10();  // 0x00646b10
void Unwind_00646b40();  // 0x00646b40
void Unwind_00646b70();  // 0x00646b70
void Unwind_00646b78();  // 0x00646b78
void Unwind_00646bb0();  // 0x00646bb0
void Unwind_00646c00();  // 0x00646c00
void Unwind_00646c08();  // 0x00646c08
void Unwind_00646c40();  // 0x00646c40
void Unwind_00646c48();  // 0x00646c48
void Unwind_00646c50();  // 0x00646c50
void Unwind_00646c80();  // 0x00646c80
void Unwind_00646cc0();  // 0x00646cc0
void Unwind_00646cc8();  // 0x00646cc8
void Unwind_00646cd0();  // 0x00646cd0
void Unwind_00646cd8();  // 0x00646cd8
void Unwind_00646d10();  // 0x00646d10
void Unwind_00646d70();  // 0x00646d70
void Unwind_00646d78();  // 0x00646d78
void Unwind_00646db0();  // 0x00646db0
void Unwind_00646dbb();  // 0x00646dbb
void Unwind_00646dc3();  // 0x00646dc3
void Unwind_00646dcb();  // 0x00646dcb
void Unwind_00646e10();  // 0x00646e10
void Unwind_00646e1b();  // 0x00646e1b
void Unwind_00646e23();  // 0x00646e23
void Unwind_00646e2e();  // 0x00646e2e
void Unwind_00646e36();  // 0x00646e36
void Unwind_00646e41();  // 0x00646e41
void Unwind_00646e80();  // 0x00646e80
void Unwind_00646e88();  // 0x00646e88
void Unwind_00646e93();  // 0x00646e93
void Unwind_00646e9e();  // 0x00646e9e
void Unwind_00646ea9();  // 0x00646ea9
void Unwind_00646eb1();  // 0x00646eb1
void Unwind_00646ebc();  // 0x00646ebc
void Unwind_00646ef0();  // 0x00646ef0
void Unwind_00646f30();  // 0x00646f30
void Unwind_00646f3b();  // 0x00646f3b
void Unwind_00646f70();  // 0x00646f70
void Unwind_00646fa0();  // 0x00646fa0
void Unwind_00646fd0();  // 0x00646fd0
void Unwind_00647020();  // 0x00647020
void Unwind_00647028();  // 0x00647028
void Unwind_00647060();  // 0x00647060
void Unwind_00647068();  // 0x00647068
void Unwind_00647070();  // 0x00647070
void Unwind_006470d0();  // 0x006470d0
void Unwind_006470d8();  // 0x006470d8
void Unwind_00647110();  // 0x00647110
void Unwind_00647118();  // 0x00647118
void Unwind_00647120();  // 0x00647120
void Unwind_00647150();  // 0x00647150
void Unwind_00647158();  // 0x00647158
void Unwind_00647160();  // 0x00647160
void Unwind_00647168();  // 0x00647168
void Unwind_00647170();  // 0x00647170
void Unwind_00647178();  // 0x00647178
void Unwind_00647180();  // 0x00647180
void Unwind_006471b0();  // 0x006471b0
void Unwind_006471b8();  // 0x006471b8
void Unwind_006471c0();  // 0x006471c0
void Unwind_006471c8();  // 0x006471c8
void Unwind_00647220();  // 0x00647220
void Unwind_00647270();  // 0x00647270
void Unwind_00647278();  // 0x00647278
void Unwind_006472b0();  // 0x006472b0
void Unwind_006472e0();  // 0x006472e0
void Unwind_00647330();  // 0x00647330
void Unwind_00647349();  // 0x00647349
void Unwind_00647351();  // 0x00647351
void Unwind_00647390();  // 0x00647390
void Unwind_00647398();  // 0x00647398
void Unwind_006473a3();  // 0x006473a3
void Unwind_006473ae();  // 0x006473ae
void Unwind_006473f0();  // 0x006473f0
void Unwind_006473f8();  // 0x006473f8
void Unwind_00647403();  // 0x00647403
void Unwind_00647430();  // 0x00647430
void Unwind_00647480();  // 0x00647480
void Unwind_00647488();  // 0x00647488
void Unwind_00647490();  // 0x00647490
void Unwind_006474c0();  // 0x006474c0
void Unwind_006474c8();  // 0x006474c8
void Unwind_006474d7();  // 0x006474d7
void Unwind_006474df();  // 0x006474df
void Unwind_006474e7();  // 0x006474e7
void Unwind_00647520();  // 0x00647520
void Unwind_00647528();  // 0x00647528
void Unwind_00647570();  // 0x00647570
void Unwind_006475b0();  // 0x006475b0
void Unwind_006475f0();  // 0x006475f0
void Unwind_006475f9();  // 0x006475f9
void Unwind_00647630();  // 0x00647630
void Unwind_00647639();  // 0x00647639
void Unwind_00647642();  // 0x00647642
void Unwind_0064764b();  // 0x0064764b
void Unwind_00647654();  // 0x00647654
void Unwind_0064765d();  // 0x0064765d
void Unwind_00647666();  // 0x00647666
void Unwind_0064766f();  // 0x0064766f
void Unwind_00647678();  // 0x00647678
void Unwind_00647681();  // 0x00647681
void Unwind_0064768a();  // 0x0064768a
void Unwind_00647693();  // 0x00647693
void Unwind_0064769c();  // 0x0064769c
void Unwind_006476d0();  // 0x006476d0
void Unwind_006476d9();  // 0x006476d9
void Unwind_006476e2();  // 0x006476e2
void Unwind_006476eb();  // 0x006476eb
void Unwind_006476f4();  // 0x006476f4
void Unwind_006476fd();  // 0x006476fd
void Unwind_00647706();  // 0x00647706
void Unwind_0064770f();  // 0x0064770f
void Unwind_00647718();  // 0x00647718
void Unwind_00647721();  // 0x00647721
void Unwind_0064772a();  // 0x0064772a
void Unwind_00647733();  // 0x00647733
void Unwind_0064773c();  // 0x0064773c
void Unwind_00647745();  // 0x00647745
void Unwind_0064774e();  // 0x0064774e
void Unwind_00647780();  // 0x00647780
void Unwind_006477c0();  // 0x006477c0
void Unwind_00647800();  // 0x00647800
void Unwind_00647830();  // 0x00647830
void Unwind_0064783b();  // 0x0064783b
void Unwind_00647846();  // 0x00647846
void Unwind_00647851();  // 0x00647851
void Unwind_00647890();  // 0x00647890
void Unwind_006478d0();  // 0x006478d0
void Unwind_00647910();  // 0x00647910
void Unwind_00647918();  // 0x00647918
void Unwind_00647950();  // 0x00647950
void Unwind_00647990();  // 0x00647990
void Unwind_00647998();  // 0x00647998
void Unwind_006479d0();  // 0x006479d0
void Unwind_00647a10();  // 0x00647a10
void Unwind_00647a50();  // 0x00647a50
void Unwind_00647a90();  // 0x00647a90
void Unwind_00647a98();  // 0x00647a98
void Unwind_00647aa3();  // 0x00647aa3
void Unwind_00647aae();  // 0x00647aae
void Unwind_00647ab9();  // 0x00647ab9
void Unwind_00647af0();  // 0x00647af0
void Unwind_00647af8();  // 0x00647af8
void Unwind_00647b00();  // 0x00647b00
void Unwind_00647b0f();  // 0x00647b0f
void Unwind_00647b28();  // 0x00647b28
void Unwind_00647b60();  // 0x00647b60
void Unwind_00647b68();  // 0x00647b68
void Unwind_00647b70();  // 0x00647b70
void Unwind_00647b78();  // 0x00647b78
void Unwind_00647bb0();  // 0x00647bb0
void Unwind_00647bb8();  // 0x00647bb8
void Unwind_00647bc3();  // 0x00647bc3
void Unwind_00647c00();  // 0x00647c00
void Unwind_00647c60();  // 0x00647c60
void Unwind_00647c68();  // 0x00647c68
void Unwind_00647ca0();  // 0x00647ca0
void Unwind_00647cd0();  // 0x00647cd0
void Unwind_00647d10();  // 0x00647d10
void Unwind_00647d70();  // 0x00647d70
void Unwind_00647da0();  // 0x00647da0
void Unwind_00647dd0();  // 0x00647dd0
void Unwind_00647dd8();  // 0x00647dd8
void Unwind_00647de3();  // 0x00647de3
void Unwind_00647e20();  // 0x00647e20
void Unwind_00647e35();  // 0x00647e35
void Unwind_00647e4a();  // 0x00647e4a
void Unwind_00647e90();  // 0x00647e90
void Unwind_00647e9b();  // 0x00647e9b
void Unwind_00647ea6();  // 0x00647ea6
void Unwind_00647ee0();  // 0x00647ee0
void Unwind_00647eeb();  // 0x00647eeb
void Unwind_00647f30();  // 0x00647f30
void Unwind_00647f70();  // 0x00647f70
void Unwind_00647fb0();  // 0x00647fb0
void Unwind_00647fb8();  // 0x00647fb8
void Unwind_00647ff0();  // 0x00647ff0
void Unwind_00648020();  // 0x00648020
void Unwind_00648050();  // 0x00648050
void Unwind_00648080();  // 0x00648080
void Unwind_00648088();  // 0x00648088
void Unwind_00648097();  // 0x00648097
void Unwind_0064809f();  // 0x0064809f
void Unwind_006480ae();  // 0x006480ae
void Unwind_006480bd();  // 0x006480bd
void Unwind_006480c5();  // 0x006480c5
void Unwind_006480d4();  // 0x006480d4
void Unwind_006480dc();  // 0x006480dc
void Unwind_00648120();  // 0x00648120
void Unwind_00648160();  // 0x00648160
void Unwind_006481a0();  // 0x006481a0
void Unwind_006481e0();  // 0x006481e0
void Unwind_006481e8();  // 0x006481e8
void Unwind_006481f0();  // 0x006481f0
void Unwind_006481f8();  // 0x006481f8
void Unwind_00648230();  // 0x00648230
void Unwind_00648260();  // 0x00648260
void Unwind_0064826b();  // 0x0064826b
void Unwind_00648276();  // 0x00648276
void Unwind_006482b0();  // 0x006482b0
void Unwind_006482f0();  // 0x006482f0
void Unwind_00648330();  // 0x00648330
void Unwind_0064834d();  // 0x0064834d
void Unwind_00648359();  // 0x00648359
void Unwind_00648390();  // 0x00648390
void Unwind_0064839b();  // 0x0064839b
void Unwind_006483d0();  // 0x006483d0
void Unwind_006483df();  // 0x006483df
void Unwind_006483e7();  // 0x006483e7
void Unwind_006483ef();  // 0x006483ef
void Unwind_00648420();  // 0x00648420
void Unwind_00648460();  // 0x00648460
void Unwind_006484a0();  // 0x006484a0
void Unwind_006484ab();  // 0x006484ab
void Unwind_006484b6();  // 0x006484b6
void Unwind_006484be();  // 0x006484be
void Unwind_006484c6();  // 0x006484c6
void Unwind_006484ce();  // 0x006484ce
void Unwind_006484d6();  // 0x006484d6
void Unwind_006484de();  // 0x006484de
void Unwind_006484e6();  // 0x006484e6
void Unwind_006484ee();  // 0x006484ee
void Unwind_006484f6();  // 0x006484f6
void Unwind_006484fe();  // 0x006484fe
void Unwind_00648506();  // 0x00648506
void Unwind_0064850e();  // 0x0064850e
void Unwind_00648516();  // 0x00648516
void Unwind_0064851e();  // 0x0064851e
void Unwind_00648526();  // 0x00648526
void Unwind_0064852e();  // 0x0064852e
void Unwind_00648536();  // 0x00648536
void Unwind_0064853e();  // 0x0064853e
void Unwind_00648546();  // 0x00648546
void Unwind_00648580();  // 0x00648580
void Unwind_0064858b();  // 0x0064858b
void Unwind_00648593();  // 0x00648593
void Unwind_0064859b();  // 0x0064859b
void Unwind_006485ad();  // 0x006485ad
void Unwind_006485b5();  // 0x006485b5
void Unwind_006485f0();  // 0x006485f0
void Unwind_006485fb();  // 0x006485fb
void Unwind_00648603();  // 0x00648603
void Unwind_0064860b();  // 0x0064860b
void Unwind_00648613();  // 0x00648613
void Unwind_0064861b();  // 0x0064861b
void Unwind_00648626();  // 0x00648626
void Unwind_00648660();  // 0x00648660
void Unwind_00648668();  // 0x00648668
void Unwind_00648670();  // 0x00648670
void Unwind_00648678();  // 0x00648678
void Unwind_006486b0();  // 0x006486b0
void Unwind_006486f0();  // 0x006486f0
void Unwind_006486f8();  // 0x006486f8
void Unwind_00648700();  // 0x00648700
void Unwind_00648740();  // 0x00648740
void Unwind_00648780();  // 0x00648780
void Unwind_0064878b();  // 0x0064878b
void Unwind_00648796();  // 0x00648796
void Unwind_006487a1();  // 0x006487a1
void Unwind_006487ac();  // 0x006487ac
void Unwind_006487b7();  // 0x006487b7
void Unwind_006487c2();  // 0x006487c2
void Unwind_006487cd();  // 0x006487cd
void Unwind_00648810();  // 0x00648810
void Unwind_00648850();  // 0x00648850
void Unwind_0064885b();  // 0x0064885b
void Unwind_00648866();  // 0x00648866
void Unwind_00648871();  // 0x00648871
void Unwind_0064887c();  // 0x0064887c
void Unwind_00648887();  // 0x00648887
void Unwind_00648892();  // 0x00648892
void Unwind_0064889d();  // 0x0064889d
void Unwind_006488e0();  // 0x006488e0
void Unwind_006488e8();  // 0x006488e8
void Unwind_00648920();  // 0x00648920
void Unwind_00648960();  // 0x00648960
void Unwind_006489b0();  // 0x006489b0
void Unwind_00648a00();  // 0x00648a00
void Unwind_00648a30();  // 0x00648a30
void Unwind_00648a38();  // 0x00648a38
void Unwind_00648a70();  // 0x00648a70
void Unwind_00648aa0();  // 0x00648aa0
void Unwind_00648aab();  // 0x00648aab
void Unwind_00648ae0();  // 0x00648ae0
void Unwind_00648b10();  // 0x00648b10
void Unwind_00648b40();  // 0x00648b40
void Unwind_00648b48();  // 0x00648b48
void Unwind_00648b80();  // 0x00648b80
void Unwind_00648bb0();  // 0x00648bb0
void Unwind_00648bb8();  // 0x00648bb8
void Unwind_00648bf0();  // 0x00648bf0
void Unwind_00648c40();  // 0x00648c40
void Unwind_00648c70();  // 0x00648c70
void Unwind_00648c7e();  // 0x00648c7e
void Unwind_00648c8c();  // 0x00648c8c
void Unwind_00648c9a();  // 0x00648c9a
void Unwind_00648ca8();  // 0x00648ca8
void Unwind_00648d40();  // 0x00648d40
void Unwind_00648d90();  // 0x00648d90
void Unwind_00648e60();  // 0x00648e60
void Unwind_00648e6b();  // 0x00648e6b
void Unwind_00648e79();  // 0x00648e79
void Unwind_00648e87();  // 0x00648e87
void Unwind_00648e95();  // 0x00648e95
void Unwind_00648ea3();  // 0x00648ea3
void Unwind_00648eb1();  // 0x00648eb1
void Unwind_00648ebf();  // 0x00648ebf
void Unwind_00648ecd();  // 0x00648ecd
void Unwind_00648edb();  // 0x00648edb
void Unwind_00648ee9();  // 0x00648ee9
void Unwind_00648ef7();  // 0x00648ef7
void Unwind_00648f05();  // 0x00648f05
void Unwind_00648f13();  // 0x00648f13
void Unwind_00648f21();  // 0x00648f21
void Unwind_00648f2f();  // 0x00648f2f
void Unwind_00648f3d();  // 0x00648f3d
void Unwind_00648f4b();  // 0x00648f4b
void Unwind_00648f59();  // 0x00648f59
void Unwind_00648f67();  // 0x00648f67
void Unwind_00648f75();  // 0x00648f75
void Unwind_00648f83();  // 0x00648f83
void Unwind_00648f91();  // 0x00648f91
void Unwind_00648f9f();  // 0x00648f9f
void Unwind_00648fad();  // 0x00648fad
void Unwind_00648fbb();  // 0x00648fbb
void Unwind_00648fc9();  // 0x00648fc9
void Unwind_00648fd7();  // 0x00648fd7
void Unwind_00648fe5();  // 0x00648fe5
void Unwind_00648ff3();  // 0x00648ff3
void Unwind_00649001();  // 0x00649001
void Unwind_0064900f();  // 0x0064900f
void Unwind_0064901d();  // 0x0064901d
void Unwind_0064902b();  // 0x0064902b
void Unwind_00649039();  // 0x00649039
void Unwind_00649047();  // 0x00649047
void Unwind_00649055();  // 0x00649055
void Unwind_00649063();  // 0x00649063
void Unwind_0064906e();  // 0x0064906e
void Unwind_00649079();  // 0x00649079
void Unwind_006490d0();  // 0x006490d0
void Unwind_00649140();  // 0x00649140
void Unwind_00649148();  // 0x00649148
void Unwind_00649180();  // 0x00649180
void Unwind_006491c0();  // 0x006491c0
void Unwind_00649200();  // 0x00649200
void Unwind_00649230();  // 0x00649230
void Unwind_00649270();  // 0x00649270
void Unwind_00649278();  // 0x00649278
void Unwind_006492b0();  // 0x006492b0
void Unwind_006492d2();  // 0x006492d2
void Unwind_006492f4();  // 0x006492f4
void Unwind_006492fc();  // 0x006492fc
void Unwind_00649340();  // 0x00649340
void Unwind_00649348();  // 0x00649348
void Unwind_00649350();  // 0x00649350
void Unwind_00649358();  // 0x00649358
void Unwind_00649360();  // 0x00649360
void Unwind_006493a0();  // 0x006493a0
void Unwind_006493e0();  // 0x006493e0
void Unwind_00649420();  // 0x00649420
void Unwind_00649460();  // 0x00649460
void Unwind_006494a0();  // 0x006494a0
void Unwind_006494a8();  // 0x006494a8
void Unwind_006494e0();  // 0x006494e0
void Unwind_00649520();  // 0x00649520
void Unwind_00649528();  // 0x00649528
void Unwind_00649560();  // 0x00649560
void Unwind_00649568();  // 0x00649568
void Unwind_006495a0();  // 0x006495a0
void Unwind_006495e0();  // 0x006495e0
void Unwind_00649620();  // 0x00649620
void Unwind_0064962b();  // 0x0064962b
void Unwind_00649636();  // 0x00649636
void Unwind_00649641();  // 0x00649641
void Unwind_00649680();  // 0x00649680
void Unwind_00649688();  // 0x00649688
void Unwind_006496c0();  // 0x006496c0
void Unwind_00649700();  // 0x00649700
void Unwind_0064970b();  // 0x0064970b
void Unwind_00649716();  // 0x00649716
void Unwind_00649750();  // 0x00649750
void Unwind_0064975b();  // 0x0064975b
void Unwind_006497a0();  // 0x006497a0
void Unwind_006497e0();  // 0x006497e0
void Unwind_006497e8();  // 0x006497e8
void Unwind_006497f0();  // 0x006497f0
void Unwind_006497f8();  // 0x006497f8
void Unwind_00649850();  // 0x00649850
void Unwind_00649880();  // 0x00649880
void Unwind_00649888();  // 0x00649888
void Unwind_006498c0();  // 0x006498c0
void Unwind_006498cb();  // 0x006498cb
void Unwind_006498d6();  // 0x006498d6
void Unwind_00649910();  // 0x00649910
void Unwind_00649918();  // 0x00649918
void Unwind_00649950();  // 0x00649950
void Unwind_00649962();  // 0x00649962
void Unwind_0064996a();  // 0x0064996a
void Unwind_00649972();  // 0x00649972
void Unwind_006499a0();  // 0x006499a0
void Unwind_006499a8();  // 0x006499a8
void Unwind_006499e0();  // 0x006499e0
void Unwind_006499e8();  // 0x006499e8
void Unwind_006499f0();  // 0x006499f0
void Unwind_006499f8();  // 0x006499f8
void Unwind_00649a00();  // 0x00649a00
void Unwind_00649a40();  // 0x00649a40
void Unwind_00649a48();  // 0x00649a48
void Unwind_00649a80();  // 0x00649a80
void Unwind_00649a88();  // 0x00649a88
void Unwind_00649a90();  // 0x00649a90
void Unwind_00649a98();  // 0x00649a98
void Unwind_00649ad0();  // 0x00649ad0
void Unwind_00649ad8();  // 0x00649ad8
void Unwind_00649ae0();  // 0x00649ae0
void Unwind_00649ae8();  // 0x00649ae8
void Unwind_00649af0();  // 0x00649af0
void Unwind_00649afb();  // 0x00649afb
void Unwind_00649b06();  // 0x00649b06
void Unwind_00649b40();  // 0x00649b40
void Unwind_00649b48();  // 0x00649b48
void Unwind_00649b5a();  // 0x00649b5a
void Unwind_00649b62();  // 0x00649b62
void Unwind_00649b6d();  // 0x00649b6d
void Unwind_00649b78();  // 0x00649b78
void Unwind_00649b80();  // 0x00649b80
void Unwind_00649b88();  // 0x00649b88
void Unwind_00649b90();  // 0x00649b90
void Unwind_00649b9b();  // 0x00649b9b
void Unwind_00649ba3();  // 0x00649ba3
void Unwind_00649bae();  // 0x00649bae
void Unwind_00649bb6();  // 0x00649bb6
void Unwind_00649bc1();  // 0x00649bc1
void Unwind_00649c00();  // 0x00649c00
void Unwind_00649c30();  // 0x00649c30
void Unwind_00649c38();  // 0x00649c38
void Unwind_00649c70();  // 0x00649c70
void Unwind_00649c78();  // 0x00649c78
void Unwind_00649c80();  // 0x00649c80
void Unwind_00649cc0();  // 0x00649cc0
void Unwind_00649cc8();  // 0x00649cc8
void Unwind_00649cd0();  // 0x00649cd0
void Unwind_00649cd8();  // 0x00649cd8
void Unwind_00649d10();  // 0x00649d10
void Unwind_00649d18();  // 0x00649d18
void Unwind_00649d2a();  // 0x00649d2a
void Unwind_00649d32();  // 0x00649d32
void Unwind_00649d44();  // 0x00649d44
void Unwind_00649da0();  // 0x00649da0
void Unwind_00649dab();  // 0x00649dab
void Unwind_00649db3();  // 0x00649db3
void Unwind_00649dc2();  // 0x00649dc2
void Unwind_00649dca();  // 0x00649dca
void Unwind_00649e00();  // 0x00649e00
void Unwind_00649e30();  // 0x00649e30
void Unwind_00649e38();  // 0x00649e38
void Unwind_00649e43();  // 0x00649e43
void Unwind_00649e4e();  // 0x00649e4e
void Unwind_00649e59();  // 0x00649e59
void Unwind_00649e64();  // 0x00649e64
void Unwind_00649e6c();  // 0x00649e6c
void Unwind_00649ea0();  // 0x00649ea0
void Unwind_00649ea8();  // 0x00649ea8
void Unwind_00649ee0();  // 0x00649ee0
void Unwind_00649ee8();  // 0x00649ee8
void Unwind_00649efa();  // 0x00649efa
void Unwind_00649f02();  // 0x00649f02
void Unwind_00649f30();  // 0x00649f30
void Unwind_00649f60();  // 0x00649f60
void Unwind_00649fa0();  // 0x00649fa0
void Unwind_00649fa8();  // 0x00649fa8
void Unwind_00649fe0();  // 0x00649fe0
void Unwind_00649fe8();  // 0x00649fe8
void Unwind_0064a020();  // 0x0064a020
void Unwind_0064a02b();  // 0x0064a02b
void Unwind_0064a036();  // 0x0064a036
void Unwind_0064a03e();  // 0x0064a03e
void Unwind_0064a049();  // 0x0064a049
void Unwind_0064a054();  // 0x0064a054
void Unwind_0064a080();  // 0x0064a080
void Unwind_0064a088();  // 0x0064a088
void Unwind_0064a0c0();  // 0x0064a0c0
void Unwind_0064a0cb();  // 0x0064a0cb
void Unwind_0064a0d6();  // 0x0064a0d6
void Unwind_0064a0e9();  // 0x0064a0e9
void Unwind_0064a0f1();  // 0x0064a0f1
void Unwind_0064a120();  // 0x0064a120
void Unwind_0064a128();  // 0x0064a128
void Unwind_0064a160();  // 0x0064a160
void Unwind_0064a16b();  // 0x0064a16b
void Unwind_0064a176();  // 0x0064a176
void Unwind_0064a184();  // 0x0064a184
void Unwind_0064a18f();  // 0x0064a18f
void Unwind_0064a19a();  // 0x0064a19a
void Unwind_0064a1a8();  // 0x0064a1a8
void Unwind_0064a1ba();  // 0x0064a1ba
void Unwind_0064a1c8();  // 0x0064a1c8
void Unwind_0064a1d6();  // 0x0064a1d6
void Unwind_0064a1e4();  // 0x0064a1e4
void Unwind_0064a1f2();  // 0x0064a1f2
void Unwind_0064a200();  // 0x0064a200
void Unwind_0064a20f();  // 0x0064a20f
void Unwind_0064a217();  // 0x0064a217
void Unwind_0064a229();  // 0x0064a229
void Unwind_0064a231();  // 0x0064a231
void Unwind_0064a270();  // 0x0064a270
void Unwind_0064a2a0();  // 0x0064a2a0
void Unwind_0064a2a8();  // 0x0064a2a8
void Unwind_0064a2b7();  // 0x0064a2b7
void Unwind_0064a300();  // 0x0064a300
void Unwind_0064a308();  // 0x0064a308
void Unwind_0064a340();  // 0x0064a340
void Unwind_0064a348();  // 0x0064a348
void Unwind_0064a350();  // 0x0064a350
void Unwind_0064a3b0();  // 0x0064a3b0
void Unwind_0064a3bb();  // 0x0064a3bb
void Unwind_0064a400();  // 0x0064a400
void Unwind_0064a408();  // 0x0064a408
void Unwind_0064a440();  // 0x0064a440
void Unwind_0064a470();  // 0x0064a470
void Unwind_0064a4b0();  // 0x0064a4b0
void Unwind_0064a4b8();  // 0x0064a4b8
void Unwind_0064a4c0();  // 0x0064a4c0
void Unwind_0064a4c8();  // 0x0064a4c8
void Unwind_0064a500();  // 0x0064a500
void Unwind_0064a508();  // 0x0064a508
void Unwind_0064a540();  // 0x0064a540
void Unwind_0064a548();  // 0x0064a548
void Unwind_0064a550();  // 0x0064a550
void Unwind_0064a562();  // 0x0064a562
void Unwind_0064a56a();  // 0x0064a56a
void Unwind_0064a5a0();  // 0x0064a5a0
void Unwind_0064a5ab();  // 0x0064a5ab
void Unwind_0064a5e0();  // 0x0064a5e0
void Unwind_0064a610();  // 0x0064a610
void Unwind_0064a640();  // 0x0064a640
void Unwind_0064a680();  // 0x0064a680
void Unwind_0064a6c0();  // 0x0064a6c0
void Unwind_0064a700();  // 0x0064a700
void Unwind_0064a730();  // 0x0064a730
void Unwind_0064a770();  // 0x0064a770
void Unwind_0064a7a0();  // 0x0064a7a0
void Unwind_0064a7e0();  // 0x0064a7e0
void Unwind_0064a820();  // 0x0064a820
void Unwind_0064a828();  // 0x0064a828
void Unwind_0064a830();  // 0x0064a830
void Unwind_0064a838();  // 0x0064a838
void Unwind_0064a840();  // 0x0064a840
void Unwind_0064a848();  // 0x0064a848
void Unwind_0064a850();  // 0x0064a850
void Unwind_0064a858();  // 0x0064a858
void Unwind_0064a860();  // 0x0064a860
void Unwind_0064a868();  // 0x0064a868
void Unwind_0064a870();  // 0x0064a870
void Unwind_0064a878();  // 0x0064a878
void Unwind_0064a880();  // 0x0064a880
void Unwind_0064a888();  // 0x0064a888
void Unwind_0064a890();  // 0x0064a890
void Unwind_0064a898();  // 0x0064a898
void Unwind_0064a8a0();  // 0x0064a8a0
void Unwind_0064a8a8();  // 0x0064a8a8
void Unwind_0064a8b0();  // 0x0064a8b0
void Unwind_0064a8b8();  // 0x0064a8b8
void Unwind_0064a8c0();  // 0x0064a8c0
void Unwind_0064a8c8();  // 0x0064a8c8
void Unwind_0064a8d0();  // 0x0064a8d0
void Unwind_0064a8d8();  // 0x0064a8d8
void Unwind_0064a8e0();  // 0x0064a8e0
void Unwind_0064a8e8();  // 0x0064a8e8
void Unwind_0064a8f0();  // 0x0064a8f0
void Unwind_0064a8f8();  // 0x0064a8f8
void Unwind_0064a900();  // 0x0064a900
void Unwind_0064a908();  // 0x0064a908
void Unwind_0064a910();  // 0x0064a910
void Unwind_0064a918();  // 0x0064a918
void Unwind_0064a920();  // 0x0064a920
void Unwind_0064a928();  // 0x0064a928
void Unwind_0064a930();  // 0x0064a930
void Unwind_0064a938();  // 0x0064a938
void Unwind_0064a940();  // 0x0064a940
void Unwind_0064a948();  // 0x0064a948
void Unwind_0064a950();  // 0x0064a950
void Unwind_0064a958();  // 0x0064a958
void Unwind_0064a960();  // 0x0064a960
void Unwind_0064a968();  // 0x0064a968
void Unwind_0064a970();  // 0x0064a970
void Unwind_0064a978();  // 0x0064a978
void Unwind_0064a980();  // 0x0064a980
void Unwind_0064a988();  // 0x0064a988
void Unwind_0064a990();  // 0x0064a990
void Unwind_0064a998();  // 0x0064a998
void Unwind_0064a9a0();  // 0x0064a9a0
void Unwind_0064a9a8();  // 0x0064a9a8
void Unwind_0064a9b0();  // 0x0064a9b0
void Unwind_0064a9b8();  // 0x0064a9b8
void Unwind_0064a9c0();  // 0x0064a9c0
void Unwind_0064a9c8();  // 0x0064a9c8
void Unwind_0064a9d0();  // 0x0064a9d0
void Unwind_0064a9d8();  // 0x0064a9d8
void Unwind_0064a9e0();  // 0x0064a9e0
void Unwind_0064a9e8();  // 0x0064a9e8
void Unwind_0064a9f0();  // 0x0064a9f0
void Unwind_0064a9f8();  // 0x0064a9f8
void Unwind_0064aa00();  // 0x0064aa00
void Unwind_0064aa08();  // 0x0064aa08
void Unwind_0064aa10();  // 0x0064aa10
void Unwind_0064aa18();  // 0x0064aa18
void Unwind_0064aa20();  // 0x0064aa20
void Unwind_0064aa28();  // 0x0064aa28
void Unwind_0064aa30();  // 0x0064aa30
void Unwind_0064aa38();  // 0x0064aa38
void Unwind_0064aa40();  // 0x0064aa40
void Unwind_0064aa48();  // 0x0064aa48
void Unwind_0064aa50();  // 0x0064aa50
void Unwind_0064aa58();  // 0x0064aa58
void Unwind_0064aa60();  // 0x0064aa60
void Unwind_0064aa68();  // 0x0064aa68
void Unwind_0064aa70();  // 0x0064aa70
void Unwind_0064aa78();  // 0x0064aa78
void Unwind_0064aa80();  // 0x0064aa80
void Unwind_0064aa88();  // 0x0064aa88
void Unwind_0064aa90();  // 0x0064aa90
void Unwind_0064aa98();  // 0x0064aa98
void Unwind_0064aaa0();  // 0x0064aaa0
void Unwind_0064aaa8();  // 0x0064aaa8
void Unwind_0064aab0();  // 0x0064aab0
void Unwind_0064aab8();  // 0x0064aab8
void Unwind_0064aac0();  // 0x0064aac0
void Unwind_0064aac8();  // 0x0064aac8
void Unwind_0064aad0();  // 0x0064aad0
void Unwind_0064aad8();  // 0x0064aad8
void Unwind_0064aae0();  // 0x0064aae0
void Unwind_0064aae8();  // 0x0064aae8
void Unwind_0064aaf0();  // 0x0064aaf0
void Unwind_0064ab20();  // 0x0064ab20
void Unwind_0064ab2b();  // 0x0064ab2b
void Unwind_0064ab39();  // 0x0064ab39
void Unwind_0064ab80();  // 0x0064ab80
void Unwind_0064abb0();  // 0x0064abb0
void Unwind_0064abf0();  // 0x0064abf0
void Unwind_0064ac30();  // 0x0064ac30
void Unwind_0064ac38();  // 0x0064ac38
void Unwind_0064ac70();  // 0x0064ac70
void Unwind_0064ac78();  // 0x0064ac78
void Unwind_0064ac80();  // 0x0064ac80
void Unwind_0064acb0();  // 0x0064acb0
void Unwind_0064acb8();  // 0x0064acb8
void Unwind_0064acc0();  // 0x0064acc0
void Unwind_0064acc8();  // 0x0064acc8
void Unwind_0064acd3();  // 0x0064acd3
void Unwind_0064acde();  // 0x0064acde
void Unwind_0064ace9();  // 0x0064ace9
void Unwind_0064ad20();  // 0x0064ad20
void Unwind_0064ad2b();  // 0x0064ad2b
void Unwind_0064ad60();  // 0x0064ad60
void Unwind_0064ad90();  // 0x0064ad90
void Unwind_0064ad98();  // 0x0064ad98
void Unwind_0064adaa();  // 0x0064adaa
void Unwind_0064adb2();  // 0x0064adb2
void Unwind_0064ade0();  // 0x0064ade0
void Unwind_0064ade8();  // 0x0064ade8
void Unwind_0064adf6();  // 0x0064adf6
void Unwind_0064ae04();  // 0x0064ae04
void Unwind_0064ae12();  // 0x0064ae12
void Unwind_0064ae1a();  // 0x0064ae1a
void Unwind_0064ae22();  // 0x0064ae22
void Unwind_0064ae2d();  // 0x0064ae2d
void Unwind_0064ae70();  // 0x0064ae70
void Unwind_0064aeb0();  // 0x0064aeb0
void Unwind_0064aebf();  // 0x0064aebf
void Unwind_0064aef0();  // 0x0064aef0
void Unwind_0064aeff();  // 0x0064aeff
void Unwind_0064af30();  // 0x0064af30
void Unwind_0064af60();  // 0x0064af60
void Unwind_0064afa0();  // 0x0064afa0
void Unwind_0064afe0();  // 0x0064afe0
void Unwind_0064b010();  // 0x0064b010
void Unwind_0064b018();  // 0x0064b018
void Unwind_0064b020();  // 0x0064b020
void Unwind_0064b028();  // 0x0064b028
void Unwind_0064b030();  // 0x0064b030
void Unwind_0064b038();  // 0x0064b038
void Unwind_0064b040();  // 0x0064b040
void Unwind_0064b0a0();  // 0x0064b0a0
void Unwind_0064b0af();  // 0x0064b0af
void Unwind_0064b0e0();  // 0x0064b0e0
void Unwind_0064b120();  // 0x0064b120
void Unwind_0064b160();  // 0x0064b160
void Unwind_0064b1a0();  // 0x0064b1a0
void Unwind_0064b1e0();  // 0x0064b1e0
void Unwind_0064b210();  // 0x0064b210
void Unwind_0064b240();  // 0x0064b240
void Unwind_0064b24b();  // 0x0064b24b
void Unwind_0064b256();  // 0x0064b256
void Unwind_0064b25e();  // 0x0064b25e
void Unwind_0064b266();  // 0x0064b266
void Unwind_0064b26e();  // 0x0064b26e
void Unwind_0064b276();  // 0x0064b276
void Unwind_0064b27e();  // 0x0064b27e
void Unwind_0064b286();  // 0x0064b286
void Unwind_0064b28e();  // 0x0064b28e
void Unwind_0064b296();  // 0x0064b296
void Unwind_0064b29e();  // 0x0064b29e
void Unwind_0064b2a6();  // 0x0064b2a6
void Unwind_0064b2ae();  // 0x0064b2ae
void Unwind_0064b2b6();  // 0x0064b2b6
void Unwind_0064b2be();  // 0x0064b2be
void Unwind_0064b2c6();  // 0x0064b2c6
void Unwind_0064b2ce();  // 0x0064b2ce
void Unwind_0064b2d6();  // 0x0064b2d6
void Unwind_0064b2de();  // 0x0064b2de
void Unwind_0064b2e6();  // 0x0064b2e6
void Unwind_0064b2ee();  // 0x0064b2ee
void Unwind_0064b330();  // 0x0064b330
void Unwind_0064b339();  // 0x0064b339
void Unwind_0064b342();  // 0x0064b342
void Unwind_0064b34b();  // 0x0064b34b
void Unwind_0064b354();  // 0x0064b354
void Unwind_0064b35d();  // 0x0064b35d
void Unwind_0064b390();  // 0x0064b390
void Unwind_0064b3c0();  // 0x0064b3c0
void Unwind_0064b3e2();  // 0x0064b3e2
void Unwind_0064b3ed();  // 0x0064b3ed
void Unwind_0064b430();  // 0x0064b430
void Unwind_0064b44d();  // 0x0064b44d
void Unwind_0064b459();  // 0x0064b459
void Unwind_0064b464();  // 0x0064b464
void Unwind_0064b490();  // 0x0064b490
void Unwind_0064b4c0();  // 0x0064b4c0
void Unwind_0064b4c8();  // 0x0064b4c8
void Unwind_0064b4d0();  // 0x0064b4d0
void Unwind_0064b4d8();  // 0x0064b4d8
void Unwind_0064b510();  // 0x0064b510
void Unwind_0064b540();  // 0x0064b540
void Unwind_0064b570();  // 0x0064b570
void Unwind_0064b5a0();  // 0x0064b5a0
void Unwind_0064b5ac();  // 0x0064b5ac
void Unwind_0064b5f0();  // 0x0064b5f0
void Unwind_0064b5f9();  // 0x0064b5f9
void Unwind_0064b602();  // 0x0064b602
void Unwind_0064b60e();  // 0x0064b60e
void Unwind_0064b61a();  // 0x0064b61a
void Unwind_0064b626();  // 0x0064b626
void Unwind_0064b660();  // 0x0064b660
void Unwind_0064b6a0();  // 0x0064b6a0
void Unwind_0064b6ab();  // 0x0064b6ab
void Unwind_0064b6b7();  // 0x0064b6b7
void Unwind_0064b6c0();  // 0x0064b6c0
void Unwind_0064b6c8();  // 0x0064b6c8
void Unwind_0064b700();  // 0x0064b700
void Unwind_0064b730();  // 0x0064b730
void Unwind_0064b738();  // 0x0064b738
void Unwind_0064b740();  // 0x0064b740
void Unwind_0064b748();  // 0x0064b748
void Unwind_0064b780();  // 0x0064b780
void Unwind_0064b7a2();  // 0x0064b7a2
void Unwind_0064b7aa();  // 0x0064b7aa
void Unwind_0064b7b2();  // 0x0064b7b2
void Unwind_0064b7d4();  // 0x0064b7d4
void Unwind_0064b7f6();  // 0x0064b7f6
void Unwind_0064b830();  // 0x0064b830
void Unwind_0064b843();  // 0x0064b843
void Unwind_0064b84b();  // 0x0064b84b
void Unwind_0064b853();  // 0x0064b853
void Unwind_0064b86c();  // 0x0064b86c
void Unwind_0064b874();  // 0x0064b874
void Unwind_0064b87c();  // 0x0064b87c
void Unwind_0064b8b0();  // 0x0064b8b0
void Unwind_0064b8b8();  // 0x0064b8b8
void Unwind_0064b8c0();  // 0x0064b8c0
void Unwind_0064b8c8();  // 0x0064b8c8
void Unwind_0064b900();  // 0x0064b900
void Unwind_0064b908();  // 0x0064b908
void Unwind_0064b940();  // 0x0064b940
void Unwind_0064b948();  // 0x0064b948
void Unwind_0064b950();  // 0x0064b950
void Unwind_0064b958();  // 0x0064b958
void Unwind_0064b960();  // 0x0064b960
void Unwind_0064b968();  // 0x0064b968
void Unwind_0064b9a0();  // 0x0064b9a0
void Unwind_0064b9d0();  // 0x0064b9d0
void Unwind_0064ba20();  // 0x0064ba20
void Unwind_0064ba90();  // 0x0064ba90
void Unwind_0064bac0();  // 0x0064bac0
void Unwind_0064baf0();  // 0x0064baf0
void Unwind_0064bb30();  // 0x0064bb30
void Unwind_0064bb60();  // 0x0064bb60
void Unwind_0064bb68();  // 0x0064bb68
void Unwind_0064bb70();  // 0x0064bb70
void Unwind_0064bb78();  // 0x0064bb78
void Unwind_0064bbb0();  // 0x0064bbb0
void Unwind_0064bbe0();  // 0x0064bbe0
void Unwind_0064bc20();  // 0x0064bc20
void Unwind_0064bc2b();  // 0x0064bc2b
void Unwind_0064bc70();  // 0x0064bc70
void Unwind_0064bcb0();  // 0x0064bcb0
void Unwind_0064bcb8();  // 0x0064bcb8
void Unwind_0064bcf0();  // 0x0064bcf0
void Unwind_0064bd20();  // 0x0064bd20
void Unwind_0064bd28();  // 0x0064bd28
void Unwind_0064bd60();  // 0x0064bd60
void Unwind_0064bd68();  // 0x0064bd68
void Unwind_0064bd70();  // 0x0064bd70
void Unwind_0064bdb0();  // 0x0064bdb0
void Unwind_0064bdf0();  // 0x0064bdf0
void Unwind_0064bdf8();  // 0x0064bdf8
void Unwind_0064be30();  // 0x0064be30
void Unwind_0064be38();  // 0x0064be38
void Unwind_0064be70();  // 0x0064be70
void Unwind_0064beb0();  // 0x0064beb0
void Unwind_0064bef0();  // 0x0064bef0
void Unwind_0064bf20();  // 0x0064bf20
void Unwind_0064bf42();  // 0x0064bf42
void Unwind_0064bf4a();  // 0x0064bf4a
void Unwind_0064bf52();  // 0x0064bf52
void Unwind_0064bf5a();  // 0x0064bf5a
void Unwind_0064bf65();  // 0x0064bf65
void Unwind_0064bf6d();  // 0x0064bf6d
void Unwind_0064bf78();  // 0x0064bf78
void Unwind_0064bf80();  // 0x0064bf80
void Unwind_0064bf88();  // 0x0064bf88
void Unwind_0064bfd0();  // 0x0064bfd0
void Unwind_0064c010();  // 0x0064c010
void Unwind_0064c018();  // 0x0064c018
void Unwind_0064c050();  // 0x0064c050
void Unwind_0064c080();  // 0x0064c080
void Unwind_0064c099();  // 0x0064c099
void Unwind_0064c0e0();  // 0x0064c0e0
void Unwind_0064c140();  // 0x0064c140
void Unwind_0064c180();  // 0x0064c180
void Unwind_0064c18b();  // 0x0064c18b
void Unwind_0064c196();  // 0x0064c196
void Unwind_0064c19e();  // 0x0064c19e
void Unwind_0064c1a9();  // 0x0064c1a9
void Unwind_0064c1e0();  // 0x0064c1e0
void Unwind_0064c220();  // 0x0064c220
void Unwind_0064c260();  // 0x0064c260
void Unwind_0064c279();  // 0x0064c279
void Unwind_0064c2b0();  // 0x0064c2b0
void Unwind_0064c2b8();  // 0x0064c2b8
void Unwind_0064c2c0();  // 0x0064c2c0
void Unwind_0064c300();  // 0x0064c300
void Unwind_0064c30f();  // 0x0064c30f
void Unwind_0064c317();  // 0x0064c317
void Unwind_0064c350();  // 0x0064c350
void Unwind_0064c390();  // 0x0064c390
void Unwind_0064c3d0();  // 0x0064c3d0
void Unwind_0064c410();  // 0x0064c410
void Unwind_0064c41b();  // 0x0064c41b
void Unwind_0064c426();  // 0x0064c426
void Unwind_0064c460();  // 0x0064c460
void Unwind_0064c490();  // 0x0064c490
void Unwind_0064c4c0();  // 0x0064c4c0
void Unwind_0064c500();  // 0x0064c500
void Unwind_0064c540();  // 0x0064c540
void Unwind_0064c580();  // 0x0064c580
void Unwind_0064c5c0();  // 0x0064c5c0
void Unwind_0064c600();  // 0x0064c600
void Unwind_0064c608();  // 0x0064c608
void Unwind_0064c640();  // 0x0064c640
void Unwind_0064c6a0();  // 0x0064c6a0
void Unwind_0064c6a8();  // 0x0064c6a8
void Unwind_0064c6e0();  // 0x0064c6e0
void Unwind_0064c720();  // 0x0064c720
void Unwind_0064c728();  // 0x0064c728
void Unwind_0064c730();  // 0x0064c730
void Unwind_0064c738();  // 0x0064c738
void Unwind_0064c740();  // 0x0064c740
void Unwind_0064c748();  // 0x0064c748
void Unwind_0064c750();  // 0x0064c750
void Unwind_0064c758();  // 0x0064c758
void Unwind_0064c790();  // 0x0064c790
void Unwind_0064c798();  // 0x0064c798
void Unwind_0064c7a0();  // 0x0064c7a0
void Unwind_0064c7a8();  // 0x0064c7a8
void Unwind_0064c7b0();  // 0x0064c7b0
void Unwind_0064c7b8();  // 0x0064c7b8
void Unwind_0064c7c7();  // 0x0064c7c7
void Unwind_0064c7cf();  // 0x0064c7cf
void Unwind_0064c7d7();  // 0x0064c7d7
void Unwind_0064c7df();  // 0x0064c7df
void Unwind_0064c7ee();  // 0x0064c7ee
void Unwind_0064c7f6();  // 0x0064c7f6
void Unwind_0064c7fe();  // 0x0064c7fe
void Unwind_0064c806();  // 0x0064c806
void Unwind_0064c80e();  // 0x0064c80e
void Unwind_0064c816();  // 0x0064c816
void Unwind_0064c81e();  // 0x0064c81e
void Unwind_0064c826();  // 0x0064c826
void Unwind_0064c860();  // 0x0064c860
void Unwind_0064c8a0();  // 0x0064c8a0
void Unwind_0064c8ac();  // 0x0064c8ac
void Unwind_0064c8e0();  // 0x0064c8e0
void Unwind_0064c920();  // 0x0064c920
void Unwind_0064c92a();  // 0x0064c92a
void Unwind_0064c960();  // 0x0064c960
void Unwind_0064c96b();  // 0x0064c96b
void Unwind_0064c9b0();  // 0x0064c9b0
void Unwind_0064c9f0();  // 0x0064c9f0
void Unwind_0064c9f8();  // 0x0064c9f8
void Unwind_0064ca00();  // 0x0064ca00
void Unwind_0064ca40();  // 0x0064ca40
void Unwind_0064ca48();  // 0x0064ca48
void Unwind_0064ca80();  // 0x0064ca80
void Unwind_0064cac0();  // 0x0064cac0
void Unwind_0064cac8();  // 0x0064cac8
void Unwind_0064cb00();  // 0x0064cb00
void Unwind_0064cb40();  // 0x0064cb40
void Unwind_0064cb4b();  // 0x0064cb4b
void Unwind_0064cb56();  // 0x0064cb56
void Unwind_0064cb5e();  // 0x0064cb5e
void Unwind_0064cb66();  // 0x0064cb66
void Unwind_0064cb6e();  // 0x0064cb6e
void Unwind_0064cb76();  // 0x0064cb76
void Unwind_0064cb7e();  // 0x0064cb7e
void Unwind_0064cb86();  // 0x0064cb86
void Unwind_0064cb8e();  // 0x0064cb8e
void Unwind_0064cb96();  // 0x0064cb96
void Unwind_0064cb9e();  // 0x0064cb9e
void Unwind_0064cba6();  // 0x0064cba6
void Unwind_0064cbae();  // 0x0064cbae
void Unwind_0064cbb6();  // 0x0064cbb6
void Unwind_0064cbbe();  // 0x0064cbbe
void Unwind_0064cc00();  // 0x0064cc00
void Unwind_0064cc08();  // 0x0064cc08
void Unwind_0064cc10();  // 0x0064cc10
void Unwind_0064cc50();  // 0x0064cc50
void Unwind_0064cc5f();  // 0x0064cc5f
void Unwind_0064cc90();  // 0x0064cc90
void Unwind_0064ccc0();  // 0x0064ccc0
void Unwind_0064ccf0();  // 0x0064ccf0
void Unwind_0064ccf8();  // 0x0064ccf8
void Unwind_0064cd00();  // 0x0064cd00
void Unwind_0064cd40();  // 0x0064cd40
void Unwind_0064cd80();  // 0x0064cd80
void Unwind_0064cd8b();  // 0x0064cd8b
void Unwind_0064cd96();  // 0x0064cd96
void Unwind_0064cda1();  // 0x0064cda1
void Unwind_0064cdd0();  // 0x0064cdd0
void Unwind_0064ce10();  // 0x0064ce10
void Unwind_0064ce60();  // 0x0064ce60
void Unwind_0064ce79();  // 0x0064ce79
void Unwind_0064ceb0();  // 0x0064ceb0
void Unwind_0064cec9();  // 0x0064cec9
void Unwind_0064ced1();  // 0x0064ced1
void Unwind_0064cf10();  // 0x0064cf10
void Unwind_0064cf18();  // 0x0064cf18
void Unwind_0064cf20();  // 0x0064cf20
void Unwind_0064cf60();  // 0x0064cf60
void Unwind_0064cf68();  // 0x0064cf68
void Unwind_0064cfa0();  // 0x0064cfa0
void Unwind_0064cfa8();  // 0x0064cfa8
void Unwind_0064cfe0();  // 0x0064cfe0
void Unwind_0064cfe8();  // 0x0064cfe8
void Unwind_0064cff0();  // 0x0064cff0
void Unwind_0064d030();  // 0x0064d030
void Unwind_0064d070();  // 0x0064d070
void Unwind_0064d0a0();  // 0x0064d0a0
void Unwind_0064d0a8();  // 0x0064d0a8
void Unwind_0064d0b3();  // 0x0064d0b3
void Unwind_0064d0be();  // 0x0064d0be
void Unwind_0064d0c9();  // 0x0064d0c9
void Unwind_0064d100();  // 0x0064d100
void Unwind_0064d108();  // 0x0064d108
void Unwind_0064d110();  // 0x0064d110
void Unwind_0064d140();  // 0x0064d140
void Unwind_0064d148();  // 0x0064d148
void Unwind_0064d150();  // 0x0064d150
void Unwind_0064d158();  // 0x0064d158
void Unwind_0064d190();  // 0x0064d190
void Unwind_0064d198();  // 0x0064d198
void Unwind_0064d1a0();  // 0x0064d1a0
void Unwind_0064d1e0();  // 0x0064d1e0
void Unwind_0064d1eb();  // 0x0064d1eb
void Unwind_0064d1f9();  // 0x0064d1f9
void Unwind_0064d207();  // 0x0064d207
void Unwind_0064d215();  // 0x0064d215
void Unwind_0064d223();  // 0x0064d223
void Unwind_0064d234();  // 0x0064d234
void Unwind_0064d245();  // 0x0064d245
void Unwind_0064d250();  // 0x0064d250
void Unwind_0064d258();  // 0x0064d258
void Unwind_0064d260();  // 0x0064d260
void Unwind_0064d268();  // 0x0064d268
void Unwind_0064d270();  // 0x0064d270
void Unwind_0064d2b0();  // 0x0064d2b0
void Unwind_0064d2bb();  // 0x0064d2bb
void Unwind_0064d2c7();  // 0x0064d2c7
void Unwind_0064d2d2();  // 0x0064d2d2
void Unwind_0064d2dd();  // 0x0064d2dd
void Unwind_0064d2e5();  // 0x0064d2e5
void Unwind_0064d2ed();  // 0x0064d2ed
void Unwind_0064d2f5();  // 0x0064d2f5
void Unwind_0064d2fd();  // 0x0064d2fd
void Unwind_0064d308();  // 0x0064d308
void Unwind_0064d310();  // 0x0064d310
void Unwind_0064d350();  // 0x0064d350
void Unwind_0064d380();  // 0x0064d380
void Unwind_0064d38b();  // 0x0064d38b
void Unwind_0064d397();  // 0x0064d397
void Unwind_0064d3a2();  // 0x0064d3a2
void Unwind_0064d3ad();  // 0x0064d3ad
void Unwind_0064d3b5();  // 0x0064d3b5
void Unwind_0064d3c7();  // 0x0064d3c7
void Unwind_0064d3d2();  // 0x0064d3d2
void Unwind_0064d3dd();  // 0x0064d3dd
void Unwind_0064d3e5();  // 0x0064d3e5
void Unwind_0064d3f0();  // 0x0064d3f0
void Unwind_0064d430();  // 0x0064d430
void Unwind_0064d438();  // 0x0064d438
void Unwind_0064d440();  // 0x0064d440
void Unwind_0064d448();  // 0x0064d448
void Unwind_0064d450();  // 0x0064d450
void Unwind_0064d490();  // 0x0064d490
void Unwind_0064d49b();  // 0x0064d49b
void Unwind_0064d4a7();  // 0x0064d4a7
void Unwind_0064d4b2();  // 0x0064d4b2
void Unwind_0064d4bd();  // 0x0064d4bd
void Unwind_0064d4c5();  // 0x0064d4c5
void Unwind_0064d4cd();  // 0x0064d4cd
void Unwind_0064d4d8();  // 0x0064d4d8
void Unwind_0064d4e3();  // 0x0064d4e3
void Unwind_0064d4ee();  // 0x0064d4ee
void Unwind_0064d4f6();  // 0x0064d4f6
void Unwind_0064d501();  // 0x0064d501
void Unwind_0064d50c();  // 0x0064d50c
void Unwind_0064d550();  // 0x0064d550
void Unwind_0064d580();  // 0x0064d580
void Unwind_0064d588();  // 0x0064d588
void Unwind_0064d5c0();  // 0x0064d5c0
void Unwind_0064d5d9();  // 0x0064d5d9
void Unwind_0064d5e1();  // 0x0064d5e1
void Unwind_0064d5ec();  // 0x0064d5ec
void Unwind_0064d5f4();  // 0x0064d5f4
void Unwind_0064d5fc();  // 0x0064d5fc
void Unwind_0064d607();  // 0x0064d607
void Unwind_0064d650();  // 0x0064d650
void Unwind_0064d658();  // 0x0064d658
void Unwind_0064d660();  // 0x0064d660
void Unwind_0064d668();  // 0x0064d668
void Unwind_0064d677();  // 0x0064d677
void Unwind_0064d682();  // 0x0064d682
void Unwind_0064d68a();  // 0x0064d68a
void Unwind_0064d692();  // 0x0064d692
void Unwind_0064d6d0();  // 0x0064d6d0
void Unwind_0064d6d8();  // 0x0064d6d8
void Unwind_0064d6e0();  // 0x0064d6e0
void Unwind_0064d710();  // 0x0064d710
void Unwind_0064d718();  // 0x0064d718
void Unwind_0064d720();  // 0x0064d720
void Unwind_0064d728();  // 0x0064d728
void Unwind_0064d730();  // 0x0064d730
void Unwind_0064d738();  // 0x0064d738
void Unwind_0064d770();  // 0x0064d770
void Unwind_0064d778();  // 0x0064d778
void Unwind_0064d7b0();  // 0x0064d7b0
void Unwind_0064d7f0();  // 0x0064d7f0
void Unwind_0064d7f8();  // 0x0064d7f8
void Unwind_0064d830();  // 0x0064d830
void Unwind_0064d838();  // 0x0064d838
void Unwind_0064d840();  // 0x0064d840
void Unwind_0064d848();  // 0x0064d848
void Unwind_0064d850();  // 0x0064d850
void Unwind_0064d858();  // 0x0064d858
void Unwind_0064d890();  // 0x0064d890
void Unwind_0064d898();  // 0x0064d898
void Unwind_0064d8a3();  // 0x0064d8a3
void Unwind_0064d8e0();  // 0x0064d8e0
void Unwind_0064d8e8();  // 0x0064d8e8
void Unwind_0064d90a();  // 0x0064d90a
void Unwind_0064d915();  // 0x0064d915
void Unwind_0064d920();  // 0x0064d920
void Unwind_0064d92b();  // 0x0064d92b
void Unwind_0064d936();  // 0x0064d936
void Unwind_0064d941();  // 0x0064d941
void Unwind_0064d94c();  // 0x0064d94c
void Unwind_0064d990();  // 0x0064d990
void Unwind_0064d9c0();  // 0x0064d9c0
void Unwind_0064d9c8();  // 0x0064d9c8
void Unwind_0064d9d0();  // 0x0064d9d0
void Unwind_0064d9d8();  // 0x0064d9d8
void Unwind_0064d9f1();  // 0x0064d9f1
void Unwind_0064da30();  // 0x0064da30
void Unwind_0064da49();  // 0x0064da49
void Unwind_0064da58();  // 0x0064da58
void Unwind_0064da60();  // 0x0064da60
void Unwind_0064da68();  // 0x0064da68
void Unwind_0064da73();  // 0x0064da73
void Unwind_0064da7b();  // 0x0064da7b
void Unwind_0064dab0();  // 0x0064dab0
void Unwind_0064dab8();  // 0x0064dab8
void Unwind_0064dac0();  // 0x0064dac0
void Unwind_0064daf0();  // 0x0064daf0
void Unwind_0064db09();  // 0x0064db09
void Unwind_0064db11();  // 0x0064db11
void Unwind_0064db20();  // 0x0064db20
void Unwind_0064db28();  // 0x0064db28
void Unwind_0064db30();  // 0x0064db30
void Unwind_0064db3b();  // 0x0064db3b
void Unwind_0064db43();  // 0x0064db43
void Unwind_0064db70();  // 0x0064db70
void Unwind_0064db7b();  // 0x0064db7b
void Unwind_0064db86();  // 0x0064db86
void Unwind_0064db8e();  // 0x0064db8e
void Unwind_0064db96();  // 0x0064db96
void Unwind_0064db9e();  // 0x0064db9e
void Unwind_0064dba6();  // 0x0064dba6
void Unwind_0064dbae();  // 0x0064dbae
void Unwind_0064dbb6();  // 0x0064dbb6
void Unwind_0064dbbe();  // 0x0064dbbe
void Unwind_0064dbc9();  // 0x0064dbc9
void Unwind_0064dc00();  // 0x0064dc00
void Unwind_0064dc08();  // 0x0064dc08
void Unwind_0064dc10();  // 0x0064dc10
void Unwind_0064dc29();  // 0x0064dc29
void Unwind_0064dc70();  // 0x0064dc70
void Unwind_0064dc78();  // 0x0064dc78
void Unwind_0064dc91();  // 0x0064dc91
void Unwind_0064dcd0();  // 0x0064dcd0
void Unwind_0064dd00();  // 0x0064dd00
void Unwind_0064dd08();  // 0x0064dd08
void Unwind_0064dd10();  // 0x0064dd10
void Unwind_0064dd18();  // 0x0064dd18
void Unwind_0064dd50();  // 0x0064dd50
void Unwind_0064dd58();  // 0x0064dd58
void Unwind_0064dd67();  // 0x0064dd67
void Unwind_0064dd6f();  // 0x0064dd6f
void Unwind_0064dd77();  // 0x0064dd77
void Unwind_0064dd82();  // 0x0064dd82
void Unwind_0064ddb0();  // 0x0064ddb0
void Unwind_0064ddb8();  // 0x0064ddb8
void Unwind_0064ddf0();  // 0x0064ddf0
void Unwind_0064ddfb();  // 0x0064ddfb
void Unwind_0064de03();  // 0x0064de03
void Unwind_0064de0b();  // 0x0064de0b
void Unwind_0064de16();  // 0x0064de16
void Unwind_0064de1e();  // 0x0064de1e
void Unwind_0064de26();  // 0x0064de26
void Unwind_0064de2e();  // 0x0064de2e
void Unwind_0064de39();  // 0x0064de39
void Unwind_0064de41();  // 0x0064de41
void Unwind_0064de49();  // 0x0064de49
void Unwind_0064de51();  // 0x0064de51
void Unwind_0064de59();  // 0x0064de59
void Unwind_0064de64();  // 0x0064de64
void Unwind_0064de6c();  // 0x0064de6c
void Unwind_0064de74();  // 0x0064de74
void Unwind_0064de7c();  // 0x0064de7c
void Unwind_0064de87();  // 0x0064de87
void Unwind_0064de8f();  // 0x0064de8f
void Unwind_0064de97();  // 0x0064de97
void Unwind_0064de9f();  // 0x0064de9f
void Unwind_0064deaa();  // 0x0064deaa
void Unwind_0064deb2();  // 0x0064deb2
void Unwind_0064deba();  // 0x0064deba
void Unwind_0064dec2();  // 0x0064dec2
void Unwind_0064decd();  // 0x0064decd
void Unwind_0064ded5();  // 0x0064ded5
void Unwind_0064dedd();  // 0x0064dedd
void Unwind_0064dee5();  // 0x0064dee5
void Unwind_0064def0();  // 0x0064def0
void Unwind_0064def8();  // 0x0064def8
void Unwind_0064df00();  // 0x0064df00
void Unwind_0064df08();  // 0x0064df08
void Unwind_0064df13();  // 0x0064df13
void Unwind_0064df1b();  // 0x0064df1b
void Unwind_0064df23();  // 0x0064df23
void Unwind_0064df2b();  // 0x0064df2b
void Unwind_0064df36();  // 0x0064df36
void Unwind_0064df70();  // 0x0064df70
void Unwind_0064df7b();  // 0x0064df7b
void Unwind_0064df83();  // 0x0064df83
void Unwind_0064df8b();  // 0x0064df8b
void Unwind_0064df96();  // 0x0064df96
void Unwind_0064df9e();  // 0x0064df9e
void Unwind_0064dfa6();  // 0x0064dfa6
void Unwind_0064dfae();  // 0x0064dfae
void Unwind_0064dfb9();  // 0x0064dfb9
void Unwind_0064dfc1();  // 0x0064dfc1
void Unwind_0064dfc9();  // 0x0064dfc9
void Unwind_0064dfd1();  // 0x0064dfd1
void Unwind_0064dfd9();  // 0x0064dfd9
void Unwind_0064dfe4();  // 0x0064dfe4
void Unwind_0064dfec();  // 0x0064dfec
void Unwind_0064dff4();  // 0x0064dff4
void Unwind_0064dffc();  // 0x0064dffc
void Unwind_0064e007();  // 0x0064e007
void Unwind_0064e00f();  // 0x0064e00f
void Unwind_0064e017();  // 0x0064e017
void Unwind_0064e01f();  // 0x0064e01f
void Unwind_0064e02a();  // 0x0064e02a
void Unwind_0064e032();  // 0x0064e032
void Unwind_0064e03a();  // 0x0064e03a
void Unwind_0064e042();  // 0x0064e042
void Unwind_0064e04d();  // 0x0064e04d
void Unwind_0064e055();  // 0x0064e055
void Unwind_0064e05d();  // 0x0064e05d
void Unwind_0064e065();  // 0x0064e065
void Unwind_0064e070();  // 0x0064e070
void Unwind_0064e078();  // 0x0064e078
void Unwind_0064e080();  // 0x0064e080
void Unwind_0064e088();  // 0x0064e088
void Unwind_0064e093();  // 0x0064e093
void Unwind_0064e09b();  // 0x0064e09b
void Unwind_0064e0a3();  // 0x0064e0a3
void Unwind_0064e0ab();  // 0x0064e0ab
void Unwind_0064e0b6();  // 0x0064e0b6
void Unwind_0064e0f0();  // 0x0064e0f0
void Unwind_0064e120();  // 0x0064e120
void Unwind_0064e128();  // 0x0064e128
void Unwind_0064e130();  // 0x0064e130
void Unwind_0064e138();  // 0x0064e138
void Unwind_0064e140();  // 0x0064e140
void Unwind_0064e148();  // 0x0064e148
void Unwind_0064e180();  // 0x0064e180
void Unwind_0064e188();  // 0x0064e188
void Unwind_0064e1c0();  // 0x0064e1c0
void Unwind_0064e1f0();  // 0x0064e1f0
void Unwind_0064e220();  // 0x0064e220
void Unwind_0064e250();  // 0x0064e250
void Unwind_0064e258();  // 0x0064e258
void Unwind_0064e271();  // 0x0064e271
void Unwind_0064e279();  // 0x0064e279
void Unwind_0064e281();  // 0x0064e281
void Unwind_0064e289();  // 0x0064e289
void Unwind_0064e291();  // 0x0064e291
void Unwind_0064e299();  // 0x0064e299
void Unwind_0064e2b2();  // 0x0064e2b2
void Unwind_0064e2c5();  // 0x0064e2c5
void Unwind_0064e2f0();  // 0x0064e2f0
void Unwind_0064e320();  // 0x0064e320
void Unwind_0064e350();  // 0x0064e350
void Unwind_0064e380();  // 0x0064e380
void Unwind_0064e3b0();  // 0x0064e3b0
void Unwind_0064e3e0();  // 0x0064e3e0
void Unwind_0064e410();  // 0x0064e410
void Unwind_0064e440();  // 0x0064e440
void Unwind_0064e490();  // 0x0064e490
void Unwind_0064e4b2();  // 0x0064e4b2
void Unwind_0064e4ba();  // 0x0064e4ba
void Unwind_0064e4c2();  // 0x0064e4c2
void Unwind_0064e4cd();  // 0x0064e4cd
void Unwind_0064e4d5();  // 0x0064e4d5
void Unwind_0064e4dd();  // 0x0064e4dd
void Unwind_0064e4e5();  // 0x0064e4e5
void Unwind_0064e4ed();  // 0x0064e4ed
void Unwind_0064e4f5();  // 0x0064e4f5
void Unwind_0064e4fd();  // 0x0064e4fd
void Unwind_0064e505();  // 0x0064e505
void Unwind_0064e540();  // 0x0064e540
void Unwind_0064e548();  // 0x0064e548
void Unwind_0064e5a0();  // 0x0064e5a0
void Unwind_0064e5a8();  // 0x0064e5a8
void Unwind_0064e5b0();  // 0x0064e5b0
void Unwind_0064e5b8();  // 0x0064e5b8
void Unwind_0064e5c0();  // 0x0064e5c0
void Unwind_0064e5c8();  // 0x0064e5c8
void Unwind_0064e600();  // 0x0064e600
void Unwind_0064e608();  // 0x0064e608
void Unwind_0064e610();  // 0x0064e610
void Unwind_0064e618();  // 0x0064e618
void Unwind_0064e650();  // 0x0064e650
void Unwind_0064e658();  // 0x0064e658
void Unwind_0064e690();  // 0x0064e690
void Unwind_0064e698();  // 0x0064e698
void Unwind_0064e6d0();  // 0x0064e6d0
void Unwind_0064e6d8();  // 0x0064e6d8
void Unwind_0064e6e0();  // 0x0064e6e0
void Unwind_0064e6e8();  // 0x0064e6e8
void Unwind_0064e720();  // 0x0064e720
void Unwind_0064e728();  // 0x0064e728
void Unwind_0064e730();  // 0x0064e730
void Unwind_0064e738();  // 0x0064e738
void Unwind_0064e770();  // 0x0064e770
void Unwind_0064e778();  // 0x0064e778
void Unwind_0064e780();  // 0x0064e780
void Unwind_0064e788();  // 0x0064e788
void Unwind_0064e790();  // 0x0064e790
void Unwind_0064e79b();  // 0x0064e79b
void Unwind_0064e7e0();  // 0x0064e7e0
void Unwind_0064e7e8();  // 0x0064e7e8
void Unwind_0064e840();  // 0x0064e840
void Unwind_0064e848();  // 0x0064e848
void Unwind_0064e880();  // 0x0064e880
void Unwind_0064e888();  // 0x0064e888
void Unwind_0064e890();  // 0x0064e890
void Unwind_0064e898();  // 0x0064e898
void Unwind_0064e8a0();  // 0x0064e8a0
void Unwind_0064e8a8();  // 0x0064e8a8
void Unwind_0064e8b0();  // 0x0064e8b0
void Unwind_0064e8e0();  // 0x0064e8e0
void Unwind_0064e8f9();  // 0x0064e8f9
void Unwind_0064e901();  // 0x0064e901
void Unwind_0064e910();  // 0x0064e910
void Unwind_0064e918();  // 0x0064e918
void Unwind_0064e920();  // 0x0064e920
void Unwind_0064e92b();  // 0x0064e92b
void Unwind_0064e933();  // 0x0064e933
void Unwind_0064e960();  // 0x0064e960
void Unwind_0064e968();  // 0x0064e968
void Unwind_0064e970();  // 0x0064e970
void Unwind_0064e9a0();  // 0x0064e9a0
void Unwind_0064e9b9();  // 0x0064e9b9
void Unwind_0064e9c1();  // 0x0064e9c1
void Unwind_0064e9d0();  // 0x0064e9d0
void Unwind_0064e9d8();  // 0x0064e9d8
void Unwind_0064e9e0();  // 0x0064e9e0
void Unwind_0064e9eb();  // 0x0064e9eb
void Unwind_0064e9f3();  // 0x0064e9f3
void Unwind_0064ea20();  // 0x0064ea20
void Unwind_0064ea39();  // 0x0064ea39
void Unwind_0064ea41();  // 0x0064ea41
void Unwind_0064ea50();  // 0x0064ea50
void Unwind_0064ea58();  // 0x0064ea58
void Unwind_0064ea60();  // 0x0064ea60
void Unwind_0064ea6b();  // 0x0064ea6b
void Unwind_0064ea73();  // 0x0064ea73
void Unwind_0064eaa0();  // 0x0064eaa0
void Unwind_0064eaaf();  // 0x0064eaaf
void Unwind_0064eab7();  // 0x0064eab7
void Unwind_0064eabf();  // 0x0064eabf
void Unwind_0064eac7();  // 0x0064eac7
void Unwind_0064eacf();  // 0x0064eacf
void Unwind_0064eb10();  // 0x0064eb10
void Unwind_0064eb18();  // 0x0064eb18
void Unwind_0064eb20();  // 0x0064eb20
void Unwind_0064eb28();  // 0x0064eb28
void Unwind_0064eb30();  // 0x0064eb30
void Unwind_0064eb38();  // 0x0064eb38
void Unwind_0064eb40();  // 0x0064eb40
void Unwind_0064eb48();  // 0x0064eb48
void Unwind_0064eb50();  // 0x0064eb50
void Unwind_0064eb58();  // 0x0064eb58
void Unwind_0064eb90();  // 0x0064eb90
void Unwind_0064eb98();  // 0x0064eb98
void Unwind_0064eba0();  // 0x0064eba0
void Unwind_0064ebe0();  // 0x0064ebe0
void Unwind_0064ebf9();  // 0x0064ebf9
void Unwind_0064ec08();  // 0x0064ec08
void Unwind_0064ec10();  // 0x0064ec10
void Unwind_0064ec18();  // 0x0064ec18
void Unwind_0064ec23();  // 0x0064ec23
void Unwind_0064ec2b();  // 0x0064ec2b
void Unwind_0064ec60();  // 0x0064ec60
void Unwind_0064ec68();  // 0x0064ec68
void Unwind_0064ec70();  // 0x0064ec70
void Unwind_0064ec78();  // 0x0064ec78
void Unwind_0064ec91();  // 0x0064ec91
void Unwind_0064ecd0();  // 0x0064ecd0
void Unwind_0064ece9();  // 0x0064ece9
void Unwind_0064ecf8();  // 0x0064ecf8
void Unwind_0064ed00();  // 0x0064ed00
void Unwind_0064ed08();  // 0x0064ed08
void Unwind_0064ed13();  // 0x0064ed13
void Unwind_0064ed1b();  // 0x0064ed1b
void Unwind_0064ed50();  // 0x0064ed50
void Unwind_0064ed69();  // 0x0064ed69
void Unwind_0064ed78();  // 0x0064ed78
void Unwind_0064ed80();  // 0x0064ed80
void Unwind_0064ed88();  // 0x0064ed88
void Unwind_0064ed93();  // 0x0064ed93
void Unwind_0064ed9b();  // 0x0064ed9b
void Unwind_0064edd0();  // 0x0064edd0
void Unwind_0064edd8();  // 0x0064edd8
void Unwind_0064ede0();  // 0x0064ede0
void Unwind_0064edeb();  // 0x0064edeb
void Unwind_0064ee30();  // 0x0064ee30
void Unwind_0064ee60();  // 0x0064ee60
void Unwind_0064ee90();  // 0x0064ee90
void Unwind_0064eec0();  // 0x0064eec0
void Unwind_0064eef0();  // 0x0064eef0
void Unwind_0064ef20();  // 0x0064ef20
void Unwind_0064ef28();  // 0x0064ef28
void Unwind_0064ef60();  // 0x0064ef60
void Unwind_0064ef79();  // 0x0064ef79
void Unwind_0064ef81();  // 0x0064ef81
void Unwind_0064ef90();  // 0x0064ef90
void Unwind_0064ef98();  // 0x0064ef98
void Unwind_0064efa0();  // 0x0064efa0
void Unwind_0064efab();  // 0x0064efab
void Unwind_0064efb3();  // 0x0064efb3
void Unwind_0064efe0();  // 0x0064efe0
void Unwind_0064eff9();  // 0x0064eff9
void Unwind_0064f001();  // 0x0064f001
void Unwind_0064f010();  // 0x0064f010
void Unwind_0064f018();  // 0x0064f018
void Unwind_0064f020();  // 0x0064f020
void Unwind_0064f02b();  // 0x0064f02b
void Unwind_0064f033();  // 0x0064f033
void Unwind_0064f060();  // 0x0064f060
void Unwind_0064f068();  // 0x0064f068
void Unwind_0064f070();  // 0x0064f070
void Unwind_0064f078();  // 0x0064f078
void Unwind_0064f080();  // 0x0064f080
void Unwind_0064f0b0();  // 0x0064f0b0
void Unwind_0064f0b8();  // 0x0064f0b8
void Unwind_0064f0f0();  // 0x0064f0f0
void Unwind_0064f120();  // 0x0064f120
void Unwind_0064f150();  // 0x0064f150
void Unwind_0064f180();  // 0x0064f180
void Unwind_0064f188();  // 0x0064f188
void Unwind_0064f1c0();  // 0x0064f1c0
void Unwind_0064f1c8();  // 0x0064f1c8
void Unwind_0064f1d0();  // 0x0064f1d0
void Unwind_0064f200();  // 0x0064f200
void Unwind_0064f230();  // 0x0064f230
void Unwind_0064f260();  // 0x0064f260
void Unwind_0064f290();  // 0x0064f290
void Unwind_0064f298();  // 0x0064f298
void Unwind_0064f2a0();  // 0x0064f2a0
void Unwind_0064f2a8();  // 0x0064f2a8
void Unwind_0064f2b0();  // 0x0064f2b0
void Unwind_0064f2b8();  // 0x0064f2b8
void Unwind_0064f2c0();  // 0x0064f2c0
void Unwind_0064f2c8();  // 0x0064f2c8
void Unwind_0064f2e1();  // 0x0064f2e1
void Unwind_0064f2e9();  // 0x0064f2e9
void Unwind_0064f320();  // 0x0064f320
void Unwind_0064f328();  // 0x0064f328
void Unwind_0064f330();  // 0x0064f330
void Unwind_0064f338();  // 0x0064f338
void Unwind_0064f343();  // 0x0064f343
void Unwind_0064f34b();  // 0x0064f34b
void Unwind_0064f353();  // 0x0064f353
void Unwind_0064f35e();  // 0x0064f35e
void Unwind_0064f3a0();  // 0x0064f3a0
void Unwind_0064f3a8();  // 0x0064f3a8
void Unwind_0064f3c1();  // 0x0064f3c1
void Unwind_0064f3c9();  // 0x0064f3c9
void Unwind_0064f3d1();  // 0x0064f3d1
void Unwind_0064f400();  // 0x0064f400
void Unwind_0064f430();  // 0x0064f430
void Unwind_0064f438();  // 0x0064f438
void Unwind_0064f440();  // 0x0064f440
void Unwind_0064f44b();  // 0x0064f44b
void Unwind_0064f490();  // 0x0064f490
void Unwind_0064f498();  // 0x0064f498
void Unwind_0064f4d0();  // 0x0064f4d0
void Unwind_0064f4d8();  // 0x0064f4d8
void Unwind_0064f510();  // 0x0064f510
void Unwind_0064f518();  // 0x0064f518
void Unwind_0064f550();  // 0x0064f550
void Unwind_0064f558();  // 0x0064f558
void Unwind_0064f563();  // 0x0064f563
void Unwind_0064f56e();  // 0x0064f56e
void Unwind_0064f579();  // 0x0064f579
void Unwind_0064f584();  // 0x0064f584
void Unwind_0064f592();  // 0x0064f592
void Unwind_0064f59a();  // 0x0064f59a
void Unwind_0064f5a2();  // 0x0064f5a2
void Unwind_0064f5d0();  // 0x0064f5d0
void Unwind_0064f5e9();  // 0x0064f5e9
void Unwind_0064f5f1();  // 0x0064f5f1
void Unwind_0064f600();  // 0x0064f600
void Unwind_0064f608();  // 0x0064f608
void Unwind_0064f610();  // 0x0064f610
void Unwind_0064f61b();  // 0x0064f61b
void Unwind_0064f623();  // 0x0064f623
void Unwind_0064f650();  // 0x0064f650
void Unwind_0064f669();  // 0x0064f669
void Unwind_0064f671();  // 0x0064f671
void Unwind_0064f680();  // 0x0064f680
void Unwind_0064f688();  // 0x0064f688
void Unwind_0064f690();  // 0x0064f690
void Unwind_0064f69b();  // 0x0064f69b
void Unwind_0064f6a3();  // 0x0064f6a3
void Unwind_0064f6d0();  // 0x0064f6d0
void Unwind_0064f6e9();  // 0x0064f6e9
void Unwind_0064f6f1();  // 0x0064f6f1
void Unwind_0064f700();  // 0x0064f700
void Unwind_0064f708();  // 0x0064f708
void Unwind_0064f710();  // 0x0064f710
void Unwind_0064f71b();  // 0x0064f71b
void Unwind_0064f723();  // 0x0064f723
void Unwind_0064f750();  // 0x0064f750
void Unwind_0064f780();  // 0x0064f780
void Unwind_0064f7b0();  // 0x0064f7b0
void Unwind_0064f7e0();  // 0x0064f7e0
void Unwind_0064f7e8();  // 0x0064f7e8
void Unwind_0064f820();  // 0x0064f820
void Unwind_0064f850();  // 0x0064f850
void Unwind_0064f858();  // 0x0064f858
void Unwind_0064f890();  // 0x0064f890
void Unwind_0064f89f();  // 0x0064f89f
void Unwind_0064f8d0();  // 0x0064f8d0
void Unwind_0064f900();  // 0x0064f900
void Unwind_0064f908();  // 0x0064f908
void Unwind_0064f910();  // 0x0064f910
void Unwind_0064f918();  // 0x0064f918
void Unwind_0064f920();  // 0x0064f920
void Unwind_0064f928();  // 0x0064f928
void Unwind_0064f960();  // 0x0064f960
void Unwind_0064f990();  // 0x0064f990
void Unwind_0064f998();  // 0x0064f998
void Unwind_0064f9d0();  // 0x0064f9d0
void Unwind_0064fa00();  // 0x0064fa00
void Unwind_0064fa08();  // 0x0064fa08
void Unwind_0064fa40();  // 0x0064fa40
void Unwind_0064fa48();  // 0x0064fa48
void Unwind_0064fa80();  // 0x0064fa80
void Unwind_0064fab0();  // 0x0064fab0
void Unwind_0064fabf();  // 0x0064fabf
void Unwind_0064fac7();  // 0x0064fac7
void Unwind_0064facf();  // 0x0064facf
void Unwind_0064fb00();  // 0x0064fb00
void Unwind_0064fb08();  // 0x0064fb08
void Unwind_0064fb21();  // 0x0064fb21
void Unwind_0064fb29();  // 0x0064fb29
void Unwind_0064fb31();  // 0x0064fb31
void Unwind_0064fb39();  // 0x0064fb39
void Unwind_0064fb70();  // 0x0064fb70
void Unwind_0064fba0();  // 0x0064fba0
void Unwind_0064fbd0();  // 0x0064fbd0
void Unwind_0064fbd8();  // 0x0064fbd8
void Unwind_0064fc10();  // 0x0064fc10
void Unwind_0064fc50();  // 0x0064fc50
void Unwind_0064fc58();  // 0x0064fc58
void Unwind_0064fc60();  // 0x0064fc60
void Unwind_0064fc90();  // 0x0064fc90
void Unwind_0064fc98();  // 0x0064fc98
void Unwind_0064fca7();  // 0x0064fca7
void Unwind_0064fcb2();  // 0x0064fcb2
void Unwind_0064fce0();  // 0x0064fce0
void Unwind_0064fd10();  // 0x0064fd10
void Unwind_0064fd40();  // 0x0064fd40
void Unwind_0064fd48();  // 0x0064fd48
void Unwind_0064fd50();  // 0x0064fd50
void Unwind_0064fd80();  // 0x0064fd80
void Unwind_0064fd88();  // 0x0064fd88
void Unwind_0064fd90();  // 0x0064fd90
void Unwind_0064fde0();  // 0x0064fde0
void Unwind_0064fde8();  // 0x0064fde8
void Unwind_0064fe20();  // 0x0064fe20
void Unwind_0064fe28();  // 0x0064fe28
void Unwind_0064fe30();  // 0x0064fe30
void Unwind_0064fe38();  // 0x0064fe38
void Unwind_0064fe70();  // 0x0064fe70
void Unwind_0064fe78();  // 0x0064fe78
void Unwind_0064feb0();  // 0x0064feb0
void Unwind_0064feb8();  // 0x0064feb8
void Unwind_0064fec3();  // 0x0064fec3
void Unwind_0064fece();  // 0x0064fece
void Unwind_0064fed9();  // 0x0064fed9
void Unwind_0064fee1();  // 0x0064fee1
void Unwind_0064feec();  // 0x0064feec
void Unwind_0064ff02();  // 0x0064ff02
void Unwind_0064ff0d();  // 0x0064ff0d
void Unwind_0064ff18();  // 0x0064ff18
void Unwind_0064ff23();  // 0x0064ff23
void Unwind_0064ff2e();  // 0x0064ff2e
void Unwind_0064ff44();  // 0x0064ff44
void Unwind_0064ff4f();  // 0x0064ff4f
void Unwind_0064ff5a();  // 0x0064ff5a
void Unwind_0064ff70();  // 0x0064ff70
void Unwind_0064ff7b();  // 0x0064ff7b
void Unwind_0064ff86();  // 0x0064ff86
void Unwind_0064ff9c();  // 0x0064ff9c
void Unwind_0064ffa7();  // 0x0064ffa7
void Unwind_0064ffbd();  // 0x0064ffbd
void Unwind_0064ffd3();  // 0x0064ffd3
void Unwind_0064ffe9();  // 0x0064ffe9
void Unwind_0064fff4();  // 0x0064fff4
void Unwind_0064ffff();  // 0x0064ffff
void Unwind_00650015();  // 0x00650015
void Unwind_00650020();  // 0x00650020
void Unwind_00650036();  // 0x00650036
void Unwind_00650041();  // 0x00650041
void Unwind_0065004c();  // 0x0065004c
void Unwind_00650062();  // 0x00650062
void Unwind_0065006d();  // 0x0065006d
void Unwind_00650078();  // 0x00650078
void Unwind_00650080();  // 0x00650080
void Unwind_00650096();  // 0x00650096
void Unwind_006500a1();  // 0x006500a1
void Unwind_006500b7();  // 0x006500b7
void Unwind_006500c2();  // 0x006500c2
void Unwind_006500d8();  // 0x006500d8
void Unwind_006500e3();  // 0x006500e3
void Unwind_006500ee();  // 0x006500ee
void Unwind_006500f6();  // 0x006500f6
void Unwind_0065010c();  // 0x0065010c
void Unwind_00650117();  // 0x00650117
void Unwind_0065012d();  // 0x0065012d
void Unwind_00650138();  // 0x00650138
void Unwind_0065014e();  // 0x0065014e
void Unwind_00650159();  // 0x00650159
void Unwind_0065016f();  // 0x0065016f
void Unwind_0065017a();  // 0x0065017a
void Unwind_00650190();  // 0x00650190
void Unwind_0065019b();  // 0x0065019b
void Unwind_006501a6();  // 0x006501a6
void Unwind_006501b1();  // 0x006501b1
void Unwind_006501c7();  // 0x006501c7
void Unwind_006501dd();  // 0x006501dd
void Unwind_00650230();  // 0x00650230
void Unwind_0065023b();  // 0x0065023b
void Unwind_00650246();  // 0x00650246
void Unwind_0065025c();  // 0x0065025c
void Unwind_00650267();  // 0x00650267
void Unwind_00650272();  // 0x00650272
void Unwind_0065027d();  // 0x0065027d
void Unwind_00650293();  // 0x00650293
void Unwind_0065029e();  // 0x0065029e
void Unwind_006502a9();  // 0x006502a9
void Unwind_006502bf();  // 0x006502bf
void Unwind_006502ca();  // 0x006502ca
void Unwind_006502d5();  // 0x006502d5
void Unwind_006502eb();  // 0x006502eb
void Unwind_006502f3();  // 0x006502f3
void Unwind_006502fe();  // 0x006502fe
void Unwind_00650314();  // 0x00650314
void Unwind_0065031c();  // 0x0065031c
void Unwind_00650327();  // 0x00650327
void Unwind_00650332();  // 0x00650332
void Unwind_0065033d();  // 0x0065033d
void Unwind_00650353();  // 0x00650353
void Unwind_00650369();  // 0x00650369
void Unwind_00650374();  // 0x00650374
void Unwind_00650393();  // 0x00650393
void Unwind_0065039b();  // 0x0065039b
void Unwind_006503e0();  // 0x006503e0
void Unwind_006503e8();  // 0x006503e8
void Unwind_00650420();  // 0x00650420
void Unwind_00650450();  // 0x00650450
void Unwind_00650458();  // 0x00650458
void Unwind_00650460();  // 0x00650460
void Unwind_00650490();  // 0x00650490
void Unwind_006504d0();  // 0x006504d0
void Unwind_006504d8();  // 0x006504d8
void Unwind_006504e0();  // 0x006504e0
void Unwind_006504e8();  // 0x006504e8
void Unwind_006504fb();  // 0x006504fb
void Unwind_00650540();  // 0x00650540
void Unwind_0065054a();  // 0x0065054a
void Unwind_00650580();  // 0x00650580
void Unwind_0065058a();  // 0x0065058a
void Unwind_006505c0();  // 0x006505c0
void Unwind_006505c8();  // 0x006505c8
void Unwind_00650600();  // 0x00650600
void Unwind_00650608();  // 0x00650608
void Unwind_00650610();  // 0x00650610
void Unwind_00650650();  // 0x00650650
void Unwind_00650658();  // 0x00650658
void Unwind_00650690();  // 0x00650690
void Unwind_0065069b();  // 0x0065069b
void Unwind_006506a6();  // 0x006506a6
void Unwind_006506b1();  // 0x006506b1
void Unwind_006506bc();  // 0x006506bc
void Unwind_006506c7();  // 0x006506c7
void Unwind_006506d2();  // 0x006506d2
void Unwind_006506dd();  // 0x006506dd
void Unwind_00650720();  // 0x00650720
void Unwind_0065073f();  // 0x0065073f
void Unwind_0065075e();  // 0x0065075e
void Unwind_00650769();  // 0x00650769
void Unwind_00650771();  // 0x00650771
void Unwind_006507b0();  // 0x006507b0
void Unwind_006507b8();  // 0x006507b8
void Unwind_006507d1();  // 0x006507d1
void Unwind_006507d9();  // 0x006507d9
void Unwind_00650810();  // 0x00650810
void Unwind_00650850();  // 0x00650850
void Unwind_00650890();  // 0x00650890
void Unwind_006508d0();  // 0x006508d0
void Unwind_006508db();  // 0x006508db
void Unwind_006508e6();  // 0x006508e6
void Unwind_006508f1();  // 0x006508f1
void Unwind_006508fc();  // 0x006508fc
void Unwind_00650907();  // 0x00650907
void Unwind_00650912();  // 0x00650912
void Unwind_0065091d();  // 0x0065091d
void Unwind_00650960();  // 0x00650960
void Unwind_006509a0();  // 0x006509a0
void Unwind_006509a8();  // 0x006509a8
void Unwind_006509b0();  // 0x006509b0
void Unwind_006509bf();  // 0x006509bf
void Unwind_006509c7();  // 0x006509c7
void Unwind_00650a10();  // 0x00650a10
void Unwind_00650a18();  // 0x00650a18
void Unwind_00650a20();  // 0x00650a20
void Unwind_00650a28();  // 0x00650a28
void Unwind_00650a30();  // 0x00650a30
void Unwind_00650a38();  // 0x00650a38
void Unwind_00650a43();  // 0x00650a43
void Unwind_00650a4b();  // 0x00650a4b
void Unwind_00650a90();  // 0x00650a90
void Unwind_00650a9b();  // 0x00650a9b
void Unwind_00650ad0();  // 0x00650ad0
void Unwind_00650b00();  // 0x00650b00
void Unwind_00650b08();  // 0x00650b08
void Unwind_00650b40();  // 0x00650b40
void Unwind_00650b4b();  // 0x00650b4b
void Unwind_00650b80();  // 0x00650b80
void Unwind_00650bb0();  // 0x00650bb0
void Unwind_00650be0();  // 0x00650be0
void Unwind_00650c10();  // 0x00650c10
void Unwind_00650c18();  // 0x00650c18
void Unwind_00650c50();  // 0x00650c50
void Unwind_00650c58();  // 0x00650c58
void Unwind_00650c90();  // 0x00650c90
void Unwind_00650cd0();  // 0x00650cd0
void Unwind_00650cd8();  // 0x00650cd8
void Unwind_00650ce3();  // 0x00650ce3
void Unwind_00650cee();  // 0x00650cee
void Unwind_00650cf9();  // 0x00650cf9
void Unwind_00650d04();  // 0x00650d04
void Unwind_00650d16();  // 0x00650d16
void Unwind_00650d21();  // 0x00650d21
void Unwind_00650d29();  // 0x00650d29
void Unwind_00650d60();  // 0x00650d60
void Unwind_00650d6f();  // 0x00650d6f
void Unwind_00650d7a();  // 0x00650d7a
void Unwind_00650d89();  // 0x00650d89
void Unwind_00650d91();  // 0x00650d91
void Unwind_00650d99();  // 0x00650d99
void Unwind_00650dd0();  // 0x00650dd0
void Unwind_00650ddb();  // 0x00650ddb
void Unwind_00650e20();  // 0x00650e20
void Unwind_00650e50();  // 0x00650e50
void Unwind_00650e90();  // 0x00650e90
void Unwind_00650e98();  // 0x00650e98
void Unwind_00650ea0();  // 0x00650ea0
void Unwind_00650ed0();  // 0x00650ed0
void Unwind_00650f10();  // 0x00650f10
void Unwind_00650f18();  // 0x00650f18
void Unwind_00650f2b();  // 0x00650f2b
void Unwind_00650f35();  // 0x00650f35
void Unwind_00650f3d();  // 0x00650f3d
void Unwind_00650f80();  // 0x00650f80
void Unwind_00650f88();  // 0x00650f88
void Unwind_00650f93();  // 0x00650f93
void Unwind_00650f9e();  // 0x00650f9e
void Unwind_00650fb0();  // 0x00650fb0
void Unwind_00650fbe();  // 0x00650fbe
void Unwind_00650fcc();  // 0x00650fcc
void Unwind_00650fd7();  // 0x00650fd7
void Unwind_00650fe2();  // 0x00650fe2
void Unwind_00650fed();  // 0x00650fed
void Unwind_00650ff8();  // 0x00650ff8
void Unwind_00651003();  // 0x00651003
void Unwind_0065100e();  // 0x0065100e
void Unwind_00651050();  // 0x00651050
void Unwind_00651058();  // 0x00651058
void Unwind_0065107a();  // 0x0065107a
void Unwind_00651085();  // 0x00651085
void Unwind_0065108d();  // 0x0065108d
void Unwind_00651098();  // 0x00651098
void Unwind_006510a0();  // 0x006510a0
void Unwind_006510a8();  // 0x006510a8
void Unwind_006510b3();  // 0x006510b3
void Unwind_006510bb();  // 0x006510bb
void Unwind_006510c3();  // 0x006510c3
void Unwind_006510ce();  // 0x006510ce
void Unwind_006510d9();  // 0x006510d9
void Unwind_00651130();  // 0x00651130
void Unwind_00651138();  // 0x00651138
void Unwind_00651170();  // 0x00651170
void Unwind_00651178();  // 0x00651178
void Unwind_006511c0();  // 0x006511c0
void Unwind_006511c8();  // 0x006511c8
void Unwind_00651230();  // 0x00651230
void Unwind_00651238();  // 0x00651238


// --- Auto-added globals (undeclared references) ---
extern uint32_t DAT_0067d280;
extern uint32_t DAT_00682204;
extern uint32_t DAT_00702964;
extern uint32_t DAT_0074990c;

} // namespace Giants
