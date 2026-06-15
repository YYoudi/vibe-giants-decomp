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
#include <cstdio>

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

// FUN_00437e00 — vector reserve (ensure capacity). Functional: realloc-based.
// Original manages a vector struct (ptr, size, capacity). Here simplified.
static void* VectorReserve(int capacity, void* existing) {
    if (existing) return realloc(existing, capacity * 4);  // assume 4-byte elements
    return malloc(capacity * 4);
}

// FUN_004409f0 — typed sub-object allocator (switch-based). Functional: malloc+zero.
static void* TypedAllocator(int type) {
    void* obj = operator_new(type == 0 ? 0x20 : 0x40);  // size by type
    if (obj) memset(obj, 0, type == 0 ? 0x20 : 0x40);
    return obj;
}

// FUN_0042fc00 — InitCOMSubsystem. Creates + registers the core COM object.
void InitCOMSubsystem_Real() {
    ComObject* obj = static_cast<ComObject*>(operator_new(0x58));  // 0x58 bytes
    if (!obj) return;
    obj->vtable = g_comVtbl_0065ce08;
    obj->strongRef = 1;
    obj->weakRef = 1;
    obj->pad = 0;
    memset(obj->data, 0, sizeof(obj->data));

    // FUN_004358b0 — COM subsystem sub-init: sets secondary vtables + creates
    // an internal linked list (self-referencing node) + reserves vectors.
    // Original sets obj fields at specific offsets within the 0x48 data area.
    uint32_t* fields = reinterpret_cast<uint32_t*>(obj->data);
    fields[0] = 0;  // PTR_FUN_0065d0c0 (secondary vtable — original .rdata addr)
    fields[1] = 0;  // DAT_0065d0b4 (secondary vtable 2)
    fields[2] = 0x3f800000;  // 1.0f (scale factor)
    // Create the self-referencing linked list node (operator_new(0x18))
    uint32_t* listNode = static_cast<uint32_t*>(operator_new(0x18));
    if (listNode) {
        listNode[0] = (uint32_t)listNode;  // prev = self
        listNode[1] = (uint32_t)listNode;  // next = self
        fields[3] = (uint32_t)listNode;    // head node
    }
    fields[8] = 7;   // initial capacity hint
    fields[9] = 8;   // initial capacity hint
    // FUN_00437e00(0x10, listNode) — vector reserve (stubbed)
    // FUN_004409f0(0) x2 — allocator init (stubbed)

    ComRegister(&g_comGuid_0065cdf8, obj);

    // FUN_0042e110 — config file loader (parses Default configuration).
    // Functional stub: defaults used (no config file parsed yet). The original
    // loads a config via FUN_00431980 + parses key-value sections. Porting the
    // full parser is a transitive chain (9 callees). For now, defaults.
    extern FILE* g_traceLog;
    if (g_traceLog) { fprintf(g_traceLog, "[INIT] Config loaded (defaults)\n"); fflush(g_traceLog); }

    // FUN_0042fd68 — refcount helper (0 callees, trivial decrement).
    // Already handled by the ComObject strongRef/weakRef fields.
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

// Game-context GUID (DAT_0065f184 equivalent — what GetGameContext queries).
static const char g_comGuid_gameContext = 0;

// Register the game-context object (created during PreInitCheck in the original).
// Wired into the init path so GetGameContext's query succeeds.
void RegisterGameContext() {
    ComObject* obj = static_cast<ComObject*>(operator_new(sizeof(ComObject)));
    if (!obj) return;
    obj->vtable = g_comVtbl_0065ce08;
    obj->strongRef = 1;
    obj->weakRef = 1;
    obj->pad = 0;
    memset(obj->data, 0, sizeof(obj->data));
    ComRegister(&g_comGuid_gameContext, obj);
}

// Query the game-context object (used by GetGameContext / FUN_00461a60).
void* ComQueryGameContext() {
    return ComQuery(&g_comGuid_gameContext);
}

// FUN_0046fd40 — factory init subsystem (dispatches via DAT_00660194 GUID).
// Same COM smart-pointer pattern as GetGameContext. Register functionally.
static const char g_comGuid_00660194 = 0;
void RegisterFactoryInit() {
    ComObject* obj = static_cast<ComObject*>(operator_new(sizeof(ComObject)));
    if (!obj) return;
    obj->vtable = g_comVtbl_0065ce08;
    obj->strongRef = 1; obj->weakRef = 1; obj->pad = 0;
    memset(obj->data, 0, sizeof(obj->data));
    ComRegister(&g_comGuid_00660194, obj);
}

// FUN_005c4400 — register frame/update callback objects. Original creates 4
// small callback objects (operator_new(4) → set vtable) + adds to a global array
// (DAT_0073e784). Functional: create + count them (the callbacks fire per-frame).
static void* g_callbackObjs[16];
static int   g_callbackCount = 0;
void RegisterCallbacks() {
    extern FILE* g_traceLog;
    // Create 4 callback objects (vtables PTR_FUN_006655ec/d4/bc/...).
    for (int i = 0; i < 4; i++) {
        if (g_callbackCount < 16) {
            g_callbackObjs[g_callbackCount++] = malloc(4);  // callback object (vtable ptr)
        }
    }
    if (g_traceLog) { fprintf(g_traceLog, "[INIT] RegisterCallbacks: %d callback objects\n", g_callbackCount); fflush(g_traceLog); }
}

// Level-load method (the game-context's vtable[6]/0x18 in the original, called
// by LoadDefaultPlayer with "intro_island"). Functional: looks up the level file
// in the VFS to verify the level-load path reaches the file system. The full
// scene-build (parse .gck, construct scene graph) is the next phase.
// VFSFileLookup is defined in VirtualFileSystem.cpp (namespace Giants).
uint32_t VFSFileLookup(char* filename);  // FUN_00623f00
int LevelLoad(void* /*self*/, const char* levelName) {
    extern FILE* g_traceLog;
    extern unsigned long VFSExtractFile(const char*, unsigned char*, unsigned int);
    // The level terrain is stored as "<name>.gti" in the VFS (GZP archives).
    char path[128];
    snprintf(path, sizeof(path), "%s.gti", levelName);
    uint32_t handle = VFSFileLookup(path);
    if (handle == 0) {
        snprintf(path, sizeof(path), "%s", levelName);
        handle = VFSFileLookup(path);
    }
    if (handle != 0) {
        // Extract the terrain to verify the GZP read + LZ77 decompression work.
        static unsigned char terrainBuf[1 << 20];  // 1MB scratch
        uint32_t sz = VFSExtractFile(path, terrainBuf, sizeof(terrainBuf));
        if (g_traceLog) {
            fprintf(g_traceLog, "[LOAD] LevelLoad(\"%s\"): extracted %s -> %u bytes\n",
                    levelName, path, sz);
            // Parse the GTI header (96 bytes) for terrain dimensions.
            // GtiHeader: [0]sig [8]XOff [12]YOff [16]MinH [20]MaxH [24]Width [28]Height [32]Stretch
            if (sz >= 96) {
                uint32_t sig = *(uint32_t*)&terrainBuf[0];
                float minX = *(float*)&terrainBuf[8], minY = *(float*)&terrainBuf[12];
                float minH = *(float*)&terrainBuf[16], maxH = *(float*)&terrainBuf[20];
                int32_t w = *(int32_t*)&terrainBuf[24], h = *(int32_t*)&terrainBuf[28];
                float stretch = *(float*)&terrainBuf[32];
                fprintf(g_traceLog, "[LOAD]   GTI sig=0x%08X W=%d H=%d minH=%.1f maxH=%.1f stretch=%.3f XY=(%.0f,%.0f)\n",
                        sig, w, h, minH, maxH, stretch, minX, minY);
                // Decode the GTI RLE heightmap (spec from GiantsEdit GtiFormat.cs):
                //   byte b: b>=0x80 → skip (256-b) cells; else read (b+1) literal cells,
                //   each 8 bytes = float height + byte tri + RGB.
                int cellCount = w * h;
                static float heights[256 * 256];  // max grid
                static uint8_t lightmap[256 * 256 * 3];  // RGB per cell (real terrain colors)
                if (cellCount <= 256 * 256) {
                    for (int i = 0; i < cellCount; i++) heights[i] = minH;  // default
                    int pos = 96, cellIdx = 0;
                    while (cellIdx < cellCount && pos < (int)sz) {
                        uint8_t b = terrainBuf[pos++];
                        if (b >= 0x80) {
                            cellIdx += (256 - b);
                        } else {
                            int lit = b + 1;
                            for (int i = 0; i < lit && cellIdx < cellCount && pos + 8 <= (int)sz; i++) {
                                heights[cellIdx] = *(float*)&terrainBuf[pos];
                                // Cell layout: float height(4) + byte triangle(1) + R(1) + G(1) + B(1)
                                lightmap[cellIdx * 3 + 0] = terrainBuf[pos + 5];
                                lightmap[cellIdx * 3 + 1] = terrainBuf[pos + 6];
                                lightmap[cellIdx * 3 + 2] = terrainBuf[pos + 7];
                                pos += 8;
                                cellIdx++;
                            }
                        }
                    }
                    // Write decoded heights + lightmap for the stub renderer.
                    FILE* hf = fopen("terrain_heights.bin", "wb");
                    if (hf) {
                        fwrite(&w, 4, 1, hf); fwrite(&h, 4, 1, hf);
                        fwrite(&stretch, 4, 1, hf);
                        fwrite(&minX, 4, 1, hf); fwrite(&minY, 4, 1, hf);
                        fwrite(&minH, 4, 1, hf); fwrite(&maxH, 4, 1, hf);
                        fwrite(heights, 4, cellCount, hf);
                        fwrite(lightmap, 1, cellCount * 3, hf);  // RGB lightmap
                        fclose(hf);
                        fprintf(g_traceLog, "[LOAD]   decoded+wrote terrain_heights.bin (%d cells + lightmap)\n", cellCount);
                    }
                }
            }
            fflush(g_traceLog);
        }
    } else if (g_traceLog) {
        fprintf(g_traceLog, "[LOAD] LevelLoad(\"%s\"): terrain not found in VFS\n", levelName);
        fflush(g_traceLog);
    }
    return handle != 0 ? 1 : 0;
}

} // namespace Giants
