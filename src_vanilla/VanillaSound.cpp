// Giants Vanilla-Native Recomp — FUN_00491830 port (sound loader).
// 1:1 port of vanilla_decompiled/00491830.json (size 240). DAT_/fn addresses cited.
#include "VanillaSound.h"
#include <cstdint>
#include <cstring>

extern "C" {
extern uint32_t DAT_006316ec;        // world_state
int  FUN_00547250(const char* a, const char* b);   // strcmp (real)
extern void FUN_00544b47(void*, const char*, ...); // log (stub)
extern void FUN_00523aa0(const char*);             // print (real)
extern const char s_Too_many_scenerios__skipping___d_0055e7ec[];
}

extern "C" void FUN_00491830(int param_1, uint32_t param_2, const char* param_3) {
    int* piVar3 = (int*)(uintptr_t)(DAT_006316ec + 0x4554);
    int iVar1 = 0;
    do {
        if (*piVar3 == 0) {
            if (iVar1 < 0x1b) {
                int off = iVar1 * 0x30;
                *(int*)(uintptr_t)(DAT_006316ec + 0x4554 + off) = param_1;
                *(uint32_t*)(uintptr_t)(DAT_006316ec + 0x4558 + off) = param_2;
                strncpy((char*)(uintptr_t)(DAT_006316ec + 0x455c + off), param_3 ? param_3 : "", 0x20);
                if (param_1 != 2) return;
                // kind==2: resolve name index in the +0x2214 table (stride 0x118).
                int iVar5 = 0, iVar4 = 0;
                do {
                    int iVar2 = FUN_00547250((const char*)(uintptr_t)(DAT_006316ec + 0x2214 + iVar5), param_3 ? param_3 : "");
                    if (iVar2 == 0) {
                        *(int*)(uintptr_t)(DAT_006316ec + 0x457c + off) = iVar4;
                        return;
                    }
                    iVar5 += 0x118;
                    iVar4 += 1;
                } while (iVar5 < 0x2300);
                return;
            }
            break;
        }
        iVar1 += 1;
        piVar3 += 0xc;   // stride 0x30 bytes = 0xc dwords
    } while (iVar1 < 0x1b);
    // No free slot.
    FUN_00544b47((void*)0, s_Too_many_scenerios__skipping___d_0055e7ec, 0x1b);
    FUN_00523aa0(s_Too_many_scenerios__skipping___d_0055e7ec);
}
