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

// rdata string tag (setupgam.c:148 — free file/line assert tag). extern "C" gives
// it external linkage (C++ `const` alone = internal linkage → link fail).
extern const char s_C__Giants_Source_main_setupgam_c_00564ebc[] = "C:\\Giants\\Source\\main\\setupgam.c";

// ── FUN_ callees (no-op link stubs; return 0 where a value is expected) ──
// FUN_004913c0 callees:
int  FUN_0052f960(void) { return 0; }                 // gate: DAT_005dd5d8 == 4
void FUN_0052a050(void) {}
int  FUN_004b77c0(void) { return 0; }                 // level-table max-index
void* FUN_004b7640(int) { return 0; }                 // level-record lookup
int  FUN_0053c970(const char*, const char*) { return 0; }  // strcmp==0
void FUN_0045a520(uint32_t) {}                        // DAT_0059ca4c = v
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
void* FUN_0049d280(int) { return 0; }                 // spawn-record lookup
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
