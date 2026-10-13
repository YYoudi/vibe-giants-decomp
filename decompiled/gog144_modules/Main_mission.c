/* Giants 1.449 — module Main/mission
 * 2 functions (1 named) — decompiled, names from PS2 symbols
 * Original source: C:\Giants\source\Main/mission.c(pp) (assert-string evidence)
 */

/* ===== FUN_00490860 @ 0x00490860 ===== */
/* PS2 candidate: read_worlds_bin_fn_PS2 (conf 0.517) */



void FUN_00490860(void)



{

  int iVar1;

  undefined4 uVar2;

  undefined4 uVar3;

  int iVar4;

  undefined1 local_180 [128];

  undefined1 local_100 [256];

  

  iVar4 = 0;

  do {

    if (*(int *)(iVar4 + 0x4550 + DAT_006330e4) == 2) {

      FUN_00542f27(local_100,s_wm__s_bin_0055c6d8,iVar4 + 0x4558 + DAT_006330e4);

      iVar1 = main_005380e0(local_100);

      if (iVar1 == 0) {

        FUN_00542f27(local_180,s_Mission___s__Can_t_be_found_0055c6bc,local_100);

        FUN_0051ea20(local_180);

      }

      else {

        uVar2 = FUN_00517990(iVar1);

        uVar3 = FUN_0053a700(0x16,uVar2,s_mission_data_0055c68c,

                             s_C__Giants_source_Main_mission_c_0055c69c,0xa6);

        *(undefined4 *)(iVar4 + 0x457c + DAT_006330e4) = uVar3;

        FUN_005178d0(iVar1,*(undefined4 *)(iVar4 + 0x457c + DAT_006330e4),uVar2);

        ANM_BinderDestroy_2(iVar1);

      }

    }

    iVar4 = iVar4 + 0x30;

  } while (iVar4 < 0x510);

  return;

}

/* ===== main_mission_00490970 @ 0x00490970 ===== */
void main_mission_00490970(void)



{

  int iVar1;

  int iVar2;

  

  if (DAT_006330e4 != 0) {

    iVar2 = 0;

    do {

      iVar1 = *(int *)(iVar2 + 0x457c + DAT_006330e4);

      if (iVar1 != 0) {

        mem_free_tagged(iVar1,s_C__Giants_source_Main_mission_c_0055c69c,0xc3);

        *(undefined4 *)(iVar2 + 0x457c + DAT_006330e4) = 0;

      }

      iVar2 = iVar2 + 0x30;

    } while (iVar2 < 0x510);

  }

  return;

}

