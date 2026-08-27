// GiantsRE system layer - func_0053A090
// VA 0x0053A090
// via GhidraMCP headless bulk decompile (project with PS2 renames)


HANDLE BinFileRead(char *param_1)

{
  char *pcVar1;
  HANDLE pvVar2;
  int iVar3;
  int iVar4;
  CHAR aCStack_200 [512];
  
  FUN_0053a660();
  iVar3 = 0;
  do {
    iVar4 = DAT_005e12c0;
    if (iVar3 != 0) {
      iVar4 = iVar3;
    }
    if (iVar4 == 0) goto LAB_0053a168;
    if (iVar4 == 0) {
      pcVar1 = s_Override_0058148c;
LAB_0053a0ff:
      if (*pcVar1 == '\0') {
        pcVar1 = s_Music_00581484;
      }
      else {
        FUN_00544b47(&DAT_005e0ea0,s__s_Music_00581478,pcVar1);
        pcVar1 = &DAT_005e0ea0;
      }
      if (*pcVar1 != '\0') {
        FUN_00544b47(aCStack_200,s__s__c_c_c__s_00581468,pcVar1,(int)*param_1,(int)param_1[1],
                     (int)param_1[2],param_1);
        pvVar2 = CreateFileA(aCStack_200,0x80000000,1,(LPSECURITY_ATTRIBUTES)0x0,3,0x8000080,
                             (HANDLE)0x0);
        if (pvVar2 != (HANDLE)0xffffffff) {
          DAT_005e12c0 = iVar4;
          return pvVar2;
        }
      }
    }
    else {
      if (iVar4 == 1) {
        pcVar1 = &DAT_00585524;
        goto LAB_0053a0ff;
      }
      if (iVar4 == 2) {
        if (DAT_005e10a0 != '\0') {
          pcVar1 = &DAT_005e10a0;
          goto LAB_0053a0ff;
        }
      }
      else if (DAT_005e11a0 != '\0') {
        pcVar1 = &DAT_005e11a0;
        goto LAB_0053a0ff;
      }
    }
LAB_0053a168:
    iVar3 = iVar3 + 1;
    if (3 < iVar3) {
      return (HANDLE)0x0;
    }
  } while( true );
}

