/* Giants 1.449 — module main/objspec
 * 5 functions (0 named) — decompiled, names from PS2 symbols
 * Original source: C:\Giants\source\main/objspec.c(pp) (assert-string evidence)
 */

/* ===== FUN_00499c80 @ 0x00499C80 ===== */
void FUN_00499c80(int param_1)



{

  int iVar1;

  

  iVar1 = *(int *)(param_1 + 0x2e0);

  if ((iVar1 != 0) && (*(char *)(iVar1 + 0x1e) < '\0')) {

    FUN_00508840(iVar1);

    FUN_005086e0(*(undefined4 *)(param_1 + 0x2e0));

    mem_free_tagged(*(undefined4 *)(param_1 + 0x2e0),s_C__Giants_source_main_objspec_c_0055e774,0xbb

                   );

  }

  *(undefined4 *)(param_1 + 0x2e0) = 0;

  return;

}

/* ===== FUN_00499cd0 @ 0x00499CD0 ===== */
/* PS2 candidate: object_free_all_allocated_data (conf 0.423) */



void FUN_00499cd0(int param_1)



{

  int iVar1;

  

  if (((*(int *)(param_1 + 0x1e0) < 0x6b) &&

      (*(code **)(&DAT_0055cb28 + *(int *)(param_1 + 0x1e0) * 0x44) != (code *)0x0)) &&

     (*(int *)(param_1 + 0x100) != 0)) {

    (**(code **)(&DAT_0055cb28 + *(int *)(param_1 + 0x1e0) * 0x44))(param_1);

  }

  if (*(int *)(param_1 + 0x100) != 0) {

    mem_free_tagged(*(int *)(param_1 + 0x100),s_C__Giants_source_main_objspec_c_0055e774,0xf9);

    *(undefined4 *)(param_1 + 0x100) = 0;

  }

  iVar1 = *(int *)(param_1 + 0x2e0);

  if ((iVar1 != 0) && (*(char *)(iVar1 + 0x1e) < '\0')) {

    FUN_00508840(iVar1);

    FUN_005086e0(*(undefined4 *)(param_1 + 0x2e0));

    mem_free_tagged(*(undefined4 *)(param_1 + 0x2e0),s_C__Giants_source_main_objspec_c_0055e774,0xbb

                   );

  }

  *(undefined4 *)(param_1 + 0x2e0) = 0;

  *(undefined4 *)(param_1 + 0x104) = 0;

  FUN_004101d0(param_1);

  if (*(int *)(param_1 + 0x2dc) != 0) {

    mem_free_tagged(*(int *)(param_1 + 0x2dc),s_C__Giants_source_main_objspec_c_0055e774,0xe1);

  }

  *(undefined4 *)(param_1 + 0x2dc) = 0;

  *(undefined4 *)(param_1 + 0x2d8) = 0;

  return;

}

/* ===== FUN_00499da0 @ 0x00499DA0 ===== */
void FUN_00499da0(int param_1)



{

  uint uVar1;

  undefined4 *puVar2;

  uint uVar3;

  

  if ((((*(int *)(param_1 + 0x100) == 0) && (*(int *)(param_1 + 0x1e0) < 0x6b)) &&

      (*(code **)(&DAT_0055cb14 + *(int *)(param_1 + 0x1e0) * 0x44) != (code *)0x0)) &&

     (uVar1 = (**(code **)(&DAT_0055cb14 + *(int *)(param_1 + 0x1e0) * 0x44))(param_1), uVar1 != 0))

  {

    puVar2 = (undefined4 *)

             FUN_0053a700(0x18,uVar1,s_ospec_0055e794,s_C__Giants_source_main_objspec_c_0055e774,

                          0xed);

    *(undefined4 **)(param_1 + 0x100) = puVar2;

    for (uVar3 = uVar1 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {

      *puVar2 = 0;

      puVar2 = puVar2 + 1;

    }

    for (uVar1 = uVar1 & 3; uVar1 != 0; uVar1 = uVar1 - 1) {

      *(undefined1 *)puVar2 = 0;

      puVar2 = (undefined4 *)((int)puVar2 + 1);

    }

  }

  return;

}

/* ===== FUN_00499e10 @ 0x00499E10 ===== */
void FUN_00499e10(int param_1)



{

  if (((*(int *)(param_1 + 0x1e0) < 0x6b) &&

      (*(code **)(&DAT_0055cb28 + *(int *)(param_1 + 0x1e0) * 0x44) != (code *)0x0)) &&

     (*(int *)(param_1 + 0x100) != 0)) {

    (**(code **)(&DAT_0055cb28 + *(int *)(param_1 + 0x1e0) * 0x44))(param_1);

  }

  if (*(int *)(param_1 + 0x100) != 0) {

    mem_free_tagged(*(int *)(param_1 + 0x100),s_C__Giants_source_main_objspec_c_0055e774,0xf9);

    *(undefined4 *)(param_1 + 0x100) = 0;

  }

  return;

}

/* ===== FUN_00499e70 @ 0x00499E70 ===== */
/* PS2 candidate: object_change_ospec (conf 0.5) */



void FUN_00499e70(int param_1,int param_2)



{

  uint uVar1;

  undefined4 *puVar2;

  uint uVar3;

  

  if (((*(int *)(param_1 + 0x1e0) < 0x6b) &&

      (*(code **)(&DAT_0055cb28 + *(int *)(param_1 + 0x1e0) * 0x44) != (code *)0x0)) &&

     (*(int *)(param_1 + 0x100) != 0)) {

    (**(code **)(&DAT_0055cb28 + *(int *)(param_1 + 0x1e0) * 0x44))(param_1);

  }

  if (*(int *)(param_1 + 0x100) != 0) {

    mem_free_tagged(*(int *)(param_1 + 0x100),s_C__Giants_source_main_objspec_c_0055e774,0xf9);

    *(undefined4 *)(param_1 + 0x100) = 0;

  }

  *(int *)(param_1 + 0x1e0) = param_2;

  if (((*(int *)(param_1 + 0x100) == 0) && (param_2 < 0x6b)) &&

     ((*(code **)(&DAT_0055cb14 + param_2 * 0x44) != (code *)0x0 &&

      (uVar1 = (**(code **)(&DAT_0055cb14 + param_2 * 0x44))(param_1), uVar1 != 0)))) {

    puVar2 = (undefined4 *)

             FUN_0053a700(0x18,uVar1,s_ospec_0055e794,s_C__Giants_source_main_objspec_c_0055e774,

                          0xed);

    *(undefined4 **)(param_1 + 0x100) = puVar2;

    for (uVar3 = uVar1 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {

      *puVar2 = 0;

      puVar2 = puVar2 + 1;

    }

    for (uVar1 = uVar1 & 3; uVar1 != 0; uVar1 = uVar1 - 1) {

      *(undefined1 *)puVar2 = 0;

      puVar2 = (undefined4 *)((int)puVar2 + 1);

    }

  }

  return;

}

