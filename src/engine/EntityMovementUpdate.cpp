// Giants Engine - Entity Movement Update Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
// re-agent verdict: PASS
#include "EntityMovementUpdate.h"
#include <cstring>
#include <cstdlib>

namespace Giants {

// ─── Globals ────────────────────────────────────────────────────
extern uint32_t DAT_0067d280;     // Security cookie
extern uint32_t DAT_0066bd9c;     // Float negative threshold
extern uint32_t DAT_0066c580;     // XOR float mask
extern uint32_t DAT_00682ee0;     // Callback table base

// ─── External callees ──────────────────────────────────────────
extern int  FUN_005687d0();
extern void FUN_00566270();
extern void FUN_0056ca90();

static inline float u2f(uint32_t u) { float f; memcpy(&f, &u, 4); return f; }

void UpdateEntityMovement(int param1)
{
    uint32_t local_c = DAT_0067d280 ^ static_cast<uint32_t>(param1);

    float local_10 = *reinterpret_cast<float*>(param1 + 0xf8) - *reinterpret_cast<float*>(param1 + 0x104);
    float local_18 = *reinterpret_cast<float*>(param1 + 0xf0) - *reinterpret_cast<float*>(param1 + 0xfc);
    float local_14 = *reinterpret_cast<float*>(param1 + 0xf4) - *reinterpret_cast<float*>(param1 + 0x100);

    *reinterpret_cast<uint32_t*>(param1 + 0x124) &= 0xf7e7ffff;

    if ((local_18 != 0.0f) || (local_14 != 0.0f))
    {
        free(*reinterpret_cast<void**>(param1 + 0x270));
        *reinterpret_cast<uint32_t*>(param1 + 0x270) = 0;
    }

    if (*reinterpret_cast<int*>(param1 + 0x264) == 0)
    {
        if ((((*reinterpret_cast<uint32_t*>(param1 + 0x124) & 0x10000000) != 0) ||
             (*reinterpret_cast<float*>(param1 + 0xf0) != *reinterpret_cast<float*>(param1 + 0xfc))) ||
            (*reinterpret_cast<float*>(param1 + 0xf4) != *reinterpret_cast<float*>(param1 + 0x100)) ||
            (*reinterpret_cast<float*>(param1 + 0xf8) != *reinterpret_cast<float*>(param1 + 0x104)))
        {
            *reinterpret_cast<uint32_t*>(param1 + 0x124) &= 0xefffffff;

            **reinterpret_cast<uint8_t**>(param1 + 0x150) = 0;
            *reinterpret_cast<uint32_t*>(param1 + 0x278) = 0;
            *reinterpret_cast<uint32_t*>(param1 + 0x274) = 0;

            if (*reinterpret_cast<int*>(param1 + 0x8) != 0)
            {
                if ((*reinterpret_cast<uint32_t*>(param1 + 0x214) & 0x400) == 0)
                {
                    int iVar2 = 1;
                    int iVar3 = 0;
                    do
                    {
                        if (iVar2 == 0) goto done_collision;
                        iVar2 = FUN_005687d0();
                    } while ((((*reinterpret_cast<float*>(param1 + 0xf0) != *reinterpret_cast<float*>(param1 + 0xfc)) ||
                               (*reinterpret_cast<float*>(param1 + 0xf4) != *reinterpret_cast<float*>(param1 + 0x100))) ||
                              (*reinterpret_cast<float*>(param1 + 0xf8) != *reinterpret_cast<float*>(param1 + 0x104))) &&
                             (iVar3 = iVar3 + 1, iVar3 < 4));

                    if (iVar2 != 0)
                    {
                        *reinterpret_cast<uint64_t*>(param1 + 0xf0) = *reinterpret_cast<uint64_t*>(param1 + 0xfc);
                        *reinterpret_cast<uint32_t*>(param1 + 0xf8) = *reinterpret_cast<uint32_t*>(param1 + 0x104);
                    }
                }

            done_collision:
                if ((*reinterpret_cast<uint32_t*>(param1 + 0x214) & 0x200) == 0)
                    FUN_00566270();
            }

            uint32_t uVar1 = **reinterpret_cast<uint32_t**>(param1 + 0x150);
            if ((uVar1 & 0x68) != 0)
                **reinterpret_cast<uint32_t**>(param1 + 0x150) = uVar1 | 0x80;

            int idx = *reinterpret_cast<int*>(param1 + 0x22c);
            if (((*reinterpret_cast<uint8_t*>(*reinterpret_cast<uintptr_t*>(param1 + 0x150)) & 0x96) != 0) &&
                (idx < 0x6c) &&
                (*reinterpret_cast<void(**)()>(&DAT_00682ee0 + idx * 0x50) != nullptr))
            {
                auto cb = *reinterpret_cast<void(__cdecl**)(int, int)>(&DAT_00682ee0 + idx * 0x50);
                cb(param1, 0);
            }
        }

        float fVar5 = *reinterpret_cast<float*>(param1 + 0xf8) -
                      *reinterpret_cast<float*>(param1 + 0x370) * *reinterpret_cast<float*>(param1 + 0x220);

        if (fVar5 <= 0.0f)
        {
            float fVar4 = u2f(*reinterpret_cast<uint32_t*>(param1 + 0x234) ^ DAT_0066c580);
            uint32_t uVar1 = *reinterpret_cast<uint32_t*>(param1 + 0x124);
            *reinterpret_cast<uint32_t*>(param1 + 0x124) = uVar1 | 0x100000;

            if (fVar5 <= fVar4 * *reinterpret_cast<float*>(param1 + 0x370))
                *reinterpret_cast<uint32_t*>(param1 + 0x124) = uVar1 | 0x8100000;
        }

        if (fVar5 - *reinterpret_cast<float*>(param1 + 0x18c) < u2f(DAT_0066bd9c))
            *reinterpret_cast<uint32_t*>(param1 + 0x124) |= 0x80000;

        FUN_0056ca90();
    }
}

} // namespace Giants
