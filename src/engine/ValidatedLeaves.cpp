// GiantsRE — proxy-validated leaf functions (see ValidatedLeaves.h for provenance).
// Bodies are faithful ports of the proxy's RE_* implementations, themselves
// proven equivalent to the original GiantsMain.exe bodies via self-test.
#include "ValidatedLeaves.h"
#include <cstring>

namespace Giants {

// FUN_00635890 — integer modulo 5. PROVEN exact (proxy RE_Mod5).
uint32_t Modulo5(uint32_t x) { return x % 5u; }

// FUN_00635850 — FLICK field math. PROVEN equivalent (proxy RE_FlickFieldMath,
// synthetic-struct self-test). Reads 3 object fields; deterministic given (fields, a).
int FlickFieldMath(int p, float a) {
    return (int)((float)*(int*)(p + 0x18) * a * (float)*(int*)(p + 0x1c)
                 + (float)*(int*)(p + 0x10));
}

// FUN_00634e80 — FLICK flag check. PROVEN equivalent (proxy RE_FlickFlagCheck).
int FlickFlagCheck(int p) {
    return (*(short*)(p + 4) == 1) ? p : 0;
}

// FUN_006355f0 — field division. PROVEN equivalent (proxy RE_FieldDiv).
float FieldDiv(int p, int a) {
    return (float)(a - *(int*)(p + 0x10))
         / (float)(*(int*)(p + 0x1c) * *(int*)(p + 0x18));
}

// FUN_0048aca0 — indexed float read. PROVEN equivalent (proxy RE_ArrayIndexFloat).
float ArrayIndexFloat(const int32_t* desc, int32_t idx) {
    uintptr_t addr = static_cast<uintptr_t>(desc[1]) * static_cast<uintptr_t>(idx)
                   + static_cast<uintptr_t>(desc[0]);
    float f; std::memcpy(&f, reinterpret_cast<const void*>(addr), 4);
    return f;
}

// FUN_006408c0 — deep-mined accessor. PROVEN equivalent (proxy RE_AccField1c).
int AccessorField1c(int p)        { return *(int*)(p + 0x1c); }

// FUN_00640c60 — accessor. PROVEN equivalent (proxy RE_AccU2PlusP).
int AccessorU2PlusP(int p)        { return (unsigned int)*(unsigned short*)(p + 2) + p; }

// FUN_00640c70 — accessor. PROVEN equivalent (proxy RE_AccU2PlusP4).
int AccessorU2PlusP4(int p)       { return *(unsigned short*)(p + 2) + 4 + p; }

// FUN_00640bf0 — accessor. PROVEN equivalent (proxy RE_AccDeref1c).
int AccessorDeref1c(int p)        { return *(int*)(*(int*)(p + 4) + 0x1c); }

} // namespace Giants
