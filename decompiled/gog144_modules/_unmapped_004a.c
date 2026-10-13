/* Giants 1.449 — module _unmapped_004a
 * 131 functions (116 named) — decompiled, names from PS2 symbols
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

      iVar2 = grid_dir_walk(local_8,local_c,param_1,local_4,&local_8,&local_c,&param_1);

      if (iVar2 != 0) {

        return 1;

      }

      iVar2 = iVar4;

      if ((-1 < iVar5) &&

         (iVar3 = grid_dir_walk(local_8,local_c,param_1,param_2,&local_8,&local_c,&param_1),

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

        iVar2 = grid_dir_walk(local_8,local_c,param_1,param_2,&local_8,&local_c,&param_1);

        if ((iVar2 != 0) ||

           ((iVar2 = iVar6, -1 < iVar5 &&

            (iVar3 = grid_dir_walk(local_8,local_c,param_1,local_4,&local_8,&local_c,&param_1),

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

/* ===== grid_dir_walk @ 0x004A0D00 ===== */
undefined1

grid_dir_walk(int param_1,int param_2,int param_3,int param_4,int *param_5,int *param_6,int *param_7

             )



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

  uVar1 = grid_get_conntype(param_1,param_2);

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

/* ===== path_flyer_calculate @ 0x004A1250 ===== */
/* PS2 candidate: path_flyer_calculate (conf 0.692) */



void path_flyer_calculate

               (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,float param_5,

               undefined4 param_6,undefined4 param_7,undefined4 param_8)



{

  main_path_004a0f40(param_1,param_2,param_3,param_4,param_5,

                     *(float *)(param_1 + 0x1e8) * *(float *)(param_1 + 0xc4) + param_5,param_6,

                     param_7,param_8);

  return;

}

/* ===== path_short_calculate @ 0x004A12A0 ===== */
/* PS2 candidate: path_short_calculate (conf 0.636) */



void path_short_calculate

               (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,

               undefined4 param_5,undefined4 param_6,undefined4 param_7)



{

  main_path_004a0f40(param_1,param_2,param_3,param_4,0,

                     *(float *)(param_1 + 0x1e8) * *(float *)(param_1 + 0xc4),param_5,param_6,

                     param_7);

  return;

}

/* ===== heap_siftup__FPP5ANODEi @ 0x004A12F0 ===== */
/* PS2 candidate: heap_siftup__FPP5ANODEi (conf 0.558) */



void heap_siftup__FPP5ANODEi(int param_1,int param_2)



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

/* ===== path_node_push @ 0x004A1330 ===== */
void path_node_push(int param_1)



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

/* ===== audio_register_sound_name @ 0x004A13C0 ===== */
int audio_register_sound_name(char *param_1)



{

  char cVar1;

  undefined4 uVar2;

  char *local_10;

  char *local_c;

  int local_8;

  

  Audio3DTestToneStop__Fv();

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

  uVar2 = crt_rdtsc();

  *(undefined4 *)(&DAT_005a0e80 + local_8 * 4) = uVar2;

  *(undefined4 *)(&DAT_005a0e00 + local_8 * 4) = 0;

  DAT_005a0ec4 = DAT_005a0ec4 | 1 << ((byte)local_8 & 0x1f);

  DAT_0055e9e8 = local_8;

  return local_8;

}

/* ===== crt_rdtsc @ 0x004A14A0 ===== */
undefined8 crt_rdtsc(void)



{

  undefined8 uVar1;

  

  uVar1 = rdtsc();

  return uVar1;

}

/* ===== Audio3DTestToneStop__Fv @ 0x004A14B0 ===== */
/* PS2 candidate: Audio3DTestToneStop__Fv (conf 0.51) */



void Audio3DTestToneStop__Fv(void)



{

  int iVar1;

  

  if (DAT_0055e9e8 != -1) {

    iVar1 = crt_rdtsc();

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

  Audio3DTestToneStop__Fv();

  return;

}

/* ===== PhysicsExZeroForce @ 0x004A1740 ===== */
/* PS2 candidate: PhysicsExInit (conf 0.605) */



void PhysicsExZeroForce(int param_1)



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

/* ===== PhysicsExCollisionPlane @ 0x004A17F0 ===== */
/* PS2 candidate: PhysicsExCollisionPlane (conf 0.511) */



void PhysicsExCollisionPlane(int param_1,float *param_2,float *param_3)



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

/* ===== PhysicsExCollisionPlane2_OLD__FP6OBJECTP3P3DN31P7PLANE3D @ 0x004A18D0 ===== */
/* PS2 candidate: PhysicsExCollisionPlane2_OLD__FP6OBJECTP3P3DN31P7PLANE3D (conf 0.551) */



void PhysicsExCollisionPlane2_OLD__FP6OBJECTP3P3DN31P7PLANE3D

               (int param_1,float *param_2,float *param_3,float *param_4,undefined4 param_5,

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

/* ===== obj_speed_sq_calc @ 0x004A1BD0 ===== */
void obj_speed_sq_calc(int param_1)



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

/* ===== obj_vel_reset @ 0x004A1C50 ===== */
void obj_vel_reset(int param_1)



{

  float *pfVar1;

  float fVar2;

  int iVar3;

  float fVar4;

  float10 fVar5;

  float10 fVar6;

  float10 fVar7;

  

  iVar3 = *(int *)(param_1 + 0x104);

  if (*(int *)(param_1 + 0x210) != 0) {

    if ((*(uint *)(param_1 + 0xdc) & 0x1000) == 0) {

      *(undefined4 *)(param_1 + 0x130) = 0;

      *(undefined4 *)(param_1 + 300) = 0;

      *(undefined4 *)(param_1 + 0x128) = 0;

      *(undefined4 *)(param_1 + 0x13c) = 0;

      *(undefined4 *)(param_1 + 0x138) = 0;

      *(undefined4 *)(param_1 + 0x134) = 0;

    }

    *(undefined4 *)(iVar3 + 0x20) = 0;

    *(undefined4 *)(iVar3 + 0x1c) = 0;

    *(undefined4 *)(iVar3 + 0x18) = 0;

    return;

  }

  fVar5 = (float10)FUN_00518b70(param_1,0);

  *(float *)(iVar3 + 0x14) = (float)fVar5;

  fVar6 = fVar5;

  if ((0.0 < *(float *)(iVar3 + 0x2c)) && ((float10)*(float *)(iVar3 + 0x2c) < fVar5)) {

    fVar6 = (float10)*(float *)(iVar3 + 0x2c);

  }

  *(undefined4 *)(iVar3 + 0x2c) = 0;

  pfVar1 = (float *)(param_1 + 0x128);

  *(float *)(param_1 + 0x134) = *pfVar1;

  *(undefined4 *)(param_1 + 0x138) = *(undefined4 *)(param_1 + 300);

  *(undefined4 *)(param_1 + 0x13c) = *(undefined4 *)(param_1 + 0x130);

  fVar7 = (float10)1.0 / (float10)*(float *)(iVar3 + 8);

  *pfVar1 = (float)(fVar7 * (float10)*(float *)(iVar3 + 0x18) * fVar6 + (float10)*pfVar1);

  *(float *)(param_1 + 300) =

       (float)(fVar7 * (float10)*(float *)(iVar3 + 0x1c) * fVar6 +

              (float10)*(float *)(param_1 + 300));

  fVar6 = fVar7 * (float10)*(float *)(iVar3 + 0x20) * fVar6 + (float10)*(float *)(param_1 + 0x130);

  *(float *)(param_1 + 0x130) = (float)fVar6;

  if ((*(float *)(iVar3 + 0x28) != 0.0) &&

     (fVar2 = (float)SQRT((float10)*pfVar1 * (float10)*pfVar1 +

                          (float10)*(float *)(param_1 + 300) * (float10)*(float *)(param_1 + 300) +

                          fVar6 * fVar6), fVar2 != 0.0)) {

    fVar4 = 1.0;

    if (*(float *)(iVar3 + 0x28) < fVar2) {

      fVar4 = *(float *)(iVar3 + 0x28) / fVar2;

    }

    *pfVar1 = fVar4 * *pfVar1;

    *(float *)(param_1 + 300) = fVar4 * *(float *)(param_1 + 300);

    *(float *)(param_1 + 0x130) = fVar4 * *(float *)(param_1 + 0x130);

  }

  *(float *)(param_1 + 0xa0) =

       (float)(((float10)*pfVar1 + (float10)*(float *)(param_1 + 0x134)) * fVar5 * (float10)0.5 +

              (float10)*(float *)(param_1 + 0xa0));

  *(float *)(param_1 + 0xa4) =

       (float)(((float10)*(float *)(param_1 + 0x138) + (float10)*(float *)(param_1 + 300)) * fVar5 *

               (float10)0.5 + (float10)*(float *)(param_1 + 0xa4));

  *(float *)(param_1 + 0xa8) =

       (float)(((float10)*(float *)(param_1 + 0x13c) + (float10)*(float *)(param_1 + 0x130)) * fVar5

               * (float10)0.5 + (float10)*(float *)(param_1 + 0xa8));

  *(undefined4 *)(iVar3 + 0x20) = 0;

  *(undefined4 *)(iVar3 + 0x1c) = 0;

  *(undefined4 *)(iVar3 + 0x18) = 0;

  return;

}

/* ===== obj_geom_process @ 0x004A1E30 ===== */
void obj_geom_process(int param_1)



{

  undefined4 *puVar1;

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

  undefined4 local_68;

  undefined4 local_64;

  float local_60;

  undefined4 local_5c;

  undefined4 local_58;

  float local_54;

  undefined4 local_50;

  undefined4 local_4c;

  undefined4 local_48;

  float local_44;

  float local_40;

  float local_3c;

  float local_38 [4];

  undefined4 local_28;

  int local_24;

  int local_20;

  float local_1c [5];

  int local_8;

  int local_4;

  

  local_64 = *(undefined4 *)(param_1 + 0xa4);

  local_54 = *(float *)(param_1 + 0xc4) * *(float *)(param_1 + 0x1d4);

  local_68 = *(undefined4 *)(param_1 + 0xa0);

  local_5c = *(undefined4 *)(param_1 + 0xac);

  local_60 = *(float *)(param_1 + 0xa8) - local_54;

  puVar1 = (undefined4 *)(param_1 + 0x128);

  local_58 = *(undefined4 *)(param_1 + 0xb0);

  local_54 = *(float *)(param_1 + 0xb4) - local_54;

  local_50 = *puVar1;

  local_4c = *(undefined4 *)(param_1 + 300);

  local_48 = *(undefined4 *)(param_1 + 0x130);

  puVar2 = *(uint **)(param_1 + 0x104);

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

      iVar7 = Det3x3__8geom_Mat(&local_44,local_38,local_1c,&DAT_0055ea40);

      if (iVar7 != 0) {

        *puVar1 = local_50;

        local_60 = *(float *)(param_1 + 0xa8) -

                   *(float *)(param_1 + 0xc4) * *(float *)(param_1 + 0x1d4);

        *(undefined4 *)(param_1 + 300) = local_4c;

        local_68 = *(undefined4 *)(param_1 + 0xa0);

        *(undefined4 *)(param_1 + 0x130) = local_48;

        local_64 = *(undefined4 *)(param_1 + 0xa4);

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

    fVar10 = (float10)PhysicsExCollisionPlane2_OLD__FP6OBJECTP3P3DN31P7PLANE3D

                                (param_1,&local_68,&local_5c,puVar1,param_1 + 0x134,local_38,1);

    local_6c = (float)fVar10;

    if ((float10)0.0 < fVar10) break;

    local_70 = local_70 + -1;

    *puVar2 = *puVar2 | 4;

  } while (local_70 != 0);

  if ((bVar6) && (0.0 < *(float *)(param_1 + 0x130))) {

    *(float *)(*(int *)(param_1 + 0x104) + 0x20) =

         *(float *)(*(int *)(param_1 + 0x104) + 0x20) - (float)puVar2[1] * 32.17405;

  }

  if (local_6c < 0.05) {

    *puVar2 = *puVar2 | 8;

  }

  DAT_0055ea3c = *(float *)(param_1 + 0x1e8) * *(float *)(param_1 + 0xc4);

  fVar10 = (float10)PhysicsExCollisionPlane2_OLD__FP6OBJECTP3P3DN31P7PLANE3D

                              (param_1,&local_68,&local_5c,puVar1,param_1 + 0x134,&DAT_0055ea30,1);

  if ((float10)0.05 <= fVar10) {

    if ((~*puVar2 & 0x20) != 0) {

      *(float *)(param_1 + 0x144) = local_38[0];

      *(undefined4 *)(param_1 + 0x140) = local_28;

      *(float *)(param_1 + 0x148) = local_38[1];

      *(float *)(param_1 + 0x14c) = local_38[2];

      *(float *)(param_1 + 0x150) = local_38[3];

    }

  }

  else {

    *puVar2 = *puVar2 | 0x40;

    *(float *)(param_1 + 0x144) = DAT_0055ea30;

    *(undefined4 *)(param_1 + 0x148) = DAT_0055ea34;

    *(undefined4 *)(param_1 + 0x14c) = DAT_0055ea38;

    *(float *)(param_1 + 0x150) = DAT_0055ea3c;

    *(float *)(param_1 + 0x140) =

         -((*(float *)(param_1 + 0xa0) * *(float *)(param_1 + 0x144) +

            *(float *)(param_1 + 0x148) * *(float *)(param_1 + 0xa4) + *(float *)(param_1 + 0x150))

          / *(float *)(param_1 + 0x14c));

  }

  fVar3 = *(float *)(param_1 + 0xc4) * *(float *)(param_1 + 0x1d4);

  *(undefined4 *)(param_1 + 0xa0) = local_68;

  *(float *)(param_1 + 0xa8) = local_60 + fVar3;

  *(undefined4 *)(param_1 + 0xa4) = local_64;

  *(undefined4 *)(param_1 + 0xac) = local_5c;

  *(undefined4 *)(param_1 + 0xb0) = local_58;

  *(float *)(param_1 + 0xb4) = fVar3 + local_54;

  return;

}

/* ===== PhysicsExGroundCollision @ 0x004A2220 ===== */
void PhysicsExGroundCollision(int param_1)



{

  **(uint **)(param_1 + 0x104) = **(uint **)(param_1 + 0x104) & 0xffffff81;

  obj_geom_process();

  return;

}

/* ===== obj_gravity_apply @ 0x004A2240 ===== */
void obj_gravity_apply(int param_1,int param_2)



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

/* ===== obj_move_clamped @ 0x004A24E0 ===== */
void obj_move_clamped(float param_1,float *param_2,float param_3)



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

    fVar7 = (float10)powf();

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

/* ===== obj_bone_update @ 0x004A26F0 ===== */
void obj_bone_update(int param_1,float param_2,float param_3,undefined4 param_4,undefined4 param_5,

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

      quat_to_matrix__FP4QUATPf(local_44,local_98);

      (*(code *)PTR_crt_matrix_mul_00580c18)(local_88,local_44,param_1 + 0x294);

    }

    fVar1 = 1.0 / *(float *)(param_1 + 0xc4);

    param_2 = (float)(int)*(char *)(param_1 + 0x20a) * 0.03125 * fVar1 * param_2;

    param_3 = (float)(int)*(char *)(param_1 + 0x20b) * 0.03125 * fVar1 * param_3;

    local_a4 = local_88[1] * param_3 + -(local_88[2] * param_2);

    fStack_a0 = fStack_74 * param_3 + -(fStack_70 * param_2);

    fStack_9c = fStack_64 * param_3 + -(fStack_60 * param_2);

    obj_move_clamped(param_1,&local_a4,param_4,param_5);

  }

  return;

}

/* ===== PhysicsExApplyMoveControls @ 0x004A2850 ===== */
/* PS2 candidate: PhysicsExApplyMoveControls (conf 0.657) */



void PhysicsExApplyMoveControls(float param_1)



{

  undefined4 *puVar1;

  uint uVar2;

  float fVar3;

  int iVar4;

  float fVar5;

  float local_8;

  

  iVar4 = (int)param_1;

  local_8 = *(float *)((int)param_1 + 0x194);

  puVar1 = (undefined4 *)((int)param_1 + 0x1a0);

  fVar3 = -((*(float *)((int)param_1 + 0xa8) -

            *(float *)((int)param_1 + 0x1d4) * *(float *)((int)param_1 + 0xc4)) /

           (*(float *)((int)param_1 + 0x1e8) * *(float *)((int)param_1 + 0xc4)));

  fVar5 = *(float *)((int)param_1 + 400);

  if (0.0 < fVar3) {

    if (1.0 < fVar3) {

      fVar3 = 1.0;

    }

    fVar3 = 1.0 - fVar3 * *(float *)((int)param_1 + 0x19c);

    local_8 = fVar3 * local_8;

    fVar5 = *(float *)((int)param_1 + 400) * fVar3;

  }

  param_1 = fVar5;

  uVar2 = *(uint *)(iVar4 + 0xd8);

  if ((uVar2 & 0x8000000) != 0) {

    param_1 = param_1 * 0.5;

    local_8 = local_8 * 0.5;

  }

  obj_bone_update(iVar4,local_8,local_8,param_1,*puVar1,uVar2 & 0x10);

  return;

}

/* ===== obj_velocity_normalize @ 0x004A2930 ===== */
void obj_velocity_normalize(int param_1,int param_2,int param_3,float param_4,float param_5)



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

/* ===== PhysicsExCalcControledModelSpeeds @ 0x004A2B90 ===== */
/* PS2 candidate: PhysicsExCalcControledModelSpeeds (conf 0.533) */



void PhysicsExCalcControledModelSpeeds(int param_1,undefined4 param_2,undefined4 param_3)



{

  obj_velocity_normalize

            (param_1,(int)*(char *)(param_1 + 0x20a),(int)*(char *)(param_1 + 0x20b),param_3,param_2

            );

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

/* ===== SphereFitToObject @ 0x004A2C50 ===== */
/* PS2 candidate: SphereFitToObject (conf 0.368) */



void SphereFitToObject(undefined4 param_1,int param_2,float param_3)



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

    GEO_MatFromQuat(local_88,&local_94);

    local_a0 = *(undefined4 *)(param_2 + 0xa0);

    local_98 = local_a4 + *(float *)(param_2 + 0xa8);

    local_9c = *(undefined4 *)(param_2 + 0xa4);

    FUN_0053dc10(local_44,&local_a0);

    (*(code *)PTR_crt_matrix_mul_00580c18)(param_1,local_44,local_88);

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
/* PS2 candidate: smartie_move (conf 0.722) */



undefined4 FUN_004a2d60(int param_1,int param_2)



{

  float *pfVar1;

  float *pfVar2;

  float *pfVar3;

  float fVar4;

  int iVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  int iVar9;

  int iVar10;

  uint uVar11;

  uint uVar12;

  uint uVar13;

  int iVar14;

  float10 fVar15;

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

  int iStack_2a0;

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

  int iStack_19c;

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

  

  (*(code *)PTR_crt_matrix_copy_init_00580c1c)(local_88,param_2 + 0x294);

  if (param_1 != 0) {

    fStack_2a8 = *(float *)(param_1 + 0x1ec) * *(float *)(param_1 + 0xc4) * 0.5;

    puStack_2e8 = (undefined4 *)fStack_2a8;

    if ((*(uint **)(param_1 + 0x104) != (uint *)0x0) &&

       ((**(uint **)(param_1 + 0x104) & 0x200) != 0)) {

      puStack_2e8 = (undefined4 *)0x0;

    }

    fStack_2b0 = *(float *)(param_1 + 0x154);

    fStack_2ac = fStack_2b0;

    GEO_MatFromQuat(afStack_29c,&fStack_2b0);

    fStack_258 = *(float *)(param_1 + 0xa0);

    fStack_250 = (float)puStack_2e8 + *(float *)(param_1 + 0xa8);

    fStack_254 = *(float *)(param_1 + 0xa4);

    FUN_0053dc10(afStack_228,&fStack_258);

    (*(code *)PTR_crt_matrix_mul_00580c18)(auStack_154,afStack_228,afStack_29c);

  }

  (*(code *)PTR_crt_matrix_copy_init_00580c1c)(auStack_cc,auStack_154);

  FUN_0053d970(auStack_110,auStack_cc);

  (*(code *)PTR_crt_matrix_mul_00580c18)(auStack_1e4,auStack_cc,param_2 + 0x294);

  (*(code *)PTR_crt_matrix_mul_00580c18)(auStack_198,local_88,auStack_154);

  FUN_0053d970(auStack_44,auStack_198);

  fStack_2dc = 0.99;

  fStack_2e0 = 1.5;

  iVar9 = main_0042b1d0(param_2);

  main_animate_00404b60(param_2,iVar9);

  iVar9 = *(int *)(*(int *)(param_2 + 8) + 0x400 + iVar9 * 4);

  iStack_2a0 = 0;

  if (0 < *(int *)(iVar9 + 0x68)) {

    puStack_2e8 = (undefined4 *)(iVar9 + 0x84);

    iStack_230 = iVar9;

    do {

      iVar14 = iStack_2a0;

      iVar10 = hud_parse_format_codes_3(param_2,iVar9,iStack_2a0);

      if (iVar10 == 0) {

        afStack_240[3] = (float)*puStack_2e8;

        uStack_244 = 0xffff;

        iStack_2a4 = 0;

        iVar10 = collgrid_00430e10(afStack_240 + 3,&uStack_244,&iStack_22c,&iStack_24c,&iStack_248);

        while (iVar10 != 0) {

          iVar14 = *(int *)(iVar9 + 0x34);

          iVar9 = *(int *)(iVar9 + 0x14);

          iStack_2a4 = iStack_2a4 + 1;

          pfVar1 = (float *)(iVar9 + (uint)*(ushort *)(iVar14 + iStack_22c * 2) * 0xc);

          pfVar2 = (float *)(iVar9 + (uint)*(ushort *)(iVar14 + iStack_24c * 2) * 0xc);

          uVar13 = (uint)*(ushort *)(iVar14 + iStack_248 * 2);

          pfVar3 = (float *)(iVar9 + uVar13 * 0xc);

          fVar6 = *(float *)(iVar9 + 8 + uVar13 * 0xc) - pfVar1[2];

          fStack_2d8 = (pfVar2[1] - pfVar1[1]) * fVar6 -

                       (pfVar2[2] - pfVar1[2]) * (pfVar3[1] - pfVar1[1]);

          fStack_2ec = *pfVar2 - *pfVar1;

          fStack_2d4 = (*pfVar3 - *pfVar1) * (pfVar2[2] - pfVar1[2]) - fStack_2ec * fVar6;

          fVar6 = fStack_2ec * (pfVar3[1] - pfVar1[1]) -

                  (*pfVar3 - *pfVar1) * (pfVar2[1] - pfVar1[1]);

          fVar7 = -(fStack_2d8 * *pfVar1 + fStack_2d4 * pfVar1[1] + fVar6 * pfVar1[2]);

          fStack_2fc = fStack_194 * fStack_2d8 +

                       fStack_184 * fStack_2d4 + fStack_174 * fVar6 + fStack_164 * fVar7;

          fStack_2f8 = fStack_190 * fStack_2d8 +

                       fStack_180 * fStack_2d4 + fStack_170 * fVar6 + fStack_160 * fVar7;

          fStack_2f4 = fStack_18c * fStack_2d8 +

                       fStack_17c * fStack_2d4 + fStack_16c * fVar6 + fStack_15c * fVar7;

          fStack_2f0 = fStack_188 * fStack_2d8 +

                       fStack_178 * fStack_2d4 + fStack_168 * fVar6 + fStack_158 * fVar7;

          fStack_2e4 = fStack_2f4 * fStack_2f4 + fStack_2fc * fStack_2fc + fStack_2f8 * fStack_2f8;

          if ((fStack_2e4 != 0.0) && (0.0 <= fStack_2f0)) {

            fVar6 = fStack_2f0 / fStack_2e4;

            fStack_2ec = fStack_2f0 * fVar6;

            if (fStack_2ec < 1.5) {

              fVar8 = -(fStack_2fc * fVar6);

              fVar7 = -(fStack_2f8 * fVar6);

              fVar6 = -(fVar6 * fStack_2f4);

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

                   afStack_29c[0] * fVar8 + afStack_29c[1] * fVar7 + afStack_29c[2] * fVar6 +

                   afStack_29c[3];

              afStack_2c8[1] =

                   fStack_28c * fVar8 + fStack_288 * fVar7 + fStack_284 * fVar6 + fStack_280;

              afStack_2c8[2] =

                   fStack_27c * fVar8 + fStack_278 * fVar7 + fStack_274 * fVar6 + fStack_270;

              uVar13 = ((uint)(0.0 < afStack_2c8[2]) * 2 | (uint)(0.0 < afStack_2c8[1])) << 1 |

                       (uint)(0.0 < afStack_2c8[0]);

              fStack_308 = fVar8;

              fStack_304 = fVar7;

              fStack_300 = fVar6;

              if (uVar13 != 0) {

                iVar9 = *(int *)(uVar13 * 4 + 0x55ea5c);

                if (iVar9 < 0) {

                  fStack_254 = fVar7;

                  iVar14 = *(int *)(&DAT_0055eab4 + iVar9 * -4);

                  fStack_258 = fVar8;

                  fVar4 = afStack_29c[iVar14 * 4 + 1];

                  fStack_250 = fVar6;

                  fVar4 = afStack_2c8[iVar14] /

                          (afStack_29c[iVar14 * 4 + 2] * afStack_29c[iVar14 * 4 + 2] +

                          fVar4 * fVar4 + afStack_29c[iVar14 * 4] * afStack_29c[iVar14 * 4]);

                  fStack_308 = fVar8 - fVar4 * afStack_29c[iVar14 * 4];

                  iVar10 = *(int *)(&DAT_0055ea9c + iVar14 * 4);

                  fStack_304 = fVar7 - fVar4 * afStack_29c[iVar14 * 4 + 1];

                  iVar5 = *(int *)(&DAT_0055eaa8 + iVar14 * 4);

                  fStack_300 = fVar6 - fVar4 * afStack_29c[iVar14 * 4 + 2];

                  afStack_240[iVar10] =

                       fStack_308 * afStack_29c[iVar10 * 4] +

                       fStack_304 * afStack_29c[iVar10 * 4 + 1] +

                       fStack_300 * afStack_29c[iVar10 * 4 + 2] + afStack_29c[iVar10 * 4 + 3];

                  fVar4 = fStack_308 * afStack_29c[iVar5 * 4] +

                          fStack_304 * afStack_29c[iVar5 * 4 + 1] +

                          fStack_300 * afStack_29c[iVar5 * 4 + 2] + afStack_29c[iVar5 * 4 + 3];

                  afStack_240[iVar5] = fVar4;

                  uVar11 = (uint)(0.0 < fVar4) << ((byte)iVar5 & 0x1f) |

                           (uint)(0.0 < afStack_240[iVar10]) << ((byte)iVar10 & 0x1f);

                  if (uVar11 != 0) {

                    uVar12 = 1 << ((byte)*(undefined4 *)(&DAT_0055ead4 + iVar9 * -4) & 0x1f);

                    if ((uVar11 & uVar12) == 0) {

                      iVar9 = *(int *)(&DAT_0055eac4 + iVar9 * -4);

                      fVar4 = afStack_2c8[iVar9] /

                              (afStack_29c[iVar9 * 4 + 2] * afStack_29c[iVar9 * 4 + 2] +

                              afStack_29c[iVar9 * 4 + 1] * afStack_29c[iVar9 * 4 + 1] +

                              afStack_29c[iVar9 * 4] * afStack_29c[iVar9 * 4]);

                      fStack_308 = fVar8 - fVar4 * afStack_29c[iVar9 * 4];

                      iVar14 = *(int *)(&DAT_0055ea9c + iVar9 * 4);

                      fStack_304 = fVar7 - fVar4 * afStack_29c[iVar9 * 4 + 1];

                      iVar10 = *(int *)(&DAT_0055eaa8 + iVar9 * 4);

                      fStack_300 = fVar6 - fVar4 * afStack_29c[iVar9 * 4 + 2];

                      afStack_240[iVar14] =

                           fStack_308 * afStack_29c[iVar14 * 4] +

                           fStack_304 * afStack_29c[iVar14 * 4 + 1] +

                           fStack_300 * afStack_29c[iVar14 * 4 + 2] + afStack_29c[iVar14 * 4 + 3];

                      fVar6 = fStack_308 * afStack_29c[iVar10 * 4] +

                              fStack_304 * afStack_29c[iVar10 * 4 + 1] +

                              fStack_300 * afStack_29c[iVar10 * 4 + 2] + afStack_29c[iVar10 * 4 + 3]

                      ;

                      afStack_240[iVar10] = fVar6;

                      uVar11 = (uint)(0.0 < fVar6) << ((byte)iVar10 & 0x1f) |

                               (uint)(0.0 < afStack_240[iVar14]) << ((byte)iVar14 & 0x1f);

                      if (uVar11 == 0) goto LAB_004a3a06;

                      if ((uVar11 & uVar12) == 0) {

                        iVar9 = *(int *)(&DAT_0055ea7c + uVar13 * 4);

                      }

                      else {

                        iVar9 = *(int *)(&DAT_0055ea7c + (1 << ((byte)iVar9 & 0x1f) | uVar11) * 4);

                      }

                    }

                    else {

                      iVar9 = *(int *)(&DAT_0055ea7c + (1 << ((byte)iVar14 & 0x1f) | uVar11) * 4);

                    }

                    goto LAB_004a39db;

                  }

                }

                else {

                  fVar4 = afStack_2c8[iVar9] /

                          (afStack_29c[iVar9 * 4 + 2] * afStack_29c[iVar9 * 4 + 2] +

                          afStack_29c[iVar9 * 4 + 1] * afStack_29c[iVar9 * 4 + 1] +

                          afStack_29c[iVar9 * 4] * afStack_29c[iVar9 * 4]);

                  fStack_308 = fVar8 - fVar4 * afStack_29c[iVar9 * 4];

                  iVar14 = *(int *)(&DAT_0055ea9c + iVar9 * 4);

                  fStack_304 = fVar7 - fVar4 * afStack_29c[iVar9 * 4 + 1];

                  iVar10 = *(int *)(&DAT_0055eaa8 + iVar9 * 4);

                  fStack_300 = fVar6 - fVar4 * afStack_29c[iVar9 * 4 + 2];

                  afStack_240[iVar14] =

                       fStack_308 * afStack_29c[iVar14 * 4] +

                       fStack_304 * afStack_29c[iVar14 * 4 + 1] +

                       fStack_300 * afStack_29c[iVar14 * 4 + 2] + afStack_29c[iVar14 * 4 + 3];

                  fVar6 = fStack_308 * afStack_29c[iVar10 * 4] +

                          fStack_304 * afStack_29c[iVar10 * 4 + 1] +

                          fStack_300 * afStack_29c[iVar10 * 4 + 2] + afStack_29c[iVar10 * 4 + 3];

                  afStack_240[iVar10] = fVar6;

                  iVar9 = *(int *)(&DAT_0055ea7c +

                                  ((uint)(0.0 < fVar6) << ((byte)iVar10 & 0x1f) |

                                   (uint)(0.0 < afStack_240[iVar14]) << ((byte)iVar14 & 0x1f) |

                                  1 << ((byte)iVar9 & 0x1f)) * 4);

LAB_004a39db:

                  if (-1 < iVar9) {

                    fStack_308 = afStack_228[iVar9 * 3];

                    fStack_304 = afStack_228[iVar9 * 3 + 1];

                    fStack_300 = afStack_228[iVar9 * 3 + 2];

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

                iStack_19c = iStack_2a0;

              }

            }

          }

          iVar10 = collgrid_00430e10(afStack_240 + 3,&uStack_244,&iStack_22c,&iStack_24c,&iStack_248

                                    );

          iVar9 = iStack_230;

          iVar14 = iStack_2a0;

        }

      }

      iStack_2a0 = iVar14 + 1;

      puStack_2e8 = puStack_2e8 + 0x14;

    } while (iStack_2a0 < *(int *)(iVar9 + 0x68));

    if (fStack_2e0 < 1.5) {

      fStack_2fc = -fStack_2b0;

      fStack_2f8 = -fStack_2ac;

      fStack_2f0 = fStack_2e0;

      fStack_2f4 = -fStack_2a8;

      (*(code *)PTR_S_GEO_Vec4Transform_00580c28)(&fStack_2d8,&fStack_2fc,1,auStack_110);

      fVar15 = (float10)distancesq3d1p__FP3P3D(&fStack_2d8);

      GEO_Vec4Scale((float *)(param_1 + 0x144),&fStack_2d8,(float)((float10)1.0 / fVar15));

      *(float *)(param_1 + 0x140) =

           -((*(float *)(param_1 + 0xa0) * *(float *)(param_1 + 0x144) +

              *(float *)(param_1 + 0x148) * *(float *)(param_1 + 0xa4) + *(float *)(param_1 + 0x150)

             ) / *(float *)(param_1 + 0x14c));

      if (fStack_2e0 < 1.15) {

        **(uint **)(param_1 + 0x104) = **(uint **)(param_1 + 0x104) | 0x20;

        *(int *)(param_1 + 0x224) = param_2;

        *(int *)(param_1 + 0x228) = iStack_19c;

        *(int *)(param_1 + 0x22c) = iStack_1a0;

      }

    }

    if (fStack_2dc < 0.99) {

      fStack_2fc = -afStack_2c8[3];

      fStack_2f8 = -fStack_2b8;

      fStack_2f0 = fStack_2dc;

      fStack_2f4 = -fStack_2b4;

      (*(code *)PTR_S_GEO_Vec4Transform_00580c28)(&fStack_2d8,&fStack_2fc,1,auStack_110);

      fVar15 = (float10)distancesq3d1p__FP3P3D(&fStack_2d8);

      GEO_Vec4Scale(&fStack_2d8,&fStack_2d8,(float)((float10)1.0 / fVar15));

      (*(code *)PTR_S_GEO_Vec3Transform_00580c20)(param_1 + 0x254,afStack_2c8 + 3,1,auStack_154);

      fVar6 = 1.0 / SQRT(fStack_2dc);

      afStack_2c8[3] = afStack_2c8[3] * fVar6;

      fStack_2b8 = fStack_2b8 * fVar6;

      fStack_2b4 = fVar6 * fStack_2b4;

      (*(code *)PTR_S_GEO_Vec3Transform_00580c20)

                ((float *)(param_1 + 0x260),afStack_2c8 + 3,1,auStack_154);

      uVar13 = objspec_has_shot_function_2(param_1,param_2);

      if ((uVar13 & 1) == 0) {

        if (fStack_2d8 * *(float *)(param_1 + 0x128) +

            fStack_2d4 * *(float *)(param_1 + 300) + fStack_2d0 * *(float *)(param_1 + 0x130) < 0.0)

        {

          fVar6 = *(float *)(param_1 + 0x260) - *(float *)(param_1 + 0xa0);

          fVar7 = *(float *)(param_1 + 0x264) - *(float *)(param_1 + 0xa4);

          fVar8 = *(float *)(param_1 + 0x268) - *(float *)(param_1 + 0xa8);

          afStack_2c8[0] = fVar6 + *(float *)(param_1 + 0xa0);

          afStack_2c8[1] = fVar7 + *(float *)(param_1 + 0xa4);

          afStack_2c8[2] = fVar8 + *(float *)(param_1 + 0xa8);

          fStack_2b0 = fVar6 + *(float *)(param_1 + 0xac);

          fStack_2ac = fVar7 + *(float *)(param_1 + 0xb0);

          fStack_2a8 = fVar8 + *(float *)(param_1 + 0xb4);

          PhysicsExCollisionPlane2_OLD__FP6OBJECTP3P3DN31P7PLANE3D

                    (param_1,afStack_2c8,&fStack_2b0,(float *)(param_1 + 0x128),param_1 + 0x134,

                     &fStack_2d8,0);

          *(float *)(param_1 + 0xa0) = afStack_2c8[0] - fVar6;

          *(float *)(param_1 + 0xa4) = afStack_2c8[1] - fVar7;

          *(float *)(param_1 + 0xa8) = afStack_2c8[2] - fVar8;

          **(uint **)(param_1 + 0x104) = **(uint **)(param_1 + 0x104) | 0x10;

          *(int *)(param_1 + 0x220) = param_2;

          if ((*(byte *)(param_2 + 0xdc) & 0x10) != 0) {

            *(int *)(param_2 + 0x220) = param_1;

          }

          return 1;

        }

      }

      else {

        **(uint **)(param_1 + 0x104) = **(uint **)(param_1 + 0x104) & 0xffffffdf;

        *(undefined4 *)(param_1 + 0x224) = 0;

      }

    }

  }

  return 0;

}

/* ===== obj_material_names @ 0x004A3E90 ===== */
undefined4 obj_material_names(int param_1)



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

/* ===== obj_visibility_test @ 0x004A3EE0 ===== */
int obj_visibility_test(float param_1)



{

  float *pfVar1;

  float fVar2;

  float fVar3;

  int iVar4;

  float fVar5;

  float fVar6;

  int iVar7;

  int iVar8;

  float *pfVar9;

  float10 fVar10;

  int *local_58;

  float local_54;

  float local_50;

  float local_40;

  float local_3c;

  undefined4 local_38;

  float local_34;

  float local_30;

  float local_2c;

  float local_28;

  undefined4 local_24;

  undefined4 local_20;

  float local_1c;

  undefined4 local_18;

  

  iVar7 = (int)param_1;

  local_54 = 0.0;

  if ((~**(uint **)((int)param_1 + 0x104) & 0x100) != 0) {

    iVar4 = *(int *)(*(int *)((int)param_1 + 8) + 0xc);

    if (iVar4 == 0) {

      fVar5 = 0.5;

      pfVar9 = (float *)(*(int *)(*(int *)((int)param_1 + 8) + 0x400) + 0x44);

    }

    else {

      fVar5 = 0.85;

      pfVar9 = (float *)(iVar4 + 0xc);

    }

    fVar2 = -*pfVar9;

    if (fVar2 < pfVar9[3]) {

      fVar2 = pfVar9[3];

    }

    fVar3 = -pfVar9[1];

    if (fVar3 < pfVar9[4]) {

      fVar3 = pfVar9[4];

    }

    *(float *)((int)param_1 + 0x154) =

         SQRT(fVar2 * fVar2 + fVar3 * fVar3) * *(float *)((int)param_1 + 0xc4) * fVar5;

  }

  local_58 = DAT_00632d7c;

  if (DAT_00632d7c == (int *)0x0) {

    return 0;

  }

  do {

    iVar4 = local_58[3];

    if (((((*(uint *)(iVar4 + 0x1c8) & 0x800) == 0 && (*(uint *)(iVar4 + 0xd8) & 0x4000c000) == 0)

         && (iVar7 != iVar4)) && (*(int *)(iVar4 + 8) != 0)) && (*(int *)(iVar4 + 0x210) != iVar7))

    {

      pfVar9 = (float *)(iVar7 + 0xa0);

      local_1c = *(float *)(iVar7 + 0x1ec) * *(float *)(iVar7 + 0xc4);

      pfVar1 = (float *)(iVar7 + 0xac);

      local_28 = *pfVar9;

      local_24 = *(undefined4 *)(iVar7 + 0xa4);

      local_20 = *(undefined4 *)(iVar7 + 0xa8);

      local_18 = *(undefined4 *)(iVar7 + 0x154);

      if (*pfVar9 <= *pfVar1) {

        local_40 = *pfVar9 - *(float *)(iVar7 + 0x154);

        local_34 = *(float *)(iVar7 + 0x154) + *pfVar1;

      }

      else {

        local_40 = *pfVar1 - *(float *)(iVar7 + 0x154);

        local_34 = *(float *)(iVar7 + 0x154) + *pfVar9;

      }

      if (*(float *)(iVar7 + 0xa4) <= *(float *)(iVar7 + 0xb0)) {

        local_3c = *(float *)(iVar7 + 0xa4) - *(float *)(iVar7 + 0x154);

        local_30 = *(float *)(iVar7 + 0x154) + *(float *)(iVar7 + 0xb0);

      }

      else {

        local_3c = *(float *)(iVar7 + 0xb0) - *(float *)(iVar7 + 0x154);

        local_30 = *(float *)(iVar7 + 0x154) + *(float *)(iVar7 + 0xa4);

      }

      if (*(float *)(iVar7 + 0xa8) <= *(float *)(iVar7 + 0xb4)) {

        local_38 = *(undefined4 *)(iVar7 + 0xa8);

        local_2c = *(float *)(iVar7 + 0xb4);

      }

      else {

        local_38 = *(undefined4 *)(iVar7 + 0xb4);

        local_2c = *(float *)(iVar7 + 0xa8);

      }

      local_2c = local_1c + local_2c;

      iVar8 = collide_bbox_bbox(&local_40,iVar4 + 0x27c);

      if (iVar8 != 0) {

        local_54 = *(float *)(iVar7 + 0x1ec) * *(float *)(iVar7 + 0xc4) * 0.5;

        if (*(float *)(iVar7 + 0x154) < local_54) {

          local_54 = *(float *)(iVar7 + 0x154);

        }

        fVar10 = (float10)distance3d__FP3P3DT0(pfVar1,pfVar9);

        if (fVar10 == (float10)0.0) {

          local_50 = 1.0;

        }

        else {

          local_50 = (float)((float10)local_54 / fVar10);

        }

        fVar5 = *pfVar9;

        fVar2 = *(float *)(iVar7 + 0xa4);

        fVar3 = *(float *)(iVar7 + 0xa8);

        param_1 = 0.0;

        do {

          param_1 = param_1 + local_50;

          if (1.0 < param_1) {

            param_1 = 1.0;

          }

          fVar6 = 1.0 - param_1;

          *pfVar9 = fVar6 * *pfVar1 + fVar5 * param_1;

          *(float *)(iVar7 + 0xa4) = fVar2 * param_1 + fVar6 * *(float *)(iVar7 + 0xb0);

          *(float *)(iVar7 + 0xa8) = fVar3 * param_1 + fVar6 * *(float *)(iVar7 + 0xb4);

          local_54 = (float)FUN_004a2d60(iVar7,iVar4);

        } while ((local_54 == 0.0) && (param_1 < 1.0));

      }

    }

    local_58 = (int *)*local_58;

  } while (local_58 != (int *)0x0);

  return (int)local_54;

}

/* ===== obj_move_to_target @ 0x004A4210 ===== */
void obj_move_to_target(int param_1,undefined4 param_2)



{

  uint uVar1;

  int iVar2;

  int iVar3;

  

  if (((((*(uint *)(param_1 + 0xd8) & 0x10000000) != 0) ||

       (*(float *)(param_1 + 0xa0) != *(float *)(param_1 + 0xac))) ||

      (*(float *)(param_1 + 0xa4) != *(float *)(param_1 + 0xb0))) ||

     (*(float *)(param_1 + 0xa8) != *(float *)(param_1 + 0xb4))) {

    *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) & 0xefffffff;

    **(undefined1 **)(param_1 + 0x104) = 0;

    *(undefined4 *)(param_1 + 0x224) = 0;

    *(undefined4 *)(param_1 + 0x220) = 0;

    if (*(int *)(param_1 + 8) != 0) {

      if ((*(uint *)(param_1 + 0x1c8) & 0x400) == 0) {

        iVar2 = 1;

        iVar3 = 0;

        do {

          if (iVar2 == 0) goto LAB_004a431f;

          iVar2 = obj_visibility_test(param_1,param_2);

        } while ((((*(float *)(param_1 + 0xa0) != *(float *)(param_1 + 0xac)) ||

                  (*(float *)(param_1 + 0xa4) != *(float *)(param_1 + 0xb0))) ||

                 (*(float *)(param_1 + 0xa8) != *(float *)(param_1 + 0xb4))) &&

                (iVar3 = iVar3 + 1, iVar3 < 4));

        if (iVar2 != 0) {

          *(undefined4 *)(param_1 + 0xa0) = *(undefined4 *)(param_1 + 0xac);

          *(undefined4 *)(param_1 + 0xa4) = *(undefined4 *)(param_1 + 0xb0);

          *(undefined4 *)(param_1 + 0xa8) = *(undefined4 *)(param_1 + 0xb4);

        }

      }

LAB_004a431f:

      if ((*(uint *)(param_1 + 0x1c8) & 0x200) == 0) {

        obj_geom_process(param_1);

      }

    }

    uVar1 = **(uint **)(param_1 + 0x104);

    if ((uVar1 & 0x68) != 0) {

      **(uint **)(param_1 + 0x104) = uVar1 | 0x80;

    }

    if ((**(byte **)(param_1 + 0x104) & 0x96) != 0) {

      objspec_has_shot_function_2(param_1,0);

    }

  }

  return;

}

/* ===== PhysicsExApplyLocation @ 0x004A4360 ===== */
/* PS2 candidate: PhysicsExApplyLocation (conf 0.382) */



void PhysicsExApplyLocation(int param_1)



{

  uint uVar1;

  float fVar2;

  float fVar3;

  float local_c;

  float local_8;

  float local_4;

  

  local_c = *(float *)(param_1 + 0xa0) - *(float *)(param_1 + 0xac);

  *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) & 0xf7e7ffff;

  local_8 = *(float *)(param_1 + 0xa4) - *(float *)(param_1 + 0xb0);

  local_4 = *(float *)(param_1 + 0xa8) - *(float *)(param_1 + 0xb4);

  if ((local_c != 0.0) || (local_8 != 0.0)) {

    collgrid_clear_grid(param_1);

  }

  if (*(int *)(param_1 + 0x210) == 0) {

    obj_move_to_target(param_1,&local_c);

    fVar2 = *(float *)(param_1 + 0xa8) - *(float *)(param_1 + 0x1d4) * *(float *)(param_1 + 0xc4);

    if (fVar2 < 0.0 != (fVar2 == 0.0)) {

      uVar1 = *(uint *)(param_1 + 0xd8);

      *(uint *)(param_1 + 0xd8) = uVar1 | 0x100000;

      fVar3 = -(*(float *)(param_1 + 0x1e8) * *(float *)(param_1 + 0xc4));

      if (fVar2 < fVar3 != (fVar2 == fVar3)) {

        *(uint *)(param_1 + 0xd8) = uVar1 | 0x8100000;

      }

    }

    if (fVar2 - *(float *)(param_1 + 0x140) < 0.1) {

      *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) | 0x80000;

    }

    ObjectCalculateTransform(param_1);

  }

  return;

}

/* ===== trajectory_calculate @ 0x004A4480 ===== */
/* PS2 candidate: trajectory_calculate (conf 0.592) */



void trajectory_calculate(float *param_1,float *param_2,float *param_3,float *param_4,float param_5)



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

/* ===== piranha_finit @ 0x004A4510 ===== */
/* PS2 candidate: piranha_finit (conf 0.608) */



void piranha_finit(void)



{

  int *piVar1;

  

  piVar1 = &DAT_00632960;

  do {

    piVar1[2] = 0;

    piVar1[1] = 0;

    if (*piVar1 != 0) {

      fx_delete(*piVar1);

    }

    *piVar1 = 0;

    piVar1 = piVar1 + 3;

  } while ((int)piVar1 < 0x6329d8);

  return;

}

/* ===== piranha_go @ 0x004A4550 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* PS2 candidate: piranha_go (conf 0.444) */



void piranha_go(void)



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

          fx_delete(pfVar5[-2]);

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

         ((iVar3 = ObjIsMecc(in_ECX), iVar3 != 0 && ((*(uint *)(in_ECX + 0xd8) & 0x200) == 0))))

      goto LAB_004a473d;

    }

    for (; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {

      in_ECX = puVar1[3];

      if (((((*(uint *)(in_ECX + 0xd8) & 0x4000c000) == 0) &&

           (*(float *)(in_ECX + 0x278) < *(float *)(in_ECX + 0x1c0))) &&

          (((*(uint *)(in_ECX + 0xd8) & 0x8000000) != 0 &&

           ((*(int *)(in_ECX + 4) == 0xb && (*(int *)(in_ECX + 0x210) == 0)))))) &&

         (((*(int *)(in_ECX + 0x274) == 0 ||

           ((iVar3 = ObjIsReaper(*(int *)(in_ECX + 0x274)), iVar3 == 0 &&

            (iVar3 = reaperbase_bldg_from_object(*(undefined4 *)(in_ECX + 0x274)), iVar3 == 0)))) &&

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

      iVar3 = piranha_make__FP6OBJECT(in_ECX);

      *(uint *)(iVar3 + 0xe0) = *(uint *)(iVar3 + 0xe0) | 1;

      *(undefined4 *)(iVar3 + 0xf0) = 0x3dcccccd;

      *(undefined4 *)(iVar3 + 0xf4) = 1;

    }

  }

  return;

}

/* ===== piranha_make__FP6OBJECT @ 0x004A4770 ===== */
/* PS2 candidate: piranha_make__FP6OBJECT (conf 0.443) */



int piranha_make__FP6OBJECT(int param_1)



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

  ObjectSetAnim(iVar5,1,0x21,0,0,0);

  pfVar1 = (float *)(param_1 + 0xa0);

  pfVar2 = (float *)(iVar5 + 0xa0);

  *pfVar2 = *pfVar1;

  *(undefined4 *)(iVar5 + 0xa4) = *(undefined4 *)(param_1 + 0xa4);

  *(undefined4 *)(iVar5 + 0xa8) = *(undefined4 *)(param_1 + 0xa8);

  *(undefined4 *)(iVar5 + 0xa8) = 0xbf800000;

  param_1 = 9;

  do {

    fVar6 = (float10)rndfloat(0x43b40000);

    *(float *)(iVar5 + 200) = (float)fVar6;

    sine_cos_lookup((float)fVar6,&local_8,&local_4);

    *pfVar2 = *pfVar1 - local_8 * 20.0;

    fVar3 = *(float *)(iVar4 + 0xa4);

    *(undefined4 *)(iVar5 + 0xa8) = 0xbf800000;

    *(float *)(iVar5 + 0xa4) = local_4 * 20.0 + fVar3;

    fVar6 = (float10)get_floor_z_point(pfVar2);

    if (fVar6 < (float10)-2.0) {

      return iVar5;

    }

    param_1 = param_1 + -1;

  } while (param_1 != 0);

  return iVar5;

}

/* ===== piranha_chase_swimmer__FP6OBJECT @ 0x004A48A0 ===== */
/* PS2 candidate: piranha_chase_swimmer__FP6OBJECT (conf 0.443) */



void piranha_chase_swimmer__FP6OBJECT(float param_1)



{

  float *pfVar1;

  float fVar2;

  bool bVar3;

  float fVar4;

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

  

  fVar4 = param_1;

  bVar3 = false;

  if ((*(uint *)((int)param_1 + 0xe0) & 0x18) == 0) {

    pfVar1 = (float *)((int)param_1 + 0xa0);

    fVar6 = (float10)distancesq2d__FP3P3DT0(pfVar1,*(int *)((int)param_1 + 0x274) + 0xa0);

    local_28 = (float)fVar6;

    fVar6 = (float10)dirfcalcp3d__FP3P3DT0(pfVar1,*(int *)((int)fVar4 + 0x274) + 0xa0);

    local_24 = (float)fVar6;

    *(float *)((int)fVar4 + 200) = (float)fVar6;

    local_c = *pfVar1;

    local_8 = *(float *)((int)fVar4 + 0xa4);

    local_4 = *(undefined4 *)((int)fVar4 + 0xa8);

    local_18 = *pfVar1;

    local_14 = *(float *)((int)fVar4 + 0xa4);

    local_10 = *(undefined4 *)((int)fVar4 + 0xa8);

    fVar2 = *(float *)(*(int *)((int)fVar4 + 0x274) + 0x154) * 1.8;

    if (local_28 <= fVar2 * fVar2) {

      *(uint *)((int)fVar4 + 0xe0) = *(uint *)((int)fVar4 + 0xe0) | 2;

      goto LAB_004a4bf3;

    }

    sine_cos_lookup(local_24,&param_1,&local_2c);

    fVar6 = (float10)FUN_00518b70(fVar4,0);

    local_24 = (float)(fVar6 * (float10)param_1 * (float10)15.0);

    fVar6 = (float10)FUN_00518b70(fVar4,0);

    fVar6 = fVar6 * (float10)local_2c * (float10)-15.0;

    fStack_20 = (float)fVar6;

    local_18 = (float)(fVar6 * (float10)0.25 + (float10)local_24 + (float10)local_18);

    local_14 = (fStack_20 - local_24 * 0.25) + local_14;

    local_c = local_24 * 10.0 + local_18;

    local_8 = fStack_20 * 10.0 + local_14;

    if (400.0 < local_28) {

      local_18 = *pfVar1;

      local_14 = *(float *)((int)fVar4 + 0xa4);

      local_10 = *(undefined4 *)((int)fVar4 + 0xa8);

      *(undefined4 *)((int)fVar4 + 0x184) = 0x3f800000;

      local_28 = SQRT(local_28) - 15.0;

      fVar6 = (float10)rndfloatrange(0xc0800000,0x40800000);

      local_18 = (float)((float10)local_28 * (float10)local_24 + fVar6 + (float10)local_18);

      fVar6 = (float10)rndfloatrange(0xc0800000,0x40800000);

      local_14 = (float)((float10)local_28 * (float10)fStack_20 + fVar6 + (float10)local_14);

    }

    fVar6 = (float10)get_floor_z_point(&local_18);

    if ((fVar6 < (float10)-2.0) &&

       (fVar6 = (float10)get_floor_z_point(&local_c), fVar6 < (float10)-2.0)) goto LAB_004a49ca;

  }

  else {

    local_c = *(float *)((int)param_1 + 0xa0);

    local_8 = *(float *)((int)param_1 + 0xa4);

    local_4 = *(undefined4 *)((int)param_1 + 0xa8);

    local_18 = *(float *)((int)param_1 + 0xa0);

    local_14 = *(float *)((int)param_1 + 0xa4);

    local_10 = *(undefined4 *)((int)param_1 + 0xa8);

    local_24 = (float)((*(uint *)((int)param_1 + 0x188) >> 8) % 10);

    fStack_20 = 0.0;

    local_28 = (float)(uint)local_24 + 2.0;

    if ((*(uint *)((int)param_1 + 0xe0) & 8) == 0) {

      fVar6 = (float10)FUN_00518b70(param_1,0);

      fVar6 = (float10)*(float *)((int)fVar4 + 200) - fVar6 * (float10)120.0;

      *(float *)((int)fVar4 + 200) = (float)fVar6;

      fVar6 = fVar6 + (float10)90.0;

    }

    else {

      fVar6 = (float10)FUN_00518b70(param_1,0);

      fVar6 = fVar6 * (float10)120.0 + (float10)*(float *)((int)fVar4 + 200);

      *(float *)((int)fVar4 + 200) = (float)fVar6;

      fVar6 = fVar6 - (float10)90.0;

    }

    sine_cos_lookup((float)fVar6,&param_1,&local_2c);

    local_18 = param_1 * local_28 + *(float *)(*(int *)((int)fVar4 + 0x274) + 0xa0);

    local_14 = *(float *)(*(int *)((int)fVar4 + 0x274) + 0xa4) - local_2c * local_28;

    fVar6 = (float10)get_floor_z_point(&local_18);

    if (fVar6 < (float10)-2.0) {

LAB_004a49ca:

      bVar3 = true;

      object_set_location_p3d(fVar4,&local_18);

    }

  }

  uVar5 = *(uint *)((int)fVar4 + 0xe0) & 0xfffffffd;

  *(uint *)((int)fVar4 + 0xe0) = uVar5;

  if (bVar3) {

    *(uint *)((int)fVar4 + 0xe0) = uVar5 | 4;

    return;

  }

LAB_004a4bf3:

  *(uint *)((int)fVar4 + 0xe0) = *(uint *)((int)fVar4 + 0xe0) & 0xfffffffb;

  return;

}

/* ===== piranha_launch_fx__FP6OBJECT @ 0x004A4C10 ===== */
/* PS2 candidate: piranha_launch_fx__FP6OBJECT (conf 0.546) */



void piranha_launch_fx__FP6OBJECT(int param_1)



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

/* ===== comm_game_session_update @ 0x004A54E0 ===== */
void comm_game_session_update(void)



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

    cam_mode_switch(0xffffffff);

  }

  if ((*(float *)(DAT_00632a88 + 0x1c0) <= *(float *)(DAT_00632a88 + 0x278)) &&

     (iVar3 = camera_is_sniper(), iVar3 != 0)) {

    cam_mode_switch(1);

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

        comm_audio_volume_user(DAT_00632fb8,uVar9,uVar10,0);

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

      dlog_text_render_screen();

    }

    if (DAT_00632ae7 != '\0') {

      giftshopview_enable(0,0);

    }

    if ((((DAT_00632aeb != '\0') && (DAT_00632bb8 == 0)) && (DAT_00632ba8 == 0)) &&

       (((DAT_00632bac == 0 && (DAT_00632bb0 == 0)) && (DAT_00632bb4 == 0)))) {

      item_drop_backheld(DAT_00632a88);

    }

    if (DAT_00632aec != '\0') {

      item_drop_curweap(DAT_00632a88);

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

    iVar3 = dialog_level_is_base();

    if (((iVar3 != 0) && (DAT_00632ad8 != '\0')) && (iVar3 = dialog_level_is_base(), iVar3 != 0)) {

      DAT_00633020 = 0;

      DAT_00632920 = 0xffffffff;

      comm_show_conn_menu();

    }

    if (DAT_00632a88 != 0) {

      audio_speaker_user();

      if (*(int *)(DAT_00632a88 + 0x18c) + -1 < 2) {

        FUN_00500f50(DAT_006330cc,DAT_006330c4);

        rpman_init__FP6OBJECT();

        return;

      }

      FUN_00500f50(DAT_006330d0,DAT_006330c4);

    }

  }

  rpman_init__FP6OBJECT();

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

      sine_cos_lookup(*(undefined4 *)(DAT_00632a88 + 200),&local_18,&local_14);

      if (*(char *)(DAT_00632a88 + 0x20a) != '\0') {

        local_28 = 1.0;

        if (*(char *)(DAT_00632a88 + 0x20a) < '\x01') {

          local_28 = -1.0;

        }

        fVar3 = (float10)FUN_00518b70(DAT_00632a88,0,0);

        fVar3 = (float10)FUN_00518b70(DAT_00632a88,0,

                                      (float)(fVar3 * (float10)local_28 * (float10)local_14 *

                                             (float10)-1600.0));

        object_add_location_2

                  (DAT_00632a88,

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

        object_add_location_2

                  (DAT_00632a88,

                   (float)(fVar3 * (float10)local_28 * (float10)local_14 * (float10)1600.0));

      }

    }

    return;

  }

  XFGetViewportExt(&local_24,&local_28,&local_10,&local_c);

  sine_cos_lookup(local_24,&local_1c,&local_20);

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

/* ===== screenshot_helper @ 0x004A5CD0 ===== */
void screenshot_helper(void)



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

/* ===== audio_speaker_user @ 0x004A5D10 ===== */
void audio_speaker_user(void)



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

    textrender_draw_buffered(0xff0000,0,fVar3,0x3f000000,DAT_005a0ee4,uVar1);

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

    textrender_draw_buffered

              (0xe0e020,0,(float)(fVar1 * (float10)1.2),0x3f000000,0x3ecccccd,&DAT_00632c10);

    fVar1 = (float10)FUN_00518b70(DAT_00632a88,0);

    fVar1 = (float10)_DAT_00632d10 - fVar1;

    _DAT_00632d10 = (float)fVar1;

    if (fVar1 < (float10)0.0 != (fVar1 == (float10)0.0)) {

      _DAT_00632d10 = 0.0;

    }

  }

  return;

}

/* ===== player_force_type @ 0x004A5F40 ===== */
/* PS2 candidate: player_force_type (conf 0.383) */



void player_force_type(int param_1)



{

  int iVar1;

  int iVar2;

  undefined4 uVar3;

  

  iVar1 = dialog_level_is_base();

  if (iVar1 == 0) {

    iVar1 = -1;

    if (param_1 == 0x85) {

      param_1 = 2;

      iVar1 = 0x85;

    }

    object_destroy_specialtype(DAT_00632a88);

    object_free_all_allocated_data(DAT_00632a88);

    iVar2 = object_find(param_1);

    if (iVar2 == 0) {

      param_1 = 0;

      iVar2 = object_find(0);

      if (iVar2 == 0) {

        return;

      }

    }

    if (DAT_00632a88 != 0) {

      DAT_00633108 = (uint)(param_1 != 0);

      object_copy_personality(DAT_00632a88,iVar2);

      if (-1 < iVar1) {

        uVar3 = objectset_find(0x85);

        *(undefined4 *)(DAT_00632a88 + 8) = uVar3;

      }

      *(uint *)(DAT_00632a88 + 0xd8) = *(uint *)(DAT_00632a88 + 0xd8) | *(uint *)(iVar2 + 0xd8);

      *(uint *)(DAT_00632a88 + 0xdc) = *(uint *)(DAT_00632a88 + 0xdc) | *(uint *)(iVar2 + 0xdc);

      *(uint *)(DAT_00632a88 + 0xdc) = *(uint *)(DAT_00632a88 + 0xdc) | 0x80000000;

      *(undefined4 *)(DAT_00632a88 + 0xcc) = 0;

      *(undefined4 *)(DAT_00632a88 + 0xd4) = 0;

      camera_fov_update();

      object_copy_posdirinfo(DAT_00632a88);

      object_setup_specialtype(DAT_00632a88);

      anim_select_check(DAT_00632a88,1);

      *(uint *)(DAT_00632a88 + 0x1c8) = *(uint *)(DAT_00632a88 + 0x1c8) | 1;

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

/* ===== ObjIsRipper @ 0x004A6100 ===== */
/* PS2 candidate: ObjIsRipper (conf 0.368) */



undefined4 ObjIsRipper(int param_1)



{

  if ((param_1 != 0) && (*(int *)(param_1 + 0x1e0) == 0x17)) {

    return 1;

  }

  return 0;

}

/* ===== ObjIsJetski @ 0x004A6120 ===== */
/* PS2 candidate: ObjIsJetski (conf 0.446) */



undefined4 ObjIsJetski(int param_1)



{

  if ((param_1 != 0) && (*(int *)(param_1 + 0x1e0) == 0x5a)) {

    return 1;

  }

  return 0;

}

/* ===== ObjIsTurret @ 0x004A6140 ===== */
/* PS2 candidate: ObjIsTurret (conf 0.381) */



undefined4 ObjIsTurret(int param_1)



{

  if ((param_1 != 0) && (*(int *)(param_1 + 0x1e0) == 0x2c)) {

    return 1;

  }

  return 0;

}

/* ===== ObjIsMecc @ 0x004A6160 ===== */
/* PS2 candidate: ObjIsMecc (conf 0.677) */



undefined4 ObjIsMecc(int param_1)



{

  if ((param_1 != 0) && (*(int *)(param_1 + 0x1e0) == 2)) {

    return 1;

  }

  return 0;

}

/* ===== ObjIsReaper @ 0x004A6180 ===== */
/* PS2 candidate: ObjIsReaper (conf 0.59) */



undefined4 ObjIsReaper(int param_1)



{

  if ((param_1 != 0) && (*(int *)(param_1 + 0x1e0) == 3)) {

    return 1;

  }

  return 0;

}

/* ===== ObjIsKabuto @ 0x004A61A0 ===== */
/* PS2 candidate: ObjIsKabuto (conf 0.626) */



undefined4 ObjIsKabuto(int param_1)



{

  if ((param_1 != 0) && (*(int *)(param_1 + 0x1e0) == 1)) {

    return 1;

  }

  return 0;

}

/* ===== obj_is_type0f @ 0x004A61C0 ===== */
undefined4 obj_is_type0f(int param_1)



{

  if ((param_1 != 0) && (*(int *)(param_1 + 0x1e0) == 0xf)) {

    return 1;

  }

  return 0;

}

/* ===== ObjIsPlayer @ 0x004A61E0 ===== */
/* PS2 candidate: ObjIsPlayer (conf 0.381) */



undefined4 ObjIsPlayer(int param_1)



{

  if ((param_1 != 0) && ((*(byte *)(param_1 + 0x1c8) & 1) != 0)) {

    return 1;

  }

  return 0;

}

/* ===== meccbasepit_bldg_from_object @ 0x004A6200 ===== */
/* PS2 candidate: meccbasepit_bldg_from_object (conf 0.712) */



undefined4 meccbasepit_bldg_from_object(int param_1)



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

/* ===== obj_is_pickup_4a @ 0x004A6240 ===== */
undefined4 obj_is_pickup_4a(int param_1)



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

/* ===== reaperbase_bldg_from_object @ 0x004A6290 ===== */
/* PS2 candidate: reaperbase_bldg_from_object (conf 0.712) */



undefined4 reaperbase_bldg_from_object(int param_1)



{

  if ((param_1 != 0) && (*(int *)(param_1 + 0x1e0) == 0x52)) {

    return 1;

  }

  return 0;

}

/* ===== obj_is_pickup_53 @ 0x004A62B0 ===== */
undefined4 obj_is_pickup_53(int param_1)



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

/* ===== ObjIsReaperBldg @ 0x004A6300 ===== */
/* PS2 candidate: ObjIsReaperBldg (conf 0.341) */



undefined4 ObjIsReaperBldg(int param_1)



{

  if ((param_1 != 0) && (*(int *)(param_1 + 0x1e0) == 0x53)) {

    return 1;

  }

  return 0;

}

/* ===== obj_is_pickup_4a_model @ 0x004A6320 ===== */
undefined4 obj_is_pickup_4a_model(int param_1)



{

  int iVar1;

  

  if (((param_1 != 0) && (*(int *)(param_1 + 0x1e0) == 0x4a)) &&

     ((iVar1 = *(int *)(param_1 + 4), iVar1 == 0x2c5 ||

      (((iVar1 == 0x2e8 || (iVar1 == 0x2ca)) || (iVar1 == 0x307)))))) {

    return 1;

  }

  return 0;

}

/* ===== obj_is_pickup_53_model @ 0x004A6360 ===== */
undefined4 obj_is_pickup_53_model(int param_1)



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

  

  iVar2 = dialog_level_is_base();

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

/* ===== obj_turn_update @ 0x004A6730 ===== */
void obj_turn_update(int param_1)



{

  float10 fVar1;

  float10 fVar2;

  

  obj_alpha_fade_update(param_1);

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

  obj_scale_compute(param_1);

  if ((*(uint *)(param_1 + 0xd8) & 0x10) == 0) {

    if (((*(uint *)(param_1 + 0xd8) & 0x80000) == 0) && (*(int *)(param_1 + 0x210) == 0)) {

      fVar1 = (float10)FUN_00518b70(param_1,0);

      *(float *)(param_1 + 0x108) =

           (float)((float10)*(float *)(param_1 + 0x108) -

                  fVar1 * (float10)*(float *)(param_1 + 0x1b8));

    }

    else if (*(float *)(param_1 + 0x108) < 0.0) {

      *(undefined4 *)(param_1 + 0x108) = 0;

    }

  }

  fVar1 = (float10)FUN_00518b70(param_1,0);

  object_add_location(param_1,0,0,

                      (float)(((float10)*(float *)(param_1 + 0x118) +

                              (float10)*(float *)(param_1 + 0x108)) * fVar1 * (float10)0.5));

  return;

}

/* ===== obj_alpha_fade_update @ 0x004A6860 ===== */
void obj_alpha_fade_update(float param_1)



{

  float fVar1;

  float fVar2;

  int iVar3;

  float10 fVar4;

  

  iVar3 = (int)param_1;

  if (DAT_00632bc4 != 0) {

    return;

  }

  fVar4 = (float10)FUN_0040d480();

  fVar1 = (float)((float10)(int)*(char *)((int)param_1 + 0x208) * (float10)0.03125 * fVar4);

  fVar4 = (float10)FUN_00518b70(param_1,0);

  fVar2 = (float)(fVar4 * (float10)*(float *)((int)param_1 + 0x1a4) * (float10)fVar1);

  fVar1 = fVar1 * *(float *)((int)param_1 + 0x1a8);

  if (fVar1 <= 0.0) {

    if (0.0 <= fVar1) {

      if (*(float *)((int)param_1 + 0x114) <= 0.0) {

        if (0.0 <= *(float *)((int)param_1 + 0x114)) goto LAB_004a6a79;

        fVar4 = (float10)FUN_00518b70(param_1,0);

        fVar4 = fVar4 * (float10)*(float *)((int)param_1 + 0x1ac) +

                (float10)*(float *)((int)param_1 + 0x114);

        *(float *)((int)param_1 + 0x114) = (float)fVar4;

        if (fVar4 <= (float10)0.0) goto LAB_004a6a79;

      }

      else {

        fVar4 = (float10)FUN_00518b70(param_1,0);

        fVar4 = (float10)*(float *)((int)param_1 + 0x114) -

                fVar4 * (float10)*(float *)((int)param_1 + 0x1ac);

        *(float *)((int)param_1 + 0x114) = (float)fVar4;

        if ((float10)0.0 <= fVar4) goto LAB_004a6a79;

      }

      *(undefined4 *)((int)param_1 + 0x114) = 0;

      goto LAB_004a6a79;

    }

    if (0.0 < *(float *)((int)param_1 + 0x114)) {

      *(undefined4 *)((int)param_1 + 0x114) = 0;

    }

    if (fVar1 < *(float *)((int)param_1 + 0x114)) {

      fVar2 = fVar2 + *(float *)((int)param_1 + 0x114);

      *(float *)((int)param_1 + 0x114) = fVar2;

      if (fVar2 < fVar1) {

        *(float *)((int)param_1 + 0x114) = fVar1;

      }

      goto LAB_004a6a79;

    }

    if (fVar1 <= *(float *)((int)param_1 + 0x114)) goto LAB_004a6a79;

    fVar4 = (float10)FUN_00518b70(param_1,0);

    fVar4 = fVar4 * (float10)*(float *)((int)param_1 + 0x1ac);

  }

  else {

    if (*(float *)((int)param_1 + 0x114) < 0.0) {

      *(undefined4 *)((int)param_1 + 0x114) = 0;

    }

    if (fVar1 <= *(float *)((int)param_1 + 0x114)) {

      if (fVar1 < *(float *)((int)param_1 + 0x114)) {

        fVar4 = (float10)FUN_00518b70(param_1,0);

        fVar4 = (float10)*(float *)((int)param_1 + 0x114) -

                fVar4 * (float10)*(float *)((int)param_1 + 0x1ac);

        *(float *)((int)param_1 + 0x114) = (float)fVar4;

        if (fVar4 < (float10)fVar1) {

          *(float *)((int)param_1 + 0x114) = fVar1;

        }

      }

      goto LAB_004a6a79;

    }

    fVar4 = (float10)fVar2;

  }

  fVar4 = fVar4 + (float10)*(float *)((int)param_1 + 0x114);

  *(float *)((int)param_1 + 0x114) = (float)fVar4;

  if ((float10)fVar1 < fVar4) {

    *(float *)((int)param_1 + 0x114) = fVar1;

  }

LAB_004a6a79:

  fVar4 = (float10)FUN_00518b70(param_1,0);

  fVar1 = (float)(((float10)*(float *)((int)param_1 + 0x124) +

                  (float10)*(float *)((int)param_1 + 0x114)) * fVar4 * (float10)0.5);

  if (((*(uint *)((int)param_1 + 0xd8) & 0x1000000) != 0) &&

     (((fVar4 = (float10)playerobj_turn(*(undefined4 *)((int)param_1 + 0x158),

                                        *(undefined4 *)((int)param_1 + 200)), (float10)0.0 < fVar4

       && (fVar4 < (float10)fVar1)) || ((fVar4 < (float10)0.0 && ((float10)fVar1 < fVar4)))))) {

    *(undefined4 *)((int)param_1 + 0x124) = 0;

    *(undefined4 *)((int)param_1 + 0x114) = 0;

    fVar1 = (float)fVar4;

  }

  param_1 = fVar1;

  param_1 = param_1 + *(float *)(iVar3 + 200);

  *(float *)(iVar3 + 200) = param_1;

  if (360.0 <= param_1) {

    *(float *)(iVar3 + 200) = param_1 - 360.0;

  }

  if (*(float *)(iVar3 + 200) < 0.0) {

    *(float *)(iVar3 + 200) = *(float *)(iVar3 + 200) + 360.0;

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

/* ===== obj_scale_compute @ 0x004A6C00 ===== */
/* PS2 candidate: playerobj_walkrun (conf 0.474) */



void obj_scale_compute(float param_1)



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

  sine_cos_lookup(*(undefined4 *)((int)param_1 + 200),&local_8,&local_4);

  fVar3 = (float)(int)*(char *)((int)param_1 + 0x20a) * 0.03125;

  fVar6 = (float10)FUN_00518b70(param_1,0);

  fVar1 = (float)(fVar6 * (float10)fVar3 * (float10)*(float *)((int)param_1 + 400));

  fVar3 = fVar3 * *(float *)((int)param_1 + 0x194);

  iVar5 = ObjIsMecc(param_1);

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

  iVar5 = ObjIsMecc(iVar4);

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

  object_add_location(iVar4,local_c,local_10,0);

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

  object_add_location(param_1,0,0,

                      (float)(((float10)*(float *)(param_1 + 0x118) +

                              (float10)*(float *)(param_1 + 0x108)) * fVar1 * (float10)0.5));

  return;

}

/* ===== ObjectCalculateTransform @ 0x004A7440 ===== */
/* PS2 candidate: ObjectCalculateTransform (conf 0.497) */



void ObjectCalculateTransform(int param_1)



{

  float fVar1;

  uint uVar2;

  uint uVar3;

  float local_18;

  float local_14;

  float local_10;

  float local_c;

  float local_8;

  float local_4;

  

  if ((*(uint *)(param_1 + 0xd8) & 0x10000) == 0) {

    fVar1 = *(float *)(param_1 + 0xc4);

    sine_cos_lookup(-*(float *)(param_1 + 0xcc),&local_18,&local_14);

    sine_cos_lookup(*(undefined4 *)(param_1 + 0xd0),&local_4,&local_8);

    sine_cos_lookup(*(undefined4 *)(param_1 + 200),&local_10,&local_c);

    *(float *)(param_1 + 0x298) = local_c * local_8 * fVar1;

    *(float *)(param_1 + 0x29c) = (-(local_18 * local_c * local_4) - local_10 * local_14) * fVar1;

    *(float *)(param_1 + 0x2a0) = (local_10 * local_18 - local_c * local_4 * local_14) * fVar1;

    *(float *)(param_1 + 0x2a8) = local_10 * local_8 * fVar1;

    *(float *)(param_1 + 0x2ac) = (local_c * local_14 - local_10 * local_4 * local_18) * fVar1;

    *(float *)(param_1 + 0x2b0) = (-(local_10 * local_4 * local_14) - local_c * local_18) * fVar1;

    *(float *)(param_1 + 0x2b8) = local_4 * fVar1;

    *(float *)(param_1 + 700) = local_8 * local_18 * fVar1;

    *(float *)(param_1 + 0x2c0) = local_8 * local_14 * fVar1;

    if (*(int *)(param_1 + 0xc4) == 0x3f800000) {

      uVar3 = 0;

    }

    else {

      uVar3 = 2;

    }

    if (0.0 <= *(float *)(param_1 + 0xc4)) {

      uVar2 = 0;

    }

    else {

      uVar2 = 8;

    }

    *(uint *)(param_1 + 0x294) = uVar2 | uVar3 | 1;

  }

  *(undefined4 *)(param_1 + 0x2a4) = *(undefined4 *)(param_1 + 0xa0);

  *(uint *)(param_1 + 0x294) = *(uint *)(param_1 + 0x294) | 0x10;

  *(undefined4 *)(param_1 + 0x2b4) = *(undefined4 *)(param_1 + 0xa4);

  *(undefined4 *)(param_1 + 0x2c4) = *(undefined4 *)(param_1 + 0xa8);

  *(undefined4 *)(param_1 + 0x2d0) = 0;

  *(undefined4 *)(param_1 + 0x2cc) = 0;

  *(undefined4 *)(param_1 + 0x2c8) = 0;

  *(undefined4 *)(param_1 + 0x2d4) = 0x3f800000;

  *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) | 0x20;

  return;

}

/* ===== tracer_entry_angle @ 0x004A7630 ===== */
float10 tracer_entry_angle(int param_1,int param_2)



{

  float10 fVar1;

  undefined1 local_44 [8];

  float fStack_3c;

  float fStack_2c;

  

  (*(code *)PTR_crt_matrix_mul_00580c18)

            (local_44,param_1 + 0x294,param_2 * 0x44 + *(int *)(param_1 + 0x2dc));

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

/* ===== playerobj_eval_refpt @ 0x004A76E0 ===== */
/* PS2 candidate: playerobj_eval_refpt (conf 0.712) */



void playerobj_eval_refpt(int param_1,int param_2,undefined4 *param_3)



{

  int iVar1;

  undefined4 local_c;

  undefined4 local_8;

  undefined4 local_4;

  

  if ((char)param_2 < '\0') {

    local_4 = 0;

    local_8 = 0;

    local_c = 0;

    xformobj_p3d_world(param_1,&local_c,param_3);

    return;

  }

  if ((-1 < param_2) && (param_2 < *(int *)(param_1 + 0x2d8))) {

    iVar1 = param_2 * 0x44 + *(int *)(param_1 + 0x2dc);

    local_c = *(undefined4 *)(iVar1 + 0x10);

    local_8 = *(undefined4 *)(iVar1 + 0x20);

    local_4 = *(undefined4 *)(iVar1 + 0x30);

    xformobj_p3d_world(param_1,&local_c,param_3);

    return;

  }

  *param_3 = *(undefined4 *)(param_1 + 0xa0);

  param_3[1] = *(undefined4 *)(param_1 + 0xa4);

  param_3[2] = *(undefined4 *)(param_1 + 0xa8);

  return;

}

/* ===== sound_play_player_noparent @ 0x004A7790 ===== */
/* PS2 candidate: sound_play_player_noparent (conf 0.524) */



void sound_play_player_noparent(int param_1)



{

  if (param_1 == DAT_00632a88) {

    dlog_objname_menu();

  }

  *(undefined4 *)(param_1 + 0x208) = 0;

  *(undefined4 *)(param_1 + 0x20c) = 0;

  return;

}

/* ===== playerobj_zap_movement @ 0x004A77C0 ===== */
/* PS2 candidate: playerobj_zap_movement (conf 0.325) */



void playerobj_zap_movement(int param_1)



{

  *(undefined4 *)(param_1 + 0xac) = *(undefined4 *)(param_1 + 0xa0);

  *(undefined4 *)(param_1 + 0xb0) = *(undefined4 *)(param_1 + 0xa4);

  *(undefined4 *)(param_1 + 0xb4) = *(undefined4 *)(param_1 + 0xa8);

  *(undefined4 *)(param_1 + 0x118) = 0;

  *(undefined4 *)(param_1 + 0x108) = 0;

  *(undefined4 *)(param_1 + 0x11c) = 0;

  *(undefined4 *)(param_1 + 0x10c) = 0;

  *(undefined4 *)(param_1 + 0x120) = 0;

  *(undefined4 *)(param_1 + 0x110) = 0;

  *(undefined4 *)(param_1 + 0x130) = 0;

  *(undefined4 *)(param_1 + 300) = 0;

  *(undefined4 *)(param_1 + 0x128) = 0;

  *(undefined4 *)(param_1 + 0x13c) = 0;

  *(undefined4 *)(param_1 + 0x138) = 0;

  *(undefined4 *)(param_1 + 0x134) = 0;

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

/* ===== math_sign_of @ 0x004A7CB0 ===== */
char math_sign_of(void)



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

/* ===== math_clamp_sign @ 0x004A7D70 ===== */
char math_clamp_sign(float param_1)



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

/* ===== math_sincos_pair @ 0x004A7DF0 ===== */
void math_sincos_pair(float *param_1,float param_2,undefined4 param_3)



{

  float *pfVar1;

  float *pfVar2;

  

  pfVar2 = param_1;

  pfVar1 = param_1 + 1;

  sine_cos_lookup(param_2,param_1,pfVar1);

  *pfVar1 = -*pfVar1;

  sine_cos_lookup(param_3,&param_2,&param_1);

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

/* ===== PROJ_DefGet @ 0x004A8F50 ===== */
/* PS2 candidate: PROJ_DefGet (conf 0.51) */



undefined4 * PROJ_DefGet(int param_1)



{

  if ((-1 < param_1) && (param_1 < 0x35)) {

    return &DAT_005a2588 + param_1 * 0x55;

  }

  return (undefined4 *)0x0;

}

/* ===== IconDef_entry_ptr @ 0x004A8F70 ===== */
undefined * IconDef_entry_ptr(int param_1)



{

  if ((-2 < param_1) && (param_1 < 0x4b)) {

    return &DAT_005a0f44 + param_1 * 0x4c;

  }

  return (undefined *)0x0;

}

/* ===== IconDef_valid_check @ 0x004A8F90 ===== */
undefined4 IconDef_valid_check(int param_1)



{

  if (((-2 < param_1) && (param_1 < 0x4b)) &&

     ((undefined4 *)(&DAT_005a0f44 + param_1 * 0x4c) != (undefined4 *)0x0)) {

    return *(undefined4 *)(&DAT_005a0f44 + param_1 * 0x4c);

  }

  return 0;

}

/* ===== IconDefWieldType @ 0x004A8FB0 ===== */
/* PS2 candidate: IconDefWieldType (conf 0.53) */



undefined4 IconDefWieldType(int param_1,int param_2)



{

  if (((-2 < param_1) && (param_1 < 0x4b)) && (param_1 = param_1 * 0x4c, param_1 != -0x5a0f44)) {

    if (param_2 != 0) {

      return *(undefined4 *)(&DAT_005a0f48 + param_1);

    }

    return *(undefined4 *)(&DAT_005a0f4c + param_1);

  }

  return 0;

}

/* ===== IconDef_0x50_get @ 0x004A8FE0 ===== */
undefined4 IconDef_0x50_get(int param_1)



{

  if (((-2 < param_1) && (param_1 < 0x4b)) && (param_1 * 0x4c != -0x5a0f44)) {

    return *(undefined4 *)(&DAT_005a0f50 + param_1 * 0x4c);

  }

  return 0xffffffff;

}

/* ===== IconDefAmmoIcon @ 0x004A9010 ===== */
/* PS2 candidate: IconDefAmmoIcon (conf 0.534) */



undefined4 IconDefAmmoIcon(int param_1)



{

  if (((-2 < param_1) && (param_1 < 0x4b)) && (param_1 * 0x4c != -0x5a0f44)) {

    return *(undefined4 *)(&DAT_005a0f54 + param_1 * 0x4c);

  }

  return 0xffffffff;

}

/* ===== IconDefProjectile @ 0x004A9040 ===== */
/* PS2 candidate: IconDefProjectile (conf 0.507) */



undefined4 IconDefProjectile(int param_1)



{

  if (((-2 < param_1) && (param_1 < 0x4b)) && (param_1 * 0x4c != -0x5a0f44)) {

    return *(undefined4 *)(&DAT_005a0f58 + param_1 * 0x4c);

  }

  return 0xffffffff;

}

/* ===== IconDefMaxAmmo @ 0x004A9070 ===== */
/* PS2 candidate: IconDefMaxAmmo (conf 0.443) */



undefined4 IconDefMaxAmmo(int param_1)



{

  if (((-2 < param_1) && (param_1 < 0x4b)) && (param_1 * 0x4c != -0x5a0f44)) {

    return *(undefined4 *)(&DAT_005a0f60 + param_1 * 0x4c);

  }

  return 0xffffffff;

}

/* ===== IconDefGiveAmmo @ 0x004A90A0 ===== */
/* PS2 candidate: IconDefGiveAmmo (conf 0.454) */



undefined4 IconDefGiveAmmo(int param_1)



{

  if (((-2 < param_1) && (param_1 < 0x4b)) && (param_1 * 0x4c != -0x5a0f44)) {

    return *(undefined4 *)(&DAT_005a0f64 + param_1 * 0x4c);

  }

  return 0xffffffff;

}

/* ===== IconDef_0x68_get @ 0x004A90D0 ===== */
undefined4 IconDef_0x68_get(int param_1)



{

  if (((-2 < param_1) && (param_1 < 0x4b)) && (param_1 * 0x4c != -0x5a0f44)) {

    return *(undefined4 *)(&DAT_005a0f68 + param_1 * 0x4c);

  }

  return 0xffffffff;

}

/* ===== IconDef_0x6c_get @ 0x004A9100 ===== */
undefined4 IconDef_0x6c_get(int param_1)



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

  

  iVar1 = stream_player_start(s_weapondefs_bin_0055fd48);

  if (iVar1 == 0) {

    FUN_0051ea20(s_Error__Can_t_load_the_projectile_0055fd20);

    return;

  }

  BinFileRead(iVar1,&local_8,8);

  puVar2 = _malloc(local_4);

  *puVar2 = local_8;

  puVar2[1] = local_4;

  BinFileRead(iVar1,puVar2 + 2,local_4 - 8);

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

  crt_free_ext(puVar2);

  return;

}

/* ===== bbox_center_calc @ 0x004A9F30 ===== */
void bbox_center_calc(float *param_1,int param_2)



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

/* ===== ObjectGetWorldRefPoint__FP3P3DiP6OBJECT @ 0x004A9FE0 ===== */
/* PS2 candidate: ObjectGetWorldRefPoint__FP3P3DiP6OBJECT (conf 0.793) */



void ObjectGetWorldRefPoint__FP3P3DiP6OBJECT(undefined4 param_1,int param_2)



{

  undefined1 local_c [12];

  

  if (-1 < param_2) {

    playerobj_eval_refpt(param_1,param_2,local_c);

  }

  return;

}

/* ===== PROJ_CreateBasic @ 0x004AA0B0 ===== */
/* PS2 candidate: PROJ_CreateBasic (conf 0.422) */



int PROJ_CreateBasic(int param_1,undefined4 param_2)



{

  uint *puVar1;

  int iVar2;

  uint *puVar3;

  int iVar4;

  uint *puVar5;

  uint *puVar6;

  

  if ((param_1 < 0) || (0x34 < param_1)) {

    puVar3 = (uint *)0x0;

  }

  else {

    puVar3 = &DAT_005a2588 + param_1 * 0x55;

  }

  iVar2 = object_allocate_type_end(*puVar3,0x21);

  object_change_ospec(iVar2,0x4d);

  *(undefined4 *)(iVar2 + 0x18c) = param_2;

  *(uint *)(iVar2 + 0x1c8) = *(uint *)(iVar2 + 0x1c8) | 0x600;

  ObjectCalculateTransform(iVar2);

  puVar1 = *(uint **)(iVar2 + 0x100);

  if ((~*puVar1 & 1) != 0) {

    *(uint **)(iVar2 + 0x104) = puVar1 + 8;

    puVar1[0x6c] = 0xffffffff;

    PhysicsExZeroForce(iVar2);

    *puVar1 = *puVar1 | 1;

  }

  if ((puVar3[1] & 0x4000) != 0) {

    *(uint *)(iVar2 + 0x1c8) = *(uint *)(iVar2 + 0x1c8) | 0x20000;

  }

  puVar1 = *(uint **)(iVar2 + 0x100);

  if ((~puVar3[1] & 2) != 0) {

    *puVar1 = *puVar1 | 0x20;

  }

  iVar4 = *(int *)(iVar2 + 0x104);

  *(uint *)(iVar4 + 8) = puVar3[0x15];

  *(uint *)(iVar4 + 4) = puVar3[0x16];

  *(uint *)(iVar4 + 0xc) = puVar3[0x17];

  *(uint *)(iVar4 + 0x10) = puVar3[0x18];

  *(uint *)(iVar4 + 0x30) = puVar3[0x19];

  *(uint *)(iVar4 + 0x34) = puVar3[0x1c];

  if ((char)puVar3[0x1e] != '\0') {

    fx_get_free_effect__Fv();

  }

  if ((param_1 < 0) || (0x34 < param_1)) {

    puVar5 = (uint *)0x0;

  }

  else {

    puVar5 = (uint *)(&DAT_0055f6d0 + param_1 * 0x1c);

  }

  puVar6 = puVar1;

  for (iVar4 = 7; puVar6 = puVar6 + 1, iVar4 != 0; iVar4 = iVar4 + -1) {

    *puVar6 = *puVar5;

    puVar5 = puVar5 + 1;

  }

  puVar5 = puVar1 + 0x17;

  for (iVar4 = 0x55; iVar4 != 0; iVar4 = iVar4 + -1) {

    *puVar5 = *puVar3;

    puVar3 = puVar3 + 1;

    puVar5 = puVar5 + 1;

  }

  *(char *)(puVar1 + 0x79) = (char)param_1;

  puVar3 = (uint *)XFGetCameraOrigin();

  puVar1[0x7b] = *puVar3;

  puVar1[0x7c] = puVar3[1];

  puVar1[0x7d] = puVar3[2];

  return iVar2;

}

/* ===== PROJ_Create2 @ 0x004AA230 ===== */
/* PS2 candidate: PROJ_Create2 (conf 0.479) */



int PROJ_Create2(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,

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

  iVar2 = PROJ_CreateBasic(param_1,param_2);

  if ((param_1 < 0) || (0x34 < param_1)) {

    puVar7 = (undefined4 *)0x0;

  }

  else {

    puVar7 = &DAT_005a2588 + param_1 * 0x55;

  }

  local_130 = *(int *)(iVar2 + 0x100);

  local_128 = *(int *)(iVar2 + 0x104);

  *(undefined4 *)(local_130 + 0x1d0) = param_5;

  playerobj_eval_refpt(param_3,param_4,&local_13c);

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

    GEO_MatLookAt(local_44,&local_13c,&local_10c,&local_118);

    GEO_MatFromQuat_3(local_88,0xbfc90fdb);

    (*(code *)PTR_crt_matrix_mul_00580c18)(local_100,local_44,local_88);

    object_set_location(iVar2,uStack_f0,uStack_e0,uStack_d0);

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

    fVar10 = (float10)powf();

    local_12c = (float)(fVar10 * (float10)0.1);

    local_11c = (*(float *)(local_128 + 4) / *(float *)(local_128 + 8)) * -32.17405;

    trajectory_calculate(iVar2 + 0x128,&local_13c,param_6,&local_124,local_12c);

    object_set_location_p3d(iVar2,&local_13c);

  }

  puVar11 = puVar7 + 0x36;

  if (*(char *)(puVar7 + 0x36) != '\0') {

    puVar13 = local_bc;

    uVar12 = 0x24;

    local_a4 = param_3;

    local_a8 = param_4;

    local_ac = 8;

    uVar3 = fx_get_free_effect__Fv();

    fx_process_one(uVar3,0,puVar11,uVar12,puVar13);

  }

  PROJ_ObjectFinalize(iVar2);

  iVar5 = local_130;

  if ((*(byte *)(puVar7 + 1) & 1) != 0) {

    iVar4 = ObjIsMecc(*(undefined4 *)(local_130 + 0x1d0));

    if (iVar4 != 0) {

      iVar4 = mecc_in_gyro(*(undefined4 *)(iVar5 + 0x1d0));

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

/* ===== PROJ_Create3 @ 0x004AA550 ===== */
/* PS2 candidate: PROJ_Create3 (conf 0.591) */



int PROJ_Create3(int param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,

                undefined4 *param_5,undefined4 param_6)



{

  int iVar1;

  uint uVar2;

  int iVar3;

  int iVar4;

  int *piVar5;

  undefined4 *puVar6;

  undefined4 *puVar7;

  

  iVar3 = PROJ_CreateBasic(param_1,param_2);

  *(uint *)(iVar3 + 0x1c8) = *(uint *)(iVar3 + 0x1c8) & 0xfffdffff;

  if ((param_1 < 0) || (0x34 < param_1)) {

    param_2 = (undefined4 *)0x0;

  }

  else {

    param_2 = &DAT_005a2588 + param_1 * 0x55;

  }

  iVar1 = *(int *)(iVar3 + 0x100);

  *(undefined4 *)(iVar1 + 0x1d0) = param_6;

  object_set_location(iVar3,param_5[4],param_5[8],param_5[0xc]);

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

  PROJ_ObjectFinalize(iVar3);

  if ((*(byte *)(param_2 + 1) & 1) != 0) {

    iVar4 = ObjIsMecc(*(undefined4 *)(iVar1 + 0x1d0));

    if (iVar4 != 0) {

      iVar4 = mecc_in_gyro(*(undefined4 *)(iVar1 + 0x1d0));

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

/* ===== obj_targetable_by_player @ 0x004AA6D0 ===== */
bool obj_targetable_by_player(int param_1,int param_2)



{

  int iVar1;

  int iVar2;

  uint uVar3;

  

  iVar2 = FUN_004a6220(param_1);

  if ((((iVar2 == 0) && (iVar2 = meccbasepit_bldg_from_object(param_1), iVar2 == 0)) &&

      (iVar2 = ObjIsReaperBldg(param_1), iVar2 == 0)) &&

     (iVar2 = reaperbase_bldg_from_object(param_1), iVar2 == 0)) {

    if (((*(char *)(param_1 + 0x1f5) != '\0') ||

        (uVar3 = *(uint *)(param_1 + 0xd8) & 0x4000c000,

        (~*(uint *)(param_1 + 0x1c8) >> 0x11 & 1) != 0 || uVar3 != 0)) ||

       ((uVar3 != 0 || (*(float *)(param_1 + 0x1c0) <= *(float *)(param_1 + 0x278))))) {

      return false;

    }

  }

  else if ((~*(uint *)(param_1 + 0x1c8) >> 0x11 & 1) != 0 ||

           (*(uint *)(param_1 + 0xd8) & 0x4000c000) != 0) {

    return false;

  }

  iVar2 = *(int *)(param_1 + 0x210);

  while (iVar1 = iVar2, iVar1 != 0) {

    param_1 = iVar1;

    iVar2 = *(int *)(iVar1 + 0x210);

  }

  iVar2 = dialog_level_is_base();

  if (((((iVar2 == 0) || (DAT_00632f20 == 0)) || (iVar2 = ObjIsPlayer(param_1), iVar2 == 0)) &&

      (((iVar2 = FUN_004a6220(param_1), iVar2 == 0 && (iVar2 = ObjIsReaperBldg(param_1), iVar2 == 0)

        ) && (*(int *)(param_1 + 0x1e0) != 0x2c)))) && (*(int *)(param_1 + 0x1e0) != 0x5f)) {

    return *(int *)(param_1 + 0x18c) != param_2;

  }

  return true;

}

/* ===== obj_targetable_by_player_2 @ 0x004AA7F0 ===== */
bool obj_targetable_by_player_2(int param_1,int param_2)



{

  int iVar1;

  int iVar2;

  uint uVar3;

  

  iVar2 = FUN_004a6220(param_1);

  if ((((iVar2 == 0) && (iVar2 = meccbasepit_bldg_from_object(param_1), iVar2 == 0)) &&

      (iVar2 = ObjIsReaperBldg(param_1), iVar2 == 0)) &&

     (iVar2 = reaperbase_bldg_from_object(param_1), iVar2 == 0)) {

    if (((*(char *)(param_1 + 0x1f5) != '\0') ||

        (uVar3 = *(uint *)(param_1 + 0xd8) & 0x4000c000,

        (~*(uint *)(param_1 + 0x1c8) >> 0x11 & 1) != 0 || uVar3 != 0)) ||

       ((uVar3 != 0 || (*(float *)(param_1 + 0x1c0) <= *(float *)(param_1 + 0x278))))) {

      return false;

    }

  }

  else if ((~*(uint *)(param_1 + 0x1c8) >> 0x11 & 1) != 0 ||

           (*(uint *)(param_1 + 0xd8) & 0x4000c000) != 0) {

    return false;

  }

  iVar2 = *(int *)(param_1 + 0x210);

  while (iVar1 = iVar2, iVar1 != 0) {

    param_1 = iVar1;

    iVar2 = *(int *)(iVar1 + 0x210);

  }

  iVar2 = FUN_004a6220(param_1);

  if (((iVar2 == 0) && (iVar2 = ObjIsReaperBldg(param_1), iVar2 == 0)) &&

     ((*(int *)(param_1 + 0x1e0) != 0x2c && (*(int *)(param_1 + 0x1e0) != 0x5f)))) {

    return *(int *)(param_1 + 0x18c) != param_2;

  }

  return true;

}

/* ===== obj_targetable_by_player_3 @ 0x004AA8F0 ===== */
bool obj_targetable_by_player_3(int param_1,int param_2)



{

  int iVar1;

  int iVar2;

  uint uVar3;

  

  iVar2 = FUN_004a6220(param_1);

  if ((((iVar2 == 0) && (iVar2 = meccbasepit_bldg_from_object(param_1), iVar2 == 0)) &&

      (iVar2 = ObjIsReaperBldg(param_1), iVar2 == 0)) &&

     (iVar2 = reaperbase_bldg_from_object(param_1), iVar2 == 0)) {

    if (((*(char *)(param_1 + 0x1f5) != '\0') ||

        (uVar3 = *(uint *)(param_1 + 0xd8) & 0x4000c000,

        (~*(uint *)(param_1 + 0x1c8) >> 0x11 & 1) != 0 || uVar3 != 0)) ||

       ((uVar3 != 0 || (*(float *)(param_1 + 0x1c0) <= *(float *)(param_1 + 0x278))))) {

      return false;

    }

  }

  else if ((~*(uint *)(param_1 + 0x1c8) >> 0x11 & 1) != 0 ||

           (*(uint *)(param_1 + 0xd8) & 0x4000c000) != 0) {

    return false;

  }

  if (*(int *)(param_1 + 0x1e0) != 0x12) {

    iVar2 = *(int *)(param_1 + 0x210);

    while (iVar1 = iVar2, iVar1 != 0) {

      param_1 = iVar1;

      iVar2 = *(int *)(iVar1 + 0x210);

    }

    return *(int *)(param_1 + 0x18c) != param_2;

  }

  return false;

}

/* ===== obj_targetable_by_player_4 @ 0x004AA9D0 ===== */
undefined4 obj_targetable_by_player_4(int param_1,int param_2)



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

    iVar2 = dialog_level_is_base();

    if ((((((iVar2 != 0) && (DAT_00632f20 != 0)) && (iVar2 = ObjIsPlayer(param_1), iVar2 != 0)) ||

         ((iVar2 = FUN_004a6220(param_1), iVar2 != 0 ||

          (iVar2 = ObjIsReaperBldg(param_1), iVar2 != 0)))) ||

        ((*(int *)(param_1 + 0x1e0) == 0x2c ||

         ((*(int *)(param_1 + 0x1e0) == 0x5f || (*(int *)(param_1 + 0x18c) != param_2)))))) ||

       ((*(int *)(param_1 + 4) == 0x325 && (*(int *)(param_1 + 0xe4) != 1)))) {

      return 1;

    }

  }

  return 0;

}

/* ===== MortarCollisionValid__FP6OBJECTi @ 0x004AAA80 ===== */
/* PS2 candidate: MortarCollisionValid__FP6OBJECTi (conf 0.62) */



undefined4 MortarCollisionValid__FP6OBJECTi(int param_1,int param_2)



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

    iVar2 = dialog_level_is_base();

    if ((((((iVar2 != 0) && (DAT_00632f20 != 0)) && (iVar2 = ObjIsPlayer(param_1), iVar2 != 0)) ||

         ((iVar2 = FUN_004a6220(param_1), iVar2 != 0 ||

          (iVar2 = ObjIsReaperBldg(param_1), iVar2 != 0)))) ||

        ((*(int *)(param_1 + 0x1e0) == 0x2c || (*(int *)(param_1 + 0x1e0) == 0x5f)))) ||

       (((*(int *)(param_1 + 4) != 0x325 || (*(int *)(param_1 + 0xe4) != 1)) &&

        ((iVar2 = ObjIsPlayer(param_1), iVar2 == 0 || (*(int *)(param_1 + 0x18c) != param_2)))))) {

      return 1;

    }

  }

  return 0;

}

/* ===== cast_repair_spell @ 0x004AAB40 ===== */
void cast_repair_spell(undefined4 param_1,int param_2,int param_3,int param_4,undefined4 param_5,

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

    object_destroy(param_1);

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

    object_destroy(param_1);

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

      iVar2 = objanim_select_animloop(param_4[6]);

      *(int *)(param_1 + 0x274) = iVar2;

      *(undefined4 *)(param_1 + 0x18c) = *(undefined4 *)(iVar2 + 0x18c);

      return;

    }

    break;

  case 7:

    uVar5 = objanim_select_animloop(*param_4);

    *(undefined4 *)(iVar2 + 0x1d8) = uVar5;

    *(uint *)(param_1 + 0xe4) = (uint)*(byte *)(param_4 + 1);

    break;

  case 8:

    iVar3 = fx_create(param_1);

    if (iVar3 == 0) {

      iVar3 = objanim_select_animloop(param_4[3]);

      uVar5 = param_4[4];

      iVar4 = object_allocate_type(0x374,0);

      object_change_ospec(iVar4,0x28);

      object_set_location(iVar4,*param_4,param_4[1],param_4[2]);

      *(undefined4 *)(iVar4 + 0x18c) = *(undefined4 *)(param_1 + 0x18c);

      if (iVar3 != 0) {

        *(int *)(iVar4 + 0x274) = iVar3;

      }

      local_54 = 0xffffffff;

      local_50 = iVar4;

      fx_get_free_effect__Fv();

      iVar3 = fx_create(param_1);

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

    iVar3 = fx_create(param_1);

    if (iVar3 == 0) {

      uVar5 = param_4[3];

      iVar3 = object_allocate_type(0x374,0);

      object_change_ospec(iVar3,0x28);

      object_set_location(iVar3,*param_4,param_4[1],param_4[2]);

      puVar8 = local_34;

      *(undefined4 *)(iVar3 + 0x18c) = *(undefined4 *)(param_1 + 0x18c);

      uVar7 = 4;

      pcVar6 = s_fx_repair_spell_ground_0055fd7c;

      local_20 = 0xffffffff;

      local_1c = iVar3;

      fx_get_free_effect__Fv();

      iVar4 = fx_create(param_1,pcVar6,uVar7,puVar8);

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

        object_destroy(param_1);

        return;

      }

      sound_play_3dpos(iVar3,param_4);

      object_destroy(param_1);

      return;

    }

    goto LAB_004ac24a;

  case 10:

    *(uint *)(iVar2 + 0x60) = *(uint *)(iVar2 + 0x60) & 0xfffeffff;

    iVar2 = objanim_select_animloop(*param_4);

    if (iVar2 != 0) {

      *(int *)(*(int *)(iVar2 + 0x100) + 0x1d0) = param_1;

      return;

    }

    break;

  case 100:

    uVar5 = objanim_select_animloop(*param_4);

    sf_is_valid_target__FP6OBJECT(param_1,uVar5);

    return;

  case 0x65:

    reaper_ability_3dsound(param_1);

    return;

  }

  return;

}

/* ===== face_target @ 0x004AC4B0 ===== */
/* PS2 candidate: face_target (conf 0.504) */



void face_target(int param_1,float *param_2,int param_3,float param_4,float param_5)



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

  GEO_Vec3Normalize(&local_12c,&local_12c);

  GEO_Vec3Normalize(&local_138,&local_138);

  Dot__FP3P3DT0(&local_12c,&local_138);

  fVar1 = (float10)FUN_005445f0();

  if (fVar1 != (float10)0.0) {

    fVar2 = (float10)param_4 * fVar1 * (float10)param_5;

    if (fVar1 < fVar2) {

      fVar2 = fVar1;

    }

    vec_cross_normalize(local_120,&local_12c,&local_138,(float)(fVar2 / fVar1));

    quat_to_matrix__FP4QUATPf(local_88,local_120);

    GEO_MatCopy(local_44,local_110,param_1 + 0x294);

    (*(code *)PTR_crt_matrix_mul_00580c18)(local_cc,local_88,local_110);

    (*(code *)PTR_crt_matrix_mul_00580c18)(param_1 + 0x294,local_44,local_cc);

    return;

  }

  return;

}

/* ===== align_with_ground @ 0x004AC620 ===== */
/* PS2 candidate: align_with_ground (conf 0.56) */



void align_with_ground(int param_1,float *param_2,float param_3)



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

  GEO_MatCopy(local_44,local_110,param_1 + 0x294);

  local_138 = local_104;

  local_134 = local_f4;

  local_130 = local_e4;

  GEO_Vec3Normalize(&local_138,&local_138);

  vec_cross_normalize(local_120,&local_138,&local_12c,local_13c);

  quat_to_matrix__FP4QUATPf(local_cc,local_120);

  (*(code *)PTR_crt_matrix_mul_00580c18)(local_88,local_cc,local_110);

  (*(code *)PTR_crt_matrix_mul_00580c18)(param_1 + 0x294,local_44,local_88);

  return;

}

/* ===== kabuto_punch_check @ 0x004AC760 ===== */
bool kabuto_punch_check(int param_1)



{

  int iVar1;

  

  iVar1 = ObjIsReaper(param_1);

  if (iVar1 == 0) {

    iVar1 = ObjIsMecc(param_1);

    if (iVar1 == 0) {

      iVar1 = *(int *)(param_1 + 4);

      if (iVar1 == 8) {

        if (*(int *)(param_1 + 0xe4) != 6) {

          return false;

        }

      }

      else if (iVar1 == 0xb) {

        iVar1 = FUN_004ef510(param_1);

        if ((iVar1 != 0) && (*(int *)(param_1 + 0xe4) != 0x35)) {

          return false;

        }

      }

      else {

        if ((iVar1 != 0x438) && (iVar1 != 0x29a)) {

          if (iVar1 == 0xd7) {

            iVar1 = FUN_004d7b80();

            if (iVar1 == 0) {

              return true;

            }

            iVar1 = kabutoai_is_punch_anim__FP6OBJECT_3(param_1);

            return iVar1 != 0;

          }

          iVar1 = ObjIsRipper(param_1);

          if (iVar1 != 0) {

            iVar1 = FUN_004d49c0(param_1);

            if (iVar1 == 0) {

              return true;

            }

            iVar1 = kabutoai_is_punch_anim__FP6OBJECT_2(param_1);

            return iVar1 != 0;

          }

          if (*(int *)(param_1 + 4) != 0x232) {

            return true;

          }

        }

        if (*(int *)(param_1 + 0xe4) != 100) {

          return false;

        }

      }

    }

    else if ((*(byte *)(param_1 + 0xe0) & 0x40) == 0) {

      return false;

    }

  }

  else if ((*(byte *)(param_1 + 0xe0) & 0x20) == 0) {

    return false;

  }

  return true;

}

/* ===== reaper_ability_3dsound @ 0x004AC860 ===== */
/* PS2 candidate: sf_is_valid_target__FP6OBJECT (conf 0.391) */



void reaper_ability_3dsound(int param_1)



{

  uint *puVar1;

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

    iVar3 = ObjIsMecc(*(int *)(iVar4 + 0xc));

    if (iVar3 == 0) {

      iVar3 = ObjIsReaper(*(int *)(iVar4 + 0xc));

      if (iVar3 == 0) {

        iVar3 = *(int *)(iVar4 + 0xc);

        if (*(int *)(iVar3 + 4) == 8) {

          *(undefined4 *)(iVar3 + 0xe4) = 1;

        }

        else {

          if (*(int *)(iVar3 + 4) == 0xb) {

            iVar3 = FUN_004ef510(iVar3);

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

                ai_ospec12d_logic(*(undefined4 *)(iVar4 + 0xc));

                goto LAB_004ac9df;

              }

            }

            iVar3 = ObjIsRipper(*(undefined4 *)(iVar4 + 0xc));

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

/* ===== sf_is_valid_target__FP6OBJECT @ 0x004ACA20 ===== */
/* PS2 candidate: sf_is_valid_target__FP6OBJECT (conf 0.39) */



void sf_is_valid_target__FP6OBJECT(int param_1,int param_2)



{

  int iVar1;

  bool bVar2;

  int iVar3;

  int iVar4;

  undefined4 uVar5;

  int iVar6;

  int iVar7;

  undefined4 *puVar8;

  undefined4 *puVar9;

  undefined4 *local_38;

  

  iVar3 = param_2;

  iVar7 = param_1;

  iVar6 = *(int *)(*(int *)(param_1 + 0x100) + 0x1c);

  if (((param_2 == 0) ||

      ((((((iVar4 = ObjIsMecc(param_2), iVar4 == 0 && (iVar4 = ObjIsReaper(iVar3), iVar4 == 0)) &&

          (*(int *)(iVar3 + 4) != 8)) &&

         ((*(int *)(iVar3 + 4) != 0xb || (iVar4 = FUN_004ef510(iVar3), iVar4 == 0)))) &&

        ((iVar4 = *(int *)(iVar3 + 4), iVar4 != 0x438 && (iVar4 != 0x232)))) &&

       ((((iVar4 != 0xd7 || (iVar4 = FUN_004d7b80(iVar3), iVar4 == 0)) &&

         (*(int *)(iVar3 + 4) != 0x29a)) &&

        ((iVar4 = ObjIsRipper(iVar3), iVar4 == 0 || (iVar4 = FUN_004d49c0(iVar3), iVar4 == 0))))))))

     || (iVar4 = ObjIsJetski(*(undefined4 *)(iVar3 + 0x210)), iVar4 != 0)) {

    *(undefined4 *)(iVar6 + 0x14) = 1;

    sound_play_3dpos(0x3a9,iVar7 + 0xa0);

    goto LAB_004accab;

  }

  iVar4 = 0;

  do {

    iVar1 = *(int *)(iVar6 + iVar4 * 4);

    if (iVar1 != 0) {

      iVar1 = *(int *)(iVar1 + 0x100);

      if (iVar1 == 0) {

        return;

      }

      *(int *)(iVar1 + 0x1d0) = iVar3;

      if (*(int *)(iVar6 + iVar4 * 4) == iVar7) {

        local_38 = (undefined4 *)(iVar1 + 0x5c);

        param_2 = iVar4;

      }

    }

    iVar4 = iVar4 + 1;

  } while (iVar4 < 3);

  *(int *)(iVar6 + 0xc) = iVar3;

  *(undefined4 *)(iVar6 + 0x10) = 1;

  iVar4 = ObjIsMecc(iVar3);

  if (iVar4 == 0) {

    iVar4 = ObjIsReaper(iVar3);

    if (iVar4 == 0) {

      if (*(int *)(iVar3 + 4) == 8) {

        *(undefined4 *)(iVar3 + 0xe4) = 6;

      }

      else if ((*(int *)(iVar3 + 4) == 0xb) && (iVar4 = FUN_004ef510(iVar3), iVar4 != 0)) {

        *(undefined4 *)(iVar3 + 0xe4) = 0x35;

      }

      else {

        iVar4 = *(int *)(iVar3 + 4);

        if ((iVar4 == 0x438) || (iVar4 == 0x29a)) {

LAB_004acbe1:

          *(undefined4 *)(iVar3 + 0xe4) = 100;

        }

        else if ((iVar4 == 0xd7) && (iVar4 = FUN_004d7b80(iVar3), iVar4 != 0)) {

          FUN_004d7c60(iVar3,iVar7);

        }

        else {

          iVar4 = ObjIsRipper(iVar3);

          if ((iVar4 == 0) || (iVar4 = FUN_004d49c0(iVar3), iVar4 == 0)) {

            if (*(int *)(iVar3 + 4) == 0x232) goto LAB_004acbe1;

          }

          else {

            FUN_004d4a00(iVar3);

          }

        }

      }

    }

    else {

      *(uint *)(iVar3 + 0xe0) = *(uint *)(iVar3 + 0xe0) | 0x20;

    }

  }

  else {

    *(uint *)(iVar3 + 0xe0) = *(uint *)(iVar3 + 0xe0) | 0x40;

  }

  uVar5 = fx_get_free_effect__Fv();

  *(undefined4 *)(iVar6 + 0x1c) = uVar5;

  bVar2 = true;

  iVar4 = 0;

  do {

    if ((iVar4 != param_2) && (iVar1 = *(int *)(iVar6 + iVar4 * 4), iVar1 != 0)) {

      iVar1 = *(int *)(iVar1 + 0x100);

      puVar8 = local_38;

      puVar9 = (undefined4 *)(iVar1 + 0x5c);

      for (iVar7 = 0x55; iVar7 != 0; iVar7 = iVar7 + -1) {

        *puVar9 = *puVar8;

        puVar8 = puVar8 + 1;

        puVar9 = puVar9 + 1;

      }

      iVar7 = param_1;

      if (bVar2) {

        bVar2 = false;

        *(float *)(iVar1 + 0x6c) = *(float *)(DAT_00632ed8 + 0x918) * *(float *)(iVar1 + 0x6c);

      }

    }

    iVar4 = iVar4 + 1;

  } while (iVar4 < 3);

  sound_play_3dpos(0x3a8,iVar3 + 0xa0);

LAB_004accab:

  iVar6 = reaper_0052e4a0(iVar7);

  if (iVar6 != 0) {

    param_1 = *(undefined4 *)(iVar3 + 0x188);

    reaper_00530bd0(iVar7,0,1,0,100,&param_1);

  }

  return;

}

/* ===== sound_3dpos_user @ 0x004AD190 ===== */
void sound_3dpos_user(int param_1,int param_2)



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

  reaper_ability_3dsound(param_1);

  return;

}

/* ===== reapertrail_logic @ 0x004AD7E0 ===== */
/* PS2 candidate: reapertrail_logic (conf 0.51) */



void reapertrail_logic(int param_1)



{

  uint *puVar1;

  

  puVar1 = *(uint **)(param_1 + 0x100);

  if (-1 < (char)*puVar1) {

    *puVar1 = *puVar1 | 0x484;

    puVar1[0x18] = puVar1[0x18] & 0xffffffcf;

    ObjectSetAnim(param_1,10,0x21,1,0x41a00000,0);

    *(undefined4 *)(param_1 + 0xe4) = 1;

  }

  return;

}

/* ===== repairgun_target_valid__FP6OBJECTi @ 0x004ADBF0 ===== */
/* PS2 candidate: repairgun_target_valid__FP6OBJECTi (conf 0.572) */



undefined4 repairgun_target_valid__FP6OBJECTi(int param_1,int param_2)



{

  int iVar1;

  int iVar2;

  float10 fVar3;

  float10 fVar4;

  

  if ((~*(uint *)(param_1 + 0x1c8) >> 0x11 & 1) == 0 &&

      (*(uint *)(param_1 + 0xd8) & 0x4000c000) == 0) {

    iVar2 = *(int *)(param_1 + 0x210);

    while (iVar1 = iVar2, iVar1 != 0) {

      param_1 = iVar1;

      iVar2 = *(int *)(iVar1 + 0x210);

    }

    iVar2 = FUN_004a6220(param_1);

    if (((iVar2 == 0) && (iVar2 = ObjIsMecc(param_1), iVar2 == 0)) &&

       (*(int *)(param_1 + 0x1e0) != 0x5f)) {

      iVar2 = ObjIsTurret(param_1);

      if ((((iVar2 != 0) && (*(int *)(param_1 + 0x18c) == param_2)) &&

          (0.0 < *(float *)(param_1 + 0x278))) &&

         (*(float *)(param_1 + 0x278) < *(float *)(param_1 + 0x1c0))) {

        return 1;

      }

    }

    else {

      iVar2 = ObjIsMecc(param_1);

      if ((iVar2 == 0) || (*(float *)(param_1 + 0x278) != 0.0)) {

        iVar2 = FUN_004a6220(param_1);

        if (iVar2 != 0) {

          fVar3 = (float10)bldg_get_energy(param_1);

          fVar4 = (float10)bldg_get_max_energy(param_1);

          if (fVar4 == (float10)(float)fVar3) {

            return 0;

          }

        }

        if (((*(int *)(param_1 + 4) != 0x447) && (*(int *)(param_1 + 4) != 0x342)) &&

           ((*(int *)(param_1 + 0x1e0) != 0x5f || (*(float *)(param_1 + 0x278) != 0.0)))) {

          if (*(int *)(param_1 + 0x18c) == param_2) {

            return 1;

          }

          iVar2 = FUN_004a6220(param_1);

          if (iVar2 != 0) {

            return 1;

          }

        }

      }

    }

  }

  return 0;

}

/* ===== PROJ_GetCustom @ 0x004ADD50 ===== */
/* PS2 candidate: PROJ_GetCustom (conf 0.528) */



undefined * PROJ_GetCustom(int param_1)



{

  if ((-1 < param_1) && (param_1 < 0x35)) {

    return &DAT_0055f6d0 + param_1 * 0x1c;

  }

  return (undefined *)0x0;

}

/* ===== fx_create_hack_logic @ 0x004ADD70 ===== */
/* PS2 candidate: fx_create_hack_logic (conf 0.458) */



void fx_create_hack_logic(int param_1)



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

/* ===== releaseMpegBuffers__Fv @ 0x004AE290 ===== */
/* PS2 candidate: releaseMpegBuffers__Fv (conf 0.831) */



void releaseMpegBuffers__Fv(void)



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
/* PS2 candidate: read_worlds_bin_fn_PS2 (conf 0.516) */



void read_objects_bin_PS2(void)



{

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

  undefined4 uVar16;

  undefined4 *puVar17;

  uint uVar18;

  int iVar19;

  int iVar20;

  int iVar21;

  uint uVar22;

  int *piVar23;

  byte *pbVar24;

  byte *pbVar25;

  int iVar26;

  char *pcVar27;

  float *pfVar28;

  float *pfVar29;

  float *pfVar30;

  float fVar31;

  float10 fVar32;

  uint uVar33;

  int iStack00000004;

  uint uStack00000008;

  char *pcStack0000000c;

  undefined4 *puStack00000010;

  int iStack00000014;

  int *piStack0000001c;

  undefined4 *in_stack_00000020;

  undefined4 *in_stack_00000030;

  

  FUN_00543e00();

  BinFileRead();

  piVar9 = (int *)MemAllocMsg();

  BinFileRead();

  pcStack0000000c = (char *)*piVar9;

  piStack0000001c = piVar9 + 1;

  puStack00000010 = (undefined4 *)MemAllocMsg();

  puVar10 = &DAT_00632d4c;

  for (puVar14 = DAT_00632d4c; puVar14 != (undefined4 *)0x0; puVar14 = (undefined4 *)*puVar14) {

    puVar10 = puVar14;

  }

  *puVar10 = puStack00000010;

  puVar10 = puStack00000010;

  for (uVar18 = (int)pcStack0000000c * 4 + 8U >> 2; uVar18 != 0; uVar18 = uVar18 - 1) {

    *puVar10 = 0;

    puVar10 = puVar10 + 1;

  }

  for (iVar19 = 0; iVar19 != 0; iVar19 = iVar19 + -1) {

    *(undefined1 *)puVar10 = 0;

    puVar10 = (undefined4 *)((int)puVar10 + 1);

  }

  puStack00000010[1] = pcStack0000000c;

  if (0 < (int)pcStack0000000c) {

    puStack00000010 = puStack00000010 + 2;

    do {

      uVar11 = *(undefined4 *)(*piStack0000001c + (int)piVar9);

      pcVar27 = (char *)((int)piVar9 + *piStack0000001c + 4);

      piStack0000001c = piStack0000001c + 1;

      crt_sprintf();

      puVar10 = (undefined4 *)object_clone_objectset();

      *puStack00000010 = puVar10;

      *puVar10 = uVar11;

      crt_sprintf();

      loadsave_save__FPCc();

      cVar1 = *pcVar27;

      while (cVar1 != '\0') {

        pcVar15 = pcVar27 + 1;

        pcVar27 = pcVar27 + 1;

        cVar1 = *pcVar15;

      }

      puStack00000010 = puStack00000010 + 1;

      pcStack0000000c = (char *)((int)pcStack0000000c + -1);

    } while (pcStack0000000c != (char *)0x0);

  }

  iVar19 = piStack0000001c[*piStack0000001c + 1];

  piStack0000001c = piStack0000001c + *piStack0000001c + 2;

  if (0 < iVar19) {

    in_stack_00000030 = (undefined4 *)MemAllocMsg();

    puVar10 = &DAT_00632d50;

    for (puVar14 = DAT_00632d50; puVar14 != (undefined4 *)0x0; puVar14 = (undefined4 *)*puVar14) {

      puVar10 = puVar14;

    }

    *puVar10 = in_stack_00000030;

    puVar10 = in_stack_00000030;

    for (uVar18 = iVar19 * 0x464 + 8U >> 2; uVar18 != 0; uVar18 = uVar18 - 1) {

      *puVar10 = 0;

      puVar10 = puVar10 + 1;

    }

    for (iVar20 = 0; iVar20 != 0; iVar20 = iVar20 + -1) {

      *(undefined1 *)puVar10 = 0;

      puVar10 = (undefined4 *)((int)puVar10 + 1);

    }

    in_stack_00000030[1] = iVar19;

  }

  iStack00000014 = 0;

  if (0 < iVar19) {

    do {

      iVar20 = *piStack0000001c;

      piStack0000001c = piStack0000001c + 1;

      puVar10 = in_stack_00000030 + iStack00000014 * 0x119 + 2;

      uVar18 = 0;

      puVar14 = (undefined4 *)&stack0x000004a8;

      for (iVar21 = 0x80; iVar21 != 0; iVar21 = iVar21 + -1) {

        *puVar14 = 0;

        puVar14 = puVar14 + 1;

      }

      puStack00000010 = (undefined4 *)0x0;

      uStack00000008 = 0;

      pcStack0000000c = (char *)0x0;

      *puVar10 = *(undefined4 *)(iVar20 + (int)piVar9);

      pbVar25 = (byte *)((undefined4 *)(iVar20 + (int)piVar9) + 1);

      iStack00000004 = 0;

      uVar33 = uVar18;

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

                          bVar2 = *pbVar25;

                          pbVar24 = pbVar25 + 1;

                          if (bVar2 != 0x51) break;

                          if (9 < iStack00000004) {

                            crt_sprintf();

                            FUN_0051ea20();

                          }

                          if (*(int *)pbVar24 == 0) {

                            puVar10[iStack00000004 + 0x100] = 0;

                          }

                          else {

                            uVar11 = objectset_find_2();

                            puVar10[iStack00000004 + 0x100] = uVar11;

                          }

                          fVar32 = (float10)*(float *)(pbVar25 + 5);

                          if (fVar32 == (float10)0.0) {

                            fVar32 = (float10)60.0;

                          }

                          fVar32 = (float10)fsin(fVar32 * (float10)0.008726646);

                          puVar10[iStack00000004 + 0x10a] =

                               (float)(fVar32 * (float10)*(float *)(pbVar25 + 9));

                          pbVar25 = pbVar25 + 0xd;

                          iStack00000004 = iStack00000004 + 1;

                        }

                        if (bVar2 != 0x59) break;

                        if (9 < iStack00000004) {

                          crt_sprintf();

                          FUN_0051ea20();

                        }

                        uVar11 = objectset_find_2();

                        puVar10[iStack00000004 + 0x100] = uVar11;

                        puVar10[iStack00000004 + 0x10a] = 0xc0400000;

                        iStack00000004 = iStack00000004 + 1;

                        pbVar25 = pbVar25 + 5;

                      }

                      if (bVar2 != 0x5a) break;

                      if (9 < iStack00000004) {

                        crt_sprintf();

                        FUN_0051ea20();

                      }

                      uVar11 = objectset_find_2();

                      puVar10[iStack00000004 + 0x100] = uVar11;

                      puVar10[iStack00000004 + 0x10a] = 0xbf800000;

                      iStack00000004 = iStack00000004 + 1;

                      pbVar25 = pbVar25 + 5;

                    }

                    if (bVar2 != 0x5b) break;

                    if (9 < iStack00000004) {

                      crt_sprintf();

                      FUN_0051ea20();

                    }

                    uVar11 = objectset_find_2();

                    puVar10[iStack00000004 + 0x100] = uVar11;

                    puVar10[iStack00000004 + 0x10a] = 0xc0000000;

                    iStack00000004 = iStack00000004 + 1;

                    crt_sprintf();

                    FUN_0051ea20();

                    pbVar25 = pbVar25 + 5;

                  }

                  if (bVar2 != 0x52) break;

                  if ((puStack00000010 != (undefined4 *)0x0) && (uVar18 != 0)) {

                    puVar12 = (uint *)MemAllocMsg();

                    *(uint **)((int)puStack00000010 + 0x24) = puVar12;

                    *puVar12 = uVar33;

                    puVar14 = *(undefined4 **)((int)puStack00000010 + 0x24);

                    puVar17 = (undefined4 *)&stack0x000000a8;

                    for (iVar20 = (uVar33 & 0x7ffffff) << 3; puVar14 = puVar14 + 1, iVar20 != 0;

                        iVar20 = iVar20 + -1) {

                      *puVar14 = *puVar17;

                      puVar17 = puVar17 + 1;

                    }

                    for (iVar20 = 0; uVar18 = uVar33, iVar20 != 0; iVar20 = iVar20 + -1) {

                      *(undefined1 *)puVar14 = *(undefined1 *)puVar17;

                      puVar17 = (undefined4 *)((int)puVar17 + 1);

                      puVar14 = (undefined4 *)((int)puVar14 + 1);

                    }

                  }

                  bVar2 = *pbVar24;

                  pbVar25 = pbVar25 + 2;

                  bVar3 = *pbVar25;

                  while (bVar3 != 0) {

                    pbVar24 = pbVar25 + 1;

                    pbVar25 = pbVar25 + 1;

                    bVar3 = *pbVar24;

                  }

                  pbVar25 = pbVar25 + 1;

                  if (puVar10[bVar2 + 2] == 0) {

                    AnimationCreate();

                    puStack00000010 = (undefined4 *)puVar10[bVar2 + 2];

                    uVar18 = 0;

                    puVar14 = (undefined4 *)&stack0x000000a8;

                    for (iVar20 = 0x100; uVar33 = uVar18, iVar20 != 0; iVar20 = iVar20 + -1) {

                      *puVar14 = 0;

                      puVar14 = puVar14 + 1;

                    }

                  }

                  else {

                    crt_sprintf();

                    FUN_0051ea20();

                  }

                }

                if (bVar2 != 0x56) break;

                if (0x1f < (int)uVar18) {

                  FUN_0051ea20();

                  uVar18 = 0;

                }

                iVar20 = *(int *)pbVar24;

                uVar11 = *(undefined4 *)(pbVar25 + 5);

                iVar21 = uVar18 * 0x20;

                pbVar25 = pbVar25 + 9;

                *(undefined4 *)(&stack0x000000b0 + iVar21) = uVar11;

                *(float *)(&stack0x000000ac + iVar21) = (float)iVar20 * 0.033333335;

                *(undefined4 *)(&stack0x000000b4 + iVar21) = uVar11;

                *(undefined4 *)(&stack0x000000a8 + iVar21) = 1;

                uVar18 = uVar18 + 1;

                uVar33 = uVar18;

              }

              if (bVar2 != 0x57) break;

              if (0x1f < (int)(uVar18 + 1)) {

                FUN_0051ea20();

                uVar18 = 0;

              }

              iVar20 = *(int *)pbVar24;

              uVar11 = *(undefined4 *)(pbVar25 + 5);

              iVar21 = uVar18 * 0x20;

              *(undefined4 *)(&stack0x000000b0 + iVar21) = uVar11;

              *(undefined4 *)(&stack0x000000a8 + iVar21) = 3;

              *(float *)(&stack0x000000ac + iVar21) = (float)iVar20 * 0.033333335;

              *(undefined4 *)(&stack0x000000b4 + iVar21) = uVar11;

              uVar11 = *(undefined4 *)(pbVar25 + 9);

              iVar20 = (uVar18 + 1) * 0x20;

              *(undefined4 *)(&stack0x000000ac + iVar20) =

                   *(undefined4 *)(&stack0x0000008c + iVar20);

              pbVar25 = pbVar25 + 0xd;

              *(undefined4 *)(&stack0x000000b0 + iVar20) = uVar11;

              *(undefined4 *)(&stack0x000000b4 + iVar20) = uVar11;

              *(undefined4 *)(&stack0x000000a8 + iVar20) = 5;

              uVar18 = uVar18 + 2;

              uVar33 = uVar18;

            }

            if (bVar2 != 0x58) break;

            if (0x1f < (int)uVar18) {

              FUN_0051ea20();

              uVar18 = 0;

            }

            uVar11 = *(undefined4 *)(pbVar25 + 5);

            uVar13 = *(undefined4 *)(pbVar25 + 9);

            iVar20 = uVar18 * 0x20;

            pbVar25 = pbVar25 + 0xd;

            *(float *)(&stack0x000000ac + iVar20) = (float)*(int *)pbVar24 * 0.033333335;

            *(undefined4 *)(&stack0x000000b0 + iVar20) = uVar11;

            *(undefined4 *)(&stack0x000000b4 + iVar20) = uVar13;

            *(undefined4 *)(&stack0x000000a8 + iVar20) = 9;

            uVar18 = uVar18 + 1;

            uVar33 = uVar18;

          }

          if (bVar2 != 0x5c) break;

          if (0x1f < (int)uVar18) {

            FUN_0051ea20();

            uVar18 = 0;

          }

          uVar11 = *(undefined4 *)(pbVar25 + 5);

          uVar13 = *(undefined4 *)(pbVar25 + 9);

          iVar20 = uVar18 * 0x20;

          pbVar25 = pbVar25 + 0xd;

          *(float *)(&stack0x000000ac + iVar20) = (float)*(int *)pbVar24 * 0.033333335;

          *(undefined4 *)(&stack0x000000b0 + iVar20) = uVar11;

          *(undefined4 *)(&stack0x000000b4 + iVar20) = uVar13;

          *(undefined4 *)(&stack0x000000a8 + iVar20) = 0x10001;

          uVar18 = uVar18 + 1;

          uVar33 = uVar18;

        }

        if (bVar2 != 0x7f) break;

        if (0x1f < (int)uVar18) {

          FUN_0051ea20();

          uVar33 = 0;

        }

        iVar20 = uVar33 * 0x20;

        pbVar25 = pbVar25 + 5;

        *(float *)(&stack0x000000ac + iVar20) = (float)*(int *)pbVar24 * 0.033333335;

        do {

          bVar2 = *pbVar25;

          pbVar25 = pbVar25 + 1;

        } while (bVar2 != 0);

        uVar11 = Main_fx_00447210();

        *(undefined4 *)(&stack0x000000b0 + iVar20) = uVar11;

        do {

          bVar2 = *pbVar25;

          pbVar25 = pbVar25 + 1;

        } while (bVar2 != 0);

        uVar11 = Main_fx_00447210();

        *(undefined4 *)(&stack0x000000b4 + iVar20) = uVar11;

        do {

          bVar2 = *pbVar25;

          pbVar25 = pbVar25 + 1;

        } while (bVar2 != 0);

        uVar11 = Main_fx_00447210();

        *(undefined4 *)(&stack0x000000b8 + iVar20) = uVar11;

        do {

          bVar2 = *pbVar25;

          pbVar25 = pbVar25 + 1;

        } while (bVar2 != 0);

        uVar11 = Main_fx_00447210();

        *(undefined4 *)(&stack0x000000bc + iVar20) = uVar11;

        do {

          bVar2 = *pbVar25;

          pbVar25 = pbVar25 + 1;

        } while (bVar2 != 0);

        uVar11 = Main_fx_00447210();

        *(undefined4 *)(&stack0x000000c0 + iVar20) = uVar11;

        uVar11 = *(undefined4 *)pbVar25;

        *(undefined4 *)(&stack0x000000a8 + iVar20) = 0x40;

        *(undefined4 *)(&stack0x000000c4 + iVar20) = uVar11;

LAB_004aed0a:

        uVar18 = uVar33 + 1;

        pbVar25 = pbVar25 + 4;

        uVar33 = uVar18;

      }

      if (bVar2 == 0x80) {

        if (0x1f < (int)uVar18) {

          FUN_0051ea20();

          uVar33 = 0;

        }

        iVar20 = uVar33 * 0x20;

        pbVar25 = pbVar25 + 5;

        *(float *)(&stack0x000000ac + iVar20) = (float)*(int *)pbVar24 * 0.033333335;

        do {

          bVar2 = *pbVar25;

          pbVar25 = pbVar25 + 1;

        } while (bVar2 != 0);

        uVar11 = Main_fx_00447210();

        *(undefined4 *)(&stack0x000000b0 + iVar20) = uVar11;

        do {

          bVar2 = *pbVar25;

          pbVar25 = pbVar25 + 1;

        } while (bVar2 != 0);

        uVar11 = Main_fx_00447210();

        *(undefined4 *)(&stack0x000000b4 + iVar20) = uVar11;

        do {

          bVar2 = *pbVar25;

          pbVar25 = pbVar25 + 1;

        } while (bVar2 != 0);

        uVar11 = Main_fx_00447210();

        *(undefined4 *)(&stack0x000000b8 + iVar20) = uVar11;

        do {

          bVar2 = *pbVar25;

          pbVar25 = pbVar25 + 1;

        } while (bVar2 != 0);

        uVar11 = Main_fx_00447210();

        *(undefined4 *)(&stack0x000000bc + iVar20) = uVar11;

        do {

          bVar2 = *pbVar25;

          pbVar25 = pbVar25 + 1;

        } while (bVar2 != 0);

        uVar13 = Main_fx_00447210();

        uVar11 = *(undefined4 *)pbVar25;

        *(undefined4 *)(&stack0x000000c0 + iVar20) = uVar13;

        *(undefined4 *)(&stack0x000000a8 + iVar20) = 0x80;

        *(undefined4 *)(&stack0x000000c4 + iVar20) = uVar11;

        goto LAB_004aed0a;

      }

      if (bVar2 == 0x53) {

        uVar22 = (uint)*pbVar24;

        *(byte **)(&stack0x000004a8 + uVar22 * 4) = pbVar25 + 2;

        pbVar25 = pbVar25 + 0x12;

        if (uStack00000008 <= uVar22) {

          uStack00000008 = uVar22 + 1;

        }

        if (0x7f < uStack00000008) {

          FUN_0051ea20();

          uStack00000008 = 0x80;

        }

        goto LAB_004ae6c3;

      }

      if (bVar2 == 0x54) {

        bVar2 = *pbVar24;

        bVar3 = pbVar25[2];

        uVar11 = *(undefined4 *)(pbVar25 + 0x13);

        *(byte **)(&stack0x000006a8 + (int)pcStack0000000c * 4) = pbVar25 + 3;

        *(undefined4 *)(&stack0x00000aa8 + (int)pcStack0000000c * 4) = uVar11;

        *(uint *)(&stack0x000008a8 + (int)pcStack0000000c * 4) = (uint)bVar2;

        *(uint *)(&stack0x00000ca8 + (int)pcStack0000000c * 4) = (uint)bVar3;

        if (bVar2 == 0) {

          FUN_0051ea20();

          pbVar25 = pbVar25 + 0x17;

        }

        else {

          pcStack0000000c = (char *)((int)pcStack0000000c + 1);

          pbVar25 = pbVar25 + 0x17;

        }

        goto LAB_004ae6c3;

      }

      if (bVar2 == 0x55) {

        puVar10[1] = puVar10[1] | 0x10;

        pbVar25 = pbVar24;

        goto LAB_004ae6c3;

      }

      if (bVar2 != 0xff) {

        crt_sprintf();

        FUN_0051ea20();

        return;

      }

      if ((0 < iStack00000004) && (puVar10[iStack00000004 + 0xff] != 0)) {

        if (9 < iStack00000004) {

          crt_sprintf();

          FUN_0051ea20();

        }

        fVar32 = (float10)fsin((float10)0.5235987901687622);

        puVar10[iStack00000004 + 0x100] = 0;

        puVar10[iStack00000004 + 0x10a] = (float)(fVar32 * (float10)3000.0);

      }

      if (uStack00000008 == 0) {

        puVar10[0x114] = 0;

        puVar10[0x115] = 0;

      }

      else {

        iVar20 = 0;

        iVar21 = 0;

        if (uStack00000008 != 0) {

          do {

            if (*(char **)(&stack0x000004a8 + iVar21 * 4) != (char *)0x0) {

              uVar18 = 0xffffffff;

              pcVar27 = *(char **)(&stack0x000004a8 + iVar21 * 4);

              do {

                if (uVar18 == 0) break;

                uVar18 = uVar18 - 1;

                cVar1 = *pcVar27;

                pcVar27 = pcVar27 + 1;

              } while (cVar1 != '\0');

              iVar20 = iVar20 + ~uVar18;

            }

            iVar21 = iVar21 + 1;

          } while (iVar21 < (int)uStack00000008);

        }

        iVar21 = 0;

        piVar23 = puVar10 + 2;

        iVar26 = 0xfe;

        do {

          iVar4 = *piVar23;

          piVar23 = piVar23 + 1;

          iVar21 = iVar21 + (uint)(iVar4 != 0);

          iVar26 = iVar26 + -1;

        } while (iVar26 != 0);

        uVar18 = iVar20 + uStack00000008 * 4 + iVar21 * uStack00000008 * 4;

        puVar10[0x114] = uStack00000008;

        puVar14 = (undefined4 *)MemAllocMsg();

        puVar10[0x115] = puVar14;

        for (uVar22 = uVar18 >> 2; uVar22 != 0; uVar22 = uVar22 - 1) {

          *puVar14 = 0;

          puVar14 = puVar14 + 1;

        }

        for (uVar18 = uVar18 & 3; uVar18 != 0; uVar18 = uVar18 - 1) {

          *(undefined1 *)puVar14 = 0;

          puVar14 = (undefined4 *)((int)puVar14 + 1);

        }

        puVar17 = (undefined4 *)puVar10[0x115];

        puVar14 = puVar17 + uStack00000008;

        iStack00000004 = 0;

        if (uStack00000008 != 0) {

          do {

            pcVar27 = *(char **)(&stack0x000004a8 + iStack00000004 * 4);

            if (pcVar27 == (char *)0x0) {

              *puVar17 = 0;

            }

            else {

              pcVar15 = pcVar27;

              do {

                cVar1 = *pcVar15;

                pcVar15[(int)puVar14 - (int)pcVar27] = cVar1;

                pcVar15 = pcVar15 + 1;

              } while (cVar1 != '\0');

              *puVar17 = puVar14;

              uVar18 = 0xffffffff;

              do {

                if (uVar18 == 0) break;

                uVar18 = uVar18 - 1;

                cVar1 = *pcVar27;

                pcVar27 = pcVar27 + 1;

              } while (cVar1 != '\0');

              puVar14 = (undefined4 *)((int)puVar14 + ~uVar18);

            }

            puVar17 = puVar17 + 1;

            iStack00000004 = iStack00000004 + 1;

          } while (iStack00000004 < (int)uStack00000008);

        }

        piVar23 = puVar10 + 2;

        iVar20 = 0xfe;

        do {

          if (*piVar23 != 0) {

            *(undefined4 **)(*piVar23 + 0x54) = puVar14;

            puVar14 = puVar14 + uStack00000008;

          }

          piVar23 = piVar23 + 1;

          iVar20 = iVar20 + -1;

        } while (iVar20 != 0);

      }

      if (pcStack0000000c != (char *)0x0) {

        puVar14 = (undefined4 *)MemAllocMsg();

        puVar10[0x117] = puVar14;

        for (iVar20 = ((int)pcStack0000000c * 9 & 0x1fffffffU) << 1; iVar20 != 0;

            iVar20 = iVar20 + -1) {

          *puVar14 = 0;

          puVar14 = puVar14 + 1;

        }

        iVar21 = 0;

        for (iVar20 = 0; iVar20 != 0; iVar20 = iVar20 + -1) {

          *(undefined1 *)puVar14 = 0;

          puVar14 = (undefined4 *)((int)puVar14 + 1);

        }

        puVar10[0x116] = pcStack0000000c;

        if (0 < (int)pcStack0000000c) {

          uStack00000008 = 0;

          do {

            handle_next_get();

            if (puVar10[*(int *)(&stack0x00000ca8 + iVar21 * 4) + 2] == 0) {

              *(undefined4 *)(uStack00000008 + puVar10[0x117]) = 0xffffffff;

            }

            else {

              __ftol();

              FUN_0053be00();

              in_stack_00000020 = (undefined4 *)ANM_NodeGetMat();

              uVar11 = *(undefined4 *)(&stack0x000008a8 + iVar21 * 4);

              FUN_0053be00();

              iVar20 = ANM_NodeGetMat();

              if ((in_stack_00000020 == (undefined4 *)0x0) || (iVar20 == 0)) {

                *(undefined4 *)(uStack00000008 + puVar10[0x117]) = 0xffffffff;

                crt_sprintf();

                FUN_0051ea20();

              }

              else {

                (*(code *)PTR_crt_matrix_copy_init_00580c1c)();

                (*(code *)PTR_crt_matrix_mul_00580c18)();

                *(undefined4 *)(puVar10[0x117] + uStack00000008) = uVar11;

              }

            }

            iVar21 = iVar21 + 1;

            uStack00000008 = uStack00000008 + 0x48;

          } while (iVar21 < (int)pcStack0000000c);

        }

      }

      if ((puStack00000010 != (undefined4 *)0x0) && (uVar33 != 0)) {

        puVar12 = (uint *)MemAllocMsg();

        *(uint **)((int)puStack00000010 + 0x24) = puVar12;

        *puVar12 = uVar33;

        puVar10 = *(undefined4 **)((int)puStack00000010 + 0x24);

        puVar14 = (undefined4 *)&stack0x000000a8;

        for (iVar20 = (uVar33 & 0x7ffffff) << 3; puVar10 = puVar10 + 1, iVar20 != 0;

            iVar20 = iVar20 + -1) {

          *puVar10 = *puVar14;

          puVar14 = puVar14 + 1;

        }

        for (iVar20 = 0; iVar20 != 0; iVar20 = iVar20 + -1) {

          *(undefined1 *)puVar10 = *(undefined1 *)puVar14;

          puVar14 = (undefined4 *)((int)puVar14 + 1);

          puVar10 = (undefined4 *)((int)puVar10 + 1);

        }

      }

      iStack00000014 = iStack00000014 + 1;

    } while (iStack00000014 < iVar19);

  }

  iVar19 = *piStack0000001c;

  if (0 < iVar19) {

    in_stack_00000020 = (undefined4 *)MemAllocMsg();

    puVar10 = &DAT_00632d54;

    for (puVar14 = DAT_00632d54; puVar14 != (undefined4 *)0x0; puVar14 = (undefined4 *)*puVar14) {

      puVar10 = puVar14;

    }

    *puVar10 = in_stack_00000020;

    puVar10 = in_stack_00000020;

    for (uVar18 = iVar19 * 0x304 + 8U >> 2; uVar18 != 0; uVar18 = uVar18 - 1) {

      *puVar10 = 0;

      puVar10 = puVar10 + 1;

    }

    for (iVar20 = 0; iVar20 != 0; iVar20 = iVar20 + -1) {

      *(undefined1 *)puVar10 = 0;

      puVar10 = (undefined4 *)((int)puVar10 + 1);

    }

    in_stack_00000020[1] = iVar19;

  }

  iStack00000014 = 0;

  if (iVar19 < 1) {

LAB_004af20c:

    mem_free_tagged();

    return;

  }

LAB_004af232:

  piStack0000001c = piStack0000001c + 1;

  iVar20 = *piStack0000001c;

  puVar10 = in_stack_00000020 + iStack00000014 * 0xc1 + 2;

  object_stop_movement_2();

  iVar21 = *(int *)(iVar20 + (int)piVar9);

  object_find();

  puVar10[1] = iVar21;

  if (iVar21 == 0) {

    DAT_00632d58 = puVar10;

  }

  puVar14 = puVar10 + 4;

  iVar21 = 4;

  do {

    *puVar14 = 0xfe;

    puVar14 = puVar14 + 9;

    iVar21 = iVar21 + -1;

  } while (iVar21 != 0);

  pcStack0000000c = &stack0x00000ea8;

  puVar10[0x31] = 0x3f800000;

  pfVar29 = (float *)((int *)(iVar20 + (int)piVar9) + 1);

switchD_004af2c0_caseD_24:

  pfVar30 = pfVar29;

  pfVar28 = (float *)((int)pfVar30 + 1);

  pfVar29 = pfVar28;

  switch(*(undefined1 *)pfVar30) {

  case 1:

    pfVar29 = (float *)((int)pfVar30 + 5);

    iVar20 = objectset_find();

    puVar10[2] = iVar20;

    if ((iVar20 != 0) && (*(int *)(iVar20 + 0x400) != 0)) {

      fVar31 = *(float *)(*(int *)(iVar20 + 0x400) + 0x58);

      puVar10[0x7b] = fVar31;

      if (fVar31 < 1.0) {

        puVar10[0x7b] = 0x3f800000;

      }

      puVar10[0x7a] = (float)puVar10[0x7b] * 0.8;

      puVar10[0x79] = (float)puVar10[0x7b] * 0.2;

    }

    goto switchD_004af2c0_caseD_24;

  case 2:

    pfVar30 = (float *)((int)pfVar30 + 5);

    if (*pfVar28 == 0.0) {

      puVar10[0xb9] = 0;

      pfVar28 = pfVar30;

    }

    else {

      puVar10[0xb9] = 1.0 / *pfVar28;

      pfVar28 = pfVar30;

    }

    do {

      cVar1 = *(char *)pfVar28;

      pfVar28 = (float *)((int)pfVar28 + 1);

    } while (cVar1 != '\0');

    if (*(char *)pfVar30 == '\0') {

      puVar10[0xb8] = 0;

    }

    else {

      uVar11 = main_texture_00508750();

      puVar10[0xb8] = uVar11;

    }

    iVar20 = puVar10[1];

    if (((((iVar20 != 0x101) && (iVar20 != 0x3e4)) &&

         ((iVar20 != 0x3e5 && ((iVar20 != 0x3e6 && (iVar20 != 999)))))) && (iVar20 != 0x405)) &&

       (pfVar29 = pfVar28, iVar20 != 0x406)) goto switchD_004af2c0_caseD_24;

switchD_004af2c0_caseD_54:

    puVar10[0x72] = puVar10[0x72] | 0x80000000;

    pfVar29 = pfVar28;

    goto switchD_004af2c0_caseD_24;

  case 3:

    if (*pfVar28 == 0.0) {

      puVar10[0xb9] = 0;

    }

    else {

      puVar10[0xb9] = 1.0 / *pfVar28;

    }

    uVar11 = *(undefined4 *)((int)pfVar30 + 5);

    uVar13 = *(undefined4 *)((int)pfVar30 + 9);

    puVar14 = (undefined4 *)MemAllocMsg();

    puVar14[1] = 0;

    puVar14[2] = 0;

    *puVar14 = s_Dynamic_shadow_texture_0055ca88;

    puVar14[3] = uVar11;

    puVar14[4] = uVar13;

    puVar14[6] = 5;

    puVar14[5] = 5;

    *(undefined1 *)((int)puVar14 + 0x1d) = 0;

    *(undefined1 *)(puVar14 + 7) = 0x20;

    *(undefined2 *)((int)puVar14 + 0x1e) = 0x80;

    puVar10[0xb8] = puVar14;

    pfVar29 = (float *)((int)pfVar30 + 0xd);

    goto switchD_004af2c0_caseD_24;

  case 4:

    *(undefined1 *)((int)puVar10 + 0x1f6) = 1;

    puVar10[0x65] = *pfVar28;

    iVar20 = puVar10[1];

    puVar10[100] = *(undefined4 *)((int)pfVar30 + 5);

    if ((((iVar20 == 2) || (iVar20 == 3)) || (iVar20 == 1)) || (iVar20 == 0xd7)) {

      puVar10[0x72] = puVar10[0x72] | 0x40000;

    }

    puVar10[0x72] = puVar10[0x72] | 0x400000;

    pfVar29 = (float *)((int)pfVar30 + 9);

    goto switchD_004af2c0_caseD_24;

  case 5:

    puVar10[0x68] = *pfVar28;

    pfVar29 = (float *)((int)pfVar30 + 5);

    goto switchD_004af2c0_caseD_24;

  case 6:

    puVar10[0x66] = *pfVar28;

    pfVar29 = (float *)((int)pfVar30 + 5);

    goto switchD_004af2c0_caseD_24;

  case 7:

    puVar10[0x67] = *pfVar28;

    pfVar29 = (float *)((int)pfVar30 + 5);

    goto switchD_004af2c0_caseD_24;

  case 8:

    puVar10[0x6a] = *pfVar28;

    puVar10[0x69] = *(undefined4 *)((int)pfVar30 + 5);

    pfVar29 = (float *)((int)pfVar30 + 9);

    goto switchD_004af2c0_caseD_24;

  case 9:

    puVar10[0x6b] = *pfVar28;

    pfVar29 = (float *)((int)pfVar30 + 5);

    goto switchD_004af2c0_caseD_24;

  case 10:

    puVar10[0x6c] = *pfVar28;

    pfVar29 = (float *)((int)pfVar30 + 5);

    goto switchD_004af2c0_caseD_24;

  case 0xb:

    puVar10[0x6e] = *pfVar28;

    pfVar29 = (float *)((int)pfVar30 + 5);

    goto switchD_004af2c0_caseD_24;

  case 0xc:

    crt_sprintf();

    FUN_00425eb0();

  case 0x38:

    pfVar29 = (float *)((int)pfVar30 + 0xd);

    goto switchD_004af2c0_caseD_24;

  case 0xd:

    puVar10[0x6d] = *pfVar28;

    pfVar29 = (float *)((int)pfVar30 + 5);

    goto switchD_004af2c0_caseD_24;

  default:

    crt_sprintf();

    FUN_0051ea20();

    return;

  case 0x13:

    ObjectSetAnim();

    pfVar29 = (float *)((int)pfVar30 + 2);

    goto switchD_004af2c0_caseD_24;

  case 0x14:

    puVar10[0x72] = puVar10[0x72] | 2;

    goto switchD_004af2c0_caseD_24;

  case 0x15:

    puVar10[0x75] = *pfVar28;

    pfVar29 = (float *)((int)pfVar30 + 5);

    goto switchD_004af2c0_caseD_24;

  case 0x16:

    puVar10[0x72] = puVar10[0x72] | 4;

    goto switchD_004af2c0_caseD_24;

  case 0x17:

    puVar10[0x31] = *pfVar28;

    pfVar29 = (float *)((int)pfVar30 + 5);

    goto switchD_004af2c0_caseD_24;

  case 0x18:

    puVar10[0x72] = puVar10[0x72] | 8;

    goto switchD_004af2c0_caseD_24;

  case 0x19:

    puVar10[0x6f] = *pfVar28;

    pfVar29 = (float *)((int)pfVar30 + 5);

    goto switchD_004af2c0_caseD_24;

  case 0x1a:

    iVar20 = puVar10[0x76];

    if (iVar20 < 0x10) {

      *(float *)(&stack0x00000044 + iVar20 * 4) = *pfVar28;

      puVar10[0x76] = iVar20 + 1;

      pfVar29 = (float *)((int)pfVar30 + 5);

    }

    else {

      FUN_0051ea20();

      pfVar29 = (float *)((int)pfVar30 + 5);

    }

    goto switchD_004af2c0_caseD_24;

  case 0x1b:

    puVar10[0x36] = puVar10[0x36] | 0x10;

    goto switchD_004af2c0_caseD_24;

  case 0x1c:

    pfVar29 = (float *)((int)pfVar30 + 9);

    goto switchD_004af2c0_caseD_24;

  case 0x1d:

    puVar10[0x72] = puVar10[0x72] | 0x40;

    goto switchD_004af2c0_caseD_24;

  case 0x1e:

    object_change_ospec();

    pfVar29 = (float *)((int)pfVar30 + 2);

    goto switchD_004af2c0_caseD_24;

  case 0x1f:

    iVar20 = puVar10[0x78];

    if (iVar20 == 2) {

      iVar20 = puVar10[0x40];

      uVar11 = objectset_find();

      *(undefined4 *)(iVar20 + 0x6c) = uVar11;

      *(undefined4 *)(iVar20 + 0x70) = *(undefined4 *)((int)pfVar30 + 5);

      pfVar28 = (float *)((int)pfVar30 + 0xd);

      *(undefined4 *)(iVar20 + 0x74) = *(undefined4 *)((int)pfVar30 + 9);

      *(float *)(iVar20 + 0x78) = *pfVar28;

      goto switchD_004af2c0_caseD_32;

    }

    if (iVar20 == 1) {

      iVar20 = puVar10[0x40];

      uVar11 = objectset_find();

      *(undefined4 *)(iVar20 + 0xa0) = uVar11;

      *(undefined4 *)(iVar20 + 0xa8) = *(undefined4 *)((int)pfVar30 + 5);

      *(undefined4 *)(iVar20 + 0xac) = *(undefined4 *)((int)pfVar30 + 9);

      *(undefined4 *)(iVar20 + 0xb0) = *(undefined4 *)((int)pfVar30 + 0xd);

      pfVar29 = (float *)((int)pfVar30 + 0x11);

    }

    else if (iVar20 == 3) {

      iVar20 = puVar10[0x40];

      uVar11 = objectset_find();

      *(undefined4 *)(iVar20 + 0xfb4) = uVar11;

      *(undefined4 *)(iVar20 + 0xfb8) = *(undefined4 *)((int)pfVar30 + 5);

      *(undefined4 *)(iVar20 + 0xfbc) = *(undefined4 *)((int)pfVar30 + 9);

      *(undefined4 *)(iVar20 + 0xfc0) = *(undefined4 *)((int)pfVar30 + 0xd);

      pfVar29 = (float *)((int)pfVar30 + 0x11);

    }

    else {

      FUN_0051ea20();

      pfVar29 = (float *)((int)pfVar30 + 0x11);

    }

    goto switchD_004af2c0_caseD_24;

  case 0x20:

    puVar10[0x72] = puVar10[0x72] | 0x80;

    goto switchD_004af2c0_caseD_24;

  case 0x21:

    puVar10[0x7a] = *pfVar28;

    puVar10[0x7b] = *(undefined4 *)((int)pfVar30 + 5);

    puVar10[0x79] = (float)puVar10[0x7a] * 0.5;

    pfVar29 = (float *)((int)pfVar30 + 9);

    goto switchD_004af2c0_caseD_24;

  case 0x22:

    puVar10[0x72] = puVar10[0x72] | 0x800;

    goto switchD_004af2c0_caseD_24;

  case 0x23:

    puVar10[0x72] = puVar10[0x72] | 0x1000;

  case 0x24:

  case 0x3f:

  case 0x43:

    goto switchD_004af2c0_caseD_24;

  case 0x25:

    puVar10[0x7f] = *pfVar28;

    pfVar29 = (float *)((int)pfVar30 + 5);

    goto switchD_004af2c0_caseD_24;

  case 0x26:

    *(undefined1 *)((int)puVar10 + 0x1f7) = *(undefined1 *)pfVar28;

    puVar10[0x7e] = *(undefined4 *)((int)pfVar30 + 5);

    pfVar29 = (float *)((int)pfVar30 + 9);

    goto switchD_004af2c0_caseD_24;

  case 0x27:

    FUN_0051ea20();

    goto switchD_004af2c0_caseD_24;

  case 0x28:

    if (puVar10[0x78] == 1) {

      iVar20 = puVar10[0x40];

      uVar11 = objectset_find();

      *(undefined4 *)(iVar20 + 0xa4) = uVar11;

      *(undefined4 *)(iVar20 + 0xb4) = *(undefined4 *)((int)pfVar30 + 5);

      *(undefined4 *)(iVar20 + 0xb8) = *(undefined4 *)((int)pfVar30 + 9);

      *(undefined4 *)(iVar20 + 0xbc) = *(undefined4 *)((int)pfVar30 + 0xd);

      pfVar29 = (float *)((int)pfVar30 + 0x11);

    }

    else {

      FUN_0051ea20();

      pfVar29 = (float *)((int)pfVar30 + 0x11);

    }

    goto switchD_004af2c0_caseD_24;

  case 0x29:

    puVar10[0x7c] = *pfVar28;

    pfVar29 = (float *)((int)pfVar30 + 5);

    goto switchD_004af2c0_caseD_24;

  case 0x2a:

    goto switchD_004af2c0_caseD_2a;

  case 0x2b:

    puVar10[0x72] = puVar10[0x72] | 0x100;

    goto switchD_004af2c0_caseD_24;

  case 0x2c:

    if (pcStack0000000c != &stack0x00000ea8) {

      *pcStack0000000c = '\0';

      pcStack0000000c = pcStack0000000c + 1;

    }

    do {

      cVar1 = *(char *)pfVar28;

      *pcStack0000000c = cVar1;

      pcStack0000000c = pcStack0000000c + 1;

      pfVar28 = (float *)((int)pfVar28 + 1);

      pfVar29 = pfVar28;

    } while (cVar1 != '\0');

    goto switchD_004af2c0_caseD_24;

  case 0x2d:

    do {

      cVar1 = *(char *)pfVar28;

      *pcStack0000000c = cVar1;

      pcStack0000000c = pcStack0000000c + 1;

      pfVar28 = (float *)((int)pfVar28 + 1);

      pfVar29 = pfVar28;

    } while (cVar1 != '\0');

    goto switchD_004af2c0_caseD_24;

  case 0x2e:

    puVar10[0x72] = puVar10[0x72] | 0x600;

    goto switchD_004af2c0_caseD_24;

  case 0x2f:

    puVar10[0x72] = puVar10[0x72] | 0x10000;

    goto switchD_004af2c0_caseD_24;

  case 0x30:

    puVar10[0x8a] = *pfVar28;

    pfVar29 = (float *)((int)pfVar30 + 5);

    goto switchD_004af2c0_caseD_24;

  case 0x31:

    iVar20 = __ftol();

    if (puVar10[0x71] == iVar20) {

      puVar10[0x70] = *pfVar28;

      uVar11 = __ftol();

      puVar10[0x71] = uVar11;

      pfVar29 = (float *)((int)pfVar30 + 5);

    }

    else {

      puVar10[0x70] = *pfVar28;

      pfVar29 = (float *)((int)pfVar30 + 5);

    }

    goto switchD_004af2c0_caseD_24;

  case 0x32:

  case 0x37:

  case 0x3e:

switchD_004af2c0_caseD_32:

    pfVar29 = pfVar28 + 1;

    goto switchD_004af2c0_caseD_24;

  case 0x33:

    if ((*pfVar28 != 0.0) || (*(float *)((int)pfVar30 + 5) != 0.0)) {

      FUN_0051ea20();

    }

    puVar10[0x72] = puVar10[0x72] | 0x80000;

    pfVar29 = (float *)((int)pfVar30 + 9);

    goto switchD_004af2c0_caseD_24;

  case 0x34:

    if ((*pfVar28 != 0.0) || (*(float *)((int)pfVar30 + 5) != 0.0)) {

      FUN_0051ea20();

    }

    puVar10[0x72] = puVar10[0x72] | 0x100000;

    pfVar29 = (float *)((int)pfVar30 + 9);

    goto switchD_004af2c0_caseD_24;

  case 0x35:

    if ((*pfVar28 != 0.0) || (*(float *)((int)pfVar30 + 5) != 0.0)) {

      FUN_0051ea20();

    }

    puVar10[0x72] = puVar10[0x72] | 0x200000;

    pfVar29 = (float *)((int)pfVar30 + 9);

    goto switchD_004af2c0_caseD_24;

  case 0x36:

    *(undefined1 *)((int)puVar10 + 0x1f6) = *(undefined1 *)pfVar28;

    pfVar29 = (float *)((int)pfVar30 + 2);

    goto switchD_004af2c0_caseD_24;

  case 0x39:

    fVar31 = *pfVar28;

    pfVar28 = (float *)((int)pfVar30 + 5);

    *(char *)((int)puVar10 + 0x1f5) = SUB41(fVar31,0);

switchD_004af2c0_caseD_2a:

    puVar10[0x72] = puVar10[0x72] | 0x20000;

    pfVar29 = pfVar28;

    goto switchD_004af2c0_caseD_24;

  case 0x3a:

    puVar10[0x75] = -*(float *)(*(int *)(puVar10[2] + 0x400) + 0x4c);

    goto switchD_004af2c0_caseD_24;

  case 0x3b:

    puVar10[99] = *pfVar28;

    pfVar29 = (float *)((int)pfVar30 + 5);

    goto switchD_004af2c0_caseD_24;

  case 0x3c:

    iVar20 = puVar10[0x78];

    if (((iVar20 == 6) || (iVar20 == 0x2b)) || (iVar20 == 0x39)) {

      iVar20 = puVar10[0x40];

      *(float *)(iVar20 + 0x10) = *pfVar28;

      *(undefined4 *)(iVar20 + 0xc) = *(undefined4 *)((int)pfVar30 + 5);

      *(undefined4 *)(iVar20 + 0x18) = *(undefined4 *)((int)pfVar30 + 9);

      *(undefined4 *)(iVar20 + 0x14) = *(undefined4 *)((int)pfVar30 + 0xd);

      fVar31 = (*(float *)(iVar20 + 0x10) - *(float *)(iVar20 + 0x18)) /

               (*(float *)(iVar20 + 0xc) - *(float *)(iVar20 + 0x14));

      *(float *)(iVar20 + 0x1c) = fVar31;

      *(float *)(iVar20 + 0x20) = *(float *)(iVar20 + 0x10) - fVar31 * *(float *)(iVar20 + 0xc);

      pfVar29 = (float *)((int)pfVar30 + 0x11);

    }

    else {

      FUN_0051ea20();

      pfVar29 = (float *)((int)pfVar30 + 0x11);

    }

    goto switchD_004af2c0_caseD_24;

  case 0x3d:

    puVar10[0x72] = puVar10[0x72] | 0x1000000;

    goto switchD_004af2c0_caseD_24;

  case 0x40:

  case 0x46:

    puVar10[0x73] = puVar10[0x73] | 1;

    goto switchD_004af2c0_caseD_24;

  case 0x41:

    puVar10[0x36] = puVar10[0x36] | 0x40000010;

    puVar10[0x72] = puVar10[0x72] | 0x8000e00;

    goto switchD_004af2c0_caseD_24;

  case 0x42:

    crt_sprintf();

    FUN_00425eb0();

    pfVar29 = (float *)((int)pfVar30 + 0xd);

    goto switchD_004af2c0_caseD_24;

  case 0x44:

    fVar31 = *pfVar28;

    pfVar28 = (float *)puVar10[0x40];

    pfVar29 = (float *)((int)pfVar30 + 5);

    if (pfVar28 == (float *)0x0) {

      crt_sprintf();

      FUN_0051ea20();

      pfVar29 = pfVar29 + (int)fVar31;

    }

    else if (0 < (int)fVar31) {

      do {

        *pfVar28 = *pfVar29;

        pfVar29 = pfVar29 + 1;

        pfVar28 = pfVar28 + 1;

        fVar31 = (float)((int)fVar31 + -1);

      } while (fVar31 != 0.0);

    }

    goto switchD_004af2c0_caseD_24;

  case 0x45:

    puVar10[0x80] = *pfVar28;

    pfVar29 = (float *)((int)pfVar30 + 5);

    goto switchD_004af2c0_caseD_24;

  case 0x47:

    puVar10[0x73] = puVar10[0x73] | 0x3c;

    goto switchD_004af2c0_caseD_24;

  case 0x48:

    puVar10[0x73] = puVar10[0x73] | 0x3c0;

    goto switchD_004af2c0_caseD_24;

  case 0x49:

    puVar10[0x73] = puVar10[0x73] | 0x3c00;

    goto switchD_004af2c0_caseD_24;

  case 0x4a:

    puVar10[0x73] = puVar10[0x73] | 2;

    goto switchD_004af2c0_caseD_24;

  case 0x4b:

    puVar10[0x73] = puVar10[0x73] | 0x3c000;

    goto switchD_004af2c0_caseD_24;

  case 0x4c:

    puVar10[0x73] = puVar10[0x73] | 0x3c0000;

    goto switchD_004af2c0_caseD_24;

  case 0x4d:

    puVar10[0x73] = puVar10[0x73] | 0x3c00000;

    goto switchD_004af2c0_caseD_24;

  case 0x4e:

    puVar10[0x74] = puVar10[0x74] | 0xf0;

    goto switchD_004af2c0_caseD_24;

  case 0x4f:

    puVar10[0x74] = puVar10[0x74] | 0xf;

    goto switchD_004af2c0_caseD_24;

  case 0x50:

    puVar10[0x74] = puVar10[0x74] | 0xf00;

    goto switchD_004af2c0_caseD_24;

  case 0x51:

    puVar10[0x36] = puVar10[0x36] | 0x40000010;

    puVar10[0x72] = puVar10[0x72] | 0x28000e00;

    goto switchD_004af2c0_caseD_24;

  case 0x52:

    puVar10[0x36] = puVar10[0x36] | 0x20000;

    goto switchD_004af2c0_caseD_24;

  case 0x53:

    puVar10[0x36] = puVar10[0x36] | 2;

    goto switchD_004af2c0_caseD_24;

  case 0x54:

    goto switchD_004af2c0_caseD_54;

  case 0x55:

    puVar10[0x36] = puVar10[0x36] | 0x40000000;

    goto switchD_004af2c0_caseD_24;

  case 0x56:

    puVar10[0x73] = puVar10[0x73] | 4;

    goto switchD_004af2c0_caseD_24;

  case 0x57:

    do {

      pfVar29 = pfVar28;

      pfVar28 = (float *)((int)pfVar29 + 1);

    } while (*(char *)pfVar29 != '\0');

    fVar31 = *(float *)((int)pfVar29 + 1);

    uVar11 = Main_fx_00447210();

    puVar10[0xbf] = uVar11;

    *(char *)(puVar10 + 0xbe) = SUB41(fVar31,0);

    pfVar29 = (float *)((int)pfVar29 + 5);

    goto switchD_004af2c0_caseD_24;

  case 0x58:

    puVar10[0x73] = puVar10[0x73] | 0x10;

    goto switchD_004af2c0_caseD_24;

  case 0x59:

    puVar10[0x73] = puVar10[0x73] | 0x40;

    goto switchD_004af2c0_caseD_24;

  case 0x5a:

    puVar10[0x73] = puVar10[0x73] | 0x80;

    goto switchD_004af2c0_caseD_24;

  case 0x5b:

    puVar10[0x73] = puVar10[0x73] | 0x100;

    goto switchD_004af2c0_caseD_24;

  case 0x5c:

    puVar10[0x73] = puVar10[0x73] | 0x400;

    goto switchD_004af2c0_caseD_24;

  case 0x5d:

    puVar10[0x73] = puVar10[0x73] | 0x800;

    goto switchD_004af2c0_caseD_24;

  case 0x5e:

    puVar10[0x73] = puVar10[0x73] | 0x1000;

    goto switchD_004af2c0_caseD_24;

  case 0x5f:

    puVar10[0x73] = puVar10[0x73] | 0x4000;

    goto switchD_004af2c0_caseD_24;

  case 0x60:

    puVar10[0x73] = puVar10[0x73] | 0x8000;

    goto switchD_004af2c0_caseD_24;

  case 0x61:

    puVar10[0x73] = puVar10[0x73] | 0x10000;

    goto switchD_004af2c0_caseD_24;

  case 0x62:

    puVar10[0x73] = puVar10[0x73] | 0x40000;

    goto switchD_004af2c0_caseD_24;

  case 99:

    puVar10[0x73] = puVar10[0x73] | 0x80000;

    goto switchD_004af2c0_caseD_24;

  case 100:

    puVar10[0x73] = puVar10[0x73] | 0x100000;

    goto switchD_004af2c0_caseD_24;

  case 0x65:

    puVar10[0x73] = puVar10[0x73] | 0x400000;

    goto switchD_004af2c0_caseD_24;

  case 0x66:

    puVar10[0x73] = puVar10[0x73] | 0x800000;

    goto switchD_004af2c0_caseD_24;

  case 0x67:

    puVar10[0x73] = puVar10[0x73] | 0x1000000;

    goto switchD_004af2c0_caseD_24;

  case 0x68:

    puVar10[0x74] = puVar10[0x74] | 0x10;

    goto switchD_004af2c0_caseD_24;

  case 0x69:

    puVar10[0x71] = *pfVar28;

    pfVar29 = (float *)((int)pfVar30 + 5);

    goto switchD_004af2c0_caseD_24;

  case 0x6a:

    puVar10[0x74] = puVar10[0x74] | 0x40;

    goto switchD_004af2c0_caseD_24;

  case 0x6b:

    puVar10[0x74] = puVar10[0x74] | 1;

    goto switchD_004af2c0_caseD_24;

  case 0x6c:

    puVar10[0x74] = puVar10[0x74] | 2;

    goto switchD_004af2c0_caseD_24;

  case 0x6d:

    puVar10[0x74] = puVar10[0x74] | 4;

    goto switchD_004af2c0_caseD_24;

  case 0x6e:

    puVar10[0x74] = puVar10[0x74] | 0x100;

    goto switchD_004af2c0_caseD_24;

  case 0x6f:

    puVar10[0x74] = puVar10[0x74] | 0x200;

    goto switchD_004af2c0_caseD_24;

  case 0x70:

    puVar10[0x74] = puVar10[0x74] | 0x400;

    goto switchD_004af2c0_caseD_24;

  case 0x71:

    puVar10[0x74] = puVar10[0x74] | 0x20;

    goto switchD_004af2c0_caseD_24;

  case 0x72:

    puVar10[0x73] = puVar10[0x73] | 8;

    goto switchD_004af2c0_caseD_24;

  case 0x73:

    puVar10[0x73] = puVar10[0x73] | 0x20;

    goto switchD_004af2c0_caseD_24;

  case 0x74:

    puVar10[0x73] = puVar10[0x73] | 0x200;

    goto switchD_004af2c0_caseD_24;

  case 0x75:

    puVar10[0x73] = puVar10[0x73] | 0x2000;

    goto switchD_004af2c0_caseD_24;

  case 0x76:

    puVar10[0x73] = puVar10[0x73] | 0x20000;

    goto switchD_004af2c0_caseD_24;

  case 0x77:

    puVar10[0x73] = puVar10[0x73] | 0x200000;

    goto switchD_004af2c0_caseD_24;

  case 0x78:

    puVar10[0x73] = puVar10[0x73] | 0x2000000;

    goto switchD_004af2c0_caseD_24;

  case 0x79:

    puVar10[0x74] = puVar10[0x74] | 0x80;

    goto switchD_004af2c0_caseD_24;

  case 0x7a:

    if ((puVar10[0x78] == 0x65) || (pfVar29 = (float *)((int)pfVar30 + 5), puVar10[0x78] == 0x3c)) {

      *(float *)puVar10[0x40] = *pfVar28;

      pfVar29 = (float *)((int)pfVar30 + 5);

    }

    goto switchD_004af2c0_caseD_24;

  case 0x7b:

    do {

      cVar1 = *(char *)pfVar28;

      pfVar28 = (float *)((int)pfVar28 + 1);

    } while (cVar1 != '\0');

    if ((puVar10[0x78] == 0x65) || (pfVar29 = pfVar28, puVar10[0x78] == 0x3c)) {

      iVar20 = puVar10[0x40];

      uVar11 = Main_fx_00447210();

      *(undefined4 *)(iVar20 + 4) = uVar11;

      pfVar29 = pfVar28;

    }

    goto switchD_004af2c0_caseD_24;

  case 0x7c:

    do {

      cVar1 = *(char *)pfVar28;

      pfVar28 = (float *)((int)pfVar28 + 1);

    } while (cVar1 != '\0');

    if ((puVar10[0x78] == 0x65) || (pfVar29 = pfVar28, puVar10[0x78] == 0x3c)) {

      iVar20 = puVar10[0x40];

      uVar11 = Main_fx_00447210();

      *(undefined4 *)(iVar20 + 8) = uVar11;

      pfVar29 = pfVar28;

    }

    goto switchD_004af2c0_caseD_24;

  case 0x7d:

    puVar10[0x72] = puVar10[0x72] | 0x2000000;

    goto switchD_004af2c0_caseD_24;

  case 0x7e:

    puVar10[0x72] = puVar10[0x72] | 0x10000000;

    goto switchD_004af2c0_caseD_24;

  case 0x7f:

    puVar10[0x74] = puVar10[0x74] | 8;

    goto switchD_004af2c0_caseD_24;

  case 0x80:

    puVar10[0x74] = puVar10[0x74] | 0x800;

    goto switchD_004af2c0_caseD_24;

  case 0x81:

    fVar7 = *(float *)((int)pfVar30 + 5);

    fVar5 = *(float *)((int)pfVar30 + 9);

    fVar31 = *(float *)((int)pfVar30 + 0xd);

    fVar6 = *(float *)((int)pfVar30 + 0x11);

    pfVar29 = (float *)((int)pfVar30 + 0x15);

    if (puVar10[0x78] == 0x3a) {

      pfVar29 = (float *)puVar10[0x40];

      *pfVar29 = *pfVar28;

      pfVar29[5] = fVar31;

      pfVar29[1] = fVar7;

      pfVar29[2] = fVar5;

      pfVar29[6] = fVar6;

      pfVar29 = (float *)((int)pfVar30 + 0x15);

    }

    goto switchD_004af2c0_caseD_24;

  case 0x82:

    uVar13 = *(undefined4 *)((int)pfVar30 + 5);

    uVar11 = *(undefined4 *)((int)pfVar30 + 9);

    uVar16 = *(undefined4 *)((int)pfVar30 + 0xd);

    pfVar29 = (float *)((int)pfVar30 + 0x11);

    if (puVar10[0x78] == 0x3a) {

      iVar20 = puVar10[0x40];

      *(float *)(iVar20 + 0xc) = *pfVar28;

      *(undefined4 *)(iVar20 + 0x1c) = uVar11;

      *(undefined4 *)(iVar20 + 0x10) = uVar13;

      *(undefined4 *)(iVar20 + 0x20) = uVar16;

    }

    goto switchD_004af2c0_caseD_24;

  case 0x83:

    if ((puVar10[0x78] == 0x65) || (puVar10[0x78] == 0x3c)) {

      *(undefined4 *)(puVar10[0x40] + 0xc) = 1;

    }

    goto switchD_004af2c0_caseD_24;

  case 0x84:

    puVar10[0x73] = puVar10[0x73] | 0x4000000;

    goto switchD_004af2c0_caseD_24;

  case 0x85:

    do {

      pfVar30 = pfVar28;

      pfVar28 = (float *)((int)pfVar30 + 1);

    } while (*(char *)pfVar30 != '\0');

    fVar31 = *(float *)((int)pfVar30 + 1);

    uVar11 = *(undefined4 *)((int)pfVar30 + 5);

    uVar13 = *(undefined4 *)((int)pfVar30 + 9);

    pfVar29 = (float *)((int)pfVar30 + 0xd);

    if (puVar10[0x78] == 5) {

      puVar14 = (undefined4 *)puVar10[0x40];

      uVar16 = Main_fx_00447210();

      *puVar14 = uVar16;

      puVar14[1] = fVar31;

      puVar14[2] = uVar11;

      puVar14[3] = uVar13;

    }

    goto switchD_004af2c0_caseD_24;

  case 0x86:

    fVar31 = *pfVar28;

    pfVar29 = (float *)((int)pfVar30 + 5);

    do {

      pfVar28 = pfVar29;

      pfVar29 = (float *)((int)pfVar28 + 1);

    } while (*(char *)pfVar28 != '\0');

    fVar7 = *(float *)((int)pfVar28 + 5);

    pfVar29 = (float *)((int)pfVar28 + 9);

    if (puVar10[0x78] == 0x3a) {

      pfVar8 = (float *)puVar10[0x40];

      if ((int)pfVar8[0xd] < 10) {

        pfVar8[5] = *(float *)((int)pfVar28 + 1);

        *pfVar8 = fVar31;

        pfVar8[6] = fVar7;

        _strncpy((char *)(pfVar8 + (int)pfVar8[0xd] * 8 + 0xf),(char *)((int)pfVar30 + 5),0x20);

        pfVar8[0xd] = (float)((int)pfVar8[0xd] + 1);

      }

    }

    goto switchD_004af2c0_caseD_24;

  case 0x87:

    pfVar30 = pfVar28;

    do {

      pfVar29 = pfVar30;

      pfVar30 = (float *)((int)pfVar29 + 1);

    } while (*(char *)pfVar29 != '\0');

    fVar31 = *(float *)((int)pfVar29 + 1);

    uVar11 = *(undefined4 *)((int)pfVar29 + 5);

    pfVar29 = (float *)((int)pfVar29 + 9);

    if (puVar10[0x78] == 0x3a) {

      iVar20 = puVar10[0x40];

      if (*(int *)(iVar20 + 0x38) < 10) {

        _strncpy((char *)(*(int *)(iVar20 + 0x38) * 0x20 + 0x17c + iVar20),(char *)pfVar28,0x20);

        *(float *)(iVar20 + 0x1c) = fVar31;

        *(undefined4 *)(iVar20 + 0x20) = uVar11;

        *(int *)(iVar20 + 0x38) = *(int *)(iVar20 + 0x38) + 1;

      }

    }

    goto switchD_004af2c0_caseD_24;

  case 0x88:

    uVar11 = *(undefined4 *)((int)pfVar30 + 5);

    uVar13 = *(undefined4 *)((int)pfVar30 + 9);

    pfVar29 = (float *)((int)pfVar30 + 0xd);

    if (puVar10[0x78] == 5) {

      iVar20 = puVar10[0x40];

      *(float *)(iVar20 + 0x14) = *pfVar28;

      *(undefined4 *)(iVar20 + 0x18) = uVar11;

      *(undefined4 *)(iVar20 + 0x1c) = uVar13;

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

  if (0 < (int)puVar10[0x76]) {

    puVar17 = (undefined4 *)MemAllocMsg();

    puVar10[0x77] = puVar17;

    puVar14 = (undefined4 *)&stack0x00000044;

    for (uVar18 = puVar10[0x76] & 0x3fffffff; uVar18 != 0; uVar18 = uVar18 - 1) {

      *puVar17 = *puVar14;

      puVar14 = puVar14 + 1;

      puVar17 = puVar17 + 1;

    }

    for (iVar20 = 0; iVar20 != 0; iVar20 = iVar20 + -1) {

      *(undefined1 *)puVar17 = *(undefined1 *)puVar14;

      puVar14 = (undefined4 *)((int)puVar14 + 1);

      puVar17 = (undefined4 *)((int)puVar17 + 1);

    }

  }

  if (pcStack0000000c != &stack0x00000ea8) {

    puVar14 = (undefined4 *)MemAllocMsg();

    puVar10[0x81] = puVar14;

    puVar10 = (undefined4 *)&stack0x00000ea8;

    for (uVar18 = (uint)((int)pcStack0000000c - (int)&stack0x00000ea8) >> 2; uVar18 != 0;

        uVar18 = uVar18 - 1) {

      *puVar14 = *puVar10;

      puVar10 = puVar10 + 1;

      puVar14 = puVar14 + 1;

    }

    for (uVar18 = (int)pcStack0000000c - (int)&stack0x00000ea8 & 3; uVar18 != 0; uVar18 = uVar18 - 1

        ) {

      *(undefined1 *)puVar14 = *(undefined1 *)puVar10;

      puVar10 = (undefined4 *)((int)puVar10 + 1);

      puVar14 = (undefined4 *)((int)puVar14 + 1);

    }

  }

  iStack00000014 = iStack00000014 + 1;

  if (iVar19 <= iStack00000014) goto LAB_004af20c;

  goto LAB_004af232;

switchD_004af2c0_caseD_89:

  puVar10[0x37] = puVar10[0x37] | 0x1000000;

  goto switchD_004af2c0_caseD_24;

}

