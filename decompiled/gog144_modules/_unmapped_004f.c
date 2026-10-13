/* Giants 1.449 — module _unmapped_004f
 * 48 functions (8 named) — decompiled, names from PS2 symbols
 * Original source: C:\Giants\source\_unmapped_004f.c(pp) (assert-string evidence)
 */

/* ===== FUN_004f38f0 @ 0x004F38F0 ===== */
/* WARNING: Type propagation algorithm not settling */

/* WARNING: Struct "OBJECT": ignoring multiple overlapping fields */

/* PS2 candidate: smartie_handle_reaper_grab__FP6OBJECTP14ObjSpecSmartie (conf 0.597) */



void FUN_004f38f0(OBJECT *param_1,int param_2)



{

  dword *pdVar1;

  float fVar2;

  dword dVar3;

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

    FUN_004f4fc0(param_1);

    return;

  }

  fVar4 = *(float *)(param_2 + 0x44) - fVar2;

  *(float *)(param_2 + 0x44) = fVar4;

  if (0.0 <= fVar4) {

    FUN_004992d0(param_1,0,0,*(float *)(DAT_00632ed8 + 0x7d8) * fVar2);

  }

  else {

    dVar3 = param_1->field_274;

    pdVar1 = &param_1->gap_A0;

    local_30[2] = *(float *)(dVar3 + 0x298) * 5.0 + *(float *)(dVar3 + 0xa0);

    local_30[1] = 0.0;

    local_24 = *(float *)(dVar3 + 0x2a8) * 5.0 + *(float *)(dVar3 + 0xa4);

    local_20 = *(float *)(dVar3 + 0xa8) + 3.0;

    local_34 = local_30[2] - (float)*pdVar1;

    local_30[0] = local_24 - *(float *)&param_1->field_0xa4;

    FUN_0050a810(&local_34,local_30,local_30 + 1);

    local_34 = *(float *)(DAT_00632ed8 + 0x7e4) * local_34;

    local_30[0] = *(float *)(DAT_00632ed8 + 0x7e4) * local_30[0];

    FUN_004992d0(param_1,local_34 * fVar2,local_30[0] * fVar2,

                 -(*(float *)(DAT_00632ed8 + 0x7e8) * fVar2));

    FUN_00414690(pdVar1,local_1c);

    if (*(float *)&param_1->field_0xa8 < local_c + 3.0) {

      *(float *)&param_1->field_0xa8 = local_c + 3.0;

    }

    fVar5 = (float10)FUN_0050a610(pdVar1,local_30 + 2);

    if ((*(uint *)(param_1->field_274 + 0xdc) & 0x800000) == 0) {

      if (fVar5 < (float10)4.0) {

        FUN_00495750(0x3b5,param_1);

        smartie_lock_to_player(param_1);

        return;

      }

    }

    else if (fVar5 < (float10)900.0) {

      FUN_004f4fc0(param_1);

      return;

    }

  }

  return;

}

/* ===== FUN_004f3af0 @ 0x004F3AF0 ===== */
/* WARNING: Struct "OBJECT": ignoring multiple overlapping fields */

/* PS2 candidate: smartie_animselect (conf 0.509) */



void FUN_004f3af0(int param_1)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  undefined4 uVar7;

  int iVar8;

  OBJECT *unaff_EDI;

  char *p0;

  char *p1;

  

  iVar3 = FUN_0052e5b0(*(undefined4 *)(param_1 + 0x14));

  if (iVar3 == 0) {

    iVar3 = object_allocate_type(*(undefined4 *)(param_1 + 0x10),0x80000000);

    *(undefined4 *)(iVar3 + 0x188) = *(undefined4 *)(param_1 + 0x14);

  }

  *(undefined4 *)(iVar3 + 0x18c) = *(undefined4 *)(param_1 + 0x20);

  FUN_004993c0(iVar3,param_1);

  *(undefined4 *)(iVar3 + 200) = *(undefined4 *)(param_1 + 0xc);

  *(undefined4 *)(iVar3 + 0xcc) = 0;

  *(undefined4 *)(iVar3 + 0xd0) = 0;

  *(undefined4 *)(iVar3 + 0xe4) = *(undefined4 *)(param_1 + 0x18);

  FUN_00418010(iVar3,*(undefined4 *)(DAT_00632ed8 + 0x894));

  *(uint *)(iVar3 + 0xd8) = *(uint *)(iVar3 + 0xd8) | 0x10;

  *(uint *)(iVar3 + 0xe0) = *(uint *)(iVar3 + 0xe0) | *(uint *)(param_1 + 0x1c);

  if (*(int *)(param_1 + 0x24) != 0) {

    sound_play_obj(*(int *)(param_1 + 0x24),iVar3);

  }

  iVar4 = FUN_0052e5b0(*(undefined4 *)(param_1 + 0x28));

  *(int *)(iVar3 + 0x274) = iVar4;

  if (iVar4 != 0) {

    iVar6 = *(int *)(iVar4 + 0x100);

    iVar5 = FUN_0052e5b0(*(undefined4 *)(param_1 + 0x2c));

    if (iVar5 != 0) {

      iVar1 = *(int *)(iVar5 + 0x100);

      iVar2 = *(int *)(iVar1 + 0x54);

      *(int *)(iVar6 + 0x574 + iVar2 * 4) = iVar3;

      iVar6 = FUN_0052e5b0(*(undefined4 *)(param_1 + 0x30));

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

        FUN_00497510(*(undefined4 *)(iVar8 + 0x30));

        *(undefined4 *)(iVar8 + 0x30) = 0;

        *(undefined4 *)(iVar8 + 0x14) = 0x41d80000;

        iVar8 = reaper_0052e4a0(iVar5);

        if (iVar8 != 0) {

          reaper_00530bd0(iVar5,0,0,0,0x14,0);

        }

      }

      *(undefined4 *)(iVar5 + 0xe4) = 0x13;

      iVar6 = FUN_004a6160(iVar6);

      if (iVar6 != 0) {

        *(undefined4 *)(iVar5 + 0x274) = *(undefined4 *)(iVar5 + 0x210);

      }

      *(undefined4 *)(iVar1 + 0x54) = 0;

      *(undefined4 *)(iVar5 + 0xec) = 0;

      iVar6 = FUN_0052aa70();

      if (iVar6 != 0) {

        iVar4 = FUN_004a6200(iVar4);

        if ((((iVar4 != 0) && (iVar2 == 3)) && (DAT_00632a88 != 0)) &&

           (*(int *)(iVar3 + 0x18c) == *(int *)(DAT_00632a88 + 0x18c))) {

          iVar3 = FUN_004d5730(100);

          if (iVar3 < 0x21) {

            p1 = *(char **)(DAT_006330e4 + 0x50e0);

            p0 = s_BAZ_CT09_00562278;

          }

          else if (iVar3 < 0x42) {

            p1 = *(char **)(DAT_006330e4 + 0x50e0);

            p0 = s_GOR_CT09_0056226c;

          }

          else {

            p1 = *(char **)(DAT_006330e4 + 0x50e0);

            p0 = s_REG_CT09_00562260;

          }

          teammecc_clear_mode((int)p0,p1,0,unaff_EDI);

          uVar7 = FUN_00507b00(s_SmChGyropadDone_00562250,1,1);

          chat_insert_name(iVar1 + 0x80,uVar7);

        }

      }

    }

  }

  return;

}

/* ===== FUN_004f3de0 @ 0x004F3DE0 ===== */
/* PS2 candidate: smartie_start_special_building (conf 0.468) */



void FUN_004f3de0(int param_1,int param_2,int param_3,int param_4,float *param_5,undefined4 param_6)



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

  

  iVar1 = FUN_004a6160(param_4);

  iVar2 = param_2 + 0x30;

  if (iVar1 == 0) {

    iVar2 = param_2 + 0x40;

  }

  pfVar3 = local_34;

  for (iVar1 = 0xd; iVar1 != 0; iVar1 = iVar1 + -1) {

    *pfVar3 = 0.0;

    pfVar3 = pfVar3 + 1;

  }

  local_24 = FUN_004a8fb0(iVar2,1);

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

  iVar1 = FUN_004a6180(param_4);

  if ((iVar1 != 0) &&

     ((((param_2 == 5 || (param_2 == 6)) && (iVar1 = *(int *)(param_4 + 0x224), iVar1 != 0)) &&

      ((*(int *)(iVar1 + 4) == 0x4a5 && (*(int *)(iVar1 + 0x18c) == *(int *)(param_4 + 0x18c)))))))

  {

    local_18 = local_18 | 0x1000;

  }

  iVar1 = FUN_004a6180(param_4);

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

  iVar1 = FUN_004a6160(param_4);

  local_10 = (-(uint)(iVar1 != 0) & 0xfffffffc) + 0x6e9;

LAB_004f3ef6:

  iVar1 = FUN_004a6180(param_4);

  if ((iVar1 != 0) && (param_2 == 3)) {

    local_3c = param_5[1];

    local_40 = *param_5 + 50.0;

    local_38 = 0;

    FUN_0045a740(&local_40,0x3c,*(undefined4 *)(iVar2 + 0x188));

    local_3c = local_3c + 15.0;

    FUN_0045a740(&local_40,0x3d,*(undefined4 *)(iVar2 + 0x188));

    local_3c = local_3c + 15.0;

    FUN_0045a740(&local_40,0x3e,*(undefined4 *)(iVar2 + 0x188));

  }

  local_c = *(undefined4 *)(param_3 + 0x188);

  local_8 = *(undefined4 *)(param_1 + 0x188);

  local_4 = *(undefined4 *)(param_4 + 0x188);

  FUN_004f3af0(local_34);

  iVar2 = FUN_0052aa70();

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

  FUN_00530d70(param_1,4,3,0,0x17,local_1c);

  return;

}

/* ===== FUN_004f40a0 @ 0x004F40A0 ===== */
/* WARNING: Struct "OBJECT": ignoring multiple overlapping fields */

/* PS2 candidate: smartie_from_back_to_partyhouse (conf 0.496) */



void FUN_004f40a0(OBJECT *param_1,int param_2,int param_3)



{

  int iVar1;

  OBJECT *pOVar2;

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

  pOVar2 = param_1;

  FUN_004f5410(param_1);

  param_1->gap_E4 = 0x37;

  FUN_004f7b50(param_1,0x2f2,pOVar2,param_2,param_3);

  FUN_004034a0(param_1,0x41,0x20,0,0,0x3f2aaaab);

  iVar1 = reaper_0052e4a0(param_1);

  if (iVar1 != 0) {

    reaper_00530bd0(param_1,0,0,0,0xb,0);

  }

  return;

}

/* ===== FUN_004f4150 @ 0x004F4150 ===== */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

/* WARNING: Struct "OBJECT": ignoring multiple overlapping fields */



void FUN_004f4150(OBJECT *obj)



{

  int iVar1;

  int *piVar2;

  

  if (*(int *)&obj->field_0xe8 == 10) {

    if ((obj->field_274 != 0) &&

       ((iVar1 = FUN_004a6200(obj->field_274), iVar1 != 0 ||

        (iVar1 = FUN_004a6290(obj->field_274), iVar1 != 0)))) {

LAB_004f4192:

      FUN_0041b390(obj);

      return;

    }

    if (DAT_00632d9c != (int *)0x0) {

      piVar2 = DAT_00632d9c;

      do {

        if (*(dword *)(piVar2[3] + 0x18c) == obj->field_18C) goto LAB_004f4192;

        piVar2 = (int *)*piVar2;

      } while (piVar2 != (int *)0x0);

    }

    *(undefined4 *)&obj->field_0xa4 = 0;

    obj->gap_A0 = 0;

    *(undefined4 *)&obj->field_0xa8 = 0x43480000;

  }

  return;

}

/* ===== FUN_004f41f0 @ 0x004F41F0 ===== */
void FUN_004f41f0(undefined4 param_1,int param_2,int param_3,int param_4)



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
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

/* WARNING: Struct "OBJECT": ignoring multiple overlapping fields */



void kabutoai_select_punch_anim__FP6OBJECT_2(OBJECT *p0)



{

  reaper_00530bd0(p0,0,0,0,0xc,0);

  return;

}

/* ===== smartie_lock_to_player @ 0x004F4C00 ===== */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

/* WARNING: Struct "OBJECT": ignoring multiple overlapping fields */



void smartie_lock_to_player(OBJECT *obj)



{

  uint *puVar1;

  int iVar2;

  undefined4 uVar3;

  int iVar4;

  dword in_stack_00000008;

  int in_stack_0000000c;

  char *pcVar5;

  undefined1 local_40 [28];

  undefined4 local_24;

  undefined4 local_20;

  OBJECT *local_1c;

  

  iVar4 = *(int *)&obj->field_0x100;

  FUN_00401000(obj);

  obj->field_274 = in_stack_00000008;

  obj->field_0x20b = 0;

  obj->field_0x20a = 0;

  obj->field_0x208 = 0;

  *(undefined4 *)(iVar4 + 0x1c) = 0xffffffff;

  *(undefined4 *)(iVar4 + 0x20) = 0xffffffff;

  *(undefined4 *)(iVar4 + 0x24) = 0xffffffff;

  *(undefined4 *)(iVar4 + 0x28) = 0xffffffff;

  *(undefined4 *)(iVar4 + 0x18) = 0;

  obj->acc_grenade_do_stopped = obj->acc_grenade_do_stopped & 0xfffdffff | 0x800;

  obj->gap_E4 = 0x13;

  *(uint *)&obj->field_0xd8 = *(uint *)&obj->field_0xd8 & 0xf7ffffff | 0x10;

  puVar1 = (uint *)(obj->field_274 + 0xdc);

  *puVar1 = *puVar1 | 0x800000;

  *(undefined4 *)(iVar4 + 0x94) = DAT_00632e6c;

  iVar2 = FUN_004a6160(obj->field_274);

  if (iVar2 == 0) {

    iVar2 = FUN_004a6180(obj->field_274);

    if (iVar2 == 0) {

      if (*(int *)(obj->field_274 + 4) == 0xd7) {

        *(dword *)&obj->field_0x210 = obj->field_274;

        *(undefined4 *)&obj->field_0x214 = 1;

        obj->field_218 = 0xb;

        *(undefined4 *)&obj->field_0xec = 0;

        *(float *)(iVar4 + 0x50) = *(float *)&obj->field_0xc4 * 0.8;

        *(float *)&obj->field_0xc4 = *(float *)&obj->field_0xc4 * 0.8;

        FUN_004a76e0(obj->field_274,0xb,local_40);

        FUN_004993c0(obj,local_40);

        obj->field_E0 = obj->field_E0 | 0x20;

      }

    }

    else {

      if (*(int *)(iVar4 + 0x3c) == 0) {

        local_1c = obj;

        local_20 = 6;

        local_24 = 8;

        uVar3 = fx_get_free_effect__Fv();

        *(undefined4 *)(iVar4 + 0x3c) = uVar3;

        *(float *)(iVar4 + 0x50) = *(float *)&obj->field_0xc4 * 0.5;

        *(float *)&obj->field_0xc4 = *(float *)&obj->field_0xc4 * 0.5;

      }

      if (*(int *)(iVar4 + 0xbc) == 0) {

        uVar3 = sound_get_free_sequence__Fv();

        *(undefined4 *)(iVar4 + 0xbc) = uVar3;

      }

    }

  }

  else {

    *(dword *)&obj->field_0x210 = obj->field_274;

    *(undefined4 *)&obj->field_0x214 = 1;

    obj->field_218 = 10;

    *(undefined4 *)&obj->field_0xec = 0;

    *(float *)(iVar4 + 0x50) = *(float *)&obj->field_0xc4 * 0.8;

    *(float *)&obj->field_0xc4 = *(float *)&obj->field_0xc4 * 0.8;

    FUN_004a76e0(obj->field_274,10,local_40);

    FUN_004993c0(obj,local_40);

    sound_play_player(0x5e6,obj->field_274);

  }

  if (obj->field_274 == DAT_00632a88) {

    FUN_00493c90(obj);

    if ((in_stack_0000000c != 0) && (obj->field_4 == 0xb)) {

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

  iVar4 = FUN_004d5730(100);

  if (iVar4 < 0x32) {

    sound_play_obj(0x6a9,obj);

    return;

  }

  sound_play_obj(0x6aa,obj);

  return;

}

/* ===== FUN_004f4ed0 @ 0x004F4ED0 ===== */
/* PS2 candidate: smartie_find_legal_nearby_base__FP6OBJECTT0 (conf 0.467) */



int FUN_004f4ed0(int param_1,int param_2)



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

    iVar4 = FUN_004a6160(param_2);

    if ((((iVar4 == 0) || (iVar4 = FUN_004a6200(iVar2), iVar4 != 0)) &&

        ((iVar4 = FUN_004a6180(param_2), iVar4 == 0 || (iVar4 = FUN_004a6290(iVar2), iVar4 != 0))))

       && ((((*(int *)(iVar2 + 0x18c) == *(int *)(param_2 + 0x18c) || (*(int *)(iVar2 + 0x18c) == 0)

             ) && ((iVar4 = FUN_004a6160(param_2), iVar4 == 0 ||

                   ((iVar4 = *(int *)(iVar1 + 0xd8), iVar4 == 0 || (iVar4 == iVar2)))))) &&

           (((iVar4 = FUN_004a6180(param_2), iVar4 == 0 ||

             ((iVar4 = *(int *)(iVar1 + 0xcfc), iVar4 == 0 || (iVar4 == iVar2)))) &&

            (fVar5 = (float10)FUN_0050a5e0(iVar2 + 0xa0,param_1 + 0xa0), fVar5 <= (float10)160000.0)

            ))))) break;

    puVar3 = (undefined4 *)*puVar3;

  }

  return iVar2;

}

/* ===== FUN_004f4fc0 @ 0x004F4FC0 ===== */
/* PS2 candidate: smartie_escape_reaper_grab (conf 0.505) */



void FUN_004f4fc0(float param_1)



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

  FUN_0050ae40(*(float *)(iVar1 + 200) + 180.0,&param_1,&local_4);

  *(float *)((int)fVar3 + 0x128) = param_1 * 30.0;

  *(float *)((int)fVar3 + 300) = local_4 * -30.0;

  if (*(int *)(iVar2 + 0x3c) != 0) {

    FUN_00448920(*(int *)(iVar2 + 0x3c));

  }

  *(undefined4 *)(iVar2 + 0x3c) = 0;

  if (*(int *)(iVar2 + 0xbc) != 0) {

    FUN_00495ee0(iVar2 + 0xbc);

  }

  if (*(int *)((int)fVar3 + 0xe8) == 2) {

    FUN_004034a0(fVar3,1,0x21,0,0,0x3e2aaaab);

    *(uint *)((int)fVar3 + 0xe0) = *(uint *)((int)fVar3 + 0xe0) | 0x11;

    fVar4 = (float10)FUN_00413e40((int)fVar3 + 0xa0);

    *(float *)((int)fVar3 + 0xa8) = (float)fVar4;

    FUN_00499280(fVar3);

  }

  return;

}

/* ===== smartie_unlock_from_player @ 0x004F50C0 ===== */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

/* WARNING: Struct "OBJECT": ignoring multiple overlapping fields */



void smartie_unlock_from_player(OBJECT *obj)



{

  dword *pdVar1;

  int iVar2;

  undefined4 *puVar3;

  int iVar4;

  int iVar5;

  float10 fVar6;

  int in_stack_00000008;

  int in_stack_0000000c;

  undefined4 uVar7;

  char *pcVar8;

  float local_8;

  float local_4;

  

  iVar5 = *(int *)&obj->field_0x100;

  obj->field_274 = 0;

  *(undefined4 *)&obj->field_0x210 = 0;

  obj->field_184 = 0;

  *(uint *)&obj->field_0xd8 = *(uint *)&obj->field_0xd8 & 0xbfffffff;

  if (*(int *)(iVar5 + 0x30) != 0) {

    *(undefined4 *)(*(int *)(iVar5 + 0x30) + 0x210) = 0;

    FUN_00497510(*(undefined4 *)(iVar5 + 0x30));

    *(undefined4 *)(iVar5 + 0x30) = 0;

    *(undefined4 *)(iVar5 + 0x14) = 0x41d80000;

    iVar4 = reaper_0052e4a0(obj);

    if (iVar4 != 0) {

      reaper_00530bd0(obj,0,0,0,0x14,0);

    }

  }

  obj->field_E0 = obj->field_E0 & 0xffffffdf;

  *(uint *)&obj->field_0xd8 = *(uint *)&obj->field_0xd8 & 0xfff7ffef;

  *(uint *)(in_stack_00000008 + 0xdc) = *(uint *)(in_stack_00000008 + 0xdc) & 0xff7fffff;

  obj->acc_grenade_do_stopped = obj->acc_grenade_do_stopped & 0xfffff7ff | 0x20000;

  FUN_0050ae40(*(float *)(in_stack_00000008 + 200) + 180.0,&local_8,&local_4);

  iVar4 = *(int *)&obj->field_0xe8;

  *(undefined4 *)&obj->field_0xec = 0x3f800000;

  obj->gap_128 = (dword)(local_8 * 30.0);

  *(float *)&obj->field_0x12c = local_4 * -30.0;

  if (iVar4 == 10) {

    obj->gap_E4 = 0x34;

    *(undefined4 *)&obj->field_0xf0 = 0x41a00000;

  }

  else if (iVar4 == 5) {

    obj->gap_E4 = 0x52;

    FUN_004f7b50(obj,0x2f2);

    for (puVar3 = DAT_00632d98; puVar3 != (undefined4 *)0x0; puVar3 = (undefined4 *)*puVar3) {

      iVar4 = puVar3[3];

      if ((*(int *)(iVar4 + 4) == 0xb) && (*(int *)(iVar4 + 0xe8) == 5)) {

        pdVar1 = &obj->gap_A0;

        iVar2 = iVar4 + 0xa0;

        fVar6 = (float10)FUN_0050a5e0(iVar2,pdVar1);

        if (fVar6 <= (float10)1600.0) {

          fVar6 = (float10)FUN_0050a400(iVar2,pdVar1);

          main_ai_move_00401910(iVar4,(float)fVar6);

          fVar6 = (float10)FUN_0050a400(pdVar1,iVar2);

          main_ai_move_00401910(obj,(float)fVar6);

        }

      }

    }

  }

  else {

    if (iVar4 == 2) {

      FUN_004034a0(obj,1,0x21,0,0,0x3e2aaaab);

      obj->field_E0 = obj->field_E0 | 0x11;

      fVar6 = (float10)FUN_00413e40(&obj->gap_A0);

      *(float *)&obj->field_0xa8 = (float)fVar6;

      FUN_00499280(obj);

    }

    obj->gap_E4 = 4;

  }

  iVar4 = FUN_004a6180(in_stack_00000008);

  if (iVar4 == 0) {

    iVar4 = FUN_004a6160(in_stack_00000008);

    if (iVar4 != 0) {

      uVar7 = 0x5e5;

      goto LAB_004f5334;

    }

  }

  else {

    if (*(int *)(iVar5 + 0x3c) != 0) {

      FUN_00448920(*(int *)(iVar5 + 0x3c));

      *(undefined4 *)(iVar5 + 0x3c) = 0;

    }

    if (*(int *)(iVar5 + 0xbc) != 0) {

      FUN_00495ee0(iVar5 + 0xbc);

    }

    uVar7 = 0x39b;

LAB_004f5334:

    sound_play_player(uVar7,in_stack_00000008);

  }

  *(undefined4 *)(iVar5 + 0x54) = 0;

  *(float *)&obj->field_0xc4 = *(float *)(iVar5 + 0x50) + *(float *)&obj->field_0xc4;

  iVar4 = FUN_0052e480(in_stack_00000008);

  if (((iVar4 != 0) && (*(int *)(iVar5 + 0x54) == 0)) && (obj->field_4 == 0xb)) {

    if (in_stack_0000000c == 1) {

      pcVar8 = s_SmChDropoff_005622c0;

    }

    else {

      if (in_stack_0000000c != 5) goto LAB_004f539d;

      pcVar8 = s_SmChDropBase_005622cc;

    }

    uVar7 = TextGetPtrRandom(pcVar8,4,0);

    chat_insert_name(iVar5 + 0x80,uVar7);

  }

LAB_004f539d:

  iVar5 = FUN_004d5730(100);

  if (iVar5 < 0x19) {

    sound_play_obj(0x6ab,obj);

    return;

  }

  if (iVar5 < 0x32) {

    sound_play_obj(0x6ac,obj);

    return;

  }

  if (iVar5 < 0x4b) {

    sound_play_obj(0x6ad,obj);

    return;

  }

  sound_play_obj(0x6ae,obj);

  return;

}

/* ===== FUN_004f5410 @ 0x004F5410 ===== */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

/* WARNING: Struct "OBJECT": ignoring multiple overlapping fields */

/* PS2 candidate: smartie_attach_to_base (conf 0.598) */



void FUN_004f5410(OBJECT *obj)



{

  int iVar1;

  int iVar2;

  undefined4 uVar3;

  undefined4 in_stack_00000008;

  dword in_stack_0000000c;

  dword dVar4;

  

  iVar2 = *(int *)&obj->field_0x100;

  smartie_unlock_from_player(obj);

  uVar3 = 0;

  obj->field_274 = in_stack_0000000c;

  obj->field_E0 = obj->field_E0 | 8;

  *(undefined4 *)&obj->field_0xec = 0;

  obj->gap_128 = 0;

  *(undefined4 *)&obj->field_0x12c = 0;

  obj->field_278 = 0;

  iVar1 = FUN_004188e0(in_stack_0000000c);

  if (iVar1 == 0) {

    obj->gap_E4 = 0x24;

  }

  else {

    obj->gap_E4 = 0x1e;

  }

  *(undefined4 *)(iVar2 + 0x1c) = 0xffffffff;

  *(undefined4 *)(iVar2 + 0x20) = 0xffffffff;

  *(undefined4 *)(iVar2 + 0x24) = 0xffffffff;

  iVar1 = FUN_0052e480(in_stack_0000000c);

  if (iVar1 == 0) goto LAB_004f55b7;

  iVar1 = FUN_0052aa70();

  if (iVar1 != 0) {

    iVar1 = FUN_00521330(DAT_00632f18);

    if (iVar1 == 0) goto LAB_004f55b7;

  }

  iVar1 = FUN_004a6200(in_stack_0000000c);

  if (iVar1 == 0) {

    iVar1 = FUN_004a6290(in_stack_0000000c);

    if (iVar1 == 0) goto LAB_004f55b7;

    iVar1 = FUN_00418540(in_stack_0000000c,0);

    if (iVar1 == 0) {

LAB_004f5569:

      iVar1 = FUN_00418540(in_stack_0000000c,1);

      if (iVar1 == 0) goto LAB_004f55b7;

      iVar1 = FUN_00418510(in_stack_0000000c,9);

      if (iVar1 != 0) goto LAB_004f55b7;

      uVar3 = 1;

    }

    else {

      iVar1 = FUN_00418510(in_stack_0000000c,8);

      if (iVar1 != 0) goto LAB_004f5569;

    }

    iVar1 = FUN_00418510(in_stack_0000000c,uVar3);

    if (iVar1 == 0) {

      FUN_00416a30(in_stack_0000000c,uVar3);

    }

    dVar4 = obj->field_274;

  }

  else {

    iVar1 = FUN_00418540(in_stack_0000000c,0);

    if (iVar1 == 0) {

LAB_004f54ef:

      iVar1 = FUN_00418540(in_stack_0000000c,1);

      if (iVar1 == 0) goto LAB_004f55b7;

      iVar1 = FUN_00418510(in_stack_0000000c,0xe);

      if (iVar1 != 0) goto LAB_004f55b7;

      uVar3 = 1;

    }

    else {

      iVar1 = FUN_00418510(in_stack_0000000c,0xd);

      if (iVar1 != 0) goto LAB_004f54ef;

      FUN_00493ea0();

    }

    iVar1 = FUN_00418510(in_stack_0000000c,uVar3);

    if (iVar1 == 0) {

      FUN_00416a30(in_stack_0000000c,uVar3);

    }

    dVar4 = obj->field_274;

  }

  FUN_00416990(dVar4,uVar3,obj,1);

LAB_004f55b7:

  *(undefined4 *)(iVar2 + 0x1c) = 0xffffffff;

  *(undefined4 *)(iVar2 + 0x28) = 0xffffffff;

  *(undefined4 *)(iVar2 + 0x18) = *(undefined4 *)(DAT_00632ed8 + 0x624);

  obj->acc_grenade_do_stopped = obj->acc_grenade_do_stopped & 0xfffdffff | 0x800;

  iVar2 = FUN_004a6160(in_stack_00000008);

  if (iVar2 != 0) {

    sound_play_player(0x5e4);

    return;

  }

  iVar2 = FUN_004a6180(in_stack_00000008);

  if (iVar2 != 0) {

    sound_play_player(0x39b,in_stack_00000008);

  }

  return;

}

/* ===== FUN_004f5630 @ 0x004F5630 ===== */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

/* WARNING: Struct "OBJECT": ignoring multiple overlapping fields */



void FUN_004f5630(OBJECT *obj)



{

  int iVar1;

  int iVar2;

  

  iVar1 = *(int *)&obj->field_0x100;

  if ((obj->field_E0 & 8) != 0) {

    obj->field_E0 = obj->field_E0 & 0xfffffff7;

    if (*(int *)(iVar1 + 0x30) != 0) {

      *(undefined4 *)(*(int *)(iVar1 + 0x30) + 0x210) = 0;

      FUN_00497510(*(undefined4 *)(iVar1 + 0x30));

      *(undefined4 *)(iVar1 + 0x30) = 0;

      *(undefined4 *)(iVar1 + 0x14) = 0x41d80000;

      iVar2 = reaper_0052e4a0(obj);

      if (iVar2 != 0) {

        reaper_00530bd0(obj,0,0,0,0x14,0);

      }

    }

    FUN_004177f0(obj->field_274,obj);

    FUN_00401000(obj);

    iVar2 = FUN_004a6200(obj->field_274);

    if (iVar2 == 0) {

      iVar2 = FUN_004a6290(obj->field_274);

      if (iVar2 != 0) {

        FUN_004b6cd0(obj,*(undefined4 *)(iVar1 + 0x2c),*(undefined4 *)(iVar1 + 0x28));

      }

    }

    else {

      FUN_0040ac70(obj,*(undefined4 *)(iVar1 + 0x2c),*(undefined4 *)(iVar1 + 0x28));

    }

    *(undefined4 *)(iVar1 + 0x2c) = 0xffffffff;

    *(undefined4 *)(iVar1 + 0x28) = 0xffffffff;

    obj->field_274 = 0;

  }

  return;

}

/* ===== fx_reaper_bubble @ 0x004F5710 ===== */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

/* WARNING: Struct "OBJECT": ignoring multiple overlapping fields */

/* PS2 candidate: smartie_reaper_grab (conf 0.374) */



void fx_reaper_bubble(OBJECT *obj)



{

  int iVar1;

  int iVar2;

  undefined4 uVar3;

  dword in_stack_00000008;

  dword local_40;

  undefined4 local_3c;

  float local_38;

  undefined4 local_24;

  undefined4 local_20;

  OBJECT *local_1c;

  

  iVar1 = *(int *)&obj->field_0x100;

  if (obj->gap_E4 != 0x32) {

    if ((obj->field_E0 & 8) != 0) {

      obj->field_E0 = obj->field_E0 & 0xfffffff7;

      if (*(int *)(iVar1 + 0x30) != 0) {

        *(undefined4 *)(*(int *)(iVar1 + 0x30) + 0x210) = 0;

        FUN_00497510(*(undefined4 *)(iVar1 + 0x30));

        *(undefined4 *)(iVar1 + 0x30) = 0;

        *(undefined4 *)(iVar1 + 0x14) = 0x41d80000;

        iVar2 = reaper_0052e4a0(obj);

        if (iVar2 != 0) {

          reaper_00530bd0(obj,0,0,0,0x14,0);

        }

      }

      FUN_004177f0(obj->field_274,obj);

      FUN_00401000(obj);

      iVar2 = FUN_004a6200(obj->field_274);

      if (iVar2 == 0) {

        iVar2 = FUN_004a6290(obj->field_274);

        if (iVar2 != 0) {

          FUN_004b6cd0(obj,*(undefined4 *)(iVar1 + 0x2c),*(undefined4 *)(iVar1 + 0x28));

        }

      }

      else {

        FUN_0040ac70(obj,*(undefined4 *)(iVar1 + 0x2c),*(undefined4 *)(iVar1 + 0x28));

      }

      *(undefined4 *)(iVar1 + 0x2c) = 0xffffffff;

      *(undefined4 *)(iVar1 + 0x28) = 0xffffffff;

      obj->field_274 = 0;

    }

    obj->field_274 = in_stack_00000008;

    *(uint *)&obj->field_0xd8 = *(uint *)&obj->field_0xd8 | 0x10;

    obj->field_0x20b = 0;

    obj->field_0x20a = 0;

    obj->field_0x208 = 0;

    *(dword *)(iVar1 + 4) = obj->gap_A0;

    *(undefined4 *)(iVar1 + 8) = *(undefined4 *)&obj->field_0xa4;

    *(undefined4 *)(iVar1 + 0xc) = *(undefined4 *)&obj->field_0xa8;

    *(undefined4 *)(iVar1 + 0x1c) = 0xffffffff;

    *(undefined4 *)(iVar1 + 0x20) = 0xffffffff;

    *(undefined4 *)(iVar1 + 0x24) = 0xffffffff;

    *(undefined4 *)(iVar1 + 0x28) = 0xffffffff;

    *(undefined4 *)(iVar1 + 0x18) = 0;

    local_40 = obj->gap_A0;

    local_3c = *(undefined4 *)&obj->field_0xa4;

    local_38 = *(float *)&obj->field_0xa8 + 3.0;

    obj->gap_E4 = 0x32;

    FUN_004993c0(obj,&local_40);

    *(float *)&obj->field_0xc8 = *(float *)(obj->field_274 + 200) + 180.0;

    if (*(int *)(iVar1 + 0x3c) == 0) {

      local_1c = obj;

      local_20 = 6;

      local_24 = 8;

      uVar3 = fx_get_free_effect__Fv();

      *(undefined4 *)(iVar1 + 0x3c) = uVar3;

      *(float *)(iVar1 + 0x50) = *(float *)&obj->field_0xc4 * 0.5;

      *(float *)&obj->field_0xc4 = *(float *)&obj->field_0xc4 * 0.5;

    }

    *(undefined4 *)(iVar1 + 0x40) = *(undefined4 *)(DAT_00632ed8 + 0x7e0);

    *(undefined4 *)(iVar1 + 0x44) = *(undefined4 *)(DAT_00632ed8 + 0x7dc);

    if (*(int *)(iVar1 + 0xbc) == 0) {

      uVar3 = sound_get_free_sequence__Fv();

      *(undefined4 *)(iVar1 + 0xbc) = uVar3;

    }

    obj->field_E0 = obj->field_E0 & 0xffffffee;

  }

  return;

}

/* ===== FUN_004f5950 @ 0x004F5950 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

/* WARNING: Struct "OBJECT": ignoring multiple overlapping fields */

/* PS2 candidate: smartie_check_follow__FP6OBJECTf (conf 0.469) */



int FUN_004f5950(OBJECT *obj)



{

  char cVar1;

  int iVar2;

  undefined4 *puVar3;

  int iVar4;

  char *pcVar5;

  char *pcVar6;

  float10 fVar7;

  float in_stack_00000008;

  

  iVar2 = *(int *)&obj->field_0x100;

  if (*(int *)&obj->field_0xe8 == 7) {

    return 0;

  }

  if (*(int *)&obj->field_0x220 != 0) {

    *(undefined4 *)(iVar2 + 0x38) = 0;

  }

  *(undefined4 *)&obj->field_0x220 = 0;

  fVar7 = (float10)FUN_00518b70(obj,0);

  fVar7 = (float10)*(float *)(iVar2 + 0x38) - fVar7;

  *(float *)(iVar2 + 0x38) = (float)fVar7;

  if ((float10)0.0 < fVar7) {

    return 0;

  }

  *(undefined4 *)(iVar2 + 0x38) = 0x40000000;

  puVar3 = DAT_00632d6c;

  if ((obj->field_E0 & 8) != 0) {

    *(undefined4 *)(iVar2 + 0x38) = 0x3f4ccccd;

    puVar3 = DAT_00632d6c;

  }

  do {

    if (puVar3 == (undefined4 *)0x0) {

      return 0;

    }

    iVar2 = puVar3[3];

    if ((((-1 < (char)((uint)*(undefined4 *)(iVar2 + 0xd8) >> 8)) &&

         (((iVar4 = FUN_004a6160(iVar2), iVar4 != 0 || (iVar4 = FUN_004a6180(iVar2), iVar4 != 0)) &&

          (*(float *)(iVar2 + 0x278) < *(float *)(iVar2 + 0x1c0))))) &&

        (((((*(int *)&obj->field_0xe8 == 10 && (obj->gap_E4 == 0x34)) &&

           (*(dword *)(iVar2 + 0x18c) == obj->field_18C)) ||

          ((((*(uint *)(iVar2 + 0xdc) & 0x800000) == 0 &&

            (((iVar4 = FUN_004a6160(iVar2), iVar4 == 0 ||

              ((*(uint *)(iVar2 + 0xdc) & 0x400000) == 0)) ||

             (iVar4 = FUN_004586e0(iVar2), iVar4 != 10)))) &&

           (((iVar4 = FUN_004a6180(iVar2), iVar4 == 0 ||

             (*(int *)(*(int *)(iVar2 + 0x100) + 0xe2c) == 0)) &&

            ((iVar4 = FUN_004a6160(iVar2), iVar4 == 0 ||

             ((*(uint *)(iVar2 + 0xe0) & 0x2000000) == 0)))))))) &&

         (((((obj->field_E0 & 8) == 0 || (obj->field_274 == 0)) ||

           (*(int *)(obj->field_274 + 0x18c) != *(int *)(iVar2 + 0x18c))) &&

          ((*(int *)&obj->field_0xe8 != 10 ||

           (((((DAT_00632f08 < 1 || (DAT_00632f30 <= 0.0)) &&

              ((iVar4 = FUN_004a6160(iVar2), iVar4 == 0 ||

               (*(int *)(*(int *)(iVar2 + 0x100) + 0xd8) != 0)))) &&

             ((iVar4 = FUN_004a6180(iVar2), iVar4 == 0 ||

              (*(int *)(*(int *)(iVar2 + 0x100) + 0xcfc) != 0)))) &&

            ((obj->gap_E4 != 0x33 || (*(dword *)(iVar2 + 0x18c) != obj->field_18C)))))))))))) &&

       (fVar7 = (float10)FUN_0050a610(iVar2 + 0xa0,&obj->gap_A0),

       (float10)in_stack_00000008 * (float10)in_stack_00000008 < fVar7 ==

       ((float10)in_stack_00000008 * (float10)in_stack_00000008 == fVar7))) {

      if ((*(int *)&obj->field_0xe8 != 10) ||

         ((((iVar4 = FUN_004a6180(iVar2), iVar4 == 0 || (*(int *)(iVar2 + 0x210) == 0)) ||

           (iVar4 = FUN_004a6120(*(int *)(iVar2 + 0x210)), iVar4 == 0)) &&

          ((iVar4 = FUN_004a6160(iVar2), iVar4 == 0 || (iVar4 = FUN_0047f730(iVar2), iVar4 == 0)))))

         ) {

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

/* ===== FUN_004f5c10 @ 0x004F5C10 ===== */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

/* WARNING: Struct "OBJECT": ignoring multiple overlapping fields */

/* PS2 candidate: smartie_board_player__FP6OBJECTT0i (conf 0.656) */



void FUN_004f5c10(OBJECT *obj)



{

  char cVar1;

  int iVar2;

  char *pcVar3;

  undefined4 uVar4;

  uint uVar5;

  int iVar6;

  char *pcVar7;

  int in_stack_00000008;

  undefined4 in_stack_0000000c;

  OBJECT *pOVar8;

  undefined4 local_108;

  undefined4 local_104;

  char local_100 [256];

  

  if (((*(int *)&obj->field_0xe8 != 10) && ((obj->field_E0 & 8) != 0)) &&

     (iVar2 = FUN_0052aa70(), iVar2 != 0)) {

    pcVar3 = (char *)(*(int *)&obj->field_0x100 + 0x80);

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

    uVar4 = comm_player_name4(in_stack_00000008);

    uVar4 = TextGetPtrRandom(s_SmChKidnapped_005622dc,uVar4);

    uVar5 = 0xffffffff;

    pcVar3 = local_100;

    do {

      if (uVar5 == 0) break;

      uVar5 = uVar5 - 1;

      cVar1 = *pcVar3;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

    FUN_00542f27(local_100 + (~uVar5 - 1),uVar4);

    FUN_0052ea80(local_100,4,0,0);

  }

  if (*(int *)&obj->field_0xe8 == 5) {

    if (obj->acc_rpman_tuba_horn_check != 0) {

      FUN_00448920(obj->acc_rpman_tuba_horn_check);

    }

    iVar2 = *(int *)&obj->field_0x210;

    obj->acc_rpman_tuba_horn_check = 0;

    if ((iVar2 != 0) && (*(int *)(iVar2 + 4) == 0x3e9)) {

      iVar6 = 0;

      do {

        if ((*(uint *)(iVar2 + 0xf4) & 1 << ((byte)iVar6 & 0x1f)) != 0) {

          *(uint *)(iVar2 + 0xf4) = ~(1 << ((byte)iVar6 & 0x1f)) & *(uint *)(iVar2 + 0xf4);

          break;

        }

        iVar6 = iVar6 + 1;

      } while (iVar6 < 8);

      if (*(int *)(*(int *)&obj->field_0x210 + 0xf4) == 0) {

        iVar2 = 8;

        do {

          iVar6 = object_allocate_type(0xb,0x80000000);

          *(undefined4 *)(iVar6 + 0xe8) = 5;

          *(uint *)(iVar6 + 0xdc) = *(uint *)(iVar6 + 0xdc) | *(uint *)&obj->field_0xdc & 0xf;

          iVar2 = iVar2 + -1;

          *(uint *)(iVar6 + 0xd8) = *(uint *)(iVar6 + 0xd8) | *(uint *)&obj->field_0xd8 & 0x400;

        } while (iVar2 != 0);

      }

    }

  }

  iVar2 = *(int *)&obj->field_0x100;

  if ((obj->field_E0 & 8) != 0) {

    obj->field_E0 = obj->field_E0 & 0xfffffff7;

    if (*(int *)(iVar2 + 0x30) != 0) {

      *(undefined4 *)(*(int *)(iVar2 + 0x30) + 0x210) = 0;

      FUN_00497510(*(undefined4 *)(iVar2 + 0x30));

      *(undefined4 *)(iVar2 + 0x30) = 0;

      *(undefined4 *)(iVar2 + 0x14) = 0x41d80000;

      iVar6 = reaper_0052e4a0(obj);

      if (iVar6 != 0) {

        reaper_00530bd0(obj,0,0,0,0x14,0);

      }

    }

    FUN_004177f0(obj->field_274,obj);

    FUN_00401000(obj);

    iVar6 = FUN_004a6200(obj->field_274);

    if (iVar6 == 0) {

      iVar6 = FUN_004a6290(obj->field_274);

      if (iVar6 != 0) {

        FUN_004b6cd0(obj,*(undefined4 *)(iVar2 + 0x2c),*(undefined4 *)(iVar2 + 0x28));

      }

    }

    else {

      FUN_0040ac70(obj,*(undefined4 *)(iVar2 + 0x2c),*(undefined4 *)(iVar2 + 0x28));

    }

    *(undefined4 *)(iVar2 + 0x2c) = 0xffffffff;

    *(undefined4 *)(iVar2 + 0x28) = 0xffffffff;

    obj->field_274 = 0;

  }

  pOVar8 = obj;

  iVar2 = in_stack_00000008;

  smartie_lock_to_player(obj);

  iVar2 = FUN_004a6180(in_stack_00000008,pOVar8,iVar2,in_stack_0000000c);

  if (iVar2 == 0) {

    uVar4 = 0x29;

  }

  else {

    uVar4 = 0x59;

  }

  FUN_004034a0(obj,uVar4,0x21,0,0,0x3f000000);

  iVar2 = reaper_0052e4a0(obj);

  if (iVar2 != 0) {

    local_108 = *(undefined4 *)(in_stack_00000008 + 0x188);

    local_104 = 0;

    reaper_00530bd0(obj,0,2,0,3,&local_108);

  }

  return;

}

/* ===== FUN_004f6090 @ 0x004F6090 ===== */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

/* WARNING: Struct "OBJECT": ignoring multiple overlapping fields */

/* PS2 candidate: meccbaseitem_shot (conf 0.407) */



dword FUN_004f6090(OBJECT *obj)



{

  int iVar1;

  int iVar2;

  int iVar3;

  dword dVar4;

  float10 fVar5;

  

  iVar3 = *(int *)&obj->field_0x100;

  iVar1 = FUN_004a6200();

  if (iVar1 == 0) {

    iVar3 = FUN_004a6290(obj->field_274);

    dVar4 = 1;

    if (iVar3 != 0) {

      if ((obj->acc_vimp_set_run_anim & 2) == 0) {

        return obj->field_10;

      }

      fVar5 = (float10)FUN_00417f20();

      if ((float10)0.0 < fVar5) {

        if (((0x5c < (int)obj->field_10) && ((int)obj->field_10 < 0x60)) &&

           (iVar3 = FUN_004d5730(100), 0x20 < iVar3)) {

          iVar3 = FUN_004d5730(100);

          return (0x42 < iVar3) + 0x5e;

        }

        return 0x5d;

      }

      dVar4 = 0x6b;

    }

  }

  else {

    fVar5 = (float10)FUN_00417f20();

    if (fVar5 <= (float10)0.0) {

      dVar4 = obj->field_10;

      if (((obj->acc_vimp_set_run_anim & 2) != 0) && (dVar4 = 0x3f, obj->field_10 == 0x3f)) {

        iVar3 = FUN_004d5730(100);

        return ((0x31 < iVar3) - 1 & 0xe) + 0x31;

      }

    }

    else {

      dVar4 = obj->field_10;

      if (dVar4 == 0x3f) {

        iVar2 = FUN_0040b1d0();

        iVar1 = *(int *)&obj->field_0x100;

        if ((*(int *)(iVar1 + 0x30) == 0) && (iVar2 != 0)) {

          *(int *)(iVar1 + 0x30) = iVar2;

          FUN_004a76e0(obj,0,iVar2 + 0xa0);

          FUN_00499280(*(undefined4 *)(iVar1 + 0x30));

          *(dword *)(*(int *)(iVar1 + 0x30) + 0x18c) = obj->field_18C;

          *(OBJECT **)(*(int *)(iVar1 + 0x30) + 0x210) = obj;

          *(undefined4 *)(*(int *)(iVar1 + 0x30) + 0x214) = 0;

          *(undefined4 *)(*(int *)(iVar1 + 0x30) + 0x218) = 0;

          iVar2 = *(int *)(iVar1 + 0x30);

          *(undefined4 *)(iVar1 + 0x14) = *(undefined4 *)(iVar2 + 0xc4);

          *(uint *)(iVar2 + 0xd8) = *(uint *)(iVar2 + 0xd8) | 0x400000;

        }

        iVar3 = *(int *)(iVar3 + 0x30);

        if (iVar3 == 0) {

          return 0x3f;

        }

        dVar4 = (*(int *)(iVar3 + 4) == 0x2f6) + 0x3d;

        iVar3 = FUN_004d5730(100);

        if (iVar3 < 0x32) {

          sound_play_obj(0x6b7,obj);

          return dVar4;

        }

        sound_play_obj(0x6b8,obj);

        return dVar4;

      }

      if ((obj->acc_vimp_set_run_anim & 2) != 0) {

        if (dVar4 != 0x3a) {

          if ((int)dVar4 < 0x3d) {

            return 0x3f;

          }

          if (0x3e < (int)dVar4) {

            return 0x3f;

          }

          return 0x3a;

        }

        iVar1 = FUN_004d5730(100);

        if (0x4f < iVar1) {

          iVar3 = *(int *)&obj->field_0x100;

          if (*(int *)(iVar3 + 0x30) != 0) {

            *(undefined4 *)(*(int *)(iVar3 + 0x30) + 0x210) = 0;

            FUN_00497510(*(undefined4 *)(iVar3 + 0x30));

            *(undefined4 *)(iVar3 + 0x30) = 0;

            *(undefined4 *)(iVar3 + 0x14) = 0x41d80000;

            iVar3 = reaper_0052e4a0(obj);

            if (iVar3 != 0) {

              reaper_00530bd0(obj,0,0,0,0x14,0);

            }

          }

          return 0x3c;

        }

        iVar3 = *(int *)(iVar3 + 0x30);

        dVar4 = 1;

        if (iVar3 != 0) {

          return (*(int *)(iVar3 + 4) == 0x2f6) + 0x3d;

        }

      }

    }

  }

  return dVar4;

}

/* ===== FUN_004f75c0 @ 0x004F75C0 ===== */
void FUN_004f75c0(void)



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

  

  iVar8 = FUN_0052aa70();

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

          iVar9 = FUN_004189e0(*(int *)(iVar1 + 0x274));

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

      FUN_0052f8f0(0);

    }

  }

  return;

}

/* ===== FUN_004f7780 @ 0x004F7780 ===== */
/* WARNING: Struct "OBJECT": ignoring multiple overlapping fields */

/* PS2 candidate: smartie_shot (conf 0.441) */



void FUN_004f7780(int param_1,float param_2,OBJECT *param_3,undefined4 param_4,undefined4 param_5)



{

  uint *puVar1;

  dword dVar2;

  float fVar3;

  int iVar4;

  int iVar5;

  uint uVar6;

  undefined4 uVar7;

  

  iVar5 = *(int *)&param_3->field_0x100;

  if (param_1 == 3) {

    FUN_00497510(param_3);

    return;

  }

  if ((((param_3->gap_E4 != 0x41) || (*(int *)(iVar5 + 0xa0) == 0)) ||

      (iVar4 = ANM_AnimGetImage(*(int *)(iVar5 + 0xa0)), iVar4 != 0)) &&

     (((param_3->gap_E4 != 0x29 && (iVar4 = *(int *)&param_3->field_0xe8, iVar4 != 8)) &&

      ((iVar4 != 9 && (iVar4 != 1)))))) {

    if (iVar4 == 10) {

      if (((param_1 == 7) && (iVar5 = FUN_0052e480(param_3), iVar5 != 0)) &&

         (param_3->field_274 != 0)) {

        FUN_0041b390(param_3);

        return;

      }

    }

    else {

      if (param_3->gap_E4 == 0x32) {

        FUN_004f4fc0(param_3);

        return;

      }

      if (((*(int *)&param_3->field_0x210 == 0) &&

          (((param_3->field_274 == 0 || (iVar4 = FUN_004a6180(param_3->field_274), iVar4 == 0)) &&

           ((param_3->field_E0 & 8) == 0)))) &&

         ((((*(int *)&param_3->field_0xe8 == 5 ||

            (uVar6 = *(uint *)&param_3->field_0xdc & 0xf, uVar6 == 0)) || (uVar6 == 2)) &&

          (*(int *)(iVar5 + 0x3c) == 0)))) {

        fVar3 = param_2 + (float)param_3->field_278;

        param_3->field_278 = (dword)fVar3;

        if (*(float *)&param_3->field_0x1c0 <= fVar3) {

          if (*(int *)(iVar5 + 0xa0) != 0) {

            puVar1 = (uint *)(*(int *)(iVar5 + 0xa0) + 0xe0);

            *puVar1 = *puVar1 & 0xfffffffb;

            *(undefined4 *)(iVar5 + 0xa0) = 0;

          }

          dVar2 = param_3->field_274;

          if (dVar2 != 0) {

            iVar5 = *(int *)&param_3->field_0x100;

            switch(param_3->gap_E4) {

            case 0x1e:

            case 0x1f:

            case 0x21:

              FUN_004177f0(dVar2,param_3);

              FUN_00401000(param_3);

              break;

            default:

              goto switchD_004f7908_caseD_20;

            case 0x24:

            case 0x25:

              iVar4 = FUN_004a6200(dVar2);

              if (iVar4 == 0) {

                iVar4 = FUN_004a6290(param_3->field_274);

                if (iVar4 != 0) {

                  FUN_004b6cd0(param_3,*(undefined4 *)(iVar5 + 0x2c),*(undefined4 *)(iVar5 + 0x28));

                }

              }

              else {

                FUN_0040ac70(param_3,*(undefined4 *)(iVar5 + 0x2c),*(undefined4 *)(iVar5 + 0x28));

              }

              FUN_00401000(param_3);

            }

            *(undefined4 *)(iVar5 + 0x2c) = 0xffffffff;

            *(undefined4 *)(iVar5 + 0x28) = 0xffffffff;

          }

switchD_004f7908_caseD_20:

          if (param_1 == 7) {

            param_3->field_E0 = param_3->field_E0 | 0x40;

            iVar5 = reaper_0052e4a0(param_3);

            if (iVar5 != 0) {

              reaper_00530bd0(param_3,0,0,0,0x15,0);

            }

            FUN_00497510(param_3);

          }

          param_3->gap_E4 = 0x29;

          param_3->field_0x20b = 0;

          param_3->field_0x20a = 0;

          param_3->field_0x208 = 0;

          if ((*(uint *)&param_3->field_0xd8 & 0x800) == 0) {

            uVar7 = 0x4f;

          }

          else {

            uVar7 = 0x6a;

          }

          FUN_004034a0(param_3,uVar7,0,0,0,0x3ecccccd);

          iVar5 = FUN_004d5730(100);

          if (iVar5 < 0x32) {

            sound_play_3dpos(0x6af,&param_3->gap_A0);

            return;

          }

          sound_play_3dpos(0x6b0,&param_3->gap_A0);

          return;

        }

        FUN_00456a10(param_1,param_2,param_2,param_3,param_4,param_5);

        FUN_0040bb40(param_3,param_5);

        iVar5 = FUN_004d5730(0x3c);

        if (iVar5 < 10) {

          sound_play_obj(0x6f2,param_3);

          return;

        }

        if (iVar5 < 0x14) {

          sound_play_obj(0x6f4,param_3);

          return;

        }

        if (iVar5 < 0x1e) {

          sound_play_obj(0x6f6,param_3);

          return;

        }

        if (iVar5 < 0x28) {

          sound_play_obj(0x6f3,param_3);

          return;

        }

        if (iVar5 < 0x32) {

          sound_play_obj(0x6f5,param_3);

          return;

        }

        sound_play_obj(0x6f7,param_3);

      }

    }

  }

  return;

}

/* ===== FUN_004f7af0 @ 0x004F7AF0 ===== */
/* PS2 candidate: smartie_clear_held_object (conf 0.607) */



void FUN_004f7af0(int param_1)



{

  int iVar1;

  

  iVar1 = *(int *)(param_1 + 0x100);

  if (*(int *)(iVar1 + 0x30) != 0) {

    *(undefined4 *)(*(int *)(iVar1 + 0x30) + 0x210) = 0;

    FUN_00497510(*(undefined4 *)(iVar1 + 0x30));

    *(undefined4 *)(iVar1 + 0x30) = 0;

    *(undefined4 *)(iVar1 + 0x14) = 0x41d80000;

    iVar1 = reaper_0052e4a0(param_1);

    if (iVar1 != 0) {

      reaper_00530bd0(param_1,0,0,0,0x14,0);

    }

  }

  return;

}

/* ===== FUN_004f7b50 @ 0x004F7B50 ===== */
/* PS2 candidate: smartie_make_held_object__FP6OBJECTi (conf 0.637) */



void FUN_004f7b50(int param_1,undefined4 param_2)



{

  uint *puVar1;

  int iVar2;

  int iVar3;

  

  iVar3 = *(int *)(param_1 + 0x100);

  if (*(int *)(iVar3 + 0x30) == 0) {

    iVar2 = object_allocate_type(param_2,0);

    *(int *)(iVar3 + 0x30) = iVar2;

    FUN_004a76e0(param_1,0,iVar2 + 0xa0);

    FUN_00499280(*(undefined4 *)(iVar3 + 0x30));

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
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

/* WARNING: Struct "OBJECT": ignoring multiple overlapping fields */



void smartie_get_name__FP6OBJECT(OBJECT *p0)



{

  char cVar1;

  dword dVar2;

  uint uVar3;

  char *pcVar4;

  uint uVar5;

  char *pcVar6;

  int iVar7;

  uint uVar8;

  undefined1 *puVar9;

  int iVar10;

  int iVar11;

  char *pcVar12;

  char *pcVar13;

  uint auStack_48 [6];

  undefined1 local_30 [48];

  

  dVar2 = p0->field_4;

  if (dVar2 == 0xd8) {

    pcVar4 = &DAT_00562310;

  }

  else if (dVar2 == 0x247) {

    pcVar4 = s_Timmy_00562308;

  }

  else if (dVar2 == 0x248) {

    pcVar4 = s_Borjoyzee_0055b3c0;

  }

  else {

    if (dVar2 != 0x2e6) {

      uVar3 = p0->field_188;

      pcVar4 = (char *)(*(int *)&p0->field_0x100 + 0x80);

      puVar9 = local_30;

      iVar10 = 0;

      *pcVar4 = '\0';

      iVar11 = 0;

      do {

        uVar5 = (int)(uVar3 >> 8) >> ((byte)iVar11 & 0x1f) & 3;

        auStack_48[iVar10] = uVar5;

        FUN_00542f27(puVar9,s_SmNameSyl_c_d_005622f8,iVar10 + 0x41,uVar5 + 1);

        pcVar6 = (char *)TextGetPtrQ(puVar9);

        uVar5 = 0xffffffff;

        auStack_48[iVar10 + 3] = (uint)pcVar6;

        do {

          pcVar13 = pcVar6;

          if (uVar5 == 0) break;

          uVar5 = uVar5 - 1;

          pcVar13 = pcVar6 + 1;

          cVar1 = *pcVar6;

          pcVar6 = pcVar13;

        } while (cVar1 != '\0');

        uVar5 = ~uVar5;

        iVar7 = -1;

        pcVar6 = pcVar4;

        do {

          pcVar12 = pcVar6;

          if (iVar7 == 0) break;

          iVar7 = iVar7 + -1;

          pcVar12 = pcVar6 + 1;

          cVar1 = *pcVar6;

          pcVar6 = pcVar12;

        } while (cVar1 != '\0');

        pcVar6 = pcVar13 + -uVar5;

        pcVar13 = pcVar12 + -1;

        for (uVar8 = uVar5 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {

          *(undefined4 *)pcVar13 = *(undefined4 *)pcVar6;

          pcVar6 = pcVar6 + 4;

          pcVar13 = pcVar13 + 4;

        }

        for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {

          *pcVar13 = *pcVar6;

          pcVar6 = pcVar6 + 1;

          pcVar13 = pcVar13 + 1;

        }

        iVar11 = iVar11 + 2;

        puVar9 = puVar9 + 0x10;

        iVar10 = iVar10 + 1;

        if (5 < iVar11) {

          return;

        }

      } while( true );

    }

    pcVar4 = &DAT_0055b3bc;

  }

  iVar10 = (*(int *)&p0->field_0x100 + 0x80) - (int)pcVar4;

  do {

    cVar1 = *pcVar4;

    pcVar4[iVar10] = cVar1;

    pcVar4 = pcVar4 + 1;

  } while (cVar1 != '\0');

  return;

}

/* ===== FUN_004f8350 @ 0x004F8350 ===== */
/* PS2 candidate: sceMpegIsEnd (conf 0.604) */



float10 FUN_004f8350(int param_1)



{

  return (float10)**(float **)(param_1 + 0x100);

}

/* ===== FUN_004f8360 @ 0x004F8360 ===== */
/* PS2 candidate: smokegen_process (conf 0.444) */



void FUN_004f8360(float param_1)



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

    fVar9 = (float10)FUN_004d5780(puVar4[2],puVar4[3]);

    *(float *)((int)param_1 + 0xec) = (float)fVar9;

    if ((*(byte *)((int)param_1 + 0xe0) & 2) == 0) {

      fVar9 = (float10)FUN_004d5780(puVar4[4],puVar4[5]);

      piVar3[2] = (int)(float)fVar9;

      piVar3[1] = 0;

    }

    else {

      fVar9 = (float10)FUN_004d5780(puVar4[4],puVar4[5]);

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

      fVar9 = (float10)FUN_004d5780(puVar4[2],puVar4[3]);

      *(float *)((int)param_1 + 0xec) = (float)fVar9;

      fVar9 = (float10)FUN_004d5780(puVar4[4],puVar4[5]);

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

        FUN_00497510(param_1);

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

      FUN_004f8800(param_1);

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

        FUN_004f8800(param_1);

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

    fVar9 = (float10)FUN_004d5780(*puVar4,puVar4[1]);

    *(float *)((int)param_1 + 0xec) = (float)fVar9;

    *(undefined4 *)((int)param_1 + 0xe4) = 2;

    return;

  }

LAB_004f85c8:

  fVar9 = (float10)FUN_004d5780(-(float)puVar4[0xe],puVar4[0xe]);

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

  FUN_0050ae40(param_1,piVar3 + 5,piVar3 + 6);

  fVar9 = (float10)FUN_004d5780(-(float)puVar4[0x11],puVar4[0x11]);

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

/* ===== FUN_004f86a0 @ 0x004F86A0 ===== */
void FUN_004f86a0(undefined4 *param_1)



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

    FUN_00499490(iVar3,0,0,(float)(fVar6 * (float10)pfVar1[3]));

  }

  else {

    fVar6 = (float10)FUN_00518b70(iVar3,0);

    fVar6 = (float10)FUN_00518b70(iVar3,0,(float)(fVar6 * (float10)pfVar1[3]));

    fVar6 = (float10)FUN_00518b70(iVar3,0,(float)-(fVar6 * (float10)(float)puVar4[6] *

                                                  (float10)(float)puVar4[4]));

    FUN_00499490(iVar3,(float)(fVar6 * (float10)(float)puVar4[5] * (float10)(float)puVar4[4]));

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

    FUN_00497510(iVar3);

    *(undefined4 *)(iVar3 + 0xec) = 0;

  }

  return;

}

/* ===== FUN_004f8800 @ 0x004F8800 ===== */
/* PS2 candidate: make_particle__FP6OBJECT (conf 0.42) */



int FUN_004f8800(float param_1)



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

  FUN_004993c0(iVar4,(int)param_1 + 0xa0);

  fVar5 = (float10)FUN_004d5780(*(undefined4 *)(iVar1 + 0x28),*(undefined4 *)(iVar1 + 0x2c));

  *(float *)(iVar4 + 0xec) = (float)fVar5;

  pfVar2[2] = (float)((float10)1.0 / fVar5);

  fVar5 = (float10)FUN_004d5780(*(undefined4 *)(iVar1 + 0x20),*(undefined4 *)(iVar1 + 0x24));

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

    fVar5 = (float10)FUN_004d5760((float)fVar5);

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

  

  FUN_0040d6b0(local_c);

  fVar1 = (float10)FUN_0050a580(local_c,param_1);

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

/* ===== FUN_004f9380 @ 0x004F9380 ===== */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

/* WARNING: Struct "OBJECT": ignoring multiple overlapping fields */

/* PS2 candidate: ripper_medium_move__FP6OBJECT (conf 0.464) */



void FUN_004f9380(OBJECT *obj)



{

  undefined1 *puVar1;

  dword *pdVar2;

  float *pfVar3;

  undefined4 *puVar4;

  float fVar5;

  int iVar6;

  int iVar7;

  uint uVar8;

  float10 fVar9;

  float10 fVar10;

  undefined4 uVar11;

  undefined1 local_1c [16];

  float local_c;

  

  pfVar3 = *(float **)&obj->field_0x100;

  if (obj->gap_E4 == 0) {

    obj->field_18C = 100;

    fVar9 = (float10)FUN_004d5780(*(undefined4 *)(DAT_00632ed8 + 0xb9c),

                                  *(undefined4 *)(DAT_00632ed8 + 0xba0));

    pfVar3[3] = (float)fVar9;

    if (obj->field_4 == 0x23f) {

      if (*(int *)&obj->field_0xe8 == 1) {

        obj->acc_grenade_do_stopped = obj->acc_grenade_do_stopped & 0xfffdffff;

        object_change_ospec(obj,0x1b);

        return;

      }

      if (*(int *)&obj->field_0xe8 == 2) {

        obj->gap_E4 = 100;

      }

    }

    else {

      obj->gap_E4 = 0x1e;

    }

  }

  uVar8 = obj->acc_vimp_set_run_anim & 2;

  obj->field_0x208 = 0;

  obj->field_0x20b = 0;

  obj->field_0x20a = 0;

  *(uint *)&obj->field_0xd8 = *(uint *)&obj->field_0xd8 & 0xfcffffff;

  fVar9 = (float10)FUN_00518b70(obj,0);

  pfVar3[4] = (float)((float10)pfVar3[4] - fVar9);

  if (pfVar3[7] == 0.0) {

    fVar9 = (float10)FUN_00518b70(0,0);

    fVar5 = pfVar3[8];

    pfVar3[8] = (float)((float10)fVar5 - fVar9);

    if ((float10)fVar5 - fVar9 < (float10)0.0) {

      FUN_004f9b50(obj,0);

      pfVar3[8] = 2.2;

    }

  }

  if ((*(float *)&obj->field_0x1c0 <= (float)obj->field_278) && (obj->gap_E4 != 0x14)) {

    pfVar3[10] = 0.0;

    obj->field_278 = *(dword *)&obj->field_0x1c0;

    obj->gap_E4 = 0x14;

  }

  switch(obj->gap_E4) {

  case 10:

    if ((0 < (int)pfVar3[1]) && (1.0666667 <= (float)obj->field_14)) {

      if ((float)obj->field_18 < 1.0666667) {

        fVar5 = (float)FUN_004f9d20(obj,0x43160000);

        pfVar3[10] = fVar5;

        pfVar3[9] = 0.0;

        if (fVar5 != 0.0) {

          fVar9 = (float10)FUN_0050a400(&obj->gap_A0,(int)fVar5 + 0xa0,

                                        *(undefined4 *)&obj->field_0xc8);

          fVar9 = (float10)FUN_0050a7c0((float)fVar9);

          pfVar3[9] = (float)fVar9;

        }

        if (35.0 < pfVar3[9]) {

          pfVar3[9] = 35.0;

        }

        if (pfVar3[9] < -35.0) {

          pfVar3[9] = -35.0;

        }

      }

      fVar9 = (float10)FUN_00518b70(obj,0);

      fVar5 = *pfVar3;

      *pfVar3 = (float)((float10)fVar5 - fVar9);

      if ((float10)fVar5 - fVar9 < (float10)0.0) {

        iVar6 = *(int *)&obj->field_0x100;

        iVar7 = object_allocate_type(0x25f,0x80000000);

        FUN_004a76e0(obj,1,iVar7 + 0xa0);

        FUN_00499280(iVar7);

        *(float *)(iVar7 + 200) = *(float *)&obj->field_0xc8 + *(float *)(iVar6 + 0x24);

        *(dword *)(iVar7 + 0x18c) = obj->field_18C;

        *(undefined4 *)(iVar7 + 0x11c) = *(undefined4 *)(iVar7 + 0x194);

        *(undefined4 *)(iVar7 + 0x10c) = *(undefined4 *)(iVar7 + 0x194);

        *(undefined4 *)(iVar7 + 0xec) = *(undefined4 *)(DAT_00632ed8 + 0xcb8);

        *(undefined4 *)(iVar7 + 0xc4) = *(undefined4 *)(DAT_00632ed8 + 0xcbc);

        *pfVar3 = 0.2;

        pfVar3[1] = (float)((int)pfVar3[1] + -1);

      }

    }

    if (uVar8 != 0) {

      obj->gap_E4 = 0xb;

      return;

    }

    break;

  case 0xb:

    if (1.3333334 <= (float)obj->field_14) {

      sound_play_obj(0x511,obj);

      iVar6 = FUN_0052e480(obj);

      if (iVar6 != 0) {

        FUN_00431a00(&obj->gap_A0,*(undefined4 *)(DAT_00632ed8 + 0x40c),

                     *(undefined4 *)(DAT_00632ed8 + 0x410),*(undefined4 *)(DAT_00632ed8 + 0x414),

                     *(undefined4 *)(DAT_00632ed8 + 0x4ac));

      }

      obj->gap_E4 = 0xc;

      return;

    }

    break;

  case 0xc:

    if (uVar8 != 0) {

      obj->gap_E4 = 0x65;

      *(undefined4 *)&obj->field_0xec = 0x40a00000;

      return;

    }

    break;

  case 0x14:

    if ((uVar8 != 0) && ((*(uint *)&obj->field_0xdc & 0x20000) == 0)) {

      fVar5 = pfVar3[5];

      if ((fVar5 != 0.0) && (*(int *)((int)fVar5 + 0x1e0) == 0x61)) {

        FUN_004782d0(fVar5);

      }

      *(uint *)&obj->field_0xdc = *(uint *)&obj->field_0xdc | 0x20000;

      *(undefined4 *)&obj->field_0xec = DAT_00632e6c;

      return;

    }

    break;

  case 100:

    pfVar3[10] = 0.0;

    if (pfVar3[7] != 0.0) {

      fVar5 = (float)FUN_004f9d20(obj,0x43160000);

      pfVar3[10] = fVar5;

      if (fVar5 != 0.0) {

        obj->gap_E4 = 0x65;

        if (pfVar3[5] != 0.0) {

          *(undefined4 *)((int)pfVar3[5] + 0xe4) = 3;

        }

      }

    }

    iVar6 = *(int *)&obj->field_0x100;

    pdVar2 = &obj->gap_A0;

    FUN_004a76e0(*(undefined4 *)(iVar6 + 0x14),*(undefined4 *)(iVar6 + 0x18),pdVar2);

    FUN_00414690(pdVar2,local_1c);

    if (*(int *)(*(int *)(iVar6 + 0x14) + 0xf8) == 0) {

      *(float *)&obj->field_0xa8 = local_c + (float)obj->acc_popup_pre_logic;

    }

    else if (*(float *)&obj->field_0xa8 < local_c) {

      *(float *)&obj->field_0xa8 = local_c;

    }

    if (((float)obj->gap_B8 != (float)*pdVar2) ||

       (*(float *)&obj->field_0xbc != *(float *)&obj->field_0xa4)) {

      fVar9 = (float10)FUN_0050a400(&obj->gap_B8,pdVar2);

      fVar9 = (float10)FUN_00518b70(obj,0,0x461c4000,(float)fVar9,&obj->field_0xc8);

      FUN_004515b0((float)(fVar9 * (float10)30.0));

    }

    *(uint *)&obj->field_0xd8 = *(uint *)&obj->field_0xd8 | 0x40;

    FUN_004967b0(obj);

    fVar9 = (float10)FUN_00518b70(obj,0);

    FUN_00403e60(obj,(float)fVar9);

    FUN_004a7440(obj);

    *(uint *)&obj->field_0xd8 = *(uint *)&obj->field_0xd8 | 0x20;

    obj->acc_rpman_tuba_horn_check = *(dword *)&obj->field_0xc8;

    break;

  case 0x65:

    fVar5 = (float)FUN_004f9d20(obj,0x43160000);

    pfVar3[10] = fVar5;

    if (fVar5 == 0.0) {

      obj->acc_minishop_use_icon = obj->acc_rpman_tuba_horn_check;

    }

    else {

      fVar9 = (float10)FUN_0050a400(&obj->gap_A0,(int)fVar5 + 0xa0);

      obj->acc_minishop_use_icon = (dword)(float)fVar9;

    }

    puVar1 = &obj->field_0xc8;

    obj->gap_FC = *(dword *)&obj->field_0xc8;

    fVar9 = (float10)FUN_00518b70(obj,0,0x461c4000,obj->acc_minishop_use_icon,puVar1);

    FUN_004515b0((float)(fVar9 * (float10)(float)obj->field_1A8));

    fVar9 = (float10)FUN_0050a7c0(obj->acc_minishop_use_icon,*(undefined4 *)puVar1);

    fVar10 = (float10)FUN_00518b70(obj,0);

    fVar10 = (float10)*(float *)&obj->field_0xec - fVar10;

    *(float *)&obj->field_0xec = (float)fVar10;

    if (((fVar10 < (float10)0.0) && ((float)ABS(fVar9) < 5.0 != ((float)ABS(fVar9) == 5.0))) &&

       (*(undefined4 *)&obj->field_0xec = 0x40000000, pfVar3[10] != 0.0)) {

      obj->gap_E4 = 10;

      pfVar3[1] = 1.68156e-44;

      *pfVar3 = 0.0;

    }

    if ((float)obj->gap_FC == *(float *)puVar1) {

      fVar9 = (float10)FUN_00518b70(obj,0);

      fVar9 = (float10)*(float *)&obj->field_0xf0 - fVar9;

      *(float *)&obj->field_0xf0 = (float)fVar9;

      if ((pfVar3[10] == 0.0) && (fVar9 < (float10)0.0 != (fVar9 == (float10)0.0))) {

        iVar6 = FUN_004d5730(100);

        if (iVar6 < 0x32) {

          uVar11 = 0x28;

        }

        else {

          uVar11 = 0x29;

        }

        anim_select_check2(obj,uVar11);

        obj->gap_E4 = 0x66;

      }

    }

    fVar9 = (float10)FUN_00518b70(obj,0);

    fVar5 = pfVar3[2];

    pfVar3[2] = (float)((float10)fVar5 - fVar9);

    if ((float10)fVar5 - fVar9 < (float10)0.0) {

      fVar9 = (float10)FUN_004d5780(0x3f666666,0x3fc00000);

      pfVar3[2] = (float)fVar9;

      pfVar3[7] = 1.4013e-45;

      for (puVar4 = DAT_00632d6c; puVar4 != (undefined4 *)0x0; puVar4 = (undefined4 *)*puVar4) {

        if ((*(int *)(puVar4[3] + 0x1e0) == 0x33) &&

           (*(float *)(*(int *)(puVar4[3] + 0x100) + 0x134) == pfVar3[5])) {

          pfVar3[7] = 0.0;

          break;

        }

      }

    }

    if (((pfVar3[7] != 0.0) && (pfVar3[10] == 0.0)) &&

       ((float)obj->acc_minishop_use_icon == *(float *)puVar1)) {

      pfVar3[10] = 0.0;

      obj->gap_E4 = 100;

      if (pfVar3[5] != 0.0) {

        *(undefined4 *)((int)pfVar3[5] + 0xe4) = 2;

        return;

      }

    }

    break;

  case 0x66:

    if (uVar8 != 0) {

      fVar9 = (float10)FUN_004d5780(0x40400000,0x41700000);

      *(float *)&obj->field_0xf0 = (float)fVar9;

      obj->gap_E4 = 0x65;

      return;

    }

  }

  return;

}

/* ===== FUN_004f9b50 @ 0x004F9B50 ===== */
/* WARNING: Struct "OBJECT": ignoring multiple overlapping fields */



void FUN_004f9b50(OBJECT *param_1,int param_2)



{

  int iVar1;

  OBJECT *obj;

  bool bVar2;

  OBJECT *pOVar3;

  int *piVar4;

  

  iVar1 = *(int *)&param_1->field_0x100;

  if ((*(int *)(iVar1 + 0x14) != 0) && (param_1->gap_E4 == 100)) {

    bVar2 = false;

    pOVar3 = (OBJECT *)0x0;

    if ((*(int *)(iVar1 + 0x1c) == 0) && (piVar4 = DAT_00632d6c, DAT_00632d6c != (int *)0x0)) {

      do {

        obj = (OBJECT *)piVar4[3];

        if ((*(int *)&obj->field_0x1e0 != 0x33) || (bVar2)) {

          if ((*(int *)&obj->field_0x1e0 == 0x27) &&

             ((obj != param_1 &&

              (*(int *)(*(int *)&obj->field_0x100 + 0x14) == *(int *)(iVar1 + 0x14))))) {

            pOVar3 = obj;

          }

        }

        else if ((*(int *)(*(int *)&obj->field_0x100 + 0x134) == *(int *)(iVar1 + 0x14)) &&

                (*(int *)(*(int *)&obj->field_0x100 + 0xb0) == 0)) {

          if (param_2 != 0) {

            FUN_004e7ae0(obj);

          }

          bVar2 = true;

        }

        piVar4 = (int *)*piVar4;

      } while (piVar4 != (int *)0x0);

      if (pOVar3 != (OBJECT *)0x0) {

        return;

      }

      if (bVar2) {

        return;

      }

    }

    *(undefined4 *)(iVar1 + 0x1c) = 1;

  }

  return;

}

/* ===== FUN_004f9c10 @ 0x004F9C10 ===== */
void FUN_004f9c10(undefined4 param_1,float param_2,int param_3,undefined4 param_4,undefined4 param_5

                 )



{

  int iVar1;

  int iVar2;

  undefined4 uVar3;

  

  iVar1 = *(int *)(param_3 + 0x100);

  FUN_004f9b50(param_3,1);

  param_2 = param_2 + *(float *)(param_3 + 0x278);

  *(float *)(param_3 + 0x278) = param_2;

  if (*(float *)(param_3 + 0x1c0) <= param_2) {

    if (*(int *)(param_3 + 0xe4) != 0x14) {

      iVar2 = FUN_004d5730(100);

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

    FUN_0040b4b0(param_3);

    *(uint *)(param_3 + 0x1c8) = *(uint *)(param_3 + 0x1c8) & 0xfffdffff;

    return;

  }

  iVar2 = FUN_004d5730(100);

  if (iVar2 < 0x32) {

    uVar3 = 0x51b;

  }

  else {

    uVar3 = 0x51c;

  }

  sound_play_obj(uVar3,param_3);

  FUN_0040bb40(param_3,param_5);

  *(undefined4 *)(iVar1 + 0x10) = 0x41200000;

  if (*(int *)(iVar1 + 0x1c) != 0) {

    *(undefined4 *)(param_3 + 0xe4) = 0x65;

    if (*(int *)(iVar1 + 0x14) != 0) {

      *(undefined4 *)(*(int *)(iVar1 + 0x14) + 0xe4) = 3;

    }

  }

  return;

}

/* ===== FUN_004f9d20 @ 0x004F9D20 ===== */
int FUN_004f9d20(int *param_1,float param_2)



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

    iVar7 = FUN_004a6160(iVar5);

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

          fVar9 = (float10)FUN_0050a400(puVar2,puVar1);

          fVar9 = (float10)FUN_0050a770((float)fVar9,*(undefined4 *)(iVar6 + 200));

          if (fVar9 <= (float10)*(float *)(DAT_00632ed8 + 0x5c)) {

            local_c = *puVar2;

            local_8 = *(undefined4 *)(iVar6 + 0xa4);

            local_4 = *(float *)(iVar6 + 0x1e8) * *(float *)(iVar6 + 0xc4) +

                      *(float *)(iVar6 + 0xa8);

            local_18 = *puVar1;

            local_14 = *(undefined4 *)(iVar5 + 0xa4);

            local_10 = *(float *)(iVar5 + 0x1e8) * *(float *)(iVar5 + 0xc4) +

                       *(float *)(iVar5 + 0xa8);

            iVar7 = FUN_004ef070(&local_c,&local_18,4,&DAT_00562368,0);

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

/* ===== AudioDataStreamStatus__Fv_3 @ 0x004FA1E0 ===== */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */



undefined4 * AudioDataStreamStatus__Fv_3(void)



{

  return &DAT_00632900;

}

/* ===== FUN_004fa1f0 @ 0x004FA1F0 ===== */
void FUN_004fa1f0(int param_1,int *param_2,int param_3)



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

/* ===== FUN_004fa380 @ 0x004FA380 ===== */
void FUN_004fa380(int param_1,int param_2,undefined4 param_3,float param_4,float param_5,

                 float param_6,float param_7)



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

    FUN_00516b60(iVar2 * 0x38 + iVar1,param_4,param_5,param_6,param_7,

                 *(undefined4 *)(param_2 + 0x54),uVar3);

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

    FUN_004fa380(param_1,*puVar4,param_4,param_5,param_6,(float)iVar2 * param_7,

                 (float)iVar3 * param_8);

    puVar4 = puVar4 + 1;

    param_2 = param_2 + -1;

  } while (param_2 != 0);

  return;

}

/* ===== FUN_004fa520 @ 0x004FA520 ===== */
/* PS2 candidate: hurt_pusher (conf 0.292) */



void FUN_004fa520(int param_1,float param_2)



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

        main_texture_00508720(iVar3);

        uVar12 = uVar11 | 4;

        iVar8 = FUN_00508fa0(iVar3);

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

    FUN_004fa520(param_1,*puVar2);

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

/* ===== FUN_004fdd00 @ 0x004FDD00 ===== */
float10 FUN_004fdd00(int param_1,undefined4 param_2,int param_3,int param_4,float param_5,

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

  FUN_00544a37(param_2,&local_c,10);

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

      FUN_004fa380(param_1,*puVar11,0,param_5,param_6,(float)iVar10 * param_7,(float)iVar2 * param_8

                  );

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

      FUN_004fa520(param_1,*puVar11);

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

/* ===== FUN_004fded0 @ 0x004FDED0 ===== */
int FUN_004fded0(int param_1,int param_2,float param_3,float param_4,undefined4 param_5)



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

    FUN_004fa380(param_1,*puVar6,0,0x3f800000,0x3f800000,(float)iVar5 * param_3,

                 (float)iVar1 * param_4);

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

    FUN_004fa520(param_1,*puVar6);

    puVar6 = puVar6 + 1;

    iVar5 = iVar5 + -1;

  } while (iVar5 != 0);

  *(uint *)(iVar2 + 0x18) = uVar3;

  return iVar2;

}

/* ===== FUN_004fdfd0 @ 0x004FDFD0 ===== */
int FUN_004fdfd0(int param_1,int param_2,undefined4 param_3,undefined4 param_4,float param_5,

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

    FUN_004fa380(param_1,*puVar5,0,param_3,param_4,(float)iVar4 * param_5,(float)iVar1 * param_6);

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

    FUN_004fa520(param_1,*puVar5);

    puVar5 = puVar5 + 1;

    iVar4 = iVar4 + -1;

  } while (iVar4 != 0);

  return iVar2;

}

/* ===== FUN_004fe0f0 @ 0x004FE0F0 ===== */
int FUN_004fe0f0(int param_1,int param_2,float param_3,float param_4,float param_5,float param_6,

                int param_7)



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

    FUN_004fa380(param_1,*puVar5,0,param_3,param_4,(float)iVar1 * param_5,param_6 * (float)iVar2);

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

    FUN_004fa520(param_1,*puVar5);

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

/* ===== FUN_004ff470 @ 0x004FF470 ===== */
void FUN_004ff470(void)



{

  if (DAT_00632bb8 != 0) {

    FUN_0049f1c0();

  }

  if (DAT_00632bb0 != 0) {

    FUN_00416550();

  }

  if (DAT_00632bb4 != 0) {

    FUN_004544f0();

  }

  if ((DAT_00632bac != 0) && (DAT_00632a88 != 0)) {

    FUN_0050c2a0(DAT_00632a88);

  }

  if (DAT_00632ba8 != 0) {

    FUN_00475700(1);

  }

  return;

}

/* ===== FUN_004ff6a0 @ 0x004FF6A0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_004ff6a0(float param_1)



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

      ((iVar3 = FUN_004a6160(param_1), iVar3 == 0 ||

       ((*(uint *)((int)fVar2 + 0xe0) & 0x2000000) == 0)))) &&

     ((iVar3 = FUN_004a6180(fVar2), iVar3 == 0 ||

      (*(int *)(*(int *)((int)fVar2 + 0x100) + 0xe2c) == 0)))) {

    FUN_0040d6f0(local_1c,local_20,local_24,local_c);

    local_30 = *(undefined4 *)((int)fVar2 + 4);

    local_18 = *(undefined4 *)((int)fVar2 + 0xa0);

    local_14 = *(undefined4 *)((int)fVar2 + 0xa4);

    local_10 = *(float *)((int)fVar2 + 0x1ec) * *(float *)((int)fVar2 + 0xc4) +

               *(float *)((int)fVar2 + 0xa8) + 2.0;

    iVar3 = 1;

    iVar4 = FUN_004ef070(local_c,&local_18,1,&local_30,0);

    if ((iVar4 != 0) && (iVar4 = FUN_005168f0(&local_18,&param_1,&local_34), iVar4 == 0)) {

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

          FUN_004fa380(&DAT_00632900,*puVar5,0,0x3f000000,0x3f000000,local_28,fVar2);

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

          FUN_004fa520(&DAT_00632900,*puVar5);

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

        FUN_004fa380(&DAT_00632900,*puVar5,0,0x3f800000,0x3f800000,local_2c,fVar2);

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

        FUN_004fa520(&DAT_00632900,*puVar5);

        puVar5 = puVar5 + 1;

        iVar3 = iVar3 + -1;

      } while (iVar3 != 0);

    }

  }

  return;

}

/* ===== FUN_004ffe50 @ 0x004FFE50 ===== */
bool FUN_004ffe50(float param_1,float param_2,int param_3,int param_4,int param_5)



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

        iVar4 = main_00430e10(&local_4,&local_8,&local_c,&local_10,&param_3);

        while (iVar4 != 0) {

          iVar4 = FUN_004ffe50(fVar1,fVar2,local_c * 0x38 + iVar8,param_3 * 0x38 + iVar8,

                               local_10 * 0x38 + iVar8);

          if (iVar4 != 0) {

            if ((*(code **)(iVar6 + 0xc) == (code *)0x0) ||

               (iVar6 = (**(code **)(iVar6 + 0xc))(iVar3,iVar6,0,iVar6 + 0xc), iVar6 != 0)) {

              param_2 = iVar7;

            }

            break;

          }

          iVar4 = main_00430e10(&local_4,&local_8,&local_c,&local_10,&param_3);

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

