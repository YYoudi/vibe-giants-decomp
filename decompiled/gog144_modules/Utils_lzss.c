/* Giants 1.449 — module Utils/lzss
 * 3 functions (0 named) — decompiled, names from PS2 symbols
 * Original source: C:\Giants\source\Utils/lzss.c(pp) (assert-string evidence)
 */

/* ===== FUN_005395f0 @ 0x005395F0 ===== */
void FUN_005395f0(byte *param_1,uint param_2,byte *param_3)



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

  

  SetFilePointer(DAT_005f010c,(LONG)param_1,(PLONG)0x0,0);

  ReadFile(DAT_005f010c,local_30,0x10,&local_18,(LPOVERLAPPED)0x0);

  if (local_24 == 2) {

    ReadFile(DAT_005f010c,param_3,param_2,&local_18,(LPOVERLAPPED)0x0);

    return;

  }

  if (local_24 != 1) {

    return;

  }

  DAT_005f00f0 = local_30[0] - 0x10;

  if (DAT_005f00e4 == (byte *)0x0) {

    DAT_005f00e4 = (byte *)FUN_0053a700(0x20,0x8000,s_lzssbuff_005804a0,

                                        s_C__Giants_source_Utils_lzss_c_005804b4,0x282);

  }

  if (DAT_005f00f0 < 0x8001) {

    param_1 = (byte *)DAT_005f00f0;

    if (DAT_005f00f0 == 0) goto LAB_005396d1;

  }

  else {

    param_1 = (byte *)0x8000;

  }

  ReadFile(DAT_005f010c,DAT_005f00e4,(DWORD)param_1,(LPDWORD)&param_1,(LPOVERLAPPED)0x0);

LAB_005396d1:

  DAT_005f00e8 = DAT_005f00e4;

  DAT_005f00ec = DAT_005f00e4 + ((int)param_1 - 1);

  DAT_005f00f0 = DAT_005f00f0 - (int)param_1;

  param_1 = param_3;

  puVar9 = &DAT_005ef0c8;

  for (iVar4 = 0x3fb; iVar4 != 0; iVar4 = iVar4 + -1) {

    *puVar9 = 0x20202020;

    puVar9 = puVar9 + 1;

  }

  *(undefined2 *)puVar9 = 0x2020;

  param_2 = 0xfee;

  param_3 = (byte *)0x0;

  lpBuffer = DAT_005f00e8;

  uVar5 = DAT_005f00f0;

  pbVar8 = DAT_005f00e8;

LAB_00539713:

  do {

    uVar10 = param_2;

    param_3 = (byte *)((uint)param_3 >> 1);

    if (((uint)param_3 & 0x100) == 0) {

      pbVar7 = pbVar8;

      if (DAT_005f00ec < pbVar8) {

        if (lpBuffer == (byte *)0x0) {

          lpBuffer = (byte *)FUN_0053a700(0x20,0x8000,s_lzssbuff_005804a0,

                                          s_C__Giants_source_Utils_lzss_c_005804b4,0x282);

          uVar5 = DAT_005f00f0;

          DAT_005f00e4 = lpBuffer;

        }

        if (uVar5 < 0x8001) {

          uVar6 = 0;

          local_8 = uVar5;

          if (uVar5 != 0) goto LAB_0053977b;

        }

        else {

          local_8 = 0x8000;

LAB_0053977b:

          ReadFile(DAT_005f010c,lpBuffer,local_8,&local_8,(LPOVERLAPPED)0x0);

          lpBuffer = DAT_005f00e4;

          uVar6 = DAT_005f00f0;

        }

        DAT_005f00ec = lpBuffer + (local_8 - 1);

        uVar5 = uVar6 - local_8;

        pbVar7 = lpBuffer;

        DAT_005f00f0 = uVar5;

        if (DAT_005f00ec < lpBuffer) {

          DAT_005f00e8 = lpBuffer;

          return;

        }

      }

      pbVar8 = pbVar7 + 1;

      if (*pbVar7 == 0xffffffff) {

        DAT_005f00e8 = pbVar8;

        return;

      }

      param_3 = (byte *)(*pbVar7 | 0xff00);

      DAT_005f00e8 = pbVar8;

    }

    if (((uint)param_3 & 1) == 0) {

      if (DAT_005f00ec < pbVar8) {

        if (lpBuffer == (byte *)0x0) {

          lpBuffer = (byte *)FUN_0053a700(0x20,0x8000,s_lzssbuff_005804a0,

                                          s_C__Giants_source_Utils_lzss_c_005804b4,0x282);

          uVar5 = DAT_005f00f0;

          DAT_005f00e4 = lpBuffer;

        }

        if (uVar5 < 0x8001) {

          uVar10 = 0;

          local_10 = uVar5;

          if (uVar5 != 0) goto LAB_00539908;

        }

        else {

          local_10 = 0x8000;

LAB_00539908:

          ReadFile(DAT_005f010c,lpBuffer,local_10,&local_10,(LPOVERLAPPED)0x0);

          lpBuffer = DAT_005f00e4;

          uVar10 = DAT_005f00f0;

        }

        DAT_005f00ec = lpBuffer + (local_10 - 1);

        uVar5 = uVar10 - local_10;

        pbVar8 = lpBuffer;

        DAT_005f00f0 = uVar5;

        if (DAT_005f00ec < lpBuffer) {

          DAT_005f00e8 = lpBuffer;

          return;

        }

      }

      bVar1 = *pbVar8;

      DAT_005f00e8 = pbVar8 + 1;

      if (bVar1 == 0xffffffff) {

        return;

      }

      if (DAT_005f00ec < DAT_005f00e8) {

        if (lpBuffer == (byte *)0x0) {

          lpBuffer = (byte *)FUN_0053a700(0x20,0x8000,s_lzssbuff_005804a0,

                                          s_C__Giants_source_Utils_lzss_c_005804b4,0x282);

          uVar5 = DAT_005f00f0;

          DAT_005f00e4 = lpBuffer;

        }

        if (uVar5 < 0x8001) {

          uVar10 = 0;

          local_14 = uVar5;

          if (uVar5 != 0) goto LAB_005399bb;

        }

        else {

          local_14 = 0x8000;

LAB_005399bb:

          ReadFile(DAT_005f010c,lpBuffer,local_14,&local_14,(LPOVERLAPPED)0x0);

          lpBuffer = DAT_005f00e4;

          uVar10 = DAT_005f00f0;

        }

        DAT_005f00ec = lpBuffer + (local_14 - 1);

        DAT_005f00f0 = uVar10 - local_14;

        DAT_005f00e8 = lpBuffer;

        if (DAT_005f00ec < lpBuffer) {

          return;

        }

      }

      bVar2 = *DAT_005f00e8;

      DAT_005f00e8 = DAT_005f00e8 + 1;

      if (bVar2 == 0xffffffff) {

        return;

      }

      local_1c = (bVar2 & 0xf0) << 4 | (uint)bVar1;

      local_20 = (bVar2 & 0xf) + 2;

      iVar4 = local_20;

      uVar10 = local_1c;

      do {

        bVar1 = *(byte *)((int)&DAT_005ef0c8 + (uVar10 & 0xfff));

        *param_1 = bVar1;

        param_1 = param_1 + 1;

        *(byte *)((int)&DAT_005ef0c8 + param_2) = bVar1;

        uVar10 = (uVar10 & 0xfff) + 1;

        param_2 = param_2 + 1 & 0xfff;

        bVar3 = 0 < iVar4;

        lpBuffer = DAT_005f00e4;

        uVar5 = DAT_005f00f0;

        pbVar8 = DAT_005f00e8;

        iVar4 = iVar4 + -1;

      } while (bVar3);

      goto LAB_00539713;

    }

    if (DAT_005f00ec < pbVar8) {

      if (lpBuffer == (byte *)0x0) {

        lpBuffer = (byte *)FUN_0053a700(0x20,0x8000,s_lzssbuff_005804a0,

                                        s_C__Giants_source_Utils_lzss_c_005804b4,0x282);

        uVar5 = DAT_005f00f0;

        DAT_005f00e4 = lpBuffer;

      }

      if (uVar5 < 0x8001) {

        uVar6 = 0;

        local_c = uVar5;

        if (uVar5 != 0) goto LAB_0053983f;

      }

      else {

        local_c = 0x8000;

LAB_0053983f:

        ReadFile(DAT_005f010c,lpBuffer,local_c,&local_c,(LPOVERLAPPED)0x0);

        lpBuffer = DAT_005f00e4;

        uVar6 = DAT_005f00f0;

      }

      DAT_005f00ec = lpBuffer + (local_c - 1);

      uVar5 = uVar6 - local_c;

      pbVar8 = lpBuffer;

      DAT_005f00f0 = uVar5;

      if (DAT_005f00ec < lpBuffer) {

        DAT_005f00e8 = lpBuffer;

        return;

      }

    }

    bVar1 = *pbVar8;

    pbVar8 = pbVar8 + 1;

    if (bVar1 == 0xffffffff) {

      DAT_005f00e8 = pbVar8;

      return;

    }

    DAT_005f00e8 = pbVar8;

    *param_1 = bVar1;

    *(byte *)((int)&DAT_005ef0c8 + uVar10) = bVar1;

    param_2 = uVar10 + 1 & 0xfff;

    param_1 = param_1 + 1;

  } while( true );

}

/* ===== FUN_00539b10 @ 0x00539B10 ===== */
undefined4 FUN_00539b10(LPCSTR param_1)



{

  undefined4 *puVar1;

  int iVar2;

  uint nNumberOfBytesToRead;

  code *pcVar3;

  undefined4 *puVar4;

  undefined4 *puVar5;

  int local_1c;

  undefined4 local_18 [4];

  uint local_7;

  

  if (DAT_005f010c != (HANDLE)0x0) {

    return 0;

  }

  DAT_005f010c = CreateFileA(param_1,0x80000000,1,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);

  if (DAT_005f010c == (HANDLE)0xffffffff) {

    DAT_005f010c = (HANDLE)0x0;

    return 0;

  }

  SetFilePointer(DAT_005f010c,0,(PLONG)0x0,0);

  pcVar3 = ReadFile_exref;

  ReadFile(DAT_005f010c,&DAT_005e6ca8,8,(LPDWORD)&param_1,(LPOVERLAPPED)0x0);

  if (DAT_005e6ca8 != 0x6608f101) {

    CloseHandle(DAT_005f010c);

    DAT_005f010c = (HANDLE)0x0;

    return 0;

  }

  SetFilePointer(DAT_005f010c,DAT_005e6cac,(PLONG)0x0,0);

  ReadFile(DAT_005f010c,&DAT_005f00dc,8,(LPDWORD)&param_1,(LPOVERLAPPED)0x0);

  local_1c = 0;

  if (0 < DAT_005f00e0) {

    do {

      (*pcVar3)(DAT_005f010c,local_18,0x12,&param_1,0);

      nNumberOfBytesToRead = local_7 & 0xff;

      puVar1 = (undefined4 *)

               FUN_0053a700(0x20,nNumberOfBytesToRead + 0x17,s_lzss_de_005804ac,

                            s_C__Giants_source_Utils_lzss_c_005804b4,0x3a6);

      puVar4 = local_18;

      puVar5 = puVar1;

      for (iVar2 = 5; puVar5 = puVar5 + 1, iVar2 != 0; iVar2 = iVar2 + -1) {

        *puVar5 = *puVar4;

        puVar4 = puVar4 + 1;

      }

      ReadFile(DAT_005f010c,(LPVOID)((int)puVar1 + 0x16),nNumberOfBytesToRead,(LPDWORD)&param_1,

               (LPOVERLAPPED)0x0);

      puVar5 = &DAT_005e6ca4;

      for (puVar4 = DAT_005e6ca4; puVar4 != (undefined4 *)0x0; puVar4 = (undefined4 *)*puVar4) {

        puVar5 = puVar4;

      }

      *puVar5 = puVar1;

      *puVar1 = 0;

      local_1c = local_1c + 1;

      pcVar3 = ReadFile_exref;

    } while (local_1c < DAT_005f00e0);

  }

  DAT_005e2c90 = 0;

  return 1;

}

/* ===== FUN_00539cb0 @ 0x00539CB0 ===== */
undefined4 FUN_00539cb0(void)



{

  undefined4 *puVar1;

  undefined4 *puVar2;

  undefined4 uVar3;

  DWORD local_4;

  

  if (DAT_005f010c == (HANDLE)0x0) {

    return 0;

  }

  if (DAT_005e2c90 != 0) {

    SetFilePointer(DAT_005f010c,0,(PLONG)0x0,0);

    WriteFile(DAT_005f010c,&DAT_005e6ca8,8,&local_4,(LPOVERLAPPED)0x0);

    SetFilePointer(DAT_005f010c,DAT_005e6cac,(PLONG)0x0,0);

    WriteFile(DAT_005f010c,&DAT_005f00dc,8,&local_4,(LPOVERLAPPED)0x0);

    for (puVar1 = DAT_005e6ca4; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {

      WriteFile(DAT_005f010c,puVar1 + 1,*(byte *)((int)puVar1 + 0x15) + 0x12,&local_4,

                (LPOVERLAPPED)0x0);

    }

  }

  CloseHandle(DAT_005f010c);

  DAT_005f010c = (HANDLE)0x0;

  DAT_005e2c90 = 0;

  if (DAT_005f00e4 != 0) {

    mem_free_tagged(DAT_005f00e4,s_C__Giants_source_Utils_lzss_c_005804b4,0x3ce);

    DAT_005f00e4 = 0;

  }

  puVar1 = DAT_005e6ca4;

  uVar3 = 0;

  if (DAT_005f00f4 != 0) {

    mem_free_tagged(DAT_005f00f4,s_C__Giants_source_Utils_lzss_c_005804b4,0x3d3);

    DAT_005f00f4 = 0;

    puVar1 = DAT_005e6ca4;

    uVar3 = DAT_005f00f4;

  }

  while (DAT_005f00f4 = uVar3, puVar1 != (undefined4 *)0x0) {

    puVar2 = (undefined4 *)*puVar1;

    mem_free_tagged(puVar1,s_C__Giants_source_Utils_lzss_c_005804b4,0x3dc);

    puVar1 = puVar2;

    uVar3 = DAT_005f00f4;

  }

  DAT_005e6ca4 = (undefined4 *)0x0;

  return 1;

}

