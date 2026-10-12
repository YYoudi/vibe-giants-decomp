/* Giants 1.449 — module _unmapped_0046
 * 53 functions (0 named) — decompiled, names from PS2 symbols
 * Original source: C:\Giants\source\_unmapped_0046.c(pp) (assert-string evidence)
 */

/* ===== FUN_00465030 @ 0x00465030 ===== */
void FUN_00465030(undefined4 param_1,undefined4 param_2)



{

  undefined4 uVar1;

  int iVar2;

  

  uVar1 = param_2;

  FUN_00495550(param_1,param_2);

  iVar2 = FUN_0052e4a0(uVar1);

  if (iVar2 != 0) {

    param_2 = param_1;

    FUN_00530bd0(uVar1,0,1,0,0x11,&param_2);

  }

  return;

}

/* ===== FUN_00465070 @ 0x00465070 ===== */
void FUN_00465070(int param_1)



{

  int iVar1;

  undefined4 local_14;

  undefined4 local_10;

  undefined4 local_c;

  undefined4 local_8;

  undefined4 local_4;

  

  iVar1 = FUN_0052e530(param_1);

  if (iVar1 != 0) {

    local_14 = *(undefined4 *)(param_1 + 0xa0);

    local_10 = *(undefined4 *)(param_1 + 0xa4);

    local_c = *(undefined4 *)(param_1 + 0xa8);

    local_8 = *(undefined4 *)(param_1 + 200);

    local_4 = DAT_006328e8;

    FUN_00530f10(param_1,5,0,0,0x10,&local_14);

  }

  return;

}

/* ===== FUN_004650d0 @ 0x004650D0 ===== */
int FUN_004650d0(undefined4 param_1,float *param_2,float *param_3,float param_4,float param_5,

                float *param_6)



{

  float fVar1;

  float fVar2;

  float fVar3;

  int iVar4;

  undefined4 *puVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  int iVar10;

  int local_28;

  

  fVar1 = *param_2;

  fVar2 = param_2[1];

  fVar3 = param_2[2];

  local_28 = 0;

  for (puVar5 = DAT_00632d68; puVar5 != (undefined4 *)0x0; puVar5 = (undefined4 *)*puVar5) {

    iVar4 = puVar5[3];

    iVar10 = FUN_0045ae90(param_1,iVar4,7);

    if ((iVar10 != 0) && ((*(uint *)(iVar4 + 0xd8) & 0x4000c000) == 0)) {

      fVar6 = (*(float *)(iVar4 + 0x288) + *(float *)(iVar4 + 0x27c)) * 0.5 - fVar1;

      fVar7 = (*(float *)(iVar4 + 0x28c) + *(float *)(iVar4 + 0x280)) * 0.5 - fVar2;

      fVar8 = (*(float *)(iVar4 + 0x290) + *(float *)(iVar4 + 0x284)) * 0.5 - fVar3;

      fVar9 = fVar6 * *param_3 + fVar7 * param_3[1] + fVar8 * param_3[2];

      if ((0.0 <= fVar9) &&

         ((fVar9 < param_4 &&

          (fVar6 = (fVar6 * fVar6 + fVar7 * fVar7 + fVar8 * fVar8) - fVar9 * fVar9, fVar6 < param_5)

          ))) {

        param_5 = fVar6;

        local_28 = iVar4;

      }

    }

  }

  if (param_6 != (float *)0x0) {

    *param_6 = param_5;

  }

  return local_28;

}

/* ===== FUN_00465230 @ 0x00465230 ===== */
int FUN_00465230(float param_1,undefined4 param_2,float *param_3,int *param_4,uint param_5)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  float fVar6;

  int *piVar7;

  int iVar8;

  float10 fVar9;

  int local_18;

  undefined1 local_c [12];

  

  fVar6 = param_1;

  iVar2 = *param_4;

  iVar8 = -1;

  local_18 = 0;

  piVar7 = param_4;

  while (iVar2 != 0xfe) {

    if ((piVar7[4] & param_5) != 0) {

      iVar2 = *(int *)(*(int *)(piVar7[6] + 0xc) + 0x1c);

      iVar3 = *(int *)(*(int *)(piVar7[6] + 0xc) + 0x18);

      iVar4 = piVar7[2];

      iVar5 = piVar7[1];

      param_4 = (int *)0x3f800000;

      do {

        fVar9 = (float10)FUN_00465350(piVar7[6],

                                      (float)piVar7[1] * (float)param_4 +

                                      (1.0 - (float)param_4) * (float)piVar7[2],local_c,fVar6,

                                      param_2,(float)piVar7[1]);

        if ((iVar8 < 0) || (fVar9 < (float10)param_1)) {

          param_1 = (float)fVar9;

          iVar8 = local_18;

        }

        param_4 = (int *)((float)param_4 - (float)(iVar2 * iVar3) / ((float)(iVar4 - iVar5) * 240.0)

                         );

      } while (0.0 <= (float)param_4);

    }

    piVar1 = piVar7 + 7;

    piVar7 = piVar7 + 7;

    local_18 = local_18 + 1;

    iVar2 = *piVar1;

  }

  if (param_3 != (float *)0x0) {

    *param_3 = param_1;

  }

  return iVar8;

}

/* ===== FUN_00465350 @ 0x00465350 ===== */
float10 FUN_00465350(int param_1,undefined4 param_2,float *param_3,int param_4,int param_5,

                    float param_6)



{

  float fVar1;

  float fVar2;

  undefined4 uVar3;

  int iVar4;

  float10 fVar5;

  float fStack_18;

  float fStack_14;

  undefined4 local_c;

  undefined4 local_8;

  undefined4 local_4;

  

  if (param_1 == 0) {

    return (float10)0.0;

  }

  uVar3 = __ftol(*(undefined4 *)(param_4 + 0xc));

  iVar4 = FUN_0053cb50(param_1,uVar3);

  local_c = *(undefined4 *)(iVar4 + 0x10);

  local_8 = *(undefined4 *)(iVar4 + 0x20);

  local_4 = *(undefined4 *)(iVar4 + 0x30);

  (*(code *)PTR_FUN_00580c20)(param_3,&local_c,1,param_4 + 0x294);

  fStack_18 = *(float *)(param_5 + 0x128);

  fStack_14 = *(float *)(param_5 + 300);

  fVar1 = *(float *)(param_5 + 0x130);

  if (*(int *)(param_5 + 0x104) == 0) {

    fStack_18 = *(float *)(param_5 + 0x2a0) * *(float *)(param_5 + 0x108) +

                (*(float *)(param_5 + 0x298) * *(float *)(param_5 + 0x110) -

                *(float *)(param_5 + 0x29c) * *(float *)(param_5 + 0x10c)) + fStack_18;

    fVar2 = *(float *)(param_5 + 0x2b0) * *(float *)(param_5 + 0x108);

    fStack_14 = (*(float *)(param_5 + 0x2a8) * *(float *)(param_5 + 0x110) -

                *(float *)(param_5 + 0x2ac) * *(float *)(param_5 + 0x10c)) + fVar2 + fStack_14;

    fVar1 = (*(float *)(param_5 + 0x2b8) * *(float *)(param_5 + 0x110) -

            *(float *)(param_5 + 700) * *(float *)(param_5 + 0x10c)) + fVar2 + fVar1;

  }

  fVar2 = (param_6 - (float)*(int *)(*(int *)(param_1 + 0xc) + 0x10)) * 0.00020833334;

  *param_3 = (*(float *)(param_4 + 0x128) - fStack_18) * fVar2 + *param_3;

  param_3[1] = (*(float *)(param_4 + 300) - fStack_14) * fVar2 + param_3[1];

  param_3[2] = (*(float *)(param_4 + 0x130) - fVar1) * fVar2 + param_3[2];

  fVar5 = (float10)FUN_004a9f80(param_3,param_5);

  return fVar5;

}

/* ===== FUN_004654c0 @ 0x004654C0 ===== */
undefined4

FUN_004654c0(undefined4 param_1,int param_2,int param_3,int param_4,float param_5,float *param_6,

            undefined4 *param_7,float param_8)



{

  int iVar1;

  int iVar2;

  float fVar3;

  int iVar4;

  float10 fVar5;

  float local_14;

  undefined4 local_c;

  undefined4 local_8;

  undefined4 local_4;

  

  iVar4 = (int)param_5;

  if (param_2 != 0) {

    iVar1 = *(int *)((int)param_5 + 4);

    iVar2 = *(int *)((int)param_5 + 8);

    if ((byte)(((param_3 < iVar1) << 1 | iVar2 < param_3) &

              ((param_4 < iVar1) << 1 | iVar2 < param_4)) == 0) {

      fVar3 = 0.0;

      local_14 = 1.0;

      if (param_3 < iVar1) {

        fVar3 = (float)(iVar1 - param_3) / (float)(param_4 - param_3);

      }

      if (iVar2 < param_4) {

        local_14 = (float)(iVar2 - param_3) / (float)(param_4 - param_3);

      }

      iVar1 = *(int *)(*(int *)((int)param_5 + 0x18) + 0xc);

      iVar2 = *(int *)(iVar1 + 0x1c);

      iVar1 = *(int *)(iVar1 + 0x18);

      if (fVar3 < local_14 != (fVar3 == local_14)) {

        param_5 = fVar3;

        do {

          fVar5 = (float10)FUN_00465350(*(undefined4 *)(iVar4 + 0x18),

                                        (float)param_4 * param_5 + (1.0 - param_5) * (float)param_3,

                                        &local_c,param_1,param_2,0);

          if (*param_6 < 0.0) {

            *param_6 = (float)fVar5;

            *param_7 = local_c;

            param_7[1] = local_8;

            param_7[2] = local_4;

          }

          if (fVar5 <= (float10)*param_6 + (float10)0.2) {

            *param_6 = (float)fVar5;

            param_7[3] = *param_7;

            param_7[4] = param_7[1];

            param_7[5] = param_7[2];

            *param_7 = local_c;

            param_7[1] = local_8;

            param_7[2] = local_4;

          }

          else if (*param_6 < param_8) {

            return 1;

          }

          param_5 = param_5 + (float)(iVar2 * iVar1) / ((float)(param_4 - param_3) * 240.0);

        } while (param_5 < local_14 != (param_5 == local_14));

      }

      if ((*(int *)(iVar4 + 8) <= param_4) && (*param_6 < param_8)) {

        return 1;

      }

    }

  }

  return 0;

}

/* ===== FUN_004656b0 @ 0x004656B0 ===== */
void FUN_004656b0(undefined4 param_1,int param_2,float param_3,int param_4)



{

  int iVar1;

  float local_8;

  undefined4 local_4;

  

  if (param_4 != 0) {

    iVar1 = FUN_0052e4a0(param_1);

    if (iVar1 != 0) {

      local_4 = *(undefined4 *)(param_2 + 0x188);

      local_8 = param_3;

      FUN_00530bd0(param_1,1,1,0,8,&local_8);

    }

  }

  if (param_3 != 0.0) {

    *(float *)(param_2 + 0xc4) = *(float *)(param_2 + 0xc4) / param_3;

  }

  *(undefined4 *)(param_2 + 0x210) = 0;

  if (*(int *)(param_2 + 0x1e0) == 0x59) {

    if (*(int *)(param_2 + 0x218) < 2) {

      FUN_00425850(param_2);

    }

  }

  else if (*(int *)(param_2 + 0x1e0) == 0x12) {

    FUN_004f4150();

  }

  else {

    iVar1 = FUN_004a6180(param_2);

    if (iVar1 != 0) {

      *(undefined4 *)(param_2 + 0xc4) = *(undefined4 *)(*(int *)(param_2 + 0x100) + 0xfac);

    }

  }

  *(uint *)(param_2 + 0xd8) = *(uint *)(param_2 + 0xd8) & 0xfff7ffff | 0x10000000;

  return;

}

/* ===== FUN_00465790 @ 0x00465790 ===== */
void FUN_00465790(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,float param_5

                 ,int param_6,float param_7)



{

  int iVar1;

  float10 fVar2;

  

  if (param_7 != 0.0) {

    *(float *)(param_2 + 0xc4) = *(float *)(param_2 + 0xc4) / param_7;

  }

  *(undefined4 *)(param_2 + 0x210) = 0;

  if (*(int *)(param_2 + 0x1e0) == 0x59) {

    if (*(int *)(param_2 + 0x218) < 2) {

      FUN_00425850(param_2);

    }

  }

  else if (*(int *)(param_2 + 0x1e0) == 0x12) {

    FUN_004f4150();

  }

  else {

    iVar1 = FUN_004a6180(param_2);

    if (iVar1 != 0) {

      *(undefined4 *)(param_2 + 0xc4) = *(undefined4 *)(*(int *)(param_2 + 0x100) + 0xfac);

    }

  }

  *(uint *)(param_2 + 0xd8) = *(uint *)(param_2 + 0xd8) & 0xfff7ffff | 0x10000000;

  *(int *)(param_2 + 0x210) = param_6;

  *(undefined4 *)(param_2 + 0x218) = 0xffffffff;

  FUN_0050a610(param_6 + 0xa0,param_3);

  fVar2 = (float10)FUN_00543e70();

  FUN_0046e9d0(param_6,param_3,param_4,(float)(fVar2 / (float10)param_5),0x3f400000);

  return;

}

/* ===== FUN_00465880 @ 0x00465880 ===== */
/* PS2 candidate: reaper_update_xhair_status__FP6OBJECT (conf 0.376) */



void FUN_00465880(int param_1,int param_2,int param_3,undefined4 param_4,float param_5,float param_6

                 )



{

  float fVar1;

  float *pfVar2;

  int iVar3;

  int iVar4;

  float10 fVar5;

  float local_44;

  float local_40;

  float local_3c;

  float local_38;

  float local_34;

  float local_30;

  float local_2c;

  float local_28;

  float local_24;

  float local_20;

  float local_1c;

  float local_18;

  float local_14;

  float local_10;

  undefined4 local_c;

  undefined4 local_8;

  undefined4 local_4;

  

  iVar4 = param_3;

  if (param_3 == 0) {

    iVar4 = FUN_00455890(&local_38,0x459c4000,&param_3);

    if (iVar4 == 0) {

      pfVar2 = (float *)FUN_00515db0();

      local_44 = *pfVar2;

      local_40 = pfVar2[1];

      local_3c = pfVar2[2];

      pfVar2 = (float *)FUN_00515dc0(2);

      local_2c = *pfVar2;

      local_28 = pfVar2[1];

      local_24 = pfVar2[2];

      if (*(int *)(param_2 + 4) == 0x2a5) {

        fVar1 = 1000.0;

      }

      else {

        if ((**(byte **)(param_1 + 0x100) & 1) == 0) {

          fVar1 = 1.0;

        }

        else {

          fVar1 = *(float *)(*(byte **)(param_1 + 0x100) + 0x1d0);

        }

        fVar1 = fVar1 * 1000.0;

        param_5 = param_5 * 0.4;

      }

      local_38 = local_2c * fVar1 + local_44;

      local_34 = local_28 * fVar1 + local_40;

      local_30 = local_24 * fVar1 + local_3c;

    }

    iVar4 = FUN_0046e830(param_1,param_2);

    if (iVar4 != 0) {

      iVar3 = FUN_0052e4a0(param_1);

      if (iVar3 != 0) {

        local_1c = local_34;

        local_10 = param_6;

        local_20 = local_38;

        local_18 = local_30;

        local_c = *(undefined4 *)(iVar4 + 0x188);

        local_14 = param_5;

        local_8 = *(undefined4 *)(param_2 + 0x188);

        local_4 = 0;

        FUN_00530bd0(param_1,5,3,0,6,&local_20);

      }

      FUN_0046e120(iVar4,&LAB_0045afe0);

      if (param_6 != 0.0) {

        *(float *)(param_2 + 0xc4) = *(float *)(param_2 + 0xc4) / param_6;

      }

      *(undefined4 *)(param_2 + 0x210) = 0;

      if (*(int *)(param_2 + 0x1e0) == 0x59) {

        if (*(int *)(param_2 + 0x218) < 2) {

          FUN_00425850(param_2);

        }

      }

      else if (*(int *)(param_2 + 0x1e0) == 0x12) {

        FUN_004f4150();

      }

      else {

        iVar3 = FUN_004a6180(param_2);

        if (iVar3 != 0) {

          *(undefined4 *)(param_2 + 0xc4) = *(undefined4 *)(*(int *)(param_2 + 0x100) + 0xfac);

        }

      }

      *(uint *)(param_2 + 0xd8) = *(uint *)(param_2 + 0xd8) & 0xfff7ffff | 0x10000000;

      *(int *)(param_2 + 0x210) = iVar4;

      *(undefined4 *)(param_2 + 0x218) = 0xffffffff;

      FUN_0050a610(iVar4 + 0xa0,&local_38);

      fVar5 = (float10)FUN_00543e70();

      param_5 = (float)(fVar5 / (float10)param_5);

      FUN_0046e9d0(iVar4,&local_38,0,param_5,0x3f400000);

    }

    return;

  }

  pfVar2 = (float *)FUN_00515db0();

  local_2c = *pfVar2;

  local_28 = pfVar2[1];

  local_24 = pfVar2[2];

  pfVar2 = (float *)FUN_00515dc0(2);

  local_44 = *pfVar2 * 50000.0 + local_2c;

  local_40 = pfVar2[1] * 50000.0 + local_28;

  local_3c = pfVar2[2] * 50000.0 + local_24;

  iVar3 = FUN_0049a550(&local_38,&local_2c,&local_44,(float *)(iVar4 + 0x27c));

  if (iVar3 != 0) {

    if ((*(uint *)(iVar4 + 0x1c8) & 0x1000000) != 0) goto LAB_00465986;

    iVar3 = FUN_0049bf60(&local_2c,&local_44,iVar4,&local_38,0);

    if (iVar3 != 0) goto LAB_00465986;

  }

  local_38 = (*(float *)(iVar4 + 0x288) + *(float *)(iVar4 + 0x27c)) * 0.5;

  local_34 = (*(float *)(iVar4 + 0x28c) + *(float *)(iVar4 + 0x280)) * 0.5;

  local_30 = (*(float *)(iVar4 + 0x290) + *(float *)(iVar4 + 0x284)) * 0.5;

LAB_00465986:

  FUN_0045b2b0(param_1,param_2,&local_38,iVar4,param_5,param_6);

  return;

}

/* ===== FUN_00465bf0 @ 0x00465BF0 ===== */
/* PS2 candidate: reaper_collect_food (conf 0.513) */



void FUN_00465bf0(float param_1,float param_2,undefined4 param_3,float param_4)



{

  undefined4 uVar1;

  float fVar2;

  int iVar3;

  float fVar4;

  undefined4 uVar5;

  undefined4 local_18;

  float local_14;

  undefined4 local_10;

  undefined1 local_c [12];

  

  fVar2 = param_2;

  if (param_2 == 0.0) {

LAB_00465d3b:

    iVar3 = FUN_004d5730(100);

    if (iVar3 < 0x32) {

      uVar5 = 0x411;

    }

    else {

      uVar5 = 0x412;

    }

  }

  else {

    if (*(int *)((int)param_2 + 0x1e0) == 0x12) {

      iVar3 = FUN_004d5730(100);

      fVar4 = param_1;

      if (iVar3 < 0x32) {

        uVar5 = 0x474;

      }

      else {

        uVar5 = 0x475;

      }

      FUN_00495550(uVar5,param_1);

      iVar3 = *(int *)((int)fVar4 + 0x2dc);

      local_18 = *(undefined4 *)(iVar3 + 0x120);

      local_14 = *(float *)(iVar3 + 0x130);

      local_10 = *(undefined4 *)(iVar3 + 0x140);

      (*(code *)PTR_FUN_00580c20)(local_c,&local_18,1,(int)fVar4 + 0x294);

      param_1 = *(float *)((int)fVar4 + 200) + 90.0;

      uVar5 = *(undefined4 *)(DAT_00632ed8 + 0x2b4);

      uVar1 = *(undefined4 *)(DAT_00632ed8 + 0x2b8);

      param_2 = *(float *)((int)fVar4 + 200) - 90.0;

      *(undefined4 *)(DAT_00632ed8 + 0x2b4) = 0x3e99999a;

      *(undefined4 *)(DAT_00632ed8 + 0x2b8) = 0x3f4ccccd;

      FUN_0040b350(local_c,0x1e,0x32,param_2,param_1,0x41200000,0x42340000,0,0x41700000);

      *(undefined4 *)(DAT_00632ed8 + 0x2b4) = uVar5;

      *(undefined4 *)(DAT_00632ed8 + 0x2b8) = uVar1;

      goto LAB_00465d63;

    }

    if (*(int *)((int)param_2 + 0x1e0) != 0x15) goto LAB_00465d3b;

    iVar3 = FUN_004d5730(100);

    if (iVar3 < 0x32) {

      uVar5 = 0x481;

    }

    else {

      uVar5 = 0x482;

    }

  }

  fVar4 = param_1;

  FUN_00495550(uVar5,param_1);

LAB_00465d63:

  iVar3 = FUN_0052e4a0(fVar4);

  if (iVar3 == 0) {

    *(undefined4 *)((int)fVar4 + 0x278) = param_3;

  }

  else {

    if (fVar2 == 0.0) {

      return;

    }

    local_10 = *(undefined4 *)((int)fVar2 + 0x188);

    local_18 = param_3;

    local_14 = param_4;

    FUN_00530bd0(fVar4,2,1,0,3,&local_18);

  }

  if (fVar2 != 0.0) {

    if (param_4 != 0.0) {

      *(float *)((int)fVar2 + 0xc4) = *(float *)((int)fVar2 + 0xc4) / param_4;

    }

    *(undefined4 *)((int)fVar2 + 0x210) = 0;

    if (*(int *)((int)fVar2 + 0x1e0) == 0x59) {

      if (*(int *)((int)fVar2 + 0x218) < 2) {

        FUN_00425850(fVar2);

      }

    }

    else if (*(int *)((int)fVar2 + 0x1e0) == 0x12) {

      FUN_004f4150();

    }

    else {

      iVar3 = FUN_004a6180(fVar2);

      if (iVar3 != 0) {

        *(undefined4 *)((int)fVar2 + 0xc4) = *(undefined4 *)(*(int *)((int)fVar2 + 0x100) + 0xfac);

      }

    }

    *(uint *)((int)fVar2 + 0xd8) = *(uint *)((int)fVar2 + 0xd8) & 0xfff7ffff | 0x10000000;

    if (*(int *)((int)fVar2 + 4) != 0xb) {

      FUN_0050ae40(*(undefined4 *)((int)fVar4 + 200),&param_1,&param_4);

      if (*(int *)((int)fVar2 + 0x104) == 0) {

        *(float *)((int)fVar2 + 0x128) = param_1 * 100.0;

        *(undefined4 *)((int)fVar2 + 0x108) = 0x41f00000;

        *(float *)((int)fVar2 + 300) = param_4 * -100.0;

      }

      else {

        *(float *)((int)fVar2 + 0x128) = param_1 * 100.0 + *(float *)((int)fVar2 + 0x128);

        *(float *)((int)fVar2 + 300) = *(float *)((int)fVar2 + 300) - param_4 * 100.0;

        *(float *)((int)fVar2 + 0x130) = *(float *)((int)fVar2 + 0x130) + 30.0;

      }

    }

    iVar3 = FUN_0052e480(fVar4);

    if (iVar3 != 0) {

      FUN_00456f80(7,0x461c4000,fVar2,fVar4,0,0);

    }

  }

  return;

}

/* ===== FUN_00465f10 @ 0x00465F10 ===== */
void FUN_00465f10(int param_1,undefined4 param_2,int param_3,int *param_4)



{

  int iVar1;

  int *piVar2;

  undefined1 local_44 [68];

  

  iVar1 = param_1;

  if (param_4 == (int *)0x0) {

    if ((*(byte *)(param_1 + 0x20c) & 1) != 0) {

      param_1 = 0;

      FUN_00403890(local_44,&param_1,iVar1,1,7,0);

      FUN_0040d7e0(local_44);

      FUN_0040d810(param_1);

      return;

    }

  }

  else if ((*(byte *)(param_1 + 0x20c) & 1) != 0) {

    iVar1 = *param_4;

    for (piVar2 = param_4; (-1 < iVar1 && ((param_3 < piVar2[1] || (piVar2[2] <= param_3))));

        piVar2 = piVar2 + 3) {

      iVar1 = piVar2[3];

    }

    FUN_0040d7b0(param_1,*piVar2);

    return;

  }

  FUN_0040d790();

  return;

}

/* ===== FUN_00466980 @ 0x00466980 ===== */
/* PS2 candidate: kabuto_get_kbos (conf 0.309) */



undefined4 FUN_00466980(int param_1,int param_2)



{

  if (param_2 == 0) {

    return *(undefined4 *)(*(int *)(param_1 + 0x100) + 800);

  }

  return *(undefined4 *)(*(int *)(param_1 + 0x100) + 0x324);

}

/* ===== FUN_004669a0 @ 0x004669A0 ===== */
/* PS2 candidate: kabuto_create_kbos (conf 0.438) */



void FUN_004669a0(float param_1,int param_2)



{

  int iVar1;

  int iVar2;

  int iVar3;

  float10 fVar4;

  float local_18;

  float local_14 [3];

  float local_8;

  float local_4;

  

  iVar2 = (int)param_1;

  iVar1 = *(int *)((int)param_1 + 0x100);

  if (param_2 == 0) {

    param_1 = *(float *)((int)param_1 + 200) + 40.0;

    if (360.0 < param_1) {

      param_1 = param_1 - 360.0;

    }

  }

  else {

    param_1 = *(float *)((int)param_1 + 200) - 40.0;

    if (param_1 < 0.0) {

      param_1 = param_1 + 360.0;

    }

  }

  FUN_0050ae40(param_1,&local_18,local_14);

  local_4 = *(float *)(iVar2 + 0xa8);

  local_14[0] = -local_14[0];

  local_14[1] = 0.0;

  local_14[2] = local_18 * 50.0 + *(float *)(iVar2 + 0xa0);

  local_8 = local_14[0] * 50.0 + *(float *)(iVar2 + 0xa4);

  fVar4 = (float10)FUN_00455600(local_14 + 2);

  local_4 = (float)fVar4;

  if (param_2 == 0) {

    iVar3 = FUN_0046b5e0(local_14 + 2);

    *(int *)(iVar1 + 800) = iVar3;

  }

  else {

    iVar3 = FUN_0046b5e0(local_14 + 2);

    *(int *)(iVar1 + 0x324) = iVar3;

  }

  *(undefined4 *)(iVar3 + 0x18c) = *(undefined4 *)(iVar2 + 0x18c);

  return;

}

/* ===== FUN_00467260 @ 0x00467260 ===== */
undefined4 FUN_00467260(void)



{

  return 0;

}

/* ===== FUN_00467510 @ 0x00467510 ===== */
void FUN_00467510(int param_1)



{

  undefined4 *puVar1;

  uint uVar2;

  undefined4 *puVar3;

  undefined4 *puVar4;

  int iVar5;

  int iVar6;

  undefined4 *puVar7;

  undefined4 *puVar8;

  undefined4 *puVar9;

  float10 fVar10;

  undefined4 local_178;

  undefined4 local_174;

  undefined4 local_170;

  undefined *puStack_16c;

  undefined4 uStack_168;

  uint uStack_164;

  int iStack_160;

  undefined1 local_154 [68];

  undefined1 local_110 [68];

  undefined1 auStack_cc [68];

  undefined1 auStack_88 [68];

  undefined1 auStack_44 [4];

  undefined1 auStack_40 [64];

  

  if (*(int *)(param_1 + 0x50) != 0) {

    local_178 = 0;

    local_174 = 0;

    local_170 = 0x3f800000;

    FUN_0053dca0(local_154,param_1 + 0x44);

    fVar10 = (float10)FUN_004d5760(0x40c90fdb);

    FUN_0053dd90(local_110,(float)fVar10);

    (*(code *)PTR_FUN_00580c18)(local_154,local_154,local_110);

    FUN_0053dde0(auStack_88,param_1 + 0x2c,param_1 + 0x38,&local_178);

    (*(code *)PTR_FUN_00580c18)(auStack_cc,auStack_88,local_154);

    FUN_0053d970(auStack_44,auStack_cc);

    (**(code **)(DAT_00656420 + 0x18))(DAT_00656420,auStack_40);

    (**(code **)(DAT_00656430 + 0x10))(DAT_00656430,1);

    (**(code **)(DAT_00656430 + 0xc))(DAT_00656430,*(undefined4 *)(param_1 + 0x58));

    uStack_164 = *(uint *)(param_1 + 0x54) | 0x21104;

    puStack_16c = &DAT_00632a60;

    uStack_168 = 0;

    uVar2 = __ftol();

    iStack_160 = (uVar2 | 0xffffff00) << 0x10;

    (**(code **)(DAT_00656430 + 0x14))(DAT_00656430,&puStack_16c);

    puVar1 = *(undefined4 **)(param_1 + 0x24);

    puVar3 = (undefined4 *)

             (**(code **)(DAT_00656450 + 0x10))(DAT_00656450,*(undefined4 *)(param_1 + 0x18));

    iVar6 = *(int *)(param_1 + 0x18);

    while (iVar6 != 0) {

      puVar4 = puVar3 + 8;

      puVar7 = puVar1 + 8;

      iVar6 = iVar6 + -1;

      puVar8 = puVar1;

      puVar9 = puVar3;

      for (iVar5 = 8; puVar1 = puVar7, puVar3 = puVar4, iVar5 != 0; iVar5 = iVar5 + -1) {

        *puVar9 = *puVar8;

        puVar8 = puVar8 + 1;

        puVar9 = puVar9 + 1;

      }

    }

    (**(code **)(DAT_00656450 + 0x18))(DAT_00656450,0);

    (**(code **)(DAT_00656450 + 0x20))

              (DAT_00656450,*(undefined4 *)(param_1 + 0x1c),*(undefined4 *)(param_1 + 0x20));

  }

  return;

}

/* ===== FUN_004676a0 @ 0x004676A0 ===== */
void FUN_004676a0(void)



{

  undefined4 *puVar1;

  undefined4 *puVar2;

  

  if (DAT_0059da1c != 0) {

    puVar1 = (undefined4 *)(((undefined4 **)DAT_00632a80 == &DAT_00632a80) - 1 & (uint)DAT_00632a80)

    ;

    puVar2 = (undefined4 *)*DAT_00632a80;

    if (puVar1 != (undefined4 *)0x0) {

      while( true ) {

        FUN_00467510(puVar1);

        if ((undefined4 **)puVar2 == &DAT_00632a80) break;

        puVar1 = puVar2;

        puVar2 = (undefined4 *)*puVar2;

      }

    }

  }

  return;

}

/* ===== FUN_00469860 @ 0x00469860 ===== */
/* PS2 candidate: kabutoai_change_anim__FP6OBJECTii4SDKYfi (conf 0.461) */



void FUN_00469860(int param_1,int param_2,int param_3,undefined4 param_4,float param_5,int param_6)



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

    FUN_00495750(0x6dc,param_1);

    FUN_00495750(0x6dd,param_1);

  }

  return;

}

/* ===== FUN_004698f0 @ 0x004698F0 ===== */
float10 FUN_004698f0(int param_1,undefined4 param_2)



{

  int iVar1;

  float10 fVar2;

  

  iVar1 = *(int *)(param_1 + 0x100);

  FUN_0050a610(param_1 + 0xa0,param_2);

  fVar2 = (float10)FUN_00543e70();

  FUN_004a4480(param_1 + 0x128,param_1 + 0xa0,param_2,iVar1 + 0x40,(float)(fVar2 * (float10)0.1));

  return (float10)(float)(fVar2 * (float10)0.1);

}

/* ===== FUN_00469950 @ 0x00469950 ===== */
float10 FUN_00469950(int param_1,undefined4 param_2)



{

  undefined1 uVar1;

  float10 fVar2;

  

  fVar2 = (float10)FUN_0050a7c0(param_2,*(undefined4 *)(param_1 + 200));

  if (ABS(fVar2) == (float10)0.0) {

    return (float10)0.0;

  }

  *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) | 0x1000000;

  *(undefined4 *)(param_1 + 0x158) = param_2;

  uVar1 = __ftol();

  *(undefined1 *)(param_1 + 0x208) = uVar1;

  return (float10)(float)ABS(fVar2);

}

/* ===== FUN_004699e0 @ 0x004699E0 ===== */
/* PS2 candidate: loglauncher_process (conf 0.419) */



void FUN_004699e0(int param_1)



{

  float fVar1;

  int iVar2;

  undefined1 uVar3;

  float10 fVar4;

  float10 fVar5;

  undefined4 uVar6;

  

  iVar2 = DAT_00632a88;

  *(int *)(param_1 + 0x274) = DAT_00632a88;

  fVar4 = (float10)FUN_0050a400(param_1 + 0xa0,iVar2 + 0xa0);

  fVar5 = (float10)FUN_0050a7c0((float)fVar4,*(undefined4 *)(param_1 + 200));

  fVar1 = (float)ABS(fVar5);

  if (ABS(fVar5) == (float10)0.0) {

    fVar1 = 0.0;

  }

  else {

    *(float *)(param_1 + 0x158) = (float)fVar4;

    *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) | 0x1000000;

    uVar3 = __ftol();

    *(undefined1 *)(param_1 + 0x208) = uVar3;

  }

  if (5.0 <= fVar1) {

    if ((*(int *)(param_1 + 0x10) != 0x26) && (*(int *)(*(int *)(param_1 + 8) + 0xa0) != 0)) {

      FUN_004034a0(param_1,0x26,0x21,3,

                   *(float *)(DAT_00632ed8 + 0x15dc) * *(float *)(param_1 + 0xc4),0x3e2aaaab);

      FUN_00495750(0x6dc,param_1);

      FUN_00495750(0x6dd,param_1);

    }

    *(undefined4 *)(param_1 + 0xe4) = 0xe;

    return;

  }

  fVar4 = (float10)FUN_0050a5e0(param_1 + 0xa0,*(int *)(param_1 + 0x274) + 0xa0);

  if ((float10)*(float *)(DAT_00632ed8 + 0x11c0) * (float10)*(float *)(DAT_00632ed8 + 0x11c0) <=

      fVar4) {

    if ((*(int *)(param_1 + 0x10) == 0xa7) || (*(int *)(*(int *)(param_1 + 8) + 0x2a4) == 0))

    goto LAB_00469b54;

    fVar1 = *(float *)(param_1 + 0xc4);

    uVar6 = 0xa7;

  }

  else {

    if ((*(int *)(param_1 + 0x10) == 0xa6) || (*(int *)(*(int *)(param_1 + 8) + 0x2a0) == 0))

    goto LAB_00469b54;

    fVar1 = *(float *)(param_1 + 0xc4);

    uVar6 = 0xa6;

  }

  FUN_004034a0(param_1,uVar6,0x20,0,fVar1 * 0.0,0x3e2aaaab);

  FUN_00495750(0x6dc,param_1);

  FUN_00495750(0x6dd,param_1);

LAB_00469b54:

  *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xfffffff7;

  *(undefined4 *)(param_1 + 0xe4) = 0xc;

  return;

}

/* ===== FUN_0046a480 @ 0x0046A480 ===== */
void FUN_0046a480(int param_1,float param_2)



{

  int iVar1;

  int iVar2;

  float fVar3;

  

  iVar1 = *(int *)(param_1 + 0x100);

  iVar2 = *(int *)(iVar1 + 4);

  if (iVar2 != 0) {

    fVar3 = param_2 * *(float *)(iVar2 + 0x194);

    *(float *)(iVar1 + 0x88) = fVar3;

    fVar3 = fVar3 * 0.5;

    *(float *)(iVar1 + 0x84) = fVar3;

    *(float *)(iVar1 + 0x8c) = fVar3 * 0.15915494;

    *(float *)(param_1 + 0xc4) = param_2 * *(float *)(iVar2 + 0xc4);

    FUN_004148a0(param_1);

  }

  return;

}

/* ===== FUN_0046a4e0 @ 0x0046A4E0 ===== */
void FUN_0046a4e0(int param_1,int param_2)



{

  int iVar1;

  undefined4 uVar2;

  

  *(undefined4 *)(param_2 + 0x30) = *(undefined4 *)(param_1 + 0xe4);

  *(undefined4 *)(param_2 + 4) = *(undefined4 *)(param_1 + 0x10);

  *(uint *)(param_2 + 0xc) = *(uint *)(param_1 + 0x30) & 2;

  *(undefined4 *)(param_2 + 0x40) = 0;

  if ((*(int *)(param_1 + 0x10) < 0xfe) &&

     (iVar1 = *(int *)(*(int *)(param_1 + 8) + 8 + *(int *)(param_1 + 0x10) * 4), iVar1 != 0)) {

    *(undefined4 *)(param_2 + 0x40) = *(undefined4 *)(iVar1 + 0x28);

  }

  if (*(int *)(param_2 + 0x40) != 0) {

    uVar2 = FUN_0053c5f0(*(int *)(param_2 + 0x40),*(undefined4 *)(param_1 + 0x18));

    *(undefined4 *)(param_2 + 0x38) = uVar2;

    uVar2 = FUN_0053c5f0(*(undefined4 *)(param_2 + 0x40),*(undefined4 *)(param_1 + 0x14));

    *(undefined4 *)(param_2 + 0x3c) = uVar2;

    return;

  }

  *(undefined4 *)(param_2 + 0x3c) = 0;

  *(undefined4 *)(param_2 + 0x38) = 0;

  return;

}

/* ===== FUN_0046a710 @ 0x0046A710 ===== */
uint FUN_0046a710(int param_1,undefined4 *param_2,int param_3)



{

  int iVar1;

  undefined4 uVar2;

  undefined4 uVar3;

  undefined4 uVar4;

  uint uVar5;

  undefined4 local_14;

  undefined4 local_10;

  int local_c;

  uint local_8;

  undefined4 local_4;

  

  iVar1 = param_2[2];

  uVar5 = 0;

  *param_2 = 0;

  param_2[6] = param_2[6] & 0xfffffeff;

  if ((-1 < iVar1) && ((param_2[1] != iVar1 || (param_2[0xb] != 0)))) {

    uVar2 = param_2[9];

    uVar3 = param_2[7];

    uVar5 = ~param_2[5] & param_2[4];

    uVar4 = param_2[8];

    FUN_004034a0(param_1,iVar1,uVar5,uVar3,uVar4,uVar2);

    if (param_3 != 0) {

      local_14 = uVar4;

      local_10 = uVar2;

      local_c = iVar1;

      local_8 = uVar5;

      local_4 = uVar3;

      FUN_00530bd0(param_1,3,3,0,4,&local_14);

    }

    if ((char)uVar5 < '\0') {

      *(undefined4 *)(param_1 + 0x14) = param_2[10];

    }

    FUN_00403e60(param_1,0);

    uVar5 = 1;

  }

  iVar1 = param_2[0xd];

  if ((-1 < iVar1) && (param_2[0xc] != iVar1)) {

    *(int *)(param_1 + 0xe4) = iVar1;

    uVar5 = uVar5 | 2;

  }

  return uVar5;

}

/* ===== FUN_0046a800 @ 0x0046A800 ===== */
void FUN_0046a800(uint param_1,float *param_2)



{

  uint *puVar1;

  uint uVar2;

  uint uVar3;

  float10 fVar4;

  float10 fVar5;

  float local_c;

  float local_8;

  uint local_4;

  

  uVar3 = param_1;

  puVar1 = *(uint **)(param_1 + 0x100);

  uVar2 = puVar1[4];

  if ((uVar2 == 0) || ((*puVar1 & 0x10) == 0)) {

    *puVar1 = *puVar1 & 0xffffffef;

  }

  else {

    puVar1[5] = *(uint *)(uVar2 + 0xa0);

    puVar1[6] = *(uint *)(uVar2 + 0xa4);

    puVar1[7] = *(uint *)(uVar2 + 0xa8);

  }

  if ((uVar2 == 0) || ((*puVar1 & 0x20) == 0)) {

    *puVar1 = *puVar1 & 0xffffffdf;

  }

  else {

    local_c = (float)puVar1[5] - *(float *)(param_1 + 0xa0);

    local_8 = (float)puVar1[6] - *(float *)(param_1 + 0xa4);

    fVar4 = (float10)FUN_0050a390(local_8,local_c);

    puVar1[0xc] = (uint)(float)(fVar4 + (float10)90.0);

  }

  uVar2 = *puVar1;

  *puVar1 = uVar2 | 0xc0;

  puVar1[8] = (uint)DAT_0059da70;

  puVar1[9] = DAT_0059da74;

  puVar1[10] = DAT_0059da78;

  puVar1[0xb] = 0;

  if ((uVar2 & 4) != 0) {

    fVar4 = (float10)FUN_004a2650(&local_c,&param_1,puVar1 + 5,uVar3 + 0xa0,

                                  (float)puVar1[0x24] * (float)puVar1[0x21],

                                  (float)puVar1[0x22] * (float)puVar1[0x24],0x3f800000);

    puVar1[0xd] = (uint)(float)fVar4;

    fVar5 = (float10)*param_2;

    if ((float10)0.25 < fVar5) {

      fVar5 = (float10)0.25;

    }

    if ((float10)(float)puVar1[0x24] * (float10)(float)puVar1[0x21] * fVar5 * (float10)4.0 < fVar4)

    {

      fVar4 = (float10)FUN_0050a390(local_8,local_c);

      puVar1[0xc] = (uint)(float)(fVar4 + (float10)90.0);

      puVar1[8] = (uint)local_c;

      puVar1[9] = (uint)local_8;

      puVar1[10] = local_4;

      puVar1[0xb] = param_1;

      *puVar1 = *puVar1 & 0xffffffbf | 8;

    }

  }

  *(undefined4 *)(uVar3 + 0x114) = 0;

  if ((*puVar1 & 8) != 0) {

    fVar4 = (float10)FUN_0050a7c0(puVar1[0xc],*(undefined4 *)(uVar3 + 200));

    puVar1[0xe] = (uint)(float)fVar4;

    if ((float10)-90.0 <= fVar4) {

      if ((float10)90.0 < fVar4) {

        fVar4 = (float10)90.0;

      }

    }

    else {

      fVar4 = (float10)-90.0;

    }

    *(float *)(uVar3 + 0x114) = (float)((float10)5.0 * fVar4);

    puVar1[0x28] = 0x3e4ccccd;

    if (fVar4 < (float10)-1.0) {

      *puVar1 = *puVar1 & 0xffffff7f;

    }

    else if ((float10)1.0 < fVar4) {

      *puVar1 = *puVar1 & 0xffffff7f;

      return;

    }

  }

  return;

}

/* ===== FUN_0046aa30 @ 0x0046AA30 ===== */
void FUN_0046aa30(int param_1,int param_2)



{

  uint *puVar1;

  bool bVar2;

  bool bVar3;

  undefined4 uVar4;

  int iVar5;

  char *pcVar6;

  undefined4 uVar7;

  undefined1 *puVar8;

  undefined1 local_50 [8];

  float local_48;

  undefined1 local_34 [4];

  undefined4 local_30;

  undefined4 local_2c;

  undefined4 local_28;

  undefined4 local_24;

  undefined4 local_20;

  int local_1c;

  

  puVar1 = *(uint **)(param_1 + 0x100);

  if ((*(byte *)(param_1 + 0xe0) & 1) != 0) {

    return;

  }

  if ((~*puVar1 & 0x40) == 0) {

    return;

  }

  if ((float)puVar1[3] * 3.0 <=

      (*(float *)(param_1 + 0xa8) - *(float *)(param_1 + 0x1d4) * *(float *)(param_1 + 0xc4)) -

      *(float *)(param_1 + 0x140)) {

    if (0.5 <= (float)puVar1[3]) {

      *(undefined4 *)(param_2 + 8) = 0x46;

      *(uint *)(param_2 + 0x10) = *(uint *)(param_2 + 0x10) | 1;

      return;

    }

    *(undefined4 *)(param_2 + 8) = 0x2a;

    *(uint *)(param_2 + 0x10) = *(uint *)(param_2 + 0x10) | 1;

    return;

  }

  *(undefined4 *)(param_2 + 0x1c) = 1;

  if (puVar1[0x1f] == 0) {

    bVar2 = *(float *)(param_1 + 0xa8) < 0.0;

    bVar3 = *(float *)(param_1 + 0xa8) == 0.0;

    if ((float)puVar1[0x22] * 1.5 < *(float *)(param_1 + 0x10c)) {

      if (0.5 <= (float)puVar1[3]) {

        if (bVar2 == bVar3) {

          FUN_00414690((undefined4 *)(param_1 + 0xa0),local_50);

          if (0.64278 <= local_48) {

            *(undefined4 *)(param_2 + 8) = 0x48;

            *(uint *)(param_2 + 0x10) = *(uint *)(param_2 + 0x10) | 1;

            *(float *)(param_2 + 0x20) = *(float *)(param_1 + 0xc4) * 75.0;

            if (*(int *)(param_2 + 4) != 0x48) {

              return;

            }

            if (*(int *)(param_2 + 0x3c) < 0xd20) {

              return;

            }

            if (0xd1f < *(int *)(param_2 + 0x38)) {

              return;

            }

            local_30 = *(undefined4 *)(param_1 + 0xa0);

            local_2c = *(undefined4 *)(param_1 + 0xa4);

            local_28 = *(undefined4 *)(param_1 + 0xa8);

            fx_get_free_effect__Fv();

            return;

          }

          goto LAB_0046ac2e;

        }

      }

      else if (bVar2 == bVar3) {

        FUN_00414690(param_1 + 0xa0,local_50);

        if (0.64278 <= local_48) {

          *(undefined4 *)(param_2 + 8) = 0x2c;

          goto LAB_0046acf5;

        }

LAB_0046ac2e:

        *(undefined4 *)(param_2 + 8) = 99;

        *(uint *)(param_2 + 0x10) = *(uint *)(param_2 + 0x10) | 1;

        iVar5 = *(int *)(param_1 + 0x100);

        *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 1;

        *(undefined4 *)(iVar5 + 0xb8) = *(undefined4 *)(param_1 + 0xe4);

LAB_0046ad71:

        puVar8 = local_34;

        *(undefined4 *)(iVar5 + 0xbc) = 0x3f800000;

        uVar7 = 0x24;

        pcVar6 = s_fx_ripper_dirt_0055b4d8;

        *(undefined4 *)(param_1 + 0xe4) = 0xc;

        local_1c = param_1;

        local_20 = 0xffffffff;

        local_24 = 8;

        uVar4 = fx_get_free_effect__Fv();

        *(undefined4 *)(iVar5 + 0xc0) = uVar4;

        *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) | 0x40000000;

        *(uint *)(*(int *)(iVar5 + 0xb0) + 0xd8) =

             *(uint *)(*(int *)(iVar5 + 0xb0) + 0xd8) | 0x40000000;

        iVar5 = FUN_0052e4a0(param_1,pcVar6,uVar7,puVar8);

        if (iVar5 == 0) {

          return;

        }

        FUN_00530bd0(param_1,0,0,0,9,0);

        return;

      }

    }

    else if (0.5 <= (float)puVar1[3]) {

      if (bVar2 == bVar3) {

        FUN_00414690(param_1 + 0xa0,local_50);

        if (0.64278 <= local_48) {

          *(undefined4 *)(param_2 + 8) = 0x47;

          *(uint *)(param_2 + 0x10) = *(uint *)(param_2 + 0x10) | 1;

          *(float *)(param_2 + 0x20) = *(float *)(param_1 + 0xc4) * 25.0;

          return;

        }

        *(undefined4 *)(param_2 + 8) = 99;

        *(uint *)(param_2 + 0x10) = *(uint *)(param_2 + 0x10) | 1;

        iVar5 = *(int *)(param_1 + 0x100);

        *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 1;

        *(undefined4 *)(iVar5 + 0xb8) = *(undefined4 *)(param_1 + 0xe4);

        goto LAB_0046ad71;

      }

    }

    else if (bVar2 == bVar3) {

      FUN_00414690(param_1 + 0xa0,local_50);

      if (0.64278 <= local_48) {

        *(undefined4 *)(param_2 + 8) = 0x2b;

        *(uint *)(param_2 + 0x10) = *(uint *)(param_2 + 0x10) | 1;

        *(float *)(param_2 + 0x20) = *(float *)(param_1 + 0xc4) * 20.0;

        return;

      }

      goto LAB_0046ad3d;

    }

  }

  else if (*(float *)(param_1 + 0xa8) < 0.0 == (*(float *)(param_1 + 0xa8) == 0.0)) {

    FUN_00414690((undefined4 *)(param_1 + 0xa0),local_50);

    if (0.64278 <= local_48) {

      *(undefined4 *)(param_2 + 8) = 0x59;

      *(uint *)(param_2 + 0x10) = *(uint *)(param_2 + 0x10) | 1;

      *(float *)(param_2 + 0x20) = *(float *)(param_1 + 0xc4) * 50.0;

      if (*(int *)(param_2 + 4) != 0x59) {

        return;

      }

      if (*(int *)(param_2 + 0x3c) < 0xe60) {

        return;

      }

      if (0xe5f < *(int *)(param_2 + 0x38)) {

        return;

      }

      local_30 = *(undefined4 *)(param_1 + 0xa0);

      local_2c = *(undefined4 *)(param_1 + 0xa4);

      local_28 = *(undefined4 *)(param_1 + 0xa8);

      fx_get_free_effect__Fv();

      return;

    }

LAB_0046ad3d:

    *(undefined4 *)(param_2 + 8) = 99;

    *(uint *)(param_2 + 0x10) = *(uint *)(param_2 + 0x10) | 1;

    iVar5 = *(int *)(param_1 + 0x100);

    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 1;

    *(undefined4 *)(iVar5 + 0xb8) = *(undefined4 *)(param_1 + 0xe4);

    goto LAB_0046ad71;

  }

  *(undefined4 *)(param_2 + 8) = 100;

LAB_0046acf5:

  *(uint *)(param_2 + 0x10) = *(uint *)(param_2 + 0x10) | 1;

  *(float *)(param_2 + 0x20) = *(float *)(param_1 + 0xc4) * 60.0;

  return;

}

/* ===== FUN_0046aeb0 @ 0x0046AEB0 ===== */
/* PS2 candidate: kbos_init (conf 0.471) */



void FUN_0046aeb0(int param_1)



{

  float fVar1;

  uint *puVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  uint uVar6;

  float10 fVar7;

  

  puVar2 = *(uint **)(param_1 + 0x100);

  if ((~*puVar2 & 1) != 0) {

    *(uint **)(param_1 + 0x104) = puVar2 + 0x10;

    FUN_004a1740(param_1);

    *(undefined4 *)(*(int *)(param_1 + 0x104) + 8) = *(undefined4 *)(param_1 + 0x200);

    fVar1 = *(float *)(param_1 + 0x200) * *(float *)(param_1 + 0x1b8);

    *(float *)(*(int *)(param_1 + 0x104) + 4) = fVar1 + fVar1;

    *(undefined4 *)(*(int *)(param_1 + 0x104) + 0x30) = *(undefined4 *)(param_1 + 0x1bc);

    puVar2[8] = DAT_0059da70;

    puVar2[9] = DAT_0059da74;

    puVar2[10] = DAT_0059da78;

    puVar2[0xb] = 0;

    uVar6 = FUN_00497d70(*(undefined4 *)(param_1 + 4));

    puVar2[1] = uVar6;

    puVar2[0x26] = 0;

    puVar2[0x25] = 0;

    puVar2[0x27] = (uint)(*(float *)(param_1 + 0x1b8) * -64.3481);

    fVar1 = *(float *)(param_1 + 400);

    puVar2[0x2a] = 0;

    puVar2[0x29] = (uint)(fVar1 * 30.0);

    if (*(int *)(param_1 + 4) == 0x2e9) {

      uVar6 = FUN_00496c00(0x3b1,1);

      puVar2[0x2c] = uVar6;

      *(int *)(uVar6 + 0x210) = param_1;

      *(undefined4 *)(puVar2[0x2c] + 0x214) = 0;

      *(undefined4 *)(puVar2[0x2c] + 0x218) = 0;

      *(undefined4 *)(puVar2[0x2c] + 0x18c) = *(undefined4 *)(param_1 + 0x18c);

      *(uint *)(puVar2[0x2c] + 0xd8) = *(uint *)(puVar2[0x2c] + 0xd8) | 0x400000;

      *(uint *)(puVar2[0x2c] + 0x1c8) = *(uint *)(puVar2[0x2c] + 0x1c8) | 0x4000000;

      *(uint *)(puVar2[0x2c] + 0xdc) = *(uint *)(puVar2[0x2c] + 0xdc) | 0x2000000;

      *(uint *)(puVar2[0x2c] + 0xd8) = *(uint *)(puVar2[0x2c] + 0xd8) | 0x20000000;

    }

    *puVar2 = *puVar2 | 1;

  }

  if (((*(int *)(param_1 + 0xe4) != 0) && (puVar2[0xf] == *(uint *)(param_1 + 0xe8))) ||

     (puVar2[0xf] = *(uint *)(param_1 + 0xe8), *(int *)(param_1 + 0xe4) != 0)) {

    return;

  }

  fVar7 = (float10)FUN_004d5780(0x41700000,0x41f00000);

  *(float *)(param_1 + 0xf0) = (float)fVar7;

  **(uint **)(param_1 + 0x100) = **(uint **)(param_1 + 0x100) & 0xffffffc3;

  *(undefined4 *)(param_1 + 0x178) = *(undefined4 *)(param_1 + 0xa0);

  *(undefined4 *)(param_1 + 0x17c) = *(undefined4 *)(param_1 + 0xa4);

  *(undefined4 *)(param_1 + 0x180) = *(undefined4 *)(param_1 + 0xa8);

  iVar3 = *(int *)(param_1 + 4);

  if (iVar3 != 0x2e9) {

    if (iVar3 == 0x2eb) {

      *(undefined4 *)(param_1 + 0xec) = 0x41f00000;

      *(undefined4 *)(param_1 + 0xe4) = 0x1d;

    }

    else {

      if (iVar3 != 0x2ec) {

        if (iVar3 != 0x2ea) {

          *(undefined4 *)(param_1 + 0xe4) = 1;

          return;

        }

        if (*(int *)(param_1 + 0xe8) == 1) {

          FUN_00495840(0x4b2,(undefined4 *)(param_1 + 0xa0));

          *(undefined4 *)(param_1 + 0xe4) = 3;

        }

        else {

          FUN_004954e0(0x4b1,param_1);

          *(undefined4 *)(param_1 + 0xe4) = 2;

        }

        *puVar2 = *puVar2 | 2;

        *(uint *)(param_1 + 0x1cc) = *(uint *)(param_1 + 0x1cc) | 1;

        *(uint *)(param_1 + 0x1c8) = *(uint *)(param_1 + 0x1c8) & 0xfffffdff | 0x400;

        return;

      }

      fVar7 = (float10)FUN_004d5780(0xc20c0000,0x420c0000);

      *(float *)(param_1 + 0x128) = (float)fVar7;

      fVar7 = (float10)FUN_004d5780(0xc20c0000,0x420c0000);

      *(float *)(param_1 + 300) = (float)fVar7;

      fVar7 = (float10)FUN_004d5780(0x41700000,0x41c80000);

      *(float *)(param_1 + 0x130) = (float)fVar7;

      *(undefined4 *)(*(int *)(param_1 + 0x104) + 0xc) = 0x3f800000;

      *(undefined4 *)(*(int *)(param_1 + 0x104) + 0x10) = 0x3e800000;

      fVar7 = (float10)FUN_004d5760(0x43b40000);

      *(float *)(param_1 + 200) = (float)fVar7;

      fVar7 = (float10)FUN_004d5780(0x3f800000,0x40400000);

      *(float *)(param_1 + 0xec) = (float)fVar7;

      *(undefined4 *)(param_1 + 0xe4) = 0x1b;

    }

    *puVar2 = *puVar2 | 2;

    *(uint *)(param_1 + 0x1c8) = *(uint *)(param_1 + 0x1c8) & 0xfffffdff | 0xc00;

    return;

  }

  iVar3 = *(int *)(param_1 + 0xe8);

  if (iVar3 == 0) {

    puVar2[2] = 0x3e800000;

    puVar2[3] = 0x3e4ccccd;

    iVar3 = *(int *)(param_1 + 0x100);

    iVar4 = *(int *)(iVar3 + 4);

    if (iVar4 != 0) {

      fVar1 = *(float *)(iVar4 + 0x194) * 0.2;

      *(float *)(iVar3 + 0x88) = fVar1;

      fVar1 = fVar1 * 0.5;

      *(float *)(iVar3 + 0x84) = fVar1;

      *(float *)(iVar3 + 0x8c) = fVar1 * 0.15915494;

      *(float *)(param_1 + 0xc4) = *(float *)(iVar4 + 0xc4) * 0.2;

      FUN_004148a0(param_1);

    }

    *(undefined4 *)(param_1 + 0xe4) = 6;

    return;

  }

  if (iVar3 != 1) {

    puVar2[3] = 0x3f000000;

    puVar2[2] = 0x3f000000;

    iVar4 = *(int *)(param_1 + 0x100);

    iVar5 = *(int *)(iVar4 + 4);

    if (iVar3 != 2) {

      if (iVar5 != 0) {

        fVar1 = *(float *)(iVar5 + 0x194) * 0.5;

        *(float *)(iVar4 + 0x88) = fVar1;

        fVar1 = fVar1 * 0.5;

        *(float *)(iVar4 + 0x84) = fVar1;

        *(float *)(iVar4 + 0x8c) = fVar1 * 0.15915494;

        *(float *)(param_1 + 0xc4) = *(float *)(iVar5 + 0xc4) * 0.5;

        FUN_004148a0(param_1);

      }

      FUN_004034a0(param_1,0x49,0x21,3,0x42b40000,0);

      *(undefined4 *)(param_1 + 0xe4) = 1;

      *(undefined1 *)(param_1 + 0x208) = 0xec;

      return;

    }

    if (iVar5 != 0) {

      fVar1 = *(float *)(iVar5 + 0x194) * 0.5;

      *(float *)(iVar4 + 0x88) = fVar1;

      fVar1 = fVar1 * 0.5;

      *(float *)(iVar4 + 0x84) = fVar1;

      *(float *)(iVar4 + 0x8c) = fVar1 * 0.15915494;

      *(float *)(param_1 + 0xc4) = *(float *)(iVar5 + 0xc4) * 0.5;

      FUN_004148a0(param_1);

    }

    FUN_004034a0(param_1,0x49,0x21,3,0x42b40000,0);

    *(undefined4 *)(param_1 + 0xe4) = 1;

    *(undefined1 *)(param_1 + 0x208) = 0x14;

    return;

  }

  puVar2[2] = 0x3f800000;

  puVar2[3] = 0x3f800000;

  iVar3 = *(int *)(param_1 + 0x100);

  iVar4 = *(int *)(iVar3 + 4);

  if (iVar4 != 0) {

    fVar1 = *(float *)(iVar4 + 0x194);

    *(float *)(iVar3 + 0x88) = fVar1;

    fVar1 = fVar1 * 0.5;

    *(float *)(iVar3 + 0x84) = fVar1;

    *(float *)(iVar3 + 0x8c) = fVar1 * 0.15915494;

    *(undefined4 *)(param_1 + 0xc4) = *(undefined4 *)(iVar4 + 0xc4);

    FUN_004148a0(param_1);

  }

  FUN_004034a0(param_1,5,0x21,0,0,0);

  *(undefined4 *)(param_1 + 0xe4) = 1;

  return;

}

/* ===== FUN_0046b3f0 @ 0x0046B3F0 ===== */
void FUN_0046b3f0(undefined4 param_1,undefined4 param_2)



{

  object_init_usage(param_1);

  FUN_004993c0(param_1,param_2);

  FUN_004a7440(param_1);

  FUN_0049a1f0(param_1);

  FUN_0046aeb0(param_1);

  return;

}

/* ===== FUN_0046b420 @ 0x0046B420 ===== */
float10 FUN_0046b420(int param_1)



{

  if ((param_1 != 0) && (*(int *)(param_1 + 4) == 0x2e9)) {

    return (float10)*(float *)(*(int *)(param_1 + 0x100) + 0xc);

  }

  return (float10)0.0;

}

/* ===== FUN_0046b450 @ 0x0046B450 ===== */
float10 FUN_0046b450(int param_1)



{

  if ((param_1 != 0) && (*(int *)(param_1 + 4) == 0x2e9)) {

    return (float10)*(float *)(*(int *)(param_1 + 0x100) + 8);

  }

  return (float10)0.0;

}

/* ===== FUN_0046b480 @ 0x0046B480 ===== */
undefined4 FUN_0046b480(int param_1,undefined4 param_2,char param_3)



{

  float fVar1;

  int iVar2;

  float fVar3;

  int iVar4;

  undefined4 local_8;

  char local_4;

  

  if ((param_1 != 0) && (*(int *)(param_1 + 4) == 0x2e9)) {

    iVar2 = *(int *)(param_1 + 0x100);

    *(undefined4 *)(iVar2 + 8) = param_2;

    iVar4 = FUN_0052e4a0(param_1);

    if (iVar4 != 0) {

      local_8 = *(undefined4 *)(iVar2 + 8);

      local_4 = param_3;

      FUN_00530bd0(param_1,1,0,1,3,&local_8);

    }

    if (param_3 != '\0') {

      fVar1 = *(float *)(iVar2 + 8);

      *(float *)(iVar2 + 0xc) = fVar1;

      iVar2 = *(int *)(param_1 + 0x100);

      iVar4 = *(int *)(iVar2 + 4);

      if (iVar4 != 0) {

        fVar3 = fVar1 * *(float *)(iVar4 + 0x194);

        *(float *)(iVar2 + 0x88) = fVar3;

        fVar3 = fVar3 * 0.5;

        *(float *)(iVar2 + 0x84) = fVar3;

        *(float *)(iVar2 + 0x8c) = fVar3 * 0.15915494;

        *(float *)(param_1 + 0xc4) = fVar1 * *(float *)(iVar4 + 0xc4);

        FUN_004148a0(param_1);

        return 1;

      }

    }

    return 1;

  }

  return 0;

}

/* ===== FUN_0046b560 @ 0x0046B560 ===== */
int FUN_0046b560(undefined4 param_1,undefined4 param_2,undefined4 *param_3)



{

  int iVar1;

  

  iVar1 = FUN_00496c00(0x2ea,0x80000000);

  *(undefined4 *)(iVar1 + 0xe8) = 1;

  object_init_usage(iVar1);

  FUN_004993c0(iVar1,param_2);

  FUN_004a7440(iVar1);

  FUN_0049a1f0(iVar1);

  FUN_0046aeb0(iVar1);

  if (param_3 != (undefined4 *)0x0) {

    *(undefined4 *)(iVar1 + 0x128) = *param_3;

    *(undefined4 *)(iVar1 + 300) = param_3[1];

    *(undefined4 *)(iVar1 + 0x130) = param_3[2];

    *(undefined4 *)(iVar1 + 0x274) = param_1;

    return iVar1;

  }

  *(undefined4 *)(iVar1 + 0x274) = param_1;

  return iVar1;

}

/* ===== FUN_0046b5e0 @ 0x0046B5E0 ===== */
int FUN_0046b5e0(undefined4 param_1)



{

  int iVar1;

  

  iVar1 = FUN_00496c00(0x2e9,0x80000000);

  if (iVar1 != 0) {

    FUN_00499e70(iVar1,0x4b);

    *(undefined4 *)(iVar1 + 0xe8) = 0;

    object_init_usage(iVar1);

    FUN_004993c0(iVar1,param_1);

    FUN_004a7440(iVar1);

    FUN_0049a1f0(iVar1);

    FUN_0046aeb0(iVar1);

  }

  return iVar1;

}

/* ===== FUN_0046b640 @ 0x0046B640 ===== */
undefined4 FUN_0046b640(int param_1,uint *param_2)



{

  uint uVar1;

  uint uVar2;

  uint *puVar3;

  float10 fVar4;

  

  if (((*(float *)(param_1 + 0x278) < *(float *)(param_1 + 0x1c0)) &&

      (*(int *)(*(int *)(param_1 + 0x100) + 0x7c) == 0)) &&

     (*(int *)(*(int *)(param_1 + 0x100) + 0x80) == 0)) {

    uVar1 = *param_2;

    uVar2 = param_2[1];

    fVar4 = (float10)FUN_004143f0(param_2);

    *(uint *)(param_1 + 0x178) = uVar1;

    *(uint *)(param_1 + 0x17c) = uVar2;

    *(float *)(param_1 + 0x180) = (float)fVar4;

    puVar3 = *(uint **)(param_1 + 0x100);

    *puVar3 = *puVar3 & 0xffffffcf | 0xc;

    puVar3[5] = uVar1;

    puVar3[6] = uVar2;

    puVar3[7] = (uint)(float)fVar4;

    *(undefined4 *)(param_1 + 0xe4) = 0x10;

    return 1;

  }

  return 0;

}

/* ===== FUN_0046b6f0 @ 0x0046B6F0 ===== */
undefined4 FUN_0046b6f0(int param_1,uint *param_2,undefined4 param_3)



{

  int iVar1;

  uint uVar2;

  uint uVar3;

  uint *puVar4;

  float10 fVar5;

  

  iVar1 = *(int *)(param_1 + 0x100);

  if ((((*(float *)(param_1 + 0x278) < *(float *)(param_1 + 0x1c0)) &&

       (*(int *)(param_1 + 4) == 0x2e9)) && (*(int *)(param_1 + 0xe4) != 0)) &&

     ((*(int *)(iVar1 + 0x7c) == 0 && (*(int *)(iVar1 + 0x80) == 0)))) {

    uVar2 = *param_2;

    uVar3 = param_2[1];

    fVar5 = (float10)FUN_004143f0(param_2);

    *(uint *)(param_1 + 0x178) = uVar2;

    *(uint *)(param_1 + 0x17c) = uVar3;

    *(float *)(param_1 + 0x180) = (float)fVar5;

    puVar4 = *(uint **)(param_1 + 0x100);

    *puVar4 = *puVar4 & 0xffffffcf | 0xc;

    puVar4[5] = uVar2;

    puVar4[6] = uVar3;

    puVar4[7] = (uint)(float)fVar5;

    if ((*(byte *)(param_1 + 0xe0) & 1) == 0) {

      *(undefined4 *)(param_1 + 0xe4) = 10;

      *(undefined4 *)(iVar1 + 0xc4) = param_3;

      return 1;

    }

    *(undefined4 *)(iVar1 + 0xb8) = 10;

    *(undefined4 *)(iVar1 + 0xc4) = param_3;

    return 1;

  }

  return 0;

}

/* ===== FUN_0046b7f0 @ 0x0046B7F0 ===== */
undefined4 FUN_0046b7f0(int param_1,uint param_2,undefined4 param_3)



{

  uint *puVar1;

  

  puVar1 = *(uint **)(param_1 + 0x100);

  if (((*(float *)(param_1 + 0x278) < *(float *)(param_1 + 0x1c0)) && (puVar1[0x1f] == 0)) &&

     (puVar1[0x20] == 0)) {

    *puVar1 = *puVar1 | 0x3c;

    puVar1[4] = param_2;

    *(undefined4 *)(param_1 + 0xf4) = 0;

    *(undefined4 *)(param_1 + 0xf8) = param_3;

    *(undefined4 *)(param_1 + 0xe4) = 0x14;

    return 1;

  }

  return 0;

}

/* ===== FUN_0046b850 @ 0x0046B850 ===== */
undefined4 FUN_0046b850(int param_1)



{

  uint *puVar1;

  float10 fVar2;

  

  if (((*(float *)(param_1 + 0x278) < *(float *)(param_1 + 0x1c0)) &&

      (*(int *)(*(int *)(param_1 + 0x100) + 0x7c) == 0)) &&

     (*(int *)(*(int *)(param_1 + 0x100) + 0x80) == 0)) {

    fVar2 = (float10)FUN_0050a400(param_1 + 0xa0,DAT_00632a88 + 0xa0);

    puVar1 = *(uint **)(param_1 + 0x100);

    puVar1[0xc] = (uint)(float)fVar2;

    *puVar1 = *puVar1 & 0xffffffcb | 8;

    *(undefined4 *)(param_1 + 0xec) = 0x40a00000;

    *(undefined4 *)(param_1 + 0xe4) = 0x13;

    return 1;

  }

  return 0;

}

/* ===== FUN_0046baf0 @ 0x0046BAF0 ===== */
/* PS2 candidate: kbos_attach_object (conf 0.388) */



undefined4 FUN_0046baf0(undefined4 param_1,int param_2,char param_3,byte param_4,int param_5)



{

  uint *puVar1;

  uint uVar2;

  int iVar3;

  int *piVar4;

  int *piVar5;

  undefined4 local_8;

  char local_4;

  byte local_3;

  

  if ((((param_2 != 0) && (*(int *)(param_2 + 4) == 3)) && (*(int *)(param_2 + 0x210) != 0)) &&

     (*(int *)(*(int *)(param_2 + 0x210) + 4) == 0x434)) {

    return 0;

  }

  if ((param_5 != 0) && (iVar3 = FUN_0052e4a0(param_1), iVar3 != 0)) {

    local_8 = *(undefined4 *)(param_2 + 0x188);

    local_4 = param_3;

    local_3 = param_4;

    FUN_00530bd0(param_1,0,1,2,5,&local_8);

  }

  *(uint *)(param_2 + 0x218) = (uint)param_4;

  piVar4 = &DAT_0055b428;

  if (-1 < DAT_0055b428) {

    iVar3 = DAT_0055b428;

    do {

      if (iVar3 == *(int *)(param_2 + 4)) break;

      iVar3 = piVar4[0xb];

      piVar4 = piVar4 + 0xb;

    } while (-1 < iVar3);

  }

  if (*piVar4 == *(int *)(param_2 + 4)) {

    if (param_3 == '\0') {

      *(float *)(param_2 + 0xc4) = *(float *)(param_2 + 0xc4) / (float)piVar4[1];

      goto LAB_0046bc13;

    }

    piVar5 = piVar4 + 5;

    iVar3 = 0;

    uVar2 = piVar4[5];

    while ((uVar2 != param_4 && (-1 < (int)uVar2))) {

      puVar1 = (uint *)(piVar5 + 1);

      piVar5 = piVar5 + 1;

      iVar3 = iVar3 + 1;

      uVar2 = *puVar1;

    }

    *(float *)(param_2 + 0xc4) = (float)piVar4[1] * *(float *)(param_2 + 0xc4);

    *(int *)(param_2 + 0x214) = piVar4[iVar3 + 2];

    if (*(int *)(param_2 + 0x10) != piVar4[iVar3 + 8]) {

      FUN_004034a0(param_2,piVar4[iVar3 + 8],0x21,0,0,0);

      FUN_00403e60(param_2,0);

    }

  }

  else {

    *(undefined4 *)(param_2 + 0x214) = 0xffffffff;

  }

  if (param_3 != '\0') {

    *(undefined4 *)(param_2 + 0x210) = param_1;

    return 1;

  }

LAB_0046bc13:

  *(undefined4 *)(param_2 + 0x210) = 0;

  return 1;

}

/* ===== FUN_0046bc60 @ 0x0046BC60 ===== */
/* PS2 candidate: kbos_scan_food__FP6OBJECTP14ObjProcessInfo (conf 0.347) */



undefined4 FUN_0046bc60(float param_1,int *param_2)



{

  float fVar1;

  int iVar2;

  uint *puVar3;

  float fVar4;

  int iVar5;

  int iVar6;

  float10 fVar7;

  float local_24;

  float local_1c;

  float local_18;

  float local_14;

  undefined1 local_10;

  float local_c;

  float local_8;

  undefined4 local_4;

  

  iVar5 = (int)param_2;

  fVar4 = param_1;

  local_24 = 0.0;

  if ((*(uint *)((int)param_2 + 0x18) & 0x100) != 0) {

    fVar1 = *(float *)(*(int *)((int)param_1 + 0x100) + 8);

    local_14 = *(float *)(*(int *)((int)param_1 + 0x100) + 8) * 40.0;

    param_2 = DAT_00632d68;

    if (DAT_00632d68 != (int *)0x0) {

      iVar6 = 0;

      do {

        iVar2 = param_2[3];

        if ((((-1 < (char)((uint)*(undefined4 *)(iVar2 + 0xd8) >> 8)) &&

             (0x45c < *(int *)(iVar2 + 4))) && (*(int *)(iVar2 + 4) < 0x460)) &&

           ((*(byte *)(iVar2 + 0xe0) & 1) != 0)) {

          local_c = *(float *)(iVar2 + 0xa0) - *(float *)((int)fVar4 + 0xa0);

          local_4 = 0;

          local_8 = *(float *)(iVar2 + 0xa4) - *(float *)((int)fVar4 + 0xa4);

          fVar7 = (float10)FUN_0050a500(&local_c);

          param_1 = (float)fVar7;

          if (fVar7 <= (float10)(fVar1 * 300.0)) {

            local_c = local_c * (1.0 / param_1);

            local_8 = (1.0 / param_1) * local_8;

            FUN_0050ae40(*(undefined4 *)((int)fVar4 + 200),&local_1c,&local_18);

            if ((0.0 <= local_1c * local_c - local_18 * local_8) &&

               ((param_1 < local_24 || (iVar6 == 0)))) {

              local_24 = param_1;

              iVar6 = iVar2;

            }

          }

        }

        param_2 = (int *)*param_2;

      } while (param_2 != (int *)0x0);

      if (iVar6 != 0) {

        if (local_14 <= local_24) {

          if (*(int *)(iVar5 + 0x30) == 0xd) {

            return 1;

          }

          puVar3 = *(uint **)((int)fVar4 + 0x100);

          *puVar3 = *puVar3 & 0xffffffcf | 0xc;

          puVar3[5] = *(uint *)(iVar6 + 0xa0);

          puVar3[6] = *(uint *)(iVar6 + 0xa4);

          puVar3[7] = *(uint *)(iVar6 + 0xa8);

          *(undefined4 *)(iVar5 + 0x34) = 0xd;

          return 0;

        }

        if ((*(int *)(iVar5 + 4) != 0x30) || (*(int *)(iVar5 + 0x3c) < 0xb41)) {

          fVar7 = (float10)FUN_0050a400((int)fVar4 + 0xa0,iVar6 + 0xa0);

          param_1 = (float)fVar7;

          fVar7 = (float10)FUN_0050a7c0(param_1,*(undefined4 *)((int)fVar4 + 200));

          if ((float10)5.0 <= ABS(fVar7)) {

            if (*(int *)(iVar5 + 0x30) == 0xe) {

              return 1;

            }

            puVar3 = *(uint **)((int)fVar4 + 0x100);

            *puVar3 = *puVar3 & 0xffffffcb | 8;

            puVar3[0xc] = (uint)param_1;

            *(undefined4 *)(iVar5 + 0x34) = 0xe;

            return 0;

          }

          if (*(int *)(iVar5 + 0x30) == 0xf) {

            return 1;

          }

          FUN_004954e0(0x4ab,fVar4);

          **(uint **)((int)fVar4 + 0x100) = **(uint **)((int)fVar4 + 0x100) & 0xffffffc3;

          *(undefined4 *)(iVar5 + 8) = 0x30;

          *(undefined4 *)(iVar5 + 0x34) = 0xf;

          return 0;

        }

        param_1 = *(float *)(DAT_00632ed8 + 0x2b4);

        param_2 = *(int **)(DAT_00632ed8 + 0x2b8);

        *(undefined4 *)(DAT_00632ed8 + 0x2b4) = 0x3e99999a;

        *(undefined4 *)(DAT_00632ed8 + 0x2b8) = 0x3f666666;

        FUN_0040b350(iVar6 + 0xa0,0x3c,0x3c,0,0x43b40000,0x40a00000,0x41f00000,0x41200000,0x42200000

                    );

        *(float *)(DAT_00632ed8 + 0x2b4) = param_1;

        *(int **)(DAT_00632ed8 + 0x2b8) = param_2;

        iVar5 = FUN_0052e4a0(fVar4);

        if (iVar5 != 0) {

          param_1 = *(float *)(iVar6 + 0x188);

          FUN_00530bd0(fVar4,0,1,0,6,&param_1);

        }

        FUN_00497510(iVar6);

        iVar5 = *(int *)((int)fVar4 + 0x100);

        if (*(float *)((int)fVar4 + 0x1c0) <= *(float *)((int)fVar4 + 0x278)) {

          return 1;

        }

        if (1.0 <= *(float *)(iVar5 + 8)) {

          return 1;

        }

        if (*(int *)((int)fVar4 + 4) != 0x2e9) {

          return 1;

        }

        *(float *)(iVar5 + 8) = *(float *)(iVar5 + 8) + 0.25;

        iVar6 = FUN_0052e4a0(fVar4);

        if (iVar6 == 0) {

          return 1;

        }

        local_14 = *(float *)(iVar5 + 8);

        local_10 = 0;

        FUN_00530bd0(fVar4,1,0,1,3,&local_14);

        return 1;

      }

    }

    if ((*(int *)(iVar5 + 0x30) == 0xd) || (*(int *)(iVar5 + 0x30) == 0xe)) {

      **(uint **)((int)fVar4 + 0x100) = **(uint **)((int)fVar4 + 0x100) & 0xffffffc3;

    }

  }

  return 1;

}

/* ===== FUN_0046c060 @ 0x0046C060 ===== */
undefined4 FUN_0046c060(int param_1,int param_2)



{

  float fVar1;

  uint uVar2;

  uint *puVar3;

  float fVar4;

  uint uVar5;

  int *piVar6;

  float10 fVar7;

  float local_18;

  float local_14;

  float local_10;

  float local_c;

  float local_8;

  undefined4 local_4;

  

  uVar5 = 0;

  local_18 = 0.0;

  if ((*(int *)(*(int *)(param_1 + 0x100) + 0xc4) != 0) &&

     ((*(uint *)(param_2 + 0x18) & 0x100) != 0)) {

    fVar4 = *(float *)(*(int *)(param_1 + 0x100) + 8) * 300.0;

    piVar6 = DAT_00632d68;

    if (DAT_00632d68 != (int *)0x0) {

      do {

        uVar2 = piVar6[3];

        if (((((*(uint *)(uVar2 + 0xd8) & 0x4000c000) == 0) &&

             (*(float *)(uVar2 + 0x278) < *(float *)(uVar2 + 0x1c0))) &&

            ((*(uint *)(uVar2 + 0x1c8) & 0x400000) != 0)) && ((*(byte *)(uVar2 + 0x1d0) & 0xf) != 0)

           ) {

          local_c = *(float *)(uVar2 + 0xa0) - *(float *)(param_1 + 0xa0);

          local_4 = 0;

          local_8 = *(float *)(uVar2 + 0xa4) - *(float *)(param_1 + 0xa4);

          fVar7 = (float10)FUN_0050a5c0(&local_c);

          fVar1 = (float)fVar7;

          if (fVar7 <= (float10)(fVar4 * fVar4)) {

            local_c = local_c * (1.0 / fVar1);

            local_8 = (1.0 / fVar1) * local_8;

            FUN_0050ae40(*(undefined4 *)(param_1 + 200),&local_14,&local_10);

            if ((0.0 <= local_14 * local_c - local_10 * local_8) &&

               ((fVar1 < local_18 || (uVar5 == 0)))) {

              uVar5 = uVar2;

              local_18 = fVar1;

            }

          }

        }

        piVar6 = (int *)*piVar6;

      } while (piVar6 != (int *)0x0);

      if (uVar5 != 0) {

        puVar3 = *(uint **)(param_1 + 0x100);

        if (((*(float *)(param_1 + 0x278) < *(float *)(param_1 + 0x1c0)) && (puVar3[0x1f] == 0)) &&

           (puVar3[0x20] == 0)) {

          *puVar3 = *puVar3 | 0x3c;

          puVar3[4] = uVar2;

          *(undefined4 *)(param_1 + 0xf4) = 0;

          *(undefined4 *)(param_1 + 0xf8) = 1;

          *(undefined4 *)(param_1 + 0xe4) = 0x14;

        }

        return 0;

      }

    }

  }

  return 1;

}

/* ===== FUN_0046e120 @ 0x0046E120 ===== */
void FUN_0046e120(int param_1,undefined4 param_2)



{

  if ((param_1 != 0) && (*(int *)(param_1 + 0x100) != 0)) {

    *(undefined4 *)(*(int *)(param_1 + 0x100) + 0x48) = param_2;

  }

  return;

}

/* ===== FUN_0046e830 @ 0x0046E830 ===== */
/* PS2 candidate: formation_create_sonak__FP6OBJECTi (conf 0.4) */



int FUN_0046e830(int param_1,int param_2)



{

  undefined4 uVar1;

  int iVar2;

  int iVar3;

  undefined4 *puVar4;

  undefined4 *puVar5;

  

  iVar2 = FUN_00496c00(0x374,0x80000000);

  FUN_00499e70(iVar2,0x4c);

  *(undefined4 *)(iVar2 + 0xe8) = 0;

  *(uint *)(iVar2 + 0xd8) = *(uint *)(iVar2 + 0xd8) | 0x10000;

  iVar3 = *(int *)(param_2 + 0x210);

  if (iVar3 == 0) {

    puVar4 = (undefined4 *)(param_1 + 0x294);

    puVar5 = (undefined4 *)(iVar2 + 0x294);

    for (iVar3 = 0x11; iVar3 != 0; iVar3 = iVar3 + -1) {

      *puVar5 = *puVar4;

      puVar4 = puVar4 + 1;

      puVar5 = puVar5 + 1;

    }

  }

  else {

    (*(code *)PTR_FUN_00580c18)

              (iVar2 + 0x294,iVar3 + 0x294,

               *(int *)(param_2 + 0x218) * 0x44 + *(int *)(iVar3 + 0x2dc));

  }

  object_init_usage(iVar2);

  FUN_00499310(iVar2,*(undefined4 *)(iVar2 + 0x2a4),*(undefined4 *)(iVar2 + 0x2b4),

               *(undefined4 *)(iVar2 + 0x2c4));

  FUN_004a7440(iVar2);

  FUN_0049a1f0(iVar2);

  puVar4 = *(undefined4 **)(iVar2 + 0x100);

  if ((~puVar4[0x10] & 1) != 0) {

    puVar5 = puVar4;

    for (iVar3 = 0x1c; iVar3 != 0; iVar3 = iVar3 + -1) {

      *puVar5 = 0;

      puVar5 = puVar5 + 1;

    }

    *(undefined4 **)(iVar2 + 0x104) = puVar4;

    *(uint *)(iVar2 + 0xd8) = *(uint *)(iVar2 + 0xd8) & 0xffffffef;

    *(uint *)(iVar2 + 0x1c8) = *(uint *)(iVar2 + 0x1c8) & 0xfffff1ff;

    FUN_004a1740(iVar2);

    puVar4[0x10] = puVar4[0x10] | 3;

  }

  if ((*(int *)(iVar2 + 0xe4) == 0) || (puVar4[0xf] != *(int *)(iVar2 + 0xe8))) {

    puVar4[0xf] = *(undefined4 *)(iVar2 + 0xe8);

  }

  **(uint **)(iVar2 + 0x104) = **(uint **)(iVar2 + 0x104) | 0x300;

  *(undefined4 *)(*(int *)(iVar2 + 0x104) + 0x10) = 0;

  *(float *)(iVar2 + 0x154) = *(float *)(param_2 + 0x154) + *(float *)(param_2 + 0x154);

  *(float *)(iVar2 + 0x1ec) = (2.0 / *(float *)(param_1 + 0xc4)) * *(float *)(param_2 + 0x154);

  uVar1 = *(undefined4 *)(param_1 + 0xc4);

  *(int *)(iVar2 + 0x274) = param_1;

  *(undefined4 *)(iVar2 + 0xc4) = uVar1;

  *(int *)(*(int *)(iVar2 + 0x100) + 0x44) = param_2;

  return iVar2;

}

/* ===== FUN_0046e9d0 @ 0x0046E9D0 ===== */
void FUN_0046e9d0(int param_1,undefined4 *param_2,undefined4 param_3,float param_4,float param_5)



{

  undefined4 *puVar1;

  undefined4 uVar2;

  int iVar3;

  undefined4 *puVar4;

  

  puVar1 = *(undefined4 **)(param_1 + 0x100);

  if ((~puVar1[0x10] & 1) != 0) {

    puVar4 = puVar1;

    for (iVar3 = 0x1c; iVar3 != 0; iVar3 = iVar3 + -1) {

      *puVar4 = 0;

      puVar4 = puVar4 + 1;

    }

    *(undefined4 **)(param_1 + 0x104) = puVar1;

    *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) & 0xffffffef;

    *(uint *)(param_1 + 0x1c8) = *(uint *)(param_1 + 0x1c8) & 0xfffff1ff;

    FUN_004a1740(param_1);

    puVar1[0x10] = puVar1[0x10] | 3;

  }

  if ((*(int *)(param_1 + 0xe4) == 0) || (puVar1[0xf] != *(int *)(param_1 + 0xe8))) {

    puVar1[0xf] = *(undefined4 *)(param_1 + 0xe8);

  }

  puVar1[0x14] = *param_2;

  puVar1[0x15] = param_2[1];

  uVar2 = param_2[2];

  puVar1[0x1b] = param_4 * param_5;

  puVar1[0x16] = uVar2;

  puVar1[0x1a] = param_4;

  puVar1[0x13] = param_3;

  puVar1[0x10] = puVar1[0x10] | 4;

  return;

}

/* ===== FUN_0046f050 @ 0x0046F050 ===== */
/* PS2 candidate: lift_update_rider_position__FP6OBJECT (conf 0.492) */



void FUN_0046f050(int param_1)



{

  float *pfVar1;

  float fVar2;

  float fVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  undefined4 *puVar7;

  float fVar8;

  float10 fVar9;

  float local_170;

  float local_16c;

  float local_168;

  float local_164;

  undefined1 local_160 [8];

  float local_158;

  undefined1 auStack_154 [16];

  float fStack_144;

  float fStack_134;

  float fStack_124;

  undefined1 local_110 [68];

  undefined1 local_cc [68];

  undefined1 local_88 [68];

  undefined1 auStack_44 [68];

  

  iVar4 = *(int *)(param_1 + 0x100);

  FUN_004a76e0(*(undefined4 *)(iVar4 + 4),1,local_160);

  for (puVar7 = DAT_00632d6c; puVar7 != (undefined4 *)0x0; puVar7 = (undefined4 *)*puVar7) {

    iVar5 = puVar7[3];

    if ((*(float *)(iVar5 + 0xa8) <= local_158 + 2.0) &&

       (local_158 - 2.0 < *(float *)(iVar5 + 0xa8) != (local_158 - 2.0 == *(float *)(iVar5 + 0xa8)))

       ) {

      pfVar1 = (float *)(iVar5 + 0xa0);

      fVar9 = (float10)FUN_0050a5e0(pfVar1,local_160);

      if (fVar9 < (float10)900.0) {

        iVar6 = *(int *)(iVar4 + 4);

        fVar2 = *(float *)(iVar6 + 0xa0) - *(float *)(iVar6 + 0xac);

        fVar3 = *(float *)(iVar6 + 0xa4) - *(float *)(iVar6 + 0xb0);

        fVar8 = *(float *)(iVar6 + 0xa8) - *(float *)(iVar6 + 0xb4);

        local_170 = fVar2 + *pfVar1;

        *pfVar1 = local_170;

        local_16c = fVar3 + *(float *)(iVar5 + 0xa4);

        *(float *)(iVar5 + 0xa4) = local_16c;

        local_164 = fVar8 + *(float *)(iVar5 + 0xa8);

        *(float *)(iVar5 + 0xa8) = local_164;

        *(float *)(iVar5 + 0x2a4) = fVar2 + *(float *)(iVar5 + 0x2a4);

        *(float *)(iVar5 + 0x2b4) = fVar3 + *(float *)(iVar5 + 0x2b4);

        *(float *)(iVar5 + 0x2c4) = fVar8 + *(float *)(iVar5 + 0x2c4);

        iVar6 = *(int *)(iVar4 + 4);

        local_170 = *(float *)(iVar6 + 0xa0) - local_170;

        local_16c = *(float *)(iVar6 + 0xa4) - local_16c;

        local_168 = *(float *)(iVar6 + 0xa8) - local_164;

        FUN_0053dc10(local_88,&local_170);

        FUN_0053dd90(local_110,

                     (*(float *)(*(int *)(iVar4 + 4) + 0xf4) - *(float *)(*(int *)(iVar4 + 4) + 200)

                     ) * 0.017453292);

        (*(code *)PTR_FUN_00580c18)(local_cc,local_110,local_88);

        local_170 = -local_170;

        local_16c = -local_16c;

        local_168 = -local_168;

        FUN_0053dc10(auStack_44,&local_170);

        (*(code *)PTR_FUN_00580c18)(auStack_154,auStack_44,local_cc);

        *pfVar1 = fStack_144 + *pfVar1;

        *(float *)(iVar5 + 0xa4) = fStack_134 + *(float *)(iVar5 + 0xa4);

        *(float *)(iVar5 + 0xa8) = fStack_124 + *(float *)(iVar5 + 0xa8);

        *(float *)(iVar5 + 0x2a4) = fStack_144 + *(float *)(iVar5 + 0x2a4);

        *(float *)(iVar5 + 0x2b4) = fStack_134 + *(float *)(iVar5 + 0x2b4);

        *(float *)(iVar5 + 0x2c4) = fStack_124 + *(float *)(iVar5 + 0x2c4);

        fVar2 = *(float *)(*(int *)(iVar4 + 4) + 200);

        fVar3 = *(float *)(*(int *)(iVar4 + 4) + 0xf4);

        *(uint *)(iVar5 + 0xd8) = *(uint *)(iVar5 + 0xd8) | 0x10000000;

        *(float *)(iVar5 + 200) = (fVar2 - fVar3) + *(float *)(iVar5 + 200);

      }

    }

  }

  return;

}

/* ===== FUN_0046f2e0 @ 0x0046F2E0 ===== */
void FUN_0046f2e0(int param_1,int param_2)



{

  int iVar1;

  int iVar2;

  int iVar3;

  undefined4 uVar4;

  undefined1 local_18 [8];

  float local_10;

  undefined1 local_c [8];

  float local_4;

  

  iVar2 = param_1;

  iVar1 = *(int *)(param_1 + 0x100);

  FUN_004a76e0(*(undefined4 *)(iVar1 + 4),0,local_c);

  FUN_004a76e0(iVar2,0,local_18);

  *(float *)(iVar2 + 0xf4) = *(float *)(iVar2 + 200) + 180.0;

  *(float *)(iVar2 + 0xf8) = 180.0 / ((local_10 - local_4) * 0.1);

  *(undefined4 *)(*(int *)(iVar1 + 4) + 0x108) = 0x41200000;

  *(undefined4 *)(iVar2 + 0xe4) = 3;

  iVar3 = FUN_0052e4a0(iVar2);

  if (iVar3 != 0) {

    if (param_2 == 0) {

      param_1 = -1;

    }

    else {

      param_1 = *(int *)(param_2 + 0x188);

    }

    FUN_00530bd0(iVar2,0,1,0,1,&param_1);

  }

  uVar4 = sound_get_free_sequence__Fv();

  *(undefined4 *)(iVar1 + 8) = uVar4;

  return;

}

/* ===== FUN_0046f540 @ 0x0046F540 ===== */
undefined * FUN_0046f540(int param_1)



{

  uint uVar1;

  

  uVar1 = *(uint *)(param_1 + 0xe8);

  if (4 < uVar1) {

    uVar1 = 0;

  }

  return (&PTR_s_Illegal_0055b518)[uVar1];

}

/* ===== FUN_0046f7f0 @ 0x0046F7F0 ===== */
void FUN_0046f7f0(float *param_1)



{

  float fVar1;

  

  if (1.0 < *param_1) {

    *param_1 = 1.0;

  }

  if (1.0 < param_1[1]) {

    param_1[1] = 1.0;

  }

  if (1.0 < param_1[2]) {

    param_1[2] = 1.0;

  }

  if (*param_1 < 0.0) {

    *param_1 = 0.0;

  }

  if (param_1[1] < 0.0) {

    param_1[1] = 0.0;

  }

  if (param_1[2] < 0.0) {

    param_1[2] = 0.0;

  }

  fVar1 = SQRT(*param_1 * *param_1 + param_1[1] * param_1[1] + param_1[2] * param_1[2]);

  param_1[3] = fVar1;

  if (1.0 < fVar1) {

    param_1[3] = 1.0;

  }

  return;

}

/* ===== FUN_0046f8b0 @ 0x0046F8B0 ===== */
bool FUN_0046f8b0(int param_1)



{

  return *(int *)(param_1 + 0xe8) == 1;

}

/* ===== FUN_0046f8d0 @ 0x0046F8D0 ===== */
void FUN_0046f8d0(int param_1,uint *param_2)



{

  int *piVar1;

  uint *puVar2;

  int iVar3;

  undefined4 *puVar4;

  int iVar5;

  int local_c [3];

  

  puVar2 = *(uint **)(param_1 + 0x100);

  if ((~*puVar2 & 1) != 0) {

    if (*(int *)(param_1 + 0xe8) == 0) {

      local_c[0] = 0;

      local_c[1] = 0;

      local_c[2] = 0;

      for (puVar4 = DAT_00632d68; puVar4 != (undefined4 *)0x0; puVar4 = (undefined4 *)*puVar4) {

        iVar5 = puVar4[3];

        if (((*(int *)(iVar5 + 0x1e0) == 0x5c) && (iVar3 = *(int *)(iVar5 + 0xe8), 0 < iVar3)) &&

           (iVar3 < 4)) {

          *(int *)(&stack0xfffffff0 + iVar3 * 4) = iVar5;

        }

      }

      iVar5 = 0;

      do {

        piVar1 = local_c + iVar5;

        iVar5 = iVar5 + 1;

        if (*piVar1 == 0) goto LAB_0046f950;

      } while (iVar5 < 3);

      iVar5 = 0;

LAB_0046f950:

      *(int *)(param_1 + 0xe8) = iVar5;

    }

    puVar2[1] = 3;

    if ((~*puVar2 & 8) != 0) {

      puVar2[4] = 0x3f800000;

      puVar2[3] = 0x3f800000;

      puVar2[2] = 0x3f800000;

      *puVar2 = *puVar2 | 8;

    }

    if ((~*puVar2 & 4) != 0) {

      puVar2[10] = puVar2[2];

      puVar2[0xb] = puVar2[3];

      puVar2[0xc] = puVar2[4];

      puVar2[0xd] = puVar2[5];

      puVar2[6] = puVar2[2];

      puVar2[7] = puVar2[3];

      puVar2[8] = puVar2[4];

      puVar2[9] = puVar2[5];

      *puVar2 = *puVar2 | 4;

    }

    puVar2[0x16] = 0x3f800000;

    puVar2[0x14] = 0x5f7fffff;

    *(undefined4 *)(param_1 + 0xf4) = 1;

    *puVar2 = *puVar2 & 0xfffffffd | 1;

  }

  *param_2 = puVar2[2];

  param_2[1] = puVar2[3];

  param_2[2] = puVar2[4];

  param_2[3] = puVar2[5];

  return;

}

/* ===== FUN_0046fa10 @ 0x0046FA10 ===== */
void FUN_0046fa10(int param_1,uint *param_2)



{

  int *piVar1;

  uint *puVar2;

  int iVar3;

  undefined4 *puVar4;

  int iVar5;

  int local_c [3];

  

  puVar2 = *(uint **)(param_1 + 0x100);

  if ((~*puVar2 & 1) != 0) {

    if (*(int *)(param_1 + 0xe8) == 0) {

      local_c[0] = 0;

      local_c[1] = 0;

      local_c[2] = 0;

      for (puVar4 = DAT_00632d68; puVar4 != (undefined4 *)0x0; puVar4 = (undefined4 *)*puVar4) {

        iVar5 = puVar4[3];

        if (((*(int *)(iVar5 + 0x1e0) == 0x5c) && (iVar3 = *(int *)(iVar5 + 0xe8), 0 < iVar3)) &&

           (iVar3 < 4)) {

          *(int *)(&stack0xfffffff0 + iVar3 * 4) = iVar5;

        }

      }

      iVar5 = 0;

      do {

        piVar1 = local_c + iVar5;

        iVar5 = iVar5 + 1;

        if (*piVar1 == 0) goto LAB_0046fa90;

      } while (iVar5 < 3);

      iVar5 = 0;

LAB_0046fa90:

      *(int *)(param_1 + 0xe8) = iVar5;

    }

    puVar2[1] = 3;

    if ((~*puVar2 & 8) != 0) {

      puVar2[4] = 0x3f800000;

      puVar2[3] = 0x3f800000;

      puVar2[2] = 0x3f800000;

      *puVar2 = *puVar2 | 8;

    }

    if ((~*puVar2 & 4) != 0) {

      puVar2[10] = puVar2[2];

      puVar2[0xb] = puVar2[3];

      puVar2[0xc] = puVar2[4];

      puVar2[0xd] = puVar2[5];

      puVar2[6] = puVar2[2];

      puVar2[7] = puVar2[3];

      puVar2[8] = puVar2[4];

      puVar2[9] = puVar2[5];

      *puVar2 = *puVar2 | 4;

    }

    puVar2[0x16] = 0x3f800000;

    puVar2[0x14] = 0x5f7fffff;

    *(undefined4 *)(param_1 + 0xf4) = 1;

    *puVar2 = *puVar2 & 0xfffffffd | 1;

  }

  *param_2 = puVar2[0x11];

  param_2[1] = puVar2[0x12];

  param_2[2] = puVar2[0x13];

  return;

}

/* ===== FUN_0046fb50 @ 0x0046FB50 ===== */
void FUN_0046fb50(int param_1)



{

  int *piVar1;

  uint *puVar2;

  int iVar3;

  undefined4 *puVar4;

  int iVar5;

  int local_c [3];

  

  puVar2 = *(uint **)(param_1 + 0x100);

  if ((~*puVar2 & 1) != 0) {

    if (*(int *)(param_1 + 0xe8) == 0) {

      local_c[0] = 0;

      local_c[1] = 0;

      local_c[2] = 0;

      for (puVar4 = DAT_00632d68; puVar4 != (undefined4 *)0x0; puVar4 = (undefined4 *)*puVar4) {

        iVar5 = puVar4[3];

        if (((*(int *)(iVar5 + 0x1e0) == 0x5c) && (iVar3 = *(int *)(iVar5 + 0xe8), 0 < iVar3)) &&

           (iVar3 < 4)) {

          *(int *)(&stack0xfffffff0 + iVar3 * 4) = iVar5;

        }

      }

      iVar5 = 0;

      do {

        piVar1 = local_c + iVar5;

        iVar5 = iVar5 + 1;

        if (*piVar1 == 0) goto LAB_0046fbd0;

      } while (iVar5 < 3);

      iVar5 = 0;

LAB_0046fbd0:

      *(int *)(param_1 + 0xe8) = iVar5;

    }

    puVar2[1] = 3;

    if ((~*puVar2 & 8) != 0) {

      puVar2[4] = 0x3f800000;

      puVar2[3] = 0x3f800000;

      puVar2[2] = 0x3f800000;

      *puVar2 = *puVar2 | 8;

    }

    if ((~*puVar2 & 4) != 0) {

      puVar2[10] = puVar2[2];

      puVar2[0xb] = puVar2[3];

      puVar2[0xc] = puVar2[4];

      puVar2[0xd] = puVar2[5];

      puVar2[6] = puVar2[2];

      puVar2[7] = puVar2[3];

      puVar2[8] = puVar2[4];

      puVar2[9] = puVar2[5];

      *puVar2 = *puVar2 | 4;

    }

    puVar2[0x16] = 0x3f800000;

    puVar2[0x14] = 0x5f7fffff;

    *(undefined4 *)(param_1 + 0xf4) = 1;

    *puVar2 = *puVar2 & 0xfffffffd | 1;

  }

  *puVar2 = *puVar2 & 0xfffffffd;

  return;

}

/* ===== FUN_0046fc80 @ 0x0046FC80 ===== */
void FUN_0046fc80(int param_1,uint *param_2)



{

  uint *puVar1;

  uint *puVar2;

  uint *puVar3;

  int iVar4;

  undefined4 *puVar5;

  int iVar6;

  uint local_10 [4];

  

  local_10[0] = *param_2;

  local_10[1] = param_2[1];

  local_10[2] = param_2[2];

  puVar2 = *(uint **)(param_1 + 0x100);

  local_10[3] = param_2[3];

  FUN_0046f7f0(local_10);

  *puVar2 = *puVar2 | 0xc;

  puVar2[2] = local_10[0];

  puVar2[3] = local_10[1];

  puVar2[4] = local_10[2];

  puVar2[5] = local_10[3];

  puVar2[6] = local_10[0];

  puVar2[7] = local_10[1];

  puVar2[8] = local_10[2];

  puVar2[9] = local_10[3];

  puVar2[10] = local_10[0];

  puVar2[0xb] = local_10[1];

  puVar2[0xc] = local_10[2];

  puVar2[0xd] = local_10[3];

  puVar3 = *(uint **)(param_1 + 0x100);

  if ((~*puVar3 & 1) != 0) {

    if (*(int *)(param_1 + 0xe8) == 0) {

      local_10[0] = 0;

      local_10[1] = 0;

      local_10[2] = 0;

      for (puVar5 = DAT_00632d68; puVar5 != (undefined4 *)0x0; puVar5 = (undefined4 *)*puVar5) {

        iVar6 = puVar5[3];

        if (((*(int *)(iVar6 + 0x1e0) == 0x5c) && (iVar4 = *(int *)(iVar6 + 0xe8), 0 < iVar4)) &&

           (iVar4 < 4)) {

          *(int *)(&stack0xffffffec + iVar4 * 4) = iVar6;

        }

      }

      iVar6 = 0;

      do {

        puVar1 = local_10 + iVar6;

        iVar6 = iVar6 + 1;

        if (*puVar1 == 0) goto LAB_0046fd76;

      } while (iVar6 < 3);

      iVar6 = 0;

LAB_0046fd76:

      *(int *)(param_1 + 0xe8) = iVar6;

    }

    puVar3[1] = 3;

    if ((~*puVar3 & 8) != 0) {

      puVar3[4] = 0x3f800000;

      puVar3[3] = 0x3f800000;

      puVar3[2] = 0x3f800000;

      *puVar3 = *puVar3 | 8;

    }

    if ((~*puVar3 & 4) != 0) {

      puVar3[10] = puVar3[2];

      puVar3[0xb] = puVar3[3];

      puVar3[0xc] = puVar3[4];

      puVar3[0xd] = puVar3[5];

      puVar3[6] = puVar3[2];

      puVar3[7] = puVar3[3];

      puVar3[8] = puVar3[4];

      puVar3[9] = puVar3[5];

      *puVar3 = *puVar3 | 4;

    }

    puVar3[0x16] = 0x3f800000;

    puVar3[0x14] = 0x5f7fffff;

    *(undefined4 *)(param_1 + 0xf4) = 1;

    *puVar3 = *puVar3 & 0xfffffffd | 1;

  }

  *puVar2 = *puVar2 & 0xfffffffd;

  return;

}

/* ===== FUN_0046fe30 @ 0x0046FE30 ===== */
void FUN_0046fe30(int param_1,uint *param_2)



{

  int *piVar1;

  uint *puVar2;

  uint *puVar3;

  int iVar4;

  undefined4 *puVar5;

  int iVar6;

  int local_c [3];

  

  puVar2 = *(uint **)(param_1 + 0x100);

  *puVar2 = *puVar2 | 8;

  puVar2[2] = *param_2;

  puVar2[3] = param_2[1];

  puVar2[4] = param_2[2];

  puVar2[5] = param_2[3];

  FUN_0046f7f0(puVar2 + 2);

  puVar3 = *(uint **)(param_1 + 0x100);

  if ((~*puVar3 & 1) != 0) {

    if (*(int *)(param_1 + 0xe8) == 0) {

      local_c[0] = 0;

      local_c[1] = 0;

      local_c[2] = 0;

      for (puVar5 = DAT_00632d68; puVar5 != (undefined4 *)0x0; puVar5 = (undefined4 *)*puVar5) {

        iVar6 = puVar5[3];

        if (((*(int *)(iVar6 + 0x1e0) == 0x5c) && (iVar4 = *(int *)(iVar6 + 0xe8), 0 < iVar4)) &&

           (iVar4 < 4)) {

          *(int *)(&stack0xfffffff0 + iVar4 * 4) = iVar6;

        }

      }

      iVar6 = 0;

      do {

        piVar1 = local_c + iVar6;

        iVar6 = iVar6 + 1;

        if (*piVar1 == 0) goto LAB_0046fee0;

      } while (iVar6 < 3);

      iVar6 = 0;

LAB_0046fee0:

      *(int *)(param_1 + 0xe8) = iVar6;

    }

    puVar3[1] = 3;

    if ((~*puVar3 & 8) != 0) {

      puVar3[4] = 0x3f800000;

      puVar3[3] = 0x3f800000;

      puVar3[2] = 0x3f800000;

      *puVar3 = *puVar3 | 8;

    }

    if ((~*puVar3 & 4) != 0) {

      puVar3[10] = puVar3[2];

      puVar3[0xb] = puVar3[3];

      puVar3[0xc] = puVar3[4];

      puVar3[0xd] = puVar3[5];

      puVar3[6] = puVar3[2];

      puVar3[7] = puVar3[3];

      puVar3[8] = puVar3[4];

      puVar3[9] = puVar3[5];

      *puVar3 = *puVar3 | 4;

    }

    puVar3[0x16] = 0x3f800000;

    puVar3[0x14] = 0x5f7fffff;

    *(undefined4 *)(param_1 + 0xf4) = 1;

    *puVar3 = *puVar3 & 0xfffffffd | 1;

  }

  *puVar2 = *puVar2 & 0xfffffffd;

  return;

}

/* ===== FUN_0046ff90 @ 0x0046FF90 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_0046ff90(uint param_1,int param_2)



{

  int *piVar1;

  uint *puVar2;

  int iVar3;

  undefined4 *puVar4;

  int iVar5;

  uint *puVar6;

  uint *puVar7;

  int local_74 [4];

  float local_64;

  float local_60;

  float local_5c;

  float local_58;

  float local_54;

  float local_50;

  float local_4c;

  float local_48;

  float local_44;

  float local_40;

  float local_3c;

  float local_38;

  

  puVar2 = *(uint **)(param_1 + 0x100);

  if ((~*puVar2 & 1) != 0) {

    if (*(int *)(param_1 + 0xe8) == 0) {

      local_74[0] = 0;

      local_74[1] = 0;

      local_74[2] = 0;

      for (puVar4 = DAT_00632d68; puVar4 != (undefined4 *)0x0; puVar4 = (undefined4 *)*puVar4) {

        iVar5 = puVar4[3];

        if (((*(int *)(iVar5 + 0x1e0) == 0x5c) && (iVar3 = *(int *)(iVar5 + 0xe8), 0 < iVar3)) &&

           (iVar3 < 4)) {

          *(int *)(&stack0xffffff88 + iVar3 * 4) = iVar5;

        }

      }

      iVar5 = 0;

      do {

        piVar1 = local_74 + iVar5;

        iVar5 = iVar5 + 1;

        if (*piVar1 == 0) goto LAB_00470010;

      } while (iVar5 < 3);

      iVar5 = 0;

LAB_00470010:

      *(int *)(param_1 + 0xe8) = iVar5;

    }

    puVar2[1] = 3;

    if ((~*puVar2 & 8) != 0) {

      puVar2[4] = 0x3f800000;

      puVar2[3] = 0x3f800000;

      puVar2[2] = 0x3f800000;

      *puVar2 = *puVar2 | 8;

    }

    if ((~*puVar2 & 4) != 0) {

      puVar2[10] = puVar2[2];

      puVar2[0xb] = puVar2[3];

      puVar2[0xc] = puVar2[4];

      puVar2[0xd] = puVar2[5];

      puVar2[6] = puVar2[2];

      puVar2[7] = puVar2[3];

      puVar2[8] = puVar2[4];

      puVar2[9] = puVar2[5];

      *puVar2 = *puVar2 | 4;

    }

    puVar2[0x16] = 0x3f800000;

    puVar2[0x14] = 0x5f7fffff;

    *(undefined4 *)(param_1 + 0xf4) = 1;

    *puVar2 = *puVar2 & 0xfffffffd | 1;

  }

  if ((*(int *)(param_1 + 0xe8) != 0) && (((~*puVar2 & 2) != 0 || (param_2 != 0)))) {

    puVar2[0xe] = *(uint *)(param_1 + 0xa0);

    puVar2[0xf] = *(uint *)(param_1 + 0xa4);

    puVar2[0x10] = *(uint *)(param_1 + 0xa8);

    FUN_004a7440(param_1);

    puVar2[0x11] = (uint)-*(float *)(param_1 + 0x29c);

    puVar2[0x12] = (uint)-*(float *)(param_1 + 0x2ac);

    puVar2[0x13] = (uint)-*(float *)(param_1 + 700);

    puVar7 = (uint *)(local_74 + 3);

    puVar6 = puVar2;

    for (iVar5 = 0x1a; puVar6 = puVar6 + 1, iVar5 != 0; iVar5 = iVar5 + -1) {

      *puVar7 = *puVar6;

      puVar7 = puVar7 + 1;

    }

    local_64 = _DAT_006330b8 * local_64;

    local_60 = _DAT_006330b8 * local_60;

    local_5c = _DAT_006330b8 * local_5c;

    local_58 = _DAT_006330b8 * local_58;

    local_54 = _DAT_006330b8 * local_54;

    local_50 = _DAT_006330b8 * local_50;

    local_4c = _DAT_006330b8 * local_4c;

    local_48 = _DAT_006330b8 * local_48;

    local_44 = _DAT_006330b8 * local_44;

    local_40 = _DAT_006330b8 * local_40;

    local_3c = _DAT_006330b8 * local_3c;

    local_38 = _DAT_006330b8 * local_38;

    (**(code **)(DAT_00656420 + 0x5c))

              (DAT_00656420,*(int *)(param_1 + 0xe8) + -1,*(undefined4 *)(param_1 + 0xf4),

               local_74 + 3);

    if (*(int *)(param_1 + 0xe8) == 1) {

      DAT_006330b4 = -(uint)(*(int *)(param_1 + 0xf4) != 0) & param_1;

    }

    *puVar2 = *puVar2 | 2;

    puVar2[0x1b] = puVar2[0x1b] + 1;

  }

  return;

}

