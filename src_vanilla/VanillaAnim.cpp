// Giants Vanilla-Native Recomp — FUN_00405080 port (load .anm).
// 1:1 port of vanilla_decompiled/00405080.json (size 369). Manages the anim cache
// (DAT_00585354, refcount at node[2]), loads anim data, builds a 0x58-byte instance
// with scale math. Callees extern/stubbed; addresses cited inline.
#include "VanillaAnim.h"
#include <cstdio>
#include <cstdint>
#include <cstring>

extern "C" {
int  FUN_0053c970(const char* a, const char* b);   // strcmp-eq (real)
void FUN_0053a3e0(const char* name, uint32_t* out1, char** out2);   // FIXME(unverified): load anim data
uint32_t FUN_0053db60(int, int, uint32_t);          // FIXME(unverified): anim create
int* FUN_0053dc40(uint32_t h);                      // FIXME(unverified): anim size ptr
void* FUN_0053c810(uint32_t pool, uint32_t size, const char* tag, const char* file, uint32_t line); // alloc (real)
extern void FUN_00544b47(void*, const char*, ...);  // log (stub)
extern void FUN_00429100(void*);                    // log ctx flush (stub)
extern void FUN_00523aa0(const char*);              // assert/print (real)
extern uint32_t DAT_006552c0;                       // log ctx
extern uint32_t DAT_00585354;                       // anim cache list head
extern uint32_t DAT_0058534c;                       // total anim bytes
extern uint32_t _DAT_005522c0;                      // 1.0f const (scale numerator)
}

// Build a 0x58-byte anim instance from the anim handle fVar5. (LAB_0040518e)
static float* buildAnimInstance(uint32_t fVar5) {
    float* pfVar8 = (float*)FUN_0053c810(2, 0x58, (const char*)0, "C:\\Giants\\Source\\main\\ANIMATE.CP", 0x509);
    float* pfVar11 = pfVar8;
    for (int i = 0x16; i != 0; i--) { *pfVar11 = 0.0f; pfVar11++; }   // zero 0x16 floats
    pfVar8[10] = (float)fVar5;
    float denom = (float)*(int*)((int)fVar5 + 0x1c);
    float fVar2 = *(float*)(uintptr_t)&_DAT_005522c0 / (denom != 0.0f ? denom : 1.0f);
    int iVar4 = *(int*)((int)fVar5 + 0x18);
    pfVar8[1] = *(float*)((int)fVar5 + 0x10);
    int lo = *(int*)((int)fVar5 + 0x10);
    int hi = *(int*)((int)fVar5 + 0x14);
    *pfVar8 = (float)(hi - lo) * (fVar2 / (float)(iVar4 != 0 ? iVar4 : 1));
    *(uint32_t*)&pfVar8[2] = (uint32_t)pfVar8[2] | 1u;
    return pfVar8;
}

extern "C" void FUN_00405080(char* param_1) {
    char* pcVar3 = param_1;
    // Phase 1: search the anim cache (DAT_00585354) by name (at node+3).
    for (uint32_t* n = (uint32_t*)(uintptr_t)DAT_00585354; n; n = (uint32_t*)(uintptr_t)*n) {
        if (FUN_0053c970(pcVar3, (const char*)(n + 3)) != 0) {
            n[2] = n[2] + 1;                        // refcount++
            float fVar5 = (float)n[1];
            if (fVar5 != 0.0f) { buildAnimInstance((uint32_t)fVar5); }
            return;
        }
    }
    // Phase 2: not cached → load.
    uint32_t local_4 = 0;
    char* loadedName = nullptr;
    FUN_0053a3e0(pcVar3, &local_4, &loadedName);
    if (loadedName != (char*)0) {
        uint32_t fVar5 = FUN_0053db60(0, 0, local_4);
        // strlen(pcVar3)
        uint32_t uVar9 = 0xffffffff;
        char* pcVar10 = pcVar3;
        char c;
        do { if (uVar9 == 0) break; uVar9--; c = *pcVar10; pcVar10++; } while (c != '\0');
        uint32_t nodeSize = ~uVar9 + 0xf;
        uint32_t* puVar6 = (uint32_t*)FUN_0053c810(2, nodeSize, (const char*)0, "C:\\Giants\\Source\\main\\ANIMATE.CP", 0x5c5);
        *puVar6 = DAT_00585354;                     // head-insert
        DAT_00585354 = (uint32_t)(uintptr_t)puVar6;
        puVar6[1] = fVar5;
        // strcpy name → node+0xc
        char* dst = (char*)((uintptr_t)puVar6 + 0xc);
        std::strcpy(dst, pcVar3);
        puVar6[2] = 1;
        int* piVar7 = FUN_0053dc40(fVar5);
        DAT_0058534c = DAT_0058534c + (uint32_t)*piVar7;
        if (fVar5 != 0) { buildAnimInstance(fVar5); }
        return;
    }
    // Phase 3: failed → log + set error flag.
    FUN_00544b47((void*)(uintptr_t)&DAT_006552c0, "AnimationCreateF:read_animdata_z", pcVar3);
    FUN_00429100((void*)(uintptr_t)&DAT_006552c0);
    FUN_00523aa0((const char*)(uintptr_t)&DAT_006552c0);
    // FIXME(unverified): vanilla writes _DAT_00000008 |= 1 (Ghidra artifact — absolute addr 8; likely a register/global misread). Skipped.
}
