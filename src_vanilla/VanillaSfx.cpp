// Giants Vanilla-Native Recomp — FUN_0049a580 port (SFX section loader).
// 1:1 port of vanilla_decompiled/0049a580.json (size 904). Addresses cited inline.
#include "VanillaSfx.h"
#include <cstdint>

extern "C" {
uint32_t FUN_0051d750(uint32_t h, void* buf, uint32_t n);          // read (real)
void FUN_0051d7b0(uint32_t h, uint32_t off);                       // seek (real)
void* FUN_0053c810(uint32_t pool, uint32_t sz, const char* tag, const char* file, uint32_t line); // alloc (real)
void FUN_0053c5c0(void* ptr, const char* file, uint32_t line);     // free (stub)
void FUN_0053a3e0(int name, uint32_t* outHandle, int* outSize);    // FIXME(unverified): load data
int  FUN_0052f960(void);                                            // gate (real)
extern void FUN_00544b47(void*, const char*, ...);                 // log (stub)
extern void FUN_00429100(void*);                                   // log flush (stub)
extern uint32_t DAT_006552c0;
extern uint32_t DAT_0063141c;   // sounds table ptr
extern uint32_t DAT_00631418;   // sounds table count (2000)
extern uint32_t DAT_0063185c;   // SFX init flag
extern uint32_t DAT_0062f510;   // total sound bytes
}

extern "C" void FUN_0049a580(uint32_t param_1) {
    // Lazy-alloc the sounds table once (2000 entries × 0xb dwords = 88000 bytes).
    if (DAT_0063141c == 0) {
        DAT_00631418 = 2000;
        DAT_0063141c = (uint32_t)(uintptr_t)FUN_0053c810(0x17, 88000, "sounds", "C:\\Giants\\Source\\main\\noise.c", 0xa6);
        uint32_t* p = (uint32_t*)(uintptr_t)DAT_0063141c;
        for (uint32_t u = DAT_00631418 * 0xb & 0x3fffffff; u != 0; u--) { *p = 0; p++; }
    }
    if (DAT_0063185c != 0) return;

    int local_24 = 0, local_20 = 0, local_1c = 0, local_18 = 0, local_14 = 0, local_10 = 0, local_c = 0, local_8 = 0;
    uint32_t local_4 = 0;
    FUN_0051d750(param_1, &local_24, 4);
    if (local_24 == -1) {
        FUN_0051d750(param_1, &local_18, 4);
        FUN_0051d750(param_1, &local_24, 4);
        FUN_0051d750(param_1, &local_8, 4);
        FUN_0051d750(param_1, &local_1c, 4);
        local_14 = 0x14;
    } else {
        local_18 = 0x33221100;
        local_8 = 0x1c;
        local_1c = local_24 * 0x1c;
        local_14 = 0;
    }
    if (local_24 == 0) return;

    uint32_t* tab = (uint32_t*)(uintptr_t)DAT_0063141c;
    int iVar6 = (int)(uintptr_t)FUN_0053c810(0x17, (uint32_t)local_1c, "sfxdef", "C:\\Giants\\Source\\main\\noise.c", 0xc6);
    local_c = iVar6;
    FUN_0051d750(param_1, (void*)(uintptr_t)iVar6, local_1c - local_14);

    local_10 = 0;
    if (0 < local_24) {
        do {
            char* entry = (char*)(uintptr_t)(local_10 * local_8 + iVar6);
            int iVar1 = *(int*)entry;
            int iVar2 = (int)tab[iVar1 * 0xb + 1];
            FUN_0053c5c0((void*)(uintptr_t)tab[iVar1 * 0xb], "C:\\Giants\\Source\\main\\noise.c", 0xe1);
            tab[iVar1 * 0xb] = 0;
            tab[iVar1 * 0xb + 3] = *(uint32_t*)(entry + 4);
            tab[iVar1 * 0xb + 7] = *(uint32_t*)(entry + 8);
            tab[iVar1 * 0xb + 5] = *(uint32_t*)(entry + 0xc);
            tab[iVar1 * 0xb + 6] = *(uint32_t*)(entry + 0x10);
            if (local_18 == 0x33221100) {
                tab[iVar1 * 0xb + 9] = 0;
                tab[iVar1 * 0xb + 10] = 0;
                local_20 = *(int*)(entry + 0x18);
                if (iVar2 == 0) {
                    FUN_0051d7b0(param_1, *(uint32_t*)(entry + 0x14));
                    uint32_t uVar3 = (uint32_t)(uintptr_t)FUN_0053c810(0x17, (uint32_t)local_20, (const char*)0, "C:\\Giants\\Source\\main\\noise.c", 0x103);
                    tab[iVar1 * 0xb + 1] = uVar3;
                    DAT_0062f510 = DAT_0062f510 + (uint32_t)local_20;
                    FUN_0051d750(param_1, (void*)(uintptr_t)tab[iVar1 * 0xb + 1], (uint32_t)local_20);
                }
            } else {
                tab[iVar1 * 0xb + 9] = *(uint32_t*)(entry + 0x14);
                int* piVar7 = (int*)(uintptr_t)(entry + 0x1c);
                tab[iVar1 * 0xb + 10] = *(uint32_t*)(entry + 0x18);
                if (local_18 == 0x33221102) {
                    int iVar4 = FUN_0052f960();
                    if (iVar4 != 0) tab[iVar1 * 0xb + 9] = (uint32_t)*piVar7;
                    iVar4 = FUN_0052f960();
                    if (iVar4 != 0) tab[iVar1 * 0xb + 10] = *(uint32_t*)(entry + 0x20);
                    piVar7 = (int*)(uintptr_t)(entry + 0x24);
                }
                int nameOff = (*piVar7 - local_14) + local_c;
                if (iVar2 == 0) {
                    int sz = 0;
                    FUN_0053a3e0(nameOff, &local_4, &sz);
                    DAT_0062f510 = DAT_0062f510 + (uint32_t)sz;
                    if (sz == 0) {
                        FUN_00544b47((void*)(uintptr_t)&DAT_006552c0, "Failed binread %s", nameOff);
                        FUN_00429100((void*)(uintptr_t)&DAT_006552c0);
                    }
                    tab[iVar1 * 0xb + 1] = local_4;
                }
            }
            uint32_t uVar3 = (uint32_t)(uintptr_t)FUN_0053c810(0x17, 8, (const char*)0, "C:\\Giants\\Source\\main\\noise.c", 0x130);
            tab[iVar1 * 0xb] = uVar3;
            FUN_00544b47((void*)(uintptr_t)tab[iVar1 * 0xb], "SFX %d", iVar1);
            local_10++;
            iVar6 = local_c;
        } while (local_10 < local_24);
    }
    FUN_0053c5c0((void*)(uintptr_t)iVar6, "C:\\Giants\\Source\\main\\noise.c", 0x134);
}
