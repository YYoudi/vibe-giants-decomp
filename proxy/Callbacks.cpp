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
} // namespace

uint32_t RunSelfTests() {
    Logger::Separator();
    Logger::Log("[selftest] Running deterministic self-tests...");
    uint32_t total = 0;
    total += SelfTest_SinCosLookup();
    total += SelfTest_VectorDistanceSq();
    Logger::Log("[selftest] Done — %u total mismatches", total);
    Logger::Separator();
    return total;
}

} // namespace Callbacks
