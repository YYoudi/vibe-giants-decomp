// GiantsRE system layer - func_0043005C
// VA 0x0043005C
// via GhidraMCP headless bulk decompile (project with PS2 renames)


int wait_wrapper_site(int param_1)

{
  int iVar1;
  float *pfVar2;
  
  iVar1 = 0;
  pfVar2 = (float *)(*(int *)(param_1 + 8) + 0x428);
  do {
    if (*pfVar2 == -1.0) {
      return iVar1;
    }
    iVar1 = iVar1 + 1;
    pfVar2 = pfVar2 + 1;
  } while (iVar1 < 10);
  return 0;
}

