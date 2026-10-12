/* Giants 1.449 — module _unmapped_0041
 * 100 functions (1 named) — decompiled, names from PS2 symbols
 * Original source: C:\Giants\source\_unmapped_0041.c(pp) (assert-string evidence)
 */

/* ===== FUN_00410720 @ 0x00410720 ===== */
void FUN_00410720(undefined4 param_1,undefined4 *param_2,int *param_3)



{

  undefined2 *puVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  undefined2 uVar7;

  int iVar8;

  int iVar9;

  int iVar10;

  int iVar11;

  int iVar12;

  uint uVar13;

  char *pcVar14;

  float local_6c;

  float local_68;

  float local_64;

  float local_60;

  float local_58;

  float local_54;

  float local_44;

  float local_40;

  float local_38;

  float local_34;

  float local_2c;

  float local_28;

  float local_20;

  float local_1c;

  undefined4 local_14;

  undefined4 local_10;

  undefined4 local_c;

  

  puVar1 = (undefined2 *)*param_3;

  local_14 = *param_2;

  local_10 = param_2[1];

  local_c = param_2[2];

  FUN_005170f0(param_1,&local_14,&local_2c);

  local_14 = param_2[3];

  FUN_005170f0(param_1,&local_14,&local_44);

  local_10 = param_2[4];

  FUN_005170f0(param_1,&local_14,&local_38);

  local_14 = *param_2;

  FUN_005170f0(param_1,&local_14,&local_20);

  fVar2 = local_28;

  if (local_40 < local_28) {

    fVar2 = local_40;

  }

  if (local_34 < fVar2) {

    fVar2 = local_34;

  }

  if (local_1c < fVar2) {

    fVar2 = local_1c;

  }

  local_68 = local_28;

  if (local_28 < local_40) {

    local_68 = local_40;

  }

  if (local_68 < local_34) {

    local_68 = local_34;

  }

  if (local_68 < local_1c) {

    local_68 = local_1c;

  }

  local_6c = local_2c;

  if (local_44 < local_2c) {

    local_6c = local_44;

  }

  if (local_38 < local_6c) {

    local_6c = local_38;

  }

  if (local_20 < local_6c) {

    local_6c = local_20;

  }

  local_64 = local_2c;

  if (local_2c < local_44) {

    local_64 = local_44;

  }

  if (local_64 < local_38) {

    local_64 = local_38;

  }

  if (local_64 < local_20) {

    local_64 = local_20;

  }

  FUN_005435a5((double)(fVar2 * 0.2 + 0.5));

  iVar8 = __ftol();

  FUN_005435a5((double)(local_68 * 0.2 + 0.5));

  iVar9 = __ftol();

  FUN_005435a5((double)(local_6c * 0.2 + 0.5));

  iVar10 = __ftol();

  FUN_005435a5((double)(local_64 * 0.2 + 0.5));

  uVar7 = __ftol();

  *puVar1 = (short)iVar10;

  puVar1[1] = (short)iVar8;

  puVar1[2] = uVar7;

  puVar1[3] = (short)iVar9;

  pcVar14 = (char *)(puVar1 + 4);

  fVar2 = (local_20 + local_38 + local_44 + local_2c) * 0.25;

  for (; iVar8 <= iVar9; iVar8 = iVar8 + 1) {

    fVar3 = (float)iVar8 * 5.0;

    if (local_28 == local_40) {

      local_68 = 999999.0;

    }

    else {

      local_68 = ((local_44 - local_2c) * (local_28 - fVar3)) / (local_28 - local_40) + local_2c;

    }

    if (local_40 == local_34) {

      local_6c = 999999.0;

    }

    else {

      local_6c = ((local_38 - local_44) * (local_40 - fVar3)) / (local_40 - local_34) + local_44;

    }

    fVar5 = local_6c;

    if (local_34 == local_1c) {

      fVar4 = 999999.0;

    }

    else {

      fVar4 = ((local_20 - local_38) * (local_34 - fVar3)) / (local_34 - local_1c) + local_38;

    }

    if (local_1c == local_28) {

      local_64 = 999999.0;

    }

    else {

      local_64 = ((local_2c - local_20) * (local_1c - fVar3)) / (local_1c - local_28) + local_20;

    }

    local_54 = ABS(local_68 - fVar2);

    fVar6 = ABS(local_6c - fVar2);

    fVar3 = ABS(fVar4 - fVar2);

    local_58 = ABS(local_64 - fVar2);

    local_60 = fVar6;

    if (fVar6 < local_54) {

      local_6c = local_68;

      local_68 = fVar5;

      local_60 = local_54;

      local_54 = fVar6;

    }

    fVar5 = fVar4;

    fVar6 = fVar3;

    if (local_58 < fVar3) {

      fVar5 = local_64;

      fVar6 = local_58;

      local_64 = fVar4;

      local_58 = fVar3;

    }

    if ((fVar6 <= local_60) && (local_6c = fVar5, local_58 < local_54)) {

      local_6c = local_64;

      local_68 = fVar5;

    }

    if (local_6c <= local_68) {

      FUN_005435a5((double)(local_6c * 0.2 + 0.5));

      iVar11 = __ftol();

      FUN_005435a5((double)(local_68 * 0.2 + 0.5));

      iVar12 = __ftol();

    }

    else {

      FUN_005435a5((double)(local_68 * 0.2 + 0.5));

      iVar11 = __ftol();

      FUN_005435a5((double)(local_6c * 0.2 + 0.5));

      iVar12 = __ftol();

    }

    uVar13 = iVar11 - iVar10 >> 0x1f;

    if (0x7f < (int)((iVar11 - iVar10 ^ uVar13) - uVar13)) {

      FUN_00518f00();

    }

    local_58._0_1_ = (char)iVar10;

    *pcVar14 = (char)iVar11 - local_58._0_1_;

    pcVar14[1] = ((char)iVar12 - (char)iVar11) + '\x01';

    if (0xff < iVar12 - iVar11) {

      FUN_00518f00();

    }

    pcVar14 = pcVar14 + 2;

    iVar10 = iVar11;

  }

  *pcVar14 = -0x80;

  *param_3 = (int)(pcVar14 + 1);

  return;

}

/* ===== FUN_00412180 @ 0x00412180 ===== */
uint FUN_00412180(int param_1,int param_2,int param_3)



{

  char cVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  uint uVar9;

  uint uVar10;

  short *psVar11;

  char *pcVar12;

  char *pcVar13;

  byte *pbVar14;

  

  main_collgrid_00410200();

  pcVar13 = *(char **)(param_1 + 0x21c);

  if (pcVar13 == (char *)0x0) {

    uVar9 = *(uint *)(param_1 + 0x1c8);

    if (((((uVar9 & 0x400000) != 0) && ((uVar9 & 0x800) == 0)) &&

        (((uVar9 & 0x80000) == 0 && (((uVar9 & 0x100000) == 0 && ((uVar9 & 0x1008) == 0)))))) &&

       ((*(uint *)(param_1 + 0xd8) & 0x80000) != 0)) {

      fVar2 = *(float *)(param_1 + 0xa0);

      fVar3 = *(float *)(param_1 + 0xa4);

      fVar4 = *(float *)(param_1 + 0x154);

      FUN_005435a5((double)((fVar3 - fVar4) * 0.2 + 0.5));

      iVar5 = __ftol();

      FUN_005435a5((double)((fVar3 + fVar4) * 0.2 + 0.5));

      iVar6 = __ftol();

      FUN_005435a5((double)((fVar2 - fVar4) * 0.2 + 0.5));

      iVar7 = __ftol();

      FUN_005435a5((double)((fVar2 + fVar4) * 0.2 + 0.5));

      iVar8 = __ftol();

      if ((((iVar7 <= param_2) && (param_2 <= iVar8)) && (iVar5 <= param_3)) && (param_3 <= iVar6))

      {

        return 1;

      }

    }

  }

  else {

    cVar1 = *pcVar13;

    psVar11 = (short *)(pcVar13 + 1);

    if (cVar1 == '\x01') {

      iVar6 = (int)*psVar11;

      iVar5 = (int)*(short *)(pcVar13 + 3);

      pcVar12 = pcVar13 + 9;

      if ((((iVar6 <= param_2) && (iVar5 <= param_3)) && (param_2 <= *(short *)(pcVar13 + 5))) &&

         (param_3 <= *(short *)(pcVar13 + 7))) {

        while( true ) {

          cVar1 = *pcVar12;

          if (cVar1 == -0x80) break;

          uVar9 = (uint)(byte)pcVar12[1];

          pcVar12 = pcVar12 + 2;

          iVar6 = iVar6 + cVar1;

          if (iVar5 != param_3 && param_3 <= iVar5) {

            return 0;

          }

          if (iVar5 == param_3) {

LAB_00412348:

            if (param_2 < iVar6) {

              return 0;

            }

            if ((int)(uVar9 + iVar6) <= param_2) {

              return 0;

            }

            return 1;

          }

          iVar5 = iVar5 + 1;

        }

      }

    }

    else if (cVar1 == '\x02') {

      iVar5 = (int)*psVar11;

      iVar6 = (int)*(short *)(pcVar13 + 3);

      pcVar13 = pcVar13 + 9;

      while( true ) {

        cVar1 = *pcVar13;

        pbVar14 = (byte *)(pcVar13 + 1);

        if (cVar1 == -0x80) break;

        pcVar13 = pcVar13 + 2;

        iVar5 = iVar5 + cVar1;

        if (((iVar6 == param_3) && (iVar5 <= param_2)) && (param_2 < (int)((uint)*pbVar14 + iVar5)))

        {

          return 1;

        }

        iVar6 = iVar6 + 1;

      }

      iVar6 = (int)*(short *)pbVar14;

      iVar5 = (int)*(short *)(pcVar13 + 3);

      pcVar12 = pcVar13 + 9;

      if (((iVar6 <= param_2) && (iVar5 <= param_3)) &&

         ((param_2 <= *(short *)(pcVar13 + 5) && (param_3 <= *(short *)(pcVar13 + 7))))) {

        while( true ) {

          cVar1 = *pcVar12;

          if (cVar1 == -0x80) break;

          uVar9 = (uint)(byte)pcVar12[1];

          pcVar12 = pcVar12 + 2;

          iVar6 = iVar6 + cVar1;

          if (iVar5 != param_3 && param_3 <= iVar5) {

            return 0;

          }

          if (iVar5 == param_3) goto LAB_00412348;

          iVar5 = iVar5 + 1;

        }

      }

    }

    else if (cVar1 == '\x03') {

      iVar5 = (int)*psVar11;

      if (((iVar5 <= param_2) && (*(short *)(pcVar13 + 3) <= param_3)) &&

         ((param_2 <= *(short *)(pcVar13 + 5) &&

          (((param_3 <= *(short *)(pcVar13 + 7) &&

            ((pcVar13[(((*(short *)(pcVar13 + 5) - iVar5) + 1) * (param_3 - *(short *)(pcVar13 + 3))

                      - iVar5) + param_2 + 9] & 1U) != 0)) &&

           ((pcVar13[(((*(short *)(pcVar13 + 5) - iVar5) + 1) * (param_3 - *(short *)(pcVar13 + 3))

                     - iVar5) + param_2 + 9] & 2U) == 0)))))) {

        return 1;

      }

    }

    else if (cVar1 == '\x04') {

      iVar5 = (int)*psVar11;

      if (((iVar5 <= param_2) && (*(short *)(pcVar13 + 3) <= param_3)) &&

         ((param_2 <= *(short *)(pcVar13 + 5) && (param_3 <= *(short *)(pcVar13 + 7))))) {

        uVar9 = param_2 - iVar5;

        iVar5 = (*(short *)(pcVar13 + 5) - iVar5) + 1;

        uVar10 = uVar9 & 0x80000007;

        if ((int)uVar10 < 0) {

          uVar10 = (uVar10 - 1 | 0xfffffff8) + 1;

        }

        return (uint)*(byte *)((int)(pcVar13 + 7) +

                              ((int)(uVar9 + ((int)uVar9 >> 0x1f & 7U)) >> 3) + 2 +

                              ((int)(iVar5 + (iVar5 >> 0x1f & 7U)) >> 3) *

                              (param_3 - *(short *)(pcVar13 + 3))) & 1 << ((byte)uVar10 & 0x1f);

      }

    }

    else if (cVar1 == '\x05') {

      iVar6 = (int)*psVar11;

      iVar5 = (int)*(short *)(pcVar13 + 3);

      pcVar12 = pcVar13 + 9;

      if ((((iVar6 <= param_2) && (iVar5 <= param_3)) && (param_2 <= *(short *)(pcVar13 + 5))) &&

         (param_3 <= *(short *)(pcVar13 + 7))) {

        while( true ) {

          cVar1 = *pcVar12;

          if (cVar1 == -0x80) break;

          uVar9 = (uint)(byte)pcVar12[1];

          pcVar12 = pcVar12 + 2;

          iVar6 = iVar6 + cVar1;

          if (iVar5 != param_3 && param_3 <= iVar5) {

            return 0;

          }

          if (iVar5 == param_3) goto LAB_00412348;

          iVar5 = iVar5 + 1;

        }

      }

    }

  }

  return 0;

}

/* ===== FUN_00412570 @ 0x00412570 ===== */
byte FUN_00412570(int param_1,int param_2,int param_3)



{

  char *pcVar1;

  int iVar2;

  

  main_collgrid_00410200(param_1);

  pcVar1 = *(char **)(param_1 + 0x21c);

  if (((pcVar1 != (char *)0x0) && ((*(byte *)(param_1 + 0x1c8) & 8) != 0)) && (*pcVar1 == '\x03')) {

    iVar2 = (int)*(short *)(pcVar1 + 1);

    if (((iVar2 <= param_2) && (*(short *)(pcVar1 + 3) <= param_3)) &&

       ((param_2 <= *(short *)(pcVar1 + 5) && (param_3 <= *(short *)(pcVar1 + 7))))) {

      return *(byte *)((int)(pcVar1 + 7) +

                      param_2 + (((*(short *)(pcVar1 + 5) - iVar2) + 1) *

                                 (param_3 - *(short *)(pcVar1 + 3)) - iVar2) + 2) & 2;

    }

  }

  return 0;

}

/* ===== FUN_004125f0 @ 0x004125F0 ===== */
void FUN_004125f0(int param_1,float *param_2,float *param_3)



{

  char *pcVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  uint uVar5;

  uint uVar6;

  int iVar7;

  int iVar8;

  

  *param_3 = *param_2;

  param_3[1] = param_2[1];

  param_3[2] = param_2[2];

  main_collgrid_00410200();

  pcVar1 = *(char **)(param_1 + 0x21c);

  if (((pcVar1 != (char *)0x0) && ((*(byte *)(param_1 + 0x1c8) & 8) != 0)) && (*pcVar1 == '\x03')) {

    iVar7 = (int)*(short *)(pcVar1 + 1);

    param_1 = (int)*(short *)(pcVar1 + 3);

    iVar8 = (int)*(short *)(pcVar1 + 5);

    iVar2 = (int)*(short *)(pcVar1 + 7);

    FUN_005435a5((double)(*param_2 * 0.2 + 0.5));

    iVar3 = __ftol();

    FUN_005435a5((double)(param_2[1] * 0.2 + 0.5));

    iVar4 = __ftol();

    if (((iVar7 <= iVar3) && (param_1 <= iVar4)) && ((iVar3 <= iVar8 && (iVar4 <= iVar2)))) {

      if (iVar3 - iVar7 < iVar8 - iVar3) {

        iVar7 = iVar7 + -1;

      }

      else {

        iVar7 = iVar8 + 1;

      }

      if (iVar4 - param_1 < iVar2 - iVar4) {

        param_1 = param_1 + -1;

      }

      else {

        param_1 = iVar2 + 1;

      }

      uVar5 = iVar4 - param_1 >> 0x1f;

      uVar6 = iVar3 - iVar7 >> 0x1f;

      param_2 = (float *)iVar3;

      if ((int)((iVar3 - iVar7 ^ uVar6) - uVar6) < (int)((iVar4 - param_1 ^ uVar5) - uVar5)) {

        param_1 = iVar4;

        param_2 = (float *)iVar7;

      }

      *param_3 = (float)(int)param_2 * 5.0;

      param_3[1] = (float)param_1 * 5.0;

    }

  }

  return;

}

/* ===== FUN_00412730 @ 0x00412730 ===== */
void FUN_00412730(int param_1,int param_2,int param_3,int param_4,int param_5)



{

  int iVar1;

  char cVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  int iVar9;

  uint uVar10;

  int iVar11;

  uint uVar12;

  int iVar13;

  short *psVar14;

  char *pcVar15;

  byte *pbVar16;

  char *pcVar17;

  undefined4 *puVar18;

  int local_20;

  int local_18;

  

  main_collgrid_00410200();

  pcVar17 = *(char **)(param_1 + 0x21c);

  if (pcVar17 == (char *)0x0) {

    if ((((*(uint *)(param_1 + 0x1c8) & 0x400000) != 0) &&

        ((*(uint *)(param_1 + 0x1c8) & 0x181808) == 0)) &&

       ((*(uint *)(param_1 + 0xd8) & 0x80000) != 0)) {

      fVar3 = *(float *)(param_1 + 0xa0);

      fVar4 = *(float *)(param_1 + 0xa4);

      fVar5 = *(float *)(param_1 + 0x154);

      FUN_005435a5((double)((fVar4 - fVar5) * 0.2 + 0.5));

      iVar6 = __ftol();

      FUN_005435a5((double)((fVar4 + fVar5) * 0.2 + 0.5));

      iVar7 = __ftol();

      FUN_005435a5((double)((fVar3 - fVar5) * 0.2 + 0.5));

      iVar8 = __ftol();

      FUN_005435a5((double)((fVar3 + fVar5) * 0.2 + 0.5));

      iVar9 = __ftol();

      iVar13 = param_3 + -1 + param_4;

      iVar1 = param_2 + -1 + param_4;

      if (((iVar8 <= iVar1) && (iVar6 <= iVar13)) && ((param_2 <= iVar9 && (param_3 <= iVar7)))) {

        if (iVar6 < param_3) {

          iVar6 = param_3;

        }

        if (iVar13 < iVar7) {

          iVar7 = iVar13;

        }

        if (iVar8 < param_2) {

          iVar8 = param_2;

        }

        if (iVar1 < iVar9) {

          iVar9 = iVar1;

        }

        if ((iVar8 <= iVar9) && (param_5 = (iVar6 - param_3) * param_4 + param_5, iVar6 <= iVar7)) {

          uVar10 = ((iVar9 - (iVar8 - param_2)) - param_2) + 1;

          iVar13 = (iVar7 - iVar6) + 1;

          do {

            puVar18 = (undefined4 *)((iVar8 - param_2) + param_5);

            for (uVar12 = uVar10 >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {

              *puVar18 = 0x1010101;

              puVar18 = puVar18 + 1;

            }

            for (uVar12 = uVar10 & 3; uVar12 != 0; uVar12 = uVar12 - 1) {

              *(undefined1 *)puVar18 = 1;

              puVar18 = (undefined4 *)((int)puVar18 + 1);

            }

            param_5 = param_5 + param_4;

            iVar13 = iVar13 + -1;

          } while (iVar13 != 0);

        }

      }

    }

  }

  else {

    cVar2 = *pcVar17;

    iVar13 = param_4 + -1 + param_2;

    psVar14 = (short *)(pcVar17 + 1);

    iVar1 = param_3 + -1 + param_4;

    if (cVar2 == '\x01') {

      iVar6 = (int)*psVar14;

      iVar9 = (int)*(short *)(pcVar17 + 3);

      pcVar15 = pcVar17 + 9;

      if ((((iVar6 <= iVar13) && (iVar9 <= iVar1)) && (param_2 <= *(short *)(pcVar17 + 5))) &&

         (param_3 <= *(short *)(pcVar17 + 7))) {

        param_5 = (iVar9 - param_3) * param_4 + param_5;

        while( true ) {

          pbVar16 = (byte *)(pcVar15 + 1);

          if (*pcVar15 == -0x80) break;

          iVar6 = iVar6 + *pcVar15;

          pcVar15 = pcVar15 + 2;

          if (iVar1 < iVar9) {

            return;

          }

          if (param_3 <= iVar9) {

            iVar13 = iVar6 - param_2;

            if (iVar13 < 0) {

              iVar13 = 0;

            }

            iVar7 = ((uint)*pbVar16 - param_2) + -1 + iVar6;

            if (param_4 <= iVar7) {

              iVar7 = param_4 + -1;

            }

            if (iVar13 <= iVar7) {

              uVar12 = (iVar7 - iVar13) + 1;

              puVar18 = (undefined4 *)(iVar13 + param_5);

              for (uVar10 = uVar12 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {

                *puVar18 = 0x1010101;

                puVar18 = puVar18 + 1;

              }

              for (uVar12 = uVar12 & 3; uVar12 != 0; uVar12 = uVar12 - 1) {

                *(undefined1 *)puVar18 = 1;

                puVar18 = (undefined4 *)((int)puVar18 + 1);

              }

            }

          }

          param_5 = param_5 + param_4;

          iVar9 = iVar9 + 1;

        }

      }

    }

    else if (cVar2 == '\x02') {

      iVar6 = (int)*psVar14;

      iVar7 = (int)*(short *)(pcVar17 + 3);

      pcVar17 = pcVar17 + 9;

      iVar9 = (iVar7 - param_3) * param_4 + param_5;

      while( true ) {

        pbVar16 = (byte *)(pcVar17 + 1);

        if (*pcVar17 == -0x80) break;

        iVar6 = iVar6 + *pcVar17;

        pcVar17 = pcVar17 + 2;

        if ((iVar7 < iVar1) && (param_3 <= iVar7)) {

          iVar8 = iVar6 - param_2;

          if (iVar8 < 0) {

            iVar8 = 0;

          }

          iVar11 = ((uint)*pbVar16 - param_2) + -1 + iVar6;

          if (param_4 <= iVar11) {

            iVar11 = param_4 + -1;

          }

          if (iVar8 <= iVar11) {

            uVar12 = (iVar11 - iVar8) + 1;

            puVar18 = (undefined4 *)(iVar8 + iVar9);

            for (uVar10 = uVar12 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {

              *puVar18 = 0x1010101;

              puVar18 = puVar18 + 1;

            }

            for (uVar12 = uVar12 & 3; uVar12 != 0; uVar12 = uVar12 - 1) {

              *(undefined1 *)puVar18 = 1;

              puVar18 = (undefined4 *)((int)puVar18 + 1);

            }

          }

        }

        iVar9 = iVar9 + param_4;

        iVar7 = iVar7 + 1;

      }

      iVar9 = (int)*(short *)pbVar16;

      iVar6 = (int)*(short *)(pcVar17 + 3);

      pcVar15 = pcVar17 + 9;

      if (((iVar9 <= iVar13) && (iVar6 <= iVar1)) &&

         ((param_2 <= *(short *)(pcVar17 + 5) && (param_3 <= *(short *)(pcVar17 + 7))))) {

        param_5 = (iVar6 - param_3) * param_4 + param_5;

        while( true ) {

          pbVar16 = (byte *)(pcVar15 + 1);

          if (*pcVar15 == -0x80) break;

          iVar9 = iVar9 + *pcVar15;

          pcVar15 = pcVar15 + 2;

          if (iVar1 < iVar6) {

            return;

          }

          if (param_3 <= iVar6) {

            iVar13 = iVar9 - param_2;

            if (iVar13 < 0) {

              iVar13 = 0;

            }

            iVar7 = ((uint)*pbVar16 - param_2) + -1 + iVar9;

            if (param_4 <= iVar7) {

              iVar7 = param_4 + -1;

            }

            if (iVar13 <= iVar7) {

              uVar12 = (iVar7 - iVar13) + 1;

              puVar18 = (undefined4 *)(iVar13 + param_5);

              for (uVar10 = uVar12 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {

                *puVar18 = 0x1010101;

                puVar18 = puVar18 + 1;

              }

              for (uVar12 = uVar12 & 3; uVar12 != 0; uVar12 = uVar12 - 1) {

                *(undefined1 *)puVar18 = 1;

                puVar18 = (undefined4 *)((int)puVar18 + 1);

              }

            }

          }

          param_5 = param_5 + param_4;

          iVar6 = iVar6 + 1;

        }

      }

    }

    else if (cVar2 == '\x03') {

      iVar7 = (int)*psVar14;

      iVar6 = (int)*(short *)(pcVar17 + 3);

      iVar8 = (int)*(short *)(pcVar17 + 5);

      iVar9 = (int)*(short *)(pcVar17 + 7);

      pcVar17 = pcVar17 + 9;

      if (((iVar7 <= iVar13) && (iVar6 <= iVar1)) &&

         ((param_2 <= iVar8 && ((param_3 <= iVar9 && (iVar6 <= iVar9)))))) {

        local_20 = ((iVar6 - param_3) * param_4 + param_5) - param_2;

        param_5 = iVar6;

        while (iVar6 <= iVar1) {

          if ((param_3 <= iVar6) && (iVar7 <= iVar8)) {

            iVar11 = iVar7;

            do {

              if ((((pcVar17[iVar11 - iVar7] & 1U) != 0) && (param_2 <= iVar11)) &&

                 (iVar11 <= iVar13)) {

                *(undefined1 *)(iVar11 + local_20) = 1;

              }

              iVar11 = iVar11 + 1;

            } while (iVar11 <= iVar8);

          }

          pcVar17 = pcVar17 + (iVar8 - iVar7) + 1;

          local_20 = local_20 + param_4;

          iVar6 = iVar6 + 1;

          param_5 = param_5 + 1;

          if (iVar9 < param_5) {

            return;

          }

        }

      }

    }

    else if (cVar2 == '\x04') {

      iVar9 = (int)*psVar14;

      iVar8 = (int)*(short *)(pcVar17 + 3);

      iVar7 = (int)*(short *)(pcVar17 + 5);

      iVar6 = (int)*(short *)(pcVar17 + 7);

      pcVar17 = pcVar17 + 9;

      if (((iVar9 <= iVar13) && (iVar8 <= iVar1)) &&

         ((param_2 <= iVar7 && ((param_3 <= iVar6 && (iVar8 <= iVar6)))))) {

        local_18 = ((iVar8 - param_3) * param_4 + param_5) - param_2;

        param_5 = iVar8;

        while (iVar8 <= iVar1) {

          if ((param_3 <= iVar8) && (iVar9 <= iVar7)) {

            uVar10 = 0;

            iVar11 = iVar9;

            do {

              uVar12 = uVar10 & 0x80000007;

              if ((int)uVar12 < 0) {

                uVar12 = (uVar12 - 1 | 0xfffffff8) + 1;

              }

              if ((((byte)(pcVar17[(int)(uVar10 + ((int)uVar10 >> 0x1f & 7U)) >> 3] &

                          (byte)(1 << ((byte)uVar12 & 0x1f))) != 0) && (param_2 <= iVar11)) &&

                 (iVar11 <= iVar13)) {

                *(undefined1 *)(local_18 + iVar11) = 1;

              }

              iVar11 = iVar11 + 1;

              uVar10 = uVar10 + 1;

            } while (iVar11 <= iVar7);

          }

          iVar11 = (iVar7 - iVar9) + 1;

          pcVar17 = pcVar17 + ((int)(iVar11 + (iVar11 >> 0x1f & 7U)) >> 3);

          local_18 = local_18 + param_4;

          iVar8 = iVar8 + 1;

          param_5 = param_5 + 1;

          if (iVar6 < param_5) {

            return;

          }

        }

      }

    }

    else if (cVar2 == '\x05') {

      iVar6 = (int)*psVar14;

      iVar9 = (int)*(short *)(pcVar17 + 3);

      pcVar15 = pcVar17 + 9;

      if ((((iVar6 <= iVar13) && (iVar9 <= iVar1)) && (param_2 <= *(short *)(pcVar17 + 5))) &&

         (param_3 <= *(short *)(pcVar17 + 7))) {

        param_5 = (iVar9 - param_3) * param_4 + param_5;

        while( true ) {

          pbVar16 = (byte *)(pcVar15 + 1);

          if (*pcVar15 == -0x80) break;

          iVar6 = iVar6 + *pcVar15;

          pcVar15 = pcVar15 + 2;

          if (iVar1 < iVar9) {

            return;

          }

          if (param_3 <= iVar9) {

            iVar13 = iVar6 - param_2;

            if (iVar13 < 0) {

              iVar13 = 0;

            }

            iVar7 = ((uint)*pbVar16 - param_2) + -1 + iVar6;

            if (param_4 <= iVar7) {

              iVar7 = param_4 + -1;

            }

            if (iVar13 <= iVar7) {

              uVar12 = (iVar7 - iVar13) + 1;

              puVar18 = (undefined4 *)(iVar13 + param_5);

              for (uVar10 = uVar12 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {

                *puVar18 = 0x1010101;

                puVar18 = puVar18 + 1;

              }

              for (uVar12 = uVar12 & 3; uVar12 != 0; uVar12 = uVar12 - 1) {

                *(undefined1 *)puVar18 = 1;

                puVar18 = (undefined4 *)((int)puVar18 + 1);

              }

            }

          }

          param_5 = param_5 + param_4;

          iVar9 = iVar9 + 1;

        }

      }

    }

  }

  return;

}

/* ===== FUN_00412df0 @ 0x00412DF0 ===== */
/* PS2 candidate: collide_objects__FP6OBJECT (conf 0.445) */



void FUN_00412df0(int param_1)



{

  float fVar1;

  float fVar2;

  bool bVar3;

  float fVar4;

  int iVar5;

  uint uVar6;

  int iVar7;

  float *pfVar8;

  float *pfVar9;

  float10 fVar10;

  float10 fVar11;

  int local_b8;

  float local_b0;

  float local_ac;

  float local_a8;

  float local_a4;

  float local_a0;

  float local_9c;

  undefined4 *local_98;

  float local_94;

  float local_90;

  float local_8c;

  int local_88;

  float local_84 [4];

  float local_74;

  float local_70;

  float local_6c [4];

  float local_5c;

  float local_54;

  undefined4 local_50;

  undefined4 local_4c;

  undefined4 local_48;

  undefined4 local_44;

  undefined4 local_40;

  int local_3c;

  undefined1 local_38 [4];

  undefined1 local_34 [16];

  undefined1 local_24 [4];

  int local_20;

  undefined1 local_1c [4];

  float local_18 [6];

  

  if (((((*(uint *)(param_1 + 0xd8) & 0x10000000) == 0) &&

       (*(float *)(param_1 + 0xa0) == *(float *)(param_1 + 0xac))) &&

      (*(float *)(param_1 + 0xa4) == *(float *)(param_1 + 0xb0))) &&

     (*(float *)(param_1 + 0xa8) == *(float *)(param_1 + 0xb4))) {

    return;

  }

  *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) & 0xefffffff;

  *(undefined4 *)(param_1 + 0x224) = 0;

  *(undefined4 *)(param_1 + 0x220) = 0;

  local_3c = FUN_004551b0((float *)(param_1 + 0xac),&local_50,local_38,&local_40,1);

  *(undefined4 *)(param_1 + 0x140) = local_40;

  *(undefined4 *)(param_1 + 0x144) = local_50;

  *(undefined4 *)(param_1 + 0x148) = local_4c;

  *(undefined4 *)(param_1 + 0x14c) = local_48;

  *(undefined4 *)(param_1 + 0x150) = local_44;

  if (*(int *)(param_1 + 8) != 0) {

    if ((*(uint *)(param_1 + 0x1c8) & 0x200) != 0) {

      return;

    }

    local_b8 = 1;

    iVar5 = FUN_004a61a0(param_1);

    if ((iVar5 == 0) && (iVar5 = FUN_004a61c0(param_1), iVar5 == 0)) {

      local_88 = 0;

      do {

        pfVar8 = (float *)(param_1 + 0xac);

        if (local_b8 == 0) goto LAB_004135eb;

        if ((*(uint *)(param_1 + 0x1c8) & 0x600) == 0) {

          if ((*(uint *)(param_1 + 0xd8) & 0x80000) == 0) {

            fVar2 = 0.0;

            fVar4 = 0.0;

          }

          else {

            fVar2 = 2.0;

            fVar4 = -1.0;

          }

          if (*(float *)(param_1 + 0xa0) <= *pfVar8) {

            local_84[0] = *(float *)(param_1 + 0xa0) - *(float *)(param_1 + 0x154);

            local_84[3] = *pfVar8 + *(float *)(param_1 + 0x154);

          }

          else {

            local_84[0] = *pfVar8 - *(float *)(param_1 + 0x154);

            local_84[3] = *(float *)(param_1 + 0x154) + *(float *)(param_1 + 0xa0);

          }

          if (*(float *)(param_1 + 0xa4) <= *(float *)(param_1 + 0xb0)) {

            local_84[1] = *(float *)(param_1 + 0xa4) - *(float *)(param_1 + 0x154);

            local_74 = *(float *)(param_1 + 0x154) + *(float *)(param_1 + 0xb0);

          }

          else {

            local_84[1] = *(float *)(param_1 + 0xb0) - *(float *)(param_1 + 0x154);

            local_74 = *(float *)(param_1 + 0x154) + *(float *)(param_1 + 0xa4);

          }

          if (*(float *)(param_1 + 0xa8) <= *(float *)(param_1 + 0xb4)) {

            fVar1 = *(float *)(param_1 + 0xb4);

            local_84[2] = *(float *)(param_1 + 0xa8);

          }

          else {

            fVar1 = *(float *)(param_1 + 0xa8);

            local_84[2] = *(float *)(param_1 + 0xb4);

          }

          local_70 = *(float *)(param_1 + 0xc4) * *(float *)(param_1 + 0x1ec) + fVar1;

          pfVar8 = local_84;

          pfVar9 = local_18;

          for (iVar5 = 6; iVar5 != 0; iVar5 = iVar5 + -1) {

            *pfVar9 = *pfVar8;

            pfVar8 = pfVar8 + 1;

            pfVar9 = pfVar9 + 1;

          }

          local_18[2] = local_84[2] + fVar2;

          local_84[2] = local_84[2] + fVar4;

          local_b8 = 0;

          for (local_98 = DAT_00632d7c; local_98 != (undefined4 *)0x0;

              local_98 = (undefined4 *)*local_98) {

            iVar5 = local_98[3];

            uVar6 = *(uint *)(iVar5 + 0x1c8) & 0x800;

            if ((((((*(uint *)(iVar5 + 0xd8) & 0x4000c000) == 0 && uVar6 == 0) && (uVar6 == 0)) &&

                 (param_1 != iVar5)) &&

                ((*(int *)(iVar5 + 8) != 0 &&

                 ((*(int *)(param_1 + 4) != 3 || (*(int *)(iVar5 + 4) != 3)))))) &&

               (((*(int *)(param_1 + 4) != 0x23c || (iVar7 = FUN_004a6160(iVar5), iVar7 == 0)) &&

                (((*(int *)(param_1 + 4) != 0x2ea || (iVar7 = FUN_004a61a0(iVar5), iVar7 == 0)) &&

                 (*(int *)(iVar5 + 0x210) != param_1)))))) {

              if ((*(byte *)(iVar5 + 0x1c8) & 8) == 0) {

                pfVar8 = local_18;

              }

              else {

                pfVar8 = local_84;

              }

              iVar7 = FUN_0049a3c0(pfVar8,iVar5 + 0x27c);

              if (iVar7 != 0) {

                if ((*(uint *)(iVar5 + 0x1c8) & 0x1008) == 0) {

                  pfVar8 = (float *)(param_1 + 0xa0);

                  fVar11 = (float10)FUN_0050a520(pfVar8,iVar5 + 0xa0);

                  fVar2 = (float)fVar11;

                  if ((*(uint *)(iVar5 + 0x1c8) & 0x80000) == 0) {

                    if (((fVar2 <= *(float *)(iVar5 + 0x154) + *(float *)(param_1 + 0x154)) &&

                        (*(float *)(param_1 + 0xa8) <=

                         *(float *)(iVar5 + 0x1ec) * *(float *)(iVar5 + 0xc4) +

                         *(float *)(iVar5 + 0xa8))) &&

                       (*(float *)(iVar5 + 0xa8) <=

                        *(float *)(param_1 + 0xc4) * *(float *)(param_1 + 0x1ec) +

                        *(float *)(param_1 + 0xa8))) {

                      if ((char)((uint)*(undefined4 *)(param_1 + 0x1c8) >> 8) < '\0') {

                        *pfVar8 = *(float *)(param_1 + 0xac);

                        *(undefined4 *)(param_1 + 0xa4) = *(undefined4 *)(param_1 + 0xb0);

                        *(undefined4 *)(param_1 + 0xa8) = *(undefined4 *)(param_1 + 0xb4);

                        *(uint *)(param_1 + 0xdc) = *(uint *)(param_1 + 0xdc) | 0x800;

                        *(int *)(param_1 + 0x220) = iVar5;

                        local_b8 = 1;

                        break;

                      }

                      pfVar9 = (float *)(param_1 + 0xac);

                      fVar11 = (float10)FUN_0050a5e0(pfVar9,iVar5 + 0xa0);

                      if ((float10)fVar2 * (float10)fVar2 <= fVar11) {

                        fVar11 = ((float10)*(float *)(iVar5 + 0x154) +

                                 (float10)*(float *)(param_1 + 0x154)) / SQRT(fVar11);

                        if (ABS(fVar11) <= (float10)1.0) {

                          fVar11 = (float10)FUN_0050a4f0((float)fVar11);

                          local_b0 = (float)fVar11;

                        }

                        else {

                          local_b0 = 95.0;

                        }

                        fVar11 = (float10)FUN_0050a400(pfVar9,iVar5 + 0xa0);

                        fVar2 = (float)fVar11;

                        fVar11 = (float10)FUN_0050a400(pfVar9,pfVar8);

                        fVar10 = (float10)FUN_0050a770((float)fVar11,fVar2 + local_b0);

                        local_9c = (float)fVar10;

                        fVar11 = (float10)FUN_0050a770((float)fVar11,fVar2 - local_b0);

                        if (fVar11 < (float10)local_9c) {

                          local_b0 = -local_b0;

                        }

                        FUN_0050ae40(fVar2 + local_b0,&local_54,&local_a0);

                        fVar11 = (float10)FUN_0050a520(pfVar9,pfVar8);

                        local_b8 = 1;

                        *(int *)(param_1 + 0x220) = iVar5;

                        *pfVar8 = (float)((float10)local_54 * fVar11 + (float10)*pfVar9);

                        *(float *)(param_1 + 0xa4) =

                             (float)((float10)*(float *)(param_1 + 0xb0) -

                                    (float10)local_a0 * fVar11);

                      }

                    }

                  }

                  else {

                    FUN_00517220(iVar5,param_1 + 0xa0,&local_ac);

                    fVar2 = *(float *)(param_1 + 0x154) / *(float *)(iVar5 + 0xc4);

                    pfVar8 = (float *)(*(int *)(*(int *)(iVar5 + 8) + 0x400) + 0x44);

                    pfVar9 = local_6c;

                    for (iVar7 = 6; iVar7 != 0; iVar7 = iVar7 + -1) {

                      *pfVar9 = *pfVar8;

                      pfVar8 = pfVar8 + 1;

                      pfVar9 = pfVar9 + 1;

                    }

                    iVar7 = FUN_0049a450(&local_ac,fVar2,local_6c);

                    if (iVar7 != 0) {

                      FUN_00517220(iVar5,param_1 + 0xac,&local_94);

                      local_9c = ABS(local_90 - local_5c);

                      if (ABS(local_94 - local_6c[3]) <= ABS(local_94 - local_6c[0])) {

                        fVar4 = local_6c[3] + fVar2;

                      }

                      else {

                        fVar4 = local_6c[0] - fVar2;

                      }

                      bVar3 = local_9c <= ABS(local_90 - local_6c[1]);

                      if (bVar3) {

                        fVar1 = local_5c + fVar2;

                      }

                      else {

                        fVar1 = local_6c[1] - fVar2;

                      }

                      if (ABS(local_a8 - fVar1) <= ABS(local_ac - fVar4)) {

                        if (bVar3) {

                          local_a8 = local_5c + fVar2;

                        }

                        else {

                          local_a8 = local_6c[1] - fVar2;

                        }

                      }

                      else if (ABS(local_94 - local_6c[3]) <= ABS(local_94 - local_6c[0])) {

                        local_ac = local_6c[3] + fVar2;

                      }

                      else {

                        local_ac = local_6c[0] - fVar2;

                      }

                      FUN_005170f0(iVar5,&local_ac,param_1 + 0xa0);

                      local_b8 = 1;

                      *(int *)(param_1 + 0x220) = iVar5;

                      *(uint *)(param_1 + 0xdc) = *(uint *)(param_1 + 0xdc) | 0x800;

                    }

                  }

                }

                else {

                  local_b8 = FUN_00414d40(param_1,iVar5);

                }

              }

            }

          }

        }

        else {

          local_b8 = 0;

        }

      } while ((((*(float *)(param_1 + 0xa0) != *(float *)(param_1 + 0xac)) ||

                (*(float *)(param_1 + 0xa4) != *(float *)(param_1 + 0xb0))) ||

               (*(float *)(param_1 + 0xa8) != *(float *)(param_1 + 0xb4))) &&

              (local_88 = local_88 + 1, local_88 < 5));

    }

    else {

      local_94 = *(float *)(param_1 + 0xa0) - *(float *)(param_1 + 0xac);

      iVar5 = 0;

      local_90 = *(float *)(param_1 + 0xa4) - *(float *)(param_1 + 0xb0);

      local_8c = *(float *)(param_1 + 0xa8) - *(float *)(param_1 + 0xb4);

      local_b8 = 1;

      do {

        if (local_b8 == 0) goto LAB_004135eb;

        local_ac = *(float *)(param_1 + 0xa0);

        local_a8 = *(float *)(param_1 + 0xa4);

        local_a4 = *(float *)(param_1 + 0xa8);

        local_b8 = FUN_004156f0(param_1,&local_94);

      } while ((((*(float *)(param_1 + 0xa0) != local_ac) ||

                (*(float *)(param_1 + 0xa4) != local_a8)) ||

               (*(float *)(param_1 + 0xa8) != local_a4)) && (iVar5 = iVar5 + 1, iVar5 < 5));

    }

    if (local_b8 != 0) {

      *(undefined4 *)(param_1 + 0xa0) = *(undefined4 *)(param_1 + 0xac);

      *(undefined4 *)(param_1 + 0xa4) = *(undefined4 *)(param_1 + 0xb0);

    }

LAB_004135eb:

    if (*(int *)(param_1 + 0x224) != 0) goto LAB_00413703;

  }

  if (((*(uint *)(param_1 + 0xd8) & 0x80000) == 0) ||

     (*(float *)(param_1 + 0xa8) < *(float *)(param_1 + 0xb4) ==

      (*(float *)(param_1 + 0xa8) == *(float *)(param_1 + 0xb4)))) {

    bVar3 = false;

  }

  else {

    bVar3 = true;

  }

  if (*(int *)(param_1 + 0x104) == 0) {

    if (bVar3) {

      FUN_00413970(param_1,&local_50);

    }

    else {

      FUN_00413c90(param_1,&local_50);

    }

    local_20 = FUN_004551b0(param_1 + 0xa0,local_34,local_1c,local_24,1);

    iVar5 = 0;

    if (local_20 != local_3c) {

      if (!bVar3) {

        FUN_00413c90(param_1,local_34);

        goto LAB_00413703;

      }

      iVar5 = FUN_00413970(param_1,local_34);

    }

    if (bVar3) {

      if (iVar5 != 0) {

        local_20 = FUN_004551b0(param_1 + 0xa0,local_34,local_1c,local_24,1);

      }

      FUN_00413b70(param_1,local_34);

    }

  }

  else {

    FUN_004a2220(param_1);

  }

LAB_00413703:

  fVar11 = (float10)FUN_00413e90(param_1 + 0xa0,&local_a0);

  fVar2 = (float)fVar11;

  if (((local_a0 != 0.0) && (fVar2 < *(float *)(param_1 + 0xa8))) &&

     (*(float *)(param_1 + 0x140) < fVar2)) {

    *(float *)(param_1 + 0x140) = fVar2;

    *(float *)(param_1 + 0x150) = -fVar2;

    *(undefined4 *)(param_1 + 0x148) = 0;

    *(undefined4 *)(param_1 + 0x144) = 0;

    *(undefined4 *)(param_1 + 0x14c) = 0x3f800000;

  }

  fVar2 = *(float *)(param_1 + 0x1d4) + *(float *)(param_1 + 0x140);

  if (0.1 <= ABS(fVar2 - *(float *)(param_1 + 0xa8))) {

    *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) & 0xfff7ffff;

  }

  else {

    if (*(int *)(param_1 + 0x104) == 0) {

      *(float *)(param_1 + 0xa8) = fVar2;

    }

    if ((*(uint *)(param_1 + 0xd8) & 0x80000) == 0) {

      *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) | 0x10000000;

    }

    *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) | 0x80000;

    if (*(float *)(param_1 + 0x108) < 0.0) {

      *(undefined4 *)(param_1 + 0x108) = 0;

      return;

    }

  }

  return;

}

/* ===== FUN_00413820 @ 0x00413820 ===== */
void FUN_00413820(int param_1)



{

  undefined4 local_1c;

  undefined4 local_18;

  undefined4 local_14;

  undefined4 local_10;

  undefined4 local_c [2];

  undefined1 local_4 [4];

  

  FUN_004551b0(param_1 + 0xa0,&local_1c,local_4,local_c,1);

  *(undefined4 *)(param_1 + 0x140) = local_c[0];

  *(undefined4 *)(param_1 + 0x144) = local_1c;

  *(undefined4 *)(param_1 + 0x148) = local_18;

  *(undefined4 *)(param_1 + 0x14c) = local_14;

  *(undefined4 *)(param_1 + 0x150) = local_10;

  return;

}

/* ===== FUN_00413880 @ 0x00413880 ===== */
undefined4 FUN_00413880(int param_1)



{

  if (((*(float *)(param_1 + 0x1bc) < 0.0 == (*(float *)(param_1 + 0x1bc) == 0.0)) &&

      (*(int *)(param_1 + 0x224) == 0)) && (*(float *)(param_1 + 0x14c) < 0.64278)) {

    return 1;

  }

  return 0;

}

/* ===== FUN_004138c0 @ 0x004138C0 ===== */
undefined4 FUN_004138c0(float param_1,int param_2)



{

  int iVar1;

  int iVar2;

  float10 fVar3;

  undefined1 local_10 [8];

  float local_8;

  

  iVar2 = param_2;

  iVar1 = (int)param_1;

  if ((*(float *)((int)param_1 + 0x1bc) < 0.0 == (*(float *)((int)param_1 + 0x1bc) == 0.0)) &&

     (*(int *)((int)param_1 + 0x224) == 0)) {

    fVar3 = (float10)FUN_00413e90(param_2,&param_2);

    param_1 = (float)fVar3;

    if (param_2 == 0) {

      FUN_004551b0(iVar2,local_10,0,&param_1,1);

      if (local_8 < 0.64278) {

        return 1;

      }

      if (param_1 < -(*(float *)(iVar1 + 0x1e8) * *(float *)(iVar1 + 0xc4))) {

        return 1;

      }

    }

  }

  return 0;

}

/* ===== FUN_00413970 @ 0x00413970 ===== */
undefined4 FUN_00413970(float param_1,float *param_2)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  int iVar7;

  float *pfVar8;

  float10 fVar9;

  float10 fVar10;

  

  pfVar8 = param_2;

  iVar7 = (int)param_1;

  *(uint *)((int)param_1 + 0xdc) = *(uint *)((int)param_1 + 0xdc) & 0xfffeffff;

  if ((param_2[2] < 0.64278) && (0.0 < *(float *)((int)param_1 + 0x1bc))) {

    fVar9 = (float10)FUN_00518b70(param_1,0);

    fVar1 = *param_2;

    fVar2 = *param_2;

    fVar3 = *param_2;

    fVar10 = (float10)FUN_00518b70(param_1,0);

    fVar4 = param_2[1];

    fVar5 = param_2[1];

    fVar6 = param_2[1];

    *(uint *)((int)param_1 + 0xdc) = *(uint *)((int)param_1 + 0xdc) | 0x10000;

    *(uint *)((int)param_1 + 0xd8) = *(uint *)((int)param_1 + 0xd8) | 0x10000000;

    *(float *)((int)param_1 + 0xa0) =

         (float)(fVar9 * (float10)fVar1 * (float10)fVar2 * (float10)fVar3 * (float10)30.0) +

         *(float *)((int)param_1 + 0xac);

    *(float *)((int)param_1 + 0xa4) =

         (float)(fVar10 * (float10)fVar4 * (float10)fVar5 * (float10)fVar6 * (float10)30.0 +

                (float10)*(float *)((int)param_1 + 0xb0));

    return 1;

  }

  if (param_2[2] < 0.9659) {

    fVar1 = 1.0 - *param_2 * *param_2 * *(float *)((int)param_1 + 0x1bc) * 0.02;

    param_2 = (float *)(1.0 - param_2[1] * param_2[1] * *(float *)((int)param_1 + 0x1bc) * 0.02);

    param_1 = fVar1;

    if (fVar1 < 0.2) {

      param_1 = 0.2;

    }

    if ((float)param_2 < 0.2) {

      param_2 = (float *)0x3e4ccccd;

    }

    fVar1 = *(float *)(iVar7 + 0xa0) - *(float *)(iVar7 + 0xac);

    fVar2 = *(float *)(iVar7 + 0xa4) - *(float *)(iVar7 + 0xb0);

    if (((0.0 < fVar1) && (*pfVar8 < 0.0)) || ((fVar1 < 0.0 && (0.0 < *pfVar8)))) {

      fVar1 = fVar1 * param_1;

    }

    if (((0.0 < fVar2) && (pfVar8[1] < 0.0)) || ((fVar2 < 0.0 && (0.0 < pfVar8[1])))) {

      fVar2 = fVar2 * (float)param_2;

    }

    *(float *)(iVar7 + 0xa0) = fVar1 + *(float *)(iVar7 + 0xac);

    *(float *)(iVar7 + 0xa4) = fVar2 + *(float *)(iVar7 + 0xb0);

    return 1;

  }

  return 0;

}

/* ===== FUN_00413b70 @ 0x00413B70 ===== */
void FUN_00413b70(float param_1,undefined4 *param_2)



{

  float *pfVar1;

  float fVar2;

  int iVar3;

  float10 fVar4;

  float10 fVar5;

  float10 fVar6;

  float local_c;

  undefined4 local_8;

  float local_4;

  

  iVar3 = (int)param_1;

  pfVar1 = (float *)((int)param_1 + 0xa0);

  local_c = *pfVar1;

  local_8 = *(undefined4 *)((int)param_1 + 0xa4);

  local_4 = *(float *)((int)param_1 + 0xa8);

  fVar4 = (float10)FUN_0050a730(param_2,local_c,local_8);

  local_4 = (float)fVar4;

  fVar4 = (float10)FUN_00431e30(&local_c);

  if (fVar4 < (float10)-61.1) {

    fVar4 = (float10)-61.1;

  }

  fVar5 = -((float10)*(float *)((int)param_1 + 0x1e8) * (float10)*(float *)((int)param_1 + 0xc4));

  fVar6 = fVar4;

  if (fVar4 < fVar5) {

    fVar6 = fVar5;

  }

  param_1 = (float)fVar6;

  fVar2 = ABS(*pfVar1 - *(float *)(iVar3 + 0xac)) +

          ABS(*(float *)(iVar3 + 0xa4) - *(float *)(iVar3 + 0xb0));

  if (fVar2 < 3.0) {

    if (DAT_00632b90 < 1) {

      fVar2 = 3.0;

    }

    else {

      fVar2 = *(float *)(DAT_00632ed8 + 0x418);

    }

  }

  param_1 = param_1 + *(float *)(iVar3 + 0x1d4);

  if (*(float *)(iVar3 + 0xa8) - fVar2 < param_1) {

    *(float *)(iVar3 + 0xa8) = param_1;

  }

  *(float *)(iVar3 + 0x140) = (float)fVar4;

  *(undefined4 *)(iVar3 + 0x144) = *param_2;

  *(undefined4 *)(iVar3 + 0x148) = param_2[1];

  *(undefined4 *)(iVar3 + 0x14c) = param_2[2];

  *(undefined4 *)(iVar3 + 0x150) = param_2[3];

  return;

}

/* ===== FUN_00413c90 @ 0x00413C90 ===== */
void FUN_00413c90(int param_1)



{

  float *pfVar1;

  float fVar2;

  float fVar3;

  float10 fVar4;

  float10 fVar5;

  float local_1c;

  float local_18;

  float local_14;

  undefined4 local_10;

  float local_c;

  undefined4 local_8;

  undefined1 local_4 [4];

  

  pfVar1 = (float *)(param_1 + 0xa0);

  local_8 = FUN_004551b0(pfVar1,&local_1c,local_4,&local_c,1);

  if (*(float *)(param_1 + 0x140) < local_c) {

    *(float *)(param_1 + 0x140) = local_c;

    *(float *)(param_1 + 0x144) = local_1c;

    *(float *)(param_1 + 0x148) = local_18;

    *(float *)(param_1 + 0x14c) = local_14;

    *(undefined4 *)(param_1 + 0x150) = local_10;

    if (((*(float *)(param_1 + 0xa8) < local_c != (*(float *)(param_1 + 0xa8) == local_c)) &&

        (local_14 < 0.64278)) && (0.0 < *(float *)(param_1 + 0x1bc))) {

      fVar4 = (float10)FUN_00518b70(param_1,0);

      fVar5 = (float10)FUN_00518b70(param_1,0);

      *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) | 0x10000000;

      *pfVar1 = (float)(fVar4 * (float10)local_1c * (float10)local_1c * (float10)local_1c *

                       (float10)30.0) + *(float *)(param_1 + 0xac);

      *(float *)(param_1 + 0xa4) =

           (float)(fVar5 * (float10)local_18 * (float10)local_18 * (float10)local_18 * (float10)30.0

                  + (float10)*(float *)(param_1 + 0xb0));

      return;

    }

  }

  if (*(float *)(param_1 + 0x140) < -61.1) {

    *(undefined4 *)(param_1 + 0x140) = 0xc2746666;

  }

  fVar3 = -(*(float *)(param_1 + 0x1e8) * *(float *)(param_1 + 0xc4));

  fVar2 = *(float *)(param_1 + 0x140);

  if (*(float *)(param_1 + 0x140) < fVar3) {

    fVar2 = fVar3;

  }

  fVar2 = fVar2 + *(float *)(param_1 + 0x1d4);

  if (*(float *)(param_1 + 0xa8) < fVar2) {

    if ((char)((uint)*(undefined4 *)(param_1 + 0x1c8) >> 8) < '\0') {

      FUN_004146c0(param_1,pfVar1);

      *(uint *)(param_1 + 0xdc) = *(uint *)(param_1 + 0xdc) | 0x800;

      return;

    }

    *(float *)(param_1 + 0xa8) = fVar2;

    return;

  }

  return;

}

/* ===== FUN_00413e40 @ 0x00413E40 ===== */
/* PS2 candidate: get_floor_z_point (conf 0.526) */



float10 FUN_00413e40(undefined4 param_1)



{

  float fVar1;

  float10 fVar2;

  undefined1 local_1c [16];

  float local_c [2];

  undefined1 local_4 [4];

  

  FUN_004551b0(param_1,local_1c,local_4,local_c,1);

  fVar1 = local_c[0];

  fVar2 = (float10)FUN_00413e90(param_1,0);

  if (fVar2 <= (float10)local_c[0]) {

    fVar2 = (float10)fVar1;

  }

  return fVar2;

}

/* ===== FUN_00413e90 @ 0x00413E90 ===== */
/* PS2 candidate: get_floor_z_point_plat (conf 0.366) */



float10 FUN_00413e90(float *param_1,int *param_2)



{

  float fVar1;

  float fVar2;

  ushort uVar3;

  ushort uVar4;

  float fVar5;

  bool bVar6;

  int iVar7;

  int iVar8;

  float *pfVar9;

  int iVar10;

  int iVar11;

  int iVar12;

  float local_b8;

  undefined4 *local_b4;

  float local_b0;

  float local_ac;

  float local_a8;

  float local_a4;

  undefined4 *local_a0;

  float local_9c;

  float local_98;

  float local_94;

  int local_90;

  float local_8c;

  int local_88;

  int local_84;

  undefined4 local_80;

  int local_7c;

  int local_78;

  int local_74;

  undefined4 local_70;

  float local_6c;

  undefined4 local_68;

  float local_64;

  float local_60;

  float local_5c;

  float local_58;

  float local_54;

  float local_50;

  float local_4c [5];

  float local_38;

  undefined4 local_34;

  float local_28;

  undefined1 local_24 [36];

  

  local_b8 = -61.1;

  FUN_005435a5((double)(*param_1 * 0.2 + 0.5));

  local_34 = __ftol();

  FUN_005435a5((double)(param_1[1] * 0.2 + 0.5));

  local_68 = __ftol();

  local_a0 = DAT_00632d7c;

  if (param_2 != (int *)0x0) {

    *param_2 = 0;

    local_a0 = DAT_00632d7c;

  }

  for (; local_a0 != (undefined4 *)0x0; local_a0 = (undefined4 *)*local_a0) {

    iVar11 = local_a0[3];

    if ((((((*(uint *)(iVar11 + 0x1c8) & 8) != 0) &&

          ((*(uint *)(iVar11 + 0xd8) & 0x4000c000) == 0 && (*(uint *)(iVar11 + 0x1c8) & 0x800) == 0)

          ) && (*param_1 - 0.5 <= *(float *)(iVar11 + 0x288))) &&

        ((param_1[1] - 0.5 <= *(float *)(iVar11 + 0x28c) &&

         (*(float *)(iVar11 + 0x27c) <= *param_1 + 0.5)))) &&

       ((*(float *)(iVar11 + 0x280) <= param_1[1] + 0.5 &&

        (local_90 = iVar11, iVar7 = FUN_00412570(iVar11,local_34,local_68), iVar7 != 0)))) {

      FUN_00516f30(iVar11,local_24);

      iVar7 = FUN_0042b1a0(iVar11);

      iVar7 = *(int *)(*(int *)(iVar11 + 8) + 0x400 + iVar7 * 4);

      local_7c = 0;

      local_84 = iVar7;

      if (0 < *(int *)(iVar7 + 0x68)) {

        local_b4 = (undefined4 *)(iVar7 + 0x84);

        do {

          local_70 = *local_b4;

          local_80 = 0xffff;

          iVar8 = FUN_00430e10(&local_70,&local_80,&local_78,&local_74,&local_88);

          if (iVar8 != 0) {

            iVar8 = iVar11 + 0xa0;

            do {

              iVar11 = *(int *)(iVar7 + 0x34);

              iVar7 = *(int *)(iVar7 + 0x14);

              uVar3 = *(ushort *)(iVar11 + local_74 * 2);

              uVar4 = *(ushort *)(iVar11 + local_88 * 2);

              FUN_00517080(local_24,iVar8,iVar7 + (uint)*(ushort *)(iVar11 + local_78 * 2) * 0xc,

                           &local_9c);

              FUN_00517080(local_24,iVar8,iVar7 + (uint)uVar3 * 0xc,&local_58);

              FUN_00517080(local_24,iVar8,iVar7 + (uint)uVar4 * 0xc,&local_64);

              local_8c = local_60 - local_98;

              local_b0 = (local_5c - local_94) * (local_54 - local_98) -

                         (local_50 - local_94) * local_8c;

              local_6c = local_64 - local_9c;

              local_ac = local_6c * (local_50 - local_94) -

                         (local_58 - local_9c) * (local_5c - local_94);

              local_a8 = (local_58 - local_9c) * local_8c - local_6c * (local_54 - local_98);

              FUN_0050a810(&local_b0,&local_ac,&local_a8);

              local_a4 = -(local_a8 * local_94 + local_ac * local_98 + local_9c * local_b0);

              if (((0.64278 <= local_a8) &&

                  (fVar5 = local_a8 * param_1[2] + local_b0 * *param_1 + local_ac * param_1[1] +

                           local_a4, fVar5 <= 10.0)) && (-1.0 <= fVar5)) {

                fVar1 = *param_1;

                fVar2 = param_1[1];

                local_28 = param_1[2] - fVar5 / local_a8;

                if (local_b8 <= local_28) {

                  bVar6 = false;

                  local_4c[0] = local_9c - fVar1;

                  local_4c[1] = local_98 - fVar2;

                  local_4c[2] = local_58 - fVar1;

                  local_4c[3] = local_54 - fVar2;

                  local_4c[4] = local_64 - fVar1;

                  local_38 = local_60 - fVar2;

                  if (0.0 <= local_98 - fVar2) {

                    iVar11 = 1;

                  }

                  else {

                    iVar11 = -1;

                  }

                  iVar7 = 1;

                  pfVar9 = local_4c;

                  do {

                    iVar10 = iVar7;

                    if (2 < iVar7) {

                      iVar10 = 0;

                    }

                    if (0.0 <= local_4c[iVar10 * 2 + 1]) {

                      iVar12 = 1;

                    }

                    else {

                      iVar12 = -1;

                    }

                    if ((iVar11 != iVar12) &&

                       (((iVar11 = iVar12, 0.0 <= *pfVar9 && (0.0 <= local_4c[iVar10 * 2])) ||

                        (((0.0 <= *pfVar9 || (0.0 <= local_4c[iVar10 * 2])) &&

                         (((local_4c[iVar10 * 2] - *pfVar9) * pfVar9[1]) /

                          (local_4c[iVar10 * 2 + 1] - pfVar9[1]) < *pfVar9)))))) {

                      bVar6 = (bool)(bVar6 ^ 1);

                    }

                    iVar7 = iVar7 + 1;

                    pfVar9 = pfVar9 + 2;

                  } while (iVar10 != 0);

                  if ((bVar6) && (local_b8 = local_28, param_2 != (int *)0x0)) {

                    *param_2 = local_90;

                  }

                }

              }

              iVar10 = FUN_00430e10(&local_70,&local_80,&local_78,&local_74,&local_88);

              iVar11 = local_90;

              iVar7 = local_84;

            } while (iVar10 != 0);

          }

          local_7c = local_7c + 1;

          local_b4 = local_b4 + 0x14;

        } while (local_7c < *(int *)(iVar7 + 0x68));

      }

    }

  }

  return (float10)local_b8;

}

/* ===== FUN_004143f0 @ 0x004143F0 ===== */
float10 FUN_004143f0(undefined4 param_1)



{

  undefined1 local_1c [16];

  float local_c [2];

  undefined1 local_4 [4];

  

  FUN_004551b0(param_1,local_1c,local_4,local_c,1);

  return (float10)local_c[0];

}

/* ===== FUN_00414420 @ 0x00414420 ===== */
uint FUN_00414420(int param_1,float *param_2,int param_3,int param_4,int param_5)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  int iVar7;

  int iVar8;

  uint uVar9;

  

  if (ABS(*param_2) <= ABS(param_2[1])) {

    if (ABS(param_2[2]) < ABS(param_2[1])) {

      iVar7 = 0;

      iVar8 = 2;

      goto LAB_0041447d;

    }

  }

  else if (ABS(param_2[2]) < ABS(*param_2)) {

    iVar7 = 1;

    iVar8 = 2;

    goto LAB_0041447d;

  }

  iVar7 = 0;

  iVar8 = 1;

LAB_0041447d:

  fVar1 = *(float *)(param_3 + iVar7 * 4) - *(float *)(param_1 + iVar7 * 4);

  fVar2 = *(float *)(param_3 + iVar8 * 4) - *(float *)(param_1 + iVar8 * 4);

  fVar3 = *(float *)(param_4 + iVar7 * 4) - *(float *)(param_1 + iVar7 * 4);

  fVar4 = *(float *)(param_4 + iVar8 * 4) - *(float *)(param_1 + iVar8 * 4);

  fVar5 = *(float *)(param_5 + iVar7 * 4) - *(float *)(param_1 + iVar7 * 4);

  fVar6 = *(float *)(param_5 + iVar8 * 4) - *(float *)(param_1 + iVar8 * 4);

  uVar9 = 0;

  if ((0.0 <= fVar2 != 0.0 <= fVar4) &&

     (((0.0 <= fVar1 && (0.0 <= fVar3)) ||

      (((0.0 <= fVar1 || (0.0 <= fVar3)) &&

       (0.0 < fVar1 - ((fVar3 - fVar1) * fVar2) / (fVar4 - fVar2))))))) {

    uVar9 = 1;

  }

  if ((0.0 <= fVar6 != 0.0 <= fVar4) &&

     (((0.0 <= fVar5 && (0.0 <= fVar3)) ||

      (((0.0 <= fVar5 || (0.0 <= fVar3)) &&

       (0.0 < fVar5 - ((fVar3 - fVar5) * fVar6) / (fVar4 - fVar6))))))) {

    uVar9 = uVar9 + 1;

  }

  if ((0.0 <= fVar2 != 0.0 <= fVar6) &&

     (((0.0 <= fVar1 && (0.0 <= fVar5)) ||

      (((0.0 <= fVar1 || (0.0 <= fVar5)) &&

       (0.0 < fVar1 - ((fVar5 - fVar1) * fVar2) / (fVar6 - fVar2))))))) {

    uVar9 = uVar9 + 1;

  }

  return uVar9 & 1;

}

/* ===== FUN_00414680 @ 0x00414680 ===== */
float10 FUN_00414680(int param_1)



{

  return (float10)*(float *)(param_1 + 0x140);

}

/* ===== FUN_00414690 @ 0x00414690 ===== */
/* PS2 candidate: get_grid_ground_info (conf 0.4) */



void FUN_00414690(undefined4 param_1,int param_2)



{

  undefined4 uVar1;

  

  uVar1 = FUN_004551b0(param_1,param_2,param_2 + 0x18,param_2 + 0x10,1);

  *(undefined4 *)(param_2 + 0x14) = uVar1;

  return;

}

/* ===== FUN_004146c0 @ 0x004146C0 ===== */
void FUN_004146c0(float param_1,float *param_2)



{

  float *pfVar1;

  float *pfVar2;

  float fVar3;

  float fVar4;

  int iVar5;

  float local_1c;

  float local_18;

  float local_14;

  float local_10;

  undefined1 local_c [4];

  undefined4 local_8;

  undefined1 local_4 [4];

  

  iVar5 = (int)param_1;

  pfVar1 = (float *)((int)param_1 + 0xac);

  pfVar2 = (float *)((int)param_1 + 0xa0);

  local_8 = FUN_004551b0(pfVar1,&local_1c,local_4,local_c,1);

  fVar3 = local_1c * *pfVar1 +

          local_18 * *(float *)((int)param_1 + 0xb0) + local_14 * *(float *)((int)param_1 + 0xb4) +

          local_10;

  fVar4 = local_18 * *(float *)((int)param_1 + 0xa4) +

          local_14 * *(float *)((int)param_1 + 0xa8) + local_1c * *pfVar2 + local_10;

  if (0.0 < fVar3 * fVar4) {

    FUN_004551b0(pfVar2,&local_1c,local_4,local_c,1);

    fVar4 = local_18 * *(float *)((int)param_1 + 0xa4) +

            local_14 * *(float *)((int)param_1 + 0xa8) + local_1c * *pfVar2 + local_10;

    fVar3 = local_1c * *pfVar1 +

            local_18 * *(float *)((int)param_1 + 0xb0) + local_14 * *(float *)((int)param_1 + 0xb4)

            + local_10;

  }

  param_1 = fVar3;

  if (0.0 < param_1 * fVar4) {

    *param_2 = *pfVar2;

    param_2[1] = *(float *)(iVar5 + 0xa4);

    param_2[2] = *(float *)(iVar5 + 0xa8);

    return;

  }

  fVar3 = (*pfVar2 - *pfVar1) * local_1c +

          (*(float *)(iVar5 + 0xa4) - *(float *)(iVar5 + 0xb0)) * local_18 +

          (*(float *)(iVar5 + 0xa8) - *(float *)(iVar5 + 0xb4)) * local_14;

  if (fVar3 == 0.0) {

    fVar3 = 0.0;

  }

  else {

    fVar3 = -(param_1 / fVar3);

  }

  *param_2 = (*pfVar2 - *pfVar1) * fVar3 + *pfVar1;

  param_2[1] = (*(float *)(iVar5 + 0xa4) - *(float *)(iVar5 + 0xb0)) * fVar3 +

               *(float *)(iVar5 + 0xb0);

  param_2[2] = (*(float *)(iVar5 + 0xa8) - *(float *)(iVar5 + 0xb4)) * fVar3 +

               *(float *)(iVar5 + 0xb4);

  return;

}

/* ===== FUN_00414840 @ 0x00414840 ===== */
void FUN_00414840(int param_1)



{

  undefined4 local_1c;

  undefined4 local_18;

  undefined4 local_14;

  undefined4 local_10;

  undefined4 local_c [2];

  undefined1 local_4 [4];

  

  FUN_004148a0(param_1);

  FUN_004551b0(param_1 + 0xa0,&local_1c,local_4,local_c,1);

  *(undefined4 *)(param_1 + 0x140) = local_c[0];

  *(undefined4 *)(param_1 + 0x144) = local_1c;

  *(undefined4 *)(param_1 + 0x148) = local_18;

  *(undefined4 *)(param_1 + 0x14c) = local_14;

  *(undefined4 *)(param_1 + 0x150) = local_10;

  return;

}

/* ===== FUN_004148a0 @ 0x004148A0 ===== */
void FUN_004148a0(int param_1)



{

  float fVar1;

  float fVar2;

  int iVar3;

  float fVar4;

  float *pfVar5;

  

  if (*(float *)(param_1 + 0x1fc) == 0.0) {

    iVar3 = *(int *)(*(int *)(param_1 + 8) + 0xc);

    if (iVar3 == 0) {

      fVar4 = 0.5;

      pfVar5 = (float *)(*(int *)(*(int *)(param_1 + 8) + 0x400) + 0x44);

    }

    else {

      fVar4 = 0.85;

      pfVar5 = (float *)(iVar3 + 0xc);

    }

    fVar1 = -*pfVar5;

    if (fVar1 < pfVar5[3]) {

      fVar1 = pfVar5[3];

    }

    fVar2 = -pfVar5[1];

    if (fVar2 < pfVar5[4]) {

      fVar2 = pfVar5[4];

    }

    *(float *)(param_1 + 0x154) =

         SQRT(fVar1 * fVar1 + fVar2 * fVar2) * fVar4 * *(float *)(param_1 + 0xc4);

  }

  else {

    *(float *)(param_1 + 0x154) = *(float *)(param_1 + 0x1fc) * *(float *)(param_1 + 0xc4);

  }

  if (*(float *)(param_1 + 0x1f8) != 0.0) {

    fVar4 = *(float *)(param_1 + 0x1f8) * *(float *)(param_1 + 0xc4) - 1.0;

    if (fVar4 < 0.5) {

      fVar4 = 0.5;

    }

    if (fVar4 < *(float *)(param_1 + 0x154)) {

      *(float *)(param_1 + 0x154) = fVar4;

      return;

    }

  }

  return;

}

/* ===== FUN_00414990 @ 0x00414990 ===== */
void FUN_00414990(int param_1,float *param_2,float *param_3)



{

  bool bVar1;

  float fVar2;

  int *piVar3;

  uint uVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  float10 fVar8;

  float local_40;

  int local_3c;

  int *local_38;

  int local_34;

  float local_30;

  float local_2c;

  int local_28;

  float local_24;

  float local_20;

  float local_1c;

  undefined1 local_18 [8];

  float local_10;

  

  if (param_2 == (float *)0x0) {

    local_1c = param_3[2];

    local_20 = 9999.0;

    local_24 = 9999.0;

  }

  else {

    local_24 = *param_2;

    local_20 = param_2[1];

    local_1c = param_2[2];

  }

  local_3c = 4;

  while ((FUN_0049c550(param_1 + 0xa0,param_3,*(undefined4 *)(param_1 + 0x154)),

         piVar3 = DAT_00632d7c,

         *(float *)(param_1 + 0x1bc) < 0.0 == (*(float *)(param_1 + 0x1bc) == 0.0) &&

         (piVar3 = DAT_00632d7c, *(int *)(param_1 + 0x224) == 0))) {

    fVar8 = (float10)FUN_00413e90(param_3);

    local_38 = (int *)(float)fVar8;

    piVar3 = DAT_00632d7c;

    if ((local_34 != 0) ||

       ((FUN_004551b0(param_3,local_18,0,&local_38), 0.64278 <= local_10 &&

        (piVar3 = DAT_00632d7c,

        -(*(float *)(param_1 + 0x1e8) * *(float *)(param_1 + 0xc4)) <= (float)local_38)))) break;

    fVar8 = (float10)FUN_0050a400();

    FUN_0050ae40((float)fVar8,&local_30,&local_2c);

    *param_3 = local_30 * *(float *)(DAT_006330e4 + 0x1c0) * 0.25 + *param_3;

    param_3[1] = param_3[1] - local_2c * *(float *)(DAT_006330e4 + 0x1c0) * 0.25;

    bVar1 = local_3c < 1;

    local_3c = local_3c + -1;

    piVar3 = DAT_00632d7c;

    if (bVar1) break;

  }

  do {

    local_38 = piVar3;

    if (local_38 == (int *)0x0) {

      return;

    }

    iVar6 = local_38[3];

    uVar4 = *(uint *)(iVar6 + 0x1c8) & 0x800;

    if (((((*(uint *)(iVar6 + 0xd8) & 0x4000c000) == 0 && uVar4 == 0) && (uVar4 == 0)) &&

        (((local_34 = iVar6, iVar5 = FUN_004a61a0(), iVar5 == 0 &&

          (iVar5 = FUN_004a61c0(), iVar5 == 0)) || ((*(byte *)(iVar6 + 0x1cc) & 1) == 0)))) &&

       (((param_1 != iVar6 && (*(int *)(iVar6 + 8) != 0)) && (*(int *)(iVar6 + 0x210) != param_1))))

    {

      FUN_005435a5((double)(*param_3 * 0.2 + 0.5));

      iVar6 = __ftol();

      FUN_005435a5((double)(param_3[1] * 0.2 + 0.5));

      iVar5 = __ftol();

      iVar7 = FUN_00412180(local_34,iVar6,iVar5);

      while (iVar7 != 0) {

        FUN_005435a5((double)(*param_2 * 0.2 + 0.5));

        local_28 = __ftol();

        FUN_005435a5((double)(param_2[1] * 0.2 + 0.5));

        iVar7 = __ftol();

        if ((iVar6 == local_28) && (iVar5 == iVar7)) {

          return;

        }

        if (local_28 < iVar6) {

          local_28 = iVar6 + -1;

LAB_00414c3a:

          local_40 = ((float)local_28 * 5.0 - *param_2) / (*param_3 - *param_2);

        }

        else {

          if (iVar6 < local_28) {

            local_28 = iVar6 + 1;

            goto LAB_00414c3a;

          }

          local_40 = 0.0;

        }

        if (iVar7 < iVar5) {

          local_28 = iVar5 + -1;

LAB_00414c70:

          fVar2 = ((float)local_28 * 5.0 - param_2[1]) / (param_3[1] - param_2[1]);

        }

        else {

          if (iVar5 < iVar7) {

            local_28 = iVar5 + 1;

            goto LAB_00414c70;

          }

          fVar2 = 0.0;

        }

        if (fVar2 <= local_40) {

          fVar2 = local_40;

        }

        *param_3 = (*param_3 - *param_2) * fVar2 + *param_2;

        param_3[1] = (param_3[1] - param_2[1]) * fVar2 + param_2[1];

        FUN_005435a5((double)(*param_3 * 0.2 + 0.5));

        iVar6 = __ftol();

        FUN_005435a5((double)(param_3[1] * 0.2 + 0.5));

        iVar5 = __ftol();

        iVar7 = FUN_00412180(local_34,iVar6,iVar5);

      }

    }

    piVar3 = (int *)*local_38;

  } while( true );

}

/* ===== FUN_00414d40 @ 0x00414D40 ===== */
undefined4 FUN_00414d40(int param_1,int param_2)



{

  float fVar1;

  ushort uVar2;

  ushort uVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  int iVar8;

  int iVar9;

  int iVar10;

  uint uVar11;

  float local_ac;

  float local_a8;

  float local_a4;

  float local_a0;

  float local_9c;

  float local_98;

  float local_94;

  float local_90;

  float local_8c;

  float local_88;

  float local_84;

  float local_80;

  float local_7c;

  undefined4 local_78;

  float local_74;

  float local_70;

  float local_6c;

  undefined4 *local_68;

  float local_64;

  float local_60;

  float local_5c;

  int local_58;

  undefined4 local_54;

  int local_50;

  int local_4c;

  int local_48;

  undefined4 local_44;

  int local_40;

  float local_3c;

  float local_38;

  float local_34;

  float local_30;

  float local_2c;

  float local_28;

  undefined1 local_24 [36];

  

  local_78 = 0;

  iVar8 = FUN_0042b1d0(param_2);

  FUN_0042b010(iVar8);

  main_animate_00404b60(param_2,0xffffffff);

  FUN_0042b030();

  FUN_00516f30(param_2,local_24);

  iVar8 = *(int *)(*(int *)(param_2 + 8) + 0x400 + iVar8 * 4);

  local_48 = 0;

  if (*(int *)(iVar8 + 0x68) < 1) {

    return 0;

  }

  local_68 = (undefined4 *)(iVar8 + 0x84);

  local_50 = iVar8;

  do {

    iVar10 = local_48;

    iVar9 = FUN_00513b60(param_2,iVar8,local_48);

    if (iVar9 == 0) {

      local_44 = *local_68;

      local_54 = 0xffff;

      iVar9 = FUN_00430e10(&local_44,&local_54,&local_58,&local_40,&local_4c);

      while (iVar9 != 0) {

        iVar10 = *(int *)(iVar8 + 0x34);

        iVar9 = *(int *)(iVar8 + 0x14);

        uVar2 = *(ushort *)(iVar10 + local_40 * 2);

        uVar3 = *(ushort *)(iVar10 + local_4c * 2);

        iVar8 = param_2 + 0xa0;

        FUN_00517080(local_24,iVar8,iVar9 + (uint)*(ushort *)(iVar10 + local_58 * 2) * 0xc,&local_74

                    );

        FUN_00517080(local_24,iVar8,iVar9 + (uint)uVar2 * 0xc,&local_30);

        FUN_00517080(local_24,iVar8,iVar9 + (uint)uVar3 * 0xc,&local_3c);

        local_98 = local_38 - local_70;

        local_ac = (local_34 - local_6c) * (local_2c - local_70) - local_98 * (local_28 - local_6c);

        local_94 = local_3c - local_74;

        local_a8 = local_94 * (local_28 - local_6c) - (local_30 - local_74) * (local_34 - local_6c);

        local_a4 = (local_30 - local_74) * local_98 - local_94 * (local_2c - local_70);

        FUN_0050a810(&local_ac,&local_a8,&local_a4);

        local_a0 = -(local_a4 * local_6c + local_a8 * local_70 + local_74 * local_ac);

        fVar4 = ABS(local_a4);

        uVar11 = *(uint *)(param_1 + 0x1c8) & 0x8000;

        if ((uVar11 != 0) || (fVar4 < 0.75)) {

          local_8c = *(float *)(param_1 + 0x1e8) * *(float *)(param_1 + 0xc4);

          local_90 = local_a8 * *(float *)(param_1 + 0xb0) +

                     local_ac * *(float *)(param_1 + 0xac) +

                     (local_8c + *(float *)(param_1 + 0xb4)) * local_a4 + local_a0;

          fVar1 = local_a8 * *(float *)(param_1 + 0xa4) +

                  local_ac * *(float *)(param_1 + 0xa0) +

                  (local_8c + *(float *)(param_1 + 0xa8)) * local_a4 + local_a0;

          if ((0.0 <= fVar1 - *(float *)(param_1 + 0x154)) || (local_90 <= 0.0)) goto LAB_0041529b;

          local_98 = *(float *)(param_1 + 0xa8) - *(float *)(param_1 + 0xb4);

          local_94 = *(float *)(param_1 + 0xa4) - *(float *)(param_1 + 0xb0);

          local_7c = *(float *)(param_1 + 0xa0) - *(float *)(param_1 + 0xac);

          fVar5 = local_7c * local_ac + local_98 * local_a4 + local_94 * local_a8;

          if (fVar5 == 0.0) {

            local_9c = 0.0;

          }

          else {

            local_9c = -(local_90 / fVar5);

          }

          local_88 = local_7c * local_9c + *(float *)(param_1 + 0xac);

          local_84 = local_94 * local_9c + *(float *)(param_1 + 0xb0);

          local_80 = local_98 * local_9c + local_8c + *(float *)(param_1 + 0xb4);

          iVar8 = FUN_00414420(&local_88,&local_ac,&local_74,&local_30,&local_3c);

          if (iVar8 != 0) {

            if (uVar11 == 0) {

              if (0.0 <= local_90) {

                fVar1 = *(float *)(param_1 + 0x154) - fVar1;

              }

              else {

                fVar1 = -(fVar1 + *(float *)(param_1 + 0x154));

              }

              local_64 = local_ac * fVar1 + *(float *)(param_1 + 0xa0);

              local_60 = fVar1 * local_a8 + *(float *)(param_1 + 0xa4);

              local_5c = fVar1 * local_a4 + *(float *)(param_1 + 0xa8);

              if (((local_64 != *(float *)(param_1 + 0xa0)) ||

                  (local_60 != *(float *)(param_1 + 0xa4))) ||

                 (local_5c != *(float *)(param_1 + 0xa8))) {

                *(float *)(param_1 + 0xa0) = local_64;

                *(float *)(param_1 + 0xa4) = local_60;

                *(float *)(param_1 + 0xa8) = local_5c;

                local_78 = 1;

                *(int *)(param_1 + 0x220) = param_2;

              }

              goto LAB_0041529b;

            }

            if (local_9c <= 0.99) {

              local_9c = local_9c - 0.01;

              *(uint *)(param_1 + 0xdc) = *(uint *)(param_1 + 0xdc) | 0x800;

              *(int *)(param_1 + 0x220) = param_2;

              local_78 = 1;

              local_80 = local_98 * local_9c + local_8c + *(float *)(param_1 + 0xb4);

              *(float *)(param_1 + 0xa0) = local_7c * local_9c + *(float *)(param_1 + 0xac);

              *(float *)(param_1 + 0xa4) = local_94 * local_9c + *(float *)(param_1 + 0xb0);

              *(float *)(param_1 + 0xa8) = local_80 - local_8c;

            }

          }

          goto LAB_0041566c;

        }

LAB_0041529b:

        if (0.5 < fVar4) {

          fVar1 = *(float *)(param_1 + 0xa8);

          if (fVar1 < *(float *)(param_1 + 0xb4)) {

            fVar1 = *(float *)(param_1 + 0xb4);

          }

          local_8c = *(float *)(param_1 + 0x1e8) * *(float *)(param_1 + 0xc4);

          fVar7 = local_8c * 0.4;

          local_98 = (fVar7 + fVar1) - *(float *)(param_1 + 0x1d4);

          fVar6 = local_a8 * *(float *)(param_1 + 0xa4);

          fVar5 = local_ac * *(float *)(param_1 + 0xa0);

          local_90 = local_a4 * local_98 + fVar5 + fVar6 + local_a0;

          if (0.0 <= (((fVar1 - 100.0) - *(float *)(param_1 + 0x1d4)) * local_a4 + fVar5 + fVar6 +

                     local_a0) * local_90) goto LAB_00415478;

          fVar1 = local_8c * -0.3 - fVar7;

          fVar5 = local_a4 * fVar1;

          if (fVar5 == 0.0) {

            fVar5 = 0.0;

          }

          else {

            fVar5 = -(local_90 / fVar5);

          }

          local_88 = *(float *)(param_1 + 0xa0);

          local_84 = *(float *)(param_1 + 0xa4);

          local_80 = fVar5 * fVar1 + local_98;

          if ((*(float *)(param_1 + 0x140) <= local_80) &&

             (iVar8 = FUN_00414420(&local_88,&local_ac,&local_74,&local_30,&local_3c), iVar8 != 0))

          {

            local_5c = local_80 + *(float *)(param_1 + 0x1d4);

            *(float *)(param_1 + 0x144) = local_ac;

            *(float *)(param_1 + 0x140) = local_80;

            *(float *)(param_1 + 0x148) = local_a8;

            *(float *)(param_1 + 0x14c) = local_a4;

            *(float *)(param_1 + 0x150) = local_a0;

            if ((*(float *)(param_1 + 0x108) <= 0.0) &&

               (*(float *)(param_1 + 0xa8) - local_5c <= fVar7)) {

              if (*(int *)(param_1 + 0x104) != 0) {

                *(undefined4 *)(param_1 + 0x130) = 0;

              }

              if (local_5c != *(float *)(param_1 + 0xa8)) {

                *(float *)(param_1 + 0xa8) = local_5c;

                local_78 = 1;

              }

              *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) | 0x80000;

              goto LAB_00415478;

            }

          }

        }

        else {

LAB_00415478:

          if ((0.6 < fVar4) && ((*(uint *)(param_1 + 0xd8) & 0x80000) == 0)) {

            fVar4 = *(float *)(param_1 + 0x1e8) * *(float *)(param_1 + 0xc4);

            local_90 = local_a8 * *(float *)(param_1 + 0xb0) +

                       local_ac * *(float *)(param_1 + 0xac) +

                       (fVar4 + *(float *)(param_1 + 0xb4)) * local_a4 + local_a0;

            fVar1 = *(float *)(param_1 + 0x1ec) * *(float *)(param_1 + 0xc4);

            if ((local_a8 * *(float *)(param_1 + 0xa4) +

                 local_ac * *(float *)(param_1 + 0xa0) +

                 (fVar1 + *(float *)(param_1 + 0xa8)) * local_a4 + local_a0) * local_90 < 0.0) {

              fVar6 = *(float *)(param_1 + 0xa8) - *(float *)(param_1 + 0xb4);

              local_94 = *(float *)(param_1 + 0xa4) - *(float *)(param_1 + 0xb0);

              local_7c = *(float *)(param_1 + 0xa0) - *(float *)(param_1 + 0xac);

              fVar5 = local_7c * local_ac + fVar6 * local_a4 + local_94 * local_a8;

              if (fVar5 == 0.0) {

                fVar5 = 0.0;

              }

              else {

                fVar5 = -(local_90 / fVar5);

              }

              local_88 = local_7c * fVar5 + *(float *)(param_1 + 0xac);

              local_84 = local_94 * fVar5 + *(float *)(param_1 + 0xb0);

              local_80 = fVar6 * fVar5 + fVar4 + *(float *)(param_1 + 0xb4);

              iVar8 = FUN_00414420(&local_88,&local_ac,&local_74,&local_30,&local_3c);

              if ((iVar8 != 0) &&

                 (((fVar1 = local_80 - fVar1, local_88 != *(float *)(param_1 + 0xa0) ||

                   (local_84 != *(float *)(param_1 + 0xa4))) ||

                  (fVar1 != *(float *)(param_1 + 0xa8))))) {

                *(float *)(param_1 + 0xa0) = local_88;

                *(float *)(param_1 + 0xa4) = local_84;

                if ((*(float *)(param_1 + 0xa8) <= fVar1) ||

                   (*(float *)(param_1 + 0xa8) = fVar1, *(float *)(param_1 + 0x108) <= 0.0)) {

                  local_78 = 1;

                }

                else {

                  *(undefined4 *)(param_1 + 0x108) = 0;

                  local_78 = 1;

                }

              }

            }

          }

        }

LAB_0041566c:

        iVar9 = FUN_00430e10(&local_44,&local_54,&local_58,&local_40,&local_4c);

        iVar8 = local_50;

        iVar10 = local_48;

      }

    }

    local_48 = iVar10 + 1;

    local_68 = local_68 + 0x14;

    if (*(int *)(iVar8 + 0x68) <= local_48) {

      return local_78;

    }

  } while( true );

}

/* ===== FUN_004156f0 @ 0x004156F0 ===== */
/* PS2 candidate: collide_objects_kabuto__FP6OBJECTP3P3D (conf 0.376) */



undefined4 FUN_004156f0(int param_1,float *param_2)



{

  int iVar1;

  bool bVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  uint uVar6;

  int iVar7;

  float *pfVar8;

  float *pfVar9;

  int iVar10;

  float *pfVar11;

  float10 fVar12;

  float10 fVar13;

  int local_b8;

  undefined4 local_b4;

  undefined4 local_b0;

  uint local_ac;

  float local_a8;

  float local_a4;

  float local_9c;

  undefined4 *local_98;

  float local_94;

  float local_90;

  float local_8c;

  float local_88;

  float local_84;

  undefined4 local_80;

  float local_7c;

  float local_78 [4];

  float local_68;

  float local_60;

  undefined4 local_5c;

  undefined4 local_58;

  undefined4 local_54;

  float local_50;

  float local_4c;

  undefined4 local_48;

  undefined4 local_44;

  undefined4 local_40;

  undefined4 local_3c;

  undefined4 local_38;

  float local_34;

  undefined4 local_30;

  undefined4 local_2c;

  float local_28;

  float local_24;

  float local_8;

  

  local_b0 = 0;

  local_60 = *(float *)(param_1 + 0xc4) * 20.0 + *(float *)(param_1 + 0xa8);

  local_50 = *(float *)(param_1 + 0xc4) * 35.0 + *(float *)(param_1 + 0xa8);

  local_98 = DAT_00632d7c;

  do {

    if (local_98 == (undefined4 *)0x0) {

      return local_b0;

    }

    iVar1 = local_98[3];

    uVar6 = *(uint *)(iVar1 + 0x1c8) & 0x800;

    if ((((((*(uint *)(iVar1 + 0xd8) & 0x4000c000) == 0 && uVar6 == 0) && (uVar6 == 0)) &&

         ((*(byte *)(iVar1 + 0x1cc) & 1) == 0)) &&

        ((param_1 != iVar1 && (*(int *)(iVar1 + 8) != 0)))) && (*(int *)(iVar1 + 0x210) != param_1))

    {

      local_9c = *(float *)(iVar1 + 0x290);

      if (local_9c <= local_50) {

        if ((local_60 < local_9c) || (20.0 < *(float *)(iVar1 + 0x154) * *(float *)(param_1 + 0xc4))

           ) {

          local_28 = *(float *)(param_1 + 0xc4) * 75.0;

          local_34 = *(float *)(param_1 + 0xa0);

          local_30 = *(undefined4 *)(param_1 + 0xa4);

          local_24 = *(float *)(param_1 + 0xc4) * 20.0;

          local_2c = *(undefined4 *)(param_1 + 0xa8);

          local_b4 = 2;

          goto LAB_0041591e;

        }

        local_b8 = 2;

        pfVar8 = (float *)register0x00000010;

        iVar7 = 0x88;

        do {

          iVar10 = iVar7 + -0x44;

          local_40 = *(undefined4 *)(iVar7 + 0x1ec + *(int *)(param_1 + 0x2dc));

          iVar7 = iVar10 + *(int *)(param_1 + 0x2dc);

          local_3c = *(undefined4 *)(iVar7 + 0x240);

          local_38 = *(undefined4 *)(iVar7 + 0x250);

          (*(code *)PTR_FUN_00580c20)(pfVar8 + -8,&local_40,1,param_1 + 0x294);

          pfVar8[-5] = *(float *)(param_1 + 0xc4) * 20.0;

          pfVar8[-4] = *(float *)(param_1 + 0xc4) * 10.0;

          pfVar8 = pfVar8 + -5;

          iVar7 = iVar10;

        } while (iVar10 != 0);

        local_b4 = 1;

        local_ac = 0;

      }

      else {

        local_28 = *(float *)(param_1 + 0xc4) * 75.0;

        local_34 = *(float *)(param_1 + 0xa0);

        local_30 = *(undefined4 *)(param_1 + 0xa4);

        local_24 = *(float *)(param_1 + 0xc4) * 25.0;

        local_2c = *(undefined4 *)(param_1 + 0xa8);

        local_b4 = 4;

LAB_0041591e:

        local_b8 = 1;

        local_ac = 1;

      }

      pfVar8 = &local_34;

      if ((*(uint *)(iVar1 + 0x1c8) & 0x80000) == 0) {

        do {

          while( true ) {

            if (local_b8 == 0) goto LAB_00415d47;

            local_b8 = local_b8 + -1;

            if ((pfVar8[2] < local_9c) && (*(float *)(iVar1 + 0xa8) < pfVar8[3] + pfVar8[2])) break;

LAB_00415d68:

            pfVar8 = pfVar8 + 5;

          }

          fVar12 = (float10)FUN_0050a520(pfVar8,iVar1 + 0xa0);

          if ((*(float *)(iVar1 + 0x154) + pfVar8[4]) - (float)fVar12 < 0.0) goto LAB_00415d68;

          uVar6 = FUN_0045bd90(param_1,iVar1,local_b4);

          local_ac = local_ac & uVar6;

          if (local_ac == 0) goto LAB_00415d47;

          local_8c = pfVar8[2];

          local_94 = *pfVar8 - (*(float *)(param_1 + 0xa0) - *(float *)(param_1 + 0xac));

          local_90 = pfVar8[1] - (*(float *)(param_1 + 0xa4) - *(float *)(param_1 + 0xb0));

          fVar13 = (float10)FUN_0050a520(&local_94,iVar1 + 0xa0);

        } while (fVar13 < (float10)(float)fVar12);

        local_88 = local_94 - *(float *)(iVar1 + 0xa0);

        local_84 = local_90 - *(float *)(iVar1 + 0xa4);

        local_80 = 0;

        FUN_0050a810(&local_88,&local_84,&local_80);

        pfVar9 = (float *)(param_1 + 0xa0);

        local_4c = *pfVar9;

        local_48 = *(undefined4 *)(param_1 + 0xa4);

        local_44 = *(undefined4 *)(param_1 + 0xa8);

        local_5c = *(undefined4 *)(param_1 + 0x128);

        local_58 = *(undefined4 *)(param_1 + 300);

        local_54 = *(undefined4 *)(param_1 + 0x130);

        local_7c = -(local_84 * *(float *)(iVar1 + 0xa4) + local_88 * *(float *)(iVar1 + 0xa0)) -

                   (*(float *)(iVar1 + 0x154) + pfVar8[4]);

        FUN_004a17f0(param_1,pfVar8,&local_88);

        if ((*pfVar9 - *(float *)(param_1 + 0xac)) * *param_2 +

            (*(float *)(param_1 + 0xa4) - *(float *)(param_1 + 0xb0)) * param_2[1] < 0.0) {

          *pfVar9 = local_4c;

          *(undefined4 *)(param_1 + 0xa4) = local_48;

          *(undefined4 *)(param_1 + 0xa8) = local_44;

          *(undefined4 *)(param_1 + 0x128) = local_5c;

          *(undefined4 *)(param_1 + 300) = local_58;

          *(undefined4 *)(param_1 + 0x130) = local_54;

        }

LAB_00415d36:

        local_b0 = 1;

        *(int *)(param_1 + 0x220) = iVar1;

      }

      else {

        while (local_b8 != 0) {

          local_b8 = local_b8 + -1;

          FUN_00517220(iVar1,pfVar8,&local_a8);

          pfVar9 = (float *)(*(int *)(*(int *)(iVar1 + 8) + 0x400) + 0x44);

          pfVar11 = local_78;

          for (iVar7 = 6; iVar7 != 0; iVar7 = iVar7 + -1) {

            *pfVar11 = *pfVar9;

            pfVar9 = pfVar9 + 1;

            pfVar11 = pfVar11 + 1;

          }

          fVar3 = pfVar8[4] / *(float *)(iVar1 + 0xc4);

          iVar7 = FUN_0049a450(&local_a8,fVar3,local_78);

          if (iVar7 != 0) {

            uVar6 = FUN_0045bd90(param_1,iVar1,local_b4);

            if ((local_ac & uVar6) != 0) {

              fVar3 = fVar3 + 0.1;

              if (ABS(local_a8 - local_78[3]) <= ABS(local_a8 - local_78[0])) {

                fVar4 = local_78[3] + fVar3;

              }

              else {

                fVar4 = local_78[0] - fVar3;

              }

              bVar2 = ABS(local_a4 - local_68) <= ABS(local_a4 - local_78[1]);

              if (bVar2) {

                fVar5 = local_68 + fVar3;

              }

              else {

                fVar5 = local_78[1] - fVar3;

              }

              if (ABS(local_a4 - fVar5) <= ABS(local_a8 - fVar4)) {

                if (bVar2) {

                  local_a4 = local_68 + fVar3;

                }

                else {

                  local_a4 = local_78[1] - fVar3;

                }

              }

              else if (ABS(local_a8 - local_78[3]) <= ABS(local_a8 - local_78[0])) {

                local_a8 = local_78[3] + fVar3;

              }

              else {

                local_a8 = local_78[0] - fVar3;

              }

              FUN_005170f0(iVar1,&local_a8,&local_94);

              fVar3 = ((local_94 - *pfVar8) + *(float *)(param_1 + 0xa0)) -

                      *(float *)(param_1 + 0xac);

              local_8 = ((local_90 - pfVar8[1]) + *(float *)(param_1 + 0xa4)) -

                        *(float *)(param_1 + 0xb0);

              if (0.0 <= fVar3 * *param_2 + local_8 * param_2[1]) {

                *(float *)(param_1 + 0xa0) = fVar3 + *(float *)(param_1 + 0xac);

                *(float *)(param_1 + 0xa4) = local_8 + *(float *)(param_1 + 0xb0);

              }

              goto LAB_00415d36;

            }

            break;

          }

          pfVar8 = pfVar8 + 5;

        }

      }

    }

LAB_00415d47:

    local_98 = (undefined4 *)*local_98;

  } while( true );

}

/* ===== FUN_00415d80 @ 0x00415D80 ===== */
/* PS2 candidate: collide_camera_check_walls (conf 0.463) */



void FUN_00415d80(float *param_1,float *param_2)



{

  ushort uVar1;

  float fVar2;

  float fVar3;

  uint uVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  float10 fVar9;

  float local_b0;

  float local_ac;

  float local_a8;

  float local_a4;

  float local_a0;

  undefined4 *local_9c;

  int local_98;

  float local_94;

  undefined4 *local_90;

  float local_8c;

  float local_88;

  float local_84;

  undefined4 local_80;

  int local_7c;

  int local_78;

  int local_74;

  int local_70;

  undefined4 local_6c;

  float local_68;

  float local_64;

  float local_60;

  float local_5c;

  float local_58;

  float local_54;

  float local_50;

  float local_4c;

  float local_48;

  float local_44;

  int local_40;

  float local_3c;

  float local_38;

  float local_34;

  float local_30;

  float local_2c;

  float local_28;

  undefined1 local_24 [36];

  

  local_4c = *param_2;

  if (*param_1 <= *param_2) {

    local_58 = *param_1;

  }

  else {

    local_58 = local_4c;

    local_4c = *param_1;

  }

  local_48 = param_2[1];

  if (param_1[1] <= param_2[1]) {

    local_54 = param_1[1];

  }

  else {

    local_54 = local_48;

    local_48 = param_1[1];

  }

  local_44 = param_2[2];

  local_9c = DAT_00632d7c;

  if (param_1[2] <= param_2[2]) {

    local_50 = param_1[2];

  }

  else {

    local_50 = local_44;

    local_44 = param_1[2];

  }

  for (; local_9c != (undefined4 *)0x0; local_9c = (undefined4 *)*local_9c) {

    iVar7 = local_9c[3];

    uVar4 = *(uint *)(iVar7 + 0x1c8) & 0x800;

    if ((((((*(uint *)(iVar7 + 0xd8) & 0x4000c000) == 0 && uVar4 == 0) && (uVar4 == 0)) &&

         (*(int *)(iVar7 + 8) != 0)) &&

        ((iVar7 != DAT_00632a88 &&

         ((*(int *)(iVar7 + 0x210) == 0 || (*(int *)(iVar7 + 0x210) != DAT_00632a88)))))) &&

       (((*(uint *)(iVar7 + 0x1c8) & 0x1008) != 0 &&

        (local_40 = iVar7, iVar5 = FUN_0049a3c0(&local_58,iVar7 + 0x27c), iVar5 != 0)))) {

      FUN_00516f30(iVar7,local_24);

      iVar5 = FUN_0042b1d0(iVar7);

      iVar5 = *(int *)(*(int *)(iVar7 + 8) + 0x400 + iVar5 * 4);

      local_98 = 0;

      local_78 = iVar5;

      if (0 < *(int *)(iVar5 + 0x68)) {

        local_90 = (undefined4 *)(iVar5 + 0x84);

        do {

          iVar6 = FUN_00513b60(iVar7,iVar5,local_98);

          if (iVar6 == 0) {

            local_6c = *local_90;

            local_80 = 0xffff;

            iVar6 = FUN_00430e10(&local_6c,&local_80,&local_70,&local_74,&local_7c);

            if (iVar6 != 0) {

              iVar6 = iVar7 + 0xa0;

              do {

                iVar7 = *(int *)(iVar5 + 0x34);

                iVar5 = *(int *)(iVar5 + 0x14);

                uVar1 = *(ushort *)(iVar7 + local_74 * 2);

                local_a0 = (float)(iVar5 + (uint)*(ushort *)(iVar7 + local_7c * 2) * 0xc);

                FUN_00517080(local_24,iVar6,iVar5 + (uint)*(ushort *)(iVar7 + local_70 * 2) * 0xc,

                             &local_8c);

                FUN_00517080(local_24,iVar6,iVar5 + (uint)uVar1 * 0xc,&local_3c);

                FUN_00517080(local_24,iVar6,local_a0,&local_30);

                local_a0 = local_2c - local_88;

                local_b0 = (local_28 - local_84) * (local_38 - local_88) -

                           (local_34 - local_84) * local_a0;

                local_68 = local_3c - local_8c;

                local_ac = (local_30 - local_8c) * (local_34 - local_84) -

                           local_68 * (local_28 - local_84);

                local_a8 = local_68 * local_a0 - (local_30 - local_8c) * (local_38 - local_88);

                FUN_0050a810(&local_b0,&local_ac,&local_a8);

                local_a4 = -(local_a8 * local_84 + local_ac * local_88 + local_8c * local_b0);

                fVar2 = local_a8 * param_2[2] + local_b0 * *param_2 + local_ac * param_2[1] +

                        local_a4;

                if ((local_b0 * *param_1 + local_a8 * param_1[2] + local_ac * param_1[1] + local_a4)

                    * fVar2 < 0.0) {

                  fVar3 = (param_1[1] - param_2[1]) * local_ac +

                          (param_1[2] - param_2[2]) * local_a8 + (*param_1 - *param_2) * local_b0;

                  if (fVar3 == 0.0) {

                    local_94 = 0.0;

                  }

                  else {

                    local_94 = -(fVar2 / fVar3);

                  }

                  fVar9 = (float10)FUN_0050a580(param_1,param_2);

                  if ((float10)4.0 / fVar9 <= (float10)local_94) {

                    fVar9 = (float10)local_94;

                  }

                  else {

                    fVar9 = (float10)FUN_0050a580(param_1,param_2);

                    fVar9 = (float10)4.0 / fVar9;

                  }

                  local_64 = (float)(((float10)*param_1 - (float10)*param_2) * fVar9 +

                                    (float10)*param_2);

                  local_60 = (float)(((float10)param_1[1] - (float10)param_2[1]) * fVar9 +

                                    (float10)param_2[1]);

                  local_5c = (float)(((float10)param_1[2] - (float10)param_2[2]) * fVar9 +

                                    (float10)param_2[2]);

                  iVar7 = FUN_00414420(&local_64,&local_b0,&local_8c,&local_3c,&local_30);

                  if (iVar7 != 0) {

                    *param_1 = local_64;

                    param_1[1] = local_60;

                    param_1[2] = local_5c;

                  }

                }

                iVar8 = FUN_00430e10(&local_6c,&local_80,&local_70,&local_74,&local_7c);

                iVar7 = local_40;

                iVar5 = local_78;

              } while (iVar8 != 0);

            }

          }

          local_98 = local_98 + 1;

          local_90 = local_90 + 0x14;

        } while (local_98 < *(int *)(iVar5 + 0x68));

      }

    }

  }

  return;

}

/* ===== FUN_00416240 @ 0x00416240 ===== */
void FUN_00416240(int param_1)



{

  int iVar1;

  int iVar2;

  

  iVar1 = param_1;

  if ((param_1 != 0) && (DAT_00632bbc != 0)) {

    iVar2 = FUN_0052aa70();

    if (iVar2 != 0) {

      iVar2 = FUN_0052e480(DAT_00632bbc);

      if (iVar2 == 0) {

        param_1 = *(undefined4 *)(iVar1 + 0x188);

        FUN_00530d70(DAT_00632bbc,0,1,0,5,&param_1);

        return;

      }

      *(undefined4 *)(*(int *)(DAT_00632bbc + 0x100) + 0x56c) = *(undefined4 *)(iVar1 + 0x188);

    }

    FUN_004162c0(iVar1);

  }

  return;

}

/* ===== FUN_004162c0 @ 0x004162C0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* PS2 candidate: evilreaper_award_item__FP6OBJECT (conf 0.492) */



void FUN_004162c0(int param_1)



{

  int iVar1;

  float10 fVar2;

  undefined4 uVar3;

  

  if (DAT_00632bbc == 0) {

    return;

  }

  DAT_00632bb0 = 1;

  DAT_00633020 = 0;

  DAT_0065755c = FUN_005160a0();

  iVar1 = FUN_005160a0();

  if (7 < iVar1) {

    FUN_00515f60(7);

  }

  FUN_00426F40(&LAB_00416630,&LAB_00416b40);

  FUN_00426FA0();

  *(undefined1 *)(param_1 + 0x20a) = 0;

  *(undefined1 *)(param_1 + 0x20b) = 0;

  *(undefined1 *)(param_1 + 0x208) = 0;

  iVar1 = FUN_004a6160(param_1);

  if (iVar1 == 0) {

    iVar1 = FUN_004a6180(param_1);

    if (iVar1 != 0) {

      FUN_004c4880(param_1);

    }

  }

  else {

    FUN_00480a60();

    *(uint *)(param_1 + 0x20c) = *(uint *)(param_1 + 0x20c) & 0xfffffbff;

  }

  FUN_00495920(0x652);

  FUN_0040d6b0(&DAT_00657510);

  fVar2 = (float10)FUN_0040d6d0();

  DAT_0065751c = (float)fVar2;

  fVar2 = (float10)FUN_0040d6e0();

  DAT_00657520 = (float)fVar2;

  DAT_00657524 = 0;

  _DAT_00657560 = 0x3f800000;

  DAT_00657534 = *(undefined4 *)(DAT_00632bbc + 200);

  DAT_00657538 = 0xc2700000;

  DAT_0065753c = 0;

  _DAT_0065750c = 0x4428c000;

  DAT_00657508 = 1;

  DAT_00657500 = 0;

  _DAT_00657504 = 0;

  _DAT_00657674 = 0;

  iVar1 = FUN_0052aa70();

  if (iVar1 == 0) {

    iVar1 = FUN_004a6160(DAT_00632a88);

    if (iVar1 != 0) {

      uVar3 = 0x248;

      goto LAB_00416450;

    }

  }

  else if (((*(int *)(DAT_00632bbc + 0x18c) == 1) && (DAT_00632a88 != 0)) ||

          (*(int *)(DAT_00632bbc + 0x18c) == 2)) {

    uVar3 = 0x248;

    goto LAB_00416450;

  }

  uVar3 = 0x2e6;

LAB_00416450:

  DAT_00657564 = FUN_00496c00(uVar3,0);

  if (DAT_00657564 != 0) {

    *(undefined4 *)(DAT_00657564 + 0xa0) = 0x47c34f80;

    *(undefined4 *)(DAT_00657564 + 0xa4) = 0x47c34f80;

    *(undefined4 *)(DAT_00657564 + 0xa8) = 0x47c34f80;

    *(undefined4 *)(DAT_00657564 + 0x184) = 0x3f800000;

    *(undefined4 *)(DAT_00657564 + 0xe8) = 10;

    *(undefined4 *)(DAT_00657564 + 0xe4) = 0x33;

    *(uint *)(DAT_00657564 + 0xd8) = *(uint *)(DAT_00657564 + 0xd8) | 0x10;

  }

  main_status_00500520(&DAT_00632900);

  DAT_0063291c = 0xf;

  DAT_00632920 = 0xffffffff;

  DAT_00632924 = DAT_00632e84;

  DAT_00632928 = DAT_00632e88;

  iVar1 = FUN_004a6200(DAT_00632bbc);

  if (iVar1 == 0) {

    iVar1 = FUN_004a6290(DAT_00632bbc);

    if (iVar1 != 0) {

      FUN_004b6800(0);

    }

  }

  else {

    FUN_0040a7b0(0);

  }

  fVar2 = (float10)FUN_00515d90();

  DAT_00584370 = (float)fVar2;

  fVar2 = (float10)FUN_00515da0();

  DAT_00584328 = (float)fVar2;

  FUN_005163e0();

  return;

}

/* ===== FUN_00416550 @ 0x00416550 ===== */
void FUN_00416550(void)



{

  int iVar1;

  int iVar2;

  int iVar3;

  undefined4 local_4;

  

  iVar1 = DAT_00632bbc;

  iVar3 = *(int *)(DAT_00632bbc + 0x100);

  iVar2 = FUN_0052aa70();

  if (iVar2 != 0) {

    local_4 = 0;

    FUN_00530bd0(iVar1,0,1,0,6,&local_4);

  }

  *(undefined4 *)(iVar3 + 0x56c) = 0;

  FUN_00515f60(DAT_0065755c);

  FUN_00426fd0(&LAB_00416630);

  DAT_00632bb0 = 0;

  iVar3 = FUN_004a6200(iVar1);

  if (iVar3 == 0) {

    iVar3 = FUN_004a6290(iVar1);

    if (iVar3 != 0) {

      FUN_004b6800(1);

    }

  }

  else {

    FUN_0040a7b0(1);

  }

  if (DAT_00657564 != 0) {

    FUN_00497510(DAT_00657564);

  }

  DAT_00657564 = 0;

  DAT_00657508 = 0;

  FUN_0040d790();

  FUN_005162b0(&DAT_00584330);

  FUN_005160b0(DAT_00584370,DAT_00584328,1);

  FUN_00516850();

  return;

}

/* ===== FUN_00416990 @ 0x00416990 ===== */
void FUN_00416990(int param_1,int param_2,int param_3,int param_4)



{

  int iVar1;

  int local_c;

  undefined4 local_8;

  undefined4 local_4;

  

  iVar1 = FUN_004a6200(param_1);

  if (iVar1 == 0) {

    iVar1 = FUN_004a6290(param_1);

    if (iVar1 != 0) {

      FUN_004b65a0(param_3,param_2);

    }

  }

  else {

    FUN_0040a550(param_3,param_2);

  }

  if ((param_4 != 0) && (iVar1 = FUN_0052e4a0(param_1), iVar1 != 0)) {

    local_8 = *(undefined4 *)(param_3 + 0x188);

    local_c = param_2;

    local_4 = *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x100) + 0x20 + param_2 * 0x1c) + 0x188);

    FUN_00530bd0(param_1,0,3,0,0xc,&local_c);

  }

  return;

}

/* ===== FUN_00416a30 @ 0x00416A30 ===== */
void FUN_00416a30(undefined4 param_1,undefined4 param_2)



{

  int iVar1;

  

  iVar1 = FUN_004a6200(param_1);

  if (iVar1 != 0) {

    FUN_0040a5e0(param_1,param_2);

    return;

  }

  FUN_004b6630(param_1,param_2);

  return;

}

/* ===== FUN_00416a70 @ 0x00416A70 ===== */
undefined4

FUN_00416a70(float param_1,float param_2,float param_3,float param_4,float param_5,float param_6,

            float param_7,float param_8)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  

  fVar4 = param_8;

  fVar3 = param_7;

  fVar2 = param_4;

  fVar1 = param_3;

  if (param_3 < param_1) {

    param_3 = param_1;

    param_1 = fVar1;

  }

  if (param_4 < param_2) {

    param_4 = param_2;

    param_2 = fVar2;

  }

  if (param_7 < param_5) {

    param_7 = param_5;

    param_5 = fVar3;

  }

  if (param_8 < param_6) {

    param_8 = param_6;

    param_6 = fVar4;

  }

  if (param_7 < param_1) {

    return 0;

  }

  if (param_8 < param_2) {

    return 0;

  }

  if (param_3 < param_5) {

    return 0;

  }

  if (param_4 < param_6) {

    return 0;

  }

  return 1;

}

/* ===== FUN_004171d0 @ 0x004171D0 ===== */
void FUN_004171d0(float param_1,float param_2,float param_3)



{

  float fVar1;

  float fVar2;

  int iVar3;

  float local_14;

  float local_10;

  float local_c;

  float local_8;

  float local_4;

  

  fVar2 = param_1;

  if (DAT_00633188 < 6) {

    iVar3 = FUN_005168f0((int)param_1 + 0xa0,&local_14,&param_1);

    if (iVar3 == 0) {

      fVar1 = 1.0 / (float)DAT_00632e84;

      local_4 = fVar1 * 10.0;

      local_8 = 1.0 / (float)DAT_00632e88;

      local_c = local_8 + local_8;

      if (fVar2 == DAT_00632bbc) {

        param_1 = param_1 + 20.0;

        local_4 = fVar1 * 80.0;

        local_c = local_c + local_c;

      }

      local_10 = local_4 * 0.5;

      local_14 = fVar1 * local_14;

      param_1 = local_8 * param_1;

      FUN_0042ebf0(0x7700,local_14 - local_10,local_10 + local_14,local_8 * 5.0 + param_1,

                   local_c + local_8 * 5.0 + param_1);

      local_8 = local_14 - local_10;

      FUN_0042ebf0(0xff00,local_8,(param_2 / param_3) * local_4 + local_8,

                   5.0 / (float)DAT_00632e88 + param_1,local_c + 5.0 / (float)DAT_00632e88 + param_1

                  );

    }

  }

  return;

}

/* ===== FUN_00417330 @ 0x00417330 ===== */
void FUN_00417330(float param_1,float param_2,float param_3,float param_4,float param_5)



{

  float fVar1;

  int iVar2;

  float local_10;

  float local_c;

  float local_8;

  float local_4;

  

  if (DAT_00633188 < 6) {

    iVar2 = FUN_005168f0((int)param_1 + 0xa0,&param_1,&local_10);

    if (iVar2 == 0) {

      param_1 = param_1 * (1.0 / (float)DAT_00632e84);

      fVar1 = 1.0 / (float)DAT_00632e88;

      local_10 = local_10 * fVar1;

      local_4 = param_3 * 0.02;

      local_8 = local_4 / (float)DAT_00632e88;

      local_c = local_8 * 0.5;

      fVar1 = fVar1 * 20.0;

      FUN_0042ebf0(0x7700,fVar1 + param_1,(1.0 / (float)DAT_00632e84) * 4.0 + fVar1 + param_1,

                   local_10 - local_c,local_c + local_10);

      local_c = local_10 - local_c;

      FUN_0042ebf0(0xff00,20.0 / (float)DAT_00632e88 + param_1,

                   4.0 / (float)DAT_00632e84 + 20.0 / (float)DAT_00632e88 + param_1,local_c,

                   (param_2 / param_3) * local_8 + local_c);

      local_8 = local_4 / (float)DAT_00632e88;

      local_c = local_8 * 0.5;

      fVar1 = 24.0 / (float)DAT_00632e88;

      FUN_0042ebf0(0x777777,fVar1 + param_1,2.0 / (float)DAT_00632e84 + fVar1 + param_1,

                   local_10 - local_c,local_c + local_10);

      if (0.0 < param_4) {

        local_c = local_10 - local_c;

        FUN_0042ebf0(0xffffff,24.0 / (float)DAT_00632e88 + param_1,

                     2.0 / (float)DAT_00632e84 + 24.0 / (float)DAT_00632e88 + param_1,local_c,

                     (param_4 / param_5) * local_8 + local_c);

      }

    }

  }

  return;

}

/* ===== FUN_004177a0 @ 0x004177A0 ===== */
int FUN_004177a0(int param_1)



{

  int iVar1;

  undefined4 *puVar2;

  int iVar3;

  

  puVar2 = DAT_00632d9c;

  while( true ) {

    if (puVar2 == (undefined4 *)0x0) {

      return 0;

    }

    iVar1 = puVar2[3];

    iVar3 = FUN_004a6200(iVar1);

    if (((iVar3 != 0) || (iVar3 = FUN_004a6290(iVar1), iVar3 != 0)) &&

       (*(int *)(iVar1 + 0x18c) == param_1)) break;

    puVar2 = (undefined4 *)*puVar2;

  }

  return iVar1;

}

/* ===== FUN_004177f0 @ 0x004177F0 ===== */
void FUN_004177f0(undefined4 param_1,undefined4 param_2)



{

  int iVar1;

  

  iVar1 = FUN_004a6200(param_1);

  if (iVar1 != 0) {

    FUN_0040ab60(param_1,param_2);

    return;

  }

  iVar1 = FUN_004a6290(param_1);

  if (iVar1 != 0) {

    FUN_004b6bb0(param_1,param_2);

  }

  return;

}

/* ===== FUN_00417830 @ 0x00417830 ===== */
undefined4 FUN_00417830(int param_1)



{

  int iVar1;

  

  iVar1 = *(int *)(*(int *)(param_1 + 0x100) + 0x1c);

  if (iVar1 < 0) {

    return 0;

  }

  if (*(int *)(param_1 + 0x274) == 0) {

    return 0;

  }

  return *(undefined4 *)(iVar1 * 0x1c + 0x20 + *(int *)(*(int *)(param_1 + 0x274) + 0x100));

}

/* ===== FUN_00417860 @ 0x00417860 ===== */
undefined4 FUN_00417860(int param_1)



{

  return *(undefined4 *)(*(int *)(param_1 + 0x100) + 0x564);

}

/* ===== FUN_00417880 @ 0x00417880 ===== */
undefined4 FUN_00417880(float param_1,float param_2)



{

  float fVar1;

  float *pfVar2;

  int iVar3;

  int iVar4;

  undefined4 uVar5;

  float10 fVar6;

  

  iVar3 = (int)param_1;

  uVar5 = 0;

  iVar4 = FUN_004a6200(param_1);

  if (iVar4 == 0) {

    iVar4 = FUN_004a6220(param_1);

    if (iVar4 != 0) goto LAB_004178ce;

    iVar4 = FUN_004a6290(param_1);

    if (iVar4 != 0) {

LAB_004178c6:

      fVar6 = (float10)FUN_004b6d60(param_1);

      goto LAB_004178d4;

    }

    iVar4 = FUN_004a6300(param_1);

    if (iVar4 != 0) goto LAB_004178c6;

    param_1 = 50.0;

  }

  else {

LAB_004178ce:

    fVar6 = (float10)FUN_0040ad30(param_1);

LAB_004178d4:

    param_1 = (float)fVar6;

  }

  pfVar2 = *(float **)(iVar3 + 0x100);

  iVar4 = FUN_004a6200(iVar3);

  if (iVar4 == 0) {

    iVar4 = FUN_004a6290(iVar3);

    if (iVar4 != 0) goto LAB_00417900;

    fVar1 = *pfVar2;

  }

  else {

LAB_00417900:

    fVar1 = pfVar2[0x166];

  }

  if (param_1 - 1.0 < param_2 + fVar1 != (param_1 - 1.0 == param_2 + fVar1)) {

    pfVar2 = *(float **)(iVar3 + 0x100);

    iVar4 = FUN_004a6200(iVar3);

    if (iVar4 == 0) {

      iVar4 = FUN_004a6290(iVar3);

      if (iVar4 != 0) goto LAB_00417945;

      param_2 = *pfVar2;

    }

    else {

LAB_00417945:

      param_2 = pfVar2[0x166];

    }

    uVar5 = 1;

    param_2 = param_1 - param_2;

  }

  pfVar2 = *(float **)(iVar3 + 0x100);

  iVar4 = FUN_004a6200(iVar3);

  if (iVar4 == 0) {

    iVar4 = FUN_004a6290(iVar3);

    if (iVar4 != 0) goto LAB_00417980;

    fVar1 = *pfVar2;

  }

  else {

LAB_00417980:

    fVar1 = pfVar2[0x166];

  }

  fVar1 = fVar1 + param_2;

  pfVar2 = *(float **)(iVar3 + 0x100);

  iVar4 = FUN_004a6200(iVar3);

  if (iVar4 == 0) {

    iVar4 = FUN_004a6290(iVar3);

    if (iVar4 == 0) {

      iVar4 = FUN_004a6220(iVar3);

      if (iVar4 == 0) {

        iVar4 = FUN_004a6300(iVar3);

        if (iVar4 == 0) goto LAB_00417a14;

      }

      if ((pfVar2 != (float *)0x0) && (*pfVar2 = fVar1, fVar1 < 0.0)) {

        *pfVar2 = 0.0;

      }

      goto LAB_00417a14;

    }

  }

  if ((pfVar2 != (float *)0x0) && (pfVar2[0x166] = fVar1, fVar1 < 0.0)) {

    pfVar2[0x166] = 0.0;

  }

LAB_00417a14:

  param_2 = *(float *)(iVar3 + 0x278) - param_2;

  *(float *)(iVar3 + 0x278) = param_2;

  if (param_2 < 0.0) {

    *(undefined4 *)(iVar3 + 0x278) = 0;

  }

  return uVar5;

}

/* ===== FUN_00417a50 @ 0x00417A50 ===== */
float10 FUN_00417a50(float param_1,float param_2)



{

  float fVar1;

  float *pfVar2;

  undefined4 *puVar3;

  int iVar4;

  int iVar5;

  

  iVar4 = (int)param_1;

  pfVar2 = *(float **)((int)param_1 + 0x100);

  iVar5 = FUN_004a6200(param_1);

  if (iVar5 == 0) {

    iVar5 = FUN_004a6290(param_1);

    if (iVar5 != 0) goto LAB_00417a7a;

    fVar1 = *pfVar2;

  }

  else {

LAB_00417a7a:

    fVar1 = pfVar2[0x166];

  }

  if (param_2 <= fVar1) {

    param_1 = param_2;

  }

  else {

    pfVar2 = *(float **)((int)param_1 + 0x100);

    iVar5 = FUN_004a6200(param_1);

    if (iVar5 == 0) {

      iVar5 = FUN_004a6290(param_1);

      if (iVar5 == 0) {

        param_1 = *pfVar2;

        goto LAB_00417acb;

      }

    }

    param_1 = pfVar2[0x166];

  }

LAB_00417acb:

  pfVar2 = *(float **)(iVar4 + 0x100);

  iVar5 = FUN_004a6200(iVar4);

  if (iVar5 == 0) {

    iVar5 = FUN_004a6290(iVar4);

    if (iVar5 != 0) goto LAB_00417aef;

    fVar1 = *pfVar2;

  }

  else {

LAB_00417aef:

    fVar1 = pfVar2[0x166];

  }

  fVar1 = fVar1 - param_2;

  pfVar2 = *(float **)(iVar4 + 0x100);

  iVar5 = FUN_004a6200(iVar4);

  if (iVar5 == 0) {

    iVar5 = FUN_004a6290(iVar4);

    if (iVar5 != 0) goto LAB_00417b5a;

    iVar5 = FUN_004a6220(iVar4);

    if (iVar5 == 0) {

      iVar5 = FUN_004a6300(iVar4);

      if (iVar5 != 0) goto LAB_00417b37;

    }

    else {

LAB_00417b37:

      if ((pfVar2 != (float *)0x0) && (*pfVar2 = fVar1, fVar1 < 0.0)) {

        *pfVar2 = 0.0;

      }

    }

  }

  else {

LAB_00417b5a:

    if ((pfVar2 != (float *)0x0) && (pfVar2[0x166] = fVar1, fVar1 < 0.0)) {

      pfVar2[0x166] = 0.0;

    }

  }

  pfVar2 = *(float **)(iVar4 + 0x100);

  iVar5 = FUN_004a6200(iVar4);

  if (iVar5 == 0) {

    iVar5 = FUN_004a6290(iVar4);

    if (iVar5 != 0) goto LAB_00417ba7;

    fVar1 = *pfVar2;

  }

  else {

LAB_00417ba7:

    fVar1 = pfVar2[0x166];

  }

  if (fVar1 < 0.0 != (fVar1 == 0.0)) {

    puVar3 = *(undefined4 **)(iVar4 + 0x100);

    iVar5 = FUN_004a6200(iVar4);

    if (iVar5 == 0) {

      iVar5 = FUN_004a6290(iVar4);

      if (iVar5 == 0) {

        iVar5 = FUN_004a6220(iVar4);

        if (iVar5 == 0) {

          iVar5 = FUN_004a6300(iVar4);

          if (iVar5 == 0) goto LAB_00417c0e;

        }

        if (puVar3 != (undefined4 *)0x0) {

          *puVar3 = 0;

        }

        goto LAB_00417c0e;

      }

    }

    if (puVar3 != (undefined4 *)0x0) {

      puVar3[0x166] = 0;

    }

  }

LAB_00417c0e:

  *(float *)(iVar4 + 0x278) = param_1 + *(float *)(iVar4 + 0x278);

  return (float10)param_1;

}

/* ===== FUN_00417f20 @ 0x00417F20 ===== */
/* PS2 candidate: bldg_get_energy (conf 0.414) */



float10 FUN_00417f20(int param_1)



{

  float *pfVar1;

  int iVar2;

  

  pfVar1 = *(float **)(param_1 + 0x100);

  iVar2 = FUN_004a6200(param_1);

  if (iVar2 == 0) {

    iVar2 = FUN_004a6290(param_1);

    if (iVar2 == 0) {

      return (float10)*pfVar1;

    }

  }

  return (float10)pfVar1[0x166];

}

/* ===== FUN_00417f60 @ 0x00417F60 ===== */
/* PS2 candidate: ObjIsMeccBaseWall (conf 0.434) */



undefined4 FUN_00417f60(int param_1)



{

  float fVar1;

  float fVar2;

  float *pfVar3;

  int iVar4;

  float10 fVar5;

  

  iVar4 = FUN_004a6200(param_1);

  if ((iVar4 == 0) && (iVar4 = FUN_004a6220(param_1), iVar4 == 0)) {

    iVar4 = FUN_004a6290(param_1);

    if ((iVar4 == 0) && (iVar4 = FUN_004a6300(param_1), iVar4 == 0)) {

      fVar5 = (float10)50.0;

    }

    else {

      fVar5 = (float10)FUN_004b6d60(param_1);

    }

  }

  else {

    fVar5 = (float10)FUN_0040ad30(param_1);

  }

  pfVar3 = *(float **)(param_1 + 0x100);

  fVar1 = (float)((float10)*(float *)(DAT_00632ed8 + 0xb80) * fVar5 * (float10)0.01);

  iVar4 = FUN_004a6200(param_1);

  if ((iVar4 == 0) && (iVar4 = FUN_004a6290(param_1), iVar4 == 0)) {

    fVar2 = *pfVar3;

  }

  else {

    fVar2 = pfVar3[0x166];

  }

  if (fVar2 < fVar1 == (fVar2 == fVar1)) {

    return 0;

  }

  return 1;

}

/* ===== FUN_00418010 @ 0x00418010 ===== */
/* PS2 candidate: bldg_set_energy (conf 0.553) */



float10 FUN_00418010(int param_1,float param_2)



{

  float *pfVar1;

  int iVar2;

  

  pfVar1 = *(float **)(param_1 + 0x100);

  iVar2 = FUN_004a6200(param_1);

  if ((iVar2 == 0) && (iVar2 = FUN_004a6290(param_1), iVar2 == 0)) {

    iVar2 = FUN_004a6220(param_1);

    if (((iVar2 != 0) || (iVar2 = FUN_004a6300(param_1), iVar2 != 0)) && (pfVar1 != (float *)0x0)) {

      *pfVar1 = param_2;

      if ((float10)param_2 < (float10)0.0) {

        *pfVar1 = 0.0;

        return (float10)param_2;

      }

    }

  }

  else if (pfVar1 != (float *)0x0) {

    pfVar1[0x166] = param_2;

    if ((float10)param_2 < (float10)0.0) {

      pfVar1[0x166] = 0.0;

      return (float10)param_2;

    }

  }

  return (float10)param_2;

}

/* ===== FUN_004180a0 @ 0x004180A0 ===== */
void FUN_004180a0(int param_1,float param_2)



{

  int iVar1;

  int iVar2;

  

  iVar1 = *(int *)(param_1 + 0x100);

  iVar2 = FUN_004a6200(param_1);

  if ((iVar2 != 0) || (iVar2 = FUN_004a6290(param_1), iVar2 != 0)) {

    *(float *)(iVar1 + 0x5a0) = param_2;

    if (param_2 < 0.0 != (param_2 == 0.0)) {

      *(float *)(iVar1 + 0x5a0) =

           -(*(float *)(DAT_00632ed8 + 0xfc0) * *(float *)(DAT_00632ed8 + 0xfb8));

    }

    if (*(float *)(DAT_00632ed8 + 0xfbc) < *(float *)(iVar1 + 0x5a0)) {

      *(undefined4 *)(iVar1 + 0x5a0) = *(undefined4 *)(DAT_00632ed8 + 0xfbc);

    }

    return;

  }

  *(float *)(iVar1 + 8) = param_2;

  if (param_2 < 0.0 != (param_2 == 0.0)) {

    *(float *)(iVar1 + 8) = -(*(float *)(DAT_00632ed8 + 0xfc0) * *(float *)(DAT_00632ed8 + 0xfb8));

  }

  if (*(float *)(iVar1 + 8) <= *(float *)(DAT_00632ed8 + 0xfbc)) {

    return;

  }

  *(undefined4 *)(iVar1 + 8) = *(undefined4 *)(DAT_00632ed8 + 0xfbc);

  return;

}

/* ===== FUN_00418170 @ 0x00418170 ===== */
/* PS2 candidate: bldg_get_max_energy (conf 0.469) */



float10 FUN_00418170(undefined4 param_1)



{

  int iVar1;

  float10 fVar2;

  

  iVar1 = FUN_004a6200(param_1);

  if (iVar1 == 0) {

    iVar1 = FUN_004a6220(param_1);

    if (iVar1 == 0) {

      iVar1 = FUN_004a6290(param_1);

      if (iVar1 == 0) {

        iVar1 = FUN_004a6300(param_1);

        if (iVar1 == 0) {

          return (float10)50.0;

        }

      }

      fVar2 = (float10)FUN_004b6d60(param_1);

      return fVar2;

    }

  }

  fVar2 = (float10)FUN_0040ad30(param_1);

  return fVar2;

}

/* ===== FUN_004181d0 @ 0x004181D0 ===== */
undefined4 FUN_004181d0(float param_1,int param_2)



{

  float *pfVar1;

  undefined4 uVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  float10 fVar6;

  

  iVar5 = *(int *)((int)param_1 + 0x100);

  iVar4 = *(int *)(param_2 * 0x1c + 0x20 + iVar5);

  if (iVar4 != 0) {

    pfVar1 = *(float **)(iVar4 + 0x100);

    iVar3 = FUN_004a6200(iVar4);

    if ((iVar3 == 0) && (iVar4 = FUN_004a6290(iVar4), iVar4 == 0)) {

      param_1 = *pfVar1;

    }

    else {

      param_1 = pfVar1[0x166];

    }

    uVar2 = *(undefined4 *)(param_2 * 0x1c + 0x20 + iVar5);

    iVar5 = FUN_004a6200(uVar2);

    if ((iVar5 == 0) && (iVar5 = FUN_004a6220(uVar2), iVar5 == 0)) {

      iVar5 = FUN_004a6290(uVar2);

      if ((iVar5 == 0) && (iVar5 = FUN_004a6300(uVar2), iVar5 == 0)) {

        fVar6 = (float10)50.0;

      }

      else {

        fVar6 = (float10)FUN_004b6d60(uVar2);

      }

    }

    else {

      fVar6 = (float10)FUN_0040ad30(uVar2);

    }

    if ((float10)param_1 == fVar6) {

      return 1;

    }

  }

  return 0;

}

/* ===== FUN_00418380 @ 0x00418380 ===== */
undefined4 FUN_00418380(float param_1,int param_2)



{

  float fVar1;

  float *pfVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  float10 fVar6;

  

  iVar5 = *(int *)((int)param_1 + 0x100);

  iVar4 = *(int *)(param_2 * 0x1c + 0x20 + iVar5);

  if (iVar4 == 0) {

    return 0;

  }

  iVar3 = FUN_004a6200(iVar4);

  if ((iVar3 == 0) && (iVar3 = FUN_004a6220(iVar4), iVar3 == 0)) {

    iVar3 = FUN_004a6290(iVar4);

    if ((iVar3 == 0) && (iVar3 = FUN_004a6300(iVar4), iVar3 == 0)) {

      param_1 = 50.0;

      goto LAB_004183f6;

    }

    fVar6 = (float10)FUN_004b6d60(iVar4);

  }

  else {

    fVar6 = (float10)FUN_0040ad30(iVar4);

  }

  param_1 = (float)fVar6;

LAB_004183f6:

  iVar5 = *(int *)(param_2 * 0x1c + 0x20 + iVar5);

  if (*(int *)(iVar5 + 0xe4) < 4) {

    return 0;

  }

  pfVar2 = *(float **)(iVar5 + 0x100);

  iVar4 = FUN_004a6200(iVar5);

  if ((iVar4 == 0) && (iVar5 = FUN_004a6290(iVar5), iVar5 == 0)) {

    fVar1 = *pfVar2;

  }

  else {

    fVar1 = pfVar2[0x166];

  }

  if (fVar1 <= *(float *)(DAT_00632ed8 + 0xb84) * param_1 * 0.01) {

    return 0;

  }

  return 1;

}

/* ===== FUN_00418460 @ 0x00418460 ===== */
bool FUN_00418460(int param_1)



{

  return param_1 != 0;

}

/* ===== FUN_00418470 @ 0x00418470 ===== */
bool FUN_00418470(int param_1,int param_2)



{

  int iVar1;

  

  iVar1 = *(int *)(param_2 * 0x1c + 0x20 + *(int *)(param_1 + 0x100));

  if (iVar1 == 0) {

    return false;

  }

  return 2 < *(int *)(iVar1 + 0xe4);

}

/* ===== FUN_004184a0 @ 0x004184A0 ===== */
bool FUN_004184a0(int param_1,int param_2)



{

  int iVar1;

  

  iVar1 = *(int *)(param_2 * 0x1c + 0x20 + *(int *)(param_1 + 0x100));

  if (iVar1 == 0) {

    return false;

  }

  return 3 < *(int *)(iVar1 + 0xe4);

}

/* ===== FUN_004184d0 @ 0x004184D0 ===== */
undefined4 FUN_004184d0(int param_1,int param_2)



{

  int iVar1;

  

  iVar1 = *(int *)(param_2 * 0x1c + 0x20 + *(int *)(param_1 + 0x100));

  if ((iVar1 != 0) && (0.0 < *(float *)(iVar1 + 0x278))) {

    return 1;

  }

  return 0;

}

/* ===== FUN_00418510 @ 0x00418510 ===== */
undefined4 FUN_00418510(int param_1,int param_2)



{

  int iVar1;

  

  iVar1 = *(int *)(param_2 * 0x1c + 0x20 + *(int *)(param_1 + 0x100));

  if ((iVar1 != 0) && (1 < *(int *)(iVar1 + 0xe4))) {

    return 1;

  }

  return 0;

}

/* ===== FUN_00418540 @ 0x00418540 ===== */
undefined4 FUN_00418540(float param_1,int param_2)



{

  float *pfVar1;

  undefined4 uVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  float10 fVar6;

  

  iVar5 = *(int *)((int)param_1 + 0x100);

  param_2 = param_2 * 0x1c;

  iVar4 = *(int *)(param_2 + 0x20 + iVar5);

  if ((iVar4 == 0) || (*(int *)(iVar4 + 0xe4) < 2)) {

    return 1;

  }

  iVar4 = *(int *)(param_2 + 0x20 + iVar5);

  if (iVar4 != 0) {

    pfVar1 = *(float **)(iVar4 + 0x100);

    iVar3 = FUN_004a6200(iVar4);

    if ((iVar3 == 0) && (iVar4 = FUN_004a6290(iVar4), iVar4 == 0)) {

      param_1 = *pfVar1;

    }

    else {

      param_1 = pfVar1[0x166];

    }

    uVar2 = *(undefined4 *)(param_2 + 0x20 + iVar5);

    iVar5 = FUN_004a6200(uVar2);

    if ((iVar5 == 0) && (iVar5 = FUN_004a6220(uVar2), iVar5 == 0)) {

      iVar5 = FUN_004a6290(uVar2);

      if ((iVar5 == 0) && (iVar5 = FUN_004a6300(uVar2), iVar5 == 0)) {

        fVar6 = (float10)50.0;

      }

      else {

        fVar6 = (float10)FUN_004b6d60(uVar2);

      }

    }

    else {

      fVar6 = (float10)FUN_0040ad30(uVar2);

    }

    if ((float10)param_1 == fVar6) {

      return 0;

    }

  }

  return 1;

}

/* ===== FUN_00418630 @ 0x00418630 ===== */
/* PS2 candidate: bldg_get_refpt_worldloc (conf 0.358) */



void FUN_00418630(int param_1,int param_2,undefined4 *param_3)



{

  int iVar1;

  undefined4 *puVar2;

  undefined4 *puVar3;

  undefined4 local_44 [4];

  undefined4 local_34;

  undefined4 local_24;

  undefined4 local_14;

  

  if ((param_1 != 0) && (*(int *)(param_1 + 8) != 0)) {

    if ((param_2 < 0) ||

       ((*(int *)(param_1 + 0x2d8) <= param_2 ||

        (*(int *)(*(int *)(*(int *)(param_1 + 8) + 0x454) + param_2 * 4) == 0)))) {

      puVar2 = (undefined4 *)(param_1 + 0x294);

      puVar3 = local_44;

      for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {

        *puVar3 = *puVar2;

        puVar2 = puVar2 + 1;

        puVar3 = puVar3 + 1;

      }

    }

    else {

      (*(code *)PTR_FUN_00580c18)

                (local_44,param_1 + 0x294,param_2 * 0x44 + *(int *)(param_1 + 0x2dc));

    }

  }

  *param_3 = local_34;

  param_3[1] = local_24;

  param_3[2] = local_14;

  return;

}

/* ===== FUN_004186c0 @ 0x004186C0 ===== */
/* PS2 candidate: bldg_get_refpt_worldlocdir (conf 0.346) */



void FUN_004186c0(int param_1,int param_2,undefined4 *param_3,float *param_4)



{

  int iVar1;

  float *pfVar2;

  float *pfVar3;

  float10 fVar4;

  float local_44 [4];

  undefined4 local_34;

  float local_2c;

  undefined4 local_24;

  undefined4 local_14;

  

  if ((param_1 != 0) && (*(int *)(param_1 + 8) != 0)) {

    if ((param_2 < 0) ||

       ((*(int *)(param_1 + 0x2d8) <= param_2 ||

        (*(int *)(*(int *)(*(int *)(param_1 + 8) + 0x454) + param_2 * 4) == 0)))) {

      pfVar2 = (float *)(param_1 + 0x294);

      pfVar3 = local_44;

      for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {

        *pfVar3 = *pfVar2;

        pfVar2 = pfVar2 + 1;

        pfVar3 = pfVar3 + 1;

      }

    }

    else {

      (*(code *)PTR_FUN_00580c18)

                (local_44,param_1 + 0x294,param_2 * 0x44 + *(int *)(param_1 + 0x2dc));

    }

  }

  *param_3 = local_34;

  param_3[1] = local_24;

  param_3[2] = local_14;

  fVar4 = (float10)FUN_0050a390(-local_2c,-local_44[2]);

  *param_4 = (float)(fVar4 + (float10)90.0);

  return;

}

/* ===== FUN_00418770 @ 0x00418770 ===== */
void FUN_00418770(int param_1,int param_2,float *param_3)



{

  int iVar1;

  float *pfVar2;

  float *pfVar3;

  float10 fVar4;

  float local_44 [6];

  float local_2c;

  

  if ((param_1 != 0) && (*(int *)(param_1 + 8) != 0)) {

    if ((param_2 < 0) ||

       ((*(int *)(param_1 + 0x2d8) <= param_2 ||

        (*(int *)(*(int *)(*(int *)(param_1 + 8) + 0x454) + param_2 * 4) == 0)))) {

      pfVar2 = (float *)(param_1 + 0x294);

      pfVar3 = local_44;

      for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {

        *pfVar3 = *pfVar2;

        pfVar2 = pfVar2 + 1;

        pfVar3 = pfVar3 + 1;

      }

    }

    else {

      (*(code *)PTR_FUN_00580c18)

                (local_44,param_1 + 0x294,param_2 * 0x44 + *(int *)(param_1 + 0x2dc));

    }

  }

  fVar4 = (float10)FUN_0050a390(-local_2c,-local_44[2]);

  *param_3 = (float)(fVar4 + (float10)90.0);

  return;

}

/* ===== FUN_00418810 @ 0x00418810 ===== */
void FUN_00418810(int param_1,int param_2,float *param_3,float *param_4)



{

  int iVar1;

  float *pfVar2;

  float *pfVar3;

  float local_44 [6];

  float local_2c;

  

  if ((param_1 != 0) && (*(int *)(param_1 + 8) != 0)) {

    if ((param_2 < 0) ||

       ((*(int *)(param_1 + 0x2d8) <= param_2 ||

        (*(int *)(*(int *)(*(int *)(param_1 + 8) + 0x454) + param_2 * 4) == 0)))) {

      pfVar2 = (float *)(param_1 + 0x294);

      pfVar3 = local_44;

      for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {

        *pfVar3 = *pfVar2;

        pfVar2 = pfVar2 + 1;

        pfVar3 = pfVar3 + 1;

      }

    }

    else {

      (*(code *)PTR_FUN_00580c18)

                (local_44,param_1 + 0x294,param_2 * 0x44 + *(int *)(param_1 + 0x2dc));

    }

  }

  *param_3 = -local_44[2];

  *param_4 = -local_2c;

  return;

}

/* ===== FUN_004188a0 @ 0x004188A0 ===== */
/* PS2 candidate: base_get_base_building (conf 0.343) */



undefined4 FUN_004188a0(undefined4 param_1)



{

  int iVar1;

  undefined4 uVar2;

  

  iVar1 = FUN_004a6290(param_1);

  if (iVar1 != 0) {

    uVar2 = FUN_004b6f20();

    return uVar2;

  }

  iVar1 = FUN_004a6200(param_1);

  if (iVar1 != 0) {

    uVar2 = FUN_0040abb0(param_1);

    return uVar2;

  }

  return param_1;

}

/* ===== FUN_004188e0 @ 0x004188E0 ===== */
/* PS2 candidate: base_has_partyhouse (conf 0.394) */



bool FUN_004188e0(int param_1)



{

  int iVar1;

  

  iVar1 = FUN_004a6200(param_1);

  if (iVar1 == 0) {

    iVar1 = FUN_004a6290(param_1);

    if ((iVar1 != 0) && (iVar1 = *(int *)(*(int *)(param_1 + 0x100) + 0x100), iVar1 != 0)) {

      return 3 < *(int *)(iVar1 + 0xe4);

    }

  }

  else {

    iVar1 = *(int *)(*(int *)(param_1 + 0x100) + 0x18c);

    if (iVar1 != 0) {

      return 3 < *(int *)(iVar1 + 0xe4);

    }

  }

  return false;

}

/* ===== FUN_00418950 @ 0x00418950 ===== */
/* PS2 candidate: base_find_closest (conf 0.421) */



int FUN_00418950(int param_1)



{

  undefined4 *puVar1;

  int iVar2;

  int iVar3;

  float10 fVar4;

  

  iVar2 = FUN_004a61e0(param_1);

  puVar1 = DAT_00632d9c;

  if (iVar2 == 0) {

    return 0;

  }

  while( true ) {

    if (puVar1 == (undefined4 *)0x0) {

      return 0;

    }

    iVar2 = puVar1[3];

    iVar3 = FUN_004a6160(param_1);

    if ((((iVar3 == 0) || (iVar3 = FUN_004a6200(iVar2), iVar3 != 0)) &&

        ((iVar3 = FUN_004a6180(param_1), iVar3 == 0 || (iVar3 = FUN_004a6290(iVar2), iVar3 != 0))))

       && (fVar4 = (float10)FUN_0050a5e0(iVar2 + 0xa0,param_1 + 0xa0), fVar4 < (float10)490000.0))

    break;

    puVar1 = (undefined4 *)*puVar1;

  }

  return iVar2;

}

/* ===== FUN_004189e0 @ 0x004189E0 ===== */
int FUN_004189e0(int param_1)



{

  if ((*(int *)(param_1 + 0x18c) == 1) && (DAT_00632a88 != 0)) {

    return 1;

  }

  return *(int *)(param_1 + 0x18c) + -1;

}

/* ===== FUN_00418a00 @ 0x00418A00 ===== */
/* PS2 candidate: playergroup_claim_base (conf 0.381) */



undefined4 FUN_00418a00(int param_1,float param_2)



{

  int *piVar1;

  float fVar2;

  int iVar3;

  float fVar4;

  int iVar5;

  float *pfVar6;

  float *pfVar7;

  float10 fVar8;

  undefined4 uVar9;

  float local_50;

  float local_4c;

  float local_48;

  float local_44 [4];

  float local_34;

  float local_2c;

  float local_24;

  float local_14;

  

  fVar2 = param_2;

  piVar1 = *(int **)((int)param_2 + 0x100);

  if ((*(int *)((int)param_2 + 0x18c) != 0) || (param_1 == 0)) {

    return 0;

  }

  *(int *)((int)param_2 + 0x18c) = param_1;

  if (*piVar1 != 0) {

    iVar3 = FUN_00496c00(*piVar1,0);

    if (iVar3 == 0) {

      return 0;

    }

    local_50 = *(float *)((int)fVar2 + 0xa0) - (float)piVar1[4];

    local_4c = *(float *)((int)fVar2 + 0xa4) - (float)piVar1[5];

    local_48 = *(float *)((int)fVar2 + 0xa8) - (float)piVar1[6];

    FUN_004993c0(iVar3,&local_50);

    *(float *)(iVar3 + 200) = *(float *)((int)fVar2 + 200) - (float)piVar1[7];

    FUN_004a7440(iVar3);

    FUN_004034a0(iVar3,1,0x20,0,0,0);

    FUN_00403e60(iVar3,0x3d4ccccd);

    if (param_1 == 2) {

      fVar4 = (float)FUN_00496c00(0x344,0x10);

      DAT_00632d14 = fVar4;

    }

    else {

      if (param_1 != 3) goto LAB_00418bc3;

      fVar4 = (float)FUN_00496c00(0x343,0x10);

      DAT_00632d18 = fVar4;

    }

    param_2 = fVar4;

    if (fVar4 != 0.0) {

      if (*(int *)(iVar3 + 8) != 0) {

        if ((*(int *)(iVar3 + 0x2d8) < 8) ||

           (*(int *)(*(int *)(*(int *)(iVar3 + 8) + 0x454) + 0x1c) == 0)) {

          pfVar6 = (float *)(iVar3 + 0x294);

          pfVar7 = local_44;

          for (iVar5 = 0x11; iVar5 != 0; iVar5 = iVar5 + -1) {

            *pfVar7 = *pfVar6;

            pfVar6 = pfVar6 + 1;

            pfVar7 = pfVar7 + 1;

          }

        }

        else {

          (*(code *)PTR_FUN_00580c18)(local_44,iVar3 + 0x294,*(int *)(iVar3 + 0x2dc) + 0x1dc);

        }

      }

      local_50 = local_34;

      local_4c = local_24;

      local_48 = local_14;

      fVar8 = (float10)FUN_0050a390(-local_2c,-local_44[2]);

      param_2 = (float)(fVar8 + (float10)90.0);

      FUN_004993c0(fVar4,&local_50);

      *(float *)((int)fVar4 + 200) = param_2;

      *(int *)((int)fVar4 + 0x18c) = param_1;

    }

  }

LAB_00418bc3:

  iVar3 = FUN_0052e4a0(fVar2);

  if (iVar3 != 0) {

    param_2 = (float)param_1;

    FUN_00530bd0(fVar2,0,1,0,10,&param_2);

    iVar3 = FUN_00521370(DAT_00632f18);

    if (iVar3 != 0) {

      if (*(int *)((int)fVar2 + 0x18c) == 2) {

        uVar9 = 0x248;

      }

      else {

        uVar9 = 0x2e6;

      }

      iVar3 = FUN_00496c00(uVar9,0x80000000);

      FUN_0041b390(iVar3,fVar2);

      iVar5 = FUN_0052e4a0(fVar2);

      if (iVar5 != 0) {

        param_2 = *(float *)(iVar3 + 0x188);

        FUN_00530bd0(fVar2,0,1,0,8,&param_2);

      }

    }

  }

  return 1;

}

/* ===== FUN_00418c80 @ 0x00418C80 ===== */
/* PS2 candidate: base_bldg_pulsate (conf 0.473) */



void FUN_00418c80(int param_1)



{

  float10 fVar1;

  

  fVar1 = (float10)FUN_00518b70(param_1,0);

  fVar1 = fVar1 * (float10)*(float *)(param_1 + 0xf8) + (float10)*(float *)(param_1 + 0x184);

  *(float *)(param_1 + 0x184) = (float)fVar1;

  if (fVar1 < (float10)0.1 != (fVar1 == (float10)0.1)) {

    *(undefined4 *)(param_1 + 0x184) = 0x3dcccccd;

    *(undefined4 *)(param_1 + 0xf8) = 0x40000000;

  }

  if (0.8 <= *(float *)(param_1 + 0x184)) {

    *(undefined4 *)(param_1 + 0x184) = 0x3f4ccccd;

    *(undefined4 *)(param_1 + 0xf8) = 0xc0000000;

  }

  return;

}

/* ===== FUN_00418cf0 @ 0x00418CF0 ===== */
void FUN_00418cf0(int param_1,int param_2)



{

  float fVar1;

  uint uVar2;

  float *pfVar3;

  int iVar4;

  undefined4 *puVar5;

  float10 fVar6;

  

  uVar2 = *(uint *)(param_1 + 0xe0);

  do {

    if ((uVar2 & 0x2000) == 0) {

      return;

    }

    *(uint *)(param_1 + 0x1c8) = *(uint *)(param_1 + 0x1c8) & 0xfffff7ff;

    *(uint *)(param_1 + 0x1cc) = *(uint *)(param_1 + 0x1cc) & 0xfffffffe;

    *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) & 0xbfffffff;

    main_collgrid_00410200(param_1);

    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xffffdfff;

    iVar4 = FUN_004a6200(param_1);

    if ((iVar4 == 0) && (iVar4 = FUN_004a6220(param_1), iVar4 == 0)) {

      iVar4 = FUN_004a6290(param_1);

      if ((iVar4 == 0) && (iVar4 = FUN_004a6300(param_1), iVar4 == 0)) {

        fVar6 = (float10)50.0;

      }

      else {

        fVar6 = (float10)FUN_004b6d60(param_1);

      }

    }

    else {

      fVar6 = (float10)FUN_0040ad30(param_1);

    }

    pfVar3 = *(float **)(param_1 + 0x100);

    fVar1 = (float)((float10)*(float *)(DAT_00632ed8 + 0xb80) * fVar6 * (float10)0.01 + (float10)1.0

                   );

    iVar4 = FUN_004a6200(param_1);

    if ((iVar4 == 0) && (iVar4 = FUN_004a6290(param_1), iVar4 == 0)) {

      iVar4 = FUN_004a6220(param_1);

      if ((((iVar4 != 0) || (iVar4 = FUN_004a6300(param_1), iVar4 != 0)) && (pfVar3 != (float *)0x0)

          ) && (*pfVar3 = fVar1, fVar1 < 0.0)) {

        *pfVar3 = 0.0;

      }

    }

    else if ((pfVar3 != (float *)0x0) && (pfVar3[0x166] = fVar1, fVar1 < 0.0)) {

      pfVar3[0x166] = 0.0;

    }

    if ((*(int *)(param_1 + 4) == 0x3d7) && (puVar5 = DAT_00632d9c, param_2 != 0)) {

      for (; puVar5 != (undefined4 *)0x0; puVar5 = (undefined4 *)*puVar5) {

        iVar4 = puVar5[3];

        if (((*(int *)(iVar4 + 4) == 0x3d7) &&

            ((*(int *)(iVar4 + 0x18c) == 1 || (*(int *)(iVar4 + 0x18c) == *(int *)(param_1 + 0x18c))

             ))) && ((iVar4 != param_1 && (-1 < (char)((uint)*(undefined4 *)(iVar4 + 0xd8) >> 8)))))

        {

          FUN_00418cf0(iVar4,0);

          break;

        }

      }

    }

    if (*(int *)(param_1 + 4) != 0x4a8) {

      return;

    }

    puVar5 = DAT_00632d9c;

    if (param_2 == 0) {

      return;

    }

    while( true ) {

      if (puVar5 == (undefined4 *)0x0) {

        return;

      }

      iVar4 = puVar5[3];

      if (((*(int *)(iVar4 + 4) == 0x4a8) &&

          (((*(int *)(iVar4 + 0x18c) == 1 || (*(int *)(iVar4 + 0x18c) == *(int *)(param_1 + 0x18c)))

           && (iVar4 != param_1)))) && (-1 < (char)((uint)*(undefined4 *)(iVar4 + 0xd8) >> 8)))

      break;

      puVar5 = (undefined4 *)*puVar5;

    }

    uVar2 = *(uint *)(iVar4 + 0xe0);

    param_2 = 0;

    param_1 = iVar4;

  } while( true );

}

/* ===== FUN_0041a090 @ 0x0041A090 ===== */
void FUN_0041a090(undefined4 param_1,int param_2,undefined4 param_3)



{

  undefined4 local_8;

  undefined4 local_4;

  

  local_4 = *(undefined4 *)(param_2 + 0x188);

  local_8 = param_3;

  FUN_00530bd0(param_1,0,2,0,1,&local_8);

  return;

}

/* ===== FUN_0041a0d0 @ 0x0041A0D0 ===== */
void FUN_0041a0d0(undefined4 param_1,int param_2,undefined4 param_3)



{

  undefined4 local_8;

  undefined4 local_4;

  

  local_4 = *(undefined4 *)(param_2 + 0x188);

  local_8 = param_3;

  FUN_00530bd0(param_1,0,2,0,9,&local_8);

  return;

}

/* ===== FUN_0041a110 @ 0x0041A110 ===== */
void FUN_0041a110(undefined4 param_1)



{

  FUN_00530bd0(param_1,0,0,0,3,0);

  return;

}

/* ===== FUN_0041a130 @ 0x0041A130 ===== */
void FUN_0041a130(int param_1)



{

  undefined4 *puVar1;

  int iVar2;

  int iVar3;

  undefined4 local_8;

  undefined4 local_4;

  

  puVar1 = *(undefined4 **)(param_1 + 0x100);

  iVar2 = FUN_004a6200(param_1);

  if (iVar2 == 0) {

    iVar2 = FUN_004a6290(param_1);

    if (iVar2 != 0) goto LAB_0041a15d;

    local_8 = *puVar1;

  }

  else {

LAB_0041a15d:

    local_8 = puVar1[0x166];

  }

  iVar2 = *(int *)(param_1 + 0x100);

  iVar3 = FUN_004a6200(param_1);

  if (iVar3 == 0) {

    iVar3 = FUN_004a6290(param_1);

    if (iVar3 == 0) {

      local_4 = *(undefined4 *)(iVar2 + 8);

      goto LAB_0041a192;

    }

  }

  local_4 = *(undefined4 *)(iVar2 + 0x5a0);

LAB_0041a192:

  FUN_00530bd0(param_1,2,0,0,2,&local_8);

  return;

}

/* ===== FUN_0041a1c0 @ 0x0041A1C0 ===== */
void FUN_0041a1c0(int param_1,undefined4 param_2)



{

  param_1 = *(undefined4 *)(param_1 + 0x188);

  FUN_00530d70(param_2,0,1,0,0x1a,&param_1);

  return;

}

/* ===== FUN_0041a1f0 @ 0x0041A1F0 ===== */
void FUN_0041a1f0(undefined4 param_1,undefined4 param_2)



{

  undefined4 local_4;

  

  local_4 = 0;

  FUN_00530bd0(param_2,0,1,0,0x1b,&local_4);

  return;

}

/* ===== FUN_0041a220 @ 0x0041A220 ===== */
void FUN_0041a220(undefined4 param_1,int param_2,undefined4 param_3)



{

  undefined4 local_c;

  undefined4 local_8;

  undefined4 local_4;

  

  local_c = *(undefined4 *)(param_2 + 0x188);

  local_8 = 99999999;

  local_4 = param_3;

  FUN_00530bd0(param_1,0,3,0,0x1c,&local_c);

  return;

}

/* ===== FUN_0041a260 @ 0x0041A260 ===== */
void FUN_0041a260(undefined4 param_1,int param_2)



{

  undefined4 local_c;

  undefined4 local_8;

  undefined4 local_4;

  

  local_c = *(undefined4 *)(param_2 + 0x188);

  local_8 = 99999;

  local_4 = 999999;

  FUN_00530bd0(param_1,0,3,0,0x1e,&local_c);

  main_commonbase_00418f00(param_1,0x1e,0xc,&local_c);

  return;

}

/* ===== FUN_0041a2b0 @ 0x0041A2B0 ===== */
void FUN_0041a2b0(int param_1,int param_2)



{

  int iVar1;

  

  iVar1 = *(int *)(param_1 + 0x100);

  if (*(int *)(iVar1 + 0x5bc) == *(int *)(param_2 + 0x188)) {

    *(undefined4 *)(iVar1 + 0x5bc) = 0;

  }

  if (*(int *)(iVar1 + 0x5c0) == *(int *)(param_2 + 0x188)) {

    *(undefined4 *)(iVar1 + 0x5c0) = 0;

  }

  return;

}

/* ===== FUN_0041a2f0 @ 0x0041A2F0 ===== */
void FUN_0041a2f0(undefined4 param_1,int param_2,int param_3)



{

  undefined4 local_c;

  undefined4 local_8;

  undefined4 local_4;

  

  local_c = *(undefined4 *)(param_2 + 0x188);

  local_8 = *(undefined4 *)(param_3 + 0x188);

  local_4 = 0;

  FUN_00530bd0(param_1,0,2,0,0x1f,&local_c);

  return;

}

/* ===== FUN_0041a340 @ 0x0041A340 ===== */
void FUN_0041a340(undefined4 param_1,int param_2,int param_3)



{

  undefined4 local_c;

  undefined4 local_8;

  undefined4 local_4;

  

  local_c = *(undefined4 *)(param_2 + 0x188);

  local_8 = *(undefined4 *)(param_3 + 0x188);

  local_4 = 0;

  FUN_00530bd0(param_1,0,2,0,0x21,&local_c);

  main_commonbase_00418f00(param_1,0x21,0xc,&local_c);

  return;

}

/* ===== FUN_0041a3a0 @ 0x0041A3A0 ===== */
void FUN_0041a3a0(undefined4 param_1,int param_2)



{

  *(undefined4 *)(*(int *)(param_2 + 0x100) + 0x10) = 0;

  return;

}

/* ===== FUN_0041a3c0 @ 0x0041A3C0 ===== */
void FUN_0041a3c0(undefined4 param_1,int param_2,int param_3)



{

  undefined4 local_c;

  undefined4 local_8;

  undefined4 local_4;

  

  local_c = *(undefined4 *)(param_2 + 0x188);

  local_8 = *(undefined4 *)(param_3 + 0x188);

  local_4 = 0;

  FUN_00530bd0(param_1,0,2,0,0x22,&local_c);

  return;

}

/* ===== FUN_0041a410 @ 0x0041A410 ===== */
void FUN_0041a410(undefined4 param_1,int param_2,int param_3)



{

  undefined4 local_c;

  undefined4 local_8;

  undefined4 local_4;

  

  local_c = *(undefined4 *)(param_2 + 0x188);

  local_8 = *(undefined4 *)(param_3 + 0x188);

  local_4 = 0;

  FUN_00530bd0(param_1,0,2,0,0x24,&local_c);

  main_commonbase_00418f00(param_1,0x24,0xc,&local_c);

  return;

}

/* ===== FUN_0041a570 @ 0x0041A570 ===== */
void FUN_0041a570(undefined4 param_1)



{

  int iVar1;

  undefined4 *puVar2;

  undefined4 *puVar3;

  int iVar4;

  int iVar5;

  float *pfVar6;

  undefined4 *puVar7;

  float *pfVar8;

  undefined4 *puVar9;

  float10 fVar10;

  undefined4 local_94;

  undefined4 local_90;

  undefined4 local_8c;

  float local_88 [4];

  undefined4 local_78;

  float local_70;

  undefined4 local_68;

  undefined4 local_58;

  undefined4 auStack_44 [4];

  undefined4 uStack_34;

  undefined4 uStack_24;

  undefined4 uStack_14;

  

  puVar3 = DAT_00632d9c;

  do {

    if (puVar3 == (undefined4 *)0x0) {

      return;

    }

    iVar1 = puVar3[3];

    if ((*(int *)(iVar1 + 0x1e0) == 0x5b) && (-1 < (char)((uint)*(undefined4 *)(iVar1 + 0xd8) >> 8))

       ) {

      if (*(int *)(iVar1 + 4) == 0x3d5) {

        iVar4 = FUN_00496c00(0x2ee,0x80000000);

      }

      else {

        if (*(int *)(iVar1 + 4) != 0x3d9) goto LAB_0041a787;

        iVar4 = FUN_00496c00(0x2d9,0x80000000);

      }

      FUN_004a7440(iVar1);

      FUN_004034a0(iVar1,1,0x20,0,0,0);

      FUN_00403e60(iVar1,0x3d4ccccd);

      if (*(int *)(iVar1 + 8) != 0) {

        if ((*(int *)(iVar1 + 0x2d8) < 3) ||

           (*(int *)(*(int *)(*(int *)(iVar1 + 8) + 0x454) + 8) == 0)) {

          pfVar6 = (float *)(iVar1 + 0x294);

          pfVar8 = local_88;

          for (iVar5 = 0x11; iVar5 != 0; iVar5 = iVar5 + -1) {

            *pfVar8 = *pfVar6;

            pfVar6 = pfVar6 + 1;

            pfVar8 = pfVar8 + 1;

          }

        }

        else {

          (*(code *)PTR_FUN_00580c18)(local_88,iVar1 + 0x294,*(int *)(iVar1 + 0x2dc) + 0x88);

        }

      }

      local_94 = local_78;

      local_90 = local_68;

      local_8c = local_58;

      fVar10 = (float10)FUN_0050a390(-local_70,-local_88[2]);

      *(float *)(iVar4 + 200) = (float)(fVar10 + (float10)90.0);

      FUN_004993c0(iVar4,&local_94);

      puVar2 = *(undefined4 **)(iVar4 + 0x100);

      *puVar2 = *(undefined4 *)(iVar1 + 4);

      puVar2[4] = *(float *)(iVar4 + 0xa0) - *(float *)(iVar1 + 0xa0);

      puVar2[5] = *(float *)(iVar4 + 0xa4) - *(float *)(iVar1 + 0xa4);

      puVar2[6] = *(float *)(iVar4 + 0xa8) - *(float *)(iVar1 + 0xa8);

      puVar2[7] = *(float *)(iVar4 + 200) - *(float *)(iVar1 + 200);

      if (*(int *)(iVar1 + 8) != 0) {

        if ((*(int *)(iVar1 + 0x2d8) < 9) ||

           (*(int *)(*(int *)(*(int *)(iVar1 + 8) + 0x454) + 0x20) == 0)) {

          puVar7 = (undefined4 *)(iVar1 + 0x294);

          puVar9 = auStack_44;

          for (iVar5 = 0x11; iVar5 != 0; iVar5 = iVar5 + -1) {

            *puVar9 = *puVar7;

            puVar7 = puVar7 + 1;

            puVar9 = puVar9 + 1;

          }

        }

        else {

          (*(code *)PTR_FUN_00580c18)(auStack_44,iVar1 + 0x294,*(int *)(iVar1 + 0x2dc) + 0x220);

        }

      }

      puVar2[1] = uStack_34;

      puVar2[2] = uStack_24;

      puVar2[3] = uStack_14;

      FUN_0041a980(iVar4,param_1);

    }

LAB_0041a787:

    puVar3 = (undefined4 *)*puVar3;

  } while( true );

}

/* ===== FUN_0041a7f0 @ 0x0041A7F0 ===== */
void FUN_0041a7f0(int param_1,float param_2)



{

  float *pfVar1;

  int iVar2;

  int iVar3;

  float10 fVar4;

  undefined4 uVar5;

  

  iVar3 = *(int *)(param_1 + 0x100);

  iVar2 = FUN_004a6200(param_1);

  if (iVar2 == 0) {

    uVar5 = (&DAT_005606b0)[(int)param_2 * 0x16];

  }

  else {

    uVar5 = (&DAT_00554560)[(int)param_2 * 0x16];

  }

  iVar2 = FUN_00496c00(uVar5,0x80000000);

  iVar3 = (int)param_2 * 0x1c + iVar3;

  *(int *)(iVar3 + 0x20) = iVar2;

  FUN_004993c0(iVar2,iVar3 + 0x24);

  *(undefined4 *)(iVar2 + 200) = *(undefined4 *)(iVar3 + 0x30);

  *(undefined4 *)(iVar2 + 0xcc) = 0;

  *(undefined4 *)(iVar2 + 0xd0) = 0;

  *(undefined4 *)(iVar2 + 0xe4) = 4;

  *(int *)(iVar2 + 0x274) = param_1;

  iVar3 = FUN_004a6200(iVar2);

  if (iVar3 == 0) {

    iVar3 = FUN_004a6220(iVar2);

    if (iVar3 != 0) goto LAB_0041a8b7;

    iVar3 = FUN_004a6290(iVar2);

    if (iVar3 != 0) {

LAB_0041a8af:

      fVar4 = (float10)FUN_004b6d60(iVar2);

      goto LAB_0041a8bd;

    }

    iVar3 = FUN_004a6300(iVar2);

    if (iVar3 != 0) goto LAB_0041a8af;

    param_2 = 50.0;

  }

  else {

LAB_0041a8b7:

    fVar4 = (float10)FUN_0040ad30(iVar2);

LAB_0041a8bd:

    param_2 = (float)fVar4;

  }

  pfVar1 = *(float **)(iVar2 + 0x100);

  iVar3 = FUN_004a6200(iVar2);

  if (iVar3 == 0) {

    iVar3 = FUN_004a6290(iVar2);

    if (iVar3 == 0) {

      iVar3 = FUN_004a6220(iVar2);

      if (iVar3 == 0) {

        iVar3 = FUN_004a6300(iVar2);

        if (iVar3 == 0) goto LAB_0041a942;

      }

      if ((pfVar1 != (float *)0x0) && (*pfVar1 = param_2, param_2 < 0.0)) {

        *pfVar1 = 0.0;

      }

      goto LAB_0041a942;

    }

  }

  if ((pfVar1 != (float *)0x0) && (pfVar1[0x166] = param_2, param_2 < 0.0)) {

    pfVar1[0x166] = 0.0;

  }

LAB_0041a942:

  FUN_004034a0(iVar2,1,0x84,0,0,0);

  *(undefined4 *)(iVar2 + 0x14) = 0x3f800000;

  *(uint *)(iVar2 + 0x1c8) = *(uint *)(iVar2 + 0x1c8) & 0xfffff7ff | 0x20000;

  return;

}

/* ===== FUN_0041a980 @ 0x0041A980 ===== */
void FUN_0041a980(int param_1)



{

  int iVar1;

  int iVar2;

  

  iVar2 = *(int *)(param_1 + 0x100);

  iVar1 = FUN_004a6200(param_1);

  if (iVar1 != 0) {

    iVar1 = FUN_005250e0(DAT_00632f10);

    if (iVar1 == 0) {

      return;

    }

    FUN_00407c40(param_1);

    iVar1 = FUN_0052aa70();

    if ((iVar1 == 0) || (iVar1 = FUN_005213a0(DAT_00632f18), iVar1 == 0)) {

      iVar2 = FUN_0052aa70();

      if ((iVar2 != 0) && (iVar2 = FUN_00521330(DAT_00632f18), iVar2 == 0)) {

        *(undefined4 *)(param_1 + 0x184) = 0x3f800000;

        *(uint *)(param_1 + 0x1c8) = *(uint *)(param_1 + 0x1c8) & 0xfffdffff | 0x800;

        FUN_0041a7f0(param_1,0xd);

      }

    }

    else {

      *(undefined4 *)(param_1 + 0x184) = 0x3f800000;

      *(uint *)(param_1 + 0x1c8) = *(uint *)(param_1 + 0x1c8) & 0xfffdffff | 0x800;

      FUN_0041a7f0(param_1,0xd);

      FUN_0041a7f0(param_1,0xe);

      FUN_0041a7f0(param_1,0xf);

      FUN_0041a7f0(param_1,0x10);

      FUN_0041a7f0(param_1,0x11);

      FUN_0041a7f0(param_1,0x12);

      FUN_0041a7f0(param_1,0x13);

      FUN_0041a7f0(param_1,0x14);

      FUN_0041a7f0(param_1,0x15);

      FUN_0041a7f0(param_1,0x16);

      FUN_0041a7f0(param_1,0x17);

      FUN_0041a7f0(param_1,0x18);

      FUN_0041a7f0(param_1,0x19);

      iVar1 = FUN_00521310(DAT_00632f18);

      if (iVar1 != 0) {

        FUN_0045a740(iVar2 + 0x5c4,0x13,0xffffffff);

        FUN_0045a740(iVar2 + 0x5d0,0x13,0xffffffff);

        FUN_00409200(param_1);

        return;

      }

    }

    FUN_00409200(param_1);

    return;

  }

  iVar1 = FUN_00525100(DAT_00632f10);

  if (iVar1 != 0) {

    FUN_004b4570(param_1);

    iVar1 = FUN_0052aa70();

    if ((iVar1 == 0) || (iVar1 = FUN_005213a0(DAT_00632f18), iVar1 == 0)) {

      iVar2 = FUN_0052aa70();

      if ((iVar2 != 0) && (iVar2 = FUN_00521330(DAT_00632f18), iVar2 == 0)) {

        *(undefined4 *)(param_1 + 0x184) = 0x3f800000;

        *(uint *)(param_1 + 0x1c8) = *(uint *)(param_1 + 0x1c8) & 0xfffdffff | 0x800;

        FUN_0041a7f0(param_1,8);

      }

    }

    else {

      *(undefined4 *)(param_1 + 0x184) = 0x3f800000;

      *(uint *)(param_1 + 0x1c8) = *(uint *)(param_1 + 0x1c8) & 0xfffdffff | 0x800;

      FUN_0041a7f0(param_1,8);

      FUN_0041a7f0(param_1,9);

      FUN_0041a7f0(param_1,10);

      FUN_0041a7f0(param_1,0xb);

      FUN_0041a7f0(param_1,0xc);

      FUN_0041a7f0(param_1,0xd);

      FUN_0041a7f0(param_1,0xe);

      FUN_0041a7f0(param_1,0xf);

      iVar1 = FUN_00521310(DAT_00632f18);

      if (iVar1 != 0) {

        FUN_0045a740(iVar2 + 0x5c4,0x49,0xffffffff);

        FUN_0045a740(iVar2 + 0x5d0,0x49,0xffffffff);

        FUN_004b5810(param_1);

        return;

      }

    }

    FUN_004b5810(param_1);

    return;

  }

  return;

}

/* ===== FUN_0041ac40 @ 0x0041AC40 ===== */
/* PS2 candidate: buoy_process__FP6OBJECT (conf 0.383) */



void FUN_0041ac40(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,

                 undefined4 param_5,float param_6,undefined4 param_7)



{

  float *pfVar1;

  undefined4 *puVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  undefined4 *puVar6;

  undefined4 *puVar7;

  float10 fVar8;

  undefined4 local_44 [4];

  undefined4 local_34;

  undefined4 local_24;

  undefined4 local_14;

  

  iVar3 = FUN_00496c00(param_1,0x80000000);

  *(undefined4 *)(iVar3 + 0x188) = param_2;

  *(undefined4 *)(iVar3 + 200) = param_4;

  FUN_004993c0(iVar3,param_3);

  pfVar1 = *(float **)(iVar3 + 0x100);

  iVar4 = FUN_004a6200(iVar3);

  if ((iVar4 == 0) && (iVar4 = FUN_004a6290(iVar3), iVar4 == 0)) {

    iVar4 = FUN_004a6220(iVar3);

    if ((((iVar4 != 0) || (iVar4 = FUN_004a6300(iVar3), iVar4 != 0)) && (pfVar1 != (float *)0x0)) &&

       (*pfVar1 = param_6, param_6 < 0.0)) {

      *pfVar1 = 0.0;

    }

  }

  else if ((pfVar1 != (float *)0x0) && (pfVar1[0x166] = param_6, param_6 < 0.0)) {

    pfVar1[0x166] = 0.0;

  }

  puVar2 = *(undefined4 **)(iVar3 + 0x100);

  *(undefined4 *)(iVar3 + 0x278) = param_7;

  puVar6 = DAT_00632d9c;

  while( true ) {

    if (puVar6 == (undefined4 *)0x0) goto LAB_0041ae31;

    iVar4 = puVar6[3];

    if (((*(int *)(iVar4 + 0x1e0) == 0x5b) &&

        (-1 < (char)((uint)*(undefined4 *)(iVar4 + 0xd8) >> 8))) &&

       (fVar8 = (float10)FUN_0050a5e0(iVar4 + 0xa0,iVar3 + 0xa0), fVar8 <= (float10)250000.0))

    break;

    puVar6 = (undefined4 *)*puVar6;

  }

  *puVar2 = *(undefined4 *)(iVar4 + 4);

  FUN_004a7440(iVar4);

  FUN_004034a0(iVar4,1,0x20,0,0,0);

  FUN_00403e60(iVar4,0x3d4ccccd);

  puVar2[4] = *(float *)(iVar3 + 0xa0) - *(float *)(iVar4 + 0xa0);

  puVar2[5] = *(float *)(iVar3 + 0xa4) - *(float *)(iVar4 + 0xa4);

  puVar2[6] = *(float *)(iVar3 + 0xa8) - *(float *)(iVar4 + 0xa8);

  puVar2[7] = *(float *)(iVar3 + 200) - *(float *)(iVar4 + 200);

  if (*(int *)(iVar4 + 8) != 0) {

    if ((*(int *)(iVar4 + 0x2d8) < 9) ||

       (*(int *)(*(int *)(*(int *)(iVar4 + 8) + 0x454) + 0x20) == 0)) {

      puVar6 = (undefined4 *)(iVar4 + 0x294);

      puVar7 = local_44;

      for (iVar5 = 0x11; iVar5 != 0; iVar5 = iVar5 + -1) {

        *puVar7 = *puVar6;

        puVar6 = puVar6 + 1;

        puVar7 = puVar7 + 1;

      }

    }

    else {

      (*(code *)PTR_FUN_00580c18)(local_44,iVar4 + 0x294,*(int *)(iVar4 + 0x2dc) + 0x220);

    }

  }

  puVar2[1] = local_34;

  puVar2[2] = local_24;

  puVar2[3] = local_14;

LAB_0041ae31:

  iVar4 = FUN_004a6200(iVar3);

  if (iVar4 == 0) {

    FUN_004b4570(iVar3);

  }

  else {

    FUN_00407c40();

  }

  FUN_00418a00(param_5,iVar3);

  return;

}

/* ===== FUN_0041ae70 @ 0x0041AE70 ===== */
void FUN_0041ae70(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,

                 undefined4 param_6,float param_7,undefined4 param_8,undefined4 param_9)



{

  float fVar1;

  float *pfVar2;

  float fVar3;

  int iVar4;

  int iVar5;

  int *piVar6;

  int iVar7;

  int *piVar8;

  float10 fVar9;

  

  iVar4 = FUN_00496c00(param_2,0x80000000);

  iVar7 = *(int *)(param_1 + 0x100);

  iVar5 = FUN_004a6220(iVar4);

  if (iVar5 == 0) {

    iVar5 = FUN_004a6300(iVar4);

    if (iVar5 != 0) {

      iVar5 = 0;

      piVar6 = &DAT_005606b0;

      piVar8 = (int *)(iVar7 + 0x20);

      do {

        if ((*piVar6 == param_2) && (*piVar8 == 0)) {

          *(int *)(iVar5 * 0x1c + 0x20 + iVar7) = iVar4;

          break;

        }

        piVar6 = piVar6 + 0x16;

        iVar5 = iVar5 + 1;

        piVar8 = piVar8 + 7;

      } while ((int)piVar6 < 0x560c30);

      if ((iVar5 == 3) || (iVar5 == 0xb)) {

        *(undefined4 *)(iVar4 + 0xf4) = param_9;

      }

      FUN_004b5810(param_1);

    }

  }

  else {

    iVar5 = 0;

    piVar6 = &DAT_00554560;

    piVar8 = (int *)(iVar7 + 0x20);

    do {

      if ((*piVar6 == param_2) && (*piVar8 == 0)) {

        *(int *)(iVar5 * 0x1c + 0x20 + iVar7) = iVar4;

        break;

      }

      piVar6 = piVar6 + 0x16;

      iVar5 = iVar5 + 1;

      piVar8 = piVar8 + 7;

    } while ((int)piVar6 < 0x554e50);

    if ((iVar5 == 3) || (iVar5 == 0x10)) {

      *(undefined4 *)(iVar4 + 0xf4) = param_9;

    }

    FUN_00409200(param_1);

  }

  switch(param_2) {

  case 0x3d7:

  case 0x4a8:

    *(int *)(iVar7 + 0x584) = iVar4;

    break;

  case 0x3d8:

  case 0x49d:

    *(int *)(iVar7 + 0x580) = iVar4;

    break;

  case 0x3da:

  case 0x3dd:

    *(undefined4 *)(iVar4 + 0xf4) = param_9;

    *(int *)(iVar7 + 0x57c) = iVar4;

    break;

  case 0x3dc:

  case 0x4a5:

    *(int *)(iVar7 + 0x578) = iVar4;

    break;

  case 0x425:

  case 0x4a1:

  case 0x4a4:

    *(int *)(iVar7 + 0x58c) = iVar4;

    break;

  case 0x426:

  case 0x4a2:

  case 0x4a3:

    *(int *)(iVar7 + 0x588) = iVar4;

  }

  iVar7 = FUN_004a6200(param_1);

  if (((iVar7 != 0) && (param_2 == 0x396)) ||

     ((iVar7 = FUN_004a6290(param_1), iVar7 != 0 && (param_2 == 0x484)))) {

    *(undefined4 *)(param_1 + 0x184) = 0x3f800000;

    *(uint *)(param_1 + 0x1c8) = *(uint *)(param_1 + 0x1c8) & 0xfffdffff | 0x800;

  }

  *(undefined4 *)(iVar4 + 0x188) = param_3;

  *(undefined4 *)(iVar4 + 200) = param_6;

  *(undefined4 *)(iVar4 + 0x278) = param_8;

  FUN_004993c0(iVar4,param_5);

  pfVar2 = *(float **)(iVar4 + 0x100);

  *(int *)(iVar4 + 0x274) = param_1;

  iVar7 = FUN_004a6200(iVar4);

  if ((iVar7 == 0) && (iVar7 = FUN_004a6290(iVar4), iVar7 == 0)) {

    iVar7 = FUN_004a6220(iVar4);

    if ((((iVar7 != 0) || (iVar7 = FUN_004a6300(iVar4), iVar7 != 0)) && (pfVar2 != (float *)0x0)) &&

       (*pfVar2 = param_7, param_7 < 0.0)) {

      *pfVar2 = 0.0;

    }

  }

  else if ((pfVar2 != (float *)0x0) && (pfVar2[0x166] = param_7, param_7 < 0.0)) {

    pfVar2[0x166] = 0.0;

  }

  *(undefined4 *)(iVar4 + 0xcc) = 0;

  *(undefined4 *)(iVar4 + 0xd0) = 0;

  *(undefined4 *)(iVar4 + 0xe4) = param_4;

  FUN_004034a0(iVar4,1,0x84,0,0,0);

  iVar7 = FUN_004a6220(iVar4);

  if (iVar7 == 0) {

    iVar7 = FUN_004a6300(iVar4);

    if ((iVar7 == 0) || (iVar7 = FUN_004b6f60(iVar4), iVar7 < 0)) goto LAB_0041b268;

    iVar5 = FUN_004a6200(iVar4);

    if ((iVar5 == 0) && (iVar5 = FUN_004a6220(iVar4), iVar5 == 0)) {

      iVar5 = FUN_004a6290(iVar4);

      if ((iVar5 != 0) || (iVar5 = FUN_004a6300(iVar4), iVar5 != 0)) {

        fVar9 = (float10)FUN_004b6d60(iVar4);

        goto LAB_0041b204;

      }

      param_7 = 50.0;

    }

    else {

      fVar9 = (float10)FUN_0040ad30(iVar4);

LAB_0041b204:

      param_7 = (float)fVar9;

    }

    pfVar2 = *(float **)(iVar4 + 0x100);

    iVar5 = FUN_004a6200(iVar4);

    if ((iVar5 == 0) && (iVar5 = FUN_004a6290(iVar4), iVar5 == 0)) {

      fVar1 = *pfVar2;

    }

    else {

      fVar1 = pfVar2[0x166];

    }

    fVar3 = *(float *)(DAT_00632ed8 + 0xb84) * param_7 * 0.01;

    if (fVar1 < fVar3 != (fVar1 == fVar3)) {

      FUN_004b5b30(*(undefined4 *)(iVar4 + 0x274),iVar7,1);

    }

    goto LAB_0041b268;

  }

  iVar7 = FUN_0040acf0();

  if (iVar7 < 0) goto LAB_0041b268;

  iVar5 = FUN_004a6200(iVar4);

  if ((iVar5 == 0) && (iVar5 = FUN_004a6220(iVar4), iVar5 == 0)) {

    iVar5 = FUN_004a6290(iVar4);

    if ((iVar5 != 0) || (iVar5 = FUN_004a6300(iVar4), iVar5 != 0)) {

      fVar9 = (float10)FUN_004b6d60(iVar4);

      goto LAB_0041b12c;

    }

    param_7 = 50.0;

  }

  else {

    fVar9 = (float10)FUN_0040ad30(iVar4);

LAB_0041b12c:

    param_7 = (float)fVar9;

  }

  pfVar2 = *(float **)(iVar4 + 0x100);

  iVar5 = FUN_004a6200(iVar4);

  if ((iVar5 == 0) && (iVar5 = FUN_004a6290(iVar4), iVar5 == 0)) {

    fVar1 = *pfVar2;

  }

  else {

    fVar1 = pfVar2[0x166];

  }

  fVar3 = *(float *)(DAT_00632ed8 + 0xb84) * param_7 * 0.01;

  if (fVar1 < fVar3 != (fVar1 == fVar3)) {

    FUN_00409780(*(undefined4 *)(iVar4 + 0x274),iVar7,1);

  }

LAB_0041b268:

  *(undefined4 *)(iVar4 + 0x14) = 0x3f800000;

  *(uint *)(iVar4 + 0x1c8) = *(uint *)(iVar4 + 0x1c8) & 0xfffff7ff | 0x20000;

  *(uint *)(iVar4 + 0xd8) = *(uint *)(iVar4 + 0xd8) | 0x10;

  return;

}

/* ===== FUN_0041b390 @ 0x0041B390 ===== */
void FUN_0041b390(int param_1,int param_2)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  float *pfVar4;

  float *pfVar5;

  float10 fVar6;

  undefined4 uVar7;

  float local_50;

  float local_4c;

  float local_48;

  float local_44 [4];

  float local_34;

  float local_2c;

  undefined4 local_24;

  undefined4 local_14;

  

  piVar1 = *(int **)(param_2 + 0x100);

  *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xfffffeff;

  iVar2 = FUN_0052aa70();

  if (iVar2 == 0) {

    iVar2 = *(int *)(param_1 + 0x100);

    *(undefined4 *)(param_1 + 200) = *(undefined4 *)(iVar2 + 0xb4);

    *(undefined4 *)(param_1 + 0xa0) = *(undefined4 *)(iVar2 + 0xa8);

    *(undefined4 *)(param_1 + 0xa4) = *(undefined4 *)(iVar2 + 0xac);

    *(undefined4 *)(param_1 + 0xa8) = *(undefined4 *)(iVar2 + 0xb0);

    FUN_00499280(param_1);

    FUN_004d8420();

  }

  else if (*piVar1 == 0) {

    *(undefined4 *)(param_1 + 200) = *(undefined4 *)(param_2 + 200);

    pfVar4 = (float *)(param_1 + 0xa0);

    *pfVar4 = *(float *)(param_2 + 0xa0);

    *(undefined4 *)(param_1 + 0xa4) = *(undefined4 *)(param_2 + 0xa4);

    *(undefined4 *)(param_1 + 0xa8) = *(undefined4 *)(param_2 + 0xa8);

    *pfVar4 = *pfVar4 + 40.0;

    FUN_00499280(param_1);

  }

  else {

    iVar2 = FUN_00496c00(*piVar1,0);

    local_50 = *(float *)(param_2 + 0xa0) - (float)piVar1[4];

    local_4c = *(float *)(param_2 + 0xa4) - (float)piVar1[5];

    local_48 = *(float *)(param_2 + 0xa8) - (float)piVar1[6];

    FUN_004993c0(iVar2,&local_50);

    *(float *)(iVar2 + 200) = *(float *)(param_2 + 200) - (float)piVar1[7];

    FUN_004a7440(iVar2);

    FUN_004034a0(iVar2,1,0x20,0,0,0);

    FUN_00403e60(iVar2,0x3d4ccccd);

    if (*(int *)(iVar2 + 8) != 0) {

      if ((*(int *)(iVar2 + 0x2d8) < 7) ||

         (*(int *)(*(int *)(*(int *)(iVar2 + 8) + 0x454) + 0x18) == 0)) {

        pfVar4 = (float *)(iVar2 + 0x294);

        pfVar5 = local_44;

        for (iVar3 = 0x11; iVar3 != 0; iVar3 = iVar3 + -1) {

          *pfVar5 = *pfVar4;

          pfVar4 = pfVar4 + 1;

          pfVar5 = pfVar5 + 1;

        }

      }

      else {

        (*(code *)PTR_FUN_00580c18)(local_44,iVar2 + 0x294,*(int *)(iVar2 + 0x2dc) + 0x198);

      }

    }

    local_50 = local_34;

    local_4c = (float)local_24;

    local_48 = (float)local_14;

    fVar6 = (float10)FUN_0050a390(-local_2c,-local_44[2]);

    FUN_004993c0(param_1,&local_50);

    *(float *)(param_1 + 200) = (float)(fVar6 + (float10)90.0);

    FUN_00497510(iVar2);

  }

  *(undefined4 *)(param_1 + 0xc4) = 0x40000000;

  *(undefined4 *)(param_1 + 0x130) = 0;

  *(undefined4 *)(param_1 + 300) = 0;

  *(undefined4 *)(param_1 + 0x128) = 0;

  *(undefined4 *)(param_1 + 0xe8) = 10;

  *(int *)(param_1 + 0x274) = param_2;

  *(undefined4 *)(param_1 + 0xe4) = 0x33;

  *(undefined4 *)(param_1 + 0x18c) = *(undefined4 *)(param_2 + 0x18c);

  *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 8;

  FUN_004034a0(param_1,0x65,0x20,0,0,0);

  iVar2 = FUN_0052aa70();

  if ((iVar2 != 0) && (-1 < *(char *)(param_1 + 0xe0))) {

    if (*(int *)(param_2 + 0x18c) == 2) {

      uVar7 = 0x3b7;

    }

    else {

      uVar7 = 0x3b8;

    }

    iVar2 = FUN_00496c00(uVar7,0);

    *(int *)(iVar2 + 0x210) = param_1;

    *(undefined4 *)(iVar2 + 0x218) = 2;

    *(undefined4 *)(iVar2 + 0x214) = 0;

    *(uint *)(iVar2 + 0xd8) = *(uint *)(iVar2 + 0xd8) | 0x400000;

    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 0x80;

  }

  return;

}

/* ===== FUN_0041b660 @ 0x0041B660 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* PS2 candidate: base_add_smartie_to_building__FP6OBJECTi (conf 0.413) */



undefined4 FUN_0041b660(int param_1,int param_2)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int *piVar6;

  int *piVar7;

  float10 fVar8;

  float local_50;

  int local_4c;

  int local_40;

  undefined4 local_3c;

  undefined4 local_38;

  undefined4 local_30;

  undefined4 local_2c;

  undefined4 local_28;

  

  iVar1 = *(int *)(param_1 + 0x100);

  if ((*(int *)(param_1 + 0x18c) != 1) || (iVar4 = 1, DAT_00632a88 == 0)) {

    iVar4 = *(int *)(param_1 + 0x18c) + -1;

  }

  if ((int)(&DAT_006330d0)[iVar4] < 1) {

    return 0;

  }

  iVar3 = FUN_004a6200(param_1);

  iVar2 = param_2;

  if (iVar3 == 0) {

    FUN_004b6630(param_1,param_2);

  }

  else {

    FUN_0040a5e0();

  }

  iVar3 = (iVar2 + 2) * 0x1c;

  piVar6 = (int *)(iVar1 + iVar3);

  *piVar6 = *(int *)(iVar1 + iVar3) + 1;

  (&DAT_006330d0)[iVar4] = (&DAT_006330d0)[iVar4] + -1;

  iVar4 = FUN_0052e4a0(param_1);

  if (iVar4 != 0) {

    param_2._0_2_ = CONCAT11((char)*piVar6,(char)iVar2);

    FUN_00530bd0(param_1,0,0,2,0x25,&param_2);

    FUN_0052f8f0(0);

  }

  param_2 = 0;

  iVar4 = FUN_004a6200(param_1);

  if (iVar4 == 0) {

    iVar4 = FUN_004a6290(param_1);

    if (iVar4 != 0) {

      param_2 = FUN_004b6eb0(param_1);

    }

  }

  else {

    param_2 = FUN_0040ae40();

  }

  local_4c = 0;

  local_50 = 1e+10;

  piVar7 = DAT_00632d98;

  if (DAT_00632d98 != (int *)0x0) {

    do {

      iVar4 = piVar7[3];

      if ((((((*(uint *)(iVar4 + 0xd8) & 0x4000c000) == 0) &&

            (*(int *)(iVar4 + 0x184) != 0x3f800000)) && (*(int *)(iVar4 + 0x1e0) == 0x12)) &&

          ((((*(byte *)(iVar4 + 0xe0) & 8) != 0 && (*(int *)(iVar4 + 0xe8) != 10)) &&

           ((*(int *)(iVar4 + 0x274) == param_1 &&

            ((iVar3 = *(int *)(iVar4 + 0x100), *(int *)(iVar3 + 0x1c) < 0 &&

             (*(int *)(iVar3 + 0x24) < 0)))))))) && (*(int *)(iVar3 + 0x20) < 0)) {

        iVar5 = param_2;

        if (param_2 == 0) {

          iVar5 = *(int *)(iVar2 * 0x1c + 0x20 + iVar1);

        }

        fVar8 = (float10)FUN_0050a5e0(iVar4 + 0xa0,iVar5 + 0xa0);

        if (*(float *)(iVar3 + 0x18) < *(float *)(DAT_00632ed8 + 0x624) * 0.5) {

          fVar8 = fVar8 + (float10)40000.0;

        }

        if (fVar8 < (float10)local_50) {

          local_50 = (float)fVar8;

          local_4c = iVar4;

        }

      }

      piVar7 = (int *)*piVar7;

    } while (piVar7 != (int *)0x0);

    if (local_4c != 0) {

      *(int *)(*(int *)(local_4c + 0x100) + 0x24) = iVar2;

    }

  }

  iVar4 = FUN_004a6200(param_1);

  iVar3 = iVar2 * 0x58;

  if (iVar4 == 0) {

    iVar4 = *(int *)(&DAT_005606c4 + iVar3);

  }

  else {

    iVar4 = *(int *)(&DAT_00554574 + iVar3);

  }

  if (iVar4 <= *piVar6) {

    if ((*(int *)(param_1 + 0x18c) == *(int *)(DAT_00632a88 + 0x18c)) && (DAT_00632bb0 != 0)) {

      iVar4 = FUN_004a6200(param_1);

      if (iVar4 == 0) {

        iVar4 = *(int *)(&DAT_005606c4 + iVar3);

      }

      else {

        iVar4 = *(int *)(&DAT_00554574 + iVar3);

      }

      if (*piVar6 == iVar4) {

        _DAT_00657674 = 0x40000000;

        FUN_00495920(0x651);

      }

    }

    param_2 = 0;

    for (piVar6 = DAT_00632d98; piVar6 != (int *)0x0; piVar6 = (int *)*piVar6) {

      iVar4 = piVar6[3];

      if ((((((*(uint *)(iVar4 + 0xd8) & 0x4000c000) == 0) &&

            (*(int *)(iVar4 + 0x184) != 0x3f800000)) && (*(int *)(iVar4 + 0x1e0) == 0x12)) &&

          (((*(byte *)(iVar4 + 0xe0) & 8) != 0 && (*(int *)(iVar4 + 0xe8) != 10)))) &&

         ((*(int *)(iVar4 + 0x274) == param_1 &&

          (iVar3 = *(int *)(iVar4 + 0x100), *(int *)(iVar3 + 0x24) == iVar2)))) {

        iVar5 = FUN_004a6200(param_1);

        if (iVar5 == 0) {

          iVar5 = FUN_004a6290(param_1);

          if (iVar5 != 0) {

            FUN_004b65a0(iVar4,iVar2);

          }

        }

        else {

          FUN_0040a550(iVar4,iVar2);

        }

        iVar5 = FUN_0052e4a0(param_1);

        if (iVar5 != 0) {

          local_3c = *(undefined4 *)(iVar4 + 0x188);

          local_40 = iVar2;

          local_38 = *(undefined4 *)

                      (*(int *)(iVar2 * 0x1c + 0x20 + *(int *)(param_1 + 0x100)) + 0x188);

          FUN_00530bd0(param_1,0,3,0,0xc,&local_40);

        }

        if (param_2 == 0) {

          iVar4 = *(int *)(iVar2 * 0x1c + 0x20 + iVar1);

          local_30 = *(undefined4 *)(iVar4 + 0xa0);

          local_2c = *(undefined4 *)(iVar4 + 0xa4);

          local_28 = *(undefined4 *)(iVar4 + 0xa8);

          fx_get_free_effect__Fv();

          param_2 = 1;

        }

        *(undefined4 *)(iVar3 + 0x24) = 0xffffffff;

      }

    }

  }

  return 1;

}

/* ===== FUN_0041ba60 @ 0x0041BA60 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined4 FUN_0041ba60(int param_1,int param_2)



{

  int iVar1;

  bool bVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  int *piVar7;

  float10 fVar8;

  undefined4 local_c;

  int local_8;

  float local_4;

  

  iVar4 = *(int *)(param_1 + 0x100);

  iVar3 = FUN_004a6200(param_1);

  if (iVar3 != 0) {

    if (param_2 == 6) {

      if (*(int *)(iVar4 + 0xe0) < 1) {

        param_2 = 5;

LAB_0041baa4:

        if (*(int *)(iVar4 + 0xc4) < 1) {

          param_2 = 4;

        }

      }

    }

    else {

      if (param_2 == 5) goto LAB_0041baa4;

      if (param_2 == 8) {

        if (*(int *)(iVar4 + 0x118) < 1) {

          param_2 = 7;

        }

      }

      else if (param_2 == 0xb) {

        if (*(int *)(iVar4 + 0x16c) < 1) {

          param_2 = 10;

LAB_0041bb04:

          if (*(int *)(iVar4 + 0x150) < 1) {

            param_2 = 9;

          }

        }

      }

      else {

        if (param_2 == 10) goto LAB_0041bb04;

        if (param_2 == 0x13) {

          if (0 < *(int *)(iVar4 + 0x24c)) goto LAB_0041bba6;

          param_2 = 0x12;

        }

        else if (param_2 != 0x12) {

          if (param_2 == 0x15) {

            if (*(int *)(iVar4 + 0x284) < 1) {

              param_2 = 0x14;

            }

          }

          else if (param_2 == 0x18) {

            if (*(int *)(iVar4 + 0x2d8) < 1) {

              param_2 = 0x17;

LAB_0041bb8b:

              if (*(int *)(iVar4 + 700) < 1) {

                param_2 = 0x16;

              }

            }

          }

          else if (param_2 == 0x17) goto LAB_0041bb8b;

          goto LAB_0041bba6;

        }

        if (*(int *)(iVar4 + 0x230) < 1) {

          param_2 = 0x11;

        }

      }

    }

  }

LAB_0041bba6:

  piVar7 = (int *)(iVar4 + (param_2 + 2) * 0x1c);

  if (*piVar7 < 1) {

    return 0;

  }

  *piVar7 = *piVar7 + -1;

  if ((*(int *)(param_1 + 0x18c) == 1) && (DAT_00632a88 != 0)) {

    iVar4 = 1;

  }

  else {

    iVar4 = *(int *)(param_1 + 0x18c) + -1;

  }

  (&DAT_006330d0)[iVar4] = (&DAT_006330d0)[iVar4] + 1;

  iVar4 = FUN_0052e4a0(param_1);

  if (iVar4 != 0) {

    local_c._0_2_ = CONCAT11((char)*piVar7,(char)param_2);

    FUN_00530bd0(param_1,0,0,2,0x25,&local_c);

    FUN_0052f8f0(0);

  }

  local_8 = 0;

  iVar4 = FUN_004a6200(param_1);

  if (iVar4 == 0) {

    iVar4 = *(int *)(&DAT_005606c4 + param_2 * 0x58);

  }

  else {

    iVar4 = *(int *)(&DAT_00554574 + param_2 * 0x58);

  }

  if (((*piVar7 < iVar4) &&

      (local_8 = 1, *(int *)(param_1 + 0x18c) == *(int *)(DAT_00632a88 + 0x18c))) &&

     (DAT_00632bb0 != 0)) {

    _DAT_00657674 = 0;

  }

  iVar4 = 0;

  local_4 = 1e+10;

  piVar7 = DAT_00632d98;

  if (DAT_00632d98 != (int *)0x0) {

    do {

      iVar3 = piVar7[3];

      if ((((((*(uint *)(iVar3 + 0xd8) & 0x4000c000) == 0) &&

            (*(int *)(iVar3 + 0x184) != 0x3f800000)) &&

           ((*(int *)(iVar3 + 0x1e0) == 0x12 &&

            (((*(byte *)(iVar3 + 0xe0) & 8) != 0 && (*(int *)(iVar3 + 0xe8) != 10)))))) &&

          (*(int *)(iVar3 + 0x274) == param_1)) &&

         (((iVar6 = *(int *)(iVar3 + 0x100), *(int *)(iVar6 + 0x1c) == param_2 ||

           (*(int *)(iVar6 + 0x24) == param_2)) || (*(int *)(iVar6 + 0x20) == param_2)))) {

        local_c = piVar7;

        if ((local_8 != 0) && (*(int *)(iVar3 + 0x274) != 0)) {

          FUN_00401000(iVar3);

          FUN_004f7af0(iVar3);

          *(undefined1 *)(iVar3 + 0x20b) = 0;

          *(undefined1 *)(iVar3 + 0x20a) = 0;

          *(undefined1 *)(iVar3 + 0x208) = 0;

          *(undefined4 *)(iVar6 + 0x24) = 0xffffffff;

          *(undefined4 *)(iVar6 + 0x20) = 0xffffffff;

          *(undefined4 *)(iVar6 + 0x1c) = 0xffffffff;

          *(undefined4 *)(iVar6 + 0x28) = 0xffffffff;

          if (*(float *)(DAT_00632ed8 + 0x624) == *(float *)(iVar6 + 0x18)) {

            iVar1 = *(int *)(iVar3 + 0x274);

            iVar5 = FUN_004a6200(iVar1);

            if (iVar5 == 0) {

              iVar5 = FUN_004a6290(iVar1);

              if (iVar5 != 0) {

                iVar1 = *(int *)(*(int *)(iVar1 + 0x100) + 0x100);

                bVar2 = false;

                if (iVar1 != 0) {

                  bVar2 = 3 < *(int *)(iVar1 + 0xe4);

                }

                goto LAB_0041bdc7;

              }

            }

            else {

              iVar1 = *(int *)(*(int *)(iVar1 + 0x100) + 0x18c);

              bVar2 = false;

              if (iVar1 != 0) {

                bVar2 = 3 < *(int *)(iVar1 + 0xe4);

              }

LAB_0041bdc7:

              if (bVar2) goto LAB_0041bdd7;

            }

            *(undefined4 *)(iVar3 + 0xe4) = 0x24;

          }

          else {

LAB_0041bdd7:

            *(undefined4 *)(iVar3 + 0xe4) = 0x1e;

          }

        }

        piVar7 = local_c;

        fVar8 = (float10)FUN_0050a5e0(iVar3 + 0xa0,param_1 + 0xa0);

        if (*(float *)(iVar6 + 0x18) < *(float *)(DAT_00632ed8 + 0x624) * 0.1) {

          fVar8 = fVar8 - (float10)40000.0;

        }

        if (fVar8 < (float10)local_4) {

          local_4 = (float)fVar8;

          iVar4 = iVar3;

        }

      }

      piVar7 = (int *)*piVar7;

    } while (piVar7 != (int *)0x0);

    if (iVar4 == 0) {

      return 1;

    }

    if (local_8 != 0) {

      return 1;

    }

    iVar3 = *(int *)(iVar4 + 0x100);

    if (*(int *)(iVar4 + 0x274) == 0) {

      return 1;

    }

    local_c = piVar7;

    FUN_00401000(iVar4);

    FUN_004f7af0(iVar4);

    *(undefined1 *)(iVar4 + 0x20b) = 0;

    *(undefined1 *)(iVar4 + 0x20a) = 0;

    *(undefined1 *)(iVar4 + 0x208) = 0;

    *(undefined4 *)(iVar3 + 0x24) = 0xffffffff;

    *(undefined4 *)(iVar3 + 0x20) = 0xffffffff;

    *(undefined4 *)(iVar3 + 0x1c) = 0xffffffff;

    *(undefined4 *)(iVar3 + 0x28) = 0xffffffff;

    if (*(float *)(DAT_00632ed8 + 0x624) == *(float *)(iVar3 + 0x18)) {

      iVar3 = *(int *)(iVar4 + 0x274);

      iVar6 = FUN_004a6200(iVar3);

      if (iVar6 == 0) {

        iVar6 = FUN_004a6290(iVar3);

        if (iVar6 == 0) goto LAB_0041bf20;

        iVar3 = *(int *)(*(int *)(iVar3 + 0x100) + 0x100);

        bVar2 = false;

        if (iVar3 != 0) {

          bVar2 = 3 < *(int *)(iVar3 + 0xe4);

        }

      }

      else {

        iVar3 = *(int *)(*(int *)(iVar3 + 0x100) + 0x18c);

        bVar2 = false;

        if (iVar3 != 0) {

          bVar2 = 3 < *(int *)(iVar3 + 0xe4);

        }

      }

      if (!bVar2) {

LAB_0041bf20:

        *(undefined4 *)(iVar4 + 0xe4) = 0x24;

        return 1;

      }

    }

    *(undefined4 *)(iVar4 + 0xe4) = 0x1e;

  }

  return 1;

}

/* ===== FUN_0041bf50 @ 0x0041BF50 ===== */
undefined4 FUN_0041bf50(undefined4 param_1,undefined4 param_2)



{

  int iVar1;

  

  iVar1 = FUN_004a6200(param_1);

  if (iVar1 == 0) {

    switch(param_2) {

    case 2:

      return 0x21;

    case 3:

      return 0x22;

    case 4:

      return 0x26;

    case 5:

      return 0x27;

    case 6:

      return 0x28;

    case 7:

      return 0x29;

    case 8:

      goto switchD_0041bf79_caseD_d;

    case 9:

      return 0x25;

    case 10:

      return 0x23;

    case 0xb:

      return 0x24;

    case 0xc:

      return 0x2a;

    case 0xd:

      return 0x2b;

    case 0xe:

      return 0x2c;

    case 0xf:

      return 0x2d;

    }

  }

  else {

    switch(param_2) {

    case 3:

      return 1;

    case 4:

    case 5:

    case 6:

      return 2;

    case 7:

    case 8:

      return 3;

    case 9:

    case 10:

    case 0xb:

      return 4;

    case 0xc:

      return 5;

    case 0xd:

switchD_0041bf79_caseD_d:

      return 0xc;

    case 0xe:

      return 0x20;

    case 0xf:

      return 6;

    case 0x10:

      return 7;

    case 0x11:

    case 0x12:

    case 0x13:

      return 8;

    case 0x14:

    case 0x15:

      return 9;

    case 0x16:

    case 0x17:

    case 0x18:

      return 10;

    case 0x19:

      return 0xb;

    }

  }

  return 0;

}

/* ===== bldg_get_bldg_name @ 0x0041C0C0 ===== */
/* WARNING: Struct "OBJECT": ignoring multiple overlapping fields */



undefined1 * bldg_get_bldg_name(int param_1)



{

  char cVar1;

  OBJECT *p0;

  int iVar2;

  undefined1 *puVar3;

  int iVar4;

  char *pcVar5;

  uint uVar6;

  uint uVar7;

  char *pcVar8;

  char *pcVar9;

  undefined4 local_80;

  undefined4 local_7c;

  undefined1 local_78;

  

  iVar2 = FUN_004a6200(param_1);

  if (iVar2 != 0) {

    puVar3 = (undefined1 *)FUN_00507b00(s_BaseBldgMeccBase_0055581c);

    return puVar3;

  }

  iVar2 = FUN_004a6290(param_1);

  if (iVar2 != 0) {

    puVar3 = (undefined1 *)FUN_00507b00(s_BaseBldgReaperBase_00555808);

    return puVar3;

  }

  iVar2 = FUN_004a6220(param_1);

  if (iVar2 == 0) {

    iVar2 = FUN_004b6f60(param_1);

  }

  else {

    iVar2 = FUN_0040acf0();

  }

  if (-1 < iVar2) {

    p0 = *(OBJECT **)(param_1 + 0x274);

    if (p0 != (OBJECT *)0x0) {

      iVar4 = FUN_004a6200(p0);

      if (iVar4 == 0) {

        pcVar5 = (char *)base_get_required_smarties__FP6OBJECTi(p0,iVar2);

      }

      else {

        pcVar5 = (char *)FUN_00407c30();

      }

      local_80 = DAT_005557f0;

      local_78 = DAT_005557f8;

      local_7c = DAT_005557f4;

      uVar6 = 0xffffffff;

      do {

        pcVar9 = pcVar5;

        if (uVar6 == 0) break;

        uVar6 = uVar6 - 1;

        pcVar9 = pcVar5 + 1;

        cVar1 = *pcVar5;

        pcVar5 = pcVar9;

      } while (cVar1 != '\0');

      uVar6 = ~uVar6;

      iVar2 = -1;

      pcVar5 = (char *)&local_80;

      do {

        pcVar8 = pcVar5;

        if (iVar2 == 0) break;

        iVar2 = iVar2 + -1;

        pcVar8 = pcVar5 + 1;

        cVar1 = *pcVar5;

        pcVar5 = pcVar8;

      } while (cVar1 != '\0');

      pcVar5 = pcVar9 + -uVar6;

      pcVar9 = pcVar8 + -1;

      for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {

        *(undefined4 *)pcVar9 = *(undefined4 *)pcVar5;

        pcVar5 = pcVar5 + 4;

        pcVar9 = pcVar9 + 4;

      }

      for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {

        *pcVar9 = *pcVar5;

        pcVar5 = pcVar5 + 1;

        pcVar9 = pcVar9 + 1;

      }

      puVar3 = (undefined1 *)FUN_00507b00(&local_80);

      return puVar3;

    }

switchD_0041c1e2_caseD_3d9:

    return &DAT_00584374;

  }

  switch(*(undefined4 *)(param_1 + 4)) {

  case 0x3d7:

  case 0x4a8:

    iVar2 = 4;

    break;

  case 0x3d8:

  case 0x49d:

    iVar2 = 3;

    break;

  default:

    goto switchD_0041c1e2_caseD_3d9;

  case 0x3da:

  case 0x3dd:

    iVar2 = 2;

    break;

  case 0x3dc:

  case 0x4a5:

    iVar2 = 1;

    break;

  case 0x425:

  case 0x4a1:

  case 0x4a4:

    iVar2 = 6;

    break;

  case 0x426:

  case 0x4a2:

  case 0x4a3:

    iVar2 = 5;

  }

  iVar4 = FUN_004a6220(param_1);

  if (iVar4 != 0) {

    puVar3 = (undefined1 *)FUN_00507b00(*(undefined4 *)(s_collmgrid_005555c0 + iVar2 * 4 + 8));

    return puVar3;

  }

  puVar3 = (undefined1 *)FUN_00507b00(*(undefined4 *)(iVar2 * 4 + 0x5555e8));

  return puVar3;

}

/* ===== FUN_0041e440 @ 0x0041E440 ===== */
int FUN_0041e440(float param_1)



{

  int iVar1;

  float *pfVar2;

  int iVar3;

  int iVar4;

  undefined4 uVar5;

  int iVar6;

  int *piVar7;

  float10 fVar8;

  int local_8;

  

  iVar3 = (int)param_1;

  iVar1 = *(int *)((int)param_1 + 0x100);

  if (*(int *)(iVar1 + 0x568) != 0) {

    return 0;

  }

  iVar4 = FUN_004a6200(param_1);

  iVar6 = (-(uint)(iVar4 != 0) & 5) + 8;

  iVar4 = FUN_004a6200(iVar3);

  if (iVar4 == 0) {

    uVar5 = (&DAT_005606b0)[iVar6 * 0x16];

  }

  else {

    uVar5 = (&DAT_00554560)[iVar6 * 0x16];

  }

  iVar4 = FUN_00496c00(uVar5,0x80000000);

  iVar6 = iVar6 * 0x1c + iVar1;

  *(int *)(iVar6 + 0x20) = iVar4;

  FUN_004993c0(iVar4,iVar6 + 0x24);

  *(undefined4 *)(iVar4 + 200) = *(undefined4 *)(iVar6 + 0x30);

  *(undefined4 *)(iVar4 + 0xcc) = 0;

  *(undefined4 *)(iVar4 + 0xd0) = 0;

  *(undefined4 *)(iVar4 + 0xe4) = 4;

  *(int *)(iVar4 + 0x274) = iVar3;

  iVar6 = FUN_004a6200(iVar4);

  if (iVar6 == 0) {

    iVar6 = FUN_004a6220(iVar4);

    if (iVar6 != 0) goto LAB_0041e52a;

    iVar6 = FUN_004a6290(iVar4);

    if (iVar6 != 0) {

LAB_0041e522:

      fVar8 = (float10)FUN_004b6d60(iVar4);

      goto LAB_0041e530;

    }

    iVar6 = FUN_004a6300(iVar4);

    if (iVar6 != 0) goto LAB_0041e522;

    param_1 = 50.0;

  }

  else {

LAB_0041e52a:

    fVar8 = (float10)FUN_0040ad30(iVar4);

LAB_0041e530:

    param_1 = (float)fVar8;

  }

  pfVar2 = *(float **)(iVar4 + 0x100);

  iVar6 = FUN_004a6200(iVar4);

  if (iVar6 == 0) {

    iVar6 = FUN_004a6290(iVar4);

    if (iVar6 == 0) {

      iVar6 = FUN_004a6220(iVar4);

      if (iVar6 == 0) {

        iVar6 = FUN_004a6300(iVar4);

        if (iVar6 == 0) goto LAB_0041e5bd;

      }

      if ((pfVar2 != (float *)0x0) && (*pfVar2 = param_1, param_1 < 0.0)) {

        *pfVar2 = 0.0;

      }

      goto LAB_0041e5bd;

    }

  }

  if ((pfVar2 != (float *)0x0) && (pfVar2[0x166] = param_1, param_1 < 0.0)) {

    pfVar2[0x166] = 0.0;

  }

LAB_0041e5bd:

  FUN_004034a0(iVar4,1,0x84,0,0,0);

  *(undefined4 *)(iVar4 + 0x14) = 0x3f800000;

  *(uint *)(iVar4 + 0x1c8) = *(uint *)(iVar4 + 0x1c8) & 0xfffff7ff | 0x20000;

  iVar6 = FUN_004a6200(iVar3);

  if (iVar6 == 0) {

    FUN_004b5810(iVar3);

  }

  else {

    FUN_00409200();

  }

  iVar6 = FUN_0052e4a0(iVar3);

  if (iVar6 != 0) {

    param_1 = *(float *)(iVar4 + 0x188);

    FUN_00530bd0(iVar3,0,1,0,0x10,&param_1);

  }

  iVar6 = FUN_0052e480(iVar3);

  if (iVar6 != 0) {

    piVar7 = (int *)(iVar1 + 0x370);

    local_8 = 5;

    do {

      param_1 = 1.68156e-44;

      do {

        iVar6 = *piVar7;

        if (iVar6 != 0) {

          *(undefined4 *)(iVar6 + 0xe4) = 0x1e;

          FUN_00401000(iVar6);

          *(undefined4 *)(*(int *)(iVar6 + 0x100) + 0x28) = 0xffffffff;

          *piVar7 = 0;

        }

        piVar7 = piVar7 + 2;

        param_1 = (float)((int)param_1 + -1);

      } while (param_1 != 0.0);

      local_8 = local_8 + -1;

    } while (local_8 != 0);

    param_1 = 0.0;

  }

  *(undefined4 *)(iVar3 + 0x184) = 0x3f800000;

  *(uint *)(iVar3 + 0x1c8) = *(uint *)(iVar3 + 0x1c8) & 0xfffdffff | 0x800;

  FUN_004a6200(iVar3);

  if (*(int *)(iVar1 + 0x20) != 0) {

    *(undefined4 *)(*(int *)(iVar1 + 0x20) + 0x184) = 0x3f800000;

    *(undefined4 *)(*(int *)(iVar1 + 0x20) + 0xe4) = 5;

    FUN_004034a0(*(undefined4 *)(iVar1 + 0x20),1,0x10,0,0,0);

  }

  *(undefined4 *)(iVar1 + 0x20) = 0;

  return iVar4;

}

/* ===== FUN_0041e720 @ 0x0041E720 ===== */
void FUN_0041e720(float param_1)



{

  float *pfVar1;

  int iVar2;

  int iVar3;

  float10 fVar4;

  

  iVar3 = (int)param_1;

  iVar2 = FUN_004a6200(param_1);

  if ((iVar2 == 0) && (iVar2 = FUN_004a6220(param_1), iVar2 == 0)) {

    iVar2 = FUN_004a6290(param_1);

    if ((iVar2 == 0) && (iVar2 = FUN_004a6300(param_1), iVar2 == 0)) {

      param_1 = 50.0;

      goto LAB_0041e779;

    }

    fVar4 = (float10)FUN_004b6d60(param_1);

  }

  else {

    fVar4 = (float10)FUN_0040ad30(param_1);

  }

  param_1 = (float)fVar4;

LAB_0041e779:

  pfVar1 = *(float **)(iVar3 + 0x100);

  iVar2 = FUN_004a6200(iVar3);

  if ((iVar2 != 0) || (iVar2 = FUN_004a6290(iVar3), iVar2 != 0)) {

    if ((pfVar1 != (float *)0x0) && (pfVar1[0x166] = param_1, param_1 < 0.0)) {

      pfVar1[0x166] = 0.0;

    }

    return;

  }

  iVar2 = FUN_004a6220(iVar3);

  if ((iVar2 == 0) && (iVar3 = FUN_004a6300(iVar3), iVar3 == 0)) {

    return;

  }

  if (pfVar1 == (float *)0x0) {

    return;

  }

  *pfVar1 = param_1;

  if (0.0 <= param_1) {

    return;

  }

  *pfVar1 = 0.0;

  return;

}

/* ===== FUN_0041e810 @ 0x0041E810 ===== */
void FUN_0041e810(float param_1)



{

  float *pfVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int *piVar5;

  float10 fVar6;

  

  iVar4 = *(int *)((int)param_1 + 0x100);

  iVar2 = FUN_004a6200(param_1);

  if (iVar2 == 0) {

    iVar3 = FUN_004a6290(param_1);

    iVar2 = 0x10;

    if (iVar3 == 0) {

      iVar2 = (int)param_1;

    }

  }

  else {

    iVar2 = 0x1a;

  }

  if (0 < iVar2) {

    piVar5 = (int *)(iVar4 + 0x20);

    do {

      iVar4 = *piVar5;

      if ((iVar4 != 0) && ((*(int *)(iVar4 + 0xe4) == 2 || (*(int *)(iVar4 + 0xe4) == 3)))) {

        iVar3 = FUN_004a6200(iVar4);

        if ((iVar3 == 0) && (iVar3 = FUN_004a6220(iVar4), iVar3 == 0)) {

          iVar3 = FUN_004a6290(iVar4);

          if ((iVar3 != 0) || (iVar3 = FUN_004a6300(iVar4), iVar3 != 0)) {

            fVar6 = (float10)FUN_004b6d60(iVar4);

            goto LAB_0041e8bf;

          }

          param_1 = 50.0;

        }

        else {

          fVar6 = (float10)FUN_0040ad30(iVar4);

LAB_0041e8bf:

          param_1 = (float)fVar6;

        }

        iVar4 = *piVar5;

        pfVar1 = *(float **)(iVar4 + 0x100);

        iVar3 = FUN_004a6200(iVar4);

        if ((iVar3 == 0) && (iVar3 = FUN_004a6290(iVar4), iVar3 == 0)) {

          iVar3 = FUN_004a6220(iVar4);

          if (((iVar3 != 0) || (iVar4 = FUN_004a6300(iVar4), iVar4 != 0)) &&

             ((pfVar1 != (float *)0x0 && (*pfVar1 = param_1, param_1 < 0.0)))) {

            *pfVar1 = 0.0;

          }

        }

        else if ((pfVar1 != (float *)0x0) && (pfVar1[0x166] = param_1, param_1 < 0.0)) {

          pfVar1[0x166] = 0.0;

        }

      }

      piVar5 = piVar5 + 7;

      iVar2 = iVar2 + -1;

    } while (iVar2 != 0);

  }

  return;

}

/* ===== FUN_0041e960 @ 0x0041E960 ===== */
/* PS2 candidate: repair_logic (conf 0.45) */



void FUN_0041e960(float param_1)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int *piVar6;

  float10 fVar7;

  int local_8;

  

  iVar1 = (int)param_1;

  iVar5 = *(int *)((int)param_1 + 0x100);

  iVar2 = FUN_0052aa70();

  if ((iVar2 == 0) && (*(int *)(iVar5 + 0x568) == 0)) {

    iVar2 = FUN_004a6200(param_1);

    if (iVar2 == 0) {

      iVar2 = FUN_004a6290(param_1);

      if (iVar2 == 0) {

        return;

      }

      local_8 = 8;

    }

    else {

      local_8 = 0xd;

    }

    iVar2 = *(int *)((int)param_1 + 0x100);

    iVar3 = FUN_004a6200(param_1);

    if (iVar3 == 0) {

      iVar4 = FUN_004a6290(param_1);

      iVar3 = 0x10;

      if (iVar4 == 0) {

        iVar3 = (int)param_1;

      }

    }

    else {

      iVar3 = 0x1a;

    }

    if (0 < iVar3) {

      piVar6 = (int *)(iVar2 + 0x20);

      do {

        iVar2 = *piVar6;

        if ((iVar2 != 0) && ((*(int *)(iVar2 + 0xe4) == 2 || (*(int *)(iVar2 + 0xe4) == 3)))) {

          iVar4 = FUN_004a6200(iVar2);

          if ((iVar4 == 0) && (iVar4 = FUN_004a6220(iVar2), iVar4 == 0)) {

            iVar4 = FUN_004a6290(iVar2);

            if ((iVar4 != 0) || (iVar4 = FUN_004a6300(iVar2), iVar4 != 0)) {

              fVar7 = (float10)FUN_004b6d60(iVar2);

              goto LAB_0041ea62;

            }

            param_1 = 50.0;

          }

          else {

            fVar7 = (float10)FUN_0040ad30(iVar2);

LAB_0041ea62:

            param_1 = (float)fVar7;

          }

          FUN_00418010(*piVar6,param_1);

        }

        piVar6 = piVar6 + 7;

        iVar3 = iVar3 + -1;

      } while (iVar3 != 0);

    }

    iVar2 = FUN_00496c00(0xb,0x80000000);

    iVar3 = 0;

    *(int *)(iVar2 + 0x274) = iVar1;

    if (local_8 != 0) {

      piVar6 = (int *)(iVar5 + 0x20);

      do {

        iVar5 = FUN_004a6200(iVar1);

        if (iVar5 == 0) {

          if (*piVar6 == 0) goto LAB_0041eae1;

          iVar4 = FUN_004a6200(iVar1);

          iVar5 = iVar3 + 8;

          if (iVar4 == 0) goto LAB_0041eb12;

          FUN_0040a5e0(iVar1,iVar5);

LAB_0041eb17:

          iVar4 = FUN_004a6200(iVar1);

          if (iVar4 == 0) {

            iVar4 = FUN_004a6290(iVar1);

            if (iVar4 != 0) {

LAB_0041eb6c:

              FUN_004b65a0(iVar2,iVar5);

            }

          }

          else {

            FUN_0040a550(iVar2,iVar5);

          }

        }

        else {

          if (*piVar6 != 0) {

            iVar4 = FUN_004a6200(iVar1);

            iVar5 = iVar3 + 0xd;

            if (iVar4 == 0) {

LAB_0041eb12:

              FUN_004b6630(iVar1,iVar5);

            }

            else {

              FUN_0040a5e0();

            }

            goto LAB_0041eb17;

          }

LAB_0041eae1:

          iVar5 = FUN_004a6200(iVar1);

          if (iVar5 == 0) {

            FUN_004b6630(iVar1,iVar3);

          }

          else {

            FUN_0040a5e0();

          }

          iVar5 = FUN_004a6200(iVar1);

          if (iVar5 == 0) {

            iVar4 = FUN_004a6290(iVar1);

            iVar5 = iVar3;

            if (iVar4 == 0) goto LAB_0041eb75;

            goto LAB_0041eb6c;

          }

          FUN_0040a550(iVar2,iVar3);

        }

LAB_0041eb75:

        iVar3 = iVar3 + 1;

        piVar6 = piVar6 + 7;

      } while (iVar3 < local_8);

    }

    FUN_00497510(iVar2);

    DAT_00657678 = 1;

    FUN_0041e810(iVar1);

  }

  return;

}

/* ===== FUN_0041ebb0 @ 0x0041EBB0 ===== */
/* PS2 candidate: do_building_move__FP6OBJECT (conf 0.492) */



void FUN_0041ebb0(int param_1)



{

  int iVar1;

  undefined4 *puVar2;

  int iVar3;

  

  for (puVar2 = DAT_00632d9c; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {

    iVar1 = puVar2[3];

    iVar3 = FUN_004a6220(iVar1);

    if ((iVar3 != 0) && (*(int *)(iVar1 + 0x274) == param_1)) {

      FUN_00408530(iVar1);

    }

  }

  return;

}

/* ===== FUN_0041ebf0 @ 0x0041EBF0 ===== */
/* PS2 candidate: repair_logic (conf 0.36) */



void FUN_0041ebf0(int param_1,float param_2,int param_3)



{

  undefined4 *puVar1;

  undefined4 *puVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  int *piVar7;

  float10 fVar8;

  float local_4;

  

  iVar3 = FUN_00496c00(0xb,0x80000000);

  *(int *)(iVar3 + 0x274) = param_1;

  iVar6 = *(int *)(param_1 + 0x100);

  iVar4 = FUN_004a6200(param_1);

  if (iVar4 == 0) {

    iVar5 = FUN_004a6290(param_1);

    iVar4 = 0x10;

    if (iVar5 == 0) {

      iVar4 = param_1;

    }

  }

  else {

    iVar4 = 0x1a;

  }

  if (0 < iVar4) {

    piVar7 = (int *)(iVar6 + 0x20);

    do {

      iVar6 = *piVar7;

      if ((iVar6 != 0) && ((*(int *)(iVar6 + 0xe4) == 2 || (*(int *)(iVar6 + 0xe4) == 3)))) {

        iVar5 = FUN_004a6200(iVar6);

        if ((iVar5 == 0) && (iVar5 = FUN_004a6220(iVar6), iVar5 == 0)) {

          iVar5 = FUN_004a6290(iVar6);

          if ((iVar5 != 0) || (iVar5 = FUN_004a6300(iVar6), iVar5 != 0)) {

            fVar8 = (float10)FUN_004b6d60(iVar6);

            goto LAB_0041ecb2;

          }

          local_4 = 50.0;

        }

        else {

          fVar8 = (float10)FUN_0040ad30(iVar6);

LAB_0041ecb2:

          local_4 = (float)fVar8;

        }

        FUN_00418010(*piVar7,local_4);

      }

      piVar7 = piVar7 + 7;

      iVar4 = iVar4 + -1;

    } while (iVar4 != 0);

  }

  for (; (int)param_2 <= param_3; param_2 = (float)((int)param_2 + 1)) {

    iVar6 = FUN_004a6200(param_1);

    if (iVar6 == 0) {

      FUN_004b6630(param_1,param_2);

    }

    else {

      FUN_0040a5e0();

    }

    iVar6 = FUN_004a6200(param_1);

    if (iVar6 == 0) {

      iVar6 = FUN_004a6290(param_1);

      if (iVar6 != 0) {

        FUN_004b65a0(iVar3,param_2);

      }

    }

    else {

      FUN_0040a550(iVar3,param_2);

    }

  }

  FUN_00497510(iVar3);

  iVar6 = *(int *)(param_1 + 0x100);

  iVar3 = FUN_004a6200(param_1);

  if (iVar3 == 0) {

    iVar4 = FUN_004a6290(param_1);

    iVar3 = 0x10;

    if (iVar4 == 0) {

      iVar3 = param_1;

    }

  }

  else {

    iVar3 = 0x1a;

  }

  puVar2 = DAT_00632d9c;

  if (0 < iVar3) {

    piVar7 = (int *)(iVar6 + 0x20);

    do {

      iVar6 = *piVar7;

      if ((iVar6 != 0) && ((*(int *)(iVar6 + 0xe4) == 2 || (*(int *)(iVar6 + 0xe4) == 3)))) {

        iVar4 = FUN_004a6200(iVar6);

        if ((iVar4 == 0) && (iVar4 = FUN_004a6220(iVar6), iVar4 == 0)) {

          iVar4 = FUN_004a6290(iVar6);

          if ((iVar4 != 0) || (iVar4 = FUN_004a6300(iVar6), iVar4 != 0)) {

            fVar8 = (float10)FUN_004b6d60(iVar6);

            goto LAB_0041edda;

          }

          param_2 = 50.0;

        }

        else {

          fVar8 = (float10)FUN_0040ad30(iVar6);

LAB_0041edda:

          param_2 = (float)fVar8;

        }

        FUN_00418010(*piVar7,param_2);

      }

      piVar7 = piVar7 + 7;

      iVar3 = iVar3 + -1;

      puVar2 = DAT_00632d9c;

    } while (iVar3 != 0);

  }

  for (; puVar1 = DAT_00632d9c, puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {

    iVar6 = puVar2[3];

    iVar3 = FUN_004a6220(iVar6);

    if ((iVar3 != 0) && (*(int *)(iVar6 + 0x274) == param_1)) {

      FUN_00408530(iVar6);

    }

  }

  for (; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {

    iVar6 = puVar1[3];

    iVar3 = FUN_004a6220(iVar6);

    if ((iVar3 != 0) && (*(int *)(iVar6 + 0x274) == param_1)) {

      FUN_00408530(iVar6);

    }

  }

  return;

}

/* ===== FUN_0041ee70 @ 0x0041EE70 ===== */
void FUN_0041ee70(int param_1)



{

  int iVar1;

  int iVar2;

  int iVar3;

  

  iVar2 = *(int *)(param_1 + 0x100);

  iVar1 = FUN_0052aa70();

  if (((iVar1 == 0) && (*(int *)(iVar2 + 0x568) == 0)) &&

     (iVar2 = FUN_004a6290(param_1), iVar2 == 0)) {

    iVar2 = *(int *)(param_1 + 0x100);

    if ((*(int *)(iVar2 + 0x1fc) == 0) || (*(int *)(*(int *)(iVar2 + 0x1fc) + 0xe4) < 2)) {

      if ((*(int *)(iVar2 + 0x250) == 0) || (*(int *)(*(int *)(iVar2 + 0x250) + 0xe4) < 2)) {

        if ((*(int *)(iVar2 + 0x288) == 0) || (*(int *)(*(int *)(iVar2 + 0x288) + 0xe4) < 2)) {

          if ((*(int *)(iVar2 + 0x90) == 0) || (*(int *)(*(int *)(iVar2 + 0x90) + 0xe4) < 2)) {

            if ((*(int *)(iVar2 + 0xe4) == 0) || (*(int *)(*(int *)(iVar2 + 0xe4) + 0xe4) < 2)) {

              iVar2 = FUN_00418510(param_1,9);

              if (iVar2 == 0) {

                return;

              }

              FUN_0041ebf0(param_1,9,0xb);

              return;

            }

            iVar2 = FUN_00496c00(0xb,0x80000000);

            *(int *)(iVar2 + 0x274) = param_1;

            FUN_0041e810(param_1);

            iVar1 = 7;

            do {

              FUN_00416a30(param_1,iVar1);

              FUN_00416990(param_1,iVar1,iVar2,0);

              iVar1 = iVar1 + 1;

            } while (iVar1 < 9);

          }

          else {

            iVar2 = FUN_00496c00(0xb,0x80000000);

            *(int *)(iVar2 + 0x274) = param_1;

            FUN_0041e810(param_1);

            iVar1 = 4;

            do {

              FUN_00416a30(param_1,iVar1);

              FUN_00416990(param_1,iVar1,iVar2,0);

              iVar1 = iVar1 + 1;

            } while (iVar1 < 7);

          }

        }

        else {

          iVar2 = FUN_00496c00(0xb,0x80000000);

          *(int *)(iVar2 + 0x274) = param_1;

          FUN_0041e810(param_1);

          iVar1 = 0x16;

          do {

            iVar3 = FUN_004a6200(param_1);

            if (iVar3 == 0) {

              FUN_004b6630(param_1,iVar1);

            }

            else {

              FUN_0040a5e0();

            }

            FUN_00416990(param_1,iVar1,iVar2,0);

            iVar1 = iVar1 + 1;

          } while (iVar1 < 0x19);

        }

      }

      else {

        iVar2 = FUN_00496c00(0xb,0x80000000);

        *(int *)(iVar2 + 0x274) = param_1;

        FUN_0041e810(param_1);

        iVar1 = 0x14;

        do {

          iVar3 = FUN_004a6200(param_1);

          if (iVar3 == 0) {

            FUN_004b6630(param_1,iVar1);

          }

          else {

            FUN_0040a5e0();

          }

          FUN_00416990(param_1,iVar1,iVar2,0);

          iVar1 = iVar1 + 1;

        } while (iVar1 < 0x16);

      }

    }

    else {

      iVar2 = FUN_00496c00(0xb,0x80000000);

      *(int *)(iVar2 + 0x274) = param_1;

      FUN_0041e810(param_1);

      iVar1 = 0x11;

      do {

        iVar3 = FUN_004a6200(param_1);

        if (iVar3 == 0) {

          FUN_004b6630(param_1,iVar1);

        }

        else {

          FUN_0040a5e0();

        }

        FUN_00416990(param_1,iVar1,iVar2,0);

        iVar1 = iVar1 + 1;

      } while (iVar1 < 0x14);

    }

    FUN_00497510(iVar2);

    FUN_0041e810(param_1);

    FUN_0041ebb0(param_1);

    FUN_0041ebb0(param_1);

    return;

  }

  return;

}

/* ===== FUN_0041f0f0 @ 0x0041F0F0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_0041f0f0(undefined4 param_1)



{

  _DAT_0058c5d4 = param_1;

  FUN_00519C70();

  return;

}

/* ===== FUN_0041f100 @ 0x0041F100 ===== */
void FUN_0041f100(int param_1,int param_2)



{

  DAT_00632abc = (float)param_1;

  DAT_00632ac0 = (float)param_2;

  return;

}

/* ===== FUN_0041f120 @ 0x0041F120 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* PS2 candidate: turret_process (conf 0.469) */



void FUN_0041f120(void)



{

  byte bVar1;

  bool bVar2;

  undefined4 uVar3;

  undefined1 uVar4;

  int iVar5;

  int iVar6;

  byte bVar7;

  int iVar8;

  uint uVar9;

  undefined4 *puVar10;

  float10 fVar11;

  float10 extraout_ST0;

  float10 extraout_ST0_00;

  float10 extraout_ST0_01;

  undefined4 uVar12;

  

  FUN_0041f960();

  if (DAT_00632fac != 0) {

    return;

  }

  if ((0 < DAT_00632f08) && (DAT_00632f08 < 0xe)) {

    return;

  }

  if (DAT_00632a88 != 0) {

    _DAT_00584574 = *(undefined4 *)(DAT_00632a88 + 0x1b0);

    DAT_00584578 = *(undefined4 *)(DAT_00632a88 + 0x198);

  }

  _DAT_0058457c = DAT_00584578;

  _DAT_00584584 = 0x3f800000;

  _DAT_00584580 = 0x3f000000;

  puVar10 = (undefined4 *)(DAT_00632a88 + 0x208);

  if (DAT_00632a88 == 0) {

    puVar10 = &DAT_005844d8;

  }

  *puVar10 = 0;

  puVar10[1] = 0;

  DAT_00632aa0._0_1_ = '\0';

  iVar5 = 0;

  do {

    if (((&DAT_005dd120)[(&DAT_00555948)[iVar5]] & 1 << ((byte)(&DAT_005559b0)[iVar5] & 0x1f)) != 0)

    {

      DAT_00632aa0._0_1_ = (char)iVar5 + 'A';

    }

    iVar5 = iVar5 + 1;

  } while (iVar5 < 0x1a);

  FUN_00519d30();

  DAT_00632aed = (byte)(DAT_005dd0f8 >> 8) & 1;

  DAT_00632aee = DAT_005dd0f8._2_1_ & 1;

  DAT_00632aef = (byte)(DAT_005dd0f8 >> 0xb) & 1;

  DAT_00632af0 = (byte)(DAT_005dd0f8 >> 0xd) & 1;

  DAT_00632af1 = (byte)(DAT_005dd0f8 >> 9) & 1;

  DAT_00632af2 = (byte)(DAT_005dd0f8 >> 0x11) & 1;

  if (((DAT_005dd0e0 >> 0x1d & 1) == 0) && ((DAT_005dd0f0 >> 0x1d & 1) == 0)) {

    DAT_00632af3 = '\0';

  }

  else {

    DAT_00632af3 = '\x01';

  }

  DAT_00632af4 = (byte)(DAT_005dd120 >> 0x19) & 1;

  bVar7 = (byte)(DAT_005dd124 >> 0x18);

  DAT_00632ad8 = bVar7 >> 3 & 1;

  if (DAT_00632af3 == '\0') {

    DAT_00632aea = bVar7 >> 4 & 1;

  }

  iVar5 = FUN_00426ed0();

  if (iVar5 != 0) {

    if (((DAT_005dd120 >> 0xd & 1) != 0) &&

       (((DAT_005dd0e4 >> 0x16 & 1) != 0 || ((DAT_005dd0e4 >> 10 & 1) != 0)))) {

      iVar5 = FUN_005160a0();

      FUN_00515f60(iVar5 + -1);

    }

    if (((DAT_005dd120 >> 0xc & 1) != 0) &&

       (((DAT_005dd0e4 >> 0x16 & 1) != 0 || ((DAT_005dd0e4 >> 10 & 1) != 0)))) {

      iVar5 = FUN_005160a0();

      FUN_00515f60(iVar5 + 1);

    }

  }

  _DAT_006328f0 = 0x3f800000;

  iVar5 = FUN_0052aa70();

  if (iVar5 == 0) {

    DAT_00632ae5 = (byte)(DAT_005dd120 >> 0x19) & 1;

  }

  if ((0.0 < _DAT_00633024) && (iVar5 = FUN_004469e0(), iVar5 == 0)) {

    fVar11 = (float10)FUN_00518b70(0,0);

    fVar11 = (float10)_DAT_00633024 - fVar11;

    _DAT_00633024 = (float)fVar11;

    if (fVar11 < (float10)0.0 != (fVar11 == (float10)0.0)) {

      DAT_00633020 = 1;

      DAT_00633028 = 1;

      DAT_0063302c = 0;

      _DAT_00633024 = 0.0;

      goto LAB_0041f398;

    }

  }

  if (DAT_00633020 != 0) {

LAB_0041f398:

    iVar5 = FUN_004469e0();

    if ((iVar5 == 0) &&

       (((((DAT_00632aa8 != '\0' || (DAT_00632aab != '\0')) || (DAT_00632aae != '\0')) ||

         ((DAT_00632aa4._3_1_ != '\0' || (DAT_00632ab9 != '\0')))) ||

        (((DAT_005dd124 >> 0x19 & 1) != 0 || (DAT_00632aea != 0)))))) {

      if (DAT_00633028 == 0) {

        FUN_00536150();

      }

      else {

        FUN_00536120();

      }

      iVar5 = DAT_00632a88;

      puVar10 = &DAT_00632aa0;

      for (iVar8 = 0x1f; iVar8 != 0; iVar8 = iVar8 + -1) {

        *puVar10 = 0;

        puVar10 = puVar10 + 1;

      }

      _DAT_00632ac4 = DAT_00632abc;

      _DAT_00632ac8 = DAT_00632ac0;

      DAT_00633020 = 0;

      DAT_00633028 = 0;

      iVar5 = FUN_004a6160(iVar5);

      if (iVar5 != 0) {

        *(uint *)(DAT_00632a88 + 0xe0) = *(uint *)(DAT_00632a88 + 0xe0) | 0x100000;

        return;

      }

      iVar5 = FUN_004a6180(DAT_00632a88);

      if (iVar5 != 0) {

        **(uint **)(DAT_00632a88 + 0x100) = **(uint **)(DAT_00632a88 + 0x100) | 8;

        return;

      }

    }

    return;

  }

  puVar10[1] = 0;

  iVar5 = FUN_004a6180(DAT_00632a88);

  if (iVar5 == 0) {

    iVar5 = FUN_004a6160(DAT_00632a88);

    if (iVar5 == 0) {

      iVar5 = FUN_004a61a0(DAT_00632a88);

      iVar5 = 3 - (uint)(iVar5 != 0);

    }

    else {

      iVar5 = 1;

    }

  }

  else {

    iVar5 = 0;

  }

  if (DAT_00632e74 == 0) {

    iVar8 = 0;

    do {

      iVar6 = FUN_00426ed0();

      bVar7 = (byte)iVar8;

      if ((iVar6 != 0) ||

         ((iVar6 = FUN_004a6160(DAT_00632a88), iVar6 != 0 && (1 << (bVar7 & 0x1f) == 1)))) {

        iVar6 = (iVar5 * 0x2c + iVar8) * 2;

        bVar1 = (&DAT_00584378)[iVar6];

        uVar9 = (uint)bVar1;

        iVar6 = (int)(char)(&DAT_00584379)[iVar6];

        if (uVar9 == 100 || bVar1 < 100) {

          iVar6 = FUN_00420180(uVar9,iVar6);

LAB_0041f57d:

          if (iVar6 != 0) {

            puVar10[1] = puVar10[1] | 1 << (bVar7 & 0x1f);

          }

        }

        else if (uVar9 == 0x6e || bVar1 < 0x6e) {

          iVar6 = FUN_00420090(uVar9,iVar6);

          if (iVar6 != 0) {

            puVar10[1] = puVar10[1] | 1 << (bVar7 & 0x1f);

          }

        }

        else if (uVar9 < 0x100) {

          iVar6 = FUN_0041fed0(uVar9,iVar6);

          goto LAB_0041f57d;

        }

      }

      iVar8 = iVar8 + 1;

    } while (iVar8 < 0x20);

  }

  iVar8 = 0x20;

  do {

    iVar6 = FUN_00426ed0();

    if ((iVar6 != 0) ||

       (((((DAT_00632ba8 != 0 || (DAT_00632bb4 != 0)) || (DAT_00632bb0 != 0)) ||

         ((DAT_00632bb8 != 0 || (DAT_00632bac != 0)))) &&

        ((iVar8 == 0x2a || (((DAT_00632ba8 != 0 && (DAT_00632bac == 0)) && (iVar8 == 0x23)))))))) {

      iVar6 = (iVar5 * 0x2c + iVar8) * 2;

      bVar7 = (&DAT_00584378)[iVar6];

      iVar6 = (int)(char)(&DAT_00584379)[iVar6];

      if (bVar7 < 0x65) {

        iVar6 = FUN_00420180(bVar7,iVar6);

      }

      else if (bVar7 < 0x6f) {

        iVar6 = FUN_00420090(bVar7,iVar6);

      }

      else {

        iVar6 = FUN_0041fed0(bVar7,iVar6);

      }

      if (iVar6 != 0) {

        FUN_00420780(puVar10,iVar8);

      }

    }

    uVar3 = DAT_0058c5e8;

    uVar12 = DAT_0058c5e4;

    iVar6 = iVar8 + -0x1f;

    iVar8 = iVar8 + 1;

  } while (iVar6 < 0xc);

  iVar5 = FUN_0041fed0(0xf0,1);

  if (iVar5 == 0) {

    iVar5 = FUN_0041fed0(0xf2,1);

    DAT_0058c5e4 = -(uint)(iVar5 != 0);

  }

  else {

    DAT_0058c5e4 = 1;

  }

  iVar5 = FUN_0041fed0(0xf3,1);

  if (iVar5 == 0) {

    iVar5 = FUN_0041fed0(0xf1,1);

    DAT_0058c5e8 = -(uint)(iVar5 != 0);

  }

  else {

    DAT_0058c5e8 = 1;

  }

  FUN_00420280(DAT_0058c5e8,DAT_0058c5e4,uVar3,uVar12);

  if (DAT_005dd22c == -0x17) {

    uVar12 = 0x24;

LAB_0041f6ee:

    FUN_00420780(puVar10,uVar12);

  }

  else if (DAT_005dd22c == 0x19) {

    uVar12 = 0x25;

    goto LAB_0041f6ee;

  }

  if (DAT_005dd228 == -0x17) {

    uVar12 = 0x26;

  }

  else {

    if (DAT_005dd228 != 0x19) goto LAB_0041f715;

    uVar12 = 0x27;

  }

  FUN_00420780(puVar10,uVar12);

LAB_0041f715:

  if (DAT_00633124 != 0) {

    return;

  }

  iVar5 = FUN_00426ed0();

  if (iVar5 == 0) {

    return;

  }

  if ((DAT_00632e74 == 0) ||

     ((((DAT_00632ad2 == '\0' && DAT_00632ad1 == '\0') && DAT_00632acf == '\0') &&

      DAT_00632ace == '\0') && DAT_00632acd == '\0')) {

    bVar2 = true;

  }

  else {

    bVar2 = false;

  }

  if ((DAT_005dd21c == 0) || (!bVar2)) {

    _DAT_0058c5ec = 0.0;

  }

  else {

    iVar5 = __ftol();

    _DAT_0058c5ec = (float)(extraout_ST0 - (float10)iVar5);

    if (DAT_00632b20._3_1_ != '\0') {

      iVar5 = -iVar5;

    }

    if (iVar5 < 0x80) {

      if (iVar5 < -0x80) {

        iVar5 = -0x80;

      }

    }

    else {

      iVar5 = 0x7f;

    }

    uVar4 = (undefined1)iVar5;

    switch(DAT_00632b20 & 0xff) {

    case 1:

      *(undefined1 *)puVar10 = uVar4;

      break;

    case 2:

      *(undefined1 *)((int)puVar10 + 3) = uVar4;

      break;

    case 3:

      *(undefined1 *)((int)puVar10 + 2) = uVar4;

      break;

    case 4:

      *(undefined1 *)((int)puVar10 + 1) = uVar4;

    }

  }

  if ((DAT_005dd220 == 0) || (!bVar2)) {

    _DAT_0058c5f0 = 0.0;

  }

  else {

    iVar5 = __ftol();

    _DAT_0058c5f0 = (float)(extraout_ST0_00 - (float10)iVar5);

    FUN_0041f8f0(puVar10,iVar5,DAT_00632b20 >> 8 & 0xff,DAT_00632b24 & 0xff);

  }

  if ((DAT_005dd224 != 0) && (bVar2)) {

    iVar5 = __ftol();

    _DAT_0058c5f4 = (float)(extraout_ST0_01 - (float10)iVar5);

    FUN_0041f8f0(puVar10,iVar5,DAT_00632b20 >> 0x10 & 0xff,DAT_00632b24 >> 8 & 0xff);

    return;

  }

  _DAT_0058c5f4 = 0.0;

  return;

}

/* ===== FUN_0041f8f0 @ 0x0041F8F0 ===== */
void FUN_0041f8f0(undefined1 *param_1,int param_2,undefined4 param_3,int param_4)



{

  undefined1 uVar1;

  

  if (param_4 != 0) {

    param_2 = -param_2;

  }

  if (param_2 < 0x80) {

    if (param_2 < -0x80) {

      param_2 = -0x80;

    }

  }

  else {

    param_2 = 0x7f;

  }

  uVar1 = (undefined1)param_2;

  switch(param_3) {

  case 1:

    *param_1 = uVar1;

    return;

  case 2:

    param_1[3] = uVar1;

    return;

  case 3:

    param_1[2] = uVar1;

    return;

  case 4:

    param_1[1] = uVar1;

  }

  return;

}

/* ===== FUN_0041f960 @ 0x0041F960 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_0041f960(void)



{

  float fVar1;

  int iVar2;

  uint uVar3;

  uint uVar4;

  undefined4 *puVar5;

  bool bVar6;

  bool bVar7;

  bool bVar8;

  

  uVar3 = DAT_005dd120;

  uVar4 = DAT_005dd0f8;

  puVar5 = &DAT_00632aa0;

  for (iVar2 = 0x1f; iVar2 != 0; iVar2 = iVar2 + -1) {

    *puVar5 = 0;

    puVar5 = puVar5 + 1;

  }

  _DAT_00632ac4 = DAT_00632abc;

  _DAT_00632ac8 = DAT_00632ac0;

  if (DAT_00632e74 != 0) {

    if (((DAT_005dd0e4 >> 10 & 1) != 0) || (DAT_00632acc = 0, (DAT_005dd0e4 >> 0x16 & 1) != 0)) {

      DAT_00632acc = 1;

    }

    DAT_00632acd = (byte)(uVar4 >> 0x12) & 1;

    DAT_00632ace = (byte)(uVar4 >> 7) & 1;

    DAT_00632acf = (byte)(uVar4 >> 9) & 1;

    DAT_00632ad1 = (byte)(uVar4 >> 0x13) & 1;

    DAT_00632ad0 = (byte)(uVar4 >> 0x11) & 1;

    DAT_00632ad2 = (byte)(uVar4 >> 0xf) & 1;

    if ((((byte)(DAT_005dd0e0 >> 0x1d) & 1) != 0) ||

       (DAT_00632ad5 = 0, ((byte)((uint)DAT_005dd0f0 >> 0x1d) & 1) != 0)) {

      DAT_00632ad5 = 1;

    }

    DAT_00632ad3 = (byte)(uVar3 >> 0x16) & 1;

    DAT_00632ad4 = (byte)(uVar3 >> 0x13) & 1;

    DAT_00632ad6 = (byte)(DAT_005dd0e0 >> 0x14) & 1;

    DAT_00632ad7 = (byte)(DAT_005dd0e0 >> 0x15) & 1;

  }

  _DAT_00632b10 = (float)DAT_005dd21c;

  _DAT_00632b14 = (float)DAT_005dd220;

  DAT_00632aa0._1_1_ = (byte)(DAT_005dd138 >> 8) & 1;

  DAT_00632aa0._2_1_ = DAT_005dd138._2_1_ & 1;

  _DAT_00632b18 = (float)DAT_005dd224;

  DAT_00632aa0._3_1_ = (byte)(DAT_005dd138 >> 0xb) & 1;

  DAT_00632aa4._0_1_ = (byte)(DAT_005dd138 >> 0xd) & 1;

  DAT_00632aa4._3_1_ = (byte)(uVar3 >> 1) & 1;

  if (((DAT_00633104 != 0) && ((uVar3 >> 1 & 1) == 0)) &&

     (iVar2 = FUN_0041fed0(0x7a,3), uVar3 = DAT_005dd120, uVar4 = DAT_005dd0f8, iVar2 != 0)) {

    DAT_00632aa4._3_1_ = 1;

  }

  if (((((DAT_005dd0e4 & 0x1000000) == 0) && ((DAT_005dd0f7 & 1) == 0)) &&

      (((DAT_005dd144._3_1_ & 1) == 0 &&

       (((DAT_005dd157 & 1) == 0 && ((DAT_005dd124 & 0x1000000) == 0)))))) &&

     ((DAT_005dd137 & 1) == 0)) {

    DAT_00632aa8 = (byte)(uVar3 >> 0x1c) & 1;

  }

  else {

    DAT_00632aa8 = 0;

  }

  DAT_00632aa9 = (byte)((uint)DAT_005dd140 >> 0x1c) & 1;

  DAT_00632ab9 = (byte)(uVar3 >> 0xe) & 1;

  DAT_00632ab3 = (byte)(DAT_005dd138 >> 0x13) & 1;

  DAT_00632ab4 = (byte)(DAT_005dd138 >> 0x12) & 1;

  DAT_00632ab5 = (byte)(DAT_005dd138 >> 7) & 1;

  DAT_00632ab6 = (byte)(DAT_005dd138 >> 0xf) & 1;

  DAT_00632ab8 = (byte)(DAT_005dd138 >> 0x11) & 1;

  DAT_00632ab7 = (byte)(DAT_005dd138 >> 9) & 1;

  DAT_00632aba = (byte)(uVar3 >> 0xf) & 1;

  if (DAT_00633104 == 0) {

    DAT_00632aab = DAT_005dd240 & 1;

    DAT_00632aaa = DAT_005dd23c & 1;

    DAT_00632aac = DAT_005dd238 & 1;

    DAT_00632aae = DAT_005dd240 & 2;

    DAT_00632aad = DAT_005dd23c & 2;

    DAT_00632aaf = DAT_005dd238 & 2;

    DAT_00632ab1 = DAT_005dd240 & 4;

    DAT_00632ab0 = DAT_005dd23c & 4;

    DAT_00632ab2 = DAT_005dd238 & 4;

  }

  else {

    bVar6 = (DAT_005dd1d0 & 0x80) == 0;

    if (bVar6) {

      DAT_00632aaa = DAT_005dd204 >> 7;

      DAT_00632aab = 0;

    }

    else {

      DAT_00632aab = (byte)~DAT_005dd204 >> 7;

      DAT_00632aaa = 0;

    }

    DAT_00632aac = !bVar6;

    bVar6 = (DAT_005dd1d1 & 0x80) == 0;

    if (bVar6) {

      DAT_00632aad = DAT_005dd205 >> 7;

      DAT_00632aae = 0;

    }

    else {

      DAT_00632aae = (byte)~DAT_005dd205 >> 7;

      DAT_00632aaa = 0;

    }

    DAT_00632aaf = !bVar6;

    if ((DAT_005dd1c8 & 0x80) == 0) {

      DAT_00632ab0 = DAT_005dd1fc >> 7;

      DAT_00632ab2 = 0;

      DAT_00632ab1 = 0;

    }

    else {

      DAT_00632ab1 = (byte)~DAT_005dd1fc >> 7;

      DAT_00632ab2 = 1;

      DAT_00632aaa = 0;

    }

  }

  DAT_00632abc = DAT_00632abc + _DAT_00632b10;

  DAT_00632aa4._2_1_ = (byte)(DAT_005dd124 >> 0x14) & 1;

  DAT_00632ac0 = DAT_00632ac0 - _DAT_00632b14;

  DAT_00632aa4._1_1_ = (byte)(DAT_005dd124 >> 0x13) & 1;

  if (DAT_0058c5d8 != 0) {

    bVar6 = (uVar4 >> 0xb & 1) != 0;

    if (bVar6) {

      DAT_00632abc = DAT_00632abc - _DAT_00584588 * DAT_006328e0;

    }

    bVar7 = (uVar4 >> 0xd & 1) != 0;

    if (bVar7) {

      DAT_00632abc = _DAT_00584588 * DAT_006328e0 + DAT_00632abc;

    }

    bVar8 = (DAT_005dd0f8 & 0x10000) != 0;

    if (bVar8) {

      DAT_00632ac0 = DAT_00632ac0 - _DAT_00584588 * DAT_006328e0;

    }

    if ((uVar4 & 0x100) == 0) {

      if (!bVar8 && (!bVar7 && !bVar6)) {

        _DAT_00584588 = ((float)_DAT_005ddb48 + (float)_DAT_005ddb48) * 0.1;

        goto LAB_0041fe47;

      }

    }

    else {

      DAT_00632ac0 = _DAT_00584588 * DAT_006328e0 + DAT_00632ac0;

    }

    fVar1 = (float)_DAT_005ddb48 + (float)_DAT_005ddb48;

    if (_DAT_00584588 < fVar1) {

      _DAT_00584588 = fVar1 * 0.05 + _DAT_00584588;

    }

  }

LAB_0041fe47:

  if (DAT_00632abc < 0.0) {

    DAT_00632abc = 0.0;

  }

  if ((float)_DAT_005ddb44 < DAT_00632abc) {

    DAT_00632abc = (float)_DAT_005ddb44;

  }

  if (DAT_00632ac0 < 0.0) {

    DAT_00632ac0 = 0.0;

  }

  if (DAT_00632ac0 <= (float)_DAT_005ddb48) {

    return;

  }

  DAT_00632ac0 = (float)_DAT_005ddb48;

  return;

}

/* ===== FUN_0041fed0 @ 0x0041FED0 ===== */
undefined4 FUN_0041fed0(int param_1,undefined4 param_2)



{

  uint uVar1;

  uint uVar2;

  uint uVar3;

  uint uVar4;

  uint uVar5;

  

  if (param_1 < 0xf0) {

    switch(param_2) {

    case 0:

      if (-1 < (char)(&DAT_005dd159)[param_1]) {

        return 1;

      }

      return 0;

    case 1:

      if ((char)(&DAT_005dd159)[param_1] < '\0') {

        return 1;

      }

      return 0;

    case 2:

      goto switchD_0041fee6_caseD_2;

    case 3:

      if (((&DAT_005dd159)[param_1] & 0x80) == 0) {

        return 0;

      }

      if (((&DAT_005dd18d)[param_1] & 0x80) == 0) {

        return 1;

      }

      return 0;

    default:

      return 0;

    }

  }

  if (0xfe < param_1) {

    return 0;

  }

  uVar1 = param_1 - 0xf0U & 0x80000003;

  if ((int)uVar1 < 0) {

    uVar1 = (uVar1 - 1 | 0xfffffffc) + 1;

  }

  if (uVar1 == 0) {

    uVar1 = 0;

    uVar2 = 0x1194;

    uVar3 = 0x7b0c;

    uVar4 = 37000;

  }

  else if (uVar1 == 1) {

    uVar1 = 0x1194;

    uVar2 = 0x34bc;

    uVar3 = 0x1194;

    uVar4 = 0x34bc;

  }

  else if (uVar1 == 2) {

    uVar1 = 0x34bc;

    uVar2 = 0x57e4;

    uVar3 = 0x34bc;

    uVar4 = 0x57e4;

  }

  else {

    uVar1 = 0x57e4;

    uVar2 = 0x7b0c;

    uVar3 = 0x57e4;

    uVar4 = 0x7b0c;

  }

  switch(param_2) {

  case 0:

    if (uVar1 <= DAT_005dd1c4) {

      return 0;

    }

    if (DAT_005dd1c4 <= uVar2) {

      return 0;

    }

    if (uVar3 <= DAT_005dd1c4) {

      return 0;

    }

    if (DAT_005dd1c4 <= uVar4) {

      return 0;

    }

    return 1;

  case 2:

    if (uVar1 <= DAT_005dd1c4) {

      return 0;

    }

    if (DAT_005dd1c4 <= uVar2) {

      return 0;

    }

    if (uVar3 <= DAT_005dd1c4) {

      return 0;

    }

    uVar5 = DAT_005dd1f8;

    if (DAT_005dd1c4 <= uVar4) {

      return 0;

    }

    break;

  case 3:

    if (uVar1 <= DAT_005dd1f8) {

      return 0;

    }

    if (DAT_005dd1f8 <= uVar2) {

      return 0;

    }

    if (uVar3 <= DAT_005dd1f8) {

      return 0;

    }

    if (DAT_005dd1f8 <= uVar4) {

      return 0;

    }

  case 1:

    uVar5 = DAT_005dd1c4;

    break;

  default:

    goto switchD_0041fee6_default;

  }

  if (((uVar1 <= uVar5) && (uVar5 <= uVar2)) || ((uVar3 <= uVar5 && (uVar5 <= uVar4)))) {

    return 1;

  }

switchD_0041fee6_default:

  return 0;

switchD_0041fee6_caseD_2:

  if (((&DAT_005dd159)[param_1] & 0x80) != 0) {

    return 0;

  }

  if (((&DAT_005dd18d)[param_1] & 0x80) == 0) {

    return 0;

  }

  return 1;

}

