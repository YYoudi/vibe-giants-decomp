/* Giants 1.449 — module _unmapped_004a
 * 131 functions (24 named) — decompiled, names from PS2 symbols
 * Original source: C:\Giants\source\_unmapped_004a.c(pp) (assert-string evidence)
 */

/* ===== main/path_004a0a00 @ 0x004A0A00 ===== */
void main_path_004a0a00(undefined4 *param_1)



{

  uint *puVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  uint uVar7;

  undefined4 *puVar8;

  

  if (4999 < DAT_005a0cb8) {

    DAT_005a0cbc = DAT_005a0cbc + 1;

    return;

  }

  puVar8 = (undefined4 *)(DAT_005a0cd8 + DAT_005a0cb8 * 0x18);

  for (iVar6 = 6; iVar6 != 0; iVar6 = iVar6 + -1) {

    *puVar8 = *param_1;

    param_1 = param_1 + 1;

    puVar8 = puVar8 + 1;

  }

  puVar1 = (uint *)(DAT_005a0cd8 + DAT_005a0cb8 * 0x18);

  uVar7 = *puVar1 % 0xfb;

  puVar1[5] = *(uint *)(DAT_005a0cd4 + uVar7 * 4);

  *(int *)(DAT_005a0cd4 + uVar7 * 4) = DAT_005a0cd8 + DAT_005a0cb8 * 0x18;

  iVar6 = DAT_005a0cd8 + DAT_005a0cb8 * 0x18;

  if (DAT_005a0cdc < DAT_005a0ce0) {

    DAT_005a0cdc = DAT_005a0cdc + 1;

    *(int *)(DAT_005a0ce4 + DAT_005a0cdc * 4) = iVar6;

    iVar5 = DAT_005a0ce4;

    iVar2 = *(int *)(DAT_005a0ce4 + DAT_005a0cdc * 4);

    iVar4 = DAT_005a0cdc;

    while (1 < iVar4) {

      iVar3 = *(int *)(iVar5 + (iVar4 >> 1) * 4);

      if (*(float *)(iVar3 + 4) < *(float *)(iVar2 + 4)) break;

      *(int *)(iVar5 + iVar4 * 4) = iVar3;

      iVar4 = iVar4 >> 1;

    }

    *(int *)(iVar5 + iVar4 * 4) = iVar2;

    puVar1 = (uint *)(iVar6 + 0x10);

    *puVar1 = *puVar1 | 0x80000000;

  }

  DAT_005a0cb8 = DAT_005a0cb8 + 1;

  if (DAT_005a0cbc < DAT_005a0cb8) {

    DAT_005a0cbc = DAT_005a0cb8;

  }

  return;

}

/* ===== ObjectTransformIntegrity_2 @ 0x004A0B00 ===== */
void ObjectTransformIntegrity_2(int param_1,int param_2)



{

  *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_2 + 4);

  *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_2 + 8);

  *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_2 + 0xc);

  return;

}

/* ===== main/path_004a0b20 @ 0x004A0B20 ===== */
/* PS2 candidate: path_est__FP5ANODEP9PathPoint (conf 0.53) */



float10 main_path_004a0b20(uint *param_1,int param_2)



{

  float10 fVar1;

  float10 fVar2;

  

  fVar1 = (float10)(int)((*param_1 >> 0xc & 0xfff) - *(int *)(param_2 + 0xc));

  fVar2 = (float10)(int)((*param_1 & 0xfff) - *(int *)(param_2 + 0x10));

  return SQRT(fVar1 * fVar1 + fVar2 * fVar2);

}

/* ===== main/path_004a0b70 @ 0x004A0B70 ===== */
/* PS2 candidate: path_blocked_long__FP9PathPointT0 (conf 0.634) */



undefined4 main_path_004a0b70(uint param_1,int param_2)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  bool bVar7;

  int local_c;

  int local_8;

  uint local_4;

  

  local_8 = *(int *)(param_1 + 0xc);

  local_c = *(int *)(param_1 + 0x10);

  iVar6 = *(int *)(param_2 + 0xc) - local_8;

  param_1 = (uint)*(byte *)(param_1 + 0x14);

  iVar4 = *(int *)(param_2 + 0x10) - local_c;

  param_2 = 3;

  if (iVar4 < 0) {

    iVar4 = -iVar4;

    param_2 = 2;

  }

  bVar7 = iVar6 < 0;

  if (bVar7) {

    iVar6 = -iVar6;

  }

  local_4 = (uint)!bVar7;

  if (iVar4 < iVar6) {

    iVar4 = iVar4 * 2;

    iVar1 = iVar6 * -2;

    iVar5 = iVar4 - iVar6;

    while (iVar6 != 0) {

      iVar6 = iVar6 + -1;

      iVar2 = main_path_004a0d00(local_8,local_c,param_1,local_4,&local_8,&local_c,&param_1);

      if (iVar2 != 0) {

        return 1;

      }

      iVar2 = iVar4;

      if ((-1 < iVar5) &&

         (iVar3 = main_path_004a0d00(local_8,local_c,param_1,param_2,&local_8,&local_c,&param_1),

         iVar2 = iVar4 + iVar1, iVar3 != 0)) {

        return 1;

      }

      iVar5 = iVar5 + iVar2;

    }

  }

  else {

    iVar6 = iVar6 * 2;

    iVar1 = iVar4 * -2;

    iVar5 = iVar6 - iVar4;

    if (iVar4 != 0) {

      while( true ) {

        iVar4 = iVar4 + -1;

        iVar2 = main_path_004a0d00(local_8,local_c,param_1,param_2,&local_8,&local_c,&param_1);

        if ((iVar2 != 0) ||

           ((iVar2 = iVar6, -1 < iVar5 &&

            (iVar3 = main_path_004a0d00(local_8,local_c,param_1,local_4,&local_8,&local_c,&param_1),

            iVar2 = iVar6 + iVar1, iVar3 != 0)))) break;

        iVar5 = iVar5 + iVar2;

        if (iVar4 == 0) {

          return 0;

        }

      }

      return 1;

    }

  }

  return 0;

}

/* ===== main/path_004a0d00 @ 0x004A0D00 ===== */
undefined1

main_path_004a0d00(int param_1,int param_2,int param_3,int param_4,int *param_5,int *param_6,

                  int *param_7)



{

  undefined4 uVar1;

  int iVar2;

  

  if (DAT_005a0ce8 != 0) {

    switch(param_4) {

    case 0:

      param_1 = param_1 + -1;

      break;

    case 1:

      param_1 = param_1 + 1;

      break;

    case 2:

      param_2 = param_2 + -1;

      break;

    case 3:

      param_2 = param_2 + 1;

    }

    if (param_1 < 0) {

      return 1;

    }

    if (param_2 < 0) {

      return 1;

    }

    if (param_1 < 0x40) {

      if (param_2 < 0x40) {

        *param_5 = param_1;

        *param_6 = param_2;

        *param_7 = 0;

        return *(undefined1 *)(param_2 * 0x40 + DAT_005a0cec + param_1);

      }

      return 1;

    }

    return 1;

  }

  if (param_1 < 0) {

    return 0;

  }

  if (param_2 < 0) {

    return 0;

  }

  if (*(int *)(DAT_006330e4 + 0x1d8) <= param_1) {

    return 0;

  }

  if (*(int *)(DAT_006330e4 + 0x1dc) <= param_2) {

    return 0;

  }

  switch(param_4) {

  case 0:

    param_1 = param_1 + -1;

    break;

  case 1:

    param_1 = param_1 + 1;

    break;

  case 2:

    param_2 = param_2 + -1;

    break;

  case 3:

    param_2 = param_2 + 1;

  }

  if ((((param_1 < 0) || (param_2 < 0)) || (*(int *)(DAT_006330e4 + 0x1d8) <= param_1)) ||

     ((*(int *)(DAT_006330e4 + 0x1dc) <= param_2 || (param_3 == 0)))) {

    iVar2 = 0;

    goto LAB_004a0eb3;

  }

  uVar1 = FUN_00455190(param_1,param_2);

  switch(uVar1) {

  case 2:

switchD_004a0e2f_caseD_2:

    iVar2 = 4;

    break;

  case 4:

switchD_004a0e2f_caseD_4:

    iVar2 = 3;

    break;

  case 5:

    if (0 < param_4) {

      if (param_4 < 3) goto switchD_004a0e2f_caseD_4;

      if (param_4 == 4) {

        iVar2 = (param_3 == 2) + 2;

        break;

      }

    }

  default:

    iVar2 = 2;

    break;

  case 6:

    if ((param_4 == 0) || (param_4 == 2)) goto switchD_004a0e2f_caseD_2;

    if (param_4 == 4) {

      iVar2 = (-(uint)(param_3 != 1) & 0xfffffffd) + 4;

      break;

    }

  case 1:

    iVar2 = 1;

  }

LAB_004a0eb3:

  if ((((-1 < param_1) && (-1 < param_2)) && (param_1 < *(int *)(DAT_006330e4 + 0x1d8))) &&

     (param_2 < *(int *)(DAT_006330e4 + 0x1dc))) {

    if (*(char *)(*(int *)(*(int *)(DAT_006330e4 + 0x10) + param_2 * 4) + 0xe + param_1 * 0x10) !=

        '\0') {

      return 1;

    }

    *param_5 = param_1;

    *param_6 = param_2;

    *param_7 = iVar2;

  }

  return 0;

}

/* ===== FUN_004a1250 @ 0x004A1250 ===== */
/* PS2 candidate: path_flyer_calculate (conf 0.692) */



void FUN_004a1250(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,float param_5

                 ,undefined4 param_6,undefined4 param_7,undefined4 param_8)



{

  main_path_004a0f40(param_1,param_2,param_3,param_4,param_5,

                     *(float *)(param_1 + 0x1e8) * *(float *)(param_1 + 0xc4) + param_5,param_6,

                     param_7,param_8);

  return;

}

/* ===== FUN_004a12a0 @ 0x004A12A0 ===== */
/* PS2 candidate: path_short_calculate (conf 0.636) */



void FUN_004a12a0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,

                 undefined4 param_5,undefined4 param_6,undefined4 param_7)



{

  main_path_004a0f40(param_1,param_2,param_3,param_4,0,

                     *(float *)(param_1 + 0x1e8) * *(float *)(param_1 + 0xc4),param_5,param_6,

                     param_7);

  return;

}

/* ===== FUN_004a12f0 @ 0x004A12F0 ===== */
/* PS2 candidate: heap_siftup__FPP5ANODEi (conf 0.558) */



void FUN_004a12f0(int param_1,int param_2)



{

  int iVar1;

  int iVar2;

  

  iVar1 = *(int *)(param_1 + param_2 * 4);

  while (1 < param_2) {

    iVar2 = *(int *)(param_1 + (param_2 >> 1) * 4);

    if (*(float *)(iVar2 + 4) < *(float *)(iVar1 + 4)) break;

    *(int *)(param_1 + param_2 * 4) = iVar2;

    param_2 = param_2 >> 1;

  }

  *(int *)(param_1 + param_2 * 4) = iVar1;

  return;

}

/* ===== FUN_004a1330 @ 0x004A1330 ===== */
void FUN_004a1330(int param_1)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  

  if (DAT_005a0cdc < DAT_005a0ce0) {

    DAT_005a0cdc = DAT_005a0cdc + 1;

    *(int *)(DAT_005a0ce4 + DAT_005a0cdc * 4) = param_1;

    iVar4 = DAT_005a0ce4;

    iVar1 = *(int *)(DAT_005a0ce4 + DAT_005a0cdc * 4);

    iVar3 = DAT_005a0cdc;

    while (1 < iVar3) {

      iVar2 = *(int *)(iVar4 + (iVar3 >> 1) * 4);

      if (*(float *)(iVar2 + 4) < *(float *)(iVar1 + 4)) break;

      *(int *)(iVar4 + iVar3 * 4) = iVar2;

      iVar3 = iVar3 >> 1;

    }

    *(int *)(iVar4 + iVar3 * 4) = iVar1;

    *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) | 0x80000000;

  }

  return;

}

/* ===== endDisplay__Fv @ 0x004A13A0 ===== */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */



void endDisplay__Fv(void)



{

  DAT_005a0ec4 = 0;

  DAT_0055e9e8 = 0xffffffff;

  return;

}

/* ===== FUN_004a13c0 @ 0x004A13C0 ===== */
int FUN_004a13c0(char *param_1)



{

  char cVar1;

  undefined4 uVar2;

  char *local_10;

  char *local_c;

  int local_8;

  

  FUN_004a14b0();

  local_8 = 0;

  while ((local_8 < 0x10 && ((DAT_005a0ec4 & 1 << ((byte)local_8 & 0x1f)) != 0))) {

    local_8 = local_8 + 1;

  }

  if (local_8 == 0x10) {

    local_8 = 0;

  }

  local_c = param_1;

  local_10 = &DAT_005a0d00 + local_8 * 0x10;

  do {

    cVar1 = *local_c;

    *local_10 = cVar1;

    local_c = local_c + 1;

    local_10 = local_10 + 1;

  } while (cVar1 != '\0');

  uVar2 = FUN_004a14a0();

  *(undefined4 *)(&DAT_005a0e80 + local_8 * 4) = uVar2;

  *(undefined4 *)(&DAT_005a0e00 + local_8 * 4) = 0;

  DAT_005a0ec4 = DAT_005a0ec4 | 1 << ((byte)local_8 & 0x1f);

  DAT_0055e9e8 = local_8;

  return local_8;

}

/* ===== FUN_004a14a0 @ 0x004A14A0 ===== */
undefined8 FUN_004a14a0(void)



{

  undefined8 uVar1;

  

  uVar1 = rdtsc();

  return uVar1;

}

/* ===== FUN_004a14b0 @ 0x004A14B0 ===== */
/* PS2 candidate: Audio3DTestToneStop__Fv (conf 0.51) */



void FUN_004a14b0(void)



{

  int iVar1;

  

  if (DAT_0055e9e8 != -1) {

    iVar1 = FUN_004a14a0();

    *(int *)(&DAT_005a0e00 + DAT_0055e9e8 * 4) =

         (iVar1 - *(int *)(&DAT_005a0e80 + DAT_0055e9e8 * 4)) +

         *(int *)(&DAT_005a0e00 + DAT_0055e9e8 * 4);

    DAT_0055e9e8 = -1;

  }

  return;

}

/* ===== AddHud__4cHudP8cHudIcon_2 @ 0x004A1500 ===== */
void AddHud__4cHudP8cHudIcon_2(void)



{

  FUN_004a14b0();

  return;

}

/* ===== FUN_004a1740 @ 0x004A1740 ===== */
/* PS2 candidate: PhysicsExInit (conf 0.605) */



void FUN_004a1740(int param_1)



{

  undefined4 *puVar1;

  

  puVar1 = *(undefined4 **)(param_1 + 0x104);

  puVar1[3] = 0;

  puVar1[4] = 0x3f800000;

  *puVar1 = 0;

  puVar1[8] = 0;

  puVar1[7] = 0;

  puVar1[6] = 0;

  puVar1[2] = 0x3f800000;

  puVar1[1] = 0x3f800000;

  puVar1[0xc] = 0;

  puVar1[0xe] = 0;

  puVar1[0xd] = 0;

  puVar1[10] = 0;

  puVar1[0xb] = 0;

  puVar1[9] = 0;

  return;

}

/* ===== PhysicsExZeroVelocity @ 0x004A1780 ===== */
void PhysicsExZeroVelocity(int param_1)



{

  *(undefined4 *)(param_1 + 0x130) = 0;

  *(undefined4 *)(param_1 + 300) = 0;

  *(undefined4 *)(param_1 + 0x128) = 0;

  return;

}

/* ===== PhysicsExZeroForce @ 0x004A17A0 ===== */
void PhysicsExZeroForce(int param_1)



{

  int iVar1;

  

  iVar1 = *(int *)(param_1 + 0x104);

  *(undefined4 *)(iVar1 + 0x20) = 0;

  *(undefined4 *)(iVar1 + 0x1c) = 0;

  *(undefined4 *)(iVar1 + 0x18) = 0;

  return;

}

/* ===== FUN_004a17c0 @ 0x004A17C0 ===== */
void FUN_004a17c0(int param_1,float param_2)



{

  if ((param_2 < *(float *)(param_1 + 0x2c)) || (*(float *)(param_1 + 0x2c) == 0.0)) {

    *(float *)(param_1 + 0x2c) = param_2;

  }

  return;

}

/* ===== FUN_004a17f0 @ 0x004A17F0 ===== */
/* PS2 candidate: PhysicsExCollisionPlane (conf 0.511) */



void FUN_004a17f0(int param_1,float *param_2,float *param_3)



{

  uint *puVar1;

  float fVar2;

  float fVar3;

  

  puVar1 = *(uint **)(param_1 + 0x104);

  fVar2 = *param_2 * *param_3 + param_2[2] * param_3[2] + param_2[1] * param_3[1] + param_3[3];

  if (fVar2 < 0.0) {

    fVar3 = (float)puVar1[3] + 1.0;

    *(float *)(param_1 + 0xa0) = *(float *)(param_1 + 0xa0) - fVar3 * *param_3 * fVar2;

    *(float *)(param_1 + 0xa4) = *(float *)(param_1 + 0xa4) - fVar3 * param_3[1] * fVar2;

    *(float *)(param_1 + 0xa8) = *(float *)(param_1 + 0xa8) - fVar3 * fVar2 * param_3[2];

    fVar2 = *param_3 * *(float *)(param_1 + 0x128) +

            *(float *)(param_1 + 300) * param_3[1] + *(float *)(param_1 + 0x130) * param_3[2];

    *(float *)(param_1 + 0x128) = *(float *)(param_1 + 0x128) - fVar2 * *param_3 * fVar3;

    *(float *)(param_1 + 300) = *(float *)(param_1 + 300) - fVar2 * param_3[1] * fVar3;

    *(float *)(param_1 + 0x130) = *(float *)(param_1 + 0x130) - fVar2 * fVar3 * param_3[2];

    *puVar1 = *puVar1 | 2;

  }

  return;

}

/* ===== FUN_004a18d0 @ 0x004A18D0 ===== */
/* PS2 candidate: PhysicsExCollisionPlane2_OLD__FP6OBJECTP3P3DN31P7PLANE3D (conf 0.551) */



void FUN_004a18d0(int param_1,float *param_2,float *param_3,float *param_4,undefined4 param_5,

                 float *param_6,int param_7)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  uint *puVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  float fVar11;

  float fVar12;

  

  puVar5 = *(uint **)(param_1 + 0x104);

  fVar9 = *param_2 * *param_6 + param_6[1] * param_2[1] + param_2[2] * param_6[2] + param_6[3];

  if (fVar9 < 0.0) {

    fVar12 = (float)puVar5[3] + 1.0;

    fVar3 = *param_3 * *param_6 + param_6[1] * param_3[1] + param_3[2] * param_6[2] + param_6[3];

    if (fVar3 < 0.0) {

      fVar4 = *param_2 - fVar9 * *param_6;

      fVar11 = param_2[1] - fVar9 * param_6[1];

      fVar10 = param_2[2] - fVar9 * param_6[2];

    }

    else {

      fVar10 = fVar3 / (fVar3 - fVar9);

      fVar4 = (*param_2 - *param_3) * fVar10 + *param_3;

      fVar11 = (param_2[1] - param_3[1]) * fVar10 + param_3[1];

      fVar10 = (param_2[2] - param_3[2]) * fVar10 + param_3[2];

    }

    fVar6 = *param_2;

    fVar7 = param_2[1];

    fVar8 = param_2[2];

    fVar1 = param_6[1];

    fVar2 = param_6[2];

    *param_2 = ((*param_2 - fVar12 * *param_6 * fVar9) - fVar4) * (float)puVar5[4] + fVar4;

    param_2[1] = ((param_2[1] - fVar12 * fVar1 * fVar9) - fVar11) * (float)puVar5[4] + fVar11;

    fVar10 = ((param_2[2] - fVar12 * fVar9 * fVar2) - fVar10) * (float)puVar5[4] + fVar10;

    param_2[2] = fVar10;

    if (((param_7 == 0) && ((*puVar5 & 0x400) != 0)) && (fVar3 < -0.1)) {

      fVar9 = *param_2 - *param_3;

      fVar3 = param_2[1] - param_3[1];

      fVar10 = fVar10 - param_3[2];

      fVar6 = fVar6 - *param_3;

      fVar7 = fVar7 - param_3[1];

      fVar8 = fVar8 - param_3[2];

      fVar4 = fVar6 * fVar9 + fVar7 * fVar3 + fVar8 * fVar10;

      if (((fVar4 < 0.0 != (fVar4 == 0.0)) ||

          (fVar11 = fVar9 * fVar9 + fVar3 * fVar3 + fVar10 * fVar10, fVar11 <= 0.001)) ||

         (fVar6 * fVar6 + fVar7 * fVar7 + fVar8 * fVar8 <= 0.001)) {

        *param_2 = *param_3;

        param_2[1] = param_3[1];

        param_2[2] = param_3[2];

      }

      else {

        fVar4 = fVar4 / SQRT(fVar11);

        if (1.0 < fVar4) {

          fVar4 = 1.0;

        }

        fVar4 = fVar4 - 1.0;

        *param_2 = fVar9 * fVar4 + *param_2;

        param_2[1] = fVar3 * fVar4 + param_2[1];

        param_2[2] = fVar4 * fVar10 + param_2[2];

      }

    }

    fVar9 = *param_4 * *param_6 + param_4[2] * param_6[2] + param_6[1] * param_4[1];

    if (fVar9 < 0.0) {

      fVar3 = param_6[1];

      fVar4 = param_6[2];

      *param_4 = (*param_4 - fVar9 * *param_6 * fVar12) * (float)puVar5[4];

      param_4[1] = (param_4[1] - fVar9 * fVar3 * fVar12) * (float)puVar5[4];

      param_4[2] = (param_4[2] - fVar9 * fVar12 * fVar4) * (float)puVar5[4];

      *puVar5 = *puVar5 | 2;

      return;

    }

    *puVar5 = *puVar5 | 2;

  }

  return;

}

/* ===== FUN_004a1bd0 @ 0x004A1BD0 ===== */
void FUN_004a1bd0(int param_1)



{

  float fVar1;

  

  if ((param_1 != 0) &&

     (fVar1 = *(float *)(param_1 + 0xa8) * *(float *)(param_1 + 0xa8) +

              *(float *)(param_1 + 0xa4) * *(float *)(param_1 + 0xa4) +

              *(float *)(param_1 + 0xa0) * *(float *)(param_1 + 0xa0), 8.1e+07 < fVar1)) {

    fVar1 = SQRT(8.1e+07 / fVar1);

    *(float *)(param_1 + 0xa0) = fVar1 * *(float *)(param_1 + 0xa0);

    *(float *)(param_1 + 0xa4) = fVar1 * *(float *)(param_1 + 0xa4);

    *(float *)(param_1 + 0xa8) = fVar1 * *(float *)(param_1 + 0xa8);

    return;

  }

  return;

}

/* ===== FUN_004a1c50 @ 0x004A1C50 ===== */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

/* WARNING: Struct "OBJECT": ignoring multiple overlapping fields */



void FUN_004a1c50(OBJECT *obj)



{

  dword *pdVar1;

  float fVar2;

  int iVar3;

  float fVar4;

  float10 fVar5;

  float10 fVar6;

  float10 fVar7;

  

  iVar3 = *(int *)&obj->field_0x104;

  if (*(int *)&obj->field_0x210 != 0) {

    if ((*(uint *)&obj->field_0xdc & 0x1000) == 0) {

      *(undefined4 *)&obj->field_0x130 = 0;

      *(undefined4 *)&obj->field_0x12c = 0;

      obj->gap_128 = 0;

      obj->acc_TargetCenter = 0;

      obj->acc_TargetCenter = 0;

      obj->acc_army_platoon_base_attack = 0;

    }

    *(undefined4 *)(iVar3 + 0x20) = 0;

    *(undefined4 *)(iVar3 + 0x1c) = 0;

    *(undefined4 *)(iVar3 + 0x18) = 0;

    return;

  }

  fVar5 = (float10)FUN_00518b70(obj,0);

  *(float *)(iVar3 + 0x14) = (float)fVar5;

  fVar6 = fVar5;

  if ((0.0 < *(float *)(iVar3 + 0x2c)) && ((float10)*(float *)(iVar3 + 0x2c) < fVar5)) {

    fVar6 = (float10)*(float *)(iVar3 + 0x2c);

  }

  *(undefined4 *)(iVar3 + 0x2c) = 0;

  pdVar1 = &obj->gap_128;

  obj->acc_army_platoon_base_attack = *pdVar1;

  obj->acc_TargetCenter = *(dword *)&obj->field_0x12c;

  obj->acc_TargetCenter = *(dword *)&obj->field_0x130;

  fVar7 = (float10)1.0 / (float10)*(float *)(iVar3 + 8);

  *pdVar1 = (dword)(float)(fVar7 * (float10)*(float *)(iVar3 + 0x18) * fVar6 +

                          (float10)(float)*pdVar1);

  *(float *)&obj->field_0x12c =

       (float)(fVar7 * (float10)*(float *)(iVar3 + 0x1c) * fVar6 +

              (float10)*(float *)&obj->field_0x12c);

  fVar6 = fVar7 * (float10)*(float *)(iVar3 + 0x20) * fVar6 + (float10)*(float *)&obj->field_0x130;

  *(float *)&obj->field_0x130 = (float)fVar6;

  if ((*(float *)(iVar3 + 0x28) != 0.0) &&

     (fVar2 = (float)SQRT((float10)(float)*pdVar1 * (float10)(float)*pdVar1 +

                          (float10)*(float *)&obj->field_0x12c *

                          (float10)*(float *)&obj->field_0x12c + fVar6 * fVar6), fVar2 != 0.0)) {

    fVar4 = 1.0;

    if (*(float *)(iVar3 + 0x28) < fVar2) {

      fVar4 = *(float *)(iVar3 + 0x28) / fVar2;

    }

    *pdVar1 = (dword)(fVar4 * (float)*pdVar1);

    *(float *)&obj->field_0x12c = fVar4 * *(float *)&obj->field_0x12c;

    *(float *)&obj->field_0x130 = fVar4 * *(float *)&obj->field_0x130;

  }

  obj->gap_A0 = (dword)(float)(((float10)(float)*pdVar1 +

                               (float10)(float)obj->acc_army_platoon_base_attack) * fVar5 *

                               (float10)0.5 + (float10)(float)obj->gap_A0);

  *(float *)&obj->field_0xa4 =

       (float)(((float10)(float)obj->acc_TargetCenter + (float10)*(float *)&obj->field_0x12c) *

               fVar5 * (float10)0.5 + (float10)*(float *)&obj->field_0xa4);

  *(float *)&obj->field_0xa8 =

       (float)(((float10)(float)obj->acc_TargetCenter + (float10)*(float *)&obj->field_0x130) *

               fVar5 * (float10)0.5 + (float10)*(float *)&obj->field_0xa8);

  *(undefined4 *)(iVar3 + 0x20) = 0;

  *(undefined4 *)(iVar3 + 0x1c) = 0;

  *(undefined4 *)(iVar3 + 0x18) = 0;

  return;

}

/* ===== FUN_004a1e30 @ 0x004A1E30 ===== */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

/* WARNING: Struct "OBJECT": ignoring multiple overlapping fields */



void FUN_004a1e30(OBJECT *obj)



{

  dword *pdVar1;

  uint *puVar2;

  float fVar3;

  float fVar4;

  bool bVar5;

  bool bVar6;

  int iVar7;

  float *pfVar8;

  float *pfVar9;

  float10 fVar10;

  int local_70;

  float local_6c;

  dword local_68;

  undefined4 local_64;

  float local_60;

  undefined4 local_5c;

  undefined4 local_58;

  float local_54;

  dword local_50;

  undefined4 local_4c;

  undefined4 local_48;

  float local_44;

  float local_40;

  float local_3c;

  float local_38 [4];

  dword local_28;

  int local_24;

  int local_20;

  float local_1c [5];

  int local_8;

  int local_4;

  

  local_64 = *(undefined4 *)&obj->field_0xa4;

  local_54 = *(float *)&obj->field_0xc4 * (float)obj->acc_popup_pre_logic;

  local_68 = obj->gap_A0;

  local_5c = *(undefined4 *)&obj->field_0xac;

  local_60 = *(float *)&obj->field_0xa8 - local_54;

  pdVar1 = &obj->gap_128;

  local_58 = *(undefined4 *)&obj->field_0xb0;

  local_54 = (float)obj->acc_army_platoon_coordinated - local_54;

  local_50 = *pdVar1;

  local_4c = *(undefined4 *)&obj->field_0x12c;

  local_48 = *(undefined4 *)&obj->field_0x130;

  puVar2 = *(uint **)&obj->field_0x104;

  bVar6 = false;

  bVar5 = true;

  local_70 = 3;

  do {

    if (bVar5) {

      FUN_00414690(&local_68,local_38);

      bVar5 = false;

    }

    else {

      pfVar8 = local_38;

      pfVar9 = local_1c;

      for (iVar7 = 7; iVar7 != 0; iVar7 = iVar7 + -1) {

        *pfVar9 = *pfVar8;

        pfVar8 = pfVar8 + 1;

        pfVar9 = pfVar9 + 1;

      }

      FUN_00414690(&local_68,local_38);

      if ((local_4 == local_20) && (local_8 == local_24)) break;

      iVar7 = FUN_0053f440(&local_44,local_38,local_1c,&DAT_0055ea40);

      if (iVar7 != 0) {

        *pdVar1 = local_50;

        local_60 = *(float *)&obj->field_0xa8 -

                   *(float *)&obj->field_0xc4 * (float)obj->acc_popup_pre_logic;

        *(undefined4 *)&obj->field_0x12c = local_4c;

        local_68 = obj->gap_A0;

        *(undefined4 *)&obj->field_0x130 = local_48;

        local_64 = *(undefined4 *)&obj->field_0xa4;

        local_38[0] = local_38[0] + local_1c[0];

        local_38[1] = local_38[1] + local_1c[1];

        fVar4 = local_38[2] + local_1c[2];

        fVar3 = local_38[0] * local_38[0] + local_38[1] * local_38[1] + fVar4 * fVar4;

        if (fVar3 == 0.0) {

          local_38[2] = 0.0;

        }

        else {

          local_38[2] = (float)((&DAT_005f0a18)[(uint)fVar3 >> 8 & 0xffff] |

                               ((int)fVar3 + 0xc0800000U >> 1) + 0x3f800000 & 0x7f800000);

        }

        local_38[2] = 1.0 / local_38[2];

        local_24 = -1;

        bVar6 = true;

        local_38[0] = local_38[2] * local_38[0];

        local_38[1] = local_38[1] * local_38[2];

        local_38[2] = local_38[2] * fVar4;

        local_38[3] = -(local_44 * local_38[0] + local_40 * local_38[1] + local_3c * local_38[2]);

      }

    }

    fVar10 = (float10)FUN_004a18d0(obj,&local_68,&local_5c,pdVar1,&obj->acc_army_platoon_base_attack

                                   ,local_38,1);

    local_6c = (float)fVar10;

    if ((float10)0.0 < fVar10) break;

    local_70 = local_70 + -1;

    *puVar2 = *puVar2 | 4;

  } while (local_70 != 0);

  if ((bVar6) && (0.0 < *(float *)&obj->field_0x130)) {

    *(float *)(*(int *)&obj->field_0x104 + 0x20) =

         *(float *)(*(int *)&obj->field_0x104 + 0x20) - (float)puVar2[1] * 32.17405;

  }

  if (local_6c < 0.05) {

    *puVar2 = *puVar2 | 8;

  }

  DAT_0055ea3c = (float)obj->field_1E8 * *(float *)&obj->field_0xc4;

  fVar10 = (float10)FUN_004a18d0(obj,&local_68,&local_5c,pdVar1,&obj->acc_army_platoon_base_attack,

                                 &DAT_0055ea30,1);

  if ((float10)0.05 <= fVar10) {

    if ((~*puVar2 & 0x20) != 0) {

      obj->gap_144 = (dword)local_38[0];

      obj->acc_TargetCenter = local_28;

      obj->field_148 = (dword)local_38[1];

      obj->field_14C = (dword)local_38[2];

      obj->field_150 = (dword)local_38[3];

    }

  }

  else {

    *puVar2 = *puVar2 | 0x40;

    obj->gap_144 = DAT_0055ea30;

    obj->field_148 = DAT_0055ea34;

    obj->field_14C = DAT_0055ea38;

    obj->field_150 = (dword)DAT_0055ea3c;

    obj->acc_TargetCenter =

         (dword)-(((float)obj->gap_A0 * (float)obj->gap_144 +

                   (float)obj->field_148 * *(float *)&obj->field_0xa4 + (float)obj->field_150) /

                 (float)obj->field_14C);

  }

  fVar3 = *(float *)&obj->field_0xc4 * (float)obj->acc_popup_pre_logic;

  obj->gap_A0 = local_68;

  *(float *)&obj->field_0xa8 = local_60 + fVar3;

  *(undefined4 *)&obj->field_0xa4 = local_64;

  *(undefined4 *)&obj->field_0xac = local_5c;

  *(undefined4 *)&obj->field_0xb0 = local_58;

  obj->acc_army_platoon_coordinated = (dword)(fVar3 + local_54);

  return;

}

/* ===== PhysicsExGroundCollision @ 0x004A2220 ===== */
/* WARNING: Struct "OBJECT": ignoring multiple overlapping fields */



void PhysicsExGroundCollision(OBJECT *param_1)



{

  **(uint **)&param_1->field_0x104 = **(uint **)&param_1->field_0x104 & 0xffffff81;

  FUN_004a1e30(param_1);

  return;

}

/* ===== FUN_004a2240 @ 0x004A2240 ===== */
void FUN_004a2240(int param_1,int param_2)



{

  byte *pbVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  

  pbVar1 = *(byte **)(param_1 + 0x104);

  if ((*(byte *)(param_1 + 0xd8) & 0x10) == 0) {

    fVar2 = *(float *)(pbVar1 + 0x20) - *(float *)(pbVar1 + 4) * 32.17405;

    *(float *)(pbVar1 + 0x20) = fVar2;

    if (((param_2 != 0) && ((*pbVar1 & 0x68) != 0)) &&

       (fVar3 = *(float *)(pbVar1 + 0x18) * *(float *)(param_1 + 0x144) +

                *(float *)(pbVar1 + 0x1c) * *(float *)(param_1 + 0x148) +

                fVar2 * *(float *)(param_1 + 0x14c), fVar3 < 0.0)) {

      fVar6 = *(float *)(pbVar1 + 0x18) - fVar3 * *(float *)(param_1 + 0x144);

      *(float *)(pbVar1 + 0x18) = fVar6;

      fVar5 = *(float *)(pbVar1 + 0x1c) - fVar3 * *(float *)(param_1 + 0x148);

      *(float *)(pbVar1 + 0x1c) = fVar5;

      fVar2 = fVar2 - fVar3 * *(float *)(param_1 + 0x14c);

      *(float *)(pbVar1 + 0x20) = fVar2;

      fVar4 = SQRT(fVar6 * fVar6 + fVar5 * fVar5 + fVar2 * fVar2);

      fVar3 = 1.0;

      if (*(float *)(pbVar1 + 0x30) < fVar4) {

        fVar3 = *(float *)(pbVar1 + 0x30) / fVar4;

      }

      *(float *)(pbVar1 + 0x18) = *(float *)(pbVar1 + 0x18) - fVar6 * fVar3;

      *(float *)(pbVar1 + 0x1c) = *(float *)(pbVar1 + 0x1c) - fVar5 * fVar3;

      *(float *)(pbVar1 + 0x20) = *(float *)(pbVar1 + 0x20) - fVar3 * fVar2;

    }

    *(float *)(pbVar1 + 0x18) =

         *(float *)(pbVar1 + 0x18) - *(float *)(param_1 + 0x128) * *(float *)(pbVar1 + 0x34);

    *(float *)(pbVar1 + 0x1c) =

         *(float *)(pbVar1 + 0x1c) - *(float *)(param_1 + 300) * *(float *)(pbVar1 + 0x34);

    *(float *)(pbVar1 + 0x20) =

         *(float *)(pbVar1 + 0x20) - *(float *)(param_1 + 0x130) * *(float *)(pbVar1 + 0x38);

    if ((*(float *)(pbVar1 + 0x34) != 0.0) &&

       ((*(float *)(pbVar1 + 8) / *(float *)(pbVar1 + 0x34) < *(float *)(pbVar1 + 0x2c) ||

        (*(float *)(pbVar1 + 0x2c) == 0.0)))) {

      *(float *)(pbVar1 + 0x2c) = *(float *)(pbVar1 + 8) / *(float *)(pbVar1 + 0x34);

    }

    if ((*(float *)(pbVar1 + 0x38) != 0.0) &&

       ((*(float *)(pbVar1 + 8) / *(float *)(pbVar1 + 0x38) < *(float *)(pbVar1 + 0x2c) ||

        (*(float *)(pbVar1 + 0x2c) == 0.0)))) {

      *(float *)(pbVar1 + 0x2c) = *(float *)(pbVar1 + 8) / *(float *)(pbVar1 + 0x38);

      return;

    }

  }

  return;

}

/* ===== FUN_004a24e0 @ 0x004A24E0 ===== */
void FUN_004a24e0(float param_1,float *param_2,float param_3)



{

  int iVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float10 fVar7;

  

  iVar1 = *(int *)((int)param_1 + 0x104);

  fVar2 = SQRT(param_2[2] * param_2[2] + param_2[1] * param_2[1] + *param_2 * *param_2) * 0.75;

  fVar3 = *param_2 - *(float *)((int)param_1 + 0x128);

  fVar4 = param_2[1] - *(float *)((int)param_1 + 300);

  fVar5 = param_2[2] - *(float *)((int)param_1 + 0x130);

  param_1 = param_3;

  fVar6 = SQRT(fVar3 * fVar3 + fVar4 * fVar4 + fVar5 * fVar5);

  if ((fVar2 != 0.0) && (fVar2 < fVar6)) {

    param_1 = (fVar2 / fVar6) * param_3;

  }

  if (param_1 != 0.0) {

    *(float *)(iVar1 + 0x18) = param_1 * fVar3 + *(float *)(iVar1 + 0x18);

    *(float *)(iVar1 + 0x1c) = param_1 * fVar4 + *(float *)(iVar1 + 0x1c);

    fVar7 = (float10)FUN_00543e70();

    *(float *)(iVar1 + 0x20) =

         (float)(ABS(fVar7) * (float10)param_1 * (float10)fVar5 + (float10)*(float *)(iVar1 + 0x20))

    ;

    param_1 = *(float *)(iVar1 + 8) / param_1;

    if ((param_1 < *(float *)(iVar1 + 0x2c)) || (*(float *)(iVar1 + 0x2c) == 0.0)) {

      *(float *)(iVar1 + 0x2c) = param_1;

      return;

    }

  }

  return;

}

/* ===== FUN_004a2650 @ 0x004A2650 ===== */
void FUN_004a2650(float *param_1,float *param_2,float *param_3,float *param_4,float param_5,

                 float param_6,float param_7)



{

  float fVar1;

  float fVar2;

  

  *param_1 = *param_3 - *param_4;

  param_1[1] = param_3[1] - param_4[1];

  fVar1 = param_3[2] - param_4[2];

  param_1[2] = fVar1;

  fVar1 = SQRT(fVar1 * fVar1 + param_1[1] * param_1[1] + *param_1 * *param_1);

  if (0.0 < fVar1) {

    fVar2 = param_7 * fVar1;

    if (param_7 * fVar1 < param_5) {

      fVar2 = param_5;

    }

    if (param_6 < fVar2) {

      fVar2 = param_6;

    }

    fVar1 = fVar2 / fVar1;

    *param_1 = fVar1 * *param_1;

    param_1[1] = fVar1 * param_1[1];

    param_1[2] = fVar1 * param_1[2];

    if (param_2 != (float *)0x0) {

      *param_2 = fVar2;

      return;

    }

  }

  return;

}

/* ===== FUN_004a26f0 @ 0x004A26F0 ===== */
void FUN_004a26f0(int param_1,float param_2,float param_3,undefined4 param_4,undefined4 param_5,

                 int param_6)



{

  float fVar1;

  int iVar2;

  float *pfVar3;

  float *pfVar4;

  float local_a4;

  float fStack_a0;

  float fStack_9c;

  undefined1 local_98 [16];

  float local_88 [5];

  float fStack_74;

  float fStack_70;

  float fStack_64;

  float fStack_60;

  undefined1 local_44 [68];

  

  if (((*(int *)(param_1 + 0x224) != 0) || ((**(byte **)(param_1 + 0x104) & 0x68) != 0)) ||

     (param_6 != 0)) {

    if (((**(byte **)(param_1 + 0x104) & 0x28) == 0) || (param_6 != 0)) {

      pfVar3 = (float *)(param_1 + 0x294);

      pfVar4 = local_88;

      for (iVar2 = 0x11; iVar2 != 0; iVar2 = iVar2 + -1) {

        *pfVar4 = *pfVar3;

        pfVar3 = pfVar3 + 1;

        pfVar4 = pfVar4 + 1;

      }

    }

    else {

      FUN_0053fad0(local_98,&DAT_0055ea50,param_1 + 0x144);

      FUN_0053deb0(local_44,local_98);

      (*(code *)PTR_FUN_00580c18)(local_88,local_44,param_1 + 0x294);

    }

    fVar1 = 1.0 / *(float *)(param_1 + 0xc4);

    param_2 = (float)(int)*(char *)(param_1 + 0x20a) * 0.03125 * fVar1 * param_2;

    param_3 = (float)(int)*(char *)(param_1 + 0x20b) * 0.03125 * fVar1 * param_3;

    local_a4 = local_88[1] * param_3 + -(local_88[2] * param_2);

    fStack_a0 = fStack_74 * param_3 + -(fStack_70 * param_2);

    fStack_9c = fStack_64 * param_3 + -(fStack_60 * param_2);

    FUN_004a24e0(param_1,&local_a4,param_4,param_5);

  }

  return;

}

/* ===== FUN_004a2850 @ 0x004A2850 ===== */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

/* WARNING: Struct "OBJECT": ignoring multiple overlapping fields */

/* PS2 candidate: PhysicsExApplyMoveControls (conf 0.657) */



void FUN_004a2850(OBJECT *obj)



{

  dword *pdVar1;

  uint uVar2;

  float fVar3;

  OBJECT *pOVar4;

  OBJECT *pOVar5;

  float local_8;

  

  pOVar4 = obj;

  local_8 = (float)obj->field_194;

  pdVar1 = &obj->field_1A0;

  fVar3 = -((*(float *)&obj->field_0xa8 -

            (float)obj->acc_popup_pre_logic * *(float *)&obj->field_0xc4) /

           ((float)obj->field_1E8 * *(float *)&obj->field_0xc4));

  pOVar5 = (OBJECT *)obj->field_190;

  if (0.0 < fVar3) {

    if (1.0 < fVar3) {

      fVar3 = 1.0;

    }

    fVar3 = 1.0 - fVar3 * (float)obj->field_19C;

    local_8 = fVar3 * local_8;

    pOVar5 = (OBJECT *)((float)obj->field_190 * fVar3);

  }

  obj = pOVar5;

  uVar2 = *(uint *)&pOVar4->field_0xd8;

  if ((uVar2 & 0x8000000) != 0) {

    obj = (OBJECT *)((float)obj * 0.5);

    local_8 = local_8 * 0.5;

  }

  FUN_004a26f0(pOVar4,local_8,local_8,obj,*pdVar1,uVar2 & 0x10);

  return;

}

/* ===== FUN_004a2930 @ 0x004A2930 ===== */
void FUN_004a2930(int param_1,int param_2,int param_3,float param_4,float param_5)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  float10 fVar11;

  float local_30;

  float local_2c;

  

  *(float *)(*(int *)(param_1 + 0x104) + 0x24) =

       SQRT(*(float *)(param_1 + 0x130) * *(float *)(param_1 + 0x130) +

            *(float *)(param_1 + 300) * *(float *)(param_1 + 300) +

            *(float *)(param_1 + 0x128) * *(float *)(param_1 + 0x128));

  *(undefined4 *)(param_1 + 0x108) = 0;

  *(undefined4 *)(param_1 + 0x110) = 0;

  *(undefined4 *)(param_1 + 0x10c) = 0;

  if (*(float *)(param_1 + 0xc4) != 0.0) {

    fVar10 = 1.0 / *(float *)(param_1 + 0xc4);

    fVar1 = *(float *)(param_1 + 0x29c);

    fVar2 = *(float *)(param_1 + 0x2ac);

    fVar3 = *(float *)(param_1 + 700);

    fVar4 = *(float *)(param_1 + 0x298);

    fVar5 = *(float *)(param_1 + 0x2a8);

    fVar6 = *(float *)(param_1 + 0x2b8);

    fVar7 = *(float *)(param_1 + 0x2a0);

    fVar8 = *(float *)(param_1 + 0x2b0);

    fVar9 = *(float *)(param_1 + 0x2c0);

    fVar11 = (float10)FUN_00518b70(param_1,0);

    if (fVar11 == (float10)0.0) {

      fVar11 = (float10)0.0;

      local_2c = 0.0;

      local_30 = 0.0;

    }

    else {

      fVar11 = (float10)FUN_00518b70(param_1,0);

      fVar11 = (float10)1.0 / fVar11;

      local_30 = (float)(((float10)*(float *)(param_1 + 0xa0) - (float10)*(float *)(param_1 + 0xac))

                        * fVar11);

      local_2c = (float)(((float10)*(float *)(param_1 + 0xa4) - (float10)*(float *)(param_1 + 0xb0))

                        * fVar11);

      fVar11 = ((float10)*(float *)(param_1 + 0xa8) - (float10)*(float *)(param_1 + 0xb4)) * fVar11;

    }

    fVar4 = (float)((float10)local_30 * (float10)(fVar10 * fVar4) +

                   (float10)local_2c * (float10)(fVar10 * fVar5) +

                   (float10)(fVar10 * fVar6) * fVar11);

    *(float *)(param_1 + 0x110) = fVar4;

    if (param_3 != 0) {

      if (param_3 < 0) {

        if (-param_5 < fVar4) {

          *(float *)(param_1 + 0x110) = -param_5;

        }

      }

      else if (fVar4 < param_5) {

        *(float *)(param_1 + 0x110) = param_5;

      }

    }

    fVar1 = (float)((float10)local_30 * (float10)-(fVar10 * fVar1) +

                   (float10)local_2c * (float10)-(fVar10 * fVar2) +

                   (float10)-(fVar10 * fVar3) * fVar11);

    *(float *)(param_1 + 0x10c) = fVar1;

    if (param_2 != 0) {

      if (param_2 < 0) {

        if (-param_4 < fVar1) {

          *(float *)(param_1 + 0x10c) = -param_4;

        }

      }

      else if (fVar1 < param_4) {

        *(float *)(param_1 + 0x10c) = param_4;

      }

    }

    *(float *)(param_1 + 0x108) =

         (float)((float10)local_30 * (float10)(fVar10 * fVar7) +

                (float10)local_2c * (float10)(fVar10 * fVar8) + fVar11 * (float10)(fVar10 * fVar9));

  }

  return;

}

/* ===== FUN_004a2b90 @ 0x004A2B90 ===== */
/* PS2 candidate: PhysicsExCalcControledModelSpeeds (conf 0.533) */



void FUN_004a2b90(int param_1,undefined4 param_2,undefined4 param_3)



{

  FUN_004a2930(param_1,(int)*(char *)(param_1 + 0x20a),(int)*(char *)(param_1 + 0x20b),param_3,

               param_2);

  if (*(char *)(param_1 + 0x20a) == '\0') {

    *(undefined4 *)(param_1 + 0x10c) = 0;

  }

  if (*(char *)(param_1 + 0x20b) == '\0') {

    *(undefined4 *)(param_1 + 0x110) = 0;

  }

  return;

}

/* ===== FUN_004a2be0 @ 0x004A2BE0 ===== */
float10 FUN_004a2be0(int param_1)



{

  int iVar1;

  float *pfVar2;

  float10 fVar3;

  float10 fVar4;

  float10 fVar5;

  

  iVar1 = *(int *)(*(int *)(param_1 + 8) + 0xc);

  if (iVar1 == 0) {

    fVar3 = (float10)0.5;

    pfVar2 = (float *)(*(int *)(*(int *)(param_1 + 8) + 0x400) + 0x44);

  }

  else {

    fVar3 = (float10)0.85;

    pfVar2 = (float *)(iVar1 + 0xc);

  }

  fVar4 = -(float10)*pfVar2;

  if (fVar4 < (float10)pfVar2[3]) {

    fVar4 = (float10)pfVar2[3];

  }

  fVar5 = -(float10)pfVar2[1];

  if (fVar5 < (float10)pfVar2[4]) {

    fVar5 = (float10)pfVar2[4];

  }

  return SQRT(fVar4 * fVar4 + fVar5 * fVar5) * (float10)*(float *)(param_1 + 0xc4) * fVar3;

}

/* ===== FUN_004a2c50 @ 0x004A2C50 ===== */
/* PS2 candidate: SphereFitToObject (conf 0.368) */



void FUN_004a2c50(undefined4 param_1,int param_2,float param_3)



{

  float local_a4;

  undefined4 local_a0;

  undefined4 local_9c;

  float local_98;

  float local_94;

  float local_90;

  float local_8c;

  undefined1 local_88 [68];

  undefined1 local_44 [68];

  

  if (param_2 != 0) {

    local_8c = *(float *)(param_2 + 0x1ec) * *(float *)(param_2 + 0xc4) * 0.5;

    local_a4 = local_8c;

    if ((*(uint **)(param_2 + 0x104) != (uint *)0x0) &&

       ((**(uint **)(param_2 + 0x104) & 0x200) != 0)) {

      local_a4 = 0.0;

    }

    local_94 = *(float *)(param_2 + 0x154) * param_3;

    local_90 = *(float *)(param_2 + 0x154) * param_3;

    local_8c = local_8c * param_3;

    FUN_0053dca0(local_88,&local_94);

    local_a0 = *(undefined4 *)(param_2 + 0xa0);

    local_98 = local_a4 + *(float *)(param_2 + 0xa8);

    local_9c = *(undefined4 *)(param_2 + 0xa4);

    FUN_0053dc10(local_44,&local_a0);

    (*(code *)PTR_FUN_00580c18)(param_1,local_44,local_88);

  }

  return;

}

/* ===== ObjectTransformIntegrity @ 0x004A2D30 ===== */
void ObjectTransformIntegrity(int param_1)



{

  *(undefined4 *)(param_1 + 0xa0) = *(undefined4 *)(param_1 + 0x2a4);

  *(undefined4 *)(param_1 + 0xa4) = *(undefined4 *)(param_1 + 0x2b4);

  *(undefined4 *)(param_1 + 0xa8) = *(undefined4 *)(param_1 + 0x2c4);

  return;

}

/* ===== FUN_004a2d60 @ 0x004A2D60 ===== */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

/* WARNING: Struct "OBJECT": ignoring multiple overlapping fields */

/* PS2 candidate: smartie_move (conf 0.722) */



undefined4 FUN_004a2d60(OBJECT *obj)



{

  float *pfVar1;

  float *pfVar2;

  float *pfVar3;

  float fVar4;

  int iVar5;

  int iVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  int iVar10;

  int iVar11;

  uint uVar12;

  uint uVar13;

  uint uVar14;

  dword dVar15;

  float10 fVar16;

  dword in_stack_00000008;

  float fStack_308;

  float fStack_304;

  float fStack_300;

  float fStack_2fc;

  float fStack_2f8;

  float fStack_2f4;

  float fStack_2f0;

  float fStack_2ec;

  undefined4 *puStack_2e8;

  float fStack_2e4;

  float fStack_2e0;

  float fStack_2dc;

  float fStack_2d8;

  float fStack_2d4;

  float fStack_2d0;

  float afStack_2c8 [4];

  float fStack_2b8;

  float fStack_2b4;

  float fStack_2b0;

  float fStack_2ac;

  float fStack_2a8;

  int iStack_2a4;

  dword dStack_2a0;

  float afStack_29c [4];

  float fStack_28c;

  float fStack_288;

  float fStack_284;

  float fStack_280;

  float fStack_27c;

  float fStack_278;

  float fStack_274;

  float fStack_270;

  float fStack_258;

  float fStack_254;

  float fStack_250;

  int iStack_24c;

  int iStack_248;

  undefined4 uStack_244;

  float afStack_240 [4];

  int iStack_230;

  int iStack_22c;

  float afStack_228 [4];

  float fStack_218;

  float fStack_214;

  float fStack_210;

  float fStack_20c;

  float fStack_208;

  undefined1 auStack_1e4 [4];

  float fStack_1e0;

  float fStack_1dc;

  float fStack_1d8;

  float fStack_1d4;

  float fStack_1d0;

  float fStack_1cc;

  float fStack_1c8;

  float fStack_1c4;

  float fStack_1c0;

  float fStack_1bc;

  float fStack_1b8;

  float fStack_1b4;

  int iStack_1a0;

  dword dStack_19c;

  undefined1 auStack_198 [4];

  float fStack_194;

  float fStack_190;

  float fStack_18c;

  float fStack_188;

  float fStack_184;

  float fStack_180;

  float fStack_17c;

  float fStack_178;

  float fStack_174;

  float fStack_170;

  float fStack_16c;

  float fStack_168;

  float fStack_164;

  float fStack_160;

  float fStack_15c;

  float fStack_158;

  undefined1 auStack_154 [68];

  undefined1 auStack_110 [68];

  undefined1 auStack_cc [68];

  undefined1 local_88 [68];

  undefined1 auStack_44 [68];

  

  (*(code *)PTR_FUN_00580c1c)(local_88,in_stack_00000008 + 0x294);

  if (obj != (OBJECT *)0x0) {

    fStack_2a8 = (float)obj->gap_1EC * *(float *)&obj->field_0xc4 * 0.5;

    puStack_2e8 = (undefined4 *)fStack_2a8;

    if ((*(uint **)&obj->field_0x104 != (uint *)0x0) &&

       ((**(uint **)&obj->field_0x104 & 0x200) != 0)) {

      puStack_2e8 = (undefined4 *)0x0;

    }

    fStack_2b0 = (float)obj->gap_154;

    fStack_2ac = fStack_2b0;

    FUN_0053dca0(afStack_29c,&fStack_2b0);

    fStack_258 = (float)obj->gap_A0;

    fStack_250 = (float)puStack_2e8 + *(float *)&obj->field_0xa8;

    fStack_254 = *(float *)&obj->field_0xa4;

    FUN_0053dc10(afStack_228,&fStack_258);

    (*(code *)PTR_FUN_00580c18)(auStack_154,afStack_228,afStack_29c);

  }

  (*(code *)PTR_FUN_00580c1c)(auStack_cc,auStack_154);

  FUN_0053d970(auStack_110,auStack_cc);

  (*(code *)PTR_FUN_00580c18)(auStack_1e4,auStack_cc,in_stack_00000008 + 0x294);

  (*(code *)PTR_FUN_00580c18)(auStack_198,local_88,auStack_154);

  FUN_0053d970(auStack_44,auStack_198);

  fStack_2dc = 0.99;

  fStack_2e0 = 1.5;

  iVar10 = main_0042b1d0();

  main_animate_00404b60();

  iVar10 = *(int *)(*(int *)(in_stack_00000008 + 8) + 0x400 + iVar10 * 4);

  dStack_2a0 = 0;

  if (0 < *(int *)(iVar10 + 0x68)) {

    puStack_2e8 = (undefined4 *)(iVar10 + 0x84);

    iStack_230 = iVar10;

    do {

      dVar15 = dStack_2a0;

      iVar11 = FUN_00513b60(in_stack_00000008,iVar10,dStack_2a0);

      if (iVar11 == 0) {

        afStack_240[3] = (float)*puStack_2e8;

        uStack_244 = 0xffff;

        iStack_2a4 = 0;

        iVar11 = main_00430e10(afStack_240 + 3,&uStack_244,&iStack_22c,&iStack_24c,&iStack_248);

        while (iVar11 != 0) {

          iVar11 = *(int *)(iVar10 + 0x34);

          iVar10 = *(int *)(iVar10 + 0x14);

          iStack_2a4 = iStack_2a4 + 1;

          pfVar1 = (float *)(iVar10 + (uint)*(ushort *)(iVar11 + iStack_22c * 2) * 0xc);

          pfVar2 = (float *)(iVar10 + (uint)*(ushort *)(iVar11 + iStack_24c * 2) * 0xc);

          uVar14 = (uint)*(ushort *)(iVar11 + iStack_248 * 2);

          pfVar3 = (float *)(iVar10 + uVar14 * 0xc);

          fVar7 = *(float *)(iVar10 + 8 + uVar14 * 0xc) - pfVar1[2];

          fStack_2d8 = (pfVar2[1] - pfVar1[1]) * fVar7 -

                       (pfVar2[2] - pfVar1[2]) * (pfVar3[1] - pfVar1[1]);

          fStack_2ec = *pfVar2 - *pfVar1;

          fStack_2d4 = (*pfVar3 - *pfVar1) * (pfVar2[2] - pfVar1[2]) - fStack_2ec * fVar7;

          fVar7 = fStack_2ec * (pfVar3[1] - pfVar1[1]) -

                  (*pfVar3 - *pfVar1) * (pfVar2[1] - pfVar1[1]);

          fVar8 = -(fStack_2d8 * *pfVar1 + fStack_2d4 * pfVar1[1] + fVar7 * pfVar1[2]);

          fStack_2fc = fStack_194 * fStack_2d8 +

                       fStack_184 * fStack_2d4 + fStack_174 * fVar7 + fStack_164 * fVar8;

          fStack_2f8 = fStack_190 * fStack_2d8 +

                       fStack_180 * fStack_2d4 + fStack_170 * fVar7 + fStack_160 * fVar8;

          fStack_2f4 = fStack_18c * fStack_2d8 +

                       fStack_17c * fStack_2d4 + fStack_16c * fVar7 + fStack_15c * fVar8;

          fStack_2f0 = fStack_188 * fStack_2d8 +

                       fStack_178 * fStack_2d4 + fStack_168 * fVar7 + fStack_158 * fVar8;

          fStack_2e4 = fStack_2f4 * fStack_2f4 + fStack_2fc * fStack_2fc + fStack_2f8 * fStack_2f8;

          if ((fStack_2e4 != 0.0) && (0.0 <= fStack_2f0)) {

            fVar7 = fStack_2f0 / fStack_2e4;

            fStack_2ec = fStack_2f0 * fVar7;

            if (fStack_2ec < 1.5) {

              fVar9 = -(fStack_2fc * fVar7);

              fVar8 = -(fStack_2f8 * fVar7);

              fVar7 = -(fVar7 * fStack_2f4);

              afStack_228[0] =

                   fStack_1e0 * *pfVar1 + fStack_1dc * pfVar1[1] + fStack_1d8 * pfVar1[2] +

                   fStack_1d4;

              afStack_228[1] =

                   fStack_1d0 * *pfVar1 + fStack_1cc * pfVar1[1] + fStack_1c8 * pfVar1[2] +

                   fStack_1c4;

              afStack_228[2] =

                   fStack_1c0 * *pfVar1 + fStack_1bc * pfVar1[1] + fStack_1b8 * pfVar1[2] +

                   fStack_1b4;

              afStack_228[3] =

                   fStack_1d8 * pfVar2[2] + fStack_1e0 * *pfVar2 + fStack_1dc * pfVar2[1] +

                   fStack_1d4;

              fStack_218 = fStack_1c8 * pfVar2[2] + fStack_1d0 * *pfVar2 + fStack_1cc * pfVar2[1] +

                           fStack_1c4;

              fStack_214 = fStack_1b8 * pfVar2[2] + fStack_1c0 * *pfVar2 + fStack_1bc * pfVar2[1] +

                           fStack_1b4;

              fStack_210 = fStack_1dc * pfVar3[1] + fStack_1e0 * *pfVar3 + fStack_1d8 * pfVar3[2] +

                           fStack_1d4;

              fStack_20c = fStack_1cc * pfVar3[1] + fStack_1d0 * *pfVar3 + fStack_1c8 * pfVar3[2] +

                           fStack_1c4;

              fStack_208 = fStack_1bc * pfVar3[1] + fStack_1c0 * *pfVar3 + fStack_1b8 * pfVar3[2] +

                           fStack_1b4;

              afStack_29c[0] =

                   (fStack_208 - afStack_228[2]) * fStack_2f8 -

                   (fStack_20c - afStack_228[1]) * fStack_2f4;

              afStack_29c[1] =

                   fStack_2f4 * (fStack_210 - afStack_228[0]) -

                   (fStack_208 - afStack_228[2]) * fStack_2fc;

              afStack_29c[2] =

                   (fStack_20c - afStack_228[1]) * fStack_2fc -

                   (fStack_210 - afStack_228[0]) * fStack_2f8;

              afStack_29c[3] =

                   -(afStack_29c[0] * afStack_228[0] +

                    afStack_29c[1] * afStack_228[1] + afStack_29c[2] * afStack_228[2]);

              fStack_28c = (fStack_214 - fStack_208) * fStack_2f8 -

                           (fStack_218 - fStack_20c) * fStack_2f4;

              fStack_288 = fStack_2f4 * (afStack_228[3] - fStack_210) -

                           (fStack_214 - fStack_208) * fStack_2fc;

              fStack_284 = (fStack_218 - fStack_20c) * fStack_2fc -

                           (afStack_228[3] - fStack_210) * fStack_2f8;

              fStack_280 = -(fStack_28c * fStack_210 +

                            fStack_288 * fStack_20c + fStack_284 * fStack_208);

              fStack_27c = (afStack_228[2] - fStack_214) * fStack_2f8 -

                           (afStack_228[1] - fStack_218) * fStack_2f4;

              fStack_278 = fStack_2f4 * (afStack_228[0] - afStack_228[3]) -

                           (afStack_228[2] - fStack_214) * fStack_2fc;

              fStack_274 = (afStack_228[1] - fStack_218) * fStack_2fc -

                           (afStack_228[0] - afStack_228[3]) * fStack_2f8;

              fStack_270 = -(fStack_27c * afStack_228[3] +

                            fStack_278 * fStack_218 + fStack_274 * fStack_214);

              afStack_2c8[0] =

                   afStack_29c[0] * fVar9 + afStack_29c[1] * fVar8 + afStack_29c[2] * fVar7 +

                   afStack_29c[3];

              afStack_2c8[1] =

                   fStack_28c * fVar9 + fStack_288 * fVar8 + fStack_284 * fVar7 + fStack_280;

              afStack_2c8[2] =

                   fStack_27c * fVar9 + fStack_278 * fVar8 + fStack_274 * fVar7 + fStack_270;

              uVar14 = ((uint)(0.0 < afStack_2c8[2]) * 2 | (uint)(0.0 < afStack_2c8[1])) << 1 |

                       (uint)(0.0 < afStack_2c8[0]);

              fStack_308 = fVar9;

              fStack_304 = fVar8;

              fStack_300 = fVar7;

              if (uVar14 != 0) {

                iVar10 = *(int *)(uVar14 * 4 + 0x55ea5c);

                if (iVar10 < 0) {

                  fStack_254 = fVar8;

                  iVar11 = *(int *)(&DAT_0055eab4 + iVar10 * -4);

                  fStack_258 = fVar9;

                  fVar4 = afStack_29c[iVar11 * 4 + 1];

                  fStack_250 = fVar7;

                  fVar4 = afStack_2c8[iVar11] /

                          (afStack_29c[iVar11 * 4 + 2] * afStack_29c[iVar11 * 4 + 2] +

                          fVar4 * fVar4 + afStack_29c[iVar11 * 4] * afStack_29c[iVar11 * 4]);

                  fStack_308 = fVar9 - fVar4 * afStack_29c[iVar11 * 4];

                  iVar5 = *(int *)(&DAT_0055ea9c + iVar11 * 4);

                  fStack_304 = fVar8 - fVar4 * afStack_29c[iVar11 * 4 + 1];

                  iVar6 = *(int *)(&DAT_0055eaa8 + iVar11 * 4);

                  fStack_300 = fVar7 - fVar4 * afStack_29c[iVar11 * 4 + 2];

                  afStack_240[iVar5] =

                       fStack_308 * afStack_29c[iVar5 * 4] +

                       fStack_304 * afStack_29c[iVar5 * 4 + 1] +

                       fStack_300 * afStack_29c[iVar5 * 4 + 2] + afStack_29c[iVar5 * 4 + 3];

                  fVar4 = fStack_308 * afStack_29c[iVar6 * 4] +

                          fStack_304 * afStack_29c[iVar6 * 4 + 1] +

                          fStack_300 * afStack_29c[iVar6 * 4 + 2] + afStack_29c[iVar6 * 4 + 3];

                  afStack_240[iVar6] = fVar4;

                  uVar12 = (uint)(0.0 < fVar4) << ((byte)iVar6 & 0x1f) |

                           (uint)(0.0 < afStack_240[iVar5]) << ((byte)iVar5 & 0x1f);

                  if (uVar12 != 0) {

                    uVar13 = 1 << ((byte)*(undefined4 *)(&DAT_0055ead4 + iVar10 * -4) & 0x1f);

                    if ((uVar12 & uVar13) == 0) {

                      iVar10 = *(int *)(&DAT_0055eac4 + iVar10 * -4);

                      fVar4 = afStack_2c8[iVar10] /

                              (afStack_29c[iVar10 * 4 + 2] * afStack_29c[iVar10 * 4 + 2] +

                              afStack_29c[iVar10 * 4 + 1] * afStack_29c[iVar10 * 4 + 1] +

                              afStack_29c[iVar10 * 4] * afStack_29c[iVar10 * 4]);

                      fStack_308 = fVar9 - fVar4 * afStack_29c[iVar10 * 4];

                      iVar11 = *(int *)(&DAT_0055ea9c + iVar10 * 4);

                      fStack_304 = fVar8 - fVar4 * afStack_29c[iVar10 * 4 + 1];

                      iVar5 = *(int *)(&DAT_0055eaa8 + iVar10 * 4);

                      fStack_300 = fVar7 - fVar4 * afStack_29c[iVar10 * 4 + 2];

                      afStack_240[iVar11] =

                           fStack_308 * afStack_29c[iVar11 * 4] +

                           fStack_304 * afStack_29c[iVar11 * 4 + 1] +

                           fStack_300 * afStack_29c[iVar11 * 4 + 2] + afStack_29c[iVar11 * 4 + 3];

                      fVar7 = fStack_308 * afStack_29c[iVar5 * 4] +

                              fStack_304 * afStack_29c[iVar5 * 4 + 1] +

                              fStack_300 * afStack_29c[iVar5 * 4 + 2] + afStack_29c[iVar5 * 4 + 3];

                      afStack_240[iVar5] = fVar7;

                      uVar12 = (uint)(0.0 < fVar7) << ((byte)iVar5 & 0x1f) |

                               (uint)(0.0 < afStack_240[iVar11]) << ((byte)iVar11 & 0x1f);

                      if (uVar12 == 0) goto LAB_004a3a06;

                      if ((uVar12 & uVar13) == 0) {

                        iVar10 = *(int *)(&DAT_0055ea7c + uVar14 * 4);

                      }

                      else {

                        iVar10 = *(int *)(&DAT_0055ea7c + (1 << ((byte)iVar10 & 0x1f) | uVar12) * 4)

                        ;

                      }

                    }

                    else {

                      iVar10 = *(int *)(&DAT_0055ea7c + (1 << ((byte)iVar11 & 0x1f) | uVar12) * 4);

                    }

                    goto LAB_004a39db;

                  }

                }

                else {

                  fVar4 = afStack_2c8[iVar10] /

                          (afStack_29c[iVar10 * 4 + 2] * afStack_29c[iVar10 * 4 + 2] +

                          afStack_29c[iVar10 * 4 + 1] * afStack_29c[iVar10 * 4 + 1] +

                          afStack_29c[iVar10 * 4] * afStack_29c[iVar10 * 4]);

                  fStack_308 = fVar9 - fVar4 * afStack_29c[iVar10 * 4];

                  iVar11 = *(int *)(&DAT_0055ea9c + iVar10 * 4);

                  fStack_304 = fVar8 - fVar4 * afStack_29c[iVar10 * 4 + 1];

                  iVar5 = *(int *)(&DAT_0055eaa8 + iVar10 * 4);

                  fStack_300 = fVar7 - fVar4 * afStack_29c[iVar10 * 4 + 2];

                  afStack_240[iVar11] =

                       fStack_308 * afStack_29c[iVar11 * 4] +

                       fStack_304 * afStack_29c[iVar11 * 4 + 1] +

                       fStack_300 * afStack_29c[iVar11 * 4 + 2] + afStack_29c[iVar11 * 4 + 3];

                  fVar7 = fStack_308 * afStack_29c[iVar5 * 4] +

                          fStack_304 * afStack_29c[iVar5 * 4 + 1] +

                          fStack_300 * afStack_29c[iVar5 * 4 + 2] + afStack_29c[iVar5 * 4 + 3];

                  afStack_240[iVar5] = fVar7;

                  iVar10 = *(int *)(&DAT_0055ea7c +

                                   ((uint)(0.0 < fVar7) << ((byte)iVar5 & 0x1f) |

                                    (uint)(0.0 < afStack_240[iVar11]) << ((byte)iVar11 & 0x1f) |

                                   1 << ((byte)iVar10 & 0x1f)) * 4);

LAB_004a39db:

                  if (-1 < iVar10) {

                    fStack_308 = afStack_228[iVar10 * 3];

                    fStack_304 = afStack_228[iVar10 * 3 + 1];

                    fStack_300 = afStack_228[iVar10 * 3 + 2];

                  }

                }

LAB_004a3a06:

                fStack_2ec = fStack_308 * fStack_308 +

                             fStack_304 * fStack_304 + fStack_300 * fStack_300;

              }

              if (fStack_2ec < fStack_2dc) {

                fStack_2dc = fStack_2ec;

                afStack_2c8[3] = fStack_308;

                fStack_2b8 = fStack_304;

                fStack_2b4 = fStack_300;

              }

              if (((fStack_2ec < fStack_2e0) && (fStack_300 < 0.0)) &&

                 ((fStack_308 * fStack_308 + fStack_304 * fStack_304) / (fStack_300 * fStack_300) <

                  4.0)) {

                fStack_2e0 = fStack_2ec;

                fStack_2b0 = fStack_308;

                fStack_2ac = fStack_304;

                fStack_2a8 = fStack_300;

                iStack_1a0 = iStack_2a4;

                dStack_19c = dStack_2a0;

              }

            }

          }

          iVar11 = main_00430e10(afStack_240 + 3,&uStack_244,&iStack_22c,&iStack_24c,&iStack_248);

          iVar10 = iStack_230;

          dVar15 = dStack_2a0;

        }

      }

      dStack_2a0 = dVar15 + 1;

      puStack_2e8 = puStack_2e8 + 0x14;

    } while ((int)dStack_2a0 < *(int *)(iVar10 + 0x68));

    if (fStack_2e0 < 1.5) {

      fStack_2fc = -fStack_2b0;

      fStack_2f8 = -fStack_2ac;

      fStack_2f0 = fStack_2e0;

      fStack_2f4 = -fStack_2a8;

      (*(code *)PTR_FUN_00580c28)(&fStack_2d8,&fStack_2fc,1,auStack_110);

      fVar16 = (float10)FUN_0053e8d0(&fStack_2d8);

      FUN_0053e9c0(&obj->gap_144,&fStack_2d8,(float)((float10)1.0 / fVar16));

      obj->acc_TargetCenter =

           (dword)-(((float)obj->gap_A0 * (float)obj->gap_144 +

                     (float)obj->field_148 * *(float *)&obj->field_0xa4 + (float)obj->field_150) /

                   (float)obj->field_14C);

      if (fStack_2e0 < 1.15) {

        **(uint **)&obj->field_0x104 = **(uint **)&obj->field_0x104 | 0x20;

        obj->acc_verm_init_parameters = in_stack_00000008;

        obj->gap_228 = dStack_19c;

        *(int *)&obj->field_0x22c = iStack_1a0;

      }

    }

    if (fStack_2dc < 0.99) {

      fStack_2fc = -afStack_2c8[3];

      fStack_2f8 = -fStack_2b8;

      fStack_2f0 = fStack_2dc;

      fStack_2f4 = -fStack_2b4;

      (*(code *)PTR_FUN_00580c28)(&fStack_2d8,&fStack_2fc,1,auStack_110);

      fVar16 = (float10)FUN_0053e8d0(&fStack_2d8);

      FUN_0053e9c0(&fStack_2d8,&fStack_2d8,(float)((float10)1.0 / fVar16));

      (*(code *)PTR_FUN_00580c20)(&obj->field_0x254,afStack_2c8 + 3,1,auStack_154);

      fVar7 = 1.0 / SQRT(fStack_2dc);

      afStack_2c8[3] = afStack_2c8[3] * fVar7;

      fStack_2b8 = fStack_2b8 * fVar7;

      fStack_2b4 = fVar7 * fStack_2b4;

      (*(code *)PTR_FUN_00580c20)(&obj->field_0x260,afStack_2c8 + 3,1,auStack_154);

      uVar14 = FUN_0049a060(obj,in_stack_00000008);

      if ((uVar14 & 1) == 0) {

        if (fStack_2d8 * (float)obj->gap_128 +

            fStack_2d4 * *(float *)&obj->field_0x12c + fStack_2d0 * *(float *)&obj->field_0x130 <

            0.0) {

          fVar7 = *(float *)&obj->field_0x260 - (float)obj->gap_A0;

          fVar8 = (float)obj->acc_rpman_get_thrust - *(float *)&obj->field_0xa4;

          fVar9 = (float)obj->gap_268 - *(float *)&obj->field_0xa8;

          afStack_2c8[0] = fVar7 + (float)obj->gap_A0;

          afStack_2c8[1] = fVar8 + *(float *)&obj->field_0xa4;

          afStack_2c8[2] = fVar9 + *(float *)&obj->field_0xa8;

          fStack_2b0 = fVar7 + *(float *)&obj->field_0xac;

          fStack_2ac = fVar8 + *(float *)&obj->field_0xb0;

          fStack_2a8 = fVar9 + (float)obj->acc_army_platoon_coordinated;

          FUN_004a18d0(obj,afStack_2c8,&fStack_2b0,&obj->gap_128,&obj->acc_army_platoon_base_attack,

                       &fStack_2d8,0);

          obj->gap_A0 = (dword)(afStack_2c8[0] - fVar7);

          *(float *)&obj->field_0xa4 = afStack_2c8[1] - fVar8;

          *(float *)&obj->field_0xa8 = afStack_2c8[2] - fVar9;

          **(uint **)&obj->field_0x104 = **(uint **)&obj->field_0x104 | 0x10;

          *(dword *)&obj->field_0x220 = in_stack_00000008;

          if ((*(byte *)(in_stack_00000008 + 0xdc) & 0x10) != 0) {

            *(OBJECT **)(in_stack_00000008 + 0x220) = obj;

          }

          return 1;

        }

      }

      else {

        **(uint **)&obj->field_0x104 = **(uint **)&obj->field_0x104 & 0xffffffdf;

        obj->acc_verm_init_parameters = 0;

      }

    }

  }

  return 0;

}

/* ===== FUN_004a3e90 @ 0x004A3E90 ===== */
undefined4 FUN_004a3e90(int param_1)



{

  int iVar1;

  

  if ((*(int *)(param_1 + 0x224) != 0) && (*(int *)(param_1 + 0x104) != 0)) {

    iVar1 = main_0042b1d0(*(int *)(param_1 + 0x224));

    return *(undefined4 *)

            (*(int *)(*(int *)(*(int *)(param_1 + 0x224) + 8) + 0x400 + iVar1 * 4) + 0x90 +

            *(int *)(param_1 + 0x228) * 0x50);

  }

  return 0;

}

/* ===== FUN_004a3ee0 @ 0x004A3EE0 ===== */
/* WARNING: Struct "OBJECT": ignoring multiple overlapping fields */



int FUN_004a3ee0(OBJECT *param_1)



{

  dword *pdVar1;

  undefined1 *puVar2;

  float fVar3;

  float fVar4;

  OBJECT *pOVar5;

  float fVar6;

  float fVar7;

  OBJECT *obj;

  int iVar8;

  float *pfVar9;

  float10 fVar10;

  int *local_58;

  float local_54;

  float local_50;

  float local_40;

  float local_3c;

  dword local_38;

  float local_34;

  float local_30;

  float local_2c;

  dword local_28;

  undefined4 local_24;

  undefined4 local_20;

  float local_1c;

  dword local_18;

  

  obj = param_1;

  local_54 = 0.0;

  if ((~**(uint **)&param_1->field_0x104 & 0x100) != 0) {

    iVar8 = *(int *)(param_1->field_8 + 0xc);

    if (iVar8 == 0) {

      fVar6 = 0.5;

      pfVar9 = (float *)(*(int *)(param_1->field_8 + 0x400) + 0x44);

    }

    else {

      fVar6 = 0.85;

      pfVar9 = (float *)(iVar8 + 0xc);

    }

    fVar3 = -*pfVar9;

    if (fVar3 < pfVar9[3]) {

      fVar3 = pfVar9[3];

    }

    fVar4 = -pfVar9[1];

    if (fVar4 < pfVar9[4]) {

      fVar4 = pfVar9[4];

    }

    param_1->gap_154 =

         (dword)(SQRT(fVar3 * fVar3 + fVar4 * fVar4) * *(float *)&param_1->field_0xc4 * fVar6);

  }

  local_58 = DAT_00632d7c;

  if (DAT_00632d7c == (int *)0x0) {

    return 0;

  }

  do {

    pOVar5 = (OBJECT *)local_58[3];

    if (((((pOVar5->acc_grenade_do_stopped & 0x800) == 0 &&

           (*(uint *)&pOVar5->field_0xd8 & 0x4000c000) == 0) && (obj != pOVar5)) &&

        (pOVar5->field_8 != 0)) && (*(OBJECT **)&pOVar5->field_0x210 != obj)) {

      pdVar1 = &obj->gap_A0;

      local_1c = (float)obj->gap_1EC * *(float *)&obj->field_0xc4;

      puVar2 = &obj->field_0xac;

      local_28 = *pdVar1;

      local_24 = *(undefined4 *)&obj->field_0xa4;

      local_20 = *(undefined4 *)&obj->field_0xa8;

      local_18 = obj->gap_154;

      if ((float)*pdVar1 <= *(float *)puVar2) {

        local_40 = (float)*pdVar1 - (float)obj->gap_154;

        local_34 = (float)obj->gap_154 + *(float *)puVar2;

      }

      else {

        local_40 = *(float *)puVar2 - (float)obj->gap_154;

        local_34 = (float)obj->gap_154 + (float)*pdVar1;

      }

      if (*(float *)&obj->field_0xa4 <= *(float *)&obj->field_0xb0) {

        local_3c = *(float *)&obj->field_0xa4 - (float)obj->gap_154;

        local_30 = (float)obj->gap_154 + *(float *)&obj->field_0xb0;

      }

      else {

        local_3c = *(float *)&obj->field_0xb0 - (float)obj->gap_154;

        local_30 = (float)obj->gap_154 + *(float *)&obj->field_0xa4;

      }

      if (*(float *)&obj->field_0xa8 <= (float)obj->acc_army_platoon_coordinated) {

        local_38 = *(dword *)&obj->field_0xa8;

        local_2c = (float)obj->acc_army_platoon_coordinated;

      }

      else {

        local_38 = obj->acc_army_platoon_coordinated;

        local_2c = *(float *)&obj->field_0xa8;

      }

      local_2c = local_1c + local_2c;

      iVar8 = FUN_0049a3c0(&local_40,&pOVar5->acc_teammecc_get_new_wander_);

      if (iVar8 != 0) {

        local_54 = (float)obj->gap_1EC * *(float *)&obj->field_0xc4 * 0.5;

        if ((float)obj->gap_154 < local_54) {

          local_54 = (float)obj->gap_154;

        }

        fVar10 = (float10)FUN_0050a580(puVar2,pdVar1);

        if (fVar10 == (float10)0.0) {

          local_50 = 1.0;

        }

        else {

          local_50 = (float)((float10)local_54 / fVar10);

        }

        fVar6 = (float)*pdVar1;

        fVar3 = *(float *)&obj->field_0xa4;

        fVar4 = *(float *)&obj->field_0xa8;

        param_1 = (OBJECT *)0x0;

        do {

          param_1 = (OBJECT *)((float)param_1 + local_50);

          if (1.0 < (float)param_1) {

            param_1 = (OBJECT *)0x3f800000;

          }

          fVar7 = 1.0 - (float)param_1;

          *pdVar1 = (dword)(fVar7 * *(float *)puVar2 + fVar6 * (float)param_1);

          *(float *)&obj->field_0xa4 = fVar3 * (float)param_1 + fVar7 * *(float *)&obj->field_0xb0;

          *(float *)&obj->field_0xa8 =

               fVar4 * (float)param_1 + fVar7 * (float)obj->acc_army_platoon_coordinated;

          local_54 = (float)FUN_004a2d60(obj);

        } while ((local_54 == 0.0) && ((float)param_1 < 1.0));

      }

    }

    local_58 = (int *)*local_58;

  } while (local_58 != (int *)0x0);

  return (int)local_54;

}

/* ===== FUN_004a4210 @ 0x004A4210 ===== */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

/* WARNING: Struct "OBJECT": ignoring multiple overlapping fields */



void FUN_004a4210(OBJECT *obj)



{

  uint uVar1;

  int iVar2;

  int iVar3;

  

  if (((((*(uint *)&obj->field_0xd8 & 0x10000000) != 0) ||

       ((float)obj->gap_A0 != *(float *)&obj->field_0xac)) ||

      (*(float *)&obj->field_0xa4 != *(float *)&obj->field_0xb0)) ||

     (*(float *)&obj->field_0xa8 != (float)obj->acc_army_platoon_coordinated)) {

    *(uint *)&obj->field_0xd8 = *(uint *)&obj->field_0xd8 & 0xefffffff;

    **(undefined1 **)&obj->field_0x104 = 0;

    obj->acc_verm_init_parameters = 0;

    *(undefined4 *)&obj->field_0x220 = 0;

    if (obj->field_8 != 0) {

      if ((obj->acc_grenade_do_stopped & 0x400) == 0) {

        iVar2 = 1;

        iVar3 = 0;

        do {

          if (iVar2 == 0) goto LAB_004a431f;

          iVar2 = FUN_004a3ee0(obj);

        } while (((((float)obj->gap_A0 != *(float *)&obj->field_0xac) ||

                  (*(float *)&obj->field_0xa4 != *(float *)&obj->field_0xb0)) ||

                 (*(float *)&obj->field_0xa8 != (float)obj->acc_army_platoon_coordinated)) &&

                (iVar3 = iVar3 + 1, iVar3 < 4));

        if (iVar2 != 0) {

          obj->gap_A0 = *(dword *)&obj->field_0xac;

          *(undefined4 *)&obj->field_0xa4 = *(undefined4 *)&obj->field_0xb0;

          *(dword *)&obj->field_0xa8 = obj->acc_army_platoon_coordinated;

        }

      }

LAB_004a431f:

      if ((obj->acc_grenade_do_stopped & 0x200) == 0) {

        FUN_004a1e30(obj);

      }

    }

    uVar1 = **(uint **)&obj->field_0x104;

    if ((uVar1 & 0x68) != 0) {

      **(uint **)&obj->field_0x104 = uVar1 | 0x80;

    }

    if ((**(byte **)&obj->field_0x104 & 0x96) != 0) {

      FUN_0049a060(obj,0);

    }

  }

  return;

}

/* ===== FUN_004a4360 @ 0x004A4360 ===== */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

/* WARNING: Struct "OBJECT": ignoring multiple overlapping fields */

/* PS2 candidate: PhysicsExApplyLocation (conf 0.382) */



void FUN_004a4360(OBJECT *obj)



{

  uint uVar1;

  float fVar2;

  float fVar3;

  

  *(uint *)&obj->field_0xd8 = *(uint *)&obj->field_0xd8 & 0xf7e7ffff;

  if (((float)obj->gap_A0 - *(float *)&obj->field_0xac != 0.0) ||

     (*(float *)&obj->field_0xa4 - *(float *)&obj->field_0xb0 != 0.0)) {

    collgrid_clear_grid(obj);

  }

  if (*(int *)&obj->field_0x210 == 0) {

    FUN_004a4210(obj);

    fVar2 = *(float *)&obj->field_0xa8 -

            (float)obj->acc_popup_pre_logic * *(float *)&obj->field_0xc4;

    if (fVar2 < 0.0 != (fVar2 == 0.0)) {

      uVar1 = *(uint *)&obj->field_0xd8;

      *(uint *)&obj->field_0xd8 = uVar1 | 0x100000;

      fVar3 = -((float)obj->field_1E8 * *(float *)&obj->field_0xc4);

      if (fVar2 < fVar3 != (fVar2 == fVar3)) {

        *(uint *)&obj->field_0xd8 = uVar1 | 0x8100000;

      }

    }

    if (fVar2 - (float)obj->acc_TargetCenter < 0.1) {

      *(uint *)&obj->field_0xd8 = *(uint *)&obj->field_0xd8 | 0x80000;

    }

    FUN_004a7440(obj);

  }

  return;

}

/* ===== FUN_004a4480 @ 0x004A4480 ===== */
/* PS2 candidate: trajectory_calculate (conf 0.592) */



void FUN_004a4480(float *param_1,float *param_2,float *param_3,float *param_4,float param_5)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  

  fVar1 = param_3[1];

  fVar2 = param_2[1];

  fVar3 = param_3[2];

  fVar4 = param_2[2];

  fVar5 = 1.0 / param_5;

  *param_1 = fVar5 * (*param_3 - *param_2) - param_5 * *param_4 * 0.5;

  param_1[1] = fVar5 * (fVar1 - fVar2) - param_5 * param_4[1] * 0.5;

  param_1[2] = fVar5 * (fVar3 - fVar4) - param_5 * param_4[2] * 0.5;

  return;

}

/* ===== FUN_004a4510 @ 0x004A4510 ===== */
/* PS2 candidate: piranha_finit (conf 0.608) */



void FUN_004a4510(void)



{

  int *piVar1;

  

  piVar1 = &DAT_00632960;

  do {

    piVar1[2] = 0;

    piVar1[1] = 0;

    if (*piVar1 != 0) {

      FUN_00448920(*piVar1);

    }

    *piVar1 = 0;

    piVar1 = piVar1 + 3;

  } while ((int)piVar1 < 0x6329d8);

  return;

}

/* ===== FUN_004a4550 @ 0x004A4550 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* PS2 candidate: piranha_go (conf 0.444) */



void FUN_004a4550(void)



{

  undefined4 *puVar1;

  undefined4 *puVar2;

  int iVar3;

  uint uVar4;

  int in_ECX;

  float *pfVar5;

  int *piVar6;

  float10 fVar7;

  float10 fVar8;

  

  pfVar5 = (float *)&DAT_00632968;

  do {

    if (*pfVar5 != 0.0) {

      fVar7 = (float10)FUN_00518b70(0,0);

      fVar7 = (float10)*pfVar5 - fVar7;

      *pfVar5 = (float)fVar7;

      if (fVar7 < (float10)0.0 != (fVar7 == (float10)0.0)) {

        *pfVar5 = 0.0;

        pfVar5[-1] = 0.0;

        if (pfVar5[-2] != 0.0) {

          FUN_00448920(pfVar5[-2]);

        }

        pfVar5[-2] = 0.0;

      }

    }

    pfVar5 = pfVar5 + 3;

  } while ((int)pfVar5 < 0x6329e0);

  puVar2 = DAT_00632d70;

  if (DAT_00632e74 == 0) {

    for (; puVar1 = DAT_00632d98, puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {

      in_ECX = puVar2[3];

      if (((((*(uint *)(in_ECX + 0xd8) & 0x8000000) != 0) &&

           ((*(uint *)(in_ECX + 0xd8) & 0x4000c000) == 0)) &&

          (*(float *)(in_ECX + 0x278) < *(float *)(in_ECX + 0x1c0))) &&

         ((iVar3 = FUN_004a6160(in_ECX), iVar3 != 0 && ((*(uint *)(in_ECX + 0xd8) & 0x200) == 0))))

      goto LAB_004a473d;

    }

    for (; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {

      in_ECX = puVar1[3];

      if (((((*(uint *)(in_ECX + 0xd8) & 0x4000c000) == 0) &&

           (*(float *)(in_ECX + 0x278) < *(float *)(in_ECX + 0x1c0))) &&

          (((*(uint *)(in_ECX + 0xd8) & 0x8000000) != 0 &&

           ((*(int *)(in_ECX + 4) == 0xb && (*(int *)(in_ECX + 0x210) == 0)))))) &&

         (((*(int *)(in_ECX + 0x274) == 0 ||

           ((iVar3 = FUN_004a6180(*(int *)(in_ECX + 0x274)), iVar3 == 0 &&

            (iVar3 = FUN_004a6290(*(undefined4 *)(in_ECX + 0x274)), iVar3 == 0)))) &&

          (((*(int *)(in_ECX + 0xe8) == 5 ||

            ((uVar4 = *(uint *)(in_ECX + 0xdc) & 0xf, uVar4 == 0 || (uVar4 == 2)))) &&

           ((*(uint *)(in_ECX + 0xd8) & 0x200) == 0)))))) goto LAB_004a473d;

    }

    fVar8 = (float10)FUN_00518b70(0,0);

    fVar7 = (float10)_DAT_005a0ee0;

    _DAT_005a0ee0 = (float)(fVar8 + fVar7);

    piVar6 = (int *)0x0;

    if ((float10)2.0 < fVar8 + fVar7) {

      _DAT_005a0ee0 = 0.0;

      piVar6 = DAT_00632d68;

      if (DAT_00632d68 == (int *)0x0) {

        _DAT_005a0ee0 = 0.0;

        return;

      }

      while( true ) {

        in_ECX = piVar6[3];

        uVar4 = *(uint *)(in_ECX + 0xd8);

        if (((((uVar4 & 0x4000c000) == 0) &&

             (*(float *)(in_ECX + 0x278) < *(float *)(in_ECX + 0x1c0))) &&

            (*(int *)(in_ECX + 0x1e0) == 0x33)) &&

           (((uVar4 & 0x8000000) != 0 && ((uVar4 & 0x200) == 0)))) break;

        piVar6 = (int *)*piVar6;

        if (piVar6 == (int *)0x0) {

          return;

        }

      }

    }

    if (piVar6 != (int *)0x0) {

LAB_004a473d:

      iVar3 = FUN_004a4770(in_ECX);

      *(uint *)(iVar3 + 0xe0) = *(uint *)(iVar3 + 0xe0) | 1;

      *(undefined4 *)(iVar3 + 0xf0) = 0x3dcccccd;

      *(undefined4 *)(iVar3 + 0xf4) = 1;

    }

  }

  return;

}

/* ===== FUN_004a4770 @ 0x004A4770 ===== */
/* PS2 candidate: piranha_make__FP6OBJECT (conf 0.443) */



int FUN_004a4770(int param_1)



{

  float *pfVar1;

  float *pfVar2;

  float fVar3;

  int iVar4;

  int iVar5;

  float10 fVar6;

  float local_8;

  float local_4;

  

  iVar4 = param_1;

  iVar5 = object_allocate_type(0x3ed,0);

  *(int *)(iVar5 + 0x274) = param_1;

  *(undefined4 *)(iVar5 + 0xec) = 0x3dcccccd;

  *(undefined4 *)(iVar5 + 0xe0) = 0;

  *(undefined4 *)(iVar5 + 0xe4) = 1;

  *(uint *)(iVar5 + 0xd8) = *(uint *)(iVar5 + 0xd8) | 0x40000010;

  *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) | 0x200;

  FUN_004034a0(iVar5,1,0x21,0,0,0);

  pfVar1 = (float *)(param_1 + 0xa0);

  pfVar2 = (float *)(iVar5 + 0xa0);

  *pfVar2 = *pfVar1;

  *(undefined4 *)(iVar5 + 0xa4) = *(undefined4 *)(param_1 + 0xa4);

  *(undefined4 *)(iVar5 + 0xa8) = *(undefined4 *)(param_1 + 0xa8);

  *(undefined4 *)(iVar5 + 0xa8) = 0xbf800000;

  param_1 = 9;

  do {

    fVar6 = (float10)FUN_004d5760(0x43b40000);

    *(float *)(iVar5 + 200) = (float)fVar6;

    FUN_0050ae40((float)fVar6,&local_8,&local_4);

    *pfVar2 = *pfVar1 - local_8 * 20.0;

    fVar3 = *(float *)(iVar4 + 0xa4);

    *(undefined4 *)(iVar5 + 0xa8) = 0xbf800000;

    *(float *)(iVar5 + 0xa4) = local_4 * 20.0 + fVar3;

    fVar6 = (float10)FUN_00413e40(pfVar2);

    if (fVar6 < (float10)-2.0) {

      return iVar5;

    }

    param_1 = param_1 + -1;

  } while (param_1 != 0);

  return iVar5;

}

/* ===== FUN_004a48a0 @ 0x004A48A0 ===== */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

/* WARNING: Struct "OBJECT": ignoring multiple overlapping fields */

/* PS2 candidate: piranha_chase_swimmer__FP6OBJECT (conf 0.443) */



void FUN_004a48a0(OBJECT *obj)



{

  dword *pdVar1;

  float fVar2;

  bool bVar3;

  OBJECT *pOVar4;

  uint uVar5;

  float10 fVar6;

  float local_2c;

  float local_28;

  float local_24;

  float fStack_20;

  float local_18;

  float local_14;

  undefined4 local_10;

  float local_c;

  float local_8;

  undefined4 local_4;

  

  pOVar4 = obj;

  bVar3 = false;

  if ((obj->field_E0 & 0x18) == 0) {

    pdVar1 = &obj->gap_A0;

    fVar6 = (float10)FUN_0050a5e0(pdVar1,obj->field_274 + 0xa0);

    local_28 = (float)fVar6;

    fVar6 = (float10)FUN_0050a400(pdVar1,pOVar4->field_274 + 0xa0);

    local_24 = (float)fVar6;

    *(float *)&pOVar4->field_0xc8 = (float)fVar6;

    local_c = (float)*pdVar1;

    local_8 = *(float *)&pOVar4->field_0xa4;

    local_4 = *(undefined4 *)&pOVar4->field_0xa8;

    local_18 = (float)*pdVar1;

    local_14 = *(float *)&pOVar4->field_0xa4;

    local_10 = *(undefined4 *)&pOVar4->field_0xa8;

    fVar2 = *(float *)(pOVar4->field_274 + 0x154) * 1.8;

    if (local_28 <= fVar2 * fVar2) {

      pOVar4->field_E0 = pOVar4->field_E0 | 2;

      goto LAB_004a4bf3;

    }

    FUN_0050ae40(local_24,&obj,&local_2c);

    fVar6 = (float10)FUN_00518b70(pOVar4,0);

    local_24 = (float)(fVar6 * (float10)(float)obj * (float10)15.0);

    fVar6 = (float10)FUN_00518b70(pOVar4,0);

    fVar6 = fVar6 * (float10)local_2c * (float10)-15.0;

    fStack_20 = (float)fVar6;

    local_18 = (float)(fVar6 * (float10)0.25 + (float10)local_24 + (float10)local_18);

    local_14 = (fStack_20 - local_24 * 0.25) + local_14;

    local_c = local_24 * 10.0 + local_18;

    local_8 = fStack_20 * 10.0 + local_14;

    if (400.0 < local_28) {

      local_18 = (float)*pdVar1;

      local_14 = *(float *)&pOVar4->field_0xa4;

      local_10 = *(undefined4 *)&pOVar4->field_0xa8;

      pOVar4->field_184 = 0x3f800000;

      local_28 = SQRT(local_28) - 15.0;

      fVar6 = (float10)FUN_004d5780(0xc0800000,0x40800000);

      local_18 = (float)((float10)local_28 * (float10)local_24 + fVar6 + (float10)local_18);

      fVar6 = (float10)FUN_004d5780(0xc0800000,0x40800000);

      local_14 = (float)((float10)local_28 * (float10)fStack_20 + fVar6 + (float10)local_14);

    }

    fVar6 = (float10)FUN_00413e40(&local_18);

    if ((fVar6 < (float10)-2.0) && (fVar6 = (float10)FUN_00413e40(&local_c), fVar6 < (float10)-2.0))

    goto LAB_004a49ca;

  }

  else {

    local_c = (float)obj->gap_A0;

    local_8 = *(float *)&obj->field_0xa4;

    local_4 = *(undefined4 *)&obj->field_0xa8;

    local_18 = (float)obj->gap_A0;

    local_14 = *(float *)&obj->field_0xa4;

    local_10 = *(undefined4 *)&obj->field_0xa8;

    local_24 = (float)((obj->field_188 >> 8) % 10);

    fStack_20 = 0.0;

    local_28 = (float)(uint)local_24 + 2.0;

    if ((obj->field_E0 & 8) == 0) {

      fVar6 = (float10)FUN_00518b70(obj,0);

      fVar6 = (float10)*(float *)&pOVar4->field_0xc8 - fVar6 * (float10)120.0;

      *(float *)&pOVar4->field_0xc8 = (float)fVar6;

      fVar6 = fVar6 + (float10)90.0;

    }

    else {

      fVar6 = (float10)FUN_00518b70(obj,0);

      fVar6 = fVar6 * (float10)120.0 + (float10)*(float *)&pOVar4->field_0xc8;

      *(float *)&pOVar4->field_0xc8 = (float)fVar6;

      fVar6 = fVar6 - (float10)90.0;

    }

    FUN_0050ae40((float)fVar6,&obj,&local_2c);

    local_18 = (float)obj * local_28 + *(float *)(pOVar4->field_274 + 0xa0);

    local_14 = *(float *)(pOVar4->field_274 + 0xa4) - local_2c * local_28;

    fVar6 = (float10)FUN_00413e40(&local_18);

    if (fVar6 < (float10)-2.0) {

LAB_004a49ca:

      bVar3 = true;

      FUN_004993c0(pOVar4,&local_18);

    }

  }

  uVar5 = pOVar4->field_E0 & 0xfffffffd;

  pOVar4->field_E0 = uVar5;

  if (bVar3) {

    pOVar4->field_E0 = uVar5 | 4;

    return;

  }

LAB_004a4bf3:

  pOVar4->field_E0 = pOVar4->field_E0 & 0xfffffffb;

  return;

}

/* ===== FUN_004a4c10 @ 0x004A4C10 ===== */
/* PS2 candidate: piranha_launch_fx__FP6OBJECT (conf 0.546) */



void FUN_004a4c10(int param_1)



{

  int *piVar1;

  undefined4 uVar2;

  int iVar3;

  int iVar4;

  undefined4 local_40;

  undefined4 local_3c;

  undefined4 local_38;

  undefined4 local_30;

  undefined4 local_2c;

  undefined4 local_28;

  undefined4 local_24;

  

  iVar4 = -1;

  iVar3 = 0;

  piVar1 = &DAT_00632964;

  do {

    if (*piVar1 == 0) {

      if (iVar4 == -1) {

        iVar4 = iVar3;

      }

    }

    else if (*piVar1 == *(int *)(*(int *)(param_1 + 0x274) + 0x188)) {

      local_40 = *(undefined4 *)(*(int *)(param_1 + 0x274) + 0xa0);

      local_3c = *(undefined4 *)(*(int *)(param_1 + 0x274) + 0xa4);

      local_38 = 0;

      FUN_004489e0((&DAT_00632960)[iVar3 * 3],&local_40);

      if (iVar3 < 10) {

        return;

      }

      break;

    }

    piVar1 = piVar1 + 3;

    iVar3 = iVar3 + 1;

  } while ((int)piVar1 < 0x6329dc);

  if (iVar4 != -1) {

    local_30 = *(undefined4 *)(*(int *)(param_1 + 0x274) + 0xa0);

    local_2c = *(undefined4 *)(*(int *)(param_1 + 0x274) + 0xa4);

    local_28 = 0;

    local_24 = 8;

    uVar2 = fx_get_free_effect__Fv();

    (&DAT_00632960)[iVar4 * 3] = uVar2;

    (&DAT_00632964)[iVar4 * 3] = *(undefined4 *)(*(int *)(param_1 + 0x274) + 0x188);

    (&DAT_00632968)[iVar4 * 3] = 0x40000000;

  }

  return;

}

/* ===== FUN_004a54a0 @ 0x004A54A0 ===== */
void FUN_004a54a0(void)



{

  uint uVar1;

  uint uVar2;

  undefined4 *puVar3;

  

  uVar2 = DAT_00632fb4;

  DAT_00632fac = 0;

  puVar3 = DAT_00632fb8;

  for (uVar1 = DAT_00632fb4 >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {

    *puVar3 = 0;

    puVar3 = puVar3 + 1;

  }

  for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {

    *(undefined1 *)puVar3 = 0;

    puVar3 = (undefined4 *)((int)puVar3 + 1);

  }

  FUN_0041f0f0(0);

  return;

}

/* ===== FUN_004A54E0 @ 0x004A54E0 ===== */
void FUN_004A54E0(void)



{

  char cVar1;

  char cVar2;

  int iVar3;

  char *pcVar4;

  char *pcVar5;

  uint uVar6;

  char *pcVar7;

  char *pcVar8;

  undefined4 uVar9;

  undefined4 uVar10;

  

  if (DAT_00632af4 != '\0') {

    FUN_0040d130(0xffffffff);

  }

  if ((*(float *)(DAT_00632a88 + 0x1c0) <= *(float *)(DAT_00632a88 + 0x278)) &&

     (iVar3 = FUN_0040cf70(), iVar3 != 0)) {

    FUN_0040d130(1);

  }

  if ((DAT_00632ae8 != '\0') || (DAT_00632ae9 != '\0')) {

    if (DAT_00632fb8 == (char *)0x0) {

      DAT_00633020 = 0;

      comm_show_conn_menu();

    }

    DAT_00632fac = (DAT_00632ae8 == '\0') + 1;

    FUN_0041f0f0(1);

    iVar3 = DAT_00632a88;

    *(undefined4 *)(DAT_00632a88 + 0x208) = 0;

    *(undefined4 *)(iVar3 + 0x20c) = 0;

    DAT_00632fb0 = 0;

    *DAT_00632fb8 = '\0';

  }

  if (DAT_00632fac == 0) goto LAB_004a5802;

  if (DAT_00632aa8 != '\0') {

    if (*DAT_00632fb8 != '\0') {

      iVar3 = chat_log_init(DAT_00632fb8);

      if (iVar3 == 0) {

        if (DAT_00632fac == 1) {

          iVar3 = comm_00426540();

          uVar10 = 0x40;

          if (iVar3 == 0) {

            uVar9 = 2;

          }

          else {

            uVar9 = 1;

          }

        }

        else {

          uVar10 = 0x60;

          uVar9 = 3;

        }

        FUN_0052ea80(DAT_00632fb8,uVar9,uVar10,0);

      }

      *DAT_00632fb8 = '\0';

      DAT_00632fb0 = 0;

    }

    FUN_004a54a0();

    goto LAB_004a5802;

  }

  if (DAT_00632aa4._3_1_ != '\0') {

    FUN_004a54a0();

    goto LAB_004a5802;

  }

  if (DAT_00632aa0._3_1_ == '\0') {

    if ((char)DAT_00632aa4 == '\0') {

      if (DAT_00632ab9 == '\0') {

        if (DAT_00632ab3 == '\0') {

          if (DAT_00632ab4 == '\0') {

            if (DAT_00632ab5 == '\0') {

              if (DAT_00632ab6 != '\0') goto LAB_004a56f9;

            }

            else {

              DAT_00632fb0 = 0;

            }

          }

          else {

            DAT_00632fbc = (uint)(DAT_00632fbc == 0);

          }

        }

        else {

          uVar6 = 0xffffffff;

          pcVar4 = DAT_00632fb8;

          do {

            if (uVar6 == 0) break;

            uVar6 = uVar6 - 1;

            cVar2 = *pcVar4;

            pcVar4 = pcVar4 + 1;

          } while (cVar2 != '\0');

          if (DAT_00632fb0 < (int)(~uVar6 - 1)) {

            pcVar8 = DAT_00632fb8 + DAT_00632fb0;

            pcVar4 = pcVar8;

            do {

              pcVar4 = pcVar4 + 1;

              cVar2 = *pcVar4;

              *pcVar8 = cVar2;

              pcVar8 = pcVar8 + 1;

            } while (cVar2 != '\0');

          }

        }

      }

    }

    else {

      DAT_00632fb0 = DAT_00632fb0 + 1;

      uVar6 = 0xffffffff;

      pcVar4 = DAT_00632fb8;

      do {

        if (uVar6 == 0) break;

        uVar6 = uVar6 - 1;

        cVar2 = *pcVar4;

        pcVar4 = pcVar4 + 1;

      } while (cVar2 != '\0');

      if ((int)(~uVar6 - 1) < DAT_00632fb0) {

LAB_004a56f9:

        uVar6 = 0xffffffff;

        pcVar4 = DAT_00632fb8;

        do {

          if (uVar6 == 0) break;

          uVar6 = uVar6 - 1;

          cVar2 = *pcVar4;

          pcVar4 = pcVar4 + 1;

        } while (cVar2 != '\0');

        DAT_00632fb0 = ~uVar6 - 1;

      }

    }

  }

  else {

    DAT_00632fb0 = DAT_00632fb0 + -1;

    if (DAT_00632fb0 < 0) {

      DAT_00632fb0 = 0;

    }

  }

  pcVar4 = (char *)FUN_00519CF0();

  if (pcVar4 != (char *)0x0) {

    cVar2 = *pcVar4;

    iVar3 = DAT_00632fb0;

    pcVar8 = DAT_00632fb8;

    while (cVar2 != '\0') {

      pcVar4 = pcVar4 + 1;

      if (cVar2 == '\b') {

        if (0 < iVar3) {

          DAT_00632fb0 = iVar3 + -1;

          pcVar7 = pcVar8 + DAT_00632fb0;

          pcVar5 = pcVar7;

          do {

            pcVar5 = pcVar5 + 1;

            cVar2 = *pcVar5;

            *pcVar7 = cVar2;

            pcVar7 = pcVar7 + 1;

            iVar3 = DAT_00632fb0;

            pcVar8 = DAT_00632fb8;

          } while (cVar2 != '\0');

        }

      }

      else {

        uVar6 = 0xffffffff;

        pcVar5 = pcVar8;

        do {

          if (uVar6 == 0) break;

          uVar6 = uVar6 - 1;

          cVar1 = *pcVar5;

          pcVar5 = pcVar5 + 1;

        } while (cVar1 != '\0');

        if (iVar3 < (int)(~uVar6 - 1)) {

          if (DAT_00632fbc == 0) {

            pcVar8[iVar3] = cVar2;

          }

          else {

            uVar6 = 0xffffffff;

            pcVar5 = pcVar8;

            do {

              if (uVar6 == 0) break;

              uVar6 = uVar6 - 1;

              cVar1 = *pcVar5;

              pcVar5 = pcVar5 + 1;

            } while (cVar1 != '\0');

            if (DAT_00632fb4 <= (int)(~uVar6 - 1)) goto LAB_004a57f0;

            pcVar8 = pcVar8 + iVar3;

            uVar6 = 0xffffffff;

            pcVar5 = pcVar8;

            do {

              if (uVar6 == 0) break;

              uVar6 = uVar6 - 1;

              cVar1 = *pcVar5;

              pcVar5 = pcVar5 + 1;

            } while (cVar1 != '\0');

            FUN_00543270(pcVar8 + 1,pcVar8,~uVar6 - 1);

            DAT_00632fb8[DAT_00632fb0] = cVar2;

          }

        }

        else {

          if (DAT_00632fb4 <= iVar3) goto LAB_004a57f0;

          pcVar8[iVar3] = cVar2;

          DAT_00632fb8[DAT_00632fb0 + 1] = '\0';

        }

        DAT_00632fb0 = DAT_00632fb0 + 1;

        iVar3 = DAT_00632fb0;

        pcVar8 = DAT_00632fb8;

      }

LAB_004a57f0:

      cVar2 = *pcVar4;

    }

    wredit_00519c70();

  }

LAB_004a5802:

  FUN_004a59a0();

  if (DAT_00632a88 != 0) {

    if (((DAT_00632ae6 != '\0') && (DAT_00632bac == 0)) &&

       ((*(int *)(DAT_00632a88 + 0x1e0) != 3 || ((*(uint *)(DAT_00632a88 + 0xe0) & 0x100) == 0)))) {

      FUN_004753c0();

    }

    if (DAT_00632ae7 != '\0') {

      FUN_00452490(0,0);

    }

    if ((((DAT_00632aeb != '\0') && (DAT_00632bb8 == 0)) && (DAT_00632ba8 == 0)) &&

       (((DAT_00632bac == 0 && (DAT_00632bb0 == 0)) && (DAT_00632bb4 == 0)))) {

      FUN_0045a900(DAT_00632a88);

    }

    if (DAT_00632aec != '\0') {

      FUN_0045ab30(DAT_00632a88);

    }

    if (DAT_00632aea != '\0') {

      DAT_00633020 = DAT_00633020 ^ 1;

    }

    if (DAT_00632aa4._3_1_ != '\0') {

      if (DAT_00632bd8 == 0) {

        if (((DAT_00632bb0 == 0) && (DAT_00632ba8 == 0)) &&

           ((DAT_00632bb4 == 0 && ((DAT_00632bac == 0 && (DAT_00633040 == 0)))))) {

          FUN_00489D40();

        }

      }

      else {

        ANM_DumpCluster();

        ANM_DumpCluster(0x16);

      }

    }

    iVar3 = FUN_0052aa70();

    if (((iVar3 != 0) && (DAT_00632ad8 != '\0')) && (iVar3 = dialog_level_is_base(), iVar3 != 0)) {

      DAT_00633020 = 0;

      DAT_00632920 = 0xffffffff;

      comm_show_conn_menu();

    }

    if (DAT_00632a88 != 0) {

      FUN_004a5d10();

      if (*(int *)(DAT_00632a88 + 0x18c) + -1 < 2) {

        FUN_00500f50(DAT_006330cc,DAT_006330c4);

        FUN_004361b0();

        return;

      }

      FUN_00500f50(DAT_006330d0,DAT_006330c4);

    }

  }

  FUN_004361b0();

  return;

}

/* ===== FUN_004a59a0 @ 0x004A59A0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* PS2 candidate: PS2BaseViewTextRender (conf 0.722) */



void FUN_004a59a0(void)



{

  float fVar1;

  float fVar2;

  float10 fVar3;

  float local_28;

  float local_24;

  float local_20;

  float local_1c;

  float local_18;

  float local_14;

  undefined4 local_10;

  float local_c;

  float local_8;

  float local_4;

  

  if (DAT_00633124 == 0) {

    if (DAT_00632af7 != '\0') {

      FUN_0050ae40(*(undefined4 *)(DAT_00632a88 + 200),&local_18,&local_14);

      if (*(char *)(DAT_00632a88 + 0x20a) != '\0') {

        local_28 = 1.0;

        if (*(char *)(DAT_00632a88 + 0x20a) < '\x01') {

          local_28 = -1.0;

        }

        fVar3 = (float10)FUN_00518b70(DAT_00632a88,0,0);

        fVar3 = (float10)FUN_00518b70(DAT_00632a88,0,

                                      (float)(fVar3 * (float10)local_28 * (float10)local_14 *

                                             (float10)-1600.0));

        FUN_00499490(DAT_00632a88,

                     (float)(fVar3 * (float10)local_28 * (float10)local_18 * (float10)1600.0));

      }

      if (*(char *)(DAT_00632a88 + 0x20b) != '\0') {

        local_28 = 1.0;

        if (*(char *)(DAT_00632a88 + 0x20b) < '\x01') {

          local_28 = -1.0;

        }

        fVar3 = (float10)FUN_00518b70(DAT_00632a88,0,0);

        fVar3 = (float10)FUN_00518b70(DAT_00632a88,0,

                                      (float)(fVar3 * (float10)local_28 * (float10)local_18 *

                                             (float10)1600.0));

        FUN_00499490(DAT_00632a88,

                     (float)(fVar3 * (float10)local_28 * (float10)local_14 * (float10)1600.0));

      }

    }

    return;

  }

  FUN_0040d6f0(&local_24,&local_28,&local_10,&local_c);

  FUN_0050ae40(local_24,&local_1c,&local_20);

  if (DAT_00632af7 == '\0') {

    if ((((byte)(DAT_005dd0e4 >> 0x16) | (byte)(DAT_005dd0e4 >> 10)) & 1) == 0) {

      fVar1 = 1.0;

    }

    else {

      fVar1 = 4.0;

    }

  }

  else {

    fVar1 = 16.0;

  }

  if ((DAT_005dd0f8 >> 8 & 1) == 0) {

    if ((DAT_005dd0f8 & 0x10000) != 0) {

      fVar2 = -20.0;

      goto LAB_004a5a3c;

    }

  }

  else {

    fVar2 = 20.0;

LAB_004a5a3c:

    if (fVar2 * fVar1 != 0.0) {

      fVar2 = fVar2 * fVar1 * _DAT_006328e4;

      local_c = local_1c * fVar2 + local_c;

      local_8 = local_8 - fVar2 * local_20;

    }

  }

  if ((DAT_005dd0e4 >> 0x13 & 1) == 0) {

    if ((DAT_005dd0e4 >> 0x14 & 1) == 0) goto LAB_004a5ac1;

    fVar2 = -20.0;

  }

  else {

    fVar2 = 20.0;

  }

  if (fVar2 * fVar1 != 0.0) {

    fVar2 = fVar2 * fVar1 * _DAT_006328e4;

    local_c = local_20 * fVar2 + local_c;

    local_8 = fVar2 * local_1c + local_8;

  }

LAB_004a5ac1:

  if (DAT_00632af8 == '\0') {

    if (DAT_00632af9 != '\0') {

      local_4 = local_4 - _DAT_006328e4 * fVar1 * 20.0;

    }

  }

  else {

    local_4 = _DAT_006328e4 * fVar1 * 20.0 + local_4;

  }

  if ((DAT_005dd0f8 >> 0xb & 1) == 0) {

    if ((DAT_005dd0f8 >> 0xd & 1) == 0) {

      fVar2 = _DAT_00632b10 * fVar1 * -0.9;

    }

    else {

      fVar2 = fVar1 * -0.9;

    }

  }

  else {

    fVar2 = fVar1 * 0.9;

  }

  local_24 = fVar2 + local_24;

  if ((DAT_005dd0f8 >> 0x12 & 1) == 0) {

    if ((DAT_005dd0f8 >> 0x13 & 1) == 0) {

      fVar1 = fVar1 * _DAT_00632b14 * -0.3;

    }

    else {

      fVar1 = fVar1 * -0.6;

    }

  }

  else {

    fVar1 = fVar1 * 0.6;

  }

  local_28 = fVar1 + local_28;

  if (local_28 < 90.0) {

    if (local_28 < -90.0 != (local_28 == -90.0)) {

      local_28 = -90.0;

    }

  }

  else {

    local_28 = 90.0;

  }

  camera_override_info(local_24,local_28,local_10,&local_c);

  return;

}

/* ===== FUN_004a5cd0 @ 0x004A5CD0 ===== */
void FUN_004a5cd0(void)



{

  if (DAT_00632afe != '\0') {

    DAT_00633114 = 1;

  }

  DAT_00632afe = 0;

  if ((DAT_00633114 != 0) && (DAT_00633114 = DAT_00633114 + -1, DAT_00633114 == 0)) {

    main_scrnshot_004ebae0();

    return;

  }

  return;

}

/* ===== FUN_004a5d10 @ 0x004A5D10 ===== */
void FUN_004a5d10(void)



{

  int iVar1;

  undefined4 *puVar2;

  undefined4 *puVar3;

  float *pfVar4;

  int iVar5;

  float local_4;

  

  if (DAT_00632a88 != 0) {

    iVar1 = *(int *)(DAT_00632a88 + 0x1e0);

    if (iVar1 == 2) {

      pfVar4 = (float *)(*(int *)(DAT_00632a88 + 0x100) + 0x4c);

    }

    else {

      if (iVar1 != 3) {

        return;

      }

      pfVar4 = (float *)(*(int *)(DAT_00632a88 + 0x100) + 0xcec);

    }

    if (*(int *)(DAT_00632a88 + 0x170) == 0) {

      AudioSetSpeakerConfig__F14SPEAKER_SYSTEM_5(*pfVar4);

      return;

    }

    local_4 = 0.0;

    iVar5 = DAT_00632a88;

    puVar2 = DAT_00632d74;

    puVar3 = DAT_00632d70;

    if (iVar1 == 2) {

      for (; puVar3 != (undefined4 *)0x0; puVar3 = (undefined4 *)*puVar3) {

        if ((*(int *)(puVar3[3] + 0x170) == *(int *)(iVar5 + 0x170)) &&

           (*(int *)(iVar5 + 0x170) != 0)) {

          iVar1 = *(int *)(puVar3[3] + 0x100);

          local_4 = local_4 + *(float *)(iVar1 + 0x4c);

          *(undefined4 *)(iVar1 + 0x4c) = 0;

          iVar5 = DAT_00632a88;

        }

      }

    }

    else {

      for (; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {

        if ((*(int *)(puVar2[3] + 0x170) == *(int *)(iVar5 + 0x170)) &&

           (*(int *)(iVar5 + 0x170) != 0)) {

          iVar1 = *(int *)(puVar2[3] + 0x100);

          local_4 = local_4 + *(float *)(iVar1 + 0xcec);

          *(undefined4 *)(iVar1 + 0xcec) = 0;

          iVar5 = DAT_00632a88;

        }

      }

    }

    *pfVar4 = local_4;

    AudioSetSpeakerConfig__F14SPEAKER_SYSTEM_5(local_4);

  }

  return;

}

/* ===== player_draw_missile_lock @ 0x004A5E10 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void player_draw_missile_lock(void)



{

  undefined4 uVar1;

  float10 fVar2;

  float fVar3;

  

  if (0.0 < _DAT_00632b54) {

    fVar2 = (float10)main_dlog_004272e0();

    DAT_005a0ee4 = 0x3f000000;

    fVar3 = (float)(fVar2 * (float10)1.2);

    uVar1 = TextGetPtrQ(s_MissileLock_0055eb2c,fVar3);

    FUN_0051ba00(0xff0000,0,fVar3,0x3f000000,DAT_005a0ee4,uVar1);

    sound_play(0x10b);

    fVar2 = (float10)FUN_00518b70(DAT_00632a88,0);

    fVar2 = (float10)_DAT_00632b54 - fVar2;

    _DAT_00632b54 = (float)fVar2;

    if (fVar2 < (float10)0.0 != (fVar2 == (float10)0.0)) {

      _DAT_00632b54 = 0.0;

    }

  }

  return;

}

/* ===== FUN_004a5eb0 @ 0x004A5EB0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_004a5eb0(void)



{

  float10 fVar1;

  

  if (0.0 < _DAT_00632d10) {

    fVar1 = (float10)main_dlog_004272e0();

    _DAT_005a0ee8 = 0x3ecccccd;

    FUN_0051ba00(0xe0e020,0,(float)(fVar1 * (float10)1.2),0x3f000000,0x3ecccccd,&DAT_00632c10);

    fVar1 = (float10)FUN_00518b70(DAT_00632a88,0);

    fVar1 = (float10)_DAT_00632d10 - fVar1;

    _DAT_00632d10 = (float)fVar1;

    if (fVar1 < (float10)0.0 != (fVar1 == (float10)0.0)) {

      _DAT_00632d10 = 0.0;

    }

  }

  return;

}

/* ===== FUN_004a5f40 @ 0x004A5F40 ===== */
/* WARNING: Struct "OBJECT": ignoring multiple overlapping fields */

/* PS2 candidate: player_force_type (conf 0.383) */



void FUN_004a5f40(int param_1)



{

  int iVar1;

  int iVar2;

  dword dVar3;

  

  iVar1 = FUN_0052aa70();

  if (iVar1 == 0) {

    iVar1 = -1;

    if (param_1 == 0x85) {

      param_1 = 2;

      iVar1 = 0x85;

    }

    FUN_0049baa0(DAT_00632a88);

    FUN_00499cd0(DAT_00632a88);

    iVar2 = FUN_00497d70(param_1);

    if (iVar2 == 0) {

      param_1 = 0;

      iVar2 = FUN_00497d70(0);

      if (iVar2 == 0) {

        return;

      }

    }

    if (DAT_00632a88 != (OBJECT *)0x0) {

      DAT_00633108 = (uint)(param_1 != 0);

      object_copy_personality(DAT_00632a88);

      if (-1 < iVar1) {

        dVar3 = FUN_00497d20(0x85);

        DAT_00632a88->field_8 = dVar3;

      }

      *(uint *)&DAT_00632a88->field_0xd8 =

           *(uint *)&DAT_00632a88->field_0xd8 | *(uint *)(iVar2 + 0xd8);

      *(uint *)&DAT_00632a88->field_0xdc =

           *(uint *)&DAT_00632a88->field_0xdc | *(uint *)(iVar2 + 0xdc);

      *(uint *)&DAT_00632a88->field_0xdc = *(uint *)&DAT_00632a88->field_0xdc | 0x80000000;

      *(undefined4 *)&DAT_00632a88->field_0xcc = 0;

      *(undefined4 *)&DAT_00632a88->field_0xd4 = 0;

      FUN_0040d670();

      FUN_00499280(DAT_00632a88);

      FUN_0049b8a0(DAT_00632a88);

      anim_select_check(DAT_00632a88,1);

      DAT_00632a88->acc_grenade_do_stopped = DAT_00632a88->acc_grenade_do_stopped | 1;

      main_linkage_004704e0(&DAT_00632d78,DAT_00632a88);

      main_linkage_004704e0(&DAT_00632d70,DAT_00632a88);

      main_linkage_004704e0(&DAT_00632d74,DAT_00632a88);

      if (param_1 == 1) {

        main_linkage_00470250(&DAT_00632d78,DAT_00632a88);

        return;

      }

      if (param_1 == 2) {

        main_linkage_00470250(&DAT_00632d70,DAT_00632a88);

        return;

      }

      if (param_1 == 3) {

        main_linkage_00470250(&DAT_00632d74,DAT_00632a88);

      }

    }

  }

  return;

}

/* ===== FUN_004a6100 @ 0x004A6100 ===== */
/* PS2 candidate: ObjIsRipper (conf 0.368) */



undefined4 FUN_004a6100(int param_1)



{

  if ((param_1 != 0) && (*(int *)(param_1 + 0x1e0) == 0x17)) {

    return 1;

  }

  return 0;

}

/* ===== FUN_004a6120 @ 0x004A6120 ===== */
/* PS2 candidate: ObjIsJetski (conf 0.446) */



undefined4 FUN_004a6120(int param_1)



{

  if ((param_1 != 0) && (*(int *)(param_1 + 0x1e0) == 0x5a)) {

    return 1;

  }

  return 0;

}

/* ===== FUN_004a6140 @ 0x004A6140 ===== */
/* PS2 candidate: ObjIsTurret (conf 0.381) */



undefined4 FUN_004a6140(int param_1)



{

  if ((param_1 != 0) && (*(int *)(param_1 + 0x1e0) == 0x2c)) {

    return 1;

  }

  return 0;

}

/* ===== FUN_004a6160 @ 0x004A6160 ===== */
/* PS2 candidate: ObjIsMecc (conf 0.677) */



undefined4 FUN_004a6160(int param_1)



{

  if ((param_1 != 0) && (*(int *)(param_1 + 0x1e0) == 2)) {

    return 1;

  }

  return 0;

}

/* ===== FUN_004a6180 @ 0x004A6180 ===== */
/* PS2 candidate: ObjIsReaper (conf 0.59) */



undefined4 FUN_004a6180(int param_1)



{

  if ((param_1 != 0) && (*(int *)(param_1 + 0x1e0) == 3)) {

    return 1;

  }

  return 0;

}

/* ===== FUN_004a61a0 @ 0x004A61A0 ===== */
/* PS2 candidate: ObjIsKabuto (conf 0.626) */



undefined4 FUN_004a61a0(int param_1)



{

  if ((param_1 != 0) && (*(int *)(param_1 + 0x1e0) == 1)) {

    return 1;

  }

  return 0;

}

/* ===== FUN_004a61c0 @ 0x004A61C0 ===== */
undefined4 FUN_004a61c0(int param_1)



{

  if ((param_1 != 0) && (*(int *)(param_1 + 0x1e0) == 0xf)) {

    return 1;

  }

  return 0;

}

/* ===== FUN_004a61e0 @ 0x004A61E0 ===== */
/* PS2 candidate: ObjIsPlayer (conf 0.381) */



undefined4 FUN_004a61e0(int param_1)



{

  if ((param_1 != 0) && ((*(byte *)(param_1 + 0x1c8) & 1) != 0)) {

    return 1;

  }

  return 0;

}

/* ===== FUN_004a6200 @ 0x004A6200 ===== */
/* PS2 candidate: meccbasepit_bldg_from_object (conf 0.712) */



undefined4 FUN_004a6200(int param_1)



{

  if ((param_1 != 0) && (*(int *)(param_1 + 0x1e0) == 0x20)) {

    return 1;

  }

  return 0;

}

/* ===== FUN_004a6220 @ 0x004A6220 ===== */
/* PS2 candidate: ObjIsMeccBldg (conf 0.712) */



undefined4 FUN_004a6220(int param_1)



{

  if ((param_1 != 0) && (*(int *)(param_1 + 0x1e0) == 0x4a)) {

    return 1;

  }

  return 0;

}

/* ===== FUN_004a6240 @ 0x004A6240 ===== */
undefined4 FUN_004a6240(int param_1)



{

  if (param_1 != 0) {

    if (*(int *)(param_1 + 0x1e0) == 0x4a) {

      if ((*(int *)(param_1 + 4) != 0x447) && (*(int *)(param_1 + 4) != 0x342)) {

        return 1;

      }

    }

    else if ((*(int *)(param_1 + 0x1e0) == 0x2c) && (*(int *)(param_1 + 0x18c) != 100)) {

      return 1;

    }

  }

  return 0;

}

/* ===== FUN_004a6290 @ 0x004A6290 ===== */
/* PS2 candidate: reaperbase_bldg_from_object (conf 0.712) */



undefined4 FUN_004a6290(int param_1)



{

  if ((param_1 != 0) && (*(int *)(param_1 + 0x1e0) == 0x52)) {

    return 1;

  }

  return 0;

}

/* ===== FUN_004a62b0 @ 0x004A62B0 ===== */
undefined4 FUN_004a62b0(int param_1)



{

  int iVar1;

  

  if (param_1 != 0) {

    if (*(int *)(param_1 + 0x1e0) == 0x53) {

      iVar1 = *(int *)(param_1 + 4);

      if (((iVar1 != 0x359) && (iVar1 != 0x35a)) && (iVar1 != 0x353)) {

        return 1;

      }

    }

    else if ((*(int *)(param_1 + 0x1e0) == 0x2c) && (*(int *)(param_1 + 0x18c) != 100)) {

      return 1;

    }

  }

  return 0;

}

/* ===== FUN_004a6300 @ 0x004A6300 ===== */
/* PS2 candidate: ObjIsReaperBldg (conf 0.341) */



undefined4 FUN_004a6300(int param_1)



{

  if ((param_1 != 0) && (*(int *)(param_1 + 0x1e0) == 0x53)) {

    return 1;

  }

  return 0;

}

/* ===== FUN_004a6320 @ 0x004A6320 ===== */
undefined4 FUN_004a6320(int param_1)



{

  int iVar1;

  

  if (((param_1 != 0) && (*(int *)(param_1 + 0x1e0) == 0x4a)) &&

     ((iVar1 = *(int *)(param_1 + 4), iVar1 == 0x2c5 ||

      (((iVar1 == 0x2e8 || (iVar1 == 0x2ca)) || (iVar1 == 0x307)))))) {

    return 1;

  }

  return 0;

}

/* ===== FUN_004a6360 @ 0x004A6360 ===== */
undefined4 FUN_004a6360(int param_1)



{

  int iVar1;

  

  if (((param_1 != 0) && (*(int *)(param_1 + 0x1e0) == 0x53)) &&

     ((iVar1 = *(int *)(param_1 + 4), iVar1 == 0x47c ||

      (((iVar1 == 0x47e || (iVar1 == 0x47d)) || (iVar1 == 0x47f)))))) {

    return 1;

  }

  return 0;

}

/* ===== FUN_004a63a0 @ 0x004A63A0 ===== */
undefined4 FUN_004a63a0(int param_1)



{

  undefined4 *puVar1;

  int iVar2;

  

  iVar2 = FUN_0052aa70();

  if ((iVar2 != 0) && (puVar1 = DAT_00632d98, (*(uint *)(param_1 + 0xdc) & 0x800000) != 0)) {

    for (; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {

      iVar2 = puVar1[3];

      if ((-1 < (char)((uint)*(undefined4 *)(iVar2 + 0xd8) >> 8)) &&

         (((*(int *)(iVar2 + 0x210) == param_1 || (*(int *)(iVar2 + 0x274) == param_1)) &&

          (*(int *)(iVar2 + 0xe8) == 10)))) {

        return 1;

      }

    }

  }

  return 0;

}

/* ===== voBufReset__FP5VoBuf @ 0x004A6400 ===== */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */



void voBufReset__FP5VoBuf(undefined4 *p0)



{

  p0[0x82] = 0;

  p0[0x83] = 0;

  return;

}

/* ===== FUN_004a6420 @ 0x004A6420 ===== */
void FUN_004a6420(int param_1)



{

  int iVar1;

  int *piVar2;

  int *piVar3;

  bool bVar4;

  int local_8 [2];

  

  if ((param_1 != 0) && ((*(uint *)(param_1 + 0xd8) & 0xc000) == 0)) {

    if ((*(uint *)(param_1 + 0x1c8) & 0x10) != 0) {

      local_8[0] = 0;

      local_8[1] = 0;

      bVar4 = true;

      iVar1 = 2;

      piVar2 = local_8;

      piVar3 = (int *)(param_1 + 0x208);

      do {

        if (iVar1 == 0) break;

        iVar1 = iVar1 + -1;

        bVar4 = *piVar2 == *piVar3;

        piVar2 = piVar2 + 1;

        piVar3 = piVar3 + 1;

      } while (bVar4);

      if (bVar4) {

        return;

      }

      *(uint *)(param_1 + 0x1c8) = *(uint *)(param_1 + 0x1c8) & 0xffffffef;

    }

    *(undefined4 *)(param_1 + 0x11c) = *(undefined4 *)(param_1 + 0x10c);

    *(undefined4 *)(param_1 + 0x120) = *(undefined4 *)(param_1 + 0x110);

    *(undefined4 *)(param_1 + 0x124) = *(undefined4 *)(param_1 + 0x114);

    *(undefined4 *)(param_1 + 0x118) = *(undefined4 *)(param_1 + 0x108);

    FUN_0049a090(param_1);

  }

  return;

}

/* ===== FUN_004a6730 @ 0x004A6730 ===== */
/* WARNING: Struct "OBJECT": ignoring multiple overlapping fields */



void FUN_004a6730(OBJECT *param_1)



{

  float10 fVar1;

  float10 fVar2;

  

  FUN_004a6860(param_1);

  if (param_1->field_0x209 != '\0') {

    fVar1 = (float10)FUN_00518b70(param_1,0);

    fVar2 = (float10)FUN_0040d480();

    fVar1 = (float10)(int)(char)param_1->field_0x209 * (float10)0.03125 *

            fVar2 * (float10)(float)fVar1 * (float10)90.0 + (float10)*(float *)&param_1->field_0xd4;

    *(float *)&param_1->field_0xd4 = (float)fVar1;

    if ((param_1 == DAT_00632a88) && ((float10)80.0 < fVar1)) {

      *(undefined4 *)&param_1->field_0xd4 = 0x42a00000;

    }

    if (*(float *)&param_1->field_0xd4 < -90.0) {

      *(undefined4 *)&param_1->field_0xd4 = 0xc2b40000;

    }

  }

  FUN_004a6c00(param_1);

  if ((*(uint *)&param_1->field_0xd8 & 0x10) == 0) {

    if (((*(uint *)&param_1->field_0xd8 & 0x80000) == 0) && (*(int *)&param_1->field_0x210 == 0)) {

      fVar1 = (float10)FUN_00518b70(param_1,0);

      *(float *)&param_1->field_0x108 =

           (float)((float10)*(float *)&param_1->field_0x108 -

                  fVar1 * (float10)(float)param_1->field_1B8);

    }

    else if (*(float *)&param_1->field_0x108 < 0.0) {

      *(undefined4 *)&param_1->field_0x108 = 0;

    }

  }

  fVar1 = (float10)FUN_00518b70(param_1,0);

  FUN_004992d0(param_1,0,0,

               (float)(((float10)*(float *)&param_1->field_0x118 +

                       (float10)*(float *)&param_1->field_0x108) * fVar1 * (float10)0.5));

  return;

}

/* ===== FUN_004a6860 @ 0x004A6860 ===== */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

/* WARNING: Struct "OBJECT": ignoring multiple overlapping fields */



void FUN_004a6860(OBJECT *obj)



{

  float fVar1;

  float fVar2;

  OBJECT *pOVar3;

  OBJECT *pOVar4;

  float10 fVar5;

  

  pOVar4 = obj;

  if (DAT_00632bc4 != 0) {

    return;

  }

  fVar5 = (float10)FUN_0040d480();

  fVar1 = (float)((float10)(int)(char)obj->field_0x208 * (float10)0.03125 * fVar5);

  fVar5 = (float10)FUN_00518b70(obj,0);

  fVar2 = (float)(fVar5 * (float10)(float)obj->field_1A4 * (float10)fVar1);

  fVar1 = fVar1 * (float)obj->field_1A8;

  if (fVar1 <= 0.0) {

    if (0.0 <= fVar1) {

      if (*(float *)&obj->field_0x114 <= 0.0) {

        if (0.0 <= *(float *)&obj->field_0x114) goto LAB_004a6a79;

        fVar5 = (float10)FUN_00518b70(obj,0);

        fVar5 = fVar5 * (float10)(float)obj->field_1AC + (float10)*(float *)&obj->field_0x114;

        *(float *)&obj->field_0x114 = (float)fVar5;

        if (fVar5 <= (float10)0.0) goto LAB_004a6a79;

      }

      else {

        fVar5 = (float10)FUN_00518b70(obj,0);

        fVar5 = (float10)*(float *)&obj->field_0x114 - fVar5 * (float10)(float)obj->field_1AC;

        *(float *)&obj->field_0x114 = (float)fVar5;

        if ((float10)0.0 <= fVar5) goto LAB_004a6a79;

      }

      *(undefined4 *)&obj->field_0x114 = 0;

      goto LAB_004a6a79;

    }

    if (0.0 < *(float *)&obj->field_0x114) {

      *(undefined4 *)&obj->field_0x114 = 0;

    }

    if (fVar1 < *(float *)&obj->field_0x114) {

      fVar2 = fVar2 + *(float *)&obj->field_0x114;

      *(float *)&obj->field_0x114 = fVar2;

      if (fVar2 < fVar1) {

        *(float *)&obj->field_0x114 = fVar1;

      }

      goto LAB_004a6a79;

    }

    if (fVar1 <= *(float *)&obj->field_0x114) goto LAB_004a6a79;

    fVar5 = (float10)FUN_00518b70(obj,0);

    fVar5 = fVar5 * (float10)(float)obj->field_1AC;

  }

  else {

    if (*(float *)&obj->field_0x114 < 0.0) {

      *(undefined4 *)&obj->field_0x114 = 0;

    }

    if (fVar1 <= *(float *)&obj->field_0x114) {

      if (fVar1 < *(float *)&obj->field_0x114) {

        fVar5 = (float10)FUN_00518b70(obj,0);

        fVar5 = (float10)*(float *)&obj->field_0x114 - fVar5 * (float10)(float)obj->field_1AC;

        *(float *)&obj->field_0x114 = (float)fVar5;

        if (fVar5 < (float10)fVar1) {

          *(float *)&obj->field_0x114 = fVar1;

        }

      }

      goto LAB_004a6a79;

    }

    fVar5 = (float10)fVar2;

  }

  fVar5 = fVar5 + (float10)*(float *)&obj->field_0x114;

  *(float *)&obj->field_0x114 = (float)fVar5;

  if ((float10)fVar1 < fVar5) {

    *(float *)&obj->field_0x114 = fVar1;

  }

LAB_004a6a79:

  fVar5 = (float10)FUN_00518b70(obj,0);

  pOVar3 = (OBJECT *)

           (float)(((float10)(float)obj->acc_sf_arm_followers + (float10)*(float *)&obj->field_0x114

                   ) * fVar5 * (float10)0.5);

  if (((*(uint *)&obj->field_0xd8 & 0x1000000) != 0) &&

     (((fVar5 = (float10)FUN_0050a7c0(*(undefined4 *)&obj->field_0x158,

                                      *(undefined4 *)&obj->field_0xc8), (float10)0.0 < fVar5 &&

       (fVar5 < (float10)(float)pOVar3)) ||

      ((fVar5 < (float10)0.0 && ((float10)(float)pOVar3 < fVar5)))))) {

    obj->acc_sf_arm_followers = 0;

    *(undefined4 *)&obj->field_0x114 = 0;

    pOVar3 = (OBJECT *)(float)fVar5;

  }

  obj = pOVar3;

  fVar1 = (float)obj + *(float *)&pOVar4->field_0xc8;

  *(float *)&pOVar4->field_0xc8 = fVar1;

  if (360.0 <= fVar1) {

    *(float *)&pOVar4->field_0xc8 = fVar1 - 360.0;

  }

  if (*(float *)&pOVar4->field_0xc8 < 0.0) {

    *(float *)&pOVar4->field_0xc8 = *(float *)&pOVar4->field_0xc8 + 360.0;

  }

  return;

}

/* ===== FUN_004a6b60 @ 0x004A6B60 ===== */
void FUN_004a6b60(int param_1)



{

  float10 fVar1;

  float10 fVar2;

  

  if (*(char *)(param_1 + 0x209) != '\0') {

    fVar1 = (float10)FUN_00518b70(param_1,0);

    fVar2 = (float10)FUN_0040d480();

    fVar1 = (float10)(int)*(char *)(param_1 + 0x209) * (float10)0.03125 *

            fVar2 * (float10)(float)fVar1 * (float10)90.0 + (float10)*(float *)(param_1 + 0xd4);

    *(float *)(param_1 + 0xd4) = (float)fVar1;

    if ((param_1 == DAT_00632a88) && ((float10)80.0 < fVar1)) {

      *(undefined4 *)(param_1 + 0xd4) = 0x42a00000;

    }

    if (*(float *)(param_1 + 0xd4) < -90.0) {

      *(undefined4 *)(param_1 + 0xd4) = 0xc2b40000;

    }

  }

  return;

}

/* ===== FUN_004a6c00 @ 0x004A6C00 ===== */
/* PS2 candidate: playerobj_walkrun (conf 0.474) */



void FUN_004a6c00(float param_1)



{

  float fVar1;

  float fVar2;

  float fVar3;

  int iVar4;

  int iVar5;

  float10 fVar6;

  float local_10;

  float local_c;

  float local_8;

  float local_4;

  

  iVar4 = (int)param_1;

  FUN_0050ae40(*(undefined4 *)((int)param_1 + 200),&local_8,&local_4);

  fVar3 = (float)(int)*(char *)((int)param_1 + 0x20a) * 0.03125;

  fVar6 = (float10)FUN_00518b70(param_1,0);

  fVar1 = (float)(fVar6 * (float10)fVar3 * (float10)*(float *)((int)param_1 + 400));

  fVar3 = fVar3 * *(float *)((int)param_1 + 0x194);

  iVar5 = FUN_004a6160(param_1);

  if ((iVar5 == 0) || ((*(uint *)((int)param_1 + 0xd8) & 0x8000000) == 0)) {

    if ((*(uint *)((int)param_1 + 0xd8) & 0x100000) != 0) {

      fVar2 = *(float *)((int)param_1 + 0x19c);

      goto LAB_004a6c9b;

    }

  }

  else {

    fVar2 = *(float *)(DAT_00632ed8 + 0x1c);

LAB_004a6c9b:

    fVar3 = fVar2 * fVar3;

  }

  param_1 = fVar3;

  if (param_1 <= 0.0) {

    if (0.0 <= param_1) {

      if (*(float *)(iVar4 + 0x10c) <= 0.0) {

        if (*(float *)(iVar4 + 0x10c) < 0.0) {

          fVar6 = (float10)FUN_00518b70(iVar4,0);

          fVar6 = fVar6 * (float10)*(float *)(iVar4 + 0x1a0) + (float10)*(float *)(iVar4 + 0x10c);

          *(float *)(iVar4 + 0x10c) = (float)fVar6;

          if ((float10)0.0 < fVar6) goto LAB_004a6e5a;

        }

      }

      else {

        fVar6 = (float10)FUN_00518b70(iVar4,0);

        fVar6 = (float10)*(float *)(iVar4 + 0x10c) - fVar6 * (float10)*(float *)(iVar4 + 0x1a0);

        *(float *)(iVar4 + 0x10c) = (float)fVar6;

        if (fVar6 < (float10)0.0) {

LAB_004a6e5a:

          *(undefined4 *)(iVar4 + 0x10c) = 0;

        }

      }

    }

    else {

      if (0.0 < *(float *)(iVar4 + 0x10c)) {

        *(undefined4 *)(iVar4 + 0x10c) = 0;

      }

      if (*(float *)(iVar4 + 0x10c) <= param_1) {

        if (*(float *)(iVar4 + 0x10c) < param_1) {

          fVar6 = (float10)FUN_00518b70(iVar4,0);

          fVar6 = fVar6 * (float10)*(float *)(iVar4 + 0x1a0);

          goto LAB_004a6ce2;

        }

      }

      else {

        fVar1 = fVar1 + *(float *)(iVar4 + 0x10c);

        *(float *)(iVar4 + 0x10c) = fVar1;

        if (fVar1 < param_1) {

          *(float *)(iVar4 + 0x10c) = param_1;

        }

      }

    }

  }

  else {

    if (*(float *)(iVar4 + 0x10c) < 0.0) {

      *(undefined4 *)(iVar4 + 0x10c) = 0;

    }

    if (param_1 <= *(float *)(iVar4 + 0x10c)) {

      if (param_1 < *(float *)(iVar4 + 0x10c)) {

        fVar6 = (float10)FUN_00518b70(iVar4,0);

        fVar6 = (float10)*(float *)(iVar4 + 0x10c) - fVar6 * (float10)*(float *)(iVar4 + 0x1a0);

        *(float *)(iVar4 + 0x10c) = (float)fVar6;

        if (fVar6 < (float10)param_1) {

          *(float *)(iVar4 + 0x10c) = param_1;

        }

      }

    }

    else {

      fVar6 = (float10)fVar1;

LAB_004a6ce2:

      fVar6 = fVar6 + (float10)*(float *)(iVar4 + 0x10c);

      *(float *)(iVar4 + 0x10c) = (float)fVar6;

      if ((float10)param_1 < fVar6) {

        *(float *)(iVar4 + 0x10c) = param_1;

      }

    }

  }

  fVar3 = (float)(int)*(char *)(iVar4 + 0x20b) * 0.03125;

  fVar6 = (float10)FUN_00518b70(iVar4,0);

  fVar1 = (float)(fVar6 * (float10)fVar3 * (float10)*(float *)(iVar4 + 400));

  fVar3 = fVar3 * *(float *)(iVar4 + 0x194);

  iVar5 = FUN_004a6160(iVar4);

  if ((iVar5 == 0) || ((*(uint *)(iVar4 + 0xd8) & 0x8000000) == 0)) {

    if ((*(uint *)(iVar4 + 0xd8) & 0x100000) != 0) {

      fVar3 = fVar3 * *(float *)(iVar4 + 0x19c);

    }

  }

  else {

    fVar3 = *(float *)(DAT_00632ed8 + 0x1c) * fVar3;

  }

  if ((*(uint *)(iVar4 + 0x1c8) & 0x40000) == 0) {

    fVar3 = fVar3 * 0.2;

  }

  if (fVar3 <= 0.0) {

    if (0.0 <= fVar3) {

      if (*(float *)(iVar4 + 0x110) <= 0.0) {

        if (0.0 <= *(float *)(iVar4 + 0x110)) goto LAB_004a70b2;

        fVar6 = (float10)FUN_00518b70(iVar4,0);

        fVar6 = fVar6 * (float10)*(float *)(iVar4 + 0x1a0) + (float10)*(float *)(iVar4 + 0x110);

        *(float *)(iVar4 + 0x110) = (float)fVar6;

        if (fVar6 <= (float10)0.0) goto LAB_004a70b2;

      }

      else {

        fVar6 = (float10)FUN_00518b70(iVar4,0);

        fVar6 = (float10)*(float *)(iVar4 + 0x110) - fVar6 * (float10)*(float *)(iVar4 + 0x1a0);

        *(float *)(iVar4 + 0x110) = (float)fVar6;

        if ((float10)0.0 <= fVar6) goto LAB_004a70b2;

      }

      *(undefined4 *)(iVar4 + 0x110) = 0;

      goto LAB_004a70b2;

    }

    if (0.0 < *(float *)(iVar4 + 0x110)) {

      *(undefined4 *)(iVar4 + 0x110) = 0;

    }

    if (fVar3 < *(float *)(iVar4 + 0x110)) {

      fVar1 = fVar1 + *(float *)(iVar4 + 0x110);

      *(float *)(iVar4 + 0x110) = fVar1;

      if (fVar1 < fVar3) {

        *(float *)(iVar4 + 0x110) = fVar3;

      }

      goto LAB_004a70b2;

    }

    if (fVar3 <= *(float *)(iVar4 + 0x110)) goto LAB_004a70b2;

    fVar6 = (float10)FUN_00518b70(iVar4,0);

    fVar6 = fVar6 * (float10)*(float *)(iVar4 + 0x1a0);

  }

  else {

    if (*(float *)(iVar4 + 0x110) < 0.0) {

      *(undefined4 *)(iVar4 + 0x110) = 0;

    }

    if (fVar3 <= *(float *)(iVar4 + 0x110)) {

      if (fVar3 < *(float *)(iVar4 + 0x110)) {

        fVar6 = (float10)FUN_00518b70(iVar4,0);

        fVar6 = (float10)*(float *)(iVar4 + 0x110) - fVar6 * (float10)*(float *)(iVar4 + 0x1a0);

        *(float *)(iVar4 + 0x110) = (float)fVar6;

        if (fVar6 < (float10)fVar3) {

          *(float *)(iVar4 + 0x110) = fVar3;

        }

      }

      goto LAB_004a70b2;

    }

    fVar6 = (float10)fVar1;

  }

  fVar6 = fVar6 + (float10)*(float *)(iVar4 + 0x110);

  *(float *)(iVar4 + 0x110) = (float)fVar6;

  if ((float10)fVar3 < fVar6) {

    *(float *)(iVar4 + 0x110) = fVar3;

  }

LAB_004a70b2:

  fVar6 = (float10)FUN_00518b70(iVar4,0);

  fVar1 = (float)(((float10)*(float *)(iVar4 + 0x11c) + (float10)*(float *)(iVar4 + 0x10c)) * fVar6

                 * (float10)0.5);

  fVar6 = (float10)FUN_00518b70(iVar4,0);

  fVar6 = ((float10)*(float *)(iVar4 + 0x120) + (float10)*(float *)(iVar4 + 0x110)) * fVar6 *

          (float10)0.5;

  local_c = (float)(fVar6 * (float10)local_4 + (float10)fVar1 * (float10)local_8);

  local_10 = (float)(fVar6 * (float10)local_8 - (float10)fVar1 * (float10)local_4);

  if ((*(uint *)(iVar4 + 0xd8) & 0x2000000) != 0) {

    fVar1 = *(float *)(iVar4 + 0x15c) - *(float *)(iVar4 + 0xa0);

    fVar3 = *(float *)(iVar4 + 0x160) - *(float *)(iVar4 + 0xa4);

    if ((((0.0 <= fVar1) && (fVar1 < local_c)) ||

        ((!NAN(fVar1) && fVar1 < 0.0 != (fVar1 == 0.0) && (local_c < fVar1)))) &&

       (local_c = fVar1, ABS(fVar3) < fVar1 * 0.2)) {

      local_10 = fVar3;

    }

    if ((((0.0 <= fVar3) && (fVar3 < local_10)) ||

        ((fVar3 < 0.0 != (fVar3 == 0.0) && (local_10 < fVar3)))) &&

       (local_10 = fVar3, ABS(fVar1) < fVar3 * 0.2)) {

      local_c = fVar1;

    }

    if ((fVar1 == local_c) && (fVar3 == local_10)) {

      *(undefined4 *)(iVar4 + 0x110) = 0;

      *(undefined4 *)(iVar4 + 0x10c) = 0;

    }

  }

  FUN_004992d0(iVar4,local_c,local_10,0);

  return;

}

/* ===== FUN_004a73a0 @ 0x004A73A0 ===== */
void FUN_004a73a0(int param_1)



{

  float10 fVar1;

  

  if ((*(uint *)(param_1 + 0xd8) & 0x10) == 0) {

    if (((*(uint *)(param_1 + 0xd8) & 0x80000) == 0) && (*(int *)(param_1 + 0x210) == 0)) {

      fVar1 = (float10)FUN_00518b70(param_1,0);

      *(float *)(param_1 + 0x108) =

           (float)((float10)*(float *)(param_1 + 0x108) -

                  fVar1 * (float10)*(float *)(param_1 + 0x1b8));

      return;

    }

    if (*(float *)(param_1 + 0x108) < 0.0) {

      *(undefined4 *)(param_1 + 0x108) = 0;

    }

  }

  return;

}

/* ===== FUN_004a7400 @ 0x004A7400 ===== */
void FUN_004a7400(int param_1)



{

  float10 fVar1;

  

  fVar1 = (float10)FUN_00518b70(param_1,0);

  FUN_004992d0(param_1,0,0,

               (float)(((float10)*(float *)(param_1 + 0x118) + (float10)*(float *)(param_1 + 0x108))

                       * fVar1 * (float10)0.5));

  return;

}

/* ===== FUN_004a7440 @ 0x004A7440 ===== */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

/* WARNING: Struct "OBJECT": ignoring multiple overlapping fields */

/* PS2 candidate: ObjectCalculateTransform (conf 0.497) */



void FUN_004a7440(OBJECT *obj)



{

  float fVar1;

  dword dVar2;

  uint uVar3;

  uint uVar4;

  float local_18;

  float local_14;

  float local_10;

  float local_c;

  float local_8;

  float local_4;

  

  if ((*(uint *)&obj->field_0xd8 & 0x10000) == 0) {

    fVar1 = *(float *)&obj->field_0xc4;

    FUN_0050ae40(-*(float *)&obj->field_0xcc,&local_18,&local_14);

    FUN_0050ae40(*(undefined4 *)&obj->field_0xd0,&local_4,&local_8);

    FUN_0050ae40(*(undefined4 *)&obj->field_0xc8,&local_10,&local_c);

    obj->gap_298 = (dword)(local_c * local_8 * fVar1);

    *(float *)&obj->field_0x29c = (-(local_18 * local_c * local_4) - local_10 * local_14) * fVar1;

    *(float *)&obj->field_0x2a0 = (local_10 * local_18 - local_c * local_4 * local_14) * fVar1;

    *(float *)&obj->field_0x2a8 = local_10 * local_8 * fVar1;

    *(float *)&obj->field_0x2ac = (local_c * local_14 - local_10 * local_4 * local_18) * fVar1;

    *(float *)&obj->field_0x2b0 = (-(local_10 * local_4 * local_14) - local_c * local_18) * fVar1;

    obj->gap_2B8 = (dword)(local_4 * fVar1);

    obj->acc_reaper_can_do_cosmetic_a = (dword)(local_8 * local_18 * fVar1);

    obj->acc_reaper_can_do_cosmetic_a = (dword)(local_8 * local_14 * fVar1);

    if (*(int *)&obj->field_0xc4 == 0x3f800000) {

      uVar4 = 0;

    }

    else {

      uVar4 = 2;

    }

    if (0.0 <= *(float *)&obj->field_0xc4) {

      uVar3 = 0;

    }

    else {

      uVar3 = 8;

    }

    obj->field_294 = uVar3 | uVar4 | 1;

  }

  uVar4 = obj->field_294;

  dVar2 = *(dword *)&obj->field_0xa8;

  *(dword *)((int)&obj->acc_gate_death_move + 3) = obj->gap_A0;

  obj->field_294 = uVar4 | 0x10;

  obj->field_2B4 = *(dword *)&obj->field_0xa4;

  obj->field_2C4 = dVar2;

  obj->gap_2D0 = 0;

  obj->acc_vu0_ObjectCollision = 0;

  obj->gap_2C8 = 0;

  *(undefined4 *)&obj->field_0x2d4 = 0x3f800000;

  *(uint *)&obj->field_0xd8 = *(uint *)&obj->field_0xd8 | 0x20;

  return;

}

/* ===== FUN_004a7630 @ 0x004A7630 ===== */
float10 FUN_004a7630(int param_1,int param_2)



{

  float10 fVar1;

  undefined1 local_44 [8];

  float fStack_3c;

  float fStack_2c;

  

  (*(code *)PTR_FUN_00580c18)(local_44,param_1 + 0x294,param_2 * 0x44 + *(int *)(param_1 + 0x2dc));

  if ((-(float10)fStack_3c == (float10)0.0) && (-(float10)fStack_2c == (float10)0.0)) {

    return (float10)90.0;

  }

  fVar1 = (float10)fpatan(-(float10)fStack_2c,-(float10)fStack_3c);

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

/* ===== FUN_004a76e0 @ 0x004A76E0 ===== */
/* WARNING: Struct "OBJECT": ignoring multiple overlapping fields */

/* PS2 candidate: playerobj_eval_refpt (conf 0.712) */



void FUN_004a76e0(OBJECT *param_1,int param_2,dword *param_3)



{

  if ((char)param_2 < '\0') {

    FUN_005170f0(param_1);

    return;

  }

  if ((-1 < param_2) && (param_2 < *(int *)&param_1->field_0x2d8)) {

    FUN_005170f0(param_1);

    return;

  }

  *param_3 = param_1->gap_A0;

  param_3[1] = *(dword *)&param_1->field_0xa4;

  param_3[2] = *(dword *)&param_1->field_0xa8;

  return;

}

/* ===== FUN_004a7790 @ 0x004A7790 ===== */
/* PS2 candidate: sound_play_player_noparent (conf 0.524) */



void FUN_004a7790(int param_1)



{

  if (param_1 == DAT_00632a88) {

    FUN_00426570();

  }

  *(undefined4 *)(param_1 + 0x208) = 0;

  *(undefined4 *)(param_1 + 0x20c) = 0;

  return;

}

/* ===== playerobj_zap_movement @ 0x004A77C0 ===== */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

/* WARNING: Struct "OBJECT": ignoring multiple overlapping fields */

/* PS2 candidate: playerobj_zap_movement (conf 0.325) */



void playerobj_zap_movement(OBJECT *obj)



{

  *(dword *)&obj->field_0xac = obj->gap_A0;

  *(undefined4 *)&obj->field_0xb0 = *(undefined4 *)&obj->field_0xa4;

  obj->acc_army_platoon_coordinated = *(dword *)&obj->field_0xa8;

  *(undefined4 *)&obj->field_0x118 = 0;

  *(undefined4 *)&obj->field_0x108 = 0;

  *(undefined4 *)&obj->field_0x11c = 0;

  *(undefined4 *)&obj->field_0x10c = 0;

  *(undefined4 *)&obj->field_0x120 = 0;

  *(undefined4 *)&obj->field_0x110 = 0;

  *(undefined4 *)&obj->field_0x130 = 0;

  *(undefined4 *)&obj->field_0x12c = 0;

  obj->gap_128 = 0;

  obj->acc_TargetCenter = 0;

  obj->acc_TargetCenter = 0;

  obj->acc_army_platoon_base_attack = 0;

  return;

}

/* ===== FUN_004a7be0 @ 0x004A7BE0 ===== */
char FUN_004a7be0(void)



{

  char cVar1;

  float10 extraout_ST0;

  

  cVar1 = __ftol();

  if ((cVar1 == '\0') && (extraout_ST0 != (float10)0.0)) {

    if (extraout_ST0 < (float10)0.0) {

      return -1;

    }

    return '\x01';

  }

  return cVar1;

}

/* ===== FUN_004a7cb0 @ 0x004A7CB0 ===== */
char FUN_004a7cb0(void)



{

  char cVar1;

  float10 extraout_ST0;

  

  cVar1 = __ftol();

  if ((cVar1 == '\0') && (extraout_ST0 != (float10)0.0)) {

    if ((float10)0.0 <= extraout_ST0) {

      return '\x01';

    }

    return -1;

  }

  return cVar1;

}

/* ===== FUN_004a7d70 @ 0x004A7D70 ===== */
char FUN_004a7d70(float param_1)



{

  char cVar1;

  

  if (param_1 <= 1.0) {

    if (param_1 < -1.0) {

      param_1 = -1.0;

    }

  }

  else {

    param_1 = 1.0;

  }

  cVar1 = __ftol();

  if (cVar1 == '\0') {

    if (param_1 != 0.0) {

      if (param_1 < 0.0) {

        return -1;

      }

      return '\x01';

    }

  }

  return cVar1;

}

/* ===== FUN_004a7df0 @ 0x004A7DF0 ===== */
void FUN_004a7df0(float *param_1,float param_2,undefined4 param_3)



{

  float *pfVar1;

  float *pfVar2;

  

  pfVar2 = param_1;

  pfVar1 = param_1 + 1;

  FUN_0050ae40(param_2,param_1,pfVar1);

  *pfVar1 = -*pfVar1;

  FUN_0050ae40(param_3,&param_2,&param_1);

  pfVar2[2] = param_2;

  *pfVar2 = (float)param_1 * *pfVar2;

  pfVar2[3] = 0.0;

  *pfVar1 = (float)param_1 * *pfVar1;

  return;

}

/* ===== MeccProcAnimsCreate @ 0x004A8CC0 ===== */
void MeccProcAnimsCreate(undefined4 *param_1)



{

  ProcAnimsCreate__FP9ObjectSetP9UsrAnmDef(param_1,&PTR_s_arm_r_0055ebb8);

  return;

}

/* ===== MeccProcAnimsCreate_2 @ 0x004A8CE0 ===== */
void MeccProcAnimsCreate_2(undefined4 *param_1)



{

  ProcAnimsCreate__FP9ObjectSetP9UsrAnmDef(param_1,&PTR_s_center_0055f0e8);

  return;

}

/* ===== MeccProcAnimsCreate_3 @ 0x004A8D00 ===== */
void MeccProcAnimsCreate_3(undefined4 *param_1)



{

  ProcAnimsCreate__FP9ObjectSetP9UsrAnmDef(param_1,&PTR_s_seatbone_0055f170);

  return;

}

/* ===== MeccProcAnimsCreate_4 @ 0x004A8D20 ===== */
void MeccProcAnimsCreate_4(undefined4 *param_1)



{

  ProcAnimsCreate__FP9ObjectSetP9UsrAnmDef(param_1,&PTR_s_center_0055f1f0);

  return;

}

/* ===== main/procanim_004a8d40 @ 0x004A8D40 ===== */
void main_procanim_004a8d40(int param_1)



{

  int iVar1;

  undefined4 uVar2;

  undefined4 *puVar3;

  int iVar4;

  undefined4 *puVar5;

  undefined4 local_34;

  undefined4 local_30;

  undefined4 local_2c;

  undefined4 local_28;

  undefined4 local_24;

  undefined1 *local_20;

  undefined4 local_1c;

  undefined4 local_18;

  undefined4 *local_14;

  undefined4 local_10;

  undefined4 local_c;

  undefined4 local_8;

  undefined4 local_4;

  

  puVar3 = &local_34;

  local_30 = DAT_0055f508;

  local_24 = 1;

  local_18 = 1;

  local_10 = 1;

  local_34 = DAT_0055f504;

  local_8 = 0;

  local_4 = 0;

  local_2c = DAT_0055f4fc;

  local_28 = DAT_0055f500;

  local_20 = (undefined1 *)&local_34;

  local_1c = 0;

  local_14 = &local_2c;

  local_c = 0;

  if ((param_1 != 0) && (&stack0x00000000 != (undefined1 *)0x34)) {

    puVar5 = &local_1c;

    do {

      iVar1 = *(int *)(param_1 + 8 + puVar5[-2] * 4);

      if (((iVar1 != 0) &&

          (iVar4 = FUN_0053be00(*(undefined4 *)(iVar1 + 0x28),0,puVar3), iVar4 != 0)) &&

         (*(int *)(iVar4 + 0x18) == 0)) {

        *(uint *)(iVar1 + 8) = *(uint *)(iVar1 + 8) | 2;

        *(uint *)(iVar4 + 8) = *(uint *)(iVar4 + 8) | 0x20;

        uVar2 = *puVar5;

        *(undefined1 **)(iVar4 + 0x18) = &LAB_004a8390;

        *(undefined4 *)(iVar4 + 0x1c) = uVar2;

      }

      puVar3 = (undefined4 *)puVar5[2];

      puVar5 = puVar5 + 3;

    } while (puVar3 != (undefined4 *)0x0);

  }

  return;

}

/* ===== FUN_004a8f50 @ 0x004A8F50 ===== */
/* PS2 candidate: PROJ_DefGet (conf 0.51) */



undefined4 * FUN_004a8f50(int param_1)



{

  if ((-1 < param_1) && (param_1 < 0x35)) {

    return &DAT_005a2588 + param_1 * 0x55;

  }

  return (undefined4 *)0x0;

}

/* ===== FUN_004a8f70 @ 0x004A8F70 ===== */
undefined * FUN_004a8f70(int param_1)



{

  if ((-2 < param_1) && (param_1 < 0x4b)) {

    return &DAT_005a0f44 + param_1 * 0x4c;

  }

  return (undefined *)0x0;

}

/* ===== FUN_004a8f90 @ 0x004A8F90 ===== */
undefined4 FUN_004a8f90(int param_1)



{

  if (((-2 < param_1) && (param_1 < 0x4b)) &&

     ((undefined4 *)(&DAT_005a0f44 + param_1 * 0x4c) != (undefined4 *)0x0)) {

    return *(undefined4 *)(&DAT_005a0f44 + param_1 * 0x4c);

  }

  return 0;

}

/* ===== FUN_004a8fb0 @ 0x004A8FB0 ===== */
/* PS2 candidate: IconDefWieldType (conf 0.53) */



undefined4 FUN_004a8fb0(int param_1,int param_2)



{

  if (((-2 < param_1) && (param_1 < 0x4b)) && (param_1 = param_1 * 0x4c, param_1 != -0x5a0f44)) {

    if (param_2 != 0) {

      return *(undefined4 *)(&DAT_005a0f48 + param_1);

    }

    return *(undefined4 *)(&DAT_005a0f4c + param_1);

  }

  return 0;

}

/* ===== FUN_004a8fe0 @ 0x004A8FE0 ===== */
undefined4 FUN_004a8fe0(int param_1)



{

  if (((-2 < param_1) && (param_1 < 0x4b)) && (param_1 * 0x4c != -0x5a0f44)) {

    return *(undefined4 *)(&DAT_005a0f50 + param_1 * 0x4c);

  }

  return 0xffffffff;

}

/* ===== FUN_004a9010 @ 0x004A9010 ===== */
/* PS2 candidate: IconDefAmmoIcon (conf 0.534) */



undefined4 FUN_004a9010(int param_1)



{

  if (((-2 < param_1) && (param_1 < 0x4b)) && (param_1 * 0x4c != -0x5a0f44)) {

    return *(undefined4 *)(&DAT_005a0f54 + param_1 * 0x4c);

  }

  return 0xffffffff;

}

/* ===== FUN_004a9040 @ 0x004A9040 ===== */
/* PS2 candidate: IconDefProjectile (conf 0.507) */



undefined4 FUN_004a9040(int param_1)



{

  if (((-2 < param_1) && (param_1 < 0x4b)) && (param_1 * 0x4c != -0x5a0f44)) {

    return *(undefined4 *)(&DAT_005a0f58 + param_1 * 0x4c);

  }

  return 0xffffffff;

}

/* ===== FUN_004a9070 @ 0x004A9070 ===== */
/* PS2 candidate: IconDefMaxAmmo (conf 0.443) */



undefined4 FUN_004a9070(int param_1)



{

  if (((-2 < param_1) && (param_1 < 0x4b)) && (param_1 * 0x4c != -0x5a0f44)) {

    return *(undefined4 *)(&DAT_005a0f60 + param_1 * 0x4c);

  }

  return 0xffffffff;

}

/* ===== FUN_004a90a0 @ 0x004A90A0 ===== */
/* PS2 candidate: IconDefGiveAmmo (conf 0.454) */



undefined4 FUN_004a90a0(int param_1)



{

  if (((-2 < param_1) && (param_1 < 0x4b)) && (param_1 * 0x4c != -0x5a0f44)) {

    return *(undefined4 *)(&DAT_005a0f64 + param_1 * 0x4c);

  }

  return 0xffffffff;

}

/* ===== FUN_004a90d0 @ 0x004A90D0 ===== */
undefined4 FUN_004a90d0(int param_1)



{

  if (((-2 < param_1) && (param_1 < 0x4b)) && (param_1 * 0x4c != -0x5a0f44)) {

    return *(undefined4 *)(&DAT_005a0f68 + param_1 * 0x4c);

  }

  return 0xffffffff;

}

/* ===== FUN_004a9100 @ 0x004A9100 ===== */
undefined4 FUN_004a9100(int param_1)



{

  if (((-2 < param_1) && (param_1 < 0x4b)) && (param_1 * 0x4c != -0x5a0f44)) {

    return *(undefined4 *)(&DAT_005a0f6c + param_1 * 0x4c);

  }

  return 0xffffffff;

}

/* ===== FUN_004a9130 @ 0x004A9130 ===== */
/* PS2 candidate: IconDefTextDescription (conf 0.6) */



undefined4 FUN_004a9130(int param_1)



{

  undefined4 uVar1;

  

  if ((((-2 < param_1) && (param_1 < 0x4b)) && (param_1 * 0x4c != -0x5a0f44)) &&

     ((&DAT_005a0f70)[param_1 * 0x4c] != '\0')) {

    uVar1 = FUN_00507b00();

    return uVar1;

  }

  return 0;

}

/* ===== projectile_define @ 0x004A9160 ===== */
/* PS2 candidate: reset__9mus_Piece (conf 0.436) */



undefined4 * projectile_define(int param_1,undefined4 *param_2)



{

  undefined4 uVar1;

  char cVar2;

  char *pcVar3;

  uint uVar4;

  undefined4 *puVar5;

  int iVar6;

  undefined4 *puVar7;

  undefined4 *puVar8;

  char *pcVar9;

  undefined4 *local_4;

  

  puVar5 = (undefined4 *)0x0;

  local_4 = (undefined4 *)0x0;

LAB_004a9173:

  switch(*param_2) {

  case 0:

    return param_2;

  case 1:

    puVar5 = (undefined4 *)0x0;

    if ((int)param_2[2] < 0x35) {

      puVar5 = &DAT_005a2588 + param_2[2] * 0x55;

      puVar7 = &DAT_0055f528;

      puVar8 = puVar5;

      for (iVar6 = 0x55; iVar6 != 0; iVar6 = iVar6 + -1) {

        *puVar8 = *puVar7;

        puVar7 = puVar7 + 1;

        puVar8 = puVar8 + 1;

      }

      param_2 = param_2 + param_2[1];

      goto LAB_004a9173;

    }

    break;

  case 2:

    puVar5 = (undefined4 *)0x0;

    param_2 = param_2 + param_2[1];

    goto LAB_004a9173;

  case 3:

    if (puVar5 != (undefined4 *)0x0) {

      *puVar5 = param_2[2];

      param_2 = param_2 + param_2[1];

      goto LAB_004a9173;

    }

    break;

  case 4:

    if (puVar5 != (undefined4 *)0x0) {

      puVar5[1] = puVar5[1] | param_2[2];

      param_2 = param_2 + param_2[1];

      goto LAB_004a9173;

    }

    break;

  case 5:

    if (puVar5 != (undefined4 *)0x0) {

      puVar5[3] = param_2[2];

      param_2 = param_2 + param_2[1];

      goto LAB_004a9173;

    }

    break;

  case 6:

    if (puVar5 != (undefined4 *)0x0) {

      puVar5[4] = param_2[2];

      param_2 = param_2 + param_2[1];

      goto LAB_004a9173;

    }

    break;

  case 7:

    if (puVar5 != (undefined4 *)0x0) {

      uVar1 = param_2[2];

      puVar5[8] = uVar1;

      puVar5[7] = uVar1;

      puVar5[6] = uVar1;

      param_2 = param_2 + param_2[1];

      goto LAB_004a9173;

    }

    break;

  case 8:

    if (puVar5 != (undefined4 *)0x0) {

      puVar5[10] = param_2[2];

      param_2 = param_2 + param_2[1];

      goto LAB_004a9173;

    }

    break;

  case 9:

    if (puVar5 != (undefined4 *)0x0) {

      puVar5[0xc] = param_2[2];

      puVar5[0xd] = param_2[3];

      puVar5[0xe] = param_2[4];

      puVar5[0xf] = param_2[5];

      if (puVar5 == (undefined4 *)&DAT_005a6548) {

        uRam005a657c = 0;

        uRam005a6578 = 0x43c80000;

        uRam005a6580 = 0x43480000;

        uRam005a6584 = 0x42f00000;

        param_2 = param_2 + param_2[1];

        goto LAB_004a9173;

      }

      if (puVar5 == (undefined4 *)&DAT_005a5800) {

        uRam005a5834 = 0;

        uRam005a5830 = 0x42a00000;

        uRam005a5838 = 0x41f00000;

        uRam005a583c = 0x428c0000;

        param_2 = param_2 + param_2[1];

        goto LAB_004a9173;

      }

      if (puVar5 == (undefined4 *)&DAT_005a3974) {

        uRam005a39a8 = 0;

        uRam005a39a4 = 0x42c80000;

        uRam005a39ac = 0x41f00000;

        uRam005a39b0 = 0x42700000;

        param_2 = param_2 + param_2[1];

        goto LAB_004a9173;

      }

      if (puVar5 == (undefined4 *)&DAT_005a6a98) {

        uRam005a6acc = 0;

        uRam005a6ac8 = 0x41f00000;

        uRam005a6ad0 = 0x41200000;

        uRam005a6ad4 = 0x42200000;

        param_2 = param_2 + param_2[1];

        goto LAB_004a9173;

      }

      if (puVar5 == (undefined4 *)&DAT_005a3578) {

        uRam005a35ac = 0;

        uRam005a35a8 = 0x44960000;

        uRam005a35b0 = 0x43960000;

        uRam005a35b4 = 0x42f00000;

        param_2 = param_2 + param_2[1];

        goto LAB_004a9173;

      }

    }

    break;

  case 10:

    if (puVar5 != (undefined4 *)0x0) {

      puVar5[0x10] = param_2[2];

      if (puVar5 == (undefined4 *)&DAT_005a6548) {

        uRam005a6588 = 0x43c80000;

        param_2 = param_2 + param_2[1];

        goto LAB_004a9173;

      }

      if (puVar5 == (undefined4 *)&DAT_005a5800) {

        uRam005a5840 = 0x42a00000;

        param_2 = param_2 + param_2[1];

        goto LAB_004a9173;

      }

      if (puVar5 == (undefined4 *)&DAT_005a3974) {

        uRam005a39b4 = 0x42c80000;

        param_2 = param_2 + param_2[1];

        goto LAB_004a9173;

      }

      if (puVar5 == (undefined4 *)&DAT_005a6a98) {

        uRam005a6ad8 = 0x41f00000;

        param_2 = param_2 + param_2[1];

        goto LAB_004a9173;

      }

      if (puVar5 == (undefined4 *)&DAT_005a3578) {

        uRam005a35b8 = 0x44960000;

        param_2 = param_2 + param_2[1];

        goto LAB_004a9173;

      }

      if (puVar5 == (undefined4 *)&DAT_005a3ac8) {

        uRam005a3b08 = 0x41c00000;

        param_2 = param_2 + param_2[1];

        goto LAB_004a9173;

      }

      if (puVar5 == (undefined4 *)&DAT_005a4568) {

        uRam005a45a8 = 0x42200000;

        param_2 = param_2 + param_2[1];

        goto LAB_004a9173;

      }

    }

    break;

  case 0xd:

    if (puVar5 != (undefined4 *)0x0) {

      puVar5[0x11] = param_2[2];

      if (puVar5 == (undefined4 *)&DAT_005a3ac8) {

        uRam005a3b0c = 0x3ecccccd;

        param_2 = param_2 + param_2[1];

        goto LAB_004a9173;

      }

      if (puVar5 == (undefined4 *)&DAT_005a4568) {

        uRam005a45ac = 0x3ecccccd;

        param_2 = param_2 + param_2[1];

        goto LAB_004a9173;

      }

    }

    break;

  case 0xe:

    if (puVar5 != (undefined4 *)0x0) {

      puVar5[0x15] = param_2[2];

      param_2 = param_2 + param_2[1];

      goto LAB_004a9173;

    }

    break;

  case 0xf:

    if (puVar5 != (undefined4 *)0x0) {

      puVar5[0x16] = param_2[2];

      param_2 = param_2 + param_2[1];

      goto LAB_004a9173;

    }

    break;

  case 0x10:

    if (puVar5 != (undefined4 *)0x0) {

      puVar5[0x17] = param_2[2];

      param_2 = param_2 + param_2[1];

      goto LAB_004a9173;

    }

    break;

  case 0x11:

    if (puVar5 != (undefined4 *)0x0) {

      puVar5[0x19] = param_2[2];

      param_2 = param_2 + param_2[1];

      goto LAB_004a9173;

    }

    break;

  case 0x12:

    if (puVar5 != (undefined4 *)0x0) {

      puVar5[0x1a] = param_2[2];

      param_2 = param_2 + param_2[1];

      goto LAB_004a9173;

    }

    break;

  case 0x13:

    if (puVar5 != (undefined4 *)0x0) {

      puVar5[0x1b] = param_2[2];

      param_2 = param_2 + param_2[1];

      goto LAB_004a9173;

    }

    break;

  case 0x14:

    if (puVar5 != (undefined4 *)0x0) {

      puVar5[0x1c] = param_2[2];

      param_2 = param_2 + param_2[1];

      goto LAB_004a9173;

    }

    break;

  case 0x15:

    if (puVar5 != (undefined4 *)0x0) {

      puVar5[0x1d] = param_2[2];

      param_2 = param_2 + param_2[1];

      goto LAB_004a9173;

    }

    break;

  case 0x16:

    if (puVar5 != (undefined4 *)0x0) {

      if (param_2[2] == 0) {

        pcVar3 = (char *)0x0;

      }

      else {

        pcVar3 = (char *)(param_2[2] + param_1);

      }

      puVar7 = puVar5 + 0x1e;

      if (pcVar3 == (char *)0x0) {

        *(undefined1 *)puVar7 = 0;

      }

      else {

        uVar4 = 0xffffffff;

        pcVar9 = pcVar3;

        do {

          if (uVar4 == 0) break;

          uVar4 = uVar4 - 1;

          cVar2 = *pcVar9;

          pcVar9 = pcVar9 + 1;

        } while (cVar2 != '\0');

        if (~uVar4 - 1 < 0x20) {

          iVar6 = (int)puVar7 - (int)pcVar3;

          do {

            cVar2 = *pcVar3;

            pcVar3[iVar6] = cVar2;

            pcVar3 = pcVar3 + 1;

          } while (cVar2 != '\0');

        }

        else {

          *(undefined1 *)puVar7 = 0;

          FUN_0051ea20(s_Error__fx_name_too_long_for_proj_0055fc9c);

        }

      }

      if (puVar5 == (undefined4 *)&DAT_005a52b0) {

        uRam005a5348._0_1_ = s_fx_spell_2_0055fd14[0];

        uRam005a5348._1_1_ = s_fx_spell_2_0055fd14[1];

        uRam005a5348._2_1_ = s_fx_spell_2_0055fd14[2];

        uRam005a5348._3_1_ = s_fx_spell_2_0055fd14[3];

        uRam005a534c._0_1_ = s_fx_spell_2_0055fd14[4];

        uRam005a534c._1_1_ = s_fx_spell_2_0055fd14[5];

        uRam005a534c._2_1_ = s_fx_spell_2_0055fd14[6];

        uRam005a534c._3_1_ = s_fx_spell_2_0055fd14[7];

        uRam005a5350._0_1_ = s_fx_spell_2_0055fd14[8];

        uRam005a5350._1_1_ = s_fx_spell_2_0055fd14[9];

        cRam005a5352 = s_fx_spell_2_0055fd14[10];

        uRam005a5368._0_1_ = s_fx_spell_2_0055fd14[0];

        uRam005a5368._1_1_ = s_fx_spell_2_0055fd14[1];

        uRam005a5368._2_1_ = s_fx_spell_2_0055fd14[2];

        uRam005a5368._3_1_ = s_fx_spell_2_0055fd14[3];

        uRam005a536c._0_1_ = s_fx_spell_2_0055fd14[4];

        uRam005a536c._1_1_ = s_fx_spell_2_0055fd14[5];

        uRam005a536c._2_1_ = s_fx_spell_2_0055fd14[6];

        uRam005a536c._3_1_ = s_fx_spell_2_0055fd14[7];

        uRam005a5370._0_1_ = s_fx_spell_2_0055fd14[8];

        uRam005a5370._1_1_ = s_fx_spell_2_0055fd14[9];

        cRam005a5372 = s_fx_spell_2_0055fd14[10];

        param_2 = param_2 + param_2[1];

        goto LAB_004a9173;

      }

    }

    break;

  case 0x17:

    if (puVar5 != (undefined4 *)0x0) {

      if (param_2[2] == 0) {

        pcVar3 = (char *)0x0;

      }

      else {

        pcVar3 = (char *)(param_1 + param_2[2]);

      }

      puVar7 = puVar5 + 0x26;

      if (pcVar3 == (char *)0x0) {

LAB_004a9cac:

        *(undefined1 *)puVar7 = 0;

        param_2 = param_2 + param_2[1];

      }

      else {

        uVar4 = 0xffffffff;

        pcVar9 = pcVar3;

        do {

          if (uVar4 == 0) break;

          uVar4 = uVar4 - 1;

          cVar2 = *pcVar9;

          pcVar9 = pcVar9 + 1;

        } while (cVar2 != '\0');

        if (~uVar4 - 1 < 0x20) {

          iVar6 = (int)puVar7 - (int)pcVar3;

          do {

            cVar2 = *pcVar3;

            pcVar3[iVar6] = cVar2;

            pcVar3 = pcVar3 + 1;

          } while (cVar2 != '\0');

          param_2 = param_2 + param_2[1];

        }

        else {

LAB_004a991b:

          *(undefined1 *)puVar7 = 0;

          FUN_0051ea20(s_Error__fx_name_too_long_for_proj_0055fc9c);

          param_2 = param_2 + param_2[1];

        }

      }

      goto LAB_004a9173;

    }

    break;

  case 0x18:

    if (puVar5 != (undefined4 *)0x0) {

      puVar5[0xb] = param_2[2];

      param_2 = param_2 + param_2[1];

      goto LAB_004a9173;

    }

    break;

  case 0x19:

    if (puVar5 != (undefined4 *)0x0) {

      puVar5[0x48] = param_2[2];

      param_2 = param_2 + param_2[1];

      goto LAB_004a9173;

    }

    break;

  case 0x1a:

    if (puVar5 != (undefined4 *)0x0) {

      puVar5[0x49] = param_2[2];

      param_2 = param_2 + param_2[1];

      goto LAB_004a9173;

    }

    break;

  case 0x1b:

    if (puVar5 != (undefined4 *)0x0) {

      puVar5[0x4a] = param_2[2];

      param_2 = param_2 + param_2[1];

      goto LAB_004a9173;

    }

    break;

  case 0x1c:

    if (puVar5 != (undefined4 *)0x0) {

      puVar5[0x4b] = param_2[2];

      param_2 = param_2 + param_2[1];

      goto LAB_004a9173;

    }

    break;

  case 0x1d:

    if (puVar5 != (undefined4 *)0x0) {

      if (param_2[2] == 0) {

        pcVar3 = (char *)0x0;

      }

      else {

        pcVar3 = (char *)(param_1 + param_2[2]);

      }

      puVar7 = puVar5 + 0x36;

      if (pcVar3 == (char *)0x0) goto LAB_004a9cac;

      uVar4 = 0xffffffff;

      pcVar9 = pcVar3;

      do {

        if (uVar4 == 0) break;

        uVar4 = uVar4 - 1;

        cVar2 = *pcVar9;

        pcVar9 = pcVar9 + 1;

      } while (cVar2 != '\0');

      if (0x1f < ~uVar4 - 1) goto LAB_004a991b;

      iVar6 = (int)puVar7 - (int)pcVar3;

      do {

        cVar2 = *pcVar3;

        pcVar3[iVar6] = cVar2;

        pcVar3 = pcVar3 + 1;

      } while (cVar2 != '\0');

      param_2 = param_2 + param_2[1];

      goto LAB_004a9173;

    }

    break;

  case 0x1e:

    if (puVar5 != (undefined4 *)0x0) {

      puVar5[9] = param_2[2];

      param_2 = param_2 + param_2[1];

      goto LAB_004a9173;

    }

    break;

  case 0x1f:

    if (puVar5 != (undefined4 *)0x0) {

      puVar5[6] = param_2[2];

      param_2 = param_2 + param_2[1];

      goto LAB_004a9173;

    }

    break;

  case 0x20:

    if (puVar5 != (undefined4 *)0x0) {

      puVar5[7] = param_2[2];

      param_2 = param_2 + param_2[1];

      goto LAB_004a9173;

    }

    break;

  case 0x21:

    if (puVar5 != (undefined4 *)0x0) {

      puVar5[8] = param_2[2];

      param_2 = param_2 + param_2[1];

      goto LAB_004a9173;

    }

    break;

  case 0x22:

    if (puVar5 != (undefined4 *)0x0) {

      puVar5[2] = param_2[2];

      param_2 = param_2 + param_2[1];

      goto LAB_004a9173;

    }

    break;

  case 0x23:

    if (puVar5 != (undefined4 *)0x0) {

      puVar5[0x18] = param_2[2];

      param_2 = param_2 + param_2[1];

      goto LAB_004a9173;

    }

    break;

  case 0x24:

    iVar6 = param_2[2];

    local_4 = (undefined4 *)0x0;

    if ((-2 < iVar6) && (iVar6 < 0x4b)) {

      local_4 = (undefined4 *)(&DAT_005a0f44 + iVar6 * 0x4c);

      puVar7 = &DAT_0055f680;

      puVar8 = local_4;

      for (iVar6 = 0x13; iVar6 != 0; iVar6 = iVar6 + -1) {

        *puVar8 = *puVar7;

        puVar7 = puVar7 + 1;

        puVar8 = puVar8 + 1;

      }

      param_2 = param_2 + param_2[1];

      goto LAB_004a9173;

    }

    break;

  case 0x25:

    local_4 = (undefined4 *)0x0;

    param_2 = param_2 + param_2[1];

    goto LAB_004a9173;

  case 0x26:

    if (local_4 != (undefined4 *)0x0) {

      *local_4 = param_2[2];

      param_2 = param_2 + param_2[1];

      goto LAB_004a9173;

    }

    break;

  case 0x27:

    if (local_4 != (undefined4 *)0x0) {

      local_4[1] = param_2[2];

      param_2 = param_2 + param_2[1];

      goto LAB_004a9173;

    }

    break;

  case 0x28:

    if (local_4 != (undefined4 *)0x0) {

      local_4[2] = param_2[2];

      param_2 = param_2 + param_2[1];

      goto LAB_004a9173;

    }

    break;

  case 0x29:

    if (local_4 != (undefined4 *)0x0) {

      local_4[3] = param_2[2];

      param_2 = param_2 + param_2[1];

      goto LAB_004a9173;

    }

    break;

  case 0x2a:

    if (local_4 != (undefined4 *)0x0) {

      local_4[4] = param_2[2];

      param_2 = param_2 + param_2[1];

      goto LAB_004a9173;

    }

    break;

  case 0x2b:

    if (local_4 != (undefined4 *)0x0) {

      local_4[5] = param_2[2];

      param_2 = param_2 + param_2[1];

      goto LAB_004a9173;

    }

    break;

  case 0x2c:

    if (local_4 != (undefined4 *)0x0) {

      local_4[6] = param_2[2];

      param_2 = param_2 + param_2[1];

      goto LAB_004a9173;

    }

    break;

  case 0x2d:

    if (local_4 != (undefined4 *)0x0) {

      local_4[7] = param_2[2];

      param_2 = param_2 + param_2[1];

      goto LAB_004a9173;

    }

    break;

  case 0x2e:

    if (local_4 != (undefined4 *)0x0) {

      local_4[8] = param_2[2];

      param_2 = param_2 + param_2[1];

      goto LAB_004a9173;

    }

    break;

  case 0x2f:

    if (local_4 != (undefined4 *)0x0) {

      local_4[9] = param_2[2];

      param_2 = param_2 + param_2[1];

      goto LAB_004a9173;

    }

    break;

  case 0x30:

    if (local_4 != (undefined4 *)0x0) {

      if (param_2[2] == 0) {

        pcVar3 = (char *)0x0;

      }

      else {

        pcVar3 = (char *)(param_2[2] + param_1);

      }

      puVar7 = local_4 + 0xb;

      if (pcVar3 == (char *)0x0) goto LAB_004a9cac;

      uVar4 = 0xffffffff;

      pcVar9 = pcVar3;

      do {

        if (uVar4 == 0) break;

        uVar4 = uVar4 - 1;

        cVar2 = *pcVar9;

        pcVar9 = pcVar9 + 1;

      } while (cVar2 != '\0');

      if (~uVar4 - 1 < 0x20) {

        iVar6 = (int)puVar7 - (int)pcVar3;

        do {

          cVar2 = *pcVar3;

          pcVar3[iVar6] = cVar2;

          pcVar3 = pcVar3 + 1;

        } while (cVar2 != '\0');

        param_2 = param_2 + param_2[1];

      }

      else {

        *(undefined1 *)puVar7 = 0;

        FUN_0051ea20(s_Error__icon_description_index_na_0055fcd0);

        param_2 = param_2 + param_2[1];

      }

      goto LAB_004a9173;

    }

    break;

  case 0x31:

    if (puVar5 != (undefined4 *)0x0) {

      if (param_2[2] == 0) {

        pcVar3 = (char *)0x0;

      }

      else {

        pcVar3 = (char *)(param_2[2] + param_1);

      }

      puVar7 = puVar5 + 0x3e;

      if (pcVar3 == (char *)0x0) goto LAB_004a9cac;

      uVar4 = 0xffffffff;

      pcVar9 = pcVar3;

      do {

        if (uVar4 == 0) break;

        uVar4 = uVar4 - 1;

        cVar2 = *pcVar9;

        pcVar9 = pcVar9 + 1;

      } while (cVar2 != '\0');

      if (0x1f < ~uVar4 - 1) goto LAB_004a991b;

      iVar6 = (int)puVar7 - (int)pcVar3;

      do {

        cVar2 = *pcVar3;

        pcVar3[iVar6] = cVar2;

        pcVar3 = pcVar3 + 1;

      } while (cVar2 != '\0');

      param_2 = param_2 + param_2[1];

      goto LAB_004a9173;

    }

    break;

  case 0x32:

    if (puVar5 != (undefined4 *)0x0) {

      puVar5[5] = param_2[2];

      param_2 = param_2 + param_2[1];

      goto LAB_004a9173;

    }

    break;

  case 0x33:

    if (puVar5 != (undefined4 *)0x0) {

      puVar5[0x14] = param_2[2];

      param_2 = param_2 + param_2[1];

      goto LAB_004a9173;

    }

    break;

  case 0x35:

    if (puVar5 != (undefined4 *)0x0) {

      if (param_2[2] == 0) {

        pcVar3 = (char *)0x0;

      }

      else {

        pcVar3 = (char *)(param_2[2] + param_1);

      }

      puVar7 = puVar5 + 0x2e;

      if (pcVar3 == (char *)0x0) goto LAB_004a9cac;

      uVar4 = 0xffffffff;

      pcVar9 = pcVar3;

      do {

        if (uVar4 == 0) break;

        uVar4 = uVar4 - 1;

        cVar2 = *pcVar9;

        pcVar9 = pcVar9 + 1;

      } while (cVar2 != '\0');

      if (0x1f < ~uVar4 - 1) goto LAB_004a991b;

      iVar6 = (int)puVar7 - (int)pcVar3;

      do {

        cVar2 = *pcVar3;

        pcVar3[iVar6] = cVar2;

        pcVar3 = pcVar3 + 1;

      } while (cVar2 != '\0');

      param_2 = param_2 + param_2[1];

      goto LAB_004a9173;

    }

    break;

  case 0x36:

    if (local_4 != (undefined4 *)0x0) {

      local_4[10] = param_2[2];

      param_2 = param_2 + param_2[1];

      goto LAB_004a9173;

    }

    break;

  case 0x37:

    if (puVar5 != (undefined4 *)0x0) {

      puVar5[0x13] = param_2[2];

    }

    break;

  case 0x38:

    if (puVar5 != (undefined4 *)0x0) {

      puVar5[0x46] = param_2[2];

      puVar5[0x47] = param_2[3];

      param_2 = param_2 + param_2[1];

      goto LAB_004a9173;

    }

    break;

  case 0x39:

    if (puVar5 != (undefined4 *)0x0) {

      puVar5[10] = 0x4479c000;

      puVar5[1] = puVar5[1] | 0x20000;

      param_2 = param_2 + param_2[1];

      goto LAB_004a9173;

    }

    break;

  case 0x3a:

    if (puVar5 == (undefined4 *)0x0) break;

    if (param_2[2] == 0) {

      pcVar3 = (char *)0x0;

    }

    else {

      pcVar3 = (char *)(param_2[2] + param_1);

    }

    puVar7 = puVar5 + 0x4c;

    if (pcVar3 == (char *)0x0) {

      *(undefined1 *)puVar7 = 0;

      puVar5[0x54] = param_2[3];

      param_2 = param_2 + param_2[1];

    }

    else {

      uVar4 = 0xffffffff;

      pcVar9 = pcVar3;

      do {

        if (uVar4 == 0) break;

        uVar4 = uVar4 - 1;

        cVar2 = *pcVar9;

        pcVar9 = pcVar9 + 1;

      } while (cVar2 != '\0');

      if (~uVar4 - 1 < 0x20) {

        iVar6 = (int)puVar7 - (int)pcVar3;

        do {

          cVar2 = *pcVar3;

          pcVar3[iVar6] = cVar2;

          pcVar3 = pcVar3 + 1;

        } while (cVar2 != '\0');

        puVar5[0x54] = param_2[3];

        param_2 = param_2 + param_2[1];

      }

      else {

        *(undefined1 *)puVar7 = 0;

        FUN_0051ea20(s_Error__fx_name_too_long_for_proj_0055fc9c);

        puVar5[0x54] = param_2[3];

        param_2 = param_2 + param_2[1];

      }

    }

    goto LAB_004a9173;

  }

  param_2 = param_2 + param_2[1];

  goto LAB_004a9173;

}

/* ===== weapondefs_load @ 0x004A9E10 ===== */
/* PS2 candidate: mussys_loadScore__FP9mus_Score (conf 0.511) */



void weapondefs_load(void)



{

  int iVar1;

  undefined4 *puVar2;

  int *piVar3;

  int iVar4;

  undefined4 *puVar5;

  undefined4 local_8;

  size_t local_4;

  

  iVar1 = main_005380e0(s_weapondefs_bin_0055fd48);

  if (iVar1 == 0) {

    FUN_0051ea20(s_Error__Can_t_load_the_projectile_0055fd20);

    return;

  }

  FUN_005178d0(iVar1,&local_8,8);

  puVar2 = _malloc(local_4);

  *puVar2 = local_8;

  puVar2[1] = local_4;

  FUN_005178d0(iVar1,puVar2 + 2,local_4 - 8);

  ANM_BinderDestroy_2(iVar1);

  puVar5 = &DAT_005a2588;

  for (iVar1 = 0x1199; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar5 = 0;

    puVar5 = puVar5 + 1;

  }

  puVar5 = &DAT_005a0ef8;

  for (iVar1 = 0x5a4; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar5 = 0;

    puVar5 = puVar5 + 1;

  }

  projectile_define(puVar2,puVar2 + 2);

  piVar3 = &DAT_005a2588;

  iVar1 = 0;

  iVar4 = 0x1199;

  do {

    iVar1 = iVar1 + *piVar3;

    piVar3 = piVar3 + 1;

    iVar4 = iVar4 + -1;

  } while (iVar4 != 0);

  if (iVar1 == 0x52e3b831) {

    piVar3 = &DAT_005a0ef8;

    iVar1 = 0;

    iVar4 = 0x5a4;

    do {

      iVar1 = iVar1 + *piVar3;

      piVar3 = piVar3 + 1;

      iVar4 = iVar4 + -1;

    } while (iVar4 != 0);

    if (iVar1 == -0x1b2ddecb) goto LAB_004a9ef4;

    piVar3 = &DAT_005a0ef8;

    iVar1 = 0;

    iVar4 = 0x5a4;

    do {

      iVar1 = iVar1 + *piVar3;

      piVar3 = piVar3 + 1;

      iVar4 = iVar4 + -1;

    } while (iVar4 != 0);

    if (iVar1 == -0x1b2de69b) goto LAB_004a9ef4;

  }

  Audio3DTestToneUpdate__Fv_4();

LAB_004a9ef4:

  FUN_005443bf(puVar2);

  return;

}

/* ===== FUN_004a9f30 @ 0x004A9F30 ===== */
void FUN_004a9f30(float *param_1,int param_2)



{

  *param_1 = (*(float *)(param_2 + 0x288) + *(float *)(param_2 + 0x27c)) * 0.5;

  param_1[1] = (*(float *)(param_2 + 0x28c) + *(float *)(param_2 + 0x280)) * 0.5;

  param_1[2] = (*(float *)(param_2 + 0x290) + *(float *)(param_2 + 0x284)) * 0.5;

  return;

}

/* ===== ANM_DumpCluster_2 @ 0x004A9F80 ===== */
void ANM_DumpCluster_2(void)



{

  return;

}

/* ===== FUN_004a9fe0 @ 0x004A9FE0 ===== */
/* PS2 candidate: ObjectGetWorldRefPoint__FP3P3DiP6OBJECT (conf 0.793) */



void FUN_004a9fe0(undefined4 param_1,int param_2)



{

  undefined1 local_c [12];

  

  if (-1 < param_2) {

    FUN_004a76e0(param_1,param_2,local_c);

  }

  return;

}

/* ===== FUN_004aa0b0 @ 0x004AA0B0 ===== */
/* WARNING: Struct "OBJECT": ignoring multiple overlapping fields */

/* PS2 candidate: PROJ_CreateBasic (conf 0.422) */



OBJECT * FUN_004aa0b0(int param_1,dword param_2)



{

  uint *puVar1;

  OBJECT *obj;

  uint *puVar2;

  int iVar3;

  uint *puVar4;

  uint *puVar5;

  

  if ((param_1 < 0) || (0x34 < param_1)) {

    puVar2 = (uint *)0x0;

  }

  else {

    puVar2 = &DAT_005a2588 + param_1 * 0x55;

  }

  obj = (OBJECT *)object_allocate_type_end(*puVar2,0x21);

  object_change_ospec(obj,0x4d);

  obj->field_18C = param_2;

  obj->acc_grenade_do_stopped = obj->acc_grenade_do_stopped | 0x600;

  FUN_004a7440(obj);

  puVar1 = *(uint **)&obj->field_0x100;

  if ((~*puVar1 & 1) != 0) {

    *(uint **)&obj->field_0x104 = puVar1 + 8;

    puVar1[0x6c] = 0xffffffff;

    FUN_004a1740(obj);

    *puVar1 = *puVar1 | 1;

  }

  if ((puVar2[1] & 0x4000) != 0) {

    obj->acc_grenade_do_stopped = obj->acc_grenade_do_stopped | 0x20000;

  }

  puVar1 = *(uint **)&obj->field_0x100;

  if ((~puVar2[1] & 2) != 0) {

    *puVar1 = *puVar1 | 0x20;

  }

  iVar3 = *(int *)&obj->field_0x104;

  *(uint *)(iVar3 + 8) = puVar2[0x15];

  *(uint *)(iVar3 + 4) = puVar2[0x16];

  *(uint *)(iVar3 + 0xc) = puVar2[0x17];

  *(uint *)(iVar3 + 0x10) = puVar2[0x18];

  *(uint *)(iVar3 + 0x30) = puVar2[0x19];

  *(uint *)(iVar3 + 0x34) = puVar2[0x1c];

  if ((char)puVar2[0x1e] != '\0') {

    fx_get_free_effect__Fv();

  }

  if ((param_1 < 0) || (0x34 < param_1)) {

    puVar4 = (uint *)0x0;

  }

  else {

    puVar4 = (uint *)(&DAT_0055f6d0 + param_1 * 0x1c);

  }

  puVar5 = puVar1;

  for (iVar3 = 7; puVar5 = puVar5 + 1, iVar3 != 0; iVar3 = iVar3 + -1) {

    *puVar5 = *puVar4;

    puVar4 = puVar4 + 1;

  }

  puVar4 = puVar1 + 0x17;

  for (iVar3 = 0x55; iVar3 != 0; iVar3 = iVar3 + -1) {

    *puVar4 = *puVar2;

    puVar2 = puVar2 + 1;

    puVar4 = puVar4 + 1;

  }

  *(char *)(puVar1 + 0x79) = (char)param_1;

  puVar2 = (uint *)FUN_00515db0();

  puVar1[0x7b] = *puVar2;

  puVar1[0x7c] = puVar2[1];

  puVar1[0x7d] = puVar2[2];

  return obj;

}

/* ===== FUN_004aa230 @ 0x004AA230 ===== */
/* PS2 candidate: PROJ_Create2 (conf 0.479) */



int FUN_004aa230(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,

                undefined4 param_5,float *param_6)



{

  uint uVar1;

  int iVar2;

  undefined4 uVar3;

  int iVar4;

  int iVar5;

  int *piVar6;

  undefined4 *puVar7;

  float *pfVar8;

  float *pfVar9;

  float10 fVar10;

  undefined4 *puVar11;

  undefined4 uVar12;

  undefined1 *puVar13;

  float local_13c;

  float local_138;

  float local_134;

  int local_130;

  float local_12c;

  int local_128;

  undefined4 local_124;

  undefined4 local_120;

  float local_11c;

  undefined4 local_118;

  undefined4 local_114;

  undefined4 local_110;

  float local_10c;

  float local_108;

  float local_104;

  float local_100 [4];

  undefined4 uStack_f0;

  float fStack_e8;

  undefined4 uStack_e0;

  float fStack_d8;

  undefined4 uStack_d0;

  undefined1 local_bc [16];

  undefined4 local_ac;

  undefined4 local_a8;

  undefined4 local_a4;

  undefined1 local_88 [68];

  undefined1 local_44 [68];

  

  local_118 = 0;

  local_114 = 0;

  local_110 = 0x3f800000;

  iVar2 = FUN_004aa0b0(param_1,param_2);

  if ((param_1 < 0) || (0x34 < param_1)) {

    puVar7 = (undefined4 *)0x0;

  }

  else {

    puVar7 = &DAT_005a2588 + param_1 * 0x55;

  }

  local_130 = *(int *)(iVar2 + 0x100);

  local_128 = *(int *)(iVar2 + 0x104);

  *(undefined4 *)(local_130 + 0x1d0) = param_5;

  FUN_004a76e0(param_3,param_4,&local_13c);

  *(undefined4 *)(iVar2 + 0x210) = param_3;

  if (*(int *)(iVar2 + 0x2d8) < 1) {

    *(undefined4 *)(iVar2 + 0x214) = 0xffffffff;

  }

  else {

    *(undefined4 *)(iVar2 + 0x214) = 0;

  }

  *(undefined4 *)(iVar2 + 0x218) = param_4;

  *(uint *)(iVar2 + 0xdc) = *(uint *)(iVar2 + 0xdc) | 0x9000;

  local_10c = *param_6 - local_13c;

  local_108 = param_6[1] - local_138;

  local_104 = param_6[2] - local_134;

  if ((float)puVar7[0x16] == 0.0) {

    FUN_0053dde0(local_44,&local_13c,&local_10c,&local_118);

    FUN_0053dd40(local_88,0xbfc90fdb);

    (*(code *)PTR_FUN_00580c18)(local_100,local_44,local_88);

    FUN_00499310(iVar2,uStack_f0,uStack_e0,uStack_d0);

    uVar1 = *(uint *)(iVar2 + 0xd8);

    pfVar8 = local_100;

    pfVar9 = (float *)(iVar2 + 0x294);

    for (iVar5 = 0x11; iVar5 != 0; iVar5 = iVar5 + -1) {

      *pfVar9 = *pfVar8;

      pfVar8 = pfVar8 + 1;

      pfVar9 = pfVar9 + 1;

    }

    *(uint *)(iVar2 + 0xd8) = uVar1 | 0x10000;

    *(float *)(iVar2 + 0x128) = -(local_100[2] * (float)puVar7[2]);

    *(float *)(iVar2 + 300) = -(fStack_e8 * (float)puVar7[2]);

    *(float *)(iVar2 + 0x130) = -(fStack_d8 * (float)puVar7[2]);

  }

  else {

    local_124 = 0;

    local_120 = 0;

    local_11c = 0.0;

    FUN_0050a610(&local_13c,param_6);

    fVar10 = (float10)FUN_00543e70();

    local_12c = (float)(fVar10 * (float10)0.1);

    local_11c = (*(float *)(local_128 + 4) / *(float *)(local_128 + 8)) * -32.17405;

    FUN_004a4480(iVar2 + 0x128,&local_13c,param_6,&local_124,local_12c);

    FUN_004993c0(iVar2,&local_13c);

  }

  puVar11 = puVar7 + 0x36;

  if (*(char *)(puVar7 + 0x36) != '\0') {

    puVar13 = local_bc;

    uVar12 = 0x24;

    local_a4 = param_3;

    local_a8 = param_4;

    local_ac = 8;

    uVar3 = fx_get_free_effect__Fv();

    FUN_0044ed20(uVar3,0,puVar11,uVar12,puVar13);

  }

  FUN_0049a1f0(iVar2);

  iVar5 = local_130;

  if ((*(byte *)(puVar7 + 1) & 1) != 0) {

    iVar4 = FUN_004a6160(*(undefined4 *)(local_130 + 0x1d0));

    if (iVar4 != 0) {

      iVar4 = FUN_0047f730(*(undefined4 *)(iVar5 + 0x1d0));

      if ((iVar4 != 0) && (DAT_00632d70 != (int *)0x0)) {

        piVar6 = DAT_00632d70;

        while ((iVar4 = piVar6[3], *(int *)(iVar4 + 0x210) != *(int *)(iVar5 + 0x1d0) ||

               (*(int *)(iVar4 + 4) != 0x3df))) {

          piVar6 = (int *)*piVar6;

          if (piVar6 == (int *)0x0) {

            return iVar2;

          }

        }

        *(int *)(iVar5 + 0x1dc) = iVar4;

      }

    }

  }

  return iVar2;

}

/* ===== FUN_004aa550 @ 0x004AA550 ===== */
/* PS2 candidate: PROJ_Create3 (conf 0.591) */



int FUN_004aa550(int param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,

                undefined4 *param_5,undefined4 param_6)



{

  int iVar1;

  uint uVar2;

  int iVar3;

  int iVar4;

  int *piVar5;

  undefined4 *puVar6;

  undefined4 *puVar7;

  

  iVar3 = FUN_004aa0b0(param_1,param_2);

  *(uint *)(iVar3 + 0x1c8) = *(uint *)(iVar3 + 0x1c8) & 0xfffdffff;

  if ((param_1 < 0) || (0x34 < param_1)) {

    param_2 = (undefined4 *)0x0;

  }

  else {

    param_2 = &DAT_005a2588 + param_1 * 0x55;

  }

  iVar1 = *(int *)(iVar3 + 0x100);

  *(undefined4 *)(iVar1 + 0x1d0) = param_6;

  FUN_00499310(iVar3,param_5[4],param_5[8],param_5[0xc]);

  uVar2 = *(uint *)(iVar3 + 0xd8);

  puVar6 = param_5;

  puVar7 = (undefined4 *)(iVar3 + 0x294);

  for (iVar4 = 0x11; iVar4 != 0; iVar4 = iVar4 + -1) {

    *puVar7 = *puVar6;

    puVar6 = puVar6 + 1;

    puVar7 = puVar7 + 1;

  }

  *(uint *)(iVar3 + 0xd8) = uVar2 | 0x10000;

  *(float *)(iVar3 + 0x128) = -((float)param_5[2] * (float)param_2[2]);

  *(float *)(iVar3 + 300) = -((float)param_5[6] * (float)param_2[2]);

  *(float *)(iVar3 + 0x130) = -((float)param_5[10] * (float)param_2[2]);

  if (*(char *)(param_2 + 0x36) != '\0') {

    fx_get_free_effect__Fv();

  }

  FUN_0049a1f0(iVar3);

  if ((*(byte *)(param_2 + 1) & 1) != 0) {

    iVar4 = FUN_004a6160(*(undefined4 *)(iVar1 + 0x1d0));

    if (iVar4 != 0) {

      iVar4 = FUN_0047f730(*(undefined4 *)(iVar1 + 0x1d0));

      if ((iVar4 != 0) && (DAT_00632d70 != (int *)0x0)) {

        piVar5 = DAT_00632d70;

        while ((iVar4 = piVar5[3], *(int *)(iVar4 + 0x210) != *(int *)(iVar1 + 0x1d0) ||

               (*(int *)(iVar4 + 4) != 0x3df))) {

          piVar5 = (int *)*piVar5;

          if (piVar5 == (int *)0x0) {

            return iVar3;

          }

        }

        *(int *)(iVar1 + 0x1dc) = iVar4;

      }

    }

  }

  return iVar3;

}

/* ===== FUN_004aa6d0 @ 0x004AA6D0 ===== */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

/* WARNING: Struct "OBJECT": ignoring multiple overlapping fields */



bool FUN_004aa6d0(OBJECT *obj)



{

  OBJECT *pOVar1;

  OBJECT *pOVar2;

  int iVar3;

  uint uVar4;

  dword in_stack_00000008;

  

  iVar3 = FUN_004a6220(obj);

  if ((((iVar3 == 0) && (iVar3 = FUN_004a6200(obj), iVar3 == 0)) &&

      (iVar3 = FUN_004a6300(obj), iVar3 == 0)) && (iVar3 = FUN_004a6290(obj), iVar3 == 0)) {

    if (((obj->field_0x1f5 != '\0') ||

        (uVar4 = *(uint *)&obj->field_0xd8 & 0x4000c000,

        (~obj->acc_grenade_do_stopped >> 0x11 & 1) != 0 || uVar4 != 0)) ||

       ((uVar4 != 0 || (*(float *)&obj->field_0x1c0 <= (float)obj->field_278)))) {

      return false;

    }

  }

  else if ((~obj->acc_grenade_do_stopped >> 0x11 & 1) != 0 ||

           (*(uint *)&obj->field_0xd8 & 0x4000c000) != 0) {

    return false;

  }

  pOVar2 = *(OBJECT **)&obj->field_0x210;

  while (pOVar1 = pOVar2, pOVar1 != (OBJECT *)0x0) {

    obj = pOVar1;

    pOVar2 = *(OBJECT **)&pOVar1->field_0x210;

  }

  iVar3 = FUN_0052aa70();

  if (((((iVar3 == 0) || (DAT_00632f20 == 0)) || (iVar3 = FUN_004a61e0(obj), iVar3 == 0)) &&

      (((iVar3 = FUN_004a6220(obj), iVar3 == 0 && (iVar3 = FUN_004a6300(obj), iVar3 == 0)) &&

       (*(int *)&obj->field_0x1e0 != 0x2c)))) && (*(int *)&obj->field_0x1e0 != 0x5f)) {

    return obj->field_18C != in_stack_00000008;

  }

  return true;

}

/* ===== FUN_004aa7f0 @ 0x004AA7F0 ===== */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

/* WARNING: Struct "OBJECT": ignoring multiple overlapping fields */



bool FUN_004aa7f0(OBJECT *obj)



{

  OBJECT *pOVar1;

  OBJECT *pOVar2;

  int iVar3;

  uint uVar4;

  dword in_stack_00000008;

  

  iVar3 = FUN_004a6220(obj);

  if ((((iVar3 == 0) && (iVar3 = FUN_004a6200(obj), iVar3 == 0)) &&

      (iVar3 = FUN_004a6300(obj), iVar3 == 0)) && (iVar3 = FUN_004a6290(obj), iVar3 == 0)) {

    if (((obj->field_0x1f5 != '\0') ||

        (uVar4 = *(uint *)&obj->field_0xd8 & 0x4000c000,

        (~obj->acc_grenade_do_stopped >> 0x11 & 1) != 0 || uVar4 != 0)) ||

       ((uVar4 != 0 || (*(float *)&obj->field_0x1c0 <= (float)obj->field_278)))) {

      return false;

    }

  }

  else if ((~obj->acc_grenade_do_stopped >> 0x11 & 1) != 0 ||

           (*(uint *)&obj->field_0xd8 & 0x4000c000) != 0) {

    return false;

  }

  pOVar2 = *(OBJECT **)&obj->field_0x210;

  while (pOVar1 = pOVar2, pOVar1 != (OBJECT *)0x0) {

    obj = pOVar1;

    pOVar2 = *(OBJECT **)&pOVar1->field_0x210;

  }

  iVar3 = FUN_004a6220(obj);

  if (((iVar3 == 0) && (iVar3 = FUN_004a6300(obj), iVar3 == 0)) &&

     ((*(int *)&obj->field_0x1e0 != 0x2c && (*(int *)&obj->field_0x1e0 != 0x5f)))) {

    return obj->field_18C != in_stack_00000008;

  }

  return true;

}

/* ===== FUN_004aa8f0 @ 0x004AA8F0 ===== */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

/* WARNING: Struct "OBJECT": ignoring multiple overlapping fields */



bool FUN_004aa8f0(OBJECT *obj)



{

  OBJECT *pOVar1;

  OBJECT *pOVar2;

  int iVar3;

  uint uVar4;

  dword in_stack_00000008;

  

  iVar3 = FUN_004a6220(obj);

  if ((((iVar3 == 0) && (iVar3 = FUN_004a6200(obj), iVar3 == 0)) &&

      (iVar3 = FUN_004a6300(obj), iVar3 == 0)) && (iVar3 = FUN_004a6290(obj), iVar3 == 0)) {

    if (((obj->field_0x1f5 != '\0') ||

        (uVar4 = *(uint *)&obj->field_0xd8 & 0x4000c000,

        (~obj->acc_grenade_do_stopped >> 0x11 & 1) != 0 || uVar4 != 0)) ||

       ((uVar4 != 0 || (*(float *)&obj->field_0x1c0 <= (float)obj->field_278)))) {

      return false;

    }

  }

  else if ((~obj->acc_grenade_do_stopped >> 0x11 & 1) != 0 ||

           (*(uint *)&obj->field_0xd8 & 0x4000c000) != 0) {

    return false;

  }

  if (*(int *)&obj->field_0x1e0 != 0x12) {

    pOVar2 = *(OBJECT **)&obj->field_0x210;

    while (pOVar1 = pOVar2, pOVar1 != (OBJECT *)0x0) {

      obj = pOVar1;

      pOVar2 = *(OBJECT **)&pOVar1->field_0x210;

    }

    return obj->field_18C != in_stack_00000008;

  }

  return false;

}

/* ===== FUN_004aa9d0 @ 0x004AA9D0 ===== */
undefined4 FUN_004aa9d0(int param_1,int param_2)



{

  int iVar1;

  int iVar2;

  

  if ((~*(uint *)(param_1 + 0x1c8) >> 0x11 & 1) == 0 &&

      (*(uint *)(param_1 + 0xd8) & 0x4000c000) == 0) {

    iVar2 = *(int *)(param_1 + 0x210);

    while (iVar1 = iVar2, iVar1 != 0) {

      param_1 = iVar1;

      iVar2 = *(int *)(iVar1 + 0x210);

    }

    iVar2 = FUN_0052aa70();

    if ((((((iVar2 != 0) && (DAT_00632f20 != 0)) && (iVar2 = FUN_004a61e0(param_1), iVar2 != 0)) ||

         ((iVar2 = FUN_004a6220(param_1), iVar2 != 0 || (iVar2 = FUN_004a6300(param_1), iVar2 != 0))

         )) || ((*(int *)(param_1 + 0x1e0) == 0x2c ||

                ((*(int *)(param_1 + 0x1e0) == 0x5f || (*(int *)(param_1 + 0x18c) != param_2))))))

       || ((*(int *)(param_1 + 4) == 0x325 && (*(int *)(param_1 + 0xe4) != 1)))) {

      return 1;

    }

  }

  return 0;

}

/* ===== FUN_004aaa80 @ 0x004AAA80 ===== */
/* PS2 candidate: MortarCollisionValid__FP6OBJECTi (conf 0.62) */



undefined4 FUN_004aaa80(int param_1,int param_2)



{

  int iVar1;

  int iVar2;

  

  if ((~*(uint *)(param_1 + 0x1c8) >> 0x11 & 1) == 0 &&

      (*(uint *)(param_1 + 0xd8) & 0x4000c000) == 0) {

    iVar2 = *(int *)(param_1 + 0x210);

    while (iVar1 = iVar2, iVar1 != 0) {

      param_1 = iVar1;

      iVar2 = *(int *)(iVar1 + 0x210);

    }

    iVar2 = FUN_0052aa70();

    if ((((((iVar2 != 0) && (DAT_00632f20 != 0)) && (iVar2 = FUN_004a61e0(param_1), iVar2 != 0)) ||

         ((iVar2 = FUN_004a6220(param_1), iVar2 != 0 || (iVar2 = FUN_004a6300(param_1), iVar2 != 0))

         )) || ((*(int *)(param_1 + 0x1e0) == 0x2c || (*(int *)(param_1 + 0x1e0) == 0x5f)))) ||

       (((*(int *)(param_1 + 4) != 0x325 || (*(int *)(param_1 + 0xe4) != 1)) &&

        ((iVar2 = FUN_004a61e0(param_1), iVar2 == 0 || (*(int *)(param_1 + 0x18c) != param_2)))))) {

      return 1;

    }

  }

  return 0;

}

/* ===== FUN_004aab40 @ 0x004AAB40 ===== */
void FUN_004aab40(undefined4 param_1,int param_2,int param_3,int param_4,undefined4 param_5,

                 undefined4 param_6)



{

  int iVar1;

  

  iVar1 = reaper_0052e4a0(param_1);

  if (iVar1 != 0) {

    reaper_00530bd0(param_1,param_2,param_3,param_4,param_5,param_6);

  }

  repair_spell_fx(param_1,param_5,param_4 + (param_2 + param_3) * 4,param_6);

  return;

}

/* ===== repair_spell_fx @ 0x004ABD40 ===== */
/* PS2 candidate: husk_shot (conf 0.362) */



void repair_spell_fx(int param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)



{

  uint uVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  undefined4 uVar5;

  char *pcVar6;

  undefined4 uVar7;

  undefined1 *puVar8;

  int local_78;

  undefined4 local_74;

  undefined4 local_70;

  undefined4 local_6c;

  undefined1 local_68 [16];

  float local_58;

  undefined4 local_54;

  int local_50;

  undefined1 local_34 [4];

  undefined4 local_30;

  undefined4 local_2c;

  undefined4 local_28;

  undefined4 local_20;

  int local_1c;

  

  iVar2 = *(int *)(param_1 + 0x100);

  switch(param_2) {

  case 1:

    uVar1 = *(uint *)(iVar2 + 0x60);

    if (((uVar1 & 0x40) == 0) || (*(char *)(iVar2 + 0xf4) == '\0')) goto LAB_004ac24a;

    local_30 = *param_4;

    local_2c = param_4[1];

    local_28 = param_4[2];

    goto LAB_004ac207;

  case 2:

    uVar1 = *(uint *)(iVar2 + 0x60);

    if (*(char *)(iVar2 + 0xf4) == '\0') goto LAB_004ac24a;

    local_30 = *param_4;

    local_2c = param_4[1];

    local_28 = param_4[2];

LAB_004ac207:

    fx_get_free_effect__Fv();

    if (((uVar1 & 0x80) != 0) &&

       (FUN_00414690(param_4,local_68), (float)param_4[2] - local_58 < 5.0)) {

LAB_004ac241:

      FUN_0042dfd0(param_4,param_1 + 0x128,0x41200000);

    }

LAB_004ac24a:

    FUN_00497510(param_1);

    return;

  case 3:

    local_70 = *(undefined4 *)(param_1 + 0x2ac);

    local_74 = *(undefined4 *)(param_1 + 0x29c);

    local_6c = *(undefined4 *)(param_1 + 700);

    iVar3 = *(int *)(iVar2 + 0x174);

    if ((float)param_4[2] < 0.0 == ((float)param_4[2] == 0.0)) {

      local_78 = *(int *)(iVar2 + 0x178);

      pcVar6 = (char *)(iVar2 + 0xf4);

    }

    else {

      local_78 = *(int *)(iVar2 + 0x178);

      pcVar6 = (char *)(iVar2 + 0x114);

    }

    uVar1 = *(uint *)(iVar2 + 0x60);

    if (*pcVar6 != '\0') {

      local_30 = *param_4;

      local_2c = param_4[1];

      local_28 = param_4[2];

      fx_get_free_effect__Fv();

      if (((uVar1 & 0x80) != 0) &&

         (FUN_00414690(param_4,local_68), (float)param_4[2] - local_58 < 5.0)) {

        FUN_0042dfd0(param_4,&local_74,0x41200000);

      }

    }

    if (-1 < iVar3) {

      if ((float)param_4[2] < 0.0 != ((float)param_4[2] == 0.0)) {

        iVar3 = local_78;

      }

      sound_play_3dpos(iVar3,param_4);

    }

    FUN_00497510(param_1);

    return;

  case 4:

    *(undefined4 *)(param_1 + 0xa0) = *param_4;

    *(undefined4 *)(param_1 + 0xa4) = param_4[1];

    *(undefined4 *)(param_1 + 0xa8) = param_4[2];

    *(undefined4 *)(param_1 + 0x128) = param_4[3];

    *(undefined4 *)(param_1 + 300) = param_4[4];

    *(undefined4 *)(param_1 + 0x130) = param_4[5];

    return;

  case 6:

    *(undefined4 *)(param_1 + 0xa0) = *param_4;

    *(undefined4 *)(param_1 + 0xa4) = param_4[1];

    *(undefined4 *)(param_1 + 0xa8) = param_4[2];

    *(undefined4 *)(param_1 + 0x128) = param_4[3];

    *(undefined4 *)(param_1 + 300) = param_4[4];

    *(undefined4 *)(param_1 + 0x130) = param_4[5];

    if ((*(byte *)(iVar2 + 0x60) & 1) == 0) {

      iVar2 = FUN_0052e5b0(param_4[6]);

      *(int *)(param_1 + 0x274) = iVar2;

      *(undefined4 *)(param_1 + 0x18c) = *(undefined4 *)(iVar2 + 0x18c);

      return;

    }

    break;

  case 7:

    uVar5 = FUN_0052e5b0(*param_4);

    *(undefined4 *)(iVar2 + 0x1d8) = uVar5;

    *(uint *)(param_1 + 0xe4) = (uint)*(byte *)(param_4 + 1);

    break;

  case 8:

    iVar3 = FUN_0052e480(param_1);

    if (iVar3 == 0) {

      iVar3 = FUN_0052e5b0(param_4[3]);

      uVar5 = param_4[4];

      iVar4 = object_allocate_type(0x374,0);

      object_change_ospec(iVar4,0x28);

      FUN_00499310(iVar4,*param_4,param_4[1],param_4[2]);

      *(undefined4 *)(iVar4 + 0x18c) = *(undefined4 *)(param_1 + 0x18c);

      if (iVar3 != 0) {

        *(int *)(iVar4 + 0x274) = iVar3;

      }

      local_54 = 0xffffffff;

      local_50 = iVar4;

      fx_get_free_effect__Fv();

      iVar3 = FUN_0052e480(param_1);

      if (iVar3 == 0) {

        *(undefined4 *)(iVar4 + 0x188) = uVar5;

      }

    }

    uVar1 = *(uint *)(iVar2 + 0x60);

    if (*(char *)(iVar2 + 0xf4) == '\0') goto LAB_004ac24a;

    local_30 = *param_4;

    local_2c = param_4[1];

    local_28 = param_4[2];

    fx_get_free_effect__Fv();

    if (((uVar1 & 0x80) == 0) ||

       (FUN_00414690(param_4,local_68), 5.0 <= (float)param_4[2] - local_58)) goto LAB_004ac24a;

    goto LAB_004ac241;

  case 9:

    iVar3 = FUN_0052e480(param_1);

    if (iVar3 == 0) {

      uVar5 = param_4[3];

      iVar3 = object_allocate_type(0x374,0);

      object_change_ospec(iVar3,0x28);

      FUN_00499310(iVar3,*param_4,param_4[1],param_4[2]);

      puVar8 = local_34;

      *(undefined4 *)(iVar3 + 0x18c) = *(undefined4 *)(param_1 + 0x18c);

      uVar7 = 4;

      pcVar6 = s_fx_repair_spell_ground_0055fd7c;

      local_20 = 0xffffffff;

      local_1c = iVar3;

      fx_get_free_effect__Fv();

      iVar4 = FUN_0052e480(param_1,pcVar6,uVar7,puVar8);

      if (iVar4 == 0) {

        *(undefined4 *)(iVar3 + 0x188) = uVar5;

      }

    }

    local_70 = *(undefined4 *)(param_1 + 0x2ac);

    local_74 = *(undefined4 *)(param_1 + 0x29c);

    local_6c = *(undefined4 *)(param_1 + 700);

    iVar3 = *(int *)(iVar2 + 0x174);

    if ((float)param_4[2] < 0.0 == ((float)param_4[2] == 0.0)) {

      local_78 = *(undefined4 *)(iVar2 + 0x178);

      pcVar6 = (char *)(iVar2 + 0xf4);

    }

    else {

      local_78 = *(undefined4 *)(iVar2 + 0x178);

      pcVar6 = (char *)(iVar2 + 0x114);

    }

    uVar1 = *(uint *)(iVar2 + 0x60);

    if (*pcVar6 != '\0') {

      local_30 = *param_4;

      local_2c = param_4[1];

      local_28 = param_4[2];

      fx_get_free_effect__Fv();

      if (((uVar1 & 0x80) != 0) &&

         (FUN_00414690(param_4,local_68), (float)param_4[2] - local_58 < 5.0)) {

        FUN_0042dfd0(param_4,&local_74,0x41200000);

      }

    }

    if (-1 < iVar3) {

      if ((float)param_4[2] < 0.0 != ((float)param_4[2] == 0.0)) {

        sound_play_3dpos(local_78,param_4);

        FUN_00497510(param_1);

        return;

      }

      sound_play_3dpos(iVar3,param_4);

      FUN_00497510(param_1);

      return;

    }

    goto LAB_004ac24a;

  case 10:

    *(uint *)(iVar2 + 0x60) = *(uint *)(iVar2 + 0x60) & 0xfffeffff;

    iVar2 = FUN_0052e5b0(*param_4);

    if (iVar2 != 0) {

      *(int *)(*(int *)(iVar2 + 0x100) + 0x1d0) = param_1;

      return;

    }

    break;

  case 100:

    uVar5 = FUN_0052e5b0(*param_4);

    FUN_004aca20(param_1,uVar5);

    return;

  case 0x65:

    FUN_004ac860(param_1);

    return;

  }

  return;

}

/* ===== FUN_004ac4b0 @ 0x004AC4B0 ===== */
/* PS2 candidate: face_target (conf 0.504) */



void FUN_004ac4b0(int param_1,float *param_2,int param_3,float param_4,float param_5)



{

  float10 fVar1;

  float10 fVar2;

  float local_138;

  float local_134;

  float local_130;

  float local_12c;

  float local_128;

  float local_124;

  undefined1 local_120 [16];

  undefined1 local_110 [68];

  undefined1 local_cc [68];

  undefined1 local_88 [68];

  undefined1 local_44 [68];

  

  local_130 = 0.0;

  local_12c = -*(float *)(param_1 + 0x29c);

  local_128 = -*(float *)(param_1 + 0x2ac);

  local_124 = -*(float *)(param_1 + 700);

  local_138 = *param_2 - *(float *)(param_1 + 0xa0);

  local_134 = param_2[1] - *(float *)(param_1 + 0xa4);

  if (param_3 == 0) {

    local_130 = param_2[2] - *(float *)(param_1 + 0xa8);

  }

  FUN_0053e960(&local_12c,&local_12c);

  FUN_0053e960(&local_138,&local_138);

  FUN_00516290(&local_12c,&local_138);

  fVar1 = (float10)FUN_005445f0();

  if (fVar1 != (float10)0.0) {

    fVar2 = (float10)param_4 * fVar1 * (float10)param_5;

    if (fVar1 < fVar2) {

      fVar2 = fVar1;

    }

    FUN_0053fb40(local_120,&local_12c,&local_138,(float)(fVar2 / fVar1));

    FUN_0053deb0(local_88,local_120);

    FUN_0053dbb0(local_44,local_110,param_1 + 0x294);

    (*(code *)PTR_FUN_00580c18)(local_cc,local_88,local_110);

    (*(code *)PTR_FUN_00580c18)(param_1 + 0x294,local_44,local_cc);

    return;

  }

  return;

}

/* ===== FUN_004ac620 @ 0x004AC620 ===== */
/* PS2 candidate: align_with_ground (conf 0.56) */



void FUN_004ac620(int param_1,float *param_2,float param_3)



{

  float local_13c;

  undefined4 local_138;

  undefined4 local_134;

  undefined4 local_130;

  float local_12c;

  float local_128;

  float local_124;

  undefined1 local_120 [16];

  undefined1 local_110 [12];

  undefined4 local_104;

  undefined4 local_f4;

  undefined4 local_e4;

  undefined1 local_cc [68];

  undefined1 local_88 [68];

  undefined1 local_44 [68];

  

  local_13c = 1.0 - (*(float *)(param_1 + 0xa4) * param_2[1] +

                     *(float *)(param_1 + 0xa0) * *param_2 + *(float *)(param_1 + 0xa8) * param_2[2]

                    + param_2[3]) * param_3;

  if (0.0 <= local_13c) {

    if (1.0 < local_13c) {

      local_13c = 1.0;

    }

  }

  else {

    local_13c = 0.0;

  }

  local_12c = *param_2;

  local_128 = param_2[1];

  local_124 = param_2[2];

  FUN_0053dbb0(local_44,local_110,param_1 + 0x294);

  local_138 = local_104;

  local_134 = local_f4;

  local_130 = local_e4;

  FUN_0053e960(&local_138,&local_138);

  FUN_0053fb40(local_120,&local_138,&local_12c,local_13c);

  FUN_0053deb0(local_cc,local_120);

  (*(code *)PTR_FUN_00580c18)(local_88,local_cc,local_110);

  (*(code *)PTR_FUN_00580c18)(param_1 + 0x294,local_44,local_88);

  return;

}

/* ===== FUN_004ac760 @ 0x004AC760 ===== */
/* WARNING: Struct "OBJECT": ignoring multiple overlapping fields */



bool FUN_004ac760(OBJECT *param_1)



{

  dword dVar1;

  int iVar2;

  

  iVar2 = FUN_004a6180(param_1);

  if (iVar2 == 0) {

    iVar2 = FUN_004a6160(param_1);

    if (iVar2 == 0) {

      dVar1 = param_1->field_4;

      if (dVar1 == 8) {

        if (param_1->gap_E4 != 6) {

          return false;

        }

      }

      else if (dVar1 == 0xb) {

        iVar2 = FUN_004ef510(param_1);

        if ((iVar2 != 0) && (param_1->gap_E4 != 0x35)) {

          return false;

        }

      }

      else {

        if ((dVar1 != 0x438) && (dVar1 != 0x29a)) {

          if (dVar1 == 0xd7) {

            iVar2 = FUN_004d7b80();

            if (iVar2 == 0) {

              return true;

            }

            iVar2 = kabutoai_is_punch_anim__FP6OBJECT_3(param_1);

            return iVar2 != 0;

          }

          iVar2 = FUN_004a6100(param_1);

          if (iVar2 != 0) {

            iVar2 = FUN_004d49c0(param_1);

            if (iVar2 == 0) {

              return true;

            }

            iVar2 = kabutoai_is_punch_anim__FP6OBJECT_2(param_1);

            return iVar2 != 0;

          }

          if (param_1->field_4 != 0x232) {

            return true;

          }

        }

        if (param_1->gap_E4 != 100) {

          return false;

        }

      }

    }

    else if ((param_1->field_E0 & 0x40) == 0) {

      return false;

    }

  }

  else if ((param_1->field_E0 & 0x20) == 0) {

    return false;

  }

  return true;

}

/* ===== FUN_004ac860 @ 0x004AC860 ===== */
/* WARNING: Struct "OBJECT": ignoring multiple overlapping fields */

/* PS2 candidate: sf_is_valid_target__FP6OBJECT (conf 0.391) */



void FUN_004ac860(int param_1)



{

  uint *puVar1;

  OBJECT *obj;

  int iVar2;

  int iVar3;

  int iVar4;

  undefined4 uVar5;

  

  iVar4 = *(int *)(*(int *)(param_1 + 0x100) + 0x1c);

  if (*(int *)(iVar4 + 0x18) == 2) {

    uVar5 = 0x3ab;

  }

  else {

    uVar5 = 0x3a9;

  }

  sound_play_3dpos(uVar5,param_1 + 0xa0);

  if (*(int *)(iVar4 + 0xc) != 0) {

    iVar3 = FUN_004a6160(*(int *)(iVar4 + 0xc));

    if (iVar3 == 0) {

      iVar3 = FUN_004a6180(*(int *)(iVar4 + 0xc));

      if (iVar3 == 0) {

        obj = *(OBJECT **)(iVar4 + 0xc);

        if (obj->field_4 == 8) {

          obj->gap_E4 = 1;

        }

        else {

          if (obj->field_4 == 0xb) {

            iVar3 = FUN_004ef510(obj);

            if (iVar3 != 0) {

              iVar3 = *(int *)(iVar4 + 0xc);

              if (*(float *)(iVar3 + 0x278) < *(float *)(iVar3 + 0x1c0)) {

                *(undefined4 *)(iVar3 + 0xe4) = 5;

              }

              goto LAB_004ac9df;

            }

          }

          iVar3 = *(int *)(iVar4 + 0xc);

          iVar2 = *(int *)(iVar3 + 4);

          if ((iVar2 == 0x438) || (iVar2 == 0x29a)) {

            if (*(float *)(iVar3 + 0x278) < *(float *)(iVar3 + 0x1c0)) {

              *(undefined4 *)(iVar3 + 0xe4) = 0xb;

            }

          }

          else {

            if (iVar2 == 0xd7) {

              iVar3 = FUN_004d7b80(iVar3);

              if (iVar3 != 0) {

                FUN_004d7e10(*(OBJECT **)(iVar4 + 0xc));

                goto LAB_004ac9df;

              }

            }

            iVar3 = FUN_004a6100(*(undefined4 *)(iVar4 + 0xc));

            if (iVar3 != 0) {

              iVar3 = FUN_004d49c0(*(undefined4 *)(iVar4 + 0xc));

              if (iVar3 != 0) {

                FUN_004d4a20(*(undefined4 *)(iVar4 + 0xc));

                goto LAB_004ac9df;

              }

            }

            iVar3 = *(int *)(iVar4 + 0xc);

            if ((*(int *)(iVar3 + 4) == 0x232) &&

               (*(float *)(iVar3 + 0x278) < *(float *)(iVar3 + 0x1c0))) {

              *(undefined4 *)(iVar3 + 0xe4) = 10;

            }

          }

        }

      }

      else {

        puVar1 = (uint *)(*(int *)(iVar4 + 0xc) + 0xe0);

        *puVar1 = *puVar1 & 0xffffffdf;

      }

    }

    else {

      puVar1 = (uint *)(*(int *)(iVar4 + 0xc) + 0xe0);

      *puVar1 = *puVar1 & 0xffffffbf;

    }

  }

LAB_004ac9df:

  if (*(int *)(iVar4 + 0x1c) != 0) {

    FUN_00448c20(*(int *)(iVar4 + 0x1c));

    *(undefined4 *)(iVar4 + 0x1c) = 0;

  }

  iVar4 = reaper_0052e4a0(param_1);

  if (iVar4 != 0) {

    reaper_00530bd0(param_1,0,0,0,0x65,0);

  }

  return;

}

/* ===== FUN_004aca20 @ 0x004ACA20 ===== */
/* WARNING: Struct "OBJECT": ignoring multiple overlapping fields */

/* PS2 candidate: sf_is_valid_target__FP6OBJECT (conf 0.39) */



void FUN_004aca20(dword param_1,OBJECT *param_2)



{

  dword dVar1;

  bool bVar2;

  OBJECT *obj;

  int iVar3;

  undefined4 uVar4;

  int iVar5;

  int iVar6;

  OBJECT *pOVar7;

  undefined4 *puVar8;

  undefined4 *puVar9;

  undefined4 *local_38;

  

  obj = param_2;

  iVar6 = param_1;

  iVar5 = *(int *)(*(int *)(param_1 + 0x100) + 0x1c);

  if (((param_2 == (OBJECT *)0x0) ||

      ((((((iVar3 = FUN_004a6160(param_2), iVar3 == 0 && (iVar3 = FUN_004a6180(obj), iVar3 == 0)) &&

          (obj->field_4 != 8)) && ((obj->field_4 != 0xb || (iVar3 = FUN_004ef510(obj), iVar3 == 0)))

         ) && ((dVar1 = obj->field_4, dVar1 != 0x438 && (dVar1 != 0x232)))) &&

       ((((dVar1 != 0xd7 || (iVar3 = FUN_004d7b80(obj), iVar3 == 0)) && (obj->field_4 != 0x29a)) &&

        ((iVar3 = FUN_004a6100(obj), iVar3 == 0 || (iVar3 = FUN_004d49c0(obj), iVar3 == 0)))))))) ||

     (iVar3 = FUN_004a6120(*(undefined4 *)&obj->field_0x210), iVar3 != 0)) {

    *(undefined4 *)(iVar5 + 0x14) = 1;

    sound_play_3dpos(0x3a9,iVar6 + 0xa0);

    goto LAB_004accab;

  }

  pOVar7 = (OBJECT *)0x0;

  do {

    iVar3 = *(int *)(iVar5 + (int)pOVar7 * 4);

    if (iVar3 != 0) {

      iVar3 = *(int *)(iVar3 + 0x100);

      if (iVar3 == 0) {

        return;

      }

      *(OBJECT **)(iVar3 + 0x1d0) = obj;

      if (*(int *)(iVar5 + (int)pOVar7 * 4) == iVar6) {

        local_38 = (undefined4 *)(iVar3 + 0x5c);

        param_2 = pOVar7;

      }

    }

    pOVar7 = (OBJECT *)((int)&pOVar7->gap_0 + 1);

  } while ((int)pOVar7 < 3);

  *(OBJECT **)(iVar5 + 0xc) = obj;

  *(undefined4 *)(iVar5 + 0x10) = 1;

  iVar3 = FUN_004a6160(obj);

  if (iVar3 == 0) {

    iVar3 = FUN_004a6180(obj);

    if (iVar3 == 0) {

      if (obj->field_4 == 8) {

        obj->gap_E4 = 6;

      }

      else if ((obj->field_4 == 0xb) && (iVar3 = FUN_004ef510(obj), iVar3 != 0)) {

        obj->gap_E4 = 0x35;

      }

      else {

        dVar1 = obj->field_4;

        if ((dVar1 == 0x438) || (dVar1 == 0x29a)) {

LAB_004acbe1:

          obj->gap_E4 = 100;

        }

        else if ((dVar1 == 0xd7) && (iVar3 = FUN_004d7b80(obj), iVar3 != 0)) {

          FUN_004d7c60(obj);

        }

        else {

          iVar3 = FUN_004a6100(obj);

          if ((iVar3 == 0) || (iVar3 = FUN_004d49c0(obj), iVar3 == 0)) {

            if (obj->field_4 == 0x232) goto LAB_004acbe1;

          }

          else {

            FUN_004d4a00(obj);

          }

        }

      }

    }

    else {

      obj->field_E0 = obj->field_E0 | 0x20;

    }

  }

  else {

    obj->field_E0 = obj->field_E0 | 0x40;

  }

  uVar4 = fx_get_free_effect__Fv();

  *(undefined4 *)(iVar5 + 0x1c) = uVar4;

  bVar2 = true;

  pOVar7 = (OBJECT *)0x0;

  do {

    if ((pOVar7 != param_2) && (iVar3 = *(int *)(iVar5 + (int)pOVar7 * 4), iVar3 != 0)) {

      iVar3 = *(int *)(iVar3 + 0x100);

      puVar8 = local_38;

      puVar9 = (undefined4 *)(iVar3 + 0x5c);

      for (iVar6 = 0x55; iVar6 != 0; iVar6 = iVar6 + -1) {

        *puVar9 = *puVar8;

        puVar8 = puVar8 + 1;

        puVar9 = puVar9 + 1;

      }

      iVar6 = param_1;

      if (bVar2) {

        bVar2 = false;

        *(float *)(iVar3 + 0x6c) = *(float *)(DAT_00632ed8 + 0x918) * *(float *)(iVar3 + 0x6c);

      }

    }

    pOVar7 = (OBJECT *)((int)&pOVar7->gap_0 + 1);

  } while ((int)pOVar7 < 3);

  sound_play_3dpos(0x3a8,&obj->gap_A0);

LAB_004accab:

  iVar5 = reaper_0052e4a0(iVar6);

  if (iVar5 != 0) {

    param_1 = obj->field_188;

    reaper_00530bd0(iVar6,0,1,0,100,&param_1);

  }

  return;

}

/* ===== FUN_004ad190 @ 0x004AD190 ===== */
void FUN_004ad190(int param_1,int param_2)



{

  int iVar1;

  int iVar2;

  

  if (*(int *)(param_2 + 0x18) != 2) {

    iVar2 = 0;

    do {

      if (param_1 == *(int *)(param_2 + iVar2 * 4)) break;

      iVar2 = iVar2 + 1;

    } while (iVar2 < 3);

    *(undefined4 *)(param_2 + iVar2 * 4) = 0;

    if ((iVar2 == 1) && (*(int *)(param_2 + 0x14) != 0)) {

      iVar2 = 0;

      do {

        iVar1 = *(int *)(param_2 + iVar2 * 4);

        if (iVar1 != 0) {

          if ((*(uint *)(iVar1 + 0xd8) & 0x8000) == 0) {

            *(undefined4 *)(*(int *)(iVar1 + 0x100) + 0x84) = 0;

          }

          else {

            *(undefined4 *)(param_2 + iVar2 * 4) = 0;

          }

        }

        iVar2 = iVar2 + 1;

      } while (iVar2 < 3);

    }

    sound_play_3dpos(0x3a9,param_1 + 0xa0);

    return;

  }

  if (*(int *)(param_2 + 0x14) == 0) {

    iVar2 = 0;

    do {

      if (param_1 == *(int *)(param_2 + iVar2 * 4)) break;

      iVar2 = iVar2 + 1;

    } while (iVar2 < 3);

    iVar2 = *(int *)(*(int *)(param_2 + iVar2 * 4) + 0x100);

    FUN_00456ee0(0x10,param_1,0,*(int *)(param_2 + 0xc) + 0xa0,*(undefined4 *)(iVar2 + 0x90),

                 *(undefined4 *)(iVar2 + 0x98),*(undefined4 *)(iVar2 + 0x8c),

                 *(undefined4 *)(iVar2 + 0x94),*(undefined4 *)(param_1 + 0x18c));

  }

  FUN_004ac860(param_1);

  return;

}

/* ===== FUN_004ad7e0 @ 0x004AD7E0 ===== */
/* PS2 candidate: reapertrail_logic (conf 0.51) */



void FUN_004ad7e0(int param_1)



{

  uint *puVar1;

  

  puVar1 = *(uint **)(param_1 + 0x100);

  if (-1 < (char)*puVar1) {

    *puVar1 = *puVar1 | 0x484;

    puVar1[0x18] = puVar1[0x18] & 0xffffffcf;

    FUN_004034a0(param_1,10,0x21,1,0x41a00000,0);

    *(undefined4 *)(param_1 + 0xe4) = 1;

  }

  return;

}

/* ===== FUN_004adbf0 @ 0x004ADBF0 ===== */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

/* WARNING: Struct "OBJECT": ignoring multiple overlapping fields */

/* PS2 candidate: repairgun_target_valid__FP6OBJECTi (conf 0.572) */



undefined4 FUN_004adbf0(OBJECT *obj)



{

  OBJECT *pOVar1;

  OBJECT *pOVar2;

  int iVar3;

  float10 fVar4;

  float10 fVar5;

  dword in_stack_00000008;

  

  if ((~obj->acc_grenade_do_stopped >> 0x11 & 1) == 0 &&

      (*(uint *)&obj->field_0xd8 & 0x4000c000) == 0) {

    pOVar2 = *(OBJECT **)&obj->field_0x210;

    while (pOVar1 = pOVar2, pOVar1 != (OBJECT *)0x0) {

      obj = pOVar1;

      pOVar2 = *(OBJECT **)&pOVar1->field_0x210;

    }

    iVar3 = FUN_004a6220(obj);

    if (((iVar3 == 0) && (iVar3 = FUN_004a6160(obj), iVar3 == 0)) &&

       (*(int *)&obj->field_0x1e0 != 0x5f)) {

      iVar3 = FUN_004a6140(obj);

      if ((((iVar3 != 0) && (obj->field_18C == in_stack_00000008)) && (0.0 < (float)obj->field_278))

         && ((float)obj->field_278 < *(float *)&obj->field_0x1c0)) {

        return 1;

      }

    }

    else {

      iVar3 = FUN_004a6160(obj);

      if ((iVar3 == 0) || ((float)obj->field_278 != 0.0)) {

        iVar3 = FUN_004a6220(obj);

        if (iVar3 != 0) {

          fVar4 = (float10)FUN_00417f20(obj);

          fVar5 = (float10)FUN_00418170(obj);

          if (fVar5 == (float10)(float)fVar4) {

            return 0;

          }

        }

        if (((obj->field_4 != 0x447) && (obj->field_4 != 0x342)) &&

           ((*(int *)&obj->field_0x1e0 != 0x5f || ((float)obj->field_278 != 0.0)))) {

          if (obj->field_18C == in_stack_00000008) {

            return 1;

          }

          iVar3 = FUN_004a6220(obj);

          if (iVar3 != 0) {

            return 1;

          }

        }

      }

    }

  }

  return 0;

}

/* ===== FUN_004add50 @ 0x004ADD50 ===== */
/* PS2 candidate: PROJ_GetCustom (conf 0.528) */



undefined * FUN_004add50(int param_1)



{

  if ((-1 < param_1) && (param_1 < 0x35)) {

    return &DAT_0055f6d0 + param_1 * 0x1c;

  }

  return (undefined *)0x0;

}

/* ===== FUN_004add70 @ 0x004ADD70 ===== */
/* PS2 candidate: fx_create_hack_logic (conf 0.458) */



void FUN_004add70(int param_1)



{

  int iVar1;

  

  if (*(int *)(param_1 + 0xec) != 0x3f800000) {

    iVar1 = *(int *)(param_1 + 4);

    if (((iVar1 != 0x2d6) && (iVar1 != 0x2d7)) && (iVar1 != 0x2d8)) {

      if (iVar1 == 0x2df) {

        fx_get_free_effect__Fv();

        fx_get_free_effect__Fv();

        fx_get_free_effect__Fv();

        *(undefined4 *)(param_1 + 0xec) = 0x3f800000;

        return;

      }

      if (iVar1 == 0x2e0) {

        fx_get_free_effect__Fv();

        fx_get_free_effect__Fv();

        fx_get_free_effect__Fv();

        fx_get_free_effect__Fv();

        *(undefined4 *)(param_1 + 0xec) = 0x3f800000;

        return;

      }

      if (iVar1 == 0x2e1) {

        fx_get_free_effect__Fv();

        fx_get_free_effect__Fv();

        fx_get_free_effect__Fv();

        fx_get_free_effect__Fv();

        *(undefined4 *)(param_1 + 0xec) = 0x3f800000;

        return;

      }

      if (iVar1 == 0x2d9) {

        fx_get_free_effect__Fv();

        fx_get_free_effect__Fv();

        *(undefined4 *)(param_1 + 0xec) = 0x3f800000;

        return;

      }

      if (iVar1 == 0x353) {

        fx_get_free_effect__Fv();

      }

    }

    *(undefined4 *)(param_1 + 0xec) = 0x3f800000;

  }

  return;

}

/* ===== FUN_004ae290 @ 0x004AE290 ===== */
/* PS2 candidate: releaseMpegBuffers__Fv (conf 0.831) */



void FUN_004ae290(void)



{

  main_makeobj_00472dd0(DAT_00632d48);

  main_makeobj_00472dd0(DAT_00632d44);

  main_makeobj_00472dd0(DAT_00632d40);

  main_makeobj_00472dd0(DAT_00632d3c);

  main_makeobj_00472dd0(DAT_00632d38);

  main_makeobj_00472dd0(DAT_00632d34);

  main_makeobj_00472dd0(DAT_00632d30);

  main_makeobj_00472dd0(DAT_00632d2c);

  return;

}

/* ===== read_objects_bin_PS2 @ 0x004AE4C0 ===== */
/* WARNING: Struct "OBJECT": ignoring multiple overlapping fields */

/* PS2 candidate: read_worlds_bin_fn_PS2 (conf 0.516) */



void read_objects_bin_PS2(void)



{

  OBJECT *obj;

  char cVar1;

  byte bVar2;

  byte bVar3;

  int iVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float *pfVar8;

  int *piVar9;

  undefined4 *puVar10;

  undefined4 uVar11;

  uint *puVar12;

  undefined4 uVar13;

  undefined4 *puVar14;

  char *pcVar15;

  dword *pdVar16;

  undefined4 uVar17;

  dword dVar18;

  uint uVar19;

  int iVar20;

  int iVar21;

  int iVar22;

  uint uVar23;

  int *piVar24;

  undefined4 *puVar25;

  byte *pbVar26;

  byte *pbVar27;

  int iVar28;

  char *pcVar29;

  float *pfVar30;

  float *pfVar31;

  float *pfVar32;

  float fVar33;

  float10 fVar34;

  uint uVar35;

  int iStack00000004;

  uint uStack00000008;

  char *pcStack0000000c;

  undefined4 *puStack00000010;

  int iStack00000014;

  int *piStack0000001c;

  undefined4 *in_stack_00000020;

  undefined4 *in_stack_00000030;

  

  FUN_00543e00();

  FUN_005178d0();

  piVar9 = (int *)FUN_0053a700();

  FUN_005178d0();

  pcStack0000000c = (char *)*piVar9;

  piStack0000001c = piVar9 + 1;

  puStack00000010 = (undefined4 *)FUN_0053a700();

  puVar10 = &DAT_00632d4c;

  for (puVar14 = DAT_00632d4c; puVar14 != (undefined4 *)0x0; puVar14 = (undefined4 *)*puVar14) {

    puVar10 = puVar14;

  }

  *puVar10 = puStack00000010;

  puVar10 = puStack00000010;

  for (uVar19 = (int)pcStack0000000c * 4 + 8U >> 2; uVar19 != 0; uVar19 = uVar19 - 1) {

    *puVar10 = 0;

    puVar10 = puVar10 + 1;

  }

  for (iVar20 = 0; iVar20 != 0; iVar20 = iVar20 + -1) {

    *(undefined1 *)puVar10 = 0;

    puVar10 = (undefined4 *)((int)puVar10 + 1);

  }

  puStack00000010[1] = pcStack0000000c;

  if (0 < (int)pcStack0000000c) {

    puStack00000010 = puStack00000010 + 2;

    do {

      uVar11 = *(undefined4 *)(*piStack0000001c + (int)piVar9);

      pcVar29 = (char *)((int)piVar9 + *piStack0000001c + 4);

      piStack0000001c = piStack0000001c + 1;

      FUN_00542f27();

      puVar10 = (undefined4 *)object_clone_objectset();

      *puStack00000010 = puVar10;

      *puVar10 = uVar11;

      FUN_00542f27();

      FUN_00405130();

      cVar1 = *pcVar29;

      while (cVar1 != '\0') {

        pcVar15 = pcVar29 + 1;

        pcVar29 = pcVar29 + 1;

        cVar1 = *pcVar15;

      }

      puStack00000010 = puStack00000010 + 1;

      pcStack0000000c = (char *)((int)pcStack0000000c + -1);

    } while (pcStack0000000c != (char *)0x0);

  }

  iVar20 = piStack0000001c[*piStack0000001c + 1];

  piStack0000001c = piStack0000001c + *piStack0000001c + 2;

  if (0 < iVar20) {

    in_stack_00000030 = (undefined4 *)FUN_0053a700();

    puVar10 = &DAT_00632d50;

    for (puVar14 = DAT_00632d50; puVar14 != (undefined4 *)0x0; puVar14 = (undefined4 *)*puVar14) {

      puVar10 = puVar14;

    }

    *puVar10 = in_stack_00000030;

    puVar10 = in_stack_00000030;

    for (uVar19 = iVar20 * 0x464 + 8U >> 2; uVar19 != 0; uVar19 = uVar19 - 1) {

      *puVar10 = 0;

      puVar10 = puVar10 + 1;

    }

    for (iVar21 = 0; iVar21 != 0; iVar21 = iVar21 + -1) {

      *(undefined1 *)puVar10 = 0;

      puVar10 = (undefined4 *)((int)puVar10 + 1);

    }

    in_stack_00000030[1] = iVar20;

  }

  iStack00000014 = 0;

  if (0 < iVar20) {

    do {

      iVar21 = *piStack0000001c;

      piStack0000001c = piStack0000001c + 1;

      puVar10 = in_stack_00000030 + iStack00000014 * 0x119 + 2;

      uVar19 = 0;

      puVar14 = (undefined4 *)&stack0x000004a8;

      for (iVar22 = 0x80; iVar22 != 0; iVar22 = iVar22 + -1) {

        *puVar14 = 0;

        puVar14 = puVar14 + 1;

      }

      puStack00000010 = (undefined4 *)0x0;

      uStack00000008 = 0;

      pcStack0000000c = (char *)0x0;

      *puVar10 = *(undefined4 *)(iVar21 + (int)piVar9);

      pbVar27 = (byte *)((undefined4 *)(iVar21 + (int)piVar9) + 1);

      iStack00000004 = 0;

      uVar35 = uVar19;

LAB_004ae6c3:

      while( true ) {

        while( true ) {

          while( true ) {

            while( true ) {

              while( true ) {

                while( true ) {

                  while( true ) {

                    while( true ) {

                      while( true ) {

                        while( true ) {

                          bVar2 = *pbVar27;

                          pbVar26 = pbVar27 + 1;

                          if (bVar2 != 0x51) break;

                          if (9 < iStack00000004) {

                            FUN_00542f27();

                            FUN_0051ea20();

                          }

                          if (*(int *)pbVar26 == 0) {

                            puVar10[iStack00000004 + 0x100] = 0;

                          }

                          else {

                            uVar11 = FUN_00497cd0();

                            puVar10[iStack00000004 + 0x100] = uVar11;

                          }

                          fVar34 = (float10)*(float *)(pbVar27 + 5);

                          if (fVar34 == (float10)0.0) {

                            fVar34 = (float10)60.0;

                          }

                          fVar34 = (float10)fsin(fVar34 * (float10)0.008726646);

                          puVar10[iStack00000004 + 0x10a] =

                               (float)(fVar34 * (float10)*(float *)(pbVar27 + 9));

                          pbVar27 = pbVar27 + 0xd;

                          iStack00000004 = iStack00000004 + 1;

                        }

                        if (bVar2 != 0x59) break;

                        if (9 < iStack00000004) {

                          FUN_00542f27();

                          FUN_0051ea20();

                        }

                        uVar11 = FUN_00497cd0();

                        puVar10[iStack00000004 + 0x100] = uVar11;

                        puVar10[iStack00000004 + 0x10a] = 0xc0400000;

                        iStack00000004 = iStack00000004 + 1;

                        pbVar27 = pbVar27 + 5;

                      }

                      if (bVar2 != 0x5a) break;

                      if (9 < iStack00000004) {

                        FUN_00542f27();

                        FUN_0051ea20();

                      }

                      uVar11 = FUN_00497cd0();

                      puVar10[iStack00000004 + 0x100] = uVar11;

                      puVar10[iStack00000004 + 0x10a] = 0xbf800000;

                      iStack00000004 = iStack00000004 + 1;

                      pbVar27 = pbVar27 + 5;

                    }

                    if (bVar2 != 0x5b) break;

                    if (9 < iStack00000004) {

                      FUN_00542f27();

                      FUN_0051ea20();

                    }

                    uVar11 = FUN_00497cd0();

                    puVar10[iStack00000004 + 0x100] = uVar11;

                    puVar10[iStack00000004 + 0x10a] = 0xc0000000;

                    iStack00000004 = iStack00000004 + 1;

                    FUN_00542f27();

                    FUN_0051ea20();

                    pbVar27 = pbVar27 + 5;

                  }

                  if (bVar2 != 0x52) break;

                  if ((puStack00000010 != (undefined4 *)0x0) && (uVar19 != 0)) {

                    puVar12 = (uint *)FUN_0053a700();

                    *(uint **)((int)puStack00000010 + 0x24) = puVar12;

                    *puVar12 = uVar35;

                    puVar14 = *(undefined4 **)((int)puStack00000010 + 0x24);

                    puVar25 = (undefined4 *)&stack0x000000a8;

                    for (iVar21 = (uVar35 & 0x7ffffff) << 3; puVar14 = puVar14 + 1, iVar21 != 0;

                        iVar21 = iVar21 + -1) {

                      *puVar14 = *puVar25;

                      puVar25 = puVar25 + 1;

                    }

                    for (iVar21 = 0; uVar19 = uVar35, iVar21 != 0; iVar21 = iVar21 + -1) {

                      *(undefined1 *)puVar14 = *(undefined1 *)puVar25;

                      puVar25 = (undefined4 *)((int)puVar25 + 1);

                      puVar14 = (undefined4 *)((int)puVar14 + 1);

                    }

                  }

                  bVar2 = *pbVar26;

                  pbVar27 = pbVar27 + 2;

                  bVar3 = *pbVar27;

                  while (bVar3 != 0) {

                    pbVar26 = pbVar27 + 1;

                    pbVar27 = pbVar27 + 1;

                    bVar3 = *pbVar26;

                  }

                  pbVar27 = pbVar27 + 1;

                  if (puVar10[bVar2 + 2] == 0) {

                    AnimationCreate();

                    puStack00000010 = (undefined4 *)puVar10[bVar2 + 2];

                    uVar19 = 0;

                    puVar14 = (undefined4 *)&stack0x000000a8;

                    for (iVar21 = 0x100; uVar35 = uVar19, iVar21 != 0; iVar21 = iVar21 + -1) {

                      *puVar14 = 0;

                      puVar14 = puVar14 + 1;

                    }

                  }

                  else {

                    FUN_00542f27();

                    FUN_0051ea20();

                  }

                }

                if (bVar2 != 0x56) break;

                if (0x1f < (int)uVar19) {

                  FUN_0051ea20();

                  uVar19 = 0;

                }

                iVar21 = *(int *)pbVar26;

                uVar11 = *(undefined4 *)(pbVar27 + 5);

                iVar22 = uVar19 * 0x20;

                pbVar27 = pbVar27 + 9;

                *(undefined4 *)(&stack0x000000b0 + iVar22) = uVar11;

                *(float *)(&stack0x000000ac + iVar22) = (float)iVar21 * 0.033333335;

                *(undefined4 *)(&stack0x000000b4 + iVar22) = uVar11;

                *(undefined4 *)(&stack0x000000a8 + iVar22) = 1;

                uVar19 = uVar19 + 1;

                uVar35 = uVar19;

              }

              if (bVar2 != 0x57) break;

              if (0x1f < (int)(uVar19 + 1)) {

                FUN_0051ea20();

                uVar19 = 0;

              }

              iVar21 = *(int *)pbVar26;

              uVar11 = *(undefined4 *)(pbVar27 + 5);

              iVar22 = uVar19 * 0x20;

              *(undefined4 *)(&stack0x000000b0 + iVar22) = uVar11;

              *(undefined4 *)(&stack0x000000a8 + iVar22) = 3;

              *(float *)(&stack0x000000ac + iVar22) = (float)iVar21 * 0.033333335;

              *(undefined4 *)(&stack0x000000b4 + iVar22) = uVar11;

              uVar11 = *(undefined4 *)(pbVar27 + 9);

              iVar21 = (uVar19 + 1) * 0x20;

              *(undefined4 *)(&stack0x000000ac + iVar21) =

                   *(undefined4 *)(&stack0x0000008c + iVar21);

              pbVar27 = pbVar27 + 0xd;

              *(undefined4 *)(&stack0x000000b0 + iVar21) = uVar11;

              *(undefined4 *)(&stack0x000000b4 + iVar21) = uVar11;

              *(undefined4 *)(&stack0x000000a8 + iVar21) = 5;

              uVar19 = uVar19 + 2;

              uVar35 = uVar19;

            }

            if (bVar2 != 0x58) break;

            if (0x1f < (int)uVar19) {

              FUN_0051ea20();

              uVar19 = 0;

            }

            uVar11 = *(undefined4 *)(pbVar27 + 5);

            uVar13 = *(undefined4 *)(pbVar27 + 9);

            iVar21 = uVar19 * 0x20;

            pbVar27 = pbVar27 + 0xd;

            *(float *)(&stack0x000000ac + iVar21) = (float)*(int *)pbVar26 * 0.033333335;

            *(undefined4 *)(&stack0x000000b0 + iVar21) = uVar11;

            *(undefined4 *)(&stack0x000000b4 + iVar21) = uVar13;

            *(undefined4 *)(&stack0x000000a8 + iVar21) = 9;

            uVar19 = uVar19 + 1;

            uVar35 = uVar19;

          }

          if (bVar2 != 0x5c) break;

          if (0x1f < (int)uVar19) {

            FUN_0051ea20();

            uVar19 = 0;

          }

          uVar11 = *(undefined4 *)(pbVar27 + 5);

          uVar13 = *(undefined4 *)(pbVar27 + 9);

          iVar21 = uVar19 * 0x20;

          pbVar27 = pbVar27 + 0xd;

          *(float *)(&stack0x000000ac + iVar21) = (float)*(int *)pbVar26 * 0.033333335;

          *(undefined4 *)(&stack0x000000b0 + iVar21) = uVar11;

          *(undefined4 *)(&stack0x000000b4 + iVar21) = uVar13;

          *(undefined4 *)(&stack0x000000a8 + iVar21) = 0x10001;

          uVar19 = uVar19 + 1;

          uVar35 = uVar19;

        }

        if (bVar2 != 0x7f) break;

        if (0x1f < (int)uVar19) {

          FUN_0051ea20();

          uVar35 = 0;

        }

        iVar21 = uVar35 * 0x20;

        pbVar27 = pbVar27 + 5;

        *(float *)(&stack0x000000ac + iVar21) = (float)*(int *)pbVar26 * 0.033333335;

        do {

          bVar2 = *pbVar27;

          pbVar27 = pbVar27 + 1;

        } while (bVar2 != 0);

        uVar11 = Main_fx_00447210();

        *(undefined4 *)(&stack0x000000b0 + iVar21) = uVar11;

        do {

          bVar2 = *pbVar27;

          pbVar27 = pbVar27 + 1;

        } while (bVar2 != 0);

        uVar11 = Main_fx_00447210();

        *(undefined4 *)(&stack0x000000b4 + iVar21) = uVar11;

        do {

          bVar2 = *pbVar27;

          pbVar27 = pbVar27 + 1;

        } while (bVar2 != 0);

        uVar11 = Main_fx_00447210();

        *(undefined4 *)(&stack0x000000b8 + iVar21) = uVar11;

        do {

          bVar2 = *pbVar27;

          pbVar27 = pbVar27 + 1;

        } while (bVar2 != 0);

        uVar11 = Main_fx_00447210();

        *(undefined4 *)(&stack0x000000bc + iVar21) = uVar11;

        do {

          bVar2 = *pbVar27;

          pbVar27 = pbVar27 + 1;

        } while (bVar2 != 0);

        uVar11 = Main_fx_00447210();

        *(undefined4 *)(&stack0x000000c0 + iVar21) = uVar11;

        uVar11 = *(undefined4 *)pbVar27;

        *(undefined4 *)(&stack0x000000a8 + iVar21) = 0x40;

        *(undefined4 *)(&stack0x000000c4 + iVar21) = uVar11;

LAB_004aed0a:

        uVar19 = uVar35 + 1;

        pbVar27 = pbVar27 + 4;

        uVar35 = uVar19;

      }

      if (bVar2 == 0x80) {

        if (0x1f < (int)uVar19) {

          FUN_0051ea20();

          uVar35 = 0;

        }

        iVar21 = uVar35 * 0x20;

        pbVar27 = pbVar27 + 5;

        *(float *)(&stack0x000000ac + iVar21) = (float)*(int *)pbVar26 * 0.033333335;

        do {

          bVar2 = *pbVar27;

          pbVar27 = pbVar27 + 1;

        } while (bVar2 != 0);

        uVar11 = Main_fx_00447210();

        *(undefined4 *)(&stack0x000000b0 + iVar21) = uVar11;

        do {

          bVar2 = *pbVar27;

          pbVar27 = pbVar27 + 1;

        } while (bVar2 != 0);

        uVar11 = Main_fx_00447210();

        *(undefined4 *)(&stack0x000000b4 + iVar21) = uVar11;

        do {

          bVar2 = *pbVar27;

          pbVar27 = pbVar27 + 1;

        } while (bVar2 != 0);

        uVar11 = Main_fx_00447210();

        *(undefined4 *)(&stack0x000000b8 + iVar21) = uVar11;

        do {

          bVar2 = *pbVar27;

          pbVar27 = pbVar27 + 1;

        } while (bVar2 != 0);

        uVar11 = Main_fx_00447210();

        *(undefined4 *)(&stack0x000000bc + iVar21) = uVar11;

        do {

          bVar2 = *pbVar27;

          pbVar27 = pbVar27 + 1;

        } while (bVar2 != 0);

        uVar13 = Main_fx_00447210();

        uVar11 = *(undefined4 *)pbVar27;

        *(undefined4 *)(&stack0x000000c0 + iVar21) = uVar13;

        *(undefined4 *)(&stack0x000000a8 + iVar21) = 0x80;

        *(undefined4 *)(&stack0x000000c4 + iVar21) = uVar11;

        goto LAB_004aed0a;

      }

      if (bVar2 == 0x53) {

        uVar23 = (uint)*pbVar26;

        *(byte **)(&stack0x000004a8 + uVar23 * 4) = pbVar27 + 2;

        pbVar27 = pbVar27 + 0x12;

        if (uStack00000008 <= uVar23) {

          uStack00000008 = uVar23 + 1;

        }

        if (0x7f < uStack00000008) {

          FUN_0051ea20();

          uStack00000008 = 0x80;

        }

        goto LAB_004ae6c3;

      }

      if (bVar2 == 0x54) {

        bVar2 = *pbVar26;

        bVar3 = pbVar27[2];

        uVar11 = *(undefined4 *)(pbVar27 + 0x13);

        *(byte **)(&stack0x000006a8 + (int)pcStack0000000c * 4) = pbVar27 + 3;

        *(undefined4 *)(&stack0x00000aa8 + (int)pcStack0000000c * 4) = uVar11;

        *(uint *)(&stack0x000008a8 + (int)pcStack0000000c * 4) = (uint)bVar2;

        *(uint *)(&stack0x00000ca8 + (int)pcStack0000000c * 4) = (uint)bVar3;

        if (bVar2 == 0) {

          FUN_0051ea20();

          pbVar27 = pbVar27 + 0x17;

        }

        else {

          pcStack0000000c = (char *)((int)pcStack0000000c + 1);

          pbVar27 = pbVar27 + 0x17;

        }

        goto LAB_004ae6c3;

      }

      if (bVar2 == 0x55) {

        puVar10[1] = puVar10[1] | 0x10;

        pbVar27 = pbVar26;

        goto LAB_004ae6c3;

      }

      if (bVar2 != 0xff) {

        FUN_00542f27();

        FUN_0051ea20();

        return;

      }

      if ((0 < iStack00000004) && (puVar10[iStack00000004 + 0xff] != 0)) {

        if (9 < iStack00000004) {

          FUN_00542f27();

          FUN_0051ea20();

        }

        fVar34 = (float10)fsin((float10)0.5235987901687622);

        puVar10[iStack00000004 + 0x100] = 0;

        puVar10[iStack00000004 + 0x10a] = (float)(fVar34 * (float10)3000.0);

      }

      if (uStack00000008 == 0) {

        puVar10[0x114] = 0;

        puVar10[0x115] = 0;

      }

      else {

        iVar21 = 0;

        iVar22 = 0;

        if (uStack00000008 != 0) {

          do {

            if (*(char **)(&stack0x000004a8 + iVar22 * 4) != (char *)0x0) {

              uVar19 = 0xffffffff;

              pcVar29 = *(char **)(&stack0x000004a8 + iVar22 * 4);

              do {

                if (uVar19 == 0) break;

                uVar19 = uVar19 - 1;

                cVar1 = *pcVar29;

                pcVar29 = pcVar29 + 1;

              } while (cVar1 != '\0');

              iVar21 = iVar21 + ~uVar19;

            }

            iVar22 = iVar22 + 1;

          } while (iVar22 < (int)uStack00000008);

        }

        iVar22 = 0;

        piVar24 = puVar10 + 2;

        iVar28 = 0xfe;

        do {

          iVar4 = *piVar24;

          piVar24 = piVar24 + 1;

          iVar22 = iVar22 + (uint)(iVar4 != 0);

          iVar28 = iVar28 + -1;

        } while (iVar28 != 0);

        uVar19 = iVar21 + uStack00000008 * 4 + iVar22 * uStack00000008 * 4;

        puVar10[0x114] = uStack00000008;

        puVar14 = (undefined4 *)FUN_0053a700();

        puVar10[0x115] = puVar14;

        for (uVar23 = uVar19 >> 2; uVar23 != 0; uVar23 = uVar23 - 1) {

          *puVar14 = 0;

          puVar14 = puVar14 + 1;

        }

        for (uVar19 = uVar19 & 3; uVar19 != 0; uVar19 = uVar19 - 1) {

          *(undefined1 *)puVar14 = 0;

          puVar14 = (undefined4 *)((int)puVar14 + 1);

        }

        puVar25 = (undefined4 *)puVar10[0x115];

        puVar14 = puVar25 + uStack00000008;

        iStack00000004 = 0;

        if (uStack00000008 != 0) {

          do {

            pcVar29 = *(char **)(&stack0x000004a8 + iStack00000004 * 4);

            if (pcVar29 == (char *)0x0) {

              *puVar25 = 0;

            }

            else {

              pcVar15 = pcVar29;

              do {

                cVar1 = *pcVar15;

                pcVar15[(int)puVar14 - (int)pcVar29] = cVar1;

                pcVar15 = pcVar15 + 1;

              } while (cVar1 != '\0');

              *puVar25 = puVar14;

              uVar19 = 0xffffffff;

              do {

                if (uVar19 == 0) break;

                uVar19 = uVar19 - 1;

                cVar1 = *pcVar29;

                pcVar29 = pcVar29 + 1;

              } while (cVar1 != '\0');

              puVar14 = (undefined4 *)((int)puVar14 + ~uVar19);

            }

            puVar25 = puVar25 + 1;

            iStack00000004 = iStack00000004 + 1;

          } while (iStack00000004 < (int)uStack00000008);

        }

        piVar24 = puVar10 + 2;

        iVar21 = 0xfe;

        do {

          if (*piVar24 != 0) {

            *(undefined4 **)(*piVar24 + 0x54) = puVar14;

            puVar14 = puVar14 + uStack00000008;

          }

          piVar24 = piVar24 + 1;

          iVar21 = iVar21 + -1;

        } while (iVar21 != 0);

      }

      if (pcStack0000000c != (char *)0x0) {

        puVar14 = (undefined4 *)FUN_0053a700();

        puVar10[0x117] = puVar14;

        for (iVar21 = ((int)pcStack0000000c * 9 & 0x1fffffffU) << 1; iVar21 != 0;

            iVar21 = iVar21 + -1) {

          *puVar14 = 0;

          puVar14 = puVar14 + 1;

        }

        iVar22 = 0;

        for (iVar21 = 0; iVar21 != 0; iVar21 = iVar21 + -1) {

          *(undefined1 *)puVar14 = 0;

          puVar14 = (undefined4 *)((int)puVar14 + 1);

        }

        puVar10[0x116] = pcStack0000000c;

        if (0 < (int)pcStack0000000c) {

          uStack00000008 = 0;

          do {

            FUN_0053ca70();

            if (puVar10[*(int *)(&stack0x00000ca8 + iVar22 * 4) + 2] == 0) {

              *(undefined4 *)(uStack00000008 + puVar10[0x117]) = 0xffffffff;

            }

            else {

              __ftol();

              FUN_0053be00();

              in_stack_00000020 = (undefined4 *)FUN_0053cb50();

              uVar11 = *(undefined4 *)(&stack0x000008a8 + iVar22 * 4);

              FUN_0053be00();

              iVar21 = FUN_0053cb50();

              if ((in_stack_00000020 == (undefined4 *)0x0) || (iVar21 == 0)) {

                *(undefined4 *)(uStack00000008 + puVar10[0x117]) = 0xffffffff;

                FUN_00542f27();

                FUN_0051ea20();

              }

              else {

                (*(code *)PTR_FUN_00580c1c)();

                (*(code *)PTR_FUN_00580c18)();

                *(undefined4 *)(puVar10[0x117] + uStack00000008) = uVar11;

              }

            }

            iVar22 = iVar22 + 1;

            uStack00000008 = uStack00000008 + 0x48;

          } while (iVar22 < (int)pcStack0000000c);

        }

      }

      if ((puStack00000010 != (undefined4 *)0x0) && (uVar35 != 0)) {

        puVar12 = (uint *)FUN_0053a700();

        *(uint **)((int)puStack00000010 + 0x24) = puVar12;

        *puVar12 = uVar35;

        puVar10 = *(undefined4 **)((int)puStack00000010 + 0x24);

        puVar14 = (undefined4 *)&stack0x000000a8;

        for (iVar21 = (uVar35 & 0x7ffffff) << 3; puVar10 = puVar10 + 1, iVar21 != 0;

            iVar21 = iVar21 + -1) {

          *puVar10 = *puVar14;

          puVar14 = puVar14 + 1;

        }

        for (iVar21 = 0; iVar21 != 0; iVar21 = iVar21 + -1) {

          *(undefined1 *)puVar10 = *(undefined1 *)puVar14;

          puVar14 = (undefined4 *)((int)puVar14 + 1);

          puVar10 = (undefined4 *)((int)puVar10 + 1);

        }

      }

      iStack00000014 = iStack00000014 + 1;

    } while (iStack00000014 < iVar20);

  }

  iVar20 = *piStack0000001c;

  if (0 < iVar20) {

    in_stack_00000020 = (undefined4 *)FUN_0053a700();

    puVar10 = &DAT_00632d54;

    for (puVar14 = DAT_00632d54; puVar14 != (undefined4 *)0x0; puVar14 = (undefined4 *)*puVar14) {

      puVar10 = puVar14;

    }

    *puVar10 = in_stack_00000020;

    puVar10 = in_stack_00000020;

    for (uVar19 = iVar20 * 0x304 + 8U >> 2; uVar19 != 0; uVar19 = uVar19 - 1) {

      *puVar10 = 0;

      puVar10 = puVar10 + 1;

    }

    for (iVar21 = 0; iVar21 != 0; iVar21 = iVar21 + -1) {

      *(undefined1 *)puVar10 = 0;

      puVar10 = (undefined4 *)((int)puVar10 + 1);

    }

    in_stack_00000020[1] = iVar20;

  }

  iStack00000014 = 0;

  if (iVar20 < 1) {

LAB_004af20c:

    mem_free_tagged();

    return;

  }

LAB_004af232:

  piStack0000001c = piStack0000001c + 1;

  iVar21 = *piStack0000001c;

  obj = (OBJECT *)(in_stack_00000020 + iStack00000014 * 0xc1 + 2);

  FUN_004973c0(obj);

  dVar18 = *(dword *)(iVar21 + (int)piVar9);

  FUN_00497d70();

  obj->field_4 = dVar18;

  if (dVar18 == 0) {

    DAT_00632d58 = obj;

  }

  pdVar16 = &obj->field_10;

  iVar22 = 4;

  do {

    *pdVar16 = 0xfe;

    pdVar16 = pdVar16 + 9;

    iVar22 = iVar22 + -1;

  } while (iVar22 != 0);

  pcStack0000000c = &stack0x00000ea8;

  *(undefined4 *)&obj->field_0xc4 = 0x3f800000;

  pfVar31 = (float *)((dword *)(iVar21 + (int)piVar9) + 1);

switchD_004af2c0_caseD_24:

  pfVar32 = pfVar31;

  pfVar30 = (float *)((int)pfVar32 + 1);

  pfVar31 = pfVar30;

  switch(*(undefined1 *)pfVar32) {

  case 1:

    pfVar31 = (float *)((int)pfVar32 + 5);

    dVar18 = FUN_00497d20();

    obj->field_8 = dVar18;

    if ((dVar18 != 0) && (*(int *)(dVar18 + 0x400) != 0)) {

      fVar33 = *(float *)(*(int *)(dVar18 + 0x400) + 0x58);

      obj->gap_1EC = (dword)fVar33;

      if (fVar33 < 1.0) {

        obj->gap_1EC = 0x3f800000;

      }

      obj->field_1E8 = (dword)((float)obj->gap_1EC * 0.8);

      *(float *)&obj->field_0x1e4 = (float)obj->gap_1EC * 0.2;

    }

    goto switchD_004af2c0_caseD_24;

  case 2:

    pfVar32 = (float *)((int)pfVar32 + 5);

    if (*pfVar30 == 0.0) {

      *(undefined4 *)&obj->field_0x2e4 = 0;

      pfVar30 = pfVar32;

    }

    else {

      *(float *)&obj->field_0x2e4 = 1.0 / *pfVar30;

      pfVar30 = pfVar32;

    }

    do {

      cVar1 = *(char *)pfVar30;

      pfVar30 = (float *)((int)pfVar30 + 1);

    } while (cVar1 != '\0');

    if (*(char *)pfVar32 == '\0') {

      *(undefined4 *)&obj->field_0x2e0 = 0;

    }

    else {

      uVar11 = main_texture_00508750();

      *(undefined4 *)&obj->field_0x2e0 = uVar11;

    }

    dVar18 = obj->field_4;

    if (((((dVar18 != 0x101) && (dVar18 != 0x3e4)) &&

         ((dVar18 != 0x3e5 && ((dVar18 != 0x3e6 && (dVar18 != 999)))))) && (dVar18 != 0x405)) &&

       (pfVar31 = pfVar30, dVar18 != 0x406)) goto switchD_004af2c0_caseD_24;

switchD_004af2c0_caseD_54:

    obj->acc_grenade_do_stopped = obj->acc_grenade_do_stopped | 0x80000000;

    pfVar31 = pfVar30;

    goto switchD_004af2c0_caseD_24;

  case 3:

    if (*pfVar30 == 0.0) {

      *(undefined4 *)&obj->field_0x2e4 = 0;

    }

    else {

      *(float *)&obj->field_0x2e4 = 1.0 / *pfVar30;

    }

    uVar11 = *(undefined4 *)((int)pfVar32 + 5);

    uVar13 = *(undefined4 *)((int)pfVar32 + 9);

    puVar10 = (undefined4 *)FUN_0053a700();

    puVar10[1] = 0;

    puVar10[2] = 0;

    *puVar10 = s_Dynamic_shadow_texture_0055ca88;

    puVar10[3] = uVar11;

    puVar10[4] = uVar13;

    puVar10[6] = 5;

    puVar10[5] = 5;

    *(undefined1 *)((int)puVar10 + 0x1d) = 0;

    *(undefined1 *)(puVar10 + 7) = 0x20;

    *(undefined2 *)((int)puVar10 + 0x1e) = 0x80;

    *(undefined4 **)&obj->field_0x2e0 = puVar10;

    pfVar31 = (float *)((int)pfVar32 + 0xd);

    goto switchD_004af2c0_caseD_24;

  case 4:

    obj->field_0x1f6 = 1;

    obj->field_194 = (dword)*pfVar30;

    dVar18 = obj->field_4;

    obj->field_190 = *(dword *)((int)pfVar32 + 5);

    if ((((dVar18 == 2) || (dVar18 == 3)) || (dVar18 == 1)) || (dVar18 == 0xd7)) {

      obj->acc_grenade_do_stopped = obj->acc_grenade_do_stopped | 0x40000;

    }

    obj->acc_grenade_do_stopped = obj->acc_grenade_do_stopped | 0x400000;

    pfVar31 = (float *)((int)pfVar32 + 9);

    goto switchD_004af2c0_caseD_24;

  case 5:

    obj->field_1A0 = (dword)*pfVar30;

    pfVar31 = (float *)((int)pfVar32 + 5);

    goto switchD_004af2c0_caseD_24;

  case 6:

    obj->acc_TurretShoot = (dword)*pfVar30;

    pfVar31 = (float *)((int)pfVar32 + 5);

    goto switchD_004af2c0_caseD_24;

  case 7:

    obj->field_19C = (dword)*pfVar30;

    pfVar31 = (float *)((int)pfVar32 + 5);

    goto switchD_004af2c0_caseD_24;

  case 8:

    obj->field_1A8 = (dword)*pfVar30;

    obj->field_1A4 = *(dword *)((int)pfVar32 + 5);

    pfVar31 = (float *)((int)pfVar32 + 9);

    goto switchD_004af2c0_caseD_24;

  case 9:

    obj->field_1AC = (dword)*pfVar30;

    pfVar31 = (float *)((int)pfVar32 + 5);

    goto switchD_004af2c0_caseD_24;

  case 10:

    obj->acc_grenade_do_stopped = (dword)*pfVar30;

    pfVar31 = (float *)((int)pfVar32 + 5);

    goto switchD_004af2c0_caseD_24;

  case 0xb:

    obj->field_1B8 = (dword)*pfVar30;

    pfVar31 = (float *)((int)pfVar32 + 5);

    goto switchD_004af2c0_caseD_24;

  case 0xc:

    FUN_00542f27();

    FUN_00425eb0();

  case 0x38:

    pfVar31 = (float *)((int)pfVar32 + 0xd);

    goto switchD_004af2c0_caseD_24;

  case 0xd:

    obj->field_1B4 = (dword)*pfVar30;

    pfVar31 = (float *)((int)pfVar32 + 5);

    goto switchD_004af2c0_caseD_24;

  default:

    FUN_00542f27();

    FUN_0051ea20();

    return;

  case 0x13:

    FUN_004034a0();

    pfVar31 = (float *)((int)pfVar32 + 2);

    goto switchD_004af2c0_caseD_24;

  case 0x14:

    obj->acc_grenade_do_stopped = obj->acc_grenade_do_stopped | 2;

    goto switchD_004af2c0_caseD_24;

  case 0x15:

    obj->acc_popup_pre_logic = (dword)*pfVar30;

    pfVar31 = (float *)((int)pfVar32 + 5);

    goto switchD_004af2c0_caseD_24;

  case 0x16:

    obj->acc_grenade_do_stopped = obj->acc_grenade_do_stopped | 4;

    goto switchD_004af2c0_caseD_24;

  case 0x17:

    *(float *)&obj->field_0xc4 = *pfVar30;

    pfVar31 = (float *)((int)pfVar32 + 5);

    goto switchD_004af2c0_caseD_24;

  case 0x18:

    obj->acc_grenade_do_stopped = obj->acc_grenade_do_stopped | 8;

    goto switchD_004af2c0_caseD_24;

  case 0x19:

    obj->gap_1BC = (dword)*pfVar30;

    pfVar31 = (float *)((int)pfVar32 + 5);

    goto switchD_004af2c0_caseD_24;

  case 0x1a:

    dVar18 = obj->field_1D8;

    if ((int)dVar18 < 0x10) {

      *(float *)(&stack0x00000044 + dVar18 * 4) = *pfVar30;

      obj->field_1D8 = dVar18 + 1;

      pfVar31 = (float *)((int)pfVar32 + 5);

    }

    else {

      FUN_0051ea20();

      pfVar31 = (float *)((int)pfVar32 + 5);

    }

    goto switchD_004af2c0_caseD_24;

  case 0x1b:

    *(uint *)&obj->field_0xd8 = *(uint *)&obj->field_0xd8 | 0x10;

    goto switchD_004af2c0_caseD_24;

  case 0x1c:

    pfVar31 = (float *)((int)pfVar32 + 9);

    goto switchD_004af2c0_caseD_24;

  case 0x1d:

    obj->acc_grenade_do_stopped = obj->acc_grenade_do_stopped | 0x40;

    goto switchD_004af2c0_caseD_24;

  case 0x1e:

    object_change_ospec();

    pfVar31 = (float *)((int)pfVar32 + 2);

    goto switchD_004af2c0_caseD_24;

  case 0x1f:

    iVar21 = *(int *)&obj->field_0x1e0;

    if (iVar21 == 2) {

      iVar21 = *(int *)&obj->field_0x100;

      uVar11 = FUN_00497d20();

      *(undefined4 *)(iVar21 + 0x6c) = uVar11;

      *(undefined4 *)(iVar21 + 0x70) = *(undefined4 *)((int)pfVar32 + 5);

      pfVar30 = (float *)((int)pfVar32 + 0xd);

      *(undefined4 *)(iVar21 + 0x74) = *(undefined4 *)((int)pfVar32 + 9);

      *(float *)(iVar21 + 0x78) = *pfVar30;

      goto switchD_004af2c0_caseD_32;

    }

    if (iVar21 == 1) {

      iVar21 = *(int *)&obj->field_0x100;

      uVar11 = FUN_00497d20();

      *(undefined4 *)(iVar21 + 0xa0) = uVar11;

      *(undefined4 *)(iVar21 + 0xa8) = *(undefined4 *)((int)pfVar32 + 5);

      *(undefined4 *)(iVar21 + 0xac) = *(undefined4 *)((int)pfVar32 + 9);

      *(undefined4 *)(iVar21 + 0xb0) = *(undefined4 *)((int)pfVar32 + 0xd);

      pfVar31 = (float *)((int)pfVar32 + 0x11);

    }

    else if (iVar21 == 3) {

      iVar21 = *(int *)&obj->field_0x100;

      uVar11 = FUN_00497d20();

      *(undefined4 *)(iVar21 + 0xfb4) = uVar11;

      *(undefined4 *)(iVar21 + 0xfb8) = *(undefined4 *)((int)pfVar32 + 5);

      *(undefined4 *)(iVar21 + 0xfbc) = *(undefined4 *)((int)pfVar32 + 9);

      *(undefined4 *)(iVar21 + 0xfc0) = *(undefined4 *)((int)pfVar32 + 0xd);

      pfVar31 = (float *)((int)pfVar32 + 0x11);

    }

    else {

      FUN_0051ea20();

      pfVar31 = (float *)((int)pfVar32 + 0x11);

    }

    goto switchD_004af2c0_caseD_24;

  case 0x20:

    obj->acc_grenade_do_stopped = obj->acc_grenade_do_stopped | 0x80;

    goto switchD_004af2c0_caseD_24;

  case 0x21:

    obj->field_1E8 = (dword)*pfVar30;

    obj->gap_1EC = *(dword *)((int)pfVar32 + 5);

    *(float *)&obj->field_0x1e4 = (float)obj->field_1E8 * 0.5;

    pfVar31 = (float *)((int)pfVar32 + 9);

    goto switchD_004af2c0_caseD_24;

  case 0x22:

    obj->acc_grenade_do_stopped = obj->acc_grenade_do_stopped | 0x800;

    goto switchD_004af2c0_caseD_24;

  case 0x23:

    obj->acc_grenade_do_stopped = obj->acc_grenade_do_stopped | 0x1000;

  case 0x24:

  case 0x3f:

  case 0x43:

    goto switchD_004af2c0_caseD_24;

  case 0x25:

    obj->field_1FC = (dword)*pfVar30;

    pfVar31 = (float *)((int)pfVar32 + 5);

    goto switchD_004af2c0_caseD_24;

  case 0x26:

    obj->field_0x1f7 = *(undefined1 *)pfVar30;

    *(undefined4 *)&obj->field_0x1f8 = *(undefined4 *)((int)pfVar32 + 5);

    pfVar31 = (float *)((int)pfVar32 + 9);

    goto switchD_004af2c0_caseD_24;

  case 0x27:

    FUN_0051ea20();

    goto switchD_004af2c0_caseD_24;

  case 0x28:

    if (*(int *)&obj->field_0x1e0 == 1) {

      iVar21 = *(int *)&obj->field_0x100;

      uVar11 = FUN_00497d20();

      *(undefined4 *)(iVar21 + 0xa4) = uVar11;

      *(undefined4 *)(iVar21 + 0xb4) = *(undefined4 *)((int)pfVar32 + 5);

      *(undefined4 *)(iVar21 + 0xb8) = *(undefined4 *)((int)pfVar32 + 9);

      *(undefined4 *)(iVar21 + 0xbc) = *(undefined4 *)((int)pfVar32 + 0xd);

      pfVar31 = (float *)((int)pfVar32 + 0x11);

    }

    else {

      FUN_0051ea20();

      pfVar31 = (float *)((int)pfVar32 + 0x11);

    }

    goto switchD_004af2c0_caseD_24;

  case 0x29:

    *(float *)&obj->field_0x1f0 = *pfVar30;

    pfVar31 = (float *)((int)pfVar32 + 5);

    goto switchD_004af2c0_caseD_24;

  case 0x2a:

    goto switchD_004af2c0_caseD_2a;

  case 0x2b:

    obj->acc_grenade_do_stopped = obj->acc_grenade_do_stopped | 0x100;

    goto switchD_004af2c0_caseD_24;

  case 0x2c:

    if (pcStack0000000c != &stack0x00000ea8) {

      *pcStack0000000c = '\0';

      pcStack0000000c = pcStack0000000c + 1;

    }

    do {

      cVar1 = *(char *)pfVar30;

      *pcStack0000000c = cVar1;

      pcStack0000000c = pcStack0000000c + 1;

      pfVar30 = (float *)((int)pfVar30 + 1);

      pfVar31 = pfVar30;

    } while (cVar1 != '\0');

    goto switchD_004af2c0_caseD_24;

  case 0x2d:

    do {

      cVar1 = *(char *)pfVar30;

      *pcStack0000000c = cVar1;

      pcStack0000000c = pcStack0000000c + 1;

      pfVar30 = (float *)((int)pfVar30 + 1);

      pfVar31 = pfVar30;

    } while (cVar1 != '\0');

    goto switchD_004af2c0_caseD_24;

  case 0x2e:

    obj->acc_grenade_do_stopped = obj->acc_grenade_do_stopped | 0x600;

    goto switchD_004af2c0_caseD_24;

  case 0x2f:

    obj->acc_grenade_do_stopped = obj->acc_grenade_do_stopped | 0x10000;

    goto switchD_004af2c0_caseD_24;

  case 0x30:

    obj->gap_228 = (dword)*pfVar30;

    pfVar31 = (float *)((int)pfVar32 + 5);

    goto switchD_004af2c0_caseD_24;

  case 0x31:

    dVar18 = __ftol();

    if (obj->acc_grenade_do_stopped == dVar18) {

      *(float *)&obj->field_0x1c0 = *pfVar30;

      dVar18 = __ftol();

      obj->acc_grenade_do_stopped = dVar18;

      pfVar31 = (float *)((int)pfVar32 + 5);

    }

    else {

      *(float *)&obj->field_0x1c0 = *pfVar30;

      pfVar31 = (float *)((int)pfVar32 + 5);

    }

    goto switchD_004af2c0_caseD_24;

  case 0x32:

  case 0x37:

  case 0x3e:

switchD_004af2c0_caseD_32:

    pfVar31 = pfVar30 + 1;

    goto switchD_004af2c0_caseD_24;

  case 0x33:

    if ((*pfVar30 != 0.0) || (*(float *)((int)pfVar32 + 5) != 0.0)) {

      FUN_0051ea20();

    }

    obj->acc_grenade_do_stopped = obj->acc_grenade_do_stopped | 0x80000;

    pfVar31 = (float *)((int)pfVar32 + 9);

    goto switchD_004af2c0_caseD_24;

  case 0x34:

    if ((*pfVar30 != 0.0) || (*(float *)((int)pfVar32 + 5) != 0.0)) {

      FUN_0051ea20();

    }

    obj->acc_grenade_do_stopped = obj->acc_grenade_do_stopped | 0x100000;

    pfVar31 = (float *)((int)pfVar32 + 9);

    goto switchD_004af2c0_caseD_24;

  case 0x35:

    if ((*pfVar30 != 0.0) || (*(float *)((int)pfVar32 + 5) != 0.0)) {

      FUN_0051ea20();

    }

    obj->acc_grenade_do_stopped = obj->acc_grenade_do_stopped | 0x200000;

    pfVar31 = (float *)((int)pfVar32 + 9);

    goto switchD_004af2c0_caseD_24;

  case 0x36:

    obj->field_0x1f6 = *(undefined1 *)pfVar30;

    pfVar31 = (float *)((int)pfVar32 + 2);

    goto switchD_004af2c0_caseD_24;

  case 0x39:

    fVar33 = *pfVar30;

    pfVar30 = (float *)((int)pfVar32 + 5);

    obj->field_0x1f5 = SUB41(fVar33,0);

switchD_004af2c0_caseD_2a:

    obj->acc_grenade_do_stopped = obj->acc_grenade_do_stopped | 0x20000;

    pfVar31 = pfVar30;

    goto switchD_004af2c0_caseD_24;

  case 0x3a:

    obj->acc_popup_pre_logic = (dword)-*(float *)(*(int *)(obj->field_8 + 0x400) + 0x4c);

    goto switchD_004af2c0_caseD_24;

  case 0x3b:

    obj->field_18C = (dword)*pfVar30;

    pfVar31 = (float *)((int)pfVar32 + 5);

    goto switchD_004af2c0_caseD_24;

  case 0x3c:

    iVar21 = *(int *)&obj->field_0x1e0;

    if (((iVar21 == 6) || (iVar21 == 0x2b)) || (iVar21 == 0x39)) {

      iVar21 = *(int *)&obj->field_0x100;

      *(float *)(iVar21 + 0x10) = *pfVar30;

      *(undefined4 *)(iVar21 + 0xc) = *(undefined4 *)((int)pfVar32 + 5);

      *(undefined4 *)(iVar21 + 0x18) = *(undefined4 *)((int)pfVar32 + 9);

      *(undefined4 *)(iVar21 + 0x14) = *(undefined4 *)((int)pfVar32 + 0xd);

      fVar33 = (*(float *)(iVar21 + 0x10) - *(float *)(iVar21 + 0x18)) /

               (*(float *)(iVar21 + 0xc) - *(float *)(iVar21 + 0x14));

      *(float *)(iVar21 + 0x1c) = fVar33;

      *(float *)(iVar21 + 0x20) = *(float *)(iVar21 + 0x10) - fVar33 * *(float *)(iVar21 + 0xc);

      pfVar31 = (float *)((int)pfVar32 + 0x11);

    }

    else {

      FUN_0051ea20();

      pfVar31 = (float *)((int)pfVar32 + 0x11);

    }

    goto switchD_004af2c0_caseD_24;

  case 0x3d:

    obj->acc_grenade_do_stopped = obj->acc_grenade_do_stopped | 0x1000000;

    goto switchD_004af2c0_caseD_24;

  case 0x40:

  case 0x46:

    obj->gap_1CC = obj->gap_1CC | 1;

    goto switchD_004af2c0_caseD_24;

  case 0x41:

    *(uint *)&obj->field_0xd8 = *(uint *)&obj->field_0xd8 | 0x40000010;

    obj->acc_grenade_do_stopped = obj->acc_grenade_do_stopped | 0x8000e00;

    goto switchD_004af2c0_caseD_24;

  case 0x42:

    FUN_00542f27();

    FUN_00425eb0();

    pfVar31 = (float *)((int)pfVar32 + 0xd);

    goto switchD_004af2c0_caseD_24;

  case 0x44:

    fVar33 = *pfVar30;

    pfVar30 = *(float **)&obj->field_0x100;

    pfVar31 = (float *)((int)pfVar32 + 5);

    if (pfVar30 == (float *)0x0) {

      FUN_00542f27();

      FUN_0051ea20();

      pfVar31 = pfVar31 + (int)fVar33;

    }

    else if (0 < (int)fVar33) {

      do {

        *pfVar30 = *pfVar31;

        pfVar31 = pfVar31 + 1;

        pfVar30 = pfVar30 + 1;

        fVar33 = (float)((int)fVar33 - 1);

      } while (fVar33 != 0.0);

    }

    goto switchD_004af2c0_caseD_24;

  case 0x45:

    obj->gap_200 = (dword)*pfVar30;

    pfVar31 = (float *)((int)pfVar32 + 5);

    goto switchD_004af2c0_caseD_24;

  case 0x47:

    obj->gap_1CC = obj->gap_1CC | 0x3c;

    goto switchD_004af2c0_caseD_24;

  case 0x48:

    obj->gap_1CC = obj->gap_1CC | 0x3c0;

    goto switchD_004af2c0_caseD_24;

  case 0x49:

    obj->gap_1CC = obj->gap_1CC | 0x3c00;

    goto switchD_004af2c0_caseD_24;

  case 0x4a:

    obj->gap_1CC = obj->gap_1CC | 2;

    goto switchD_004af2c0_caseD_24;

  case 0x4b:

    obj->gap_1CC = obj->gap_1CC | 0x3c000;

    goto switchD_004af2c0_caseD_24;

  case 0x4c:

    obj->gap_1CC = obj->gap_1CC | 0x3c0000;

    goto switchD_004af2c0_caseD_24;

  case 0x4d:

    obj->gap_1CC = obj->gap_1CC | 0x3c00000;

    goto switchD_004af2c0_caseD_24;

  case 0x4e:

    obj->acc_popup_pre_logic = obj->acc_popup_pre_logic | 0xf0;

    goto switchD_004af2c0_caseD_24;

  case 0x4f:

    obj->acc_popup_pre_logic = obj->acc_popup_pre_logic | 0xf;

    goto switchD_004af2c0_caseD_24;

  case 0x50:

    obj->acc_popup_pre_logic = obj->acc_popup_pre_logic | 0xf00;

    goto switchD_004af2c0_caseD_24;

  case 0x51:

    *(uint *)&obj->field_0xd8 = *(uint *)&obj->field_0xd8 | 0x40000010;

    obj->acc_grenade_do_stopped = obj->acc_grenade_do_stopped | 0x28000e00;

    goto switchD_004af2c0_caseD_24;

  case 0x52:

    *(uint *)&obj->field_0xd8 = *(uint *)&obj->field_0xd8 | 0x20000;

    goto switchD_004af2c0_caseD_24;

  case 0x53:

    *(uint *)&obj->field_0xd8 = *(uint *)&obj->field_0xd8 | 2;

    goto switchD_004af2c0_caseD_24;

  case 0x54:

    goto switchD_004af2c0_caseD_54;

  case 0x55:

    *(uint *)&obj->field_0xd8 = *(uint *)&obj->field_0xd8 | 0x40000000;

    goto switchD_004af2c0_caseD_24;

  case 0x56:

    obj->gap_1CC = obj->gap_1CC | 4;

    goto switchD_004af2c0_caseD_24;

  case 0x57:

    do {

      pfVar31 = pfVar30;

      pfVar30 = (float *)((int)pfVar31 + 1);

    } while (*(char *)pfVar31 != '\0');

    fVar33 = *(float *)((int)pfVar31 + 1);

    dVar18 = Main_fx_00447210();

    obj->acc_kabuto_new_offspring = dVar18;

    obj->field_0x2f8 = SUB41(fVar33,0);

    pfVar31 = (float *)((int)pfVar31 + 5);

    goto switchD_004af2c0_caseD_24;

  case 0x58:

    obj->gap_1CC = obj->gap_1CC | 0x10;

    goto switchD_004af2c0_caseD_24;

  case 0x59:

    obj->gap_1CC = obj->gap_1CC | 0x40;

    goto switchD_004af2c0_caseD_24;

  case 0x5a:

    obj->gap_1CC = obj->gap_1CC | 0x80;

    goto switchD_004af2c0_caseD_24;

  case 0x5b:

    obj->gap_1CC = obj->gap_1CC | 0x100;

    goto switchD_004af2c0_caseD_24;

  case 0x5c:

    obj->gap_1CC = obj->gap_1CC | 0x400;

    goto switchD_004af2c0_caseD_24;

  case 0x5d:

    obj->gap_1CC = obj->gap_1CC | 0x800;

    goto switchD_004af2c0_caseD_24;

  case 0x5e:

    obj->gap_1CC = obj->gap_1CC | 0x1000;

    goto switchD_004af2c0_caseD_24;

  case 0x5f:

    obj->gap_1CC = obj->gap_1CC | 0x4000;

    goto switchD_004af2c0_caseD_24;

  case 0x60:

    obj->gap_1CC = obj->gap_1CC | 0x8000;

    goto switchD_004af2c0_caseD_24;

  case 0x61:

    obj->gap_1CC = obj->gap_1CC | 0x10000;

    goto switchD_004af2c0_caseD_24;

  case 0x62:

    obj->gap_1CC = obj->gap_1CC | 0x40000;

    goto switchD_004af2c0_caseD_24;

  case 99:

    obj->gap_1CC = obj->gap_1CC | 0x80000;

    goto switchD_004af2c0_caseD_24;

  case 100:

    obj->gap_1CC = obj->gap_1CC | 0x100000;

    goto switchD_004af2c0_caseD_24;

  case 0x65:

    obj->gap_1CC = obj->gap_1CC | 0x400000;

    goto switchD_004af2c0_caseD_24;

  case 0x66:

    obj->gap_1CC = obj->gap_1CC | 0x800000;

    goto switchD_004af2c0_caseD_24;

  case 0x67:

    obj->gap_1CC = obj->gap_1CC | 0x1000000;

    goto switchD_004af2c0_caseD_24;

  case 0x68:

    obj->acc_popup_pre_logic = obj->acc_popup_pre_logic | 0x10;

    goto switchD_004af2c0_caseD_24;

  case 0x69:

    obj->acc_grenade_do_stopped = (dword)*pfVar30;

    pfVar31 = (float *)((int)pfVar32 + 5);

    goto switchD_004af2c0_caseD_24;

  case 0x6a:

    obj->acc_popup_pre_logic = obj->acc_popup_pre_logic | 0x40;

    goto switchD_004af2c0_caseD_24;

  case 0x6b:

    obj->acc_popup_pre_logic = obj->acc_popup_pre_logic | 1;

    goto switchD_004af2c0_caseD_24;

  case 0x6c:

    obj->acc_popup_pre_logic = obj->acc_popup_pre_logic | 2;

    goto switchD_004af2c0_caseD_24;

  case 0x6d:

    obj->acc_popup_pre_logic = obj->acc_popup_pre_logic | 4;

    goto switchD_004af2c0_caseD_24;

  case 0x6e:

    obj->acc_popup_pre_logic = obj->acc_popup_pre_logic | 0x100;

    goto switchD_004af2c0_caseD_24;

  case 0x6f:

    obj->acc_popup_pre_logic = obj->acc_popup_pre_logic | 0x200;

    goto switchD_004af2c0_caseD_24;

  case 0x70:

    obj->acc_popup_pre_logic = obj->acc_popup_pre_logic | 0x400;

    goto switchD_004af2c0_caseD_24;

  case 0x71:

    obj->acc_popup_pre_logic = obj->acc_popup_pre_logic | 0x20;

    goto switchD_004af2c0_caseD_24;

  case 0x72:

    obj->gap_1CC = obj->gap_1CC | 8;

    goto switchD_004af2c0_caseD_24;

  case 0x73:

    obj->gap_1CC = obj->gap_1CC | 0x20;

    goto switchD_004af2c0_caseD_24;

  case 0x74:

    obj->gap_1CC = obj->gap_1CC | 0x200;

    goto switchD_004af2c0_caseD_24;

  case 0x75:

    obj->gap_1CC = obj->gap_1CC | 0x2000;

    goto switchD_004af2c0_caseD_24;

  case 0x76:

    obj->gap_1CC = obj->gap_1CC | 0x20000;

    goto switchD_004af2c0_caseD_24;

  case 0x77:

    obj->gap_1CC = obj->gap_1CC | 0x200000;

    goto switchD_004af2c0_caseD_24;

  case 0x78:

    obj->gap_1CC = obj->gap_1CC | 0x2000000;

    goto switchD_004af2c0_caseD_24;

  case 0x79:

    obj->acc_popup_pre_logic = obj->acc_popup_pre_logic | 0x80;

    goto switchD_004af2c0_caseD_24;

  case 0x7a:

    if ((*(int *)&obj->field_0x1e0 == 0x65) ||

       (pfVar31 = (float *)((int)pfVar32 + 5), *(int *)&obj->field_0x1e0 == 0x3c)) {

      **(float **)&obj->field_0x100 = *pfVar30;

      pfVar31 = (float *)((int)pfVar32 + 5);

    }

    goto switchD_004af2c0_caseD_24;

  case 0x7b:

    do {

      cVar1 = *(char *)pfVar30;

      pfVar30 = (float *)((int)pfVar30 + 1);

    } while (cVar1 != '\0');

    if ((*(int *)&obj->field_0x1e0 == 0x65) ||

       (pfVar31 = pfVar30, *(int *)&obj->field_0x1e0 == 0x3c)) {

      iVar21 = *(int *)&obj->field_0x100;

      uVar11 = Main_fx_00447210();

      *(undefined4 *)(iVar21 + 4) = uVar11;

      pfVar31 = pfVar30;

    }

    goto switchD_004af2c0_caseD_24;

  case 0x7c:

    do {

      cVar1 = *(char *)pfVar30;

      pfVar30 = (float *)((int)pfVar30 + 1);

    } while (cVar1 != '\0');

    if ((*(int *)&obj->field_0x1e0 == 0x65) ||

       (pfVar31 = pfVar30, *(int *)&obj->field_0x1e0 == 0x3c)) {

      iVar21 = *(int *)&obj->field_0x100;

      uVar11 = Main_fx_00447210();

      *(undefined4 *)(iVar21 + 8) = uVar11;

      pfVar31 = pfVar30;

    }

    goto switchD_004af2c0_caseD_24;

  case 0x7d:

    obj->acc_grenade_do_stopped = obj->acc_grenade_do_stopped | 0x2000000;

    goto switchD_004af2c0_caseD_24;

  case 0x7e:

    obj->acc_grenade_do_stopped = obj->acc_grenade_do_stopped | 0x10000000;

    goto switchD_004af2c0_caseD_24;

  case 0x7f:

    obj->acc_popup_pre_logic = obj->acc_popup_pre_logic | 8;

    goto switchD_004af2c0_caseD_24;

  case 0x80:

    obj->acc_popup_pre_logic = obj->acc_popup_pre_logic | 0x800;

    goto switchD_004af2c0_caseD_24;

  case 0x81:

    fVar7 = *(float *)((int)pfVar32 + 5);

    fVar5 = *(float *)((int)pfVar32 + 9);

    fVar33 = *(float *)((int)pfVar32 + 0xd);

    fVar6 = *(float *)((int)pfVar32 + 0x11);

    pfVar31 = (float *)((int)pfVar32 + 0x15);

    if (*(int *)&obj->field_0x1e0 == 0x3a) {

      pfVar31 = *(float **)&obj->field_0x100;

      *pfVar31 = *pfVar30;

      pfVar31[5] = fVar33;

      pfVar31[1] = fVar7;

      pfVar31[2] = fVar5;

      pfVar31[6] = fVar6;

      pfVar31 = (float *)((int)pfVar32 + 0x15);

    }

    goto switchD_004af2c0_caseD_24;

  case 0x82:

    uVar13 = *(undefined4 *)((int)pfVar32 + 5);

    uVar11 = *(undefined4 *)((int)pfVar32 + 9);

    uVar17 = *(undefined4 *)((int)pfVar32 + 0xd);

    pfVar31 = (float *)((int)pfVar32 + 0x11);

    if (*(int *)&obj->field_0x1e0 == 0x3a) {

      iVar21 = *(int *)&obj->field_0x100;

      *(float *)(iVar21 + 0xc) = *pfVar30;

      *(undefined4 *)(iVar21 + 0x1c) = uVar11;

      *(undefined4 *)(iVar21 + 0x10) = uVar13;

      *(undefined4 *)(iVar21 + 0x20) = uVar17;

    }

    goto switchD_004af2c0_caseD_24;

  case 0x83:

    if ((*(int *)&obj->field_0x1e0 == 0x65) || (*(int *)&obj->field_0x1e0 == 0x3c)) {

      *(undefined4 *)(*(int *)&obj->field_0x100 + 0xc) = 1;

    }

    goto switchD_004af2c0_caseD_24;

  case 0x84:

    obj->gap_1CC = obj->gap_1CC | 0x4000000;

    goto switchD_004af2c0_caseD_24;

  case 0x85:

    do {

      pfVar32 = pfVar30;

      pfVar30 = (float *)((int)pfVar32 + 1);

    } while (*(char *)pfVar32 != '\0');

    fVar33 = *(float *)((int)pfVar32 + 1);

    uVar11 = *(undefined4 *)((int)pfVar32 + 5);

    uVar13 = *(undefined4 *)((int)pfVar32 + 9);

    pfVar31 = (float *)((int)pfVar32 + 0xd);

    if (*(int *)&obj->field_0x1e0 == 5) {

      puVar10 = *(undefined4 **)&obj->field_0x100;

      uVar17 = Main_fx_00447210();

      *puVar10 = uVar17;

      puVar10[1] = fVar33;

      puVar10[2] = uVar11;

      puVar10[3] = uVar13;

    }

    goto switchD_004af2c0_caseD_24;

  case 0x86:

    fVar33 = *pfVar30;

    pfVar31 = (float *)((int)pfVar32 + 5);

    do {

      pfVar30 = pfVar31;

      pfVar31 = (float *)((int)pfVar30 + 1);

    } while (*(char *)pfVar30 != '\0');

    fVar7 = *(float *)((int)pfVar30 + 5);

    pfVar31 = (float *)((int)pfVar30 + 9);

    if (*(int *)&obj->field_0x1e0 == 0x3a) {

      pfVar8 = *(float **)&obj->field_0x100;

      if ((int)pfVar8[0xd] < 10) {

        pfVar8[5] = *(float *)((int)pfVar30 + 1);

        *pfVar8 = fVar33;

        pfVar8[6] = fVar7;

        _strncpy((char *)(pfVar8 + (int)pfVar8[0xd] * 8 + 0xf),(char *)((int)pfVar32 + 5),0x20);

        pfVar8[0xd] = (float)((int)pfVar8[0xd] + 1);

      }

    }

    goto switchD_004af2c0_caseD_24;

  case 0x87:

    pfVar32 = pfVar30;

    do {

      pfVar31 = pfVar32;

      pfVar32 = (float *)((int)pfVar31 + 1);

    } while (*(char *)pfVar31 != '\0');

    fVar33 = *(float *)((int)pfVar31 + 1);

    uVar11 = *(undefined4 *)((int)pfVar31 + 5);

    pfVar31 = (float *)((int)pfVar31 + 9);

    if (*(int *)&obj->field_0x1e0 == 0x3a) {

      iVar21 = *(int *)&obj->field_0x100;

      if (*(int *)(iVar21 + 0x38) < 10) {

        _strncpy((char *)(*(int *)(iVar21 + 0x38) * 0x20 + 0x17c + iVar21),(char *)pfVar30,0x20);

        *(float *)(iVar21 + 0x1c) = fVar33;

        *(undefined4 *)(iVar21 + 0x20) = uVar11;

        *(int *)(iVar21 + 0x38) = *(int *)(iVar21 + 0x38) + 1;

      }

    }

    goto switchD_004af2c0_caseD_24;

  case 0x88:

    uVar11 = *(undefined4 *)((int)pfVar32 + 5);

    uVar13 = *(undefined4 *)((int)pfVar32 + 9);

    pfVar31 = (float *)((int)pfVar32 + 0xd);

    if (*(int *)&obj->field_0x1e0 == 5) {

      iVar21 = *(int *)&obj->field_0x100;

      *(float *)(iVar21 + 0x14) = *pfVar30;

      *(undefined4 *)(iVar21 + 0x18) = uVar11;

      *(undefined4 *)(iVar21 + 0x1c) = uVar13;

    }

    goto switchD_004af2c0_caseD_24;

  case 0x89:

    goto switchD_004af2c0_caseD_89;

  case 0xff:

    break;

  }

  if (pcStack0000000c != &stack0x00000ea8) {

    *pcStack0000000c = '\0';

    pcStack0000000c[1] = '\0';

    pcStack0000000c = pcStack0000000c + 2;

  }

  if (0 < (int)obj->field_1D8) {

    puVar14 = (undefined4 *)FUN_0053a700();

    obj->gap_1DC = (dword)puVar14;

    puVar10 = (undefined4 *)&stack0x00000044;

    for (uVar19 = obj->field_1D8 & 0x3fffffff; uVar19 != 0; uVar19 = uVar19 - 1) {

      *puVar14 = *puVar10;

      puVar10 = puVar10 + 1;

      puVar14 = puVar14 + 1;

    }

    for (iVar21 = 0; iVar21 != 0; iVar21 = iVar21 + -1) {

      *(undefined1 *)puVar14 = *(undefined1 *)puVar10;

      puVar10 = (undefined4 *)((int)puVar10 + 1);

      puVar14 = (undefined4 *)((int)puVar14 + 1);

    }

  }

  if (pcStack0000000c != &stack0x00000ea8) {

    puVar14 = (undefined4 *)FUN_0053a700();

    *(undefined4 **)&obj->field_0x204 = puVar14;

    puVar10 = (undefined4 *)&stack0x00000ea8;

    for (uVar19 = (uint)((int)pcStack0000000c - (int)&stack0x00000ea8) >> 2; uVar19 != 0;

        uVar19 = uVar19 - 1) {

      *puVar14 = *puVar10;

      puVar10 = puVar10 + 1;

      puVar14 = puVar14 + 1;

    }

    for (uVar19 = (int)pcStack0000000c - (int)&stack0x00000ea8 & 3; uVar19 != 0; uVar19 = uVar19 - 1

        ) {

      *(undefined1 *)puVar14 = *(undefined1 *)puVar10;

      puVar10 = (undefined4 *)((int)puVar10 + 1);

      puVar14 = (undefined4 *)((int)puVar14 + 1);

    }

  }

  iStack00000014 = iStack00000014 + 1;

  if (iVar20 <= iStack00000014) goto LAB_004af20c;

  goto LAB_004af232;

switchD_004af2c0_caseD_89:

  *(uint *)&obj->field_0xdc = *(uint *)&obj->field_0xdc | 0x1000000;

  goto switchD_004af2c0_caseD_24;

}

