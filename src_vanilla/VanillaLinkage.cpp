// Giants Vanilla-Native Recomp — doubly-linked-list insert (FUN_00472ef0 port).
// Faithful port of vanilla FUN_00472ef0 (size 273, linkage.c): inserts a linkage node
// into TWO lists (param_1 list + param_2 list) using the free-pool DAT_0059cadc
// (lazily alloc'd in chunks of 0xc6 nodes). See vanilla_decompiled/00472ef0.json.
#include <cstdint>

extern "C" {
void* FUN_0053c810(uint32_t pool, uint32_t size, const char* tag, const char* file, uint32_t line); // alloc (real)
extern uint32_t DAT_0059cadc;   // linkage free-pool head
extern uint32_t DAT_0059cae0;   // linkage pool chunk head
extern const char s_links_0055d658[];
extern const char s_C__Giants_Source_main_linkage_c_0055d660[];
}

// Pop a node from the free-pool, alloc'ing a fresh chunk of 0xc6 nodes if empty.
static int* poolAlloc() {
    int* piVar4 = (int*)(uintptr_t)DAT_0059cadc;
    if (piVar4 == (int*)0) {
        uint32_t* puVar2 = (uint32_t*)FUN_0053c810(0xf, 0xc84, s_links_0055d658, s_C__Giants_Source_main_linkage_c_0055d660, 0x1b);
        *puVar2 = DAT_0059cae0;
        DAT_0059cadc = (uint32_t)(uintptr_t)(puVar2 + 1);
        DAT_0059cae0 = (uint32_t)(uintptr_t)puVar2;
        int* piVar3 = (int*)(uintptr_t)DAT_0059cadc;
        for (int iVar5 = 0xc6; iVar5 != 0; iVar5--) { *piVar3 = (int)(uintptr_t)(piVar3 + 4); piVar3 += 4; }
        puVar2[0x319] = 0;
        piVar4 = (int*)(uintptr_t)DAT_0059cadc;
    }
    DAT_0059cadc = (uint32_t)(uintptr_t)*piVar4;
    return piVar4;
}

extern "C" void FUN_00472ef0(int* param_1, int* param_2) {
    // Walk list1 (*param_1) to its tail.
    int* piVar4 = (int*)(uintptr_t)*param_1;
    int* piVar3 = param_1;
    while (piVar4 != (int*)0) { piVar3 = piVar4; piVar4 = (int*)(uintptr_t)*piVar4; }
    // Node A → insert into list1.
    int* nodeA = poolAlloc();
    nodeA[1] = (int)(uintptr_t)piVar3;
    nodeA[2] = (int)(uintptr_t)param_1;
    nodeA[0] = (int)(uintptr_t)*piVar3;
    nodeA[3] = (int)(uintptr_t)param_2;
    *piVar3 = (int)(uintptr_t)nodeA;
    if (*nodeA != 0) *(int**)(uintptr_t)(*nodeA + 4) = nodeA;
    // Node B → insert into list2 (*param_2).
    int* nodeB = poolAlloc();
    nodeB[1] = (int)(uintptr_t)param_2;
    nodeB[2] = (int)(uintptr_t)param_2;
    nodeB[0] = (int)(uintptr_t)*param_2;
    nodeB[3] = (int)(uintptr_t)nodeA;
    *param_2 = (int)(uintptr_t)nodeB;
    if (*nodeB != 0) *(int**)(uintptr_t)(*nodeB + 4) = nodeB;
}
