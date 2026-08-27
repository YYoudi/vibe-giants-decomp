// GiantsRE system layer - func_0053AE80
// VA 0x0053AE80
// via GhidraMCP headless bulk decompile (project with PS2 renames)


bool cd_check(void)

{
  char *pcVar1;
  char cVar2;
  BOOL BVar3;
  int iVar4;
  undefined1 *puVar5;
  CHAR *lpVolumeNameBuffer;
  DWORD nVolumeNameSize;
  DWORD *lpVolumeSerialNumber;
  DWORD *lpMaximumComponentLength;
  DWORD *lpFileSystemFlags;
  CHAR *lpFileSystemNameBuffer;
  DWORD nFileSystemNameSize;
  DWORD local_31c;
  DWORD local_318;
  DWORD local_314;
  DWORD local_310;
  DWORD local_30c;
  DWORD local_308;
  DWORD local_304;
  char local_300 [256];
  CHAR local_200 [256];
  CHAR local_100 [256];
  
  if (DAT_00631890 != 0) {
    return true;
  }
  if (DAT_005e11a0 == '\0') {
    return false;
  }
  puVar5 = &DAT_005e11a0;
  cVar2 = DAT_005e11a0;
  while ((cVar2 != '\\' && (cVar2 != '\0'))) {
    pcVar1 = puVar5 + 1;
    puVar5 = puVar5 + 1;
    cVar2 = *pcVar1;
  }
  _strncpy(local_300,&DAT_005e11a0,(size_t)(puVar5 + -0x5e119f));
  lpFileSystemNameBuffer = local_100;
  lpFileSystemFlags = &local_304;
  lpMaximumComponentLength = &local_308;
  nFileSystemNameSize = 0x100;
  lpVolumeSerialNumber = &local_30c;
  lpVolumeNameBuffer = local_200;
  nVolumeNameSize = 0x100;
  (&stack0xffa1eb61)[(int)puVar5] = 0;
  BVar3 = GetVolumeInformationA
                    (local_300,lpVolumeNameBuffer,nVolumeNameSize,lpVolumeSerialNumber,
                     lpMaximumComponentLength,lpFileSystemFlags,lpFileSystemNameBuffer,
                     nFileSystemNameSize);
  if (BVar3 == 0) {
    return false;
  }
  BVar3 = GetDiskFreeSpaceA(local_300,&local_310,&local_314,&local_31c,&local_318);
  if (BVar3 == 0) {
    return false;
  }
  iVar4 = FUN_00547250();
  if (iVar4 == 0) {
    iVar4 = FUN_00547250();
    if (iVar4 == 0) {
      return local_31c == 0;
    }
    return false;
  }
  return false;
}

