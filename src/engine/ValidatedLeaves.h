// GiantsRE — proxy-validated leaf functions, ported into the recomp.
//
// Each function here was reverse-engineered, then PROVEN equivalent to the
// original GiantsMain.exe body via the gg_dx9r proxy's self-test harness
// (deterministic input sweep, bit-exact / @1ULP comparison against the original
// at its fixed in-process address). The recomp is the product binary — it must
// CONTAIN these proven-equivalent bodies, not just the proxy's copies. This file
// consolidates them with their FUN_ address + validation provenance.
//
// Only PURE leaves are ported here (computation on arguments, no fixed-address
// original-exe globals). Address-referencing validated funcs (e.g. trig lookups
// via 0x006ac808) are NOT portable to the recomp's separate data layer and stay
// in proxy/Callbacks.cpp.
#pragma once
#include <cstdint>

namespace Giants {

// FUN_00635890 — integer modulo 5. Trivial, exact. (proxy: RE_Mod5)
uint32_t Modulo5(uint32_t x);

// FUN_00635850 — FLICK callee: int f(int p, float a) =
//   (int)( *(int*)(p+0x18) * a * *(int*)(p+0x1c) + *(int*)(p+0x10) )
// Validated via synthetic struct (proxy: RE_FlickFieldMath).
int FlickFieldMath(int p, float a);

// FUN_00634e80 — FLICK callee: int f(int p) = (*(short*)(p+4)==1) ? p : 0
// (proxy: RE_FlickFlagCheck)
int FlickFlagCheck(int p);

// FUN_006355f0 — float f(int p, int a) = (a - field+0x10) / (field+0x1c * field+0x18)
// (proxy: RE_FieldDiv)
float FieldDiv(int p, int a);

// FUN_0048aca0 — indexed float read: *(float*)(desc[1]*idx + desc[0]).
// desc[0]=base addr, desc[1]=stride bytes. (proxy: RE_ArrayIndexFloat)
float ArrayIndexFloat(const int32_t* desc, int32_t idx);

// FUN_006408c0 — accessor: return *(int*)(p + 0x1c). (proxy: RE_AccField1c)
int AccessorField1c(int p);

// FUN_00640c60 — accessor: return (unsigned)*(unsigned short*)(p+2) + p. (proxy: RE_AccU2PlusP)
int AccessorU2PlusP(int p);

// FUN_00640c70 — accessor: return *(unsigned short*)(p+2) + 4 + p. (proxy: RE_AccU2PlusP4)
int AccessorU2PlusP4(int p);

// FUN_00640bf0 — accessor: return *(int*)(*(int*)(p+4) + 0x1c). (proxy: RE_AccDeref1c)
int AccessorDeref1c(int p);

} // namespace Giants
