/* Giants 1.449 — module main/linkage
 * 3 functions (3 named) — decompiled, names from PS2 symbols
 * Original source: C:\Giants\source\main/linkage.c(pp) (assert-string evidence)
 */

/* ===== main_linkage_00470250 @ 0x00470250 ===== */
void main_linkage_00470250(int *param_1,int *param_2)



{

  undefined4 *puVar1;

  int *piVar2;

  int *piVar3;

  int iVar4;

  

  piVar3 = DAT_0059da7c;

  if (DAT_0059da7c == (int *)0x0) {

    puVar1 = (undefined4 *)

             FUN_0053a700(0xf,0xc84,s_links_0055b558,s_C__Giants_source_main_linkage_c_0055b560,0x1b

                         );

    *puVar1 = DAT_0059da80;

    DAT_0059da7c = puVar1 + 1;

    iVar4 = 0xc6;

    piVar3 = DAT_0059da7c;

    DAT_0059da80 = puVar1;

    do {

      iVar4 = iVar4 + -1;

      *piVar3 = (int)(piVar3 + 4);

      piVar3 = piVar3 + 4;

    } while (iVar4 != 0);

    puVar1[0x319] = 0;

    piVar3 = DAT_0059da7c;

  }

  DAT_0059da7c = (int *)*piVar3;

  piVar3[1] = (int)param_1;

  *piVar3 = *param_1;

  piVar3[2] = (int)param_1;

  piVar3[3] = (int)param_2;

  *param_1 = (int)piVar3;

  if (*piVar3 != 0) {

    *(int **)(*piVar3 + 4) = piVar3;

  }

  piVar2 = DAT_0059da7c;

  if (DAT_0059da7c == (int *)0x0) {

    puVar1 = (undefined4 *)

             FUN_0053a700(0xf,0xc84,s_links_0055b558,s_C__Giants_source_main_linkage_c_0055b560,0x1b

                         );

    *puVar1 = DAT_0059da80;

    DAT_0059da7c = puVar1 + 1;

    iVar4 = 0xc6;

    piVar2 = DAT_0059da7c;

    DAT_0059da80 = puVar1;

    do {

      iVar4 = iVar4 + -1;

      *piVar2 = (int)(piVar2 + 4);

      piVar2 = piVar2 + 4;

    } while (iVar4 != 0);

    puVar1[0x319] = 0;

    piVar2 = DAT_0059da7c;

  }

  DAT_0059da7c = (int *)*piVar2;

  piVar2[1] = (int)param_2;

  *piVar2 = *param_2;

  piVar2[2] = (int)param_2;

  piVar2[3] = (int)piVar3;

  *param_2 = (int)piVar2;

  if (*piVar2 != 0) {

    *(int **)(*piVar2 + 4) = piVar2;

  }

  return;

}

/* ===== main_linkage_00470360 @ 0x00470360 ===== */
void main_linkage_00470360(int *param_1,int *param_2)



{

  int *piVar1;

  undefined4 *puVar2;

  int *piVar3;

  int *piVar4;

  int iVar5;

  

  piVar4 = (int *)*param_1;

  piVar3 = param_1;

  while (piVar1 = piVar4, piVar1 != (int *)0x0) {

    piVar3 = piVar1;

    piVar4 = (int *)*piVar1;

  }

  piVar4 = DAT_0059da7c;

  if (DAT_0059da7c == (int *)0x0) {

    puVar2 = (undefined4 *)

             FUN_0053a700(0xf,0xc84,s_links_0055b558,s_C__Giants_source_main_linkage_c_0055b560,0x1b

                         );

    *puVar2 = DAT_0059da80;

    DAT_0059da7c = puVar2 + 1;

    iVar5 = 0xc6;

    piVar4 = DAT_0059da7c;

    DAT_0059da80 = puVar2;

    do {

      iVar5 = iVar5 + -1;

      *piVar4 = (int)(piVar4 + 4);

      piVar4 = piVar4 + 4;

    } while (iVar5 != 0);

    puVar2[0x319] = 0;

    piVar4 = DAT_0059da7c;

  }

  DAT_0059da7c = (int *)*piVar4;

  piVar4[1] = (int)piVar3;

  iVar5 = *piVar3;

  piVar4[2] = (int)param_1;

  *piVar4 = iVar5;

  piVar4[3] = (int)param_2;

  *piVar3 = (int)piVar4;

  if (*piVar4 != 0) {

    *(int **)(*piVar4 + 4) = piVar4;

  }

  piVar3 = DAT_0059da7c;

  if (DAT_0059da7c == (int *)0x0) {

    puVar2 = (undefined4 *)

             FUN_0053a700(0xf,0xc84,s_links_0055b558,s_C__Giants_source_main_linkage_c_0055b560,0x1b

                         );

    *puVar2 = DAT_0059da80;

    DAT_0059da7c = puVar2 + 1;

    iVar5 = 0xc6;

    piVar3 = DAT_0059da7c;

    DAT_0059da80 = puVar2;

    do {

      iVar5 = iVar5 + -1;

      *piVar3 = (int)(piVar3 + 4);

      piVar3 = piVar3 + 4;

    } while (iVar5 != 0);

    puVar2[0x319] = 0;

    piVar3 = DAT_0059da7c;

  }

  DAT_0059da7c = (int *)*piVar3;

  piVar3[1] = (int)param_2;

  *piVar3 = *param_2;

  piVar3[2] = (int)param_2;

  piVar3[3] = (int)piVar4;

  *param_2 = (int)piVar3;

  if (*piVar3 != 0) {

    *(int **)(*piVar3 + 4) = piVar3;

  }

  return;

}

/* ===== main_linkage_00470610 @ 0x00470610 ===== */
void main_linkage_00470610(void)



{

  undefined4 *puVar1;

  undefined4 *puVar2;

  

  puVar2 = DAT_0059da80;

  while (puVar2 != (undefined4 *)0x0) {

    puVar1 = (undefined4 *)*puVar2;

    mem_free_tagged(puVar2,s_C__Giants_source_main_linkage_c_0055b560,0x11d);

    puVar2 = puVar1;

  }

  DAT_0059da80 = (undefined4 *)0x0;

  DAT_0059da7c = 0;

  return;

}

