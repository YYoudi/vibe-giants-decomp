/* Giants 1.449 — module main/readgbls
 * 2 functions (2 named) — decompiled, names from PS2 symbols
 * Original source: C:\Giants\source\main/readgbls.c(pp) (assert-string evidence)
 */

/* ===== reread_globals_bin @ 0x004AE310 ===== */
void reread_globals_bin(void)



{

  int iVar1;

  int local_c;

  int local_8;

  int local_4;

  

  iVar1 = main_005380e0(s_GData_gbn_0055ff24);

  if (iVar1 == 0) {

    error_screen_show(s_Failed_to_open_GData_gbn_0055ff08);

    return;

  }

  FUN_005178d0(iVar1,&local_4,4);

  if (local_4 != 0x7a330000) {

    error_screen_show(s_Bad_version_for_GData_gbn_0055feec);

    ANM_BinderDestroy_2(iVar1);

    return;

  }

  FUN_005178d0(iVar1,&local_c,4);

  FUN_005178d0(iVar1,&local_8,4);

  if (DAT_00632ed8 == 0) {

LAB_004ae3ae:

    DAT_00632ed8 = FUN_0053a700(0x27,local_c * 4,s_gdata_0055fec0,

                                s_C__Giants_source_main_readgbls_c_0055fec8,0x2b);

    DAT_00632ed4 = local_c;

  }

  else if (DAT_00632ed4 < local_c) {

    mem_free_tagged(DAT_00632ed8,s_C__Giants_source_main_readgbls_c_0055fec8,0x2a);

    goto LAB_004ae3ae;

  }

  if (DAT_00632ee0 != 0) {

    if (local_8 <= DAT_00632edc) goto LAB_004ae43b;

    mem_free_tagged(DAT_00632ee0,s_C__Giants_source_main_readgbls_c_0055fec8,0x31);

  }

  DAT_00632ee0 = FUN_0053a700(0x27,local_8 * 4,s_gadata_0055feb8,

                              s_C__Giants_source_main_readgbls_c_0055fec8,0x32);

  DAT_00632edc = local_8;

LAB_004ae43b:

  FUN_005178d0(iVar1,DAT_00632ed8,local_c * 4);

  FUN_005178d0(iVar1,DAT_00632ee0,local_8 * 4);

  ANM_BinderDestroy_2(iVar1);

  DAT_00632ed0 = DAT_00632ed0 + 1;

  return;

}

/* ===== main_readgbls_004ae480 @ 0x004AE480 ===== */
void main_readgbls_004ae480(void)



{

  mem_free_tagged(DAT_00632ee0,s_C__Giants_source_main_readgbls_c_0055fec8,0x44);

  mem_free_tagged(DAT_00632ed8,s_C__Giants_source_main_readgbls_c_0055fec8,0x45);

  DAT_00632ed8 = 0;

  DAT_00632ee0 = 0;

  return;

}

