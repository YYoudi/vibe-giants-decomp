/* Giants 1.449 — module main/reaper
 * 1 functions (1 named) — decompiled, names from PS2 symbols
 * Original source: C:\Giants\source\main/reaper.c(pp) (assert-string evidence)
 */

/* ===== reaper_finish_slow_follow__FP6OBJECTPUi @ 0x004C0010 ===== */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

/* WARNING: Struct "OBJECT": ignoring multiple overlapping fields */



void reaper_finish_slow_follow__FP6OBJECTPUi(OBJECT *p0,uint *p1)



{

  byte *pbVar1;

  int iVar2;

  int iVar3;

  OBJECT *pOVar4;

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

  

  pOVar4 = p0;

  iVar2 = *(int *)&p0->field_0x100;

  p0->field_E0 = p0->field_E0 & 0xfffdffff;

  if (*(int *)(iVar2 + 0xf28) != 0) {

    FUN_004a76e0(p0,0,local_5c + 3);

    fVar10 = (float10)FUN_0050a400(local_5c + 3,*(int *)(iVar2 + 0xf28) + 0xa0);

    fVar11 = (float10)FUN_0050a490(local_5c + 3,*(int *)(iVar2 + 0xf28) + 0xa0);

    p0 = (OBJECT *)((float)fVar10 - 90.0);

    iVar5 = FUN_004a8f50(0x12);

    if (iVar5 != 0) {

      iVar5 = 0;

      do {

        FUN_0053e460(local_44,(float)fVar11,0,p0);

        local_34 = local_5c[3];

        local_44[0] = local_44[0] | 0x10;

        local_24 = local_4c;

        local_14 = local_48;

        if (iVar5 == 1) {

          local_5c[1] = FUN_004aa550(0x14,pOVar4->field_18C,pOVar4,0xfffffffe,local_44,

                                     *(undefined4 *)(iVar2 + 0xf28));

        }

        else {

          iVar6 = FUN_004aa550(0x12,pOVar4->field_18C,pOVar4,0xfffffffe,local_44,

                               *(undefined4 *)(iVar2 + 0xf28));

          local_5c[iVar5] = iVar6;

        }

        iVar6 = FUN_0052e480(pOVar4);

        if (iVar6 == 0) {

          *(uint *)(local_5c[iVar5] + 0x188) = p1[iVar5];

        }

        piVar9 = local_5c + iVar5;

        p0 = (OBJECT *)((float)p0 + 90.0);

        iVar5 = iVar5 + 1;

        *(OBJECT **)(*piVar9 + 0x274) = pOVar4;

      } while (iVar5 < 3);

      piVar7 = (int *)FUN_0053a700(0xd,0x20,s_slow_follow_custom_00561044,

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

      iVar8 = FUN_0052e4a0(pOVar4);

      if (iVar8 != 0) {

        local_5c[0] = *(int *)(iVar2 + 0x188);

        local_5c[1] = *(int *)(iVar5 + 0x188);

        local_5c[2] = *(int *)(iVar6 + 0x188);

        FUN_00530bd0(pOVar4,0,3,0,0x1e,local_5c);

      }

      sound_play_player(0x3a8,pOVar4);

    }

  }

  return;

}

