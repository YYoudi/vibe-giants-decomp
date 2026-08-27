// GiantsRE system layer - func_0053A4C0
// VA 0x0053A4C0
// via GhidraMCP headless bulk decompile (project with PS2 renames)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void vfs_fileread_load(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  char *pcVar5;
  int iVar6;
  undefined1 *puVar7;
  char local_200 [512];
  
  _DAT_005e12a4 = 0x41200000;
  *param_3 = 0;
  *param_2 = 0;
  if (DAT_005e12c8 != 0) {
    return;
  }
  DAT_005e12c8 = 1;
  FUN_0053a660();
  iVar3 = FUN_0053b280(DAT_005e12b0,param_1);
  if (iVar3 == 0) {
    FUN_00544b47(&DAT_006552c0,s_ZipRead_fail___s_005814c4,param_1);
    FUN_00429100(&DAT_006552c0);
    FUN_00523700(&DAT_006552c0);
    DAT_005e12c8 = 0;
    return;
  }
  iVar6 = *(int *)(iVar3 + 4);
  if (*(int *)(iVar6 + 4) == 0) {
    FUN_00544b47(local_200,s__s__s_0058140c,s_Bin_Override_00581414,iVar3 + 0x10);
    iVar3 = FUN_0051d6f0(local_200);
    if (iVar3 == 0) {
      DAT_005e12c8 = 0;
      return;
    }
    uVar4 = FUN_0051d810(iVar3);
    *param_3 = uVar4;
    uVar4 = mem_alloc_tagged(0x1e,uVar4,s_gzpmem_005814bc,
                             s_C__Giants_Source_Utils_fileread__00581498,0x10a);
    *param_2 = uVar4;
    FUN_0051d750(iVar3,uVar4,*param_3);
    FUN_0051d850(iVar3);
    DAT_005e12c8 = 0;
    return;
  }
  iVar2 = *(int *)(iVar6 + 4);
  if (iVar2 == 0) {
    pcVar5 = s_Bin_Override_00581414;
  }
  else {
    if (iVar2 != 1) {
      if (iVar2 == 2) {
        if (DAT_005e10a0 != '\0') {
          puVar7 = &DAT_005e10a0;
          goto LAB_0053a524;
        }
      }
      else if (DAT_005e11a0 != '\0') {
        puVar7 = &DAT_005e11a0;
LAB_0053a524:
        FUN_00544b47(&DAT_005e0d98,s__s_Bin_00581428,puVar7);
        pcVar5 = &DAT_005e0d98;
        goto LAB_0053a53b;
      }
      local_200[0] = '\0';
      goto LAB_0053a57f;
    }
    pcVar5 = &DAT_00581424;
  }
LAB_0053a53b:
  if (*pcVar5 == '\0') {
    pcVar5 = (char *)(iVar6 + 8);
    iVar6 = -(int)pcVar5;
    do {
      cVar1 = *pcVar5;
      pcVar5[(int)(local_200 + iVar6)] = cVar1;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
  }
  else {
    FUN_00544b47(local_200,s__s__s_0058140c,pcVar5,iVar6 + 8);
  }
LAB_0053a57f:
  if (*(int *)(iVar3 + 4) != DAT_005e12c4) {
    if (DAT_005e12c4 != 0) {
      gzp_close_free();
    }
    DAT_005e12c4 = 0;
    iVar6 = BinFileOpenRead(local_200);
    if (iVar6 == 0) {
      DAT_005e12c8 = 0;
      return;
    }
    DAT_005e12c4 = *(int *)(iVar3 + 4);
  }
  uVar4 = mem_alloc_tagged(0x1e,*(undefined4 *)(iVar3 + 8),s_gzpmem_005814bc,
                           s_C__Giants_Source_Utils_fileread__00581498,0x128);
  *param_2 = uVar4;
  gzp_block_read(*(undefined4 *)(iVar3 + 0xc),*(undefined4 *)(iVar3 + 8),uVar4);
  *param_3 = *(undefined4 *)(iVar3 + 8);
  DAT_005e12c8 = 0;
  return;
}

