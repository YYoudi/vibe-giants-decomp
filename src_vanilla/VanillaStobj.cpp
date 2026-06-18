// Giants Vanilla-Native Recomp — stobj lifecycle ports.
// 1:1 structural port of vanilla_decompiled/0049cfd0.json + 0049f3b0.json.
// DAT_/fn addresses cited inline. Callees not yet ported are extern/stubbed.
#include "VanillaStobj.h"
#include <cstdint>

extern "C" {
// callees (stubbed in VanillaStubs/VanillaBinStubs unless noted)
void FUN_0049f480(int stobj, int src);          // FIXME(unverified)
int  FUN_00458e70(int src);                     // FIXME(unverified)
void FUN_00458dd0(int stobj, int idx);          // FIXME(unverified)
int  FUN_00458e00(int src);                     // FIXME(unverified)
void FUN_00458da0(int stobj, int idx);          // FIXME(unverified)
void FUN_0045ba30(int stobj, int src);          // FIXME(unverified)
void FUN_0053c5c0(void* ptr, const char* file, int line);  // deallocator (stub)
void* FUN_0053c810(uint32_t pool, uint32_t size, const char* tag, const char* file, uint32_t line); // alloc (real)
// fn-ptr tables indexed by kind (vanilla .data); 0 here while dormant
extern uint32_t DAT_0055f8cc;   // objspec constructor table (kind*0x44)
extern uint32_t DAT_0055f8e0;   // objspec destructor table (kind*0x44)
extern const char s_C__Giants_Source_main_objspec_c_0056152c[];
extern const char s_ospec_0056154c[];
}

// FUN_0049cfd0 — copy defaults from src into stobj. (vanilla 0049cfd0)
extern "C" void FUN_0049cfd0(int param_1, int param_2) {
    int iVar1 = param_2;
    *(uint32_t*)(param_1 + 0xa0) = *(uint32_t*)(param_2 + 0xa0);
    *(uint32_t*)(param_1 + 0xa4) = *(uint32_t*)(param_2 + 0xa4);
    *(uint32_t*)(param_1 + 0xa8) = *(uint32_t*)(param_2 + 0xa8);
    *(uint32_t*)(param_1 + 0xb8) = *(uint32_t*)(param_2 + 0xb8);
    *(uint32_t*)(param_1 + 0xbc) = *(uint32_t*)(param_2 + 0xbc);
    *(uint32_t*)(param_1 + 0xc0) = *(uint32_t*)(param_2 + 0xc0);
    *(uint32_t*)(param_1 + 0xac) = *(uint32_t*)(param_2 + 0xac);
    *(uint32_t*)(param_1 + 0xb0) = *(uint32_t*)(param_2 + 0xb0);
    *(uint32_t*)(param_1 + 0xb4) = *(uint32_t*)(param_2 + 0xb4);
    *(uint32_t*)(param_1 + 200) = *(uint32_t*)(param_2 + 200);   // 0xc8
    *(uint32_t*)(param_1 + 0xd4) = *(uint32_t*)(param_2 + 0xd4);
    *(uint32_t*)(param_1 + 0xcc) = *(uint32_t*)(param_2 + 0xcc);
    *(uint32_t*)(param_1 + 0xd0) = *(uint32_t*)(param_2 + 0xd0);
    *(uint32_t*)(param_1 + 0xd8) = *(uint32_t*)(param_2 + 0xd8);
    *(uint32_t*)(param_1 + 0xdc) = *(uint32_t*)(param_2 + 0xdc) | 0x80000000u;
    *(uint32_t*)(param_1 + 0x18c) = *(uint32_t*)(param_2 + 0x18c);
    *(uint32_t*)(param_1 + 0xe0) = *(uint32_t*)(param_2 + 0xe0);
    *(uint32_t*)(param_1 + 0xe8) = *(uint32_t*)(param_2 + 0xe8);
    *(uint32_t*)(param_1 + 0xe4) = *(uint32_t*)(param_2 + 0xe4);
    FUN_0049f480(param_1, param_2);
    *(uint32_t*)(param_1 + 0xec) = *(uint32_t*)(param_2 + 0xec);
    if (0 < *(int*)(param_2 + 0x1d8)) {
        int iVar2 = FUN_00458e70(param_2);
        if ((0 < iVar2) && (iVar2 <= *(int*)(param_1 + 0x1d8))) FUN_00458dd0(param_1, iVar2);
        iVar2 = FUN_00458e00(param_2);
        if ((0 < iVar2) && (iVar2 <= *(int*)(param_1 + 0x1d8))) FUN_00458da0(param_1, iVar2);
    }
    // copy 4 × 9-dword block from src (param_2 - param_1 offset) starting at +0x10
    int iVar2 = param_2 - param_1;
    uint32_t* puVar3 = (uint32_t*)(param_1 + 0x10);
    for (int n = 0; n < 4; n++) {
        uint32_t* src = (uint32_t*)(iVar2 + (int)(puVar3));
        for (int k = 0; k < 9; k++) { *puVar3 = *src; src++; puVar3++; }
    }
    FUN_0045ba30(param_1, iVar1);
}

// FUN_0049f3b0 — set object kind/subtype. Runs old-kind destructor, frees +0x100,
// sets +0x1e0=kind, runs new-kind constructor + allocs objspec. (vanilla 0049f3b0)
extern "C" void FUN_0049f3b0(int param_1, int param_2) {
    int curKind = *(int*)(param_1 + 0x1e0);
    uintptr_t dtbl = (uintptr_t)&DAT_0055f8e0;   // destructor table base (byte-indexed, kind*0x44)
    if ((curKind < 0x6b) &&
        (*(uint32_t*)(dtbl + curKind * 0x44) != 0) &&
        (*(int*)(param_1 + 0x100) != 0)) {
        typedef void (__cdecl *Fn)(int);
        Fn d = *(Fn*)(dtbl + curKind * 0x44);
        d(param_1);
    }
    if (*(int*)(param_1 + 0x100) != 0) {
        FUN_0053c5c0((void*)(uintptr_t)*(int*)(param_1 + 0x100), s_C__Giants_Source_main_objspec_c_0056152c, 0xf9);
        *(uint32_t*)(param_1 + 0x100) = 0;
    }
    *(int*)(param_1 + 0x1e0) = param_2;
    uintptr_t ctbl = (uintptr_t)&DAT_0055f8cc;   // constructor table base (byte-indexed, kind*0x44)
    if ((*(int*)(param_1 + 0x100) == 0) && (param_2 < 0x6b) &&
        (*(uint32_t*)(ctbl + param_2 * 0x44) != 0)) {
        typedef uint32_t (__cdecl *Ctor)(int);
        Ctor c = *(Ctor*)(ctbl + param_2 * 0x44);
        uint32_t uVar1 = c(param_1);
        if (uVar1 != 0) {
            uint32_t* puVar2 = (uint32_t*)FUN_0053c810(0x18, uVar1, s_ospec_0056154c, s_C__Giants_Source_main_objspec_c_0056152c, 0xed);
            *(uint32_t**)(param_1 + 0x100) = puVar2;
            for (uint32_t uVar3 = uVar1 >> 2; uVar3 != 0; uVar3--) { *puVar2 = 0; puVar2++; }
            for (uint32_t r = uVar1 & 3; r != 0; r--) { *(uint8_t*)puVar2 = 0; puVar2 = (uint32_t*)((int)puVar2 + 1); }
        }
    }
}

