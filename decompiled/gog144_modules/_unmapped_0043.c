/* Giants 1.449 — module _unmapped_0043
 * 74 functions (62 named) — decompiled, names from PS2 symbols
 * Original source: C:\Giants\source\_unmapped_0043.c(pp) (assert-string evidence)
 */

/* ===== dlog_alpha_flags_copy @ 0x00430480 ===== */
void dlog_alpha_flags_copy(int param_1,undefined4 *param_2,int *param_3,undefined4 *param_4)



{

  float fVar1;

  float fVar2;

  undefined4 *puVar3;

  undefined1 uVar4;

  int iVar5;

  undefined4 *puVar6;

  undefined4 *puVar7;

  undefined4 *puVar8;

  int local_c;

  

  puVar3 = param_2;

  local_c = 0;

  DAT_0059b7c8 = 0;

  puVar6 = param_2;

  if (param_1 != 1) {

    param_2 = (undefined4 *)(param_1 + -1);

    do {

      if ((*(byte *)(puVar6 + 0xd) & 8) == 0) {

        puVar7 = puVar6;

        puVar8 = param_4;

        for (iVar5 = 0xe; iVar5 != 0; iVar5 = iVar5 + -1) {

          *puVar8 = *puVar7;

          puVar7 = puVar7 + 1;

          puVar8 = puVar8 + 1;

        }

        param_4 = param_4 + 0xe;

        local_c = local_c + 1;

        DAT_0059b7c8 = DAT_0059b7c8 | *(byte *)(puVar6 + 0xd);

      }

      if (((*(byte *)(puVar6 + 0x1b) ^ *(byte *)(puVar6 + 0xd)) & 8) != 0) {

        fVar2 = ((float)puVar6[5] - (float)puVar6[3]) /

                (((float)puVar6[0x11] - (float)puVar6[3]) - ((float)puVar6[0x13] - (float)puVar6[5])

                );

        param_4[3] = ((float)puVar6[0x11] - (float)puVar6[3]) * fVar2 + (float)puVar6[3];

        param_4[4] = ((float)puVar6[0x12] - (float)puVar6[4]) * fVar2 + (float)puVar6[4];

        fVar1 = (float)param_4[3];

        param_4[5] = fVar1;

        param_4[0xb] = ((float)puVar6[0x19] - (float)puVar6[0xb]) * fVar2 + (float)puVar6[0xb];

        param_4[0xc] = ((float)puVar6[0x1a] - (float)puVar6[0xc]) * fVar2 + (float)puVar6[0xc];

        uVar4 = __ftol();

        *(undefined1 *)(param_4 + 10) = uVar4;

        uVar4 = __ftol();

        *(undefined1 *)((int)param_4 + 0x29) = uVar4;

        uVar4 = __ftol();

        *(undefined1 *)((int)param_4 + 0x2a) = uVar4;

        uVar4 = __ftol();

        *(undefined1 *)((int)param_4 + 0x2b) = uVar4;

        if ((float)param_4[4] <= fVar1) {

          if (-fVar1 <= (float)param_4[4]) {

            *(undefined1 *)(param_4 + 0xd) = 0;

            FUN_00516cf0(param_4);

          }

          else {

            *(undefined1 *)(param_4 + 0xd) = 0x10;

            DAT_0059b7c8 = DAT_0059b7c8 | 0x10;

          }

        }

        else {

          *(undefined1 *)(param_4 + 0xd) = 0x20;

          DAT_0059b7c8 = DAT_0059b7c8 | 0x20;

        }

        param_4 = param_4 + 0xe;

        local_c = local_c + 1;

      }

      puVar6 = puVar6 + 0xe;

      param_2 = (undefined4 *)((int)param_2 + -1);

    } while (param_2 != (undefined4 *)0x0);

  }

  if ((*(byte *)(puVar6 + 0xd) & 8) == 0) {

    puVar7 = puVar6;

    puVar8 = param_4;

    for (iVar5 = 0xe; iVar5 != 0; iVar5 = iVar5 + -1) {

      *puVar8 = *puVar7;

      puVar7 = puVar7 + 1;

      puVar8 = puVar8 + 1;

    }

    param_4 = param_4 + 0xe;

    local_c = local_c + 1;

    DAT_0059b7c8 = DAT_0059b7c8 | *(byte *)(puVar6 + 0xd);

  }

  if (((*(byte *)(puVar3 + 0xd) ^ *(byte *)(puVar6 + 0xd)) & 8) == 0) {

    *param_3 = local_c;

    return;

  }

  fVar2 = ((float)puVar6[5] - (float)puVar6[3]) /

          (((float)puVar3[3] - (float)puVar6[3]) - ((float)puVar3[5] - (float)puVar6[5]));

  param_4[3] = ((float)puVar3[3] - (float)puVar6[3]) * fVar2 + (float)puVar6[3];

  param_4[4] = ((float)puVar3[4] - (float)puVar6[4]) * fVar2 + (float)puVar6[4];

  fVar1 = (float)param_4[3];

  param_4[5] = fVar1;

  param_4[0xb] = ((float)puVar3[0xb] - (float)puVar6[0xb]) * fVar2 + (float)puVar6[0xb];

  param_4[0xc] = ((float)puVar3[0xc] - (float)puVar6[0xc]) * fVar2 + (float)puVar6[0xc];

  uVar4 = __ftol();

  *(undefined1 *)(param_4 + 10) = uVar4;

  uVar4 = __ftol();

  *(undefined1 *)((int)param_4 + 0x29) = uVar4;

  uVar4 = __ftol();

  *(undefined1 *)((int)param_4 + 0x2a) = uVar4;

  uVar4 = __ftol();

  *(undefined1 *)((int)param_4 + 0x2b) = uVar4;

  if (fVar1 < (float)param_4[4]) {

    *(undefined1 *)(param_4 + 0xd) = 0x20;

    DAT_0059b7c8 = DAT_0059b7c8 | 0x20;

    *param_3 = local_c + 1;

    return;

  }

  if ((float)param_4[4] < -fVar1) {

    *(undefined1 *)(param_4 + 0xd) = 0x10;

    DAT_0059b7c8 = DAT_0059b7c8 | 0x10;

    *param_3 = local_c + 1;

    return;

  }

  *(undefined1 *)(param_4 + 0xd) = 0;

  FUN_00516cf0(param_4);

  *param_3 = local_c + 1;

  return;

}

/* ===== dlog_alpha_range_copy @ 0x00430820 ===== */
void dlog_alpha_range_copy(int param_1,undefined4 *param_2,int *param_3,undefined4 *param_4)



{

  float fVar1;

  float fVar2;

  undefined4 *puVar3;

  undefined1 uVar4;

  int iVar5;

  undefined4 *puVar6;

  undefined4 *puVar7;

  undefined4 *puVar8;

  int local_8;

  

  puVar3 = param_2;

  local_8 = 0;

  DAT_0059b7c8 = 0;

  puVar6 = param_2;

  if (param_1 != 1) {

    param_2 = (undefined4 *)(param_1 + -1);

    do {

      if ((*(byte *)(puVar6 + 0xd) & 0x10) == 0) {

        puVar7 = puVar6;

        puVar8 = param_4;

        for (iVar5 = 0xe; iVar5 != 0; iVar5 = iVar5 + -1) {

          *puVar8 = *puVar7;

          puVar7 = puVar7 + 1;

          puVar8 = puVar8 + 1;

        }

        param_4 = param_4 + 0xe;

        local_8 = local_8 + 1;

        DAT_0059b7c8 = DAT_0059b7c8 | *(byte *)(puVar6 + 0xd);

      }

      if (((*(byte *)(puVar6 + 0x1b) ^ *(byte *)(puVar6 + 0xd)) & 0x10) != 0) {

        fVar1 = (-(float)puVar6[5] - (float)puVar6[4]) /

                (((float)puVar6[0x12] - (float)puVar6[4]) + ((float)puVar6[0x13] - (float)puVar6[5])

                );

        param_4[3] = ((float)puVar6[0x11] - (float)puVar6[3]) * fVar1 + (float)puVar6[3];

        fVar2 = ((float)puVar6[0x12] - (float)puVar6[4]) * fVar1 + (float)puVar6[4];

        param_4[4] = fVar2;

        param_4[5] = -fVar2;

        param_4[0xb] = ((float)puVar6[0x19] - (float)puVar6[0xb]) * fVar1 + (float)puVar6[0xb];

        param_4[0xc] = ((float)puVar6[0x1a] - (float)puVar6[0xc]) * fVar1 + (float)puVar6[0xc];

        uVar4 = __ftol();

        *(undefined1 *)(param_4 + 10) = uVar4;

        uVar4 = __ftol();

        *(undefined1 *)((int)param_4 + 0x29) = uVar4;

        uVar4 = __ftol();

        *(undefined1 *)((int)param_4 + 0x2a) = uVar4;

        uVar4 = __ftol();

        *(undefined1 *)((int)param_4 + 0x2b) = uVar4;

        *(undefined1 *)(param_4 + 0xd) = 0;

        FUN_00516cf0(param_4);

        param_4 = param_4 + 0xe;

        local_8 = local_8 + 1;

      }

      puVar6 = puVar6 + 0xe;

      param_2 = (undefined4 *)((int)param_2 + -1);

    } while (param_2 != (undefined4 *)0x0);

  }

  if ((*(byte *)(puVar6 + 0xd) & 0x10) == 0) {

    puVar7 = puVar6;

    puVar8 = param_4;

    for (iVar5 = 0xe; iVar5 != 0; iVar5 = iVar5 + -1) {

      *puVar8 = *puVar7;

      puVar7 = puVar7 + 1;

      puVar8 = puVar8 + 1;

    }

    param_4 = param_4 + 0xe;

    local_8 = local_8 + 1;

    DAT_0059b7c8 = DAT_0059b7c8 | *(byte *)(puVar6 + 0xd);

  }

  if (((*(byte *)(puVar3 + 0xd) ^ *(byte *)(puVar6 + 0xd)) & 0x10) != 0) {

    fVar1 = (-(float)puVar6[5] - (float)puVar6[4]) /

            (((float)puVar3[4] - (float)puVar6[4]) + ((float)puVar3[5] - (float)puVar6[5]));

    param_4[3] = ((float)puVar3[3] - (float)puVar6[3]) * fVar1 + (float)puVar6[3];

    fVar2 = ((float)puVar3[4] - (float)puVar6[4]) * fVar1 + (float)puVar6[4];

    param_4[4] = fVar2;

    param_4[5] = -fVar2;

    param_4[0xb] = ((float)puVar3[0xb] - (float)puVar6[0xb]) * fVar1 + (float)puVar6[0xb];

    param_4[0xc] = ((float)puVar3[0xc] - (float)puVar6[0xc]) * fVar1 + (float)puVar6[0xc];

    uVar4 = __ftol();

    *(undefined1 *)(param_4 + 10) = uVar4;

    uVar4 = __ftol();

    *(undefined1 *)((int)param_4 + 0x29) = uVar4;

    uVar4 = __ftol();

    *(undefined1 *)((int)param_4 + 0x2a) = uVar4;

    uVar4 = __ftol();

    *(undefined1 *)((int)param_4 + 0x2b) = uVar4;

    *(undefined1 *)(param_4 + 0xd) = 0;

    FUN_00516cf0(param_4);

    *param_3 = local_8 + 1;

    return;

  }

  *param_3 = local_8;

  return;

}

/* ===== dlog_alpha_flags20_copy @ 0x00430B20 ===== */
void dlog_alpha_flags20_copy(int param_1,undefined4 *param_2,int *param_3,undefined4 *param_4)



{

  float fVar1;

  float fVar2;

  undefined4 *puVar3;

  undefined1 uVar4;

  int iVar5;

  undefined4 *puVar6;

  undefined4 *puVar7;

  undefined4 *puVar8;

  int local_8;

  

  puVar3 = param_2;

  local_8 = 0;

  DAT_0059b7c8 = 0;

  puVar6 = param_2;

  if (param_1 != 1) {

    param_2 = (undefined4 *)(param_1 + -1);

    do {

      if ((*(byte *)(puVar6 + 0xd) & 0x20) == 0) {

        puVar7 = puVar6;

        puVar8 = param_4;

        for (iVar5 = 0xe; iVar5 != 0; iVar5 = iVar5 + -1) {

          *puVar8 = *puVar7;

          puVar7 = puVar7 + 1;

          puVar8 = puVar8 + 1;

        }

        param_4 = param_4 + 0xe;

        local_8 = local_8 + 1;

        DAT_0059b7c8 = DAT_0059b7c8 | *(byte *)(puVar6 + 0xd);

      }

      if (((*(byte *)(puVar6 + 0x1b) ^ *(byte *)(puVar6 + 0xd)) & 0x20) != 0) {

        fVar1 = ((float)puVar6[5] - (float)puVar6[4]) /

                (((float)puVar6[0x12] - (float)puVar6[4]) - ((float)puVar6[0x13] - (float)puVar6[5])

                );

        param_4[3] = ((float)puVar6[0x11] - (float)puVar6[3]) * fVar1 + (float)puVar6[3];

        fVar2 = ((float)puVar6[0x12] - (float)puVar6[4]) * fVar1 + (float)puVar6[4];

        param_4[4] = fVar2;

        param_4[5] = fVar2;

        param_4[0xb] = ((float)puVar6[0x19] - (float)puVar6[0xb]) * fVar1 + (float)puVar6[0xb];

        param_4[0xc] = ((float)puVar6[0x1a] - (float)puVar6[0xc]) * fVar1 + (float)puVar6[0xc];

        uVar4 = __ftol();

        *(undefined1 *)(param_4 + 10) = uVar4;

        uVar4 = __ftol();

        *(undefined1 *)((int)param_4 + 0x29) = uVar4;

        uVar4 = __ftol();

        *(undefined1 *)((int)param_4 + 0x2a) = uVar4;

        uVar4 = __ftol();

        *(undefined1 *)((int)param_4 + 0x2b) = uVar4;

        *(undefined1 *)(param_4 + 0xd) = 0;

        FUN_00516cf0(param_4);

        param_4 = param_4 + 0xe;

        local_8 = local_8 + 1;

      }

      puVar6 = puVar6 + 0xe;

      param_2 = (undefined4 *)((int)param_2 + -1);

    } while (param_2 != (undefined4 *)0x0);

  }

  if ((*(byte *)(puVar6 + 0xd) & 0x20) == 0) {

    puVar7 = puVar6;

    puVar8 = param_4;

    for (iVar5 = 0xe; iVar5 != 0; iVar5 = iVar5 + -1) {

      *puVar8 = *puVar7;

      puVar7 = puVar7 + 1;

      puVar8 = puVar8 + 1;

    }

    param_4 = param_4 + 0xe;

    local_8 = local_8 + 1;

    DAT_0059b7c8 = DAT_0059b7c8 | *(byte *)(puVar6 + 0xd);

  }

  if (((*(byte *)(puVar3 + 0xd) ^ *(byte *)(puVar6 + 0xd)) & 0x20) != 0) {

    fVar1 = ((float)puVar6[5] - (float)puVar6[4]) /

            (((float)puVar3[4] - (float)puVar6[4]) - ((float)puVar3[5] - (float)puVar6[5]));

    param_4[3] = ((float)puVar3[3] - (float)puVar6[3]) * fVar1 + (float)puVar6[3];

    fVar2 = ((float)puVar3[4] - (float)puVar6[4]) * fVar1 + (float)puVar6[4];

    param_4[4] = fVar2;

    param_4[5] = fVar2;

    param_4[0xb] = ((float)puVar3[0xb] - (float)puVar6[0xb]) * fVar1 + (float)puVar6[0xb];

    param_4[0xc] = ((float)puVar3[0xc] - (float)puVar6[0xc]) * fVar1 + (float)puVar6[0xc];

    uVar4 = __ftol();

    *(undefined1 *)(param_4 + 10) = uVar4;

    uVar4 = __ftol();

    *(undefined1 *)((int)param_4 + 0x29) = uVar4;

    uVar4 = __ftol();

    *(undefined1 *)((int)param_4 + 0x2a) = uVar4;

    uVar4 = __ftol();

    *(undefined1 *)((int)param_4 + 0x2b) = uVar4;

    *(undefined1 *)(param_4 + 0xd) = 0;

    FUN_00516cf0(param_4);

    *param_3 = local_8 + 1;

    return;

  }

  *param_3 = local_8;

  return;

}

/* ===== collgrid_00430e10 @ 0x00430E10 ===== */
undefined4

collgrid_00430e10(undefined4 *param_1,ushort *param_2,uint *param_3,uint *param_4,uint *param_5)



{

  ushort uVar1;

  ushort *puVar2;

  ushort uVar3;

  uint uVar4;

  uint uVar5;

  

  uVar4 = (uint)*param_2;

  puVar2 = (ushort *)*param_1;

  if (*param_2 == 0xffff) {

    uVar4 = 0;

  }

  uVar1 = *puVar2;

  uVar5 = (uint)uVar1;

  if (uVar1 == 0) {

    return 0;

  }

  if ((short)uVar1 < 0) {

    uVar5 = uVar5 & 0x7fff;

    *param_3 = (uint)puVar2[uVar4 + 1];

    if ((uVar4 & 1) == 0) {

LAB_00430e93:

      *param_4 = (uint)puVar2[uVar4 + 2];

      uVar1 = puVar2[uVar4 + 3];

    }

    else {

      *param_4 = (uint)puVar2[uVar4 + 3];

      uVar1 = puVar2[uVar4 + 2];

    }

    *param_5 = (uint)uVar1;

    uVar3 = (ushort)(uVar4 + 1);

    if ((uVar4 + 1 & 0xffff) != uVar5 - 2) goto LAB_00430f12;

  }

  else {

    if ((uVar1 & 0x4000) != 0) {

      uVar5 = uVar5 & 0xbfff;

      *param_3 = (uint)puVar2[1];

      goto LAB_00430e93;

    }

    *param_3 = (uint)puVar2[uVar4 * 3 + 1];

    *param_4 = (uint)puVar2[uVar4 * 3 + 2];

    uVar3 = (short)uVar4 + 1;

    *param_5 = (uint)puVar2[uVar4 * 3 + 3];

    if (uVar3 != uVar1) goto LAB_00430f12;

    uVar5 = uVar5 * 3;

  }

  puVar2 = puVar2 + uVar5 + 1;

  uVar3 = 0;

LAB_00430f12:

  *param_1 = puVar2;

  *param_2 = uVar3;

  return 1;

}

/* ===== dlog_entry_alloc @ 0x00430FD0 ===== */
void dlog_entry_alloc(void)



{

  undefined4 *puVar1;

  undefined4 *puVar2;

  undefined4 *puVar3;

  int iVar4;

  undefined4 uVar5;

  undefined4 uVar6;

  undefined4 uVar7;

  undefined4 uStack_58;

  int iStack_54;

  undefined4 uStack_50;

  undefined4 uStack_4c;

  undefined4 uStack_48;

  undefined4 uStack_44;

  undefined4 local_40;

  undefined4 local_3c;

  undefined4 local_38;

  undefined4 local_34;

  undefined4 local_30;

  undefined4 local_2c;

  undefined4 local_28;

  undefined4 local_24;

  undefined4 local_20;

  undefined4 local_1c;

  undefined4 local_18;

  undefined4 local_14;

  undefined4 local_10;

  undefined4 local_c;

  undefined4 local_8;

  undefined4 local_4;

  

  local_40 = 0x3f800000;

  local_3c = 0;

  local_38 = 0;

  local_34 = 0;

  local_30 = 0;

  local_2c = 0x3f800000;

  local_28 = 0;

  local_24 = 0;

  local_20 = 0;

  local_1c = 0;

  local_18 = 0x3f800000;

  local_14 = 0;

  local_10 = 0;

  local_c = 0;

  local_8 = 0;

  local_4 = 0x3f800000;

  (**(code **)(DAT_00656420 + 0x10))(DAT_00656420);

  (**(code **)(DAT_00656420 + 0x18))(DAT_00656420,&local_40);

  (**(code **)(DAT_00656430 + 0xc))(DAT_00656430,1);

  (**(code **)(DAT_00656430 + 0x10))(DAT_00656430,1);

  (**(code **)(DAT_00656420 + 0xac))

            (DAT_00656420,*(undefined4 *)(DAT_006330e4 + 0x140),

             *(undefined4 *)(DAT_006330e4 + 0x144),DAT_006330e4 + 0x148);

  if (DAT_00632ba8 == 0) {

    if (0 < DAT_00633244) {

      uStack_4c = 0;

      if ((*(byte *)(DAT_006330e4 + 0x4ebf) & 0x40) == 0) {

        uStack_50 = 0x34;

        iStack_54 = 0;

      }

      else {

        iStack_54 = DAT_006330e4 + 0x4ea0;

        uStack_50 = 0xa074;

      }

      uStack_58 = *(undefined4 *)(DAT_006330e4 + 0x6c);

      uStack_44 = 0;

      uStack_48 = 0;

      (**(code **)(DAT_00656430 + 0x14))(DAT_00656430,&uStack_58);

      goto LAB_0043114d;

    }

    uVar6 = *(undefined4 *)(DAT_006330e4 + 0x6c);

    uVar7 = 0;

    uVar5 = 0x14;

  }

  else {

    uVar6 = *(undefined4 *)(DAT_006330e4 + 0x6c);

    uVar7 = 0x404040;

    uVar5 = 0x23004;

  }

  (**(code **)(DAT_00656430 + 8))(DAT_00656430,uVar5,uVar6,uVar7);

LAB_0043114d:

  (**(code **)(DAT_00656420 + 0x50))(DAT_00656420,2,1);

  puVar1 = (undefined4 *)

           (**(code **)(DAT_0065644c + 0x10))(DAT_0065644c,*(undefined4 *)(DAT_00632d34 + 4));

  puVar3 = *(undefined4 **)(DAT_00632d34 + 0x10);

  puVar2 = *(undefined4 **)(DAT_00632d34 + 0xc);

  iVar4 = *(int *)(DAT_00632d34 + 4);

  if (0 < iVar4) {

    do {

      *puVar1 = *puVar2;

      puVar1[1] = puVar2[1];

      puVar1[2] = puVar2[2];

      puVar1[4] = *puVar3;

      puVar1[5] = puVar3[1];

      puVar1[3] = 0xffffff;

      puVar2 = puVar2 + 3;

      puVar3 = puVar3 + 2;

      puVar1 = puVar1 + 6;

      iVar4 = iVar4 + -1;

    } while (iVar4 != 0);

  }

  (**(code **)(DAT_0065644c + 0x18))(DAT_0065644c,0);

  (**(code **)(DAT_0065644c + 0x20))

            (DAT_0065644c,*(int *)(DAT_00632d34 + 8) * 3,*(undefined4 *)(DAT_00632d34 + 0x18));

  (**(code **)(DAT_00656420 + 0x50))(DAT_00656420,0,1);

  (**(code **)(DAT_00656420 + 0x10))(DAT_00656420);

  (**(code **)(DAT_00656420 + 0xac))

            (DAT_00656420,*(undefined4 *)(DAT_006330e4 + 0x128),*(undefined4 *)(DAT_006330e4 + 300),

             DAT_006330e4 + 0x130);

  return;

}

/* ===== FUN_004319c0 @ 0x004319C0 ===== */
void FUN_004319c0(undefined4 *param_1)



{

  undefined4 uVar1;

  undefined4 *puVar2;

  

  puVar2 = (undefined4 *)XFGetCameraAxis(2);

  uVar1 = puVar2[1];

  *param_1 = *puVar2;

  param_1[1] = uVar1;

  return;

}

/* ===== get_free_world_ripple__Fv_2 @ 0x00431A00 ===== */
/* PS2 candidate: get_free_world_ripple__Fv_2 (conf 0.568) */



void get_free_world_ripple__Fv_2

               (undefined4 *param_1,float param_2,float param_3,float param_4,float param_5)



{

  float fVar1;

  int iVar2;

  float *pfVar3;

  int iVar4;

  undefined4 uVar5;

  

  if (DAT_00632b90 < 8) {

    iVar4 = DAT_00632b90;

    DAT_00632b90 = DAT_00632b90 + 1;

  }

  else {

    iVar2 = 1;

    iVar4 = 0;

    if (1 < DAT_00632b90) {

      pfVar3 = (float *)&DAT_0059cad8;

      fVar1 = DAT_0059cab8;

      do {

        if (*pfVar3 < fVar1) {

          fVar1 = *pfVar3;

          iVar4 = iVar2;

        }

        iVar2 = iVar2 + 1;

        pfVar3 = pfVar3 + 8;

      } while (iVar2 < DAT_00632b90);

    }

  }

  (&DAT_0059caa0)[iVar4 * 8] = 0;

  (&DAT_0059caa4)[iVar4 * 8] = *param_1;

  (&DAT_0059caa8)[iVar4 * 8] = param_1[1];

  *(undefined4 *)(iVar4 * 0x20 + 0x59caac) = param_1[2];

  (&DAT_0059cab0)[iVar4 * 8] = param_5;

  (&DAT_0059cab4)[iVar4 * 8] = param_2;

  (&DAT_0059cab8)[iVar4 * 8] = param_3;

  (&DAT_0059cabc)[iVar4 * 8] = (param_2 * param_3) / (param_4 - param_5);

  iVar2 = crt_rand_scaled(100);

  if (iVar2 < 0x32) {

    uVar5 = 0x667;

  }

  else {

    uVar5 = 0x668;

  }

  sound_play_3dpos(uVar5,param_1);

  comm_0052b780_user_8(&DAT_0059caa0 + iVar4 * 8,0x20);

  return;

}

/* ===== get_free_world_ripple__Fv @ 0x00431AE0 ===== */
/* PS2 candidate: get_free_world_ripple__Fv (conf 0.606) */



void get_free_world_ripple__Fv(undefined4 *param_1)



{

  float fVar1;

  int iVar2;

  float *pfVar3;

  undefined4 *puVar4;

  int iVar5;

  undefined4 *puVar6;

  

  if (DAT_00632b90 < 8) {

    iVar5 = DAT_00632b90;

    DAT_00632b90 = DAT_00632b90 + 1;

  }

  else {

    iVar2 = 1;

    iVar5 = 0;

    if (1 < DAT_00632b90) {

      pfVar3 = (float *)&DAT_0059cad8;

      fVar1 = DAT_0059cab8;

      do {

        if (*pfVar3 < fVar1) {

          fVar1 = *pfVar3;

          iVar5 = iVar2;

        }

        iVar2 = iVar2 + 1;

        pfVar3 = pfVar3 + 8;

      } while (iVar2 < DAT_00632b90);

    }

  }

  puVar4 = param_1;

  puVar6 = &DAT_0059caa0 + iVar5 * 8;

  for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {

    *puVar6 = *puVar4;

    puVar4 = puVar4 + 1;

    puVar6 = puVar6 + 1;

  }

  iVar5 = crt_rand_scaled(100);

  if (0x31 < iVar5) {

    sound_play_3dpos(0x668,param_1 + 1);

    return;

  }

  sound_play_3dpos(0x667,param_1 + 1);

  return;

}

/* ===== kabutoai_select_target__FP6OBJECT @ 0x00431B80 ===== */
/* PS2 candidate: kabutoai_select_target__FP6OBJECT (conf 0.51) */



void kabutoai_select_target__FP6OBJECT(void)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  undefined4 *puVar6;

  int iVar7;

  float *pfVar8;

  int *piVar9;

  int *piVar10;

  float *pfVar11;

  int iVar12;

  int *piVar13;

  float10 fVar14;

  undefined4 uVar15;

  undefined4 *local_20;

  float *local_1c;

  float *local_18;

  int local_14;

  float *local_10;

  undefined4 local_c;

  undefined4 local_8;

  undefined4 local_4;

  

  if (DAT_00632ae2 != '\0') {

    project_cursor_to_ground(&local_c,0x459c4000,&local_10);

    fVar1 = *(float *)(DAT_00632ed8 + 0x4ac);

    fVar2 = *(float *)(DAT_00632ed8 + 0x414);

    fVar3 = *(float *)(DAT_00632ed8 + 0x410);

    fVar4 = *(float *)(DAT_00632ed8 + 0x40c);

    if (DAT_00632b90 < 8) {

      iVar12 = DAT_00632b90;

      DAT_00632b90 = DAT_00632b90 + 1;

    }

    else {

      iVar7 = 1;

      iVar12 = 0;

      if (1 < DAT_00632b90) {

        pfVar8 = (float *)&DAT_0059cad8;

        fVar5 = DAT_0059cab8;

        do {

          if (*pfVar8 < fVar5) {

            fVar5 = *pfVar8;

            iVar12 = iVar7;

          }

          iVar7 = iVar7 + 1;

          pfVar8 = pfVar8 + 8;

        } while (iVar7 < DAT_00632b90);

      }

    }

    (&DAT_0059cab0)[iVar12 * 8] = fVar1;

    (&DAT_0059cab4)[iVar12 * 8] = fVar4;

    (&DAT_0059caa4)[iVar12 * 8] = local_c;

    (&DAT_0059cab8)[iVar12 * 8] = fVar3;

    (&DAT_0059caa8)[iVar12 * 8] = local_8;

    (&DAT_0059caa0)[iVar12 * 8] = 0;

    *(undefined4 *)(iVar12 * 0x20 + 0x59caac) = local_4;

    (&DAT_0059cabc)[iVar12 * 8] = (fVar4 * fVar3) / (fVar2 - fVar1);

    iVar7 = crt_rand_scaled(100);

    if (iVar7 < 0x32) {

      uVar15 = 0x667;

    }

    else {

      uVar15 = 0x668;

    }

    sound_play_3dpos(uVar15,&local_c);

    comm_0052b780_user_8(&DAT_0059caa0 + iVar12 * 8,0x20);

  }

  puVar6 = DAT_00632d68;

  if (DAT_00632b90 != 0) {

    for (; puVar6 != (undefined4 *)0x0; puVar6 = (undefined4 *)*puVar6) {

      *(uint *)(puVar6[3] + 0xd8) = *(uint *)(puVar6[3] + 0xd8) | 0x10000000;

    }

    local_14 = 0;

    if (0 < DAT_00632b90) {

      piVar9 = &DAT_0059caa0;

      local_10 = &DAT_0059cab8;

      local_18 = (float *)&DAT_0059cabc;

      pfVar8 = (float *)&DAT_0059cab0;

      local_1c = (float *)&DAT_0059cab4;

      local_20 = &DAT_0059caa4;

      do {

        pfVar11 = local_10;

        fVar14 = (float10)FUN_0050a610(DAT_00632a88 + 0xa0,local_20);

        if ((fVar14 < (float10)90000.0) && (iVar12 = ObjIsMecc(DAT_00632a88), iVar12 != 0)) {

          ANM_DumpCluster(DAT_00632a88,0x1c);

        }

        fVar1 = DAT_006328e0 * *local_1c;

        *piVar9 = *piVar9 + 1;

        *pfVar8 = fVar1 + *pfVar8;

        fVar1 = *pfVar11 - DAT_006328e0 * *local_18;

        *pfVar11 = fVar1;

        iVar12 = DAT_00632b90;

        if ((fVar1 < 0.0 != (fVar1 == 0.0)) &&

           (iVar12 = DAT_00632b90 + -1, DAT_00632b90 = iVar12, 0 < iVar12)) {

          piVar10 = &DAT_0059caa0 + iVar12 * 8;

          piVar13 = piVar9;

          for (iVar7 = 8; iVar7 != 0; iVar7 = iVar7 + -1) {

            *piVar13 = *piVar10;

            piVar10 = piVar10 + 1;

            piVar13 = piVar13 + 1;

          }

          local_14 = local_14 + -1;

          local_20 = local_20 + -8;

          local_1c = local_1c + -8;

          local_18 = local_18 + -8;

          pfVar11 = local_10 + -8;

          pfVar8 = pfVar8 + -8;

          piVar9 = piVar9 + -8;

        }

        local_20 = local_20 + 8;

        local_1c = local_1c + 8;

        local_14 = local_14 + 1;

        local_18 = local_18 + 8;

        local_10 = pfVar11 + 8;

        pfVar8 = pfVar8 + 8;

        piVar9 = piVar9 + 8;

      } while (local_14 < iVar12);

    }

  }

  return;

}

/* ===== world_ripple_xform @ 0x00431E30 ===== */
/* PS2 candidate: world_ripple_xform (conf 0.568) */



float10 world_ripple_xform(float *param_1)



{

  float fVar1;

  float *pfVar2;

  int iVar3;

  float10 fVar4;

  float10 fVar5;

  

  if (DAT_00632b90 != 0) {

    fVar4 = (float10)0.0;

    if (0 < DAT_00632b90) {

      pfVar2 = (float *)&DAT_0059caa4;

      iVar3 = DAT_00632b90;

      do {

        if (pfVar2[-1] != 0.0) {

          fVar1 = (*pfVar2 - *param_1) * (*pfVar2 - *param_1) +

                  (pfVar2[1] - param_1[1]) * (pfVar2[1] - param_1[1]);

          if (fVar1 == 0.0) {

            fVar5 = (float10)0.0;

          }

          else {

            fVar5 = (float10)(float)((&DAT_005f0a18)[(uint)fVar1 >> 8 & 0xffff] |

                                    ((int)fVar1 + 0xc0800000U >> 1) + 0x3f800000 & 0x7f800000);

          }

          fVar5 = ((float10)*(float *)(DAT_00632ed8 + 0x418) -

                  ABS(fVar5 - (float10)pfVar2[3]) * ABS(fVar5 - (float10)pfVar2[3]) *

                  ((float10)*(float *)(DAT_00632ed8 + 0x418) /

                  ((float10)*(float *)(DAT_00632ed8 + 0x41c) *

                  (float10)*(float *)(DAT_00632ed8 + 0x41c)))) * (float10)pfVar2[5];

          if ((float10)0.0 < fVar5) {

            fVar4 = fVar5 + fVar4;

          }

        }

        pfVar2 = pfVar2 + 8;

        iVar3 = iVar3 + -1;

      } while (iVar3 != 0);

    }

    if ((float10)*(float *)(DAT_00632ed8 + 0x418) < fVar4) {

      fVar4 = (float10)*(float *)(DAT_00632ed8 + 0x418);

    }

    return fVar4 + (float10)param_1[2];

  }

  return (float10)param_1[2];

}

/* ===== FUN_00432270 @ 0x00432270 ===== */
void FUN_00432270(int param_1)



{

  (**(code **)((&DAT_00656680)[param_1] + 0x14))

            ((&DAT_00656680)[param_1],((&DAT_00656c40)[param_1] * 2 + 2) - (&DAT_00656600)[param_1])

  ;

  (**(code **)((&DAT_00656680)[param_1] + 0x18))((&DAT_00656680)[param_1],0);

  if ((&DAT_00656480)[param_1] != 0) {

    (**(code **)((&DAT_00656680)[param_1] + 0x20))

              ((&DAT_00656680)[param_1],(&DAT_00656480)[param_1],(&DAT_00656520)[param_1]);

  }

  return;

}

/* ===== makewrld_big @ 0x00432400 ===== */
void makewrld_big(void)



{

  undefined4 uVar1;

  undefined4 *puVar2;

  float *pfVar3;

  int iVar4;

  undefined2 *puVar5;

  int iVar6;

  int iVar7;

  undefined4 *puVar8;

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

  undefined4 uStack_154;

  float afStack_150 [4];

  float afStack_140 [6];

  undefined4 uStack_128;

  undefined1 auStack_110 [68];

  undefined1 auStack_cc [68];

  undefined4 uStack_88;

  undefined4 auStack_84 [16];

  undefined1 auStack_44 [68];

  

  puVar5 = &DAT_00656480;

  iVar7 = 0;

  do {

    (**(code **)(*(int *)((int)&DAT_00656680 + iVar7) + 4))

              (*(int *)((int)&DAT_00656680 + iVar7),0,5);

    uVar1 = *(undefined4 *)((int)&DAT_006573c0 + iVar7);

    *puVar5 = 0;

    *(undefined4 *)((int)&DAT_00657340 + iVar7) = 0;

    *(undefined4 *)((int)&DAT_00656600 + iVar7) = uVar1;

    puVar5 = puVar5 + 1;

    iVar7 = iVar7 + 4;

  } while ((int)puVar5 < 0x656492);

  if (0 < DAT_00633244) {

    (**(code **)(DAT_00656420 + 0x50))(DAT_00656420,2,2);

  }

  iVar7 = 0x4ec0;

  fStack_17c = DAT_0059cba0;

  do {

    if ((DAT_006331ac == 0) &&

       (fStack_188 = *(float *)(iVar7 + 0xc + DAT_006330e4), fStack_188 != 0.0)) {

      fStack_184 = *(float *)(iVar7 + DAT_006330e4);

      fStack_174 = 0.0;

      fStack_178 = 0.0;

      if ((*(ushort *)(*(int *)(DAT_006330e4 + 0x503c) * 0x20 + 0x505e + DAT_006330e4) & 0x8000) !=

          0) {

        fStack_178 = (float)((*(int *)(DAT_006330e4 + 0x503c) + 0x282) * 0x20 + DAT_006330e4);

      }

      if (DAT_00633244 < 1) {

        fStack_180 = (float)(DAT_0059ca90 & 0xffff8fff | 0x68002);

      }

      else {

        fStack_180 = (float)(DAT_0059ca90 & 0xffff8fff | 0x68300);

        fStack_17c = (float)((uint)fStack_17c | *(uint *)(DAT_006330e4 + 0x50a0) & 0xffffff);

      }

      if ((*(int *)(DAT_006330e4 + 0x4f3c) != 0) && (DAT_006330b4 != 0)) {

        obj_5c_mount_check(DAT_006330b4,&fStack_170);

        fStack_164 = -fStack_170;

        fStack_160 = -fStack_16c;

        fStack_15c = -fStack_168;

        main_makewrld_00473600(&fStack_164,0);

        *(undefined4 *)(DAT_006330e4 + 0x4f3c) = 0;

      }

    }

    else {

      fStack_188 = *(float *)(iVar7 + DAT_006330e4);

      fStack_184 = 0.0;

      fStack_180 = (float)DAT_0059ca90;

    }

    (**(code **)(*(int *)(&DAT_006524f0 + iVar7) + 0x14))

              (*(int *)(&DAT_006524f0 + iVar7),&fStack_188);

    iVar7 = iVar7 + 4;

  } while (iVar7 < 0x4ecc);

  iVar7 = 0;

  iVar6 = 0;

  do {

    if (*(int *)((int)&DAT_006565c0 + iVar7) != 0) {

      puVar2 = (undefined4 *)(**(code **)(DAT_00656420 + 0x2c))(DAT_00656420);

      puVar8 = auStack_84;

      for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {

        *puVar8 = *puVar2;

        puVar2 = puVar2 + 1;

        puVar8 = puVar8 + 1;

      }

      uStack_88 = 0x21;

      FUN_0053d970(auStack_44,&uStack_88);

      (*(code *)PTR_crt_matrix_copy_init_00580c1c)(auStack_cc,auStack_44);

      GEO_MatIdentity(&uStack_154);

      iVar4 = *(int *)((int)&DAT_00556e44 + iVar7);

      uStack_128 = 0;

      afStack_140[1] = 0.0;

      afStack_150[0] = 0.0;

      afStack_150[*(int *)((int)&DAT_00556e20 + iVar7)] = *(float *)((int)&DAT_00657040 + iVar7);

      afStack_140[iVar4] = *(float *)((int)&DAT_00656d00 + iVar7);

      uStack_154 = 7;

      (*(code *)PTR_crt_matrix_mul_00580c18)(auStack_110,&uStack_154,auStack_cc);

      FUN_0053d970(&DAT_00656980 + iVar6,auStack_110);

      iVar4 = *(int *)((int)&DAT_00556e44 + iVar7);

      afStack_150[*(int *)((int)&DAT_00556e20 + iVar7)] = *(float *)((int)&DAT_00656c00 + iVar7);

      afStack_140[iVar4] = *(float *)((int)&DAT_00656c80 + iVar7);

      uStack_154 = 7;

      (*(code *)PTR_crt_matrix_mul_00580c18)(auStack_110,&uStack_154,auStack_cc);

      FUN_0053d970(&DAT_00657080 + iVar6,auStack_110);

      iVar4 = *(int *)((int)&DAT_00556e44 + iVar7);

      afStack_150[*(int *)((int)&DAT_00556e20 + iVar7)] = *(float *)((int)&DAT_006564a0 + iVar7);

      afStack_140[iVar4] = *(float *)((int)&DAT_006564e0 + iVar7);

      uStack_154 = 7;

      (*(code *)PTR_crt_matrix_mul_00580c18)(auStack_110,&uStack_154,auStack_cc);

      FUN_0053d970(&DAT_00656dc0 + iVar6,auStack_110);

      iVar4 = *(int *)((int)&DAT_00556e44 + iVar7);

      afStack_150[*(int *)((int)&DAT_00556e20 + iVar7)] = *(float *)((int)&DAT_00656d80 + iVar7);

      afStack_140[iVar4] = *(float *)((int)&DAT_00656640 + iVar7);

      uStack_154 = 7;

      (*(code *)PTR_crt_matrix_mul_00580c18)(auStack_110,&uStack_154,auStack_cc);

      FUN_0053d970(&DAT_00656700 + iVar6,auStack_110);

      iVar4 = *(int *)((int)&DAT_00556e20 + iVar7);

      afStack_140[*(int *)((int)&DAT_00556e44 + iVar7)] = 0.0;

      afStack_150[iVar4] = 0.0;

      afStack_150[0] = 1.0 / *(float *)(DAT_006330e4 + 0x7c);

      afStack_140[1] = 1.0 / *(float *)(DAT_006330e4 + 0x7c);

      uStack_154 = 7;

      (*(code *)PTR_crt_matrix_mul_00580c18)(auStack_110,&uStack_154,auStack_cc);

      FUN_0053d970(&DAT_00656560,auStack_110);

      afStack_140[1] = 0.0;

      afStack_150[0] = 0.0;

    }

    iVar6 = iVar6 + 0x44;

    iVar7 = iVar7 + 4;

  } while (iVar6 < 0x264);

  if (1 < DAT_00633244) {

    pfVar3 = (float *)XFGetCameraOrigin();

    fStack_188 = *pfVar3;

    fStack_184 = pfVar3[1];

    fStack_180 = 0.0;

    fStack_17c = *(float *)(DAT_006330e4 + 0x4f60);

    fStack_178 = *(float *)(DAT_006330e4 + 0x4f64);

    fStack_174 = 0.0;

    normalize__FPfN20(&fStack_17c,&fStack_178,&fStack_174);

    fStack_17c = fStack_17c * 12500.0;

    fStack_178 = fStack_178 * 12500.0;

    fStack_174 = fStack_174 * 12500.0;

    fStack_170 = fStack_17c - fStack_188;

    fStack_16c = fStack_178 - fStack_184;

    fStack_168 = fStack_174 - fStack_180;

    normalize__FPfN20(&fStack_170,&fStack_16c,&fStack_168);

    fStack_164 = fStack_16c * -0.0013;

    fStack_160 = fStack_170 * 0.0013;

    fStack_158 = -(fStack_180 * 0.0 + fStack_164 * fStack_188 + fStack_160 * fStack_184);

    (**(code **)(DAT_00656420 + 0xe8))(DAT_00656420,0,fStack_164,fStack_160,0,fStack_158);

  }

  return;

}

/* ===== FUN_00432950 @ 0x00432950 ===== */
void FUN_00432950(void)



{

  int iVar1;

  

  iVar1 = 0;

  do {

    (*(code *)(&DAT_00656d40)[iVar1])(iVar1);

    (**(code **)((&DAT_00656680)[iVar1] + 8))((&DAT_00656680)[iVar1]);

    iVar1 = iVar1 + 1;

  } while (iVar1 < 9);

  (**(code **)(DAT_00656420 + 0x4c))(DAT_00656420,0,0,0,0);

  (**(code **)(DAT_00656420 + 0x4c))(DAT_00656420,0,0,0,1);

  if (0 < DAT_00633244) {

    (**(code **)(DAT_00656420 + 0x50))(DAT_00656420,0,2);

  }

  return;

}

/* ===== drawwrld_scene_link @ 0x00432F30 ===== */
void drawwrld_scene_link(void)



{

  if (DAT_006330e4 != 0) {

    main_drawwrld_00432e10();

    main_drawwrld_004329b0();

    return;

  }

  return;

}

/* ===== audio_stream_tied @ 0x00434280 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void audio_stream_tied(void)



{

  undefined4 *puVar1;

  float *pfVar2;

  uint uVar3;

  int iVar4;

  int iVar5;

  int *piVar6;

  uint uVar7;

  int *piVar8;

  float *pfVar9;

  float local_284;

  float local_280;

  float local_27c;

  float local_278;

  float local_274;

  float local_270;

  float local_26c;

  float local_268;

  int local_264;

  int local_260;

  undefined1 local_25c [8];

  undefined4 local_254;

  float local_250 [4];

  float afStack_240 [4];

  float afStack_230 [4];

  float afStack_220 [4];

  int local_210 [2];

  float local_208 [4];

  float local_1f8;

  float local_1f0;

  float local_1ec;

  float local_1e4;

  float local_1e0;

  undefined1 auStack_80 [128];

  

  puVar1 = (undefined4 *)XFGetCameraOrigin();

  _DAT_0059ca94 = *puVar1;

  _DAT_0059ca98 = puVar1[1];

  _DAT_0059ca9c = puVar1[2];

  local_274 = (float)*(int *)(DAT_006330e4 + 0x20);

  local_26c = (float)*(int *)(DAT_006330e4 + 0x24);

  local_268 = (float)*(int *)(DAT_006330e4 + 0x28);

  local_270 = (float)*(int *)(DAT_006330e4 + 0x2c);

  local_264 = *(int *)(DAT_006330e4 + 0x30);

  local_260 = *(int *)(DAT_006330e4 + 0x34);

  XFGetCameraOrigin();

  FUN_004319c0(local_25c);

  pfVar2 = (float *)AudioDataStreamStatus__Fv_4();

  pfVar9 = local_250;

  for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {

    *pfVar9 = *pfVar2;

    pfVar2 = pfVar2 + 1;

    pfVar9 = pfVar9 + 1;

  }

  local_208[0] = local_274;

  local_208[1] = local_268;

  local_208[3] = local_26c;

  local_1f8 = local_268;

  local_1f0 = local_26c;

  local_254 = 0x33;

  local_210[0] = 4;

  local_1ec = local_270;

  local_1e4 = local_274;

  local_1e0 = local_270;

  uVar7 = 0;

  piVar8 = local_210;

  do {

    piVar6 = piVar8;

    if (*piVar8 == 0) break;

    if ((int)uVar7 < 4) {

      uVar3 = (int)uVar7 >> 1 & 1;

      local_284 = local_250[uVar3];

      local_280 = afStack_240[uVar3];

      local_27c = afStack_230[uVar3];

      local_278 = afStack_220[uVar3];

      if ((uVar7 & 1) != 0) {

        local_284 = -local_284;

        local_280 = -local_280;

        local_27c = -local_27c;

        local_278 = -local_278;

      }

      local_284 = local_250[3] + local_284;

      local_280 = afStack_240[3] + local_280;

      local_27c = afStack_230[3] + local_27c;

      local_278 = afStack_220[3] + local_278;

    }

    else {

      local_284 = local_250[2] * -1.0;

      local_280 = afStack_240[2] * -1.0;

      local_27c = afStack_230[2] * -1.0;

      local_278 = afStack_220[2] * -1.0;

    }

    local_278 = local_284 * *(float *)(DAT_006330e4 + 0x1c8) +

                local_280 * *(float *)(DAT_006330e4 + 0x1cc) + local_278;

    local_284 = local_284 * *(float *)(DAT_006330e4 + 0x1c0);

    local_280 = local_280 * *(float *)(DAT_006330e4 + 0x1c0);

    iVar5 = local_264;

    if (0.0 < local_27c) {

      iVar5 = local_260;

    }

    iVar4 = 0;

    if (0 < *piVar8) {

      piVar6 = piVar8 + 4;

      do {

        *piVar6 = iVar5;

        iVar4 = iVar4 + 1;

        piVar6 = piVar6 + 3;

      } while (iVar4 < *piVar8);

    }

    piVar6 = local_210 + (~uVar7 & 1) * 0x32;

    iVar5 = geom_clip_poly_plane(local_208 + (~uVar7 & 1) * 0x32,piVar8 + 2,&local_284,*piVar8);

    uVar7 = uVar7 + 1;

    *piVar6 = iVar5;

    piVar8 = piVar6;

  } while ((int)uVar7 < 4);

  main_drawwrld_00434620(piVar6,local_25c);

  if (*piVar6 < 3) {

    return;

  }

  (**(code **)(DAT_00656420 + 0x18))(DAT_00656420,&DAT_00556770);

  DAT_0059ca90 = (-(uint)(DAT_00632ba8 != 0) & 0xfffffff0) + 0x14;

  if ((*(byte *)(DAT_006330e4 + 0x1c) & 2) == 0) {

    DAT_0059cba0 = 0;

  }

  else {

    uVar7 = *(uint *)(DAT_006330e4 + 0x48) & 0xf0;

    if (uVar7 == 0x10) {

      DAT_0059ca90 = DAT_0059ca90 | 0x1080;

    }

    else if (uVar7 == 0x20) {

      DAT_0059ca90 = DAT_0059ca90 | 0x3080;

    }

    else {

      DAT_0059ca90 = DAT_0059ca90 | 0x2080;

    }

    if (*(float *)(DAT_006330e4 + 0x1ac) == 0.0) {

      iVar5 = __ftol();

      DAT_0059cba0 = iVar5 << 0x18;

    }

    else {

      DAT_0059cba0 = -0x1000000;

    }

  }

  makewrld_big();

  FUN_0053f2e0(auStack_80,piVar6 + 2,*piVar6);

  FUN_004a13c0(&DAT_00556fc4);

  if (DAT_00632ba8 == 0) {

    crt_loader_walk(piVar6[1],*piVar6,auStack_80,&PTR_LAB_00556e68,0,0);

    FUN_00432950();

    return;

  }

  crt_matrix_ops(*piVar6,auStack_80,&PTR_LAB_00556e88);

  FUN_00432950();

  return;

}

/* ===== main/drawwrld_00434620 @ 0x00434620 ===== */
void main_drawwrld_00434620(int param_1,float *param_2)



{

  uint uVar1;

  

  uVar1 = (uint)(param_2[1] < 0.0) * 4;

  *(uint *)(param_1 + 4) = uVar1;

  uVar1 = (uint)(*param_2 < 0.0) * 2 | uVar1;

  *(uint *)(param_1 + 4) = uVar1;

  switch(uVar1) {

  case 0:

    break;

  case 2:

    if (-*param_2 <= param_2[1]) {

      *(undefined4 *)(param_1 + 4) = 2;

      return;

    }

    *(undefined4 *)(param_1 + 4) = 3;

    return;

  case 4:

    if (*param_2 <= -param_2[1]) {

      *(undefined4 *)(param_1 + 4) = 4;

      return;

    }

    *(undefined4 *)(param_1 + 4) = 5;

    return;

  case 6:

    if (-param_2[1] < -*param_2) {

      *(undefined4 *)(param_1 + 4) = 7;

      return;

    }

    *(undefined4 *)(param_1 + 4) = 6;

  default:

    return;

  }

  if (*param_2 <= param_2[1]) {

    *(undefined4 *)(param_1 + 4) = 0;

    return;

  }

  *(undefined4 *)(param_1 + 4) = 1;

  return;

}

/* ===== dlog_entry_draw @ 0x00434730 ===== */
void dlog_entry_draw(uint *param_1,int param_2)



{

  undefined4 *puVar1;

  int iVar2;

  int iVar3;

  undefined4 *puVar4;

  

  iVar3 = (uint)*(ushort *)(param_2 + 0x16) - (uint)*(ushort *)(param_2 + 0x14);

  if (iVar3 != 0) {

    (**(code **)(param_1[0xd] + 8))

              (param_1[0xd],*(undefined4 *)(param_2 + 4),*(undefined4 *)(param_2 + 8),

               *(undefined4 *)(param_2 + 0xc));

    (**(code **)(DAT_00656420 + 0x50))(DAT_00656420,2,0);

    (**(code **)(DAT_00656420 + 0x50))(DAT_00656420,2,1);

    (**(code **)(DAT_00656420 + 0x50))(DAT_00656420,2,2);

    (**(code **)(DAT_00656420 + 0x50))(DAT_00656420,2,3);

    if ((~*param_1 & 1) == 0) {

      (**(code **)(param_1[0xc] + 0x1c))

                (param_1[0xc],0,(uint)*(ushort *)(param_2 + 0x10),

                 (uint)*(ushort *)(param_2 + 0x12) - (uint)*(ushort *)(param_2 + 0x10));

    }

    else {

      puVar1 = (undefined4 *)

               (**(code **)(param_1[0xc] + 0x10))

                         (param_1[0xc],

                          (uint)*(ushort *)(param_2 + 0x12) - (uint)*(ushort *)(param_2 + 0x10));

      puVar4 = (undefined4 *)(param_1[4] + (uint)*(ushort *)(param_2 + 0x10) * 0x18);

      for (iVar2 = (((uint)*(ushort *)(param_2 + 0x12) - (uint)*(ushort *)(param_2 + 0x10)) * 3 &

                   0x1fffffff) << 1; iVar2 != 0; iVar2 = iVar2 + -1) {

        *puVar1 = *puVar4;

        puVar4 = puVar4 + 1;

        puVar1 = puVar1 + 1;

      }

      for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {

        *(undefined1 *)puVar1 = *(undefined1 *)puVar4;

        puVar4 = (undefined4 *)((int)puVar4 + 1);

        puVar1 = (undefined4 *)((int)puVar1 + 1);

      }

      (**(code **)(param_1[0xc] + 0x18))(param_1[0xc],-(uint)*(ushort *)(param_2 + 0x10));

    }

    (**(code **)(param_1[0xc] + 0x20))

              (param_1[0xc],iVar3,param_1[2] + (uint)*(ushort *)(param_2 + 0x14) * 2);

    (**(code **)(DAT_00656420 + 0x50))(DAT_00656420,0,0);

    (**(code **)(DAT_00656420 + 0x50))(DAT_00656420,0,1);

    (**(code **)(DAT_00656420 + 0x50))(DAT_00656420,0,2);

    (**(code **)(DAT_00656420 + 0x50))(DAT_00656420,0,3);

  }

  return;

}

/* ===== main/drawwrld_00434880 @ 0x00434880 ===== */
bool main_drawwrld_00434880(float *param_1,float param_2,float param_3,float *param_4,int param_5)



{

  float fVar1;

  float fVar2;

  float10 fVar3;

  float local_c;

  float local_8;

  float local_4;

  

  *param_1 = param_2;

  param_1[1] = param_3;

  if (DAT_00632b90 == 0) {

    param_1[2] = *param_4;

  }

  else {

    *param_1 = param_2;

    local_c = param_2;

    local_8 = param_3;

    param_1[1] = param_3;

    local_4 = *param_4;

    fVar3 = (float10)world_ripple_xform(&local_c);

    param_1[2] = (float)fVar3;

  }

  fVar1 = param_3 * *(float *)(param_5 + 0x40) + param_2 * *(float *)(param_5 + 0x3c) +

          *(float *)(param_5 + 0x48);

  fVar2 = param_3 * *(float *)(param_5 + 0x50) + param_2 * *(float *)(param_5 + 0x4c) +

          *(float *)(param_5 + 0x58);

  param_1[4] = fVar1;

  param_1[5] = fVar2;

  if (1.0 < fVar2) {

    return true;

  }

  return (fVar2 < 0.0 || fVar1 < 0.0) || 1.0 < fVar1;

}

/* ===== geometry_clip_helper @ 0x00434AA0 ===== */
int geometry_clip_helper

              (int param_1,int *param_2,int *param_3,int *param_4,float *param_5,int param_6)



{

  int iVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  int iVar5;

  float *pfVar6;

  float *pfVar7;

  float *pfVar8;

  float *pfVar9;

  int *local_8;

  int local_4;

  

  local_4 = param_6;

  param_6 = 0;

  iVar5 = 0;

  if (2 < local_4) {

    iVar1 = *param_3;

    pfVar6 = (float *)(param_1 + param_3[local_4 + -1] * 0x18);

    iVar5 = param_6;

    if (local_4 != 0) {

      local_8 = param_3;

      pfVar8 = (float *)(param_1 + *param_4 * 0x18);

      param_3 = (int *)(pfVar6[4] * *param_5 +

                        *(float *)(param_1 + 0x14 + param_3[local_4 + -1] * 0x18) * param_5[1] +

                       param_5[2]);

      do {

        pfVar7 = (float *)(param_1 + iVar1 * 0x18);

        fVar2 = pfVar7[4] * *param_5 + param_5[1] * pfVar7[5] + param_5[2];

        pfVar9 = pfVar8;

        if ((float)param_3 < 0.0 != fVar2 < 0.0) {

          pfVar9 = pfVar8 + 6;

          fVar3 = (float)param_3 / ((float)param_3 - fVar2);

          fVar4 = 1.0 - fVar3;

          *pfVar8 = fVar3 * *pfVar7 + fVar4 * *pfVar6;

          pfVar8[1] = fVar3 * pfVar7[1] + fVar4 * pfVar6[1];

          pfVar8[2] = fVar3 * pfVar7[2] + fVar4 * pfVar6[2];

          pfVar8[4] = fVar3 * pfVar7[4] + fVar4 * pfVar6[4];

          pfVar8[5] = fVar3 * pfVar7[5] + fVar4 * pfVar6[5];

          *param_2 = *param_4;

          param_6 = param_6 + 1;

          *param_4 = *param_4 + 1;

          param_2 = param_2 + 1;

        }

        if (0.0 < fVar2) {

          *param_2 = *local_8;

          param_2 = param_2 + 1;

          param_6 = param_6 + 1;

        }

        local_8 = local_8 + 1;

        iVar1 = *local_8;

        local_4 = local_4 + -1;

        iVar5 = param_6;

        pfVar6 = pfVar7;

        pfVar8 = pfVar9;

        param_3 = (int *)fVar2;

      } while (local_4 != 0);

    }

  }

  return iVar5;

}

/* ===== main/drawwrld_00434c30 @ 0x00434C30 ===== */
void main_drawwrld_00434c30(int param_1)



{

  undefined4 *puVar1;

  

  if (param_1 != 0) {

    puVar1 = *(undefined4 **)(param_1 + 0x18);

    *(undefined4 **)(param_1 + 0x1c) = puVar1;

    *(undefined4 **)(param_1 + 0x20) = puVar1;

    *(undefined4 **)(param_1 + 0x24) = puVar1 + *(int *)(param_1 + 0x14) * 6 + -6;

    *(undefined2 *)(puVar1 + 5) = 0;

    *(undefined2 *)(puVar1 + 4) = 0;

    *(undefined2 *)((int)puVar1 + 0x12) = 0;

    *(undefined2 *)((int)puVar1 + 0x16) = 0;

    *puVar1 = 0;

    GEO_MatIdentity(param_1 + 0x38);

    *(undefined4 *)(param_1 + 0x7c) = 0;

  }

  return;

}

/* ===== sceMpegSetDecodeMode @ 0x00434CC0 ===== */
void sceMpegSetDecodeMode(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)



{

  int iVar1;

  

  iVar1 = *(int *)(param_1 + 0x1c);

  *(undefined4 *)(iVar1 + 4) = param_2;

  *(undefined4 *)(iVar1 + 8) = param_3;

  *(undefined4 *)(iVar1 + 0xc) = param_4;

  return;

}

/* ===== main/drawwrld_00434ce0 @ 0x00434CE0 ===== */
void main_drawwrld_00434ce0(byte *param_1)



{

  undefined4 uVar1;

  

  if ((*param_1 & 1) != 0) {

    (**(code **)(*(int *)(param_1 + 0x30) + 4))(*(int *)(param_1 + 0x30),0,5);

    uVar1 = (**(code **)(*(int *)(param_1 + 0x30) + 0x10))

                      (*(int *)(param_1 + 0x30),*(undefined4 *)(param_1 + 0xc));

    *(undefined4 *)(param_1 + 0x10) = uVar1;

  }

  return;

}

/* ===== dlog_level_free_if @ 0x00434D10 ===== */
void dlog_level_free_if(byte *param_1)



{

  if ((*param_1 & 1) != 0) {

    cleanup_00434d40(param_1);

    (**(code **)(*(int *)(param_1 + 0x30) + 0x2c))(*(int *)(param_1 + 0x30));

    (**(code **)(*(int *)(param_1 + 0x30) + 8))(*(int *)(param_1 + 0x30));

  }

  return;

}

/* ===== cleanup_00434d40 @ 0x00434D40 ===== */
void cleanup_00434d40(uint *param_1)



{

  uint uVar1;

  int iVar2;

  int *piVar3;

  int *piVar4;

  int *piVar5;

  int *piVar6;

  int aiStack_18 [4];

  short sStack_6;

  short sStack_4;

  short sStack_2;

  

  (**(code **)(DAT_00656420 + 0x18))(DAT_00656420,&DAT_00556770);

  (**(code **)(DAT_00656420 + 0x48))(DAT_00656420,2);

  if ((~*param_1 & 1) != 0) {

    (**(code **)(param_1[0xc] + 4))(param_1[0xc],0,5);

  }

  piVar3 = (int *)param_1[8];

  if ((*param_1 & 2) == 0) {

    piVar5 = (int *)param_1[7];

    piVar4 = piVar3;

    piVar6 = aiStack_18;

    for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {

      *piVar6 = *piVar4;

      piVar4 = piVar4 + 1;

      piVar6 = piVar6 + 1;

    }

    if (piVar3 != piVar5) {

      do {

        piVar3 = piVar3 + 6;

        if ((int *)param_1[9] < piVar3) {

          piVar3 = (int *)param_1[6];

        }

        if ((((aiStack_18[1] == piVar3[1]) && (aiStack_18[2] == piVar3[2])) &&

            (aiStack_18[3] == piVar3[3])) &&

           ((sStack_2 == (short)piVar3[5] && (sStack_6 == (short)piVar3[4])))) {

          sStack_2 = *(short *)((int)piVar3 + 0x16);

          sStack_6 = *(short *)((int)piVar3 + 0x12);

        }

        else {

          dlog_entry_draw(param_1,aiStack_18);

          piVar5 = piVar3;

          piVar4 = aiStack_18;

          for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {

            *piVar4 = *piVar5;

            piVar5 = piVar5 + 1;

            piVar4 = piVar4 + 1;

          }

        }

      } while (piVar3 != (int *)param_1[7]);

    }

    if (sStack_4 == sStack_2) goto LAB_00434f2e;

    piVar5 = aiStack_18;

  }

  else {

    if (piVar3 != (int *)param_1[7]) {

      do {

        uVar1 = __ftol();

        piVar3[3] = ((uVar1 << 8 | uVar1) << 8 | uVar1) << 8 | uVar1;

        dlog_entry_draw(param_1,piVar3);

        piVar3 = piVar3 + 6;

        if ((int *)param_1[9] < piVar3) {

          piVar3 = (int *)param_1[6];

        }

      } while (piVar3 != (int *)param_1[7]);

    }

    piVar3[3] = -1;

    piVar5 = piVar3;

  }

  dlog_entry_draw(param_1,piVar5);

LAB_00434f2e:

  if ((~*param_1 & 1) == 0) {

    param_1[8] = (uint)piVar3;

    *(undefined2 *)((int)piVar3 + 0x12) = 0;

    *(undefined2 *)(piVar3 + 4) = 0;

    *(undefined2 *)((int)piVar3 + 0x16) = 0;

    *(undefined2 *)(piVar3 + 5) = 0;

    param_1[10] = param_1[3];

    param_1[0xb] = param_1[1];

    param_1[0x1f] = 0;

  }

  else {

    (**(code **)(param_1[0xc] + 8))(param_1[0xc]);

  }

  (**(code **)(DAT_00656420 + 0x48))(DAT_00656420,0);

  return;

}

/* ===== drawwrld_cell_cull @ 0x00434F80 ===== */
void drawwrld_cell_cull(int param_1,int param_2,int param_3)



{

  ushort uVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  uint uVar5;

  

  iVar2 = *(int *)(param_1 + 0x1c);

  while( true ) {

    while( true ) {

      uVar1 = *(ushort *)(iVar2 + 0x12);

      iVar4 = (uint)*(ushort *)(*(int *)(param_1 + 0x20) + 0x10) - (uint)uVar1;

      if (-1 < iVar4) break;

      iVar4 = *(int *)(param_1 + 0xc) - (uint)uVar1;

      if ((param_2 <= iVar4) || (*(ushort *)(iVar2 + 0x10) != uVar1)) goto LAB_00435000;

      *(undefined2 *)(iVar2 + 0x12) = 0;

      *(undefined2 *)(iVar2 + 0x10) = 0;

    }

    if ((param_2 <= iVar4) || (*(int *)(param_1 + 0x20) == *(int *)(param_1 + 0x1c))) break;

    do {

      uVar5 = *(int *)(param_1 + 0x20) + 0x18;

      *(uint *)(param_1 + 0x20) = uVar5;

      if (*(uint *)(param_1 + 0x24) < uVar5) {

        *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(param_1 + 0x18);

      }

      *(int *)(param_1 + 0x7c) = *(int *)(param_1 + 0x7c) + -1;

    } while (((**(byte **)(param_1 + 0x20) & 1) != 0) &&

            (*(byte **)(param_1 + 0x20) != *(byte **)(param_1 + 0x1c)));

  }

LAB_00435000:

  do {

    uVar1 = *(ushort *)(iVar2 + 0x16);

    iVar3 = (uint)*(ushort *)(*(int *)(param_1 + 0x20) + 0x14) - (uint)uVar1;

    if (-1 < iVar3) {

      if ((param_3 <= iVar3) || (*(int *)(param_1 + 0x20) == *(int *)(param_1 + 0x1c))) {

LAB_00435071:

        if (*(int *)(param_1 + 0x20) == iVar2) {

          if (*(short *)(iVar2 + 0x14) == *(short *)(iVar2 + 0x16)) {

            *(undefined2 *)(iVar2 + 0x16) = 0;

            *(undefined2 *)(iVar2 + 0x14) = 0;

            iVar3 = *(int *)(param_1 + 4);

          }

          if (*(short *)(iVar2 + 0x10) == *(short *)(iVar2 + 0x12)) {

            *(undefined2 *)(iVar2 + 0x12) = 0;

            *(undefined2 *)(iVar2 + 0x10) = 0;

            *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(param_1 + 0xc);

            *(int *)(param_1 + 0x2c) = iVar3;

            return;

          }

        }

        *(int *)(param_1 + 0x28) = iVar4;

        *(int *)(param_1 + 0x2c) = iVar3;

        return;

      }

      do {

        uVar5 = *(int *)(param_1 + 0x20) + 0x18;

        *(uint *)(param_1 + 0x20) = uVar5;

        if (*(uint *)(param_1 + 0x24) < uVar5) {

          *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(param_1 + 0x18);

        }

        *(int *)(param_1 + 0x7c) = *(int *)(param_1 + 0x7c) + -1;

      } while (((**(byte **)(param_1 + 0x20) & 1) != 0) &&

              (*(byte **)(param_1 + 0x20) != *(byte **)(param_1 + 0x1c)));

      goto LAB_00435000;

    }

    iVar3 = *(int *)(param_1 + 4) - (uint)uVar1;

    if ((param_3 <= iVar3) || (*(ushort *)(iVar2 + 0x14) != uVar1)) goto LAB_00435071;

    *(undefined2 *)(iVar2 + 0x16) = 0;

    *(undefined2 *)(iVar2 + 0x14) = 0;

  } while( true );

}

/* ===== dlog_entry_update @ 0x004350C0 ===== */
void dlog_entry_update(byte *param_1)



{

  undefined2 uVar1;

  undefined4 *puVar2;

  int iVar3;

  undefined4 *puVar4;

  

  puVar2 = *(undefined4 **)(param_1 + 0x1c);

  if ((*(short *)(puVar2 + 4) != *(short *)((int)puVar2 + 0x12)) ||

     (*(short *)(puVar2 + 5) != *(short *)((int)puVar2 + 0x16))) {

    puVar4 = puVar2 + 6;

    if (*(undefined4 **)(param_1 + 0x24) < puVar4) {

      puVar4 = *(undefined4 **)(param_1 + 0x18);

    }

    if (puVar4 == *(undefined4 **)(param_1 + 0x20)) {

      if ((*param_1 & 1) == 0) {

        *(undefined4 **)(param_1 + 0x1c) = puVar4;

        do {

          iVar3 = *(int *)(param_1 + 0x20);

          *(uint *)(param_1 + 0x20) = iVar3 + 0x18U;

          if (*(uint *)(param_1 + 0x24) < iVar3 + 0x18U) {

            *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(param_1 + 0x18);

          }

          *(int *)(param_1 + 0x7c) = *(int *)(param_1 + 0x7c) + -1;

        } while (((**(byte **)(param_1 + 0x20) & 1) != 0) &&

                (*(byte **)(param_1 + 0x20) != *(byte **)(param_1 + 0x1c)));

      }

      else {

        cleanup_00434d40(param_1);

        puVar4 = puVar2;

      }

    }

    else {

      *(undefined4 **)(param_1 + 0x1c) = puVar4;

    }

    *(int *)(param_1 + 0x7c) = *(int *)(param_1 + 0x7c) + 1;

    puVar4[1] = puVar2[1];

    puVar4[2] = puVar2[2];

    puVar4[3] = puVar2[3];

    uVar1 = *(undefined2 *)((int)puVar2 + 0x16);

    *(undefined2 *)((int)puVar4 + 0x16) = uVar1;

    *(undefined2 *)(puVar4 + 5) = uVar1;

    uVar1 = *(undefined2 *)((int)puVar2 + 0x12);

    *(undefined2 *)((int)puVar4 + 0x12) = uVar1;

    *(undefined2 *)(puVar4 + 4) = uVar1;

    *puVar4 = 0;

  }

  return;

}

/* ===== dlog_entry_render_quads @ 0x00435940 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void dlog_entry_render_quads(byte *param_1,undefined4 param_2,float *param_3)



{

  byte *pbVar1;

  undefined4 *puVar2;

  undefined4 uVar3;

  int iVar4;

  byte *local_190;

  float fStack_18c;

  float fStack_188;

  undefined4 uStack_184;

  float fStack_180;

  float fStack_17c;

  undefined4 uStack_178;

  float fStack_174;

  float fStack_170;

  undefined4 uStack_16c;

  float fStack_168;

  float fStack_164;

  undefined4 uStack_160;

  float fStack_15c;

  float fStack_158;

  undefined4 uStack_154;

  float fStack_150;

  float fStack_14c;

  undefined4 uStack_148;

  undefined1 auStack_144 [8];

  undefined4 auStack_13c [22];

  undefined1 auStack_e4 [68];

  undefined1 auStack_a0 [96];

  undefined1 auStack_40 [64];

  

  pbVar1 = param_1 + 0x38;

  local_190 = param_1;

  (*(code *)PTR_crt_matrix_copy_init_00580c1c)(pbVar1,param_2);

  fStack_18c = -*param_3;

  fStack_188 = -param_3[4];

  uStack_184 = 0;

  FUN_0053dc10(auStack_e4,&fStack_18c);

  (*(code *)PTR_crt_matrix_mul_00580c18)(pbVar1,auStack_e4,pbVar1);

  fStack_180 = 1.0 / (param_3[3] - *param_3);

  uStack_178 = 0;

  fStack_17c = -1.0 / (param_3[4] - param_3[1]);

  FUN_0053dca0(auStack_e4,&fStack_180);

  (*(code *)PTR_crt_matrix_mul_00580c18)(pbVar1,auStack_e4,pbVar1);

  fStack_174 = *param_3;

  fStack_170 = param_3[1];

  fStack_168 = param_3[3];

  fStack_158 = param_3[4];

  fStack_150 = *param_3;

  uStack_148 = 0;

  uStack_154 = 0;

  uStack_160 = 0;

  uStack_16c = 0;

  fStack_164 = fStack_170;

  fStack_15c = fStack_168;

  fStack_14c = fStack_158;

  (*(code *)PTR_S_GEO_Vec3Transform_00580c20)(auStack_144,&fStack_174,4,param_2);

  iVar4 = 4;

  puVar2 = auStack_13c;

  do {

    iVar4 = iVar4 + -1;

    puVar2[-2] = ((float)puVar2[-2] - *(float *)(DAT_006330e4 + 0x1c8)) *

                 *(float *)(DAT_006330e4 + 0x1c4);

    puVar2[-1] = ((float)puVar2[-1] - *(float *)(DAT_006330e4 + 0x1cc)) *

                 *(float *)(DAT_006330e4 + 0x1c4);

    *puVar2 = *puVar2;

    puVar2 = puVar2 + 3;

  } while (iVar4 != 0);

  _DAT_00556f4c = -(float)*(int *)(DAT_006330e4 + 0x20);

  _DAT_00556f5c = -(float)*(int *)(DAT_006330e4 + 0x28);

  _DAT_00556f6c = (float)*(int *)(DAT_006330e4 + 0x24);

  _DAT_00556f7c = (float)*(int *)(DAT_006330e4 + 0x2c);

  uVar3 = geom_clip_poly_plane(auStack_a0,auStack_144,&DAT_00556f40,4);

  uVar3 = geom_clip_poly_plane(auStack_144,auStack_a0,&DAT_00556f50,uVar3);

  uVar3 = geom_clip_poly_plane(auStack_a0,auStack_144,&DAT_00556f60,uVar3);

  iVar4 = geom_clip_poly_plane(auStack_144,auStack_a0,&DAT_00556f70,uVar3);

  FUN_0053f2e0(auStack_40,auStack_144,iVar4);

  if (2 < iVar4) {

    crt_matrix_ops(iVar4,auStack_40,&PTR_LAB_00556f1c,0,&local_190);

  }

  dlog_entry_update(param_1);

  if ((*param_1 & 1) != 0) {

    cleanup_00434d40(param_1);

    uVar3 = (**(code **)(*(int *)(param_1 + 0x30) + 0x10))

                      (*(int *)(param_1 + 0x30),*(undefined4 *)(param_1 + 0xc));

    *(undefined4 *)(param_1 + 0x10) = uVar3;

    drawwrld_cell_cull(param_1,0,0);

  }

  return;

}

/* ===== fx_blob_shadow @ 0x00435BC0 ===== */
void fx_blob_shadow(void)



{

  int iVar1;

  undefined4 uVar2;

  

  PTR_main_drawwrld_00434880_00556ee8 = main_drawwrld_00434880;

  if (-1 < (char)DAT_00632e94) {

    PTR_main_drawwrld_00434880_00556ee8 = &LAB_00434990;

  }

  fx_blastmark();

  fx_kabuto_footprint();

  drawwrld_mpeg_helper();

  DAT_006565e4 = main_texture_00508750(s_b_shadow_00556fd4);

  DAT_00656498 = main_drawwrld_00435170(500,0x14,1);

  DAT_00656494 = main_drawwrld_00435170(200,0x32,1);

  uVar2 = DAT_006565e4;

  iVar1 = *(int *)(DAT_00656494 + 0x1c);

  *(undefined4 *)(iVar1 + 4) = 0x4033c;

  *(undefined4 *)(iVar1 + 8) = uVar2;

  *(undefined4 *)(iVar1 + 0xc) = 0xffffffff;

  DAT_0065646c = main_drawwrld_00435170(2000,500,0);

  DAT_00656544 = main_drawwrld_00435170(500,0xfa,0);

  uVar2 = DAT_006565e4;

  iVar1 = *(int *)(DAT_00656544 + 0x1c);

  *(undefined4 *)(iVar1 + 4) = 0x4033c;

  *(undefined4 *)(iVar1 + 8) = uVar2;

  *(undefined4 *)(iVar1 + 0xc) = 0xffffffff;

  return;

}

/* ===== dlog_frame_reset @ 0x00435C90 ===== */
void dlog_frame_reset(void)



{

  undefined4 *puVar1;

  int iVar2;

  int iVar3;

  

  iVar3 = DAT_00656544;

  for (puVar1 = DAT_00632d68; DAT_00656544 = iVar3, puVar1 != (undefined4 *)0x0;

      puVar1 = (undefined4 *)*puVar1) {

    *(uint *)(puVar1[3] + 0x1c8) = *(uint *)(puVar1[3] + 0x1c8) & 0xbfffffff;

    iVar3 = DAT_00656544;

  }

  PTR_main_drawwrld_00434880_00556ee8 = main_drawwrld_00434880;

  if (-1 < (char)DAT_00632e94) {

    PTR_main_drawwrld_00434880_00556ee8 = &LAB_00434990;

  }

  if (iVar3 != 0) {

    puVar1 = *(undefined4 **)(iVar3 + 0x18);

    *(undefined4 **)(iVar3 + 0x1c) = puVar1;

    *(undefined4 **)(iVar3 + 0x20) = puVar1;

    *(undefined4 **)(iVar3 + 0x24) = puVar1 + *(int *)(iVar3 + 0x14) * 6 + -6;

    *(undefined2 *)(puVar1 + 5) = 0;

    *(undefined2 *)(puVar1 + 4) = 0;

    *(undefined2 *)((int)puVar1 + 0x12) = 0;

    *(undefined2 *)((int)puVar1 + 0x16) = 0;

    *puVar1 = 0;

    GEO_MatIdentity(iVar3 + 0x38);

    *(undefined4 *)(iVar3 + 0x7c) = 0;

  }

  iVar3 = DAT_0065646c;

  if (DAT_0065646c != 0) {

    puVar1 = *(undefined4 **)(DAT_0065646c + 0x18);

    iVar2 = *(int *)(DAT_0065646c + 0x14);

    *(undefined4 **)(DAT_0065646c + 0x1c) = puVar1;

    *(undefined4 **)(iVar3 + 0x20) = puVar1;

    *(undefined4 **)(iVar3 + 0x24) = puVar1 + iVar2 * 6 + -6;

    *(undefined2 *)(puVar1 + 5) = 0;

    *(undefined2 *)(puVar1 + 4) = 0;

    *(undefined2 *)((int)puVar1 + 0x12) = 0;

    *(undefined2 *)((int)puVar1 + 0x16) = 0;

    *puVar1 = 0;

    GEO_MatIdentity(iVar3 + 0x38);

    *(undefined4 *)(iVar3 + 0x7c) = 0;

  }

  iVar3 = DAT_006573ec;

  if (DAT_006573ec != 0) {

    puVar1 = *(undefined4 **)(DAT_006573ec + 0x18);

    iVar2 = *(int *)(DAT_006573ec + 0x14);

    *(undefined4 **)(DAT_006573ec + 0x1c) = puVar1;

    *(undefined4 **)(iVar3 + 0x20) = puVar1;

    *(undefined4 **)(iVar3 + 0x24) = puVar1 + iVar2 * 6 + -6;

    *(undefined2 *)(puVar1 + 5) = 0;

    *(undefined2 *)(puVar1 + 4) = 0;

    *(undefined2 *)((int)puVar1 + 0x12) = 0;

    *(undefined2 *)((int)puVar1 + 0x16) = 0;

    *puVar1 = 0;

    GEO_MatIdentity(iVar3 + 0x38);

    *(undefined4 *)(iVar3 + 0x7c) = 0;

  }

  iVar3 = DAT_006573e8;

  if (DAT_006573e8 != 0) {

    puVar1 = *(undefined4 **)(DAT_006573e8 + 0x18);

    iVar2 = *(int *)(DAT_006573e8 + 0x14);

    *(undefined4 **)(DAT_006573e8 + 0x1c) = puVar1;

    *(undefined4 **)(iVar3 + 0x20) = puVar1;

    *(undefined4 **)(iVar3 + 0x24) = puVar1 + iVar2 * 6 + -6;

    *(undefined2 *)(puVar1 + 5) = 0;

    *(undefined2 *)(puVar1 + 4) = 0;

    *(undefined2 *)((int)puVar1 + 0x12) = 0;

    *(undefined2 *)((int)puVar1 + 0x16) = 0;

    *puVar1 = 0;

    GEO_MatIdentity(iVar3 + 0x38);

    *(undefined4 *)(iVar3 + 0x7c) = 0;

  }

  iVar3 = DAT_006573f0;

  if (DAT_006573f0 != 0) {

    puVar1 = *(undefined4 **)(DAT_006573f0 + 0x18);

    iVar2 = *(int *)(DAT_006573f0 + 0x14);

    *(undefined4 **)(DAT_006573f0 + 0x1c) = puVar1;

    *(undefined4 **)(iVar3 + 0x20) = puVar1;

    *(undefined4 **)(iVar3 + 0x24) = puVar1 + iVar2 * 6 + -6;

    *(undefined2 *)(puVar1 + 5) = 0;

    *(undefined2 *)(puVar1 + 4) = 0;

    *(undefined2 *)((int)puVar1 + 0x12) = 0;

    *(undefined2 *)((int)puVar1 + 0x16) = 0;

    *puVar1 = 0;

    GEO_MatIdentity(iVar3 + 0x38);

    *(undefined4 *)(iVar3 + 0x7c) = 0;

  }

  return;

}

/* ===== FUN_00435f30 @ 0x00435F30 ===== */
void FUN_00435f30(void)



{

  byte *pbVar1;

  undefined4 uVar2;

  

  pbVar1 = DAT_00656498;

  if ((*DAT_00656498 & 1) != 0) {

    (**(code **)(*(int *)(DAT_00656498 + 0x30) + 4))(*(int *)(DAT_00656498 + 0x30),0,5);

    uVar2 = (**(code **)(*(int *)(pbVar1 + 0x30) + 0x10))

                      (*(int *)(pbVar1 + 0x30),*(undefined4 *)(pbVar1 + 0xc));

    *(undefined4 *)(pbVar1 + 0x10) = uVar2;

  }

  pbVar1 = DAT_00656494;

  if ((*DAT_00656494 & 1) != 0) {

    (**(code **)(*(int *)(DAT_00656494 + 0x30) + 4))(*(int *)(DAT_00656494 + 0x30),0,5);

    uVar2 = (**(code **)(*(int *)(pbVar1 + 0x30) + 0x10))

                      (*(int *)(pbVar1 + 0x30),*(undefined4 *)(pbVar1 + 0xc));

    *(undefined4 *)(pbVar1 + 0x10) = uVar2;

  }

  pbVar1 = DAT_0065646c;

  if ((*DAT_0065646c & 1) != 0) {

    (**(code **)(*(int *)(DAT_0065646c + 0x30) + 4))(*(int *)(DAT_0065646c + 0x30),0,5);

    uVar2 = (**(code **)(*(int *)(pbVar1 + 0x30) + 0x10))

                      (*(int *)(pbVar1 + 0x30),*(undefined4 *)(pbVar1 + 0xc));

    *(undefined4 *)(pbVar1 + 0x10) = uVar2;

  }

  pbVar1 = DAT_00656544;

  if ((*DAT_00656544 & 1) != 0) {

    (**(code **)(*(int *)(DAT_00656544 + 0x30) + 4))(*(int *)(DAT_00656544 + 0x30),0,5);

    uVar2 = (**(code **)(*(int *)(pbVar1 + 0x30) + 0x10))

                      (*(int *)(pbVar1 + 0x30),*(undefined4 *)(pbVar1 + 0xc));

    *(undefined4 *)(pbVar1 + 0x10) = uVar2;

  }

  return;

}

/* ===== FUN_00435fd0 @ 0x00435FD0 ===== */
void FUN_00435fd0(void)



{

  int iVar1;

  byte *pbVar2;

  

  pbVar2 = DAT_00656498;

  if ((*DAT_00656498 & 1) != 0) {

    cleanup_00434d40(DAT_00656498);

    iVar1 = *(int *)(pbVar2 + 0x30);

    (**(code **)(iVar1 + 0x2c))(iVar1);

    iVar1 = *(int *)(pbVar2 + 0x30);

    (**(code **)(iVar1 + 8))(iVar1);

  }

  pbVar2 = DAT_00656494;

  if ((*DAT_00656494 & 1) != 0) {

    cleanup_00434d40(DAT_00656494);

    iVar1 = *(int *)(pbVar2 + 0x30);

    (**(code **)(iVar1 + 0x2c))(iVar1);

    iVar1 = *(int *)(pbVar2 + 0x30);

    (**(code **)(iVar1 + 8))(iVar1);

  }

  pbVar2 = DAT_0065646c;

  if ((*DAT_0065646c & 1) != 0) {

    cleanup_00434d40(DAT_0065646c);

    iVar1 = *(int *)(pbVar2 + 0x30);

    (**(code **)(iVar1 + 0x2c))(iVar1);

    iVar1 = *(int *)(pbVar2 + 0x30);

    (**(code **)(iVar1 + 8))(iVar1);

  }

  pbVar2 = DAT_00656544;

  if ((*DAT_00656544 & 1) != 0) {

    cleanup_00434d40(DAT_00656544);

    iVar1 = *(int *)(pbVar2 + 0x30);

    (**(code **)(iVar1 + 0x2c))(iVar1);

    iVar1 = *(int *)(pbVar2 + 0x30);

    (**(code **)(iVar1 + 8))(iVar1);

  }

  return;

}

/* ===== cleanup_00436060 @ 0x00436060 ===== */
void cleanup_00436060(void)



{

  dlog_free_global_1();

  dlog_free_global_2();

  dlog_free_global_3();

  cleanup_00434d40(DAT_0065646c);

  cleanup_00434d40(DAT_00656544);

  return;

}

/* ===== FUN_00436090 @ 0x00436090 ===== */
void FUN_00436090(uint param_1,int param_2,undefined4 param_3)



{

  int iVar1;

  

  if ((param_2 != 0) && (*(char *)(param_2 + 0x1e) < '\0')) {

    param_1 = param_1 | 0x80000;

  }

  iVar1 = *(int *)(DAT_00656498 + 0x1c);

  *(int *)(iVar1 + 8) = param_2;

  *(uint *)(iVar1 + 4) = param_1;

  *(undefined4 *)(iVar1 + 0xc) = param_3;

  return;

}

/* ===== FUN_004360d0 @ 0x004360D0 ===== */
void FUN_004360d0(undefined4 param_1,undefined4 param_2)



{

  dlog_entry_render_quads(DAT_00656498,param_1,param_2);

  return;

}

/* ===== FUN_004360f0 @ 0x004360F0 ===== */
void FUN_004360f0(undefined4 param_1)



{

  int iVar1;

  

  iVar1 = *(int *)(DAT_00656494 + 0x1c);

  *(undefined4 *)(iVar1 + 8) = DAT_006565e4;

  *(undefined4 *)(iVar1 + 4) = 0x4033c;

  *(undefined4 *)(iVar1 + 0xc) = param_1;

  return;

}

/* ===== FUN_00436110 @ 0x00436110 ===== */
void FUN_00436110(undefined4 param_1,undefined4 param_2)



{

  dlog_entry_render_quads(DAT_00656494,param_1,param_2);

  return;

}

/* ===== gfx_set_image_buffer @ 0x00436130 ===== */
/* PS2 candidate: sceMpegSetImageBuff (conf 0.769) */



void gfx_set_image_buffer(undefined4 param_1,undefined4 param_2,undefined4 param_3)



{

  int iVar1;

  

  iVar1 = *(int *)(DAT_0065646c + 0x1c);

  *(undefined4 *)(iVar1 + 4) = param_1;

  *(undefined4 *)(iVar1 + 8) = param_2;

  *(undefined4 *)(iVar1 + 0xc) = param_3;

  return;

}

/* ===== FUN_00436150 @ 0x00436150 ===== */
void FUN_00436150(undefined4 param_1,undefined4 param_2)



{

  dlog_entry_render_quads(DAT_0065646c,param_1,param_2);

  return;

}

/* ===== FUN_00436170 @ 0x00436170 ===== */
void FUN_00436170(undefined4 param_1)



{

  int iVar1;

  

  iVar1 = *(int *)(DAT_00656544 + 0x1c);

  *(undefined4 *)(iVar1 + 8) = DAT_006565e4;

  *(undefined4 *)(iVar1 + 4) = 0x4033c;

  *(undefined4 *)(iVar1 + 0xc) = param_1;

  return;

}

/* ===== FUN_00436190 @ 0x00436190 ===== */
void FUN_00436190(undefined4 param_1,undefined4 param_2)



{

  dlog_entry_render_quads(DAT_00656544,param_1,param_2);

  return;

}

/* ===== editor_cursor_pick_point @ 0x00437FA0 ===== */
int editor_cursor_pick_point(int param_1)



{

  int iVar1;

  int iVar2;

  undefined4 *puVar3;

  int iVar4;

  float *pfVar5;

  undefined1 local_1c [4];

  float local_18;

  float local_14;

  undefined1 local_c [12];

  

  if (DAT_0059cbe4 != 0) {

    if (param_1 != 0) {

      iVar4 = project_cursor_to_object(&LAB_004380c0,0,0x460ca000,0);

      return iVar4;

    }

    iVar4 = project_cursor_to_object(0,0,0x460ca000,0);

    return iVar4;

  }

  project_cursor_to_ground(local_c,0x447a0000,local_1c);

  puVar3 = DAT_00632d68;

  do {

    if (puVar3 == (undefined4 *)0x0) {

      return 0;

    }

    iVar4 = puVar3[3];

    if ((((param_1 == 0) || ((*(uint *)(iVar4 + 0xdc) & 0x20000000) != 0)) &&

        (-1 < (char)((uint)*(undefined4 *)(iVar4 + 0xd8) >> 8))) &&

       (iVar1 = *(int *)(iVar4 + 8), iVar1 != 0)) {

      if ((*(int *)(iVar4 + 0x10) == 0xfe) ||

         (iVar2 = *(int *)(iVar1 + 8 + *(int *)(iVar4 + 0x10) * 4), pfVar5 = (float *)(iVar2 + 0xc),

         iVar2 == 0)) {

        pfVar5 = (float *)(*(int *)(iVar1 + 0x400) + 0x44);

      }

      xformobj_world_local(iVar4,local_c,&local_18);

      if (((local_18 <= pfVar5[3]) && (local_14 <= pfVar5[4])) &&

         ((*pfVar5 <= local_18 && (pfVar5[1] <= local_14)))) {

        return iVar4;

      }

    }

    puVar3 = (undefined4 *)*puVar3;

  } while( true );

}

/* ===== object_spawn_42 @ 0x004380E0 ===== */
int object_spawn_42(undefined4 param_1)



{

  int iVar1;

  undefined4 uVar2;

  int iVar3;

  

  uVar2 = param_1;

  iVar3 = object_allocate_type(param_1,0x80000000);

  project_cursor_to_ground(iVar3 + 0xa0,0x447a0000,&param_1);

  object_copy_posdirinfo(iVar3);

  *(uint *)(iVar3 + 0xdc) = *(uint *)(iVar3 + 0xdc) | 0x20000000;

  if (DAT_00632bd8 != 0) {

    *(uint *)(iVar3 + 0xd8) = *(uint *)(iVar3 + 0xd8) | 0x400;

  }

  if ((*(uint *)(iVar3 + 0x1c8) & 0x8000000) == 0) {

    iVar1 = *(int *)(iVar3 + 4);

    if (((iVar1 == 1099) || (iVar1 == 0x44c)) || (iVar1 == 0x44d)) {

      *(undefined4 *)(iVar3 + 0xe8) = 1;

      if (2.0 <= *(float *)(iVar3 + 0xa8)) {

        *(float *)(iVar3 + 0xa8) = *(float *)(iVar3 + 0xa8) + 2.0;

      }

      else {

        *(undefined4 *)(iVar3 + 0xa8) = 0x40000000;

      }

    }

    else {

      if (*(int *)(iVar3 + 0x1e0) != 0x3a) {

        DAT_0059cbdc = 1;

        DAT_0059cbf4 = uVar2;

        return iVar3;

      }

      if (0.0 <= *(float *)(iVar3 + 0xa8)) {

        DAT_0059cbdc = 1;

        DAT_0059cbf4 = uVar2;

        return iVar3;

      }

      *(undefined4 *)(iVar3 + 0xa8) = 0;

    }

    object_copy_posdirinfo(iVar3);

  }

  else {

    if (*(float *)(iVar3 + 0xa8) < 0.0) {

      *(undefined4 *)(iVar3 + 0xa8) = 0;

      object_copy_posdirinfo(iVar3);

    }

    if ((*(uint *)(iVar3 + 0x1c8) & 0x20000000) != 0) {

      if (*(int *)(iVar3 + 4) == 0x44a) {

        *(undefined4 *)(iVar3 + 0xfc) = 0x42700000;

      }

      else {

        *(undefined4 *)(iVar3 + 0xfc) = 0x41200000;

      }

    }

  }

  DAT_0059cbf4 = uVar2;

  DAT_0059cbdc = 1;

  return iVar3;

}

/* ===== main/editor_00438230 @ 0x00438230 ===== */
/* PS2 candidate: object_copy_posdirinfo (conf 0.842) */



void main_editor_00438230(int param_1,int param_2)



{

  *(undefined4 *)(param_2 + 4) = *(undefined4 *)(param_1 + 0xa0);

  *(undefined4 *)(param_2 + 8) = *(undefined4 *)(param_1 + 0xa4);

  *(undefined4 *)(param_2 + 0xc) = *(undefined4 *)(param_1 + 0xa8);

  *(undefined4 *)(param_2 + 0x10) = *(undefined4 *)(param_1 + 200);

  *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)(param_1 + 0xcc);

  *(undefined4 *)(param_2 + 0x18) = *(undefined4 *)(param_1 + 0xd0);

  *(undefined4 *)(param_2 + 0x1c) = *(undefined4 *)(param_1 + 0xc4);

  *(undefined4 *)(param_2 + 0x20) = *(undefined4 *)(param_1 + 0x1d4);

  *(undefined4 *)(param_2 + 0x2c) = *(undefined4 *)(param_1 + 0xe8);

  *(undefined4 *)(param_2 + 0x30) = *(undefined4 *)(param_1 + 0x174);

  *(undefined4 *)(param_2 + 0x24) = *(undefined4 *)(param_1 + 0xf8);

  *(undefined4 *)(param_2 + 0x28) = *(undefined4 *)(param_1 + 0xfc);

  *(undefined4 *)(param_2 + 0x34) = *(undefined4 *)(param_1 + 4);

  *(int *)(param_2 + 0x38) = param_1;

  return;

}

/* ===== main/editor_004382b0 @ 0x004382B0 ===== */
int main_editor_004382b0(int param_1,int param_2)



{

  if (*(int *)(param_1 + 4) != *(int *)(param_2 + 0x34)) {

    object_destroy(param_1);

    param_1 = object_spawn_42(*(undefined4 *)(param_2 + 0x34));

  }

  *(undefined4 *)(param_1 + 0xa0) = *(undefined4 *)(param_2 + 4);

  *(undefined4 *)(param_1 + 0xa4) = *(undefined4 *)(param_2 + 8);

  *(undefined4 *)(param_1 + 0xa8) = *(undefined4 *)(param_2 + 0xc);

  *(undefined4 *)(param_1 + 200) = *(undefined4 *)(param_2 + 0x10);

  *(undefined4 *)(param_1 + 0xcc) = *(undefined4 *)(param_2 + 0x14);

  *(undefined4 *)(param_1 + 0xd0) = *(undefined4 *)(param_2 + 0x18);

  *(undefined4 *)(param_1 + 0xc4) = *(undefined4 *)(param_2 + 0x1c);

  *(undefined4 *)(param_1 + 0x1d4) = *(undefined4 *)(param_2 + 0x20);

  *(undefined4 *)(param_1 + 0xe8) = *(undefined4 *)(param_2 + 0x2c);

  *(undefined4 *)(param_1 + 0x174) = *(undefined4 *)(param_2 + 0x30);

  *(undefined4 *)(param_1 + 0xf8) = *(undefined4 *)(param_2 + 0x24);

  *(undefined4 *)(param_1 + 0xfc) = *(undefined4 *)(param_2 + 0x28);

  object_copy_posdirinfo(param_1);

  return param_1;

}

/* ===== wredit_menu_main @ 0x00438770 ===== */
void wredit_menu_main(void)



{

  undefined *puVar1;

  int iVar2;

  undefined4 uVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  char *pcVar7;

  undefined1 *puVar8;

  undefined8 uVar9;

  undefined1 auStack_100 [256];

  

  wredit_004959c0();

  dlog_push_level(&LAB_00438ef0,&LAB_00438dd0);

  DAT_00632ab0 = 0;

  DAT_00632aad = 0;

  DAT_00632aaa = 0;

  wredit_00519c70();

  main_editor_00438350();

  switch(DAT_0059cc38) {

  case 0:

    DAT_0059cc3c = 0;

    if (DAT_0059cd4c != 0) {

      main_dlog_00427180();

    }

    DAT_0059cd4c = 0;

    DAT_0059cd4c = main_dlog_00427150();

    main_dlog_004273b0(DAT_0059cd4c,0,0x3f000000,0x3f800000,0x88000000,

                       s_World_Object_Editor_Menu_00557230);

    main_dlog_00427e80(DAT_0059cd4c,1,0x3f000000,0x40400000,0x88000022);

    uVar3 = DAT_0059cd4c;

    puVar1 = &DAT_0055722c;

    if (DAT_00632e74 == 0) {

      puVar1 = &DAT_00557228;

    }

    puVar8 = auStack_100;

    uVar9 = CONCAT44(puVar1,s_1__Mouse_Edit_Mode_is__s_0055720c);

    crt_sprintf();

    main_dlog_004281f0(uVar3,1,auStack_100,puVar8,uVar9);

    main_dlog_004281f0(DAT_0059cd4c,1,s_2__Create_Object_from_List_005571f0);

    wredit_00441580(DAT_0059cd4c,s_3__Orient_to_Ground_is__s_005571d4,DAT_0059cbe0);

    main_dlog_004281f0(DAT_0059cd4c,1,s_4__Save_Changes_to_World_File_005571b4);

    wredit_00441580(DAT_0059cd4c,s_5__Select_By_GroundLoc_is__s_00557194,DAT_0059cbe4 == 0);

    return;

  case 1:

    DAT_0059cd50 = main_dlog_00427150();

    if (DAT_0059cbd8 == 0) {

      pcVar7 = s_New_Object_Group_Selection_00557178;

    }

    else {

      pcVar7 = s_Modify_Object_Type___Group_0055715c;

    }

    main_dlog_004273b0(DAT_0059cd50,0,0x3f000000,0x3f800000,0x88000000,pcVar7);

    main_dlog_00427e80(DAT_0059cd50,1,0x3f000000,0x40400000,0x88000022);

    wredit_00428050(DAT_0059cd50,1,0x14);

    main_editor_00438350();

    iVar6 = 0;

    if (0 < DAT_0059cd38) {

      do {

        main_dlog_004281f0();

        iVar6 = iVar6 + 1;

      } while (iVar6 < DAT_0059cd38);

    }

    break;

  case 2:

    DAT_0059cd54 = main_dlog_00427150();

    crt_sprintf();

    main_dlog_00427890(DAT_0059cd54,0,0x3f000000,0x3f800000,0x88000000,auStack_100);

    main_dlog_00427e80(DAT_0059cd54,1,0x3f000000,0x40400000,0x88000032);

    wredit_00428050(DAT_0059cd54,1,0x14);

    iVar6 = 0;

    if (0 < DAT_0059cd34) {

      iVar5 = 0;

      do {

        iVar2 = object_find();

        if (*(byte *)(iVar2 + 0x1f6) == DAT_0059cd3c) {

          main_dlog_00428140(DAT_0059cd54,1,iVar5 + 4 + DAT_0059cd30,iVar6);

        }

        iVar6 = iVar6 + 1;

        iVar5 = iVar5 + 0x24;

      } while (iVar6 < DAT_0059cd34);

    }

    wredit_004284d0();

    break;

  case 3:

    wredit_obj_info();

    return;

  case 4:

    iVar6 = 0;

    DAT_0059cc3c = 0;

    if (DAT_0059cbd8 == 0) {

      wredit_00439490();

      return;

    }

    iVar5 = *(int *)(DAT_0059cbd8 + 0x38);

    DAT_0059cd5c = main_dlog_00427150();

    uVar3 = main_editor_0043aa00();

    crt_sprintf(auStack_100,s_Object_Locking_on__s_00557110,uVar3);

    main_dlog_00427890(DAT_0059cd5c,0,0x3f000000,0x3f800000,0x88000000,auStack_100);

    main_dlog_00427e80(DAT_0059cd5c,1,0x3f000000,0x40400000,0x88000022);

    iVar2 = *(int *)(iVar5 + 8);

    iVar4 = 0;

    if (0 < *(int *)(iVar2 + 0x450)) {

      do {

        if (*(int *)(*(int *)(iVar2 + 0x454) + iVar6 * 4) != 0) {

          iVar4 = iVar4 + 1;

          iVar2 = wredit_0043b500(iVar5,iVar6);

          if (iVar2 == 0) {

            uVar3 = wredit_0043b4d0(iVar5);

            pcVar7 = s__d____s____no_lock__005570e8;

          }

          else {

            uVar3 = main_editor_0043aa00();

            wredit_0043b4d0();

            uVar3 = wredit_0043b4d0(iVar5,iVar6,uVar3);

            pcVar7 = s__d____s____s____s_005570fc;

          }

          crt_sprintf(auStack_100,pcVar7,CONCAT44(uVar3,iVar4));

          main_dlog_00428140(DAT_0059cd5c);

        }

        iVar2 = *(int *)(iVar5 + 8);

        iVar6 = iVar6 + 1;

      } while (iVar6 < *(int *)(iVar2 + 0x450));

      if (iVar4 != 0) {

        return;

      }

    }

    main_dlog_00428140(DAT_0059cd5c,1,s__No_Reference_Points__005570d0,0xffffffff);

    return;

  case 5:

    wredit_flick_menu();

    return;

  case 6:

    wredit_lock_list();

    return;

  case 7:

    wredit_ai_menu();

    return;

  case 8:

    wredit_marker_menu_full();

    return;

  case 9:

    if (DAT_0059cbd8 != 0) {

      iVar6 = *(int *)(DAT_0059cbd8 + 0x38);

      DAT_0059cd70 = main_dlog_00427150();

      uVar3 = main_editor_0043aa00();

      crt_sprintf(auStack_100,s_Object_Type__d___s__005570bc,*(undefined4 *)(iVar6 + 4),uVar3);

      main_dlog_00427890(DAT_0059cd70,0,0x3f000000,0x40400000,0x88000000,auStack_100);

      crt_sprintf(auStack_100,s_Marker_Type_ID_Misc_Misc2____d___0055708c,

                  *(undefined4 *)(iVar6 + 0xe8),*(undefined4 *)(iVar6 + 0x174),

                  (double)*(float *)(iVar6 + 0xf8),(double)*(float *)(iVar6 + 0xfc));

      main_dlog_00427890(DAT_0059cd70,0,0x3f000000,0x40800000,0x88000000,auStack_100);

      crt_sprintf(&DAT_0059cd18,&DAT_00557088,*(undefined4 *)(iVar6 + 0x174));

      main_dlog_00427970(DAT_0059cd70,2,0x3f000000,0x40a00000,0x88000008,&DAT_0059cd18,0x10);

      return;

    }

    wredit_00439490();

    return;

  case 10:

    wredit_marker_info();

    return;

  case 0xb:

    wredit_marker_info2();

    return;

  case 0xc:

    wredit_trigger_menu();

    return;

  default:

    return;

  }

  DAT_0059cd08 = 0;

  DAT_0059cd28 = 0;

  return;

}

/* ===== wredit_00439490 @ 0x00439490 ===== */
void wredit_00439490(void)



{

  dialog_level_pop(&LAB_00438ef0);

  if (DAT_0059cd4c != 0) {

    main_dlog_00427180(DAT_0059cd4c);

  }

  DAT_0059cd4c = 0;

  if (DAT_0059cd50 != 0) {

    main_dlog_00427180(DAT_0059cd50);

  }

  DAT_0059cd50 = 0;

  if (DAT_0059cd54 != 0) {

    main_dlog_00427180(DAT_0059cd54);

  }

  DAT_0059cd54 = 0;

  if (DAT_0059cd58 != 0) {

    main_dlog_00427180(DAT_0059cd58);

  }

  DAT_0059cd58 = 0;

  if (DAT_0059cd5c != 0) {

    main_dlog_00427180(DAT_0059cd5c);

  }

  DAT_0059cd5c = 0;

  if (DAT_0059cd60 != 0) {

    main_dlog_00427180(DAT_0059cd60);

  }

  DAT_0059cd60 = 0;

  if (DAT_0059cd64 != 0) {

    main_dlog_00427180(DAT_0059cd64);

  }

  DAT_0059cd64 = 0;

  if (DAT_0059cd68 != 0) {

    main_dlog_00427180(DAT_0059cd68);

  }

  DAT_0059cd68 = 0;

  if (DAT_0059cd6c != 0) {

    main_dlog_00427180(DAT_0059cd6c);

  }

  DAT_0059cd6c = 0;

  if (DAT_0059cd70 != 0) {

    main_dlog_00427180(DAT_0059cd70);

  }

  DAT_0059cd70 = 0;

  if (DAT_0059cd74 != 0) {

    main_dlog_00427180(DAT_0059cd74);

  }

  DAT_0059cd74 = 0;

  if (DAT_0059cd78 != 0) {

    main_dlog_00427180(DAT_0059cd78);

  }

  DAT_0059cd78 = 0;

  if (DAT_0059cd7c != 0) {

    main_dlog_00427180(DAT_0059cd7c);

  }

  DAT_0059cd7c = 0;

  if (DAT_0059cd84 != 0) {

    main_dlog_00427180(DAT_0059cd84);

  }

  DAT_0059cd84 = 0;

  if (DAT_0059cd8c != 0) {

    main_dlog_00427180(DAT_0059cd8c);

  }

  DAT_0059cd8c = 0;

  if (DAT_0059cd80 != 0) {

    main_dlog_00427180(DAT_0059cd80);

  }

  DAT_0059cd80 = 0;

  if (DAT_0059cd88 != 0) {

    main_dlog_00427180(DAT_0059cd88);

  }

  DAT_0059cd88 = 0;

  if (DAT_0059cd90 != 0) {

    main_dlog_00427180(DAT_0059cd90);

  }

  DAT_0059cd90 = 0;

  FUN_004959d0();

  return;

}

/* ===== wredit_menu_draw @ 0x00439660 ===== */
void wredit_menu_draw(void)



{

  undefined4 uVar1;

  undefined *puVar2;

  undefined1 local_100 [256];

  

  DAT_0059cc3c = 0;

  if (DAT_0059cd4c != 0) {

    main_dlog_00427180(DAT_0059cd4c);

  }

  DAT_0059cd4c = 0;

  DAT_0059cd4c = main_dlog_00427150();

  main_dlog_004273b0(DAT_0059cd4c,0,0x3f000000,0x3f800000,0x88000000,

                     s_World_Object_Editor_Menu_00557230);

  main_dlog_00427e80(DAT_0059cd4c,1,0x3f000000,0x40400000,0x88000022);

  uVar1 = DAT_0059cd4c;

  puVar2 = &DAT_0055722c;

  if (DAT_00632e74 == 0) {

    puVar2 = &DAT_00557228;

  }

  crt_sprintf(local_100,s_1__Mouse_Edit_Mode_is__s_0055720c,puVar2);

  main_dlog_004281f0(uVar1,1,local_100);

  main_dlog_004281f0(DAT_0059cd4c,1,s_2__Create_Object_from_List_005571f0);

  uVar1 = DAT_0059cd4c;

  puVar2 = &DAT_0055722c;

  if (DAT_0059cbe0 == 0) {

    puVar2 = &DAT_00557228;

  }

  crt_sprintf(local_100,s_3__Orient_to_Ground_is__s_005571d4,puVar2);

  main_dlog_004281f0(uVar1,1,local_100);

  main_dlog_004281f0(DAT_0059cd4c,1,s_4__Save_Changes_to_World_File_005571b4);

  uVar1 = DAT_0059cd4c;

  puVar2 = &DAT_0055722c;

  if (DAT_0059cbe4 != 0) {

    puVar2 = &DAT_00557228;

  }

  crt_sprintf(local_100,s_5__Select_By_GroundLoc_is__s_00557194,puVar2);

  main_dlog_004281f0(uVar1,1,local_100);

  return;

}

/* ===== wredit_menu_3 @ 0x004397B0 ===== */
void wredit_menu_3(int param_1)



{

  undefined *puVar1;

  int iVar2;

  undefined4 uVar3;

  int iVar4;

  undefined4 uVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  char *pcVar9;

  undefined1 auStack_100 [256];

  

  iVar7 = 0;

  if (param_1 == 0) {

    param_1 = wredit_00428460(DAT_0059cd4c,1);

    param_1 = param_1 + 1;

  }

  wredit_00439490();

  switch(param_1) {

  case 1:

    DAT_00632e74 = (uint)(DAT_00632e74 == 0);

    break;

  case 2:

    DAT_0059cc38 = 1;

    wredit_004959c0();

    dlog_push_level(&LAB_00438ef0,&LAB_00438dd0);

    DAT_00632ab0 = 0;

    DAT_00632aad = 0;

    DAT_00632aaa = 0;

    wredit_00519c70();

    main_editor_00438350();

    switch(DAT_0059cc38) {

    case 0:

      DAT_0059cc3c = 0;

      if (DAT_0059cd4c != 0) {

        main_dlog_00427180(DAT_0059cd4c);

      }

      DAT_0059cd4c = 0;

      DAT_0059cd4c = main_dlog_00427150();

      main_dlog_004273b0(DAT_0059cd4c,0,0x3f000000,0x3f800000,0x88000000,

                         s_World_Object_Editor_Menu_00557230);

      main_dlog_00427e80(DAT_0059cd4c,1,0x3f000000,0x40400000,0x88000022);

      uVar3 = DAT_0059cd4c;

      puVar1 = &DAT_0055722c;

      if (DAT_00632e74 == 0) {

        puVar1 = &DAT_00557228;

      }

      crt_sprintf(auStack_100,s_1__Mouse_Edit_Mode_is__s_0055720c,puVar1);

      main_dlog_004281f0(uVar3,1,auStack_100);

      main_dlog_004281f0(DAT_0059cd4c,1,s_2__Create_Object_from_List_005571f0);

      wredit_00441580(DAT_0059cd4c,s_3__Orient_to_Ground_is__s_005571d4,DAT_0059cbe0);

      main_dlog_004281f0(DAT_0059cd4c,1,s_4__Save_Changes_to_World_File_005571b4);

      wredit_00441580(DAT_0059cd4c,s_5__Select_By_GroundLoc_is__s_00557194,DAT_0059cbe4 == 0);

      return;

    case 1:

      DAT_0059cd50 = main_dlog_00427150();

      if (DAT_0059cbd8 == 0) {

        pcVar9 = s_New_Object_Group_Selection_00557178;

      }

      else {

        pcVar9 = s_Modify_Object_Type___Group_0055715c;

      }

      main_dlog_004273b0(DAT_0059cd50,0,0x3f000000,0x3f800000,0x88000000,pcVar9);

      main_dlog_00427e80(DAT_0059cd50,1,0x3f000000,0x40400000,0x88000022);

      wredit_00428050(DAT_0059cd50,1,0x14);

      main_editor_00438350();

      iVar7 = 0;

      if (0 < DAT_0059cd38) {

        iVar4 = 0;

        do {

          main_dlog_004281f0(DAT_0059cd50,1,iVar4 + 4 + DAT_0059cd2c);

          iVar7 = iVar7 + 1;

          iVar4 = iVar4 + 0x24;

        } while (iVar7 < DAT_0059cd38);

      }

      DAT_0059cd28 = 0;

      DAT_0059cd08 = 0;

      return;

    case 2:

      DAT_0059cd54 = main_dlog_00427150();

      if (DAT_0059cbd8 == 0) {

        iVar4 = DAT_0059cd2c + 4 + DAT_0059cd3c * 0x24;

        pcVar9 = s_New_Object_of_Group__s_00557144;

      }

      else {

        iVar4 = DAT_0059cd2c + 4 + DAT_0059cd3c * 0x24;

        pcVar9 = s_Modify_Object_of_Group__s_00557128;

      }

      crt_sprintf(auStack_100,pcVar9,iVar4);

      main_dlog_00427890(DAT_0059cd54,0,0x3f000000,0x3f800000,0x88000000,auStack_100);

      main_dlog_00427e80(DAT_0059cd54,1,0x3f000000,0x40400000,0x88000032);

      wredit_00428050(DAT_0059cd54,1,0x14);

      iVar4 = 0;

      iVar6 = 0;

      if (0 < DAT_0059cd34) {

        iVar8 = 0;

        do {

          iVar2 = object_find(*(undefined4 *)(iVar8 + DAT_0059cd30));

          if (*(byte *)(iVar2 + 0x1f6) == DAT_0059cd3c) {

            main_dlog_00428140(DAT_0059cd54,1,iVar8 + 4 + DAT_0059cd30,iVar6);

            if (*(int *)(iVar8 + DAT_0059cd30) == DAT_0059cd40) {

              iVar7 = iVar4;

            }

            iVar4 = iVar4 + 1;

          }

          iVar6 = iVar6 + 1;

          iVar8 = iVar8 + 0x24;

        } while (iVar6 < DAT_0059cd34);

      }

      wredit_004284d0(DAT_0059cd54,1,iVar7);

      DAT_0059cd08 = 0;

      DAT_0059cd28 = 0;

      return;

    case 3:

      wredit_obj_info();

      return;

    case 4:

      goto switchD_00439858_caseD_4;

    case 5:

      wredit_flick_menu();

      return;

    case 6:

      wredit_lock_list();

      return;

    case 7:

      wredit_ai_menu();

      return;

    case 8:

      wredit_marker_menu_full();

      return;

    case 9:

      wredit_marker_info3();

      return;

    case 10:

      wredit_marker_info();

      return;

    case 0xb:

      wredit_marker_info2();

      return;

    case 0xc:

      wredit_trigger_menu();

      return;

    default:

      return;

    }

  case 3:

    DAT_0059cbe0 = (uint)(DAT_0059cbe0 == 0);

    break;

  case 4:

    main_editor_00440d90();

    break;

  case 5:

    DAT_0059cbe4 = (uint)(DAT_0059cbe4 == 0);

    break;

  default:

    goto switchD_004397eb_default;

  }

  dialog_level_pop(&LAB_00438ef0);

switchD_004397eb_default:

  return;

switchD_00439858_caseD_4:

  DAT_0059cc3c = 0;

  if (DAT_0059cbd8 == 0) {

    wredit_00439490();

    return;

  }

  iVar7 = *(int *)(DAT_0059cbd8 + 0x38);

  DAT_0059cd5c = main_dlog_00427150();

  uVar3 = main_editor_0043aa00(*(undefined4 *)(iVar7 + 4));

  crt_sprintf(auStack_100,s_Object_Locking_on__s_00557110,uVar3);

  main_dlog_00427890(DAT_0059cd5c,0,0x3f000000,0x3f800000,0x88000000,auStack_100);

  main_dlog_00427e80(DAT_0059cd5c,1,0x3f000000,0x40400000,0x88000022);

  iVar4 = *(int *)(iVar7 + 8);

  iVar6 = 0;

  iVar8 = 0;

  if (0 < *(int *)(iVar4 + 0x450)) {

    do {

      if (*(int *)(*(int *)(iVar4 + 0x454) + iVar8 * 4) != 0) {

        iVar6 = iVar6 + 1;

        iVar4 = wredit_0043b500(iVar7,iVar8);

        if (iVar4 == 0) {

          uVar3 = wredit_0043b4d0(iVar7,iVar8);

          pcVar9 = s__d____s____no_lock__005570e8;

        }

        else {

          uVar3 = main_editor_0043aa00(*(undefined4 *)(iVar4 + 4));

          uVar5 = wredit_0043b4d0(iVar4,*(undefined4 *)(iVar4 + 0x214));

          uVar3 = wredit_0043b4d0(iVar7,iVar8,uVar3,uVar5);

          pcVar9 = s__d____s____s____s_005570fc;

        }

        crt_sprintf(auStack_100,pcVar9,iVar6,uVar3);

        main_dlog_00428140(DAT_0059cd5c,1,auStack_100,iVar8);

      }

      iVar4 = *(int *)(iVar7 + 8);

      iVar8 = iVar8 + 1;

    } while (iVar8 < *(int *)(iVar4 + 0x450));

    if (iVar6 != 0) {

      return;

    }

  }

  main_dlog_00428140(DAT_0059cd5c,1,s__No_Reference_Points__005570d0,0xffffffff);

  return;

}

/* ===== wredit_group_select @ 0x00439DF0 ===== */
void wredit_group_select(void)



{

  int iVar1;

  int iVar2;

  char *pcVar3;

  

  DAT_0059cd50 = main_dlog_00427150();

  if (DAT_0059cbd8 == 0) {

    pcVar3 = s_New_Object_Group_Selection_00557178;

  }

  else {

    pcVar3 = s_Modify_Object_Type___Group_0055715c;

  }

  main_dlog_004273b0(DAT_0059cd50,0,0x3f000000,0x3f800000,0x88000000,pcVar3);

  main_dlog_00427e80(DAT_0059cd50,1,0x3f000000,0x40400000,0x88000022);

  wredit_00428050(DAT_0059cd50,1,0x14);

  main_editor_00438350();

  iVar1 = 0;

  if (0 < DAT_0059cd38) {

    iVar2 = 0;

    do {

      main_dlog_004281f0(DAT_0059cd50,1,iVar2 + 4 + DAT_0059cd2c);

      iVar1 = iVar1 + 1;

      iVar2 = iVar2 + 0x24;

    } while (iVar1 < DAT_0059cd38);

  }

  DAT_0059cd08 = 0;

  DAT_0059cd28 = 0;

  return;

}

/* ===== wredit_menu_4 @ 0x00439EB0 ===== */
void wredit_menu_4(void)



{

  undefined *puVar1;

  int iVar2;

  undefined4 uVar3;

  int iVar4;

  undefined4 uVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  char *pcVar9;

  undefined1 auStack_100 [256];

  

  DAT_0059cd3c = wredit_00428460(DAT_0059cd50,1);

  wredit_00439490();

  DAT_0059cc38 = 2;

  wredit_004959c0();

  dlog_push_level(&LAB_00438ef0,&LAB_00438dd0);

  DAT_00632ab0 = 0;

  DAT_00632aad = 0;

  DAT_00632aaa = 0;

  wredit_00519c70();

  main_editor_00438350();

  switch(DAT_0059cc38) {

  case 0:

    DAT_0059cc3c = 0;

    if (DAT_0059cd4c != 0) {

      main_dlog_00427180(DAT_0059cd4c);

    }

    DAT_0059cd4c = 0;

    DAT_0059cd4c = main_dlog_00427150();

    main_dlog_004273b0(DAT_0059cd4c,0,0x3f000000,0x3f800000,0x88000000,

                       s_World_Object_Editor_Menu_00557230);

    main_dlog_00427e80(DAT_0059cd4c,1,0x3f000000,0x40400000,0x88000022);

    uVar3 = DAT_0059cd4c;

    puVar1 = &DAT_0055722c;

    if (DAT_00632e74 == 0) {

      puVar1 = &DAT_00557228;

    }

    crt_sprintf(auStack_100,s_1__Mouse_Edit_Mode_is__s_0055720c,puVar1);

    main_dlog_004281f0(uVar3,1,auStack_100);

    main_dlog_004281f0(DAT_0059cd4c,1,s_2__Create_Object_from_List_005571f0);

    wredit_00441580(DAT_0059cd4c,s_3__Orient_to_Ground_is__s_005571d4,DAT_0059cbe0);

    main_dlog_004281f0(DAT_0059cd4c,1,s_4__Save_Changes_to_World_File_005571b4);

    wredit_00441580(DAT_0059cd4c,s_5__Select_By_GroundLoc_is__s_00557194,DAT_0059cbe4 == 0);

    return;

  case 1:

    DAT_0059cd50 = main_dlog_00427150();

    if (DAT_0059cbd8 == 0) {

      pcVar9 = s_New_Object_Group_Selection_00557178;

    }

    else {

      pcVar9 = s_Modify_Object_Type___Group_0055715c;

    }

    main_dlog_004273b0(DAT_0059cd50,0,0x3f000000,0x3f800000,0x88000000,pcVar9);

    main_dlog_00427e80(DAT_0059cd50,1,0x3f000000,0x40400000,0x88000022);

    wredit_00428050(DAT_0059cd50,1,0x14);

    main_editor_00438350();

    iVar8 = 0;

    if (0 < DAT_0059cd38) {

      iVar6 = 0;

      do {

        main_dlog_004281f0(DAT_0059cd50,1,iVar6 + 4 + DAT_0059cd2c);

        iVar8 = iVar8 + 1;

        iVar6 = iVar6 + 0x24;

      } while (iVar8 < DAT_0059cd38);

    }

    break;

  case 2:

    DAT_0059cd54 = main_dlog_00427150();

    if (DAT_0059cbd8 == 0) {

      iVar8 = DAT_0059cd2c + 4 + DAT_0059cd3c * 0x24;

      pcVar9 = s_New_Object_of_Group__s_00557144;

    }

    else {

      iVar8 = DAT_0059cd2c + 4 + DAT_0059cd3c * 0x24;

      pcVar9 = s_Modify_Object_of_Group__s_00557128;

    }

    crt_sprintf(auStack_100,pcVar9,iVar8);

    main_dlog_00427890(DAT_0059cd54,0,0x3f000000,0x3f800000,0x88000000,auStack_100);

    main_dlog_00427e80(DAT_0059cd54,1,0x3f000000,0x40400000,0x88000032);

    wredit_00428050(DAT_0059cd54,1,0x14);

    iVar8 = 0;

    iVar6 = 0;

    iVar4 = 0;

    if (0 < DAT_0059cd34) {

      iVar7 = 0;

      do {

        iVar2 = object_find(*(undefined4 *)(iVar7 + DAT_0059cd30));

        if (*(byte *)(iVar2 + 0x1f6) == DAT_0059cd3c) {

          main_dlog_00428140(DAT_0059cd54,1,iVar7 + 4 + DAT_0059cd30,iVar4);

          if (*(int *)(iVar7 + DAT_0059cd30) == DAT_0059cd40) {

            iVar8 = iVar6;

          }

          iVar6 = iVar6 + 1;

        }

        iVar4 = iVar4 + 1;

        iVar7 = iVar7 + 0x24;

      } while (iVar4 < DAT_0059cd34);

    }

    wredit_004284d0(DAT_0059cd54,1,iVar8);

    break;

  case 3:

    wredit_obj_info();

    return;

  case 4:

    iVar8 = 0;

    DAT_0059cc3c = 0;

    if (DAT_0059cbd8 == 0) {

      wredit_00439490();

      return;

    }

    iVar6 = *(int *)(DAT_0059cbd8 + 0x38);

    DAT_0059cd5c = main_dlog_00427150();

    uVar3 = main_editor_0043aa00(*(undefined4 *)(iVar6 + 4));

    crt_sprintf(auStack_100,s_Object_Locking_on__s_00557110,uVar3);

    main_dlog_00427890(DAT_0059cd5c,0,0x3f000000,0x3f800000,0x88000000,auStack_100);

    main_dlog_00427e80(DAT_0059cd5c,1,0x3f000000,0x40400000,0x88000022);

    iVar4 = *(int *)(iVar6 + 8);

    iVar7 = 0;

    if (0 < *(int *)(iVar4 + 0x450)) {

      do {

        if (*(int *)(*(int *)(iVar4 + 0x454) + iVar8 * 4) != 0) {

          iVar7 = iVar7 + 1;

          iVar4 = wredit_0043b500(iVar6,iVar8);

          if (iVar4 == 0) {

            uVar3 = wredit_0043b4d0(iVar6,iVar8);

            pcVar9 = s__d____s____no_lock__005570e8;

          }

          else {

            uVar3 = main_editor_0043aa00(*(undefined4 *)(iVar4 + 4));

            uVar5 = wredit_0043b4d0(iVar4,*(undefined4 *)(iVar4 + 0x214));

            uVar3 = wredit_0043b4d0(iVar6,iVar8,uVar3,uVar5);

            pcVar9 = s__d____s____s____s_005570fc;

          }

          crt_sprintf(auStack_100,pcVar9,iVar7,uVar3);

          main_dlog_00428140(DAT_0059cd5c,1,auStack_100,iVar8);

        }

        iVar4 = *(int *)(iVar6 + 8);

        iVar8 = iVar8 + 1;

      } while (iVar8 < *(int *)(iVar4 + 0x450));

      if (iVar7 != 0) {

        return;

      }

    }

    main_dlog_00428140(DAT_0059cd5c,1,s__No_Reference_Points__005570d0,0xffffffff);

    return;

  case 5:

    wredit_flick_menu();

    return;

  case 6:

    wredit_lock_list();

    return;

  case 7:

    wredit_ai_menu();

    return;

  case 8:

    wredit_marker_menu_full();

    return;

  case 9:

    wredit_marker_info3();

    return;

  case 10:

    wredit_marker_info();

    return;

  case 0xb:

    wredit_marker_info2();

    return;

  case 0xc:

    wredit_trigger_menu();

    return;

  default:

    return;

  }

  DAT_0059cd08 = 0;

  DAT_0059cd28 = 0;

  return;

}

/* ===== wredit_object_select @ 0x0043A440 ===== */
void wredit_object_select(void)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  char *pcVar6;

  undefined1 local_100 [256];

  

  DAT_0059cd54 = main_dlog_00427150();

  if (DAT_0059cbd8 == 0) {

    iVar2 = DAT_0059cd2c + 4 + DAT_0059cd3c * 0x24;

    pcVar6 = s_New_Object_of_Group__s_00557144;

  }

  else {

    iVar2 = DAT_0059cd2c + 4 + DAT_0059cd3c * 0x24;

    pcVar6 = s_Modify_Object_of_Group__s_00557128;

  }

  crt_sprintf(local_100,pcVar6,iVar2);

  main_dlog_00427890(DAT_0059cd54,0,0x3f000000,0x3f800000,0x88000000,local_100);

  main_dlog_00427e80(DAT_0059cd54,1,0x3f000000,0x40400000,0x88000032);

  wredit_00428050(DAT_0059cd54,1,0x14);

  iVar2 = 0;

  iVar3 = 0;

  if (0 < DAT_0059cd34) {

    iVar4 = 0;

    iVar5 = 0;

    do {

      iVar1 = object_find(*(undefined4 *)(iVar4 + DAT_0059cd30));

      if (*(byte *)(iVar1 + 0x1f6) == DAT_0059cd3c) {

        main_dlog_00428140(DAT_0059cd54,1,iVar4 + 4 + DAT_0059cd30,iVar5);

        if (*(int *)(iVar4 + DAT_0059cd30) == DAT_0059cd40) {

          iVar2 = iVar3;

        }

        iVar3 = iVar3 + 1;

      }

      iVar5 = iVar5 + 1;

      iVar4 = iVar4 + 0x24;

    } while (iVar5 < DAT_0059cd34);

  }

  wredit_004284d0(DAT_0059cd54,1,iVar2);

  DAT_0059cd08 = 0;

  DAT_0059cd28 = 0;

  return;

}

/* ===== main/editor_0043aa00 @ 0x0043AA00 ===== */
/* PS2 candidate: world_get_pointer_2 (conf 0.575) */



char * main_editor_0043aa00(int param_1)



{

  int iVar1;

  int *piVar2;

  

  main_editor_00438350();

  iVar1 = 0;

  piVar2 = DAT_0059cd30;

  if (0 < DAT_0059cd34) {

    do {

      if (*piVar2 == param_1) {

        return (char *)(DAT_0059cd30 + iVar1 * 9 + 1);

      }

      iVar1 = iVar1 + 1;

      piVar2 = piVar2 + 9;

    } while (iVar1 < DAT_0059cd34);

  }

  return s__unknown__0055724c;

}

/* ===== wredit_obj_info @ 0x0043AA40 ===== */
void wredit_obj_info(void)



{

  int iVar1;

  int iVar2;

  int iVar3;

  undefined4 uVar4;

  int *piVar5;

  char *pcVar6;

  undefined1 *puVar8;

  undefined8 uVar7;

  undefined8 uVar9;

  undefined4 uVar11;

  undefined8 uVar10;

  undefined1 auStack_108 [260];

  

  if (DAT_0059cbd8 == 0) {

    wredit_00439490();

    return;

  }

  iVar1 = *(int *)(DAT_0059cbd8 + 0x38);

  DAT_0059cd58 = main_dlog_00427150();

  main_dlog_004273b0(DAT_0059cd58,0,0x3f000000,0x3f800000,0x88000000,s_Object_Information_00557498);

  iVar2 = *(int *)(iVar1 + 4);

  main_editor_00438350();

  iVar3 = 0;

  piVar5 = DAT_0059cd30;

  if (0 < DAT_0059cd34) {

    do {

      if (*piVar5 == iVar2) {

        pcVar6 = (char *)(DAT_0059cd30 + iVar3 * 9 + 1);

        goto LAB_0043aac5;

      }

      iVar3 = iVar3 + 1;

      piVar5 = piVar5 + 9;

    } while (iVar3 < DAT_0059cd34);

  }

  pcVar6 = s__unknown__0055724c;

LAB_0043aac5:

  uVar11 = *(undefined4 *)(iVar1 + 0x1e0);

  uVar4 = FUN_0049a180();

  uVar10 = CONCAT44(uVar11,uVar4);

  uVar9 = CONCAT44(*(undefined4 *)(iVar1 + 0x1e0),pcVar6);

  puVar8 = auStack_108;

  uVar7 = CONCAT44(*(undefined4 *)(iVar1 + 4),s_Object_Type__d___s___MoveType__d_00557470);

  crt_sprintf();

  main_dlog_00427890(DAT_0059cd58,0,0x3f000000,0x40400000,0x88000000,auStack_108,puVar8,uVar7,uVar9,

                     uVar10);

  crt_sprintf(auStack_108,s_Location___1f___1f___1f_Directio_0055743c,

              (double)*(float *)(iVar1 + 0xa0),(double)*(float *)(iVar1 + 0xa4),

              (double)*(float *)(iVar1 + 0xa8),(double)*(float *)(iVar1 + 200),

              (double)*(float *)(iVar1 + 0xcc),(double)*(float *)(iVar1 + 0xd0));

  main_dlog_00427890(DAT_0059cd58,0,0x3f000000,0x40800000,0x88000000,auStack_108);

  crt_sprintf();

  main_dlog_00427890();

  if ((*(uint *)(iVar1 + 0xd8) & 0x400) == 0) {

    main_dlog_00427890(DAT_0059cd58,0,0x3f000000,0x40c00000,0x88000000,s_Not_Mission_Object_0055741c

                      );

  }

  else {

    mission_trigger_name();

    main_dlog_00427890();

  }

  main_dlog_00427e80();

  if (((*(uint *)(iVar1 + 0xd8) & 0x400) == 0) || (DAT_00632bd8 != 0)) {

    uVar7 = 0x55740c00000001;

    uVar11 = DAT_0059cd58;

    main_dlog_004281f0();

    main_dlog_004281f0(DAT_0059cd58,1,s_2__Flick_Use_edit_005573f8,uVar11,uVar7);

    if ((*(uint *)(iVar1 + 0x1c8) & 0x8000000) == 0) {

      main_dlog_004281f0();

      if ((DAT_00632bd8 != 0) && ((*(uint *)(iVar1 + 0xd8) & 0x400) != 0)) {

        crt_sprintf(auStack_108,s_4__Change_Mission_Trigger_00557258);

        main_dlog_004281f0();

      }

    }

    else {

      puVar8 = auStack_108;

      uVar7 = CONCAT44(*(undefined4 *)(iVar1 + 0xe8),s_3__Marker_Type____d_005573e4);

      crt_sprintf();

      main_dlog_004281f0(DAT_0059cd58,1,auStack_108,puVar8,uVar7);

      puVar8 = auStack_108;

      uVar7 = CONCAT44(*(undefined4 *)(iVar1 + 0x174),s_4__Marker_ID______d_005573d0);

      crt_sprintf();

      main_dlog_004281f0(DAT_0059cd58,1,auStack_108,puVar8,uVar7);

      if ((*(uint *)(iVar1 + 0x1c8) & 0x20000000) == 0) {

        crt_sprintf(auStack_108,s_5__Marker_Misc_Vimp_Herd_Radius___005572ac,

                    (double)*(float *)(iVar1 + 0xf8));

        main_dlog_004281f0();

        crt_sprintf(auStack_108,s_6__Marker_Misc2_Vimp_Wait_PCT_____00557284,

                    (double)*(float *)(iVar1 + 0xfc));

        uVar9 = CONCAT44(auStack_108,1);

        uVar11 = DAT_0059cd58;

        main_dlog_004281f0();

        puVar8 = auStack_108;

        uVar7 = CONCAT44(uVar11,s_7__Change_Mission_Trigger_00557370);

        crt_sprintf();

        main_dlog_004281f0(DAT_0059cd58,1,auStack_108,puVar8,uVar7,uVar9);

        return;

      }

      iVar2 = *(int *)(iVar1 + 0x100);

      if (*(int *)(iVar1 + 4) == 0x44a) {

        if (*(float *)(iVar1 + 0xf8) == 0.0) {

          uVar7 = CONCAT44(s_5__No_Buoy____Off_005573a8,auStack_108);

        }

        else {

          uVar7 = CONCAT44(s_5__No_Buoy____On_005573bc,auStack_108);

        }

        crt_sprintf(uVar7);

        main_dlog_004281f0();

        crt_sprintf(auStack_108,s_6__Buoy_Distance____8_3f_0055738c,(double)*(float *)(iVar1 + 0xfc)

                   );

        uVar9 = CONCAT44(auStack_108,1);

        uVar11 = DAT_0059cd58;

        main_dlog_004281f0();

        puVar8 = auStack_108;

        uVar7 = CONCAT44(uVar11,s_7__Change_Mission_Trigger_00557370);

        crt_sprintf();

        main_dlog_004281f0(DAT_0059cd58,1,auStack_108,puVar8,uVar7,uVar9);

        return;

      }

      crt_sprintf(auStack_108,s_5__Scan_Time____3_2f_00557358,(double)*(float *)(iVar1 + 0xf8));

      main_dlog_004281f0();

      crt_sprintf(auStack_108,s_6__Path_Speed____3_2f_00557340,(double)*(float *)(iVar1 + 0xfc));

      main_dlog_004281f0();

      if (*(int *)(iVar2 + 0x48) == 0) {

        uVar7 = CONCAT44(s_7__3D_Spline____Off_00557318,auStack_108);

      }

      else {

        uVar7 = CONCAT44(s_7__3D_Spline____On_0055732c,auStack_108);

      }

      crt_sprintf(uVar7);

      main_dlog_004281f0();

      if (*(int *)(iVar2 + 0x4c) == 0) {

        uVar7 = CONCAT44(s_8__Jet_pack____Off_005572f0,auStack_108);

      }

      else {

        uVar7 = CONCAT44(s_8__Jet_pack____On_00557304,auStack_108);

      }

      crt_sprintf(uVar7);

      main_dlog_004281f0();

      if ((DAT_00632bd8 != 0) && ((*(uint *)(iVar1 + 0xd8) & 0x400) != 0)) {

        crt_sprintf(auStack_108,s_9__Change_Mission_Trigger_005572d4);

        main_dlog_004281f0();

        return;

      }

    }

  }

  return;

}

/* ===== wredit_0043afa0 @ 0x0043AFA0 ===== */
void wredit_0043afa0(int param_1)



{

  int iVar1;

  

  iVar1 = *(int *)(DAT_0059cbd8 + 0x38);

  if (param_1 == 0) {

    param_1 = wredit_00428460(DAT_0059cd58,1);

    param_1 = param_1 + 1;

  }

  wredit_00439490();

  switch(param_1) {

  case 1:

    DAT_0059cc38 = 4;

    wredit_004959c0();

    dlog_push_level(&LAB_00438ef0,&LAB_00438dd0);

    DAT_00632ab0 = 0;

    DAT_00632aad = 0;

    DAT_00632aaa = 0;

    wredit_00519c70();

    main_editor_00438350();

    switch(DAT_0059cc38) {

    case 0:

switchD_0043b245_caseD_0:

      wredit_menu_draw();

      return;

    case 1:

switchD_0043b245_caseD_1:

      wredit_group_select();

      return;

    case 2:

switchD_0043b245_caseD_2:

      wredit_object_select();

      return;

    case 3:

switchD_0043b245_caseD_3:

      wredit_obj_info();

      return;

    case 4:

switchD_0043b245_caseD_4:

      wredit_lock_menu();

      return;

    case 5:

switchD_0043b245_caseD_5:

      wredit_flick_menu();

      return;

    case 6:

switchD_0043b245_caseD_6:

      wredit_lock_list();

      return;

    case 7:

switchD_0043b245_caseD_7:

      wredit_ai_menu();

      return;

    case 8:

switchD_0043b245_caseD_8:

      wredit_marker_menu_full();

      return;

    case 9:

switchD_0043b245_caseD_9:

      wredit_marker_info3();

      return;

    case 10:

switchD_0043b245_caseD_a:

      wredit_marker_info();

      return;

    case 0xb:

switchD_0043b245_caseD_b:

      wredit_marker_info2();

      return;

    case 0xc:

switchD_0043b245_caseD_c:

      wredit_trigger_menu();

      return;

    }

    break;

  case 2:

    DAT_0059cc38 = 5;

    wredit_004959c0();

    dlog_push_level(&LAB_00438ef0,&LAB_00438dd0);

    DAT_00632ab0 = 0;

    DAT_00632aad = 0;

    DAT_00632aaa = 0;

    wredit_00519c70();

    main_editor_00438350();

    switch(DAT_0059cc38) {

    case 0:

      goto switchD_0043b245_caseD_0;

    case 1:

      goto switchD_0043b245_caseD_1;

    case 2:

      goto switchD_0043b245_caseD_2;

    case 3:

      goto switchD_0043b245_caseD_3;

    case 4:

      goto switchD_0043b245_caseD_4;

    case 5:

      goto switchD_0043b245_caseD_5;

    case 6:

      goto switchD_0043b245_caseD_6;

    case 7:

      goto switchD_0043b245_caseD_7;

    case 8:

      goto switchD_0043b245_caseD_8;

    case 9:

      goto switchD_0043b245_caseD_9;

    case 10:

      goto switchD_0043b245_caseD_a;

    case 0xb:

      goto switchD_0043b245_caseD_b;

    case 0xc:

      goto switchD_0043b245_caseD_c;

    }

    break;

  case 3:

    DAT_0059cc38 = ((*(uint *)(iVar1 + 0x1c8) & 0x8000000) != 0) + 7;

    wredit_004959c0();

    dlog_push_level(&LAB_00438ef0,&LAB_00438dd0);

    DAT_00632ab0 = 0;

    DAT_00632aad = 0;

    DAT_00632aaa = 0;

    wredit_00519c70();

    main_editor_00438350();

    switch(DAT_0059cc38) {

    case 0:

      goto switchD_0043b245_caseD_0;

    case 1:

      goto switchD_0043b245_caseD_1;

    case 2:

      goto switchD_0043b245_caseD_2;

    case 3:

      goto switchD_0043b245_caseD_3;

    case 4:

      goto switchD_0043b245_caseD_4;

    case 5:

      goto switchD_0043b245_caseD_5;

    case 6:

      goto switchD_0043b245_caseD_6;

    case 7:

      goto switchD_0043b245_caseD_7;

    case 8:

      goto switchD_0043b245_caseD_8;

    case 9:

      goto switchD_0043b245_caseD_9;

    case 10:

      goto switchD_0043b245_caseD_a;

    case 0xb:

      goto switchD_0043b245_caseD_b;

    case 0xc:

      goto switchD_0043b245_caseD_c;

    }

    break;

  case 4:

    if ((*(uint *)(iVar1 + 0x1c8) & 0x8000000) == 0) {

      if (DAT_00632bd8 != 0) {

        DAT_0059cc38 = 0xc;

        wredit_004959c0();

        dlog_push_level(&LAB_00438ef0,&LAB_00438dd0);

        DAT_00632ab0 = 0;

        DAT_00632aad = 0;

        DAT_00632aaa = 0;

        wredit_00519c70();

        main_editor_00438350();

        switch(DAT_0059cc38) {

        case 0:

          goto switchD_0043b245_caseD_0;

        case 1:

          goto switchD_0043b245_caseD_1;

        case 2:

          goto switchD_0043b245_caseD_2;

        case 3:

          goto switchD_0043b245_caseD_3;

        case 4:

          goto switchD_0043b245_caseD_4;

        case 5:

          goto switchD_0043b245_caseD_5;

        case 6:

          goto switchD_0043b245_caseD_6;

        case 7:

          goto switchD_0043b245_caseD_7;

        case 8:

          goto switchD_0043b245_caseD_8;

        case 9:

          goto switchD_0043b245_caseD_9;

        case 10:

          goto switchD_0043b245_caseD_a;

        case 0xb:

          goto switchD_0043b245_caseD_b;

        case 0xc:

          goto switchD_0043b245_caseD_c;

        }

      }

    }

    else {

      DAT_0059cc38 = 9;

      wredit_004959c0();

      dlog_push_level(&LAB_00438ef0,&LAB_00438dd0);

      DAT_00632ab0 = 0;

      DAT_00632aad = 0;

      DAT_00632aaa = 0;

      wredit_00519c70();

      main_editor_00438350();

      switch(DAT_0059cc38) {

      case 0:

        goto switchD_0043b245_caseD_0;

      case 1:

        goto switchD_0043b245_caseD_1;

      case 2:

        goto switchD_0043b245_caseD_2;

      case 3:

        goto switchD_0043b245_caseD_3;

      case 4:

        goto switchD_0043b245_caseD_4;

      case 5:

        goto switchD_0043b245_caseD_5;

      case 6:

        goto switchD_0043b245_caseD_6;

      case 7:

        goto switchD_0043b245_caseD_7;

      case 8:

        goto switchD_0043b245_caseD_8;

      case 9:

        goto switchD_0043b245_caseD_9;

      case 10:

        goto switchD_0043b245_caseD_a;

      case 0xb:

        goto switchD_0043b245_caseD_b;

      case 0xc:

        goto switchD_0043b245_caseD_c;

      }

    }

    break;

  case 5:

    if ((*(uint *)(iVar1 + 0x1c8) & 0x8000000) != 0) {

      if (*(int *)(iVar1 + 4) == 0x44a) {

        if (*(float *)(iVar1 + 0xf8) != 0.0) {

          *(undefined4 *)(iVar1 + 0xf8) = 0;

          marker_spline_adjust_buoy(iVar1);

          return;

        }

        *(undefined4 *)(iVar1 + 0xf8) = 0x3f800000;

        marker_spline_adjust_buoy(iVar1);

        return;

      }

      DAT_0059cc38 = 10;

      wredit_004959c0();

      dlog_push_level(&LAB_00438ef0,&LAB_00438dd0);

      DAT_00632ab0 = 0;

      DAT_00632aad = 0;

      DAT_00632aaa = 0;

      wredit_00519c70();

      main_editor_00438350();

      switch(DAT_0059cc38) {

      case 0:

        goto switchD_0043b245_caseD_0;

      case 1:

        goto switchD_0043b245_caseD_1;

      case 2:

        goto switchD_0043b245_caseD_2;

      case 3:

        goto switchD_0043b245_caseD_3;

      case 4:

        goto switchD_0043b245_caseD_4;

      case 5:

        goto switchD_0043b245_caseD_5;

      case 6:

        goto switchD_0043b245_caseD_6;

      case 7:

        goto switchD_0043b245_caseD_7;

      case 8:

        goto switchD_0043b245_caseD_8;

      case 9:

        goto switchD_0043b245_caseD_9;

      case 10:

        goto switchD_0043b245_caseD_a;

      case 0xb:

        goto switchD_0043b245_caseD_b;

      case 0xc:

        goto switchD_0043b245_caseD_c;

      }

    }

    break;

  case 6:

    if ((*(uint *)(iVar1 + 0x1c8) & 0x8000000) == 0) {

      return;

    }

    DAT_0059cc38 = 0xb;

    if (*(int *)(iVar1 + 4) == 0x44a) {

      wredit_menu_main();

      return;

    }

    goto LAB_0043b360;

  case 7:

    if (((*(uint *)(iVar1 + 0x1c8) & 0x20000000) != 0) && (*(int *)(iVar1 + 4) != 0x44a)) {

      *(uint *)(*(int *)(iVar1 + 0x100) + 0x48) =

           (uint)(*(int *)(*(int *)(iVar1 + 0x100) + 0x48) == 0);

      if ((*(uint *)(iVar1 + 0x1c8) & 0x20000000) == 0) {

        return;

      }

      formation_update_info(iVar1);

      return;

    }

  case 9:

switchD_0043afda_caseD_9:

    if (DAT_00632bd8 != 0) {

      DAT_0059cc38 = 0xc;

LAB_0043b360:

      wredit_menu_main();

      return;

    }

    break;

  case 8:

    if ((*(uint *)(iVar1 + 0x1c8) & 0x20000000) != 0) {

      *(uint *)(*(int *)(iVar1 + 0x100) + 0x4c) =

           (uint)(*(int *)(*(int *)(iVar1 + 0x100) + 0x4c) == 0);

      formation_update_info(iVar1);

      return;

    }

    goto switchD_0043afda_caseD_9;

  }

  return;

}

/* ===== wredit_0043b4d0 @ 0x0043B4D0 ===== */
char * wredit_0043b4d0(int param_1,int param_2)



{

  if ((param_2 != 0xff) && (-1 < param_2)) {

    return *(char **)(*(int *)(*(int *)(param_1 + 8) + 0x454) + param_2 * 4);

  }

  return s__0_0_0__005574ac;

}

/* ===== wredit_0043b500 @ 0x0043B500 ===== */
int wredit_0043b500(int param_1,int param_2)



{

  int iVar1;

  undefined4 *puVar2;

  

  puVar2 = DAT_00632d68;

  while( true ) {

    if (puVar2 == (undefined4 *)0x0) {

      return 0;

    }

    iVar1 = puVar2[3];

    if ((*(int *)(iVar1 + 0x210) == param_1) && (*(int *)(iVar1 + 0x218) == param_2)) break;

    puVar2 = (undefined4 *)*puVar2;

  }

  return iVar1;

}

/* ===== wredit_lock_menu @ 0x0043B530 ===== */
void wredit_lock_menu(void)



{

  int iVar1;

  undefined4 *puVar2;

  int iVar3;

  int iVar4;

  char *pcVar5;

  int iVar6;

  int iVar7;

  char *pcVar8;

  int *piVar9;

  char *pcVar10;

  int iVar11;

  undefined1 local_c8 [200];

  

  iVar11 = 0;

  DAT_0059cc3c = 0;

  if (DAT_0059cbd8 == 0) {

    wredit_00439490();

    return;

  }

  iVar1 = *(int *)(DAT_0059cbd8 + 0x38);

  DAT_0059cd5c = main_dlog_00427150();

  iVar6 = *(int *)(iVar1 + 4);

  main_editor_00438350();

  iVar4 = 0;

  piVar9 = DAT_0059cd30;

  if (0 < DAT_0059cd34) {

    do {

      if (*piVar9 == iVar6) {

        pcVar5 = (char *)(DAT_0059cd30 + iVar4 * 9 + 1);

        goto LAB_0043b59c;

      }

      iVar4 = iVar4 + 1;

      piVar9 = piVar9 + 9;

    } while (iVar4 < DAT_0059cd34);

  }

  pcVar5 = s__unknown__0055724c;

LAB_0043b59c:

  crt_sprintf(local_c8,s_Object_Locking_on__s_00557110,pcVar5);

  main_dlog_00427890(DAT_0059cd5c,0,0x3f000000,0x3f800000,0x88000000,local_c8);

  main_dlog_00427e80(DAT_0059cd5c,1,0x3f000000,0x40400000,0x88000022);

  iVar6 = *(int *)(iVar1 + 8);

  iVar4 = 0;

  if (0 < *(int *)(iVar6 + 0x450)) {

LAB_0043b600:

    pcVar5 = *(char **)(*(int *)(iVar6 + 0x454) + iVar11 * 4);

    if (pcVar5 != (char *)0x0) {

      iVar4 = iVar4 + 1;

      for (puVar2 = DAT_00632d68; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {

        iVar6 = puVar2[3];

        if ((*(int *)(iVar6 + 0x210) == iVar1) && (*(int *)(iVar6 + 0x218) == iVar11)) {

          iVar3 = *(int *)(iVar6 + 4);

          main_editor_00438350();

          iVar7 = 0;

          piVar9 = DAT_0059cd30;

          if (0 < DAT_0059cd34) goto LAB_0043b670;

          goto LAB_0043b680;

        }

      }

      if ((iVar11 == 0xff) || (iVar11 < 0)) {

        pcVar5 = s__0_0_0__005574ac;

      }

      crt_sprintf(local_c8,s__d____s____no_lock__005570e8,iVar4,pcVar5);

      goto LAB_0043b71c;

    }

    goto LAB_0043b732;

  }

LAB_0043b748:

  main_dlog_00428140(DAT_0059cd5c,1,s__No_Reference_Points__005570d0,0xffffffff);

  return;

  while( true ) {

    iVar7 = iVar7 + 1;

    piVar9 = piVar9 + 9;

    if (DAT_0059cd34 <= iVar7) break;

LAB_0043b670:

    if (*piVar9 == iVar3) {

      pcVar5 = (char *)(DAT_0059cd30 + iVar7 * 9 + 1);

      goto LAB_0043b685;

    }

  }

LAB_0043b680:

  pcVar5 = s__unknown__0055724c;

LAB_0043b685:

  iVar3 = *(int *)(iVar6 + 0x214);

  if ((iVar3 == 0xff) || (iVar3 < 0)) {

    pcVar8 = s__0_0_0__005574ac;

  }

  else {

    pcVar8 = *(char **)(*(int *)(*(int *)(iVar6 + 8) + 0x454) + iVar3 * 4);

  }

  if ((iVar11 == 0xff) || (iVar11 < 0)) {

    pcVar10 = s__0_0_0__005574ac;

  }

  else {

    pcVar10 = *(char **)(*(int *)(*(int *)(iVar1 + 8) + 0x454) + iVar11 * 4);

  }

  crt_sprintf(local_c8,s__d____s____s____s_005570fc,iVar4,pcVar10,pcVar5,pcVar8);

LAB_0043b71c:

  main_dlog_00428140(DAT_0059cd5c,1,local_c8,iVar11);

LAB_0043b732:

  iVar6 = *(int *)(iVar1 + 8);

  iVar11 = iVar11 + 1;

  if (*(int *)(iVar6 + 0x450) <= iVar11) goto code_r0x0043b744;

  goto LAB_0043b600;

code_r0x0043b744:

  if (iVar4 != 0) {

    return;

  }

  goto LAB_0043b748;

}

/* ===== wredit_menu_5 @ 0x0043B770 ===== */
void wredit_menu_5(int param_1)



{

  undefined *puVar1;

  int iVar2;

  undefined4 uVar3;

  int *piVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  char *pcVar9;

  undefined1 auStack_100 [256];

  

  iVar8 = 0;

  if (param_1 == 0) {

    param_1 = wredit_00428460(DAT_0059cd5c,1);

    param_1 = param_1 + 1;

  }

  DAT_0059cc34 = wredit_00428670(DAT_0059cd5c,1,param_1 + -1);

  if (-1 < DAT_0059cc34) {

    if (DAT_00632d68 != (int *)0x0) {

      piVar4 = DAT_00632d68;

      do {

        iVar5 = piVar4[3];

        if ((*(int *)(iVar5 + 0x210) == *(int *)(DAT_0059cbd8 + 0x38)) &&

           (*(int *)(iVar5 + 0x218) == DAT_0059cc34)) {

          DAT_0059cd3c = (uint)*(byte *)(iVar5 + 0x1f6);

          DAT_0059cd40 = *(int *)(iVar5 + 4);

          break;

        }

        piVar4 = (int *)*piVar4;

      } while (piVar4 != (int *)0x0);

    }

    wredit_00439490();

    DAT_0059cc38 = 2;

    wredit_004959c0();

    dlog_push_level(&LAB_00438ef0,&LAB_00438dd0);

    DAT_00632ab0 = 0;

    DAT_00632aad = 0;

    DAT_00632aaa = 0;

    wredit_00519c70();

    main_editor_00438350();

    switch(DAT_0059cc38) {

    case 0:

      DAT_0059cc3c = 0;

      if (DAT_0059cd4c != 0) {

        main_dlog_00427180(DAT_0059cd4c);

      }

      DAT_0059cd4c = 0;

      DAT_0059cd4c = main_dlog_00427150();

      main_dlog_004273b0(DAT_0059cd4c,0,0x3f000000,0x3f800000,0x88000000,

                         s_World_Object_Editor_Menu_00557230);

      main_dlog_00427e80(DAT_0059cd4c,1,0x3f000000,0x40400000,0x88000022);

      iVar8 = DAT_0059cd4c;

      puVar1 = &DAT_0055722c;

      if (DAT_00632e74 == 0) {

        puVar1 = &DAT_00557228;

      }

      crt_sprintf(auStack_100,s_1__Mouse_Edit_Mode_is__s_0055720c,puVar1);

      main_dlog_004281f0(iVar8,1,auStack_100);

      main_dlog_004281f0(DAT_0059cd4c,1,s_2__Create_Object_from_List_005571f0);

      wredit_00441580(DAT_0059cd4c,s_3__Orient_to_Ground_is__s_005571d4,DAT_0059cbe0);

      main_dlog_004281f0(DAT_0059cd4c,1,s_4__Save_Changes_to_World_File_005571b4);

      wredit_00441580(DAT_0059cd4c,s_5__Select_By_GroundLoc_is__s_00557194,DAT_0059cbe4 == 0);

      break;

    case 1:

      DAT_0059cd50 = main_dlog_00427150();

      if (DAT_0059cbd8 == 0) {

        pcVar9 = s_New_Object_Group_Selection_00557178;

      }

      else {

        pcVar9 = s_Modify_Object_Type___Group_0055715c;

      }

      main_dlog_004273b0(DAT_0059cd50,0,0x3f000000,0x3f800000,0x88000000,pcVar9);

      main_dlog_00427e80(DAT_0059cd50,1,0x3f000000,0x40400000,0x88000022);

      wredit_00428050(DAT_0059cd50,1,0x14);

      main_editor_00438350();

      iVar5 = 0;

      if (0 < DAT_0059cd38) {

        do {

          main_dlog_004281f0(DAT_0059cd50,1,iVar8 + 4 + DAT_0059cd2c);

          iVar5 = iVar5 + 1;

          iVar8 = iVar8 + 0x24;

        } while (iVar5 < DAT_0059cd38);

      }

      DAT_0059cd08 = 0;

      DAT_0059cd28 = 0;

      break;

    case 2:

      DAT_0059cd54 = main_dlog_00427150();

      if (DAT_0059cbd8 == 0) {

        iVar5 = DAT_0059cd2c + 4 + DAT_0059cd3c * 0x24;

        pcVar9 = s_New_Object_of_Group__s_00557144;

      }

      else {

        iVar5 = DAT_0059cd2c + 4 + DAT_0059cd3c * 0x24;

        pcVar9 = s_Modify_Object_of_Group__s_00557128;

      }

      crt_sprintf(auStack_100,pcVar9,iVar5);

      main_dlog_00427890(DAT_0059cd54,0,0x3f000000,0x3f800000,0x88000000,auStack_100);

      main_dlog_00427e80(DAT_0059cd54,1,0x3f000000,0x40400000,0x88000032);

      wredit_00428050(DAT_0059cd54,1,0x14);

      iVar5 = 0;

      iVar6 = 0;

      if (0 < DAT_0059cd34) {

        iVar7 = 0;

        do {

          iVar2 = object_find(*(undefined4 *)(iVar7 + DAT_0059cd30));

          if (*(byte *)(iVar2 + 0x1f6) == DAT_0059cd3c) {

            main_dlog_00428140(DAT_0059cd54,1,iVar7 + 4 + DAT_0059cd30,iVar8);

            if (*(int *)(iVar7 + DAT_0059cd30) == DAT_0059cd40) {

              iVar5 = iVar6;

            }

            iVar6 = iVar6 + 1;

          }

          iVar8 = iVar8 + 1;

          iVar7 = iVar7 + 0x24;

        } while (iVar8 < DAT_0059cd34);

      }

      wredit_004284d0(DAT_0059cd54,1,iVar5);

      DAT_0059cd08 = 0;

      DAT_0059cd28 = 0;

      break;

    case 3:

      wredit_obj_info();

      break;

    case 4:

      wredit_lock_menu();

      break;

    case 5:

      if (DAT_0059cbd8 == 0) {

        wredit_00439490();

      }

      else {

        iVar5 = *(int *)(DAT_0059cbd8 + 0x38);

        DAT_0059cd60 = main_dlog_00427150();

        uVar3 = main_editor_0043aa00(*(undefined4 *)(iVar5 + 4));

        crt_sprintf(auStack_100,s_Flick_exclusions_on_Object__s_005574cc,uVar3);

        main_dlog_00427890(DAT_0059cd60,0,0x3f000000,0x3f800000,0x88000000,auStack_100);

        main_dlog_00427e80(DAT_0059cd60,1,0x3f000000,0x40400000,0x88000022);

        wredit_00428050(DAT_0059cd60,1,0x14);

        iVar6 = 0;

        iVar7 = 0;

        do {

          if (*(char *)(iVar8 + 0x210 + DAT_006330e4) != '\0') {

            iVar6 = iVar6 + 1;

            wredit_flick_list2(iVar5,iVar6,iVar7,auStack_100);

            main_dlog_00428140(DAT_0059cd60,1,auStack_100,iVar7);

          }

          iVar8 = iVar8 + 0x20;

          iVar7 = iVar7 + 1;

        } while (iVar8 < 0x1000);

        if (iVar6 == 0) {

          main_dlog_00428140(DAT_0059cd60,1,s__No_Flicks_for_World__005574b4,0xffffffff);

        }

      }

      break;

    case 6:

      wredit_lock_list();

      break;

    case 7:

      wredit_ai_menu();

      break;

    case 8:

      wredit_marker_menu_full();

      break;

    case 9:

      wredit_marker_info3();

      break;

    case 10:

      wredit_marker_info();

      break;

    case 0xb:

      wredit_marker_info2();

      break;

    case 0xc:

      wredit_trigger_menu();

    }

    DAT_0059cc3c = 4;

  }

  return;

}

/* ===== wredit_flick_list2 @ 0x0043BCC0 ===== */
void wredit_flick_list2(int param_1,undefined4 param_2,int param_3,undefined4 param_4)



{

  uint uVar1;

  byte bVar2;

  uint uVar3;

  

  bVar2 = (byte)param_3;

  if (param_3 < 0x20) {

    uVar1 = *(uint *)(param_1 + 0x2e8);

    uVar3 = 1 << (bVar2 & 0x1f);

  }

  else if (param_3 < 0x40) {

    uVar1 = 1 << (bVar2 - 0x20 & 0x1f);

    uVar3 = *(uint *)(param_1 + 0x2ec);

  }

  else {

    if (param_3 < 0x60) {

      bVar2 = bVar2 - 0x40;

    }

    else {

      if (0x7f < param_3) goto LAB_0043bd4f;

      bVar2 = bVar2 + 0xa0;

    }

    uVar1 = 1 << (bVar2 & 0x1f);

    uVar3 = *(uint *)(param_1 + 0x2f0);

  }

  if ((uVar1 & uVar3) != 0) {

    crt_sprintf(param_4,s__d___Out____s_005574fc,param_2,param_3 * 0x20 + 0x210 + DAT_006330e4);

    return;

  }

LAB_0043bd4f:

  crt_sprintf(param_4,s__d___In____s_005574ec,param_2,param_3 * 0x20 + 0x210 + DAT_006330e4);

  return;

}

/* ===== wredit_flick_menu @ 0x0043BD80 ===== */
void wredit_flick_menu(void)



{

  int iVar1;

  int iVar2;

  char *pcVar3;

  uint uVar4;

  uint uVar5;

  byte bVar6;

  int *piVar7;

  int iVar8;

  int iVar9;

  char *pcVar10;

  undefined1 local_c8 [200];

  

  if (DAT_0059cbd8 == 0) {

    wredit_00439490();

    return;

  }

  iVar1 = *(int *)(DAT_0059cbd8 + 0x38);

  DAT_0059cd60 = main_dlog_00427150();

  iVar8 = *(int *)(iVar1 + 4);

  main_editor_00438350();

  iVar2 = 0;

  piVar7 = DAT_0059cd30;

  if (0 < DAT_0059cd34) {

    do {

      if (*piVar7 == iVar8) {

        pcVar3 = (char *)(DAT_0059cd30 + iVar2 * 9 + 1);

        goto LAB_0043bddc;

      }

      iVar2 = iVar2 + 1;

      piVar7 = piVar7 + 9;

    } while (iVar2 < DAT_0059cd34);

  }

  pcVar3 = s__unknown__0055724c;

LAB_0043bddc:

  crt_sprintf(local_c8,s_Flick_exclusions_on_Object__s_005574cc,pcVar3);

  main_dlog_00427890(DAT_0059cd60,0,0x3f000000,0x3f800000,0x88000000,local_c8);

  main_dlog_00427e80(DAT_0059cd60,1,0x3f000000,0x40400000,0x88000022);

  wredit_00428050(DAT_0059cd60,1,0x14);

  iVar8 = 0;

  iVar2 = 0;

  iVar9 = 0;

  do {

    pcVar3 = (char *)(iVar9 + 0x210 + DAT_006330e4);

    if (*pcVar3 != '\0') {

      iVar8 = iVar8 + 1;

      bVar6 = (byte)iVar2;

      if (iVar9 < 0x400) {

        uVar4 = 1 << (bVar6 & 0x1f);

        uVar5 = *(uint *)(iVar1 + 0x2e8);

LAB_0043bebf:

        if ((uVar5 & uVar4) == 0) goto LAB_0043bed3;

        pcVar10 = s__d___Out____s_005574fc;

      }

      else {

        if (iVar9 < 0x800) {

          uVar5 = 1 << (bVar6 - 0x20 & 0x1f);

          uVar4 = *(uint *)(iVar1 + 0x2ec);

          goto LAB_0043bebf;

        }

        if (iVar9 < 0xc00) {

          bVar6 = bVar6 - 0x40;

LAB_0043beb2:

          uVar5 = 1 << (bVar6 & 0x1f);

          uVar4 = *(uint *)(iVar1 + 0x2f0);

          goto LAB_0043bebf;

        }

        if (iVar9 < 0x1000) {

          bVar6 = bVar6 + 0xa0;

          goto LAB_0043beb2;

        }

LAB_0043bed3:

        pcVar10 = s__d___In____s_005574ec;

      }

      crt_sprintf(local_c8,pcVar10,iVar8,pcVar3);

      main_dlog_00428140(DAT_0059cd60,1,local_c8,iVar2);

    }

    iVar9 = iVar9 + 0x20;

    iVar2 = iVar2 + 1;

    if (0xfff < iVar9) {

      if (iVar8 == 0) {

        main_dlog_00428140(DAT_0059cd60,1,s__No_Flicks_for_World__005574b4,0xffffffff);

      }

      return;

    }

  } while( true );

}

/* ===== wredit_flick_list @ 0x0043BF40 ===== */
void wredit_flick_list(void)



{

  char cVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  byte bVar5;

  byte bVar6;

  uint uVar7;

  uint uVar8;

  char *pcVar9;

  undefined1 local_c8 [200];

  

  dlog_list_navigate_sound(DAT_0059cd60);

  if ((DAT_00632aa4._3_1_ != '\0') || (DAT_00632aad != '\0')) {

    wredit_00439490();

    DAT_0059cc38 = 3;

    wredit_004959c0();

    dlog_push_level(&LAB_00438ef0,&LAB_00438dd0);

    DAT_00632ab0 = 0;

    DAT_00632aad = 0;

    DAT_00632aaa = 0;

    wredit_00519c70();

    main_editor_00438350();

    switch(DAT_0059cc38) {

    case 0:

      goto switchD_0043c260_caseD_0;

    case 1:

      wredit_group_select();

      return;

    case 2:

      wredit_object_select();

      return;

    case 3:

      wredit_obj_info();

      return;

    case 4:

      wredit_lock_menu();

      return;

    case 5:

      wredit_flick_menu();

      return;

    case 6:

      wredit_lock_list();

      return;

    case 7:

      wredit_ai_menu();

      return;

    case 8:

      wredit_marker_menu_full();

      return;

    case 9:

      wredit_marker_info3();

      return;

    case 10:

      wredit_marker_info();

      return;

    case 0xb:

      wredit_marker_info2();

      return;

    case 0xc:

      wredit_trigger_menu();

      return;

    default:

      return;

    }

  }

  if (DAT_00632aa8 == '\0') {

    if ((DAT_00632aaa == '\0') || (iVar3 = main_dlog_00427310(DAT_0059cd60), iVar3 != 1))

    goto LAB_0043c17b;

    iVar3 = wredit_00428460(DAT_0059cd60,1);

    iVar4 = wredit_00428670(DAT_0059cd60,1,iVar3);

    if (iVar4 < 0) goto LAB_0043c17b;

    iVar2 = *(int *)(DAT_0059cbd8 + 0x38);

    bVar6 = (byte)iVar4;

    if (iVar4 < 0x20) {

      *(uint *)(iVar2 + 0x2e8) = *(uint *)(iVar2 + 0x2e8) ^ 1 << (bVar6 & 0x1f);

    }

    else if (iVar4 < 0x40) {

      *(uint *)(iVar2 + 0x2ec) = *(uint *)(iVar2 + 0x2ec) ^ 1 << (bVar6 - 0x20 & 0x1f);

    }

    else {

      if (iVar4 < 0x60) {

        bVar6 = bVar6 - 0x40;

      }

      else {

        if (0x7f < iVar4) goto LAB_0043c158;

        bVar6 = bVar6 + 0xa0;

      }

      *(uint *)(iVar2 + 0x2f0) = *(uint *)(iVar2 + 0x2f0) ^ 1 << (bVar6 & 0x1f);

    }

LAB_0043c158:

    wredit_flick_list2(iVar2,iVar3 + 1,iVar4,local_c8);

    main_dlog_004286c0(DAT_0059cd60,1,iVar3,local_c8);

    goto LAB_0043c17b;

  }

  iVar3 = wredit_00428460(DAT_0059cd60,1);

  iVar4 = wredit_00428670(DAT_0059cd60,1,iVar3);

  if (iVar4 < 0) goto LAB_0043c17b;

  iVar2 = *(int *)(DAT_0059cbd8 + 0x38);

  bVar6 = (byte)iVar4;

  if (iVar4 < 0x20) {

    *(uint *)(iVar2 + 0x2e8) = *(uint *)(iVar2 + 0x2e8) ^ 1 << (bVar6 & 0x1f);

  }

  else if (iVar4 < 0x40) {

    *(uint *)(iVar2 + 0x2ec) = *(uint *)(iVar2 + 0x2ec) ^ 1 << (bVar6 - 0x20 & 0x1f);

  }

  else {

    if (iVar4 < 0x60) {

      bVar5 = bVar6 - 0x40;

    }

    else {

      if (0x7f < iVar4) goto LAB_0043c004;

      bVar5 = bVar6 + 0xa0;

    }

    *(uint *)(iVar2 + 0x2f0) = *(uint *)(iVar2 + 0x2f0) ^ 1 << (bVar5 & 0x1f);

  }

LAB_0043c004:

  if (iVar4 < 0x20) {

    uVar7 = 1 << (bVar6 & 0x1f);

    uVar8 = *(uint *)(iVar2 + 0x2e8);

LAB_0043c056:

    if ((uVar8 & uVar7) == 0) goto LAB_0043c075;

    pcVar9 = s__d___Out____s_005574fc;

  }

  else {

    if (iVar4 < 0x40) {

      uVar8 = 1 << (bVar6 - 0x20 & 0x1f);

      uVar7 = *(uint *)(iVar2 + 0x2ec);

      goto LAB_0043c056;

    }

    if (iVar4 < 0x60) {

      bVar6 = bVar6 - 0x40;

LAB_0043c049:

      uVar8 = 1 << (bVar6 & 0x1f);

      uVar7 = *(uint *)(iVar2 + 0x2f0);

      goto LAB_0043c056;

    }

    if (iVar4 < 0x80) {

      bVar6 = bVar6 + 0xa0;

      goto LAB_0043c049;

    }

LAB_0043c075:

    pcVar9 = s__d___In____s_005574ec;

  }

  crt_sprintf(local_c8,pcVar9,iVar3 + 1,iVar4 * 0x20 + 0x210 + DAT_006330e4);

  main_dlog_004286c0(DAT_0059cd60,1,iVar3,local_c8);

LAB_0043c17b:

  if ((DAT_0059cd48 == (char *)0x0) || (*DAT_0059cd48 == '\0')) {

    pcVar9 = (char *)FUN_00519CF0();

    if (pcVar9 == (char *)0x0) {

      return;

    }

    if (*pcVar9 == '\0') {

      return;

    }

    if (*pcVar9 == '\b') {

      return;

    }

    iVar3 = (int)&DAT_0059cbb4 - (int)pcVar9;

    do {

      cVar1 = *pcVar9;

      pcVar9[iVar3] = cVar1;

      pcVar9 = pcVar9 + 1;

    } while (cVar1 != '\0');

    DAT_0059cd48 = &DAT_0059cbb4;

    wredit_00519c70();

  }

  iVar3 = (int)*DAT_0059cd48;

  if (iVar3 != 0) {

    DAT_0059cd48 = DAT_0059cd48 + 1;

    if ((iVar3 < 0x31) || (0x39 < iVar3)) {

      if ((iVar3 < 0x41) || (0x5a < iVar3)) {

        if (iVar3 < 0x61) {

          return;

        }

        if (0x7a < iVar3) {

          return;

        }

        iVar3 = iVar3 + -0x57;

      }

      else {

        iVar3 = iVar3 + -0x37;

      }

    }

    else {

      iVar3 = iVar3 + -0x30;

    }

    if (iVar3 != 0) {

      wredit_flick_list3(iVar3);

    }

  }

  return;

switchD_0043c260_caseD_0:

  DAT_0059cc3c = 0;

  if (DAT_0059cd4c != 0) {

    main_dlog_00427180(DAT_0059cd4c);

  }

  DAT_0059cd4c = 0;

  DAT_0059cd4c = main_dlog_00427150();

  main_dlog_004273b0(DAT_0059cd4c,0,0x3f000000,0x3f800000,0x88000000,

                     s_World_Object_Editor_Menu_00557230);

  main_dlog_00427e80(DAT_0059cd4c,1,0x3f000000,0x40400000,0x88000022);

  wredit_00441580(DAT_0059cd4c,s_1__Mouse_Edit_Mode_is__s_0055720c,DAT_00632e74);

  main_dlog_004281f0(DAT_0059cd4c,1,s_2__Create_Object_from_List_005571f0);

  wredit_00441580(DAT_0059cd4c,s_3__Orient_to_Ground_is__s_005571d4,DAT_0059cbe0);

  main_dlog_004281f0(DAT_0059cd4c,1,s_4__Save_Changes_to_World_File_005571b4);

  wredit_00441580(DAT_0059cd4c,s_5__Select_By_GroundLoc_is__s_00557194,DAT_0059cbe4 == 0);

  return;

}

/* ===== wredit_flick_list3 @ 0x0043C420 ===== */
void wredit_flick_list3(int param_1)



{

  int iVar1;

  int iVar2;

  byte bVar3;

  byte bVar4;

  uint uVar5;

  char *pcVar6;

  undefined1 local_c8 [200];

  

  if (param_1 == 0) {

    param_1 = wredit_00428460(DAT_0059cd60,1);

    param_1 = param_1 + 1;

  }

  iVar2 = wredit_00428670(DAT_0059cd60,1,param_1 + -1);

  if (iVar2 < 0) {

    return;

  }

  iVar1 = *(int *)(DAT_0059cbd8 + 0x38);

  bVar4 = (byte)iVar2;

  if (iVar2 < 0x20) {

    *(uint *)(iVar1 + 0x2e8) = *(uint *)(iVar1 + 0x2e8) ^ 1 << (bVar4 & 0x1f);

  }

  else if (iVar2 < 0x40) {

    *(uint *)(iVar1 + 0x2ec) = *(uint *)(iVar1 + 0x2ec) ^ 1 << (bVar4 - 0x20 & 0x1f);

  }

  else {

    if (iVar2 < 0x60) {

      bVar3 = bVar4 - 0x40;

    }

    else {

      if (0x7f < iVar2) goto LAB_0043c4bb;

      bVar3 = bVar4 + 0xa0;

    }

    *(uint *)(iVar1 + 0x2f0) = *(uint *)(iVar1 + 0x2f0) ^ 1 << (bVar3 & 0x1f);

  }

LAB_0043c4bb:

  if (iVar2 < 0x20) {

    uVar5 = *(uint *)(iVar1 + 0x2e8) & 1 << (bVar4 & 0x1f);

LAB_0043c50f:

    if (uVar5 != 0) {

      pcVar6 = s__d___Out____s_005574fc;

      goto LAB_0043c543;

    }

  }

  else {

    if (iVar2 < 0x40) {

      bVar4 = bVar4 - 0x20;

      uVar5 = *(uint *)(iVar1 + 0x2ec);

LAB_0043c50d:

      uVar5 = 1 << (bVar4 & 0x1f) & uVar5;

      goto LAB_0043c50f;

    }

    if (iVar2 < 0x60) {

      bVar4 = bVar4 - 0x40;

LAB_0043c500:

      uVar5 = *(uint *)(iVar1 + 0x2f0);

      goto LAB_0043c50d;

    }

    if (iVar2 < 0x80) {

      bVar4 = bVar4 + 0xa0;

      goto LAB_0043c500;

    }

  }

  pcVar6 = s__d___In____s_005574ec;

LAB_0043c543:

  crt_sprintf(local_c8,pcVar6,param_1,iVar2 * 0x20 + 0x210 + DAT_006330e4);

  main_dlog_004286c0(DAT_0059cd60,1,param_1 + -1,local_c8);

  return;

}

/* ===== wredit_lock_list @ 0x0043C580 ===== */
void wredit_lock_list(void)



{

  int iVar1;

  int iVar2;

  int iVar3;

  char *pcVar4;

  char *pcVar5;

  int *piVar6;

  char *pcVar7;

  int iVar8;

  undefined1 local_c8 [200];

  

  DAT_0059cc3c = 0;

  if (DAT_0059cbd8 == 0) {

    wredit_00439490();

    return;

  }

  iVar3 = *(int *)(DAT_0059cbd8 + 0x38);

  iVar1 = object_find(DAT_0059cc30);

  DAT_0059cd64 = main_dlog_00427150();

  if ((DAT_0059cc34 == 0xff) || (DAT_0059cc34 < 0)) {

    pcVar5 = s__0_0_0__005574ac;

  }

  else {

    pcVar5 = *(char **)(*(int *)(*(int *)(iVar3 + 8) + 0x454) + DAT_0059cc34 * 4);

  }

  iVar3 = *(int *)(iVar3 + 4);

  main_editor_00438350();

  iVar8 = DAT_0059cc30;

  iVar2 = 0;

  piVar6 = DAT_0059cd30;

  if (0 < DAT_0059cd34) {

    do {

      if (*piVar6 == iVar3) {

        pcVar7 = (char *)(DAT_0059cd30 + iVar2 * 9 + 1);

        goto LAB_0043c619;

      }

      iVar2 = iVar2 + 1;

      piVar6 = piVar6 + 9;

    } while (iVar2 < DAT_0059cd34);

  }

  pcVar7 = s__unknown__0055724c;

LAB_0043c619:

  main_editor_00438350();

  iVar3 = 0;

  piVar6 = DAT_0059cd30;

  if (0 < DAT_0059cd34) {

    do {

      if (*piVar6 == iVar8) {

        pcVar4 = (char *)(DAT_0059cd30 + iVar3 * 9 + 1);

        goto LAB_0043c665;

      }

      iVar3 = iVar3 + 1;

      piVar6 = piVar6 + 9;

    } while (iVar3 < DAT_0059cd34);

  }

  pcVar4 = s__unknown__0055724c;

LAB_0043c665:

  crt_sprintf(local_c8,s_Locking__s_to__s____s_00557514,pcVar4,pcVar7,pcVar5);

  main_dlog_00427890(DAT_0059cd64,0,0x3f000000,0x3f800000,0x88000000,local_c8);

  main_dlog_00427e80(DAT_0059cd64,1,0x3f000000,0x40400000,0x88000022);

  iVar3 = *(int *)(iVar1 + 8);

  iVar2 = 0;

  iVar8 = 0;

  if (0 < *(int *)(iVar3 + 0x450)) {

    do {

      pcVar5 = *(char **)(*(int *)(iVar3 + 0x454) + iVar8 * 4);

      if (pcVar5 != (char *)0x0) {

        iVar2 = iVar2 + 1;

        if ((iVar8 == 0xff) || (iVar8 < 0)) {

          pcVar5 = s__0_0_0__005574ac;

        }

        crt_sprintf(local_c8,s__d____s_0055750c,iVar2,pcVar5);

        main_dlog_00428140(DAT_0059cd64,1,local_c8,iVar8);

      }

      iVar3 = *(int *)(iVar1 + 8);

      iVar8 = iVar8 + 1;

    } while (iVar8 < *(int *)(iVar3 + 0x450));

  }

  crt_sprintf(local_c8,s__d____s_0055750c,iVar2,s__0_0_0__005574ac);

  main_dlog_00428140(DAT_0059cd64,1,local_c8,0xff);

  return;

}

/* ===== wredit_menu_6 @ 0x0043C760 ===== */
void wredit_menu_6(void)



{

  char cVar1;

  int iVar2;

  char *pcVar3;

  int iVar4;

  

  dlog_list_navigate_sound(DAT_0059cd64);

  if ((DAT_00632aa4._3_1_ == '\0') && (DAT_00632aad == '\0')) {

    if ((DAT_00632aa8 != '\0') ||

       ((DAT_00632aaa != '\0' && (iVar2 = main_dlog_00427310(DAT_0059cd64), iVar2 == 1)))) {

      wredit_menu_7(0);

    }

    if ((DAT_0059cd48 == (char *)0x0) || (*DAT_0059cd48 == '\0')) {

      pcVar3 = (char *)FUN_00519CF0();

      if (pcVar3 == (char *)0x0) {

        return;

      }

      if (*pcVar3 == '\0') {

        return;

      }

      if (*pcVar3 == '\b') {

        return;

      }

      iVar2 = (int)&DAT_0059cbb4 - (int)pcVar3;

      do {

        cVar1 = *pcVar3;

        pcVar3[iVar2] = cVar1;

        pcVar3 = pcVar3 + 1;

      } while (cVar1 != '\0');

      DAT_0059cd48 = &DAT_0059cbb4;

      wredit_00519c70();

    }

    iVar2 = (int)*DAT_0059cd48;

    if (iVar2 != 0) {

      DAT_0059cd48 = DAT_0059cd48 + 1;

      if ((iVar2 < 0x31) || (0x39 < iVar2)) {

        if ((iVar2 < 0x41) || (0x5a < iVar2)) {

          if (iVar2 < 0x61) {

            return;

          }

          if (0x7a < iVar2) {

            return;

          }

          iVar2 = iVar2 + -0x57;

        }

        else {

          iVar2 = iVar2 + -0x37;

        }

      }

      else {

        iVar2 = iVar2 + -0x30;

      }

      if (iVar2 != 0) {

        wredit_menu_7(iVar2);

      }

    }

  }

  else {

    wredit_00439490();

    DAT_0059cc38 = 3;

    wredit_004959c0();

    dlog_push_level(&LAB_00438ef0,&LAB_00438dd0);

    DAT_00632ab0 = 0;

    DAT_00632aad = '\0';

    DAT_00632aaa = '\0';

    wredit_00519c70();

    main_editor_00438350();

    switch(DAT_0059cc38) {

    case 0:

      DAT_0059cc3c = 0;

      if (DAT_0059cd4c != 0) {

        main_dlog_00427180(DAT_0059cd4c);

      }

      DAT_0059cd4c = 0;

      DAT_0059cd4c = main_dlog_00427150();

      main_dlog_004273b0(DAT_0059cd4c,0,0x3f000000,0x3f800000,0x88000000,

                         s_World_Object_Editor_Menu_00557230);

      main_dlog_00427e80(DAT_0059cd4c,1,0x3f000000,0x40400000,0x88000022);

      wredit_00441580(DAT_0059cd4c,s_1__Mouse_Edit_Mode_is__s_0055720c,DAT_00632e74);

      main_dlog_004281f0(DAT_0059cd4c,1,s_2__Create_Object_from_List_005571f0);

      wredit_00441580(DAT_0059cd4c,s_3__Orient_to_Ground_is__s_005571d4,DAT_0059cbe0);

      main_dlog_004281f0(DAT_0059cd4c,1,s_4__Save_Changes_to_World_File_005571b4);

      wredit_00441580(DAT_0059cd4c,s_5__Select_By_GroundLoc_is__s_00557194,DAT_0059cbe4 == 0);

      return;

    case 1:

      DAT_0059cd50 = main_dlog_00427150();

      if (DAT_0059cbd8 == 0) {

        pcVar3 = s_New_Object_Group_Selection_00557178;

      }

      else {

        pcVar3 = s_Modify_Object_Type___Group_0055715c;

      }

      main_dlog_004273b0(DAT_0059cd50,0,0x3f000000,0x3f800000,0x88000000,pcVar3);

      main_dlog_00427e80(DAT_0059cd50,1,0x3f000000,0x40400000,0x88000022);

      wredit_00428050(DAT_0059cd50,1,0x14);

      main_editor_00438350();

      iVar2 = 0;

      if (0 < DAT_0059cd38) {

        iVar4 = 0;

        do {

          main_dlog_004281f0(DAT_0059cd50,1,iVar4 + 4 + DAT_0059cd2c);

          iVar2 = iVar2 + 1;

          iVar4 = iVar4 + 0x24;

        } while (iVar2 < DAT_0059cd38);

      }

      DAT_0059cd08 = 0;

      DAT_0059cd28 = 0;

      return;

    case 2:

      wredit_object_select();

      return;

    case 3:

      wredit_obj_info();

      return;

    case 4:

      wredit_lock_menu();

      return;

    case 5:

      wredit_flick_menu();

      return;

    case 6:

      wredit_lock_list();

      return;

    case 7:

      wredit_ai_menu();

      return;

    case 8:

      wredit_marker_menu_full();

      return;

    case 9:

      wredit_marker_info3();

      return;

    case 10:

      wredit_marker_info();

      return;

    case 0xb:

      wredit_marker_info2();

      return;

    case 0xc:

      wredit_trigger_menu();

      return;

    }

  }

  return;

}

/* ===== wredit_menu_7 @ 0x0043CAA0 ===== */
void wredit_menu_7(int param_1)



{

  undefined4 *puVar1;

  int iVar2;

  undefined *puVar3;

  int iVar4;

  undefined4 uVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  char *pcVar9;

  undefined1 auStack_100 [256];

  

  iVar8 = 0;

  if (param_1 == 0) {

    param_1 = wredit_00428460(DAT_0059cd64,1);

    param_1 = param_1 + 1;

  }

  iVar2 = wredit_00428670(DAT_0059cd64,1,param_1 + -1);

  if (-1 < iVar2) {

    iVar6 = *(int *)(DAT_0059cbd8 + 0x38);

    for (puVar1 = DAT_00632d68; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {

      iVar7 = puVar1[3];

      if ((*(int *)(iVar7 + 0x210) == iVar6) && (*(int *)(iVar7 + 0x218) == DAT_0059cc34)) {

        if (*(int *)(iVar7 + 4) != DAT_0059cc30) {

          *(undefined4 *)(iVar7 + 0x210) = 0;

          object_destroy(iVar7);

          iVar2 = object_spawn_small(iVar6,DAT_0059cc30,iVar2,DAT_0059cc34,0);

          goto LAB_0043cb30;

        }

        *(int *)(iVar7 + 0x214) = iVar2;

        goto LAB_0043cb4c;

      }

    }

    iVar2 = object_spawn_small(iVar6,DAT_0059cc30,iVar2,DAT_0059cc34,0);

LAB_0043cb30:

    *(uint *)(iVar2 + 0xdc) = *(uint *)(iVar2 + 0xdc) | 0x20000000;

    if (DAT_00632bd8 != 0) {

      *(uint *)(iVar2 + 0xd8) = *(uint *)(iVar2 + 0xd8) | 0x400;

    }

LAB_0043cb4c:

    wredit_00439490();

    DAT_0059cc38 = 4;

    wredit_004959c0();

    dlog_push_level(&LAB_00438ef0,&LAB_00438dd0);

    DAT_00632ab0 = 0;

    DAT_00632aad = 0;

    DAT_00632aaa = 0;

    wredit_00519c70();

    main_editor_00438350();

    switch(DAT_0059cc38) {

    case 0:

      DAT_0059cc3c = 0;

      if (DAT_0059cd4c != 0) {

        main_dlog_00427180(DAT_0059cd4c);

      }

      DAT_0059cd4c = 0;

      DAT_0059cd4c = main_dlog_00427150();

      main_dlog_004273b0(DAT_0059cd4c,0,0x3f000000,0x3f800000,0x88000000,

                         s_World_Object_Editor_Menu_00557230);

      main_dlog_00427e80(DAT_0059cd4c,1,0x3f000000,0x40400000,0x88000022);

      iVar8 = DAT_0059cd4c;

      puVar3 = &DAT_0055722c;

      if (DAT_00632e74 == 0) {

        puVar3 = &DAT_00557228;

      }

      crt_sprintf(auStack_100,s_1__Mouse_Edit_Mode_is__s_0055720c,puVar3);

      main_dlog_004281f0(iVar8,1,auStack_100);

      main_dlog_004281f0(DAT_0059cd4c,1,s_2__Create_Object_from_List_005571f0);

      wredit_00441580(DAT_0059cd4c,s_3__Orient_to_Ground_is__s_005571d4,DAT_0059cbe0);

      main_dlog_004281f0(DAT_0059cd4c,1,s_4__Save_Changes_to_World_File_005571b4);

      wredit_00441580(DAT_0059cd4c,s_5__Select_By_GroundLoc_is__s_00557194,DAT_0059cbe4 == 0);

      break;

    case 1:

      DAT_0059cd50 = main_dlog_00427150();

      if (DAT_0059cbd8 == 0) {

        pcVar9 = s_New_Object_Group_Selection_00557178;

      }

      else {

        pcVar9 = s_Modify_Object_Type___Group_0055715c;

      }

      main_dlog_004273b0(DAT_0059cd50,0,0x3f000000,0x3f800000,0x88000000,pcVar9);

      main_dlog_00427e80(DAT_0059cd50,1,0x3f000000,0x40400000,0x88000022);

      wredit_00428050(DAT_0059cd50,1,0x14);

      main_editor_00438350();

      iVar8 = 0;

      if (0 < DAT_0059cd38) {

        iVar2 = 0;

        do {

          main_dlog_004281f0(DAT_0059cd50,1,iVar2 + 4 + DAT_0059cd2c);

          iVar8 = iVar8 + 1;

          iVar2 = iVar2 + 0x24;

        } while (iVar8 < DAT_0059cd38);

      }

      DAT_0059cd28 = 0;

      DAT_0059cd08 = 0;

      return;

    case 2:

      DAT_0059cd54 = main_dlog_00427150();

      if (DAT_0059cbd8 == 0) {

        iVar2 = DAT_0059cd2c + 4 + DAT_0059cd3c * 0x24;

        pcVar9 = s_New_Object_of_Group__s_00557144;

      }

      else {

        iVar2 = DAT_0059cd2c + 4 + DAT_0059cd3c * 0x24;

        pcVar9 = s_Modify_Object_of_Group__s_00557128;

      }

      crt_sprintf(auStack_100,pcVar9,iVar2);

      main_dlog_00427890(DAT_0059cd54,0,0x3f000000,0x3f800000,0x88000000,auStack_100);

      main_dlog_00427e80(DAT_0059cd54,1,0x3f000000,0x40400000,0x88000032);

      wredit_00428050(DAT_0059cd54,1,0x14);

      iVar2 = 0;

      iVar6 = 0;

      if (0 < DAT_0059cd34) {

        iVar7 = 0;

        do {

          iVar4 = object_find(*(undefined4 *)(iVar7 + DAT_0059cd30));

          if (*(byte *)(iVar4 + 0x1f6) == DAT_0059cd3c) {

            main_dlog_00428140(DAT_0059cd54,1,iVar7 + 4 + DAT_0059cd30,iVar8);

            if (*(int *)(iVar7 + DAT_0059cd30) == DAT_0059cd40) {

              iVar2 = iVar6;

            }

            iVar6 = iVar6 + 1;

          }

          iVar8 = iVar8 + 1;

          iVar7 = iVar7 + 0x24;

        } while (iVar8 < DAT_0059cd34);

      }

      wredit_004284d0(DAT_0059cd54,1,iVar2);

      DAT_0059cd08 = 0;

      DAT_0059cd28 = 0;

      return;

    case 3:

      wredit_obj_info();

      return;

    case 4:

      wredit_lock_menu();

      return;

    case 5:

      if (DAT_0059cbd8 == 0) {

        wredit_00439490();

        return;

      }

      iVar2 = *(int *)(DAT_0059cbd8 + 0x38);

      DAT_0059cd60 = main_dlog_00427150();

      uVar5 = main_editor_0043aa00(*(undefined4 *)(iVar2 + 4));

      crt_sprintf(auStack_100,s_Flick_exclusions_on_Object__s_005574cc,uVar5);

      main_dlog_00427890(DAT_0059cd60,0,0x3f000000,0x3f800000,0x88000000,auStack_100);

      main_dlog_00427e80(DAT_0059cd60,1,0x3f000000,0x40400000,0x88000022);

      wredit_00428050(DAT_0059cd60,1,0x14);

      iVar6 = 0;

      iVar7 = 0;

      do {

        if (*(char *)(iVar8 + 0x210 + DAT_006330e4) != '\0') {

          iVar6 = iVar6 + 1;

          wredit_flick_list2(iVar2,iVar6,iVar7,auStack_100);

          main_dlog_00428140(DAT_0059cd60,1,auStack_100,iVar7);

        }

        iVar8 = iVar8 + 0x20;

        iVar7 = iVar7 + 1;

      } while (iVar8 < 0x1000);

      if (iVar6 == 0) {

        main_dlog_00428140(DAT_0059cd60,1,s__No_Flicks_for_World__005574b4,0xffffffff);

        return;

      }

      break;

    case 6:

      wredit_lock_list();

      return;

    case 7:

      wredit_ai_menu();

      return;

    case 8:

      wredit_marker_menu_full();

      return;

    case 9:

      wredit_marker_info3();

      return;

    case 10:

      wredit_marker_info();

      return;

    case 0xb:

      wredit_marker_info2();

      return;

    case 0xc:

      wredit_trigger_menu();

      return;

    }

  }

  return;

}

/* ===== wredit_ai_menu @ 0x0043D0A0 ===== */
void wredit_ai_menu(void)



{

  int iVar1;

  float *pfVar2;

  int iVar3;

  char *pcVar4;

  int iVar5;

  undefined4 uVar6;

  int *piVar7;

  int iVar8;

  undefined4 unaff_ESI;

  undefined4 unaff_EDI;

  undefined4 *puVar9;

  undefined1 *puVar11;

  undefined8 uVar10;

  undefined8 uVar12;

  undefined1 local_100 [256];

  

  if (DAT_0059cbd8 == 0) {

    wredit_00439490();

    return;

  }

  iVar1 = *(int *)(DAT_0059cbd8 + 0x38);

  DAT_0059cd68 = main_dlog_00427150();

  iVar5 = *(int *)(iVar1 + 4);

  main_editor_00438350();

  iVar3 = 0;

  piVar7 = DAT_0059cd30;

  if (0 < DAT_0059cd34) {

    do {

      if (*piVar7 == iVar5) break;

      iVar3 = iVar3 + 1;

      piVar7 = piVar7 + 9;

    } while (iVar3 < DAT_0059cd34);

  }

  puVar11 = local_100;

  uVar10 = CONCAT44(*(undefined4 *)(iVar1 + 4),s_Object_Type__d___s__005570bc);

  crt_sprintf();

  main_dlog_00427890(DAT_0059cd68,0,0x3f000000,0x40400000,0x88000000,local_100,puVar11,uVar10);

  crt_sprintf(local_100,s_AI_Type____d_00557e6c,*(undefined4 *)(iVar1 + 0xe8));

  main_dlog_00427890(DAT_0059cd68,0,0x3f000000,0x40800000,0x88000000,local_100);

  iVar5 = *(int *)(iVar1 + 0x1e0);

  if (iVar5 == 0x34) {

    main_dlog_004273b0(DAT_0059cd68,0,0x3f000000,0x3f800000,0x88000000,s_Gate_AI_Selection_00557e58)

    ;

    pfVar2 = *(float **)(iVar1 + 0x100);

    crt_sprintf(local_100,s_Radius_____f__Origin_____f___f___00557e34,(double)*pfVar2,

                (double)pfVar2[1],(double)pfVar2[2],(double)pfVar2[3]);

    main_dlog_00427890(DAT_0059cd68,0,0x3f000000,0x40a00000,0x88000000,local_100);

    uVar12 = 0x8800002240e00000;

    uVar10 = 0x3f00000000000001;

    uVar6 = DAT_0059cd68;

    main_dlog_00427e80();

    main_dlog_004281f0(DAT_0059cd68,1,s_0__Set_AI_HardCode_Operation_00557e14,uVar6,uVar10,uVar12);

    main_dlog_004281f0(DAT_0059cd68,1,s_1__Set_AI_Mecc_Approach_00557dfc);

    main_dlog_004281f0(DAT_0059cd68,1,s_2__Set_AI_Enemies_Killed_00557de0);

    return;

  }

  if ((iVar5 != 0x61) && (iVar5 != 0x2d)) {

    if (iVar5 == 0x17) {

      main_dlog_004273b0(DAT_0059cd68,0,0x3f000000,0x3f800000,0x88000000,

                         s_ReaperMan_AI_Selection_00557dc8);

      main_dlog_00427e80(DAT_0059cd68,1,0x3f000000,0x40e00000,0x88000022);

      main_dlog_004281f0(DAT_0059cd68,1,s_0__Set_AI_Normal_00557db4);

      main_dlog_004281f0(DAT_0059cd68,1,s_1__Set_AI_Building_Smasher_00557d98);

      uVar10 = 0x557d8000000001;

      uVar6 = DAT_0059cd68;

      main_dlog_004281f0();

      main_dlog_004281f0(DAT_0059cd68,1,s_3__Set_AI_Radius_Bound_00557d68,uVar6,uVar10);

      return;

    }

    if (iVar5 != 100) {

      if (iVar5 == 0x68) {

        main_dlog_004273b0(DAT_0059cd68,0,0x3f000000,0x3f800000,0x88000000,

                           s_ReaperMan_AI_Selection_00557dc8);

        main_dlog_00427e80(DAT_0059cd68,1,0x3f000000,0x40e00000,0x88000022);

        main_dlog_004281f0(DAT_0059cd68,1,s_0__Start_In_Down_Position_00557d4c);

        main_dlog_004281f0(DAT_0059cd68,1,s_1__Start_In_Up_Position_00557d34);

        return;

      }

      if (iVar5 == 0x66) {

        iVar1 = *(int *)(*(int *)(DAT_0059cbd8 + 0x38) + 0x100);

        puVar9 = (undefined4 *)(iVar1 + 0x54);

        for (iVar5 = 0x14; iVar5 != 0; iVar5 = iVar5 + -1) {

          *puVar9 = 0;

          puVar9 = puVar9 + 1;

        }

        puVar9 = (undefined4 *)(iVar1 + 0xf8);

        for (iVar5 = 0x14; iVar5 != 0; iVar5 = iVar5 + -1) {

          *puVar9 = 0;

          puVar9 = puVar9 + 1;

        }

        DAT_00632e7c = 1;

        DAT_0059cbb0 = DAT_00632a88;

        DAT_00632a88 = object_allocate_type(3,0x80000000);

        object_setup_specialtype();

        giftshopview_enable();

        return;

      }

      if (iVar5 == 0x33) {

        main_dlog_004273b0(DAT_0059cd68,0,0x3f000000,0x3f800000,0x88000000,

                           s_ReaperMan_AI_Selection_00557dc8);

        main_dlog_00427e80(DAT_0059cd68,1,0x3f000000,0x40e00000,0x88000022);

        main_dlog_004281f0(DAT_0059cd68,1,s_0__Set_Machine_Gun_RPG__no_jetpa_00557d10);

        main_dlog_004281f0(DAT_0059cd68,1,s_1__Set_Sniper_00557d00);

        uVar10 = 0x557cf000000001;

        uVar6 = DAT_0059cd68;

        main_dlog_004281f0();

        main_dlog_004281f0(DAT_0059cd68,1,s_3__Set_RPG__with_jetpack__00557cd4,uVar6,uVar10);

        return;

      }

      if ((iVar5 == 1) || (iVar5 == 0xf)) {

        main_dlog_004273b0(DAT_0059cd68,0,0x3f000000,0x3f800000,0x88000000,

                           s_Log_Luncher_Number_of_Riders_00557cb4);

        main_dlog_00427e80(DAT_0059cd68,1,0x3f000000,0x40e00000,0x88000022);

        main_dlog_004281f0(DAT_0059cd68,1,s_0__Player_Kabuto_00557558);

        main_dlog_004281f0(DAT_0059cd68,1,s_1__Pre_Arena_Kabuto_00557544);

        main_dlog_004281f0();

        return;

      }

      if (iVar5 == 0x1c) {

        main_dlog_004273b0(DAT_0059cd68,0,0x3f000000,0x3f800000,0x88000000,

                           s_Log_Luncher_Number_of_Riders_00557cb4);

        main_dlog_00427e80(DAT_0059cd68,1,0x3f000000,0x40e00000,0x88000022);

        main_dlog_004281f0(DAT_0059cd68,1,s_0__KabutoAI_Generator_00557c9c);

        pcVar4 = s_1__Player_Kabuto_Generator_00557c80;

      }

      else {

        if (iVar5 == 99) {

          main_dlog_004273b0(DAT_0059cd68,0,0x3f000000,0x3f800000,0x88000000,

                             s_Log_Luncher_Number_of_Riders_00557cb4);

          main_dlog_00427e80(DAT_0059cd68,1,0x3f000000,0x40e00000,0x88000022);

          main_dlog_004281f0(DAT_0059cd68,1,s_0__Normal_00557c74);

          main_dlog_004281f0(DAT_0059cd68,1,s_1__Turret_00557c68);

          uVar10 = 0x557c5c00000001;

          uVar6 = DAT_0059cd68;

          main_dlog_004281f0();

          main_dlog_004281f0(DAT_0059cd68,1,s_3__Fast_Raik_00557c4c,uVar6,uVar10);

          main_dlog_004281f0(DAT_0059cd68,1,s_4__Fast_Turret_00557c3c);

          return;

        }

        if (iVar5 == 0x62) {

          main_dlog_004273b0(DAT_0059cd68,0,0x3f000000,0x3f800000,0x88000000,

                             s_Log_Luncher_Number_of_Riders_00557cb4);

          main_dlog_00427e80(DAT_0059cd68,1,0x3f000000,0x40e00000,0x88000022);

          main_dlog_004281f0(DAT_0059cd68,1,s_0__Mini_Barracks_00557c28);

          main_dlog_004281f0(DAT_0059cd68,1,s_1__Mini_Barracks__no_rpmen__00557c0c);

          uVar10 = 0x557bf800000001;

          uVar6 = DAT_0059cd68;

          main_dlog_004281f0();

          main_dlog_004281f0(DAT_0059cd68,1,s_3__Full_Barracks__no_rpmen__00557bdc,uVar6,uVar10);

          main_dlog_004281f0(DAT_0059cd68,1,s_4__Ripper_Husk_00557bcc);

          main_dlog_004281f0(DAT_0059cd68,1,s_5__Ripper_Husk__no_rippers__00557bb0);

          return;

        }

        if (iVar5 == 0x43) {

          main_dlog_004273b0(DAT_0059cd68,0,0x3f000000,0x3f800000,0x88000000,

                             s_Log_Luncher_Number_of_Riders_00557cb4);

          main_dlog_00427e80(DAT_0059cd68,1,0x3f000000,0x40e00000,0x88000022);

          main_dlog_004281f0(DAT_0059cd68,1,s_0__Zero_00557ba8);

          main_dlog_004281f0(DAT_0059cd68,1,s_1__One_00557ba0);

          uVar10 = 0x557b9800000001;

          uVar6 = DAT_0059cd68;

          main_dlog_004281f0();

          main_dlog_004281f0(DAT_0059cd68,1,s_3__Three_00557b8c,uVar6,uVar10);

          main_dlog_004281f0(DAT_0059cd68,1,s_4__Four_00557b84);

          main_dlog_004281f0(DAT_0059cd68,1,s_5__Five_00557b7c);

          main_dlog_004281f0(DAT_0059cd68,1,s_6__Six_00557b74);

          main_dlog_004281f0(DAT_0059cd68,1,s_7__Seven_00557b68);

          main_dlog_004281f0();

          return;

        }

        if (iVar5 == 0x67) {

          main_dlog_004273b0(DAT_0059cd68,0,0x3f000000,0x3f800000,0x88000000,

                             s_Bunker_AI_Selection_00557b48);

          main_dlog_00427e80(DAT_0059cd68,1,0x3f000000,0x40e00000,0x88000022);

          main_dlog_004281f0(DAT_0059cd68,1,s_0__No_Reapermen_00557b38);

          main_dlog_004281f0(DAT_0059cd68,1,s_1__One_Reapermen_00557b24);

          uVar10 = 0x557b1000000001;

          uVar6 = DAT_0059cd68;

          main_dlog_004281f0();

          main_dlog_004281f0(DAT_0059cd68,1,s_3__Three_Reapermen_00557afc,uVar6,uVar10);

          main_dlog_004281f0(DAT_0059cd68,1,s_4__Four_Reapermen_00557ae8);

          main_dlog_004281f0(DAT_0059cd68,1,s_5__Five_Reapermen_00557ad4);

          main_dlog_004281f0(DAT_0059cd68,1,s_6__Six_Reapermen_00557ac0);

          return;

        }

        if (iVar5 == 0x12) {

          main_dlog_004273b0(DAT_0059cd68,0,0x3f000000,0x3f800000,0x88000000,

                             s_Smartie_AI_Selection_00557aa8);

          main_dlog_00427e80(DAT_0059cd68,1,0x3f000000,0x40e00000,0x88000022);

          main_dlog_00428140(DAT_0059cd68,1,s_0__Set_AI_WalkAbout_00557a94,0);

          main_dlog_00428140(DAT_0059cd68,1,s_1__Set_AI_Frozen_00557a80,1);

          main_dlog_00428140(DAT_0059cd68,1,s_2__Set_AI_Wait__then_Board_00557a64,2);

          main_dlog_00428140(DAT_0059cd68,1,s_3__Set_AI_Board_on___Stay_00557a48,3);

          main_dlog_00428140(DAT_0059cd68,1,s_4__Set_AI_Base_Builder_00557a30,4);

          main_dlog_00428140(DAT_0059cd68,1,s_5__Set_AI_Cliffhanger_00557a18,5);

          main_dlog_00428140(DAT_0059cd68,1,s_6__Set_AI_Timmy_Jetpack_00557a00,6);

          main_dlog_00428140(DAT_0059cd68,1,s_7__Set_AI_Borjoyzee_Waiting_005579e4,7);

          main_dlog_00428140(DAT_0059cd68,1,s_8__Set_AI_Sitting_005579d0,8);

          main_dlog_00428140(DAT_0059cd68,1,s_9__Set_AI_Kidnapped_005579bc,9);

          main_dlog_00428140(DAT_0059cd68,1,s_10___Set_AI_Single_Player_Borjoy_00557998,10);

          return;

        }

        if (iVar5 == 2) {

          main_dlog_004273b0(DAT_0059cd68,0,0x3f000000,0x3f800000,0x88000000,

                             s_Mecc_AI_Selection_00557984);

          main_dlog_00427e80(DAT_0059cd68,1,0x3f000000,0x40e00000,0x88000022);

          main_dlog_004281f0(DAT_0059cd68,1,s_0__Set_AI_Normal_00557db4);

          main_dlog_004281f0(DAT_0059cd68,1,s_1__Set_AI_Tel_Hanging_0055796c);

          return;

        }

        if (iVar5 == 0x26) {

          main_dlog_004273b0(DAT_0059cd68,0,0x3f000000,0x3f800000,0x88000000,

                             s_Smartie_Hatch_AI_Selection_00557950);

          main_dlog_00427e80(DAT_0059cd68,1,0x3f000000,0x40e00000,0x88000022);

          main_dlog_004281f0(DAT_0059cd68,1,s_0__Set_AI_Disabled_0055793c);

          main_dlog_004281f0(DAT_0059cd68,1,s_1__Set_AI_Entrance_00557928);

          uVar10 = 0x55791000000001;

          uVar6 = DAT_0059cd68;

          main_dlog_004281f0();

          main_dlog_004281f0(DAT_0059cd68,1,s_3__Set_AI_Spawn_Basebuilder_Smar_005578e8,uVar6,uVar10

                            );

          main_dlog_004281f0(DAT_0059cd68,1,s_4__Set_AI_Spawn_Kabuto_Smarties_005578c8);

          return;

        }

        if (iVar5 != 0x15) {

          if (iVar5 == 0x11) {

            main_dlog_004273b0(DAT_0059cd68,0,0x3f000000,0x3f800000,0x88000000,

                               s_Herd_Generator_AI_Selection_00557868);

            main_dlog_00427e80(DAT_0059cd68,1,0x3f000000,0x40e00000,0x88000022);

            main_dlog_004281f0(DAT_0059cd68,1,s_0__Start_Generated_Vimps_Young___00557840);

            main_dlog_004281f0(DAT_0059cd68,1,s_1__Freeze_Generated_Vimps_at_Ran_00557818);

            return;

          }

          if (iVar5 == 0x35) {

            main_dlog_004273b0(DAT_0059cd68,0,0x3f000000,0x3f800000,0x88000000,

                               s_Verm_AI_Selection_00557804);

            main_dlog_00427e80(DAT_0059cd68,1,0x3f000000,0x40e00000,0x88000022);

            main_dlog_00428140(DAT_0059cd68,1,s_0__Set_AI_Normal_00557db4,0);

            main_dlog_00428140(DAT_0059cd68,1,s_1__Set_AI_Frozen_Test_005577ec,1);

            return;

          }

          if (iVar5 == 0x25) {

            main_dlog_004273b0(DAT_0059cd68,0,0x3f000000,0x3f800000,0x88000000,

                               s_Item_Powerup_AI_Selection_005577d0);

            main_dlog_00427e80(DAT_0059cd68,1,0x3f000000,0x40e00000,0x88000022);

            main_dlog_004281f0(DAT_0059cd68,1,s_0__Award_Once_005577c0);

            main_dlog_004281f0(DAT_0059cd68,1,s_1__Regenerate_30_Seconds_005577a4);

            uVar10 = 0x55778800000001;

            uVar6 = DAT_0059cd68;

            main_dlog_004281f0();

            main_dlog_004281f0(DAT_0059cd68,1,s_3__Regenerate_1_Minute_00557770,uVar6,uVar10);

            main_dlog_004281f0(DAT_0059cd68,1,s_4__Regenerate_2_Minutes_00557758);

            main_dlog_004281f0(DAT_0059cd68,1,s_5__Regenerate_5_Minutes_00557740);

            return;

          }

          if (iVar5 != 0x4a) {

            if ((iVar5 == 0x20) || (iVar5 == 0x52)) {

              main_dlog_004273b0(DAT_0059cd68,0,0x3f000000,0x3f800000,0x88000000,

                                 s_Base_Setup_005575fc);

              main_dlog_00427e80(DAT_0059cd68,1,0x3f000000,0x40e00000,0x88000022);

              main_dlog_00428140(DAT_0059cd68,1,s_0__Identifier_for_scenario_setup_005575d8,0);

              main_dlog_00428140(DAT_0059cd68,1,s_1__Identifier_for_scenario_setup_005575b4,1);

              main_dlog_00428140(DAT_0059cd68,1,s_2__Identifier_for_scenario_setup_00557590,2);

              uVar10 = 0x30055756c;

            }

            else {

              if (iVar5 == 0x53) {

                main_dlog_004273b0(DAT_0059cd68,0,0x3f000000,0x3f800000,0x88000000,

                                   s_Reaper_Base_Item_Setup_00557710);

                main_dlog_00427e80(DAT_0059cd68,1,0x3f000000,0x40e00000,0x88000022);

                main_dlog_00428140(DAT_0059cd68,1,s_0__Real_Standalone__decorative__005576f0,0);

                main_dlog_00428140(DAT_0059cd68,1,s_1__Ghost_Placement_for_Base__pos_005576bc,1);

                main_dlog_00428140(DAT_0059cd68,1,s_2__Hide_Until_Base_Activated_0055769c,2);

                return;

              }

              if (iVar5 != 0x4b) {

                if (iVar5 != 0x5c) {

                  main_dlog_004273b0(DAT_0059cd68,0,0x3f000000,0x3f800000,0x88000000,

                                     s_Unknown_AI_Selection_00557608);

                  return;

                }

                main_dlog_004273b0(DAT_0059cd68,0,0x3f000000,0x3f800000,0x88000000,

                                   s_Light_selection_00557638);

                main_dlog_00427e80(DAT_0059cd68,1,0x3f000000,0x40e00000,0x88000022);

                uVar6 = FUN_0046f540(iVar1);

                crt_sprintf(local_100,s_Current_light_is____s_00557620,uVar6);

                main_dlog_00427890(DAT_0059cd68,0,0x3f000000,0x40e00000,0x88000000,local_100);

                return;

              }

              main_dlog_004273b0(DAT_0059cd68,0,0x3f000000,0x3f800000,0x88000000,

                                 s_Offspring_AI_selection_00557684);

              main_dlog_00427e80(DAT_0059cd68,1,0x3f000000,0x40e00000,0x88000022);

              main_dlog_00428140(DAT_0059cd68,1,s_0__Normal_00557c74,0);

              main_dlog_00428140(DAT_0059cd68,1,s_1__Test_anim_00557674,1);

              main_dlog_00428140(DAT_0059cd68,1,s_2__Test_anitclockwise_0055765c,2);

              uVar10 = 0x300557648;

            }

            main_dlog_00428140(DAT_0059cd68,1,uVar10);

            return;

          }

          main_dlog_004273b0(DAT_0059cd68,0,0x3f000000,0x3f800000,0x88000000,

                             s_Mecc_Base_Item_Setup_00557728);

          return;

        }

        main_dlog_004273b0(DAT_0059cd68,0,0x3f000000,0x3f800000,0x88000000,

                           s_Vimp_AI_Selection_005578b4);

        main_dlog_00427e80(DAT_0059cd68,1,0x3f000000,0x40e00000,0x88000022);

        main_dlog_004281f0(DAT_0059cd68,1,s_0__Start_Young___Grow_0055789c);

        pcVar4 = s_1__Freeze_at_Random_Age_00557884;

      }

      main_dlog_004281f0(DAT_0059cd68,1,pcVar4);

      return;

    }

  }

  iVar1 = *(int *)(DAT_0059cbd8 + 0x38);

  DAT_0059cd80 = main_dlog_00427150(unaff_EDI,unaff_ESI);

  iVar5 = *(int *)(iVar1 + 4);

  main_editor_00438350();

  iVar3 = 0;

  piVar7 = DAT_0059cd30;

  if (0 < DAT_0059cd34) {

    do {

      if (*piVar7 == iVar5) {

        pcVar4 = (char *)(DAT_0059cd30 + iVar3 * 9 + 1);

        goto LAB_0043e09d;

      }

      iVar3 = iVar3 + 1;

      piVar7 = piVar7 + 9;

    } while (iVar3 < DAT_0059cd34);

  }

  pcVar4 = s__unknown__0055724c;

LAB_0043e09d:

  crt_sprintf(local_100,s_Object_Type__d___s__005570bc,*(undefined4 *)(iVar1 + 4),pcVar4);

  main_dlog_00427890(DAT_0059cd80,0,0x3f000000,0,0x88000000,local_100);

  crt_sprintf(local_100,s_Marker_Type____d_00557e84,*(undefined4 *)(iVar1 + 0xe8));

  main_dlog_00427890(DAT_0059cd80,0,0x3f000000,0x3f800000,0x88000000,local_100);

  iVar5 = AudioDataStreamStatus__Fv_2();

  main_dlog_00427e80();

  iVar3 = 0;

  if (-1 < iVar5) {

    do {

      iVar8 = iVar3 + 0x30;

      if (9 < iVar3) {

        iVar8 = iVar3 + 0x37;

      }

      uVar6 = marker_get_name(iVar1,iVar3);

      crt_sprintf(local_100,s__c___s_00557e7c,iVar8,uVar6);

      main_dlog_004281f0(DAT_0059cd80,1,local_100);

      uVar6 = showchat_mission_objective__Fi(iVar3);

      wredit_004287c0(DAT_0059cd80,1,iVar3,uVar6);

      iVar3 = iVar3 + 1;

    } while (iVar3 <= iVar5);

  }

  dlog_push_level(&LAB_0043e1d0,&LAB_0043e1c0);

  return;

}

/* ===== wredit_marker_menu2 @ 0x0043EFB0 ===== */
void wredit_marker_menu2(void)



{

  int iVar1;

  int iVar2;

  char *pcVar3;

  int iVar4;

  undefined4 uVar5;

  int *piVar6;

  int iVar7;

  undefined1 local_100 [256];

  

  iVar1 = *(int *)(DAT_0059cbd8 + 0x38);

  DAT_0059cd8c = main_dlog_00427150();

  iVar4 = *(int *)(iVar1 + 4);

  main_editor_00438350();

  iVar2 = 0;

  piVar6 = DAT_0059cd30;

  if (0 < DAT_0059cd34) {

    do {

      if (*piVar6 == iVar4) {

        pcVar3 = (char *)(DAT_0059cd30 + iVar2 * 9 + 1);

        goto LAB_0043effd;

      }

      iVar2 = iVar2 + 1;

      piVar6 = piVar6 + 9;

    } while (iVar2 < DAT_0059cd34);

  }

  pcVar3 = s__unknown__0055724c;

LAB_0043effd:

  crt_sprintf(local_100,s_Object_Type__d___s__005570bc,*(undefined4 *)(iVar1 + 4),pcVar3);

  main_dlog_00427890(DAT_0059cd8c,0,0x3f000000,0,0x88000000,local_100);

  crt_sprintf(local_100,s_Marker_Type____d_00557e84,*(undefined4 *)(iVar1 + 0xe8));

  main_dlog_00427890(DAT_0059cd8c,0,0x3f000000,0x3f800000,0x88000000,local_100);

  iVar4 = AudioDataStreamStatus__Fv_2();

  main_dlog_00427e80(DAT_0059cd8c,1,0x3f000000,0x40400000,0x88000022);

  iVar2 = 0;

  if (-1 < iVar4) {

    do {

      iVar7 = iVar2 + 0x30;

      if (9 < iVar2) {

        iVar7 = iVar2 + 0x37;

      }

      uVar5 = marker_get_name(iVar1,iVar2);

      crt_sprintf(local_100,s__c___s_00557e7c,iVar7,uVar5);

      main_dlog_004281f0(DAT_0059cd8c,1,local_100);

      uVar5 = showchat_mission_objective__Fi(iVar2);

      wredit_004287c0(DAT_0059cd8c,1,iVar2,uVar5);

      iVar2 = iVar2 + 1;

    } while (iVar2 <= iVar4);

  }

  dlog_push_level(&LAB_0043e780,&LAB_0043efa0);

  return;

}

/* ===== wredit_ai_menu3 @ 0x0043F120 ===== */
void wredit_ai_menu3(void)



{

  char cVar1;

  char *pcVar2;

  int iVar3;

  

  dlog_list_navigate_sound(DAT_0059cd68);

  if ((DAT_00632aa4._3_1_ == '\0') && (DAT_00632aad == '\0')) {

    if (DAT_00632aa8 == '\0') {

      if ((DAT_00632aaa != '\0') && (iVar3 = main_dlog_00427310(DAT_0059cd68), iVar3 == 1)) {

        wredit_ai_menu2(0xffffffff);

      }

    }

    else {

      wredit_ai_menu2(0xffffffff);

    }

  }

  else {

    wredit_00439490();

  }

  if ((DAT_0059cd48 == (char *)0x0) || (*DAT_0059cd48 == '\0')) {

    pcVar2 = (char *)FUN_00519CF0();

    if (pcVar2 == (char *)0x0) {

      return;

    }

    if (*pcVar2 == '\0') {

      return;

    }

    if (*pcVar2 == '\b') {

      return;

    }

    iVar3 = (int)&DAT_0059cbb4 - (int)pcVar2;

    do {

      cVar1 = *pcVar2;

      pcVar2[iVar3] = cVar1;

      pcVar2 = pcVar2 + 1;

    } while (cVar1 != '\0');

    DAT_0059cd48 = &DAT_0059cbb4;

    wredit_00519c70();

  }

  iVar3 = (int)*DAT_0059cd48;

  if (iVar3 != 0) {

    DAT_0059cd48 = DAT_0059cd48 + 1;

    if ((iVar3 < 0x30) || (0x39 < iVar3)) {

      if ((iVar3 < 0x41) || (0x5a < iVar3)) {

        if (iVar3 < 0x61) {

          return;

        }

        if (0x7a < iVar3) {

          return;

        }

        iVar3 = iVar3 + -0x57;

      }

      else {

        iVar3 = iVar3 + -0x37;

      }

    }

    else {

      iVar3 = iVar3 + -0x30;

    }

    if (iVar3 != -1) {

      wredit_ai_menu2(iVar3);

    }

  }

  return;

}

/* ===== wredit_ai_menu2 @ 0x0043F220 ===== */
void wredit_ai_menu2(int param_1)



{

  int iVar1;

  int iVar2;

  char *pcVar3;

  int iVar4;

  undefined4 uVar5;

  int *piVar6;

  int iVar7;

  bool bVar8;

  undefined1 local_100 [256];

  

  if (param_1 == -1) {

    param_1 = wredit_00428460(DAT_0059cd68,1);

  }

  iVar1 = *(int *)(DAT_0059cbd8 + 0x38);

  iVar4 = *(int *)(iVar1 + 0x1e0);

  if (iVar4 == 0x34) {

    *(int *)(iVar1 + 0xe8) = param_1;

    if (**(float **)(iVar1 + 0x100) == 0.0) {

      **(float **)(iVar1 + 0x100) = 100.0;

      iVar4 = *(int *)(iVar1 + 0x100);

      *(undefined4 *)(iVar4 + 4) = *(undefined4 *)(iVar1 + 0xa0);

      *(undefined4 *)(iVar4 + 8) = *(undefined4 *)(iVar1 + 0xa4);

      *(undefined4 *)(iVar4 + 0xc) = *(undefined4 *)(iVar1 + 0xa8);

      wredit_00439490();

      return;

    }

    goto LAB_0043f7ab;

  }

  if (iVar4 != 0x68) {

    if (iVar4 == 0x17) {

      bVar8 = param_1 == 1;

LAB_0043f49d:

      *(int *)(iVar1 + 0xe8) = param_1;

      *(undefined4 *)(iVar1 + 0xe4) = 0;

      if (bVar8) {

        iVar1 = *(int *)(DAT_0059cbd8 + 0x38);

        DAT_0059cd80 = main_dlog_00427150();

        iVar4 = *(int *)(iVar1 + 4);

        main_editor_00438350();

        iVar2 = 0;

        piVar6 = DAT_0059cd30;

        if (0 < DAT_0059cd34) {

          do {

            if (*piVar6 == iVar4) {

              pcVar3 = (char *)(DAT_0059cd30 + iVar2 * 9 + 1);

              goto LAB_0043e09d;

            }

            iVar2 = iVar2 + 1;

            piVar6 = piVar6 + 9;

          } while (iVar2 < DAT_0059cd34);

        }

        pcVar3 = s__unknown__0055724c;

LAB_0043e09d:

        crt_sprintf(local_100,s_Object_Type__d___s__005570bc,*(undefined4 *)(iVar1 + 4),pcVar3);

        main_dlog_00427890(DAT_0059cd80,0,0x3f000000,0,0x88000000,local_100);

        crt_sprintf(local_100,s_Marker_Type____d_00557e84,*(undefined4 *)(iVar1 + 0xe8));

        main_dlog_00427890(DAT_0059cd80,0,0x3f000000,0x3f800000,0x88000000,local_100);

        iVar4 = AudioDataStreamStatus__Fv_2();

        main_dlog_00427e80(DAT_0059cd80,1,0x3f000000,0x40400000,0x88000022);

        iVar2 = 0;

        if (-1 < iVar4) {

          do {

            iVar7 = iVar2 + 0x30;

            if (9 < iVar2) {

              iVar7 = iVar2 + 0x37;

            }

            uVar5 = marker_get_name(iVar1,iVar2);

            crt_sprintf(local_100,s__c___s_00557e7c,iVar7,uVar5);

            main_dlog_004281f0(DAT_0059cd80,1,local_100);

            uVar5 = showchat_mission_objective__Fi(iVar2);

            wredit_004287c0(DAT_0059cd80,1,iVar2,uVar5);

            iVar2 = iVar2 + 1;

          } while (iVar2 <= iVar4);

        }

        dlog_push_level(&LAB_0043e1d0,&LAB_0043e1c0);

        return;

      }

      goto LAB_0043f7ab;

    }

    if (iVar4 == 0x33) {

      *(float *)(iVar1 + 0xfc) = (float)param_1;

      DAT_0059cd84 = main_dlog_00427150();

      main_dlog_004273b0(DAT_0059cd84,0,0x3f000000,0x3f800000,0x88000000,

                         s_ReaperMan_AI_Selection_00557dc8);

      main_dlog_00427e80(DAT_0059cd84,1,0x3f000000,0x40e00000,0x88000022);

      main_dlog_004281f0(DAT_0059cd84,1,s_0__Set_AI_Ground_005580d8);

      main_dlog_004281f0(DAT_0059cd84,1,s_1__Set_AI_Small_Tower_005580c0);

      main_dlog_004281f0(DAT_0059cd84,1,s_2__Set_AI_Gate_Guard_005580a8);

      main_dlog_004281f0(DAT_0059cd84,1,s_3__Set_AI_Disabled_00558094);

      main_dlog_004281f0(DAT_0059cd84,1,s_4__Set_AI_Bunker_00558080);

      main_dlog_004281f0(DAT_0059cd84,1,s_5__Set_AI_Low_Bunker_00558068);

      main_dlog_004281f0(DAT_0059cd84,1,s_6__Set_AI_Window_00558054);

      main_dlog_004281f0(DAT_0059cd84,1,s_7__Set_AI_Sonak_Rider_0055803c);

      main_dlog_004281f0(DAT_0059cd84,1,s_8__Set_AI_Log_Rider_00558028);

      main_dlog_004281f0(DAT_0059cd84,1,s_9__Set_AI_Tuba_Player_00558010);

      main_dlog_004281f0(DAT_0059cd84,1,s_10___Set_AI_Jetski_Rider_00557ff4);

      main_dlog_004281f0(DAT_0059cd84,1,s_11___Set_AI_Jetski_Racer_00557fd8);

      main_dlog_004281f0(DAT_0059cd84,1,s_12___Set_AI_Jetski_Starter_00557fbc);

      main_dlog_004281f0(DAT_0059cd84,1,s_13___Set_AI_Boxer_00557fa8);

      main_dlog_004281f0(DAT_0059cd84,1,s_14___Set_AI_Turret_00557f94);

      main_dlog_004281f0(DAT_0059cd84,1,s_15___Set_AI_Sit_And_Spin_00557f78);

      main_dlog_004281f0(DAT_0059cd84,1,s_16___Long_Range_Turret_00557f60);

      dlog_push_level(&LAB_0043eb30,&LAB_0043f7c0);

      return;

    }

    if (((iVar4 != 0x1c) && (iVar4 != 1)) && (iVar4 != 0xf)) {

      if (iVar4 == 99) {

        bVar8 = param_1 == 2;

        goto LAB_0043f49d;

      }

      if (iVar4 == 0x62) {

        *(int *)(iVar1 + 0xe8) = param_1;

        *(undefined4 *)(iVar1 + 0x100) = 0;

        if (((param_1 == 0) || (param_1 == 2)) || (param_1 == 4)) {

          DAT_0059cd88 = main_dlog_00427150();

          main_dlog_004273b0(DAT_0059cd88,0,0x3f000000,0x3f800000,0x88000000,

                             s_Barracks_Type_Selection_00557f48);

          main_dlog_00427e80(DAT_0059cd88,1,0x3f000000,0x40e00000,0x88000022);

          if ((*(int *)(iVar1 + 0xe8) == 0) || (*(int *)(iVar1 + 0xe8) == 2)) {

            main_dlog_004281f0(DAT_0059cd88,1,s_0__Machine_Gunners_00557f04);

            main_dlog_004281f0(DAT_0059cd88,1,s_1__Snipers_00557ef8);

            main_dlog_004281f0(DAT_0059cd88,1,s_2__Bazooka_00557eec);

            main_dlog_004281f0(DAT_0059cd88,1,s_3__Jet_Pack_00557ee0);

          }

          else {

            main_dlog_004281f0(DAT_0059cd88,1,s_0__All_Medium_00557f38);

            main_dlog_004281f0(DAT_0059cd88,1,s_1__One_Large_00557f28);

            main_dlog_004281f0(DAT_0059cd88,1,s_2__All_Large_00557f18);

          }

          dlog_push_level(&LAB_0043f7e0,&LAB_0043f7d0);

          return;

        }

        goto LAB_0043f7ab;

      }

      if (iVar4 != 0x43) {

        if (iVar4 == 0x67) {

          *(float *)(iVar1 + 0xf8) = (float)param_1;

          wredit_00439490();

          return;

        }

        if (iVar4 != 2) {

          if (iVar4 != 0x12) {

            if (iVar4 == 0x26) {

              *(int *)(iVar1 + 0xe8) = param_1;

              *(undefined4 *)(iVar1 + 0xe4) = 0;

              if (param_1 == 4) {

                iVar1 = *(int *)(DAT_0059cbd8 + 0x38);

                DAT_0059cd74 = main_dlog_00427150();

                if (*(int *)(iVar1 + 0x1e0) == 0x26) {

                  pcVar3 = s_Enter_Number_Of_Smarties_To_Spaw_00557ebc;

                }

                else {

                  pcVar3 = s_Type_Marker_ID_Number_To_Start_A_00557e98;

                }

                crt_sprintf(local_100,pcVar3);

                main_dlog_00427890(DAT_0059cd74,0,0x3f000000,0x40400000,0x88000000,local_100);

                crt_sprintf(&DAT_0059cd18,&DAT_00557088,0);

                main_dlog_00427970(DAT_0059cd74,2,0x3f000000,0x40a00000,0x88000008,&DAT_0059cd18,

                                   0x10);

                dlog_push_level(&LAB_0043e590,&LAB_0043e580);

                return;

              }

              goto LAB_0043f7ab;

            }

            if (iVar4 != 0x35) {

              if (iVar4 == 0x25) goto LAB_0043f79b;

              if ((iVar4 == 0x4a) || (iVar4 == 0x53)) goto LAB_0043f7ab;

              if ((iVar4 != 0x20) && ((iVar4 != 0x52 && (iVar4 != 0x4b)))) {

                if (iVar4 == 0x27) {

                  iVar4 = wredit_00428670(DAT_0059cd68,1,param_1);

                  if (0 < iVar4) {

                    *(int *)(iVar1 + 0xe8) = iVar4 + 1;

                    wredit_00439490();

                    return;

                  }

                }

                else if (iVar4 == 0x5c) {

                  uVar5 = wredit_00428670(DAT_0059cd68,1,param_1);

                  *(undefined4 *)(iVar1 + 0xe8) = uVar5;

                  wredit_00439490();

                  return;

                }

                goto LAB_0043f7ab;

              }

            }

          }

          param_1 = wredit_00428670(DAT_0059cd68,1,param_1);

        }

      }

    }

  }

LAB_0043f79b:

  *(undefined4 *)(iVar1 + 0xe4) = 0;

  *(int *)(iVar1 + 0xe8) = param_1;

LAB_0043f7ab:

  wredit_00439490();

  return;

}

/* ===== wredit_marker_info @ 0x0043F950 ===== */
void wredit_marker_info(void)



{

  int iVar1;

  int iVar2;

  int iVar3;

  char *pcVar4;

  int *piVar5;

  undefined1 local_100 [256];

  

  if (DAT_0059cbd8 == 0) {

    wredit_00439490();

    return;

  }

  iVar1 = *(int *)(DAT_0059cbd8 + 0x38);

  DAT_0059cd74 = main_dlog_00427150();

  iVar2 = *(int *)(iVar1 + 4);

  main_editor_00438350();

  iVar3 = 0;

  piVar5 = DAT_0059cd30;

  if (0 < DAT_0059cd34) {

    do {

      if (*piVar5 == iVar2) {

        pcVar4 = (char *)(DAT_0059cd30 + iVar3 * 9 + 1);

        goto LAB_0043f9ab;

      }

      iVar3 = iVar3 + 1;

      piVar5 = piVar5 + 9;

    } while (iVar3 < DAT_0059cd34);

  }

  pcVar4 = s__unknown__0055724c;

LAB_0043f9ab:

  crt_sprintf(local_100,s_Object_Type__d___s__005570bc,*(undefined4 *)(iVar1 + 4),pcVar4);

  main_dlog_00427890(DAT_0059cd74,0,0x3f000000,0x40400000,0x88000000,local_100);

  crt_sprintf(local_100,s_Marker_Type_ID_Misc_Misc____d__d_005580f4,*(undefined4 *)(iVar1 + 0xe8),

              *(undefined4 *)(iVar1 + 0x174),(double)*(float *)(iVar1 + 0xf8),

              (double)*(float *)(iVar1 + 0xfc));

  main_dlog_00427890(DAT_0059cd74,0,0x3f000000,0x40800000,0x88000000,local_100);

  crt_sprintf(&DAT_0059cd18,s__3_2f_005580ec,(double)*(float *)(iVar1 + 0xf8));

  main_dlog_00427970(DAT_0059cd74,2,0x3f000000,0x40a00000,0x88000008,&DAT_0059cd18,0x10);

  return;

}

/* ===== wredit_anim_update @ 0x0043FA90 ===== */
void wredit_anim_update(void)



{

  char cVar1;

  char *pcVar2;

  int iVar3;

  float10 fVar4;

  

  dlog_list_navigate_sound(DAT_0059cd74);

  if ((DAT_00632aa4._3_1_ == '\0') && (DAT_00632aad == '\0')) {

    if (DAT_00632aa8 == '\0') {

      if ((DAT_00632aaa == '\0') || (iVar3 = main_dlog_00427310(DAT_0059cd74), iVar3 != 1))

      goto LAB_0043fb02;

      iVar3 = *(int *)(DAT_0059cbd8 + 0x38);

    }

    else {

      iVar3 = *(int *)(DAT_0059cbd8 + 0x38);

    }

    fVar4 = (float10)crt_scanf_float2(&DAT_0059cd18);

    *(float *)(iVar3 + 0xf8) = (float)fVar4;

  }

  wredit_00439490();

LAB_0043fb02:

  if ((DAT_0059cd48 == (char *)0x0) || (*DAT_0059cd48 == '\0')) {

    pcVar2 = (char *)FUN_00519CF0();

    if (pcVar2 == (char *)0x0) {

      return;

    }

    if (*pcVar2 == '\0') {

      return;

    }

    if (*pcVar2 == '\b') {

      return;

    }

    iVar3 = (int)&DAT_0059cbb4 - (int)pcVar2;

    do {

      cVar1 = *pcVar2;

      pcVar2[iVar3] = cVar1;

      pcVar2 = pcVar2 + 1;

    } while (cVar1 != '\0');

    DAT_0059cd48 = &DAT_0059cbb4;

    wredit_00519c70();

  }

  iVar3 = (int)*DAT_0059cd48;

  if (iVar3 != 0) {

    DAT_0059cd48 = DAT_0059cd48 + 1;

    if ((iVar3 < 0x31) || (0x39 < iVar3)) {

      if ((iVar3 < 0x41) || (0x5a < iVar3)) {

        if (iVar3 < 0x61) {

          return;

        }

        if (0x7a < iVar3) {

          return;

        }

        iVar3 = iVar3 + -0x57;

      }

      else {

        iVar3 = iVar3 + -0x37;

      }

    }

    else {

      iVar3 = iVar3 + -0x30;

    }

    if (0 < iVar3) {

      iVar3 = *(int *)(DAT_0059cbd8 + 0x38);

      fVar4 = (float10)crt_scanf_float2(&DAT_0059cd18);

      *(float *)(iVar3 + 0xf8) = (float)fVar4;

      wredit_00439490();

      return;

    }

  }

  return;

}

/* ===== wredit_marker_info2 @ 0x0043FBC0 ===== */
void wredit_marker_info2(void)



{

  int iVar1;

  int iVar2;

  int iVar3;

  char *pcVar4;

  int *piVar5;

  undefined1 local_100 [256];

  

  if (DAT_0059cbd8 == 0) {

    wredit_00439490();

    return;

  }

  iVar1 = *(int *)(DAT_0059cbd8 + 0x38);

  DAT_0059cd78 = main_dlog_00427150();

  iVar2 = *(int *)(iVar1 + 4);

  main_editor_00438350();

  iVar3 = 0;

  piVar5 = DAT_0059cd30;

  if (0 < DAT_0059cd34) {

    do {

      if (*piVar5 == iVar2) {

        pcVar4 = (char *)(DAT_0059cd30 + iVar3 * 9 + 1);

        goto LAB_0043fc1b;

      }

      iVar3 = iVar3 + 1;

      piVar5 = piVar5 + 9;

    } while (iVar3 < DAT_0059cd34);

  }

  pcVar4 = s__unknown__0055724c;

LAB_0043fc1b:

  crt_sprintf(local_100,s_Object_Type__d___s__005570bc,*(undefined4 *)(iVar1 + 4),pcVar4);

  main_dlog_00427890(DAT_0059cd78,0,0x3f000000,0x40400000,0x88000000,local_100);

  crt_sprintf(local_100,s_Marker_Type_ID_Misc_Misc____d__d_005580f4,*(undefined4 *)(iVar1 + 0xe8),

              *(undefined4 *)(iVar1 + 0x174),(double)*(float *)(iVar1 + 0xf8),

              (double)*(float *)(iVar1 + 0xfc));

  main_dlog_00427890(DAT_0059cd78,0,0x3f000000,0x40800000,0x88000000,local_100);

  crt_sprintf(&DAT_0059cd18,s__3_2f_005580ec,(double)*(float *)(iVar1 + 0xfc));

  main_dlog_00427970(DAT_0059cd78,2,0x3f000000,0x40a00000,0x88000008,&DAT_0059cd18,0x10);

  return;

}

/* ===== wredit_obj_update @ 0x0043FD00 ===== */
void wredit_obj_update(void)



{

  char cVar1;

  char *pcVar2;

  int iVar3;

  float10 fVar4;

  

  dlog_list_navigate_sound(DAT_0059cd78);

  if ((DAT_00632aa4._3_1_ == '\0') && (DAT_00632aad == '\0')) {

    if (DAT_00632aa8 == '\0') {

      if ((DAT_00632aaa == '\0') || (iVar3 = main_dlog_00427310(DAT_0059cd78), iVar3 != 1))

      goto LAB_0043fd98;

      iVar3 = *(int *)(DAT_0059cbd8 + 0x38);

    }

    else {

      iVar3 = *(int *)(DAT_0059cbd8 + 0x38);

    }

    fVar4 = (float10)crt_scanf_float2(&DAT_0059cd18);

    *(float *)(iVar3 + 0xfc) = (float)fVar4;

    if ((*(uint *)(iVar3 + 0x1c8) & 0x20000000) != 0) {

      if (*(int *)(iVar3 + 4) == 0x44a) {

        marker_spline_adjust_buoy();

      }

      else {

        formation_update_info(iVar3);

      }

    }

  }

  wredit_00439490();

LAB_0043fd98:

  if ((DAT_0059cd48 == (char *)0x0) || (*DAT_0059cd48 == '\0')) {

    pcVar2 = (char *)FUN_00519CF0();

    if (pcVar2 == (char *)0x0) {

      return;

    }

    if (*pcVar2 == '\0') {

      return;

    }

    if (*pcVar2 == '\b') {

      return;

    }

    iVar3 = (int)&DAT_0059cbb4 - (int)pcVar2;

    do {

      cVar1 = *pcVar2;

      pcVar2[iVar3] = cVar1;

      pcVar2 = pcVar2 + 1;

    } while (cVar1 != '\0');

    DAT_0059cd48 = &DAT_0059cbb4;

    wredit_00519c70();

  }

  iVar3 = (int)*DAT_0059cd48;

  if (iVar3 != 0) {

    DAT_0059cd48 = DAT_0059cd48 + 1;

    if ((iVar3 < 0x31) || (0x39 < iVar3)) {

      if ((iVar3 < 0x41) || (0x5a < iVar3)) {

        if (iVar3 < 0x61) {

          return;

        }

        if (0x7a < iVar3) {

          return;

        }

        iVar3 = iVar3 + -0x57;

      }

      else {

        iVar3 = iVar3 + -0x37;

      }

    }

    else {

      iVar3 = iVar3 + -0x30;

    }

    if (0 < iVar3) {

      iVar3 = *(int *)(DAT_0059cbd8 + 0x38);

      fVar4 = (float10)crt_scanf_float2(&DAT_0059cd18);

      *(float *)(iVar3 + 0xfc) = (float)fVar4;

      if ((*(uint *)(iVar3 + 0x1c8) & 0x20000000) != 0) {

        if (*(int *)(iVar3 + 4) == 0x44a) {

          marker_spline_adjust_buoy();

          wredit_00439490();

          return;

        }

        formation_update_info(iVar3);

      }

      wredit_00439490();

      return;

    }

  }

  return;

}

/* ===== wredit_trigger_menu @ 0x0043FE90 ===== */
void wredit_trigger_menu(void)



{

  int iVar1;

  int iVar2;

  int iVar3;

  char *pcVar4;

  undefined4 uVar5;

  int *piVar6;

  undefined8 uVar7;

  undefined8 uVar8;

  undefined1 *puVar10;

  undefined8 uVar9;

  undefined8 uVar11;

  undefined1 local_108 [260];

  

  if (DAT_0059cbd8 == 0) {

    wredit_00439490();

    return;

  }

  iVar1 = *(int *)(DAT_0059cbd8 + 0x38);

  DAT_0059cd7c = main_dlog_00427150();

  main_dlog_004273b0(DAT_0059cd7c,0,0x3f000000,0x3f800000,0x88000000,s_Object_Information_00557498);

  iVar2 = *(int *)(iVar1 + 4);

  main_editor_00438350();

  iVar3 = 0;

  piVar6 = DAT_0059cd30;

  if (0 < DAT_0059cd34) {

    do {

      if (*piVar6 == iVar2) {

        pcVar4 = (char *)(DAT_0059cd30 + iVar3 * 9 + 1);

        goto LAB_0043ff15;

      }

      iVar3 = iVar3 + 1;

      piVar6 = piVar6 + 9;

    } while (iVar3 < DAT_0059cd34);

  }

  pcVar4 = s__unknown__0055724c;

LAB_0043ff15:

  crt_sprintf(local_108,s_Object_Type__d___s__005570bc,*(undefined4 *)(iVar1 + 4),pcVar4);

  main_dlog_00427890(DAT_0059cd7c,0,0x3f000000,0x40400000,0x88000000,local_108);

  crt_sprintf(local_108,s_Location___1f___1f___1f_Directio_0055743c,(double)*(float *)(iVar1 + 0xa0)

              ,(double)*(float *)(iVar1 + 0xa4),(double)*(float *)(iVar1 + 0xa8),

              (double)*(float *)(iVar1 + 200),(double)*(float *)(iVar1 + 0xcc),

              (double)*(float *)(iVar1 + 0xd0));

  main_dlog_00427890(DAT_0059cd7c,0,0x3f000000,0x40800000,0x88000000,local_108);

  puVar10 = local_108;

  uVar11 = CONCAT44(*(undefined4 *)(iVar1 + 0xe8),s_AI_Mode__d_00557430);

  crt_sprintf();

  uVar9 = CONCAT44(puVar10,local_108);

  uVar8 = 0x8800000040a00000;

  uVar7 = 0x3f00000000000000;

  uVar5 = DAT_0059cd7c;

  main_dlog_00427890();

  uVar5 = mission_trigger_name(iVar1,uVar5,uVar7,uVar8,uVar9,uVar11);

  main_dlog_00427890(DAT_0059cd7c,0,0x3f000000,0x40c00000,0x88000000,uVar5);

  uVar8 = 0x8800002240e00000;

  uVar7 = 0x3f00000000000001;

  uVar5 = DAT_0059cd7c;

  main_dlog_00427e80();

  main_dlog_004281f0(DAT_0059cd7c,1,s_1__No_Trigger_0055818c,uVar5,uVar7,uVar8);

  uVar7 = 0x55817400000001;

  uVar5 = DAT_0059cd7c;

  main_dlog_004281f0();

  main_dlog_004281f0(DAT_0059cd7c,1,s_3__Death_Trigger_00558160,uVar5,uVar7);

  main_dlog_004281f0(DAT_0059cd7c,1,s_4__Destination_Trigger_00558148);

  main_dlog_004281f0();

  return;

}

