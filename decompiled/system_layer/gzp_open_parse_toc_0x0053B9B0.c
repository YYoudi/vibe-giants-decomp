// GiantsRE system layer - gzp_open_parse_toc
// VA 0x0053B9B0 (ghidra name was gzp_open_parse_toc)
// provenance: runtime anchors in scripts/re_db.json + PS2 symbols


undefined4 gzp_open_parse_toc(LPCSTR param_1)

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
  
  if (DAT_005ee74c != (HANDLE)0x0) {
    return 0;
  }
  DAT_005ee74c = CreateFileA(param_1,0x80000000,1,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
  if (DAT_005ee74c == (HANDLE)0xffffffff) {
    DAT_005ee74c = (HANDLE)0x0;
    return 0;
  }
  SetFilePointer(DAT_005ee74c,0,(PLONG)0x0,0);
  pcVar3 = ReadFile_exref;
  ReadFile(DAT_005ee74c,&DAT_005e52e8,8,(LPDWORD)&param_1,(LPOVERLAPPED)0x0);
  if (DAT_005e52e8 != 0x6608f101) {
    CloseHandle(DAT_005ee74c);
    DAT_005ee74c = (HANDLE)0x0;
    return 0;
  }
  SetFilePointer(DAT_005ee74c,DAT_005e52ec,(PLONG)0x0,0);
  ReadFile(DAT_005ee74c,&DAT_005ee71c,8,(LPDWORD)&param_1,(LPOVERLAPPED)0x0);
  local_1c = 0;
  if (0 < DAT_005ee720) {
    do {
      (*pcVar3)(DAT_005ee74c,local_18,0x12,&param_1,0);
      nNumberOfBytesToRead = local_7 & 0xff;
      puVar1 = (undefined4 *)
               mem_alloc_tagged(0x20,nNumberOfBytesToRead + 0x17,s_lzss_de_005815c0,
                                s_C__Giants_Source_Utils_lzss_c_005815c8,0x3a6);
      puVar4 = local_18;
      puVar5 = puVar1;
      for (iVar2 = 5; puVar5 = puVar5 + 1, iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + 1;
      }
      ReadFile(DAT_005ee74c,(LPVOID)((int)puVar1 + 0x16),nNumberOfBytesToRead,(LPDWORD)&param_1,
               (LPOVERLAPPED)0x0);
      puVar5 = &DAT_005e52e4;
      for (puVar4 = DAT_005e52e4; puVar4 != (undefined4 *)0x0; puVar4 = (undefined4 *)*puVar4) {
        puVar5 = puVar4;
      }
      *puVar5 = puVar1;
      *puVar1 = 0;
      local_1c = local_1c + 1;
      pcVar3 = ReadFile_exref;
    } while (local_1c < DAT_005ee720);
  }
  DAT_005e12d0 = 0;
  return 1;
}


