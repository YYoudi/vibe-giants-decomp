/* Giants 1.449 — module _unmapped_004d
 * 54 functions (50 named) — decompiled, names from PS2 symbols
 * Original source: C:\Giants\source\_unmapped_004d.c(pp) (assert-string evidence)
 */

/* ===== EnemyIsInvalid__FP6OBJECTT0 @ 0x004D1790 ===== */
/* PS2 candidate: EnemyIsInvalid__FP6OBJECTT0 (conf 0.631) */



undefined4 EnemyIsInvalid__FP6OBJECTT0(int param_1,int param_2)



{

  uint uVar1;

  int iVar2;

  int iVar3;

  

  iVar3 = *(int *)(param_1 + 0x100);

  if ((((param_2 != 0) && (*(int *)(param_2 + 4) != 0)) &&

      ((*(uint *)(param_2 + 0xd8) & 0x4000c000) == 0)) &&

     ((*(float *)(param_2 + 0x278) < *(float *)(param_2 + 0x1c0) &&

      (((iVar2 = ObjIsMecc(param_2), iVar2 == 0 || ((*(uint *)(param_2 + 0xe0) & 0x2000000) == 0))

       || (4.0 <= *(float *)(iVar3 + 0x54))))))) {

    iVar3 = ObjIsReaper(param_2);

    if (iVar3 != 0) {

      uVar1 = *(uint *)(param_1 + 0xe0);

      if ((*(byte *)(param_2 + 0xe0) & 8) == 0) {

        *(uint *)(param_1 + 0xe0) = uVar1 & 0xffffffef;

      }

      else if ((uVar1 & 0x10) == 0) {

        *(uint *)(param_1 + 0xe0) = uVar1 | 0x10;

        return 1;

      }

    }

    return 0;

  }

  return 1;

}

/* ===== FUN_004d1840 @ 0x004D1840 ===== */
/* PS2 candidate: verm_collect__FP6OBJECT (conf 0.399) */



void FUN_004d1840(int param_1,int *param_2)



{

  int iVar1;

  int iVar2;

  int iVar3;

  bool bVar4;

  float10 fVar5;

  float local_24;

  int local_20;

  undefined4 local_18;

  undefined4 local_14;

  float local_10;

  undefined4 local_c;

  undefined4 local_8;

  float local_4;

  

  local_24 = (float)param_2 * (float)param_2;

  iVar1 = *(int *)(param_1 + 0x100);

  local_20 = 0;

  param_2 = DAT_00632d6c;

  if (DAT_00632d6c == (int *)0x0) {

    *(undefined4 *)(iVar1 + 0xc) = 0;

    return;

  }

  do {

    iVar2 = param_2[3];

    if (((*(uint *)(iVar2 + 0xd8) & 0x4000c000) == 0) &&

       (*(float *)(iVar2 + 0x278) < *(float *)(iVar2 + 0x1c0))) {

      if (*(int *)(param_1 + 0xe8) == 100) {

        iVar3 = obj_is_pickup_4a(iVar2);

        if ((iVar3 == 0) && (iVar3 = obj_is_pickup_53(iVar2), iVar3 == 0)) {

          if ((*(int *)(iVar2 + 0x1e0) == 0x2c) &&

             (*(int *)(iVar2 + 0x18c) != *(int *)(param_1 + 0x18c))) goto LAB_004d1921;

        }

        else {

          iVar3 = bldg_get_max_energy(iVar2);

          bVar4 = iVar3 == 0;

LAB_004d191b:

          if (bVar4) goto LAB_004d1921;

        }

      }

      else {

        iVar3 = *(int *)(iVar2 + 4);

        if ((((iVar3 != 0x24e) && (iVar3 != 0x250)) && (iVar3 != 0x251)) && (iVar3 != 0x3ea)) {

          bVar4 = iVar3 == 0x3eb;

          goto LAB_004d191b;

        }

LAB_004d1921:

        fVar5 = (float10)FUN_0050a610((undefined4 *)(iVar2 + 0xa0),(undefined4 *)(param_1 + 0xa0));

        if (fVar5 <= (float10)local_24) {

          if (*(int *)(param_1 + 0xe8) == 100) {

            local_c = *(undefined4 *)(param_1 + 0xa0);

            local_8 = *(undefined4 *)(param_1 + 0xa4);

            local_4 = *(float *)(param_1 + 0x1e8) * *(float *)(param_1 + 0xc4) +

                      *(float *)(param_1 + 0xa8);

            local_18 = *(undefined4 *)(iVar2 + 0xa0);

            local_14 = *(undefined4 *)(iVar2 + 0xa4);

            local_10 = *(float *)(iVar2 + 0x1e8) * *(float *)(iVar2 + 0xc4) +

                       *(float *)(iVar2 + 0xa8);

            iVar3 = ai_class_filter(&local_c,&local_18,2,&DAT_00561374,0);

            if (iVar3 == 0) goto LAB_004d19ce;

          }

          local_24 = (float)fVar5;

          local_20 = iVar2;

        }

      }

    }

LAB_004d19ce:

    param_2 = (int *)*param_2;

    if (param_2 == (int *)0x0) {

      *(int *)(iVar1 + 0xc) = local_20;

      return;

    }

  } while( true );

}

/* ===== FUN_004d1a00 @ 0x004D1A00 ===== */
/* PS2 candidate: ripper_choose_enemy__FP6OBJECTf (conf 0.387) */



void FUN_004d1a00(int param_1,float param_2)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int *piVar6;

  float10 fVar7;

  

  iVar1 = *(int *)(param_1 + 0x100);

  iVar4 = *(int *)(iVar1 + 0xc);

  if ((iVar4 != 0) && ((char)((uint)*(undefined4 *)(iVar4 + 0xd8) >> 8) < '\0')) {

    iVar4 = 0;

  }

  param_2 = param_2 * param_2;

  iVar5 = 0;

  piVar6 = DAT_00632d6c;

  if (DAT_00632d6c != (int *)0x0) {

    do {

      iVar2 = piVar6[3];

      if ((((((*(uint *)(iVar2 + 0xd8) & 0x4000c000) == 0) &&

            (*(float *)(iVar2 + 0x278) < *(float *)(iVar2 + 0x1c0))) &&

           ((iVar3 = ObjIsPlayer(iVar2), iVar3 != 0 || (*(int *)(iVar2 + 0x1e0) == 0x55)))) &&

          (*(int *)(iVar2 + 4) != 0)) &&

         ((((iVar3 = ObjIsMecc(iVar2), iVar3 == 0 || ((*(uint *)(iVar2 + 0xe0) & 0x2000000) == 0))

           || (4.0 <= *(float *)(iVar1 + 0x54))) && (*(int *)(iVar2 + 0x210) == 0)))) {

        fVar7 = (float10)FUN_0050a610(iVar2 + 0xa0,param_1 + 0xa0);

        if (iVar2 == iVar4) {

          fVar7 = fVar7 * (float10)0.5;

        }

        if (fVar7 <= (float10)param_2) {

          param_2 = (float)fVar7;

          iVar5 = iVar2;

        }

      }

      piVar6 = (int *)*piVar6;

    } while (piVar6 != (int *)0x0);

    if (iVar5 != 0) {

      *(int *)(iVar1 + 0xc) = iVar5;

      return;

    }

  }

  if (iVar4 != 0) {

    *(int *)(iVar1 + 0xc) = iVar4;

    return;

  }

  *(undefined4 *)(iVar1 + 0xc) = 0;

  return;

}

/* ===== smartie_mana_timer @ 0x004D1B30 ===== */
void smartie_mana_timer(int param_1)



{

  float fVar1;

  int iVar2;

  float10 fVar3;

  

  fVar3 = (float10)FUN_00518b70(0,0);

  fVar3 = (float10)*(float *)(param_1 + 0xec) - fVar3;

  *(float *)(param_1 + 0xec) = (float)fVar3;

  if ((float10)0.0 <= fVar3) {

    if (*(int *)(param_1 + 4) == 0xe6) {

      fVar1 = *(float *)(DAT_00632ed8 + 0x10e8);

    }

    else if (*(int *)(param_1 + 4) == 0x49) {

      fVar1 = *(float *)(DAT_00632ed8 + 0x10ec);

    }

    else {

      fVar1 = *(float *)(DAT_00632ed8 + 0x10f0);

    }

    if (fVar1 != 0.0) {

      if ((*(byte *)(param_1 + 0xe0) & 8) != 0) {

        return;

      }

      iVar2 = vimp_mana_effect(param_1,param_1,0,fVar1,2);

      if (iVar2 == 0) {

        return;

      }

    }

  }

  object_destroy(param_1);

  return;

}

/* ===== verm_control @ 0x004D1BD0 ===== */
/* PS2 candidate: verm_control__FP6OBJECT (conf 0.469) */



void verm_control(int param_1)



{

  float *pfVar1;

  undefined1 uVar2;

  uint uVar3;

  float fVar4;

  int iVar5;

  int iVar6;

  float fVar7;

  undefined4 *puVar8;

  float10 fVar9;

  float10 fVar10;

  float local_80;

  float local_7c;

  float local_78;

  float local_74;

  float local_70;

  float local_6c;

  float local_68;

  float local_64;

  undefined4 local_60;

  undefined4 local_5c;

  undefined4 local_58;

  float local_54;

  undefined1 local_50 [12];

  undefined1 local_44 [8];

  float local_3c;

  undefined4 local_30;

  undefined4 local_2c;

  undefined4 local_28;

  undefined4 local_24;

  undefined4 local_20;

  int local_1c;

  

  pfVar1 = *(float **)(param_1 + 0x100);

  fVar7 = (float)(*(uint *)(param_1 + 0x30) & 2);

  if ((pfVar1[3] != 0.0) && ((char)((uint)*(undefined4 *)((int)pfVar1[3] + 0xd8) >> 8) < '\0')) {

    pfVar1[3] = 0.0;

  }

  local_74 = fVar7;

  if (pfVar1[3] == 0.0) {

    FUN_004d1a00(param_1,*(undefined4 *)(DAT_00632ed8 + 0xe0));

  }

  fVar4 = pfVar1[3];

  if (fVar4 == 0.0) {

    local_78 = 9.99998e+11;

    local_6c = 9.99998e+11;

    local_54 = 99999.0;

    local_58 = 0x47c34f80;

    local_5c = 0x47c34f80;

  }

  else {

    local_5c = *(undefined4 *)((int)fVar4 + 0xa0);

    local_58 = *(undefined4 *)((int)fVar4 + 0xa4);

    local_54 = *(float *)((int)fVar4 + 0xa8);

    fVar9 = (float10)distancesq2d__FP3P3DT0(&local_5c,param_1 + 0xa0);

    local_78 = (float)fVar9;

    fVar9 = (float10)FUN_0050a610(&local_5c,param_1 + 0xa0);

    local_6c = (float)fVar9;

    local_54 = *(float *)((int)fVar4 + 0x1e8) * *(float *)((int)fVar4 + 0xc4) + local_54;

    fVar7 = local_74;

  }

  switch(*(undefined4 *)(param_1 + 0xe4)) {

  case 0x1f:

    XFGetViewport(local_50);

    local_70 = *(float *)(DAT_00632ed8 + 0x144);

    iVar6 = param_1 + 0xa0;

    fVar9 = (float10)FUN_0050a610(local_50,iVar6);

    if (fVar9 <= (float10)local_70 * (float10)local_70) {

      *(undefined4 *)(param_1 + 0x184) = 0;

    }

    else {

      *(undefined4 *)(param_1 + 0x184) = 0x3f800000;

    }

    if (fVar4 != 0.0) {

      local_6c = (float)crt_rand_scaled(100);

      if (((float)(int)local_6c < *(float *)(DAT_00632ed8 + 0x3e4)) ||

         (ai_fly_update_goal_4(iVar6,local_44,&local_6c), local_3c < 0.64278)) {

        if (pfVar1[0xe] == 0.0) {

          local_1c = param_1;

          local_20 = 0xffffffff;

          local_24 = 8;

          fVar7 = (float)fx_get_free_effect__Fv();

          pfVar1[0xe] = fVar7;

        }

        puVar8 = *(undefined4 **)(param_1 + 0x100);

        *(undefined4 *)(param_1 + 0xe4) = 0x22;

        if (puVar8[3] != 0) {

          fVar9 = (float10)dirfcalcp3d__FP3P3DT0(puVar8[3] + 0xa0,iVar6);

          fVar9 = (float10)rndfloatrange((float)(fVar9 - (float10)50.0),

                                         (float)((float10)50.0 + fVar9));

          puVar8[1] = (float)fVar9;

          diff_rangle__Fff(puVar8 + 1);

          fVar9 = (float10)rndfloatrange(*(undefined4 *)(DAT_00632ed8 + 200),

                                         *(undefined4 *)(DAT_00632ed8 + 0xcc));

          puVar8[2] = (float)fVar9;

          *puVar8 = *(undefined4 *)(DAT_00632ed8 + 0xd0);

        }

        *(undefined4 *)(param_1 + 0x184) = 0x3f800000;

        sound_play_obj(0x4e8,param_1);

        sound_stop_obj(0x4ea,param_1);

      }

      else {

        *(undefined4 *)(param_1 + 0xe4) = 0x2c;

        sound_stop_obj(0x4ea,param_1);

      }

    }

    break;

  case 0x20:

    goto switchD_004d1ccc_caseD_20;

  case 0x21:

    iVar6 = *(int *)(param_1 + 0x100);

    if ((((fVar4 == 0.0) || (*(int *)((int)fVar4 + 4) == 0)) ||

        (((*(uint *)((int)fVar4 + 0xd8) & 0x4000c000) != 0 ||

         (*(float *)((int)fVar4 + 0x1c0) <= *(float *)((int)fVar4 + 0x278))))) ||

       (((iVar5 = ObjIsMecc(fVar4), iVar5 != 0 && ((*(uint *)((int)fVar4 + 0xe0) & 0x2000000) != 0))

        && (*(float *)(iVar6 + 0x54) < 4.0)))) goto LAB_004d2124;

    iVar6 = ObjIsReaper(fVar4);

    if (iVar6 == 0) {

LAB_004d2151:

      local_68 = *(float *)((int)fVar4 + 0xa0);

      local_64 = *(float *)((int)fVar4 + 0xa4);

      local_60 = *(undefined4 *)((int)fVar4 + 0xa8);

      sine_cos_lookup(pfVar1[1],&local_80,&local_7c);

      local_68 = local_80 * pfVar1[2] + local_68;

      local_64 = local_64 - local_7c * pfVar1[2];

      fVar9 = (float10)distance2d__FP3P3DT0(param_1 + 0xa0,&local_68);

      local_6c = (float)fVar9;

      if ((float10)0.0 <= fVar9) {

        *(undefined1 *)(param_1 + 0x208) = 0;

        fVar9 = (float10)dirfcalcp3d__FP3P3DT0(param_1 + 0xa0,&local_68);

        local_70 = (float)fVar9;

        fVar9 = (float10)playerobj_turn(local_70,*(undefined4 *)(param_1 + 200));

        local_74 = (float)fVar9;

        if (ABS(fVar9) == (float10)0.0) {

          fVar7 = 0.0;

        }

        else {

          uVar2 = math_sign_of(local_74 * 0.05,0x3e800000);

          *(undefined1 *)(param_1 + 0x208) = uVar2;

          *(float *)(param_1 + 0x158) = local_70;

          *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) | 0x1000000;

          fVar7 = local_74;

        }

        *(float *)(param_1 + 0x15c) = local_68;

        *(float *)(param_1 + 0x160) = local_64;

        *(undefined4 *)(param_1 + 0x164) = local_60;

        *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) | 0x2000000;

        if (10.0 <= ABS(fVar7)) {

          *(undefined1 *)(param_1 + 0x20a) = 3;

        }

        else {

          uVar2 = math_sign_of(local_6c * 0.1,0x3e4ccccd);

          *(undefined1 *)(param_1 + 0x20a) = uVar2;

        }

      }

      if (pfVar1[2] * 1.1 * pfVar1[2] * 1.1 <= local_78) break;

      local_6c = (float)crt_rand_scaled(100);

LAB_004d286e:

      if ((float)(int)local_6c < *(float *)(DAT_00632ed8 + 0xe4)) goto LAB_004d288a;

      goto LAB_004d2d85;

    }

    uVar3 = *(uint *)(param_1 + 0xe0);

    if ((*(byte *)((int)fVar4 + 0xe0) & 8) == 0) {

      *(uint *)(param_1 + 0xe0) = uVar3 & 0xffffffef;

      goto LAB_004d2151;

    }

    if ((uVar3 & 0x10) != 0) goto LAB_004d2151;

    goto LAB_004d211b;

  case 0x22:

    iVar6 = *(int *)(param_1 + 0x100);

    if ((((fVar4 == 0.0) || (*(int *)((int)fVar4 + 4) == 0)) ||

        (((*(uint *)((int)fVar4 + 0xd8) & 0x4000c000) != 0 ||

         (*(float *)((int)fVar4 + 0x1c0) <= *(float *)((int)fVar4 + 0x278))))) ||

       (((iVar5 = ObjIsMecc(fVar4), iVar5 != 0 && ((*(uint *)((int)fVar4 + 0xe0) & 0x2000000) != 0))

        && (*(float *)(iVar6 + 0x54) < 4.0)))) {

LAB_004d2364:

      if (pfVar1[0xe] != 0.0) {

        fx_delete(pfVar1[0xe]);

      }

      pfVar1[0xe] = 0.0;

      sound_play_obj(0x4ea,param_1);

      *(undefined4 *)(param_1 + 0xe4) = 0x1f;

      pfVar1[3] = 0.0;

    }

    else {

      iVar6 = ObjIsReaper(fVar4);

      if (iVar6 != 0) {

        uVar3 = *(uint *)(param_1 + 0xe0);

        if ((*(byte *)((int)fVar4 + 0xe0) & 8) == 0) {

          *(uint *)(param_1 + 0xe0) = uVar3 & 0xffffffef;

        }

        else if ((uVar3 & 0x10) == 0) {

          *(uint *)(param_1 + 0xe0) = uVar3 | 0x10;

          goto LAB_004d2364;

        }

      }

      local_68 = *(float *)((int)fVar4 + 0xa0);

      local_64 = *(float *)((int)fVar4 + 0xa4);

      local_60 = *(undefined4 *)((int)fVar4 + 0xa8);

      sine_cos_lookup(pfVar1[1],&local_80,&local_7c);

      iVar6 = param_1 + 0xa0;

      local_68 = local_80 * pfVar1[2] + local_68;

      local_64 = local_64 - local_7c * pfVar1[2];

      fVar9 = (float10)distance2d__FP3P3DT0(iVar6,&local_68);

      local_6c = (float)fVar9;

      if ((float10)0.0 <= fVar9) {

        *(undefined1 *)(param_1 + 0x208) = 0;

        fVar9 = (float10)dirfcalcp3d__FP3P3DT0(iVar6,&local_68);

        local_70 = (float)fVar9;

        fVar9 = (float10)playerobj_turn(local_70,*(undefined4 *)(param_1 + 200));

        local_74 = (float)fVar9;

        if (ABS(fVar9) == (float10)0.0) {

          fVar7 = 0.0;

        }

        else {

          uVar2 = math_sign_of(local_74 * 0.05,0x3e800000);

          *(undefined1 *)(param_1 + 0x208) = uVar2;

          *(float *)(param_1 + 0x158) = local_70;

          *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) | 0x1000000;

          fVar7 = local_74;

        }

        *(float *)(param_1 + 0x15c) = local_68;

        *(float *)(param_1 + 0x160) = local_64;

        *(undefined4 *)(param_1 + 0x164) = local_60;

        *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) | 0x2000000;

        if (10.0 <= ABS(fVar7)) {

          *(undefined1 *)(param_1 + 0x20a) = 3;

        }

        else {

          uVar2 = math_sign_of(local_6c * 0.1,0x3e4ccccd);

          *(undefined1 *)(param_1 + 0x20a) = uVar2;

        }

      }

      if ((local_78 < pfVar1[2] * 1.1 * pfVar1[2] * 1.1) &&

         (ai_fly_update_goal_4(iVar6,local_44,&local_6c), 0.64278 <= local_3c)) {

        *(undefined4 *)(param_1 + 0xe4) = 0x2c;

        sound_stop_obj(0x4e8,param_1);

      }

    }

    break;

  case 0x23:

    iVar6 = *(int *)(param_1 + 0x100);

    if ((((fVar4 == 0.0) || (*(int *)((int)fVar4 + 4) == 0)) ||

        (((*(uint *)((int)fVar4 + 0xd8) & 0x4000c000) != 0 ||

         (*(float *)((int)fVar4 + 0x1c0) <= *(float *)((int)fVar4 + 0x278))))) ||

       (((iVar5 = ObjIsMecc(fVar4), iVar5 != 0 && ((*(uint *)((int)fVar4 + 0xe0) & 0x2000000) != 0))

        && (*(float *)(iVar6 + 0x54) < 4.0)))) goto LAB_004d2124;

    iVar6 = ObjIsReaper(fVar4);

    if (iVar6 != 0) {

      uVar3 = *(uint *)(param_1 + 0xe0);

      if ((*(byte *)((int)fVar4 + 0xe0) & 8) == 0) {

        *(uint *)(param_1 + 0xe0) = uVar3 & 0xffffffef;

      }

      else if ((uVar3 & 0x10) == 0) goto LAB_004d211b;

    }

    local_68 = *(float *)((int)fVar4 + 0xa0);

    local_64 = *(float *)((int)fVar4 + 0xa4);

    local_60 = *(undefined4 *)((int)fVar4 + 0xa8);

    sine_cos_lookup(pfVar1[1],&local_80,&local_7c);

    iVar6 = param_1 + 0xa0;

    local_68 = local_80 * pfVar1[2] + local_68;

    local_64 = local_64 - local_7c * pfVar1[2];

    fVar9 = (float10)distance2d__FP3P3DT0(iVar6,&local_68);

    local_6c = (float)fVar9;

    if ((float10)0.0 <= fVar9) {

      *(undefined1 *)(param_1 + 0x208) = 0;

      fVar9 = (float10)dirfcalcp3d__FP3P3DT0(iVar6,&local_68);

      local_70 = (float)fVar9;

      fVar9 = (float10)playerobj_turn(local_70,*(undefined4 *)(param_1 + 200));

      local_74 = (float)fVar9;

      if (ABS(fVar9) == (float10)0.0) {

        fVar7 = 0.0;

      }

      else {

        uVar2 = math_sign_of(local_74 * 0.05,0x3e800000);

        *(undefined1 *)(param_1 + 0x208) = uVar2;

        *(float *)(param_1 + 0x158) = local_70;

        *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) | 0x1000000;

        fVar7 = local_74;

      }

      *(float *)(param_1 + 0x15c) = local_68;

      *(float *)(param_1 + 0x160) = local_64;

      *(undefined4 *)(param_1 + 0x164) = local_60;

      *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) | 0x2000000;

      if (10.0 <= ABS(fVar7)) {

        *(undefined1 *)(param_1 + 0x20a) = 3;

      }

      else {

        uVar2 = math_sign_of(local_6c * 0.1,0x3e4ccccd);

        *(undefined1 *)(param_1 + 0x20a) = uVar2;

      }

    }

    if (*(float *)(DAT_00632ed8 + 0xd4) * *(float *)(DAT_00632ed8 + 0xd4) <= local_78) {

      fVar9 = (float10)distancesq2d__FP3P3DT0(&local_68,iVar6);

      if (((float10)5.0 <= fVar9) && (0.0 <= *pfVar1)) break;

      local_6c = (float)crt_rand_scaled(100);

      goto LAB_004d286e;

    }

    local_6c = (float)crt_rand_scaled(100);

    if ((float)(int)local_6c < *(float *)(DAT_00632ed8 + 0xdc)) goto LAB_004d27a6;

    puVar8 = *(undefined4 **)(param_1 + 0x100);

    if (puVar8[3] == 0) break;

    fVar9 = (float10)dirfcalcp3d__FP3P3DT0(puVar8[3] + 0xa0,iVar6);

    fVar10 = (float10)20.0 + fVar9;

    fVar9 = fVar9 - (float10)20.0;

    goto LAB_004d27e4;

  case 0x24:

    iVar6 = *(int *)(param_1 + 0x100);

    if ((((fVar4 == 0.0) || (*(int *)((int)fVar4 + 4) == 0)) ||

        (((*(uint *)((int)fVar4 + 0xd8) & 0x4000c000) != 0 ||

         (*(float *)((int)fVar4 + 0x1c0) <= *(float *)((int)fVar4 + 0x278))))) ||

       (((iVar5 = ObjIsMecc(fVar4), iVar5 != 0 && ((*(uint *)((int)fVar4 + 0xe0) & 0x2000000) != 0))

        && (*(float *)(iVar6 + 0x54) < 4.0)))) {

LAB_004d2a47:

      if (pfVar1[0xe] != 0.0) {

        fx_delete(pfVar1[0xe]);

      }

      pfVar1[0xe] = 0.0;

      *(undefined4 *)(param_1 + 0xe4) = 0x2b;

      pfVar1[3] = 0.0;

    }

    else {

      iVar6 = ObjIsReaper(fVar4);

      if (iVar6 != 0) {

        uVar3 = *(uint *)(param_1 + 0xe0);

        if ((*(byte *)((int)fVar4 + 0xe0) & 8) == 0) {

          *(uint *)(param_1 + 0xe0) = uVar3 & 0xffffffef;

        }

        else if ((uVar3 & 0x10) == 0) {

          *(uint *)(param_1 + 0xe0) = uVar3 | 0x10;

          goto LAB_004d2a47;

        }

      }

      local_68 = *(float *)((int)fVar4 + 0xa0);

      local_64 = *(float *)((int)fVar4 + 0xa4);

      local_60 = *(undefined4 *)((int)fVar4 + 0xa8);

      sine_cos_lookup(pfVar1[1],&local_80,&local_7c);

      iVar6 = param_1 + 0xa0;

      local_68 = local_80 * pfVar1[2] + local_68;

      local_64 = local_64 - local_7c * pfVar1[2];

      fVar9 = (float10)distance2d__FP3P3DT0(iVar6,&local_68);

      local_6c = (float)fVar9;

      if ((float10)0.0 <= fVar9) {

        *(undefined1 *)(param_1 + 0x208) = 0;

        fVar9 = (float10)dirfcalcp3d__FP3P3DT0(iVar6,&local_68);

        local_70 = (float)fVar9;

        fVar9 = (float10)playerobj_turn(local_70,*(undefined4 *)(param_1 + 200));

        local_74 = (float)fVar9;

        if (ABS(fVar9) == (float10)0.0) {

          fVar7 = 0.0;

        }

        else {

          uVar2 = math_sign_of(local_74 * 0.05,0x3e800000);

          *(undefined1 *)(param_1 + 0x208) = uVar2;

          *(float *)(param_1 + 0x158) = local_70;

          *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) | 0x1000000;

          fVar7 = local_74;

        }

        *(float *)(param_1 + 0x15c) = local_68;

        *(float *)(param_1 + 0x160) = local_64;

        *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) | 0x2000000;

        *(undefined4 *)(param_1 + 0x164) = local_60;

        if (10.0 <= ABS(fVar7)) {

          *(undefined1 *)(param_1 + 0x20a) = 3;

        }

        else {

          uVar2 = math_sign_of(local_6c * 0.1,0x3e4ccccd);

          *(undefined1 *)(param_1 + 0x20a) = uVar2;

        }

      }

      fVar9 = (float10)distancesq2d__FP3P3DT0(&local_68,iVar6);

      if (((fVar9 < (float10)5.0) || (*pfVar1 < 0.0)) &&

         (ai_fly_update_goal_4(iVar6,local_44,&local_6c), 0.64278 <= local_3c)) {

        *(undefined4 *)(param_1 + 0xe4) = 0x2c;

        sound_stop_obj(0x4e8,param_1);

      }

    }

    break;

  case 0x25:

    *(undefined4 *)(param_1 + 0xe4) = 0x26;

  case 0x26:

    iVar6 = *(int *)(param_1 + 0x100);

    if (((((fVar4 != 0.0) && (*(int *)((int)fVar4 + 4) != 0)) &&

         ((*(uint *)((int)fVar4 + 0xd8) & 0x4000c000) == 0)) &&

        (*(float *)((int)fVar4 + 0x278) < *(float *)((int)fVar4 + 0x1c0))) &&

       (((iVar5 = ObjIsMecc(fVar4), iVar5 == 0 || ((*(uint *)((int)fVar4 + 0xe0) & 0x2000000) == 0))

        || (4.0 <= *(float *)(iVar6 + 0x54))))) {

      iVar6 = ObjIsReaper(fVar4);

      if (iVar6 != 0) {

        uVar3 = *(uint *)(param_1 + 0xe0);

        if ((*(byte *)((int)fVar4 + 0xe0) & 8) == 0) {

          *(uint *)(param_1 + 0xe0) = uVar3 & 0xffffffef;

        }

        else if ((uVar3 & 0x10) == 0) {

LAB_004d211b:

          *(uint *)(param_1 + 0xe0) = uVar3 | 0x10;

          goto LAB_004d2124;

        }

      }

      *(undefined1 *)(param_1 + 0x208) = 0;

      if ((int)fVar4 + 0xa0 == 0) {

        local_78 = 0.0;

      }

      else {

        fVar9 = (float10)dirfcalcp3d__FP3P3DT0(param_1 + 0xa0,(int)fVar4 + 0xa0);

        local_78 = (float)fVar9;

      }

      fVar9 = (float10)playerobj_turn(local_78,*(undefined4 *)(param_1 + 200));

      if (ABS(fVar9) != (float10)0.0) {

        uVar2 = math_sign_of((float)(fVar9 * (float10)0.05),0x3e800000);

        *(undefined1 *)(param_1 + 0x208) = uVar2;

        *(float *)(param_1 + 0x158) = local_78;

        *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) | 0x1000000;

      }

      if (local_74 != 0.0) {

LAB_004d2d85:

        *(undefined4 *)(param_1 + 0xe4) = 0x27;

      }

      break;

    }

    goto LAB_004d2124;

  case 0x27:

    iVar6 = *(int *)(param_1 + 0x100);

    if (((fVar4 != 0.0) && (*(int *)((int)fVar4 + 4) != 0)) &&

       ((((*(uint *)((int)fVar4 + 0xd8) & 0x4000c000) == 0 &&

         (*(float *)((int)fVar4 + 0x278) < *(float *)((int)fVar4 + 0x1c0))) &&

        (((iVar5 = ObjIsMecc(fVar4), iVar5 == 0 || ((*(uint *)((int)fVar4 + 0xe0) & 0x2000000) == 0)

          ) || (4.0 <= *(float *)(iVar6 + 0x54))))))) {

      iVar6 = ObjIsReaper(fVar4);

      if (iVar6 != 0) {

        uVar3 = *(uint *)(param_1 + 0xe0);

        if ((*(byte *)((int)fVar4 + 0xe0) & 8) == 0) {

          *(uint *)(param_1 + 0xe0) = uVar3 & 0xffffffef;

        }

        else if ((uVar3 & 0x10) == 0) goto LAB_004d211b;

      }

      *(undefined1 *)(param_1 + 0x208) = 0;

      if ((int)fVar4 + 0xa0 == 0) {

        local_78 = 0.0;

      }

      else {

        fVar9 = (float10)dirfcalcp3d__FP3P3DT0(param_1 + 0xa0,(int)fVar4 + 0xa0);

        local_78 = (float)fVar9;

      }

      fVar9 = (float10)playerobj_turn(local_78,*(undefined4 *)(param_1 + 200));

      if (ABS(fVar9) != (float10)0.0) {

        uVar2 = math_sign_of((float)(fVar9 * (float10)0.05),0x3e800000);

        *(undefined1 *)(param_1 + 0x208) = uVar2;

        *(float *)(param_1 + 0x158) = local_78;

        *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) | 0x1000000;

      }

      if (local_74 == 0.0) {

        if ((*(float *)(param_1 + 0x18) < 0.43333334) && (0.43333334 <= *(float *)(param_1 + 0x14)))

        {

          make_spit__FP6OBJECTP3P3Df(param_1,&local_5c,*(undefined4 *)(DAT_00632ed8 + 0xf0));

        }

        break;

      }

      local_6c = (float)crt_rand_scaled(100);

      if ((float)(int)local_6c < *(float *)(DAT_00632ed8 + 0xe8)) {

        *(undefined4 *)(param_1 + 0xe4) = 0x25;

        break;

      }

      if ((float)(int)local_6c < *(float *)(DAT_00632ed8 + 0xec) + *(float *)(DAT_00632ed8 + 0xe8))

      {

        puVar8 = *(undefined4 **)(param_1 + 0x100);

        if (puVar8[3] != 0) {

          fVar9 = (float10)dirfcalcp3d__FP3P3DT0(puVar8[3] + 0xa0,param_1 + 0xa0);

          fVar9 = (float10)rndfloatrange((float)(fVar9 - (float10)80.0),

                                         (float)((float10)80.0 + fVar9));

          puVar8[1] = (float)fVar9;

          diff_rangle__Fff(puVar8 + 1);

          fVar9 = (float10)rndfloatrange(*(undefined4 *)(DAT_00632ed8 + 200),

                                         *(undefined4 *)(DAT_00632ed8 + 0xcc));

          puVar8[2] = (float)fVar9;

          *puVar8 = *(undefined4 *)(DAT_00632ed8 + 0xd0);

        }

        local_6c = (float)crt_rand_scaled(100);

        if (*(float *)(DAT_00632ed8 + 0x3e4) <= (float)(int)local_6c) {

          *(undefined4 *)(param_1 + 0xe4) = 0x23;

        }

        else {

          sound_play_obj(0x4e8,param_1);

          *(undefined4 *)(param_1 + 0xe4) = 0x2d;

        }

        break;

      }

LAB_004d27a6:

      *(undefined4 *)(param_1 + 0xe4) = 0x29;

      break;

    }

    goto LAB_004d2124;

  case 0x29:

    iVar6 = *(int *)(param_1 + 0x100);

    if (((fVar4 != 0.0) && (*(int *)((int)fVar4 + 4) != 0)) &&

       ((((*(uint *)((int)fVar4 + 0xd8) & 0x4000c000) == 0 &&

         (*(float *)((int)fVar4 + 0x278) < *(float *)((int)fVar4 + 0x1c0))) &&

        (((iVar5 = ObjIsMecc(fVar4), iVar5 == 0 || ((*(uint *)((int)fVar4 + 0xe0) & 0x2000000) == 0)

          ) || (4.0 <= *(float *)(iVar6 + 0x54))))))) {

      iVar6 = ObjIsReaper(fVar4);

      if (iVar6 != 0) {

        uVar3 = *(uint *)(param_1 + 0xe0);

        if ((*(byte *)((int)fVar4 + 0xe0) & 8) == 0) {

          *(uint *)(param_1 + 0xe0) = uVar3 & 0xffffffef;

        }

        else if ((uVar3 & 0x10) == 0) goto LAB_004d211b;

      }

      puVar8 = (undefined4 *)((int)fVar4 + 0xa0);

      *(undefined1 *)(param_1 + 0x208) = 0;

      if (puVar8 == (undefined4 *)0x0) {

        local_74 = 0.0;

      }

      else {

        fVar9 = (float10)dirfcalcp3d__FP3P3DT0(param_1 + 0xa0,puVar8);

        local_74 = (float)fVar9;

      }

      fVar9 = (float10)playerobj_turn(local_74,*(undefined4 *)(param_1 + 200));

      local_70 = (float)fVar9;

      if (ABS(fVar9) == (float10)0.0) {

        fVar7 = 0.0;

      }

      else {

        uVar2 = math_sign_of(local_70 * 0.05,0x3e800000);

        *(undefined1 *)(param_1 + 0x208) = uVar2;

        *(float *)(param_1 + 0x158) = local_74;

        *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) | 0x1000000;

        fVar7 = local_70;

      }

      if (ABS(fVar7) < 5.0) {

        *(undefined1 *)(param_1 + 0x20a) = 0x20;

      }

      *(undefined4 *)(param_1 + 0x15c) = *puVar8;

      *(undefined4 *)(param_1 + 0x160) = *(undefined4 *)((int)fVar4 + 0xa4);

      *(undefined4 *)(param_1 + 0x164) = *(undefined4 *)((int)fVar4 + 0xa8);

      *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) | 0x2000000;

      if (local_78 < *(float *)(DAT_00632ed8 + 0xd8) * *(float *)(DAT_00632ed8 + 0xd8)) {

        sound_play_obj(0x4e6,param_1);

        *(undefined4 *)(param_1 + 0xe4) = 0x2a;

      }

      break;

    }

    goto LAB_004d2124;

  case 0x2a:

    iVar6 = *(int *)(param_1 + 0x100);

    if (((((fVar4 != 0.0) && (*(int *)((int)fVar4 + 4) != 0)) &&

         ((*(uint *)((int)fVar4 + 0xd8) & 0x4000c000) == 0)) &&

        (*(float *)((int)fVar4 + 0x278) < *(float *)((int)fVar4 + 0x1c0))) &&

       (((iVar5 = ObjIsMecc(fVar4), iVar5 == 0 || ((*(uint *)((int)fVar4 + 0xe0) & 0x2000000) == 0))

        || (4.0 <= *(float *)(iVar6 + 0x54))))) {

      iVar6 = ObjIsReaper(fVar4);

      if (iVar6 != 0) {

        uVar3 = *(uint *)(param_1 + 0xe0);

        if ((*(byte *)((int)fVar4 + 0xe0) & 8) == 0) {

          *(uint *)(param_1 + 0xe0) = uVar3 & 0xffffffef;

        }

        else if ((uVar3 & 0x10) == 0) goto LAB_004d211b;

      }

      *(undefined1 *)(param_1 + 0x208) = 0;

      if ((int)fVar4 + 0xa0 == 0) {

        local_70 = 0.0;

      }

      else {

        fVar9 = (float10)dirfcalcp3d__FP3P3DT0(param_1 + 0xa0,(int)fVar4 + 0xa0);

        local_70 = (float)fVar9;

      }

      fVar9 = (float10)playerobj_turn(local_70,*(undefined4 *)(param_1 + 200));

      if (ABS(fVar9) != (float10)0.0) {

        uVar2 = math_sign_of((float)(fVar9 * (float10)0.05),0x3e800000);

        *(undefined1 *)(param_1 + 0x208) = uVar2;

        *(float *)(param_1 + 0x158) = local_70;

        *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) | 0x1000000;

      }

      if (local_74 != 0.0) {

        puVar8 = *(undefined4 **)(param_1 + 0x100);

        if (puVar8[3] != 0) {

          fVar9 = (float10)dirfcalcp3d__FP3P3DT0(puVar8[3] + 0xa0,param_1 + 0xa0);

          fVar9 = (float10)rndfloatrange((float)(fVar9 - (float10)20.0),

                                         (float)((float10)20.0 + fVar9));

          puVar8[1] = (float)fVar9;

          diff_rangle__Fff(puVar8 + 1);

          fVar9 = (float10)rndfloatrange(*(undefined4 *)(DAT_00632ed8 + 200),

                                         *(undefined4 *)(DAT_00632ed8 + 0xcc));

          puVar8[2] = (float)fVar9;

          *puVar8 = *(undefined4 *)(DAT_00632ed8 + 0xd0);

        }

        *(undefined4 *)(param_1 + 0xe4) = 0x23;

        if (local_6c < *(float *)(DAT_00632ed8 + 0xd8) * *(float *)(DAT_00632ed8 + 0xd8)) {

          obj_damage_apply(2,*(undefined4 *)(DAT_00632ed8 + 1000),fVar4,param_1,0,0);

        }

      }

      break;

    }

LAB_004d2124:

    sound_play_obj(0x4f5,param_1);

    *(undefined4 *)(param_1 + 0xe4) = 0x2b;

    pfVar1[3] = 0.0;

    break;

  case 0x2b:

    if (0.73333335 < *(float *)(param_1 + 0x14)) {

      iVar6 = *(int *)(param_1 + 0x274);

      if ((iVar6 != 0) && (*(int *)(iVar6 + 4) == 0xdb)) {

        *(undefined4 *)(iVar6 + 0xe4) = 2;

      }

      *(uint *)(param_1 + 0x1c8) = *(uint *)(param_1 + 0x1c8) | 0x40;

    }

    if (fVar7 != 0.0) {

      ANM_DumpCluster(param_1 + 0xa0);

      sound_play_obj(0x4ea,param_1);

      *(undefined4 *)(param_1 + 0xe4) = 0x1f;

      *(uint *)(param_1 + 0x1c8) = *(uint *)(param_1 + 0x1c8) | 0x840;

    }

    break;

  case 0x2c:

    local_30 = *(undefined4 *)(param_1 + 0xa0);

    local_2c = *(undefined4 *)(param_1 + 0xa4);

    local_28 = *(undefined4 *)(param_1 + 0xa8);

    fx_get_free_effect__Fv();

    if (pfVar1[0xe] != 0.0) {

      fx_delete(pfVar1[0xe]);

    }

    pfVar1[0xe] = 0.0;

    sound_play_obj(0x4f3,param_1);

    *(undefined4 *)(param_1 + 0xe4) = 0x20;

    *(undefined4 *)(param_1 + 0x184) = 0;

    *(uint *)(param_1 + 0x1c8) = *(uint *)(param_1 + 0x1c8) & 0xfffff7ff;

    ANM_DumpCluster((undefined4 *)(param_1 + 0xa0));

    object_copy_posdirinfo(param_1);

    object_stop_movement(param_1);

    if (0.0 < *(float *)(param_1 + 0xa8)) {

      iVar6 = object_allocate_type(0xdb,0x11);

      object_copy_posdirinfo_2(iVar6,param_1);

      *(undefined4 *)(iVar6 + 0xc4) = *(undefined4 *)(param_1 + 0xc4);

      *(undefined4 *)(iVar6 + 0xe4) = 0;

      *(int *)(param_1 + 0x274) = iVar6;

      *(int *)(iVar6 + 0x274) = param_1;

    }

    goto switchD_004d1ccc_caseD_20;

  case 0x2d:

    if (pfVar1[0xe] == 0.0) {

      local_1c = param_1;

      local_20 = 0xffffffff;

      local_24 = 8;

      fVar4 = (float)fx_get_free_effect__Fv();

      pfVar1[0xe] = fVar4;

    }

    if (0.73333335 < *(float *)(param_1 + 0x14)) {

      iVar6 = *(int *)(param_1 + 0x274);

      if ((iVar6 != 0) && (*(int *)(iVar6 + 4) == 0xdb)) {

        *(undefined4 *)(iVar6 + 0xe4) = 2;

      }

      *(uint *)(param_1 + 0x1c8) = *(uint *)(param_1 + 0x1c8) | 0x40;

    }

    if (fVar7 != 0.0) {

      ANM_DumpCluster(param_1 + 0xa0);

      puVar8 = *(undefined4 **)(param_1 + 0x100);

      if (puVar8[3] != 0) {

        fVar9 = (float10)dirfcalcp3d__FP3P3DT0(puVar8[3] + 0xa0,param_1 + 0xa0);

        fVar9 = (float10)rndfloatrange((float)(fVar9 - (float10)80.0),(float)((float10)80.0 + fVar9)

                                      );

        puVar8[1] = (float)fVar9;

        diff_rangle__Fff(puVar8 + 1);

        fVar9 = (float10)rndfloatrange(*(undefined4 *)(DAT_00632ed8 + 200),

                                       *(undefined4 *)(DAT_00632ed8 + 0xcc));

        puVar8[2] = (float)fVar9;

        *puVar8 = *(undefined4 *)(DAT_00632ed8 + 0xd0);

      }

      *(undefined4 *)(param_1 + 0xe4) = 0x24;

      *(uint *)(param_1 + 0x1c8) = *(uint *)(param_1 + 0x1c8) | 0x840;

      *(undefined4 *)(param_1 + 0x184) = 0x3f800000;

      sound_play_obj(0x4e8,param_1);

    }

    break;

  case 0x50:

    *(undefined1 *)(param_1 + 0x20a) = 0x18;

    *(undefined1 *)(param_1 + 0x208) = 0;

    fVar9 = (float10)FUN_00518b70(param_1,0);

    fVar7 = *pfVar1;

    *pfVar1 = (float)((float10)fVar7 - fVar9);

    if ((float10)0.0 <= (float10)fVar7 - fVar9) break;

    FUN_004d1a00(param_1,*(undefined4 *)(DAT_00632ed8 + 0x140));

    if (pfVar1[3] == 0.0) {

      sound_play_obj(0x4f5,param_1);

      *(undefined4 *)(param_1 + 0xe4) = 0x2b;

      break;

    }

LAB_004d288a:

    *(undefined4 *)(param_1 + 0xe4) = 0x25;

    break;

  case 0x5a:

    if (fVar7 != 0.0) {

      if (*(int *)(param_1 + 0x184) == 0x3f800000) {

        *(undefined4 *)(param_1 + 0xe4) = 0x2c;

      }

      else {

        *(undefined4 *)(param_1 + 0xe4) = 0x27;

        FUN_004d1a00(param_1,*(undefined4 *)(DAT_00632ed8 + 0x140));

      }

    }

    break;

  case 0x5b:

    *(undefined4 *)(param_1 + 0x184) = 0;

    if (pfVar1[0xe] != 0.0) {

      fx_delete(pfVar1[0xe]);

    }

    pfVar1[0xe] = 0.0;

    *(uint *)(param_1 + 0x1c8) = *(uint *)(param_1 + 0x1c8) & 0xfffff3bf;

    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xfffffffd;

    if (fVar7 != 0.0) {

      *(undefined4 *)(param_1 + 0xe4) = 0x5c;

      fVar9 = (float10)rndfloatrange(*(undefined4 *)(DAT_00632ed8 + 0x134),

                                     *(undefined4 *)(DAT_00632ed8 + 0x138));

      *(float *)(param_1 + 0xec) = (float)fVar9;

    }

    break;

  case 0x5c:

    fVar9 = (float10)FUN_00518b70(param_1,0);

    fVar9 = (float10)*(float *)(param_1 + 0xec) - fVar9;

    *(float *)(param_1 + 0xec) = (float)fVar9;

    if (fVar9 < (float10)0.0) {

      *(undefined4 *)(param_1 + 0xe4) = 0x5d;

    }

    break;

  case 0x5d:

    if (fVar7 != 0.0) {

      if (*(int *)(param_1 + 0x184) == 0x3f800000) {

        *(undefined4 *)(param_1 + 0xe4) = 0x2c;

      }

      else {

        *(undefined4 *)(param_1 + 0xe4) = 0x27;

        FUN_004d1a00(param_1,*(undefined4 *)(DAT_00632ed8 + 0x140));

      }

    }

    break;

  case 0x5e:

    fVar9 = (float10)FUN_00518b70(0,0);

    fVar9 = (float10)*(float *)(param_1 + 0xec) - fVar9;

    *(float *)(param_1 + 0xec) = (float)fVar9;

    if ((float10)0.0 <= fVar9) {

      if (*(int *)(param_1 + 4) == 0xe6) {

        local_70 = *(float *)(DAT_00632ed8 + 0x10e8);

      }

      else if (*(int *)(param_1 + 4) == 0x49) {

        local_70 = *(float *)(DAT_00632ed8 + 0x10ec);

      }

      else {

        local_70 = *(float *)(DAT_00632ed8 + 0x10f0);

      }

      if ((local_70 != 0.0) &&

         (((*(byte *)(param_1 + 0xe0) & 8) != 0 ||

          (iVar6 = vimp_mana_effect(param_1,param_1,0,local_70,2), iVar6 == 0)))) break;

    }

    object_destroy(param_1);

  }

switchD_004d1ccc_caseD_28:

  if ((*(int *)(param_1 + 0x10) == 2) &&

     (((0.6333333 <= *(float *)(param_1 + 0x14) && (*(float *)(param_1 + 0x18) < 0.6333333)) ||

      ((1.9666667 <= *(float *)(param_1 + 0x14) && (*(float *)(param_1 + 0x18) < 1.9666667)))))) {

    sound_play_obj(0x4ed,param_1);

  }

  return;

switchD_004d1ccc_caseD_20:

  *(undefined1 *)(param_1 + 0x208) = 0;

  fVar9 = (float10)dirfcalcp3d__FP3P3DT0(param_1 + 0xa0,&local_5c);

  local_70 = (float)fVar9;

  fVar9 = (float10)playerobj_turn(local_70,*(undefined4 *)(param_1 + 200));

  if (ABS(fVar9) != (float10)0.0) {

    uVar2 = math_sign_of((float)(fVar9 * (float10)0.05),0x3e800000);

    *(undefined1 *)(param_1 + 0x208) = uVar2;

    *(float *)(param_1 + 0x158) = local_70;

    *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) | 0x1000000;

  }

  *(uint *)(param_1 + 0x1c8) = *(uint *)(param_1 + 0x1c8) & 0xffffffbf;

  if (local_74 != 0.0) {

    if (pfVar1[0xe] != 0.0) {

      fx_delete(pfVar1[0xe]);

    }

    pfVar1[0xe] = 0.0;

    puVar8 = *(undefined4 **)(param_1 + 0x100);

    *(undefined4 *)(param_1 + 0xe4) = 0x21;

    if (puVar8[3] != 0) {

      fVar9 = (float10)dirfcalcp3d__FP3P3DT0(puVar8[3] + 0xa0,param_1 + 0xa0);

      fVar10 = (float10)50.0 + fVar9;

      fVar9 = fVar9 - (float10)50.0;

LAB_004d27e4:

      fVar9 = (float10)rndfloatrange((float)fVar9,(float)fVar10);

      puVar8[1] = (float)fVar9;

      diff_rangle__Fff(puVar8 + 1);

      fVar9 = (float10)rndfloatrange(*(undefined4 *)(DAT_00632ed8 + 200),

                                     *(undefined4 *)(DAT_00632ed8 + 0xcc));

      puVar8[2] = (float)fVar9;

      *puVar8 = *(undefined4 *)(DAT_00632ed8 + 0xd0);

    }

  }

  goto switchD_004d1ccc_caseD_28;

}

/* ===== obj_follow_owner_refpt @ 0x004D3720 ===== */
undefined4 obj_follow_owner_refpt(int param_1)



{

  float *pfVar1;

  int iVar2;

  undefined4 *puVar3;

  undefined4 uVar4;

  float10 fVar5;

  undefined1 local_1c [16];

  float local_c;

  

  iVar2 = *(int *)(param_1 + 0x100);

  puVar3 = *(undefined4 **)(*(int *)(iVar2 + 0x24) + 0x100);

  pfVar1 = (float *)(param_1 + 0xa0);

  playerobj_eval_refpt(*(int *)(iVar2 + 0x24),*(undefined4 *)(iVar2 + 0x28),pfVar1);

  ground_height_at(pfVar1,local_1c);

  if (*(float *)(param_1 + 0xa8) < local_c) {

    *(float *)(param_1 + 0xa8) = local_c;

  }

  uVar4 = *puVar3;

  if ((*(float *)(param_1 + 0xb8) != *pfVar1) ||

     (*(float *)(param_1 + 0xbc) != *(float *)(param_1 + 0xa4))) {

    fVar5 = (float10)dirfcalcp3d__FP3P3DT0(param_1 + 0xb8,pfVar1);

    fVar5 = (float10)FUN_00518b70(param_1,0,0x461c4000,(float)fVar5,param_1 + 200);

    chase_angle((float)(fVar5 * (float10)30.0));

  }

  *(undefined4 *)(iVar2 + 0x34) = puVar3[10];

  *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) | 0x40;

  objspec_dispatch_gate(param_1);

  fVar5 = (float10)FUN_00518b70(param_1,0);

  object_animate_process(param_1,(float)fVar5);

  ObjectCalculateTransform(param_1);

  *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) | 0x20;

  *(undefined4 *)(param_1 + 0x10c) = puVar3[9];

  return uVar4;

}

/* ===== death_handler_c23 @ 0x004D3840 ===== */
void death_handler_c23(undefined4 param_1,float param_2,int param_3,int param_4)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  uint uVar4;

  int iVar5;

  undefined4 *puVar6;

  float10 fVar7;

  char *pcVar8;

  undefined4 uVar9;

  undefined1 *puVar10;

  undefined1 auStack_34 [4];

  undefined4 uStack_30;

  undefined4 uStack_2c;

  undefined4 uStack_28;

  undefined4 uStack_20;

  int iStack_1c;

  

  iVar5 = *(int *)(param_3 + 0x100);

  if (*(float *)(param_3 + 0x1c0) <= *(float *)(param_3 + 0x278)) {

    return;

  }

  if (*(int *)(param_3 + 0xe8) == 1) {

    if (param_4 != 0) {

      *(undefined4 *)(iVar5 + 0xc) = *(undefined4 *)(param_4 + 0x274);

    }

    *(undefined4 *)(param_3 + 0xe8) = 0;

    if (*(int *)(param_3 + 4) == 0xe6) {

      *(undefined4 *)(param_3 + 0xe4) = 0x40;

    }

    else if (*(int *)(param_3 + 4) == 0x49) {

      *(undefined4 *)(param_3 + 0xe4) = 0x21;

    }

    else {

      *(undefined4 *)(param_3 + 0xe4) = 7;

    }

  }

  sound_stop_obj(0x4e8,param_3);

  sound_stop_obj(0x4ea,param_3);

  sound_stop_obj(0x4d3,param_3);

  sound_stop_obj(0x4f7,param_3);

  sound_stop_obj(0x4f8,param_3);

  *(undefined4 *)(param_3 + 0x210) = 0;

  iVar3 = *(int *)(iVar5 + 0x10);

  if ((iVar3 != 0) &&

     (((char)((uint)*(undefined4 *)(iVar3 + 0xd8) >> 8) < '\0' ||

      ((*(int *)(iVar3 + 0x1e0) != 0x31 && (*(int *)(iVar3 + 0x1e0) != 0x2f)))))) {

    *(undefined4 *)(iVar5 + 0x10) = 0;

  }

  param_2 = param_2 + *(float *)(param_3 + 0x278);

  *(float *)(param_3 + 0x278) = param_2;

  if (param_2 < *(float *)(param_3 + 0x1c0)) {

    blood_from_object(param_3);

    if (*(int *)(param_3 + 0xe8) != 0) {

      if (*(int *)(param_3 + 0xe4) != 0x67) {

        return;

      }

      *(undefined4 *)(param_3 + 0xe4) = 0x6c;

      return;

    }

    if (*(int *)(param_3 + 4) == 0xe5) {

      iVar3 = crt_rand_scaled(100);

      if (iVar3 < 0x32) {

        uVar9 = 0x500;

      }

      else {

        uVar9 = 0x501;

      }

      sound_play_obj(uVar9,param_3);

      puVar6 = DAT_00632d6c;

      if (DAT_00632d6c == (undefined4 *)0x0) {

        return;

      }

      do {

        iVar3 = puVar6[3];

        if ((*(int *)(iVar3 + 4) == *(int *)(param_3 + 4)) &&

           (*(int *)(*(int *)(iVar3 + 0x100) + 0x10) == *(int *)(iVar5 + 0x10))) {

          FUN_004d1a00(iVar3,*(undefined4 *)(DAT_00632ed8 + 0x140));

        }

        puVar6 = (undefined4 *)*puVar6;

      } while (puVar6 != (undefined4 *)0x0);

      return;

    }

    if (((param_4 != 0) && (*(int *)(param_4 + 0x1e0) == 0x4d)) &&

       (puVar6 = DAT_00632d6c, *(int *)(param_4 + 0x274) != 0)) {

      for (; puVar6 != (undefined4 *)0x0; puVar6 = (undefined4 *)*puVar6) {

        iVar5 = puVar6[3];

        iVar3 = ObjIsRipper(iVar5);

        if (((iVar3 != 0) &&

            (fVar7 = (float10)distancesq2d__FP3P3DT0(param_3 + 0xa0,iVar5 + 0xa0),

            fVar7 < (float10)200.0)) && (*(int *)(*(int *)(iVar5 + 0x100) + 0xc) == 0)) {

          *(undefined4 *)(*(int *)(iVar5 + 0x100) + 0xc) = *(undefined4 *)(param_4 + 0x274);

        }

      }

    }

    if (*(int *)(param_3 + 4) == 0xe6) {

      iVar5 = crt_rand_scaled(100);

      if (0x31 < iVar5) {

        sound_play_obj(0x4dd,param_3);

        return;

      }

      sound_play_obj(0x4dc,param_3);

      return;

    }

    if (*(int *)(param_3 + 4) == 0x49) {

      iVar5 = crt_rand_scaled(100);

      if (0x31 < iVar5) {

        sound_play_obj(0x4f2,param_3);

        return;

      }

      sound_play_obj(0x4f1,param_3);

      return;

    }

    if (*(int *)(param_3 + 0xe8) != 0x65) {

      return;

    }

    sound_play_obj(0x67d,param_3);

    return;

  }

  if ((((*(int *)(param_3 + 4) == 0x49) || (*(int *)(param_3 + 4) == 0xe6)) &&

      (iVar3 = ObjIsKabuto(DAT_00632a88), iVar3 == 0)) &&

     (iVar3 = crt_rand_scaled(100), iVar3 <= *(int *)(DAT_00632ed8 + 0x1080))) {

    fVar7 = (float10)rndfloatrange(0,0x40c8f5c3);

    math_sin_lut_read_b((float)fVar7);

    math_sin_lut_read_a((float)fVar7);

    iVar3 = object_allocate_type(0x311,0);

    object_change_ospec(iVar3,0x25);

    puVar6 = *(undefined4 **)(iVar3 + 0x100);

    *(undefined4 *)(iVar3 + 0xa0) = *(undefined4 *)(param_3 + 0xa0);

    *(undefined4 *)(iVar3 + 0xa4) = *(undefined4 *)(param_3 + 0xa4);

    *(undefined4 *)(iVar3 + 0xa8) = *(undefined4 *)(param_3 + 0xa8);

    *(uint *)(iVar3 + 0xe0) = *(uint *)(iVar3 + 0xe0) | 1;

    *(uint *)(iVar3 + 0xd8) = *(uint *)(iVar3 + 0xd8) | 0x40000000;

    puVar6[3] = param_3;

    puVar6[4] = 0x3f800000;

    puVar6[5] = 0x41f00000;

    *puVar6 = 0x24;

    if (*(int *)(param_3 + 4) == 0x49) {

      uStack_20 = 0xffffffff;

      iStack_1c = iVar3;

      fx_get_free_effect__Fv();

      puVar6[1] = *(undefined4 *)(DAT_00632ed8 + 0x1078);

      uVar4 = *(uint *)(iVar3 + 0xe0) | 2;

    }

    else {

      if (*(int *)(param_3 + 4) != 0xe6) goto LAB_004d3aa2;

      uStack_20 = 0xffffffff;

      iStack_1c = iVar3;

      fx_get_free_effect__Fv();

      puVar6[1] = *(undefined4 *)(DAT_00632ed8 + 0x107c);

      uVar4 = *(uint *)(iVar3 + 0xe0) | 4;

    }

    *(uint *)(iVar3 + 0xe0) = uVar4;

  }

LAB_004d3aa2:

  if (*(int *)(iVar5 + 0x10) != 0) {

    piVar1 = *(int **)(*(int *)(iVar5 + 0x10) + 0x100);

    *piVar1 = *piVar1 + -1;

  }

  if (*(int *)(param_3 + 4) == 0xe6) {

    uStack_30 = *(undefined4 *)(param_3 + 0xa0);

    uStack_2c = *(undefined4 *)(param_3 + 0xa4);

    uStack_28 = *(undefined4 *)(param_3 + 0xa8);

    puVar10 = auStack_34;

    uVar9 = 8;

    pcVar8 = s_fx_ripper_death_large_005613bc;

    fx_get_free_effect__Fv();

    iVar3 = crt_rand_scaled(100,pcVar8,uVar9,puVar10);

    if (iVar3 < 0x32) {

      uVar9 = 0x4d4;

    }

    else {

      uVar9 = 0x4d5;

    }

    sound_play_3dpos(uVar9,(undefined4 *)(param_3 + 0xa0));

    iVar3 = crt_rand_scaled(100);

    if (iVar3 < 0x32) {

      uVar9 = 0x607;

    }

    else {

      uVar9 = 0x608;

    }

  }

  else {

    if (*(int *)(param_3 + 4) == 0x49) {

      uStack_30 = *(undefined4 *)(param_3 + 0xa0);

      uStack_2c = *(undefined4 *)(param_3 + 0xa4);

      uStack_28 = *(undefined4 *)(param_3 + 0xa8);

      puVar10 = auStack_34;

      uVar9 = 8;

      pcVar8 = s_fx_ripper_death_medium_005613a4;

      fx_get_free_effect__Fv();

      iVar3 = crt_rand_scaled(100,pcVar8,uVar9,puVar10);

      if (iVar3 < 0x32) {

        uVar9 = 0x4eb;

      }

      else {

        uVar9 = 0x4ec;

      }

    }

    else {

      if (*(int *)(param_3 + 0xe8) == 0x65) {

        uVar9 = 0x67e;

        goto LAB_004d3c0a;

      }

      uStack_30 = *(undefined4 *)(param_3 + 0xa0);

      uStack_2c = *(undefined4 *)(param_3 + 0xa4);

      uStack_28 = *(undefined4 *)(param_3 + 0xa8);

      puVar10 = auStack_34;

      uVar9 = 8;

      pcVar8 = s_fx_ripper_death_small_0056138c;

      fx_get_free_effect__Fv();

      iVar3 = crt_rand_scaled(100,pcVar8,uVar9,puVar10);

      if (iVar3 < 0x32) {

        uVar9 = 0x4fc;

      }

      else {

        uVar9 = 0x4fd;

      }

    }

    sound_play_3dpos(uVar9,param_3 + 0xa0);

    iVar3 = crt_rand_scaled(100);

    if (iVar3 < 0x32) {

      uVar9 = 0x60b;

    }

    else {

      uVar9 = 0x60c;

    }

  }

LAB_004d3c0a:

  sound_play_3dpos(uVar9,param_3 + 0xa0);

  iVar3 = *(int *)(param_3 + 0x274);

  if ((iVar3 != 0) && (*(int *)(iVar3 + 4) == 0xdb)) {

    object_destroy(iVar3);

  }

  *(undefined4 *)(param_3 + 0xe4) = 0x5e;

  *(undefined4 *)(param_3 + 0xec) = *(undefined4 *)(DAT_00632ed8 + 0x10f4);

  *(uint *)(param_3 + 0x1c8) = *(uint *)(param_3 + 0x1c8) | 0xe00;

  *(uint *)(param_3 + 0xd8) = *(uint *)(param_3 + 0xd8) | 0x40000010;

  if (*(int *)(param_3 + 0xe8) == 100) {

    iVar3 = *(int *)(param_3 + 0x100);

    if ((*(int *)(iVar3 + 0x24) != 0) && (puVar6 = DAT_00632d6c, *(int *)(iVar3 + 0x40) != -1)) {

      for (; puVar6 != (undefined4 *)0x0; puVar6 = (undefined4 *)*puVar6) {

        iVar2 = puVar6[3];

        if ((((param_3 != iVar2) && (*(int *)(iVar2 + 4) == 0xe6)) &&

            (iVar2 = *(int *)(iVar2 + 0x100), *(int *)(iVar2 + 0x24) == *(int *)(iVar3 + 0x24))) &&

           (*(int *)(iVar3 + 0x40) < *(int *)(iVar2 + 0x40))) {

          *(int *)(iVar2 + 0x40) = *(int *)(iVar2 + 0x40) + -1;

        }

      }

      *(undefined4 *)(iVar3 + 0x40) = 0xffffffff;

    }

    if ((*(byte *)(param_3 + 0xe0) & 4) == 0) {

      piVar1 = (int *)(*(int *)(*(int *)(iVar5 + 0x24) + 0x100) + 8);

      *piVar1 = *piVar1 + -1;

    }

    formation_notify_death(*(undefined4 *)(iVar5 + 0x24));

  }

  if (*(int *)(iVar5 + 0x38) != 0) {

    fx_delete(*(int *)(iVar5 + 0x38));

  }

  *(undefined4 *)(iVar5 + 0x38) = 0;

  return;

}

/* ===== ripper_animselect @ 0x004D3ED0 ===== */
/* PS2 candidate: ripper_animselect (conf 0.489) */



void ripper_animselect(int param_1)



{

  undefined4 uVar1;

  int iVar2;

  bool bVar3;

  int iVar4;

  int iVar5;

  float10 fVar6;

  

  iVar5 = *(int *)(param_1 + 0x100);

  if (*(int *)(param_1 + 0x210) != 0) {

    iVar2 = *(int *)(*(int *)(param_1 + 0x210) + 0x1e0);

    if (iVar2 == 1) {

      return;

    }

    if (iVar2 == 0x4c) {

      return;

    }

  }

  iVar2 = *(int *)(param_1 + 0x10);

  bVar3 = true;

  iVar4 = 1;

  switch(*(undefined4 *)(param_1 + 0xe4)) {

  case 5:

  case 6:

  case 7:

  case 8:

  case 9:

  case 0x21:

  case 0x23:

  case 0x28:

  case 0x29:

  case 0x3f:

  case 0x40:

  case 0x43:

  case 0x50:

  case 100:

  case 0x65:

  case 0x67:

  case 0x68:

  case 0x96:

  case 0x97:

    iVar4 = 2;

    break;

  case 10:

    iVar4 = 0x33;

    break;

  case 0xb:

    iVar4 = 9;

    break;

  case 0x14:

    if (iVar2 == 2) {

      return;

    }

    *(undefined4 *)(param_1 + 0x10c) = *(undefined4 *)(*(int *)(iVar5 + 0x24) + 0xfc);

    goto LAB_004d4031;

  case 0x15:

  case 0x6a:

    if (iVar2 == 1) {

      if ((*(byte *)(param_1 + 0x30) & 2) == 0) goto LAB_004d4074;

    }

    else {

      if ((*(byte *)(param_1 + 0x30) & 2) != 0) goto switchD_004d3f27_caseD_42;

LAB_004d4074:

      if ((*(float *)(param_1 + 0x18) < 0.43333334) && (0.43333334 <= *(float *)(param_1 + 0x14))) {

        if (*(int *)(iVar5 + 0xc) != 0) {

          make_spit__FP6OBJECTP3P3Df

                    (param_1,*(int *)(iVar5 + 0xc) + 0xa0,*(undefined4 *)(DAT_00632ed8 + 0x11c));

          *(undefined4 *)(param_1 + 0xf0) = *(undefined4 *)(DAT_00632ed8 + 0xd14);

          *(int *)(param_1 + 0xf4) = *(int *)(param_1 + 0xf4) + -1;

          iVar4 = 0x32;

          break;

        }

        *(undefined4 *)(param_1 + 0xf4) = 0;

      }

    }

    iVar4 = 0x32;

    break;

  case 0x1f:

  case 0x22:

  case 0x24:

  case 0x2c:

  case 0x3d:

    iVar4 = 0x2a;

    break;

  case 0x20:

    if ((iVar2 == 0x28) || (iVar2 == 0x29)) {

LAB_004d41e1:

      bVar3 = false;

      iVar4 = iVar2;

    }

    else {

      iVar5 = crt_rand_scaled(100);

      iVar4 = (iVar5 < 0x33) + 0x28;

      bVar3 = false;

    }

    break;

  case 0x25:

  case 0x26:

    iVar4 = 1;

    bVar3 = false;

    break;

  case 0x27:

    iVar4 = 0x32;

    bVar3 = false;

    break;

  case 0x2a:

    iVar4 = 10;

    bVar3 = false;

    break;

  case 0x2b:

  case 0x2d:

  case 0x47:

    iVar4 = 0x2b;

    bVar3 = false;

    break;

  case 0x3e:

    if ((iVar2 == 0x28) || (iVar2 == 0x29)) goto LAB_004d41e1;

    iVar5 = crt_rand_scaled(100);

    iVar4 = (iVar5 < 0x33) + 0x28;

    bVar3 = false;

    break;

  case 0x41:

    iVar4 = 0x32;

    bVar3 = false;

    break;

  case 0x42:

  case 0x66:

switchD_004d3f27_caseD_42:

    iVar4 = 1;

    break;

  case 0x44:

    iVar4 = 10;

    bVar3 = false;

    break;

  case 0x45:

  case 0x46:

    iVar4 = 0x33;

    bVar3 = false;

    break;

  case 0x55:

    if ((*(byte *)(param_1 + 0x30) & 2) == 0) {

      return;

    }

    if ((0.0 <= *(float *)(param_1 + 0xf0)) || (*(int *)(iVar5 + 0xc) == 0))

    goto switchD_004d3f27_caseD_42;

    *(undefined4 *)(param_1 + 0xe4) = 0x56;

LAB_004d3f6e:

    iVar4 = 0x32;

    break;

  case 0x56:

    if (((*(int *)(iVar5 + 0xc) != 0) && (*(float *)(param_1 + 0x18) < 0.43333334)) &&

       (0.43333334 <= *(float *)(param_1 + 0x14))) {

      if (*(int *)(param_1 + 4) == 0xe6) {

        uVar1 = *(undefined4 *)(DAT_00632ed8 + 0x11c);

      }

      else {

        uVar1 = *(undefined4 *)(DAT_00632ed8 + 0xf0);

      }

      make_spit__FP6OBJECTP3P3Df(param_1,*(int *)(iVar5 + 0xc) + 0xa0,uVar1);

    }

    if ((*(byte *)(param_1 + 0x30) & 2) == 0) goto LAB_004d3f6e;

    fVar6 = (float10)rndfloatrange(*(undefined4 *)(DAT_00632ed8 + 0xd0c),

                                   *(undefined4 *)(DAT_00632ed8 + 0xd10));

    *(float *)(param_1 + 0xf0) = (float)fVar6;

    iVar4 = 1;

    *(undefined4 *)(param_1 + 0xe4) = 0x55;

    break;

  case 0x5a:

  case 0x6c:

    if ((iVar2 == 0x31) || (iVar2 == 0x34)) goto LAB_004d41e1;

    iVar5 = crt_rand_scaled(100);

    bVar3 = false;

    iVar4 = ((iVar5 < 0x33) - 1 & 0xfffffffd) + 0x34;

    break;

  case 0x5b:

    bVar3 = false;

  case 0x5e:

    iVar4 = 0x2c;

    break;

  case 0x5c:

    if (iVar2 == 0x2d) {

      return;

    }

    if (iVar2 == 0x30) {

      return;

    }

    iVar5 = crt_rand_scaled(100);

    iVar4 = ((iVar5 < 0x33) - 1 & 0xfffffffd) + 0x30;

    break;

  case 0x5d:

    iVar4 = 0x2e;

    bVar3 = false;

    break;

  case 0x98:

    iVar4 = 0x39;

  }

  if (iVar2 != iVar4) {

    if (iVar4 == 2) {

LAB_004d4031:

      ObjectSetAnim(param_1,2,0x21,1,*(float *)(param_1 + 0x1b4) * *(float *)(param_1 + 0xc4),

                    0x3e2aaaab);

      return;

    }

    if (bVar3) {

      anim_select_check();

      return;

    }

    anim_select_check2(param_1,iVar4);

  }

  return;

}

/* ===== make_spit__FP6OBJECTP3P3Df @ 0x004D4350 ===== */
/* PS2 candidate: make_spit__FP6OBJECTP3P3Df (conf 0.437) */



void make_spit__FP6OBJECTP3P3Df(int param_1,int param_2,float param_3)



{

  float fVar1;

  float fVar2;

  int iVar3;

  int iVar4;

  float10 fVar5;

  char *pcVar6;

  undefined4 uVar7;

  undefined1 *puVar8;

  undefined1 local_34 [20];

  undefined4 local_20;

  int local_1c;

  

  if (*(int *)(param_1 + 4) == 0xe6) {

    uVar7 = 0xe8;

  }

  else {

    uVar7 = 0x5a;

  }

  iVar3 = object_find(uVar7);

  if (iVar3 != 0) {

    iVar4 = object_allocate_type(0x374,0);

    if (iVar4 != 0) {

      object_copy_personality(iVar4,iVar3);

      object_copy_activedata(iVar4,iVar3);

      puVar8 = local_34;

      local_20 = 0xffffffff;

      uVar7 = 4;

      local_1c = iVar4;

      if (*(int *)(param_1 + 4) == 0xe6) {

        pcVar6 = s_fx_ripper_large_proj_00561404;

        *(undefined4 *)(iVar4 + 0xe8) = 1;

        fx_get_free_effect__Fv();

        iVar3 = crt_rand_scaled(100,pcVar6,uVar7,puVar8);

        if (iVar3 < 0x32) {

          uVar7 = 0x4cb;

        }

        else {

          uVar7 = 0x4cc;

        }

        sound_play_3dpos(uVar7,param_1 + 0xa0);

        *(undefined4 *)(iVar4 + 0xf4) = 0x636;

        *(undefined4 *)(iVar4 + 0xf8) = 0x4d8;

        *(undefined4 *)(iVar4 + 0xfc) = 0x4d9;

      }

      else {

        pcVar6 = s_fx_ripper_medium_proj_005613ec;

        *(undefined4 *)(iVar4 + 0xe8) = 0;

        fx_get_free_effect__Fv();

        iVar3 = crt_rand_scaled(100,pcVar6,uVar7,puVar8);

        if (iVar3 < 0x32) {

          uVar7 = 0x4e2;

        }

        else {

          uVar7 = 0x4e3;

        }

        sound_play_3dpos(uVar7,param_1 + 0xa0);

        *(undefined4 *)(iVar4 + 0xf4) = 0x637;

        *(undefined4 *)(iVar4 + 0xf8) = 0x4ef;

      }

      playerobj_eval_refpt(param_1,0,iVar4 + 0xa0);

      object_copy_posdirinfo(iVar4);

      *(undefined4 *)(iVar4 + 200) = *(undefined4 *)(param_1 + 200);

      *(undefined4 *)(iVar4 + 0xcc) = 0;

      *(undefined4 *)(iVar4 + 0xd0) = 0;

      uVar7 = *(undefined4 *)(param_1 + 0x18c);

      *(undefined4 *)(iVar4 + 0x11c) = *(undefined4 *)(iVar4 + 0x194);

      *(undefined4 *)(iVar4 + 0x10c) = *(undefined4 *)(iVar4 + 0x194);

      *(undefined4 *)(iVar4 + 0x18c) = uVar7;

      fVar5 = (float10)distance2d__FP3P3DT0(param_2,iVar4 + 0xa0);

      fVar1 = (float)(fVar5 / (float10)*(float *)(iVar4 + 0x10c));

      fVar2 = (fVar1 * *(float *)(iVar4 + 0x1b8) * fVar1 * 0.5 +

              (*(float *)(param_2 + 8) - *(float *)(iVar4 + 0xa8))) / fVar1;

      fVar5 = (float10)rndfloatrange((1.0 - param_3 * 0.01) * fVar2,(param_3 * 0.01 + 1.0) * fVar2);

      *(float *)(iVar4 + 0x118) = (float)fVar5;

      *(float *)(iVar4 + 0x108) = (float)fVar5;

      **(float **)(iVar4 + 0x100) = fVar1 + 1.0;

      (*(undefined4 **)(iVar4 + 0x100))[1] = **(undefined4 **)(iVar4 + 0x100);

      *(int *)(iVar4 + 0x274) = param_1;

    }

  }

  return;

}

/* ===== obj_face_target_move @ 0x004D4580 ===== */
float10 obj_face_target_move(float param_1,int param_2,float param_3)



{

  int iVar1;

  undefined1 uVar2;

  float10 fVar3;

  

  iVar1 = (int)param_1;

  *(undefined1 *)((int)param_1 + 0x208) = 0;

  if (param_2 == 0) {

    param_1 = param_3;

  }

  else {

    fVar3 = (float10)dirfcalcp3d__FP3P3DT0((int)param_1 + 0xa0,param_2);

    param_1 = (float)fVar3;

  }

  fVar3 = (float10)playerobj_turn(param_1,*(undefined4 *)(iVar1 + 200));

  if (ABS(fVar3) == (float10)0.0) {

    return (float10)0.0;

  }

  uVar2 = math_sign_of((float)fVar3 * 0.05,0x3e800000);

  *(undefined1 *)(iVar1 + 0x208) = uVar2;

  *(float *)(iVar1 + 0x158) = param_1;

  *(uint *)(iVar1 + 0xd8) = *(uint *)(iVar1 + 0xd8) | 0x1000000;

  return (float10)(float)fVar3;

}

/* ===== ai_face_move @ 0x004D4630 ===== */
void ai_face_move(undefined4 *param_1,undefined4 *param_2,float param_3)



{

  float fVar1;

  int iVar2;

  undefined1 uVar3;

  float10 fVar4;

  float10 fVar5;

  

  iVar2 = (int)param_1;

  fVar4 = (float10)distance2d__FP3P3DT0((int)param_1 + 0xa0,param_2);

  if ((float10)param_3 <= fVar4) {

    *(undefined1 *)((int)param_1 + 0x208) = 0;

    if (param_2 == (undefined4 *)0x0) {

      param_1 = param_2;

    }

    else {

      fVar5 = (float10)dirfcalcp3d__FP3P3DT0((int)param_1 + 0xa0,param_2);

      param_1 = (undefined4 *)(float)fVar5;

    }

    fVar5 = (float10)playerobj_turn(param_1,*(undefined4 *)(iVar2 + 200));

    fVar1 = (float)fVar5;

    if (ABS(fVar5) == (float10)0.0) {

      fVar1 = 0.0;

    }

    else {

      uVar3 = math_sign_of(fVar1 * 0.05,0x3e800000);

      *(undefined1 *)(iVar2 + 0x208) = uVar3;

      *(undefined4 **)(iVar2 + 0x158) = param_1;

      *(uint *)(iVar2 + 0xd8) = *(uint *)(iVar2 + 0xd8) | 0x1000000;

    }

    *(undefined4 *)(iVar2 + 0x15c) = *param_2;

    *(undefined4 *)(iVar2 + 0x160) = param_2[1];

    *(undefined4 *)(iVar2 + 0x164) = param_2[2];

    *(uint *)(iVar2 + 0xd8) = *(uint *)(iVar2 + 0xd8) | 0x2000000;

    if (ABS(fVar1) < 10.0) {

      uVar3 = math_sign_of((float)fVar4 * 0.1,0x3e4ccccd);

      *(undefined1 *)(iVar2 + 0x20a) = uVar3;

      return;

    }

    *(undefined1 *)(iVar2 + 0x20a) = 3;

  }

  return;

}

/* ===== enemy_check_player_grab__FP6OBJECTif @ 0x004D4760 ===== */
/* PS2 candidate: enemy_check_player_grab__FP6OBJECTif (conf 0.486) */



int enemy_check_player_grab__FP6OBJECTif(int param_1,undefined4 param_2,float param_3)



{

  int iVar1;

  uint uVar2;

  undefined4 *puVar3;

  int iVar4;

  int iVar5;

  float10 fVar6;

  float10 fVar7;

  float local_18;

  float local_14;

  float local_10;

  undefined1 local_c [12];

  

  playerobj_eval_refpt(param_1,param_2,local_c);

  puVar3 = DAT_00632d6c;

  do {

    if (puVar3 == (undefined4 *)0x0) {

      return 0;

    }

    iVar1 = puVar3[3];

    if (((((((*(uint *)(iVar1 + 0xd8) & 0x4000c000) == 0) &&

           (*(float *)(iVar1 + 0x278) < *(float *)(iVar1 + 0x1c0))) &&

          (*(int *)(iVar1 + 0x18c) != *(int *)(param_1 + 0x18c))) &&

         (((*(int *)(iVar1 + 0x210) == 0 && ((*(uint *)(iVar1 + 0x1c8) & 0x20000) != 0)) &&

          ((iVar4 = ObjIsMecc(iVar1), iVar4 != 0 || (iVar4 = ObjIsReaper(iVar1), iVar4 != 0)))))) &&

        ((iVar4 = *(int *)(param_1 + 0x100), *(int *)(iVar1 + 4) != 0 &&

         ((*(uint *)(iVar1 + 0xd8) & 0x4000c000) == 0)))) &&

       ((*(float *)(iVar1 + 0x278) < *(float *)(iVar1 + 0x1c0) &&

        (((iVar5 = ObjIsMecc(iVar1), iVar5 == 0 || ((*(uint *)(iVar1 + 0xe0) & 0x2000000) == 0)) ||

         (4.0 <= *(float *)(iVar4 + 0x54))))))) {

      iVar4 = ObjIsReaper(iVar1);

      if (iVar4 != 0) {

        uVar2 = *(uint *)(param_1 + 0xe0);

        if ((*(byte *)(iVar1 + 0xe0) & 8) == 0) {

          *(uint *)(param_1 + 0xe0) = uVar2 & 0xffffffef;

        }

        else if ((uVar2 & 0x10) == 0) {

          *(uint *)(param_1 + 0xe0) = uVar2 | 0x10;

          goto LAB_004d4912;

        }

      }

      local_18 = (*(float *)(iVar1 + 0x288) + *(float *)(iVar1 + 0x27c)) * 0.5;

      local_14 = (*(float *)(iVar1 + 0x28c) + *(float *)(iVar1 + 0x280)) * 0.5;

      local_10 = (*(float *)(iVar1 + 0x290) + *(float *)(iVar1 + 0x284)) * 0.5;

      fVar6 = (float10)FUN_0050a610(local_c,&local_18);

      fVar7 = (float10)param_3 + (float10)*(float *)(iVar1 + 0x154);

      if (fVar6 < fVar7 * fVar7) {

        return iVar1;

      }

    }

LAB_004d4912:

    puVar3 = (undefined4 *)*puVar3;

  } while( true );

}

/* ===== FUN_004d4930 @ 0x004D4930 ===== */
int FUN_004d4930(int param_1)



{

  int iVar1;

  undefined4 *puVar2;

  

  puVar2 = DAT_00632d6c;

  while( true ) {

    if (puVar2 == (undefined4 *)0x0) {

      return 0;

    }

    iVar1 = puVar2[3];

    if ((((*(uint *)(iVar1 + 0xd8) & 0x4000c000) == 0) &&

        (*(float *)(iVar1 + 0x278) < *(float *)(iVar1 + 0x1c0))) &&

       (*(int *)(iVar1 + 0x210) == param_1)) break;

    puVar2 = (undefined4 *)*puVar2;

  }

  return iVar1;

}

/* ===== cspec_004d4980 @ 0x004D4980 ===== */
void cspec_004d4980(int param_1)



{

  int iVar1;

  

  iVar1 = *(int *)(param_1 + 0x100);

  obj_ptr_clear_if_dead(iVar1 + 0xc);

  obj_ptr_clear_if_dead(iVar1 + 0x10);

  obj_ptr_clear_if_dead(iVar1 + 0x44);

  obj_ptr_clear_if_dead(iVar1 + 0x24);

  return;

}

/* ===== target_not_player_check @ 0x004D49C0 ===== */
undefined4 target_not_player_check(int param_1)



{

  if ((*(int *)(param_1 + 0xe8) != 100) && (*(int *)(param_1 + 0xe8) != 0x65)) {

    return 1;

  }

  return 0;

}

/* ===== kabutoai_is_punch_anim__FP6OBJECT_2 @ 0x004D49E0 ===== */
bool kabutoai_is_punch_anim__FP6OBJECT_2(int param_1)



{

  return *(int *)(param_1 + 0xe4) == 0x98;

}

/* ===== reaper_state_set98 @ 0x004D4A00 ===== */
void reaper_state_set98(int param_1)



{

  if ((*(int *)(param_1 + 0xe8) != 100) && (*(int *)(param_1 + 0xe8) != 0x65)) {

    *(undefined4 *)(param_1 + 0xe4) = 0x98;

  }

  return;

}

/* ===== reaper_state98_advance @ 0x004D4A20 ===== */
void reaper_state98_advance(int param_1)



{

  if ((*(int *)(param_1 + 0xe4) == 0x98) &&

     (*(float *)(param_1 + 0x278) < *(float *)(param_1 + 0x1c0))) {

    if (*(int *)(param_1 + 4) == 0xe6) {

      *(undefined4 *)(param_1 + 0xe4) = 0x47;

      return;

    }

    *(uint *)(param_1 + 0xe4) = ((*(int *)(param_1 + 4) != 0x49) - 1 & 0x26) + 5;

  }

  return;

}

/* ===== ripnest_move @ 0x004D4AE0 ===== */
/* PS2 candidate: ripnest_move (conf 0.394) */



void ripnest_move(int param_1)



{

  int *piVar1;

  undefined4 *puVar2;

  uint uVar3;

  int iVar4;

  bool bVar5;

  float10 fVar6;

  

  piVar1 = *(int **)(param_1 + 0x100);

  if (*(int *)(param_1 + 0xe4) == 0) {

    sound_play_obj(0x4ff,param_1);

    *(undefined4 *)(param_1 + 0xe4) = 1;

  }

  iVar4 = *(int *)(param_1 + 0x10);

  uVar3 = *(uint *)(param_1 + 0x30) & 2;

  switch(*(undefined4 *)(param_1 + 0xe4)) {

  case 1:

    *(undefined4 *)(param_1 + 0xe4) = 2;

    iVar4 = object_allocate_type(0xdb,0x11);

    object_copy_posdirinfo_2(iVar4,param_1);

    *(undefined4 *)(iVar4 + 0xe4) = 0;

    *(int *)(param_1 + 0x274) = iVar4;

    return;

  case 2:

    bVar5 = iVar4 == 0xb;

    break;

  case 3:

    if (iVar4 == 10) {

      if (uVar3 == 0) {

        return;

      }

      *(undefined4 *)(param_1 + 0xe4) = 5;

      iVar4 = object_allocate_type(0xe5,0x11);

      puVar2 = *(undefined4 **)(iVar4 + 0x100);

      fVar6 = (float10)rndfloatrange(*(undefined4 *)(DAT_00632ed8 + 0xc0),

                                     *(undefined4 *)(DAT_00632ed8 + 0xc4));

      *(float *)(iVar4 + 0xc4) = (float)fVar6;

      object_set_location_p3d(iVar4,(undefined4 *)(param_1 + 0xa0));

      fVar6 = (float10)rndfloat(0x43b40000);

      *(float *)(iVar4 + 200) = (float)fVar6;

      *(undefined4 *)(iVar4 + 0x108) = 0x41c80000;

      *(undefined4 *)(iVar4 + 0xe4) = 0x50;

      puVar2[4] = param_1;

      *puVar2 = 0x3f800000;

      puVar2[5] = *(undefined4 *)(param_1 + 0xa0);

      puVar2[6] = *(undefined4 *)(param_1 + 0xa4);

      puVar2[7] = *(undefined4 *)(param_1 + 0xa8);

      *piVar1 = *piVar1 + 1;

      return;

    }

  case 4:

    bVar5 = iVar4 == 0;

    break;

  case 5:

    if ((uVar3 != 0) && (*piVar1 < *(int *)(DAT_00632ed8 + 0x148))) {

      *(undefined4 *)(param_1 + 0xe4) = 3;

      return;

    }

  default:

    goto switchD_004d4b2b_default;

  }

  if ((bVar5) && (uVar3 != 0)) {

    *(undefined4 *)(param_1 + 0xe4) = 5;

  }

switchD_004d4b2b_default:

  return;

}

/* ===== cspec_004d4c80 @ 0x004D4C80 ===== */
void cspec_004d4c80(int param_1)



{

  bool bVar1;

  int iVar2;

  

  bVar1 = false;

  iVar2 = param_1;

  switch(*(undefined4 *)(param_1 + 0xe4)) {

  case 2:

    iVar2 = 0xb;

    break;

  case 3:

    iVar2 = 10;

    break;

  case 4:

    iVar2 = 0;

    break;

  case 5:

    bVar1 = true;

    iVar2 = 1;

  }

  if (*(int *)(param_1 + 0x10) != iVar2) {

    if (bVar1) {

      anim_select_check();

      return;

    }

    anim_select_check2(param_1,iVar2);

  }

  return;

}

/* ===== death_handler_c47 @ 0x004D4CF0 ===== */
void death_handler_c47(undefined4 param_1,float param_2,int param_3)



{

  undefined4 *puVar1;

  int iVar2;

  

  if ((*(uint *)(param_3 + 0xd8) & 0x40000000) == 0) {

    param_2 = param_2 + *(float *)(param_3 + 0x278);

    *(float *)(param_3 + 0x278) = param_2;

    puVar1 = DAT_00632d6c;

    if (*(float *)(param_3 + 0x1c0) <= param_2) {

      iVar2 = object_allocate_type(0xe2,0x11);

      object_copy_posdirinfo_2(iVar2,param_3);

      *(undefined4 *)(iVar2 + 0xc4) = *(undefined4 *)(param_3 + 0xc4);

      object_destroy(param_3);

      return;

    }

    for (; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {

      iVar2 = puVar1[3];

      if ((*(int *)(iVar2 + 4) == 0xe5) && (*(int *)(*(int *)(iVar2 + 0x100) + 0x10) == param_3)) {

        FUN_004d1a00(iVar2,*(undefined4 *)(DAT_00632ed8 + 0x140));

      }

    }

    *(undefined4 *)(param_3 + 0xe4) = 4;

    blood_from_object(param_3);

  }

  return;

}

/* ===== obj_state_machine_update @ 0x004D4DB0 ===== */
void obj_state_machine_update(int param_1)



{

  undefined4 uVar1;

  int iVar2;

  uint uVar3;

  float10 fVar4;

  

  uVar3 = *(uint *)(param_1 + 0x30) & 2;

  switch(*(undefined4 *)(param_1 + 0xe4)) {

  case 0:

    if ((*(int *)(param_1 + 0x10) == 0xb) && (uVar3 != 0)) {

      *(undefined4 *)(param_1 + 0xe4) = 1;

      return;

    }

    break;

  case 1:

    iVar2 = *(int *)(param_1 + 0x274);

    if (((iVar2 != 0) && (*(int *)(iVar2 + 0x1e0) == 0x17)) &&

       ((*(float *)(param_1 + 0xa0) != *(float *)(iVar2 + 0xa0) ||

        (*(float *)(param_1 + 0xa4) != *(float *)(iVar2 + 0xa4))))) {

      uVar1 = *(undefined4 *)(DAT_00632ed8 + 0x3d4);

      *(undefined4 *)(param_1 + 0xe4) = 3;

      *(undefined4 *)(param_1 + 0xec) = uVar1;

    }

    break;

  case 2:

    if ((*(int *)(param_1 + 0x10) == 0xc) && (uVar3 != 0)) {

      object_destroy(param_1);

      return;

    }

    break;

  case 3:

    fVar4 = (float10)FUN_00518b70(param_1,0);

    fVar4 = (float10)*(float *)(param_1 + 0xec) - fVar4;

    *(float *)(param_1 + 0xec) = (float)fVar4;

    if (fVar4 < (float10)0.0) {

      *(undefined4 *)(param_1 + 0xe4) = 2;

      return;

    }

  }

  return;

}

/* ===== cspec_004d4ea0 @ 0x004D4EA0 ===== */
void cspec_004d4ea0(int param_1)



{

  bool bVar1;

  int iVar2;

  

  bVar1 = false;

  iVar2 = param_1;

  switch(*(undefined4 *)(param_1 + 0xe4)) {

  case 0:

    iVar2 = 0xb;

    break;

  case 1:

  case 3:

    bVar1 = true;

    iVar2 = 1;

    break;

  case 2:

    iVar2 = 0xc;

  }

  if (*(int *)(param_1 + 0x10) != iVar2) {

    if (bVar1) {

      anim_select_check();

      return;

    }

    anim_select_check2(param_1,iVar2);

  }

  return;

}

/* ===== smoke_puff_spawner_c49 @ 0x004D4F00 ===== */
void smoke_puff_spawner_c49(float param_1)



{

  float *pfVar1;

  undefined4 uVar2;

  int *piVar3;

  float fVar4;

  float fVar5;

  int iVar6;

  int iVar7;

  float10 fVar8;

  undefined4 uVar9;

  float fStack_24;

  float fStack_20;

  float fStack_1c;

  int iStack_18;

  int iStack_14;

  int *piStack_10;

  undefined1 auStack_c [12];

  

  fVar5 = param_1;

  piVar3 = *(int **)((int)param_1 + 0x100);

  if (DAT_00632e74 == 0) {

    iVar7 = *(int *)((int)param_1 + 4);

    piStack_10 = piVar3;

    if ((iVar7 == 0xdd) || (iVar7 == 0xde)) {

      fVar8 = (float10)FUN_00518b70(param_1,0);

      fVar8 = (float10)*(float *)((int)fVar5 + 0xec) - fVar8;

      *(float *)((int)fVar5 + 0xec) = (float)fVar8;

      if (fVar8 <= (float10)0.0) {

        if (5 < *(int *)((int)fVar5 + 0xe4)) {

          main_smoke_004f90e0((int)fVar5 + 0xa0,0x3f800000);

          if (*(int *)((int)fVar5 + 4) == 0xdd) {

            iVar7 = object_allocate_type(0xde,0x11);

            object_copy_posdirinfo_2(iVar7,fVar5);

            object_change_ospec(iVar7,0x31);

            *(undefined4 *)(iVar7 + 0xc4) = *(undefined4 *)((int)fVar5 + 0xc4);

          }

          object_destroy(fVar5);

          return;

        }

        *(undefined4 *)((int)fVar5 + 0xec) = 0x3e99999a;

        playerobj_eval_refpt(fVar5,*(int *)((int)fVar5 + 0xe4),auStack_c);

        texture_object_debug_dump_2

                  (auStack_c,*(float *)((int)fVar5 + 0xc4) + *(float *)((int)fVar5 + 0xc4));

        if (*(int *)((int)fVar5 + 0xe4) < 3) {

          playerobj_eval_refpt(fVar5,*(int *)((int)fVar5 + 0xe4) + 6,auStack_c);

          func_0x004f8900(0x3f800000,auStack_c);

        }

        iVar7 = *(int *)((int)fVar5 + 0xe4) + 1;

        *(int *)((int)fVar5 + 0xe4) = iVar7;

        if (5 < iVar7) {

          *(undefined4 *)((int)fVar5 + 0xec) = 0x41033333;

        }

      }

    }

    else if (iVar7 == 0xfd) {

      switch(*(undefined4 *)((int)param_1 + 0xe4)) {

      case 0:

        if (*(int *)((int)param_1 + 0xe8) == 1) {

          *(undefined4 *)((int)param_1 + 0xe4) = 0x14;

          anim_select_check(param_1,1);

          return;

        }

        *(undefined4 *)((int)param_1 + 0xe4) = 0x16;

        anim_select_check2(param_1,10);

        return;

      case 0x14:

        sine_cos_lookup(*(undefined4 *)((int)param_1 + 200),&fStack_20,&fStack_1c);

        param_1 = fStack_20 * *(float *)((int)fVar5 + 0x10c);

        fStack_24 = -(fStack_1c * *(float *)((int)fVar5 + 0x10c));

        if ((0.0 < param_1) &&

           (fVar4 = *(float *)((int)fVar5 + 0x15c) - *(float *)((int)fVar5 + 0xa0), fVar4 < param_1)

           ) {

          param_1 = fVar4;

        }

        if ((param_1 < 0.0) &&

           (fVar4 = *(float *)((int)fVar5 + 0x15c) - *(float *)((int)fVar5 + 0xa0), param_1 < fVar4)

           ) {

          param_1 = fVar4;

        }

        if ((0.0 < fStack_24) &&

           (fVar4 = *(float *)((int)fVar5 + 0x160) - *(float *)((int)fVar5 + 0xa4),

           fVar4 < fStack_24)) {

          fStack_24 = fVar4;

        }

        if ((fStack_24 < 0.0) &&

           (fVar4 = *(float *)((int)fVar5 + 0x160) - *(float *)((int)fVar5 + 0xa4),

           fStack_24 < fVar4)) {

          fStack_24 = fVar4;

        }

        *(float *)((int)fVar5 + 0xa0) = param_1 + *(float *)((int)fVar5 + 0xa0);

        *(float *)((int)fVar5 + 0xa4) = fStack_24 + *(float *)((int)fVar5 + 0xa4);

        setMenuSelection__7PS2Gameiiii(fVar5);

        fVar4 = *(float *)((int)fVar5 + 0x1d4) * *(float *)((int)fVar5 + 0xc4) +

                *(float *)((int)fVar5 + 0x140);

        *(float *)((int)fVar5 + 0xa8) = fVar4;

        if (fVar4 < 0.0) {

          *(undefined4 *)((int)fVar5 + 0xa8) = 0;

        }

        object_copy_posdirinfo(fVar5);

        if ((param_1 == 0.0) && (fStack_24 == 0.0)) {

          *(uint *)((int)fVar5 + 0x30) = *(uint *)((int)fVar5 + 0x30) & 0xfffffffe;

          *(undefined4 *)((int)fVar5 + 0xe4) = 0x15;

          return;

        }

        break;

      case 0x15:

        sine_cos_lookup(*(undefined4 *)((int)param_1 + 200),&fStack_20,&fStack_1c);

        fVar4 = *(float *)((int)fVar5 + 0x10c) * 0.85;

        *(float *)((int)fVar5 + 0x10c) = fVar4;

        *(float *)((int)fVar5 + 0xa0) = fStack_20 * fVar4 + *(float *)((int)fVar5 + 0xa0);

        *(float *)((int)fVar5 + 0xa4) = -(fVar4 * fStack_1c) + *(float *)((int)fVar5 + 0xa4);

        setMenuSelection__7PS2Gameiiii(fVar5);

        fVar4 = *(float *)((int)fVar5 + 0x1d4) * *(float *)((int)fVar5 + 0xc4) +

                *(float *)((int)fVar5 + 0x140);

        *(float *)((int)fVar5 + 0xa8) = fVar4;

        if (fVar4 < 0.0) {

          *(undefined4 *)((int)fVar5 + 0xa8) = 0;

        }

        object_copy_posdirinfo(fVar5);

        if ((*(byte *)((int)fVar5 + 0x30) & 2) != 0) {

          anim_select_check2(fVar5,10);

          *(undefined4 *)((int)fVar5 + 0xe4) = 0x16;

          return;

        }

        break;

      case 0x16:

        if ((*(byte *)((int)param_1 + 0x30) & 2) != 0) {

LAB_004d547a:

          anim_select_check2(fVar5,0xb);

          *(undefined4 *)((int)fVar5 + 0xe4) = 0x17;

          return;

        }

        break;

      case 0x17:

        if ((*(byte *)((int)param_1 + 0x30) & 2) != 0) {

          iStack_18 = crt_rand_scaled(100);

          if (*(int *)((int)fVar5 + 0xe8) == 1) {

            pfVar1 = (float *)(DAT_00632ee0 + 0x18 +

                              (piVar3[1] * 7 + *(int *)(DAT_00632ed8 + 0x1bc)) * 4);

            if (*pfVar1 <= (float)iStack_18) {

              if (*(float *)(DAT_00632ee0 +

                            ((piVar3[1] + 1) * 7 + *(int *)(DAT_00632ed8 + 0x1bc)) * 4) + *pfVar1 <=

                  (float)iStack_18) {

                iVar7 = 0xe5;

              }

              else {

                iVar7 = 0x49;

              }

            }

            else {

              iVar7 = 0xe6;

            }

          }

          else if (iStack_18 < 10) {

            iVar7 = 0xe6;

          }

          else {

            iVar7 = ((0x3b < iStack_18) - 1 & 0xffffff64) + 0xe5;

          }

          iVar6 = object_allocate_type(iVar7,0x11);

          iStack_14 = *(int *)(iVar6 + 0x100);

          *(undefined4 *)(iVar6 + 0xa0) = *(undefined4 *)((int)fVar5 + 0xa0);

          *(undefined4 *)(iVar6 + 0xa4) = *(undefined4 *)((int)fVar5 + 0xa4);

          *(undefined4 *)(iVar6 + 0xa8) = *(undefined4 *)((int)fVar5 + 0xa8);

          object_copy_posdirinfo(iVar6);

          iStack_18 = *(undefined4 *)((int)fVar5 + 200);

          *(int *)(iVar6 + 200) = iStack_18;

          sine_cos_lookup(iStack_18,&param_1,&fStack_24);

          *(float *)(iVar6 + 0x128) = param_1 * 40.0;

          *(float *)(iVar6 + 300) = fStack_24 * -40.0;

          if (*(int *)(iVar6 + 0x104) == 0) {

            *(undefined4 *)(iVar6 + 0x108) = 0x41f00000;

          }

          else {

            *(undefined4 *)(iVar6 + 0x130) = 0x41f00000;

          }

          *(undefined4 *)(iVar6 + 0x11c) = *(undefined4 *)(iVar6 + 0x194);

          *(undefined4 *)(iVar6 + 0x10c) = *(undefined4 *)(iVar6 + 0x194);

          *(undefined4 *)(iVar6 + 0xe4) = 0x50;

          **(undefined4 **)(iVar6 + 0x100) = 0x40400000;

          *(float *)(iStack_14 + 0x10) = fVar5;

          *(undefined4 *)(iStack_14 + 0x14) = *(undefined4 *)((int)fVar5 + 0xa0);

          *(undefined4 *)(iStack_14 + 0x18) = *(undefined4 *)((int)fVar5 + 0xa4);

          *(undefined4 *)(iStack_14 + 0x1c) = *(undefined4 *)((int)fVar5 + 0xa8);

          if (iVar7 == 0xe6) {

            uVar9 = *(undefined4 *)(DAT_00632ed8 + 0x124);

            uVar2 = *(undefined4 *)(DAT_00632ed8 + 0x120);

          }

          else if (iVar7 == 0x49) {

            uVar9 = *(undefined4 *)(DAT_00632ed8 + 0xf8);

            uVar2 = *(undefined4 *)(DAT_00632ed8 + 0xf4);

          }

          else {

            uVar9 = *(undefined4 *)(DAT_00632ed8 + 0xc4);

            uVar2 = *(undefined4 *)(DAT_00632ed8 + 0xc0);

          }

          fVar8 = (float10)rndfloatrange(uVar2,uVar9);

          *(float *)(iVar6 + 0xc4) = (float)fVar8;

          *piStack_10 = *piStack_10 + 1;

          *(undefined4 *)((int)fVar5 + 0xe4) = 0x18;

          return;

        }

        break;

      case 0x18:

        if (*(int *)((int)param_1 + 0xe8) == 1) {

          if (*piVar3 < *(int *)(DAT_00632ee0 + 0x14 +

                                (piVar3[1] * 7 + *(int *)(DAT_00632ed8 + 0x1bc)) * 4)) {

LAB_004d5429:

            *(undefined4 *)((int)param_1 + 0xec) = *(undefined4 *)(DAT_00632ed8 + 0x13c);

            *(undefined4 *)((int)param_1 + 0xe4) = 0x19;

            return;

          }

        }

        else if (*piVar3 < 3) goto LAB_004d5429;

        break;

      case 0x19:

        fVar8 = (float10)FUN_00518b70(param_1,0);

        fVar8 = (float10)*(float *)((int)fVar5 + 0xec) - fVar8;

        *(float *)((int)fVar5 + 0xec) = (float)fVar8;

        if (fVar8 < (float10)0.0) goto LAB_004d547a;

      }

    }

  }

  return;

}

/* ===== death_handler_c49 @ 0x004D55F0 ===== */
void death_handler_c49(undefined4 param_1,float param_2,int param_3)



{

  int iVar1;

  

  param_2 = param_2 + *(float *)(param_3 + 0x278);

  *(float *)(param_3 + 0x278) = param_2;

  if (*(int *)(param_3 + 4) == 0xdd) {

    if (*(float *)(param_3 + 0x1c0) <= param_2) {

      main_smoke_004f90e0(param_3 + 0xa0,0x3f800000);

      sound_play_3dpos(0x67e,param_3 + 0xa0);

      iVar1 = object_allocate_type(0xde,0x11);

      object_copy_posdirinfo_2(iVar1,param_3);

      object_change_ospec(iVar1,0x31);

      *(undefined4 *)(iVar1 + 0xc4) = *(undefined4 *)(param_3 + 0xc4);

      object_destroy(param_3);

      return;

    }

  }

  else {

    if (*(int *)(param_3 + 4) != 0xfd) {

      return;

    }

    if (*(float *)(param_3 + 0x1c0) <= param_2) {

      main_smoke_004f90e0(param_3 + 0xa0,0x3f800000);

      sound_play_3dpos(0x67e,param_3 + 0xa0);

      iVar1 = object_allocate_type(0xdd,0x11);

      object_copy_posdirinfo_2(iVar1,param_3);

      object_change_ospec(iVar1,0x31);

      *(uint *)(iVar1 + 0x1c8) = *(uint *)(iVar1 + 0x1c8) | 0x20000;

      *(undefined4 *)(iVar1 + 0xc4) = *(undefined4 *)(param_3 + 0xc4);

      object_destroy(param_3);

      return;

    }

  }

  blood_from_object(param_3);

  return;

}

/* ===== cspec_004d5700 @ 0x004D5700 ===== */
undefined4 cspec_004d5700(void)



{

  return 8;

}

/* ===== rndstart @ 0x004D5710 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void rndstart(void)



{

  DWORD DVar1;

  

  DVar1 = timeGetTime();

  _DAT_00632950 = DVar1 & 0x7fff;

  crt_getptd_user(_DAT_00632950);

  return;

}

/* ===== crt_rand_scaled @ 0x004D5730 ===== */
/* PS2 candidate: rndint (conf 0.75) */



int crt_rand_scaled(int param_1)



{

  int iVar1;

  

  iVar1 = _rand();

  return iVar1 * param_1 >> 0xf;

}

/* ===== rndintrange @ 0x004D5740 ===== */
/* PS2 candidate: rndintrange (conf 0.54) */



int rndintrange(int param_1,int param_2)



{

  int iVar1;

  

  iVar1 = _rand();

  return (iVar1 * ((param_2 - param_1) + 1) >> 0xf) + param_1;

}

/* ===== rndfloat @ 0x004D5760 ===== */
/* PS2 candidate: rndfloat (conf 0.413) */



float10 rndfloat(float param_1)



{

  int iVar1;

  

  iVar1 = _rand();

  return (float10)iVar1 * (float10)param_1 * (float10)3.0517578e-05;

}

/* ===== rndfloatrange @ 0x004D5780 ===== */
/* PS2 candidate: rndfloatrange (conf 0.672) */



float10 rndfloatrange(float param_1,float param_2)



{

  int iVar1;

  

  iVar1 = _rand();

  return ((float10)param_2 - (float10)param_1) * (float10)iVar1 * (float10)3.0517578e-05 +

         (float10)param_1;

}

/* ===== rpboat_unlock_from_boat__FP6OBJECTT0 @ 0x004D5810 ===== */
/* PS2 candidate: rpboat_unlock_from_boat__FP6OBJECTT0 (conf 0.506) */



void rpboat_unlock_from_boat__FP6OBJECTT0(int param_1,int param_2)



{

  uint *puVar1;

  int iVar2;

  

  puVar1 = *(uint **)(param_1 + 0x100);

  if (param_2 != 0) {

    sound_stop_obj(0x62b,param_1);

    sound_stop_obj(0x626,param_1);

    sound_stop_obj(0x629,param_1);

    sound_stop_obj(0x62e,param_1);

    sound_stop_obj(0x6fc,param_1);

    sound_stop_obj(0x6fc,param_2);

    sound_stop_obj(0x36c,param_1);

    *(undefined4 *)(param_1 + 0x210) = 0;

    *(undefined4 *)(param_2 + 0x274) = 0;

    camera_override_done();

    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 2;

    iVar2 = gun_find_right(param_1);

    if (iVar2 != 0) {

      *(uint *)(iVar2 + 0xd8) = *(uint *)(iVar2 + 0xd8) & 0xbfffffff;

    }

    *puVar1 = *puVar1 & 0xfffffffd;

    playerobj_eval_refpt(param_2,5,param_1 + 0xa0);

    iVar2 = reaper_0052e4a0(param_1);

    if (iVar2 != 0) {

      reaper_00530bd0(param_2,0,0,0,5,0);

    }

    *(undefined4 *)(param_2 + 0x18c) = 0;

    sound_play_obj(0x62a,param_2);

  }

  return;

}

/* ===== object_attach_target @ 0x004D5910 ===== */
/* PS2 candidate: rpboat_lock_to_boat__FP6OBJECTT0 (conf 0.406) */



void object_attach_target(int param_1,int param_2)



{

  uint *puVar1;

  int iVar2;

  int iVar3;

  

  iVar2 = *(int *)(param_1 + 0x100);

  *(int *)(param_1 + 0x210) = param_2;

  *(undefined4 *)(param_1 + 0x214) = 9;

  *(undefined4 *)(param_1 + 0x218) = 0;

  obj_snap_variant_a(param_1);

  anim_select_check(param_1,0x91);

  if (*(int *)(param_2 + 0x1e0) != 0x5a) {

    object_change_ospec(param_2,0x5a);

  }

  *(int *)(param_2 + 0x274) = param_1;

  iVar3 = gun_find_right(param_1);

  if (iVar3 != 0) {

    *(uint *)(iVar3 + 0xd8) = *(uint *)(iVar3 + 0xd8) | 0x40000000;

  }

  *(undefined4 *)(param_1 + 0x208) = 0;

  *(undefined4 *)(param_1 + 0x20c) = 0;

  *(undefined4 *)(param_2 + 0x18c) = *(undefined4 *)(param_1 + 0x18c);

  iVar2 = *(int *)(iVar2 + 0x50);

  if (iVar2 != 0) {

    puVar1 = (uint *)(iVar2 + 0xd8);

    *puVar1 = *puVar1 | 0x40000000;

  }

  sound_play_2(0x62b,param_1);

  sound_play_2(0x626,param_1);

  reaper_stop_looping_effects(param_1);

  return;

}

/* ===== rpboat_ghost_logic__FP6OBJECT @ 0x004D59D0 ===== */
/* PS2 candidate: rpboat_ghost_logic__FP6OBJECT (conf 0.391) */



void rpboat_ghost_logic__FP6OBJECT(int param_1)



{

  float fVar1;

  int iVar2;

  float10 fVar3;

  

  iVar2 = *(int *)(param_1 + 0x100);

  fVar3 = (float10)FUN_00518b70(param_1,0);

  *(uint *)(param_1 + 0x1c8) = *(uint *)(param_1 + 0x1c8) | 0x400;

  *(float *)(param_1 + 0xa0) =

       (float)(((float10)*(float *)(param_1 + 0x134) + (float10)*(float *)(param_1 + 0x128)) * fVar3

               * (float10)0.5 + (float10)*(float *)(param_1 + 0xa0));

  *(float *)(param_1 + 0xa4) =

       (float)(((float10)*(float *)(param_1 + 0x138) + (float10)*(float *)(param_1 + 300)) * fVar3 *

               (float10)0.5 + (float10)*(float *)(param_1 + 0xa4));

  fVar1 = *(float *)(param_1 + 0x13c);

  *(undefined4 *)(param_1 + 0x134) = *(undefined4 *)(param_1 + 0x128);

  *(undefined4 *)(param_1 + 0x138) = *(undefined4 *)(param_1 + 300);

  *(undefined4 *)(param_1 + 0x13c) = *(undefined4 *)(param_1 + 0x130);

  *(float *)(param_1 + 0xa8) =

       (float)(((float10)fVar1 + (float10)*(float *)(param_1 + 0x130)) * fVar3 * (float10)0.5 +

              (float10)*(float *)(param_1 + 0xa8));

  PhysicsExApplyLocation(param_1);

  *(uint *)(param_1 + 0x1c8) = *(uint *)(param_1 + 0x1c8) & 0xfffffbff;

  fVar3 = (float10)FUN_00518b70(param_1,0);

  object_animate_process(param_1,(float)fVar3);

  *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) | 0x40;

  rpboat_tilt__FP6OBJECT(param_1);

  fVar3 = (float10)FUN_00518b70(param_1,0,0x461c4000,*(undefined4 *)(iVar2 + 0x48),

                                (float *)(iVar2 + 0x40));

  chase_angle((float)(fVar3 * (float10)*(float *)(DAT_00632ed8 + 0xe04)));

  fVar3 = (float10)FUN_00518b70(param_1,0,0x461c4000,*(undefined4 *)(iVar2 + 0x4c),

                                (undefined4 *)(iVar2 + 0x44));

  chase_angle((float)(fVar3 * (float10)*(float *)(DAT_00632ed8 + 0xe00)));

  GEO_MatBuildXYZ(param_1 + 0x294,-*(float *)(iVar2 + 0x40),*(undefined4 *)(iVar2 + 0x44),

                  *(undefined4 *)(param_1 + 200));

  return;

}

/* ===== rpboat_tilt__FP6OBJECT @ 0x004D5B50 ===== */
/* PS2 candidate: rpboat_tilt__FP6OBJECT (conf 0.453) */



void rpboat_tilt__FP6OBJECT(int param_1)



{

  float *pfVar1;

  float fVar2;

  int iVar3;

  uint uVar4;

  int iVar5;

  float10 fVar6;

  undefined4 local_94;

  undefined4 local_90;

  undefined4 local_8c;

  undefined4 local_88;

  undefined4 local_84;

  undefined4 local_80;

  undefined4 local_7c [2];

  undefined4 local_74;

  undefined4 local_70;

  undefined4 local_6c;

  undefined1 local_44 [68];

  

  iVar3 = *(int *)(param_1 + 0x100);

  local_94 = 0;

  iVar5 = *(int *)(param_1 + 0x274);

  if (*(int *)(param_1 + 0x274) == 0) {

    iVar5 = param_1;

  }

  iVar5 = fx_create(iVar5);

  if (((iVar5 != 0) && (*(int *)(param_1 + 0x274) != 0)) &&

     (DAT_00632a88 == *(int *)(param_1 + 0x274))) {

    if ((char)((uint)*(undefined4 *)(DAT_00632a88 + 0x20c) >> 8) < '\0') {

      ref_get_anode2(local_44,&local_94,param_1,*(undefined4 *)(param_1 + 0x10),4,0);

      camera_override_begin(local_44);

      AudioSetSpeakerConfig__F14SPEAKER_SYSTEM(local_94);

    }

    else {

      camera_override_done();

    }

  }

  *(undefined4 *)(iVar3 + 0x48) = 0;

  *(undefined4 *)(iVar3 + 0x4c) = 0;

  uVar4 = **(uint **)(param_1 + 0x104);

  if ((char)uVar4 < '\0') {

    if ((uVar4 & 0x28) != 0) {

      if (*(float *)(param_1 + 0xf8) < 0.0 == (*(float *)(param_1 + 0xf8) == 0.0)) {

        fVar6 = (float10)FUN_00518b70(0,0);

        *(float *)(param_1 + 0xf8) = (float)((float10)*(float *)(param_1 + 0xf8) - fVar6);

      }

      else if (0.0 < (float)(*(uint **)(param_1 + 0x104))[9]) {

        local_74 = *(undefined4 *)(param_1 + 0xa0);

        local_70 = *(undefined4 *)(param_1 + 0xa4);

        local_6c = *(undefined4 *)(param_1 + 0xa8);

        fx_get_free_effect__Fv();

        *(undefined4 *)(param_1 + 0xf8) = 0x3e4ccccd;

      }

      goto LAB_004d5d41;

    }

    uVar4 = *(uint *)(param_1 + 0xe0);

    *(undefined4 *)(param_1 + 0xf8) = 0;

    if (*(char *)(param_1 + 0x20a) == '\0') {

      if ((uVar4 & 0x10) == 0) {

        if (((uVar4 & 0x20) != 0) || ((uVar4 & 8) == 0)) {

          *(undefined4 *)(iVar3 + 0x48) = 0;

          goto LAB_004d5d41;

        }

        fVar2 = *(float *)(DAT_00632ed8 + 0xdfc);

      }

      else {

        *(uint *)(param_1 + 0xe0) = uVar4 & 0xffffffef | 8;

        fVar2 = *(float *)(DAT_00632ed8 + 0xdfc);

      }

      goto LAB_004d5d3c;

    }

    *(uint *)(param_1 + 0xe0) = uVar4 & 0xffffffd7 | 0x10;

    if ((uVar4 & 1) == 0) {

      fVar2 = *(float *)(DAT_00632ed8 + 0xd94);

    }

    else {

      fVar2 = *(float *)(DAT_00632ed8 + 0xe10);

    }

  }

  else {

    *(undefined4 *)(param_1 + 0xf8) = 0;

    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xffffffd7 | 0x10;

    if (*(float *)(DAT_00632ed8 + 0xf10) < *(float *)(param_1 + 0x130)) {

      *(undefined4 *)(iVar3 + 0x48) = *(undefined4 *)(iVar3 + 0x40);

      goto LAB_004d5d41;

    }

    fVar2 = *(float *)(DAT_00632ed8 + 0xf14);

LAB_004d5d3c:

    fVar2 = -fVar2;

  }

  *(float *)(iVar3 + 0x48) = fVar2;

LAB_004d5d41:

  if (((**(byte **)(param_1 + 0x104) & 0x28) == 0) &&

     (25.0 < *(float *)(*(byte **)(param_1 + 0x104) + 0x24))) {

    local_90 = *(undefined4 *)(param_1 + 0x128);

    local_8c = *(undefined4 *)(param_1 + 300);

    local_88 = *(undefined4 *)(param_1 + 0x130);

    local_84 = *(undefined4 *)(param_1 + 0x298);

    local_80 = *(undefined4 *)(param_1 + 0x2a8);

    local_7c[0] = *(undefined4 *)(param_1 + 0x2b8);

    normalize__FPfN20(&local_90,&local_8c,&local_88);

    normalize__FPfN20(&local_84,&local_80,local_7c);

    fVar6 = (float10)Dot__FP3P3DT0(&local_90,&local_84);

    *(float *)(iVar3 + 0x4c) =

         (float)(fVar6 * (float10)1.4285715 * (float10)*(float *)(DAT_00632ed8 + 0xd90));

  }

  pfVar1 = (float *)(iVar3 + 0x40);

  if ((*(uint *)(param_1 + 0xe0) & 8) == 0) {

    fVar6 = (float10)FUN_00518b70(param_1,0,0x461c4000,*(undefined4 *)(iVar3 + 0x48),pfVar1);

    chase_angle((float)(fVar6 * (float10)*(float *)(DAT_00632ed8 + 0xe04)));

  }

  else {

    if ((*(uint *)(param_1 + 0xe0) & 0x20) == 0) {

      fVar6 = (float10)FUN_00518b70(param_1,0,0x461c4000,*(undefined4 *)(iVar3 + 0x48),pfVar1);

      fVar6 = fVar6 * (float10)*(float *)(DAT_00632ed8 + 0xe08);

    }

    else {

      fVar6 = (float10)FUN_00518b70(param_1,0,0x461c4000,*(undefined4 *)(iVar3 + 0x48),pfVar1);

      fVar6 = fVar6 * (float10)*(float *)(DAT_00632ed8 + 0xe0c);

    }

    chase_angle((float)fVar6);

    if (*(float *)(iVar3 + 0x48) < 0.0) {

      *(float *)(iVar3 + 0x48) = *(float *)(iVar3 + 0x48) + 360.0;

    }

    if (*(float *)(iVar3 + 0x48) == *pfVar1) {

      uVar4 = *(uint *)(param_1 + 0xe0);

      if ((uVar4 & 0x20) == 0) {

        *(uint *)(param_1 + 0xe0) = uVar4 | 0x20;

      }

      else {

        *(uint *)(param_1 + 0xe0) = uVar4 & 0xffffffd7;

      }

    }

  }

  fVar6 = (float10)FUN_00518b70(param_1,0,0x461c4000,*(undefined4 *)(iVar3 + 0x4c),

                                (undefined4 *)(iVar3 + 0x44));

  chase_angle((float)(fVar6 * (float10)*(float *)(DAT_00632ed8 + 0xe00)));

  GEO_MatBuildXYZ(param_1 + 0x294,-*pfVar1,*(undefined4 *)(iVar3 + 0x44),

                  *(undefined4 *)(param_1 + 200));

  ANM_DumpCluster(param_1,iVar3 + 0x60);

  return;

}

/* ===== seamonster_ai_main_c90 @ 0x004D5F20 ===== */
void seamonster_ai_main_c90(float param_1)



{

  undefined4 *puVar1;

  float *pfVar2;

  float *pfVar3;

  uint *puVar4;

  float fVar5;

  int iVar6;

  float *pfVar7;

  uint uVar8;

  uint uVar9;

  float fVar10;

  int iVar11;

  float fVar12;

  float fVar13;

  bool bVar14;

  float10 fVar15;

  undefined4 uVar16;

  undefined4 uVar17;

  undefined4 uVar18;

  float fStack_60;

  int *piStack_5c;

  float fStack_58;

  int iStack_54;

  int iStack_50;

  float fStack_4c;

  float fStack_48;

  float fStack_44;

  float fStack_40;

  float fStack_3c;

  float fStack_38;

  float fStack_34;

  float fStack_30;

  float fStack_2c;

  undefined4 uStack_28;

  undefined4 uStack_24;

  undefined4 uStack_20;

  float fStack_1c;

  

  fVar5 = param_1;

  if (*(int *)((int)param_1 + 0x210) != 0) {

    return;

  }

  iVar11 = *(int *)((int)param_1 + 0x100);

  iStack_50 = iVar11;

  if (*(int *)((int)param_1 + 0x104) == 0) {

    *(int *)((int)param_1 + 0x104) = iVar11;

    PhysicsExZeroForce(param_1);

    *(undefined4 *)(*(int *)((int)fVar5 + 0x104) + 0xc) = *(undefined4 *)(DAT_00632ed8 + 0x8d0);

    *(undefined4 *)(*(int *)((int)fVar5 + 0x104) + 0x10) = *(undefined4 *)(DAT_00632ed8 + 0x8d4);

    *(undefined4 *)(*(int *)((int)fVar5 + 0x104) + 4) = *(undefined4 *)(DAT_00632ed8 + 0x8c8);

    *(undefined4 *)(*(int *)((int)fVar5 + 0x104) + 8) = *(undefined4 *)(DAT_00632ed8 + 0x8cc);

    *(undefined4 *)(*(int *)((int)fVar5 + 0x104) + 0x34) = *(undefined4 *)(DAT_00632ed8 + 0x8c0);

    *(undefined4 *)(*(int *)((int)fVar5 + 0x104) + 0x38) = *(undefined4 *)(DAT_00632ed8 + 0x8c4);

    *(undefined4 *)(*(int *)((int)fVar5 + 0x104) + 0x28) = *(undefined4 *)(DAT_00632ed8 + 0xd98);

    *(undefined4 *)(*(int *)((int)fVar5 + 0x104) + 0x30) = *(undefined4 *)(DAT_00632ed8 + 0xda4);

    *(undefined4 *)(iVar11 + 0x54) = *(undefined4 *)(DAT_00632ed8 + 0xf20);

    *(undefined4 *)(iVar11 + 0x50) = *(undefined4 *)((int)fVar5 + 0x1a8);

    if (*(int *)((int)fVar5 + 0x274) == 0) {

      *(undefined4 *)((int)fVar5 + 0x18c) = 0;

    }

  }

  fVar10 = fVar5;

  if (*(float *)((int)fVar5 + 0x274) != 0.0) {

    fVar10 = *(float *)((int)fVar5 + 0x274);

  }

  iVar6 = fx_create(fVar10);

  if (iVar6 == 0) {

    rpboat_ghost_logic__FP6OBJECT(fVar5);

    return;

  }

  puVar1 = (undefined4 *)((int)fVar5 + 0x208);

  *puVar1 = 0;

  *(undefined4 *)((int)fVar5 + 0x20c) = 0;

  if ((*(int *)((int)fVar5 + 0x274) == 0) || (*(int *)((int)fVar5 + 0xfc) != 0)) {

    uVar8 = *(uint *)((int)fVar5 + 0xe0) & 0xfffffffb;

  }

  else {

    if ((*(uint *)((int)fVar5 + 0xe0) & 2) == 0) {

      if ((((*(uint *)(*(int *)((int)fVar5 + 0x274) + 0x20c) & 0x20000) != 0) &&

          (*(int *)(iVar11 + 0x74) != 0)) && ((*(uint *)((int)fVar5 + 0xe0) & 1) == 0)) {

        *(int *)(iVar11 + 0x74) = *(int *)(iVar11 + 0x74) + -1;

        uVar17 = *(undefined4 *)(DAT_00632ed8 + 0xddc);

        *(uint *)((int)fVar5 + 0xe0) = *(uint *)((int)fVar5 + 0xe0) | 1;

        *(undefined4 *)((int)fVar5 + 0xec) = uVar17;

        sound_play_2(0x6d4,*(undefined4 *)((int)fVar5 + 0x274));

        uStack_20 = 1;

        fStack_1c = fVar5;

        fx_get_free_effect__Fv();

      }

    }

    else {

      fVar15 = (float10)FUN_00518b70(fVar5,0);

      fVar15 = (float10)*(float *)((int)fVar5 + 0xec) - fVar15;

      *(float *)((int)fVar5 + 0xec) = (float)fVar15;

      if (fVar15 < (float10)0.0 != (fVar15 == (float10)0.0)) {

        *(uint *)((int)fVar5 + 0xe0) = *(uint *)((int)fVar5 + 0xe0) & 0xfffffffd;

      }

    }

    if (((**(byte **)((int)fVar5 + 0x104) & 0x68) != 0) &&

       ((*(uint *)(*(int *)((int)fVar5 + 0x274) + 0x20c) & 0x40000) != 0)) {

      *(undefined1 *)((int)fVar5 + 0x20a) = 0x20;

    }

    iVar6 = *(int *)((int)fVar5 + 0x274);

    if ((*(uint *)(iVar6 + 0x20c) & 0x80000) == 0) {

      if ((*(uint *)(iVar6 + 0x20c) & 0x100000) == 0) {

        if (*(char *)(iVar6 + 0x208) != '\0') {

          *(undefined4 *)((int)fVar5 + 0x1a8) = *(undefined4 *)(DAT_00632ed8 + 0xdf0);

          *(undefined1 *)puVar1 = *(undefined1 *)(iVar6 + 0x208);

        }

      }

      else {

        uVar17 = *(undefined4 *)(DAT_00632ed8 + 0xdf4);

        *(undefined1 *)puVar1 = 0xe0;

        *(undefined4 *)((int)fVar5 + 0x1a8) = uVar17;

      }

    }

    else {

      uVar17 = *(undefined4 *)(DAT_00632ed8 + 0xdf4);

      *(undefined1 *)puVar1 = 0x20;

      *(undefined4 *)((int)fVar5 + 0x1a8) = uVar17;

    }

    *(undefined1 *)((int)fVar5 + 0x209) = *(undefined1 *)(iVar6 + 0x209);

    if ((*(uint *)(iVar6 + 0x20c) & 0x10000) == 0) {

      uVar8 = *(uint *)((int)fVar5 + 0xe0) & 0xfffffffb;

    }

    else {

      uVar8 = *(uint *)((int)fVar5 + 0xe0) | 4;

    }

    *(uint *)((int)fVar5 + 0xe0) = uVar8;

    if ((*(byte *)(iVar6 + 0x20c) & 0xc0) == 0) {

      uVar8 = *(uint *)((int)fVar5 + 0xe0) & 0xfffff7ff;

    }

    else {

      uVar8 = *(uint *)((int)fVar5 + 0xe0) | 0x800;

    }

  }

  *(uint *)((int)fVar5 + 0xe0) = uVar8;

  if (**(char **)((int)fVar5 + 0x104) < '\0') {

    *(undefined4 *)((int)fVar5 + 0x1a8) = *(undefined4 *)(iVar11 + 0x50);

  }

  else {

    *(undefined4 *)((int)fVar5 + 0x1a8) = *(undefined4 *)(iVar11 + 0x54);

  }

  *(uint *)((int)fVar5 + 0xd8) = *(uint *)((int)fVar5 + 0xd8) | 0x40;

  obj_alpha_fade_update(fVar5);

  player_pitch_update(fVar5);

  if (40.0 < *(float *)((int)fVar5 + 0xd4)) {

    *(undefined4 *)((int)fVar5 + 0xd4) = 0x42200000;

  }

  if ((**(byte **)((int)fVar5 + 0x104) & 0x40) != 0) {

    param_1 = *(float *)(*(byte **)((int)fVar5 + 0x104) + 0x24);

    pfVar7 = (float *)((int)fVar5 + 0x130);

    pfVar2 = (float *)((int)fVar5 + 300);

    pfVar3 = (float *)((int)fVar5 + 0x128);

    normalize__FPfN20(pfVar3,pfVar2,pfVar7);

    fVar10 = (1.0 - (ABS(*(float *)((int)fVar5 + 0x114)) / *(float *)((int)fVar5 + 0x1a8)) *

                    *(float *)(DAT_00632ed8 + 0xf38)) * param_1;

    *pfVar3 = fVar10 * *pfVar3;

    *pfVar2 = fVar10 * *pfVar2;

    *pfVar7 = fVar10 * *pfVar7;

    *(float *)(*(int *)((int)fVar5 + 0x104) + 0x24) = fVar10;

  }

  obj_vel_reset(fVar5);

  obj_speed_sq_calc(fVar5);

  PhysicsExApplyLocation(fVar5);

  PhysicsExCalcControledModelSpeeds(fVar5,0,*(undefined4 *)(DAT_00632ed8 + 0x8bc));

  obj_gravity_apply(fVar5,1);

  if (*(char *)((int)fVar5 + 0x20a) == '\0') {

    if ((**(uint **)((int)fVar5 + 0x104) & 0x28) == 0) {

      uVar17 = 0;

      if ((**(uint **)((int)fVar5 + 0x104) & 0x40) == 0) {

        uVar18 = *(undefined4 *)(DAT_00632ed8 + 0xd9c);

        uVar16 = 0;

      }

      else {

        uVar18 = *(undefined4 *)(DAT_00632ed8 + 0xd8c);

        uVar16 = 0;

      }

    }

    else {

      uVar17 = *(undefined4 *)(DAT_00632ed8 + 0xdb4);

      uVar18 = *(undefined4 *)(DAT_00632ed8 + 0x8b8);

      uVar16 = 0;

    }

  }

  else if ((*(byte *)((int)fVar5 + 0xe0) & 1) == 0) {

    if ((**(byte **)((int)fVar5 + 0x104) & 0x28) == 0) {

      uVar17 = *(undefined4 *)(DAT_00632ed8 + 0x1084);

      uVar18 = *(undefined4 *)(DAT_00632ed8 + 0x8b4);

      uVar16 = *(undefined4 *)(DAT_00632ed8 + 0x8b0);

    }

    else {

      uVar17 = *(undefined4 *)(DAT_00632ed8 + 0x1594);

      uVar18 = *(undefined4 *)(DAT_00632ed8 + 0x129c);

      uVar16 = *(undefined4 *)(DAT_00632ed8 + 0x1298);

    }

  }

  else if ((**(byte **)((int)fVar5 + 0x104) & 0x28) == 0) {

    uVar18 = *(undefined4 *)(DAT_00632ed8 + 0xdc4);

    uVar17 = 0;

    uVar16 = *(undefined4 *)(DAT_00632ed8 + 0xdc8);

  }

  else {

    uVar17 = *(undefined4 *)(DAT_00632ed8 + 0xdbc);

    uVar18 = *(undefined4 *)(DAT_00632ed8 + 0xdb8);

    uVar16 = *(undefined4 *)(DAT_00632ed8 + 0xdc0);

  }

  obj_bone_update(fVar5,uVar16,0,uVar18,uVar17,1);

  if ((*(byte *)((int)fVar5 + 0xe0) & 1) != 0) {

    fVar15 = (float10)FUN_00518b70(fVar5,0);

    fVar15 = (float10)*(float *)((int)fVar5 + 0xec) - fVar15;

    *(float *)((int)fVar5 + 0xec) = (float)fVar15;

    if (fVar15 < (float10)0.0 != (fVar15 == (float10)0.0)) {

      *(undefined4 *)((int)fVar5 + 0xec) = *(undefined4 *)(DAT_00632ed8 + 0xde0);

      *(uint *)((int)fVar5 + 0xe0) = *(uint *)((int)fVar5 + 0xe0) & 0xfffffffe | 2;

    }

  }

  iVar11 = *(int *)((int)fVar5 + 0x274);

  fVar10 = param_1;

  fVar12 = param_1;

  fVar13 = param_1;

  if (iVar11 != 0) {

    fStack_60 = *(float *)(iVar11 + 0x10);

    piStack_5c = (int *)0x3e2aaaab;

    fVar10 = (float)(*(uint *)(iVar11 + 0x30) & 2);

    fVar12 = 1.4013e-45;

    fVar13 = -NAN;

  }

  uVar8 = *(uint *)((int)fVar5 + 0xe0);

  iStack_54 = *(int *)((int)fVar5 + 0x10);

  uVar9 = *(uint *)((int)fVar5 + 0x30) & 2;

  param_1 = 1.4013e-45;

  if ((uVar8 & 0x40) == 0) {

    if ((uVar8 & 0x200) == 0) {

      if ((uVar8 & 0x100) == 0) {

        if (-1 < (char)uVar8) {

          if ((uVar8 & 0x400) == 0) {

code_r0x004d65ab:

            if (fVar13 == -NAN) goto code_r0x004d65b4;

          }

          else if (fStack_60 == 2.10195e-43) {

            fVar13 = fStack_60;

            if (fVar10 == 0.0) goto code_r0x004d65ab;

            fVar13 = 2.11596e-43;

          }

          else {

            fVar13 = fStack_60;

            if (fStack_60 == 2.11596e-43) goto code_r0x004d65ab;

            fVar13 = 2.10195e-43;

            fVar12 = 0.0;

          }

          goto code_r0x004d6699;

        }

        if ((iStack_54 == 0x2b) && (uVar9 != 0)) {

          *(uint *)((int)fVar5 + 0xe0) = uVar8 & 0xffffff7f;

          goto code_r0x004d65b4;

        }

        fVar12 = 0.0;

        param_1 = 0.0;

        fVar13 = 2.08793e-43;

        iVar11 = 0x2b;

      }

      else {

        if ((iStack_54 == 0x2a) && (uVar9 != 0)) {

          *(uint *)((int)fVar5 + 0xe0) = uVar8 & 0xfffffeff;

          goto code_r0x004d65b4;

        }

        fVar12 = 0.0;

        param_1 = 0.0;

        fVar13 = 2.07392e-43;

        iVar11 = 0x2a;

      }

    }

    else {

      if ((iStack_54 == 0x29) && (uVar9 != 0)) {

        *(uint *)((int)fVar5 + 0xe0) = uVar8 & 0xfffffdff;

        goto code_r0x004d65b4;

      }

      fVar12 = 0.0;

      param_1 = 0.0;

      fVar13 = 2.05991e-43;

      iVar11 = 0x29;

    }

  }

  else {

    *(uint *)((int)fVar5 + 0xe0) = uVar8 & 0xffffffbf;

code_r0x004d65b4:

    if (-10.0 <= *(float *)(*(int *)((int)fVar5 + 0x100) + 0x4c)) {

      if (10.0 < *(float *)(*(int *)((int)fVar5 + 0x100) + 0x4c)) {

        if (fStack_60 == 2.158e-43) {

          fVar13 = fStack_60;

          if (fVar10 != 0.0) {

            fVar13 = 2.17201e-43;

          }

        }

        else {

          fVar13 = fStack_60;

          if (fStack_60 != 2.17201e-43) {

            fVar12 = 0.0;

            fVar13 = 2.158e-43;

          }

        }

        bVar14 = (**(byte **)((int)fVar5 + 0x104) & 0x40) == 0;

        goto code_r0x004d6640;

      }

      piStack_5c = (int *)0x3e2aaaab;

      fVar13 = 2.03188e-43;

      if ((**(byte **)((int)fVar5 + 0x104) & 0x40) != 0) {

        fVar10 = fVar5;

        if (*(float *)((int)fVar5 + 0x274) != 0.0) {

          fVar10 = *(float *)((int)fVar5 + 0x274);

        }

        sound_stop_obj(0x62e,fVar10);

      }

    }

    else {

      if (fStack_60 == 2.12997e-43) {

        fVar13 = fStack_60;

        if (fVar10 != 0.0) {

          fVar13 = 2.14399e-43;

          bVar14 = (**(byte **)((int)fVar5 + 0x104) & 0x40) == 0;

          goto code_r0x004d6640;

        }

      }

      else {

        fVar13 = fStack_60;

        if (fStack_60 != 2.14399e-43) {

          fVar12 = 0.0;

          fVar13 = 2.12997e-43;

        }

      }

      bVar14 = (**(byte **)((int)fVar5 + 0x104) & 0x40) == 0;

code_r0x004d6640:

      if (!bVar14) {

        if (*(int *)((int)fVar5 + 0x274) == 0) {

          sound_play_obj(0x62e,fVar5);

        }

        else {

          sound_play_2(0x62e,*(int *)((int)fVar5 + 0x274));

        }

      }

    }

code_r0x004d6699:

    iVar11 = 1;

  }

  iVar6 = *(int *)((int)fVar5 + 0x274);

  if ((iVar6 != 0) && (fStack_60 != fVar13)) {

    if (fVar12 == 0.0) {

      uVar17 = 0x20;

    }

    else {

      uVar17 = 0x21;

    }

    ObjectSetAnim(iVar6,fVar13,uVar17,0,*(float *)(iVar6 + 0xc4) * 0.0,piStack_5c);

  }

  if (iStack_54 != iVar11) {

    if (param_1 == 0.0) {

      uVar17 = 0x20;

    }

    else {

      uVar17 = 0x21;

    }

    ObjectSetAnim(fVar5,iVar11,uVar17,0,*(float *)((int)fVar5 + 0xc4) * 0.0,0x3e2aaaab);

  }

  fVar15 = (float10)FUN_00518b70(fVar5,0);

  object_animate_process(fVar5,(float)fVar15);

  iVar11 = *(int *)((int)fVar5 + 0x100);

  if ((*(uint *)((int)fVar5 + 0xe0) & 0x800) != 0) {

    *(uint *)(iVar11 + 0x78) = (uint)(*(int *)(iVar11 + 0x78) == 0);

    *(undefined4 *)((int)fVar5 + 0xf0) = *(undefined4 *)(DAT_00632ed8 + 0xdec);

    if (*(int *)(iVar11 + 0x5c) != 0) {

      puVar4 = (uint *)(*(int *)(iVar11 + 0x5c) + 0xd8);

      *puVar4 = *puVar4 | 0x40000000;

    }

    sound_stop_obj(0x36c,*(undefined4 *)((int)fVar5 + 0x274));

  }

  if (*(int *)(iVar11 + 0x78) == 0) {

    iVar6 = *(int *)(iVar11 + 0x70);

  }

  else {

    iVar6 = *(int *)(iVar11 + 0x6c);

  }

  if (iVar6 == 0) {

    *(uint *)((int)fVar5 + 0xe0) = *(uint *)((int)fVar5 + 0xe0) & 0xfffffffb;

  }

  fVar15 = (float10)FUN_00518b70(fVar5,0);

  fVar15 = (float10)*(float *)(iVar11 + 0x7c) - fVar15;

  *(float *)(iVar11 + 0x7c) = (float)fVar15;

  if ((*(byte *)((int)fVar5 + 0xe0) & 4) == 0) {

    uVar17 = *(undefined4 *)(DAT_00632ed8 + 0xdec);

    *(undefined4 *)((int)fVar5 + 0xf4) = 0;

    *(undefined4 *)((int)fVar5 + 0xf0) = uVar17;

    if (*(int *)(iVar11 + 0x5c) != 0) {

      puVar4 = (uint *)(*(int *)(iVar11 + 0x5c) + 0xd8);

      *puVar4 = *puVar4 | 0x40000000;

    }

    if (*(int *)(iVar11 + 0x58) != 0) {

      if (*(int *)(iVar11 + 0x78) != 0) {

        reaper_spell_sound_2(fVar5,*(int *)(iVar11 + 0x58),0xffffffff);

        *(int *)(iVar11 + 0x6c) = *(int *)(iVar11 + 0x6c) + -1;

      }

      *(undefined4 *)(iVar11 + 0x58) = 0;

    }

  }

  else if (*(int *)(iVar11 + 0x78) == 0) {

    if (fVar15 < (float10)0.0) {

      XFGetViewportExt(&fStack_58,&iStack_54,&param_1,&fStack_4c);

      pfVar7 = (float *)XFGetCameraAxis(2);

      fStack_40 = *pfVar7;

      fStack_3c = pfVar7[1];

      fStack_38 = pfVar7[2];

      fStack_34 = fStack_40 * 1000.0 + fStack_4c;

      fStack_30 = fStack_3c * 1000.0 + fStack_48;

      fStack_2c = fStack_38 * 1000.0 + fStack_44;

      reaper_spell_sound_1(fVar5,&fStack_34,0xffffffff);

      *(int *)(iVar11 + 0x70) = *(int *)(iVar11 + 0x70) + -1;

      *(undefined4 *)(iVar11 + 0x7c) = *(undefined4 *)(DAT_00632ed8 + 0xdec);

    }

  }

  else {

    iVar6 = *(int *)(iVar11 + 0x58);

    if (iVar6 == 0) {

      fStack_58 = *(float *)(DAT_00632ed8 + 0xde8);

      piStack_5c = DAT_00632d6c;

      iStack_54 = 0;

      if (DAT_00632d6c != (int *)0x0) {

        do {

          iVar6 = piStack_5c[3];

          if (((((*(uint *)(iVar6 + 0xd8) & 0x4000c000) == 0) &&

               (*(float *)(iVar6 + 0x278) < *(float *)(iVar6 + 0x1c0))) &&

              (*(char *)(iVar6 + 0x1f5) == '\0')) &&

             (*(int *)(iVar6 + 0x18c) != *(int *)(DAT_00632a88 + 0x18c))) {

            param_1 = *(float *)(DAT_00632ed8 + 0xdf8);

            fVar15 = (float10)distancesq2d__FP3P3DT0(iVar6 + 0xa0,(float *)((int)fVar5 + 0xa0));

            if (fVar15 < (float10)param_1 * (float10)param_1) {

              param_1 = *(float *)(DAT_00632ed8 + 0xde8);

              fStack_40 = -*(float *)((int)fVar5 + 0x29c);

              fStack_3c = -*(float *)((int)fVar5 + 0x2ac);

              fStack_38 = -*(float *)((int)fVar5 + 700);

              normalize__FPfN20(&fStack_40,&fStack_3c,&fStack_38);

              fStack_4c = *(float *)(iVar6 + 0xa0) - *(float *)((int)fVar5 + 0xa0);

              fStack_48 = *(float *)(iVar6 + 0xa4) - *(float *)((int)fVar5 + 0xa4);

              fStack_44 = *(float *)(iVar6 + 0xa8) - *(float *)((int)fVar5 + 0xa8);

              normalize__FPfN20(&fStack_4c,&fStack_48,&fStack_44);

              Dot__FP3P3DT0(&fStack_40,&fStack_4c);

              fVar15 = (float10)crt_pow_special1();

              fStack_60 = (float)(fVar15 * (float10)57.339447);

              if ((fStack_60 < param_1 * 0.5) && (fStack_60 < fStack_58)) {

                fStack_58 = fStack_60;

                iStack_54 = iVar6;

              }

            }

          }

          iVar6 = iStack_54;

          piStack_5c = (int *)*piStack_5c;

        } while (piStack_5c != (int *)0x0);

        if (iStack_54 != 0) {

          sound_play_player(0x36c,*(undefined4 *)((int)fVar5 + 0x274));

          *(undefined4 *)((int)fVar5 + 0xf4) = 1;

          fVar15 = (float10)FUN_00518b70(fVar5,0);

          fVar15 = (float10)*(float *)((int)fVar5 + 0xf0) - fVar15;

          *(float *)((int)fVar5 + 0xf0) = (float)fVar15;

          if (fVar15 < (float10)0.0 != (fVar15 == (float10)0.0)) {

            *(int *)(iVar11 + 0x58) = iVar6;

          }

          if (*(int *)(iVar11 + 0x5c) == 0) {

            uVar17 = object_allocate_type(0x3d4,0);

            *(undefined4 *)(iVar11 + 0x5c) = uVar17;

          }

          puVar4 = (uint *)(*(int *)(iVar11 + 0x5c) + 0xd8);

          *puVar4 = *puVar4 & 0xbfffffff;

          puVar4 = (uint *)(*(int *)(iVar11 + 0x5c) + 0xd8);

          *puVar4 = *puVar4 | 0x10000;

          GEO_MatIdentity(*(int *)(iVar11 + 0x5c) + 0x294);

          goto code_r0x004d6b21;

        }

      }

      if (*(int *)(iVar11 + 0x5c) != 0) {

        puVar4 = (uint *)(*(int *)(iVar11 + 0x5c) + 0xd8);

        *puVar4 = *puVar4 | 0x40000000;

      }

      *(undefined4 *)((int)fVar5 + 0xf0) = *(undefined4 *)(DAT_00632ed8 + 0xdec);

      *(undefined4 *)((int)fVar5 + 0xf4) = 0;

      sound_stop_player(0x36c,*(undefined4 *)((int)fVar5 + 0x274));

    }

    else {

      param_1 = *(float *)(DAT_00632ed8 + 0xdf8);

      fVar15 = (float10)distancesq2d__FP3P3DT0(iVar6 + 0xa0,(int)fVar5 + 0xa0);

      if (((float10)param_1 * (float10)param_1 <= fVar15) ||

         (iVar6 = func_0x004d72d0(fVar5,iVar6,*(undefined4 *)(DAT_00632ed8 + 0xde8),&fStack_60),

         iVar6 == 0)) {

        *(undefined4 *)(iVar11 + 0x58) = 0;

        uVar17 = *(undefined4 *)(DAT_00632ed8 + 0xdec);

        *(undefined4 *)((int)fVar5 + 0xf4) = 0;

        *(undefined4 *)((int)fVar5 + 0xf0) = uVar17;

        if (*(int *)(iVar11 + 0x5c) != 0) {

          puVar4 = (uint *)(*(int *)(iVar11 + 0x5c) + 0xd8);

          *puVar4 = *puVar4 | 0x40000000;

        }

        sound_stop_player(0x36c,*(undefined4 *)((int)fVar5 + 0x274));

      }

      else {

        puVar4 = (uint *)(*(int *)(iVar11 + 0x5c) + 0xd8);

        *puVar4 = *puVar4 & 0xbfffffff;

        puVar4 = (uint *)(*(int *)(iVar11 + 0x5c) + 0xd8);

        *puVar4 = *puVar4 | 0x10000;

        GEO_MatIdentity(*(int *)(iVar11 + 0x5c) + 0x294);

        iVar6 = *(int *)(iVar11 + 0x58);

code_r0x004d6b21:

        SphereFitToObject(*(int *)(iVar11 + 0x5c) + 0x294,iVar6,0x40000000);

      }

    }

  }

  rpboat_tilt__FP6OBJECT(fVar5);

  iVar11 = *(int *)((int)fVar5 + 0x100);

  if ((**(byte **)((int)fVar5 + 0x104) & 0x28) == 0) {

    if (*(int *)(iVar11 + 0x88) != 0) {

      if (*(int *)((int)fVar5 + 0x274) != 0) {

        sound_stop_obj(0x627,*(int *)((int)fVar5 + 0x274));

      }

      sound_stop_obj(0x627,fVar5);

      *(undefined4 *)(iVar11 + 0x88) = 0;

    }

  }

  else {

    if (*(float *)(*(byte **)((int)fVar5 + 0x104) + 0x24) < *(float *)(DAT_00632ed8 + 0xda8)) {

      playerobj_lookud(fVar5,0,1,*(undefined4 *)(DAT_00632ed8 + 0xda0),0,0);

    }

    if (*(int *)(iVar11 + 0x8c) != 0) {

      if (*(int *)((int)fVar5 + 0x274) != 0) {

        sound_stop_obj(0x6fc,*(int *)((int)fVar5 + 0x274));

      }

      sound_stop_obj(0x6fc,fVar5);

      *(undefined4 *)(iVar11 + 0x8c) = 0;

    }

    if (*(int *)(iVar11 + 0x88) == 0) {

      if (*(int *)((int)fVar5 + 0x274) != 0) {

        sound_play_2(0x627,*(int *)((int)fVar5 + 0x274));

      }

      sound_play_obj(0x627,fVar5);

      *(undefined4 *)(iVar11 + 0x88) = 1;

    }

  }

  puVar4 = *(uint **)((int)fVar5 + 0x104);

  if ((*puVar4 & 0x14) == 0) {

    if ((*puVar4 & 0x40) == 0) goto code_r0x004d6e3a;

    if ((*(int *)(iVar11 + 0x8c) == 0) && (*(int *)(iVar11 + 0x84) != 0)) {

      if (*(int *)((int)fVar5 + 0x274) == 0) {

        sound_play_obj(0x6fc,fVar5);

      }

      else {

        sound_play_2(0x6fc,*(int *)((int)fVar5 + 0x274));

      }

      *(undefined4 *)(iVar11 + 0x8c) = 1;

    }

    if (*(float *)((int)fVar5 + 0x13c) < 0.0) {

      fVar10 = *(float *)((int)fVar5 + 0x130) - *(float *)((int)fVar5 + 0x13c);

      if (fVar10 < *(float *)(DAT_00632ed8 + 0xf24)) {

        if (fVar10 < *(float *)(DAT_00632ed8 + 0xf24)) {

          if (fVar10 < *(float *)(DAT_00632ed8 + 0xf2c)) goto code_r0x004d6e6e;

          *(uint *)((int)fVar5 + 0xe0) = *(uint *)((int)fVar5 + 0xe0) | 0x80;

          *(float *)((int)fVar5 + 0x128) =

               *(float *)(DAT_00632ed8 + 0x1184) * *(float *)((int)fVar5 + 0x128);

          *(float *)((int)fVar5 + 300) =

               *(float *)(DAT_00632ed8 + 0x1184) * *(float *)((int)fVar5 + 300);

          fVar10 = *(float *)(DAT_00632ed8 + 0x1184);

        }

        else {

          *(uint *)((int)fVar5 + 0xe0) = *(uint *)((int)fVar5 + 0xe0) | 0x100;

          *(float *)((int)fVar5 + 0x128) =

               *(float *)(DAT_00632ed8 + 0x1188) * *(float *)((int)fVar5 + 0x128);

          *(float *)((int)fVar5 + 300) =

               *(float *)(DAT_00632ed8 + 0x1188) * *(float *)((int)fVar5 + 300);

          fVar10 = *(float *)(DAT_00632ed8 + 0x1188);

        }

      }

      else {

        *(uint *)((int)fVar5 + 0xe0) = *(uint *)((int)fVar5 + 0xe0) | 0x200;

        *(float *)((int)fVar5 + 0x128) =

             *(float *)(DAT_00632ed8 + 0xbc4) * *(float *)((int)fVar5 + 0x128);

        *(float *)((int)fVar5 + 300) =

             *(float *)(DAT_00632ed8 + 0xbc4) * *(float *)((int)fVar5 + 300);

        fVar10 = *(float *)(DAT_00632ed8 + 0xbc4);

      }

      *(float *)((int)fVar5 + 0x130) = fVar10 * *(float *)((int)fVar5 + 0x130);

      if (*(int *)((int)fVar5 + 0x274) == 0) {

        sound_play_obj(0x6d2,fVar5);

      }

      else {

        sound_play_2(0x6d2,*(int *)((int)fVar5 + 0x274));

      }

    }

  }

  else {

    if ((*(float *)(DAT_00632ed8 + 0xdd0) < *(float *)((int)fVar5 + 0x14c)) &&

       (*(float *)(DAT_00632ed8 + 0xde4) < (float)puVar4[9])) {

      obj_damage_apply(0x1a,((float)puVar4[9] - *(float *)(DAT_00632ed8 + 0xde4)) *

                            *(float *)(DAT_00632ed8 + 0xdd8) + *(float *)(DAT_00632ed8 + 0xdd4),

                       fVar5,0,(int)fVar5 + 0xa0,0);

      *(uint *)((int)fVar5 + 0xe0) = *(uint *)((int)fVar5 + 0xe0) | 0x40;

      if (*(int *)((int)fVar5 + 0x274) != 0) {

        sound_play_2(0x628,*(int *)((int)fVar5 + 0x274));

      }

    }

    if ((*(float *)((int)fVar5 + 0x130) < 0.0) &&

       (fVar10 = *(float *)((int)fVar5 + 0x130) - *(float *)((int)fVar5 + 0x13c),

       *(float *)(DAT_00632ed8 + 0xdcc) <= fVar10)) {

      obj_damage_apply(0x1a,(fVar10 - *(float *)(DAT_00632ed8 + 0xdcc)) *

                            *(float *)(DAT_00632ed8 + 0xdb0) + *(float *)(DAT_00632ed8 + 0xdac),

                       fVar5,0,(int)fVar5 + 0xa0,0);

      *(uint *)((int)fVar5 + 0xe0) = *(uint *)((int)fVar5 + 0xe0) | 0x40;

      if (*(int *)((int)fVar5 + 0x274) != 0) {

        sound_play_2(0x628,*(int *)((int)fVar5 + 0x274));

      }

    }

code_r0x004d6e3a:

    if (*(int *)(iVar11 + 0x8c) != 0) {

      if (*(int *)((int)fVar5 + 0x274) != 0) {

        sound_stop_obj(0x6fc,*(int *)((int)fVar5 + 0x274));

      }

      sound_stop_obj(0x6fc,fVar5);

      *(undefined4 *)(iVar11 + 0x8c) = 0;

    }

  }

code_r0x004d6e6e:

  iVar11 = iStack_50;

  if (**(char **)((int)fVar5 + 0x104) < '\0') {

    uVar8 = *(uint *)((int)fVar5 + 0xe0) & 0xfffffbff;

code_r0x004d706e:

    *(uint *)((int)fVar5 + 0xe0) = uVar8;

  }

  else if (*(float *)((int)fVar5 + 0x130) < 0.0) {

    uVar8 = *(uint *)((int)fVar5 + 0xe0) | 0x400;

    goto code_r0x004d706e;

  }

  drip_system_init(fVar5,iStack_50 + 0x3c,0);

  fVar10 = *(float *)((int)fVar5 + 0x274);

  if (*(float *)((int)fVar5 + 0x274) == 0.0) {

    fVar10 = fVar5;

  }

  iVar6 = comm_send_gate_check_2(fVar10);

  if (iVar6 == 0) {

    iVar6 = comm_send_gate_check(fVar10);

    if (iVar6 == 0) goto code_r0x004d7133;

    fStack_34 = *(float *)((int)fVar5 + 0x128);

    fStack_30 = *(float *)((int)fVar5 + 300);

    fStack_2c = *(float *)((int)fVar5 + 0x130);

    uVar18 = 2;

    uStack_28 = *(undefined4 *)((int)fVar5 + 200);

    uVar17 = 4;

  }

  else {

    fStack_34 = *(float *)((int)fVar5 + 0xa0);

    fStack_30 = *(float *)((int)fVar5 + 0xa4);

    fStack_2c = *(float *)((int)fVar5 + 0xa8);

    uStack_28 = *(undefined4 *)((int)fVar5 + 0x128);

    uStack_24 = *(undefined4 *)((int)fVar5 + 300);

    uStack_20 = *(undefined4 *)((int)fVar5 + 0x130);

    uVar18 = 1;

    fStack_1c = *(float *)((int)fVar5 + 200);

    uVar17 = 7;

  }

  comm_chat_send_2(fVar5,uVar17,0,0,uVar18,&fStack_34);

code_r0x004d7133:

  iVar6 = *(int *)((int)fVar5 + 0x274);

  if (iVar6 != 0) {

    if (*(float *)(*(byte **)((int)fVar5 + 0x104) + 0x24) <= 25.0) {

      if (*(int *)(iVar11 + 0x84) != 0) {

        sound_play_2(0x626,iVar6);

        sound_play_2(0x62c,*(undefined4 *)((int)fVar5 + 0x274));

        sound_stop_obj(0x629,*(undefined4 *)((int)fVar5 + 0x274));

        if (*(int *)(iVar11 + 0x8c) != 0) {

          if (*(int *)((int)fVar5 + 0x274) != 0) {

            sound_stop_obj(0x6fc,*(int *)((int)fVar5 + 0x274));

          }

          sound_stop_obj(0x6fc,fVar5);

          *(undefined4 *)(iVar11 + 0x8c) = 0;

        }

        *(undefined4 *)(iVar11 + 0x84) = 0;

      }

    }

    else {

      if (*(int *)(iVar11 + 0x84) == 0) {

        sound_stop_obj(0x626,iVar6);

        sound_play_2(0x629,*(undefined4 *)((int)fVar5 + 0x274));

        sound_play_2(0x62d,*(undefined4 *)((int)fVar5 + 0x274));

        fVar15 = (float10)rndfloatrange(0x40a00000,0x41200000);

        *(float *)(iVar11 + 0x80) = (float)fVar15;

        *(undefined4 *)(iVar11 + 0x84) = 1;

        return;

      }

      if ((**(byte **)((int)fVar5 + 0x104) & 0x40) != 0) {

        fVar15 = (float10)FUN_00518b70(fVar5,0);

        fVar15 = (float10)*(float *)(iVar11 + 0x80) - fVar15;

        *(float *)(iVar11 + 0x80) = (float)fVar15;

        if ((fVar15 < (float10)0.0 != (fVar15 == (float10)0.0)) &&

           (10.0 < *(float *)(*(int *)((int)fVar5 + 0x104) + 0x24))) {

          iVar6 = crt_rand_scaled(100);

          if (iVar6 < 0x32) {

            uVar17 = *(undefined4 *)((int)fVar5 + 0x274);

            uVar18 = 0x61d;

          }

          else {

            uVar17 = *(undefined4 *)((int)fVar5 + 0x274);

            uVar18 = 0x61e;

          }

          sound_play_2(uVar18,uVar17);

          fVar15 = (float10)rndfloatrange(0x40a00000,0x41200000);

          *(float *)(iVar11 + 0x80) = (float)fVar15;

          return;

        }

      }

    }

  }

  return;

}

/* ===== reaper_spell_sound_1 @ 0x004D73B0 ===== */
void reaper_spell_sound_1(int param_1,undefined4 *param_2,undefined4 param_3)



{

  int iVar1;

  int iVar2;

  int iVar3;

  float10 fVar4;

  float10 fVar5;

  undefined4 local_60;

  undefined4 local_5c;

  undefined4 local_58;

  undefined4 local_54;

  undefined4 local_50;

  undefined4 local_4c;

  undefined4 local_48;

  uint local_44 [4];

  undefined4 local_34;

  undefined4 local_24;

  undefined4 local_14;

  

  if (*(int *)(param_1 + 0x274) != 0) {

    playerobj_eval_refpt(param_1,2,&local_60);

    fVar4 = (float10)dirucalcp3d__FP3P3DT0(&local_60,param_2);

    fVar5 = (float10)dirfcalcp3d__FP3P3DT0(&local_60,param_2);

    local_44[0] = 0;

    GEO_MatBuildXYZ(local_44,-(float)fVar4,0,(float)fVar5);

    local_24 = local_5c;

    local_34 = local_60;

    local_44[0] = local_44[0] | 0x10;

    local_14 = local_58;

    iVar1 = PROJ_Create3(0x29,*(undefined4 *)(*(int *)(param_1 + 0x274) + 0x18c),param_1,0,local_44,

                         0);

    iVar3 = *(int *)(param_1 + 0x274);

    if (*(int *)(param_1 + 0x274) == 0) {

      iVar3 = param_1;

    }

    *(int *)(iVar1 + 0x274) = iVar3;

    iVar2 = fx_create(iVar3);

    if (iVar2 == 0) {

      *(undefined4 *)(iVar1 + 0x188) = param_3;

    }

    else {

      iVar3 = reaper_0052e4a0(iVar3);

      if (iVar3 != 0) {

        local_54 = *param_2;

        local_48 = *(undefined4 *)(iVar1 + 0x188);

        local_50 = param_2[1];

        local_4c = param_2[2];

        reaper_00530bd0(param_1,3,1,0,6,&local_54);

      }

    }

    sound_play_2(0x6cd,*(undefined4 *)(param_1 + 0x274));

  }

  return;

}

/* ===== reaper_spell_sound_2 @ 0x004D7500 ===== */
void reaper_spell_sound_2(int param_1,int param_2,undefined4 param_3)



{

  int iVar1;

  int iVar2;

  int iVar3;

  undefined4 uStack_58;

  undefined4 uStack_54;

  undefined4 uStack_50;

  undefined4 uStack_4c;

  undefined4 uStack_48;

  undefined1 local_44 [16];

  undefined4 uStack_34;

  undefined4 uStack_24;

  undefined4 uStack_14;

  

  if (*(int *)(param_1 + 0x274) != 0) {

    (*(code *)PTR_crt_matrix_mul_00580c18)

              (local_44,param_1 + 0x294,*(int *)(param_1 + 0x2dc) + 0x88);

    playerobj_eval_refpt(param_1,2,&uStack_50);

    uStack_34 = uStack_50;

    uStack_24 = uStack_4c;

    uStack_14 = uStack_48;

    iVar1 = PROJ_Create3(0x1f,*(undefined4 *)(*(int *)(param_1 + 0x274) + 0x18c),param_1,0,local_44,

                         param_2);

    iVar3 = *(int *)(param_1 + 0x274);

    if (*(int *)(param_1 + 0x274) == 0) {

      iVar3 = param_1;

    }

    *(int *)(iVar1 + 0x274) = iVar3;

    iVar2 = fx_create(iVar3);

    if (iVar2 == 0) {

      *(undefined4 *)(iVar1 + 0x188) = param_3;

    }

    else {

      iVar3 = reaper_0052e4a0(iVar3);

      if (iVar3 != 0) {

        uStack_58 = *(undefined4 *)(iVar1 + 0x188);

        uStack_54 = *(undefined4 *)(param_2 + 0x188);

        reaper_00530bd0(param_1,0,2,0,3,&uStack_58);

      }

    }

    sound_play_2(0x6cd,*(undefined4 *)(param_1 + 0x274));

  }

  return;

}

/* ===== cspec_004d7610 @ 0x004D7610 ===== */
undefined4 cspec_004d7610(void)



{

  return 0x90;

}

/* ===== reaper_death_cleanup_c90 @ 0x004D7620 ===== */
void reaper_death_cleanup_c90(undefined4 param_1,float param_2,int param_3,int param_4)



{

  uint *puVar1;

  int iVar2;

  int iVar3;

  

  iVar3 = *(int *)(param_3 + 0x100);

  if (((*(int *)(param_3 + 0x210) == 0) &&

      (((param_4 == 0 || (*(int *)(param_4 + 0x1e0) != 0x4d)) ||

       ((*(int *)(param_4 + 0x274) != param_3 &&

        (*(int *)(param_4 + 0x274) != *(int *)(param_3 + 0x274))))))) &&

     (param_2 = param_2 + *(float *)(param_3 + 0x278), *(float *)(param_3 + 0x278) = param_2,

     *(float *)(param_3 + 0x1c0) <= param_2)) {

    if (*(int *)(iVar3 + 0x88) != 0) {

      if (*(int *)(param_3 + 0x274) != 0) {

        sound_stop_obj(0x627,*(int *)(param_3 + 0x274));

      }

      sound_stop_obj(0x627,param_3);

      *(undefined4 *)(iVar3 + 0x88) = 0;

    }

    if (*(int *)(iVar3 + 0x8c) != 0) {

      if (*(int *)(param_3 + 0x274) != 0) {

        sound_stop_obj(0x6fc,*(int *)(param_3 + 0x274));

      }

      sound_stop_obj(0x6fc,param_3);

      *(undefined4 *)(iVar3 + 0x8c) = 0;

    }

    iVar3 = *(int *)(param_3 + 0x274);

    if (iVar3 != 0) {

      puVar1 = *(uint **)(iVar3 + 0x100);

      sound_stop_obj(0x62b,iVar3);

      sound_stop_obj(0x626,iVar3);

      sound_stop_obj(0x629,iVar3);

      sound_stop_obj(0x62e,iVar3);

      sound_stop_obj(0x6fc,iVar3);

      sound_stop_obj(0x6fc,param_3);

      sound_stop_obj(0x36c,iVar3);

      *(undefined4 *)(iVar3 + 0x210) = 0;

      *(undefined4 *)(param_3 + 0x274) = 0;

      camera_override_done();

      *(uint *)(iVar3 + 0xe0) = *(uint *)(iVar3 + 0xe0) | 2;

      iVar2 = gun_find_right(iVar3);

      if (iVar2 != 0) {

        *(uint *)(iVar2 + 0xd8) = *(uint *)(iVar2 + 0xd8) & 0xbfffffff;

      }

      *puVar1 = *puVar1 & 0xfffffffd;

      playerobj_eval_refpt(param_3,5,iVar3 + 0xa0);

      iVar3 = reaper_0052e4a0(iVar3);

      if (iVar3 != 0) {

        reaper_00530bd0(param_3,0,0,0,5,0);

      }

      *(undefined4 *)(param_3 + 0x18c) = 0;

      sound_play_obj(0x62a,param_3);

    }

    object_destroy(param_3);

  }

  return;

}

/* ===== charger_do_fx__FP6OBJECTiii @ 0x004D77E0 ===== */
/* PS2 candidate: charger_do_fx__FP6OBJECTiii (conf 0.418) */



void charger_do_fx__FP6OBJECTiii

               (int param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)



{

  uint *puVar1;

  int iVar2;

  undefined4 *puVar3;

  undefined4 uVar4;

  int iVar5;

  int iVar6;

  

  puVar3 = param_4;

  iVar2 = param_1;

  switch(param_2) {

  case 1:

    *(undefined4 *)(param_1 + 0xa0) = *param_4;

    *(undefined4 *)(param_1 + 0xa4) = param_4[1];

    *(undefined4 *)(param_1 + 0xa8) = param_4[2];

    *(undefined4 *)(param_1 + 0x128) = param_4[3];

    *(undefined4 *)(param_1 + 300) = param_4[4];

    *(undefined4 *)(param_1 + 0x130) = param_4[5];

    *(undefined4 *)(param_1 + 200) = param_4[6];

    return;

  case 2:

    *(undefined4 *)(param_1 + 0x128) = *param_4;

    *(undefined4 *)(param_1 + 300) = param_4[1];

    *(undefined4 *)(param_1 + 0x130) = param_4[2];

    *(undefined4 *)(param_1 + 200) = param_4[3];

    return;

  case 3:

    uVar4 = objanim_select_animloop(param_4[1]);

    reaper_spell_sound_2(param_1,uVar4,*puVar3);

    return;

  case 4:

    iVar6 = fx_create(param_1);

    if ((((iVar6 != 0) && (*(int *)(iVar2 + 0x274) == 0)) &&

        (iVar6 = objanim_select_animloop(*param_4), iVar6 != 0)) && (*(int *)(iVar6 + 0x210) == 0))

    {

      param_1 = *(undefined4 *)(iVar2 + 0x188);

      reaper_00530bd0(iVar6,0,1,0,0x23,&param_1);

      reaper_animselect(iVar6,0x23,4,&param_1);

    }

    break;

  case 5:

    iVar6 = *(int *)(param_1 + 0x274);

    puVar1 = *(uint **)(iVar6 + 0x100);

    sound_stop_obj(0x62b,iVar6);

    sound_stop_obj(0x626,iVar6);

    sound_stop_obj(0x629,iVar6);

    sound_stop_obj(0x62e,iVar6);

    sound_stop_obj(0x6fc,iVar6);

    sound_stop_obj(0x6fc,iVar2);

    sound_stop_obj(0x36c,iVar6);

    *(undefined4 *)(iVar6 + 0x210) = 0;

    *(undefined4 *)(iVar2 + 0x274) = 0;

    camera_override_done();

    *(uint *)(iVar6 + 0xe0) = *(uint *)(iVar6 + 0xe0) | 2;

    iVar5 = gun_find_right(iVar6);

    if (iVar5 != 0) {

      *(uint *)(iVar5 + 0xd8) = *(uint *)(iVar5 + 0xd8) & 0xbfffffff;

    }

    *puVar1 = *puVar1 & 0xfffffffd;

    playerobj_eval_refpt(iVar2,5,iVar6 + 0xa0);

    iVar6 = reaper_0052e4a0(iVar6);

    if (iVar6 != 0) {

      reaper_00530bd0(iVar2,0,0,0,5,0);

    }

    *(undefined4 *)(iVar2 + 0x18c) = 0;

    sound_play_obj(0x62a,iVar2);

    return;

  case 6:

    reaper_spell_sound_1(param_1,param_4,param_4[3]);

    return;

  }

  return;

}

/* ===== cspec_004d7a20 @ 0x004D7A20 ===== */
undefined4 cspec_004d7a20(int param_1,int param_2)



{

  int iVar1;

  int iVar2;

  undefined4 uVar3;

  

  if (param_2 == 0) {

    return 0;

  }

  iVar1 = crt_rand_scaled(100);

  iVar2 = *(int *)(param_1 + 0x274);

  if (iVar1 < 0x32) {

    if (iVar2 != 0) {

      sound_play_2(0x6c7,iVar2);

      goto code_r0x004d7a7c;

    }

    uVar3 = 0x6c7;

  }

  else {

    if (iVar2 != 0) {

      sound_play_2(0x6c8,iVar2);

      goto code_r0x004d7a7c;

    }

    uVar3 = 0x6c8;

  }

  sound_play_obj(uVar3,param_1);

code_r0x004d7a7c:

  if (*(int *)(param_2 + 0x18c) == *(int *)(param_1 + 0x18c)) {

    return 0;

  }

  if (*(float *)(*(int *)(param_1 + 0x104) + 0x24) <= *(float *)(DAT_00632ed8 + 0xf30)) {

    return 0;

  }

  iVar2 = func_0x0049a1a0(param_2);

  if (iVar2 == 0) {

    return 0;

  }

  iVar2 = FUN_004a6220(param_2);

  if (((iVar2 != 0) || (iVar2 = ObjIsReaperBldg(param_2), iVar2 != 0)) &&

     (iVar2 = ObjIsTurret(param_2), iVar2 == 0)) {

    return 0;

  }

  iVar2 = fx_create(param_1);

  if ((iVar2 != 0) && (*(int *)(param_1 + 0x274) != 0)) {

    iVar2 = dialog_level_is_base();

    if (iVar2 == 0) {

      obj_damage_apply(0x1d,*(undefined4 *)(DAT_00632ed8 + 0xf34),param_2,param_1,0,0);

      return 1;

    }

    obj_damage_apply(0x1d,0x42480000,param_2,param_1,0,0);

  }

  return 0;

}

/* ===== cspec_004d7b40 @ 0x004D7B40 ===== */
void cspec_004d7b40(void)



{

  obj_ptr_clear_if_dead();

  return;

}

/* ===== cspec_004d7b60 @ 0x004D7B60 ===== */
void cspec_004d7b60(int param_1)



{

  if (*(int *)(*(int *)(param_1 + 0x100) + 0x5c) != 0) {

    object_destroy();

    return;

  }

  return;

}

/* ===== target_hurt_class_check @ 0x004D7B80 ===== */
bool target_hurt_class_check(int param_1)



{

  if (*(float *)(param_1 + 0x278) < *(float *)(param_1 + 0x1c0)) {

    switch(*(undefined4 *)(param_1 + 0xe8)) {

    case 0:

    case 2:

    case 100:

    case 0x66:

    case 0x67:

      return *(int *)(param_1 + 0xe4) != 0xdd;

    case 1:

    case 9:

    case 0xe:

      return true;

    }

  }

  return false;

}

/* ===== kabutoai_is_punch_anim__FP6OBJECT_3 @ 0x004D7C40 ===== */
bool kabutoai_is_punch_anim__FP6OBJECT_3(int param_1)



{

  return *(int *)(param_1 + 0xe4) == 0x12d;

}

/* ===== FUN_004d7c60 @ 0x004D7C60 ===== */
/* PS2 candidate: rpman_sfcaught (conf 0.311) */



void FUN_004d7c60(int param_1,int param_2)



{

  int iVar1;

  int *piVar2;

  

  if (*(float *)(param_1 + 0x278) < *(float *)(param_1 + 0x1c0)) {

    iVar1 = *(int *)(param_1 + 0xe8);

    switch(iVar1) {

    case 0:

    case 2:

    case 100:

    case 0x66:

    case 0x67:

      if (*(int *)(param_1 + 0xe4) == 0xdd) {

        return;

      }

    case 1:

    case 9:

    case 0xe:

      piVar2 = *(int **)(param_1 + 0x100);

      if ((0x65 < iVar1) && (iVar1 < 0x68)) {

        if ((param_2 != 0) && (*(int *)(param_2 + 0x1e0) == 0x4d)) {

          *piVar2 = *(int *)(param_2 + 0x274);

        }

        piVar2[0x7a] = *(int *)(param_1 + 0xe4);

        if (((*(uint *)(param_1 + 0xe0) & 0x1000000) != 0) && (piVar2[0x83] == 0)) {

          DAT_005a8578 = 0;

          *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xfeffffff;

          iVar1 = *piVar2;

          if ((iVar1 != 0) && ((*(int *)(iVar1 + 0x1e0) == 0x12 && (*(int *)(iVar1 + 0xe8) == 10))))

          {

            *piVar2 = 0;

          }

        }

      }

      if (*(float *)(param_1 + 0x278) < *(float *)(param_1 + 0x1c0)) {

        rpman_notify_hit(param_1,param_2);

      }

      if ((*(int *)(param_1 + 0x10) != 0xaa) && (*(int *)(*(int *)(param_1 + 8) + 0x2b0) != 0)) {

        ObjectSetAnim(param_1,0xaa,0x20,0,*(float *)(param_1 + 0xc4) * 0.0,0x3e2aaaab);

      }

      *(undefined4 *)(param_1 + 0xe4) = 0x12d;

    }

  }

  return;

}

/* ===== ai_ospec12d_logic @ 0x004D7E10 ===== */
void ai_ospec12d_logic(int param_1)



{

  float fVar1;

  int iVar2;

  int iVar3;

  float10 fVar4;

  float10 fVar5;

  undefined4 uVar6;

  float local_8;

  float local_4;

  

  if (*(int *)(param_1 + 0xe4) != 0x12d) {

    return;

  }

  if (*(float *)(param_1 + 0x1c0) <= *(float *)(param_1 + 0x278)) {

    return;

  }

  iVar3 = *(int *)(param_1 + 0x100);

  switch(*(undefined4 *)(param_1 + 0xe8)) {

  case 0:

  case 2:

    if (*(int *)(iVar3 + 0x134) != 0) {

      *(uint *)(param_1 + 0xe4) = 0x22 - (uint)(*(int *)(iVar3 + 0xb0) != 0);

      return;

    }

  case 0xe:

    *(undefined4 *)(param_1 + 0xe4) = 10;

    return;

  case 1:

    *(undefined4 *)(param_1 + 0xe4) = 0x69;

  default:

    return;

  case 9:

    *(undefined4 *)(param_1 + 0xe4) = 0x78;

    return;

  case 100:

    fVar4 = (float10)rndfloatrange(0x40800000,0x40e00000);

    *(float *)(iVar3 + 0xd0) = (float)fVar4;

    *(undefined4 *)(iVar3 + 0x28) = *(undefined4 *)(param_1 + 0xa0);

    *(undefined4 *)(iVar3 + 0x2c) = *(undefined4 *)(param_1 + 0xa4);

    *(undefined4 *)(iVar3 + 0x30) = *(undefined4 *)(param_1 + 0xa8);

    if ((*(uint *)(param_1 + 0xe0) & 0x200) != 0) {

      ai_damage_response(param_1,1,0,0);

      *(undefined4 *)(param_1 + 0xe4) = 0x51;

      return;

    }

    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 0x8004000;

    iVar3 = crt_rand_scaled(100);

    if (iVar3 < 0x33) {

      *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 0x8000;

      if ((*(int *)(param_1 + 0x10) == 0x7f) || (*(int *)(*(int *)(param_1 + 8) + 0x204) == 0))

      goto LAB_004d7f5f;

      fVar1 = *(float *)(param_1 + 0xc4);

      uVar6 = 0x7f;

    }

    else {

      *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xffff7fff;

      if ((*(int *)(param_1 + 0x10) == 0x7e) || (*(int *)(*(int *)(param_1 + 8) + 0x200) == 0))

      goto LAB_004d7f5f;

      fVar1 = *(float *)(param_1 + 0xc4);

      uVar6 = 0x7e;

    }

    ObjectSetAnim(param_1,uVar6,0x21,0,fVar1 * 0.0,0x3e2aaaab);

LAB_004d7f5f:

    *(undefined4 *)(param_1 + 0xe4) = 0x51;

    return;

  case 0x66:

    if (((*(uint *)(param_1 + 0xe0) & 0x1000000) != 0) && (*(int *)(iVar3 + 0x20c) != 0)) {

      *(undefined4 *)(param_1 + 0xe4) = *(undefined4 *)(iVar3 + 0x1e8);

      return;

    }

    break;

  case 0x67:

    if (*(int *)(iVar3 + 0x1e4) != 0) {

      *(undefined4 *)(param_1 + 0xe4) = 0xea;

      return;

    }

    fVar4 = (float10)rndfloatrange(*(undefined4 *)(iVar3 + 0x1dc),*(undefined4 *)(iVar3 + 0x1e0));

    fVar5 = (float10)rndfloatrange(*(float *)(param_1 + 200) - 45.0,*(float *)(param_1 + 200) + 45.0

                                  );

    sine_cos_lookup((float)fVar5,&local_8,&local_4);

    iVar2 = *(int *)(iVar3 + 0x1ec);

    *(float *)(iVar3 + 8) = local_8 * (float)fVar4 + *(float *)(iVar2 + 0xa0);

    *(float *)(iVar3 + 0xc) = *(float *)(iVar2 + 0xa4) - local_4 * (float)fVar4;

    *(undefined4 *)(iVar3 + 0x10) = *(undefined4 *)(iVar2 + 0xa8);

    *(undefined4 *)(iVar3 + 0x14) = *(undefined4 *)(param_1 + 200);

    *(undefined4 *)(iVar3 + 0x134) = 0;

    *(undefined4 *)(param_1 + 0xe8) = 2;

  }

  *(undefined4 *)(param_1 + 0xe4) = 0xc;

  return;

}

/* ===== ai_accel_update @ 0x004D8150 ===== */
void ai_accel_update(int param_1,float param_2)



{

  float fVar1;

  int iVar2;

  float fVar3;

  char cVar4;

  float10 fVar5;

  float local_10;

  float local_c;

  float local_8;

  float local_4;

  

  iVar2 = *(int *)(param_1 + 0x100);

  fVar5 = (float10)FUN_00518b70(param_1,0);

  fVar1 = (float)fVar5;

  rpman_get_thrust__FP6OBJECTfPfT2(param_1,0x3f800000,&local_c,&local_10);

  fVar3 = local_c * fVar1 * 4.0 + *(float *)(param_1 + 0x108);

  local_8 = fVar1 * *(float *)(param_1 + 0x1b8);

  if (local_10 < fVar3 - local_8) {

    fVar3 = local_10;

  }

  fVar3 = ((fVar3 - local_8 * 4.0) + *(float *)(param_1 + 0x108)) * fVar1;

  local_4 = fVar3 + fVar3 + *(float *)(param_1 + 0xa8);

  rpman_get_thrust__FP6OBJECTfPfT2(param_1,0x3f000000,&local_c,&local_10);

  fVar3 = local_c * fVar1 * 4.0 + *(float *)(param_1 + 0x108);

  if (local_10 < fVar3) {

    fVar3 = local_10;

  }

  local_8 = fVar1 * *(float *)(param_1 + 0x1b8) * 4.0;

  fVar3 = ((fVar3 - local_8) + *(float *)(param_1 + 0x108)) * fVar1;

  local_10 = fVar3 + fVar3 + *(float *)(param_1 + 0xa8);

  fVar1 = ((*(float *)(param_1 + 0x108) - local_8) + *(float *)(param_1 + 0x108)) * fVar1;

  if (param_2 <= fVar1 + fVar1 + *(float *)(param_1 + 0xa8)) {

    *(undefined4 *)(iVar2 + 0x148) = 0;

    return;

  }

  if (param_2 <= local_10) {

    cVar4 = __ftol();

    *(float *)(iVar2 + 0x148) = (float)(int)cVar4;

    return;

  }

  if (param_2 <= local_4) {

    cVar4 = __ftol();

    *(float *)(iVar2 + 0x148) = (float)(int)cVar4;

    return;

  }

  *(undefined4 *)(iVar2 + 0x148) = 0x42000000;

  return;

}

/* ===== rpman_get_thrust__FP6OBJECTfPfT2 @ 0x004D8330 ===== */
/* PS2 candidate: rpman_get_thrust__FP6OBJECTfPfT2 (conf 0.898) */



void rpman_get_thrust__FP6OBJECTfPfT2(int param_1,float param_2,float *param_3,float *param_4)



{

  float fVar1;

  float fVar2;

  float fVar3;

  

  fVar1 = *(float *)(param_1 + 0x140);

  if (**(int **)(param_1 + 0x100) != 0) {

    fVar1 = *(float *)(**(int **)(param_1 + 0x100) + 0x140);

  }

  fVar1 = 1.0 - (*(float *)(param_1 + 0xa8) - fVar1) * (1.0 / *(float *)(DAT_00632ed8 + 0xd30));

  if (1.0 < fVar1) {

    fVar1 = 1.0;

  }

  fVar2 = 1.0 - (1.0 / *(float *)(param_1 + 0x194)) *

                (ABS(*(float *)(param_1 + 0x10c)) + ABS(*(float *)(param_1 + 0x110)));

  if (fVar2 < *(float *)(DAT_00632ed8 + 0xd38)) {

    fVar2 = *(float *)(DAT_00632ed8 + 0xd38);

  }

  fVar3 = *(float *)(DAT_00632ed8 + 0xd40);

  param_2 = ((*(float *)(DAT_00632ed8 + 0xd3c) - *(float *)(param_1 + 0x1b8)) * fVar1 +

            *(float *)(param_1 + 0x1b8)) * param_2;

  if (param_2 < 0.0) {

    param_2 = 0.0;

  }

  *param_3 = param_2;

  *param_4 = fVar3 * fVar2;

  return;

}

/* ===== endDisplay__Fv_2 @ 0x004D8420 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */



void endDisplay__Fv_2(void)



{

  _DAT_005a857c = 0;

  _DAT_005a8580 = 0x43700000;

  return;

}

/* ===== ai_damage_response @ 0x004D8440 ===== */
void ai_damage_response(int param_1,int param_2,int param_3,int param_4)



{

  uint uVar1;

  char cVar4;

  int iVar2;

  int iVar3;

  float10 fVar5;

  undefined4 uVar6;

  

  iVar3 = *(int *)(param_1 + 0x100);

  if ((param_2 == 0) || (param_3 == 0)) {

    uVar1 = *(uint *)(param_1 + 0xe0);

    *(uint *)(param_1 + 0xe0) = uVar1 & 0xf7ff7fff | 0x4000;

    if ((uVar1 & 0x200) != 0) {

      ai_anim_play(param_1,0x8d,1,0,0,param_4);

      return;

    }

    if ((uVar1 & 0x100) == 0) {

      iVar3 = crt_rand_scaled(100);

      if ((iVar3 < 100) && (*(int *)(param_1 + 0xe8) != 2)) {

        *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 0x8000;

        iVar3 = crt_rand_scaled(100);

        if (0x31 < iVar3) {

          ai_anim_play(param_1,0xa1,1,0,0,param_4);

          return;

        }

        ai_anim_play(param_1,0xa0,1,0,0,param_4);

        return;

      }

      iVar3 = crt_rand_scaled(100);

      if ((0x20 < iVar3) && (*(int *)(param_1 + 0xe8) != 2)) {

        if (0x42 < iVar3) {

          ai_anim_play(param_1,0x9f,1,0,0,param_4);

          return;

        }

        ai_anim_play(param_1,0x9e,1,0,0,param_4);

        return;

      }

      ai_anim_play(param_1,0x4a,1,0,0,param_4);

      return;

    }

    iVar3 = crt_rand_scaled(100);

    if ((iVar3 < 0x32) && (*(int *)(param_1 + 0xe8) != 2)) {

      *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 0x8000;

      iVar3 = crt_rand_scaled(100);

      if (0x31 < iVar3) {

        ai_anim_play(param_1,0x79,1,0,0,param_4);

        return;

      }

      ai_anim_play(param_1,0x78,1,0,0,param_4);

      return;

    }

    iVar3 = crt_rand_scaled(100);

    if (iVar3 < 0x19) {

      ai_anim_play(param_1,0x75,1,0,0,param_4);

      return;

    }

    if (0x31 < iVar3) {

      if (0x4a < iVar3) {

        ai_anim_play(param_1,0x9f,1,0,0,param_4);

        return;

      }

      ai_anim_play(param_1,0x9e,1,0,0,param_4);

      return;

    }

    ai_anim_play(param_1,0x76,1,0,0,param_4);

    return;

  }

  uVar1 = *(uint *)(param_1 + 0xe0);

  cVar4 = (char)(uVar1 >> 8);

  if ((uVar1 & 0x8000000) == 0) {

    if ((uVar1 & 0x200) != 0) {

      if ((uVar1 & 0x4000) == 0) {

        if ((*(int *)(param_1 + 0x10) != 0x8d) && (*(int *)(*(int *)(param_1 + 8) + 0x23c) != 0)) {

          ObjectSetAnim(param_1,0x8d,0x21,0,*(float *)(param_1 + 0xc4) * 0.0,0x3e2aaaab);

        }

      }

      else if ((*(int *)(param_1 + 0x10) != 0x8c) && (*(int *)(*(int *)(param_1 + 8) + 0x238) != 0))

      {

        ObjectSetAnim(param_1,0x8c,0x21,0,*(float *)(param_1 + 0xc4) * 0.0,0x3e2aaaab);

      }

      goto LAB_004d8a77;

    }

    if ((uVar1 & 0x100) == 0) {

      if ((uVar1 & 0x4000) != 0) {

        if (*(int *)(param_1 + 0xe8) == 2) {

          if ((*(int *)(param_1 + 0x10) != 0x2b) && (*(int *)(*(int *)(param_1 + 8) + 0xb4) != 0)) {

            ObjectSetAnim(param_1,0x2b,0x21,0,*(float *)(param_1 + 0xc4) * 0.0,0x3e2aaaab);

          }

          goto LAB_004d8a77;

        }

        if (-1 < cVar4) {

          if ((*(int *)(param_1 + 0x10) != 0x50) && (*(int *)(*(int *)(param_1 + 8) + 0x148) != 0))

          {

            ObjectSetAnim(param_1,0x50,0x21,0,*(float *)(param_1 + 0xc4) * 0.0,0x3e2aaaab);

          }

          goto LAB_004d8a77;

        }

        if (*(int *)(param_1 + 0x10) == 0x30) goto LAB_004d8a77;

        iVar2 = *(int *)(*(int *)(param_1 + 8) + 200);

        goto LAB_004d88df;

      }

      if (*(int *)(param_1 + 0xe8) == 2) {

        iVar2 = crt_rand_scaled(3);

        if (iVar2 == 0) {

          if ((*(int *)(param_1 + 0x10) != 0x4a) && (*(int *)(*(int *)(param_1 + 8) + 0x130) != 0))

          {

            ObjectSetAnim(param_1,0x4a,0x21,0,*(float *)(param_1 + 0xc4) * 0.0,0x3e2aaaab);

          }

        }

        else if (iVar2 == 1) {

          if ((*(int *)(param_1 + 0x10) != 0x4b) && (*(int *)(*(int *)(param_1 + 8) + 0x134) != 0))

          {

            ObjectSetAnim(param_1,0x4b,0x21,0,*(float *)(param_1 + 0xc4) * 0.0,0x3e2aaaab);

          }

        }

        else if ((*(int *)(param_1 + 0x10) != 0x4f) &&

                (*(int *)(*(int *)(param_1 + 8) + 0x144) != 0)) {

          ObjectSetAnim(param_1,0x4f,0x21,0,*(float *)(param_1 + 0xc4) * 0.0,0x3e2aaaab);

        }

        goto LAB_004d8a77;

      }

      if (cVar4 < '\0') {

        iVar2 = crt_rand_scaled(100);

        if (iVar2 < 0x32) {

          uVar6 = 0xa0;

        }

        else {

          uVar6 = 0xa1;

        }

      }

      else {

        iVar2 = crt_rand_scaled(100);

        if (iVar2 < 0x32) {

          uVar6 = 0x9e;

        }

        else {

          uVar6 = 0x9f;

        }

      }

      goto LAB_004d8a6e;

    }

    if ((uVar1 & 0x4000) == 0) {

      if (cVar4 < '\0') {

        iVar2 = crt_rand_scaled(100);

        if (iVar2 < 0x32) {

          if ((*(int *)(param_1 + 0x10) != 0x78) && (*(int *)(*(int *)(param_1 + 8) + 0x1e8) != 0))

          {

            ObjectSetAnim(param_1,0x78,0x21,0,*(float *)(param_1 + 0xc4) * 0.0,0x3e2aaaab);

          }

        }

        else if ((*(int *)(param_1 + 0x10) != 0x79) &&

                (*(int *)(*(int *)(param_1 + 8) + 0x1ec) != 0)) {

          ObjectSetAnim(param_1,0x79,0x21,0,*(float *)(param_1 + 0xc4) * 0.0,0x3e2aaaab);

        }

      }

      else {

        iVar2 = crt_rand_scaled(100);

        if (iVar2 < 0x19) {

          if ((*(int *)(param_1 + 0x10) != 0x75) && (*(int *)(*(int *)(param_1 + 8) + 0x1dc) != 0))

          {

            if (param_4 == 0) {

              uVar6 = 0x21;

            }

            else {

              fVar5 = (float10)rndfloatrange(0,0x3f800000);

              *(float *)(param_1 + 0x14) = (float)fVar5;

              uVar6 = 0x81;

            }

            ObjectSetAnim(param_1,0x75,uVar6,0,*(float *)(param_1 + 0xc4) * 0.0,0x3e2aaaab);

          }

        }

        else if (iVar2 < 0x32) {

          if ((*(int *)(param_1 + 0x10) != 0x76) && (*(int *)(*(int *)(param_1 + 8) + 0x1e0) != 0))

          {

            if (param_4 == 0) {

              uVar6 = 0x21;

            }

            else {

              fVar5 = (float10)rndfloatrange(0,0x3f800000);

              *(float *)(param_1 + 0x14) = (float)fVar5;

              uVar6 = 0x81;

            }

            ObjectSetAnim(param_1,0x76,uVar6,0,*(float *)(param_1 + 0xc4) * 0.0,0x3e2aaaab);

          }

        }

        else if (iVar2 < 0x4b) {

          if ((*(int *)(param_1 + 0x10) != 0x9e) && (*(int *)(*(int *)(param_1 + 8) + 0x280) != 0))

          {

            if (param_4 == 0) {

              uVar6 = 0x21;

            }

            else {

              fVar5 = (float10)rndfloatrange(0,0x3f800000);

              *(float *)(param_1 + 0x14) = (float)fVar5;

              uVar6 = 0x81;

            }

            ObjectSetAnim(param_1,0x9e,uVar6,0,*(float *)(param_1 + 0xc4) * 0.0,0x3e2aaaab);

          }

        }

        else if ((*(int *)(param_1 + 0x10) != 0x9f) &&

                (*(int *)(*(int *)(param_1 + 8) + 0x284) != 0)) {

          if (param_4 == 0) {

            uVar6 = 0x21;

          }

          else {

            fVar5 = (float10)rndfloatrange(0,0x3f800000);

            *(float *)(param_1 + 0x14) = (float)fVar5;

            uVar6 = 0x81;

          }

          ObjectSetAnim(param_1,0x9f,uVar6,0,*(float *)(param_1 + 0xc4) * 0.0,0x3e2aaaab);

        }

      }

      goto LAB_004d8a77;

    }

    if (cVar4 < '\0') {

      if ((*(int *)(param_1 + 0x10) != 0x77) && (*(int *)(*(int *)(param_1 + 8) + 0x1e4) != 0)) {

        ObjectSetAnim(param_1,0x77,0x21,0,*(float *)(param_1 + 0xc4) * 0.0,0x3e2aaaab);

      }

      goto LAB_004d8a77;

    }

    if (*(int *)(param_1 + 0x10) == 0x74) goto LAB_004d8a77;

    iVar2 = *(int *)(*(int *)(param_1 + 8) + 0x1d8);

  }

  else {

    if ((uVar1 & 0x4000) == 0) {

      if ((uVar1 & 0x200) != 0) {

        ai_damage_response(param_1,1);

        goto LAB_004d8a77;

      }

      *(uint *)(param_1 + 0xe0) = uVar1 | 0x8004000;

      if ((char)((uVar1 | 0x8004000) >> 8) < '\0') {

        uVar6 = 0x7f;

      }

      else {

        uVar6 = 0x7e;

      }

LAB_004d8a6e:

      ai_anim_play(param_1,uVar6,1,0,0,0);

      goto LAB_004d8a77;

    }

    if (cVar4 < '\0') {

      if (*(int *)(param_1 + 0x10) == 0x30) goto LAB_004d8a77;

      iVar2 = *(int *)(*(int *)(param_1 + 8) + 200);

LAB_004d88df:

      if (iVar2 != 0) {

        ObjectSetAnim(param_1,0x30,0x21,0,*(float *)(param_1 + 0xc4) * 0.0,0x3e2aaaab);

      }

      goto LAB_004d8a77;

    }

    if (*(int *)(param_1 + 0x10) == 0x74) goto LAB_004d8a77;

    iVar2 = *(int *)(*(int *)(param_1 + 8) + 0x1d8);

  }

  if (iVar2 != 0) {

    ObjectSetAnim(param_1,0x74,0x21,0,*(float *)(param_1 + 0xc4) * 0.0,0x3e2aaaab);

  }

LAB_004d8a77:

  if ((*(uint *)(param_1 + 0xe0) & 0x4000) == 0) {

    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 0x4000;

    return;

  }

  fVar5 = (float10)rndfloatrange(*(undefined4 *)(DAT_00632ed8 + 0xa1c),

                                 *(undefined4 *)(DAT_00632ed8 + 0xa54));

  *(float *)(iVar3 + 0x15c) = (float)fVar5;

  *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xffffbfff;

  return;

}

/* ===== ai_anim_play @ 0x004D8CE0 ===== */
void ai_anim_play(int param_1,int param_2,int param_3,undefined4 param_4,float param_5,int param_6)



{

  byte bVar1;

  float10 fVar2;

  

  if ((*(int *)(param_1 + 0x10) != param_2) &&

     (*(int *)(*(int *)(param_1 + 8) + 8 + param_2 * 4) != 0)) {

    if (param_6 == 0) {

      bVar1 = param_3 != 0 | 0x20;

    }

    else {

      fVar2 = (float10)rndfloatrange(0,0x3f800000);

      *(float *)(param_1 + 0x14) = (float)fVar2;

      bVar1 = param_3 != 0 | 0x80;

    }

    ObjectSetAnim(param_1,param_2,bVar1,param_4,param_5 * *(float *)(param_1 + 0xc4),0x3e2aaaab);

  }

  return;

}

/* ===== rpman_ai_main @ 0x004D8D60 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void rpman_ai_main(int *param_1)



{

  float fVar1;

  int *piVar2;

  undefined4 *puVar3;

  undefined1 uVar4;

  char cVar12;

  int iVar5;

  uint uVar6;

  int iVar7;

  int iVar8;

  int iVar9;

  int *piVar10;

  uint uVar11;

  float *pfVar13;

  undefined4 *puVar14;

  int *piVar15;

  bool bVar16;

  float10 fVar17;

  float10 fVar18;

  char *pcVar19;

  undefined4 uVar20;

  undefined1 *puVar21;

  char *pcVar22;

  undefined4 uVar23;

  float fVar24;

  undefined1 *puVar25;

  float fStack_1c8;

  int **ppiStack_1c4;

  int *piStack_1c0;

  int *apiStack_1bc [3];

  float fStack_1b0;

  undefined4 uStack_1ac;

  undefined4 uStack_1a8;

  float fStack_1a4;

  int iStack_1a0;

  int iStack_19c;

  float fStack_198;

  int iStack_194;

  int iStack_190;

  float fStack_18c;

  int iStack_188;

  int iStack_184;

  float fStack_180;

  float fStack_17c;

  float fStack_178;

  float fStack_174;

  float fStack_170;

  float fStack_16c;

  float fStack_168;

  float fStack_164;

  float fStack_160;

  float fStack_158;

  float fStack_154;

  float fStack_150;

  float fStack_148;

  float fStack_144;

  float fStack_140;

  float fStack_13c;

  float fStack_138;

  float fStack_134;

  float fStack_130;

  float fStack_12c;

  float fStack_128;

  float fStack_124;

  float fStack_120;

  float fStack_11c;

  float fStack_118;

  float fStack_114;

  undefined4 uStack_110;

  float fStack_10c;

  float fStack_108;

  undefined4 uStack_104;

  undefined4 uStack_100;

  undefined4 uStack_fc;

  undefined4 uStack_f8;

  undefined1 auStack_f4 [12];

  undefined1 auStack_e8 [12];

  undefined1 auStack_dc [12];

  undefined1 auStack_d0 [12];

  undefined1 auStack_c4 [12];

  undefined1 auStack_b8 [12];

  undefined1 auStack_ac [20];

  undefined4 uStack_98;

  int iStack_94;

  undefined1 auStack_78 [20];

  undefined4 uStack_64;

  int iStack_60;

  undefined1 auStack_44 [16];

  undefined4 uStack_34;

  undefined4 uStack_24;

  undefined4 uStack_14;

  

  piVar15 = (int *)param_1[0x40];

  if (DAT_00632e74 != 0) {

    return;

  }

  if (param_1[0x84] != 0) {

    iVar7 = *(int *)(param_1[0x84] + 0x1e0);

    if (iVar7 == 1) {

      return;

    }

    if (iVar7 == 0x4c) {

      return;

    }

  }

  if ((((param_1[0x41] == 0) && (iVar7 = param_1[0x3a], iVar7 != 7)) && (iVar7 != 10)) &&

     (iVar7 != 0xd)) {

    param_1[0x41] = (int)(piVar15 + 0x3e);

    PhysicsExZeroForce(param_1);

    *(undefined4 *)(param_1[0x41] + 4) = *(undefined4 *)(DAT_00632ed8 + 0xd48);

    *(undefined4 *)(param_1[0x41] + 8) = *(undefined4 *)(DAT_00632ed8 + 0xd4c);

    *(undefined4 *)(param_1[0x41] + 0x28) = *(undefined4 *)(DAT_00632ed8 + 0xd50);

    *(undefined4 *)(param_1[0x41] + 0xc) = *(undefined4 *)(DAT_00632ed8 + 0xd54);

    *(undefined4 *)(param_1[0x41] + 0x30) = *(undefined4 *)(DAT_00632ed8 + 0xd58);

    *(undefined4 *)(param_1[0x41] + 0x34) = *(undefined4 *)(DAT_00632ed8 + 0xd60);

    *(undefined4 *)(param_1[0x41] + 0x38) = *(undefined4 *)(DAT_00632ed8 + 0xd64);

    param_1[100] = *(int *)(DAT_00632ed8 + 0xd68);

    param_1[0x65] = *(int *)(DAT_00632ed8 + 0xd6c);

    param_1[0x68] = *(int *)(DAT_00632ed8 + 0xd70);

  }

  iVar7 = param_1[0x39];

  if (iVar7 == 0) {

    iVar7 = param_1[0x40];

    param_1[99] = 100;

    fVar24 = (float)param_1[0x6a];

    *(float *)(iVar7 + 0x1ac) = fVar24;

    *(float *)(iVar7 + 0x1b0) = fVar24 * 3.0;

    _DAT_005a84e8 = *(undefined4 *)(DAT_00632ed8 + 0x1004);

    uRam005a84ec = *(undefined4 *)(DAT_00632ed8 + 0x1008);

    uRam005a84f0 = *(undefined4 *)(DAT_00632ed8 + 0x100c);

    uRam005a84f4 = *(undefined4 *)(DAT_00632ed8 + 0x1010);

    uRam005a84f8 = *(undefined4 *)(DAT_00632ed8 + 0x1014);

    uRam005a84fc = *(undefined4 *)(DAT_00632ed8 + 0x1018);

    _DAT_005a8550 = *(undefined4 *)(DAT_00632ed8 + 0xfec);

    uRam005a8554 = *(undefined4 *)(DAT_00632ed8 + 0xff0);

    uRam005a8558 = *(undefined4 *)(DAT_00632ed8 + 0xff4);

    _DAT_005a855c = *(undefined4 *)(DAT_00632ed8 + 0xff8);

    uRam005a8560 = *(undefined4 *)(DAT_00632ed8 + 0xffc);

    uRam005a8564 = *(undefined4 *)(DAT_00632ed8 + 0x1000);

    if (param_1[0x3a] == 0x10) {

      *(undefined4 *)(iVar7 + 0x70) = 1;

      param_1[0x3a] = 0xe;

    }

    iVar5 = param_1[0x3a];

    if (iVar5 == 7) {

      if ((param_1[4] != 0x5d) && (*(int *)(param_1[2] + 0x17c) != 0)) {

        ObjectSetAnim(param_1,0x5d,0x21,0,(float)param_1[0x31] * 0.0,0x3e2aaaab);

      }

      param_1[0x39] = 0x136;

      return;

    }

    if (iVar5 == 10) {

      iVar5 = game_water_00513be0(0x28,0x28);

      *(int *)(iVar7 + 0x1b4) = iVar5;

      if (iVar5 != 0) {

        MAP_MemGroupSetBase(iVar5,param_1);

      }

      smartie_claim_targets(param_1);

      if (*(int *)(iVar7 + 0x134) == 0) {

        object_destroy(param_1);

        return;

      }

      iVar5 = object_allocate_type(0x487,0x80000000);

      *(int **)(iVar5 + 0x210) = param_1;

      *(undefined4 *)(iVar5 + 0x214) = 0;

      *(undefined4 *)(iVar5 + 0x218) = 2;

      ai_anim_play(param_1,0x9a,1,0,0,1);

      param_1[0x39] = 0x96;

      if ((param_1[0x36] & 0x400U) != 0) {

        *(uint *)(iVar5 + 0xd8) = *(uint *)(iVar5 + 0xd8) | 0x400;

      }

      puVar25 = auStack_ac;

      uVar23 = 4;

      pcVar22 = s_fx_rpm_jetski_exhaust_1_00561ac8;

      uStack_98 = 1;

      iStack_94 = iVar5;

      fx_get_free_effect__Fv();

      puVar21 = auStack_ac;

      uVar20 = 4;

      pcVar19 = s_fx_rpm_jetski_exhaust_2_00561ab0;

      uStack_98 = 2;

      fx_get_free_effect__Fv();

      fVar17 = (float10)rndfloatrange(0x41200000,0x41a00000,pcVar19,uVar20,puVar21,pcVar22,uVar23,

                                      puVar25);

      *(float *)(iVar7 + 0x23c) = (float)fVar17;

      sound_play_obj(0x621,param_1);

      return;

    }

    if (iVar5 == 0xd) {

      ai_anim_play(param_1,0xa5,1,0,0,0);

      param_1[0x72] = param_1[0x72] & 0xfffdffffU | 0xe00;

      param_1[0x36] = param_1[0x36] | 0x10;

      param_1[0x39] = 0xbe;

      return;

    }

    if (param_1[0x3f] == 0x40800000) {

      object_spawn_small(param_1,0x4b3,0,0xb,0);

      uVar6 = param_1[0x38] | 0x40000;

code_r0x004d9225:

      param_1[0x38] = uVar6;

    }

    else {

      if (param_1[0x3f] != 0x40400000) {

        if (param_1[0x3f] == 0x40000000) {

          uVar6 = param_1[0x38] | 0x200;

        }

        else if (param_1[0x3f] == 0x3f800000) {

          uVar6 = param_1[0x38] | 0x100;

        }

        else {

          uVar6 = param_1[0x38] | 0x80;

        }

        goto code_r0x004d9225;

      }

      param_1[0x38] = param_1[0x38] | 0x400;

      fVar17 = (float10)rndfloatrange(*(undefined4 *)(DAT_00632ed8 + 0xc28),

                                      *(undefined4 *)(DAT_00632ed8 + 0xc2c));

      *(float *)(iVar7 + 0xdc) = (float)fVar17;

      object_spawn_small(param_1,0x419,0,0xb,0);

      param_1[0x70] = *(int *)(DAT_00632ed8 + 0x1528);

    }

    rpman_setup_firing_parameters__FP6OBJECTi(param_1,0xffffffff);

    param_1[0x3f] = 0;

    fVar17 = (float10)get_floor_z_point(param_1 + 0x28);

    param_1[0x2a] = (int)(float)fVar17;

    object_copy_posdirinfo(param_1);

    if ((param_1[0x3a] != 0x65) && (param_1[0x3a] != 0x66)) {

      *(int *)(iVar7 + 8) = param_1[0x28];

      *(int *)(iVar7 + 0xc) = param_1[0x29];

      *(int *)(iVar7 + 0x10) = param_1[0x2a];

      *(int *)(iVar7 + 0x14) = param_1[0x32];

    }

    iVar5 = param_1[0x3a];

    if (iVar5 == 9) {

      object_spawn_small(param_1,0x2b5,0,0xb,0);

      param_1[0x39] = 0x78;

      return;

    }

    if (iVar5 == 0xb) {

      iVar5 = game_water_00513be0(0x28,0x28);

      *(int *)(iVar7 + 0x1b4) = iVar5;

      if (iVar5 != 0) {

        MAP_MemGroupSetBase(iVar5,param_1);

      }

      smartie_claim_targets(param_1);

      if (*(int *)(iVar7 + 0x134) == 0) {

        object_destroy(param_1);

        return;

      }

      iVar5 = object_allocate_type(0x487,0x80000000);

      *(int **)(iVar5 + 0x210) = param_1;

      *(undefined4 *)(iVar5 + 0x214) = 0;

      *(undefined4 *)(iVar5 + 0x218) = 2;

      ai_anim_play(param_1,0x9a,1,0,0,0);

      param_1[0x39] = 0xa0;

      *(undefined4 *)(iVar7 + 0x184) = 1;

      *(undefined4 *)(iVar7 + 0x198) = 1;

      *(undefined4 *)(iVar7 + 0x13c) = 0x3f800000;

      rpboat_logic__FP6OBJECT(param_1,0);

      if ((param_1[0x36] & 0x400U) != 0) {

        *(uint *)(iVar5 + 0xd8) = *(uint *)(iVar5 + 0xd8) | 0x400;

      }

      puVar25 = auStack_78;

      uVar23 = 4;

      pcVar22 = s_fx_rpm_jetski_exhaust_1_00561ac8;

      uStack_64 = 1;

      iStack_60 = iVar5;

      fx_get_free_effect__Fv();

      puVar21 = auStack_78;

      uVar20 = 4;

      pcVar19 = s_fx_rpm_jetski_exhaust_2_00561ab0;

      uStack_64 = 2;

      fx_get_free_effect__Fv();

      sound_play_obj(0x620,param_1,pcVar19,uVar20,puVar21,pcVar22,uVar23,puVar25);

      return;

    }

    if (iVar5 == 0xc) {

      iVar7 = object_spawn_small(param_1,0x2b5,0,0xb,0);

      *(int *)(iVar7 + 0xc4) = param_1[0x31];

      param_1[0x3b] = 0x40a00000;

      param_1[0x39] = 0xa2;

      return;

    }

    uVar6 = param_1[0x38];

    if ((uVar6 & 0x200) == 0) {

      if ((uVar6 & 0x100) != 0) {

        uVar20 = 0x417;

        goto code_r0x004d9478;

      }

      if ((uVar6 & 0x40000) == 0) {

        uVar20 = 0xf0;

        goto code_r0x004d9478;

      }

      object_spawn_small(param_1,0x2b5,0,0xb,0);

    }

    else {

      uVar20 = 0x418;

code_r0x004d9478:

      iVar5 = object_spawn_small(param_1,uVar20,0,0,0);

      if (iVar5 != 0) {

        param_1[0x9d] = iVar5;

        iVar8 = object_spawn_small(iVar5,0x26f,0xffffffff,2,0);

        *(int *)(iVar5 + 0x274) = iVar8;

        *(uint *)(iVar8 + 0xd8) = *(uint *)(iVar8 + 0xd8) | 0x40000000;

        iVar5 = object_spawn_small(iVar5,0x273,0xffffffff,2,0);

        *(int *)(iVar8 + 0x274) = iVar5;

        *(uint *)(iVar5 + 0xd8) = *(uint *)(iVar5 + 0xd8) | 0x40000000;

        fVar17 = (float10)rndfloatrange(0x41a00000,0x42c80000);

        *(float *)(iVar7 + 0x40) = (float)fVar17;

      }

    }

    switch(param_1[0x3a]) {

    case 0:

    case 0xe:

      smartie_claim_targets(param_1);

      if (*(int *)(iVar7 + 0x134) != 0) {

        ai_idle_anim_53(param_1,1);

        fVar17 = (float10)rndfloatrange(*(undefined4 *)(DAT_00632ed8 + 0xb44),

                                        *(undefined4 *)(DAT_00632ed8 + 0xb48));

        *(float *)(iVar7 + 0xb8) = (float)fVar17;

        param_1[0x39] = 0x1e;

        return;

      }

    case 2:

      param_1[0x39] = 10;

      return;

    case 1:

      *(undefined4 *)(iVar7 + 0xa4) = *(undefined4 *)(DAT_00632ed8 + 0x105c);

      *(undefined4 *)(iVar7 + 0xa8) = *(undefined4 *)(DAT_00632ed8 + 0x1060);

      param_1[0x37] = param_1[0x37] | 0x8000;

      param_1[0x39] = 100;

      return;

    case 4:

      if (*(int *)(iVar7 + 0x150) != 0) {

        param_1[0x39] = 0xad;

        return;

      }

    case 3:

    case 5:

    case 6:

      object_destroy(param_1);

      return;

    case 8:

      ai_anim_play(param_1,0x66,1,0,0,0);

      param_1[0x39] = 0x82;

      return;

    case 0xf:

      rpman_set_anim_flags(param_1);

      param_1[0x39] = 0xb4;

      return;

    case 100:

      smartie_claim_targets(param_1);

      if (*(int *)(iVar7 + 0x134) == 0) {

        object_destroy(param_1);

        return;

      }

      fVar17 = (float10)rndfloatrange(*(undefined4 *)(DAT_00632ed8 + 0xb44),

                                      *(undefined4 *)(DAT_00632ed8 + 0xb48));

      *(float *)(iVar7 + 0xb8) = (float)fVar17;

      param_1[0x39] = 0x1e;

      ai_idle_anim_53(param_1,1);

      return;

    case 0x65:

      param_1[0x72] = param_1[0x72] | 0xe00;

      param_1[0x36] = param_1[0x36] | 0x10;

      fVar17 = (float10)dirfcalcp3d__FP3P3DT0(param_1 + 0x28,iVar7 + 8);

      param_1[0x32] = (int)(float)fVar17;

      ai_move_force_goal(param_1,iVar7 + 8);

      rpman_sniper_anim_set(param_1);

      param_1[0x39] = 0x6e;

      return;

    case 0x66:

    case 0x67:

      param_1[0x72] = param_1[0x72] | 0xe00;

      param_1[0x36] = param_1[0x36] | 0x10;

      fVar17 = (float10)dirfcalcp3d__FP3P3DT0(param_1 + 0x28,iVar7 + 8);

      param_1[0x32] = (int)(float)fVar17;

      ai_move_force_goal(param_1,iVar7 + 8);

      rpman_sniper_anim_set(param_1);

      if (param_1[0x3a] == 0x67) {

        smartie_claim_targets(param_1);

        for (piVar15 = DAT_00632d68; piVar15 != (int *)0x0; piVar15 = (int *)*piVar15) {

          iVar5 = piVar15[3];

          if (((*(int *)(iVar5 + 4) == 0x48a) &&

              (*(int *)(iVar5 + 0xe8) == *(int *)(*(int *)(iVar7 + 0x134) + 0xe8))) &&

             ((*(int *)(iVar7 + 0x1ec) == 0 ||

              (*(int *)(*(int *)(iVar7 + 0x1ec) + 0x174) < *(int *)(iVar5 + 0x174))))) {

            *(int *)(iVar7 + 0x1ec) = iVar5;

          }

        }

        param_1[0x39] = 0xe6;

        return;

      }

      iVar5 = *(int *)(*(int *)(iVar7 + 0x134) + 0x100);

      for (piVar15 = DAT_00632d68; piVar15 != (int *)0x0; piVar15 = (int *)*piVar15) {

        iVar8 = piVar15[3];

        if (((*(int *)(iVar8 + 4) == 0x48a) &&

            (*(int *)(iVar8 + 0xe8) == *(int *)(*(int *)(iVar5 + 0x18) + 0xe8))) &&

           ((*(int *)(iVar7 + 0x1ec) == 0 ||

            (*(int *)(*(int *)(iVar7 + 0x1ec) + 0x174) < *(int *)(iVar8 + 0x174))))) {

          *(int *)(iVar7 + 0x1ec) = iVar8;

        }

      }

      param_1[0x39] = 200;

      return;

    case 0x68:

      smartie_claim_targets(param_1);

      if (*(int *)(iVar7 + 0x134) == 0) {

        object_destroy(param_1);

        return;

      }

      rpman_setup_firing_parameters__FP6OBJECTi(param_1,0xffffffff);

      *(undefined4 *)(iVar7 + 0xd8) = 1;

      param_1[0x36] = param_1[0x36] & 0xfff7ffff;

      param_1[0x39] = 0x23;

      return;

    }

  }

  else {

    if (((float)param_1[0x70] <= (float)param_1[0x9e]) && (iVar7 < 500)) {

      uVar20 = rndintrange(0,8);

      switch(uVar20) {

      case 0:

        fStack_1b0 = 8.12753e-44;

        break;

      case 1:

        fStack_1b0 = 8.40779e-44;

        break;

      case 2:

        fStack_1b0 = 8.96831e-44;

        break;

      case 3:

        fStack_1b0 = 1.20512e-43;

        break;

      case 4:

        fStack_1b0 = 1.21913e-43;

        break;

      case 5:

        fStack_1b0 = 1.24716e-43;

        break;

      case 6:

        fStack_1b0 = 1.26117e-43;

        break;

      case 7:

        fStack_1b0 = 1.27518e-43;

        break;

      case 8:

        fStack_1b0 = 1.28919e-43;

      }

      if (((float)param_1[4] != fStack_1b0) && (*(int *)(param_1[2] + 8 + (int)fStack_1b0 * 4) != 0)

         ) {

        ObjectSetAnim(param_1,fStack_1b0,0x20,0,(float)param_1[0x31] * 0.0,0x3e2aaaab);

      }

      param_1[0x39] = 500;

      return;

    }

    if (DAT_005a8578 != (int *)0x0) {

      if (DAT_005a8578[1] == 0xd7) {

        if (((DAT_005a8578 == param_1) && (piVar15[0x83] == 0)) && (iVar7 != 0xdb)) {

          DAT_005a8578 = (int *)0x0;

          param_1[0x38] = param_1[0x38] & 0xfeffffff;

          iVar7 = *piVar15;

          if (((iVar7 != 0) && (*(int *)(iVar7 + 0x1e0) == 0x12)) && (*(int *)(iVar7 + 0xe8) == 10))

          {

            *piVar15 = 0;

          }

        }

      }

      else {

        DAT_005a8578 = (int *)0x0;

        param_1[0x38] = param_1[0x38] & 0xfeffffff;

      }

    }

    *(undefined1 *)(param_1 + 0x82) = 0;

    *(undefined1 *)((int)param_1 + 0x20b) = 0;

    *(undefined1 *)((int)param_1 + 0x20a) = 0;

    param_1[0x36] = param_1[0x36] & 0xfcffffff;

    iVar5 = DAT_00632a88;

    uVar6 = param_1[0xc] & 2;

    iVar7 = param_1[0x40];

    if (iRam005a8570 != DAT_00632e70) {

      iRam005a8570 = DAT_00632e70;

      fVar18 = (float10)FUN_00518b70(param_1,0);

      fVar17 = (float10)_DAT_005a856c;

      _DAT_005a856c = (float)(fVar17 - fVar18);

      if (fVar17 - fVar18 < (float10)0.0) {

        _DAT_005a856c = 0.0;

      }

    }

    if (iRam005a8574 != DAT_00632e70) {

      iVar8 = ObjIsMecc(iVar5);

      if ((iVar8 == 0) || ((*(uint *)(iVar5 + 0xe0) & 0x2000000) == 0)) {

        _DAT_005a856c = 0.0;

        iRam005a8574 = DAT_00632e70;

      }

      else if ((*(float *)(iVar5 + 0x10c) != 0.0) || (*(float *)(iVar5 + 0x110) != 0.0)) {

        fVar17 = (float10)FUN_0050a610(param_1 + 0x28,iVar5 + 0xa0);

        if (fVar17 < (float10)57600.0) {

          fVar17 = (float10)dirfcalcp3d__FP3P3DT0

                                      (param_1 + 0x28,iVar5 + 0xa0,*(undefined4 *)(iVar7 + 0x58));

          fVar17 = (float10)diff_angle((float)fVar17);

          if (fVar17 < (float10)60.0) {

            fVar17 = (float10)FUN_00518b70(param_1,0);

            iRam005a8574 = DAT_00632e70;

            _DAT_005a856c = (float)(fVar17 + fVar17 + (float10)_DAT_005a856c);

          }

        }

      }

    }

    if (iRam005a8584 != DAT_00632e70) {

      iRam005a8584 = DAT_00632e70;

      fVar17 = (float10)FUN_00518b70(param_1,0);

      _DAT_005a857c = (float)(fVar17 + (float10)_DAT_005a857c);

    }

    fVar17 = (float10)func_0x0050a880(param_1[0xb7] + 0xcc);

    piVar15[0x16] = (int)(float)(fVar17 + (float10)(float)param_1[0x32]);

    iVar7 = *piVar15;

    if (iVar7 != 0) {

      piVar15[10] = *(int *)(iVar7 + 0xa0);

      piVar15[0xb] = *(int *)(iVar7 + 0xa4);

      piVar15[0xc] = *(int *)(iVar7 + 0xa8);

      fVar17 = (float10)FUN_0050a610(param_1 + 0x28,*piVar15 + 0xa0);

      piVar15[0xd] = (int)(float)fVar17;

    }

    fVar17 = (float10)FUN_00518b70(param_1,0);

    piVar15[8] = (int)(float)((float10)(float)piVar15[8] - fVar17);

    fVar17 = (float10)FUN_00518b70(param_1,0);

    piVar15[0x8c] = (int)(float)((float10)(float)piVar15[0x8c] - fVar17);

    fVar17 = (float10)FUN_00518b70(param_1,0);

    piVar15[0x19] = (int)(float)((float10)(float)piVar15[0x19] - fVar17);

    iVar7 = param_1[0x40];

    if ((param_1[0x38] & 0x400U) == 0) {

      *(undefined4 *)(iVar7 + 0xd4) = 0;

    }

    else {

      *(undefined4 *)(iVar7 + 0x148) = 0;

      if (param_1[0x39] == 0xe1) {

        *(undefined4 *)(iVar7 + 0xd4) = 1;

        *(undefined4 *)(iVar7 + 0xdc) = 0;

      }

      else {

        fVar17 = (float10)get_floor_z_point(param_1 + 0x28);

        if (fVar17 < (float10)0.0 == (fVar17 == (float10)0.0)) {

          fVar17 = (float10)FUN_00518b70(param_1,0);

          fVar17 = (float10)*(float *)(iVar7 + 0xdc) - fVar17;

          *(float *)(iVar7 + 0xdc) = (float)fVar17;

          if (fVar17 < (float10)0.0 == (fVar17 == (float10)0.0)) goto code_r0x004d9cb7;

          if (*(int *)(iVar7 + 0xd4) == 0) {

            *(undefined4 *)(iVar7 + 0xd4) = 1;

            uVar20 = *(undefined4 *)(DAT_00632ed8 + 0xbe0);

            uVar23 = *(undefined4 *)(DAT_00632ed8 + 0xbdc);

          }

          else {

            *(undefined4 *)(iVar7 + 0xd4) = 0;

            uVar20 = *(undefined4 *)(DAT_00632ed8 + 0xc2c);

            uVar23 = *(undefined4 *)(DAT_00632ed8 + 0xc28);

          }

        }

        else {

          *(undefined4 *)(iVar7 + 0xd4) = 1;

          uVar20 = *(undefined4 *)(DAT_00632ed8 + 0xbe0);

          uVar23 = *(undefined4 *)(DAT_00632ed8 + 0xbdc);

        }

        fVar17 = (float10)rndfloatrange(uVar23,uVar20);

        *(float *)(iVar7 + 0xdc) = (float)fVar17;

      }

    }

code_r0x004d9cb7:

    if ((DAT_005a8588 != 0) && (fRam005614b4 != DAT_006328e8)) {

      fRam005614b4 = DAT_006328e8;

      fVar17 = (float10)FUN_00518b70(0,0);

      pfVar13 = (float *)&DAT_005a850c;

      do {

        if (0.0 < *pfVar13) {

          fVar18 = (float10)*pfVar13 - fVar17;

          *pfVar13 = (float)fVar18;

          if (fVar18 < (float10)0.0 != (fVar18 == (float10)0.0)) {

            DAT_005a8588 = DAT_005a8588 + -1;

          }

        }

        pfVar13 = pfVar13 + 4;

      } while ((int)pfVar13 < 0x5a855c);

    }

    if ((param_1[0x3a] == 1) &&

       ((iVar7 = param_1[0x84], iVar7 == 0 ||

        (*(float *)(DAT_00632ed8 + 0xc8c) <

         (*(float *)(iVar7 + 0x278) / *(float *)(iVar7 + 0x1c0)) * 100.0)))) {

      param_1[0x6a] = *(int *)(param_1[0x40] + 0x1ac);

      sine_cos_lookup(param_1[0x32],&fStack_170,&fStack_120);

      param_1[0x4a] = (int)(*(float *)(DAT_00632ed8 + 0xc90) * fStack_170);

      param_1[0x4b] = (int)-(*(float *)(DAT_00632ed8 + 0xc90) * fStack_120);

      param_1[0x4c] = *(int *)(DAT_00632ed8 + 0xc94);

      param_1[0x84] = 0;

      param_1[0x3a] = 2;

      if ((param_1[4] != 0x97) && (*(int *)(param_1[2] + 0x264) != 0)) {

        ObjectSetAnim(param_1,0x97,0x20,0,(float)param_1[0x31] * 0.0,0x3e2aaaab);

      }

      param_1[0x39] = 0x66;

      iVar7 = crt_rand_scaled(100);

      if (iVar7 < 0x32) {

        uVar20 = 0x86;

      }

      else {

        uVar20 = 0x87;

      }

      sound_play_obj(uVar20,param_1);

    }

    if (param_1[0x39] - 10U < 0x1ed) {

                    /* WARNING (jumptable): Sanity check requires truncation of jumptable */

                    /* WARNING: Could not find normalized switch variable to match jumptable */

      switch(*(undefined1 *)((int)&PTR_LAB_004e0e28 + param_1[0x39] + 2)) {

      case 0:

        if (piVar15[0x4d] == 0) {

          piVar15[2] = param_1[0x28];

          piVar15[3] = param_1[0x29];

          piVar15[4] = param_1[0x2a];

          piVar15[5] = param_1[0x32];

        }

        ai_damage_response(param_1,1,0,0);

        param_1[0x3b] = 0x3f800000;

        param_1[0x39] = 0xb;

        break;

      case 1:

        fVar17 = (float10)FUN_00518b70(param_1,0);

        fVar17 = (float10)(float)piVar15[0x57] - fVar17;

        piVar15[0x57] = (int)(float)fVar17;

        if ((*(byte *)(param_1 + 0xc) & 2) != 0) {

          if ((param_1[0x38] & 0x4000U) == 0) {

            if (fVar17 < (float10)0.0 != (fVar17 == (float10)0.0)) {

              ai_damage_response(param_1,1,1,0);

            }

          }

          else {

            ai_damage_response(param_1,1,1,0);

          }

        }

        fVar17 = (float10)FUN_00518b70(param_1,0);

        fVar24 = (float)param_1[0x3b];

        param_1[0x3b] = (int)(float)((float10)fVar24 - fVar17);

        if ((float10)fVar24 - fVar17 < (float10)0.0) {

          rpman_scan_for_enemy__FP6OBJECTfii(param_1,piVar15[0x2b],1,0);

          param_1[0x3b] = 0x3f800000;

        }

        if (*piVar15 == 0) {

LAB_004de7f8:

          ai_visibility_cull(param_1);

        }

        else {

LAB_004dfddd:

          ai_d7_pairing(param_1,*(undefined4 *)(DAT_00632ed8 + 0xa20));

          param_1[0x39] = 0xc;

        }

        break;

      case 2:

        iVar7 = rpman_verify_enemy__FP6OBJECTf(param_1,piVar15[0x28]);

        if (iVar7 == 0) {

          if (*piVar15 == 0) {

LAB_004deb84:

            if (param_1[0x3a] != 0xe) goto LAB_004dfc63;

LAB_004deb91:

            param_1[0x39] = 10;

          }

          else {

            ai_d7_pairing(param_1,*(undefined4 *)(DAT_00632ed8 + 0xa20));

            piVar15[0x11] = 0;

            if (((((param_1[0x38] & 0x400U) == 0) && (param_1[0x3a] != 0x66)) &&

                (apiStack_1bc[1] = (int *)crt_rand_scaled(100),

                (float)(int)apiStack_1bc[1] < *(float *)(DAT_00632ed8 + 0xa28))) &&

               ((*(byte *)(param_1 + 0x38) & 0x20) == 0)) {

              rpman_find_hide_spot__FP6OBJECTi(param_1,1);

            }

            if (piVar15[0x11] == 0) goto LAB_004dd739;

            rpman_sniper_anim_set(param_1);

            param_1[0x39] = 0x3c;

          }

        }

        break;

      case 3:

        if (((((float)piVar15[0xd] < (float)piVar15[0x29] * (float)piVar15[0x29]) &&

             (param_1[0x3a] != 0xe)) || (iVar7 = obj_is_pickup_4a(*piVar15), iVar7 != 0)) ||

           ((iVar7 = obj_is_pickup_53(*piVar15), iVar7 != 0 ||

            (iVar7 = ObjIsTurret(*piVar15), iVar7 != 0)))) {

          if ((param_1[0x38] & 0x40000000U) == 0) {

            fVar17 = (float10)rndfloatrange(0x3f800000,0x40a00000);

            piVar15[0x17] = (int)(float)fVar17;

            rpman_set_enemy_attack_goal__FP6OBJECTi(param_1,0);

          }

          else {

            param_1[0x38] = param_1[0x38] & 0xbfffffff;

            piVar15[0x17] = 0;

          }

          if ((piVar15[0x35] == 0) && (piVar15[0x36] == 0)) {

            rpman_sniper_anim_set(param_1);

            param_1[0x39] = 0xe;

          }

          else {

            rpman_setup_firing_parameters__FP6OBJECTi(param_1,0xffffffff);

            rpman_init_firing__FP6OBJECT(param_1);

            cleaner_process(param_1,0);

            piVar15[0x36] = 1;

            param_1[0x39] = 0xf;

          }

        }

        else {

          param_1[0x39] = 0x14;

        }

        break;

      case 4:

        iVar7 = rpman_verify_enemy__FP6OBJECTf(param_1,piVar15[0x28]);

        if (iVar7 == 0) {

          if (*piVar15 == 0) {

            rpman_goto_last_loc__FP6OBJECTi(param_1,0);

            rpman_sniper_anim_set(param_1);

            param_1[0x39] = 0x10;

          }

          else {

            ai_d7_pairing(param_1,*(undefined4 *)(DAT_00632ed8 + 0xa20));

            rpman_consider_run_chatter__FP6OBJECT(param_1);

            param_1[0x5b] = (int)&LAB_004cb930;

            ai_goal_process(param_1);

            fVar17 = (float10)FUN_00518b70(param_1,0);

            fVar24 = (float)piVar15[0x17];

            piVar15[0x17] = (int)(float)((float10)fVar24 - fVar17);

            if ((param_1[0x5a] == 0) || ((float10)fVar24 - fVar17 < (float10)0.0)) {

              ai_clear_move_goal(param_1);

              if (((float)piVar15[0xd] < (float)piVar15[0x2a] * (float)piVar15[0x2a]) &&

                 (((float)piVar15[8] < 0.0 != ((float)piVar15[8] == 0.0) &&

                  ((*(byte *)(param_1 + 0x38) & 2) == 0)))) {

                iVar7 = *piVar15 + 0xa0;

                goto LAB_004decf7;

              }

              rpman_sniper_anim_set(param_1);

              fVar17 = (float10)rndfloatrange(0x3f800000,0x40a00000);

              piVar15[0x17] = (int)(float)fVar17;

              rpman_set_enemy_attack_goal__FP6OBJECTi(param_1,1);

              ai_goal_process(param_1);

              if (param_1[0x5a] == 0) {

                rpman_shot(param_1);

              }

              if (piVar15[0x35] != 0) {

                rpman_setup_firing_parameters__FP6OBJECTi(param_1,0xffffffff);

                rpman_init_firing__FP6OBJECT(param_1);

                piVar15[0x36] = 1;

                param_1[0x39] = 0xf;

              }

            }

          }

        }

        break;

      case 5:

        piVar15[0x53] = 0;

        if ((*(byte *)(param_1 + 0xc) & 2) != 0) {

          cleaner_process(param_1,0);

        }

        iVar7 = rpman_verify_enemy__FP6OBJECTf(param_1,piVar15[0x28]);

        if (iVar7 == 0) {

          if (*piVar15 == 0) {

            iVar7 = FUN_004e7250();

            if (iVar7 == 0) {

              fVar17 = (float10)get_floor_z_point(param_1 + 0x28);

              if (fVar17 < (float10)(float)piVar15[0xc]) {

                fVar17 = (float10)(float)piVar15[0xc];

              }

              ai_accel_update(param_1,(float)((float10)*(float *)(DAT_00632ed8 + 0xd24) + fVar17));

              rpman_goto_last_loc__FP6OBJECTi(param_1,1);

              param_1[0x5b] = (int)&LAB_004cb930;

              ai_goal_process(param_1);

              fVar17 = (float10)FUN_00518b70(param_1,0);

              fVar24 = (float)param_1[0x3b];

              param_1[0x3b] = (int)(float)((float10)fVar24 - fVar17);

              if ((float10)fVar24 - fVar17 < (float10)0.0) {

                iVar7 = piVar15[0x2b];

                goto LAB_004dee82;

              }

            }

            else {

              param_1[0x39] = 0x13;

            }

          }

          else {

            rpman_flying_fire__FP6OBJECT(param_1);

            ai_d7_pairing(param_1,*(undefined4 *)(DAT_00632ed8 + 0xa20));

            rpman_consider_run_chatter__FP6OBJECT(param_1);

            param_1[0x5b] = (int)&LAB_004cb930;

            ai_goal_process(param_1);

            fVar17 = (float10)FUN_00518b70(param_1,0);

            piVar15[0x17] = (int)(float)((float10)(float)piVar15[0x17] - fVar17);

            if (param_1[0x5a] == 0) {

LAB_004def3a:

              ai_clear_move_goal(param_1);

              fVar17 = (float10)rndfloatrange(0x3f800000,0x40a00000);

              piVar15[0x17] = (int)(float)fVar17;

              ai_move_force_goal(param_1,*piVar15 + 0xa0);

            }

            else {

              ai_get_goal_location(param_1,auStack_e8);

              fVar17 = (float10)distancesq2d__FP3P3DT0(auStack_e8,param_1 + 0x28);

              if (fVar17 < (float10)1600.0 != (fVar17 == (float10)1600.0)) {

                ai_clear_move_goal(param_1);

              }

              if ((param_1[0x5a] == 0) || ((float)piVar15[0x17] < 0.0)) goto LAB_004def3a;

            }

            if (piVar15[0x35] == 0) {

              iVar7 = FUN_004e7250(param_1);

              if (iVar7 != 0) {

                param_1[0x39] = 0x13;

              }

            }

            else {

              fVar17 = (float10)get_floor_z_point(param_1 + 0x28);

              if (fVar17 < (float10)*(float *)(*piVar15 + 0xa8)) {

                fVar17 = (float10)*(float *)(*piVar15 + 0xa8);

              }

              ai_accel_update(param_1,(float)((float10)*(float *)(DAT_00632ed8 + 0xd24) + fVar17));

            }

          }

        }

        break;

      case 6:

        fVar17 = (float10)FUN_00518b70(param_1,0);

        fVar24 = (float)param_1[0x3b];

        param_1[0x3b] = (int)(float)((float10)fVar24 - fVar17);

        if ((float10)fVar24 - fVar17 < (float10)0.0) {

          if (param_1[0x3a] != 0x66) {

            iVar7 = piVar15[0x2b];

          }

          else {

            iVar7 = piVar15[0x2b];

          }

          rpman_scan_for_enemy__FP6OBJECTfii(param_1,iVar7,1,param_1[0x3a] == 0x66);

          param_1[0x3b] = 0x3f800000;

        }

        if (*piVar15 == 0) {

          param_1[0x5b] = (int)&LAB_004cb930;

          ai_goal_process(param_1);

          if ((param_1[0x5a] == 0) ||

             ((-0.1 < *(float *)(param_1[0x41] + 0x24) && (*(float *)(param_1[0x41] + 0x24) < 0.1)))

             ) {

            rpman_hurt_anim(param_1,1);

            fVar17 = (float10)rndfloatrange(0x41200000,0x41f00000);

            piVar15[0x17] = (int)(float)fVar17;

            param_1[0x39] = 0x11;

          }

          else {

            ai_visibility_cull(param_1);

          }

        }

        else {

          iVar7 = obj_is_pickup_4a(*piVar15);

          if (((iVar7 == 0) && (iVar7 = obj_is_pickup_53(*piVar15), iVar7 == 0)) ||

             (param_1[0x3a] != 0x66)) goto LAB_004dfddd;

          param_1[0x39] = 0xcd;

        }

        break;

      case 7:

        if (((param_1[0x3a] == 2) || (param_1[0x3a] == 0x66)) || (piVar15[0x4d] != 0)) {

          fVar17 = (float10)FUN_00518b70(param_1,0);

          fVar17 = (float10)(float)piVar15[0x17] - fVar17;

          piVar15[0x17] = (int)(float)fVar17;

          if (fVar17 < (float10)0.0 != (fVar17 == (float10)0.0)) {

            if (param_1[0x3a] == 0x66) {

              rpman_scan_for_enemy__FP6OBJECTfii(param_1,piVar15[0x2b],1,1);

              if (*piVar15 == 0) {

                rpman_army_goto_firepit__FP6OBJECT(param_1);

              }

              else {

                iVar7 = obj_is_pickup_4a(*piVar15);

                if (((iVar7 == 0) && (iVar7 = obj_is_pickup_53(*piVar15), iVar7 == 0)) ||

                   (param_1[0x3a] != 0x66)) {

                  param_1[0x39] = 0xc;

                }

                else {

                  param_1[0x39] = 0xcd;

                }

              }

            }

            else {

              main_ai_move_004014b0(param_1,piVar15 + 2,piVar15[5]);

              rpman_sniper_anim_set(param_1);

              param_1[0x39] = 0x12;

            }

          }

        }

        else if ((param_1[0x38] & 0x8000000U) != 0) {

          fVar17 = (float10)FUN_00518b70(param_1,0);

          fVar17 = (float10)(float)piVar15[0x17] - fVar17;

          piVar15[0x17] = (int)(float)fVar17;

          if ((((*(byte *)(param_1 + 0xc) & 2) != 0) &&

              (fVar17 < (float10)0.0 != (fVar17 == (float10)0.0))) &&

             (uVar6 = param_1[0x38], (uVar6 & 0x4000) == 0)) {

            uVar11 = uVar6 & 0xf7ffffff;

            param_1[0x38] = uVar11;

            if ((char)(uVar11 >> 8) < '\0') {

              if ((uVar6 & 0x100) != 0) {

LAB_004df304:

                param_1[0x38] = uVar11 | 0x4000;

                ai_damage_response(param_1,1,1,0);

              }

            }

            else if ((uVar6 & 0x100) == 0) goto LAB_004df304;

          }

        }

        fVar17 = (float10)FUN_00518b70(param_1,0);

        fVar17 = (float10)(float)piVar15[0x57] - fVar17;

        piVar15[0x57] = (int)(float)fVar17;

        if ((*(byte *)(param_1 + 0xc) & 2) != 0) {

          if ((param_1[0x38] & 0x4000U) == 0) {

            if (fVar17 < (float10)0.0 != (fVar17 == (float10)0.0)) {

              ai_damage_response(param_1,1,1,0);

            }

          }

          else {

            ai_damage_response(param_1,1,1,0);

          }

        }

        fVar17 = (float10)FUN_00518b70(param_1,0);

        fVar24 = (float)param_1[0x3b];

        param_1[0x3b] = (int)(float)((float10)fVar24 - fVar17);

        if ((float10)fVar24 - fVar17 < (float10)0.0) {

          if (param_1[0x3a] != 0x66) {

            iVar7 = piVar15[0x29];

          }

          else {

            iVar7 = piVar15[0x29];

          }

          rpman_scan_for_enemy__FP6OBJECTfii(param_1,iVar7,1,param_1[0x3a] == 0x66);

          param_1[0x3b] = 0x3f800000;

        }

        if (*piVar15 == 0) goto LAB_004de7f8;

        iVar7 = obj_is_pickup_4a(*piVar15);

        if (((iVar7 == 0) && (iVar7 = obj_is_pickup_53(*piVar15), iVar7 == 0)) ||

           (param_1[0x3a] != 0x66)) {

          ai_d7_pairing(param_1,*(undefined4 *)(DAT_00632ed8 + 0xa20));

          param_1[0x39] = 0xc;

        }

        else {

          param_1[0x39] = 0xcd;

        }

        break;

      case 8:

        fVar17 = (float10)FUN_00518b70(param_1,0);

        fVar24 = (float)param_1[0x3b];

        param_1[0x3b] = (int)(float)((float10)fVar24 - fVar17);

        if ((float10)fVar24 - fVar17 < (float10)0.0) {

          rpman_scan_for_enemy__FP6OBJECTfii(param_1,piVar15[0x2b],1,0);

          param_1[0x3b] = 0x3f800000;

        }

        if (*piVar15 == 0) {

          param_1[0x5b] = (int)&LAB_004cb930;

          ai_goal_process(param_1);

          if (param_1[0x5a] != 0) goto LAB_004de7f8;

          if (piVar15[0x4d] == 0) goto LAB_004deb91;

          if ((*(byte *)(piVar15 + 0x51) & 2) == 0) {

            ai_rand_anim_select(param_1,1,1);

          }

          else {

            piVar15[0x35] = 1;

            piVar15[0x36] = 1;

            fVar17 = (float10)rndfloatrange(*(undefined4 *)(DAT_00632ed8 + 0xbdc),

                                            *(undefined4 *)(DAT_00632ed8 + 0xbe0));

            piVar15[0x37] = (int)(float)fVar17;

            ai_anim_play(param_1,0x81,1,0,0,0);

            if (1.0 < ABS((float)param_1[0x2a] - (float)piVar15[4])) {

              ai_accel_update(param_1,piVar15[4]);

              break;

            }

            param_1[0x4a] = 0;

            param_1[0x4b] = 0;

            param_1[0x4c] = 0;

          }

          param_1[0x39] = 0x22 - (uint)(piVar15[0x2c] != 0);

        }

        else {

          ai_d7_pairing(param_1,*(undefined4 *)(DAT_00632ed8 + 0xa20));

          param_1[0x39] = 0xc;

        }

        break;

      case 9:

        piVar15[0x53] = 0;

        if ((*(byte *)(param_1 + 0xc) & 2) != 0) {

          cleaner_process(param_1,0);

        }

        if (*piVar15 != 0) {

          rpman_flying_fire__FP6OBJECT(param_1);

        }

        param_1[0x5b] = (int)&LAB_004cb930;

        ai_goal_process(param_1);

        fVar17 = (float10)FUN_00518b70(param_1,0);

        piVar15[0x17] = (int)(float)((float10)(float)piVar15[0x17] - fVar17);

        if (param_1[0x5a] == 0) {

          if (*piVar15 != 0) {

            obj_turn_toward_point(param_1,*piVar15 + 0xa0);

          }

        }

        else {

          ai_get_goal_location(param_1,auStack_dc);

          fVar17 = (float10)distancesq2d__FP3P3DT0(auStack_dc,param_1 + 0x28);

          if (fVar17 < (float10)1600.0 != (fVar17 == (float10)1600.0)) {

            ai_clear_move_goal(param_1);

          }

        }

        if (*(char *)param_1[0x41] < '\0') {

          iVar7 = FUN_004e7250(param_1);

          if (iVar7 == 0) {

            rpman_sniper_anim_set(param_1);

            piVar15[0x36] = 0;

            ai_move_force_goal(param_1,piVar15 + 0x38);

            param_1[0x39] = 0x15;

          }

          else {

            rpman_sniper_anim_set(param_1);

            piVar15[0x36] = 0;

            param_1[0x39] = 0xe;

          }

        }

        else if ((float)param_1[0x4c] < -20.0) {

          param_1[0x4c] = -0x3e600000;

        }

        break;

      case 10:

        iVar7 = rpman_verify_enemy__FP6OBJECTf(param_1,piVar15[0x28]);

        if (iVar7 == 0) {

          if (*piVar15 == 0) goto LAB_004deb84;

          ai_d7_pairing(param_1,*(undefined4 *)(DAT_00632ed8 + 0xa20));

          fVar17 = (float10)obj_turn_toward_point(param_1,*piVar15 + 0xa0);

          if ((float10)5.0 <= fVar17) {

            if ((float)piVar15[0x29] * (float)piVar15[0x29] <= (float)piVar15[0xd])

            goto LAB_004ded23;

            FUN_004e7160(param_1,1);

            param_1[0x39] = 0xd;

          }

          else {

            FUN_004e7160(param_1,1);

LAB_004db788:

            if ((((float)piVar15[0xd] < (float)piVar15[0x2a] * (float)piVar15[0x2a]) &&

                ((float)piVar15[8] < 0.0 != ((float)piVar15[8] == 0.0))) &&

               ((*(byte *)(param_1 + 0x38) & 2) == 0)) {

              rpman_shot(param_1);

            }

          }

        }

        break;

      case 0xb:

        ai_goal_process(param_1);

        if (param_1[0x5a] == 0) {

          rpman_sniper_anim_set(param_1);

          piVar15[0x36] = 0;

          param_1[0x39] = 0xe;

        }

        else if (piVar15[0x35] != 0) {

          ai_clear_move_goal(param_1);

          param_1[0x39] = 0xd;

        }

        break;

      case 0xc:

        iVar7 = ai_ground_snap(param_1);

        if ((iVar7 != 0) && (piVar15[0x2c] == 0)) {

          ai_damage_update(param_1,iVar7);

        }

        if ((*(byte *)(piVar15 + 0x51) & 2) == 0) {

          piVar15[0x35] = 0;

          piVar15[0x36] = 0;

        }

        else {

          if ((*(byte *)(param_1 + 0xc) & 2) != 0) {

            cleaner_process(param_1,0);

          }

          piVar15[0x35] = 1;

          piVar15[0x36] = 1;

          fVar17 = (float10)rndfloatrange(*(undefined4 *)(DAT_00632ed8 + 0xbdc),

                                          *(undefined4 *)(DAT_00632ed8 + 0xbe0));

          piVar15[0x37] = (int)(float)fVar17;

        }

        fVar17 = (float10)FUN_00518b70(param_1,0);

        fVar24 = (float)param_1[0x3b];

        param_1[0x3b] = (int)(float)((float10)fVar24 - fVar17);

        if ((float10)fVar24 - fVar17 < (float10)0.0) {

          rpman_scan_for_enemy__FP6OBJECTfii(param_1,piVar15[0x2b],1,0);

          param_1[0x3b] = 0x3f800000;

        }

        if (*piVar15 == 0) {

          fVar17 = (float10)FUN_00518b70(param_1,0);

          fVar17 = (float10)(float)piVar15[0x2e] - fVar17;

          piVar15[0x2e] = (int)(float)fVar17;

          if (fVar17 < (float10)0.0 == (fVar17 == (float10)0.0)) {

            if (uVar6 != 0) {

              ai_idle_anim_53(param_1,0);

            }

          }

          else {

            ai_idle_anim_select(param_1);

            fVar17 = (float10)rndfloatrange(*(undefined4 *)(DAT_00632ed8 + 0xb44),

                                            *(undefined4 *)(DAT_00632ed8 + 0xb48));

            piVar15[0x2e] = (int)(float)fVar17;

          }

          iVar7 = ai_visibility_cull(param_1);

          if (iVar7 != 0) {

            ai_damage_update(param_1,0);

          }

        }

        else {

          ai_d7_pairing(param_1,*(undefined4 *)(DAT_00632ed8 + 0xa20));

          param_1[0x39] = 0xc;

          if ((piVar15[0x1b] != 0) && (*(int *)(piVar15[0x1b] + 0xe4) == 100)) {

            fVar17 = (float10)rndfloatrange(0x40400000,0x41700000);

            *(float *)(piVar15[0x1b] + 0xf0) = (float)fVar17;

            *(undefined4 *)(piVar15[0x1b] + 0xe4) = 0x65;

          }

          if (piVar15[0x4d] != 0) {

            *(undefined4 *)(piVar15[0x4d] + 0xe4) = 3;

          }

          piVar15[2] = param_1[0x28];

          piVar15[3] = param_1[0x29];

          piVar15[4] = param_1[0x2a];

          piVar15[5] = param_1[0x32];

        }

        break;

      case 0xd:

        iVar7 = ai_ground_snap(param_1);

        if (iVar7 != 0) {

          piVar15[0x50] = *(int *)(iVar7 + 0xfc);

        }

        puVar14 = DAT_00632d6c;

        if (uVar6 != 0) {

          for (; puVar14 != (undefined4 *)0x0; puVar14 = (undefined4 *)*puVar14) {

            piVar10 = (int *)puVar14[3];

            if (((param_1 != piVar10) && (piVar10[1] == 0xd7)) &&

               (*(int *)(piVar10[0x40] + 0x134) == piVar15[0x4d])) {

              if ((piVar10[0x38] & 0x1000U) == 0) {

                piVar15[2] = param_1[0x28];

                piVar15[3] = param_1[0x29];

                piVar15[4] = param_1[0x2a];

                piVar15[5] = param_1[0x32];

                ai_rand_anim_select(piVar10,1,1);

                if (piVar10[0x3a] == 0x66) {

                  if (*(int *)(*(int *)(piVar15[0x7c] + 0x100) + 0x5c) == 0) {

                    piVar10[0x39] = 0xcc;

                  }

                  else {

                    piVar10[0x39] = 0xd5;

                  }

                }

                else {

                  piVar10[0x39] = 0x21;

                }

              }

              else {

                piVar10[0x38] = piVar10[0x38] & 0xffffefff;

              }

            }

          }

          if (piVar15[0x1b] != 0) {

            fVar17 = (float10)rndfloatrange(0x40400000,0x41700000);

            *(float *)(piVar15[0x1b] + 0xf0) = (float)fVar17;

            *(undefined4 *)(piVar15[0x1b] + 0xe4) = 0x65;

          }

          if ((param_1[0x38] & 0x1000U) == 0) {

            piVar15[2] = param_1[0x28];

            piVar15[3] = param_1[0x29];

            piVar15[4] = param_1[0x2a];

            piVar15[5] = param_1[0x32];

            ai_damage_response(param_1,0,0,0);

            if (param_1[0x3a] != 0x66) goto LAB_004de042;

            param_1[0x39] =

                 (-(uint)(*(int *)(*(int *)(piVar15[0x7c] + 0x100) + 0x5c) != 0) & 9) + 0xcc;

          }

          else {

            param_1[0x38] = param_1[0x38] & 0xffffefff;

            iVar7 = rpman_verify_bush__FP6OBJECT(param_1);

            if (iVar7 == 0) {

              piVar15[2] = param_1[0x28];

              piVar15[3] = param_1[0x29];

              piVar15[4] = param_1[0x2a];

              piVar15[5] = param_1[0x32];

              ai_damage_response(param_1,0,0,0);

              param_1[0x38] = param_1[0x38] & 0xffffdfff;

LAB_004de042:

              param_1[0x39] = 0x20;

            }

            else {

              rpman_sniper_anim_set(param_1);

              param_1[0x39] = 0x46;

            }

          }

LAB_004de04c:

          if (piVar15[0x4d] != 0) {

            *(undefined4 *)(piVar15[0x4d] + 0xe4) = 3;

          }

        }

        break;

      case 0xe:

        fVar17 = (float10)FUN_00518b70(param_1,0);

        fVar24 = (float)param_1[0x3b];

        param_1[0x3b] = (int)(float)((float10)fVar24 - fVar17);

        if ((float10)fVar24 - fVar17 < (float10)0.0) {

          rpman_scan_for_enemy__FP6OBJECTfii(param_1,piVar15[0x2b],1,0);

          param_1[0x3b] = 0x3f800000;

        }

        if (*piVar15 == 0) {

          if (piVar15[0x30] == 0) {

            fVar17 = (float10)FUN_00518b70(param_1,0);

            piVar15[0x2f] = (int)(float)((float10)(float)piVar15[0x2f] - fVar17);

          }

          if (((float)piVar15[0x2f] < 0.0 == ((float)piVar15[0x2f] == 0.0)) ||

             (iVar7 = FUN_004e21f0(param_1), iVar7 == 0)) goto LAB_004de7f8;

          if ((piVar15[0x1b] == 0) || (*(int *)(piVar15[0x1b] + 0xe4) != 0x66)) {

            param_1[0x38] = param_1[0x38] & 0xffffdfff;

            for (puVar14 = DAT_00632d6c; puVar14 != (undefined4 *)0x0;

                puVar14 = (undefined4 *)*puVar14) {

              piVar10 = (int *)puVar14[3];

              if (((param_1 != piVar10) && (piVar10[1] == 0xd7)) &&

                 (*(int *)(piVar10[0x40] + 0x134) == piVar15[0x4d])) {

                ai_idle_anim_53(piVar10,0);

                piVar10[0x39] = 0x1e;

              }

            }

            if (piVar15[0x1b] != 0) {

              *(undefined4 *)(piVar15[0x1b] + 0xe4) = 100;

            }

            ai_idle_anim_53(param_1,0);

            *(undefined4 *)(piVar15[0x4d] + 0xe4) = 2;

            param_1[0x39] = 0x1e;

          }

          else {

            piVar15[0x2f] = 0x3f800000;

          }

        }

        else {

          ai_d7_pairing(param_1,*(undefined4 *)(DAT_00632ed8 + 0xa20));

          param_1[0x39] = 0xc;

          param_1[0x38] = param_1[0x38] & 0xffffdfff;

        }

        break;

      case 0xf:

        fVar17 = (float10)FUN_00518b70(param_1,0);

        fVar24 = (float)param_1[0x3b];

        param_1[0x3b] = (int)(float)((float10)fVar24 - fVar17);

        if ((float10)fVar24 - fVar17 < (float10)0.0) {

          rpman_scan_for_enemy__FP6OBJECTfii(param_1,piVar15[0x2b],1,0);

          param_1[0x3b] = 0x3f800000;

        }

        if (*piVar15 == 0) {

          ai_visibility_cull(param_1);

          if ((*(byte *)(piVar15 + 0x51) & 2) != 0) {

            piVar15[0x35] = 1;

            piVar15[0x36] = 1;

            fVar17 = (float10)rndfloatrange(*(undefined4 *)(DAT_00632ed8 + 0xbdc),

                                            *(undefined4 *)(DAT_00632ed8 + 0xbe0));

            piVar15[0x37] = (int)(float)fVar17;

            ai_accel_update(param_1,piVar15[4]);

          }

        }

        else {

          ai_d7_pairing(param_1,*(undefined4 *)(DAT_00632ed8 + 0xa20));

          param_1[0x39] = 0xc;

        }

        break;

      case 0x10:

        fVar17 = (float10)FUN_00518b70(param_1,0);

        fVar24 = (float)param_1[0x3b];

        param_1[0x3b] = (int)(float)((float10)fVar24 - fVar17);

        if ((float10)fVar24 - fVar17 < (float10)0.0) {

          rpman_scan_for_enemy__FP6OBJECTfii(param_1,piVar15[0x2b],1,0);

          param_1[0x3b] = 0x3f800000;

        }

        puVar14 = DAT_00632d6c;

        if (*piVar15 == 0) {

          for (; puVar14 != (undefined4 *)0x0; puVar14 = (undefined4 *)*puVar14) {

            piVar10 = (int *)puVar14[3];

            if (((param_1 != piVar10) && (piVar10[1] == 0xd7)) &&

               ((piVar15[0x4d] == *(int *)(piVar10[0x40] + 0x134) && (piVar10[0x39] != 0x21))))

            goto LAB_004de4e2;

          }

          if ((piVar15[0x1b] == 0) || (*(int *)(piVar15[0x1b] + 0xe4) != 0x66)) {

            param_1[0x38] = param_1[0x38] & 0xffffdfff;

            for (puVar14 = DAT_00632d6c; puVar14 != (undefined4 *)0x0;

                puVar14 = (undefined4 *)*puVar14) {

              iVar7 = puVar14[3];

              if ((*(int *)(iVar7 + 4) == 0xd7) &&

                 (piVar15[0x4d] == *(int *)(*(int *)(iVar7 + 0x100) + 0x134))) {

                if (piVar15[0x30] == 0) {

                  ai_idle_anim_53(iVar7,0);

                  *(undefined4 *)(iVar7 + 0xe4) = 0x1e;

                }

                else if (piVar15[0x2c] == 0) {

                  ai_damage_response(iVar7,0,0,0);

                  param_1[0x39] = 0x20;

                }

                else {

                  ai_rand_anim_select(iVar7,1,1);

                  *(undefined4 *)(iVar7 + 0xe4) = 0x21;

                }

              }

            }

            if (piVar15[0x1b] != 0) {

              if (piVar15[0x30] == 0) {

                *(undefined4 *)(piVar15[0x1b] + 0xe4) = 100;

              }

              else {

                fVar17 = (float10)rndfloatrange(0x40400000,0x41700000);

                *(float *)(piVar15[0x1b] + 0xf0) = (float)fVar17;

                *(undefined4 *)(piVar15[0x1b] + 0xe4) = 0x65;

              }

            }

            if ((piVar15[0x4d] != 0) && (piVar15[0x30] == 0)) {

              *(undefined4 *)(piVar15[0x4d] + 0xe4) = 2;

            }

          }

          else {

LAB_004de4e2:

            ai_visibility_cull(param_1);

            if ((*(byte *)(piVar15 + 0x51) & 2) != 0) {

              piVar15[0x35] = 1;

              piVar15[0x36] = 1;

              fVar17 = (float10)rndfloatrange(*(undefined4 *)(DAT_00632ed8 + 0xbdc),

                                              *(undefined4 *)(DAT_00632ed8 + 0xbe0));

              piVar15[0x37] = (int)(float)fVar17;

              ai_accel_update(param_1,piVar15[4]);

            }

          }

        }

        else {

          ai_d7_pairing(param_1,*(undefined4 *)(DAT_00632ed8 + 0xa20));

          param_1[0x39] = 0xc;

        }

        break;

      case 0x11:

        if ((*(byte *)(param_1 + 0xc) & 2) != 0) {

          cleaner_process(param_1,0);

        }

        ai_ground_snap(param_1);

        if (piVar15[0x2c] == 0) {

          if (*piVar15 == 0) {

            rpman_scan_for_enemy__FP6OBJECTfii(param_1,0x43c80000,1,0);

            *(int *)(piVar15[0x4d] + 0x274) = *piVar15;

            if (*piVar15 == 0) break;

            piVar15[0x84] = 0x3f000000;

            goto LAB_004de88d;

          }

        }

        else {

          if (*piVar15 != *(int *)(piVar15[0x4d] + 0x274)) {

            piVar15[0x84] = 0x3f000000;

          }

          *piVar15 = *(int *)(piVar15[0x4d] + 0x274);

LAB_004de88d:

          if (*piVar15 == 0) break;

        }

        fVar17 = (float10)FUN_00518b70(param_1,0);

        fVar17 = fVar17 + fVar17 + (float10)(float)piVar15[0x84];

        piVar15[0x84] = (int)(float)fVar17;

        if ((float10)1.5 < fVar17) {

          piVar15[0x84] = 0x3fc00000;

        }

        playerobj_eval_refpt(param_1[0x9d],2,&fStack_154);

        piVar15[10] = (int)((*(float *)(*piVar15 + 0xa0) - fStack_154) * (float)piVar15[0x84] +

                           fStack_154);

        piVar15[0xb] = (int)((*(float *)(*piVar15 + 0xa4) - fStack_150) * (float)piVar15[0x84] +

                            fStack_150);

        fVar17 = (float10)get_floor_z_point(piVar15 + 10);

        piVar15[0xc] = (int)(float)fVar17;

        fVar17 = (float10)dirucalcp3d__FP3P3DT0(&fStack_154,*piVar15 + 0xa0);

        if ((fVar17 < (float10)*(float *)(DAT_00632ed8 + 0x11ac)) ||

           ((float10)*(float *)(DAT_00632ed8 + 0x11b0) < fVar17)) {

LAB_004de996:

          if (piVar15[0x2c] == 0) {

            *(undefined4 *)(piVar15[0x4d] + 0x274) = 0;

          }

          *piVar15 = 0;

        }

        else if ((float)piVar15[0x84] < 1.5) {

          iVar7 = *piVar15;

          *piVar15 = 0;

          rpman_flying_fire__FP6OBJECT(param_1);

          *piVar15 = iVar7;

        }

        break;

      case 0x12:

        rpman_rapid_fire__FP6OBJECTiii(param_1,0x4e,0x9b,0);

        break;

      case 0x13:

        if (*piVar15 != 0) {

          obj_turn_toward_point(param_1,*piVar15 + 0xa0);

        }

        if (uVar6 != 0) {

          param_1[0x39] = 0x2a;

        }

        break;

      case 0x14:

        rpman_rapid_fire__FP6OBJECTiii(param_1,0x37,0x37,1);

        break;

      case 0x15:

        if (*piVar15 != 0) {

          obj_turn_toward_point(param_1,*piVar15 + 0xa0);

        }

        if (uVar6 != 0) {

          param_1[0x39] = 0x2c;

        }

        break;

      case 0x16:

        rpman_rapid_fire__FP6OBJECTiii(param_1,0x31,0x30,1);

        break;

      case 0x17:

        bVar16 = false;

        if (*piVar15 != 0) {

          if (param_1[0x3a] == 4) {

            iVar7 = rpman_turn_towards(param_1,*piVar15 + 0xa0);

            bVar16 = iVar7 == 0;

          }

          else {

            obj_turn_toward_point();

          }

        }

        ai_d7_pairing(param_1,*(undefined4 *)(DAT_00632ed8 + 0xa20));

        if ((1.1 < (float)param_1[5]) && (!bVar16)) {

          param_1[0x39] = 0x2e;

          make_grenade_shot__FP6OBJECTf(param_1,*(undefined4 *)(DAT_00632ed8 + 0x54));

        }

        if (uVar6 == 0) {

          if (!bVar16) break;

        }

        else {

          fVar17 = (float10)rndfloatrange(piVar15[0x25],piVar15[0x26]);

          piVar15[8] = (int)(float)fVar17;

        }

        iVar7 = param_1[0x3a];

        if (iVar7 == 4) {

          param_1[0x39] = 0xad;

        }

        else if (iVar7 == 0x66) {

          if ((param_1[0x38] & 0x80000U) == 0) {

            iVar7 = obj_is_pickup_4a(*piVar15);

            if ((iVar7 == 0) && (iVar7 = obj_is_pickup_53(*piVar15), iVar7 == 0)) goto LAB_004dffe0;

            iVar7 = crt_rand_scaled(100);

            if (((iVar7 < piVar15[0x70]) && (iVar7 = obj_is_pickup_4a_model(*piVar15), iVar7 == 0))

               && (iVar7 = obj_is_pickup_53_model(*piVar15), iVar7 == 0)) {

              iVar7 = piVar15[0x26];

              iVar5 = piVar15[0x25];

              goto LAB_004e0191;

            }

LAB_004dd316:

            param_1[0x39] = 0xd0;

          }

          else {

LAB_004e00c3:

            ai_radius_scan(param_1,0x44480000);

            if (*piVar15 == 0) {

              param_1[0x38] = param_1[0x38] & 0xfff7ffff;

              goto LAB_004e00f0;

            }

            param_1[0x39] = 0xd7;

          }

        }

        else {

          if (iVar7 != 0x67) {

LAB_004dffe0:

            iVar7 = piVar15[0x26];

            iVar5 = piVar15[0x25];

            goto LAB_004e012b;

          }

          param_1[0x39] = 0xea;

        }

        break;

      case 0x18:

        if (*piVar15 != 0) {

          obj_turn_toward_point(param_1,*piVar15 + 0xa0);

        }

        ai_d7_pairing(param_1,*(undefined4 *)(DAT_00632ed8 + 0xa20));

        if (uVar6 != 0) {

          iVar7 = param_1[0x3a];

          if (iVar7 == 4) {

            param_1[0x39] = 0xad;

          }

          else {

            if (iVar7 == 0x66) {

              if ((param_1[0x38] & 0x80000U) != 0) goto LAB_004e00c3;

              iVar7 = obj_is_pickup_4a(*piVar15);

              if ((iVar7 == 0) && (iVar7 = obj_is_pickup_53(*piVar15), iVar7 == 0))

              goto LAB_004e011d;

              iVar7 = crt_rand_scaled(100);

              if ((piVar15[0x70] <= iVar7) ||

                 ((iVar7 = obj_is_pickup_4a_model(*piVar15), iVar7 != 0 ||

                  (iVar7 = obj_is_pickup_53_model(*piVar15), iVar7 != 0)))) goto LAB_004dd316;

              iVar7 = piVar15[0x26];

              iVar5 = piVar15[0x25];

LAB_004e0191:

              fVar17 = (float10)rndfloatrange(iVar5,iVar7);

              piVar15[8] = (int)(float)fVar17;

              goto LAB_004e019c;

            }

            if (iVar7 == 0x67) {

              param_1[0x39] = 0xea;

              break;

            }

LAB_004e011d:

            iVar7 = piVar15[0x26];

            iVar5 = piVar15[0x25];

LAB_004e012b:

            fVar17 = (float10)rndfloatrange(iVar5,iVar7);

            piVar15[8] = (int)(float)fVar17;

LAB_004e0136:

            param_1[0x39] = 0xc;

          }

        }

        break;

      case 0x19:

        fire_sniper_shot__FP6OBJECTT0(param_1,0x7b,0x74,1);

        break;

      case 0x1a:

        if (*piVar15 != 0) {

          obj_turn_toward_point(param_1,*piVar15 + 0xa0);

        }

        if (uVar6 != 0) {

          param_1[0x39] = 0x31;

        }

        break;

      case 0x1b:

        fire_sniper_shot__FP6OBJECTT0(param_1,0x7a,0x77,1);

        break;

      case 0x1c:

        fire_sniper_shot__FP6OBJECTT0(param_1,0x90,0x8c,1);

        break;

      case 0x1d:

        if (*piVar15 != 0) {

          obj_turn_toward_point(param_1,*piVar15 + 0xa0);

        }

        if (uVar6 != 0) {

          param_1[0x39] = 0x34;

        }

        break;

      case 0x1e:

        fire_sniper_shot__FP6OBJECTT0(param_1,0x95,0x94,1);

        break;

      case 0x1f:

        fire_sniper_shot__FP6OBJECTT0(param_1,0x7c,0x50,0);

        break;

      case 0x20:

        if ((param_1[0x38] & 0x800U) == 0) {

          iVar7 = rpman_verify_enemy__FP6OBJECTf(param_1,piVar15[0x28]);

          if (iVar7 != 0) break;

          if (*piVar15 == 0) {

LAB_004df66e:

            rpman_sniper_anim_set(param_1);

            rpman_goto_last_loc__FP6OBJECTi(param_1,0);

            param_1[0x39] = 0x10;

          }

          else {

            ai_d7_pairing(param_1,*(undefined4 *)(DAT_00632ed8 + 0xa20));

LAB_004df73d:

            if (piVar15[0x11] == 0) {

              rpman_find_hide_spot__FP6OBJECTi(param_1,1);

              if (piVar15[0x11] == 0) {

                param_1[0x39] = 0xc;

              }

              param_1[0x72] = param_1[0x72] & 0xfffffbff;

              return;

            }

            if (*piVar15 != 0) {

              fVar17 = (float10)dirfcalcp3d__FP3P3DT0(piVar15[0x11] + 0xa0,*piVar15 + 0xa0);

              sine_cos_lookup((float)(fVar17 + (float10)180.0),&fStack_17c,&fStack_138);

              iVar7 = piVar15[0x11];

              pfVar13 = (float *)(piVar15 + 0x12);

              fVar24 = *(float *)(iVar7 + 0x1f8) * *(float *)(iVar7 + 0xc4) + (float)param_1[0x55];

              *pfVar13 = fStack_17c * fVar24 + *(float *)(iVar7 + 0xa0);

              piVar15[0x13] = (int)(*(float *)(piVar15[0x11] + 0xa4) - fVar24 * fStack_138);

              piVar15[0x14] = *(int *)(piVar15[0x11] + 0xa8);

              param_1[0x5b] = (int)&LAB_004cb930;

              ai_move_update_goal(param_1,pfVar13);

              fVar17 = (float10)distancesq2d__FP3P3DT0(param_1 + 0x28,pfVar13);

              if (fVar17 < (float10)25.0) {

                param_1[0x72] = param_1[0x72] | 0x400;

              }

            }

            rpman_consider_run_chatter__FP6OBJECT(param_1);

            param_1[0x5b] = (int)&LAB_004cb930;

            ai_goal_process(param_1);

            if (param_1[0x5a] != 0) break;

            iVar7 = piVar15[0x11] + 0xa0;

            if (*(char *)(piVar15[0x11] + 0x1f7) == '\x03') {

              fVar17 = (float10)dirfcalcp3d__FP3P3DT0(iVar7,*piVar15 + 0xa0);

              param_1[0x32] = (int)(float)fVar17;

              ai_anim_play(param_1,0x43,1,0,0,0);

              param_1[0x38] = param_1[0x38] & 0xfffffffb;

              param_1[0x39] = 0x3f;

            }

            else {

              fVar17 = (float10)dirfcalcp3d__FP3P3DT0(iVar7,*piVar15 + 0xa0);

              param_1[0x32] = (int)(float)fVar17;

              ai_anim_play(param_1,0x2d,1,0,0,0);

              param_1[0x38] = param_1[0x38] & 0xfffffffb;

              param_1[0x39] = 0x41;

            }

          }

        }

        else {

          fVar17 = (float10)FUN_00518b70(param_1,0);

          fVar24 = (float)param_1[0x3b];

          param_1[0x3b] = (int)(float)((float10)fVar24 - fVar17);

          if ((float10)fVar24 - fVar17 < (float10)0.0) {

            rpman_scan_for_enemy__FP6OBJECTfii(param_1,piVar15[0x58],1,0);

            param_1[0x3b] = 0x3f800000;

          }

          if (*piVar15 == 0) {

            iVar7 = ai_move_pair_caller(param_1);

            if (iVar7 == 0) goto LAB_004df73d;

          }

          else {

LAB_004df6f3:

            ai_d7_pairing(param_1,*(undefined4 *)(DAT_00632ed8 + 0xa20));

            param_1[0x38] = param_1[0x38] & 0xfffff7ff;

            param_1[0x39] = 0xc;

          }

        }

LAB_004df8ad:

        param_1[0x72] = param_1[0x72] & 0xfffffbff;

        break;

      case 0x21:

        if ((param_1[0x38] & 0x800U) == 0) {

          iVar7 = rpman_verify_enemy__FP6OBJECTf(param_1,piVar15[0x28]);

          if (iVar7 != 0) break;

          if (*piVar15 == 0) goto LAB_004df66e;

          ai_d7_pairing(param_1,*(undefined4 *)(DAT_00632ed8 + 0xa20));

          rpman_maintain_hide__FP6OBJECT(param_1);

        }

        else {

          fVar17 = (float10)FUN_00518b70(param_1,0);

          fVar24 = (float)param_1[0x3b];

          param_1[0x3b] = (int)(float)((float10)fVar24 - fVar17);

          if ((float10)fVar24 - fVar17 < (float10)0.0) {

            rpman_scan_for_enemy__FP6OBJECTfii(param_1,piVar15[0x58],1,0);

            param_1[0x3b] = 0x3f800000;

          }

          if (*piVar15 != 0) goto LAB_004df6f3;

          iVar7 = ai_move_pair_caller(param_1);

          if (iVar7 != 0) goto LAB_004df8ad;

        }

        uVar11 = param_1[0x38];

        if ((((uVar11 & 4) != 0) && ((uVar11 & 0x800) == 0)) ||

           ((uVar6 != 0 && (((uVar11 & 0x800) == 0 && (iVar7 = crt_rand_scaled(100), iVar7 < 0x14)))

            ))) {

          ai_anim_play(param_1,0x44,0,0,0,0);

          param_1[0xc] = param_1[0xc] | 0x10;

          param_1[0x39] = 0x40;

          goto LAB_004df8ad;

        }

        break;

      case 0x22:

        iVar7 = rpman_verify_enemy__FP6OBJECTf(param_1,piVar15[0x28]);

        if (iVar7 == 0) {

          if (*piVar15 == 0) goto LAB_004dfc63;

          uVar20 = *(undefined4 *)(DAT_00632ed8 + 0xa20);

LAB_004dfc8e:

          ai_d7_pairing(param_1,uVar20);

          if (uVar6 != 0) {

            piVar15[0x11] = 0;

            param_1[0x39] = 0xd;

          }

        }

        break;

      case 0x23:

        if ((param_1[0x38] & 0x800U) == 0) {

          piVar15[0xe] = 0;

          iVar7 = rpman_verify_enemy__FP6OBJECTf(param_1,piVar15[0x28]);

          if (iVar7 != 0) break;

          if (*piVar15 == 0) goto LAB_004df66e;

          ai_d7_pairing(param_1,*(undefined4 *)(DAT_00632ed8 + 0xa20));

          rpman_maintain_hide__FP6OBJECT(param_1);

        }

        else {

          fVar17 = (float10)FUN_00518b70(param_1,0);

          fVar24 = (float)param_1[0x3b];

          param_1[0x3b] = (int)(float)((float10)fVar24 - fVar17);

          if ((float10)fVar24 - fVar17 < (float10)0.0) {

            rpman_scan_for_enemy__FP6OBJECTfii(param_1,piVar15[0x58],1,0);

            param_1[0x3b] = 0x3f800000;

          }

          if (*piVar15 != 0) goto LAB_004df6f3;

          iVar7 = ai_move_pair_caller(param_1);

          if (iVar7 != 0) goto LAB_004df8ad;

        }

        if (((param_1[0x38] & 4U) != 0) && ((param_1[0x38] & 0x800U) == 0)) {

LAB_004dfafe:

          ai_anim_play(param_1,0x2e,0,0,0,0);

          param_1[0xc] = param_1[0xc] | 0x10;

          param_1[0x39] = 0x42;

          goto LAB_004df8ad;

        }

        if ((uVar6 != 0) &&

           (((param_1[0x39] & 0x800U) == 0 && (iVar7 = crt_rand_scaled(100), iVar7 < 0x28)))) {

          iVar7 = crt_rand_scaled(100);

          ppiStack_1c4 = (int **)0xbf800000;

          if (0x31 < iVar7) {

            ppiStack_1c4 = (int **)0x3f800000;

          }

          fVar17 = (float10)rndfloatrange(0x40a00000,0x41a00000);

          sine_cos_lookup((float)ppiStack_1c4 * 90.0 + (float)param_1[0x32],&fStack_128,&fStack_1b0)

          ;

          apiStack_1bc[0] = (int *)(fStack_128 * (float)fVar17);

          apiStack_1bc[1] = (int *)-(fStack_1b0 * (float)fVar17);

          iVar7 = ai_los_clear_to_target(apiStack_1bc[0],apiStack_1bc[1],param_1,*piVar15);

          if (iVar7 != 0) {

            if (0.0 <= (float)ppiStack_1c4) {

              param_1[0x38] = param_1[0x38] & 0xffffffef;

            }

            else {

              param_1[0x38] = param_1[0x38] | 0x10;

            }

            goto LAB_004dfafe;

          }

        }

        break;

      case 0x24:

        iVar7 = rpman_check_los__FP6OBJECTT0(param_1,*piVar15);

        if (iVar7 == 0) {

          *(byte *)((int)param_1 + 0x20b) =

               (-((*(byte *)(param_1 + 0x38) & 0x10) != 0) & 0xdaU) + 0x13;

        }

        iVar7 = rpman_verify_enemy__FP6OBJECTf(param_1,piVar15[0x28]);

        if (iVar7 == 0) {

          if (*piVar15 != 0) {

            uVar20 = *(undefined4 *)(DAT_00632ed8 + 0xa20);

            goto LAB_004dfc8e;

          }

LAB_004dfc63:

          rpman_sniper_anim_set(param_1);

          rpman_goto_last_loc__FP6OBJECTi(param_1,0);

          param_1[0x39] = 0x10;

        }

        break;

      case 0x25:

        iVar7 = rpman_verify_bush__FP6OBJECT(param_1);

        if (iVar7 == 0) {

          rpman_scan_for_enemy__FP6OBJECTfii(param_1,piVar15[0x2b],1,0);

          if (*piVar15 == 0) {

            if ((param_1[0x3a] == 2) || (piVar15[0x4d] != 0)) {

              iVar7 = piVar15[5];

LAB_004dfe2b:

              main_ai_move_004014b0(param_1,piVar15 + 2,iVar7);

              param_1[0x39] = 0x12;

              goto LAB_004dfe3e;

            }

          }

          else {

            ai_d7_pairing(param_1,*(undefined4 *)(DAT_00632ed8 + 0xa20));

            param_1[0x39] = 0xc;

          }

        }

        else {

          ai_move_update_goal(param_1,DAT_00632a88 + 0xa0);

          ai_goal_process(param_1);

          if ((param_1[0x5a] == 0) ||

             (fVar17 = (float10)distancesq2d__FP3P3DT0(param_1 + 0x28,DAT_00632a88 + 0xa0),

             fVar17 < (float10)121.0)) {

            ai_clear_move_goal(param_1);

            ai_anim_play(param_1,0x42,0,0,0,0);

            param_1[0x39] = 0x47;

            sound_play_obj(0x82,param_1);

          }

        }

        break;

      case 0x26:

        iVar7 = rpman_verify_bush__FP6OBJECT(param_1);

        if (iVar7 == 0) {

          rpman_scan_for_enemy__FP6OBJECTfii(param_1,piVar15[0x2b],1,0);

          if (*piVar15 != 0) goto LAB_004dfddd;

          if ((param_1[0x3a] == 2) || (piVar15[0x4d] != 0)) {

            iVar7 = piVar15[5];

            goto LAB_004dfe2b;

          }

          param_1[0x39] = 10;

LAB_004dfe3e:

          if (piVar15[0x4d] != 0) {

            FUN_004e2b10(param_1);

          }

        }

        else {

          obj_turn_toward_point(param_1,DAT_00632a88 + 0xa0);

          if (uVar6 != 0) {

            if (param_1[0x3a] == 2) {

              if (piVar15[0x4d] != 0) goto LAB_004dfe9f;

LAB_004dfea8:

              main_ai_move_004014b0(param_1,piVar15 + 2,piVar15[5]);

              rpman_sniper_anim_set(param_1);

              param_1[0x39] = 0x12;

            }

            else {

              if (piVar15[0x4d] != 0) {

LAB_004dfe9f:

                FUN_004e2b10(param_1);

                goto LAB_004dfea8;

              }

              param_1[0x39] = 10;

            }

            DAT_005a8568 = 0;

            _DAT_005a856c = 0.0;

          }

        }

        break;

      case 0x27:

        if ((piVar15[0x11] == 0) &&

           (rpman_find_hide_spot__FP6OBJECTi(param_1,0), piVar15[0x11] == 0)) {

          rpman_hurt_anim(param_1,1);

          param_1[0x39] = 0x51;

        }

        else {

          fVar17 = (float10)FUN_00518b70(param_1,0);

          fVar24 = (float)param_1[0x3b];

          param_1[0x3b] = (int)(float)((float10)fVar24 - fVar17);

          if ((float10)fVar24 - fVar17 < (float10)0.0) {

            rpman_scan_for_enemy__FP6OBJECTfii(param_1,piVar15[0x58],1,0);

            param_1[0x3b] = 0x3f800000;

          }

          if (*piVar15 != 0) goto LAB_004dfddd;

          fVar17 = (float10)dirfcalcp3d__FP3P3DT0(piVar15[0x11] + 0xa0,piVar15 + 0x31);

          sine_cos_lookup((float)(fVar17 + (float10)180.0),&fStack_11c,&fStack_140);

          iVar7 = piVar15[0x11];

          fVar24 = *(float *)(iVar7 + 0x1f8) * *(float *)(iVar7 + 0xc4) + (float)param_1[0x55];

          piVar15[0x12] = (int)(fStack_11c * fVar24 + *(float *)(iVar7 + 0xa0));

          piVar15[0x13] = (int)(*(float *)(piVar15[0x11] + 0xa4) - fVar24 * fStack_140);

          piVar15[0x14] = *(int *)(piVar15[0x11] + 0xa8);

          param_1[0x5b] = (int)&LAB_004cb930;

          ai_move_update_goal(param_1,piVar15 + 0x12);

          rpman_consider_run_chatter__FP6OBJECT(param_1);

          param_1[0x5b] = (int)&LAB_004cb930;

          ai_goal_process(param_1);

          if (param_1[0x5a] == 0) {

            iVar7 = piVar15[0x11] + 0xa0;

            if (*(char *)(piVar15[0x11] + 0x1f7) == '\x03') {

              fVar17 = (float10)dirfcalcp3d__FP3P3DT0(iVar7,DAT_00632a88 + 0xa0);

              param_1[0x32] = (int)(float)fVar17;

              ai_anim_play(param_1,0x43,1,0,0,0);

              param_1[0x38] = param_1[0x38] & 0xfffffffb;

              param_1[0x39] = 0x3f;

            }

            else {

              fVar17 = (float10)dirfcalcp3d__FP3P3DT0(iVar7,DAT_00632a88 + 0xa0);

              param_1[0x32] = (int)(float)fVar17;

              ai_anim_play(param_1,0x2d,1,0,0,0);

              param_1[0x38] = param_1[0x38] & 0xfffffffb;

              param_1[0x39] = 0x41;

            }

            param_1[0x38] = param_1[0x38] | 0x800;

          }

        }

        break;

      case 0x28:

        fVar17 = (float10)FUN_00518b70(param_1,0);

        fVar17 = (float10)(float)piVar15[0x57] - fVar17;

        piVar15[0x57] = (int)(float)fVar17;

        if ((*(byte *)(param_1 + 0xc) & 2) != 0) {

          if ((param_1[0x38] & 0x4000U) == 0) {

            if (fVar17 < (float10)0.0 != (fVar17 == (float10)0.0)) {

              ai_damage_response(param_1,1,1,0);

            }

          }

          else {

            ai_damage_response(param_1,1,1,0);

          }

        }

        fVar17 = (float10)FUN_00518b70(param_1,0);

        fVar24 = (float)param_1[0x3b];

        param_1[0x3b] = (int)(float)((float10)fVar24 - fVar17);

        if ((float10)fVar24 - fVar17 < (float10)0.0) {

          rpman_scan_for_enemy__FP6OBJECTfii(param_1,piVar15[0x58],1,0);

        }

        if (*piVar15 != 0) goto LAB_004dfddd;

        rpman_find_hide_spot__FP6OBJECTi(param_1,0);

        if (piVar15[0x11] == 0) {

          iVar7 = ai_move_pair_caller(param_1);

          if (iVar7 == 0) goto LAB_004de7f8;

        }

        else {

          rpman_sniper_anim_set();

          param_1[0x39] = 0x50;

        }

        break;

      case 0x29:

        fVar24 = (float)param_1[0x4c] - (float)param_1[0x4f];

        if ((char)((*(float *)(DAT_00632ed8 + 0xd74) <= fVar24) +

                  (*(float *)(DAT_00632ed8 + 0xd78) <= fVar24)) == '\0') {

          if (*(char *)param_1[0x41] < '\0') {

            ai_anim_play(param_1,0x3f,0,0,0,0);

            param_1[0x39] = 0x5b;

          }

        }

        else {

          obj_damage_apply(2,(fVar24 - *(float *)(DAT_00632ed8 + 0xd78)) *

                             *(float *)(DAT_00632ed8 + 0xd7c) + *(float *)(DAT_00632ed8 + 0xd88),

                           param_1,0,param_1 + 0x28,0);

          ai_anim_play(param_1,0x3f,0,0,0,0);

          param_1[0x39] = 0x5b;

        }

        break;

      case 0x2a:

        if (uVar6 != 0) {

          if (piVar15[0x36] == 0) goto LAB_004e0136;

          piVar15[0x36] = 0;

          ai_anim_play(param_1,0x8b,0,0,0,0);

          param_1[0x39] = 0x5c;

        }

        break;

      case 0x2b:

        if (uVar6 != 0) {

          param_1[0x39] = 0xc;

        }

        break;

      case 0x2c:

        if (uVar6 != 0) {

          if (param_1[0x3a] == 1) {

            param_1[0x39] = 100;

          }

          else {

            param_1[0x39] = (piVar15[0x36] != 0) + 0xc;

          }

        }

        break;

      case 0x2d:

        if (uVar6 != 0) {

          if (param_1[0x3a] == 1) {

            param_1[0x39] = 100;

          }

          else {

            param_1[0x39] = (piVar15[0x36] != 0) + 0xc;

          }

        }

        break;

      case 0x2e:

        ai_damage_response(param_1,1,0,0);

        param_1[0x39] = 0x65;

        param_1[0x3b] = 0x3f800000;

        break;

      case 0x2f:

        fVar17 = (float10)FUN_00518b70(param_1,0);

        fVar24 = (float)param_1[0x3b];

        param_1[0x3b] = (int)(float)((float10)fVar24 - fVar17);

        if ((float10)fVar24 - fVar17 < (float10)0.0) {

          rpman_scan_for_enemy__FP6OBJECTfii(param_1,piVar15[0x29],1,0);

          param_1[0x3b] = 0x3f800000;

        }

        iVar7 = piVar15[5];

        fVar17 = (float10)playerobj_turn(iVar7,param_1[0x32]);

        if (ABS(fVar17) == (float10)0.0) {

LAB_004daadd:

          param_1[0x6a] = *(int *)(param_1[0x40] + 0x1ac);

        }

        else {

          param_1[0x56] = iVar7;

          param_1[0x36] = param_1[0x36] | 0x1000000;

          uVar4 = __ftol();

          *(undefined1 *)(param_1 + 0x82) = uVar4;

          if ((float)ABS(fVar17) < 2.0) goto LAB_004daadd;

          iVar7 = param_1[0x40];

          if ((param_1[0x38] & 0x200U) == 0) {

            if ((param_1[0x38] & 0x100U) == 0) {

              uVar20 = 0x52;

            }

            else {

              uVar20 = 0x9c;

            }

          }

          else {

            uVar20 = 0x91;

          }

          ai_anim_play(param_1,uVar20,1,0,0,0);

          param_1[0x6a] = (int)(*(float *)(iVar7 + 0x1ac) + *(float *)(iVar7 + 0x1ac));

        }

        if (*piVar15 == 0) {

LAB_004dab5a:

          fVar17 = (float10)FUN_00518b70(param_1,0);

          fVar17 = (float10)(float)piVar15[0x57] - fVar17;

          piVar15[0x57] = (int)(float)fVar17;

          if ((*(byte *)(param_1 + 0xc) & 2) != 0) {

            if ((param_1[0x38] & 0x4000U) == 0) {

              if (fVar17 < (float10)0.0 != (fVar17 == (float10)0.0)) {

                ai_damage_response(param_1,1,1,0);

              }

            }

            else {

              ai_damage_response(param_1,1,1,0);

            }

          }

        }

        else {

          param_1[0x38] = param_1[0x38] | 0x40;

          param_1[0x6a] = *(int *)(param_1[0x40] + 0x1ac);

          ai_d7_pairing(param_1,*(undefined4 *)(DAT_00632ed8 + 5000));

          param_1[0x39] = 0x69;

        }

        break;

      case 0x30:

        if (uVar6 != 0) {

          if ((param_1[4] != 0x98) && (*(int *)(param_1[2] + 0x268) != 0)) {

            ObjectSetAnim(param_1,0x98,0x21,0,(float)param_1[0x31] * 0.0,0x3e2aaaab);

          }

          param_1[0x39] = 0x67;

        }

        break;

      case 0x31:

        if (*(char *)param_1[0x41] < '\0') {

          fVar24 = (float)param_1[0x4c] - (float)param_1[0x4f];

          if ((char)((*(float *)(DAT_00632ed8 + 0xd78) <= fVar24) +

                    (*(float *)(DAT_00632ed8 + 0xd74) <= fVar24)) == '\0') {

            if ((param_1[4] != 0x99) && (*(int *)(param_1[2] + 0x26c) != 0)) {

              ObjectSetAnim(param_1,0x99,0x20,0,(float)param_1[0x31] * 0.0,0x3e2aaaab);

            }

            param_1[0x39] = 0x68;

          }

          else {

            obj_damage_apply(2,(fVar24 - *(float *)(DAT_00632ed8 + 0xd78)) *

                               *(float *)(DAT_00632ed8 + 0xd7c) + *(float *)(DAT_00632ed8 + 0xd88),

                             param_1,0,param_1 + 0x28,0);

            if ((param_1[4] != 0x3f) && (*(int *)(param_1[2] + 0x104) != 0)) {

              ObjectSetAnim(param_1,0x3f,0x20,0,(float)param_1[0x31] * 0.0,0x3e2aaaab);

            }

            param_1[0x39] = 0x5b;

          }

        }

        break;

      case 0x32:

        if (uVar6 != 0) {

          param_1[0x39] = 10;

        }

        break;

      case 0x33:

        if (*piVar15 != 0) {

          fVar17 = (float10)dirfcalcp3d__FP3P3DT0(param_1 + 0x28,*piVar15 + 0xa0);

          fVar18 = (float10)playerobj_turn((float)fVar17,param_1[0x32]);

          fVar24 = (float)ABS(fVar18);

          if (ABS(fVar18) == (float10)0.0) {

            fVar24 = 0.0;

          }

          else {

            param_1[0x56] = (int)(float)fVar17;

            param_1[0x36] = param_1[0x36] | 0x1000000;

            uVar4 = __ftol();

            *(undefined1 *)(param_1 + 0x82) = uVar4;

          }

          if (5.0 <= fVar24) {

            iVar7 = param_1[0x40];

            if ((param_1[0x38] & 0x200U) == 0) {

              if ((param_1[0x38] & 0x100U) == 0) {

                uVar20 = 0x52;

              }

              else {

                uVar20 = 0x9c;

              }

            }

            else {

              uVar20 = 0x91;

            }

            ai_anim_play(param_1,uVar20,1,0,0,0);

            param_1[0x6a] = (int)(*(float *)(iVar7 + 0x1ac) + *(float *)(iVar7 + 0x1ac));

          }

          else {

            param_1[0x6a] = *(int *)(param_1[0x40] + 0x1ac);

            iVar7 = rpman_verify_enemy__FP6OBJECTf(param_1);

            if (iVar7 != 0) break;

          }

          if (*piVar15 != 0) {

            param_1[0x38] = param_1[0x38] | 0x40;

            ai_d7_pairing(param_1,*(undefined4 *)(DAT_00632ed8 + 5000));

            if ((float)piVar15[8] < 0.0 != ((float)piVar15[8] == 0.0)) {

              param_1[0x6a] = *(int *)(param_1[0x40] + 0x1ac);

              rpman_shot(param_1);

            }

            break;

          }

        }

        param_1[0x6a] = *(int *)(param_1[0x40] + 0x1ac);

        param_1[0x39] = 100;

        break;

      case 0x34:

        uVar6 = param_1[0x38];

        cVar12 = (char)(uVar6 >> 8);

        if ((uVar6 & 0x100) == 0) {

          if ((uVar6 & 0x200) == 0) {

            if (cVar12 < '\0') {

              if ((param_1[4] != 0x30) && (*(int *)(param_1[2] + 200) != 0)) {

                fVar24 = (float)param_1[0x31] * 0.0;

                uVar20 = 0x30;

                goto LAB_004daead;

              }

            }

            else if ((param_1[4] != 0x9b) && (*(int *)(param_1[2] + 0x274) != 0)) {

              fVar24 = (float)param_1[0x31] * 0.0;

              uVar20 = 0x9b;

              goto LAB_004daead;

            }

          }

          else if (cVar12 < '\0') {

            if ((param_1[4] != 0x94) && (*(int *)(param_1[2] + 600) != 0)) {

              fVar24 = (float)param_1[0x31] * 0.0;

              uVar20 = 0x94;

              goto LAB_004daead;

            }

          }

          else if ((param_1[4] != 0x50) && (*(int *)(param_1[2] + 0x148) != 0)) {

            fVar24 = (float)param_1[0x31] * 0.0;

            uVar20 = 0x50;

            goto LAB_004daead;

          }

        }

        else if (cVar12 < '\0') {

          if ((param_1[4] != 0x77) && (*(int *)(param_1[2] + 0x1e4) != 0)) {

            fVar24 = (float)param_1[0x31] * 0.0;

            uVar20 = 0x77;

LAB_004daead:

            ObjectSetAnim(param_1,uVar20,0x21,0,fVar24,0x3e2aaaab);

          }

        }

        else if ((param_1[4] != 0x74) && (*(int *)(param_1[2] + 0x1d8) != 0)) {

          fVar24 = (float)param_1[0x31] * 0.0;

          uVar20 = 0x74;

          goto LAB_004daead;

        }

        param_1[0x39] = 0x69;

        break;

      case 0x35:

        ai_goal_process(param_1);

        if (param_1[0x5a] == 0) {

          fVar17 = (float10)rndfloatrange(0xc32a0000,0xc1200000);

          apiStack_1bc[1] = (int *)(float)(fVar17 + (float10)(float)param_1[0x32]);

          sine_cos_lookup(apiStack_1bc[1],&fStack_148,&fStack_124);

          fVar17 = (float10)rndfloatrange(*(undefined4 *)(DAT_00632ed8 + 0xc98),

                                          *(undefined4 *)(DAT_00632ed8 + 0xc9c));

          pfVar13 = (float *)(piVar15 + 2);

          *pfVar13 = (float)(fVar17 * (float10)fStack_124 + (float10)(float)piVar15[0x12]);

          fVar17 = (float10)rndfloatrange(*(undefined4 *)(DAT_00632ed8 + 0xc98),

                                          *(undefined4 *)(DAT_00632ed8 + 0xc9c));

          piVar15[3] = (int)(float)(fVar17 * (float10)fStack_148 + (float10)(float)piVar15[0x13]);

          fVar17 = (float10)dirfcalcp3d__FP3P3DT0(piVar15 + 0x12,pfVar13);

          apiStack_1bc[1] = (int *)(float)fVar17;

          piVar15[5] = (int)(float)fVar17;

          main_ai_move_004014b0(param_1,pfVar13,apiStack_1bc[1]);

          param_1[0x72] = param_1[0x72] & 0xfffff1ff;

          param_1[0x36] = param_1[0x36] & 0xffffffef;

          piVar15[0x17] = 0x40a00000;

          param_1[0x39] = 0x6f;

        }

        break;

      case 0x36:

        ai_goal_process(param_1);

        fVar17 = (float10)FUN_00518b70(param_1,0);

        fVar24 = (float)param_1[0x3b];

        param_1[0x3b] = (int)(float)((float10)fVar24 - fVar17);

        if ((float10)fVar24 - fVar17 < (float10)0.0) {

          rpman_scan_for_enemy__FP6OBJECTfii(param_1,piVar15[0x2b],1,0);

          param_1[0x3b] = 0x3f800000;

        }

        if (*piVar15 == 0) {

          if (param_1[0x5a] == 0) {

            param_1[0x3a] = 2;

            param_1[0x39] = 10;

          }

        }

        else {

          ai_d7_pairing(param_1,*(undefined4 *)(DAT_00632ed8 + 0xa20));

          param_1[0x39] = 0xc;

          param_1[0x3a] = 2;

        }

        break;

      case 0x37:

        iVar7 = param_1[0x9d];

        if ((iVar7 == 0) || (*(float *)(iVar7 + 0x1c0) <= *(float *)(iVar7 + 0x278))) {

          param_1[0x38] = param_1[0x38] | 0x20000;

          param_1[0x39] = 10;

        }

        else {

          ai_goal_process(param_1);

          if (param_1[0x5a] == 0) {

            param_1[0x72] = param_1[0x72] | 0xe00;

            param_1[0x36] = param_1[0x36] | 0x10;

            playerobj_eval_refpt(param_1[0x9d],0,auStack_f4);

            ai_move_force_goal(param_1,auStack_f4);

            param_1[0x39] = 0x71;

          }

        }

        break;

      case 0x38:

        iVar7 = param_1[0x9d];

        if ((iVar7 == 0) || (*(float *)(iVar7 + 0x1c0) <= *(float *)(iVar7 + 0x278))) {

          param_1[0x38] = param_1[0x38] | 0x20000;

          param_1[0x39] = 10;

          param_1[0x72] = param_1[0x72] & 0xfffff1ff;

          param_1[0x36] = param_1[0x36] & 0xffffffef;

        }

        else {

          ai_goal_process(param_1);

          if (param_1[0x5a] == 0) {

            *(int *)(param_1[0x9d] + 0xf4) = *(int *)(param_1[0x9d] + 0xf4) + 1;

            object_destroy(param_1);

          }

        }

        break;

      case 0x39:

        iVar7 = crt_rand_scaled(100);

        if (9 < iVar7) {

          iVar5 = 0x6e;

        }

        else {

          iVar5 = crt_rand_scaled(100);

          iVar5 = (0x31 < iVar5) + 0x6f;

        }

        if ((param_1[4] != iVar5) && (*(int *)(param_1[2] + 8 + iVar5 * 4) != 0)) {

          ObjectSetAnim(param_1,iVar5,9 < iVar7 | 0x20,0,(float)param_1[0x31] * 0.0,0x3e2aaaab);

        }

        param_1[0x39] = 0x79;

        break;

      case 0x3a:

        fVar17 = (float10)FUN_00518b70(param_1,0);

        fVar24 = (float)param_1[0x3b];

        param_1[0x3b] = (int)(float)((float10)fVar24 - fVar17);

        if ((float10)fVar24 - fVar17 < (float10)0.0) {

          rpman_scan_for_enemy__FP6OBJECTfii(param_1,piVar15[0x2b],1,0);

          param_1[0x3b] = 0x3f800000;

          iVar7 = crt_rand_scaled(100);

          if (iVar7 < 5) {

            if ((param_1[0x38] & 0x200U) == 0) {

              ai_anim_play(param_1,0x47,1,1,*(undefined4 *)(DAT_00632ed8 + 0xb38),0);

            }

            else if ((param_1[4] != 0x8e) && (*(int *)(param_1[2] + 0x240) != 0)) {

              ObjectSetAnim(param_1,0x8e,0x21,1,

                            *(float *)(DAT_00632ed8 + 0xb38) * (float)param_1[0x31],0x3e2aaaab);

              param_1[0x39] = 0x7a;

              break;

            }

            param_1[0x39] = 0x7a;

            break;

          }

        }

        fVar17 = (float10)FUN_00518b70(param_1,0);

        piVar15[0x3d] = (int)(float)((float10)(float)piVar15[0x3d] - fVar17);

        FUN_004e6670(param_1);

        if (*piVar15 != 0) {

          ai_d7_pairing(param_1,*(undefined4 *)(DAT_00632ed8 + 0xa20));

        }

        if (uVar6 != 0) {

          iVar7 = crt_rand_scaled(100);

          if (9 < iVar7) {

            iVar5 = 0x6e;

          }

          else {

            iVar5 = crt_rand_scaled(100);

            iVar5 = (0x31 < iVar5) + 0x6f;

          }

          if ((param_1[4] != iVar5) && (*(int *)(param_1[2] + 8 + iVar5 * 4) != 0)) {

            ObjectSetAnim(param_1,iVar5,9 < iVar7 | 0x20,0,(float)param_1[0x31] * 0.0,0x3e2aaaab);

          }

        }

        break;

      case 0x3b:

        fVar17 = (float10)rndfloatrange(-*(float *)(DAT_00632ed8 + 0xc88),

                                        *(undefined4 *)(DAT_00632ed8 + 0xc88));

        param_1[0x57] = (int)(float)(fVar17 + (float10)(float)piVar15[2]);

        fVar17 = (float10)rndfloatrange(-*(float *)(DAT_00632ed8 + 0xc88),

                                        *(undefined4 *)(DAT_00632ed8 + 0xc88));

        param_1[0x58] = (int)(float)(fVar17 + (float10)(float)piVar15[3]);

        param_1[0x59] = param_1[0x2a];

        param_1[0x5b] = (int)&LAB_004cb930;

        ai_moveonly_set_goal(param_1,param_1 + 0x57);

        param_1[0x39] = 0x7b;

        fVar17 = (float10)rndfloatrange(0x3f800000,0x40a00000);

        piVar15[0x17] = (int)(float)fVar17;

        break;

      case 0x3c:

        iVar7 = param_1[0x40];

        fVar17 = (float10)FUN_00518b70(param_1,0);

        fVar17 = (float10)*(float *)(iVar7 + 0x40) - fVar17;

        *(float *)(iVar7 + 0x40) = (float)fVar17;

        if (fVar17 < (float10)0.0) {

          fVar17 = (float10)rndfloatrange(0x41a00000,0x42c80000);

          *(float *)(iVar7 + 0x40) = (float)fVar17;

          uVar20 = rndintrange(0x7d,0x81);

          sound_play_obj(uVar20,param_1);

        }

        param_1[0x5b] = (int)&LAB_004cb930;

        ai_goal_process(param_1);

        fVar17 = (float10)FUN_00518b70(param_1,0);

        fVar24 = (float)piVar15[0x17];

        piVar15[0x17] = (int)(float)((float10)fVar24 - fVar17);

        if ((param_1[0x5a] == 0) || ((float10)fVar24 - fVar17 < (float10)0.0)) {

          ai_clear_move_goal(param_1);

          param_1[0x39] = 0x78;

        }

        fVar17 = (float10)FUN_00518b70(param_1,0);

        piVar15[0x3d] = (int)(float)((float10)(float)piVar15[0x3d] - fVar17);

        FUN_004e6670(param_1);

        break;

      case 0x3d:

        if (uVar6 != 0) {

          iVar7 = sound_obj_event(param_1 + 0x28);

          if (iVar7 == 0) {

            piVar15[0x3c] = piVar15[0x3c] + 1;

          }

          else {

            piVar15[0x3c] = 0;

          }

          if (*(int *)(DAT_00632ed8 + 0xc44) < piVar15[0x3c]) {

            piVar15[0x3c] = 0;

            fVar17 = (float10)rndfloatrange(0x3f800000,0x40a00000);

            piVar15[0x17] = (int)(float)fVar17;

            rpman_set_enemy_attack_goal__FP6OBJECTi(param_1,0);

            if ((param_1[0x38] & 0x200U) == 0) {

              ai_anim_play(param_1,0x47,1,1,*(undefined4 *)(DAT_00632ed8 + 0xb38),0);

            }

            else if ((param_1[4] != 0x8e) && (*(int *)(param_1[2] + 0x240) != 0)) {

              ObjectSetAnim(param_1,0x8e,0x21,1,

                            *(float *)(DAT_00632ed8 + 0xb38) * (float)param_1[0x31],0x3e2aaaab);

              param_1[0x39] = 0x7d;

              goto LAB_004da7ec;

            }

            param_1[0x39] = 0x7d;

          }

          else {

            param_1[0x39] = 0x78;

          }

LAB_004da7ec:

          fVar17 = (float10)rndfloatrange(*(undefined4 *)(DAT_00632ed8 + 0xc34),

                                          *(undefined4 *)(DAT_00632ed8 + 0xc38));

          piVar15[0x3d] = (int)(float)fVar17;

        }

        break;

      case 0x3e:

        iVar7 = rpman_verify_enemy__FP6OBJECTf(param_1,piVar15[0x28]);

        if (iVar7 == 0) {

          if (*piVar15 == 0) {

            piVar15[0x3c] = 0;

            param_1[0x39] = 0x78;

          }

          else {

            ai_d7_pairing(param_1,*(undefined4 *)(DAT_00632ed8 + 0xa20));

            param_1[0x5b] = (int)&LAB_004cb930;

            ai_goal_process(param_1);

            fVar17 = (float10)FUN_00518b70(param_1,0);

            fVar24 = (float)piVar15[0x17];

            piVar15[0x17] = (int)(float)((float10)fVar24 - fVar17);

            if ((param_1[0x5a] == 0) || ((float10)fVar24 - fVar17 < (float10)0.0)) {

              ai_clear_move_goal(param_1);

              iVar7 = *(int *)param_1[0x40];

              if (iVar7 == 0) {

LAB_004da987:

                uVar6 = param_1[0x38] | 2;

              }

              else {

                iVar5 = obj_is_pickup_4a(iVar7);

                if ((iVar5 == 0) && (iVar5 = obj_is_pickup_53(iVar7), iVar5 == 0)) {

                  iStack_1a0 = param_1[0x28];

                  iStack_19c = param_1[0x29];

                  fStack_198 = (float)param_1[0x7a] * (float)param_1[0x31] + (float)param_1[0x2a];

                  uStack_1ac = *(undefined4 *)(iVar7 + 0xa0);

                  uStack_1a8 = *(undefined4 *)(iVar7 + 0xa4);

                  fStack_1a4 = *(float *)(iVar7 + 0x1e8) * *(float *)(iVar7 + 0xc4) +

                               *(float *)(iVar7 + 0xa8);

                  if (param_1[0x84] == 0) {

                    uVar20 = 7;

                  }

                  else {

                    _DAT_00561494 = *(undefined4 *)(param_1[0x84] + 4);

                    uVar20 = 8;

                  }

                  iVar7 = ai_class_filter(&iStack_1a0,&uStack_1ac,uVar20,&DAT_00561478,0);

                  if (iVar7 == 0) goto LAB_004da987;

                }

                uVar6 = param_1[0x38] & 0xfffffffd;

              }

              param_1[0x38] = uVar6;

              if ((uVar6 & 2) == 0) {

                fVar17 = (float10)rndfloatrange(0x3f800000,0x40a00000);

                piVar15[0x17] = (int)(float)fVar17;

                rpman_set_enemy_attack_goal__FP6OBJECTi(param_1,1);

              }

              else {

                param_1[0x39] = 0x78;

              }

            }

          }

        }

        break;

      case 0x3f:

        if (param_1[0x84] == 0) {

          if ((param_1[4] != 0x67) && (*(int *)(param_1[2] + 0x1a4) != 0)) {

            ObjectSetAnim(param_1,0x67,0x20,0,(float)param_1[0x31] * 0.0,0x3e2aaaab);

          }

          param_1[0x39] = 0x83;

          fVar17 = (float10)rndfloatrange(0,0x41f00000);

          param_1[0x4c] = (int)(float)fVar17;

          fVar17 = (float10)rndfloat(0x43b40000);

          param_1[0x32] = (int)(float)fVar17;

          for (piVar15 = DAT_00632d68; piVar15 != (int *)0x0; piVar15 = (int *)*piVar15) {

            iVar7 = piVar15[3];

            if ((*(int *)(iVar7 + 4) == 0x2b2) && (*(int **)(iVar7 + 0x210) == param_1)) {

              anim_select_check(iVar7,0xb);

              break;

            }

          }

        }

        break;

      case 0x40:

        if (uVar6 != 0) {

          iVar7 = crt_rand_scaled(100);

          if (iVar7 < 0x14) {

            if ((param_1[4] != 0x69) && (*(int *)(param_1[2] + 0x1ac) != 0)) {

              fVar24 = (float)param_1[0x31];

              uVar20 = 0x69;

LAB_004d9fad:

              ObjectSetAnim(param_1,uVar20,0x21,0,fVar24 * 0.0,0x3e2aaaab);

            }

          }

          else if ((param_1[4] != 0x68) && (*(int *)(param_1[2] + 0x1a8) != 0)) {

            fVar24 = (float)param_1[0x31];

            uVar20 = 0x68;

            goto LAB_004d9fad;

          }

          param_1[0x39] = 0x84;

          param_1[0x3b] = 0x3f800000;

        }

        break;

      case 0x41:

        if ((float)param_1[0x4c] < -10.0) {

          param_1[0x4c] = -0x3ee00000;

        }

        *(undefined1 *)((int)param_1 + 0x20a) = 9;

        if (35.0 <= (float)param_1[0x2a] - (float)param_1[0x50]) {

          fVar17 = (float10)FUN_00518b70(param_1,0);

          fVar24 = (float)param_1[0x3b];

          param_1[0x3b] = (int)(float)((float10)fVar24 - fVar17);

          if ((float10)fVar24 - fVar17 < (float10)0.0) {

            iVar7 = 0x43a00000;

LAB_004dee82:

            rpman_scan_for_enemy__FP6OBJECTfii(param_1,iVar7,1,0);

            param_1[0x3b] = 0x3f800000;

          }

        }

        else {

          if (param_1[4] != 0x6b) {

            iVar7 = *(int *)(param_1[2] + 0x1b4);

LAB_004da0aa:

            if (iVar7 != 0) {

              ObjectSetAnim(param_1,0x6b,0x20,0,(float)param_1[0x31] * 0.0,0x3e2aaaab);

            }

          }

LAB_004da0d0:

          param_1[0x39] = 0x86;

        }

        break;

      case 0x42:

        if ((float)param_1[0x4c] < -10.0) {

          param_1[0x4c] = -0x3ee00000;

        }

        *(undefined1 *)((int)param_1 + 0x20a) = 9;

        if ((float)param_1[0x2a] - (float)param_1[0x50] < 35.0) {

          if (param_1[4] != 0x6b) {

            iVar7 = *(int *)(param_1[2] + 0x1b4);

            goto LAB_004da0aa;

          }

          goto LAB_004da0d0;

        }

        iVar7 = rpman_verify_enemy__FP6OBJECTf(param_1,0x43e10000);

        if (iVar7 == 0) {

          if (*piVar15 == 0) {

            iVar7 = crt_rand_scaled(100);

            if (iVar7 < 0x14) {

              if ((param_1[4] != 0x69) && (*(int *)(param_1[2] + 0x1ac) != 0)) {

                fVar24 = (float)param_1[0x31];

                uVar20 = 0x69;

LAB_004da168:

                ObjectSetAnim(param_1,uVar20,0x21,0,fVar24 * 0.0,0x3e2aaaab);

              }

            }

            else if ((param_1[4] != 0x68) && (*(int *)(param_1[2] + 0x1a8) != 0)) {

              fVar24 = (float)param_1[0x31];

              uVar20 = 0x68;

              goto LAB_004da168;

            }

            param_1[0x39] = 0x84;

          }

          else {

            ai_d7_pairing(param_1,*(undefined4 *)(DAT_00632ed8 + 0xa20));

            fVar17 = (float10)dirfcalcp3d__FP3P3DT0(param_1 + 0x28,*piVar15 + 0xa0);

            fVar18 = (float10)playerobj_turn((float)fVar17,param_1[0x32]);

            if (ABS(fVar18) != (float10)0.0) {

              param_1[0x56] = (int)(float)fVar17;

              param_1[0x36] = param_1[0x36] | 0x1000000;

              uVar4 = __ftol();

              *(undefined1 *)(param_1 + 0x82) = uVar4;

            }

          }

        }

        break;

      case 0x43:

        for (piVar15 = DAT_00632d68; piVar15 != (int *)0x0; piVar15 = (int *)*piVar15) {

          iVar7 = piVar15[3];

          if ((*(int *)(iVar7 + 4) == 0x2b2) && (*(int **)(iVar7 + 0x210) == param_1)) {

            object_change_ospec(iVar7,0x45);

            anim_select_check(iVar7,0xc);

            *(undefined4 *)(iVar7 + 0x210) = 0;

            *(undefined4 *)(iVar7 + 0xec) = *(undefined4 *)(iVar7 + 400);

            *(undefined4 *)(iVar7 + 0x10c) = *(undefined4 *)(iVar7 + 0x194);

            *(undefined4 *)(iVar7 + 0x108) = *(undefined4 *)(iVar7 + 0x1b8);

            fVar17 = (float10)rndfloat(0x43b40000);

            *(float *)(iVar7 + 200) = (float)fVar17;

          }

        }

        param_1[0x39] = 0x87;

      case 0x44:

        if (uVar6 != 0) {

          if ((param_1[4] != 0x6c) && (*(int *)(param_1[2] + 0x1b8) != 0)) {

            ObjectSetAnim(param_1,0x6c,0x21,0,(float)param_1[0x31] * 0.0,0x3e2aaaab);

          }

          param_1[0x39] = 0x88;

        }

        break;

      case 0x45:

        if (*(char *)param_1[0x41] < '\0') {

          if ((param_1[4] != 0x99) && (*(int *)(param_1[2] + 0x26c) != 0)) {

            ObjectSetAnim(param_1,0x99,0x21,0,(float)param_1[0x31] * 0.0,0x3e2aaaab);

          }

          param_1[0x39] = 0x89;

        }

        break;

      case 0x46:

        if (uVar6 != 0) {

          param_1[0x3a] = 0;

          param_1[0x39] = 10;

          param_1[0x38] = param_1[0x38] | 1;

        }

        break;

      case 0x47:

        rpboat_logic__FP6OBJECT(param_1,piVar15[0x50]);

        return;

      case 0x48:

        rpboat_logic__FP6OBJECT(param_1,0);

        return;

      case 0x49:

        obj_proximity_update(param_1);

        rpboat_logic__FP6OBJECT(param_1,piVar15[0x62]);

        return;

      case 0x4a:

        if (0.0 < (float)param_1[0x3b]) {

          fVar17 = (float10)FUN_00518b70(0,0);

          fVar17 = (float10)(float)param_1[0x3b] - fVar17;

          param_1[0x3b] = (int)(float)fVar17;

          if (fVar17 < (float10)0.0 != (fVar17 == (float10)0.0)) {

            ai_anim_play(param_1,0x71,0,0,0,0);

            param_1[0x39] = 0xa3;

          }

        }

        break;

      case 0x4b:

        if ((1.1666666 <= (float)param_1[5]) &&

           (piVar10 = DAT_00632d68, (float)param_1[6] < 1.1666666)) {

          for (; piVar10 != (int *)0x0; piVar10 = (int *)*piVar10) {

            iVar7 = piVar10[3];

            if (*(int *)(iVar7 + 4) == 0xd7) {

              if (*(int *)(iVar7 + 0xe4) == 0xa0) {

                sound_stop_obj(0x620,param_1);

                sound_play_obj(0x621,param_1);

                sound_play_obj(0x625,param_1);

                fVar17 = (float10)rndfloatrange(0x41200000,0x41a00000);

                piVar15[0x8f] = (int)(float)fVar17;

                *(undefined4 *)(iVar7 + 0xe4) = 0xa1;

              }

            }

            else {

              iVar5 = ObjIsJetski(iVar7);

              if (iVar5 != 0) {

                *(undefined4 *)(iVar7 + 0xfc) = 0;

              }

            }

          }

        }

        if ((((-1 < param_1[0x38]) && ((*(uint *)(DAT_00632a88 + 0x20c) & 0x20000) != 0)) &&

            (param_1[0x38] = param_1[0x38] | 0x80000000, 1.1666666 <= (float)param_1[5])) &&

           ((float)param_1[5] < 1.5 != ((float)param_1[5] == 1.5))) {

          piVar15 = (int *)(*(int *)(*(int *)(DAT_00632a88 + 0x210) + 0x100) + 0x74);

          *piVar15 = *piVar15 + 1;

        }

        if (uVar6 != 0) {

          ai_anim_play(param_1,0x50,1,0,0,0);

          param_1[0x39] = 0xa4;

        }

        break;

      case 0x4c:

        ai_goal_process(param_1);

        if (param_1[0x5a] == 0) {

          if (piVar15[0x54] == 0) goto LAB_004e0779;

          param_1[0x72] = param_1[0x72] | 0xe00;

          param_1[0x36] = param_1[0x36] | 0x10;

          (*(code *)PTR_crt_matrix_mul_00580c18)

                    (auStack_44,piVar15[0x54] + 0x294,

                     piVar15[0x55] * 0x44 + *(int *)(piVar15[0x54] + 0x2dc));

          uStack_100 = uStack_34;

          uStack_fc = uStack_24;

          uStack_f8 = uStack_14;

          fVar17 = (float10)tracer_entry_angle(piVar15[0x54],piVar15[0x55]);

          piVar15[0x56] = (int)(float)fVar17;

          ai_move_force_goal(param_1,&uStack_100);

          param_1[0x39] = 0xac;

        }

        break;

      case 0x4d:

        ai_goal_process(param_1);

        if (param_1[0x5a] == 0) {

          param_1[0x72] = param_1[0x72] & 0xfffff1ff;

          param_1[0x36] = param_1[0x36] & 0xffffffef;

          if (piVar15[0x54] == 0) goto LAB_004e0779;

          fVar17 = (float10)rndfloatrange(piVar15[0x25],piVar15[0x26]);

          piVar15[8] = (int)(float)fVar17;

          param_1[0x39] = 0xad;

          FUN_004e9ce0(piVar15[0x54],0,piVar15[0x55]);

        }

        break;

      case 0x4e:

        playerobj_eval_refpt(piVar15[0x54],piVar15[0x55],param_1 + 0x28);

        ai_rand_anim_select(param_1,1,1);

        param_1[0x39] = 0xae;

        break;

      case 0x4f:

        if (*piVar15 == 0) {

          FUN_00469950(param_1,piVar15[0x56]);

        }

        else {

          iVar7 = rpman_turn_towards(param_1,*piVar15 + 0xa0);

          if (iVar7 != 0) goto LAB_004e06b5;

        }

        break;

      case 0x50:

        if ((float)param_1[0x32] == (float)piVar15[0x56]) {

          ai_goal_process(param_1);

          if (param_1[0x5a] == 0) {

            if (piVar15[0x54] != 0) {

              *(undefined4 *)(piVar15[0x54] + 0x274) = 0;

            }

            param_1[0x72] = param_1[0x72] & 0xfffff1ff;

            param_1[0x36] = param_1[0x36] & 0xffffffef;

            param_1[0x3a] = 2;

            param_1[0x39] = 10;

          }

        }

        else {

          FUN_00469950(param_1,piVar15[0x56]);

        }

        break;

      case 0x51:

        if (uVar6 != 0) {

LAB_004e0779:

          param_1[0x3a] = 2;

          param_1[0x39] = 10;

        }

        break;

      case 0x52:

        FUN_004e7160(param_1,0);

        FUN_00469950(param_1,(float)param_1[0x32] + 70.0);

        break;

      case 0x53:

        ai_goal_process(param_1);

        if (param_1[0x5a] == 0) {

          param_1[0x72] = param_1[0x72] & 0xfffff1ff;

          param_1[0x36] = param_1[0x36] & 0xffffffef;

          playerobj_eval_refpt(piVar15[0x4d],piVar15[0x4e],auStack_b8);

          main_ai_move_004014b0(param_1,auStack_b8,*(undefined4 *)(piVar15[0x4d] + 200));

          param_1[0x39] = 0xc9;

        }

        break;

      case 0x54:

        if (*(int *)(*(int *)(piVar15[0x4d] + 0x100) + 0x10) == 0) {

          param_1[0x3a] = 2;

          rpman_scan_for_enemy__FP6OBJECTfii(param_1,0x42960000,1,0);

          param_1[0x3a] = 0x66;

          if (*piVar15 != 0) goto LAB_004db8dd;

        }

        else {

          rpman_scan_for_enemy__FP6OBJECTfii(param_1,piVar15[0x2b],1,1);

          if (*piVar15 != 0) {

LAB_004db899:

            param_1[0x39] = 0xd1;

            ai_clear_move_goal(param_1);

            break;

          }

        }

        ai_goal_process(param_1);

        if (param_1[0x5a] == 0) {

          *(int *)(*(int *)(piVar15[0x4d] + 0x100) + 8) =

               *(int *)(*(int *)(piVar15[0x4d] + 0x100) + 8) + 1;

          crt_rand_scaled(100);

          if ((param_1[0x38] & 0x200U) == 0) {

            ai_anim_play(param_1,0x50,1,0,0,0);

          }

          else if ((param_1[4] != 0x8c) && (*(int *)(param_1[2] + 0x238) != 0)) {

            ObjectSetAnim(param_1,0x8c,0x21,0,(float)param_1[0x31] * 0.0,0x3e2aaaab);

            param_1[0x39] = 0xca;

            break;

          }

          param_1[0x39] = 0xca;

        }

        break;

      case 0x55:

        param_1[0x3a] = 2;

        rpman_scan_for_enemy__FP6OBJECTfii(param_1,0x42960000,1,0);

        param_1[0x3a] = 0x66;

        if (*piVar15 == 0) {

          puVar14 = DAT_00632d6c;

          if (*(int *)(*(int *)(piVar15[0x4d] + 0x100) + 8) ==

              *(int *)(*(int *)(piVar15[0x4d] + 0x100) + 4)) {

            for (; puVar14 != (undefined4 *)0x0; puVar14 = (undefined4 *)*puVar14) {

              iVar7 = puVar14[3];

              if ((*(int *)(iVar7 + 4) == 0xd7) &&

                 (*(int *)(*(int *)(iVar7 + 0x100) + 0x134) == piVar15[0x4d])) {

                if ((param_1[0x38] & 0x2000000U) == 0) {

                  *(undefined4 *)(iVar7 + 0xe4) = 0xcb;

                }

                else {

                  *(undefined4 *)(*(int *)(iVar7 + 0x100) + 0xd8) = 1;

                  *(undefined4 *)(iVar7 + 0xe4) = 0xde;

                  *(uint *)(iVar7 + 0xd8) = *(uint *)(iVar7 + 0xd8) & 0xfff7ffff;

                }

                if (*(int *)(*(int *)(iVar7 + 0x100) + 0xd8) == 0) {

                  if ((*(uint *)(iVar7 + 0xe0) & 0x200) == 0) {

                    ai_anim_play(iVar7,0x53,1,1,

                                 *(float *)(DAT_00632ed8 + 0xb34) * *(float *)(iVar7 + 0xc4),1);

                  }

                  else {

                    fVar24 = *(float *)(DAT_00632ed8 + 0xb34);

                    fVar1 = *(float *)(iVar7 + 0xc4);

                    if ((*(int *)(iVar7 + 0x10) != 0x92) &&

                       (*(int *)(*(int *)(iVar7 + 8) + 0x250) != 0)) {

                      fVar17 = (float10)rndfloatrange(0,0x3f800000);

                      *(float *)(iVar7 + 0x14) = (float)fVar17;

                      ObjectSetAnim(iVar7,0x92,0x81,1,fVar24 * fVar1 * *(float *)(iVar7 + 0xc4),

                                    0x3e2aaaab);

                    }

                  }

                }

                else {

                  cleaner_process(iVar7,1);

                }

              }

            }

            *(undefined4 *)(piVar15[0x4d] + 0xe4) = 2;

          }

        }

        else {

LAB_004db8dd:

          ai_clear_move_goal(param_1);

LAB_004db8e6:

          if ((float)param_1[0x9e] < (float)param_1[0x70]) {

            rpman_notify_hit(param_1,0);

          }

        }

        break;

      case 0x56:

        param_1[0x3a] = 2;

        rpman_scan_for_enemy__FP6OBJECTfii(param_1,0x42960000,1,0);

        param_1[0x3a] = 0x66;

        if (*piVar15 != 0) goto LAB_004db8e6;

        if (((*(float *)(param_1[0x40] + 0x230) <= 0.0) && (DAT_005a8588 != 0)) &&

           (*(int *)(param_1[0x40] + 0xb0) == 0)) {

          iVar7 = 0;

          puVar14 = &DAT_005a8500;

          do {

            if (((float)puVar14[3] < 0.0 == ((float)puVar14[3] == 0.0)) &&

               (fVar17 = (float10)distancesq2d__FP3P3DT0(puVar14,param_1 + 0x28),

               fVar17 < (float10)40000.0)) break;

            puVar14 = puVar14 + 4;

            iVar7 = iVar7 + 1;

          } while ((int)puVar14 < 0x5a8550);

          if ((iVar7 < 5) && (apiStack_1bc[1] = (int *)param_1[0x40], apiStack_1bc[1][0x7c] != 0)) {

            *apiStack_1bc[1] = 0;

            fStack_1c8 = 160000.0;

            for (puVar14 = DAT_00632d80; puVar14 != (undefined4 *)0x0;

                puVar14 = (undefined4 *)*puVar14) {

              piVar10 = (int *)puVar14[3];

              apiStack_1bc[0] = piVar10;

              if (piVar10[1] == 0x325) {

                fVar17 = (float10)distancesq2d__FP3P3DT0(piVar10 + 0x28,param_1 + 0x28);

                if (fVar17 < (float10)fStack_1c8) {

                  iVar7 = obj_is_pickup_4a(apiStack_1bc[0]);

                  if ((iVar7 == 0) && (iVar7 = obj_is_pickup_53(apiStack_1bc[0]), iVar7 == 0)) {

                    iStack_194 = param_1[0x28];

                    iStack_190 = param_1[0x29];

                    fStack_18c = (float)param_1[0x7a] * (float)param_1[0x31] + (float)param_1[0x2a];

                    iStack_188 = piVar10[0x28];

                    iStack_184 = piVar10[0x29];

                    fStack_180 = (float)apiStack_1bc[0][0x7a] * (float)apiStack_1bc[0][0x31] +

                                 (float)piVar10[0x2a];

                    if (param_1[0x84] == 0) {

                      uVar20 = 7;

                    }

                    else {

                      _DAT_00561494 = *(undefined4 *)(param_1[0x84] + 4);

                      uVar20 = 8;

                    }

                    iVar7 = ai_class_filter(&iStack_194,&iStack_188,uVar20,&DAT_00561478,0);

                    if (iVar7 == 0) goto LAB_004dbf20;

                  }

                  *apiStack_1bc[1] = (int)apiStack_1bc[0];

                  fStack_1c8 = (float)fVar17;

                }

              }

LAB_004dbf20:

            }

          }

        }

        if (*piVar15 == 0) {

          iVar7 = ai_ground_snap(param_1);

          if (iVar7 != 0) {

            if ((param_1[0x38] & 0x100000U) != 0) {

              iVar5 = piVar15[0x7c];

              for (piVar10 = DAT_00632d68; piVar10 != (int *)0x0; piVar10 = (int *)*piVar10) {

                iVar8 = piVar10[3];

                iVar9 = ObjIsMyArmySpline__FP6OBJECTi(iVar8,*(undefined4 *)(iVar5 + 0xe8));

                if ((iVar9 != 0) && (*(int *)(iVar8 + 0x174) == *(int *)(iVar5 + 0x174) + -1)) {

                  param_1[0x38] = param_1[0x38] & 0xffefffff;

                  *(undefined4 *)(iVar8 + 0xf8) = 0;

                  break;

                }

              }

            }

            piVar15[0x7c] = iVar7;

            puVar14 = DAT_00632d6c;

            if (*(int *)(iVar7 + 0x174) == *(int *)(piVar15[0x7b] + 0x174) + -1) {

              for (; puVar14 != (undefined4 *)0x0; puVar14 = (undefined4 *)*puVar14) {

                iVar7 = puVar14[3];

                if ((*(int *)(iVar7 + 4) == 0xd7) &&

                   (*(int *)(*(int *)(iVar7 + 0x100) + 0x134) == piVar15[0x4d])) {

                  *(undefined4 *)(iVar7 + 0xe4) = 0xcd;

                }

              }

LAB_004dc35d:

              *(undefined4 *)(piVar15[0x4d] + 0xe4) = 3;

            }

            else if ((piVar15[0x2c] == 0) && ((*(byte *)(piVar15 + 0x6e) & 1) == 0)) {

              ai_damage_update(param_1,iVar7);

            }

          }

        }

        else {

LAB_004dc372:

          piVar15[0x7d] = param_1[0x39];

          ai_anim_play(param_1,0x51,0,0,0,0);

          param_1[0x39] = 0xd6;

        }

        break;

      case 0x57:

        if ((*(byte *)(piVar15 + 0x6e) & 4) != 0) {

          fVar17 = (float10)FUN_00518b70(param_1,0);

          fVar24 = (float)piVar15[0x6f];

          piVar15[0x6f] = (int)(float)((float10)fVar24 - fVar17);

          if ((float10)fVar24 - fVar17 < (float10)0.0) {

            piVar15[0x6e] = piVar15[0x6e] & 0xfffffffbU | 1;

          }

        }

        param_1[0x3a] = 2;

        rpman_scan_for_enemy__FP6OBJECTfii(param_1,0x42960000,1,0);

        param_1[0x3a] = 0x66;

        if (*piVar15 != 0) goto LAB_004db8e6;

        if ((piVar15[0x2c] == 0) && (piVar10 = DAT_00632d68, (*(byte *)(piVar15 + 0x6e) & 1) != 0))

        {

          for (; piVar10 != (int *)0x0; piVar10 = (int *)*piVar10) {

            iVar7 = piVar10[3];

            if (*(int *)(iVar7 + 4) == 0xd7) {

              iVar5 = *(int *)(iVar7 + 0x100);

              if (*(int *)(iVar5 + 0x134) == piVar15[0x4d]) {

                *(uint *)(iVar5 + 0x1b8) = *(uint *)(iVar5 + 0x1b8) | 1;

                ai_idle_anim_53(iVar7,0);

                *(undefined4 *)(iVar7 + 0xe4) = 0xcf;

              }

            }

            else {

              iVar5 = ObjIsMyArmySpline__FP6OBJECTi(iVar7,*(undefined4 *)(piVar15[0x7c] + 0xe8));

              if ((iVar5 != 0) && (*(int *)(iVar7 + 0x174) == *(int *)(piVar15[0x7c] + 0x174) + -1))

              {

                *(undefined4 *)(iVar7 + 0xf8) = 0;

              }

            }

          }

          *(undefined4 *)(piVar15[0x4d] + 0xe4) = 2;

        }

        break;

      case 0x58:

        if ((*(byte *)(piVar15 + 0x6e) & 2) == 0) {

          fVar17 = (float10)FUN_00518b70(param_1,0);

          fVar17 = (float10)(float)piVar15[0x17] - fVar17;

          piVar15[0x17] = (int)(float)fVar17;

          if (fVar17 < (float10)0.0 != (fVar17 == (float10)0.0)) {

            ai_clear_move_goal(param_1);

          }

          if (param_1[0x5a] == 0) {

            fVar17 = (float10)rndfloatrange(0x41200000,0x41f00000);

            fVar18 = (float10)rndfloatrange(0,0x43b40000);

            apiStack_1bc[1] = (int *)(float)fVar18;

            sine_cos_lookup(apiStack_1bc[1],&fStack_134,&fStack_168);

            fStack_10c = fStack_134 * (float)fVar17 + *(float *)(piVar15[0x7b] + 0xa0);

            fStack_108 = *(float *)(piVar15[0x7b] + 0xa4) - fStack_168 * (float)fVar17;

            uStack_104 = *(undefined4 *)(piVar15[0x7b] + 0xa8);

            param_1[0x5b] = (int)&LAB_004cb930;

            ai_moveonly_set_goal(param_1,&fStack_10c);

            rpman_sniper_anim_set(param_1);

            rpman_scan_for_enemy__FP6OBJECTfii(param_1,piVar15[0x2b],0,1);

            piVar15[0x17] = 0x3fc00000;

          }

          else {

            ai_goal_process(param_1);

            if ((param_1[0x5a] == 0) || ((float)piVar15[0xd] < 900.0)) {

              piVar15[0x6e] = piVar15[0x6e] | 2;

              param_1[0x39] = 0xce;

            }

          }

        }

        else {

          param_1[0x39] = 0xd3;

        }

        break;

      case 0x59:

        if ((param_1[0x38] & 0x1000000U) == 0) {

          rpman_scan_for_enemy__FP6OBJECTfii(param_1,piVar15[0x2b],1,1);

          if (*piVar15 != 0) {

            iVar7 = *(int *)(*piVar15 + 0x1e0);

            goto LAB_004dc633;

          }

LAB_004dc53c:

          rpman_army_goto_firepit__FP6OBJECT(param_1);

        }

        else {

          piVar15[0x17] = 0x3f800000;

          param_1[0x39] = 0xdc;

        }

        break;

      case 0x5a:

        param_1[0x3a] = 2;

        rpman_scan_for_enemy__FP6OBJECTfii(param_1,0x42960000,1,0);

        param_1[0x3a] = 0x66;

        if (*piVar15 != 0) goto LAB_004db8e6;

        iVar7 = FUN_004e3730(param_1);

        if (iVar7 != 0) {

          ai_radius_scan(param_1,0x43c80000);

        }

        if (*piVar15 != 0) goto LAB_004dc372;

        iVar7 = ai_ground_snap(param_1);

        if (iVar7 != 0) {

          if ((param_1[0x38] & 0x100000U) != 0) {

            FUN_004e7330(param_1,piVar15[0x7c]);

          }

          piVar15[0x7c] = iVar7;

          puVar14 = DAT_00632d6c;

          if (*(int *)(iVar7 + 0x174) == *(int *)(piVar15[0x7b] + 0x174) + -1) {

            for (; puVar14 != (undefined4 *)0x0; puVar14 = (undefined4 *)*puVar14) {

              iVar7 = puVar14[3];

              if ((*(int *)(iVar7 + 4) == 0xd7) &&

                 (*(int *)(*(int *)(iVar7 + 0x100) + 0x134) == piVar15[0x4d])) {

                *(undefined4 *)(iVar7 + 0xe4) = 0xcd;

              }

            }

            goto LAB_004dc35d;

          }

        }

        break;

      case 0x5b:

        iVar7 = rpman_verify_enemy__FP6OBJECTf(param_1,piVar15[0x28]);

        if (iVar7 == 0) {

          iVar7 = *piVar15;

          if (iVar7 != 0) {

            if ((float)piVar15[8] < 0.0 == ((float)piVar15[8] == 0.0)) {

              iVar7 = obj_is_pickup_4a_model(iVar7);

              if ((iVar7 == 0) && (iVar7 = obj_is_pickup_53_model(*piVar15), iVar7 == 0)) {

                param_1[0x39] = 0xce;

              }

              break;

            }

            if (((float)piVar15[0xd] < (float)piVar15[0x2a] * (float)piVar15[0x2a]) &&

               ((*(byte *)(param_1 + 0x38) & 2) == 0)) {

              iVar7 = iVar7 + 0xa0;

              goto LAB_004decf7;

            }

          }

LAB_004e019c:

          param_1[0x39] = 0xce;

        }

        break;

      case 0x5c:

        iVar7 = rpman_verify_enemy__FP6OBJECTf(param_1,piVar15[0x28]);

        if (iVar7 == 0) {

          if (*piVar15 == 0) goto LAB_004e019c;

          if (((float)piVar15[0xd] < (float)piVar15[0x29] * (float)piVar15[0x29]) ||

             (iVar7 = ObjIsPlayer(*piVar15), iVar7 == 0)) {

            fVar17 = (float10)rndfloatrange(0x3f800000,0x40a00000);

            piVar15[0x17] = (int)(float)fVar17;

            rpman_set_enemy_attack_goal__FP6OBJECTi(param_1,0);

            param_1[0x38] = param_1[0x38] & 0xbfffffff;

            rpman_sniper_anim_set(param_1);

            param_1[0x39] = 0xd2;

          }

          else {

            ai_damage_response(param_1,0,0,0);

            param_1[0x39] = 0xce;

          }

        }

        break;

      case 0x5d:

        iVar7 = rpman_verify_enemy__FP6OBJECTf(param_1,piVar15[0x28]);

        if (iVar7 == 0) {

          iVar7 = *piVar15;

          if (iVar7 != 0) {

            if ((*(int *)(iVar7 + 0x1e0) != 0x12) || (*(int *)(iVar7 + 0xe8) != 10)) {

              ai_d7_pairing(param_1,*(undefined4 *)(DAT_00632ed8 + 0xa20));

              rpman_consider_run_chatter__FP6OBJECT(param_1);

              param_1[0x5b] = (int)&LAB_004cb930;

              ai_get_goal_location(param_1,auStack_c4);

              iVar7 = ai_goal_process(param_1);

              if (iVar7 == -1) {

                ai_move_force_goal(param_1,auStack_c4);

                ai_goal_process(param_1);

                piVar15[0x17] = 0x3f800000;

              }

              fVar17 = (float10)FUN_00518b70(param_1,0);

              fVar24 = (float)piVar15[0x17];

              piVar15[0x17] = (int)(float)((float10)fVar24 - fVar17);

              if ((param_1[0x5a] == 0) || ((float10)fVar24 - fVar17 < (float10)0.0)) {

                ai_clear_move_goal(param_1);

                if (((float)piVar15[0xd] < (float)piVar15[0x2a] * (float)piVar15[0x2a]) &&

                   (((float)piVar15[8] < 0.0 != ((float)piVar15[8] == 0.0) &&

                    ((*(byte *)(param_1 + 0x38) & 2) == 0)))) {

                  iVar7 = *piVar15 + 0xa0;

                  goto LAB_004decf7;

                }

                rpman_sniper_anim_set(param_1);

                fVar17 = (float10)rndfloatrange(0x3f800000,0x40a00000);

                piVar15[0x17] = (int)(float)fVar17;

                iVar7 = ObjIsPlayer(*piVar15);

                if (iVar7 == 0) {

                  rpman_set_enemy_attack_goal__FP6OBJECTi(param_1,0);

                }

                else {

                  rpman_set_enemy_attack_goal__FP6OBJECTi(param_1,1);

                }

              }

              break;

            }

            *piVar15 = 0;

          }

          ai_damage_response(param_1,0,0,0);

          param_1[0x39] = 0xce;

        }

        break;

      case 0x5e:

        if (*piVar15 == 0) {

          rpman_scan_for_enemy__FP6OBJECTfii(param_1,piVar15[0x2b],0,1);

        }

        else {

          iVar7 = rpman_verify_enemy__FP6OBJECTf(param_1,piVar15[0x28]);

          if (iVar7 != 0) break;

        }

        if (*piVar15 == 0) goto LAB_004e019c;

        fVar17 = (float10)rndfloatrange(0x3f800000,0x40a00000);

        piVar15[0x17] = (int)(float)fVar17;

        rpman_set_enemy_attack_goal__FP6OBJECTi(param_1,0);

        rpman_sniper_anim_set(param_1);

        param_1[0x39] = 0xd4;

        break;

      case 0x5f:

        iVar7 = rpman_verify_enemy__FP6OBJECTf(param_1,piVar15[0x28]);

        if (iVar7 == 0) {

          if (*piVar15 != 0) {

            param_1[0x5b] = (int)&LAB_004cb930;

            iVar7 = ai_goal_process(param_1);

            if (iVar7 == -1) {

              fVar17 = (float10)rndfloatrange(0x41a00000,0x42480000);

              fVar18 = (float10)rndfloatrange(0,0x43b40000);

              apiStack_1bc[1] = (int *)(float)fVar18;

              sine_cos_lookup(apiStack_1bc[1],&fStack_12c,&fStack_158);

              fStack_118 = fStack_12c * (float)fVar17 + *(float *)(piVar15[0x7b] + 0xa0);

              fStack_114 = *(float *)(piVar15[0x7b] + 0xa4) - fStack_158 * (float)fVar17;

              uStack_110 = *(undefined4 *)(piVar15[0x7b] + 0xa8);

              param_1[0x5b] = (int)&LAB_004cb930;

              ai_moveonly_set_goal(param_1,&fStack_118);

              iVar7 = ai_goal_process(param_1);

              if (iVar7 == -1) {

                ai_move_force_goal(param_1,&fStack_118);

                ai_goal_process(param_1);

                piVar15[0x17] = 0x3f800000;

              }

            }

            fVar17 = (float10)FUN_00518b70(param_1,0);

            fVar24 = (float)piVar15[0x17];

            piVar15[0x17] = (int)(float)((float10)fVar24 - fVar17);

            if ((param_1[0x5a] != 0) && ((float10)0.0 <= (float10)fVar24 - fVar17)) break;

            ai_clear_move_goal(param_1);

            if (((float)piVar15[0xd] < (float)piVar15[0x2a] * (float)piVar15[0x2a]) &&

               (((float)piVar15[8] < 0.0 != ((float)piVar15[8] == 0.0) &&

                ((*(byte *)(param_1 + 0x38) & 2) == 0)))) {

              rpman_scan_for_enemy__FP6OBJECTfii(param_1,piVar15[0x2b],0,1);

              if (*piVar15 != 0) {

                iVar7 = *piVar15 + 0xa0;

                goto LAB_004decf7;

              }

            }

          }

          param_1[0x39] = 0xd3;

        }

        break;

      case 0x60:

        param_1[0x3a] = 2;

        rpman_scan_for_enemy__FP6OBJECTfii(param_1,0x42960000,1,0);

        param_1[0x3a] = 0x66;

        if (*piVar15 != 0) goto LAB_004db8e6;

        if ((piVar15[0x2c] == 0) &&

           (piVar10 = DAT_00632d68, *(float *)(piVar15[0x7c] + 0xf8) == 0.0)) {

          for (; piVar10 != (int *)0x0; piVar10 = (int *)*piVar10) {

            iVar7 = piVar10[3];

            if (*(int *)(iVar7 + 4) == 0xd7) {

              if (*(int *)(*(int *)(iVar7 + 0x100) + 0x134) == piVar15[0x4d]) {

                ai_idle_anim_53(iVar7,0);

                *(undefined4 *)(iVar7 + 0xe4) = 0xcb;

              }

            }

            else {

              iVar5 = ObjIsMyArmySpline__FP6OBJECTi(iVar7,*(undefined4 *)(piVar15[0x7c] + 0xe8));

              if ((iVar5 != 0) && (*(int *)(iVar7 + 0x174) == *(int *)(piVar15[0x7c] + 0x174) + -1))

              {

                *(undefined4 *)(iVar7 + 0xf8) = 0;

              }

            }

          }

          goto LAB_004dc268;

        }

        break;

      case 0x61:

        piVar10 = (int *)ai_ground_snap(param_1);

        apiStack_1bc[1] = piVar10;

        if (piVar10 != (undefined4 *)0x0) {

          if ((param_1[0x38] & 0x100000U) != 0) {

            FUN_004e7330(param_1,piVar15[0x7c]);

          }

          piVar15[0x7c] = (int)piVar10;

          if (piVar10[0x5d] == *(int *)(piVar15[0x7b] + 0x174) + -1) {

            piVar15[0x7d] = 0xcd;

          }

          else {

            piVar15[0x50] = piVar10[0x3f];

            if (0.0 < (float)piVar10[0x3e]) {

              if (*(int *)(piVar10[0x40] + 0x5c) == 0) {

                piVar15[0x7d] = 0xcc;

              }

              else {

                piVar15[0x7d] = 0xd5;

              }

            }

          }

        }

        puVar14 = DAT_00632d6c;

        if (uVar6 != 0) {

          for (; puVar14 != (undefined4 *)0x0; puVar14 = (undefined4 *)*puVar14) {

            piVar2 = (int *)puVar14[3];

            if (piVar2[1] == 0xd7) {

              iVar7 = piVar2[0x40];

              if (*(int *)(iVar7 + 0x134) == piVar15[0x4d]) {

                *(int *)(iVar7 + 0x1f8) = piVar2[0x32];

                if (piVar2 != param_1) {

                  *(int *)(iVar7 + 500) = piVar2[0x39];

                }

                ai_radius_scan(param_1,0x44480000);

                if (*piVar15 == 0) {

                  piVar2[0x39] = 0xda;

                }

                else {

                  *(undefined4 *)(iVar7 + 0x230) = 0x41f00000;

                  piVar2[0x39] = 0xd7;

                  piVar2[0x38] = piVar2[0x38] | 0x80000;

                }

              }

            }

            else if (((piVar2[1] == 0x48a) && (piVar2[0x3a] == *(int *)(piVar15[0x7c] + 0xe8))) &&

                    (piVar2[0x5d] == *(int *)(piVar15[0x7c] + 0x174) + -1)) {

              *(undefined4 *)(piVar2[0x40] + 0x5c) = 1;

              piVar10[0x3e] = 0x4426aaa0;

            }

            piVar10 = apiStack_1bc[1];

          }

          goto LAB_004de04c;

        }

        break;

      case 0x62:

        if ((float)piVar15[0x8c] < 0.0) {

LAB_004e00f0:

          param_1[0x39] = 0xda;

        }

        else {

          iVar7 = *piVar15;

          if (iVar7 == 0) {

            ai_radius_scan(param_1,0x44480000);

            iVar7 = *piVar15;

            if (iVar7 == 0) goto LAB_004e00f0;

          }

          iVar7 = iVar7 + 0xa0;

LAB_004decf7:

          fVar17 = (float10)obj_turn_toward_point(param_1,iVar7);

          if ((float10)5.0 <= fVar17) goto LAB_004ded23;

LAB_004ded0d:

          FUN_004e7160(param_1,1);

          rpman_shot(param_1);

        }

        break;

      case 99:

        if (*piVar15 == 0) {

          ai_radius_scan(param_1,0x44480000);

          param_1[0x39] = (-(uint)(*piVar15 != 0) & 0xfffffffd) + 0xda;

        }

        else {

LAB_004e06b5:

          if ((float)piVar15[8] < 0.0 != ((float)piVar15[8] == 0.0)) {

            rpman_shot(param_1);

          }

        }

        break;

      case 100:

        puVar14 = DAT_00632d6c;

        if (piVar15[0x2c] == 0) {

          for (; puVar14 != (undefined4 *)0x0; puVar14 = (undefined4 *)*puVar14) {

            iVar7 = puVar14[3];

            if (((*(int *)(iVar7 + 4) == 0xd7) &&

                (*(int *)(*(int *)(iVar7 + 0x100) + 0x134) == piVar15[0x4d])) &&

               (*(int *)(iVar7 + 0xe4) != 0xd9)) goto LAB_004e0a56;

          }

          param_1[0x38] = param_1[0x38] | 0x100000;

          apiStack_1bc[0] = DAT_00632d68;

          if (DAT_00632d68 != (int *)0x0) {

            do {

              iVar7 = apiStack_1bc[0][3];

              if (*(int *)(iVar7 + 4) == 0xd7) {

                iVar5 = *(int *)(iVar7 + 0x100);

                if (*(int *)(iVar5 + 0x134) == piVar15[0x4d]) {

                  if (piVar15[0x7d] != 0xcd) {

                    ai_idle_anim_53(iVar7,1);

                  }

                  *(int *)(iVar7 + 0xe4) = piVar15[0x7d];

                  *(undefined4 *)(iVar5 + 0x230) = 0x41200000;

                }

              }

              else if (((*(int *)(iVar7 + 4) == 0x48a) && (piVar15[0x7d] != 0xcd)) &&

                      ((*(int *)(iVar7 + 0xe8) == *(int *)(piVar15[0x7c] + 0xe8) &&

                       (*(int *)(iVar7 + 0x174) == *(int *)(piVar15[0x7c] + 0x174) + -1)))) {

                param_1[0x38] = param_1[0x38] & 0xffefffff;

                *(undefined4 *)(iVar7 + 0xf8) = 0;

              }

              apiStack_1bc[0] = (int *)*apiStack_1bc[0];

            } while (apiStack_1bc[0] != (int *)0x0);

            apiStack_1bc[0] = (int *)0x0;

          }

LAB_004dc268:

          *(undefined4 *)(piVar15[0x4d] + 0xe4) = 2;

        }

        break;

      case 0x65:

        fVar17 = (float10)FUN_00469950(param_1,piVar15[0x7e]);

        if (fVar17 == (float10)0.0) {

          FUN_004e7160(param_1,1);

          ai_rand_anim_select(param_1,0,0);

          param_1[0x39] = 0xd9;

        }

        else {

LAB_004ded23:

          FUN_004e7160(param_1,0);

        }

        break;

      case 0x66:

        rpman_sniper_anim_set(param_1);

        ai_goal_process(param_1);

        fVar17 = (float10)FUN_0050a610(param_1 + 0x28,*piVar15 + 0xa0);

        if (param_1[0x5a] == 0) {

          if (fVar17 < (float10)100.0) goto LAB_004dcef8;

          DAT_005a8578 = (int *)0x0;

          param_1[0x38] = param_1[0x38] & 0xfeffffff;

          piVar15[0x83] = 0;

          iVar7 = *piVar15;

          if (((iVar7 == 0) || (*(int *)(iVar7 + 0x1e0) != 0x12)) || (*(int *)(iVar7 + 0xe8) != 10))

          goto LAB_004e019c;

          *piVar15 = 0;

          param_1[0x39] = 0xce;

        }

        else if (fVar17 < (float10)100.0) {

LAB_004dcef8:

          piVar15[0x83] = *piVar15;

          *piVar15 = 0;

          rpman_set_smartie_goal__FP6OBJECT(param_1);

          smartie_board_player__FP6OBJECTT0i(piVar15[0x83],param_1,0);

          piVar15[0x17] = 0x3f800000;

          param_1[0x39] = 0xe4;

          iVar7 = ObjIsMecc(DAT_00632a88);

          if (iVar7 == 0) {

            uVar20 = FUN_00507b00(s_SmChYanSteal_00561a74,4,0);

            chat_insert_name(&DAT_0055b3bc,uVar20);

            teammecc_clear_mode(s_DElCT24_2_00561a68,*(undefined4 *)(DAT_006330e4 + 0x50e0),0);

          }

          else {

            uVar20 = FUN_00507b00(s_SmChBorjoyzeeSteal_00561a9c,4,0);

            chat_insert_name(s_Borjoyzee_0055b3c0,uVar20);

            iVar7 = crt_rand_scaled(100);

            if (iVar7 < 0x32) {

              teammecc_clear_mode(s_GORCT23_2_00561a90,*(undefined4 *)(DAT_006330e4 + 0x50e0),0);

            }

            else {

              teammecc_clear_mode(s_REG_CT23_00561a84,*(undefined4 *)(DAT_006330e4 + 0x50e0),0);

            }

          }

          fStack_1c8 = 0.0;

          apiStack_1bc[0] = (int *)0x0;

          if (DAT_00632d6c != (undefined4 *)0x0) {

            piStack_1c0 = piVar15 + 0x8a;

            puVar14 = DAT_00632d6c;

            do {

              piVar10 = (int *)puVar14[3];

              if (((piVar10[1] == 0xd7) && (piVar10[0x3a] == 0x66)) &&

                 ((piVar10 != param_1 && (piVar10[0x39] != 0xde)))) {

                if ((piVar10[0x38] & 0x400U) == 0) {

                  fVar17 = (float10)distancesq2d__FP3P3DT0(piVar10 + 0x28,param_1 + 0x28);

                  if ((fVar17 < (float10)40000.0) && ((int)apiStack_1bc[0] < 2)) {

                    apiStack_1bc[(int)apiStack_1bc[0] + 1] = piVar10;

                    apiStack_1bc[0] = (int *)((int)apiStack_1bc[0] + 1);

                  }

                }

                else {

                  fVar17 = (float10)distancesq2d__FP3P3DT0(piVar10 + 0x28,param_1 + 0x28);

                  if (fVar17 < (float10)40000.0) {

                    puVar3 = (undefined4 *)piVar10[0x40];

                    *puVar3 = 0;

                    puVar3[0x8a] = param_1;

                    fVar17 = (float10)rndfloatrange(0x3f800000,0x40000000);

                    puVar3[0x17] = (float)fVar17;

                    ai_move_force_goal(piVar10,param_1 + 0x28);

                    cleaner_process(piVar10,0);

                    piVar10[0x39] = 0xe1;

                    fStack_1c8 = (float)((int)fStack_1c8 + 1);

                    *piStack_1c0 = (int)piVar10;

                    piStack_1c0 = piStack_1c0 + 1;

                    if (1 < (int)fStack_1c8) break;

                  }

                }

              }

              puVar14 = (undefined4 *)*puVar14;

            } while (puVar14 != (undefined4 *)0x0);

            if (1 < (int)fStack_1c8) break;

          }

          ppiStack_1c4 = apiStack_1bc + (int)apiStack_1bc[0];

          piVar15 = piVar15 + (int)fStack_1c8 + 0x8a;

          do {

            if ((int)apiStack_1bc[0] < 1) break;

            piVar10 = *ppiStack_1c4;

            puVar14 = (undefined4 *)piVar10[0x40];

            puVar14[0x6e] = puVar14[0x6e] & 0xfffffffd;

            *puVar14 = 0;

            puVar14[0x8a] = param_1;

            fVar17 = (float10)rndfloatrange(0x3f800000,0x40000000);

            puVar14[0x17] = (float)fVar17;

            ai_move_force_goal(piVar10,param_1 + 0x28);

            rpman_sniper_anim_set(piVar10);

            piVar10[0x39] = 0xe2;

            *piVar15 = (int)piVar10;

            fStack_1c8 = (float)((int)fStack_1c8 + 1);

            piVar15 = piVar15 + 1;

            apiStack_1bc[0] = (int *)((int)apiStack_1bc[0] + -1);

            ppiStack_1c4 = ppiStack_1c4 + -1;

          } while ((int)fStack_1c8 < 2);

        }

        break;

      case 0x67:

        rpman_sniper_anim_set(param_1);

        rpman_scan_for_enemy__FP6OBJECTfii(param_1,0x42960000,0,1);

        if ((*piVar15 == 0) ||

           (fVar17 = (float10)distancesq2d__FP3P3DT0(param_1 + 0x28,*piVar15 + 0xa0),

           (float10)5625.0 <= fVar17)) {

          if (((float)param_1[0x3b] < 0.0) || (*piVar15 != 0)) {

            *piVar15 = 0;

            ai_clear_move_goal(param_1);

            rpman_set_smartie_goal__FP6OBJECT(param_1);

            param_1[0x72] = param_1[0x72] & 0xfffffbff;

          }

          ai_goal_process(param_1);

          if (param_1[0x5a] == 0) {

            fVar17 = (float10)distance3d__FP3P3DT0

                                        (param_1 + 0x28,

                                         *(int *)(*(int *)(piVar15[0x4d] + 0x100) + 0x18) + 0xa0);

            if ((float10)100.0 <= fVar17) {

              rpman_set_smartie_goal__FP6OBJECT(param_1);

              ai_goal_process(param_1);

              if ((param_1[0x5a] == 0) &&

                 (rpman_scan_for_enemy__FP6OBJECTfii(param_1,piVar15[0x2b],0,1), *piVar15 != 0)) {

                piVar15[8] = 0;

                param_1[0x39] = 0xd0;

                param_1[0x72] = param_1[0x72] & 0xfffffbff;

              }

            }

            else {

              ai_rand_anim_select(param_1,0,0);

              param_1[0x39] = 0xdd;

            }

          }

        }

        else {

          if (piVar15[0x8a] != 0) {

            **(int **)(piVar15[0x8a] + 0x100) = *piVar15;

          }

          if (piVar15[0x8b] != 0) {

            **(int **)(piVar15[0x8b] + 0x100) = *piVar15;

          }

LAB_004dd3aa:

          ai_clear_move_goal(param_1);

          piVar15[8] = 0;

          param_1[0x72] = param_1[0x72] & 0xfffffbff;

          param_1[0x39] = 0xd0;

        }

        break;

      case 0x68:

        voice_quota_check();

        break;

      case 0x69:

        if ((*(byte *)(param_1 + 0xc) & 2) != 0) {

          cleaner_process(param_1,0);

        }

        iVar7 = ai_ground_snap(param_1);

        if ((iVar7 != 0) && (*(int *)(iVar7 + 0x174) == *(int *)(piVar15[0x7b] + 0x174))) {

          object_destroy(param_1);

          piVar10 = (int *)(*(int *)(piVar15[0x4d] + 0x100) + 8);

          *piVar10 = *piVar10 + -1;

          formation_notify_death(piVar15[0x4d]);

        }

        if (piVar15[0x2c] == 0) {

          if (*piVar15 == 0) {

            rpman_scan_for_enemy__FP6OBJECTfii(param_1,piVar15[0x86],1,1);

            *(int *)(piVar15[0x4d] + 0x274) = *piVar15;

            if (*piVar15 == 0) break;

            piVar15[0x84] = piVar15[0x85];

            goto LAB_004dbc0d;

          }

        }

        else {

          if (*piVar15 != *(int *)(piVar15[0x4d] + 0x274)) {

            piVar15[0x84] = piVar15[0x85];

          }

          *piVar15 = *(int *)(piVar15[0x4d] + 0x274);

LAB_004dbc0d:

          if (*piVar15 == 0) break;

        }

        fVar17 = (float10)FUN_00518b70(param_1,0);

        fVar17 = fVar17 * (float10)(float)piVar15[0x87] + (float10)(float)piVar15[0x84];

        piVar15[0x84] = (int)(float)fVar17;

        if ((float10)(float)piVar15[0x88] < fVar17) {

          piVar15[0x84] = piVar15[0x88];

        }

        playerobj_eval_refpt(param_1[0x9d],2,&fStack_164);

        piVar15[10] = (int)((*(float *)(*piVar15 + 0xa0) - fStack_164) * (float)piVar15[0x84] +

                           fStack_164);

        piVar15[0xb] = (int)((*(float *)(*piVar15 + 0xa4) - fStack_160) * (float)piVar15[0x84] +

                            fStack_160);

        fVar17 = (float10)get_floor_z_point(piVar15 + 10);

        piVar15[0xc] = (int)(float)fVar17;

        fVar17 = (float10)dirucalcp3d__FP3P3DT0(&fStack_164,*piVar15 + 0xa0);

        if ((fVar17 < (float10)*(float *)(DAT_00632ed8 + 0x11ac)) ||

           ((float10)*(float *)(DAT_00632ed8 + 0x11b0) < fVar17)) goto LAB_004de996;

        if ((float)piVar15[0x84] < (float)piVar15[0x88]) {

          iVar7 = *piVar15;

          *piVar15 = 0;

          rpman_flying_fire__FP6OBJECT(param_1);

          *piVar15 = iVar7;

        }

        break;

      case 0x6a:

        fVar17 = (float10)FUN_00518b70(param_1,0);

        fVar24 = (float)param_1[0x3b];

        param_1[0x3b] = (int)(float)((float10)fVar24 - fVar17);

        if ((float10)fVar24 - fVar17 < (float10)0.0) {

          rpman_scan_for_enemy__FP6OBJECTfii(param_1,piVar15[0x2b],1,1);

          param_1[0x3b] = 0x3f800000;

        }

        if (*piVar15 == 0) {

          ai_goal_process(param_1);

          if (param_1[0x5a] == 0) {

            param_1[0x3b] = 0x3f800000;

            ai_damage_response(param_1,1,0,0);

            param_1[0x39] = 0xe0;

          }

        }

        else if (*(int *)(*piVar15 + 0x1e0) != 0x12) goto LAB_004db899;

        break;

      case 0x6b:

        fVar17 = (float10)FUN_00518b70(param_1,0);

        fVar24 = (float)param_1[0x3b];

        param_1[0x3b] = (int)(float)((float10)fVar24 - fVar17);

        if ((float10)fVar24 - fVar17 < (float10)0.0) {

          rpman_scan_for_enemy__FP6OBJECTfii(param_1,piVar15[0x2b],1,1);

          param_1[0x3b] = 0x3f800000;

        }

        if (*piVar15 == 0) goto LAB_004dab5a;

        iVar7 = *(int *)(*piVar15 + 0x1e0);

LAB_004dc633:

        if (iVar7 != 0x12) {

          param_1[0x39] = 0xd1;

        }

        break;

      case 0x6c:

        if (piVar15[0x8a] == 0) {

          if (*piVar15 == 0) {

            iVar7 = FUN_004e7250(param_1);

            if (iVar7 == 0) {

              fVar17 = (float10)get_floor_z_point(param_1 + 0x28);

              if (fVar17 < (float10)(float)piVar15[0xc]) {

                fVar17 = (float10)(float)piVar15[0xc];

              }

              ai_accel_update(param_1,(float)((float10)*(float *)(DAT_00632ed8 + 0xd24) + fVar17));

              rpman_goto_last_loc__FP6OBJECTi(param_1,1);

              param_1[0x5b] = (int)&LAB_004cb930;

              ai_goal_process(param_1);

              fVar17 = (float10)FUN_00518b70(param_1,0);

              fVar24 = (float)param_1[0x3b];

              param_1[0x3b] = (int)(float)((float10)fVar24 - fVar17);

              if ((float10)fVar24 - fVar17 < (float10)0.0) {

                iVar7 = piVar15[0x2b];

                goto LAB_004dee82;

              }

            }

            else {

              param_1[0x39] = 0x13;

            }

          }

          else {

            param_1[0x39] = 0xf;

          }

        }

        else {

          piVar15[0x53] = 0;

          if ((*(byte *)(param_1 + 0xc) & 2) != 0) {

            cleaner_process(param_1,0);

          }

          if (*piVar15 != 0) {

            iVar7 = rpman_verify_enemy__FP6OBJECTf(param_1,piVar15[0x28]);

            if (iVar7 != 0) break;

            if (*piVar15 != 0) {

              rpman_flying_fire__FP6OBJECT(param_1);

              ai_d7_pairing(param_1,*(undefined4 *)(DAT_00632ed8 + 0xa20));

              rpman_consider_run_chatter__FP6OBJECT(param_1);

              fVar17 = (float10)distancesq2d__FP3P3DT0(param_1 + 0x28,piVar15[0x8a] + 0xa0);

              if ((float10)90000.0 < fVar17) {

                piVar15[0x17] = 0;

                *piVar15 = 0;

              }

            }

          }

          param_1[0x5b] = (int)&LAB_004cb930;

          ai_goal_process(param_1);

          if (param_1[0x5a] == 0) {

LAB_004dd68d:

            fVar17 = (float10)rndfloatrange(0x3f800000,0x40000000);

            piVar15[0x17] = (int)(float)fVar17;

            iVar7 = *piVar15;

            if (iVar7 == 0) {

              iVar7 = piVar15[0x8a];

            }

            ai_move_force_goal(param_1,iVar7 + 0xa0);

          }

          else {

            ai_get_goal_location(param_1,auStack_d0);

            fVar17 = (float10)distancesq2d__FP3P3DT0(auStack_d0,param_1 + 0x28);

            if (fVar17 < (float10)1600.0 != (fVar17 == (float10)1600.0)) {

              ai_clear_move_goal(param_1);

            }

            if ((param_1[0x5a] == 0) ||

               ((float)piVar15[0x17] < 0.0 != ((float)piVar15[0x17] == 0.0))) goto LAB_004dd68d;

            fVar17 = (float10)FUN_00518b70(0,0);

            piVar15[0x17] = (int)(float)((float10)(float)piVar15[0x17] - fVar17);

          }

          fVar17 = (float10)get_floor_z_point(param_1 + 0x28);

          iVar7 = *piVar15;

          if (iVar7 == 0) {

            if (fVar17 < (float10)*(float *)(piVar15[0x8a] + 0xa8)) {

              fVar17 = (float10)*(float *)(piVar15[0x8a] + 0xa8);

            }

          }

          else if (fVar17 < (float10)*(float *)(iVar7 + 0xa8)) {

            fVar17 = (float10)*(float *)(iVar7 + 0xa8);

          }

          ai_accel_update(param_1,(float)((float10)*(float *)(DAT_00632ed8 + 0xd24) + fVar17));

        }

        break;

      case 0x6d:

        if (piVar15[0x8a] == 0) {

          if (*piVar15 == 0) goto LAB_004dc53c;

LAB_004dd739:

          param_1[0x39] = 0xd;

        }

        else {

          if (*piVar15 != 0) {

            fVar17 = (float10)distancesq2d__FP3P3DT0(param_1 + 0x28,piVar15[0x8a] + 0xa0);

            if (fVar17 <= (float10)90000.0) {

              if ((float)piVar15[8] < 0.0 != ((float)piVar15[8] == 0.0)) {

                ai_clear_move_goal(param_1);

                param_1[0x39] = 0xe3;

              }

            }

            else {

              piVar15[0x17] = 0;

              *piVar15 = 0;

            }

          }

          param_1[0x5b] = (int)&LAB_004cb930;

          ai_goal_process(param_1);

          if ((param_1[0x5a] == 0) || ((float)piVar15[0x17] < 0.0 != ((float)piVar15[0x17] == 0.0)))

          {

            fVar17 = (float10)rndfloatrange(0x3f800000,0x40000000);

            piVar15[0x17] = (int)(float)fVar17;

            if (*piVar15 == 0) {

              ai_moveonly_set_goal(param_1,piVar15[0x8a] + 0xa0);

            }

            else {

              ai_moveonly_set_goal(param_1,*piVar15 + 0xa0);

            }

          }

          else {

            fVar17 = (float10)FUN_00518b70(0,0);

            piVar15[0x17] = (int)(float)((float10)(float)piVar15[0x17] - fVar17);

          }

        }

        break;

      case 0x6e:

        iVar7 = rpman_verify_enemy__FP6OBJECTf(param_1,piVar15[0x28]);

        if (iVar7 == 0) {

          if (*piVar15 == 0) {

            param_1[0x39] = 0xe2;

          }

          else {

            if ((float)piVar15[0xd] < (float)piVar15[0x2a] * (float)piVar15[0x2a]) {

              fVar17 = (float10)obj_turn_toward_point(param_1,*piVar15 + 0xa0);

              if ((float10)5.0 <= fVar17) goto LAB_004ded23;

              piVar15[0x6e] = piVar15[0x6e] | 8;

              goto LAB_004ded0d;

            }

            fVar17 = (float10)rndfloatrange(piVar15[0x25],piVar15[0x26]);

            piVar15[8] = (int)(float)fVar17;

            param_1[0x39] = 0xe2;

          }

        }

        break;

      case 0x6f:

        rpman_sniper_anim_set(param_1);

        rpman_scan_for_enemy__FP6OBJECTfii(param_1,0x42960000,0,1);

        if ((*piVar15 != 0) &&

           (fVar17 = (float10)distancesq2d__FP3P3DT0(param_1 + 0x28,*piVar15 + 0xa0),

           fVar17 < (float10)5625.0)) {

          if (piVar15[0x8a] != 0) {

            **(int **)(piVar15[0x8a] + 0x100) = *piVar15;

          }

          if (piVar15[0x8b] != 0) {

            **(int **)(piVar15[0x8b] + 0x100) = *piVar15;

          }

          goto LAB_004dd3aa;

        }

        ai_goal_process(param_1);

        if (param_1[0x5a] == 0) {

          fVar17 = (float10)distance3d__FP3P3DT0(param_1 + 0x28,piVar15[0x7b] + 0xa0);

          if ((float10)25.0 <= fVar17) {

            rpman_set_smartie_goal__FP6OBJECT(param_1);

            ai_goal_process(param_1);

            if (param_1[0x5a] == 0) {

              rpman_scan_for_enemy__FP6OBJECTfii(param_1,piVar15[0x2b],0,1);

              if (*piVar15 == 0) {

                iVar7 = *(int *)(*(int *)(piVar15[0x4d] + 0x100) + 0x18);

                goto LAB_004dd2c5;

              }

              piVar15[8] = 0;

              goto LAB_004dd316;

            }

          }

          else {

            iVar7 = *(int *)(*(int *)(piVar15[0x4d] + 0x100) + 0x18);

LAB_004dd2c5:

            ai_moveonly_set_goal(param_1,iVar7 + 0xa0);

            param_1[0x39] = 0xdc;

          }

        }

        break;

      case 0x70:

        ai_goal_process(param_1);

        if (param_1[0x5a] == 0) {

          param_1[0x72] = param_1[0x72] & 0xfffff1ff;

          param_1[0x36] = param_1[0x36] & 0xffffffef;

          if (*(int *)(param_1[0x40] + 0xd8) == 0) {

            if ((param_1[0x38] & 0x200U) == 0) {

              ai_anim_play(param_1,0x53,1,1,*(float *)(DAT_00632ed8 + 0xb34) * (float)param_1[0x31],

                           0);

            }

            else if ((param_1[4] != 0x92) && (*(int *)(param_1[2] + 0x250) != 0)) {

              ObjectSetAnim(param_1,0x92,0x21,1,

                            *(float *)(DAT_00632ed8 + 0xb34) * (float)param_1[0x31] *

                            (float)param_1[0x31],0x3e2aaaab);

            }

          }

          else {

            cleaner_process(param_1,0);

          }

          main_ai_move_004014b0(param_1,piVar15[0x4d] + 0xa0,*(undefined4 *)(piVar15[0x4d] + 200));

          param_1[0x39] = 0xe7;

        }

        break;

      case 0x71:

        rpman_scan_for_enemy__FP6OBJECTfii(param_1,*(undefined4 *)(DAT_00632ed8 + 0x1510),1,0);

        if (*piVar15 == 0) {

          ai_goal_process(param_1);

          if (param_1[0x5a] == 0) {

            param_1[0x39] = 0xe8;

          }

        }

        else if (piVar15[0x79] == 0) {

          iVar7 = param_1[0x40];

          fVar17 = (float10)rndfloatrange(*(undefined4 *)(iVar7 + 0x1dc),

                                          *(undefined4 *)(iVar7 + 0x1e0));

          fVar18 = (float10)rndfloatrange((float)param_1[0x32] - 45.0,(float)param_1[0x32] + 45.0);

          sine_cos_lookup((float)fVar18,&fStack_130,&fStack_144);

          *(float *)(iVar7 + 8) =

               (float)fVar17 * fStack_130 + *(float *)(*(int *)(iVar7 + 0x1ec) + 0xa0);

          *(float *)(iVar7 + 0xc) =

               *(float *)(*(int *)(iVar7 + 0x1ec) + 0xa4) - (float)fVar17 * fStack_144;

          *(undefined4 *)(iVar7 + 0x10) = *(undefined4 *)(*(int *)(iVar7 + 0x1ec) + 0xa8);

          *(int *)(iVar7 + 0x14) = param_1[0x32];

          piVar15[0x4d] = 0;

          param_1[0x3a] = 2;

          param_1[0x39] = 0xc;

        }

        else {

          piVar15[0x7a] = param_1[0x39];

          param_1[0x39] = 0xea;

        }

        break;

      case 0x72:

        rpman_scan_for_enemy__FP6OBJECTfii(param_1,*(undefined4 *)(DAT_00632ed8 + 0x1510),1,0);

        if (*piVar15 == 0) {

          iVar7 = ai_ground_snap(param_1);

          if ((iVar7 != 0) && (*(int *)(iVar7 + 0x174) == *(int *)(piVar15[0x7b] + 0x174))) {

            iVar7 = param_1[0x40];

            fVar17 = (float10)rndfloatrange(*(undefined4 *)(iVar7 + 0x1dc),

                                            *(undefined4 *)(iVar7 + 0x1e0));

            fVar18 = (float10)rndfloatrange((float)param_1[0x32] - 45.0,(float)param_1[0x32] + 45.0)

            ;

            sine_cos_lookup((float)fVar18,&fStack_16c,&fStack_13c);

            *(float *)(iVar7 + 8) =

                 fStack_16c * (float)fVar17 + *(float *)(*(int *)(iVar7 + 0x1ec) + 0xa0);

            *(float *)(iVar7 + 0xc) =

                 *(float *)(*(int *)(iVar7 + 0x1ec) + 0xa4) - fStack_13c * (float)fVar17;

            *(undefined4 *)(iVar7 + 0x10) = *(undefined4 *)(*(int *)(iVar7 + 0x1ec) + 0xa8);

            *(int *)(iVar7 + 0x14) = param_1[0x32];

            param_1[0x5b] = (int)&LAB_004cb930;

            ai_moveonly_set_goal(param_1,piVar15 + 2);

            param_1[0x39] = 0xe9;

          }

        }

        else if (piVar15[0x79] == 0) {

          iVar7 = param_1[0x40];

          fVar17 = (float10)rndfloatrange(*(undefined4 *)(iVar7 + 0x1dc),

                                          *(undefined4 *)(iVar7 + 0x1e0));

          fVar18 = (float10)rndfloatrange((float)param_1[0x32] - 45.0,(float)param_1[0x32] + 45.0);

          sine_cos_lookup((float)fVar18,&fStack_178,&fStack_174);

          *(float *)(iVar7 + 8) =

               fStack_178 * (float)fVar17 + *(float *)(*(int *)(iVar7 + 0x1ec) + 0xa0);

          *(float *)(iVar7 + 0xc) =

               *(float *)(*(int *)(iVar7 + 0x1ec) + 0xa4) - fStack_174 * (float)fVar17;

          *(undefined4 *)(iVar7 + 0x10) = *(undefined4 *)(*(int *)(iVar7 + 0x1ec) + 0xa8);

          *(int *)(iVar7 + 0x14) = param_1[0x32];

          piVar15[0x4d] = 0;

          param_1[0x3a] = 2;

          param_1[0x39] = 0xc;

        }

        else {

LAB_004db48c:

          piVar15[0x7a] = param_1[0x39];

          param_1[0x39] = 0xea;

        }

        break;

      case 0x73:

        rpman_scan_for_enemy__FP6OBJECTfii(param_1,*(undefined4 *)(DAT_00632ed8 + 0x1510),1,0);

        if (*piVar15 == 0) {

          ai_goal_process(param_1);

          if (param_1[0x5a] == 0) {

            iVar7 = piVar15[5];

            fVar17 = (float10)playerobj_turn(iVar7,param_1[0x32]);

            if (ABS(fVar17) != (float10)0.0) {

              param_1[0x56] = iVar7;

              param_1[0x36] = param_1[0x36] | 0x1000000;

              uVar4 = __ftol();

              *(undefined1 *)(param_1 + 0x82) = uVar4;

              if (5.0 <= (float)ABS(fVar17)) goto LAB_004db566;

            }

            param_1[0x6a] = *(int *)(param_1[0x40] + 0x1ac);

            piVar15[0x4d] = 0;

            param_1[0x39] = 10;

            param_1[0x3a] = (-(uint)(piVar15[0x79] != 0) & 0xc) + 2;

          }

        }

        else {

          if (piVar15[0x79] != 0) goto LAB_004db48c;

          piVar15[0x4d] = 0;

          param_1[0x3a] = 2;

          param_1[0x39] = 0xc;

        }

        break;

      case 0x74:

        iVar7 = rpman_verify_enemy__FP6OBJECTf(param_1,piVar15[0x28]);

        if (iVar7 == 0) {

          if (*piVar15 == 0) {

            if (*(int *)(param_1[0x40] + 0xd8) == 0) {

              if ((param_1[0x38] & 0x200U) == 0) {

                ai_anim_play(param_1,0x53,1,1,

                             *(float *)(DAT_00632ed8 + 0xb34) * (float)param_1[0x31],0);

              }

              else if ((param_1[4] != 0x92) && (*(int *)(param_1[2] + 0x250) != 0)) {

                ObjectSetAnim(param_1,0x92,0x21,1,

                              *(float *)(DAT_00632ed8 + 0xb34) * (float)param_1[0x31] *

                              (float)param_1[0x31],0x3e2aaaab);

                param_1[0x39] = piVar15[0x7a];

                break;

              }

              param_1[0x39] = piVar15[0x7a];

            }

            else {

              cleaner_process(param_1,0);

              param_1[0x39] = piVar15[0x7a];

            }

          }

          else {

            ai_d7_pairing(param_1,*(undefined4 *)(DAT_00632ed8 + 0xa20));

            fVar17 = (float10)dirfcalcp3d__FP3P3DT0(param_1 + 0x28,*piVar15 + 0xa0);

            fVar18 = (float10)playerobj_turn((float)fVar17,param_1[0x32]);

            fVar24 = (float)ABS(fVar18);

            if (ABS(fVar18) == (float10)0.0) {

              fVar24 = 0.0;

            }

            else {

              param_1[0x56] = (int)(float)fVar17;

              param_1[0x36] = param_1[0x36] | 0x1000000;

              uVar4 = __ftol();

              *(undefined1 *)(param_1 + 0x82) = uVar4;

            }

            if (fVar24 < 5.0) {

              param_1[0x6a] = *(int *)(param_1[0x40] + 0x1ac);

              goto LAB_004db788;

            }

LAB_004db566:

            iVar7 = param_1[0x40];

            if ((param_1[0x38] & 0x200U) == 0) {

              if ((param_1[0x38] & 0x100U) == 0) {

                uVar20 = 0x52;

              }

              else {

                uVar20 = 0x9c;

              }

            }

            else {

              uVar20 = 0x91;

            }

            ai_anim_play(param_1,uVar20,1,0,0,0);

            param_1[0x6a] = (int)(*(float *)(iVar7 + 0x1ac) + *(float *)(iVar7 + 0x1ac));

          }

        }

        break;

      case 0x75:

        if ((param_1[4] == 0xaa) && (uVar6 != 0)) {

          ai_anim_play(param_1,0xab,1,0,0,0);

        }

        break;

      case 0x76:

        ai_goal_process(param_1);

        if (param_1[0x5a] == 0) {

          param_1[0x39] = piVar15[0x3b];

        }

        break;

      case 0x77:

        ai_goal_process(param_1);

        break;

      case 0x78:

        if ((uVar6 != 0) && ((param_1[0x37] & 0x20000U) == 0)) {

          param_1[0x37] = param_1[0x37] | 0x20000;

          param_1[0x3b] = DAT_00632e6c;

        }

        if (((param_1[0x38] & 0x4000000U) == 0) &&

           (iVar7 = vimp_mana_effect(param_1,param_1,0,*(undefined4 *)(DAT_00632ed8 + 0x10f8),2),

           iVar7 != 0)) {

          param_1[0x38] = param_1[0x38] | 0x4000000;

        }

        break;

      case 0x79:

        if (uVar6 != 0) {

          ai_anim_play(param_1,0x3d,1,0,0,0);

          param_1[0x39] = 0x1f6;

        }

        break;

      case 0x7a:

        if (*(char *)param_1[0x41] < '\0') {

          ai_anim_play(param_1,0x3f,0,0,0,0);

          param_1[0x39] = 500;

        }

      }

    }

LAB_004e0a56:

    if ((param_1[0x3a] != 4) && (ripper_control__FP6OBJECT(param_1), param_1[0x36] < 0)) {

      ai_death_anim(param_1);

    }

    obj_alpha_fade_update(param_1);

    player_pitch_update(param_1);

    iVar7 = param_1[0x39];

    if (((((iVar7 != 0x1e) && (iVar7 != 0x1f)) &&

         ((iVar7 != 0xcb && (((param_1[0x3a] != 7 && (param_1[0x3a] != 0xd)) && (iVar7 != 0xcf))))))

        && ((iVar7 != 0xe8 && (iVar7 != 0xd6)))) &&

       ((iVar7 != 0xde && ((iVar7 != 0x23 && (param_1[0x41] != 0)))))) {

      obj_vel_reset(param_1);

      PhysicsExApplyLocation(param_1);

      PhysicsExCalcControledModelSpeeds

                (param_1,*(undefined4 *)(DAT_00632ed8 + 0xd84),*(undefined4 *)(DAT_00632ed8 + 0xd80)

                );

      obj_gravity_apply(param_1,1);

      if ((param_1[0x38] & 0x400U) != 0) {

        rpman_jet__FP6OBJECT(param_1);

      }

      PhysicsExApplyMoveControls(param_1);

    }

    fVar17 = (float10)FUN_00518b70(param_1,0);

    object_animate_process(param_1,(float)fVar17);

    param_1[0x36] = param_1[0x36] | 0x40;

  }

  return;

}

