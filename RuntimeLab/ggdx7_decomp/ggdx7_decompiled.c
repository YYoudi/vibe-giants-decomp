/* ===== FUN_10001000 @ 0x10001000 ===== */

void __cdecl FUN_10001000(float *param_1,float *param_2,float *param_3)

{
  *param_3 = param_1[3] * param_2[0xc] +
             param_1[1] * param_2[4] + param_2[8] * param_1[2] + *param_1 * *param_2;
  param_3[1] = param_2[0xd] * param_1[3] +
               param_1[1] * param_2[5] + *param_1 * param_2[1] + param_2[9] * param_1[2];
  param_3[2] = param_2[0xe] * param_1[3] +
               param_1[1] * param_2[6] + param_2[10] * param_1[2] + *param_1 * param_2[2];
  param_3[3] = param_2[0xb] * param_1[2] +
               param_2[3] * *param_1 + param_1[1] * param_2[7] + param_1[3] * param_2[0xf];
  param_3[4] = param_1[4] * *param_2 +
               param_2[8] * param_1[6] + param_1[7] * param_2[0xc] + param_1[5] * param_2[4];
  param_3[5] = param_2[9] * param_1[6] +
               param_2[0xd] * param_1[7] + param_1[4] * param_2[1] + param_2[5] * param_1[5];
  param_3[6] = param_1[4] * param_2[2] +
               param_2[10] * param_1[6] + param_2[0xe] * param_1[7] + param_1[5] * param_2[6];
  param_3[7] = param_1[5] * param_2[7] +
               param_1[6] * param_2[0xb] + param_1[7] * param_2[0xf] + param_1[4] * param_2[3];
  param_3[8] = param_1[8] * *param_2 +
               param_2[8] * param_1[10] + param_1[0xb] * param_2[0xc] + param_1[9] * param_2[4];
  param_3[9] = param_2[9] * param_1[10] +
               param_2[0xd] * param_1[0xb] + param_1[8] * param_2[1] + param_2[5] * param_1[9];
  param_3[10] = param_1[8] * param_2[2] +
                param_2[10] * param_1[10] + param_2[0xe] * param_1[0xb] + param_1[9] * param_2[6];
  param_3[0xb] = param_1[9] * param_2[7] +
                 param_1[10] * param_2[0xb] + param_1[0xb] * param_2[0xf] + param_1[8] * param_2[3];
  param_3[0xc] = param_1[0xc] * *param_2 +
                 param_2[8] * param_1[0xe] + param_1[0xf] * param_2[0xc] + param_1[0xd] * param_2[4]
  ;
  param_3[0xd] = param_2[9] * param_1[0xe] +
                 param_2[0xd] * param_1[0xf] + param_1[0xc] * param_2[1] + param_2[5] * param_1[0xd]
  ;
  param_3[0xe] = param_1[0xc] * param_2[2] +
                 param_2[10] * param_1[0xe] +
                 param_2[0xe] * param_1[0xf] + param_1[0xd] * param_2[6];
  param_3[0xf] = param_1[0xd] * param_2[7] +
                 param_1[0xe] * param_2[0xb] +
                 param_1[0xf] * param_2[0xf] + param_1[0xc] * param_2[3];
  return;
}



/* ===== FUN_10001220 @ 0x10001220 ===== */

void __cdecl FUN_10001220(float *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  
  fVar1 = param_2[5] * param_2[10] - param_2[9] * param_2[6];
  fVar2 = 1.0 / ((param_2[9] * param_2[4] - param_2[8] * param_2[5]) * param_2[2] +
                (fVar1 * *param_2 -
                (param_2[4] * param_2[10] - param_2[8] * param_2[6]) * param_2[1]));
  *param_1 = fVar1 * fVar2;
  param_1[1] = (param_2[9] * param_2[2] - param_2[1] * param_2[10]) * fVar2;
  param_1[2] = (param_2[1] * param_2[6] - param_2[2] * param_2[5]) * fVar2;
  param_1[4] = (param_2[8] * param_2[6] - param_2[4] * param_2[10]) * fVar2;
  param_1[5] = (*param_2 * param_2[10] - param_2[8] * param_2[2]) * fVar2;
  param_1[6] = (param_2[4] * param_2[2] - *param_2 * param_2[6]) * fVar2;
  param_1[8] = (param_2[9] * param_2[4] - param_2[8] * param_2[5]) * fVar2;
  param_1[9] = (param_2[8] * param_2[1] - param_2[9] * *param_2) * fVar2;
  param_1[10] = (param_2[5] * *param_2 - param_2[4] * param_2[1]) * fVar2;
  param_1[0xc] = (-(param_2[0xc] * *param_1) - param_2[0xd] * param_1[4]) -
                 param_2[0xe] * param_1[8];
  param_1[0xd] = (-(param_2[0xc] * *param_1) - param_2[0xd] * param_1[4]) -
                 param_2[0xe] * param_1[8];
  param_1[0xe] = (-(param_2[0xc] * *param_1) - param_2[0xd] * param_1[4]) -
                 param_2[0xe] * param_1[8];
  return;
}



/* ===== FUN_100013a0 @ 0x100013A0 ===== */

void __cdecl FUN_100013a0(int param_1)

{
  int *piVar1;
  
  (**(code **)(param_1 + 0x2c))(param_1);
  piVar1 = *(int **)(param_1 + 0xc4 + *(int *)(param_1 + 0x94) * 4);
  (**(code **)(*piVar1 + 0x30))(piVar1);
  *(undefined4 *)(param_1 + 0x70) = 0;
  return;
}



/* ===== FUN_100013e0 @ 0x100013E0 ===== */

void __cdecl FUN_100013e0(int param_1)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x3c);
  if (*(int *)(param_1 + 0x6c) != 0) {
    *(undefined4 *)(param_1 + 0x7c) = 0;
    *(int *)(param_1 + 0x80) = *(int *)(param_1 + 0x6c);
    (**(code **)(param_1 + 0x60))(param_1);
    if (*(int *)(param_1 + 0x54) == 0) {
      *(int *)(iVar2 + 0x99c) = *(int *)(iVar2 + 0x99c) + *(int *)(param_1 + 0x6c) / 2;
    }
    else if (*(int *)(param_1 + 0x54) == 2) {
      *(int *)(iVar2 + 0x990) = *(int *)(iVar2 + 0x990) + *(int *)(param_1 + 0x6c) / 3;
    }
    (**(code **)(**(int **)(iVar2 + 0x850) + 0x14c))
              (*(int **)(iVar2 + 0x850),0,
               *(undefined4 *)(param_1 + 0xd8 + *(int *)(param_1 + 0x94) * 4),
               *(undefined4 *)(param_1 + 0xcc));
    if (*(int *)(iVar2 + 0x7d8) == 0) {
      (**(code **)(**(int **)(iVar2 + 0x850) + 0x130))
                (*(int **)(iVar2 + 0x850),*(undefined4 *)(param_1 + 0xd0));
    }
    else {
      (**(code **)(**(int **)(iVar2 + 0x850) + 0x130))
                (*(int **)(iVar2 + 0x850),*(int *)(iVar2 + 0x7d8));
    }
    (**(code **)(**(int **)(iVar2 + 0x850) + 0x160))
              (*(int **)(iVar2 + 0x850),*(undefined4 *)(iVar2 + 0x7dc));
    (**(code **)(**(int **)(iVar2 + 0x850) + 0x118))
              (*(int **)(iVar2 + 0x850),*(undefined4 *)(param_1 + 0x90),0,
               *(undefined4 *)(param_1 + 0x6c));
    iVar2 = *(int *)(param_1 + 0x94) + 1;
    *(int *)(param_1 + 0x94) = iVar2;
    if (*(int *)(param_1 + 0x8c) <= iVar2) {
      *(undefined4 *)(param_1 + 0x94) = 0;
    }
    if (*(int *)(param_1 + 0x70) != 0) {
      (*DAT_10024718)(s_Error_locking_vertex_buffer__alr_1001e30c);
      *(undefined4 *)(param_1 + 0x6c) = 0;
      return;
    }
    piVar1 = *(int **)(param_1 + 0xc4 + *(int *)(param_1 + 0x94) * 4);
    (**(code **)(*piVar1 + 0x2c))(piVar1,0,0,param_1 + 0x70,*(undefined4 *)(param_1 + 0xc0));
    *(undefined4 *)(param_1 + 0x6c) = 0;
  }
  return;
}



/* ===== FUN_10001730 @ 0x10001730 ===== */

int __cdecl FUN_10001730(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x6c);
  iVar2 = iVar1 + param_2;
  if (*(int *)(param_1 + 100) < iVar2) {
    (**(code **)(param_1 + 0x2c))(param_1);
    iVar1 = *(int *)(param_1 + 0x6c);
    iVar2 = iVar1 + param_2;
    if (*(int *)(param_1 + 100) < iVar2) {
      return 0;
    }
  }
  *(int *)(param_1 + 0x6c) = iVar2;
  return *(int *)(param_1 + 0x88) * iVar1 + *(int *)(param_1 + 0x70);
}



/* ===== FUN_10001780 @ 0x10001780 ===== */

int __cdecl FUN_10001780(int param_1,int param_2)

{
  int iVar1;
  
  if (*(int *)(param_1 + 100) < *(int *)(param_1 + 0x6c) + param_2) {
    (**(code **)(param_1 + 0x2c))(param_1);
    if (*(int *)(param_1 + 100) < *(int *)(param_1 + 0x6c) + param_2) {
      return 0;
    }
  }
  **(undefined2 **)(param_1 + 0x78) = (short)param_2;
  iVar1 = *(int *)(param_1 + 0x6c);
  *(int *)(param_1 + 0x78) = *(int *)(param_1 + 0x78) + 2;
  *(int *)(param_1 + 0x6c) = iVar1 + param_2;
  return *(int *)(param_1 + 0x88) * iVar1 + *(int *)(param_1 + 0x70);
}



/* ===== FUN_10001830 @ 0x10001830 ===== */

void __cdecl FUN_10001830(int param_1)

{
  int *piVar1;
  
  if (*(int *)(param_1 + 0x70) != 0) {
    piVar1 = *(int **)(param_1 + 0xc4 + *(int *)(param_1 + 0x94) * 4);
    (**(code **)(*piVar1 + 0x30))(piVar1);
    *(undefined4 *)(param_1 + 0x70) = 0;
  }
  return;
}



/* ===== FUN_10001860 @ 0x10001860 ===== */

int __cdecl FUN_10001860(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 100) < *(int *)(param_1 + 0x6c) + param_2) {
    (**(code **)(param_1 + 0x2c))(param_1);
    *(uint *)(param_1 + 0xc0) = *(uint *)(param_1 + 0xc0) & 0xffffefff | 0x2000;
    *(undefined4 *)(param_1 + 0x68) = 0;
    *(undefined4 *)(param_1 + 0x6c) = 0;
    if (*(int *)(param_1 + 100) < param_2) {
      return 0;
    }
  }
  if (*(int *)(param_1 + 0x70) == 0) {
    iVar2 = *(int *)(param_1 + 0x94) + 1;
    *(int *)(param_1 + 0x94) = iVar2;
    if (*(int *)(param_1 + 0x8c) <= iVar2) {
      *(undefined4 *)(param_1 + 0x94) = 0;
    }
    piVar1 = *(int **)(param_1 + 0xc4 + *(int *)(param_1 + 0x94) * 4);
    (**(code **)(*piVar1 + 0x2c))
              (piVar1,0,0,(int *)(param_1 + 0x70),*(undefined4 *)(param_1 + 0xc0));
    *(uint *)(param_1 + 0xc0) = *(uint *)(param_1 + 0xc0) & 0xffffdfff | 0x1000;
  }
  else {
    (*DAT_10024718)(s_Error_locking_vertex_buffer__alr_1001e30c);
  }
  iVar2 = *(int *)(param_1 + 0x6c);
  *(int *)(param_1 + 0x68) = iVar2;
  *(int *)(param_1 + 0x6c) = iVar2 + param_2;
  return *(int *)(param_1 + 0x88) * iVar2 + *(int *)(param_1 + 0x70);
}



/* ===== FUN_10001b40 @ 0x10001B40 ===== */

void __cdecl FUN_10001b40(int param_1)

{
  uint uVar1;
  undefined4 auStack_80 [16];
  float afStack_40 [16];
  
  if ((*(byte *)(param_1 + 0x420) & 1) != 0) {
    (**(code **)(**(int **)(param_1 + 0x850) + 0x94))
              (*(int **)(param_1 + 0x850),0x100,param_1 + 0x154);
  }
  if ((*(byte *)(param_1 + 0x420) & 2) != 0) {
    (**(code **)(**(int **)(param_1 + 0x850) + 0x94))(*(int **)(param_1 + 0x850),2,param_1 + 0x194);
    *(uint *)(param_1 + 0x420) = *(uint *)(param_1 + 0x420) | 0x80;
  }
  if ((*(byte *)(param_1 + 0x420) & 4) != 0) {
    (**(code **)(**(int **)(param_1 + 0x850) + 0x94))(*(int **)(param_1 + 0x850),3,param_1 + 0x1d4);
  }
  uVar1 = *(uint *)(param_1 + 0x420);
  *(uint *)(param_1 + 0x420) = uVar1 & 0xfffffff8;
  if (*(int *)(param_1 + 0x7d8) != 0) {
    if ((*(byte *)(param_1 + 0x424) & 6) != 0) {
      FUN_10001000((float *)(param_1 + 0x194),(float *)(param_1 + 0x1d4),(float *)(param_1 + 0x254))
      ;
    }
    if ((*(byte *)(param_1 + 0x424) & 3) != 0) {
      FUN_10001000((float *)(param_1 + 0x154),(float *)(param_1 + 0x194),(float *)(param_1 + 0x214))
      ;
      FUN_1000fdb6(auStack_80,(float *)(param_1 + 0x214));
      (**(code **)(**(int **)(param_1 + 0x850) + 0x13c))(*(int **)(param_1 + 0x850),6,auStack_80,4);
    }
    if ((*(byte *)(param_1 + 0x424) & 7) != 0) {
      FUN_10001000((float *)(param_1 + 0x154),(float *)(param_1 + 0x254),(float *)(param_1 + 0x294))
      ;
      FUN_1000fdb6(auStack_80,(float *)(param_1 + 0x294));
      (**(code **)(**(int **)(param_1 + 0x850) + 0x13c))(*(int **)(param_1 + 0x850),2,auStack_80,4);
    }
    if ((*(byte *)(param_1 + 0x424) & 8) != 0) {
      FUN_10001000((float *)(param_1 + 0x194),(float *)(param_1 + 0x2d4),afStack_40);
      FUN_1000fdb6(auStack_80,afStack_40);
      (**(code **)(**(int **)(param_1 + 0x850) + 0x13c))(*(int **)(param_1 + 0x850),10,auStack_80,4)
      ;
    }
    if ((*(byte *)(param_1 + 0x424) & 0x10) != 0) {
      FUN_10001000((float *)(param_1 + 0x194),(float *)(param_1 + 0x314),afStack_40);
      FUN_1000fdb6(auStack_80,afStack_40);
      (**(code **)(**(int **)(param_1 + 0x850) + 0x13c))
                (*(int **)(param_1 + 0x850),0xe,auStack_80,4);
    }
    if ((*(byte *)(param_1 + 0x424) & 0x20) != 0) {
      FUN_10001000((float *)(param_1 + 0x194),(float *)(param_1 + 0x354),afStack_40);
      FUN_1000fdb6(auStack_80,afStack_40);
      (**(code **)(**(int **)(param_1 + 0x850) + 0x13c))
                (*(int **)(param_1 + 0x850),0x12,auStack_80,4);
    }
    if ((*(byte *)(param_1 + 0x424) & 0x40) != 0) {
      FUN_10001000((float *)(param_1 + 0x194),(float *)(param_1 + 0x394),afStack_40);
      FUN_1000fdb6(auStack_80,afStack_40);
      (**(code **)(**(int **)(param_1 + 0x850) + 0x13c))
                (*(int **)(param_1 + 0x850),0x16,auStack_80,4);
    }
    *(uint *)(param_1 + 0x424) = *(uint *)(param_1 + 0x424) & 0xffffff80;
    return;
  }
  if ((uVar1 & 8) != 0) {
    (**(code **)(**(int **)(param_1 + 0x850) + 0x94))
              (*(int **)(param_1 + 0x850),0x10,param_1 + 0x2d4);
  }
  if ((*(byte *)(param_1 + 0x420) & 0x10) != 0) {
    (**(code **)(**(int **)(param_1 + 0x850) + 0x94))
              (*(int **)(param_1 + 0x850),0x11,param_1 + 0x314);
  }
  if ((*(byte *)(param_1 + 0x420) & 0x20) != 0) {
    (**(code **)(**(int **)(param_1 + 0x850) + 0x94))
              (*(int **)(param_1 + 0x850),0x12,param_1 + 0x354);
  }
  if ((*(byte *)(param_1 + 0x420) & 0x40) != 0) {
    (**(code **)(**(int **)(param_1 + 0x850) + 0x94))
              (*(int **)(param_1 + 0x850),0x13,param_1 + 0x394);
  }
  *(uint *)(param_1 + 0x420) = *(uint *)(param_1 + 0x420) & 0xffffff87;
  return;
}



/* ===== FUN_10001e60 @ 0x10001E60 ===== */

void __cdecl FUN_10001e60(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int *piVar6;
  float *pfVar7;
  int *piVar8;
  float *pfVar9;
  float afStack_44 [4];
  float fStack_34;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  undefined4 uStack_4;
  
  iVar1 = *(int *)(param_1 + 0x3c);
  iVar2 = *(int *)(param_1 + 0x48);
  puVar5 = (undefined4 *)(iVar2 + 0x28);
  *(int *)(iVar1 + 0x9a4) = *(int *)(iVar1 + 0x9a4) + 1;
  if ((((*(int *)(iVar1 + 0x110) != *(int *)(iVar2 + 0x2c)) ||
       (*(int *)(iVar1 + 0x114) != *(int *)(iVar2 + 0x30))) ||
      (*(int *)(iVar1 + 0x118) != *(int *)(iVar2 + 0x34))) ||
     (*(int *)(iVar1 + 0x11c) != *(int *)(iVar2 + 0x38))) {
    piVar6 = (int *)(iVar2 + 0x2c);
    piVar8 = (int *)(iVar1 + 0x110);
    for (iVar3 = 6; iVar3 != 0; iVar3 = iVar3 + -1) {
      *piVar8 = *piVar6;
      piVar6 = piVar6 + 1;
      piVar8 = piVar8 + 1;
    }
    FUN_10009c70(iVar1,(int)puVar5);
  }
  if (*(int *)(iVar1 + 0x13c) != *(int *)(iVar2 + 0x58)) {
    (**(code **)(**(int **)(iVar1 + 0x850) + 200))
              (*(int **)(iVar1 + 0x850),0x16,
               *(undefined4 *)(&DAT_1001e120 + *(int *)(iVar2 + 0x58) * 4));
    *(undefined4 *)(iVar1 + 0x13c) = *(undefined4 *)(iVar2 + 0x58);
  }
  if (((*(uint *)(iVar2 + 0x34) & 2) == 0) ||
     (-1 < (char)((uint)*(undefined4 *)(iVar1 + 0x9dc) >> 8))) {
    iVar3 = 0;
  }
  else {
    iVar3 = 1;
  }
  if ((*(uint *)(iVar2 + 0x34) & 1) == 0) {
    (**(code **)(**(int **)(iVar1 + 0x850) + 200))(*(int **)(iVar1 + 0x850),0x89,0);
    (**(code **)(**(int **)(iVar1 + 0x850) + 200))(*(int **)(iVar1 + 0x850),0x1d,iVar3);
    (**(code **)(**(int **)(iVar1 + 0x850) + 200))(*(int **)(iVar1 + 0x850),0x8d,1);
    (**(code **)(**(int **)(iVar1 + 0x850) + 200))(*(int **)(iVar1 + 0x850),0x91,1);
    (**(code **)(**(int **)(iVar1 + 0x850) + 200))(*(int **)(iVar1 + 0x850),0x92,2);
  }
  else {
    afStack_44[0] = (float)(*(uint *)(iVar2 + 0x4c) & 0xff) * 0.003921569;
    afStack_44[1] = (float)*(byte *)(iVar2 + 0x4d) * 0.003921569;
    afStack_44[2] = (float)*(byte *)(iVar2 + 0x4e) * 0.003921569;
    afStack_44[3] = (float)*(byte *)(iVar2 + 0x4f) * 0.003921569;
    fStack_34 = (float)(*(uint *)(iVar2 + 0x48) & 0xff) * 0.003921569;
    fStack_30 = (float)*(byte *)(iVar2 + 0x49) * 0.003921569;
    fStack_2c = (float)*(byte *)(iVar2 + 0x4a) * 0.003921569;
    fStack_28 = (float)*(byte *)(iVar2 + 0x4b) * 0.003921569;
    if (iVar3 == 0) {
      fStack_18 = 0.0;
      fStack_1c = 0.0;
      fStack_20 = 0.0;
      fStack_24 = 0.0;
    }
    else {
      fStack_24 = (float)(*(uint *)(iVar2 + 0x50) & 0xff) * 0.003921569;
      fStack_20 = (float)*(byte *)(iVar2 + 0x51) * 0.003921569;
      fStack_1c = (float)*(byte *)(iVar2 + 0x52) * 0.003921569;
      fStack_18 = (float)*(byte *)(iVar2 + 0x53) * 0.003921569;
    }
    fStack_14 = (float)(*(uint *)(iVar2 + 0x44) & 0xff) * 0.003921569;
    fStack_10 = (float)*(byte *)(iVar2 + 0x45) * 0.003921569;
    fStack_c = (float)*(byte *)(iVar2 + 0x46) * 0.003921569;
    fStack_8 = (float)*(byte *)(iVar2 + 0x47) * 0.003921569;
    if (iVar3 == 0) {
      uStack_4 = 0;
    }
    else {
      uStack_4 = *(undefined4 *)(iVar2 + 0x54);
    }
    piVar6 = *(int **)(iVar1 + 0x850);
    pfVar7 = afStack_44;
    pfVar9 = (float *)(iVar1 + 0x76c);
    for (iVar3 = 0x11; iVar3 != 0; iVar3 = iVar3 + -1) {
      *pfVar9 = *pfVar7;
      pfVar7 = pfVar7 + 1;
      pfVar9 = pfVar9 + 1;
    }
    (**(code **)(*piVar6 + 0xa8))(piVar6,afStack_44);
    (**(code **)(**(int **)(iVar1 + 0x850) + 200))(*(int **)(iVar1 + 0x850),0x89,1);
    if ((fStack_10 == 0.0) || (fStack_18 <= 0.0)) {
      uVar4 = 0;
    }
    else {
      uVar4 = 1;
    }
    (**(code **)(**(int **)(iVar1 + 0x850) + 200))(*(int **)(iVar1 + 0x850),0x1d,uVar4);
    (**(code **)(**(int **)(iVar1 + 0x850) + 200))(*(int **)(iVar1 + 0x850),0x8d,0);
    (**(code **)(**(int **)(iVar1 + 0x850) + 200))(*(int **)(iVar1 + 0x850),0x91,0);
    (**(code **)(**(int **)(iVar1 + 0x850) + 200))(*(int **)(iVar1 + 0x850),0x92,0);
  }
  if (*(int *)(iVar1 + 0x140) != *(int *)(iVar2 + 0x5c)) {
    piVar6 = *(int **)(iVar1 + 0x850);
    if (*(int *)(iVar2 + 0x5c) == 0) {
      (**(code **)(*piVar6 + 200))(piVar6,0x88,0);
    }
    else {
      (**(code **)(*piVar6 + 200))(piVar6,0x88,1);
    }
    *(undefined4 *)(iVar1 + 0x140) = *(undefined4 *)(iVar2 + 0x5c);
    *(undefined4 *)(iVar1 + 0x10c) = *puVar5;
    return;
  }
  *(undefined4 *)(iVar1 + 0x10c) = *puVar5;
  return;
}



/* ===== FUN_10002560 @ 0x10002560 ===== */

void __cdecl FUN_10002560(int param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  
  puVar1 = *(undefined4 **)(param_1 + 0xf0);
  uVar2 = (puVar1 == (undefined4 *)(param_1 + 0xf0U)) - 1 & (uint)puVar1;
  puVar1 = (undefined4 *)*puVar1;
  while (uVar2 != 0) {
    (**(code **)(uVar2 + 0x24))(uVar2 - 0x34);
    uVar2 = (puVar1 == (undefined4 *)(param_1 + 0xf0U)) - 1 & (uint)puVar1;
    puVar1 = (undefined4 *)*puVar1;
  }
  puVar1 = *(undefined4 **)(param_1 + 0xf8);
  uVar2 = (puVar1 == (undefined4 *)(param_1 + 0xf8U)) - 1 & (uint)puVar1;
  puVar1 = (undefined4 *)*puVar1;
  while (uVar2 != 0) {
    (**(code **)(uVar2 + 0x18))(uVar2 - 0x10);
    uVar2 = (puVar1 == (undefined4 *)(param_1 + 0xf8U)) - 1 & (uint)puVar1;
    puVar1 = (undefined4 *)*puVar1;
  }
  return;
}



/* ===== FUN_100025e0 @ 0x100025E0 ===== */

void __cdecl FUN_100025e0(int param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  
  puVar1 = *(undefined4 **)(param_1 + 0xf0);
  uVar2 = (puVar1 == (undefined4 *)(param_1 + 0xf0U)) - 1 & (uint)puVar1;
  puVar1 = (undefined4 *)*puVar1;
  while (uVar2 != 0) {
    (**(code **)(uVar2 + 0x28))(uVar2 - 0x34);
    uVar2 = (puVar1 == (undefined4 *)(param_1 + 0xf0U)) - 1 & (uint)puVar1;
    puVar1 = (undefined4 *)*puVar1;
  }
  puVar1 = *(undefined4 **)(param_1 + 0xf8);
  uVar2 = (puVar1 == (undefined4 *)(param_1 + 0xf8U)) - 1 & (uint)puVar1;
  puVar1 = (undefined4 *)*puVar1;
  while (uVar2 != 0) {
    (**(code **)(uVar2 + 0x1c))(uVar2 - 0x10);
    uVar2 = (puVar1 == (undefined4 *)(param_1 + 0xf8U)) - 1 & (uint)puVar1;
    puVar1 = (undefined4 *)*puVar1;
  }
  return;
}



/* ===== FUN_10002660 @ 0x10002660 ===== */

void __cdecl FUN_10002660(int param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  uint uVar2;
  
  puVar1 = *(undefined4 **)(param_1 + 0xf0);
  uVar2 = (puVar1 == (undefined4 *)(param_1 + 0xf0U)) - 1 & (uint)puVar1;
  puVar1 = (undefined4 *)*puVar1;
  while (uVar2 != 0) {
    (**(code **)(uVar2 - 8))(uVar2 - 0x34);
    uVar2 = (puVar1 == (undefined4 *)(param_1 + 0xf0U)) - 1 & (uint)puVar1;
    puVar1 = (undefined4 *)*puVar1;
  }
  *(int *)(param_1 + 0x3d4 + param_3 * 4) = param_2;
  (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))
            (*(int **)(param_1 + 0x850),param_3,0xd,*(undefined4 *)(&DAT_1001e0f0 + param_2 * 4));
  (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))
            (*(int **)(param_1 + 0x850),param_3,0xe,*(undefined4 *)(&DAT_1001e0f0 + param_2 * 4));
  return;
}



/* ===== GDVSysCreate @ 0x100026F0 ===== */ /* EXPORT GDVSysCreate */

undefined4 * __cdecl
GDVSysCreate(char *param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6,
            int param_7,uint *param_8,uint *param_9)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  
                    /* 0x26f0  1  GDVSysCreate */
  puVar1 = (undefined4 *)(*DAT_10024754)(0x26,0xa44,s_gfx_sys_1001e33c);
  if (puVar1 != (undefined4 *)0x0) {
    puVar4 = puVar1;
    for (iVar3 = 0x291; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
    puVar4 = puVar1 + 0x40;
    *puVar4 = puVar4;
    puVar1[0x41] = puVar4;
    puVar4 = puVar1 + 0x3c;
    *puVar4 = puVar4;
    puVar1[0x3d] = puVar4;
    puVar4 = puVar1 + 0x3e;
    *puVar4 = puVar4;
    puVar1[0x3f] = puVar4;
    *puVar1 = FUN_100048a0;
    puVar1[2] = &LAB_10004710;
    puVar1[1] = FUN_100029f0;
    puVar1[3] = FUN_10002df0;
    puVar1[4] = &LAB_10004040;
    puVar1[5] = FUN_10004720;
    puVar1[6] = FUN_10004080;
    puVar1[7] = FUN_10004100;
    puVar1[8] = FUN_10004180;
    puVar1[9] = FUN_10004270;
    puVar1[10] = &LAB_10004310;
    puVar1[0xb] = &LAB_10004320;
    puVar1[0xc] = &LAB_10004330;
    puVar1[0xd] = &LAB_10004340;
    puVar1[0xe] = &LAB_10004490;
    puVar1[0xf] = &LAB_10004360;
    puVar1[0x10] = &LAB_10004480;
    puVar1[0x11] = FUN_100045a0;
    puVar1[0x12] = FUN_100045e0;
    puVar1[0x15] = FUN_10004640;
    puVar1[0x16] = &LAB_100046a0;
    puVar1[0x17] = &LAB_10004740;
    puVar1[0x13] = FUN_100044e0;
    puVar1[0x14] = FUN_10002660;
    puVar1[0x18] = &LAB_1000d040;
    puVar1[0x19] = &DAT_1000d280;
    puVar1[0x1a] = FUN_1000d1b0;
    puVar1[0x1b] = &LAB_1000d230;
    puVar1[0x1c] = &LAB_10008bb0;
    puVar1[0x1d] = &LAB_10008cd0;
    puVar1[0x1e] = &LAB_10008cf0;
    puVar1[0x1f] = &LAB_10008cd0;
    puVar1[0x20] = FUN_100084e0;
    puVar1[0x21] = &LAB_100085a0;
    puVar1[0x22] = &LAB_10008b00;
    puVar1[0x23] = &LAB_1000b6e0;
    puVar1[0x24] = FUN_100097d0;
    puVar1[0x25] = FUN_10009990;
    puVar1[0x26] = &LAB_100099e0;
    puVar1[0x27] = &LAB_10009a50;
    puVar1[0x28] = &LAB_10009b20;
    puVar1[0x29] = &LAB_10009ba0;
    puVar1[0x2a] = &LAB_10009c50;
    puVar1[0x2b] = &LAB_10009450;
    puVar1[0x2c] = &LAB_1000c6b0;
    puVar1[0x2d] = FUN_1000cde0;
    puVar1[0x2e] = &LAB_1000b7f0;
    puVar1[0x2f] = &LAB_1000b820;
    puVar1[0x30] = &LAB_1000b840;
    puVar1[0x31] = &LAB_10008a10;
    puVar1[0x32] = &LAB_10008b40;
    puVar1[0x33] = &LAB_10008850;
    puVar1[0x34] = &LAB_10008960;
    puVar1[0x35] = &DAT_100092d0;
    puVar1[0x36] = &DAT_100092d0;
    puVar1[0x37] = &DAT_100092d0;
    puVar1[0x38] = &LAB_100091a0;
    puVar1[0x39] = FUN_10003e00;
    iVar3 = FUN_10006ee0((int)puVar1,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8
                         ,param_9);
    if (iVar3 == 0) {
      (*(code *)*puVar1)();
      return (undefined4 *)0x0;
    }
    uVar2 = (*(code *)puVar1[1])(puVar1);
    puVar1[0x42] = uVar2;
    (*(code *)puVar1[5])(puVar1);
    (*(code *)puVar1[6])(puVar1,&DAT_1001e0b0);
    (*(code *)puVar1[7])(puVar1,&DAT_1001e0b0);
    (*(code *)puVar1[8])(puVar1,&DAT_1001e0b0);
    (*(code *)puVar1[9])(puVar1,&DAT_1001e0b0,0);
    (*(code *)puVar1[9])(puVar1,&DAT_1001e0b0,1);
    (*(code *)puVar1[0x11])(puVar1,0);
    (*(code *)puVar1[0x13])(puVar1,0,0,0,0);
    (*(code *)puVar1[0x13])(puVar1,0,0,0,1);
    uVar2 = (*(code *)puVar1[0x39])(puVar1,0x10000);
    puVar1[0x10a] = uVar2;
    puVar1[0x3a] = &LAB_100046d0;
  }
  return puVar1;
}



/* ===== FUN_100029f0 @ 0x100029F0 ===== */

undefined4 * __cdecl FUN_100029f0(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  int *piVar5;
  
  puVar1 = (undefined4 *)(*DAT_10024754)(0x26,0x68,s_gfx_state_1001e344);
  puVar4 = puVar1;
  for (iVar2 = 0x1a; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  piVar3 = puVar1 + 7;
  puVar1[8] = piVar3;
  *piVar3 = (int)piVar3;
  puVar1[8] = *(undefined4 *)(param_1 + 0x104);
  *piVar3 = param_1 + 0x100;
  *(int **)(param_1 + 0x104) = piVar3;
  *(int **)puVar1[8] = piVar3;
  puVar4 = puVar1 + 0x18;
  *puVar4 = puVar4;
  puVar1[0x19] = puVar4;
  puVar1[9] = param_1;
  *puVar1 = FUN_10002ac0;
  puVar1[2] = &LAB_10002b90;
  puVar1[3] = FUN_10002c20;
  puVar1[4] = FUN_10002c90;
  puVar1[5] = FUN_10002d00;
  puVar1[6] = FUN_10002d70;
  piVar3 = &DAT_1001e040;
  piVar5 = puVar1 + 10;
  for (iVar2 = 0xe; iVar2 != 0; iVar2 = iVar2 + -1) {
    *piVar5 = *piVar3;
    piVar3 = piVar3 + 1;
    piVar5 = piVar5 + 1;
  }
  DAT_10024288 = DAT_10024288 + 1;
  if (DAT_10024288 == 0) {
    DAT_10024288 = 1;
  }
  puVar1[10] = DAT_10024288;
  (*(code *)puVar1[3])(puVar1,1);
  (*(code *)puVar1[4])(puVar1,1);
  return puVar1;
}



/* ===== FUN_10002ac0 @ 0x10002AC0 ===== */

void __cdecl FUN_10002ac0(int param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  uint uVar3;
  
  puVar2 = *(undefined4 **)(param_1 + 0x60);
  uVar3 = (puVar2 == (undefined4 *)(param_1 + 0x60U)) - 1 & (uint)puVar2;
  puVar2 = (undefined4 *)*puVar2;
  while (uVar3 != 0) {
    FUN_10002b30(uVar3 - 0x40,0);
    uVar3 = (puVar2 == (undefined4 *)(param_1 + 0x60U)) - 1 & (uint)puVar2;
    puVar2 = (undefined4 *)*puVar2;
  }
  piVar1 = (int *)(param_1 + 0x1c);
  **(undefined4 **)(param_1 + 0x20) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(*piVar1 + 4) = *(undefined4 *)(param_1 + 0x20);
  *piVar1 = (int)piVar1;
  *(int **)(param_1 + 0x20) = piVar1;
  (*DAT_10024758)(param_1);
  return;
}



/* ===== FUN_10002b30 @ 0x10002B30 ===== */

void __cdecl FUN_10002b30(int param_1,int param_2)

{
  int *piVar1;
  
  piVar1 = (int *)(param_1 + 0x40);
  if (param_2 != 0) {
    **(int **)(param_1 + 0x44) = *piVar1;
    *(undefined4 *)(*piVar1 + 4) = *(undefined4 *)(param_1 + 0x44);
    *(undefined4 *)(param_1 + 0x44) = *(undefined4 *)(param_2 + 100);
    *piVar1 = param_2 + 0x60;
    *(int **)(param_2 + 100) = piVar1;
    **(int **)(param_1 + 0x44) = (int)piVar1;
    *(int *)(param_1 + 0x48) = param_2;
    return;
  }
  **(int **)(param_1 + 0x44) = *piVar1;
  *(undefined4 *)(*piVar1 + 4) = *(undefined4 *)(param_1 + 0x44);
  *piVar1 = (int)piVar1;
  *(int **)(param_1 + 0x44) = piVar1;
  *(undefined4 *)(param_1 + 0x48) = *(undefined4 *)(*(int *)(param_1 + 0x3c) + 0x108);
  return;
}



/* ===== FUN_10002c20 @ 0x10002C20 ===== */

void __cdecl FUN_10002c20(int param_1,int param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  
  puVar1 = *(undefined4 **)(param_1 + 0x60);
  uVar2 = (puVar1 == (undefined4 *)(param_1 + 0x60U)) - 1 & (uint)puVar1;
  puVar1 = (undefined4 *)*puVar1;
  while (uVar2 != 0) {
    (**(code **)(uVar2 - 0x14))(uVar2 - 0x40);
    uVar2 = (puVar1 == (undefined4 *)(param_1 + 0x60U)) - 1 & (uint)puVar1;
    puVar1 = (undefined4 *)*puVar1;
  }
  if ((*(int *)(param_1 + 0x58) != param_2) &&
     (*(int *)(param_1 + 0x58) = param_2,
     *(int *)(*(int *)(param_1 + 0x24) + 0x10c) == *(int *)(param_1 + 0x28))) {
    *(undefined4 *)(*(int *)(param_1 + 0x24) + 0x10c) = 0;
  }
  return;
}



/* ===== FUN_10002c90 @ 0x10002C90 ===== */

void __cdecl FUN_10002c90(int param_1,int param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  
  puVar1 = *(undefined4 **)(param_1 + 0x60);
  uVar2 = (puVar1 == (undefined4 *)(param_1 + 0x60U)) - 1 & (uint)puVar1;
  puVar1 = (undefined4 *)*puVar1;
  while (uVar2 != 0) {
    (**(code **)(uVar2 - 0x14))(uVar2 - 0x40);
    uVar2 = (puVar1 == (undefined4 *)(param_1 + 0x60U)) - 1 & (uint)puVar1;
    puVar1 = (undefined4 *)*puVar1;
  }
  if ((*(int *)(param_1 + 0x5c) != param_2) &&
     (*(int *)(param_1 + 0x5c) = param_2,
     *(int *)(*(int *)(param_1 + 0x24) + 0x10c) == *(int *)(param_1 + 0x28))) {
    *(undefined4 *)(*(int *)(param_1 + 0x24) + 0x10c) = 0;
  }
  return;
}



/* ===== FUN_10002d00 @ 0x10002D00 ===== */

void __cdecl FUN_10002d00(int param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  
  puVar5 = *(undefined4 **)(param_1 + 0x60);
  uVar3 = (puVar5 == (undefined4 *)(param_1 + 0x60U)) - 1 & (uint)puVar5;
  puVar5 = (undefined4 *)*puVar5;
  while (uVar3 != 0) {
    (**(code **)(uVar3 - 0x14))(uVar3 - 0x40);
    uVar3 = (puVar5 == (undefined4 *)(param_1 + 0x60U)) - 1 & (uint)puVar5;
    puVar5 = (undefined4 *)*puVar5;
  }
  iVar1 = *(int *)(param_1 + 0x24);
  iVar2 = *(int *)(param_1 + 0x28);
  puVar5 = (undefined4 *)(param_1 + 0x2c);
  for (iVar4 = 6; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = *param_2;
    param_2 = param_2 + 1;
    puVar5 = puVar5 + 1;
  }
  if (*(int *)(iVar1 + 0x10c) == iVar2) {
    *(undefined4 *)(iVar1 + 0x10c) = 0;
  }
  return;
}



/* ===== FUN_10002d70 @ 0x10002D70 ===== */

void __cdecl FUN_10002d70(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  
  puVar5 = *(undefined4 **)(param_1 + 0x60);
  uVar3 = (puVar5 == (undefined4 *)(param_1 + 0x60U)) - 1 & (uint)puVar5;
  puVar5 = (undefined4 *)*puVar5;
  while (uVar3 != 0) {
    (**(code **)(uVar3 - 0x14))(uVar3 - 0x40);
    uVar3 = (puVar5 == (undefined4 *)(param_1 + 0x60U)) - 1 & (uint)puVar5;
    puVar5 = (undefined4 *)*puVar5;
  }
  iVar1 = *(int *)(param_1 + 0x24);
  iVar2 = *(int *)(param_1 + 0x28);
  puVar5 = (undefined4 *)(param_1 + 0x2c);
  for (iVar4 = 6; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = *param_2;
    param_2 = param_2 + 1;
    puVar5 = puVar5 + 1;
  }
  puVar5 = (undefined4 *)(param_1 + 0x44);
  for (iVar4 = 5; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = *param_3;
    param_3 = param_3 + 1;
    puVar5 = puVar5 + 1;
  }
  if (*(int *)(iVar1 + 0x10c) == iVar2) {
    *(undefined4 *)(iVar1 + 0x10c) = 0;
  }
  return;
}



/* ===== FUN_10002df0 @ 0x10002DF0 ===== */

undefined4 * __cdecl FUN_10002df0(int param_1,undefined4 param_2,int param_3,int param_4)

{
  int *piVar1;
  byte bVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined3 extraout_var;
  undefined4 *puVar5;
  
  iVar3 = 0x2e0;
  if (param_4 != 0) {
    iVar3 = param_3 * 2 + 0xe0;
  }
  puVar4 = (undefined4 *)(*DAT_10024754)(0x26,iVar3,s_gfx_primbuffer_1001e350);
  if (puVar4 != (undefined4 *)0x0) {
    puVar5 = puVar4;
    for (iVar3 = 0x38; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = 0;
      puVar5 = puVar5 + 1;
    }
    piVar1 = puVar4 + 0xd;
    puVar4[0xe] = piVar1;
    *piVar1 = (int)piVar1;
    puVar4[0xe] = *(undefined4 *)(param_1 + 0xf4);
    *piVar1 = param_1 + 0xf0;
    *(int **)(param_1 + 0xf4) = piVar1;
    *(int **)puVar4[0xe] = piVar1;
    puVar5 = puVar4 + 0x10;
    *puVar5 = puVar5;
    puVar4[0x11] = puVar5;
    puVar4[0xf] = param_1;
    puVar4[0x16] = FUN_10002ef0;
    puVar4[0x17] = FUN_10003b60;
    puVar4[0x12] = *(undefined4 *)(param_1 + 0x108);
    *puVar4 = FUN_10002f80;
    puVar4[1] = &LAB_10002fd0;
    puVar4[3] = FUN_10002b30;
    puVar4[0xb] = &LAB_10002fc0;
    puVar4[0x23] = 1;
    puVar4[0x1c] = 0;
    puVar4[0x19] = param_3;
    puVar4[0x1b] = 0;
    if (param_4 != 0) {
      puVar4[0x1d] = puVar4 + 0x38;
    }
    puVar4[0x1e] = puVar4[0x1d];
    puVar4[0x14] = param_2;
    bVar2 = FUN_10003b60((uint)puVar4);
    if (CONCAT31(extraout_var,bVar2) == 0) {
      return puVar4;
    }
    (*(code *)*puVar4)(puVar4);
  }
  return (undefined4 *)0x0;
}



/* ===== FUN_10002ef0 @ 0x10002EF0 ===== */

void __cdecl FUN_10002ef0(int param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  
  if (*(int *)(param_1 + 0x70) != 0) {
    (*DAT_10024718)(s_Error_releasing_VB_while_it_is_l_1001e360);
    piVar3 = *(int **)(param_1 + 0xc4 + *(int *)(param_1 + 0x94) * 4);
    (**(code **)(*piVar3 + 0x30))(piVar3);
    *(undefined4 *)(param_1 + 0x70) = 0;
  }
  iVar2 = *(int *)(param_1 + 0x8c);
  if (iVar2 != 0) {
    piVar3 = (int *)(param_1 + 0xb0 + iVar2 * 4);
    do {
      piVar1 = (int *)piVar3[-5];
      piVar4 = piVar3 + -1;
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 8))(piVar1);
        piVar3[-5] = 0;
      }
      piVar3 = (int *)*piVar4;
      if (piVar3 != (int *)0x0) {
        (**(code **)(*piVar3 + 8))(piVar3);
        *piVar4 = 0;
      }
      iVar2 = iVar2 + -1;
      piVar3 = piVar4;
    } while (iVar2 != 0);
  }
  *(undefined4 *)(param_1 + 0x4c) = 3;
  *(undefined4 *)(param_1 + 0x54) = 6;
  return;
}



/* ===== FUN_10002f80 @ 0x10002F80 ===== */

void __cdecl FUN_10002f80(int param_1)

{
  int *piVar1;
  
  (**(code **)(param_1 + 0xc))(param_1,0);
  FUN_10002ef0(param_1);
  piVar1 = (int *)(param_1 + 0x34);
  **(undefined4 **)(param_1 + 0x38) = *(undefined4 *)(param_1 + 0x34);
  *(undefined4 *)(*piVar1 + 4) = *(undefined4 *)(param_1 + 0x38);
  *piVar1 = (int)piVar1;
  *(int **)(param_1 + 0x38) = piVar1;
  (*DAT_10024758)(param_1);
  return;
}



/* ===== FUN_10003410 @ 0x10003410 ===== */

void __cdecl FUN_10003410(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  
  iVar2 = *(int *)(param_1 + 0x3c);
  if (*(int *)(*(int *)(param_1 + 0x48) + 0x28) != *(int *)(iVar2 + 0x10c)) {
    FUN_10001e60(param_1);
  }
  FUN_10001b40(iVar2);
  iVar6 = *(int *)(param_1 + 0x80);
  iVar8 = *(int *)(param_1 + 0x7c) * 0x1c + *(int *)(param_1 + 0x70);
  if (*(int *)(iVar2 + 0x41c) == 0) {
    for (; iVar6 != 0; iVar6 = iVar6 + -1) {
      *(float *)(iVar8 + 4) = (float)*(int *)(iVar2 + 0x964) - *(float *)(iVar8 + 4);
      if (*(int *)(iVar2 + 0x9e8) != 0) {
        if ((*(int *)(iVar2 + 0x9f0) == 0) ||
           (uVar5 = *(uint *)(iVar2 + 0x9f8), (uVar5 & 0x20000) == 0)) {
          if ((*(int *)(iVar2 + 0x9ec) != 0) &&
             (uVar5 = *(uint *)(iVar2 + 0x9f8), (uVar5 & 0x40000) != 0)) {
            if (-1 < (char)uVar5) {
              if ((uVar5 & 0x10000) == 0) {
                uVar5 = *(uint *)(iVar2 + 0x9f4);
              }
              else {
                uVar5 = (*(ushort *)(iVar8 + 0x12) & 0xff00) * (*(ushort *)(iVar2 + 0x9f6) & 0xff00)
                ;
              }
              uVar5 = uVar5 & 0xff000000;
              goto LAB_100035e6;
            }
            if ((uVar5 & 0x10000) == 0) {
              uVar5 = *(uint *)(iVar2 + 0x9f4);
            }
            else {
              uVar5 = (*(ushort *)(iVar8 + 0x12) & 0xff00) * (*(ushort *)(iVar2 + 0x9f6) & 0xff00);
            }
            uVar7 = *(uint *)(iVar8 + 0x10);
LAB_1000359e:
            *(uint *)(iVar8 + 0x10) = (uVar7 ^ uVar5) & 0xffffff ^ uVar5;
          }
        }
        else {
          cVar4 = (char)uVar5;
          if ((*(int *)(iVar2 + 0x9ec) == 0) || ((uVar5 & 0x40000) == 0)) {
            if ((uVar5 & 0x10000) == 0) {
              if (cVar4 < '\0') {
                uVar5 = *(uint *)(iVar2 + 0x9f4) & 0xffffff;
                goto LAB_100035e6;
              }
              *(uint *)(iVar8 + 0x10) = *(uint *)(iVar2 + 0x9f4) & 0xffffff;
            }
            else {
              uVar7 = *(uint *)(iVar2 + 0x9f4);
              uVar5 = *(uint *)(iVar8 + 0x10);
              if (-1 < cVar4) goto LAB_1000359e;
              *(uint *)(iVar8 + 0x10) = (uVar7 ^ uVar5) & 0xffffff ^ uVar5;
            }
          }
          else if ((uVar5 & 0x10000) == 0) {
            if (cVar4 < '\0') {
              uVar5 = *(uint *)(iVar2 + 0x9f4);
LAB_100035e6:
              *(uint *)(iVar8 + 0x10) = uVar5;
            }
            else {
              *(undefined4 *)(iVar8 + 0x10) = *(undefined4 *)(iVar2 + 0x9f4);
            }
          }
          else {
            uVar5 = (*(ushort *)(iVar8 + 0x12) & 0xff00) * (*(ushort *)(iVar2 + 0x9f6) & 0xff00);
            *(uint *)(iVar8 + 0x10) = (*(uint *)(iVar2 + 0x9f4) ^ uVar5) & 0xffffff ^ uVar5;
          }
        }
      }
      *(float *)(iVar8 + 8) =
           ((1.0 - *(float *)(iVar8 + 0xc) * *(float *)(iVar2 + 0x414)) * *(float *)(iVar2 + 0x418))
           / (*(float *)(iVar2 + 0x418) - *(float *)(iVar2 + 0x414));
      iVar8 = iVar8 + 0x1c;
    }
  }
  else {
    for (; iVar6 != 0; iVar6 = iVar6 + -1) {
      iVar1 = *(int *)(iVar2 + 0x964);
      *(undefined4 *)(iVar8 + 8) = 0;
      *(float *)(iVar8 + 4) = (float)iVar1 - *(float *)(iVar8 + 4);
      FUN_10003670(iVar8,iVar2);
      iVar8 = iVar8 + 0x1c;
    }
  }
  piVar3 = *(int **)(param_1 + 0xc4 + *(int *)(param_1 + 0x94) * 4);
  (**(code **)(*piVar3 + 0x30))(piVar3);
  *(undefined4 *)(param_1 + 0x70) = 0;
  return;
}



/* ===== FUN_10003670 @ 0x10003670 ===== */

void __cdecl FUN_10003670(int param_1,int param_2)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  
  if (*(int *)(param_2 + 0x9e8) != 0) {
    if ((*(int *)(param_2 + 0x9f0) != 0) &&
       (uVar2 = *(uint *)(param_2 + 0x9f8), (uVar2 & 0x20000) != 0)) {
      cVar1 = (char)uVar2;
      if ((*(int *)(param_2 + 0x9ec) != 0) && ((uVar2 & 0x40000) != 0)) {
        if ((uVar2 & 0x10000) != 0) {
          uVar2 = (*(ushort *)(param_2 + 0x9f6) & 0xff00) * (*(ushort *)(param_1 + 0x12) & 0xff00);
          *(uint *)(param_1 + 0x10) = (*(uint *)(param_2 + 0x9f4) ^ uVar2) & 0xffffff ^ uVar2;
          return;
        }
        if (cVar1 < '\0') {
          *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_2 + 0x9f4);
          return;
        }
        *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_2 + 0x9f4);
        return;
      }
      if ((uVar2 & 0x10000) == 0) {
        if (cVar1 < '\0') {
          *(uint *)(param_1 + 0x10) = *(uint *)(param_2 + 0x9f4) & 0xffffff;
          return;
        }
        *(uint *)(param_1 + 0x10) = *(uint *)(param_2 + 0x9f4) & 0xffffff;
        return;
      }
      uVar2 = *(uint *)(param_2 + 0x9f4);
      uVar3 = *(uint *)(param_1 + 0x10);
      if (cVar1 < '\0') {
        *(uint *)(param_1 + 0x10) = (uVar2 ^ uVar3) & 0xffffff ^ uVar3;
        return;
      }
LAB_100037bb:
      *(uint *)(param_1 + 0x10) = (uVar2 ^ uVar3) & 0xffffff ^ uVar3;
      return;
    }
    if ((*(int *)(param_2 + 0x9ec) != 0) &&
       (uVar2 = *(uint *)(param_2 + 0x9f8), (uVar2 & 0x40000) != 0)) {
      if ((char)uVar2 < '\0') {
        if ((uVar2 & 0x10000) == 0) {
          *(uint *)(param_1 + 0x10) =
               (*(uint *)(param_1 + 0x10) ^ *(uint *)(param_2 + 0x9f4)) & 0xffffff ^
               *(uint *)(param_2 + 0x9f4);
          return;
        }
        uVar3 = (*(ushort *)(param_1 + 0x12) & 0xff00) * (*(ushort *)(param_2 + 0x9f6) & 0xff00);
        uVar2 = *(uint *)(param_1 + 0x10);
        goto LAB_100037bb;
      }
      if ((uVar2 & 0x10000) != 0) {
        *(uint *)(param_1 + 0x10) =
             (*(ushort *)(param_1 + 0x12) & 0xff00) * (*(ushort *)(param_2 + 0x9f6) & 0xff00) &
             0xff000000;
        return;
      }
      *(uint *)(param_1 + 0x10) = *(uint *)(param_2 + 0x9f4) & 0xff000000;
    }
  }
  return;
}



/* ===== FUN_10003b60 @ 0x10003B60 ===== */

byte __cdecl FUN_10003b60(uint param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  byte bVar7;
  int iVar8;
  byte bVar9;
  uint uVar10;
  int iVar11;
  undefined4 local_18;
  undefined4 local_c;
  int local_8;
  
  uVar3 = param_1;
  iVar1 = *(int *)(param_1 + 0x3c);
  iVar2 = *(int *)(param_1 + 100);
  iVar11 = *(int *)(param_1 + 0x50);
  bVar7 = 0;
  *(undefined4 *)(param_1 + 0x4c) = 3;
  *(undefined4 *)(param_1 + 0x54) = 6;
  *(undefined4 *)(param_1 + 0x94) = 0;
  if ((iVar11 == 2) || (*(int *)(iVar1 + 0x8b8) == 0)) {
    local_18 = 0x200;
    if (iVar11 == 2) {
      local_c = 2;
    }
    else {
      local_c = 0;
      local_18 = 0x218;
    }
    param_1 = 0x44;
    iVar4 = 0x14;
    if (((iVar11 == 1) || (iVar11 == 6)) || (iVar11 == 4)) {
      iVar4 = 0x18;
      param_1 = 0xc4;
    }
    if (iVar11 == 5) {
      uVar10 = param_1 | 0x10100;
      iVar4 = iVar4 + 0xc;
    }
    else {
      uVar10 = param_1 | 0x100;
      iVar4 = iVar4 + 8;
    }
    *(undefined4 *)(uVar3 + 0xc0) = 0x2800;
    if (iVar4 != 0) {
      local_8 = *(int *)(uVar3 + 0x8c);
      if (local_8 != 0) {
        iVar8 = uVar3 + 0xa0 + local_8 * 4;
        do {
          iVar8 = iVar8 + -4;
          iVar5 = (**(code **)(**(int **)(iVar1 + 0x850) + 0x5c))
                            (*(int **)(iVar1 + 0x850),iVar4 * iVar2,local_18,uVar10,local_c,iVar8);
          bVar7 = bVar7 | iVar5 < 0;
          local_8 = local_8 + -1;
        } while (local_8 != 0);
      }
    }
    *(int *)(uVar3 + 0x98) = iVar4;
    *(uint *)(uVar3 + 0x9c) = uVar10;
  }
  if (((((iVar11 == 0) || (iVar11 == 1)) || ((iVar11 == 3 || ((iVar11 == 4 || (iVar11 == 5)))))) ||
      (iVar11 == 6)) || ((iVar11 == 7 || (iVar11 == 8)))) {
    local_18 = 0x208;
    if (*(int *)(iVar1 + 0x8b8) == 0) {
      bVar9 = 2;
      local_18 = 0x218;
    }
    else {
      bVar9 = -(*(int *)(iVar1 + 0xa0c) != 0) & 2;
    }
    iVar4 = 0xc;
    uVar6 = 2;
    if (iVar11 == 0) {
      uVar6 = 0x142;
      iVar4 = 0x18;
    }
    else if (iVar11 == 1) {
      uVar6 = 0x152;
      iVar4 = 0x24;
    }
    else if (iVar11 == 3) {
      uVar6 = 0x42;
      iVar4 = 0x10;
    }
    else if (iVar11 == 4) {
      uVar6 = 0xc2;
      iVar4 = 0x14;
    }
    else if (iVar11 == 5) {
      uVar6 = 0x10142;
      iVar4 = 0x1c;
    }
    else if (iVar11 == 6) {
      uVar6 = 0x112;
      iVar4 = 0x20;
    }
    else if (iVar11 == 7) {
      uVar6 = 0x1d2;
      iVar4 = 0x28;
    }
    else if (iVar11 == 8) {
      uVar6 = 0x452;
      iVar4 = 0x3c;
    }
    *(undefined4 *)(uVar3 + 0xc0) = 0x2800;
    *(int *)(uVar3 + 0xa8) = iVar4;
    *(undefined4 *)(uVar3 + 0xac) = uVar6;
    if (iVar4 != 0) {
      iVar11 = *(int *)(uVar3 + 0x8c);
      if (iVar11 != 0) {
        iVar8 = uVar3 + 0xb0 + iVar11 * 4;
        do {
          iVar8 = iVar8 + -4;
          iVar5 = (**(code **)(**(int **)(iVar1 + 0x850) + 0x5c))
                            (*(int **)(iVar1 + 0x850),iVar4 * iVar2,local_18,0,bVar9,iVar8);
          bVar7 = bVar7 | iVar5 < 0;
          iVar11 = iVar11 + -1;
        } while (iVar11 != 0);
      }
    }
  }
  return bVar7;
}



/* ===== FUN_10003e00 @ 0x10003E00 ===== */

undefined4 * __cdecl FUN_10003e00(int param_1,undefined4 param_2)

{
  int *piVar1;
  bool bVar2;
  undefined4 *puVar3;
  undefined3 extraout_var;
  int iVar4;
  undefined4 *puVar5;
  
  puVar3 = (undefined4 *)(*DAT_10024754)(0x26,0x3c,s_gfx_indexbuffer_1001e388);
  if (puVar3 != (undefined4 *)0x0) {
    puVar5 = puVar3;
    for (iVar4 = 0xf; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar5 = 0;
      puVar5 = puVar5 + 1;
    }
    piVar1 = puVar3 + 4;
    puVar3[5] = piVar1;
    *piVar1 = (int)piVar1;
    puVar3[5] = *(undefined4 *)(param_1 + 0xfc);
    *piVar1 = param_1 + 0xf8;
    *(int **)(param_1 + 0xfc) = piVar1;
    *(int **)puVar3[5] = piVar1;
    puVar3[6] = param_1;
    puVar3[1] = FUN_10003eb0;
    puVar3[2] = &LAB_10003f50;
    puVar3[3] = FUN_10003f70;
    puVar3[10] = FUN_10003f90;
    puVar3[0xb] = FUN_10004000;
    *puVar3 = FUN_10003fd0;
    puVar3[0xc] = 0;
    puVar3[7] = param_2;
    puVar3[9] = 0;
    bVar2 = FUN_10004000((int)puVar3);
    if (CONCAT31(extraout_var,bVar2) == 0) {
      return puVar3;
    }
    (*(code *)*puVar3)(puVar3);
  }
  return (undefined4 *)0x0;
}



/* ===== FUN_10003eb0 @ 0x10003EB0 ===== */

int __cdecl FUN_10003eb0(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0x1c) < *(int *)(param_1 + 0x24) + param_2) {
    *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) & 0xffffefff | 0x2000;
    *(undefined4 *)(param_1 + 0x20) = 0;
    *(undefined4 *)(param_1 + 0x24) = 0;
    if (*(int *)(param_1 + 0x1c) < param_2) {
      return 0;
    }
  }
  piVar1 = (int *)(param_1 + 0x30);
  if (*(int *)(param_1 + 0x30) != 0) {
    (*DAT_10024718)(s_Error_locking_vertex_buffer__alr_1001e30c);
    iVar2 = *(int *)(param_1 + 0x24);
    *(int *)(param_1 + 0x20) = iVar2;
    *(int *)(param_1 + 0x24) = iVar2 + param_2;
    return *piVar1 + iVar2 * 2;
  }
  (**(code **)(**(int **)(param_1 + 0x34) + 0x2c))
            (*(int **)(param_1 + 0x34),0,0,piVar1,*(undefined4 *)(param_1 + 0x38));
  iVar2 = *(int *)(param_1 + 0x24);
  *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) & 0xffffdfff | 0x1000;
  *(int *)(param_1 + 0x20) = iVar2;
  *(int *)(param_1 + 0x24) = iVar2 + param_2;
  return *piVar1 + iVar2 * 2;
}



/* ===== FUN_10003f70 @ 0x10003F70 ===== */

void __cdecl FUN_10003f70(int param_1)

{
  if (*(int *)(param_1 + 0x30) != 0) {
    (**(code **)(**(int **)(param_1 + 0x34) + 0x30))(*(int **)(param_1 + 0x34));
  }
  *(undefined4 *)(param_1 + 0x30) = 0;
  return;
}



/* ===== FUN_10003f90 @ 0x10003F90 ===== */

void __cdecl FUN_10003f90(int param_1)

{
  int *piVar1;
  
  if (*(int *)(param_1 + 0x30) != 0) {
    (*DAT_10024718)(s_Error_releasing_IB_while_it_is_l_1001e398);
    (**(code **)(**(int **)(param_1 + 0x34) + 0x30))(*(int **)(param_1 + 0x34));
    *(undefined4 *)(param_1 + 0x30) = 0;
  }
  piVar1 = *(int **)(param_1 + 0x34);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(param_1 + 0x34) = 0;
  }
  return;
}



/* ===== FUN_10003fd0 @ 0x10003FD0 ===== */

void __cdecl FUN_10003fd0(int param_1)

{
  int *piVar1;
  
  (**(code **)(param_1 + 0x28))(param_1);
  piVar1 = (int *)(param_1 + 0x10);
  **(undefined4 **)(param_1 + 0x14) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(*piVar1 + 4) = *(undefined4 *)(param_1 + 0x14);
  *piVar1 = (int)piVar1;
  *(int **)(param_1 + 0x14) = piVar1;
  (*DAT_10024758)(param_1);
  return;
}



/* ===== FUN_10004000 @ 0x10004000 ===== */

bool __cdecl FUN_10004000(int param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = *(int **)(*(int *)(param_1 + 0x18) + 0x850);
  iVar2 = (**(code **)(*piVar1 + 0x60))
                    (piVar1,*(int *)(param_1 + 0x1c) * 2,0x208,0x65,0,param_1 + 0x34);
  return iVar2 < 0;
}



/* ===== FUN_10004080 @ 0x10004080 ===== */

void __cdecl FUN_10004080(int param_1,undefined4 *param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  puVar3 = *(undefined4 **)(param_1 + 0xf0);
  uVar1 = (puVar3 == (undefined4 *)(param_1 + 0xf0U)) - 1 & (uint)puVar3;
  puVar3 = (undefined4 *)*puVar3;
  while (uVar1 != 0) {
    (**(code **)(uVar1 - 8))(uVar1 - 0x34);
    uVar1 = (puVar3 == (undefined4 *)(param_1 + 0xf0U)) - 1 & (uint)puVar3;
    puVar3 = (undefined4 *)*puVar3;
  }
  uVar1 = *(uint *)(param_1 + 0x420);
  puVar3 = (undefined4 *)(param_1 + 0x154);
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *param_2;
    param_2 = param_2 + 1;
    puVar3 = puVar3 + 1;
  }
  *(uint *)(param_1 + 0x420) = uVar1 | 1;
  *(uint *)(param_1 + 0x424) = *(uint *)(param_1 + 0x424) | 1;
  return;
}



/* ===== FUN_10004100 @ 0x10004100 ===== */

void __cdecl FUN_10004100(int param_1,undefined4 *param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  puVar3 = *(undefined4 **)(param_1 + 0xf0);
  uVar1 = (puVar3 == (undefined4 *)(param_1 + 0xf0U)) - 1 & (uint)puVar3;
  puVar3 = (undefined4 *)*puVar3;
  while (uVar1 != 0) {
    (**(code **)(uVar1 - 8))(uVar1 - 0x34);
    uVar1 = (puVar3 == (undefined4 *)(param_1 + 0xf0U)) - 1 & (uint)puVar3;
    puVar3 = (undefined4 *)*puVar3;
  }
  uVar1 = *(uint *)(param_1 + 0x420);
  puVar3 = (undefined4 *)(param_1 + 0x194);
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *param_2;
    param_2 = param_2 + 1;
    puVar3 = puVar3 + 1;
  }
  *(uint *)(param_1 + 0x420) = uVar1 | 2;
  *(uint *)(param_1 + 0x424) = *(uint *)(param_1 + 0x424) | 2;
  return;
}



/* ===== FUN_10004180 @ 0x10004180 ===== */

void __cdecl FUN_10004180(int param_1,undefined4 *param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  puVar3 = *(undefined4 **)(param_1 + 0xf0);
  uVar1 = (puVar3 == (undefined4 *)(param_1 + 0xf0U)) - 1 & (uint)puVar3;
  puVar3 = (undefined4 *)*puVar3;
  while (uVar1 != 0) {
    (**(code **)(uVar1 - 8))(uVar1 - 0x34);
    uVar1 = (puVar3 == (undefined4 *)(param_1 + 0xf0U)) - 1 & (uint)puVar3;
    puVar3 = (undefined4 *)*puVar3;
  }
  puVar3 = param_2;
  puVar4 = (undefined4 *)(param_1 + 0x1d4);
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  *(uint *)(param_1 + 0x420) = *(uint *)(param_1 + 0x420) | 4;
  *(uint *)(param_1 + 0x424) = *(uint *)(param_1 + 0x424) | 4;
  if (((float)param_2[10] * (float)param_2[0xb] != 0.0) &&
     (((float)param_2[10] - (float)param_2[0xb]) * (float)param_2[0xb] + (float)param_2[0xf] != 0.0)
     ) {
    *(float *)(param_1 + 0x414) =
         (float)param_2[0xf] - ((float)param_2[0xe] / (float)param_2[10]) * (float)param_2[0xb];
    *(float *)(param_1 + 0x418) =
         (((float)param_2[0xf] - (float)param_2[0xe]) / ((float)param_2[10] - (float)param_2[0xb]))
         * (float)param_2[0xb] + (float)param_2[0xf];
    return;
  }
  *(undefined4 *)(param_1 + 0x414) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x418) = 0x40000000;
  return;
}



/* ===== FUN_10004270 @ 0x10004270 ===== */

void __cdecl FUN_10004270(int param_1,undefined4 *param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  puVar3 = *(undefined4 **)(param_1 + 0xf0);
  uVar1 = (puVar3 == (undefined4 *)(param_1 + 0xf0U)) - 1 & (uint)puVar3;
  puVar3 = (undefined4 *)*puVar3;
  while (uVar1 != 0) {
    (**(code **)(uVar1 - 8))(uVar1 - 0x34);
    uVar1 = (puVar3 == (undefined4 *)(param_1 + 0xf0U)) - 1 & (uint)puVar3;
    puVar3 = (undefined4 *)*puVar3;
  }
  puVar3 = (undefined4 *)(param_3 * 0x40 + 0x2d4 + param_1);
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *param_2;
    param_2 = param_2 + 1;
    puVar3 = puVar3 + 1;
  }
  *(uint *)(param_1 + 0x420) = *(uint *)(param_1 + 0x420) | *(uint *)(&DAT_1001e234 + param_3 * 4);
  *(uint *)(param_1 + 0x424) = *(uint *)(param_1 + 0x424) | *(uint *)(&DAT_1001e234 + param_3 * 4);
  *(undefined4 *)(param_1 + 0x118) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x10c) = 0;
  return;
}



/* ===== FUN_100044e0 @ 0x100044E0 ===== */

void __cdecl FUN_100044e0(int param_1,int param_2,int param_3,uint param_4,int param_5)

{
  undefined4 *puVar1;
  uint uVar2;
  
  puVar1 = *(undefined4 **)(param_1 + 0xf0);
  uVar2 = (puVar1 == (undefined4 *)(param_1 + 0xf0U)) - 1 & (uint)puVar1;
  puVar1 = (undefined4 *)*puVar1;
  while (uVar2 != 0) {
    (**(code **)(uVar2 - 8))(uVar2 - 0x34);
    uVar2 = (puVar1 == (undefined4 *)(param_1 + 0xf0U)) - 1 & (uint)puVar1;
    puVar1 = (undefined4 *)*puVar1;
  }
  *(undefined4 *)(param_1 + 0x118) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x10c) = 0;
  *(int *)(param_1 + 0x3e4 + param_5 * 4) = param_2;
  *(int *)(param_1 + 0x3f4 + param_5 * 4) = param_3;
  *(uint *)(param_1 + 0x404 + param_5 * 4) = param_4;
  (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))
            (*(int **)(param_1 + 0x850),param_5,0xb,*(uint *)(&DAT_1001e0fc + param_2 * 4) | param_4
            );
  (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))
            (*(int **)(param_1 + 0x850),param_5,0x18,*(undefined4 *)(&DAT_1001e10c + param_3 * 4));
  return;
}



/* ===== FUN_100045a0 @ 0x100045A0 ===== */

void __cdecl FUN_100045a0(int param_1,int param_2)

{
  if ((param_2 == 1) && (*(int *)(param_1 + 0x89c) != 0)) {
    *(undefined4 *)(param_1 + 0x9ac) = 2;
    *(undefined4 *)(param_1 + 0x41c) = 1;
    return;
  }
  *(undefined4 *)(param_1 + 0x9ac) = 1;
  *(int *)(param_1 + 0x41c) = param_2;
  return;
}



/* ===== FUN_100045e0 @ 0x100045E0 ===== */

void __cdecl FUN_100045e0(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  
  puVar1 = *(undefined4 **)(param_1 + 0xf0);
  uVar2 = (puVar1 == (undefined4 *)(param_1 + 0xf0U)) - 1 & (uint)puVar1;
  puVar1 = (undefined4 *)*puVar1;
  while (uVar2 != 0) {
    (**(code **)(uVar2 - 8))(uVar2 - 0x34);
    uVar2 = (puVar1 == (undefined4 *)(param_1 + 0xf0U)) - 1 & (uint)puVar1;
    puVar1 = (undefined4 *)*puVar1;
  }
  *(undefined4 *)(param_1 + 0x9b0) = param_2;
  (**(code **)(**(int **)(param_1 + 0x850) + 200))(*(int **)(param_1 + 0x850),0x2f,param_2);
  return;
}



/* ===== FUN_10004640 @ 0x10004640 ===== */

void __cdecl FUN_10004640(int param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 *puVar2;
  
  puVar2 = *(undefined4 **)(param_1 + 0xf0);
  uVar1 = (puVar2 == (undefined4 *)(param_1 + 0xf0U)) - 1 & (uint)puVar2;
  puVar2 = (undefined4 *)*puVar2;
  if (uVar1 != 0) {
    do {
      (**(code **)(uVar1 - 8))(uVar1 - 0x34);
      uVar1 = (puVar2 == (undefined4 *)(param_1 + 0xf0U)) - 1 & (uint)puVar2;
      puVar2 = (undefined4 *)*puVar2;
    } while (uVar1 != 0);
    *(undefined4 *)(param_1 + 0x9b4) = param_2;
    return;
  }
  *(undefined4 *)(param_1 + 0x9b4) = param_2;
  return;
}



/* ===== FUN_10004720 @ 0x10004720 ===== */

void __cdecl FUN_10004720(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar2 = &DAT_1001e078;
  puVar3 = (undefined4 *)(param_1 + 0x10c);
  for (iVar1 = 0xe; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  return;
}



/* ===== FUN_100048a0 @ 0x100048A0 ===== */

void __cdecl FUN_100048a0(int param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  
  puVar1 = *(undefined4 **)(param_1 + 0x428);
  if (puVar1 != (undefined4 *)0x0) {
    (*(code *)*puVar1)(puVar1);
  }
  puVar1 = *(undefined4 **)(param_1 + 0xf8);
  uVar2 = (puVar1 == (undefined4 *)(param_1 + 0xf8U)) - 1 & (uint)puVar1;
  puVar1 = (undefined4 *)*puVar1;
  while (uVar2 != 0) {
    (**(code **)(uVar2 - 0x10))((undefined4 *)(uVar2 - 0x10));
    uVar2 = (puVar1 == (undefined4 *)(param_1 + 0xf8U)) - 1 & (uint)puVar1;
    puVar1 = (undefined4 *)*puVar1;
  }
  puVar1 = *(undefined4 **)(param_1 + 0xf0);
  uVar2 = (puVar1 == (undefined4 *)(param_1 + 0xf0U)) - 1 & (uint)puVar1;
  puVar1 = (undefined4 *)*puVar1;
  while (uVar2 != 0) {
    (**(code **)(uVar2 - 0x34))((undefined4 *)(uVar2 - 0x34));
    uVar2 = (puVar1 == (undefined4 *)(param_1 + 0xf0U)) - 1 & (uint)puVar1;
    puVar1 = (undefined4 *)*puVar1;
  }
  puVar1 = *(undefined4 **)(param_1 + 0x100);
  uVar2 = (puVar1 == (undefined4 *)(param_1 + 0x100U)) - 1 & (uint)puVar1;
  puVar1 = (undefined4 *)*puVar1;
  while (uVar2 != 0) {
    (**(code **)(uVar2 - 0x1c))((undefined4 *)(uVar2 - 0x1c));
    uVar2 = (puVar1 == (undefined4 *)(param_1 + 0x100U)) - 1 & (uint)puVar1;
    puVar1 = (undefined4 *)*puVar1;
  }
  FUN_100082a0(param_1);
  (*DAT_10024758)(param_1);
  return;
}



/* ===== FUN_10004980 @ 0x10004980 ===== */

int __cdecl FUN_10004980(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  iVar1 = 0;
  if (0 < DAT_1001e288) {
    while (iVar2 < param_1) {
      iVar2 = iVar2 * 2;
      iVar1 = iVar1 + 1;
      if (DAT_1001e288 < iVar2) {
        return -iVar1;
      }
    }
    if (iVar2 <= param_1) {
      return iVar1;
    }
  }
  return -iVar1;
}



/* ===== FUN_100049b0 @ 0x100049B0 ===== */

undefined4 __cdecl FUN_100049b0(uint param_1)

{
  if ((-1 < (int)param_1) && (param_1 < 0x11)) {
    return *(undefined4 *)(&DAT_1001e248 + param_1 * 4);
  }
  return 0;
}



/* ===== FUN_10004d00 @ 0x10004D00 ===== */

void __cdecl FUN_10004d00(uint *param_1)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  
  lVar1 = __ftol();
  lVar2 = __ftol();
  lVar3 = __ftol();
  lVar4 = __ftol();
  *param_1 = (((int)lVar1 << 8 | (uint)lVar2) << 8 | (uint)lVar3) << 8 | (uint)lVar4;
  return;
}



/* ===== FUN_10004d40 @ 0x10004D40 ===== */

void __cdecl FUN_10004d40(uint *param_1)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  
  lVar1 = __ftol();
  lVar2 = __ftol();
  lVar3 = __ftol();
  *param_1 = ((int)lVar1 << 8 | (uint)lVar2) << 8 | (uint)lVar3;
  return;
}



/* ===== FUN_10004db0 @ 0x10004DB0 ===== */

void __cdecl FUN_10004db0(ushort *param_1)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  
  lVar1 = __ftol();
  lVar2 = __ftol();
  lVar3 = __ftol();
  lVar4 = __ftol();
  *param_1 = (ushort)((((ushort)lVar1 & 0xfff0) << 4 | (uint)lVar2 & 0xfff0) << 4) |
             (ushort)((int)lVar3 >> 4) | (ushort)lVar4 & 0xfff0;
  return;
}



/* ===== FUN_10004e10 @ 0x10004E10 ===== */

void __cdecl FUN_10004e10(ushort *param_1)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  
  lVar1 = __ftol();
  lVar2 = __ftol();
  lVar3 = __ftol();
  *param_1 = (ushort)((((ushort)lVar1 & 0xfff8) << 5 | (uint)lVar2 & 0xfffc) << 3) |
             (ushort)((int)lVar3 >> 3);
  return;
}



/* ===== FUN_10004e60 @ 0x10004E60 ===== */

void __cdecl FUN_10004e60(ushort *param_1)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  
  lVar1 = __ftol();
  lVar2 = __ftol();
  lVar3 = __ftol();
  lVar4 = __ftol();
  *param_1 = (ushort)(((((ushort)lVar1 & 0xff80) << 1 | (uint)lVar2 & 0xfff8) << 5 |
                      (uint)lVar3 & 0xfff8) << 2) | (ushort)((int)lVar4 >> 3);
  return;
}



/* ===== FUN_10004ee0 @ 0x10004EE0 ===== */

void __cdecl FUN_10004ee0(undefined1 *param_1)

{
  longlong lVar1;
  
  lVar1 = __ftol();
  *param_1 = (char)lVar1;
  lVar1 = __ftol();
  param_1[1] = (char)lVar1;
  return;
}



/* ===== FUN_10004f10 @ 0x10004F10 ===== */

void __cdecl FUN_10004f10(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(&DAT_1001e2cc + param_1[5] * 4);
  if (param_2 == 0) {
    param_2 = *param_1 * iVar1;
  }
  param_1[4] = 0;
  if ((param_1[6] & 1U) == 0) {
    param_1[2] = iVar1;
  }
  else {
    param_1[2] = -iVar1;
    param_1[4] = -((*param_1 + -1) * -iVar1);
  }
  if ((param_1[6] & 2U) != 0) {
    param_1[3] = -param_2;
    param_1[4] = param_1[4] - (param_1[1] + -1) * -param_2;
    return;
  }
  param_1[3] = param_2;
  return;
}



/* ===== FUN_10004f70 @ 0x10004F70 ===== */

void __cdecl FUN_10004f70(int *param_1,int *param_2,float param_3)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int *piVar7;
  int *piVar8;
  uint uVar9;
  uint uVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  longlong lVar13;
  longlong lVar14;
  longlong lVar15;
  float *pfVar16;
  int *local_3c;
  float local_34;
  float local_30;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  piVar8 = param_2;
  piVar7 = param_1;
  if ((((param_1[5] == param_2[5]) && (param_1[4] == param_2[4])) && (param_1[2] == param_2[2])) &&
     (param_1[3] == param_2[3])) {
    uVar9 = *(int *)(&DAT_1001e2cc + param_1[5] * 4) * param_1[1] * *param_1;
    puVar11 = (undefined4 *)param_2[7];
    puVar12 = (undefined4 *)param_1[7];
    for (uVar10 = uVar9 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
      *puVar12 = *puVar11;
      puVar11 = puVar11 + 1;
      puVar12 = puVar12 + 1;
    }
    for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
      *(undefined1 *)puVar12 = *(undefined1 *)puVar11;
      puVar11 = (undefined4 *)((int)puVar11 + 1);
      puVar12 = (undefined4 *)((int)puVar12 + 1);
    }
    return;
  }
  fVar2 = (float)*param_1;
  fVar3 = (float)param_1[1];
  fVar4 = (float)*param_2 / fVar2;
  fVar5 = (float)param_2[1] / fVar3;
  fVar6 = fVar5 * fVar4;
  if (fVar6 < 1.0) {
    fVar6 = 1.0;
  }
  param_2 = (int *)0x0;
  fVar6 = param_3 / fVar6;
  local_30 = 0.0;
  if (0.0 < fVar2) {
    do {
      param_1 = (int *)0x0;
      local_34 = 0.0;
      if (0.0 < fVar3) {
        lVar13 = __ftol();
        do {
          local_3c = param_2;
          local_4 = 0.0;
          local_8 = 0.0;
          local_c = 0.0;
          local_10 = 0.0;
          if ((float)param_2 < (float)param_2 + fVar4) {
            do {
              param_3 = (float)param_1;
              if ((float)param_1 < (float)param_1 + fVar5) {
                lVar14 = __ftol();
                do {
                  iVar1 = piVar8[5];
                  pfVar16 = &local_10;
                  lVar15 = __ftol();
                  (*(code *)(&PTR_LAB_1001e28c)[iVar1])
                            ((int)lVar15 * piVar8[3] + piVar8[2] * (int)lVar14 + piVar8[7] +
                             piVar8[4],pfVar16);
                  param_3 = param_3 + 1.0;
                } while (param_3 < (float)param_1 + fVar5);
              }
              local_3c = (int *)((float)local_3c + 1.0);
            } while ((float)local_3c < (float)param_2 + fVar4);
          }
          iVar1 = piVar7[5];
          local_10 = local_10 * fVar6;
          pfVar16 = &local_10;
          local_c = local_c * fVar6;
          local_8 = local_8 * fVar6;
          local_4 = local_4 * fVar6;
          lVar14 = __ftol();
          (*(code *)(&PTR_FUN_1001e2ac)[iVar1])
                    ((int)lVar14 * piVar7[3] + piVar7[2] * (int)lVar13 + piVar7[4] + piVar7[7],
                     pfVar16);
          param_1 = (int *)((float)param_1 + fVar5);
          local_34 = local_34 + 1.0;
        } while (local_34 < fVar3);
      }
      param_2 = (int *)((float)param_2 + fVar4);
      local_30 = local_30 + 1.0;
    } while (local_30 < fVar2);
  }
  return;
}



/* ===== FUN_10005210 @ 0x10005210 ===== */

void __cdecl FUN_10005210(byte *param_1,undefined4 param_2,uint *param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  longlong lVar4;
  
  lVar4 = __ftol();
  uVar2 = 0xff;
  if ((uint)lVar4 < 0x100) {
    uVar2 = (uint)lVar4;
  }
  lVar4 = __ftol();
  uVar3 = 0xff;
  if ((uint)lVar4 < 0x100) {
    uVar3 = (uint)lVar4;
  }
  lVar4 = __ftol();
  uVar1 = (uint)lVar4;
  if (0xff < uVar1) {
    uVar1 = 0xff;
  }
  if (uVar3 < param_4) {
    uVar3 = param_4;
  }
  *param_3 = (((uint)*param_1 << 8 | uVar2) << 8 | uVar3) << 8 | uVar1;
  return;
}



/* ===== FUN_100052b0 @ 0x100052B0 ===== */

void __cdecl FUN_100052b0(uint *param_1,float param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  float fVar3;
  uint *puVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint *puVar9;
  uint *puVar10;
  uint local_7c;
  float local_78;
  uint local_74;
  uint local_70;
  uint *local_6c;
  uint local_68;
  float local_64;
  uint *local_60;
  uint local_5c;
  uint *local_58;
  int local_54;
  int local_50;
  int local_4c;
  uint local_48;
  uint local_44;
  uint local_40;
  float local_3c;
  uint local_38;
  uint *local_34;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_8;
  
  local_6c = (uint *)param_1[7];
  if (local_6c != (uint *)0x0) {
    uVar6 = *param_1;
    uVar8 = param_1[1];
    uVar7 = uVar8 * uVar6 * 4;
    local_70 = uVar8;
    local_38 = uVar7;
    puVar4 = operator_new(uVar7);
    local_64 = 0.0;
    local_78 = 0.0;
    local_74 = 0;
    puVar9 = puVar4;
    local_34 = puVar4;
    if (uVar8 != 0) {
      do {
        local_60 = puVar9;
        if (uVar6 != 0) {
          iVar1 = uVar6 - 1;
          local_58 = local_60;
          local_28 = (local_78 + 1.0) - local_78;
          uVar8 = 0;
          do {
            uVar7 = local_74;
            local_54 = 0;
            local_68 = ((int)uVar8 < 1) - 1 & uVar8;
            local_7c = local_74;
            local_7c = FUN_10006230(&local_54,(int *)&local_7c);
            local_50 = iVar1;
            local_68 = FUN_10006250(&local_50,(int *)&local_68);
            local_4c = local_70 - 1;
            iVar5 = FUN_10006250(&local_4c,(int *)&local_7c);
            local_5c = CONCAT31(local_5c._1_3_,
                                *(undefined1 *)((int)local_6c + (iVar5 * uVar6 + local_68) * 4 + 3))
            ;
            uVar2 = uVar8 + 1;
            local_4c = 0;
            local_68 = ((int)uVar2 < 1) - 1 & uVar2;
            local_7c = uVar7;
            local_7c = FUN_10006230(&local_4c,(int *)&local_7c);
            local_50 = iVar1;
            local_68 = FUN_10006250(&local_50,(int *)&local_68);
            local_54 = local_70 - 1;
            iVar5 = FUN_10006250(&local_54,(int *)&local_7c);
            local_44 = CONCAT31(local_44._1_3_,
                                *(undefined1 *)((int)local_6c + (iVar5 * uVar6 + local_68) * 4 + 3))
            ;
            local_7c = local_74 + 1;
            local_68 = ((int)uVar8 < 1) - 1 & uVar8;
            local_4c = 0;
            local_7c = FUN_10006230(&local_4c,(int *)&local_7c);
            local_50 = iVar1;
            local_68 = FUN_10006250(&local_50,(int *)&local_68);
            local_54 = local_70 - 1;
            local_7c = FUN_10006250(&local_54,(int *)&local_7c);
            local_2c = (float)(local_5c & 0xff) * param_2;
            local_48 = (uint)*(byte *)((int)local_6c + (local_7c * uVar6 + local_68) * 4 + 3);
            local_3c = local_64 + 1.0;
            local_8 = (float)local_48 * param_2;
            local_18 = local_3c - local_64;
            fVar3 = (float)(local_44 & 0xff) * param_2 - local_2c;
            local_2c = local_8 - local_2c;
            FUN_10005620(&local_24,local_2c * 0.0 - local_28 * fVar3,local_28 * local_18 - 0.0,
                         fVar3 * 0.0 - local_2c * local_18);
            FUN_10006170(&local_24,&local_20,&local_1c);
            FUN_10005210((byte *)&local_5c,&local_24,&local_40,param_3);
            local_64 = local_3c;
            *local_58 = local_40;
            local_58 = local_58 + 1;
            puVar4 = local_34;
            uVar7 = local_38;
            uVar8 = uVar2;
          } while (uVar2 < uVar6);
        }
        local_78 = local_78 + 1.0;
        local_60 = local_60 + uVar6;
        local_74 = local_74 + 1;
        puVar9 = local_60;
      } while (local_74 < local_70);
    }
    puVar9 = puVar4;
    puVar10 = local_6c;
    for (uVar6 = uVar7 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *puVar10 = *puVar9;
      puVar9 = puVar9 + 1;
      puVar10 = puVar10 + 1;
    }
    for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(char *)puVar10 = (char)*puVar9;
      puVar9 = (uint *)((int)puVar9 + 1);
      puVar10 = (uint *)((int)puVar10 + 1);
    }
    FUN_1000fe9b((undefined *)puVar4);
  }
  return;
}



/* ===== FUN_10005620 @ 0x10005620 ===== */

void __thiscall FUN_10005620(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  *(undefined4 *)this = param_1;
  *(undefined4 *)((int)this + 4) = param_2;
  *(undefined4 *)((int)this + 8) = param_3;
  return;
}



/* ===== FUN_10005640 @ 0x10005640 ===== */

void __cdecl FUN_10005640(uint *param_1)

{
  char cVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  uint local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  uint local_2c;
  undefined1 *local_28;
  uint local_24;
  uint local_20;
  undefined1 *local_1c;
  uint local_18;
  int local_14;
  int local_10;
  uint local_c;
  undefined4 *local_8;
  uint local_4;
  
  if (param_1[7] != 0) {
    uVar7 = *param_1;
    local_38 = param_1[1];
    uVar9 = local_38 * uVar7 * 4;
    local_4 = uVar9;
    puVar2 = operator_new(uVar9);
    local_30 = 0;
    local_8 = puVar2;
    if (local_38 != 0) {
      local_28 = (undefined1 *)((int)puVar2 + 2);
      do {
        if (uVar7 != 0) {
          local_1c = local_28;
          uVar9 = 0;
          do {
            uVar5 = local_30;
            local_24 = param_1[7];
            uVar8 = uVar7 - 1;
            uVar6 = ((int)uVar9 < 1) - 1 & uVar9;
            uVar3 = ((int)local_30 < 1) - 1 & local_30;
            local_2c = uVar8;
            if ((int)uVar6 <= (int)uVar8) {
              local_2c = uVar6;
            }
            local_34 = local_38 - 1;
            if ((int)local_34 < (int)uVar3) {
              uVar3 = local_34;
            }
            local_20 = (uint)*(byte *)(local_24 + 3 + (uVar3 * uVar7 + local_2c) * 4);
            local_c = uVar9 + 1;
            local_2c = local_20;
            if (local_c < uVar7) {
              uVar3 = ((int)local_c < 1) - 1 & local_c;
              uVar6 = ((int)local_30 < 1) - 1 & local_30;
              if ((int)uVar8 < (int)uVar3) {
                uVar3 = uVar8;
              }
              uVar8 = local_34;
              if ((int)uVar6 <= (int)local_34) {
                uVar8 = uVar6;
              }
              local_2c = (uint)*(byte *)(local_24 + 3 + (uVar8 * uVar7 + uVar3) * 4);
            }
            uVar3 = ((int)(uVar9 - 1) < 1) - 1 & uVar9 - 1;
            local_3c = ((int)local_30 < 1) - 1 & local_30;
            uVar8 = uVar7 - 1;
            if ((int)uVar3 <= (int)(uVar7 - 1)) {
              uVar8 = uVar3;
            }
            local_18 = local_34;
            iVar4 = FUN_10006250((int *)&local_18,(int *)&local_3c);
            uVar3 = (uint)*(byte *)(local_24 + 3 + (iVar4 * uVar7 + uVar8) * 4);
            uVar5 = uVar5 + 1;
            uVar8 = local_20;
            if (uVar5 < local_38) {
              uVar8 = param_1[7];
              local_3c = ((int)uVar9 < 1) - 1 & uVar9;
              local_24 = uVar5 & ((int)uVar5 < 1) - 1;
              local_18 = uVar7 - 1;
              local_3c = FUN_10006250((int *)&local_18,(int *)&local_3c);
              local_24 = FUN_10006250((int *)&local_34,(int *)&local_24);
              uVar8 = (uint)*(byte *)(uVar8 + 3 + (local_24 * uVar7 + local_3c) * 4);
            }
            local_34 = local_30 - 1;
            uVar5 = param_1[7];
            local_18 = 0;
            local_3c = uVar9;
            local_3c = FUN_10006230((int *)&local_18,(int *)&local_3c);
            local_24 = 0;
            local_34 = FUN_10006230((int *)&local_24,(int *)&local_34);
            local_14 = uVar7 - 1;
            local_3c = FUN_10006250(&local_14,(int *)&local_3c);
            local_10 = local_38 - 1;
            local_34 = FUN_10006250(&local_10,(int *)&local_34);
            cVar1 = *(char *)(uVar5 + 3 + (local_34 * uVar7 + local_3c) * 4);
            iVar4 = uVar3 - local_2c;
            if (((int)local_20 < (int)uVar3) && ((int)local_20 < (int)local_2c)) {
              iVar4 = uVar3 - local_20;
              if ((int)(uVar3 - local_20) < (int)(local_20 - local_2c)) {
                iVar4 = local_20 - local_2c;
              }
            }
            local_1c[-2] = (char)iVar4;
            local_1c[-1] = cVar1 - (char)uVar8;
            *local_1c = 0;
            local_1c[1] = 0;
            local_1c = local_1c + 4;
            puVar2 = local_8;
            uVar9 = local_c;
          } while (local_c < uVar7);
        }
        local_28 = local_28 + uVar7 * 4;
        local_30 = local_30 + 1;
        uVar9 = local_4;
      } while (local_30 < local_38);
    }
    puVar10 = puVar2;
    puVar11 = (undefined4 *)param_1[7];
    for (uVar7 = uVar9 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
      *puVar11 = *puVar10;
      puVar10 = puVar10 + 1;
      puVar11 = puVar11 + 1;
    }
    for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
      *(undefined1 *)puVar11 = *(undefined1 *)puVar10;
      puVar10 = (undefined4 *)((int)puVar10 + 1);
      puVar11 = (undefined4 *)((int)puVar11 + 1);
    }
    FUN_1000fe9b((undefined *)puVar2);
  }
  return;
}



/* ===== FUN_10005950 @ 0x10005950 ===== */

void __cdecl FUN_10005950(uint *param_1,uint param_2)

{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint *puVar8;
  uint *puVar9;
  uint uVar10;
  uint *puVar11;
  longlong lVar12;
  uint local_30;
  uint *local_2c;
  uint *local_28;
  uint *local_24;
  uint *local_20;
  uint local_1c [2];
  uint *local_14;
  undefined4 uStack_10;
  uint local_c;
  uint local_8;
  undefined4 uStack_4;
  
  puVar11 = (uint *)param_1[7];
  if (puVar11 != (uint *)0x0) {
    uVar6 = *param_1;
    uVar1 = param_1[1];
    local_1c[0] = uVar1 * uVar6;
    local_c = local_1c[0] * 4;
    puVar2 = operator_new(local_c);
    local_30 = 0;
    switch(param_2) {
    case 0:
      param_2 = 0;
      puVar8 = puVar2;
      if (uVar1 != 0) {
        do {
          local_24 = puVar8;
          uVar10 = 0;
          if (uVar6 != 0) {
            local_2c = (uint *)(uVar1 - 1);
            puVar8 = local_24;
            do {
              local_30 = param_2;
              local_1c[0] = 0;
              local_28 = (uint *)(((int)uVar10 < 1) - 1 & uVar10);
              local_30 = FUN_10006230((int *)local_1c,(int *)&local_30);
              local_20 = (uint *)(uVar6 - 1);
              local_28 = (uint *)FUN_10006250((int *)&local_20,(int *)&local_28);
              local_14 = local_2c;
              local_30 = FUN_10006250((int *)&local_14,(int *)&local_30);
              puVar9 = (uint *)puVar11[(int)(local_30 * uVar6 + (int)local_28)];
              uStack_4 = 0;
              local_8 = ((uint)puVar9 >> 0x10 & 0xff) + ((uint)puVar9 >> 8 & 0xff) +
                        ((uint)puVar9 & 0xff);
              local_14 = puVar9;
              lVar12 = __ftol();
              *puVar8 = (int)lVar12 << 0x18 | (uint)puVar9 & 0xffffff;
              uVar10 = uVar10 + 1;
              puVar8 = puVar8 + 1;
            } while (uVar10 < uVar6);
          }
          local_24 = local_24 + uVar6;
          param_2 = param_2 + 1;
          puVar8 = local_24;
        } while (param_2 < uVar1);
      }
    case 2:
      uVar10 = 0;
      puVar8 = puVar2;
      if (uVar1 != 0) {
        do {
          uVar5 = 0;
          puVar9 = puVar8;
          if (uVar6 != 0) {
            do {
              uVar7 = ((int)uVar5 < 1) - 1 & uVar5;
              uVar3 = ((int)uVar10 < 1) - 1 & uVar10;
              if ((int)(uVar6 - 1) < (int)uVar7) {
                uVar7 = uVar6 - 1;
              }
              if ((int)(uVar1 - 1) < (int)uVar3) {
                uVar3 = uVar1 - 1;
              }
              local_24 = (uint *)puVar11[uVar3 * uVar6 + uVar7];
              *puVar9 = ((uint)local_24 >> 0x10) << 0x18 | (uint)local_24 & 0xffffff;
              uVar5 = uVar5 + 1;
              puVar9 = puVar9 + 1;
            } while (uVar5 < uVar6);
          }
          uVar10 = uVar10 + 1;
          puVar8 = puVar8 + uVar6;
        } while (uVar10 < uVar1);
      }
    case 3:
      param_2 = 0;
      puVar8 = puVar2;
      if (uVar1 != 0) {
        do {
          local_24 = puVar8;
          if (uVar6 != 0) {
            uVar10 = 0;
            puVar8 = local_24;
            do {
              uVar5 = ((int)uVar10 < 1) - 1 & uVar10;
              local_28 = (uint *)(param_2 & ((int)param_2 < 1) - 1);
              if ((int)(uVar6 - 1) < (int)uVar5) {
                uVar5 = uVar6 - 1;
              }
              local_14 = (uint *)(uVar1 - 1);
              local_28 = (uint *)FUN_10006250((int *)&local_14,(int *)&local_28);
              *puVar8 = (puVar11[(int)local_28 * uVar6 + uVar5] >> 8) << 0x18 |
                        puVar11[(int)local_28 * uVar6 + uVar5] & 0xffffff;
              uVar10 = uVar10 + 1;
              puVar8 = puVar8 + 1;
            } while (uVar10 < uVar6);
          }
          local_24 = local_24 + uVar6;
          param_2 = param_2 + 1;
          puVar8 = local_24;
        } while (param_2 < uVar1);
      }
    case 4:
      param_2 = 0;
      puVar8 = puVar2;
      if (uVar1 != 0) {
        do {
          local_24 = puVar8;
          if (uVar6 != 0) {
            uVar10 = 0;
            puVar8 = local_24;
            do {
              uVar5 = ((int)uVar10 < 1) - 1 & uVar10;
              local_28 = (uint *)(param_2 & ((int)param_2 < 1) - 1);
              if ((int)(uVar6 - 1) < (int)uVar5) {
                uVar5 = uVar6 - 1;
              }
              local_14 = (uint *)(uVar1 - 1);
              local_28 = (uint *)FUN_10006250((int *)&local_14,(int *)&local_28);
              *puVar8 = puVar11[(int)local_28 * uVar6 + uVar5] << 0x18 |
                        puVar11[(int)local_28 * uVar6 + uVar5] & 0xffffff;
              uVar10 = uVar10 + 1;
              puVar8 = puVar8 + 1;
            } while (uVar10 < uVar6);
          }
          local_24 = local_24 + uVar6;
          param_2 = param_2 + 1;
          puVar8 = local_24;
        } while (param_2 < uVar1);
      }
    case 5:
      param_2 = 0;
      puVar8 = puVar2;
      if (uVar1 != 0) {
        do {
          local_28 = puVar8;
          uVar10 = 0;
          if (uVar6 != 0) {
            local_2c = local_28;
            do {
              uVar5 = ((int)uVar10 < 1) - 1 & uVar10;
              local_24 = (uint *)(param_2 & ((int)param_2 < 1) - 1);
              if ((int)(uVar6 - 1) < (int)uVar5) {
                uVar5 = uVar6 - 1;
              }
              local_14 = (uint *)(uVar1 - 1);
              iVar4 = FUN_10006250((int *)&local_14,(int *)&local_24);
              local_24 = (uint *)puVar11[iVar4 * uVar6 + uVar5];
              uVar3 = (uint)local_24 >> 8 & 0xff;
              uVar5 = (uint)local_24 >> 0x10 & 0xff;
              if (uVar5 < uVar3) {
                uVar5 = uVar3;
              }
              uVar3 = (uint)local_24 & 0xff;
              if (((uint)local_24 & 0xff) <= uVar5) {
                uVar3 = uVar5;
              }
              *local_2c = uVar3 << 0x18 | (uint)local_24 & 0xffffff;
              uVar10 = uVar10 + 1;
              local_2c = local_2c + 1;
            } while (uVar10 < uVar6);
          }
          local_28 = local_28 + uVar6;
          param_2 = param_2 + 1;
          puVar8 = local_28;
        } while (param_2 < uVar1);
      }
    case 6:
      param_2 = 0;
      puVar8 = puVar2;
      if (uVar1 != 0) {
        do {
          local_24 = puVar8;
          uVar10 = 0;
          puVar8 = local_24;
          if (uVar6 != 0) {
            do {
              uVar7 = ((int)uVar10 < 1) - 1 & uVar10;
              uVar5 = param_2 & ((int)param_2 < 1) - 1;
              uVar3 = uVar6 - 1;
              if ((int)uVar7 <= (int)(uVar6 - 1)) {
                uVar3 = uVar7;
              }
              if ((int)(uVar1 - 1) < (int)uVar5) {
                uVar5 = uVar1 - 1;
              }
              uVar5 = puVar11[uVar5 * uVar6 + uVar3];
              local_8 = uVar5 >> 0x10 & 0xff;
              uStack_4 = 0;
              local_14 = (uint *)(uVar5 >> 8 & 0xff);
              uStack_10 = 0;
              local_1c[0] = uVar5 & 0xff;
              local_1c[1] = 0;
              lVar12 = __ftol();
              *puVar8 = (int)lVar12 << 0x18 | uVar5 & 0xffffff;
              uVar10 = uVar10 + 1;
              puVar8 = puVar8 + 1;
            } while (uVar10 < uVar6);
          }
          local_24 = local_24 + uVar6;
          param_2 = param_2 + 1;
          puVar8 = local_24;
        } while (param_2 < uVar1);
      }
      break;
    case 1:
      uVar10 = 0;
      if (uVar1 != 0) {
        do {
          uVar5 = 0;
          if (uVar6 != 0) {
            local_2c = (uint *)(uVar1 - 1);
            do {
              param_2 = ((int)uVar5 < 1) - 1 & uVar5;
              local_24 = (uint *)(((int)uVar10 < 1) - 1 & uVar10);
              local_28 = (uint *)(uVar6 - 1);
              param_2 = FUN_10006250((int *)&local_28,(int *)&param_2);
              local_20 = local_2c;
              local_24 = (uint *)FUN_10006250((int *)&local_20,(int *)&local_24);
              param_2 = puVar11[(int)local_24 * uVar6 + param_2];
              uStack_10 = 0;
              local_14 = (uint *)((param_2 >> 8 & 0xff) + (param_2 >> 0x10 & 0xff) +
                                 (param_2 & 0xff));
              lVar12 = __ftol();
              local_30 = local_30 + ((uint)lVar12 & 0xff);
              uVar5 = uVar5 + 1;
            } while (uVar5 < uVar6);
          }
          uVar10 = uVar10 + 1;
        } while (uVar10 < uVar1);
      }
      local_30 = (int)local_30 / (int)local_1c[0];
      uVar10 = 0;
      puVar8 = puVar2;
      if (uVar1 != 0) {
        do {
          local_2c = puVar8;
          uVar5 = 0;
          puVar8 = local_2c;
          if (uVar6 != 0) {
            do {
              param_2 = ((int)uVar5 < 1) - 1 & uVar5;
              local_24 = (uint *)(((int)uVar10 < 1) - 1 & uVar10);
              local_1c[0] = uVar6 - 1;
              param_2 = FUN_10006250((int *)local_1c,(int *)&param_2);
              local_20 = (uint *)(uVar1 - 1);
              local_24 = (uint *)FUN_10006250((int *)&local_20,(int *)&local_24);
              param_2 = puVar11[(int)local_24 * uVar6 + param_2];
              uStack_10 = 0;
              local_14 = (uint *)((param_2 >> 0x10 & 0xff) + (param_2 >> 8 & 0xff) +
                                 (param_2 & 0xff));
              lVar12 = __ftol();
              uVar3 = ((uint)lVar12 & 0xff) - local_30;
              uVar7 = (int)uVar3 >> 0x1f;
              *puVar8 = ((uVar3 ^ uVar7) - uVar7) * 0x1000000;
              uVar5 = uVar5 + 1;
              puVar8 = puVar8 + 1;
            } while (uVar5 < uVar6);
          }
          local_2c = local_2c + uVar6;
          uVar10 = uVar10 + 1;
          puVar8 = local_2c;
        } while (uVar10 < uVar1);
      }
    }
    puVar8 = puVar2;
    for (uVar6 = local_c >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *puVar11 = *puVar8;
      puVar8 = puVar8 + 1;
      puVar11 = puVar11 + 1;
    }
    for (uVar6 = local_c & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(char *)puVar11 = (char)*puVar8;
      puVar8 = (uint *)((int)puVar8 + 1);
      puVar11 = (uint *)((int)puVar11 + 1);
    }
    FUN_1000fe9b((undefined *)puVar2);
  }
  return;
}



/* ===== FUN_10006120 @ 0x10006120 ===== */

uint __cdecl FUN_10006120(int *param_1)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  
  puVar3 = (uint *)param_1[7];
  uVar2 = param_1[1];
  if (puVar3 != (uint *)0x0) {
    uVar1 = *puVar3;
    uVar5 = uVar2 * *param_1;
    uVar4 = 0;
    if (uVar5 != 0) {
      do {
        uVar2 = *puVar3 & 0xff000000;
        puVar3 = puVar3 + 1;
        if (uVar2 != (uVar1 & 0xff000000)) {
          return CONCAT31((int3)(uVar2 >> 8),1);
        }
        uVar4 = uVar4 + 1;
      } while (uVar4 < uVar5);
    }
  }
  return uVar2 & 0xffffff00;
}



/* ===== FUN_10006170 @ 0x10006170 ===== */

undefined4 __cdecl FUN_10006170(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  
  fVar1 = *param_2 * *param_2 + *param_3 * *param_3 + *param_1 * *param_1;
  fVar2 = fVar1 - 1.0;
  if (fVar2 < 0.0) {
    fVar2 = -fVar2;
  }
  if (fVar2 < 1e-12) {
    return 0;
  }
  fVar1 = SQRT(fVar1);
  fVar2 = fVar1;
  if (fVar1 < 0.0) {
    fVar2 = -fVar1;
  }
  if (fVar2 < 1e-24) {
    *param_3 = 0.0;
    *param_2 = 0.0;
    *param_1 = 0.0;
    return 0xffffb1df;
  }
  fVar1 = 1.0 / fVar1;
  *param_1 = fVar1 * *param_1;
  *param_2 = fVar1 * *param_2;
  *param_3 = fVar1 * *param_3;
  return 0;
}



/* ===== FUN_10006230 @ 0x10006230 ===== */

int __cdecl FUN_10006230(int *param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (*param_1 < *param_2) {
    iVar1 = *param_2;
  }
  return iVar1;
}



/* ===== FUN_10006250 @ 0x10006250 ===== */

int __cdecl FUN_10006250(int *param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (*param_2 <= *param_1) {
    iVar1 = *param_2;
  }
  return iVar1;
}



/* ===== FUN_10006270 @ 0x10006270 ===== */

void __cdecl FUN_10006270(undefined4 param_1,undefined4 param_2,LPCSTR param_3)

{
  CHAR local_200 [512];
  
  FUN_1000feb4(local_200,(byte *)s_Generic_application_error_0x_X__E_1001e3d8);
  if (param_3 != (LPCSTR)0x0) {
    lstrcatA(local_200,param_3);
  }
  (*DAT_10024714)(local_200);
  MessageBoxA((HWND)0x0,local_200,s_GFX_DX7_1001e3d0,0x10);
  return;
}



/* ===== FUN_100062d0 @ 0x100062D0 ===== */

undefined4 __cdecl FUN_100062d0(int param_1)

{
  bool bVar1;
  
  if (param_1 < 0x4a) {
    if (param_1 != 0x49) {
      switch(param_1) {
      case 0:
switchD_100062e8_caseD_0:
        return 0;
      default:
switchD_100062e8_caseD_1:
        return 0;
      case 0x14:
        return 0x18;
      case 0x15:
      case 0x16:
      case 0x3e:
      case 0x3f:
      case 0x40:
      case 0x41:
      case 0x47:
switchD_100062e8_caseD_15:
        return 0x20;
      case 0x17:
      case 0x18:
      case 0x19:
      case 0x1a:
      case 0x1d:
      case 0x1e:
      case 0x28:
      case 0x33:
      case 0x3c:
      case 0x3d:
      case 0x46:
        break;
      case 0x1b:
      case 0x1c:
      case 0x29:
      case 0x32:
      case 0x34:
        return 8;
      }
    }
  }
  else if (param_1 < 0x31545845) {
    if (param_1 != 0x31545844) {
      switch(param_1) {
      case 0x4b:
      case 0x4d:
      case 0x4f:
      case 0x66:
        goto switchD_100062e8_caseD_15;
      default:
        goto switchD_100062e8_caseD_1;
      case 0x50:
      case 0x65:
        break;
      case 100:
        goto switchD_100062e8_caseD_0;
      }
    }
  }
  else {
    if (param_1 < 0x34545845) {
      if (param_1 == 0x34545844) {
        return 0x10;
      }
      if (param_1 == 0x32545844) {
        return 0x10;
      }
      if (param_1 == 0x32595559) {
        return 0x10;
      }
      bVar1 = param_1 == 0x33545844;
    }
    else {
      if (param_1 == 0x35545844) {
        return 0x10;
      }
      bVar1 = param_1 == 0x59565955;
    }
    if (!bVar1) {
      return 0;
    }
  }
  return 0x10;
}



/* ===== FUN_100063f0 @ 0x100063F0 ===== */

undefined4 __cdecl FUN_100063f0(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  bool bVar10;
  uint local_24;
  uint local_20;
  
  iVar8 = 0;
  local_24 = 0;
  local_20 = 0;
  uVar6 = 0;
  if (*(int *)(param_1 + 0xe0) != 0) {
    piVar4 = (int *)(param_1 + 0xe8);
    do {
      iVar1 = *piVar4 - param_3;
      iVar2 = piVar4[1];
      iVar7 = piVar4[-1] - param_2;
      if (iVar2 < 0x4a) {
        if (iVar2 == 0x49) goto switchD_10006456_caseD_17;
        switch(iVar2) {
        case 0:
switchD_10006456_caseD_0:
          iVar2 = 0;
          break;
        default:
switchD_10006456_caseD_1:
          iVar2 = 0;
          break;
        case 0x14:
          iVar2 = 0x18;
          break;
        case 0x15:
        case 0x16:
        case 0x3e:
        case 0x3f:
        case 0x40:
        case 0x41:
        case 0x47:
switchD_10006456_caseD_15:
          iVar2 = 0x20;
          break;
        case 0x17:
        case 0x18:
        case 0x19:
        case 0x1a:
        case 0x1d:
        case 0x1e:
        case 0x28:
        case 0x33:
        case 0x3c:
        case 0x3d:
        case 0x46:
          goto switchD_10006456_caseD_17;
        case 0x1b:
        case 0x1c:
        case 0x29:
        case 0x32:
        case 0x34:
          iVar2 = 8;
        }
      }
      else {
        if (iVar2 < 0x31545845) {
          if (iVar2 != 0x31545844) {
            switch(iVar2) {
            case 0x4b:
            case 0x4d:
            case 0x4f:
            case 0x66:
              goto switchD_10006456_caseD_15;
            default:
              goto switchD_10006456_caseD_1;
            case 0x50:
            case 0x65:
              break;
            case 100:
              goto switchD_10006456_caseD_0;
            }
          }
        }
        else if (iVar2 < 0x34545845) {
          if (((iVar2 != 0x34545844) && (iVar2 != 0x32545844)) && (iVar2 != 0x32595559)) {
            bVar10 = iVar2 == 0x33545844;
LAB_100064c0:
            if (!bVar10) goto switchD_10006456_caseD_1;
          }
        }
        else if (iVar2 != 0x35545844) {
          bVar10 = iVar2 == 0x59565955;
          goto LAB_100064c0;
        }
switchD_10006456_caseD_17:
        iVar2 = 0x10;
      }
      iVar2 = iVar2 - param_4;
      iVar5 = *(int *)(param_1 + 0xe4 + iVar8) - param_2;
      iVar3 = *(int *)(param_1 + 0xec + iVar8);
      iVar9 = *(int *)(param_1 + 0xe8 + iVar8) - param_3;
      if (iVar3 < 0x4a) {
        if (iVar3 == 0x49) goto switchD_10006500_caseD_17;
        switch(iVar3) {
        case 0:
switchD_10006500_caseD_0:
          iVar3 = 0;
          break;
        default:
switchD_10006500_caseD_1:
          iVar3 = 0;
          break;
        case 0x14:
          iVar3 = 0x18;
          break;
        case 0x15:
        case 0x16:
        case 0x3e:
        case 0x3f:
        case 0x40:
        case 0x41:
        case 0x47:
switchD_10006500_caseD_15:
          iVar3 = 0x20;
          break;
        case 0x17:
        case 0x18:
        case 0x19:
        case 0x1a:
        case 0x1d:
        case 0x1e:
        case 0x28:
        case 0x33:
        case 0x3c:
        case 0x3d:
        case 0x46:
          goto switchD_10006500_caseD_17;
        case 0x1b:
        case 0x1c:
        case 0x29:
        case 0x32:
        case 0x34:
          iVar3 = 8;
        }
      }
      else {
        if (iVar3 < 0x31545845) {
          if (iVar3 != 0x31545844) {
            switch(iVar3) {
            case 0x4b:
            case 0x4d:
            case 0x4f:
            case 0x66:
              goto switchD_10006500_caseD_15;
            default:
              goto switchD_10006500_caseD_1;
            case 0x50:
            case 0x65:
              break;
            case 100:
              goto switchD_10006500_caseD_0;
            }
          }
        }
        else if (iVar3 < 0x34545845) {
          if (((iVar3 != 0x34545844) && (iVar3 != 0x32545844)) && (iVar3 != 0x32595559)) {
            bVar10 = iVar3 == 0x33545844;
LAB_1000656a:
            if (!bVar10) goto switchD_10006500_caseD_1;
          }
        }
        else if (iVar3 != 0x35545844) {
          bVar10 = iVar3 == 0x59565955;
          goto LAB_1000656a;
        }
switchD_10006500_caseD_17:
        iVar3 = 0x10;
      }
      if (iVar2 < 1) {
        if (iVar3 - param_4 <= iVar2) {
LAB_10006593:
          if (iVar7 < 1) {
            if (iVar5 <= iVar7) {
LAB_100065a1:
              if (iVar1 < 1) {
                if (iVar9 <= iVar1) {
LAB_100065b3:
                  local_20 = local_24;
                  iVar8 = (-0xe8 - param_1) + (int)piVar4;
                }
              }
              else if (iVar1 <= iVar9) goto LAB_100065b3;
            }
          }
          else if (iVar7 <= iVar5) goto LAB_100065a1;
        }
      }
      else if (iVar2 <= iVar3 - param_4) goto LAB_10006593;
      local_24 = local_24 + 1;
      piVar4 = piVar4 + 5;
      uVar6 = local_20;
    } while (local_24 < *(uint *)(param_1 + 0xe0));
  }
  iVar8 = param_1 + uVar6 * 0x14;
  *(uint *)(param_1 + 0xc9c) = uVar6;
  if (*(int *)(iVar8 + 0xe4) != param_2) {
    return 0;
  }
  if (*(int *)(iVar8 + 0xe8) != param_3) {
    return 0;
  }
  iVar8 = *(int *)(iVar8 + 0xec);
  if (iVar8 < 0x4a) {
    if (iVar8 != 0x49) {
      switch(iVar8) {
      case 0:
switchD_10006632_caseD_0:
        iVar8 = 0;
        break;
      default:
switchD_10006632_caseD_1:
        iVar8 = 0;
        break;
      case 0x14:
        iVar8 = 0x18;
        break;
      case 0x15:
      case 0x16:
      case 0x3e:
      case 0x3f:
      case 0x40:
      case 0x41:
      case 0x47:
switchD_10006632_caseD_15:
        iVar8 = 0x20;
        break;
      case 0x17:
      case 0x18:
      case 0x19:
      case 0x1a:
      case 0x1d:
      case 0x1e:
      case 0x28:
      case 0x33:
      case 0x3c:
      case 0x3d:
      case 0x46:
        goto switchD_10006632_caseD_17;
      case 0x1b:
      case 0x1c:
      case 0x29:
      case 0x32:
      case 0x34:
        iVar8 = 8;
      }
      goto LAB_100066a7;
    }
  }
  else if (iVar8 < 0x31545845) {
    if (iVar8 != 0x31545844) {
      switch(iVar8) {
      case 0x4b:
      case 0x4d:
      case 0x4f:
      case 0x66:
        goto switchD_10006632_caseD_15;
      default:
        goto switchD_10006632_caseD_1;
      case 0x50:
      case 0x65:
        break;
      case 100:
        goto switchD_10006632_caseD_0;
      }
    }
  }
  else if (iVar8 < 0x34545845) {
    if (((iVar8 != 0x34545844) && (iVar8 != 0x32545844)) && (iVar8 != 0x32595559)) {
      bVar10 = iVar8 == 0x33545844;
LAB_1000669c:
      if (!bVar10) goto switchD_10006632_caseD_1;
    }
  }
  else if (iVar8 != 0x35545844) {
    bVar10 = iVar8 == 0x59565955;
    goto LAB_1000669c;
  }
switchD_10006632_caseD_17:
  iVar8 = 0x10;
LAB_100066a7:
  if (iVar8 != param_4) {
    return 0;
  }
  return 1;
}



/* ===== FUN_100068e0 @ 0x100068E0 ===== */

uint __cdecl FUN_100068e0(int param_1,LPCSTR param_2,undefined4 param_3)

{
  HANDLE pvVar1;
  HANDLE hHeap;
  LPVOID lpBuffer;
  int iVar2;
  DWORD DVar3;
  undefined4 *puVar4;
  LPCSTR dwBytes;
  undefined4 local_4;
  
  local_4 = 0;
  pvVar1 = CreateFileA(param_2,0x80000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,0,(HANDLE)0x0);
  if (pvVar1 == (HANDLE)0xffffffff) {
    return 0;
  }
  param_2 = (LPCSTR)GetFileSize(pvVar1,(LPDWORD)0x0);
  DVar3 = 8;
  dwBytes = param_2;
  hHeap = GetProcessHeap();
  lpBuffer = HeapAlloc(hHeap,DVar3,(SIZE_T)dwBytes);
  ReadFile(pvVar1,lpBuffer,(DWORD)param_2,(LPDWORD)&param_2,(LPOVERLAPPED)0x0);
  CloseHandle(pvVar1);
  puVar4 = &local_4;
  iVar2 = (**(code **)(**(int **)(param_1 + 0x850) + 300))
                    (*(int **)(param_1 + 0x850),param_3,lpBuffer,puVar4,0);
  DVar3 = 0;
  pvVar1 = GetProcessHeap();
  HeapFree(pvVar1,DVar3,lpBuffer);
  return (iVar2 < 0) - 1 & (uint)puVar4;
}



/* ===== FUN_10006990 @ 0x10006990 ===== */

uint __cdecl FUN_10006990(int param_1,LPCSTR param_2)

{
  HANDLE pvVar1;
  HANDLE hHeap;
  LPVOID lpBuffer;
  int iVar2;
  uint unaff_ESI;
  DWORD DVar3;
  LPCSTR dwBytes;
  undefined4 local_4;
  
  local_4 = 0;
  pvVar1 = CreateFileA(param_2,0x80000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,0,(HANDLE)0x0);
  if (pvVar1 == (HANDLE)0xffffffff) {
    return 0;
  }
  param_2 = (LPCSTR)GetFileSize(pvVar1,(LPDWORD)0x0);
  DVar3 = 8;
  dwBytes = param_2;
  hHeap = GetProcessHeap();
  lpBuffer = HeapAlloc(hHeap,DVar3,(SIZE_T)dwBytes);
  ReadFile(pvVar1,lpBuffer,(DWORD)param_2,(LPDWORD)&param_2,(LPOVERLAPPED)0x0);
  CloseHandle(pvVar1);
  iVar2 = (**(code **)(**(int **)(param_1 + 0x850) + 0x15c))
                    (*(int **)(param_1 + 0x850),lpBuffer,&local_4);
  DVar3 = 0;
  pvVar1 = GetProcessHeap();
  HeapFree(pvVar1,DVar3,lpBuffer);
  return (iVar2 < 0) - 1 & unaff_ESI;
}



/* ===== FUN_10006a40 @ 0x10006A40 ===== */

void __cdecl FUN_10006a40(int param_1)

{
  if (*(int *)(param_1 + 0x7b0) != 0) {
    (**(code **)(**(int **)(param_1 + 0x850) + 0x138))
              (*(int **)(param_1 + 0x850),*(int *)(param_1 + 0x7b0));
    *(undefined4 *)(param_1 + 0x7b0) = 0;
    (**(code **)(**(int **)(param_1 + 0x850) + 0x168))
              (*(int **)(param_1 + 0x850),*(undefined4 *)(param_1 + 0x7c4));
    *(undefined4 *)(param_1 + 0x7c4) = 0;
  }
  if (*(int *)(param_1 + 0x7b4) != 0) {
    (**(code **)(**(int **)(param_1 + 0x850) + 0x138))
              (*(int **)(param_1 + 0x850),*(int *)(param_1 + 0x7b4));
    *(undefined4 *)(param_1 + 0x7b4) = 0;
    (**(code **)(**(int **)(param_1 + 0x850) + 0x168))
              (*(int **)(param_1 + 0x850),*(undefined4 *)(param_1 + 0x7c8));
    *(undefined4 *)(param_1 + 0x7c8) = 0;
  }
  if (*(int *)(param_1 + 0x7b8) != 0) {
    (**(code **)(**(int **)(param_1 + 0x850) + 0x138))
              (*(int **)(param_1 + 0x850),*(int *)(param_1 + 0x7b8));
    *(undefined4 *)(param_1 + 0x7b8) = 0;
    (**(code **)(**(int **)(param_1 + 0x850) + 0x168))
              (*(int **)(param_1 + 0x850),*(undefined4 *)(param_1 + 0x7cc));
    *(undefined4 *)(param_1 + 0x7cc) = 0;
  }
  if (*(int *)(param_1 + 0x7bc) != 0) {
    (**(code **)(**(int **)(param_1 + 0x850) + 0x138))
              (*(int **)(param_1 + 0x850),*(int *)(param_1 + 0x7bc));
    *(undefined4 *)(param_1 + 0x7bc) = 0;
    (**(code **)(**(int **)(param_1 + 0x850) + 0x168))
              (*(int **)(param_1 + 0x850),*(undefined4 *)(param_1 + 2000));
    *(undefined4 *)(param_1 + 2000) = 0;
  }
  if (*(int *)(param_1 + 0x7c0) != 0) {
    (**(code **)(**(int **)(param_1 + 0x850) + 0x138))
              (*(int **)(param_1 + 0x850),*(int *)(param_1 + 0x7c0));
    *(undefined4 *)(param_1 + 0x7c0) = 0;
    (**(code **)(**(int **)(param_1 + 0x850) + 0x168))
              (*(int **)(param_1 + 0x850),*(undefined4 *)(param_1 + 0x7d4));
    *(undefined4 *)(param_1 + 0x7d4) = 0;
  }
  return;
}



/* ===== FUN_10006b80 @ 0x10006B80 ===== */

void __cdecl FUN_10006b80(int param_1)

{
  uint uVar1;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  
  if (*(int *)(param_1 + 0x7b0) == 0) {
    local_50 = 0x20000000;
    local_4c = 0x40020000;
    local_48 = 0x40040001;
    local_44 = 0x40040002;
    local_40 = 0xffffffff;
    uVar1 = FUN_100068e0(param_1,s_landscape_vso_1001e4a0,&local_50);
    *(uint *)(param_1 + 0x7b0) = uVar1;
    uVar1 = FUN_10006990(param_1,s_landscape_pso_1001e490);
    *(uint *)(param_1 + 0x7c4) = uVar1;
  }
  if (*(int *)(param_1 + 0x7b4) == 0) {
    local_50 = 0x20000000;
    local_4c = 0x40020000;
    local_48 = 0x40020001;
    local_44 = 0x40040002;
    local_40 = 0x40010003;
    local_3c = 0x40020004;
    local_38 = 0x40020005;
    local_34 = 0xffffffff;
    if (*(int *)(param_1 + 0xa14) != 0) {
      uVar1 = FUN_100068e0(param_1,s_bumpmodel_vso_1001e480,&local_50);
      *(uint *)(param_1 + 0x7b4) = uVar1;
      uVar1 = FUN_10006990(param_1,s_bumpmodel_pso_1001e470);
      *(uint *)(param_1 + 0x7c8) = uVar1;
    }
  }
  if (*(int *)(param_1 + 0x7b8) == 0) {
    local_50 = 0x20000000;
    local_4c = 0x40020000;
    local_48 = 0x40040001;
    local_44 = 0x40010002;
    local_40 = 0xffffffff;
    uVar1 = FUN_100068e0(param_1,s_shadow_vso_1001e464,&local_50);
    *(uint *)(param_1 + 0x7b8) = uVar1;
    uVar1 = FUN_10006990(param_1,s_shadow_pso_1001e458);
    *(uint *)(param_1 + 0x7cc) = uVar1;
  }
  if (*(int *)(param_1 + 0x7bc) == 0) {
    local_50 = 0x20000000;
    local_4c = 0x40020000;
    local_48 = 0x40040001;
    local_44 = 0x40010002;
    local_40 = 0xffffffff;
    uVar1 = FUN_100068e0(param_1,s_water_vso_1001e44c,&local_50);
    *(uint *)(param_1 + 0x7bc) = uVar1;
    uVar1 = FUN_10006990(param_1,s_water_pso_1001e440);
    *(uint *)(param_1 + 2000) = uVar1;
  }
  if (*(int *)(param_1 + 0x7c0) == 0) {
    local_50 = 0x20000000;
    local_4c = 0x40020000;
    local_48 = 0x40040001;
    local_44 = 0x40010002;
    local_40 = 0xffffffff;
    uVar1 = FUN_100068e0(param_1,s_ocean_vso_1001e434,&local_50);
    *(uint *)(param_1 + 0x7c0) = uVar1;
    uVar1 = FUN_10006990(param_1,s_ocean_pso_1001e428);
    *(uint *)(param_1 + 0x7d4) = uVar1;
  }
  return;
}



/* ===== FUN_10006d60 @ 0x10006D60 ===== */

void __cdecl FUN_10006d60(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  HWND hWnd;
  int iVar1;
  int iVar2;
  DWORD dwStyle;
  DWORD dwExStyle;
  tagRECT local_10;
  
  if (param_2 == 0) {
    param_2 = 800;
  }
  if (param_3 == 0) {
    param_3 = 600;
  }
  if (param_4 == 0) {
    param_4 = 0x20;
  }
  *(int *)(param_1 + 0x7ec) = param_4;
  *(int *)(param_1 + 0x968) = param_4;
  *(int *)(param_1 + 0x7e4) = param_2;
  *(int *)(param_1 + 0x960) = param_2;
  *(int *)(param_1 + 0x7e8) = param_3;
  *(int *)(param_1 + 0x964) = param_3;
  *(int *)(param_1 + 0x7f0) = param_5;
  *(int *)(param_1 + 0x898) = param_5;
  if (((*(int *)(param_1 + 0x838) == 0) || (param_6 != 0)) && (param_5 != 0)) {
    hWnd = *(HWND *)(param_1 + 0x824);
    iVar1 = GetSystemMetrics(0);
    iVar2 = GetSystemMetrics(1);
    dwStyle = GetWindowLongA(hWnd,-0x10);
    dwExStyle = GetWindowLongA(hWnd,-0x14);
    local_10.top = (iVar2 - param_3) / 2;
    local_10.bottom = local_10.top + param_3;
    local_10.left = (iVar1 - param_2) / 2;
    local_10.right = local_10.left + param_2;
    AdjustWindowRectEx(&local_10,dwStyle,0,dwExStyle);
    SetWindowPos(hWnd,(HWND)0x0,local_10.left,local_10.top,local_10.right - local_10.left,
                 local_10.bottom - local_10.top,0x540);
    GetWindowRect(*(HWND *)(param_1 + 0x824),(LPRECT)(param_1 + 0x828));
    iVar1 = *(int *)(param_1 + 0x83c);
    if (iVar1 != 0) {
      GetWindowRect(*(HWND *)(iVar1 + 0x2a3cc),(LPRECT)(iVar1 + 0x2a4d8));
      GetClientRect(*(HWND *)(*(int *)(param_1 + 0x83c) + 0x2a3cc),
                    (LPRECT)(*(int *)(param_1 + 0x83c) + 0x2a4e8));
    }
    *(undefined4 *)(param_1 + 0x838) = 1;
  }
  return;
}



/* ===== FUN_10006ee0 @ 0x10006EE0 ===== */

int __cdecl
FUN_10006ee0(int param_1,char *param_2,undefined4 param_3,int param_4,int param_5,int param_6,
            int param_7,int param_8,uint *param_9,uint *param_10)

{
  void *this;
  int *piVar1;
  char *pcVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  short *psVar7;
  uint uVar8;
  char *pcVar9;
  uint uVar10;
  char *pcVar11;
  bool bVar12;
  byte local_100 [256];
  
  *(undefined4 *)(param_1 + 0x824) = param_3;
  _strncpy((char *)local_100,param_2,0xff);
  *(undefined4 *)(param_1 + 0x7f8) = 1;
  pcVar2 = (char *)FUN_10010040(local_100,&DAT_1001e5b8);
  do {
    if (pcVar2 == (char *)0x0) {
      *(undefined4 *)(param_1 + 0xa10) = 1;
      if (*(int *)(param_1 + 0x7f4) != 0) {
        param_10 = (uint *)0x0;
        param_9 = (uint *)0x0;
      }
      FUN_10006d60(param_1,param_4,param_5,param_6,param_7,param_8);
      *(uint *)(param_1 + 0x7fc) = 0;
      *(undefined4 *)(param_1 + 0x800) = 0;
      *(undefined4 *)(param_1 + 0x804) = 0;
      *(undefined4 *)(param_1 + 0x808) = 0;
      *(uint *)(param_1 + 0x80c) = 0;
      *(undefined4 *)(param_1 + 0x810) = 0;
      *(undefined4 *)(param_1 + 0x814) = 0;
      *(undefined4 *)(param_1 + 0x818) = 0;
      if (param_9 != (uint *)0x0) {
        *(uint *)(param_1 + 0x7fc) = *param_9;
        *(uint *)(param_1 + 0x800) = param_9[1];
        *(uint *)(param_1 + 0x804) = param_9[2];
        *(uint *)(param_1 + 0x808) = param_9[3];
      }
      if (param_10 != (uint *)0x0) {
        *(uint *)(param_1 + 0x80c) = *param_10;
        *(uint *)(param_1 + 0x810) = param_10[1];
        *(uint *)(param_1 + 0x814) = param_10[2];
        *(uint *)(param_1 + 0x818) = param_10[3];
      }
      puVar3 = operator_new(0x2a5a4);
      if (puVar3 == (undefined4 *)0x0) {
        uVar4 = 0;
      }
      else {
        uVar4 = FUN_1000d290(puVar3);
      }
      *(undefined4 *)(param_1 + 0x83c) = uVar4;
      uVar4 = Direct3DCreate8(0x78);
      *(undefined4 *)(*(int *)(param_1 + 0x83c) + 0x2a3d4) = uVar4;
      this = *(void **)(param_1 + 0x83c);
      if (*(int *)((int)this + 0x2a3d4) == 0) {
        iVar6 = FUN_1000eb70(this,-0x7dffffff,1);
        return iVar6;
      }
      *(undefined4 *)((int)this + 0x2a58c) = 1;
      *(undefined4 *)(*(int *)(param_1 + 0x83c) + 0x2a590) = 0x18;
      *(undefined4 *)(*(int *)(param_1 + 0x83c) + 0x2a594) = 0;
      *(undefined4 *)(*(int *)(param_1 + 0x83c) + 0x2a3cc) = param_3;
      *(undefined4 *)(*(int *)(param_1 + 0x83c) + 0x2a3d0) = param_3;
      iVar6 = FUN_1000d590(*(int **)(param_1 + 0x83c));
      if (iVar6 < 0) {
        piVar1 = *(int **)(*(int *)(param_1 + 0x83c) + 0x2a3d4);
        if (piVar1 != (int *)0x0) {
          (**(code **)(*piVar1 + 8))(piVar1);
          *(undefined4 *)(*(int *)(param_1 + 0x83c) + 0x2a3d4) = 0;
        }
        FUN_1000fe9b(*(undefined **)(param_1 + 0x83c));
        *(undefined4 *)(param_1 + 0x83c) = 0;
        return 0;
      }
      iVar5 = FUN_10007540(param_1,param_3,param_9,param_10);
      if (iVar5 < 0) {
        FUN_100085d0(param_1);
        FUN_1000eb70(*(void **)(param_1 + 0x83c),iVar6,1);
        return 0;
      }
      FUN_1000b450(param_1);
      *(undefined4 *)(param_1 + 0x81c) = 1;
      if (*(int *)(param_1 + 0x8d0) == 0) {
        *(undefined4 *)(param_1 + 0x914) = 0;
      }
      else {
        puVar3 = _malloc(0x20);
        *(undefined4 **)(param_1 + 0x914) = puVar3;
        *puVar3 = s_Envmap_1001e4d0;
        *(undefined4 *)(*(int *)(param_1 + 0x914) + 4) = 0;
        *(undefined4 *)(*(int *)(param_1 + 0x914) + 8) = 0;
        *(undefined4 *)(*(int *)(param_1 + 0x914) + 0xc) = 7;
        *(undefined4 *)(*(int *)(param_1 + 0x914) + 0x10) = 7;
        *(undefined4 *)(*(int *)(param_1 + 0x914) + 0x14) = 0;
        *(undefined4 *)(*(int *)(param_1 + 0x914) + 0x18) = 0;
        *(undefined1 *)(*(int *)(param_1 + 0x914) + 0x1c) = 1;
        *(undefined1 *)(*(int *)(param_1 + 0x914) + 0x1d) = 0;
        *(undefined2 *)(*(int *)(param_1 + 0x914) + 0x1e) = 0;
        FUN_1000bab0(*(int *)(param_1 + 0x914),(uint *)0x80);
        (**(code **)(param_1 + 0xb0))(param_1,*(undefined4 *)(param_1 + 0x914));
      }
      *(undefined4 *)(param_1 + 0x92c) = 2;
      *(undefined4 *)(param_1 + 0x930) = 2;
      *(undefined4 *)(param_1 + 0x934) = 5;
      *(undefined4 *)(param_1 + 0x938) = 5;
      *(undefined4 *)(param_1 + 0x94c) = 4;
      *(undefined4 *)(param_1 + 0x950) = 4;
      *(undefined1 *)(param_1 + 0x93c) = 0x60;
      *(undefined1 *)(param_1 + 0x95c) = 0x60;
      *(char **)(param_1 + 0x920) = s_Default_Texture_1001e4c0;
      *(undefined **)(param_1 + 0x924) = &DAT_100246e0;
      *(undefined4 *)(param_1 + 0x928) = 0;
      *(undefined1 *)(param_1 + 0x93d) = 0;
      *(undefined2 *)(param_1 + 0x93e) = 0;
      *(char **)(param_1 + 0x940) = s_Cueing_Texture_1001e4b0;
      *(undefined2 **)(param_1 + 0x944) = &DAT_100242e0;
      *(undefined4 *)(param_1 + 0x948) = 0;
      *(undefined4 *)(param_1 + 0x954) = 3;
      *(undefined4 *)(param_1 + 0x958) = 3;
      *(undefined1 *)(param_1 + 0x95d) = 0;
      *(undefined2 *)(param_1 + 0x95e) = 0;
      psVar7 = &DAT_100242e0;
      uVar10 = 0xf;
      do {
        uVar8 = uVar10;
        if (uVar10 == 0xf) {
          uVar8 = 0;
        }
        iVar6 = 0;
        do {
          *psVar7 = (short)uVar8 * 0x111 + ((short)iVar6 + 1) * -0x1000;
          iVar6 = iVar6 + 1;
          psVar7 = psVar7 + 1;
        } while (iVar6 < 0x10);
        uVar10 = uVar10 - 1;
      } while (uVar10 < 0x80000000);
      FUN_100092e0(param_1);
      return 1;
    }
    iVar6 = 6;
    bVar12 = true;
    pcVar9 = pcVar2;
    pcVar11 = &DAT_1001e5b0;
    do {
      if (iVar6 == 0) break;
      iVar6 = iVar6 + -1;
      bVar12 = *pcVar9 == *pcVar11;
      pcVar9 = pcVar9 + 1;
      pcVar11 = pcVar11 + 1;
    } while (bVar12);
    if (bVar12) {
      *(undefined4 *)(param_1 + 0x7f4) = 1;
    }
    else {
      iVar6 = 7;
      bVar12 = true;
      pcVar9 = pcVar2;
      pcVar11 = &DAT_1001e5a8;
      do {
        if (iVar6 == 0) break;
        iVar6 = iVar6 + -1;
        bVar12 = *pcVar9 == *pcVar11;
        pcVar9 = pcVar9 + 1;
        pcVar11 = pcVar11 + 1;
      } while (bVar12);
      if (bVar12) {
        *(undefined4 *)(param_1 + 0x9d8) = 0x400000;
      }
      else {
        iVar6 = 7;
        bVar12 = true;
        pcVar9 = pcVar2;
        pcVar11 = &DAT_1001e5a0;
        do {
          if (iVar6 == 0) break;
          iVar6 = iVar6 + -1;
          bVar12 = *pcVar9 == *pcVar11;
          pcVar9 = pcVar9 + 1;
          pcVar11 = pcVar11 + 1;
        } while (bVar12);
        if (bVar12) {
          *(undefined4 *)(param_1 + 0x7f8) = 1;
        }
        else {
          iVar6 = 7;
          bVar12 = true;
          pcVar9 = pcVar2;
          pcVar11 = &DAT_1001e598;
          do {
            if (iVar6 == 0) break;
            iVar6 = iVar6 + -1;
            bVar12 = *pcVar9 == *pcVar11;
            pcVar9 = pcVar9 + 1;
            pcVar11 = pcVar11 + 1;
          } while (bVar12);
          if (bVar12) {
            *(undefined4 *)(param_1 + 0x7f8) = 0;
          }
          else {
            iVar6 = 9;
            bVar12 = true;
            pcVar9 = pcVar2;
            pcVar11 = s_safemode_1001e58c;
            do {
              if (iVar6 == 0) break;
              iVar6 = iVar6 + -1;
              bVar12 = *pcVar9 == *pcVar11;
              pcVar9 = pcVar9 + 1;
              pcVar11 = pcVar11 + 1;
            } while (bVar12);
            if (bVar12) {
              *(undefined4 *)(param_1 + 0x9d8) = 0x200000;
            }
            else {
              iVar6 = 7;
              bVar12 = true;
              pcVar9 = pcVar2;
              pcVar11 = &DAT_1001e584;
              do {
                if (iVar6 == 0) break;
                iVar6 = iVar6 + -1;
                bVar12 = *pcVar9 == *pcVar11;
                pcVar9 = pcVar9 + 1;
                pcVar11 = pcVar11 + 1;
              } while (bVar12);
              if (bVar12) {
                *(undefined4 *)(param_1 + 0x9e0) = 1;
              }
              else {
                iVar6 = 9;
                bVar12 = true;
                pcVar9 = pcVar2;
                pcVar11 = s_mixalpha_1001e578;
                do {
                  if (iVar6 == 0) break;
                  iVar6 = iVar6 + -1;
                  bVar12 = *pcVar9 == *pcVar11;
                  pcVar9 = pcVar9 + 1;
                  pcVar11 = pcVar11 + 1;
                } while (bVar12);
                if (bVar12) {
                  *(undefined4 *)(param_1 + 0x9ec) = 1;
                }
                else {
                  iVar6 = 9;
                  bVar12 = true;
                  pcVar9 = pcVar2;
                  pcVar11 = s_mixcolor_1001e56c;
                  do {
                    if (iVar6 == 0) break;
                    iVar6 = iVar6 + -1;
                    bVar12 = *pcVar9 == *pcVar11;
                    pcVar9 = pcVar9 + 1;
                    pcVar11 = pcVar11 + 1;
                  } while (bVar12);
                  if (bVar12) {
                    *(undefined4 *)(param_1 + 0x9f0) = 1;
                  }
                  else {
                    iVar6 = 8;
                    bVar12 = true;
                    pcVar9 = pcVar2;
                    pcVar11 = s_noblend_1001e564;
                    do {
                      if (iVar6 == 0) break;
                      iVar6 = iVar6 + -1;
                      bVar12 = *pcVar9 == *pcVar11;
                      pcVar9 = pcVar9 + 1;
                      pcVar11 = pcVar11 + 1;
                    } while (bVar12);
                    if (bVar12) {
                      *(undefined4 *)(param_1 + 0x9e4) = 1;
                    }
                    else {
                      iVar6 = 6;
                      bVar12 = true;
                      pcVar9 = pcVar2;
                      pcVar11 = &DAT_1001e55c;
                      do {
                        if (iVar6 == 0) break;
                        iVar6 = iVar6 + -1;
                        bVar12 = *pcVar9 == *pcVar11;
                        pcVar9 = pcVar9 + 1;
                        pcVar11 = pcVar11 + 1;
                      } while (bVar12);
                      if (bVar12) {
                        *(undefined4 *)(param_1 + 0x91c) = 1;
                      }
                      else {
                        iVar6 = 0xd;
                        bVar12 = true;
                        pcVar9 = pcVar2;
                        pcVar11 = s_needstexture_1001e54c;
                        do {
                          if (iVar6 == 0) break;
                          iVar6 = iVar6 + -1;
                          bVar12 = *pcVar9 == *pcVar11;
                          pcVar9 = pcVar9 + 1;
                          pcVar11 = pcVar11 + 1;
                        } while (bVar12);
                        if (bVar12) {
                          *(undefined4 *)(param_1 + 0x918) = 1;
                        }
                        else {
                          iVar6 = 0xb;
                          bVar12 = true;
                          pcVar9 = pcVar2;
                          pcVar11 = s_noattached_1001e540;
                          do {
                            if (iVar6 == 0) break;
                            iVar6 = iVar6 + -1;
                            bVar12 = *pcVar9 == *pcVar11;
                            pcVar9 = pcVar9 + 1;
                            pcVar11 = pcVar11 + 1;
                          } while (bVar12);
                          if (bVar12) {
                            *(undefined4 *)(param_1 + 0x9fc) = 1;
                          }
                          else {
                            iVar6 = 0xb;
                            bVar12 = true;
                            pcVar9 = pcVar2;
                            pcVar11 = s_nodetached_1001e534;
                            do {
                              if (iVar6 == 0) break;
                              iVar6 = iVar6 + -1;
                              bVar12 = *pcVar9 == *pcVar11;
                              pcVar9 = pcVar9 + 1;
                              pcVar11 = pcVar11 + 1;
                            } while (bVar12);
                            if (bVar12) {
                              *(undefined4 *)(param_1 + 0xa00) = 1;
                            }
                            else {
                              iVar6 = 0xc;
                              bVar12 = true;
                              pcVar9 = pcVar2;
                              pcVar11 = s_displayonly_1001e528;
                              do {
                                if (iVar6 == 0) break;
                                iVar6 = iVar6 + -1;
                                bVar12 = *pcVar9 == *pcVar11;
                                pcVar9 = pcVar9 + 1;
                                pcVar11 = pcVar11 + 1;
                              } while (bVar12);
                              if (bVar12) {
                                *(undefined4 *)(param_1 + 0xa04) = 1;
                              }
                              else {
                                iVar6 = 10;
                                bVar12 = true;
                                pcVar9 = pcVar2;
                                pcVar11 = s_noprimary_1001e51c;
                                do {
                                  if (iVar6 == 0) break;
                                  iVar6 = iVar6 + -1;
                                  bVar12 = *pcVar9 == *pcVar11;
                                  pcVar9 = pcVar9 + 1;
                                  pcVar11 = pcVar11 + 1;
                                } while (bVar12);
                                if (bVar12) {
                                  *(undefined4 *)(param_1 + 0xa08) = 1;
                                }
                                else {
                                  iVar6 = 0x12;
                                  bVar12 = true;
                                  pcVar9 = pcVar2;
                                  pcVar11 = s_debugvertexshader_1001e508;
                                  do {
                                    if (iVar6 == 0) break;
                                    iVar6 = iVar6 + -1;
                                    bVar12 = *pcVar9 == *pcVar11;
                                    pcVar9 = pcVar9 + 1;
                                    pcVar11 = pcVar11 + 1;
                                  } while (bVar12);
                                  if (bVar12) {
                                    *(undefined4 *)(param_1 + 0xa0c) = 1;
                                    DAT_10024700 = 1;
                                  }
                                  else {
                                    iVar6 = 8;
                                    bVar12 = true;
                                    pcVar9 = pcVar2;
                                    pcVar11 = s_shaders_1001e500;
                                    do {
                                      if (iVar6 == 0) break;
                                      iVar6 = iVar6 + -1;
                                      bVar12 = *pcVar9 == *pcVar11;
                                      pcVar9 = pcVar9 + 1;
                                      pcVar11 = pcVar11 + 1;
                                    } while (bVar12);
                                    if (bVar12) {
                                      *(undefined4 *)(param_1 + 0xa10) = 1;
                                    }
                                    else {
                                      iVar6 = 0xc;
                                      bVar12 = true;
                                      pcVar9 = pcVar2;
                                      pcVar11 = s_bumpshaders_1001e4f4;
                                      do {
                                        if (iVar6 == 0) break;
                                        iVar6 = iVar6 + -1;
                                        bVar12 = *pcVar9 == *pcVar11;
                                        pcVar9 = pcVar9 + 1;
                                        pcVar11 = pcVar11 + 1;
                                      } while (bVar12);
                                      if (bVar12) {
                                        *(undefined4 *)(param_1 + 0xa14) = 1;
                                      }
                                      else {
                                        iVar6 = 0xb;
                                        bVar12 = true;
                                        pcVar9 = pcVar2;
                                        pcVar11 = s_bumpshader_1001e4e8;
                                        do {
                                          if (iVar6 == 0) break;
                                          iVar6 = iVar6 + -1;
                                          bVar12 = *pcVar9 == *pcVar11;
                                          pcVar9 = pcVar9 + 1;
                                          pcVar11 = pcVar11 + 1;
                                        } while (bVar12);
                                        if (bVar12) {
                                          *(undefined4 *)(param_1 + 0xa14) = 1;
                                        }
                                        else {
                                          iVar6 = 0xf;
                                          bVar12 = true;
                                          pcVar9 = s_allowreference_1001e4d8;
                                          do {
                                            if (iVar6 == 0) break;
                                            iVar6 = iVar6 + -1;
                                            bVar12 = *pcVar2 == *pcVar9;
                                            pcVar2 = pcVar2 + 1;
                                            pcVar9 = pcVar9 + 1;
                                          } while (bVar12);
                                          if (bVar12) {
                                            *(undefined4 *)(param_1 + 0xa18) = 1;
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    pcVar2 = (char *)FUN_10010040((byte *)0x0,&DAT_1001e5b8);
  } while( true );
}



/* ===== FUN_10007540 @ 0x10007540 ===== */

undefined4 __cdecl FUN_10007540(int param_1,undefined4 param_2,uint *param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  LONG LVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  uint *puVar7;
  uint *puVar8;
  uint *puVar9;
  uint *puVar10;
  bool bVar11;
  
  *(undefined4 *)(param_1 + 0x844) = 0;
  if (((param_3 != (uint *)0x0) && (param_4 != (uint *)0x0)) &&
     (iVar4 = *(int *)(param_1 + 0x83c), iVar4 != 0)) {
    uVar1 = *param_4;
    param_4 = (uint *)0x0;
    if (*(uint **)(iVar4 + 0x2a37c) != (uint *)0x0) {
      puVar8 = (uint *)(iVar4 + 0x440);
      do {
        uVar2 = 0;
        if (*puVar8 != 0) {
          puVar7 = puVar8 + 1;
          do {
            iVar6 = 4;
            bVar11 = true;
            puVar9 = puVar8 + -9;
            puVar10 = param_3;
            do {
              if (iVar6 == 0) break;
              iVar6 = iVar6 + -1;
              bVar11 = *puVar9 == *puVar10;
              puVar9 = puVar9 + 1;
              puVar10 = puVar10 + 1;
            } while (bVar11);
            if ((bVar11) && (*puVar7 == uVar1)) {
              puVar8[0xfd3] = uVar2;
              *(uint **)(iVar4 + 0x2a380) = param_4;
              goto LAB_10007618;
            }
            uVar2 = uVar2 + 1;
            puVar7 = puVar7 + 0x32a;
          } while (uVar2 < *puVar8);
        }
        param_4 = (uint *)((int)param_4 + 1);
        puVar8 = puVar8 + 0x10e3;
      } while (param_4 < *(uint **)(iVar4 + 0x2a37c));
    }
  }
LAB_10007618:
  iVar4 = *(int *)(*(int *)(param_1 + 0x83c) + 0x2a380) * 0x438c + 4 + *(int *)(param_1 + 0x83c);
  *(int *)(param_1 + 0x840) = iVar4;
  iVar4 = *(int *)(iVar4 + 0x4388) * 0xca8 + 0x440 + iVar4;
  *(int *)(param_1 + 0x844) = iVar4;
  FUN_100063f0(iVar4,*(int *)(param_1 + 0x960),*(int *)(param_1 + 0x964),*(int *)(param_1 + 0x968));
  if ((*(int *)(*(int *)(param_1 + 0x844) + 0xdc) == 0) || (*(int *)(param_1 + 0x7f0) == 0)) {
    *(undefined4 *)(*(int *)(param_1 + 0x83c) + 0x2a384) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x844) + 0xca0) = 0;
  }
  else {
    *(undefined4 *)(*(int *)(param_1 + 0x83c) + 0x2a384) = 1;
    *(undefined4 *)(*(int *)(param_1 + 0x844) + 0xca0) = 1;
  }
  LVar3 = GetWindowLongA(*(HWND *)(*(int *)(param_1 + 0x83c) + 0x2a3cc),-0x10);
  *(LONG *)(*(int *)(param_1 + 0x83c) + 0x2a4d4) = LVar3;
  GetWindowRect(*(HWND *)(*(int *)(param_1 + 0x83c) + 0x2a3cc),
                (LPRECT)(*(int *)(param_1 + 0x83c) + 0x2a4d8));
  GetClientRect(*(HWND *)(*(int *)(param_1 + 0x83c) + 0x2a3cc),
                (LPRECT)(*(int *)(param_1 + 0x83c) + 0x2a4e8));
  iVar4 = FUN_1000e2c0(*(int **)(param_1 + 0x83c));
  if (iVar4 < 0) {
    FUN_100063f0(*(int *)(param_1 + 0x844),0x280,0x1e0,0x20);
    *(undefined4 *)(*(int *)(param_1 + 0x844) + 0xca0) = 0;
    iVar4 = FUN_1000e2c0(*(int **)(param_1 + 0x83c));
    if (iVar4 < 0) {
      return 0x80004005;
    }
  }
  iVar4 = *(int *)(param_1 + 0x83c);
  *(undefined4 *)(param_1 + 0x84c) = *(undefined4 *)(iVar4 + 0x2a3d4);
  *(undefined4 *)(param_1 + 0x850) = *(undefined4 *)(iVar4 + 0x2a3d8);
  iVar6 = *(int *)(param_1 + 0x844);
  *(int *)(param_1 + 0x848) = iVar6 + 0xe4 + *(int *)(iVar6 + 0xc9c) * 0x14;
  *(undefined4 *)(param_1 + 0x960) = *(undefined4 *)(iVar6 + 0xe4 + *(int *)(iVar6 + 0xc9c) * 0x14);
  *(undefined4 *)(param_1 + 0x964) = *(undefined4 *)(iVar6 + 0xe8 + *(int *)(iVar6 + 0xc9c) * 0x14);
  iVar6 = *(int *)(iVar6 + 0xec + *(int *)(iVar6 + 0xc9c) * 0x14);
  if (iVar6 < 0x4a) {
    if (iVar6 == 0x49) goto switchD_100077eb_caseD_17;
    switch(iVar6) {
    case 0:
switchD_100077eb_caseD_0:
      uVar5 = 0;
      break;
    default:
switchD_100077eb_caseD_1:
      uVar5 = 0;
      break;
    case 0x14:
      uVar5 = 0x18;
      break;
    case 0x15:
    case 0x16:
    case 0x3e:
    case 0x3f:
    case 0x40:
    case 0x41:
    case 0x47:
switchD_100077eb_caseD_15:
      uVar5 = 0x20;
      break;
    case 0x17:
    case 0x18:
    case 0x19:
    case 0x1a:
    case 0x1d:
    case 0x1e:
    case 0x28:
    case 0x33:
    case 0x3c:
    case 0x3d:
    case 0x46:
      goto switchD_100077eb_caseD_17;
    case 0x1b:
    case 0x1c:
    case 0x29:
    case 0x32:
    case 0x34:
      uVar5 = 8;
    }
  }
  else {
    if (iVar6 < 0x31545845) {
      if (iVar6 != 0x31545844) {
        switch(iVar6) {
        case 0x4b:
        case 0x4d:
        case 0x4f:
        case 0x66:
          goto switchD_100077eb_caseD_15;
        default:
          goto switchD_100077eb_caseD_1;
        case 0x50:
        case 0x65:
          break;
        case 100:
          goto switchD_100077eb_caseD_0;
        }
      }
    }
    else if (iVar6 < 0x34545845) {
      if (((iVar6 != 0x34545844) && (iVar6 != 0x32545844)) && (iVar6 != 0x32595559)) {
        bVar11 = iVar6 == 0x33545844;
LAB_10007855:
        if (!bVar11) goto switchD_100077eb_caseD_1;
      }
    }
    else if (iVar6 != 0x35545844) {
      bVar11 = iVar6 == 0x59565955;
      goto LAB_10007855;
    }
switchD_100077eb_caseD_17:
    uVar5 = 0x10;
  }
  *(undefined4 *)(param_1 + 0x968) = uVar5;
  if (((*(byte *)(*(int *)(param_1 + 0x844) +
                 (*(int *)(*(int *)(param_1 + 0x844) + 0xc9c) + 0xc) * 0x14) & 0xd0) == 0) &&
     (DAT_10024700 == 0)) {
    uVar5 = 0;
  }
  else {
    uVar5 = 1;
  }
  *(undefined4 *)(param_1 + 0x8b8) = uVar5;
  *(undefined4 *)(param_1 + 0x960) = *(undefined4 *)(iVar4 + 0x2a4c8);
  *(undefined4 *)(param_1 + 0x964) = *(undefined4 *)(iVar4 + 0x2a4cc);
  iVar4 = *(int *)(iVar4 + 0x2a4b0);
  if (iVar4 < 0x4a) {
    if (iVar4 == 0x49) goto switchD_100078c8_caseD_17;
    switch(iVar4) {
    case 0:
switchD_100078c8_caseD_0:
      uVar5 = 0;
      break;
    default:
switchD_100078c8_caseD_1:
      uVar5 = 0;
      break;
    case 0x14:
      uVar5 = 0x18;
      break;
    case 0x15:
    case 0x16:
    case 0x3e:
    case 0x3f:
    case 0x40:
    case 0x41:
    case 0x47:
switchD_100078c8_caseD_15:
      uVar5 = 0x20;
      break;
    case 0x17:
    case 0x18:
    case 0x19:
    case 0x1a:
    case 0x1d:
    case 0x1e:
    case 0x28:
    case 0x33:
    case 0x3c:
    case 0x3d:
    case 0x46:
      goto switchD_100078c8_caseD_17;
    case 0x1b:
    case 0x1c:
    case 0x29:
    case 0x32:
    case 0x34:
      uVar5 = 8;
    }
  }
  else {
    if (iVar4 < 0x31545845) {
      if (iVar4 != 0x31545844) {
        switch(iVar4) {
        case 0x4b:
        case 0x4d:
        case 0x4f:
        case 0x66:
          goto switchD_100078c8_caseD_15;
        default:
          goto switchD_100078c8_caseD_1;
        case 0x50:
        case 0x65:
          break;
        case 100:
          goto switchD_100078c8_caseD_0;
        }
      }
    }
    else if (iVar4 < 0x34545845) {
      if (((iVar4 != 0x34545844) && (iVar4 != 0x32545844)) && (iVar4 != 0x32595559)) {
        bVar11 = iVar4 == 0x33545844;
LAB_10007939:
        if (!bVar11) goto switchD_100078c8_caseD_1;
      }
    }
    else if (iVar4 != 0x35545844) {
      bVar11 = iVar4 == 0x59565955;
      goto LAB_10007939;
    }
switchD_100078c8_caseD_17:
    uVar5 = 0x10;
  }
  *(undefined4 *)(param_1 + 0x968) = uVar5;
  iVar4 = *(int *)(*(int *)(param_1 + 0x848) + 0x10);
  if (iVar4 < 0x4a) {
    if (iVar4 != 0x49) {
      switch(iVar4) {
      case 0:
switchD_10007967_caseD_0:
        uVar5 = 0;
        break;
      default:
switchD_10007967_caseD_1:
        uVar5 = 0;
        break;
      case 0x14:
        uVar5 = 0x18;
        break;
      case 0x15:
      case 0x16:
      case 0x3e:
      case 0x3f:
      case 0x40:
      case 0x41:
      case 0x47:
switchD_10007967_caseD_15:
        uVar5 = 0x20;
        break;
      case 0x17:
      case 0x18:
      case 0x19:
      case 0x1a:
      case 0x1d:
      case 0x1e:
      case 0x28:
      case 0x33:
      case 0x3c:
      case 0x3d:
      case 0x46:
        goto switchD_10007967_caseD_17;
      case 0x1b:
      case 0x1c:
      case 0x29:
      case 0x32:
      case 0x34:
        uVar5 = 8;
      }
      goto LAB_100079dc;
    }
  }
  else if (iVar4 < 0x31545845) {
    if (iVar4 != 0x31545844) {
      switch(iVar4) {
      case 0x4b:
      case 0x4d:
      case 0x4f:
      case 0x66:
        goto switchD_10007967_caseD_15;
      default:
        goto switchD_10007967_caseD_1;
      case 0x50:
      case 0x65:
        break;
      case 100:
        goto switchD_10007967_caseD_0;
      }
    }
  }
  else if (iVar4 < 0x34545845) {
    if (((iVar4 != 0x34545844) && (iVar4 != 0x32545844)) && (iVar4 != 0x32595559)) {
      bVar11 = iVar4 == 0x33545844;
LAB_100079d1:
      if (!bVar11) goto switchD_10007967_caseD_1;
    }
  }
  else if (iVar4 != 0x35545844) {
    bVar11 = iVar4 == 0x59565955;
    goto LAB_100079d1;
  }
switchD_10007967_caseD_17:
  uVar5 = 0x10;
LAB_100079dc:
  *(undefined4 *)(param_1 + 0x96c) = uVar5;
  FUN_10007bd0(param_1);
  FUN_1000ce00(param_1);
  (**(code **)(param_1 + 0x3c))(param_1,0);
  (**(code **)(param_1 + 0x98))(param_1,0);
  (**(code **)(param_1 + 0xa8))(param_1);
  if (*(int *)(param_1 + 0xa10) != 0) {
    FUN_10006b80(param_1);
  }
  return 0;
}



/* ===== FUN_10007bd0 @ 0x10007BD0 ===== */

void __cdecl FUN_10007bd0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  iVar1 = *(int *)(param_1 + 0x83c);
  *(uint *)(param_1 + 0x89c) = *(uint *)(iVar1 + 0x2a400) & 0x40000;
  *(uint *)(param_1 + 0x8e4) = *(uint *)(iVar1 + 0x2a400) & 0x100000;
  if (((*(uint *)(iVar1 + 0x2a400) & 0x10000) == 0) || (*(int *)(param_1 + 0x8b8) == 0)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  *(undefined4 *)(param_1 + 0x8e8) = uVar2;
  *(uint *)(param_1 + 0x8ec) = *(uint *)(iVar1 + 0x2a400) & 0x100;
  *(uint *)(param_1 + 0x8f0) = *(uint *)(iVar1 + 0x2a400) & 0x80;
  *(uint *)(param_1 + 0x8bc) = *(uint *)(iVar1 + 0x2a400) & 0x4000;
  *(uint *)(param_1 + 0x8c0) = *(uint *)(iVar1 + 0x2a400) & 0x2000;
  if (((*(uint *)(iVar1 + 0x2a408) & 0x100) == 0) || ((*(byte *)(iVar1 + 0x2a40c) & 4) == 0)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  *(undefined4 *)(param_1 + 0x8c4) = uVar2;
  *(undefined4 *)(param_1 + 0x854) = 2;
  *(undefined4 *)(param_1 + 0x85c) = 2;
  iVar3 = *(int *)(iVar1 + 0x2a434);
  *(int *)(param_1 + 0x858) = iVar3;
  if (iVar3 == 0) {
    *(undefined4 *)(param_1 + 0x858) = 0x100;
  }
  iVar3 = *(int *)(iVar1 + 0x2a438);
  *(int *)(param_1 + 0x860) = iVar3;
  if (iVar3 == 0) {
    *(undefined4 *)(param_1 + 0x860) = 0x100;
  }
  if ((*(byte *)(iVar1 + 0x2a418) & 0x20) == 0) {
    if (*(int *)(iVar1 + 0x2a444) == 0) {
      *(undefined4 *)(param_1 + 0x8a0) = 0xffffffff;
    }
    else {
      iVar3 = FUN_10004980(*(int *)(iVar1 + 0x2a444));
      *(int *)(param_1 + 0x8a0) = iVar3;
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x8a0) = 0;
  }
  if ((((*(uint *)(iVar1 + 0x2a400) & 0x20000) == 0) || ((*(uint *)(iVar1 + 0x2a41c) & 0x400) == 0))
     || ((*(uint *)(iVar1 + 0x2a41c) & 0x4000000) == 0)) {
    *(undefined4 *)(param_1 + 0x8a4) = 0;
    if (((*(uint *)(iVar1 + 0x2a41c) & 0x200) == 0) ||
       ((*(uint *)(iVar1 + 0x2a41c) & 0x2000000) == 0)) {
      *(undefined4 *)(param_1 + 0x8a8) = 1;
      *(undefined4 *)(param_1 + 0x8ac) = 1;
    }
    else {
      *(undefined4 *)(param_1 + 0x8a8) = 2;
      *(undefined4 *)(param_1 + 0x8ac) = 2;
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x8a4) = *(undefined4 *)(iVar1 + 0x2a448);
    *(undefined4 *)(param_1 + 0x8a8) = 3;
    *(undefined4 *)(param_1 + 0x8ac) = 3;
  }
  if ((*(uint *)(iVar1 + 0x2a41c) & 0x20000) == 0) {
    if ((*(uint *)(iVar1 + 0x2a41c) & 0x10000) == 0) {
      *(undefined4 *)(param_1 + 0x8b4) = 0;
    }
    else {
      *(undefined4 *)(param_1 + 0x8b0) = 1;
      *(undefined4 *)(param_1 + 0x8b4) = 1;
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x8b0) = 2;
    *(undefined4 *)(param_1 + 0x8b4) = 1;
  }
  iVar3 = *(int *)(iVar1 + 0x2a474);
  *(int *)(param_1 + 0x8c8) = iVar3;
  if (((*(byte *)(iVar1 + 0x2a46e) & 0x80) == 0) || (iVar3 < 2)) {
    iVar3 = 0;
  }
  else {
    iVar3 = 1;
  }
  *(int *)(param_1 + 0x8cc) = iVar3;
  if (iVar3 == 0) {
    if (((*(uint *)(iVar1 + 0x2a46c) & 0x200000) == 0) || (*(int *)(param_1 + 0x8c8) < 3)) {
      iVar3 = 0;
    }
    else {
      iVar3 = 1;
    }
    *(int *)(param_1 + 0x8cc) = iVar3;
    if (iVar3 == 0) {
      *(undefined4 *)(param_1 + 0x8cc) = 0;
      goto LAB_10007ded;
    }
    *(undefined4 *)(param_1 + 0x8d0) = 1;
  }
  else {
LAB_10007ded:
    *(undefined4 *)(param_1 + 0x8d0) = 0;
  }
  if (((*(uint *)(iVar1 + 0x2a418) & 0x800) == 0) || (*(int *)(param_1 + 0x8c8) < 2)) {
    iVar3 = 0;
  }
  else {
    iVar3 = 1;
  }
  *(int *)(param_1 + 0x8d4) = iVar3;
  *(uint *)(param_1 + 0x8d8) = *(uint *)(iVar1 + 0x2a46c) & 0x10;
  *(uint *)(param_1 + 0x8dc) = *(uint *)(iVar1 + 0x2a46c) & 0x20;
  *(uint *)(param_1 + 0x8e0) = *(uint *)(iVar1 + 0x2a46c) & 0x400;
  *(undefined4 *)(param_1 + 0x9b0) = 0;
  *(undefined4 *)(param_1 + 0x9b4) = 0;
  *(undefined4 *)(param_1 + 0x9b8) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x9bc) = 0xbdcccccd;
  *(undefined4 *)(param_1 + 0x9c0) = 0xbd4ccccd;
  *(undefined4 *)(param_1 + 0x9d4) = 0;
  if (*(int *)(param_1 + 0x9d8) == 0) {
    *(undefined4 *)(param_1 + 0x9d8) = 0x8000000;
  }
  uVar4 = 0x4e409;
  if (*(int *)(param_1 + 0x8cc) != 0) {
    uVar4 = 0x4e40b;
  }
  if ((iVar3 != 0) && (*(int *)(param_1 + 0x8b8) != 0)) {
    uVar4 = uVar4 | 4;
  }
  if (*(int *)(param_1 + 0x8d8) != 0) {
    uVar4 = uVar4 | 0x20;
  }
  if (*(int *)(param_1 + 0x8dc) != 0) {
    uVar4 = uVar4 | 0x10;
  }
  if (*(int *)(param_1 + 0x89c) != 0) {
    uVar4 = uVar4 | 0x100;
  }
  if (*(int *)(param_1 + 0x8bc) != 0) {
    uVar4 = uVar4 | 0x80;
  }
  if (*(int *)(param_1 + 0x8c4) != 0) {
    uVar4 = uVar4 | 0x40;
  }
  if (*(int *)(param_1 + 0x8e0) != 0) {
    uVar4 = uVar4 | 0x800;
  }
  if (*(int *)(param_1 + 0x8b8) == 0) {
    uVar4 = uVar4 & 0xffff7fff;
  }
  else {
    uVar4 = uVar4 | 0x1000;
  }
  iVar1 = *(int *)(param_1 + 0x840);
  if (*(int *)(iVar1 + 0x408) == 0x102b) {
    if (*(int *)(iVar1 + 0x40c) == 0x521) {
      *(undefined4 *)(param_1 + 0x9e4) = 1;
      *(undefined4 *)(param_1 + 0x9ec) = 1;
      uVar4 = uVar4 & 0xfffbffff;
    }
    else if (*(int *)(iVar1 + 0x40c) == 0x525) {
      uVar4 = uVar4 & 0xfffff7bf;
    }
  }
  if (*(int *)(iVar1 + 0x408) == 0x5333) {
    if (*(int *)(iVar1 + 0x40c) == 0x9102) {
      uVar4 = uVar4 & 0xffffbfff | 0x20000;
    }
    else if (*(int *)(iVar1 + 0x40c) == 0x8a22) {
      *(undefined4 *)(param_1 + 0x858) = 0x400;
      *(undefined4 *)(param_1 + 0x860) = 0x400;
      *(undefined4 *)(param_1 + 0x8b4) = 0;
    }
  }
  if (*(int *)(iVar1 + 0x408) == 0x1002) {
    iVar3 = *(int *)(iVar1 + 0x40c);
    if (((((((((iVar3 != 0x5041) && (iVar3 != 0x5042)) && (iVar3 != 0x5043)) &&
            ((iVar3 != 0x5044 && (iVar3 != 0x5045)))) && (iVar3 != 0x5046)) &&
          (((iVar3 != 0x5047 && (iVar3 != 0x5048)) &&
           ((iVar3 != 0x5049 && (((iVar3 != 0x504a && (iVar3 != 0x504b)) && (iVar3 != 0x504c))))))))
         && (((iVar3 != 0x504d && (iVar3 != 0x504e)) &&
             ((iVar3 != 0x504f &&
              (((iVar3 != 0x5050 && (iVar3 != 0x5051)) &&
               ((iVar3 != 0x5052 && (((iVar3 != 0x5053 && (iVar3 != 0x5054)) && (iVar3 != 0x5055))))
               )))))))) && ((iVar3 != 0x5056 && (iVar3 != 0x5057)))) &&
       ((iVar3 != 0x5058 &&
        ((((iVar3 != 0x5245 && (iVar3 != 0x5246)) &&
          ((iVar3 != 0x534b &&
           ((((iVar3 != 0x534c && (iVar3 != 0x534d)) && (iVar3 != 0x524b)) &&
            ((iVar3 != 0x524c && (iVar3 != 0x5345)))))))) &&
         ((iVar3 != 0x5346 && (iVar3 != 0x5347)))))))) {
      if ((((iVar3 != 0x4c4d) && (iVar3 != 0x4c52)) &&
          ((iVar3 != 0x4c42 && (((iVar3 != 0x4c49 && (iVar3 != 0x4c50)) && (iVar3 != 0x4c47)))))) &&
         (((((iVar3 != 0x474d && (iVar3 != 0x474f)) && (iVar3 != 0x4752)) &&
           ((iVar3 != 0x474e && (iVar3 != 0x4742)))) &&
          (((((iVar3 != 0x4744 && (((iVar3 != 0x4749 && (iVar3 != 0x4750)) && (iVar3 != 0x4757))))
             && ((iVar3 != 0x4759 && (iVar3 != 0x475a)))) && (iVar3 != 0x4756)) &&
           (((iVar3 != 0x5656 && (iVar3 != 0x4755)) && (iVar3 != 0x4754)))))))) goto LAB_100081e2;
      *(undefined4 *)(param_1 + 0x9f0) = 1;
      *(undefined4 *)(param_1 + 0x9e4) = 1;
    }
    *(undefined4 *)(param_1 + 0x9ec) = 1;
    uVar4 = uVar4 & 0xffffff7f;
    *(undefined4 *)(param_1 + 0x918) = 1;
    *(undefined4 *)(param_1 + 0x91c) = 1;
  }
LAB_100081e2:
  if (*(int *)(iVar1 + 0x408) == 0x121a) {
    iVar3 = *(int *)(iVar1 + 0x40c);
    uVar5 = uVar4 & 0xfffffff7;
    if (iVar3 == 5) {
      uVar5 = uVar4 & 0xffffffd7;
    }
    if ((iVar3 == 2) || (iVar3 == 1)) {
      *(undefined4 *)(param_1 + 0x9ec) = 1;
      uVar5 = uVar5 & 0xffff3fff;
    }
    if (*(int *)(iVar1 + 0x40c) == 3) {
      *(undefined4 *)(param_1 + 0x9f0) = 1;
      *(undefined4 *)(param_1 + 0x9ec) = 1;
      *(undefined4 *)(param_1 + 0x9e4) = 1;
      uVar5 = uVar5 & 0xffff7fff;
    }
    uVar4 = uVar5 & 0xfffffbff | 0x200;
  }
  if ((*(int *)(iVar1 + 0x408) == 0x8086) && (*(int *)(iVar1 + 0x40c) == 0x7123)) {
    uVar4 = uVar4 & 0xffffbfff;
    *(undefined4 *)(param_1 + 0x91c) = 1;
  }
  if ((*(int *)(iVar1 + 0x408) == 0x1163) && (*(int *)(iVar1 + 0x40c) == 0x2000)) {
    uVar4 = uVar4 & 0xffffbfff;
    *(undefined4 *)(param_1 + 0x9ec) = 1;
    *(undefined4 *)(param_1 + 0x91c) = 1;
    *(undefined4 *)(param_1 + 0x9e4) = 1;
  }
  *(uint *)(param_1 + 0x9dc) = uVar4;
  return;
}



/* ===== FUN_100082a0 @ 0x100082A0 ===== */

undefined4 __cdecl FUN_100082a0(int param_1)

{
  FUN_100085d0(param_1);
  (*DAT_10024758)(*(undefined4 *)(param_1 + 0x980));
  *(undefined4 *)(param_1 + 0x980) = 0;
  if (*(undefined4 **)(param_1 + 0x914) != (undefined4 *)0x0) {
    FUN_100101ee((undefined *)**(undefined4 **)(param_1 + 0x914));
    FUN_100101ee(*(undefined **)(*(int *)(param_1 + 0x914) + 4));
    FUN_1000cde0(param_1,*(int *)(param_1 + 0x914));
    FUN_100101ee(*(undefined **)(param_1 + 0x914));
  }
  return 1;
}



/* ===== FUN_10008310 @ 0x10008310 ===== */

void __cdecl FUN_10008310(int param_1,int param_2)

{
  char cVar1;
  undefined4 *puVar2;
  char *pcVar3;
  int iVar4;
  char *pcVar5;
  uint uVar6;
  float fStack_a8;
  int local_a4;
  char acStack_a0 [160];
  
  local_a4 = 0;
  pcVar3 = (char *)(*DAT_10024738)(s_RestoreTextures_1001e5c0);
  pcVar5 = acStack_a0;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
    *pcVar5 = cVar1;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  if (param_2 != 0) {
    puVar2 = *(undefined4 **)(param_1 + 0x978);
    uVar6 = (puVar2 == (undefined4 *)(param_1 + 0x978U)) - 1 & (uint)puVar2;
    local_a4 = 0;
    puVar2 = (undefined4 *)*puVar2;
    while (uVar6 != 0) {
      if (*(int *)(uVar6 + 8) != 0) {
        local_a4 = local_a4 + 1;
      }
      uVar6 = (puVar2 == (undefined4 *)(param_1 + 0x978U)) - 1 & (uint)puVar2;
      puVar2 = (undefined4 *)*puVar2;
    }
  }
  puVar2 = *(undefined4 **)(param_1 + 0x978);
  fStack_a8 = 0.0;
  uVar6 = (puVar2 == (undefined4 *)(param_1 + 0x978U)) - 1 & (uint)puVar2;
  puVar2 = (undefined4 *)*puVar2;
  do {
    if (uVar6 == 0) {
      return;
    }
    if (*(int *)(uVar6 + 8) != 0) {
      if (param_2 != 0) {
        fStack_a8 = 40.0 / (float)local_a4 + fStack_a8;
        while (1.0 < fStack_a8) {
          fStack_a8 = fStack_a8 - 1.0;
          iVar4 = -1;
          pcVar5 = acStack_a0;
          do {
            pcVar3 = pcVar5;
            if (iVar4 == 0) break;
            iVar4 = iVar4 + -1;
            pcVar3 = pcVar5 + 1;
            cVar1 = *pcVar5;
            pcVar5 = pcVar3;
          } while (cVar1 != '\0');
          *(undefined2 *)(pcVar3 + -1) = DAT_1001e5bc;
        }
        (**(code **)(param_1 + 0x98))(param_1,0);
        (**(code **)(param_1 + 0x90))(param_1);
        FUN_1000cee0();
        (**(code **)(param_1 + 0x94))(param_1);
        (**(code **)(param_1 + 0xa8))(param_1);
      }
      *(undefined1 *)(*(int *)(uVar6 + 8) + 0x1d) = 0;
      (**(code **)(param_1 + 0xb0))(param_1,*(undefined4 *)(uVar6 + 8));
    }
    uVar6 = (puVar2 == (undefined4 *)(param_1 + 0x978)) - 1 & (uint)puVar2;
    puVar2 = (undefined4 *)*puVar2;
  } while( true );
}



/* ===== FUN_100084e0 @ 0x100084E0 ===== */

undefined4 __cdecl FUN_100084e0(int param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(**(int **)(param_1 + 0x850) + 0xc))(*(int **)(param_1 + 0x850));
  if (iVar1 < 0) {
    if (iVar1 == -0x7789f798) {
      return 0;
    }
    if (iVar1 == -0x7789f797) {
      iVar1 = *(int *)(param_1 + 0x83c);
      if (*(int *)(iVar1 + 0x2a384) != 0) {
        (**(code **)(**(int **)(iVar1 + 0x2a3d4) + 0x20))
                  (*(int **)(iVar1 + 0x2a3d4),*(undefined4 *)(iVar1 + 0x2a380),
                   *(int *)(param_1 + 0x840) + 0x42c);
        *(undefined4 *)(*(int *)(param_1 + 0x83c) + 0x2a3a0) =
             *(undefined4 *)(*(int *)(param_1 + 0x840) + 0x438);
      }
      iVar1 = FUN_100086b0(param_1);
      if (iVar1 != 0) {
        return 0;
      }
      iVar1 = FUN_10008780(param_1,(uint *)(param_1 + 0x7fc),(uint *)(param_1 + 0x80c));
      if (iVar1 != 0) {
        return 0;
      }
      return 3;
    }
  }
  else if (param_1 == 0) {
    return 2;
  }
  return 1;
}



/* ===== FUN_100085d0 @ 0x100085D0 ===== */

void __cdecl FUN_100085d0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  
  iVar1 = *(int *)(param_1 + 0x81c);
  *(undefined4 *)(param_1 + 0x81c) = 0;
  if (iVar1 != 0) {
    puVar2 = *(undefined4 **)(param_1 + 0x978);
    piVar3 = (int *)((puVar2 == (undefined4 *)(param_1 + 0x978U)) - 1 & (uint)puVar2);
    puVar2 = (undefined4 *)*puVar2;
    while (piVar3 != (int *)0x0) {
      FUN_1000cd50(param_1,piVar3);
      piVar3 = (int *)((puVar2 == (undefined4 *)(param_1 + 0x978U)) - 1 & (uint)puVar2);
      puVar2 = (undefined4 *)*puVar2;
    }
  }
  FUN_10006a40(param_1);
  FUN_10002560(param_1);
  FUN_1000ce90();
  piVar3 = *(int **)(param_1 + 0x7e0);
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 8))(piVar3);
    *(undefined4 *)(param_1 + 0x7e0) = 0;
  }
  if (*(int *)(param_1 + 0x83c) != 0) {
    piVar3 = *(int **)(*(int *)(param_1 + 0x83c) + 0x2a3d8);
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 8))(piVar3);
      piVar3 = *(int **)(*(int *)(param_1 + 0x83c) + 0x2a3d4);
      (**(code **)(*piVar3 + 8))(piVar3);
      *(undefined4 *)(*(int *)(param_1 + 0x83c) + 0x2a3d8) = 0;
      *(undefined4 *)(*(int *)(param_1 + 0x83c) + 0x2a3d4) = 0;
    }
    FUN_1000fe9b(*(undefined **)(param_1 + 0x83c));
    *(undefined4 *)(param_1 + 0x83c) = 0;
  }
  return;
}



/* ===== FUN_100086b0 @ 0x100086B0 ===== */

undefined4 __cdecl FUN_100086b0(int param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  
  if (*(int *)(*(int *)(param_1 + 0x83c) + 0x2a3d8) != 0) {
    puVar1 = *(undefined4 **)(param_1 + 0x978);
    uVar3 = (puVar1 == (undefined4 *)(param_1 + 0x978U)) - 1 & (uint)puVar1;
    puVar1 = (undefined4 *)*puVar1;
    while (uVar3 != 0) {
      FUN_1000cd10(param_1,uVar3);
      uVar3 = (puVar1 == (undefined4 *)(param_1 + 0x978U)) - 1 & (uint)puVar1;
      puVar1 = (undefined4 *)*puVar1;
    }
    iVar4 = 0;
    do {
      (**(code **)(**(int **)(param_1 + 0x850) + 0xf4))(*(int **)(param_1 + 0x850),iVar4,0);
      iVar4 = iVar4 + 1;
    } while (iVar4 < 4);
    FUN_10006a40(param_1);
    FUN_10002560(param_1);
    FUN_1000ce90();
    piVar2 = *(int **)(param_1 + 0x7e0);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 8))(piVar2);
      *(undefined4 *)(param_1 + 0x7e0) = 0;
    }
    piVar2 = *(int **)(*(int *)(param_1 + 0x83c) + 0x2a3d8);
    (**(code **)(*piVar2 + 8))(piVar2);
    *(undefined4 *)(*(int *)(param_1 + 0x83c) + 0x2a3d8) = 0;
    *(undefined4 *)(param_1 + 0x850) = 0;
  }
  return 0;
}



/* ===== FUN_10008780 @ 0x10008780 ===== */

int __cdecl FUN_10008780(int param_1,uint *param_2,uint *param_3)

{
  int iVar1;
  
  iVar1 = 0;
  if (*(int *)(*(int *)(param_1 + 0x83c) + 0x2a3d4) != 0) {
    if (*(int *)(param_1 + 0x898) != 0) {
      SetWindowPos(*(HWND *)(param_1 + 0x824),(HWND)0xffffffff,*(int *)(param_1 + 0x828),
                   *(int *)(param_1 + 0x82c),*(int *)(param_1 + 0x830) - *(int *)(param_1 + 0x828),
                   *(int *)(param_1 + 0x834) - *(int *)(param_1 + 0x82c),0x40);
    }
    iVar1 = FUN_10007540(param_1,*(undefined4 *)(param_1 + 0x824),param_2,param_3);
    if (iVar1 < 0) {
      FUN_1000eb70(*(void **)(param_1 + 0x83c),-0x7dfffff4,1);
      SendMessageA(*(HWND *)(param_1 + 0x824),0x10,0,0);
      return iVar1;
    }
    FUN_100025e0(param_1);
    FUN_10008310(param_1,1);
    FUN_100092e0(param_1);
    (**(code **)(param_1 + 0x14))(param_1);
  }
  return iVar1;
}



/* ===== FUN_100092e0 @ 0x100092E0 ===== */

void __cdecl FUN_100092e0(int param_1)

{
  int iVar1;
  int *piStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  int *piStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  int *piStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  int *piStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  int *piStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  
  piStack_28 = *(int **)(param_1 + 0x850);
  uStack_20 = 1;
  uStack_24 = 0x1a;
  *(undefined4 *)(param_1 + 0xa1c) = 1;
  *(undefined4 *)(param_1 + 0xa20) = 1;
  *(undefined4 *)(param_1 + 0xa24) = 1;
  *(undefined4 *)(param_1 + 0xa34) = 0;
  *(undefined4 *)(param_1 + 0xa28) = 1;
  *(undefined4 *)(param_1 + 0xa2c) = 1;
  *(undefined4 *)(param_1 + 0xa30) = 1;
  uStack_2c = 0x1000932f;
  (**(code **)(*piStack_28 + 200))();
  piStack_34 = *(int **)(param_1 + 0x850);
  uStack_2c = 0;
  uStack_30 = 0x1d;
  uStack_38 = 0x10009342;
  (**(code **)(*piStack_34 + 200))();
  piStack_40 = *(int **)(param_1 + 0x850);
  uStack_38 = 0;
  uStack_3c = 0x8b;
  uStack_44 = 0x10009358;
  (**(code **)(*piStack_40 + 200))();
  piStack_4c = *(int **)(param_1 + 0x850);
  uStack_44 = 0;
  uStack_48 = 0x89;
  uStack_50 = 0x1000936e;
  (**(code **)(*piStack_4c + 200))();
  piStack_58 = *(int **)(param_1 + 0x850);
  uStack_50 = 1;
  uStack_54 = 0x8f;
  (**(code **)(*piStack_58 + 200))();
  (**(code **)(**(int **)(param_1 + 0x850) + 200))(*(int **)(param_1 + 0x850),0x92,0);
  if ((*(byte *)(*(int *)(param_1 + 0x83c) + 0x2a410) & 0x40) != 0) {
    (**(code **)(**(int **)(param_1 + 0x850) + 200))(*(int **)(param_1 + 0x850),0x18,1);
    (**(code **)(**(int **)(param_1 + 0x850) + 200))(*(int **)(param_1 + 0x850),0xf,0);
    (**(code **)(**(int **)(param_1 + 0x850) + 200))(*(int **)(param_1 + 0x850),0x19,7);
  }
  iVar1 = 4;
  do {
    (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))(*(int **)(param_1 + 0x850),0,1,1);
    (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))(*(int **)(param_1 + 0x850),1,4,1);
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  piStack_58 = (int *)0x0;
  uStack_54 = 0x3f800000;
  uStack_50 = 0x3f000000;
  piStack_4c = (int *)0x3e800000;
  (**(code **)(**(int **)(param_1 + 0x850) + 0x13c))(*(int **)(param_1 + 0x850),0x1b,&piStack_58,1);
  return;
}



/* ===== FUN_100096c0 @ 0x100096C0 ===== */

void __cdecl FUN_100096c0(int param_1,int param_2,int param_3)

{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  
  uVar3 = 0;
  if ((param_2 == 0) && (*(int *)(param_1 + 0x918) != 0)) {
    param_2 = param_1 + 0x920;
  }
  if (*(int *)(param_1 + 0x904 + param_3 * 4) == param_2) {
    return;
  }
  *(int *)(param_1 + 0x904 + param_3 * 4) = param_2;
  if (param_2 != 0) {
    uVar1 = *(ushort *)(param_2 + 0x1e);
    if (-1 < (short)uVar1) {
      (**(code **)(param_1 + 0xb0))(param_1,param_2);
      uVar1 = *(ushort *)(param_2 + 0x1e);
      if (-1 < (short)uVar1) {
        uVar3 = 0;
        goto LAB_100097b3;
      }
    }
    uVar3 = *(undefined4 *)(*(int *)(param_2 + 8) + 0xc);
    piVar4 = *(int **)(param_1 + 0x850);
    if ((uVar1 & 0x100) == 0) {
      (**(code **)(*piVar4 + 0xfc))(piVar4,param_3,0x12,0);
      if (*(int *)(param_1 + 0x8a4) == 0) goto LAB_100097b3;
      piVar4 = *(int **)(param_1 + 0x850);
      iVar2 = *piVar4;
      iVar5 = 1;
    }
    else {
      (**(code **)(*piVar4 + 0xfc))(piVar4,param_3,0x13,*(undefined4 *)(param_1 + 0x9b4));
      (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))
                (*(int **)(param_1 + 0x850),param_3,0x12,*(undefined4 *)(param_1 + 0x8b0));
      iVar5 = *(int *)(param_1 + 0x8a4);
      if (iVar5 == 0) goto LAB_100097b3;
      piVar4 = *(int **)(param_1 + 0x850);
      iVar2 = *piVar4;
    }
    (**(code **)(iVar2 + 0xfc))(piVar4,param_3,0x15,iVar5);
  }
LAB_100097b3:
  (**(code **)(**(int **)(param_1 + 0x850) + 0xf4))(*(int **)(param_1 + 0x850),param_3,uVar3);
  return;
}



/* ===== FUN_100097d0 @ 0x100097D0 ===== */

undefined4 __cdecl FUN_100097d0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (**(code **)(**(int **)(param_1 + 0x850) + 0x88))(*(int **)(param_1 + 0x850));
  if (iVar1 == 0) {
    if (*(int *)(param_1 + 0xa2c) == 0) {
      uVar2 = 1;
    }
    else {
      uVar2 = *(undefined4 *)(param_1 + 0x8a8);
    }
    (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))(*(int **)(param_1 + 0x850),0,0x11,uVar2);
    if (*(int *)(param_1 + 0xa2c) == 0) {
      uVar2 = 1;
    }
    else {
      uVar2 = *(undefined4 *)(param_1 + 0x8ac);
    }
    (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))(*(int **)(param_1 + 0x850),0,0x10,uVar2);
    if (*(int *)(param_1 + 0xa2c) == 0) {
      uVar2 = 1;
    }
    else {
      uVar2 = *(undefined4 *)(param_1 + 0x8a8);
    }
    (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))(*(int **)(param_1 + 0x850),1,0x11,uVar2);
    if (*(int *)(param_1 + 0xa2c) == 0) {
      uVar2 = 1;
    }
    else {
      uVar2 = *(undefined4 *)(param_1 + 0x8ac);
    }
    (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))(*(int **)(param_1 + 0x850),1,0x10,uVar2);
    if (*(int *)(param_1 + 0xa2c) == 0) {
      uVar2 = 1;
    }
    else {
      uVar2 = *(undefined4 *)(param_1 + 0x8a8);
    }
    (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))(*(int **)(param_1 + 0x850),2,0x11,uVar2);
    if (*(int *)(param_1 + 0xa2c) == 0) {
      uVar2 = 1;
    }
    else {
      uVar2 = *(undefined4 *)(param_1 + 0x8ac);
    }
    (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))(*(int **)(param_1 + 0x850),2,0x10,uVar2);
    if (*(int *)(param_1 + 0xa2c) == 0) {
      uVar2 = 1;
    }
    else {
      uVar2 = *(undefined4 *)(param_1 + 0x8a8);
    }
    (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))(*(int **)(param_1 + 0x850),3,0x11,uVar2);
    if (*(int *)(param_1 + 0xa2c) == 0) {
      uVar2 = 1;
    }
    else {
      uVar2 = *(undefined4 *)(param_1 + 0x8ac);
    }
    (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))(*(int **)(param_1 + 0x850),3,0x10,uVar2);
    (**(code **)(**(int **)(param_1 + 0x850) + 200))
              (*(int **)(param_1 + 0x850),8,3 - (uint)(*(int *)(param_1 + 0xa34) != 0));
    *(undefined4 *)(param_1 + 0x9a8) = 1;
    return 1;
  }
  (*DAT_1002471c)(iVar1);
  return 0;
}



/* ===== FUN_10009990 @ 0x10009990 ===== */

undefined4 __cdecl FUN_10009990(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x9a8) != 0) {
    iVar1 = (**(code **)(**(int **)(param_1 + 0x850) + 0x8c))(*(int **)(param_1 + 0x850));
    if (iVar1 != 0) {
      (*DAT_1002471c)(iVar1);
      return 0;
    }
    *(undefined4 *)(param_1 + 0x9a8) = 0;
  }
  return 1;
}



/* ===== FUN_10009c70 @ 0x10009C70 ===== */

void __cdecl FUN_10009c70(int param_1,int param_2)

{
  bool bVar1;
  float fVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  float *pfVar7;
  float *pfVar8;
  undefined1 *puStack_16c;
  float fStack_168;
  int *piStack_164;
  undefined4 uStack_160;
  undefined1 *puStack_15c;
  undefined4 uStack_158;
  int *piStack_154;
  undefined4 uStack_150;
  int *piVar9;
  float local_94;
  float fStack_84;
  uint local_7c;
  uint local_48;
  float afStack_44 [4];
  undefined4 uStack_34;
  undefined4 uStack_2c;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 local_4;
  
  local_7c = *(uint *)(param_2 + 0x10);
  local_94 = *(float *)(param_2 + 0xc);
  *(int *)(param_1 + 0x9a4) = *(int *)(param_1 + 0x9a4) + 1;
  if (*(int *)(param_1 + 0xa28) == 0) {
    local_94 = (float)((uint)local_94 & 0xfffffff3);
  }
  if (*(int *)(param_1 + 0xa20) == 0) {
    local_94 = (float)((uint)local_94 & 0xfffff0ff);
  }
  local_48 = (uint)local_94 & 0xf00;
  uVar6 = (uint)local_94 & 0xf000;
  if (local_48 == 0x600) {
    local_48 = 0x100;
LAB_10009cff:
    local_94 = (float)((uint)local_94 | 0x50000);
  }
  else if (local_48 == 0x700) {
    local_48 = 0x300;
    goto LAB_10009cff;
  }
  if ((-1 < SUB41(local_94,0)) && (((uint)local_94 & 0x20000) == 0)) {
    local_94 = (float)((uint)local_94 | 0x20000);
    local_7c = local_7c & 0xff000000;
  }
  *(undefined4 *)(param_1 + 0x9e8) = 0;
  if ((*(int *)(param_1 + 0x9ec) != 0) && (((uint)local_94 & 0x40000) != 0)) {
    *(uint *)(param_1 + 0x9f4) = local_7c;
    *(float *)(param_1 + 0x9f8) = local_94;
    local_94 = (float)((uint)local_94 & 0xfffbffff | 0x10000);
    *(undefined4 *)(param_1 + 0x9e8) = 1;
  }
  if ((*(int *)(param_1 + 0x9f0) != 0) && (((uint)local_94 & 0x20000) != 0)) {
    if (*(int *)(param_1 + 0x9e8) == 0) {
      *(uint *)(param_1 + 0x9f4) = local_7c;
      *(float *)(param_1 + 0x9f8) = local_94;
      *(undefined4 *)(param_1 + 0x9e8) = 1;
    }
    local_94 = (float)((uint)local_94 & 0xfffdffff);
  }
  local_4 = *(undefined4 *)(param_1 + 0x7d8);
  *(undefined4 *)(param_1 + 0x7dc) = 0;
  *(undefined4 *)(param_1 + 0x7d8) = 0;
  if (((*(int *)(param_1 + 0xa10) != 0) && (((uint)local_94 & 0x80000) != 0)) &&
     (*(int *)(param_1 + 0x7b8) != 0)) {
    if (*(int *)(param_1 + 0x110) != 0) {
      (**(code **)(**(int **)(param_1 + 0x850) + 0x13c))();
    }
    FUN_100096c0(param_1,*(int *)(param_1 + 0x110),1);
    FUN_100096c0(param_1,*(int *)(param_1 + 0x110),2);
    FUN_100096c0(param_1,*(int *)(param_1 + 0x110),3);
    *(undefined4 *)(param_1 + 0x7d8) = *(undefined4 *)(param_1 + 0x7b8);
    *(undefined4 *)(param_1 + 0x7dc) = *(undefined4 *)(param_1 + 0x7cc);
  }
  if (((uint)local_94 & 0xc) == 0) {
    FUN_100096c0(param_1,0,0);
    goto LAB_1000af5e;
  }
  if (uVar6 == 0x7000) {
    (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))();
    piVar9 = *(int **)(param_1 + 0x850);
    (**(code **)(*piVar9 + 0xfc))();
    (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))();
    if (((uint)piVar9 & 8) == 0) {
      (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))();
      (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))();
      (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))();
    }
    else {
      (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))();
      (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))();
      (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))();
    }
    (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))();
    (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))();
    (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))();
    FUN_100096c0(param_1,*(int *)(param_2 + 4),0);
    uStack_150 = 0x1000a064;
    FUN_100096c0(param_1,*(int *)(param_2 + 8),1);
    (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))();
    piStack_154 = *(int **)(param_1 + 0x850);
    uStack_150 = 1;
    uStack_158 = 0x1000a094;
    (**(code **)(*piStack_154 + 0xfc))();
    if (*(char *)(param_1 + 0x420) < '\0') {
      pfVar7 = (float *)(param_1 + 0x194);
      pfVar8 = afStack_44;
      for (iVar5 = 0x10; uVar4 = uStack_2c, uVar3 = uStack_34, fVar2 = afStack_44[2], iVar5 != 0;
          iVar5 = iVar5 + -1) {
        *pfVar8 = *pfVar7;
        pfVar7 = pfVar7 + 1;
        pfVar8 = pfVar8 + 1;
      }
      uStack_34 = afStack_44[1];
      afStack_44[2] = (float)uStack_24;
      uStack_24 = fVar2;
      uStack_2c = uStack_20;
      uStack_20 = uVar4;
      uStack_c = 0;
      uStack_10 = 0;
      uStack_14 = 0;
      afStack_44[1] = (float)uVar3;
      (**(code **)(**(int **)(param_1 + 0x850) + 0x94))();
      *(uint *)(param_1 + 0x420) = *(uint *)(param_1 + 0x420) & 0xffffff7f;
    }
  }
  else if (uVar6 == 0x6000) {
    if (*(int *)(param_1 + 0x8d0) == 0) {
      FUN_100096c0(param_1,*(int *)(param_2 + 4),0);
      FUN_100096c0(param_1,*(int *)(param_2 + 8),1);
      (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))();
      (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))();
      (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))();
      (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))();
      (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))();
      (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))();
      (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))();
      (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))();
      (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))();
      (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))();
      piStack_154 = *(int **)(param_1 + 0x850);
      uStack_150 = 1;
      uStack_158 = 0x1000a4c7;
      (**(code **)(*piStack_154 + 0xfc))();
      piStack_164 = *(int **)(param_1 + 0x850);
      uStack_158 = 2;
      puStack_15c = (undefined1 *)0x4;
      uStack_160 = 0;
      fStack_168 = 2.5370552e-29;
      (**(code **)(*piStack_164 + 0xfc))();
      fStack_168 = 1.4013e-45;
      puStack_16c = (undefined1 *)0x5;
      (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))();
      (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))(*(int **)(param_1 + 0x850),0);
      (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))(*(int **)(param_1 + 0x850),1,4,2);
      (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))(*(int **)(param_1 + 0x850),1,5,1);
      (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))(*(int **)(param_1 + 0x850),1,6,1);
      if ((*(int *)(param_1 + 0xa10) != 0) && (*(int *)(param_1 + 0x7b4) != 0)) {
        FUN_10001220(afStack_44,(float *)(param_1 + 0x154));
        (**(code **)(**(int **)(param_1 + 0x850) + 0x13c))();
        local_94 = *(float *)(param_1 + 0x7a4) + *(float *)(param_1 + 0x784);
        (**(code **)(**(int **)(param_1 + 0x850) + 0x13c))();
        (**(code **)(**(int **)(param_1 + 0x850) + 0x13c))();
        (**(code **)(**(int **)(param_1 + 0x850) + 0x16c))();
        (**(code **)(**(int **)(param_1 + 0x850) + 0x13c))();
        (**(code **)(**(int **)(param_1 + 0x850) + 0x13c))();
        (**(code **)(**(int **)(param_1 + 0x850) + 0x13c))();
        (**(code **)(**(int **)(param_1 + 0x850) + 0x13c))();
        (**(code **)(**(int **)(param_1 + 0x850) + 0x13c))();
        (**(code **)(**(int **)(param_1 + 0x850) + 0x13c))();
        piStack_154 = *(int **)(param_1 + 0x850);
        uStack_150 = 0x23;
        uStack_158 = 0x1000a8bd;
        (**(code **)(*piStack_154 + 0x13c))();
        piStack_164 = *(int **)(param_1 + 0x850);
        uStack_158 = 1;
        puStack_15c = &stack0xfffffec4;
        uStack_160 = 0x24;
        fStack_168 = 2.5373757e-29;
        (**(code **)(*piStack_164 + 0x13c))();
        fStack_168 = 1.4013e-45;
        puStack_16c = &stack0xfffffec8;
        (**(code **)(**(int **)(param_1 + 0x850) + 0x13c))();
        piStack_154 = *(int **)(param_1 + 0x508);
        puStack_15c = *(undefined1 **)(param_1 + 0x500);
        uStack_158 = *(undefined4 *)(param_1 + 0x504);
        (**(code **)(**(int **)(param_1 + 0x850) + 0x13c))(*(int **)(param_1 + 0x850),0x26);
        puStack_16c = (undefined1 *)(*(float *)(param_1 + 0x510) * *(float *)(param_1 + 0x78c));
        fStack_168 = *(float *)(param_1 + 0x514) * *(float *)(param_1 + 0x790);
        piStack_164 = (int *)(*(float *)(param_1 + 0x518) * *(float *)(param_1 + 0x794));
        (**(code **)(**(int **)(param_1 + 0x850) + 0x13c))
                  (*(int **)(param_1 + 0x850),0x27,&puStack_16c,1);
        (**(code **)(**(int **)(param_1 + 0x850) + 0x13c))
                  (*(int **)(param_1 + 0x850),0x28,&stack0xfffffe84,1);
        *(undefined4 *)(param_1 + 0x7d8) = *(undefined4 *)(param_1 + 0x7b4);
        *(undefined4 *)(param_1 + 0x7dc) = *(undefined4 *)(param_1 + 0x7c8);
      }
    }
    else {
      FUN_100096c0(param_1,*(int *)(param_2 + 8),0);
      (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))();
      (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))();
      (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))();
      (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))();
      FUN_100096c0(param_1,*(int *)(param_2 + 4),1);
      (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))();
      (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))();
      (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))();
      (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))();
      (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))();
      (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))();
      piStack_154 = *(int **)(param_1 + 0x850);
      uStack_150 = 1;
      uStack_158 = 0x1000a26f;
      (**(code **)(*piStack_154 + 0xfc))();
      piStack_164 = *(int **)(param_1 + 0x850);
      uStack_158 = 0;
      puStack_15c = (undefined1 *)0x9;
      uStack_160 = 1;
      fStack_168 = 2.536878e-29;
      (**(code **)(*piStack_164 + 0xfc))();
      uStack_150 = 0x40000000;
      fStack_168 = 2.0;
      puStack_16c = (undefined1 *)0xa;
      (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))();
      FUN_100096c0(param_1,*(int *)(param_1 + 0x914),2);
      (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))(*(int **)(param_1 + 0x850),2);
      (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))(*(int **)(param_1 + 0x850),2,0xe,3);
      (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))(*(int **)(param_1 + 0x850),2,0xb,0);
      (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))(*(int **)(param_1 + 0x850),2,1,5);
      (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))(*(int **)(param_1 + 0x850),2,2,2);
      (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))(*(int **)(param_1 + 0x850),2,3,1);
      (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))(*(int **)(param_1 + 0x850),0,4,2);
      (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))(*(int **)(param_1 + 0x850),0,5,1);
      (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))(*(int **)(param_1 + 0x850),0,6,1);
      (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))(*(int **)(param_1 + 0x850),1,4,2);
      (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))(*(int **)(param_1 + 0x850),1,5,1);
      (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))(*(int **)(param_1 + 0x850),1,6,1);
    }
  }
  else if (uVar6 == 0x8000) {
    if (*(int *)(param_1 + 0x8d0) == 0) {
      FUN_100096c0(param_1,*(int *)(param_2 + 4),0);
      FUN_100096c0(param_1,*(int *)(param_2 + 8),1);
      if ((*(int *)(param_1 + 0xa10) == 0) || (*(int *)(param_1 + 0x7c4) == 0)) {
        (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))();
        (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))();
        (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))();
        (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))();
        (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))();
        (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))();
        (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))();
        (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))();
        (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))();
      }
      else {
        FUN_100096c0(param_1,param_1 + 0x940,2);
        FUN_100096c0(param_1,*(int *)(param_2 + 0x14),3);
        *(undefined4 *)(param_1 + 0x7dc) = *(undefined4 *)(param_1 + 0x7c4);
        (**(code **)(**(int **)(param_1 + 0x850) + 0x13c))();
        (**(code **)(**(int **)(param_1 + 0x850) + 0x13c))();
        local_94 = 0.0;
        (**(code **)(**(int **)(param_1 + 0x850) + 0x16c))();
      }
      if ((*(int *)(param_1 + 0xa10) != 0) && (*(int *)(param_1 + 0x7b0) != 0)) {
        *(int *)(param_1 + 0x7d8) = *(int *)(param_1 + 0x7b0);
      }
    }
  }
  else if (uVar6 == 0x9000) {
    FUN_100096c0(param_1,*(int *)(param_2 + 4),0);
    if ((*(int *)(param_1 + 0xa10) == 0) || (*(int *)(param_1 + 0x7bc) == 0)) {
      (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))();
      goto LAB_1000af5e;
    }
    *(int *)(param_1 + 0x7d8) = *(int *)(param_1 + 0x7bc);
    *(undefined4 *)(param_1 + 0x7dc) = *(undefined4 *)(param_1 + 2000);
  }
  else if (uVar6 == 0x2000) {
    FUN_100096c0(param_1,*(int *)(param_2 + 4),0);
    (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))();
    (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))();
    (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))();
  }
  else {
    if (uVar6 == 0x3000) {
      FUN_100096c0(param_1,*(int *)(param_2 + 4),0);
      (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))();
LAB_1000af5e:
      (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))();
    }
    else {
      if (uVar6 == 0x4000) {
        FUN_100096c0(param_1,*(int *)(param_2 + 4),0);
        (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))();
        goto LAB_1000af5e;
      }
      if (uVar6 == 0x5000) {
        FUN_100096c0(param_1,*(int *)(param_2 + 4),0);
        (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))();
        goto LAB_1000af5e;
      }
      if (uVar6 == 0x1000) {
        FUN_100096c0(param_1,*(int *)(param_2 + 4),0);
        (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))();
        goto LAB_1000af5e;
      }
      if (uVar6 == 0xa000) {
        FUN_100096c0(param_1,*(int *)(param_2 + 4),0);
        FUN_100096c0(param_1,*(int *)(param_2 + 8),1);
        *(undefined4 *)(param_1 + 0x7dc) = *(undefined4 *)(param_1 + 0x7d4);
        *(undefined4 *)(param_1 + 0x7d8) = *(undefined4 *)(param_1 + 0x7c0);
        (**(code **)(**(int **)(param_1 + 0x850) + 0x13c))();
        fStack_84 = ((*(float *)(param_1 + 0x1b0) -
                     *(float *)(param_1 + 0x1ac) * *(float *)(param_1 + 0x1cc)) -
                    *(float *)(param_1 + 0x1a8) * *(float *)(param_1 + 0x1c8)) -
                    *(float *)(param_1 + 0x1a4) * *(float *)(param_1 + 0x1c4);
        (**(code **)(**(int **)(param_1 + 0x850) + 0x13c))();
        goto LAB_1000af83;
      }
      FUN_100096c0(param_1,*(int *)(param_2 + 4),0);
      (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))();
      (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))();
    }
    (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))();
  }
LAB_1000af83:
  bVar1 = true;
  if (local_48 == 0) {
    (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))();
  }
  else {
    if (((uint)local_94 & 8) != 0) {
      piVar9 = *(int **)(param_1 + 0x850);
      if (((uint)local_94 & 0x10000) == 0) {
        if (((uint)local_94 & 0x40000) == 0) {
          (**(code **)(*piVar9 + 0xfc))();
          (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))();
        }
        else {
          (**(code **)(*piVar9 + 0xfc))();
          (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))();
          (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))();
        }
      }
      else {
        (**(code **)(*piVar9 + 0xfc))();
        (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))();
        (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))();
      }
      goto LAB_1000b121;
    }
    if ((((uint)local_94 & 0x10000) != 0) && (((uint)local_94 & 0x40000) != 0)) {
      (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))();
      (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))();
      (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))();
      goto LAB_1000b121;
    }
    if (((uint)local_94 & 0x10000) != 0) {
      (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))();
      (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))();
      goto LAB_1000b121;
    }
    iVar5 = **(int **)(param_1 + 0x850);
    if (((uint)local_94 & 0x40000) != 0) {
      (**(code **)(iVar5 + 0xfc))();
      (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))();
      goto LAB_1000b121;
    }
    (**(code **)(iVar5 + 0xfc))();
  }
  bVar1 = false;
LAB_1000b121:
  piVar9 = *(int **)(param_1 + 0x850);
  (**(code **)(*piVar9 + 0xfc))();
  (**(code **)(**(int **)(param_1 + 0x850) + 0xfc))();
  if (local_48 == 0x100) {
    if (bVar1) {
      (**(code **)(**(int **)(param_1 + 0x850) + 200))();
    }
    else {
      (**(code **)(**(int **)(param_1 + 0x850) + 200))();
    }
    (**(code **)(**(int **)(param_1 + 0x850) + 200))();
  }
  else if (local_48 == 0x300) {
    if (bVar1) {
      (**(code **)(**(int **)(param_1 + 0x850) + 200))();
    }
    else {
      (**(code **)(**(int **)(param_1 + 0x850) + 200))();
    }
    (**(code **)(**(int **)(param_1 + 0x850) + 200))();
  }
  else if (local_48 == 0x200) {
    (**(code **)(**(int **)(param_1 + 0x850) + 200))();
    (**(code **)(**(int **)(param_1 + 0x850) + 200))();
  }
  else if (local_48 == 0x400) {
    (**(code **)(**(int **)(param_1 + 0x850) + 200))();
    (**(code **)(**(int **)(param_1 + 0x850) + 200))();
  }
  else if (local_48 == 0x500) {
    (**(code **)(**(int **)(param_1 + 0x850) + 200))();
    (**(code **)(**(int **)(param_1 + 0x850) + 200))();
  }
  if (((uint)piVar9 & 0x60000) != 0) {
    (**(code **)(**(int **)(param_1 + 0x850) + 200))();
    (**(code **)(**(int **)(param_1 + 0x850) + 0x16c))();
  }
  (**(code **)(**(int **)(param_1 + 0x850) + 200))();
  (**(code **)(**(int **)(param_1 + 0x850) + 200))();
  (**(code **)(**(int **)(param_1 + 0x850) + 200))();
  if (*(int *)(param_1 + 0x91c) == 0) {
    (**(code **)(**(int **)(param_1 + 0x850) + 200))();
  }
  else {
    (**(code **)(**(int **)(param_1 + 0x850) + 200))();
  }
  if ((*(int *)(param_1 + 0x7d8) == 0) != (fStack_84 == 0.0)) {
    if ((*(int *)(param_1 + 0x7d8) == 0) &&
       ((*(int *)(param_1 + 0x8ec) == 0 || (*(int *)(param_1 + 0x8e4) == 0)))) {
      if (*(int *)(param_1 + 0x8f0) == 0) {
        return;
      }
      (**(code **)(**(int **)(param_1 + 0x850) + 200))();
    }
    else {
      (**(code **)(**(int **)(param_1 + 0x850) + 200))();
    }
    (**(code **)(**(int **)(param_1 + 0x850) + 200))();
  }
  return;
}



/* ===== FUN_1000b450 @ 0x1000B450 ===== */

void __cdecl FUN_1000b450(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  iVar3 = param_1 + 0x978;
  iVar1 = param_1 + 0x970;
  *(int *)iVar1 = iVar1;
  *(int *)(param_1 + 0x974) = iVar1;
  *(int *)iVar3 = iVar3;
  *(int *)(param_1 + 0x97c) = iVar3;
  piVar2 = (int *)(*DAT_10024754)(0x26,0x6000,s_gfx_texbucketmem_1001e75c);
  *(int **)(param_1 + 0x980) = piVar2;
  if (piVar2 != (int *)0x0) {
    iVar3 = 0x400;
    do {
      piVar2[2] = 0;
      piVar2[3] = 0;
      piVar2[4] = 0;
      piVar2[5] = 0;
      piVar2[1] = (int)piVar2;
      *piVar2 = (int)piVar2;
      piVar2[1] = *(int *)(param_1 + 0x974);
      *piVar2 = iVar1;
      *(int **)(param_1 + 0x974) = piVar2;
      *(int **)piVar2[1] = piVar2;
      piVar2 = piVar2 + 6;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  puVar5 = &DAT_1001e628;
  puVar4 = (undefined4 *)(param_1 + 0x864);
  do {
    iVar3 = (**(code **)(**(int **)(param_1 + 0x84c) + 0x28))
                      (*(int **)(param_1 + 0x84c),
                       *(undefined4 *)(*(int *)(param_1 + 0x83c) + 0x2a380),
                       **(undefined4 **)(param_1 + 0x844),
                       *(undefined4 *)(*(int *)(param_1 + 0x848) + 8),0,3,*puVar5);
    if (iVar3 < 0) {
      *puVar4 = 0;
    }
    else {
      *puVar4 = *puVar5;
    }
    puVar5 = puVar5 + 1;
    puVar4 = puVar4 + 1;
  } while ((int)puVar5 < 0x1001e65c);
  return;
}



/* ===== FUN_1000b530 @ 0x1000B530 ===== */

int __cdecl FUN_1000b530(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *unaff_EBX;
  int *unaff_EBP;
  int *unaff_retaddr;
  undefined1 *puVar3;
  int iVar4;
  char *pcVar5;
  int local_8c [5];
  undefined1 auStack_78 [4];
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined1 auStack_6c [108];
  
  local_8c[0] = 0;
  local_8c[1] = 0;
  iVar1 = (**(code **)(**(int **)(param_1 + 0x850) + 0x84))(*(int **)(param_1 + 0x850),local_8c);
  if ((iVar1 != -0x7789f79a) && (iVar1 != 0)) {
    (*DAT_1002471c)(iVar1);
    puVar3 = auStack_6c;
    pcVar5 = s_DXErr__8_8X_1001e770;
    iVar4 = iVar1;
    FUN_1000feb4(puVar3,(byte *)s_DXErr__8_8X_1001e770);
    (*DAT_10024718)(auStack_6c,puVar3,pcVar5,iVar4);
    return iVar1;
  }
  if (param_1 == 0) {
    if (unaff_EBP != (int *)0x0) {
      piRam000007e0 = unaff_EBP;
    }
    unaff_EBP = (int *)0x0;
  }
  else {
    if (unaff_EBP == (int *)0x0) {
      unaff_EBP = *(int **)(param_1 + 0x7e0);
    }
    *(undefined4 *)(param_1 + 0x7e0) = 0;
  }
  if (unaff_retaddr == (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x850) + 0x40))
              (*(int **)(param_1 + 0x850),0,0,&stack0xffffff70);
    unaff_retaddr = unaff_EBX;
    if (unaff_EBX == (int *)0x0) goto LAB_1000b6c0;
  }
  iVar1 = (**(code **)(**(int **)(param_1 + 0x850) + 0x7c))
                    (*(int **)(param_1 + 0x850),unaff_retaddr,unaff_EBP);
  if (iVar1 != 0) {
    (*DAT_1002471c)(iVar1);
    puVar3 = auStack_78;
    pcVar5 = s_DXErr__8_8X_1001e770;
    iVar4 = iVar1;
    FUN_1000feb4(puVar3,(byte *)s_DXErr__8_8X_1001e770);
    (*DAT_10024718)(auStack_78,puVar3,pcVar5,iVar4);
    return iVar1;
  }
  iVar1 = (**(code **)(*unaff_retaddr + 0x20))(unaff_retaddr,&stack0xffffff68);
  if (iVar1 != 0) {
    (*DAT_1002471c)(iVar1);
    puVar3 = auStack_6c;
    pcVar5 = s_DXErr__8_8X_1001e770;
    iVar4 = iVar1;
    FUN_1000feb4(puVar3,(byte *)s_DXErr__8_8X_1001e770);
    (*DAT_10024718)(auStack_6c,puVar3,pcVar5,iVar4);
    return iVar1;
  }
  *(undefined4 *)(param_1 + 0x960) = uStack_74;
  *(undefined4 *)(param_1 + 0x964) = uStack_70;
  uVar2 = FUN_100062d0(local_8c[0]);
  *(undefined4 *)(param_1 + 0x968) = uVar2;
  if (unaff_EBX != (int *)0x0) {
    (**(code **)(*unaff_EBX + 8))(unaff_EBX);
  }
LAB_1000b6c0:
  if (unaff_EBP != (int *)0x0) {
    (**(code **)(*unaff_EBP + 8))(unaff_EBP);
  }
  return 0;
}



/* ===== FUN_1000b930 @ 0x1000B930 ===== */

undefined4 __cdecl FUN_1000b930(int param_1,int param_2)

{
  if (param_2 == 0) {
LAB_1000b93d:
    if (*(int *)(param_1 + 0x864) != 0) {
      return 0;
    }
    if (*(int *)(param_1 + 0x870) != 0) {
      return 3;
    }
    if (*(int *)(param_1 + 0x874) != 0) {
      return 4;
    }
  }
  else {
    if ((param_2 == 1) || (param_2 == 2)) {
      if (*(int *)(param_1 + 0x86c) != 0) {
        return 2;
      }
      if (*(int *)(param_1 + 0x868) != 0) {
        return 1;
      }
      if (*(int *)(param_1 + 0x864) != 0) {
        return 0;
      }
      if (*(int *)(param_1 + 0x878) == 0) {
        if (*(int *)(param_1 + 0x874) != 0) {
          return 4;
        }
        if (*(int *)(param_1 + 0x870) == 0) {
          return 8;
        }
        return 3;
      }
      return 5;
    }
    if (param_2 == 3) {
      if (*(int *)(param_1 + 0x870) != 0) {
        return 3;
      }
      if (*(int *)(param_1 + 0x874) != 0) {
        return 4;
      }
    }
    else if (param_2 == 5) {
      if (*(int *)(param_1 + 0x878) != 0) {
        return 5;
      }
      if (*(int *)(param_1 + 0x874) != 0) {
        return 4;
      }
      if (*(int *)(param_1 + 0x86c) != 0) {
        return 2;
      }
      if (*(int *)(param_1 + 0x868) != 0) {
        return 1;
      }
    }
    else {
      if (param_2 != 4) {
        if (param_2 != 6) {
          if (param_2 != 7) {
            return 8;
          }
          if (*(int *)(param_1 + 0x880) == 0) {
            return 8;
          }
          return 7;
        }
        goto LAB_1000b93d;
      }
      if (*(int *)(param_1 + 0x874) != 0) {
        return 4;
      }
      if (*(int *)(param_1 + 0x870) != 0) {
        return 3;
      }
    }
    if (*(int *)(param_1 + 0x864) != 0) {
      return 0;
    }
  }
  return 8;
}



/* ===== FUN_1000bab0 @ 0x1000BAB0 ===== */

void __cdecl FUN_1000bab0(int param_1,uint *param_2)

{
  bool bVar1;
  uint *puVar2;
  uint *puVar3;
  uint uVar4;
  uint *puVar5;
  uint *puVar6;
  longlong lVar7;
  
  puVar2 = param_2;
  puVar5 = (uint *)0x0;
  if (*(undefined **)(param_1 + 4) != (undefined *)0x0) {
    FUN_100101ee(*(undefined **)(param_1 + 4));
  }
  puVar3 = _malloc((int)param_2 * (int)param_2 * 4);
  *(uint **)(param_1 + 4) = puVar3;
  bVar1 = param_2 != (uint *)0x0;
  param_2 = puVar3;
  if (bVar1) {
    do {
      puVar6 = (uint *)0x0;
      puVar3 = param_2;
      do {
        FUN_100102e0();
        lVar7 = __ftol();
        uVar4 = (uint)lVar7;
        if ((int)uVar4 < 0x100) {
          if ((int)uVar4 < 0) {
            uVar4 = 0;
          }
        }
        else {
          uVar4 = 0xff;
        }
        *puVar3 = (uVar4 << 8 | uVar4) << 8 | uVar4;
        puVar6 = (uint *)((int)puVar6 + 1);
        puVar3 = puVar3 + 1;
      } while (puVar6 < puVar2);
      puVar5 = (uint *)((int)puVar5 + 1);
      param_2 = param_2 + (int)puVar2;
    } while (puVar5 < puVar2);
  }
  return;
}



/* ===== FUN_1000bbd0 @ 0x1000BBD0 ===== */

void __cdecl FUN_1000bbd0(int *param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  float fVar2;
  int iVar3;
  uint uVar4;
  undefined *puVar5;
  int *unaff_ESI;
  uint *puVar6;
  uint *puVar7;
  int **ppiVar8;
  undefined4 *puVar9;
  undefined1 *puVar10;
  char *pcVar11;
  undefined4 uVar12;
  int *piVar13;
  int *piVar14;
  int *piVar15;
  int *apiStack_148 [2];
  int local_128 [6];
  undefined4 local_110;
  uint auStack_108 [5];
  undefined4 uStack_f4;
  undefined4 uStack_f0;
  int local_ec;
  int local_e8;
  int iStack_e4;
  uint auStack_e0 [4];
  undefined4 local_d0;
  undefined4 uStack_cc;
  undefined *puStack_c4;
  uint uStack_a8;
  undefined4 uStack_a4;
  undefined1 auStack_a0 [4];
  float fStack_9c;
  undefined1 auStack_94 [4];
  undefined1 auStack_90 [12];
  undefined4 uStack_84;
  undefined4 uStack_80;
  int *piStack_38;
  int iStack_34;
  
  iVar1 = *(int *)(param_2 + 8);
  local_128[1] = 0;
  local_128[0] = 0;
  local_128[2] = 0;
  local_128[3] = 0x3f800000;
  local_ec = FUN_100049b0(*(uint *)(iVar1 + 0xc));
  apiStack_148[1] = (int *)0x1000bc12;
  local_e8 = FUN_100049b0(*(uint *)(iVar1 + 0x10));
  local_d0 = param_3;
  auStack_e0[2] = *(undefined4 *)(iVar1 + 0x14);
  auStack_e0[3] = (uint)((*(byte *)(iVar1 + 0x1e) & 2) != 0);
  if ((*(byte *)(iVar1 + 0x1e) & 4) != 0) {
    auStack_e0[3] = auStack_e0[3] | 2;
  }
  apiStack_148[1] = (int *)0x1000bc58;
  FUN_10004f10(&local_ec,0);
  if (((*(byte *)(iVar1 + 0x1f) & 1) == 0) || (param_1[0x22d] == 0)) {
    local_128[4] = 1;
  }
  else {
    apiStack_148[0] = param_1;
    apiStack_148[1] = (int *)iVar1;
    (*(code *)param_1[0x30])();
    local_128[4] = (*(code *)param_1[0x2f])(param_1,local_128[5],local_110);
    local_128[4] = local_128[4] + 1;
    if (local_128[4] < 1) goto LAB_1000c004;
  }
  do {
    if ((*(byte *)(iVar1 + 0x1e) & 0x60) == 0) {
      apiStack_148[1] = *(int **)(param_2 + 0xc);
      apiStack_148[0] = (int *)0x1000bcee;
      (**(code **)(*apiStack_148[1] + 0x3c))();
    }
    else {
      apiStack_148[0] = *(int **)(param_2 + 0xc);
      apiStack_148[1] = DAT_1001e740;
      (**(code **)(*apiStack_148[0] + 0x3c))();
    }
    if (unaff_ESI == (int *)0x0) break;
    puVar10 = auStack_94;
    piVar15 = unaff_ESI;
    (**(code **)(*unaff_ESI + 0x20))();
    fVar2 = fStack_9c;
    piVar13 = (int *)param_1[0x214];
    piVar14 = (int *)&stack0xfffffec0;
    iVar3 = (**(code **)(*piVar13 + 0x6c))(piVar13,uStack_84,uStack_80);
    if (iVar3 != 0) {
LAB_1000c07f:
      (*DAT_1002471c)(iVar3);
      puVar10 = auStack_90;
      pcVar11 = s_DXErr__8_8X_1001e770;
      FUN_1000feb4(puVar10,(byte *)s_DXErr__8_8X_1001e770);
      (*DAT_10024718)(auStack_90,puVar10,pcVar11,iVar3);
      return;
    }
    uVar12 = 0x800;
    iVar3 = (**(code **)(*piVar14 + 0x24))(piVar14,auStack_e0 + 2,0,0x800);
    if (iVar3 != 0) {
      (*DAT_1002471c)(iVar3);
      puVar10 = auStack_a0;
      pcVar11 = s_DXErr__8_8X_1001e770;
      FUN_1000feb4(puVar10,(byte *)s_DXErr__8_8X_1001e770);
      (*DAT_10024718)(auStack_a0,puVar10,pcVar11,iVar3);
      return;
    }
    auStack_108[0] = uStack_a8;
    local_ec = iStack_e4;
    auStack_108[1] = uStack_a4;
    uStack_f4 = *(undefined4 *)(iStack_34 + 0x10);
    uStack_f0 = 0;
    FUN_10004f10((int *)auStack_108,local_e8);
    if ((*(byte *)(iVar1 + 0x1e) & 0x10) == 0) {
      FUN_10004f70((int *)auStack_108,local_128,fVar2);
    }
    else {
      iVar3 = 8;
      if (param_1[0x234] == 0) {
        puVar6 = auStack_108;
        ppiVar8 = apiStack_148;
        for (; iVar3 != 0; iVar3 = iVar3 + -1) {
          *ppiVar8 = (int *)*puVar6;
          puVar6 = puVar6 + 1;
          ppiVar8 = ppiVar8 + 1;
        }
        unaff_ESI = (int *)0x0;
        puVar5 = operator_new((int)apiStack_148[1] * (int)apiStack_148[0] * 4);
        FUN_10004f10((int *)apiStack_148,0);
        FUN_10004f70((int *)apiStack_148,local_128,1.0);
        uVar4 = FUN_10006120((int *)apiStack_148);
        if ((char)uVar4 == '\0') {
          FUN_10005950((uint *)apiStack_148,0);
        }
        FUN_100052b0((uint *)apiStack_148,0.015625,0);
        FUN_10004f70((int *)auStack_108,(int *)apiStack_148,1.0);
        FUN_1000fe9b(puVar5);
        param_1 = piStack_38;
      }
      else {
        uStack_f4 = 7;
        puVar6 = auStack_108;
        puVar7 = auStack_e0;
        for (; iVar3 != 0; iVar3 = iVar3 + -1) {
          *puVar7 = *puVar6;
          puVar6 = puVar6 + 1;
          puVar7 = puVar7 + 1;
        }
        uStack_cc = 0;
        puStack_c4 = operator_new(auStack_e0[1] * auStack_e0[0] * 4);
        FUN_10004f10((int *)auStack_e0,0);
        FUN_10004f70((int *)auStack_e0,local_128,1.0);
        uVar4 = FUN_10006120((int *)auStack_e0);
        if ((char)uVar4 == '\0') {
          FUN_10005950(auStack_e0,5);
        }
        FUN_10005640(auStack_e0);
        FUN_10004f70((int *)auStack_108,(int *)auStack_e0,1.0);
        FUN_1000fe9b(puStack_c4);
        param_1 = piStack_38;
      }
    }
    iVar3 = (**(code **)(*piVar13 + 0x28))(piVar13);
    if (iVar3 != 0) {
      (*DAT_1002471c)(iVar3);
      puVar9 = &uStack_a4;
      pcVar11 = s_DXErr__8_8X_1001e770;
      FUN_1000feb4((undefined1 *)puVar9,(byte *)s_DXErr__8_8X_1001e770);
      (*DAT_10024718)(&uStack_a4,puVar9,pcVar11,iVar3);
      return;
    }
    iVar3 = (**(code **)(*(int *)param_1[0x214] + 0x70))((int *)param_1[0x214],uVar12,0,0,piVar13,0)
    ;
    if (iVar3 != 0) goto LAB_1000c07f;
    if (piVar14 != (int *)0x0) {
      (**(code **)(*piVar14 + 8))(piVar14);
    }
    (**(code **)(*piVar15 + 8))(piVar15);
  } while ((int)(puVar10 + 1) < local_128[4]);
LAB_1000c004:
  *(byte *)(iVar1 + 0x1f) = *(byte *)(iVar1 + 0x1f) | 0x40;
  return;
}



/* ===== FUN_1000c0c0 @ 0x1000C0C0 ===== */

undefined4 __cdecl FUN_1000c0c0(int param_1,int param_2,int *param_3,undefined4 *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  int *piVar8;
  int local_c;
  
  iVar1 = param_2;
  *param_4 = 8;
  if (param_2 < 0x33545845) {
    if (param_2 == 0x33545844) {
      param_2 = 4;
      param_4 = (undefined4 *)0x0;
      goto LAB_1000c118;
    }
    if (param_2 == 0) goto LAB_1000c28d;
    if (param_2 == 0x31545844) {
      param_2 = 1;
      param_4 = (undefined4 *)0x0;
      goto LAB_1000c118;
    }
    if (param_2 != 0x32545844) goto LAB_1000c1db;
    param_2 = 4;
  }
  else {
    if (param_2 != 0x34545844) {
      if (param_2 == 0x35545844) {
        param_2 = 8;
        param_4 = (undefined4 *)0x0;
        goto LAB_1000c118;
      }
LAB_1000c1db:
      if (param_3 == (int *)0x0) {
        if (param_2 == 0x15) {
          *param_4 = 0;
          uRam00000000 = 0;
          return 0;
        }
        if (param_2 == 0x16) {
          *param_4 = 1;
          uRam00000000 = 0;
          return 0;
        }
        if (param_2 == 0x14) {
          *param_4 = 2;
          uRam00000000 = 0;
          return 0;
        }
        if (param_2 == 0x17) {
          *param_4 = 5;
          uRam00000000 = 0;
          return 0;
        }
        if (param_2 == 0x1a) {
          *param_4 = 3;
          uRam00000000 = 0;
          return 0;
        }
        if (param_2 == 0x19) {
          *param_4 = 4;
        }
LAB_1000c28d:
        *param_3 = 0;
        return 0;
      }
      goto LAB_1000c118;
    }
    param_2 = 8;
  }
  param_4 = (undefined4 *)0x1;
LAB_1000c118:
  piVar8 = (int *)(param_1 + 0x864);
  uVar6 = 0;
  piVar5 = piVar8;
  do {
    iVar7 = *piVar5;
    if (iVar7 == iVar1) goto LAB_1000c32b;
    uVar6 = uVar6 + 1;
    piVar5 = piVar5 + 1;
  } while (uVar6 < 0xd);
  local_c = -1;
  uVar6 = 0;
  do {
    iVar1 = *piVar8;
    if (iVar1 != 0) {
      iVar7 = (&DAT_1001e6d0)[uVar6];
      iVar2 = (&DAT_1001e708)[uVar6];
      iVar3 = (&DAT_1001e660)[uVar6];
      iVar4 = (&DAT_1001e698)[uVar6];
      if (iVar1 == 0x34545844) {
        (*DAT_10024718)(s_Warning_premultiplied_alpha_1001e77c);
      }
      if ((undefined4 *)(uint)(iVar1 == 0x34545844) == param_4) {
        if ((((iVar3 == param_2) && (3 < iVar4)) && (3 < iVar7)) && (3 < iVar2)) {
          iVar7 = *(int *)(param_1 + 0x864 + uVar6 * 4);
LAB_1000c32b:
          *param_3 = iVar7;
          return 0;
        }
        if (((local_c < iVar3) && (3 < iVar4)) && ((3 < iVar7 && (3 < iVar2)))) {
          *param_3 = *piVar8;
          local_c = iVar3;
        }
      }
    }
    if (0xc < uVar6) {
      return 0x80004005;
    }
    uVar6 = uVar6 + 1;
    piVar8 = piVar8 + 1;
    if (0xc < uVar6) {
      return 0;
    }
  } while( true );
}



/* ===== FUN_1000c350 @ 0x1000C350 ===== */

void __cdecl FUN_1000c350(int param_1,uint *param_2,uint *param_3,undefined4 *param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  uint *puVar6;
  uint *puVar7;
  uint *puVar8;
  uint unaff_EDI;
  uint *puVar9;
  int iStack_ac;
  uint uStack_a8;
  undefined4 *puStack_a4;
  undefined4 local_90 [5];
  uint local_7c [6];
  uint *local_64;
  uint uStack_5c;
  undefined4 local_2c;
  undefined4 *puStack_c;
  
  puVar6 = param_2;
  puVar5 = local_7c;
  for (iVar2 = 0x1f; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar5 = *puVar6;
    puVar6 = puVar6 + 1;
    puVar5 = puVar5 + 1;
  }
  puVar6 = local_7c;
  for (iVar2 = 0x1f; iVar2 != 0; iVar2 = iVar2 + -1) {
    *param_3 = *puVar6;
    puVar6 = puVar6 + 1;
    param_3 = param_3 + 1;
  }
  puVar6 = param_2 + 0x1f;
  local_90[0] = 0;
  puVar5 = (uint *)0x1;
  if (*(int *)(param_1 + 0x8b4) != 0) {
    puVar5 = local_64;
  }
  puStack_a4 = local_90;
  uStack_a8 = 2;
  *param_4 = local_2c;
  iVar2 = (**(code **)(**(int **)(param_1 + 0x850) + 0x50))(*(int **)(param_1 + 0x850),local_7c[3]);
  if (-1 < iVar2) {
    *puStack_c = 0;
    iStack_ac = 0;
    uVar4 = local_7c[2];
    while (iVar2 = (**(code **)(iRam00000000 + 0x40))(0,iStack_ac,&puStack_a4,0), -1 < iVar2) {
      uVar1 = (uStack_5c >> 3) * (int)puStack_a4;
      puVar7 = puVar5;
      uVar3 = uVar4;
      if (local_7c[2] == uVar1) {
        puVar7 = puVar6;
        puVar8 = puVar5;
        for (uVar3 = unaff_EDI >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
          *puVar8 = *puVar7;
          puVar7 = puVar7 + 1;
          puVar8 = puVar8 + 1;
        }
        for (uVar3 = unaff_EDI & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
          *(char *)puVar8 = (char)*puVar7;
          puVar7 = (uint *)((int)puVar7 + 1);
          puVar8 = (uint *)((int)puVar8 + 1);
        }
        puVar6 = (uint *)((int)puVar6 + unaff_EDI);
      }
      else {
        for (; uVar3 != 0; uVar3 = uVar3 - 1) {
          puVar8 = puVar6;
          puVar9 = puVar7;
          for (uVar4 = uVar1 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
            *puVar9 = *puVar8;
            puVar8 = puVar8 + 1;
            puVar9 = puVar9 + 1;
          }
          for (uVar4 = uVar1 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
            *(char *)puVar9 = (char)*puVar8;
            puVar8 = (uint *)((int)puVar8 + 1);
            puVar9 = (uint *)((int)puVar9 + 1);
          }
          puVar6 = (uint *)((int)puVar6 + uVar1);
          puVar7 = (uint *)((int)puVar7 + local_7c[2]);
          uVar4 = uStack_a8;
        }
      }
      (**(code **)(iRam00000800 + 0x44))(0x800,0);
      iStack_ac = iStack_ac + 1;
    }
  }
  return;
}



/* ===== FUN_1000c4a0 @ 0x1000C4A0 ===== */

int __cdecl FUN_1000c4a0(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *unaff_EDI;
  bool bVar6;
  undefined1 *puVar7;
  char *pcVar8;
  int iVar9;
  int *local_a0;
  int local_9c;
  int iStack_98;
  uint local_94;
  uint local_90;
  int iStack_8c;
  int iStack_88;
  int iStack_84;
  undefined1 auStack_64 [100];
  
  iVar9 = *(int *)(param_2 + 8);
  iVar5 = 0;
  iVar2 = FUN_1000b930(param_1,*(int *)(iVar9 + 0x18));
  *(int *)(param_2 + 0x10) = iVar2;
  if (iVar2 != 8) {
    iVar2 = *(int *)(param_1 + 0x864 + iVar2 * 4);
    local_9c = 0;
    local_a0 = (int *)0x0;
    (**(code **)(param_1 + 0xc0))(param_1,iVar9,&local_94,&local_90);
    iStack_98 = FUN_100049b0(local_94);
    iStack_8c = FUN_100049b0(local_90);
    if (*(char *)(iVar9 + 0x1e) < '\0') {
      (**(code **)(**(int **)(param_1 + 0x850) + 0x40))(*(int **)(param_1 + 0x850),0,0,&local_a0);
      iVar2 = (**(code **)(*unaff_EDI + 0x20))(unaff_EDI,&local_94);
      if (iVar2 != 0) {
        (*DAT_1002471c)(iVar2);
        puVar7 = auStack_64;
        pcVar8 = s_DXErr__8_8X_1001e770;
        iVar9 = iVar2;
        FUN_1000feb4(puVar7,(byte *)s_DXErr__8_8X_1001e770);
        (*DAT_10024718)(auStack_64,puVar7,pcVar8,iVar9);
        return iVar2;
      }
      if (local_a0 != (int *)0x0) {
        (**(code **)(*local_a0 + 8))(local_a0);
      }
      local_a0 = (int *)0x1;
      iVar2 = iStack_84;
    }
    if ((((*(ushort *)(iVar9 + 0x1e) & 0x10) == 0) || (*(int *)(param_1 + 0x8cc) == 0)) ||
       (*(int *)(param_1 + 0x8d0) == 0)) {
      if (((*(ushort *)(iVar9 + 0x1e) & 0x100) != 0) && (*(int *)(param_1 + 0x8b4) != 0)) {
        iVar5 = (**(code **)(param_1 + 0xbc))(param_1,local_94,local_90);
        local_9c = iVar5;
      }
    }
    else {
      *(undefined4 *)(iVar9 + 0x18) = 7;
      iVar2 = 0x3c;
      *(undefined4 *)(param_2 + 0x10) = 7;
    }
    iStack_88 = (-(uint)((*(byte *)(iVar9 + 0x1e) & 0x60) != 0) & 5) + 1;
    iVar3 = FUN_100062d0(iVar2);
    iVar3 = (iVar3 >> 3) * iStack_8c * iStack_98;
    iVar4 = 0;
    do {
      iVar4 = iVar4 + iVar3;
      iVar3 = (int)(iVar3 + (iVar3 >> 0x1f & 3U)) >> 2;
      bVar6 = iVar5 != 0;
      iVar5 = iVar5 + -1;
    } while (bVar6);
    iVar5 = iVar4 * iStack_88;
    if ((uint)(*(int *)(param_1 + 0x9d4) + iVar5) < *(uint *)(param_1 + 0x9d8)) {
      piVar1 = *(int **)(param_1 + 0x850);
      if ((*(byte *)(iVar9 + 0x1e) & 0x60) != 0) {
        (**(code **)(*piVar1 + 0x58))(piVar1,iStack_98);
        return iVar5;
      }
      (**(code **)(*piVar1 + 0x50))
                (piVar1,iStack_98,iStack_8c,local_9c + 1,local_a0,iVar2,0,param_2 + 0xc);
    }
  }
  return iVar5;
}



/* ===== FUN_1000cd10 @ 0x1000CD10 ===== */

void __cdecl FUN_1000cd10(int param_1,int param_2)

{
  byte *pbVar1;
  int *piVar2;
  
  piVar2 = *(int **)(param_2 + 0xc);
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 8))(piVar2);
    *(undefined4 *)(param_2 + 0xc) = 0;
  }
  pbVar1 = (byte *)(*(int *)(param_2 + 8) + 0x1f);
  *pbVar1 = *pbVar1 & 0x3f;
  *(int *)(param_1 + 0x9d4) = *(int *)(param_1 + 0x9d4) - *(int *)(param_2 + 0x14);
  *(undefined4 *)(param_2 + 0x14) = 0;
  return;
}



/* ===== FUN_1000cd50 @ 0x1000CD50 ===== */

void __cdecl FUN_1000cd50(int param_1,int *param_2)

{
  int *piVar1;
  
  if (param_2 != (int *)0x0) {
    piVar1 = (int *)param_2[3];
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
      param_2[3] = 0;
    }
    *(byte *)(param_2[2] + 0x1f) = *(byte *)(param_2[2] + 0x1f) & 0x3f;
    *(int *)(param_1 + 0x9d4) = *(int *)(param_1 + 0x9d4) - param_2[5];
    param_2[5] = 0;
    *(undefined4 *)(param_2[2] + 8) = 0;
    param_2[2] = 0;
    *(int *)param_2[1] = *param_2;
    *(int *)(*param_2 + 4) = param_2[1];
    piVar1 = (int *)(param_1 + 0x970);
    param_2[1] = (int)piVar1;
    *param_2 = *piVar1;
    *piVar1 = (int)param_2;
    *(int **)(*param_2 + 4) = param_2;
    *(undefined4 *)(param_1 + 0x904) = 0;
    *(undefined4 *)(param_1 + 0x908) = 0;
    *(undefined4 *)(param_1 + 0x90c) = 0;
    *(undefined4 *)(param_1 + 0x910) = 0;
    (**(code **)(param_1 + 0x14))(param_1);
  }
  return;
}



/* ===== FUN_1000cde0 @ 0x1000CDE0 ===== */

void __cdecl FUN_1000cde0(int param_1,int param_2)

{
  if ((param_2 != 0) && (*(int **)(param_2 + 8) != (int *)0x0)) {
    FUN_1000cd50(param_1,*(int **)(param_2 + 8));
    return;
  }
  return;
}



/* ===== FUN_1000ce00 @ 0x1000CE00 ===== */

void __cdecl FUN_1000ce00(int param_1)

{
  void *this;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_10019eab;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  this = operator_new(0x678);
  local_4 = 0;
  if (this == (void *)0x0) {
    DAT_10024708 = (void *)0x0;
  }
  else {
    DAT_10024708 = (void *)FUN_1000edc0(this,s_Arial_1001e8bc,0xc,1);
  }
  local_4 = 0xffffffff;
  if (DAT_10024708 != (void *)0x0) {
    FUN_1000ee80(DAT_10024708,*(int **)(param_1 + 0x850));
    FUN_1000f210((int)DAT_10024708);
  }
  ExceptionList = local_c;
  return;
}



/* ===== FUN_1000ce90 @ 0x1000CE90 ===== */

void FUN_1000ce90(void)

{
  undefined *puVar1;
  
  if (DAT_10024708 != (undefined *)0x0) {
    FUN_1000f480((int)DAT_10024708);
    FUN_1000f4f0((int)DAT_10024708);
    puVar1 = DAT_10024708;
    if (DAT_10024708 != (undefined *)0x0) {
      FUN_1000ee10((int)DAT_10024708);
      FUN_1000fe9b(puVar1);
    }
    DAT_10024708 = (undefined *)0x0;
  }
  return;
}



/* ===== FUN_1000cee0 @ 0x1000CEE0 ===== */

void FUN_1000cee0(void)

{
  int iVar1;
  
  iVar1 = DAT_10024708;
  if (DAT_10024708 != 0) {
    __ftol();
    __ftol();
    __ftol();
    FUN_1000f520(iVar1);
  }
  return;
}



/* ===== UpCallsLoad @ 0x1000CF50 ===== */ /* EXPORT UpCallsLoad */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl UpCallsLoad(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
                    /* 0xcf50  2  UpCallsLoad */
  _DAT_1002470c = *param_3;
  _DAT_10024710 = param_3[1];
  DAT_10024714 = param_3[2];
  DAT_10024718 = param_3[3];
  DAT_1002471c = param_3[4];
  _DAT_10024720 = param_3[5];
  _DAT_10024724 = param_3[6];
  _DAT_10024728 = param_3[7];
  _DAT_1002472c = param_3[8];
  DAT_10024730 = param_3[9];
  DAT_10024734 = param_3[10];
  DAT_10024738 = param_3[0xb];
  _DAT_1002473c = param_3[0xc];
  _DAT_10024740 = param_3[0xd];
  _DAT_10024744 = param_3[0xe];
  _DAT_10024748 = param_3[0xf];
  _DAT_1002474c = param_3[0x10];
  _DAT_10024750 = param_3[0x11];
  DAT_10024754 = param_3[0x12];
  DAT_10024758 = param_3[0x13];
  _DAT_1002475c = param_3[0x14];
  return;
}



/* ===== FUN_1000d1b0 @ 0x1000D1B0 ===== */

bool __cdecl
FUN_1000d1b0(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,uint *param_7,
            uint *param_8)

{
  int iVar1;
  
  *(undefined4 *)(*(int *)(param_1 + 0x83c) + 0x2a38c) = 0;
  *(undefined4 *)(param_1 + 0x81c) = 0;
  iVar1 = FUN_100086b0(param_1);
  if (-1 < iVar1) {
    FUN_10006d60(param_1,param_2,param_3,param_4,param_5,param_6);
    iVar1 = FUN_10008780(param_1,param_7,param_8);
  }
  *(undefined4 *)(param_1 + 0x81c) = 1;
  *(undefined4 *)(*(int *)(param_1 + 0x83c) + 0x2a38c) = 1;
  return iVar1 == 0;
}



/* ===== FUN_1000d290 @ 0x1000D290 ===== */

void __fastcall FUN_1000d290(undefined4 *param_1)

{
  *param_1 = &PTR_LAB_1001a228;
  DAT_10024760 = param_1;
  param_1[0xa8df] = 0;
  param_1[0xa8e0] = 0;
  param_1[0xa8f5] = 0;
  param_1[0xa8f6] = 0;
  param_1[0xa8f3] = 0;
  param_1[0xa8f4] = 0;
  param_1[0xa8e2] = 0;
  param_1[0xa8e3] = 0;
  param_1[0xa934] = 0;
  param_1[0xa8e4] = 1;
  param_1[0xa8e5] = 0;
  param_1[0xa940] = 0;
  *(undefined1 *)(param_1 + 0xa941) = 0;
  *(undefined1 *)((int)param_1 + 0x2a55e) = 0;
  param_1[0xa962] = s_D3D8_Application_1001e8c4;
  param_1[0xa966] = 400;
  param_1[0xa967] = 300;
  param_1[0xa963] = 0;
  param_1[0xa964] = 0x10;
  param_1[0xa965] = 0;
  param_1[0xa968] = 0;
  return;
}



/* ===== FUN_1000d590 @ 0x1000D590 ===== */

undefined4 __fastcall FUN_1000d590(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  uint uVar6;
  int iVar7;
  int *piVar8;
  uint unaff_EBX;
  uint uVar9;
  uint *puVar10;
  undefined4 *puVar11;
  bool bVar12;
  uint uVar13;
  uint uVar14;
  undefined4 *puVar15;
  int *piVar16;
  uint uStack_7c8;
  int iStack_7c4;
  int aiStack_7b8 [10];
  undefined *local_790;
  undefined *local_78c;
  undefined4 local_788;
  undefined4 local_784;
  int aiStack_758 [20];
  int aiStack_708 [20];
  int aiStack_6b8 [20];
  uint auStack_668 [410];
  
  aiStack_7b8[2] = 0;
  aiStack_7b8[4] = 0;
  aiStack_7b8[1] = 0;
  aiStack_7b8[3] = 0;
  local_790 = &DAT_1001e8e8;
  local_78c = &DAT_1001e8e4;
  local_788 = 1;
  local_784 = 2;
  iVar3 = (**(code **)(*(int *)param_1[0xa8f5] + 0x10))((int *)param_1[0xa8f5]);
  if (iVar3 != 0) {
    do {
      piVar1 = param_1 + param_1[0xa8df] * 0x10e3 + 1;
      puVar11 = (undefined4 *)0x0;
      puVar15 = (undefined4 *)0x0;
      piVar16 = piVar1;
      (**(code **)(*(int *)param_1[0xa8f5] + 0x14))((int *)param_1[0xa8f5]);
      (**(code **)(*(int *)param_1[0xa8f5] + 0x20))
                ((int *)param_1[0xa8f5],iStack_7c4,piVar1 + 0x10b);
      piVar1[0x10f] = 0;
      piVar1[0x10e2] = 0;
      uVar4 = (**(code **)(*(int *)param_1[0xa8f5] + 0x18))((int *)param_1[0xa8f5],iStack_7c4);
      aiStack_758[0] = piVar1[0x10e];
      uVar9 = 1;
      uVar14 = 1;
      uVar13 = 0;
      if (uVar4 != 0) {
        puVar10 = auStack_668 + 1;
        do {
          (**(code **)(*(int *)param_1[0xa8f5] + 0x1c))
                    ((int *)param_1[0xa8f5],iStack_7c4,uVar13,&stack0xfffff834);
          if ((0x27f < unaff_EBX) && (399 < uStack_7c8)) {
            puVar15 = (undefined4 *)0x0;
            if (puVar11 != (undefined4 *)0x0) {
              puVar5 = auStack_668 + 1;
              do {
                uVar9 = uVar14;
                if (((puVar5[-1] == unaff_EBX) && (*puVar5 == uStack_7c8)) && (puVar5[2] == 0))
                break;
                puVar15 = (undefined4 *)((int)puVar15 + 1);
                puVar5 = puVar5 + 4;
              } while (puVar15 < puVar11);
            }
            if (puVar15 == puVar11) {
              puVar10[-1] = unaff_EBX;
              uVar6 = 0;
              *puVar10 = uStack_7c8;
              puVar10[2] = 0;
              puVar10[1] = 0;
              puVar11 = (undefined4 *)((int)puVar11 + 1);
              puVar10 = puVar10 + 4;
              bVar12 = uVar9 == 0;
              if (uVar9 != 0) {
                do {
                  if (aiStack_758[uVar6] == 0) break;
                  uVar6 = uVar6 + 1;
                } while (uVar6 < uVar9);
                bVar12 = uVar6 == uVar9;
              }
              if (bVar12) {
                aiStack_758[uVar9] = 0;
                uVar9 = uVar9 + 1;
                uVar14 = uVar9;
              }
            }
          }
          uVar13 = uVar13 + 1;
          puVar15 = puVar11;
        } while (uVar13 < uVar4);
      }
      FUN_100108d2((int *)auStack_668,puVar11,0x10,&LAB_1000d540);
      uVar9 = 0;
      do {
        piVar1 = piVar16 + piVar16[0x10f] * 0x32a + 0x110;
        iVar3 = *(int *)((int)aiStack_7b8 + uVar9 + 8);
        *piVar1 = iVar3;
        uVar4 = uVar9;
        (**(code **)(*(int *)param_1[0xa8f5] + 0x34))
                  ((int *)param_1[0xa8f5],iStack_7c4,iVar3,piVar1 + 1);
        uVar13 = 0;
        piVar1[0x36] = *(int *)((int)aiStack_7b8 + uVar9);
        piVar1[0x38] = 0;
        piVar1[0x327] = 0;
        piVar1[0x37] = 0;
        piVar1[0x328] = 0;
        piVar1[0x329] = 0;
        if (uVar14 != 0) {
          do {
            iVar3 = aiStack_758[uVar13];
            piVar8 = (int *)param_1[0xa8f5];
            aiStack_6b8[uVar13] = 0;
            iVar7 = *piVar1;
            iVar2 = *piVar8;
            aiStack_7b8[uVar13 + 4] = 0;
            iVar7 = (**(code **)(iVar2 + 0x24))(piVar8,iStack_7c4,iVar7,iVar3,iVar3,0);
            if (-1 < iVar7) {
              if ((piVar1[8] & 0x10000U) == 0) {
LAB_1000d8bc:
                if (aiStack_7b8[uVar13 + 4] == 0) {
                  iVar7 = *param_1;
                  aiStack_708[uVar13] = 0x20;
                  iVar7 = (**(code **)(iVar7 + 4))(piVar1 + 1,0x20,iVar3);
                  if (-1 < iVar7) {
                    aiStack_7b8[uVar13 + 4] = 1;
                  }
                  if (aiStack_7b8[uVar13 + 4] == 0) goto LAB_1000d91c;
                }
              }
              else {
                if ((piVar1[8] & 0x100000U) != 0) {
                  iVar7 = *param_1;
                  aiStack_708[uVar13] = 0x50;
                  iVar7 = (**(code **)(iVar7 + 4))(piVar1 + 1,0x50,iVar3);
                  if (-1 < iVar7) {
                    aiStack_7b8[uVar13 + 4] = 1;
                  }
                }
                if (aiStack_7b8[uVar13 + 4] == 0) {
                  iVar7 = *param_1;
                  aiStack_708[uVar13] = 0x40;
                  iVar7 = (**(code **)(iVar7 + 4))(piVar1 + 1,0x40,iVar3);
                  if (-1 < iVar7) {
                    aiStack_7b8[uVar13 + 4] = 1;
                  }
                  if (aiStack_7b8[uVar13 + 4] == 0) {
                    iVar7 = *param_1;
                    aiStack_708[uVar13] = 0x80;
                    iVar7 = (**(code **)(iVar7 + 4))(piVar1 + 1,0x80,iVar3);
                    if (-1 < iVar7) {
                      aiStack_7b8[uVar13 + 4] = 1;
                    }
                    goto LAB_1000d8bc;
                  }
                }
              }
              if ((param_1[0xa963] != 0) &&
                 (iVar3 = FUN_1000dc20(param_1,iStack_7c4,(undefined4 *)*piVar1,iVar3,
                                       aiStack_6b8 + uVar13), iVar3 == 0)) {
                aiStack_7b8[uVar13 + 4] = 0;
              }
            }
LAB_1000d91c:
            uVar13 = uVar13 + 1;
          } while (uVar13 < uVar14);
        }
        if (puVar15 != (undefined4 *)0x0) {
          iVar3 = 0;
          puVar11 = puVar15;
          do {
            uVar9 = 0;
            if (uVar14 != 0) {
              do {
                if ((*(int *)((int)auStack_668 + iVar3 + 0xc) == aiStack_758[uVar9]) &&
                   (aiStack_7b8[uVar9 + 4] == 1)) {
                  piVar1[piVar1[0x38] * 5 + 0x39] = *(int *)((int)auStack_668 + iVar3);
                  piVar1[piVar1[0x38] * 5 + 0x3a] = *(int *)((int)auStack_668 + iVar3 + 4);
                  piVar1[piVar1[0x38] * 5 + 0x3b] = *(int *)((int)auStack_668 + iVar3 + 0xc);
                  piVar1[(piVar1[0x38] + 0xc) * 5] = aiStack_708[uVar9];
                  piVar1[piVar1[0x38] * 5 + 0x3d] = aiStack_6b8[uVar9];
                  piVar1[0x38] = piVar1[0x38] + 1;
                }
                uVar9 = uVar9 + 1;
              } while (uVar9 < uVar14);
            }
            iVar3 = iVar3 + 0x10;
            puVar11 = (undefined4 *)((int)puVar11 - 1);
          } while (puVar11 != (undefined4 *)0x0);
        }
        uVar9 = piVar1[0x38];
        uVar13 = 0;
        if (uVar9 != 0) {
          piVar8 = piVar1 + 0x3b;
          do {
            if ((piVar8[-2] == 0x280) && (piVar8[-1] == 0x1e0)) {
              piVar1[0x327] = uVar13;
              iVar3 = *piVar8;
              if ((iVar3 == 0x17) || ((iVar3 == 0x18 || (iVar3 == 0x19)))) break;
            }
            uVar13 = uVar13 + 1;
            piVar8 = piVar8 + 5;
          } while (uVar13 < uVar9);
        }
        if ((aiStack_7b8[4] != 0) && ((piVar1[4] & 0x80000U) != 0)) {
          piVar1[0x37] = 1;
          piVar1[0x328] = 1;
        }
        if (uVar9 != 0) {
          piVar16[0x10f] = piVar16[0x10f] + 1;
        }
        uVar9 = uVar4 + 4;
      } while (uVar9 < 8);
      if (piVar16[0x10f] != 0) {
        param_1[0xa8df] = param_1[0xa8df] + 1;
      }
      uVar9 = (**(code **)(*(int *)param_1[0xa8f5] + 0x10))((int *)param_1[0xa8f5]);
    } while (iStack_7c4 + 1U < uVar9);
  }
  uVar9 = param_1[0xa8df];
  if (uVar9 == 0) {
    return 0x82000003;
  }
  uVar14 = 0;
  if (uVar9 != 0) {
    puVar10 = (uint *)(param_1 + 0x110);
    do {
      uVar4 = 0;
      if (*puVar10 != 0) {
        puVar5 = puVar10 + 0x329;
        do {
          if (*puVar5 != 0) {
            param_1[(uVar14 + 1) * 0x10e3] = uVar4;
            param_1[0xa8e0] = uVar14;
            param_1[0xa8e1] = 1;
            if (param_1[uVar14 * 0x10e3 + uVar4 * 0x32a + 0x111] == 2) {
              if (aiStack_7b8[1] == 0) {
                FUN_1000eb70(param_1,-0x7dfffffb,2);
                return 0;
              }
              if (aiStack_7b8[2] == 0) {
                FUN_1000eb70(param_1,-0x7dfffffa,2);
                return 0;
              }
              if (aiStack_7b8[3] == 0) {
                FUN_1000eb70(param_1,-0x7dfffff9,2);
                return 0;
              }
              if (aiStack_7b8[0] == 0) {
                FUN_1000eb70(param_1,-0x7dfffff8,2);
                return 0;
              }
              FUN_1000eb70(param_1,-0x7dfffff7,2);
            }
            return 0;
          }
          uVar4 = uVar4 + 1;
          puVar5 = puVar5 + 0x32a;
        } while (uVar4 < *puVar10);
      }
      uVar14 = uVar14 + 1;
      puVar10 = puVar10 + 0x10e3;
    } while (uVar14 < uVar9);
  }
  return 0x82000004;
}



/* ===== FUN_1000dc20 @ 0x1000DC20 ===== */

undefined4 __thiscall
FUN_1000dc20(void *this,undefined4 param_1,undefined4 *param_2,undefined4 param_3,
            undefined4 *param_4)

{
  int iVar1;
  undefined4 *puVar2;
  
  if ((*(uint *)((int)this + 0x2a590) < 0x11) && (*(int *)((int)this + 0x2a594) == 0)) {
    iVar1 = (**(code **)(**(int **)((int)this + 0x2a3d4) + 0x28))
                      (*(int **)((int)this + 0x2a3d4),param_1,param_2,param_3,2,1,0x50);
    if (-1 < iVar1) {
      iVar1 = (**(code **)(**(int **)((int)this + 0x2a3d4) + 0x30))
                        (*(int **)((int)this + 0x2a3d4),param_1,param_2,param_3,param_3,0x50);
      if (-1 < iVar1) {
        *param_4 = 0x50;
        return 1;
      }
    }
  }
  if ((*(uint *)((int)this + 0x2a590) < 0x10) && (*(uint *)((int)this + 0x2a594) < 2)) {
    iVar1 = (**(code **)(**(int **)((int)this + 0x2a3d4) + 0x28))
                      (*(int **)((int)this + 0x2a3d4),param_1,param_2,param_3,2,1,0x49);
    if (-1 < iVar1) {
      iVar1 = (**(code **)(**(int **)((int)this + 0x2a3d4) + 0x30))
                        (*(int **)((int)this + 0x2a3d4),param_1,param_2,param_3,param_3,0x49);
      if (-1 < iVar1) {
        *param_4 = 0x49;
        return 1;
      }
    }
  }
  if (*(uint *)((int)this + 0x2a590) < 0x19) {
    if (*(int *)((int)this + 0x2a594) == 0) {
      iVar1 = (**(code **)(**(int **)((int)this + 0x2a3d4) + 0x28))
                        (*(int **)((int)this + 0x2a3d4),param_1,param_2,param_3,2,1,0x4d);
      if (-1 < iVar1) {
        iVar1 = (**(code **)(**(int **)((int)this + 0x2a3d4) + 0x30))
                          (*(int **)((int)this + 0x2a3d4),param_1,param_2,param_3,param_3,0x4d);
        if (-1 < iVar1) {
          *param_4 = 0x4d;
          return 1;
        }
      }
    }
    if (*(uint *)((int)this + 0x2a590) < 0x19) {
      if (*(uint *)((int)this + 0x2a594) < 9) {
        iVar1 = (**(code **)(**(int **)((int)this + 0x2a3d4) + 0x28))
                          (*(int **)((int)this + 0x2a3d4),param_1,param_2,param_3,2,1,0x4b);
        if (-1 < iVar1) {
          iVar1 = (**(code **)(**(int **)((int)this + 0x2a3d4) + 0x30))
                            (*(int **)((int)this + 0x2a3d4),param_1,param_2,param_3,param_3,0x4b);
          if (-1 < iVar1) {
            *param_4 = 0x4b;
            return 1;
          }
        }
      }
      if ((*(uint *)((int)this + 0x2a590) < 0x19) && (*(uint *)((int)this + 0x2a594) < 5)) {
        iVar1 = (**(code **)(**(int **)((int)this + 0x2a3d4) + 0x28))
                          (*(int **)((int)this + 0x2a3d4),param_1,param_2,param_3,2,1,0x4f);
        if (-1 < iVar1) {
          iVar1 = (**(code **)(**(int **)((int)this + 0x2a3d4) + 0x30))
                            (*(int **)((int)this + 0x2a3d4),param_1,param_2,param_3,param_3,0x4f);
          if (-1 < iVar1) {
            *param_4 = 0x4f;
            return 1;
          }
        }
      }
    }
  }
  if ((*(uint *)((int)this + 0x2a590) < 0x21) && (*(int *)((int)this + 0x2a594) == 0)) {
    puVar2 = param_2;
    iVar1 = (**(code **)(**(int **)((int)this + 0x2a3d4) + 0x28))
                      (*(int **)((int)this + 0x2a3d4),param_1,param_2,param_3,2,1,0x47);
    if (-1 < iVar1) {
      iVar1 = (**(code **)(**(int **)((int)this + 0x2a3d4) + 0x30))
                        (*(int **)((int)this + 0x2a3d4),param_1,param_2,param_3,param_3,0x47);
      if (-1 < iVar1) {
        *puVar2 = 0x47;
        return 1;
      }
    }
  }
  return 0;
}



/* ===== FUN_1000de50 @ 0x1000DE50 ===== */

LRESULT __thiscall FUN_1000de50(void *this,HWND param_1,uint param_2,uint param_3,int param_4)

{
  LPRECT lpRect;
  int iVar1;
  HMENU hMenu;
  int iVar2;
  int iVar3;
  LRESULT LVar4;
  tagPOINT local_10 [2];
  
  if (0x112 < param_2) {
    switch(param_2) {
    case 0x200:
      if (((*(int *)((int)this + 0x2a388) != 0) && (*(int *)((int)this + 0x2a38c) != 0)) &&
         (*(int *)((int)this + 0x2a3d8) != 0)) {
        GetCursorPos(local_10);
        ScreenToClient(*(HWND *)((int)this + 0x2a3cc),local_10);
        (**(code **)(**(int **)((int)this + 0x2a3d8) + 0x2c))
                  (*(int **)((int)this + 0x2a3d8),local_10[0].x,local_10[0].y,0);
      }
      break;
    case 0x211:
      (**(code **)(*(int *)this + 0x34))(1);
      break;
    case 0x212:
      (**(code **)(*(int *)this + 0x34))(0);
      break;
    case 0x218:
      if (param_3 == 0) {
        return 1;
      }
      if (param_3 == 7) {
        return 1;
      }
      break;
    case 0x231:
      if (*(int *)((int)this + 0x2a390) != 0) {
        FUN_1000fa90(2);
      }
      break;
    case 0x232:
      if (*(int *)((int)this + 0x2a390) != 0) {
        FUN_1000fa90(1);
      }
      if ((*(int *)((int)this + 0x2a388) != 0) && (*(int *)((int)this + 0x2a384) != 0)) {
        lpRect = (LPRECT)((int)this + 0x2a4e8);
        local_10[0].x = lpRect->left;
        local_10[0].y = *(int *)((int)this + 0x2a4ec);
        iVar3 = *(int *)((int)this + 0x2a4f0);
        iVar1 = *(int *)((int)this + 0x2a4f4);
        GetWindowRect(*(HWND *)((int)this + 0x2a3cc),(LPRECT)((int)this + 0x2a4d8));
        GetClientRect(*(HWND *)((int)this + 0x2a3cc),lpRect);
        iVar2 = *(int *)((int)this + 0x2a4f0) - lpRect->left;
        if ((iVar3 - local_10[0].x != iVar2) ||
           (iVar1 - local_10[0].y != *(int *)((int)this + 0x2a4f4) - *(int *)((int)this + 0x2a4ec)))
        {
          *(int *)((int)this + 0x2a398) = iVar2;
          *(undefined4 *)((int)this + 0x2a38c) = 0;
          *(int *)((int)this + 0x2a39c) =
               *(int *)((int)this + 0x2a4f4) - *(int *)((int)this + 0x2a4ec);
          iVar3 = FUN_1000e670(this);
          if (iVar3 < 0) {
            FUN_1000eb70(this,-0x7dfffff4,1);
            return 0;
          }
          *(undefined4 *)((int)this + 0x2a38c) = 1;
        }
      }
    }
    goto switchD_1000de83_caseD_6;
  }
  if (param_2 == 0x112) {
    if (param_3 < 0xf031) {
      if ((param_3 != 0xf030) && ((param_3 != 0xf000 && (param_3 != 0xf010))))
      goto switchD_1000de83_caseD_6;
    }
    else if ((param_3 != 0xf100) && (param_3 != 0xf170)) goto switchD_1000de83_caseD_6;
switchD_1000de83_caseD_84:
    if (*(int *)((int)this + 0x2a384) == 0) {
      return 1;
    }
  }
  else {
    switch(param_2) {
    case 5:
      if ((param_3 == 4) || (param_3 == 1)) {
        *(undefined4 *)((int)this + 0x2a388) = 0;
      }
      else {
        *(undefined4 *)((int)this + 0x2a388) = 1;
      }
      break;
    case 0x10:
      *(undefined4 *)((int)this + 0x2a388) = 0;
      *(undefined4 *)((int)this + 0x2a38c) = 0;
      if (*(int *)((int)this + 0x2a3d8) != 0) {
        (**(code **)(*(int *)this + 0x1c))();
        (**(code **)(*(int *)this + 0x20))();
        (**(code **)(**(int **)((int)this + 0x2a3d8) + 8))(*(int **)((int)this + 0x2a3d8));
        (**(code **)(**(int **)((int)this + 0x2a3d4) + 8))(*(int **)((int)this + 0x2a3d4));
        *(undefined4 *)((int)this + 0x2a3d8) = 0;
        *(undefined4 *)((int)this + 0x2a3d4) = 0;
      }
      (**(code **)(*(int *)this + 0x24))();
      hMenu = GetMenu(param_1);
      DestroyMenu(hMenu);
      DestroyWindow(param_1);
      PostQuitMessage(0);
      return 0;
    case 0x20:
      if (((*(int *)((int)this + 0x2a388) != 0) && (*(int *)((int)this + 0x2a38c) != 0)) &&
         (*(int *)((int)this + 0x2a384) == 0)) {
        SetCursor((HCURSOR)0x0);
        if (*(int *)((int)this + 0x2a5a0) != 0) {
          (**(code **)(**(int **)((int)this + 0x2a3d8) + 0x30))(*(int **)((int)this + 0x2a3d8),1);
        }
        return 1;
      }
      break;
    case 0x24:
      *(undefined4 *)(param_4 + 0x18) = 100;
      *(undefined4 *)(param_4 + 0x1c) = 100;
      break;
    case 0x84:
      goto switchD_1000de83_caseD_84;
    }
  }
switchD_1000de83_caseD_6:
  LVar4 = DefWindowProcA(param_1,param_2,param_3,param_4);
  return LVar4;
}



/* ===== FUN_1000e2c0 @ 0x1000E2C0 ===== */

int __fastcall FUN_1000e2c0(int *param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  LPCSTR lpString2;
  char *lpString2_00;
  int *piVar6;
  int iStack_28;
  uint uStack_24;
  int *piStack_20;
  int *piStack_1c;
  
  iVar1 = param_1[0xa8e0];
  piVar4 = param_1 + iVar1 * 0x10e3 + param_1[iVar1 * 0x10e3 + 0x10e3] * 0x32a + 0x111;
  piVar6 = piVar4 + piVar4[0x327] * 5 + 0x39;
  piStack_1c = (int *)0x1000e307;
  (**(code **)*param_1)();
  piStack_20 = param_1 + 0xa8e6;
  piVar5 = piStack_20;
  for (iVar3 = 0xd; iVar3 != 0; iVar3 = iVar3 + -1) {
    *piVar5 = 0;
    piVar5 = piVar5 + 1;
  }
  param_1[0xa8ed] = piVar4[0x328];
  param_1[0xa8e9] = 2;
  param_1[0xa8ea] = piVar4[0x329];
  param_1[0xa8ee] = param_1[0xa963];
  param_1[0xa8eb] = 1;
  param_1[0xa8ef] = piVar6[4];
  param_1[0xa8ec] = param_1[0xa8f3];
  if (param_1[0xa8e1] == 0) {
    *piStack_20 = *piVar6;
    param_1[0xa8e7] = piVar6[1];
    param_1[0xa8e8] = piVar6[2];
  }
  else {
    *piStack_20 = param_1[0xa93c] - param_1[0xa93a];
    param_1[0xa8e7] = param_1[0xa93d] - param_1[0xa93b];
    param_1[0xa8e8] = param_1[iVar1 * 0x10e3 + 0x10f];
  }
  piStack_1c = param_1 + 0xa8f6;
  iStack_28 = param_1[0xa8f4];
  uStack_24 = piVar6[3] | 4;
  iVar1 = *piVar4;
  iVar3 = (**(code **)(*(int *)param_1[0xa8f5] + 0x3c))((int *)param_1[0xa8f5],param_1[0xa8e0]);
  if (iVar3 < 0) goto LAB_1000e5e6;
  if (param_1[0xa8e1] != 0) {
    SetWindowPos((HWND)param_1[0xa8f3],(HWND)0x0,param_1[0xa936],param_1[0xa937],
                 param_1[0xa938] - param_1[0xa936],param_1[0xa939] - param_1[0xa937],0x40);
  }
  piVar5 = param_1 + 0xa8f7;
  (**(code **)(*(int *)param_1[0xa8f6] + 0x1c))((int *)param_1[0xa8f6]);
  param_1[0xa934] = piVar6[3];
  iVar3 = *piVar4;
  if (iVar3 == 2) {
    lpString2 = &DAT_1001e8e4;
LAB_1000e481:
    lstrcpyA((LPSTR)(param_1 + 0xa941),lpString2);
  }
  else {
    if (iVar3 == 1) {
      lpString2 = &DAT_1001e8e8;
      goto LAB_1000e481;
    }
    if (iVar3 == 3) {
      lpString2 = &DAT_1001e968;
      goto LAB_1000e481;
    }
  }
  uVar2 = piVar6[3];
  if (((uVar2 & 0x40) == 0) || ((uVar2 & 0x10) == 0)) {
    if ((uVar2 & 0x40) != 0) {
      if (*piVar4 == 1) {
        lpString2_00 = s__hw_vp__1001e934;
      }
      else {
        lpString2_00 = s__simulated_hw_vp__1001e920;
      }
      goto LAB_1000e50b;
    }
    if ((char)uVar2 < '\0') {
      if (*piVar4 == 1) {
        lpString2_00 = s__mixed_vp__1001e914;
      }
      else {
        lpString2_00 = s__simulated_mixed_vp__1001e8fc;
      }
      goto LAB_1000e50b;
    }
    if ((uVar2 & 0x20) != 0) {
      lpString2_00 = s__sw_vp__1001e8f0;
      goto LAB_1000e50b;
    }
  }
  else {
    if (*piVar4 == 1) {
      lpString2_00 = s__pure_hw_vp__1001e958;
    }
    else {
      lpString2_00 = s__simulated_pure_hw_vp__1001e940;
    }
LAB_1000e50b:
    lstrcatA((LPSTR)(param_1 + 0xa941),lpString2_00);
  }
  if (*piVar4 == 1) {
    lstrcatA((LPSTR)(param_1 + 0xa941),&DAT_1001e8ec);
    lstrcatA((LPSTR)(param_1 + 0xa941),(LPCSTR)(iVar1 + 0x200));
  }
  piVar6 = &iStack_28;
  (**(code **)(*(int *)param_1[0xa8f6] + 0x40))((int *)param_1[0xa8f6],0,0);
  (**(code **)(*piVar5 + 0x20))(piVar5,param_1 + 0xa92c);
  (**(code **)(*piVar6 + 8))(piVar6);
  if ((param_1[0xa968] != 0) && (param_1[0xa8e1] == 0)) {
    GetClassLongA((HWND)param_1[0xa8f3],-0xc);
    (**(code **)(*(int *)param_1[0xa8f6] + 0x30))((int *)param_1[0xa8f6],1);
  }
  iVar3 = (**(code **)(*param_1 + 0xc))();
  if ((-1 < iVar3) && (iVar3 = (**(code **)(*param_1 + 0x10))(), -1 < iVar3)) {
    param_1[0xa8e2] = 1;
    return 0;
  }
  (**(code **)(*param_1 + 0x1c))();
  (**(code **)(*param_1 + 0x20))();
  piVar6 = (int *)param_1[0xa8f6];
  if (piVar6 != (int *)0x0) {
    (**(code **)(*piVar6 + 8))(piVar6);
    param_1[0xa8f6] = 0;
  }
LAB_1000e5e6:
  if (*piVar4 == 1) {
    FUN_1000eb70(param_1,iVar3,2);
    uVar2 = 0;
    param_1[0xa8e0] = 0;
    if (param_1[0x110] != 0) {
      piVar4 = param_1 + 0x111;
      do {
        if (*piVar4 == 2) {
          param_1[0x10e3] = uVar2;
          param_1[0xa8e1] = param_1[uVar2 * 0x32a + 0x439];
          break;
        }
        uVar2 = uVar2 + 1;
        piVar4 = piVar4 + 0x32a;
      } while (uVar2 < (uint)param_1[0x110]);
    }
    if (param_1[param_1[0x10e3] * 0x32a + 0x111] == 2) {
      iVar3 = FUN_1000e2c0(param_1);
    }
  }
  return iVar3;
}



/* ===== FUN_1000e670 @ 0x1000E670 ===== */

int __fastcall FUN_1000e670(int *param_1)

{
  int iVar1;
  int *piVar2;
  int *piStack_c;
  
  piStack_c = (int *)0x1000e679;
  iVar1 = (**(code **)(*param_1 + 0x1c))();
  if (-1 < iVar1) {
    piStack_c = param_1 + 0xa8e6;
    iVar1 = (**(code **)(*(int *)param_1[0xa8f6] + 0x38))((int *)param_1[0xa8f6]);
    if (-1 < iVar1) {
      piVar2 = (int *)0x0;
      (**(code **)(*(int *)param_1[0xa8f6] + 0x40))((int *)param_1[0xa8f6],0,0,&piStack_c);
      (**(code **)(*piVar2 + 0x20))(piVar2);
      (**(code **)(param_1[0xa92c] + 8))(param_1 + 0xa92c);
      if ((param_1[0xa968] != 0) && (param_1[0xa8e1] == 0)) {
        GetClassLongA((HWND)param_1[0xa8f3],-0xc);
        (**(code **)(*(int *)param_1[0xa8f6] + 0x30))((int *)param_1[0xa8f6],1);
      }
      iVar1 = (**(code **)(*param_1 + 0x10))();
      if (-1 < iVar1) {
        if (param_1[0xa8e4] == 0) {
          param_1[0xa8e5] = 1;
          FUN_1000fa90(1);
          FUN_1000fa90(2);
        }
        iVar1 = 0;
      }
    }
  }
  return iVar1;
}



/* ===== FUN_1000e860 @ 0x1000E860 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __fastcall FUN_1000e860(int *param_1)

{
  LPSTR lpString1;
  int iVar1;
  float10 fVar2;
  float10 fVar3;
  
  iVar1 = (**(code **)(*(int *)param_1[0xa8f6] + 0xc))((int *)param_1[0xa8f6]);
  if (iVar1 < 0) {
    if (iVar1 == -0x7789f798) {
      return 0;
    }
    if (iVar1 == -0x7789f797) {
      if (param_1[0xa8e1] != 0) {
        iVar1 = param_1[0xa8e0];
        (**(code **)(*(int *)param_1[0xa8f5] + 0x20))();
        param_1[0xa8e8] = param_1[iVar1 * 0x10e3 + 0x10f];
      }
      iVar1 = FUN_1000e670(param_1);
      return iVar1;
    }
    return iVar1;
  }
  fVar2 = FUN_1000fa90(5);
  fVar3 = FUN_1000fa90(6);
  if ((float10)0.0 == fVar3) {
    if (param_1[0xa8e4] != 0) {
      return 0;
    }
LAB_1000e911:
    if (param_1[0xa8e5] == 0) goto LAB_1000e948;
  }
  else if (param_1[0xa8e4] == 0) goto LAB_1000e911;
  param_1[0xa93f] = (int)(float)fVar3;
  param_1[0xa93e] = (int)(float)fVar2;
  iVar1 = (**(code **)(*param_1 + 0x14))();
  if (iVar1 < 0) {
    return iVar1;
  }
  param_1[0xa8e5] = 0;
LAB_1000e948:
  iVar1 = (**(code **)(*param_1 + 0x18))();
  if (-1 < iVar1) {
    fVar2 = FUN_1000fa90(4);
    DAT_10024768 = DAT_10024768 + 1;
    if ((float10)1.0 < fVar2 - (float10)_DAT_10024764) {
      param_1[0xa940] = (int)(float)((float10)DAT_10024768 / (fVar2 - (float10)_DAT_10024764));
      DAT_10024768 = 0;
      _DAT_10024764 = (float)fVar2;
      (**(code **)(*(int *)param_1[0xa8f5] + 0x20))
                ((int *)param_1[0xa8f5],param_1[0xa8e0],&stack0xffffffec);
      lpString1 = (LPSTR)((int)param_1 + 0x2a55e);
      FUN_1000feb4(lpString1,(byte *)s___02f_fps___dx_dx_d__1001e9ac);
      if (param_1[0xa963] != 0) {
        iVar1 = param_1[0xa8e0];
        switch(param_1[iVar1 * 0x10e3 +
                       param_1[iVar1 * 0x10e3 + 0x10e3] * 0x32a +
                       param_1[iVar1 * 0x10e3 + param_1[iVar1 * 0x10e3 + 0x10e3] * 0x32a + 0x438] *
                       5 + 0x14e]) {
        case 0x47:
          lstrcatA(lpString1,s__D32__1001e96c);
          break;
        case 0x49:
          lstrcatA(lpString1,s__D15S1__1001e998);
          break;
        case 0x4b:
          lstrcatA(lpString1,s__D24S8__1001e980);
          break;
        case 0x4d:
          lstrcatA(lpString1,s__D24X8__1001e98c);
          break;
        case 0x4f:
          lstrcatA(lpString1,s__D24X4S4__1001e974);
          break;
        case 0x50:
          lstrcatA(lpString1,s__D16__1001e9a4);
        }
      }
    }
    (**(code **)(*(int *)param_1[0xa8f6] + 0x3c))((int *)param_1[0xa8f6],0,0,0,0);
    return 0;
  }
  return iVar1;
}



/* ===== FUN_1000eb70 @ 0x1000EB70 ===== */

int __thiscall FUN_1000eb70(void *this,int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  LPCSTR lpCaption;
  UINT uType;
  char local_200 [512];
  
  if (param_1 < -0x7dfffff8) {
    if (param_1 == -0x7dfffff9) {
      iVar2 = 0;
      do {
        cVar1 = s_Your_Direct3D_hardware_accelerat_1001ed20[iVar2];
        local_200[iVar2] = cVar1;
        iVar2 = iVar2 + 1;
      } while (cVar1 != '\0');
      goto LAB_1000ed32;
    }
    if (param_1 < -0x7dfffffb) {
      if (param_1 == -0x7dfffffc) {
        iVar2 = 0;
        do {
          cVar1 = s_This_sample_cannot_run_in_a_desk_1001ee48[iVar2];
          local_200[iVar2] = cVar1;
          iVar2 = iVar2 + 1;
        } while (cVar1 != '\0');
        goto LAB_1000ed32;
      }
      if (param_1 == -0x7ff8fff2) {
        iVar2 = 0;
        do {
          cVar1 = s_Not_enough_memory__1001eef4[iVar2];
          local_200[iVar2] = cVar1;
          iVar2 = iVar2 + 1;
        } while (cVar1 != '\0');
        goto LAB_1000ed32;
      }
      if (param_1 == -0x7dffffff) {
        iVar2 = 0;
        do {
          cVar1 = s_Could_not_initialize_Direct3D__Y_1001ef08[iVar2];
          local_200[iVar2] = cVar1;
          iVar2 = iVar2 + 1;
        } while (cVar1 != '\0');
        goto LAB_1000ed32;
      }
      if (param_1 == -0x7dfffffd) {
        iVar2 = 0;
        do {
          cVar1 = s_Could_not_find_any_compatible_Di_1001eff0[iVar2];
          local_200[iVar2] = cVar1;
          iVar2 = iVar2 + 1;
        } while (cVar1 != '\0');
        goto LAB_1000ed32;
      }
    }
    else {
      if (param_1 == -0x7dfffffb) {
        iVar2 = 0;
        do {
          cVar1 = s_No_hardware_accelerated_Direct3D_1001edb0[iVar2];
          local_200[iVar2] = cVar1;
          iVar2 = iVar2 + 1;
        } while (cVar1 != '\0');
        goto LAB_1000ed32;
      }
      if (param_1 == -0x7dfffffa) {
        iVar2 = 0;
        do {
          cVar1 = s_This_sample_requires_functionali_1001ede8[iVar2];
          local_200[iVar2] = cVar1;
          iVar2 = iVar2 + 1;
        } while (cVar1 != '\0');
        goto LAB_1000ed32;
      }
    }
  }
  else if (param_1 < -0x7789fe83) {
    if (param_1 == -0x7789fe84) {
      iVar2 = 0;
      do {
        cVar1 = s_Not_enough_video_memory__1001eabc[iVar2];
        local_200[iVar2] = cVar1;
        iVar2 = iVar2 + 1;
      } while (cVar1 != '\0');
      goto LAB_1000ed32;
    }
    switch(param_1) {
    case -0x7dfffff8:
      iVar2 = 0;
      do {
        cVar1 = s_Your_Direct3D_hardware_accelerat_1001ec60[iVar2];
        local_200[iVar2] = cVar1;
        iVar2 = iVar2 + 1;
      } while (cVar1 != '\0');
      break;
    case -0x7dfffff7:
      iVar2 = 0;
      do {
        cVar1 = s_This_sample_requires_functionali_1001eb80[iVar2];
        local_200[iVar2] = cVar1;
        iVar2 = iVar2 + 1;
      } while (cVar1 != '\0');
      break;
    case -0x7dfffff6:
      iVar2 = 0;
      do {
        cVar1 = s_A_D3D_object_has_a_non_zero_refe_1001ead8[iVar2];
        local_200[iVar2] = cVar1;
        iVar2 = iVar2 + 1;
      } while (cVar1 != '\0');
      break;
    case -0x7dfffff5:
      iVar2 = 0;
      do {
        cVar1 = s_Could_not_load_required_media__1001eb5c[iVar2];
        local_200[iVar2] = cVar1;
        iVar2 = iVar2 + 1;
      } while (cVar1 != '\0');
      break;
    case -0x7dfffff4:
      iVar2 = 0;
      do {
        cVar1 = s_Could_not_reset_the_Direct3D_dev_1001eb34[iVar2];
        local_200[iVar2] = cVar1;
        iVar2 = iVar2 + 1;
      } while (cVar1 != '\0');
      break;
    default:
      goto switchD_1000ec95_default;
    }
    goto LAB_1000ed32;
  }
switchD_1000ec95_default:
  iVar2 = 0;
  do {
    cVar1 = s_Generic_application_error__Enabl_1001ea70[iVar2];
    local_200[iVar2] = cVar1;
    iVar2 = iVar2 + 1;
  } while (cVar1 != '\0');
LAB_1000ed32:
  if (param_2 == 1) {
    iVar2 = -1;
    pcVar3 = local_200;
    do {
      pcVar4 = pcVar3;
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      pcVar4 = pcVar3 + 1;
      cVar1 = *pcVar3;
      pcVar3 = pcVar4;
    } while (cVar1 != '\0');
    lpCaption = *(LPCSTR *)((int)this + 0x2a588);
    pcVar3 = s_This_sample_will_now_exit__1001ea4c;
    pcVar4 = pcVar4 + -1;
    for (iVar2 = 7; iVar2 != 0; iVar2 = iVar2 + -1) {
      *(undefined4 *)pcVar4 = *(undefined4 *)pcVar3;
      pcVar3 = pcVar3 + 4;
      pcVar4 = pcVar4 + 4;
    }
    uType = 0x10;
    *pcVar4 = *pcVar3;
  }
  else {
    if (param_2 == 2) {
      iVar2 = -1;
      pcVar3 = local_200;
      do {
        pcVar4 = pcVar3;
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        pcVar4 = pcVar3 + 1;
        cVar1 = *pcVar3;
        pcVar3 = pcVar4;
      } while (cVar1 != '\0');
      pcVar3 = s_Switching_to_the_reference_raste_1001e9c8;
      pcVar4 = pcVar4 + -1;
      for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
        *(undefined4 *)pcVar4 = *(undefined4 *)pcVar3;
        pcVar3 = pcVar3 + 4;
        pcVar4 = pcVar4 + 4;
      }
      *(undefined2 *)pcVar4 = *(undefined2 *)pcVar3;
    }
    lpCaption = *(LPCSTR *)((int)this + 0x2a588);
    uType = 0x30;
  }
  MessageBoxA((HWND)0x0,local_200,lpCaption,uType);
  return param_1;
}



/* ===== FUN_1000edc0 @ 0x1000EDC0 ===== */

void __thiscall FUN_1000edc0(void *this,char *param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (int)this - (int)param_1;
  do {
    cVar1 = *param_1;
    param_1[iVar2] = cVar1;
    param_1 = param_1 + 1;
  } while (cVar1 != '\0');
  *(undefined4 *)((int)this + 0x50) = param_2;
  *(undefined4 *)((int)this + 0x54) = param_3;
  *(undefined4 *)((int)this + 0x58) = 0;
  *(undefined4 *)((int)this + 0x5c) = 0;
  *(undefined4 *)((int)this + 0x60) = 0;
  *(undefined4 *)((int)this + 0x670) = 0;
  *(undefined4 *)((int)this + 0x674) = 0;
  return;
}



/* ===== FUN_1000ee10 @ 0x1000EE10 ===== */

void __fastcall FUN_1000ee10(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x60);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(param_1 + 0x60) = 0;
  }
  piVar1 = *(int **)(param_1 + 0x58);
  if (piVar1 != (int *)0x0) {
    if (*(int *)(param_1 + 0x670) != 0) {
      (**(code **)(*piVar1 + 0xe0))(piVar1,*(int *)(param_1 + 0x670));
    }
    if (*(int *)(param_1 + 0x674) != 0) {
      (**(code **)(**(int **)(param_1 + 0x58) + 0xe0))
                (*(int **)(param_1 + 0x58),*(int *)(param_1 + 0x674));
    }
  }
  piVar1 = *(int **)(param_1 + 0x5c);
  *(undefined4 *)(param_1 + 0x670) = 0;
  *(undefined4 *)(param_1 + 0x674) = 0;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(param_1 + 0x5c) = 0;
  }
  *(undefined4 *)(param_1 + 0x58) = 0;
  return;
}



/* ===== FUN_1000ee80 @ 0x1000EE80 ===== */

/* WARNING: Type propagation algorithm not settling */

int __thiscall FUN_1000ee80(void *this,int *param_1)

{
  LONG LVar1;
  undefined1 uVar2;
  char cVar3;
  int iVar4;
  HDC hdc;
  HBITMAP h;
  HFONT h_00;
  uint uVar5;
  undefined4 uVar6;
  ushort *puVar7;
  uint uVar8;
  float *pfVar9;
  int unaff_EDI;
  BITMAPINFO *pBVar10;
  undefined1 *x;
  uint uVar11;
  longlong lVar12;
  HGDIOBJ ho;
  undefined4 uStack_194;
  HGDIOBJ pvStack_190;
  HFONT pHStack_18c;
  int iStack_188;
  int *piStack_184;
  undefined1 *puStack_180;
  undefined1 auStack_130 [8];
  BITMAPINFO BStack_128;
  undefined1 local_d4 [80];
  uint uStack_84;
  
  *(int **)((int)this + 0x58) = param_1;
  *(undefined4 *)((int)this + 0x6c) = 0x3f800000;
  if (*(uint *)((int)this + 0x50) < 0x29) {
    uVar6 = 0x200;
    if (*(uint *)((int)this + 0x50) < 0x15) {
      uVar6 = 0x100;
    }
  }
  else {
    uVar6 = 0x400;
  }
  puStack_180 = local_d4;
  *(undefined4 *)((int)this + 0x68) = uVar6;
  *(undefined4 *)((int)this + 100) = uVar6;
  piStack_184 = param_1;
  iStack_188 = 0x1000eecc;
  (**(code **)(*param_1 + 0x1c))();
  uVar11 = *(uint *)((int)this + 100);
  if (uStack_84 < uVar11) {
    *(uint *)((int)this + 0x68) = uStack_84;
    *(uint *)((int)this + 100) = uStack_84;
    *(float *)((int)this + 0x6c) = (float)uStack_84 / (float)(int)uVar11;
  }
  iStack_188 = (int)this + 0x5c;
  pHStack_18c = (HFONT)0x1;
  pvStack_190 = (HGDIOBJ)0x1a;
  uStack_194 = 0;
  iVar4 = (**(code **)(**(int **)((int)this + 0x58) + 0x50))
                    (*(int **)((int)this + 0x58),*(undefined4 *)((int)this + 100),
                     *(undefined4 *)((int)this + 0x68));
  if (-1 < iVar4) {
    LVar1 = *(LONG *)((int)this + 100);
    pBVar10 = &BStack_128;
    for (iVar4 = 10; iVar4 != 0; iVar4 = iVar4 + -1) {
      (pBVar10->bmiHeader).biSize = 0;
      pBVar10 = (BITMAPINFO *)&(pBVar10->bmiHeader).biWidth;
    }
    BStack_128.bmiHeader.biHeight = -*(int *)((int)this + 0x68);
    BStack_128.bmiHeader.biSize = 0x28;
    BStack_128.bmiHeader.biPlanes = 1;
    BStack_128.bmiHeader.biCompression = 0;
    BStack_128.bmiHeader.biBitCount = 0x20;
    BStack_128.bmiHeader.biWidth = LVar1;
    hdc = CreateCompatibleDC((HDC)0x0);
    h = CreateDIBSection(hdc,&BStack_128,0,(void **)&stack0xfffffe88,(HANDLE)0x0,0);
    SetMapMode(hdc,1);
    iVar4 = 0x48;
    pvStack_190 = (HGDIOBJ)GetDeviceCaps(hdc,0x5a);
    lVar12 = __ftol();
    iVar4 = MulDiv(*(int *)((int)this + 0x50),(int)lVar12,iVar4);
    h_00 = CreateFontA(-iVar4,0,0,0,(-(uint)((*(uint *)((int)this + 0x54) & 1) != 0) & 300) + 400,
                       *(uint *)((int)this + 0x54) >> 1 & 1,0,0,1,0,0,4,2,this);
    if (h_00 == (HFONT)0x0) {
      return -0x7fffbffb;
    }
    pHStack_18c = h_00;
    SelectObject(hdc,h);
    SelectObject(hdc,h_00);
    SetTextColor(hdc,0xffffff);
    x = (undefined1 *)0x0;
    SetBkColor(hdc,0);
    SetTextAlign(hdc,0);
    pvStack_190 = (HGDIOBJ)0x0;
    uStack_194._0_2_ = CONCAT11(0x20,(undefined1)uStack_194);
    uStack_194 = CONCAT22(DAT_1001f020,(undefined2)uStack_194);
    pfVar9 = (float *)((int)this + 0x74);
    do {
      uVar2 = uStack_194._1_1_;
      uStack_194._0_3_ = CONCAT12(uVar2,(undefined2)uStack_194);
      GetTextExtentPoint32A(hdc,(LPCSTR)((int)&uStack_194 + 2),1,(LPSIZE)&puStack_180);
      if (*(undefined1 **)((int)this + 100) < puStack_180 + 1 + (int)x) {
        pvStack_190 = (HGDIOBJ)((int)pvStack_190 + unaff_EDI + 1);
        x = (undefined1 *)0x0;
      }
      ExtTextOutA(hdc,(int)x,(int)pvStack_190,2,(RECT *)0x0,(LPCSTR)((int)&uStack_194 + 2),1,
                  (INT *)0x0);
      pfVar9[-1] = (float)x / (float)*(int *)((int)this + 100);
      puVar7 = *(ushort **)((int)this + 0x68);
      *pfVar9 = (float)pvStack_190 / (float)(int)puVar7;
      pfVar9[1] = (float)(puStack_180 + (int)x) / (float)*(int *)((int)this + 100);
      cVar3 = uStack_194._1_1_ + '\x01';
      uStack_194._0_2_ = CONCAT11(cVar3,(undefined1)uStack_194);
      pfVar9[2] = (float)(uint)(unaff_EDI + (int)pvStack_190) / (float)*(int *)((int)this + 0x68);
      x = x + 1 + (int)puStack_180;
      pfVar9 = pfVar9 + 4;
    } while (cVar3 < '\x7f');
    ho = (HGDIOBJ)0x0;
    (**(code **)(*(int *)*piStack_184 + 0x40))((int *)*piStack_184,0,auStack_130,0);
    uVar11 = 0;
    if (*(int *)((int)this + 0x68) != 0) {
      do {
        uVar5 = *(uint *)((int)this + 100);
        uVar8 = 0;
        if (uVar5 != 0) {
          do {
            uVar5 = (uint)pHStack_18c[uVar5 * uVar11 + uVar8].unused >> 4;
            if ((uVar5 & 0xf) == 0) {
              *puVar7 = 0;
            }
            else {
              *puVar7 = (ushort)((byte)uVar5 & 0xf) << 0xc | 0xfff;
            }
            uVar5 = *(uint *)((int)this + 100);
            puVar7 = puVar7 + 1;
            uVar8 = uVar8 + 1;
          } while (uVar8 < uVar5);
        }
        uVar11 = uVar11 + 1;
      } while (uVar11 < *(uint *)((int)this + 0x68));
    }
    (**(code **)(*piRam00000001 + 0x44))(piRam00000001,0);
    DeleteObject(pvStack_190);
    DeleteDC(hdc);
    DeleteObject(ho);
    iVar4 = 0;
  }
  return iVar4;
}



/* ===== FUN_1000f210 @ 0x1000F210 ===== */

int __fastcall FUN_1000f210(int param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = (**(code **)(**(int **)(param_1 + 0x58) + 0x5c))
                    (*(int **)(param_1 + 0x58),0x20d0,0x208,0,0,param_1 + 0x60);
  if (-1 < iVar1) {
    uVar2 = 0;
    do {
      (**(code **)(**(int **)(param_1 + 0x58) + 0xd0))(*(int **)(param_1 + 0x58));
      (**(code **)(**(int **)(param_1 + 0x58) + 0xf4))
                (*(int **)(param_1 + 0x58),0,*(undefined4 *)(param_1 + 0x5c));
      (**(code **)(**(int **)(param_1 + 0x58) + 200))(*(int **)(param_1 + 0x58),0x1b,1);
      (**(code **)(**(int **)(param_1 + 0x58) + 200))(*(int **)(param_1 + 0x58),0x13,5);
      (**(code **)(**(int **)(param_1 + 0x58) + 200))(*(int **)(param_1 + 0x58),0x14,6);
      (**(code **)(**(int **)(param_1 + 0x58) + 200))(*(int **)(param_1 + 0x58),0xf,1);
      (**(code **)(**(int **)(param_1 + 0x58) + 200))(*(int **)(param_1 + 0x58),0x18,8);
      (**(code **)(**(int **)(param_1 + 0x58) + 200))(*(int **)(param_1 + 0x58),0x19,7);
      (**(code **)(**(int **)(param_1 + 0x58) + 200))(*(int **)(param_1 + 0x58),8,3);
      (**(code **)(**(int **)(param_1 + 0x58) + 200))(*(int **)(param_1 + 0x58),0x16,3);
      (**(code **)(**(int **)(param_1 + 0x58) + 200))(*(int **)(param_1 + 0x58),7,0);
      (**(code **)(**(int **)(param_1 + 0x58) + 200))(*(int **)(param_1 + 0x58),0x34,0);
      (**(code **)(**(int **)(param_1 + 0x58) + 200))(*(int **)(param_1 + 0x58),0x88,1);
      (**(code **)(**(int **)(param_1 + 0x58) + 200))(*(int **)(param_1 + 0x58),0x28,0);
      (**(code **)(**(int **)(param_1 + 0x58) + 200))(*(int **)(param_1 + 0x58),0x98,0);
      (**(code **)(**(int **)(param_1 + 0x58) + 200))(*(int **)(param_1 + 0x58),0x97,0);
      (**(code **)(**(int **)(param_1 + 0x58) + 200))(*(int **)(param_1 + 0x58),0xa7,0);
      (**(code **)(**(int **)(param_1 + 0x58) + 200))(*(int **)(param_1 + 0x58),0x1c,0);
      (**(code **)(**(int **)(param_1 + 0x58) + 0xfc))(*(int **)(param_1 + 0x58),0,1,4);
      (**(code **)(**(int **)(param_1 + 0x58) + 0xfc))(*(int **)(param_1 + 0x58),0,2,2);
      (**(code **)(**(int **)(param_1 + 0x58) + 0xfc))(*(int **)(param_1 + 0x58),0,3,0);
      (**(code **)(**(int **)(param_1 + 0x58) + 0xfc))(*(int **)(param_1 + 0x58),0,4,4);
      (**(code **)(**(int **)(param_1 + 0x58) + 0xfc))(*(int **)(param_1 + 0x58),0,5,2);
      (**(code **)(**(int **)(param_1 + 0x58) + 0xfc))(*(int **)(param_1 + 0x58),0,6,0);
      (**(code **)(**(int **)(param_1 + 0x58) + 0xfc))(*(int **)(param_1 + 0x58),0,0x11,1);
      (**(code **)(**(int **)(param_1 + 0x58) + 0xfc))(*(int **)(param_1 + 0x58),0,0x10,1);
      (**(code **)(**(int **)(param_1 + 0x58) + 0xfc))(*(int **)(param_1 + 0x58),0,0x12,0);
      (**(code **)(**(int **)(param_1 + 0x58) + 0xfc))(*(int **)(param_1 + 0x58),0,0xb,0);
      (**(code **)(**(int **)(param_1 + 0x58) + 0xfc))(*(int **)(param_1 + 0x58),0,0x18,0);
      (**(code **)(**(int **)(param_1 + 0x58) + 0xfc))(*(int **)(param_1 + 0x58),1,1,1);
      (**(code **)(**(int **)(param_1 + 0x58) + 0xfc))(*(int **)(param_1 + 0x58),1,4,1);
      iVar1 = param_1 + 0x670;
      if (uVar2 != 0) {
        iVar1 = param_1 + 0x674;
      }
      (**(code **)(**(int **)(param_1 + 0x58) + 0xd4))(*(int **)(param_1 + 0x58),iVar1);
      uVar2 = uVar2 + 1;
    } while (uVar2 < 2);
    iVar1 = 0;
  }
  return iVar1;
}



/* ===== FUN_1000f480 @ 0x1000F480 ===== */

undefined4 __fastcall FUN_1000f480(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x60);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(param_1 + 0x60) = 0;
  }
  piVar1 = *(int **)(param_1 + 0x58);
  if (piVar1 != (int *)0x0) {
    if (*(int *)(param_1 + 0x670) != 0) {
      (**(code **)(*piVar1 + 0xe0))(piVar1,*(int *)(param_1 + 0x670));
    }
    if (*(int *)(param_1 + 0x674) != 0) {
      (**(code **)(**(int **)(param_1 + 0x58) + 0xe0))
                (*(int **)(param_1 + 0x58),*(int *)(param_1 + 0x674));
    }
  }
  *(undefined4 *)(param_1 + 0x670) = 0;
  *(undefined4 *)(param_1 + 0x674) = 0;
  return 0;
}



/* ===== FUN_1000f4f0 @ 0x1000F4F0 ===== */

undefined4 __fastcall FUN_1000f4f0(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x5c);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(param_1 + 0x5c) = 0;
  }
  *(undefined4 *)(param_1 + 0x58) = 0;
  return 0;
}



/* ===== FUN_1000f520 @ 0x1000F520 ===== */

undefined4 __fastcall FUN_1000f520(int param_1)

{
  char cVar1;
  float fVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  float *pfVar6;
  int **ppiVar7;
  int *piStack_188;
  int **ppiStack_174;
  int *piStack_170;
  int *piStack_160;
  undefined4 uStack_15c;
  int *piStack_158;
  float fStack_154;
  int *piStack_150;
  undefined4 uStack_14c;
  int *piStack_148;
  float fStack_144;
  float fStack_134;
  float fStack_e4;
  int *piStack_e0;
  undefined4 uStack_dc;
  undefined4 uStack_d8;
  undefined4 uStack_d4;
  float fStack_d0;
  float fStack_cc;
  float fStack_c8;
  int *piStack_c4;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  undefined4 uStack_b8;
  float fStack_b4;
  float fStack_b0;
  float afStack_ac [5];
  float fStack_98;
  float fStack_94;
  float afStack_90 [5];
  float fStack_7c;
  float fStack_78;
  float afStack_74 [5];
  float fStack_60;
  float fStack_5c;
  float fStack_58;
  int *piStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  float fStack_44;
  float fStack_40;
  float fStack_38;
  float fStack_34;
  undefined4 uStack_30;
  char *pcStack_2c;
  byte bStack_14;
  
  piStack_148 = *(int **)(param_1 + 0x58);
  if (piStack_148 == (int *)0x0) {
    return 0x80004005;
  }
  fStack_144 = *(float *)(param_1 + 0x670);
  uStack_14c = 0x1000f553;
  (**(code **)(*piStack_148 + 0xdc))();
  uStack_14c = *(undefined4 *)(param_1 + 0x674);
  piStack_150 = *(int **)(param_1 + 0x58);
  fStack_154 = 2.5432597e-29;
  (**(code **)(*piStack_150 + 0xd8))();
  piStack_158 = *(int **)(param_1 + 0x58);
  fStack_154 = 4.54021e-43;
  uStack_15c = 0x1000f577;
  (**(code **)(*piStack_158 + 0x130))();
  piStack_160 = *(int **)(param_1 + 0x60);
  uStack_15c = 0x1c;
  (**(code **)(**(int **)(param_1 + 0x58) + 0x14c))();
  if ((bStack_14 & 4) != 0) {
    (**(code **)(**(int **)(param_1 + 0x58) + 0xfc))();
    piStack_188 = *(int **)(param_1 + 0x58);
    (**(code **)(*piStack_188 + 0xfc))();
  }
  piStack_170 = (int *)0x2000;
  ppiStack_174 = &piStack_160;
  piStack_160 = (int *)0x0;
  uStack_15c = 0;
  (**(code **)(**(int **)(param_1 + 0x60) + 0x2c))();
  cVar1 = *pcStack_2c;
  piVar3 = (int *)0x0;
  while (cVar1 != '\0') {
    pcStack_2c = pcStack_2c + 1;
    if (cVar1 == '\n') {
      fStack_38 = fStack_134;
      fStack_34 = (*(float *)(param_1 + 0x7c) - *(float *)(param_1 + 0x74)) *
                  (float)*(int *)(param_1 + 0x68) + fStack_34;
    }
    else if ('\x1f' < cVar1) {
      iVar4 = cVar1 * 0x10 + param_1;
      fStack_98 = *(float *)((cVar1 + -0x19) * 0x10 + param_1);
      iVar5 = *(int *)(param_1 + 100);
      fStack_cc = *(float *)(iVar4 + -0x18c);
      fStack_60 = *(float *)(iVar4 + -0x188);
      fStack_94 = *(float *)(iVar4 + -0x184);
      fVar2 = 1.0 / *(float *)(param_1 + 0x6c);
      afStack_ac[2] = 0.9;
      afStack_ac[4] = (float)uStack_30;
      uStack_15c = 0x3f666666;
      piStack_158 = (int *)0x3f800000;
      uStack_d4 = uStack_30;
      afStack_ac[0] = fStack_38 - 0.5;
      afStack_ac[3] = 1.0;
      afStack_ac[1] =
           ((fStack_94 - fStack_cc) * (float)*(int *)(param_1 + 0x68) * fVar2 + fStack_34) - 0.5;
      pfVar6 = afStack_ac;
      ppiVar7 = ppiStack_174;
      for (iVar4 = 7; iVar4 != 0; iVar4 = iVar4 + -1) {
        *ppiVar7 = (int *)*pfVar6;
        pfVar6 = pfVar6 + 1;
        ppiVar7 = ppiVar7 + 1;
      }
      piStack_160 = (int *)(fStack_34 - 0.5);
      fStack_d0 = fStack_98;
      fStack_e4 = afStack_ac[0];
      piStack_e0 = piStack_160;
      uStack_dc = 0x3f666666;
      uStack_d8 = 0x3f800000;
      pfVar6 = &fStack_e4;
      ppiVar7 = ppiStack_174 + 7;
      for (iVar4 = 7; iVar4 != 0; iVar4 = iVar4 + -1) {
        *ppiVar7 = (int *)*pfVar6;
        pfVar6 = pfVar6 + 1;
        ppiVar7 = ppiVar7 + 1;
      }
      fVar2 = (fStack_60 - fStack_98) * (float)iVar5 * fVar2 + fStack_38;
      fStack_154 = fVar2 - 0.5;
      afStack_74[2] = 0.9;
      afStack_74[0] = fStack_154;
      afStack_74[3] = 1.0;
      afStack_74[1] = afStack_ac[1];
      fStack_5c = fStack_94;
      afStack_74[4] = (float)uStack_30;
      pfVar6 = afStack_74;
      ppiVar7 = ppiStack_174 + 0xe;
      for (iVar5 = 7; iVar5 != 0; iVar5 = iVar5 + -1) {
        *ppiVar7 = (int *)*pfVar6;
        pfVar6 = pfVar6 + 1;
        ppiVar7 = ppiVar7 + 1;
      }
      fStack_b4 = fStack_60;
      fStack_b0 = fStack_cc;
      fStack_7c = fStack_60;
      fStack_78 = fStack_94;
      fStack_c8 = fStack_154;
      uStack_14c = 0x3f666666;
      uStack_c0 = 0x3f666666;
      piStack_148 = (int *)0x3f800000;
      piStack_c4 = piStack_160;
      uStack_bc = 0x3f800000;
      uStack_b8 = uStack_30;
      pfVar6 = &fStack_c8;
      ppiVar7 = ppiStack_174 + 0x15;
      for (iVar5 = 7; iVar5 != 0; iVar5 = iVar5 + -1) {
        *ppiVar7 = (int *)*pfVar6;
        pfVar6 = pfVar6 + 1;
        ppiVar7 = ppiVar7 + 1;
      }
      afStack_90[0] = fStack_154;
      afStack_90[1] = afStack_ac[1];
      afStack_90[2] = 0.9;
      afStack_90[3] = 1.0;
      afStack_90[4] = (float)uStack_30;
      pfVar6 = afStack_90;
      ppiVar7 = ppiStack_174 + 0x1c;
      for (iVar5 = 7; iVar5 != 0; iVar5 = iVar5 + -1) {
        *ppiVar7 = (int *)*pfVar6;
        pfVar6 = pfVar6 + 1;
        ppiVar7 = ppiVar7 + 1;
      }
      fStack_44 = fStack_98;
      fStack_58 = afStack_ac[0];
      piStack_54 = piStack_160;
      fStack_40 = fStack_cc;
      uStack_50 = 0x3f666666;
      uStack_4c = 0x3f800000;
      uStack_48 = uStack_30;
      pfVar6 = &fStack_58;
      ppiVar7 = ppiStack_174 + 0x23;
      for (iVar5 = 7; iVar5 != 0; iVar5 = iVar5 + -1) {
        *ppiVar7 = (int *)*pfVar6;
        pfVar6 = pfVar6 + 1;
        ppiVar7 = ppiVar7 + 1;
      }
      piStack_170 = (int *)((int)piStack_170 + 2);
      ppiStack_174 = ppiStack_174 + 0x2a;
      piStack_150 = piStack_160;
      fStack_144 = fStack_154;
      if (0x126 < (uint)((int)piStack_170 * 3)) {
        piStack_188 = *(int **)(param_1 + 0x60);
        (**(code **)(*piStack_188 + 0x30))();
        (**(code **)(**(int **)(param_1 + 0x58) + 0x118))(*(int **)(param_1 + 0x58),4,0,piStack_170)
        ;
        piStack_188 = (int *)0x0;
        (**(code **)(**(int **)(param_1 + 0x60) + 0x2c))
                  (*(int **)(param_1 + 0x60),0,0,&piStack_188,0x2000);
        piStack_170 = (int *)0x0;
      }
      fStack_38 = fVar2;
    }
    piVar3 = piStack_170;
    cVar1 = *pcStack_2c;
  }
  piStack_188 = (int *)0x1000fa5b;
  (**(code **)(**(int **)(param_1 + 0x60) + 0x30))();
  if (piVar3 != (int *)0x0) {
    piStack_188 = piVar3;
    (**(code **)(**(int **)(param_1 + 0x58) + 0x118))(*(int **)(param_1 + 0x58),4,0);
  }
  piStack_188 = *(int **)(param_1 + 0x670);
  (**(code **)(**(int **)(param_1 + 0x58) + 0xd8))(*(int **)(param_1 + 0x58));
  return 0;
}



/* ===== FUN_1000fa90 @ 0x1000FA90 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_1000fa90(int param_1)

{
  int iVar1;
  longlong lVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  uint uVar8;
  bool bVar9;
  float10 fVar10;
  float10 fVar11;
  longlong lVar12;
  LARGE_INTEGER local_8;
  
  if (DAT_100248a0 == 0) {
    DAT_100248a0 = 1;
    DAT_100248a4 = QueryPerformanceFrequency(&local_8);
    if (DAT_100248a4 != 0) {
      DAT_100248a8 = local_8.s.LowPart;
      DAT_100248ac = local_8.s.HighPart;
      goto LAB_1000fadc;
    }
  }
  else {
LAB_1000fadc:
    if (DAT_100248a4 != 0) {
      if (((DAT_100248b0 == 0 && DAT_100248b4 == 0) || (param_1 == 1)) || (param_1 == 4)) {
        QueryPerformanceCounter(&local_8);
        uVar6 = local_8.s.HighPart;
        uVar7 = local_8.s.LowPart;
      }
      else {
        local_8.s.HighPart = DAT_100248b4;
        local_8.s.LowPart = DAT_100248b0;
        uVar6 = DAT_100248b4;
        uVar7 = DAT_100248b0;
      }
      lVar2 = CONCAT44(DAT_100248b4,DAT_100248b0);
      if (param_1 == 6) {
        local_8.s.HighPart = (uVar6 - DAT_100248bc) - (uint)((uint)uVar7 < DAT_100248b8);
        local_8.s.LowPart = uVar7 - DAT_100248b8;
        DAT_100248b8 = uVar7;
        DAT_100248bc = uVar6;
        return (float10)(longlong)local_8 / (float10)CONCAT44(DAT_100248ac,DAT_100248a8);
      }
      if (param_1 == 5) {
        local_8.s.HighPart = (uVar6 - DAT_100248c4) - (uint)((uint)uVar7 < DAT_100248c0);
        local_8.s.LowPart = uVar7 - DAT_100248c0;
        return (float10)(longlong)local_8 / (float10)CONCAT44(DAT_100248ac,DAT_100248a8);
      }
      uVar3 = DAT_100248b0;
      iVar4 = DAT_100248b4;
      uVar5 = uVar7;
      iVar1 = uVar6;
      if (param_1 == 0) {
LAB_1000fbb3:
        DAT_100248c4 = iVar1;
        DAT_100248c0 = uVar5;
        DAT_100248b4 = iVar4;
        DAT_100248b0 = uVar3;
        DAT_100248b8 = uVar7;
        DAT_100248bc = uVar6;
        return (float10)0.0;
      }
      if (param_1 == 1) {
        bVar9 = (uint)uVar7 < DAT_100248b0;
        uVar8 = uVar7 - DAT_100248b0;
        iVar1 = uVar6 - DAT_100248b4;
        DAT_100248b0 = 0;
        DAT_100248b4 = 0;
        uVar3 = DAT_100248b0;
        iVar4 = DAT_100248b4;
        uVar5 = DAT_100248c0 + uVar8;
        iVar1 = DAT_100248c4 + (iVar1 - (uint)bVar9) + (uint)CARRY4(DAT_100248c0,uVar8);
        goto LAB_1000fbb3;
      }
      uVar3 = uVar7;
      iVar4 = uVar6;
      uVar5 = DAT_100248c0;
      iVar1 = DAT_100248c4;
      if (param_1 == 2) goto LAB_1000fbb3;
      if (param_1 == 3) {
        lVar12 = __alldiv(DAT_100248a8,DAT_100248ac,10,0);
        lVar12 = lVar12 + lVar2;
        DAT_100248b4 = (int)((ulonglong)lVar12 >> 0x20);
        DAT_100248b0 = (int)lVar12;
        return (float10)0.0;
      }
      if (param_1 == 4) {
        return (float10)(longlong)local_8 / (float10)CONCAT44(DAT_100248ac,DAT_100248a8);
      }
      goto LAB_1000fd9d;
    }
  }
  if (((_DAT_100248d8 == 0.0) || (param_1 == 1)) || (param_1 == 4)) {
    local_8.s.LowPart = timeGetTime();
    local_8.s.HighPart = 0;
    fVar10 = (float10)(longlong)local_8 * (float10)0.001;
  }
  else {
    fVar10 = (float10)_DAT_100248d8;
  }
  if (param_1 == 6) {
    fVar11 = (float10)_DAT_100248c8;
    _DAT_100248c8 = (double)fVar10;
    return (float10)(double)(fVar10 - fVar11);
  }
  if (param_1 == 5) {
    return fVar10 - (float10)_DAT_100248d0;
  }
  if (param_1 == 0) {
    _DAT_100248d0 = (double)fVar10;
    _DAT_100248c8 = (double)fVar10;
    return (float10)0.0;
  }
  if (param_1 == 1) {
    fVar11 = (float10)_DAT_100248d8;
    _DAT_100248d8 = 0.0;
    _DAT_100248d0 = (double)((fVar10 - fVar11) + (float10)_DAT_100248d0);
    _DAT_100248c8 = (double)fVar10;
    return (float10)0.0;
  }
  if (param_1 == 2) {
    _DAT_100248d8 = (double)fVar10;
    return (float10)0.0;
  }
  if (param_1 == 3) {
    _DAT_100248d8 = _DAT_100248d8 + 0.10000000149011612;
    return (float10)0.0;
  }
  if (param_1 == 4) {
    return fVar10;
  }
LAB_1000fd9d:
  return (float10)-1.0;
}



/* ===== FUN_1000fdb6 @ 0x1000FDB6 ===== */

void FUN_1000fdb6(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = param_2[1];
  param_1[1] = param_2[4];
  param_1[4] = uVar1;
  uVar1 = param_2[2];
  param_1[2] = param_2[8];
  param_1[8] = uVar1;
  uVar1 = param_2[3];
  param_1[3] = param_2[0xc];
  param_1[0xc] = uVar1;
  uVar1 = param_2[6];
  param_1[6] = param_2[9];
  param_1[9] = uVar1;
  uVar1 = param_2[7];
  param_1[7] = param_2[0xd];
  param_1[0xd] = uVar1;
  uVar1 = param_2[0xb];
  param_1[0xb] = param_2[0xe];
  param_1[0xe] = uVar1;
  if (param_1 != param_2) {
    *param_1 = *param_2;
    param_1[5] = param_2[5];
    param_1[10] = param_2[10];
    param_1[0xf] = param_2[0xf];
  }
  return;
}



/* ===== FUN_1000fe23 @ 0x1000FE23 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000fe23(void)

{
  void *extraout_ECX;
  
  FUN_1000fe3b();
  _DAT_100254dc = FUN_10011352();
  FUN_10011302(extraout_ECX);
  return;
}



/* ===== FUN_1000fe3b @ 0x1000FE3B ===== */

void FUN_1000fe3b(void)

{
  PTR___fptrap_10020fd8 = &LAB_100113d5;
  PTR___fptrap_10020fd4 = __cfltcvt;
  PTR___fptrap_10020fdc = __fassign;
  PTR___fptrap_10020fe0 = FUN_1001137b;
  PTR___fptrap_10020fe4 = &LAB_10011423;
  PTR___fptrap_10020fe8 = __cfltcvt;
  return;
}



/* ===== __ftol @ 0x1000FE74 ===== */

/* Library Function - Single Match
    __ftol
   
   Library: Visual Studio */

longlong __ftol(void)

{
  float10 in_ST0;
  
  return (longlong)ROUND(in_ST0);
}



/* ===== FUN_1000fe9b @ 0x1000FE9B ===== */

void __cdecl FUN_1000fe9b(undefined *param_1)

{
  FUN_100101ee(param_1);
  return;
}



/* ===== operator_new @ 0x1000FEA6 ===== */

/* Library Function - Single Match
    void * __cdecl operator new(unsigned int)
   
   Library: Visual Studio 2003 Release */

void * __cdecl operator_new(uint param_1)

{
  void *pvVar1;
  
  pvVar1 = __nh_malloc(param_1,1);
  return pvVar1;
}



/* ===== FUN_1000feb4 @ 0x1000FEB4 ===== */

int __cdecl FUN_1000feb4(undefined1 *param_1,byte *param_2)

{
  int iVar1;
  undefined1 *local_24;
  int local_20;
  undefined1 *local_1c;
  undefined4 local_18;
  
  local_1c = param_1;
  local_24 = param_1;
  local_18 = 0x42;
  local_20 = 0x7fffffff;
  iVar1 = FUN_100118b9((int *)&local_24,param_2,(undefined4 *)&stack0x0000000c);
  local_20 = local_20 + -1;
  if (local_20 < 0) {
    FUN_100117a1(0,(int *)&local_24);
  }
  else {
    *local_24 = 0;
  }
  return iVar1;
}



/* ===== _malloc @ 0x1000FF06 ===== */

/* Library Function - Single Match
    _malloc
   
   Library: Visual Studio 2003 Release */

void * __cdecl _malloc(size_t _Size)

{
  void *pvVar1;
  
  pvVar1 = __nh_malloc(_Size,DAT_10025538);
  return pvVar1;
}



/* ===== __nh_malloc @ 0x1000FF18 ===== */

/* Library Function - Single Match
    __nh_malloc
   
   Library: Visual Studio 2003 Release */

void * __cdecl __nh_malloc(size_t _Size,int _NhFlag)

{
  void *pvVar1;
  int iVar2;
  
  if (_Size < 0xffffffe1) {
    do {
      pvVar1 = (void *)FUN_1000ff44((uint *)_Size);
      if (pvVar1 != (void *)0x0) {
        return pvVar1;
      }
      if (_NhFlag == 0) {
        return (void *)0x0;
      }
      iVar2 = FUN_100120c3(_Size);
    } while (iVar2 != 0);
  }
  return (void *)0x0;
}



/* ===== FUN_1000ff44 @ 0x1000FF44 ===== */

void __cdecl FUN_1000ff44(uint *param_1)

{
  int *piVar1;
  uint dwBytes;
  void *local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &DAT_1001c3b8;
  puStack_10 = &LAB_100132e0;
  local_14 = ExceptionList;
  if (DAT_10026be4 == 3) {
    ExceptionList = &local_14;
    if (param_1 <= DAT_10026bdc) {
      ExceptionList = &local_14;
      FUN_10013262(9);
      local_8 = 0;
      piVar1 = FUN_100126f4(param_1);
      local_8 = 0xffffffff;
      FUN_1000ffab();
      if (piVar1 != (int *)0x0) {
        ExceptionList = local_14;
        return;
      }
    }
  }
  else {
    ExceptionList = &local_14;
    if (DAT_10026be4 == 2) {
      if (param_1 == (uint *)0x0) {
        dwBytes = 0x10;
      }
      else {
        dwBytes = (int)param_1 + 0xfU & 0xfffffff0;
      }
      ExceptionList = &local_14;
      if (dwBytes <= DAT_1002301c) {
        ExceptionList = &local_14;
        FUN_10013262(9);
        local_8 = 1;
        piVar1 = FUN_10012ea1(dwBytes >> 4);
        local_8 = 0xffffffff;
        FUN_1001000a();
        if (piVar1 != (int *)0x0) {
          ExceptionList = local_14;
          return;
        }
      }
      goto LAB_10010023;
    }
  }
  if (param_1 == (uint *)0x0) {
    param_1 = (uint *)0x1;
  }
  dwBytes = (int)param_1 + 0xfU & 0xfffffff0;
LAB_10010023:
  HeapAlloc(DAT_10026be0,0,dwBytes);
  ExceptionList = local_14;
  return;
}



/* ===== FUN_1000ffab @ 0x1000FFAB ===== */

void FUN_1000ffab(void)

{
  FUN_100132c3(9);
  return;
}



/* ===== FUN_1001000a @ 0x1001000A ===== */

void FUN_1001000a(void)

{
  FUN_100132c3(9);
  return;
}



/* ===== FUN_10010040 @ 0x10010040 ===== */

uint __cdecl FUN_10010040(byte *param_1,byte *param_2)

{
  byte bVar1;
  DWORD *pDVar2;
  int iVar3;
  byte *pbVar4;
  byte local_24 [32];
  
  pDVar2 = FUN_1001343d();
  pbVar4 = local_24;
  for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
    pbVar4[0] = 0;
    pbVar4[1] = 0;
    pbVar4[2] = 0;
    pbVar4[3] = 0;
    pbVar4 = pbVar4 + 4;
  }
  do {
    bVar1 = *param_2;
    local_24[bVar1 >> 3] = local_24[bVar1 >> 3] | '\x01' << (bVar1 & 7);
    param_2 = param_2 + 1;
  } while (bVar1 != 0);
  if (param_1 == (byte *)0x0) {
    param_1 = (byte *)pDVar2[6];
  }
  for (; (bVar1 = *param_1, pbVar4 = param_1, (local_24[bVar1 >> 3] & (byte)(1 << (bVar1 & 7))) != 0
         && (bVar1 != 0)); param_1 = param_1 + 1) {
  }
  do {
    bVar1 = *pbVar4;
    if (bVar1 == 0) {
LAB_100100cf:
      pDVar2[6] = (DWORD)pbVar4;
      return -(uint)(param_1 != pbVar4) & (uint)param_1;
    }
    if ((local_24[bVar1 >> 3] & (byte)(1 << (bVar1 & 7))) != 0) {
      *pbVar4 = 0;
      pbVar4 = pbVar4 + 1;
      goto LAB_100100cf;
    }
    pbVar4 = pbVar4 + 1;
  } while( true );
}



/* ===== _strncpy @ 0x100100F0 ===== */

/* Library Function - Single Match
    _strncpy
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

char * __cdecl _strncpy(char *_Dest,char *_Source,size_t _Count)

{
  uint uVar1;
  uint uVar2;
  char cVar3;
  uint uVar4;
  uint *puVar5;
  
  if (_Count == 0) {
    return _Dest;
  }
  puVar5 = (uint *)_Dest;
  if (((uint)_Source & 3) != 0) {
    while( true ) {
      uVar4 = *(uint *)_Source;
      _Source = (char *)((int)_Source + 1);
      *(char *)puVar5 = (char)uVar4;
      puVar5 = (uint *)((int)puVar5 + 1);
      _Count = _Count - 1;
      if (_Count == 0) {
        return _Dest;
      }
      if ((char)uVar4 == '\0') break;
      if (((uint)_Source & 3) == 0) {
        uVar4 = _Count >> 2;
        goto joined_r0x1001012e;
      }
    }
    do {
      if (((uint)puVar5 & 3) == 0) {
        uVar4 = _Count >> 2;
        cVar3 = '\0';
        if (uVar4 == 0) goto LAB_1001016b;
        goto LAB_100101d9;
      }
      *(char *)puVar5 = '\0';
      puVar5 = (uint *)((int)puVar5 + 1);
      _Count = _Count - 1;
    } while (_Count != 0);
    return _Dest;
  }
  uVar4 = _Count >> 2;
  if (uVar4 != 0) {
    do {
      uVar1 = *(uint *)_Source;
      uVar2 = *(uint *)_Source;
      _Source = (char *)((int)_Source + 4);
      if (((uVar1 ^ 0xffffffff ^ uVar1 + 0x7efefeff) & 0x81010100) != 0) {
        if ((char)uVar2 == '\0') {
          *puVar5 = 0;
joined_r0x100101d5:
          while( true ) {
            uVar4 = uVar4 - 1;
            puVar5 = puVar5 + 1;
            if (uVar4 == 0) break;
LAB_100101d9:
            *puVar5 = 0;
          }
          cVar3 = '\0';
          _Count = _Count & 3;
          if (_Count != 0) goto LAB_1001016b;
          return _Dest;
        }
        if ((char)(uVar2 >> 8) == '\0') {
          *puVar5 = uVar2 & 0xff;
          goto joined_r0x100101d5;
        }
        if ((uVar2 & 0xff0000) == 0) {
          *puVar5 = uVar2 & 0xffff;
          goto joined_r0x100101d5;
        }
        if ((uVar2 & 0xff000000) == 0) {
          *puVar5 = uVar2;
          goto joined_r0x100101d5;
        }
      }
      *puVar5 = uVar2;
      puVar5 = puVar5 + 1;
      uVar4 = uVar4 - 1;
joined_r0x1001012e:
    } while (uVar4 != 0);
    _Count = _Count & 3;
    if (_Count == 0) {
      return _Dest;
    }
  }
  do {
    cVar3 = (char)*(uint *)_Source;
    _Source = (char *)((int)_Source + 1);
    *(char *)puVar5 = cVar3;
    puVar5 = (uint *)((int)puVar5 + 1);
    if (cVar3 == '\0') {
      while (_Count = _Count - 1, _Count != 0) {
LAB_1001016b:
        *(char *)puVar5 = cVar3;
        puVar5 = (uint *)((int)puVar5 + 1);
      }
      return _Dest;
    }
    _Count = _Count - 1;
  } while (_Count != 0);
  return _Dest;
}



/* ===== FUN_100101ee @ 0x100101EE ===== */

void __cdecl FUN_100101ee(undefined *param_1)

{
  uint *puVar1;
  int local_2c;
  uint *local_28;
  uint local_24;
  uint *local_20;
  void *local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &DAT_1001c3d0;
  puStack_10 = &LAB_100132e0;
  local_14 = ExceptionList;
  if (param_1 == (undefined *)0x0) {
    return;
  }
  if (DAT_10026be4 == 3) {
    ExceptionList = &local_14;
    FUN_10013262(9);
    local_8 = 0;
    local_20 = (uint *)FUN_100123a0((int)param_1);
    if (local_20 != (uint *)0x0) {
      FUN_100123cb(local_20,(int)param_1);
    }
    local_8 = 0xffffffff;
    FUN_10010258();
    puVar1 = local_20;
  }
  else {
    ExceptionList = &local_14;
    if (DAT_10026be4 != 2) goto LAB_100102ba;
    ExceptionList = &local_14;
    FUN_10013262(9);
    local_8 = 1;
    local_28 = (uint *)FUN_10012e05(param_1,&local_2c,&local_24);
    if (local_28 != (uint *)0x0) {
      FUN_10012e5c(local_2c,local_24,(byte *)local_28);
    }
    local_8 = 0xffffffff;
    FUN_100102b0();
    puVar1 = local_28;
  }
  if (puVar1 != (uint *)0x0) {
    ExceptionList = local_14;
    return;
  }
LAB_100102ba:
  HeapFree(DAT_10026be0,0,param_1);
  ExceptionList = local_14;
  return;
}



/* ===== FUN_10010258 @ 0x10010258 ===== */

void FUN_10010258(void)

{
  FUN_100132c3(9);
  return;
}



/* ===== FUN_100102b0 @ 0x100102B0 ===== */

void FUN_100102b0(void)

{
  FUN_100132c3(9);
  return;
}



/* ===== FUN_100102e0 @ 0x100102E0 ===== */

void FUN_100102e0(void)

{
  float10 in_ST0;
  float10 in_ST1;
  
  FUN_10010302(SUB84((double)in_ST1,0),(uint)((ulonglong)(double)in_ST1 >> 0x20),
               SUB84((double)in_ST0,0),(uint)((ulonglong)(double)in_ST0 >> 0x20));
  return;
}



/* ===== FUN_10010302 @ 0x10010302 ===== */
// FAIL

/* ===== FUN_100104d5 @ 0x100104D5 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100104d5(void)

{
  float10 in_ST0;
  
  if (ROUND(in_ST0) == in_ST0) {
    return;
  }
  return;
}



/* ===== FUN_100104fd @ 0x100104FD ===== */

void FUN_100104fd(undefined *UNRECOVERED_JUMPTABLE)

{
  ExceptionList = *(void **)ExceptionList;
                    /* WARNING: Could not recover jumptable at 0x10010528. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)UNRECOVERED_JUMPTABLE)();
  return;
}



/* ===== FUN_10010531 @ 0x10010531 ===== */

void FUN_10010531(undefined4 param_1,undefined *UNRECOVERED_JUMPTABLE)

{
  LOCK();
  UNLOCK();
                    /* WARNING: Could not recover jumptable at 0x10010536. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)UNRECOVERED_JUMPTABLE)();
  return;
}



/* ===== FUN_10010538 @ 0x10010538 ===== */

void FUN_10010538(undefined4 param_1,undefined *UNRECOVERED_JUMPTABLE)

{
  LOCK();
  UNLOCK();
                    /* WARNING: Could not recover jumptable at 0x1001053d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)UNRECOVERED_JUMPTABLE)();
  return;
}



/* ===== FUN_1001053f @ 0x1001053F ===== */

void FUN_1001053f(PVOID param_1,PEXCEPTION_RECORD param_2)

{
  void *pvVar1;
  
  pvVar1 = ExceptionList;
  RtlUnwind(param_1,(PVOID)0x10010567,param_2,(PVOID)0x0);
  param_2->ExceptionFlags = param_2->ExceptionFlags & 0xfffffffd;
  *(void **)pvVar1 = ExceptionList;
  ExceptionList = pvVar1;
  return;
}



/* ===== FUN_1001058e @ 0x1001058E ===== */

undefined4 __cdecl
FUN_1001058e(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4)

{
  int *in_EAX;
  undefined4 uVar1;
  
  uVar1 = FUN_10013cb1(param_1,param_2,param_3,param_4,in_EAX,0,(PVOID)0x0,'\0');
  return uVar1;
}



/* ===== FUN_100105c4 @ 0x100105C4 ===== */

undefined4 __cdecl
FUN_100105c4(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5)

{
  undefined4 uVar1;
  void *local_18;
  code *local_14;
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  
  local_10 = param_2;
  local_14 = FUN_10010618;
  local_8 = param_4 + 1;
  local_c = param_1;
  local_18 = ExceptionList;
  ExceptionList = &local_18;
  uVar1 = __CallSettingFrame_12(param_3,param_1,param_5);
  ExceptionList = local_18;
  return uVar1;
}



/* ===== FUN_10010618 @ 0x10010618 ===== */

void __cdecl FUN_10010618(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3)

{
  FUN_10013cb1(param_1,*(PVOID *)((int)param_2 + 0xc),param_3,0,*(int **)((int)param_2 + 8),
               *(int *)((int)param_2 + 0x10),param_2,'\0');
  return;
}



/* ===== FUN_1001063d @ 0x1001063D ===== */

undefined4 __cdecl
FUN_1001063d(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  DWORD *pDVar1;
  undefined4 uVar2;
  undefined4 **ppuVar3;
  undefined4 *local_34;
  undefined4 local_30;
  undefined4 *local_2c;
  code *local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined1 *local_10;
  undefined1 *local_c;
  int local_8;
  
  local_c = &stack0xfffffffc;
  local_10 = &stack0xffffffbc;
  local_28 = FUN_100106f3;
  local_24 = param_5;
  local_20 = param_2;
  local_1c = param_6;
  local_18 = param_7;
  local_8 = 0;
  local_14 = 0x100106c5;
  local_2c = ExceptionList;
  ExceptionList = &local_2c;
  local_34 = param_1;
  local_30 = param_3;
  ppuVar3 = &local_34;
  uVar2 = *param_1;
  pDVar1 = FUN_1001343d();
  (*(code *)pDVar1[0x1a])(uVar2,ppuVar3);
  if (local_8 != 0) {
    *local_2c = *(undefined4 *)ExceptionList;
  }
  ExceptionList = local_2c;
  return 0;
}



/* ===== FUN_100106f3 @ 0x100106F3 ===== */

undefined4 __cdecl FUN_100106f3(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3)

{
  undefined4 uVar1;
  
  if ((param_1->ExceptionFlags & 0x66) != 0) {
    *(undefined4 *)((int)param_2 + 0x24) = 1;
    return 1;
  }
  FUN_10013cb1(param_1,*(PVOID *)((int)param_2 + 0xc),param_3,0,*(int **)((int)param_2 + 8),
               *(int *)((int)param_2 + 0x10),*(PVOID *)((int)param_2 + 0x14),'\x01');
  if (*(int *)((int)param_2 + 0x24) == 0) {
    FUN_1001053f(param_2,param_1);
  }
                    /* WARNING: Could not recover jumptable at 0x1001075d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)((int)param_2 + 0x18))();
  return uVar1;
}



/* ===== FUN_10010768 @ 0x10010768 ===== */

int __cdecl FUN_10010768(int param_1,int param_2,int param_3,uint *param_4,uint *param_5)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = *(uint *)(param_1 + 0xc);
  iVar1 = *(int *)(param_1 + 0x10);
  uVar4 = uVar5;
  uVar3 = uVar5;
  while (uVar2 = uVar4, -1 < param_2) {
    if (uVar5 == 0xffffffff) {
      FUN_1001457d();
    }
    uVar5 = uVar5 - 1;
    if (((*(int *)(iVar1 + 4 + uVar5 * 0x14) < param_3) &&
        (param_3 <= *(int *)(iVar1 + uVar5 * 0x14 + 8))) || (uVar4 = uVar2, uVar5 == 0xffffffff)) {
      param_2 = param_2 + -1;
      uVar4 = uVar5;
      uVar3 = uVar2;
    }
  }
  uVar5 = uVar5 + 1;
  *param_4 = uVar5;
  *param_5 = uVar3;
  if ((*(uint *)(param_1 + 0xc) < uVar3) || (uVar3 < uVar5)) {
    FUN_1001457d();
  }
  return iVar1 + uVar5 * 0x14;
}



/* ===== __global_unwind2 @ 0x100107E4 ===== */

/* Library Function - Single Match
    __global_unwind2
   
   Library: Visual Studio */

void __cdecl __global_unwind2(PVOID param_1)

{
  RtlUnwind(param_1,(PVOID)0x100107fc,(PEXCEPTION_RECORD)0x0,(PVOID)0x0);
  return;
}



/* ===== __local_unwind2 @ 0x10010826 ===== */

/* Library Function - Single Match
    __local_unwind2
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release, Visual Studio 2003 Debug, Visual
   Studio 2003 Release */

void __cdecl __local_unwind2(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  void *pvStack_1c;
  undefined1 *puStack_18;
  undefined4 local_14;
  int iStack_10;
  
  iStack_10 = param_1;
  puStack_18 = &LAB_10010804;
  pvStack_1c = ExceptionList;
  ExceptionList = &pvStack_1c;
  while( true ) {
    iVar1 = *(int *)(param_1 + 8);
    iVar2 = *(int *)(param_1 + 0xc);
    if ((iVar2 == -1) || (iVar2 == param_2)) break;
    local_14 = *(undefined4 *)(iVar1 + iVar2 * 0xc);
    *(undefined4 *)(param_1 + 0xc) = local_14;
    if (*(int *)(iVar1 + 4 + iVar2 * 0xc) == 0) {
      FUN_100108ba();
      (**(code **)(iVar1 + 8 + iVar2 * 0xc))();
    }
  }
  ExceptionList = pvStack_1c;
  return;
}



/* ===== __abnormal_termination @ 0x1001088E ===== */

/* Library Function - Single Match
    __abnormal_termination
   
   Library: Visual Studio */

int __cdecl __abnormal_termination(void)

{
  int iVar1;
  
  iVar1 = 0;
  if ((*(undefined1 **)((int)ExceptionList + 4) == &LAB_10010804) &&
     (*(int *)((int)ExceptionList + 8) == *(int *)(*(int *)((int)ExceptionList + 0xc) + 0xc))) {
    iVar1 = 1;
  }
  return iVar1;
}



/* ===== __NLG_Notify1 @ 0x100108B1 ===== */

/* Library Function - Single Match
    __NLG_Notify1
   
   Libraries: Visual Studio 2017 Debug, Visual Studio 2017 Release, Visual Studio 2019 Debug, Visual
   Studio 2019 Release */

void __fastcall __NLG_Notify1(undefined4 param_1)

{
  undefined4 in_EAX;
  undefined4 unaff_EBP;
  
  DAT_10020f94 = param_1;
  DAT_10020f90 = in_EAX;
  DAT_10020f98 = unaff_EBP;
  return;
}



/* ===== FUN_100108ba @ 0x100108BA ===== */

void FUN_100108ba(void)

{
  undefined4 in_EAX;
  int unaff_EBP;
  
  DAT_10020f94 = *(undefined4 *)(unaff_EBP + 8);
  DAT_10020f90 = in_EAX;
  DAT_10020f98 = unaff_EBP;
  return;
}



/* ===== FUN_100108d2 @ 0x100108D2 ===== */

void __cdecl FUN_100108d2(int *param_1,undefined4 *param_2,uint param_3,undefined *param_4)

{
  int *piVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  undefined4 local_fc [30];
  int local_84 [30];
  int *local_c;
  int local_8;
  
  if ((param_2 < (undefined4 *)0x2) || (param_3 == 0)) {
    return;
  }
  local_8 = 0;
  iVar4 = (int)param_2 + -1;
  param_2 = local_fc;
  piVar5 = (int *)(iVar4 * param_3 + (int)param_1);
  piVar3 = param_1;
  param_1 = local_84;
LAB_10010911:
  uVar2 = (uint)((int)piVar5 - (int)piVar3) / param_3 + 1;
  if (8 < uVar2) {
    FUN_10010a74((undefined1 *)((uVar2 >> 1) * param_3 + (int)piVar3),(undefined1 *)piVar3,param_3);
    piVar6 = (int *)(param_3 + (int)piVar5);
    local_c = piVar3;
LAB_10010968:
    local_c = (int *)((int)local_c + param_3);
    if (local_c <= piVar5) goto code_r0x10010975;
    goto LAB_10010980;
  }
  FUN_10010a26((undefined1 *)piVar3,(undefined1 *)piVar5,param_3,param_4);
  goto LAB_10010930;
code_r0x10010975:
  iVar4 = (*(code *)param_4)(local_c,piVar3);
  if (iVar4 < 1) goto LAB_10010968;
LAB_10010980:
  do {
    piVar6 = (int *)((int)piVar6 - param_3);
    if (piVar6 <= piVar3) break;
    iVar4 = (*(code *)param_4)(piVar6,piVar3);
  } while (-1 < iVar4);
  if (local_c <= piVar6) {
    FUN_10010a74((undefined1 *)local_c,(undefined1 *)piVar6,param_3);
    goto LAB_10010968;
  }
  FUN_10010a74((undefined1 *)piVar3,(undefined1 *)piVar6,param_3);
  piVar1 = local_c;
  if ((int)((int)piVar6 + (-1 - (int)piVar3)) < (int)piVar5 - (int)local_c) {
    if (local_c < piVar5) {
      local_8 = local_8 + 1;
      *param_2 = local_c;
      *param_1 = (int)piVar5;
      param_1 = param_1 + 1;
      param_2 = param_2 + 1;
    }
    if ((int *)(param_3 + (int)piVar3) < piVar6) {
      piVar5 = (int *)((int)piVar6 - param_3);
      goto LAB_10010911;
    }
  }
  else {
    if ((int *)((int)piVar3 + param_3) < piVar6) {
      local_8 = local_8 + 1;
      *param_2 = piVar3;
      *param_1 = (int)piVar6 - param_3;
      param_1 = param_1 + 1;
      param_2 = param_2 + 1;
    }
    piVar3 = piVar1;
    if (piVar1 < piVar5) goto LAB_10010911;
  }
LAB_10010930:
  local_8 = local_8 + -1;
  param_2 = param_2 + -1;
  param_1 = param_1 + -1;
  if (local_8 < 0) {
    return;
  }
  piVar5 = (int *)*param_1;
  piVar3 = (int *)*param_2;
  goto LAB_10010911;
}



/* ===== FUN_10010a26 @ 0x10010A26 ===== */

void __cdecl FUN_10010a26(undefined1 *param_1,undefined1 *param_2,int param_3,undefined *param_4)

{
  int iVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  
  for (; puVar2 = param_1, puVar3 = param_1, param_1 < param_2; param_2 = param_2 + -param_3) {
    while (puVar3 = puVar3 + param_3, puVar3 <= param_2) {
      iVar1 = (*(code *)param_4)(puVar3,puVar2);
      if (0 < iVar1) {
        puVar2 = puVar3;
      }
    }
    FUN_10010a74(puVar2,param_2,param_3);
  }
  return;
}



/* ===== FUN_10010a74 @ 0x10010A74 ===== */

void __cdecl FUN_10010a74(undefined1 *param_1,undefined1 *param_2,int param_3)

{
  undefined1 uVar1;
  
  if (param_1 != param_2) {
    for (; param_3 != 0; param_3 = param_3 + -1) {
      uVar1 = *param_1;
      *param_1 = *param_2;
      param_1 = param_1 + 1;
      *param_2 = uVar1;
      param_2 = param_2 + 1;
    }
  }
  return;
}



/* ===== __alldiv @ 0x10010BA0 ===== */

/* Library Function - Single Match
    __alldiv
   
   Library: Visual Studio */

undefined8 __alldiv(uint param_1,uint param_2,uint param_3,uint param_4)

{
  ulonglong uVar1;
  longlong lVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  bool bVar10;
  char cVar11;
  uint uVar9;
  
  cVar11 = (int)param_2 < 0;
  if ((bool)cVar11) {
    bVar10 = param_1 != 0;
    param_1 = -param_1;
    param_2 = -(uint)bVar10 - param_2;
  }
  if ((int)param_4 < 0) {
    cVar11 = cVar11 + '\x01';
    bVar10 = param_3 != 0;
    param_3 = -param_3;
    param_4 = -(uint)bVar10 - param_4;
  }
  uVar3 = param_1;
  uVar5 = param_3;
  uVar6 = param_2;
  uVar9 = param_4;
  if (param_4 == 0) {
    uVar3 = param_2 / param_3;
    iVar4 = (int)(((ulonglong)param_2 % (ulonglong)param_3 << 0x20 | (ulonglong)param_1) /
                 (ulonglong)param_3);
  }
  else {
    do {
      uVar8 = uVar9 >> 1;
      uVar5 = uVar5 >> 1 | (uint)((uVar9 & 1) != 0) << 0x1f;
      uVar7 = uVar6 >> 1;
      uVar3 = uVar3 >> 1 | (uint)((uVar6 & 1) != 0) << 0x1f;
      uVar6 = uVar7;
      uVar9 = uVar8;
    } while (uVar8 != 0);
    uVar1 = CONCAT44(uVar7,uVar3) / (ulonglong)uVar5;
    iVar4 = (int)uVar1;
    lVar2 = (ulonglong)param_3 * (uVar1 & 0xffffffff);
    uVar3 = (uint)((ulonglong)lVar2 >> 0x20);
    uVar5 = uVar3 + iVar4 * param_4;
    if (((CARRY4(uVar3,iVar4 * param_4)) || (param_2 < uVar5)) ||
       ((param_2 <= uVar5 && (param_1 < (uint)lVar2)))) {
      iVar4 = iVar4 + -1;
    }
    uVar3 = 0;
  }
  if (cVar11 == '\x01') {
    bVar10 = iVar4 != 0;
    iVar4 = -iVar4;
    uVar3 = -(uint)bVar10 - uVar3;
  }
  return CONCAT44(uVar3,iVar4);
}



/* ===== FUN_10010c4a @ 0x10010C4A ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_10010c4a(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_2 == 1) {
    DAT_100254f8 = GetVersion();
    iVar1 = FUN_10012253(1);
    if (iVar1 != 0) {
      _DAT_10025504 = DAT_100254f8 >> 8 & 0xff;
      _DAT_10025500 = DAT_100254f8 & 0xff;
      DAT_100254f8 = DAT_100254f8 >> 0x10;
      _DAT_100254fc = _DAT_10025500 * 0x100 + _DAT_10025504;
      iVar1 = FUN_100133b8();
      if (iVar1 != 0) {
        DAT_10026bf8 = GetCommandLineA();
        DAT_100254e4 = FUN_10014ae9();
        FUN_100145d3();
        FUN_1001489c();
        FUN_100147e3();
        FUN_100110a7();
        DAT_100254e0 = DAT_100254e0 + 1;
        goto LAB_10010d1d;
      }
      FUN_100122b0();
    }
LAB_10010caa:
    uVar2 = 0;
  }
  else {
    if (param_2 == 0) {
      if (DAT_100254e0 < 1) goto LAB_10010caa;
      DAT_100254e0 = DAT_100254e0 + -1;
      if (DAT_10025530 == 0) {
        FUN_100110e5();
      }
      FUN_1001478f();
      FUN_1001340c();
      FUN_100122b0();
    }
    else if (param_2 == 3) {
      FUN_100134a4((undefined *)0x0);
    }
LAB_10010d1d:
    uVar2 = 1;
  }
  return uVar2;
}



/* ===== entry @ 0x10010D23 ===== */ /* EXPORT entry */

int entry(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = param_2;
  iVar2 = DAT_100254e0;
  if (param_2 != 0) {
    if ((param_2 != 1) && (param_2 != 2)) goto LAB_10010d6b;
    if ((DAT_10026bfc != (code *)0x0) &&
       (iVar2 = (*DAT_10026bfc)(param_1,param_2,param_3), iVar2 == 0)) {
      return 0;
    }
    iVar2 = FUN_10010c4a(param_1,param_2);
  }
  if (iVar2 == 0) {
    return 0;
  }
LAB_10010d6b:
  iVar2 = FUN_10014c1b();
  if (param_2 == 1) {
    if (iVar2 != 0) {
      return iVar2;
    }
    FUN_10010c4a(param_1,0);
  }
  if ((param_2 != 0) && (param_2 != 3)) {
    return iVar2;
  }
  iVar3 = FUN_10010c4a(param_1,param_2);
  param_2 = iVar2;
  if (iVar3 == 0) {
    param_2 = 0;
  }
  if (param_2 != 0) {
    if (DAT_10026bfc != (code *)0x0) {
      iVar2 = (*DAT_10026bfc)(param_1,iVar1,param_3);
      return iVar2;
    }
    return param_2;
  }
  return 0;
}



/* ===== __amsg_exit @ 0x10010DC0 ===== */

/* Library Function - Single Match
    __amsg_exit
   
   Library: Visual Studio 2003 Release */

void __cdecl __amsg_exit(int param_1)

{
  if ((DAT_100254ec == 1) || ((DAT_100254ec == 0 && (DAT_100254f0 == 1)))) {
    FUN_10014c21();
  }
  FUN_10014c5a(param_1);
  (*(code *)PTR___exit_10020fb0)(0xff);
  return;
}



/* ===== FUN_10010e00 @ 0x10010E00 ===== */

void FUN_10010e00(void)

{
  float10 in_ST0;
  double dVar1;
  
  dVar1 = (double)in_ST0;
  FUN_10013a18(SUB84(dVar1,0),(uint)((ulonglong)dVar1 >> 0x20));
  FUN_10010e1d(SUB84(dVar1,0),(uint)((ulonglong)dVar1 >> 0x20));
  return;
}



/* ===== FUN_10010e1d @ 0x10010E1D ===== */

void __cdecl FUN_10010e1d(int param_1,uint param_2)

{
  uint in_EAX;
  bool in_ZF;
  ushort in_FPUControlWord;
  float10 in_ST0;
  float10 extraout_ST0;
  undefined4 unaff_retaddr;
  
  if (in_ZF) {
    if (((in_EAX & 0xfffff) != 0) || (param_1 != 0)) {
      FUN_100139bc();
    }
LAB_10010eac:
    if (DAT_100254d8 == 0) {
      __startOneArgErrorHandling(&DAT_10020fc0,0xd,in_FPUControlWord,unaff_retaddr,param_1,param_2);
      return;
    }
  }
  else {
    if (in_FPUControlWord != 0x27f) {
      in_EAX = FUN_100139a5();
      in_ST0 = extraout_ST0;
    }
    if (in_EAX < 0x3ff00000) {
      fpatan(SQRT(((float10)1 - in_ST0) * ((float10)1 + in_ST0)),in_ST0);
    }
    else if ((0x3ff00000 < in_EAX) || ((param_2 & 0xfffff) != 0 || param_1 != 0)) goto LAB_10010eac;
    if (DAT_100254d8 == 0) {
      __math_exit(&DAT_10020fc0,0xd,unaff_retaddr,param_1,param_2);
      return;
    }
  }
  return;
}



/* ===== FUN_10010ecb @ 0x10010ECB ===== */

int __cdecl FUN_10010ecb(int param_1,uint param_2)

{
  int iVar1;
  
  if ((param_2._2_2_ & 0x7ff0) == 0x7ff0) {
    iVar1 = FUN_10014dd6(param_1,(uint)(CONCAT26(param_2._2_2_,CONCAT24((undefined2)param_2,param_1)
                                                ) >> 0x20));
    if (iVar1 != 1) {
      if (iVar1 == 2) {
        iVar1 = 4;
      }
      else if (iVar1 == 3) {
        iVar1 = 2;
      }
      else {
        iVar1 = 1;
      }
      return iVar1;
    }
    return 0x200;
  }
  if (((param_2 & 0x7ff00000) == 0) && (((param_2 & 0xfffff) != 0 || (param_1 != 0)))) {
    return (-(uint)((param_2 & 0x80000000) != 0) & 0xffffff90) + 0x80;
  }
  if ((double)CONCAT26(param_2._2_2_,CONCAT24((undefined2)param_2,param_1)) == 0.0) {
    return (-(uint)((param_2 & 0x80000000) != 0) & 0xffffffe0) + 0x40;
  }
  return (-(uint)((param_2 & 0x80000000) != 0) & 0xffffff08) + 0x100;
}



/* ===== FUN_10010f60 @ 0x10010F60 ===== */

/* WARNING: Unable to track spacebase fully for stack */

void FUN_10010f60(void)

{
  uint in_EAX;
  undefined1 *puVar1;
  undefined4 unaff_retaddr;
  
  puVar1 = &stack0x00000004;
  for (; 0xfff < in_EAX; in_EAX = in_EAX - 0x1000) {
    puVar1 = puVar1 + -0x1000;
  }
  *(undefined4 *)(puVar1 + (-4 - in_EAX)) = unaff_retaddr;
  return;
}



/* ===== FUN_100110a7 @ 0x100110A7 ===== */

void FUN_100110a7(void)

{
  if (PTR_FUN_10020f74 != (undefined *)0x0) {
    (*(code *)PTR_FUN_10020f74)();
  }
  FUN_100111ab((undefined4 *)&DAT_1001e008,(undefined4 *)&DAT_1001e01c);
  FUN_100111ab((undefined4 *)&DAT_1001e000,(undefined4 *)&DAT_1001e004);
  return;
}



/* ===== __exit @ 0x100110D4 ===== */

/* Library Function - Single Match
    __exit
   
   Library: Visual Studio 2003 Release */

void __cdecl __exit(int _Code)

{
  FUN_100110f4(_Code,1,0);
  return;
}



/* ===== FUN_100110e5 @ 0x100110E5 ===== */

void FUN_100110e5(void)

{
  FUN_100110f4(0,0,1);
  return;
}



/* ===== FUN_100110f4 @ 0x100110F4 ===== */

void __cdecl FUN_100110f4(UINT param_1,int param_2,int param_3)

{
  HANDLE hProcess;
  undefined4 *puVar1;
  UINT uExitCode;
  
  FUN_10011199();
  if (DAT_10025534 == 1) {
    uExitCode = param_1;
    hProcess = GetCurrentProcess();
    TerminateProcess(hProcess,uExitCode);
  }
  DAT_10025530 = 1;
  DAT_1002552c = (undefined1)param_3;
  if (param_2 == 0) {
    if ((DAT_10026bf4 != (undefined4 *)0x0) &&
       (puVar1 = (undefined4 *)(DAT_10026bf0 - 4), DAT_10026bf4 <= puVar1)) {
      do {
        if ((code *)*puVar1 != (code *)0x0) {
          (*(code *)*puVar1)();
        }
        puVar1 = puVar1 + -1;
      } while (DAT_10026bf4 <= puVar1);
    }
    FUN_100111ab((undefined4 *)&DAT_1001e020,(undefined4 *)&DAT_1001e028);
  }
  FUN_100111ab((undefined4 *)&DAT_1001e02c,(undefined4 *)&DAT_1001e034);
  if (param_3 == 0) {
    DAT_10025534 = 1;
                    /* WARNING: Subroutine does not return */
    ExitProcess(param_1);
  }
  FUN_100111a2();
  return;
}



/* ===== FUN_10011199 @ 0x10011199 ===== */

void FUN_10011199(void)

{
  FUN_10013262(0xd);
  return;
}



/* ===== FUN_100111a2 @ 0x100111A2 ===== */

void FUN_100111a2(void)

{
  FUN_100132c3(0xd);
  return;
}



/* ===== FUN_100111ab @ 0x100111AB ===== */

void __cdecl FUN_100111ab(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* ===== FUN_100111c5 @ 0x100111C5 ===== */

int * __cdecl FUN_100111c5(int param_1,int param_2)

{
  int iVar1;
  uint *puVar2;
  uint *puVar3;
  uint *_Size;
  int *local_24;
  void *local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &DAT_1001c3f8;
  puStack_10 = &LAB_100132e0;
  local_14 = ExceptionList;
  puVar2 = (uint *)(param_1 * param_2);
  puVar3 = puVar2;
  ExceptionList = &local_14;
  if (puVar2 < (uint *)0xffffffe1) {
    if (puVar2 == (uint *)0x0) {
      puVar3 = (uint *)0x1;
    }
    puVar3 = (uint *)((int)puVar3 + 0xfU & 0xfffffff0);
    ExceptionList = &local_14;
  }
  do {
    local_24 = (int *)0x0;
    if (puVar3 < (uint *)0xffffffe1) {
      if (DAT_10026be4 == 3) {
        if (puVar2 <= DAT_10026bdc) {
          FUN_10013262(9);
          local_8 = 0;
          local_24 = FUN_100126f4(puVar2);
          local_8 = 0xffffffff;
          FUN_1001125e();
          _Size = puVar2;
          if (local_24 == (int *)0x0) goto LAB_100112b2;
LAB_100112a1:
          _memset(local_24,0,(size_t)_Size);
        }
LAB_100112ad:
        if (local_24 != (int *)0x0) {
          ExceptionList = local_14;
          return local_24;
        }
      }
      else {
        if ((DAT_10026be4 != 2) || (DAT_1002301c < puVar3)) goto LAB_100112ad;
        FUN_10013262(9);
        local_8 = 1;
        local_24 = FUN_10012ea1((uint)puVar3 >> 4);
        local_8 = 0xffffffff;
        FUN_100112e7();
        _Size = puVar3;
        if (local_24 != (int *)0x0) goto LAB_100112a1;
      }
LAB_100112b2:
      local_24 = HeapAlloc(DAT_10026be0,8,(SIZE_T)puVar3);
    }
    if (local_24 != (int *)0x0) {
      ExceptionList = local_14;
      return local_24;
    }
    if (DAT_10025538 == 0) {
      ExceptionList = local_14;
      return (int *)0x0;
    }
    iVar1 = FUN_100120c3(puVar3);
    if (iVar1 == 0) {
      ExceptionList = local_14;
      return (int *)0x0;
    }
  } while( true );
}



/* ===== FUN_1001125e @ 0x1001125E ===== */

void FUN_1001125e(void)

{
  FUN_100132c3(9);
  return;
}



/* ===== FUN_100112e7 @ 0x100112E7 ===== */

void FUN_100112e7(void)

{
  FUN_100132c3(9);
  return;
}



/* ===== FUN_10011302 @ 0x10011302 ===== */

void __fastcall FUN_10011302(void *param_1)

{
  FUN_100156bd(param_1,0x10000,0x30000);
  return;
}



/* ===== FUN_10011314 @ 0x10011314 ===== */

/* WARNING: Removing unreachable block (ram,0x10011349) */

undefined4 FUN_10011314(void)

{
  return 0;
}



/* ===== FUN_10011352 @ 0x10011352 ===== */

void FUN_10011352(void)

{
  HMODULE hModule;
  FARPROC pFVar1;
  
  hModule = GetModuleHandleA("KERNEL32");
  if (hModule != (HMODULE)0x0) {
    pFVar1 = GetProcAddress(hModule,"IsProcessorFeaturePresent");
    if (pFVar1 != (FARPROC)0x0) {
      (*pFVar1)(0);
      return;
    }
  }
  FUN_10011314();
  return;
}



/* ===== FUN_1001137b @ 0x1001137B ===== */

void __cdecl FUN_1001137b(char *param_1)

{
  char cVar1;
  char cVar2;
  undefined *this;
  uint uVar3;
  undefined *puVar4;
  
  this = (undefined *)(int)*param_1;
  uVar3 = FUN_100157ee((uint)this);
  if (uVar3 != 0x65) {
    do {
      param_1 = param_1 + 1;
      if (DAT_10023574 < 2) {
        uVar3 = (byte)PTR_DAT_10023368[*param_1 * 2] & 4;
        this = PTR_DAT_10023368;
      }
      else {
        puVar4 = (undefined *)0x4;
        uVar3 = FUN_100154f0(this,(int)*param_1,4);
        this = puVar4;
      }
    } while (uVar3 != 0);
  }
  cVar2 = *param_1;
  *param_1 = DAT_10023578;
  do {
    param_1 = param_1 + 1;
    cVar1 = *param_1;
    *param_1 = cVar2;
    cVar2 = cVar1;
  } while (*param_1 != '\0');
  return;
}



/* ===== __fassign @ 0x1001143B ===== */

/* Library Function - Single Match
    __fassign
   
   Library: Visual Studio 2003 Release */

void __cdecl __fassign(int flag,char *argument,char *number)

{
  void *in_ECX;
  void *local_c;
  void *local_8;
  
  if (flag != 0) {
    local_c = in_ECX;
    local_8 = in_ECX;
    FUN_10015cba(in_ECX,(uint *)&local_c,(byte *)number);
    *(void **)argument = local_c;
    *(void **)(argument + 4) = local_8;
    return;
  }
  FUN_10015ce7(in_ECX,(uint *)&number,(byte *)number);
  *(char **)argument = number;
  return;
}



/* ===== FUN_10011479 @ 0x10011479 ===== */

undefined1 * __cdecl FUN_10011479(undefined8 *param_1,undefined1 *param_2,int param_3,int param_4)

{
  uint local_2c [6];
  int local_14 [4];
  
  FUN_10015d8b((int)*param_1,(int)((ulonglong)*param_1 >> 0x20),local_14,local_2c);
  FUN_10015d14(param_2 + (uint)(0 < param_3) + (uint)(local_14[0] == 0x2d),param_3 + 1,(int)local_14
              );
  FUN_100114da(param_2,param_3,param_4,local_14,'\0');
  return param_2;
}



/* ===== FUN_100114da @ 0x100114DA ===== */

undefined1 * __cdecl
FUN_100114da(undefined1 *param_1,int param_2,int param_3,int *param_4,char param_5)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  uint *puVar3;
  int iVar4;
  
  if (param_5 != '\0') {
    FUN_1001177c(param_1 + (*param_4 == 0x2d),(uint)(0 < param_2));
  }
  puVar1 = param_1;
  if (*param_4 == 0x2d) {
    *param_1 = 0x2d;
    puVar1 = param_1 + 1;
  }
  puVar2 = puVar1;
  if (0 < param_2) {
    puVar2 = puVar1 + 1;
    *puVar1 = puVar1[1];
    *puVar2 = DAT_10023578;
  }
  puVar3 = FUN_10015ea0((uint *)(puVar2 + param_2 + (uint)(param_5 == '\0')),(uint *)"e+000");
  if (param_3 != 0) {
    *(undefined1 *)puVar3 = 0x45;
  }
  if (*(char *)param_4[3] != '0') {
    iVar4 = param_4[1] + -1;
    if (iVar4 < 0) {
      iVar4 = -iVar4;
      *(undefined1 *)((int)puVar3 + 1) = 0x2d;
    }
    if (99 < iVar4) {
      *(char *)((int)puVar3 + 2) = *(char *)((int)puVar3 + 2) + (char)(iVar4 / 100);
      iVar4 = iVar4 % 100;
    }
    if (9 < iVar4) {
      *(char *)((int)puVar3 + 3) = *(char *)((int)puVar3 + 3) + (char)(iVar4 / 10);
      iVar4 = iVar4 % 10;
    }
    *(char *)(puVar3 + 1) = (char)puVar3[1] + (char)iVar4;
  }
  return param_1;
}



/* ===== FUN_1001159c @ 0x1001159C ===== */

char * __cdecl FUN_1001159c(undefined8 *param_1,char *param_2,size_t param_3)

{
  uint local_2c [6];
  int local_14;
  int local_10;
  
  FUN_10015d8b((int)*param_1,(int)((ulonglong)*param_1 >> 0x20),&local_14,local_2c);
  FUN_10015d14(param_2 + (local_14 == 0x2d),local_10 + param_3,(int)&local_14);
  FUN_100115f1(param_2,param_3,&local_14,'\0');
  return param_2;
}



/* ===== FUN_100115f1 @ 0x100115F1 ===== */

char * __cdecl FUN_100115f1(char *param_1,size_t param_2,int *param_3,char param_4)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  
  iVar1 = param_3[1];
  if ((param_4 != '\0') && (iVar1 - 1U == param_2)) {
    iVar2 = *param_3;
    param_1[(uint)(iVar2 == 0x2d) + (iVar1 - 1U)] = '0';
    (param_1 + (uint)(iVar2 == 0x2d) + (iVar1 - 1U))[1] = '\0';
  }
  pcVar3 = param_1;
  if (*param_3 == 0x2d) {
    *param_1 = '-';
    pcVar3 = param_1 + 1;
  }
  if (param_3[1] < 1) {
    FUN_1001177c(pcVar3,1);
    *pcVar3 = '0';
    pcVar3 = pcVar3 + 1;
  }
  else {
    pcVar3 = pcVar3 + param_3[1];
  }
  if (0 < (int)param_2) {
    FUN_1001177c(pcVar3,1);
    *pcVar3 = DAT_10023578;
    iVar1 = param_3[1];
    if (iVar1 < 0) {
      if ((param_4 != '\0') || (-iVar1 <= (int)param_2)) {
        param_2 = -iVar1;
      }
      FUN_1001177c(pcVar3 + 1,param_2);
      _memset(pcVar3 + 1,0x30,param_2);
    }
  }
  return param_1;
}



/* ===== FUN_10011698 @ 0x10011698 ===== */

void __cdecl FUN_10011698(undefined8 *param_1,char *param_2,size_t param_3,int param_4)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  uint local_2c [6];
  int local_14;
  int local_10;
  
  FUN_10015d8b((int)*param_1,(int)((ulonglong)*param_1 >> 0x20),&local_14,local_2c);
  iVar1 = local_10 + -1;
  FUN_10015d14(param_2 + (local_14 == 0x2d),param_3,(int)&local_14);
  local_10 = local_10 + -1;
  if ((local_10 < -4) || ((int)param_3 <= local_10)) {
    FUN_100114da(param_2,param_3,param_4,&local_14,'\x01');
  }
  else {
    pcVar2 = param_2 + (local_14 == 0x2d);
    if (iVar1 < local_10) {
      do {
        pcVar3 = pcVar2;
        pcVar2 = pcVar3 + 1;
      } while (*pcVar3 != '\0');
      pcVar3[-1] = '\0';
    }
    FUN_100115f1(param_2,param_3,&local_14,'\x01');
  }
  return;
}



/* ===== __cfltcvt @ 0x1001172B ===== */

/* Library Function - Single Match
    __cfltcvt
   
   Library: Visual Studio 2003 Release */

errno_t __cdecl
__cfltcvt(double *arg,char *buffer,size_t sizeInBytes,int format,int precision,int caps)

{
  char *pcVar1;
  undefined1 *puVar2;
  
  if ((sizeInBytes == 0x65) || (sizeInBytes == 0x45)) {
    puVar2 = FUN_10011479(arg,buffer,format,precision);
  }
  else {
    if (sizeInBytes == 0x66) {
      pcVar1 = FUN_1001159c(arg,buffer,format);
      return (errno_t)pcVar1;
    }
    puVar2 = (undefined1 *)FUN_10011698(arg,buffer,format,precision);
  }
  return (errno_t)puVar2;
}



/* ===== FUN_1001177c @ 0x1001177C ===== */

void __cdecl FUN_1001177c(char *param_1,int param_2)

{
  size_t sVar1;
  
  if (param_2 != 0) {
    sVar1 = _strlen(param_1);
    FUN_10015f90((undefined4 *)(param_1 + param_2),(undefined4 *)param_1,sVar1 + 1);
  }
  return;
}



/* ===== FUN_100117a1 @ 0x100117A1 ===== */

uint __cdecl FUN_100117a1(uint param_1,int *param_2)

{
  uint uVar1;
  uint uVar2;
  char *pcVar3;
  int *piVar4;
  byte bVar5;
  undefined3 extraout_var;
  undefined *puVar6;
  int *piVar7;
  
  piVar4 = param_2;
  uVar1 = param_2[3];
  uVar2 = param_2[4];
  if (((uVar1 & 0x82) == 0) || ((uVar1 & 0x40) != 0)) {
LAB_100118ad:
    param_2[3] = uVar1 | 0x20;
  }
  else {
    if ((uVar1 & 1) != 0) {
      param_2[1] = 0;
      if ((uVar1 & 0x10) == 0) goto LAB_100118ad;
      *param_2 = param_2[2];
      param_2[3] = uVar1 & 0xfffffffe;
    }
    uVar1 = param_2[3];
    param_2[1] = 0;
    param_2 = (int *)0x0;
    piVar4[3] = uVar1 & 0xffffffef | 2;
    if (((uVar1 & 0x10c) == 0) &&
       (((piVar4 != (int *)&DAT_100235e0 && (piVar4 != (int *)&DAT_10023600)) ||
        (bVar5 = FUN_100165da(uVar2), CONCAT31(extraout_var,bVar5) == 0)))) {
      FUN_10016596(piVar4);
    }
    if ((*(ushort *)(piVar4 + 3) & 0x108) == 0) {
      piVar7 = (int *)0x1;
      param_2 = (int *)FUN_100163a6(uVar2,(char *)&param_1,1);
    }
    else {
      pcVar3 = (char *)piVar4[2];
      piVar7 = (int *)(*piVar4 - (int)pcVar3);
      *piVar4 = (int)(pcVar3 + 1);
      piVar4[1] = piVar4[6] + -1;
      if ((int)piVar7 < 1) {
        if (uVar2 == 0xffffffff) {
          puVar6 = &DAT_10023198;
        }
        else {
          puVar6 = (undefined *)((&DAT_10026ac0)[(int)uVar2 >> 5] + (uVar2 & 0x1f) * 0x24);
        }
        if ((puVar6[4] & 0x20) != 0) {
          FUN_100162ce(uVar2,0,2);
        }
      }
      else {
        param_2 = (int *)FUN_100163a6(uVar2,pcVar3,(uint)piVar7);
      }
      *(undefined1 *)piVar4[2] = (undefined1)param_1;
    }
    if (param_2 == piVar7) {
      return param_1 & 0xff;
    }
    piVar4[3] = piVar4[3] | 0x20;
  }
  return 0xffffffff;
}



/* ===== FUN_100118b9 @ 0x100118B9 ===== */

int __cdecl FUN_100118b9(int *param_1,byte *param_2,undefined4 *param_3)

{
  byte *pbVar1;
  uint uVar2;
  WCHAR *pWVar3;
  WCHAR *pWVar4;
  undefined4 uVar5;
  short *psVar6;
  int *piVar7;
  int iVar8;
  byte bVar9;
  int iVar10;
  uint uVar11;
  undefined1 *puVar12;
  ulonglong uVar13;
  undefined8 uVar14;
  ulonglong uVar15;
  undefined1 local_24c [511];
  undefined1 local_4d;
  undefined4 local_4c;
  undefined4 local_48;
  uint local_44;
  uint local_40;
  CHAR local_3c [4];
  undefined4 local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  char local_1a;
  char local_19;
  int local_18;
  int local_14;
  undefined1 *local_10;
  WCHAR *local_c;
  uint local_8;
  
  local_34 = 0;
  bVar9 = *param_2;
  local_10 = (undefined1 *)0x0;
  local_18 = 0;
  pbVar1 = param_2;
  do {
    if ((bVar9 == 0) || (param_2 = pbVar1 + 1, local_18 < 0)) {
      return local_18;
    }
    if (((char)bVar9 < ' ') || ('x' < (char)bVar9)) {
      uVar2 = 0;
    }
    else {
      uVar2 = (byte)"GAIsProcessorFeaturePresent"[(char)bVar9 + 0x12] & 0xf;
    }
    local_34 = (int)(char)(&DAT_1001c450)[uVar2 * 8 + local_34] >> 4;
    switch(local_34) {
    case 0:
switchD_10011927_caseD_0:
      local_28 = 0;
      if ((PTR_DAT_10023368[(uint)bVar9 * 2 + 1] & 0x80) != 0) {
        FUN_10011ffa((int)(char)bVar9,param_1,&local_18);
        bVar9 = *param_2;
        param_2 = pbVar1 + 2;
      }
      FUN_10011ffa((int)(char)bVar9,param_1,&local_18);
      break;
    case 1:
      local_14 = -1;
      local_38 = 0;
      local_2c = 0;
      local_24 = 0;
      local_20 = 0;
      local_8 = 0;
      local_28 = 0;
      break;
    case 2:
      if (bVar9 == 0x20) {
        local_8 = local_8 | 2;
      }
      else if (bVar9 == 0x23) {
        local_8 = local_8 | 0x80;
      }
      else if (bVar9 == 0x2b) {
        local_8 = local_8 | 1;
      }
      else if (bVar9 == 0x2d) {
        local_8 = local_8 | 4;
      }
      else if (bVar9 == 0x30) {
        local_8 = local_8 | 8;
      }
      break;
    case 3:
      if (bVar9 == 0x2a) {
        local_24 = FUN_10012098((int *)&param_3);
        if (local_24 < 0) {
          local_8 = local_8 | 4;
          local_24 = -local_24;
        }
      }
      else {
        local_24 = (char)bVar9 + -0x30 + local_24 * 10;
      }
      break;
    case 4:
      local_14 = 0;
      break;
    case 5:
      if (bVar9 == 0x2a) {
        local_14 = FUN_10012098((int *)&param_3);
        if (local_14 < 0) {
          local_14 = -1;
        }
      }
      else {
        local_14 = (char)bVar9 + -0x30 + local_14 * 10;
      }
      break;
    case 6:
      if (bVar9 == 0x49) {
        if ((*param_2 != 0x36) || (pbVar1[2] != 0x34)) {
          local_34 = 0;
          goto switchD_10011927_caseD_0;
        }
        param_2 = pbVar1 + 3;
        local_8 = local_8 | 0x8000;
      }
      else if (bVar9 == 0x68) {
        local_8 = local_8 | 0x20;
      }
      else if (bVar9 == 0x6c) {
        local_8 = local_8 | 0x10;
      }
      else if (bVar9 == 0x77) {
        local_8 = local_8 | 0x800;
      }
      break;
    case 7:
      pWVar4 = local_c;
      if ((char)bVar9 < 'h') {
        if ((char)bVar9 < 'e') {
          if ((char)bVar9 < 'Y') {
            if (bVar9 == 0x58) {
LAB_10011d38:
              local_30 = 7;
LAB_10011d3f:
              local_10 = (undefined1 *)0x10;
              if ((local_8 & 0x80) != 0) {
                local_1a = '0';
                local_19 = (char)local_30 + 'Q';
                local_20 = 2;
              }
              goto LAB_10011da9;
            }
            if (bVar9 != 0x43) {
              if ((bVar9 != 0x45) && (bVar9 != 0x47)) {
                if (bVar9 == 0x53) {
                  if ((local_8 & 0x830) == 0) {
                    local_8 = local_8 | 0x800;
                  }
                  goto LAB_10011ae6;
                }
                goto LAB_10011ec3;
              }
              local_38 = 1;
              bVar9 = bVar9 + 0x20;
              goto LAB_10011b47;
            }
            if ((local_8 & 0x830) == 0) {
              local_8 = local_8 | 0x800;
            }
LAB_10011b74:
            if ((local_8 & 0x810) == 0) {
              uVar5 = FUN_10012098((int *)&param_3);
              local_24c[0] = (char)uVar5;
              local_10 = (undefined1 *)0x1;
            }
            else {
              uVar5 = FUN_100120b5((int *)&param_3);
              local_10 = (undefined1 *)FUN_10016763(local_24c,(WCHAR)uVar5);
              if ((int)local_10 < 0) {
                local_2c = 1;
              }
            }
            pWVar4 = (WCHAR *)local_24c;
          }
          else if (bVar9 == 0x5a) {
            psVar6 = (short *)FUN_10012098((int *)&param_3);
            if ((psVar6 == (short *)0x0) ||
               (pWVar4 = *(WCHAR **)(psVar6 + 2), pWVar4 == (WCHAR *)0x0)) {
              local_c = (WCHAR *)PTR_DAT_10020fec;
              pWVar4 = (WCHAR *)PTR_DAT_10020fec;
              goto LAB_10011cb9;
            }
            if ((local_8 & 0x800) == 0) {
              local_28 = 0;
              local_10 = (undefined1 *)(int)*psVar6;
            }
            else {
              local_28 = 1;
              local_10 = (undefined1 *)((uint)(int)*psVar6 >> 1);
            }
          }
          else {
            if (bVar9 == 99) goto LAB_10011b74;
            if (bVar9 == 100) goto LAB_10011d9e;
          }
        }
        else {
LAB_10011b47:
          local_8 = local_8 | 0x40;
          pWVar4 = (WCHAR *)local_24c;
          if (local_14 < 0) {
            local_14 = 6;
          }
          else if ((local_14 == 0) && (bVar9 == 0x67)) {
            local_14 = 1;
          }
          local_4c = *param_3;
          local_48 = param_3[1];
          param_3 = param_3 + 2;
          local_c = pWVar4;
          (*(code *)PTR___fptrap_10020fd4)(&local_4c,local_24c,(int)(char)bVar9,local_14,local_38);
          uVar2 = local_8 & 0x80;
          if ((uVar2 != 0) && (local_14 == 0)) {
            (*(code *)PTR___fptrap_10020fe0)(local_24c);
          }
          if ((bVar9 == 0x67) && (uVar2 == 0)) {
            (*(code *)PTR___fptrap_10020fd8)(local_24c);
          }
          if (local_24c[0] == '-') {
            local_8 = local_8 | 0x100;
            pWVar4 = (WCHAR *)(local_24c + 1);
            local_c = pWVar4;
          }
LAB_10011cb9:
          local_10 = (undefined1 *)_strlen((char *)pWVar4);
          pWVar4 = local_c;
        }
      }
      else {
        if (bVar9 == 0x69) {
LAB_10011d9e:
          local_8 = local_8 | 0x40;
        }
        else {
          if (bVar9 == 0x6e) {
            piVar7 = (int *)FUN_10012098((int *)&param_3);
            if ((local_8 & 0x20) == 0) {
              *piVar7 = local_18;
            }
            else {
              *(undefined2 *)piVar7 = (undefined2)local_18;
            }
            local_2c = 1;
            break;
          }
          if (bVar9 == 0x6f) {
            local_10 = (undefined1 *)0x8;
            if ((local_8 & 0x80) != 0) {
              local_8 = local_8 | 0x200;
            }
            goto LAB_10011da9;
          }
          if (bVar9 == 0x70) {
            local_14 = 8;
            goto LAB_10011d38;
          }
          if (bVar9 == 0x73) {
LAB_10011ae6:
            iVar10 = local_14;
            if (local_14 == -1) {
              iVar10 = 0x7fffffff;
            }
            pWVar3 = (WCHAR *)FUN_10012098((int *)&param_3);
            if ((local_8 & 0x810) == 0) {
              pWVar4 = pWVar3;
              if (pWVar3 == (WCHAR *)0x0) {
                pWVar3 = (WCHAR *)PTR_DAT_10020fec;
                pWVar4 = (WCHAR *)PTR_DAT_10020fec;
              }
              for (; (iVar10 != 0 && ((char)*pWVar3 != '\0')); pWVar3 = (WCHAR *)((int)pWVar3 + 1))
              {
                iVar10 = iVar10 + -1;
              }
              local_10 = (undefined1 *)((int)pWVar3 - (int)pWVar4);
            }
            else {
              if (pWVar3 == (WCHAR *)0x0) {
                pWVar3 = (WCHAR *)PTR_DAT_10020ff0;
              }
              local_28 = 1;
              for (pWVar4 = pWVar3; (iVar10 != 0 && (*pWVar4 != L'\0')); pWVar4 = pWVar4 + 1) {
                iVar10 = iVar10 + -1;
              }
              local_10 = (undefined1 *)((int)pWVar4 - (int)pWVar3 >> 1);
              pWVar4 = pWVar3;
            }
            goto LAB_10011ec3;
          }
          if (bVar9 != 0x75) {
            if (bVar9 != 0x78) goto LAB_10011ec3;
            local_30 = 0x27;
            goto LAB_10011d3f;
          }
        }
        local_10 = (undefined1 *)0xa;
LAB_10011da9:
        if ((local_8 & 0x8000) == 0) {
          if ((local_8 & 0x20) == 0) {
            if ((local_8 & 0x40) == 0) {
              uVar2 = FUN_10012098((int *)&param_3);
              uVar13 = (ulonglong)uVar2;
              goto LAB_10011dfc;
            }
            uVar2 = FUN_10012098((int *)&param_3);
          }
          else if ((local_8 & 0x40) == 0) {
            uVar2 = FUN_10012098((int *)&param_3);
            uVar2 = uVar2 & 0xffff;
          }
          else {
            uVar5 = FUN_10012098((int *)&param_3);
            uVar2 = (uint)(short)uVar5;
          }
          uVar13 = (ulonglong)(int)uVar2;
        }
        else {
          uVar13 = FUN_100120a5((int *)&param_3);
        }
LAB_10011dfc:
        iVar10 = (int)(uVar13 >> 0x20);
        if ((((local_8 & 0x40) != 0) && (iVar10 == 0 || (longlong)uVar13 < 0)) &&
           ((longlong)uVar13 < 0)) {
          local_8 = local_8 | 0x100;
          uVar13 = CONCAT44(-(iVar10 + (uint)((int)uVar13 != 0)),-(int)uVar13);
        }
        uVar2 = (uint)(uVar13 >> 0x20);
        uVar15 = uVar13 & 0xffffffff;
        if ((local_8 & 0x8000) == 0) {
          uVar2 = 0;
        }
        if (local_14 < 0) {
          local_14 = 1;
        }
        else {
          local_8 = local_8 & 0xfffffff7;
        }
        if ((int)uVar13 == 0 && uVar2 == 0) {
          local_20 = 0;
        }
        local_c = (WCHAR *)&local_4d;
        while( true ) {
          uVar11 = (uint)uVar15;
          iVar10 = local_14 + -1;
          if ((local_14 < 1) && (uVar11 == 0 && uVar2 == 0)) break;
          local_40 = (int)local_10 >> 0x1f;
          local_44 = (uint)local_10;
          local_14 = iVar10;
          uVar14 = __aullrem(uVar11,uVar2,(uint)local_10,local_40);
          iVar10 = (int)uVar14 + 0x30;
          uVar15 = __aulldiv(uVar11,uVar2,local_44,local_40);
          uVar2 = (uint)(uVar15 >> 0x20);
          if (0x39 < iVar10) {
            iVar10 = iVar10 + local_30;
          }
          pWVar4 = (WCHAR *)((int)local_c + -1);
          *(char *)local_c = (char)iVar10;
          local_c = pWVar4;
        }
        iVar8 = -(int)local_c;
        local_10 = &local_4d + iVar8;
        pWVar4 = (WCHAR *)((int)local_c + 1);
        local_14 = iVar10;
        if (((local_8 & 0x200) != 0) &&
           ((*(char *)pWVar4 != '0' || (local_10 == (undefined1 *)0x0)))) {
          *(char *)local_c = '0';
          local_10 = (undefined1 *)((int)&local_4c + iVar8);
          pWVar4 = local_c;
        }
      }
LAB_10011ec3:
      local_c = pWVar4;
      uVar2 = local_8;
      if (local_2c == 0) {
        if ((local_8 & 0x40) != 0) {
          if ((local_8 & 0x100) == 0) {
            if ((local_8 & 1) == 0) {
              if ((local_8 & 2) == 0) goto LAB_10011efb;
              local_1a = ' ';
            }
            else {
              local_1a = '+';
            }
          }
          else {
            local_1a = '-';
          }
          local_20 = 1;
        }
LAB_10011efb:
        iVar10 = (local_24 - local_20) - (int)local_10;
        if ((local_8 & 0xc) == 0) {
          FUN_1001202f(0x20,iVar10,param_1,&local_18);
        }
        FUN_10012060(&local_1a,local_20,param_1,&local_18);
        if (((uVar2 & 8) != 0) && ((uVar2 & 4) == 0)) {
          FUN_1001202f(0x30,iVar10,param_1,&local_18);
        }
        if ((local_28 == 0) || (puVar12 = local_10, pWVar4 = local_c, (int)local_10 < 1)) {
          FUN_10012060((char *)local_c,(int)local_10,param_1,&local_18);
        }
        else {
          do {
            puVar12 = puVar12 + -1;
            iVar8 = FUN_10016763(local_3c,*pWVar4);
            if (iVar8 < 1) break;
            FUN_10012060(local_3c,iVar8,param_1,&local_18);
            pWVar4 = pWVar4 + 1;
          } while (puVar12 != (undefined1 *)0x0);
        }
        if ((local_8 & 4) != 0) {
          FUN_1001202f(0x20,iVar10,param_1,&local_18);
        }
      }
    }
    bVar9 = *param_2;
    pbVar1 = param_2;
  } while( true );
}



/* ===== FUN_10011ffa @ 0x10011FFA ===== */

void __cdecl FUN_10011ffa(uint param_1,int *param_2,int *param_3)

{
  int *piVar1;
  uint uVar2;
  
  piVar1 = param_2 + 1;
  *piVar1 = *piVar1 + -1;
  if (*piVar1 < 0) {
    uVar2 = FUN_100117a1(param_1,param_2);
  }
  else {
    *(undefined1 *)*param_2 = (undefined1)param_1;
    *param_2 = *param_2 + 1;
    uVar2 = param_1 & 0xff;
  }
  if (uVar2 == 0xffffffff) {
    *param_3 = -1;
    return;
  }
  *param_3 = *param_3 + 1;
  return;
}



/* ===== FUN_1001202f @ 0x1001202F ===== */

void __cdecl FUN_1001202f(uint param_1,int param_2,int *param_3,int *param_4)

{
  do {
    if (param_2 < 1) {
      return;
    }
    param_2 = param_2 + -1;
    FUN_10011ffa(param_1,param_3,param_4);
  } while (*param_4 != -1);
  return;
}



/* ===== FUN_10012060 @ 0x10012060 ===== */

void __cdecl FUN_10012060(char *param_1,int param_2,int *param_3,int *param_4)

{
  char cVar1;
  
  do {
    if (param_2 < 1) {
      return;
    }
    param_2 = param_2 + -1;
    cVar1 = *param_1;
    param_1 = param_1 + 1;
    FUN_10011ffa((int)cVar1,param_3,param_4);
  } while (*param_4 != -1);
  return;
}



/* ===== FUN_10012098 @ 0x10012098 ===== */

undefined4 __cdecl FUN_10012098(int *param_1)

{
  *param_1 = *param_1 + 4;
  return *(undefined4 *)(*param_1 + -4);
}



/* ===== FUN_100120a5 @ 0x100120A5 ===== */

undefined8 __cdecl FUN_100120a5(int *param_1)

{
  *param_1 = *param_1 + 8;
  return *(undefined8 *)(*param_1 + -8);
}



/* ===== FUN_100120b5 @ 0x100120B5 ===== */

undefined4 __cdecl FUN_100120b5(int *param_1)

{
  *param_1 = *param_1 + 4;
  return CONCAT22((short)((uint)*param_1 >> 0x10),*(undefined2 *)(*param_1 + -4));
}



/* ===== FUN_100120c3 @ 0x100120C3 ===== */

undefined4 __cdecl FUN_100120c3(undefined4 param_1)

{
  int iVar1;
  
  if (DAT_1002553c != (code *)0x0) {
    iVar1 = (*DAT_1002553c)(param_1);
    if (iVar1 != 0) {
      return 1;
    }
  }
  return 0;
}



/* ===== FUN_100120de @ 0x100120DE ===== */

void __cdecl FUN_100120de(undefined4 *param_1)

{
  int iVar1;
  HMODULE pHVar2;
  
  *param_1 = 0;
  pHVar2 = GetModuleHandleA((LPCSTR)0x0);
  if (((short)pHVar2->unused == 0x5a4d) && (iVar1 = pHVar2[0xf].unused, iVar1 != 0)) {
    *(undefined1 *)param_1 = *(undefined1 *)((int)&pHVar2[6].unused + iVar1 + 2);
    *(undefined1 *)((int)param_1 + 1) = *(undefined1 *)((int)&pHVar2[6].unused + iVar1 + 3);
  }
  return;
}



/* ===== FUN_1001210b @ 0x1001210B ===== */

int FUN_1001210b(void)

{
  char cVar1;
  byte bVar2;
  BOOL BVar3;
  DWORD DVar4;
  int iVar5;
  byte *pbVar6;
  char *pcVar7;
  byte *this;
  byte unaff_BL;
  char local_1230 [4240];
  char local_1a0 [260];
  DWORD local_9c;
  uint local_98;
  DWORD local_8c;
  CHAR aCStackY_18 [4];
  
  FUN_10010f60();
  local_9c = 0x94;
  BVar3 = GetVersionExA((LPOSVERSIONINFOA)&local_9c);
  if (((BVar3 == 0) || (local_8c != 2)) || (local_98 < 5)) {
    builtin_memcpy(aCStackY_18,"e!\x01\x10",4);
    DVar4 = GetEnvironmentVariableA("__MSVCRT_HEAP_SELECT",local_1230,0x1090);
    if (DVar4 != 0) {
      pcVar7 = local_1230;
      while (local_1230[0] != '\0') {
        cVar1 = *pcVar7;
        if (('`' < cVar1) && (cVar1 < '{')) {
          *pcVar7 = cVar1 + -0x20;
        }
        pcVar7 = pcVar7 + 1;
        local_1230[0] = *pcVar7;
      }
      aCStackY_18[0] = -0x5d;
      aCStackY_18[1] = '!';
      aCStackY_18[2] = '\x01';
      aCStackY_18[3] = '\x10';
      iVar5 = _strncmp("__GLOBAL_HEAP_SELECTED",local_1230,0x16);
      if (iVar5 == 0) {
        pcVar7 = local_1230;
      }
      else {
        aCStackY_18[0] = -0x3b;
        aCStackY_18[1] = '!';
        aCStackY_18[2] = '\x01';
        aCStackY_18[3] = '\x10';
        GetModuleFileNameA((HMODULE)0x0,local_1a0,0x104);
        pcVar7 = local_1a0;
        while (local_1a0[0] != '\0') {
          cVar1 = *pcVar7;
          if (('`' < cVar1) && (cVar1 < '{')) {
            *pcVar7 = cVar1 + -0x20;
          }
          pcVar7 = pcVar7 + 1;
          local_1a0[0] = *pcVar7;
        }
        pcVar7 = _strstr(local_1230,local_1a0);
      }
      if ((pcVar7 != (char *)0x0) && (pcVar7 = _strchr(pcVar7,0x2c), pcVar7 != (char *)0x0)) {
        pbVar6 = (byte *)(pcVar7 + 1);
        bVar2 = *pbVar6;
        this = pbVar6;
        while (bVar2 != 0) {
          if (*this == 0x3b) {
            *this = 0;
          }
          else {
            this = this + 1;
          }
          bVar2 = *this;
        }
        builtin_memcpy(aCStackY_18,"+\"\x01\x10",4);
        iVar5 = FUN_10016915(this,pbVar6,(int *)0x0,(void *)0xa);
        if (iVar5 == 2) {
          return 2;
        }
        if (iVar5 == 3) {
          return 3;
        }
        if (iVar5 == 1) {
          return 1;
        }
      }
    }
    FUN_100120de((undefined4 *)&stack0xfffffff8);
    iVar5 = 3 - (uint)(unaff_BL < 6);
  }
  else {
    iVar5 = 1;
  }
  return iVar5;
}



/* ===== FUN_10012253 @ 0x10012253 ===== */

undefined4 __cdecl FUN_10012253(int param_1)

{
  undefined **ppuVar1;
  
  DAT_10026be0 = HeapCreate((uint)(param_1 == 0),0x1000,0);
  if (DAT_10026be0 != (HANDLE)0x0) {
    DAT_10026be4 = FUN_1001210b();
    if (DAT_10026be4 == 3) {
      ppuVar1 = (undefined **)FUN_10012358(0x3f8);
    }
    else {
      if (DAT_10026be4 != 2) {
        return 1;
      }
      ppuVar1 = FUN_10012ba9();
    }
    if (ppuVar1 != (undefined **)0x0) {
      return 1;
    }
    HeapDestroy(DAT_10026be0);
  }
  return 0;
}



/* ===== FUN_100122b0 @ 0x100122B0 ===== */

void FUN_100122b0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined **ppuVar3;
  
  if (DAT_10026be4 == 3) {
    iVar1 = 0;
    if (0 < DAT_10026bd4) {
      puVar2 = (undefined4 *)((int)DAT_10026bd8 + 0xc);
      do {
        VirtualFree((LPVOID)*puVar2,0x100000,0x4000);
        VirtualFree((LPVOID)*puVar2,0,0x8000);
        HeapFree(DAT_10026be0,0,(LPVOID)puVar2[1]);
        puVar2 = puVar2 + 5;
        iVar1 = iVar1 + 1;
      } while (iVar1 < DAT_10026bd4);
    }
    HeapFree(DAT_10026be0,0,DAT_10026bd8);
  }
  else if (DAT_10026be4 == 2) {
    ppuVar3 = &PTR_LOOP_10020ff8;
    do {
      if (ppuVar3[4] != (undefined *)0x0) {
        VirtualFree(ppuVar3[4],0,0x8000);
      }
      ppuVar3 = (undefined **)*ppuVar3;
    } while (ppuVar3 != &PTR_LOOP_10020ff8);
  }
  HeapDestroy(DAT_10026be0);
  return;
}



/* ===== FUN_10012358 @ 0x10012358 ===== */

undefined4 __cdecl FUN_10012358(undefined4 param_1)

{
  DAT_10026bd8 = HeapAlloc(DAT_10026be0,0,0x140);
  if (DAT_10026bd8 == (LPVOID)0x0) {
    return 0;
  }
  DAT_10026bd0 = 0;
  DAT_10026bd4 = 0;
  DAT_10026bcc = DAT_10026bd8;
  DAT_10026bdc = param_1;
  DAT_10026bc4 = 0x10;
  return 1;
}



/* ===== FUN_100123a0 @ 0x100123A0 ===== */

uint __cdecl FUN_100123a0(int param_1)

{
  uint uVar1;
  
  uVar1 = DAT_10026bd8;
  while( true ) {
    if (DAT_10026bd8 + DAT_10026bd4 * 0x14 <= uVar1) {
      return 0;
    }
    if ((uint)(param_1 - *(int *)(uVar1 + 0xc)) < 0x100000) break;
    uVar1 = uVar1 + 0x14;
  }
  return uVar1;
}



/* ===== FUN_100123cb @ 0x100123CB ===== */

void __cdecl FUN_100123cb(uint *param_1,int param_2)

{
  char *pcVar1;
  uint *puVar2;
  int *piVar3;
  char cVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  byte bVar8;
  uint uVar9;
  uint *puVar10;
  uint *puVar11;
  uint *puVar12;
  uint uVar13;
  uint uVar14;
  uint local_8;
  
  uVar5 = param_1[4];
  puVar12 = (uint *)(param_2 + -4);
  uVar14 = param_2 - param_1[3] >> 0xf;
  piVar3 = (int *)(uVar14 * 0x204 + 0x144 + uVar5);
  uVar13 = *puVar12;
  local_8 = uVar13 - 1;
  if ((local_8 & 1) == 0) {
    uVar6 = *(uint *)(local_8 + (int)puVar12);
    uVar7 = *(uint *)(param_2 + -8);
    if ((uVar6 & 1) == 0) {
      uVar9 = ((int)uVar6 >> 4) - 1;
      if (0x3f < uVar9) {
        uVar9 = 0x3f;
      }
      if (*(int *)((int)puVar12 + uVar13 + 3) == *(int *)((int)puVar12 + uVar13 + 7)) {
        if (uVar9 < 0x20) {
          pcVar1 = (char *)(uVar9 + 4 + uVar5);
          uVar9 = ~(0x80000000U >> ((byte)uVar9 & 0x1f));
          puVar10 = (uint *)(uVar5 + 0x44 + uVar14 * 4);
          *puVar10 = *puVar10 & uVar9;
          *pcVar1 = *pcVar1 + -1;
          if (*pcVar1 == '\0') {
            *param_1 = *param_1 & uVar9;
          }
        }
        else {
          pcVar1 = (char *)(uVar9 + 4 + uVar5);
          uVar9 = ~(0x80000000U >> ((byte)uVar9 - 0x20 & 0x1f));
          puVar10 = (uint *)(uVar5 + 0xc4 + uVar14 * 4);
          *puVar10 = *puVar10 & uVar9;
          *pcVar1 = *pcVar1 + -1;
          if (*pcVar1 == '\0') {
            param_1[1] = param_1[1] & uVar9;
          }
        }
      }
      local_8 = local_8 + uVar6;
      *(undefined4 *)(*(int *)((int)puVar12 + uVar13 + 7) + 4) =
           *(undefined4 *)((int)puVar12 + uVar13 + 3);
      *(undefined4 *)(*(int *)((int)puVar12 + uVar13 + 3) + 8) =
           *(undefined4 *)((int)puVar12 + uVar13 + 7);
    }
    puVar10 = (uint *)(((int)local_8 >> 4) - 1);
    if ((uint *)0x3f < puVar10) {
      puVar10 = (uint *)0x3f;
    }
    puVar11 = param_1;
    if ((uVar7 & 1) == 0) {
      puVar12 = (uint *)((int)puVar12 - uVar7);
      puVar11 = (uint *)(((int)uVar7 >> 4) - 1);
      if ((uint *)0x3f < puVar11) {
        puVar11 = (uint *)0x3f;
      }
      local_8 = local_8 + uVar7;
      puVar10 = (uint *)(((int)local_8 >> 4) - 1);
      if ((uint *)0x3f < puVar10) {
        puVar10 = (uint *)0x3f;
      }
      if (puVar11 != puVar10) {
        if (puVar12[1] == puVar12[2]) {
          if (puVar11 < (uint *)0x20) {
            uVar13 = ~(0x80000000U >> ((byte)puVar11 & 0x1f));
            puVar2 = (uint *)(uVar5 + 0x44 + uVar14 * 4);
            *puVar2 = *puVar2 & uVar13;
            pcVar1 = (char *)((int)puVar11 + uVar5 + 4);
            *pcVar1 = *pcVar1 + -1;
            if (*pcVar1 == '\0') {
              *param_1 = *param_1 & uVar13;
            }
          }
          else {
            uVar13 = ~(0x80000000U >> ((byte)puVar11 - 0x20 & 0x1f));
            puVar2 = (uint *)(uVar5 + 0xc4 + uVar14 * 4);
            *puVar2 = *puVar2 & uVar13;
            pcVar1 = (char *)((int)puVar11 + uVar5 + 4);
            *pcVar1 = *pcVar1 + -1;
            if (*pcVar1 == '\0') {
              param_1[1] = param_1[1] & uVar13;
            }
          }
        }
        *(uint *)(puVar12[2] + 4) = puVar12[1];
        *(uint *)(puVar12[1] + 8) = puVar12[2];
      }
    }
    if (((uVar7 & 1) != 0) || (puVar11 != puVar10)) {
      puVar12[1] = piVar3[(int)puVar10 * 2 + 1];
      puVar12[2] = (uint)(piVar3 + (int)puVar10 * 2);
      (piVar3 + (int)puVar10 * 2)[1] = (int)puVar12;
      *(uint **)(puVar12[1] + 8) = puVar12;
      if (puVar12[1] == puVar12[2]) {
        cVar4 = *(char *)((int)puVar10 + uVar5 + 4);
        *(char *)((int)puVar10 + uVar5 + 4) = cVar4 + '\x01';
        bVar8 = (byte)puVar10;
        if (puVar10 < (uint *)0x20) {
          if (cVar4 == '\0') {
            *param_1 = *param_1 | 0x80000000U >> (bVar8 & 0x1f);
          }
          puVar10 = (uint *)(uVar5 + 0x44 + uVar14 * 4);
          *puVar10 = *puVar10 | 0x80000000U >> (bVar8 & 0x1f);
        }
        else {
          if (cVar4 == '\0') {
            param_1[1] = param_1[1] | 0x80000000U >> (bVar8 - 0x20 & 0x1f);
          }
          puVar10 = (uint *)(uVar5 + 0xc4 + uVar14 * 4);
          *puVar10 = *puVar10 | 0x80000000U >> (bVar8 - 0x20 & 0x1f);
        }
      }
    }
    *puVar12 = local_8;
    *(uint *)((local_8 - 4) + (int)puVar12) = local_8;
    *piVar3 = *piVar3 + -1;
    if (*piVar3 == 0) {
      if (DAT_10026bd0 != (uint *)0x0) {
        VirtualFree((LPVOID)(DAT_10026bc8 * 0x8000 + DAT_10026bd0[3]),0x8000,0x4000);
        DAT_10026bd0[2] = DAT_10026bd0[2] | 0x80000000U >> ((byte)DAT_10026bc8 & 0x1f);
        *(undefined4 *)(DAT_10026bd0[4] + 0xc4 + DAT_10026bc8 * 4) = 0;
        *(char *)(DAT_10026bd0[4] + 0x43) = *(char *)(DAT_10026bd0[4] + 0x43) + -1;
        if (*(char *)(DAT_10026bd0[4] + 0x43) == '\0') {
          DAT_10026bd0[1] = DAT_10026bd0[1] & 0xfffffffe;
        }
        if (DAT_10026bd0[2] == 0xffffffff) {
          VirtualFree((LPVOID)DAT_10026bd0[3],0,0x8000);
          HeapFree(DAT_10026be0,0,(LPVOID)DAT_10026bd0[4]);
          FUN_10015f90(DAT_10026bd0,DAT_10026bd0 + 5,
                       (DAT_10026bd4 * 0x14 - (int)DAT_10026bd0) + -0x14 + DAT_10026bd8);
          DAT_10026bd4 = DAT_10026bd4 + -1;
          if (DAT_10026bd0 < param_1) {
            param_1 = param_1 + -5;
          }
          DAT_10026bcc = DAT_10026bd8;
        }
      }
      DAT_10026bd0 = param_1;
      DAT_10026bc8 = uVar14;
    }
  }
  return;
}



/* ===== FUN_100126f4 @ 0x100126F4 ===== */

int * __cdecl FUN_100126f4(uint *param_1)

{
  char *pcVar1;
  int *piVar2;
  char cVar3;
  int *piVar4;
  byte bVar5;
  uint uVar6;
  int iVar7;
  uint *puVar8;
  int iVar9;
  int *piVar10;
  uint *puVar11;
  uint *puVar12;
  uint uVar13;
  int iVar14;
  uint local_10;
  uint local_c;
  int local_8;
  
  puVar8 = DAT_10026bd8 + DAT_10026bd4 * 5;
  uVar6 = (int)param_1 + 0x17U & 0xfffffff0;
  iVar7 = ((int)((int)param_1 + 0x17U) >> 4) + -1;
  bVar5 = (byte)iVar7;
  param_1 = DAT_10026bcc;
  if (iVar7 < 0x20) {
    local_10 = 0xffffffff >> (bVar5 & 0x1f);
    local_c = 0xffffffff;
  }
  else {
    local_c = 0xffffffff >> (bVar5 - 0x20 & 0x1f);
    local_10 = 0;
  }
  for (; (param_1 < puVar8 && ((param_1[1] & local_c) == 0 && (*param_1 & local_10) == 0));
      param_1 = param_1 + 5) {
  }
  puVar11 = DAT_10026bd8;
  if (param_1 == puVar8) {
    for (; (puVar11 < DAT_10026bcc && ((puVar11[1] & local_c) == 0 && (*puVar11 & local_10) == 0));
        puVar11 = puVar11 + 5) {
    }
    param_1 = puVar11;
    if (puVar11 == DAT_10026bcc) {
      for (; (puVar11 < puVar8 && (puVar11[2] == 0)); puVar11 = puVar11 + 5) {
      }
      puVar12 = DAT_10026bd8;
      param_1 = puVar11;
      if (puVar11 == puVar8) {
        for (; (puVar12 < DAT_10026bcc && (puVar12[2] == 0)); puVar12 = puVar12 + 5) {
        }
        param_1 = puVar12;
        if ((puVar12 == DAT_10026bcc) && (param_1 = FUN_100129fd(), param_1 == (uint *)0x0)) {
          return (int *)0x0;
        }
      }
      iVar7 = FUN_10012aae((int)param_1);
      *(int *)param_1[4] = iVar7;
      if (*(int *)param_1[4] == -1) {
        return (int *)0x0;
      }
    }
  }
  piVar4 = (int *)param_1[4];
  local_8 = *piVar4;
  if ((local_8 == -1) ||
     ((piVar4[local_8 + 0x31] & local_c) == 0 && (piVar4[local_8 + 0x11] & local_10) == 0)) {
    local_8 = 0;
    puVar8 = (uint *)(piVar4 + 0x11);
    if ((piVar4[0x31] & local_c) == 0 && (piVar4[0x11] & local_10) == 0) {
      do {
        puVar11 = puVar8 + 0x21;
        local_8 = local_8 + 1;
        puVar8 = puVar8 + 1;
      } while ((*puVar11 & local_c) == 0 && (local_10 & *puVar8) == 0);
    }
  }
  iVar7 = 0;
  piVar2 = piVar4 + local_8 * 0x81 + 0x51;
  local_10 = piVar4[local_8 + 0x11] & local_10;
  if (local_10 == 0) {
    local_10 = piVar4[local_8 + 0x31] & local_c;
    iVar7 = 0x20;
  }
  for (; -1 < (int)local_10; local_10 = local_10 << 1) {
    iVar7 = iVar7 + 1;
  }
  piVar10 = (int *)piVar2[iVar7 * 2 + 1];
  iVar9 = *piVar10 - uVar6;
  iVar14 = (iVar9 >> 4) + -1;
  if (0x3f < iVar14) {
    iVar14 = 0x3f;
  }
  DAT_10026bcc = param_1;
  if (iVar14 != iVar7) {
    if (piVar10[1] == piVar10[2]) {
      if (iVar7 < 0x20) {
        pcVar1 = (char *)((int)piVar4 + iVar7 + 4);
        uVar13 = ~(0x80000000U >> ((byte)iVar7 & 0x1f));
        piVar4[local_8 + 0x11] = uVar13 & piVar4[local_8 + 0x11];
        *pcVar1 = *pcVar1 + -1;
        if (*pcVar1 == '\0') {
          *param_1 = *param_1 & uVar13;
        }
      }
      else {
        pcVar1 = (char *)((int)piVar4 + iVar7 + 4);
        uVar13 = ~(0x80000000U >> ((byte)iVar7 - 0x20 & 0x1f));
        piVar4[local_8 + 0x31] = piVar4[local_8 + 0x31] & uVar13;
        *pcVar1 = *pcVar1 + -1;
        if (*pcVar1 == '\0') {
          param_1[1] = param_1[1] & uVar13;
        }
      }
    }
    *(int *)(piVar10[2] + 4) = piVar10[1];
    *(int *)(piVar10[1] + 8) = piVar10[2];
    if (iVar9 == 0) goto LAB_100129ba;
    piVar10[1] = piVar2[iVar14 * 2 + 1];
    piVar10[2] = (int)(piVar2 + iVar14 * 2);
    (piVar2 + iVar14 * 2)[1] = (int)piVar10;
    *(int **)(piVar10[1] + 8) = piVar10;
    if (piVar10[1] == piVar10[2]) {
      cVar3 = *(char *)(iVar14 + 4 + (int)piVar4);
      bVar5 = (byte)iVar14;
      if (iVar14 < 0x20) {
        *(char *)(iVar14 + 4 + (int)piVar4) = cVar3 + '\x01';
        if (cVar3 == '\0') {
          *param_1 = *param_1 | 0x80000000U >> (bVar5 & 0x1f);
        }
        piVar4[local_8 + 0x11] = piVar4[local_8 + 0x11] | 0x80000000U >> (bVar5 & 0x1f);
      }
      else {
        *(char *)(iVar14 + 4 + (int)piVar4) = cVar3 + '\x01';
        if (cVar3 == '\0') {
          param_1[1] = param_1[1] | 0x80000000U >> (bVar5 - 0x20 & 0x1f);
        }
        piVar4[local_8 + 0x31] = piVar4[local_8 + 0x31] | 0x80000000U >> (bVar5 - 0x20 & 0x1f);
      }
    }
  }
  if (iVar9 != 0) {
    *piVar10 = iVar9;
    *(int *)(iVar9 + -4 + (int)piVar10) = iVar9;
  }
LAB_100129ba:
  piVar10 = (int *)((int)piVar10 + iVar9);
  *piVar10 = uVar6 + 1;
  *(uint *)((int)piVar10 + (uVar6 - 4)) = uVar6 + 1;
  iVar7 = *piVar2;
  *piVar2 = iVar7 + 1;
  if (((iVar7 == 0) && (param_1 == DAT_10026bd0)) && (local_8 == DAT_10026bc8)) {
    DAT_10026bd0 = (uint *)0x0;
  }
  *piVar4 = local_8;
  return piVar10 + 1;
}



/* ===== FUN_100129fd @ 0x100129FD ===== */

undefined4 * FUN_100129fd(void)

{
  undefined4 *puVar1;
  LPVOID pvVar2;
  
  if (DAT_10026bd4 == DAT_10026bc4) {
    pvVar2 = HeapReAlloc(DAT_10026be0,0,DAT_10026bd8,(DAT_10026bc4 * 5 + 0x50) * 4);
    if (pvVar2 == (LPVOID)0x0) {
      return (undefined4 *)0x0;
    }
    DAT_10026bc4 = DAT_10026bc4 + 0x10;
    DAT_10026bd8 = pvVar2;
  }
  puVar1 = (undefined4 *)((int)DAT_10026bd8 + DAT_10026bd4 * 0x14);
  pvVar2 = HeapAlloc(DAT_10026be0,8,0x41c4);
  puVar1[4] = pvVar2;
  if (pvVar2 != (LPVOID)0x0) {
    pvVar2 = VirtualAlloc((LPVOID)0x0,0x100000,0x2000,4);
    puVar1[3] = pvVar2;
    if (pvVar2 != (LPVOID)0x0) {
      puVar1[2] = 0xffffffff;
      *puVar1 = 0;
      puVar1[1] = 0;
      DAT_10026bd4 = DAT_10026bd4 + 1;
      *(undefined4 *)puVar1[4] = 0xffffffff;
      return puVar1;
    }
    HeapFree(DAT_10026be0,0,(LPVOID)puVar1[4]);
  }
  return (undefined4 *)0x0;
}



/* ===== FUN_10012aae @ 0x10012AAE ===== */

int __cdecl FUN_10012aae(int param_1)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  LPVOID pvVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  int *lpAddress;
  
  iVar3 = *(int *)(param_1 + 0x10);
  iVar9 = 0;
  for (iVar4 = *(int *)(param_1 + 8); -1 < iVar4; iVar4 = iVar4 << 1) {
    iVar9 = iVar9 + 1;
  }
  iVar8 = 0x3f;
  iVar4 = iVar9 * 0x204 + 0x144 + iVar3;
  iVar5 = iVar4;
  do {
    *(int *)(iVar5 + 8) = iVar5;
    *(int *)(iVar5 + 4) = iVar5;
    iVar5 = iVar5 + 8;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  lpAddress = (int *)(iVar9 * 0x8000 + *(int *)(param_1 + 0xc));
  pvVar6 = VirtualAlloc(lpAddress,0x8000,0x1000,4);
  if (pvVar6 == (LPVOID)0x0) {
    iVar9 = -1;
  }
  else {
    if (lpAddress <= lpAddress + 0x1c00) {
      piVar7 = lpAddress + 4;
      do {
        piVar7[-2] = -1;
        piVar7[0x3fb] = -1;
        piVar7[-1] = 0xff0;
        *piVar7 = (int)(piVar7 + 0x3ff);
        piVar7[1] = (int)(piVar7 + -0x401);
        piVar7[0x3fa] = 0xff0;
        piVar1 = piVar7 + 0x3fc;
        piVar7 = piVar7 + 0x400;
      } while (piVar1 <= lpAddress + 0x1c00);
    }
    *(int **)(iVar4 + 0x1fc) = lpAddress + 3;
    lpAddress[5] = iVar4 + 0x1f8;
    *(int **)(iVar4 + 0x200) = lpAddress + 0x1c03;
    lpAddress[0x1c04] = iVar4 + 0x1f8;
    *(undefined4 *)(iVar3 + 0x44 + iVar9 * 4) = 0;
    *(undefined4 *)(iVar3 + 0xc4 + iVar9 * 4) = 1;
    cVar2 = *(char *)(iVar3 + 0x43);
    *(char *)(iVar3 + 0x43) = cVar2 + '\x01';
    if (cVar2 == '\0') {
      *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 1;
    }
    *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) & ~(0x80000000U >> ((byte)iVar9 & 0x1f));
  }
  return iVar9;
}



/* ===== FUN_10012ba9 @ 0x10012BA9 ===== */

undefined ** FUN_10012ba9(void)

{
  bool bVar1;
  int *lpAddress;
  LPVOID pvVar2;
  undefined **ppuVar3;
  int iVar4;
  undefined **lpMem;
  
  if (DAT_10021008 == -1) {
    lpMem = &PTR_LOOP_10020ff8;
  }
  else {
    lpMem = HeapAlloc(DAT_10026be0,0,0x2020);
    if (lpMem == (undefined **)0x0) {
      return (undefined **)0x0;
    }
  }
  lpAddress = VirtualAlloc((LPVOID)0x0,0x400000,0x2000,4);
  if (lpAddress != (int *)0x0) {
    pvVar2 = VirtualAlloc(lpAddress,0x10000,0x1000,4);
    if (pvVar2 != (LPVOID)0x0) {
      if (lpMem == &PTR_LOOP_10020ff8) {
        if (PTR_LOOP_10020ff8 == (undefined *)0x0) {
          PTR_LOOP_10020ff8 = (undefined *)&PTR_LOOP_10020ff8;
        }
        if (PTR_LOOP_10020ffc == (undefined *)0x0) {
          PTR_LOOP_10020ffc = (undefined *)&PTR_LOOP_10020ff8;
        }
      }
      else {
        *lpMem = (undefined *)&PTR_LOOP_10020ff8;
        lpMem[1] = PTR_LOOP_10020ffc;
        PTR_LOOP_10020ffc = (undefined *)lpMem;
        *(undefined ***)lpMem[1] = lpMem;
      }
      lpMem[5] = (undefined *)(lpAddress + 0x100000);
      ppuVar3 = lpMem + 6;
      lpMem[3] = (undefined *)(lpMem + 0x26);
      lpMem[4] = (undefined *)lpAddress;
      lpMem[2] = (undefined *)ppuVar3;
      iVar4 = 0;
      do {
        bVar1 = 0xf < iVar4;
        iVar4 = iVar4 + 1;
        *ppuVar3 = (undefined *)((bVar1 - 1 & 0xf1) - 1);
        ppuVar3[1] = (undefined *)0xf1;
        ppuVar3 = ppuVar3 + 2;
      } while (iVar4 < 0x400);
      _memset(lpAddress,0,0x10000);
      for (; lpAddress < lpMem[4] + 0x10000; lpAddress = lpAddress + 0x400) {
        *(undefined1 *)(lpAddress + 0x3e) = 0xff;
        *lpAddress = (int)(lpAddress + 2);
        lpAddress[1] = 0xf0;
      }
      return lpMem;
    }
    VirtualFree(lpAddress,0,0x8000);
  }
  if (lpMem != &PTR_LOOP_10020ff8) {
    HeapFree(DAT_10026be0,0,lpMem);
  }
  return (undefined **)0x0;
}



/* ===== FUN_10012ced @ 0x10012CED ===== */

void __cdecl FUN_10012ced(undefined **param_1)

{
  VirtualFree(param_1[4],0,0x8000);
  if ((undefined **)PTR_LOOP_10023018 == param_1) {
    PTR_LOOP_10023018 = param_1[1];
  }
  if (param_1 != &PTR_LOOP_10020ff8) {
    *(undefined **)param_1[1] = *param_1;
    *(undefined **)(*param_1 + 4) = param_1[1];
    HeapFree(DAT_10026be0,0,param_1);
    return;
  }
  DAT_10021008 = 0xffffffff;
  return;
}



/* ===== FUN_10012d43 @ 0x10012D43 ===== */

void __cdecl FUN_10012d43(int param_1)

{
  BOOL BVar1;
  undefined **ppuVar2;
  int iVar3;
  undefined **ppuVar4;
  undefined **ppuVar5;
  int local_8;
  
  ppuVar4 = (undefined **)PTR_LOOP_10020ffc;
  do {
    ppuVar5 = ppuVar4;
    if (ppuVar4[4] != (undefined *)0xffffffff) {
      local_8 = 0;
      ppuVar5 = ppuVar4 + 0x804;
      iVar3 = 0x3ff000;
      do {
        if (*ppuVar5 == (undefined *)0xf0) {
          BVar1 = VirtualFree(ppuVar4[4] + iVar3,0x1000,0x4000);
          if (BVar1 != 0) {
            *ppuVar5 = (undefined *)0xffffffff;
            DAT_10025540 = DAT_10025540 + -1;
            if (((undefined **)ppuVar4[3] == (undefined **)0x0) || (ppuVar5 < ppuVar4[3])) {
              ppuVar4[3] = (undefined *)ppuVar5;
            }
            local_8 = local_8 + 1;
            param_1 = param_1 + -1;
            if (param_1 == 0) break;
          }
        }
        iVar3 = iVar3 + -0x1000;
        ppuVar5 = ppuVar5 + -2;
      } while (-1 < iVar3);
      ppuVar5 = (undefined **)ppuVar4[1];
      if ((local_8 != 0) && (ppuVar4[6] == (undefined *)0xffffffff)) {
        ppuVar2 = ppuVar4 + 8;
        iVar3 = 1;
        do {
          if (*ppuVar2 != (undefined *)0xffffffff) break;
          iVar3 = iVar3 + 1;
          ppuVar2 = ppuVar2 + 2;
        } while (iVar3 < 0x400);
        if (iVar3 == 0x400) {
          FUN_10012ced(ppuVar4);
        }
      }
    }
    if ((ppuVar5 == (undefined **)PTR_LOOP_10020ffc) || (ppuVar4 = ppuVar5, param_1 < 1)) {
      return;
    }
  } while( true );
}



/* ===== FUN_10012e05 @ 0x10012E05 ===== */

int __cdecl FUN_10012e05(undefined *param_1,undefined4 *param_2,uint *param_3)

{
  undefined **ppuVar1;
  uint uVar2;
  
  ppuVar1 = &PTR_LOOP_10020ff8;
  while ((param_1 <= ppuVar1[4] || (ppuVar1[5] <= param_1))) {
    ppuVar1 = (undefined **)*ppuVar1;
    if (ppuVar1 == &PTR_LOOP_10020ff8) {
      return 0;
    }
  }
  if (((uint)param_1 & 0xf) != 0) {
    return 0;
  }
  if (((uint)param_1 & 0xfff) < 0x100) {
    return 0;
  }
  *param_2 = ppuVar1;
  uVar2 = (uint)param_1 & 0xfffff000;
  *param_3 = uVar2;
  return ((int)(param_1 + (-0x100 - uVar2)) >> 4) + 8 + uVar2;
}



/* ===== FUN_10012e5c @ 0x10012E5C ===== */

void __cdecl FUN_10012e5c(int param_1,int param_2,byte *param_3)

{
  int *piVar1;
  
  piVar1 = (int *)(param_1 + 0x18 + (param_2 - *(int *)(param_1 + 0x10) >> 0xc) * 8);
  *piVar1 = *piVar1 + (uint)*param_3;
  *param_3 = 0;
  piVar1[1] = 0xf1;
  if ((*piVar1 == 0xf0) && (DAT_10025540 = DAT_10025540 + 1, DAT_10025540 == 0x20)) {
    FUN_10012d43(0x10);
  }
  return;
}



/* ===== FUN_10012ea1 @ 0x10012EA1 ===== */

/* WARNING: Type propagation algorithm not settling */

int * __cdecl FUN_10012ea1(uint param_1)

{
  uint *puVar1;
  undefined **ppuVar2;
  undefined *puVar3;
  int *piVar4;
  int *piVar5;
  undefined **ppuVar6;
  int *piVar7;
  uint *puVar8;
  undefined **ppuVar9;
  int local_8;
  
  piVar7 = (int *)PTR_LOOP_10023018;
  do {
    if (piVar7[4] != -1) {
      puVar8 = (uint *)piVar7[2];
      piVar4 = (int *)(((int)puVar8 + (-0x18 - (int)piVar7) >> 3) * 0x1000 + piVar7[4]);
      if (puVar8 < piVar7 + 0x806) {
        do {
          if (((int)param_1 <= (int)*puVar8) && (param_1 < puVar8[1])) {
            piVar5 = (int *)FUN_100130a9(piVar4,*puVar8,param_1);
            if (piVar5 != (int *)0x0) goto LAB_10012f6c;
            puVar8[1] = param_1;
          }
          puVar8 = puVar8 + 2;
          piVar4 = piVar4 + 0x400;
        } while (puVar8 < piVar7 + 0x806);
      }
      puVar1 = (uint *)piVar7[2];
      piVar4 = (int *)piVar7[4];
      for (puVar8 = (uint *)(piVar7 + 6); puVar8 < puVar1; puVar8 = puVar8 + 2) {
        if (((int)param_1 <= (int)*puVar8) && (param_1 < puVar8[1])) {
          piVar5 = (int *)FUN_100130a9(piVar4,*puVar8,param_1);
          if (piVar5 != (int *)0x0) {
LAB_10012f6c:
            PTR_LOOP_10023018 = (undefined *)piVar7;
            *puVar8 = *puVar8 - param_1;
            piVar7[2] = (int)puVar8;
            return piVar5;
          }
          puVar8[1] = param_1;
        }
        piVar4 = piVar4 + 0x400;
      }
    }
    piVar7 = (int *)*piVar7;
    if (piVar7 == (int *)PTR_LOOP_10023018) {
      ppuVar9 = &PTR_LOOP_10020ff8;
      while ((ppuVar9[4] == (undefined *)0xffffffff || (ppuVar9[3] == (undefined *)0x0))) {
        ppuVar9 = (undefined **)*ppuVar9;
        if (ppuVar9 == &PTR_LOOP_10020ff8) {
          ppuVar9 = FUN_10012ba9();
          if (ppuVar9 == (undefined **)0x0) {
            return (int *)0x0;
          }
          piVar7 = (int *)ppuVar9[4];
          *(char *)(piVar7 + 2) = (char)param_1;
          PTR_LOOP_10023018 = (undefined *)ppuVar9;
          *piVar7 = (int)piVar7 + param_1 + 8;
          piVar7[1] = 0xf0 - param_1;
          ppuVar9[6] = ppuVar9[6] + -(param_1 & 0xff);
          return piVar7 + 0x40;
        }
      }
      ppuVar2 = (undefined **)ppuVar9[3];
      local_8 = 0;
      piVar7 = (int *)(ppuVar9[4] + ((int)ppuVar2 + (-0x18 - (int)ppuVar9) >> 3) * 0x1000);
      puVar3 = *ppuVar2;
      ppuVar6 = ppuVar2;
      for (; (puVar3 == (undefined *)0xffffffff && (local_8 < 0x10)); local_8 = local_8 + 1) {
        ppuVar6 = ppuVar6 + 2;
        puVar3 = *ppuVar6;
      }
      piVar4 = VirtualAlloc(piVar7,local_8 << 0xc,0x1000,4);
      if (piVar4 != piVar7) {
        return (int *)0x0;
      }
      _memset(piVar7,local_8 << 0xc,0);
      ppuVar6 = ppuVar2;
      if (0 < local_8) {
        piVar4 = piVar7 + 1;
        do {
          *(undefined1 *)(piVar4 + 0x3d) = 0xff;
          piVar4[-1] = (int)(piVar4 + 1);
          *piVar4 = 0xf0;
          *ppuVar6 = (undefined *)0xf0;
          ppuVar6[1] = (undefined *)0xf1;
          piVar4 = piVar4 + 0x400;
          ppuVar6 = ppuVar6 + 2;
          local_8 = local_8 + -1;
        } while (local_8 != 0);
      }
      for (; (ppuVar6 < ppuVar9 + 0x806 && (*ppuVar6 != (undefined *)0xffffffff));
          ppuVar6 = ppuVar6 + 2) {
      }
      PTR_LOOP_10023018 = (undefined *)ppuVar9;
      ppuVar9[3] = (undefined *)(-(uint)(ppuVar6 < ppuVar9 + 0x806) & (uint)ppuVar6);
      *(char *)(piVar7 + 2) = (char)param_1;
      ppuVar9[2] = (undefined *)ppuVar2;
      *ppuVar2 = *ppuVar2 + -param_1;
      piVar7[1] = piVar7[1] - param_1;
      *piVar7 = (int)piVar7 + param_1 + 8;
      return piVar7 + 0x40;
    }
  } while( true );
}



/* ===== FUN_100130a9 @ 0x100130A9 ===== */

int __cdecl FUN_100130a9(int *param_1,uint param_2,uint param_3)

{
  byte *pbVar1;
  byte *pbVar2;
  byte bVar3;
  byte *pbVar4;
  uint uVar5;
  byte *pbVar6;
  
  pbVar2 = (byte *)*param_1;
  pbVar1 = (byte *)(param_1 + 0x3e);
  bVar3 = (byte)param_3;
  if ((uint)param_1[1] < param_3) {
    pbVar6 = pbVar2;
    if (pbVar2[param_1[1]] != 0) {
      pbVar6 = pbVar2 + param_1[1];
    }
    while( true ) {
      while( true ) {
        if (pbVar1 <= pbVar6 + param_3) {
          pbVar6 = (byte *)(param_1 + 2);
          while( true ) {
            while( true ) {
              if (pbVar2 <= pbVar6) {
                return 0;
              }
              if (pbVar1 <= pbVar6 + param_3) {
                return 0;
              }
              if (*pbVar6 == 0) break;
              pbVar6 = pbVar6 + *pbVar6;
            }
            uVar5 = 1;
            pbVar4 = pbVar6;
            while (pbVar4 = pbVar4 + 1, *pbVar4 == 0) {
              uVar5 = uVar5 + 1;
            }
            if (param_3 <= uVar5) break;
            param_2 = param_2 - uVar5;
            pbVar6 = pbVar4;
            if (param_2 < param_3) {
              return 0;
            }
          }
          if (pbVar6 + param_3 < pbVar1) {
            *param_1 = (int)(pbVar6 + param_3);
            param_1[1] = uVar5 - param_3;
          }
          else {
            param_1[1] = 0;
            *param_1 = (int)(param_1 + 2);
          }
          *pbVar6 = bVar3;
          pbVar2 = pbVar6 + 8;
          goto LAB_100131bc;
        }
        if (*pbVar6 == 0) break;
        pbVar6 = pbVar6 + *pbVar6;
      }
      uVar5 = 1;
      pbVar4 = pbVar6;
      while (pbVar4 = pbVar4 + 1, *pbVar4 == 0) {
        uVar5 = uVar5 + 1;
      }
      if (param_3 <= uVar5) break;
      if (pbVar6 == pbVar2) {
        param_1[1] = uVar5;
        pbVar6 = pbVar4;
      }
      else {
        param_2 = param_2 - uVar5;
        pbVar6 = pbVar4;
        if (param_2 < param_3) {
          return 0;
        }
      }
    }
    if (pbVar6 + param_3 < pbVar1) {
      *param_1 = (int)(pbVar6 + param_3);
      param_1[1] = uVar5 - param_3;
    }
    else {
      param_1[1] = 0;
      *param_1 = (int)(param_1 + 2);
    }
    *pbVar6 = bVar3;
    pbVar2 = pbVar6 + 8;
  }
  else {
    *pbVar2 = bVar3;
    if (pbVar2 + param_3 < pbVar1) {
      *param_1 = *param_1 + param_3;
      param_1[1] = param_1[1] - param_3;
    }
    else {
      param_1[1] = 0;
      *param_1 = (int)(param_1 + 2);
    }
    pbVar2 = pbVar2 + 8;
  }
LAB_100131bc:
  return (int)pbVar2 * 0x10 + (int)param_1 * -0xf;
}



/* ===== FUN_100131cd @ 0x100131CD ===== */

void FUN_100131cd(void)

{
  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_10023064);
  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_10023054);
  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_10023044);
  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_10023024);
  return;
}



/* ===== FUN_100131f6 @ 0x100131F6 ===== */

void FUN_100131f6(void)

{
  undefined **ppuVar1;
  
  ppuVar1 = (undefined **)&DAT_10023020;
  do {
    if (((((LPCRITICAL_SECTION)*ppuVar1 != (LPCRITICAL_SECTION)0x0) &&
         (ppuVar1 != &PTR_DAT_10023064)) && (ppuVar1 != &PTR_DAT_10023054)) &&
       ((ppuVar1 != &PTR_DAT_10023044 && (ppuVar1 != &PTR_DAT_10023024)))) {
      DeleteCriticalSection((LPCRITICAL_SECTION)*ppuVar1);
      FUN_100101ee(*ppuVar1);
    }
    ppuVar1 = ppuVar1 + 1;
  } while ((int)ppuVar1 < 0x100230e0);
  DeleteCriticalSection((LPCRITICAL_SECTION)PTR_DAT_10023044);
  DeleteCriticalSection((LPCRITICAL_SECTION)PTR_DAT_10023054);
  DeleteCriticalSection((LPCRITICAL_SECTION)PTR_DAT_10023064);
  DeleteCriticalSection((LPCRITICAL_SECTION)PTR_DAT_10023024);
  return;
}



/* ===== FUN_10013262 @ 0x10013262 ===== */

void __cdecl FUN_10013262(int param_1)

{
  int *piVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  
  piVar1 = &DAT_10023020 + param_1;
  if ((&DAT_10023020)[param_1] == 0) {
    lpCriticalSection = _malloc(0x18);
    if (lpCriticalSection == (LPCRITICAL_SECTION)0x0) {
      __amsg_exit(0x11);
    }
    FUN_10013262(0x11);
    if (*piVar1 == 0) {
      InitializeCriticalSection(lpCriticalSection);
      *piVar1 = (int)lpCriticalSection;
    }
    else {
      FUN_100101ee((undefined *)lpCriticalSection);
    }
    FUN_100132c3(0x11);
  }
  EnterCriticalSection((LPCRITICAL_SECTION)*piVar1);
  return;
}



/* ===== FUN_100132c3 @ 0x100132C3 ===== */

void __cdecl FUN_100132c3(int param_1)

{
  LeaveCriticalSection((LPCRITICAL_SECTION)(&DAT_10023020)[param_1]);
  return;
}



/* ===== FUN_1001339d @ 0x1001339D ===== */

void FUN_1001339d(int param_1)

{
  __local_unwind2(*(int *)(param_1 + 0x18),*(int *)(param_1 + 0x1c));
  return;
}



/* ===== FUN_100133b8 @ 0x100133B8 ===== */

undefined4 FUN_100133b8(void)

{
  DWORD *lpTlsValue;
  BOOL BVar1;
  DWORD DVar2;
  
  FUN_100131cd();
  DAT_100230e0 = TlsAlloc();
  if (DAT_100230e0 != 0xffffffff) {
    lpTlsValue = (DWORD *)FUN_100111c5(1,0x74);
    if (lpTlsValue != (DWORD *)0x0) {
      BVar1 = TlsSetValue(DAT_100230e0,lpTlsValue);
      if (BVar1 != 0) {
        FUN_1001342a((int)lpTlsValue);
        DVar2 = GetCurrentThreadId();
        lpTlsValue[1] = 0xffffffff;
        *lpTlsValue = DVar2;
        return 1;
      }
    }
  }
  return 0;
}



/* ===== FUN_1001340c @ 0x1001340C ===== */

void FUN_1001340c(void)

{
  FUN_100131f6();
  if (DAT_100230e0 != 0xffffffff) {
    TlsFree(DAT_100230e0);
    DAT_100230e0 = 0xffffffff;
  }
  return;
}



/* ===== FUN_1001342a @ 0x1001342A ===== */

void __cdecl FUN_1001342a(int param_1)

{
  *(undefined **)(param_1 + 0x50) = &DAT_10023840;
  *(undefined4 *)(param_1 + 0x14) = 1;
  return;
}



/* ===== FUN_1001343d @ 0x1001343D ===== */

DWORD * FUN_1001343d(void)

{
  DWORD dwErrCode;
  DWORD *lpTlsValue;
  BOOL BVar1;
  DWORD DVar2;
  
  dwErrCode = GetLastError();
  lpTlsValue = TlsGetValue(DAT_100230e0);
  if (lpTlsValue == (DWORD *)0x0) {
    lpTlsValue = (DWORD *)FUN_100111c5(1,0x74);
    if (lpTlsValue != (DWORD *)0x0) {
      BVar1 = TlsSetValue(DAT_100230e0,lpTlsValue);
      if (BVar1 != 0) {
        FUN_1001342a((int)lpTlsValue);
        DVar2 = GetCurrentThreadId();
        lpTlsValue[1] = 0xffffffff;
        *lpTlsValue = DVar2;
        goto LAB_10013498;
      }
    }
    __amsg_exit(0x10);
  }
LAB_10013498:
  SetLastError(dwErrCode);
  return lpTlsValue;
}



/* ===== FUN_100134a4 @ 0x100134A4 ===== */

void __cdecl FUN_100134a4(undefined *param_1)

{
  if (DAT_100230e0 != 0xffffffff) {
    if ((param_1 != (undefined *)0x0) ||
       (param_1 = TlsGetValue(DAT_100230e0), param_1 != (undefined *)0x0)) {
      if (*(undefined **)(param_1 + 0x24) != (undefined *)0x0) {
        FUN_100101ee(*(undefined **)(param_1 + 0x24));
      }
      if (*(undefined **)(param_1 + 0x28) != (undefined *)0x0) {
        FUN_100101ee(*(undefined **)(param_1 + 0x28));
      }
      if (*(undefined **)(param_1 + 0x30) != (undefined *)0x0) {
        FUN_100101ee(*(undefined **)(param_1 + 0x30));
      }
      if (*(undefined **)(param_1 + 0x38) != (undefined *)0x0) {
        FUN_100101ee(*(undefined **)(param_1 + 0x38));
      }
      if (*(undefined **)(param_1 + 0x40) != (undefined *)0x0) {
        FUN_100101ee(*(undefined **)(param_1 + 0x40));
      }
      if (*(undefined **)(param_1 + 0x44) != (undefined *)0x0) {
        FUN_100101ee(*(undefined **)(param_1 + 0x44));
      }
      if (*(undefined **)(param_1 + 0x50) != &DAT_10023840) {
        FUN_100101ee(*(undefined **)(param_1 + 0x50));
      }
      FUN_100101ee(param_1);
    }
    TlsSetValue(DAT_100230e0,(LPVOID)0x0);
    return;
  }
  return;
}



/* ===== FUN_10013930 @ 0x10013930 ===== */

float10 __fastcall
FUN_10013930(undefined4 param_1,uint param_2,undefined2 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  float10 in_ST0;
  int local_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 local_14;
  undefined4 local_10;
  double dStack_c;
  
  local_14 = param_7;
  local_10 = param_8;
  dStack_c = (double)in_ST0;
  uStack_1c = param_5;
  uStack_18 = param_6;
  uStack_20 = param_1;
  FUN_10017a5b(param_2,&local_24,&param_3);
  return (float10)dStack_c;
}



/* ===== __startOneArgErrorHandling @ 0x10013947 ===== */

/* Library Function - Single Match
    __startOneArgErrorHandling
   
   Library: Visual Studio */

float10 __fastcall
__startOneArgErrorHandling
          (undefined4 param_1,uint param_2,ushort param_3,undefined4 param_4,undefined4 param_5,
          undefined4 param_6)

{
  float10 in_ST0;
  int local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  double local_c;
  
  local_c = (double)in_ST0;
  local_1c = param_5;
  local_18 = param_6;
  local_20 = param_1;
  FUN_10017a5b(param_2,&local_24,&param_3);
  return (float10)local_c;
}



/* ===== FUN_10013990 @ 0x10013990 ===== */

undefined1  [10] FUN_10013990(void)

{
  float10 in_ST0;
  float10 fVar1;
  undefined1 auVar2 [10];
  
  fVar1 = (float10)f2xm1(-(ROUND(in_ST0) - in_ST0));
  auVar2 = (undefined1  [10])fscale((float10)1 + fVar1,ROUND(in_ST0));
  return auVar2;
}



/* ===== FUN_100139a5 @ 0x100139A5 ===== */

void FUN_100139a5(void)

{
  return;
}



/* ===== FUN_100139bc @ 0x100139BC ===== */

undefined4 FUN_100139bc(void)

{
  uint in_EAX;
  
  if ((in_EAX & 0x80000) != 0) {
    return 7;
  }
  return 1;
}



/* ===== __fload_withFB @ 0x100139D5 ===== */

/* Library Function - Single Match
    __fload_withFB
   
   Library: Visual Studio */

uint __fastcall __fload_withFB(undefined4 param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_2 + 4) & 0x7ff00000;
  if (uVar1 != 0x7ff00000) {
    return uVar1;
  }
  return *(uint *)(param_2 + 4);
}



/* ===== FUN_10013a18 @ 0x10013A18 ===== */

uint __cdecl FUN_10013a18(undefined4 param_1,uint param_2)

{
  if ((param_2 & 0x7ff00000) != 0x7ff00000) {
    return param_2 & 0x7ff00000;
  }
  return param_2;
}



/* ===== FUN_10013a2e @ 0x10013A2E ===== */

void FUN_10013a2e(void)

{
  return;
}



/* ===== __math_exit @ 0x10013A3B ===== */

/* Library Function - Single Match
    __math_exit
   
   Library: Visual Studio */

void __fastcall
__math_exit(undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
           )

{
  ushort in_FPUStatusWord;
  ushort unaff_retaddr;
  
  if (((unaff_retaddr != 0x27f) && ((unaff_retaddr & 0x20) != 0)) &&
     ((in_FPUStatusWord & 0x20) != 0)) {
    __startOneArgErrorHandling(param_1,param_2,unaff_retaddr,param_3,param_4,param_5);
    return;
  }
  return;
}



/* ===== FUN_10013a79 @ 0x10013A79 ===== */

void __fastcall
FUN_10013a79(undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  ushort in_FPUStatusWord;
  float10 in_ST0;
  ushort unaff_retaddr;
  uint uStack_4;
  
  uStack_4 = (uint)((ulonglong)(double)in_ST0 >> 0x20);
  if (((ulonglong)(double)in_ST0 & 0x7ff0000000000000) == 0) {
    fscale(in_ST0,(float10)1536.0);
  }
  else if ((uStack_4 & 0x7ff00000) == 0x7ff00000) {
    fscale(in_ST0,(float10)-1536.0);
  }
  else if (((unaff_retaddr == 0x27f) || ((unaff_retaddr & 0x20) != 0)) ||
          ((in_FPUStatusWord & 0x20) == 0)) {
    return;
  }
  if (param_2 == 0x1d) {
    FUN_10013930(param_1,0x1d,unaff_retaddr,param_3,param_4,param_5,param_6,param_7);
    return;
  }
  __startOneArgErrorHandling(param_1,param_2,unaff_retaddr,param_3,param_4,param_5);
  return;
}



/* ===== FUN_10013b1c @ 0x10013B1C ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_10013b1c(int param_1,int param_2,double param_3,double *param_4)

{
  double dVar1;
  double dVar2;
  int iVar3;
  
  dVar1 = (double)CONCAT44(param_2,param_1);
  if ((double)CONCAT44(param_2,param_1) < 0.0) {
    dVar1 = -dVar1;
  }
  dVar2 = _DAT_10023250;
  if (param_3._4_4_ == 0x7ff00000) {
    if (param_3._0_4_ != 0) {
LAB_10013ba7:
      if (param_2 == 0x7ff00000) {
        if (param_1 != 0) {
          return 0;
        }
        if (0.0 < param_3) goto LAB_10013c42;
        if (param_3 < 0.0) goto LAB_10013bd9;
      }
      else {
        if (param_2 != -0x100000) {
          return 0;
        }
        if (param_1 != 0) {
          return 0;
        }
        iVar3 = FUN_10013c4c(param_3);
        if (0.0 < param_3) {
          dVar2 = _DAT_10023250;
          if (iVar3 == 1) {
            dVar2 = -_DAT_10023250;
          }
          goto LAB_10013c42;
        }
        if (param_3 < 0.0) {
          dVar2 = _DAT_10023270;
          if (iVar3 != 1) {
            dVar2 = 0.0;
          }
          goto LAB_10013c42;
        }
      }
      dVar2 = 1.0;
      goto LAB_10013c42;
    }
    if (1.0 < dVar1) goto LAB_10013c42;
    if (1.0 <= dVar1) {
LAB_10013b6c:
      *param_4 = _DAT_10023258;
      return 1;
    }
  }
  else {
    if (param_3 != -INFINITY) goto LAB_10013ba7;
    if (dVar1 <= 1.0) {
      if (1.0 <= dVar1) goto LAB_10013b6c;
      goto LAB_10013c42;
    }
  }
LAB_10013bd9:
  dVar2 = 0.0;
LAB_10013c42:
  *param_4 = dVar2;
  return 0;
}



/* ===== FUN_10013c4c @ 0x10013C4C ===== */

undefined4 __cdecl FUN_10013c4c(double param_1)

{
  uint uVar1;
  float10 fVar2;
  undefined4 uVar3;
  
  uVar1 = FUN_10010ecb(SUB84(param_1,0),(uint)((ulonglong)param_1 >> 0x20));
  if ((uVar1 & 0x90) == 0) {
    fVar2 = __frnd(param_1);
    if ((double)fVar2 == param_1) {
      fVar2 = __frnd(param_1 / 2.0);
      if (fVar2 == (float10)(param_1 / 2.0)) {
        uVar3 = 2;
      }
      else {
        uVar3 = 1;
      }
      return uVar3;
    }
  }
  return 0;
}



/* ===== FUN_10013cb1 @ 0x10013CB1 ===== */

undefined4 __cdecl
FUN_10013cb1(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4,int *param_5,
            int param_6,PVOID param_7,char param_8)

{
  code *pcVar1;
  undefined4 uVar2;
  
  if (*param_5 != 0x19930520) {
    FUN_1001457d();
  }
  if ((param_1->ExceptionFlags & 0x66) == 0) {
    if (param_5[3] != 0) {
      if (((param_1->ExceptionCode == 0xe06d7363) && (0x19930520 < param_1->ExceptionInformation[0])
          ) && (pcVar1 = *(code **)(param_1->ExceptionInformation[2] + 8), pcVar1 != (code *)0x0)) {
        uVar2 = (*pcVar1)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
        return uVar2;
      }
      FUN_10013d4c(param_1,param_2,param_3,param_4,(int)param_5,param_8,param_6,param_7);
    }
  }
  else if ((param_5[1] != 0) && (param_6 == 0)) {
    FUN_10014006((int)param_2,param_4,(int)param_5,-1);
  }
  return 1;
}



/* ===== FUN_10013d4c @ 0x10013D4C ===== */

void __cdecl
FUN_10013d4c(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4,int param_5,
            char param_6,int param_7,PVOID param_8)

{
  byte *pbVar1;
  bool bVar2;
  DWORD *pDVar3;
  undefined3 extraout_var;
  int *piVar4;
  int iVar5;
  int *piVar6;
  uint local_1c;
  uint local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  local_18 = local_18 & 0xffffff00;
  local_14 = *(int *)((int)param_2 + 8);
  if ((local_14 < -1) || (*(int *)(param_5 + 4) <= local_14)) {
    FUN_1001457d();
  }
  if (param_1->ExceptionCode == 0xe06d7363) {
    if (((param_1->NumberParameters == 3) && (param_1->ExceptionInformation[0] == 0x19930520)) &&
       (param_1->ExceptionInformation[2] == 0)) {
      pDVar3 = FUN_1001343d();
      if (pDVar3[0x1b] == 0) {
        return;
      }
      pDVar3 = FUN_1001343d();
      param_1 = (PEXCEPTION_RECORD)pDVar3[0x1b];
      pDVar3 = FUN_1001343d();
      param_3 = pDVar3[0x1c];
      local_18 = CONCAT31(local_18._1_3_,1);
      bVar2 = FUN_10017b8f(param_1,1);
      if (CONCAT31(extraout_var,bVar2) == 0) {
        FUN_1001457d();
      }
      if (param_1->ExceptionCode != 0xe06d7363) goto LAB_10013ed4;
      if (((param_1->NumberParameters == 3) && (param_1->ExceptionInformation[0] == 0x19930520)) &&
         (param_1->ExceptionInformation[2] == 0)) {
        FUN_1001457d();
      }
    }
    iVar5 = local_14;
    if (((param_1->ExceptionCode == 0xe06d7363) && (param_1->NumberParameters == 3)) &&
       (param_1->ExceptionInformation[0] == 0x19930520)) {
      piVar4 = (int *)FUN_10010768(param_5,param_7,local_14,&local_8,&local_1c);
      do {
        if (local_1c <= local_8) {
          if (param_6 == '\0') {
            return;
          }
          FUN_1001443e((int)param_1);
          return;
        }
        if ((*piVar4 <= iVar5) && (iVar5 <= piVar4[1])) {
          pbVar1 = (byte *)piVar4[4];
          for (local_10 = piVar4[3]; iVar5 = local_14, 0 < local_10; local_10 = local_10 + -1) {
            piVar6 = *(int **)(param_1->ExceptionInformation[2] + 0xc);
            for (local_c = *piVar6; 0 < local_c; local_c = local_c + -1) {
              piVar6 = piVar6 + 1;
              iVar5 = FUN_10013fa9(pbVar1,(byte *)*piVar6,(uint *)param_1->ExceptionInformation[2]);
              if (iVar5 != 0) {
                FUN_100140ba(param_1,param_2,param_3,param_4,param_5,pbVar1,(byte *)*piVar6,piVar4,
                             param_7,param_8);
                iVar5 = local_14;
                goto LAB_10013eb4;
              }
            }
            pbVar1 = pbVar1 + 0x10;
          }
        }
LAB_10013eb4:
        local_8 = local_8 + 1;
        piVar4 = piVar4 + 5;
      } while( true );
    }
  }
LAB_10013ed4:
  if (param_6 == '\0') {
    FUN_10013eff(param_1,param_2,param_3,param_4,param_5,local_14,param_7,param_8);
    return;
  }
  FUN_1001451c();
  return;
}



/* ===== FUN_10013eff @ 0x10013EFF ===== */

void __cdecl
FUN_10013eff(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4,int param_5,
            int param_6,int param_7,PVOID param_8)

{
  DWORD *pDVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  uint local_c;
  uint local_8;
  
  pDVar1 = FUN_1001343d();
  if ((pDVar1[0x1a] != 0) &&
     (iVar2 = FUN_1001063d(&param_1->ExceptionCode,param_2,param_3,param_4,param_5,param_7,param_8),
     iVar2 != 0)) {
    return;
  }
  piVar3 = (int *)FUN_10010768(param_5,param_7,param_6,&local_8,&local_c);
  for (; local_8 < local_c; local_8 = local_8 + 1) {
    if ((*piVar3 <= param_6) && (param_6 <= piVar3[1])) {
      iVar4 = piVar3[3] * 0x10 + piVar3[4];
      iVar2 = *(int *)(iVar4 + -0xc);
      if ((iVar2 == 0) || (*(char *)(iVar2 + 8) == '\0')) {
        FUN_100140ba(param_1,param_2,param_3,param_4,param_5,(byte *)(iVar4 + -0x10),(byte *)0x0,
                     piVar3,param_7,param_8);
      }
    }
    piVar3 = piVar3 + 5;
  }
  return;
}



/* ===== FUN_10013fa9 @ 0x10013FA9 ===== */

undefined4 __cdecl FUN_10013fa9(byte *param_1,byte *param_2,uint *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(param_1 + 4);
  if ((iVar1 == 0) || (*(char *)(iVar1 + 8) == '\0')) {
LAB_10014000:
    uVar2 = 1;
  }
  else {
    if (iVar1 == *(int *)(param_2 + 4)) {
LAB_10013fda:
      if (((((*param_2 & 2) == 0) || ((*param_1 & 8) != 0)) &&
          (((*param_3 & 1) == 0 || ((*param_1 & 1) != 0)))) &&
         (((*param_3 & 2) == 0 || ((*param_1 & 2) != 0)))) goto LAB_10014000;
    }
    else {
      iVar1 = _strcmp((char *)(iVar1 + 8),(char *)(*(int *)(param_2 + 4) + 8));
      if (iVar1 == 0) goto LAB_10013fda;
    }
    uVar2 = 0;
  }
  return uVar2;
}



/* ===== FUN_10014006 @ 0x10014006 ===== */

void __cdecl FUN_10014006(int param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  void *local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_1001c550;
  puStack_10 = &LAB_100132e0;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  for (iVar2 = *(int *)(param_1 + 8); local_8 = 0xffffffff, iVar2 != param_4;
      iVar2 = *(int *)(*(int *)(param_3 + 8) + iVar2 * 8)) {
    if ((iVar2 < 0) || (*(int *)(param_3 + 4) <= iVar2)) {
      FUN_1001457d();
    }
    local_8 = 0;
    iVar1 = *(int *)(*(int *)(param_3 + 8) + 4 + iVar2 * 8);
    if (iVar1 != 0) {
      __CallSettingFrame_12(iVar1,param_1,0x103);
    }
  }
  *(int *)(param_1 + 8) = iVar2;
  ExceptionList = local_14;
  return;
}



/* ===== FUN_100140ba @ 0x100140BA ===== */

void __cdecl
FUN_100140ba(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4,int param_5,
            byte *param_6,byte *param_7,int *param_8,int param_9,PVOID param_10)

{
  undefined *UNRECOVERED_JUMPTABLE;
  
  if (param_7 != (byte *)0x0) {
    FUN_1001427a((int)param_1,(int)param_2,param_6,param_7);
  }
  if (param_10 == (PVOID)0x0) {
    param_10 = param_2;
  }
  FUN_1001053f(param_10,param_1);
  FUN_10014006((int)param_2,param_4,param_5,*param_8);
  *(int *)((int)param_2 + 8) = param_8[1] + 1;
  UNRECOVERED_JUMPTABLE =
       (undefined *)
       FUN_10014135((DWORD)param_1,param_2,param_3,param_5,*(undefined4 *)(param_6 + 0xc),param_9,
                    0x100);
  if (UNRECOVERED_JUMPTABLE != (undefined *)0x0) {
    FUN_100104fd(UNRECOVERED_JUMPTABLE);
  }
  return;
}



/* ===== FUN_10014135 @ 0x10014135 ===== */

undefined4 __cdecl
FUN_10014135(DWORD param_1,undefined4 param_2,DWORD param_3,undefined4 param_4,undefined4 param_5,
            int param_6,int param_7)

{
  DWORD *pDVar1;
  undefined4 uVar2;
  void *local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &DAT_1001c560;
  puStack_10 = &LAB_100132e0;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  FUN_1001343d();
  FUN_1001343d();
  pDVar1 = FUN_1001343d();
  pDVar1[0x1b] = param_1;
  pDVar1 = FUN_1001343d();
  pDVar1[0x1c] = param_3;
  local_8 = 1;
  uVar2 = FUN_100105c4(param_2,param_4,param_5,param_6,param_7);
  local_8 = 0xffffffff;
  FUN_10014202();
  ExceptionList = local_14;
  return uVar2;
}



/* ===== FUN_10014202 @ 0x10014202 ===== */

void FUN_10014202(void)

{
  DWORD *pDVar1;
  int unaff_EBP;
  int unaff_ESI;
  int *unaff_EDI;
  
  *(undefined4 *)(unaff_ESI + -4) = *(undefined4 *)(unaff_EBP + -0x28);
  pDVar1 = FUN_1001343d();
  pDVar1[0x1b] = *(DWORD *)(unaff_EBP + -0x1c);
  pDVar1 = FUN_1001343d();
  pDVar1[0x1c] = *(DWORD *)(unaff_EBP + -0x20);
  if ((((*unaff_EDI == -0x1f928c9d) && (unaff_EDI[4] == 3)) && (unaff_EDI[5] == 0x19930520)) &&
     ((*(int *)(unaff_EBP + -0x24) == 0 && (*(int *)(unaff_EBP + -0x2c) != 0)))) {
    __abnormal_termination();
    FUN_1001443e((int)unaff_EDI);
  }
  return;
}



/* ===== FUN_1001427a @ 0x1001427A ===== */

void __cdecl FUN_1001427a(int param_1,int param_2,byte *param_3,byte *param_4)

{
  int *piVar1;
  bool bVar2;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int iVar3;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  undefined3 extraout_var_03;
  undefined3 extraout_var_04;
  undefined4 *puVar4;
  undefined3 extraout_var_05;
  undefined3 extraout_var_06;
  undefined3 extraout_var_07;
  uint uVar5;
  void *local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_1001c578;
  puStack_10 = &LAB_100132e0;
  local_14 = ExceptionList;
  if (*(int *)(param_3 + 4) == 0) {
    return;
  }
  if (*(char *)(*(int *)(param_3 + 4) + 8) == '\0') {
    return;
  }
  if (*(int *)(param_3 + 8) == 0) {
    return;
  }
  piVar1 = (int *)(*(int *)(param_3 + 8) + 0xc + param_2);
  local_8 = 0;
  if ((*param_3 & 8) == 0) {
    if ((*param_4 & 1) == 0) {
      if (*(int *)(param_4 + 0x18) == 0) {
        ExceptionList = &local_14;
        bVar2 = FUN_10017b8f(*(void **)(param_1 + 0x18),1);
        if ((CONCAT31(extraout_var_03,bVar2) != 0) &&
           (bVar2 = FUN_10017bab(piVar1,1), CONCAT31(extraout_var_04,bVar2) != 0)) {
          uVar5 = *(uint *)(param_4 + 0x14);
          puVar4 = (undefined4 *)FUN_100144a5(*(int *)(param_1 + 0x18),(int *)(param_4 + 8));
          FUN_10015f90(piVar1,puVar4,uVar5);
          ExceptionList = local_14;
          return;
        }
      }
      else {
        ExceptionList = &local_14;
        bVar2 = FUN_10017b8f(*(void **)(param_1 + 0x18),1);
        if (((CONCAT31(extraout_var_05,bVar2) != 0) &&
            (bVar2 = FUN_10017bab(piVar1,1), CONCAT31(extraout_var_06,bVar2) != 0)) &&
           (bVar2 = FUN_10017bc7(*(FARPROC *)(param_4 + 0x18)), CONCAT31(extraout_var_07,bVar2) != 0
           )) {
          if ((*param_4 & 4) != 0) {
            FUN_100144a5(*(int *)(param_1 + 0x18),(int *)(param_4 + 8));
            FUN_10010538(piVar1,*(undefined **)(param_4 + 0x18));
            ExceptionList = local_14;
            return;
          }
          FUN_100144a5(*(int *)(param_1 + 0x18),(int *)(param_4 + 8));
          FUN_10010531(piVar1,*(undefined **)(param_4 + 0x18));
          ExceptionList = local_14;
          return;
        }
      }
    }
    else {
      ExceptionList = &local_14;
      bVar2 = FUN_10017b8f(*(void **)(param_1 + 0x18),1);
      if ((CONCAT31(extraout_var_01,bVar2) != 0) &&
         (bVar2 = FUN_10017bab(piVar1,1), CONCAT31(extraout_var_02,bVar2) != 0)) {
        FUN_10015f90(piVar1,*(undefined4 **)(param_1 + 0x18),*(uint *)(param_4 + 0x14));
        if (*(int *)(param_4 + 0x14) != 4) {
          ExceptionList = local_14;
          return;
        }
        iVar3 = *piVar1;
        if (iVar3 == 0) {
          ExceptionList = local_14;
          return;
        }
        goto LAB_10014308;
      }
    }
  }
  else {
    ExceptionList = &local_14;
    bVar2 = FUN_10017b8f(*(void **)(param_1 + 0x18),1);
    if ((CONCAT31(extraout_var,bVar2) != 0) &&
       (bVar2 = FUN_10017bab(piVar1,1), CONCAT31(extraout_var_00,bVar2) != 0)) {
      iVar3 = *(int *)(param_1 + 0x18);
      *piVar1 = iVar3;
LAB_10014308:
      iVar3 = FUN_100144a5(iVar3,(int *)(param_4 + 8));
      *piVar1 = iVar3;
      ExceptionList = local_14;
      return;
    }
  }
  FUN_1001457d();
  ExceptionList = local_14;
  return;
}



/* ===== FUN_1001443e @ 0x1001443E ===== */

void __cdecl FUN_1001443e(int param_1)

{
  undefined *UNRECOVERED_JUMPTABLE;
  void *local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_1001c588;
  puStack_10 = &LAB_100132e0;
  local_14 = ExceptionList;
  if ((param_1 != 0) &&
     (UNRECOVERED_JUMPTABLE = *(undefined **)(*(int *)(param_1 + 0x1c) + 4),
     UNRECOVERED_JUMPTABLE != (undefined *)0x0)) {
    local_8 = 0;
    ExceptionList = &local_14;
    FUN_10010531(*(undefined4 *)(param_1 + 0x18),UNRECOVERED_JUMPTABLE);
  }
  ExceptionList = local_14;
  return;
}



/* ===== FUN_100144a5 @ 0x100144A5 ===== */

int __cdecl FUN_100144a5(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = param_2[1];
  iVar2 = *param_2 + param_1;
  if (-1 < iVar1) {
    iVar2 = iVar2 + *(int *)(*(int *)(iVar1 + param_1) + param_2[2]) + iVar1;
  }
  return iVar2;
}



/* ===== __CallSettingFrame@12 @ 0x100144D0 ===== */

/* WARNING: Restarted to delay deadcode elimination for space: stack */
/* Library Function - Single Match
    __CallSettingFrame@12
   
   Libraries: Visual Studio 2017 Debug, Visual Studio 2017 Release, Visual Studio 2019 Debug, Visual
   Studio 2019 Release */

void __CallSettingFrame_12(undefined4 param_1,undefined4 param_2,int param_3)

{
  code *pcVar1;
  
  pcVar1 = (code *)__NLG_Notify1(param_3);
  (*pcVar1)();
  if (param_3 == 0x100) {
    param_3 = 2;
  }
  __NLG_Notify1(param_3);
  return;
}



/* ===== FUN_1001451c @ 0x1001451C ===== */

void FUN_1001451c(void)

{
  DWORD *pDVar1;
  void *pvStack_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_1001c598;
  puStack_10 = &LAB_100132e0;
  pvStack_14 = ExceptionList;
  local_8 = 0;
  ExceptionList = &pvStack_14;
  pDVar1 = FUN_1001343d();
  if (pDVar1[0x18] != 0) {
    local_8 = 1;
    pDVar1 = FUN_1001343d();
    (*(code *)pDVar1[0x18])();
  }
  local_8 = 0xffffffff;
  FUN_10017c64();
  return;
}



/* ===== FUN_1001457d @ 0x1001457D ===== */

void FUN_1001457d(void)

{
  void *pvStack_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_1001c5b0;
  puStack_10 = &LAB_100132e0;
  pvStack_14 = ExceptionList;
  ExceptionList = &pvStack_14;
  if (PTR_FUN_10023190 != (undefined *)0x0) {
    local_8 = 1;
    ExceptionList = &pvStack_14;
    (*(code *)PTR_FUN_10023190)();
  }
  local_8 = 0xffffffff;
  FUN_1001451c();
  return;
}



/* ===== FUN_100145d3 @ 0x100145D3 ===== */

void FUN_100145d3(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  DWORD DVar4;
  HANDLE hFile;
  UINT *pUVar5;
  int iVar6;
  uint uVar7;
  UINT UVar8;
  UINT UVar9;
  _STARTUPINFOA local_4c;
  byte *local_8;
  
  puVar2 = _malloc(0x480);
  if (puVar2 == (undefined4 *)0x0) {
    __amsg_exit(0x1b);
  }
  DAT_10026bc0 = 0x20;
  DAT_10026ac0 = puVar2;
  for (; puVar2 < DAT_10026ac0 + 0x120; puVar2 = puVar2 + 9) {
    *(undefined1 *)(puVar2 + 1) = 0;
    *puVar2 = 0xffffffff;
    puVar2[2] = 0;
    *(undefined1 *)((int)puVar2 + 5) = 10;
  }
  GetStartupInfoA(&local_4c);
  if ((local_4c.cbReserved2 != 0) && ((UINT *)local_4c.lpReserved2 != (UINT *)0x0)) {
    UVar8 = *(UINT *)local_4c.lpReserved2;
    pUVar5 = (UINT *)((int)local_4c.lpReserved2 + 4);
    local_8 = (byte *)((int)pUVar5 + UVar8);
    if (0x7ff < (int)UVar8) {
      UVar8 = 0x800;
    }
    UVar9 = UVar8;
    if ((int)DAT_10026bc0 < (int)UVar8) {
      puVar2 = &DAT_10026ac4;
      do {
        puVar3 = _malloc(0x480);
        UVar9 = DAT_10026bc0;
        if (puVar3 == (undefined4 *)0x0) break;
        DAT_10026bc0 = DAT_10026bc0 + 0x20;
        *puVar2 = puVar3;
        puVar1 = puVar3;
        for (; puVar3 < puVar1 + 0x120; puVar3 = puVar3 + 9) {
          *(undefined1 *)(puVar3 + 1) = 0;
          *puVar3 = 0xffffffff;
          puVar3[2] = 0;
          *(undefined1 *)((int)puVar3 + 5) = 10;
          puVar1 = (undefined4 *)*puVar2;
        }
        puVar2 = puVar2 + 1;
        UVar9 = UVar8;
      } while ((int)DAT_10026bc0 < (int)UVar8);
    }
    uVar7 = 0;
    if (0 < (int)UVar9) {
      do {
        if (((*(HANDLE *)local_8 != (HANDLE)0xffffffff) && ((*pUVar5 & 1) != 0)) &&
           (((*pUVar5 & 8) != 0 || (DVar4 = GetFileType(*(HANDLE *)local_8), DVar4 != 0)))) {
          puVar2 = (undefined4 *)((int)(&DAT_10026ac0)[(int)uVar7 >> 5] + (uVar7 & 0x1f) * 0x24);
          *puVar2 = *(undefined4 *)local_8;
          *(byte *)(puVar2 + 1) = (byte)*pUVar5;
        }
        local_8 = local_8 + 4;
        uVar7 = uVar7 + 1;
        pUVar5 = (UINT *)((int)pUVar5 + 1);
      } while ((int)uVar7 < (int)UVar9);
    }
  }
  iVar6 = 0;
  do {
    puVar2 = DAT_10026ac0 + iVar6 * 9;
    if (DAT_10026ac0[iVar6 * 9] == -1) {
      *(undefined1 *)(puVar2 + 1) = 0x81;
      if (iVar6 == 0) {
        DVar4 = 0xfffffff6;
      }
      else {
        DVar4 = 0xfffffff5 - (iVar6 != 1);
      }
      hFile = GetStdHandle(DVar4);
      if ((hFile != (HANDLE)0xffffffff) && (DVar4 = GetFileType(hFile), DVar4 != 0)) {
        *puVar2 = hFile;
        if ((DVar4 & 0xff) != 2) {
          if ((DVar4 & 0xff) == 3) {
            *(byte *)(puVar2 + 1) = *(byte *)(puVar2 + 1) | 8;
          }
          goto LAB_10014778;
        }
      }
      *(byte *)(puVar2 + 1) = *(byte *)(puVar2 + 1) | 0x40;
    }
    else {
      *(byte *)(puVar2 + 1) = *(byte *)(puVar2 + 1) | 0x80;
    }
LAB_10014778:
    iVar6 = iVar6 + 1;
    if (2 < iVar6) {
      SetHandleCount(DAT_10026bc0);
      return;
    }
  } while( true );
}



/* ===== FUN_1001478f @ 0x1001478F ===== */

void FUN_1001478f(void)

{
  LPCRITICAL_SECTION lpCriticalSection;
  uint *puVar1;
  uint uVar2;
  
  puVar1 = &DAT_10026ac0;
  do {
    uVar2 = *puVar1;
    if (uVar2 != 0) {
      if (uVar2 < uVar2 + 0x480) {
        lpCriticalSection = (LPCRITICAL_SECTION)(uVar2 + 0xc);
        do {
          if (lpCriticalSection[-1].SpinCount != 0) {
            DeleteCriticalSection(lpCriticalSection);
          }
          uVar2 = uVar2 + 0x24;
          lpCriticalSection = (LPCRITICAL_SECTION)&lpCriticalSection[1].OwningThread;
        } while (uVar2 < *puVar1 + 0x480);
      }
      FUN_100101ee((undefined *)*puVar1);
      *puVar1 = 0;
    }
    puVar1 = puVar1 + 1;
  } while ((int)puVar1 < 0x10026bc0);
  return;
}



/* ===== FUN_100147e3 @ 0x100147E3 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100147e3(void)

{
  char cVar1;
  size_t sVar2;
  undefined4 *puVar3;
  void *pvVar4;
  int iVar5;
  uint *puVar6;
  
  if (DAT_10026bec == 0) {
    FUN_1001838d();
  }
  iVar5 = 0;
  for (puVar6 = DAT_100254e4; (char)*puVar6 != '\0'; puVar6 = (uint *)((int)puVar6 + sVar2 + 1)) {
    if ((char)*puVar6 != '=') {
      iVar5 = iVar5 + 1;
    }
    sVar2 = _strlen((char *)puVar6);
  }
  puVar3 = _malloc(iVar5 * 4 + 4);
  _DAT_10025514 = puVar3;
  if (puVar3 == (undefined4 *)0x0) {
    __amsg_exit(9);
  }
  cVar1 = (char)*DAT_100254e4;
  puVar6 = DAT_100254e4;
  while (cVar1 != '\0') {
    sVar2 = _strlen((char *)puVar6);
    if ((char)*puVar6 != '=') {
      pvVar4 = _malloc(sVar2 + 1);
      *puVar3 = pvVar4;
      if (pvVar4 == (void *)0x0) {
        __amsg_exit(9);
      }
      FUN_10015ea0((uint *)*puVar3,puVar6);
      puVar3 = puVar3 + 1;
    }
    puVar6 = (uint *)((int)puVar6 + sVar2 + 1);
    cVar1 = (char)*puVar6;
  }
  FUN_100101ee((undefined *)DAT_100254e4);
  DAT_100254e4 = (uint *)0x0;
  *puVar3 = 0;
  _DAT_10026be8 = 1;
  return;
}



/* ===== FUN_1001489c @ 0x1001489C ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001489c(void)

{
  undefined4 *puVar1;
  byte *pbVar2;
  int local_c;
  int local_8;
  
  if (DAT_10026bec == 0) {
    FUN_1001838d();
  }
  GetModuleFileNameA((HMODULE)0x0,&DAT_100255a8,0x104);
  _DAT_10025524 = &DAT_100255a8;
  pbVar2 = &DAT_100255a8;
  if (*DAT_10026bf8 != 0) {
    pbVar2 = DAT_10026bf8;
  }
  FUN_10014935(pbVar2,(undefined4 *)0x0,(byte *)0x0,&local_8,&local_c);
  puVar1 = _malloc(local_c + local_8 * 4);
  if (puVar1 == (undefined4 *)0x0) {
    __amsg_exit(8);
  }
  FUN_10014935(pbVar2,puVar1,(byte *)(puVar1 + local_8),&local_8,&local_c);
  _DAT_1002550c = puVar1;
  _DAT_10025508 = local_8 + -1;
  return;
}



/* ===== FUN_10014935 @ 0x10014935 ===== */

void __cdecl FUN_10014935(byte *param_1,undefined4 *param_2,byte *param_3,int *param_4,int *param_5)

{
  byte bVar1;
  bool bVar2;
  bool bVar3;
  byte *pbVar4;
  byte *pbVar5;
  uint uVar6;
  undefined4 *puVar7;
  
  *param_5 = 0;
  *param_4 = 1;
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = param_3;
    param_2 = param_2 + 1;
  }
  if (*param_1 == 0x22) {
    while( true ) {
      bVar1 = param_1[1];
      pbVar4 = param_1 + 1;
      if ((bVar1 == 0x22) || (bVar1 == 0)) break;
      if (((*(byte *)((int)&DAT_10025980 + bVar1 + 1) & 4) != 0) &&
         (*param_5 = *param_5 + 1, param_3 != (byte *)0x0)) {
        *param_3 = *pbVar4;
        param_3 = param_3 + 1;
        pbVar4 = param_1 + 2;
      }
      *param_5 = *param_5 + 1;
      param_1 = pbVar4;
      if (param_3 != (byte *)0x0) {
        *param_3 = *pbVar4;
        param_3 = param_3 + 1;
      }
    }
    *param_5 = *param_5 + 1;
    if (param_3 != (byte *)0x0) {
      *param_3 = 0;
      param_3 = param_3 + 1;
    }
    if (*pbVar4 == 0x22) {
      pbVar4 = param_1 + 2;
    }
  }
  else {
    do {
      *param_5 = *param_5 + 1;
      if (param_3 != (byte *)0x0) {
        *param_3 = *param_1;
        param_3 = param_3 + 1;
      }
      bVar1 = *param_1;
      pbVar4 = param_1 + 1;
      if ((*(byte *)((int)&DAT_10025980 + bVar1 + 1) & 4) != 0) {
        *param_5 = *param_5 + 1;
        if (param_3 != (byte *)0x0) {
          *param_3 = *pbVar4;
          param_3 = param_3 + 1;
        }
        pbVar4 = param_1 + 2;
      }
      if (bVar1 == 0x20) break;
      if (bVar1 == 0) goto LAB_100149e0;
      param_1 = pbVar4;
    } while (bVar1 != 9);
    if (bVar1 == 0) {
LAB_100149e0:
      pbVar4 = pbVar4 + -1;
    }
    else if (param_3 != (byte *)0x0) {
      param_3[-1] = 0;
    }
  }
  bVar2 = false;
  puVar7 = param_2;
  while (*pbVar4 != 0) {
    for (; (*pbVar4 == 0x20 || (*pbVar4 == 9)); pbVar4 = pbVar4 + 1) {
    }
    if (*pbVar4 == 0) break;
    if (puVar7 != (undefined4 *)0x0) {
      *puVar7 = param_3;
      puVar7 = puVar7 + 1;
      param_2 = puVar7;
    }
    *param_4 = *param_4 + 1;
    while( true ) {
      bVar3 = true;
      uVar6 = 0;
      for (; *pbVar4 == 0x5c; pbVar4 = pbVar4 + 1) {
        uVar6 = uVar6 + 1;
      }
      if (*pbVar4 == 0x22) {
        pbVar5 = pbVar4;
        if ((uVar6 & 1) == 0) {
          if ((!bVar2) || (pbVar5 = pbVar4 + 1, pbVar4[1] != 0x22)) {
            bVar3 = false;
            pbVar5 = pbVar4;
          }
          bVar2 = !bVar2;
          puVar7 = param_2;
        }
        uVar6 = uVar6 >> 1;
        pbVar4 = pbVar5;
      }
      for (; uVar6 != 0; uVar6 = uVar6 - 1) {
        if (param_3 != (byte *)0x0) {
          *param_3 = 0x5c;
          param_3 = param_3 + 1;
        }
        *param_5 = *param_5 + 1;
      }
      bVar1 = *pbVar4;
      if ((bVar1 == 0) || ((!bVar2 && ((bVar1 == 0x20 || (bVar1 == 9)))))) break;
      if (bVar3) {
        if (param_3 == (byte *)0x0) {
          if ((*(byte *)((int)&DAT_10025980 + bVar1 + 1) & 4) != 0) {
            pbVar4 = pbVar4 + 1;
            *param_5 = *param_5 + 1;
          }
        }
        else {
          if ((*(byte *)((int)&DAT_10025980 + bVar1 + 1) & 4) != 0) {
            *param_3 = bVar1;
            param_3 = param_3 + 1;
            pbVar4 = pbVar4 + 1;
            *param_5 = *param_5 + 1;
          }
          *param_3 = *pbVar4;
          param_3 = param_3 + 1;
        }
        *param_5 = *param_5 + 1;
      }
      pbVar4 = pbVar4 + 1;
    }
    if (param_3 != (byte *)0x0) {
      *param_3 = 0;
      param_3 = param_3 + 1;
    }
    *param_5 = *param_5 + 1;
  }
  if (puVar7 != (undefined4 *)0x0) {
    *puVar7 = 0;
  }
  *param_4 = *param_4 + 1;
  return;
}



/* ===== FUN_10014ae9 @ 0x10014AE9 ===== */

LPSTR FUN_10014ae9(void)

{
  char cVar1;
  WCHAR WVar2;
  WCHAR *pWVar3;
  WCHAR *pWVar4;
  int iVar5;
  size_t _Size;
  LPSTR pCVar6;
  char *pcVar7;
  LPWCH lpWideCharStr;
  LPCH pCVar9;
  LPSTR local_8;
  char *pcVar8;
  
  lpWideCharStr = (LPWCH)0x0;
  pCVar9 = (LPCH)0x0;
  if (DAT_100256ac == 0) {
    lpWideCharStr = GetEnvironmentStringsW();
    if (lpWideCharStr != (LPWCH)0x0) {
      DAT_100256ac = 1;
LAB_10014b40:
      if ((lpWideCharStr == (LPWCH)0x0) &&
         (lpWideCharStr = GetEnvironmentStringsW(), lpWideCharStr == (LPWCH)0x0)) {
        return (LPSTR)0x0;
      }
      WVar2 = *lpWideCharStr;
      pWVar4 = lpWideCharStr;
      while (WVar2 != L'\0') {
        do {
          pWVar3 = pWVar4;
          pWVar4 = pWVar3 + 1;
        } while (*pWVar4 != L'\0');
        pWVar4 = pWVar3 + 2;
        WVar2 = *pWVar4;
      }
      iVar5 = ((int)pWVar4 - (int)lpWideCharStr >> 1) + 1;
      _Size = WideCharToMultiByte(0,0,lpWideCharStr,iVar5,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0);
      local_8 = (LPSTR)0x0;
      if (((_Size != 0) && (pCVar6 = _malloc(_Size), pCVar6 != (LPSTR)0x0)) &&
         (iVar5 = WideCharToMultiByte(0,0,lpWideCharStr,iVar5,pCVar6,_Size,(LPCSTR)0x0,(LPBOOL)0x0),
         local_8 = pCVar6, iVar5 == 0)) {
        FUN_100101ee(pCVar6);
        local_8 = (LPSTR)0x0;
      }
      FreeEnvironmentStringsW(lpWideCharStr);
      return local_8;
    }
    pCVar9 = GetEnvironmentStrings();
    if (pCVar9 == (LPCH)0x0) {
      return (LPSTR)0x0;
    }
    DAT_100256ac = 2;
  }
  else {
    if (DAT_100256ac == 1) goto LAB_10014b40;
    if (DAT_100256ac != 2) {
      return (LPSTR)0x0;
    }
  }
  if ((pCVar9 == (LPCH)0x0) && (pCVar9 = GetEnvironmentStrings(), pCVar9 == (LPCH)0x0)) {
    return (LPSTR)0x0;
  }
  cVar1 = *pCVar9;
  pcVar7 = pCVar9;
  while (cVar1 != '\0') {
    do {
      pcVar8 = pcVar7;
      pcVar7 = pcVar8 + 1;
    } while (*pcVar7 != '\0');
    pcVar7 = pcVar8 + 2;
    cVar1 = *pcVar7;
  }
  pCVar6 = _malloc((size_t)(pcVar7 + (1 - (int)pCVar9)));
  if (pCVar6 == (LPSTR)0x0) {
    pCVar6 = (LPSTR)0x0;
  }
  else {
    FUN_10017c80((undefined4 *)pCVar6,(undefined4 *)pCVar9,(uint)(pcVar7 + (1 - (int)pCVar9)));
  }
  FreeEnvironmentStringsA(pCVar9);
  return pCVar6;
}



/* ===== FUN_10014c1b @ 0x10014C1B ===== */

undefined4 FUN_10014c1b(void)

{
  return 1;
}



/* ===== FUN_10014c21 @ 0x10014C21 ===== */

void FUN_10014c21(void)

{
  if ((DAT_100254ec == 1) || ((DAT_100254ec == 0 && (DAT_100254f0 == 1)))) {
    FUN_10014c5a(0xfc);
    if (DAT_100256b0 != (code *)0x0) {
      (*DAT_100256b0)();
    }
    FUN_10014c5a(0xff);
  }
  return;
}



/* ===== FUN_10014c5a @ 0x10014C5A ===== */

void __cdecl FUN_10014c5a(DWORD param_1)

{
  undefined4 *puVar1;
  DWORD *pDVar2;
  DWORD DVar3;
  size_t sVar4;
  HANDLE hFile;
  int iVar5;
  uint *_Dest;
  undefined1 auStackY_1e3 [7];
  LPCVOID lpBuffer;
  LPOVERLAPPED lpOverlapped;
  uint local_1a8 [65];
  uint local_a4 [40];
  
  iVar5 = 0;
  pDVar2 = &DAT_100231c0;
  do {
    if (param_1 == *pDVar2) break;
    pDVar2 = pDVar2 + 2;
    iVar5 = iVar5 + 1;
  } while (pDVar2 < &DAT_10023250);
  if (param_1 == (&DAT_100231c0)[iVar5 * 2]) {
    if ((DAT_100254ec == 1) || ((DAT_100254ec == 0 && (DAT_100254f0 == 1)))) {
      pDVar2 = &param_1;
      puVar1 = (undefined4 *)(iVar5 * 8 + 0x100231c4);
      lpOverlapped = (LPOVERLAPPED)0x0;
      sVar4 = _strlen((char *)*puVar1);
      lpBuffer = (LPCVOID)*puVar1;
      hFile = GetStdHandle(0xfffffff4);
      WriteFile(hFile,lpBuffer,sVar4,pDVar2,lpOverlapped);
    }
    else if (param_1 != 0xfc) {
      DVar3 = GetModuleFileNameA((HMODULE)0x0,(LPSTR)local_1a8,0x104);
      if (DVar3 == 0) {
        FUN_10015ea0(local_1a8,(uint *)"<program name unknown>");
      }
      _Dest = local_1a8;
      sVar4 = _strlen((char *)local_1a8);
      if (0x3c < sVar4 + 1) {
        sVar4 = _strlen((char *)local_1a8);
        _Dest = (uint *)(auStackY_1e3 + sVar4);
        _strncpy((char *)_Dest,"...",3);
      }
      FUN_10015ea0(local_a4,(uint *)"Runtime Error!\n\nProgram: ");
      FUN_10015eb0(local_a4,_Dest);
      FUN_10015eb0(local_a4,(uint *)&DAT_1001c87c);
      FUN_10015eb0(local_a4,*(uint **)(iVar5 * 8 + 0x100231c4));
      auStackY_1e3._3_4_ = 0x10014d7e;
      FUN_100183a9(local_a4,"Microsoft Visual C++ Runtime Library",0x12010);
    }
  }
  return;
}



/* ===== FUN_10014dad @ 0x10014DAD ===== */

float10 __cdecl FUN_10014dad(undefined8 param_1,short param_2)

{
  undefined8 local_c;
  
  local_c = (double)CONCAT26((param_2 + 0x3fe) * 0x10 | param_1._6_2_ & 0x800f,(int6)param_1);
  return (float10)local_c;
}



/* ===== FUN_10014dd6 @ 0x10014DD6 ===== */

undefined4 __cdecl FUN_10014dd6(int param_1,uint param_2)

{
  undefined4 uStack_8;
  
  if (param_2 == 0x7ff00000) {
    if (param_1 == 0) {
      return 1;
    }
  }
  else if ((param_2 == 0xfff00000) && (param_1 == 0)) {
    return 2;
  }
  if ((param_2._2_2_ & 0x7ff8) == 0x7ff8) {
    uStack_8 = 3;
  }
  else {
    if (((param_2._2_2_ & 0x7ff8) != 0x7ff0) || (((param_2 & 0x7ffff) == 0 && (param_1 == 0)))) {
      return 0;
    }
    uStack_8 = 4;
  }
  return uStack_8;
}



/* ===== FUN_10014e30 @ 0x10014E30 ===== */

float10 __cdecl FUN_10014e30(uint param_1,uint param_2,int *param_3)

{
  ushort uVar1;
  int iVar2;
  bool bVar3;
  int iVar4;
  float10 fVar5;
  undefined8 local_c;
  
  if ((double)CONCAT17(param_2._3_1_,CONCAT16(param_2._2_1_,CONCAT24((ushort)param_2,param_1))) ==
      0.0) {
    iVar4 = 0;
    local_c = 0.0;
  }
  else if (((param_2 & 0x7ff00000) == 0) && (((param_2 & 0xfffff) != 0 || (param_1 != 0)))) {
    iVar4 = -0x3fd;
    if (0.0 <= (double)CONCAT17(param_2._3_1_,
                                CONCAT16(param_2._2_1_,CONCAT24((ushort)param_2,param_1)))) {
      bVar3 = false;
    }
    else {
      bVar3 = true;
    }
    while ((param_2._2_1_ & 0x10) == 0) {
      iVar2 = CONCAT13(param_2._3_1_,CONCAT12(param_2._2_1_,(ushort)param_2)) << 1;
      param_2._0_2_ = (ushort)iVar2;
      param_2._2_1_ = (byte)((uint)iVar2 >> 0x10);
      param_2._3_1_ = (byte)((uint)iVar2 >> 0x18);
      if ((param_1 & 0x80000000) != 0) {
        param_2._0_2_ = (ushort)param_2 | 1;
      }
      param_1 = param_1 << 1;
      iVar4 = iVar4 + -1;
    }
    uVar1 = CONCAT11(param_2._3_1_,param_2._2_1_) & 0xffef;
    param_2._2_1_ = (byte)uVar1;
    param_2._3_1_ = (byte)(uVar1 >> 8);
    if (bVar3) {
      param_2._3_1_ = param_2._3_1_ | 0x80;
    }
    fVar5 = FUN_10014dad(CONCAT17(param_2._3_1_,
                                  CONCAT16(param_2._2_1_,CONCAT24((ushort)param_2,param_1))),0);
    local_c = (double)fVar5;
  }
  else {
    fVar5 = FUN_10014dad(CONCAT17(param_2._3_1_,
                                  CONCAT16(param_2._2_1_,CONCAT24((ushort)param_2,param_1))),0);
    local_c = (double)fVar5;
    iVar4 = (short)((ushort)(param_2 >> 0x14) & 0x7ff) + -0x3fe;
  }
  *param_3 = iVar4;
  return (float10)local_c;
}



/* ===== FUN_10014ef1 @ 0x10014EF1 ===== */

void __cdecl
FUN_10014ef1(uint *param_1,uint *param_2,uint param_3,uint param_4,undefined8 *param_5,
            undefined8 *param_6)

{
  uint *puVar1;
  undefined8 *puVar2;
  uint uVar3;
  
  uVar3 = param_3;
  puVar1 = param_2;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  if ((param_3 & 0x10) != 0) {
    param_3 = 0xc000008f;
    param_1[1] = param_1[1] | 1;
  }
  if ((uVar3 & 2) != 0) {
    param_3 = 0xc0000093;
    param_1[1] = param_1[1] | 2;
  }
  if ((uVar3 & 1) != 0) {
    param_3 = 0xc0000091;
    param_1[1] = param_1[1] | 4;
  }
  if ((uVar3 & 4) != 0) {
    param_3 = 0xc000008e;
    param_1[1] = param_1[1] | 8;
  }
  if ((uVar3 & 8) != 0) {
    param_3 = 0xc0000090;
    param_1[1] = param_1[1] | 0x10;
  }
  param_1[2] = (~*param_2 & 1) << 4 | param_1[2] & 0xffffffef;
  param_1[2] = (~*param_2 & 4) << 1 | param_1[2] & 0xfffffff7;
  param_1[2] = ~*param_2 >> 1 & 4 | param_1[2] & 0xfffffffb;
  param_1[2] = ~*param_2 >> 3 & 2 | param_1[2] & 0xfffffffd;
  param_1[2] = ~*param_2 >> 5 & 1 | param_1[2] & 0xfffffffe;
  uVar3 = FUN_100153e3();
  puVar2 = param_6;
  if ((uVar3 & 1) != 0) {
    param_1[3] = param_1[3] | 0x10;
  }
  if ((uVar3 & 4) != 0) {
    param_1[3] = param_1[3] | 8;
  }
  if ((uVar3 & 8) != 0) {
    param_1[3] = param_1[3] | 4;
  }
  if ((uVar3 & 0x10) != 0) {
    param_1[3] = param_1[3] | 2;
  }
  if ((uVar3 & 0x20) != 0) {
    param_1[3] = param_1[3] | 1;
  }
  uVar3 = *puVar1 & 0xc00;
  if (uVar3 == 0) {
    *param_1 = *param_1 & 0xfffffffc;
  }
  else {
    if (uVar3 == 0x400) {
      uVar3 = *param_1 & 0xfffffffd | 1;
    }
    else {
      if (uVar3 != 0x800) {
        if (uVar3 == 0xc00) {
          *param_1 = *param_1 | 3;
        }
        goto LAB_10015066;
      }
      uVar3 = *param_1 & 0xfffffffe | 2;
    }
    *param_1 = uVar3;
  }
LAB_10015066:
  uVar3 = *puVar1 & 0x300;
  if (uVar3 == 0) {
    uVar3 = *param_1 & 0xffffffeb | 8;
LAB_1001509c:
    *param_1 = uVar3;
  }
  else {
    if (uVar3 == 0x200) {
      uVar3 = *param_1 & 0xffffffe7 | 4;
      goto LAB_1001509c;
    }
    if (uVar3 == 0x300) {
      *param_1 = *param_1 & 0xffffffe3;
    }
  }
  *param_1 = (param_4 & 0xfff) << 5 | *param_1 & 0xfffe001f;
  param_1[8] = param_1[8] | 1;
  param_1[8] = param_1[8] & 0xffffffe3 | 2;
  *(undefined8 *)(param_1 + 4) = *param_5;
  param_1[0x14] = param_1[0x14] | 1;
  param_1[0x14] = param_1[0x14] & 0xffffffe3 | 2;
  *(undefined8 *)(param_1 + 0x10) = *param_6;
  FUN_100153f1();
  RaiseException(param_3,0,1,(ULONG_PTR *)&param_1);
  if ((param_1[2] & 0x10) != 0) {
    *puVar1 = *puVar1 & 0xfffffffe;
  }
  if ((param_1[2] & 8) != 0) {
    *puVar1 = *puVar1 & 0xfffffffb;
  }
  if ((param_1[2] & 4) != 0) {
    *puVar1 = *puVar1 & 0xfffffff7;
  }
  if ((param_1[2] & 2) != 0) {
    *puVar1 = *puVar1 & 0xffffffef;
  }
  if ((param_1[2] & 1) != 0) {
    *puVar1 = *puVar1 & 0xffffffdf;
  }
  uVar3 = *param_1 & 3;
  if (uVar3 == 0) {
    *puVar1 = *puVar1 & 0xfffff3ff;
  }
  else {
    if (uVar3 == 1) {
      uVar3 = *puVar1 & 0xfffff7ff | 0x400;
    }
    else {
      if (uVar3 != 2) {
        if (uVar3 == 3) {
          *(byte *)((int)puVar1 + 1) = *(byte *)((int)puVar1 + 1) | 0xc;
        }
        goto LAB_10015171;
      }
      uVar3 = *puVar1 & 0xfffffbff | 0x800;
    }
    *puVar1 = uVar3;
  }
LAB_10015171:
  uVar3 = *param_1 >> 2 & 7;
  if (uVar3 == 0) {
    uVar3 = *puVar1 & 0xfffff3ff | 0x300;
  }
  else {
    if (uVar3 != 1) {
      if (uVar3 == 2) {
        *puVar1 = *puVar1 & 0xfffff3ff;
      }
      goto LAB_1001519a;
    }
    uVar3 = *puVar1 & 0xfffff3ff | 0x200;
  }
  *puVar1 = uVar3;
LAB_1001519a:
  *puVar2 = *(undefined8 *)(param_1 + 0x10);
  return;
}



/* ===== FUN_100151a4 @ 0x100151A4 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool __cdecl FUN_100151a4(uint param_1,double *param_2,uint param_3)

{
  double dVar1;
  bool bVar2;
  uint uVar3;
  bool bVar4;
  float10 fVar5;
  undefined8 local_10;
  int local_8;
  
  uVar3 = param_1 & 0x1f;
  bVar2 = true;
  if (((param_1 & 8) != 0) && ((param_3 & 1) != 0)) {
    FUN_10015423();
    uVar3 = param_1 & 0x17;
    goto LAB_10015399;
  }
  if (((param_1 & 4) != 0) && ((param_3 & 4) != 0)) {
    FUN_10015423();
    uVar3 = param_1 & 0x1b;
    goto LAB_10015399;
  }
  if (((param_1 & 1) == 0) || ((param_3 & 8) == 0)) {
    if (((param_1 & 2) != 0) && ((param_3 & 0x10) != 0)) {
      bVar4 = (param_1 & 0x10) != 0;
      dVar1 = *param_2;
      if (dVar1 != 0.0) {
        fVar5 = FUN_10014e30(SUB84(dVar1,0),(uint)((ulonglong)dVar1 >> 0x20),&local_8);
        local_8 = local_8 + -0x600;
        if (local_8 < -0x432) {
          local_10 = 0.0;
          bVar4 = bVar2;
        }
        else {
          local_10 = (double)(ulonglong)
                             (SUB87((double)fVar5,0) & 0xfffffffffffff | 0x10000000000000);
          if (local_8 < -0x3fd) {
            local_8 = -0x3fd - local_8;
            do {
              if ((((ulonglong)local_10 & 1) != 0) && (!bVar4)) {
                bVar4 = bVar2;
              }
              uVar3 = (uint)local_10 >> 1;
              if (((ulonglong)local_10 & 0x100000000) != 0) {
                local_10._3_1_ = (byte)((ulonglong)local_10 >> 0x18) >> 1;
                local_10._0_3_ = (undefined3)uVar3;
                local_10._0_4_ = CONCAT13(local_10._3_1_,(undefined3)local_10) | 0x80000000;
                uVar3 = (uint)local_10;
              }
              local_10._0_4_ = uVar3;
              local_10 = (double)CONCAT44(local_10._4_4_ >> 1,(uint)local_10);
              local_8 = local_8 + -1;
            } while (local_8 != 0);
          }
          if ((double)fVar5 < 0.0) {
            local_10 = -local_10;
          }
        }
        *param_2 = local_10;
        bVar2 = bVar4;
      }
      if (bVar2) {
        FUN_10015423();
      }
      uVar3 = param_1 & 0x1d;
    }
    goto LAB_10015399;
  }
  FUN_10015423();
  uVar3 = param_3 & 0xc00;
  dVar1 = _DAT_10023250;
  if (uVar3 == 0) {
    if (*param_2 <= 0.0) {
      dVar1 = -_DAT_10023250;
    }
LAB_100152b9:
    *param_2 = dVar1;
  }
  else {
    if (uVar3 == 0x400) {
      dVar1 = _DAT_10023260;
      if (*param_2 <= 0.0) {
        dVar1 = -_DAT_10023250;
      }
      goto LAB_100152b9;
    }
    if (uVar3 == 0x800) {
      if (*param_2 <= 0.0) {
        dVar1 = -_DAT_10023260;
      }
      goto LAB_100152b9;
    }
    if (uVar3 == 0xc00) {
      dVar1 = _DAT_10023260;
      if (*param_2 <= 0.0) {
        dVar1 = -_DAT_10023260;
      }
      goto LAB_100152b9;
    }
  }
  uVar3 = param_1 & 0x1e;
LAB_10015399:
  if (((param_1 & 0x10) != 0) && ((param_3 & 0x20) != 0)) {
    FUN_10015423();
    uVar3 = uVar3 & 0xffffffef;
  }
  return uVar3 == 0;
}



/* ===== FUN_100153bb @ 0x100153BB ===== */

void __cdecl FUN_100153bb(int param_1)

{
  DWORD *pDVar1;
  
  if (param_1 == 1) {
    pDVar1 = FUN_100184a5();
    *pDVar1 = 0x21;
  }
  else if ((1 < param_1) && (param_1 < 4)) {
    pDVar1 = FUN_100184a5();
    *pDVar1 = 0x22;
    return;
  }
  return;
}



/* ===== FUN_100153e3 @ 0x100153E3 ===== */

int FUN_100153e3(void)

{
  short in_FPUStatusWord;
  
  return (int)in_FPUStatusWord;
}



/* ===== FUN_100153f1 @ 0x100153F1 ===== */

int FUN_100153f1(void)

{
  short in_FPUStatusWord;
  
  return (int)in_FPUStatusWord;
}



/* ===== FUN_10015400 @ 0x10015400 ===== */

int FUN_10015400(void)

{
  short in_FPUControlWord;
  
  return (int)in_FPUControlWord;
}



/* ===== FUN_10015423 @ 0x10015423 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10015423(void)

{
  return;
}



/* ===== __frnd @ 0x10015479 ===== */

/* Library Function - Single Match
    __frnd
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release, Visual Studio 2012 Release,
   Visual Studio 2019 Release */

float10 __cdecl __frnd(double param_1)

{
  return (float10)ROUND(param_1);
}



/* ===== FUN_1001548b @ 0x1001548B ===== */

void FUN_1001548b(void)

{
  return;
}



/* ===== FUN_100154f0 @ 0x100154F0 ===== */

uint __thiscall FUN_100154f0(void *this,int param_1,uint param_2)

{
  BOOL BVar1;
  int iVar2;
  undefined4 local_8;
  
  if (param_1 + 1U < 0x101) {
    param_1._2_2_ = *(ushort *)(PTR_DAT_10023368 + param_1 * 2);
  }
  else {
    if ((PTR_DAT_10023368[(param_1 >> 8 & 0xffU) * 2 + 1] & 0x80) == 0) {
      local_8 = CONCAT31((int3)((uint)this >> 8),(char)param_1) & 0xffff00ff;
      iVar2 = 1;
    }
    else {
      local_8._0_2_ = CONCAT11((char)param_1,(char)((uint)param_1 >> 8));
      local_8 = CONCAT22((short)((uint)this >> 0x10),(undefined2)local_8) & 0xff00ffff;
      iVar2 = 2;
    }
    BVar1 = FUN_100184ba(1,(LPCSTR)&local_8,iVar2,(LPWORD)((int)&param_1 + 2),0,0,1);
    if (BVar1 == 0) {
      return 0;
    }
  }
  return param_1._2_2_ & param_2;
}



/* ===== _strlen @ 0x100155B0 ===== */

/* Library Function - Single Match
    _strlen
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

size_t __cdecl _strlen(char *_Str)

{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  
  puVar2 = (uint *)_Str;
  do {
    if (((uint)puVar2 & 3) == 0) goto LAB_100155d0;
    uVar1 = *puVar2;
    puVar2 = (uint *)((int)puVar2 + 1);
  } while ((char)uVar1 != '\0');
LAB_10015603:
  return (size_t)((int)puVar2 + (-1 - (int)_Str));
LAB_100155d0:
  do {
    do {
      puVar3 = puVar2;
      puVar2 = puVar3 + 1;
    } while (((*puVar3 ^ 0xffffffff ^ *puVar3 + 0x7efefeff) & 0x81010100) == 0);
    uVar1 = *puVar3;
    if ((char)uVar1 == '\0') {
      return (int)puVar3 - (int)_Str;
    }
    if ((char)(uVar1 >> 8) == '\0') {
      return (size_t)((int)puVar3 + (1 - (int)_Str));
    }
    if ((uVar1 & 0xff0000) == 0) {
      return (size_t)((int)puVar3 + (2 - (int)_Str));
    }
  } while ((uVar1 & 0xff000000) != 0);
  goto LAB_10015603;
}



/* ===== _memset @ 0x10015630 ===== */

/* Library Function - Single Match
    _memset
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

void * __cdecl _memset(void *_Dst,int _Val,size_t _Size)

{
  uint uVar1;
  uint uVar2;
  size_t sVar3;
  uint *puVar4;
  
  if (_Size == 0) {
    return _Dst;
  }
  uVar1 = _Val & 0xff;
  puVar4 = _Dst;
  if (3 < _Size) {
    uVar2 = -(int)_Dst & 3;
    sVar3 = _Size;
    if (uVar2 != 0) {
      sVar3 = _Size - uVar2;
      do {
        *(undefined1 *)puVar4 = (undefined1)_Val;
        puVar4 = (uint *)((int)puVar4 + 1);
        uVar2 = uVar2 - 1;
      } while (uVar2 != 0);
    }
    uVar1 = uVar1 * 0x1010101;
    _Size = sVar3 & 3;
    uVar2 = sVar3 >> 2;
    if (uVar2 != 0) {
      for (; uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar4 = uVar1;
        puVar4 = puVar4 + 1;
      }
      if (_Size == 0) {
        return _Dst;
      }
    }
  }
  do {
    *(char *)puVar4 = (char)uVar1;
    puVar4 = (uint *)((int)puVar4 + 1);
    _Size = _Size - 1;
  } while (_Size != 0);
  return _Dst;
}



/* ===== FUN_10015688 @ 0x10015688 ===== */

uint __thiscall FUN_10015688(void *this,uint param_1,uint param_2)

{
  uint uVar1;
  undefined2 in_FPUControlWord;
  undefined4 local_8;
  
  local_8 = CONCAT22((short)((uint)this >> 0x10),in_FPUControlWord);
  uVar1 = FUN_100156d3(local_8);
  uVar1 = uVar1 & ~param_2 | param_1 & param_2;
  FUN_10015765(uVar1);
  return uVar1;
}



/* ===== FUN_100156bd @ 0x100156BD ===== */

void __thiscall FUN_100156bd(void *this,uint param_1,uint param_2)

{
  FUN_10015688(this,param_1,param_2 & 0xfff7ffff);
  return;
}



/* ===== FUN_100156d3 @ 0x100156D3 ===== */

uint __cdecl FUN_100156d3(uint param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = 0;
  if ((param_1 & 1) != 0) {
    uVar1 = 0x10;
  }
  if ((param_1 & 4) != 0) {
    uVar1 = uVar1 | 8;
  }
  if ((param_1 & 8) != 0) {
    uVar1 = uVar1 | 4;
  }
  if ((param_1 & 0x10) != 0) {
    uVar1 = uVar1 | 2;
  }
  if ((param_1 & 0x20) != 0) {
    uVar1 = uVar1 | 1;
  }
  if ((param_1 & 2) != 0) {
    uVar1 = uVar1 | 0x80000;
  }
  uVar2 = param_1 & 0xc00;
  if (uVar2 != 0) {
    if (uVar2 == 0x400) {
      uVar1 = uVar1 | 0x100;
    }
    else if (uVar2 == 0x800) {
      uVar1 = uVar1 | 0x200;
    }
    else if (uVar2 == 0xc00) {
      uVar1 = uVar1 | 0x300;
    }
  }
  if ((param_1 & 0x300) == 0) {
    uVar1 = uVar1 | 0x20000;
  }
  else if ((param_1 & 0x300) == 0x200) {
    uVar1 = uVar1 | 0x10000;
  }
  if ((param_1 & 0x1000) != 0) {
    uVar1 = uVar1 | 0x40000;
  }
  return uVar1;
}



/* ===== FUN_10015765 @ 0x10015765 ===== */

uint __cdecl FUN_10015765(uint param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = (uint)((param_1 & 0x10) != 0);
  if ((param_1 & 8) != 0) {
    uVar1 = uVar1 | 4;
  }
  if ((param_1 & 4) != 0) {
    uVar1 = uVar1 | 8;
  }
  if ((param_1 & 2) != 0) {
    uVar1 = uVar1 | 0x10;
  }
  if ((param_1 & 1) != 0) {
    uVar1 = uVar1 | 0x20;
  }
  if ((param_1 & 0x80000) != 0) {
    uVar1 = uVar1 | 2;
  }
  uVar2 = param_1 & 0x300;
  if (uVar2 != 0) {
    if (uVar2 == 0x100) {
      uVar1 = uVar1 | 0x400;
    }
    else if (uVar2 == 0x200) {
      uVar1 = uVar1 | 0x800;
    }
    else if (uVar2 == 0x300) {
      uVar1 = uVar1 | 0xc00;
    }
  }
  if ((param_1 & 0x30000) == 0) {
    uVar1 = uVar1 | 0x300;
  }
  else if ((param_1 & 0x30000) == 0x10000) {
    uVar1 = uVar1 | 0x200;
  }
  if ((param_1 & 0x40000) != 0) {
    uVar1 = uVar1 | 0x1000;
  }
  return uVar1;
}



/* ===== FUN_100157ee @ 0x100157EE ===== */

uint __cdecl FUN_100157ee(uint param_1)

{
  void *extraout_ECX;
  bool bVar1;
  void *this;
  
  if (DAT_100256f8 == 0) {
    if ((0x40 < (int)param_1) && ((int)param_1 < 0x5b)) {
      return param_1 + 0x20;
    }
  }
  else {
    InterlockedIncrement((LONG *)&DAT_10025854);
    bVar1 = DAT_10025850 != 0;
    this = extraout_ECX;
    if (bVar1) {
      InterlockedDecrement((LONG *)&DAT_10025854);
      this = (void *)0x13;
      FUN_10013262(0x13);
    }
    param_1 = FUN_1001585d(this,param_1);
    if (bVar1) {
      FUN_100132c3(0x13);
    }
    else {
      InterlockedDecrement((LONG *)&DAT_10025854);
    }
  }
  return param_1;
}



/* ===== FUN_1001585d @ 0x1001585D ===== */

uint __thiscall FUN_1001585d(void *this,uint param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  void *local_8;
  
  uVar1 = param_1;
  if (DAT_100256f8 == 0) {
    if ((0x40 < (int)param_1) && ((int)param_1 < 0x5b)) {
      uVar1 = param_1 + 0x20;
    }
  }
  else {
    iVar3 = 1;
    local_8 = this;
    if ((int)param_1 < 0x100) {
      if (DAT_10023574 < 2) {
        uVar2 = (byte)PTR_DAT_10023368[param_1 * 2] & 1;
      }
      else {
        uVar2 = FUN_100154f0(this,param_1,1);
      }
      if (uVar2 == 0) {
        return uVar1;
      }
    }
    if ((PTR_DAT_10023368[((int)uVar1 >> 8 & 0xffU) * 2 + 1] & 0x80) == 0) {
      param_1 = CONCAT31((int3)(param_1 >> 8),(char)uVar1) & 0xffff00ff;
    }
    else {
      uVar2 = param_1 >> 0x10;
      param_1._0_2_ = CONCAT11((char)uVar1,(char)(uVar1 >> 8));
      param_1 = CONCAT22((short)uVar2,(undefined2)param_1) & 0xff00ffff;
      iVar3 = 2;
    }
    iVar3 = FUN_100187ee(DAT_100256f8,0x100,(char *)&param_1,iVar3,(LPWSTR)&local_8,3,0,1);
    if (iVar3 != 0) {
      if (iVar3 == 1) {
        uVar1 = (uint)local_8 & 0xff;
      }
      else {
        uVar1 = (uint)local_8 & 0xffff;
      }
    }
  }
  return uVar1;
}



/* ===== FUN_10015928 @ 0x10015928 ===== */

undefined4 __cdecl FUN_10015928(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  
  if ((*(uint *)(param_1 + (param_2 / 0x20) * 4) & ~(-1 << (0x1fU - (char)(param_2 % 0x20) & 0x1f)))
      != 0) {
    return 0;
  }
  iVar2 = param_2 / 0x20 + 1;
  if (iVar2 < 3) {
    piVar1 = (int *)(param_1 + iVar2 * 4);
    do {
      if (*piVar1 != 0) {
        return 0;
      }
      iVar2 = iVar2 + 1;
      piVar1 = piVar1 + 1;
    } while (iVar2 < 3);
  }
  return 1;
}



/* ===== FUN_10015971 @ 0x10015971 ===== */

void __cdecl FUN_10015971(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  
  puVar3 = (uint *)(param_1 + (param_2 / 0x20) * 4);
  iVar1 = FUN_10018a3d(*puVar3,1 << (0x1fU - (char)(param_2 % 0x20) & 0x1f),puVar3);
  iVar2 = param_2 / 0x20 + -1;
  if (-1 < iVar2) {
    puVar3 = (uint *)(param_1 + iVar2 * 4);
    do {
      if (iVar1 == 0) {
        return;
      }
      iVar1 = FUN_10018a3d(*puVar3,1,puVar3);
      iVar2 = iVar2 + -1;
      puVar3 = puVar3 + -1;
    } while (-1 < iVar2);
  }
  return;
}



/* ===== FUN_100159c7 @ 0x100159C7 ===== */

undefined4 __cdecl FUN_100159c7(int param_1,int param_2)

{
  uint *puVar1;
  int iVar2;
  byte bVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 local_8;
  
  local_8 = 0;
  puVar1 = (uint *)(param_1 + (param_2 / 0x20) * 4);
  bVar3 = 0x1f - (char)(param_2 % 0x20);
  if (((*puVar1 & 1 << (bVar3 & 0x1f)) != 0) &&
     (iVar2 = FUN_10015928(param_1,param_2 + 1), iVar2 == 0)) {
    local_8 = FUN_10015971(param_1,param_2 + -1);
  }
  *puVar1 = *puVar1 & -1 << (bVar3 & 0x1f);
  iVar2 = param_2 / 0x20 + 1;
  if (iVar2 < 3) {
    puVar5 = (undefined4 *)(param_1 + iVar2 * 4);
    for (iVar4 = 3 - iVar2; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar5 = 0;
      puVar5 = puVar5 + 1;
    }
  }
  return local_8;
}



/* ===== FUN_10015a53 @ 0x10015A53 ===== */

void __cdecl FUN_10015a53(int param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = param_1 - (int)param_2;
  iVar2 = 3;
  do {
    *(undefined4 *)(iVar1 + (int)param_2) = *param_2;
    param_2 = param_2 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}



/* ===== FUN_10015a6e @ 0x10015A6E ===== */

void __cdecl FUN_10015a6e(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return;
}



/* ===== FUN_10015a7a @ 0x10015A7A ===== */

undefined4 __cdecl FUN_10015a7a(int *param_1)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    if (*param_1 != 0) {
      return 0;
    }
    iVar1 = iVar1 + 1;
    param_1 = param_1 + 1;
  } while (iVar1 < 3);
  return 1;
}



/* ===== FUN_10015a95 @ 0x10015A95 ===== */

void __cdecl FUN_10015a95(uint *param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  uint *puVar6;
  int local_8;
  
  local_8 = 3;
  iVar2 = (int)param_2 / 0x20;
  iVar5 = (int)param_2 % 0x20;
  param_2 = 0;
  bVar3 = (byte)iVar5;
  puVar6 = param_1;
  do {
    uVar1 = *puVar6;
    *puVar6 = uVar1 >> (bVar3 & 0x1f) | param_2;
    puVar6 = puVar6 + 1;
    param_2 = (uVar1 & ~(-1 << (bVar3 & 0x1f))) << (0x20 - bVar3 & 0x1f);
    local_8 = local_8 + -1;
  } while (local_8 != 0);
  iVar5 = 2;
  iVar4 = 8;
  do {
    if (iVar5 < iVar2) {
      *(undefined4 *)(iVar4 + (int)param_1) = 0;
    }
    else {
      *(undefined4 *)(iVar4 + (int)param_1) = *(undefined4 *)(iVar4 + iVar2 * -4 + (int)param_1);
    }
    iVar5 = iVar5 + -1;
    iVar4 = iVar4 + -4;
  } while (-1 < iVar4);
  return;
}



/* ===== FUN_10015b22 @ 0x10015B22 ===== */

undefined4 __cdecl FUN_10015b22(ushort *param_1,uint *param_2,int *param_3)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 local_1c [3];
  uint local_10;
  uint local_c;
  int local_8;
  
  uVar1 = param_1[5];
  local_10 = *(uint *)(param_1 + 3);
  local_c = *(uint *)(param_1 + 1);
  uVar3 = uVar1 & 0x7fff;
  iVar4 = uVar3 - 0x3fff;
  local_8 = (uint)*param_1 << 0x10;
  if (iVar4 == -0x3fff) {
    iVar4 = 0;
    iVar2 = FUN_10015a7a((int *)&local_10);
    if (iVar2 != 0) {
LAB_10015c4e:
      uVar5 = 0;
      goto LAB_10015c50;
    }
    FUN_10015a6e(&local_10);
  }
  else {
    FUN_10015a53((int)local_1c,&local_10);
    iVar2 = FUN_100159c7((int)&local_10,param_3[2]);
    if (iVar2 != 0) {
      iVar4 = uVar3 - 0x3ffe;
    }
    iVar2 = param_3[1];
    if (iVar4 < iVar2 - param_3[2]) {
      FUN_10015a6e(&local_10);
    }
    else {
      if (iVar2 < iVar4) {
        if (*param_3 <= iVar4) {
          FUN_10015a6e(&local_10);
          local_10 = local_10 | 0x80000000;
          FUN_10015a95(&local_10,param_3[3]);
          iVar4 = param_3[5] + *param_3;
          uVar5 = 1;
          goto LAB_10015c50;
        }
        local_10 = local_10 & 0x7fffffff;
        iVar4 = param_3[5] + iVar4;
        FUN_10015a95(&local_10,param_3[3]);
        goto LAB_10015c4e;
      }
      FUN_10015a53((int)&local_10,local_1c);
      FUN_10015a95(&local_10,iVar2 - iVar4);
      FUN_100159c7((int)&local_10,param_3[2]);
      FUN_10015a95(&local_10,param_3[3] + 1);
    }
  }
  iVar4 = 0;
  uVar5 = 2;
LAB_10015c50:
  local_10 = iVar4 << (0x1fU - (char)param_3[3] & 0x1f) |
             -(uint)((uVar1 & 0x8000) != 0) & 0x80000000 | local_10;
  if (param_3[4] == 0x40) {
    param_2[1] = local_10;
    *param_2 = local_c;
  }
  else if (param_3[4] == 0x20) {
    *param_2 = local_10;
  }
  return uVar5;
}



/* ===== FUN_10015c8e @ 0x10015C8E ===== */

void __cdecl FUN_10015c8e(ushort *param_1,uint *param_2)

{
  FUN_10015b22(param_1,param_2,(int *)&DAT_10023590);
  return;
}



/* ===== FUN_10015ca4 @ 0x10015CA4 ===== */

void __cdecl FUN_10015ca4(ushort *param_1,uint *param_2)

{
  FUN_10015b22(param_1,param_2,(int *)&DAT_100235a8);
  return;
}



/* ===== FUN_10015cba @ 0x10015CBA ===== */

void __thiscall FUN_10015cba(void *this,uint *param_1,byte *param_2)

{
  ushort local_10 [6];
  
  FUN_10018bde(this,local_10,(int *)&param_2,param_2,0,0,0,0);
  FUN_10015c8e(local_10,param_1);
  return;
}



/* ===== FUN_10015ce7 @ 0x10015CE7 ===== */

void __thiscall FUN_10015ce7(void *this,uint *param_1,byte *param_2)

{
  ushort local_10 [6];
  
  FUN_10018bde(this,local_10,(int *)&param_2,param_2,0,0,0,0);
  FUN_10015ca4(local_10,param_1);
  return;
}



/* ===== FUN_10015d14 @ 0x10015D14 ===== */

void __cdecl FUN_10015d14(char *param_1,int param_2,int param_3)

{
  char *_Str;
  char *pcVar1;
  char *pcVar2;
  size_t sVar3;
  char *pcVar4;
  char cVar5;
  
  pcVar1 = param_1;
  pcVar4 = *(char **)(param_3 + 0xc);
  _Str = param_1 + 1;
  *param_1 = '0';
  pcVar2 = _Str;
  if (0 < param_2) {
    param_1 = (char *)param_2;
    param_2 = 0;
    do {
      cVar5 = *pcVar4;
      if (cVar5 == '\0') {
        cVar5 = '0';
      }
      else {
        pcVar4 = pcVar4 + 1;
      }
      *pcVar2 = cVar5;
      pcVar2 = pcVar2 + 1;
      param_1 = param_1 + -1;
    } while (param_1 != (char *)0x0);
  }
  *pcVar2 = '\0';
  if ((-1 < param_2) && ('4' < *pcVar4)) {
    while (pcVar2 = pcVar2 + -1, *pcVar2 == '9') {
      *pcVar2 = '0';
    }
    *pcVar2 = *pcVar2 + '\x01';
  }
  if (*pcVar1 == '1') {
    *(int *)(param_3 + 4) = *(int *)(param_3 + 4) + 1;
  }
  else {
    sVar3 = _strlen(_Str);
    FUN_10015f90((undefined4 *)pcVar1,(undefined4 *)_Str,sVar3 + 1);
  }
  return;
}



/* ===== FUN_10015d8b @ 0x10015D8B ===== */

int * __cdecl FUN_10015d8b(undefined4 param_1,undefined4 param_2,int *param_3,uint *param_4)

{
  int *piVar1;
  uint *puVar2;
  int iVar3;
  undefined4 in_stack_ffffffbc;
  undefined2 uVar4;
  short local_2c;
  char local_2a;
  uint local_28 [6];
  uint local_10;
  uint uStack_c;
  undefined2 uStack_8;
  
  uVar4 = (undefined2)((uint)in_stack_ffffffbc >> 0x10);
  FUN_10015de7(&local_10,&param_1);
  iVar3 = FUN_100190af(local_10,uStack_c,CONCAT22(uVar4,uStack_8),0x11,0,&local_2c);
  puVar2 = param_4;
  piVar1 = param_3;
  param_3[2] = iVar3;
  *param_3 = (int)local_2a;
  param_3[1] = (int)local_2c;
  FUN_10015ea0(param_4,local_28);
  piVar1[3] = (int)puVar2;
  return piVar1;
}



/* ===== FUN_10015de7 @ 0x10015DE7 ===== */

void __cdecl FUN_10015de7(uint *param_1,uint *param_2)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint local_8;
  
  uVar1 = *(ushort *)((int)param_2 + 6);
  uVar3 = (uVar1 & 0x7ff0) >> 4;
  uVar2 = *param_2;
  local_8 = 0x80000000;
  if (uVar3 == 0) {
    if (((param_2[1] & 0xfffff) == 0) && (uVar2 == 0)) {
      param_1[1] = 0;
      *param_1 = 0;
      *(undefined2 *)(param_1 + 2) = 0;
      return;
    }
    iVar4 = 0x3c01;
    local_8 = 0;
  }
  else if (uVar3 == 0x7ff) {
    iVar4 = 0x7fff;
  }
  else {
    iVar4 = uVar3 + 0x3c00;
  }
  local_8 = uVar2 >> 0x15 | (param_2[1] & 0xfffff) << 0xb | local_8;
  param_1[1] = local_8;
  *param_1 = uVar2 << 0xb;
  while ((local_8 & 0x80000000) == 0) {
    local_8 = *param_1 >> 0x1f | local_8 * 2;
    *param_1 = *param_1 * 2;
    param_1[1] = local_8;
    iVar4 = iVar4 + 0xffff;
  }
  *(ushort *)(param_1 + 2) = uVar1 & 0x8000 | (ushort)iVar4;
  return;
}



/* ===== FUN_10015ea0 @ 0x10015EA0 ===== */

uint * __cdecl FUN_10015ea0(uint *param_1,uint *param_2)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  
  puVar4 = param_1;
  while (((uint)param_2 & 3) != 0) {
    bVar1 = (byte)*param_2;
    uVar3 = (uint)bVar1;
    param_2 = (uint *)((int)param_2 + 1);
    if (bVar1 == 0) goto LAB_10015f88;
    *(byte *)puVar4 = bVar1;
    puVar4 = (uint *)((int)puVar4 + 1);
  }
  do {
    uVar2 = *param_2;
    uVar3 = *param_2;
    param_2 = param_2 + 1;
    if (((uVar2 ^ 0xffffffff ^ uVar2 + 0x7efefeff) & 0x81010100) != 0) {
      if ((char)uVar3 == '\0') {
LAB_10015f88:
        *(byte *)puVar4 = (byte)uVar3;
        return param_1;
      }
      if ((char)(uVar3 >> 8) == '\0') {
        *(short *)puVar4 = (short)uVar3;
        return param_1;
      }
      if ((uVar3 & 0xff0000) == 0) {
        *(short *)puVar4 = (short)uVar3;
        *(byte *)((int)puVar4 + 2) = 0;
        return param_1;
      }
      if ((uVar3 & 0xff000000) == 0) {
        *puVar4 = uVar3;
        return param_1;
      }
    }
    *puVar4 = uVar3;
    puVar4 = puVar4 + 1;
  } while( true );
}



/* ===== FUN_10015eb0 @ 0x10015EB0 ===== */

uint * __cdecl FUN_10015eb0(uint *param_1,uint *param_2)

{
  byte bVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  uint *puVar5;
  
  puVar3 = param_1;
  do {
    if (((uint)puVar3 & 3) == 0) goto LAB_10015ecc;
    uVar4 = *puVar3;
    puVar3 = (uint *)((int)puVar3 + 1);
  } while ((byte)uVar4 != 0);
  goto LAB_10015eff;
  while( true ) {
    if ((uVar4 & 0xff0000) == 0) {
      puVar5 = (uint *)((int)puVar5 + 2);
      goto joined_r0x10015f1b;
    }
    if ((uVar4 & 0xff000000) == 0) break;
LAB_10015ecc:
    do {
      puVar5 = puVar3;
      puVar3 = puVar5 + 1;
    } while (((*puVar5 ^ 0xffffffff ^ *puVar5 + 0x7efefeff) & 0x81010100) == 0);
    uVar4 = *puVar5;
    if ((char)uVar4 == '\0') goto joined_r0x10015f1b;
    if ((char)(uVar4 >> 8) == '\0') {
      puVar5 = (uint *)((int)puVar5 + 1);
      goto joined_r0x10015f1b;
    }
  }
LAB_10015eff:
  puVar5 = (uint *)((int)puVar3 + -1);
joined_r0x10015f1b:
  do {
    if (((uint)param_2 & 3) == 0) {
      do {
        uVar2 = *param_2;
        uVar4 = *param_2;
        param_2 = param_2 + 1;
        if (((uVar2 ^ 0xffffffff ^ uVar2 + 0x7efefeff) & 0x81010100) != 0) {
          if ((char)uVar4 == '\0') {
LAB_10015f88:
            *(byte *)puVar5 = (byte)uVar4;
            return param_1;
          }
          if ((char)(uVar4 >> 8) == '\0') {
            *(short *)puVar5 = (short)uVar4;
            return param_1;
          }
          if ((uVar4 & 0xff0000) == 0) {
            *(short *)puVar5 = (short)uVar4;
            *(byte *)((int)puVar5 + 2) = 0;
            return param_1;
          }
          if ((uVar4 & 0xff000000) == 0) {
            *puVar5 = uVar4;
            return param_1;
          }
        }
        *puVar5 = uVar4;
        puVar5 = puVar5 + 1;
      } while( true );
    }
    bVar1 = (byte)*param_2;
    uVar4 = (uint)bVar1;
    param_2 = (uint *)((int)param_2 + 1);
    if (bVar1 == 0) goto LAB_10015f88;
    *(byte *)puVar5 = bVar1;
    puVar5 = (uint *)((int)puVar5 + 1);
  } while( true );
}



/* ===== FUN_10015f90 @ 0x10015F90 ===== */

undefined4 * __cdecl FUN_10015f90(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  if ((param_2 < param_1) && (param_1 < (undefined4 *)(param_3 + (int)param_2))) {
    puVar3 = (undefined4 *)((param_3 - 4) + (int)param_2);
    puVar4 = (undefined4 *)((param_3 - 4) + (int)param_1);
    if (((uint)puVar4 & 3) == 0) {
      uVar1 = param_3 >> 2;
      uVar2 = param_3 & 3;
      if (7 < uVar1) {
        for (; uVar1 != 0; uVar1 = uVar1 - 1) {
          *puVar4 = *puVar3;
          puVar3 = puVar3 + -1;
          puVar4 = puVar4 + -1;
        }
        switch(uVar2) {
        case 0:
          return param_1;
        case 2:
          goto switchD_10016147_caseD_2;
        case 3:
          goto switchD_10016147_caseD_3;
        }
        goto switchD_10016147_caseD_1;
      }
    }
    else {
      switch(param_3) {
      case 0:
        goto switchD_10016147_caseD_0;
      case 1:
        goto switchD_10016147_caseD_1;
      case 2:
        goto switchD_10016147_caseD_2;
      case 3:
        goto switchD_10016147_caseD_3;
      default:
        uVar1 = param_3 - ((uint)puVar4 & 3);
        switch((uint)puVar4 & 3) {
        case 1:
          uVar2 = uVar1 & 3;
          *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
          puVar3 = (undefined4 *)((int)puVar3 + -1);
          uVar1 = uVar1 >> 2;
          puVar4 = (undefined4 *)((int)puVar4 - 1);
          if (7 < uVar1) {
            for (; uVar1 != 0; uVar1 = uVar1 - 1) {
              *puVar4 = *puVar3;
              puVar3 = puVar3 + -1;
              puVar4 = puVar4 + -1;
            }
            switch(uVar2) {
            case 0:
              return param_1;
            case 2:
              goto switchD_10016147_caseD_2;
            case 3:
              goto switchD_10016147_caseD_3;
            }
            goto switchD_10016147_caseD_1;
          }
          break;
        case 2:
          uVar2 = uVar1 & 3;
          *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
          uVar1 = uVar1 >> 2;
          *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
          puVar3 = (undefined4 *)((int)puVar3 + -2);
          puVar4 = (undefined4 *)((int)puVar4 - 2);
          if (7 < uVar1) {
            for (; uVar1 != 0; uVar1 = uVar1 - 1) {
              *puVar4 = *puVar3;
              puVar3 = puVar3 + -1;
              puVar4 = puVar4 + -1;
            }
            switch(uVar2) {
            case 0:
              return param_1;
            case 2:
              goto switchD_10016147_caseD_2;
            case 3:
              goto switchD_10016147_caseD_3;
            }
            goto switchD_10016147_caseD_1;
          }
          break;
        case 3:
          uVar2 = uVar1 & 3;
          *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
          *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
          uVar1 = uVar1 >> 2;
          *(undefined1 *)((int)puVar4 + 1) = *(undefined1 *)((int)puVar3 + 1);
          puVar3 = (undefined4 *)((int)puVar3 + -3);
          puVar4 = (undefined4 *)((int)puVar4 - 3);
          if (7 < uVar1) {
            for (; uVar1 != 0; uVar1 = uVar1 - 1) {
              *puVar4 = *puVar3;
              puVar3 = puVar3 + -1;
              puVar4 = puVar4 + -1;
            }
            switch(uVar2) {
            case 0:
              return param_1;
            case 2:
              goto switchD_10016147_caseD_2;
            case 3:
              goto switchD_10016147_caseD_3;
            }
            goto switchD_10016147_caseD_1;
          }
        }
      }
    }
    switch(uVar1) {
    case 7:
      puVar4[7 - uVar1] = puVar3[7 - uVar1];
    case 6:
      puVar4[6 - uVar1] = puVar3[6 - uVar1];
    case 5:
      puVar4[5 - uVar1] = puVar3[5 - uVar1];
    case 4:
      puVar4[4 - uVar1] = puVar3[4 - uVar1];
    case 3:
      puVar4[3 - uVar1] = puVar3[3 - uVar1];
    case 2:
      puVar4[2 - uVar1] = puVar3[2 - uVar1];
    case 1:
      puVar4[1 - uVar1] = puVar3[1 - uVar1];
      puVar3 = puVar3 + -uVar1;
      puVar4 = puVar4 + -uVar1;
    }
    switch(uVar2) {
    case 1:
switchD_10016147_caseD_1:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      return param_1;
    case 2:
switchD_10016147_caseD_2:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
      return param_1;
    case 3:
switchD_10016147_caseD_3:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
      *(undefined1 *)((int)puVar4 + 1) = *(undefined1 *)((int)puVar3 + 1);
      return param_1;
    }
switchD_10016147_caseD_0:
    return param_1;
  }
  puVar3 = param_1;
  if (((uint)param_1 & 3) == 0) {
    uVar1 = param_3 >> 2;
    uVar2 = param_3 & 3;
    if (7 < uVar1) {
      for (; uVar1 != 0; uVar1 = uVar1 - 1) {
        *puVar3 = *param_2;
        param_2 = param_2 + 1;
        puVar3 = puVar3 + 1;
      }
      switch(uVar2) {
      case 0:
        return param_1;
      case 2:
        goto switchD_10015fc5_caseD_2;
      case 3:
        goto switchD_10015fc5_caseD_3;
      }
      goto switchD_10015fc5_caseD_1;
    }
  }
  else {
    switch(param_3) {
    case 0:
      goto switchD_10015fc5_caseD_0;
    case 1:
      goto switchD_10015fc5_caseD_1;
    case 2:
      goto switchD_10015fc5_caseD_2;
    case 3:
      goto switchD_10015fc5_caseD_3;
    default:
      uVar1 = (param_3 - 4) + ((uint)param_1 & 3);
      switch((uint)param_1 & 3) {
      case 1:
        uVar2 = uVar1 & 3;
        *(undefined1 *)param_1 = *(undefined1 *)param_2;
        *(undefined1 *)((int)param_1 + 1) = *(undefined1 *)((int)param_2 + 1);
        uVar1 = uVar1 >> 2;
        *(undefined1 *)((int)param_1 + 2) = *(undefined1 *)((int)param_2 + 2);
        param_2 = (undefined4 *)((int)param_2 + 3);
        puVar3 = (undefined4 *)((int)param_1 + 3);
        if (7 < uVar1) {
          for (; uVar1 != 0; uVar1 = uVar1 - 1) {
            *puVar3 = *param_2;
            param_2 = param_2 + 1;
            puVar3 = puVar3 + 1;
          }
          switch(uVar2) {
          case 0:
            return param_1;
          case 2:
            goto switchD_10015fc5_caseD_2;
          case 3:
            goto switchD_10015fc5_caseD_3;
          }
          goto switchD_10015fc5_caseD_1;
        }
        break;
      case 2:
        uVar2 = uVar1 & 3;
        *(undefined1 *)param_1 = *(undefined1 *)param_2;
        uVar1 = uVar1 >> 2;
        *(undefined1 *)((int)param_1 + 1) = *(undefined1 *)((int)param_2 + 1);
        param_2 = (undefined4 *)((int)param_2 + 2);
        puVar3 = (undefined4 *)((int)param_1 + 2);
        if (7 < uVar1) {
          for (; uVar1 != 0; uVar1 = uVar1 - 1) {
            *puVar3 = *param_2;
            param_2 = param_2 + 1;
            puVar3 = puVar3 + 1;
          }
          switch(uVar2) {
          case 0:
            return param_1;
          case 2:
            goto switchD_10015fc5_caseD_2;
          case 3:
            goto switchD_10015fc5_caseD_3;
          }
          goto switchD_10015fc5_caseD_1;
        }
        break;
      case 3:
        uVar2 = uVar1 & 3;
        *(undefined1 *)param_1 = *(undefined1 *)param_2;
        param_2 = (undefined4 *)((int)param_2 + 1);
        uVar1 = uVar1 >> 2;
        puVar3 = (undefined4 *)((int)param_1 + 1);
        if (7 < uVar1) {
          for (; uVar1 != 0; uVar1 = uVar1 - 1) {
            *puVar3 = *param_2;
            param_2 = param_2 + 1;
            puVar3 = puVar3 + 1;
          }
          switch(uVar2) {
          case 0:
            return param_1;
          case 2:
            goto switchD_10015fc5_caseD_2;
          case 3:
            goto switchD_10015fc5_caseD_3;
          }
          goto switchD_10015fc5_caseD_1;
        }
      }
    }
  }
  switch(uVar1) {
  case 7:
    puVar3[uVar1 - 7] = param_2[uVar1 - 7];
  case 6:
    puVar3[uVar1 - 6] = param_2[uVar1 - 6];
  case 5:
    puVar3[uVar1 - 5] = param_2[uVar1 - 5];
  case 4:
    puVar3[uVar1 - 4] = param_2[uVar1 - 4];
  case 3:
    puVar3[uVar1 - 3] = param_2[uVar1 - 3];
  case 2:
    puVar3[uVar1 - 2] = param_2[uVar1 - 2];
  case 1:
    puVar3[uVar1 - 1] = param_2[uVar1 - 1];
    param_2 = param_2 + uVar1;
    puVar3 = puVar3 + uVar1;
  }
  switch(uVar2) {
  case 1:
switchD_10015fc5_caseD_1:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    return param_1;
  case 2:
switchD_10015fc5_caseD_2:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    *(undefined1 *)((int)puVar3 + 1) = *(undefined1 *)((int)param_2 + 1);
    return param_1;
  case 3:
switchD_10015fc5_caseD_3:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    *(undefined1 *)((int)puVar3 + 1) = *(undefined1 *)((int)param_2 + 1);
    *(undefined1 *)((int)puVar3 + 2) = *(undefined1 *)((int)param_2 + 2);
    return param_1;
  }
switchD_10015fc5_caseD_0:
  return param_1;
}



/* ===== __fptrap @ 0x100162C5 ===== */

/* Library Function - Single Match
    __fptrap
   
   Library: Visual Studio 2003 Release */

void __cdecl __fptrap(void)

{
  __amsg_exit(2);
  return;
}



/* ===== FUN_100162ce @ 0x100162CE ===== */

DWORD __cdecl FUN_100162ce(uint param_1,LONG param_2,DWORD param_3)

{
  DWORD DVar1;
  DWORD *pDVar2;
  
  if ((param_1 < DAT_10026bc0) &&
     ((*(byte *)((&DAT_10026ac0)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 1) != 0)) {
    FUN_10019403(param_1);
    DVar1 = FUN_10016333(param_1,param_2,param_3);
    FUN_10019462(param_1);
    return DVar1;
  }
  pDVar2 = FUN_100184a5();
  *pDVar2 = 9;
  pDVar2 = FUN_100184ae();
  *pDVar2 = 0;
  return 0xffffffff;
}



/* ===== FUN_10016333 @ 0x10016333 ===== */

DWORD __cdecl FUN_10016333(uint param_1,LONG param_2,DWORD param_3)

{
  byte *pbVar1;
  HANDLE hFile;
  DWORD *pDVar2;
  DWORD DVar3;
  uint uVar4;
  
  hFile = (HANDLE)FUN_100193c1(param_1);
  if (hFile == (HANDLE)0xffffffff) {
    pDVar2 = FUN_100184a5();
    *pDVar2 = 9;
  }
  else {
    DVar3 = SetFilePointer(hFile,param_2,(PLONG)0x0,param_3);
    if (DVar3 == 0xffffffff) {
      uVar4 = GetLastError();
    }
    else {
      uVar4 = 0;
    }
    if (uVar4 == 0) {
      pbVar1 = (byte *)((&DAT_10026ac0)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24);
      *pbVar1 = *pbVar1 & 0xfd;
      return DVar3;
    }
    FUN_10018432(uVar4);
  }
  return 0xffffffff;
}



/* ===== FUN_100163a6 @ 0x100163A6 ===== */

int __cdecl FUN_100163a6(uint param_1,char *param_2,uint param_3)

{
  int iVar1;
  DWORD *pDVar2;
  
  if ((param_1 < DAT_10026bc0) &&
     ((*(byte *)((&DAT_10026ac0)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 1) != 0)) {
    FUN_10019403(param_1);
    iVar1 = FUN_1001640b(param_1,param_2,param_3);
    FUN_10019462(param_1);
    return iVar1;
  }
  pDVar2 = FUN_100184a5();
  *pDVar2 = 9;
  pDVar2 = FUN_100184ae();
  *pDVar2 = 0;
  return -1;
}



/* ===== FUN_1001640b @ 0x1001640B ===== */

int __cdecl FUN_1001640b(DWORD param_1,char *param_2,uint param_3)

{
  int *piVar1;
  char *pcVar2;
  char cVar3;
  int iVar4;
  char *pcVar5;
  BOOL BVar6;
  DWORD *pDVar7;
  char local_418 [1028];
  int local_14;
  DWORD local_10;
  DWORD local_c;
  char *local_8;
  
  local_c = 0;
  local_14 = 0;
  if (param_3 == 0) {
LAB_10016424:
    iVar4 = 0;
  }
  else {
    piVar1 = &DAT_10026ac0 + ((int)param_1 >> 5);
    iVar4 = (param_1 & 0x1f) * 0x24;
    if ((*(byte *)(*piVar1 + 4 + iVar4) & 0x20) != 0) {
      FUN_10016333(param_1,0,2);
    }
    if ((*(byte *)((undefined4 *)(*piVar1 + iVar4) + 1) & 0x80) == 0) {
      BVar6 = WriteFile(*(HANDLE *)(*piVar1 + iVar4),param_2,param_3,&local_10,(LPOVERLAPPED)0x0);
      if (BVar6 == 0) {
        param_1 = GetLastError();
      }
      else {
        local_c = local_10;
        param_1 = 0;
      }
LAB_100164f3:
      if (local_c != 0) {
        return local_c - local_14;
      }
      if (param_1 == 0) goto LAB_10016565;
      if (param_1 == 5) {
        pDVar7 = FUN_100184a5();
        *pDVar7 = 9;
        pDVar7 = FUN_100184ae();
        *pDVar7 = 5;
      }
      else {
        FUN_10018432(param_1);
      }
    }
    else {
      local_8 = param_2;
      param_1 = 0;
      if (param_3 != 0) {
        do {
          pcVar5 = local_418;
          do {
            if (param_3 <= (uint)((int)local_8 - (int)param_2)) break;
            pcVar2 = local_8 + 1;
            cVar3 = *local_8;
            local_8 = pcVar2;
            if (cVar3 == '\n') {
              local_14 = local_14 + 1;
              *pcVar5 = '\r';
              pcVar5 = pcVar5 + 1;
            }
            *pcVar5 = cVar3;
            pcVar5 = pcVar5 + 1;
          } while ((int)pcVar5 - (int)local_418 < 0x400);
          BVar6 = WriteFile(*(HANDLE *)(*piVar1 + iVar4),local_418,(int)pcVar5 - (int)local_418,
                            &local_10,(LPOVERLAPPED)0x0);
          if (BVar6 == 0) {
            param_1 = GetLastError();
            goto LAB_100164f3;
          }
          local_c = local_c + local_10;
          if (((int)local_10 < (int)pcVar5 - (int)local_418) ||
             (param_3 <= (uint)((int)local_8 - (int)param_2))) goto LAB_100164f3;
        } while( true );
      }
LAB_10016565:
      if (((*(byte *)(*piVar1 + 4 + iVar4) & 0x40) != 0) && (*param_2 == '\x1a')) goto LAB_10016424;
      pDVar7 = FUN_100184a5();
      *pDVar7 = 0x1c;
      pDVar7 = FUN_100184ae();
      *pDVar7 = 0;
    }
    iVar4 = -1;
  }
  return iVar4;
}



/* ===== FUN_10016596 @ 0x10016596 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10016596(undefined4 *param_1)

{
  void *pvVar1;
  
  _DAT_100256b4 = _DAT_100256b4 + 1;
  pvVar1 = _malloc(0x1000);
  param_1[2] = pvVar1;
  if (pvVar1 == (void *)0x0) {
    param_1[3] = param_1[3] | 4;
    param_1[2] = param_1 + 5;
    param_1[6] = 2;
  }
  else {
    param_1[3] = param_1[3] | 8;
    param_1[6] = 0x1000;
  }
  param_1[1] = 0;
  *param_1 = param_1[2];
  return;
}



/* ===== FUN_100165da @ 0x100165DA ===== */

byte __cdecl FUN_100165da(uint param_1)

{
  if (DAT_10026bc0 <= param_1) {
    return 0;
  }
  return *(byte *)((&DAT_10026ac0)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 0x40;
}



/* ===== FUN_100166bf @ 0x100166BF ===== */

void __cdecl FUN_100166bf(uint param_1)

{
  if ((0x100235bf < param_1) && (param_1 < 0x10023821)) {
    FUN_10013262(((int)(param_1 + 0xeffdca40) >> 5) + 0x1c);
    return;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x20));
  return;
}



/* ===== FUN_100166ee @ 0x100166EE ===== */

void __cdecl FUN_100166ee(int param_1,int param_2)

{
  if (param_1 < 0x14) {
    FUN_10013262(param_1 + 0x1c);
    return;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)(param_2 + 0x20));
  return;
}



/* ===== FUN_10016711 @ 0x10016711 ===== */

void __cdecl FUN_10016711(uint param_1)

{
  if ((0x100235bf < param_1) && (param_1 < 0x10023821)) {
    FUN_100132c3(((int)(param_1 + 0xeffdca40) >> 5) + 0x1c);
    return;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x20));
  return;
}



/* ===== FUN_10016740 @ 0x10016740 ===== */

void __cdecl FUN_10016740(int param_1,int param_2)

{
  if (param_1 < 0x14) {
    FUN_100132c3(param_1 + 0x1c);
    return;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_2 + 0x20));
  return;
}



/* ===== FUN_10016763 @ 0x10016763 ===== */

int __cdecl FUN_10016763(LPSTR param_1,WCHAR param_2)

{
  int iVar1;
  bool bVar2;
  
  InterlockedIncrement((LONG *)&DAT_10025854);
  bVar2 = DAT_10025850 != 0;
  if (bVar2) {
    InterlockedDecrement((LONG *)&DAT_10025854);
    FUN_10013262(0x13);
  }
  iVar1 = FUN_100167bc(param_1,param_2);
  if (bVar2) {
    FUN_100132c3(0x13);
  }
  else {
    InterlockedDecrement((LONG *)&DAT_10025854);
  }
  return iVar1;
}



/* ===== FUN_100167bc @ 0x100167BC ===== */

int __cdecl FUN_100167bc(LPSTR param_1,WCHAR param_2)

{
  LPSTR lpMultiByteStr;
  int iVar1;
  DWORD *pDVar2;
  
  lpMultiByteStr = param_1;
  if (param_1 == (LPSTR)0x0) {
    return 0;
  }
  if (DAT_100256f8 == 0) {
    if ((ushort)param_2 < 0x100) {
      *param_1 = (CHAR)param_2;
      return 1;
    }
  }
  else {
    param_1 = (LPSTR)0x0;
    iVar1 = WideCharToMultiByte(DAT_10025708,0x220,&param_2,1,lpMultiByteStr,DAT_10023574,
                                (LPCSTR)0x0,(LPBOOL)&param_1);
    if ((iVar1 != 0) && (param_1 == (LPSTR)0x0)) {
      return iVar1;
    }
  }
  pDVar2 = FUN_100184a5();
  *pDVar2 = 0x2a;
  return -1;
}



/* ===== __aulldiv @ 0x10016830 ===== */

/* Library Function - Single Match
    __aulldiv
   
   Library: Visual Studio */

undefined8 __aulldiv(uint param_1,uint param_2,uint param_3,uint param_4)

{
  ulonglong uVar1;
  longlong lVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
  uVar3 = param_1;
  uVar8 = param_4;
  uVar6 = param_2;
  uVar9 = param_3;
  if (param_4 == 0) {
    uVar3 = param_2 / param_3;
    iVar4 = (int)(((ulonglong)param_2 % (ulonglong)param_3 << 0x20 | (ulonglong)param_1) /
                 (ulonglong)param_3);
  }
  else {
    do {
      uVar5 = uVar8 >> 1;
      uVar9 = uVar9 >> 1 | (uint)((uVar8 & 1) != 0) << 0x1f;
      uVar7 = uVar6 >> 1;
      uVar3 = uVar3 >> 1 | (uint)((uVar6 & 1) != 0) << 0x1f;
      uVar8 = uVar5;
      uVar6 = uVar7;
    } while (uVar5 != 0);
    uVar1 = CONCAT44(uVar7,uVar3) / (ulonglong)uVar9;
    iVar4 = (int)uVar1;
    lVar2 = (ulonglong)param_3 * (uVar1 & 0xffffffff);
    uVar3 = (uint)((ulonglong)lVar2 >> 0x20);
    uVar8 = uVar3 + iVar4 * param_4;
    if (((CARRY4(uVar3,iVar4 * param_4)) || (param_2 < uVar8)) ||
       ((param_2 <= uVar8 && (param_1 < (uint)lVar2)))) {
      iVar4 = iVar4 + -1;
    }
    uVar3 = 0;
  }
  return CONCAT44(uVar3,iVar4);
}



/* ===== __aullrem @ 0x100168A0 ===== */

/* Library Function - Single Match
    __aullrem
   
   Library: Visual Studio */

undefined8 __aullrem(uint param_1,uint param_2,uint param_3,uint param_4)

{
  ulonglong uVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  bool bVar11;
  
  uVar3 = param_1;
  uVar4 = param_4;
  uVar9 = param_2;
  uVar10 = param_3;
  if (param_4 == 0) {
    iVar6 = (int)(((ulonglong)param_2 % (ulonglong)param_3 << 0x20 | (ulonglong)param_1) %
                 (ulonglong)param_3);
    iVar7 = 0;
  }
  else {
    do {
      uVar5 = uVar4 >> 1;
      uVar10 = uVar10 >> 1 | (uint)((uVar4 & 1) != 0) << 0x1f;
      uVar8 = uVar9 >> 1;
      uVar3 = uVar3 >> 1 | (uint)((uVar9 & 1) != 0) << 0x1f;
      uVar4 = uVar5;
      uVar9 = uVar8;
    } while (uVar5 != 0);
    uVar1 = CONCAT44(uVar8,uVar3) / (ulonglong)uVar10;
    uVar3 = (int)uVar1 * param_4;
    lVar2 = (uVar1 & 0xffffffff) * (ulonglong)param_3;
    uVar9 = (uint)((ulonglong)lVar2 >> 0x20);
    uVar4 = (uint)lVar2;
    uVar10 = uVar9 + uVar3;
    if (((CARRY4(uVar9,uVar3)) || (param_2 < uVar10)) || ((param_2 <= uVar10 && (param_1 < uVar4))))
    {
      bVar11 = uVar4 < param_3;
      uVar4 = uVar4 - param_3;
      uVar10 = (uVar10 - param_4) - (uint)bVar11;
    }
    iVar6 = -(uVar4 - param_1);
    iVar7 = -(uint)(uVar4 - param_1 != 0) - ((uVar10 - param_2) - (uint)(uVar4 < param_1));
  }
  return CONCAT44(iVar7,iVar6);
}



/* ===== FUN_10016915 @ 0x10016915 ===== */

void __thiscall FUN_10016915(void *this,byte *param_1,int *param_2,void *param_3)

{
  FUN_1001692c(this,param_1,param_2,param_3,0);
  return;
}



/* ===== FUN_1001692c @ 0x1001692C ===== */

void * __thiscall FUN_1001692c(void *this,byte *param_1,int *param_2,void *param_3,uint param_4)

{
  byte *pbVar1;
  void *pvVar2;
  uint uVar3;
  void *pvVar4;
  uint uVar5;
  DWORD *pDVar6;
  void *this_00;
  byte bVar7;
  undefined *puVar8;
  void *local_c;
  byte *local_8;
  
  local_c = (void *)0x0;
  bVar7 = *param_1;
  pbVar1 = param_1;
  while( true ) {
    local_8 = pbVar1 + 1;
    if (DAT_10023574 < 2) {
      uVar3 = (byte)PTR_DAT_10023368[(uint)bVar7 * 2] & 8;
      this = PTR_DAT_10023368;
    }
    else {
      puVar8 = (undefined *)0x8;
      uVar3 = FUN_100154f0(this,(uint)bVar7,8);
      this = puVar8;
    }
    if (uVar3 == 0) break;
    bVar7 = *local_8;
    pbVar1 = local_8;
  }
  if (bVar7 == 0x2d) {
    param_4 = param_4 | 2;
LAB_10016987:
    bVar7 = *local_8;
    local_8 = pbVar1 + 2;
  }
  else if (bVar7 == 0x2b) goto LAB_10016987;
  if ((((int)param_3 < 0) || (param_3 == (void *)0x1)) || (0x24 < (int)param_3)) {
    if (param_2 != (int *)0x0) {
      *param_2 = (int)param_1;
    }
    return (void *)0x0;
  }
  this_00 = (void *)0x10;
  if (param_3 == (void *)0x0) {
    if (bVar7 != 0x30) {
      param_3 = (void *)0xa;
      goto LAB_100169f1;
    }
    if ((*local_8 != 0x78) && (*local_8 != 0x58)) {
      param_3 = (void *)0x8;
      goto LAB_100169f1;
    }
    param_3 = (void *)0x10;
  }
  if (((param_3 == (void *)0x10) && (bVar7 == 0x30)) && ((*local_8 == 0x78 || (*local_8 == 0x58))))
  {
    bVar7 = local_8[1];
    local_8 = local_8 + 2;
  }
LAB_100169f1:
  pvVar4 = (void *)(0xffffffff / ZEXT48(param_3));
  do {
    uVar3 = (uint)bVar7;
    if (DAT_10023574 < 2) {
      uVar5 = (byte)PTR_DAT_10023368[uVar3 * 2] & 4;
    }
    else {
      pvVar2 = (void *)0x4;
      uVar5 = FUN_100154f0(this_00,uVar3,4);
      this_00 = pvVar2;
    }
    if (uVar5 == 0) {
      if (DAT_10023574 < 2) {
        uVar3 = *(ushort *)(PTR_DAT_10023368 + uVar3 * 2) & 0x103;
      }
      else {
        uVar3 = FUN_100154f0(this_00,uVar3,0x103);
      }
      if (uVar3 == 0) {
LAB_10016a9d:
        local_8 = local_8 + -1;
        if ((param_4 & 8) == 0) {
          if (param_2 != (int *)0x0) {
            local_8 = param_1;
          }
          local_c = (void *)0x0;
        }
        else if (((param_4 & 4) != 0) ||
                (((param_4 & 1) == 0 &&
                 ((((param_4 & 2) != 0 && ((void *)0x80000000 < local_c)) ||
                  (((param_4 & 2) == 0 && ((void *)0x7fffffff < local_c)))))))) {
          pDVar6 = FUN_100184a5();
          *pDVar6 = 0x22;
          if ((param_4 & 1) == 0) {
            local_c = (void *)(((param_4 & 2) != 0) + 0x7fffffff);
          }
          else {
            local_c = (void *)0xffffffff;
          }
        }
        if (param_2 != (int *)0x0) {
          *param_2 = (int)local_8;
        }
        if ((param_4 & 2) == 0) {
          return local_c;
        }
        return (void *)-(int)local_c;
      }
      uVar3 = FUN_1001963c((int)(char)bVar7);
      this_00 = (void *)(uVar3 - 0x37);
    }
    else {
      this_00 = (void *)((char)bVar7 + -0x30);
    }
    if (param_3 <= this_00) goto LAB_10016a9d;
    if ((local_c < pvVar4) ||
       ((local_c == pvVar4 && (this_00 <= (void *)(0xffffffff % ZEXT48(param_3)))))) {
      local_c = (void *)((int)local_c * (int)param_3 + (int)this_00);
      param_4 = param_4 | 8;
    }
    else {
      param_4 = param_4 | 0xc;
    }
    bVar7 = *local_8;
    local_8 = local_8 + 1;
  } while( true );
}



/* ===== _strchr @ 0x10016B50 ===== */

/* Library Function - Single Match
    _strchr
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

char * __cdecl _strchr(char *_Str,int _Val)

{
  uint uVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  
  while (((uint)_Str & 3) != 0) {
    uVar1 = *(uint *)_Str;
    if ((char)uVar1 == (char)_Val) {
      return (char *)(uint *)_Str;
    }
    _Str = (char *)((int)_Str + 1);
    if ((char)uVar1 == '\0') {
      return (char *)0x0;
    }
  }
  while( true ) {
    while( true ) {
      uVar1 = *(uint *)_Str;
      uVar4 = uVar1 ^ CONCAT22(CONCAT11((char)_Val,(char)_Val),CONCAT11((char)_Val,(char)_Val));
      uVar3 = uVar1 ^ 0xffffffff ^ uVar1 + 0x7efefeff;
      puVar5 = (uint *)((int)_Str + 4);
      if (((uVar4 ^ 0xffffffff ^ uVar4 + 0x7efefeff) & 0x81010100) != 0) break;
      _Str = (char *)puVar5;
      if ((uVar3 & 0x81010100) != 0) {
        if ((uVar3 & 0x1010100) != 0) {
          return (char *)0x0;
        }
        if ((uVar1 + 0x7efefeff & 0x80000000) == 0) {
          return (char *)0x0;
        }
      }
    }
    uVar1 = *(uint *)_Str;
    if ((char)uVar1 == (char)_Val) {
      return (char *)(uint *)_Str;
    }
    if ((char)uVar1 == '\0') {
      return (char *)0x0;
    }
    cVar2 = (char)(uVar1 >> 8);
    if (cVar2 == (char)_Val) {
      return (char *)((int)_Str + 1);
    }
    if (cVar2 == '\0') {
      return (char *)0x0;
    }
    cVar2 = (char)(uVar1 >> 0x10);
    if (cVar2 == (char)_Val) {
      return (char *)((int)_Str + 2);
    }
    if (cVar2 == '\0') break;
    cVar2 = (char)(uVar1 >> 0x18);
    if (cVar2 == (char)_Val) {
      return (char *)((int)_Str + 3);
    }
    _Str = (char *)puVar5;
    if (cVar2 == '\0') {
      return (char *)0x0;
    }
  }
  return (char *)0x0;
}



/* ===== _strstr @ 0x10016C10 ===== */

/* Library Function - Single Match
    _strstr
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

char * __cdecl _strstr(char *_Str,char *_SubStr)

{
  char *pcVar1;
  char *pcVar2;
  char cVar3;
  uint uVar4;
  char cVar5;
  uint uVar6;
  uint uVar7;
  char *pcVar8;
  uint *puVar9;
  char *pcVar10;
  
  cVar3 = *_SubStr;
  if (cVar3 == '\0') {
    return _Str;
  }
  if (_SubStr[1] == '\0') {
    while (((uint)_Str & 3) != 0) {
      uVar4 = *(uint *)_Str;
      if ((char)uVar4 == cVar3) {
        return (char *)(uint *)_Str;
      }
      _Str = (char *)((int)_Str + 1);
      if ((char)uVar4 == '\0') {
        return (char *)0x0;
      }
    }
    while( true ) {
      while( true ) {
        uVar4 = *(uint *)_Str;
        uVar7 = uVar4 ^ CONCAT22(CONCAT11(cVar3,cVar3),CONCAT11(cVar3,cVar3));
        uVar6 = uVar4 ^ 0xffffffff ^ uVar4 + 0x7efefeff;
        puVar9 = (uint *)((int)_Str + 4);
        if (((uVar7 ^ 0xffffffff ^ uVar7 + 0x7efefeff) & 0x81010100) != 0) break;
        _Str = (char *)puVar9;
        if ((uVar6 & 0x81010100) != 0) {
          if ((uVar6 & 0x1010100) != 0) {
            return (char *)0x0;
          }
          if ((uVar4 + 0x7efefeff & 0x80000000) == 0) {
            return (char *)0x0;
          }
        }
      }
      uVar4 = *(uint *)_Str;
      if ((char)uVar4 == cVar3) {
        return (char *)(uint *)_Str;
      }
      if ((char)uVar4 == '\0') {
        return (char *)0x0;
      }
      cVar5 = (char)(uVar4 >> 8);
      if (cVar5 == cVar3) {
        return (char *)((int)_Str + 1);
      }
      if (cVar5 == '\0') {
        return (char *)0x0;
      }
      cVar5 = (char)(uVar4 >> 0x10);
      if (cVar5 == cVar3) {
        return (char *)((int)_Str + 2);
      }
      if (cVar5 == '\0') break;
      cVar5 = (char)(uVar4 >> 0x18);
      if (cVar5 == cVar3) {
        return (char *)((int)_Str + 3);
      }
      _Str = (char *)puVar9;
      if (cVar5 == '\0') {
        return (char *)0x0;
      }
    }
    return (char *)0x0;
  }
  do {
    cVar5 = *_Str;
    do {
      while (_Str = _Str + 1, cVar5 != cVar3) {
        if (cVar5 == '\0') {
          return (char *)0x0;
        }
        cVar5 = *_Str;
      }
      cVar5 = *_Str;
      pcVar10 = _Str + 1;
      pcVar8 = _SubStr;
    } while (cVar5 != _SubStr[1]);
    do {
      if (pcVar8[2] == '\0') {
LAB_10016c83:
        return _Str + -1;
      }
      if (*pcVar10 != pcVar8[2]) break;
      pcVar1 = pcVar8 + 3;
      if (*pcVar1 == '\0') goto LAB_10016c83;
      pcVar2 = pcVar10 + 1;
      pcVar8 = pcVar8 + 2;
      pcVar10 = pcVar10 + 2;
    } while (*pcVar1 == *pcVar2);
  } while( true );
}



/* ===== _strncmp @ 0x10016C90 ===== */

/* Library Function - Single Match
    _strncmp
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

int __cdecl _strncmp(char *_Str1,char *_Str2,size_t _MaxCount)

{
  char cVar1;
  char cVar2;
  size_t sVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  char *pcVar7;
  
  uVar5 = 0;
  sVar3 = _MaxCount;
  pcVar6 = _Str1;
  if (_MaxCount != 0) {
    do {
      if (sVar3 == 0) break;
      sVar3 = sVar3 - 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    iVar4 = _MaxCount - sVar3;
    do {
      pcVar6 = _Str2;
      pcVar7 = _Str1;
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      pcVar7 = _Str1 + 1;
      pcVar6 = _Str2 + 1;
      cVar2 = *_Str1;
      cVar1 = *_Str2;
      _Str2 = pcVar6;
      _Str1 = pcVar7;
    } while (cVar1 == cVar2);
    uVar5 = 0;
    if ((byte)pcVar6[-1] <= (byte)pcVar7[-1]) {
      if (pcVar6[-1] == pcVar7[-1]) {
        return 0;
      }
      uVar5 = 0xfffffffe;
    }
    uVar5 = ~uVar5;
  }
  return uVar5;
}



/* ===== FUN_10017a5b @ 0x10017A5B ===== */

void __cdecl FUN_10017a5b(uint param_1,int *param_2,ushort *param_3)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  uint uVar3;
  uint local_5c [10];
  undefined8 local_34;
  uint local_24;
  
  param_3 = (ushort *)(uint)*param_3;
  iVar2 = *param_2;
  if (iVar2 == 1) {
LAB_10017aa0:
    uVar3 = 8;
  }
  else if (iVar2 == 2) {
    uVar3 = 4;
  }
  else if (iVar2 == 3) {
    uVar3 = 0x11;
  }
  else if (iVar2 == 4) {
    uVar3 = 0x12;
  }
  else {
    if (iVar2 == 5) goto LAB_10017aa0;
    if (iVar2 == 7) {
      *param_2 = 1;
      goto LAB_10017af6;
    }
    if (iVar2 != 8) goto LAB_10017af6;
    uVar3 = 0x10;
  }
  bVar1 = FUN_100151a4(uVar3,(double *)(param_2 + 6),(uint)param_3);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    if (((param_1 == 0x10) || (param_1 == 0x16)) || (param_1 == 0x1d)) {
      local_34 = *(undefined8 *)(param_2 + 4);
      local_24 = local_24 & 0xffffffe3 | 3;
    }
    else {
      local_24 = local_24 & 0xfffffffe;
    }
    FUN_10014ef1(local_5c,(uint *)&param_3,uVar3,param_1,(undefined8 *)(param_2 + 2),
                 (undefined8 *)(param_2 + 6));
  }
LAB_10017af6:
  FUN_10015400();
  if (((*param_2 != 8) && (DAT_10023c90 == 0)) && (iVar2 = FUN_100184b7(), iVar2 != 0)) {
    return;
  }
  FUN_100153bb(*param_2);
  return;
}



/* ===== FUN_10017b2b @ 0x10017B2B ===== */

int FUN_10017b2b(int *param_1)

{
  int *piVar1;
  bool bVar2;
  int iVar3;
  undefined3 extraout_var;
  
  piVar1 = (int *)*param_1;
  if (((*piVar1 == -0x1f928c9d) && (piVar1[4] == 3)) && (piVar1[5] == 0x19930520)) {
    iVar3 = FUN_1001451c();
    return iVar3;
  }
  if ((DAT_100256b8 != (FARPROC)0x0) &&
     (bVar2 = FUN_10017bc7(DAT_100256b8), CONCAT31(extraout_var,bVar2) != 0)) {
    iVar3 = (*DAT_100256b8)(param_1);
    return iVar3;
  }
  return 0;
}



/* ===== FUN_10017b8f @ 0x10017B8F ===== */

bool __cdecl FUN_10017b8f(void *param_1,UINT_PTR param_2)

{
  BOOL BVar1;
  
  BVar1 = IsBadReadPtr(param_1,param_2);
  return BVar1 == 0;
}



/* ===== FUN_10017bab @ 0x10017BAB ===== */

bool __cdecl FUN_10017bab(LPVOID param_1,UINT_PTR param_2)

{
  BOOL BVar1;
  
  BVar1 = IsBadWritePtr(param_1,param_2);
  return BVar1 == 0;
}



/* ===== FUN_10017bc7 @ 0x10017BC7 ===== */

bool __cdecl FUN_10017bc7(FARPROC param_1)

{
  BOOL BVar1;
  
  BVar1 = IsBadCodePtr(param_1);
  return BVar1 == 0;
}



/* ===== _strcmp @ 0x10017BE0 ===== */

/* Library Function - Single Match
    _strcmp
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

int __cdecl _strcmp(char *_Str1,char *_Str2)

{
  undefined2 uVar1;
  undefined4 uVar2;
  byte bVar3;
  byte bVar4;
  bool bVar5;
  
  if (((uint)_Str1 & 3) != 0) {
    if (((uint)_Str1 & 1) != 0) {
      bVar4 = *_Str1;
      _Str1 = _Str1 + 1;
      bVar5 = bVar4 < (byte)*_Str2;
      if (bVar4 != *_Str2) goto LAB_10017c24;
      _Str2 = _Str2 + 1;
      if (bVar4 == 0) {
        return 0;
      }
      if (((uint)_Str1 & 2) == 0) goto LAB_10017bf0;
    }
    uVar1 = *(undefined2 *)_Str1;
    _Str1 = _Str1 + 2;
    bVar4 = (byte)uVar1;
    bVar5 = bVar4 < (byte)*_Str2;
    if (bVar4 != *_Str2) goto LAB_10017c24;
    if (bVar4 == 0) {
      return 0;
    }
    bVar4 = (byte)((ushort)uVar1 >> 8);
    bVar5 = bVar4 < (byte)_Str2[1];
    if (bVar4 != _Str2[1]) goto LAB_10017c24;
    if (bVar4 == 0) {
      return 0;
    }
    _Str2 = _Str2 + 2;
  }
LAB_10017bf0:
  while( true ) {
    uVar2 = *(undefined4 *)_Str1;
    bVar4 = (byte)uVar2;
    bVar5 = bVar4 < (byte)*_Str2;
    if (bVar4 != *_Str2) break;
    if (bVar4 == 0) {
      return 0;
    }
    bVar4 = (byte)((uint)uVar2 >> 8);
    bVar5 = bVar4 < (byte)_Str2[1];
    if (bVar4 != _Str2[1]) break;
    if (bVar4 == 0) {
      return 0;
    }
    bVar4 = (byte)((uint)uVar2 >> 0x10);
    bVar5 = bVar4 < (byte)_Str2[2];
    if (bVar4 != _Str2[2]) break;
    bVar3 = (byte)((uint)uVar2 >> 0x18);
    if (bVar4 == 0) {
      return 0;
    }
    bVar5 = bVar3 < (byte)_Str2[3];
    if (bVar3 != _Str2[3]) break;
    _Str2 = _Str2 + 4;
    _Str1 = _Str1 + 4;
    if (bVar3 == 0) {
      return 0;
    }
  }
LAB_10017c24:
  return (uint)bVar5 * -2 + 1;
}



/* ===== FUN_10017c64 @ 0x10017C64 ===== */

void FUN_10017c64(void)

{
  FUN_10014c5a(10);
  FUN_1001862f((DWORD *)0x16);
                    /* WARNING: Subroutine does not return */
  __exit(3);
}



/* ===== FUN_10017c80 @ 0x10017C80 ===== */

undefined4 * __cdecl FUN_10017c80(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  if ((param_2 < param_1) && (param_1 < (undefined4 *)(param_3 + (int)param_2))) {
    puVar3 = (undefined4 *)((param_3 - 4) + (int)param_2);
    puVar4 = (undefined4 *)((param_3 - 4) + (int)param_1);
    if (((uint)puVar4 & 3) == 0) {
      uVar1 = param_3 >> 2;
      uVar2 = param_3 & 3;
      if (7 < uVar1) {
        for (; uVar1 != 0; uVar1 = uVar1 - 1) {
          *puVar4 = *puVar3;
          puVar3 = puVar3 + -1;
          puVar4 = puVar4 + -1;
        }
        switch(uVar2) {
        case 0:
          return param_1;
        case 2:
          goto switchD_10017e37_caseD_2;
        case 3:
          goto switchD_10017e37_caseD_3;
        }
        goto switchD_10017e37_caseD_1;
      }
    }
    else {
      switch(param_3) {
      case 0:
        goto switchD_10017e37_caseD_0;
      case 1:
        goto switchD_10017e37_caseD_1;
      case 2:
        goto switchD_10017e37_caseD_2;
      case 3:
        goto switchD_10017e37_caseD_3;
      default:
        uVar1 = param_3 - ((uint)puVar4 & 3);
        switch((uint)puVar4 & 3) {
        case 1:
          uVar2 = uVar1 & 3;
          *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
          puVar3 = (undefined4 *)((int)puVar3 + -1);
          uVar1 = uVar1 >> 2;
          puVar4 = (undefined4 *)((int)puVar4 - 1);
          if (7 < uVar1) {
            for (; uVar1 != 0; uVar1 = uVar1 - 1) {
              *puVar4 = *puVar3;
              puVar3 = puVar3 + -1;
              puVar4 = puVar4 + -1;
            }
            switch(uVar2) {
            case 0:
              return param_1;
            case 2:
              goto switchD_10017e37_caseD_2;
            case 3:
              goto switchD_10017e37_caseD_3;
            }
            goto switchD_10017e37_caseD_1;
          }
          break;
        case 2:
          uVar2 = uVar1 & 3;
          *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
          uVar1 = uVar1 >> 2;
          *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
          puVar3 = (undefined4 *)((int)puVar3 + -2);
          puVar4 = (undefined4 *)((int)puVar4 - 2);
          if (7 < uVar1) {
            for (; uVar1 != 0; uVar1 = uVar1 - 1) {
              *puVar4 = *puVar3;
              puVar3 = puVar3 + -1;
              puVar4 = puVar4 + -1;
            }
            switch(uVar2) {
            case 0:
              return param_1;
            case 2:
              goto switchD_10017e37_caseD_2;
            case 3:
              goto switchD_10017e37_caseD_3;
            }
            goto switchD_10017e37_caseD_1;
          }
          break;
        case 3:
          uVar2 = uVar1 & 3;
          *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
          *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
          uVar1 = uVar1 >> 2;
          *(undefined1 *)((int)puVar4 + 1) = *(undefined1 *)((int)puVar3 + 1);
          puVar3 = (undefined4 *)((int)puVar3 + -3);
          puVar4 = (undefined4 *)((int)puVar4 - 3);
          if (7 < uVar1) {
            for (; uVar1 != 0; uVar1 = uVar1 - 1) {
              *puVar4 = *puVar3;
              puVar3 = puVar3 + -1;
              puVar4 = puVar4 + -1;
            }
            switch(uVar2) {
            case 0:
              return param_1;
            case 2:
              goto switchD_10017e37_caseD_2;
            case 3:
              goto switchD_10017e37_caseD_3;
            }
            goto switchD_10017e37_caseD_1;
          }
        }
      }
    }
    switch(uVar1) {
    case 7:
      puVar4[7 - uVar1] = puVar3[7 - uVar1];
    case 6:
      puVar4[6 - uVar1] = puVar3[6 - uVar1];
    case 5:
      puVar4[5 - uVar1] = puVar3[5 - uVar1];
    case 4:
      puVar4[4 - uVar1] = puVar3[4 - uVar1];
    case 3:
      puVar4[3 - uVar1] = puVar3[3 - uVar1];
    case 2:
      puVar4[2 - uVar1] = puVar3[2 - uVar1];
    case 1:
      puVar4[1 - uVar1] = puVar3[1 - uVar1];
      puVar3 = puVar3 + -uVar1;
      puVar4 = puVar4 + -uVar1;
    }
    switch(uVar2) {
    case 1:
switchD_10017e37_caseD_1:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      return param_1;
    case 2:
switchD_10017e37_caseD_2:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
      return param_1;
    case 3:
switchD_10017e37_caseD_3:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
      *(undefined1 *)((int)puVar4 + 1) = *(undefined1 *)((int)puVar3 + 1);
      return param_1;
    }
switchD_10017e37_caseD_0:
    return param_1;
  }
  puVar3 = param_1;
  if (((uint)param_1 & 3) == 0) {
    uVar1 = param_3 >> 2;
    uVar2 = param_3 & 3;
    if (7 < uVar1) {
      for (; uVar1 != 0; uVar1 = uVar1 - 1) {
        *puVar3 = *param_2;
        param_2 = param_2 + 1;
        puVar3 = puVar3 + 1;
      }
      switch(uVar2) {
      case 0:
        return param_1;
      case 2:
        goto switchD_10017cb5_caseD_2;
      case 3:
        goto switchD_10017cb5_caseD_3;
      }
      goto switchD_10017cb5_caseD_1;
    }
  }
  else {
    switch(param_3) {
    case 0:
      goto switchD_10017cb5_caseD_0;
    case 1:
      goto switchD_10017cb5_caseD_1;
    case 2:
      goto switchD_10017cb5_caseD_2;
    case 3:
      goto switchD_10017cb5_caseD_3;
    default:
      uVar1 = (param_3 - 4) + ((uint)param_1 & 3);
      switch((uint)param_1 & 3) {
      case 1:
        uVar2 = uVar1 & 3;
        *(undefined1 *)param_1 = *(undefined1 *)param_2;
        *(undefined1 *)((int)param_1 + 1) = *(undefined1 *)((int)param_2 + 1);
        uVar1 = uVar1 >> 2;
        *(undefined1 *)((int)param_1 + 2) = *(undefined1 *)((int)param_2 + 2);
        param_2 = (undefined4 *)((int)param_2 + 3);
        puVar3 = (undefined4 *)((int)param_1 + 3);
        if (7 < uVar1) {
          for (; uVar1 != 0; uVar1 = uVar1 - 1) {
            *puVar3 = *param_2;
            param_2 = param_2 + 1;
            puVar3 = puVar3 + 1;
          }
          switch(uVar2) {
          case 0:
            return param_1;
          case 2:
            goto switchD_10017cb5_caseD_2;
          case 3:
            goto switchD_10017cb5_caseD_3;
          }
          goto switchD_10017cb5_caseD_1;
        }
        break;
      case 2:
        uVar2 = uVar1 & 3;
        *(undefined1 *)param_1 = *(undefined1 *)param_2;
        uVar1 = uVar1 >> 2;
        *(undefined1 *)((int)param_1 + 1) = *(undefined1 *)((int)param_2 + 1);
        param_2 = (undefined4 *)((int)param_2 + 2);
        puVar3 = (undefined4 *)((int)param_1 + 2);
        if (7 < uVar1) {
          for (; uVar1 != 0; uVar1 = uVar1 - 1) {
            *puVar3 = *param_2;
            param_2 = param_2 + 1;
            puVar3 = puVar3 + 1;
          }
          switch(uVar2) {
          case 0:
            return param_1;
          case 2:
            goto switchD_10017cb5_caseD_2;
          case 3:
            goto switchD_10017cb5_caseD_3;
          }
          goto switchD_10017cb5_caseD_1;
        }
        break;
      case 3:
        uVar2 = uVar1 & 3;
        *(undefined1 *)param_1 = *(undefined1 *)param_2;
        param_2 = (undefined4 *)((int)param_2 + 1);
        uVar1 = uVar1 >> 2;
        puVar3 = (undefined4 *)((int)param_1 + 1);
        if (7 < uVar1) {
          for (; uVar1 != 0; uVar1 = uVar1 - 1) {
            *puVar3 = *param_2;
            param_2 = param_2 + 1;
            puVar3 = puVar3 + 1;
          }
          switch(uVar2) {
          case 0:
            return param_1;
          case 2:
            goto switchD_10017cb5_caseD_2;
          case 3:
            goto switchD_10017cb5_caseD_3;
          }
          goto switchD_10017cb5_caseD_1;
        }
      }
    }
  }
  switch(uVar1) {
  case 7:
    puVar3[uVar1 - 7] = param_2[uVar1 - 7];
  case 6:
    puVar3[uVar1 - 6] = param_2[uVar1 - 6];
  case 5:
    puVar3[uVar1 - 5] = param_2[uVar1 - 5];
  case 4:
    puVar3[uVar1 - 4] = param_2[uVar1 - 4];
  case 3:
    puVar3[uVar1 - 3] = param_2[uVar1 - 3];
  case 2:
    puVar3[uVar1 - 2] = param_2[uVar1 - 2];
  case 1:
    puVar3[uVar1 - 1] = param_2[uVar1 - 1];
    param_2 = param_2 + uVar1;
    puVar3 = puVar3 + uVar1;
  }
  switch(uVar2) {
  case 1:
switchD_10017cb5_caseD_1:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    return param_1;
  case 2:
switchD_10017cb5_caseD_2:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    *(undefined1 *)((int)puVar3 + 1) = *(undefined1 *)((int)param_2 + 1);
    return param_1;
  case 3:
switchD_10017cb5_caseD_3:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    *(undefined1 *)((int)puVar3 + 1) = *(undefined1 *)((int)param_2 + 1);
    *(undefined1 *)((int)puVar3 + 2) = *(undefined1 *)((int)param_2 + 2);
    return param_1;
  }
switchD_10017cb5_caseD_0:
  return param_1;
}



/* ===== FUN_10017fb5 @ 0x10017FB5 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_10017fb5(int param_1)

{
  BYTE *pBVar1;
  byte *pbVar2;
  byte bVar3;
  byte bVar4;
  UINT CodePage;
  UINT *pUVar5;
  BOOL BVar6;
  uint uVar7;
  uint uVar8;
  BYTE *pBVar9;
  int iVar10;
  byte *pbVar11;
  int iVar12;
  byte *pbVar13;
  undefined4 uVar14;
  undefined4 *puVar15;
  _cpinfo local_1c;
  uint local_8;
  
  FUN_10013262(0x19);
  CodePage = FUN_10018162(param_1);
  if (CodePage != DAT_10025858) {
    if (CodePage != 0) {
      iVar12 = 0;
      pUVar5 = &DAT_10023a38;
LAB_10017ff2:
      if (*pUVar5 != CodePage) goto code_r0x10017ff6;
      local_8 = 0;
      puVar15 = &DAT_10025980;
      for (iVar10 = 0x40; iVar10 != 0; iVar10 = iVar10 + -1) {
        *puVar15 = 0;
        puVar15 = puVar15 + 1;
      }
      iVar12 = iVar12 * 0x30;
      *(undefined1 *)puVar15 = 0;
      pbVar13 = (byte *)(iVar12 + 0x10023a48);
      do {
        bVar3 = *pbVar13;
        pbVar11 = pbVar13;
        while ((bVar3 != 0 && (bVar3 = pbVar11[1], bVar3 != 0))) {
          uVar8 = (uint)*pbVar11;
          if (uVar8 <= bVar3) {
            bVar4 = (&DAT_10023a30)[local_8];
            do {
              pbVar2 = (byte *)((int)&DAT_10025980 + uVar8 + 1);
              *pbVar2 = *pbVar2 | bVar4;
              uVar8 = uVar8 + 1;
            } while (uVar8 <= bVar3);
          }
          pbVar11 = pbVar11 + 2;
          bVar3 = *pbVar11;
        }
        local_8 = local_8 + 1;
        pbVar13 = pbVar13 + 8;
      } while (local_8 < 4);
      _DAT_1002586c = 1;
      DAT_10025858 = CodePage;
      DAT_10025a84 = FUN_100181ac(CodePage);
      DAT_10025860 = *(undefined4 *)(iVar12 + 0x10023a3c);
      DAT_10025864 = *(undefined4 *)(iVar12 + 0x10023a40);
      DAT_10025868 = *(undefined4 *)(iVar12 + 0x10023a44);
      goto LAB_10018146;
    }
    goto LAB_10018141;
  }
  goto LAB_10017fdc;
code_r0x10017ff6:
  pUVar5 = pUVar5 + 0xc;
  iVar12 = iVar12 + 1;
  if ((UINT *)0x10023b27 < pUVar5) goto code_r0x10018001;
  goto LAB_10017ff2;
code_r0x10018001:
  BVar6 = GetCPInfo(CodePage,&local_1c);
  uVar8 = 1;
  if (BVar6 == 1) {
    DAT_10025a84 = 0;
    puVar15 = &DAT_10025980;
    for (iVar12 = 0x40; iVar12 != 0; iVar12 = iVar12 + -1) {
      *puVar15 = 0;
      puVar15 = puVar15 + 1;
    }
    *(undefined1 *)puVar15 = 0;
    if (local_1c.MaxCharSize < 2) {
      _DAT_1002586c = 0;
      DAT_10025858 = CodePage;
    }
    else {
      DAT_10025858 = CodePage;
      if (local_1c.LeadByte[0] != '\0') {
        pBVar9 = local_1c.LeadByte + 1;
        do {
          bVar3 = *pBVar9;
          if (bVar3 == 0) break;
          for (uVar7 = (uint)pBVar9[-1]; uVar7 <= bVar3; uVar7 = uVar7 + 1) {
            pbVar13 = (byte *)((int)&DAT_10025980 + uVar7 + 1);
            *pbVar13 = *pbVar13 | 4;
          }
          pBVar1 = pBVar9 + 1;
          pBVar9 = pBVar9 + 2;
        } while (*pBVar1 != 0);
      }
      do {
        pbVar13 = (byte *)((int)&DAT_10025980 + uVar8 + 1);
        *pbVar13 = *pbVar13 | 8;
        uVar8 = uVar8 + 1;
      } while (uVar8 < 0xff);
      DAT_10025a84 = FUN_100181ac(CodePage);
      _DAT_1002586c = 1;
    }
    DAT_10025860 = 0;
    DAT_10025864 = 0;
    DAT_10025868 = 0;
  }
  else {
    if (DAT_100256bc == 0) {
      uVar14 = 0xffffffff;
      goto LAB_10018153;
    }
LAB_10018141:
    FUN_100181df();
  }
LAB_10018146:
  FUN_10018208();
LAB_10017fdc:
  uVar14 = 0;
LAB_10018153:
  FUN_100132c3(0x19);
  return uVar14;
}



/* ===== FUN_10018162 @ 0x10018162 ===== */

int __cdecl FUN_10018162(int param_1)

{
  int iVar1;
  bool bVar2;
  
  if (param_1 == -2) {
    DAT_100256bc = 1;
                    /* WARNING: Could not recover jumptable at 0x1001817c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = GetOEMCP();
    return iVar1;
  }
  if (param_1 == -3) {
    DAT_100256bc = 1;
                    /* WARNING: Could not recover jumptable at 0x10018191. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = GetACP();
    return iVar1;
  }
  bVar2 = param_1 == -4;
  if (bVar2) {
    param_1 = DAT_10025708;
  }
  DAT_100256bc = (uint)bVar2;
  return param_1;
}



/* ===== FUN_100181ac @ 0x100181AC ===== */

undefined4 __cdecl FUN_100181ac(int param_1)

{
  if (param_1 == 0x3a4) {
    return 0x411;
  }
  if (param_1 == 0x3a8) {
    return 0x804;
  }
  if (param_1 == 0x3b5) {
    return 0x412;
  }
  if (param_1 != 0x3b6) {
    return 0;
  }
  return 0x404;
}



/* ===== FUN_100181df @ 0x100181DF ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100181df(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = &DAT_10025980;
  for (iVar1 = 0x40; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined1 *)puVar2 = 0;
  DAT_10025858 = 0;
  _DAT_1002586c = 0;
  DAT_10025a84 = 0;
  DAT_10025860 = 0;
  DAT_10025864 = 0;
  DAT_10025868 = 0;
  return;
}



/* ===== FUN_10018208 @ 0x10018208 ===== */

void FUN_10018208(void)

{
  byte *pbVar1;
  BOOL BVar2;
  uint uVar3;
  char cVar4;
  uint uVar5;
  uint uVar6;
  ushort *puVar7;
  undefined1 uVar8;
  BYTE *pBVar9;
  CHAR *pCVar10;
  WORD local_518 [256];
  WCHAR local_318 [128];
  WCHAR local_218 [128];
  CHAR local_118 [256];
  _cpinfo local_18;
  
  BVar2 = GetCPInfo(DAT_10025858,&local_18);
  if (BVar2 == 1) {
    uVar3 = 0;
    do {
      local_118[uVar3] = (CHAR)uVar3;
      uVar3 = uVar3 + 1;
    } while (uVar3 < 0x100);
    local_118[0] = ' ';
    if (local_18.LeadByte[0] != 0) {
      pBVar9 = local_18.LeadByte + 1;
      do {
        uVar3 = (uint)local_18.LeadByte[0];
        if (uVar3 <= *pBVar9) {
          uVar5 = (*pBVar9 - uVar3) + 1;
          uVar6 = uVar5 >> 2;
          pCVar10 = local_118 + uVar3;
          while (uVar6 != 0) {
            uVar6 = uVar6 - 1;
            builtin_memcpy(pCVar10,"    ",4);
            pCVar10 = pCVar10 + 4;
          }
          for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
            *pCVar10 = ' ';
            pCVar10 = pCVar10 + 1;
          }
        }
        local_18.LeadByte[0] = pBVar9[1];
        pBVar9 = pBVar9 + 2;
      } while (local_18.LeadByte[0] != 0);
    }
    FUN_100184ba(1,local_118,0x100,local_518,DAT_10025858,DAT_10025a84,0);
    FUN_100187ee(DAT_10025a84,0x100,local_118,0x100,local_218,0x100,DAT_10025858,0);
    FUN_100187ee(DAT_10025a84,0x200,local_118,0x100,local_318,0x100,DAT_10025858,0);
    uVar3 = 0;
    puVar7 = local_518;
    do {
      if ((*puVar7 & 1) == 0) {
        if ((*puVar7 & 2) != 0) {
          pbVar1 = (byte *)((int)&DAT_10025980 + uVar3 + 1);
          *pbVar1 = *pbVar1 | 0x20;
          uVar8 = *(undefined1 *)((int)local_318 + uVar3);
          goto LAB_10018314;
        }
        (&DAT_10025880)[uVar3] = 0;
      }
      else {
        pbVar1 = (byte *)((int)&DAT_10025980 + uVar3 + 1);
        *pbVar1 = *pbVar1 | 0x10;
        uVar8 = *(undefined1 *)((int)local_218 + uVar3);
LAB_10018314:
        (&DAT_10025880)[uVar3] = uVar8;
      }
      uVar3 = uVar3 + 1;
      puVar7 = puVar7 + 1;
    } while (uVar3 < 0x100);
  }
  else {
    uVar3 = 0;
    do {
      if ((uVar3 < 0x41) || (0x5a < uVar3)) {
        if ((0x60 < uVar3) && (uVar3 < 0x7b)) {
          pbVar1 = (byte *)((int)&DAT_10025980 + uVar3 + 1);
          *pbVar1 = *pbVar1 | 0x20;
          cVar4 = (char)uVar3 + -0x20;
          goto LAB_1001835e;
        }
        (&DAT_10025880)[uVar3] = 0;
      }
      else {
        pbVar1 = (byte *)((int)&DAT_10025980 + uVar3 + 1);
        *pbVar1 = *pbVar1 | 0x10;
        cVar4 = (char)uVar3 + ' ';
LAB_1001835e:
        (&DAT_10025880)[uVar3] = cVar4;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < 0x100);
  }
  return;
}



/* ===== FUN_1001838d @ 0x1001838D ===== */

void FUN_1001838d(void)

{
  if (DAT_10026bec == 0) {
    FUN_10017fb5(-3);
    DAT_10026bec = 1;
  }
  return;
}



/* ===== FUN_100183a9 @ 0x100183A9 ===== */

int __cdecl FUN_100183a9(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  HMODULE hModule;
  int iVar1;
  
  iVar1 = 0;
  if (DAT_100256c0 == (FARPROC)0x0) {
    hModule = LoadLibraryA("user32.dll");
    if (hModule != (HMODULE)0x0) {
      DAT_100256c0 = GetProcAddress(hModule,"MessageBoxA");
      if (DAT_100256c0 != (FARPROC)0x0) {
        DAT_100256c4 = GetProcAddress(hModule,"GetActiveWindow");
        DAT_100256c8 = GetProcAddress(hModule,"GetLastActivePopup");
        goto LAB_100183f8;
      }
    }
    iVar1 = 0;
  }
  else {
LAB_100183f8:
    if (DAT_100256c4 != (FARPROC)0x0) {
      iVar1 = (*DAT_100256c4)();
      if ((iVar1 != 0) && (DAT_100256c8 != (FARPROC)0x0)) {
        iVar1 = (*DAT_100256c8)(iVar1);
      }
    }
    iVar1 = (*DAT_100256c0)(iVar1,param_1,param_2,param_3);
  }
  return iVar1;
}



/* ===== FUN_10018432 @ 0x10018432 ===== */

void __cdecl FUN_10018432(uint param_1)

{
  DWORD *pDVar1;
  uint *puVar2;
  int iVar3;
  
  pDVar1 = FUN_100184ae();
  iVar3 = 0;
  *pDVar1 = param_1;
  puVar2 = &DAT_10023b28;
  do {
    if (param_1 == *puVar2) {
      pDVar1 = FUN_100184a5();
      *pDVar1 = *(DWORD *)(iVar3 * 8 + 0x10023b2c);
      return;
    }
    puVar2 = puVar2 + 2;
    iVar3 = iVar3 + 1;
  } while (puVar2 < &DAT_10023c90);
  if ((0x12 < param_1) && (param_1 < 0x25)) {
    pDVar1 = FUN_100184a5();
    *pDVar1 = 0xd;
    return;
  }
  if ((0xbb < param_1) && (param_1 < 0xcb)) {
    pDVar1 = FUN_100184a5();
    *pDVar1 = 8;
    return;
  }
  pDVar1 = FUN_100184a5();
  *pDVar1 = 0x16;
  return;
}



/* ===== FUN_100184a5 @ 0x100184A5 ===== */

DWORD * FUN_100184a5(void)

{
  DWORD *pDVar1;
  
  pDVar1 = FUN_1001343d();
  return pDVar1 + 2;
}



/* ===== FUN_100184ae @ 0x100184AE ===== */

DWORD * FUN_100184ae(void)

{
  DWORD *pDVar1;
  
  pDVar1 = FUN_1001343d();
  return pDVar1 + 3;
}



/* ===== FUN_100184b7 @ 0x100184B7 ===== */

undefined4 FUN_100184b7(void)

{
  return 0;
}



/* ===== FUN_100184ba @ 0x100184BA ===== */

BOOL __cdecl
FUN_100184ba(DWORD param_1,LPCSTR param_2,int param_3,LPWORD param_4,UINT param_5,LCID param_6,
            int param_7)

{
  undefined1 *puVar1;
  BOOL BVar2;
  int iVar3;
  WORD local_20 [2];
  undefined1 *local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &DAT_1001c9c0;
  puStack_10 = &LAB_100132e0;
  local_14 = ExceptionList;
  local_1c = &stack0xffffffc8;
  iVar3 = DAT_100256cc;
  ExceptionList = &local_14;
  puVar1 = &stack0xffffffc8;
  if (DAT_100256cc == 0) {
    ExceptionList = &local_14;
    BVar2 = GetStringTypeW(1,L"",1,local_20);
    iVar3 = 1;
    puVar1 = local_1c;
    if (BVar2 == 0) {
      BVar2 = GetStringTypeA(0,1,"",1,local_20);
      if (BVar2 == 0) {
        ExceptionList = local_14;
        return 0;
      }
      iVar3 = 2;
      puVar1 = local_1c;
    }
  }
  local_1c = puVar1;
  DAT_100256cc = iVar3;
  if (DAT_100256cc != 2) {
    if (DAT_100256cc == 1) {
      if (param_5 == 0) {
        param_5 = DAT_10025708;
      }
      iVar3 = MultiByteToWideChar(param_5,(-(uint)(param_7 != 0) & 8) + 1,param_2,param_3,
                                  (LPWSTR)0x0,0);
      if (iVar3 != 0) {
        local_8 = 0;
        FUN_10010f60();
        local_1c = &stack0xffffffc8;
        _memset(&stack0xffffffc8,0,iVar3 * 2);
        local_8 = 0xffffffff;
        if ((&stack0x00000000 != (undefined1 *)0x38) &&
           (iVar3 = MultiByteToWideChar(param_5,1,param_2,param_3,(LPWSTR)&stack0xffffffc8,iVar3),
           iVar3 != 0)) {
          BVar2 = GetStringTypeW(param_1,(LPCWSTR)&stack0xffffffc8,iVar3,param_4);
          ExceptionList = local_14;
          return BVar2;
        }
      }
    }
    ExceptionList = local_14;
    return 0;
  }
  if (param_6 == 0) {
    param_6 = DAT_100256f8;
  }
  BVar2 = GetStringTypeA(param_6,param_1,param_2,param_3,param_4);
  ExceptionList = local_14;
  return BVar2;
}



/* ===== FUN_1001862f @ 0x1001862F ===== */

undefined4 __cdecl FUN_1001862f(DWORD *param_1)

{
  bool bVar1;
  DWORD *pDVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  code *pcVar6;
  undefined4 *puVar7;
  DWORD local_10;
  DWORD local_c;
  
  bVar1 = false;
  if (param_1 == (DWORD *)0x2) {
    puVar7 = &DAT_100256d0;
    pcVar6 = DAT_100256d0;
LAB_100186b5:
    bVar1 = true;
    FUN_10013262(1);
    pDVar2 = param_1;
  }
  else {
    if (((param_1 != (DWORD *)0x4) && (param_1 != (DWORD *)0x8)) && (param_1 != (DWORD *)0xb)) {
      if (param_1 == (DWORD *)0xf) {
        puVar7 = &DAT_100256dc;
        pcVar6 = DAT_100256dc;
      }
      else if (param_1 == (DWORD *)0x15) {
        puVar7 = &DAT_100256d4;
        pcVar6 = DAT_100256d4;
      }
      else {
        if (param_1 != (DWORD *)0x16) {
          return 0xffffffff;
        }
        puVar7 = &DAT_100256d8;
        pcVar6 = DAT_100256d8;
      }
      goto LAB_100186b5;
    }
    pDVar2 = FUN_1001343d();
    uVar3 = FUN_100187b1((int)param_1,pDVar2[0x14]);
    puVar7 = (undefined4 *)(uVar3 + 8);
    pcVar6 = (code *)*puVar7;
  }
  if (pcVar6 == (code *)0x1) {
    if (!bVar1) {
      return 0;
    }
    FUN_100132c3(1);
    return 0;
  }
  if (pcVar6 == (code *)0x0) {
    if (bVar1) {
      FUN_100132c3(1);
    }
                    /* WARNING: Subroutine does not return */
    __exit(3);
  }
  if (((param_1 == (DWORD *)0x8) || (param_1 == (DWORD *)0xb)) || (param_1 == (DWORD *)0x4)) {
    local_c = pDVar2[0x15];
    pDVar2[0x15] = 0;
    if (param_1 == (DWORD *)0x8) {
      local_10 = pDVar2[0x16];
      pDVar2[0x16] = 0x8c;
      goto LAB_10018729;
    }
  }
  else {
LAB_10018729:
    if (param_1 == (DWORD *)0x8) {
      if (DAT_100238b8 < DAT_100238bc + DAT_100238b8) {
        iVar4 = DAT_100238b8 * 0xc;
        iVar5 = DAT_100238b8;
        do {
          iVar4 = iVar4 + 0xc;
          *(undefined4 *)((pDVar2[0x14] - 4) + iVar4) = 0;
          iVar5 = iVar5 + 1;
        } while (iVar5 < DAT_100238bc + DAT_100238b8);
      }
      goto LAB_10018767;
    }
  }
  *puVar7 = 0;
LAB_10018767:
  if (bVar1) {
    FUN_100132c3(1);
  }
  if (param_1 == (DWORD *)0x8) {
    (*pcVar6)(8,pDVar2[0x16]);
  }
  else {
    (*pcVar6)(param_1);
    if ((param_1 != (DWORD *)0xb) && (param_1 != (DWORD *)0x4)) {
      return 0;
    }
  }
  pDVar2[0x15] = local_c;
  if (param_1 == (DWORD *)0x8) {
    pDVar2[0x16] = local_10;
  }
  return 0;
}



/* ===== FUN_100187b1 @ 0x100187B1 ===== */

uint __cdecl FUN_100187b1(int param_1,uint param_2)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = param_2;
  if (*(int *)(param_2 + 4) != param_1) {
    uVar3 = param_2;
    do {
      uVar2 = uVar3 + 0xc;
      if (param_2 + DAT_100238c4 * 0xc <= uVar2) break;
      piVar1 = (int *)(uVar3 + 0x10);
      uVar3 = uVar2;
    } while (*piVar1 != param_1);
  }
  if ((param_2 + DAT_100238c4 * 0xc <= uVar2) || (*(int *)(uVar2 + 4) != param_1)) {
    uVar2 = 0;
  }
  return uVar2;
}



/* ===== FUN_100187ee @ 0x100187EE ===== */

int __cdecl
FUN_100187ee(LCID param_1,uint param_2,char *param_3,int param_4,LPWSTR param_5,int param_6,
            UINT param_7,int param_8)

{
  int iVar1;
  int iVar2;
  void *local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &DAT_1001c9d0;
  puStack_10 = &LAB_100132e0;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if (DAT_10025710 == 0) {
    ExceptionList = &local_14;
    iVar1 = LCMapStringW(0,0x100,L"",1,(LPWSTR)0x0,0);
    if (iVar1 == 0) {
      iVar1 = LCMapStringA(0,0x100,"",1,(LPSTR)0x0,0);
      if (iVar1 == 0) {
        ExceptionList = local_14;
        return 0;
      }
      DAT_10025710 = 2;
    }
    else {
      DAT_10025710 = 1;
    }
  }
  if (0 < param_4) {
    param_4 = FUN_10018a12(param_3,param_4);
  }
  if (DAT_10025710 == 2) {
    iVar1 = LCMapStringA(param_1,param_2,param_3,param_4,(LPSTR)param_5,param_6);
    ExceptionList = local_14;
    return iVar1;
  }
  if (DAT_10025710 == 1) {
    if (param_7 == 0) {
      param_7 = DAT_10025708;
    }
    iVar1 = MultiByteToWideChar(param_7,(-(uint)(param_8 != 0) & 8) + 1,param_3,param_4,(LPWSTR)0x0,
                                0);
    if (iVar1 != 0) {
      local_8 = 0;
      FUN_10010f60();
      local_8 = 0xffffffff;
      if ((&stack0x00000000 != (undefined1 *)0x3c) &&
         (iVar2 = MultiByteToWideChar(param_7,1,param_3,param_4,(LPWSTR)&stack0xffffffc4,iVar1),
         iVar2 != 0)) {
        iVar2 = LCMapStringW(param_1,param_2,(LPCWSTR)&stack0xffffffc4,iVar1,(LPWSTR)0x0,0);
        if (iVar2 != 0) {
          if ((param_2 & 0x400) == 0) {
            local_8 = 1;
            FUN_10010f60();
            local_8 = 0xffffffff;
            if (&stack0x00000000 == (undefined1 *)0x3c) {
              ExceptionList = local_14;
              return 0;
            }
            iVar1 = LCMapStringW(param_1,param_2,(LPCWSTR)&stack0xffffffc4,iVar1,
                                 (LPWSTR)&stack0xffffffc4,iVar2);
            if (iVar1 == 0) {
              ExceptionList = local_14;
              return 0;
            }
            if (param_6 == 0) {
              param_6 = 0;
              param_5 = (LPWSTR)0x0;
            }
            iVar2 = WideCharToMultiByte(param_7,0x220,(LPCWSTR)&stack0xffffffc4,iVar2,(LPSTR)param_5
                                        ,param_6,(LPCSTR)0x0,(LPBOOL)0x0);
            iVar1 = iVar2;
          }
          else {
            if (param_6 == 0) {
              ExceptionList = local_14;
              return iVar2;
            }
            if (param_6 < iVar2) {
              ExceptionList = local_14;
              return 0;
            }
            iVar1 = LCMapStringW(param_1,param_2,(LPCWSTR)&stack0xffffffc4,iVar1,param_5,param_6);
          }
          if (iVar1 != 0) {
            ExceptionList = local_14;
            return iVar2;
          }
        }
      }
    }
  }
  ExceptionList = local_14;
  return 0;
}



/* ===== FUN_10018a12 @ 0x10018A12 ===== */

int __cdecl FUN_10018a12(char *param_1,int param_2)

{
  char *pcVar1;
  int iVar2;
  
  iVar2 = param_2;
  for (pcVar1 = param_1; (iVar2 != 0 && (iVar2 = iVar2 + -1, *pcVar1 != '\0')); pcVar1 = pcVar1 + 1)
  {
  }
  if (*pcVar1 != '\0') {
    return param_2;
  }
  return (int)pcVar1 - (int)param_1;
}



/* ===== FUN_10018a3d @ 0x10018A3D ===== */

undefined4 __cdecl FUN_10018a3d(uint param_1,uint param_2,uint *param_3)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  uVar1 = param_1 + param_2;
  if ((uVar1 < param_1) || (uVar1 < param_2)) {
    uVar2 = 1;
  }
  *param_3 = uVar1;
  return uVar2;
}



/* ===== ___add_12 @ 0x10018A5E ===== */

/* Library Function - Single Match
    ___add_12
   
   Library: Visual Studio 2003 Release */

void __cdecl ___add_12(uint *param_1,uint *param_2)

{
  int iVar1;
  
  iVar1 = FUN_10018a3d(*param_1,*param_2,param_1);
  if (iVar1 != 0) {
    iVar1 = FUN_10018a3d(param_1[1],1,param_1 + 1);
    if (iVar1 != 0) {
      param_1[2] = param_1[2] + 1;
    }
  }
  iVar1 = FUN_10018a3d(param_1[1],param_2[1],param_1 + 1);
  if (iVar1 != 0) {
    param_1[2] = param_1[2] + 1;
  }
  FUN_10018a3d(param_1[2],param_2[2],param_1 + 2);
  return;
}



/* ===== FUN_10018abc @ 0x10018ABC ===== */

void __cdecl FUN_10018abc(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = *param_1;
  uVar2 = param_1[1];
  *param_1 = uVar1 * 2;
  param_1[1] = uVar2 * 2 | uVar1 >> 0x1f;
  param_1[2] = param_1[2] << 1 | uVar2 >> 0x1f;
  return;
}



/* ===== FUN_10018aea @ 0x10018AEA ===== */

void __cdecl FUN_10018aea(uint *param_1)

{
  uint uVar1;
  
  uVar1 = param_1[1];
  param_1[1] = uVar1 >> 1 | param_1[2] << 0x1f;
  param_1[2] = param_1[2] >> 1;
  *param_1 = *param_1 >> 1 | uVar1 << 0x1f;
  return;
}



/* ===== FUN_10018b17 @ 0x10018B17 ===== */

void __cdecl FUN_10018b17(char *param_1,int param_2,uint *param_3)

{
  uint *puVar1;
  uint local_14;
  uint local_10;
  uint local_c;
  int local_8;
  
  puVar1 = param_3;
  local_8 = 0x404e;
  *param_3 = 0;
  param_3[1] = 0;
  param_3[2] = 0;
  if (param_2 != 0) {
    param_3 = (uint *)param_2;
    do {
      local_14 = *puVar1;
      local_10 = puVar1[1];
      local_c = puVar1[2];
      FUN_10018abc(puVar1);
      FUN_10018abc(puVar1);
      ___add_12(puVar1,&local_14);
      FUN_10018abc(puVar1);
      local_10 = 0;
      local_c = 0;
      local_14 = (uint)*param_1;
      ___add_12(puVar1,&local_14);
      param_1 = param_1 + 1;
      param_3 = (uint *)((int)param_3 + -1);
    } while (param_3 != (uint *)0x0);
  }
  while (puVar1[2] == 0) {
    puVar1[2] = puVar1[1] >> 0x10;
    local_8 = local_8 + 0xfff0;
    puVar1[1] = *puVar1 >> 0x10 | puVar1[1] << 0x10;
    *puVar1 = *puVar1 << 0x10;
  }
  while ((puVar1[2] & 0x8000) == 0) {
    FUN_10018abc(puVar1);
    local_8 = local_8 + 0xffff;
  }
  *(undefined2 *)((int)puVar1 + 10) = (undefined2)local_8;
  return;
}



/* ===== FUN_10018bde @ 0x10018BDE ===== */

undefined4 __thiscall
FUN_10018bde(void *this,ushort *param_1,int *param_2,byte *param_3,int param_4,int param_5,
            int param_6,int param_7)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  int iVar5;
  byte bVar6;
  byte *pbVar7;
  byte *pbVar8;
  int iVar9;
  byte *pbVar10;
  char local_60 [23];
  char local_49;
  ushort local_44;
  undefined2 uStack_42;
  undefined2 uStack_40;
  byte *local_3e;
  ushort local_3a;
  int local_34;
  int local_30;
  undefined4 local_2c;
  int local_28;
  int local_24;
  byte *local_20;
  int local_1c;
  undefined4 local_18;
  int local_14;
  char *local_10;
  int local_c;
  uint local_8;
  
  local_10 = local_60;
  local_2c = 0;
  local_1c = 1;
  local_8 = 0;
  local_14 = 0;
  local_28 = 0;
  local_24 = 0;
  local_30 = 0;
  local_34 = 0;
  local_20 = (byte *)0x0;
  local_c = 0;
  local_18 = 0;
  pbVar8 = param_3;
  while( true ) {
    bVar6 = *pbVar8;
    this = (void *)CONCAT31((int3)((uint)this >> 8),bVar6);
    if ((((bVar6 != 0x20) && (bVar6 != 9)) && (bVar6 != 10)) && (bVar6 != 0xd)) break;
    pbVar8 = pbVar8 + 1;
  }
  iVar1 = 4;
  iVar9 = 0;
  iVar5 = local_14;
LAB_10018c35:
  local_14 = iVar5;
  pbVar7 = pbVar8;
  iVar5 = 1;
  bVar6 = *pbVar7;
  pbVar8 = pbVar7 + 1;
  iVar2 = local_14;
  switch(iVar9) {
  case 0:
    if (('0' < (char)bVar6) && ((char)bVar6 < ':')) {
LAB_10018c52:
      local_14 = iVar2;
      iVar9 = 3;
      goto LAB_10018e77;
    }
    if (bVar6 == DAT_10023578) goto LAB_10018c61;
    if (bVar6 == 0x2b) {
      local_2c = 0;
      iVar9 = 2;
      iVar5 = local_14;
    }
    else if (bVar6 == 0x2d) {
      local_2c = 0x8000;
      iVar9 = 2;
      iVar5 = local_14;
    }
    else {
      iVar9 = iVar5;
      iVar5 = local_14;
      if (bVar6 != 0x30) goto LAB_10018f51;
    }
    goto LAB_10018c35;
  case 1:
    local_14 = 1;
    if (('0' < (char)bVar6) && (iVar2 = iVar5, (char)bVar6 < ':')) goto LAB_10018c52;
    iVar9 = iVar1;
    if (bVar6 != DAT_10023578) {
      iVar9 = iVar5;
      if ((bVar6 == 0x2b) || (iVar9 = local_14, bVar6 == 0x2d)) goto LAB_10018ce6;
      iVar9 = iVar5;
      local_14 = iVar5;
      if (bVar6 != 0x30) goto LAB_10018cbf;
    }
    goto LAB_10018c35;
  case 2:
    if (('0' < (char)bVar6) && ((char)bVar6 < ':')) goto LAB_10018c52;
    if (bVar6 == DAT_10023578) {
LAB_10018c61:
      iVar9 = 5;
      iVar5 = local_14;
    }
    else {
      iVar9 = iVar5;
      pbVar7 = param_3;
      iVar5 = local_14;
      if (bVar6 != 0x30) goto LAB_10018f56;
    }
    goto LAB_10018c35;
  case 3:
    local_14 = iVar5;
    while( true ) {
      if (DAT_10023574 < 2) {
        uVar3 = (byte)PTR_DAT_10023368[(uint)bVar6 * 2] & 4;
        this = PTR_DAT_10023368;
      }
      else {
        pbVar7 = (byte *)0x4;
        uVar3 = FUN_100154f0(this,(uint)bVar6,4);
        this = pbVar7;
      }
      if (uVar3 == 0) break;
      if (local_8 < 0x19) {
        local_8 = local_8 + 1;
        pcVar4 = local_10 + 1;
        *local_10 = bVar6 - 0x30;
        local_10 = pcVar4;
      }
      else {
        local_c = local_c + 1;
      }
      bVar6 = *pbVar8;
      pbVar8 = pbVar8 + 1;
    }
    iVar9 = iVar1;
    iVar5 = local_14;
    if (bVar6 != DAT_10023578) goto LAB_10018dd3;
    goto LAB_10018c35;
  case 4:
    local_14 = 1;
    local_28 = 1;
    iVar9 = iVar5;
    if (local_8 == 0) {
      while (iVar5 = local_28, iVar9 = local_14, bVar6 == 0x30) {
        local_c = local_c + -1;
        bVar6 = *pbVar8;
        pbVar8 = pbVar8 + 1;
      }
    }
    while( true ) {
      local_14 = iVar9;
      local_28 = iVar5;
      if (DAT_10023574 < 2) {
        uVar3 = (byte)PTR_DAT_10023368[(uint)bVar6 * 2] & 4;
        this = PTR_DAT_10023368;
      }
      else {
        pbVar7 = (byte *)0x4;
        uVar3 = FUN_100154f0(this,(uint)bVar6,4);
        this = pbVar7;
      }
      if (uVar3 == 0) break;
      if (local_8 < 0x19) {
        local_8 = local_8 + 1;
        local_c = local_c + -1;
        pcVar4 = local_10 + 1;
        *local_10 = bVar6 - 0x30;
        local_10 = pcVar4;
      }
      bVar6 = *pbVar8;
      pbVar8 = pbVar8 + 1;
      iVar5 = local_28;
      iVar9 = local_14;
    }
LAB_10018dd3:
    iVar9 = local_14;
    if ((bVar6 == 0x2b) || (bVar6 == 0x2d)) {
LAB_10018ce6:
      local_14 = iVar9;
      iVar9 = 0xb;
      pbVar8 = pbVar8 + -1;
      iVar5 = local_14;
    }
    else {
LAB_10018cbf:
      if (((char)bVar6 < 'D') ||
         (('E' < (char)bVar6 && (((char)bVar6 < 'd' || ('e' < (char)bVar6)))))) goto LAB_10018f51;
      iVar9 = 6;
      iVar5 = local_14;
    }
    goto LAB_10018c35;
  case 5:
    local_28 = iVar5;
    if (DAT_10023574 < 2) {
      uVar3 = (byte)PTR_DAT_10023368[(uint)bVar6 * 2] & 4;
      this = PTR_DAT_10023368;
    }
    else {
      pbVar7 = (byte *)0x4;
      uVar3 = FUN_100154f0(this,(uint)bVar6,4);
      this = pbVar7;
    }
    iVar9 = iVar1;
    pbVar7 = param_3;
    if (uVar3 != 0) goto LAB_10018e77;
    goto LAB_10018f56;
  case 6:
    pbVar7 = pbVar7 + -1;
    this = pbVar7;
    param_3 = pbVar7;
    if (((char)bVar6 < '1') || ('9' < (char)bVar6)) {
      if (bVar6 == 0x2b) goto LAB_10018eac;
      if (bVar6 == 0x2d) goto LAB_10018ea0;
      if (bVar6 != 0x30) goto LAB_10018f56;
LAB_10018e45:
      iVar9 = 8;
      iVar5 = local_14;
      goto LAB_10018c35;
    }
    break;
  case 7:
    if (((char)bVar6 < '1') || ('9' < (char)bVar6)) {
      pbVar7 = param_3;
      if (bVar6 == 0x30) goto LAB_10018e45;
      goto LAB_10018f56;
    }
    break;
  case 8:
    local_24 = 1;
    while (bVar6 == 0x30) {
      bVar6 = *pbVar8;
      pbVar8 = pbVar8 + 1;
    }
    if (((char)bVar6 < '1') || ('9' < (char)bVar6)) goto LAB_10018f51;
    break;
  case 9:
    local_24 = 1;
    pbVar7 = (byte *)0x0;
    goto LAB_10018ed7;
  default:
    goto switchD_10018c41_caseD_a;
  case 0xb:
    if (param_7 != 0) {
      if (bVar6 == 0x2b) {
LAB_10018eac:
        iVar9 = 7;
        this = pbVar7;
        param_3 = pbVar7;
        iVar5 = local_14;
      }
      else {
        param_3 = pbVar7;
        if (bVar6 != 0x2d) goto LAB_10018f56;
LAB_10018ea0:
        local_1c = -1;
        iVar9 = 7;
        this = pbVar7;
        param_3 = pbVar7;
        iVar5 = local_14;
      }
      goto LAB_10018c35;
    }
    iVar9 = 10;
    pbVar8 = pbVar7;
switchD_10018c41_caseD_a:
    pbVar7 = pbVar8;
    iVar5 = local_14;
    if (iVar9 != 10) goto LAB_10018c35;
    goto LAB_10018f56;
  }
  iVar9 = 9;
LAB_10018e77:
  pbVar8 = pbVar8 + -1;
  iVar5 = local_14;
  goto LAB_10018c35;
LAB_10018ed7:
  if (DAT_10023574 < 2) {
    uVar3 = (byte)PTR_DAT_10023368[(uint)bVar6 * 2] & 4;
    this = PTR_DAT_10023368;
  }
  else {
    pbVar10 = (byte *)0x4;
    uVar3 = FUN_100154f0(this,(uint)bVar6,4);
    this = pbVar10;
  }
  if (uVar3 == 0) goto LAB_10018f21;
  this = (void *)(int)(char)bVar6;
  pbVar7 = (byte *)((int)this + (int)pbVar7 * 10 + -0x30);
  if (0x1450 < (int)pbVar7) goto LAB_10018f19;
  bVar6 = *pbVar8;
  pbVar8 = pbVar8 + 1;
  goto LAB_10018ed7;
LAB_10018f19:
  pbVar7 = (byte *)0x1451;
LAB_10018f21:
  while( true ) {
    local_20 = pbVar7;
    if (DAT_10023574 < 2) {
      uVar3 = (byte)PTR_DAT_10023368[(uint)bVar6 * 2] & 4;
      this = PTR_DAT_10023368;
    }
    else {
      pbVar7 = (byte *)0x4;
      uVar3 = FUN_100154f0(this,(uint)bVar6,4);
      this = pbVar7;
    }
    if (uVar3 == 0) break;
    bVar6 = *pbVar8;
    pbVar8 = pbVar8 + 1;
    pbVar7 = local_20;
  }
LAB_10018f51:
  pbVar7 = pbVar8 + -1;
LAB_10018f56:
  *param_2 = (int)pbVar7;
  if (local_14 == 0) {
    local_44 = 0;
    local_3a = 0;
    local_3e = (byte *)0x0;
    param_3 = (byte *)0x0;
    local_18 = 4;
    goto LAB_10019064;
  }
  pcVar4 = local_10;
  if (0x18 < local_8) {
    if ('\x04' < local_49) {
      local_49 = local_49 + '\x01';
    }
    local_8 = 0x18;
    local_c = local_c + 1;
    pcVar4 = local_10 + -1;
  }
  if (local_8 == 0) {
    local_44 = 0;
    local_3a = 0;
    local_3e = (byte *)0x0;
    param_3 = (byte *)0x0;
  }
  else {
    while (pcVar4 = pcVar4 + -1, *pcVar4 == '\0') {
      local_8 = local_8 - 1;
      local_c = local_c + 1;
    }
    FUN_10018b17(local_60,local_8,(uint *)&local_44);
    pbVar8 = local_20;
    if (local_1c < 0) {
      pbVar8 = (byte *)-(int)local_20;
    }
    pbVar8 = pbVar8 + local_c;
    if (local_24 == 0) {
      pbVar8 = pbVar8 + param_5;
    }
    if (local_28 == 0) {
      pbVar8 = pbVar8 + -param_6;
    }
    if ((int)pbVar8 < 0x1451) {
      if (-0x1451 < (int)pbVar8) {
        FUN_10019a1a((int *)&local_44,(uint)pbVar8,param_4);
        param_3 = (byte *)CONCAT22(uStack_40,uStack_42);
        goto LAB_10018fe9;
      }
      local_34 = 1;
    }
    else {
      local_30 = 1;
    }
    local_3a = (ushort)param_3;
    local_3e = param_3;
    local_44 = local_3a;
  }
LAB_10018fe9:
  if (local_30 == 0) {
    if (local_34 != 0) {
      local_44 = 0;
      local_3a = 0;
      local_3e = (byte *)0x0;
      param_3 = (byte *)0x0;
      local_18 = 1;
    }
  }
  else {
    param_3 = (byte *)0x0;
    local_3a = 0x7fff;
    local_3e = (byte *)0x80000000;
    local_44 = 0;
    local_18 = 2;
  }
LAB_10019064:
  *(byte **)(param_1 + 3) = local_3e;
  *(byte **)(param_1 + 1) = param_3;
  param_1[5] = local_3a | (ushort)local_2c;
  *param_1 = local_44;
  return local_18;
}



/* ===== FUN_100190af @ 0x100190AF ===== */

undefined4 __cdecl
FUN_100190af(uint param_1,uint param_2,uint param_3,int param_4,byte param_5,short *param_6)

{
  short *psVar1;
  uint uVar2;
  short *psVar3;
  char cVar4;
  uint uVar5;
  short *psVar6;
  short *psVar7;
  short sVar8;
  int iVar9;
  int iVar10;
  char *pcVar11;
  undefined1 local_20;
  undefined1 local_1f;
  undefined1 local_1e;
  undefined1 local_1d;
  undefined1 local_1c;
  undefined1 local_1b;
  undefined1 local_1a;
  undefined1 local_19;
  undefined1 local_18;
  undefined1 local_17;
  undefined1 local_16;
  undefined1 local_15;
  undefined2 local_14;
  undefined4 local_12;
  undefined4 local_e;
  undefined1 local_a;
  char cStack_9;
  undefined4 local_8;
  
  psVar3 = param_6;
  uVar5 = param_3 & 0x7fff;
  local_20 = 0xcc;
  local_1f = 0xcc;
  local_1e = 0xcc;
  local_1d = 0xcc;
  local_1c = 0xcc;
  local_1b = 0xcc;
  local_1a = 0xcc;
  local_19 = 0xcc;
  local_18 = 0xcc;
  local_17 = 0xcc;
  local_16 = 0xfb;
  local_15 = 0x3f;
  local_8 = 1;
  if ((param_3 & 0x8000) == 0) {
    *(undefined1 *)(param_6 + 1) = 0x20;
  }
  else {
    *(undefined1 *)(param_6 + 1) = 0x2d;
  }
  if ((((short)uVar5 != 0) || (param_2 != 0)) || (param_1 != 0)) {
    if ((short)uVar5 == 0x7fff) {
      *param_6 = 1;
      if (((param_2 == 0x80000000) && (param_1 == 0)) || ((param_2 & 0x40000000) != 0)) {
        if (((param_3 & 0x8000) == 0) || (param_2 != 0xc0000000)) {
          if ((param_2 != 0x80000000) || (param_1 != 0)) goto LAB_100191a4;
          pcVar11 = "1#INF";
        }
        else {
          if (param_1 != 0) {
LAB_100191a4:
            pcVar11 = "1#QNAN";
            goto LAB_100191a9;
          }
          pcVar11 = "1#IND";
        }
        FUN_10015ea0((uint *)(param_6 + 2),(uint *)pcVar11);
        *(undefined1 *)((int)psVar3 + 3) = 5;
      }
      else {
        pcVar11 = "1#SNAN";
LAB_100191a9:
        FUN_10015ea0((uint *)(param_6 + 2),(uint *)pcVar11);
        *(undefined1 *)((int)psVar3 + 3) = 6;
      }
      return 0;
    }
    local_14 = 0;
    local_a = (undefined1)uVar5;
    cStack_9 = (char)(uVar5 >> 8);
    sVar8 = (short)(((uVar5 >> 8) + (param_2 >> 0x18) * 2) * 0x4d + -0x134312f4 + uVar5 * 0x4d10 >>
                   0x10);
    local_e = param_2;
    local_12 = param_1;
    FUN_10019a1a((int *)&local_14,-(int)sVar8,1);
    if (0x3ffe < CONCAT11(cStack_9,local_a)) {
      sVar8 = sVar8 + 1;
      FUN_100197fa((int *)&local_14,(int *)&local_20);
    }
    *psVar3 = sVar8;
    iVar10 = param_4;
    if (((param_5 & 1) == 0) || (iVar10 = param_4 + sVar8, 0 < param_4 + sVar8)) {
      if (0x15 < iVar10) {
        iVar10 = 0x15;
      }
      iVar9 = CONCAT11(cStack_9,local_a) - 0x3ffe;
      local_a = 0;
      cStack_9 = '\0';
      param_6 = (short *)0x8;
      do {
        FUN_10018abc((uint *)&local_14);
        param_6 = (short *)((int)param_6 + -1);
      } while (param_6 != (short *)0x0);
      if (iVar9 < 0) {
        param_6 = (short *)0x0;
        for (uVar5 = -iVar9 & 0xff; uVar5 != 0; uVar5 = uVar5 - 1) {
          FUN_10018aea((uint *)&local_14);
        }
      }
      param_4 = iVar10 + 1;
      psVar6 = psVar3 + 2;
      param_6 = psVar6;
      uVar5 = local_12;
      uVar2 = local_e;
      if (0 < param_4) {
        do {
          local_e._2_2_ = (undefined2)(uVar2 >> 0x10);
          local_e._0_2_ = (undefined2)uVar2;
          local_12._2_2_ = (undefined2)(uVar5 >> 0x10);
          local_12._0_2_ = (undefined2)uVar5;
          param_1 = CONCAT22((undefined2)local_12,local_14);
          param_2 = CONCAT22((undefined2)local_e,local_12._2_2_);
          param_3 = CONCAT13(cStack_9,CONCAT12(local_a,local_e._2_2_));
          local_12 = uVar5;
          local_e = uVar2;
          FUN_10018abc((uint *)&local_14);
          FUN_10018abc((uint *)&local_14);
          ___add_12((uint *)&local_14,&param_1);
          FUN_10018abc((uint *)&local_14);
          cVar4 = cStack_9;
          cStack_9 = '\0';
          psVar6 = (short *)((int)param_6 + 1);
          param_4 = param_4 + -1;
          *(char *)param_6 = cVar4 + '0';
          param_6 = psVar6;
          uVar5 = local_12;
          uVar2 = local_e;
        } while (param_4 != 0);
      }
      psVar7 = psVar6 + -1;
      psVar1 = psVar3 + 2;
      if ('4' < *(char *)((int)psVar6 + -1)) {
        for (; psVar1 <= psVar7; psVar7 = (short *)((int)psVar7 + -1)) {
          if ((char)*psVar7 != '9') {
            if (psVar1 <= psVar7) goto LAB_10019301;
            break;
          }
          *(char *)psVar7 = '0';
        }
        psVar7 = (short *)((int)psVar7 + 1);
        *psVar3 = *psVar3 + 1;
LAB_10019301:
        *(char *)psVar7 = (char)*psVar7 + '\x01';
LAB_10019303:
        cVar4 = ((char)psVar7 - (char)psVar3) + -3;
        *(char *)((int)psVar3 + 3) = cVar4;
        *(undefined1 *)(cVar4 + 4 + (int)psVar3) = 0;
        return local_8;
      }
      for (; psVar1 <= psVar7; psVar7 = (short *)((int)psVar7 + -1)) {
        if ((char)*psVar7 != '0') {
          if (psVar1 <= psVar7) goto LAB_10019303;
          break;
        }
      }
      *psVar3 = 0;
      *(undefined1 *)(psVar3 + 1) = 0x20;
      *(undefined1 *)((int)psVar3 + 3) = 1;
      *(char *)psVar1 = '0';
      goto LAB_10019339;
    }
  }
  *psVar3 = 0;
  *(undefined1 *)(psVar3 + 1) = 0x20;
  *(undefined1 *)((int)psVar3 + 3) = 1;
  *(undefined1 *)(psVar3 + 2) = 0x30;
LAB_10019339:
  *(undefined1 *)((int)psVar3 + 5) = 0;
  return 1;
}



/* ===== FUN_10019342 @ 0x10019342 ===== */

undefined4 __cdecl FUN_10019342(uint param_1)

{
  int *piVar1;
  DWORD *pDVar2;
  int iVar3;
  DWORD nStdHandle;
  
  if (param_1 < DAT_10026bc0) {
    iVar3 = (param_1 & 0x1f) * 0x24;
    piVar1 = (int *)((&DAT_10026ac0)[(int)param_1 >> 5] + iVar3);
    if (((*(byte *)(piVar1 + 1) & 1) != 0) && (*piVar1 != -1)) {
      if (DAT_100254f0 == 1) {
        if (param_1 == 0) {
          nStdHandle = 0xfffffff6;
        }
        else if (param_1 == 1) {
          nStdHandle = 0xfffffff5;
        }
        else {
          if (param_1 != 2) goto LAB_1001939e;
          nStdHandle = 0xfffffff4;
        }
        SetStdHandle(nStdHandle,(HANDLE)0x0);
      }
LAB_1001939e:
      *(undefined4 *)((&DAT_10026ac0)[(int)param_1 >> 5] + iVar3) = 0xffffffff;
      return 0;
    }
  }
  pDVar2 = FUN_100184a5();
  *pDVar2 = 9;
  pDVar2 = FUN_100184ae();
  *pDVar2 = 0;
  return 0xffffffff;
}



/* ===== FUN_100193c1 @ 0x100193C1 ===== */

undefined4 __cdecl FUN_100193c1(uint param_1)

{
  DWORD *pDVar1;
  
  if ((param_1 < DAT_10026bc0) &&
     ((*(byte *)((&DAT_10026ac0)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 1) != 0)) {
    return *(undefined4 *)((&DAT_10026ac0)[(int)param_1 >> 5] + (param_1 & 0x1f) * 0x24);
  }
  pDVar1 = FUN_100184a5();
  *pDVar1 = 9;
  pDVar1 = FUN_100184ae();
  *pDVar1 = 0;
  return 0xffffffff;
}



/* ===== FUN_10019403 @ 0x10019403 ===== */

void __cdecl FUN_10019403(uint param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = (param_1 & 0x1f) * 0x24;
  iVar1 = (&DAT_10026ac0)[(int)param_1 >> 5] + iVar2;
  if (*(int *)(iVar1 + 8) == 0) {
    FUN_10013262(0x11);
    if (*(int *)(iVar1 + 8) == 0) {
      InitializeCriticalSection((LPCRITICAL_SECTION)(iVar1 + 0xc));
      *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + 1;
    }
    FUN_100132c3(0x11);
  }
  EnterCriticalSection((LPCRITICAL_SECTION)((&DAT_10026ac0)[(int)param_1 >> 5] + 0xc + iVar2));
  return;
}



/* ===== FUN_10019462 @ 0x10019462 ===== */

void __cdecl FUN_10019462(uint param_1)

{
  LeaveCriticalSection
            ((LPCRITICAL_SECTION)
             ((&DAT_10026ac0)[(int)param_1 >> 5] + 0xc + (param_1 & 0x1f) * 0x24));
  return;
}



/* ===== FUN_10019505 @ 0x10019505 ===== */

int __cdecl FUN_10019505(int *param_1)

{
  int iVar1;
  
  iVar1 = FUN_10019533(param_1);
  if (iVar1 != 0) {
    return -1;
  }
  if ((*(byte *)((int)param_1 + 0xd) & 0x40) != 0) {
    iVar1 = FUN_10019b13(param_1[4]);
    return -(uint)(iVar1 != 0);
  }
  return 0;
}



/* ===== FUN_10019533 @ 0x10019533 ===== */

undefined4 __cdecl FUN_10019533(int *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar2 = 0;
  if ((((byte)param_1[3] & 3) == 2) && ((param_1[3] & 0x108U) != 0)) {
    uVar3 = *param_1 - param_1[2];
    if (0 < (int)uVar3) {
      uVar1 = FUN_100163a6(param_1[4],(char *)param_1[2],uVar3);
      if (uVar1 == uVar3) {
        if ((param_1[3] & 0x80U) != 0) {
          param_1[3] = param_1[3] & 0xfffffffd;
        }
      }
      else {
        param_1[3] = param_1[3] | 0x20;
        uVar2 = 0xffffffff;
      }
    }
  }
  param_1[1] = 0;
  *param_1 = param_1[2];
  return uVar2;
}



/* ===== FUN_10019598 @ 0x10019598 ===== */

int __cdecl FUN_10019598(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar3 = 0;
  iVar5 = 0;
  FUN_10013262(2);
  iVar4 = 0;
  if (0 < DAT_10026aa0) {
    do {
      iVar2 = *(int *)(DAT_10025a88 + iVar4 * 4);
      if ((iVar2 != 0) && ((*(byte *)(iVar2 + 0xc) & 0x83) != 0)) {
        FUN_100166ee(iVar4,iVar2);
        piVar1 = *(int **)(DAT_10025a88 + iVar4 * 4);
        if ((piVar1[3] & 0x83U) != 0) {
          if (param_1 == 1) {
            iVar2 = FUN_10019505(piVar1);
            if (iVar2 != -1) {
              iVar3 = iVar3 + 1;
            }
          }
          else if ((param_1 == 0) && ((piVar1[3] & 2U) != 0)) {
            iVar2 = FUN_10019505(piVar1);
            if (iVar2 == -1) {
              iVar5 = -1;
            }
          }
        }
        FUN_10016740(iVar4,*(int *)(DAT_10025a88 + iVar4 * 4));
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < DAT_10026aa0);
  }
  FUN_100132c3(2);
  if (param_1 != 1) {
    iVar3 = iVar5;
  }
  return iVar3;
}



/* ===== FUN_1001963c @ 0x1001963C ===== */

uint __cdecl FUN_1001963c(uint param_1)

{
  void *extraout_ECX;
  bool bVar1;
  void *this;
  
  if (DAT_100256f8 == 0) {
    if ((0x60 < (int)param_1) && ((int)param_1 < 0x7b)) {
      return param_1 - 0x20;
    }
  }
  else {
    InterlockedIncrement((LONG *)&DAT_10025854);
    bVar1 = DAT_10025850 != 0;
    this = extraout_ECX;
    if (bVar1) {
      InterlockedDecrement((LONG *)&DAT_10025854);
      this = (void *)0x13;
      FUN_10013262(0x13);
    }
    param_1 = FUN_100196ab(this,param_1);
    if (bVar1) {
      FUN_100132c3(0x13);
    }
    else {
      InterlockedDecrement((LONG *)&DAT_10025854);
    }
  }
  return param_1;
}



/* ===== FUN_100196ab @ 0x100196AB ===== */

uint __thiscall FUN_100196ab(void *this,uint param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  void *local_8;
  
  uVar1 = param_1;
  if (DAT_100256f8 == 0) {
    if ((0x60 < (int)param_1) && ((int)param_1 < 0x7b)) {
      uVar1 = param_1 - 0x20;
    }
  }
  else {
    local_8 = this;
    if ((int)param_1 < 0x100) {
      if (DAT_10023574 < 2) {
        uVar2 = (byte)PTR_DAT_10023368[param_1 * 2] & 2;
      }
      else {
        uVar2 = FUN_100154f0(this,param_1,2);
      }
      if (uVar2 == 0) {
        return uVar1;
      }
    }
    if ((PTR_DAT_10023368[((int)uVar1 >> 8 & 0xffU) * 2 + 1] & 0x80) == 0) {
      param_1 = CONCAT31((int3)(param_1 >> 8),(char)uVar1) & 0xffff00ff;
      iVar3 = 1;
    }
    else {
      uVar2 = param_1 >> 0x10;
      param_1._0_2_ = CONCAT11((char)uVar1,(char)(uVar1 >> 8));
      param_1 = CONCAT22((short)uVar2,(undefined2)param_1) & 0xff00ffff;
      iVar3 = 2;
    }
    iVar3 = FUN_100187ee(DAT_100256f8,0x200,(char *)&param_1,iVar3,(LPWSTR)&local_8,3,0,1);
    if (iVar3 != 0) {
      if (iVar3 == 1) {
        uVar1 = (uint)local_8 & 0xff;
      }
      else {
        uVar1 = (uint)local_8 & 0xffff;
      }
    }
  }
  return uVar1;
}



/* ===== FUN_10019780 @ 0x10019780 ===== */

int __cdecl FUN_10019780(byte *param_1,byte *param_2)

{
  byte bVar1;
  int iVar2;
  byte abStack_28 [32];
  
  abStack_28[0x1c] = 0;
  abStack_28[0x1d] = 0;
  abStack_28[0x1e] = 0;
  abStack_28[0x1f] = 0;
  abStack_28[0x18] = 0;
  abStack_28[0x19] = 0;
  abStack_28[0x1a] = 0;
  abStack_28[0x1b] = 0;
  abStack_28[0x14] = 0;
  abStack_28[0x15] = 0;
  abStack_28[0x16] = 0;
  abStack_28[0x17] = 0;
  abStack_28[0x10] = 0;
  abStack_28[0x11] = 0;
  abStack_28[0x12] = 0;
  abStack_28[0x13] = 0;
  abStack_28[0xc] = 0;
  abStack_28[0xd] = 0;
  abStack_28[0xe] = 0;
  abStack_28[0xf] = 0;
  abStack_28[8] = 0;
  abStack_28[9] = 0;
  abStack_28[10] = 0;
  abStack_28[0xb] = 0;
  abStack_28[4] = 0;
  abStack_28[5] = 0;
  abStack_28[6] = 0;
  abStack_28[7] = 0;
  abStack_28[0] = 0;
  abStack_28[1] = 0;
  abStack_28[2] = 0;
  abStack_28[3] = 0;
  while( true ) {
    bVar1 = *param_2;
    if (bVar1 == 0) break;
    param_2 = param_2 + 1;
    abStack_28[(int)(uint)bVar1 >> 3] = abStack_28[(int)(uint)bVar1 >> 3] | '\x01' << (bVar1 & 7);
  }
  iVar2 = -1;
  do {
    iVar2 = iVar2 + 1;
    bVar1 = *param_1;
    if (bVar1 == 0) {
      return iVar2;
    }
    param_1 = param_1 + 1;
  } while ((abStack_28[(int)(uint)bVar1 >> 3] >> (bVar1 & 7) & 1) == 0);
  return iVar2;
}



/* ===== FUN_100197c0 @ 0x100197C0 ===== */

byte * __cdecl FUN_100197c0(byte *param_1,byte *param_2)

{
  byte bVar1;
  byte *pbVar2;
  byte abStack_28 [32];
  
  abStack_28[0x1c] = 0;
  abStack_28[0x1d] = 0;
  abStack_28[0x1e] = 0;
  abStack_28[0x1f] = 0;
  abStack_28[0x18] = 0;
  abStack_28[0x19] = 0;
  abStack_28[0x1a] = 0;
  abStack_28[0x1b] = 0;
  abStack_28[0x14] = 0;
  abStack_28[0x15] = 0;
  abStack_28[0x16] = 0;
  abStack_28[0x17] = 0;
  abStack_28[0x10] = 0;
  abStack_28[0x11] = 0;
  abStack_28[0x12] = 0;
  abStack_28[0x13] = 0;
  abStack_28[0xc] = 0;
  abStack_28[0xd] = 0;
  abStack_28[0xe] = 0;
  abStack_28[0xf] = 0;
  abStack_28[8] = 0;
  abStack_28[9] = 0;
  abStack_28[10] = 0;
  abStack_28[0xb] = 0;
  abStack_28[4] = 0;
  abStack_28[5] = 0;
  abStack_28[6] = 0;
  abStack_28[7] = 0;
  abStack_28[0] = 0;
  abStack_28[1] = 0;
  abStack_28[2] = 0;
  abStack_28[3] = 0;
  while( true ) {
    bVar1 = *param_2;
    if (bVar1 == 0) break;
    param_2 = param_2 + 1;
    abStack_28[(int)(uint)bVar1 >> 3] = abStack_28[(int)(uint)bVar1 >> 3] | '\x01' << (bVar1 & 7);
  }
  do {
    pbVar2 = param_1;
    bVar1 = *pbVar2;
    if (bVar1 == 0) {
      return (byte *)0x0;
    }
    param_1 = pbVar2 + 1;
  } while ((abStack_28[(int)(uint)bVar1 >> 3] >> (bVar1 & 7) & 1) == 0);
  return pbVar2;
}



/* ===== FUN_100197fa @ 0x100197FA ===== */

void __cdecl FUN_100197fa(int *param_1,int *param_2)

{
  int *piVar1;
  short sVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  ushort uVar6;
  uint uVar7;
  int iVar8;
  ushort uVar9;
  uint uVar10;
  ushort uVar11;
  byte local_28;
  undefined1 uStack_27;
  undefined2 uStack_26;
  short local_24;
  undefined2 uStack_22;
  undefined2 local_20;
  undefined1 uStack_1e;
  byte bStack_1d;
  int *local_1c;
  int local_18;
  int local_14;
  ushort *local_10;
  ushort *local_c;
  short *local_8;
  
  piVar5 = param_2;
  piVar4 = param_1;
  local_18 = 0;
  local_28 = 0;
  uStack_27 = 0;
  uStack_26 = 0;
  local_24 = 0;
  uStack_22 = 0;
  local_20 = 0;
  uStack_1e = 0;
  bStack_1d = 0;
  uVar7 = *(ushort *)((int)param_1 + 10) & 0x7fff;
  uVar10 = *(ushort *)((int)param_2 + 10) & 0x7fff;
  uVar11 = (*(ushort *)((int)param_2 + 10) ^ *(ushort *)((int)param_1 + 10)) & 0x8000;
  uVar6 = (ushort)uVar7;
  piVar1 = (int *)(uVar10 + uVar7);
  if (((uVar6 < 0x7fff) && (uVar9 = (ushort)uVar10, uVar9 < 0x7fff)) && ((ushort)piVar1 < 0xbffe)) {
    if ((ushort)piVar1 < 0x3fc0) {
LAB_1001989d:
      piVar4[2] = 0;
      piVar4[1] = 0;
      *piVar4 = 0;
      return;
    }
    if (((uVar6 != 0) || (piVar1 = (int *)((int)piVar1 + 1), (param_1[2] & 0x7fffffffU) != 0)) ||
       ((uVar6 = 0, param_1[1] != 0 || (*param_1 != 0)))) {
      param_1 = piVar1;
      if (((uVar9 == 0) && (param_1 = (int *)((int)param_1 + 1), (param_2[2] & 0x7fffffffU) == 0))
         && ((param_2[1] == 0 && (*param_2 == 0)))) goto LAB_1001989d;
      local_14 = 0;
      local_8 = &local_24;
      param_2 = (int *)0x5;
      do {
        if (0 < (int)param_2) {
          local_c = (ushort *)(local_14 * 2 + (int)piVar4);
          local_10 = (ushort *)(piVar5 + 2);
          local_1c = param_2;
          do {
            iVar8 = FUN_10018a3d(*(uint *)(local_8 + -2),(uint)*local_c * (uint)*local_10,
                                 (uint *)(local_8 + -2));
            if (iVar8 != 0) {
              *local_8 = *local_8 + 1;
            }
            local_c = local_c + 1;
            local_10 = local_10 + -1;
            local_1c = (int *)((int)local_1c + -1);
          } while (local_1c != (int *)0x0);
        }
        local_8 = local_8 + 1;
        local_14 = local_14 + 1;
        param_2 = (int *)((int)param_2 + -1);
      } while (0 < (int)param_2);
      param_1 = (int *)((int)param_1 + 0xc002);
      if ((short)(ushort)param_1 < 1) {
LAB_10019951:
        param_1._0_2_ = (ushort)param_1 - 1;
        if ((short)(ushort)param_1 < 0) {
          iVar8 = -(int)(short)(ushort)param_1;
          param_1._0_2_ = (ushort)param_1 + (short)iVar8;
          do {
            if ((local_28 & 1) != 0) {
              local_18 = local_18 + 1;
            }
            FUN_10018aea((uint *)&local_28);
            iVar8 = iVar8 + -1;
          } while (iVar8 != 0);
          if (local_18 != 0) {
            local_28 = local_28 | 1;
          }
        }
      }
      else {
        do {
          if ((bStack_1d & 0x80) != 0) break;
          FUN_10018abc((uint *)&local_28);
          param_1 = (int *)((int)param_1 + 0xffff);
        } while (0 < (short)(ushort)param_1);
        if ((short)(ushort)param_1 < 1) goto LAB_10019951;
      }
      if ((0x8000 < CONCAT11(uStack_27,local_28)) ||
         (sVar2 = CONCAT11(bStack_1d,uStack_1e), iVar3 = CONCAT22(local_20,uStack_22),
         iVar8 = CONCAT22(local_24,uStack_26),
         (CONCAT22(uStack_26,CONCAT11(uStack_27,local_28)) & 0x1ffff) == 0x18000)) {
        if (CONCAT22(local_24,uStack_26) == -1) {
          iVar8 = 0;
          if (CONCAT22(local_20,uStack_22) == -1) {
            if (CONCAT11(bStack_1d,uStack_1e) == -1) {
              param_1._0_2_ = (ushort)param_1 + 1;
              sVar2 = -0x8000;
              iVar3 = 0;
              iVar8 = 0;
            }
            else {
              sVar2 = CONCAT11(bStack_1d,uStack_1e) + 1;
              iVar3 = 0;
              iVar8 = 0;
            }
          }
          else {
            sVar2 = CONCAT11(bStack_1d,uStack_1e);
            iVar3 = CONCAT22(local_20,uStack_22) + 1;
          }
        }
        else {
          iVar8 = CONCAT22(local_24,uStack_26) + 1;
          sVar2 = CONCAT11(bStack_1d,uStack_1e);
          iVar3 = CONCAT22(local_20,uStack_22);
        }
      }
      local_24 = (short)((uint)iVar8 >> 0x10);
      uStack_26 = (undefined2)iVar8;
      local_20 = (undefined2)((uint)iVar3 >> 0x10);
      uStack_22 = (undefined2)iVar3;
      bStack_1d = (byte)((ushort)sVar2 >> 8);
      uStack_1e = (undefined1)sVar2;
      if (0x7ffe < (ushort)param_1) goto LAB_100199fa;
      uVar6 = (ushort)param_1 | uVar11;
      *(undefined2 *)piVar4 = uStack_26;
      *(uint *)((int)piVar4 + 2) = CONCAT22(uStack_22,local_24);
      *(uint *)((int)piVar4 + 6) = CONCAT13(bStack_1d,CONCAT12(uStack_1e,local_20));
    }
    *(ushort *)((int)piVar4 + 10) = uVar6;
  }
  else {
LAB_100199fa:
    piVar4[1] = 0;
    *piVar4 = 0;
    piVar4[2] = (-(uint)(uVar11 != 0) & 0x80000000) + 0x7fff8000;
  }
  return;
}



/* ===== FUN_10019a1a @ 0x10019A1A ===== */

void __cdecl FUN_10019a1a(int *param_1,uint param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  undefined **ppuVar3;
  undefined **ppuVar4;
  undefined2 local_10;
  undefined4 local_e;
  undefined2 uStack_a;
  undefined *puStack_8;
  
  ppuVar3 = &PTR_DAT_10023e50;
  if (param_2 != 0) {
    if ((int)param_2 < 0) {
      param_2 = -param_2;
      ppuVar3 = (undefined **)0x10023fb0;
    }
    if (param_3 == 0) {
      *(undefined2 *)param_1 = 0;
    }
    while (param_2 != 0) {
      ppuVar3 = ppuVar3 + 0x15;
      uVar1 = (int)param_2 >> 3;
      uVar2 = param_2 & 7;
      param_2 = uVar1;
      if (uVar2 != 0) {
        ppuVar4 = ppuVar3 + uVar2 * 3;
        if (0x7fff < *(ushort *)(ppuVar3 + uVar2 * 3)) {
          local_10 = SUB42(*ppuVar4,0);
          local_e._0_2_ = (undefined2)((uint)*ppuVar4 >> 0x10);
          local_e._2_2_ = SUB42(ppuVar4[1],0);
          uStack_a = (undefined2)((uint)ppuVar4[1] >> 0x10);
          puStack_8 = ppuVar4[2];
          local_e = CONCAT22(local_e._2_2_,(undefined2)local_e) + -1;
          ppuVar4 = (undefined **)&local_10;
        }
        FUN_100197fa(param_1,(int *)ppuVar4);
      }
    }
  }
  return;
}



/* ===== FUN_10019a96 @ 0x10019A96 ===== */

undefined4 __cdecl FUN_10019a96(int *param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if ((*(byte *)(param_1 + 3) & 0x40) == 0) {
    FUN_100166bf((uint)param_1);
    uVar1 = FUN_10019ac7(param_1);
    FUN_10016711((uint)param_1);
  }
  else {
    param_1[3] = 0;
  }
  return uVar1;
}



/* ===== FUN_10019ac7 @ 0x10019AC7 ===== */

undefined4 __cdecl FUN_10019ac7(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0xffffffff;
  if ((*(byte *)(param_1 + 3) & 0x83) != 0) {
    uVar2 = FUN_10019533(param_1);
    FUN_10019e61(param_1);
    iVar1 = FUN_10019d81(param_1[4]);
    if (iVar1 < 0) {
      uVar2 = 0xffffffff;
    }
    else if ((undefined *)param_1[7] != (undefined *)0x0) {
      FUN_100101ee((undefined *)param_1[7]);
      param_1[7] = 0;
    }
  }
  param_1[3] = 0;
  return uVar2;
}



/* ===== FUN_10019b13 @ 0x10019B13 ===== */

undefined4 __cdecl FUN_10019b13(uint param_1)

{
  HANDLE hFile;
  BOOL BVar1;
  DWORD DVar2;
  DWORD *pDVar3;
  int iVar4;
  undefined4 uVar5;
  
  if (DAT_10026bc0 <= param_1) {
LAB_10019b94:
    pDVar3 = FUN_100184a5();
    *pDVar3 = 9;
    return 0xffffffff;
  }
  iVar4 = (param_1 & 0x1f) * 0x24;
  if ((*(byte *)((&DAT_10026ac0)[(int)param_1 >> 5] + 4 + iVar4) & 1) == 0) goto LAB_10019b94;
  FUN_10019403(param_1);
  if ((*(byte *)((&DAT_10026ac0)[(int)param_1 >> 5] + 4 + iVar4) & 1) != 0) {
    hFile = (HANDLE)FUN_100193c1(param_1);
    BVar1 = FlushFileBuffers(hFile);
    if (BVar1 == 0) {
      DVar2 = GetLastError();
    }
    else {
      DVar2 = 0;
    }
    uVar5 = 0;
    if (DVar2 == 0) goto LAB_10019b89;
    pDVar3 = FUN_100184ae();
    *pDVar3 = DVar2;
  }
  pDVar3 = FUN_100184a5();
  *pDVar3 = 9;
  uVar5 = 0xffffffff;
LAB_10019b89:
  FUN_10019462(param_1);
  return uVar5;
}



/* ===== FUN_10019bb0 @ 0x10019BB0 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint __thiscall FUN_10019bb0(void *this,byte *param_1,byte *param_2)

{
  bool bVar1;
  int iVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  char cVar6;
  void *extraout_ECX;
  void *this_00;
  void *extraout_ECX_00;
  uint uVar8;
  uint uVar9;
  uint uVar7;
  
  iVar2 = _DAT_10025854;
  if (DAT_100256f8 == 0) {
    bVar5 = 0xff;
    do {
      do {
        cVar6 = '\0';
        if (bVar5 == 0) goto LAB_10019bfe;
        bVar5 = *param_2;
        param_2 = param_2 + 1;
        bVar4 = *param_1;
        param_1 = param_1 + 1;
      } while (bVar4 == bVar5);
      bVar3 = bVar5 + 0xbf + (-((byte)(bVar5 + 0xbf) < 0x1a) & 0x20U) + 0x41;
      bVar4 = bVar4 + 0xbf;
      bVar5 = bVar4 + (-(bVar4 < 0x1a) & 0x20U) + 0x41;
    } while (bVar5 == bVar3);
    cVar6 = (bVar5 < bVar3) * -2 + '\x01';
LAB_10019bfe:
    uVar7 = (uint)cVar6;
  }
  else {
    LOCK();
    _DAT_10025854 = _DAT_10025854 + 1;
    UNLOCK();
    bVar1 = 0 < DAT_10025850;
    if (bVar1) {
      LOCK();
      UNLOCK();
      _DAT_10025854 = iVar2;
      FUN_10013262(0x13);
      this = extraout_ECX;
    }
    uVar9 = (uint)bVar1;
    uVar7 = 0xff;
    uVar8 = 0;
    do {
      do {
        if ((char)uVar7 == '\0') goto LAB_10019c5f;
        bVar5 = *param_2;
        uVar7 = CONCAT31((int3)(uVar7 >> 8),bVar5);
        param_2 = param_2 + 1;
        bVar4 = *param_1;
        uVar8 = CONCAT31((int3)(uVar8 >> 8),bVar4);
        param_1 = param_1 + 1;
      } while (bVar5 == bVar4);
      uVar8 = FUN_1001585d(this,uVar8);
      uVar7 = FUN_1001585d(this_00,uVar7);
      this = extraout_ECX_00;
    } while ((byte)uVar8 == (byte)uVar7);
    uVar8 = (uint)((byte)uVar8 < (byte)uVar7);
    uVar7 = (1 - uVar8) - (uint)(uVar8 != 0);
LAB_10019c5f:
    if (uVar9 == 0) {
      LOCK();
      _DAT_10025854 = _DAT_10025854 + -1;
      UNLOCK();
    }
    else {
      FUN_100132c3(0x13);
    }
  }
  return uVar7;
}



/* ===== FUN_10019c80 @ 0x10019C80 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_10019c80(byte *param_1,char *param_2,void *param_3)

{
  char cVar1;
  int iVar2;
  byte bVar3;
  ushort uVar4;
  uint uVar5;
  undefined4 uVar6;
  void *this;
  uint uVar7;
  bool bVar8;
  uint uVar9;
  
  iVar2 = _DAT_10025854;
  uVar6 = 0;
  if (param_3 != (void *)0x0) {
    if (DAT_100256f8 == 0) {
      do {
        bVar3 = *param_1;
        cVar1 = *param_2;
        uVar4 = CONCAT11(bVar3,cVar1);
        if (bVar3 == 0) break;
        uVar4 = CONCAT11(bVar3,cVar1);
        uVar7 = (uint)uVar4;
        if (cVar1 == '\0') break;
        param_1 = param_1 + 1;
        param_2 = param_2 + 1;
        if ((0x40 < bVar3) && (bVar3 < 0x5b)) {
          uVar7 = (uint)CONCAT11(bVar3 + 0x20,cVar1);
        }
        uVar4 = (ushort)uVar7;
        bVar3 = (byte)uVar7;
        if ((0x40 < bVar3) && (bVar3 < 0x5b)) {
          uVar4 = (ushort)CONCAT31((int3)(uVar7 >> 8),bVar3 + 0x20);
        }
        bVar3 = (byte)(uVar4 >> 8);
        bVar8 = bVar3 < (byte)uVar4;
        if (bVar3 != (byte)uVar4) goto LAB_10019cdf;
        param_3 = (void *)((int)param_3 + -1);
      } while (param_3 != (void *)0x0);
      uVar6 = 0;
      bVar3 = (byte)(uVar4 >> 8);
      bVar8 = bVar3 < (byte)uVar4;
      if (bVar3 != (byte)uVar4) {
LAB_10019cdf:
        uVar6 = 0xffffffff;
        if (!bVar8) {
          uVar6 = 1;
        }
      }
    }
    else {
      LOCK();
      _DAT_10025854 = _DAT_10025854 + 1;
      UNLOCK();
      bVar8 = 0 < DAT_10025850;
      if (bVar8) {
        LOCK();
        UNLOCK();
        _DAT_10025854 = iVar2;
        FUN_10013262(0x13);
      }
      uVar9 = (uint)bVar8;
      uVar5 = 0;
      uVar7 = 0;
      do {
        uVar5 = CONCAT31((int3)(uVar5 >> 8),*param_1);
        uVar7 = CONCAT31((int3)(uVar7 >> 8),*param_2);
        if ((uVar5 == 0) || (uVar7 == 0)) break;
        param_1 = param_1 + 1;
        param_2 = param_2 + 1;
        uVar7 = FUN_1001585d(param_3,uVar7);
        uVar5 = FUN_1001585d(this,uVar5);
        bVar8 = uVar5 < uVar7;
        if (uVar5 != uVar7) goto LAB_10019d55;
        param_3 = (void *)((int)param_3 + -1);
      } while (param_3 != (void *)0x0);
      uVar6 = 0;
      bVar8 = uVar5 < uVar7;
      if (uVar5 != uVar7) {
LAB_10019d55:
        uVar6 = 0xffffffff;
        if (!bVar8) {
          uVar6 = 1;
        }
      }
      if (uVar9 == 0) {
        LOCK();
        _DAT_10025854 = _DAT_10025854 + -1;
        UNLOCK();
      }
      else {
        FUN_100132c3(0x13);
      }
    }
  }
  return uVar6;
}



/* ===== FUN_10019d81 @ 0x10019D81 ===== */

undefined4 __cdecl FUN_10019d81(uint param_1)

{
  undefined4 uVar1;
  DWORD *pDVar2;
  
  if ((param_1 < DAT_10026bc0) &&
     ((*(byte *)((&DAT_10026ac0)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 1) != 0)) {
    FUN_10019403(param_1);
    uVar1 = FUN_10019dde(param_1);
    FUN_10019462(param_1);
    return uVar1;
  }
  pDVar2 = FUN_100184a5();
  *pDVar2 = 9;
  pDVar2 = FUN_100184ae();
  *pDVar2 = 0;
  return 0xffffffff;
}



/* ===== FUN_10019dde @ 0x10019DDE ===== */

undefined4 __cdecl FUN_10019dde(uint param_1)

{
  int iVar1;
  int iVar2;
  HANDLE hObject;
  BOOL BVar3;
  DWORD DVar4;
  undefined4 uVar5;
  
  iVar1 = FUN_100193c1(param_1);
  if (iVar1 != -1) {
    if ((param_1 == 1) || (param_1 == 2)) {
      iVar1 = FUN_100193c1(2);
      iVar2 = FUN_100193c1(1);
      if (iVar2 == iVar1) goto LAB_10019e2c;
    }
    hObject = (HANDLE)FUN_100193c1(param_1);
    BVar3 = CloseHandle(hObject);
    if (BVar3 == 0) {
      DVar4 = GetLastError();
      goto LAB_10019e2e;
    }
  }
LAB_10019e2c:
  DVar4 = 0;
LAB_10019e2e:
  FUN_10019342(param_1);
  *(undefined1 *)((&DAT_10026ac0)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) = 0;
  if (DVar4 == 0) {
    uVar5 = 0;
  }
  else {
    FUN_10018432(DVar4);
    uVar5 = 0xffffffff;
  }
  return uVar5;
}



/* ===== FUN_10019e61 @ 0x10019E61 ===== */

void __cdecl FUN_10019e61(undefined4 *param_1)

{
  if (((param_1[3] & 0x83) != 0) && ((param_1[3] & 8) != 0)) {
    FUN_100101ee((undefined *)param_1[2]);
    *(ushort *)(param_1 + 3) = *(ushort *)(param_1 + 3) & 0xfbf7;
    *param_1 = 0;
    param_1[2] = 0;
    param_1[1] = 0;
  }
  return;
}



/* ===== Unwind@10019ea0 @ 0x10019EA0 ===== */

void Unwind_10019ea0(void)

{
  int unaff_EBP;
  
  FUN_1000fe9b(*(undefined **)(unaff_EBP + -0x10));
  return;
}



