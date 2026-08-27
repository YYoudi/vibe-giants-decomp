// GiantsRE system layer - mem_alloc_tagged
// VA 0x0053C810 (ghidra name was mem_alloc_tagged)
// provenance: runtime anchors in scripts/re_db.json + PS2 symbols


int mem_alloc_tagged(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,
                    undefined4 param_5)

{
  int iVar1;
  undefined1 local_c8 [200];
  
  iVar1 = FUN_0053c380(param_1,param_2,param_4,param_5);
  if ((iVar1 == 0) && (param_2 != 0)) {
    FUN_00544b47(local_c8,s_Memory_Fail_on__s___ld_bytes___s_005819dc,param_3,param_2,param_4,
                 param_5);
    FUN_00429100(local_c8);
    FUN_00523aa0(local_c8);
  }
  return iVar1;
}


