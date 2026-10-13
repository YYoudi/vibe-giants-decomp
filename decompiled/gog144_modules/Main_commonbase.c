/* Giants 1.449 — module Main/commonbase
 * 1 functions (1 named) — decompiled, names from PS2 symbols
 * Original source: C:\Giants\source\Main/commonbase.c(pp) (assert-string evidence)
 */

/* ===== main_commonbase_00418f00 @ 0x00418F00 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* PS2 candidate: smartie_move (conf 0.522) */



void main_commonbase_00418f00(int param_1,undefined4 param_2,int param_3,float *param_4)



{

  byte bVar1;

  byte bVar2;

  float *pfVar3;

  float fVar4;

  undefined4 *puVar5;

  int iVar6;

  undefined4 uVar7;

  int iVar8;

  int iVar9;

  int iVar10;

  float10 fVar11;

  float local_94;

  float local_90;

  float local_8c;

  undefined4 local_88;

  undefined4 local_84;

  undefined1 local_80 [128];

  

  switch(param_2) {

  case 1:

    iVar8 = *(int *)(param_1 + 0x100);

    iVar9 = objanim_select_animloop(param_4[1]);

    if (iVar9 != 0) {

      meccbaseitem_start_building(param_1,iVar9,*param_4);

LAB_0041906f:

      *(float *)(*(int *)((int)*param_4 * 0x1c + 0x20 + iVar8) + 0x188) = param_4[1];

      return;

    }

    if (DAT_00657678 == 0) {

      crt_sprintf(local_80,s_Error_on_DPlay_StartMeccBldg_ind_00555780,*param_4,param_4[1]);

      FUN_0051ea20(local_80);

      return;

    }

    break;

  case 2:

    collgrid_query_obj(param_1,1);

    pfVar3 = *(float **)(param_1 + 0x100);

    if (*(int *)(param_1 + 0xe4) == 9) {

      local_90 = *param_4;

      iVar8 = meccbasepit_bldg_from_object(param_1);

      if ((iVar8 == 0) && (iVar8 = reaperbase_bldg_from_object(param_1), iVar8 == 0)) {

        iVar8 = FUN_004a6220(param_1);

        if ((((iVar8 != 0) || (iVar8 = FUN_004a6300(param_1), iVar8 != 0)) &&

            (pfVar3 != (float *)0x0)) && (*pfVar3 = local_90, local_90 < 0.0)) {

          *pfVar3 = 0.0;

          FUN_004180a0(param_1,param_4[1]);

          return;

        }

      }

      else if ((pfVar3 != (float *)0x0) && (pfVar3[0x166] = local_90, local_90 < 0.0)) {

        pfVar3[0x166] = 0.0;

      }

      FUN_004180a0(param_1,param_4[1]);

      return;

    }

    iVar8 = meccbasepit_bldg_from_object(param_1);

    if ((iVar8 == 0) && (iVar8 = reaperbase_bldg_from_object(param_1), iVar8 == 0)) {

      fVar4 = *pfVar3;

    }

    else {

      fVar4 = pfVar3[0x166];

    }

    pfVar3 = *(float **)(param_1 + 0x100);

    if (*param_4 <= fVar4) {

      iVar8 = meccbasepit_bldg_from_object(param_1);

      if ((iVar8 == 0) && (iVar8 = reaperbase_bldg_from_object(param_1), iVar8 == 0)) {

        fVar4 = *pfVar3;

      }

      else {

        fVar4 = pfVar3[0x166];

      }

      if (*param_4 < fVar4) {

        pfVar3 = *(float **)(param_1 + 0x100);

        iVar8 = meccbasepit_bldg_from_object(param_1);

        if ((iVar8 == 0) && (iVar8 = reaperbase_bldg_from_object(param_1), iVar8 == 0)) {

          local_94 = *pfVar3;

        }

        else {

          local_94 = pfVar3[0x166];

        }

        local_94 = local_94 - *param_4;

        pfVar3 = *(float **)(param_1 + 0x100);

        iVar8 = meccbasepit_bldg_from_object(param_1);

        if ((iVar8 == 0) && (iVar8 = reaperbase_bldg_from_object(param_1), iVar8 == 0)) {

          fVar4 = *pfVar3;

        }

        else {

          fVar4 = pfVar3[0x166];

        }

        if (local_94 <= fVar4) {

          local_90 = local_94;

        }

        else {

          pfVar3 = *(float **)(param_1 + 0x100);

          iVar8 = meccbasepit_bldg_from_object(param_1);

          if ((iVar8 == 0) && (iVar8 = reaperbase_bldg_from_object(param_1), iVar8 == 0)) {

            local_90 = *pfVar3;

          }

          else {

            local_90 = pfVar3[0x166];

          }

        }

        pfVar3 = *(float **)(param_1 + 0x100);

        iVar8 = meccbasepit_bldg_from_object(param_1);

        if ((iVar8 == 0) && (iVar8 = reaperbase_bldg_from_object(param_1), iVar8 == 0)) {

          fVar4 = *pfVar3;

        }

        else {

          fVar4 = pfVar3[0x166];

        }

        local_94 = fVar4 - local_94;

        pfVar3 = *(float **)(param_1 + 0x100);

        iVar8 = meccbasepit_bldg_from_object(param_1);

        if ((iVar8 == 0) && (iVar8 = reaperbase_bldg_from_object(param_1), iVar8 == 0)) {

          iVar8 = FUN_004a6220(param_1);

          if ((((iVar8 != 0) || (iVar8 = FUN_004a6300(param_1), iVar8 != 0)) &&

              (pfVar3 != (float *)0x0)) && (*pfVar3 = local_94, local_94 < 0.0)) {

            *pfVar3 = 0.0;

          }

        }

        else if ((pfVar3 != (float *)0x0) && (pfVar3[0x166] = local_94, local_94 < 0.0)) {

          pfVar3[0x166] = 0.0;

        }

        pfVar3 = *(float **)(param_1 + 0x100);

        iVar8 = meccbasepit_bldg_from_object(param_1);

        if ((iVar8 == 0) && (iVar8 = reaperbase_bldg_from_object(param_1), iVar8 == 0)) {

          fVar4 = *pfVar3;

        }

        else {

          fVar4 = pfVar3[0x166];

        }

        if (fVar4 < 0.0 != (fVar4 == 0.0)) {

          bldg_set_energy(param_1,0);

        }

        *(float *)(param_1 + 0x278) = local_90 + *(float *)(param_1 + 0x278);

      }

      goto LAB_004195d2;

    }

    iVar8 = meccbasepit_bldg_from_object(param_1);

    if ((iVar8 == 0) && (iVar8 = reaperbase_bldg_from_object(param_1), iVar8 == 0)) {

      local_94 = *pfVar3;

    }

    else {

      local_94 = pfVar3[0x166];

    }

    local_94 = *param_4 - local_94;

    iVar8 = meccbasepit_bldg_from_object(param_1);

    if ((iVar8 == 0) && (iVar8 = FUN_004a6220(param_1), iVar8 == 0)) {

      iVar8 = reaperbase_bldg_from_object(param_1);

      if ((iVar8 != 0) || (iVar8 = FUN_004a6300(param_1), iVar8 != 0)) {

        fVar11 = (float10)reaperbase_get_max_energy(param_1);

        goto LAB_0041927a;

      }

      local_90 = 50.0;

    }

    else {

      fVar11 = (float10)meccbase_get_max_energy(param_1);

LAB_0041927a:

      local_90 = (float)fVar11;

    }

    pfVar3 = *(float **)(param_1 + 0x100);

    iVar8 = meccbasepit_bldg_from_object(param_1);

    if ((iVar8 == 0) && (iVar8 = reaperbase_bldg_from_object(param_1), iVar8 == 0)) {

      fVar4 = *pfVar3;

    }

    else {

      fVar4 = pfVar3[0x166];

    }

    if (local_90 - 1.0 < local_94 + fVar4 != (local_90 - 1.0 == local_94 + fVar4)) {

      pfVar3 = *(float **)(param_1 + 0x100);

      iVar8 = meccbasepit_bldg_from_object(param_1);

      if ((iVar8 == 0) && (iVar8 = reaperbase_bldg_from_object(param_1), iVar8 == 0)) {

        local_94 = *pfVar3;

      }

      else {

        local_94 = pfVar3[0x166];

      }

      local_94 = local_90 - local_94;

    }

    pfVar3 = *(float **)(param_1 + 0x100);

    iVar8 = meccbasepit_bldg_from_object(param_1);

    if ((iVar8 == 0) && (iVar8 = reaperbase_bldg_from_object(param_1), iVar8 == 0)) {

      local_90 = *pfVar3;

    }

    else {

      local_90 = pfVar3[0x166];

    }

    local_90 = local_90 + local_94;

    pfVar3 = *(float **)(param_1 + 0x100);

    iVar8 = meccbasepit_bldg_from_object(param_1);

    if ((iVar8 == 0) && (iVar8 = reaperbase_bldg_from_object(param_1), iVar8 == 0)) {

      iVar8 = FUN_004a6220(param_1);

      if ((((iVar8 != 0) || (iVar8 = FUN_004a6300(param_1), iVar8 != 0)) && (pfVar3 != (float *)0x0)

          ) && (*pfVar3 = local_90, local_90 < 0.0)) {

        *pfVar3 = 0.0;

      }

    }

    else if ((pfVar3 != (float *)0x0) && (pfVar3[0x166] = local_90, local_90 < 0.0)) {

      pfVar3[0x166] = 0.0;

    }

    fVar4 = *(float *)(param_1 + 0x278) - local_94;

    *(float *)(param_1 + 0x278) = fVar4;

    if (fVar4 < 0.0) {

      *(undefined4 *)(param_1 + 0x278) = 0;

      FUN_004180a0(param_1,param_4[1]);

      return;

    }

LAB_004195d2:

    FUN_004180a0(param_1,param_4[1]);

    return;

  case 3:

    iVar8 = FUN_004a6220(param_1);

    if (iVar8 != 0) {

      meccbaseitem_finish_building();

      return;

    }

    iVar8 = FUN_004a6300(param_1);

    if (iVar8 != 0) {

      reaperbasebldg_finish_building(param_1);

      return;

    }

    break;

  case 5:

    iVar8 = *(int *)(param_1 + 0x100);

    fVar4 = *(float *)(iVar8 + 0x56c);

    if (((fVar4 == 0.0) || (fVar4 == *param_4)) ||

       (iVar9 = objanim_select_animloop(fVar4), iVar9 == 0)) {

      *(float *)(iVar8 + 0x56c) = *param_4;

      local_94 = *param_4;

      reaper_00530bd0(param_1,0,1,0,6,&local_94);

      return;

    }

    break;

  case 6:

    fVar4 = *param_4;

    *(float *)(*(int *)(param_1 + 0x100) + 0x56c) = fVar4;

    if ((DAT_00632a88 != 0) && (fVar4 == *(float *)(DAT_00632a88 + 0x188))) {

      evilreaper_award_item__FP6OBJECT(DAT_00632a88);

      return;

    }

    break;

  case 8:

    if (*(int *)(param_1 + 0x18c) == 2) {

      uVar7 = 0x248;

    }

    else {

      uVar7 = 0x2e6;

    }

    iVar8 = object_allocate_type(uVar7,0x80000000);

    objtype_setup_vimp(iVar8,param_1);

    iVar9 = reaper_0052e4a0(param_1);

    if (iVar9 != 0) {

      local_94 = *(float *)(iVar8 + 0x188);

      reaper_00530bd0(param_1,0,1,0,8,&local_94);

    }

    *(float *)(iVar8 + 0x188) = *param_4;

    return;

  case 9:

    iVar8 = *(int *)(param_1 + 0x100);

    iVar9 = objanim_select_animloop(param_4[1]);

    if (iVar9 != 0) {

      reaperbasebldg_start_building(param_1,iVar9,*param_4);

      goto LAB_0041906f;

    }

    if (DAT_00657678 == 0) {

      crt_sprintf(local_80,s_Error_on_DPlay_StartReaperBldg_i_00555720,*param_4,param_4[1]);

      FUN_0051ea20(local_80);

      return;

    }

    break;

  case 10:

    object_spawn_class5(*param_4,param_1);

    return;

  case 0xc:

    local_94 = *(float *)(param_1 + 0x100);

    iVar8 = objanim_select_animloop(param_4[1]);

    if (iVar8 == 0) {

      __rt_error_box(s_smartie_005556f4,s_C__Giants_source_Main_commonbase_005556fc,0x697);

    }

    fVar4 = *param_4;

    iVar9 = meccbasepit_bldg_from_object(param_1);

    if (iVar9 == 0) {

      object_spawn_4b(param_1,fVar4);

    }

    else {

      object_spawn_class4();

    }

    *(float *)(*(int *)((int)*param_4 * 0x1c + 0x20 + (int)local_94) + 0x188) = param_4[2];

    fVar4 = *param_4;

    iVar9 = meccbasepit_bldg_from_object(param_1);

    if (iVar9 == 0) {

      iVar9 = reaperbase_bldg_from_object(param_1);

      if (iVar9 != 0) {

        FUN_004b65a0(iVar8,fVar4);

      }

    }

    else {

      FUN_0040a550(iVar8,fVar4);

    }

    iVar9 = reaper_0052e4a0(param_1);

    if (iVar9 != 0) {

      local_88 = *(undefined4 *)(iVar8 + 0x188);

      local_84 = *(undefined4 *)

                  (*(int *)((int)fVar4 * 0x1c + 0x20 + *(int *)(param_1 + 0x100)) + 0x188);

      local_8c = fVar4;

      reaper_00530bd0(param_1,0,3,0,0xc,&local_8c);

      return;

    }

    break;

  case 0x10:

    iVar8 = objtype_setup_reaper(param_1);

    if (iVar8 != 0) {

      *(float *)(iVar8 + 0x188) = *param_4;

      return;

    }

    break;

  case 0x11:

    iVar8 = FUN_0052c5c0();

    if (iVar8 != 0) {

      objtype_setup_reaper(param_1);

      return;

    }

    break;

  case 0x12:

    fxb_build_select(param_1,*param_4);

    return;

  case 0x13:

    reaper_big_update(param_1,*param_4);

    return;

  case 0x14:

    *(undefined4 *)(*(int *)(param_1 + 0x100) + 0x5ac) = 1;

    return;

  case 0x15:

    *(undefined4 *)(*(int *)(param_1 + 0x100) + 0x5ac) = 0;

    return;

  case 0x16:

    *(undefined4 *)(*(int *)(param_1 + 0x100) + 0x5a4) = 1;

    return;

  case 0x17:

    *(undefined4 *)(*(int *)(param_1 + 0x100) + 0x5a4) = 0;

    return;

  case 0x18:

    iVar8 = *(int *)(param_1 + 0x100);

    fVar4 = *param_4;

    *(float *)(iVar8 + 0x36c) = fVar4;

    *(float *)(iVar8 + 0x368) = fVar4;

    return;

  case 0x19:

    *(float *)(param_1 + 0xf4) = *param_4;

    return;

  case 0x1a:

    iVar8 = *(int *)(param_1 + 0x100);

    if (((*(int *)(iVar8 + 0x570) == 0) || (*(float *)(iVar8 + 0x56c) == *param_4)) ||

       (iVar9 = objanim_select_animloop(*(int *)(iVar8 + 0x570)), iVar9 == 0)) {

      *(float *)(iVar8 + 0x570) = *param_4;

      local_94 = *param_4;

      reaper_00530bd0(param_1,0,1,0,0x1b,&local_94);

      return;

    }

    break;

  case 0x1b:

    fVar4 = *param_4;

    *(float *)(*(int *)(param_1 + 0x100) + 0x570) = fVar4;

    if ((DAT_00632a88 != 0) && (fVar4 == *(float *)(DAT_00632a88 + 0x188))) {

      dlog_text_render_screen();

      DAT_00632bac = 1;

      return;

    }

    break;

  case 0x1c:

    iVar8 = *(int *)(param_1 + 0x100);

    iVar9 = fx_create(param_1);

    if (((iVar9 != 0) && (iVar9 = objanim_select_animloop(*param_4), iVar9 != 0)) &&

       ((iVar10 = *(int *)(iVar8 + 0x5bc + (int)param_4[2] * 4), iVar10 == 0 ||

        ((iVar10 == *(int *)(iVar9 + 0x188) ||

         (iVar10 = objanim_select_animloop(iVar10), iVar10 == 0)))))) {

      *(undefined4 *)(iVar8 + 0x5bc + (int)param_4[2] * 4) = *(undefined4 *)(iVar9 + 0x188);

      reaper_00530bd0(param_1,0,3,0,0x1d,param_4);

      return;

    }

    break;

  case 0x1d:

    uVar7 = objanim_select_animloop(*param_4);

    iVar8 = fx_create(uVar7);

    if (iVar8 != 0) {

      iVar8 = meccbasepit_bldg_from_object(param_1);

      if (iVar8 == 0) {

        iVar8 = FUN_004b6de0(param_1);

      }

      else {

        iVar8 = FUN_0040ae80();

      }

      if (iVar8 != 0) {

        iVar9 = ObjIsMecc(uVar7);

        if (iVar9 == 0) {

          FUN_004c5d80(param_1,uVar7,iVar8,param_4[2]);

          return;

        }

        FUN_00480d10(param_1,uVar7,iVar8,param_4[2]);

        return;

      }

    }

    break;

  case 0x1e:

    iVar8 = fx_create(param_1);

    if ((iVar8 != 0) && (iVar8 = objanim_select_animloop(*param_4), iVar8 != 0)) {

      iVar9 = *(int *)(param_1 + 0x100);

      if (*(int *)(iVar9 + 0x5bc) == *(int *)(iVar8 + 0x188)) {

        *(undefined4 *)(iVar9 + 0x5bc) = 0;

      }

      if (*(int *)(iVar9 + 0x5c0) == *(int *)(iVar8 + 0x188)) {

        *(undefined4 *)(iVar9 + 0x5c0) = 0;

        return;

      }

    }

    break;

  case 0x1f:

    iVar8 = fx_create(param_1);

    if (iVar8 != 0) {

      iVar8 = objanim_select_animloop(*param_4);

      iVar9 = objanim_select_animloop(param_4[1]);

      if ((iVar8 != 0) && (iVar9 != 0)) {

        iVar9 = *(int *)(iVar9 + 0x100);

        iVar10 = *(int *)(iVar9 + 0x10);

        if ((iVar10 == 0) ||

           ((iVar10 == *(int *)(iVar8 + 0x188) ||

            (iVar10 = objanim_select_animloop(iVar10), iVar10 == 0)))) {

          *(undefined4 *)(iVar9 + 0x10) = *(undefined4 *)(iVar8 + 0x188);

          reaper_00530bd0(param_1,0,2,0,0x20,param_4);

          return;

        }

      }

    }

    break;

  case 0x20:

    uVar7 = objanim_select_animloop(*param_4);

    iVar8 = fx_create(uVar7);

    if ((iVar8 != 0) && (iVar8 = objanim_select_animloop(param_4[1]), iVar8 != 0)) {

      iVar9 = ObjIsMecc(uVar7);

      if (iVar9 == 0) {

        FUN_004c50b0(uVar7,iVar8);

        return;

      }

      FUN_00480ef0();

      return;

    }

    break;

  case 0x21:

    iVar8 = fx_create(param_1);

    if (iVar8 != 0) {

      iVar8 = objanim_select_animloop(*param_4);

      iVar9 = objanim_select_animloop(param_4[1]);

      if ((iVar8 != 0) && (iVar9 != 0)) {

        *(undefined4 *)(*(int *)(iVar9 + 0x100) + 0x10) = 0;

        return;

      }

    }

    break;

  case 0x22:

    iVar8 = fx_create(param_1);

    if (iVar8 != 0) {

      iVar8 = objanim_select_animloop(*param_4);

      iVar9 = objanim_select_animloop(param_4[1]);

      if ((iVar8 != 0) && (iVar9 != 0)) {

        iVar10 = *(int *)(iVar9 + 0x100);

        iVar6 = *(int *)(iVar10 + 0x10);

        if ((iVar6 == 0) ||

           ((iVar6 == *(int *)(iVar8 + 0x188) ||

            (iVar6 = objanim_select_animloop(iVar6), iVar6 == 0)))) {

          puVar5 = DAT_00632d98;

          if ((*(uint *)(iVar8 + 0xdc) & 0x800000) != 0) {

            for (; puVar5 != (undefined4 *)0x0; puVar5 = (undefined4 *)*puVar5) {

              iVar6 = puVar5[3];

              if ((((*(uint *)(iVar6 + 0xd8) & 0x8000) == 0) && (*(int *)(iVar6 + 4) == 0xb)) &&

                 ((*(int *)(iVar6 + 0x210) == iVar8 || (*(int *)(iVar6 + 0x274) == iVar8)))) {

                *(undefined4 *)(*(int *)(iVar6 + 0x100) + 0x54) = 0;

                smartie_from_back_to_partyhouse(iVar6,iVar8,param_1,iVar9);

                break;

              }

            }

          }

          *(undefined4 *)(iVar10 + 0x10) = *(undefined4 *)(iVar8 + 0x188);

          reaper_00530bd0(param_1,0,2,0,0x23,param_4);

          return;

        }

      }

    }

    break;

  case 0x23:

    uVar7 = objanim_select_animloop(*param_4);

    iVar8 = fx_create(uVar7);

    if ((iVar8 != 0) && (iVar8 = objanim_select_animloop(param_4[1]), iVar8 != 0)) {

      iVar9 = ObjIsMecc(uVar7);

      if (iVar9 == 0) {

        mecc_drop_carried_object_2(uVar7,iVar8);

        return;

      }

      mecc_drop_carried_object();

      return;

    }

    break;

  case 0x24:

    iVar8 = fx_create(param_1);

    if (iVar8 != 0) {

      iVar8 = objanim_select_animloop(*param_4);

      iVar9 = objanim_select_animloop(param_4[1]);

      if ((iVar8 != 0) && (iVar9 != 0)) {

        *(undefined4 *)(*(int *)(iVar9 + 0x100) + 0x10) = 0;

        return;

      }

    }

    break;

  case 0x25:

    local_90 = *(float *)(param_1 + 0x100);

    local_94 = (float)(param_3 / 2);

    if (0 < (int)local_94) {

      do {

        bVar1 = *(byte *)param_4;

        bVar2 = *(byte *)((int)param_4 + 1);

        param_4 = (float *)((int)param_4 + 2);

        iVar9 = (bVar1 + 2) * 0x1c;

        iVar8 = *(int *)(iVar9 + (int)local_90);

        *(uint *)(iVar9 + (int)local_90) = (uint)bVar2;

        iVar9 = meccbasepit_bldg_from_object(param_1);

        iVar10 = (uint)bVar1 * 0x58;

        if (iVar9 == 0) {

          iVar9 = *(int *)(&DAT_005606c4 + iVar10);

        }

        else {

          iVar9 = *(int *)(&DAT_00554574 + iVar10);

        }

        if ((((*(int *)(param_1 + 0x18c) == *(int *)(DAT_00632a88 + 0x18c)) && (DAT_00632bb0 != 0))

            && (iVar8 < iVar9)) && (iVar9 <= (int)(uint)bVar2)) {

          _DAT_00657674 = 0x40000000;

          sound_play(0x651);

        }

        local_94 = (float)((int)local_94 + -1);

      } while (local_94 != 0.0);

    }

    break;

  case 0x26:

    if ((*(uint *)(param_1 + 0xe0) & 0x2000) == 0) {

      FUN_00409b60(param_1,0);

      return;

    }

    FUN_00409b60(param_1,1);

    return;

  case 0x27:

    if ((*(uint *)(param_1 + 0xe0) & 0x2000) == 0) {

      reaperbasebldg_shot_2(param_1,0);

      return;

    }

    reaperbasebldg_shot_2(param_1,1);

    return;

  }

  return;

}

