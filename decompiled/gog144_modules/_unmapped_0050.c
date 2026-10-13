/* Giants 1.449 — module _unmapped_0050
 * 87 functions (19 named) — decompiled, names from PS2 symbols
 * Original source: C:\Giants\source\_unmapped_0050.c(pp) (assert-string evidence)
 */

/* ===== FUN_00500100 @ 0x00500100 ===== */
undefined4 FUN_00500100(int param_1,int param_2,int param_3)



{

  return *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x18) + param_2 * 0x24) + param_3 * 4);

}

/* ===== FUN_00500120 @ 0x00500120 ===== */
void FUN_00500120(float *param_1,int param_2,int param_3)



{

  if (DAT_00632bc0 != 0) {

    if (DAT_00632abc <= DAT_00632bcc[3]) {

      if (DAT_00632abc < *DAT_00632bcc) {

        DAT_00632abc = *DAT_00632bcc;

      }

    }

    else {

      DAT_00632abc = DAT_00632bcc[3];

    }

    if (DAT_00632ac0 <= DAT_00632bcc[4]) {

      if (DAT_00632ac0 < DAT_00632bcc[1]) {

        DAT_00632ac0 = DAT_00632bcc[1];

      }

    }

    else {

      DAT_00632ac0 = DAT_00632bcc[4];

    }

  }

  *param_1 = DAT_00632abc;

  param_1[1] = DAT_00632ac0;

  param_1[2] = (float)DAT_005dd21c;

  param_1[3] = (float)DAT_005dd220;

  param_1[4] = (float)DAT_005dd224;

  param_1[5] = *param_1 / (float)param_2;

  param_1[6] = param_1[1] / (float)param_3;

  return;

}

/* ===== status_subobj_init @ 0x00500220 ===== */
void status_subobj_init(int param_1)



{

  int *piVar1;

  int iVar2;

  uint uVar3;

  int iVar4;

  int iVar5;

  int *piVar6;

  int iVar7;

  undefined4 *local_4;

  

  piVar6 = *(int **)(param_1 + 0x10);

  iVar5 = *piVar6;

  while (iVar5 != 0) {

    if (((*(byte *)(piVar6 + 6) & 4) == 0) && (iVar5 = 0, 0 < *(int *)(param_1 + 4))) {

      do {

        iVar2 = *(int *)(*(int *)(param_1 + 8) + iVar5 * 4);

        iVar7 = 0;

        if (0 < *(int *)(iVar2 + 0x68)) {

          local_4 = (undefined4 *)(iVar2 + 0x74);

          do {

            iVar4 = FUN_00545650(*local_4,*piVar6);

            if (iVar4 == 0) {

              if ((*(byte *)(piVar6 + 6) & 1) != 0) {

                FUN_00542f27(&DAT_00657400,s_Warning__Duplicate_subobj_name_i_0057a680,*piVar6);

                FUN_0051ea20(&DAT_00657400);

              }

              uVar3 = piVar6[6];

              piVar6[0x13] = iVar5;

              piVar6[5] = iVar7;

              piVar6[6] = uVar3 | 1;

              if ((*(char *)*piVar6 != '@') && (*(char *)*piVar6 != '$')) {

                piVar6[6] = uVar3 | 3;

              }

            }

            iVar7 = iVar7 + 1;

            local_4 = local_4 + 0x14;

          } while (iVar7 < *(int *)(iVar2 + 0x68));

        }

        iVar5 = iVar5 + 1;

      } while (iVar5 < *(int *)(param_1 + 4));

    }

    piVar1 = piVar6 + 0x16;

    piVar6 = piVar6 + 0x16;

    iVar5 = *piVar1;

  }

  return;

}

/* ===== FUN_00500300 @ 0x00500300 ===== */
void FUN_00500300(int param_1)



{

  int *piVar1;

  float fVar2;

  int iVar3;

  float fVar4;

  float *pfVar5;

  int *piVar6;

  int iVar7;

  int iVar8;

  int iVar9;

  

  piVar6 = *(int **)(param_1 + 0x10);

  iVar8 = *piVar6;

  while (iVar8 != 0) {

    if ((*(byte *)(piVar6 + 6) & 1) != 0) {

      iVar3 = *(int *)(piVar6[0x13] * 4 + *(int *)(param_1 + 0xc));

      iVar8 = *(int *)(piVar6[0x13] * 4 + *(int *)(param_1 + 8)) + piVar6[5] * 0x50;

      iVar9 = *(int *)(iVar8 + 0x8c);

      iVar7 = *(int *)(iVar8 + 0x88) * 0x38;

      iVar8 = *(int *)(iVar3 + iVar7);

      piVar6[10] = iVar8;

      piVar6[7] = iVar8;

      iVar8 = *(int *)(iVar3 + 4 + iVar7);

      piVar6[0xb] = iVar8;

      piVar6[8] = iVar8;

      pfVar5 = (float *)(iVar3 + iVar7);

      for (; iVar9 != 0; iVar9 = iVar9 + -1) {

        fVar2 = *pfVar5;

        fVar4 = pfVar5[1];

        if (fVar2 < (float)piVar6[7]) {

          piVar6[7] = (int)fVar2;

        }

        if (fVar4 < (float)piVar6[8]) {

          piVar6[8] = (int)fVar4;

        }

        if ((float)piVar6[10] < fVar2) {

          piVar6[10] = (int)fVar2;

        }

        if ((float)piVar6[0xb] < fVar4) {

          piVar6[0xb] = (int)fVar4;

        }

        pfVar5 = pfVar5 + 0xe;

      }

    }

    piVar1 = piVar6 + 0x16;

    piVar6 = piVar6 + 0x16;

    iVar8 = *piVar1;

  }

  return;

}

/* ===== FUN_005003d0 @ 0x005003D0 ===== */
void FUN_005003d0(int param_1)



{

  int *piVar1;

  int iVar2;

  undefined4 *puVar3;

  int iVar4;

  float *pfVar5;

  int *piVar6;

  int *piVar7;

  float *pfVar8;

  float *pfVar9;

  

  puVar3 = *(undefined4 **)(param_1 + 0x18);

  piVar6 = (int *)*puVar3;

  if (piVar6 != (int *)0x0) {

    pfVar5 = (float *)(puVar3 + 3);

    do {

      iVar2 = *piVar6;

      piVar7 = piVar6;

      while (iVar2 != 0) {

        if ((*(byte *)(iVar2 + 0x18) & 5) != 0) {

          if (iVar2 == *piVar6) {

            pfVar8 = (float *)(iVar2 + 0x1c);

            pfVar9 = pfVar5;

            for (iVar4 = 6; iVar4 != 0; iVar4 = iVar4 + -1) {

              *pfVar9 = *pfVar8;

              pfVar8 = pfVar8 + 1;

              pfVar9 = pfVar9 + 1;

            }

          }

          else {

            if (*(float *)(iVar2 + 0x1c) < *pfVar5) {

              *pfVar5 = *(float *)(iVar2 + 0x1c);

            }

            if (*(float *)(iVar2 + 0x20) < pfVar5[1]) {

              pfVar5[1] = *(float *)(iVar2 + 0x20);

            }

            if (pfVar5[3] < *(float *)(iVar2 + 0x28)) {

              pfVar5[3] = *(float *)(iVar2 + 0x28);

            }

            if (pfVar5[4] < *(float *)(iVar2 + 0x2c)) {

              pfVar5[4] = *(float *)(iVar2 + 0x2c);

            }

          }

        }

        piVar1 = piVar7 + 1;

        piVar7 = piVar7 + 1;

        iVar2 = *piVar1;

      }

      piVar6 = (int *)puVar3[9];

      puVar3 = puVar3 + 9;

      pfVar5 = pfVar5 + 9;

    } while (piVar6 != (int *)0x0);

  }

  return;

}

/* ===== FUN_00500490 @ 0x00500490 ===== */
void FUN_00500490(int *param_1)



{

  int iVar1;

  int iVar2;

  int iVar3;

  undefined4 *puVar4;

  

  if (*param_1 != 0) {

    param_1[9] = DAT_00632e84;

    param_1[10] = DAT_00632e88;

    FUN_004fa1f0(param_1,0,0xffffffff);

    FUN_00500300(param_1);

    FUN_005003d0(param_1);

    iVar1 = param_1[9];

    puVar4 = *(undefined4 **)param_1[6];

    iVar2 = param_1[10];

    for (iVar3 = ((undefined4 *)param_1[6])[1]; iVar3 != 0; iVar3 = iVar3 + -1) {

      FUN_004fa380(param_1,*puVar4,0,0x3f800000,0x3f800000,(float)iVar1 * 0.5,(float)iVar2 * 0.5);

      puVar4 = puVar4 + 1;

    }

  }

  return;

}

/* ===== FUN_005007f0 @ 0x005007F0 ===== */
/* PS2 candidate: ButtonFakeValue__FPii (conf 0.7) */



void FUN_005007f0(undefined4 *param_1,undefined4 *param_2)



{

  if (DAT_00633020 != 0) {

    *param_1 = 0x3e3851ec;

    *param_2 = 0x3d8f5c29;

    return;

  }

  *param_1 = 0x3e3851ec;

  *param_2 = 0x3d4ccccd;

  return;

}

/* ===== FUN_00500830 @ 0x00500830 ===== */
void FUN_00500830(void)



{

  int iVar1;

  

  if ((DAT_00633044 != 0) && (iVar1 = main_status_00500520(&DAT_00632900), iVar1 != 0)) {

    if (DAT_00633020 == 0) {

      if (DAT_0063301c == 0) {

        return;

      }

      iVar1 = 0;

    }

    else {

      iVar1 = 1;

    }

    FUN_004fa520(&DAT_00632900,*(undefined4 *)(*(int *)(DAT_00632918 + 0xb4) + iVar1 * 4));

  }

  return;

}

/* ===== FUN_00500890 @ 0x00500890 ===== */
void FUN_00500890(int param_1)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  int iVar5;

  int iVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  int iVar11;

  int iVar12;

  int iVar13;

  undefined4 *puVar14;

  

  iVar11 = main_status_00500520(&DAT_00632900);

  if (iVar11 == 0) {

    return;

  }

  iVar11 = *(int *)(param_1 + 0x24);

  fVar9 = (float)iVar11;

  iVar5 = *(int *)(param_1 + 0x28);

  fVar8 = DAT_00632abc / fVar9;

  iVar12 = *(int *)(param_1 + 0x20);

  fVar7 = (float)iVar5;

  fVar10 = DAT_00632ac0 / fVar7;

  if (-1 < iVar12) {

    iVar13 = *(int *)(param_1 + 0x18);

    iVar6 = *(int *)(iVar12 * 4 + *(int *)(iVar13 + 0xfc));

    fVar1 = *(float *)(iVar6 + 0x28);

    fVar2 = *(float *)(iVar6 + 0x1c);

    puVar14 = *(undefined4 **)(iVar13 + 0xfc);

    fVar3 = *(float *)(iVar6 + 0x2c);

    fVar4 = *(float *)(iVar6 + 0x20);

    if (-1 < iVar12) {

      iVar13 = 1;

      puVar14 = puVar14 + iVar12;

      goto LAB_00500958;

    }

    for (iVar13 = *(int *)(iVar13 + 0x100); iVar13 != 0; iVar13 = iVar13 + -1) {

LAB_00500958:

      FUN_004fa380(param_1,*puVar14,0,0x3f800000,0x3f800000,

                   (fVar8 - (fVar1 - fVar2) / (float)(iVar11 * 2)) * fVar9,

                   (fVar10 - (fVar3 - fVar4) / (float)(iVar5 * 2)) * fVar7);

      puVar14 = puVar14 + 1;

    }

    if (iVar12 < 0) {

      puVar14 = *(undefined4 **)(*(int *)(param_1 + 0x18) + 0xfc);

      iVar11 = *(int *)(*(int *)(param_1 + 0x18) + 0x100);

      if (iVar11 == 0) goto LAB_005009d6;

    }

    else {

      puVar14 = (undefined4 *)(*(int *)(*(int *)(param_1 + 0x18) + 0xfc) + iVar12 * 4);

      iVar11 = 1;

    }

    do {

      FUN_004fa520(param_1,*puVar14);

      puVar14 = puVar14 + 1;

      iVar11 = iVar11 + -1;

    } while (iVar11 != 0);

  }

LAB_005009d6:

  iVar11 = *(int *)(param_1 + 0x24);

  puVar14 = *(undefined4 **)(*(int *)(param_1 + 0x18) + 0x90);

  iVar5 = *(int *)(param_1 + 0x28);

  for (iVar12 = *(int *)(*(int *)(param_1 + 0x18) + 0x94); iVar12 != 0; iVar12 = iVar12 + -1) {

    FUN_004fa380(param_1,*puVar14,0,0x3f800000,0x3f800000,(float)iVar11 * fVar8,

                 fVar10 * (float)iVar5);

    puVar14 = puVar14 + 1;

  }

  puVar14 = *(undefined4 **)(*(int *)(param_1 + 0x18) + 0x90);

  for (iVar11 = *(int *)(*(int *)(param_1 + 0x18) + 0x94); iVar11 != 0; iVar11 = iVar11 + -1) {

    FUN_004fa520(param_1,*puVar14);

    puVar14 = puVar14 + 1;

  }

  return;

}

/* ===== FUN_00500a60 @ 0x00500A60 ===== */
/* PS2 candidate: item_create_base_pickup (conf 0.338) */



void FUN_00500a60(undefined4 param_1,int param_2,int param_3,float param_4)



{

  float fVar1;

  undefined4 uVar2;

  undefined4 uVar3;

  undefined4 uVar4;

  undefined4 uVar5;

  int iVar6;

  int iVar7;

  undefined4 *puVar8;

  float fVar9;

  

  fVar9 = (float)param_3;

  fVar1 = *(float *)(param_2 + 0xa0);

  uVar2 = *(undefined4 *)(param_2 + 0xa4);

  uVar3 = *(undefined4 *)(param_2 + 0xa8);

  *(float *)(param_2 + 0xa0) = fVar9 * -4.0;

  uVar4 = *(undefined4 *)(param_2 + 200);

  uVar5 = *(undefined4 *)(param_2 + 0x184);

  *(float *)(param_2 + 0xa4) = fVar9 * 0.25;

  *(undefined4 *)(param_2 + 0xa8) = 0;

  *(undefined4 *)(param_2 + 200) = 0x42b40000;

  if (param_4 == 0.0) {

    *(float *)(param_2 + 0x184) = fVar9 * 0.1;

    if (0.9 < fVar9 * 0.1) {

      *(undefined4 *)(param_2 + 0x184) = 0x3f666666;

    }

  }

  else {

    *(float *)(param_2 + 0x184) = param_4;

  }

  FUN_004a7440(param_2);

  BinFileCreateWrite_2(param_2);

  if (*(int *)(param_2 + 8) != 0) {

    FUN_0049aa20(param_2);

    FUN_0042c3e0(param_2,1,0xffffffff);

    FUN_0042c3e0(param_2,6,0xffffffff);

  }

  object_list_update();

  for (puVar8 = DAT_00632d68; puVar8 != (undefined4 *)0x0; puVar8 = (undefined4 *)*puVar8) {

    iVar6 = puVar8[3];

    if ((*(uint *)(iVar6 + 0xd8) & 0x4000c000) == 0) {

      for (iVar7 = *(int *)(iVar6 + 0x210); iVar7 != 0; iVar7 = *(int *)(iVar7 + 0x210)) {

        if (iVar7 == param_2) {

          object_lock_logic(iVar6);

          BinFileCreateWrite_2(iVar6);

          if (*(int *)(iVar6 + 8) != 0) {

            FUN_0049aa20(iVar6);

            FUN_0042c3e0(iVar6,1,0xffffffff);

            FUN_0042c3e0(iVar6,6,0xffffffff);

          }

        }

      }

    }

  }

  *(float *)(param_2 + 0xa0) = fVar1;

  *(undefined4 *)(param_2 + 0xa4) = uVar2;

  *(undefined4 *)(param_2 + 0xa8) = uVar3;

  *(undefined4 *)(param_2 + 200) = uVar4;

  *(undefined4 *)(param_2 + 0x184) = uVar5;

  return;

}

/* ===== FUN_00500c00 @ 0x00500C00 ===== */
void FUN_00500c00(float param_1,float param_2,float param_3,undefined4 param_4)



{

  float10 fVar1;

  float10 fVar2;

  float10 fVar3;

  float10 fVar4;

  float local_ac;

  float local_a8;

  float local_a4;

  undefined4 local_a0;

  undefined4 local_9c;

  undefined4 local_98;

  float local_94;

  float local_90;

  float local_8c;

  undefined1 local_88 [68];

  undefined1 auStack_44 [4];

  undefined1 auStack_40 [64];

  

  local_a0 = 0;

  fVar1 = (float10)fcos((float10)param_2);

  local_9c = 0;

  local_98 = 0x3f800000;

  fVar2 = (float10)fsin((float10)param_2);

  fVar3 = (float10)fcos((float10)param_1);

  fVar4 = (float10)fsin((float10)param_1);

  local_94 = (float)(fVar3 * fVar1);

  local_90 = (float)(fVar4 * fVar1);

  local_8c = (float)fVar2;

  local_ac = (float)(fVar3 * fVar1 * (float10)param_3);

  local_a8 = (float)(fVar4 * fVar1 * (float10)param_3);

  local_a4 = (float)(fVar2 * (float10)param_3);

  FUN_0053e3d0();

  FUN_0053e430(param_4);

  FUN_0053dde0(local_88,&local_ac,&local_94,&local_a0);

  (*(code *)PTR_FUN_00580c1c)(local_88,local_88);

  FUN_0053e410(local_88);

  FUN_0053e3f0(local_88);

  FUN_0053d970(auStack_44,local_88);

  FUN_005162b0(auStack_40);

  return;

}

/* ===== FUN_00500cf0 @ 0x00500CF0 ===== */
void FUN_00500cf0(int param_1)



{

  int iVar1;

  bool bVar2;

  int iVar3;

  int iVar4;

  float *pfVar5;

  int *piVar6;

  float *pfVar7;

  int iVar8;

  

  piVar6 = *(int **)(DAT_00632918 + param_1 * 0x24);

  bVar2 = false;

  pfVar7 = DAT_00632bcc;

  for (iVar3 = *(int *)(DAT_00632918 + param_1 * 0x24 + 4); iVar3 != 0; iVar3 = iVar3 + -1) {

    iVar8 = *piVar6;

    iVar4 = *(int *)(iVar8 + 0x4c) * 4;

    iVar1 = *(int *)(iVar4 + DAT_00632908) + 0x74 + *(int *)(iVar8 + 0x14) * 0x50;

    if ((*(undefined **)(iVar8 + 4) == &DAT_004fe800) &&

       (iVar8 = *(int *)(iVar1 + 0x18), iVar8 != 0)) {

      pfVar5 = (float *)(*(int *)(iVar1 + 0x14) * 0x38 + *(int *)(iVar4 + DAT_0063290c) + 0x1c);

      do {

        if (bVar2) {

          if (*pfVar7 <= pfVar5[-1]) {

            if (pfVar7[3] < pfVar5[-1]) {

              pfVar7[3] = pfVar5[-1];

              pfVar7 = DAT_00632bcc;

            }

          }

          else {

            *pfVar7 = pfVar5[-1];

            pfVar7 = DAT_00632bcc;

          }

          if (*pfVar5 < pfVar7[1]) {

            pfVar7[1] = *pfVar5;

            pfVar7 = DAT_00632bcc;

          }

          else if (pfVar7[4] < *pfVar5) {

            pfVar7[4] = *pfVar5;

            pfVar7 = DAT_00632bcc;

          }

        }

        else {

          *pfVar7 = pfVar5[-1];

          DAT_00632bcc[3] = pfVar5[-1];

          DAT_00632bcc[1] = *pfVar5;

          DAT_00632bcc[4] = *pfVar5;

          bVar2 = true;

          pfVar7 = DAT_00632bcc;

        }

        pfVar5 = pfVar5 + 0xe;

        iVar8 = iVar8 + -1;

      } while (iVar8 != 0);

    }

    piVar6 = piVar6 + 1;

  }

  return;

}

/* ===== FUN_00500e20 @ 0x00500E20 ===== */
void FUN_00500e20(void)



{

  int iVar1;

  undefined4 *puVar2;

  int iVar3;

  

  iVar1 = main_status_00500520(&DAT_00632900);

  if (iVar1 == 0) {

    return;

  }

  if (DAT_00632a88 == 0) {

    return;

  }

  iVar1 = FUN_004a6160(DAT_00632a88);

  if (iVar1 == 0) {

    iVar1 = FUN_004a6180(DAT_00632a88);

    if (iVar1 != 0) {

      iVar1 = 2;

      if (DAT_00632ba8 != 0) {

        iVar1 = 0xe;

      }

      if (DAT_00632bc0 != 0) {

        if (DAT_00632bcc == (undefined *)0x0) {

          DAT_00632bcc = &DAT_005a865c;

          FUN_00500cf0(iVar1);

        }

        FUN_00500120(&DAT_0063292c,DAT_00632924,DAT_00632928);

        FUN_004fff10(&DAT_00632900,iVar1,0xffffffff);

      }

      goto LAB_00500f01;

    }

    iVar1 = FUN_004a61a0(DAT_00632a88);

    if (iVar1 == 0) {

      iVar1 = 0x11;

      goto LAB_00500f01;

    }

    iVar1 = 3;

  }

  else {

    iVar1 = 1;

  }

  if (DAT_00632ba8 != 0) {

    iVar1 = 0xe;

  }

LAB_00500f01:

  puVar2 = *(undefined4 **)(DAT_00632918 + iVar1 * 0x24);

  DAT_0063291c = iVar1;

  for (iVar3 = *(int *)(DAT_00632918 + iVar1 * 0x24 + 4); iVar3 != 0; iVar3 = iVar3 + -1) {

    FUN_004fa520(&DAT_00632900,*puVar2);

    puVar2 = puVar2 + 1;

  }

  return;

}

/* ===== AudioSetSpeakerConfig__F14SPEAKER_SYSTEM_5 @ 0x00500F40 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */



void AudioSetSpeakerConfig__F14SPEAKER_SYSTEM_5(undefined4 p0)



{

  _DAT_00562458 = p0;

  return;

}

/* ===== FUN_00500f50 @ 0x00500F50 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* PS2 candidate: ANM_DumpCluster_12 (conf 0.537) */



void FUN_00500f50(int param_1,int param_2)



{

  DAT_00562c08 = DAT_00562c08 | 2;

  _DAT_005624b8 = (float)param_1;

  _DAT_005624c0 = (float)-param_2;

  return;

}

/* ===== FUN_00500f80 @ 0x00500F80 ===== */
void FUN_00500f80(int param_1)



{

  int iVar1;

  

  if (param_1 != 0) {

    iVar1 = FUN_0052e480(param_1);

    if ((iVar1 != 0) && (*(int *)(param_1 + 4) == 2)) {

      FUN_00501170(param_1);

    }

  }

  return;

}

/* ===== FUN_00500fb0 @ 0x00500FB0 ===== */
/* PS2 candidate: team_count (conf 0.411) */



int FUN_00500fb0(int param_1)



{

  undefined4 *puVar1;

  int iVar2;

  

  if (param_1 == 0) {

    return 0;

  }

  if (*(int *)(param_1 + 0x170) == 0) {

    return 1;

  }

  iVar2 = 0;

  for (puVar1 = DAT_00632d6c; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {

    if ((-1 < (char)((uint)*(undefined4 *)(puVar1[3] + 0xd8) >> 8)) &&

       (*(int *)(puVar1[3] + 0x170) == *(int *)(param_1 + 0x170))) {

      iVar2 = iVar2 + 1;

    }

  }

  return iVar2;

}

/* ===== FUN_00501000 @ 0x00501000 ===== */
/* PS2 candidate: team_toggle (conf 0.354) */



void FUN_00501000(int param_1)



{

  int iVar1;

  

  if (param_1 != 0) {

    iVar1 = FUN_0052e480(param_1);

    if ((iVar1 != 0) && (*(int *)(param_1 + 4) == 2)) {

      FUN_00501670(param_1);

    }

  }

  return;

}

/* ===== FUN_00501030 @ 0x00501030 ===== */
void FUN_00501030(int param_1)



{

  if ((param_1 != 0) && (*(int *)(param_1 + 4) == 2)) {

    teammecc_setup_enemies__FP6OBJECTi();

    return;

  }

  return;

}

/* ===== FUN_00501050 @ 0x00501050 ===== */
void FUN_00501050(int param_1)



{

  if ((param_1 != 0) && (*(int *)(param_1 + 4) == 2)) {

    FUN_005025d0();

    return;

  }

  return;

}

/* ===== FUN_00501070 @ 0x00501070 ===== */
/* PS2 candidate: item_drop_curweap (conf 0.395) */



int FUN_00501070(int param_1)



{

  int *piVar1;

  

  piVar1 = *(int **)(param_1 + 0x170);

  if ((piVar1 != (int *)0x0) && (*piVar1 == 1)) {

    return piVar1[1];

  }

  return 0;

}

/* ===== FUN_00501090 @ 0x00501090 ===== */
undefined1 * FUN_00501090(void)



{

  int iVar1;

  float10 fVar2;

  

  if (DAT_00632a88 == 0) {

    return (undefined1 *)0x0;

  }

  iVar1 = *(int *)(DAT_00632a88 + 0x170);

  if (iVar1 == 0) {

    return (undefined1 *)0x0;

  }

  if (*(char *)(iVar1 + 0x34) == '\0') {

    return (undefined1 *)0x0;

  }

  if (*(float *)(iVar1 + 0x134) < 0.0) {

    *(undefined1 *)(iVar1 + 0x34) = 0;

    return (undefined1 *)0x0;

  }

  fVar2 = (float10)FUN_00518b70(0,0);

  *(float *)(iVar1 + 0x134) = (float)((float10)*(float *)(iVar1 + 0x134) - fVar2);

  return (undefined1 *)(iVar1 + 0x34);

}

/* ===== FUN_00501100 @ 0x00501100 ===== */
void FUN_00501100(char *param_1)



{

  char cVar1;

  char cVar2;

  int iVar3;

  int iVar4;

  

  if ((DAT_00632a88 != 0) && (iVar3 = *(int *)(DAT_00632a88 + 0x170), iVar3 != 0)) {

    cVar1 = *param_1;

    if (cVar1 == '-') {

      param_1 = param_1 + 1;

    }

    iVar4 = (iVar3 + 0x34) - (int)param_1;

    do {

      cVar2 = *param_1;

      param_1[iVar4] = cVar2;

      param_1 = param_1 + 1;

    } while (cVar2 != '\0');

    if ((cVar1 == '-') && (*(float *)(iVar3 + 0x134) < 0.0 != (*(float *)(iVar3 + 0x134) == 0.0))) {

      *(undefined4 *)(iVar3 + 0x134) = 0;

      return;

    }

    *(undefined4 *)(iVar3 + 0x134) = 0x40a00000;

  }

  return;

}

/* ===== FUN_00501170 @ 0x00501170 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_00501170(int param_1)



{

  undefined4 *puVar1;

  int iVar2;

  undefined4 *puVar3;

  

  if (((param_1 != 0) && (*(int *)(param_1 + 4) == 2)) &&

     (puVar3 = DAT_00632d70, *(int *)(param_1 + 0x170) != 0)) {

    while (puVar3 != (undefined4 *)0x0) {

      puVar1 = (undefined4 *)*puVar3;

      iVar2 = puVar3[3];

      puVar3 = puVar1;

      if (((-1 < (char)((uint)*(undefined4 *)(iVar2 + 0xd8) >> 8)) && (*(int *)(iVar2 + 4) == 2)) &&

         ((iVar2 != param_1 && (*(int *)(iVar2 + 0x170) == *(int *)(param_1 + 0x170))))) {

        FUN_00499200(iVar2);

      }

    }

    DAT_005a8834 = 0;

    DAT_005a8838 = 0;

    _DAT_005a883c = 0;

    _DAT_005a8840 = 0;

    *(undefined4 *)(*(int *)(param_1 + 0x170) + 4) = 0;

  }

  return;

}

/* ===== FUN_00501500 @ 0x00501500 ===== */
void FUN_00501500(int param_1)



{

  undefined4 *puVar1;

  int iVar2;

  undefined4 *puVar3;

  float10 fVar4;

  

  if (((param_1 != 0) && (*(int *)(param_1 + 4) == 2)) && (*(int *)(param_1 + 0x170) != 0)) {

    puVar1 = (undefined4 *)(param_1 + 0xa0);

    *(float *)(*(int *)(param_1 + 0x170) + 0x18) = *(float *)(param_1 + 0xa0) + 100000.0;

    puVar3 = DAT_00632d70;

    if (((*(int *)(param_1 + 4) == 2) && (iVar2 = *(int *)(param_1 + 0x170), iVar2 != 0)) &&

       (*(int *)(param_1 + 0x174) == 0)) {

      fVar4 = (float10)FUN_0050a610(puVar1,(undefined4 *)(iVar2 + 0x18));

      puVar3 = DAT_00632d70;

      if ((float10)*(float *)(DAT_00632ed8 + 0x1020) * (float10)*(float *)(DAT_00632ed8 + 0x1020) <

          fVar4) {

        *(undefined4 *)(iVar2 + 0x14) = *(undefined4 *)(param_1 + 200);

        *(undefined4 *)(iVar2 + 8) = *puVar1;

        *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(param_1 + 0xa4);

        *(undefined4 *)(iVar2 + 0x10) = *(undefined4 *)(param_1 + 0xa8);

        *(undefined4 *)(iVar2 + 0x18) = *puVar1;

        *(undefined4 *)(iVar2 + 0x1c) = *(undefined4 *)(param_1 + 0xa4);

        *(undefined4 *)(iVar2 + 0x20) = *(undefined4 *)(param_1 + 0xa8);

        puVar3 = DAT_00632d70;

      }

    }

    for (; puVar3 != (undefined4 *)0x0; puVar3 = (undefined4 *)*puVar3) {

      iVar2 = puVar3[3];

      if (((-1 < (char)((uint)*(undefined4 *)(iVar2 + 0xd8) >> 8)) &&

          (*(int *)(iVar2 + 0x170) == *(int *)(param_1 + 0x170))) &&

         (((*(int *)(iVar2 + 4) == 2 &&

           (((iVar2 != param_1 && (*(int *)(iVar2 + 0x210) == 0)) &&

            (*(int *)(iVar2 + 0xe4) != 0x12)))) &&

          (*(float *)(iVar2 + 0x278) < *(float *)(iVar2 + 0x1c0))))) {

        FUN_00502660(param_1,0,*(undefined4 *)(iVar2 + 0x174),iVar2 + 0xa0,iVar2 + 200);

        FUN_00499280(iVar2);

        FUN_00413820(iVar2);

        *(uint *)(iVar2 + 0xd8) = *(uint *)(iVar2 + 0xd8) | 0x10000000;

      }

    }

  }

  return;

}

/* ===== FUN_00501670 @ 0x00501670 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* PS2 candidate: teammecc_toggle (conf 0.339) */



void FUN_00501670(int param_1)



{

  undefined4 *puVar1;

  undefined4 *puVar2;

  int iVar3;

  

  if ((param_1 != 0) && (*(int *)(param_1 + 4) == 2)) {

    iVar3 = FUN_00500fb0(param_1);

    if (iVar3 + -1 < 4) {

      if (iVar3 < 5) {

        teammecc_create(param_1,1);

        return;

      }

      teammecc_create(param_1,4 - (iVar3 + -1));

      return;

    }

    if ((*(int *)(param_1 + 4) == 2) && (puVar2 = DAT_00632d70, *(int *)(param_1 + 0x170) != 0)) {

      while (puVar2 != (undefined4 *)0x0) {

        puVar1 = (undefined4 *)*puVar2;

        iVar3 = puVar2[3];

        puVar2 = puVar1;

        if ((((-1 < (char)((uint)*(undefined4 *)(iVar3 + 0xd8) >> 8)) && (*(int *)(iVar3 + 4) == 2))

            && (iVar3 != param_1)) && (*(int *)(iVar3 + 0x170) == *(int *)(param_1 + 0x170))) {

          FUN_00499200(iVar3);

        }

      }

      DAT_005a8834 = 0;

      DAT_005a8838 = 0;

      _DAT_005a883c = 0;

      _DAT_005a8840 = 0;

      *(undefined4 *)(*(int *)(param_1 + 0x170) + 4) = 0;

    }

  }

  return;

}

/* ===== teammecc_setup_enemies__FP6OBJECTi @ 0x00501740 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void teammecc_setup_enemies__FP6OBJECTi(int param_1)



{

  uint *puVar1;

  float fVar2;

  int iVar3;

  undefined4 uVar4;

  int iVar5;

  int *piVar6;

  float *pfVar7;

  int iVar8;

  uint uVar9;

  undefined4 *puVar10;

  int iVar11;

  uint uVar12;

  uint uVar13;

  undefined4 *puVar14;

  float10 fVar15;

  char *pcVar16;

  int local_1b0;

  int iStack_1ac;

  float *pfStack_1a4;

  int *piStack_1a0;

  float fStack_19c;

  int iStack_198;

  float fStack_194;

  uint uStack_190;

  int iStack_18c;

  float fStack_188;

  float fStack_184;

  int aiStack_180 [15];

  float afStack_144 [17];

  undefined1 auStack_100 [256];

  

  uVar9 = 0;

  if (param_1 == 0) {

    return;

  }

  if (*(int *)(param_1 + 4) != 2) {

    return;

  }

  iVar11 = *(int *)(param_1 + 0x100);

  if (((iVar11 != 0) && (iVar5 = *(int *)(iVar11 + 0x14), iVar5 != 0)) &&

     (((*(uint *)(iVar5 + 0xd8) & 0x4000c000) != 0 ||

      (*(float *)(iVar5 + 0x1c0) <= *(float *)(iVar5 + 0x278))))) {

    *(undefined4 *)(iVar11 + 0x14) = 0;

  }

  if (*(int *)(param_1 + 0x170) == 0) {

    return;

  }

  if (*(int *)(param_1 + 0x174) != 0) {

    return;

  }

  fVar15 = (float10)FUN_00518b70(0,0);

  _DAT_0057a774 = (float)((float10)_DAT_0057a774 - fVar15);

  iVar5 = *(int *)(param_1 + 0x170);

  if (0.0 < *(float *)(iVar5 + 0x24)) {

    fVar15 = (float10)FUN_00518b70(param_1,0);

    fVar15 = (float10)*(float *)(iVar5 + 0x24) - fVar15;

    *(float *)(iVar5 + 0x24) = (float)fVar15;

    if ((fVar15 < (float10)0.0 != (fVar15 == (float10)0.0)) &&

       (iVar3 = (*DAT_005dd358)(*(undefined4 *)(iVar11 + 0x1f8)), iVar3 == 0)) {

      switch(*(undefined4 *)(iVar11 + 0x1f0)) {

      case 1:

      case 4:

      case 6:

        iVar3 = FUN_004d5730(0x46);

        if (iVar3 < 10) {

          uVar4 = *(undefined4 *)(DAT_006330e4 + 0x50e0);

          pcVar16 = s_GOR_CT04_0057b720;

        }

        else if (iVar3 < 0x14) {

          uVar4 = *(undefined4 *)(DAT_006330e4 + 0x50e0);

          pcVar16 = s_REG_CT04_0057b714;

        }

        else if (iVar3 < 0x1e) {

          uVar4 = *(undefined4 *)(DAT_006330e4 + 0x50e0);

          pcVar16 = s_GOR_CT48_0057b708;

        }

        else if (iVar3 < 0x28) {

          uVar4 = *(undefined4 *)(DAT_006330e4 + 0x50e0);

          pcVar16 = s_GOR_CT51_0057b6fc;

        }

        else if (iVar3 < 0x32) {

          uVar4 = *(undefined4 *)(DAT_006330e4 + 0x50e0);

          pcVar16 = s_BAZ_CT64_0057b6f0;

        }

        else if (iVar3 < 0x3c) {

          uVar4 = *(undefined4 *)(DAT_006330e4 + 0x50e0);

          pcVar16 = s_GOR_CT64_0057b6e4;

        }

        else {

          uVar4 = *(undefined4 *)(DAT_006330e4 + 0x50e0);

          pcVar16 = s_REG_CT64_0057b6d8;

        }

        break;

      case 2:

        iVar3 = FUN_004d5730(100);

        if (iVar3 < 0x14) {

          uVar4 = *(undefined4 *)(DAT_006330e4 + 0x50e0);

          pcVar16 = s_GOR_CT06_0057b6cc;

        }

        else if (iVar3 < 0x28) {

          uVar4 = *(undefined4 *)(DAT_006330e4 + 0x50e0);

          pcVar16 = s_REG_CT06_0057b6c0;

        }

        else if (iVar3 < 0x3c) {

          uVar4 = *(undefined4 *)(DAT_006330e4 + 0x50e0);

          pcVar16 = s_GOR_CT57_0057b6b4;

        }

        else if (iVar3 < 0x50) {

          uVar4 = *(undefined4 *)(DAT_006330e4 + 0x50e0);

          pcVar16 = s_BAZ_CT57_0057b6a8;

        }

        else {

          uVar4 = *(undefined4 *)(DAT_006330e4 + 0x50e0);

          pcVar16 = s_REG_CT57_0057b69c;

        }

        break;

      default:

        goto switchD_00501829_caseD_3;

      }

      uVar4 = teammecc_clear_mode(pcVar16,uVar4,0);

      *(undefined4 *)(iVar11 + 0x1f8) = uVar4;

    }

  }

switchD_00501829_caseD_3:

  iVar11 = *(int *)(iVar5 + 0x30);

  local_1b0 = 0;

  if (((iVar11 != 0) && ((*(uint *)(iVar11 + 0xd8) & 0x4000c000) == 0)) &&

     (*(float *)(iVar11 + 0x278) < *(float *)(iVar11 + 0x1c0))) {

    local_1b0 = iVar11;

  }

  *(undefined4 *)(iVar5 + 0x30) = 0;

  iVar11 = 0;

  for (puVar10 = DAT_00632d70; puVar10 != (undefined4 *)0x0; puVar10 = (undefined4 *)*puVar10) {

    iStack_18c = puVar10[3];

    if (((((-1 < (char)((uint)*(undefined4 *)(iStack_18c + 0xd8) >> 8)) &&

          (*(int *)(iStack_18c + 0x170) == *(int *)(param_1 + 0x170))) &&

         ((*(int *)(iStack_18c + 4) == 2 &&

          ((iStack_18c != param_1 && (iVar11 = iVar11 + 1, *(int *)(iStack_18c + 0x210) == 0))))))

        && (*(int *)(iStack_18c + 0xe4) != 0x12)) &&

       (*(float *)(iStack_18c + 0x278) < *(float *)(iStack_18c + 0x1c0))) {

      (&DAT_005a8834)[uVar9] = iStack_18c;

      uVar9 = uVar9 + 1;

    }

  }

  DAT_005a86f8 = uVar9;

  *(int *)(iVar5 + 4) = iVar11;

  if (uVar9 != 0) {

    iVar11 = 0;

    if (0 < (int)uVar9) {

      iVar5 = 0;

      do {

        iStack_18c = (&DAT_005a8834)[iVar11];

        *(undefined4 *)(*(int *)(iStack_18c + 0x100) + 0x20) = 0;

        *(undefined4 *)((int)&DAT_005a8688 + iVar5) = *(undefined4 *)((int)&DAT_005a86fc + iVar5);

        iVar11 = iVar11 + 1;

        *(undefined4 *)((int)&DAT_005a868c + iVar5) = *(undefined4 *)((int)&DAT_005a8700 + iVar5);

        *(undefined4 *)((int)&DAT_005a8690 + iVar5) = *(undefined4 *)((int)&DAT_005a8704 + iVar5);

        iVar5 = iVar5 + 0xc;

      } while (iVar11 < (int)uVar9);

    }

    DAT_005a8800 = 0;

    if ((local_1b0 != 0) && (iVar11 = 0, 0 < (int)uVar9)) {

      do {

        if ((DAT_005a8800 & 1 << ((byte)iVar11 & 0x1f)) == 0) {

          iStack_18c = (&DAT_005a8834)[iVar11];

          if (iStack_18c == 0) break;

          iVar5 = *(int *)(iStack_18c + 0x100);

          if ((*(int *)(iVar5 + 0x14) == 0) &&

             (fVar2 = *(float *)(DAT_00632ed8 + 0xaec) + *(float *)(DAT_00632ed8 + 0xaec),

             fVar15 = (float10)FUN_0050a5e0(iStack_18c + 0xa0,local_1b0 + 0xa0),

             fVar15 <= (float10)fVar2 * (float10)fVar2)) {

            *(int *)(iVar5 + 0x14) = local_1b0;

            *(undefined4 *)(iVar5 + 0x2c) = 0x41a00000;

            *(uint *)(iVar5 + 0xec) = *(uint *)(iVar5 + 0xec) & 0xfffffff7 | 2;

            *(undefined4 *)(iStack_18c + 0xe4) = 0;

          }

        }

        iVar11 = iVar11 + 1;

      } while (iVar11 < (int)uVar9);

    }

    pfStack_1a4 = (float *)0x0;

    if (0 < (int)uVar9) {

      do {

        iVar11 = (&DAT_005a8834)[(int)pfStack_1a4];

        if (((DAT_005a8800 & 1 << ((byte)pfStack_1a4 & 0x1f)) == 0) &&

           (iVar5 = *(int *)(iVar11 + 0x100), (*(byte *)(iVar5 + 0xec) & 3) != 0)) {

          iVar3 = *(int *)(iVar5 + 0x14);

          if ((iVar3 != 0) &&

             (((*(uint *)(iVar3 + 0xd8) & 0x4000c000) != 0 ||

              (*(float *)(iVar3 + 0x1c0) <= *(float *)(iVar3 + 0x278))))) {

            if ((*(uint *)(iVar11 + 0xe0) & 0x80000) == 0) {

              if (_DAT_0057a774 < 0.0) {

                iVar3 = FUN_004d5730(100);

                if (iVar3 < 0x21) {

                  uVar4 = *(undefined4 *)(DAT_006330e4 + 0x50e0);

                  pcVar16 = s_REG_CT37_0057b620;

                }

                else if (iVar3 < 0x42) {

                  uVar4 = *(undefined4 *)(DAT_006330e4 + 0x50e0);

                  pcVar16 = s_REG_CT38_0057b614;

                }

                else {

                  uVar4 = *(undefined4 *)(DAT_006330e4 + 0x50e0);

                  pcVar16 = s_GORCT67_1_0057b608;

                }

                teammecc_clear_mode(pcVar16,uVar4,0);

                _DAT_0057a774 = 45.0;

              }

            }

            else {

              if (_DAT_0057a774 < 0.0) {

                iVar3 = FUN_004d5730(100);

                if (iVar3 < 5) {

                  uVar4 = *(undefined4 *)(DAT_006330e4 + 0x50e0);

                  pcVar16 = s_BAZ_CT65_0057b690;

                }

                else {

                  iVar3 = FUN_004d5730(0x5a);

                  if (iVar3 < 10) {

                    uVar4 = *(undefined4 *)(DAT_006330e4 + 0x50e0);

                    pcVar16 = s_BAZ_CT60_0057b684;

                  }

                  else if (iVar3 < 0x14) {

                    uVar4 = *(undefined4 *)(DAT_006330e4 + 0x50e0);

                    pcVar16 = s_BAZ_CT61_0057b678;

                  }

                  else if (iVar3 < 0x1e) {

                    uVar4 = *(undefined4 *)(DAT_006330e4 + 0x50e0);

                    pcVar16 = s_GOR_CT61_0057b66c;

                  }

                  else if (iVar3 < 0x28) {

                    uVar4 = *(undefined4 *)(DAT_006330e4 + 0x50e0);

                    pcVar16 = s_REG_CT61_0057b660;

                  }

                  else if (iVar3 < 0x32) {

                    uVar4 = *(undefined4 *)(DAT_006330e4 + 0x50e0);

                    pcVar16 = s_GOR_CT62_0057b654;

                  }

                  else if (iVar3 < 0x3c) {

                    uVar4 = *(undefined4 *)(DAT_006330e4 + 0x50e0);

                    pcVar16 = s_REG_CT62_0057b648;

                  }

                  else if (iVar3 < 0x46) {

                    uVar4 = *(undefined4 *)(DAT_006330e4 + 0x50e0);

                    pcVar16 = s_BAZ_CT63_0057b63c;

                  }

                  else if (iVar3 < 0x50) {

                    uVar4 = *(undefined4 *)(DAT_006330e4 + 0x50e0);

                    pcVar16 = s_BAZ_CT64_0057b6f0;

                  }

                  else {

                    uVar4 = *(undefined4 *)(DAT_006330e4 + 0x50e0);

                    pcVar16 = s_GOR_CT64_0057b6e4;

                  }

                }

                teammecc_clear_mode(pcVar16,uVar4,0);

                _DAT_0057a774 = 45.0;

              }

              uVar4 = FUN_0049a180(*(undefined4 *)(*(int *)(iVar5 + 0x14) + 0x1e0));

              uVar4 = TextGetPtrRandom(s_McChEnemyDead_0057b62c,uVar4);

              FUN_00542f27(auStack_100,uVar4);

              chat_insert_name((&PTR_DAT_0057a920)[*(int *)(iVar11 + 0x174)],auStack_100,5,0);

              *(uint *)(iVar11 + 0xe0) = *(uint *)(iVar11 + 0xe0) & 0xfff7ffff;

            }

            if (*(int *)(iVar5 + 0x118) != 0) {

              puVar1 = (uint *)(*(int *)(iVar5 + 0x118) + 0xd8);

              *puVar1 = *puVar1 | 0x40000000;

            }

            if ((*(uint *)(iVar5 + 0xec) & 5) == 0) {

              iVar3 = *(int *)(iVar11 + 0x100);

              *(undefined4 *)(iVar3 + 0x14) = 0;

              *(undefined4 *)(iVar3 + 0x2c) = 0;

              *(undefined4 *)(iVar11 + 0xec) = 0;

              *(undefined4 *)(iVar11 + 0xd4) = 0;

              if (*(int *)(iVar3 + 0x118) != 0) {

                puVar1 = (uint *)(*(int *)(iVar3 + 0x118) + 0xd8);

                *puVar1 = *puVar1 | 0x40000000;

              }

              *(uint *)(iVar3 + 0xec) = *(uint *)(iVar3 + 0xec) & 0xfffffff0;

              *(undefined4 *)(iVar11 + 0xe4) = 0;

            }

            else {

              *(uint *)(iVar5 + 0xec) = *(uint *)(iVar5 + 0xec) & 0xfffffffd;

              *(undefined4 *)(iVar11 + 0xec) = 0;

            }

            *(undefined4 *)(iVar5 + 0x14) = 0;

          }

          if ((*(int *)(iVar5 + 0x14) == 0) || (*(float *)(iVar5 + 0x2c) <= 0.0)) {

            uVar13 = 0;

            fStack_194 = 999999.0;

            iStack_198 = 0;

            fStack_19c = 0.0;

            piStack_1a0 = DAT_00632d6c;

            if (DAT_00632d6c != (int *)0x0) {

              do {

                iVar3 = piStack_1a0[3];

                if ((((*(uint *)(iVar3 + 0xd8) & 0x4000c000) == 0) &&

                    (*(int *)(iVar3 + 0x170) != *(int *)(param_1 + 0x170))) &&

                   (*(float *)(iVar3 + 0x278) < *(float *)(iVar3 + 0x1c0))) {

                  iVar8 = *(int *)(iVar3 + 4);

                  uVar4 = 0;

                  if (0x53 < iVar8) {

                    if (0x232 < iVar8) {

                      switch(iVar8) {

                      case 0x23b:

                        goto switchD_00501f1c_caseD_9;

                      case 0x23c:

                        goto switchD_00501f1c_caseD_49;

                      default:

                        goto switchD_00501f1c_caseD_4;

                      case 0x23e:

                      case 0x23f:

                        goto switchD_00501f1c_caseD_38;

                      }

                    }

                    if (iVar8 != 0x232) {

                      if (iVar8 == 0xd7) goto switchD_00501f1c_caseD_4d;

                      if (iVar8 != 0xe5) {

                        if (iVar8 == 0xe6) goto switchD_00501f1c_caseD_38;

                        goto switchD_00501f1c_caseD_4;

                      }

                    }

switchD_00501f1c_caseD_49:

                    uVar12 = 5;

                    goto LAB_00501f90;

                  }

                  if (iVar8 == 0x53) {

switchD_00501f1c_caseD_9:

                    uVar12 = 2;

                  }

                  else {

                    switch(iVar8) {

                    case 1:

                      uVar12 = 9;

                      uVar4 = 1;

                      break;

                    case 2:

                    case 3:

                      uVar12 = 9;

                      break;

                    default:

                      goto switchD_00501f1c_caseD_4;

                    case 8:

                      uVar12 = 1;

                      break;

                    case 9:

                    case 10:

                      goto switchD_00501f1c_caseD_9;

                    case 0x38:

switchD_00501f1c_caseD_38:

                      uVar12 = 6;

                      break;

                    case 0x49:

                      goto switchD_00501f1c_caseD_49;

                    case 0x4b:

                      uVar12 = 7;

                      uVar4 = 1;

                      break;

                    case 0x4d:

switchD_00501f1c_caseD_4d:

                      uVar12 = 7;

                    }

                  }

LAB_00501f90:

                  if (((uVar13 <= uVar12) &&

                      (fVar15 = (float10)FUN_0050a610(iVar3 + 0xa0,iVar11 + 0xa0),

                      fVar15 <= (float10)*(float *)(DAT_00632ed8 + 0xaec) *

                                (float10)*(float *)(DAT_00632ed8 + 0xaec))) &&

                     ((uVar12 != uVar13 || (fVar15 <= (float10)fStack_194)))) {

                    fStack_194 = (float)fVar15;

                    uVar13 = uVar12;

                    fStack_19c = (float)uVar4;

                    iStack_198 = iVar3;

                  }

                }

switchD_00501f1c_caseD_4:

                piStack_1a0 = (int *)*piStack_1a0;

              } while (piStack_1a0 != (int *)0x0);

              if (iStack_198 != 0) {

                *(int *)(iVar5 + 0x14) = iStack_198;

                *(float *)(iVar5 + 0x24) = fStack_19c;

                *(undefined4 *)(iVar5 + 0x2c) = 0x41000000;

                goto LAB_0050203c;

              }

            }

            *(undefined4 *)(iVar5 + 0x14) = 0;

            if (*(int *)(iVar5 + 0x118) != 0) {

              puVar1 = (uint *)(*(int *)(iVar5 + 0x118) + 0xd8);

              *puVar1 = *puVar1 | 0x40000000;

            }

          }

          else if ((*(byte *)(iVar5 + 0xec) & 2) == 0) {

            fVar15 = (float10)FUN_00518b70(iVar11,0);

            *(float *)(iVar5 + 0x2c) = (float)((float10)*(float *)(iVar5 + 0x2c) - fVar15);

          }

        }

LAB_0050203c:

        pfStack_1a4 = (float *)((int)pfStack_1a4 + 1);

      } while ((int)pfStack_1a4 < (int)uVar9);

    }

    iVar11 = 0;

    uStack_190 = uVar9;

    if (0 < (int)uVar9) {

      do {

        uVar13 = 1 << ((byte)iVar11 & 0x1f);

        if (((DAT_005a8800 & uVar13) == 0) &&

           (FUN_00502890(param_1,iVar11), (uVar13 & DAT_005a8800) != 0)) {

          uStack_190 = uStack_190 - 1;

        }

        iVar11 = iVar11 + 1;

      } while (iVar11 < (int)uVar9);

    }

    DAT_005a8804 = 0;

    _DAT_005a8814 = 0;

    DAT_005a8808 = 0;

    _DAT_005a8818 = 0;

    _DAT_005a880c = 0;

    _DAT_005a881c = 0;

    _DAT_005a8820 = 0;

    _DAT_005a8810 = 0;

    if (uStack_190 != 0) {

      fStack_19c = *(float *)(*(int *)(param_1 + 0x100) + 0x14);

      if (fStack_19c == 0.0) {

        fStack_19c = (float)param_1;

      }

      iStack_1ac = 0;

      local_1b0 = 0;

      pfStack_1a4 = (float *)&DAT_005a8734;

      do {

        if ((&DAT_005a8834)[iStack_1ac] == 0) break;

        if ((1 << ((byte)iStack_1ac & 0x1f) & DAT_005a8800) == 0) {

          iVar11 = *(int *)((&DAT_005a8834)[iStack_1ac] + 0x100);

          if ((*(byte *)(iVar11 + 0xec) & 4) == 0) break;

          puVar10 = DAT_00632d7c;

          if (0 < (int)uStack_190) {

            puVar14 = (undefined4 *)((int)aiStack_180 + local_1b0);

            for (uVar13 = uStack_190 & 0x3fffffff; uVar13 != 0; uVar13 = uVar13 - 1) {

              *puVar14 = 0;

              puVar14 = puVar14 + 1;

            }

            puVar14 = (undefined4 *)((int)afStack_144 + local_1b0 + 4);

            for (uVar13 = uStack_190 & 0x3fffffff; uVar13 != 0; uVar13 = uVar13 - 1) {

              *puVar14 = 0x461c4000;

              puVar14 = puVar14 + 1;

            }

          }

          for (; puVar10 != (undefined4 *)0x0; puVar10 = (undefined4 *)*puVar10) {

            iVar5 = puVar10[3];

            if (((((*(uint *)(iVar5 + 0xd8) & 0x4000c000) == 0) &&

                 (*(char *)(iVar5 + 0x1f7) != '\0')) && (*(float *)(iVar5 + 0x1f8) != 0.0)) &&

               (fVar15 = (float10)FUN_0050a5e0(iVar5 + 0xa0,iVar11 + 0xe0),

               fVar15 <= (float10)10000.0)) {

              uVar13 = 0;

              if (0 < (int)uStack_190) {

                pfVar7 = (float *)((int)afStack_144 + local_1b0 + 4);

                do {

                  if (fVar15 < (float10)*pfVar7) break;

                  uVar13 = uVar13 + 1;

                  pfVar7 = pfVar7 + 1;

                } while ((int)uVar13 < (int)uStack_190);

              }

              if (uVar13 != uStack_190) {

                iVar3 = uStack_190 - 1;

                if ((int)uVar13 < iVar3) {

                  iVar8 = iVar3 - uVar13;

                  iVar3 = (iVar3 + iStack_1ac * 4) * 4;

                  do {

                    *(undefined4 *)((int)aiStack_180 + iVar3) =

                         *(undefined4 *)((int)aiStack_180 + iVar3 + -4);

                    *(undefined4 *)((int)afStack_144 + iVar3 + 4) =

                         *(undefined4 *)((int)afStack_144 + iVar3);

                    iVar8 = iVar8 + -1;

                    iVar3 = iVar3 + -4;

                  } while (iVar8 != 0);

                }

                iVar3 = uVar13 + iStack_1ac * 4;

                afStack_144[iVar3 + 1] = (float)fVar15;

                aiStack_180[iVar3] = iVar5;

              }

            }

          }

          iVar11 = 0;

          piStack_1a0 = (int *)0x0;

          if (0 < (int)uStack_190) {

            piVar6 = (int *)((int)aiStack_180 + local_1b0);

            do {

              piStack_1a0 = (int *)iVar11;

              if (*piVar6 == 0) break;

              iVar11 = iVar11 + 1;

              piVar6 = piVar6 + 1;

              piStack_1a0 = (int *)iVar11;

            } while (iVar11 < (int)uStack_190);

          }

          fStack_194 = 0.0;

          iVar11 = local_1b0;

          pfVar7 = pfStack_1a4;

          if (0 < (int)piStack_1a0) {

            do {

              iVar5 = *(int *)((int)aiStack_180 + iVar11);

              fVar15 = (float10)FUN_0050a400((float *)(iVar5 + 0xa0),(int)fStack_19c + 0xa0);

              FUN_0050ae40((float)fVar15 + 180.0,&fStack_184,&fStack_188);

              fVar2 = *(float *)(iVar5 + 0x1f8) * *(float *)(iVar5 + 0xc4) +

                      *(float *)(param_1 + 0x154);

              pfVar7[-1] = fStack_184 * fVar2 + *(float *)(iVar5 + 0xa0);

              *pfVar7 = *(float *)(iVar5 + 0xa4) - fVar2 * fStack_188;

              pfVar7[1] = *(float *)(iVar5 + 0xa8);

              *(float *)(&DAT_005a86b8 + iVar11) = (float)fVar15;

              (&DAT_005a8824)[iStack_1ac * 4 + (int)fStack_194] = *(undefined1 *)(iVar5 + 0x1f7);

              fStack_194 = (float)((int)fStack_194 + 1);

              iVar11 = iVar11 + 4;

              pfVar7 = pfVar7 + 3;

            } while ((int)fStack_194 < (int)piStack_1a0);

          }

          *(int **)(&DAT_005a8814 + iStack_1ac * 4) = piStack_1a0;

        }

        pfStack_1a4 = pfStack_1a4 + 0xc;

        iStack_1ac = iStack_1ac + 1;

        local_1b0 = local_1b0 + 0x10;

      } while ((int)pfStack_1a4 < 0x5a87f4);

    }

    iVar11 = 0;

    if (0 < (int)uVar9) {

      do {

        if ((DAT_005a8800 & 1 << ((byte)iVar11 & 0x1f)) == 0) {

          FUN_005035c0(param_1,iVar11);

        }

        iVar11 = iVar11 + 1;

      } while (iVar11 < (int)uVar9);

    }

    iVar11 = 0;

    if (0 < (int)uVar9) {

      puVar10 = &DAT_005a86fc;

      do {

        uVar13 = 1 << ((byte)iVar11 & 0x1f);

        *(uint *)(iStack_18c + 0xe0) = *(uint *)(iStack_18c + 0xe0) & 0x7fffffff;

        if ((uVar13 & DAT_005a8800) == 0) {

          iVar5 = (&DAT_005a8834)[iVar11];

          DAT_005a8800 = DAT_005a8800 | uVar13;

          FUN_00502660(param_1,0,iVar11 + 1,puVar10,&fStack_188);

          fStack_19c = 1.0;

          fVar15 = (float10)FUN_0050a7c0(*(undefined4 *)(param_1 + 200),*(undefined4 *)(iVar5 + 200)

                                        );

          if ((float10)30.0 < ABS(fVar15)) {

            fStack_19c = 6.0;

          }

          fVar15 = (float10)FUN_00518b70(iVar5,0);

          fVar15 = (float10)*(float *)(iVar5 + 0xec) - fVar15 * (float10)fStack_19c;

          *(float *)(iVar5 + 0xec) = (float)fVar15;

          if (fVar15 <= (float10)0.0) {

            fVar15 = (float10)FUN_004d5780(*(float *)(param_1 + 200) - 30.0,

                                           *(float *)(param_1 + 200) + 30.0);

            (&DAT_005a87f0)[iVar11] = (float)fVar15;

            *(undefined4 *)(iVar5 + 0xe4) = 0;

            fVar15 = (float10)FUN_004d5780(0x41000000,0x41200000);

            *(float *)(iVar5 + 0xec) = (float)fVar15;

          }

          if ((DAT_005a8800 & uVar13) != 0) {

            *(uint *)(iStack_18c + 0xe0) = *(uint *)(iStack_18c + 0xe0) | 0x80000000;

          }

        }

        iVar11 = iVar11 + 1;

        puVar10 = puVar10 + 3;

      } while (iVar11 < (int)uVar9);

    }

    iVar11 = 0;

    if (0 < (int)uVar9) {

      do {

        FUN_00503970(param_1,iVar11);

        iVar11 = iVar11 + 1;

      } while (iVar11 < (int)uVar9);

    }

  }

  return;

}

/* ===== FUN_005025d0 @ 0x005025D0 ===== */
/* PS2 candidate: teammecc_leader_calc (conf 0.528) */



void FUN_005025d0(int param_1)



{

  undefined4 *puVar1;

  int iVar2;

  float10 fVar3;

  

  if ((((param_1 != 0) && (*(int *)(param_1 + 4) == 2)) &&

      (iVar2 = *(int *)(param_1 + 0x170), iVar2 != 0)) && (*(int *)(param_1 + 0x174) == 0)) {

    puVar1 = (undefined4 *)(param_1 + 0xa0);

    fVar3 = (float10)FUN_0050a610(puVar1,(undefined4 *)(iVar2 + 0x18));

    if ((float10)*(float *)(DAT_00632ed8 + 0x1020) * (float10)*(float *)(DAT_00632ed8 + 0x1020) <

        fVar3) {

      *(undefined4 *)(iVar2 + 0x14) = *(undefined4 *)(param_1 + 200);

      *(undefined4 *)(iVar2 + 8) = *puVar1;

      *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(param_1 + 0xa4);

      *(undefined4 *)(iVar2 + 0x10) = *(undefined4 *)(param_1 + 0xa8);

      *(undefined4 *)(iVar2 + 0x18) = *puVar1;

      *(undefined4 *)(iVar2 + 0x1c) = *(undefined4 *)(param_1 + 0xa4);

      *(undefined4 *)(iVar2 + 0x20) = *(undefined4 *)(param_1 + 0xa8);

    }

  }

  return;

}

/* ===== FUN_00502660 @ 0x00502660 ===== */
/* PS2 candidate: teammecc_get_wantloc_formation (conf 0.396) */



void FUN_00502660(float param_1,undefined4 param_2,float param_3,float *param_4,undefined4 *param_5)



{

  int iVar1;

  float fVar2;

  float *pfVar3;

  float local_4;

  

  pfVar3 = param_4;

  iVar1 = *(int *)((int)param_1 + 0x170);

  if (param_3 == 0.0) {

    *param_4 = *(float *)((int)param_1 + 0xa0);

    param_4[1] = *(float *)((int)param_1 + 0xa4);

    param_4[2] = *(float *)((int)param_1 + 0xa8);

    *param_5 = *(undefined4 *)((int)param_1 + 200);

  }

  fVar2 = (float)((int)((int)param_3 + 1U) >> 1);

  param_4 = (float *)(fVar2 * 8.0);

  param_1 = fVar2 * 5.0 + 4.0;

  if (((uint)param_3 & 1) != 0) {

    param_1 = -param_1;

  }

  if (2 < (int)param_3) {

    param_1 = param_1 * 1.4;

  }

  FUN_0050ae40(*(undefined4 *)(iVar1 + 0x14),&local_4,&param_3);

  *pfVar3 = local_4 * (float)param_4 + param_3 * param_1 + *(float *)(iVar1 + 8);

  pfVar3[1] = local_4 * param_1 + (*(float *)(iVar1 + 0xc) - param_3 * (float)param_4);

  pfVar3[2] = *(float *)(iVar1 + 0x10);

  *param_5 = *(undefined4 *)(iVar1 + 0x14);

  return;

}

/* ===== FUN_00502750 @ 0x00502750 ===== */
/* PS2 candidate: teammecc_get_new_wander_loc__FP6OBJECTiP3P3DffT2ffff (conf 0.434) */



void FUN_00502750(int param_1,float *param_2,undefined4 param_3,undefined4 param_4,

                 undefined4 param_5,float param_6,float param_7,undefined4 param_8,

                 undefined4 param_9)



{

  float *pfVar1;

  float fVar2;

  undefined4 *puVar3;

  int iVar4;

  float10 fVar5;

  float10 fVar6;

  int local_10;

  float local_8;

  float local_4;

  

  local_10 = 10;

  do {

    do {

      local_10 = local_10 + -1;

      if (local_10 == 0) {

        return;

      }

      fVar5 = (float10)FUN_004d5780(param_8,param_9);

      fVar6 = (float10)FUN_004d5780(param_3,param_4);

      FUN_0050ae40((float)fVar5,&local_8,&local_4);

      pfVar1 = (float *)(&DAT_005a86fc + param_1 * 3);

      *pfVar1 = local_8 * (float)fVar6 + *param_2;

      (&DAT_005a8700)[param_1 * 3] = param_2[1] - local_4 * (float)fVar6;

      (&DAT_005a8704)[param_1 * 3] = param_2[2];

      fVar5 = (float10)FUN_0050a5e0(pfVar1,param_5);

    } while ((fVar5 < (float10)param_6 * (float10)param_6) ||

            ((float10)param_7 * (float10)param_7 < fVar5));

    iVar4 = 0;

    if (0 < DAT_005a86f8) {

      puVar3 = &DAT_005a86fc;

      do {

        if ((param_1 != iVar4) &&

           (fVar2 = *(float *)(DAT_00632ed8 + 0xaf8), fVar5 = (float10)FUN_0050a5e0(pfVar1,puVar3),

           fVar5 < (float10)fVar2 * (float10)fVar2)) break;

        iVar4 = iVar4 + 1;

        puVar3 = puVar3 + 3;

      } while (iVar4 < DAT_005a86f8);

    }

    if (iVar4 == DAT_005a86f8) {

      return;

    }

  } while( true );

}

/* ===== FUN_00502890 @ 0x00502890 ===== */
/* PS2 candidate: teammecc_get_attackloc__FP6OBJECTi (conf 0.454) */



void FUN_00502890(float param_1,int param_2)



{

  undefined4 *puVar1;

  float *pfVar2;

  float fVar3;

  int iVar4;

  int iVar5;

  undefined4 uVar6;

  float fVar7;

  uint uVar8;

  byte bVar9;

  int iVar10;

  float10 fVar11;

  float10 fVar12;

  float local_40;

  float local_38;

  float local_34;

  float local_30;

  float local_2c;

  float local_28;

  float local_24;

  int local_20;

  uint local_1c;

  undefined4 local_18;

  undefined4 local_14;

  float local_10;

  float local_c;

  float local_8;

  undefined4 local_4;

  

  iVar4 = (&DAT_005a8834)[param_2];

  iVar10 = *(int *)(iVar4 + 0x100);

  iVar5 = *(int *)(iVar10 + 0x14);

  if ((*(byte *)(iVar10 + 0xec) & 3) == 0) {

    return;

  }

  bVar9 = (byte)param_2;

  if (iVar5 == 0) {

    DAT_005a8800 = DAT_005a8800 | 1 << (bVar9 & 0x1f);

    *(undefined4 *)(iVar4 + 0xe4) = 0;

    fVar11 = (float10)FUN_00518b70(iVar4,0);

    fVar11 = (float10)*(float *)(iVar4 + 0xec) - fVar11;

    *(float *)(iVar4 + 0xec) = (float)fVar11;

    if ((float10)0.0 < fVar11) {

      return;

    }

    fVar3 = *(float *)(DAT_00632ed8 + 0x101c);

    puVar1 = (undefined4 *)(DAT_00632ed8 + 0x101c);

    iVar10 = iVar10 + 0xe0;

    fVar11 = (float10)FUN_0050a610(iVar10,iVar4 + 0xa0);

    if ((float10)fVar3 * (float10)fVar3 < fVar11) {

      FUN_00502750(param_2,iVar10,0,*puVar1,iVar4 + 0xa0,*(undefined4 *)(DAT_00632ed8 + 0xae4),

                   *(undefined4 *)(DAT_00632ed8 + 0xae8),0,0x43b40000);

    }

    fVar11 = (float10)FUN_0050a400(iVar10,&DAT_005a86fc + param_2 * 3);

    (&DAT_005a87f0)[param_2] = (float)fVar11;

    fVar11 = (float10)FUN_004d5780(0x40800000,0x41200000);

    *(float *)(iVar4 + 0xec) = (float)fVar11;

    return;

  }

  local_2c = *(float *)((int)param_1 + 0x170);

  local_20 = *(int *)(iVar4 + 0x10);

  local_24 = (float)(*(uint *)(iVar10 + 0x24) & 1);

  local_1c = *(uint *)(iVar4 + 0x30) & 2;

  if (*(int *)(iVar4 + 0xe4) == 0) {

    iVar10 = FUN_00456050(iVar4);

    if (iVar10 == 0) {

      local_c = *(float *)(iVar4 + 0xa0);

      local_8 = *(float *)(iVar4 + 0xa4);

      local_4 = *(undefined4 *)(iVar4 + 0xa8);

    }

    else {

      FUN_004a76e0(iVar10,1,&local_c);

    }

    local_18 = *(undefined4 *)(iVar5 + 0xa0);

    local_14 = *(undefined4 *)(iVar5 + 0xa4);

    local_10 = *(float *)(iVar5 + 0xa8);

    if ((*(int *)(iVar5 + 0x1e0) != 0x17) ||

       (((iVar10 = *(int *)(iVar5 + 0xe4), iVar10 != 0x1f && (iVar10 != 0x22)) && (iVar10 != 0x3d)))

       ) {

      if ((*(int *)(iVar5 + 0x1e0) == 0x15) && (*(int *)(iVar5 + 0xe4) == 2)) {

        fVar3 = *(float *)(iVar5 + 0x1e8) * *(float *)(iVar5 + 0xc4) * 0.2;

      }

      else {

        fVar3 = *(float *)(iVar5 + 0x1e8) * *(float *)(iVar5 + 0xc4) * 0.5;

      }

      local_10 = fVar3 + local_10;

    }

    fVar11 = (float10)FUN_0050a490(&local_c,&local_18);

    *(float *)(iVar4 + 0xd4) = (float)fVar11;

    iVar10 = FUN_004d5730(100);

    *(uint *)(iVar4 + 0xe4) = (*(int *)(DAT_00632ed8 + 0x1050) < iVar10) + 1;

    fVar11 = (float10)FUN_004d5780(*(undefined4 *)(DAT_00632ed8 + 0x104c),

                                   *(undefined4 *)(DAT_00632ed8 + 0x1048));

    *(float *)(iVar4 + 0xec) = (float)fVar11;

    iVar10 = FUN_004d5730(100);

    if (iVar10 < 0x33) {

      uVar8 = *(uint *)(iVar4 + 0xe0) & 0xfffffffd;

    }

    else {

      uVar8 = *(uint *)(iVar4 + 0xe0) | 2;

    }

    *(uint *)(iVar4 + 0xe0) = uVar8;

  }

  local_40 = *(float *)(iVar5 + 0x1ec) * *(float *)(iVar5 + 0xc4);

  local_38 = local_40 + local_40;

  if (*(float *)(DAT_00632ed8 + 0x1034) < local_38) {

    local_38 = *(float *)(DAT_00632ed8 + 0x1034);

  }

  if (local_38 < *(float *)(DAT_00632ed8 + 0x1030)) {

    local_38 = *(float *)(DAT_00632ed8 + 0x1030);

  }

  param_1 = local_40 * 10.0;

  if (*(float *)(DAT_00632ed8 + 0x103c) < param_1) {

    param_1 = *(float *)(DAT_00632ed8 + 0x103c);

  }

  if (param_1 < *(float *)(DAT_00632ed8 + 0x1038)) {

    param_1 = *(float *)(DAT_00632ed8 + 0x1038);

  }

  local_40 = local_40 * 0.75;

  if (*(float *)(DAT_00632ed8 + 0x1044) < local_40) {

    local_40 = *(float *)(DAT_00632ed8 + 0x1044);

  }

  if (local_40 < *(float *)(DAT_00632ed8 + 0x1040)) {

    local_40 = *(float *)(DAT_00632ed8 + 0x1040);

  }

  puVar1 = (undefined4 *)(iVar4 + 0xa0);

  pfVar2 = (float *)(iVar5 + 0xa0);

  fVar11 = (float10)FUN_0050a400(pfVar2,puVar1);

  fVar3 = (float)fVar11;

  fVar11 = (float10)FUN_00518b70(iVar4,0);

  local_28 = (float)((float10)*(float *)(iVar4 + 0xec) - fVar11);

  *(float *)(iVar4 + 0xec) = local_28;

  switch(*(undefined4 *)(iVar4 + 0xe4)) {

  case 1:

    if ((*(byte *)(iVar4 + 0xe0) & 2) == 0) {

      fVar3 = fVar3 + 5.0;

    }

    else {

      fVar3 = fVar3 - 5.0;

    }

    FUN_0050ae40(fVar3,&local_34,&local_30);

    (&DAT_005a86fc)[param_2 * 3] = local_34 * local_38 + *pfVar2;

    (&DAT_005a8700)[param_2 * 3] = *(float *)(iVar5 + 0xa4) - local_30 * local_38;

    if (local_24 == 0.0) {

      fVar7 = 4.0;

    }

    else {

      fVar7 = 1.0;

    }

    (&DAT_005a8704)[param_2 * 3] =

         *(float *)(iVar5 + 0x1e8) * *(float *)(iVar5 + 0xc4) * fVar7 + *(float *)(iVar5 + 0xa8);

    (&DAT_005a87f0)[param_2] = fVar3 + 180.0;

    *(undefined4 *)(*(int *)(iVar4 + 0x100) + 0x20) = 3;

    DAT_005a8800 = DAT_005a8800 | 1 << (bVar9 & 0x1f);

    if (*(float *)(iVar4 + 0xec) < 0.0) {

      *(undefined4 *)(iVar4 + 0xe4) = 3;

      fVar11 = (float10)FUN_004d5780(0x3fc00000,0x40a00000);

      *(float *)(iVar4 + 0xec) = (float)fVar11;

      return;

    }

    break;

  case 2:

    if ((*(byte *)(iVar4 + 0xe0) & 2) == 0) {

      fVar3 = fVar3 + 5.0;

    }

    else {

      fVar3 = fVar3 - 5.0;

    }

    FUN_0050ae40(fVar3,&local_34,&local_30);

    (&DAT_005a86fc)[param_2 * 3] = local_34 * local_38 + *pfVar2;

    (&DAT_005a8700)[param_2 * 3] = *(float *)(iVar5 + 0xa4) - local_30 * local_38;

    (&DAT_005a8704)[param_2 * 3] = *(undefined4 *)(iVar5 + 0xa8);

    (&DAT_005a87f0)[param_2] = fVar3 + 180.0;

    *(undefined4 *)(*(int *)(iVar4 + 0x100) + 0x20) = 3;

    DAT_005a8800 = DAT_005a8800 | 1 << (bVar9 & 0x1f);

    FUN_00456090(iVar4);

    fVar11 = (float10)FUN_0050a5e0(puVar1,pfVar2);

    if ((*(float *)(iVar4 + 0xec) < 0.0) && (fVar11 < (float10)param_1 * (float10)param_1)) {

      *(undefined4 *)(iVar4 + 0xe4) = 4;

      fVar11 = (float10)FUN_004d5780(0x3f800000,0x41000000);

      *(float *)(iVar4 + 0xec) = (float)fVar11;

      fVar11 = (float10)FUN_004d5780(0x3f000000,0x3f800000);

      *(float *)((int)local_2c + 0x28) = (float)fVar11;

      return;

    }

    break;

  case 3:

    local_28 = (float)(param_2 * 0xc);

    (&DAT_005a86fc)[param_2 * 3] = *puVar1;

    (&DAT_005a8700)[param_2 * 3] = *(undefined4 *)(iVar4 + 0xa4);

    (&DAT_005a8704)[param_2 * 3] = *(undefined4 *)(iVar4 + 0xa8);

    if (local_24 == 0.0) {

      fVar7 = 4.0;

    }

    else {

      fVar7 = 1.0;

    }

    (&DAT_005a8704)[param_2 * 3] =

         *(float *)(iVar5 + 0x1e8) * *(float *)(iVar5 + 0xc4) * fVar7 + *(float *)(iVar5 + 0xa8);

    (&DAT_005a87f0)[param_2] = fVar3 + 180.0;

    *(undefined4 *)(*(int *)(iVar4 + 0x100) + 0x20) = 3;

    fVar11 = (float10)FUN_0050a5e0(puVar1,pfVar2);

    local_24 = (float)(SQRT(fVar11) * (float10)0.0033333334);

    FUN_0050ae40(*(undefined4 *)(iVar5 + 200),&local_28,&local_2c);

    local_4 = *(undefined4 *)(iVar5 + 0xa8);

    local_c = local_28 * *(float *)(iVar5 + 0x10c) * local_24 + *pfVar2;

    local_8 = *(float *)(iVar5 + 0xa4) - local_2c * *(float *)(iVar5 + 0x10c) * local_24;

    fVar12 = (float10)FUN_0050a400(puVar1,&local_c);

    (&DAT_005a87f0)[param_2] = (float)fVar12;

    DAT_005a8800 = DAT_005a8800 | 1 << (bVar9 & 0x1f);

    if (((*(float *)(iVar4 + 0xec) < 0.0) || (param_1 * param_1 < (float)fVar11)) ||

       ((float)fVar11 < local_40 * local_40)) {

      iVar10 = FUN_004d5730(100);

      if (0x50 < iVar10) {

        *(undefined4 *)(iVar4 + 0xe4) = 0;

        return;

      }

      *(undefined4 *)(iVar4 + 0xe4) = 1;

LAB_00502fdd:

      fVar11 = (float10)FUN_004d5780(*(undefined4 *)(DAT_00632ed8 + 0x104c),

                                     *(undefined4 *)(DAT_00632ed8 + 0x1048));

      *(float *)(iVar4 + 0xec) = (float)fVar11;

      return;

    }

    break;

  case 4:

  case 5:

  case 6:

    fVar11 = (float10)FUN_00518b70(iVar4,0);

    fVar11 = (float10)*(float *)((int)local_2c + 0x28) - fVar11;

    *(float *)((int)local_2c + 0x28) = (float)fVar11;

    if (fVar11 < (float10)0.0) {

      iVar10 = FUN_004d5730(100);

      if (iVar10 < 0x1e) {

        *(undefined4 *)(iVar4 + 0xe4) = 5;

      }

      else {

        *(uint *)(iVar4 + 0xe4) = (uint)(iVar10 < 0x3c) * 2 + 4;

      }

      fVar11 = (float10)FUN_004d5780(0x3f000000,0x3f800000);

      *(float *)((int)local_2c + 0x28) = (float)fVar11;

    }

    (&DAT_005a86fc)[param_2 * 3] = *puVar1;

    (&DAT_005a8700)[param_2 * 3] = *(undefined4 *)(iVar4 + 0xa4);

    uVar6 = *(undefined4 *)(iVar4 + 0xa8);

    (&DAT_005a87f0)[param_2] = fVar3 + 180.0;

    (&DAT_005a8704)[param_2 * 3] = uVar6;

    *(undefined4 *)(*(int *)(iVar4 + 0x100) + 0x20) = 3;

    fVar11 = (float10)FUN_0050a5e0(puVar1,pfVar2);

    local_24 = (float)(SQRT(fVar11) * (float10)0.0033333334);

    FUN_0050ae40(*(undefined4 *)(iVar5 + 200),&local_28,&local_2c);

    local_4 = *(undefined4 *)(iVar5 + 0xa8);

    local_c = local_28 * *(float *)(iVar5 + 0x10c) * local_24 + *pfVar2;

    local_8 = *(float *)(iVar5 + 0xa4) - local_2c * *(float *)(iVar5 + 0x10c) * local_24;

    fVar12 = (float10)FUN_0050a400(puVar1,&local_c);

    (&DAT_005a87f0)[param_2] = (float)fVar12;

    DAT_005a8800 = DAT_005a8800 | 1 << (bVar9 & 0x1f);

    if (((*(float *)(iVar4 + 0xec) < 0.0) || (param_1 * param_1 < (float)fVar11)) ||

       ((float)fVar11 < local_40 * local_40)) {

      iVar10 = FUN_004d5730(100);

      if (0x50 < iVar10) {

        *(undefined4 *)(iVar4 + 0xe4) = 0;

        return;

      }

      *(undefined4 *)(iVar4 + 0xe4) = 2;

      goto LAB_00502fdd;

    }

    break;

  case 7:

    (&DAT_005a86fc)[param_2 * 3] = *puVar1;

    (&DAT_005a8700)[param_2 * 3] = *(undefined4 *)(iVar4 + 0xa4);

    (&DAT_005a8704)[param_2 * 3] = *(undefined4 *)(iVar4 + 0xa8);

    (&DAT_005a87f0)[param_2] = *(undefined4 *)(iVar4 + 200);

    *(undefined4 *)(*(int *)(iVar4 + 0x100) + 0x20) = 3;

    goto LAB_00503425;

  case 8:

    (&DAT_005a86fc)[param_2 * 3] = *puVar1;

    (&DAT_005a8700)[param_2 * 3] = *(undefined4 *)(iVar4 + 0xa4);

    uVar6 = *(undefined4 *)(iVar4 + 0xa8);

    (&DAT_005a87f0)[param_2] = fVar3 + 180.0;

    (&DAT_005a8704)[param_2 * 3] = uVar6;

    *(undefined4 *)(*(int *)(iVar4 + 0x100) + 0x20) = 3;

    fVar11 = (float10)FUN_0050a5e0(puVar1,pfVar2);

    DAT_005a8800 = DAT_005a8800 | 1 << (bVar9 & 0x1f);

    if ((*(float *)(iVar4 + 0xec) < 0.0) || ((float10)param_1 * (float10)param_1 < fVar11)) {

      *(undefined4 *)(iVar4 + 0xe4) = 9;

      return;

    }

    if (fVar11 < (float10)local_40 * (float10)local_40) {

      *(undefined4 *)(iVar4 + 0xe4) = 9;

      return;

    }

    break;

  case 9:

  case 0xd:

    (&DAT_005a86fc)[param_2 * 3] = *puVar1;

    (&DAT_005a8700)[param_2 * 3] = *(undefined4 *)(iVar4 + 0xa4);

    uVar6 = *(undefined4 *)(iVar4 + 0xa8);

    (&DAT_005a87f0)[param_2] = fVar3 + 180.0;

    (&DAT_005a8704)[param_2 * 3] = uVar6;

    *(undefined4 *)(*(int *)(iVar4 + 0x100) + 0x20) = 3;

LAB_00503425:

    DAT_005a8800 = DAT_005a8800 | 1 << (bVar9 & 0x1f);

    return;

  case 10:

  case 0xe:

    (&DAT_005a86fc)[param_2 * 3] = *puVar1;

    (&DAT_005a8700)[param_2 * 3] = *(undefined4 *)(iVar4 + 0xa4);

    uVar6 = *(undefined4 *)(iVar4 + 0xa8);

    (&DAT_005a87f0)[param_2] = fVar3 + 180.0;

    (&DAT_005a8704)[param_2 * 3] = uVar6;

    *(undefined4 *)(*(int *)(iVar4 + 0x100) + 0x20) = 3;

    DAT_005a8800 = DAT_005a8800 | 1 << (bVar9 & 0x1f);

    iVar10 = FUN_004d5730(100);

    if (iVar10 < 0x51) {

      *(undefined4 *)(iVar4 + 0xe4) = 2;

LAB_00503502:

      fVar11 = (float10)FUN_004d5780(0x3f800000,0x40800000);

      *(float *)(iVar4 + 0xec) = (float)fVar11;

      return;

    }

  default:

    *(undefined4 *)(iVar4 + 0xe4) = 0;

    return;

  case 0xb:

  case 0xc:

    (&DAT_005a86fc)[param_2 * 3] = *puVar1;

    (&DAT_005a8700)[param_2 * 3] = *(undefined4 *)(iVar4 + 0xa4);

    uVar6 = *(undefined4 *)(iVar4 + 0xa8);

    (&DAT_005a87f0)[param_2] = fVar3 + 180.0;

    (&DAT_005a8704)[param_2 * 3] = uVar6;

    *(undefined4 *)(*(int *)(iVar4 + 0x100) + 0x20) = 3;

    fVar11 = (float10)FUN_0050a5e0(puVar1,pfVar2);

    DAT_005a8800 = DAT_005a8800 | 1 << (bVar9 & 0x1f);

    if ((*(float *)(iVar4 + 0xec) < 0.0) || ((float10)param_1 * (float10)param_1 < fVar11)) {

      *(undefined4 *)(iVar4 + 0xe4) = 0xd;

      return;

    }

    if (fVar11 < (float10)local_40 * (float10)local_40) {

      *(undefined4 *)(iVar4 + 0xe4) = 0xd;

      return;

    }

    break;

  case 0xf:

    if (((local_28 < 0.0) && ((*(byte *)(iVar4 + 0xe0) & 4) != 0)) &&

       ((local_20 == 0x6a ||

        ((((local_20 == 0x7a || (local_20 == 0x5c)) || (local_20 == 0x6c)) ||

         ((local_20 == 0x7c || (local_20 == 0x5e)))))))) {

      iVar10 = FUN_004d5730(100);

      if (0x5a < iVar10) {

        *(undefined4 *)(iVar4 + 0xe4) = 2;

        fVar11 = (float10)FUN_004d5780(0x3f800000,0x40800000);

        *(float *)(iVar4 + 0xec) = (float)fVar11;

        return;

      }

      *(undefined4 *)(iVar4 + 0xe4) = 0x10;

      fVar11 = (float10)FUN_004d5780(0x3f800000,0x40800000);

      *(float *)(iVar4 + 0xec) = (float)fVar11;

      return;

    }

    break;

  case 0x10:

    if (local_1c != 0) {

      *(undefined4 *)(*(int *)(iVar4 + 0x100) + 0x18) = 0;

      *(undefined4 *)(iVar4 + 0xe4) = 0x11;

      goto LAB_00503502;

    }

    break;

  case 0x11:

    if (local_28 < 0.0) {

      *(undefined4 *)(iVar4 + 0xe4) = 0xf;

      fVar11 = (float10)FUN_004d5780(0x3f800000,0x40400000);

      *(float *)(iVar4 + 0xec) = (float)fVar11;

      mecc_animselect_gm(iVar4,1);

      return;

    }

  }

  return;

}

/* ===== FUN_005035c0 @ 0x005035C0 ===== */
/* PS2 candidate: teammecc_get_hideloc__FP6OBJECTi (conf 0.479) */



void FUN_005035c0(undefined4 param_1,int param_2)



{

  float *pfVar1;

  float fVar2;

  int iVar3;

  undefined4 uVar4;

  bool bVar5;

  int iVar6;

  undefined4 *puVar7;

  uint *puVar8;

  int iVar9;

  int iVar10;

  undefined4 *puVar11;

  float10 fVar12;

  int local_28;

  undefined4 *local_24;

  int local_18;

  int local_14;

  float local_c;

  float local_8;

  float local_4;

  

  iVar6 = param_2 * 4;

  iVar3 = (&DAT_005a8834)[param_2];

  iVar10 = *(int *)(iVar3 + 0x100);

  if ((*(byte *)(iVar10 + 0xec) & 4) != 0) {

    local_14 = -1;

    local_c = 999999.0;

    local_28 = 0;

    if (0 < *(int *)(&DAT_005a8814 + iVar6)) {

      local_24 = &DAT_005a8730 + param_2 * 0xc;

      do {

        bVar5 = false;

        local_18 = 0;

        puVar7 = &DAT_005a8730;

        puVar8 = &DAT_005a8804;

        do {

          if (local_18 != param_2) {

            iVar9 = 0;

            puVar11 = puVar7;

            do {

              if (((*puVar8 & 1 << ((byte)iVar9 & 0x1f)) != 0) &&

                 (fVar12 = (float10)FUN_0050a610(local_24,puVar11), fVar12 < (float10)9.0)) {

                bVar5 = true;

              }

              iVar9 = iVar9 + 1;

              puVar11 = puVar11 + 3;

            } while (iVar9 < 4);

          }

          local_18 = local_18 + 1;

          puVar8 = puVar8 + 1;

          puVar7 = puVar7 + 0xc;

        } while ((int)puVar8 < 0x5a8814);

        if ((!bVar5) && (((&DAT_005a8804)[param_2] & 1 << ((byte)local_28 & 0x1f)) == 0)) {

          fVar12 = (float10)FUN_0050a580(iVar3 + 0xa0,local_24);

          if (*(int *)(iVar10 + 0x1c) == local_28) {

            fVar12 = fVar12 - (float10)8.0;

          }

          if (fVar12 < (float10)local_c) {

            local_c = (float)fVar12;

            local_14 = local_28;

          }

        }

        local_28 = local_28 + 1;

        local_24 = local_24 + 3;

      } while (local_28 < *(int *)(&DAT_005a8814 + iVar6));

      if (local_14 != -1) {

        *(int *)(iVar10 + 0x1c) = local_14;

        (&DAT_005a8804)[param_2] = (&DAT_005a8804)[param_2] | 1 << ((byte)local_14 & 0x1f);

        if (((*(byte *)(iVar10 + 0xec) & 3) != 0) && (*(int *)(iVar3 + 0xe4) == 0)) {

          *(undefined4 *)(iVar3 + 0xe4) = 0xf;

        }

        local_14 = local_14 + iVar6;

        pfVar1 = (float *)(&DAT_005a86fc + param_2 * 3);

        *pfVar1 = (float)(&DAT_005a8730)[local_14 * 3];

        uVar4 = (&DAT_005a8738)[local_14 * 3];

        (&DAT_005a8700)[param_2 * 3] = (&DAT_005a8734)[local_14 * 3];

        (&DAT_005a8704)[param_2 * 3] = uVar4;

        (&DAT_005a87f0)[param_2] = *(undefined4 *)(&DAT_005a86b8 + local_14 * 4);

        if ((&DAT_005a8824)[local_14] == '\x01') {

          *(undefined4 *)(iVar10 + 0x20) = 5;

        }

        else {

          *(undefined4 *)(iVar10 + 0x20) = 4;

        }

        DAT_005a8800 = DAT_005a8800 | 1 << ((byte)param_2 & 0x1f);

        if (*(int *)(iVar3 + 0xe4) != 0x10) {

          return;

        }

        if ((&DAT_005a8824)[local_14] == '\x01') {

          return;

        }

        if ((*(byte *)(iVar3 + 0xe0) & 2) == 0) {

          fVar2 = (float)(&DAT_005a87f0)[param_2] - 90.0;

        }

        else {

          fVar2 = (float)(&DAT_005a87f0)[param_2] + 90.0;

        }

        FUN_0050ae40(fVar2,&local_8,&local_4);

        *pfVar1 = local_8 * 7.0 + *pfVar1;

        (&DAT_005a8700)[param_2 * 3] = (float)(&DAT_005a8700)[param_2 * 3] - local_4 * 7.0;

        return;

      }

    }

    DAT_005a8800 = DAT_005a8800 | 1 << ((byte)param_2 & 0x1f);

    *(undefined4 *)(iVar3 + 0xe4) = 0;

    fVar12 = (float10)FUN_00518b70(iVar3,0);

    fVar12 = (float10)*(float *)(iVar3 + 0xec) - fVar12;

    *(float *)(iVar3 + 0xec) = (float)fVar12;

    if (fVar12 <= (float10)0.0) {

      fVar2 = *(float *)(DAT_00632ed8 + 0x101c);

      puVar7 = (undefined4 *)(DAT_00632ed8 + 0x101c);

      iVar10 = iVar10 + 0xe0;

      fVar12 = (float10)FUN_0050a610(iVar10,iVar3 + 0xa0);

      if ((float10)fVar2 * (float10)fVar2 < fVar12) {

        FUN_00502750(param_2,iVar10,0,*puVar7,iVar3 + 0xa0,*(undefined4 *)(DAT_00632ed8 + 0xae4),

                     *(undefined4 *)(DAT_00632ed8 + 0xae8),0,0x43b40000);

      }

      fVar12 = (float10)FUN_0050a400(iVar10,&DAT_005a86fc + param_2 * 3);

      (&DAT_005a87f0)[param_2] = (float)fVar12;

      fVar12 = (float10)FUN_004d5780(0x40800000,0x41200000);

      *(float *)(iVar3 + 0xec) = (float)fVar12;

      return;

    }

  }

  return;

}

/* ===== FUN_00503970 @ 0x00503970 ===== */
/* PS2 candidate: teammecc_set_slave_goal__FP6OBJECTi (conf 0.497) */



void FUN_00503970(int param_1,int param_2)



{

  float fVar1;

  int iVar2;

  int iVar3;

  uint uVar4;

  int iVar5;

  float10 fVar6;

  undefined4 local_18;

  int local_14;

  int local_10;

  float local_c;

  float local_8;

  float local_4;

  

  iVar2 = (&DAT_005a8834)[param_2];

  if (*(float *)(iVar2 + 0x1c0) <= *(float *)(iVar2 + 0x278)) {

    FUN_004a7790(iVar2);

    return;

  }

  local_14 = *(int *)(iVar2 + 0x10);

  iVar3 = *(int *)(iVar2 + 0x100);

  *(float *)(iVar2 + 0x194) = *(float *)(DAT_00632ed8 + 0x6d8) * 1.2;

  uVar4 = *(uint *)(iVar2 + 0xe0);

  *(float *)(iVar2 + 400) = *(float *)(DAT_00632ed8 + 0x688) * 1.5;

  fVar1 = *(float *)(DAT_00632ed8 + 0x68c);

  *(undefined4 *)(iVar2 + 0x1a4) = 0x45e10000;

  *(undefined4 *)(iVar2 + 0x1ac) = 0x45e10000;

  *(float *)(iVar2 + 0x1a0) = fVar1 * 1.5;

  *(undefined4 *)(iVar2 + 0x1a8) = 0x44160000;

  *(undefined4 *)(iVar2 + 0x20c) = 0;

  *(uint *)(iVar2 + 0xe0) = uVar4 & 0xfffffff3;

  if (*(int *)(iVar2 + 0xe4) == 0x12) {

    return;

  }

  if (*(int *)(iVar3 + 0x30) == 0x2b) {

    return;

  }

  if ((uVar4 & 0x4000000) == 0) {

    if ((uVar4 & 0x2000000) == 0) {

      if ((*(uint *)(param_1 + 0xe0) & 0x2000000) != 0) {

        FUN_0047fff0(iVar2);

        *(undefined4 *)(iVar3 + 0x34) = 0;

      }

    }

    else if (0.0 < *(float *)(iVar3 + 0x34)) {

      fVar6 = (float10)FUN_00518b70(iVar2,0);

      fVar6 = (float10)*(float *)(iVar3 + 0x34) - fVar6;

      *(float *)(iVar3 + 0x34) = (float)fVar6;

      if (fVar6 < (float10)0.0) {

        FUN_00480150(iVar2);

      }

    }

    else if (((*(uint *)(param_1 + 0xe0) & 0x4000000) != 0) ||

            ((*(uint *)(param_1 + 0xe0) & 0x2000000) == 0)) {

      fVar6 = (float10)FUN_004d5760(0x3fc00000);

      *(float *)(iVar3 + 0x34) = (float)fVar6;

    }

  }

  local_18 = (&DAT_005a87f0)[param_2];

  local_c = (float)(&DAT_005a86fc)[param_2 * 3];

  local_8 = (float)(&DAT_005a8700)[param_2 * 3];

  local_4 = (float)(&DAT_005a8704)[param_2 * 3];

  FUN_00451560(&local_18);

  if ((((*(int *)(param_1 + 0x224) == 0) || (local_c != *(float *)(iVar2 + 0xa0))) ||

      (local_8 != *(float *)(iVar2 + 0xa4))) ||

     ((*(int *)(iVar2 + 0x224) == *(int *)(param_1 + 0x224) ||

      (local_4 - *(float *)(iVar2 + 0xa8) <= 5.0)))) {

    ai_fly_update_goal_2(iVar2,&local_c,local_18);

  }

  else {

    ai_fly_update_goal(iVar2,&local_c,local_18);

  }

  FUN_0050a7c0(local_18,*(undefined4 *)(iVar2 + 200));

  if (*(int *)(iVar2 + 0x168) == 0) {

    *(uint *)(iVar2 + 0xd8) = *(uint *)(iVar2 + 0xd8) & 0xfcffffff;

    *(undefined1 *)(iVar2 + 0x20a) = 0;

LAB_00503c98:

    *(undefined1 *)(iVar2 + 0x20b) = 0;

  }

  else {

    uVar4 = *(uint *)(iVar2 + 0x20c);

    local_10 = FUN_00402270(iVar2);

    *(uint *)(iVar2 + 0x20c) = *(uint *)(iVar2 + 0x20c) | uVar4;

    if (local_10 < 1) {

      fVar6 = (float10)FUN_0050a610((undefined4 *)(iVar2 + 0xa0),(undefined4 *)(iVar3 + 0x1c8));

      if ((float10)4.0 <= fVar6) {

        *(undefined4 *)(iVar3 + 0x1c8) = *(undefined4 *)(iVar2 + 0xa0);

        *(undefined4 *)(iVar3 + 0x1cc) = *(undefined4 *)(iVar2 + 0xa4);

        *(undefined4 *)(iVar3 + 0x1d0) = *(undefined4 *)(iVar2 + 0xa8);

      }

      else {

        fVar6 = (float10)FUN_00518b70(0,0);

        fVar6 = fVar6 + (float10)*(float *)(iVar3 + 0x1c4);

        *(float *)(iVar3 + 0x1c4) = (float)fVar6;

        if (fVar6 <= (float10)5.0) goto LAB_00503c4b;

        FUN_00401000(iVar2);

        FUN_004993c0(iVar2,&local_c);

      }

      *(undefined4 *)(iVar3 + 0x1c4) = 0;

    }

LAB_00503c4b:

    if (local_10 == -1) {

      main_ai_move_00401310(iVar2,&local_c,local_18);

      iVar5 = FUN_00402240(iVar2);

      if (iVar5 == -1) {

        *(undefined1 *)(iVar3 + 0x138) = 0x20;

        *(undefined1 *)(iVar2 + 0x20a) = 0x16;

        *(undefined1 *)(iVar2 + 0x208) = 3;

        goto LAB_00503c98;

      }

    }

  }

  iVar5 = FUN_00402170(iVar2);

  if (iVar5 != 0) {

    *(uint *)(iVar2 + 0xe0) = *(uint *)(iVar2 + 0xe0) | 4;

    iVar5 = FUN_004021e0(iVar2);

    if (iVar5 != 0) {

      *(uint *)(iVar2 + 0xe0) = *(uint *)(iVar2 + 0xe0) | 8;

    }

  }

  fVar6 = (float10)FUN_0050a5e0(iVar2 + 0xa0,&local_c);

  if (local_4 < *(float *)(iVar2 + 0x140)) {

    local_4 = *(float *)(iVar2 + 0x140);

  }

  if ((*(uint *)(param_1 + 0xd8) & 0x80000) != 0) {

    if (fVar6 <= (float10)90000.0) {

      if (fVar6 <= (float10)5625.0) {

        fVar1 = local_4 - *(float *)(iVar2 + 0x140);

        if (*(int *)(param_1 + 0x224) == 0) {

          if (fVar1 < 25.0) {

            local_4 = *(float *)(iVar2 + 0x140);

          }

        }

        else if (fVar1 < 5.0) {

          local_4 = *(float *)(iVar2 + 0x140);

        }

      }

      else {

        local_4 = local_4 + 10.0;

      }

    }

    else {

      local_4 = local_4 + 20.0;

    }

  }

  *(undefined1 *)(iVar3 + 0x138) = 0;

  if (local_4 == *(float *)(iVar2 + 0x140)) {

    *(undefined1 *)(iVar3 + 0x138) = 0;

  }

  else {

    FUN_0047f370(iVar2,local_4);

  }

  if ((*(uint *)(iVar3 + 0xec) & 3) == 0) {

    if ((((*(uint *)(iVar3 + 0xec) & 4) == 0) &&

        ((fVar6 = (float10)FUN_0050a7c0(*(undefined4 *)(iVar2 + 200),*(undefined4 *)(param_1 + 200))

         , ABS(fVar6) < (float10)50.0 || ((*(byte *)(iVar2 + 0xe0) & 4) != 0)))) &&

       (iVar5 = FUN_00458150(param_1), iVar5 != 0x13)) {

      if (((*(uint *)(param_1 + 0xdc) & 0x8000000) != 0) && (*(float *)(iVar3 + 0x28) == 0.0)) {

        fVar6 = (float10)FUN_004d5760(0x3e99999a);

        *(float *)(iVar3 + 0x28) = (float)fVar6;

      }

      if (0.0 < *(float *)(iVar3 + 0x28)) {

        fVar6 = (float10)FUN_00518b70(iVar2,0);

        fVar6 = (float10)*(float *)(iVar3 + 0x28) - fVar6;

        *(float *)(iVar3 + 0x28) = (float)fVar6;

        if (fVar6 < (float10)0.0 != (fVar6 == (float10)0.0)) {

          FUN_00504050(param_1,param_2);

          *(undefined4 *)(iVar3 + 0x28) = 0;

          return;

        }

      }

    }

  }

  else {

    iVar5 = *(int *)(iVar2 + 0xe4);

    if (iVar5 == 5) {

      *(undefined1 *)(iVar2 + 0x20b) = 0x10;

    }

    else if (iVar5 == 6) {

      *(undefined1 *)(iVar2 + 0x20b) = 0xf0;

    }

    if ((((iVar5 == 4) || (iVar5 == 3)) || (iVar5 == 5)) ||

       (((iVar5 == 6 || (iVar5 == 1)) || (iVar5 == 2)))) {

      fVar6 = (float10)FUN_00518b70(iVar2,0);

      *(float *)(iVar3 + 0x18) = (float)((float10)*(float *)(iVar3 + 0x18) - fVar6);

      fVar6 = (float10)FUN_0050a7c0(local_18,*(undefined4 *)(iVar2 + 200));

      if ((*(float *)(iVar3 + 0x18) < 0.0 != (*(float *)(iVar3 + 0x18) == 0.0)) &&

         (ABS(fVar6) < (float10)20.0)) {

LAB_00503e88:

        FUN_00504050(param_1,param_2);

        fVar6 = (float10)FUN_004d5780(*(undefined4 *)(DAT_00632ed8 + 0x10d8),

                                      *(undefined4 *)(DAT_00632ed8 + 0x10dc));

        *(float *)(iVar3 + 0x18) = (float)fVar6;

        return;

      }

    }

    else if (iVar5 == 0x11) {

      fVar6 = (float10)FUN_00518b70(iVar2,0);

      fVar6 = (float10)*(float *)(iVar3 + 0x18) - fVar6;

      *(float *)(iVar3 + 0x18) = (float)fVar6;

      if (((fVar6 < (float10)0.0 != (fVar6 == (float10)0.0)) && ((*(byte *)(iVar2 + 0xe0) & 8) != 0)

          ) && (fVar6 = (float10)FUN_0050a7c0(local_18,*(undefined4 *)(iVar2 + 200)),

               ABS(fVar6) < (float10)20.0)) goto LAB_00503e88;

    }

    else {

      if (((iVar5 == 8) && (((local_14 == 0x72 || (local_14 == 0x61)) || (local_14 == 0x62)))) &&

         ((*(byte *)(iVar2 + 0x30) & 2) != 0)) {

        FUN_00504050(param_1,param_2);

        return;

      }

      if ((iVar5 == 0xc) &&

         ((((local_14 == 0x76 || (local_14 == 0x66)) || (local_14 == 0x67)) &&

          ((*(byte *)(iVar2 + 0x30) & 2) != 0)))) {

        FUN_00504050(param_1,param_2);

        return;

      }

    }

  }

  return;

}

/* ===== FUN_00504050 @ 0x00504050 ===== */
/* PS2 candidate: mecc_set_fire__FP6OBJECTi (conf 0.339) */



void FUN_00504050(int param_1,int param_2)



{

  int iVar1;

  float fVar2;

  bool bVar3;

  int iVar4;

  int iVar5;

  float10 fVar6;

  undefined4 local_30;

  undefined4 local_2c;

  float local_28;

  undefined4 local_24;

  undefined4 local_20;

  float local_1c;

  undefined4 local_18;

  undefined4 local_14;

  float local_10;

  undefined4 local_c;

  undefined4 local_8;

  undefined4 local_4;

  

  iVar1 = (&DAT_005a8834)[param_2];

  iVar5 = *(int *)(*(int *)(iVar1 + 0x100) + 0x14);

  bVar3 = false;

  if (iVar5 == 0) {

    iVar5 = *(int *)(*(int *)(param_1 + 0x100) + 0x14);

    if (iVar5 != 0) {

      bVar3 = true;

      goto LAB_00504094;

    }

    *(undefined4 *)(iVar1 + 0xd4) = *(undefined4 *)(param_1 + 0xd4);

    fVar6 = (float10)*(float *)(param_1 + 200);

    (&DAT_005a87f0)[param_2] = *(float *)(param_1 + 200);

  }

  else {

LAB_00504094:

    local_18 = *(undefined4 *)(iVar1 + 0xa0);

    local_14 = *(undefined4 *)(iVar1 + 0xa4);

    local_10 = *(float *)(iVar1 + 0x1e8) * *(float *)(iVar1 + 0xc4) + *(float *)(iVar1 + 0xa8);

    local_24 = *(undefined4 *)(iVar5 + 0xa0);

    local_20 = *(undefined4 *)(iVar5 + 0xa4);

    local_1c = *(float *)(iVar5 + 0xc4) * *(float *)(iVar5 + 0x1e8) + *(float *)(iVar5 + 0xa8);

    iVar4 = FUN_004eed30(&local_18,&local_24);

    if (iVar4 == 0) {

      return;

    }

    iVar4 = FUN_00456050(iVar1);

    if (iVar4 == 0) {

      local_c = *(undefined4 *)(iVar1 + 0xa0);

      local_8 = *(undefined4 *)(iVar1 + 0xa4);

      local_4 = *(undefined4 *)(iVar1 + 0xa8);

    }

    else {

      FUN_004a76e0(iVar4,1,&local_c);

    }

    local_30 = *(undefined4 *)(iVar5 + 0xa0);

    local_2c = *(undefined4 *)(iVar5 + 0xa4);

    local_28 = *(float *)(iVar5 + 0xa8);

    if ((*(int *)(iVar5 + 0x1e0) != 0x17) ||

       (((iVar4 = *(int *)(iVar5 + 0xe4), iVar4 != 0x1f && (iVar4 != 0x22)) && (iVar4 != 0x3d)))) {

      if ((*(int *)(iVar5 + 0x1e0) == 0x15) && (*(int *)(iVar5 + 0xe4) == 2)) {

        fVar2 = *(float *)(iVar5 + 0xc4) * *(float *)(iVar5 + 0x1e8) * 0.2;

      }

      else {

        fVar2 = *(float *)(iVar5 + 0xc4) * *(float *)(iVar5 + 0x1e8) * 0.5;

      }

      local_28 = fVar2 + local_28;

    }

    fVar6 = (float10)FUN_0050a490(&local_c,&local_30);

    *(float *)(iVar1 + 0xd4) = (float)fVar6;

    if (!bVar3) goto LAB_00504212;

    fVar6 = (float10)FUN_0050a400(&local_c,&local_30);

    (&DAT_005a87f0)[param_2] = (float)fVar6;

  }

  *(float *)(iVar1 + 200) = (float)fVar6;

LAB_00504212:

  *(uint *)(iVar1 + 0x20c) = *(uint *)(iVar1 + 0x20c) | 1;

  return;

}

/* ===== mecc_smoking_fx_update @ 0x00504230 ===== */
void mecc_smoking_fx_update(int param_1)



{

  int iVar1;

  float fVar2;

  int iVar3;

  undefined4 uVar4;

  

  iVar1 = *(int *)(param_1 + 0x100);

  iVar3 = FUN_00498cd0(param_1);

  if (iVar3 != 0) {

    *(undefined4 *)(iVar1 + 0x1a4) = 0;

    if (*(int *)(iVar1 + 0x1a0) != 0) {

      FUN_00448920(*(int *)(iVar1 + 0x1a0));

      *(undefined4 *)(iVar1 + 0x1a0) = 0;

    }

  }

  fVar2 = (*(float *)(param_1 + 0x278) / *(float *)(param_1 + 0x1c0)) * 100.0;

  if (fVar2 < *(float *)(DAT_00632ed8 + 0x1070)) {

    if (fVar2 < *(float *)(DAT_00632ed8 + 0x106c)) {

      if (fVar2 < *(float *)(DAT_00632ed8 + 0x1074)) {

        iVar3 = 0;

      }

      else {

        iVar3 = 1;

      }

    }

    else {

      iVar3 = 2;

    }

  }

  else {

    iVar3 = 3;

  }

  if ((*(int *)(iVar1 + 0x1a4) != iVar3) && (*(int *)(iVar1 + 0x1a0) != 0)) {

    FUN_00448920(*(int *)(iVar1 + 0x1a0));

    *(undefined4 *)(iVar1 + 0x1a0) = 0;

  }

  *(int *)(iVar1 + 0x1a4) = iVar3;

  if ((*(int *)(iVar1 + 0x1a0) == 0) && (((iVar3 == 1 || (iVar3 == 2)) || (iVar3 == 3)))) {

    uVar4 = fx_get_free_effect__Fv();

    *(undefined4 *)(iVar1 + 0x1a0) = uVar4;

  }

  return;

}

/* ===== teammecc_clear_mode @ 0x00504930 ===== */
void teammecc_clear_mode(int param_1)



{

  uint *puVar1;

  int iVar2;

  

  iVar2 = *(int *)(param_1 + 0x100);

  *(undefined4 *)(iVar2 + 0x14) = 0;

  *(undefined4 *)(iVar2 + 0x2c) = 0;

  *(undefined4 *)(param_1 + 0xec) = 0;

  *(undefined4 *)(param_1 + 0xd4) = 0;

  if (*(int *)(iVar2 + 0x118) != 0) {

    puVar1 = (uint *)(*(int *)(iVar2 + 0x118) + 0xd8);

    *puVar1 = *puVar1 | 0x40000000;

  }

  *(uint *)(iVar2 + 0xec) = *(uint *)(iVar2 + 0xec) & 0xfffffff0;

  *(undefined4 *)(param_1 + 0xe4) = 0;

  return;

}

/* ===== teammecc_set_mode @ 0x00504980 ===== */
void teammecc_set_mode(int param_1,float param_2,int param_3)



{

  byte *pbVar1;

  char cVar2;

  char cVar3;

  int *piVar4;

  int iVar5;

  undefined4 *puVar6;

  bool bVar7;

  int iVar8;

  char *pcVar9;

  undefined4 uVar10;

  uint uVar11;

  int iVar12;

  int iVar13;

  float fVar14;

  float10 fVar15;

  int local_20;

  int local_1c;

  undefined4 local_c;

  undefined4 local_8;

  undefined4 local_4;

  

  fVar14 = 0.0;

  local_20 = 0;

  local_1c = 0;

  if (*(int *)(param_1 + 4) != 2) {

    return;

  }

  piVar4 = *(int **)(param_1 + 0x170);

  if ((piVar4 == (int *)0x0) || (*piVar4 != 1)) {

    if (param_3 == 0) {

      return;

    }

    pcVar9 = (char *)FUN_00507b00(s_AIMeccNone_0057b800);

    if (DAT_00632a88 == 0) {

      return;

    }

    iVar13 = *(int *)(DAT_00632a88 + 0x170);

    if (iVar13 == 0) {

      return;

    }

    cVar2 = *pcVar9;

    if (cVar2 == '-') {

      pcVar9 = pcVar9 + 1;

    }

    iVar8 = (iVar13 + 0x34) - (int)pcVar9;

    do {

      cVar3 = *pcVar9;

      pcVar9[iVar8] = cVar3;

      pcVar9 = pcVar9 + 1;

    } while (cVar3 != '\0');

    if ((cVar2 == '-') && (*(float *)(iVar13 + 0x134) < 0.0 != (*(float *)(iVar13 + 0x134) == 0.0)))

    {

      *(undefined4 *)(iVar13 + 0x134) = 0;

      return;

    }

  }

  else {

    iVar13 = *(int *)(param_1 + 0x100);

    bVar7 = false;

    if (param_2 == 1.4013e-45) {

      piVar4[0xb] = 0;

      iVar8 = AudioGetMasterVolume__Fv_11();

      if (piVar4[0xb] != 0) {

        return;

      }

      if (((((iVar8 == 0) ||

            (uVar11 = *(uint *)(iVar8 + 0xd8) & 0x4000c000,

            (~*(uint *)(iVar8 + 0x1c8) >> 0x11 & 1) != 0 || uVar11 != 0)) || (uVar11 != 0)) ||

          ((*(float *)(iVar8 + 0x1c0) <= *(float *)(iVar8 + 0x278) || (*(int *)(iVar8 + 0x18c) == 1)

           ))) || (*(char *)(iVar8 + 0x1f5) != '\0')) {

        iVar8 = FUN_00455890(&local_c,0x47435000,&param_2);

        if (iVar8 == 0) {

          return;

        }

        param_2 = *(float *)(DAT_00632ed8 + 0x1068);

        fVar15 = (float10)FUN_0050a610(param_1 + 0xa0,&local_c);

        if (fVar15 < (float10)param_2 * (float10)param_2) {

          bVar7 = true;

          for (puVar6 = DAT_00632d70; puVar6 != (undefined4 *)0x0; puVar6 = (undefined4 *)*puVar6) {

            iVar8 = puVar6[3];

            if (((((*(uint *)(iVar8 + 0xd8) & 0x8000) == 0) &&

                 (*(int *)(iVar8 + 0x170) == *(int *)(param_1 + 0x170))) &&

                ((*(int *)(iVar8 + 4) == 2 &&

                 (((iVar8 != param_1 &&

                   (local_20 = local_20 + 1, *(float *)(iVar8 + 0x278) < *(float *)(iVar8 + 0x1c0)))

                  && (local_1c = local_1c + 1, *(int *)(iVar8 + 0x210) == 0)))))) &&

               ((*(uint *)(iVar8 + 0xe0) & 0x2000000) == 0)) {

              iVar12 = *(int *)(iVar8 + 0x100);

              fVar14 = (float)((int)fVar14 + 1);

              *(undefined4 *)(iVar12 + 0x14) = 0;

              *(undefined4 *)(iVar12 + 0x2c) = 0;

              *(undefined4 *)(iVar8 + 0xec) = 0;

              *(undefined4 *)(iVar8 + 0xd4) = 0;

              *(undefined4 *)(iVar12 + 0xe0) = local_c;

              *(undefined4 *)(iVar12 + 0xe4) = local_8;

              *(undefined4 *)(iVar12 + 0xe8) = local_4;

              *(uint *)(iVar12 + 0xec) = *(uint *)(iVar12 + 0xec) & 0xfffffff1 | 1;

              *(undefined4 *)(iVar8 + 0xe4) = 0;

              param_2 = fVar14;

            }

          }

        }

        if (param_3 == 0) {

          return;

        }

        if (bVar7) {

          if (fVar14 != 0.0) {

            pcVar9 = (char *)FUN_00507b00(s_AIMeccAttackLoc_0057b7c0);

            if ((DAT_00632a88 != 0) && (iVar8 = *(int *)(DAT_00632a88 + 0x170), iVar8 != 0)) {

              cVar2 = *pcVar9;

              if (cVar2 == '-') {

                pcVar9 = pcVar9 + 1;

              }

              iVar12 = (iVar8 + 0x34) - (int)pcVar9;

              do {

                cVar3 = *pcVar9;

                pcVar9[iVar12] = cVar3;

                pcVar9 = pcVar9 + 1;

              } while (cVar3 != '\0');

              if ((cVar2 != '-') ||

                 (*(float *)(iVar8 + 0x134) < 0.0 == (*(float *)(iVar8 + 0x134) == 0.0))) {

                uVar10 = 0x40a00000;

              }

              else {

                uVar10 = 0;

              }

              *(undefined4 *)(iVar8 + 0x134) = uVar10;

            }

            if ((*(int *)(iVar13 + 0x1f0) != 1) && (*(int *)(iVar13 + 500) != 0)) {

              (*DAT_005dd354)(*(int *)(iVar13 + 500));

              *(undefined4 *)(iVar13 + 500) = 0;

            }

            iVar8 = (*DAT_005dd358)(*(undefined4 *)(iVar13 + 500));

            if (iVar8 == 0) {

              iVar8 = FUN_004d5730(100);

              if (iVar8 < 0x21) {

                uVar10 = *(undefined4 *)(DAT_006330e4 + 0x50e0);

                pcVar9 = s_GOR_CT01_0057b83c;

              }

              else if (iVar8 < 0x42) {

                uVar10 = *(undefined4 *)(DAT_006330e4 + 0x50e0);

                pcVar9 = s_REG_CT01_0057b830;

              }

              else {

                uVar10 = *(undefined4 *)(DAT_006330e4 + 0x50e0);

                pcVar9 = s_REG_CT51_0057b824;

              }

              uVar10 = teammecc_clear_mode(pcVar9,uVar10,0);

              *(undefined4 *)(iVar13 + 500) = uVar10;

            }

            *(undefined4 *)(iVar13 + 0x1f0) = 1;

            fVar15 = (float10)FUN_004d5780(0x3f800000,0x40400000);

            piVar4[9] = (int)(float)fVar15;

            return;

          }

          if ((local_20 == 0) || (local_1c == 0)) {

            pcVar9 = (char *)FUN_00507b00(s_AIMeccNone_0057b800);

            if (DAT_00632a88 == 0) {

              return;

            }

            iVar13 = *(int *)(DAT_00632a88 + 0x170);

            if (iVar13 == 0) {

              return;

            }

            cVar2 = *pcVar9;

            if (cVar2 == '-') {

              pcVar9 = pcVar9 + 1;

            }

            iVar8 = (iVar13 + 0x34) - (int)pcVar9;

            do {

              cVar3 = *pcVar9;

              pcVar9[iVar8] = cVar3;

              pcVar9 = pcVar9 + 1;

            } while (cVar3 != '\0');

            if ((cVar2 == '-') &&

               (*(float *)(iVar13 + 0x134) < 0.0 != (*(float *)(iVar13 + 0x134) == 0.0))) {

              *(undefined4 *)(iVar13 + 0x134) = 0;

              return;

            }

          }

          else {

            pcVar9 = (char *)FUN_00507b00(s_AIMeccBusy_0057b80c);

            if (DAT_00632a88 == 0) {

              return;

            }

            iVar13 = *(int *)(DAT_00632a88 + 0x170);

            if (iVar13 == 0) {

              return;

            }

            cVar2 = *pcVar9;

            if (cVar2 == '-') {

              pcVar9 = pcVar9 + 1;

            }

            iVar8 = (iVar13 + 0x34) - (int)pcVar9;

            do {

              cVar3 = *pcVar9;

              pcVar9[iVar8] = cVar3;

              pcVar9 = pcVar9 + 1;

            } while (cVar3 != '\0');

            if ((cVar2 == '-') &&

               (*(float *)(iVar13 + 0x134) < 0.0 != (*(float *)(iVar13 + 0x134) == 0.0))) {

              *(undefined4 *)(iVar13 + 0x134) = 0;

              return;

            }

          }

        }

        else {

          pcVar9 = (char *)FUN_00507b00(s_AIMeccRange_0057b848);

          if (DAT_00632a88 == 0) {

            return;

          }

          iVar13 = *(int *)(DAT_00632a88 + 0x170);

          if (iVar13 == 0) {

            return;

          }

          cVar2 = *pcVar9;

          if (cVar2 == '-') {

            pcVar9 = pcVar9 + 1;

          }

          iVar8 = (iVar13 + 0x34) - (int)pcVar9;

          do {

            cVar3 = *pcVar9;

            pcVar9[iVar8] = cVar3;

            pcVar9 = pcVar9 + 1;

          } while (cVar3 != '\0');

          if ((cVar2 == '-') &&

             (*(float *)(iVar13 + 0x134) < 0.0 != (*(float *)(iVar13 + 0x134) == 0.0))) {

            *(undefined4 *)(iVar13 + 0x134) = 0;

            return;

          }

        }

      }

      else {

        param_2 = *(float *)(DAT_00632ed8 + 0x1068);

        fVar15 = (float10)FUN_0050a610(param_1 + 0xa0,iVar8 + 0xa0);

        if (fVar15 < (float10)param_2 * (float10)param_2) {

          bVar7 = true;

          for (puVar6 = DAT_00632d70; puVar6 != (undefined4 *)0x0; puVar6 = (undefined4 *)*puVar6) {

            iVar12 = puVar6[3];

            if ((((-1 < (char)((uint)*(undefined4 *)(iVar12 + 0xd8) >> 8)) &&

                 (*(int *)(iVar12 + 0x170) == *(int *)(param_1 + 0x170))) &&

                (*(int *)(iVar12 + 4) == 2)) &&

               (((iVar12 != param_1 &&

                 (local_20 = local_20 + 1, *(float *)(iVar12 + 0x278) < *(float *)(iVar12 + 0x1c0)))

                && ((local_1c = local_1c + 1, *(int *)(iVar12 + 0x210) == 0 &&

                    ((*(uint *)(iVar12 + 0xe0) & 0x2000000) == 0)))))) {

              iVar5 = *(int *)(iVar12 + 0x100);

              fVar14 = (float)((int)fVar14 + 1);

              *(int *)(iVar5 + 0x14) = iVar8;

              *(undefined4 *)(iVar5 + 0xe0) = *(undefined4 *)(iVar8 + 0xa0);

              *(undefined4 *)(iVar5 + 0xe4) = *(undefined4 *)(iVar8 + 0xa4);

              *(undefined4 *)(iVar5 + 0xe8) = *(undefined4 *)(iVar8 + 0xa8);

              *(undefined4 *)(iVar5 + 0x2c) = 0x41a00000;

              *(undefined4 *)(iVar12 + 0xec) = 0;

              *(undefined4 *)(iVar12 + 0xd4) = 0;

              *(uint *)(iVar5 + 0xec) = *(uint *)(iVar5 + 0xec) & 0xfffffff2 | 2;

              *(undefined4 *)(iVar12 + 0xe4) = 0;

              param_2 = fVar14;

            }

          }

        }

        if (param_3 == 0) {

          return;

        }

        if (bVar7) {

          if (fVar14 != 0.0) {

            pcVar9 = (char *)FUN_00507b00(s_AIMeccAttackTarg_0057b7d0);

            if ((DAT_00632a88 != 0) && (iVar8 = *(int *)(DAT_00632a88 + 0x170), iVar8 != 0)) {

              cVar2 = *pcVar9;

              if (cVar2 == '-') {

                pcVar9 = pcVar9 + 1;

              }

              iVar12 = (iVar8 + 0x34) - (int)pcVar9;

              do {

                cVar3 = *pcVar9;

                pcVar9[iVar12] = cVar3;

                pcVar9 = pcVar9 + 1;

              } while (cVar3 != '\0');

              if ((cVar2 != '-') ||

                 (*(float *)(iVar8 + 0x134) < 0.0 == (*(float *)(iVar8 + 0x134) == 0.0))) {

                uVar10 = 0x40a00000;

              }

              else {

                uVar10 = 0;

              }

              *(undefined4 *)(iVar8 + 0x134) = uVar10;

            }

            fVar15 = (float10)FUN_004d5780(0x3f800000,0x40400000);

            piVar4[9] = (int)(float)fVar15;

            if ((*(int *)(iVar13 + 0x1f0) != 1) && (*(int *)(iVar13 + 500) != 0)) {

              (*DAT_005dd354)(*(int *)(iVar13 + 500));

              *(undefined4 *)(iVar13 + 500) = 0;

            }

            iVar8 = (*DAT_005dd358)(*(undefined4 *)(iVar13 + 500));

            if (iVar8 == 0) {

              iVar8 = FUN_004d5730(100);

              if (iVar8 < 0x21) {

                uVar10 = *(undefined4 *)(DAT_006330e4 + 0x50e0);

                pcVar9 = s_GOR_CT01_0057b83c;

              }

              else if (iVar8 < 0x42) {

                uVar10 = *(undefined4 *)(DAT_006330e4 + 0x50e0);

                pcVar9 = s_REG_CT01_0057b830;

              }

              else {

                uVar10 = *(undefined4 *)(DAT_006330e4 + 0x50e0);

                pcVar9 = s_REG_CT51_0057b824;

              }

              uVar10 = teammecc_clear_mode(pcVar9,uVar10,0);

              *(undefined4 *)(iVar13 + 500) = uVar10;

            }

            *(undefined4 *)(iVar13 + 0x1f0) = 1;

            return;

          }

          if ((local_20 == 0) || (local_1c == 0)) {

            pcVar9 = (char *)FUN_00507b00(s_AIMeccNone_0057b800);

            if (DAT_00632a88 == 0) {

              return;

            }

            iVar13 = *(int *)(DAT_00632a88 + 0x170);

            if (iVar13 == 0) {

              return;

            }

            cVar2 = *pcVar9;

            if (cVar2 == '-') {

              pcVar9 = pcVar9 + 1;

            }

            iVar8 = (iVar13 + 0x34) - (int)pcVar9;

            do {

              cVar3 = *pcVar9;

              pcVar9[iVar8] = cVar3;

              pcVar9 = pcVar9 + 1;

            } while (cVar3 != '\0');

            if ((cVar2 == '-') &&

               (*(float *)(iVar13 + 0x134) < 0.0 != (*(float *)(iVar13 + 0x134) == 0.0))) {

              *(undefined4 *)(iVar13 + 0x134) = 0;

              return;

            }

          }

          else {

            pcVar9 = (char *)FUN_00507b00(s_AIMeccBusy_0057b80c);

            if (DAT_00632a88 == 0) {

              return;

            }

            iVar13 = *(int *)(DAT_00632a88 + 0x170);

            if (iVar13 == 0) {

              return;

            }

            cVar2 = *pcVar9;

            if (cVar2 == '-') {

              pcVar9 = pcVar9 + 1;

            }

            iVar8 = (iVar13 + 0x34) - (int)pcVar9;

            do {

              cVar3 = *pcVar9;

              pcVar9[iVar8] = cVar3;

              pcVar9 = pcVar9 + 1;

            } while (cVar3 != '\0');

            if ((cVar2 == '-') &&

               (*(float *)(iVar13 + 0x134) < 0.0 != (*(float *)(iVar13 + 0x134) == 0.0))) {

              *(undefined4 *)(iVar13 + 0x134) = 0;

              return;

            }

          }

        }

        else {

          pcVar9 = (char *)FUN_00507b00(s_AIMeccRange_0057b848);

          if (DAT_00632a88 == 0) {

            return;

          }

          iVar13 = *(int *)(DAT_00632a88 + 0x170);

          if (iVar13 == 0) {

            return;

          }

          cVar2 = *pcVar9;

          if (cVar2 == '-') {

            pcVar9 = pcVar9 + 1;

          }

          iVar8 = (iVar13 + 0x34) - (int)pcVar9;

          do {

            cVar3 = *pcVar9;

            pcVar9[iVar8] = cVar3;

            pcVar9 = pcVar9 + 1;

          } while (cVar3 != '\0');

          if ((cVar2 == '-') &&

             (*(float *)(iVar13 + 0x134) < 0.0 != (*(float *)(iVar13 + 0x134) == 0.0))) {

            *(undefined4 *)(iVar13 + 0x134) = 0;

            return;

          }

        }

      }

    }

    else if (param_2 == 2.8026e-45) {

      piVar4[0xb] = 0;

      for (puVar6 = DAT_00632d70; puVar6 != (undefined4 *)0x0; puVar6 = (undefined4 *)*puVar6) {

        iVar8 = puVar6[3];

        if ((((((-1 < (char)((uint)*(undefined4 *)(iVar8 + 0xd8) >> 8)) &&

               (*(int *)(iVar8 + 0x170) == *(int *)(param_1 + 0x170))) && (*(int *)(iVar8 + 4) == 2)

              ) && ((iVar8 != param_1 &&

                    (local_20 = local_20 + 1, *(float *)(iVar8 + 0x278) < *(float *)(iVar8 + 0x1c0))

                    ))) && (local_1c = local_1c + 1, *(int *)(iVar8 + 0x210) == 0)) &&

           ((*(uint *)(iVar8 + 0xe0) & 0x2000000) == 0)) {

          iVar12 = *(int *)(iVar8 + 0x100);

          *(undefined4 *)(iVar12 + 0x14) = 0;

          *(undefined4 *)(iVar12 + 0x2c) = 0;

          *(undefined4 *)(iVar8 + 0xec) = 0;

          *(undefined4 *)(iVar8 + 0xd4) = 0;

          fVar14 = (float)((int)fVar14 + 1);

          if (*(int *)(iVar12 + 0x118) != 0) {

            pbVar1 = (byte *)(*(int *)(iVar12 + 0x118) + 0xdb);

            *pbVar1 = *pbVar1 | 0x40;

          }

          *(uint *)(iVar12 + 0xec) = *(uint *)(iVar12 + 0xec) & 0xfffffff0;

          *(undefined4 *)(iVar8 + 0xe4) = 0;

        }

      }

      if (param_3 == 0) {

        return;

      }

      if (fVar14 == 0.0) {

        if ((local_20 == 0) || (local_1c == 0)) {

          pcVar9 = (char *)FUN_00507b00(s_AIMeccNone_0057b800);

          if (DAT_00632a88 == 0) {

            return;

          }

          iVar13 = *(int *)(DAT_00632a88 + 0x170);

          if (iVar13 == 0) {

            return;

          }

          cVar2 = *pcVar9;

          if (cVar2 == '-') {

            pcVar9 = pcVar9 + 1;

          }

          iVar8 = (iVar13 + 0x34) - (int)pcVar9;

          do {

            cVar3 = *pcVar9;

            pcVar9[iVar8] = cVar3;

            pcVar9 = pcVar9 + 1;

          } while (cVar3 != '\0');

          if ((cVar2 == '-') &&

             (*(float *)(iVar13 + 0x134) < 0.0 != (*(float *)(iVar13 + 0x134) == 0.0))) {

            *(undefined4 *)(iVar13 + 0x134) = 0;

            return;

          }

        }

        else {

          pcVar9 = (char *)FUN_00507b00(s_AIMeccBusy_0057b80c);

          if (DAT_00632a88 == 0) {

            return;

          }

          iVar13 = *(int *)(DAT_00632a88 + 0x170);

          if (iVar13 == 0) {

            return;

          }

          cVar2 = *pcVar9;

          if (cVar2 == '-') {

            pcVar9 = pcVar9 + 1;

          }

          iVar8 = (iVar13 + 0x34) - (int)pcVar9;

          do {

            cVar3 = *pcVar9;

            pcVar9[iVar8] = cVar3;

            pcVar9 = pcVar9 + 1;

          } while (cVar3 != '\0');

          if ((cVar2 == '-') &&

             (*(float *)(iVar13 + 0x134) < 0.0 != (*(float *)(iVar13 + 0x134) == 0.0))) {

            *(undefined4 *)(iVar13 + 0x134) = 0;

            return;

          }

        }

      }

      else {

        if ((*(int *)(iVar13 + 0x1f0) != 2) && (*(int *)(iVar13 + 500) != 0)) {

          (*DAT_005dd354)(*(int *)(iVar13 + 500));

          *(undefined4 *)(iVar13 + 500) = 0;

        }

        iVar8 = (*DAT_005dd358)(*(undefined4 *)(iVar13 + 500));

        if (iVar8 == 0) {

          uVar10 = teammecc_clear_mode(s_BAZ_CT06_0057b7f4,*(undefined4 *)(DAT_006330e4 + 0x50e0),0)

          ;

          *(undefined4 *)(iVar13 + 500) = uVar10;

        }

        *(undefined4 *)(iVar13 + 0x1f0) = 2;

        fVar15 = (float10)FUN_004d5780(0x3f800000,0x40400000);

        piVar4[9] = (int)(float)fVar15;

        pcVar9 = (char *)FUN_00507b00(s_AIMeccReturn_0057b7e4);

        if (DAT_00632a88 == 0) {

          return;

        }

        iVar13 = *(int *)(DAT_00632a88 + 0x170);

        if (iVar13 == 0) {

          return;

        }

        cVar2 = *pcVar9;

        if (cVar2 == '-') {

          pcVar9 = pcVar9 + 1;

        }

        iVar8 = (iVar13 + 0x34) - (int)pcVar9;

        do {

          cVar3 = *pcVar9;

          pcVar9[iVar8] = cVar3;

          pcVar9 = pcVar9 + 1;

        } while (cVar3 != '\0');

        if ((cVar2 == '-') &&

           (*(float *)(iVar13 + 0x134) < 0.0 != (*(float *)(iVar13 + 0x134) == 0.0))) {

          *(undefined4 *)(iVar13 + 0x134) = 0;

          return;

        }

      }

    }

    else {

      if (param_2 != 4.2039e-45) {

        return;

      }

      piVar4[0xb] = 0;

      iVar8 = FUN_00455890(&local_c,0x47435000,&param_2);

      param_2 = *(float *)(DAT_00632ed8 + 0x1068);

      fVar15 = (float10)FUN_0050a610(param_1 + 0xa0,&local_c);

      if (fVar15 < (float10)param_2 * (float10)param_2) {

        bVar7 = true;

        for (puVar6 = DAT_00632d70; puVar6 != (undefined4 *)0x0; puVar6 = (undefined4 *)*puVar6) {

          iVar12 = puVar6[3];

          if ((((-1 < (char)((uint)*(undefined4 *)(iVar12 + 0xd8) >> 8)) &&

               (*(int *)(iVar12 + 0x170) == *(int *)(param_1 + 0x170))) &&

              (*(int *)(iVar12 + 4) == 2)) &&

             (((iVar12 != param_1 && (local_20 = local_20 + 1, *(int *)(iVar12 + 0x210) == 0)) &&

              ((local_1c = local_1c + 1, *(float *)(iVar12 + 0x278) < *(float *)(iVar12 + 0x1c0) &&

               ((*(uint *)(iVar12 + 0xe0) & 0x2000000) == 0)))))) {

            iVar5 = *(int *)(iVar12 + 0x100);

            fVar14 = (float)((int)fVar14 + 1);

            *(undefined4 *)(iVar5 + 0x14) = 0;

            *(undefined4 *)(iVar5 + 0x2c) = 0;

            *(undefined4 *)(iVar12 + 0xec) = 0;

            *(undefined4 *)(iVar12 + 0xd4) = 0;

            *(undefined4 *)(iVar5 + 0xe0) = local_c;

            *(undefined4 *)(iVar5 + 0xe4) = local_8;

            *(undefined4 *)(iVar5 + 0xe8) = local_4;

            if (iVar8 == 0) {

              *(undefined4 *)(iVar5 + 0xe0) = *(undefined4 *)(param_1 + 0xa0);

              *(undefined4 *)(iVar5 + 0xe4) = *(undefined4 *)(param_1 + 0xa4);

              *(undefined4 *)(iVar5 + 0xe8) = *(undefined4 *)(param_1 + 0xa8);

            }

            *(uint *)(iVar5 + 0xec) = *(uint *)(iVar5 + 0xec) & 0xfffffff4 | 4;

            *(undefined4 *)(iVar12 + 0xe4) = 0;

            param_2 = fVar14;

          }

        }

      }

      if (param_3 == 0) {

        return;

      }

      if (bVar7) {

        if (fVar14 == 0.0) {

          if ((local_20 == 0) || (local_1c == 0)) {

            pcVar9 = (char *)FUN_00507b00(s_AIMeccNone_0057b800);

            if (DAT_00632a88 == 0) {

              return;

            }

            iVar13 = *(int *)(DAT_00632a88 + 0x170);

            if (iVar13 == 0) {

              return;

            }

            cVar2 = *pcVar9;

            if (cVar2 == '-') {

              pcVar9 = pcVar9 + 1;

            }

            iVar8 = (iVar13 + 0x34) - (int)pcVar9;

            do {

              cVar3 = *pcVar9;

              pcVar9[iVar8] = cVar3;

              pcVar9 = pcVar9 + 1;

            } while (cVar3 != '\0');

            if ((cVar2 == '-') &&

               (*(float *)(iVar13 + 0x134) < 0.0 != (*(float *)(iVar13 + 0x134) == 0.0))) {

              *(undefined4 *)(iVar13 + 0x134) = 0;

              return;

            }

          }

          else {

            pcVar9 = (char *)FUN_00507b00(s_AIMeccBusy_0057b80c);

            if (DAT_00632a88 == 0) {

              return;

            }

            iVar13 = *(int *)(DAT_00632a88 + 0x170);

            if (iVar13 == 0) {

              return;

            }

            cVar2 = *pcVar9;

            if (cVar2 == '-') {

              pcVar9 = pcVar9 + 1;

            }

            iVar8 = (iVar13 + 0x34) - (int)pcVar9;

            do {

              cVar3 = *pcVar9;

              pcVar9[iVar8] = cVar3;

              pcVar9 = pcVar9 + 1;

            } while (cVar3 != '\0');

            if ((cVar2 == '-') &&

               (*(float *)(iVar13 + 0x134) < 0.0 != (*(float *)(iVar13 + 0x134) == 0.0))) {

              *(undefined4 *)(iVar13 + 0x134) = 0;

              return;

            }

          }

        }

        else {

          iVar8 = (*DAT_005dd358)(*(undefined4 *)(iVar13 + 500));

          if (iVar8 == 0) {

            iVar8 = FUN_004d5730(100);

            if (iVar8 < 0x21) {

              uVar10 = *(undefined4 *)(DAT_006330e4 + 0x50e0);

              pcVar9 = s_GOR_CT01_0057b83c;

            }

            else if (iVar8 < 0x42) {

              uVar10 = *(undefined4 *)(DAT_006330e4 + 0x50e0);

              pcVar9 = s_REG_CT01_0057b830;

            }

            else {

              uVar10 = *(undefined4 *)(DAT_006330e4 + 0x50e0);

              pcVar9 = s_REG_CT51_0057b824;

            }

            uVar10 = teammecc_clear_mode(pcVar9,uVar10,0);

            *(undefined4 *)(iVar13 + 500) = uVar10;

          }

          fVar15 = (float10)FUN_004d5780(0x3f800000,0x40400000);

          piVar4[9] = (int)(float)fVar15;

          pcVar9 = (char *)FUN_00507b00(s_AIMeccHide_0057b818);

          if (DAT_00632a88 == 0) {

            return;

          }

          iVar13 = *(int *)(DAT_00632a88 + 0x170);

          if (iVar13 == 0) {

            return;

          }

          cVar2 = *pcVar9;

          if (cVar2 == '-') {

            pcVar9 = pcVar9 + 1;

          }

          iVar8 = (iVar13 + 0x34) - (int)pcVar9;

          do {

            cVar3 = *pcVar9;

            pcVar9[iVar8] = cVar3;

            pcVar9 = pcVar9 + 1;

          } while (cVar3 != '\0');

          if ((cVar2 == '-') &&

             (*(float *)(iVar13 + 0x134) < 0.0 != (*(float *)(iVar13 + 0x134) == 0.0))) {

            *(undefined4 *)(iVar13 + 0x134) = 0;

            return;

          }

        }

      }

      else {

        pcVar9 = (char *)FUN_00507b00(s_AIMeccRange_0057b848);

        if (DAT_00632a88 == 0) {

          return;

        }

        iVar13 = *(int *)(DAT_00632a88 + 0x170);

        if (iVar13 == 0) {

          return;

        }

        cVar2 = *pcVar9;

        if (cVar2 == '-') {

          pcVar9 = pcVar9 + 1;

        }

        iVar8 = (iVar13 + 0x34) - (int)pcVar9;

        do {

          cVar3 = *pcVar9;

          pcVar9[iVar8] = cVar3;

          pcVar9 = pcVar9 + 1;

        } while (cVar3 != '\0');

        if ((cVar2 == '-') &&

           (*(float *)(iVar13 + 0x134) < 0.0 != (*(float *)(iVar13 + 0x134) == 0.0))) {

          *(undefined4 *)(iVar13 + 0x134) = 0;

          return;

        }

      }

    }

  }

  *(undefined4 *)(iVar13 + 0x134) = 0x40a00000;

  return;

}

/* ===== mecc_animselect_gm @ 0x005059B0 ===== */
/* PS2 candidate: mecc_animselect_gm (conf 0.485) */



void mecc_animselect_gm(int param_1,int param_2)



{

  float fVar1;

  int iVar2;

  int iVar3;

  uint *puVar4;

  int iVar5;

  undefined4 *puVar6;

  int iVar7;

  uint uVar8;

  uint uVar9;

  uint uVar10;

  uint uVar11;

  uint uVar12;

  undefined4 uVar13;

  int iVar14;

  int iVar15;

  char cVar16;

  bool bVar17;

  bool bVar18;

  float10 fVar19;

  float10 fVar20;

  char *pcVar21;

  undefined4 uVar22;

  undefined1 *puVar23;

  int local_88;

  uint local_84;

  int local_80;

  uint local_6c;

  uint local_68;

  undefined4 local_60;

  float local_5c;

  float local_58;

  float local_54;

  undefined *local_50;

  int local_4c;

  int local_48;

  int local_44;

  int local_40;

  undefined4 local_3c;

  int local_38;

  undefined1 local_34 [4];

  undefined4 local_30;

  undefined4 local_2c;

  undefined4 local_28;

  undefined4 local_24;

  undefined4 local_20;

  int local_1c;

  

  iVar14 = *(int *)(param_1 + 0x100);

  local_48 = iVar14;

  if (*(int *)(param_1 + 0xe8) == 1) {

    *(undefined4 *)(param_1 + 0x174) = 1;

    uVar13 = 0x20;

    if (*(int *)(param_1 + 0xe4) == 0) {

      local_38 = 0xd7;

      uVar13 = 0x21;

    }

    else if (*(int *)(param_1 + 0xe4) == 1) {

      local_38 = 0xd8;

    }

    if (*(int *)(param_1 + 0x10) == local_38) {

      return;

    }

    FUN_004034a0(param_1,local_38,uVar13,0,0,0x3e2aaaab);

    return;

  }

  iVar2 = *(int *)(iVar14 + 0x30);

  bVar17 = false;

  local_44 = 0;

  local_68 = 0;

  local_50 = (undefined *)0x0;

  iVar3 = *(int *)(param_1 + 0x10);

  local_60 = 0xffffffff;

  local_3c = 0x3e2aaaab;

  local_84 = 0x20;

  local_88 = -1;

  local_80 = -1;

  iVar7 = FUN_00458150(param_1);

  local_40 = iVar7;

  uVar13 = WeaponIdGetPresent__FP6OBJECT(param_1);

  local_38 = FUN_004a8f90(iVar7);

  iVar7 = FUN_0052aa70();

  if ((iVar7 == 0) && (param_1 != DAT_00632a88)) {

    local_4c = 2;

  }

  else {

    local_4c = FUN_004a8f90(uVar13);

  }

  iVar7 = FUN_00458200(param_1);

  if (((*(uint *)(param_1 + 0xe0) & 0x2000000) == 0) || (iVar3 == 0x2e)) {

    local_6c = 0;

  }

  else {

    local_6c = 0x100000;

  }

  local_6c = (-(uint)(iVar7 != 0) & 0xfffe0000) + 0x20000 | (*(uint *)(param_1 + 0x30) & 2) << 0x12

             | local_6c;

  if (param_2 == 0) {

    local_6c = local_6c | 0xc000;

  }

  else {

    if (((*(float *)(param_1 + 0xa8) - *(float *)(param_1 + 0x140)) -

         *(float *)(param_1 + 0x1d4) * *(float *)(param_1 + 0xc4) <=

         *(float *)(DAT_00632ed8 + 0xc24)) || (*(int *)(param_1 + 0x224) != 0)) {

      uVar8 = 0;

    }

    else {

      uVar8 = 2;

    }

    if ((*(float *)(param_1 + 0x108) == 0.0) || (uVar8 == 0)) {

      uVar9 = 0;

    }

    else {

      uVar9 = 0x40;

    }

    uVar9 = local_6c | *(uint *)(param_1 + 0xd8) >> 10 & 4 |

            ((*(uint *)(param_1 + 0xdc) & 0x20) << 2 | *(uint *)(param_1 + 0xe0) & 0x100) << 2 |

            *(ushort *)(param_1 + 0xde) & 0x800 | uVar8 | uVar9;

    bVar18 = *(float *)(param_1 + 0x10c) == 0.0;

    if (param_1 == DAT_00632a88) {

      if (bVar18) {

        uVar8 = 0;

      }

      else {

        uVar8 = 0x10;

      }

      if (*(float *)(param_1 + 0x114) == 0.0) {

        uVar10 = 0;

      }

      else {

        uVar10 = 0x80;

      }

      uVar10 = uVar9 | uVar8 | uVar10;

      if (*(float *)(param_1 + 0x110) != 0.0) goto LAB_00505c08;

LAB_00505cc1:

      uVar8 = 0;

    }

    else {

      if ((bVar18) && (*(float *)(param_1 + 0x11c) == 0.0)) {

        uVar8 = 0;

      }

      else {

        uVar8 = 0x10;

      }

      if ((*(float *)(param_1 + 0x114) == 0.0) && (*(float *)(param_1 + 0x124) == 0.0)) {

        uVar10 = 0;

      }

      else {

        uVar10 = 0x80;

      }

      uVar10 = uVar9 | uVar8 | uVar10;

      if ((*(float *)(param_1 + 0x110) == 0.0) && (*(float *)(param_1 + 0x120) == 0.0))

      goto LAB_00505cc1;

LAB_00505c08:

      uVar8 = 0x20;

    }

    uVar9 = -(uint)((uVar10 & 0xf0) != 0 || (char)uVar8 != '\0') & 0x100;

    if (-60.0 <= *(float *)(param_1 + 0x108)) {

      uVar11 = 0;

    }

    else {

      uVar11 = 8;

    }

    fVar19 = (float10)FUN_00518b70(param_1,0);

    fVar19 = (float10)*(float *)(iVar14 + 100) - fVar19;

    *(float *)(iVar14 + 100) = (float)fVar19;

    if (fVar19 < (float10)0.0) {

      *(undefined4 *)(iVar14 + 100) = 0;

    }

    if ((uVar10 & 0x800) != 0) {

      *(undefined4 *)(iVar14 + 100) = 0x40400000;

    }

    if (*(float *)(iVar14 + 100) == 0.0) {

      uVar12 = 0;

    }

    else {

      uVar12 = 0x2000;

    }

    fVar19 = (float10)FUN_00518b70(param_1,0);

    fVar19 = (float10)*(float *)(iVar14 + 0x68) - fVar19;

    *(float *)(iVar14 + 0x68) = (float)fVar19;

    if (fVar19 < (float10)0.0) {

      *(undefined4 *)(iVar14 + 0x68) = 0;

    }

    local_6c = uVar10 | uVar8 | uVar9 | uVar11 | uVar12 |

               (-(uint)((uVar10 & 0x1900) != 0 || uVar9 != 0) & 0xffffc000) + 0x4000;

    if (((~local_6c & 0x4000) != 0) || (uVar12 != 0)) {

      *(undefined4 *)(iVar14 + 0x68) = 0x40000000;

    }

    if ((*(float *)(iVar14 + 0x68) == 0.0) && ((~local_6c & 0x10000) != 0)) {

      local_6c = local_6c | 0x8000;

    }

  }

  uVar8 = *(uint *)(param_1 + 0x30) & 2;

  if (((*(char *)(param_1 + 0x20a) == '\0') && (*(char *)(param_1 + 0x20b) == '\0')) &&

     ((local_6c & 0x200) == 0)) {

    bVar18 = false;

  }

  else {

    bVar18 = true;

    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xffffffef;

  }

  if (*(float *)(param_1 + 0x1c0) <= *(float *)(param_1 + 0x278)) {

    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xffffffef;

    if (((*(uint *)(param_1 + 0xd8) & 0x8000000) != 0) || (*(float *)(param_1 + 0xa8) < 0.0)) {

      local_88 = 0x8f;

      bVar17 = true;

      iVar7 = local_88;

    }

    else {

      iVar7 = *(int *)(iVar14 + 0xf0);

      if (*(int *)(iVar14 + 0xf0) < 1) {

        if ((iVar3 != 0x88) &&

           ((10.0 < *(float *)(param_1 + 0x130) ||

            (10.0 < (*(float *)(param_1 + 0xa8) -

                    *(float *)(param_1 + 0x1d4) * *(float *)(param_1 + 0xc4)) -

                    *(float *)(param_1 + 0x140))))) {

          local_88 = 0x88;

          local_84 = 0x21;

          local_1c = param_1;

          local_20 = 4;

          local_24 = 8;

          if (*(int *)(iVar14 + 0xf4) == 0) {

            uVar13 = fx_get_free_effect__Fv();

            *(undefined4 *)(iVar14 + 0xf4) = uVar13;

          }

        }

        iVar7 = local_88;

        if ((*(uint *)(param_1 + 0xd8) & 0x80000) != 0) {

          if (iVar3 == 0x88) {

            local_88 = 0x17;

            iVar7 = local_88;

          }

          else if (((iVar3 != 0x90) && (iVar3 != 0x17)) && (iVar3 != 0xca)) {

            iVar7 = (-(uint)((*(uint *)(param_1 + 0xd8) & 0x800) != 0) & 0x3a) + 0x90;

          }

        }

      }

      local_88 = iVar7;

      FUN_004ac620(param_1,param_1 + 0x144,0x3dcccccd);

      bVar17 = true;

      iVar7 = local_88;

    }

    goto LAB_00506977;

  }

  iVar7 = *(int *)(param_1 + 0x210);

  iVar15 = local_80;

  if (iVar7 != 0) {

    if ((*(int *)(iVar7 + 0x1e0) == 0x2c) || (*(int *)(iVar7 + 4) == 0xd2)) {

      local_88 = 1;

    }

    else {

      if (*(int *)(iVar7 + 0x1e0) != 0x5f) goto LAB_005075f7;

      local_80 = 5;

    }

LAB_005075ef:

    local_84 = 0x21;

    iVar15 = local_80;

    goto LAB_005075f7;

  }

  uVar9 = *(uint *)(param_1 + 0xe0);

  if ((uVar9 & 1) == 0) {

    if ((uVar9 & 0x200000) != 0) {

      bVar17 = true;

      if (iVar3 != 0xd9) {

        local_88 = 0xd9;

      }

      iVar7 = local_88;

      if (uVar8 != 0) {

        *(uint *)(param_1 + 0xe0) = uVar9 & 0xffdfffff;

        bVar17 = false;

      }

      goto LAB_00506977;

    }

    iVar7 = FUN_0047f730(param_1);

    if (iVar7 != 0) {

      if ((*(byte *)(param_1 + 0x30) & 2) != 0) {

        iVar14 = FUN_004d5730(100);

        if (iVar14 < 10) {

          local_88 = 0xd4;

        }

        else if (iVar14 < 0x14) {

          local_88 = 0xd5;

        }

        else {

          local_88 = 0xd3;

          local_84 = 0x21;

        }

      }

      local_5c = *(float *)(param_1 + 0x128) - *(float *)(param_1 + 0x134);

      bVar17 = true;

      local_58 = *(float *)(param_1 + 300) - *(float *)(param_1 + 0x138);

      local_54 = *(float *)(param_1 + 0x130) - *(float *)(param_1 + 0x13c);

      fVar19 = (float10)FUN_0050a550(&local_5c);

      fVar1 = (float)fVar19;

      iVar7 = local_88;

      if ((float10)*(float *)(DAT_00632ed8 + 0xb60) <= fVar19) {

        fVar19 = (float10)FUN_0050a550(param_1 + 0x134);

        fVar20 = (float10)FUN_0050a550(param_1 + 0x128);

        if ((fVar20 < (float10)(float)fVar19) && (iVar14 = FUN_0052e480(param_1), iVar14 != 0)) {

          if (*(float *)(DAT_00632ed8 + 0xb68) < fVar1 ==

              (*(float *)(DAT_00632ed8 + 0xb68) == fVar1)) {

            FUN_00456f80(0x1a,(fVar1 - *(float *)(DAT_00632ed8 + 0xb60)) *

                              *(float *)(DAT_00632ed8 + 0xb64),param_1,0,param_1 + 0xa0,0);

          }

          else {

            FUN_00456f80(0x1a,0x447a0000,param_1,0,param_1 + 0xa0,0);

          }

        }

      }

      goto LAB_00506977;

    }

    uVar9 = *(uint *)(param_1 + 0xe0);

    if ((uVar9 & 0x40) != 0) {

      local_88 = 200;

      if (((uVar9 & 0x40000) != 0) && (*(int *)(iVar14 + 0x18c) == 0x11)) {

        if ((uVar9 & 0x800000) == 0) {

LAB_005062c9:

          mecc_enable_personal_shield(param_1);

        }

        else {

          FUN_004802c0();

        }

LAB_005062ce:

        *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xfffbffff;

      }

      goto LAB_005075f7;

    }

    if ((uVar9 & 0x2000000) == 0) {

      if ((uVar9 & 0x8000000) == 0) {

        uVar10 = *(uint *)(param_1 + 0xd8);

        if ((uVar10 & 0x8000000) == 0) {

          if ((int)uVar10 < 0) {

            if (((uVar10 & 0x80000) == 0) && (DAT_00632d8c != 0)) {

              local_88 = 0x56;

              goto LAB_005075ef;

            }

            *(uint *)(param_1 + 0xd8) = uVar10 & 0x7fffffff;

            goto LAB_0050698f;

          }

          if ((uVar9 & 0x40000) == 0) {

            iVar5 = *(int *)(param_1 + 0xe4);

            if (iVar5 == 0x12) {

              iVar15 = 0x2a;

              if ((iVar2 == 0x2a) && (uVar8 != 0)) {

LAB_00506e0c:

                *(uint *)(param_1 + 0xe0) = uVar9 & 0xffffffef;

                *(undefined4 *)(param_1 + 0xe4) = 0;

                goto LAB_0050698f;

              }

            }

            else if (iVar2 == 0x2b) {

              if (uVar8 != 0) {

                *(undefined4 *)(param_1 + 0xe4) = 0x12;

              }

            }

            else if (((iVar3 == 0x86) || (iVar2 == 0x2c)) || (iVar2 == 0x2d)) {

              if ((uVar8 != 0) || (bVar18)) goto LAB_00506e0c;

            }

            else {

              iVar7 = *(int *)(iVar14 + 0xf0);

              if ((iVar3 == iVar7) && (0 < iVar7)) {

                if (uVar8 != 0) {

                  *(uint *)(param_1 + 0xe0) = uVar9 & 0xffffffef;

                  *(undefined4 *)(iVar14 + 0xf0) = 0xffffffff;

                  *(undefined4 *)(param_1 + 0xe4) = 0;

                  goto LAB_0050698f;

                }

              }

              else if ((uVar9 & 0x10) == 0) {

                if (*(int *)(iVar14 + 0x20) == 4) {

                  if (iVar5 == 0x10) {

                    if ((iVar2 == 0x2f) || ((iVar2 == 0x2e && (uVar8 == 0)))) {

                      local_80 = 0x2e;

                      local_84 = 0x30;

                    }

                    goto LAB_00506963;

                  }

                  if ((uVar9 & 4) == 0) goto LAB_0050698f;

                  iVar15 = 0x2f;

                  if ((iVar2 != 0x2f) && ((iVar2 != 0x2e || (uVar8 == 0)))) {

                    local_80 = 0x2e;

                    iVar15 = local_80;

                  }

                }

                else {

                  if ((*(int *)(iVar14 + 0x20) != 5) || ((uVar9 & 4) == 0)) {

                    if (iVar5 == 7) {

                      if ((uVar8 == 0) || (iVar2 != 0x32)) {

                        local_80 = 0x32;

                      }

                      else {

                        *(undefined4 *)(param_1 + 0xe4) = 8;

                        fVar19 = (float10)FUN_004d5780(0x40000000,0x40c00000);

                        *(float *)(param_1 + 0xec) = (float)fVar19;

                      }

                      goto LAB_00506963;

                    }

                    if (iVar5 != 8) {

                      if (iVar5 == 9) {

                        if ((iVar2 == 0x35) && (uVar8 != 0)) {

                          *(undefined4 *)(param_1 + 0xe4) = 10;

                        }

                        else {

                          local_80 = 0x35;

                          iVar15 = local_80;

                        }

                      }

                      else if (iVar5 == 0xb) {

                        local_80 = 0x38;

                        *(undefined4 *)(param_1 + 0xe4) = 0xc;

                        iVar15 = local_80;

                      }

                      else if (iVar5 == 0xc) {

                        if (uVar8 == 0) goto LAB_00506963;

                        if (iVar3 == 0x75) {

LAB_00506ce5:

                          iVar14 = FUN_004d5730(100);

                          local_84 = 0x21;

                          if (iVar14 < 0x46) {

                            local_88 = 0x76;

                          }

                          else {

                            local_88 = 0x75;

                          }

                        }

                        else if (iVar3 == 0x65) {

LAB_00506d40:

                          iVar14 = FUN_004d5730(100);

                          local_84 = 0x21;

                          if (iVar14 < 0x46) {

                            local_88 = 0x66;

                          }

                          else {

LAB_00506d64:

                            local_84 = 0x21;

                            local_88 = 0x65;

                          }

                        }

                        else {

                          if (iVar3 == 0x76) goto LAB_00506ce5;

                          if (iVar3 == 0x66) {

                            iVar14 = FUN_004d5730(100);

                            local_84 = 0x21;

                            if (0x45 < iVar14) goto LAB_00506d64;

                            local_88 = 0x67;

                          }

                          else {

                            if (iVar3 == 0x67) goto LAB_00506d40;

                            local_80 = (iVar2 == 0x38) + 0x38;

                          }

                        }

LAB_00506963:

                        bVar17 = true;

                        iVar7 = local_88;

                        iVar15 = local_80;

                        if (local_80 < 0) goto LAB_00506977;

                      }

                      else {

                        if (iVar5 != 0xd) {

                          if ((char)uVar9 < '\0') {

                            if (iVar3 != 0x8b) {

                              if (iVar3 != 0x8c) {

                                local_88 = 0x8b;

                              }

                              goto LAB_005075f7;

                            }

                            if (uVar8 != 0) {

                              local_88 = 0x8c;

                              goto LAB_005075ef;

                            }

                          }

                          goto LAB_0050698f;

                        }

                        iVar15 = 0x2a;

                        if ((iVar2 == 0x2a) && (uVar8 != 0)) {

                          *(undefined4 *)(param_1 + 0xe4) = 0xe;

                          iVar15 = local_80;

                        }

                      }

                      goto LAB_005075f7;

                    }

                    if (uVar8 != 0) {

                      if (((iVar3 != 0x6f) && (iVar3 != 0x70)) && (iVar3 != 0x71)) {

                        if (iVar3 == 0x60) {

                          iVar7 = FUN_004d5730(100);

                          bVar18 = SBORROW4(iVar7,0x32);

                          iVar14 = iVar7 + -0x32;

                          bVar17 = iVar7 == 0x32;

LAB_00506b41:

                          local_84 = 0x21;

                          if (!bVar17 && bVar18 == iVar14 < 0) {

                            local_88 = 0x61;

                            bVar17 = true;

                            iVar7 = local_88;

                            goto LAB_00506977;

                          }

                        }

                        else {

                          if (iVar3 == 0x72) {

                            iVar14 = FUN_004d5730(100);

                            local_84 = 0x21;

                            if (iVar14 < 0x1f) {

                              local_88 = 0x6f;

                              bVar17 = true;

                              iVar7 = local_88;

                            }

                            else {

                              local_88 = 0x72;

                              bVar17 = true;

                              iVar7 = local_88;

                            }

                            goto LAB_00506977;

                          }

                          if (iVar3 != 0x61) {

                            if (iVar3 != 0x62) {

                              if (iVar3 == 0x6e) {

                                local_88 = 0x72;

                              }

                              else {

                                if (iVar3 != 0x5f) goto LAB_00506c5e;

                                local_88 = 0x62;

                              }

                              goto LAB_00506c56;

                            }

                            iVar14 = FUN_004d5730(100);

                            bVar18 = SBORROW4(iVar14,0x14);

                            iVar14 = iVar14 + -0x14;

                            bVar17 = iVar14 == 0;

                            goto LAB_00506b41;

                          }

                          iVar14 = FUN_004d5730(100);

                          local_84 = 0x21;

                          if (0x14 < iVar14) {

                            local_88 = 0x62;

                            bVar17 = true;

                            iVar7 = local_88;

                            goto LAB_00506977;

                          }

                        }

                        local_84 = 0x21;

                        local_88 = 0x60;

                        bVar17 = true;

                        iVar7 = local_88;

                        goto LAB_00506977;

                      }

                      iVar14 = FUN_004d5730(100);

                      if (iVar14 < 0x3d) {

                        if (iVar14 < 0x1f) {

                          local_88 = 0x71;

                          if (iVar14 < 0x10) {

                            local_88 = 0x70;

                          }

                        }

                        else {

                          local_88 = 0x6f;

                        }

                      }

                      else {

                        local_88 = 0x72;

                      }

LAB_00506c56:

                      local_84 = 0x21;

                    }

LAB_00506c5e:

                    bVar17 = true;

                    iVar7 = local_88;

                    goto LAB_00506977;

                  }

                  if (iVar5 == 0x11) goto LAB_0050698f;

                  if (iVar5 == 0x10) {

                    if ((iVar2 == 0x31) || ((iVar2 == 0x30 && (uVar8 == 0)))) {

                      local_80 = 0x30;

                      local_84 = 0x30;

                    }

                    goto LAB_00506963;

                  }

                  if (iVar3 == 0x6c) {

                    if ((uVar8 != 0) && (iVar14 = FUN_004d5730(100), 0x50 < iVar14)) {

LAB_00506a99:

                      local_88 = 0x6d;

                      goto LAB_005075f7;

                    }

LAB_00506a69:

                    if ((iVar2 != 0x31) && ((iVar2 != 0x30 || (uVar8 == 0)))) {

                      local_80 = 0x30;

                      iVar15 = local_80;

                      goto LAB_005075f7;

                    }

                  }

                  else {

                    if (iVar3 != 0x6d) goto LAB_00506a69;

                    if (uVar8 == 0) goto LAB_00506a99;

                  }

                  local_80 = 0x31;

                  iVar15 = local_80;

                }

              }

              else {

                if (0 < iVar7) goto LAB_00506977;

                iVar14 = FUN_004d5730(100);

                if (iVar14 < 0x3a) {

                  if ((*(uint *)(param_1 + 0xd8) & 0x80000) == 0) {

                    local_88 = 0x86;

                  }

                  else {

                    local_80 = 0x2d;

                    iVar15 = local_80;

                  }

                }

                else if ((iVar14 < 0x62) || (param_1 == DAT_00632a88)) {

                  if ((*(uint *)(param_1 + 0xd8) & 0x80000) == 0) {

                    local_88 = 0x86;

                  }

                  else {

                    local_80 = 0x2c;

                    iVar15 = local_80;

                  }

                }

                else if ((*(uint *)(param_1 + 0xd8) & 0x80000) == 0) {

                  local_88 = 0x86;

                }

                else {

                  local_80 = 0x2b;

                  iVar15 = local_80;

                }

              }

            }

            goto LAB_005075f7;

          }

          iVar7 = *(int *)(iVar14 + 0x18c);

          if (iVar7 == 10) {

            if (iVar3 != 0x1f) {

              sound_play_player(0x5ce,param_1);

              local_88 = 0x1f;

              uVar13 = FUN_004a8fb0(*(undefined4 *)(iVar14 + 0x18c),1);

              iVar7 = FUN_00458300(param_1,10,uVar13);

              if ((iVar7 != 0) && (*(int *)(iVar7 + 0x1e0) == 0x4d)) {

                **(uint **)(iVar7 + 0x100) = **(uint **)(iVar7 + 0x100) & 0xffffffef;

              }

            }

LAB_0050640b:

            if (iVar3 == 0x1e) goto LAB_00506418;

LAB_005065cf:

            if (iVar3 == 0x1f) {

              if ((*(float *)(param_1 + 0x18) < 0.3) && (0.3 <= *(float *)(param_1 + 0x14))) {

                uVar13 = FUN_004a8fb0(*(undefined4 *)(iVar14 + 0x18c),1);

                iVar7 = FUN_00458300(param_1,10,uVar13);

                if (iVar7 != 0) {

                  *(undefined4 *)(iVar7 + 0x218) = 1;

                  *(undefined4 *)(iVar7 + 0x214) = 1;

                }

              }

              if ((*(float *)(param_1 + 0x18) < 2.5666666) &&

                 (2.5666666 <= *(float *)(param_1 + 0x14))) {

                uVar13 = FUN_004a8fb0(*(undefined4 *)(iVar14 + 0x18c),1);

                iVar7 = FUN_00458300(param_1,1,uVar13);

                if (iVar7 != 0) {

                  *(uint *)(param_1 + 0xdc) = *(uint *)(param_1 + 0xdc) & 0xffbfffff;

                  *(undefined4 *)(iVar14 + 0x18c) = 0xffffffff;

                  *(undefined4 *)(iVar7 + 0x210) = 0;

                  *(uint *)(iVar7 + 0xd8) = *(uint *)(iVar7 + 0xd8) | 0x10000;

                  iVar14 = FUN_0040cf70();

                  if (iVar14 != 0) {

                    *(float *)(iVar7 + 0xa0) =

                         *(float *)(param_1 + 0x298) * 1.4 + *(float *)(param_1 + 0x29c) * -6.1 +

                         *(float *)(param_1 + 0xa0);

                    *(float *)(iVar7 + 0xa4) =

                         *(float *)(param_1 + 0x2a8) * 1.4 + *(float *)(param_1 + 0x2ac) * -6.1 +

                         *(float *)(param_1 + 0xa4);

                    fVar1 = *(float *)(param_1 + 0xa8);

                    *(undefined4 *)(iVar7 + 0x2a0) = 0;

                    *(undefined4 *)(iVar7 + 0x29c) = 0;

                    *(undefined4 *)(iVar7 + 0x2b0) = 0;

                    *(undefined4 *)(iVar7 + 0x2a8) = 0;

                    *(float *)(iVar7 + 0xa8) = fVar1 - 1.0;

                    *(undefined4 *)(iVar7 + 700) = 0;

                    uVar13 = *(undefined4 *)(iVar7 + 0xc4);

                    *(undefined4 *)(iVar7 + 0x2b8) = 0;

                    *(undefined4 *)(iVar7 + 0x2c0) = uVar13;

                    *(undefined4 *)(iVar7 + 0x2ac) = uVar13;

                    *(undefined4 *)(iVar7 + 0x294) = 0x13;

                    *(undefined4 *)(iVar7 + 0x298) = uVar13;

                    *(undefined4 *)(iVar7 + 0x2a4) = *(undefined4 *)(iVar7 + 0xa0);

                    *(undefined4 *)(iVar7 + 0x2b4) = *(undefined4 *)(iVar7 + 0xa4);

                    *(undefined4 *)(iVar7 + 0x2c4) = *(undefined4 *)(iVar7 + 0xa8);

                  }

                  if (*(int *)(iVar7 + 0x1e0) == 0x4d) {

                    puVar4 = *(uint **)(iVar7 + 0x100);

                    FUN_004034a0(iVar7,10,0x20,0,0,0);

                    *puVar4 = *puVar4 & 0xfffffffb;

                    local_20 = 3;

                    local_1c = iVar7;

                    fx_get_free_effect__Fv();

                  }

                }

              }

              goto LAB_005067ce;

            }

            if (iVar3 == 0x1e) goto LAB_005067ce;

          }

          else {

            if (iVar7 != 0xb) {

              if (iVar7 == 0x14) {

                FUN_0047fff0(param_1);

LAB_005063fa:

                uVar9 = *(uint *)(param_1 + 0xe0);

              }

              else {

                if (iVar7 == 0x11) {

                  if ((uVar9 & 0x800000) == 0) {

                    mecc_enable_personal_shield(param_1);

                  }

                  else {

                    FUN_004802c0();

                  }

                  goto LAB_005063fa;

                }

                if (iVar7 == 0x13) {

                  if ((uVar9 & 0x1000000) == 0) {

                    FUN_004803a0(param_1);

                  }

                  else {

                    FUN_00480400();

                  }

                  goto LAB_005063fa;

                }

              }

              *(uint *)(param_1 + 0xe0) = uVar9 & 0xfffbffff;

              goto LAB_0050640b;

            }

            if (iVar3 != 0x1e) {

              sound_play_player(0x590,param_1);

              local_88 = 0x1e;

              goto LAB_0050640b;

            }

LAB_00506418:

            if ((*(float *)(param_1 + 0x18) < 0.21433334) &&

               (0.21433334 <= *(float *)(param_1 + 0x14))) {

              uVar13 = FUN_004a8fb0(*(undefined4 *)(iVar14 + 0x18c),1);

              iVar7 = FUN_00458300(param_1,10,uVar13);

              if (iVar7 != 0) {

                *(undefined4 *)(iVar7 + 0x218) = 0;

                *(undefined4 *)(iVar7 + 0x214) = 7;

              }

            }

            if (iVar3 != 0x1e) goto LAB_005065cf;

            if ((*(float *)(param_1 + 0x18) < 0.76666665) &&

               (0.76666665 <= *(float *)(param_1 + 0x14))) {

              uVar13 = FUN_004a8fb0(*(undefined4 *)(iVar14 + 0x18c),1);

              iVar7 = FUN_00458300(param_1,0,uVar13);

              if (iVar7 != 0) {

                *(uint *)(param_1 + 0xdc) = *(uint *)(param_1 + 0xdc) & 0xffbfffff;

                *(undefined4 *)(iVar14 + 0x18c) = 0xffffffff;

                *(undefined4 *)(iVar7 + 0x274) = 0;

                *(undefined4 *)(iVar7 + 0x210) = 0;

                FUN_00497510(iVar7);

                iVar14 = FUN_0052e480(param_1);

                if (iVar14 != 0) {

                  iVar14 = FUN_0040cf70();

                  if (iVar14 == 0) {

                    local_5c = *(float *)(iVar7 + 0xa0);

                    local_58 = *(float *)(iVar7 + 0xa4);

                  }

                  else {

                    local_5c = *(float *)(param_1 + 0x298) * 1.4 +

                               *(float *)(param_1 + 0x29c) * -6.1 + *(float *)(param_1 + 0xa0);

                    local_58 = *(float *)(param_1 + 0x2a8) * 1.4 +

                               *(float *)(param_1 + 0x2ac) * -6.1 + *(float *)(param_1 + 0xa4);

                  }

                  local_54 = *(float *)(param_1 + 0xa8) - 0.5;

                  iVar14 = FUN_0052aa70();

                  if ((iVar14 == 0) || (iVar14 = FUN_0052c5c0(), iVar14 != 0)) {

                    FUN_0047c7a0(param_1,uVar13,&local_5c,0);

                  }

                  else if ((*(uint *)(param_1 + 0xe0) & 0x10000000) == 0) {

                    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 0x10000000;

                    FUN_0047c8c0(param_1,uVar13,&local_5c);

                  }

                }

              }

            }

LAB_005067ce:

            if (uVar8 != 0) {

              *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xfffbffff;

            }

          }

          bVar17 = true;

          iVar7 = local_88;

          goto LAB_00506977;

        }

        local_88 = 0x8e;

        local_84 = 0x21;

        if (((uVar9 & 0x40000) != 0) && (*(int *)(iVar14 + 0x18c) == 0x11)) {

          if ((uVar9 & 0x800000) == 0) goto LAB_005062c9;

          FUN_004802c0(param_1);

          goto LAB_005062ce;

        }

      }

      else {

        if ((*(byte *)(param_1 + 0x30) & 2) == 0) goto LAB_0050698f;

        *(uint *)(param_1 + 0xe0) = uVar9 & 0xf7ffffff;

      }

      goto LAB_005075f7;

    }

    if ((uVar9 & 0x4000000) == 0) {

      if ((iVar3 != 0x30) && (iVar3 == 0x2e)) {

        FUN_00480a60(param_1);

        if ((*(byte *)(param_1 + 0x30) & 2) != 0) {

          local_88 = 0x30;

          goto LAB_005075ef;

        }

        local_88 = 0x2e;

        goto LAB_005075f7;

      }

    }

    else {

      if ((iVar3 != 0x2f) || ((*(byte *)(param_1 + 0x30) & 2) == 0)) {

        local_88 = 0x2f;

        goto LAB_005075f7;

      }

      *(uint *)(param_1 + 0xe0) = uVar9 & 0xf9ffffff;

    }

LAB_0050698f:

    if ((local_6c & 0x20000) != 0) {

      *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xffff03ff;

    }

    iVar7 = local_48;

    if ((local_6c & 0x40000) != 0) {

      local_68 = 0x400;

      local_80 = 0x17;

      iVar14 = local_80;

      goto LAB_00507609;

    }

    if ((*(float *)(param_1 + 0x130) < -*(float *)(DAT_00632ed8 + 0xc10)) &&

       (*(float *)(DAT_00632ed8 + 0xc14) <

        (*(float *)(param_1 + 0xa8) - *(float *)(param_1 + 0x140)) -

        *(float *)(param_1 + 0x1d4) * *(float *)(param_1 + 0xc4))) {

      local_80 = 2;

      local_60 = 0;

      iVar14 = local_80;

      goto LAB_00507609;

    }

    local_5c = *(float *)(param_1 + 0x128) - *(float *)(param_1 + 0x134);

    cVar16 = '\0';

    local_58 = *(float *)(param_1 + 300) - *(float *)(param_1 + 0x138);

    local_54 = *(float *)(param_1 + 0x130) - *(float *)(param_1 + 0x13c);

    fVar19 = (float10)FUN_0050a550(&local_5c);

    fVar1 = (float)fVar19;

    if ((float10)*(float *)(DAT_00632ed8 + 0x66c) <= fVar19) {

      fVar19 = (float10)FUN_0050a550(param_1 + 0x134);

      fVar20 = (float10)FUN_0050a550(param_1 + 0x128);

      if ((((fVar20 < (float10)(float)fVar19) &&

           (cVar16 = (*(float *)(DAT_00632ed8 + 0x670) < fVar1 !=

                     (*(float *)(DAT_00632ed8 + 0x670) == fVar1)) +

                     (*(float *)(DAT_00632ed8 + 0x66c) < fVar1 !=

                     (*(float *)(DAT_00632ed8 + 0x66c) == fVar1)), cVar16 != '\0')) &&

          (iVar14 = FUN_0052e480(param_1), iVar14 != 0)) && (*(int *)(param_1 + 0x174) == 0)) {

        FUN_00456f80(0x1a,(fVar1 - *(float *)(DAT_00632ed8 + 0x66c)) *

                          *(float *)(DAT_00632ed8 + 0xc00) + *(float *)(DAT_00632ed8 + 0xc04),

                     param_1,0,param_1 + 0xa0,0);

      }

    }

    iVar15 = local_40;

    iVar7 = local_48;

    if (((*(byte *)(local_48 + 0x80) & 2) != 0) &&

       ((*(float *)(param_1 + 0x130) < -*(float *)(DAT_00632ed8 + 0x664) ||

        ((iVar2 == 2 && (*(float *)(param_1 + 0x130) < -*(float *)(DAT_00632ed8 + 0x668))))))) {

      iVar14 = 0x3c;

      goto LAB_00507609;

    }

    iVar14 = local_80;

    if (cVar16 != '\0') {

      local_30 = *(undefined4 *)(param_1 + 0xa0);

      local_2c = *(undefined4 *)(param_1 + 0xa4);

      local_28 = *(undefined4 *)(param_1 + 0xa8);

      fx_get_free_effect__Fv();

      local_68 = 0x400;

      if (cVar16 == '\x02') {

        iVar14 = 0x3e;

        puVar6 = DAT_00632d98;

        if ((*(uint *)(param_1 + 0xdc) & 0x800000) != 0) {

          for (; puVar6 != (undefined4 *)0x0; puVar6 = (undefined4 *)*puVar6) {

            iVar15 = puVar6[3];

            if ((*(int *)(iVar15 + 0x274) == param_1) &&

               ((*(int *)(iVar15 + 4) == 0xb || (*(int *)(iVar15 + 4) == 0xd8)))) {

              FUN_004034a0(iVar15,0x57,0x20,0,0,0);

              break;

            }

          }

        }

      }

      else if (cVar16 == '\x01') {

        iVar14 = 0x3d;

      }

      goto LAB_00507609;

    }

    if ((iVar2 != 0x3c) || (-*(float *)(DAT_00632ed8 + 0x668) <= *(float *)(param_1 + 0x130))) {

      if ((local_6c & 2) != 0) {

        iVar15 = -2;

        if (-*(float *)(DAT_00632ed8 + 0xc1c) < *(float *)(param_1 + 0x10c) !=

            (-*(float *)(DAT_00632ed8 + 0xc1c) == *(float *)(param_1 + 0x10c))) {

          iVar15 = -1;

        }

        if (-*(float *)(DAT_00632ed8 + 0xc18) < *(float *)(param_1 + 0x10c) !=

            (-*(float *)(DAT_00632ed8 + 0xc18) == *(float *)(param_1 + 0x10c))) {

          iVar15 = iVar15 + 1;

        }

        if (*(float *)(DAT_00632ed8 + 0xc18) < *(float *)(param_1 + 0x10c)) {

          iVar15 = iVar15 + 1;

        }

        if (*(float *)(DAT_00632ed8 + 0xc1c) < *(float *)(param_1 + 0x10c)) {

          iVar15 = iVar15 + 1;

        }

        if (iVar15 == 0) {

          if (-*(float *)(DAT_00632ed8 + 0xc20) <= *(float *)(param_1 + 0x110)) {

            if (*(float *)(param_1 + 0x110) <= *(float *)(DAT_00632ed8 + 0xc20)) {

              local_68 = 0x800;

              if (((*(uint *)(param_1 + 0xe0) & 0x800) == 0) || ((local_6c & 0x200) != 0)) {

                iVar14 = 5;

              }

              else if ((local_6c & 0x80000) != 0) {

                iVar14 = FUN_004d5730(100);

                if (iVar14 < 10) {

                  iVar14 = 8;

                }

                else {

                  iVar14 = (uint)(iVar14 < 0x14) * 4 + 5;

                }

              }

            }

            else {

              iVar14 = 0x3b;

            }

          }

          else {

            iVar14 = 0x3a;

          }

        }

        else {

          iVar14 = iVar15 + 5;

        }

        goto LAB_00507609;

      }

      if ((local_6c & 0x100) != 0) {

        if ((local_6c & 0x10) == 0) {

          if ((local_6c & 0x20) == 0) {

            if (-1 < (char)local_6c) goto LAB_00507609;

            if ((local_6c & 0x100000) == 0) {

              if (iVar3 == 0xb7) {

                if ((~local_6c & 0x80000) == 0) goto LAB_0050731f;

              }

              else if ((*(byte *)(local_48 + 0xd4) & 2) == 0) {

LAB_0050731f:

                local_60 = 3;

                local_68 = 0x8000;

                if ((local_6c & 0x2000) == 0) {

                  if (((*(uint *)(param_1 + 0xe0) & 0x8000) == 0) || ((local_6c & 0x80000) != 0)) {

                    iVar14 = 0x10;

                  }

                }

                else {

                  iVar14 = 0x11;

                }

              }

              else {

                local_88 = 0xb7;

              }

              goto LAB_00507609;

            }

LAB_0050747e:

            local_84 = local_84 | 1;

            local_88 = 0x30;

          }

          else {

            local_60 = 2;

            local_68 = 0x2000;

            if ((local_6c & 0x100000) == 0) {

              if ((local_6c & 0x2000) == 0) {

                if (((*(uint *)(param_1 + 0xe0) & 0x2000) == 0) || ((local_6c & 0x80000) != 0)) {

                  iVar14 = 0x12;

                }

              }

              else {

                iVar14 = 0x13;

              }

            }

            else if (*(float *)(param_1 + 0x110) <= 0.0) {

              iVar14 = 0x42;

            }

            else {

              iVar14 = 0x41;

            }

          }

        }

        else {

          local_60 = 1;

          local_68 = 0x1000;

          if ((local_6c & 0x100000) == 0) {

            if ((local_6c & 0x2000) == 0) {

              if ((*(uint *)(param_1 + 0xe0) & 0x1000) == 0) {

                iVar14 = 0xb;

              }

              else if ((local_6c & 0x80000) != 0) {

                iVar14 = FUN_004d5730(100);

                if (iVar14 < 8) {

                  iVar14 = 0xd;

                }

                else if (iVar14 < 0xf) {

                  iVar14 = 0xe;

                }

                else {

                  iVar14 = (uint)(iVar14 < 0x18) * 4 + 0xb;

                }

              }

            }

            else {

              iVar14 = 0xc;

            }

          }

          else {

            iVar14 = 0x40;

          }

        }

        goto LAB_00507609;

      }

      if (iVar2 != 0x3f) {

        if ((*(byte *)(local_48 + 0xd4) & 8) != 0) {

          iVar14 = 0x3f;

          goto LAB_00507609;

        }

LAB_00507387:

        if (iVar3 == 0xb7) {

          if ((~local_6c & 0x80000) == 0) goto LAB_005073b6;

        }

        else if ((*(byte *)(local_48 + 0xd4) & 2) == 0) {

LAB_005073b6:

          if ((local_6c & 0x200) == 0) {

            if ((local_6c & 0x2000) == 0) {

              if ((local_6c & 0x4000) != 0) {

                if ((local_6c & 0x100000) != 0) goto LAB_0050747e;

                if ((local_6c & 0x20000) == 0) {

                  local_68 = 0x400;

                  iVar14 = 1;

                  if (((*(uint *)(param_1 + 0xe0) & 0x400) != 0) &&

                     (iVar14 = local_80, (local_6c & 0x80000) != 0)) {

                    if ((*(uint *)(param_1 + 0xd8) & 0x800) == 0) {

                      iVar14 = 1;

                      if ((char)(local_6c >> 8) < '\0') {

                        iVar15 = FUN_004d5730(800);

                        if (iVar2 == 0x1c) {

                          local_80 = 0x1d;

                          goto LAB_00507665;

                        }

                        if (iVar15 + -10 < 0) {

                          iVar14 = 0x17;

                        }

                        else if (iVar15 + -0x14 < 0) {

                          iVar14 = 0x18;

                        }

                        else if (iVar15 + -0x1e < 0) {

                          iVar14 = 0x19;

                        }

                        else if (iVar15 + -0x28 < 0) {

                          iVar14 = 0x1a;

                        }

                        else if (iVar15 + -0x32 < 0) {

                          iVar14 = 0x1b;

                        }

                        else {

                          iVar14 = 0x1c;

                          if (-1 < iVar15 + -0x5a) {

                            if (iVar15 + -0x6e < 0) {

                              iVar14 = 0x1e;

                            }

                            else if (iVar15 + -0x78 < 0) {

                              iVar14 = 0x1f;

                            }

                            else if (iVar15 + -0x82 < 0) {

                              iVar14 = 0x20;

                            }

                            else if (iVar15 + -0x8c < 0) {

                              iVar14 = 0x21;

                            }

                            else {

                              iVar14 = ((-1 < iVar15 + -0x96) - 1 & 0x22) + 1;

                            }

                          }

                        }

                      }

                    }

                    else {

                      local_84 = local_84 | 1;

                      local_88 = 0xc9;

                    }

                  }

                }

                else {

                  iVar14 = local_38 + 0x26;

                  local_50 = (&PTR_DAT_0057b3a0)[local_4c + local_38 * 4];

                  local_68 = 0x10000;

                  if (local_50 != (undefined *)0x0) {

                    uVar13 = FUN_004a8fb0(local_40,0);

                    *(undefined4 *)(local_50 + 8) = uVar13;

                    uVar13 = FUN_004a8fb0(iVar15,1);

                    *(undefined4 *)(local_50 + 0x28) = uVar13;

                  }

                }

              }

            }

            else if (((*(uint *)(param_1 + 0xe0) & 0x4000) == 0) || ((local_6c & 0x80000) != 0)) {

              iVar14 = 0x14;

            }

          }

          else {

            local_68 = 0x4000;

            if (local_40 == 4) {

              iVar14 = 0x14;

            }

            else {

              local_44 = 1;

              local_3c = 0;

              if ((local_6c & 0x400) == 0) {

                if (local_40 == 5) {

                  local_84 = local_84 | 1;

                  local_88 = 0xa5;

                  local_44 = 0;

                }

                else if (local_40 == 7) {

                  local_88 = 0x15;

                }

                else if (local_40 == 6) {

                  local_88 = 0x14;

                }

                else {

                  iVar14 = 0x15;

                }

              }

              else {

                iVar14 = 0x16;

              }

            }

          }

        }

        else {

          local_88 = 0xb7;

        }

        goto LAB_00507609;

      }

      if ((~local_6c & 0x80000) == 0) goto LAB_00507387;

      goto LAB_00507665;

    }

  }

  else {

    bVar17 = true;

    if ((iVar3 != 0x88) &&

       ((10.0 < *(float *)(param_1 + 0x130) ||

        (10.0 < (*(float *)(param_1 + 0xa8) -

                *(float *)(param_1 + 0x1d4) * *(float *)(param_1 + 0xc4)) -

                *(float *)(param_1 + 0x140))))) {

      local_88 = 0x88;

      local_84 = 0x21;

    }

    iVar7 = local_88;

    if ((*(uint *)(param_1 + 0xd8) & 0x80000) != 0) {

      *(uint *)(param_1 + 0xe0) = uVar9 & 0xfffffffe;

      bVar17 = false;

    }

LAB_00506977:

    local_88 = iVar7;

    iVar15 = local_80;

    if ((local_88 < 0) && (!bVar17)) goto LAB_0050698f;

LAB_005075f7:

    local_80 = iVar15;

    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xfffe03ff;

    iVar7 = local_48;

    iVar14 = local_80;

LAB_00507609:

    local_80 = iVar14;

    if (iVar2 != 0x3c) {

LAB_00507665:

      if (*(int *)(iVar7 + 0x1a8) != 0) {

        FUN_00448920(*(int *)(iVar7 + 0x1a8));

      }

      *(undefined4 *)(iVar7 + 0x1a8) = 0;

      ANM_DumpCluster(param_1,9);

      goto LAB_0050768d;

    }

  }

  local_80 = iVar14;

  if (*(int *)(iVar7 + 0x1a8) == 0) {

    puVar23 = local_34;

    uVar22 = 0x24;

    pcVar21 = s_FX_mecc_slide_0057b854;

    local_1c = param_1;

    local_20 = 0xffffffff;

    local_24 = 8;

    uVar13 = fx_get_free_effect__Fv();

    *(undefined4 *)(iVar7 + 0x1a8) = uVar13;

    ANM_DumpCluster(param_1,9,pcVar21,uVar22,puVar23);

  }

LAB_0050768d:

  if (*(int *)(iVar7 + 0x1e0) == 0) {

    if ((((*(uint *)(param_1 + 0xe0) & 0x2000000) != 0) && (*(int *)(param_1 + 0x174) == 0)) &&

       ((2.0 < ABS(*(float *)(param_1 + 0x128)) ||

        ((2.0 < ABS(*(float *)(param_1 + 300)) || (2.0 < ABS(*(float *)(param_1 + 0x130)))))))) {

      sound_play_player(0x574,param_1);

      *(undefined4 *)(iVar7 + 0x1e0) = 1;

    }

  }

  else if (((*(uint *)(param_1 + 0xe0) & 0x2000000) == 0) ||

          (((ABS(*(float *)(param_1 + 0x128)) < 2.0 != (ABS(*(float *)(param_1 + 0x128)) == 2.0) &&

            (ABS(*(float *)(param_1 + 300)) < 2.0 != (ABS(*(float *)(param_1 + 300)) == 2.0))) &&

           (ABS(*(float *)(param_1 + 0x130)) < 2.0 != (ABS(*(float *)(param_1 + 0x130)) == 2.0)))))

  {

    FUN_00495700(0x574,param_1);

    *(undefined4 *)(iVar7 + 0x1e0) = 0;

  }

  if ((-1 < local_80) && (*(int *)(&DAT_0057a940 + (local_4c + local_80 * 4) * 8) != 0xfe)) {

    local_88 = *(int *)(&DAT_0057a940 + (local_4c + local_80 * 4) * 8);

  }

  if ((-1 < local_88) && ((iVar3 != local_88 || (local_44 != 0)))) {

    switch(local_60) {

    case 0:

      fVar1 = -160.0;

      break;

    case 1:

      fVar1 = 30.0;

      break;

    case 2:

      fVar1 = -40.0;

      break;

    case 3:

      fVar1 = -321.0;

      break;

    default:

      fVar1 = 0.0;

    }

    if (-1 < local_80) {

      local_84 = local_84 | *(uint *)(&DAT_0057a944 + (local_4c + local_80 * 4) * 8);

    }

    FUN_004034a0(param_1,local_88,local_84,local_60,fVar1 * *(float *)(param_1 + 0xc4),local_3c);

    if ((*(uint *)(param_1 + 0xe0) & 0x10000) != 0) {

      FUN_00458230(param_1);

    }

    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xfffe03ff | local_68;

    *(undefined4 *)(iVar7 + 0xd0) = 0;

    *(undefined **)(iVar7 + 0x7c) = local_50;

    *(int *)(iVar7 + 0x30) = local_80;

    *(uint *)(iVar7 + 0xd4) = *(uint *)(iVar7 + 0xd4) ^ 1;

  }

  if (((((local_6c & 0x200) != 0) &&

       (iVar14 = *(int *)(param_1 + 8) + 8, *(float *)(param_1 + 0x2c) != 0.0)) &&

      ((~*(uint *)(*(int *)(iVar14 + *(int *)(param_1 + 0x58) * 4) + 8) & 4) != 0)) &&

     ((*(byte *)(*(int *)(iVar14 + *(int *)(param_1 + 0x10) * 4) + 8) & 4) != 0)) {

    *(undefined4 *)(param_1 + 0x2c) = 0;

  }

  if (((local_6c & 0x20000) != 0) &&

     (((*(uint *)(param_1 + 0xe0) & 0x10000) == 0 || ((local_6c & 0x80000) != 0)))) {

    FUN_00458230(param_1);

  }

  return;

}

/* ===== FUN_00507b00 @ 0x00507B00 ===== */
/* PS2 candidate: TextGetPtr (conf 0.7) */



undefined * FUN_00507b00(undefined *param_1)



{

  int iVar1;

  

  if (param_1 == (undefined *)0x0) {

    return &DAT_0057bce0;

  }

  if (DAT_0057bc78 != 0) {

    TextPtrInit__Fv();

  }

  iVar1 = FUN_005393e0(DAT_0057bc94,param_1);

  if (iVar1 != 0) {

    return *(undefined **)(iVar1 + 4);

  }

  return param_1;

}

/* ===== TextGetPtrRandom @ 0x00507B40 ===== */
/* PS2 candidate: TextGetPtrRandom (conf 0.8) */



undefined * TextGetPtrRandom(undefined *param_1)



{

  int iVar1;

  int iVar2;

  undefined4 uVar3;

  int iVar4;

  undefined1 local_100 [256];

  

  if (param_1 == (undefined *)0x0) {

    return &DAT_0057bce0;

  }

  if (DAT_0057bc78 != 0) {

    TextPtrInit__Fv();

  }

  iVar1 = FUN_005393e0(DAT_0057bc94,param_1);

  if (iVar1 != 0) {

    return *(undefined **)(iVar1 + 4);

  }

  iVar1 = 1;

  iVar4 = 1;

  do {

    FUN_00542f27(local_100,&DAT_0055c8ac,param_1,iVar4);

    iVar2 = FUN_005393e0(DAT_0057bc94,local_100);

    if (iVar2 == 0) break;

    iVar1 = iVar1 + 1;

    iVar4 = iVar4 + 1;

  } while (iVar4 < 10);

  uVar3 = FUN_004d5740(1,iVar1 + -1);

  FUN_00542f27(local_100,&DAT_0055c8ac,param_1,uVar3);

  iVar1 = FUN_005393e0(DAT_0057bc94,local_100);

  if (iVar1 != 0) {

    return *(undefined **)(iVar1 + 4);

  }

  return param_1;

}

/* ===== TextGetPtrQ @ 0x00507C10 ===== */
/* PS2 candidate: TextGetPtrQ (conf 0.75) */



undefined * TextGetPtrQ(undefined1 *param_1)



{

  int iVar1;

  undefined1 *puVar2;

  

  if (param_1 == (undefined1 *)0x0) {

    return &DAT_0057bce0;

  }

  if (DAT_0057bc78 != 0) {

    TextPtrInit__Fv();

  }

  iVar1 = FUN_005393e0(DAT_0057bc94,param_1);

  if ((iVar1 == 0) || (puVar2 = *(undefined1 **)(iVar1 + 4), puVar2 == param_1)) {

    puVar2 = &DAT_005561ac;

  }

  return puVar2;

}

/* ===== endDisplay__Fv_3 @ 0x00507E40 ===== */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */



void endDisplay__Fv_3(void)



{

  DAT_005a8844 = 0;

  DAT_005a8848 = 0;

  return;

}

/* ===== main/texture_00507f80 @ 0x00507F80 ===== */
/* PS2 candidate: texture_set_global (conf 0.636) */



void main_texture_00507f80(void)



{

  undefined4 *puVar1;

  undefined4 *puVar2;

  

  if (DAT_005a8844 != (undefined4 *)0x0) {

    puVar2 = (undefined4 *)*DAT_005a8844;

    DAT_005a884c = DAT_005a8844;

    while (puVar1 = puVar2, puVar1 != (undefined4 *)0x0) {

      DAT_005a884c = puVar1;

      puVar2 = (undefined4 *)*puVar1;

    }

  }

  return;

}

/* ===== main/texture_00508720 @ 0x00508720 ===== */
void main_texture_00508720(int param_1)



{

  if ((*(int *)(param_1 + 0x14) == 8) && ((*(byte *)(param_1 + 0x1e) & 8) == 0)) {

    main_texture_005080a0(param_1,0);

  }

  return;

}

/* ===== main_00508840 @ 0x00508840 ===== */
void main_00508840(undefined4 param_1)



{

  (**(code **)(DAT_00656420 + 0xb4))(DAT_00656420,param_1);

  return;

}

/* ===== main/texture_00508860 @ 0x00508860 ===== */
void main_texture_00508860(void)



{

  undefined4 *puVar1;

  undefined4 *puVar2;

  uint uVar3;

  

  for (puVar1 = DAT_005a8844; puVar2 = DAT_005a8848, puVar1 != (undefined4 *)0x0;

      puVar1 = (undefined4 *)*puVar1) {

    uVar3 = 0;

    if (puVar1[10] != 0) {

      puVar2 = puVar1 + 0xb;

      do {

        (**(code **)(DAT_00656420 + 0xb4))(DAT_00656420,puVar2);

        uVar3 = uVar3 + 1;

        puVar2 = puVar2 + 9;

      } while (uVar3 < (uint)puVar1[10]);

    }

  }

  for (; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {

    (**(code **)(DAT_00656420 + 0xb4))(DAT_00656420,puVar2 + 1);

  }

  return;

}

/* ===== FUN_00508fa0 @ 0x00508FA0 ===== */
/* PS2 candidate: objspec_has_shot_function_3 (conf 0.554) */



undefined4 FUN_00508fa0(int param_1)



{

  if (*(int *)(param_1 + 0x18) < 8) {

    return *(undefined4 *)(&DAT_0057bce8 + *(int *)(param_1 + 0x18) * 4);

  }

  return 0;

}

/* ===== FUN_005093e0 @ 0x005093E0 ===== */
/* PS2 candidate: ripper_control__FP6OBJECT (conf 0.458) */



void FUN_005093e0(float param_1)



{

  int iVar1;

  int iVar2;

  int *piVar3;

  int iVar4;

  float10 fVar5;

  float10 fVar6;

  float local_c;

  float local_8;

  float local_4;

  

  iVar2 = (int)param_1;

  iVar4 = 0;

  local_c = -1.0;

  piVar3 = DAT_00632d8c;

  if (DAT_00632d8c != (int *)0x0) {

    do {

      iVar1 = piVar3[3];

      if ((((*(int *)(iVar1 + 0x274) != 0) && (*(int *)(iVar1 + 0xe4) == 2)) &&

          (fVar5 = (float10)FUN_0050a5e0((int)param_1 + 0xa0,iVar1 + 0xa0),

          fVar5 <= (float10)*(float *)(DAT_00632ed8 + 0x310) *

                   (float10)*(float *)(DAT_00632ed8 + 0x310))) &&

         ((fVar5 < (float10)local_c || (local_c < 0.0)))) {

        local_c = (float)fVar5;

        iVar4 = iVar1;

      }

      piVar3 = (int *)*piVar3;

    } while (piVar3 != (int *)0x0);

    if (iVar4 != 0) {

      if ((*(uint *)((int)param_1 + 0xd8) & 0x80000000) == 0) {

        fVar5 = (float10)FUN_004d5780(0,0x3f800000);

        fVar6 = (float10)FUN_00518b70(param_1,0);

        if (fVar6 * (float10)0.75 < (float10)(float)fVar5 !=

            (fVar6 * (float10)0.75 == (float10)(float)fVar5)) {

          return;

        }

      }

      *(uint *)((int)param_1 + 0xd8) = *(uint *)((int)param_1 + 0xd8) | 0x80000000;

      param_1 = local_c / *(float *)(DAT_00632ed8 + 0x324) + *(float *)(DAT_00632ed8 + 0x330);

      if (*(float *)(DAT_00632ed8 + 0x328) < param_1) {

        param_1 = *(float *)(DAT_00632ed8 + 0x328);

      }

      fVar5 = (float10)FUN_004d5760(0x42960000);

      fVar6 = (float10)FUN_0050a400(iVar4 + 0xa0,iVar2 + 0xa0);

      FUN_0050ae40((float)((float10)*(float *)(DAT_00632ed8 + 0x32c) + fVar6),&local_8,&local_4);

      if ((*(uint *)(iVar2 + 0xd8) & 0x80000) == 0) {

        *(uint *)(iVar2 + 0xd8) = *(uint *)(iVar2 + 0xd8) | 0x80000000;

        *(float *)(iVar2 + 0x128) = local_8 * (float)(fVar5 + (float10)param_1);

        *(float *)(iVar2 + 300) = -(local_4 * (float)(fVar5 + (float10)param_1));

      }

      if (*(int *)(iVar2 + 0x104) == 0) {

        if (*(float *)(iVar2 + 0x108) < *(float *)(DAT_00632ed8 + 0x334)) {

          *(float *)(iVar2 + 0x108) = *(float *)(DAT_00632ed8 + 0x334) + *(float *)(iVar2 + 0x108);

        }

      }

      else if (*(float *)(iVar2 + 0x130) < *(float *)(DAT_00632ed8 + 0x334)) {

        *(float *)(iVar2 + 0x130) = *(float *)(DAT_00632ed8 + 0x334) + *(float *)(iVar2 + 0x130);

        return;

      }

    }

  }

  return;

}

/* ===== FUN_005095e0 @ 0x005095E0 ===== */
void FUN_005095e0(int param_1,int param_2,float param_3)



{

  undefined4 *puVar1;

  float fVar2;

  float fVar3;

  char cVar4;

  ushort uVar5;

  int iVar6;

  undefined4 *puVar7;

  float *pfVar8;

  ushort *puVar9;

  undefined1 *puVar10;

  float fStack_14;

  int local_10;

  int local_c;

  int local_8;

  int local_4;

  

  local_c = *(int *)(param_2 + 0x14);

  if (local_c != 0) {

    local_8 = (int)param_3 * 0x50 + param_2;

    iVar6 = *(int *)(local_8 + 0x88);

    local_10 = *(int *)(local_8 + 0x8c);

    local_4 = iVar6;

    puVar7 = (undefined4 *)(**(code **)(DAT_0065644c + 0x10))(DAT_0065644c,local_10);

    puVar9 = (ushort *)(*(int *)(param_2 + 0x34) + iVar6 * 2);

    pfVar8 = (float *)(*(int *)(param_2 + 0x3c) + iVar6 * 8);

    puVar10 = (undefined1 *)(iVar6 * 3 + *(int *)(param_2 + 0x40));

    cVar4 = **(char **)(local_8 + 0x74);

    if (cVar4 == 'a') {

      FUN_0050ae40(*(float *)(DAT_00632ed8 + 0x338) * *(float *)(param_1 + 0xf0) * 360.0,&fStack_14,

                   &param_3);

      if (0 < local_10) {

        param_1 = local_10;

        do {

          uVar5 = *puVar9;

          puVar9 = puVar9 + 1;

          puVar1 = (undefined4 *)(local_c + (uint)uVar5 * 0xc);

          *puVar7 = *puVar1;

          puVar7[1] = puVar1[1];

          puVar7[2] = puVar1[2];

          puVar7[3] = (uint)CONCAT21(CONCAT11(*puVar10,puVar10[1]),puVar10[2]);

          fVar2 = *pfVar8;

          fVar3 = pfVar8[1];

          param_1 = param_1 + -1;

          puVar7[4] = (fVar2 - 0.5) * param_3 + fStack_14 * (fVar3 - 0.5) + 0.5;

          puVar7[5] = ((fVar3 - 0.5) * param_3 - (fVar2 - 0.5) * fStack_14) + 0.5;

          pfVar8 = pfVar8 + 2;

          puVar7 = puVar7 + 6;

          puVar10 = puVar10 + 3;

        } while (param_1 != 0);

      }

    }

    else if (cVar4 == 'c') {

      FUN_0050ae40(*(float *)(DAT_00632ed8 + 0x34c) * *(float *)(param_1 + 0xf0) * 360.0,&fStack_14,

                   &param_3);

      if (0 < local_10) {

        param_1 = local_10;

        do {

          uVar5 = *puVar9;

          puVar9 = puVar9 + 1;

          puVar1 = (undefined4 *)(local_c + (uint)uVar5 * 0xc);

          *puVar7 = *puVar1;

          puVar7[1] = puVar1[1];

          puVar7[2] = puVar1[2];

          puVar7[3] = (uint)CONCAT21(CONCAT11(*puVar10,puVar10[1]),puVar10[2]);

          fVar2 = *pfVar8;

          fVar3 = pfVar8[1];

          param_1 = param_1 + -1;

          puVar7[4] = (fVar2 - 0.5) * param_3 + fStack_14 * (fVar3 - 0.5) + 0.5;

          puVar7[5] = ((fVar3 - 0.5) * param_3 - (fVar2 - 0.5) * fStack_14) + 0.5;

          pfVar8 = pfVar8 + 2;

          puVar7 = puVar7 + 6;

          puVar10 = puVar10 + 3;

        } while (param_1 != 0);

      }

    }

    else if (cVar4 == 'd') {

      FUN_0050ae40(*(float *)(DAT_00632ed8 + 0x350) * *(float *)(param_1 + 0xf0) * 360.0,&fStack_14,

                   &param_3);

      if (0 < local_10) {

        param_1 = local_10;

        do {

          uVar5 = *puVar9;

          puVar9 = puVar9 + 1;

          puVar1 = (undefined4 *)(local_c + (uint)uVar5 * 0xc);

          *puVar7 = *puVar1;

          puVar7[1] = puVar1[1];

          puVar7[2] = puVar1[2];

          puVar7[3] = (uint)CONCAT21(CONCAT11(*puVar10,puVar10[1]),puVar10[2]);

          fVar2 = *pfVar8;

          fVar3 = pfVar8[1];

          param_1 = param_1 + -1;

          puVar7[4] = (fVar2 - 0.5) * param_3 + fStack_14 * (fVar3 - 0.5) + 0.5;

          puVar7[5] = ((fVar3 - 0.5) * param_3 - (fVar2 - 0.5) * fStack_14) + 0.5;

          pfVar8 = pfVar8 + 2;

          puVar7 = puVar7 + 6;

          puVar10 = puVar10 + 3;

        } while (param_1 != 0);

      }

    }

    else {

      cVar4 = (*(char **)(local_8 + 0x74))[9];

      if (cVar4 == '1') {

        FUN_0050ae40(*(float *)(DAT_00632ed8 + 0x33c) * *(float *)(param_1 + 0xf0) * 360.0,

                     &fStack_14,&param_3);

        if (0 < local_10) {

          param_1 = local_10;

          do {

            uVar5 = *puVar9;

            puVar9 = puVar9 + 1;

            puVar1 = (undefined4 *)(local_c + (uint)uVar5 * 0xc);

            *puVar7 = *puVar1;

            puVar7[1] = puVar1[1];

            puVar7[2] = puVar1[2];

            *(undefined1 *)(puVar7 + 3) = puVar10[2];

            *(undefined1 *)((int)puVar7 + 0xd) = puVar10[1];

            *(undefined1 *)((int)puVar7 + 0xe) = *puVar10;

            fVar2 = *pfVar8;

            fVar3 = pfVar8[1];

            param_1 = param_1 + -1;

            puVar7[4] = (fVar2 - 0.5) * param_3 + fStack_14 * (fVar3 - 0.5) + 0.5;

            puVar7[5] = ((fVar3 - 0.5) * param_3 - (fVar2 - 0.5) * fStack_14) + 0.5;

            pfVar8 = pfVar8 + 2;

            puVar7 = puVar7 + 6;

            puVar10 = puVar10 + 3;

          } while (param_1 != 0);

        }

      }

      else if (cVar4 == '2') {

        if (0 < local_10) {

          param_2 = local_10;

          do {

            uVar5 = *puVar9;

            puVar9 = puVar9 + 1;

            puVar1 = (undefined4 *)(local_c + (uint)uVar5 * 0xc);

            *puVar7 = *puVar1;

            puVar7[1] = puVar1[1];

            puVar7[2] = puVar1[2];

            *(undefined1 *)(puVar7 + 3) = puVar10[2];

            *(undefined1 *)((int)puVar7 + 0xd) = puVar10[1];

            *(undefined1 *)((int)puVar7 + 0xe) = *puVar10;

            param_2 = param_2 + -1;

            puVar7[4] = *(float *)(DAT_00632ed8 + 0x340) * *(float *)(param_1 + 0xf0) + *pfVar8;

            puVar7[5] = pfVar8[1];

            pfVar8 = pfVar8 + 2;

            puVar7 = puVar7 + 6;

            puVar10 = puVar10 + 3;

          } while (param_2 != 0);

        }

      }

      else if (cVar4 == '3') {

        if (0 < local_10) {

          param_2 = local_10;

          do {

            uVar5 = *puVar9;

            puVar9 = puVar9 + 1;

            puVar1 = (undefined4 *)(local_c + (uint)uVar5 * 0xc);

            *puVar7 = *puVar1;

            puVar7[1] = puVar1[1];

            puVar7[2] = puVar1[2];

            *(undefined1 *)(puVar7 + 3) = puVar10[2];

            *(undefined1 *)((int)puVar7 + 0xd) = puVar10[1];

            *(undefined1 *)((int)puVar7 + 0xe) = *puVar10;

            param_2 = param_2 + -1;

            puVar7[4] = *(float *)(DAT_00632ed8 + 0x344) * *(float *)(param_1 + 0xf0) + *pfVar8;

            puVar7[5] = pfVar8[1];

            pfVar8 = pfVar8 + 2;

            puVar7 = puVar7 + 6;

            puVar10 = puVar10 + 3;

          } while (param_2 != 0);

        }

      }

      else if ((cVar4 == '4') && (0 < local_10)) {

        param_2 = local_10;

        do {

          uVar5 = *puVar9;

          puVar9 = puVar9 + 1;

          puVar1 = (undefined4 *)(local_c + (uint)uVar5 * 0xc);

          *puVar7 = *puVar1;

          puVar7[1] = puVar1[1];

          puVar7[2] = puVar1[2];

          *(undefined1 *)(puVar7 + 3) = puVar10[2];

          *(undefined1 *)((int)puVar7 + 0xd) = puVar10[1];

          *(undefined1 *)((int)puVar7 + 0xe) = *puVar10;

          param_2 = param_2 + -1;

          puVar7[4] = *(float *)(DAT_00632ed8 + 0x348) * *(float *)(param_1 + 0xf0) + *pfVar8;

          puVar7[5] = pfVar8[1];

          pfVar8 = pfVar8 + 2;

          puVar7 = puVar7 + 6;

          puVar10 = puVar10 + 3;

        } while (param_2 != 0);

      }

    }

    (**(code **)(DAT_0065644c + 0x18))(DAT_0065644c,-local_4);

  }

  return;

}

/* ===== tracer_add_ref @ 0x00509B80 ===== */
void tracer_add_ref(int param_1)



{

  *(int *)(param_1 + 0x40) = *(int *)(param_1 + 0x40) + 1;

  return;

}

/* ===== MAP_MemGroupSetBase_3 @ 0x00509DC0 ===== */
void MAP_MemGroupSetBase_3(int param_1,undefined4 param_2)



{

  *(undefined4 *)(param_1 + 0x1c) = param_2;

  return;

}

/* ===== main/tracer_00509dd0 @ 0x00509DD0 ===== */
void main_tracer_00509dd0(void)



{

  float *pfVar1;

  int *piVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int *piVar6;

  int iVar7;

  

  piVar6 = &DAT_00632dc8;

  do {

    piVar2 = (int *)*piVar6;

    if ((piVar2 != (int *)0x0) && (1 < *piVar2)) {

      iVar4 = piVar2[2];

      iVar5 = 0;

      if (0 < *piVar2) {

        do {

          iVar3 = iVar4 * 0x24;

          *(float *)(iVar3 + 0x1c + piVar2[3]) = DAT_006328e0 + *(float *)(iVar3 + 0x1c + piVar2[3])

          ;

          iVar7 = iVar3 + piVar2[3];

          if ((float)piVar2[4] <= *(float *)(iVar3 + 0x1c + piVar2[3])) {

            *piVar2 = iVar5;

            break;

          }

          if ((float)piVar2[5] < *(float *)(iVar7 + 0x1c)) {

            *(float *)(iVar7 + 0x18) =

                 (*(float *)(iVar7 + 0x1c) - (float)piVar2[5]) * (float)piVar2[6];

          }

          iVar4 = iVar4 + -1;

          pfVar1 = (float *)(iVar3 + 0xc + piVar2[3]);

          *pfVar1 = (((float)piVar2[0xb] - (float)piVar2[8]) / (float)piVar2[4]) * DAT_006328e0 +

                    *pfVar1;

          pfVar1 = (float *)(iVar3 + 0x10 + piVar2[3]);

          *pfVar1 = (((float)piVar2[0xc] - (float)piVar2[9]) / (float)piVar2[4]) * DAT_006328e0 +

                    *pfVar1;

          pfVar1 = (float *)(iVar3 + 0x14 + piVar2[3]);

          *pfVar1 = (((float)piVar2[0xd] - (float)piVar2[10]) / (float)piVar2[4]) * DAT_006328e0 +

                    *pfVar1;

          if (iVar4 < 0) {

            iVar4 = piVar2[1] + -1;

          }

          iVar5 = iVar5 + 1;

        } while (iVar5 < *piVar2);

      }

      iVar4 = piVar2[2];

      iVar5 = 0;

      if (*piVar2 != 1 && -1 < *piVar2 + -1) {

        do {

          iVar7 = iVar4 + -1;

          if (iVar7 < 0) {

            iVar7 = piVar2[1] + -1;

          }

          iVar3 = piVar2[3] + iVar7 * 0x24;

          main_tracer_00509f10(iVar3,piVar2[7],piVar2[0xf],piVar2[3] + iVar4 * 0x24,iVar3);

          iVar5 = iVar5 + 1;

          iVar4 = iVar7;

        } while (iVar5 < *piVar2 + -1);

      }

    }

    piVar6 = piVar6 + 1;

    if (0x632e3f < (int)piVar6) {

      return;

    }

  } while( true );

}

/* ===== main/tracer_00509f10 @ 0x00509F10 ===== */
void main_tracer_00509f10

               (undefined4 param_1,undefined4 param_2,float param_3,undefined4 param_4,

               undefined4 param_5)



{

  float fVar1;

  float fVar2;

  float fVar3;

  uint uVar4;

  int iVar5;

  undefined1 **ppuVar6;

  float *pfVar7;

  undefined1 *puStack_118;

  undefined1 *puStack_114;

  float fStack_f8;

  float fStack_f4;

  undefined4 uStack_f0;

  float fStack_ec;

  float fStack_e8;

  undefined4 uStack_e4;

  float afStack_e0 [4];

  float fStack_d0;

  undefined4 uStack_cc;

  uint uStack_b8;

  undefined1 auStack_a8 [12];

  float fStack_9c;

  float fStack_98;

  undefined4 uStack_94;

  uint uStack_80;

  undefined1 auStack_70 [12];

  float fStack_64;

  float fStack_60;

  undefined4 uStack_5c;

  uint uStack_48;

  undefined1 auStack_38 [12];

  float fStack_2c;

  float fStack_28;

  undefined4 uStack_24;

  uint uStack_10;

  

  __ftol();

  puStack_114 = (undefined1 *)0x403a0;

  puStack_118 = DAT_0065642c;

  ppuVar6 = &puStack_118;

  (**(code **)(DAT_0065642c + 8))();

  xform_view(param_4,&fStack_ec);

  xform_view(param_5,&fStack_f8);

  fVar1 = fStack_e8 - fStack_f4;

  fVar2 = fStack_f8 - fStack_ec;

  fVar3 = fVar1 * fVar1 + fVar2 * fVar2;

  if (0.1 <= fVar3) {

    fVar1 = (1.0 / SQRT(fVar3)) * fVar1;

    fVar2 = (1.0 / SQRT(fVar3)) * fVar2;

  }

  else {

    if (fVar3 == 0.0) {

      return;

    }

    fVar1 = 0.0;

    fVar2 = 1.0;

  }

  fVar1 = fVar1 * param_3;

  pfVar7 = afStack_e0;

  for (iVar5 = 0x38; iVar5 != 0; iVar5 = iVar5 + -1) {

    *pfVar7 = 0.0;

    pfVar7 = pfVar7 + 1;

  }

  fVar2 = fVar2 * param_3;

  fStack_d0 = fStack_e8 + fVar2;

  uStack_cc = uStack_e4;

  uStack_94 = uStack_e4;

  uStack_5c = uStack_f0;

  uStack_24 = uStack_f0;

  fStack_9c = fStack_ec - fVar1;

  fStack_98 = fStack_e8 - fVar2;

  fStack_64 = fVar1 + fStack_f8;

  fStack_60 = fStack_f4 + fVar2;

  fStack_2c = fStack_f8 - fVar1;

  fStack_28 = fStack_f4 - fVar2;

  puStack_114 = (undefined1 *)0x50a093;

  afStack_e0[3] = fVar1 + fStack_ec;

  iVar5 = __ftol();

  puStack_114 = (undefined1 *)0x50a0a6;

  uVar4 = __ftol();

  puStack_114 = (undefined1 *)0x50a0b9;

  uStack_b8 = __ftol();

  uStack_b8 = (iVar5 << 8 | uVar4) << 8 | uStack_b8;

  iVar5 = 4;

  uStack_80 = uStack_b8;

  uStack_48 = uStack_b8;

  uStack_10 = uStack_b8;

  do {

    ppuVar6 = (undefined1 **)((int)ppuVar6 + 0x38);

    puStack_118 = (undefined1 *)0x50a0e6;

    puStack_114 = (undefined1 *)ppuVar6;

    FUN_00516c70();

    puStack_118 = (undefined1 *)ppuVar6;

    FUN_00516cf0();

    iVar5 = iVar5 + -1;

  } while (iVar5 != 0);

  puStack_114 = auStack_70;

  puStack_118 = auStack_a8;

  FUN_0042f8e0(afStack_e0);

  FUN_0042f8e0(auStack_a8,auStack_38,auStack_70);

  FUN_0042f8e0(afStack_e0,auStack_70,auStack_a8);

  FUN_0042f8e0(auStack_a8,auStack_70,auStack_38);

  return;

}

/* ===== FUN_0050a390 @ 0x0050A390 ===== */
/* PS2 candidate: atand2pos (conf 0.338) */



float10 FUN_0050a390(float param_1,float param_2)



{

  float10 fVar1;

  

  if ((param_2 == 0.0) && (param_1 == 0.0)) {

    return (float10)0.0;

  }

  fVar1 = (float10)fpatan((float10)param_1,(float10)param_2);

  fVar1 = fVar1 * (float10)57.295776;

  if (fVar1 < (float10)0.0) {

    fVar1 = fVar1 + (float10)360.0;

  }

  if ((float10)359.99 < fVar1) {

    fVar1 = (float10)0.0;

  }

  return fVar1;

}

/* ===== FUN_0050a400 @ 0x0050A400 ===== */
/* PS2 candidate: dirfcalcp3d__FP3P3DT0 (conf 0.503) */



float10 FUN_0050a400(float *param_1,float *param_2)



{

  float10 fVar1;

  

  if (((float10)*param_2 - (float10)*param_1 == (float10)0.0) &&

     ((float10)param_2[1] - (float10)param_1[1] == (float10)0.0)) {

    return (float10)90.0;

  }

  fVar1 = (float10)fpatan((float10)param_2[1] - (float10)param_1[1],

                          (float10)*param_2 - (float10)*param_1);

  fVar1 = fVar1 * (float10)57.295776 + (float10)90.0;

  if ((float10)360.0 < fVar1) {

    fVar1 = fVar1 - (float10)360.0;

  }

  if (fVar1 < (float10)0.0) {

    fVar1 = fVar1 + (float10)360.0;

  }

  if ((float10)359.99 < fVar1) {

    fVar1 = (float10)0.0;

  }

  return fVar1;

}

/* ===== FUN_0050a490 @ 0x0050A490 ===== */
/* PS2 candidate: dirucalcp3d__FP3P3DT0 (conf 0.469) */



float10 FUN_0050a490(float *param_1,float *param_2)



{

  float10 fVar1;

  

  fVar1 = SQRT(((float10)param_2[1] - (float10)param_1[1]) *

               ((float10)param_2[1] - (float10)param_1[1]) +

               ((float10)*param_2 - (float10)*param_1) * ((float10)*param_2 - (float10)*param_1));

  if ((fVar1 == (float10)0.0) && ((float10)param_2[2] - (float10)param_1[2] == (float10)0.0)) {

    return (float10)0.0;

  }

  fVar1 = (float10)fpatan((float10)param_2[2] - (float10)param_1[2],fVar1);

  return fVar1 * (float10)57.295776;

}

/* ===== FUN_0050a4f0 @ 0x0050A4F0 ===== */
/* PS2 candidate: GetGiantsMemCard__Fv (conf 0.563) */



float10 FUN_0050a4f0(void)



{

  float10 fVar1;

  

  fVar1 = (float10)FUN_00544ac0();

  return fVar1 * (float10)57.295776;

}

/* ===== FUN_0050a500 @ 0x0050A500 ===== */
float10 FUN_0050a500(float *param_1)



{

  return SQRT((float10)param_1[1] * (float10)param_1[1] + (float10)*param_1 * (float10)*param_1);

}

/* ===== FUN_0050a520 @ 0x0050A520 ===== */
/* PS2 candidate: distance2d__FP3P3DT0 (conf 0.327) */



float10 FUN_0050a520(float *param_1,float *param_2)



{

  return SQRT(((float10)param_2[1] - (float10)param_1[1]) *

              ((float10)param_2[1] - (float10)param_1[1]) +

              ((float10)*param_2 - (float10)*param_1) * ((float10)*param_2 - (float10)*param_1));

}

/* ===== FUN_0050a550 @ 0x0050A550 ===== */
float10 FUN_0050a550(float *param_1)



{

  return SQRT((float10)param_1[2] * (float10)param_1[2] +

              (float10)param_1[1] * (float10)param_1[1] + (float10)*param_1 * (float10)*param_1);

}

/* ===== FUN_0050a580 @ 0x0050A580 ===== */
/* PS2 candidate: distance3d__FP3P3DT0 (conf 0.559) */



float10 FUN_0050a580(float *param_1,float *param_2)



{

  return SQRT(((float10)param_2[2] - (float10)param_1[2]) *

              ((float10)param_2[2] - (float10)param_1[2]) +

              ((float10)param_2[1] - (float10)param_1[1]) *

              ((float10)param_2[1] - (float10)param_1[1]) +

              ((float10)*param_2 - (float10)*param_1) * ((float10)*param_2 - (float10)*param_1));

}

/* ===== FUN_0050a5c0 @ 0x0050A5C0 ===== */
float10 FUN_0050a5c0(float *param_1)



{

  return (float10)param_1[1] * (float10)param_1[1] + (float10)*param_1 * (float10)*param_1;

}

/* ===== FUN_0050a5e0 @ 0x0050A5E0 ===== */
/* PS2 candidate: distancesq2d__FP3P3DT0 (conf 0.599) */



float10 FUN_0050a5e0(float *param_1,float *param_2)



{

  return ((float10)param_2[1] - (float10)param_1[1]) * ((float10)param_2[1] - (float10)param_1[1]) +

         ((float10)*param_2 - (float10)*param_1) * ((float10)*param_2 - (float10)*param_1);

}

/* ===== FUN_0050a610 @ 0x0050A610 ===== */
/* PS2 candidate: distancesq3d__FP3P3DT0 (conf 0.613) */



void FUN_0050a610(void)



{

  return;

}

/* ===== FUN_0050a640 @ 0x0050A640 ===== */
/* PS2 candidate: tri_to_plane__FP3P3DN20P7PLANE3D (conf 0.55) */



void FUN_0050a640(float *param_1,float *param_2,float *param_3,float *param_4)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  

  fVar4 = (param_3[2] - param_1[2]) * (param_2[1] - param_1[1]) -

          (param_3[1] - param_1[1]) * (param_2[2] - param_1[2]);

  fVar5 = (*param_3 - *param_1) * (param_2[2] - param_1[2]) -

          (*param_2 - *param_1) * (param_3[2] - param_1[2]);

  fVar6 = (*param_2 - *param_1) * (param_3[1] - param_1[1]) -

          (*param_3 - *param_1) * (param_2[1] - param_1[1]);

  fVar1 = SQRT(fVar4 * fVar4 + fVar5 * fVar5 + fVar6 * fVar6);

  if (0.0 < fVar1) {

    fVar1 = 1.0 / fVar1;

    fVar4 = fVar1 * fVar4;

    fVar5 = fVar1 * fVar5;

    fVar6 = fVar1 * fVar6;

  }

  fVar1 = *param_1;

  fVar2 = param_1[2];

  fVar3 = param_1[1];

  *param_4 = fVar4;

  param_4[3] = -(fVar5 * fVar3 + fVar6 * fVar2 + fVar4 * fVar1);

  param_4[1] = fVar5;

  param_4[2] = fVar6;

  return;

}

/* ===== FUN_0050a730 @ 0x0050A730 ===== */
float10 FUN_0050a730(float *param_1,float param_2,float param_3)



{

  if (param_1[2] == 0.0) {

    return (float10)0.0;

  }

  return -(((float10)param_2 * (float10)*param_1 + (float10)param_3 * (float10)param_1[1] +

           (float10)param_1[3]) / (float10)param_1[2]);

}

/* ===== FUN_0050a770 @ 0x0050A770 ===== */
/* PS2 candidate: diff_angle (conf 0.334) */



float10 FUN_0050a770(float param_1,float param_2)



{

  float10 fVar1;

  

  fVar1 = (float10)param_1 - (float10)param_2;

  if (fVar1 < (float10)0.0) {

    fVar1 = fVar1 + (float10)360.0;

  }

  if ((float10)360.0 < fVar1) {

    fVar1 = fVar1 - (float10)360.0;

  }

  if ((float10)180.0 < fVar1) {

    fVar1 = (float10)360.0 - fVar1;

  }

  return fVar1;

}

/* ===== FUN_0050a7c0 @ 0x0050A7C0 ===== */
/* PS2 candidate: playerobj_turn (conf 0.347) */



float10 FUN_0050a7c0(float param_1,float param_2)



{

  float10 fVar1;

  

  FUN_00451560(&param_1);

  FUN_00451560(&param_2);

  fVar1 = (float10)param_1 - (float10)param_2;

  if ((float10)180.0 < fVar1) {

    return fVar1 - (float10)360.0;

  }

  if (fVar1 < (float10)-180.0) {

    fVar1 = fVar1 + (float10)360.0;

  }

  return fVar1;

}

/* ===== FUN_0050a810 @ 0x0050A810 ===== */
/* PS2 candidate: normalize__FPfN20 (conf 0.675) */



void FUN_0050a810(float *param_1,float *param_2,float *param_3)



{

  float fVar1;

  

  fVar1 = *param_2 * *param_2 + *param_3 * *param_3 + *param_1 * *param_1;

  if (0.0001 <= fVar1) {

    fVar1 = 1.0 / SQRT(fVar1);

    *param_1 = fVar1 * *param_1;

    *param_2 = fVar1 * *param_2;

    *param_3 = fVar1 * *param_3;

    return;

  }

  *param_3 = 0.0;

  *param_2 = 0.0;

  *param_1 = 0.0;

  return;

}

/* ===== FUN_0050a8f0 @ 0x0050A8F0 ===== */
void FUN_0050a8f0(void)



{

  float fVar1;

  int iVar2;

  uint uVar3;

  float10 extraout_ST0;

  float10 extraout_ST0_00;

  float10 fVar4;

  float10 fVar5;

  float10 extraout_ST1;

  float10 fVar6;

  float *in_stack_00000010;

  

  __ftol();

  iVar2 = DAT_005bc870;

  uVar3 = __ftol();

  fVar1 = *(float *)(iVar2 + (uVar3 & 0x3fff) * 4);

  fVar6 = extraout_ST0;

  uVar3 = __ftol();

  fVar4 = (float10)(float)(&DAT_005a8870)[uVar3 & 0x3fff];

  fVar5 = (float10)*(float *)(iVar2 + (uVar3 & 0x3fff) * 4);

  *in_stack_00000010 = (float)((float10)fVar1 * fVar5);

  in_stack_00000010[1] = (float)(-(fVar5 * extraout_ST0_00 * fVar6) - fVar4 * extraout_ST1);

  in_stack_00000010[2] = (float)(fVar4 * fVar6 - fVar5 * extraout_ST0_00 * extraout_ST1);

  in_stack_00000010[3] = (float)(fVar4 * (float10)fVar1);

  in_stack_00000010[4] = (float)(fVar5 * extraout_ST1 - fVar4 * extraout_ST0_00 * fVar6);

  in_stack_00000010[5] = (float)(-(fVar4 * extraout_ST0_00 * extraout_ST1) - fVar5 * fVar6);

  in_stack_00000010[6] = (float)extraout_ST0_00;

  in_stack_00000010[7] = (float)((float10)fVar1 * fVar6);

  in_stack_00000010[8] = (float)((float10)fVar1 * extraout_ST1);

  return;

}

/* ===== FUN_0050a9e0 @ 0x0050A9E0 ===== */
void FUN_0050a9e0(float *param_1,float *param_2,float *param_3,float *param_4)



{

  float fVar1;

  float10 fVar2;

  

  fVar1 = SQRT(param_1[3] * param_1[3] + *param_1 * *param_1);

  if (fVar1 <= 1e-05) {

    if (((float10)param_1[4] == (float10)0.0) && (-(float10)param_1[5] == (float10)0.0)) {

LAB_0050ab88:

      fVar2 = (float10)0.0;

    }

    else {

      fVar2 = (float10)fpatan(-(float10)param_1[5],(float10)param_1[4]);

      fVar2 = fVar2 * (float10)57.295776;

      if (fVar2 < (float10)0.0) {

        fVar2 = fVar2 + (float10)360.0;

      }

      if ((float10)359.99 < fVar2) goto LAB_0050ab88;

    }

    *param_2 = (float)fVar2;

    if ((fVar1 != 0.0) || ((float10)param_1[6] != (float10)0.0)) {

      fVar2 = (float10)fpatan((float10)param_1[6],(float10)fVar1);

      fVar2 = fVar2 * (float10)57.295776;

      if (fVar2 < (float10)0.0) {

        fVar2 = fVar2 + (float10)360.0;

      }

      if (fVar2 <= (float10)359.99) goto LAB_0050abeb;

    }

    fVar2 = (float10)0.0;

LAB_0050abeb:

    *param_3 = (float)fVar2;

    *param_4 = 0.0;

    return;

  }

  if (((float10)param_1[8] == (float10)0.0) && ((float10)param_1[7] == (float10)0.0)) {

LAB_0050aa62:

    fVar2 = (float10)0.0;

  }

  else {

    fVar2 = (float10)fpatan((float10)param_1[7],(float10)param_1[8]);

    fVar2 = fVar2 * (float10)57.295776;

    if (fVar2 < (float10)0.0) {

      fVar2 = fVar2 + (float10)360.0;

    }

    if ((float10)359.99 < fVar2) goto LAB_0050aa62;

  }

  *param_2 = (float)fVar2;

  if ((fVar1 != 0.0) || ((float10)param_1[6] != (float10)0.0)) {

    fVar2 = (float10)fpatan((float10)param_1[6],(float10)fVar1);

    fVar2 = fVar2 * (float10)57.295776;

    if (fVar2 < (float10)0.0) {

      fVar2 = fVar2 + (float10)360.0;

    }

    if (fVar2 <= (float10)359.99) goto LAB_0050aac5;

  }

  fVar2 = (float10)0.0;

LAB_0050aac5:

  *param_3 = (float)fVar2;

  if (((float10)*param_1 == (float10)0.0) && ((float10)param_1[3] == (float10)0.0)) {

    *param_4 = 0.0;

    return;

  }

  fVar2 = (float10)fpatan((float10)param_1[3],(float10)*param_1);

  fVar2 = fVar2 * (float10)57.295776;

  if (fVar2 < (float10)0.0) {

    fVar2 = fVar2 + (float10)360.0;

  }

  if ((float10)359.99 < fVar2) {

    fVar2 = (float10)0.0;

  }

  *param_4 = (float)fVar2;

  return;

}

/* ===== FUN_0050ac00 @ 0x0050AC00 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* PS2 candidate: matrix_mult__FPfN20 (conf 0.63) */



void FUN_0050ac00(float *param_1,float *param_2,undefined4 *param_3)



{

  int iVar1;

  undefined4 *puVar2;

  

  DAT_005dc878 = param_2[2] * param_1[6] + param_1[3] * param_2[1] + *param_1 * *param_2;

  DAT_005dc87c = param_1[1] * *param_2 + param_1[4] * param_2[1] + param_1[7] * param_2[2];

  _DAT_005dc880 = *param_2 * param_1[2] + param_1[8] * param_2[2] + param_1[5] * param_2[1];

  _DAT_005dc884 = param_2[3] * *param_1 + param_1[3] * param_2[4] + param_2[5] * param_1[6];

  _DAT_005dc888 = param_1[1] * param_2[3] + param_1[4] * param_2[4] + param_1[7] * param_2[5];

  _DAT_005dc88c = param_1[5] * param_2[4] + param_1[8] * param_2[5] + param_2[3] * param_1[2];

  _DAT_005dc890 = param_2[6] * *param_1 + param_1[3] * param_2[7] + param_2[8] * param_1[6];

  _DAT_005dc894 = param_2[6] * param_1[1] + param_1[4] * param_2[7] + param_1[7] * param_2[8];

  _DAT_005dc898 = param_1[5] * param_2[7] + param_1[8] * param_2[8] + param_2[6] * param_1[2];

  puVar2 = &DAT_005dc878;

  for (iVar1 = 9; iVar1 != 0; iVar1 = iVar1 + -1) {

    *param_3 = *puVar2;

    puVar2 = puVar2 + 1;

    param_3 = param_3 + 1;

  }

  return;

}

/* ===== FUN_0050ad20 @ 0x0050AD20 ===== */
void FUN_0050ad20(void)



{

  int iVar1;

  float10 fVar2;

  int local_4;

  

  local_4 = 0;

  do {

    fVar2 = (float10)local_4;

    local_4 = local_4 + 1;

    fVar2 = (float10)fsin(fVar2 * (float10)0.0003834952);

    *(float *)(local_4 * 4 + 0x5a886c) = (float)fVar2;

  } while (local_4 < 0x5000);

  DAT_005bc870 = &DAT_005ac870;

  local_4 = 0;

  do {

    fVar2 = (float10)local_4;

    local_4 = local_4 + 1;

    fVar2 = (float10)fsin(fVar2 * (float10)0.0003834952);

    *(float *)(local_4 * 4 + 0x5bc874) = (float)((float10)1.0 / fVar2);

  } while (local_4 < 0x4000);

  iVar1 = 0;

  do {

    fVar2 = (float10)FUN_005445f0();

    (&DAT_005cc878)[iVar1] = (float)fVar2;

    iVar1 = iVar1 + 1;

  } while (iVar1 < 0x4000);

  return;

}

/* ===== FUN_0050adb0 @ 0x0050ADB0 ===== */
float10 FUN_0050adb0(void)



{

  uint uVar1;

  

  uVar1 = __ftol();

  return (float10)(float)(&DAT_005a8870)[uVar1 & 0x3fff];

}

/* ===== FUN_0050ade0 @ 0x0050ADE0 ===== */
float10 FUN_0050ade0(void)



{

  uint uVar1;

  

  uVar1 = __ftol();

  return (float10)*(float *)(DAT_005bc870 + (uVar1 & 0x3fff) * 4);

}

/* ===== FUN_0050ae10 @ 0x0050AE10 ===== */
float10 FUN_0050ae10(void)



{

  uint uVar1;

  

  uVar1 = __ftol();

  return (float10)(float)(&DAT_005cc878)[uVar1 & 0x3fff];

}

/* ===== FUN_0050ae40 @ 0x0050AE40 ===== */
/* PS2 candidate: calc_sincosd__FfPfT1 (conf 0.564) */



void FUN_0050ae40(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)



{

  uint uVar1;

  

  uVar1 = __ftol();

  *param_2 = (&DAT_005a8870)[uVar1 & 0x3fff];

  *param_3 = *(undefined4 *)(DAT_005bc870 + (uVar1 & 0x3fff) * 4);

  return;

}

/* ===== NAM_DictionaryGetTotalNames_2 @ 0x0050AE80 ===== */
undefined4 NAM_DictionaryGetTotalNames_2(int param_1)



{

  return *(undefined4 *)(*(int *)(param_1 + 0x100) + 0x24);

}

/* ===== FUN_0050ae90 @ 0x0050AE90 ===== */
/* PS2 candidate: TurretShoot__FP15TurretCommShootP6OBJECTT1 (conf 0.315) */



int FUN_0050ae90(int param_1,int param_2,undefined4 param_3)



{

  int iVar1;

  int iVar2;

  undefined4 uVar3;

  uint uVar4;

  int iVar5;

  

  iVar5 = FUN_004aa230(*(undefined1 *)(param_1 + 0x20),*(undefined4 *)(param_1 + 0x1c),param_2,

                       *(undefined4 *)(param_1 + 0x18),param_3,param_1);

  *(int *)(iVar5 + 0x274) = param_2;

  if ((param_2 != 0) && (*(int *)(param_2 + 0x1e0) == 0x2c)) {

    iVar1 = *(int *)(param_2 + 0x100);

    iVar2 = *(int *)(iVar1 + 0x38);

    if (iVar2 != 0) {

      *(undefined4 *)(iVar2 + 0xf0) = 0x3dcccccd;

      uVar3 = *(undefined4 *)(param_1 + 0x18);

      *(undefined4 *)(iVar2 + 0x218) = uVar3;

      *(undefined4 *)(*(int *)(iVar2 + 0x274) + 0x218) = uVar3;

    }

    uVar4 = *(uint *)(iVar1 + 0x2c);

    if ((uVar4 & 0x800) == 0) {

      if ((uVar4 & 0x1000) != 0) {

        sound_play_3dpos(0x5da,param_2 + 0xa0);

        return iVar5;

      }

      sound_play_3dpos(0x5dc,param_2 + 0xa0);

      return iVar5;

    }

  }

  sound_play_3dpos(0x592,param_2 + 0xa0);

  return iVar5;

}

/* ===== FUN_0050af50 @ 0x0050AF50 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* PS2 candidate: TurretFire__FP6OBJECTiT0P3P3D (conf 0.384) */



void FUN_0050af50(int param_1,undefined4 param_2,int param_3,undefined4 *param_4)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  float10 fVar5;

  undefined4 local_24;

  undefined4 local_20;

  undefined4 local_1c;

  undefined4 local_18;

  undefined4 local_14;

  undefined4 local_10;

  int local_c;

  undefined4 local_8;

  undefined1 local_4;

  

  iVar2 = param_1;

  iVar1 = *(int *)(param_1 + 0x100);

  iVar3 = *(int *)(iVar1 + 0x1c);

  iVar4 = iVar3;

  if (iVar3 == 0) {

    iVar4 = param_1;

  }

  param_1 = iVar4;

  if ((*(float *)(iVar1 + 0x20) < 0.0 != (*(float *)(iVar1 + 0x20) == 0.0)) &&

     (*(int *)(iVar1 + 0x24) != 0)) {

    if (((iVar3 != DAT_00632a88) || (DAT_00632bac == 0)) && ((*(uint *)(iVar1 + 0x2c) & 0x400) != 0)

       ) {

      if (*(float *)(iVar2 + 0xec) == 0.0) {

        if (param_3 == DAT_00632a88) {

          _DAT_00632b54 = 0x3f800000;

        }

        if (param_3 != 0) {

          iVar3 = reaper_0052e4a0(iVar2);

          if (iVar3 != 0) {

            reaper_00530bd0(iVar2,0,1,0,6,param_3 + 0x188);

          }

        }

      }

      fVar5 = (float10)FUN_00518b70(iVar2,0);

      *(float *)(iVar2 + 0xec) = (float)(fVar5 + (float10)*(float *)(iVar2 + 0xec));

    }

    do {

      *(int *)(iVar1 + 0x24) = *(int *)(iVar1 + 0x24) + -1;

      if ((*(uint *)(iVar1 + 0x2c) & 2) != 0) {

        *(uint *)(iVar1 + 0x2c) = *(uint *)(iVar1 + 0x2c) ^ 4;

      }

      iVar3 = FUN_004a8f50(*(undefined4 *)(iVar1 + 0x34));

      local_c = (*(uint *)(iVar1 + 0x2c) >> 2 & 1) + *(int *)(iVar1 + 0x30);

      *(undefined4 *)(iVar1 + 0x20) = *(undefined4 *)(iVar3 + 0x44);

      local_24 = *param_4;

      local_20 = param_4[1];

      local_1c = param_4[2];

      local_10 = *(undefined4 *)(iVar2 + 0x188);

      local_4 = *(undefined1 *)(iVar1 + 0x34);

      local_8 = param_2;

      if (param_3 == 0) {

        local_18 = 0;

      }

      else {

        local_18 = *(undefined4 *)(param_3 + 0x188);

      }

      iVar3 = FUN_0050ae90(&local_24,iVar2,param_3);

      if (iVar3 != 0) {

        iVar4 = reaper_0052e4a0(param_1);

        if (iVar4 != 0) {

          local_14 = *(undefined4 *)(iVar3 + 0x188);

          reaper_00530bd0(iVar2,3,5,1,5,&local_24);

        }

      }

    } while (((char)*(uint *)(iVar1 + 0x2c) < '\0') && ((*(uint *)(iVar1 + 0x2c) & 4) != 0));

    *(uint *)(iVar1 + 0x2c) = *(uint *)(iVar1 + 0x2c) | 0x100;

    return;

  }

  if ((*(uint *)(iVar1 + 0x2c) & 0x400) != 0) {

    *(undefined4 *)(iVar2 + 0xec) = 0;

  }

  return;

}

/* ===== FUN_0050c1c0 @ 0x0050C1C0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_0050c1c0(int param_1,int param_2)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  undefined4 uVar5;

  

  iVar2 = param_2;

  iVar1 = param_1;

  iVar4 = *(int *)(param_1 + 0x100);

  iVar3 = FUN_004a6160(param_2);

  if (iVar3 == 0) {

    iVar3 = FUN_004a6180(iVar2);

    if (iVar3 != 0) {

      **(uint **)(iVar2 + 0x100) = **(uint **)(iVar2 + 0x100) | 0x200;

    }

  }

  else {

    *(uint *)(iVar2 + 0xe0) = *(uint *)(iVar2 + 0xe0) | 0x20;

  }

  sound_play_player(0x5ee,iVar2);

  *(int *)(iVar4 + 0x1c) = iVar2;

  *(undefined4 *)(iVar2 + 0x208) = 0;

  *(undefined4 *)(iVar2 + 0x20c) = 0;

  if (DAT_005dc89c != 0) {

    iVar4 = FUN_004a6160(iVar2);

    if (iVar4 == 0) {

      uVar5 = 0x36c;

    }

    else {

      uVar5 = 0x5a5;

    }

    FUN_00495700(uVar5,iVar2);

  }

  DAT_005dc89c = 0;

  _DAT_0057bfb0 = *(undefined4 *)(DAT_00632ed8 + 0x8f4);

  iVar4 = reaper_0052e4a0(iVar2);

  if (iVar4 != 0) {

    param_1 = *(undefined4 *)(iVar2 + 0x188);

    reaper_00530bd0(iVar1,0,1,0,2,&param_1);

  }

  return;

}

/* ===== FUN_0050c2a0 @ 0x0050C2A0 ===== */
void FUN_0050c2a0(int param_1)



{

  int iVar1;

  undefined4 *puVar2;

  

  for (puVar2 = DAT_00632d6c; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {

    iVar1 = puVar2[3];

    if ((*(int *)(iVar1 + 0x1e0) == 0x2c) && (*(int *)(*(int *)(iVar1 + 0x100) + 0x1c) == param_1))

    {

      FUN_0050c2e0(iVar1);

    }

  }

  return;

}

/* ===== FUN_0050c2e0 @ 0x0050C2E0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* PS2 candidate: TurretExit (conf 0.388) */



void FUN_0050c2e0(int param_1)



{

  int iVar1;

  int iVar2;

  int iVar3;

  undefined4 uVar4;

  

  iVar3 = *(int *)(param_1 + 0x100);

  iVar1 = *(int *)(iVar3 + 0x1c);

  if (iVar1 != 0) {

    iVar2 = FUN_004a6160(iVar1);

    if (iVar2 == 0) {

      iVar2 = FUN_004a6180(iVar1);

      if (iVar2 != 0) {

        **(uint **)(iVar1 + 0x100) = **(uint **)(iVar1 + 0x100) & 0xfffffdff;

      }

    }

    else {

      *(undefined1 *)(*(int *)(iVar1 + 0x100) + 0x138) = 0;

      *(uint *)(iVar1 + 0xe0) = *(uint *)(iVar1 + 0xe0) & 0xffffffdf;

    }

    *(uint *)(iVar3 + 0x2c) = *(uint *)(iVar3 + 0x2c) | 0x10;

    *(undefined4 *)(iVar3 + 0x1c) = 0;

    *(undefined4 *)(iVar3 + 8) = 0;

    if (iVar1 == DAT_00632a88) {

      FUN_0040d790();

      if (DAT_00632bbc == 0) {

        return;

      }

      FUN_004753c0();

      if (DAT_005dc89c != 0) {

        iVar3 = FUN_004a6160(iVar1);

        if (iVar3 == 0) {

          uVar4 = 0x36c;

        }

        else {

          uVar4 = 0x5a5;

        }

        FUN_00495700(uVar4,iVar1);

      }

      DAT_005dc89c = 0;

      _DAT_0057bfb0 = *(undefined4 *)(DAT_00632ed8 + 0x8f4);

    }

    iVar3 = reaper_0052e4a0(iVar1);

    if (iVar3 != 0) {

      reaper_00530bd0(param_1,0,0,0,3,0);

    }

  }

  return;

}

/* ===== FUN_0050c3c0 @ 0x0050C3C0 ===== */
void FUN_0050c3c0(int param_1)



{

  uint uVar1;

  

  if ((*(byte *)(param_1 + 0xdc) & 0x20) != 0) {

    uVar1 = *(uint *)(*(int *)(param_1 + 0x100) + 0x2c) >> 2 & 1;

    if (*(int *)(*(int *)(param_1 + 8) + 0x34 + uVar1 * 4) != 0) {

      FUN_004034a0(param_1,uVar1 + 0xb,0x28,0,0,0);

    }

    *(uint *)(param_1 + 0xdc) = *(uint *)(param_1 + 0xdc) & 0xffffffdf;

    return;

  }

  if ((*(byte *)(param_1 + 0x30) & 2) != 0) {

    FUN_004034a0(param_1,1,0x21,0,0,0);

  }

  return;

}

/* ===== FUN_0050c950 @ 0x0050C950 ===== */
/* PS2 candidate: turret_count_portables (conf 0.681) */



void FUN_0050c950(int *param_1,int *param_2,int param_3)



{

  undefined4 *puVar1;

  int iVar2;

  int iVar3;

  

  iVar3 = 0;

  iVar2 = 0;

  for (puVar1 = DAT_00632d6c; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {

    if ((*(int *)(puVar1[3] + 4) == 0x3c) &&

       (iVar2 = iVar2 + 1, *(int *)(puVar1[3] + 0x18c) == param_3)) {

      iVar3 = iVar3 + 1;

    }

  }

  *param_1 = iVar3;

  *param_2 = iVar2;

  return;

}

/* ===== FUN_0050c9e0 @ 0x0050C9E0 ===== */
/* PS2 candidate: ANM_BinderDestroy_4 (conf 0.601) */



void FUN_0050c9e0(undefined4 param_1)



{

  FUN_0050ca00(param_1);

  FUN_004a6730(param_1);

  return;

}

/* ===== FUN_0050ca00 @ 0x0050CA00 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* PS2 candidate: kabutoai_move (conf 0.489) */



void FUN_0050ca00(float param_1)



{

  float *pfVar1;

  uint uVar2;

  float *pfVar3;

  float fVar4;

  undefined1 uVar5;

  int iVar6;

  float fVar7;

  int iVar8;

  int iVar9;

  undefined4 *puVar10;

  byte bVar11;

  float10 fVar12;

  float10 fVar13;

  undefined4 uVar14;

  undefined4 uVar15;

  float local_1c;

  float local_18;

  float local_14;

  float *local_10;

  float *local_c;

  float local_8;

  float local_4;

  

  iVar9 = (int)param_1;

  pfVar1 = *(float **)((int)param_1 + 0x100);

  if (DAT_00632e74 != 0) {

    return;

  }

  iVar6 = FUN_0052e480(param_1);

  if (iVar6 == 0) {

    return;

  }

  uVar2 = *(uint *)((int)param_1 + 0xd8);

  local_4 = (float)(*(uint *)((int)param_1 + 0x30) & 2);

  *(uint *)((int)param_1 + 0xd8) = uVar2 & 0xfcffffff;

  *(undefined1 *)((int)param_1 + 0x20a) = 0;

  *(undefined1 *)((int)param_1 + 0x208) = 0;

  switch(*(undefined4 *)((int)param_1 + 0xe4)) {

  case 0:

    *(undefined4 *)((int)param_1 + 0x178) = *(undefined4 *)((int)param_1 + 0xa0);

    *(undefined4 *)((int)param_1 + 0x17c) = *(undefined4 *)((int)param_1 + 0xa4);

    *(undefined4 *)((int)param_1 + 0x180) = *(undefined4 *)((int)param_1 + 0xa8);

    *(undefined4 *)((int)param_1 + 0x18c) = 100;

    if (*(int *)((int)param_1 + 4) == 0x240) {

      *(undefined4 *)((int)param_1 + 0xe4) = 0x40;

      return;

    }

    if (*(int *)((int)param_1 + 4) == 0x23b) {

      *(undefined4 *)((int)param_1 + 0xe4) = 0x3e;

      *(undefined4 *)((int)param_1 + 0xec) = 0x40800000;

      anim_select_check2(param_1,1);

      *(uint *)((int)param_1 + 0x30) = *(uint *)((int)param_1 + 0x30) | 4;

      return;

    }

    *(uint *)((int)param_1 + 0xe4) =

         (-(uint)(*(int *)((int)param_1 + 0xe8) != 1) & 0xffffffe7) + 0x23;

    fVar13 = (float10)FUN_004d5780(0x41700000,0x41c80000);

    pfVar1[5] = (float)fVar13;

    fVar7 = (float)FUN_004d5740(1,2);

    pfVar1[9] = fVar7;

    return;

  case 10:

    FUN_00401000(param_1);

    fVar13 = (float10)FUN_004d5780(0x3f800000,0x40400000);

    *(float *)((int)param_1 + 0xec) = (float)fVar13;

    *(undefined4 *)((int)param_1 + 0xe4) = 0xb;

  case 0xb:

    pfVar3 = *(float **)((int)param_1 + 0x100);

    local_1c = 900.0;

    if (pfVar3[1] == 0.0) {

      local_1c = 300.0;

    }

    pfVar3[1] = 0.0;

    local_c = pfVar3;

    fVar13 = (float10)FUN_00518b70(param_1,0);

    fVar7 = *pfVar3;

    *pfVar3 = (float)((float10)fVar7 - fVar13);

    if ((float10)fVar7 - fVar13 < (float10)0.0) {

      *local_c = 0.5;

      local_8 = *(float *)((int)param_1 + 0x100);

      param_1 = 250000.0;

      local_10 = (float *)0x0;

      for (puVar10 = DAT_00632d6c; puVar10 != (undefined4 *)0x0; puVar10 = (undefined4 *)*puVar10) {

        fVar7 = (float)puVar10[3];

        if (((((*(uint *)((int)fVar7 + 0xd8) & 0x4000c000) == 0) &&

             (iVar6 = FUN_004a61e0(fVar7), iVar6 != 0)) &&

            (*(float *)((int)fVar7 + 0x278) < *(float *)((int)fVar7 + 0x1c0))) &&

           ((*(int *)((int)fVar7 + 0x210) == 0 &&

            (fVar13 = (float10)FUN_0050a5e0((int)fVar7 + 0xa0,iVar9 + 0xa0),

            fVar13 <= (float10)param_1)))) {

          param_1 = (float)fVar13;

          local_10 = (float *)fVar7;

        }

      }

      *(float **)((int)local_8 + 4) = local_10;

      if ((local_c[1] != 0.0) && (local_1c * local_1c < param_1)) {

        local_c[1] = 0.0;

      }

    }

    if (pfVar1[1] != 0.0) {

LAB_0050d17f:

      *(undefined4 *)(iVar9 + 0xe4) = 0x14;

      return;

    }

    fVar13 = (float10)FUN_00518b70(iVar9,0);

    fVar13 = (float10)*(float *)(iVar9 + 0xec) - fVar13;

    *(float *)(iVar9 + 0xec) = (float)fVar13;

    if (fVar13 < (float10)0.0) {

      iVar6 = FUN_004d5730(100);

      fVar7 = (float)iVar6;

      if (35.0 <= fVar7) {

        if (fVar7 < 40.0) {

          fVar13 = (float10)FUN_004d5760(0x43b40000);

          main_ai_move_00401910(iVar9,(float)fVar13);

          *(undefined4 *)(iVar9 + 0xe4) = 0xd;

          return;

        }

        if (fVar7 < 60.0) {

          *(undefined4 *)(iVar9 + 0xe4) = 0xe;

          return;

        }

LAB_0050e1a4:

        *(undefined4 *)(iVar9 + 0xe4) = 10;

        return;

      }

      fVar13 = (float10)FUN_004d5760(0x43b40000);

      fVar12 = (float10)FUN_004d5760(0x41f00000);

      FUN_0050ae40((float)fVar13,&local_18,&local_14);

      pfVar1[2] = local_18 * (float)fVar12 + *(float *)(iVar9 + 0x178);

      pfVar1[3] = *(float *)(iVar9 + 0x17c) - local_14 * (float)fVar12;

      pfVar1[4] = *(float *)(iVar9 + 0x180);

      FUN_00401610(iVar9,pfVar1 + 2);

      *(undefined4 *)(iVar9 + 0xe4) = 0xc;

      iVar6 = FUN_004d5730(100);

      if (iVar6 < 10) {

        iVar6 = FUN_004d5730(100);

        sound_play_obj((0x31 < iVar6) + 0x536,iVar9);

        return;

      }

    }

    break;

  case 0xc:

    pfVar3 = *(float **)((int)param_1 + 0x100);

    local_1c = 900.0;

    if (pfVar3[1] == 0.0) {

      local_1c = 300.0;

    }

    pfVar3[1] = 0.0;

    local_10 = pfVar3;

    fVar13 = (float10)FUN_00518b70(param_1,0);

    fVar7 = *pfVar3;

    *pfVar3 = (float)((float10)fVar7 - fVar13);

    if ((float10)fVar7 - fVar13 < (float10)0.0) {

      *local_10 = 0.5;

      local_8 = *(float *)((int)param_1 + 0x100);

      param_1 = 250000.0;

      local_c = (float *)0x0;

      for (puVar10 = DAT_00632d6c; puVar10 != (undefined4 *)0x0; puVar10 = (undefined4 *)*puVar10) {

        iVar6 = puVar10[3];

        if (((((*(uint *)(iVar6 + 0xd8) & 0x4000c000) == 0) &&

             (iVar8 = FUN_004a61e0(iVar6), iVar8 != 0)) &&

            (*(float *)(iVar6 + 0x278) < *(float *)(iVar6 + 0x1c0))) &&

           ((*(int *)(iVar6 + 0x210) == 0 &&

            (fVar13 = (float10)FUN_0050a5e0(iVar6 + 0xa0,iVar9 + 0xa0), fVar13 <= (float10)param_1))

           )) {

          param_1 = (float)fVar13;

          local_c = (float *)iVar6;

        }

      }

      *(float **)((int)local_8 + 4) = local_c;

      if ((local_10[1] != 0.0) && (local_1c * local_1c < param_1)) {

        local_10[1] = 0.0;

      }

    }

    fVar7 = pfVar1[1];

    goto joined_r0x0050d01d;

  case 0xd:

    pfVar3 = *(float **)((int)param_1 + 0x100);

    local_1c = 900.0;

    if (pfVar3[1] == 0.0) {

      local_1c = 300.0;

    }

    pfVar3[1] = 0.0;

    local_10 = pfVar3;

    fVar13 = (float10)FUN_00518b70(param_1,0);

    fVar7 = *pfVar3;

    *pfVar3 = (float)((float10)fVar7 - fVar13);

    if ((float10)fVar7 - fVar13 < (float10)0.0) {

      *local_10 = 0.5;

      local_8 = *(float *)((int)param_1 + 0x100);

      param_1 = 250000.0;

      local_c = (float *)0x0;

      for (puVar10 = DAT_00632d6c; puVar10 != (undefined4 *)0x0; puVar10 = (undefined4 *)*puVar10) {

        iVar6 = puVar10[3];

        if (((((*(uint *)(iVar6 + 0xd8) & 0x4000c000) == 0) &&

             (iVar8 = FUN_004a61e0(iVar6), iVar8 != 0)) &&

            (*(float *)(iVar6 + 0x278) < *(float *)(iVar6 + 0x1c0))) &&

           ((*(int *)(iVar6 + 0x210) == 0 &&

            (fVar13 = (float10)FUN_0050a5e0(iVar6 + 0xa0,iVar9 + 0xa0), fVar13 <= (float10)param_1))

           )) {

          param_1 = (float)fVar13;

          local_c = (float *)iVar6;

        }

      }

      *(float **)((int)local_8 + 4) = local_c;

      if ((local_10[1] != 0.0) && (local_1c * local_1c < param_1)) {

        local_10[1] = 0.0;

      }

    }

    fVar7 = pfVar1[1];

joined_r0x0050d01d:

    if (fVar7 == 0.0) {

      *(undefined1 **)(iVar9 + 0x16c) = &LAB_0050f430;

      FUN_00402270(iVar9);

      if (*(int *)(iVar9 + 0x168) != 0) {

        return;

      }

      *(undefined4 *)(iVar9 + 0xe4) = 10;

      return;

    }

LAB_0050d177:

    FUN_00401000(iVar9);

    goto LAB_0050d17f;

  case 0xe:

    pfVar3 = *(float **)((int)param_1 + 0x100);

    local_1c = 900.0;

    if (pfVar3[1] == 0.0) {

      local_1c = 300.0;

    }

    pfVar3[1] = 0.0;

    local_10 = pfVar3;

    fVar13 = (float10)FUN_00518b70(param_1,0);

    fVar7 = *pfVar3;

    *pfVar3 = (float)((float10)fVar7 - fVar13);

    if ((float10)fVar7 - fVar13 < (float10)0.0) {

      *local_10 = 0.5;

      local_8 = *(float *)((int)param_1 + 0x100);

      param_1 = 250000.0;

      local_c = (float *)0x0;

      for (puVar10 = DAT_00632d6c; puVar10 != (undefined4 *)0x0; puVar10 = (undefined4 *)*puVar10) {

        iVar6 = puVar10[3];

        if (((((*(uint *)(iVar6 + 0xd8) & 0x4000c000) == 0) &&

             (iVar8 = FUN_004a61e0(iVar6), iVar8 != 0)) &&

            (*(float *)(iVar6 + 0x278) < *(float *)(iVar6 + 0x1c0))) &&

           ((*(int *)(iVar6 + 0x210) == 0 &&

            (fVar13 = (float10)FUN_0050a5e0(iVar6 + 0xa0,iVar9 + 0xa0), fVar13 <= (float10)param_1))

           )) {

          param_1 = (float)fVar13;

          local_c = (float *)iVar6;

        }

      }

      *(float **)((int)local_8 + 4) = local_c;

      if ((local_10[1] != 0.0) && (local_1c * local_1c < param_1)) {

        local_10[1] = 0.0;

      }

    }

    if (pfVar1[1] == 0.0) {

      if (local_4 == 0.0) {

        return;

      }

      *(undefined4 *)(iVar9 + 0xe4) = 10;

      return;

    }

    goto LAB_0050d177;

  case 0x14:

    puVar10 = DAT_00632d6c;

    if (pfVar1[1] == 0.0) {

      *(undefined4 *)((int)param_1 + 0xe4) = 10;

      return;

    }

    for (; puVar10 != (undefined4 *)0x0; puVar10 = (undefined4 *)*puVar10) {

      iVar9 = puVar10[3];

      if (((*(int *)(iVar9 + 4) == 0x232) &&

          (fVar13 = (float10)FUN_0050a610((int)param_1 + 0xa0,iVar9 + 0xa0),

          fVar13 <= (float10)100.0)) && (*(int *)(iVar9 + 0xe4) < 0x14)) {

        *(undefined4 *)(iVar9 + 0xe4) = 0x14;

      }

    }

    if ((0 < (int)pfVar1[9]) && (iVar9 = FUN_004d5730(100), iVar9 < 0x19)) {

      fVar13 = (float10)FUN_00413e40((int)param_1 + 0xa0);

      if ((float10)0.0 < fVar13) {

        iVar6 = 0;

        iVar9 = 0;

        puVar10 = DAT_00632d6c;

        if (DAT_00632d6c != (undefined4 *)0x0) {

          do {

            iVar8 = *(int *)(puVar10[3] + 4);

            if ((iVar8 == 0x232) || (iVar8 == 0x23b)) {

              iVar9 = iVar9 + 1;

            }

            else if (iVar8 == 0x23c) {

              iVar6 = iVar6 + 1;

            }

            puVar10 = (undefined4 *)*puVar10;

          } while (puVar10 != (undefined4 *)0x0);

          if ((7 < iVar9) || (9 < iVar6)) goto switchD_0050ca70_caseD_15;

        }

        *(undefined4 *)((int)param_1 + 0xe4) = 0x1e;

        fVar13 = (float10)FUN_0050a400((int)param_1 + 0xa0,(int)pfVar1[1] + 0xa0);

        fVar7 = (float)((float10)270.0 + fVar13);

        fVar13 = fVar13 + (float10)90.0;

        goto LAB_0050e133;

      }

    }

  case 0x15:

switchD_0050ca70_caseD_15:

    iVar9 = FUN_004a61a0(pfVar1[1]);

    if (iVar9 == 0) {

      fVar13 = (float10)FUN_004d5780(0x41700000,0x437a0000);

      uVar14 = 0x41f00000;

      uVar15 = 0x41200000;

    }

    else {

      fVar13 = (float10)FUN_004d5780(0x42480000,0x42f00000);

      uVar14 = 0x42aa0000;

      uVar15 = 0x428c0000;

    }

    pfVar1[7] = (float)fVar13;

    fVar13 = (float10)FUN_004d5780(uVar15,uVar14);

    pfVar1[5] = (float)fVar13;

    *(undefined4 *)((int)param_1 + 0xe4) = 0x16;

    return;

  case 0x16:

    if (pfVar1[1] == 0.0) {

      *(undefined4 *)((int)param_1 + 0xe4) = 10;

      return;

    }

    fVar13 = (float10)FUN_0050a400((int)pfVar1[1] + 0xa0,(int)param_1 + 0xa0);

    fVar4 = pfVar1[7];

    FUN_0050ae40((float)fVar13,&local_18,&local_14);

    fVar7 = pfVar1[1];

    pfVar3 = pfVar1 + 2;

    *pfVar3 = local_18 * fVar4 + *(float *)((int)fVar7 + 0xa0);

    pfVar1[3] = *(float *)((int)fVar7 + 0xa4) - local_14 * fVar4;

    pfVar1[4] = *(float *)((int)fVar7 + 0xa8) + pfVar1[5];

    *(undefined1 **)((int)param_1 + 0x16c) = &LAB_0050f430;

    ai_fly_update_goal_3(param_1,*(float *)((int)pfVar1[1] + 0xa8) + pfVar1[5],pfVar3);

    local_10 = (float *)(*(float *)((int)pfVar1[1] + 0xa8) + pfVar1[5]);

    fVar7 = *(float *)((int)param_1 + 0x140);

    if (fVar7 < 0.0) {

      fVar7 = 0.0;

    }

    fVar7 = *(float *)((int)param_1 + 0xa8) - fVar7;

    if ((float)local_10 <= fVar7) {

      if ((float)local_10 + 5.0 <= fVar7) {

        if (-50.0 <= *(float *)((int)param_1 + 0x108)) {

          if (3.0 <= fVar7 - (float)local_10) {

            fVar13 = (float10)FUN_00518b70(param_1,0);

            *(float *)((int)param_1 + 0x108) =

                 (float)((float10)*(float *)((int)param_1 + 0x108) -

                        fVar13 * (float10)*(float *)((int)param_1 + 0x1b8));

          }

          else if (*(float *)((int)param_1 + 0x108) < -3.0) {

            *(undefined4 *)((int)param_1 + 0x108) = 0xc0400000;

          }

        }

        else {

          *(undefined4 *)((int)param_1 + 0x108) = 0xc2480000;

        }

      }

      else {

        *(undefined4 *)((int)param_1 + 0x108) = 0;

      }

    }

    else {

      *(undefined4 *)((int)param_1 + 0x108) = 0x41000000;

    }

    *(undefined1 **)((int)param_1 + 0x16c) = &LAB_0050f430;

    FUN_00402270(param_1);

    if (*(int *)((int)param_1 + 0x168) == 0) {

      main_ai_move_00401790(param_1,*(float *)((int)pfVar1[1] + 0xa8) + pfVar1[5],pfVar3);

    }

    fVar13 = (float10)FUN_0050a5e0((int)pfVar1[1] + 0xa0,(int)param_1 + 0xa0);

    if (fVar13 < (float10)(fVar4 + 10.0) * (float10)(fVar4 + 10.0)) {

      FUN_00401000(param_1);

      *(undefined4 *)((int)param_1 + 0xe4) = 0x17;

      pfVar1[8] = *(float *)(DAT_00632ed8 + 0x1524);

      *(undefined4 *)((int)param_1 + 0xec) = 0;

      return;

    }

    break;

  case 0x17:

    if (pfVar1[1] == 0.0) {

      *(undefined4 *)((int)param_1 + 0xe4) = 10;

      return;

    }

    local_10 = (float *)(*(float *)((int)pfVar1[1] + 0xa8) + pfVar1[5]);

    fVar7 = *(float *)((int)param_1 + 0x140);

    if (fVar7 < 0.0) {

      fVar7 = 0.0;

    }

    fVar7 = *(float *)((int)param_1 + 0xa8) - fVar7;

    if ((float)local_10 <= fVar7) {

      if ((float)local_10 + 5.0 <= fVar7) {

        if (-50.0 <= *(float *)((int)param_1 + 0x108)) {

          if (3.0 <= fVar7 - (float)local_10) {

            fVar13 = (float10)FUN_00518b70(param_1,0);

            *(float *)((int)param_1 + 0x108) =

                 (float)((float10)*(float *)((int)param_1 + 0x108) -

                        fVar13 * (float10)*(float *)((int)param_1 + 0x1b8));

          }

          else if (*(float *)((int)param_1 + 0x108) < -3.0) {

            *(undefined4 *)((int)param_1 + 0x108) = 0xc0400000;

          }

        }

        else {

          *(undefined4 *)((int)param_1 + 0x108) = 0xc2480000;

        }

      }

      else {

        *(undefined4 *)((int)param_1 + 0x108) = 0;

      }

    }

    else {

      *(undefined4 *)((int)param_1 + 0x108) = 0x41000000;

    }

    fVar13 = (float10)FUN_0050a400((int)param_1 + 0xa0,(int)pfVar1[1] + 0xa0);

    *(undefined1 *)((int)param_1 + 0x208) = 0;

    fVar12 = (float10)FUN_0050a7c0((float)fVar13,*(undefined4 *)((int)param_1 + 200));

    local_c = (float *)(float)ABS(fVar12);

    *(uint *)((int)param_1 + 0xd8) = *(uint *)((int)param_1 + 0xd8) | 0x1000000;

    *(float *)((int)param_1 + 0x158) = (float)fVar13;

    if ((float)local_c != 0.0) {

      uVar5 = 0xe0;

      if ((float10)0.0 <= fVar12) {

        uVar5 = 0x20;

      }

      *(undefined1 *)((int)param_1 + 0x208) = uVar5;

    }

    fVar13 = (float10)FUN_00518b70(param_1,0);

    fVar13 = (float10)*(float *)((int)param_1 + 0xec) - fVar13;

    *(float *)((int)param_1 + 0xec) = (float)fVar13;

    if ((fVar13 < (float10)0.0) && ((float)local_c < 2.0)) {

      iVar9 = FUN_004d5730(100);

      if (iVar9 < 0x32) {

        uVar15 = 0x526;

      }

      else {

        uVar15 = 0x527;

      }

      sound_play_obj(uVar15,param_1);

      fVar4 = pfVar1[1];

      iVar9 = object_allocate_type(0x5a,0);

      FUN_004a76e0(param_1,0,iVar9 + 0xa0);

      FUN_00499280(iVar9);

      *(undefined4 *)(iVar9 + 200) = *(undefined4 *)((int)param_1 + 200);

      *(undefined4 *)(iVar9 + 0xcc) = 0;

      *(undefined4 *)(iVar9 + 0xd0) = 0;

      uVar15 = *(undefined4 *)((int)param_1 + 0x18c);

      *(undefined4 *)(iVar9 + 0x11c) = *(undefined4 *)(iVar9 + 0x194);

      *(undefined4 *)(iVar9 + 0x10c) = *(undefined4 *)(iVar9 + 0x194);

      *(undefined4 *)(iVar9 + 0x18c) = uVar15;

      fVar13 = (float10)FUN_0050a520((int)fVar4 + 0xa0,iVar9 + 0xa0);

      fVar7 = (float)(fVar13 / (float10)*(float *)(iVar9 + 0x10c));

      fVar4 = (fVar7 * fVar7 * *(float *)(iVar9 + 0x1b8) * 0.5 +

              (*(float *)((int)fVar4 + 0xa8) - *(float *)(iVar9 + 0xa8))) / fVar7;

      fVar13 = (float10)FUN_004d5780(fVar4 * 0.100000024,fVar4 * 1.9);

      *(float *)(iVar9 + 0x118) = (float)fVar13;

      *(float *)(iVar9 + 0x108) = (float)fVar13;

      local_c = (float *)0x0;

      local_10 = (float *)0xffffffff;

      **(float **)(iVar9 + 0x100) = fVar7 + 1.0;

      (*(undefined4 **)(iVar9 + 0x100))[1] = **(undefined4 **)(iVar9 + 0x100);

      *(undefined4 *)(iVar9 + 0xf4) = 0x637;

      *(undefined4 *)(iVar9 + 0xf8) = 0x533;

      do {

        iVar6 = object_allocate_type(0x5a,0);

        object_copy_personality(iVar6,iVar9);

        FUN_00497a50(iVar6,iVar9);

        object_change_ospec(iVar6,0xc);

        fVar4 = (float)(int)local_10 * 0.02;

        *(float *)(iVar6 + 0xec) = -fVar4;

        fVar7 = *(float *)(iVar9 + 0x108) - fVar4 * *(float *)(iVar9 + 0x1b8);

        *(float *)(iVar6 + 0x108) = fVar7;

        *(float *)(iVar6 + 0x118) = fVar7;

        *(float *)(iVar6 + 0xa8) =

             (fVar4 * *(float *)(iVar9 + 0x108) - fVar4 * fVar4 * *(float *)(iVar9 + 0x1b8) * 0.5) +

             *(float *)(iVar6 + 0xa8);

        FUN_0050ae40(*(undefined4 *)(iVar6 + 200),&local_4,&local_8);

        iVar8 = (int)local_c + 1;

        *(float *)(iVar6 + 0xa0) =

             local_4 * fVar4 * *(float *)(iVar9 + 0x10c) + *(float *)(iVar6 + 0xa0);

        fVar7 = *(float *)(iVar9 + 0x10c);

        *(int *)(iVar6 + 0x274) = iVar9;

        *(float *)(iVar6 + 0xa4) = *(float *)(iVar6 + 0xa4) - local_8 * fVar4 * fVar7;

        *(float *)(iVar6 + 0x184) = (float)iVar8 * 0.089999996;

        uVar15 = *(undefined4 *)(iVar9 + 0x10c);

        *(uint *)(iVar6 + 0x1c8) = *(uint *)(iVar6 + 0x1c8) | 0xe00;

        *(undefined4 *)(iVar6 + 0x10c) = uVar15;

        *(undefined4 *)(iVar6 + 0x11c) = uVar15;

        FUN_00499280(iVar6);

        *(uint *)(iVar6 + 0xd8) = *(uint *)(iVar6 + 0xd8) | 0x40000000;

        local_10 = (float *)((int)local_10 + -1);

        local_c = (float *)iVar8;

      } while (-0xb < (int)local_10);

      pfVar1[8] = (float)((int)pfVar1[8] + -1);

      *(undefined4 *)((int)param_1 + 0xec) = *(undefined4 *)(DAT_00632ed8 + 0x1520);

      if ((int)pfVar1[8] < 1) {

        iVar9 = FUN_004a61a0(pfVar1[1]);

        if (iVar9 == 0) {

          FUN_0050a400((int)pfVar1[1] + 0xa0,(float *)((int)param_1 + 0xa0));

          fVar13 = (float10)FUN_004d5780((*(float *)((int)param_1 + 200) + 180.0) - 100.0,

                                         *(float *)((int)param_1 + 200) + 280.0);

          fVar12 = (float10)FUN_004d5780(0x42c80000,0x43610000);

          FUN_0050ae40((float)fVar13,&local_18,&local_14);

          fVar13 = (float10)FUN_004d5780(0x41700000,0x41c80000);

          pfVar1[5] = (float)fVar13;

          pfVar1[2] = local_18 * (float)fVar12 + *(float *)((int)param_1 + 0xa0);

          pfVar1[3] = *(float *)((int)param_1 + 0xa4) - local_14 * (float)fVar12;

          pfVar1[4] = *(float *)((int)param_1 + 0xa8);

          main_ai_move_00401850

                    (param_1,(float)(fVar13 + (float10)*(float *)((int)pfVar1[1] + 0xa8)),pfVar1 + 2

                    );

          *(undefined4 *)((int)param_1 + 0xe4) = 0x18;

          return;

        }

        *(undefined4 *)((int)param_1 + 0xe4) = 0x1a;

        fVar13 = (float10)FUN_004d5780(0x40000000,0x40c00000);

        *(float *)((int)param_1 + 0xec) = (float)fVar13;

        iVar9 = FUN_004d5730(100);

        if (iVar9 < 0x32) {

          *(uint *)((int)param_1 + 0xe0) = *(uint *)((int)param_1 + 0xe0) | 8;

          return;

        }

        *(uint *)((int)param_1 + 0xe0) = *(uint *)((int)param_1 + 0xe0) & 0xfffffff7;

        return;

      }

    }

    break;

  case 0x18:

    *(undefined1 **)((int)param_1 + 0x16c) = &LAB_0050f430;

    FUN_00402270(param_1);

    if (*(int *)((int)param_1 + 0x168) == 0) {

      *(undefined4 *)((int)param_1 + 0xe4) = 0x19;

      fVar13 = (float10)FUN_004d5780(*(float *)((int)param_1 + 200) + 150.0,

                                     *(float *)((int)param_1 + 200) + 210.0);

      pfVar1[6] = (float)fVar13;

      return;

    }

    break;

  case 0x19:

    if (pfVar1[1] == 0.0) {

      local_10 = (float *)pfVar1[5];

    }

    else {

      local_10 = (float *)(*(float *)((int)pfVar1[1] + 0xa8) + pfVar1[5]);

    }

    fVar7 = *(float *)((int)param_1 + 0x140);

    if (fVar7 < 0.0) {

      fVar7 = 0.0;

    }

    fVar7 = *(float *)((int)param_1 + 0xa8) - fVar7;

    if ((float)local_10 <= fVar7) {

      if ((float)local_10 + 5.0 <= fVar7) {

        if (-50.0 <= *(float *)((int)param_1 + 0x108)) {

          if (3.0 <= fVar7 - (float)local_10) {

            fVar13 = (float10)FUN_00518b70(param_1,0);

            *(float *)((int)param_1 + 0x108) =

                 (float)((float10)*(float *)((int)param_1 + 0x108) -

                        fVar13 * (float10)*(float *)((int)param_1 + 0x1b8));

          }

          else if (*(float *)((int)param_1 + 0x108) < -3.0) {

            *(undefined4 *)((int)param_1 + 0x108) = 0xc0400000;

          }

        }

        else {

          *(undefined4 *)((int)param_1 + 0x108) = 0xc2480000;

        }

      }

      else {

        *(undefined4 *)((int)param_1 + 0x108) = 0;

      }

    }

    else {

      *(undefined4 *)((int)param_1 + 0x108) = 0x41000000;

    }

    *(undefined1 *)((int)param_1 + 0x20a) = 3;

    fVar7 = pfVar1[6];

    *(undefined1 *)((int)param_1 + 0x208) = 0;

    fVar13 = (float10)FUN_0050a7c0(fVar7,*(undefined4 *)((int)param_1 + 200));

    *(float *)((int)param_1 + 0x158) = fVar7;

    *(uint *)((int)param_1 + 0xd8) = *(uint *)((int)param_1 + 0xd8) | 0x1000000;

    if (ABS(fVar13) != (float10)0.0) {

      uVar5 = 0xe0;

      if (0.0 <= (float)fVar13) {

        uVar5 = 0x20;

      }

      *(undefined1 *)((int)param_1 + 0x208) = uVar5;

    }

    if (ABS(fVar13) < (float10)1.0) {

      *(uint *)((int)param_1 + 0xe4) = (-(uint)(pfVar1[1] != 0.0) & 10) + 10;

      return;

    }

    break;

  case 0x1a:

    if (pfVar1[1] == 0.0) {

      *(undefined4 *)((int)param_1 + 0xe4) = 10;

      return;

    }

    local_10 = (float *)(*(float *)((int)pfVar1[1] + 0xa8) + pfVar1[5]);

    fVar7 = *(float *)((int)param_1 + 0x140);

    if (fVar7 < 0.0) {

      fVar7 = 0.0;

    }

    fVar7 = *(float *)((int)param_1 + 0xa8) - fVar7;

    if ((float)local_10 <= fVar7) {

      if ((float)local_10 + 5.0 <= fVar7) {

        if (-50.0 <= *(float *)((int)param_1 + 0x108)) {

          if (3.0 <= fVar7 - (float)local_10) {

            fVar13 = (float10)FUN_00518b70(param_1,0);

            *(float *)((int)param_1 + 0x108) =

                 (float)((float10)*(float *)((int)param_1 + 0x108) -

                        fVar13 * (float10)*(float *)((int)param_1 + 0x1b8));

          }

          else if (*(float *)((int)param_1 + 0x108) < -3.0) {

            *(undefined4 *)((int)param_1 + 0x108) = 0xc0400000;

          }

        }

        else {

          *(undefined4 *)((int)param_1 + 0x108) = 0xc2480000;

        }

      }

      else {

        *(undefined4 *)((int)param_1 + 0x108) = 0;

      }

    }

    else {

      *(undefined4 *)((int)param_1 + 0x108) = 0x41000000;

    }

    fVar13 = (float10)FUN_0050a400((int)pfVar1[1] + 0xa0,(int)param_1 + 0xa0);

    if ((*(byte *)((int)param_1 + 0xe0) & 8) == 0) {

      fVar13 = fVar13 - (float10)20.0;

    }

    else {

      fVar13 = fVar13 + (float10)20.0;

    }

    FUN_0050ae40((float)fVar13,&local_18,&local_14);

    pfVar1[2] = local_18 * 40.0 + *(float *)(DAT_00632a88 + 0xa0);

    pfVar1[3] = *(float *)(DAT_00632a88 + 0xa4) - local_14 * 40.0;

    pfVar1[4] = *(float *)((int)param_1 + 0xa8);

    fVar13 = (float10)FUN_0050a400((int)param_1 + 0xa0,pfVar1 + 2);

    *(undefined1 *)((int)param_1 + 0x208) = 0;

    fVar12 = (float10)FUN_0050a7c0((float)fVar13,*(undefined4 *)((int)param_1 + 200));

    *(uint *)((int)param_1 + 0xd8) = *(uint *)((int)param_1 + 0xd8) | 0x1000000;

    *(float *)((int)param_1 + 0x158) = (float)fVar13;

    if (ABS(fVar12) != (float10)0.0) {

      uVar5 = 0xe0;

      if ((float10)0.0 <= fVar12) {

        uVar5 = 0x20;

      }

      *(undefined1 *)((int)param_1 + 0x208) = uVar5;

    }

    uVar5 = __ftol();

    *(undefined1 *)((int)param_1 + 0x20a) = uVar5;

    fVar13 = (float10)FUN_00518b70(param_1,0);

    fVar13 = (float10)*(float *)((int)param_1 + 0xec) - fVar13;

    *(float *)((int)param_1 + 0xec) = (float)fVar13;

    if (fVar13 < (float10)0.0) {

      *(undefined4 *)((int)param_1 + 0xe4) = 0x15;

      return;

    }

    break;

  case 0x1e:

    fVar7 = pfVar1[6];

    *(undefined1 *)((int)param_1 + 0x208) = 0;

    fVar13 = (float10)FUN_0050a7c0(fVar7,*(undefined4 *)((int)param_1 + 200));

    *(uint *)((int)param_1 + 0xd8) = *(uint *)((int)param_1 + 0xd8) | 0x1000000;

    *(float *)((int)param_1 + 0x158) = fVar7;

    if (ABS(fVar13) != (float10)0.0) {

      uVar5 = 0xe0;

      if ((float10)0.0 <= fVar13) {

        uVar5 = 0x20;

      }

      *(undefined1 *)((int)param_1 + 0x208) = uVar5;

    }

    uVar5 = __ftol();

    *(undefined1 *)((int)param_1 + 0x20a) = uVar5;

    fVar13 = (float10)FUN_00518b70(param_1,0);

    fVar13 = (float10)*(float *)((int)param_1 + 0xec) - fVar13;

    *(float *)((int)param_1 + 0xec) = (float)fVar13;

    if (fVar13 < (float10)0.0) {

      *(undefined4 *)((int)param_1 + 0xe4) = 0x1f;

      return;

    }

    break;

  case 0x1f:

    if (3.3333333 < *(float *)((int)param_1 + 0x14)) {

      iVar9 = object_allocate_type(0x23b,0x80000000);

      if ((*(uint *)((int)param_1 + 0xd8) & 0x400) != 0) {

        *(uint *)(iVar9 + 0xd8) = *(uint *)(iVar9 + 0xd8) | 0x400;

      }

      FUN_004979b0(iVar9,param_1);

      FUN_00499280(iVar9);

      *(undefined4 *)(iVar9 + 0x178) = *(undefined4 *)(iVar9 + 0xa0);

      *(undefined4 *)(iVar9 + 0x17c) = *(undefined4 *)(iVar9 + 0xa4);

      *(undefined4 *)(iVar9 + 0x180) = *(undefined4 *)(iVar9 + 0xa8);

      *(undefined4 *)(iVar9 + 0xec) = 0x40800000;

      anim_select_check2(iVar9,10);

      sound_play_obj(0x52d,iVar9);

      *(undefined4 *)(iVar9 + 0xe4) = 0x3d;

      pfVar1[9] = (float)((int)pfVar1[9] + -1);

      *(undefined4 *)((int)param_1 + 0xe4) = 0x20;

      return;

    }

    break;

  case 0x20:

    *(undefined1 *)((int)param_1 + 0x208) = 0;

    *(undefined1 *)((int)param_1 + 0x20a) = 0;

    if (local_4 != 0.0) {

      *(undefined4 *)((int)param_1 + 0xec) = 0x3f000000;

      *(undefined4 *)((int)param_1 + 0xe4) = 0x21;

      return;

    }

    break;

  case 0x21:

    uVar5 = __ftol();

    *(undefined1 *)((int)param_1 + 0x20a) = uVar5;

    fVar13 = (float10)FUN_00518b70(param_1,0);

    fVar13 = (float10)*(float *)((int)param_1 + 0xec) - fVar13;

    *(float *)((int)param_1 + 0xec) = (float)fVar13;

    if (fVar13 < (float10)0.0) {

      *(undefined4 *)((int)param_1 + 0xec) = 0x3f800000;

      if (((int)pfVar1[9] < 1) || (iVar9 = FUN_004d5730(100), 0x18 < iVar9)) {

        *(undefined4 *)((int)param_1 + 0xe4) = 0x22;

        return;

      }

      fVar7 = *(float *)((int)param_1 + 200) + 30.0;

      *(undefined4 *)((int)param_1 + 0xe4) = 0x1e;

      fVar13 = (float10)*(float *)((int)param_1 + 200) - (float10)30.0;

LAB_0050e133:

      fVar13 = (float10)FUN_004d5780((float)fVar13,fVar7);

      pfVar1[6] = (float)fVar13;

      *(undefined4 *)((int)param_1 + 0xec) = 0x3f000000;

      return;

    }

    break;

  case 0x22:

    uVar5 = __ftol();

    *(undefined1 *)((int)param_1 + 0x20a) = uVar5;

    fVar13 = (float10)FUN_00518b70(param_1,0);

    fVar13 = (float10)*(float *)((int)param_1 + 0xec) - fVar13;

    *(float *)((int)param_1 + 0xec) = (float)fVar13;

    if ((float10)0.0 <= fVar13) {

      return;

    }

    goto LAB_0050e1a4;

  case 0x23:

    if (pfVar1[1] != 0.0) {

      fVar7 = *(float *)((int)param_1 + 0x140);

      local_10 = (float *)pfVar1[5];

      if (fVar7 < 0.0) {

        fVar7 = 0.0;

      }

      fVar7 = *(float *)((int)param_1 + 0xa8) - fVar7;

      if ((float)local_10 <= fVar7) {

        if ((float)local_10 + 5.0 <= fVar7) {

          if (-50.0 <= *(float *)((int)param_1 + 0x108)) {

            if (3.0 <= fVar7 - (float)local_10) {

              fVar13 = (float10)FUN_00518b70(param_1,0);

              *(float *)((int)param_1 + 0x108) =

                   (float)((float10)*(float *)((int)param_1 + 0x108) -

                          fVar13 * (float10)*(float *)((int)param_1 + 0x1b8));

            }

            else if (*(float *)((int)param_1 + 0x108) < -3.0) {

              *(undefined4 *)((int)param_1 + 0x108) = 0xc0400000;

            }

          }

          else {

            *(undefined4 *)((int)param_1 + 0x108) = 0xc2480000;

          }

        }

        else {

          *(undefined4 *)((int)param_1 + 0x108) = 0;

        }

      }

      else {

        *(undefined4 *)((int)param_1 + 0x108) = 0x41000000;

      }

    }

    local_10 = (float *)(*(float *)((int)pfVar1[1] + 0xa8) + pfVar1[5]);

    fVar7 = *(float *)((int)param_1 + 0x140);

    if (fVar7 < 0.0) {

      fVar7 = 0.0;

    }

    fVar7 = *(float *)((int)param_1 + 0xa8) - fVar7;

    if (fVar7 < (float)local_10) {

      *(undefined4 *)((int)param_1 + 0x108) = 0x41000000;

      return;

    }

    if (fVar7 < (float)local_10 + 5.0) {

      *(undefined4 *)((int)param_1 + 0x108) = 0;

      return;

    }

    if (*(float *)((int)param_1 + 0x108) < -50.0) {

      *(undefined4 *)((int)param_1 + 0x108) = 0xc2480000;

      return;

    }

    fVar7 = fVar7 - (float)local_10;

    goto LAB_0050e4da;

  case 0x24:

    *(undefined1 *)((int)param_1 + 0x208) = 0;

    *(undefined1 *)((int)param_1 + 0x20a) = 0;

    fVar13 = (float10)FUN_00518b70(param_1,0);

    *(float *)((int)param_1 + 200) =

         (float)(fVar13 * (float10)300.0 + (float10)*(float *)((int)param_1 + 200));

    if ((*(float *)((int)param_1 + 0x108) < 0.0 != (*(float *)((int)param_1 + 0x108) == 0.0)) &&

       ((*(uint *)((int)param_1 + 0xd8) & 0x80000) != 0)) {

      ANM_DumpCluster(param_1);

      FUN_00497510(param_1);

    }

    puVar10 = DAT_00632d6c;

    if (DAT_00632d6c != (undefined4 *)0x0) {

      do {

        iVar9 = puVar10[3];

        if ((((*(uint *)(iVar9 + 0xd8) & 0x4000c000) == 0) &&

            (iVar6 = FUN_004a61e0(iVar9), iVar6 != 0)) &&

           (fVar13 = (float10)FUN_0050a610(iVar9 + 0xa0,(int)param_1 + 0xa0), fVar13 < (float10)25.0

           )) {

          fVar7 = *(float *)(iVar9 + 0x278) - 1.0;

          *(float *)(iVar9 + 0x278) = fVar7;

          if (fVar7 < 0.0) {

            *(undefined4 *)(iVar9 + 0x278) = 0;

          }

          sound_play_obj(0x63b,param_1);

          FUN_00497510(param_1);

        }

        puVar10 = (undefined4 *)*puVar10;

      } while (puVar10 != (undefined4 *)0x0);

      return;

    }

    break;

  case 0x29:

    fVar7 = *(float *)((int)param_1 + 0x140);

    if (fVar7 < 0.0) {

      fVar7 = 0.0;

    }

    fVar7 = *(float *)((int)param_1 + 0xa8) - fVar7;

    if (25.0 <= fVar7) {

      if (30.0 <= fVar7) {

        if (-50.0 <= *(float *)((int)param_1 + 0x108)) {

          if (3.0 <= fVar7 - 25.0) {

            fVar13 = (float10)FUN_00518b70(param_1,0);

            *(float *)((int)param_1 + 0x108) =

                 (float)((float10)*(float *)((int)param_1 + 0x108) -

                        fVar13 * (float10)*(float *)((int)param_1 + 0x1b8));

          }

          else if (*(float *)((int)param_1 + 0x108) < -3.0) {

            *(undefined4 *)((int)param_1 + 0x108) = 0xc0400000;

          }

        }

        else {

          *(undefined4 *)((int)param_1 + 0x108) = 0xc2480000;

        }

      }

      else {

        *(undefined4 *)((int)param_1 + 0x108) = 0;

      }

    }

    else {

      *(undefined4 *)((int)param_1 + 0x108) = 0x41000000;

    }

    *(undefined1 *)((int)param_1 + 0x20a) = 0x20;

    fVar13 = (float10)FUN_00518b70(param_1,0);

    fVar13 = (float10)*(float *)((int)param_1 + 0xec) - fVar13;

    *(float *)((int)param_1 + 0xec) = (float)fVar13;

    if (fVar13 < (float10)0.0) {

      *(uint *)((int)param_1 + 0xe4) =

           (-(uint)(*(int *)((int)param_1 + 0xe8) != 1) & 0xfffffffb) + 0x30;

      return;

    }

    break;

  case 0x2a:

    fVar7 = *(float *)((int)param_1 + 0x140);

    *(undefined1 *)((int)param_1 + 0x208) = 0;

    *(undefined1 *)((int)param_1 + 0x20a) = 0;

    if (fVar7 < 0.0) {

      fVar7 = 0.0;

    }

    fVar7 = *(float *)((int)param_1 + 0xa8) - fVar7;

    if (25.0 <= fVar7) {

      if (30.0 <= fVar7) {

        if (-50.0 <= *(float *)((int)param_1 + 0x108)) {

          if (3.0 <= fVar7 - 25.0) {

            fVar13 = (float10)FUN_00518b70(param_1,0);

            *(float *)((int)param_1 + 0x108) =

                 (float)((float10)*(float *)((int)param_1 + 0x108) -

                        fVar13 * (float10)*(float *)((int)param_1 + 0x1b8));

          }

          else if (*(float *)((int)param_1 + 0x108) < -3.0) {

            *(undefined4 *)((int)param_1 + 0x108) = 0xc0400000;

          }

        }

        else {

          *(undefined4 *)((int)param_1 + 0x108) = 0xc2480000;

        }

      }

      else {

        *(undefined4 *)((int)param_1 + 0x108) = 0;

      }

    }

    else {

      *(undefined4 *)((int)param_1 + 0x108) = 0x41000000;

    }

    iVar6 = FUN_004a6160(DAT_00632a88);

    if (((iVar6 == 0) && (iVar6 = FUN_004a6180(DAT_00632a88), iVar6 == 0)) &&

       (iVar6 = FUN_004a61a0(DAT_00632a88), iVar6 == 0)) {

      return;

    }

    fVar13 = (float10)FUN_0050a5e0(DAT_00632a88 + 0xa0,(int)param_1 + 0xa0);

    bVar11 = fVar13 < (float10)22500.0 |

             (byte)((ushort)((ushort)(NAN(fVar13) || NAN((float10)22500.0)) << 10) >> 8);

    goto LAB_0050efca;

  case 0x2b:

    iVar6 = FUN_004a6160(DAT_00632a88);

    if (((iVar6 != 0) || (iVar6 = FUN_004a6180(DAT_00632a88), iVar6 != 0)) ||

       (iVar6 = FUN_004a61a0(DAT_00632a88), iVar6 != 0)) {

      iVar6 = (int)param_1 + 0xa0;

      fVar13 = (float10)FUN_0050a5e0(DAT_00632a88 + 0xa0,iVar6);

      if (fVar13 <= (float10)640000.0) {

        fVar13 = (float10)FUN_0050a400(DAT_00632a88 + 0xa0,iVar6);

        FUN_0050ae40((float)(fVar13 + (float10)40.0),&local_18,&local_14);

        pfVar1[2] = local_18 * 40.0 + *(float *)(DAT_00632a88 + 0xa0);

        pfVar1[3] = *(float *)(DAT_00632a88 + 0xa4) - local_14 * 40.0;

        pfVar1[4] = *(float *)((int)param_1 + 0xa8);

        fVar7 = *(float *)((int)param_1 + 0x140);

        if (fVar7 < 0.0) {

          fVar7 = 0.0;

        }

        fVar7 = *(float *)((int)param_1 + 0xa8) - fVar7;

        if (25.0 <= fVar7) {

          if (30.0 <= fVar7) {

            if (-50.0 <= *(float *)((int)param_1 + 0x108)) {

              if (3.0 <= fVar7 - 25.0) {

                fVar13 = (float10)FUN_00518b70(param_1,0);

                *(float *)((int)param_1 + 0x108) =

                     (float)((float10)*(float *)((int)param_1 + 0x108) -

                            fVar13 * (float10)*(float *)((int)param_1 + 0x1b8));

              }

              else if (*(float *)((int)param_1 + 0x108) < -3.0) {

                *(undefined4 *)((int)param_1 + 0x108) = 0xc0400000;

              }

            }

            else {

              *(undefined4 *)((int)param_1 + 0x108) = 0xc2480000;

            }

          }

          else {

            *(undefined4 *)((int)param_1 + 0x108) = 0;

          }

        }

        else {

          *(undefined4 *)((int)param_1 + 0x108) = 0x41000000;

        }

        fVar13 = (float10)FUN_0050a400(iVar6,pfVar1 + 2);

        *(undefined1 *)((int)param_1 + 0x208) = 0;

        fVar12 = (float10)FUN_0050a7c0((float)fVar13,*(undefined4 *)((int)param_1 + 200));

        *(float *)((int)param_1 + 0x158) = (float)fVar13;

        *(uint *)((int)param_1 + 0xd8) = *(uint *)((int)param_1 + 0xd8) | 0x1000000;

        if (ABS(fVar12) != (float10)0.0) {

          uVar5 = 0xe0;

          if ((float10)0.0 <= fVar12) {

            uVar5 = 0x20;

          }

          *(undefined1 *)((int)param_1 + 0x208) = uVar5;

        }

        uVar5 = __ftol();

        *(undefined1 *)((int)param_1 + 0x20a) = uVar5;

        if (DAT_00632e70 != DAT_005dc8a8) {

          DAT_005dc8a8 = DAT_00632e70;

          fVar13 = (float10)FUN_00518b70(param_1,0);

          _DAT_005dc8a4 = (float)((float10)_DAT_005dc8a4 - fVar13);

        }

        fVar13 = (float10)FUN_00518b70(param_1,0);

        fVar7 = *pfVar1;

        *pfVar1 = (float)((float10)fVar7 - fVar13);

        if (0.0 <= _DAT_005dc8a4) {

          return;

        }

        if ((float10)0.0 <= (float10)fVar7 - fVar13) {

          return;

        }

        _DAT_005dc8a4 = 1.0;

        local_4 = *(float *)((int)param_1 + 0x100);

        param_1 = 250000.0;

        local_c = (float *)0x0;

        for (puVar10 = DAT_00632d6c; puVar10 != (undefined4 *)0x0; puVar10 = (undefined4 *)*puVar10)

        {

          iVar6 = puVar10[3];

          if ((((*(uint *)(iVar6 + 0xd8) & 0x4000c000) == 0) &&

              (iVar8 = FUN_004a61e0(iVar6), iVar8 != 0)) &&

             ((*(float *)(iVar6 + 0x278) < *(float *)(iVar6 + 0x1c0) &&

              ((*(int *)(iVar6 + 0x210) == 0 &&

               (fVar13 = (float10)FUN_0050a5e0(iVar6 + 0xa0,iVar9 + 0xa0),

               fVar13 <= (float10)param_1)))))) {

            param_1 = (float)fVar13;

            local_c = (float *)iVar6;

          }

        }

        *(float **)((int)local_4 + 4) = local_c;

        *pfVar1 = 5.0;

        if (pfVar1[1] == 0.0) {

          return;

        }

        *(undefined4 *)(iVar9 + 0xe4) = 0x2c;

        return;

      }

    }

    *(undefined4 *)((int)param_1 + 0xe4) = 0x2a;

    return;

  case 0x2c:

    if (pfVar1[1] == 0.0) {

      *(undefined4 *)((int)param_1 + 0xe4) = 0x2a;

      return;

    }

    fVar7 = *(float *)((int)param_1 + 0x140);

    if (fVar7 < 0.0) {

      fVar7 = 0.0;

    }

    fVar7 = *(float *)((int)param_1 + 0xa8) - fVar7;

    if (3.0 <= fVar7) {

      if (8.0 <= fVar7) {

        if (-50.0 <= *(float *)((int)param_1 + 0x108)) {

          if (3.0 <= fVar7 - 3.0) {

            fVar13 = (float10)FUN_00518b70(param_1,0);

            *(float *)((int)param_1 + 0x108) =

                 (float)((float10)*(float *)((int)param_1 + 0x108) -

                        fVar13 * (float10)*(float *)((int)param_1 + 0x1b8));

          }

          else if (*(float *)((int)param_1 + 0x108) < -3.0) {

            *(undefined4 *)((int)param_1 + 0x108) = 0xc0400000;

          }

        }

        else {

          *(undefined4 *)((int)param_1 + 0x108) = 0xc2480000;

        }

      }

      else {

        *(undefined4 *)((int)param_1 + 0x108) = 0;

      }

    }

    else {

      *(undefined4 *)((int)param_1 + 0x108) = 0x41000000;

    }

    fVar13 = (float10)FUN_0050a400((int)param_1 + 0xa0,(int)pfVar1[1] + 0xa0);

    *(undefined1 *)((int)param_1 + 0x208) = 0;

    fVar12 = (float10)FUN_0050a7c0((float)fVar13,*(undefined4 *)((int)param_1 + 200));

    local_4 = (float)ABS(fVar12);

    *(uint *)((int)param_1 + 0xd8) = *(uint *)((int)param_1 + 0xd8) | 0x1000000;

    *(float *)((int)param_1 + 0x158) = (float)fVar13;

    if (ABS(fVar12) != (float10)0.0) {

      uVar5 = 0xe0;

      if ((float10)0.0 <= fVar12) {

        uVar5 = 0x20;

      }

      *(undefined1 *)((int)param_1 + 0x208) = uVar5;

    }

    if (10.0 <= local_4) {

      *(undefined1 *)((int)param_1 + 0x20a) = 3;

    }

    else {

      *(undefined1 *)((int)param_1 + 0x20a) = 0x20;

    }

    fVar13 = (float10)FUN_0050a5e0((int)param_1 + 0xa0,(int)pfVar1[1] + 0xa0);

    if (fVar13 < (float10)100.0) {

      *(undefined4 *)((int)param_1 + 0xe4) = 0x2d;

      *(undefined4 *)((int)param_1 + 0xec) = 0x3fc00000;

      return;

    }

    break;

  case 0x2d:

    fVar7 = *(float *)((int)param_1 + 0x140);

    if (fVar7 < 0.0) {

      fVar7 = 0.0;

    }

    fVar7 = *(float *)((int)param_1 + 0xa8) - fVar7;

    if (3.0 <= fVar7) {

      if (8.0 <= fVar7) {

        if (-50.0 <= *(float *)((int)param_1 + 0x108)) {

          if (3.0 <= fVar7 - 3.0) {

            fVar13 = (float10)FUN_00518b70(param_1,0);

            *(float *)((int)param_1 + 0x108) =

                 (float)((float10)*(float *)((int)param_1 + 0x108) -

                        fVar13 * (float10)*(float *)((int)param_1 + 0x1b8));

          }

          else if (*(float *)((int)param_1 + 0x108) < -3.0) {

            *(undefined4 *)((int)param_1 + 0x108) = 0xc0400000;

          }

        }

        else {

          *(undefined4 *)((int)param_1 + 0x108) = 0xc2480000;

        }

      }

      else {

        *(undefined4 *)((int)param_1 + 0x108) = 0;

      }

    }

    else {

      *(undefined4 *)((int)param_1 + 0x108) = 0x41000000;

    }

    local_4 = *(float *)((int)param_1 + 0x100);

    *(undefined1 *)((int)param_1 + 0x208) = 0;

    *(undefined1 *)((int)param_1 + 0x20a) = 0x20;

    param_1 = 250000.0;

    local_c = (float *)0x0;

    for (puVar10 = DAT_00632d6c; puVar10 != (undefined4 *)0x0; puVar10 = (undefined4 *)*puVar10) {

      iVar6 = puVar10[3];

      if ((((*(uint *)(iVar6 + 0xd8) & 0x4000c000) == 0) &&

          (iVar8 = FUN_004a61e0(iVar6), iVar8 != 0)) &&

         ((*(float *)(iVar6 + 0x278) < *(float *)(iVar6 + 0x1c0) &&

          ((*(int *)(iVar6 + 0x210) == 0 &&

           (fVar13 = (float10)FUN_0050a5e0(iVar6 + 0xa0,iVar9 + 0xa0), fVar13 <= (float10)param_1)))

          ))) {

        param_1 = (float)fVar13;

        local_c = (float *)iVar6;

      }

    }

    *(float **)((int)local_4 + 4) = local_c;

    if ((pfVar1[1] != 0.0) &&

       (iVar6 = FUN_0049a3c0(iVar9 + 0x27c,(int)pfVar1[1] + 0x27c), iVar6 != 0)) {

      FUN_00456d00(pfVar1[1],0,1,0x40800000,0,0);

      *(undefined4 *)(iVar9 + 0xe4) = 0x2e;

    }

    goto LAB_0050efb0;

  case 0x2e:

    fVar7 = *(float *)((int)param_1 + 0x140);

    if (fVar7 < 0.0) {

      fVar7 = 0.0;

    }

    fVar7 = *(float *)((int)param_1 + 0xa8) - fVar7;

    if (25.0 <= fVar7) {

      if (30.0 <= fVar7) {

        if (-50.0 <= *(float *)((int)param_1 + 0x108)) {

          if (3.0 <= fVar7 - 25.0) {

            fVar13 = (float10)FUN_00518b70(param_1,0);

            *(float *)((int)param_1 + 0x108) =

                 (float)((float10)*(float *)((int)param_1 + 0x108) -

                        fVar13 * (float10)*(float *)((int)param_1 + 0x1b8));

          }

          else if (*(float *)((int)param_1 + 0x108) < -3.0) {

            *(undefined4 *)((int)param_1 + 0x108) = 0xc0400000;

          }

        }

        else {

          *(undefined4 *)((int)param_1 + 0x108) = 0xc2480000;

        }

      }

      else {

        *(undefined4 *)((int)param_1 + 0x108) = 0;

      }

    }

    else {

      *(undefined4 *)((int)param_1 + 0x108) = 0x41000000;

    }

    *(undefined1 *)((int)param_1 + 0x208) = 8;

    *(undefined1 *)((int)param_1 + 0x20a) = 0x20;

    *(float *)((int)param_1 + 0xec) = *(float *)((int)param_1 + 0xec) * 0.5;

LAB_0050efb0:

    fVar13 = (float10)FUN_00518b70(iVar9,0);

    fVar13 = (float10)*(float *)(iVar9 + 0xec) - fVar13;

    *(float *)(iVar9 + 0xec) = (float)fVar13;

    bVar11 = fVar13 < (float10)0.0 |

             (byte)((ushort)((ushort)(NAN(fVar13) || NAN((float10)0.0)) << 10) >> 8);

LAB_0050efca:

    if ((POPCOUNT(bVar11) & 1U) != 0) {

      *(undefined4 *)(iVar9 + 0xe4) = 0x2b;

      return;

    }

    break;

  case 0x2f:

    *(undefined1 *)((int)param_1 + 0x208) = 0;

    *(undefined1 *)((int)param_1 + 0x20a) = 0;

    if ((*(float *)((int)param_1 + 0x108) < 0.0 != (*(float *)((int)param_1 + 0x108) == 0.0)) &&

       ((uVar2 & 0x80000) != 0)) {

      fVar13 = (float10)FUN_00518b70(param_1,0);

      fVar13 = (float10)*(float *)((int)param_1 + 0xec) - fVar13;

      *(float *)((int)param_1 + 0xec) = (float)fVar13;

      if (fVar13 < (float10)0.0) {

        FUN_00497510(param_1);

      }

    }

    puVar10 = DAT_00632d6c;

    if (DAT_00632d6c != (undefined4 *)0x0) {

      do {

        iVar9 = puVar10[3];

        if ((((*(uint *)(iVar9 + 0xd8) & 0x4000c000) == 0) &&

            (iVar6 = FUN_004a61e0(iVar9), iVar6 != 0)) &&

           (fVar13 = (float10)FUN_0050a610(iVar9 + 0xa0,(int)param_1 + 0xa0), fVar13 < (float10)25.0

           )) {

          fVar7 = *(float *)(iVar9 + 0x278) - 1.0;

          *(float *)(iVar9 + 0x278) = fVar7;

          if (fVar7 < 0.0) {

            *(undefined4 *)(iVar9 + 0x278) = 0;

          }

          sound_play_obj(0x63b,param_1);

          FUN_00497510(param_1);

        }

        puVar10 = (undefined4 *)*puVar10;

      } while (puVar10 != (undefined4 *)0x0);

      return;

    }

    break;

  case 0x30:

    fVar7 = *(float *)((int)param_1 + 0x140);

    if (fVar7 < 0.0) {

      fVar7 = 0.0;

    }

    fVar7 = *(float *)((int)param_1 + 0xa8) - fVar7;

    if (fVar7 < 25.0) {

      *(undefined4 *)((int)param_1 + 0x108) = 0x41000000;

      return;

    }

    if (fVar7 < 30.0) {

      *(undefined4 *)((int)param_1 + 0x108) = 0;

      return;

    }

    if (*(float *)((int)param_1 + 0x108) < -50.0) {

      *(undefined4 *)((int)param_1 + 0x108) = 0xc2480000;

      return;

    }

    fVar7 = fVar7 - 25.0;

LAB_0050e4da:

    if (3.0 <= fVar7) {

      fVar13 = (float10)FUN_00518b70(param_1,0);

      *(float *)((int)param_1 + 0x108) =

           (float)((float10)*(float *)((int)param_1 + 0x108) -

                  fVar13 * (float10)*(float *)((int)param_1 + 0x1b8));

      return;

    }

    if (*(float *)((int)param_1 + 0x108) < -3.0) {

      *(undefined4 *)((int)param_1 + 0x108) = 0xc0400000;

      return;

    }

    break;

  case 0x3d:

    if (local_4 != 0.0) {

      sound_play_obj(0x52b,param_1);

      *(undefined4 *)((int)param_1 + 0xe4) = 0x3e;

      anim_select_check2(param_1,1);

      *(uint *)((int)param_1 + 0x30) = *(uint *)((int)param_1 + 0x30) | 4;

      return;

    }

    break;

  case 0x3e:

    fVar13 = (float10)FUN_00518b70(param_1,0);

    fVar13 = (float10)*(float *)((int)param_1 + 0xec) - fVar13;

    *(float *)((int)param_1 + 0xec) = (float)fVar13;

    if (fVar13 < (float10)0.0) {

      *(uint *)((int)param_1 + 0x30) = *(uint *)((int)param_1 + 0x30) & 0xfffffffb;

      *(undefined4 *)((int)param_1 + 0xe4) = 0x3f;

      return;

    }

    break;

  case 0x3f:

    if (local_4 != 0.0) {

      iVar9 = object_allocate_type(0x232,0x80000000);

      if ((*(uint *)((int)param_1 + 0xd8) & 0x400) != 0) {

        *(uint *)(iVar9 + 0xd8) = *(uint *)(iVar9 + 0xd8) | 0x400;

      }

      puVar10 = *(undefined4 **)(iVar9 + 0x100);

      FUN_004979b0(iVar9,param_1);

      FUN_00499280(iVar9);

      *(undefined4 *)(iVar9 + 0x178) = *(undefined4 *)(iVar9 + 0xa0);

      *(undefined4 *)(iVar9 + 0x17c) = *(undefined4 *)(iVar9 + 0xa4);

      *(undefined4 *)(iVar9 + 0x180) = *(undefined4 *)(iVar9 + 0xa8);

      fVar13 = (float10)FUN_0050a400(DAT_00632a88 + 0xa0,(undefined4 *)(iVar9 + 0xa0));

      *(float *)((int)param_1 + 200) = (float)fVar13;

      *puVar10 = 0x40a00000;

      *(undefined4 *)(iVar9 + 0xe4) = 10;

      fVar13 = (float10)FUN_004d5780(0x41700000,0x41c80000);

      puVar10[5] = (float)fVar13;

      puVar10[9] = 0;

      *(undefined4 *)(iVar9 + 0x108) = 0x41f00000;

      iVar9 = object_allocate_type(0x240,0x80000000);

      if ((*(uint *)((int)param_1 + 0xd8) & 0x400) != 0) {

        *(uint *)(iVar9 + 0xd8) = *(uint *)(iVar9 + 0xd8) | 0x400;

      }

      FUN_004979b0(iVar9,param_1);

      FUN_00499280(iVar9);

      *(undefined4 *)(iVar9 + 0x178) = *(undefined4 *)(iVar9 + 0xa0);

      *(undefined4 *)(iVar9 + 0x17c) = *(undefined4 *)(iVar9 + 0xa4);

      *(undefined4 *)(iVar9 + 0x180) = *(undefined4 *)(iVar9 + 0xa8);

      *(undefined4 *)(iVar9 + 0xe4) = 0x40;

      iVar9 = 0xf;

      do {

        iVar6 = object_allocate_type(0x241,0x80000000);

        if ((*(uint *)((int)param_1 + 0xd8) & 0x400) != 0) {

          *(uint *)(iVar6 + 0xd8) = *(uint *)(iVar6 + 0xd8) | 0x400;

        }

        FUN_004979b0(iVar6,param_1);

        object_change_ospec(iVar6,0x32);

        FUN_00499280(iVar6);

        *(undefined4 *)(iVar6 + 0x178) = *(undefined4 *)(iVar6 + 0xa0);

        *(undefined4 *)(iVar6 + 0x17c) = *(undefined4 *)(iVar6 + 0xa4);

        *(undefined4 *)(iVar6 + 0x180) = *(undefined4 *)(iVar6 + 0xa8);

        fVar13 = (float10)FUN_004d5780(0xc2200000,0x42200000);

        *(float *)(iVar6 + 0x128) = (float)fVar13;

        fVar13 = (float10)FUN_004d5780(0xc2200000,0x42200000);

        *(float *)(iVar6 + 300) = (float)fVar13;

        fVar13 = (float10)FUN_004d5780(0x41f00000,0x428c0000);

        *(float *)(iVar6 + 0x130) = (float)fVar13;

        fVar13 = (float10)FUN_004d5760(0x43b40000);

        *(float *)(iVar6 + 200) = (float)fVar13;

        fVar13 = (float10)FUN_004d5760(0x40000000);

        *(float *)(iVar6 + 0x14) = (float)fVar13;

        iVar9 = iVar9 + -1;

        *(undefined4 *)(iVar6 + 0xec) = 0x40400000;

        *(undefined4 *)(iVar6 + 0xe4) = 0xffffffff;

      } while (iVar9 != 0);

      sound_play_3dpos(0x52c,(int)param_1 + 0xa0);

      FUN_00497510(param_1);

      return;

    }

  }

  return;

}

