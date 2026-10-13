/* Giants 1.449 — module Main/menu
 * 2 functions (2 named) — decompiled, names from PS2 symbols
 * Original source: C:\Giants\source\Main/menu.c(pp) (assert-string evidence)
 */

/* ===== main_menu_00483200 @ 0x00483200 ===== */
void main_menu_00483200(int param_1,int param_2)



{

  int iVar1;

  int iVar2;

  

  if (param_2 == 0) {

    if ((&DAT_0059dcd4)[param_1 * 3] != 0) {

      iVar2 = 0;

      if (0 < (int)(&DAT_0059dcd8)[param_1 * 3]) {

        do {

          iVar1 = *(int *)((&DAT_0059dcd4)[param_1 * 3] + iVar2 * 4);

          if (iVar1 != 0) {

            fx_delete(iVar1);

            *(undefined4 *)((&DAT_0059dcd4)[param_1 * 3] + iVar2 * 4) = 0;

          }

          iVar2 = iVar2 + 1;

        } while (iVar2 < (int)(&DAT_0059dcd8)[param_1 * 3]);

      }

      mem_free_tagged((&DAT_0059dcd4)[param_1 * 3],s_C__Giants_source_Main_menu_c_0055bed4,0x1d9);

      (&DAT_0059dcd4)[param_1 * 3] = 0;

    }

  }

  else if (*(int *)(param_2 + 0x48) != 0) {

    if (0 < *(int *)(param_2 + 0x4c)) {

      iVar2 = 0;

      do {

        iVar1 = *(int *)(*(int *)(param_2 + 0x48) + iVar2 * 4);

        if (iVar1 != 0) {

          fx_delete(iVar1);

          *(undefined4 *)(*(int *)(param_2 + 0x48) + iVar2 * 4) = 0;

        }

        iVar2 = iVar2 + 1;

      } while (iVar2 < *(int *)(param_2 + 0x4c));

    }

    mem_free_tagged(*(undefined4 *)(param_2 + 0x48),s_C__Giants_source_Main_menu_c_0055bed4,0x1c6);

    *(undefined4 *)(param_2 + 0x48) = 0;

  }

  mission_00447fd0();

  return;

}

/* ===== main_menu_004832f0 @ 0x004832F0 ===== */
void main_menu_004832f0(void)



{

  int *piVar1;

  undefined4 *puVar2;

  int iVar3;

  uint uVar4;

  int iVar5;

  uint *puVar6;

  float10 fVar7;

  

  iVar3 = DAT_0059eec4;

  if (DAT_0059eec4 == 0) {

    iVar3 = 0;

    puVar6 = &DAT_0059dcd8;

    do {

      if (puVar6[-2] == 0) {

        if (puVar6[-1] != 0) {

          main_menu_00483200(iVar3,0);

        }

      }

      else if ((puVar6[-1] == 0) && (0 < (int)*puVar6)) {

        puVar2 = (undefined4 *)

                 MemAllocMsg(0x15,*puVar6 << 2,s_selection_fx_0055bef4,

                             s_C__Giants_source_Main_menu_c_0055bed4,0x2d5);

        puVar6[-1] = (uint)puVar2;

        for (uVar4 = *puVar6 & 0x3fffffff; uVar4 != 0; uVar4 = uVar4 - 1) {

          *puVar2 = 0;

          puVar2 = puVar2 + 1;

        }

        for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {

          *(undefined1 *)puVar2 = 0;

          puVar2 = (undefined4 *)((int)puVar2 + 1);

        }

      }

      puVar6 = puVar6 + 3;

      iVar3 = iVar3 + 1;

    } while ((int)puVar6 < 0x59e188);

  }

  else {

    do {

      if (*(int *)(iVar3 + 0x44) == 0) {

        if (*(int *)(iVar3 + 0x48) != 0) {

          main_menu_00483200(0xffffffff,iVar3);

        }

      }

      else if ((*(int *)(iVar3 + 0x48) == 0) && (0 < *(int *)(iVar3 + 0x4c))) {

        puVar2 = (undefined4 *)

                 MemAllocMsg(0x15,*(int *)(iVar3 + 0x4c) << 2,s_selection_fx_0055bef4,

                             s_C__Giants_source_Main_menu_c_0055bed4,0x2c4);

        *(undefined4 **)(iVar3 + 0x48) = puVar2;

        for (uVar4 = *(uint *)(iVar3 + 0x4c) & 0x3fffffff; uVar4 != 0; uVar4 = uVar4 - 1) {

          *puVar2 = 0;

          puVar2 = puVar2 + 1;

        }

        for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {

          *(undefined1 *)puVar2 = 0;

          puVar2 = (undefined4 *)((int)puVar2 + 1);

        }

      }

      piVar1 = (int *)(iVar3 + 0x50);

      iVar3 = *piVar1;

    } while (*piVar1 != 0);

  }

  iVar3 = dialog_level_is_base();

  if (((iVar3 == 0) || (DAT_00633044 == 0)) || (DAT_00632f08 < 0xd)) {

    FUN_00531470();

    fx_process(1);

    sound_checked_big(1);

    object_list_update();

    comm_heartbeat_send();

  }

  else {

    game_loop_run(0);

  }

  *(uint *)(DAT_0059ee98 + 0xd8) = *(uint *)(DAT_0059ee98 + 0xd8) & 0xffffffbf;

  obj_velocity_commit(DAT_0059ee98);

  if ((*(byte *)(DAT_0059ee98 + 0xd8) & 0x40) == 0) {

    objspec_dispatch_gate(DAT_0059ee98);

    fVar7 = (float10)FUN_00518b70(0,0);

    object_animate_process(DAT_0059ee98,(float)fVar7);

    ObjectCalculateTransform(DAT_0059ee98);

    *(uint *)(DAT_0059ee98 + 0xd8) = *(uint *)(DAT_0059ee98 + 0xd8) | 0x20;

  }

  object_lock_apply(0,2);

  if (DAT_00632a88 == 0) {

    DAT_00632a88 = -0x21524111;

  }

  ref_anode_user();

  if (DAT_00632a88 == -0x21524111) {

    DAT_00632a88 = 0;

  }

  return;

}

