// Giants Engine - Engine-Context (COM Service Registry) — REAL protocol port.
//
// The engine-context passed to GDVSysCreate (6th param) is a COM service
// registry ("TextLookupService" class name, but it's a generic GUID→object
// IoC container). The engine Register()s services under 16-byte COM IIDs; the
// renderer Query()s them. Captured from the ORIGINAL via proxy+Frida (2026-06-16):
// the vtable has 5 methods (Release/Register/Query/Unregister/Clear) and the
// registry matches GUIDs BY VALUE (not pointer).
//
// Registered service IIDs (captured): the engine registers under these, the
// renderer queries the same. The recomp must register under matching values.
//
//   9c8f4c9c-c1d4-4947-a073-d710548d3154  (TextLookupService / string table)
//   24669e59-4c69-b641-b354-62eea1132041
//   5067549c-f23c-794f-bc03-1ec7d4d2f7e0
//   30dfd9b2-ed25-1243-9dc2-343dae156182
//   cde2c03c-fd6c-2a44-aad8-2897038f101d
//   d3eb0d77-5d16-4043-829d-5262f473fbe3
//
// This backs the recomp's g_engineContext (EngineInit.cpp) vtable[0..4], so the
// real gg_dx9r.dll stops crashing on null vtable[3]/[4] and can query services.

#include <cstdint>
#include <cstring>
#include <map>
#include <vector>

namespace Giants {

// 16-byte COM GUID (value-compared).
struct Guid {
    uint8_t b[16];
    bool operator<(const Guid& o) const { return memcmp(b, o.b, 16) < 0; }
    bool operator==(const Guid& o) const { return memcmp(b, o.b, 16) == 0; }
};

// The registry: GUID → service object pointer. Value-keyed (matches original).
static std::map<Guid, void*> g_serviceRegistry;

static Guid MakeGuid(const uint8_t bytes[16]) {
    Guid g; memcpy(g.b, bytes, 16); return g;
}

// --- The 6 captured service IIDs (engine registers these; renderer queries). ---
static const uint8_t IID_TextLookup[16] = {0x9c,0x8f,0x4c,0x9c,0xc1,0xd4,0x49,0x47,0xa0,0x73,0xd7,0x10,0x54,0x8d,0x31,0x54};
static const uint8_t IID_Svc2[16] = {0x24,0x66,0x9e,0x59,0x4c,0x69,0xb6,0x41,0xb3,0x54,0x62,0xee,0xa1,0x13,0x20,0x41};
static const uint8_t IID_Svc3[16] = {0x50,0x67,0x54,0x9c,0xf2,0x3c,0x79,0x4f,0xbc,0x03,0x1e,0xc7,0xd4,0xd2,0xf7,0xe0};
static const uint8_t IID_Svc4[16] = {0x30,0xdf,0xd9,0xb2,0xed,0x25,0x12,0x43,0x9d,0xc2,0x34,0x3d,0xae,0x15,0x61,0x82};
static const uint8_t IID_Svc5[16] = {0xcd,0xe2,0xc0,0x3c,0xfd,0x6c,0x2a,0x44,0xaa,0xd8,0x28,0x97,0x03,0x8f,0x10,0x1d};
static const uint8_t IID_Svc6[16] = {0xd3,0xeb,0x0d,0x77,0x5d,0x16,0x40,0x43,0x82,0x9d,0x52,0x62,0xf4,0x73,0xfb,0xe3};

// ─── The 5 vtable methods (thiscall: ECX = this = the engine-context object) ──
// Signatures inferred from FUN_00635F80 (Register), FUN_00636180 (Query), etc.

// vtable[1] Register(this, guidStruct*, serviceObj, refcnt*) — FUN_00635F80.
// guidStruct points to a struct whose [0..3] = the 16-byte GUID; serviceObj is
// the object to register. We map GUID(value)→serviceObj.
extern "C" void* __attribute__((thiscall)) EngineCtx_Register(uint32_t* /*self*/, uint32_t* guidStruct, uint32_t serviceObj, uint32_t* /*refcnt*/) {
    if (!guidStruct) return nullptr;
    Guid g; memcpy(g.b, guidStruct, 16);  // GUID is the first 16 bytes of the struct
    g_serviceRegistry[g] = (void*)(uintptr_t)serviceObj;
    return (void*)(uintptr_t)serviceObj;
}

// vtable[2] Query(this, outPtr, guidPtr) — FUN_00636180. guidPtr is a POINTER to
// the 16-byte GUID (FUN_00635d70 derefs it). Looks up, writes {serviceObj,refcnt}
// into outPtr[0..1]. Returns outPtr.
extern "C" void* __attribute__((thiscall)) EngineCtx_Query(uint32_t* /*self*/, uint32_t* outPtr, uint32_t guidPtr) {
    Guid g = {};
    if (guidPtr) memcpy(g.b, (void*)(uintptr_t)guidPtr, 16);
    auto it = g_serviceRegistry.find(g);
    if (outPtr) {
        if (it != g_serviceRegistry.end()) {
            outPtr[0] = (uint32_t)(uintptr_t)it->second;  // service object
            outPtr[1] = 0;                                  // refcount placeholder
        } else {
            outPtr[0] = 0; outPtr[1] = 0;  // not found
        }
    }
    return outPtr;
}

// vtable[0] Release(this, flags) — FUN_0044DDB0. No-op for now (objects are
// process-lifetime).
extern "C" uint32_t __attribute__((thiscall)) EngineCtx_Release(uint32_t* self, uint8_t /*flags*/) {
    return (uint32_t)(uintptr_t)self;
}

// vtable[3] Unregister(this, guidPtr) — FUN_006362D0. guidPtr = pointer to GUID.
extern "C" void __attribute__((thiscall)) EngineCtx_Unregister(uint32_t* /*self*/, uint32_t guidPtr) {
    Guid g = {};
    if (guidPtr) memcpy(g.b, (void*)(uintptr_t)guidPtr, 16);
    g_serviceRegistry.erase(g);
}

// vtable[4] Clear(this) — FUN_00636210. Clears all registered services.
extern "C" void __attribute__((thiscall)) EngineCtx_Clear(uint32_t* /*self*/) {
    g_serviceRegistry.clear();
}

// ─── Engine-context vtable (5 methods) — referenced by EngineInit.cpp ──────
extern "C" void* g_engineContextVtbl[5] = {
    (void*)&EngineCtx_Release,
    (void*)&EngineCtx_Register,
    (void*)&EngineCtx_Query,
    (void*)&EngineCtx_Unregister,
    (void*)&EngineCtx_Clear,
};

// Register a service object under one of the captured IIDs (called during init
// so the renderer's queries resolve). Used by the recomp's subsystem inits.
extern "C" void EngineContext_RegisterService(const uint8_t iidBytes[16], void* serviceObj) {
    g_serviceRegistry[MakeGuid(iidBytes)] = serviceObj;
}

// ─── Placeholder service objects (minimal no-op COM vtable) ───────────────
// Registered under the 6 captured IIDs so the renderer's GDVSysCreate-time
// queries resolve to a non-null object (vs null → crash). The renderer then
// calls the object's vtable methods; these no-ops let it proceed past the
// query. REAL service objects replace these as each subsystem is ported.
static uint32_t __attribute__((thiscall)) Svc_RetSelf(uint32_t* self) { return (uint32_t)(uintptr_t)self; }
static void      __attribute__((thiscall)) Svc_NoOp(uint32_t*) {}
static void* g_svcVtbl[8] = {
    (void*)&Svc_RetSelf, (void*)&Svc_RetSelf, (void*)&Svc_NoOp, (void*)&Svc_NoOp,
    (void*)&Svc_NoOp, (void*)&Svc_NoOp, (void*)&Svc_NoOp, (void*)&Svc_NoOp,
};
static uint32_t g_svcObjects[6][4] = {};  // [0]=vtable ptr set at init
static void* g_svcObjPtrs[6] = {};

// Called from EngineInit after the engine-context is created — registers a
// placeholder service under each captured IID so renderer queries resolve.
extern "C" void EngineContext_InitServices() {
    const uint8_t* iids[6] = { IID_TextLookup, IID_Svc2, IID_Svc3, IID_Svc4, IID_Svc5, IID_Svc6 };
    for (int i = 0; i < 6; i++) {
        g_svcObjects[i][0] = (uint32_t)(uintptr_t)g_svcVtbl;
        g_svcObjPtrs[i] = (void*)&g_svcObjects[i];
        g_serviceRegistry[MakeGuid(iids[i])] = g_svcObjPtrs[i];
    }
}

} // namespace Giants
