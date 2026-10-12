/* Giants 1.449 — module _unmapped_004d
 * 39 functions (0 named) — decompiled, names from PS2 symbols
 * Original source: C:\Giants\source\_unmapped_004d.c(pp) (assert-string evidence)
 */

/* ===== FUN_004d1790 @ 0x004D1790 ===== */
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
/* PS2 candidate: ripper_medium_move__FP6OBJECT (conf 0.428) */



void FUN_004d1bd0(int param_1)



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

  undefined1 local_34 [4];

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

    fVar9 = (float10)FUN_0050a5e0(&local_5c,param_1 + 0xa0);

    local_78 = (float)fVar9;

    fVar9 = (float10)FUN_0050a610(&local_5c,param_1 + 0xa0);

    local_6c = (float)fVar9;

    local_54 = *(float *)((int)fVar4 + 0x1e8) * *(float *)((int)fVar4 + 0xc4) + local_54;

    fVar7 = local_74;

  }

  switch(*(undefined4 *)(param_1 + 0xe4)) {

  case 0x1f:

    FUN_0040d6b0(local_50);

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

      local_6c = (float)FUN_004d5730(100);

      if (((float)(int)local_6c < *(float *)(DAT_00632ed8 + 0x3e4)) ||

         (FUN_004555e0(iVar6,local_44,&local_6c), local_3c < 0.64278)) {

        if (pfVar1[0xe] == 0.0) {

          local_1c = param_1;

          local_20 = 0xffffffff;

          local_24 = 8;

          fVar7 = (float)fx_get_free_effect__Fv(s_fx_ripper_dirt_0055b4d8,0x24,local_34);

          pfVar1[0xe] = fVar7;

        }

        puVar8 = *(undefined4 **)(param_1 + 0x100);

        *(undefined4 *)(param_1 + 0xe4) = 0x22;

        if (puVar8[3] != 0) {

          fVar9 = (float10)FUN_0050a400(puVar8[3] + 0xa0,iVar6);

          fVar9 = (float10)FUN_004d5780((float)(fVar9 - (float10)50.0),

                                        (float)((float10)50.0 + fVar9));

          puVar8[1] = (float)fVar9;

          FUN_00451560(puVar8 + 1);

          fVar9 = (float10)FUN_004d5780(*(undefined4 *)(DAT_00632ed8 + 200),

                                        *(undefined4 *)(DAT_00632ed8 + 0xcc));

          puVar8[2] = (float)fVar9;

          *puVar8 = *(undefined4 *)(DAT_00632ed8 + 0xd0);

        }

        *(undefined4 *)(param_1 + 0x184) = 0x3f800000;

        FUN_004954e0(0x4e8,param_1);

        FUN_00495750(0x4ea,param_1);

      }

      else {

        *(undefined4 *)(param_1 + 0xe4) = 0x2c;

        FUN_00495750(0x4ea,param_1);

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

       (((iVar5 = FUN_004a6160(fVar4), iVar5 != 0 &&

         ((*(uint *)((int)fVar4 + 0xe0) & 0x2000000) != 0)) && (*(float *)(iVar6 + 0x54) < 4.0))))

    goto LAB_004d2124;

    iVar6 = FUN_004a6180(fVar4);

    if (iVar6 == 0) {

LAB_004d2151:

      local_68 = *(float *)((int)fVar4 + 0xa0);

      local_64 = *(float *)((int)fVar4 + 0xa4);

      local_60 = *(undefined4 *)((int)fVar4 + 0xa8);

      FUN_0050ae40(pfVar1[1],&local_80,&local_7c);

      local_68 = local_80 * pfVar1[2] + local_68;

      local_64 = local_64 - local_7c * pfVar1[2];

      fVar9 = (float10)FUN_0050a520(param_1 + 0xa0,&local_68);

      local_6c = (float)fVar9;

      if ((float10)0.0 <= fVar9) {

        *(undefined1 *)(param_1 + 0x208) = 0;

        fVar9 = (float10)FUN_0050a400(param_1 + 0xa0,&local_68);

        local_70 = (float)fVar9;

        fVar9 = (float10)FUN_0050a7c0(local_70,*(undefined4 *)(param_1 + 200));

        local_74 = (float)fVar9;

        if (ABS(fVar9) == (float10)0.0) {

          fVar7 = 0.0;

        }

        else {

          uVar2 = FUN_004a7cb0(local_74 * 0.05,0x3e800000);

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

          uVar2 = FUN_004a7cb0(local_6c * 0.1,0x3e4ccccd);

          *(undefined1 *)(param_1 + 0x20a) = uVar2;

        }

      }

      if (pfVar1[2] * 1.1 * pfVar1[2] * 1.1 <= local_78) break;

      local_6c = (float)FUN_004d5730(100);

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

       (((iVar5 = FUN_004a6160(fVar4), iVar5 != 0 &&

         ((*(uint *)((int)fVar4 + 0xe0) & 0x2000000) != 0)) && (*(float *)(iVar6 + 0x54) < 4.0)))) {

LAB_004d2364:

      if (pfVar1[0xe] != 0.0) {

        FUN_00448920(pfVar1[0xe]);

      }

      pfVar1[0xe] = 0.0;

      FUN_004954e0(0x4ea,param_1);

      *(undefined4 *)(param_1 + 0xe4) = 0x1f;

      pfVar1[3] = 0.0;

    }

    else {

      iVar6 = FUN_004a6180(fVar4);

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

      FUN_0050ae40(pfVar1[1],&local_80,&local_7c);

      iVar6 = param_1 + 0xa0;

      local_68 = local_80 * pfVar1[2] + local_68;

      local_64 = local_64 - local_7c * pfVar1[2];

      fVar9 = (float10)FUN_0050a520(iVar6,&local_68);

      local_6c = (float)fVar9;

      if ((float10)0.0 <= fVar9) {

        *(undefined1 *)(param_1 + 0x208) = 0;

        fVar9 = (float10)FUN_0050a400(iVar6,&local_68);

        local_70 = (float)fVar9;

        fVar9 = (float10)FUN_0050a7c0(local_70,*(undefined4 *)(param_1 + 200));

        local_74 = (float)fVar9;

        if (ABS(fVar9) == (float10)0.0) {

          fVar7 = 0.0;

        }

        else {

          uVar2 = FUN_004a7cb0(local_74 * 0.05,0x3e800000);

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

          uVar2 = FUN_004a7cb0(local_6c * 0.1,0x3e4ccccd);

          *(undefined1 *)(param_1 + 0x20a) = uVar2;

        }

      }

      if ((local_78 < pfVar1[2] * 1.1 * pfVar1[2] * 1.1) &&

         (FUN_004555e0(iVar6,local_44,&local_6c), 0.64278 <= local_3c)) {

        *(undefined4 *)(param_1 + 0xe4) = 0x2c;

        FUN_00495750(0x4e8,param_1);

      }

    }

    break;

  case 0x23:

    iVar6 = *(int *)(param_1 + 0x100);

    if ((((fVar4 == 0.0) || (*(int *)((int)fVar4 + 4) == 0)) ||

        (((*(uint *)((int)fVar4 + 0xd8) & 0x4000c000) != 0 ||

         (*(float *)((int)fVar4 + 0x1c0) <= *(float *)((int)fVar4 + 0x278))))) ||

       (((iVar5 = FUN_004a6160(fVar4), iVar5 != 0 &&

         ((*(uint *)((int)fVar4 + 0xe0) & 0x2000000) != 0)) && (*(float *)(iVar6 + 0x54) < 4.0))))

    goto LAB_004d2124;

    iVar6 = FUN_004a6180(fVar4);

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

    FUN_0050ae40(pfVar1[1],&local_80,&local_7c);

    iVar6 = param_1 + 0xa0;

    local_68 = local_80 * pfVar1[2] + local_68;

    local_64 = local_64 - local_7c * pfVar1[2];

    fVar9 = (float10)FUN_0050a520(iVar6,&local_68);

    local_6c = (float)fVar9;

    if ((float10)0.0 <= fVar9) {

      *(undefined1 *)(param_1 + 0x208) = 0;

      fVar9 = (float10)FUN_0050a400(iVar6,&local_68);

      local_70 = (float)fVar9;

      fVar9 = (float10)FUN_0050a7c0(local_70,*(undefined4 *)(param_1 + 200));

      local_74 = (float)fVar9;

      if (ABS(fVar9) == (float10)0.0) {

        fVar7 = 0.0;

      }

      else {

        uVar2 = FUN_004a7cb0(local_74 * 0.05,0x3e800000);

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

        uVar2 = FUN_004a7cb0(local_6c * 0.1,0x3e4ccccd);

        *(undefined1 *)(param_1 + 0x20a) = uVar2;

      }

    }

    if (*(float *)(DAT_00632ed8 + 0xd4) * *(float *)(DAT_00632ed8 + 0xd4) <= local_78) {

      fVar9 = (float10)FUN_0050a5e0(&local_68,iVar6);

      if (((float10)5.0 <= fVar9) && (0.0 <= *pfVar1)) break;

      local_6c = (float)FUN_004d5730(100);

      goto LAB_004d286e;

    }

    local_6c = (float)FUN_004d5730(100);

    if ((float)(int)local_6c < *(float *)(DAT_00632ed8 + 0xdc)) goto LAB_004d27a6;

    puVar8 = *(undefined4 **)(param_1 + 0x100);

    if (puVar8[3] == 0) break;

    fVar9 = (float10)FUN_0050a400(puVar8[3] + 0xa0,iVar6);

    fVar10 = (float10)20.0 + fVar9;

    fVar9 = fVar9 - (float10)20.0;

    goto LAB_004d27e4;

  case 0x24:

    iVar6 = *(int *)(param_1 + 0x100);

    if ((((fVar4 == 0.0) || (*(int *)((int)fVar4 + 4) == 0)) ||

        (((*(uint *)((int)fVar4 + 0xd8) & 0x4000c000) != 0 ||

         (*(float *)((int)fVar4 + 0x1c0) <= *(float *)((int)fVar4 + 0x278))))) ||

       (((iVar5 = FUN_004a6160(fVar4), iVar5 != 0 &&

         ((*(uint *)((int)fVar4 + 0xe0) & 0x2000000) != 0)) && (*(float *)(iVar6 + 0x54) < 4.0)))) {

LAB_004d2a47:

      if (pfVar1[0xe] != 0.0) {

        FUN_00448920(pfVar1[0xe]);

      }

      pfVar1[0xe] = 0.0;

      *(undefined4 *)(param_1 + 0xe4) = 0x2b;

      pfVar1[3] = 0.0;

    }

    else {

      iVar6 = FUN_004a6180(fVar4);

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

      FUN_0050ae40(pfVar1[1],&local_80,&local_7c);

      iVar6 = param_1 + 0xa0;

      local_68 = local_80 * pfVar1[2] + local_68;

      local_64 = local_64 - local_7c * pfVar1[2];

      fVar9 = (float10)FUN_0050a520(iVar6,&local_68);

      local_6c = (float)fVar9;

      if ((float10)0.0 <= fVar9) {

        *(undefined1 *)(param_1 + 0x208) = 0;

        fVar9 = (float10)FUN_0050a400(iVar6,&local_68);

        local_70 = (float)fVar9;

        fVar9 = (float10)FUN_0050a7c0(local_70,*(undefined4 *)(param_1 + 200));

        local_74 = (float)fVar9;

        if (ABS(fVar9) == (float10)0.0) {

          fVar7 = 0.0;

        }

        else {

          uVar2 = FUN_004a7cb0(local_74 * 0.05,0x3e800000);

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

          uVar2 = FUN_004a7cb0(local_6c * 0.1,0x3e4ccccd);

          *(undefined1 *)(param_1 + 0x20a) = uVar2;

        }

      }

      fVar9 = (float10)FUN_0050a5e0(&local_68,iVar6);

      if (((fVar9 < (float10)5.0) || (*pfVar1 < 0.0)) &&

         (FUN_004555e0(iVar6,local_44,&local_6c), 0.64278 <= local_3c)) {

        *(undefined4 *)(param_1 + 0xe4) = 0x2c;

        FUN_00495750(0x4e8,param_1);

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

       (((iVar5 = FUN_004a6160(fVar4), iVar5 == 0 ||

         ((*(uint *)((int)fVar4 + 0xe0) & 0x2000000) == 0)) || (4.0 <= *(float *)(iVar6 + 0x54)))))

    {

      iVar6 = FUN_004a6180(fVar4);

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

        fVar9 = (float10)FUN_0050a400(param_1 + 0xa0,(int)fVar4 + 0xa0);

        local_78 = (float)fVar9;

      }

      fVar9 = (float10)FUN_0050a7c0(local_78,*(undefined4 *)(param_1 + 200));

      if (ABS(fVar9) != (float10)0.0) {

        uVar2 = FUN_004a7cb0((float)(fVar9 * (float10)0.05),0x3e800000);

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

        (((iVar5 = FUN_004a6160(fVar4), iVar5 == 0 ||

          ((*(uint *)((int)fVar4 + 0xe0) & 0x2000000) == 0)) || (4.0 <= *(float *)(iVar6 + 0x54)))))

       )) {

      iVar6 = FUN_004a6180(fVar4);

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

        fVar9 = (float10)FUN_0050a400(param_1 + 0xa0,(int)fVar4 + 0xa0);

        local_78 = (float)fVar9;

      }

      fVar9 = (float10)FUN_0050a7c0(local_78,*(undefined4 *)(param_1 + 200));

      if (ABS(fVar9) != (float10)0.0) {

        uVar2 = FUN_004a7cb0((float)(fVar9 * (float10)0.05),0x3e800000);

        *(undefined1 *)(param_1 + 0x208) = uVar2;

        *(float *)(param_1 + 0x158) = local_78;

        *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) | 0x1000000;

      }

      if (local_74 == 0.0) {

        if ((*(float *)(param_1 + 0x18) < 0.43333334) && (0.43333334 <= *(float *)(param_1 + 0x14)))

        {

          FUN_004d4350(param_1,&local_5c,*(undefined4 *)(DAT_00632ed8 + 0xf0));

        }

        break;

      }

      local_6c = (float)FUN_004d5730(100);

      if ((float)(int)local_6c < *(float *)(DAT_00632ed8 + 0xe8)) {

        *(undefined4 *)(param_1 + 0xe4) = 0x25;

        break;

      }

      if ((float)(int)local_6c < *(float *)(DAT_00632ed8 + 0xec) + *(float *)(DAT_00632ed8 + 0xe8))

      {

        puVar8 = *(undefined4 **)(param_1 + 0x100);

        if (puVar8[3] != 0) {

          fVar9 = (float10)FUN_0050a400(puVar8[3] + 0xa0,param_1 + 0xa0);

          fVar9 = (float10)FUN_004d5780((float)(fVar9 - (float10)80.0),

                                        (float)((float10)80.0 + fVar9));

          puVar8[1] = (float)fVar9;

          FUN_00451560(puVar8 + 1);

          fVar9 = (float10)FUN_004d5780(*(undefined4 *)(DAT_00632ed8 + 200),

                                        *(undefined4 *)(DAT_00632ed8 + 0xcc));

          puVar8[2] = (float)fVar9;

          *puVar8 = *(undefined4 *)(DAT_00632ed8 + 0xd0);

        }

        local_6c = (float)FUN_004d5730(100);

        if (*(float *)(DAT_00632ed8 + 0x3e4) <= (float)(int)local_6c) {

          *(undefined4 *)(param_1 + 0xe4) = 0x23;

        }

        else {

          FUN_004954e0(0x4e8,param_1);

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

        (((iVar5 = FUN_004a6160(fVar4), iVar5 == 0 ||

          ((*(uint *)((int)fVar4 + 0xe0) & 0x2000000) == 0)) || (4.0 <= *(float *)(iVar6 + 0x54)))))

       )) {

      iVar6 = FUN_004a6180(fVar4);

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

        fVar9 = (float10)FUN_0050a400(param_1 + 0xa0,puVar8);

        local_74 = (float)fVar9;

      }

      fVar9 = (float10)FUN_0050a7c0(local_74,*(undefined4 *)(param_1 + 200));

      local_70 = (float)fVar9;

      if (ABS(fVar9) == (float10)0.0) {

        fVar7 = 0.0;

      }

      else {

        uVar2 = FUN_004a7cb0(local_70 * 0.05,0x3e800000);

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

        FUN_004954e0(0x4e6,param_1);

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

       (((iVar5 = FUN_004a6160(fVar4), iVar5 == 0 ||

         ((*(uint *)((int)fVar4 + 0xe0) & 0x2000000) == 0)) || (4.0 <= *(float *)(iVar6 + 0x54)))))

    {

      iVar6 = FUN_004a6180(fVar4);

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

        fVar9 = (float10)FUN_0050a400(param_1 + 0xa0,(int)fVar4 + 0xa0);

        local_70 = (float)fVar9;

      }

      fVar9 = (float10)FUN_0050a7c0(local_70,*(undefined4 *)(param_1 + 200));

      if (ABS(fVar9) != (float10)0.0) {

        uVar2 = FUN_004a7cb0((float)(fVar9 * (float10)0.05),0x3e800000);

        *(undefined1 *)(param_1 + 0x208) = uVar2;

        *(float *)(param_1 + 0x158) = local_70;

        *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) | 0x1000000;

      }

      if (local_74 != 0.0) {

        puVar8 = *(undefined4 **)(param_1 + 0x100);

        if (puVar8[3] != 0) {

          fVar9 = (float10)FUN_0050a400(puVar8[3] + 0xa0,param_1 + 0xa0);

          fVar9 = (float10)FUN_004d5780((float)(fVar9 - (float10)20.0),

                                        (float)((float10)20.0 + fVar9));

          puVar8[1] = (float)fVar9;

          FUN_00451560(puVar8 + 1);

          fVar9 = (float10)FUN_004d5780(*(undefined4 *)(DAT_00632ed8 + 200),

                                        *(undefined4 *)(DAT_00632ed8 + 0xcc));

          puVar8[2] = (float)fVar9;

          *puVar8 = *(undefined4 *)(DAT_00632ed8 + 0xd0);

        }

        *(undefined4 *)(param_1 + 0xe4) = 0x23;

        if (local_6c < *(float *)(DAT_00632ed8 + 0xd8) * *(float *)(DAT_00632ed8 + 0xd8)) {

          FUN_00456f80(2,*(undefined4 *)(DAT_00632ed8 + 1000),fVar4,param_1,0,0);

        }

      }

      break;

    }

LAB_004d2124:

    FUN_004954e0(0x4f5,param_1);

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

      FUN_004041f0(param_1 + 0xa0);

      FUN_004954e0(0x4ea,param_1);

      *(undefined4 *)(param_1 + 0xe4) = 0x1f;

      *(uint *)(param_1 + 0x1c8) = *(uint *)(param_1 + 0x1c8) | 0x840;

    }

    break;

  case 0x2c:

    local_30 = *(undefined4 *)(param_1 + 0xa0);

    local_2c = *(undefined4 *)(param_1 + 0xa4);

    local_28 = *(undefined4 *)(param_1 + 0xa8);

    fx_get_free_effect__Fv(s_fx_ripper_popup_0056137c,8,local_34);

    if (pfVar1[0xe] != 0.0) {

      FUN_00448920(pfVar1[0xe]);

    }

    pfVar1[0xe] = 0.0;

    FUN_004954e0(0x4f3,param_1);

    *(undefined4 *)(param_1 + 0xe4) = 0x20;

    *(undefined4 *)(param_1 + 0x184) = 0;

    *(uint *)(param_1 + 0x1c8) = *(uint *)(param_1 + 0x1c8) & 0xfffff7ff;

    FUN_004041f0((undefined4 *)(param_1 + 0xa0));

    FUN_00499280(param_1);

    FUN_00499220(param_1);

    if (0.0 < *(float *)(param_1 + 0xa8)) {

      iVar6 = FUN_00496c00(0xdb,0x11);

      FUN_004979b0(iVar6,param_1);

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

      fVar4 = (float)fx_get_free_effect__Fv(s_fx_ripper_dirt_0055b4d8,0x24,local_34);

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

      FUN_004041f0(param_1 + 0xa0);

      puVar8 = *(undefined4 **)(param_1 + 0x100);

      if (puVar8[3] != 0) {

        fVar9 = (float10)FUN_0050a400(puVar8[3] + 0xa0,param_1 + 0xa0);

        fVar9 = (float10)FUN_004d5780((float)(fVar9 - (float10)80.0),(float)((float10)80.0 + fVar9))

        ;

        puVar8[1] = (float)fVar9;

        FUN_00451560(puVar8 + 1);

        fVar9 = (float10)FUN_004d5780(*(undefined4 *)(DAT_00632ed8 + 200),

                                      *(undefined4 *)(DAT_00632ed8 + 0xcc));

        puVar8[2] = (float)fVar9;

        *puVar8 = *(undefined4 *)(DAT_00632ed8 + 0xd0);

      }

      *(undefined4 *)(param_1 + 0xe4) = 0x24;

      *(uint *)(param_1 + 0x1c8) = *(uint *)(param_1 + 0x1c8) | 0x840;

      *(undefined4 *)(param_1 + 0x184) = 0x3f800000;

      FUN_004954e0(0x4e8,param_1);

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

      FUN_004954e0(0x4f5,param_1);

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

      FUN_00448920(pfVar1[0xe]);

    }

    pfVar1[0xe] = 0.0;

    *(uint *)(param_1 + 0x1c8) = *(uint *)(param_1 + 0x1c8) & 0xfffff3bf;

    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xfffffffd;

    if (fVar7 != 0.0) {

      *(undefined4 *)(param_1 + 0xe4) = 0x5c;

      fVar9 = (float10)FUN_004d5780(*(undefined4 *)(DAT_00632ed8 + 0x134),

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

          (iVar6 = FUN_00512c80(param_1,param_1,0,local_70,2), iVar6 == 0)))) break;

    }

    FUN_00497510(param_1);

  }

switchD_004d1ccc_caseD_28:

  if ((*(int *)(param_1 + 0x10) == 2) &&

     (((0.6333333 <= *(float *)(param_1 + 0x14) && (*(float *)(param_1 + 0x18) < 0.6333333)) ||

      ((1.9666667 <= *(float *)(param_1 + 0x14) && (*(float *)(param_1 + 0x18) < 1.9666667)))))) {

    FUN_004954e0(0x4ed,param_1);

  }

  return;

switchD_004d1ccc_caseD_20:

  *(undefined1 *)(param_1 + 0x208) = 0;

  fVar9 = (float10)FUN_0050a400(param_1 + 0xa0,&local_5c);

  local_70 = (float)fVar9;

  fVar9 = (float10)FUN_0050a7c0(local_70,*(undefined4 *)(param_1 + 200));

  if (ABS(fVar9) != (float10)0.0) {

    uVar2 = FUN_004a7cb0((float)(fVar9 * (float10)0.05),0x3e800000);

    *(undefined1 *)(param_1 + 0x208) = uVar2;

    *(float *)(param_1 + 0x158) = local_70;

    *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) | 0x1000000;

  }

  *(uint *)(param_1 + 0x1c8) = *(uint *)(param_1 + 0x1c8) & 0xffffffbf;

  if (local_74 != 0.0) {

    if (pfVar1[0xe] != 0.0) {

      FUN_00448920(pfVar1[0xe]);

    }

    pfVar1[0xe] = 0.0;

    puVar8 = *(undefined4 **)(param_1 + 0x100);

    *(undefined4 *)(param_1 + 0xe4) = 0x21;

    if (puVar8[3] != 0) {

      fVar9 = (float10)FUN_0050a400(puVar8[3] + 0xa0,param_1 + 0xa0);

      fVar10 = (float10)50.0 + fVar9;

      fVar9 = fVar9 - (float10)50.0;

LAB_004d27e4:

      fVar9 = (float10)FUN_004d5780((float)fVar9,(float)fVar10);

      puVar8[1] = (float)fVar9;

      FUN_00451560(puVar8 + 1);

      fVar9 = (float10)FUN_004d5780(*(undefined4 *)(DAT_00632ed8 + 200),

                                    *(undefined4 *)(DAT_00632ed8 + 0xcc));

      puVar8[2] = (float)fVar9;

      *puVar8 = *(undefined4 *)(DAT_00632ed8 + 0xd0);

    }

  }

  goto switchD_004d1ccc_caseD_28;

}

/* ===== FUN_004d3720 @ 0x004D3720 ===== */
undefined4 FUN_004d3720(int param_1)



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

  FUN_004a76e0(*(int *)(iVar2 + 0x24),*(undefined4 *)(iVar2 + 0x28),pfVar1);

  FUN_00414690(pfVar1,local_1c);

  if (*(float *)(param_1 + 0xa8) < local_c) {

    *(float *)(param_1 + 0xa8) = local_c;

  }

  uVar4 = *puVar3;

  if ((*(float *)(param_1 + 0xb8) != *pfVar1) ||

     (*(float *)(param_1 + 0xbc) != *(float *)(param_1 + 0xa4))) {

    fVar5 = (float10)FUN_0050a400(param_1 + 0xb8,pfVar1);

    fVar5 = (float10)FUN_00518b70(param_1,0,0x461c4000,(float)fVar5,param_1 + 200);

    FUN_004515b0((float)(fVar5 * (float10)30.0));

  }

  *(undefined4 *)(iVar2 + 0x34) = puVar3[10];

  *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) | 0x40;

  FUN_004967b0(param_1);

  fVar5 = (float10)FUN_00518b70(param_1,0);

  FUN_00403e60(param_1,(float)fVar5);

  FUN_004a7440(param_1);

  *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) | 0x20;

  *(undefined4 *)(param_1 + 0x10c) = puVar3[9];

  return uVar4;

}

/* ===== FUN_004d3ed0 @ 0x004D3ED0 ===== */
/* PS2 candidate: ripper_animselect (conf 0.422) */



void FUN_004d3ed0(int param_1)



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

          FUN_004d4350(param_1,*(int *)(iVar5 + 0xc) + 0xa0,*(undefined4 *)(DAT_00632ed8 + 0x11c));

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

      iVar5 = FUN_004d5730(100);

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

    iVar5 = FUN_004d5730(100);

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

      FUN_004d4350(param_1,*(int *)(iVar5 + 0xc) + 0xa0,uVar1);

    }

    if ((*(byte *)(param_1 + 0x30) & 2) == 0) goto LAB_004d3f6e;

    fVar6 = (float10)FUN_004d5780(*(undefined4 *)(DAT_00632ed8 + 0xd0c),

                                  *(undefined4 *)(DAT_00632ed8 + 0xd10));

    *(float *)(param_1 + 0xf0) = (float)fVar6;

    iVar4 = 1;

    *(undefined4 *)(param_1 + 0xe4) = 0x55;

    break;

  case 0x5a:

  case 0x6c:

    if ((iVar2 == 0x31) || (iVar2 == 0x34)) goto LAB_004d41e1;

    iVar5 = FUN_004d5730(100);

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

    iVar5 = FUN_004d5730(100);

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

      FUN_004034a0(param_1,2,0x21,1,*(float *)(param_1 + 0x1b4) * *(float *)(param_1 + 0xc4),

                   0x3e2aaaab);

      return;

    }

    if (bVar3) {

      FUN_004035d0();

      return;

    }

    FUN_004036f0(param_1,iVar4);

  }

  return;

}

/* ===== FUN_004d4350 @ 0x004D4350 ===== */
/* PS2 candidate: make_spit__FP6OBJECTP3P3Df (conf 0.416) */



void FUN_004d4350(int param_1,int param_2,float param_3)



{

  float fVar1;

  float fVar2;

  int iVar3;

  int iVar4;

  float10 fVar5;

  undefined4 uVar6;

  undefined1 local_34 [20];

  undefined4 local_20;

  int local_1c;

  

  if (*(int *)(param_1 + 4) == 0xe6) {

    uVar6 = 0xe8;

  }

  else {

    uVar6 = 0x5a;

  }

  iVar3 = FUN_00497d70(uVar6);

  if (iVar3 != 0) {

    iVar4 = FUN_00496c00(0x374,0);

    if (iVar4 != 0) {

      FUN_00497770(iVar4,iVar3);

      FUN_00497a50(iVar4,iVar3);

      local_20 = 0xffffffff;

      local_1c = iVar4;

      if (*(int *)(param_1 + 4) == 0xe6) {

        *(undefined4 *)(iVar4 + 0xe8) = 1;

        fx_get_free_effect__Fv(s_fx_ripper_large_proj_00561404,4,local_34);

        iVar3 = FUN_004d5730(100);

        if (iVar3 < 0x32) {

          uVar6 = 0x4cb;

        }

        else {

          uVar6 = 0x4cc;

        }

        FUN_00495840(uVar6,param_1 + 0xa0);

        *(undefined4 *)(iVar4 + 0xf4) = 0x636;

        *(undefined4 *)(iVar4 + 0xf8) = 0x4d8;

        *(undefined4 *)(iVar4 + 0xfc) = 0x4d9;

      }

      else {

        *(undefined4 *)(iVar4 + 0xe8) = 0;

        fx_get_free_effect__Fv(s_fx_ripper_medium_proj_005613ec,4,local_34);

        iVar3 = FUN_004d5730(100);

        if (iVar3 < 0x32) {

          uVar6 = 0x4e2;

        }

        else {

          uVar6 = 0x4e3;

        }

        FUN_00495840(uVar6,param_1 + 0xa0);

        *(undefined4 *)(iVar4 + 0xf4) = 0x637;

        *(undefined4 *)(iVar4 + 0xf8) = 0x4ef;

      }

      FUN_004a76e0(param_1,0,iVar4 + 0xa0);

      FUN_00499280(iVar4);

      *(undefined4 *)(iVar4 + 200) = *(undefined4 *)(param_1 + 200);

      *(undefined4 *)(iVar4 + 0xcc) = 0;

      *(undefined4 *)(iVar4 + 0xd0) = 0;

      uVar6 = *(undefined4 *)(param_1 + 0x18c);

      *(undefined4 *)(iVar4 + 0x11c) = *(undefined4 *)(iVar4 + 0x194);

      *(undefined4 *)(iVar4 + 0x10c) = *(undefined4 *)(iVar4 + 0x194);

      *(undefined4 *)(iVar4 + 0x18c) = uVar6;

      fVar5 = (float10)FUN_0050a520(param_2,iVar4 + 0xa0);

      fVar1 = (float)(fVar5 / (float10)*(float *)(iVar4 + 0x10c));

      fVar2 = (fVar1 * *(float *)(iVar4 + 0x1b8) * fVar1 * 0.5 +

              (*(float *)(param_2 + 8) - *(float *)(iVar4 + 0xa8))) / fVar1;

      fVar5 = (float10)FUN_004d5780((1.0 - param_3 * 0.01) * fVar2,(param_3 * 0.01 + 1.0) * fVar2);

      *(float *)(iVar4 + 0x118) = (float)fVar5;

      *(float *)(iVar4 + 0x108) = (float)fVar5;

      **(float **)(iVar4 + 0x100) = fVar1 + 1.0;

      (*(undefined4 **)(iVar4 + 0x100))[1] = **(undefined4 **)(iVar4 + 0x100);

      *(int *)(iVar4 + 0x274) = param_1;

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
/* PS2 candidate: enemy_check_player_grab__FP6OBJECTif (conf 0.489) */



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

/* ===== FUN_004d49e0 @ 0x004D49E0 ===== */
bool FUN_004d49e0(int param_1)



{

  return *(int *)(param_1 + 0xe4) == 0x98;

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
/* PS2 candidate: ripnest_move (conf 0.369) */



void FUN_004d4ae0(int param_1)



{

  int *piVar1;

  undefined4 *puVar2;

  uint uVar3;

  int iVar4;

  bool bVar5;

  float10 fVar6;

  

  piVar1 = *(int **)(param_1 + 0x100);

  if (*(int *)(param_1 + 0xe4) == 0) {

    FUN_004954e0(0x4ff,param_1);

    *(undefined4 *)(param_1 + 0xe4) = 1;

  }

  iVar4 = *(int *)(param_1 + 0x10);

  uVar3 = *(uint *)(param_1 + 0x30) & 2;

  switch(*(undefined4 *)(param_1 + 0xe4)) {

  case 1:

    *(undefined4 *)(param_1 + 0xe4) = 2;

    iVar4 = FUN_00496c00(0xdb,0x11);

    FUN_004979b0(iVar4,param_1);

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

      iVar4 = FUN_00496c00(0xe5,0x11);

      puVar2 = *(undefined4 **)(iVar4 + 0x100);

      fVar6 = (float10)FUN_004d5780(*(undefined4 *)(DAT_00632ed8 + 0xc0),

                                    *(undefined4 *)(DAT_00632ed8 + 0xc4));

      *(float *)(iVar4 + 0xc4) = (float)fVar6;

      FUN_004993c0(iVar4,(undefined4 *)(param_1 + 0xa0));

      fVar6 = (float10)FUN_004d5760(0x43b40000);

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

/* ===== FUN_004d4db0 @ 0x004D4DB0 ===== */
void FUN_004d4db0(int param_1)



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

      FUN_00497510(param_1);

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

/* ===== FUN_004d5710 @ 0x004D5710 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_004d5710(void)



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
/* PS2 candidate: rndintrange (conf 0.534) */



int FUN_004d5740(int param_1,int param_2)



{

  int iVar1;

  

  iVar1 = _rand();

  return (iVar1 * ((param_2 - param_1) + 1) >> 0xf) + param_1;

}

/* ===== FUN_004d5760 @ 0x004D5760 ===== */
/* PS2 candidate: rndfloat (conf 0.383) */



float10 FUN_004d5760(float param_1)



{

  int iVar1;

  

  iVar1 = _rand();

  return (float10)iVar1 * (float10)param_1 * (float10)3.0517578e-05;

}

/* ===== FUN_004d5780 @ 0x004D5780 ===== */
/* PS2 candidate: rndfloatrange (conf 0.455) */



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

    iVar2 = FUN_0052e4a0(param_1);

    if (iVar2 != 0) {

      FUN_00530bd0(param_2,0,0,0,5,0);

    }

    *(undefined4 *)(param_2 + 0x18c) = 0;

    FUN_004954e0(0x62a,param_2);

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

  FUN_004035d0(param_1,0x91);

  if (*(int *)(param_2 + 0x1e0) != 0x5a) {

    FUN_00499e70(param_2,0x5a);

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

  FUN_00495650(0x62b,param_1);

  FUN_00495650(0x626,param_1);

  FUN_004ba920(param_1);

  return;

}

/* ===== FUN_004d59d0 @ 0x004D59D0 ===== */
/* PS2 candidate: rpboat_ghost_logic__FP6OBJECT (conf 0.398) */



void FUN_004d59d0(int param_1)



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

  FUN_004a4360(param_1);

  *(uint *)(param_1 + 0x1c8) = *(uint *)(param_1 + 0x1c8) & 0xfffffbff;

  fVar3 = (float10)FUN_00518b70(param_1,0);

  FUN_00403e60(param_1,(float)fVar3);

  *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) | 0x40;

  FUN_004d5b50(param_1);

  fVar3 = (float10)FUN_00518b70(param_1,0,0x461c4000,*(undefined4 *)(iVar2 + 0x48),

                                (float *)(iVar2 + 0x40));

  FUN_004515b0((float)(fVar3 * (float10)*(float *)(DAT_00632ed8 + 0xe04)));

  fVar3 = (float10)FUN_00518b70(param_1,0,0x461c4000,*(undefined4 *)(iVar2 + 0x4c),

                                (undefined4 *)(iVar2 + 0x44));

  FUN_004515b0((float)(fVar3 * (float10)*(float *)(DAT_00632ed8 + 0xe00)));

  FUN_0053e460(param_1 + 0x294,-*(float *)(iVar2 + 0x40),*(undefined4 *)(iVar2 + 0x44),

               *(undefined4 *)(param_1 + 200));

  return;

}

/* ===== FUN_004d5b50 @ 0x004D5B50 ===== */
/* PS2 candidate: rpboat_tilt__FP6OBJECT (conf 0.454) */



void FUN_004d5b50(int param_1)



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

  undefined4 local_7c;

  undefined1 local_78 [4];

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

  iVar5 = FUN_0052e480(iVar5);

  if (((iVar5 != 0) && (*(int *)(param_1 + 0x274) != 0)) &&

     (DAT_00632a88 == *(int *)(param_1 + 0x274))) {

    if ((char)((uint)*(undefined4 *)(DAT_00632a88 + 0x20c) >> 8) < '\0') {

      FUN_00403890(local_44,&local_94,param_1,*(undefined4 *)(param_1 + 0x10),4,0);

      FUN_0040d7e0(local_44);

      FUN_0040d810(local_94);

    }

    else {

      FUN_0040d790();

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

        fx_get_free_effect__Fv(s_fx_ground_dusthit_00561450,8,local_78);

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

    local_7c = *(undefined4 *)(param_1 + 0x2b8);

    FUN_0050a810(&local_90,&local_8c,&local_88);

    FUN_0050a810(&local_84,&local_80,&local_7c);

    fVar6 = (float10)FUN_00516290(&local_90,&local_84);

    *(float *)(iVar3 + 0x4c) =

         (float)(fVar6 * (float10)1.4285715 * (float10)*(float *)(DAT_00632ed8 + 0xd90));

  }

  pfVar1 = (float *)(iVar3 + 0x40);

  if ((*(uint *)(param_1 + 0xe0) & 8) == 0) {

    fVar6 = (float10)FUN_00518b70(param_1,0,0x461c4000,*(undefined4 *)(iVar3 + 0x48),pfVar1);

    FUN_004515b0((float)(fVar6 * (float10)*(float *)(DAT_00632ed8 + 0xe04)));

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

    FUN_004515b0((float)fVar6);

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

  FUN_004515b0((float)(fVar6 * (float10)*(float *)(DAT_00632ed8 + 0xe00)));

  FUN_0053e460(param_1 + 0x294,-*pfVar1,*(undefined4 *)(iVar3 + 0x44),*(undefined4 *)(param_1 + 200)

              );

  FUN_004041f0(param_1,iVar3 + 0x60);

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

      iVar3 = FUN_0052e4a0(iVar3);

      if (iVar3 != 0) {

        local_54 = *param_2;

        local_48 = *(undefined4 *)(iVar1 + 0x188);

        local_50 = param_2[1];

        local_4c = param_2[2];

        FUN_00530bd0(param_1,3,1,0,6,&local_54);

      }

    }

    FUN_00495650(0x6cd,*(undefined4 *)(param_1 + 0x274));

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

      iVar3 = FUN_0052e4a0(iVar3);

      if (iVar3 != 0) {

        uStack_58 = *(undefined4 *)(iVar1 + 0x188);

        uStack_54 = *(undefined4 *)(param_2 + 0x188);

        FUN_00530bd0(param_1,0,2,0,3,&uStack_58);

      }

    }

    FUN_00495650(0x6cd,*(undefined4 *)(param_1 + 0x274));

  }

  return;

}

/* ===== FUN_004d77e0 @ 0x004D77E0 ===== */
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

      FUN_00530bd0(iVar6,0,1,0,0x23,&param_1);

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

    iVar6 = FUN_0052e4a0(iVar6);

    if (iVar6 != 0) {

      FUN_00530bd0(iVar2,0,0,0,5,0);

    }

    *(undefined4 *)(iVar2 + 0x18c) = 0;

    FUN_004954e0(0x62a,iVar2);

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

/* ===== FUN_004d7c40 @ 0x004D7C40 ===== */
bool FUN_004d7c40(int param_1)



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

        FUN_004e7ae0(param_1,param_2);

      }

      if ((*(int *)(param_1 + 0x10) != 0xaa) && (*(int *)(*(int *)(param_1 + 8) + 0x2b0) != 0)) {

        FUN_004034a0(param_1,0xaa,0x20,0,*(float *)(param_1 + 0xc4) * 0.0,0x3e2aaaab);

      }

      *(undefined4 *)(param_1 + 0xe4) = 0x12d;

    }

  }

  return;

}

/* ===== FUN_004d7e10 @ 0x004D7E10 ===== */
void FUN_004d7e10(int param_1)



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

    fVar4 = (float10)FUN_004d5780(0x40800000,0x40e00000);

    *(float *)(iVar3 + 0xd0) = (float)fVar4;

    *(undefined4 *)(iVar3 + 0x28) = *(undefined4 *)(param_1 + 0xa0);

    *(undefined4 *)(iVar3 + 0x2c) = *(undefined4 *)(param_1 + 0xa4);

    *(undefined4 *)(iVar3 + 0x30) = *(undefined4 *)(param_1 + 0xa8);

    if ((*(uint *)(param_1 + 0xe0) & 0x200) != 0) {

      FUN_004d8440(param_1,1,0,0);

      *(undefined4 *)(param_1 + 0xe4) = 0x51;

      return;

    }

    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 0x8004000;

    iVar3 = FUN_004d5730(100);

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

    FUN_004034a0(param_1,uVar6,0x21,0,fVar1 * 0.0,0x3e2aaaab);

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

    fVar4 = (float10)FUN_004d5780(*(undefined4 *)(iVar3 + 0x1dc),*(undefined4 *)(iVar3 + 0x1e0));

    fVar5 = (float10)FUN_004d5780(*(float *)(param_1 + 200) - 45.0,*(float *)(param_1 + 200) + 45.0)

    ;

    FUN_0050ae40((float)fVar5,&local_8,&local_4);

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

/* ===== FUN_004d8150 @ 0x004D8150 ===== */
void FUN_004d8150(int param_1,float param_2)



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

  FUN_004d8330(param_1,0x3f800000,&local_c,&local_10);

  fVar3 = local_c * fVar1 * 4.0 + *(float *)(param_1 + 0x108);

  local_8 = fVar1 * *(float *)(param_1 + 0x1b8);

  if (local_10 < fVar3 - local_8) {

    fVar3 = local_10;

  }

  fVar3 = ((fVar3 - local_8 * 4.0) + *(float *)(param_1 + 0x108)) * fVar1;

  local_4 = fVar3 + fVar3 + *(float *)(param_1 + 0xa8);

  FUN_004d8330(param_1,0x3f000000,&local_c,&local_10);

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

/* ===== FUN_004d8330 @ 0x004D8330 ===== */
void FUN_004d8330(int param_1,float param_2,float *param_3,float *param_4)



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

/* ===== FUN_004d8420 @ 0x004D8420 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_004d8420(void)



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

