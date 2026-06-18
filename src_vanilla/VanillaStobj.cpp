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


// ── FUN_0049ccf0 — init placed-object slot. (vanilla 0049ccf0) ──
// Copies the 0x1e-dword block + transform-ref-mats + 4×9 matrix from objData, allocs
// transform-ref-mats (count*0x44), sets up a dynamic shadow texture if flagged, runs
// the sound callback. Addresses cited inline.
extern "C" {
extern uint32_t DAT_006316ec;          // world_state
extern const char s_C__Giants_Source_main_object_c_0055f784[];
extern const char s_Transform_Ref_Mats_0055f810[];
extern const char s_Dynamic_shadow_texture_0055f824[];
void FUN_0049f350(int stobj);          // FIXME(unverified): kind-change teardown
void FUN_0049c9b0(int stobj, int a);   // FIXME(unverified): clear transform refs
void FUN_0049f2d0(int stobj);          // FIXME(unverified): recompute derived
void FUN_0044bc40(int a, int b, void* arg);  // FIXME(unverified): sound callback (3-int struct)
}
extern "C" void FUN_0049ccf0(int param_1, int param_2) {
    int iVar2 = param_2;
    if (*(int*)(uintptr_t)(param_2 + 0x1e0) != *(int*)(uintptr_t)(param_1 + 0x1e0)) FUN_0049f350(param_1);
    // copy 0x1e dwords from param_2+400 to param_1+400
    {
        uint32_t* s = (uint32_t*)(uintptr_t)(param_2 + 400);
        uint32_t* d = (uint32_t*)(uintptr_t)(param_1 + 400);
        for (int i = 0x1e; i != 0; i--) { *d = *s; s++; d++; }
    }
    int iVar5 = *(int*)(uintptr_t)(param_2 + 8);
    if ((iVar5 == 0) || (*(int*)(uintptr_t)(iVar5 + 0x450) == 0)) {
        FUN_0053c5c0((void*)(uintptr_t)*(uint32_t*)(uintptr_t)(param_1 + 0x2dc), s_C__Giants_Source_main_object_c_0055f784, 0x161);
        *(uint32_t*)(uintptr_t)(param_1 + 0x2dc) = 0;
        *(uint32_t*)(uintptr_t)(param_1 + 0x2d8) = 0;
    } else {
        if (*(int*)(uintptr_t)(param_1 + 0x2d8) != *(int*)(uintptr_t)(iVar5 + 0x450)) {
            FUN_0049c9b0(param_1, 0);
            int iVar7 = *(int*)(uintptr_t)(iVar5 + 0x450);
            *(int*)(uintptr_t)(param_1 + 0x2d8) = iVar7;
            uint32_t uVar3 = (uint32_t)(uintptr_t)FUN_0053c810(0x18, (uint32_t)iVar7 * 0x44, s_Transform_Ref_Mats_0055f810, s_C__Giants_Source_main_object_c_0055f784, 0x15a);
            *(uint32_t*)(uintptr_t)(param_1 + 0x2dc) = uVar3;
        }
        uint32_t* puVar4 = *(uint32_t**)(uintptr_t)(param_1 + 0x2dc);
        for (uint32_t uVar6 = *(int*)(uintptr_t)(param_1 + 0x2d8) * 0x11 & 0x3fffffff; uVar6 != 0; uVar6--) { *puVar4 = 0; puVar4++; }
    }
    *(int*)(uintptr_t)(param_1 + 8) = iVar5;
    *(uint32_t*)(uintptr_t)(param_1 + 4) = *(uint32_t*)(uintptr_t)(param_2 + 4);
    *(uint32_t*)(uintptr_t)(param_1 + 0xc4) = *(uint32_t*)(uintptr_t)(param_2 + 0xc4);
    *(uint32_t*)(uintptr_t)(param_1 + 0x178) = *(uint32_t*)(uintptr_t)(param_2 + 0x178);
    *(uint32_t*)(uintptr_t)(param_1 + 0x17c) = *(uint32_t*)(uintptr_t)(param_2 + 0x17c);
    *(uint32_t*)(uintptr_t)(param_1 + 0x180) = *(uint32_t*)(uintptr_t)(param_2 + 0x180);
    FUN_0049f2d0(param_1);
    FUN_0049f480(param_1, param_2);
    // copy 4 × 9-dword matrix from src (param_2-param_1 offset) starting at +0x10
    int iVar5b = param_2 - param_1;
    uint32_t* puVar4b = (uint32_t*)(uintptr_t)(param_1 + 0x10);
    for (int n = 0; n < 4; n++) {
        uint32_t* src = (uint32_t*)(uintptr_t)(iVar5b + (int)(uintptr_t)puVar4b);
        for (int k = 0; k < 9; k++) { *puVar4b = *src; src++; puVar4b++; }
    }
    *(uint32_t*)(uintptr_t)(param_1 + 0x2e4) = *(uint32_t*)(uintptr_t)(iVar2 + 0x2e4);
    int iVar5c = *(int*)(uintptr_t)(iVar2 + 0x2e0);
    if (iVar5c != 0) {
        if (*(int8_t*)(uintptr_t)(iVar5c + 0x1e) < 0) {   // sign bit set → dynamic shadow
            uint32_t uVar3 = *(uint32_t*)(uintptr_t)(iVar5c + 0x10);
            uint32_t uVar1 = *(uint32_t*)(uintptr_t)(iVar5c + 0xc);
            uint32_t* puVar4c = (uint32_t*)FUN_0053c810(0x18, 0x20, s_Dynamic_shadow_texture_0055f824, s_C__Giants_Source_main_object_c_0055f784, 0x23a);
            puVar4c[4] = uVar3;
            *(const char**)puVar4c = s_Dynamic_shadow_texture_0055f824;
            puVar4c[1] = 0; puVar4c[2] = 0; puVar4c[3] = uVar1;
            puVar4c[6] = 5; puVar4c[5] = 5;
            *(uint8_t*)((uintptr_t)puVar4c + 0x1d) = 0;
            *(uint8_t*)(uintptr_t)(puVar4c + 7) = 0x20;
            *(uint16_t*)((uintptr_t)puVar4c + 0x1e) = 0x80;
            int iVar5d = *(int*)(uintptr_t)(param_1 + 0x2e0);
            if ((iVar5d != 0) && (*(int8_t*)(uintptr_t)(iVar5d + 0x1e) < 0)) FUN_0053c5c0((void*)(uintptr_t)iVar5d, s_C__Giants_Source_main_object_c_0055f784, 0x249);
            *(uint32_t**)(uintptr_t)(param_1 + 0x2e0) = puVar4c;
        } else {
            *(int*)(uintptr_t)(param_1 + 0x2e0) = iVar5c;
        }
    }
    // sound callback (3-int struct on stack)
    int local_34[5] = {0,0,0,0,0};
    local_34[0] = *(int*)(uintptr_t)(iVar2 + 0x2fc);
    if ((0 < local_34[0]) && (*(int*)(uintptr_t)(DAT_006316ec + 0x178) != 0)) {
        int local_20 = (int)*(int8_t*)(uintptr_t)(iVar2 + 0x2f8);
        int local_1c = param_1;
        int args[3] = { local_34[0], local_20, local_1c };
        FUN_0044bc40(0, 0x14, args);
    }
}
