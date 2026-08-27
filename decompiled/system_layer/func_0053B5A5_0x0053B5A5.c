// GiantsRE system layer - func_0053B5A5
// VA 0x0053B5A5
// via GhidraMCP headless bulk decompile (project with PS2 renames)


void gzp_block_read(byte *param_1,uint param_2,byte *param_3)

{
  byte bVar1;
  byte bVar2;
  bool bVar3;
  byte *lpBuffer;
  int iVar4;
  uint uVar5;
  uint uVar6;
  byte *pbVar7;
  byte *pbVar8;
  undefined4 *puVar9;
  uint uVar10;
  int local_30 [3];
  int local_24;
  int local_20;
  uint local_1c;
  DWORD local_18;
  DWORD local_14;
  DWORD local_10;
  DWORD local_c;
  DWORD local_8;
  
  SetFilePointer(DAT_005ee74c,(LONG)param_1,(PLONG)0x0,0);
  ReadFile(DAT_005ee74c,local_30,0x10,&local_18,(LPOVERLAPPED)0x0);
  if (local_24 == 2) {
    ReadFile(DAT_005ee74c,param_3,param_2,&local_18,(LPOVERLAPPED)0x0);
    return;
  }
  if (local_24 != 1) {
    return;
  }
  DAT_005ee730 = local_30[0] - 0x10;
  if (DAT_005ee724 == (byte *)0x0) {
    DAT_005ee724 = (byte *)mem_alloc_tagged(0x20,0x8000,s_lzssbuff_005815b4,
                                            s_C__Giants_Source_Utils_lzss_c_005815c8,0x282);
  }
  if (DAT_005ee730 < 0x8001) {
    param_1 = (byte *)DAT_005ee730;
    if (DAT_005ee730 == 0) goto LAB_0053b571;
  }
  else {
    param_1 = (byte *)0x8000;
  }
  ReadFile(DAT_005ee74c,DAT_005ee724,(DWORD)param_1,(LPDWORD)&param_1,(LPOVERLAPPED)0x0);
LAB_0053b571:
  DAT_005ee728 = DAT_005ee724;
  DAT_005ee72c = DAT_005ee724 + ((int)param_1 - 1);
  uVar5 = DAT_005ee730 - (int)param_1;
  param_1 = param_3;
  puVar9 = &DAT_005ed708;
  for (iVar4 = 0x3fb; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar9 = 0x20202020;
    puVar9 = puVar9 + 1;
  }
  DAT_005ee730 = uVar5;
  *(undefined2 *)puVar9 = 0x2020;
  param_2 = 0xfee;
  param_3 = (byte *)0x0;
  lpBuffer = DAT_005ee728;
  pbVar8 = DAT_005ee728;
LAB_0053b5b3:
  do {
    uVar10 = param_2;
    param_3 = (byte *)((uint)param_3 >> 1);
    if (((uint)param_3 & 0x100) == 0) {
      pbVar7 = pbVar8;
      if (DAT_005ee72c < pbVar8) {
        if (lpBuffer == (byte *)0x0) {
          lpBuffer = (byte *)mem_alloc_tagged(0x20,0x8000,s_lzssbuff_005815b4,
                                              s_C__Giants_Source_Utils_lzss_c_005815c8,0x282);
          uVar5 = DAT_005ee730;
          DAT_005ee724 = lpBuffer;
        }
        if (uVar5 < 0x8001) {
          uVar6 = 0;
          local_8 = uVar5;
          if (uVar5 != 0) goto LAB_0053b61b;
        }
        else {
          local_8 = 0x8000;
LAB_0053b61b:
          ReadFile(DAT_005ee74c,lpBuffer,local_8,&local_8,(LPOVERLAPPED)0x0);
          lpBuffer = DAT_005ee724;
          uVar6 = DAT_005ee730;
        }
        DAT_005ee72c = lpBuffer + (local_8 - 1);
        uVar5 = uVar6 - local_8;
        pbVar7 = lpBuffer;
        DAT_005ee730 = uVar5;
        if (DAT_005ee72c < lpBuffer) {
          DAT_005ee728 = lpBuffer;
          return;
        }
      }
      pbVar8 = pbVar7 + 1;
      if (*pbVar7 == 0xffffffff) {
        DAT_005ee728 = pbVar8;
        return;
      }
      param_3 = (byte *)(uint)CONCAT11(0xff,*pbVar7);
      DAT_005ee728 = pbVar8;
    }
    if (((uint)param_3 & 1) == 0) {
      if (DAT_005ee72c < pbVar8) {
        if (lpBuffer == (byte *)0x0) {
          lpBuffer = (byte *)mem_alloc_tagged(0x20,0x8000,s_lzssbuff_005815b4,
                                              s_C__Giants_Source_Utils_lzss_c_005815c8,0x282);
          uVar5 = DAT_005ee730;
          DAT_005ee724 = lpBuffer;
        }
        if (uVar5 < 0x8001) {
          uVar10 = 0;
          local_10 = uVar5;
          if (uVar5 != 0) goto LAB_0053b7a5;
        }
        else {
          local_10 = 0x8000;
LAB_0053b7a5:
          ReadFile(DAT_005ee74c,lpBuffer,local_10,&local_10,(LPOVERLAPPED)0x0);
          lpBuffer = DAT_005ee724;
          uVar10 = DAT_005ee730;
        }
        DAT_005ee72c = lpBuffer + (local_10 - 1);
        uVar5 = uVar10 - local_10;
        pbVar8 = lpBuffer;
        DAT_005ee730 = uVar5;
        if (DAT_005ee72c < lpBuffer) {
          DAT_005ee728 = lpBuffer;
          return;
        }
      }
      bVar1 = *pbVar8;
      DAT_005ee728 = pbVar8 + 1;
      if (bVar1 == 0xffffffff) {
        return;
      }
      if (DAT_005ee72c < DAT_005ee728) {
        if (lpBuffer == (byte *)0x0) {
          lpBuffer = (byte *)mem_alloc_tagged(0x20,0x8000,s_lzssbuff_005815b4,
                                              s_C__Giants_Source_Utils_lzss_c_005815c8,0x282);
          uVar5 = DAT_005ee730;
          DAT_005ee724 = lpBuffer;
        }
        if (uVar5 < 0x8001) {
          uVar10 = 0;
          local_14 = uVar5;
          if (uVar5 != 0) goto LAB_0053b858;
        }
        else {
          local_14 = 0x8000;
LAB_0053b858:
          ReadFile(DAT_005ee74c,lpBuffer,local_14,&local_14,(LPOVERLAPPED)0x0);
          lpBuffer = DAT_005ee724;
          uVar10 = DAT_005ee730;
        }
        DAT_005ee72c = lpBuffer + (local_14 - 1);
        DAT_005ee730 = uVar10 - local_14;
        DAT_005ee728 = lpBuffer;
        if (DAT_005ee72c < lpBuffer) {
          return;
        }
      }
      bVar2 = *DAT_005ee728;
      DAT_005ee728 = DAT_005ee728 + 1;
      if (bVar2 == 0xffffffff) {
        return;
      }
      local_1c = (bVar2 & 0xf0) << 4 | (uint)bVar1;
      local_20 = (bVar2 & 0xf) + 2;
      iVar4 = local_20;
      uVar10 = local_1c;
      do {
        bVar1 = *(byte *)((int)&DAT_005ed708 + (uVar10 & 0xfff));
        *param_1 = bVar1;
        param_1 = param_1 + 1;
        *(byte *)((int)&DAT_005ed708 + param_2) = bVar1;
        uVar10 = (uVar10 & 0xfff) + 1;
        param_2 = param_2 + 1 & 0xfff;
        bVar3 = 0 < iVar4;
        lpBuffer = DAT_005ee724;
        uVar5 = DAT_005ee730;
        pbVar8 = DAT_005ee728;
        iVar4 = iVar4 + -1;
      } while (bVar3);
      goto LAB_0053b5b3;
    }
    if (DAT_005ee72c < pbVar8) {
      if (lpBuffer == (byte *)0x0) {
        lpBuffer = (byte *)mem_alloc_tagged(0x20,0x8000,s_lzssbuff_005815b4,
                                            s_C__Giants_Source_Utils_lzss_c_005815c8,0x282);
        uVar5 = DAT_005ee730;
        DAT_005ee724 = lpBuffer;
      }
      if (uVar5 < 0x8001) {
        uVar6 = 0;
        local_c = uVar5;
        if (uVar5 != 0) goto LAB_0053b6dd;
      }
      else {
        local_c = 0x8000;
LAB_0053b6dd:
        ReadFile(DAT_005ee74c,lpBuffer,local_c,&local_c,(LPOVERLAPPED)0x0);
        lpBuffer = DAT_005ee724;
        uVar6 = DAT_005ee730;
      }
      DAT_005ee72c = lpBuffer + (local_c - 1);
      uVar5 = uVar6 - local_c;
      pbVar8 = lpBuffer;
      DAT_005ee730 = uVar5;
      if (DAT_005ee72c < lpBuffer) {
        DAT_005ee728 = lpBuffer;
        return;
      }
    }
    bVar1 = *pbVar8;
    pbVar8 = pbVar8 + 1;
    if (bVar1 == 0xffffffff) {
      DAT_005ee728 = pbVar8;
      return;
    }
    DAT_005ee728 = pbVar8;
    *(byte *)((int)&DAT_005ed708 + uVar10) = bVar1;
    *param_1 = bVar1;
    param_1 = param_1 + 1;
    param_2 = uVar10 + 1 & 0xfff;
  } while( true );
}

