// GiantsRE system layer - func_0051EBEF
// VA 0x0051EBEF
// via GhidraMCP headless bulk decompile (project with PS2 renames)


undefined4 renderer_load_return_site(char *param_1,undefined4 param_2)

{
  HMODULE hModule;
  undefined4 local_20c;
  undefined4 local_208;
  undefined4 local_204;
  CHAR local_200 [512];
  
  if ((param_1 != (char *)0x0) && (*param_1 != '\0')) {
    FUN_00544b47(local_200,s__s_gg__s_0057ec40,param_1,param_2);
    hModule = GetModuleHandleA(local_200);
    if (hModule != (HMODULE)0x0) goto LAB_0051ec00;
    hModule = LoadLibraryA(local_200);
    if (hModule != (HMODULE)0x0) goto LAB_0051ec00;
  }
  FUN_00544b47(local_200,s_gg__s_0057ec38,param_2);
  hModule = GetModuleHandleA(local_200);
  if (hModule == (HMODULE)0x0) {
    hModule = LoadLibraryA(local_200);
    if (hModule == (HMODULE)0x0) {
      return 0;
    }
  }
LAB_0051ec00:
  DAT_005dc01c = GetProcAddress(hModule,s_GDVSysCreate_0057ec28);
  if (DAT_005dc01c == (FARPROC)0x0) {
    FUN_00523ad0(s_Failed_to_load_GDVSysCreate_0057ec0c);
    return 0;
  }
  DAT_005dc020 = GetProcAddress(hModule,s_UpCallsLoad_0057ec00);
  if (DAT_005dc020 == (FARPROC)0x0) {
    FUN_00523ad0(s_Failed_to_load_UpCallsLoad_0057ebe4);
    return 0;
  }
  FUN_00521a60(&local_208,&local_20c,&local_204);
  (*DAT_005dc020)(local_208,local_20c,local_204);
  return 1;
}

