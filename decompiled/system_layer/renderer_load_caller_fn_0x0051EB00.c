// GiantsRE system layer - renderer_load_caller_fn
// VA 0x0051EB00 (ghidra name was FUN_0051eaa0)
// provenance: runtime anchors in scripts/re_db.json + PS2 symbols


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0051eaa0(void)

{
  int iVar1;
  int iVar2;
  float fVar3;
  
  iVar2 = DAT_005dc018;
  while (iVar2 != 0) {
    fVar3 = *(float *)(iVar2 + 8) - DAT_00630f20;
    *(float *)(iVar2 + 8) = fVar3;
    if (fVar3 < _DAT_005522b0 == (fVar3 == _DAT_005522b0)) {
      iVar2 = *(int *)(iVar2 + 0x1c);
    }
    else {
      iVar1 = *(int *)(iVar2 + 0x1c);
      if (*(int *)(iVar2 + 0x20) != 0) {
        *(int *)(*(int *)(iVar2 + 0x20) + 0x1c) = iVar1;
      }
      if (iVar1 != 0) {
        *(undefined4 *)(iVar1 + 0x20) = *(undefined4 *)(iVar2 + 0x20);
      }
      if (iVar2 == DAT_005dc018) {
        DAT_005dc018 = iVar1;
      }
      mem_free_tagged(iVar2,s_C__Giants_Source_win95_frate_c_0057ebc4,0x104);
      iVar2 = iVar1;
    }
  }
  return;
}


