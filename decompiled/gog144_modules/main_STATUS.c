/* Giants 1.449 — module main/STATUS
 * 1 functions (1 named) — decompiled, names from PS2 symbols
 * Original source: C:\Giants\source\main/STATUS.c(pp) (assert-string evidence)
 */

/* ===== main_status_00500520 @ 0x00500520 ===== */
int main_status_00500520(int *param_1)



{

  int iVar1;

  int iVar2;

  undefined4 uVar3;

  int *piVar4;

  undefined4 *puVar5;

  int iVar6;

  

  if (*param_1 == 0) {

    iVar1 = 0;

    puVar5 = &DAT_005775e0;

    iVar2 = DAT_005775e0;

    while (iVar2 != 0) {

      piVar4 = puVar5 + 1;

      puVar5 = puVar5 + 1;

      iVar1 = iVar1 + 1;

      iVar2 = *piVar4;

    }

    param_1[1] = iVar1;

    iVar2 = MemAllocMsg(0x1b,iVar1 * 4,s_Status_Screen_Objdata_array_0057a730,

                        s_C__Giants_source_main_STATUS_C_0057a74c,0x1de2);

    param_1[2] = iVar2;

    iVar2 = MemAllocMsg(0x1b,iVar1 * 4,s_Status_Screen_Plist_array_0057a714,

                        s_C__Giants_source_main_STATUS_C_0057a74c,0x1de3);

    param_1[3] = iVar2;

    if (DAT_005775e0 != 0) {

      iVar2 = 0;

      puVar5 = &DAT_005775e0;

      do {

        uVar3 = objectset_find_2(*puVar5);

        *(undefined4 *)(iVar2 + param_1[2]) = uVar3;

        if (*(int *)(iVar2 + param_1[2]) == 0) {

          crt_sprintf(&DAT_00657400,s_Error__missing_objdata_in_status_0057a6dc,*puVar5);

          error_msg_show(&DAT_00657400);

        }

        piVar4 = puVar5 + 1;

        puVar5 = puVar5 + 1;

        iVar2 = iVar2 + 4;

      } while (*piVar4 != 0);

    }

    world_reset_callback_add(&LAB_00500710);

    iVar2 = 0;

    param_1[4] = (int)&PTR_DAT_00562510;

    param_1[6] = (int)&PTR_PTR_00576ed8;

    param_1[8] = -1;

    if (0 < param_1[1]) {

      do {

        iVar1 = *(int *)(param_1[2] + iVar2 * 4);

        if (iVar1 != 0) {

          uVar3 = MemAllocMsg(0x1b,*(int *)(iVar1 + 0x30) * 0x38,

                              s_Status_Screen_P3DN3D_List_0057a6c0,

                              s_C__Giants_source_main_STATUS_C_0057a74c,0x1dfc);

          *(undefined4 *)(param_1[3] + iVar2 * 4) = uVar3;

        }

        iVar2 = iVar2 + 1;

      } while (iVar2 < param_1[1]);

    }

    status_subobj_init(param_1);

    puVar5 = (undefined4 *)param_1[6];

    piVar4 = (int *)*puVar5;

    while (piVar4 != (int *)0x0) {

      iVar2 = *piVar4;

      while (iVar2 != 0) {

        piVar4 = piVar4 + 1;

        puVar5[1] = puVar5[1] + 1;

        iVar2 = *piVar4;

      }

      puVar5 = puVar5 + 9;

      param_1[5] = param_1[5] + 1;

      piVar4 = (int *)*puVar5;

    }

    *param_1 = 1;

    param_1[9] = DAT_00632e84;

    param_1[10] = DAT_00632e88;

    terrain_mesh_query(param_1,0,0xffffffff);

    mission_screen_icon_bounds_calc(param_1);

    mission_screen_slot_bounds_merge(param_1);

    iVar2 = param_1[9];

    puVar5 = *(undefined4 **)param_1[6];

    iVar1 = param_1[10];

    for (iVar6 = ((undefined4 *)param_1[6])[1]; iVar6 != 0; iVar6 = iVar6 + -1) {

      textrender_glyph_quad

                (param_1,*puVar5,0,0x3f800000,0x3f800000,(float)iVar2 * 0.5,(float)iVar1 * 0.5);

      puVar5 = puVar5 + 1;

    }

  }

  return *param_1;

}

