// GiantsRE system layer - gzp_close_free
// VA 0x0053BB50 (ghidra name was gzp_close_free)
// provenance: runtime anchors in scripts/re_db.json + PS2 symbols


undefined4 __fastcall gzp_close_free(DWORD param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  DWORD local_4;
  
  if (DAT_005ee74c == (HANDLE)0x0) {
    return 0;
  }
  local_4 = param_1;
  if (DAT_005e12d0 != 0) {
    SetFilePointer(DAT_005ee74c,0,(PLONG)0x0,0);
    WriteFile(DAT_005ee74c,&DAT_005e52e8,8,&local_4,(LPOVERLAPPED)0x0);
    SetFilePointer(DAT_005ee74c,DAT_005e52ec,(PLONG)0x0,0);
    WriteFile(DAT_005ee74c,&DAT_005ee71c,8,&local_4,(LPOVERLAPPED)0x0);
    for (puVar1 = DAT_005e52e4; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {
      WriteFile(DAT_005ee74c,puVar1 + 1,*(byte *)((int)puVar1 + 0x15) + 0x12,&local_4,
                (LPOVERLAPPED)0x0);
    }
  }
  CloseHandle(DAT_005ee74c);
  DAT_005ee74c = (HANDLE)0x0;
  DAT_005e12d0 = 0;
  if (DAT_005ee724 != 0) {
    mem_free_tagged(DAT_005ee724,s_C__Giants_Source_Utils_lzss_c_005815c8,0x3ce);
    DAT_005ee724 = 0;
  }
  puVar1 = DAT_005e52e4;
  uVar3 = 0;
  if (DAT_005ee734 != 0) {
    mem_free_tagged(DAT_005ee734,s_C__Giants_Source_Utils_lzss_c_005815c8,0x3d3);
    DAT_005ee734 = 0;
    puVar1 = DAT_005e52e4;
    uVar3 = DAT_005ee734;
  }
  while (DAT_005ee734 = uVar3, puVar1 != (undefined4 *)0x0) {
    puVar2 = (undefined4 *)*puVar1;
    mem_free_tagged(puVar1,s_C__Giants_Source_Utils_lzss_c_005815c8,0x3dc);
    puVar1 = puVar2;
    uVar3 = DAT_005ee734;
  }
  DAT_005e52e4 = (undefined4 *)0x0;
  return 1;
}


