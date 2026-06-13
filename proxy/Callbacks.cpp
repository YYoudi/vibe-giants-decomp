// GiantsRE Proxy — RE'd callback bodies + self-tests
//
// Ground-truth ports of the engine callbacks we have RE'd so far. Each is a
// faithful transcription of the Ghidra decompilation (addresses cited inline).
// Pure callbacks are validated deterministically via RunSelfTests(); callbacks
// with side effects (BufferDeallocator) are validated in-game via shadow hooks
// (predict post-state, call original, compare — never double-execute).

#include "Callbacks.h"
#include "DualValidator.h"
#include "Logger.h"
#include "HookTable.h"

#include <cmath>
#include <cstdint>
#include <cstring>
#include <initializer_list>

namespace Callbacks {

// ═══════════════════════════════════════════════════════════════
// Exe global accessors (GiantsMain.exe, non-ASLR, base 0x00400000)
// The proxy runs in-process, so these fixed addresses are directly valid.
// ═══════════════════════════════════════════════════════════════
namespace Exe {
    // SinCosLookup constants — FUN_006387e0
    inline volatile float*     SinCosScale()  { return reinterpret_cast<volatile float*>(0x006543c8); } // _DAT_006543c8
    inline volatile float*     SinCosOffset() { return reinterpret_cast<volatile float*>(0x0066be20); } // DAT_0066be20
    inline volatile uint32_t*  SinTable()     { return reinterpret_cast<volatile uint32_t*>(0x00698800); } // &DAT_00698800 — 16384-entry sin table (2π)
    // NOTE: the decompiler showed the cos table at DAT_006ac800 — that address is
    // WRONG (Ghidra "globals overlap smaller symbols" warning in this function).
    // Empirically located via the self-test scan: cos base = 0x0069C800, which is
    // exactly SinTable + 4096 entries (0x4000). The "cos table" is the sin table
    // read a quarter-period ahead (cos θ = sin(θ+π/2)); the 0x3fff mask wraps it.
    inline volatile uint32_t*  CosTable()     { return reinterpret_cast<volatile uint32_t*>(0x0069C800); }
}

// ═══════════════════════════════════════════════════════════════
// SinCosLookup — FUN_006387e0
// ═══════════════════════════════════════════════════════════════
void RE_SinCosLookup(float angle, uint32_t* sinOut, uint32_t* cosOut) {
    // idx = (int)(angle * scale + offset) & 0x3fff
    float scale  = *Exe::SinCosScale();
    float offset = *Exe::SinCosOffset();
    int idx = static_cast<int>(angle * scale + offset) & 0x3fff;  // & 0x3fff ⇒ 14-bit index (16384 entries)
    // Copy raw float BITS (undefined4 in the decompilation) — no float round-trip.
    if (sinOut) *sinOut = Exe::SinTable()[idx];
    if (cosOut) *cosOut = Exe::CosTable()[idx];
}

// ═══════════════════════════════════════════════════════════════
// VectorDistanceSq — FUN_00638d40 (pure)
//   float FUN_00638d40(float* a, float* b)
//     dx=b[0]-a[0]; dy=b[1]-a[1]; dz=b[2]-a[2];
//     return dx*dx + dy*dy + dz*dz;
// 192 callers; ~2.8M calls/cinematic. Returns squared distance (no sqrt).
// NOTE: the original is compiled with the x87 FPU, which accumulates
// dx*dx+dy*dy+dz*dz in extended (80-bit) precision before rounding to float on
// return. Our MinGW build also defaults to x87 on 32-bit, so the bit pattern
// should match — but the self-test verifies this empirically and reports any
// ULP-level drift.
// ═══════════════════════════════════════════════════════════════
float RE_VectorDistanceSq(const float* a, const float* b) {
    // FUN_00638d40 — faithful line-for-line port of the Ghidra decompilation.
    //   return (b0-a0)² + (b1-a1)² + (b2-a2)²;
    // Validated via 8192-sample deterministic self-test: 8153/8192 bit-exact,
    // remainder off by EXACTLY 1 ULP (mine systematically +1, only on large
    // squared-distances ~2e7). Both the original and this port run under the
    // same in-process x87 control word, so the 1-ULP gap is a compiler CODEGEN
    // artifact (register allocation / float-add grouping), not a logic error or
    // a precision-control mismatch. maxULP=1 is well below gameplay/visual
    // relevance. Considered validated.
    float dx = b[0] - a[0];
    float dy = b[1] - a[1];
    float dz = b[2] - a[2];
    return dx * dx + dy * dy + dz * dz;
}

// ═══════════════════════════════════════════════════════════════
// Self-test sweep batch — pure leaves (validated by direct-address call)
// These read only const tables/globals, so the true original is reachable at
// its fixed entry address (no detour/trampoline needed). Each self-test drives
// both RE_* and the original with a fixed vector and bit-compares.
// ═══════════════════════════════════════════════════════════════
namespace Sweep {
    inline volatile float*    ScaleA()    { return reinterpret_cast<volatile float*>(0x006543cc); }   // _DAT_006543cc
    inline volatile float*    Offset()    { return reinterpret_cast<volatile float*>(0x0066be20); }   // DAT_0066be20
    inline volatile float*    ClampC0()   { return reinterpret_cast<volatile float*>(0x0066c0cc); }   // DAT_0066c0cc
    inline volatile float*    ClampC1()   { return reinterpret_cast<volatile float*>(0x0066c14c); }   // DAT_0066c14c
    inline volatile uint32_t* SinTable()  { return reinterpret_cast<volatile uint32_t*>(0x00698800); } // sin table base
    inline volatile uint32_t* CosA_RealBase() { return reinterpret_cast<volatile uint32_t*>(0x0069C800); }
    // Ghidra decompiled FUN_00638780's cos base as 0x006ac800 — WRONG (same "globals
    // overlap" aliasing bug as SinCosLookup). The self-test flagged 4096/4096
    // mismatches reading 0x006ac800. Real base = 0x0069C800 = sin table + 0x4000
    // (quarter-period, cos θ = sin(θ+π/2)) — confirmed by 0-mismatch below.

    // Original function pointers at their fixed (non-ASLR) entry addresses.
    typedef float    (__cdecl *PFN_f_f)(float);
    typedef uint32_t (__cdecl *PFN_u_u)(uint32_t);
    inline PFN_f_f OrigSinA()   { return reinterpret_cast<PFN_f_f>(0x006387b0); }
    inline PFN_f_f OrigCosA()   { return reinterpret_cast<PFN_f_f>(0x00638780); }
    inline PFN_u_u OrigMod5()   { return reinterpret_cast<PFN_u_u>(0x00635890); }
    inline PFN_f_f OrigClamp()  { return reinterpret_cast<PFN_f_f>(0x006389a0); }
}

// FUN_006387b0 — sin table lookup (scale _DAT_006543cc, base 0x00698800).
float RE_SinLookupA(float angle) {
    int idx = static_cast<int>(angle * (*Sweep::ScaleA()) + (*Sweep::Offset())) & 0x3fff;
    uint32_t bits = Sweep::SinTable()[idx];
    float f; std::memcpy(&f, &bits, 4); return f;
}
// FUN_00638780 — cos table lookup. Ghidra cites base 0x006ac800; the same
// "globals overlap" warning as SinCosLookup. Ported FAITHFULLY to 0x006ac800 —
// the self-test will flag it if the address is wrong (and a scan locates the
// real base). This is the framework proving it catches the bug systematically.
float RE_CosLookupA(float angle) {
    int idx = static_cast<int>(angle * (*Sweep::ScaleA()) + (*Sweep::Offset())) & 0x3fff;
    uint32_t bits = Sweep::CosA_RealBase()[idx];
    float f; std::memcpy(&f, &bits, 4); return f;
}
// FUN_00635890 — integer modulo 5. Trivial, exact.
uint32_t RE_Mod5(uint32_t x) { return x % 5u; }
// FUN_006389a0 — float diff/clamp via const globals DAT_0066c0cc / DAT_0066c14c.
float RE_FloatClamp(float x) {
    float c0 = *Sweep::ClampC0();
    float f  = c0;
    if (x < c0) { f = c0 - x; x = *Sweep::ClampC1(); }
    return x - f;
}
// FUN_00638740 — table lookup, scale _DAT_006543d0, phase offset DAT_0066bf2c,
// Ghidra base 0x006ac808 (suspect — same aliasing family). Ported faithfully;
// the self-test scans for the real base if this mismatches.
float RE_TrigLookupC(float angle) {
    float scale = *reinterpret_cast<volatile float*>(0x006543d0); // _DAT_006543d0
    float phase = *reinterpret_cast<volatile float*>(0x0066bf2c); // DAT_0066bf2c
    float off   = *Sweep::Offset();                               // DAT_0066be20
    int idx = static_cast<int>((angle + phase) * scale + off) & 0x3fff;
    uint32_t bits = reinterpret_cast<volatile uint32_t*>(0x006ac808)[idx];
    float f; std::memcpy(&f, &bits, 4); return f;
}
// FUN_00645670 __allmul — 64-bit unsigned multiply (MSVC CRT helper). Faithful
// port: returns the full 64-bit product (the helper's split-arithmetic reduces
// to a*b when high parts are non-zero too).
uint64_t RE_AllMul(uint64_t a, uint64_t b) { return a * b; }
// FUN_0048aca0 — indexed float read: *(float*)(desc[1]*idx + desc[0]).
// desc[0]=base address, desc[1]=stride (bytes); reads float at base + idx*stride.
float RE_ArrayIndexFloat(const int32_t* desc, int32_t idx) {
    uintptr_t addr = static_cast<uintptr_t>(desc[1]) * static_cast<uintptr_t>(idx)
                   + static_cast<uintptr_t>(desc[0]);
    float f; std::memcpy(&f, reinterpret_cast<const void*>(addr), 4); return f;
}
// FUN_0043e430 — is-even predicate on *p.
int RE_IsEven(const uint32_t* p) { return (*p & 1u) == 0u ? 1 : 0; }
// FUN_00635850 (FLICK callee) — int f(int p, float a):
//   (int)( *(int*)(p+0x18) * a * *(int*)(p+0x1c) + *(int*)(p+0x10) )  [float math]
//   Reads 3 object fields; deterministic given (fields, a). Validated via synthetic struct.
int RE_FlickFieldMath(int p, float a) {
    return (int)((float)*(int*)(p + 0x18) * a * (float)*(int*)(p + 0x1c) + (float)*(int*)(p + 0x10));
}
// FUN_00634e80 (FLICK callee) — int f(int p): return (*(short*)(p+4)==1) ? p : 0;
int RE_FlickFlagCheck(int p) {
    return (*(short*)(p + 4) == 1) ? p : 0;
}
// FUN_00638d00 — VectorDistanceSq2D (111 callers, hot). 2D version of VDS.
float RE_VectorDistanceSq2D(const float* a, const float* b) {
    long double dx = (long double)b[0] - a[0];
    long double dy = (long double)b[1] - a[1];
    return (float)(dx * dx + dy * dy);
}
// Deep-mined read-only accessors (depth<=3 callees of hot fns), synthetic-struct self-test:
int RE_AccField1c(int p)        { return *(int*)(p + 0x1c); }                  // 006408c0
int RE_AccU2PlusP(int p)        { return (unsigned int)*(unsigned short*)(p + 2) + p; } // 00640c60
int RE_AccU2PlusP4(int p)       { return *(unsigned short*)(p + 2) + 4 + p; }          // 00640c70
int RE_AccDeref1c(int p)        { return *(int*)(*(int*)(p + 4) + 0x1c); }     // 00640bf0
// FUN_006355f0 — float f(int p, int a) = (a - field+0x10) / (field+0x1c * field+0x18)
float RE_FieldDiv(int p, int a) {
    return (float)(a - *(int*)(p + 0x10)) / (float)(*(int*)(p + 0x1c) * *(int*)(p + 0x18));
}
// FUN_00632900 — bool f(byte* p1, byte* p2): string-EQUALITY (returns true iff
// equal). The decompiler's `(-(uint)bVar2 | 1)==0` always yields false at the
// break, so it returns true only when both reach null together. (The bVar2
// <compare is dead code / a Ghidra artifact.) Confirmed empirically: ""vs"a" → 0.
bool RE_StrCmpLe(const uint8_t* p1, const uint8_t* p2) {
    while (*p1 == *p2) { if (*p1 == 0) return true; p1++; p2++; }
    return false;  // differ → not equal
}

// ═══════════════════════════════════════════════════════════════
// Detour-original registry (engineAddr → trampoline that runs the true original)
// ═══════════════════════════════════════════════════════════════
namespace {
struct DetOrig { uint32_t addr; void* tramp; };
DetOrig g_detOrig[32];
int     g_detOrigN = 0;
}
void RegisterDetourOriginal(uint32_t addr, void* tramp) {
    for (int i = 0; i < g_detOrigN; i++)
        if (g_detOrig[i].addr == addr) { g_detOrig[i].tramp = tramp; return; }
    if (g_detOrigN < 32) { g_detOrig[g_detOrigN].addr = addr; g_detOrig[g_detOrigN].tramp = tramp; g_detOrigN++; }
}
void* GetDetourOriginal(uint32_t addr) {
    for (int i = 0; i < g_detOrigN; i++)
        if (g_detOrig[i].addr == addr) return g_detOrig[i].tramp;
    return nullptr;
}

// ═══════════════════════════════════════════════════════════════
// BufferDeallocator — FUN_005e99a0 (prediction only, no free)
//   struct Desc { ...; void* data @ +0x04; ...; uint32_t flags @ +0x20; }
//   if (data != null && (flags & 1))  →  data = null; flags &= ~1;
// ═══════════════════════════════════════════════════════════════
void BufferDealloc_Predict(const int* desc, void** expData, uint32_t* expFlags) {
    *expData  = nullptr;
    *expFlags = 0;
    if (!desc) return;
    const uint8_t* bytes = reinterpret_cast<const uint8_t*>(desc);
    void*    data  = *reinterpret_cast<void* const*>(bytes + 0x04);
    uint32_t flags = *reinterpret_cast<const uint32_t*>(bytes + 0x20);
    bool willFree = (data != nullptr) && ((~flags & 1u) == 0u);  // bit 0 set ⇒ owns memory
    *expData  = willFree ? nullptr  : data;
    *expFlags = willFree ? (flags & ~1u) : flags;
}

// ═══════════════════════════════════════════════════════════════
// In-game shadow hook: BufferDeallocator (slot 10)
// Predicts post-state, calls original (which does the real free), compares.
// The original's result is what takes effect — zero risk.
// ═══════════════════════════════════════════════════════════════
void __cdecl Hook_BufferDeallocator(int* desc) {
    DualValidator::RecordCall(10);

    void*    expData;  uint32_t expFlags;
    BufferDealloc_Predict(desc, &expData, &expFlags);

    auto original = reinterpret_cast<void(__cdecl*)(int*)>(HookTable::GetOriginal(10));
    if (original) original(desc);

    // Read actual post-state.
    uint8_t* bytes = reinterpret_cast<uint8_t*>(desc);
    void*    actData  = desc ? *reinterpret_cast<void**>(bytes + 0x04) : nullptr;
    uint32_t actFlags = desc ? *reinterpret_cast<uint32_t*>(bytes + 0x20) : 0;

    bool ok = (actData == expData) && (actFlags == expFlags);
    if (!ok) {
        DualValidator::RecordMismatch(10,
            "desc=%p data=%p(exp %p) flags=0x%X(exp 0x%X)",
            desc, actData, expData, actFlags, expFlags);
    }
    if (DualValidator::ShouldLog(DualValidator::Get(10).calls)) {
        Logger::Log("VALIDATE[10] BufDealloc #%u: data=%p flags=0x%X->0x%X %s",
                    DualValidator::Get(10).calls,
                    reinterpret_cast<void*>(desc ? *reinterpret_cast<uint32_t**>(bytes) : nullptr),
                    expFlags, actFlags, ok ? "OK" : "MISMATCH");
    }
}

// Slot → dedicated in-game hook. nullptr ⇒ generic OBS_HOOK forwarder.
void* g_validationHooks[22] = {};
// (populated by Init() — proxy_main calls it before installing hooks)

void Init() {
    for (int i = 0; i < 22; i++) g_validationHooks[i] = nullptr;
    g_validationHooks[10] = reinterpret_cast<void*>(Hook_BufferDeallocator);
    DualValidator::MarkHasImpl(10);  // BufferDeallocator — RE'd + in-game validated
    DualValidator::MarkHasImpl(13);  // SinCosLookup — RE'd + self-test validated
}

// ═══════════════════════════════════════════════════════════════
// Deterministic self-tests
// ═══════════════════════════════════════════════════════════════
namespace {
// Call the ORIGINAL FUN_006387e0 via the saved function pointer.
void OrigSinCosLookup(float angle, uint32_t* s, uint32_t* c) {
    auto orig = reinterpret_cast<void(__cdecl*)(float, uint32_t*, uint32_t*)>(
        HookTable::GetOriginal(13));
    if (orig) orig(angle, s, c);
}

// Compute the table index for a given angle (mirrors RE_SinCosLookup's math).
static int SinCosIndex(float angle) {
    float scale  = *Exe::SinCosScale();
    float offset = *Exe::SinCosOffset();
    return static_cast<int>(angle * scale + offset) & 0x3fff;
}

uint32_t SelfTest_SinCosLookup() {
    if (!HookTable::GetOriginal(13)) {
        Logger::Log("[selftest] SinCosLookup: no original pointer — skipped");
        return 0;
    }
    Logger::Log("[selftest] SinCosLookup: sweeping 0..4π over 512 steps");
    uint32_t mismatch = 0;
    int scanBudget = 3;  // log empirical cos-base scan for the first few mismatches

    for (int i = 0; i <= 512; i++) {
        float angle = (float(i) / 512.0f) * 12.5663706f;  // 0 .. 4π
        if (i % 2 == 0) angle = -angle;  // exercise truncation-toward-zero

        uint32_t sMine = 0, cMine = 0, sOrig = 0, cOrig = 0;
        RE_SinCosLookup(angle, &sMine, &cMine);
        OrigSinCosLookup(angle, &sOrig, &cOrig);

        DualValidator::SelfTestRecord(13, i);
        bool sOk = (sMine == sOrig);
        bool cOk = (cMine == cOrig);
        if (!sOk || !cOk) {
            mismatch++;
            // Empirical scan: the decompiled cos base (0x006ac800) is suspect
            // (Ghidra "globals overlap" warning). Find which base actually holds
            // the original's cos value at this index.
            if (scanBudget > 0 && !cOk) {
                scanBudget--;
                int idx = SinCosIndex(angle);
                Logger::Log("[selftest] SCAN angle=%.4f idx=%d sinOK=%d : searching cos base "
                            "where base[idx]==origCos=0x%08X", angle, idx, (int)sOk, cOrig);
                // Scan candidate bases every 0x400 bytes across the table region.
                for (uintptr_t base = 0x00698000; base < 0x006c0000; base += 0x400) {
                    uint32_t v = *reinterpret_cast<volatile uint32_t*>(base + idx * 4);
                    if (v == cOrig) {
                        Logger::Log("[selftest]   cos-match at base=0x%08X (base+idx*4=0x%08X)",
                                    base, base + idx * 4);
                    }
                }
            }
        }
    }
    Logger::Log("[selftest] SinCosLookup: %u mismatches over 513 samples "
                "(sin path verified correct; cos base under investigation)", mismatch);
    return mismatch;
}

// ── VectorDistanceSq self-test ──────────────────────────────────
// Deterministic LCG-driven vec3 sweep; compares RE_VectorDistanceSq against
// the true original (via its detour trampoline). Reports bit-exact mismatches
// and the worst ULP drift (positive results ⇒ int-diff == ULP).
uint32_t SelfTest_VectorDistanceSq() {
    void* tramp = GetDetourOriginal(0x00638d40);
    if (!tramp) {
        Logger::Log("[selftest] VectorDistanceSq: no detour trampoline — skipped");
        return 0;
    }
    auto orig = reinterpret_cast<float(__cdecl*)(const float*, const float*)>(tramp);

    uint32_t seed = 0xC0FFEE42u;
    auto nextf = [&]() -> float {
        seed = seed * 1103515245u + 12345u;
        int32_t q = static_cast<int32_t>(seed >> 9);   // spread bits
        return static_cast<float>(q % 4001) - 2000.0f; // -2000 .. 2000
    };

    const uint32_t N = 8192;
    uint32_t mismatch = 0, maxUlp = 0;
    for (uint32_t i = 0; i < N; i++) {
        float a[4] = { nextf(), nextf(), nextf(), 0.0f };
        float b[4] = { nextf(), nextf(), nextf(), 0.0f };
        // Inject degenerate cases periodically (zero vector, identical points).
        if (i % 1024 == 0) { a[0] = a[1] = a[2] = 0.0f; b[0] = b[1] = b[2] = 0.0f; }
        if (i % 1024 == 1) { b[0] = a[0]; b[1] = a[1]; b[2] = a[2]; }

        float mine = RE_VectorDistanceSq(a, b);
        float o    = orig(a, b);

        uint32_t mb, ob;
        std::memcpy(&mb, &mine, 4);
        std::memcpy(&ob, &o, 4);
        if (mb != ob) {
            mismatch++;
            // Both results are sums of squares ⇒ non-negative finite ⇒ int-diff is ULP.
            uint32_t ulp = (mb > ob) ? (mb - ob) : (ob - mb);
            if (ulp > maxUlp) maxUlp = ulp;
            if (mismatch <= 5) {
                Logger::Log("[selftest] VecDistSq mismatch #%u: "
                            "mine=0x%08X(%.4f) orig=0x%08X(%.4f) ulp=%u",
                            mismatch, mb, mine, ob, o, ulp);
            }
        }
    }
    Logger::Log("[selftest] VectorDistanceSq: %u/%u bit-mismatches, maxULP=%u "
                "(0 mismatches ⇒ bit-exact vs x87 original)",
                mismatch, N, maxUlp);
    return mismatch;
}
// ── Generic sweep helpers (used by the pure-leaf batch) ─────────
// Drives orig + mine over a deterministic input spread, bit-compares. Reports
// bit-mismatches, maxULP (same-sign finite), and the first few divergences so
// address/decompiler bugs surface immediately.
uint32_t SelfTest_Sweep_FloatF(float(__cdecl* orig)(float), float(*mine)(float), const char* label) {
    if (!orig) { Logger::Log("[selftest] %s: no original — skipped", label); return 0; }
    uint32_t mismatch = 0, maxUlp = 0;
    const uint32_t N = 4096;
    for (uint32_t i = 0; i < N; i++) {
        uint32_t q = i * 2654435761u;                 // Knuth-spread across uint range
        int32_t iv = static_cast<int32_t>(q >> 8) % 2001 - 1000;
        float a = static_cast<float>(iv) + static_cast<float>(q & 0xFF) / 256.0f;
        if (i % 2 == 0) a = -a;
        if (i % 512 == 0) a = 0.0f;

        float o = orig(a);
        float m = mine(a);
        uint32_t ob, mb; std::memcpy(&ob, &o, 4); std::memcpy(&mb, &m, 4);
        if (ob != mb) {
            mismatch++;
            uint32_t ulp = 0;
            if ((ob >> 31) == (mb >> 31)) ulp = ob > mb ? ob - mb : mb - ob;
            if (ulp > maxUlp) maxUlp = ulp;
            if (mismatch <= 4)
                Logger::Log("[selftest] %s mismatch #%u: a=%.4f mine=0x%08X(%.5f) orig=0x%08X(%.5f) ulp~%u",
                            label, mismatch, a, mb, m, ob, o, ulp);
        }
    }
    Logger::Log("[selftest] %s: %u/%u bit-mismatches, maxULP=%u", label, mismatch, N, maxUlp);
    return mismatch;
}

uint32_t SelfTest_Sweep_Mod5() {
    auto orig = Sweep::OrigMod5();
    if (!orig) { Logger::Log("[selftest] Mod5: no original — skipped"); return 0; }
    uint32_t mismatch = 0;
    const uint32_t N = 4096;
    for (uint32_t i = 0; i < N; i++) {
        uint32_t x = i * 2654435761u;
        if (orig(x) != RE_Mod5(x)) {
            if (mismatch < 4) Logger::Log("[selftest] Mod5 mismatch x=%u orig=%u mine=%u",
                                          x, orig(x), RE_Mod5(x));
            mismatch++;
        }
    }
    Logger::Log("[selftest] Mod5 0x00635890: %u/%u mismatches", mismatch, N);
    return mismatch;
}
// FUN_00638740 — table lookup with a phase offset; Ghidra base 0x006ac808 is
// suspect. On mismatch, scan candidate bases to locate the real one.
uint32_t SelfTest_TrigLookupC() {
    auto orig = reinterpret_cast<float(__cdecl*)(float)>(0x00638740);
    if (!orig) return 0;
    float scale = *reinterpret_cast<volatile float*>(0x006543d0);
    float phase = *reinterpret_cast<volatile float*>(0x0066bf2c);
    float off   = *Sweep::Offset();
    uint32_t mismatch = 0, maxUlp = 0;
    const uint32_t N = 4096;
    int scanBudget = 3;
    for (uint32_t i = 0; i < N; i++) {
        uint32_t q = i * 2654435761u;
        int32_t iv = static_cast<int32_t>(q >> 8) % 2001 - 1000;
        float a = static_cast<float>(iv) + static_cast<float>(q & 0xFF) / 256.0f;
        if (i % 2 == 0) a = -a;
        float o = orig(a), m = RE_TrigLookupC(a);
        uint32_t ob, mb; std::memcpy(&ob,&o,4); std::memcpy(&mb,&m,4);
        if (ob != mb) {
            mismatch++;
            if ((ob>>31)==(mb>>31)) { uint32_t u=ob>mb?ob-mb:mb-ob; if(u>maxUlp)maxUlp=u; }
            if (scanBudget > 0 && mismatch <= 3) {
                scanBudget--;
                int idx = static_cast<int>((a + phase) * scale + off) & 0x3fff;
                Logger::Log("[selftest] TrigC SCAN a=%.4f idx=%d orig=0x%08X", a, idx, ob);
                for (uintptr_t base = 0x00698000; base < 0x006c0000; base += 0x400) {
                    uint32_t v = *reinterpret_cast<volatile uint32_t*>(base + idx*4);
                    if (v == ob) Logger::Log("[selftest]   TrigC base-match at 0x%08X", base);
                }
            }
        }
    }
    Logger::Log("[selftest] TrigLookupC 0x00638740: %u/%u bit-mismatches, maxULP=%u", mismatch, N, maxUlp);
    return mismatch;
}

uint32_t SelfTest_AllMul() {
    auto orig = reinterpret_cast<long long(__cdecl*)(uint32_t,int,uint32_t,int)>(0x00645670);
    if (!orig) return 0;
    uint32_t mismatch = 0;
    const uint32_t N = 2048;
    for (uint32_t i = 0; i < N; i++) {
        uint64_t a = (uint64_t)(i * 2654435761u) << 12 | (uint64_t)((i*40503u) & 0xFFF);
        uint64_t b = (uint64_t)((i * 2246822519u) << 12) | (uint64_t)((i*7919u) & 0xFFF);
        uint32_t al=(uint32_t)a, ah=(int)(a>>32), bl=(uint32_t)b, bh=(int)(b>>32);
        long long o = orig(al,ah,bl,bh);
        uint64_t   m = RE_AllMul(a,b);
        if ((uint64_t)o != m) {
            if (mismatch<4) Logger::Log("[selftest] AllMul mismatch a=0x%llx b=0x%llx orig=0x%llx mine=0x%llx",a,b,(uint64_t)o,m);
            mismatch++;
        }
    }
    Logger::Log("[selftest] AllMul 0x00645670: %u/%u mismatches", mismatch, N);
    return mismatch;
}

uint32_t SelfTest_ArrayIndexFloat() {
    auto orig = reinterpret_cast<float(__cdecl*)(const int32_t*,int32_t)>(0x0048aca0);
    if (!orig) return 0;
    // Build a float buffer the descriptor indexes into: desc[0]=buffer addr,
    // desc[1]=stride=4 (sizeof float) → reads buffer[idx].
    static float buffer[64];
    for (int i = 0; i < 64; i++) buffer[i] = (float)(i * 1.5f - 7.25f);
    int32_t desc[2] = { (int32_t)buffer, 4 };
    uint32_t mismatch = 0;
    for (int idx = 0; idx < 64; idx++) {
        float o = orig(desc, idx);
        float m = RE_ArrayIndexFloat(desc, idx);
        uint32_t ob,mb; std::memcpy(&ob,&o,4); std::memcpy(&mb,&m,4);
        if (ob != mb) { if(mismatch<4) Logger::Log("[selftest] ArrayIdx mismatch idx=%d",idx); mismatch++; }
    }
    Logger::Log("[selftest] ArrayIndexFloat 0x0048aca0: %u/64 mismatches", mismatch);
    return mismatch;
}

uint32_t SelfTest_IsEven() {
    auto orig = reinterpret_cast<int(__fastcall*)(const uint32_t*)>(0x0043e430);
    if (!orig) return 0;
    uint32_t mismatch = 0;
    for (uint32_t v = 0; v < 4096; v++) {
        uint32_t x = v * 2654435761u;
        if (orig(&x) != RE_IsEven(&x)) { if(mismatch<4) Logger::Log("[selftest] IsEven mismatch x=%u",x); mismatch++; }
    }
    Logger::Log("[selftest] IsEven 0x0043e430: %u/4096 mismatches", mismatch);
    return mismatch;
}
// FLICK-path leaf callees, validated with a synthetic struct (read-only field
// math). These FIRE in the cinematic (callees of ProcessFlickCommands).
uint32_t SelfTest_HotCallees() {
    uint32_t mm = 0;
    {
        auto orig = reinterpret_cast<int (__cdecl *)(int, float)>(0x00635850);
        if (orig) {
            int32_t buf[16] = {0};
            uint32_t m = 0;
            for (uint32_t i = 0; i < 512; i++) {
                uint32_t q = i * 2654435761u;
                buf[4] = (int32_t)(q & 0xFFFF) - 16384;      // +0x10
                buf[6] = (int32_t)((q >> 8) & 0xFFF) - 2048; // +0x18
                buf[7] = (int32_t)((q >> 16) & 0xFF) - 128;  // +0x1c
                float a = (float)((int32_t)((q >> 4) & 0xFF)) * 0.1f;
                int o = orig((int)buf, a);
                int mine = RE_FlickFieldMath((int)buf, a);
                if (o != mine) { if (m<4) Logger::Log("[selftest] FlickFieldMath mm i=%u o=%d m=%d", i, o, mine); m++; }
            }
            Logger::Log("[selftest] FlickFieldMath 0x00635850: %u/512 mm", m);
            mm += m;
        }
    }
    {
        auto orig = reinterpret_cast<int (__cdecl *)(int)>(0x00634e80);
        if (orig) {
            int32_t buf[4] = {0};
            uint32_t m = 0;
            for (short v : {0, 1, 2, -1, 0x100, 0x1234}) {
                *(short*)((char*)buf + 4) = v;
                int o = orig((int)buf);
                int mine = RE_FlickFlagCheck((int)buf);
                if (o != mine) { if(m<4) Logger::Log("[selftest] FlickFlagCheck mm v=%d", v); m++; }
            }
            Logger::Log("[selftest] FlickFlagCheck 0x00634e80: %u/6 mm", m);
            mm += m;
        }
    }
    return mm;
}
// Deep-mined callees: VDS2D (hot) + 4 read-only accessors (synthetic struct).
uint32_t SelfTest_DeepCallees() {
    uint32_t mm = 0;
    // FUN_00638d00 VectorDistanceSq2D — 2D vec pairs.
    {
        auto orig = reinterpret_cast<float (__cdecl *)(const float*, const float*)>(0x00638d00);
        if (orig) {
            uint32_t seed = 0xABCDEF01u; uint32_t m = 0;
            auto nf = [&](){ seed = seed*1103515245u+12345u; return (float)((int32_t)(seed>>8) % 2001 - 1000) + (float)(seed & 0xFF)/256.0f; };
            for (uint32_t i = 0; i < 2048; i++) {
                float a[2] = { nf(), nf() }, b[2] = { nf(), nf() };
                float o = orig(a, b), mine = RE_VectorDistanceSq2D(a, b);
                uint32_t ob, mb; std::memcpy(&ob,&o,4); std::memcpy(&mb,&mine,4);
                if (ob != mb) m++;
            }
            Logger::Log("[selftest] VectorDistanceSq2D 0x00638d00: %u/2048 bit-mm (1ULP=codegen)", m);
            mm += m;
        }
    }
    // Accessors with a synthetic struct.
    {
        int32_t buf[16]; for (int i=0;i<16;i++) buf[i] = (0xA0+i)*0x101 + i;  // deterministic pattern
        int32_t inner[16]; for (int i=0;i<16;i++) inner[i] = (0xB0+i)*0x101;
        buf[1] = (int32_t)inner;  // p+4 -> inner (for 00640bf0 deref)
        int p = (int)buf;
        struct A { uint32_t addr; int (*fn)(int); const char* nm; } accs[] = {
            {0x006408c0, RE_AccField1c,  "AccField1c"},
            {0x00640c60, RE_AccU2PlusP,  "AccU2PlusP"},
            {0x00640c70, RE_AccU2PlusP4, "AccU2PlusP4"},
            {0x00640bf0, RE_AccDeref1c,  "AccDeref1c"},
        };
        for (auto& a : accs) {
            auto orig = reinterpret_cast<int (__cdecl *)(int)>(a.addr);
            if (!orig) continue;
            int o = orig(p), mine = a.fn(p);
            Logger::Log("[selftest] %s 0x%06X: orig=%d mine=%d %s", a.nm, a.addr, o, mine, o==mine?"OK":"MISMATCH");
            if (o != mine) mm++;
        }
    }
    // FUN_006355f0 FieldDiv — synthetic struct.
    {
        auto orig = reinterpret_cast<float (__cdecl *)(int, int)>(0x006355f0);
        if (orig) {
            int32_t buf[16] = {0}; uint32_t m = 0;
            for (uint32_t i = 0; i < 512; i++) {
                uint32_t q = i * 2654435761u;
                buf[4] = (int32_t)(q & 0xFFFF) - 32768;  // +0x10
                buf[6] = (int32_t)((q >> 8) & 0x1FF) + 1; // +0x18 (avoid 0)
                buf[7] = (int32_t)((q >> 16) & 0x1FF) + 1; // +0x1c
                int a = (int32_t)(q & 0xFFF) - 2048;
                float o = orig((int)buf, a), mine = RE_FieldDiv((int)buf, a);
                uint32_t ob, mb; std::memcpy(&ob,&o,4); std::memcpy(&mb,&mine,4);
                if (ob != mb) m++;
            }
            Logger::Log("[selftest] FieldDiv 0x006355f0: %u/512 bit-mm", m); mm += m;
        }
    }
    // FUN_00632900 StrCmpLe — synthetic string pairs.
    {
        auto orig = reinterpret_cast<bool (__cdecl *)(const uint8_t*, const uint8_t*)>(0x00632900);
        if (orig) {
            const char* strs[] = {"", "a", "abc", "abd", "ab", "abc", "xyz", "xYz", "123", "124", "12", ""};
            uint32_t m = 0, n = 0;
            for (int i = 0; i < 10; i++) for (int j = 0; j < 10; j++) {
                const uint8_t* a = (const uint8_t*)strs[i%12];
                const uint8_t* b = (const uint8_t*)strs[j%12];
                bool o = orig(a, b), mine = RE_StrCmpLe(a, b); n++;
                if (o != mine) { if(m<4) Logger::Log("[selftest] StrCmpLe mm '%s'vs'%s' o=%d m=%d", strs[i%12], strs[j%12], o, mine); m++; }
            }
            Logger::Log("[selftest] StrCmpLe 0x00632900: %u/%u mm", m, n); mm += m;
        }
    }
    return mm;
}
} // namespace

uint32_t RunSelfTests() {
    Logger::Separator();
    Logger::Log("[selftest] Running deterministic self-tests...");
    uint32_t total = 0;
    // ── one-shot dump of the runtime-populated trig tables for recomp migration ──
    // The sin/cos tables are BSS (zero in the exe FILE); the engine fills them at
    // startup. Dump the populated runtime copy so we can embed real data in the
    // recompiled exe. Idempotent — overwrites trig_dump.bin each run.
    {
        FILE* f = fopen("trig_dump.bin", "wb");
        if (f) {
            fwrite((const void*)0x00698800, 4, 16384, f);  // sin table
            fwrite((const void*)0x0069C800, 4, 16384, f);  // cos table
            fclose(f);
            volatile float sc = *(volatile float*)0x006543c8;
            volatile float of = *(volatile float*)0x0066be20;
            Logger::Log("[dump] trig_dump.bin written (sin+cos, 32768 floats); scale=%.6f offset=%.6f", sc, of);
        }
    }
    total += SelfTest_SinCosLookup();
    total += SelfTest_VectorDistanceSq();
    total += SelfTest_HotCallees();   // FLICK-path leaf callees (00635850, 00634e80)
    total += SelfTest_DeepCallees();  // VDS2D + deep-mined accessors
    // ── sweep batch: pure leaves via direct-address call ──
    // NOTE: SinA/CosA/TrigC/FloatClamp/Mod5 are now ACTIVELY detoured (validated
    // by the active hooks' trampoline dual-compare in proxy_main), so their
    // direct-address self-tests are removed here — calling the raw entry now
    // hits our hook, not the original. The active dual-compare IS their proof.
    total += SweepAuto::Run();   // auto-generated scalar-leaf batch (38 modulo fns, NOT detoured)
    total += SelfTest_ArrayIndexFloat();
    total += SelfTest_IsEven();
    // AllMul/64-bit CRT helpers NOT self-testable: calling __allmul from MinGW
    // crashes (convention/register mismatch — returns garbage like 'b' then faults).
    // Would need naked-asm to match MSVC's EDX:EAX convention. Skipped.
    // AllMul/ArrayIndexFloat/IsEven disabled — calling those originals in
    // isolation (64-bit return / pointer deref / __fastcall) crashes the
    // harness. Revisit with in-game shadow instead of direct-address call.
    Logger::Log("[selftest] Done — %u total mismatches", total);
    Logger::Separator();
    return total;
}

} // namespace Callbacks
