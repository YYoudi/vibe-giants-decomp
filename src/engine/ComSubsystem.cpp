// GiantsRE — COM subsystem port (FUN_0042fc00 InitCOMSubsystem + foundation).
//
// Functional reconstruction of the original's COM object creation/registration.
// The original allocates a 0x58-byte COM object, sets vtable PTR_FUN_0065ce08,
// refcounts, and registers it via the engine-context's vtable[1](GUID, obj).
// Here we recreate that behavior using the recomp's ComRegistry (the exact
// internal layout isn't byte-recoverable, but register/query behavior is).
//
// Live-dump confirmed (commit 25b036a): PTR_FUN_0065ce08 vtable =
//   [0] = FUN_00431af0 (init)   [1] = FUN_00431ae0 (release)
// both matching the Ghidra decompilation.
#include "ComRegistry.h"
#include <cstdlib>
#include <cstring>
#include <cstdint>

namespace Giants {

// ─── COM object layout (from FUN_0042fc00 decompilation) ─────────────
//   [0] = vtable ptr
//   [1] = strong refcount
//   [2] = weak refcount
//   [3..] = data (0x48 bytes zeroed)
struct ComObject {
    void** vtable;
    int    strongRef;
    int    weakRef;
    int    pad;
    uint8_t data[0x48];
};

// vtable methods (functional). Init is a no-op setup; Release decrements
// refcount and frees when both reach zero (matches FUN_00431ae0 semantics:
// "if (p) (*vtable[2])(1)" — the release path).
extern "C" void __fastcall ComVtbl_Init(ComObject* /*self*/) {
    // FUN_00431af0 — sets secondary vtables + calls sub-inits. Stubbed: the
    // object is already zeroed + primary vtable set by InitCOMSubsystem.
}
extern "C" void __fastcall ComVtbl_Release(ComObject* self, int /*arg*/) {
    // FUN_00431ae0 — smart-pointer release. Decrement strong refcount.
    if (self) {
        // The original calls vtable[2]; here we directly decrement.
        if (--self->strongRef <= 0) {
            // would free — but objects are registered for process lifetime
        }
    }
}

// The recomp's vtable for the 0065ce08 COM class (replaces original .rdata addr).
static void* g_comVtbl_0065ce08[8] = {
    (void*)&ComVtbl_Init,     // [0] init
    (void*)&ComVtbl_Release,  // [1] release
    nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
};

// GUID for the COM subsystem object (DAT_0065cdf8 in the original). We use a
// stable address as the GUID key (ComRegistry keys on pointer identity).
static const char g_comGuid_0065cdf8 = 0;  // &this serves as the GUID

// Local operator_new (the original's allocator; here plain malloc).
static void* operator_new(size_t n) { return malloc(n); }

// FUN_0042fc00 — InitCOMSubsystem. Creates + registers the core COM object.
void InitCOMSubsystem_Real() {
    ComObject* obj = static_cast<ComObject*>(operator_new(0x58));  // 0x58 bytes
    if (!obj) return;
    obj->vtable = g_comVtbl_0065ce08;
    obj->strongRef = 1;
    obj->weakRef = 1;
    obj->pad = 0;
    memset(obj->data, 0, sizeof(obj->data));
    // FUN_004358b0() — sub-init (stubbed)
    // Register via the COM registry (original: engine-context vtable[1](GUID, obj))
    ComRegister(&g_comGuid_0065cdf8, obj);
    // FUN_0042e110() — config load (stubbed)
    // FUN_0042fd68() — refcount helper (stubbed)
}

// GUID for the string-lookup subsystem (DAT_0065d154 in the original).
static const char g_comGuid_0065d154 = 0;

// FUN_00443e20 — InitStringSubsystem. Creates + registers the string-lookup
// subsystem (the live dump showed the engine context's class = "TextLookupService",
// which is likely this subsystem). Size 0x14 (smart-pointer-like COM object).
void InitStringSubsystem_Real() {
    ComObject* obj = static_cast<ComObject*>(operator_new(0x14 + sizeof(ComObject::data)));
    if (!obj) return;
    obj->vtable = g_comVtbl_0065ce08;  // reuse base COM vtable (functional)
    obj->strongRef = 1;
    obj->weakRef = 1;
    obj->pad = 0;
    memset(obj->data, 0, sizeof(obj->data));
    ComRegister(&g_comGuid_0065d154, obj);
}

// FUN_00461a60 — the central COM factory (33 callers). Original:
//   (**(code**)(*(int*)(param_1)+8))(out, &DAT_0065f184)
// i.e. QueryInterface: query the registry by the type-ID GUID, return the obj.
// Functional version: ComQuery by GUID. param_1 (the source object) is ignored
// since our registry is global (the original dispatches through param_1's vtable
// to reach the same global registry).
extern "C" void* ComFactory_Query(const void* typeId) {
    return ComQuery(typeId);
}

} // namespace Giants
