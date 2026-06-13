#pragma once
// GiantsRE Proxy — RE'd callback implementations + deterministic self-tests
//
// Each RE'd callback has:
//   - a faithful C++ port of the original body (RE_* / *_Predict),
//   - validation wiring: either an in-game shadow hook (dual-mode) or a
//     deterministic self-test (for pure callbacks the proxy can drive itself).
//
// Exe globals are read at their fixed image-base addresses (GiantsMain.exe is
// a non-ASLR PE loaded at 0x00400000), so the in-process proxy can dereference
// them directly. Every address is documented from the Ghidra decompilation.

#include <cstdint>

namespace Callbacks {

// ═══════════════════════════════════════════════════════════════
// RE'd implementations
// ═══════════════════════════════════════════════════════════════

// SinCosLookup — FUN_006387e0 (pure, bit-exact port).
//   void FUN_006387e0(float angle, undefined4* sinOut, undefined4* cosOut)
//     idx = (int)(angle * scale + offset) & 0x3fff   // 16384-entry tables
//     *sinOut = sinTable[idx];  *cosOut = cosTable[idx];
// Outputs are copied as RAW 32-bit values (the float bits), matching the
// original which stores undefined4 — never go through float arithmetic on the
// output path so there is zero chance of bit drift.
void RE_SinCosLookup(float angle, uint32_t* sinOut, uint32_t* cosOut);

// BufferDeallocator — FUN_005e99a0. Prediction of post-state (NO side effect):
//   if (desc->data != null && (desc->flags & 1)) { data=null; flags &= ~1; }
// Used by the in-game shadow hook to predict what the original will do, so we
// can compare WITHOUT double-freeing.
void BufferDealloc_Predict(const int* desc, void** expData, uint32_t* expFlags);

// VectorDistanceSq — FUN_00638d40 (pure). Squared 3D distance between two vec3.
//   float f(float* a, float* b){ dx=b0-a0; dy=b1-a1; dz=b2-a2; return dx*dx+dy*dy+dz*dz; }
// 192 callers, ~2.8M calls/cinematic. Returns squared distance (no sqrt).
float RE_VectorDistanceSq(const float* a, const float* b);

// ── Self-test sweep batch (pure leaves, validated by direct-address call) ──
// These read only const tables/globals → validated without game coverage by
// calling the TRUE original at its (non-ASLR) entry address directly.
float    RE_SinLookupA(float angle);   // FUN_006387b0 — sin table, scale _DAT_006543cc
float    RE_CosLookupA(float angle);   // FUN_00638780 — cos table (Ghidra base 0x006ac800, suspect)
uint32_t RE_Mod5(uint32_t x);          // FUN_00635890 — x % 5
float    RE_FloatClamp(float x);       // FUN_006389a0 — float diff/clamp via const globals
float    RE_TrigLookupC(float angle);  // FUN_00638740 — table lookup, scale _DAT_006543d0 (base suspect)
uint64_t RE_AllMul(uint64_t a, uint64_t b); // FUN_00645670 — 64-bit multiply (CRT helper)
float    RE_ArrayIndexFloat(const int32_t* desc, int32_t idx); // FUN_0048aca0 — *(float*)(desc[1]*idx + desc[0])
int      RE_IsEven(const uint32_t* p); // FUN_0043e430 — (*p & 1) == 0

// ═══════════════════════════════════════════════════════════════
// Detour-original registry
//
// Engine functions hooked via Detour::Hook are no longer callable at their
// native address (the entry is patched to our observer). Self-tests that need
// the TRUE original call it through the trampoline instead. Install code
// registers each successful trampoline here; self-tests look it up by address.
// ═══════════════════════════════════════════════════════════════
void  RegisterDetourOriginal(uint32_t engineAddr, void* trampoline);
void* GetDetourOriginal(uint32_t engineAddr);

// ═══════════════════════════════════════════════════════════════
// In-game validation hooks (installed into the UpCalls table)
// ═══════════════════════════════════════════════════════════════
void __cdecl Hook_BufferDeallocator(int* desc);

// Slot → dedicated validation hook. nullptr means "use the generic OBS_HOOK
// forwarder" (proxy_main handles those). proxy_main consults this array.
// Populated by Init() — call Init() BEFORE installing hooks.
extern void* g_validationHooks[22];

// Wire up g_validationHooks and mark RE'd slots (DualValidator::MarkHasImpl).
// MUST be called before the hook-installation loop in UpCallsLoad.
void Init();

// ═══════════════════════════════════════════════════════════════
// Auto-generated scalar-leaf batch (proxy/SweepAuto.cpp).
// Pattern-matched pure cdecl leaves (x % K, x / K, …) validated in bulk by a
// generic direct-address uint sweep. Regenerate / extend via /tmp/make_sweepauto.py.
// ═══════════════════════════════════════════════════════════════
namespace SweepAuto { uint32_t Run(); }

// ═══════════════════════════════════════════════════════════════
// Deterministic self-tests (proxy-driven — independent of game coverage)
// ═══════════════════════════════════════════════════════════════
// Must be called AFTER UpCallsLoad has captured the original pointers.
// For each pure callback, drives both the RE'd impl and the ORIGINAL with a
// fixed vector and logs any divergence. Returns the number of mismatches found.
uint32_t RunSelfTests();

} // namespace Callbacks
