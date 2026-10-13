/* Giants 1.449 — module _unmapped_004d
 * 39 functions (4 named) — decompiled, names from PS2 symbols
 * Original source: C:\Giants\source\_unmapped_004d.c(pp) (assert-string evidence)
 */

/* ===== FUN_004d1790 @ 0x004D1790 ===== */
/* PS2 candidate: EnemyIsInvalid__FP6OBJECTT0 (conf 0.631) */



undefined4 FUN_004d1790(int param_1,int param_2)



{

  uint uVar1;

  int iVar2;

  int iVar3;

  

  iVar3 = *(int *)(param_1 + 0x100);

  if ((((param_2 != 0) && (*(int *)(param_2 + 4) != 0)) &&

      ((*(uint *)(param_2 + 0xd8) & 0x4000c000) == 0)) &&

     ((*(float *)(param_2 + 0x278) < *(float *)(param_2 + 0x1c0) &&

      (((iVar2 = FUN_004a6160(param_2), iVar2 == 0 || ((*(uint *)(param_2 + 0xe0) & 0x2000000) == 0)

        ) || (4.0 <= *(float *)(iVar3 + 0x54))))))) {

    iVar3 = FUN_004a6180(param_2);

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

        iVar3 = FUN_004a6240(iVar2);

        if ((iVar3 == 0) && (iVar3 = FUN_004a62b0(iVar2), iVar3 == 0)) {

          if ((*(int *)(iVar2 + 0x1e0) == 0x2c) &&

             (*(int *)(iVar2 + 0x18c) != *(int *)(param_1 + 0x18c))) goto LAB_004d1921;

        }

        else {

          iVar3 = FUN_00417f60(iVar2);

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

            iVar3 = FUN_004ef070(&local_c,&local_18,2,&DAT_00561374,0);

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

           ((iVar3 = FUN_004a61e0(iVar2), iVar3 != 0 || (*(int *)(iVar2 + 0x1e0) == 0x55)))) &&

          (*(int *)(iVar2 + 4) != 0)) &&

         ((((iVar3 = FUN_004a6160(iVar2), iVar3 == 0 || ((*(uint *)(iVar2 + 0xe0) & 0x2000000) == 0)

            ) || (4.0 <= *(float *)(iVar1 + 0x54))) && (*(int *)(iVar2 + 0x210) == 0)))) {

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

/* ===== FUN_004d1b30 @ 0x004D1B30 ===== */
void FUN_004d1b30(int param_1)



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

      iVar2 = FUN_00512c80(param_1,param_1,0,fVar1,2);

      if (iVar2 == 0) {

        return;

      }

    }

  }

  FUN_00497510(param_1);

  return;

}

/* ===== FUN_004d1bd0 @ 0x004D1BD0 ===== */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

/* WARNING: Struct "OBJECT": ignoring multiple overlapping fields */

/* PS2 candidate: verm_control__FP6OBJECT (conf 0.469) */



void FUN_004d1bd0(OBJECT *obj)



{

  dword *pdVar1;

  float *pfVar2;

  undefined1 uVar3;

  dword dVar4;

  uint uVar5;

  float fVar6;

  int iVar7;

  int iVar8;

  float fVar9;

  undefined4 *puVar10;

  float10 fVar11;

  float10 fVar12;

  float local_80;

  float local_7c;

  float local_78;

  float local_74;

  float local_70;

  float local_6c;

  float local_68;

  float local_64;

  dword local_60;

  undefined4 local_5c;

  undefined4 local_58;

  float local_54;

  undefined1 local_50 [12];

  undefined1 local_44 [8];

  float local_3c;

  dword local_30;

  undefined4 local_2c;

  undefined4 local_28;

  undefined4 local_24;

  undefined4 local_20;

  OBJECT *local_1c;

  

  pfVar2 = *(float **)&obj->field_0x100;

  fVar9 = (float)(obj->acc_vimp_set_run_anim & 2);

  if ((pfVar2[3] != 0.0) && ((char)((uint)*(undefined4 *)((int)pfVar2[3] + 0xd8) >> 8) < '\0')) {

    pfVar2[3] = 0.0;

  }

  local_74 = fVar9;

  if (pfVar2[3] == 0.0) {

    FUN_004d1a00(obj,*(undefined4 *)(DAT_00632ed8 + 0xe0));

  }

  fVar6 = pfVar2[3];

  if (fVar6 == 0.0) {

    local_78 = 9.99998e+11;

    local_6c = 9.99998e+11;

    local_54 = 99999.0;

    local_58 = 0x47c34f80;

    local_5c = 0x47c34f80;

  }

  else {

    local_5c = *(undefined4 *)((int)fVar6 + 0xa0);

    local_58 = *(undefined4 *)((int)fVar6 + 0xa4);

    local_54 = *(float *)((int)fVar6 + 0xa8);

    fVar11 = (float10)FUN_0050a5e0(&local_5c,&obj->gap_A0);

    local_78 = (float)fVar11;

    fVar11 = (float10)FUN_0050a610(&local_5c,&obj->gap_A0);

    local_6c = (float)fVar11;

    local_54 = *(float *)((int)fVar6 + 0x1e8) * *(float *)((int)fVar6 + 0xc4) + local_54;

    fVar9 = local_74;

  }

  switch(obj->gap_E4) {

  case 0x1f:

    FUN_0040d6b0(local_50);

    local_70 = *(float *)(DAT_00632ed8 + 0x144);

    pdVar1 = &obj->gap_A0;

    fVar11 = (float10)FUN_0050a610(local_50,pdVar1);

    if (fVar11 <= (float10)local_70 * (float10)local_70) {

      obj->field_184 = 0;

    }

    else {

      obj->field_184 = 0x3f800000;

    }

    if (fVar6 != 0.0) {

      local_6c = (float)FUN_004d5730(100);

      if (((float)(int)local_6c < *(float *)(DAT_00632ed8 + 0x3e4)) ||

         (ai_fly_update_goal_4(pdVar1,local_44,&local_6c), local_3c < 0.64278)) {

        if (pfVar2[0xe] == 0.0) {

          local_1c = obj;

          local_20 = 0xffffffff;

          local_24 = 8;

          fVar9 = (float)fx_get_free_effect__Fv();

          pfVar2[0xe] = fVar9;

        }

        puVar10 = *(undefined4 **)&obj->field_0x100;

        obj->gap_E4 = 0x22;

        if (puVar10[3] != 0) {

          fVar11 = (float10)FUN_0050a400(puVar10[3] + 0xa0,pdVar1);

          fVar11 = (float10)FUN_004d5780((float)(fVar11 - (float10)50.0),

                                         (float)((float10)50.0 + fVar11));

          puVar10[1] = (float)fVar11;

          FUN_00451560(puVar10 + 1);

          fVar11 = (float10)FUN_004d5780(*(undefined4 *)(DAT_00632ed8 + 200),

                                         *(undefined4 *)(DAT_00632ed8 + 0xcc));

          puVar10[2] = (float)fVar11;

          *puVar10 = *(undefined4 *)(DAT_00632ed8 + 0xd0);

        }

        obj->field_184 = 0x3f800000;

        sound_play_obj(0x4e8,obj);

        FUN_00495750(0x4ea,obj);

      }

      else {

        obj->gap_E4 = 0x2c;

        FUN_00495750(0x4ea,obj);

      }

    }

    break;

  case 0x20:

    goto switchD_004d1ccc_caseD_20;

  case 0x21:

    iVar8 = *(int *)&obj->field_0x100;

    if ((((fVar6 == 0.0) || (*(int *)((int)fVar6 + 4) == 0)) ||

        (((*(uint *)((int)fVar6 + 0xd8) & 0x4000c000) != 0 ||

         (*(float *)((int)fVar6 + 0x1c0) <= *(float *)((int)fVar6 + 0x278))))) ||

       (((iVar7 = FUN_004a6160(fVar6), iVar7 != 0 &&

         ((*(uint *)((int)fVar6 + 0xe0) & 0x2000000) != 0)) && (*(float *)(iVar8 + 0x54) < 4.0))))

    goto LAB_004d2124;

    iVar8 = FUN_004a6180(fVar6);

    if (iVar8 == 0) {

LAB_004d2151:

      local_68 = *(float *)((int)fVar6 + 0xa0);

      local_64 = *(float *)((int)fVar6 + 0xa4);

      local_60 = *(dword *)((int)fVar6 + 0xa8);

      FUN_0050ae40(pfVar2[1],&local_80,&local_7c);

      local_68 = local_80 * pfVar2[2] + local_68;

      local_64 = local_64 - local_7c * pfVar2[2];

      fVar11 = (float10)FUN_0050a520(&obj->gap_A0,&local_68);

      local_6c = (float)fVar11;

      if ((float10)0.0 <= fVar11) {

        obj->field_0x208 = 0;

        fVar11 = (float10)FUN_0050a400(&obj->gap_A0,&local_68);

        local_70 = (float)fVar11;

        fVar11 = (float10)FUN_0050a7c0(local_70,*(undefined4 *)&obj->field_0xc8);

        local_74 = (float)fVar11;

        if (ABS(fVar11) == (float10)0.0) {

          fVar9 = 0.0;

        }

        else {

          uVar3 = FUN_004a7cb0(local_74 * 0.05,0x3e800000);

          obj->field_0x208 = uVar3;

          *(float *)&obj->field_0x158 = local_70;

          *(uint *)&obj->field_0xd8 = *(uint *)&obj->field_0xd8 | 0x1000000;

          fVar9 = local_74;

        }

        *(float *)&obj->field_0x15c = local_68;

        obj->acc_verm_gib = (dword)local_64;

        obj->acc_verm_gib = local_60;

        *(uint *)&obj->field_0xd8 = *(uint *)&obj->field_0xd8 | 0x2000000;

        if (10.0 <= ABS(fVar9)) {

          obj->field_0x20a = 3;

        }

        else {

          uVar3 = FUN_004a7cb0(local_6c * 0.1,0x3e4ccccd);

          obj->field_0x20a = uVar3;

        }

      }

      if (pfVar2[2] * 1.1 * pfVar2[2] * 1.1 <= local_78) break;

      local_6c = (float)FUN_004d5730(100);

LAB_004d286e:

      if ((float)(int)local_6c < *(float *)(DAT_00632ed8 + 0xe4)) goto LAB_004d288a;

      goto LAB_004d2d85;

    }

    uVar5 = obj->field_E0;

    if ((*(byte *)((int)fVar6 + 0xe0) & 8) == 0) {

      obj->field_E0 = uVar5 & 0xffffffef;

      goto LAB_004d2151;

    }

    if ((uVar5 & 0x10) != 0) goto LAB_004d2151;

    goto LAB_004d211b;

  case 0x22:

    iVar8 = *(int *)&obj->field_0x100;

    if ((((fVar6 == 0.0) || (*(int *)((int)fVar6 + 4) == 0)) ||

        (((*(uint *)((int)fVar6 + 0xd8) & 0x4000c000) != 0 ||

         (*(float *)((int)fVar6 + 0x1c0) <= *(float *)((int)fVar6 + 0x278))))) ||

       (((iVar7 = FUN_004a6160(fVar6), iVar7 != 0 &&

         ((*(uint *)((int)fVar6 + 0xe0) & 0x2000000) != 0)) && (*(float *)(iVar8 + 0x54) < 4.0)))) {

LAB_004d2364:

      if (pfVar2[0xe] != 0.0) {

        FUN_00448920(pfVar2[0xe]);

      }

      pfVar2[0xe] = 0.0;

      sound_play_obj(0x4ea,obj);

      obj->gap_E4 = 0x1f;

      pfVar2[3] = 0.0;

    }

    else {

      iVar8 = FUN_004a6180(fVar6);

      if (iVar8 != 0) {

        uVar5 = obj->field_E0;

        if ((*(byte *)((int)fVar6 + 0xe0) & 8) == 0) {

          obj->field_E0 = uVar5 & 0xffffffef;

        }

        else if ((uVar5 & 0x10) == 0) {

          obj->field_E0 = uVar5 | 0x10;

          goto LAB_004d2364;

        }

      }

      local_68 = *(float *)((int)fVar6 + 0xa0);

      local_64 = *(float *)((int)fVar6 + 0xa4);

      local_60 = *(dword *)((int)fVar6 + 0xa8);

      FUN_0050ae40(pfVar2[1],&local_80,&local_7c);

      pdVar1 = &obj->gap_A0;

      local_68 = local_80 * pfVar2[2] + local_68;

      local_64 = local_64 - local_7c * pfVar2[2];

      fVar11 = (float10)FUN_0050a520(pdVar1,&local_68);

      local_6c = (float)fVar11;

      if ((float10)0.0 <= fVar11) {

        obj->field_0x208 = 0;

        fVar11 = (float10)FUN_0050a400(pdVar1,&local_68);

        local_70 = (float)fVar11;

        fVar11 = (float10)FUN_0050a7c0(local_70,*(undefined4 *)&obj->field_0xc8);

        local_74 = (float)fVar11;

        if (ABS(fVar11) == (float10)0.0) {

          fVar9 = 0.0;

        }

        else {

          uVar3 = FUN_004a7cb0(local_74 * 0.05,0x3e800000);

          obj->field_0x208 = uVar3;

          *(float *)&obj->field_0x158 = local_70;

          *(uint *)&obj->field_0xd8 = *(uint *)&obj->field_0xd8 | 0x1000000;

          fVar9 = local_74;

        }

        *(float *)&obj->field_0x15c = local_68;

        obj->acc_verm_gib = (dword)local_64;

        obj->acc_verm_gib = local_60;

        *(uint *)&obj->field_0xd8 = *(uint *)&obj->field_0xd8 | 0x2000000;

        if (10.0 <= ABS(fVar9)) {

          obj->field_0x20a = 3;

        }

        else {

          uVar3 = FUN_004a7cb0(local_6c * 0.1,0x3e4ccccd);

          obj->field_0x20a = uVar3;

        }

      }

      if ((local_78 < pfVar2[2] * 1.1 * pfVar2[2] * 1.1) &&

         (ai_fly_update_goal_4(pdVar1,local_44,&local_6c), 0.64278 <= local_3c)) {

        obj->gap_E4 = 0x2c;

        FUN_00495750(0x4e8,obj);

      }

    }

    break;

  case 0x23:

    iVar8 = *(int *)&obj->field_0x100;

    if ((((fVar6 == 0.0) || (*(int *)((int)fVar6 + 4) == 0)) ||

        (((*(uint *)((int)fVar6 + 0xd8) & 0x4000c000) != 0 ||

         (*(float *)((int)fVar6 + 0x1c0) <= *(float *)((int)fVar6 + 0x278))))) ||

       (((iVar7 = FUN_004a6160(fVar6), iVar7 != 0 &&

         ((*(uint *)((int)fVar6 + 0xe0) & 0x2000000) != 0)) && (*(float *)(iVar8 + 0x54) < 4.0))))

    goto LAB_004d2124;

    iVar8 = FUN_004a6180(fVar6);

    if (iVar8 != 0) {

      uVar5 = obj->field_E0;

      if ((*(byte *)((int)fVar6 + 0xe0) & 8) == 0) {

        obj->field_E0 = uVar5 & 0xffffffef;

      }

      else if ((uVar5 & 0x10) == 0) goto LAB_004d211b;

    }

    local_68 = *(float *)((int)fVar6 + 0xa0);

    local_64 = *(float *)((int)fVar6 + 0xa4);

    local_60 = *(dword *)((int)fVar6 + 0xa8);

    FUN_0050ae40(pfVar2[1],&local_80,&local_7c);

    pdVar1 = &obj->gap_A0;

    local_68 = local_80 * pfVar2[2] + local_68;

    local_64 = local_64 - local_7c * pfVar2[2];

    fVar11 = (float10)FUN_0050a520(pdVar1,&local_68);

    local_6c = (float)fVar11;

    if ((float10)0.0 <= fVar11) {

      obj->field_0x208 = 0;

      fVar11 = (float10)FUN_0050a400(pdVar1,&local_68);

      local_70 = (float)fVar11;

      fVar11 = (float10)FUN_0050a7c0(local_70,*(undefined4 *)&obj->field_0xc8);

      local_74 = (float)fVar11;

      if (ABS(fVar11) == (float10)0.0) {

        fVar9 = 0.0;

      }

      else {

        uVar3 = FUN_004a7cb0(local_74 * 0.05,0x3e800000);

        obj->field_0x208 = uVar3;

        *(float *)&obj->field_0x158 = local_70;

        *(uint *)&obj->field_0xd8 = *(uint *)&obj->field_0xd8 | 0x1000000;

        fVar9 = local_74;

      }

      *(float *)&obj->field_0x15c = local_68;

      obj->acc_verm_gib = (dword)local_64;

      obj->acc_verm_gib = local_60;

      *(uint *)&obj->field_0xd8 = *(uint *)&obj->field_0xd8 | 0x2000000;

      if (10.0 <= ABS(fVar9)) {

        obj->field_0x20a = 3;

      }

      else {

        uVar3 = FUN_004a7cb0(local_6c * 0.1,0x3e4ccccd);

        obj->field_0x20a = uVar3;

      }

    }

    if (*(float *)(DAT_00632ed8 + 0xd4) * *(float *)(DAT_00632ed8 + 0xd4) <= local_78) {

      fVar11 = (float10)FUN_0050a5e0(&local_68,pdVar1);

      if (((float10)5.0 <= fVar11) && (0.0 <= *pfVar2)) break;

      local_6c = (float)FUN_004d5730(100);

      goto LAB_004d286e;

    }

    local_6c = (float)FUN_004d5730(100);

    if ((float)(int)local_6c < *(float *)(DAT_00632ed8 + 0xdc)) goto LAB_004d27a6;

    puVar10 = *(undefined4 **)&obj->field_0x100;

    if (puVar10[3] == 0) break;

    fVar11 = (float10)FUN_0050a400(puVar10[3] + 0xa0,pdVar1);

    fVar12 = (float10)20.0 + fVar11;

    fVar11 = fVar11 - (float10)20.0;

    goto LAB_004d27e4;

  case 0x24:

    iVar8 = *(int *)&obj->field_0x100;

    if ((((fVar6 == 0.0) || (*(int *)((int)fVar6 + 4) == 0)) ||

        (((*(uint *)((int)fVar6 + 0xd8) & 0x4000c000) != 0 ||

         (*(float *)((int)fVar6 + 0x1c0) <= *(float *)((int)fVar6 + 0x278))))) ||

       (((iVar7 = FUN_004a6160(fVar6), iVar7 != 0 &&

         ((*(uint *)((int)fVar6 + 0xe0) & 0x2000000) != 0)) && (*(float *)(iVar8 + 0x54) < 4.0)))) {

LAB_004d2a47:

      if (pfVar2[0xe] != 0.0) {

        FUN_00448920(pfVar2[0xe]);

      }

      pfVar2[0xe] = 0.0;

      obj->gap_E4 = 0x2b;

      pfVar2[3] = 0.0;

    }

    else {

      iVar8 = FUN_004a6180(fVar6);

      if (iVar8 != 0) {

        uVar5 = obj->field_E0;

        if ((*(byte *)((int)fVar6 + 0xe0) & 8) == 0) {

          obj->field_E0 = uVar5 & 0xffffffef;

        }

        else if ((uVar5 & 0x10) == 0) {

          obj->field_E0 = uVar5 | 0x10;

          goto LAB_004d2a47;

        }

      }

      local_68 = *(float *)((int)fVar6 + 0xa0);

      local_64 = *(float *)((int)fVar6 + 0xa4);

      local_60 = *(dword *)((int)fVar6 + 0xa8);

      FUN_0050ae40(pfVar2[1],&local_80,&local_7c);

      pdVar1 = &obj->gap_A0;

      local_68 = local_80 * pfVar2[2] + local_68;

      local_64 = local_64 - local_7c * pfVar2[2];

      fVar11 = (float10)FUN_0050a520(pdVar1,&local_68);

      local_6c = (float)fVar11;

      if ((float10)0.0 <= fVar11) {

        obj->field_0x208 = 0;

        fVar11 = (float10)FUN_0050a400(pdVar1,&local_68);

        local_70 = (float)fVar11;

        fVar11 = (float10)FUN_0050a7c0(local_70,*(undefined4 *)&obj->field_0xc8);

        local_74 = (float)fVar11;

        if (ABS(fVar11) == (float10)0.0) {

          fVar9 = 0.0;

        }

        else {

          uVar3 = FUN_004a7cb0(local_74 * 0.05,0x3e800000);

          obj->field_0x208 = uVar3;

          *(float *)&obj->field_0x158 = local_70;

          *(uint *)&obj->field_0xd8 = *(uint *)&obj->field_0xd8 | 0x1000000;

          fVar9 = local_74;

        }

        *(float *)&obj->field_0x15c = local_68;

        obj->acc_verm_gib = (dword)local_64;

        *(uint *)&obj->field_0xd8 = *(uint *)&obj->field_0xd8 | 0x2000000;

        obj->acc_verm_gib = local_60;

        if (10.0 <= ABS(fVar9)) {

          obj->field_0x20a = 3;

        }

        else {

          uVar3 = FUN_004a7cb0(local_6c * 0.1,0x3e4ccccd);

          obj->field_0x20a = uVar3;

        }

      }

      fVar11 = (float10)FUN_0050a5e0(&local_68,pdVar1);

      if (((fVar11 < (float10)5.0) || (*pfVar2 < 0.0)) &&

         (ai_fly_update_goal_4(pdVar1,local_44,&local_6c), 0.64278 <= local_3c)) {

        obj->gap_E4 = 0x2c;

        FUN_00495750(0x4e8,obj);

      }

    }

    break;

  case 0x25:

    obj->gap_E4 = 0x26;

  case 0x26:

    iVar8 = *(int *)&obj->field_0x100;

    if (((((fVar6 != 0.0) && (*(int *)((int)fVar6 + 4) != 0)) &&

         ((*(uint *)((int)fVar6 + 0xd8) & 0x4000c000) == 0)) &&

        (*(float *)((int)fVar6 + 0x278) < *(float *)((int)fVar6 + 0x1c0))) &&

       (((iVar7 = FUN_004a6160(fVar6), iVar7 == 0 ||

         ((*(uint *)((int)fVar6 + 0xe0) & 0x2000000) == 0)) || (4.0 <= *(float *)(iVar8 + 0x54)))))

    {

      iVar8 = FUN_004a6180(fVar6);

      if (iVar8 != 0) {

        uVar5 = obj->field_E0;

        if ((*(byte *)((int)fVar6 + 0xe0) & 8) == 0) {

          obj->field_E0 = uVar5 & 0xffffffef;

        }

        else if ((uVar5 & 0x10) == 0) {

LAB_004d211b:

          obj->field_E0 = uVar5 | 0x10;

          goto LAB_004d2124;

        }

      }

      obj->field_0x208 = 0;

      if ((int)fVar6 + 0xa0 == 0) {

        local_78 = 0.0;

      }

      else {

        fVar11 = (float10)FUN_0050a400(&obj->gap_A0,(int)fVar6 + 0xa0);

        local_78 = (float)fVar11;

      }

      fVar11 = (float10)FUN_0050a7c0(local_78,*(undefined4 *)&obj->field_0xc8);

      if (ABS(fVar11) != (float10)0.0) {

        uVar3 = FUN_004a7cb0((float)(fVar11 * (float10)0.05),0x3e800000);

        obj->field_0x208 = uVar3;

        *(float *)&obj->field_0x158 = local_78;

        *(uint *)&obj->field_0xd8 = *(uint *)&obj->field_0xd8 | 0x1000000;

      }

      if (local_74 != 0.0) {

LAB_004d2d85:

        obj->gap_E4 = 0x27;

      }

      break;

    }

    goto LAB_004d2124;

  case 0x27:

    iVar8 = *(int *)&obj->field_0x100;

    if (((fVar6 != 0.0) && (*(int *)((int)fVar6 + 4) != 0)) &&

       ((((*(uint *)((int)fVar6 + 0xd8) & 0x4000c000) == 0 &&

         (*(float *)((int)fVar6 + 0x278) < *(float *)((int)fVar6 + 0x1c0))) &&

        (((iVar7 = FUN_004a6160(fVar6), iVar7 == 0 ||

          ((*(uint *)((int)fVar6 + 0xe0) & 0x2000000) == 0)) || (4.0 <= *(float *)(iVar8 + 0x54)))))

       )) {

      iVar8 = FUN_004a6180(fVar6);

      if (iVar8 != 0) {

        uVar5 = obj->field_E0;

        if ((*(byte *)((int)fVar6 + 0xe0) & 8) == 0) {

          obj->field_E0 = uVar5 & 0xffffffef;

        }

        else if ((uVar5 & 0x10) == 0) goto LAB_004d211b;

      }

      obj->field_0x208 = 0;

      if ((int)fVar6 + 0xa0 == 0) {

        local_78 = 0.0;

      }

      else {

        fVar11 = (float10)FUN_0050a400(&obj->gap_A0,(int)fVar6 + 0xa0);

        local_78 = (float)fVar11;

      }

      fVar11 = (float10)FUN_0050a7c0(local_78,*(undefined4 *)&obj->field_0xc8);

      if (ABS(fVar11) != (float10)0.0) {

        uVar3 = FUN_004a7cb0((float)(fVar11 * (float10)0.05),0x3e800000);

        obj->field_0x208 = uVar3;

        *(float *)&obj->field_0x158 = local_78;

        *(uint *)&obj->field_0xd8 = *(uint *)&obj->field_0xd8 | 0x1000000;

      }

      if (local_74 == 0.0) {

        if (((float)obj->field_18 < 0.43333334) && (0.43333334 <= (float)obj->field_14)) {

          FUN_004d4350(obj,&local_5c,*(undefined4 *)(DAT_00632ed8 + 0xf0));

        }

        break;

      }

      local_6c = (float)FUN_004d5730(100);

      if ((float)(int)local_6c < *(float *)(DAT_00632ed8 + 0xe8)) {

        obj->gap_E4 = 0x25;

        break;

      }

      if ((float)(int)local_6c < *(float *)(DAT_00632ed8 + 0xec) + *(float *)(DAT_00632ed8 + 0xe8))

      {

        puVar10 = *(undefined4 **)&obj->field_0x100;

        if (puVar10[3] != 0) {

          fVar11 = (float10)FUN_0050a400(puVar10[3] + 0xa0,&obj->gap_A0);

          fVar11 = (float10)FUN_004d5780((float)(fVar11 - (float10)80.0),

                                         (float)((float10)80.0 + fVar11));

          puVar10[1] = (float)fVar11;

          FUN_00451560(puVar10 + 1);

          fVar11 = (float10)FUN_004d5780(*(undefined4 *)(DAT_00632ed8 + 200),

                                         *(undefined4 *)(DAT_00632ed8 + 0xcc));

          puVar10[2] = (float)fVar11;

          *puVar10 = *(undefined4 *)(DAT_00632ed8 + 0xd0);

        }

        local_6c = (float)FUN_004d5730(100);

        if (*(float *)(DAT_00632ed8 + 0x3e4) <= (float)(int)local_6c) {

          obj->gap_E4 = 0x23;

        }

        else {

          sound_play_obj(0x4e8,obj);

          obj->gap_E4 = 0x2d;

        }

        break;

      }

LAB_004d27a6:

      obj->gap_E4 = 0x29;

      break;

    }

    goto LAB_004d2124;

  case 0x29:

    iVar8 = *(int *)&obj->field_0x100;

    if (((fVar6 != 0.0) && (*(int *)((int)fVar6 + 4) != 0)) &&

       ((((*(uint *)((int)fVar6 + 0xd8) & 0x4000c000) == 0 &&

         (*(float *)((int)fVar6 + 0x278) < *(float *)((int)fVar6 + 0x1c0))) &&

        (((iVar7 = FUN_004a6160(fVar6), iVar7 == 0 ||

          ((*(uint *)((int)fVar6 + 0xe0) & 0x2000000) == 0)) || (4.0 <= *(float *)(iVar8 + 0x54)))))

       )) {

      iVar8 = FUN_004a6180(fVar6);

      if (iVar8 != 0) {

        uVar5 = obj->field_E0;

        if ((*(byte *)((int)fVar6 + 0xe0) & 8) == 0) {

          obj->field_E0 = uVar5 & 0xffffffef;

        }

        else if ((uVar5 & 0x10) == 0) goto LAB_004d211b;

      }

      puVar10 = (undefined4 *)((int)fVar6 + 0xa0);

      obj->field_0x208 = 0;

      if (puVar10 == (undefined4 *)0x0) {

        local_74 = 0.0;

      }

      else {

        fVar11 = (float10)FUN_0050a400(&obj->gap_A0,puVar10);

        local_74 = (float)fVar11;

      }

      fVar11 = (float10)FUN_0050a7c0(local_74,*(undefined4 *)&obj->field_0xc8);

      local_70 = (float)fVar11;

      if (ABS(fVar11) == (float10)0.0) {

        fVar9 = 0.0;

      }

      else {

        uVar3 = FUN_004a7cb0(local_70 * 0.05,0x3e800000);

        obj->field_0x208 = uVar3;

        *(float *)&obj->field_0x158 = local_74;

        *(uint *)&obj->field_0xd8 = *(uint *)&obj->field_0xd8 | 0x1000000;

        fVar9 = local_70;

      }

      if (ABS(fVar9) < 5.0) {

        obj->field_0x20a = 0x20;

      }

      *(undefined4 *)&obj->field_0x15c = *puVar10;

      obj->acc_verm_gib = *(dword *)((int)fVar6 + 0xa4);

      obj->acc_verm_gib = *(dword *)((int)fVar6 + 0xa8);

      *(uint *)&obj->field_0xd8 = *(uint *)&obj->field_0xd8 | 0x2000000;

      if (local_78 < *(float *)(DAT_00632ed8 + 0xd8) * *(float *)(DAT_00632ed8 + 0xd8)) {

        sound_play_obj(0x4e6,obj);

        obj->gap_E4 = 0x2a;

      }

      break;

    }

    goto LAB_004d2124;

  case 0x2a:

    iVar8 = *(int *)&obj->field_0x100;

    if (((((fVar6 != 0.0) && (*(int *)((int)fVar6 + 4) != 0)) &&

         ((*(uint *)((int)fVar6 + 0xd8) & 0x4000c000) == 0)) &&

        (*(float *)((int)fVar6 + 0x278) < *(float *)((int)fVar6 + 0x1c0))) &&

       (((iVar7 = FUN_004a6160(fVar6), iVar7 == 0 ||

         ((*(uint *)((int)fVar6 + 0xe0) & 0x2000000) == 0)) || (4.0 <= *(float *)(iVar8 + 0x54)))))

    {

      iVar8 = FUN_004a6180(fVar6);

      if (iVar8 != 0) {

        uVar5 = obj->field_E0;

        if ((*(byte *)((int)fVar6 + 0xe0) & 8) == 0) {

          obj->field_E0 = uVar5 & 0xffffffef;

        }

        else if ((uVar5 & 0x10) == 0) goto LAB_004d211b;

      }

      obj->field_0x208 = 0;

      if ((int)fVar6 + 0xa0 == 0) {

        local_70 = 0.0;

      }

      else {

        fVar11 = (float10)FUN_0050a400(&obj->gap_A0,(int)fVar6 + 0xa0);

        local_70 = (float)fVar11;

      }

      fVar11 = (float10)FUN_0050a7c0(local_70,*(undefined4 *)&obj->field_0xc8);

      if (ABS(fVar11) != (float10)0.0) {

        uVar3 = FUN_004a7cb0((float)(fVar11 * (float10)0.05),0x3e800000);

        obj->field_0x208 = uVar3;

        *(float *)&obj->field_0x158 = local_70;

        *(uint *)&obj->field_0xd8 = *(uint *)&obj->field_0xd8 | 0x1000000;

      }

      if (local_74 != 0.0) {

        puVar10 = *(undefined4 **)&obj->field_0x100;

        if (puVar10[3] != 0) {

          fVar11 = (float10)FUN_0050a400(puVar10[3] + 0xa0,&obj->gap_A0);

          fVar11 = (float10)FUN_004d5780((float)(fVar11 - (float10)20.0),

                                         (float)((float10)20.0 + fVar11));

          puVar10[1] = (float)fVar11;

          FUN_00451560(puVar10 + 1);

          fVar11 = (float10)FUN_004d5780(*(undefined4 *)(DAT_00632ed8 + 200),

                                         *(undefined4 *)(DAT_00632ed8 + 0xcc));

          puVar10[2] = (float)fVar11;

          *puVar10 = *(undefined4 *)(DAT_00632ed8 + 0xd0);

        }

        obj->gap_E4 = 0x23;

        if (local_6c < *(float *)(DAT_00632ed8 + 0xd8) * *(float *)(DAT_00632ed8 + 0xd8)) {

          FUN_00456f80(2,*(undefined4 *)(DAT_00632ed8 + 1000),fVar6,obj,0,0);

        }

      }

      break;

    }

LAB_004d2124:

    sound_play_obj(0x4f5,obj);

    obj->gap_E4 = 0x2b;

    pfVar2[3] = 0.0;

    break;

  case 0x2b:

    if (0.73333335 < (float)obj->field_14) {

      dVar4 = obj->field_274;

      if ((dVar4 != 0) && (*(int *)(dVar4 + 4) == 0xdb)) {

        *(undefined4 *)(dVar4 + 0xe4) = 2;

      }

      obj->acc_grenade_do_stopped = obj->acc_grenade_do_stopped | 0x40;

    }

    if (fVar9 != 0.0) {

      ANM_DumpCluster(&obj->gap_A0);

      sound_play_obj(0x4ea,obj);

      obj->gap_E4 = 0x1f;

      obj->acc_grenade_do_stopped = obj->acc_grenade_do_stopped | 0x840;

    }

    break;

  case 0x2c:

    local_30 = obj->gap_A0;

    local_2c = *(undefined4 *)&obj->field_0xa4;

    local_28 = *(undefined4 *)&obj->field_0xa8;

    fx_get_free_effect__Fv();

    if (pfVar2[0xe] != 0.0) {

      FUN_00448920(pfVar2[0xe]);

    }

    pfVar2[0xe] = 0.0;

    sound_play_obj(0x4f3,obj);

    obj->gap_E4 = 0x20;

    obj->field_184 = 0;

    obj->acc_grenade_do_stopped = obj->acc_grenade_do_stopped & 0xfffff7ff;

    ANM_DumpCluster(&obj->gap_A0);

    FUN_00499280(obj);

    object_stop_movement(obj);

    if (0.0 < *(float *)&obj->field_0xa8) {

      dVar4 = object_allocate_type(0xdb,0x11);

      FUN_004979b0(dVar4,obj);

      *(undefined4 *)(dVar4 + 0xc4) = *(undefined4 *)&obj->field_0xc4;

      *(undefined4 *)(dVar4 + 0xe4) = 0;

      obj->field_274 = dVar4;

      *(OBJECT **)(dVar4 + 0x274) = obj;

    }

    goto switchD_004d1ccc_caseD_20;

  case 0x2d:

    if (pfVar2[0xe] == 0.0) {

      local_1c = obj;

      local_20 = 0xffffffff;

      local_24 = 8;

      fVar6 = (float)fx_get_free_effect__Fv();

      pfVar2[0xe] = fVar6;

    }

    if (0.73333335 < (float)obj->field_14) {

      dVar4 = obj->field_274;

      if ((dVar4 != 0) && (*(int *)(dVar4 + 4) == 0xdb)) {

        *(undefined4 *)(dVar4 + 0xe4) = 2;

      }

      obj->acc_grenade_do_stopped = obj->acc_grenade_do_stopped | 0x40;

    }

    if (fVar9 != 0.0) {

      ANM_DumpCluster(&obj->gap_A0);

      puVar10 = *(undefined4 **)&obj->field_0x100;

      if (puVar10[3] != 0) {

        fVar11 = (float10)FUN_0050a400(puVar10[3] + 0xa0,&obj->gap_A0);

        fVar11 = (float10)FUN_004d5780((float)(fVar11 - (float10)80.0),

                                       (float)((float10)80.0 + fVar11));

        puVar10[1] = (float)fVar11;

        FUN_00451560(puVar10 + 1);

        fVar11 = (float10)FUN_004d5780(*(undefined4 *)(DAT_00632ed8 + 200),

                                       *(undefined4 *)(DAT_00632ed8 + 0xcc));

        puVar10[2] = (float)fVar11;

        *puVar10 = *(undefined4 *)(DAT_00632ed8 + 0xd0);

      }

      obj->gap_E4 = 0x24;

      obj->acc_grenade_do_stopped = obj->acc_grenade_do_stopped | 0x840;

      obj->field_184 = 0x3f800000;

      sound_play_obj(0x4e8,obj);

    }

    break;

  case 0x50:

    obj->field_0x20a = 0x18;

    obj->field_0x208 = 0;

    fVar11 = (float10)FUN_00518b70(obj,0);

    fVar9 = *pfVar2;

    *pfVar2 = (float)((float10)fVar9 - fVar11);

    if ((float10)0.0 <= (float10)fVar9 - fVar11) break;

    FUN_004d1a00(obj,*(undefined4 *)(DAT_00632ed8 + 0x140));

    if (pfVar2[3] == 0.0) {

      sound_play_obj(0x4f5,obj);

      obj->gap_E4 = 0x2b;

      break;

    }

LAB_004d288a:

    obj->gap_E4 = 0x25;

    break;

  case 0x5a:

    if (fVar9 != 0.0) {

      if (obj->field_184 == 0x3f800000) {

        obj->gap_E4 = 0x2c;

      }

      else {

        obj->gap_E4 = 0x27;

        FUN_004d1a00(obj,*(undefined4 *)(DAT_00632ed8 + 0x140));

      }

    }

    break;

  case 0x5b:

    obj->field_184 = 0;

    if (pfVar2[0xe] != 0.0) {

      FUN_00448920(pfVar2[0xe]);

    }

    pfVar2[0xe] = 0.0;

    obj->acc_grenade_do_stopped = obj->acc_grenade_do_stopped & 0xfffff3bf;

    obj->field_E0 = obj->field_E0 & 0xfffffffd;

    if (fVar9 != 0.0) {

      obj->gap_E4 = 0x5c;

      fVar11 = (float10)FUN_004d5780(*(undefined4 *)(DAT_00632ed8 + 0x134),

                                     *(undefined4 *)(DAT_00632ed8 + 0x138));

      *(float *)&obj->field_0xec = (float)fVar11;

    }

    break;

  case 0x5c:

    fVar11 = (float10)FUN_00518b70(obj,0);

    fVar11 = (float10)*(float *)&obj->field_0xec - fVar11;

    *(float *)&obj->field_0xec = (float)fVar11;

    if (fVar11 < (float10)0.0) {

      obj->gap_E4 = 0x5d;

    }

    break;

  case 0x5d:

    if (fVar9 != 0.0) {

      if (obj->field_184 == 0x3f800000) {

        obj->gap_E4 = 0x2c;

      }

      else {

        obj->gap_E4 = 0x27;

        FUN_004d1a00(obj,*(undefined4 *)(DAT_00632ed8 + 0x140));

      }

    }

    break;

  case 0x5e:

    fVar11 = (float10)FUN_00518b70(0,0);

    fVar11 = (float10)*(float *)&obj->field_0xec - fVar11;

    *(float *)&obj->field_0xec = (float)fVar11;

    if ((float10)0.0 <= fVar11) {

      if (obj->field_4 == 0xe6) {

        local_70 = *(float *)(DAT_00632ed8 + 0x10e8);

      }

      else if (obj->field_4 == 0x49) {

        local_70 = *(float *)(DAT_00632ed8 + 0x10ec);

      }

      else {

        local_70 = *(float *)(DAT_00632ed8 + 0x10f0);

      }

      if ((local_70 != 0.0) &&

         (((obj->field_E0 & 8) != 0 || (iVar8 = FUN_00512c80(obj,obj,0,local_70,2), iVar8 == 0))))

      break;

    }

    FUN_00497510(obj);

  }

switchD_004d1ccc_caseD_28:

  if ((obj->field_10 == 2) &&

     (((0.6333333 <= (float)obj->field_14 && ((float)obj->field_18 < 0.6333333)) ||

      ((1.9666667 <= (float)obj->field_14 && ((float)obj->field_18 < 1.9666667)))))) {

    sound_play_obj(0x4ed,obj);

  }

  return;

switchD_004d1ccc_caseD_20:

  obj->field_0x208 = 0;

  fVar11 = (float10)FUN_0050a400(&obj->gap_A0,&local_5c);

  local_70 = (float)fVar11;

  fVar11 = (float10)FUN_0050a7c0(local_70,*(undefined4 *)&obj->field_0xc8);

  if (ABS(fVar11) != (float10)0.0) {

    uVar3 = FUN_004a7cb0((float)(fVar11 * (float10)0.05),0x3e800000);

    obj->field_0x208 = uVar3;

    *(float *)&obj->field_0x158 = local_70;

    *(uint *)&obj->field_0xd8 = *(uint *)&obj->field_0xd8 | 0x1000000;

  }

  obj->acc_grenade_do_stopped = obj->acc_grenade_do_stopped & 0xffffffbf;

  if (local_74 != 0.0) {

    if (pfVar2[0xe] != 0.0) {

      FUN_00448920(pfVar2[0xe]);

    }

    pfVar2[0xe] = 0.0;

    puVar10 = *(undefined4 **)&obj->field_0x100;

    obj->gap_E4 = 0x21;

    if (puVar10[3] != 0) {

      fVar11 = (float10)FUN_0050a400(puVar10[3] + 0xa0,&obj->gap_A0);

      fVar12 = (float10)50.0 + fVar11;

      fVar11 = fVar11 - (float10)50.0;

LAB_004d27e4:

      fVar11 = (float10)FUN_004d5780((float)fVar11,(float)fVar12);

      puVar10[1] = (float)fVar11;

      FUN_00451560(puVar10 + 1);

      fVar11 = (float10)FUN_004d5780(*(undefined4 *)(DAT_00632ed8 + 200),

                                     *(undefined4 *)(DAT_00632ed8 + 0xcc));

      puVar10[2] = (float)fVar11;

      *puVar10 = *(undefined4 *)(DAT_00632ed8 + 0xd0);

    }

  }

  goto switchD_004d1ccc_caseD_28;

}

/* ===== FUN_004d3720 @ 0x004D3720 ===== */
/* WARNING: Struct "OBJECT": ignoring multiple overlapping fields */



undefined4 FUN_004d3720(OBJECT *param_1)



{

  dword *pdVar1;

  int iVar2;

  undefined4 *puVar3;

  undefined4 uVar4;

  float10 fVar5;

  undefined1 local_1c [16];

  float local_c;

  

  iVar2 = *(int *)&param_1->field_0x100;

  puVar3 = *(undefined4 **)(*(int *)(iVar2 + 0x24) + 0x100);

  pdVar1 = &param_1->gap_A0;

  FUN_004a76e0(*(int *)(iVar2 + 0x24),*(undefined4 *)(iVar2 + 0x28),pdVar1);

  FUN_00414690(pdVar1,local_1c);

  if (*(float *)&param_1->field_0xa8 < local_c) {

    *(float *)&param_1->field_0xa8 = local_c;

  }

  uVar4 = *puVar3;

  if (((float)param_1->gap_B8 != (float)*pdVar1) ||

     (*(float *)&param_1->field_0xbc != *(float *)&param_1->field_0xa4)) {

    fVar5 = (float10)FUN_0050a400(&param_1->gap_B8,pdVar1);

    fVar5 = (float10)FUN_00518b70(param_1,0,0x461c4000,(float)fVar5,&param_1->field_0xc8);

    FUN_004515b0((float)(fVar5 * (float10)30.0));

  }

  *(undefined4 *)(iVar2 + 0x34) = puVar3[10];

  *(uint *)&param_1->field_0xd8 = *(uint *)&param_1->field_0xd8 | 0x40;

  FUN_004967b0(param_1);

  fVar5 = (float10)FUN_00518b70(param_1,0);

  FUN_00403e60(param_1,(float)fVar5);

  FUN_004a7440(param_1);

  *(uint *)&param_1->field_0xd8 = *(uint *)&param_1->field_0xd8 | 0x20;

  *(undefined4 *)&param_1->field_0x10c = puVar3[9];

  return uVar4;

}

/* ===== FUN_004d3ed0 @ 0x004D3ED0 ===== */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

/* WARNING: Struct "OBJECT": ignoring multiple overlapping fields */

/* PS2 candidate: ripper_animselect (conf 0.489) */



void FUN_004d3ed0(OBJECT *obj)



{

  undefined4 uVar1;

  int iVar2;

  dword dVar3;

  bool bVar4;

  dword dVar5;

  int iVar6;

  float10 fVar7;

  

  iVar6 = *(int *)&obj->field_0x100;

  if (*(int *)&obj->field_0x210 != 0) {

    iVar2 = *(int *)(*(int *)&obj->field_0x210 + 0x1e0);

    if (iVar2 == 1) {

      return;

    }

    if (iVar2 == 0x4c) {

      return;

    }

  }

  dVar3 = obj->field_10;

  bVar4 = true;

  dVar5 = 1;

  switch(obj->gap_E4) {

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

    dVar5 = 2;

    break;

  case 10:

    dVar5 = 0x33;

    break;

  case 0xb:

    dVar5 = 9;

    break;

  case 0x14:

    if (dVar3 == 2) {

      return;

    }

    *(undefined4 *)&obj->field_0x10c = *(undefined4 *)(*(int *)(iVar6 + 0x24) + 0xfc);

    goto LAB_004d4031;

  case 0x15:

  case 0x6a:

    if (dVar3 == 1) {

      if ((obj->acc_vimp_set_run_anim & 2) == 0) goto LAB_004d4074;

    }

    else {

      if ((obj->acc_vimp_set_run_anim & 2) != 0) goto switchD_004d3f27_caseD_42;

LAB_004d4074:

      if (((float)obj->field_18 < 0.43333334) && (0.43333334 <= (float)obj->field_14)) {

        if (*(int *)(iVar6 + 0xc) != 0) {

          FUN_004d4350(obj,*(int *)(iVar6 + 0xc) + 0xa0,*(undefined4 *)(DAT_00632ed8 + 0x11c));

          *(undefined4 *)&obj->field_0xf0 = *(undefined4 *)(DAT_00632ed8 + 0xd14);

          obj->acc_rpman_tuba_horn_check = obj->acc_rpman_tuba_horn_check - 1;

          dVar5 = 0x32;

          break;

        }

        obj->acc_rpman_tuba_horn_check = 0;

      }

    }

    dVar5 = 0x32;

    break;

  case 0x1f:

  case 0x22:

  case 0x24:

  case 0x2c:

  case 0x3d:

    dVar5 = 0x2a;

    break;

  case 0x20:

    if ((dVar3 == 0x28) || (dVar3 == 0x29)) {

LAB_004d41e1:

      bVar4 = false;

      dVar5 = dVar3;

    }

    else {

      iVar6 = FUN_004d5730(100);

      dVar5 = (iVar6 < 0x33) + 0x28;

      bVar4 = false;

    }

    break;

  case 0x25:

  case 0x26:

    dVar5 = 1;

    bVar4 = false;

    break;

  case 0x27:

    dVar5 = 0x32;

    bVar4 = false;

    break;

  case 0x2a:

    dVar5 = 10;

    bVar4 = false;

    break;

  case 0x2b:

  case 0x2d:

  case 0x47:

    dVar5 = 0x2b;

    bVar4 = false;

    break;

  case 0x3e:

    if ((dVar3 == 0x28) || (dVar3 == 0x29)) goto LAB_004d41e1;

    iVar6 = FUN_004d5730(100);

    dVar5 = (iVar6 < 0x33) + 0x28;

    bVar4 = false;

    break;

  case 0x41:

    dVar5 = 0x32;

    bVar4 = false;

    break;

  case 0x42:

  case 0x66:

switchD_004d3f27_caseD_42:

    dVar5 = 1;

    break;

  case 0x44:

    dVar5 = 10;

    bVar4 = false;

    break;

  case 0x45:

  case 0x46:

    dVar5 = 0x33;

    bVar4 = false;

    break;

  case 0x55:

    if ((obj->acc_vimp_set_run_anim & 2) == 0) {

      return;

    }

    if ((0.0 <= *(float *)&obj->field_0xf0) || (*(int *)(iVar6 + 0xc) == 0))

    goto switchD_004d3f27_caseD_42;

    obj->gap_E4 = 0x56;

LAB_004d3f6e:

    dVar5 = 0x32;

    break;

  case 0x56:

    if (((*(int *)(iVar6 + 0xc) != 0) && ((float)obj->field_18 < 0.43333334)) &&

       (0.43333334 <= (float)obj->field_14)) {

      if (obj->field_4 == 0xe6) {

        uVar1 = *(undefined4 *)(DAT_00632ed8 + 0x11c);

      }

      else {

        uVar1 = *(undefined4 *)(DAT_00632ed8 + 0xf0);

      }

      FUN_004d4350(obj,*(int *)(iVar6 + 0xc) + 0xa0,uVar1);

    }

    if ((obj->acc_vimp_set_run_anim & 2) == 0) goto LAB_004d3f6e;

    fVar7 = (float10)FUN_004d5780(*(undefined4 *)(DAT_00632ed8 + 0xd0c),

                                  *(undefined4 *)(DAT_00632ed8 + 0xd10));

    *(float *)&obj->field_0xf0 = (float)fVar7;

    dVar5 = 1;

    obj->gap_E4 = 0x55;

    break;

  case 0x5a:

  case 0x6c:

    if ((dVar3 == 0x31) || (dVar3 == 0x34)) goto LAB_004d41e1;

    iVar6 = FUN_004d5730(100);

    bVar4 = false;

    dVar5 = ((iVar6 < 0x33) - 1 & 0xfffffffd) + 0x34;

    break;

  case 0x5b:

    bVar4 = false;

  case 0x5e:

    dVar5 = 0x2c;

    break;

  case 0x5c:

    if (dVar3 == 0x2d) {

      return;

    }

    if (dVar3 == 0x30) {

      return;

    }

    iVar6 = FUN_004d5730(100);

    dVar5 = ((iVar6 < 0x33) - 1 & 0xfffffffd) + 0x30;

    break;

  case 0x5d:

    dVar5 = 0x2e;

    bVar4 = false;

    break;

  case 0x98:

    dVar5 = 0x39;

  }

  if (dVar3 != dVar5) {

    if (dVar5 == 2) {

LAB_004d4031:

      FUN_004034a0(obj,2,0x21,1,(float)obj->field_1B4 * *(float *)&obj->field_0xc4,0x3e2aaaab);

      return;

    }

    if (bVar4) {

      anim_select_check();

      return;

    }

    anim_select_check2(obj,dVar5);

  }

  return;

}

/* ===== FUN_004d4350 @ 0x004D4350 ===== */
/* WARNING: Struct "OBJECT": ignoring multiple overlapping fields */

/* PS2 candidate: make_spit__FP6OBJECTP3P3Df (conf 0.437) */



void FUN_004d4350(dword param_1,int param_2,float param_3)



{

  float fVar1;

  dword dVar2;

  float fVar3;

  int iVar4;

  OBJECT *obj;

  float10 fVar5;

  char *pcVar6;

  undefined4 uVar7;

  undefined1 *puVar8;

  undefined1 local_34 [20];

  undefined4 local_20;

  OBJECT *local_1c;

  

  if (*(int *)(param_1 + 4) == 0xe6) {

    uVar7 = 0xe8;

  }

  else {

    uVar7 = 0x5a;

  }

  iVar4 = FUN_00497d70(uVar7);

  if (iVar4 != 0) {

    obj = (OBJECT *)object_allocate_type(0x374,0);

    if (obj != (OBJECT *)0x0) {

      object_copy_personality(obj);

      FUN_00497a50(obj);

      puVar8 = local_34;

      local_20 = 0xffffffff;

      uVar7 = 4;

      local_1c = obj;

      if (*(int *)(param_1 + 4) == 0xe6) {

        pcVar6 = s_fx_ripper_large_proj_00561404;

        *(undefined4 *)&obj->field_0xe8 = 1;

        fx_get_free_effect__Fv();

        iVar4 = FUN_004d5730(100,pcVar6,uVar7,puVar8);

        if (iVar4 < 0x32) {

          uVar7 = 0x4cb;

        }

        else {

          uVar7 = 0x4cc;

        }

        sound_play_3dpos(uVar7,param_1 + 0xa0);

        obj->acc_rpman_tuba_horn_check = 0x636;

        obj->acc_minishop_use_icon = 0x4d8;

        obj->gap_FC = 0x4d9;

      }

      else {

        pcVar6 = s_fx_ripper_medium_proj_005613ec;

        *(undefined4 *)&obj->field_0xe8 = 0;

        fx_get_free_effect__Fv();

        iVar4 = FUN_004d5730(100,pcVar6,uVar7,puVar8);

        if (iVar4 < 0x32) {

          uVar7 = 0x4e2;

        }

        else {

          uVar7 = 0x4e3;

        }

        sound_play_3dpos(uVar7,param_1 + 0xa0);

        obj->acc_rpman_tuba_horn_check = 0x637;

        obj->acc_minishop_use_icon = 0x4ef;

      }

      FUN_004a76e0(param_1,0,&obj->gap_A0);

      FUN_00499280(obj);

      *(undefined4 *)&obj->field_0xc8 = *(undefined4 *)(param_1 + 200);

      *(undefined4 *)&obj->field_0xcc = 0;

      *(undefined4 *)&obj->field_0xd0 = 0;

      dVar2 = *(dword *)(param_1 + 0x18c);

      *(dword *)&obj->field_0x11c = obj->field_194;

      *(dword *)&obj->field_0x10c = obj->field_194;

      obj->field_18C = dVar2;

      fVar5 = (float10)FUN_0050a520(param_2,&obj->gap_A0);

      fVar1 = (float)(fVar5 / (float10)*(float *)&obj->field_0x10c);

      fVar3 = (fVar1 * (float)obj->field_1B8 * fVar1 * 0.5 +

              (*(float *)(param_2 + 8) - *(float *)&obj->field_0xa8)) / fVar1;

      fVar5 = (float10)FUN_004d5780((1.0 - param_3 * 0.01) * fVar3,(param_3 * 0.01 + 1.0) * fVar3);

      *(float *)&obj->field_0x118 = (float)fVar5;

      *(float *)&obj->field_0x108 = (float)fVar5;

      **(float **)&obj->field_0x100 = fVar1 + 1.0;

      (*(undefined4 **)&obj->field_0x100)[1] = **(undefined4 **)&obj->field_0x100;

      obj->field_274 = param_1;

    }

  }

  return;

}

/* ===== FUN_004d4580 @ 0x004D4580 ===== */
float10 FUN_004d4580(float param_1,int param_2,float param_3)



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

    fVar3 = (float10)FUN_0050a400((int)param_1 + 0xa0,param_2);

    param_1 = (float)fVar3;

  }

  fVar3 = (float10)FUN_0050a7c0(param_1,*(undefined4 *)(iVar1 + 200));

  if (ABS(fVar3) == (float10)0.0) {

    return (float10)0.0;

  }

  uVar2 = FUN_004a7cb0((float)fVar3 * 0.05,0x3e800000);

  *(undefined1 *)(iVar1 + 0x208) = uVar2;

  *(float *)(iVar1 + 0x158) = param_1;

  *(uint *)(iVar1 + 0xd8) = *(uint *)(iVar1 + 0xd8) | 0x1000000;

  return (float10)(float)fVar3;

}

/* ===== FUN_004d4630 @ 0x004D4630 ===== */
void FUN_004d4630(undefined4 *param_1,undefined4 *param_2,float param_3)



{

  float fVar1;

  int iVar2;

  undefined1 uVar3;

  float10 fVar4;

  float10 fVar5;

  

  iVar2 = (int)param_1;

  fVar4 = (float10)FUN_0050a520((int)param_1 + 0xa0,param_2);

  if ((float10)param_3 <= fVar4) {

    *(undefined1 *)((int)param_1 + 0x208) = 0;

    if (param_2 == (undefined4 *)0x0) {

      param_1 = param_2;

    }

    else {

      fVar5 = (float10)FUN_0050a400((int)param_1 + 0xa0,param_2);

      param_1 = (undefined4 *)(float)fVar5;

    }

    fVar5 = (float10)FUN_0050a7c0(param_1,*(undefined4 *)(iVar2 + 200));

    fVar1 = (float)fVar5;

    if (ABS(fVar5) == (float10)0.0) {

      fVar1 = 0.0;

    }

    else {

      uVar3 = FUN_004a7cb0(fVar1 * 0.05,0x3e800000);

      *(undefined1 *)(iVar2 + 0x208) = uVar3;

      *(undefined4 **)(iVar2 + 0x158) = param_1;

      *(uint *)(iVar2 + 0xd8) = *(uint *)(iVar2 + 0xd8) | 0x1000000;

    }

    *(undefined4 *)(iVar2 + 0x15c) = *param_2;

    *(undefined4 *)(iVar2 + 0x160) = param_2[1];

    *(undefined4 *)(iVar2 + 0x164) = param_2[2];

    *(uint *)(iVar2 + 0xd8) = *(uint *)(iVar2 + 0xd8) | 0x2000000;

    if (ABS(fVar1) < 10.0) {

      uVar3 = FUN_004a7cb0((float)fVar4 * 0.1,0x3e4ccccd);

      *(undefined1 *)(iVar2 + 0x20a) = uVar3;

      return;

    }

    *(undefined1 *)(iVar2 + 0x20a) = 3;

  }

  return;

}

/* ===== FUN_004d4760 @ 0x004D4760 ===== */
/* PS2 candidate: enemy_check_player_grab__FP6OBJECTif (conf 0.486) */



int FUN_004d4760(int param_1,undefined4 param_2,float param_3)



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

  

  FUN_004a76e0(param_1,param_2,local_c);

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

          ((iVar4 = FUN_004a6160(iVar1), iVar4 != 0 || (iVar4 = FUN_004a6180(iVar1), iVar4 != 0)))))

         ) && ((iVar4 = *(int *)(param_1 + 0x100), *(int *)(iVar1 + 4) != 0 &&

               ((*(uint *)(iVar1 + 0xd8) & 0x4000c000) == 0)))) &&

       ((*(float *)(iVar1 + 0x278) < *(float *)(iVar1 + 0x1c0) &&

        (((iVar5 = FUN_004a6160(iVar1), iVar5 == 0 || ((*(uint *)(iVar1 + 0xe0) & 0x2000000) == 0))

         || (4.0 <= *(float *)(iVar4 + 0x54))))))) {

      iVar4 = FUN_004a6180(iVar1);

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

/* ===== FUN_004d49c0 @ 0x004D49C0 ===== */
undefined4 FUN_004d49c0(int param_1)



{

  if ((*(int *)(param_1 + 0xe8) != 100) && (*(int *)(param_1 + 0xe8) != 0x65)) {

    return 1;

  }

  return 0;

}

/* ===== kabutoai_is_punch_anim__FP6OBJECT_2 @ 0x004D49E0 ===== */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

/* WARNING: Struct "OBJECT": ignoring multiple overlapping fields */



bool kabutoai_is_punch_anim__FP6OBJECT_2(OBJECT *p0)



{

  return p0->gap_E4 == 0x98;

}

/* ===== FUN_004d4a00 @ 0x004D4A00 ===== */
void FUN_004d4a00(int param_1)



{

  if ((*(int *)(param_1 + 0xe8) != 100) && (*(int *)(param_1 + 0xe8) != 0x65)) {

    *(undefined4 *)(param_1 + 0xe4) = 0x98;

  }

  return;

}

/* ===== FUN_004d4a20 @ 0x004D4A20 ===== */
void FUN_004d4a20(int param_1)



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

/* ===== FUN_004d4ae0 @ 0x004D4AE0 ===== */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

/* WARNING: Struct "OBJECT": ignoring multiple overlapping fields */

/* PS2 candidate: ripnest_move (conf 0.394) */



void FUN_004d4ae0(OBJECT *obj)



{

  int *piVar1;

  undefined4 *puVar2;

  uint uVar3;

  dword dVar4;

  int iVar5;

  bool bVar6;

  float10 fVar7;

  

  piVar1 = *(int **)&obj->field_0x100;

  if (obj->gap_E4 == 0) {

    sound_play_obj(0x4ff,obj);

    obj->gap_E4 = 1;

  }

  dVar4 = obj->field_10;

  uVar3 = obj->acc_vimp_set_run_anim & 2;

  switch(obj->gap_E4) {

  case 1:

    obj->gap_E4 = 2;

    dVar4 = object_allocate_type(0xdb,0x11);

    FUN_004979b0(dVar4,obj);

    *(undefined4 *)(dVar4 + 0xe4) = 0;

    obj->field_274 = dVar4;

    return;

  case 2:

    bVar6 = dVar4 == 0xb;

    break;

  case 3:

    if (dVar4 == 10) {

      if (uVar3 == 0) {

        return;

      }

      obj->gap_E4 = 5;

      iVar5 = object_allocate_type(0xe5,0x11);

      puVar2 = *(undefined4 **)(iVar5 + 0x100);

      fVar7 = (float10)FUN_004d5780(*(undefined4 *)(DAT_00632ed8 + 0xc0),

                                    *(undefined4 *)(DAT_00632ed8 + 0xc4));

      *(float *)(iVar5 + 0xc4) = (float)fVar7;

      FUN_004993c0(iVar5,&obj->gap_A0);

      fVar7 = (float10)FUN_004d5760(0x43b40000);

      *(float *)(iVar5 + 200) = (float)fVar7;

      *(undefined4 *)(iVar5 + 0x108) = 0x41c80000;

      *(undefined4 *)(iVar5 + 0xe4) = 0x50;

      puVar2[4] = obj;

      *puVar2 = 0x3f800000;

      puVar2[5] = obj->gap_A0;

      puVar2[6] = *(undefined4 *)&obj->field_0xa4;

      puVar2[7] = *(undefined4 *)&obj->field_0xa8;

      *piVar1 = *piVar1 + 1;

      return;

    }

  case 4:

    bVar6 = dVar4 == 0;

    break;

  case 5:

    if ((uVar3 != 0) && (*piVar1 < *(int *)(DAT_00632ed8 + 0x148))) {

      obj->gap_E4 = 3;

      return;

    }

  default:

    goto switchD_004d4b2b_default;

  }

  if ((bVar6) && (uVar3 != 0)) {

    obj->gap_E4 = 5;

  }

switchD_004d4b2b_default:

  return;

}

/* ===== FUN_004d4db0 @ 0x004D4DB0 ===== */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

/* WARNING: Struct "OBJECT": ignoring multiple overlapping fields */



void FUN_004d4db0(OBJECT *obj)



{

  undefined4 uVar1;

  dword dVar2;

  uint uVar3;

  float10 fVar4;

  

  uVar3 = obj->acc_vimp_set_run_anim & 2;

  switch(obj->gap_E4) {

  case 0:

    if ((obj->field_10 == 0xb) && (uVar3 != 0)) {

      obj->gap_E4 = 1;

      return;

    }

    break;

  case 1:

    dVar2 = obj->field_274;

    if (((dVar2 != 0) && (*(int *)(dVar2 + 0x1e0) == 0x17)) &&

       (((float)obj->gap_A0 != *(float *)(dVar2 + 0xa0) ||

        (*(float *)&obj->field_0xa4 != *(float *)(dVar2 + 0xa4))))) {

      uVar1 = *(undefined4 *)(DAT_00632ed8 + 0x3d4);

      obj->gap_E4 = 3;

      *(undefined4 *)&obj->field_0xec = uVar1;

    }

    break;

  case 2:

    if ((obj->field_10 == 0xc) && (uVar3 != 0)) {

      FUN_00497510(obj);

      return;

    }

    break;

  case 3:

    fVar4 = (float10)FUN_00518b70(obj,0);

    fVar4 = (float10)*(float *)&obj->field_0xec - fVar4;

    *(float *)&obj->field_0xec = (float)fVar4;

    if (fVar4 < (float10)0.0) {

      obj->gap_E4 = 2;

      return;

    }

  }

  return;

}

/* ===== rndstart @ 0x004D5710 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void rndstart(void)



{

  DWORD DVar1;

  

  DVar1 = timeGetTime();

  _DAT_00632950 = DVar1 & 0x7fff;

  FUN_00543dc7(_DAT_00632950);

  return;

}

/* ===== FUN_004d5730 @ 0x004D5730 ===== */
/* PS2 candidate: rndint (conf 0.75) */



int FUN_004d5730(int param_1)



{

  int iVar1;

  

  iVar1 = _rand();

  return iVar1 * param_1 >> 0xf;

}

/* ===== FUN_004d5740 @ 0x004D5740 ===== */
/* PS2 candidate: rndintrange (conf 0.54) */



int FUN_004d5740(int param_1,int param_2)



{

  int iVar1;

  

  iVar1 = _rand();

  return (iVar1 * ((param_2 - param_1) + 1) >> 0xf) + param_1;

}

/* ===== FUN_004d5760 @ 0x004D5760 ===== */
/* PS2 candidate: rndfloat (conf 0.413) */



float10 FUN_004d5760(float param_1)



{

  int iVar1;

  

  iVar1 = _rand();

  return (float10)iVar1 * (float10)param_1 * (float10)3.0517578e-05;

}

/* ===== FUN_004d5780 @ 0x004D5780 ===== */
/* PS2 candidate: rndfloatrange (conf 0.672) */



float10 FUN_004d5780(float param_1,float param_2)



{

  int iVar1;

  

  iVar1 = _rand();

  return ((float10)param_2 - (float10)param_1) * (float10)iVar1 * (float10)3.0517578e-05 +

         (float10)param_1;

}

/* ===== FUN_004d5810 @ 0x004D5810 ===== */
/* PS2 candidate: rpboat_unlock_from_boat__FP6OBJECTT0 (conf 0.506) */



void FUN_004d5810(int param_1,int param_2)



{

  uint *puVar1;

  int iVar2;

  

  puVar1 = *(uint **)(param_1 + 0x100);

  if (param_2 != 0) {

    FUN_00495750(0x62b,param_1);

    FUN_00495750(0x626,param_1);

    FUN_00495750(0x629,param_1);

    FUN_00495750(0x62e,param_1);

    FUN_00495750(0x6fc,param_1);

    FUN_00495750(0x6fc,param_2);

    FUN_00495750(0x36c,param_1);

    *(undefined4 *)(param_1 + 0x210) = 0;

    *(undefined4 *)(param_2 + 0x274) = 0;

    FUN_0040d790();

    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 2;

    iVar2 = FUN_00456050(param_1);

    if (iVar2 != 0) {

      *(uint *)(iVar2 + 0xd8) = *(uint *)(iVar2 + 0xd8) & 0xbfffffff;

    }

    *puVar1 = *puVar1 & 0xfffffffd;

    FUN_004a76e0(param_2,5,param_1 + 0xa0);

    iVar2 = reaper_0052e4a0(param_1);

    if (iVar2 != 0) {

      reaper_00530bd0(param_2,0,0,0,5,0);

    }

    *(undefined4 *)(param_2 + 0x18c) = 0;

    sound_play_obj(0x62a,param_2);

  }

  return;

}

/* ===== FUN_004d5910 @ 0x004D5910 ===== */
/* PS2 candidate: rpboat_lock_to_boat__FP6OBJECTT0 (conf 0.406) */



void FUN_004d5910(int param_1,int param_2)



{

  uint *puVar1;

  int iVar2;

  int iVar3;

  

  iVar2 = *(int *)(param_1 + 0x100);

  *(int *)(param_1 + 0x210) = param_2;

  *(undefined4 *)(param_1 + 0x214) = 9;

  *(undefined4 *)(param_1 + 0x218) = 0;

  FUN_004c4880(param_1);

  anim_select_check(param_1,0x91);

  if (*(int *)(param_2 + 0x1e0) != 0x5a) {

    object_change_ospec(param_2,0x5a);

  }

  *(int *)(param_2 + 0x274) = param_1;

  iVar3 = FUN_00456050(param_1);

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

  FUN_004ba920(param_1);

  return;

}

/* ===== FUN_004d59d0 @ 0x004D59D0 ===== */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

/* WARNING: Struct "OBJECT": ignoring multiple overlapping fields */

/* PS2 candidate: rpboat_ghost_logic__FP6OBJECT (conf 0.391) */



void FUN_004d59d0(OBJECT *obj)



{

  float fVar1;

  int iVar2;

  float10 fVar3;

  

  iVar2 = *(int *)&obj->field_0x100;

  fVar3 = (float10)FUN_00518b70(obj,0);

  obj->acc_grenade_do_stopped = obj->acc_grenade_do_stopped | 0x400;

  obj->gap_A0 = (dword)(float)(((float10)(float)obj->acc_army_platoon_base_attack +

                               (float10)(float)obj->gap_128) * fVar3 * (float10)0.5 +

                              (float10)(float)obj->gap_A0);

  *(float *)&obj->field_0xa4 =

       (float)(((float10)(float)obj->acc_TargetCenter + (float10)*(float *)&obj->field_0x12c) *

               fVar3 * (float10)0.5 + (float10)*(float *)&obj->field_0xa4);

  fVar1 = (float)obj->acc_TargetCenter;

  obj->acc_army_platoon_base_attack = obj->gap_128;

  obj->acc_TargetCenter = *(dword *)&obj->field_0x12c;

  obj->acc_TargetCenter = *(dword *)&obj->field_0x130;

  *(float *)&obj->field_0xa8 =

       (float)(((float10)fVar1 + (float10)*(float *)&obj->field_0x130) * fVar3 * (float10)0.5 +

              (float10)*(float *)&obj->field_0xa8);

  FUN_004a4360(obj);

  obj->acc_grenade_do_stopped = obj->acc_grenade_do_stopped & 0xfffffbff;

  fVar3 = (float10)FUN_00518b70(obj,0);

  FUN_00403e60(obj,(float)fVar3);

  *(uint *)&obj->field_0xd8 = *(uint *)&obj->field_0xd8 | 0x40;

  FUN_004d5b50(obj);

  fVar3 = (float10)FUN_00518b70(obj,0,0x461c4000,*(undefined4 *)(iVar2 + 0x48),

                                (float *)(iVar2 + 0x40));

  FUN_004515b0((float)(fVar3 * (float10)*(float *)(DAT_00632ed8 + 0xe04)));

  fVar3 = (float10)FUN_00518b70(obj,0,0x461c4000,*(undefined4 *)(iVar2 + 0x4c),

                                (undefined4 *)(iVar2 + 0x44));

  FUN_004515b0((float)(fVar3 * (float10)*(float *)(DAT_00632ed8 + 0xe00)));

  FUN_0053e460(&obj->field_294,-*(float *)(iVar2 + 0x40),*(undefined4 *)(iVar2 + 0x44),

               *(undefined4 *)&obj->field_0xc8);

  return;

}

/* ===== FUN_004d5b50 @ 0x004D5B50 ===== */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

/* WARNING: Struct "OBJECT": ignoring multiple overlapping fields */

/* PS2 candidate: rpboat_tilt__FP6OBJECT (conf 0.453) */



void FUN_004d5b50(OBJECT *obj)



{

  float *pfVar1;

  float fVar2;

  int iVar3;

  uint uVar4;

  OBJECT *pOVar5;

  int iVar6;

  float10 fVar7;

  undefined4 local_94;

  dword local_90;

  undefined4 local_8c;

  undefined4 local_88;

  dword local_84;

  undefined4 local_80;

  dword local_7c [2];

  dword local_74;

  undefined4 local_70;

  undefined4 local_6c;

  undefined1 local_44 [68];

  

  iVar3 = *(int *)&obj->field_0x100;

  local_94 = 0;

  pOVar5 = (OBJECT *)obj->field_274;

  if ((OBJECT *)obj->field_274 == (OBJECT *)0x0) {

    pOVar5 = obj;

  }

  iVar6 = FUN_0052e480(pOVar5);

  if (((iVar6 != 0) && (obj->field_274 != 0)) && (DAT_00632a88 == obj->field_274)) {

    if ((char)((uint)*(undefined4 *)(DAT_00632a88 + 0x20c) >> 8) < '\0') {

      ref_get_anode2(local_44,&local_94,obj,obj->field_10,4,0);

      FUN_0040d7e0(local_44);

      AudioSetSpeakerConfig__F14SPEAKER_SYSTEM(local_94);

    }

    else {

      FUN_0040d790();

    }

  }

  *(undefined4 *)(iVar3 + 0x48) = 0;

  *(undefined4 *)(iVar3 + 0x4c) = 0;

  uVar4 = **(uint **)&obj->field_0x104;

  if ((char)uVar4 < '\0') {

    if ((uVar4 & 0x28) != 0) {

      if ((float)obj->acc_minishop_use_icon < 0.0 == ((float)obj->acc_minishop_use_icon == 0.0)) {

        fVar7 = (float10)FUN_00518b70(0,0);

        obj->acc_minishop_use_icon =

             (dword)(float)((float10)(float)obj->acc_minishop_use_icon - fVar7);

      }

      else if (0.0 < (float)(*(uint **)&obj->field_0x104)[9]) {

        local_74 = obj->gap_A0;

        local_70 = *(undefined4 *)&obj->field_0xa4;

        local_6c = *(undefined4 *)&obj->field_0xa8;

        fx_get_free_effect__Fv();

        obj->acc_minishop_use_icon = 0x3e4ccccd;

      }

      goto LAB_004d5d41;

    }

    uVar4 = obj->field_E0;

    obj->acc_minishop_use_icon = 0;

    if (obj->field_0x20a == '\0') {

      if ((uVar4 & 0x10) == 0) {

        if (((uVar4 & 0x20) != 0) || ((uVar4 & 8) == 0)) {

          *(undefined4 *)(iVar3 + 0x48) = 0;

          goto LAB_004d5d41;

        }

        fVar2 = *(float *)(DAT_00632ed8 + 0xdfc);

      }

      else {

        obj->field_E0 = uVar4 & 0xffffffef | 8;

        fVar2 = *(float *)(DAT_00632ed8 + 0xdfc);

      }

      goto LAB_004d5d3c;

    }

    obj->field_E0 = uVar4 & 0xffffffd7 | 0x10;

    if ((uVar4 & 1) == 0) {

      fVar2 = *(float *)(DAT_00632ed8 + 0xd94);

    }

    else {

      fVar2 = *(float *)(DAT_00632ed8 + 0xe10);

    }

  }

  else {

    obj->acc_minishop_use_icon = 0;

    obj->field_E0 = obj->field_E0 & 0xffffffd7 | 0x10;

    if (*(float *)(DAT_00632ed8 + 0xf10) < *(float *)&obj->field_0x130) {

      *(undefined4 *)(iVar3 + 0x48) = *(undefined4 *)(iVar3 + 0x40);

      goto LAB_004d5d41;

    }

    fVar2 = *(float *)(DAT_00632ed8 + 0xf14);

LAB_004d5d3c:

    fVar2 = -fVar2;

  }

  *(float *)(iVar3 + 0x48) = fVar2;

LAB_004d5d41:

  if (((**(byte **)&obj->field_0x104 & 0x28) == 0) &&

     (25.0 < *(float *)(*(byte **)&obj->field_0x104 + 0x24))) {

    local_90 = obj->gap_128;

    local_8c = *(undefined4 *)&obj->field_0x12c;

    local_88 = *(undefined4 *)&obj->field_0x130;

    local_84 = obj->gap_298;

    local_80 = *(undefined4 *)&obj->field_0x2a8;

    local_7c[0] = obj->gap_2B8;

    FUN_0050a810(&local_90,&local_8c,&local_88);

    FUN_0050a810(&local_84,&local_80,local_7c);

    fVar7 = (float10)FUN_00516290(&local_90,&local_84);

    *(float *)(iVar3 + 0x4c) =

         (float)(fVar7 * (float10)1.4285715 * (float10)*(float *)(DAT_00632ed8 + 0xd90));

  }

  pfVar1 = (float *)(iVar3 + 0x40);

  if ((obj->field_E0 & 8) == 0) {

    fVar7 = (float10)FUN_00518b70(obj,0,0x461c4000,*(undefined4 *)(iVar3 + 0x48),pfVar1);

    FUN_004515b0((float)(fVar7 * (float10)*(float *)(DAT_00632ed8 + 0xe04)));

  }

  else {

    if ((obj->field_E0 & 0x20) == 0) {

      fVar7 = (float10)FUN_00518b70(obj,0,0x461c4000,*(undefined4 *)(iVar3 + 0x48),pfVar1);

      fVar7 = fVar7 * (float10)*(float *)(DAT_00632ed8 + 0xe08);

    }

    else {

      fVar7 = (float10)FUN_00518b70(obj,0,0x461c4000,*(undefined4 *)(iVar3 + 0x48),pfVar1);

      fVar7 = fVar7 * (float10)*(float *)(DAT_00632ed8 + 0xe0c);

    }

    FUN_004515b0((float)fVar7);

    if (*(float *)(iVar3 + 0x48) < 0.0) {

      *(float *)(iVar3 + 0x48) = *(float *)(iVar3 + 0x48) + 360.0;

    }

    if (*(float *)(iVar3 + 0x48) == *pfVar1) {

      uVar4 = obj->field_E0;

      if ((uVar4 & 0x20) == 0) {

        obj->field_E0 = uVar4 | 0x20;

      }

      else {

        obj->field_E0 = uVar4 & 0xffffffd7;

      }

    }

  }

  fVar7 = (float10)FUN_00518b70(obj,0,0x461c4000,*(undefined4 *)(iVar3 + 0x4c),

                                (undefined4 *)(iVar3 + 0x44));

  FUN_004515b0((float)(fVar7 * (float10)*(float *)(DAT_00632ed8 + 0xe00)));

  FUN_0053e460(&obj->field_294,-*pfVar1,*(undefined4 *)(iVar3 + 0x44),

               *(undefined4 *)&obj->field_0xc8);

  ANM_DumpCluster(obj,iVar3 + 0x60);

  return;

}

/* ===== FUN_004d73b0 @ 0x004D73B0 ===== */
void FUN_004d73b0(int param_1,undefined4 *param_2,undefined4 param_3)



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

    FUN_004a76e0(param_1,2,&local_60);

    fVar4 = (float10)FUN_0050a490(&local_60,param_2);

    fVar5 = (float10)FUN_0050a400(&local_60,param_2);

    local_44[0] = 0;

    FUN_0053e460(local_44,-(float)fVar4,0,(float)fVar5);

    local_24 = local_5c;

    local_34 = local_60;

    local_44[0] = local_44[0] | 0x10;

    local_14 = local_58;

    iVar1 = FUN_004aa550(0x29,*(undefined4 *)(*(int *)(param_1 + 0x274) + 0x18c),param_1,0,local_44,

                         0);

    iVar3 = *(int *)(param_1 + 0x274);

    if (*(int *)(param_1 + 0x274) == 0) {

      iVar3 = param_1;

    }

    *(int *)(iVar1 + 0x274) = iVar3;

    iVar2 = FUN_0052e480(iVar3);

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

/* ===== FUN_004d7500 @ 0x004D7500 ===== */
void FUN_004d7500(int param_1,int param_2,undefined4 param_3)



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

    (*(code *)PTR_FUN_00580c18)(local_44,param_1 + 0x294,*(int *)(param_1 + 0x2dc) + 0x88);

    FUN_004a76e0(param_1,2,&uStack_50);

    uStack_34 = uStack_50;

    uStack_24 = uStack_4c;

    uStack_14 = uStack_48;

    iVar1 = FUN_004aa550(0x1f,*(undefined4 *)(*(int *)(param_1 + 0x274) + 0x18c),param_1,0,local_44,

                         param_2);

    iVar3 = *(int *)(param_1 + 0x274);

    if (*(int *)(param_1 + 0x274) == 0) {

      iVar3 = param_1;

    }

    *(int *)(iVar1 + 0x274) = iVar3;

    iVar2 = FUN_0052e480(iVar3);

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

/* ===== FUN_004d77e0 @ 0x004D77E0 ===== */
/* PS2 candidate: charger_do_fx__FP6OBJECTiii (conf 0.418) */



void FUN_004d77e0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)



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

    uVar4 = FUN_0052e5b0(param_4[1]);

    FUN_004d7500(param_1,uVar4,*puVar3);

    return;

  case 4:

    iVar6 = FUN_0052e480(param_1);

    if ((((iVar6 != 0) && (*(int *)(iVar2 + 0x274) == 0)) &&

        (iVar6 = FUN_0052e5b0(*param_4), iVar6 != 0)) && (*(int *)(iVar6 + 0x210) == 0)) {

      param_1 = *(undefined4 *)(iVar2 + 0x188);

      reaper_00530bd0(iVar6,0,1,0,0x23,&param_1);

      FUN_004b7450(iVar6,0x23,4,&param_1);

    }

    break;

  case 5:

    iVar6 = *(int *)(param_1 + 0x274);

    puVar1 = *(uint **)(iVar6 + 0x100);

    FUN_00495750(0x62b,iVar6);

    FUN_00495750(0x626,iVar6);

    FUN_00495750(0x629,iVar6);

    FUN_00495750(0x62e,iVar6);

    FUN_00495750(0x6fc,iVar6);

    FUN_00495750(0x6fc,iVar2);

    FUN_00495750(0x36c,iVar6);

    *(undefined4 *)(iVar6 + 0x210) = 0;

    *(undefined4 *)(iVar2 + 0x274) = 0;

    FUN_0040d790();

    *(uint *)(iVar6 + 0xe0) = *(uint *)(iVar6 + 0xe0) | 2;

    iVar5 = FUN_00456050(iVar6);

    if (iVar5 != 0) {

      *(uint *)(iVar5 + 0xd8) = *(uint *)(iVar5 + 0xd8) & 0xbfffffff;

    }

    *puVar1 = *puVar1 & 0xfffffffd;

    FUN_004a76e0(iVar2,5,iVar6 + 0xa0);

    iVar6 = reaper_0052e4a0(iVar6);

    if (iVar6 != 0) {

      reaper_00530bd0(iVar2,0,0,0,5,0);

    }

    *(undefined4 *)(iVar2 + 0x18c) = 0;

    sound_play_obj(0x62a,iVar2);

    return;

  case 6:

    FUN_004d73b0(param_1,param_4,param_4[3]);

    return;

  }

  return;

}

/* ===== FUN_004d7b80 @ 0x004D7B80 ===== */
bool FUN_004d7b80(int param_1)



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
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

/* WARNING: Struct "OBJECT": ignoring multiple overlapping fields */



bool kabutoai_is_punch_anim__FP6OBJECT_3(OBJECT *p0)



{

  return p0->gap_E4 == 0x12d;

}

/* ===== FUN_004d7c60 @ 0x004D7C60 ===== */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

/* WARNING: Struct "OBJECT": ignoring multiple overlapping fields */

/* PS2 candidate: rpman_sfcaught (conf 0.311) */



void FUN_004d7c60(OBJECT *obj)



{

  int iVar1;

  int *piVar2;

  int in_stack_00000008;

  

  if ((float)obj->field_278 < *(float *)&obj->field_0x1c0) {

    iVar1 = *(int *)&obj->field_0xe8;

    switch(iVar1) {

    case 0:

    case 2:

    case 100:

    case 0x66:

    case 0x67:

      if (obj->gap_E4 == 0xdd) {

        return;

      }

    case 1:

    case 9:

    case 0xe:

      piVar2 = *(int **)&obj->field_0x100;

      if ((0x65 < iVar1) && (iVar1 < 0x68)) {

        if ((in_stack_00000008 != 0) && (*(int *)(in_stack_00000008 + 0x1e0) == 0x4d)) {

          *piVar2 = *(int *)(in_stack_00000008 + 0x274);

        }

        piVar2[0x7a] = obj->gap_E4;

        if (((obj->field_E0 & 0x1000000) != 0) && (piVar2[0x83] == 0)) {

          DAT_005a8578 = 0;

          obj->field_E0 = obj->field_E0 & 0xfeffffff;

          iVar1 = *piVar2;

          if ((iVar1 != 0) && ((*(int *)(iVar1 + 0x1e0) == 0x12 && (*(int *)(iVar1 + 0xe8) == 10))))

          {

            *piVar2 = 0;

          }

        }

      }

      if ((float)obj->field_278 < *(float *)&obj->field_0x1c0) {

        FUN_004e7ae0(obj);

      }

      if ((obj->field_10 != 0xaa) && (*(int *)(obj->field_8 + 0x2b0) != 0)) {

        FUN_004034a0(obj,0xaa,0x20,0,*(float *)&obj->field_0xc4 * 0.0,0x3e2aaaab);

      }

      obj->gap_E4 = 0x12d;

    }

  }

  return;

}

/* ===== FUN_004d7e10 @ 0x004D7E10 ===== */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

/* WARNING: Struct "OBJECT": ignoring multiple overlapping fields */



void FUN_004d7e10(OBJECT *obj)



{

  float fVar1;

  int iVar2;

  int iVar3;

  float10 fVar4;

  float10 fVar5;

  undefined4 uVar6;

  float local_8;

  float local_4;

  

  if (obj->gap_E4 != 0x12d) {

    return;

  }

  if (*(float *)&obj->field_0x1c0 <= (float)obj->field_278) {

    return;

  }

  iVar3 = *(int *)&obj->field_0x100;

  switch(*(undefined4 *)&obj->field_0xe8) {

  case 0:

  case 2:

    if (*(int *)(iVar3 + 0x134) != 0) {

      obj->gap_E4 = 0x22 - (*(int *)(iVar3 + 0xb0) != 0);

      return;

    }

  case 0xe:

    obj->gap_E4 = 10;

    return;

  case 1:

    obj->gap_E4 = 0x69;

  default:

    return;

  case 9:

    obj->gap_E4 = 0x78;

    return;

  case 100:

    fVar4 = (float10)FUN_004d5780(0x40800000,0x40e00000);

    *(float *)(iVar3 + 0xd0) = (float)fVar4;

    *(dword *)(iVar3 + 0x28) = obj->gap_A0;

    *(undefined4 *)(iVar3 + 0x2c) = *(undefined4 *)&obj->field_0xa4;

    *(undefined4 *)(iVar3 + 0x30) = *(undefined4 *)&obj->field_0xa8;

    if ((obj->field_E0 & 0x200) != 0) {

      FUN_004d8440(obj,1,0,0);

      obj->gap_E4 = 0x51;

      return;

    }

    obj->field_E0 = obj->field_E0 | 0x8004000;

    iVar3 = FUN_004d5730(100);

    if (iVar3 < 0x33) {

      obj->field_E0 = obj->field_E0 | 0x8000;

      if ((obj->field_10 == 0x7f) || (*(int *)(obj->field_8 + 0x204) == 0)) goto LAB_004d7f5f;

      fVar1 = *(float *)&obj->field_0xc4;

      uVar6 = 0x7f;

    }

    else {

      obj->field_E0 = obj->field_E0 & 0xffff7fff;

      if ((obj->field_10 == 0x7e) || (*(int *)(obj->field_8 + 0x200) == 0)) goto LAB_004d7f5f;

      fVar1 = *(float *)&obj->field_0xc4;

      uVar6 = 0x7e;

    }

    FUN_004034a0(obj,uVar6,0x21,0,fVar1 * 0.0,0x3e2aaaab);

LAB_004d7f5f:

    obj->gap_E4 = 0x51;

    return;

  case 0x66:

    if (((obj->field_E0 & 0x1000000) != 0) && (*(int *)(iVar3 + 0x20c) != 0)) {

      obj->gap_E4 = *(dword *)(iVar3 + 0x1e8);

      return;

    }

    break;

  case 0x67:

    if (*(int *)(iVar3 + 0x1e4) != 0) {

      obj->gap_E4 = 0xea;

      return;

    }

    fVar4 = (float10)FUN_004d5780(*(undefined4 *)(iVar3 + 0x1dc),*(undefined4 *)(iVar3 + 0x1e0));

    fVar5 = (float10)FUN_004d5780(*(float *)&obj->field_0xc8 - 45.0,

                                  *(float *)&obj->field_0xc8 + 45.0);

    FUN_0050ae40((float)fVar5,&local_8,&local_4);

    iVar2 = *(int *)(iVar3 + 0x1ec);

    *(float *)(iVar3 + 8) = local_8 * (float)fVar4 + *(float *)(iVar2 + 0xa0);

    *(float *)(iVar3 + 0xc) = *(float *)(iVar2 + 0xa4) - local_4 * (float)fVar4;

    *(undefined4 *)(iVar3 + 0x10) = *(undefined4 *)(iVar2 + 0xa8);

    *(undefined4 *)(iVar3 + 0x14) = *(undefined4 *)&obj->field_0xc8;

    *(undefined4 *)(iVar3 + 0x134) = 0;

    *(undefined4 *)&obj->field_0xe8 = 2;

  }

  obj->gap_E4 = 0xc;

  return;

}

/* ===== FUN_004d8150 @ 0x004D8150 ===== */
/* WARNING: Struct "OBJECT": ignoring multiple overlapping fields */



void FUN_004d8150(OBJECT *param_1,float param_2)



{

  float fVar1;

  float fVar2;

  int iVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  char cVar7;

  float10 fVar8;

  float local_10;

  float local_c;

  

  iVar3 = *(int *)&param_1->field_0x100;

  fVar8 = (float10)FUN_00518b70(param_1,0);

  fVar1 = (float)fVar8;

  FUN_004d8330(param_1);

  fVar2 = local_c * fVar1 * 4.0 + *(float *)&param_1->field_0x108;

  fVar4 = fVar1 * (float)param_1->field_1B8;

  if (local_10 < fVar2 - fVar4) {

    fVar2 = local_10;

  }

  fVar4 = ((fVar2 - fVar4 * 4.0) + *(float *)&param_1->field_0x108) * fVar1;

  fVar2 = *(float *)&param_1->field_0xa8;

  FUN_004d8330(param_1);

  fVar5 = local_c * fVar1 * 4.0 + *(float *)&param_1->field_0x108;

  if (local_10 < fVar5) {

    fVar5 = local_10;

  }

  fVar6 = fVar1 * (float)param_1->field_1B8 * 4.0;

  fVar5 = ((fVar5 - fVar6) + *(float *)&param_1->field_0x108) * fVar1;

  fVar1 = ((*(float *)&param_1->field_0x108 - fVar6) + *(float *)&param_1->field_0x108) * fVar1;

  if (param_2 <= fVar1 + fVar1 + *(float *)&param_1->field_0xa8) {

    *(undefined4 *)(iVar3 + 0x148) = 0;

    return;

  }

  if (param_2 <= fVar5 + fVar5 + *(float *)&param_1->field_0xa8) {

    cVar7 = __ftol();

    *(float *)(iVar3 + 0x148) = (float)(int)cVar7;

    return;

  }

  if (param_2 <= fVar4 + fVar4 + fVar2) {

    cVar7 = __ftol();

    *(float *)(iVar3 + 0x148) = (float)(int)cVar7;

    return;

  }

  *(undefined4 *)(iVar3 + 0x148) = 0x42000000;

  return;

}

/* ===== FUN_004d8330 @ 0x004D8330 ===== */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

/* WARNING: Struct "OBJECT": ignoring multiple overlapping fields */

/* PS2 candidate: rpman_get_thrust__FP6OBJECTfPfT2 (conf 0.898) */



void FUN_004d8330(OBJECT *obj)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float in_stack_00000008;

  float *in_stack_0000000c;

  float *in_stack_00000010;

  

  fVar1 = (float)obj->acc_TargetCenter;

  if (**(int **)&obj->field_0x100 != 0) {

    fVar1 = *(float *)(**(int **)&obj->field_0x100 + 0x140);

  }

  fVar1 = 1.0 - (*(float *)&obj->field_0xa8 - fVar1) * (1.0 / *(float *)(DAT_00632ed8 + 0xd30));

  if (1.0 < fVar1) {

    fVar1 = 1.0;

  }

  fVar2 = 1.0 - (1.0 / (float)obj->field_194) *

                (ABS(*(float *)&obj->field_0x10c) + ABS(*(float *)&obj->field_0x110));

  if (fVar2 < *(float *)(DAT_00632ed8 + 0xd38)) {

    fVar2 = *(float *)(DAT_00632ed8 + 0xd38);

  }

  fVar3 = *(float *)(DAT_00632ed8 + 0xd40);

  fVar1 = ((*(float *)(DAT_00632ed8 + 0xd3c) - (float)obj->field_1B8) * fVar1 +

          (float)obj->field_1B8) * in_stack_00000008;

  if (fVar1 < 0.0) {

    fVar1 = 0.0;

  }

  *in_stack_0000000c = fVar1;

  *in_stack_00000010 = fVar3 * fVar2;

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

/* ===== FUN_004d8440 @ 0x004D8440 ===== */
void FUN_004d8440(int param_1,int param_2,int param_3,int param_4)



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

      FUN_004d8ce0(param_1,0x8d,1,0,0,param_4);

      return;

    }

    if ((uVar1 & 0x100) == 0) {

      iVar3 = FUN_004d5730(100);

      if ((iVar3 < 100) && (*(int *)(param_1 + 0xe8) != 2)) {

        *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 0x8000;

        iVar3 = FUN_004d5730(100);

        if (0x31 < iVar3) {

          FUN_004d8ce0(param_1,0xa1,1,0,0,param_4);

          return;

        }

        FUN_004d8ce0(param_1,0xa0,1,0,0,param_4);

        return;

      }

      iVar3 = FUN_004d5730(100);

      if ((0x20 < iVar3) && (*(int *)(param_1 + 0xe8) != 2)) {

        if (0x42 < iVar3) {

          FUN_004d8ce0(param_1,0x9f,1,0,0,param_4);

          return;

        }

        FUN_004d8ce0(param_1,0x9e,1,0,0,param_4);

        return;

      }

      FUN_004d8ce0(param_1,0x4a,1,0,0,param_4);

      return;

    }

    iVar3 = FUN_004d5730(100);

    if ((iVar3 < 0x32) && (*(int *)(param_1 + 0xe8) != 2)) {

      *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 0x8000;

      iVar3 = FUN_004d5730(100);

      if (0x31 < iVar3) {

        FUN_004d8ce0(param_1,0x79,1,0,0,param_4);

        return;

      }

      FUN_004d8ce0(param_1,0x78,1,0,0,param_4);

      return;

    }

    iVar3 = FUN_004d5730(100);

    if (iVar3 < 0x19) {

      FUN_004d8ce0(param_1,0x75,1,0,0,param_4);

      return;

    }

    if (0x31 < iVar3) {

      if (0x4a < iVar3) {

        FUN_004d8ce0(param_1,0x9f,1,0,0,param_4);

        return;

      }

      FUN_004d8ce0(param_1,0x9e,1,0,0,param_4);

      return;

    }

    FUN_004d8ce0(param_1,0x76,1,0,0,param_4);

    return;

  }

  uVar1 = *(uint *)(param_1 + 0xe0);

  cVar4 = (char)(uVar1 >> 8);

  if ((uVar1 & 0x8000000) == 0) {

    if ((uVar1 & 0x200) != 0) {

      if ((uVar1 & 0x4000) == 0) {

        if ((*(int *)(param_1 + 0x10) != 0x8d) && (*(int *)(*(int *)(param_1 + 8) + 0x23c) != 0)) {

          FUN_004034a0(param_1,0x8d,0x21,0,*(float *)(param_1 + 0xc4) * 0.0,0x3e2aaaab);

        }

      }

      else if ((*(int *)(param_1 + 0x10) != 0x8c) && (*(int *)(*(int *)(param_1 + 8) + 0x238) != 0))

      {

        FUN_004034a0(param_1,0x8c,0x21,0,*(float *)(param_1 + 0xc4) * 0.0,0x3e2aaaab);

      }

      goto LAB_004d8a77;

    }

    if ((uVar1 & 0x100) == 0) {

      if ((uVar1 & 0x4000) != 0) {

        if (*(int *)(param_1 + 0xe8) == 2) {

          if ((*(int *)(param_1 + 0x10) != 0x2b) && (*(int *)(*(int *)(param_1 + 8) + 0xb4) != 0)) {

            FUN_004034a0(param_1,0x2b,0x21,0,*(float *)(param_1 + 0xc4) * 0.0,0x3e2aaaab);

          }

          goto LAB_004d8a77;

        }

        if (-1 < cVar4) {

          if ((*(int *)(param_1 + 0x10) != 0x50) && (*(int *)(*(int *)(param_1 + 8) + 0x148) != 0))

          {

            FUN_004034a0(param_1,0x50,0x21,0,*(float *)(param_1 + 0xc4) * 0.0,0x3e2aaaab);

          }

          goto LAB_004d8a77;

        }

        if (*(int *)(param_1 + 0x10) == 0x30) goto LAB_004d8a77;

        iVar2 = *(int *)(*(int *)(param_1 + 8) + 200);

        goto LAB_004d88df;

      }

      if (*(int *)(param_1 + 0xe8) == 2) {

        iVar2 = FUN_004d5730(3);

        if (iVar2 == 0) {

          if ((*(int *)(param_1 + 0x10) != 0x4a) && (*(int *)(*(int *)(param_1 + 8) + 0x130) != 0))

          {

            FUN_004034a0(param_1,0x4a,0x21,0,*(float *)(param_1 + 0xc4) * 0.0,0x3e2aaaab);

          }

        }

        else if (iVar2 == 1) {

          if ((*(int *)(param_1 + 0x10) != 0x4b) && (*(int *)(*(int *)(param_1 + 8) + 0x134) != 0))

          {

            FUN_004034a0(param_1,0x4b,0x21,0,*(float *)(param_1 + 0xc4) * 0.0,0x3e2aaaab);

          }

        }

        else if ((*(int *)(param_1 + 0x10) != 0x4f) &&

                (*(int *)(*(int *)(param_1 + 8) + 0x144) != 0)) {

          FUN_004034a0(param_1,0x4f,0x21,0,*(float *)(param_1 + 0xc4) * 0.0,0x3e2aaaab);

        }

        goto LAB_004d8a77;

      }

      if (cVar4 < '\0') {

        iVar2 = FUN_004d5730(100);

        if (iVar2 < 0x32) {

          uVar6 = 0xa0;

        }

        else {

          uVar6 = 0xa1;

        }

      }

      else {

        iVar2 = FUN_004d5730(100);

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

        iVar2 = FUN_004d5730(100);

        if (iVar2 < 0x32) {

          if ((*(int *)(param_1 + 0x10) != 0x78) && (*(int *)(*(int *)(param_1 + 8) + 0x1e8) != 0))

          {

            FUN_004034a0(param_1,0x78,0x21,0,*(float *)(param_1 + 0xc4) * 0.0,0x3e2aaaab);

          }

        }

        else if ((*(int *)(param_1 + 0x10) != 0x79) &&

                (*(int *)(*(int *)(param_1 + 8) + 0x1ec) != 0)) {

          FUN_004034a0(param_1,0x79,0x21,0,*(float *)(param_1 + 0xc4) * 0.0,0x3e2aaaab);

        }

      }

      else {

        iVar2 = FUN_004d5730(100);

        if (iVar2 < 0x19) {

          if ((*(int *)(param_1 + 0x10) != 0x75) && (*(int *)(*(int *)(param_1 + 8) + 0x1dc) != 0))

          {

            if (param_4 == 0) {

              uVar6 = 0x21;

            }

            else {

              fVar5 = (float10)FUN_004d5780(0,0x3f800000);

              *(float *)(param_1 + 0x14) = (float)fVar5;

              uVar6 = 0x81;

            }

            FUN_004034a0(param_1,0x75,uVar6,0,*(float *)(param_1 + 0xc4) * 0.0,0x3e2aaaab);

          }

        }

        else if (iVar2 < 0x32) {

          if ((*(int *)(param_1 + 0x10) != 0x76) && (*(int *)(*(int *)(param_1 + 8) + 0x1e0) != 0))

          {

            if (param_4 == 0) {

              uVar6 = 0x21;

            }

            else {

              fVar5 = (float10)FUN_004d5780(0,0x3f800000);

              *(float *)(param_1 + 0x14) = (float)fVar5;

              uVar6 = 0x81;

            }

            FUN_004034a0(param_1,0x76,uVar6,0,*(float *)(param_1 + 0xc4) * 0.0,0x3e2aaaab);

          }

        }

        else if (iVar2 < 0x4b) {

          if ((*(int *)(param_1 + 0x10) != 0x9e) && (*(int *)(*(int *)(param_1 + 8) + 0x280) != 0))

          {

            if (param_4 == 0) {

              uVar6 = 0x21;

            }

            else {

              fVar5 = (float10)FUN_004d5780(0,0x3f800000);

              *(float *)(param_1 + 0x14) = (float)fVar5;

              uVar6 = 0x81;

            }

            FUN_004034a0(param_1,0x9e,uVar6,0,*(float *)(param_1 + 0xc4) * 0.0,0x3e2aaaab);

          }

        }

        else if ((*(int *)(param_1 + 0x10) != 0x9f) &&

                (*(int *)(*(int *)(param_1 + 8) + 0x284) != 0)) {

          if (param_4 == 0) {

            uVar6 = 0x21;

          }

          else {

            fVar5 = (float10)FUN_004d5780(0,0x3f800000);

            *(float *)(param_1 + 0x14) = (float)fVar5;

            uVar6 = 0x81;

          }

          FUN_004034a0(param_1,0x9f,uVar6,0,*(float *)(param_1 + 0xc4) * 0.0,0x3e2aaaab);

        }

      }

      goto LAB_004d8a77;

    }

    if (cVar4 < '\0') {

      if ((*(int *)(param_1 + 0x10) != 0x77) && (*(int *)(*(int *)(param_1 + 8) + 0x1e4) != 0)) {

        FUN_004034a0(param_1,0x77,0x21,0,*(float *)(param_1 + 0xc4) * 0.0,0x3e2aaaab);

      }

      goto LAB_004d8a77;

    }

    if (*(int *)(param_1 + 0x10) == 0x74) goto LAB_004d8a77;

    iVar2 = *(int *)(*(int *)(param_1 + 8) + 0x1d8);

  }

  else {

    if ((uVar1 & 0x4000) == 0) {

      if ((uVar1 & 0x200) != 0) {

        FUN_004d8440(param_1,1);

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

      FUN_004d8ce0(param_1,uVar6,1,0,0,0);

      goto LAB_004d8a77;

    }

    if (cVar4 < '\0') {

      if (*(int *)(param_1 + 0x10) == 0x30) goto LAB_004d8a77;

      iVar2 = *(int *)(*(int *)(param_1 + 8) + 200);

LAB_004d88df:

      if (iVar2 != 0) {

        FUN_004034a0(param_1,0x30,0x21,0,*(float *)(param_1 + 0xc4) * 0.0,0x3e2aaaab);

      }

      goto LAB_004d8a77;

    }

    if (*(int *)(param_1 + 0x10) == 0x74) goto LAB_004d8a77;

    iVar2 = *(int *)(*(int *)(param_1 + 8) + 0x1d8);

  }

  if (iVar2 != 0) {

    FUN_004034a0(param_1,0x74,0x21,0,*(float *)(param_1 + 0xc4) * 0.0,0x3e2aaaab);

  }

LAB_004d8a77:

  if ((*(uint *)(param_1 + 0xe0) & 0x4000) == 0) {

    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 0x4000;

    return;

  }

  fVar5 = (float10)FUN_004d5780(*(undefined4 *)(DAT_00632ed8 + 0xa1c),

                                *(undefined4 *)(DAT_00632ed8 + 0xa54));

  *(float *)(iVar3 + 0x15c) = (float)fVar5;

  *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xffffbfff;

  return;

}

/* ===== FUN_004d8ce0 @ 0x004D8CE0 ===== */
void FUN_004d8ce0(int param_1,int param_2,int param_3,undefined4 param_4,float param_5,int param_6)



{

  byte bVar1;

  float10 fVar2;

  

  if ((*(int *)(param_1 + 0x10) != param_2) &&

     (*(int *)(*(int *)(param_1 + 8) + 8 + param_2 * 4) != 0)) {

    if (param_6 == 0) {

      bVar1 = param_3 != 0 | 0x20;

    }

    else {

      fVar2 = (float10)FUN_004d5780(0,0x3f800000);

      *(float *)(param_1 + 0x14) = (float)fVar2;

      bVar1 = param_3 != 0 | 0x80;

    }

    FUN_004034a0(param_1,param_2,bVar1,param_4,param_5 * *(float *)(param_1 + 0xc4),0x3e2aaaab);

  }

  return;

}

