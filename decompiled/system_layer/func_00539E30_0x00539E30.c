// GiantsRE system layer - func_00539E30
// VA 0x00539E30
// via GhidraMCP headless bulk decompile (project with PS2 renames)


undefined4 vfs_load_whole_file(undefined4 param_1)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  undefined1 *puVar5;
  char local_200 [512];
  
  FUN_0053a660();
  iVar2 = FUN_0053b280(DAT_005e12b4,param_1);
  if (iVar2 == 0) {
    return 0;
  }
  cVar1 = *(char *)(iVar2 + 4);
  if (cVar1 == '\0') {
    pcVar3 = s_Bin_Override_00581414;
  }
  else {
    if (cVar1 != '\x01') {
      if (cVar1 == '\x02') {
        if (DAT_005e10a0 != '\0') {
          puVar5 = &DAT_005e10a0;
          goto LAB_00539e8b;
        }
      }
      else if (DAT_005e11a0 != '\0') {
        puVar5 = &DAT_005e11a0;
LAB_00539e8b:
        FUN_00544b47(&DAT_005e0d98,s__s_Bin_00581428,puVar5);
        pcVar3 = &DAT_005e0d98;
        goto LAB_00539ea2;
      }
      local_200[0] = '\0';
      goto LAB_00539ee5;
    }
    pcVar3 = &DAT_00581424;
  }
LAB_00539ea2:
  if (*pcVar3 == '\0') {
    pcVar3 = (char *)(iVar2 + 5);
    iVar2 = (int)local_200 - (int)pcVar3;
    do {
      cVar1 = *pcVar3;
      pcVar3[iVar2] = cVar1;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
  }
  else {
    FUN_00544b47(local_200,s__s__s_0058140c,pcVar3,iVar2 + 5);
  }
LAB_00539ee5:
  uVar4 = FUN_0051d6f0(local_200);
  return uVar4;
}

