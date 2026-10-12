/* Giants 1.449 — module Main/dedicated
 * 2 functions (2 named) — decompiled, names from PS2 symbols
 * Original source: C:\Giants\source\Main/dedicated.c(pp) (assert-string evidence)
 */

/* ===== main_dedicated_00426460 @ 0x00426460 ===== */
undefined4 main_dedicated_00426460(void)



{

  int iVar1;

  int local_8;

  int local_4;

  

  iVar1 = FUN_005380e0(&DAT_00633090);

  if (iVar1 == 0) {

    return 0;

  }

  FUN_005178d0(iVar1,&local_4,4);

  if (local_4 != 2) {

    FUN_0051e680(s_Bad_version_for_dedicated_bin_00556424);

    ANM_BinderDestroy_2(iVar1);

    return 0;

  }

  FUN_005178d0(iVar1,&local_8,4);

  DAT_0058c64c = FUN_0053a700(0x27,local_8 + -8,s_DedInfo_005563f8,

                              s_C__Giants_source_Main_dedicated__00556400,0x143);

  DAT_0058c650 = DAT_0058c64c;

  FUN_005178d0(iVar1,DAT_0058c64c,local_8 + -8);

  ANM_BinderDestroy_2(iVar1);

  return 1;

}

/* ===== main_dedicated_00426510 @ 0x00426510 ===== */
void main_dedicated_00426510(void)



{

  if (DAT_0058c64c != 0) {

    mem_free_tagged(DAT_0058c64c,s_C__Giants_source_Main_dedicated__00556400,0x14e);

  }

  DAT_0058c64c = 0;

  return;

}

