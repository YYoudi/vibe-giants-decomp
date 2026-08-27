// GiantsRE system layer - mem_free_tagged
// VA 0x0053C5C0 (ghidra name was mem_free_tagged)
// provenance: runtime anchors in scripts/re_db.json + PS2 symbols


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void mem_free_tagged(int *param_1)

{
  undefined *puVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  bool bVar7;
  undefined1 local_190 [200];
  undefined1 local_c8 [200];
  
  if (DAT_005ee7a4 == 0) {
    DAT_005ee7a4 = 1;
    DAT_005ee7a8 = 0;
    _DAT_005ee75c = 0x71625344;
    _DAT_005ee760 = 0;
    DAT_005ee764 = &DAT_005ee75c;
    DAT_005ee768 = &DAT_005ee75c;
    DAT_005ee758 = 0;
    DAT_005ee790 = 0;
    DAT_005ee79c = 0;
    DAT_005ee794 = 0;
    DAT_005ee798 = 0;
    DAT_005ee750 = 0;
    DAT_005ee7a0 = 0;
    DAT_005ee754 = 0;
    DAT_0062f510 = 0;
  }
  if (param_1 != (int *)0x0) {
    if (DAT_005ee7a8 == 0) {
      FUN_00545fd9(param_1[-1] + -0x10 + (int)param_1);
      return;
    }
    uVar2 = DAT_005ee7a8 & 1;
    if (uVar2 != 0) {
      param_1 = param_1 + -4;
    }
    if ((param_1[-0xc] != 0x12345678) && (param_1[-0xc] != 0x12345679)) {
      piVar4 = param_1;
      if (uVar2 != 0) {
        piVar4 = param_1 + 4;
      }
      FUN_00544b47(local_c8,s_MemVfy__Bad_magic__lX_from__s_li_00581600,piVar4,param_1 + -8,
                   param_1[-1]);
      FUN_00429100(local_c8);
      DAT_005ee754 = DAT_005ee754 + 1;
      FUN_00523aa0(s_Bad_Memory_Picket_Found_005819c4);
      return;
    }
    if (uVar2 != 0) {
      iVar3 = 4;
      bVar7 = true;
      piVar4 = param_1;
      piVar5 = (int *)PTR_s_0123456789ABCDEF_005815e8;
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        bVar7 = *piVar4 == *piVar5;
        piVar4 = piVar4 + 1;
        piVar5 = piVar5 + 1;
      } while (bVar7);
      if (!bVar7) {
        FUN_00544b47(local_190,s_Crpt_strt_pkt_sz_ad__lu__lX_from_00581654,param_1[-0xb],param_1 + 4
                     ,param_1 + -8,param_1[-1]);
        FUN_00429100(local_190);
        puVar1 = PTR_s_0123456789ABCDEF_005815e8;
        *param_1 = *(int *)PTR_s_0123456789ABCDEF_005815e8;
        param_1[1] = *(int *)(puVar1 + 4);
        param_1[2] = *(int *)(puVar1 + 8);
        param_1[3] = *(int *)(puVar1 + 0xc);
        DAT_005ee754 = DAT_005ee754 + 1;
      }
      iVar3 = 4;
      bVar7 = true;
      piVar4 = (int *)(param_1[-0xb] + 0x10 + (int)param_1);
      piVar5 = piVar4;
      piVar6 = (int *)PTR_s_0123456789ABCDEF_005815e8;
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        bVar7 = *piVar5 == *piVar6;
        piVar5 = piVar5 + 1;
        piVar6 = piVar6 + 1;
      } while (bVar7);
      if (!bVar7) {
        FUN_00544b47(local_190,s_Crpt_end_pkt_sz_ad__lu__lX_from___00581628,param_1[-0xb],
                     param_1 + 4,param_1 + -8,param_1[-1]);
        FUN_00429100(local_190);
        puVar1 = PTR_s_0123456789ABCDEF_005815e8;
        *piVar4 = *(int *)PTR_s_0123456789ABCDEF_005815e8;
        piVar4[1] = *(int *)(puVar1 + 4);
        piVar4[2] = *(int *)(puVar1 + 8);
        piVar4[3] = *(int *)(puVar1 + 0xc);
        DAT_005ee754 = DAT_005ee754 + 1;
      }
    }
    DAT_005ee750 = DAT_005ee750 + -1;
    DAT_005ee7a0 = DAT_005ee7a0 - param_1[-0xb];
    *(int *)(param_1[-9] + 8) = param_1[-10];
    *(int *)(param_1[-10] + 0xc) = param_1[-9];
    param_1[-0xc] = 0x33abcdef;
    FUN_00545fd9(param_1[-0xd] + -0x40 + (int)param_1);
  }
  return;
}


