// Giants Vanilla-Native Recomp — link stubs for scene-chain callees.
// These FUN_ are referenced by VanillaSceneLoad.cpp (FUN_004913c0 / FUN_004f3230
// faithful ports) but not yet ported themselves. They are declared `extern "C"`
// there with inferred prototypes; here we provide no-op definitions so the
// scene-chain TU links. C linkage = the symbol name is unmangled, so any call
// signature links. These are DORMANT (the scene-chain fns are not called in the
// boot yet — staged). As each callee is faithfully ported, delete its stub here.
//
// Each callee's vanilla address is cited. Anti-dérive: these are explicit
// unported-callee stubs (link-only), NOT behavioral implementations.
#include <cstdint>

extern "C" {

// ── .data globals referenced by FUN_004913c0 / FUN_004f3230 (zero-init) ──
uint32_t DAT_00631380 = 0;   // selected level index
uint32_t DAT_005a766c = 0;   // intro/menu-mode flag
uint32_t DAT_0063166c = 0;   // scratch flag (SetupGame)
uint32_t DAT_00630f34 = 0;   // stream/scratch handle
uint32_t DAT_006316ec = 0;   // g_WorldState (world/game-state pointer)
uint32_t DAT_00631504 = 0;   // spawn-callback count
uint32_t DAT_00631508 = 0;   // spawn-callback head
uint32_t DAT_0063150c = 0;   // spawn-callback cursor
uint32_t DAT_005dc25c = 0;   // fn-ptr global (reset cluster 3)
uint32_t DAT_005dc2e8 = 0;   // fn-ptr global
uint32_t DAT_005dc32c = 0;   // fn-ptr global
uint32_t DAT_006310e8 = 0;   // secondary world/stream handle
uint32_t DAT_005dd5d8 = 0;   // game-state phase gate (FUN_0052f960 tests == 4)
uint32_t DAT_0059ca4c = 0;   // level-selector scratch (FUN_0045a520 writes)

// Level table — DEFINED in VanillaSceneLists.cpp (g_LevelTable=DAT_00631388, g_LevelCount=DAT_00631384).
extern uint32_t g_LevelTable;
extern uint32_t g_LevelCount;

// rdata string tag (setupgam.c:148 — free file/line assert tag). extern "C" gives
// it external linkage (C++ `const` alone = internal linkage → link fail).
extern const char s_C__Giants_Source_main_setupgam_c_00564ebc[] = "C:\\Giants\\Source\\main\\setupgam.c";

// ── FUN_ callees (no-op link stubs; return 0 where a value is expected) ──
// FUN_004913c0 callees — faithfully ported (vanilla_decompiled/*.json):
// FUN_00547250 = engine strcmp (called by FUN_0053c970). Ported as real strcmp.
int FUN_00547250(const char* a, const char* b) {
    while (*a && (*a == *b)) { a++; b++; }
    return (int)(unsigned char)*a - (int)(unsigned char)*b;
}
// FUN_0053c970: nonzero(true) when strings equal. (vanilla 0053c970)
int FUN_0053c970(const char* a, const char* b) { return FUN_00547250(a, b) == 0; }
// FUN_0052f960: gate — DAT_005dd5d8 == 4. (vanilla 0052f960)
int FUN_0052f960(void) { return DAT_005dd5d8 == 4; }
// FUN_0045a520: setter — DAT_0059ca4c = v. (vanilla 0045a520)
void FUN_0045a520(uint32_t v) { DAT_0059ca4c = v; }
// FUN_004b7640: level-record lookup by first-dword key. Stride 0x1428 dwords = 0x50A0 bytes.
//   Returns a pointer into g_LevelTable on first-dword match, else NULL. (vanilla 004b7640)
void* FUN_004b7640(int key) {
    int* base = (int*)(uintptr_t)g_LevelTable;
    int n = (int)g_LevelCount;
    for (int i = 0; i < n; i++) {
        int* entry = base + i * 0x1428;
        if (*entry == key) return entry;
    }
    return 0;
}
// FUN_004b77c0: level-table walk. FIXME(unverified): decompile shows void+dead-store
//   (computes a max it discards). The selector FUN_004913c0 uses its return as the
//   scan loop bound, so it must return the entry COUNT (g_LevelCount). Returning
//   g_LevelCount makes the selector functional — confirm dynamically vs original.
int  FUN_004b77c0(void) { return (int)g_LevelCount; }
void FUN_0052a050(void) {}
void FUN_0045a530(void) {}                            // async-load kick
// FUN_004f3230 callees:
void FUN_004aa190(void) {}
void FUN_0040f2e0(void) {}
void FUN_00519ca0(uint32_t) {}
void FUN_0050e4b0(uint32_t) {}                        // texture-pool release
void FUN_0050e360(uint32_t) {}                        // texture-pool release
void FUN_00439b80(void) {}
void FUN_004470d0(void) {}
void FUN_0044a120(void) {}
void FUN_004d20f0(void) {}
void FUN_0044ab40(void) {}
// FUN_0049d280: obj-type lookup by u32 id. Walks DAT_006313b0 linked list; each node
//   [0]=next, [1]=count, [2..]=entries stride 0x119 dwords, key at entry[0]. Returns
//   ptr to the matching entry (node + iVar2*0x119 + 2), else NULL. (vanilla 0049d280)
extern "C" uint32_t DAT_006313b0;
void* FUN_0049d280(int typeId) {
    uint32_t* node = (uint32_t*)(uintptr_t)DAT_006313b0;
    while (node) {
        int count = (int)node[1];
        if (count > 0) {
            for (int i = 0; i < count; i++) {
                uint32_t* entry = node + 2 + i * 0x119;
                if (*entry == (uint32_t)typeId) return entry;
            }
        }
        node = (uint32_t*)(uintptr_t)node[0];
    }
    return 0;
}
void FUN_004af220(uint32_t) {}                        // procanim cleanup
void FUN_0051eb10(void) {}
void FUN_0049cc60(void) {}
void FUN_004b71d0(void) {}
void FUN_0044ac80(void) {}
void FUN_0049a910(void) {}
void FUN_0049b6d0(void) {}
void FUN_005102d0(void) {}
void FUN_0049a570(void) {}
void FUN_0049f1f0(uint32_t) {}
void FUN_0053c5c0(uint32_t, const char*, int) {}      // free + file-tag
void FUN_004759c0(void) {}
void FUN_004bac50(void) {}
void FUN_0040aff0(void) {}
void FUN_0050dc20(void) {}
void FUN_00491540(void) {}
void FUN_00431800(void) {}
void FUN_00473190(void) {}
void FUN_00403430(void) {}
void FUN_004a5600(void) {}
void FUN_00445340(void) {}

} // extern "C"
