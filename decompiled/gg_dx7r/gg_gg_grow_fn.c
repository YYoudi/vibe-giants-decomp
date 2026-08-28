// gg_dx7r.dll - gg_grow_fn @ 0x10002410

void FUN_10002410(int param_1)

{
  ushort uVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  ushort *puVar8;
  
  iVar7 = 0;
  iVar6 = *(int *)(param_1 + 0x38);
  if (*(int *)(param_1 + 0x68) != 0) {
    *(undefined4 *)(param_1 + 0x78) = 0;
    *(int *)(param_1 + 0x7c) = *(int *)(param_1 + 0x68);
    (**(code **)(param_1 + 0x5c))(param_1);
    puVar8 = *(ushort **)(param_1 + 0x70);
    uVar2 = *(undefined4 *)(param_1 + 0xc4 + *(int *)(param_1 + 0x90) * 4);
    for (iVar5 = *(int *)(param_1 + 0x74) - (int)puVar8 >> 1; iVar5 != 0; iVar5 = iVar5 + -1) {
      iVar3 = *(int *)(param_1 + 0x50);
      if (iVar3 == 1) {
        *(uint *)(iVar6 + 0x518) = *(int *)(iVar6 + 0x518) + (*puVar8 - 1);
      }
      else if (iVar3 == 3) {
        *(uint *)(iVar6 + 0x50c) = *(int *)(iVar6 + 0x50c) + (*puVar8 - 2);
      }
      else if (iVar3 == 4) {
        *(uint *)(iVar6 + 0x510) = *(int *)(iVar6 + 0x510) + (*puVar8 - 2);
      }
      (**(code **)(**(int **)(iVar6 + 0x294) + 0x7c))
                (*(int **)(iVar6 + 0x294),*(undefined4 *)(param_1 + 0x8c),uVar2,iVar7,*puVar8,
                 *(undefined4 *)(param_1 + 0x98));
      uVar1 = *puVar8;
      puVar8 = puVar8 + 1;
      iVar7 = iVar7 + (uint)uVar1;
    }
    iVar6 = *(int *)(param_1 + 0x90) + 1;
    *(int *)(param_1 + 0x90) = iVar6;
    if (*(int *)(param_1 + 0x88) <= iVar6) {
      *(undefined4 *)(param_1 + 0x90) = 0;
    }
    if (*(int *)(param_1 + 0x6c) != 0) {
      (*DAT_10048914)(s_Error_locking_vertex_buffer__alr_100192fc);
      *(undefined4 *)(param_1 + 0x68) = 0;
      *(undefined4 *)(param_1 + 0x74) = *(undefined4 *)(param_1 + 0x70);
      return;
    }
    piVar4 = *(int **)(param_1 + 0xbc + *(int *)(param_1 + 0x90) * 4);
    (**(code **)(*piVar4 + 0xc))(piVar4,*(undefined4 *)(param_1 + 0x94),param_1 + 0x6c,0);
    *(undefined4 *)(param_1 + 0x68) = 0;
    *(undefined4 *)(param_1 + 0x74) = *(undefined4 *)(param_1 + 0x70);
  }
  return;
}

