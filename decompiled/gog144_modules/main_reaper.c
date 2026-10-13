/* Giants 1.449 — module main/reaper
 * 1 functions (1 named) — decompiled, names from PS2 symbols
 * Original source: C:\Giants\source\main/reaper.c(pp) (assert-string evidence)
 */

/* ===== reaper_finish_slow_follow__FP6OBJECTPUi @ 0x004C0010 ===== */
void reaper_finish_slow_follow__FP6OBJECTPUi(float param_1,int param_2)



{

  byte *pbVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  int *piVar7;

  int iVar8;

  int *piVar9;

  float10 fVar10;

  float10 fVar11;

  int local_5c [4];

  undefined4 local_4c;

  undefined4 local_48;

  uint local_44 [4];

  undefined4 local_34;

  undefined4 local_24;

  undefined4 local_14;

  

  iVar4 = (int)param_1;

  iVar2 = *(int *)((int)param_1 + 0x100);

  *(uint *)((int)param_1 + 0xe0) = *(uint *)((int)param_1 + 0xe0) & 0xfffdffff;

  if (*(int *)(iVar2 + 0xf28) != 0) {

    playerobj_eval_refpt(param_1,0,local_5c + 3);

    fVar10 = (float10)dirfcalcp3d__FP3P3DT0(local_5c + 3,*(int *)(iVar2 + 0xf28) + 0xa0);

    fVar11 = (float10)FUN_0050a490(local_5c + 3,*(int *)(iVar2 + 0xf28) + 0xa0);

    param_1 = (float)fVar10 - 90.0;

    iVar5 = PROJ_DefGet(0x12);

    if (iVar5 != 0) {

      iVar5 = 0;

      do {

        FUN_0053e460(local_44,(float)fVar11,0,param_1);

        local_34 = local_5c[3];

        local_44[0] = local_44[0] | 0x10;

        local_24 = local_4c;

        local_14 = local_48;

        if (iVar5 == 1) {

          local_5c[1] = PROJ_Create3(0x14,*(undefined4 *)(iVar4 + 0x18c),iVar4,0xfffffffe,local_44,

                                     *(undefined4 *)(iVar2 + 0xf28));

        }

        else {

          iVar6 = PROJ_Create3(0x12,*(undefined4 *)(iVar4 + 0x18c),iVar4,0xfffffffe,local_44,

                               *(undefined4 *)(iVar2 + 0xf28));

          local_5c[iVar5] = iVar6;

        }

        iVar6 = fx_create(iVar4);

        if (iVar6 == 0) {

          *(undefined4 *)(local_5c[iVar5] + 0x188) = *(undefined4 *)(param_2 + iVar5 * 4);

        }

        piVar9 = local_5c + iVar5;

        param_1 = param_1 + 90.0;

        iVar5 = iVar5 + 1;

        *(int *)(*piVar9 + 0x274) = iVar4;

      } while (iVar5 < 3);

      piVar7 = (int *)MemAllocMsg(0xd,0x20,s_slow_follow_custom_00561044,

                                  s_C__Giants_source_main_reaper_c_00560fdc,0x15cf);

      iVar6 = local_5c[2];

      iVar5 = local_5c[1];

      iVar2 = local_5c[0];

      piVar9 = piVar7;

      for (iVar8 = 8; iVar8 != 0; iVar8 = iVar8 + -1) {

        *piVar9 = 0;

        piVar9 = piVar9 + 1;

      }

      *piVar7 = local_5c[0];

      piVar7[1] = local_5c[1];

      piVar7[2] = local_5c[2];

      iVar8 = 0;

      do {

        iVar3 = *(int *)(local_5c[iVar8] + 0x100);

        pbVar1 = (byte *)(iVar3 + 1);

        *pbVar1 = *pbVar1 | 8;

        iVar8 = iVar8 + 1;

        *(int **)(iVar3 + 0x1c) = piVar7;

      } while (iVar8 < 3);

      iVar8 = reaper_0052e4a0(iVar4);

      if (iVar8 != 0) {

        local_5c[0] = *(int *)(iVar2 + 0x188);

        local_5c[1] = *(int *)(iVar5 + 0x188);

        local_5c[2] = *(int *)(iVar6 + 0x188);

        reaper_00530bd0(iVar4,0,3,0,0x1e,local_5c);

      }

      sound_play_player(0x3a8,iVar4);

    }

  }

  return;

}

