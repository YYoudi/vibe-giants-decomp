/* Giants 1.449 — module _unmapped_004f
 * 63 functions (57 named) — decompiled, names from PS2 symbols
 * Original source: C:\Giants\source\_unmapped_004f.c(pp) (assert-string evidence)
 */

/* ===== smartie_handle_reaper_grab__FP6OBJECTP14ObjSpecSmartie @ 0x004F38F0 ===== */
/* WARNING: Type propagation algorithm not settling */

/* PS2 candidate: smartie_handle_reaper_grab__FP6OBJECTP14ObjSpecSmartie (conf 0.597) */



void smartie_handle_reaper_grab__FP6OBJECTP14ObjSpecSmartie(int param_1,int param_2)



{

  float *pfVar1;

  float fVar2;

  int iVar3;

  float fVar4;

  float10 fVar5;

  float local_34;

  float local_30 [3];

  float local_24;

  float local_20;

  undefined1 local_1c [16];

  float local_c;

  

  fVar5 = (float10)FUN_00518b70(param_1,0);

  fVar2 = (float)fVar5;

  fVar4 = *(float *)(param_2 + 0x40) - fVar2;

  *(float *)(param_2 + 0x40) = fVar4;

  if (fVar4 < 0.0) {

    smartie_escape_reaper_grab(param_1);

    return;

  }

  fVar4 = *(float *)(param_2 + 0x44) - fVar2;

  *(float *)(param_2 + 0x44) = fVar4;

  if (0.0 <= fVar4) {

    object_add_location(param_1,0,0,*(float *)(DAT_00632ed8 + 0x7d8) * fVar2);

  }

  else {

    iVar3 = *(int *)(param_1 + 0x274);

    pfVar1 = (float *)(param_1 + 0xa0);

    local_30[2] = *(float *)(iVar3 + 0x298) * 5.0 + *(float *)(iVar3 + 0xa0);

    local_30[1] = 0.0;

    local_24 = *(float *)(iVar3 + 0x2a8) * 5.0 + *(float *)(iVar3 + 0xa4);

    local_20 = *(float *)(iVar3 + 0xa8) + 3.0;

    local_34 = local_30[2] - *pfVar1;

    local_30[0] = local_24 - *(float *)(param_1 + 0xa4);

    normalize__FPfN20(&local_34,local_30,local_30 + 1);

    local_34 = *(float *)(DAT_00632ed8 + 0x7e4) * local_34;

    local_30[0] = *(float *)(DAT_00632ed8 + 0x7e4) * local_30[0];

    object_add_location(param_1,local_34 * fVar2,local_30[0] * fVar2,

                        -(*(float *)(DAT_00632ed8 + 0x7e8) * fVar2));

    ground_height_at(pfVar1,local_1c);

    if (*(float *)(param_1 + 0xa8) < local_c + 3.0) {

      *(float *)(param_1 + 0xa8) = local_c + 3.0;

    }

    fVar5 = (float10)FUN_0050a610(pfVar1,local_30 + 2);

    if ((*(uint *)(*(int *)(param_1 + 0x274) + 0xdc) & 0x800000) == 0) {

      if (fVar5 < (float10)4.0) {

        sound_stop_obj(0x3b5,param_1);

        smartie_lock_to_player(param_1,*(undefined4 *)(param_1 + 0x274),1);

        return;

      }

    }

    else if (fVar5 < (float10)900.0) {

      smartie_escape_reaper_grab(param_1);

      return;

    }

  }

  return;

}

/* ===== smartie_animselect @ 0x004F3AF0 ===== */
/* PS2 candidate: smartie_animselect (conf 0.509) */



void smartie_animselect(int param_1)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  undefined4 uVar7;

  int iVar8;

  char *pcVar9;

  

  iVar3 = objanim_select_animloop(*(undefined4 *)(param_1 + 0x14));

  if (iVar3 == 0) {

    iVar3 = object_allocate_type(*(undefined4 *)(param_1 + 0x10),0x80000000);

    *(undefined4 *)(iVar3 + 0x188) = *(undefined4 *)(param_1 + 0x14);

  }

  *(undefined4 *)(iVar3 + 0x18c) = *(undefined4 *)(param_1 + 0x20);

  object_set_location_p3d(iVar3,param_1);

  *(undefined4 *)(iVar3 + 200) = *(undefined4 *)(param_1 + 0xc);

  *(undefined4 *)(iVar3 + 0xcc) = 0;

  *(undefined4 *)(iVar3 + 0xd0) = 0;

  *(undefined4 *)(iVar3 + 0xe4) = *(undefined4 *)(param_1 + 0x18);

  bldg_set_energy(iVar3,*(undefined4 *)(DAT_00632ed8 + 0x894));

  *(uint *)(iVar3 + 0xd8) = *(uint *)(iVar3 + 0xd8) | 0x10;

  *(uint *)(iVar3 + 0xe0) = *(uint *)(iVar3 + 0xe0) | *(uint *)(param_1 + 0x1c);

  if (*(int *)(param_1 + 0x24) != 0) {

    sound_play_obj(*(int *)(param_1 + 0x24),iVar3);

  }

  iVar4 = objanim_select_animloop(*(undefined4 *)(param_1 + 0x28));

  *(int *)(iVar3 + 0x274) = iVar4;

  if (iVar4 != 0) {

    iVar6 = *(int *)(iVar4 + 0x100);

    iVar5 = objanim_select_animloop(*(undefined4 *)(param_1 + 0x2c));

    if (iVar5 != 0) {

      iVar1 = *(int *)(iVar5 + 0x100);

      iVar2 = *(int *)(iVar1 + 0x54);

      *(int *)(iVar6 + 0x574 + iVar2 * 4) = iVar3;

      iVar6 = objanim_select_animloop(*(undefined4 *)(param_1 + 0x30));

      if ((iVar6 != 0) && (iVar6 == DAT_00632a88)) {

        uVar7 = TextGetPtrRandom(s_SmChPHDone_00562284,4,0);

        chat_insert_name(iVar1 + 0x80,uVar7);

      }

      if (*(int *)(iVar1 + 0x54) == 2) {

        *(undefined4 *)(iVar3 + 0xf4) = *(undefined4 *)(DAT_00632ed8 + 0x10e0);

      }

      iVar8 = *(int *)(iVar5 + 0x100);

      *(uint *)(iVar5 + 0x1c8) = *(uint *)(iVar5 + 0x1c8) & 0xfffdffff | 0x800;

      *(uint *)(iVar5 + 0x1d0) = *(uint *)(iVar5 + 0x1d0) | 0xf0f;

      *(uint *)(iVar5 + 0xe0) = *(uint *)(iVar5 + 0xe0) & 0xfffffddf;

      if (*(int *)(iVar8 + 0x30) != 0) {

        *(undefined4 *)(*(int *)(iVar8 + 0x30) + 0x210) = 0;

        object_destroy(*(undefined4 *)(iVar8 + 0x30));

        *(undefined4 *)(iVar8 + 0x30) = 0;

        *(undefined4 *)(iVar8 + 0x14) = 0x41d80000;

        iVar8 = reaper_0052e4a0(iVar5);

        if (iVar8 != 0) {

          reaper_00530bd0(iVar5,0,0,0,0x14,0);

        }

      }

      *(undefined4 *)(iVar5 + 0xe4) = 0x13;

      iVar6 = ObjIsMecc(iVar6);

      if (iVar6 != 0) {

        *(undefined4 *)(iVar5 + 0x274) = *(undefined4 *)(iVar5 + 0x210);

      }

      *(undefined4 *)(iVar1 + 0x54) = 0;

      *(undefined4 *)(iVar5 + 0xec) = 0;

      iVar6 = dialog_level_is_base();

      if (iVar6 != 0) {

        iVar4 = meccbasepit_bldg_from_object(iVar4);

        if ((((iVar4 != 0) && (iVar2 == 3)) && (DAT_00632a88 != 0)) &&

           (*(int *)(iVar3 + 0x18c) == *(int *)(DAT_00632a88 + 0x18c))) {

          iVar3 = crt_rand_scaled(100);

          if (iVar3 < 0x21) {

            uVar7 = *(undefined4 *)(DAT_006330e4 + 0x50e0);

            pcVar9 = s_BAZ_CT09_00562278;

          }

          else if (iVar3 < 0x42) {

            uVar7 = *(undefined4 *)(DAT_006330e4 + 0x50e0);

            pcVar9 = s_GOR_CT09_0056226c;

          }

          else {

            uVar7 = *(undefined4 *)(DAT_006330e4 + 0x50e0);

            pcVar9 = s_REG_CT09_00562260;

          }

          teammecc_clear_mode(pcVar9,uVar7,0);

          uVar7 = FUN_00507b00(s_SmChGyropadDone_00562250,1,1);

          chat_insert_name(iVar1 + 0x80,uVar7);

        }

      }

    }

  }

  return;

}

/* ===== smartie_start_special_building @ 0x004F3DE0 ===== */
/* PS2 candidate: smartie_start_special_building (conf 0.468) */



void smartie_start_special_building

               (int param_1,int param_2,int param_3,int param_4,float *param_5,undefined4 param_6)



{

  int iVar1;

  int iVar2;

  float *pfVar3;

  float local_40;

  float local_3c;

  undefined4 local_38;

  float local_34 [4];

  undefined4 local_24;

  undefined4 local_20;

  undefined4 local_1c;

  uint local_18;

  undefined4 local_14;

  int local_10;

  undefined4 local_c;

  undefined4 local_8;

  undefined4 local_4;

  

  iVar1 = ObjIsMecc(param_4);

  iVar2 = param_2 + 0x30;

  if (iVar1 == 0) {

    iVar2 = param_2 + 0x40;

  }

  pfVar3 = local_34;

  for (iVar1 = 0xd; iVar1 != 0; iVar1 = iVar1 + -1) {

    *pfVar3 = 0.0;

    pfVar3 = pfVar3 + 1;

  }

  local_24 = IconDefWieldType(iVar2,1);

  iVar2 = object_allocate_type(local_24,0x80000000);

  local_20 = *(undefined4 *)(iVar2 + 0x188);

  local_34[0] = *param_5;

  local_34[1] = param_5[1];

  local_34[2] = param_5[2];

  local_34[3] = (float)param_6;

  if ((param_2 == 5) || (local_1c = 9, param_2 == 6)) {

    local_1c = 0;

  }

  local_14 = *(undefined4 *)(param_4 + 0x18c);

  iVar1 = ObjIsReaper(param_4);

  if ((iVar1 != 0) &&

     ((((param_2 == 5 || (param_2 == 6)) && (iVar1 = *(int *)(param_4 + 0x224), iVar1 != 0)) &&

      ((*(int *)(iVar1 + 4) == 0x4a5 && (*(int *)(iVar1 + 0x18c) == *(int *)(param_4 + 0x18c)))))))

  {

    local_18 = local_18 | 0x1000;

  }

  iVar1 = ObjIsReaper(param_4);

  if ((iVar1 == 0) || (param_2 != 1)) {

    if (param_2 == 5) {

      local_10 = 0x5ef;

      goto LAB_004f3ef6;

    }

    if (param_2 == 6) {

      local_10 = 0x5db;

      goto LAB_004f3ef6;

    }

  }

  else {

    local_18 = local_18 | 0x1000;

  }

  iVar1 = ObjIsMecc(param_4);

  local_10 = (-(uint)(iVar1 != 0) & 0xfffffffc) + 0x6e9;

LAB_004f3ef6:

  iVar1 = ObjIsReaper(param_4);

  if ((iVar1 != 0) && (param_2 == 3)) {

    local_3c = param_5[1];

    local_40 = *param_5 + 50.0;

    local_38 = 0;

    item_create_base_pickup(&local_40,0x3c,*(undefined4 *)(iVar2 + 0x188));

    local_3c = local_3c + 15.0;

    item_create_base_pickup(&local_40,0x3d,*(undefined4 *)(iVar2 + 0x188));

    local_3c = local_3c + 15.0;

    item_create_base_pickup(&local_40,0x3e,*(undefined4 *)(iVar2 + 0x188));

  }

  local_c = *(undefined4 *)(param_3 + 0x188);

  local_8 = *(undefined4 *)(param_1 + 0x188);

  local_4 = *(undefined4 *)(param_4 + 0x188);

  smartie_animselect(local_34);

  iVar2 = dialog_level_is_base();

  if (iVar2 != 0) {

    reaper_00530bd0(param_1,4,9,0,0x16,local_34);

  }

  return;

}

/* ===== FUN_004f4020 @ 0x004F4020 ===== */
void FUN_004f4020(int param_1,undefined4 param_2,int param_3,int param_4,undefined4 *param_5,

                 undefined4 param_6)



{

  undefined4 *puVar1;

  int iVar2;

  undefined4 local_1c [4];

  undefined4 local_c;

  undefined4 local_8;

  undefined4 local_4;

  

  *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 0x200;

  puVar1 = local_1c;

  for (iVar2 = 7; iVar2 != 0; iVar2 = iVar2 + -1) {

    *puVar1 = 0;

    puVar1 = puVar1 + 1;

  }

  local_1c[0] = *param_5;

  local_1c[1] = param_5[1];

  local_1c[2] = param_5[2];

  local_1c[3] = param_6;

  local_4 = param_2;

  local_c = *(undefined4 *)(param_3 + 0x188);

  local_8 = *(undefined4 *)(param_4 + 0x188);

  comm_chat_send_1(param_1,4,3,0,0x17,local_1c);

  return;

}

/* ===== smartie_from_back_to_partyhouse @ 0x004F40A0 ===== */
/* PS2 candidate: smartie_from_back_to_partyhouse (conf 0.496) */



void smartie_from_back_to_partyhouse(int param_1,int param_2,int param_3)



{

  int iVar1;

  undefined4 local_8;

  undefined4 local_4;

  

  iVar1 = reaper_0052e4a0(param_1);

  if (iVar1 != 0) {

    local_8 = *(undefined4 *)(param_2 + 0x188);

    if (param_3 == 0) {

      local_4 = 0;

    }

    else {

      local_4 = *(undefined4 *)(param_3 + 0x188);

    }

    reaper_00530bd0(param_1,0,2,0,4,&local_8);

  }

  smartie_attach_to_base(param_1,param_2,param_3);

  *(undefined4 *)(param_1 + 0xe4) = 0x37;

  smartie_make_held_object__FP6OBJECTi(param_1,0x2f2);

  ObjectSetAnim(param_1,0x41,0x20,0,0,0x3f2aaaab);

  iVar1 = reaper_0052e4a0(param_1);

  if (iVar1 != 0) {

    reaper_00530bd0(param_1,0,0,0,0xb,0);

  }

  return;

}

/* ===== smartie_release_to_bldg @ 0x004F4150 ===== */
void smartie_release_to_bldg(int param_1)



{

  int iVar1;

  int *piVar2;

  

  if (*(int *)(param_1 + 0xe8) == 10) {

    if (*(int *)(param_1 + 0x274) != 0) {

      iVar1 = meccbasepit_bldg_from_object(*(int *)(param_1 + 0x274));

      if (iVar1 != 0) {

LAB_004f418c:

        iVar1 = *(int *)(param_1 + 0x274);

LAB_004f4192:

        objtype_setup_vimp(param_1,iVar1);

        return;

      }

      iVar1 = reaperbase_bldg_from_object(*(undefined4 *)(param_1 + 0x274));

      if (iVar1 != 0) goto LAB_004f418c;

    }

    if (DAT_00632d9c != (int *)0x0) {

      piVar2 = DAT_00632d9c;

      do {

        iVar1 = piVar2[3];

        if (*(int *)(iVar1 + 0x18c) == *(int *)(param_1 + 0x18c)) goto LAB_004f4192;

        piVar2 = (int *)*piVar2;

      } while (piVar2 != (int *)0x0);

    }

    *(undefined4 *)(param_1 + 0xa4) = 0;

    *(undefined4 *)(param_1 + 0xa0) = 0;

    *(undefined4 *)(param_1 + 0xa8) = 0x43480000;

  }

  return;

}

/* ===== reaper_lock_4f @ 0x004F41F0 ===== */
void reaper_lock_4f(undefined4 param_1,int param_2,int param_3,int param_4)



{

  undefined4 local_8;

  undefined4 local_4;

  

  local_8 = *(undefined4 *)(param_2 + 0x188);

  if (param_3 == 0) {

    local_4 = 0;

  }

  else {

    local_4 = *(undefined4 *)(param_3 + 0x188);

  }

  reaper_00530bd0(param_1,0,2,0,(param_4 != 0) + '\x04',&local_8);

  return;

}

/* ===== kabutoai_select_punch_anim__FP6OBJECT_2 @ 0x004F4250 ===== */
void kabutoai_select_punch_anim__FP6OBJECT_2(undefined4 param_1)



{

  reaper_00530bd0(param_1,0,0,0,0xc,0);

  return;

}

/* ===== cspec_004f42b0 @ 0x004F42B0 ===== */
void cspec_004f42b0(int param_1,int param_2,undefined4 param_3,short *param_4)



{

  int iVar1;

  int iVar2;

  int iVar3;

  undefined4 uVar4;

  short *psVar5;

  float *pfVar6;

  float10 fVar7;

  undefined4 uVar8;

  undefined4 uStack_8;

  int iStack_4;

  

  psVar5 = param_4;

  iVar2 = *(int *)(param_1 + 0x100);

  switch(param_2) {

  case 1:

    *(float *)(param_1 + 0xa0) = (float)(int)*param_4 * 0.5;

    param_4 = (short *)(int)param_4[1];

    *(float *)(param_1 + 0xa4) = (float)(int)param_4 * 0.5;

    fVar7 = (float10)ground_get_z((float *)(param_1 + 0xa0));

    *(float *)(param_1 + 0xa8) = (float)fVar7;

    *(float *)(iVar2 + 0x18) = (float)(int)psVar5[2];

    return;

  case 2:

    *(char *)(param_1 + 0x20a) = (char)*param_4;

    *(char *)(param_1 + 0x208) = *(char *)((int)param_4 + 1);

    return;

  case 3:

    iVar2 = objanim_select_animloop(*(undefined4 *)param_4);

    if (iVar2 != 0) {

      iVar3 = *(int *)(param_1 + 0x100);

      if ((*(uint *)(param_1 + 0xe0) & 8) != 0) {

        *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xfffffff7;

        if (*(int *)(iVar3 + 0x30) != 0) {

          *(undefined4 *)(*(int *)(iVar3 + 0x30) + 0x210) = 0;

          object_destroy(*(undefined4 *)(iVar3 + 0x30));

          *(undefined4 *)(iVar3 + 0x30) = 0;

          *(undefined4 *)(iVar3 + 0x14) = 0x41d80000;

          iVar1 = reaper_0052e4a0(param_1);

          if (iVar1 != 0) {

            reaper_00530bd0(param_1,0,0,0,0x14,0);

          }

        }

        bldg_slot_action_dispatch(*(undefined4 *)(param_1 + 0x274),param_1);

        ai_clear_move_goal(param_1);

        iVar1 = meccbasepit_bldg_from_object(*(undefined4 *)(param_1 + 0x274));

        if (iVar1 == 0) {

          iVar1 = reaperbase_bldg_from_object(*(undefined4 *)(param_1 + 0x274));

          if (iVar1 != 0) {

            food_object_flag_clear

                      (param_1,*(undefined4 *)(iVar3 + 0x2c),*(undefined4 *)(iVar3 + 0x28));

          }

        }

        else {

          FUN_0040ac70(param_1,*(undefined4 *)(iVar3 + 0x2c),*(undefined4 *)(iVar3 + 0x28));

        }

        *(undefined4 *)(iVar3 + 0x2c) = 0xffffffff;

        *(undefined4 *)(iVar3 + 0x28) = 0xffffffff;

        *(undefined4 *)(param_1 + 0x274) = 0;

      }

      smartie_lock_to_player(param_1,iVar2,1);

      iVar2 = ObjIsReaper(iVar2);

      if (iVar2 == 0) {

        ObjectSetAnim(param_1,0x29,0x21,0,0,0x3f000000);

        return;

      }

      ObjectSetAnim(param_1,0x59,0x21,0,0,0x3f000000);

      return;

    }

    break;

  case 4:

  case 5:

    iVar1 = objanim_select_animloop(*(undefined4 *)param_4);

    iVar3 = *(int *)(psVar5 + 2);

    if (iVar3 == 0) {

      iVar3 = 0;

    }

    else {

      iVar3 = objanim_select_animloop(iVar3);

    }

    if (iVar1 != 0) {

      *(undefined4 *)(iVar2 + 0x54) = 0;

      if (iVar3 == 0) {

        smartie_unlock_from_player(param_1,iVar1,param_2 != 5);

        return;

      }

      smartie_attach_to_base(param_1,iVar1,iVar3);

      return;

    }

    break;

  case 7:

    *(char *)(param_1 + 0x20a) = (char)param_4[2];

    *(char *)(param_1 + 0x208) = *(char *)((int)param_4 + 5);

    *(undefined4 *)(iVar2 + 0x18) = *(undefined4 *)param_4;

    return;

  case 8:

    iVar2 = objanim_select_animloop(*(undefined4 *)param_4);

    if (iVar2 != 0) {

      objtype_setup_vimp(param_1,iVar2);

      return;

    }

    break;

  case 0xb:

    *(undefined4 *)(param_1 + 0x184) = 0x3f800000;

    *(undefined4 *)(param_1 + 0xe4) = 0x37;

    *(undefined4 *)(iVar2 + 0x18) = *(undefined4 *)(DAT_00632ed8 + 0x624);

    return;

  case 0xc:

    *(undefined4 *)(param_1 + 0x184) = 0;

    *(undefined4 *)(param_1 + 0xe4) = 0x38;

    pfVar6 = (float *)(param_1 + 0xa0);

    fVar7 = (float10)rndfloatrange(0x41a00000,0x42200000);

    *pfVar6 = (float)(fVar7 + (float10)*pfVar6);

    *(float *)(iVar2 + 0x58) = *pfVar6;

    *(undefined4 *)(iVar2 + 0x5c) = *(undefined4 *)(param_1 + 0xa4);

    *(undefined4 *)(iVar2 + 0x60) = *(undefined4 *)(param_1 + 0xa8);

    return;

  case 0xd:

    iVar2 = FUN_0052c5c0();

    psVar5 = param_4;

    if (iVar2 == 0) {

      return;

    }

    iVar3 = objanim_select_animloop(*(undefined4 *)param_4);

    if (iVar3 == 0) {

      return;

    }

    if ((*(byte *)(param_1 + 0xe0) & 8) == 0) {

      return;

    }

    if (*(int *)(param_1 + 0xe8) == 10) {

      return;

    }

    if (*(int *)(param_1 + 0xe4) != 0x37) {

      return;

    }

    if (*(float *)(iVar3 + 0x1c0) <= *(float *)(iVar3 + 0x278)) {

      return;

    }

    if ((*(uint *)(iVar3 + 0xdc) & 0x800000) != 0) {

      return;

    }

    iVar2 = ObjIsMecc(iVar3);

    if (iVar2 == 0) {

      iVar2 = *(int *)(psVar5 + 2) + 0x40;

    }

    else {

      iVar2 = *(int *)(psVar5 + 2) + 0x30;

    }

    iVar2 = item_pickup_valid_check(iVar3,iVar2,&param_2,0);

    goto LAB_004f453b;

  case 0xe:

    iVar2 = FUN_0052c5c0();

    psVar5 = param_4;

    if (iVar2 != 0) {

      return;

    }

    iVar3 = objanim_select_animloop(*(undefined4 *)param_4);

    iVar2 = iVar3;

LAB_004f453b:

    if (iVar2 != 0) {

      iVar2 = *(int *)(psVar5 + 2);

      *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 0x20;

      *(undefined4 *)(param_1 + 0x184) = 0;

      *(int *)(*(int *)(param_1 + 0x100) + 0x54) = iVar2;

      *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x274) + 0x100) + 0x574 + iVar2 * 4) = 0;

      reaper_lock_pair_4f(param_1);

      smartie_lock_to_player(param_1,iVar3,1);

      iVar1 = ObjIsReaper(iVar3);

      if (iVar1 == 0) {

        uVar4 = 0x29;

      }

      else {

        uVar4 = 0x59;

      }

      ObjectSetAnim(param_1,uVar4,0x21,0,0,0x3f000000);

      iVar1 = ObjIsReaper(iVar3);

      if (iVar1 == 0) {

        ObjectSetAnim(param_1,0x6e,0x21,0,0,0);

        smartie_make_held_object__FP6OBJECTi(param_1,0x2f3);

      }

      else {

        ObjectSetAnim(param_1,0x59,0x21,0,0,0x3f000000);

      }

      iVar1 = reaper_0052e4a0(param_1);

      if (iVar1 != 0) {

        uStack_8 = *(undefined4 *)(iVar3 + 0x188);

        iStack_4 = iVar2;

        reaper_00530bd0(param_1,0,2,0,0xe,&uStack_8);

        return;

      }

    }

    break;

  case 0xf:

    switch((char)*param_4) {

    case '\x02':

      if (*(int *)(iVar2 + 0x30) != 0) {

        *(undefined4 *)(*(int *)(iVar2 + 0x30) + 0x210) = 0;

        object_destroy(*(undefined4 *)(iVar2 + 0x30));

        *(undefined4 *)(iVar2 + 0x30) = 0;

        *(undefined4 *)(iVar2 + 0x14) = 0x41d80000;

        iVar2 = reaper_0052e4a0(param_1);

        if (iVar2 != 0) {

          reaper_00530bd0(param_1,0,0,0,0x14,0);

        }

      }

      *(undefined4 *)(param_1 + 0xe4) = 3;

      return;

    default:

      goto switchD_004f4a54_caseD_3;

    case '@':

      if (*(int *)(iVar2 + 0x30) != 0) {

        *(undefined4 *)(*(int *)(iVar2 + 0x30) + 0x210) = 0;

        object_destroy(*(undefined4 *)(iVar2 + 0x30));

        *(undefined4 *)(iVar2 + 0x30) = 0;

        *(undefined4 *)(iVar2 + 0x14) = 0x41d80000;

        iVar2 = reaper_0052e4a0(param_1);

        if (iVar2 != 0) {

          reaper_00530bd0(param_1,0,0,0,0x14,0);

        }

      }

      *(undefined4 *)(param_1 + 0xe4) = 0x1e;

      return;

    case 'A':

      uVar4 = 0x2f2;

      break;

    case 'Q':

      uVar4 = 0x314;

    }

    smartie_make_held_object__FP6OBJECTi(param_1,uVar4);

    ObjectSetAnim(param_1,0x51,0x20,0,0,0x3f2aaaab);

    *(undefined4 *)(param_1 + 0xe4) = 0x25;

    break;

  case 0x10:

    pfVar6 = (float *)(iVar2 + 0x58);

    *(float *)(iVar2 + 100) = *pfVar6;

    *(undefined4 *)(iVar2 + 0x68) = *(undefined4 *)(iVar2 + 0x5c);

    *(undefined4 *)(iVar2 + 0x6c) = *(undefined4 *)(iVar2 + 0x60);

    *pfVar6 = (float)(int)*param_4 * 0.5;

    param_4 = (short *)(int)param_4[1];

    *(float *)(iVar2 + 0x5c) = (float)(int)param_4 * 0.5;

    fVar7 = (float10)ground_get_z(pfVar6);

    *(float *)(iVar2 + 0x60) = (float)fVar7;

    ai_clear_move_goal(param_1);

    fVar7 = (float10)distancesq2d__FP3P3DT0(pfVar6,param_1 + 0xa0);

    if ((float10)4.0 <= fVar7) {

      ai_moveonly_set_goal(param_1,pfVar6);

      *(undefined4 *)(param_1 + 0xe4) = 3;

      return;

    }

    object_set_location_p3d();

    *(undefined4 *)(param_1 + 0xe4) = 3;

    return;

  case 0x11:

    uVar4 = *(undefined4 *)(param_1 + 0x274);

    *(int *)(iVar2 + 0x28) = (int)(char)*param_4;

    iVar3 = meccbasepit_bldg_from_object(uVar4);

    if (iVar3 == 0) {

      uVar8 = 0x5c;

    }

    else {

      uVar8 = 0x34;

    }

    ObjectSetAnim(param_1,uVar8,0x20,0,0,0x3e2aaaab);

    iVar3 = meccbasepit_bldg_from_object(uVar4);

    if (iVar3 != 0) {

      meccbasepit_create_food(uVar4,*(undefined4 *)(iVar2 + 0x28));

    }

    uVar4 = base_get_base_building(uVar4);

    FUN_00418770(uVar4,*(undefined4 *)(iVar2 + 0x28),param_1 + 200);

    *(undefined4 *)(param_1 + 0xe4) = 0x21;

    *(undefined4 *)(iVar2 + 4) = *(undefined4 *)(param_1 + 0xa0);

    *(undefined4 *)(iVar2 + 8) = *(undefined4 *)(param_1 + 0xa4);

    *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(param_1 + 0xa8);

    return;

  case 0x12:

    param_4 = (short *)objanim_select_animloop(*(undefined4 *)param_4);

    object_set_location_p3d(param_1,iVar2 + 0x58);

    *(undefined1 *)(param_1 + 0x20b) = 0;

    *(undefined1 *)(param_1 + 0x20a) = 0;

    *(undefined1 *)(param_1 + 0x208) = 0;

    bldg_get_refpt_worldlocdir(param_4,10,iVar2 + 0x58,param_1 + 200);

    *(undefined4 *)(iVar2 + 0x28) = 0xb;

    *(undefined4 *)(param_1 + 0xe4) = 0x27;

    *(undefined4 *)(param_1 + 0xec) = 0x40000000;

    return;

  case 0x13:

    if (*(int *)(iVar2 + 0x30) != 0) {

      *(undefined4 *)(*(int *)(iVar2 + 0x30) + 0x210) = 0;

      object_destroy(*(undefined4 *)(iVar2 + 0x30));

      *(undefined4 *)(iVar2 + 0x30) = 0;

      *(undefined4 *)(iVar2 + 0x14) = 0x41d80000;

      iVar2 = reaper_0052e4a0(param_1);

      if (iVar2 != 0) {

        reaper_00530bd0(param_1,0,0,0,0x14,0);

      }

    }

    smartie_make_held_object__FP6OBJECTi(param_1,*(undefined4 *)param_4);

    return;

  case 0x14:

    if (*(int *)(iVar2 + 0x30) != 0) {

      *(undefined4 *)(*(int *)(iVar2 + 0x30) + 0x210) = 0;

      object_destroy(*(undefined4 *)(iVar2 + 0x30));

      *(undefined4 *)(iVar2 + 0x30) = 0;

      *(undefined4 *)(iVar2 + 0x14) = 0x41d80000;

      iVar2 = reaper_0052e4a0(param_1);

      if (iVar2 != 0) {

        reaper_00530bd0(param_1,0,0,0,0x14,0);

        return;

      }

    }

    break;

  case 0x15:

    smartie_shot(2,0x461c4000,param_1,0,0,0);

    object_destroy(param_1);

    return;

  case 0x16:

    iVar2 = FUN_0052c5c0();

    if (iVar2 == 0) {

      smartie_animselect(param_4);

      return;

    }

    break;

  case 0x17:

    iVar2 = FUN_0052c5c0();

    psVar5 = param_4;

    if (iVar2 != 0) {

      iVar2 = objanim_select_animloop(*(undefined4 *)(param_4 + 8));

      iVar3 = objanim_select_animloop(*(undefined4 *)(psVar5 + 10));

      if ((iVar2 != 0) && (iVar3 != 0)) {

        smartie_start_special_building

                  (param_1,*(undefined4 *)(psVar5 + 0xc),iVar2,iVar3,psVar5,

                   *(undefined4 *)(psVar5 + 6));

        return;

      }

    }

  }

switchD_004f4a54_caseD_3:

  return;

}

/* ===== smartie_lock_to_player @ 0x004F4C00 ===== */
void smartie_lock_to_player(int param_1,undefined4 param_2,int param_3)



{

  uint *puVar1;

  int iVar2;

  undefined4 uVar3;

  int iVar4;

  char *pcVar5;

  undefined1 local_40 [28];

  undefined4 local_24;

  undefined4 local_20;

  int local_1c;

  

  iVar4 = *(int *)(param_1 + 0x100);

  ai_clear_move_goal(param_1);

  *(undefined4 *)(param_1 + 0x274) = param_2;

  *(undefined1 *)(param_1 + 0x20b) = 0;

  *(undefined1 *)(param_1 + 0x20a) = 0;

  *(undefined1 *)(param_1 + 0x208) = 0;

  *(undefined4 *)(iVar4 + 0x1c) = 0xffffffff;

  *(undefined4 *)(iVar4 + 0x20) = 0xffffffff;

  *(undefined4 *)(iVar4 + 0x24) = 0xffffffff;

  *(undefined4 *)(iVar4 + 0x28) = 0xffffffff;

  *(undefined4 *)(iVar4 + 0x18) = 0;

  *(uint *)(param_1 + 0x1c8) = *(uint *)(param_1 + 0x1c8) & 0xfffdffff | 0x800;

  *(undefined4 *)(param_1 + 0xe4) = 0x13;

  *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) & 0xf7ffffff | 0x10;

  puVar1 = (uint *)(*(int *)(param_1 + 0x274) + 0xdc);

  *puVar1 = *puVar1 | 0x800000;

  *(undefined4 *)(iVar4 + 0x94) = DAT_00632e6c;

  iVar2 = ObjIsMecc(*(undefined4 *)(param_1 + 0x274));

  if (iVar2 == 0) {

    iVar2 = ObjIsReaper(*(undefined4 *)(param_1 + 0x274));

    if (iVar2 == 0) {

      if (*(int *)(*(int *)(param_1 + 0x274) + 4) == 0xd7) {

        *(int *)(param_1 + 0x210) = *(int *)(param_1 + 0x274);

        *(undefined4 *)(param_1 + 0x214) = 1;

        *(undefined4 *)(param_1 + 0x218) = 0xb;

        *(undefined4 *)(param_1 + 0xec) = 0;

        *(float *)(iVar4 + 0x50) = *(float *)(param_1 + 0xc4) * 0.8;

        *(float *)(param_1 + 0xc4) = *(float *)(param_1 + 0xc4) * 0.8;

        playerobj_eval_refpt(*(undefined4 *)(param_1 + 0x274),0xb,local_40);

        object_set_location_p3d(param_1,local_40);

        *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 0x20;

      }

    }

    else {

      if (*(int *)(iVar4 + 0x3c) == 0) {

        local_1c = param_1;

        local_20 = 6;

        local_24 = 8;

        uVar3 = fx_get_free_effect__Fv();

        *(undefined4 *)(iVar4 + 0x3c) = uVar3;

        *(float *)(iVar4 + 0x50) = *(float *)(param_1 + 0xc4) * 0.5;

        *(float *)(param_1 + 0xc4) = *(float *)(param_1 + 0xc4) * 0.5;

      }

      if (*(int *)(iVar4 + 0xbc) == 0) {

        uVar3 = sound_get_free_sequence__Fv();

        *(undefined4 *)(iVar4 + 0xbc) = uVar3;

      }

    }

  }

  else {

    *(undefined4 *)(param_1 + 0x210) = *(undefined4 *)(param_1 + 0x274);

    *(undefined4 *)(param_1 + 0x214) = 1;

    *(undefined4 *)(param_1 + 0x218) = 10;

    *(undefined4 *)(param_1 + 0xec) = 0;

    *(float *)(iVar4 + 0x50) = *(float *)(param_1 + 0xc4) * 0.8;

    *(float *)(param_1 + 0xc4) = *(float *)(param_1 + 0xc4) * 0.8;

    playerobj_eval_refpt(*(undefined4 *)(param_1 + 0x274),10,local_40);

    object_set_location_p3d(param_1,local_40);

    sound_play_player(0x5e6,*(undefined4 *)(param_1 + 0x274));

  }

  if (*(int *)(param_1 + 0x274) == DAT_00632a88) {

    smartie_voice_trigger(param_1);

    if ((param_3 != 0) && (*(int *)(param_1 + 4) == 0xb)) {

      if (*(int *)(iVar4 + 0x54) == 0) {

        pcVar5 = s_SmChPickup_00562290;

      }

      else {

        pcVar5 = s_SmChPHPickup_0056229c;

      }

      uVar3 = TextGetPtrRandom(pcVar5,4,0);

      chat_insert_name(iVar4 + 0x80,uVar3);

    }

  }

  iVar4 = crt_rand_scaled(100);

  if (iVar4 < 0x32) {

    sound_play_obj(0x6a9,param_1);

    return;

  }

  sound_play_obj(0x6aa,param_1);

  return;

}

/* ===== smartie_find_legal_nearby_base__FP6OBJECTT0 @ 0x004F4ED0 ===== */
/* PS2 candidate: smartie_find_legal_nearby_base__FP6OBJECTT0 (conf 0.467) */



int smartie_find_legal_nearby_base__FP6OBJECTT0(int param_1,int param_2)



{

  int iVar1;

  int iVar2;

  undefined4 *puVar3;

  int iVar4;

  float10 fVar5;

  

  iVar1 = *(int *)(param_2 + 0x100);

  puVar3 = DAT_00632d9c;

  while( true ) {

    if (puVar3 == (undefined4 *)0x0) {

      return 0;

    }

    iVar2 = puVar3[3];

    iVar4 = ObjIsMecc(param_2);

    if ((((iVar4 == 0) || (iVar4 = meccbasepit_bldg_from_object(iVar2), iVar4 != 0)) &&

        ((iVar4 = ObjIsReaper(param_2), iVar4 == 0 ||

         (iVar4 = reaperbase_bldg_from_object(iVar2), iVar4 != 0)))) &&

       ((((*(int *)(iVar2 + 0x18c) == *(int *)(param_2 + 0x18c) || (*(int *)(iVar2 + 0x18c) == 0))

         && ((iVar4 = ObjIsMecc(param_2), iVar4 == 0 ||

             ((iVar4 = *(int *)(iVar1 + 0xd8), iVar4 == 0 || (iVar4 == iVar2)))))) &&

        (((iVar4 = ObjIsReaper(param_2), iVar4 == 0 ||

          ((iVar4 = *(int *)(iVar1 + 0xcfc), iVar4 == 0 || (iVar4 == iVar2)))) &&

         (fVar5 = (float10)distancesq2d__FP3P3DT0(iVar2 + 0xa0,param_1 + 0xa0),

         fVar5 <= (float10)160000.0)))))) break;

    puVar3 = (undefined4 *)*puVar3;

  }

  return iVar2;

}

/* ===== smartie_escape_reaper_grab @ 0x004F4FC0 ===== */
/* PS2 candidate: smartie_escape_reaper_grab (conf 0.505) */



void smartie_escape_reaper_grab(float param_1)



{

  int iVar1;

  int iVar2;

  float fVar3;

  float10 fVar4;

  float local_4;

  

  fVar3 = param_1;

  iVar1 = *(int *)((int)param_1 + 0x274);

  iVar2 = *(int *)((int)param_1 + 0x100);

  *(uint *)((int)param_1 + 0xd8) = *(uint *)((int)param_1 + 0xd8) & 0xffffffef;

  *(undefined4 *)((int)param_1 + 0x274) = 0;

  *(undefined4 *)((int)param_1 + 0xec) = 0x3f800000;

  *(undefined4 *)((int)param_1 + 0xe4) = 4;

  sine_cos_lookup(*(float *)(iVar1 + 200) + 180.0,&param_1,&local_4);

  *(float *)((int)fVar3 + 0x128) = param_1 * 30.0;

  *(float *)((int)fVar3 + 300) = local_4 * -30.0;

  if (*(int *)(iVar2 + 0x3c) != 0) {

    fx_delete(*(int *)(iVar2 + 0x3c));

  }

  *(undefined4 *)(iVar2 + 0x3c) = 0;

  if (*(int *)(iVar2 + 0xbc) != 0) {

    sound_interrupt_sequence(iVar2 + 0xbc);

  }

  if (*(int *)((int)fVar3 + 0xe8) == 2) {

    ObjectSetAnim(fVar3,1,0x21,0,0,0x3e2aaaab);

    *(uint *)((int)fVar3 + 0xe0) = *(uint *)((int)fVar3 + 0xe0) | 0x11;

    fVar4 = (float10)get_floor_z_point((int)fVar3 + 0xa0);

    *(float *)((int)fVar3 + 0xa8) = (float)fVar4;

    object_copy_posdirinfo(fVar3);

  }

  return;

}

/* ===== smartie_unlock_from_player @ 0x004F50C0 ===== */
void smartie_unlock_from_player(int param_1,int param_2,int param_3)



{

  int iVar1;

  int iVar2;

  undefined4 *puVar3;

  int iVar4;

  int iVar5;

  float10 fVar6;

  undefined4 uVar7;

  char *pcVar8;

  float local_8;

  float local_4;

  

  iVar5 = *(int *)(param_1 + 0x100);

  *(undefined4 *)(param_1 + 0x274) = 0;

  *(undefined4 *)(param_1 + 0x210) = 0;

  *(undefined4 *)(param_1 + 0x184) = 0;

  *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) & 0xbfffffff;

  if (*(int *)(iVar5 + 0x30) != 0) {

    *(undefined4 *)(*(int *)(iVar5 + 0x30) + 0x210) = 0;

    object_destroy(*(undefined4 *)(iVar5 + 0x30));

    *(undefined4 *)(iVar5 + 0x30) = 0;

    *(undefined4 *)(iVar5 + 0x14) = 0x41d80000;

    iVar4 = reaper_0052e4a0(param_1);

    if (iVar4 != 0) {

      reaper_00530bd0(param_1,0,0,0,0x14,0);

    }

  }

  *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xffffffdf;

  *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) & 0xfff7ffef;

  *(uint *)(param_2 + 0xdc) = *(uint *)(param_2 + 0xdc) & 0xff7fffff;

  *(uint *)(param_1 + 0x1c8) = *(uint *)(param_1 + 0x1c8) & 0xfffff7ff | 0x20000;

  sine_cos_lookup(*(float *)(param_2 + 200) + 180.0,&local_8,&local_4);

  iVar4 = *(int *)(param_1 + 0xe8);

  *(undefined4 *)(param_1 + 0xec) = 0x3f800000;

  *(float *)(param_1 + 0x128) = local_8 * 30.0;

  *(float *)(param_1 + 300) = local_4 * -30.0;

  if (iVar4 == 10) {

    *(undefined4 *)(param_1 + 0xe4) = 0x34;

    *(undefined4 *)(param_1 + 0xf0) = 0x41a00000;

  }

  else if (iVar4 == 5) {

    *(undefined4 *)(param_1 + 0xe4) = 0x52;

    smartie_make_held_object__FP6OBJECTi(param_1,0x2f2);

    for (puVar3 = DAT_00632d98; puVar3 != (undefined4 *)0x0; puVar3 = (undefined4 *)*puVar3) {

      iVar4 = puVar3[3];

      if ((*(int *)(iVar4 + 4) == 0xb) && (*(int *)(iVar4 + 0xe8) == 5)) {

        iVar1 = param_1 + 0xa0;

        iVar2 = iVar4 + 0xa0;

        fVar6 = (float10)distancesq2d__FP3P3DT0(iVar2,iVar1);

        if (fVar6 <= (float10)1600.0) {

          fVar6 = (float10)dirfcalcp3d__FP3P3DT0(iVar2,iVar1);

          main_ai_move_00401910(iVar4,(float)fVar6);

          fVar6 = (float10)dirfcalcp3d__FP3P3DT0(iVar1,iVar2);

          main_ai_move_00401910(param_1,(float)fVar6);

        }

      }

    }

  }

  else {

    if (iVar4 == 2) {

      ObjectSetAnim(param_1,1,0x21,0,0,0x3e2aaaab);

      *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 0x11;

      fVar6 = (float10)get_floor_z_point(param_1 + 0xa0);

      *(float *)(param_1 + 0xa8) = (float)fVar6;

      object_copy_posdirinfo(param_1);

    }

    *(undefined4 *)(param_1 + 0xe4) = 4;

  }

  iVar4 = ObjIsReaper(param_2);

  if (iVar4 == 0) {

    iVar4 = ObjIsMecc(param_2);

    if (iVar4 != 0) {

      uVar7 = 0x5e5;

      goto LAB_004f5334;

    }

  }

  else {

    if (*(int *)(iVar5 + 0x3c) != 0) {

      fx_delete(*(int *)(iVar5 + 0x3c));

      *(undefined4 *)(iVar5 + 0x3c) = 0;

    }

    if (*(int *)(iVar5 + 0xbc) != 0) {

      sound_interrupt_sequence(iVar5 + 0xbc);

    }

    uVar7 = 0x39b;

LAB_004f5334:

    sound_play_player(uVar7,param_2);

  }

  *(undefined4 *)(iVar5 + 0x54) = 0;

  *(float *)(param_1 + 0xc4) = *(float *)(iVar5 + 0x50) + *(float *)(param_1 + 0xc4);

  iVar4 = fx_create(param_2);

  if (((iVar4 != 0) && (*(int *)(iVar5 + 0x54) == 0)) && (*(int *)(param_1 + 4) == 0xb)) {

    if (param_3 == 1) {

      pcVar8 = s_SmChDropoff_005622c0;

    }

    else {

      if (param_3 != 5) goto LAB_004f539d;

      pcVar8 = s_SmChDropBase_005622cc;

    }

    uVar7 = TextGetPtrRandom(pcVar8,4,0);

    chat_insert_name(iVar5 + 0x80,uVar7);

  }

LAB_004f539d:

  iVar5 = crt_rand_scaled(100);

  if (iVar5 < 0x19) {

    sound_play_obj(0x6ab,param_1);

    return;

  }

  if (iVar5 < 0x32) {

    sound_play_obj(0x6ac,param_1);

    return;

  }

  if (iVar5 < 0x4b) {

    sound_play_obj(0x6ad,param_1);

    return;

  }

  sound_play_obj(0x6ae,param_1);

  return;

}

/* ===== smartie_attach_to_base @ 0x004F5410 ===== */
/* PS2 candidate: smartie_attach_to_base (conf 0.598) */



void smartie_attach_to_base(int param_1,undefined4 param_2,undefined4 param_3)



{

  int iVar1;

  int iVar2;

  undefined4 uVar3;

  undefined4 uVar4;

  

  iVar2 = *(int *)(param_1 + 0x100);

  smartie_unlock_from_player(param_1,param_2,5);

  uVar3 = 0;

  *(undefined4 *)(param_1 + 0x274) = param_3;

  *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 8;

  *(undefined4 *)(param_1 + 0xec) = 0;

  *(undefined4 *)(param_1 + 0x128) = 0;

  *(undefined4 *)(param_1 + 300) = 0;

  *(undefined4 *)(param_1 + 0x278) = 0;

  iVar1 = base_has_partyhouse(param_3);

  if (iVar1 == 0) {

    *(undefined4 *)(param_1 + 0xe4) = 0x24;

  }

  else {

    *(undefined4 *)(param_1 + 0xe4) = 0x1e;

  }

  *(undefined4 *)(iVar2 + 0x1c) = 0xffffffff;

  *(undefined4 *)(iVar2 + 0x20) = 0xffffffff;

  *(undefined4 *)(iVar2 + 0x24) = 0xffffffff;

  iVar1 = fx_create(param_3);

  if (iVar1 == 0) goto LAB_004f55b7;

  iVar1 = dialog_level_is_base();

  if (iVar1 != 0) {

    iVar1 = game_mode_set6_check(DAT_00632f18);

    if (iVar1 == 0) goto LAB_004f55b7;

  }

  iVar1 = meccbasepit_bldg_from_object(param_3);

  if (iVar1 == 0) {

    iVar1 = reaperbase_bldg_from_object(param_3);

    if (iVar1 == 0) goto LAB_004f55b7;

    iVar1 = base_slot_ready_check(param_3,0);

    if (iVar1 == 0) {

LAB_004f5569:

      iVar1 = base_slot_ready_check(param_3,1);

      if (iVar1 == 0) goto LAB_004f55b7;

      iVar1 = base_slot_built_check(param_3,9);

      if (iVar1 != 0) goto LAB_004f55b7;

      uVar3 = 1;

    }

    else {

      iVar1 = base_slot_built_check(param_3,8);

      if (iVar1 != 0) goto LAB_004f5569;

    }

    iVar1 = base_slot_built_check(param_3,uVar3);

    if (iVar1 == 0) {

      bldg_spawn_by_type(param_3,uVar3);

    }

    uVar4 = *(undefined4 *)(param_1 + 0x274);

  }

  else {

    iVar1 = base_slot_ready_check(param_3,0);

    if (iVar1 == 0) {

LAB_004f54ef:

      iVar1 = base_slot_ready_check(param_3,1);

      if (iVar1 == 0) goto LAB_004f55b7;

      iVar1 = base_slot_built_check(param_3,0xe);

      if (iVar1 != 0) goto LAB_004f55b7;

      uVar3 = 1;

    }

    else {

      iVar1 = base_slot_built_check(param_3,0xd);

      if (iVar1 != 0) goto LAB_004f54ef;

      mission_replenish_food__Fv_2();

    }

    iVar1 = base_slot_built_check(param_3,uVar3);

    if (iVar1 == 0) {

      bldg_spawn_by_type(param_3,uVar3);

    }

    uVar4 = *(undefined4 *)(param_1 + 0x274);

  }

  reaper_lock_short(uVar4,uVar3,param_1,1);

LAB_004f55b7:

  *(undefined4 *)(iVar2 + 0x1c) = 0xffffffff;

  *(undefined4 *)(iVar2 + 0x28) = 0xffffffff;

  *(undefined4 *)(iVar2 + 0x18) = *(undefined4 *)(DAT_00632ed8 + 0x624);

  *(uint *)(param_1 + 0x1c8) = *(uint *)(param_1 + 0x1c8) & 0xfffdffff | 0x800;

  iVar2 = ObjIsMecc(param_2);

  if (iVar2 != 0) {

    sound_play_player(0x5e4);

    return;

  }

  iVar2 = ObjIsReaper(param_2);

  if (iVar2 != 0) {

    sound_play_player(0x39b,param_2);

  }

  return;

}

/* ===== reaper_lock_pair_4f @ 0x004F5630 ===== */
void reaper_lock_pair_4f(int param_1)



{

  int iVar1;

  int iVar2;

  

  iVar1 = *(int *)(param_1 + 0x100);

  if ((*(uint *)(param_1 + 0xe0) & 8) != 0) {

    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xfffffff7;

    if (*(int *)(iVar1 + 0x30) != 0) {

      *(undefined4 *)(*(int *)(iVar1 + 0x30) + 0x210) = 0;

      object_destroy(*(undefined4 *)(iVar1 + 0x30));

      *(undefined4 *)(iVar1 + 0x30) = 0;

      *(undefined4 *)(iVar1 + 0x14) = 0x41d80000;

      iVar2 = reaper_0052e4a0(param_1);

      if (iVar2 != 0) {

        reaper_00530bd0(param_1,0,0,0,0x14,0);

      }

    }

    bldg_slot_action_dispatch(*(undefined4 *)(param_1 + 0x274),param_1);

    ai_clear_move_goal(param_1);

    iVar2 = meccbasepit_bldg_from_object(*(undefined4 *)(param_1 + 0x274));

    if (iVar2 == 0) {

      iVar2 = reaperbase_bldg_from_object(*(undefined4 *)(param_1 + 0x274));

      if (iVar2 != 0) {

        food_object_flag_clear(param_1,*(undefined4 *)(iVar1 + 0x2c),*(undefined4 *)(iVar1 + 0x28));

      }

    }

    else {

      FUN_0040ac70(param_1,*(undefined4 *)(iVar1 + 0x2c),*(undefined4 *)(iVar1 + 0x28));

    }

    *(undefined4 *)(iVar1 + 0x2c) = 0xffffffff;

    *(undefined4 *)(iVar1 + 0x28) = 0xffffffff;

    *(undefined4 *)(param_1 + 0x274) = 0;

  }

  return;

}

/* ===== fx_reaper_bubble_create @ 0x004F5710 ===== */
/* PS2 candidate: smartie_reaper_grab (conf 0.374) */



void fx_reaper_bubble_create(int param_1,undefined4 param_2)



{

  int iVar1;

  int iVar2;

  undefined4 uVar3;

  undefined4 local_40;

  undefined4 local_3c;

  float local_38;

  undefined4 local_24;

  undefined4 local_20;

  int local_1c;

  

  iVar1 = *(int *)(param_1 + 0x100);

  if (*(int *)(param_1 + 0xe4) != 0x32) {

    if ((*(uint *)(param_1 + 0xe0) & 8) != 0) {

      *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xfffffff7;

      if (*(int *)(iVar1 + 0x30) != 0) {

        *(undefined4 *)(*(int *)(iVar1 + 0x30) + 0x210) = 0;

        object_destroy(*(undefined4 *)(iVar1 + 0x30));

        *(undefined4 *)(iVar1 + 0x30) = 0;

        *(undefined4 *)(iVar1 + 0x14) = 0x41d80000;

        iVar2 = reaper_0052e4a0(param_1);

        if (iVar2 != 0) {

          reaper_00530bd0(param_1,0,0,0,0x14,0);

        }

      }

      bldg_slot_action_dispatch(*(undefined4 *)(param_1 + 0x274),param_1);

      ai_clear_move_goal(param_1);

      iVar2 = meccbasepit_bldg_from_object(*(undefined4 *)(param_1 + 0x274));

      if (iVar2 == 0) {

        iVar2 = reaperbase_bldg_from_object(*(undefined4 *)(param_1 + 0x274));

        if (iVar2 != 0) {

          food_object_flag_clear

                    (param_1,*(undefined4 *)(iVar1 + 0x2c),*(undefined4 *)(iVar1 + 0x28));

        }

      }

      else {

        FUN_0040ac70(param_1,*(undefined4 *)(iVar1 + 0x2c),*(undefined4 *)(iVar1 + 0x28));

      }

      *(undefined4 *)(iVar1 + 0x2c) = 0xffffffff;

      *(undefined4 *)(iVar1 + 0x28) = 0xffffffff;

      *(undefined4 *)(param_1 + 0x274) = 0;

    }

    *(undefined4 *)(param_1 + 0x274) = param_2;

    *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) | 0x10;

    *(undefined1 *)(param_1 + 0x20b) = 0;

    *(undefined1 *)(param_1 + 0x20a) = 0;

    *(undefined1 *)(param_1 + 0x208) = 0;

    *(undefined4 *)(iVar1 + 4) = *(undefined4 *)(param_1 + 0xa0);

    *(undefined4 *)(iVar1 + 8) = *(undefined4 *)(param_1 + 0xa4);

    *(undefined4 *)(iVar1 + 0xc) = *(undefined4 *)(param_1 + 0xa8);

    *(undefined4 *)(iVar1 + 0x1c) = 0xffffffff;

    *(undefined4 *)(iVar1 + 0x20) = 0xffffffff;

    *(undefined4 *)(iVar1 + 0x24) = 0xffffffff;

    *(undefined4 *)(iVar1 + 0x28) = 0xffffffff;

    *(undefined4 *)(iVar1 + 0x18) = 0;

    local_40 = *(undefined4 *)(param_1 + 0xa0);

    local_3c = *(undefined4 *)(param_1 + 0xa4);

    local_38 = *(float *)(param_1 + 0xa8) + 3.0;

    *(undefined4 *)(param_1 + 0xe4) = 0x32;

    object_set_location_p3d(param_1,&local_40);

    *(float *)(param_1 + 200) = *(float *)(*(int *)(param_1 + 0x274) + 200) + 180.0;

    if (*(int *)(iVar1 + 0x3c) == 0) {

      local_1c = param_1;

      local_20 = 6;

      local_24 = 8;

      uVar3 = fx_get_free_effect__Fv();

      *(undefined4 *)(iVar1 + 0x3c) = uVar3;

      *(float *)(iVar1 + 0x50) = *(float *)(param_1 + 0xc4) * 0.5;

      *(float *)(param_1 + 0xc4) = *(float *)(param_1 + 0xc4) * 0.5;

    }

    *(undefined4 *)(iVar1 + 0x40) = *(undefined4 *)(DAT_00632ed8 + 0x7e0);

    *(undefined4 *)(iVar1 + 0x44) = *(undefined4 *)(DAT_00632ed8 + 0x7dc);

    if (*(int *)(iVar1 + 0xbc) == 0) {

      uVar3 = sound_get_free_sequence__Fv();

      *(undefined4 *)(iVar1 + 0xbc) = uVar3;

    }

    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xffffffee;

  }

  return;

}

/* ===== smartie_check_follow__FP6OBJECTf @ 0x004F5950 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* PS2 candidate: smartie_check_follow__FP6OBJECTf (conf 0.469) */



int smartie_check_follow__FP6OBJECTf(int param_1,float param_2)



{

  char cVar1;

  int iVar2;

  undefined4 *puVar3;

  int iVar4;

  char *pcVar5;

  char *pcVar6;

  float10 fVar7;

  

  iVar2 = *(int *)(param_1 + 0x100);

  if (*(int *)(param_1 + 0xe8) == 7) {

    return 0;

  }

  if (*(int *)(param_1 + 0x220) != 0) {

    *(undefined4 *)(iVar2 + 0x38) = 0;

  }

  *(undefined4 *)(param_1 + 0x220) = 0;

  fVar7 = (float10)FUN_00518b70(param_1,0);

  fVar7 = (float10)*(float *)(iVar2 + 0x38) - fVar7;

  *(float *)(iVar2 + 0x38) = (float)fVar7;

  if ((float10)0.0 < fVar7) {

    return 0;

  }

  *(undefined4 *)(iVar2 + 0x38) = 0x40000000;

  puVar3 = DAT_00632d6c;

  if ((*(byte *)(param_1 + 0xe0) & 8) != 0) {

    *(undefined4 *)(iVar2 + 0x38) = 0x3f4ccccd;

    puVar3 = DAT_00632d6c;

  }

  do {

    if (puVar3 == (undefined4 *)0x0) {

      return 0;

    }

    iVar2 = puVar3[3];

    if ((((-1 < (char)((uint)*(undefined4 *)(iVar2 + 0xd8) >> 8)) &&

         (((iVar4 = ObjIsMecc(iVar2), iVar4 != 0 || (iVar4 = ObjIsReaper(iVar2), iVar4 != 0)) &&

          (*(float *)(iVar2 + 0x278) < *(float *)(iVar2 + 0x1c0))))) &&

        (((((*(int *)(param_1 + 0xe8) == 10 && (*(int *)(param_1 + 0xe4) == 0x34)) &&

           (*(int *)(iVar2 + 0x18c) == *(int *)(param_1 + 0x18c))) ||

          ((((*(uint *)(iVar2 + 0xdc) & 0x800000) == 0 &&

            (((iVar4 = ObjIsMecc(iVar2), iVar4 == 0 || ((*(uint *)(iVar2 + 0xdc) & 0x400000) == 0))

             || (iVar4 = SpecialWeaponIdGet__FP6OBJECT(iVar2), iVar4 != 10)))) &&

           (((iVar4 = ObjIsReaper(iVar2), iVar4 == 0 ||

             (*(int *)(*(int *)(iVar2 + 0x100) + 0xe2c) == 0)) &&

            ((iVar4 = ObjIsMecc(iVar2), iVar4 == 0 || ((*(uint *)(iVar2 + 0xe0) & 0x2000000) == 0)))

            ))))) &&

         (((((*(byte *)(param_1 + 0xe0) & 8) == 0 || (*(int *)(param_1 + 0x274) == 0)) ||

           (*(int *)(*(int *)(param_1 + 0x274) + 0x18c) != *(int *)(iVar2 + 0x18c))) &&

          ((*(int *)(param_1 + 0xe8) != 10 ||

           (((((DAT_00632f08 < 1 || (DAT_00632f30 <= 0.0)) &&

              ((iVar4 = ObjIsMecc(iVar2), iVar4 == 0 ||

               (*(int *)(*(int *)(iVar2 + 0x100) + 0xd8) != 0)))) &&

             ((iVar4 = ObjIsReaper(iVar2), iVar4 == 0 ||

              (*(int *)(*(int *)(iVar2 + 0x100) + 0xcfc) != 0)))) &&

            ((*(int *)(param_1 + 0xe4) != 0x33 ||

             (*(int *)(iVar2 + 0x18c) != *(int *)(param_1 + 0x18c))))))))))))) &&

       (fVar7 = (float10)FUN_0050a610(iVar2 + 0xa0,param_1 + 0xa0),

       (float10)param_2 * (float10)param_2 < fVar7 == ((float10)param_2 * (float10)param_2 == fVar7)

       )) {

      if ((*(int *)(param_1 + 0xe8) != 10) ||

         ((((iVar4 = ObjIsReaper(iVar2), iVar4 == 0 || (*(int *)(iVar2 + 0x210) == 0)) ||

           (iVar4 = ObjIsJetski(*(int *)(iVar2 + 0x210)), iVar4 == 0)) &&

          ((iVar4 = ObjIsMecc(iVar2), iVar4 == 0 || (iVar4 = mecc_in_gyro(iVar2), iVar4 == 0)))))) {

        return iVar2;

      }

      if (DAT_00632a88 == iVar2) {

        pcVar5 = (char *)FUN_00507b00(s_FlagHintDriveGyro_0055bccc);

        pcVar6 = &DAT_00632c10;

        do {

          cVar1 = *pcVar5;

          pcVar5 = pcVar5 + 1;

          *pcVar6 = cVar1;

          pcVar6 = pcVar6 + 1;

        } while (cVar1 != '\0');

        _DAT_00632d10 = 0x3f800000;

      }

    }

    puVar3 = (undefined4 *)*puVar3;

  } while( true );

}

/* ===== smartie_board_player__FP6OBJECTT0i @ 0x004F5C10 ===== */
/* PS2 candidate: smartie_board_player__FP6OBJECTT0i (conf 0.656) */



void smartie_board_player__FP6OBJECTT0i(int param_1,int param_2,undefined4 param_3)



{

  char cVar1;

  int iVar2;

  char *pcVar3;

  undefined4 uVar4;

  uint uVar5;

  int iVar6;

  char *pcVar7;

  undefined4 local_108;

  undefined4 local_104;

  char local_100 [256];

  

  if (((*(int *)(param_1 + 0xe8) != 10) && ((*(byte *)(param_1 + 0xe0) & 8) != 0)) &&

     (iVar2 = dialog_level_is_base(), iVar2 != 0)) {

    pcVar3 = (char *)(*(int *)(param_1 + 0x100) + 0x80);

    iVar2 = -(int)pcVar3;

    do {

      cVar1 = *pcVar3;

      pcVar3[(int)(local_100 + iVar2)] = cVar1;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

    iVar2 = -1;

    pcVar3 = local_100;

    do {

      pcVar7 = pcVar3;

      if (iVar2 == 0) break;

      iVar2 = iVar2 + -1;

      pcVar7 = pcVar3 + 1;

      cVar1 = *pcVar3;

      pcVar3 = pcVar7;

    } while (cVar1 != '\0');

    *(undefined2 *)(pcVar7 + -1) = DAT_00555928;

    pcVar7[1] = DAT_0055592a;

    uVar4 = comm_player_name4(param_2);

    uVar4 = TextGetPtrRandom(s_SmChKidnapped_005622dc,uVar4);

    uVar5 = 0xffffffff;

    pcVar3 = local_100;

    do {

      if (uVar5 == 0) break;

      uVar5 = uVar5 - 1;

      cVar1 = *pcVar3;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

    crt_sprintf(local_100 + (~uVar5 - 1),uVar4);

    comm_audio_volume_user(local_100,4,0,0);

  }

  if (*(int *)(param_1 + 0xe8) == 5) {

    if (*(int *)(param_1 + 0xf4) != 0) {

      fx_delete(*(int *)(param_1 + 0xf4));

    }

    iVar2 = *(int *)(param_1 + 0x210);

    *(undefined4 *)(param_1 + 0xf4) = 0;

    if ((iVar2 != 0) && (*(int *)(iVar2 + 4) == 0x3e9)) {

      iVar6 = 0;

      do {

        if ((*(uint *)(iVar2 + 0xf4) & 1 << ((byte)iVar6 & 0x1f)) != 0) {

          *(uint *)(iVar2 + 0xf4) = ~(1 << ((byte)iVar6 & 0x1f)) & *(uint *)(iVar2 + 0xf4);

          break;

        }

        iVar6 = iVar6 + 1;

      } while (iVar6 < 8);

      if (*(int *)(*(int *)(param_1 + 0x210) + 0xf4) == 0) {

        iVar2 = 8;

        do {

          iVar6 = object_allocate_type(0xb,0x80000000);

          *(undefined4 *)(iVar6 + 0xe8) = 5;

          *(uint *)(iVar6 + 0xdc) = *(uint *)(iVar6 + 0xdc) | *(uint *)(param_1 + 0xdc) & 0xf;

          iVar2 = iVar2 + -1;

          *(uint *)(iVar6 + 0xd8) = *(uint *)(iVar6 + 0xd8) | *(uint *)(param_1 + 0xd8) & 0x400;

        } while (iVar2 != 0);

      }

    }

  }

  iVar2 = *(int *)(param_1 + 0x100);

  if ((*(uint *)(param_1 + 0xe0) & 8) != 0) {

    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xfffffff7;

    if (*(int *)(iVar2 + 0x30) != 0) {

      *(undefined4 *)(*(int *)(iVar2 + 0x30) + 0x210) = 0;

      object_destroy(*(undefined4 *)(iVar2 + 0x30));

      *(undefined4 *)(iVar2 + 0x30) = 0;

      *(undefined4 *)(iVar2 + 0x14) = 0x41d80000;

      iVar6 = reaper_0052e4a0(param_1);

      if (iVar6 != 0) {

        reaper_00530bd0(param_1,0,0,0,0x14,0);

      }

    }

    bldg_slot_action_dispatch(*(undefined4 *)(param_1 + 0x274),param_1);

    ai_clear_move_goal(param_1);

    iVar6 = meccbasepit_bldg_from_object(*(undefined4 *)(param_1 + 0x274));

    if (iVar6 == 0) {

      iVar6 = reaperbase_bldg_from_object(*(undefined4 *)(param_1 + 0x274));

      if (iVar6 != 0) {

        food_object_flag_clear(param_1,*(undefined4 *)(iVar2 + 0x2c),*(undefined4 *)(iVar2 + 0x28));

      }

    }

    else {

      FUN_0040ac70(param_1,*(undefined4 *)(iVar2 + 0x2c),*(undefined4 *)(iVar2 + 0x28));

    }

    *(undefined4 *)(iVar2 + 0x2c) = 0xffffffff;

    *(undefined4 *)(iVar2 + 0x28) = 0xffffffff;

    *(undefined4 *)(param_1 + 0x274) = 0;

  }

  smartie_lock_to_player(param_1,param_2,param_3);

  iVar2 = ObjIsReaper(param_2);

  if (iVar2 == 0) {

    uVar4 = 0x29;

  }

  else {

    uVar4 = 0x59;

  }

  ObjectSetAnim(param_1,uVar4,0x21,0,0,0x3f000000);

  iVar2 = reaper_0052e4a0(param_1);

  if (iVar2 != 0) {

    local_108 = *(undefined4 *)(param_2 + 0x188);

    local_104 = 0;

    reaper_00530bd0(param_1,0,2,0,3,&local_108);

  }

  return;

}

/* ===== meccbaseitem_shot @ 0x004F6090 ===== */
/* PS2 candidate: meccbaseitem_shot (conf 0.407) */



int meccbaseitem_shot(int param_1,undefined4 param_2)



{

  int iVar1;

  int iVar2;

  int iVar3;

  float10 fVar4;

  

  iVar3 = *(int *)(param_1 + 0x100);

  iVar1 = meccbasepit_bldg_from_object(param_2);

  if (iVar1 == 0) {

    iVar3 = reaperbase_bldg_from_object(*(undefined4 *)(param_1 + 0x274));

    iVar1 = 1;

    if (iVar3 != 0) {

      if ((*(byte *)(param_1 + 0x30) & 2) == 0) {

        return *(int *)(param_1 + 0x10);

      }

      fVar4 = (float10)bldg_get_energy(param_2);

      if ((float10)0.0 < fVar4) {

        if (((0x5c < *(int *)(param_1 + 0x10)) && (*(int *)(param_1 + 0x10) < 0x60)) &&

           (iVar3 = crt_rand_scaled(100), 0x20 < iVar3)) {

          iVar3 = crt_rand_scaled(100);

          return (0x42 < iVar3) + 0x5e;

        }

        return 0x5d;

      }

      iVar1 = 0x6b;

    }

  }

  else {

    fVar4 = (float10)bldg_get_energy(param_2);

    if (fVar4 <= (float10)0.0) {

      iVar1 = *(int *)(param_1 + 0x10);

      if (((*(byte *)(param_1 + 0x30) & 2) != 0) && (iVar1 = 0x3f, *(int *)(param_1 + 0x10) == 0x3f)

         ) {

        iVar3 = crt_rand_scaled(100);

        return ((0x31 < iVar3) - 1 & 0xe) + 0x31;

      }

    }

    else {

      iVar1 = *(int *)(param_1 + 0x10);

      if (iVar1 == 0x3f) {

        iVar2 = FUN_0040b1d0(param_2,*(undefined4 *)(iVar3 + 0x28));

        iVar1 = *(int *)(param_1 + 0x100);

        if ((*(int *)(iVar1 + 0x30) == 0) && (iVar2 != 0)) {

          *(int *)(iVar1 + 0x30) = iVar2;

          playerobj_eval_refpt(param_1,0,iVar2 + 0xa0);

          object_copy_posdirinfo(*(undefined4 *)(iVar1 + 0x30));

          *(undefined4 *)(*(int *)(iVar1 + 0x30) + 0x18c) = *(undefined4 *)(param_1 + 0x18c);

          *(int *)(*(int *)(iVar1 + 0x30) + 0x210) = param_1;

          *(undefined4 *)(*(int *)(iVar1 + 0x30) + 0x214) = 0;

          *(undefined4 *)(*(int *)(iVar1 + 0x30) + 0x218) = 0;

          iVar2 = *(int *)(iVar1 + 0x30);

          *(undefined4 *)(iVar1 + 0x14) = *(undefined4 *)(iVar2 + 0xc4);

          *(uint *)(iVar2 + 0xd8) = *(uint *)(iVar2 + 0xd8) | 0x400000;

        }

        if (*(int *)(iVar3 + 0x30) == 0) {

          return 0x3f;

        }

        iVar1 = (*(int *)(*(int *)(iVar3 + 0x30) + 4) == 0x2f6) + 0x3d;

        iVar3 = crt_rand_scaled(100);

        if (iVar3 < 0x32) {

          sound_play_obj(0x6b7,param_1);

          return iVar1;

        }

        sound_play_obj(0x6b8,param_1);

        return iVar1;

      }

      if ((*(byte *)(param_1 + 0x30) & 2) != 0) {

        if (iVar1 != 0x3a) {

          if (iVar1 < 0x3d) {

            return 0x3f;

          }

          if (0x3e < iVar1) {

            return 0x3f;

          }

          return 0x3a;

        }

        iVar1 = crt_rand_scaled(100);

        if (0x4f < iVar1) {

          iVar3 = *(int *)(param_1 + 0x100);

          if (*(int *)(iVar3 + 0x30) != 0) {

            *(undefined4 *)(*(int *)(iVar3 + 0x30) + 0x210) = 0;

            object_destroy(*(undefined4 *)(iVar3 + 0x30));

            *(undefined4 *)(iVar3 + 0x30) = 0;

            *(undefined4 *)(iVar3 + 0x14) = 0x41d80000;

            iVar3 = reaper_0052e4a0(param_1);

            if (iVar3 != 0) {

              reaper_00530bd0(param_1,0,0,0,0x14,0);

            }

          }

          return 0x3c;

        }

        iVar1 = 1;

        if (*(int *)(iVar3 + 0x30) != 0) {

          return (*(int *)(*(int *)(iVar3 + 0x30) + 4) == 0x2f6) + 0x3d;

        }

      }

    }

  }

  return iVar1;

}

/* ===== cspec_004f6330 @ 0x004F6330 ===== */
void cspec_004f6330(int param_1)



{

  uint uVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  float fVar5;

  float fVar6;

  int *piVar7;

  int iVar8;

  float10 fVar9;

  undefined4 uVar10;

  float fStack_18;

  float fStack_14;

  float fStack_10;

  float fStack_c;

  float fStack_8;

  float fStack_4;

  

  iVar3 = *(int *)(param_1 + 0x100);

  iVar4 = *(int *)(param_1 + 0x274);

  iVar8 = (-(uint)((*(uint *)(param_1 + 0xd8) & 0x800) != 0) & 0x68) + 1;

  fStack_10 = 0.16666667;

  fStack_14 = 0.0;

  fStack_c = 0.0;

  fStack_18 = 4.62428e-44;

  if ((((*(float *)(param_1 + 0x278) < *(float *)(param_1 + 0x1c0)) &&

       ((*(uint *)(param_1 + 0xd8) & 0x8000000) != 0)) && (*(int *)(param_1 + 0x210) == 0)) &&

     ((iVar4 == 0 || (iVar2 = ObjIsReaper(iVar4), iVar2 == 0)))) {

    if (*(int *)(param_1 + 0xe8) == 10) {

      anim_select_user(param_1,0x5a);

      return;

    }

    anim_select_user(param_1,0x84);

    if (*(int *)(iVar3 + 0xc0) != 0) {

      return;

    }

    sound_play_obj(0x19c,param_1);

    *(undefined4 *)(iVar3 + 0xc0) = 1;

    return;

  }

  if (*(int *)(iVar3 + 0xc0) != 0) {

    sound_stop_obj(0x19c,param_1);

    *(undefined4 *)(iVar3 + 0xc0) = 0;

  }

  if ((*(int *)(param_1 + 0x10) == 0x58) && ((*(byte *)(param_1 + 0x30) & 2) == 0)) {

    return;

  }

  iVar2 = fx_create(param_1);

  if (iVar2 != 0) {

    if ((*(int *)(param_1 + 0xe8) == 8) && ((*(byte *)(param_1 + 0x30) & 2) != 0)) {

      iVar2 = crt_rand_scaled(1000);

      if (iVar2 < 100) {

        if (iVar2 < 0x32) {

          uVar10 = 0x711;

        }

        else {

          uVar10 = 0x712;

        }

        sound_play_obj(uVar10,param_1);

        fVar5 = *(float *)(param_1 + 0xc4);

        uVar10 = 0x31;

      }

      else {

        fVar5 = *(float *)(param_1 + 0xc4);

        uVar10 = 0x3f;

      }

      ObjectSetAnim(param_1,uVar10,0x21,0,fVar5 * 0.0,0x3e2aaaab);

    }

    if ((*(byte *)(param_1 + 0xe0) & 1) != 0) {

      return;

    }

    if (*(int *)(param_1 + 0xe4) == 0) {

      return;

    }

    if (*(int *)(param_1 + 0x210) != 0) {

      iVar2 = *(int *)(*(int *)(param_1 + 0x210) + 0x1e0);

      if (iVar2 == 1) {

        return;

      }

      if (iVar2 == 0x4c) {

        return;

      }

    }

    switch(*(int *)(param_1 + 0xe4)) {

    case 0:

      iVar8 = 1;

      break;

    case 1:

      if ((*(byte *)(param_1 + 0x30) & 2) == 0) {

LAB_004f6b37:

        iVar8 = *(int *)(param_1 + 0x10);

      }

      else {

        sine_cos_lookup(*(undefined4 *)(param_1 + 200),&fStack_8,&fStack_4);

        *(undefined4 *)(param_1 + 0xec) = 0;

        iVar8 = 1;

        *(undefined4 *)(param_1 + 0xe4) = 3;

        *(float *)(param_1 + 0xa0) = fStack_8 * 10.0 + *(float *)(param_1 + 0xa0);

        *(float *)(param_1 + 0xa4) = *(float *)(param_1 + 0xa4) - fStack_4 * 10.0;

      }

      break;

    default:

      if (((*(uint *)(param_1 + 0xd8) & 0x8000000) == 0) ||

         ((*(int *)(param_1 + 0x274) != 0 &&

          (iVar4 = ObjIsReaper(*(int *)(param_1 + 0x274)), iVar4 != 0)))) {

        if (0.0 <= *(float *)(param_1 + 0x108)) {

          if (*(float *)(param_1 + 0x10c) == 0.0) {

            if ((*(byte *)(param_1 + 0x30) & 2) != 0) {

              iVar8 = (-(uint)((*(uint *)(param_1 + 0xd8) & 0x800) != 0) & 0x68) + 1;

            }

          }

          else {

            if ((*(int *)(param_1 + 0xe4) == 0x22) &&

               (iVar4 = meccbasepit_bldg_from_object(*(undefined4 *)(param_1 + 0x274)), iVar4 != 0))

            {

              iVar8 = 0x4b;

              fStack_14 = *(float *)(param_1 + 0x10c) * 0.75;

            }

            else {

              fStack_14 = *(float *)(param_1 + 0x1b4);

              iVar8 = 2;

            }

            fStack_c = 1.4013e-45;

            ObjectUpdateSpeedDist(param_1,fStack_14 * *(float *)(param_1 + 0xc4));

          }

        }

        else {

          iVar4 = fx_create(param_1);

          if ((((iVar4 != 0) && (*(int *)(param_1 + 0xe8) != 10)) &&

              (*(float *)(param_1 + 0x108) < -50.0)) &&

             (*(float *)(param_1 + 0xb4) == *(float *)(param_1 + 0xc0))) {

            obj_damage_apply(3,*(float *)(param_1 + 0x1c0) + 1.0,param_1,0,0,0);

          }

          iVar8 = 0x73;

        }

      }

      else {

        iVar8 = 0x5a;

      }

      break;

    case 6:

      iVar8 = 10;

      fStack_18 = 4.48416e-44;

      break;

    case 7:

      iVar8 = 9;

      fStack_18 = 4.48416e-44;

      break;

    case 0x13:

      if ((*(byte *)(param_1 + 0x30) & 2) == 0) {

        iVar8 = *(int *)(param_1 + 0x10);

      }

      else if (*(int *)(param_1 + 0x274) != 0) {

        iVar4 = ObjIsMecc(*(int *)(param_1 + 0x274));

        if ((iVar4 == 0) && (iVar4 = *(int *)(param_1 + 0x274), *(int *)(iVar4 + 0x1e0) != 0x33)) {

          if ((iVar4 != 0) && (iVar4 = ObjIsReaper(iVar4), iVar4 != 0))

          goto switchD_004f6ae3_caseD_32;

        }

        else {

          iVar4 = crt_rand_scaled(1000);

          if (*(int *)(iVar3 + 0x54) == 0) {

            if (*(int *)(param_1 + 0xe8) == 10) {

              iVar8 = ((*(int *)(param_1 + 4) != 0x2e6) - 1 & 0x19) + 0x67;

            }

            else {

              if ((((*(int *)(param_1 + 4) == 0xb) && (iVar4 < 100)) &&

                  (20.0 < DAT_00632e6c - *(float *)(iVar3 + 0x94))) &&

                 (*(int *)(param_1 + 0x274) == DAT_00632a88)) {

                uVar10 = TextGetPtrRandom(s_SmChRide_005622ec,4,0);

                chat_insert_name(iVar3 + 0x80,uVar10);

                *(float *)(iVar3 + 0x94) = DAT_00632e6c;

              }

              if (iVar4 < 0x3b6) {

                iVar8 = 0x29;

              }

              else {

                iVar8 = crt_rand_scaled(100);

                if (iVar4 < 0x3cf) {

                  if ((iVar8 < 0x32) && (*(int *)(param_1 + 4) != 0xd8)) {

                    iVar4 = crt_rand_scaled(100);

                    if (iVar4 < 0x32) {

                      sound_play_player(0x6bd,param_1);

                      iVar8 = 0x55;

                      break;

                    }

                    sound_play_player(0x6be,param_1);

                  }

                  iVar8 = 0x55;

                }

                else {

                  if ((iVar8 < 0x32) && (*(int *)(param_1 + 4) != 0xd8)) {

                    iVar4 = crt_rand_scaled(100);

                    if (iVar4 < 0x32) {

                      sound_play_player(0x6bd,param_1);

                      iVar8 = 0x56;

                      break;

                    }

                    sound_play_player(0x6be,param_1);

                  }

                  iVar8 = 0x56;

                }

              }

            }

          }

          else {

            iVar8 = 0x6e;

          }

        }

      }

      break;

    case 0x21:

      fStack_10 = 0.5;

      if (iVar4 != 0) {

        iVar8 = meccbaseitem_shot(param_1,iVar4);

      }

      break;

    case 0x23:

      iVar4 = meccbasepit_bldg_from_object(*(undefined4 *)(param_1 + 0x274));

      if ((iVar4 == 0) && (iVar4 = ObjIsMecc(*(undefined4 *)(param_1 + 0x274)), iVar4 == 0)) {

        iVar4 = reaperbase_bldg_from_object(*(undefined4 *)(param_1 + 0x274));

        if ((iVar4 != 0) || (iVar4 = ObjIsReaper(*(undefined4 *)(param_1 + 0x274)), iVar4 != 0)) {

          iVar8 = 0x5b;

        }

      }

      else {

        iVar8 = 0x4c;

        if ((*(int *)(iVar3 + 0x30) != 0) &&

           (iVar4 = *(int *)(*(int *)(iVar3 + 0x30) + 4), iVar4 != 0x2f4)) {

          iVar8 = (iVar4 == 0x2f3) + 0x4d;

        }

      }

      break;

    case 0x25:

      fStack_10 = 0.5;

      if (*(int *)(param_1 + 0xe8) == 7) {

        if ((*(byte *)(param_1 + 0x30) & 2) == 0) {

          iVar8 = *(int *)(param_1 + 0x10);

        }

        else if (*(int *)(param_1 + 0x10) == 0x7a) {

LAB_004f6e2b:

          iVar8 = 0x7b;

        }

        else if (*(int *)(param_1 + 0x10) == 0x7e) {

          iVar8 = 0x7c;

        }

        else {

          iVar4 = crt_rand_scaled(1000);

          if (iVar4 < 0x14) {

            iVar8 = crt_rand_scaled(100);

            if (iVar8 < 0x32) {

              uVar10 = 0x6bb;

            }

            else {

              uVar10 = 0x6bc;

            }

            sound_play_obj(uVar10,param_1);

          }

          if (iVar4 < 900) goto LAB_004f6e2b;

          iVar8 = (iVar4 < 0x3b6) + 0x7c;

        }

      }

      else {

        if (((*(byte *)(param_1 + 0x30) & 2) == 0) || (iVar4 == 0)) goto LAB_004f6b37;

        iVar4 = meccbasepit_bldg_from_object(*(undefined4 *)(param_1 + 0x274));

        if (iVar4 != 0) {

          if (*(int *)(param_1 + 0x10) == 0x41) goto LAB_004f6db0;

          iVar4 = *(int *)(iVar3 + 0x34) + 1;

          *(int *)(iVar3 + 0x34) = iVar4;

          if (9 < iVar4) {

            *(undefined4 *)(iVar3 + 0x34) = 0;

            piVar7 = DAT_00632d98;

            if (DAT_00632d98 == (int *)0x0) {

              return;

            }

            do {

              iVar3 = piVar7[3];

              if (((*(int *)(iVar3 + 4) == 0xb) &&

                  (*(int *)(*(int *)(iVar3 + 0x100) + 0x2c) ==

                   *(int *)(*(int *)(param_1 + 0x100) + 0x2c))) && (*(int *)(iVar3 + 0xe4) == 0x25))

              {

                *(undefined4 *)(*(int *)(iVar3 + 0x100) + 0x34) = 0;

                ObjectSetAnim(iVar3,0x4a,0x80,0,0,0x3f000000);

                fVar9 = (float10)rndfloatrange(0,0x3cf5c28f);

                *(float *)(iVar3 + 0x14) = (float)fVar9;

              }

              piVar7 = (int *)*piVar7;

            } while (piVar7 != (int *)0x0);

            return;

          }

          goto LAB_004f6d36;

        }

        iVar4 = reaperbase_bldg_from_object(*(undefined4 *)(param_1 + 0x274));

        if (iVar4 != 0) {

          iVar8 = 0x5a;

        }

      }

      break;

    case 0x27:

    case 0x28:

      iVar8 = 2;

      fStack_c = 1.4013e-45;

      *(undefined4 *)(param_1 + 0x10c) = 0x41f00000;

      fStack_14 = 20.0;

      break;

    case 0x29:

      if ((*(byte *)(param_1 + 0x30) & 2) == 0) {

        iVar8 = *(int *)(param_1 + 0x10);

      }

      else {

        iVar4 = reaper_0052e4a0(param_1);

        if (iVar4 != 0) {

          reaper_00530bd0(param_1,0,0,0,0x15,0);

        }

        object_destroy(param_1);

      }

      break;

    case 0x2a:

      if ((*(byte *)(param_1 + 0x30) & 2) == 0) {

        iVar8 = *(int *)(param_1 + 0x10);

      }

      else {

        uVar10 = __ftol();

        *(undefined4 *)(param_1 + 0xe4) = uVar10;

      }

      break;

    case 0x32:

switchD_004f6ae3_caseD_32:

      iVar8 = 0x59;

      break;

    case 0x33:

      if ((*(byte *)(param_1 + 0x30) & 2) == 0) {

        iVar8 = *(int *)(param_1 + 0x10);

      }

      else {

        iVar4 = crt_rand_scaled(1000);

        if ((iVar4 < 0x14) && (*(int *)(param_1 + 4) == 0x248)) {

          if (iVar4 < 5) {

            uVar10 = 0x6fd;

          }

          else if (iVar4 < 10) {

            uVar10 = 0x6fe;

          }

          else if (iVar4 < 0xf) {

            uVar10 = 0x6ff;

          }

          else {

            uVar10 = 0x700;

          }

LAB_004f71f0:

          sound_play_obj(uVar10,param_1);

        }

        else if ((iVar4 < 100) && (*(int *)(param_1 + 4) == 0x2e6)) {

          if (iVar4 < 0x10) {

            uVar10 = 0x705;

          }

          else if (iVar4 < 0x20) {

            uVar10 = 0x706;

          }

          else if (iVar4 < 0x30) {

            uVar10 = 0x707;

          }

          else if (iVar4 < 0x40) {

            uVar10 = 0x708;

          }

          else if (iVar4 < 0x50) {

            uVar10 = 0x709;

          }

          else {

            uVar10 = 0x70a;

          }

          goto LAB_004f71f0;

        }

        iVar8 = (0x3b5 < iVar4) + 100;

      }

      break;

    case 0x35:

      iVar8 = 0x6d;

      fStack_18 = 4.62428e-44;

      break;

    case 0x37:

      if (((*(byte *)(param_1 + 0x30) & 2) == 0) || (iVar4 == 0)) goto LAB_004f6b37;

      if (*(int *)(param_1 + 0x10) == 0x41) {

LAB_004f6db0:

        fStack_10 = 0.5;

        fStack_18 = 4.48416e-44;

        iVar8 = 0x42;

      }

      else {

        iVar4 = *(int *)(iVar3 + 0x34) + 1;

        *(int *)(iVar3 + 0x34) = iVar4;

        if (9 < iVar4) {

          *(undefined4 *)(iVar3 + 0x34) = 0;

          iVar3 = *(int *)(param_1 + 0x274);

          piVar7 = DAT_00632d98;

          if (DAT_00632d98 == (int *)0x0) {

            return;

          }

          do {

            iVar4 = piVar7[3];

            if (((*(int *)(iVar4 + 4) == 0xb) && (*(int *)(iVar4 + 0x274) == iVar3)) &&

               (*(int *)(iVar4 + 0xe4) == 0x37)) {

              *(undefined4 *)(*(int *)(iVar4 + 0x100) + 0x34) = 0;

              ObjectSetAnim(iVar4,0x4a,0x80,0,0,0x3f000000);

              fVar9 = (float10)rndfloatrange(0,0x3cf5c28f);

              *(float *)(iVar4 + 0x14) = (float)fVar9;

            }

            piVar7 = (int *)*piVar7;

          } while (piVar7 != (int *)0x0);

          return;

        }

LAB_004f6d36:

        fStack_10 = 0.5;

        fStack_18 = 4.48416e-44;

        iVar4 = crt_rand_scaled(100);

        if (iVar4 < 10) {

          iVar8 = 0x43;

        }

        else if (iVar4 < 0x14) {

          iVar8 = 0x44;

        }

        else if (iVar4 < 0x1e) {

          iVar8 = 0x45;

        }

        else if (iVar4 < 0x28) {

          iVar8 = 0x46;

        }

        else if (iVar4 < 0x32) {

          iVar8 = 0x47;

        }

        else if (iVar4 < 0x3c) {

          iVar8 = 0x48;

        }

        else {

          iVar8 = ((0x45 < iVar4) - 1 & 7) + 0x42;

        }

      }

      break;

    case 0x3c:

      iVar8 = 0x77;

      fStack_18 = 4.62428e-44;

      break;

    case 0x3d:

      iVar8 = 0x76;

      fStack_18 = 4.62428e-44;

      break;

    case 0x3f:

    case 0x40:

      iVar8 = 0x85;

      fStack_18 = 4.62428e-44;

      break;

    case 0x41:

      iVar8 = 0x86;

      fStack_18 = 4.62428e-44;

      break;

    case 0x50:

      if ((*(byte *)(param_1 + 0x30) & 2) == 0) {

        iVar8 = *(int *)(param_1 + 0x10);

      }

      else {

        iVar4 = crt_rand_scaled(100);

        iVar8 = (0x31 < iVar4) + 0x6f;

      }

      break;

    case 0x51:

      if ((*(byte *)(param_1 + 0x30) & 2) == 0) {

        iVar8 = *(int *)(param_1 + 0x10);

      }

      else {

        iVar8 = 0x72;

      }

      break;

    case 0x52:

      if ((*(byte *)(param_1 + 0x30) & 2) == 0) {

        iVar8 = *(int *)(param_1 + 0x10);

      }

      else {

        iVar4 = crt_rand_scaled(100);

        iVar8 = (0x31 < iVar4) + 0x78;

      }

    }

    if (*(int *)(param_1 + 0x10) == iVar8) {

      return;

    }

    fVar5 = fStack_c;

    fVar6 = fStack_18;

    fStack_18 = fStack_14;

    if (iVar8 == 0x73) {

      if (*(int *)(iVar3 + 0xc4) == 0) {

        iVar4 = crt_rand_scaled(100);

        if (iVar4 < 0x32) {

          uVar10 = 0x6b3;

        }

        else {

          uVar10 = 0x6b4;

        }

        sound_play_obj(uVar10,param_1);

        *(undefined4 *)(iVar3 + 0xc4) = 1;

      }

    }

    else if (*(int *)(iVar3 + 0xc4) != 0) {

      sound_stop_obj(0x6b3,param_1);

      sound_stop_obj(0x6b4,param_1);

      *(undefined4 *)(iVar3 + 0xc4) = 0;

    }

    goto LAB_004f7489;

  }

  uVar1 = *(uint *)(param_1 + 0xd8);

  iVar3 = *(int *)(param_1 + 0x274);

  iVar4 = *(int *)(param_1 + 0x100);

  iVar8 = (-(uint)((uVar1 & 0x800) != 0) & 0x68) + 1;

  fStack_c = 0.16666667;

  fStack_14 = 4.62428e-44;

  if ((*(float *)(param_1 + 0x278) < *(float *)(param_1 + 0x1c0)) && ((uVar1 & 0x8000000) != 0)) {

    anim_select_user(param_1,0x84);

    return;

  }

  fStack_18 = 0.0;

  fStack_10 = fStack_18;

  switch(*(undefined4 *)(param_1 + 0xe4)) {

  case 1:

    if ((*(byte *)(param_1 + 0x30) & 2) == 0) {

      iVar8 = *(int *)(param_1 + 0x10);

    }

    else {

      *(undefined4 *)(param_1 + 0xe4) = 3;

    }

    break;

  default:

    if (((uVar1 & 0x8000000) == 0) || ((iVar3 != 0 && (iVar3 = ObjIsReaper(iVar3), iVar3 != 0)))) {

      if (0.0 <= *(float *)(param_1 + 0x108)) {

        if (*(float *)(param_1 + 0x10c) == 0.0) {

          iVar3 = *(int *)(iVar4 + 0x30);

          if (iVar3 == 0) {

LAB_004f6977:

            if ((*(byte *)(param_1 + 0x30) & 2) != 0) {

              iVar8 = (-(uint)((*(uint *)(param_1 + 0xd8) & 0x800) != 0) & 0x68) + 1;

            }

          }

          else {

            iVar2 = *(int *)(iVar3 + 4);

            if (((iVar2 == 0x2f1) || (iVar2 == 0x2f3)) || (iVar2 == 0x2f4)) {

              if (iVar2 == 0x2f4) {

                iVar8 = 0x4c;

              }

              else {

                iVar8 = (iVar2 == 0x2f3) + 0x4d;

              }

            }

            else {

              if ((iVar3 == 0) || (*(int *)(iVar3 + 4) != 0x2f2)) goto LAB_004f6977;

              if ((*(byte *)(param_1 + 0x30) & 2) == 0) {

                iVar8 = *(int *)(param_1 + 0x10);

              }

              else {

                iVar3 = meccbasepit_bldg_from_object(*(undefined4 *)(param_1 + 0x274));

                if (iVar3 != 0) {

                  fStack_14 = 4.48416e-44;

                  iVar3 = crt_rand_scaled(100);

                  if (iVar3 < 10) {

                    iVar8 = 0x43;

                  }

                  else if (iVar3 < 0x14) {

                    iVar8 = 0x44;

                  }

                  else if (iVar3 < 0x1e) {

                    iVar8 = 0x45;

                  }

                  else if (iVar3 < 0x28) {

                    iVar8 = 0x46;

                  }

                  else if (iVar3 < 0x32) {

                    iVar8 = 0x47;

                  }

                  else if (iVar3 < 0x3c) {

                    iVar8 = 0x48;

                  }

                  else {

                    iVar8 = ((0x45 < iVar3) - 1 & 7) + 0x42;

                  }

                }

              }

            }

          }

        }

        else {

          if ((*(int *)(iVar4 + 0x30) == 0) || (*(int *)(*(int *)(iVar4 + 0x30) + 4) != 0x2f9)) {

            fStack_18 = *(float *)(param_1 + 0x1b4);

            iVar8 = 2;

          }

          else {

            iVar8 = 0x4b;

            fStack_18 = *(float *)(param_1 + 0x10c) * 0.75;

          }

          fStack_10 = 1.4013e-45;

          ObjectUpdateSpeedDist(param_1,fStack_18 * *(float *)(param_1 + 0xc4));

        }

      }

      else {

        iVar8 = 0x73;

      }

    }

    else {

      iVar8 = 0x5a;

    }

    break;

  case 0x13:

    if ((*(byte *)(param_1 + 0x30) & 2) == 0) {

      iVar8 = *(int *)(param_1 + 0x10);

    }

    else if ((iVar3 == 0) || (iVar3 = ObjIsMecc(iVar3), iVar3 == 0)) {

      if ((*(int *)(param_1 + 0x274) != 0) &&

         (iVar3 = ObjIsReaper(*(int *)(param_1 + 0x274)), iVar3 != 0))

      goto switchD_004f64dd_caseD_32;

    }

    else {

      iVar3 = crt_rand_scaled(1000);

      if (*(int *)(iVar4 + 0x54) == 0) {

        if (*(int *)(param_1 + 0xe8) == 10) {

          iVar8 = ((*(int *)(param_1 + 4) != 0x2e6) - 1 & 0x19) + 0x67;

        }

        else {

          if ((((*(int *)(param_1 + 4) == 0xb) && (iVar3 < 100)) &&

              (20.0 < DAT_00632e6c - *(float *)(iVar4 + 0x94))) &&

             (*(int *)(param_1 + 0x274) == DAT_00632a88)) {

            uVar10 = TextGetPtrRandom(s_SmChRide_005622ec,4,0);

            chat_insert_name(iVar4 + 0x80,uVar10);

            *(float *)(iVar4 + 0x94) = DAT_00632e6c;

          }

          if (iVar3 < 0x3b6) {

            iVar8 = 0x29;

          }

          else {

            iVar8 = (0x3ce < iVar3) + 0x55;

          }

        }

      }

      else {

        iVar8 = 0x6e;

      }

    }

    break;

  case 0x1e:

    if (*(int *)(param_1 + 0x10) == 1) {

      if ((*(byte *)(param_1 + 0x30) & 2) == 0) {

        iVar8 = 1;

      }

      else {

        iVar3 = crt_rand_scaled(100);

        iVar8 = ((0x1d < iVar3) - 1 & 0xffffffc1) + 0x40;

      }

    }

    else if ((*(int *)(param_1 + 0x10) == 0x40) &&

            (((*(byte *)(param_1 + 0x30) & 2) == 0 || (iVar3 == 0)))) {

      iVar8 = 0x40;

    }

    else {

      iVar8 = 1;

    }

    break;

  case 0x21:

    fStack_c = 0.5;

    if (iVar3 != 0) {

      iVar8 = meccbaseitem_shot(param_1,iVar3);

    }

    break;

  case 0x27:

  case 0x28:

    iVar8 = 2;

    fStack_10 = 1.4013e-45;

    *(undefined4 *)(param_1 + 0x10c) = 0x41f00000;

    fStack_18 = 20.0;

    break;

  case 0x29:

    if ((*(byte *)(param_1 + 0x30) & 2) == 0) {

      iVar8 = *(int *)(param_1 + 0x10);

    }

    else {

      iVar3 = reaper_0052e4a0(param_1);

      if (iVar3 != 0) {

        reaper_00530bd0(param_1,0,0,0,0x15,0);

      }

      object_destroy(param_1);

    }

    break;

  case 0x2a:

    if ((*(byte *)(param_1 + 0x30) & 2) == 0) {

      iVar8 = *(int *)(param_1 + 0x10);

    }

    else {

      uVar10 = __ftol();

      *(undefined4 *)(param_1 + 0xe4) = uVar10;

    }

    break;

  case 0x32:

switchD_004f64dd_caseD_32:

    iVar8 = 0x59;

    break;

  case 0x33:

    if ((*(byte *)(param_1 + 0x30) & 2) == 0) {

      iVar8 = *(int *)(param_1 + 0x10);

    }

    else {

      iVar3 = crt_rand_scaled(1000);

      if ((iVar3 < 0x14) && (*(int *)(param_1 + 4) == 0x248)) {

        if (iVar3 < 5) {

          uVar10 = 0x6fd;

        }

        else if (iVar3 < 10) {

          uVar10 = 0x6fe;

        }

        else if (iVar3 < 0xf) {

          uVar10 = 0x6ff;

        }

        else {

          uVar10 = 0x700;

        }

LAB_004f66c3:

        sound_play_obj(uVar10,param_1);

      }

      else if ((iVar3 < 100) && (*(int *)(param_1 + 4) == 0x2e6)) {

        if (iVar3 < 0x10) {

          uVar10 = 0x705;

        }

        else if (iVar3 < 0x20) {

          uVar10 = 0x706;

        }

        else if (iVar3 < 0x30) {

          uVar10 = 0x707;

        }

        else if (iVar3 < 0x40) {

          uVar10 = 0x708;

        }

        else if (iVar3 < 0x50) {

          uVar10 = 0x709;

        }

        else {

          uVar10 = 0x70a;

        }

        goto LAB_004f66c3;

      }

      iVar8 = (0x3b5 < iVar3) + 100;

    }

  }

  if (*(int *)(param_1 + 0x10) == iVar8) {

    return;

  }

  fVar5 = fStack_10;

  fVar6 = fStack_14;

  fStack_10 = fStack_c;

  if (iVar8 == 0x73) {

    if (*(int *)(iVar4 + 0xc4) == 0) {

      iVar3 = crt_rand_scaled(100);

      if (iVar3 < 0x32) {

        uVar10 = 0x6b3;

      }

      else {

        uVar10 = 0x6b4;

      }

      sound_play_obj(uVar10,param_1);

      *(undefined4 *)(iVar4 + 0xc4) = 1;

    }

  }

  else if (*(int *)(iVar4 + 0xc4) != 0) {

    sound_stop_obj(0x6b3,param_1);

    sound_stop_obj(0x6b4,param_1);

    *(undefined4 *)(iVar4 + 0xc4) = 0;

  }

LAB_004f7489:

  ObjectSetAnim(param_1,iVar8,fVar6,fVar5,fStack_18 * *(float *)(param_1 + 0xc4),fStack_10);

  return;

}

/* ===== comm_stats_reset @ 0x004F75C0 ===== */
void comm_stats_reset(void)



{

  int iVar1;

  undefined4 *puVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  int iVar9;

  int iVar10;

  

  iVar8 = dialog_level_is_base();

  if ((iVar8 == 0) || (iVar8 = FUN_0052c5c0(), iVar8 != 0)) {

    iVar7 = DAT_006330d8;

    iVar6 = DAT_006330d4;

    iVar5 = DAT_006330d0;

    iVar4 = DAT_006330cc;

    iVar3 = DAT_006330c8;

    iVar8 = DAT_006330c4;

    DAT_006330c4 = 0;

    DAT_006330c8 = 0;

    DAT_006330cc = 0;

    DAT_006330d0 = 0;

    DAT_006330d4 = 0;

    DAT_006330d8 = 0;

    for (puVar2 = DAT_00632d98; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {

      iVar1 = puVar2[3];

      if ((((-1 < (char)((uint)*(undefined4 *)(iVar1 + 0xd8) >> 8)) && (*(int *)(iVar1 + 4) == 0xb))

          && ((*(byte *)(iVar1 + 0xe0) & 4) == 0)) && (*(int *)(iVar1 + 0xe8) != 10)) {

        DAT_006330c4 = DAT_006330c4 + 1;

        if (((*(byte *)(iVar1 + 0xe0) & 8) == 0) || (*(int *)(iVar1 + 0x274) == 0)) {

          DAT_006330c8 = DAT_006330c8 + 1;

        }

        else {

          iVar9 = base_which_team(*(int *)(iVar1 + 0x274));

          if ((0 < iVar9) && (iVar9 < 3)) {

            iVar10 = iVar9 + -1;

            (&DAT_006330cc)[iVar10] = (&DAT_006330c8)[iVar9] + 1;

            iVar1 = *(int *)(iVar1 + 0x100);

            if ((*(int *)(iVar1 + 0x1c) < 0) &&

               ((*(int *)(iVar1 + 0x20) < 0 && (*(int *)(iVar1 + 0x24) < 0)))) {

              (&DAT_006330d4)[iVar10] = (&DAT_006330d4)[iVar10] + 1;

            }

          }

        }

      }

    }

    if (((((iVar8 != DAT_006330c4) || (iVar3 != DAT_006330c8)) || (iVar4 != DAT_006330cc)) ||

        ((iVar5 != DAT_006330d0 || (iVar6 != DAT_006330d4)))) || (iVar7 != DAT_006330d8)) {

      comm_0052b780_user_5(0);

    }

  }

  return;

}

/* ===== cspec_004f7750 @ 0x004F7750 ===== */
void cspec_004f7750(int param_1)



{

  int iVar1;

  

  iVar1 = *(int *)(param_1 + 0x100);

  obj_ptr_clear_if_dead(iVar1 + 0x30);

  obj_ptr_clear_if_dead(iVar1);

  obj_ptr_clear_if_dead(iVar1 + 0xa0);

  return;

}

/* ===== smartie_shot @ 0x004F7780 ===== */
/* PS2 candidate: smartie_shot (conf 0.441) */



void smartie_shot(int param_1,float param_2,int param_3,undefined4 param_4,undefined4 param_5)



{

  uint *puVar1;

  float fVar2;

  int iVar3;

  int iVar4;

  uint uVar5;

  undefined4 uVar6;

  

  iVar4 = *(int *)(param_3 + 0x100);

  if (param_1 == 3) {

    object_destroy(param_3);

    return;

  }

  if ((((*(int *)(param_3 + 0xe4) != 0x41) || (*(int *)(iVar4 + 0xa0) == 0)) ||

      (iVar3 = ANM_AnimGetImage(*(int *)(iVar4 + 0xa0)), iVar3 != 0)) &&

     (((*(int *)(param_3 + 0xe4) != 0x29 && (iVar3 = *(int *)(param_3 + 0xe8), iVar3 != 8)) &&

      ((iVar3 != 9 && (iVar3 != 1)))))) {

    if (iVar3 == 10) {

      if (((param_1 == 7) && (iVar4 = fx_create(param_3), iVar4 != 0)) &&

         (*(int *)(param_3 + 0x274) != 0)) {

        objtype_setup_vimp(param_3,*(int *)(param_3 + 0x274));

        return;

      }

    }

    else {

      if (*(int *)(param_3 + 0xe4) == 0x32) {

        smartie_escape_reaper_grab(param_3);

        return;

      }

      if (((*(int *)(param_3 + 0x210) == 0) &&

          (((*(int *)(param_3 + 0x274) == 0 ||

            (iVar3 = ObjIsReaper(*(int *)(param_3 + 0x274)), iVar3 == 0)) &&

           ((*(byte *)(param_3 + 0xe0) & 8) == 0)))) &&

         ((((*(int *)(param_3 + 0xe8) == 5 || (uVar5 = *(uint *)(param_3 + 0xdc) & 0xf, uVar5 == 0))

           || (uVar5 == 2)) && (*(int *)(iVar4 + 0x3c) == 0)))) {

        fVar2 = param_2 + *(float *)(param_3 + 0x278);

        *(float *)(param_3 + 0x278) = fVar2;

        if (*(float *)(param_3 + 0x1c0) <= fVar2) {

          if (*(int *)(iVar4 + 0xa0) != 0) {

            puVar1 = (uint *)(*(int *)(iVar4 + 0xa0) + 0xe0);

            *puVar1 = *puVar1 & 0xfffffffb;

            *(undefined4 *)(iVar4 + 0xa0) = 0;

          }

          iVar4 = *(int *)(param_3 + 0x274);

          if (iVar4 != 0) {

            iVar3 = *(int *)(param_3 + 0x100);

            switch(*(undefined4 *)(param_3 + 0xe4)) {

            case 0x1e:

            case 0x1f:

            case 0x21:

              bldg_slot_action_dispatch(iVar4,param_3);

              ai_clear_move_goal(param_3);

              break;

            default:

              goto switchD_004f7908_caseD_20;

            case 0x24:

            case 0x25:

              iVar4 = meccbasepit_bldg_from_object(iVar4);

              if (iVar4 == 0) {

                iVar4 = reaperbase_bldg_from_object(*(undefined4 *)(param_3 + 0x274));

                if (iVar4 != 0) {

                  food_object_flag_clear

                            (param_3,*(undefined4 *)(iVar3 + 0x2c),*(undefined4 *)(iVar3 + 0x28));

                }

              }

              else {

                FUN_0040ac70(param_3,*(undefined4 *)(iVar3 + 0x2c),*(undefined4 *)(iVar3 + 0x28));

              }

              ai_clear_move_goal(param_3);

            }

            *(undefined4 *)(iVar3 + 0x2c) = 0xffffffff;

            *(undefined4 *)(iVar3 + 0x28) = 0xffffffff;

          }

switchD_004f7908_caseD_20:

          if (param_1 == 7) {

            *(uint *)(param_3 + 0xe0) = *(uint *)(param_3 + 0xe0) | 0x40;

            iVar4 = reaper_0052e4a0(param_3);

            if (iVar4 != 0) {

              reaper_00530bd0(param_3,0,0,0,0x15,0);

            }

            object_destroy(param_3);

          }

          *(undefined4 *)(param_3 + 0xe4) = 0x29;

          *(undefined1 *)(param_3 + 0x20b) = 0;

          *(undefined1 *)(param_3 + 0x20a) = 0;

          *(undefined1 *)(param_3 + 0x208) = 0;

          if ((*(uint *)(param_3 + 0xd8) & 0x800) == 0) {

            uVar6 = 0x4f;

          }

          else {

            uVar6 = 0x6a;

          }

          ObjectSetAnim(param_3,uVar6,0,0,0,0x3ecccccd);

          iVar4 = crt_rand_scaled(100);

          if (iVar4 < 0x32) {

            sound_play_3dpos(0x6af,param_3 + 0xa0);

            return;

          }

          sound_play_3dpos(0x6b0,param_3 + 0xa0);

          return;

        }

        hurt_pusher(param_1,param_2,param_2,param_3,param_4,param_5);

        wound_from_object_world(param_3,param_5);

        iVar4 = crt_rand_scaled(0x3c);

        if (iVar4 < 10) {

          sound_play_obj(0x6f2,param_3);

          return;

        }

        if (iVar4 < 0x14) {

          sound_play_obj(0x6f4,param_3);

          return;

        }

        if (iVar4 < 0x1e) {

          sound_play_obj(0x6f6,param_3);

          return;

        }

        if (iVar4 < 0x28) {

          sound_play_obj(0x6f3,param_3);

          return;

        }

        if (iVar4 < 0x32) {

          sound_play_obj(0x6f5,param_3);

          return;

        }

        sound_play_obj(0x6f7,param_3);

      }

    }

  }

  return;

}

/* ===== smartie_clear_held_object @ 0x004F7AF0 ===== */
/* PS2 candidate: smartie_clear_held_object (conf 0.607) */



void smartie_clear_held_object(int param_1)



{

  int iVar1;

  

  iVar1 = *(int *)(param_1 + 0x100);

  if (*(int *)(iVar1 + 0x30) != 0) {

    *(undefined4 *)(*(int *)(iVar1 + 0x30) + 0x210) = 0;

    object_destroy(*(undefined4 *)(iVar1 + 0x30));

    *(undefined4 *)(iVar1 + 0x30) = 0;

    *(undefined4 *)(iVar1 + 0x14) = 0x41d80000;

    iVar1 = reaper_0052e4a0(param_1);

    if (iVar1 != 0) {

      reaper_00530bd0(param_1,0,0,0,0x14,0);

    }

  }

  return;

}

/* ===== smartie_make_held_object__FP6OBJECTi @ 0x004F7B50 ===== */
/* PS2 candidate: smartie_make_held_object__FP6OBJECTi (conf 0.637) */



void smartie_make_held_object__FP6OBJECTi(int param_1,undefined4 param_2)



{

  uint *puVar1;

  int iVar2;

  int iVar3;

  

  iVar3 = *(int *)(param_1 + 0x100);

  if (*(int *)(iVar3 + 0x30) == 0) {

    iVar2 = object_allocate_type(param_2,0);

    *(int *)(iVar3 + 0x30) = iVar2;

    playerobj_eval_refpt(param_1,0,iVar2 + 0xa0);

    object_copy_posdirinfo(*(undefined4 *)(iVar3 + 0x30));

    *(undefined4 *)(*(int *)(iVar3 + 0x30) + 0x18c) = *(undefined4 *)(param_1 + 0x18c);

    *(int *)(*(int *)(iVar3 + 0x30) + 0x210) = param_1;

    *(undefined4 *)(*(int *)(iVar3 + 0x30) + 0x214) = 0;

    *(undefined4 *)(*(int *)(iVar3 + 0x30) + 0x218) = 0;

    *(undefined4 *)(iVar3 + 0x14) = *(undefined4 *)(*(int *)(iVar3 + 0x30) + 0xc4);

    puVar1 = (uint *)(*(int *)(iVar3 + 0x30) + 0xd8);

    *puVar1 = *puVar1 | 0x400000;

    *(uint *)(*(int *)(iVar3 + 0x30) + 0xd8) = *(uint *)(*(int *)(iVar3 + 0x30) + 0xd8) | 0x20000000

    ;

    iVar3 = reaper_0052e4a0(param_1);

    if (iVar3 != 0) {

      reaper_00530bd0(param_1,0,1,0,0x13,&param_2);

    }

  }

  return;

}

/* ===== smartie_get_name__FP6OBJECT @ 0x004F7C10 ===== */
void smartie_get_name__FP6OBJECT(int param_1)



{

  char cVar1;

  uint uVar2;

  char *pcVar3;

  uint uVar4;

  char *pcVar5;

  int iVar6;

  uint uVar7;

  undefined1 *puVar8;

  int iVar9;

  int iVar10;

  char *pcVar11;

  char *pcVar12;

  uint auStack_48 [6];

  undefined1 local_30 [48];

  

  iVar9 = *(int *)(param_1 + 4);

  if (iVar9 == 0xd8) {

    pcVar3 = &DAT_00562310;

  }

  else if (iVar9 == 0x247) {

    pcVar3 = s_Timmy_00562308;

  }

  else if (iVar9 == 0x248) {

    pcVar3 = s_Borjoyzee_0055b3c0;

  }

  else {

    if (iVar9 != 0x2e6) {

      uVar2 = *(uint *)(param_1 + 0x188);

      pcVar3 = (char *)(*(int *)(param_1 + 0x100) + 0x80);

      puVar8 = local_30;

      iVar9 = 0;

      *pcVar3 = '\0';

      iVar10 = 0;

      do {

        uVar4 = (int)(uVar2 >> 8) >> ((byte)iVar10 & 0x1f) & 3;

        auStack_48[iVar9] = uVar4;

        crt_sprintf(puVar8,s_SmNameSyl_c_d_005622f8,iVar9 + 0x41,uVar4 + 1);

        pcVar5 = (char *)TextGetPtrQ(puVar8);

        uVar4 = 0xffffffff;

        auStack_48[iVar9 + 3] = (uint)pcVar5;

        do {

          pcVar12 = pcVar5;

          if (uVar4 == 0) break;

          uVar4 = uVar4 - 1;

          pcVar12 = pcVar5 + 1;

          cVar1 = *pcVar5;

          pcVar5 = pcVar12;

        } while (cVar1 != '\0');

        uVar4 = ~uVar4;

        iVar6 = -1;

        pcVar5 = pcVar3;

        do {

          pcVar11 = pcVar5;

          if (iVar6 == 0) break;

          iVar6 = iVar6 + -1;

          pcVar11 = pcVar5 + 1;

          cVar1 = *pcVar5;

          pcVar5 = pcVar11;

        } while (cVar1 != '\0');

        pcVar5 = pcVar12 + -uVar4;

        pcVar12 = pcVar11 + -1;

        for (uVar7 = uVar4 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {

          *(undefined4 *)pcVar12 = *(undefined4 *)pcVar5;

          pcVar5 = pcVar5 + 4;

          pcVar12 = pcVar12 + 4;

        }

        for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {

          *pcVar12 = *pcVar5;

          pcVar5 = pcVar5 + 1;

          pcVar12 = pcVar12 + 1;

        }

        iVar10 = iVar10 + 2;

        puVar8 = puVar8 + 0x10;

        iVar9 = iVar9 + 1;

        if (5 < iVar10) {

          return;

        }

      } while( true );

    }

    pcVar3 = &DAT_0055b3bc;

  }

  iVar9 = (*(int *)(param_1 + 0x100) + 0x80) - (int)pcVar3;

  do {

    cVar1 = *pcVar3;

    pcVar3[iVar9] = cVar1;

    pcVar3 = pcVar3 + 1;

  } while (cVar1 != '\0');

  return;

}

/* ===== cspec_004f7d20 @ 0x004F7D20 ===== */
void cspec_004f7d20(int param_1)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  undefined4 *puVar4;

  uint uVar5;

  int iVar6;

  int *piVar7;

  int iVar8;

  float10 fVar9;

  undefined4 uVar10;

  

  iVar2 = param_1;

  if (DAT_00632e74 == 0) {

    if (*(int *)(param_1 + 0xe4) == 0) {

      if (*(int *)(param_1 + 0xe8) == 4) {

        iVar6 = *(int *)(param_1 + 0x100);

        iVar3 = *(int *)(iVar6 + 4);

        if (iVar3 != 0) {

          mem_free_tagged(iVar3,s_C__Giants_source_main_smartie_c_00562328,0x1617);

        }

        iVar3 = __ftol(s_smhatch_slist_00562318,s_C__Giants_source_main_smartie_c_00562328,0x1619);

        puVar4 = (undefined4 *)MemAllocMsg(0xd,iVar3 << 2);

        *(undefined4 **)(iVar6 + 4) = puVar4;

        uVar5 = __ftol();

        for (uVar5 = uVar5 & 0x3fffffff; uVar5 != 0; uVar5 = uVar5 - 1) {

          *puVar4 = 0;

          puVar4 = puVar4 + 1;

        }

        for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {

          *(undefined1 *)puVar4 = 0;

          puVar4 = (undefined4 *)((int)puVar4 + 1);

        }

      }

      *(undefined4 *)(iVar2 + 0x14) = 0;

      ObjectSetAnim(iVar2,1,0x84,0,0,0);

      *(undefined4 *)(iVar2 + 0xe4) = 1;

    }

    iVar6 = fx_create(iVar2);

    if ((iVar6 != 0) && (iVar6 = *(int *)(iVar2 + 0xe8), iVar6 != 0)) {

      uVar5 = *(uint *)(iVar2 + 0x30);

      *(uint *)(iVar2 + 0x30) = uVar5 & 0xfffffffe;

      if ((iVar6 == 2) &&

         (((*(int *)(iVar2 + 0xe4) == 3 && ((uVar5 & 2) != 0)) && (0.0 < *(float *)(iVar2 + 0x14))))

         ) {

        DAT_00632b8c = 1;

        return;

      }

      if ((iVar6 == 3) || (iVar6 == 4)) {

        piVar1 = *(int **)(iVar2 + 0x100);

        fVar9 = (float10)FUN_00518b70(iVar2,0);

        fVar9 = (float10)*(float *)(iVar2 + 0xec) - fVar9;

        *(float *)(iVar2 + 0xec) = (float)fVar9;

        if (fVar9 <= (float10)0.0) {

          iVar6 = *(int *)(iVar2 + 0xe4);

          if (iVar6 == 1) {

            *(undefined4 *)(iVar2 + 0xec) = 0x40000000;

            iVar6 = dialog_level_is_base();

            if (iVar6 == 0) {

              iVar6 = *(int *)(DAT_00632ed8 + 0x62c);

            }

            else {

              iVar6 = func_0x00521fe0(DAT_00632f3c);

            }

            if (((DAT_006330c4 < iVar6) && (*(int *)(iVar2 + 0xe8) != 4)) ||

               ((*(int *)(iVar2 + 0xe8) == 4 && (iVar6 = __ftol(), *piVar1 < iVar6)))) {

              sound_play_obj(0x663,iVar2);

              *(undefined4 *)(iVar2 + 0xe4) = 3;

              anim_select_user(iVar2,1);

              *(uint *)(iVar2 + 0x30) = *(uint *)(iVar2 + 0x30) & 0xffffffef;

              *(undefined4 *)(iVar2 + 0xec) = 0x40000000;

              if (*(int *)(iVar2 + 0xe8) == 4) {

                uVar10 = 0x539;

              }

              else {

                uVar10 = 0xb;

              }

              iVar6 = object_allocate_type(uVar10,0x80000000);

              object_set_location_p3d(iVar6,iVar2 + 0xa0);

              DAT_006330c4 = DAT_006330c4 + 1;

              *piVar1 = *piVar1 + 1;

              *(undefined4 *)(iVar6 + 0xe8) = 4;

              *(undefined4 *)(iVar6 + 0xe4) = 0x3b;

              ObjectSetAnim(iVar6,0,0x21,0,0,0);

              *(int *)(iVar2 + 0x274) = iVar6;

              *(uint *)(iVar6 + 0xd8) = *(uint *)(iVar6 + 0xd8) | 0x40000000;

              iVar3 = reaper_0052e4a0(iVar2);

              if (iVar3 != 0) {

                param_1 = *(int *)(iVar6 + 0x188);

                reaper_00530bd0(iVar2,0,1,0,2,&param_1);

              }

              if (*(int *)(iVar2 + 0xe8) == 4) {

                iVar8 = 0;

                iVar3 = __ftol();

                if (0 < iVar3) {

                  piVar7 = (int *)piVar1[1];

                  do {

                    if (*piVar7 == 0) {

                      if ((*(uint *)(iVar2 + 0xd8) & 0x400) != 0) {

                        *(uint *)(iVar6 + 0xd8) = *(uint *)(iVar6 + 0xd8) | 0x400;

                      }

                      *(int *)(piVar1[1] + iVar8 * 4) = iVar6;

                      break;

                    }

                    iVar8 = iVar8 + 1;

                    piVar7 = piVar7 + 1;

                  } while (iVar8 < iVar3);

                }

              }

              if ((*(uint *)(iVar2 + 0xd8) & 0x400) != 0) {

                *(uint *)(iVar6 + 0xd8) = *(uint *)(iVar6 + 0xd8) | 0x400;

              }

              if (((byte)*(undefined4 *)(iVar2 + 0xdc) & 0xf) == 3) {

                *(uint *)(iVar6 + 0xdc) = *(uint *)(iVar6 + 0xdc) | 3;

              }

            }

          }

          else if (iVar6 == 3) {

            iVar6 = *(int *)(iVar2 + 0x274);

            *(undefined4 *)(iVar2 + 0xe4) = 4;

            *(undefined4 *)(iVar2 + 0xec) = 0x40000000;

            if (iVar6 != 0) {

              ObjectSetAnim(iVar6,0x75,0x20,0,0,0);

              *(uint *)(iVar6 + 0xd8) = *(uint *)(iVar6 + 0xd8) & 0xbfffffff;

              *(undefined4 *)(iVar6 + 0xe8) = 4;

              *(undefined4 *)(iVar6 + 0xe4) = 1;

            }

            *(undefined4 *)(iVar2 + 0x274) = 0;

            iVar6 = reaper_0052e4a0(iVar2);

            if (iVar6 != 0) {

              reaper_00530bd0(iVar2,0,0,0,1,0);

              return;

            }

          }

          else if (iVar6 == 4) {

            sound_play_obj(0x662,iVar2);

            *(undefined4 *)(iVar2 + 0xe4) = 1;

            fVar9 = (float10)rndfloatrange(0,0x40000000);

            *(float *)(iVar2 + 0xec) = (float)(fVar9 + (float10)*(float *)(DAT_00632ed8 + 0x630));

            anim_select_user(iVar2,1);

            *(uint *)(iVar2 + 0x30) = *(uint *)(iVar2 + 0x30) | 0x10;

            iVar6 = reaper_0052e4a0(iVar2);

            if (iVar6 != 0) {

              reaper_00530bd0(iVar2,0,0,0,3,0);

              return;

            }

          }

        }

      }

    }

  }

  return;

}

/* ===== cspec_004f8130 @ 0x004F8130 ===== */
void cspec_004f8130(int param_1,int param_2,undefined4 param_3,undefined4 *param_4)



{

  int iVar1;

  

  if (param_2 == 1) {

    iVar1 = *(int *)(param_1 + 0x274);

    if (iVar1 != 0) {

      ObjectSetAnim(iVar1,0x75,0x20,0,0,0);

      *(uint *)(iVar1 + 0xd8) = *(uint *)(iVar1 + 0xd8) & 0xbfffffff;

      *(undefined4 *)(iVar1 + 0xe8) = 4;

      *(undefined4 *)(iVar1 + 0xe4) = 0;

    }

    *(undefined4 *)(param_1 + 0x274) = 0;

  }

  else {

    if (param_2 == 2) {

      *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) & 0xfffffffe;

      anim_select_user(param_1,1);

      *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) & 0xffffffef;

      iVar1 = object_allocate_type(0xb,0x80000000);

      object_set_location_p3d(iVar1,param_1 + 0xa0);

      *(undefined4 *)(iVar1 + 0xe8) = 4;

      *(undefined4 *)(iVar1 + 0xe4) = 0x3b;

      *(undefined4 *)(iVar1 + 0x188) = *param_4;

      ObjectSetAnim(iVar1,0,0x21,0,0,0);

      *(int *)(param_1 + 0x274) = iVar1;

      *(uint *)(iVar1 + 0xd8) = *(uint *)(iVar1 + 0xd8) | 0x40000000;

      return;

    }

    if (param_2 == 3) {

      *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) & 0xfffffffe;

      anim_select_user(param_1,1);

      *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) | 0x10;

      return;

    }

  }

  return;

}

/* ===== cspec_004f8250 @ 0x004F8250 ===== */
void cspec_004f8250(int param_1)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  

  piVar1 = *(int **)(param_1 + 0x100);

  iVar3 = piVar1[1];

  if (iVar3 != 0) {

    iVar4 = 0;

    iVar2 = __ftol();

    if (0 < iVar2) {

      do {

        iVar2 = *(int *)(iVar3 + iVar4 * 4);

        if (iVar2 != 0) {

          obj_ptr_clear_if_dead(iVar3 + iVar4 * 4);

          iVar3 = piVar1[1];

          if ((*(int *)(iVar3 + iVar4 * 4) == 0) && ((*(byte *)(iVar2 + 0xe0) & 0x40) == 0)) {

            *piVar1 = *piVar1 + -1;

          }

        }

        iVar4 = iVar4 + 1;

        iVar2 = __ftol();

      } while (iVar4 < iVar2);

    }

  }

  return;

}

/* ===== cspec_004f82c0 @ 0x004F82C0 ===== */
void cspec_004f82c0(int param_1)



{

  int iVar1;

  int iVar2;

  

  iVar1 = *(int *)(param_1 + 0x100);

  iVar2 = *(int *)(iVar1 + 4);

  if (iVar2 != 0) {

    mem_free_tagged(iVar2,s_C__Giants_source_main_smartie_c_00562328,0x1739);

  }

  *(undefined4 *)(iVar1 + 4) = 0;

  return;

}

/* ===== cspec_004f82f0 @ 0x004F82F0 ===== */
void cspec_004f82f0(int param_1)



{

  float10 fVar1;

  

  if ((*(uint *)(param_1 + 0x1c8) & 0x800000) == 0) {

    *(undefined4 *)(param_1 + 0x278) = 0;

    *(uint *)(param_1 + 0x1c8) = *(uint *)(param_1 + 0x1c8) | 0x800000;

  }

  fVar1 = (float10)FUN_00518b70(param_1,0);

  *(float *)(param_1 + 0xec) = (float)((float10)*(float *)(param_1 + 0xec) - fVar1);

  fVar1 = (float10)FUN_00518b70(param_1,0);

  *(float *)(param_1 + 0x278) = (float)(fVar1 + (float10)*(float *)(param_1 + 0x278));

  return;

}

/* ===== FUN_004f8350 @ 0x004F8350 ===== */
/* PS2 candidate: sceMpegIsEnd (conf 0.604) */



float10 FUN_004f8350(int param_1)



{

  return (float10)**(float **)(param_1 + 0x100);

}

/* ===== smokegen_process @ 0x004F8360 ===== */
/* PS2 candidate: smokegen_process (conf 0.444) */



void smokegen_process(float param_1)



{

  int *piVar1;

  float fVar2;

  int *piVar3;

  undefined4 *puVar4;

  undefined4 *puVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  float10 fVar9;

  float10 fVar10;

  

  iVar6 = (int)param_1;

  piVar3 = *(int **)((int)param_1 + 0x100);

  if ((*(byte *)((int)param_1 + 0xe0) & 8) != 0) {

    return;

  }

  iVar7 = *(int *)((int)param_1 + 0xe4);

  puVar4 = (undefined4 *)*piVar3;

  if (iVar7 == 0) {

    *(undefined4 *)((int)param_1 + 0xe4) = 1;

    fVar9 = (float10)rndfloatrange(puVar4[2],puVar4[3]);

    *(float *)((int)param_1 + 0xec) = (float)fVar9;

    if ((*(byte *)((int)param_1 + 0xe0) & 2) == 0) {

      fVar9 = (float10)rndfloatrange(puVar4[4],puVar4[5]);

      piVar3[2] = (int)(float)fVar9;

      piVar3[1] = 0;

    }

    else {

      fVar9 = (float10)rndfloatrange(puVar4[4],puVar4[5]);

      piVar3[1] = (int)(float)fVar9;

    }

    goto LAB_004f85c8;

  }

  if (iVar7 != 1) {

    if (iVar7 == 2) {

      fVar9 = (float10)FUN_00518b70(param_1,0);

      fVar9 = (float10)*(float *)((int)param_1 + 0xec) - fVar9;

      *(float *)((int)param_1 + 0xec) = (float)fVar9;

      if ((float10)0.0 < fVar9) {

        return;

      }

      fVar9 = (float10)rndfloatrange(puVar4[2],puVar4[3]);

      *(float *)((int)param_1 + 0xec) = (float)fVar9;

      fVar9 = (float10)rndfloatrange(puVar4[4],puVar4[5]);

      piVar3[2] = (int)(float)fVar9;

      piVar3[1] = 0;

      *(undefined4 *)((int)param_1 + 0xe4) = 1;

    }

    else if (iVar7 == 3) {

      fVar9 = (float10)FUN_00518b70(param_1,0);

      fVar9 = (float10)*(float *)((int)param_1 + 0xec) - fVar9;

      *(float *)((int)param_1 + 0xec) = (float)fVar9;

      puVar5 = DAT_00632d68;

      if (fVar9 < (float10)0.0) {

        for (; puVar5 != (undefined4 *)0x0; puVar5 = (undefined4 *)*puVar5) {

          if ((*(int *)(puVar5[3] + 0x1e0) == 0x19) &&

             (iVar7 = *(int *)(puVar5[3] + 0x100), (float)*(int *)(iVar7 + 4) == param_1)) {

            *(undefined4 *)(iVar7 + 4) = 0;

          }

        }

        object_destroy(param_1);

      }

    }

    goto LAB_004f85c8;

  }

  fVar9 = (float10)FUN_00518b70(param_1,0);

  fVar9 = (float10)*(float *)((int)param_1 + 0xec) - fVar9;

  *(float *)((int)param_1 + 0xec) = (float)fVar9;

  if ((*(byte *)((int)param_1 + 0xe0) & 2) == 0) {

    fVar9 = (float10)FUN_00518b70(param_1,0);

    fVar2 = (float)piVar3[1];

    piVar3[1] = (int)(float)((float10)fVar2 - fVar9);

    if ((float10)fVar2 - fVar9 < (float10)0.0) {

      make_particle__FP6OBJECT(param_1);

      piVar3[1] = piVar3[2];

    }

  }

  else {

    if (fVar9 < (float10)0.0 == (fVar9 == (float10)0.0)) {

      FUN_00518b70(param_1,0);

      iVar7 = __ftol();

      if ((float)piVar3[1] < (float)iVar7) goto LAB_004f844a;

    }

    else {

LAB_004f844a:

      iVar7 = __ftol();

    }

    iVar8 = iVar7;

    if (0 < iVar7) {

      do {

        make_particle__FP6OBJECT(param_1);

        iVar8 = iVar8 + -1;

      } while (iVar8 != 0);

    }

    piVar3[1] = (int)((float)piVar3[1] - (float)iVar7);

  }

  if (*(float *)((int)param_1 + 0xec) < 0.0 != (*(float *)((int)param_1 + 0xec) == 0.0)) {

    if ((*(byte *)((int)param_1 + 0xe0) & 1) != 0) {

      *(undefined4 *)((int)param_1 + 0xec) = puVar4[0xb];

      *(undefined4 *)((int)param_1 + 0xe4) = 3;

      return;

    }

    fVar9 = (float10)rndfloatrange(*puVar4,puVar4[1]);

    *(float *)((int)param_1 + 0xec) = (float)fVar9;

    *(undefined4 *)((int)param_1 + 0xe4) = 2;

    return;

  }

LAB_004f85c8:

  fVar9 = (float10)rndfloatrange(-(float)puVar4[0xe],puVar4[0xe]);

  fVar10 = (float10)FUN_00518b70(param_1,0);

  fVar9 = fVar10 * (float10)(float)fVar9 + (float10)(float)piVar3[3];

  piVar3[3] = (int)(float)fVar9;

  if ((float10)(float)puVar4[0xd] < fVar9) {

    piVar3[3] = puVar4[0xd];

  }

  if ((float)piVar3[3] < (float)puVar4[0xc]) {

    piVar3[3] = puVar4[0xc];

  }

  piVar1 = (int *)((int)param_1 + 0x210);

  param_1 = (float)piVar3[3];

  if (*piVar1 != 0) {

    param_1 = param_1 + *(float *)(*piVar1 + 200);

  }

  sine_cos_lookup(param_1,piVar3 + 5,piVar3 + 6);

  fVar9 = (float10)rndfloatrange(-(float)puVar4[0x11],puVar4[0x11]);

  fVar10 = (float10)FUN_00518b70(iVar6,0);

  fVar9 = fVar10 * (float10)(float)fVar9 + (float10)(float)piVar3[4];

  piVar3[4] = (int)(float)fVar9;

  if ((float10)(float)puVar4[0x10] < fVar9) {

    piVar3[4] = puVar4[0x10];

  }

  if ((float)piVar3[4] < (float)puVar4[0xf]) {

    piVar3[4] = puVar4[0xf];

  }

  return;

}

/* ===== obj_sound_cleanup @ 0x004F86A0 ===== */
void obj_sound_cleanup(undefined4 *param_1)



{

  float *pfVar1;

  float fVar2;

  int iVar3;

  undefined4 *puVar4;

  undefined4 *puVar5;

  float10 fVar6;

  

  iVar3 = (int)param_1;

  pfVar1 = *(float **)((int)param_1 + 0x100);

  param_1 = (undefined4 *)pfVar1[1];

  puVar4 = (undefined4 *)0x0;

  puVar5 = (undefined4 *)0x0;

  if (param_1 != (undefined4 *)0x0) {

    if ((char)((uint)param_1[0x36] >> 8) < '\0') {

      pfVar1[1] = 0.0;

      param_1 = (undefined4 *)0x0;

      puVar4 = param_1;

      puVar5 = param_1;

    }

    else {

      puVar4 = (undefined4 *)param_1[0x40];

      puVar5 = *(undefined4 **)param_1[0x40];

    }

  }

  fVar6 = (float10)FUN_00518b70(iVar3,0);

  *(float *)(iVar3 + 0xec) = (float)((float10)*(float *)(iVar3 + 0xec) - fVar6);

  if (param_1 == (undefined4 *)0x0) {

    fVar6 = (float10)FUN_00518b70(iVar3,0);

    object_add_location_2(iVar3,0,0,(float)(fVar6 * (float10)pfVar1[3]));

  }

  else {

    fVar6 = (float10)FUN_00518b70(iVar3,0);

    fVar6 = (float10)FUN_00518b70(iVar3,0,(float)(fVar6 * (float10)pfVar1[3]));

    fVar6 = (float10)FUN_00518b70(iVar3,0,(float)-(fVar6 * (float10)(float)puVar4[6] *

                                                  (float10)(float)puVar4[4]));

    object_add_location_2

              (iVar3,(float)(fVar6 * (float10)(float)puVar4[5] * (float10)(float)puVar4[4]));

    *(float *)(iVar3 + 0xc4) =

         ((float)puVar5[7] - (float)puVar5[6]) * (1.0 - pfVar1[2] * *(float *)(iVar3 + 0xec)) +

         (float)puVar5[6];

    if ((*(uint *)(iVar3 + 0x1c8) & 0x2000) != 0) {

      fVar2 = (1.0 - (float)puVar5[0x12]) * pfVar1[2] * *(float *)(iVar3 + 0xec);

      *pfVar1 = fVar2;

      if (0.0 <= fVar2) {

        if (1.0 < fVar2) {

          *pfVar1 = 1.0;

        }

      }

      else {

        *pfVar1 = 0.0;

      }

    }

  }

  if (*(float *)(iVar3 + 0xec) < 0.0) {

    object_destroy(iVar3);

    *(undefined4 *)(iVar3 + 0xec) = 0;

  }

  return;

}

/* ===== make_particle__FP6OBJECT @ 0x004F8800 ===== */
/* PS2 candidate: make_particle__FP6OBJECT (conf 0.42) */



int make_particle__FP6OBJECT(float param_1)



{

  int iVar1;

  float *pfVar2;

  float fVar3;

  int iVar4;

  float10 fVar5;

  

  iVar1 = **(int **)((int)param_1 + 0x100);

  iVar4 = object_allocate_type(*(undefined4 *)((int)param_1 + 4),0);

  object_change_ospec(iVar4,0x19);

  pfVar2 = *(float **)(iVar4 + 0x100);

  object_set_location_p3d(iVar4,(int)param_1 + 0xa0);

  fVar5 = (float10)rndfloatrange(*(undefined4 *)(iVar1 + 0x28),*(undefined4 *)(iVar1 + 0x2c));

  *(float *)(iVar4 + 0xec) = (float)fVar5;

  pfVar2[2] = (float)((float10)1.0 / fVar5);

  fVar5 = (float10)rndfloatrange(*(undefined4 *)(iVar1 + 0x20),*(undefined4 *)(iVar1 + 0x24));

  pfVar2[3] = (float)fVar5;

  *(undefined4 *)(iVar4 + 0xc4) = *(undefined4 *)(iVar1 + 0x18);

  pfVar2[1] = param_1;

  if ((*(byte *)((int)param_1 + 0xe0) & 4) != 0) {

    fVar3 = 1.0 - *(float *)(iVar1 + 0x48);

    *pfVar2 = fVar3;

    if (0.0 <= fVar3) {

      if (1.0 < fVar3) {

        *pfVar2 = 1.0;

      }

    }

    else {

      *pfVar2 = 0.0;

    }

    *(uint *)(iVar4 + 0x1c8) = *(uint *)(iVar4 + 0x1c8) | 0x2000;

  }

  fVar5 = (float10)FUN_00404200(iVar4);

  if ((float10)0.0 < fVar5) {

    fVar5 = (float10)rndfloat((float)fVar5);

    *(float *)(iVar4 + 0x14) = (float)fVar5;

  }

  return iVar4;

}

/* ===== main/smoke_004f90e0 @ 0x004F90E0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void main_smoke_004f90e0(undefined4 param_1,float param_2)



{

  float10 fVar1;

  undefined1 local_c [12];

  

  XFGetViewport(local_c);

  fVar1 = (float10)distance3d__FP3P3DT0(local_c,param_1);

  fVar1 = ((float10)960.00006 / ((fVar1 + (float10)30.0) * (fVar1 + (float10)30.0))) *

          (float10)param_2;

  if ((float10)0.1 < fVar1) {

    if ((float10)0.6 < fVar1) {

      fVar1 = (float10)0.6;

    }

    if ((float10)_DAT_00632b5c < fVar1) {

      _DAT_00632b5c = (float)fVar1;

      _DAT_00632dc0 = (float)((float10)2.5 * fVar1);

      _DAT_00632dc4 = (float)(fVar1 * (float10)1.6666666);

      return;

    }

  }

  return;

}

/* ===== cspec_004f9310 @ 0x004F9310 ===== */
undefined4 cspec_004f9310(void)



{

  return 0x1c;

}

/* ===== cspec_004f9320 @ 0x004F9320 ===== */
void cspec_004f9320(int param_1)



{

  mem_free_tagged(**(undefined4 **)(param_1 + 0x100),s_C__Giants_source_main_smoke_c_00562348,0x299)

  ;

  return;

}

/* ===== cspec_004f9340 @ 0x004F9340 ===== */
void cspec_004f9340(int param_1)



{

  if ((DAT_00632e74 == 0) && (*(int *)(param_1 + 0xe4) != 0x1e)) {

    ripper_medium_move__FP6OBJECT(param_1);

    if (*(int *)(param_1 + 0xe4) != 100) {

      obj_turn_update(param_1);

    }

  }

  return;

}

/* ===== ripper_medium_move__FP6OBJECT @ 0x004F9380 ===== */
/* PS2 candidate: ripper_medium_move__FP6OBJECT (conf 0.464) */



void ripper_medium_move__FP6OBJECT(int param_1)



{

  float *pfVar1;

  float *pfVar2;

  undefined4 *puVar3;

  float fVar4;

  int iVar5;

  int iVar6;

  uint uVar7;

  float10 fVar8;

  float10 fVar9;

  undefined4 uVar10;

  undefined1 local_1c [16];

  float local_c;

  

  pfVar2 = *(float **)(param_1 + 0x100);

  if (*(int *)(param_1 + 0xe4) == 0) {

    *(undefined4 *)(param_1 + 0x18c) = 100;

    fVar8 = (float10)rndfloatrange(*(undefined4 *)(DAT_00632ed8 + 0xb9c),

                                   *(undefined4 *)(DAT_00632ed8 + 0xba0));

    pfVar2[3] = (float)fVar8;

    if (*(int *)(param_1 + 4) == 0x23f) {

      if (*(int *)(param_1 + 0xe8) == 1) {

        *(uint *)(param_1 + 0x1c8) = *(uint *)(param_1 + 0x1c8) & 0xfffdffff;

        object_change_ospec(param_1,0x1b);

        return;

      }

      if (*(int *)(param_1 + 0xe8) == 2) {

        *(undefined4 *)(param_1 + 0xe4) = 100;

      }

    }

    else {

      *(undefined4 *)(param_1 + 0xe4) = 0x1e;

    }

  }

  uVar7 = *(uint *)(param_1 + 0x30) & 2;

  *(undefined1 *)(param_1 + 0x208) = 0;

  *(undefined1 *)(param_1 + 0x20b) = 0;

  *(undefined1 *)(param_1 + 0x20a) = 0;

  *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) & 0xfcffffff;

  fVar8 = (float10)FUN_00518b70(param_1,0);

  pfVar2[4] = (float)((float10)pfVar2[4] - fVar8);

  if (pfVar2[7] == 0.0) {

    fVar8 = (float10)FUN_00518b70(0,0);

    fVar4 = pfVar2[8];

    pfVar2[8] = (float)((float10)fVar4 - fVar8);

    if ((float10)fVar4 - fVar8 < (float10)0.0) {

      ripper_sound_state_check(param_1,0);

      pfVar2[8] = 2.2;

    }

  }

  if ((*(float *)(param_1 + 0x1c0) <= *(float *)(param_1 + 0x278)) &&

     (*(int *)(param_1 + 0xe4) != 0x14)) {

    pfVar2[10] = 0.0;

    *(undefined4 *)(param_1 + 0x278) = *(undefined4 *)(param_1 + 0x1c0);

    *(undefined4 *)(param_1 + 0xe4) = 0x14;

  }

  switch(*(undefined4 *)(param_1 + 0xe4)) {

  case 10:

    if ((0 < (int)pfVar2[1]) && (1.0666667 <= *(float *)(param_1 + 0x14))) {

      if (*(float *)(param_1 + 0x18) < 1.0666667) {

        fVar4 = (float)obj_shadow_cast(param_1,0x43160000);

        pfVar2[10] = fVar4;

        pfVar2[9] = 0.0;

        if (fVar4 != 0.0) {

          fVar8 = (float10)dirfcalcp3d__FP3P3DT0

                                     (param_1 + 0xa0,(int)fVar4 + 0xa0,

                                      *(undefined4 *)(param_1 + 200));

          fVar8 = (float10)playerobj_turn((float)fVar8);

          pfVar2[9] = (float)fVar8;

        }

        if (35.0 < pfVar2[9]) {

          pfVar2[9] = 35.0;

        }

        if (pfVar2[9] < -35.0) {

          pfVar2[9] = -35.0;

        }

      }

      fVar8 = (float10)FUN_00518b70(param_1,0);

      fVar4 = *pfVar2;

      *pfVar2 = (float)((float10)fVar4 - fVar8);

      if ((float10)fVar4 - fVar8 < (float10)0.0) {

        iVar5 = *(int *)(param_1 + 0x100);

        iVar6 = object_allocate_type(0x25f,0x80000000);

        playerobj_eval_refpt(param_1,1,iVar6 + 0xa0);

        object_copy_posdirinfo(iVar6);

        *(float *)(iVar6 + 200) = *(float *)(param_1 + 200) + *(float *)(iVar5 + 0x24);

        *(undefined4 *)(iVar6 + 0x18c) = *(undefined4 *)(param_1 + 0x18c);

        *(undefined4 *)(iVar6 + 0x11c) = *(undefined4 *)(iVar6 + 0x194);

        *(undefined4 *)(iVar6 + 0x10c) = *(undefined4 *)(iVar6 + 0x194);

        *(undefined4 *)(iVar6 + 0xec) = *(undefined4 *)(DAT_00632ed8 + 0xcb8);

        *(undefined4 *)(iVar6 + 0xc4) = *(undefined4 *)(DAT_00632ed8 + 0xcbc);

        *pfVar2 = 0.2;

        pfVar2[1] = (float)((int)pfVar2[1] + -1);

      }

    }

    if (uVar7 != 0) {

      *(undefined4 *)(param_1 + 0xe4) = 0xb;

      return;

    }

    break;

  case 0xb:

    if (1.3333334 <= *(float *)(param_1 + 0x14)) {

      sound_play_obj(0x511,param_1);

      iVar5 = fx_create(param_1);

      if (iVar5 != 0) {

        get_free_world_ripple__Fv_2

                  (param_1 + 0xa0,*(undefined4 *)(DAT_00632ed8 + 0x40c),

                   *(undefined4 *)(DAT_00632ed8 + 0x410),*(undefined4 *)(DAT_00632ed8 + 0x414),

                   *(undefined4 *)(DAT_00632ed8 + 0x4ac));

      }

      *(undefined4 *)(param_1 + 0xe4) = 0xc;

      return;

    }

    break;

  case 0xc:

    if (uVar7 != 0) {

      *(undefined4 *)(param_1 + 0xe4) = 0x65;

      *(undefined4 *)(param_1 + 0xec) = 0x40a00000;

      return;

    }

    break;

  case 0x14:

    if ((uVar7 != 0) && ((*(uint *)(param_1 + 0xdc) & 0x20000) == 0)) {

      fVar4 = pfVar2[5];

      if ((fVar4 != 0.0) && (*(int *)((int)fVar4 + 0x1e0) == 0x61)) {

        formation_notify_death(fVar4);

      }

      *(uint *)(param_1 + 0xdc) = *(uint *)(param_1 + 0xdc) | 0x20000;

      *(undefined4 *)(param_1 + 0xec) = DAT_00632e6c;

      return;

    }

    break;

  case 100:

    pfVar2[10] = 0.0;

    if (pfVar2[7] != 0.0) {

      fVar4 = (float)obj_shadow_cast(param_1,0x43160000);

      pfVar2[10] = fVar4;

      if (fVar4 != 0.0) {

        *(undefined4 *)(param_1 + 0xe4) = 0x65;

        if (pfVar2[5] != 0.0) {

          *(undefined4 *)((int)pfVar2[5] + 0xe4) = 3;

        }

      }

    }

    iVar5 = *(int *)(param_1 + 0x100);

    pfVar2 = (float *)(param_1 + 0xa0);

    playerobj_eval_refpt(*(undefined4 *)(iVar5 + 0x14),*(undefined4 *)(iVar5 + 0x18),pfVar2);

    ground_height_at(pfVar2,local_1c);

    if (*(int *)(*(int *)(iVar5 + 0x14) + 0xf8) == 0) {

      *(float *)(param_1 + 0xa8) = local_c + *(float *)(param_1 + 0x1d4);

    }

    else if (*(float *)(param_1 + 0xa8) < local_c) {

      *(float *)(param_1 + 0xa8) = local_c;

    }

    if ((*(float *)(param_1 + 0xb8) != *pfVar2) ||

       (*(float *)(param_1 + 0xbc) != *(float *)(param_1 + 0xa4))) {

      fVar8 = (float10)dirfcalcp3d__FP3P3DT0(param_1 + 0xb8,pfVar2);

      fVar8 = (float10)FUN_00518b70(param_1,0,0x461c4000,(float)fVar8,param_1 + 200);

      chase_angle((float)(fVar8 * (float10)30.0));

    }

    *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) | 0x40;

    objspec_dispatch_gate(param_1);

    fVar8 = (float10)FUN_00518b70(param_1,0);

    object_animate_process(param_1,(float)fVar8);

    ObjectCalculateTransform(param_1);

    *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) | 0x20;

    *(undefined4 *)(param_1 + 0xf4) = *(undefined4 *)(param_1 + 200);

    break;

  case 0x65:

    fVar4 = (float)obj_shadow_cast(param_1,0x43160000);

    pfVar2[10] = fVar4;

    if (fVar4 == 0.0) {

      *(undefined4 *)(param_1 + 0xf8) = *(undefined4 *)(param_1 + 0xf4);

    }

    else {

      fVar8 = (float10)dirfcalcp3d__FP3P3DT0(param_1 + 0xa0,(int)fVar4 + 0xa0);

      *(float *)(param_1 + 0xf8) = (float)fVar8;

    }

    pfVar1 = (float *)(param_1 + 200);

    *(undefined4 *)(param_1 + 0xfc) = *(undefined4 *)(param_1 + 200);

    fVar8 = (float10)FUN_00518b70(param_1,0,0x461c4000,*(undefined4 *)(param_1 + 0xf8),pfVar1);

    chase_angle((float)(fVar8 * (float10)*(float *)(param_1 + 0x1a8)));

    fVar8 = (float10)playerobj_turn(*(undefined4 *)(param_1 + 0xf8),*pfVar1);

    fVar9 = (float10)FUN_00518b70(param_1,0);

    fVar9 = (float10)*(float *)(param_1 + 0xec) - fVar9;

    *(float *)(param_1 + 0xec) = (float)fVar9;

    if (((fVar9 < (float10)0.0) && ((float)ABS(fVar8) < 5.0 != ((float)ABS(fVar8) == 5.0))) &&

       (*(undefined4 *)(param_1 + 0xec) = 0x40000000, pfVar2[10] != 0.0)) {

      *(undefined4 *)(param_1 + 0xe4) = 10;

      pfVar2[1] = 1.68156e-44;

      *pfVar2 = 0.0;

    }

    if (*(float *)(param_1 + 0xfc) == *pfVar1) {

      fVar8 = (float10)FUN_00518b70(param_1,0);

      fVar8 = (float10)*(float *)(param_1 + 0xf0) - fVar8;

      *(float *)(param_1 + 0xf0) = (float)fVar8;

      if ((pfVar2[10] == 0.0) && (fVar8 < (float10)0.0 != (fVar8 == (float10)0.0))) {

        iVar5 = crt_rand_scaled(100);

        if (iVar5 < 0x32) {

          uVar10 = 0x28;

        }

        else {

          uVar10 = 0x29;

        }

        anim_select_check2(param_1,uVar10);

        *(undefined4 *)(param_1 + 0xe4) = 0x66;

      }

    }

    fVar8 = (float10)FUN_00518b70(param_1,0);

    fVar4 = pfVar2[2];

    pfVar2[2] = (float)((float10)fVar4 - fVar8);

    if ((float10)fVar4 - fVar8 < (float10)0.0) {

      fVar8 = (float10)rndfloatrange(0x3f666666,0x3fc00000);

      pfVar2[2] = (float)fVar8;

      pfVar2[7] = 1.4013e-45;

      for (puVar3 = DAT_00632d6c; puVar3 != (undefined4 *)0x0; puVar3 = (undefined4 *)*puVar3) {

        if ((*(int *)(puVar3[3] + 0x1e0) == 0x33) &&

           (*(float *)(*(int *)(puVar3[3] + 0x100) + 0x134) == pfVar2[5])) {

          pfVar2[7] = 0.0;

          break;

        }

      }

    }

    if (((pfVar2[7] != 0.0) && (pfVar2[10] == 0.0)) && (*(float *)(param_1 + 0xf8) == *pfVar1)) {

      pfVar2[10] = 0.0;

      *(undefined4 *)(param_1 + 0xe4) = 100;

      if (pfVar2[5] != 0.0) {

        *(undefined4 *)((int)pfVar2[5] + 0xe4) = 2;

        return;

      }

    }

    break;

  case 0x66:

    if (uVar7 != 0) {

      fVar8 = (float10)rndfloatrange(0x40400000,0x41700000);

      *(float *)(param_1 + 0xf0) = (float)fVar8;

      *(undefined4 *)(param_1 + 0xe4) = 0x65;

      return;

    }

  }

  return;

}

/* ===== ripper_sound_state_check @ 0x004F9B50 ===== */
void ripper_sound_state_check(int param_1,int param_2)



{

  int iVar1;

  int iVar2;

  bool bVar3;

  int iVar4;

  int *piVar5;

  

  iVar1 = *(int *)(param_1 + 0x100);

  if ((*(int *)(iVar1 + 0x14) != 0) && (*(int *)(param_1 + 0xe4) == 100)) {

    bVar3 = false;

    iVar4 = 0;

    if ((*(int *)(iVar1 + 0x1c) == 0) && (piVar5 = DAT_00632d6c, DAT_00632d6c != (int *)0x0)) {

      do {

        iVar2 = piVar5[3];

        if ((*(int *)(iVar2 + 0x1e0) != 0x33) || (bVar3)) {

          if ((*(int *)(iVar2 + 0x1e0) == 0x27) &&

             ((iVar2 != param_1 &&

              (*(int *)(*(int *)(iVar2 + 0x100) + 0x14) == *(int *)(iVar1 + 0x14))))) {

            iVar4 = iVar2;

          }

        }

        else if ((*(int *)(*(int *)(iVar2 + 0x100) + 0x134) == *(int *)(iVar1 + 0x14)) &&

                (*(int *)(*(int *)(iVar2 + 0x100) + 0xb0) == 0)) {

          if (param_2 != 0) {

            rpman_notify_hit(iVar2,0);

          }

          bVar3 = true;

        }

        piVar5 = (int *)*piVar5;

      } while (piVar5 != (int *)0x0);

      if (iVar4 != 0) {

        return;

      }

      if (bVar3) {

        return;

      }

    }

    *(undefined4 *)(iVar1 + 0x1c) = 1;

  }

  return;

}

/* ===== sound_play_pair @ 0x004F9C10 ===== */
void sound_play_pair(undefined4 param_1,float param_2,int param_3,undefined4 param_4,

                    undefined4 param_5)



{

  int iVar1;

  int iVar2;

  undefined4 uVar3;

  

  iVar1 = *(int *)(param_3 + 0x100);

  ripper_sound_state_check(param_3,1);

  param_2 = param_2 + *(float *)(param_3 + 0x278);

  *(float *)(param_3 + 0x278) = param_2;

  if (*(float *)(param_3 + 0x1c0) <= param_2) {

    if (*(int *)(param_3 + 0xe4) != 0x14) {

      iVar2 = crt_rand_scaled(100);

      if (iVar2 < 0x32) {

        uVar3 = 0x513;

      }

      else {

        uVar3 = 0x514;

      }

      sound_play_3dpos(uVar3,param_3 + 0xa0);

    }

    *(undefined4 *)(iVar1 + 0x28) = 0;

    *(undefined4 *)(param_3 + 0x278) = *(undefined4 *)(param_3 + 0x1c0);

    *(undefined4 *)(param_3 + 0xe4) = 0x14;

    blood_from_object(param_3);

    *(uint *)(param_3 + 0x1c8) = *(uint *)(param_3 + 0x1c8) & 0xfffdffff;

    return;

  }

  iVar2 = crt_rand_scaled(100);

  if (iVar2 < 0x32) {

    uVar3 = 0x51b;

  }

  else {

    uVar3 = 0x51c;

  }

  sound_play_obj(uVar3,param_3);

  wound_from_object_world(param_3,param_5);

  *(undefined4 *)(iVar1 + 0x10) = 0x41200000;

  if (*(int *)(iVar1 + 0x1c) != 0) {

    *(undefined4 *)(param_3 + 0xe4) = 0x65;

    if (*(int *)(iVar1 + 0x14) != 0) {

      *(undefined4 *)(*(int *)(iVar1 + 0x14) + 0xe4) = 3;

    }

  }

  return;

}

/* ===== obj_shadow_cast @ 0x004F9D20 ===== */
int obj_shadow_cast(int *param_1,float param_2)



{

  undefined4 *puVar1;

  undefined4 *puVar2;

  float fVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  float10 fVar8;

  float10 fVar9;

  int local_24;

  undefined4 local_18;

  undefined4 local_14;

  float local_10;

  undefined4 local_c;

  undefined4 local_8;

  float local_4;

  

  iVar6 = (int)param_1;

  iVar4 = *(int *)((int)param_1 + 0x100);

  local_24 = 0;

  if (*(float *)(iVar4 + 0x10) <= 0.0) {

    param_2 = param_2 * param_2;

  }

  else {

    param_2 = 1e+09;

  }

  param_1 = DAT_00632d6c;

  if (DAT_00632d6c == (int *)0x0) {

    return 0;

  }

  do {

    iVar5 = param_1[3];

    iVar7 = ObjIsMecc(iVar5);

    if ((((iVar7 != 0) && ((*(uint *)(iVar5 + 0xd8) & 0x4000c000) == 0)) &&

        (*(float *)(iVar5 + 0x278) < *(float *)(iVar5 + 0x1c0))) &&

       ((*(uint *)(iVar5 + 0xe0) & 0x2000000) == 0)) {

      puVar1 = (undefined4 *)(iVar5 + 0xa0);

      puVar2 = (undefined4 *)(iVar6 + 0xa0);

      fVar8 = (float10)FUN_0050a610(puVar2,puVar1);

      if (fVar8 <= (float10)param_2) {

        fVar3 = *(float *)(iVar4 + 0x10);

        if (fVar3 < 0.0 == (fVar3 == 0.0)) {

LAB_004f9ea2:

          param_2 = (float)fVar8;

          local_24 = iVar5;

        }

        else {

          fVar9 = (float10)dirfcalcp3d__FP3P3DT0(puVar2,puVar1);

          fVar9 = (float10)diff_angle((float)fVar9,*(undefined4 *)(iVar6 + 200));

          if (fVar9 <= (float10)*(float *)(DAT_00632ed8 + 0x5c)) {

            local_c = *puVar2;

            local_8 = *(undefined4 *)(iVar6 + 0xa4);

            local_4 = *(float *)(iVar6 + 0x1e8) * *(float *)(iVar6 + 0xc4) +

                      *(float *)(iVar6 + 0xa8);

            local_18 = *puVar1;

            local_14 = *(undefined4 *)(iVar5 + 0xa4);

            local_10 = *(float *)(iVar5 + 0x1e8) * *(float *)(iVar5 + 0xc4) +

                       *(float *)(iVar5 + 0xa8);

            iVar7 = ai_class_filter(&local_c,&local_18,4,&DAT_00562368,0);

            if (iVar7 != 0) goto LAB_004f9ea2;

          }

        }

      }

    }

    param_1 = (int *)*param_1;

    if (param_1 == (int *)0x0) {

      return local_24;

    }

  } while( true );

}

/* ===== cspec_004f9ee0 @ 0x004F9EE0 ===== */
void cspec_004f9ee0(int param_1)



{

  int iVar1;

  undefined4 *puVar2;

  int iVar3;

  float10 fVar4;

  float10 fVar5;

  

  fVar4 = (float10)FUN_00518b70(param_1,0);

  *(float *)(param_1 + 0xc4) =

       (float)((((float10)*(float *)(DAT_00632ed8 + 0xcc0) -

                (float10)*(float *)(DAT_00632ed8 + 0xcbc)) /

               (float10)*(float *)(DAT_00632ed8 + 0xcb8)) * fVar4 +

              (float10)*(float *)(param_1 + 0xc4));

  fVar4 = (float10)FUN_00518b70(param_1,0);

  fVar4 = (float10)*(float *)(param_1 + 0xec) - fVar4;

  *(float *)(param_1 + 0xec) = (float)fVar4;

  *(float *)(param_1 + 0x184) =

       (float)(((float10)*(float *)(DAT_00632ed8 + 0xcb8) - fVar4) /

              (float10)*(float *)(DAT_00632ed8 + 0xcb8));

  if (fVar4 < (float10)0.0) {

    object_destroy(param_1);

  }

  obj_scale_compute(param_1);

  for (puVar2 = DAT_00632d6c; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {

    iVar1 = puVar2[3];

    iVar3 = ObjIsMecc(iVar1);

    if (iVar3 == 0) {

      iVar3 = ObjIsReaper(iVar1);

      if ((iVar3 != 0) &&

         (fVar4 = (float10)FUN_0050a610(iVar1 + 0xa0,param_1 + 0xa0),

         fVar5 = (float10)*(float *)(DAT_00632ed8 + 0xcc8) *

                 (float10)*(float *)(DAT_00632ed8 + 0xcc8), fVar4 < fVar5 != (fVar4 == fVar5))) {

        *(undefined4 *)(*(int *)(iVar1 + 0x100) + 0x2c) = *(undefined4 *)(DAT_00632ed8 + 0xcc4);

      }

    }

    else {

      fVar4 = (float10)FUN_0050a610(iVar1 + 0xa0,param_1 + 0xa0);

      fVar5 = (float10)*(float *)(DAT_00632ed8 + 0xcc8) * (float10)*(float *)(DAT_00632ed8 + 0xcc8);

      if (fVar4 < fVar5 != (fVar4 == fVar5)) {

        *(undefined4 *)(*(int *)(iVar1 + 0x100) + 0x134) = *(undefined4 *)(DAT_00632ed8 + 0xcc4);

      }

    }

  }

  return;

}

/* ===== cspec_004fa030 @ 0x004FA030 ===== */
void cspec_004fa030(int param_1)



{

  float fVar1;

  bool bVar2;

  undefined4 uVar3;

  int iVar4;

  undefined4 uVar5;

  

  bVar2 = true;

  if (*(int *)(param_1 + 0xe8) == 1) {

    return;

  }

  if (*(int *)(param_1 + 0xe4) == 0x1e) {

    return;

  }

  fVar1 = *(float *)(DAT_00632ed8 + 0xb88);

  uVar5 = 0x20;

  uVar3 = 1;

  switch(*(int *)(param_1 + 0xe4)) {

  case 10:

    iVar4 = 10;

    break;

  case 0xb:

  case 0xc:

    iVar4 = 0xb;

    break;

  default:

    goto switchD_004fa080_caseD_d;

  case 0x14:

    iVar4 = 0xe;

    break;

  case 100:

    iVar4 = 2;

    *(undefined4 *)(param_1 + 0x10c) =

         *(undefined4 *)(*(int *)(*(int *)(*(int *)(param_1 + 0x100) + 0x14) + 0x100) + 0x24);

    goto LAB_004fa0eb;

  case 0x65:

    if (*(float *)(param_1 + 0xfc) == *(float *)(param_1 + 200)) {

      iVar4 = 1;

    }

    else {

      iVar4 = 0x26;

    }

    goto LAB_004fa0e9;

  }

  bVar2 = false;

LAB_004fa0e9:

  fVar1 = 0.0;

  uVar3 = 0;

LAB_004fa0eb:

  if (*(int *)(param_1 + 0x10) != iVar4) {

    if (bVar2) {

      uVar5 = 0x21;

    }

    ObjectSetAnim(param_1,iVar4,uVar5,uVar3,fVar1 * *(float *)(param_1 + 0xc4),0x3e2aaaab);

    return;

  }

switchD_004fa080_caseD_d:

  return;

}

/* ===== cspec_004fa1a0 @ 0x004FA1A0 ===== */
undefined4 cspec_004fa1a0(void)



{

  return 0x2c;

}

/* ===== cspec_004fa1b0 @ 0x004FA1B0 ===== */
void cspec_004fa1b0(int param_1)



{

  int iVar1;

  

  iVar1 = *(int *)(param_1 + 0x100);

  obj_ptr_clear_if_dead(iVar1 + 0x28);

  obj_ptr_clear_if_dead(iVar1 + 0x14);

  return;

}

/* ===== AudioDataStreamStatus__Fv_3 @ 0x004FA1E0 ===== */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */



undefined4 * AudioDataStreamStatus__Fv_3(void)



{

  return &DAT_00632900;

}

/* ===== terrain_mesh_query @ 0x004FA1F0 ===== */
void terrain_mesh_query(int param_1,int *param_2,int param_3)



{

  float *pfVar1;

  float fVar2;

  float fVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  float fVar7;

  float fVar8;

  int iVar9;

  float *pfVar10;

  int iVar11;

  ushort *puVar12;

  float *pfVar13;

  byte *pbVar14;

  int local_8;

  

  param_2 = (int *)(*(int *)(param_1 + 0x18) + (int)param_2 * 0x24);

  if (param_3 < 0) {

    local_8 = param_2[1];

    param_2 = (int *)*param_2;

    if (local_8 == 0) {

      return;

    }

  }

  else {

    param_2 = (int *)(*param_2 + param_3 * 4);

    local_8 = 1;

  }

  do {

    iVar4 = *param_2;

    if ((*(byte *)(iVar4 + 0x18) & 1) != 0) {

      iVar11 = *(int *)(iVar4 + 0x4c) * 4;

      iVar5 = *(int *)(iVar11 + *(int *)(param_1 + 8));

      iVar6 = *(int *)(iVar5 + 0x14);

      iVar9 = *(int *)(iVar4 + 0x14) * 0x50;

      iVar4 = *(int *)(iVar9 + 0x88 + iVar5);

      puVar12 = (ushort *)(*(int *)(iVar5 + 0x34) + iVar4 * 2);

      pfVar10 = (float *)(iVar4 * 0x38 + *(int *)(*(int *)(param_1 + 0xc) + iVar11));

      pfVar13 = (float *)(*(int *)(iVar5 + 0x3c) + iVar4 * 8);

      if (*(int *)(iVar5 + 0x40) == 0) {

        pbVar14 = (byte *)0x0;

      }

      else {

        pbVar14 = (byte *)(iVar4 + *(int *)(iVar5 + 0x40));

      }

      for (iVar4 = *(int *)(iVar9 + iVar5 + 0x8c); iVar4 != 0; iVar4 = iVar4 + -1) {

        fVar7 = (float)*(int *)(param_1 + 0x24) /

                (*(float *)(iVar5 + 0x50) - *(float *)(iVar5 + 0x44));

        pfVar1 = (float *)(iVar6 + (uint)*puVar12 * 0xc);

        fVar8 = (float)*(int *)(param_1 + 0x28) /

                (*(float *)(iVar5 + 0x54) - *(float *)(iVar5 + 0x48));

        fVar2 = *(float *)(iVar5 + 0x48);

        fVar3 = *(float *)(iVar5 + 0x54);

        *pfVar10 = fVar7 * *pfVar1 +

                   (*(float *)(iVar5 + 0x44) + *(float *)(iVar5 + 0x50)) * fVar7 * -0.5;

        pfVar10[1] = fVar8 * pfVar1[1] + (fVar2 + fVar3) * fVar8 * -0.5;

        pfVar10[2] = pfVar1[2];

        pfVar10[0xb] = *pfVar13;

        pfVar10[0xc] = pfVar13[1];

        if (pbVar14 == (byte *)0x0) {

          pfVar10[10] = 2.3509886e-38;

        }

        else {

          pfVar10[10] = (float)((uint)(pbVar14[1] < 8) | (uint)*pbVar14 << 0x10);

        }

        *(undefined1 *)(pfVar10 + 0xd) = 0;

        puVar12 = puVar12 + 1;

        pfVar10 = pfVar10 + 0xe;

        pfVar13 = pfVar13 + 2;

        if (pbVar14 != (byte *)0x0) {

          pbVar14 = pbVar14 + 3;

        }

      }

    }

    param_2 = param_2 + 1;

    local_8 = local_8 + -1;

  } while (local_8 != 0);

  return;

}

/* ===== textrender_glyph_quad @ 0x004FA380 ===== */
void textrender_glyph_quad

               (int param_1,int param_2,undefined4 param_3,float param_4,float param_5,float param_6

               ,float param_7)



{

  int iVar1;

  int iVar2;

  undefined4 uVar3;

  int iVar4;

  

  if ((*(uint *)(param_2 + 0x18) & 1) != 0) {

    iVar4 = *(int *)(param_2 + 0x4c) * 4;

    iVar1 = *(int *)(*(int *)(param_1 + 0xc) + iVar4);

    iVar4 = *(int *)(*(int *)(param_1 + 8) + iVar4) + 0x74 + *(int *)(param_2 + 0x14) * 0x50;

    iVar2 = *(int *)(iVar4 + 0x14);

    uVar3 = *(undefined4 *)(iVar4 + 0x18);

    *(float *)(param_2 + 0x34) = param_4 * *(float *)(param_2 + 0x1c) + param_6;

    *(float *)(param_2 + 0x38) = param_5 * *(float *)(param_2 + 0x20) + param_7;

    *(float *)(param_2 + 0x40) = param_4 * *(float *)(param_2 + 0x28) + param_6;

    *(float *)(param_2 + 0x44) = param_5 * *(float *)(param_2 + 0x2c) + param_7;

    textrender_node_transform

              (iVar2 * 0x38 + iVar1,param_4,param_5,param_6,param_7,*(undefined4 *)(param_2 + 0x54),

               uVar3);

    return;

  }

  if ((*(uint *)(param_2 + 0x18) & 4) != 0) {

    *(float *)(param_2 + 0x34) =

         (float)DAT_00632e84 * *(float *)(param_2 + 0x1c) * param_4 * 0.0015625 + param_6;

    *(float *)(param_2 + 0x38) =

         (float)DAT_00632e88 * *(float *)(param_2 + 0x20) * param_5 * 0.0020833334 + param_7;

    *(float *)(param_2 + 0x40) =

         (float)DAT_00632e84 * *(float *)(param_2 + 0x28) * param_4 * 0.0015625 + param_6;

    *(float *)(param_2 + 0x44) =

         (float)DAT_00632e88 * *(float *)(param_2 + 0x2c) * param_5 * 0.0020833334 + param_7;

  }

  return;

}

/* ===== FUN_004fa490 @ 0x004FA490 ===== */
void FUN_004fa490(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,

                 undefined4 param_6,float param_7,float param_8)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  undefined4 *puVar4;

  

  iVar2 = *(int *)(param_1 + 0x24);

  piVar1 = (int *)(*(int *)(param_1 + 0x18) + param_2 * 0x24);

  iVar3 = *(int *)(param_1 + 0x28);

  if (param_3 < 0) {

    param_2 = piVar1[1];

    puVar4 = (undefined4 *)*piVar1;

    if (param_2 == 0) {

      return;

    }

  }

  else {

    param_2 = 1;

    puVar4 = (undefined4 *)(*piVar1 + param_3 * 4);

  }

  do {

    textrender_glyph_quad

              (param_1,*puVar4,param_4,param_5,param_6,(float)iVar2 * param_7,(float)iVar3 * param_8

              );

    puVar4 = puVar4 + 1;

    param_2 = param_2 + -1;

  } while (param_2 != 0);

  return;

}

/* ===== hurt_pusher_2 @ 0x004FA520 ===== */
/* PS2 candidate: hurt_pusher (conf 0.292) */



void hurt_pusher_2(int param_1,float param_2)



{

  int iVar1;

  undefined4 uVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  uint uVar9;

  uint uVar10;

  uint uVar11;

  uint uVar12;

  

  iVar4 = (int)param_2;

  iVar5 = *(int *)((int)param_2 + 0x4c) * 4;

  iVar1 = *(int *)(iVar5 + *(int *)(param_1 + 8));

  uVar2 = *(undefined4 *)(iVar5 + *(int *)(param_1 + 0xc));

  if ((*(byte *)((int)param_2 + 0x18) & 1) != 0) {

    uVar9 = 0;

    uVar11 = 0x60;

    if (*(code **)((int)param_2 + 4) != (code *)0x0) {

      uVar9 = (**(code **)((int)param_2 + 4))(param_1,param_2,0,(int)param_2 + 4);

      uVar11 = 0x23060;

    }

    if ((*(byte *)((int)param_2 + 0x18) & 2) != 0) {

      iVar5 = *(int *)((int)param_2 + 0x14);

      iVar3 = *(int *)(iVar5 * 0x50 + 0x90 + iVar1);

      iVar6 = iVar5 * 0x50 + iVar1;

      iVar7 = __ftol();

      uVar10 = uVar9 | iVar7 << 0x18;

      param_2 = *(float *)(iVar6 + 0x98) + *(float *)((int)param_2 + 0x50);

      if (1.0 < param_2) {

        param_2 = 1.0;

      }

      uVar12 = uVar11;

      if (iVar3 != 0) {

        texture_alloc_helper(iVar3);

        uVar12 = uVar11 | 4;

        iVar8 = objspec_get_movetype(iVar3);

        if (iVar8 != 0) {

          uVar12 = uVar11 | 0x30c;

        }

      }

      if ((uVar9 & 0xff000000) != 0 || iVar7 << 0x18 != 0) {

        uVar12 = uVar12 & 0xffff0fff;

        uVar11 = *(uint *)((iVar5 * 5 + 10) * 0x10 + iVar1) & 0xf0;

        if (uVar11 == 0x10) {

          uVar12 = uVar12 | 0x1080;

        }

        else if (uVar11 == 0x20) {

          uVar12 = uVar12 | 0x3080;

        }

        else {

          uVar12 = uVar12 | 0x2080;

        }

      }

      if (param_2 != 0.0) {

        uVar11 = *(uint *)((iVar5 * 5 + 10) * 0x10 + iVar1) & 0xf;

        if (uVar11 == 1) {

          uVar12 = uVar12 | 0x100;

        }

        else if (uVar11 == 2) {

          uVar12 = uVar12 | 0x200;

        }

        else {

          uVar12 = uVar12 | 0x300;

        }

        uVar12 = uVar12 | 0x40000;

      }

      if ((uVar12 & 0xf00) != 0) {

        iVar7 = __ftol();

        uVar10 = uVar9 & 0xffffff | iVar7 << 0x18;

      }

      if ((~uVar10 & 0xff000000) != 0) {

        uVar12 = uVar12 | 0x40000;

      }

      (**(code **)(DAT_00656428 + 8))(DAT_00656428,uVar12,iVar3,uVar10);

      FUN_00517830(iVar1,uVar2,iVar5);

      FUN_0042b220(*(undefined4 *)(iVar6 + 0x84));

    }

    if (*(code **)(iVar4 + 4) != (code *)0x0) {

      (**(code **)(iVar4 + 4))(param_1,iVar4,1,iVar4 + 4);

    }

  }

  return;

}

/* ===== FUN_004fa720 @ 0x004FA720 ===== */
void FUN_004fa720(int param_1,int param_2,int param_3)



{

  int iVar1;

  undefined4 *puVar2;

  

  if (param_3 < 0) {

    puVar2 = *(undefined4 **)(*(int *)(param_1 + 0x18) + param_2 * 0x24);

    iVar1 = *(int *)(*(int *)(param_1 + 0x18) + param_2 * 0x24 + 4);

    if (iVar1 == 0) {

      return;

    }

  }

  else {

    puVar2 = (undefined4 *)(*(int *)(*(int *)(param_1 + 0x18) + param_2 * 0x24) + param_3 * 4);

    iVar1 = 1;

  }

  do {

    hurt_pusher_2(param_1,*puVar2);

    puVar2 = puVar2 + 1;

    iVar1 = iVar1 + -1;

  } while (iVar1 != 0);

  return;

}

/* ===== FUN_004fa780 @ 0x004FA780 ===== */
void FUN_004fa780(int param_1,int param_2)



{

  param_1 = param_1 * 0x58;

  if (param_2 != 0) {

    *(uint *)(&DAT_00562528 + param_1) = *(uint *)(&DAT_00562528 + param_1) | 2;

    return;

  }

  *(uint *)(&DAT_00562528 + param_1) = *(uint *)(&DAT_00562528 + param_1) & 0xfffffffd;

  return;

}

/* ===== text_num_parse @ 0x004FDD00 ===== */
float10 text_num_parse(int param_1,undefined4 param_2,int param_3,int param_4,float param_5,

                      float param_6,float param_7,float param_8)



{

  char *pcVar1;

  int iVar2;

  char cVar3;

  int iVar4;

  float fVar5;

  float fVar6;

  int *piVar7;

  char *pcVar8;

  int iVar9;

  int iVar10;

  undefined4 *puVar11;

  char local_c;

  char local_b [11];

  

  iVar4 = *(int *)(*(int *)(param_1 + 0x18) + 0xd8);

  crt_itoa_wrapper(param_2,&local_c,10);

  if (local_c == '-') {

    local_c = ':';

  }

  fVar6 = 0.0;

  pcVar8 = &local_c;

  cVar3 = local_c;

  fVar5 = param_7;

  while (cVar3 != '\0') {

    fVar5 = *(float *)(iVar4 + -0xc0 + cVar3 * 4);

    pcVar1 = pcVar8 + 1;

    pcVar8 = pcVar8 + 1;

    fVar6 = (*(float *)((int)fVar5 + 0x28) - *(float *)((int)fVar5 + 0x1c)) + fVar6;

    cVar3 = *pcVar1;

  }

  if (param_3 != 0) {

    param_7 = param_7 - (fVar6 * param_5) / (float)((3 - param_3) * *(int *)(param_1 + 0x24));

  }

  if (param_4 != 0) {

    param_8 = param_8 - ((*(float *)((int)fVar5 + 0x2c) - *(float *)((int)fVar5 + 0x20)) * param_6)

                        / (float)(*(int *)(param_1 + 0x28) * (3 - param_4));

  }

  pcVar8 = &local_c;

  cVar3 = local_c;

  while( true ) {

    if (cVar3 == '\0') {

      return (float10)param_7;

    }

    iVar10 = *(int *)(param_1 + 0x24);

    piVar7 = (int *)(*(int *)(param_1 + 0x18) + 0xd8);

    iVar2 = *(int *)(param_1 + 0x28);

    if (-1 < *pcVar8 + -0x30) break;

    puVar11 = (undefined4 *)*piVar7;

    for (iVar9 = *(int *)(*(int *)(param_1 + 0x18) + 0xdc); iVar9 != 0; iVar9 = iVar9 + -1) {

LAB_004fde16:

      textrender_glyph_quad

                (param_1,*puVar11,0,param_5,param_6,(float)iVar10 * param_7,(float)iVar2 * param_8);

      puVar11 = puVar11 + 1;

    }

    if (-1 < *pcVar8 + -0x30) {

      puVar11 = (undefined4 *)(*(int *)(*(int *)(param_1 + 0x18) + 0xd8) + (*pcVar8 + -0x30) * 4);

      iVar10 = 1;

      goto LAB_004fde80;

    }

    puVar11 = *(undefined4 **)(*(int *)(param_1 + 0x18) + 0xd8);

    for (iVar10 = *(int *)(*(int *)(param_1 + 0x18) + 0xdc); iVar10 != 0; iVar10 = iVar10 + -1) {

LAB_004fde80:

      hurt_pusher_2(param_1,*puVar11);

      puVar11 = puVar11 + 1;

    }

    iVar10 = *(int *)(iVar4 + -0xc0 + *pcVar8 * 4);

    pcVar8 = pcVar8 + 1;

    cVar3 = *pcVar8;

    param_7 = ((*(float *)(iVar10 + 0x28) - *(float *)(iVar10 + 0x1c)) * param_5) /

              (float)*(int *)(param_1 + 0x24) + param_7;

  }

  iVar9 = 1;

  puVar11 = (undefined4 *)(*piVar7 + (*pcVar8 + -0x30) * 4);

  goto LAB_004fde16;

}

/* ===== textrender_string_draw @ 0x004FDED0 ===== */
int textrender_string_draw(int param_1,int param_2,float param_3,float param_4,undefined4 param_5)



{

  int iVar1;

  int iVar2;

  uint uVar3;

  int iVar4;

  int iVar5;

  undefined4 *puVar6;

  

  iVar2 = *(int *)(param_2 * 4 + *(int *)(*(int *)(param_1 + 0x18) + 0x240));

  uVar3 = *(uint *)(iVar2 + 0x18);

  *(uint *)(iVar2 + 0x18) = uVar3 | 2;

  *(undefined4 *)(iVar2 + 0x50) = param_5;

  iVar5 = *(int *)(param_1 + 0x24);

  puVar6 = *(undefined4 **)(*(int *)(param_1 + 0x18) + 0x240);

  iVar1 = *(int *)(param_1 + 0x28);

  if (param_2 < 0) {

    iVar4 = *(int *)(*(int *)(param_1 + 0x18) + 0x244);

    if (iVar4 == 0) goto LAB_004fdf63;

  }

  else {

    iVar4 = 1;

    puVar6 = puVar6 + param_2;

  }

  do {

    textrender_glyph_quad

              (param_1,*puVar6,0,0x3f800000,0x3f800000,(float)iVar5 * param_3,(float)iVar1 * param_4

              );

    puVar6 = puVar6 + 1;

    iVar4 = iVar4 + -1;

  } while (iVar4 != 0);

LAB_004fdf63:

  if (param_2 < 0) {

    puVar6 = *(undefined4 **)(*(int *)(param_1 + 0x18) + 0x240);

    iVar5 = *(int *)(*(int *)(param_1 + 0x18) + 0x244);

    if (iVar5 == 0) {

      *(uint *)(iVar2 + 0x18) = uVar3;

      return iVar2;

    }

  }

  else {

    puVar6 = (undefined4 *)(*(int *)(*(int *)(param_1 + 0x18) + 0x240) + param_2 * 4);

    iVar5 = 1;

  }

  do {

    hurt_pusher_2(param_1,*puVar6);

    puVar6 = puVar6 + 1;

    iVar5 = iVar5 + -1;

  } while (iVar5 != 0);

  *(uint *)(iVar2 + 0x18) = uVar3;

  return iVar2;

}

/* ===== textrender_string_draw_2 @ 0x004FDFD0 ===== */
int textrender_string_draw_2

              (int param_1,int param_2,undefined4 param_3,undefined4 param_4,float param_5,

              float param_6,undefined4 param_7)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  undefined4 *puVar5;

  

  iVar2 = *(int *)(param_2 * 4 + *(int *)(*(int *)(param_1 + 0x18) + 0x240));

  *(undefined4 *)(iVar2 + 0x50) = param_7;

  iVar4 = *(int *)(param_1 + 0x24);

  puVar5 = *(undefined4 **)(*(int *)(param_1 + 0x18) + 0x240);

  iVar1 = *(int *)(param_1 + 0x28);

  if (param_2 < 0) {

    iVar3 = *(int *)(*(int *)(param_1 + 0x18) + 0x244);

    if (iVar3 == 0) goto LAB_004fe060;

  }

  else {

    iVar3 = 1;

    puVar5 = puVar5 + param_2;

  }

  do {

    textrender_glyph_quad

              (param_1,*puVar5,0,param_3,param_4,(float)iVar4 * param_5,(float)iVar1 * param_6);

    puVar5 = puVar5 + 1;

    iVar3 = iVar3 + -1;

  } while (iVar3 != 0);

LAB_004fe060:

  if (param_2 < 0) {

    puVar5 = *(undefined4 **)(*(int *)(param_1 + 0x18) + 0x240);

    iVar4 = *(int *)(*(int *)(param_1 + 0x18) + 0x244);

    if (iVar4 == 0) {

      return iVar2;

    }

  }

  else {

    puVar5 = (undefined4 *)(*(int *)(*(int *)(param_1 + 0x18) + 0x240) + param_2 * 4);

    iVar4 = 1;

  }

  do {

    hurt_pusher_2(param_1,*puVar5);

    puVar5 = puVar5 + 1;

    iVar4 = iVar4 + -1;

  } while (iVar4 != 0);

  return iVar2;

}

/* ===== terrain_uv_sample @ 0x004FE0F0 ===== */
int terrain_uv_sample(int param_1,int param_2,float param_3,float param_4,float param_5,

                     float param_6,int param_7)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  undefined4 *puVar5;

  

  iVar4 = *(int *)(param_1 + 0x18);

  iVar3 = *(int *)(param_2 * 4 + *(int *)(iVar4 + 0xfc));

  if (param_7 != 0) {

    param_5 = param_5 - ((*(float *)(iVar3 + 0x28) - *(float *)(iVar3 + 0x1c)) * param_3) /

                        (float)(*(int *)(param_1 + 0x24) << 1);

    param_6 = param_6 - ((*(float *)(iVar3 + 0x2c) - *(float *)(iVar3 + 0x20)) * param_4) /

                        (float)(*(int *)(param_1 + 0x28) << 1);

  }

  iVar1 = *(int *)(param_1 + 0x24);

  puVar5 = *(undefined4 **)(iVar4 + 0xfc);

  iVar2 = *(int *)(param_1 + 0x28);

  if (param_2 < 0) {

    iVar4 = *(int *)(iVar4 + 0x100);

    if (iVar4 == 0) goto LAB_004fe1c0;

  }

  else {

    iVar4 = 1;

    puVar5 = puVar5 + param_2;

  }

  do {

    textrender_glyph_quad

              (param_1,*puVar5,0,param_3,param_4,(float)iVar1 * param_5,param_6 * (float)iVar2);

    puVar5 = puVar5 + 1;

    iVar4 = iVar4 + -1;

  } while (iVar4 != 0);

LAB_004fe1c0:

  if (param_2 < 0) {

    puVar5 = *(undefined4 **)(*(int *)(param_1 + 0x18) + 0xfc);

    iVar4 = *(int *)(*(int *)(param_1 + 0x18) + 0x100);

    if (iVar4 == 0) {

      return iVar3;

    }

  }

  else {

    puVar5 = (undefined4 *)(*(int *)(*(int *)(param_1 + 0x18) + 0xfc) + param_2 * 4);

    iVar4 = 1;

  }

  do {

    hurt_pusher_2(param_1,*puVar5);

    puVar5 = puVar5 + 1;

    iVar4 = iVar4 + -1;

  } while (iVar4 != 0);

  return iVar3;

}

/* ===== mission_004fe2d0 @ 0x004FE2D0 ===== */
void mission_004fe2d0(int param_1,int param_2,float param_3,float param_4,float *param_5,

                     float *param_6)



{

  *param_5 = (param_3 * *(float *)(param_2 + 0x40) + (1.0 - param_3) * *(float *)(param_2 + 0x34)) /

             (float)*(int *)(param_1 + 0x24);

  *param_6 = (param_4 * *(float *)(param_2 + 0x44) + (1.0 - param_4) * *(float *)(param_2 + 0x38)) /

             (float)*(int *)(param_1 + 0x28);

  return;

}

/* ===== comm_game_objects_release @ 0x004FF470 ===== */
void comm_game_objects_release(void)



{

  if (DAT_00632bb8 != 0) {

    partyhouse_exit_dlog();

  }

  if (DAT_00632bb0 != 0) {

    dlog_pop_user();

  }

  if (DAT_00632bb4 != 0) {

    giftshop_exit__Fv();

  }

  if ((DAT_00632bac != 0) && (DAT_00632a88 != 0)) {

    turret_exit_all_team(DAT_00632a88);

  }

  if (DAT_00632ba8 != 0) {

    dlog_text_pop_screen(1);

  }

  return;

}

/* ===== status_update_entry @ 0x004FF6A0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void status_update_entry(float param_1)



{

  uint uVar1;

  float fVar2;

  int iVar3;

  int iVar4;

  undefined4 *puVar5;

  float local_34;

  undefined4 local_30;

  float local_2c;

  float local_28;

  undefined1 local_24 [4];

  undefined1 local_20 [4];

  undefined1 local_1c [4];

  undefined4 local_18;

  undefined4 local_14;

  float local_10;

  undefined1 local_c [12];

  

  fVar2 = param_1;

  if ((((((*(uint *)((int)param_1 + 0xd8) & 0x4000c000) == 0) &&

        (*(float *)((int)param_1 + 0x278) < *(float *)((int)param_1 + 0x1c0))) &&

       (param_1 != DAT_00632a88)) &&

      ((iVar3 = ObjIsMecc(param_1), iVar3 == 0 || ((*(uint *)((int)fVar2 + 0xe0) & 0x2000000) == 0))

      )) && ((iVar3 = ObjIsReaper(fVar2), iVar3 == 0 ||

             (*(int *)(*(int *)((int)fVar2 + 0x100) + 0xe2c) == 0)))) {

    XFGetViewportExt(local_1c,local_20,local_24,local_c);

    local_30 = *(undefined4 *)((int)fVar2 + 4);

    local_18 = *(undefined4 *)((int)fVar2 + 0xa0);

    local_14 = *(undefined4 *)((int)fVar2 + 0xa4);

    local_10 = *(float *)((int)fVar2 + 0x1ec) * *(float *)((int)fVar2 + 0xc4) +

               *(float *)((int)fVar2 + 0xa8) + 2.0;

    iVar3 = 1;

    iVar4 = ai_class_filter(local_c,&local_18,1,&local_30,0);

    if ((iVar4 != 0) && (iVar4 = hud_clipcode_calc(&local_18,&param_1,&local_34), iVar4 == 0)) {

      uVar1 = (uint)(*(int *)((int)DAT_00632a88 + 0x18c) == *(int *)((int)fVar2 + 0x18c));

      main_status_00500520(&DAT_00632900);

      local_28 = (param_1 / (float)DAT_00632e84) * (float)DAT_00632924;

      if (_DAT_00633254 == 1) {

        fVar2 = (local_34 / (float)DAT_00632e88) * (float)DAT_00632928;

        local_2c = fVar2;

        if (-1 < (int)uVar1) {

          puVar5 = (undefined4 *)(*(int *)(DAT_00632918 + 0x33c) + uVar1 * 4);

          goto LAB_004ff830;

        }

        puVar5 = *(undefined4 **)(DAT_00632918 + 0x33c);

        for (iVar3 = *(int *)(DAT_00632918 + 0x340); iVar3 != 0; iVar3 = iVar3 + -1) {

LAB_004ff830:

          textrender_glyph_quad(&DAT_00632900,*puVar5,0,0x3f000000,0x3f000000,local_28,fVar2);

          puVar5 = puVar5 + 1;

        }

        if ((int)uVar1 < 0) {

          puVar5 = *(undefined4 **)(DAT_00632918 + 0x33c);

          iVar3 = *(int *)(DAT_00632918 + 0x340);

          if (iVar3 == 0) {

            return;

          }

        }

        else {

          puVar5 = (undefined4 *)(*(int *)(DAT_00632918 + 0x33c) + uVar1 * 4);

          iVar3 = 1;

        }

        do {

          hurt_pusher_2(&DAT_00632900,*puVar5);

          puVar5 = puVar5 + 1;

          iVar3 = iVar3 + -1;

        } while (iVar3 != 0);

        return;

      }

      fVar2 = (local_34 / (float)DAT_00632e88) * (float)DAT_00632928;

      local_2c = local_28;

      local_28 = fVar2;

      if (-1 < (int)uVar1) {

        puVar5 = (undefined4 *)(*(int *)(DAT_00632918 + 0x33c) + uVar1 * 4);

        goto LAB_004ff8e2;

      }

      puVar5 = *(undefined4 **)(DAT_00632918 + 0x33c);

      for (iVar3 = *(int *)(DAT_00632918 + 0x340); iVar3 != 0; iVar3 = iVar3 + -1) {

LAB_004ff8e2:

        textrender_glyph_quad(&DAT_00632900,*puVar5,0,0x3f800000,0x3f800000,local_2c,fVar2);

        puVar5 = puVar5 + 1;

      }

      if ((int)uVar1 < 0) {

        puVar5 = *(undefined4 **)(DAT_00632918 + 0x33c);

        iVar3 = *(int *)(DAT_00632918 + 0x340);

        if (iVar3 == 0) {

          return;

        }

      }

      else {

        puVar5 = (undefined4 *)(*(int *)(DAT_00632918 + 0x33c) + uVar1 * 4);

        iVar3 = 1;

      }

      do {

        hurt_pusher_2(&DAT_00632900,*puVar5);

        puVar5 = puVar5 + 1;

        iVar3 = iVar3 + -1;

      } while (iVar3 != 0);

    }

  }

  return;

}

/* ===== point_left_of_line @ 0x004FFE50 ===== */
bool point_left_of_line(float param_1,float param_2,int param_3,int param_4,int param_5)



{

  if (0.0 <= (*(float *)(param_3 + 0x1c) - *(float *)(param_5 + 0x1c)) *

             (param_1 - *(float *)(param_5 + 0x18)) -

             (*(float *)(param_3 + 0x18) - *(float *)(param_5 + 0x18)) *

             (param_2 - *(float *)(param_5 + 0x1c))) {

    return 0.0 <= (param_1 - *(float *)(param_3 + 0x18)) *

                  (*(float *)(param_4 + 0x1c) - *(float *)(param_3 + 0x1c)) -

                  (*(float *)(param_4 + 0x18) - *(float *)(param_3 + 0x18)) *

                  (param_2 - *(float *)(param_3 + 0x1c)) &&

           0.0 <= (param_1 - *(float *)(param_4 + 0x18)) *

                  (*(float *)(param_5 + 0x1c) - *(float *)(param_4 + 0x1c)) -

                  (param_2 - *(float *)(param_4 + 0x1c)) *

                  (*(float *)(param_5 + 0x18) - *(float *)(param_4 + 0x18));

  }

  return false;

}

/* ===== FUN_004fff10 @ 0x004FFF10 ===== */
int FUN_004fff10(int *param_1,int param_2,int param_3)



{

  float fVar1;

  float fVar2;

  int iVar3;

  int iVar4;

  int *piVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  int local_10;

  int local_c;

  undefined4 local_8;

  undefined4 local_4;

  

  iVar3 = (int)param_1;

  fVar1 = *(float *)((int)param_1 + 0x2c);

  fVar2 = *(float *)((int)param_1 + 0x30);

  piVar5 = (int *)(*(int *)((int)param_1 + 0x18) + param_2 * 0x24);

  if (param_3 < 0) {

    iVar7 = piVar5[1];

    param_1 = (int *)(*piVar5 + -4 + iVar7 * 4);

  }

  else {

    param_1 = (int *)(*piVar5 + param_3 * 4);

    iVar7 = 1;

  }

  param_2 = -1;

  piVar5 = param_1;

  iVar6 = iVar7;

  iVar8 = -1;

  if (iVar7 != 0) {

    do {

      *(uint *)(*piVar5 + 0x18) = *(uint *)(*piVar5 + 0x18) & 0xffffc3ff;

      iVar6 = iVar6 + -1;

      piVar5 = piVar5 + -1;

    } while (iVar6 != 0);

    while (iVar7 = iVar7 + -1, iVar8 = param_2, param_2 < 0) {

      iVar6 = *param_1;

      if ((*(uint *)(iVar6 + 0x18) & 1) == 0) {

        if (((((*(uint *)(iVar6 + 0x18) & 4) != 0) && (*(float *)(iVar6 + 0x34) <= fVar1)) &&

            (fVar1 < *(float *)(iVar6 + 0x40) != (fVar1 == *(float *)(iVar6 + 0x40)))) &&

           ((*(float *)(iVar6 + 0x38) <= fVar2 &&

            (fVar2 < *(float *)(iVar6 + 0x44) != (fVar2 == *(float *)(iVar6 + 0x44)))))) {

          if (*(code **)(iVar6 + 0xc) == (code *)0x0) {

            return iVar7;

          }

          iVar6 = (**(code **)(iVar6 + 0xc))(iVar3,iVar6,0,iVar6 + 0xc);

          param_2 = iVar7;

          if (iVar6 != 0) {

            return iVar7;

          }

        }

      }

      else {

        iVar4 = *(int *)(iVar6 + 0x4c) * 4;

        iVar8 = *(int *)(iVar4 + *(int *)(iVar3 + 0xc));

        local_4 = *(undefined4 *)

                   (*(int *)(*(int *)(iVar3 + 8) + iVar4) + 0x84 + *(int *)(iVar6 + 0x14) * 0x50);

        local_8 = 0xffff;

        iVar4 = collgrid_00430e10(&local_4,&local_8,&local_c,&local_10,&param_3);

        while (iVar4 != 0) {

          iVar4 = point_left_of_line(fVar1,fVar2,local_c * 0x38 + iVar8,param_3 * 0x38 + iVar8,

                                     local_10 * 0x38 + iVar8);

          if (iVar4 != 0) {

            if ((*(code **)(iVar6 + 0xc) == (code *)0x0) ||

               (iVar6 = (**(code **)(iVar6 + 0xc))(iVar3,iVar6,0,iVar6 + 0xc), iVar6 != 0)) {

              param_2 = iVar7;

            }

            break;

          }

          iVar4 = collgrid_00430e10(&local_4,&local_8,&local_c,&local_10,&param_3);

        }

      }

      param_1 = param_1 + -1;

      if (iVar7 == 0) {

        return param_2;

      }

    }

  }

  return iVar8;

}

