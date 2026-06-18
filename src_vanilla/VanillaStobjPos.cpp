// Giants Vanilla-Native Recomp — FUN_00472560 port (stobj position/transform apply).
// 1:1 structural port of vanilla_decompiled/00472560.json. DAT_/fn addresses cited.
// Callees FUN_004720d0 (quat transform) + globals DAT_006313c8/_DAT_005525f8 referenced.
#include "VanillaStobjPos.h"
#include <cmath>
#include <cstdint>

extern "C" {
extern uint32_t DAT_006313c8;   // placed-object list head (defined in VanillaSceneLists)
extern float    _DAT_005525f8;  // .data float const (defined in VanillaBinStubs as 0 — FIXME)
void FUN_004720d0(uint32_t* v); // callee (stub): transform the 4-dword pos quaternion
}

// FUN_00472560(stobj, pos[4]). Writes pos into the stobj local matrix (+0x100) slots,
// and (if matrix flag bit0 set) resolves the attachment-slot index from DAT_006313c8.
extern "C" void FUN_00472560(int stobj, uint32_t* pos) {
    uint32_t local[4] = { pos[0], pos[1], pos[2], pos[3] };
    FUN_004720d0(local);                                   // [0x47256c] transform quat

    uint32_t* m = *(uint32_t**)(uintptr_t)(stobj + 0x100); // matrix ptr (stobj+0x100)
    *m = *m | 0xc;                                         // [0x47257a] set flag bits 2|3
    m[2] = local[0]; m[3] = local[1]; m[4] = local[2]; m[5] = local[3];
    m[6] = local[0]; m[7] = local[1]; m[8] = local[2]; m[9] = local[3];
    m[0xa] = local[0]; m[0xb] = local[1]; m[0xc] = local[2]; m[0xd] = local[3];

    uint32_t* m2 = *(uint32_t**)(uintptr_t)(stobj + 0x100);
    if ((~(*m2) & 1u) != 0) {                              // [0x4725c0] if flag bit0 clear
        if (*(int*)(uintptr_t)(stobj + 0xe8) == 0) {       // [0x4725c8] slot not yet assigned
            // Walk DAT_006313c8; collect stobjs whose +0x1e0==0x5c into slots[1..3] by +0xe8.
            int slots[4] = {0,0,0,0};
            for (uint32_t* p = (uint32_t*)(uintptr_t)DAT_006313c8; p; p = (uint32_t*)(uintptr_t)*p) {
                int s = (int)(uintptr_t)p[3];              // stobj ref at node+0xc
                if (*(int*)(uintptr_t)(s + 0x1e0) == 0x5c) {
                    int slot = *(int*)(uintptr_t)(s + 0xe8);
                    if (slot > 0 && slot < 4) slots[slot] = s;
                }
            }
            // First-null-slot search (matches decompiled iVar7 pre-increment + goto).
            int iVar7 = 0;
            while (1) {
                int idx = iVar7;                           // puVar1 = local_10 + iVar7 (pre-incr)
                iVar7 = iVar7 + 1;
                if (slots[idx] == 0) break;                // goto LAB: iVar7 = idx+1
                if (!(iVar7 < 3)) { iVar7 = 0; break; }    // normal exit: iVar7 = 0
            }
            *(int*)(uintptr_t)(stobj + 0xe8) = iVar7;      // LAB_00472652
        }
        m2[1] = 3;                                         // [0x472660]
        if ((~(*m2) & 8u) != 0) {                          // scale-init
            m2[4] = 0x3f800000; m2[3] = 0x3f800000; m2[2] = 0x3f800000;  // 1.0f
            *m2 |= 8u;
        }
        if ((~(*m2) & 4u) != 0) {                          // mirror scale into matrix
            *m2 |= 4u;
            m2[0xa]=m2[2]; m2[0xb]=m2[3]; m2[0xc]=m2[4]; m2[0xd]=m2[5];
            m2[6]=m2[2];   m2[7]=m2[3];   m2[8]=m2[4];   m2[9]=m2[5];
        }
        float f = _DAT_005525f8;
        m2[0x16] = 0x3f800000;                             // 1.0f
        m2[0x14] = (uint32_t)std::sqrt(f);                 // SQRT(fVar6)
        *(uint32_t*)(uintptr_t)(stobj + 0xf4) = 1u;
        *m2 = (*m2 & 0xfffffffd) | 1u;                     // clear bit1, set bit0
    }
    *m = *m & 0xfffffffd;                                  // [0x4726a3] clear bit1
}
