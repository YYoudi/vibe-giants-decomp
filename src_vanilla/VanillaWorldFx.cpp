// Giants Vanilla-Native Recomp — FUN_0044ab90 port (apply world FX preset).
// 1:1 port of vanilla_decompiled/0044ab90.json (size 224). Opens "<fx>_bin",
// validates version==1, reads the FX entry count + the FX table into DAT_0059c96c.
#include "VanillaWorldFx.h"
#include <cstdio>
#include <cstdint>

extern "C" {
// File I/O (real, VanillaFileIO) + alloc/log (real)
uint32_t FUN_00539e30(const char* path);                       // open
void FUN_0051d750(uint32_t handle, void* buf, uint32_t n);     // read
void FUN_0051d850(uint32_t handle);                            // close
void FUN_00523700(const char* msg);                            // log/flush
void* FUN_0053c810(uint32_t pool, uint32_t size, const char* tag, const char* file, uint32_t line); // alloc
// FX state globals (.data) — defined in VanillaBinStubs
extern uint32_t DAT_0059c958, DAT_0059c960, DAT_0059c964;
extern uint32_t DAT_0059c96c;   // FX table ptr (alloc'd)
}

extern "C" void FUN_0044ab90(const char* fxName) {
    DAT_0059c960 = 0;
    DAT_0059c96c = 0;
    DAT_0059c964 = 0;
    DAT_0059c958 = 0;

    // FUN_00544b47(local_2c, "%s_bin", fxName) — engine sprintf. Build "<fx>_bin".
    char path[44] = {0};
    std::snprintf(path, sizeof(path), "%s_bin", fxName ? fxName : "");

    uint32_t h = FUN_00539e30(path);   // open
    if (h == 0) { FUN_00523700("Failed to open Fx bin"); return; }

    uint32_t version = 0;
    FUN_0051d750(h, &version, 4);
    if (version != 1) { FUN_00523700("Bad version for Fx bin"); FUN_0051d850(h); return; }

    uint32_t count = 0;
    FUN_0051d750(h, &count, 4);                 // entry count (reuses param in vanilla)
    FUN_0051d750(h, &DAT_0059c960, 4);          // header dword
    DAT_0059c96c = (uint32_t)(uintptr_t)FUN_0053c810(0xc, count, "fx bin", "C:\\Giants\\Source\\Main\\fx.c", 0xb6);
    FUN_0051d750(h, (void*)(uintptr_t)DAT_0059c96c, count);   // read the FX table
    FUN_0051d850(h);                            // close
}
