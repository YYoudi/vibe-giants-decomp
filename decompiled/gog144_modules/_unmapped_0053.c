/* Giants 1.449 — module _unmapped_0053
 * 179 functions (6 named) — decompiled, names from PS2 symbols
 * Original source: C:\Giants\source\_unmapped_0053.c(pp) (assert-string evidence)
 */

/* ===== FUN_00530010 @ 0x00530010 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_00530010(undefined1 param_1,undefined4 param_2,int param_3,int param_4,undefined4 *param_5)



{

  undefined4 *puVar1;

  int iVar2;

  undefined4 uVar3;

  

  iVar2 = FUN_0052aa70();

  if (iVar2 == 0) {

    return;

  }

  if ((0x3ff < (int)((int)DAT_005dfed8 + -0x5dfec1)) && (iVar2 = FUN_0052aa70(), iVar2 != 0)) {

    iVar2 = FUN_0052c5c0();

    if (iVar2 == 0) {

      if ((DAT_005dfed8 == &DAT_005dfedc) && (DAT_005e2310 == &DAT_005e2314)) {

        if (DAT_006328e8 < _DAT_005e2718 + 1.5) goto LAB_005300f8;

        DAT_005e2314._0_1_ = 0x16;

        DAT_005e2310 = (undefined4 *)((int)&DAT_005e2314 + 1);

      }

      *(undefined1 *)DAT_005dfed8 = 0;

      DAT_005dfed8 = (undefined4 *)((int)DAT_005dfed8 + 1);

      *(undefined1 *)DAT_005e2310 = 0;

      DAT_005e2310 = (undefined4 *)((int)DAT_005e2310 + 1);

      if (1 < (int)DAT_005dfed8 + -0x5dfedc) {

        FUN_0052b8c0((undefined1 *)((int)DAT_005dfed8 + -0x5dfedc),&DAT_005dfedc);

      }

      if (1 < (int)DAT_005e2310 + -0x5e2314) {

        FUN_0052ba30((undefined1 *)((int)DAT_005e2310 + -0x5e2314),&DAT_005e2314);

      }

      DAT_005dfed8 = &DAT_005dfedc;

      DAT_005e2310 = &DAT_005e2314;

    }

    else {

      FUN_005354c0();

    }

  }

LAB_005300f8:

  puVar1 = DAT_005dfed8;

  *DAT_005dfed8 = 0;

  *(undefined1 *)puVar1 = 0xd;

  *(undefined4 *)((int)puVar1 + 6) = *(undefined4 *)(param_3 + 0x188);

  if (param_4 == 0) {

    uVar3 = 0;

  }

  else {

    uVar3 = *(undefined4 *)(param_4 + 0x188);

  }

  *(undefined4 *)((int)puVar1 + 2) = uVar3;

  if (param_5 == (undefined4 *)0x0) {

    *(undefined4 *)((int)puVar1 + 10) = *(undefined4 *)(param_3 + 0xa0);

    *(undefined4 *)((int)puVar1 + 0xe) = *(undefined4 *)(param_3 + 0xa4);

    *(undefined4 *)((int)puVar1 + 0x12) = *(undefined4 *)(param_3 + 0xa8);

  }

  else {

    *(undefined4 *)((int)puVar1 + 10) = *param_5;

    *(undefined4 *)((int)puVar1 + 0xe) = param_5[1];

    *(undefined4 *)((int)puVar1 + 0x12) = param_5[2];

  }

  *(undefined1 *)((int)puVar1 + 1) = param_1;

  *(undefined4 *)((int)puVar1 + 0x16) = param_2;

  DAT_005dfed8 = (undefined4 *)((int)DAT_005dfed8 + 0x1a);

  return;

}

/* ===== FUN_00530180 @ 0x00530180 ===== */
void FUN_00530180(int param_1)



{

  int iVar1;

  int iVar2;

  int iVar3;

  undefined4 uVar4;

  float10 fVar5;

  undefined4 local_18;

  undefined4 local_14;

  undefined4 local_10;

  undefined4 local_c;

  undefined4 local_8;

  undefined1 local_4;

  undefined1 uStack_3;

  

  iVar1 = FUN_0052aa70();

  if (((iVar1 != 0) && (iVar2 = FUN_0052c5c0(), iVar1 = DAT_00632f34, iVar2 != 0)) &&

     (iVar2 = 0, 0 < DAT_00632f34)) {

    do {

      iVar3 = FUN_0052ab00(iVar2);

      if (iVar3 != 0) {

        uVar4 = FUN_0052ab50(iVar2);

        local_14 = 0;

        local_10 = 0;

        local_c = 0;

        local_8 = 0;

        local_4 = 0;

        uStack_3 = 0;

        local_18._0_2_ = CONCAT11((char)iVar2,0x40);

        local_18 = (uint)(ushort)local_18;

        fVar5 = (float10)FUN_0052afc0(iVar2);

        local_14._1_3_ = SUB43((float)fVar5,0);

        local_10._0_1_ = (undefined1)((uint)(float)fVar5 >> 0x18);

        local_18._0_3_ = CONCAT12((char)uVar4,(ushort)local_18);

        fVar5 = (float10)FUN_0052af80(uVar4);

        local_10._1_3_ = SUB43((float)fVar5,0);

        local_c._0_1_ = (undefined1)((uint)(float)fVar5 >> 0x18);

        local_18 = CONCAT13((char)iVar2,(undefined3)local_18);

        fVar5 = (float10)FUN_0052afe0(iVar2);

        local_c._1_3_ = SUB43((float)fVar5,0);

        local_8._0_1_ = (undefined1)((uint)(float)fVar5 >> 0x18);

        local_14 = CONCAT31(local_14._1_3_,(char)uVar4);

        fVar5 = (float10)FUN_0052afa0(uVar4);

        local_8._1_3_ = SUB43((float)fVar5,0);

        local_4 = (undefined1)((uint)(float)fVar5 >> 0x18);

        uStack_3 = 0;

        if (param_1 == 0) {

          FUN_0052b780(0,0x16,&local_18);

        }

        else {

          FUN_0052b4e0(param_1,0x16,&local_18);

        }

      }

      iVar2 = iVar2 + 1;

    } while (iVar2 < iVar1);

  }

  return;

}

/* ===== FUN_00530270 @ 0x00530270 ===== */
void FUN_00530270(undefined4 *param_1)



{

  float fVar1;

  char cVar2;

  undefined1 uVar3;

  int iVar4;

  undefined4 *puVar5;

  float10 fVar6;

  undefined4 local_18;

  char local_14;

  undefined1 uStack_13;

  undefined1 uStack_12;

  undefined1 uStack_11;

  undefined4 local_10;

  undefined4 local_c;

  undefined4 local_8;

  undefined1 local_4;

  undefined1 uStack_3;

  

  iVar4 = FUN_0052aa70();

  if (iVar4 != 0) {

    iVar4 = FUN_0052c5c0();

    if (iVar4 != 0) {

      cVar2 = *(char *)((int)param_1 + 1);

      if (cVar2 != -1) {

        if ((cVar2 == *(char *)((int)param_1 + 3)) ||

           ((*(char *)((int)param_1 + 2) != -1 &&

            (*(char *)((int)param_1 + 2) == *(char *)(param_1 + 1))))) {

          fVar6 = (float10)FUN_0052afc0(cVar2);

          fVar6 = fVar6 - (float10)*(float *)((int)param_1 + 5);

          uVar3 = *(undefined1 *)((int)param_1 + 1);

        }

        else {

          fVar6 = (float10)FUN_0052afc0(cVar2);

          fVar6 = fVar6 + (float10)*(float *)((int)param_1 + 5);

          uVar3 = *(undefined1 *)((int)param_1 + 1);

        }

        FUN_0052b240(uVar3,(float)fVar6);

      }

      cVar2 = *(char *)((int)param_1 + 2);

      if (cVar2 != -1) {

        if (((*(char *)((int)param_1 + 1) == -1) ||

            (*(char *)((int)param_1 + 1) != *(char *)((int)param_1 + 3))) &&

           (cVar2 != *(char *)(param_1 + 1))) {

          fVar6 = (float10)FUN_0052af80(cVar2);

          fVar6 = fVar6 + (float10)*(float *)((int)param_1 + 9);

          uVar3 = *(undefined1 *)((int)param_1 + 2);

        }

        else {

          fVar6 = (float10)FUN_0052af80(cVar2);

          fVar6 = fVar6 - (float10)*(float *)((int)param_1 + 9);

          uVar3 = *(undefined1 *)((int)param_1 + 2);

        }

        FUN_0052b200(uVar3,(float)fVar6);

      }

      if (*(char *)((int)param_1 + 3) != -1) {

        fVar6 = (float10)FUN_0052afe0(*(char *)((int)param_1 + 3));

        FUN_0052b260(*(undefined1 *)((int)param_1 + 3),

                     (float)(fVar6 + (float10)*(float *)((int)param_1 + 0xd)));

      }

      if (*(char *)(param_1 + 1) != -1) {

        fVar6 = (float10)FUN_0052afa0(*(char *)(param_1 + 1));

        FUN_0052b220(*(undefined1 *)(param_1 + 1),

                     (float)(fVar6 + (float10)*(float *)((int)param_1 + 0x11)));

      }

      local_18._1_1_ = '\0';

      local_18._2_1_ = '\0';

      local_18._3_1_ = '\0';

      local_14 = '\0';

      uStack_13 = 0;

      uStack_12 = 0;

      uStack_11 = 0;

      local_10 = 0;

      local_c = 0;

      local_8 = 0;

      local_4 = 0;

      uStack_3 = 0;

      puVar5 = &local_18;

      for (iVar4 = 5; iVar4 != 0; iVar4 = iVar4 + -1) {

        *puVar5 = *param_1;

        param_1 = param_1 + 1;

        puVar5 = puVar5 + 1;

      }

      *(undefined1 *)puVar5 = *(undefined1 *)param_1;

      local_18._0_1_ = 0x40;

      if (local_18._1_1_ != -1) {

        fVar6 = (float10)FUN_0052afc0(local_18._1_1_);

        fVar1 = (float)fVar6;

        uStack_13 = SUB41(fVar1,0);

        uStack_12 = (undefined1)((uint)fVar1 >> 8);

        uStack_11 = (undefined1)((uint)fVar1 >> 0x10);

        local_10._0_1_ = (undefined1)((uint)fVar1 >> 0x18);

      }

      if (local_18._2_1_ != -1) {

        fVar6 = (float10)FUN_0052af80(local_18._2_1_);

        local_10._1_3_ = SUB43((float)fVar6,0);

        local_c._0_1_ = (undefined1)((uint)(float)fVar6 >> 0x18);

      }

      if (local_18._3_1_ != -1) {

        fVar6 = (float10)FUN_0052afe0(local_18._3_1_);

        local_c._1_3_ = SUB43((float)fVar6,0);

        local_8._0_1_ = (undefined1)((uint)(float)fVar6 >> 0x18);

      }

      if (local_14 != -1) {

        fVar6 = (float10)FUN_0052afa0(local_14);

        local_8._1_3_ = SUB43((float)fVar6,0);

        local_4 = (undefined1)((uint)(float)fVar6 >> 0x18);

      }

      uStack_3 = 0;

      FUN_0052b780(0,0x16,&local_18);

    }

  }

  return;

}

/* ===== FUN_00530430 @ 0x00530430 ===== */
void FUN_00530430(int param_1,int param_2,int param_3,int param_4,undefined4 param_5,

                 undefined4 param_6,undefined4 param_7,undefined4 param_8)



{

  int iVar1;

  undefined1 local_18 [2];

  undefined1 uStack_16;

  undefined1 uStack_15;

  undefined1 local_14;

  undefined3 uStack_13;

  undefined4 local_10;

  undefined4 local_c;

  undefined4 local_8;

  undefined1 local_4;

  undefined1 uStack_3;

  

  iVar1 = FUN_0052aa70();

  if (iVar1 != 0) {

    if ((param_1 == 0) && ((param_3 == 0 || (param_3 == param_4)))) {

      param_1 = param_2;

      param_3 = param_4;

    }

    if (param_1 == 0) {

      local_18 = (undefined1  [2])0xff3f;

    }

    else {

      local_18[1] = *(undefined1 *)(param_1 + 0x188);

      local_18[0] = 0x3f;

    }

    _local_18 = (uint3)(ushort)local_18;

    if (param_2 == 0) {

      _local_18 = CONCAT13(0xff,_local_18);

    }

    else {

      _local_18 = CONCAT13(*(undefined1 *)(param_2 + 0x188),_local_18);

    }

    _local_18 = CONCAT12((char)param_3,local_18);

    if (param_3 == 0) {

      _local_18 = CONCAT12(0xff,local_18);

    }

    local_14 = (undefined1)param_4;

    if (param_4 == 0) {

      local_14 = 0xff;

    }

    uStack_13 = (undefined3)param_5;

    local_10._1_3_ = (undefined3)param_6;

    local_10 = CONCAT31(local_10._1_3_,(char)((uint)param_5 >> 0x18));

    local_c._1_3_ = (undefined3)param_7;

    local_c = CONCAT31(local_c._1_3_,(char)((uint)param_6 >> 0x18));

    local_8._1_3_ = (undefined3)param_8;

    local_8 = CONCAT31(local_8._1_3_,(char)((uint)param_7 >> 0x18));

    local_4 = (undefined1)((uint)param_8 >> 0x18);

    uStack_3 = 0;

    iVar1 = FUN_0052c5c0();

    if (iVar1 != 0) {

      FUN_00530270(local_18);

      return;

    }

    FUN_0052b8c0(0x16,local_18);

  }

  return;

}

/* ===== FUN_00530520 @ 0x00530520 ===== */
void FUN_00530520(int param_1,int param_2,int param_3)



{

  char cVar1;

  byte bVar2;

  char *pcVar3;

  char *pcVar4;

  byte *pbVar5;

  byte *pbVar6;

  int iVar7;

  undefined4 uVar8;

  int iVar9;

  uint uVar10;

  byte *pbVar11;

  uint uVar12;

  char *pcVar13;

  char *pcVar14;

  byte *pbVar15;

  bool bVar16;

  byte local_300 [256];

  char local_200 [512];

  

  if (param_1 == 0) {

    param_1 = param_2;

  }

  if (param_2 == 0) {

    return;

  }

  uVar10 = *(uint *)(param_1 + 0x188) & 0xff;

  uVar12 = *(uint *)(param_2 + 0x188) & 0xff;

  pcVar3 = (char *)FUN_0052adf0(uVar10);

  pcVar4 = (char *)FUN_0052adf0(uVar12);

  if (uVar10 == uVar12) {

    if ((-1 < param_3) && (param_3 < 0x45)) {

      pbVar5 = (byte *)TextGetPtrRandom((&PTR_s_SuChatMissile_0057f3a8)[param_3]);

      pbVar11 = (&PTR_s_SuChatMissile_0057f3a8)[param_3];

      pbVar6 = pbVar5;

      do {

        bVar2 = *pbVar6;

        bVar16 = bVar2 < *pbVar11;

        if (bVar2 != *pbVar11) {

LAB_005305d4:

          iVar7 = (1 - (uint)bVar16) - (uint)(bVar16 != 0);

          goto LAB_005305d9;

        }

        if (bVar2 == 0) break;

        bVar2 = pbVar6[1];

        bVar16 = bVar2 < pbVar11[1];

        if (bVar2 != pbVar11[1]) goto LAB_005305d4;

        pbVar6 = pbVar6 + 2;

        pbVar11 = pbVar11 + 2;

      } while (bVar2 != 0);

      iVar7 = 0;

LAB_005305d9:

      if (iVar7 != 0) {

        pbVar11 = local_300;

        for (iVar7 = 0x40; iVar7 != 0; iVar7 = iVar7 + -1) {

          pbVar11[0] = 0;

          pbVar11[1] = 0;

          pbVar11[2] = 0;

          pbVar11[3] = 0;

          pbVar11 = pbVar11 + 4;

        }

        uVar10 = 0xffffffff;

        iVar7 = 0;

        pbVar11 = pbVar5;

        do {

          if (uVar10 == 0) break;

          uVar10 = uVar10 - 1;

          bVar2 = *pbVar11;

          pbVar11 = pbVar11 + 1;

        } while (bVar2 != 0);

        pbVar11 = local_300;

        if (0 < (int)(~uVar10 - 1)) {

          do {

            if ((pbVar5[iVar7] == 0x25) &&

               ((pbVar5[iVar7 + 1] == 0x76 || (pbVar5[iVar7 + 1] == 0x6b)))) {

              uVar10 = 0xffffffff;

              pcVar4 = pcVar3;

              do {

                pcVar13 = pcVar4;

                if (uVar10 == 0) break;

                uVar10 = uVar10 - 1;

                pcVar13 = pcVar4 + 1;

                cVar1 = *pcVar4;

                pcVar4 = pcVar13;

              } while (cVar1 != '\0');

              uVar10 = ~uVar10;

              iVar9 = -1;

              pbVar6 = pbVar11;

              do {

                pbVar15 = pbVar6;

                if (iVar9 == 0) break;

                iVar9 = iVar9 + -1;

                pbVar15 = pbVar6 + 1;

                bVar2 = *pbVar6;

                pbVar6 = pbVar15;

              } while (bVar2 != 0);

              pbVar6 = (byte *)(pcVar13 + -uVar10);

              pbVar15 = pbVar15 + -1;

              for (uVar12 = uVar10 >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {

                *(undefined4 *)pbVar15 = *(undefined4 *)pbVar6;

                pbVar6 = pbVar6 + 4;

                pbVar15 = pbVar15 + 4;

              }

              for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {

                *pbVar15 = *pbVar6;

                pbVar6 = pbVar6 + 1;

                pbVar15 = pbVar15 + 1;

              }

              uVar10 = 0xffffffff;

              pcVar4 = pcVar3;

              do {

                if (uVar10 == 0) break;

                uVar10 = uVar10 - 1;

                cVar1 = *pcVar4;

                pcVar4 = pcVar4 + 1;

              } while (cVar1 != '\0');

              pbVar11 = pbVar11 + (~uVar10 - 1);

              iVar7 = iVar7 + 1;

            }

            else {

              *pbVar11 = pbVar5[iVar7];

              pbVar11 = pbVar11 + 1;

            }

            uVar10 = 0xffffffff;

            iVar7 = iVar7 + 1;

            pbVar6 = pbVar5;

            do {

              if (uVar10 == 0) break;

              uVar10 = uVar10 - 1;

              bVar2 = *pbVar6;

              pbVar6 = pbVar6 + 1;

            } while (bVar2 != 0);

          } while (iVar7 < (int)(~uVar10 - 1));

        }

        goto LAB_005307f3;

      }

    }

    uVar8 = TextGetPtrRandom(s_MPChSuicide_0057fe44);

    FUN_00542f27(local_300,uVar8,pcVar3);

  }

  else {

    if ((-1 < param_3) && (param_3 < 0x45)) {

      pbVar5 = (byte *)TextGetPtrRandom((&PTR_s_DChatMissile_0057f290)[param_3]);

      pbVar11 = (&PTR_s_DChatMissile_0057f290)[param_3];

      pbVar6 = pbVar5;

      do {

        bVar2 = *pbVar6;

        bVar16 = bVar2 < *pbVar11;

        if (bVar2 != *pbVar11) {

LAB_005306f4:

          iVar7 = (1 - (uint)bVar16) - (uint)(bVar16 != 0);

          goto LAB_005306f9;

        }

        if (bVar2 == 0) break;

        bVar2 = pbVar6[1];

        bVar16 = bVar2 < pbVar11[1];

        if (bVar2 != pbVar11[1]) goto LAB_005306f4;

        pbVar6 = pbVar6 + 2;

        pbVar11 = pbVar11 + 2;

      } while (bVar2 != 0);

      iVar7 = 0;

LAB_005306f9:

      if (iVar7 != 0) {

        pbVar11 = local_300;

        for (iVar7 = 0x40; iVar7 != 0; iVar7 = iVar7 + -1) {

          pbVar11[0] = 0;

          pbVar11[1] = 0;

          pbVar11[2] = 0;

          pbVar11[3] = 0;

          pbVar11 = pbVar11 + 4;

        }

        uVar10 = 0xffffffff;

        iVar7 = 0;

        pbVar11 = pbVar5;

        do {

          if (uVar10 == 0) break;

          uVar10 = uVar10 - 1;

          bVar2 = *pbVar11;

          pbVar11 = pbVar11 + 1;

        } while (bVar2 != 0);

        pbVar11 = local_300;

        if (0 < (int)(~uVar10 - 1)) {

          do {

            if (pbVar5[iVar7] == 0x25) {

              if (pbVar5[iVar7 + 1] == 0x76) {

                uVar10 = 0xffffffff;

                pcVar13 = pcVar4;

                do {

                  pcVar14 = pcVar13;

                  if (uVar10 == 0) break;

                  uVar10 = uVar10 - 1;

                  pcVar14 = pcVar13 + 1;

                  cVar1 = *pcVar13;

                  pcVar13 = pcVar14;

                } while (cVar1 != '\0');

                uVar10 = ~uVar10;

                iVar9 = -1;

                pbVar6 = pbVar11;

                do {

                  pbVar15 = pbVar6;

                  if (iVar9 == 0) break;

                  iVar9 = iVar9 + -1;

                  pbVar15 = pbVar6 + 1;

                  bVar2 = *pbVar6;

                  pbVar6 = pbVar15;

                } while (bVar2 != 0);

                pbVar6 = (byte *)(pcVar14 + -uVar10);

                pbVar15 = pbVar15 + -1;

                for (uVar12 = uVar10 >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {

                  *(undefined4 *)pbVar15 = *(undefined4 *)pbVar6;

                  pbVar6 = pbVar6 + 4;

                  pbVar15 = pbVar15 + 4;

                }

                for (uVar10 = uVar10 & 3; pcVar13 = pcVar4, uVar10 != 0; uVar10 = uVar10 - 1) {

                  *pbVar15 = *pbVar6;

                  pbVar6 = pbVar6 + 1;

                  pbVar15 = pbVar15 + 1;

                }

              }

              else {

                if (pbVar5[iVar7 + 1] != 0x6b) goto LAB_005307b6;

                uVar10 = 0xffffffff;

                pcVar13 = pcVar3;

                do {

                  pcVar14 = pcVar13;

                  if (uVar10 == 0) break;

                  uVar10 = uVar10 - 1;

                  pcVar14 = pcVar13 + 1;

                  cVar1 = *pcVar13;

                  pcVar13 = pcVar14;

                } while (cVar1 != '\0');

                uVar10 = ~uVar10;

                iVar9 = -1;

                pbVar6 = pbVar11;

                do {

                  pbVar15 = pbVar6;

                  if (iVar9 == 0) break;

                  iVar9 = iVar9 + -1;

                  pbVar15 = pbVar6 + 1;

                  bVar2 = *pbVar6;

                  pbVar6 = pbVar15;

                } while (bVar2 != 0);

                pbVar6 = (byte *)(pcVar14 + -uVar10);

                pbVar15 = pbVar15 + -1;

                for (uVar12 = uVar10 >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {

                  *(undefined4 *)pbVar15 = *(undefined4 *)pbVar6;

                  pbVar6 = pbVar6 + 4;

                  pbVar15 = pbVar15 + 4;

                }

                for (uVar10 = uVar10 & 3; pcVar13 = pcVar3, uVar10 != 0; uVar10 = uVar10 - 1) {

                  *pbVar15 = *pbVar6;

                  pbVar6 = pbVar6 + 1;

                  pbVar15 = pbVar15 + 1;

                }

              }

              uVar10 = 0xffffffff;

              do {

                if (uVar10 == 0) break;

                uVar10 = uVar10 - 1;

                cVar1 = *pcVar13;

                pcVar13 = pcVar13 + 1;

              } while (cVar1 != '\0');

              pbVar11 = pbVar11 + (~uVar10 - 1);

              iVar7 = iVar7 + 1;

            }

            else {

LAB_005307b6:

              *pbVar11 = pbVar5[iVar7];

              pbVar11 = pbVar11 + 1;

            }

            uVar10 = 0xffffffff;

            iVar7 = iVar7 + 1;

            pbVar6 = pbVar5;

            do {

              if (uVar10 == 0) break;

              uVar10 = uVar10 - 1;

              bVar2 = *pbVar6;

              pbVar6 = pbVar6 + 1;

            } while (bVar2 != 0);

          } while (iVar7 < (int)(~uVar10 - 1));

        }

        goto LAB_005307f3;

      }

    }

    uVar8 = TextGetPtrRandom(s_MPChKilled_0057fe38);

    FUN_00542f27(local_300,uVar8,pcVar4,pcVar3);

  }

LAB_005307f3:

  iVar7 = FUN_0052aa70();

  if (iVar7 == 0) {

    FUN_005362d0(local_300,1);

    return;

  }

  uVar8 = FUN_0052aad0();

  iVar7 = FUN_0052ab20(uVar8);

  if ((-1 < iVar7) && (iVar7 <= DAT_00632f34 + -1)) {

    pcVar3 = local_200;

    for (iVar9 = 0x80; iVar9 != 0; iVar9 = iVar9 + -1) {

      pcVar3[0] = '\0';

      pcVar3[1] = '\0';

      pcVar3[2] = '\0';

      pcVar3[3] = '\0';

      pcVar3 = pcVar3 + 4;

    }

    uVar10 = 0xffffffff;

    local_200[1] = (byte)iVar7 | 0x80;

    local_200[3] = 0;

    local_200[0] = '<';

    local_200[2] = 0x81;

    pbVar11 = local_300;

    do {

      pbVar6 = pbVar11;

      if (uVar10 == 0) break;

      uVar10 = uVar10 - 1;

      pbVar6 = pbVar11 + 1;

      bVar2 = *pbVar11;

      pbVar11 = pbVar6;

    } while (bVar2 != 0);

    uVar10 = ~uVar10;

    iVar7 = -1;

    pcVar3 = local_200;

    do {

      pcVar4 = pcVar3;

      if (iVar7 == 0) break;

      iVar7 = iVar7 + -1;

      pcVar4 = pcVar3 + 1;

      cVar1 = *pcVar3;

      pcVar3 = pcVar4;

    } while (cVar1 != '\0');

    pbVar11 = pbVar6 + -uVar10;

    pbVar6 = (byte *)(pcVar4 + -1);

    for (uVar12 = uVar10 >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {

      *(undefined4 *)pbVar6 = *(undefined4 *)pbVar11;

      pbVar11 = pbVar11 + 4;

      pbVar6 = pbVar6 + 4;

    }

    for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {

      *pbVar6 = *pbVar11;

      pbVar11 = pbVar11 + 1;

      pbVar6 = pbVar6 + 1;

    }

    FUN_0052e6e0(local_200,0);

  }

  return;

}

/* ===== FUN_005308b0 @ 0x005308B0 ===== */
void FUN_005308b0(undefined4 param_1,int param_2)



{

  char cVar1;

  undefined4 uVar2;

  undefined4 uVar3;

  int iVar4;

  int iVar5;

  uint uVar6;

  uint uVar7;

  char *pcVar8;

  char *pcVar9;

  char *pcVar10;

  undefined1 local_2f0 [40];

  char local_2c8 [200];

  char local_200 [512];

  

  if (param_2 != 0) {

    uVar6 = *(uint *)(param_2 + 0x188);

    uVar2 = FUN_0052ab90(param_1);

    uVar2 = FUN_00507b00(s_CommShowConnHTeam_0057e2d8,uVar2);

    FUN_00542f27(local_2f0,s__s__s_0055c280,uVar2);

    uVar2 = FUN_0052adf0(uVar6 & 0xff);

    uVar3 = TextGetPtrRandom(s_MPChKilled_0057fe38);

    FUN_00542f27(local_2c8,uVar3,uVar2,local_2f0);

    iVar4 = FUN_0052aa70();

    if (iVar4 == 0) {

      FUN_005362d0(local_2c8,1);

      return;

    }

    uVar2 = FUN_0052aad0();

    iVar4 = FUN_0052ab20(uVar2);

    if ((-1 < iVar4) && (iVar4 <= DAT_00632f34 + -1)) {

      pcVar8 = local_200;

      for (iVar5 = 0x80; iVar5 != 0; iVar5 = iVar5 + -1) {

        pcVar8[0] = '\0';

        pcVar8[1] = '\0';

        pcVar8[2] = '\0';

        pcVar8[3] = '\0';

        pcVar8 = pcVar8 + 4;

      }

      uVar6 = 0xffffffff;

      local_200[1] = (byte)iVar4 | 0x80;

      local_200[3] = 0;

      local_200[0] = '<';

      local_200[2] = 0x81;

      pcVar8 = local_2c8;

      do {

        pcVar10 = pcVar8;

        if (uVar6 == 0) break;

        uVar6 = uVar6 - 1;

        pcVar10 = pcVar8 + 1;

        cVar1 = *pcVar8;

        pcVar8 = pcVar10;

      } while (cVar1 != '\0');

      uVar6 = ~uVar6;

      iVar4 = -1;

      pcVar8 = local_200;

      do {

        pcVar9 = pcVar8;

        if (iVar4 == 0) break;

        iVar4 = iVar4 + -1;

        pcVar9 = pcVar8 + 1;

        cVar1 = *pcVar8;

        pcVar8 = pcVar9;

      } while (cVar1 != '\0');

      pcVar8 = pcVar10 + -uVar6;

      pcVar10 = pcVar9 + -1;

      for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {

        *(undefined4 *)pcVar10 = *(undefined4 *)pcVar8;

        pcVar8 = pcVar8 + 4;

        pcVar10 = pcVar10 + 4;

      }

      for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {

        *pcVar10 = *pcVar8;

        pcVar8 = pcVar8 + 1;

        pcVar10 = pcVar10 + 1;

      }

      FUN_0052e6e0(local_200,0);

    }

  }

  return;

}

/* ===== rpman_move @ 0x005309E0 ===== */
void rpman_move(int param_1,int param_2)



{

  char cVar1;

  int iVar2;

  undefined4 uVar3;

  undefined4 uVar4;

  int iVar5;

  uint uVar6;

  uint uVar7;

  char *pcVar8;

  char *pcVar9;

  char *pcVar10;

  char local_2c8 [200];

  char local_200 [512];

  

  if ((param_1 != 0) && (0 < param_2)) {

    iVar2 = FUN_0052b400();

    if (param_2 <= iVar2) {

      uVar3 = FUN_0052adf0(*(uint *)(param_1 + 0x188) & 0xff);

      pcVar8 = s_Borjoyzee_0055b3c0;

      if (param_2 != 1) {

        pcVar8 = &DAT_0055b3bc;

      }

      uVar4 = TextGetPtrRandom(s_MPChFlagCap_0057fe50);

      FUN_00542f27(local_2c8,uVar4,uVar3,pcVar8);

      iVar2 = FUN_0052aa70();

      if (iVar2 == 0) {

        FUN_005362d0(local_2c8,1);

        return;

      }

      uVar3 = FUN_0052aad0();

      iVar2 = FUN_0052ab20(uVar3);

      if ((-1 < iVar2) && (iVar2 <= DAT_00632f34 + -1)) {

        pcVar8 = local_200;

        for (iVar5 = 0x80; iVar5 != 0; iVar5 = iVar5 + -1) {

          pcVar8[0] = '\0';

          pcVar8[1] = '\0';

          pcVar8[2] = '\0';

          pcVar8[3] = '\0';

          pcVar8 = pcVar8 + 4;

        }

        uVar6 = 0xffffffff;

        local_200[1] = (byte)iVar2 | 0x80;

        local_200[3] = 0;

        local_200[0] = '<';

        local_200[2] = 0x81;

        pcVar8 = local_2c8;

        do {

          pcVar10 = pcVar8;

          if (uVar6 == 0) break;

          uVar6 = uVar6 - 1;

          pcVar10 = pcVar8 + 1;

          cVar1 = *pcVar8;

          pcVar8 = pcVar10;

        } while (cVar1 != '\0');

        uVar6 = ~uVar6;

        iVar2 = -1;

        pcVar8 = local_200;

        do {

          pcVar9 = pcVar8;

          if (iVar2 == 0) break;

          iVar2 = iVar2 + -1;

          pcVar9 = pcVar8 + 1;

          cVar1 = *pcVar8;

          pcVar8 = pcVar9;

        } while (cVar1 != '\0');

        pcVar8 = pcVar10 + -uVar6;

        pcVar10 = pcVar9 + -1;

        for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {

          *(undefined4 *)pcVar10 = *(undefined4 *)pcVar8;

          pcVar8 = pcVar8 + 4;

          pcVar10 = pcVar10 + 4;

        }

        for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {

          *pcVar10 = *pcVar8;

          pcVar8 = pcVar8 + 1;

          pcVar10 = pcVar10 + 1;

        }

        FUN_0052e6e0(local_200,0);

      }

    }

  }

  return;

}

/* ===== FUN_00530b10 @ 0x00530B10 ===== */
void FUN_00530b10(int param_1)



{

  int iVar1;

  undefined1 local_8;

  undefined3 uStack_7;

  undefined1 local_4;

  undefined1 uStack_3;

  

  iVar1 = FUN_0052aa70();

  if (iVar1 != 0) {

    _local_8 = CONCAT31((int3)*(undefined4 *)(param_1 + 0x188),10);

    local_4 = (undefined1)((uint)*(undefined4 *)(param_1 + 0x188) >> 0x18);

    uStack_3 = 0;

    iVar1 = FUN_0052c5c0();

    if (iVar1 != 0) {

      FUN_0052b780(0,6,&local_8);

      return;

    }

    FUN_0052b8c0(6,&local_8);

  }

  return;

}

/* ===== FUN_00530b70 @ 0x00530B70 ===== */
void FUN_00530b70(int param_1)



{

  int iVar1;

  undefined1 local_8;

  undefined3 uStack_7;

  undefined1 local_4;

  undefined1 uStack_3;

  

  iVar1 = FUN_0052aa70();

  if (iVar1 != 0) {

    _local_8 = CONCAT31((int3)*(undefined4 *)(param_1 + 0x188),0x23);

    local_4 = (undefined1)((uint)*(undefined4 *)(param_1 + 0x188) >> 0x18);

    uStack_3 = 0;

    iVar1 = FUN_0052c5c0();

    if (iVar1 != 0) {

      FUN_0052b780(0,6,&local_8);

      return;

    }

    FUN_0052b8c0(6,&local_8);

  }

  return;

}

/* ===== FUN_00530bd0 @ 0x00530BD0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* PS2 candidate: fx_create (conf 0.512) */



void FUN_00530bd0(int param_1,int param_2,int param_3,int param_4,undefined1 param_5,

                 undefined4 *param_6)



{

  uint uVar1;

  int iVar2;

  uint uVar3;

  undefined4 *puVar4;

  

  iVar2 = FUN_0052aa70();

  if (iVar2 == 0) {

    return;

  }

  uVar1 = param_4 + (param_2 + param_3) * 4;

  if ((0x3ff < (int)((int)DAT_005dfed8 + (uVar1 - 0x5dfecd))) &&

     (iVar2 = FUN_0052aa70(), iVar2 != 0)) {

    iVar2 = FUN_0052c5c0();

    if (iVar2 == 0) {

      if ((DAT_005dfed8 == &DAT_005dfedc) && (DAT_005e2310 == &DAT_005e2314)) {

        if (DAT_006328e8 < _DAT_005e2718 + 1.5) goto LAB_00530ccf;

        DAT_005e2314._0_1_ = 0x16;

        DAT_005e2310 = (undefined4 *)((int)&DAT_005e2314 + 1);

      }

      *(undefined1 *)DAT_005dfed8 = 0;

      DAT_005dfed8 = (int *)((int)DAT_005dfed8 + 1);

      *(undefined1 *)DAT_005e2310 = 0;

      DAT_005e2310 = (undefined4 *)((int)DAT_005e2310 + 1);

      if (1 < (int)DAT_005dfed8 + -0x5dfedc) {

        FUN_0052b8c0((undefined1 *)((int)DAT_005dfed8 + -0x5dfedc),&DAT_005dfedc);

      }

      if (1 < (int)DAT_005e2310 + -0x5e2314) {

        FUN_0052ba30((undefined1 *)((int)DAT_005e2310 + -0x5e2314),&DAT_005e2314);

      }

      DAT_005dfed8 = &DAT_005dfedc;

      DAT_005e2310 = &DAT_005e2314;

    }

    else {

      FUN_005354c0();

    }

  }

LAB_00530ccf:

  *(undefined1 *)DAT_005dfed8 = 0xb;

  DAT_005dfed8 = (int *)((int)DAT_005dfed8 + 1);

  *DAT_005dfed8 = uVar1 + 0xe;

  DAT_005dfed8 = DAT_005dfed8 + 1;

  *DAT_005dfed8 = *(int *)(param_1 + 0x188);

  DAT_005dfed8 = DAT_005dfed8 + 1;

  *(undefined1 *)DAT_005dfed8 = param_5;

  DAT_005dfed8 = (int *)((int)DAT_005dfed8 + 1);

  *DAT_005dfed8 = *(undefined4 *)(param_1 + 0x1e0);

  DAT_005dfed8 = DAT_005dfed8 + 1;

  if (uVar1 != 0) {

    puVar4 = DAT_005dfed8;

    for (uVar3 = uVar1 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {

      *puVar4 = *param_6;

      param_6 = param_6 + 1;

      puVar4 = puVar4 + 1;

    }

    for (uVar3 = uVar1 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {

      *(undefined1 *)puVar4 = *(undefined1 *)param_6;

      param_6 = (undefined4 *)((int)param_6 + 1);

      puVar4 = (undefined4 *)((int)puVar4 + 1);

    }

  }

  DAT_005dfed8 = (int *)((int)DAT_005dfed8 + uVar1);

  return;

}

/* ===== FUN_00530d70 @ 0x00530D70 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_00530d70(int param_1,int param_2,int param_3,int param_4,undefined1 param_5,

                 undefined4 *param_6)



{

  uint uVar1;

  int iVar2;

  uint uVar3;

  undefined4 *puVar4;

  

  iVar2 = FUN_0052aa70();

  if (iVar2 == 0) {

    return;

  }

  uVar1 = param_4 + (param_2 + param_3) * 4;

  if ((0x3ff < (int)((int)DAT_005dfed8 + (uVar1 - 0x5dfecd))) &&

     (iVar2 = FUN_0052aa70(), iVar2 != 0)) {

    iVar2 = FUN_0052c5c0();

    if (iVar2 == 0) {

      if ((DAT_005dfed8 == &DAT_005dfedc) && (DAT_005e2310 == &DAT_005e2314)) {

        if (DAT_006328e8 < _DAT_005e2718 + 1.5) goto LAB_00530e6f;

        DAT_005e2314._0_1_ = 0x16;

        DAT_005e2310 = (undefined4 *)((int)&DAT_005e2314 + 1);

      }

      *(undefined1 *)DAT_005dfed8 = 0;

      DAT_005dfed8 = (int *)((int)DAT_005dfed8 + 1);

      *(undefined1 *)DAT_005e2310 = 0;

      DAT_005e2310 = (undefined4 *)((int)DAT_005e2310 + 1);

      if (1 < (int)DAT_005dfed8 + -0x5dfedc) {

        FUN_0052b8c0((undefined1 *)((int)DAT_005dfed8 + -0x5dfedc),&DAT_005dfedc);

      }

      if (1 < (int)DAT_005e2310 + -0x5e2314) {

        FUN_0052ba30((undefined1 *)((int)DAT_005e2310 + -0x5e2314),&DAT_005e2314);

      }

      DAT_005dfed8 = &DAT_005dfedc;

      DAT_005e2310 = &DAT_005e2314;

    }

    else {

      FUN_005354c0();

    }

  }

LAB_00530e6f:

  *(undefined1 *)DAT_005dfed8 = 0x1b;

  DAT_005dfed8 = (int *)((int)DAT_005dfed8 + 1);

  *DAT_005dfed8 = uVar1 + 0xe;

  DAT_005dfed8 = DAT_005dfed8 + 1;

  *DAT_005dfed8 = *(int *)(param_1 + 0x188);

  DAT_005dfed8 = DAT_005dfed8 + 1;

  *(undefined1 *)DAT_005dfed8 = param_5;

  DAT_005dfed8 = (int *)((int)DAT_005dfed8 + 1);

  *DAT_005dfed8 = *(undefined4 *)(param_1 + 0x1e0);

  DAT_005dfed8 = DAT_005dfed8 + 1;

  if (uVar1 != 0) {

    puVar4 = DAT_005dfed8;

    for (uVar3 = uVar1 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {

      *puVar4 = *param_6;

      param_6 = param_6 + 1;

      puVar4 = puVar4 + 1;

    }

    for (uVar3 = uVar1 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {

      *(undefined1 *)puVar4 = *(undefined1 *)param_6;

      param_6 = (undefined4 *)((int)param_6 + 1);

      puVar4 = (undefined4 *)((int)puVar4 + 1);

    }

  }

  DAT_005dfed8 = (int *)((int)DAT_005dfed8 + uVar1);

  return;

}

/* ===== FUN_00530f10 @ 0x00530F10 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_00530f10(int param_1,int param_2,int param_3,int param_4,undefined1 param_5,

                 undefined4 *param_6)



{

  uint uVar1;

  int iVar2;

  uint uVar3;

  undefined4 *puVar4;

  

  iVar2 = FUN_0052aa70();

  if (iVar2 == 0) {

    return;

  }

  uVar1 = param_4 + (param_2 + param_3) * 4;

  if ((0x3ff < (int)((int)DAT_005e2310 + (uVar1 - 0x5e2305))) &&

     (iVar2 = FUN_0052aa70(), iVar2 != 0)) {

    iVar2 = FUN_0052c5c0();

    if (iVar2 == 0) {

      if ((DAT_005dfed8 == &DAT_005dfedc) && (DAT_005e2310 == &DAT_005e2314)) {

        if (DAT_006328e8 < _DAT_005e2718 + 1.5) goto LAB_00531013;

        DAT_005e2314._0_1_ = 0x16;

        DAT_005e2310 = (int *)((int)&DAT_005e2314 + 1);

      }

      *(undefined1 *)DAT_005dfed8 = 0;

      DAT_005dfed8 = (undefined4 *)((int)DAT_005dfed8 + 1);

      *(undefined1 *)DAT_005e2310 = 0;

      DAT_005e2310 = (int *)((int)DAT_005e2310 + 1);

      if (1 < (int)DAT_005dfed8 + -0x5dfedc) {

        FUN_0052b8c0((undefined1 *)((int)DAT_005dfed8 + -0x5dfedc),&DAT_005dfedc);

      }

      if (1 < (int)DAT_005e2310 + -0x5e2314) {

        FUN_0052ba30((undefined1 *)((int)DAT_005e2310 + -0x5e2314),&DAT_005e2314);

      }

      DAT_005dfed8 = &DAT_005dfedc;

      DAT_005e2310 = &DAT_005e2314;

    }

    else {

      FUN_005354c0();

    }

  }

LAB_00531013:

  *(undefined1 *)DAT_005e2310 = 0xc;

  DAT_005e2310 = (int *)((int)DAT_005e2310 + 1);

  *DAT_005e2310 = uVar1 + 0xe;

  DAT_005e2310 = DAT_005e2310 + 1;

  *DAT_005e2310 = *(int *)(param_1 + 0x188);

  DAT_005e2310 = DAT_005e2310 + 1;

  *(undefined1 *)DAT_005e2310 = param_5;

  DAT_005e2310 = (int *)((int)DAT_005e2310 + 1);

  *DAT_005e2310 = *(undefined4 *)(param_1 + 0x1e0);

  DAT_005e2310 = DAT_005e2310 + 1;

  if (uVar1 != 0) {

    puVar4 = DAT_005e2310;

    for (uVar3 = uVar1 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {

      *puVar4 = *param_6;

      param_6 = param_6 + 1;

      puVar4 = puVar4 + 1;

    }

    for (uVar3 = uVar1 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {

      *(undefined1 *)puVar4 = *(undefined1 *)param_6;

      param_6 = (undefined4 *)((int)param_6 + 1);

      puVar4 = (undefined4 *)((int)puVar4 + 1);

    }

  }

  DAT_005e2310 = (int *)((int)DAT_005e2310 + uVar1);

  return;

}

/* ===== FUN_005310b0 @ 0x005310B0 ===== */
void FUN_005310b0(void)



{

  DAT_005e02e4 = 1;

  return;

}

/* ===== FUN_005310c0 @ 0x005310C0 ===== */
void FUN_005310c0(uint param_1,char *param_2)



{

  char cVar1;

  int iVar2;

  uint uVar3;

  char *pcVar4;

  

  cVar1 = *param_2;

  if (cVar1 == 'A') {

    FUN_0052ac80();

    return;

  }

  if (cVar1 != '=') {

    if (cVar1 == 'Q') {

      DAT_00633040 = DAT_00633040 | 0x10;

      return;

    }

    iVar2 = FUN_0052aa70();

    if ((iVar2 != 0) && (DAT_005e02e4 == 0)) {

      while (EnterCriticalSection((LPCRITICAL_SECTION)&DAT_005e02ec),

            (int)&DAT_005e230c - (int)DAT_005e0308 < (int)param_1) {

        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_005e02ec);

        Sleep(500);

        if (DAT_005e02e4 != 0) {

          return;

        }

      }

      pcVar4 = DAT_005e0308;

      for (uVar3 = param_1 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {

        *(undefined4 *)pcVar4 = *(undefined4 *)param_2;

        param_2 = param_2 + 4;

        pcVar4 = pcVar4 + 4;

      }

      for (uVar3 = param_1 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {

        *pcVar4 = *param_2;

        param_2 = param_2 + 1;

        pcVar4 = pcVar4 + 1;

      }

      DAT_005e0308 = DAT_005e0308 + (param_1 - 1);

      DAT_005e02e0 = 1;

      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_005e02ec);

    }

    return;

  }

  DAT_00633040 = DAT_00633040 | 1;

  return;

}

/* ===== FUN_005311b0 @ 0x005311B0 ===== */
void FUN_005311b0(undefined4 param_1)



{

  undefined4 *puVar1;

  undefined1 uVar2;

  int iVar3;

  undefined2 uStack_6;

  undefined2 uStack_4;

  

  uStack_6 = (undefined2)param_1;

  uStack_4 = (undefined2)((uint)param_1 >> 0x10);

  uVar2 = FUN_0052ab20(param_1);

  iVar3 = FUN_0052aa70();

  if ((iVar3 != 0) && (DAT_005e02e4 == 0)) {

    while (EnterCriticalSection((LPCRITICAL_SECTION)&DAT_005e02ec), puVar1 = DAT_005e0308,

          (int)&DAT_005e230c - (int)DAT_005e0308 < 6) {

      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_005e02ec);

      Sleep(500);

      if (DAT_005e02e4 != 0) {

        return;

      }

    }

    *DAT_005e0308 = CONCAT22(uStack_6,CONCAT11(uVar2,4));

    *(undefined2 *)(puVar1 + 1) = uStack_4;

    DAT_005e0308 = (undefined4 *)((int)DAT_005e0308 + 6);

    *(undefined1 *)DAT_005e0308 = 0;

    DAT_005e02e0 = 1;

    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_005e02ec);

  }

  return;

}

/* ===== FUN_00531260 @ 0x00531260 ===== */
void FUN_00531260(undefined4 param_1)



{

  undefined1 local_8;

  undefined3 uStack_7;

  undefined1 local_4;

  undefined1 uStack_3;

  

  _local_8 = CONCAT31((int3)param_1,0x43);

  local_4 = (undefined1)((uint)param_1 >> 0x18);

  uStack_3 = 0;

  FUN_0052b5a0(param_1,6,&local_8);

  return;

}

/* ===== FUN_005312a0 @ 0x005312A0 ===== */
void FUN_005312a0(undefined1 param_1)



{

  int iVar1;

  undefined4 uStack_4;

  

  uStack_4 = CONCAT13(param_1,0x50000);

  iVar1 = FUN_0052aa70();

  if ((iVar1 != 0) && (DAT_005e02e4 == 0)) {

    while (EnterCriticalSection((LPCRITICAL_SECTION)&DAT_005e02ec),

          (int)&DAT_005e230c - (int)DAT_005e0308 < 2) {

      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_005e02ec);

      Sleep(500);

      if (DAT_005e02e4 != 0) {

        return;

      }

    }

    *DAT_005e0308 = uStack_4._2_2_;

    DAT_005e0308 = DAT_005e0308 + 1;

    *(undefined1 *)DAT_005e0308 = 0;

    DAT_005e02e0 = 1;

    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_005e02ec);

  }

  return;

}

/* ===== FUN_00531340 @ 0x00531340 ===== */
void FUN_00531340(undefined4 param_1)



{

  undefined4 *puVar1;

  int iVar2;

  undefined4 local_8;

  undefined1 uStack_4;

  

  local_8 = CONCAT31((int3)param_1,0x3a);

  uStack_4 = (undefined1)((uint)param_1 >> 0x18);

  iVar2 = FUN_0052aa70();

  if ((iVar2 != 0) && (DAT_005e02e4 == 0)) {

    while (EnterCriticalSection((LPCRITICAL_SECTION)&DAT_005e02ec), puVar1 = DAT_005e0308,

          (int)&DAT_005e230c - (int)DAT_005e0308 < 5) {

      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_005e02ec);

      Sleep(500);

      if (DAT_005e02e4 != 0) {

        return;

      }

    }

    *DAT_005e0308 = local_8;

    *(undefined1 *)(puVar1 + 1) = uStack_4;

    DAT_005e0308 = (undefined4 *)((int)DAT_005e0308 + 5);

    *(undefined1 *)DAT_005e0308 = 0;

    DAT_005e02e0 = 1;

    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_005e02ec);

  }

  return;

}

/* ===== FUN_005313e0 @ 0x005313E0 ===== */
void FUN_005313e0(void)



{

  int iVar1;

  

  iVar1 = FUN_0052aa70();

  if (((iVar1 != 0) && (iVar1 = FUN_0052aa70(), iVar1 != 0)) && (DAT_005e02e4 == 0)) {

    while (EnterCriticalSection((LPCRITICAL_SECTION)&DAT_005e02ec),

          (int)&DAT_005e230c - (int)DAT_005e0308 < 1) {

      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_005e02ec);

      Sleep(500);

      if (DAT_005e02e4 != 0) {

        return;

      }

    }

    *DAT_005e0308 = 0x3e;

    DAT_005e0308 = DAT_005e0308 + 1;

    *DAT_005e0308 = 0;

    DAT_005e02e0 = 1;

    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_005e02ec);

  }

  return;

}

/* ===== FUN_00531470 @ 0x00531470 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* WARNING: Struct "OBJECT": ignoring multiple overlapping fields */

/* PS2 candidate: smhatch_move (conf 0.498) */



void FUN_00531470(void)



{

  char cVar1;

  uint *puVar2;

  byte bVar3;

  int iVar4;

  undefined4 uVar5;

  int iVar6;

  char *pcVar7;

  int iVar8;

  uint uVar9;

  uint uVar10;

  OBJECT *unaff_EBP;

  undefined4 *puVar11;

  char *pcVar12;

  float10 fVar13;

  char *pcVar14;

  char *pcVar15;

  undefined4 local_538;

  ushort local_534;

  undefined4 local_530;

  undefined4 local_52c;

  ushort local_528;

  int local_524;

  char *local_520;

  undefined4 local_51c;

  undefined4 local_518;

  undefined4 local_514;

  char local_510;

  undefined1 local_50f [28];

  undefined1 local_4f3;

  undefined1 local_4e6;

  char local_4e4 [45];

  undefined1 local_4b7;

  undefined4 local_4a4;

  undefined4 local_4a0;

  int local_49c;

  undefined1 local_480 [128];

  char local_400 [256];

  undefined1 local_300 [256];

  undefined1 local_200 [256];

  char local_100 [256];

  

  local_524 = 0;

  iVar4 = FUN_0052aa70();

  if (iVar4 == 0) {

    return;

  }

  if (DAT_00633040 == 0) {

    FUN_0052d1c0();

    iVar4 = FUN_0052c5c0();

    if (iVar4 != 0) {

      iVar4 = FUN_0052aa70();

      if ((iVar4 != 0) && (1.5 <= DAT_006328e8 - _DAT_005e272c)) {

        _DAT_005e272c = DAT_006328e8;

        pcVar15 = &local_510;

        for (iVar4 = 10; iVar4 != 0; iVar4 = iVar4 + -1) {

          pcVar15[0] = '\0';

          pcVar15[1] = '\0';

          pcVar15[2] = '\0';

          pcVar15[3] = '\0';

          pcVar15 = pcVar15 + 4;

        }

        pcVar15[0] = '\0';

        pcVar15[1] = '\0';

        pcVar15[2] = '\0';

        local_510 = '4';

        bVar3 = FUN_0052b320(local_50f + 1);

        local_50f[0] = bVar3;

        uVar10 = (uint)bVar3;

        if (uVar10 < 0x14) {

          puVar11 = (undefined4 *)(local_50f + uVar10 * 2 + 1);

          for (uVar9 = 0x14 - uVar10 >> 1; uVar9 != 0; uVar9 = uVar9 - 1) {

            *puVar11 = 0;

            puVar11 = puVar11 + 1;

          }

          for (uVar10 = (uint)((0x14 - uVar10 & 1) != 0); uVar10 != 0; uVar10 = uVar10 - 1) {

            *(undefined2 *)puVar11 = 0;

            puVar11 = (undefined4 *)((int)puVar11 + 2);

          }

        }

        local_4e6 = 0;

        FUN_0052b860(0,(uint)bVar3 * 2 + 3,&local_510);

      }

      FUN_0052b020();

    }

    FUN_0052c4d0();

    if (DAT_005e02e0 == 0) {

      return;

    }

    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_005e02ec);

    DAT_005e0304 = (char *)&DAT_005e030c;

    DAT_005e02e0 = 0;

    DAT_005e0308 = &DAT_005e030c;

    DAT_005e2714 = 0;

    pcVar15 = DAT_005e0304;

    uVar10 = DAT_005e02e8;

    cVar1 = (char)DAT_005e030c;

    do {

      DAT_005e0304 = pcVar15;

      DAT_005e02e8 = uVar10;

      if (cVar1 == '\0') {

        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_005e02ec);

        if (local_524 == 0) {

          return;

        }

        FUN_005371e0();

        return;

      }

      pcVar14 = pcVar15;

      switch(*pcVar15) {

      case '\x03':

        uVar10 = (uint)(byte)pcVar15[1];

        pcVar14 = pcVar15 + 2;

        local_520 = pcVar14 + uVar10 * 4;

        DAT_005e0304 = pcVar15 + uVar10 * 6 + 2;

        FUN_0052b420(*(undefined4 *)pcVar14);

        FUN_0052b4b0(uVar10,pcVar14);

        pcVar15 = local_520;

        iVar4 = 0;

        if (uVar10 != 0) {

          do {

            FUN_0052ac60(iVar4,pcVar15[iVar4]);

            iVar4 = iVar4 + 1;

          } while (iVar4 < (int)uVar10);

        }

        iVar4 = 0;

        if (uVar10 != 0) {

          do {

            FUN_0052ab70(iVar4,pcVar14[iVar4 + uVar10 * 5]);

            iVar4 = iVar4 + 1;

          } while (iVar4 < (int)uVar10);

        }

        if ((DAT_00632f44 == 0) && (DAT_00632f08 < 6)) {

          FUN_0052f0a0(6);

          iVar4 = FUN_00525140(DAT_00632f14,DAT_00632f14);

          if (iVar4 == 0) {

            iVar4 = FUN_005250e0(DAT_00632f10);

            DAT_00632f14 = 2 - (uint)(iVar4 != 0);

            uVar5 = FUN_0052b430(DAT_00632f14);

            FUN_0052ef00(uVar5);

          }

          else {

            uVar5 = FUN_0052b430(DAT_00632f14);

            FUN_0052ef00(uVar5);

          }

        }

        break;

      case '\x04':

        iVar4 = FUN_0052aa70();

        if (iVar4 != 0) {

          iVar4 = FUN_0052c5c0();

          if (iVar4 == 0) {

            FUN_0052ae90(pcVar15[1]);

          }

          else {

            if (0x3ff < (int)(DAT_005dfed8 + -0x5dfed5)) {

              FUN_005359a0();

            }

            *DAT_005dfed8 = '\x04';

            DAT_005dfed8 = DAT_005dfed8 + 1;

            *DAT_005dfed8 = pcVar15[1];

            DAT_005dfed8 = DAT_005dfed8 + 1;

            *(undefined4 *)DAT_005dfed8 = *(undefined4 *)(pcVar15 + 2);

            DAT_005dfed8 = DAT_005dfed8 + 4;

            iVar4 = FUN_0052aca0(pcVar15[1]);

            if (iVar4 == 0) {

              uVar5 = FUN_0052adf0(pcVar15[1]);

              uVar5 = FUN_00507b00(s_MPChLostConn_0057fefc,uVar5);

            }

            else {

              uVar5 = FUN_0052adf0(pcVar15[1]);

              uVar5 = FUN_00507b00(s_MPChLeaveGame_0057ff0c,uVar5);

            }

            FUN_00542f27(local_480,uVar5);

            FUN_0052ea80(local_480,1,0,0);

            FUN_0052ac80(pcVar15[1],0);

            FUN_0052ae90(pcVar15[1]);

            FUN_0052e5e0();

          }

          if (DAT_005def94 == *(int *)(pcVar15 + 2)) {

            DAT_005def94 = 0;

            iVar4 = FUN_00426540();

            if ((iVar4 != 0) && (DAT_0063325c != 0)) {

              iVar4 = 1;

              do {

                iVar6 = FUN_0052ab00(iVar4);

                if (iVar6 != 0) {

                  uVar5 = FUN_0052ab00(iVar4);

                  FUN_0052f350(0,uVar5);

                  break;

                }

                iVar4 = iVar4 + 1;

              } while (iVar4 < 0x14);

            }

          }

          bVar3 = pcVar15[1];

          for (puVar11 = DAT_00632d68; puVar11 != (undefined4 *)0x0;

              puVar11 = (undefined4 *)*puVar11) {

            iVar4 = puVar11[3];

            if ((*(uint *)(iVar4 + 0x188) & 0xff) == (uint)bVar3) {

              iVar6 = FUN_0052c5c0();

              if ((iVar6 == 0) || (*(int *)(iVar4 + 0x1e0) != 0x4d)) {

                if ((*(byte *)(iVar4 + 0x1c8) & 1) != 0) {

                  FUN_0049baa0(iVar4);

                  FUN_00497510(iVar4);

                }

                if ((*(int *)(iVar4 + 0x1e0) == 4) || (*(int *)(iVar4 + 0x1e0) == 0x4b)) {

                  FUN_00497510(iVar4);

                }

              }

              else {

                local_51c = *(undefined4 *)(iVar4 + 0xa0);

                local_518 = *(undefined4 *)(iVar4 + 0xa4);

                local_514 = *(undefined4 *)(iVar4 + 0xa8);

                FUN_004aab40(iVar4,3,0,0,1,&local_51c);

              }

            }

          }

        }

        DAT_005e0304 = DAT_005e0304 + 6;

        break;

      case '\x05':

        DAT_005e02e8 = (uint)(byte)pcVar15[1];

        DAT_005e0304 = pcVar15 + 2;

        break;

      case '\x06':

        iVar4 = FUN_0052aa70();

        if ((iVar4 == 0) || (DAT_00632f08 < 10)) {

LAB_005319de:

          DAT_005e0304 = DAT_005e0304 + 9;

        }

        else {

          FUN_00498cf0(*(undefined4 *)(pcVar15 + 1),*(undefined4 *)(pcVar15 + 5));

          DAT_005e0304 = DAT_005e0304 + 9;

        }

        break;

      case '\a':

        iVar4 = FUN_0052aa70();

        if ((iVar4 == 0) || (DAT_00632f08 < 10)) goto LAB_005319de;

        iVar4 = FUN_0052c5c0();

        if (iVar4 != 0) {

          iVar4 = FUN_0052aa70();

          if (iVar4 == 0) goto LAB_005319de;

          local_530 = *(undefined4 *)pcVar15;

          local_52c = *(undefined4 *)(pcVar15 + 4);

          local_528 = (ushort)(byte)pcVar15[8];

          FUN_0052b780(0,10,&local_530);

        }

        FUN_004990c0(*(undefined4 *)(pcVar15 + 5),*(undefined4 *)(pcVar15 + 1));

        DAT_005e0304 = DAT_005e0304 + 9;

        break;

      case '\b':

        FUN_00532e20(pcVar15);

        DAT_005e0304 = DAT_005e0304 + 0x35;

        break;

      case '\t':

        DAT_005e0304 = pcVar15 + 1;

        local_524 = 1;

        break;

      case '\n':

        iVar4 = FUN_0052aa70();

        pcVar14 = DAT_005e0304;

        if ((iVar4 != 0) && (9 < DAT_00632f08)) {

          iVar4 = FUN_0052c5c0();

          if (iVar4 != 0) {

            iVar4 = FUN_0052aa70();

            pcVar14 = DAT_005e0304;

            if (iVar4 == 0) goto LAB_00532b8b;

            local_538 = *(undefined4 *)pcVar15;

            local_534 = (ushort)(byte)pcVar15[4];

            uVar5 = FUN_0052ab00(*(uint *)(pcVar15 + 1) & 0xff);

            FUN_0052b780(uVar5,6,&local_538);

          }

          iVar4 = FUN_0052e5b0(*(undefined4 *)(pcVar15 + 1));

          pcVar14 = DAT_005e0304;

          if (iVar4 != 0) {

            FUN_00499200(iVar4);

            pcVar14 = DAT_005e0304;

          }

        }

        goto LAB_00532b8b;

      case '\v':

        FUN_00535010(1,1);

        break;

      case '\f':

        FUN_00535010(0,1);

        break;

      case '\r':

        FUN_00534f10(pcVar15);

        DAT_005e0304 = DAT_005e0304 + 0x1a;

        break;

      case '\x0e':

        mecc_fire_logic__FP6OBJECT(unaff_EBP);

        DAT_005e0304 = DAT_005e0304 + 1;

        break;

      case '\x0f':

        FUN_00525030();

        DAT_005e0304 = DAT_005e0304 + 1;

        break;

      case '\x10':

        FUN_00525040();

        DAT_005e0304 = DAT_005e0304 + 1;

        break;

      case '\x11':

        FUN_00532f60(pcVar15);

        DAT_005e0304 = DAT_005e0304 + 9;

        break;

      case '\x12':

        FUN_0052ebd0(pcVar15);

        goto LAB_00532b21;

      case '\x13':

        FUN_00525060();

      case '\x16':

        DAT_005e0304 = DAT_005e0304 + 1;

        break;

      default:

        iVar4 = FUN_00425e90();

        if (iVar4 != 0) {

          _DAT_005e2730 = 1;

          FUN_00542f27(local_300,s_Unknown_multiplayer_opcode_recei_0057fe98,*DAT_005e0304,

                       DAT_005e0304,DAT_005e0308,(int)DAT_005e0304 - (int)DAT_005e0308,

                       DAT_005e030c & 0xff);

          FUN_00425eb0(local_300);

          iVar4 = 0;

          if (0 < (int)DAT_005e0304 - (int)DAT_005e0308) {

            do {

              FUN_00542f27(local_300,s_receivedata_buff__d_____d__0x_X__0057fe6c,iVar4,

                           *(undefined1 *)((int)&DAT_005e030c + iVar4),

                           *(undefined1 *)((int)&DAT_005e030c + iVar4));

              FUN_00425eb0(local_300);

              iVar4 = iVar4 + 1;

            } while (iVar4 < (int)DAT_005e0304 - (int)DAT_005e0308);

          }

        }

        *DAT_005e0304 = '\0';

        break;

      case '\x17':

        FUN_005331b0(pcVar15);

        DAT_005e0304 = DAT_005e0304 + 0x15;

        break;

      case '\x19':

        iVar4 = FUN_0052aa70();

        if (((iVar4 != 0) && (9 < DAT_00632f08)) &&

           (iVar4 = FUN_0052e5b0(*(undefined4 *)(pcVar15 + 5)), iVar4 == 0)) {

          iVar4 = FUN_004aa0b0(*(undefined4 *)(pcVar15 + 1),*(undefined4 *)(pcVar15 + 9));

          if (*(int *)(pcVar15 + 0x25) == 0) {

            uVar5 = 0;

          }

          else {

            uVar5 = FUN_0052e5b0(*(int *)(pcVar15 + 0x25));

          }

          *(undefined4 *)(iVar4 + 0x274) = uVar5;

          *(undefined4 *)(iVar4 + 0x188) = *(undefined4 *)(pcVar15 + 5);

          *(undefined4 *)(iVar4 + 0xa0) = *(undefined4 *)(pcVar15 + 0xd);

          *(undefined4 *)(iVar4 + 0xa4) = *(undefined4 *)(pcVar15 + 0x11);

          *(undefined4 *)(iVar4 + 0xa8) = *(undefined4 *)(pcVar15 + 0x15);

          *(undefined4 *)(iVar4 + 0x128) = *(undefined4 *)(pcVar15 + 0x19);

          *(undefined4 *)(iVar4 + 300) = *(undefined4 *)(pcVar15 + 0x1d);

          *(undefined4 *)(iVar4 + 0x130) = *(undefined4 *)(pcVar15 + 0x21);

          thunk_FUN_0049a1f0(iVar4);

        }

        DAT_005e0304 = DAT_005e0304 + 0x29;

        break;

      case '\x1a':

        FUN_00533280(pcVar15);

        DAT_005e0304 = DAT_005e0304 + 0x11;

        break;

      case '\x1b':

        FUN_00535010(1,0);

        break;

      case '\x1c':

      case '\x1d':

      case ')':

        FUN_0052ff70(pcVar15);

        pcVar14 = DAT_005e0304;

        goto LAB_00532b8b;

      case '\x1e':

        FUN_00533c60(pcVar15);

        DAT_005e0304 = DAT_005e0304 + 0x28;

        break;

      case '\x1f':

        iVar4 = FUN_0052aa70();

        if ((iVar4 != 0) && (9 < DAT_00632f08)) {

          FUN_0041ac40((int)*(short *)(pcVar15 + 1),*(undefined4 *)(pcVar15 + 3),pcVar15 + 0xc,

                       *(undefined4 *)(pcVar15 + 0x18),*(undefined4 *)(pcVar15 + 8),

                       *(undefined4 *)(pcVar15 + 0x1c),*(undefined4 *)(pcVar15 + 0x20));

        }

        DAT_005e0304 = DAT_005e0304 + 0x28;

        break;

      case ' ':

      case '(':

        FUN_00533370(pcVar15,*pcVar15 == '(');

        DAT_005e0304 = DAT_005e0304 + 0x15;

        break;

      case '\"':

        iVar4 = FUN_0052aa70();

        if (((iVar4 != 0) && (9 < DAT_00632f08)) &&

           (iVar4 = FUN_0052e5b0(*(undefined4 *)(pcVar15 + 5)), iVar4 == 0)) {

          iVar6 = FUN_00496c00(*(undefined4 *)(pcVar15 + 1),0x80000000);

          iVar4 = *(int *)(iVar6 + 0x100);

          *(undefined4 *)(iVar6 + 0x188) = *(undefined4 *)(pcVar15 + 5);

          *(undefined4 *)(iVar6 + 0xa0) = *(undefined4 *)(pcVar15 + 0xd);

          *(undefined4 *)(iVar6 + 0xa4) = *(undefined4 *)(pcVar15 + 0x11);

          *(undefined4 *)(iVar6 + 0xa8) = *(undefined4 *)(pcVar15 + 0x15);

          *(undefined4 *)(iVar6 + 200) = *(undefined4 *)(pcVar15 + 0x19);

          *(undefined4 *)(iVar6 + 0x18c) = *(undefined4 *)(pcVar15 + 9);

          iVar8 = FUN_00499030(iVar6,0x26f,0xffffffff,*(undefined4 *)(iVar4 + 0x30),0);

          *(int *)(iVar4 + 0x38) = iVar8;

          *(uint *)(iVar8 + 0xd8) = *(uint *)(iVar8 + 0xd8) | 0x40000000;

          iVar4 = FUN_00499030(iVar6,0x273,0xffffffff,*(undefined4 *)(iVar4 + 0x30),0);

          *(int *)(iVar8 + 0x274) = iVar4;

          *(uint *)(iVar4 + 0xd8) = *(uint *)(iVar4 + 0xd8) | 0x40000000;

        }

        DAT_005e0304 = DAT_005e0304 + 0x1d;

        break;

      case '#':

        iVar4 = FUN_0052e5b0(*(undefined4 *)(pcVar15 + 1));

        if (iVar4 != 0) {

          FUN_00497510(iVar4);

          pcVar14 = DAT_005e0304;

        }

        goto LAB_00532b8b;

      case '$':

        iVar4 = FUN_0052aa70();

        if (((iVar4 != 0) && (9 < DAT_00632f08)) &&

           (iVar4 = FUN_0052e5b0(*(undefined4 *)(pcVar15 + 1)), iVar4 != 0)) {

          *(undefined4 *)(iVar4 + 0x278) = *(undefined4 *)(pcVar15 + 5);

          FUN_004034a0(iVar4,1,0x84,0,0,0);

          *(uint *)(iVar4 + 0xe0) = *(uint *)(iVar4 + 0xe0) | 1;

        }

        DAT_005e0304 = DAT_005e0304 + 9;

        break;

      case '%':

        iVar4 = FUN_0052aa70();

        if (((iVar4 != 0) && (9 < DAT_00632f08)) &&

           (iVar4 = FUN_0052e5b0(*(undefined4 *)(pcVar15 + 5)), iVar4 == 0)) {

          iVar4 = FUN_00496c00(*(undefined4 *)(pcVar15 + 1),0);

          FUN_00499e70(iVar4,0x25);

          puVar2 = *(uint **)(iVar4 + 0x100);

          *(undefined4 *)(iVar4 + 0xa0) = *(undefined4 *)(pcVar15 + 9);

          *(undefined4 *)(iVar4 + 0xa4) = *(undefined4 *)(pcVar15 + 0xd);

          *(undefined4 *)(iVar4 + 0xa8) = *(undefined4 *)(pcVar15 + 0x11);

          *(undefined4 *)(iVar4 + 0x128) = *(undefined4 *)(pcVar15 + 0x15);

          *(undefined4 *)(iVar4 + 300) = *(undefined4 *)(pcVar15 + 0x19);

          *(undefined4 *)(iVar4 + 0x130) = *(undefined4 *)(pcVar15 + 0x1d);

          *(undefined4 *)(iVar4 + 0x188) = *(undefined4 *)(pcVar15 + 5);

          fVar13 = (float10)FUN_00455600((undefined4 *)(iVar4 + 0xa0));

          puVar2[2] = (uint)(float)(fVar13 + (float10)3.0);

          *puVar2 = (uint)*(ushort *)(pcVar15 + 0x23);

          puVar2[1] = *(uint *)(pcVar15 + 0x25);

          puVar2[4] = 0x3f800000;

          uVar10 = *(uint *)(pcVar15 + 0x29);

          puVar2[6] = uVar10;

          if (uVar10 == 0xffffffff) {

            puVar2[7] = 0;

          }

          else {

            puVar2[7] = 1;

          }

          uVar10 = *(uint *)(pcVar15 + 0x21);

          *(uint *)(iVar4 + 0xe8) = uVar10 & 0xffff;

          if ((uVar10 & 0xffff) == 0) {

            puVar2[5] = 0x41f00000;

          }

          else {

            puVar2[5] = 0;

          }

          *(uint *)(iVar4 + 0xe0) = *(uint *)(iVar4 + 0xe0) | 1;

          iVar4 = FUN_0052c5c0();

          if ((iVar4 != 0) && (iVar4 = FUN_0052aa70(), iVar4 != 0)) {

            pcVar14 = local_4e4;

            for (iVar4 = 0xb; iVar4 != 0; iVar4 = iVar4 + -1) {

              pcVar14[0] = '\0';

              pcVar14[1] = '\0';

              pcVar14[2] = '\0';

              pcVar14[3] = '\0';

              pcVar14 = pcVar14 + 4;

            }

            pcVar14[0] = '\0';

            pcVar14[1] = '\0';

            pcVar14 = local_4e4;

            for (iVar4 = 0xb; iVar4 != 0; iVar4 = iVar4 + -1) {

              *(undefined4 *)pcVar14 = *(undefined4 *)pcVar15;

              pcVar15 = pcVar15 + 4;

              pcVar14 = pcVar14 + 4;

            }

            *pcVar14 = *pcVar15;

            local_4b7 = 0;

            uVar5 = FUN_0052ab00(DAT_005e02e8);

            FUN_0052b780(uVar5,0x2e,local_4e4);

          }

        }

        DAT_005e0304 = DAT_005e0304 + 0x2d;

        break;

      case '&':

        iVar4 = FUN_0052aa70();

        if ((iVar4 != 0) && (9 < DAT_00632f08)) {

          iVar4 = FUN_00496c00(*(undefined4 *)(pcVar15 + 0x11),0);

          FUN_00499e70(iVar4,0x59);

          *(undefined4 *)(iVar4 + 0xa0) = *(undefined4 *)(pcVar15 + 5);

          *(undefined4 *)(iVar4 + 0xa4) = *(undefined4 *)(pcVar15 + 9);

          *(undefined4 *)(iVar4 + 0xa8) = *(undefined4 *)(pcVar15 + 0xd);

          *(undefined4 *)(iVar4 + 200) = *(undefined4 *)(pcVar15 + 1);

          *(undefined4 *)(iVar4 + 0x188) = *(undefined4 *)(pcVar15 + 0x15);

          FUN_004034a0(iVar4,*(undefined4 *)(pcVar15 + 0x19),0x80,0,0,0);

          *(undefined4 *)(iVar4 + 0x14) = 0x3f800000;

          iVar4 = FUN_0052c5c0();

          if ((iVar4 != 0) && (iVar4 = FUN_0052aa70(), iVar4 != 0)) {

            pcVar14 = &local_510;

            for (iVar4 = 7; iVar4 != 0; iVar4 = iVar4 + -1) {

              pcVar14[0] = '\0';

              pcVar14[1] = '\0';

              pcVar14[2] = '\0';

              pcVar14[3] = '\0';

              pcVar14 = pcVar14 + 4;

            }

            pcVar14[0] = '\0';

            pcVar14[1] = '\0';

            pcVar14 = &local_510;

            for (iVar4 = 7; iVar4 != 0; iVar4 = iVar4 + -1) {

              *(undefined4 *)pcVar14 = *(undefined4 *)pcVar15;

              pcVar15 = pcVar15 + 4;

              pcVar14 = pcVar14 + 4;

            }

            *pcVar14 = *pcVar15;

            local_4f3 = 0;

            uVar5 = FUN_0052ab00(DAT_005e02e8);

            FUN_0052b780(uVar5,0x1e,&local_510);

          }

        }

        DAT_005e0304 = DAT_005e0304 + 0x1d;

        break;

      case '*':

        iVar4 = FUN_0052aa70();

        if (((iVar4 != 0) && (9 < DAT_00632f08)) &&

           (iVar4 = FUN_0052e5b0(*(undefined4 *)(pcVar15 + 1)), iVar4 == 0)) {

          iVar4 = FUN_00496c00(0x3df,2);

          *(uint *)(iVar4 + 0x1d0) = *(uint *)(iVar4 + 0x1d0) | 0xf0f;

          *(undefined4 *)(iVar4 + 0x188) = *(undefined4 *)(pcVar15 + 1);

          *(uint *)(iVar4 + 0x18c) = (uint)*(ushort *)(pcVar15 + 0x27);

          *(uint *)(iVar4 + 0xf4) = *(uint *)(pcVar15 + 0x25) & 0xffff;

          *(int *)(iVar4 + 0xe8) = (int)*(short *)(pcVar15 + 0x29);

          FUN_004993c0(iVar4,pcVar15 + 5);

          *(undefined4 *)(iVar4 + 0x128) = *(undefined4 *)(pcVar15 + 0x11);

          *(undefined4 *)(iVar4 + 300) = *(undefined4 *)(pcVar15 + 0x15);

          *(undefined4 *)(iVar4 + 0x130) = *(undefined4 *)(pcVar15 + 0x19);

          *(undefined4 *)(iVar4 + 200) = *(undefined4 *)(pcVar15 + 0x1d);

          *(undefined4 *)(iVar4 + 0x278) = *(undefined4 *)(pcVar15 + 0x21);

          local_4a0 = 1;

          local_4a4 = 8;

          local_49c = iVar4;

          uVar5 = fx_get_free_effect__Fv();

          *(undefined4 *)(iVar4 + 0xfc) = uVar5;

        }

        DAT_005e0304 = DAT_005e0304 + 0x2b;

        break;

      case '+':

        FUN_00533500(pcVar15);

        DAT_005e0304 = DAT_005e0304 + 0x24;

        break;

      case ',':

        FUN_00533700(pcVar15);

        DAT_005e0304 = DAT_005e0304 + 0x26;

        break;

      case '-':

        FUN_005338e0(pcVar15);

        DAT_005e0304 = DAT_005e0304 + 0x96;

        break;

      case '.':

        FUN_005330c0(pcVar15);

        DAT_005e0304 = DAT_005e0304 + 0x15;

        break;

      case '/':

        FUN_0052f170(uVar10);

        FUN_00530180(uVar10);

        DAT_005e0304 = DAT_005e0304 + 1;

        break;

      case '0':

        DAT_00632f30 = *(undefined4 *)(pcVar15 + 1);

        DAT_00633010 = *(undefined4 *)(pcVar15 + 5);

        DAT_005e0304 = pcVar15 + 9;

        break;

      case '1':

        FUN_00532e90(pcVar15);

LAB_00532b21:

        DAT_005e0304 = DAT_005e0304 + 7;

        break;

      case '2':

        bVar3 = pcVar15[1];

        pcVar15 = pcVar15 + 2;

        pcVar14 = local_100;

        for (uVar10 = (uint)(bVar3 >> 2); uVar10 != 0; uVar10 = uVar10 - 1) {

          *(undefined4 *)pcVar14 = *(undefined4 *)pcVar15;

          pcVar15 = pcVar15 + 4;

          pcVar14 = pcVar14 + 4;

        }

        for (uVar10 = bVar3 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {

          *pcVar14 = *pcVar15;

          pcVar15 = pcVar15 + 1;

          pcVar14 = pcVar14 + 1;

        }

        FUN_00431ae0(local_100);

        DAT_005e0304 = DAT_005e0304 + bVar3 + 2;

        break;

      case '3':

        if (9 < DAT_00632f08) {

          DAT_006330c4 = (uint)(byte)pcVar15[1];

          DAT_006330c8 = (uint)(byte)pcVar15[2];

          DAT_006330cc = (uint)(byte)pcVar15[3];

          DAT_006330d0 = (uint)(byte)pcVar15[4];

          DAT_006330d4 = (uint)(byte)pcVar15[5];

          DAT_006330d8 = (uint)(byte)pcVar15[6];

        }

        DAT_005e0304 = pcVar15 + 7;

        break;

      case '4':

        FUN_0052b280(pcVar15[1],pcVar15 + 2);

        DAT_005e0304 = DAT_005e0304 + (uint)(byte)pcVar15[1] * 2 + 2;

        break;

      case '6':

        iVar4 = FUN_0052aa70();

        if (((iVar4 != 0) && (9 < DAT_00632f08)) &&

           (iVar4 = FUN_0052e5b0(*(undefined4 *)(pcVar15 + 1)), iVar4 == 0)) {

          iVar4 = FUN_00496c00(0x434,0x80000000);

          *(undefined4 *)(iVar4 + 0x188) = *(undefined4 *)(pcVar15 + 1);

          *(undefined4 *)(iVar4 + 0x18c) = *(undefined4 *)(pcVar15 + 0x25);

          FUN_004993c0(iVar4,pcVar15 + 5);

          *(undefined4 *)(iVar4 + 0x128) = *(undefined4 *)(pcVar15 + 0x11);

          *(undefined4 *)(iVar4 + 300) = *(undefined4 *)(pcVar15 + 0x15);

          *(undefined4 *)(iVar4 + 0x130) = *(undefined4 *)(pcVar15 + 0x19);

          *(undefined4 *)(iVar4 + 200) = *(undefined4 *)(pcVar15 + 0x1d);

          *(undefined4 *)(iVar4 + 0x278) = *(undefined4 *)(pcVar15 + 0x21);

        }

        DAT_005e0304 = DAT_005e0304 + 0x29;

        break;

      case '7':

        iVar4 = FUN_0052aa70();

        if (((iVar4 != 0) && (9 < DAT_00632f08)) &&

           (iVar4 = FUN_0052e5b0(*(undefined4 *)(pcVar15 + 0x21)), iVar4 != 0)) {

          uVar5 = *(undefined4 *)(pcVar15 + 0x1d);

          iVar6 = FUN_0052e5b0(uVar5);

          if (iVar6 == 0) {

            iVar6 = FUN_00456470(iVar4,pcVar15 + 5,uVar5);

            iVar4 = *(int *)(iVar6 + 0x100);

            *(undefined4 *)(iVar4 + 0x40) = *(undefined4 *)(pcVar15 + 0x11);

            *(undefined4 *)(iVar4 + 0x44) = *(undefined4 *)(pcVar15 + 0x15);

            *(undefined4 *)(iVar4 + 0x48) = *(undefined4 *)(pcVar15 + 0x19);

            uVar5 = *(undefined4 *)(pcVar15 + 1);

            *(undefined4 *)(iVar4 + 0x50) = uVar5;

            *(undefined4 *)(iVar4 + 0x4c) = uVar5;

            if (*(int *)(pcVar15 + 1) == 0x3e4ccccd) {

              *(undefined4 *)(iVar6 + 0x1c0) = *(undefined4 *)(DAT_00632ed8 + 3000);

              DAT_005e0304 = DAT_005e0304 + 0x25;

            }

            else {

              if (*(int *)(pcVar15 + 1) != 0x3f000000) {

                *(undefined4 *)(iVar6 + 0x1c0) = *(undefined4 *)(DAT_00632ed8 + 0xbc0);

                goto LAB_00532513;

              }

              *(undefined4 *)(iVar6 + 0x1c0) = *(undefined4 *)(DAT_00632ed8 + 0xbbc);

              DAT_005e0304 = DAT_005e0304 + 0x25;

            }

            break;

          }

        }

LAB_00532513:

        DAT_005e0304 = DAT_005e0304 + 0x25;

        break;

      case '8':

        FUN_00533140(pcVar15);

        DAT_005e0304 = DAT_005e0304 + 9;

        break;

      case '9':

        FUN_00533b00(pcVar15);

        DAT_005e0304 = DAT_005e0304 + 0x3d;

        break;

      case ':':

        iVar4 = FUN_0052c5c0();

        pcVar14 = DAT_005e0304;

        if ((iVar4 == 0) ||

           (iVar4 = FUN_0052a940(*(undefined4 *)(pcVar15 + 1)), pcVar14 = DAT_005e0304, iVar4 < 1))

        goto LAB_00532b8b;

        pcVar7 = (char *)FUN_0052adf0(iVar4);

        pcVar14 = local_400;

        do {

          cVar1 = *pcVar7;

          pcVar7 = pcVar7 + 1;

          *pcVar14 = cVar1;

          pcVar14 = pcVar14 + 1;

        } while (cVar1 != '\0');

        iVar4 = -1;

        pcVar14 = local_400;

        do {

          pcVar7 = pcVar14;

          if (iVar4 == 0) break;

          iVar4 = iVar4 + -1;

          pcVar7 = pcVar14 + 1;

          cVar1 = *pcVar14;

          pcVar14 = pcVar7;

        } while (cVar1 != '\0');

        *(undefined2 *)(pcVar7 + -1) = DAT_0055c728;

        pcVar14 = (char *)FUN_00507b00(s_CommConnected_0057fe5c);

        uVar10 = 0xffffffff;

        do {

          pcVar7 = pcVar14;

          if (uVar10 == 0) break;

          uVar10 = uVar10 - 1;

          pcVar7 = pcVar14 + 1;

          cVar1 = *pcVar14;

          pcVar14 = pcVar7;

        } while (cVar1 != '\0');

        uVar10 = ~uVar10;

        iVar4 = -1;

        pcVar14 = local_400;

        do {

          pcVar12 = pcVar14;

          if (iVar4 == 0) break;

          iVar4 = iVar4 + -1;

          pcVar12 = pcVar14 + 1;

          cVar1 = *pcVar14;

          pcVar14 = pcVar12;

        } while (cVar1 != '\0');

        pcVar14 = pcVar7 + -uVar10;

        pcVar7 = pcVar12 + -1;

        for (uVar9 = uVar10 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {

          *(undefined4 *)pcVar7 = *(undefined4 *)pcVar14;

          pcVar14 = pcVar14 + 4;

          pcVar7 = pcVar7 + 4;

        }

        for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {

          *pcVar7 = *pcVar14;

          pcVar14 = pcVar14 + 1;

          pcVar7 = pcVar7 + 1;

        }

        FUN_0052ea80(local_400,1,0,0);

        FUN_00525340();

        FUN_00531260(*(undefined4 *)(pcVar15 + 1));

        FUN_0052e5e0();

        DAT_005e0304 = DAT_005e0304 + 5;

        break;

      case '<':

        iVar4 = FUN_0052c5c0();

        if (iVar4 == 0) {

          bVar3 = DAT_005e0304[2];

          pcVar15 = DAT_005e0304 + 3;

          if ((int)((byte)DAT_005e0304[1] & 0x7f) <= DAT_00632f34 + -1) {

            uVar5 = FUN_0052adf0((byte)DAT_005e0304[1] & 0x7f);

            if ((bVar3 & 0x40) == 0) {

              FUN_005363f0(pcVar15,bVar3 & 0xf);

            }

            else {

              chat_insert_name(uVar5,pcVar15,bVar3 & 0xf,bVar3 & 0x20);

            }

          }

        }

        else {

          FUN_0052e6e0(DAT_005e0304,0);

        }

        uVar10 = 0xffffffff;

        pcVar15 = DAT_005e0304;

        do {

          if (uVar10 == 0) break;

          uVar10 = uVar10 - 1;

          cVar1 = *pcVar15;

          pcVar15 = pcVar15 + 1;

        } while (cVar1 != '\0');

        DAT_005e0304 = DAT_005e0304 + ~uVar10;

        break;

      case '=':

        DAT_00633040 = DAT_00633040 | 1;

        DAT_005e0304 = pcVar15 + 1;

        break;

      case '>':

        FUN_00529f80();

        DAT_005e0304 = DAT_005e0304 + 1;

        break;

      case '?':

        FUN_00530270(pcVar15);

        DAT_005e0304 = DAT_005e0304 + 0x15;

        break;

      case '@':

        iVar4 = FUN_0052aa70();

        if (iVar4 != 0) {

          if (pcVar15[1] != -1) {

            FUN_0052b240(pcVar15[1],*(undefined4 *)(pcVar15 + 5));

          }

          if (pcVar15[3] != -1) {

            FUN_0052b260(pcVar15[3],*(undefined4 *)(pcVar15 + 0xd));

          }

          if (pcVar15[2] != -1) {

            FUN_0052b200(pcVar15[2],*(undefined4 *)(pcVar15 + 9));

          }

          if (pcVar15[4] != -1) {

            FUN_0052b220(pcVar15[4],*(undefined4 *)(pcVar15 + 0x11));

          }

        }

        DAT_005e0304 = DAT_005e0304 + 0x15;

        break;

      case 'A':

        FUN_0052ac80(pcVar15[1],1);

        DAT_005e0304 = DAT_005e0304 + 2;

        break;

      case 'B':

        iVar6 = 0;

        iVar4 = 0;

        if ((DAT_00632f18 == 0) || (DAT_00632f18 == 2)) {

          iVar4 = 0x400;

          iVar6 = 0x400;

        }

        if ((iVar4 != *(int *)(pcVar15 + 1)) || (iVar6 != *(int *)(pcVar15 + 5))) {

          uVar5 = FUN_00507b00(s_CommWeaponBits_0057ff1c,1);

          FUN_005363f0(uVar5);

        }

        FUN_00452b00(*(undefined4 *)(pcVar15 + 1),*(undefined4 *)(pcVar15 + 5),1);

        DAT_005e0304 = DAT_005e0304 + 9;

        DAT_0059d99c = 1;

        break;

      case 'C':

        FUN_0052aae0(*(undefined4 *)(pcVar15 + 1));

        pcVar14 = DAT_005e0304;

        goto LAB_00532b8b;

      case 'D':

        FUN_0052adc0(pcVar15[1],pcVar15 + 2);

        DAT_005e0304 = DAT_005e0304 + 0x22;

        break;

      case 'E':

        if (*(int *)(pcVar15 + 1) == 0) {

          pcVar14 = s_CommPhFFOff_0055e8e4;

        }

        else {

          pcVar14 = s_CommPhFFOn_0055e8f0;

        }

        uVar5 = FUN_00507b00(pcVar14,1);

        FUN_005363f0(uVar5);

        DAT_00633250 = *(uint *)(pcVar15 + 1);

        DAT_005e0304 = DAT_005e0304 + 5;

        break;

      case 'F':

        if (pcVar15[1] == '\0') {

          pcVar14 = s_CommPlayerMarkerLarge_0057fe20;

        }

        else if (pcVar15[1] == '\x01') {

          pcVar14 = s_CommPlayerMarkerSmall_0057fe08;

        }

        else {

          pcVar14 = s_CommPlayerMarkerNone_0057fdf0;

        }

        uVar5 = FUN_00507b00(pcVar14,1);

        FUN_005363f0(uVar5);

        _DAT_00633254 = (uint)(byte)pcVar15[1];

        DAT_005e0304 = DAT_005e0304 + 2;

        break;

      case 'G':

        FUN_0052f3b0(pcVar15);

        pcVar14 = DAT_005e0304;

LAB_00532b8b:

        DAT_005e0304 = pcVar14 + 5;

        break;

      case 'H':

        if ((*(int *)(pcVar15 + 5) != DAT_005def94) || (iVar4 = 0, DAT_00632f34 < 1))

        goto LAB_005319de;

        do {

          iVar6 = FUN_0052ab00(iVar4);

          if (iVar6 == *(int *)(pcVar15 + 1)) {

            FUN_00521150(iVar4,0);

            goto LAB_005319de;

          }

          iVar4 = iVar4 + 1;

        } while (iVar4 < DAT_00632f34);

        DAT_005e0304 = DAT_005e0304 + 9;

        break;

      case 'I':

        if (*(int *)(pcVar15 + 1) != DAT_005def94) goto LAB_00532b8b;

        FUN_00520fd0();

        DAT_005e0304 = DAT_005e0304 + 5;

        break;

      case 'J':

        if (*(int *)(pcVar15 + 1) != DAT_005def94) goto LAB_00532b8b;

        DAT_00633250 = (uint)(DAT_00633250 == 0);

        FUN_0052f300(0);

        if (DAT_00633250 == 0) {

          pcVar15 = s_CommPhFFOff_0055e8e4;

        }

        else {

          pcVar15 = s_CommPhFFOn_0055e8f0;

        }

        uVar5 = FUN_00507b00(pcVar15,1);

        FUN_005363f0(uVar5);

        DAT_005e0304 = DAT_005e0304 + 5;

        break;

      case 'K':

        if (*(int *)(pcVar15 + 1) != DAT_005def94) goto LAB_00532b8b;

        FUN_00520d70();

        DAT_005e0304 = DAT_005e0304 + 5;

        break;

      case 'L':

        if (*(int *)(pcVar15 + 1) != DAT_005def94) goto LAB_00532b8b;

        FUN_00520b90();

        DAT_005e0304 = DAT_005e0304 + 5;

        break;

      case 'M':

        if ((DAT_005def94 == 0) || (iVar4 = 0, DAT_00632f34 < 1)) {

LAB_0053196c:

          DAT_005def94 = 0;

          FUN_00522b80();

          DAT_005e0304 = DAT_005e0304 + 5;

        }

        else {

          do {

            iVar6 = FUN_0052ab00(iVar4);

            if (iVar6 == DAT_005def94) {

              iVar6 = FUN_0052aad0();

              if (iVar6 == DAT_005def94) {

                uVar5 = FUN_00507b00(s_CommFakeHostYouOff_0057fddc);

              }

              else {

                uVar5 = FUN_0052adf0(iVar4);

                uVar5 = FUN_00507b00(s_CommFakeHostOff_0057fdcc,uVar5);

              }

              FUN_00542f27(local_200,uVar5);

              FUN_005363f0(local_200,1);

              goto LAB_0053196c;

            }

            iVar4 = iVar4 + 1;

          } while (iVar4 < DAT_00632f34);

          DAT_005def94 = 0;

          FUN_00522b80();

          DAT_005e0304 = DAT_005e0304 + 5;

        }

        break;

      case 'N':

        if (*(int *)(pcVar15 + 1) == DAT_005def94) {

          iVar4 = FUN_00525140(0xffffffff,*(undefined4 *)(pcVar15 + 9));

          if ((iVar4 != 0) && (iVar4 = 0, 0 < DAT_00632f34)) {

            do {

              iVar6 = FUN_0052ab00(iVar4);

              if (iVar6 == *(int *)(pcVar15 + 5)) {

                FUN_0052eb60(iVar4,*(undefined4 *)(pcVar15 + 9));

                goto LAB_00531a53;

              }

              iVar4 = iVar4 + 1;

            } while (iVar4 < DAT_00632f34);

            DAT_005e0304 = DAT_005e0304 + 0xd;

            break;

          }

        }

LAB_00531a53:

        DAT_005e0304 = DAT_005e0304 + 0xd;

        break;

      case 'O':

        DAT_005e0304 = pcVar15 + *(int *)(pcVar15 + 1);

        break;

      case 'P':

        if (*(int *)(pcVar15 + 1) != DAT_005def94) goto LAB_00532b8b;

        FUN_0052f790();

        DAT_005e0304 = DAT_005e0304 + 5;

        break;

      case 'Q':

        DAT_00633040 = DAT_00633040 | 0x10;

        DAT_005e0304 = pcVar15 + 1;

      }

      cVar1 = *DAT_005e0304;

      pcVar15 = DAT_005e0304;

      uVar10 = DAT_005e02e8;

    } while( true );

  }

  if ((6 < DAT_00632f08) && (DAT_00632f08 < 10)) {

    return;

  }

  if (_DAT_005e2734 != 0.0) goto LAB_0053151e;

  if ((DAT_00633040 & 1) == 0) {

    if ((DAT_00633040 & 4) != 0) {

      pcVar15 = s_CommLostEndgame_005612d8;

      goto LAB_00531503;

    }

    if ((DAT_00633040 & 8) != 0) {

      pcVar15 = s_CommLostKicked_005612c8;

      goto LAB_00531503;

    }

    if ((DAT_00633040 & 0x10) != 0) {

      pcVar15 = s_CommLostAutoKicked_005612b4;

      goto LAB_00531503;

    }

    if ((DAT_00633040 & 2) != 0) {

      pcVar15 = s_CommLostSession_005612a4;

      goto LAB_00531503;

    }

  }

  else {

    pcVar15 = s_CommLostHost_005612e8;

LAB_00531503:

    uVar5 = FUN_00507b00(pcVar15,1);

    FUN_005363f0(uVar5);

  }

  _DAT_005e2734 = 4.0;

LAB_0053151e:

  fVar13 = (float10)FUN_00518b70(0,0);

  fVar13 = (float10)_DAT_005e2734 - fVar13;

  _DAT_005e2734 = (float)fVar13;

  if (fVar13 < (float10)0.0 == (fVar13 == (float10)0.0)) {

    return;

  }

  _DAT_005e2734 = 0.0;

  FUN_00524de0();

  return;

}

/* ===== FUN_00532e20 @ 0x00532E20 ===== */
void FUN_00532e20(undefined4 *param_1)



{

  int iVar1;

  undefined4 *puVar2;

  undefined4 *puVar3;

  undefined4 local_38 [13];

  undefined1 local_3;

  

  iVar1 = FUN_0052aa70();

  if (iVar1 != 0) {

    iVar1 = FUN_0052c5c0();

    if (iVar1 != 0) {

      puVar2 = param_1;

      puVar3 = local_38;

      for (iVar1 = 0xd; iVar1 != 0; iVar1 = iVar1 + -1) {

        *puVar3 = *puVar2;

        puVar2 = puVar2 + 1;

        puVar3 = puVar3 + 1;

      }

      *(undefined1 *)puVar3 = *(undefined1 *)puVar2;

      local_3 = 0;

      FUN_0052b780(0,0x36,local_38);

    }

    FUN_004041f0(*(undefined4 *)((int)param_1 + 1),*(undefined4 *)((int)param_1 + 5),

                 *(undefined4 *)((int)param_1 + 9),*(undefined4 *)((int)param_1 + 0xd),

                 *(undefined4 *)((int)param_1 + 0x11),(undefined1 *)((int)param_1 + 0x15));

  }

  return;

}

/* ===== FUN_00532e90 @ 0x00532E90 ===== */
void FUN_00532e90(int param_1)



{

  undefined1 uVar1;

  int iVar2;

  int iVar3;

  uint uVar4;

  undefined1 local_8;

  undefined1 local_7;

  undefined4 local_6;

  char local_2;

  undefined1 local_1;

  

  iVar2 = FUN_0052aa70();

  if (iVar2 != 0) {

    iVar2 = FUN_0052c5c0();

    if (iVar2 != 0) {

      DAT_005ddb54 = DAT_005ddb54 | *(byte *)(param_1 + 1) & 0x80;

      *(byte *)(param_1 + 1) = *(byte *)(param_1 + 1) & 0x7f;

      iVar2 = FUN_0052ab20(*(undefined4 *)(param_1 + 2));

      if (-1 < iVar2) {

        iVar3 = FUN_00525140(0xffffffff,*(undefined1 *)(param_1 + 1));

        if (iVar3 != 0) {

          uVar1 = *(undefined1 *)(param_1 + 1);

          iVar3 = FUN_0052aa70();

          if (iVar3 != 0) {

            iVar3 = FUN_0052c5c0();

            if (iVar3 != 0) {

              local_8 = 0x12;

              local_6 = FUN_0052ab00(iVar2);

              local_7 = uVar1;

              uVar4 = FUN_0052ac40(iVar2);

              local_2 = '\x01' - (uVar4 < 0xe);

              local_1 = 0;

              FUN_0052ebd0(&local_8);

              FUN_0052b780(0,8,&local_8);

            }

          }

        }

      }

    }

  }

  return;

}

/* ===== FUN_00532f60 @ 0x00532F60 ===== */
void FUN_00532f60(undefined4 *param_1)



{

  int iVar1;

  undefined4 uVar2;

  uint uVar3;

  undefined4 uVar4;

  undefined4 uVar5;

  undefined4 uVar6;

  int iVar7;

  undefined4 local_d4;

  undefined4 local_d0;

  undefined1 local_cc;

  undefined1 local_cb;

  undefined1 local_c8 [200];

  

  iVar1 = FUN_0052aa70();

  if (iVar1 != 0) {

    iVar1 = FUN_0052c5c0();

    if (iVar1 != 0) {

      local_d4 = *param_1;

      local_d0 = param_1[1];

      local_cc = *(undefined1 *)(param_1 + 2);

      local_cb = 0;

      FUN_0052b780(0,10,&local_d4);

    }

    uVar2 = FUN_0052ab20(*(undefined4 *)((int)param_1 + 1));

    uVar3 = FUN_0052ac40(uVar2);

    FUN_0052ac60(uVar2,*(undefined4 *)((int)param_1 + 5));

    if (((uVar3 < 0xe) && (*(int *)((int)param_1 + 5) == 0xe)) ||

       ((iVar1 = FUN_0052aad0(), iVar1 == *(int *)((int)param_1 + 1) &&

        (*(int *)((int)param_1 + 5) == 0xe)))) {

      iVar1 = FUN_0052aaf0();

      if ((*(int *)((int)param_1 + 1) != iVar1) || (DAT_00633238 == 0)) {

        uVar4 = FUN_0052adf0(uVar2);

        uVar5 = FUN_0052ab50(uVar2);

        uVar5 = FUN_0052ab90(uVar5);

        uVar6 = FUN_00507b00(s_MPChEnterGame_0057fd98);

        FUN_00542f27(local_c8,uVar6,uVar4,uVar5);

        FUN_005363f0(local_c8,1);

      }

      iVar1 = FUN_0052c5c0();

      if (iVar1 != 0) {

        iVar1 = *(int *)((int)param_1 + 1);

        iVar7 = FUN_0052aa70();

        if (iVar7 != 0) {

          local_d4 = CONCAT31((int3)DAT_00632f30,0x30);

          local_d0._1_3_ = (undefined3)DAT_00633010;

          local_d0 = CONCAT31(local_d0._1_3_,(char)((uint)DAT_00632f30 >> 0x18));

          local_cc = (undefined1)((uint)DAT_00633010 >> 0x18);

          local_cb = 0;

          if (iVar1 == 0) {

            FUN_0052b780(0,10,&local_d4);

          }

          else {

            FUN_0052b5a0(iVar1,10,&local_d4);

          }

        }

        FUN_0052b000(uVar2);

      }

    }

  }

  return;

}

/* ===== FUN_005330c0 @ 0x005330C0 ===== */
void FUN_005330c0(int param_1)



{

  int iVar1;

  uint *puVar2;

  uint *puVar3;

  uint local_10;

  uint local_c;

  uint local_8;

  uint local_4;

  

  iVar1 = 0;

  puVar2 = &DAT_00632fc0;

  puVar3 = (uint *)(param_1 + 1);

  do {

    local_10 = *puVar2;

    local_c = puVar2[1];

    local_8 = puVar2[2];

    local_4 = puVar2[3];

    *puVar2 = *puVar3 >> 0x1f;

    puVar2[1] = *puVar3 >> 0x1e & 1;

    puVar2[2] = *puVar3 >> 0x1d & 1;

    puVar2[3] = *puVar3 & 0xffff;

    FUN_005227b0(&local_10,puVar2,iVar1);

    puVar2 = puVar2 + 4;

    iVar1 = iVar1 + 1;

    puVar3 = puVar3 + 1;

  } while ((int)puVar2 < 0x633010);

  return;

}

/* ===== FUN_00533140 @ 0x00533140 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_00533140(int param_1)



{

  char cVar1;

  char *pcVar2;

  undefined4 uVar3;

  char *pcVar4;

  char local_80 [128];

  

  if (0 < *(int *)(param_1 + 1)) {

    pcVar2 = (char *)FUN_0052ab90(*(int *)(param_1 + 1));

    pcVar4 = local_80;

    do {

      cVar1 = *pcVar2;

      pcVar2 = pcVar2 + 1;

      *pcVar4 = cVar1;

      pcVar4 = pcVar4 + 1;

    } while (cVar1 != '\0');

    uVar3 = __ftol();

    uVar3 = FUN_00507b00(s_WinCondTeamWinner_0057ff2c,local_80,uVar3);

    FUN_00542f27(&DAT_00632c10,uVar3);

    _DAT_00632d10 = 0x40c00000;

  }

  return;

}

/* ===== FUN_005331b0 @ 0x005331B0 ===== */
void FUN_005331b0(undefined4 *param_1)



{

  int iVar1;

  undefined4 uVar2;

  int *piVar3;

  undefined4 *puVar4;

  undefined4 *puVar5;

  undefined4 local_18 [5];

  undefined1 local_3;

  

  iVar1 = FUN_0052aa70();

  if (iVar1 != 0) {

    iVar1 = FUN_0052c5c0();

    if (iVar1 != 0) {

      puVar4 = param_1;

      puVar5 = local_18;

      for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {

        *puVar5 = *puVar4;

        puVar4 = puVar4 + 1;

        puVar5 = puVar5 + 1;

      }

      *(undefined1 *)puVar5 = *(undefined1 *)puVar4;

      local_3 = 0;

      uVar2 = FUN_0052ab00(DAT_005e02e8);

      FUN_0052b780(uVar2,0x16,local_18);

    }

    piVar3 = DAT_00632d68;

    if (DAT_00632d68 != (int *)0x0) {

      while ((iVar1 = piVar3[3], (*(uint *)(iVar1 + 0xd8) & 0x8000) != 0 ||

             (*(int *)(iVar1 + 0x188) != *(int *)((int)param_1 + 1)))) {

        piVar3 = (int *)*piVar3;

        if (piVar3 == (int *)0x0) {

          return;

        }

      }

      FUN_0052f980(iVar1,*(undefined4 *)((int)param_1 + 5));

      *(undefined4 *)(iVar1 + 0xa0) = *(undefined4 *)((int)param_1 + 9);

      *(undefined4 *)(iVar1 + 0xa4) = *(undefined4 *)((int)param_1 + 0xd);

      *(undefined4 *)(iVar1 + 0xa8) = *(undefined4 *)((int)param_1 + 0x11);

      FUN_00499280(iVar1);

      FUN_004a7440(iVar1);

      FUN_0049a1f0(iVar1);

    }

  }

  return;

}

/* ===== FUN_00533500 @ 0x00533500 ===== */
void FUN_00533500(int param_1)



{

  int iVar1;

  int iVar2;

  uint uVar3;

  int *piVar4;

  int iVar5;

  undefined4 uVar6;

  

  iVar2 = FUN_0052aa70();

  if (((iVar2 != 0) && (9 < DAT_00632f08)) && (piVar4 = DAT_00632d68, DAT_00632d68 != (int *)0x0)) {

    while ((iVar2 = piVar4[3], (*(uint *)(iVar2 + 0xd8) & 0x8000) != 0 ||

           (*(int *)(iVar2 + 0x188) != *(int *)(param_1 + 1)))) {

      piVar4 = (int *)*piVar4;

      if (piVar4 == (int *)0x0) {

        return;

      }

    }

    iVar1 = *(int *)(iVar2 + 0x100);

    *(undefined4 *)(iVar2 + 0x278) = *(undefined4 *)(param_1 + 5);

    FUN_004034a0(iVar2,1,0x21,0,0,0);

    if (*(byte *)(param_1 + 10) == 0xff) {

      uVar3 = 0xffffffff;

    }

    else {

      uVar3 = (uint)*(byte *)(param_1 + 10);

    }

    FUN_00457f40(iVar2,*(undefined1 *)(param_1 + 9),uVar3);

    FUN_00457fe0(iVar2,*(undefined1 *)(param_1 + 9));

    if (*(byte *)(param_1 + 0xb) == 0xff) {

      uVar3 = 0xffffffff;

    }

    else {

      uVar3 = (uint)*(byte *)(param_1 + 0xb);

    }

    FUN_00458350(iVar2,uVar3);

    *(undefined4 *)(iVar2 + 0xa0) = *(undefined4 *)(param_1 + 0x14);

    *(undefined4 *)(iVar2 + 0xa4) = *(undefined4 *)(param_1 + 0x18);

    *(undefined4 *)(iVar2 + 0xa8) = *(undefined4 *)(param_1 + 0x1c);

    *(undefined4 *)(iVar2 + 0xac) = *(undefined4 *)(param_1 + 0x14);

    *(undefined4 *)(iVar2 + 0xb0) = *(undefined4 *)(param_1 + 0x18);

    *(undefined4 *)(iVar2 + 0xb4) = *(undefined4 *)(param_1 + 0x1c);

    FUN_00499280(iVar2);

    FUN_004a7440(iVar2);

    piVar4 = DAT_00632d68;

    if (*(int *)(param_1 + 0x20) != 0) {

      for (; piVar4 != (int *)0x0; piVar4 = (int *)*piVar4) {

        iVar5 = piVar4[3];

        if (((*(uint *)(iVar5 + 0xd8) & 0x8000) == 0) &&

           (*(int *)(iVar5 + 0x188) == *(int *)(param_1 + 0x20))) goto LAB_00533630;

      }

      iVar5 = 0;

LAB_00533630:

      *(int *)(iVar1 + 0xd8) = iVar5;

    }

    if ((*(byte *)(param_1 + 0xc) & 1) != 0) {

      FUN_0047fff0(iVar2);

    }

    uVar3 = *(uint *)(param_1 + 0xc);

    piVar4 = DAT_00632d68;

    if ((uVar3 & 0xe) != 0) {

      for (; piVar4 != (int *)0x0; piVar4 = (int *)*piVar4) {

        iVar1 = piVar4[3];

        if (((*(uint *)(iVar1 + 0xd8) & 0x8000) == 0) &&

           (*(int *)(iVar1 + 0x188) == *(int *)(param_1 + 0x10))) {

          if ((uVar3 & 2) == 0) {

            if ((uVar3 & 4) == 0) {

              if ((uVar3 & 8) == 0) goto LAB_0053369f;

              uVar6 = 2;

            }

            else {

              uVar6 = 1;

            }

            FUN_004819f0(iVar2,iVar1,uVar6);

          }

          else {

            FUN_00481830(iVar2,iVar1);

          }

LAB_0053369f:

          FUN_00497570(iVar2);

          break;

        }

      }

    }

    if ((*(byte *)(param_1 + 0xc) & 0x10) != 0) {

      FUN_004801c0(iVar2);

    }

    if (((*(byte *)(param_1 + 0xc) & 0x20) != 0) &&

       (piVar4 = DAT_00632d68, DAT_00632d68 != (int *)0x0)) {

      while ((iVar1 = piVar4[3], (*(uint *)(iVar1 + 0xd8) & 0x8000) != 0 ||

             (*(int *)(iVar1 + 0x188) != *(int *)(param_1 + 0x10)))) {

        piVar4 = (int *)*piVar4;

        if (piVar4 == (int *)0x0) {

          return;

        }

      }

      FUN_0050c1c0(iVar1,iVar2);

      FUN_00497570(iVar2);

    }

  }

  return;

}

/* ===== FUN_00533700 @ 0x00533700 ===== */
void FUN_00533700(int param_1)



{

  int iVar1;

  int iVar2;

  int *piVar3;

  int iVar4;

  

  iVar2 = FUN_0052aa70();

  if (((iVar2 != 0) && (9 < DAT_00632f08)) && (piVar3 = DAT_00632d68, DAT_00632d68 != (int *)0x0)) {

    while ((iVar2 = piVar3[3], (*(uint *)(iVar2 + 0xd8) & 0x8000) != 0 ||

           (*(int *)(iVar2 + 0x188) != *(int *)(param_1 + 1)))) {

      piVar3 = (int *)*piVar3;

      if (piVar3 == (int *)0x0) {

        return;

      }

    }

    iVar1 = *(int *)(iVar2 + 0x100);

    *(undefined4 *)(iVar2 + 0xa0) = *(undefined4 *)(param_1 + 0x16);

    *(undefined4 *)(iVar2 + 0xa4) = *(undefined4 *)(param_1 + 0x1a);

    *(undefined4 *)(iVar2 + 0xa8) = *(undefined4 *)(param_1 + 0x1e);

    *(undefined4 *)(iVar2 + 0xac) = *(undefined4 *)(param_1 + 0x16);

    *(undefined4 *)(iVar2 + 0xb0) = *(undefined4 *)(param_1 + 0x1a);

    *(undefined4 *)(iVar2 + 0xb4) = *(undefined4 *)(param_1 + 0x1e);

    FUN_00499280(iVar2);

    FUN_004a7440(iVar2);

    *(undefined4 *)(iVar2 + 0x278) = *(undefined4 *)(param_1 + 5);

    FUN_004034a0(iVar2,1,0x21,0,0,0);

    piVar3 = DAT_00632d68;

    if (*(int *)(param_1 + 0x22) != 0) {

      for (; piVar3 != (int *)0x0; piVar3 = (int *)*piVar3) {

        iVar4 = piVar3[3];

        if (((*(uint *)(iVar4 + 0xd8) & 0x8000) == 0) &&

           (*(int *)(iVar4 + 0x188) == *(int *)(param_1 + 0x22))) goto LAB_005337eb;

      }

      iVar4 = 0;

LAB_005337eb:

      *(int *)(iVar1 + 0xcfc) = iVar4;

    }

    iVar4 = FUN_00458c90(*(undefined1 *)(param_1 + 9));

    if (iVar4 == 0) {

      *(undefined4 *)(iVar1 + 0xdb4) = 0;

      FUN_004bdbf0(iVar2);

    }

    else {

      *(undefined4 *)(iVar1 + 0xdb4) = 3;

      *(uint *)(iVar1 + 0xd88) = (uint)*(byte *)(param_1 + 9);

      FUN_004bdaa0();

    }

    if (0.0 < *(float *)(param_1 + 10)) {

      FUN_004bfbf0(iVar2);

      *(undefined4 *)(iVar1 + 0xe30) = *(undefined4 *)(param_1 + 10);

    }

    piVar3 = DAT_00632d68;

    if (*(int *)(param_1 + 0xe) != 0) {

      for (; piVar3 != (int *)0x0; piVar3 = (int *)*piVar3) {

        iVar1 = piVar3[3];

        if (((*(uint *)(iVar1 + 0xd8) & 0x8000) == 0) &&

           (*(int *)(iVar1 + 0x188) == *(int *)(param_1 + 0xe))) {

          FUN_004d5910(iVar2,iVar1);

          FUN_00497570(iVar2);

          break;

        }

      }

    }

    if ((*(int *)(param_1 + 0x12) != 0) && (piVar3 = DAT_00632d68, DAT_00632d68 != (int *)0x0)) {

      while ((iVar1 = piVar3[3], (*(uint *)(iVar1 + 0xd8) & 0x8000) != 0 ||

             (*(int *)(iVar1 + 0x188) != *(int *)(param_1 + 0x12)))) {

        piVar3 = (int *)*piVar3;

        if (piVar3 == (int *)0x0) {

          return;

        }

      }

      FUN_0050c1c0(iVar1,iVar2);

      FUN_00497570(iVar2);

    }

  }

  return;

}

/* ===== FUN_005338e0 @ 0x005338E0 ===== */
void FUN_005338e0(int param_1)



{

  int iVar1;

  int *piVar2;

  int iVar3;

  int iVar4;

  int *piVar5;

  int *piVar6;

  int iVar7;

  

  iVar3 = FUN_0052aa70();

  if (((iVar3 != 0) && (9 < DAT_00632f08)) && (piVar6 = DAT_00632d68, DAT_00632d68 != (int *)0x0)) {

    while ((iVar3 = piVar6[3], (*(uint *)(iVar3 + 0xd8) & 0x8000) != 0 ||

           (*(int *)(iVar3 + 0x188) != *(int *)(param_1 + 1)))) {

      piVar6 = (int *)*piVar6;

      if (piVar6 == (int *)0x0) {

        return;

      }

    }

    iVar4 = FUN_0045d300(iVar3);

    if (iVar4 != 0) {

      iVar4 = *(int *)(iVar3 + 0x100);

      piVar6 = (int *)(param_1 + 5);

      iVar7 = 2;

      do {

        piVar5 = DAT_00632d68;

        if (*piVar6 != 0) {

          for (; piVar5 != (int *)0x0; piVar5 = (int *)*piVar5) {

            iVar1 = piVar5[3];

            if (((*(uint *)(iVar1 + 0xd8) & 0x8000) == 0) && (*(int *)(iVar1 + 0x188) == *piVar6)) {

              FUN_0045b670(iVar3,iVar1,piVar6[4],piVar6[2],0);

              break;

            }

          }

        }

        piVar6 = piVar6 + 1;

        iVar7 = iVar7 + -1;

      } while (iVar7 != 0);

      piVar6 = (int *)(param_1 + 0x1d);

      iVar7 = 2;

      do {

        piVar5 = DAT_00632d68;

        if (*piVar6 != 0) {

          for (; piVar5 != (int *)0x0; piVar5 = (int *)*piVar5) {

            iVar1 = piVar5[3];

            if (((*(uint *)(iVar1 + 0xd8) & 0x8000) == 0) && (*(int *)(iVar1 + 0x188) == *piVar6)) {

              FUN_0045b670(iVar3,iVar1,piVar6[4],piVar6[2],0);

              break;

            }

          }

        }

        piVar6 = piVar6 + 1;

        iVar7 = iVar7 + -1;

      } while (iVar7 != 0);

      piVar5 = (int *)(iVar4 + 0x23c);

      piVar6 = (int *)(param_1 + 0x39);

      iVar7 = 8;

      do {

        *piVar5 = 0;

        piVar2 = DAT_00632d68;

        if (*piVar6 != 0) {

          for (; piVar2 != (int *)0x0; piVar2 = (int *)*piVar2) {

            iVar1 = piVar2[3];

            if (((*(byte *)(iVar1 + 0xd9) & 0x80) == 0) && (*(int *)(iVar1 + 0x188) == *piVar6)) {

              if (piVar5[-4] != 0) {

                *(int *)(piVar5[-4] + 0x274) = iVar1;

              }

              break;

            }

          }

          *piVar5 = piVar6[8];

        }

        piVar6 = piVar6 + 1;

        piVar5 = piVar5 + 7;

        iVar7 = iVar7 + -1;

      } while (iVar7 != 0);

      piVar6 = DAT_00632d68;

      if (*(int *)(param_1 + 0x35) != 0) {

        for (; piVar6 != (int *)0x0; piVar6 = (int *)*piVar6) {

          iVar7 = piVar6[3];

          if (((*(uint *)(iVar7 + 0xd8) & 0x8000) == 0) &&

             (*(int *)(iVar7 + 0x188) == *(int *)(param_1 + 0x35))) goto LAB_00533a8f;

        }

        iVar7 = 0;

LAB_00533a8f:

        *(int *)(iVar4 + 0x30c) = iVar7;

      }

      *(undefined4 *)(iVar4 + 0x158) = *(undefined4 *)(param_1 + 0x89);

      *(undefined4 *)(iVar4 + 0x15c) = *(undefined4 *)(param_1 + 0x8d);

      FUN_0045c3e0(iVar3);

      *(undefined4 *)(iVar3 + 0x278) = *(undefined4 *)(param_1 + 0x91);

      *(undefined1 *)(iVar4 + 0x228) = *(undefined1 *)(param_1 + 0x95);

      FUN_004034a0(iVar3,*(undefined4 *)(param_1 + 0x7d),*(undefined4 *)(param_1 + 0x81),

                   *(undefined4 *)(param_1 + 0x85),*(undefined4 *)(param_1 + 0x79),0);

    }

  }

  return;

}

/* ===== FUN_00533b00 @ 0x00533B00 ===== */
/* PS2 candidate: mecc_do_flare__FP6OBJECT (conf 0.358) */



void FUN_00533b00(int param_1)



{

  undefined4 uVar1;

  int iVar2;

  int iVar3;

  undefined4 *puVar4;

  int iVar5;

  

  iVar5 = FUN_0052aa70();

  if ((iVar5 != 0) && (puVar4 = DAT_00632d68, 9 < DAT_00632f08)) {

    for (; puVar4 != (undefined4 *)0x0; puVar4 = (undefined4 *)*puVar4) {

      iVar5 = puVar4[3];

      if (((*(uint *)(iVar5 + 0xd8) & 0x8000) == 0) &&

         (*(int *)(iVar5 + 0x188) == *(int *)(param_1 + 1))) goto LAB_00533b86;

    }

    iVar5 = FUN_00496c00(0x2e9,0x80000000);

    if (iVar5 != 0) {

      *(undefined4 *)(iVar5 + 0x188) = *(undefined4 *)(param_1 + 1);

      FUN_00499e70(iVar5,0x4b);

      FUN_0046b3f0(iVar5,param_1 + 5);

LAB_00533b86:

      iVar2 = *(int *)(iVar5 + 0x100);

      puVar4 = DAT_00632d68;

      if (*(int *)(param_1 + 0x1d) != 0) {

        for (; puVar4 != (undefined4 *)0x0; puVar4 = (undefined4 *)*puVar4) {

          iVar3 = puVar4[3];

          if (((*(uint *)(iVar3 + 0xd8) & 0x8000) == 0) &&

             (*(int *)(iVar3 + 0x188) == *(int *)(param_1 + 0x1d))) {

            FUN_0046baf0(iVar5,iVar3,1,*(undefined1 *)(param_1 + 0x21),0);

            break;

          }

        }

      }

      puVar4 = DAT_00632d68;

      if (*(int *)(param_1 + 0x25) != 0) {

        for (; puVar4 != (undefined4 *)0x0; puVar4 = (undefined4 *)*puVar4) {

          iVar3 = puVar4[3];

          if (((*(uint *)(iVar3 + 0xd8) & 0x8000) == 0) &&

             (*(int *)(iVar3 + 0x188) == *(int *)(param_1 + 0x25))) {

            FUN_0046baf0(iVar5,iVar3,1,*(undefined1 *)(param_1 + 0x29),0);

            break;

          }

        }

      }

      *(undefined4 *)(iVar2 + 8) = *(undefined4 *)(param_1 + 0x11);

      uVar1 = *(undefined4 *)(param_1 + 0x15);

      *(undefined4 *)(iVar2 + 0xc) = uVar1;

      FUN_0046a480(iVar5,uVar1);

      *(undefined4 *)(iVar5 + 0x278) = *(undefined4 *)(param_1 + 0x19);

      FUN_004034a0(iVar5,*(undefined4 *)(param_1 + 0x31),*(undefined4 *)(param_1 + 0x35),

                   *(undefined4 *)(param_1 + 0x39),*(undefined4 *)(param_1 + 0x2d),0);

    }

  }

  return;

}

/* ===== FUN_00533c60 @ 0x00533C60 ===== */
void FUN_00533c60(int param_1)



{

  undefined4 *puVar1;

  undefined4 *puVar2;

  int iVar3;

  int iVar4;

  

  iVar3 = FUN_0052aa70();

  if ((iVar3 == 0) || (puVar1 = DAT_00632d68, DAT_00632f08 < 10)) {

    return;

  }

  for (; puVar2 = DAT_00632d68, puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {

    iVar3 = puVar1[3];

    if (((*(uint *)(iVar3 + 0xd8) & 0x8000) == 0) &&

       (*(int *)(iVar3 + 0x188) == *(int *)(param_1 + 3))) goto joined_r0x00533cb4;

  }

  iVar3 = 0;

joined_r0x00533cb4:

  do {

    if (puVar2 == (undefined4 *)0x0) {

      iVar4 = 0;

LAB_00533cde:

      if (iVar3 == 0) {

        if (iVar4 == 0) {

          FUN_0051ea20(s_no_base__wtf_0057ff70);

        }

        FUN_0041ae70(iVar4,(int)*(short *)(param_1 + 1),*(undefined4 *)(param_1 + 3),

                     *(undefined1 *)(param_1 + 7),param_1 + 0xc,*(undefined4 *)(param_1 + 0x18),

                     *(undefined4 *)(param_1 + 0x1c),*(undefined4 *)(param_1 + 0x20),

                     *(undefined4 *)(param_1 + 0x24));

        return;

      }

      if (*(int *)(iVar3 + 4) == (int)*(short *)(param_1 + 1)) {

        return;

      }

      FUN_0051ea20();

      return;

    }

    iVar4 = puVar2[3];

    if (((*(uint *)(iVar4 + 0xd8) & 0x8000) == 0) &&

       (*(int *)(iVar4 + 0x188) == *(int *)(param_1 + 8))) goto LAB_00533cde;

    puVar2 = (undefined4 *)*puVar2;

  } while( true );

}

/* ===== mecc_fire_logic__FP6OBJECT @ 0x00533D40 ===== */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

/* WARNING: Struct "OBJECT": ignoring multiple overlapping fields */

/* PS2 candidate: mapmode_object_is_shown__FP6OBJECT (conf 0.491) */



void mecc_fire_logic__FP6OBJECT(OBJECT *p0)



{

  float fVar1;

  undefined4 uVar2;

  undefined4 uVar3;

  uint *puVar4;

  uint uVar5;

  int iVar6;

  int iVar7;

  undefined4 uVar8;

  int iVar9;

  int *piVar10;

  int iVar11;

  undefined4 *puVar12;

  undefined4 *puVar13;

  float10 fVar14;

  undefined1 *puVar15;

  undefined4 local_248;

  undefined4 local_244;

  undefined1 local_240;

  undefined1 uStack_23f;

  undefined1 local_23a;

  undefined1 local_239;

  undefined4 *local_238;

  undefined1 auStack_234 [3];

  undefined2 uStack_231;

  undefined2 uStack_22f;

  undefined1 uStack_22d;

  undefined1 uStack_22c;

  undefined1 uStack_22b;

  undefined2 uStack_22a;

  undefined1 uStack_228;

  undefined1 uStack_227;

  undefined2 uStack_226;

  undefined1 uStack_224;

  undefined1 uStack_223;

  undefined2 uStack_222;

  undefined1 uStack_220;

  undefined1 uStack_21f;

  undefined2 uStack_21e;

  undefined1 uStack_21c;

  undefined1 uStack_21b;

  undefined2 uStack_21a;

  undefined1 uStack_218;

  undefined1 uStack_217;

  undefined2 uStack_216;

  undefined1 uStack_214;

  undefined1 uStack_213;

  undefined2 uStack_212;

  undefined1 uStack_210;

  undefined1 uStack_20f;

  undefined1 uStack_20e;

  undefined1 uStack_20d;

  undefined1 uStack_20c;

  undefined1 uStack_20b;

  undefined1 auStack_208 [5];

  undefined4 uStack_203;

  undefined1 uStack_1ff;

  undefined1 uStack_1fe;

  undefined1 uStack_1fd;

  uint uStack_1fc;

  undefined4 uStack_1f8;

  undefined4 uStack_1f4;

  undefined4 uStack_1f0;

  undefined1 uStack_1ec;

  undefined1 uStack_1eb;

  undefined2 uStack_1ea;

  undefined4 uStack_1e8;

  undefined1 uStack_1e4;

  uint uStack_1e3;

  undefined2 uStack_1df;

  undefined1 uStack_1dd;

  int iStack_1dc;

  undefined1 auStack_1d8 [5];

  undefined4 uStack_1d3;

  undefined4 uStack_1cf;

  undefined4 uStack_1cb;

  undefined4 uStack_1c7;

  undefined4 uStack_1c3;

  undefined4 uStack_1bf;

  undefined4 uStack_1bb;

  undefined4 uStack_1b7;

  undefined4 uStack_1b3;

  undefined4 uStack_1af;

  undefined4 uStack_1ab;

  undefined4 uStack_1a7;

  undefined4 uStack_1a3;

  undefined4 uStack_19f;

  undefined1 uStack_19b;

  undefined1 auStack_198 [2];

  undefined1 auStack_196 [3];

  int aiStack_193 [4];

  int aiStack_183 [8];

  undefined4 uStack_163;

  undefined4 auStack_15f [8];

  int aiStack_13f [8];

  undefined4 uStack_11f;

  undefined4 uStack_11b;

  undefined4 uStack_117;

  undefined4 uStack_113;

  undefined4 uStack_10f;

  undefined4 uStack_10b;

  undefined4 uStack_107;

  undefined1 uStack_103;

  undefined1 uStack_102;

  undefined1 local_100 [256];

  

  iVar6 = FUN_0052c5c0();

  if ((iVar6 != 0) && (iVar6 = FUN_0052aa70(), iVar6 != 0)) {

    iVar6 = 0;

    if ((DAT_006330e4 != 0) && ((DAT_00632ee4 != -1 && (DAT_00633044 != 0)))) {

      FUN_00425eb0(s_________________________0058017c);

      FUN_00425eb0(s_Sending_object_snapshot_00580164);

      FUN_00542f27(local_100,s__d_static_objects_00580150,*(undefined4 *)(DAT_006330e4 + 0x170));

      FUN_00425eb0(local_100);

      if (0 < *(int *)(DAT_006330e4 + 0x170)) {

        local_238 = (undefined4 *)0x0;

        iVar9 = DAT_006330e4;

        do {

          iVar11 = *(int *)(iVar9 + 0x174) + (int)local_238;

          for (puVar13 = DAT_00632d68; puVar13 != (undefined4 *)0x0;

              puVar13 = (undefined4 *)*puVar13) {

            iVar9 = puVar13[3];

            if (*(int *)(iVar11 + 0x274) == iVar9) {

              iVar7 = FUN_0052aa70();

              if (iVar7 != 0) {

                uStack_23f = 0;

                local_248._1_3_ = (undefined3)iVar6;

                local_248 = CONCAT31(local_248._1_3_,6);

                local_244._1_3_ = (undefined3)*(undefined4 *)(iVar9 + 0x188);

                local_244 = CONCAT31(local_244._1_3_,(char)((uint)iVar6 >> 0x18));

                local_240 = (undefined1)((uint)*(undefined4 *)(iVar9 + 0x188) >> 0x18);

                FUN_0052b4e0(DAT_005e02e8,10,&local_248);

              }

              uVar8 = FUN_0049a180(*(undefined4 *)(iVar9 + 0x1e0));

              FUN_00425eb0(uVar8);

            }

            iVar9 = DAT_006330e4;

          }

          iVar6 = iVar6 + 1;

          local_238 = (undefined4 *)((int)local_238 + 0x304);

        } while (iVar6 < *(int *)(iVar9 + 0x170));

      }

      FUN_00425eb0(s_Sending_players_0058013c);

      for (puVar13 = DAT_00632d68; puVar13 != (undefined4 *)0x0; puVar13 = (undefined4 *)*puVar13) {

        iVar6 = puVar13[3];

        if ((*(byte *)(iVar6 + 0x1c8) & 1) != 0) {

          iVar9 = FUN_0052aa70();

          if (iVar9 != 0) {

            local_240 = (undefined1)((uint)*(undefined4 *)(iVar6 + 4) >> 0x18);

            local_248._1_3_ = (undefined3)*(undefined4 *)(iVar6 + 0x188);

            local_248 = CONCAT31(local_248._1_3_,7);

            local_244._0_1_ = (undefined1)((uint)*(undefined4 *)(iVar6 + 0x188) >> 0x18);

            local_244 = CONCAT31((int3)*(undefined4 *)(iVar6 + 4),(undefined1)local_244);

            uStack_23f = 0;

            iVar9 = FUN_0052c5c0();

            if (iVar9 == 0) {

              FUN_0052b8c0(10,&local_248);

            }

            else {

              FUN_0052b780(0,10,&local_248);

            }

          }

          uVar8 = FUN_0049a180(*(undefined4 *)(iVar6 + 0x1e0));

          FUN_00542f27(local_100,s_sending_player_id__d__type__s_0058011c,

                       *(undefined4 *)(iVar6 + 0x188),uVar8);

          FUN_00425eb0(local_100);

        }

      }

      FUN_00425eb0(s_Sending_bases_0058010c);

      for (puVar13 = DAT_00632d9c; puVar13 != (undefined4 *)0x0; puVar13 = (undefined4 *)*puVar13) {

        iVar6 = puVar13[3];

        iVar9 = FUN_004a6200(iVar6);

        if ((iVar9 != 0) || (iVar9 = FUN_004a6290(iVar6), iVar9 != 0)) {

          iVar9 = FUN_0052aa70();

          if (iVar9 != 0) {

            auStack_234._1_2_ = *(ushort *)(iVar6 + 4);

            uVar8 = *(undefined4 *)(iVar6 + 0x18c);

            uStack_231 = (undefined2)*(undefined4 *)(iVar6 + 0x188);

            uStack_22f = (undefined2)((uint)*(undefined4 *)(iVar6 + 0x188) >> 0x10);

            uVar2 = *(undefined4 *)(iVar6 + 0xa0);

            uStack_22c = (undefined1)uVar8;

            uStack_22b = (undefined1)((uint)uVar8 >> 8);

            uStack_22a = (undefined2)((uint)uVar8 >> 0x10);

            uVar8 = *(undefined4 *)(iVar6 + 0xa4);

            uVar3 = *(undefined4 *)(iVar6 + 0xa8);

            uStack_228 = (undefined1)uVar2;

            uStack_227 = (undefined1)((uint)uVar2 >> 8);

            uStack_226 = (undefined2)((uint)uVar2 >> 0x10);

            uVar2 = *(undefined4 *)(iVar6 + 200);

            auStack_234[0] = 0x1f;

            uStack_224 = (undefined1)uVar8;

            uStack_223 = (undefined1)((uint)uVar8 >> 8);

            uStack_222 = (undefined2)((uint)uVar8 >> 0x10);

            uStack_220 = (undefined1)uVar3;

            uStack_21f = (undefined1)((uint)uVar3 >> 8);

            uStack_21e = (undefined2)((uint)uVar3 >> 0x10);

            uStack_21c = (undefined1)uVar2;

            uStack_21b = (undefined1)((uint)uVar2 >> 8);

            uStack_21a = (undefined2)((uint)uVar2 >> 0x10);

            fVar14 = (float10)FUN_00417f20(iVar6);

            fVar1 = (float)fVar14;

            uStack_218 = SUB41(fVar1,0);

            uStack_217 = (undefined1)((uint)fVar1 >> 8);

            uStack_216 = (undefined2)((uint)fVar1 >> 0x10);

            uVar8 = *(undefined4 *)(iVar6 + 0x278);

            uStack_214 = (undefined1)uVar8;

            uStack_213 = (undefined1)((uint)uVar8 >> 8);

            uStack_212 = (undefined2)((uint)uVar8 >> 0x10);

            uStack_20c = 0;

            FUN_0052b4e0(DAT_005e02e8,0x29,auStack_234);

          }

          FUN_00542f27(local_100,s_base_objtype__d_005800fc,*(undefined4 *)(iVar6 + 4));

          FUN_00425eb0(local_100);

        }

      }

      FUN_00425eb0(s_Sending_base_buildings_005800e0);

      for (puVar13 = DAT_00632d9c; puVar13 != (undefined4 *)0x0; puVar13 = (undefined4 *)*puVar13) {

        iVar6 = puVar13[3];

        if ((*(int *)(iVar6 + 0x274) != 0) &&

           ((iVar9 = FUN_004a6220(iVar6), iVar9 != 0 || (iVar9 = FUN_004a6300(iVar6), iVar9 != 0))))

        {

          iVar9 = FUN_0052aa70();

          if (iVar9 != 0) {

            auStack_234._1_2_ = *(ushort *)(iVar6 + 4);

            uStack_231 = (undefined2)*(undefined4 *)(iVar6 + 0x188);

            uStack_22f = (undefined2)((uint)*(undefined4 *)(iVar6 + 0x188) >> 0x10);

            uStack_22d = *(undefined1 *)(iVar6 + 0xe4);

            auStack_234[0] = 0x1e;

            uVar8 = *(undefined4 *)(*(int *)(iVar6 + 0x274) + 0x188);

            uStack_22c = (undefined1)uVar8;

            uStack_22b = (undefined1)((uint)uVar8 >> 8);

            uStack_22a = (undefined2)((uint)uVar8 >> 0x10);

            uVar8 = *(undefined4 *)(iVar6 + 0xa0);

            uVar2 = *(undefined4 *)(iVar6 + 0xa4);

            uVar3 = *(undefined4 *)(iVar6 + 0xa8);

            uStack_228 = (undefined1)uVar8;

            uStack_227 = (undefined1)((uint)uVar8 >> 8);

            uStack_226 = (undefined2)((uint)uVar8 >> 0x10);

            uVar8 = *(undefined4 *)(iVar6 + 200);

            uStack_224 = (undefined1)uVar2;

            uStack_223 = (undefined1)((uint)uVar2 >> 8);

            uStack_222 = (undefined2)((uint)uVar2 >> 0x10);

            uStack_220 = (undefined1)uVar3;

            uStack_21f = (undefined1)((uint)uVar3 >> 8);

            uStack_21e = (undefined2)((uint)uVar3 >> 0x10);

            uStack_21c = (undefined1)uVar8;

            uStack_21b = (undefined1)((uint)uVar8 >> 8);

            uStack_21a = (undefined2)((uint)uVar8 >> 0x10);

            fVar14 = (float10)FUN_00417f20(iVar6);

            fVar1 = (float)fVar14;

            uStack_218 = SUB41(fVar1,0);

            uStack_217 = (undefined1)((uint)fVar1 >> 8);

            uStack_216 = (undefined2)((uint)fVar1 >> 0x10);

            uVar8 = *(undefined4 *)(iVar6 + 0x278);

            uVar2 = *(undefined4 *)(iVar6 + 0xf4);

            uStack_214 = (undefined1)uVar8;

            uStack_213 = (undefined1)((uint)uVar8 >> 8);

            uStack_212 = (undefined2)((uint)uVar8 >> 0x10);

            uStack_210 = (undefined1)uVar2;

            uStack_20f = (undefined1)((uint)uVar2 >> 8);

            uStack_20e = (undefined1)((uint)uVar2 >> 0x10);

            uStack_20d = (undefined1)((uint)uVar2 >> 0x18);

            iVar9 = FUN_004a6220(iVar6);

            if (iVar9 == 0) {

              FUN_004b6f60(iVar6);

            }

            else {

              FUN_0040acf0();

            }

            uStack_20c = 0;

            FUN_0052b4e0(DAT_005e02e8,0x29,auStack_234);

          }

          FUN_00542f27(local_100,s_base_building_objtype__d_005800c4,*(undefined4 *)(iVar6 + 4));

          FUN_00425eb0(local_100);

        }

      }

      FUN_00425eb0(s_Sending_smarties_005800b0);

      for (puVar13 = DAT_00632d98; puVar13 != (undefined4 *)0x0; puVar13 = (undefined4 *)*puVar13) {

        iVar6 = puVar13[3];

        if (((*(uint *)(iVar6 + 0xd8) & 0x8000) == 0) &&

           (((iVar9 = *(int *)(iVar6 + 4), iVar9 == 0xb || (iVar9 == 0x248)) || (iVar9 == 0x2e6))))

        {

          FUN_0052fd50(iVar6);

          FUN_00542f27(local_100,s_smartie_objtype__d_0058009c,*(undefined4 *)(iVar6 + 4));

          FUN_00425eb0(local_100);

        }

      }

      FUN_00425eb0(s_Sending_vimps_0058008c);

      for (puVar13 = DAT_00632d90; puVar13 != (undefined4 *)0x0; puVar13 = (undefined4 *)*puVar13) {

        iVar6 = puVar13[3];

        if ((((*(uint *)(iVar6 + 0xd8) & 0x8000) == 0) && (*(int *)(iVar6 + 4) == 8)) &&

           (*(int *)(iVar6 + 0x274) != 0)) {

          iVar9 = *(int *)(iVar6 + 0x100);

          iVar11 = FUN_0052aa70();

          if (iVar11 != 0) {

            puVar12 = (undefined4 *)auStack_208;

            for (iVar11 = 9; iVar11 != 0; iVar11 = iVar11 + -1) {

              *puVar12 = 0;

              puVar12 = puVar12 + 1;

            }

            uVar8 = *(undefined4 *)(iVar6 + 0x188);

            *(undefined2 *)puVar12 = 0;

            auStack_208[0] = 0x37;

            uStack_1eb = (undefined1)uVar8;

            uStack_1ea = (undefined2)((uint)uVar8 >> 8);

            if (*(int *)(iVar6 + 0x274) == 0) {

              uStack_1e8._1_3_ = 0;

              uStack_1e4 = 0;

            }

            else {

              uVar2 = *(undefined4 *)(*(int *)(iVar6 + 0x274) + 0x188);

              uStack_1e8._1_3_ = (undefined3)uVar2;

              uStack_1e4 = (undefined1)((uint)uVar2 >> 0x18);

            }

            uStack_1e8 = CONCAT31(uStack_1e8._1_3_,(char)((uint)uVar8 >> 0x18));

            auStack_208._1_4_ = *(undefined4 *)(iVar9 + 0x4c);

            uStack_203 = *(undefined4 *)(iVar6 + 0xa0);

            uVar8 = *(undefined4 *)(iVar6 + 0xa4);

            uStack_1ff = (undefined1)uVar8;

            uStack_1fe = (undefined1)((uint)uVar8 >> 8);

            uStack_1fd = (undefined1)((uint)uVar8 >> 0x10);

            uStack_1fc._1_3_ = (undefined3)*(undefined4 *)(iVar6 + 0xa8);

            uStack_1fc = CONCAT31(uStack_1fc._1_3_,(char)((uint)uVar8 >> 0x18));

            uStack_1f8._1_3_ = (undefined3)*(undefined4 *)(iVar9 + 0x40);

            uStack_1f8 = CONCAT31(uStack_1f8._1_3_,

                                  (char)((uint)*(undefined4 *)(iVar6 + 0xa8) >> 0x18));

            uStack_1f4._1_3_ = (undefined3)*(undefined4 *)(iVar9 + 0x44);

            uStack_1f4 = CONCAT31(uStack_1f4._1_3_,

                                  (char)((uint)*(undefined4 *)(iVar9 + 0x40) >> 0x18));

            uStack_1f0._1_3_ = (undefined3)*(undefined4 *)(iVar9 + 0x48);

            uStack_1f0 = CONCAT31(uStack_1f0._1_3_,

                                  (char)((uint)*(undefined4 *)(iVar9 + 0x44) >> 0x18));

            uStack_1ec = (undefined1)((uint)*(undefined4 *)(iVar9 + 0x48) >> 0x18);

            uStack_1e3 = uStack_1e3 & 0xffffff00;

            FUN_0052b4e0(DAT_005e02e8,0x26,auStack_208);

          }

        }

      }

      FUN_00425eb0(s_Sending_projectiles_00580074);

      for (puVar13 = DAT_00632d68; puVar13 != (undefined4 *)0x0; puVar13 = (undefined4 *)*puVar13) {

        iVar6 = puVar13[3];

        if ((-1 < (char)((uint)*(undefined4 *)(iVar6 + 0xd8) >> 8)) &&

           (*(int *)(iVar6 + 0x1e0) == 0x4d)) {

          iVar9 = *(int *)(iVar6 + 0x100);

          iVar11 = FUN_0052aa70();

          if (iVar11 != 0) {

            puVar12 = (undefined4 *)auStack_234;

            for (iVar11 = 10; iVar11 != 0; iVar11 = iVar11 + -1) {

              *puVar12 = 0;

              puVar12 = puVar12 + 1;

            }

            *(undefined2 *)puVar12 = 0;

            uVar8 = *(undefined4 *)(iVar6 + 0x188);

            uStack_22f = (undefined2)uVar8;

            uStack_22d = (undefined1)((uint)uVar8 >> 0x10);

            uStack_22c = (undefined1)((uint)uVar8 >> 0x18);

            auStack_234[0] = 0x19;

            if (*(int *)(iVar6 + 0x274) == 0) {

              uStack_20f = 0;

              uStack_20e = 0;

              uStack_20d = 0;

              uStack_20c = 0;

            }

            else {

              uVar8 = *(undefined4 *)(*(int *)(iVar6 + 0x274) + 0x188);

              uStack_20f = (undefined1)uVar8;

              uStack_20e = (undefined1)((uint)uVar8 >> 8);

              uStack_20d = (undefined1)((uint)uVar8 >> 0x10);

              uStack_20c = (undefined1)((uint)uVar8 >> 0x18);

            }

            uVar8 = *(undefined4 *)(iVar6 + 0x18c);

            uStack_22b = (undefined1)uVar8;

            uStack_22a = (undefined2)((uint)uVar8 >> 8);

            uStack_228 = (undefined1)((uint)uVar8 >> 0x18);

            uStack_20b = 0;

            auStack_234[2] = 0;

            auStack_234[1] = *(byte *)(iVar9 + 0x1e4);

            uStack_231 = 0;

            uVar8 = *(undefined4 *)(iVar6 + 0xa0);

            uVar2 = *(undefined4 *)(iVar6 + 0xa4);

            uVar3 = *(undefined4 *)(iVar6 + 0xa8);

            uStack_227 = (undefined1)uVar8;

            uStack_226 = (undefined2)((uint)uVar8 >> 8);

            uStack_224 = (undefined1)((uint)uVar8 >> 0x18);

            uVar8 = *(undefined4 *)(iVar6 + 0x128);

            uStack_223 = (undefined1)uVar2;

            uStack_222 = (undefined2)((uint)uVar2 >> 8);

            uStack_220 = (undefined1)((uint)uVar2 >> 0x18);

            uVar2 = *(undefined4 *)(iVar6 + 300);

            uStack_21b = (undefined1)uVar8;

            uStack_21a = (undefined2)((uint)uVar8 >> 8);

            uStack_218 = (undefined1)((uint)uVar8 >> 0x18);

            uStack_217 = (undefined1)uVar2;

            uStack_216 = (undefined2)((uint)uVar2 >> 8);

            uStack_214 = (undefined1)((uint)uVar2 >> 0x18);

            uStack_21f = (undefined1)uVar3;

            uStack_21e = (undefined2)((uint)uVar3 >> 8);

            uStack_21c = (undefined1)((uint)uVar3 >> 0x18);

            uVar8 = *(undefined4 *)(iVar6 + 0x130);

            uStack_213 = (undefined1)uVar8;

            uStack_212 = (undefined2)((uint)uVar8 >> 8);

            uStack_210 = (undefined1)((uint)uVar8 >> 0x18);

            FUN_0052b4e0(DAT_005e02e8,0x2a,auStack_234);

          }

        }

      }

      FUN_00425eb0(s_Sending_turrets_00580060);

      for (puVar13 = DAT_00632d68; puVar13 != (undefined4 *)0x0; puVar13 = (undefined4 *)*puVar13) {

        iVar6 = puVar13[3];

        if (((-1 < (char)((uint)*(undefined4 *)(iVar6 + 0xd8) >> 8)) &&

            (*(int *)(iVar6 + 0x1e0) == 0x2c)) && (iVar9 = FUN_0052aa70(), iVar9 != 0)) {

          uVar8 = *(undefined4 *)(iVar6 + 4);

          puVar12 = (undefined4 *)auStack_208;

          for (iVar9 = 7; iVar9 != 0; iVar9 = iVar9 + -1) {

            *puVar12 = 0;

            puVar12 = puVar12 + 1;

          }

          uVar2 = *(undefined4 *)(iVar6 + 0x188);

          *(undefined2 *)puVar12 = 0;

          uVar3 = *(undefined4 *)(iVar6 + 0x18c);

          uStack_1ff = (undefined1)uVar3;

          uStack_1fe = (undefined1)((uint)uVar3 >> 8);

          uStack_1fd = (undefined1)((uint)uVar3 >> 0x10);

          uStack_1f4._1_3_ = (undefined3)*(undefined4 *)(iVar6 + 0xa8);

          uStack_1f4 = CONCAT31(uStack_1f4._1_3_,(char)((uint)*(undefined4 *)(iVar6 + 0xa4) >> 0x18)

                               );

          uStack_1fc._1_3_ = (undefined3)*(undefined4 *)(iVar6 + 0xa0);

          uStack_1fc = CONCAT31(uStack_1fc._1_3_,(char)((uint)uVar3 >> 0x18));

          uStack_1f8._0_1_ = (undefined1)((uint)*(undefined4 *)(iVar6 + 0xa0) >> 0x18);

          uStack_1f8 = CONCAT31((int3)*(undefined4 *)(iVar6 + 0xa4),(undefined1)uStack_1f8);

          auStack_208[0] = 0x22;

          uStack_1f0._1_3_ = (undefined3)*(undefined4 *)(iVar6 + 200);

          uStack_1f0 = CONCAT31(uStack_1f0._1_3_,(char)((uint)*(undefined4 *)(iVar6 + 0xa8) >> 0x18)

                               );

          uStack_1ec = (undefined1)((uint)*(undefined4 *)(iVar6 + 200) >> 0x18);

          uStack_1eb = 0;

          auStack_208._1_4_ = uVar8;

          uStack_203 = uVar2;

          FUN_0052b4e0(DAT_005e02e8,0x1e,auStack_208);

        }

      }

      FUN_00425eb0(s_Sending_health_snapshot_of_shoot_00580038);

      for (puVar13 = DAT_00632d68; puVar13 != (undefined4 *)0x0; puVar13 = (undefined4 *)*puVar13) {

        iVar6 = puVar13[3];

        if (((-1 < (char)((uint)*(undefined4 *)(iVar6 + 0xd8) >> 8)) &&

            (*(int *)(iVar6 + 0x1e0) == 0x3d)) &&

           ((*(float *)(iVar6 + 0x278) != 0.0 && (iVar9 = FUN_0052aa70(), iVar9 != 0)))) {

          uStack_23f = 0;

          local_248 = CONCAT31((int3)*(undefined4 *)(iVar6 + 0x188),0x24);

          local_244._1_3_ = (undefined3)*(undefined4 *)(iVar6 + 0x278);

          local_244 = CONCAT31(local_244._1_3_,(char)((uint)*(undefined4 *)(iVar6 + 0x188) >> 0x18))

          ;

          local_240 = (undefined1)((uint)*(undefined4 *)(iVar6 + 0x278) >> 0x18);

          FUN_0052b4e0(DAT_005e02e8,10,&local_248);

        }

      }

      FUN_00425eb0(s_Sending_gyros_jetskis_kbos_00580018);

      puVar13 = DAT_00632d68;

      do {

        if (puVar13 == (undefined4 *)0x0) {

          FUN_00425eb0(s_Sending_player_snapshots_0057fffc);

          puVar13 = DAT_00632d68;

          do {

            local_238 = puVar13;

            if (puVar13 == (undefined4 *)0x0) {

              FUN_00425eb0(s_Sending_GiveItems_0057ffe8);

              for (puVar13 = DAT_00632d68; puVar13 != (undefined4 *)0x0;

                  puVar13 = (undefined4 *)*puVar13) {

                iVar6 = puVar13[3];

                if (((*(uint *)(iVar6 + 0xd8) & 0x8000) == 0) && (*(int *)(iVar6 + 0x1e0) == 0x25))

                {

                  FUN_0052fbf0(iVar6,1);

                }

              }

              FUN_00425eb0(s_Sending_scores_0057ffd4);

              FUN_00530180(DAT_005e02e8);

              FUN_00425eb0(s_Sending_smartie_counts_0057ffb8);

              FUN_0052f8f0(DAT_005e02e8);

              if (DAT_0059d99c != 0) {

                iVar6 = FUN_0052ab00(DAT_005e02e8);

                iVar9 = FUN_0052aa70();

                if (iVar9 != 0) {

                  local_248 = CONCAT31(local_248._1_3_,0x42);

                  FUN_00452ae0((int)&local_248 + 1,(int)&local_244 + 1);

                  uStack_23f = 0;

                  if (iVar6 == 0) {

                    FUN_0052b780(0,10,&local_248);

                  }

                  else {

                    FUN_0052b5a0(iVar6,10,&local_248);

                  }

                }

              }

              uVar8 = FUN_0052ab00(DAT_005e02e8);

              FUN_0052f300(uVar8);

              uVar8 = FUN_0052ab00(DAT_005e02e8);

              FUN_00534ec0(uVar8);

              iVar6 = FUN_00426540();

              if (iVar6 != 0) {

                if (DAT_005def94 == 0) {

                  if (DAT_0063325c != 0) {

                    uVar8 = FUN_0052ab00(DAT_005e02e8);

                    FUN_0052f350(0,uVar8);

                  }

                }

                else {

                  uVar8 = FUN_0052ab00(DAT_005e02e8,DAT_005def94);

                  FUN_0052f350(uVar8);

                }

              }

              if (DAT_00633260 != '\0') {

                uVar8 = FUN_0052ab00(DAT_005e02e8);

                FUN_0052ea80(&DAT_00633260,1,0,uVar8);

              }

              FUN_00425eb0(s_Sending_completion_marker_0057ff9c);

              local_23a = 0x10;

              local_239 = 0;

              FUN_0052b4e0(DAT_005e02e8,2,&local_23a);

              FUN_00425eb0(s_________________________0058017c);

              return;

            }

            iVar6 = puVar13[3];

            if (-1 < (char)((uint)*(undefined4 *)(iVar6 + 0xd8) >> 8)) {

              iVar9 = FUN_004a6160(iVar6);

              if (iVar9 == 0) {

                iVar9 = FUN_004a6180(iVar6);

                if (iVar9 == 0) {

                  iVar9 = FUN_004a61a0(iVar6);

                  if (iVar9 != 0) {

                    iVar9 = *(int *)(iVar6 + 0x100);

                    iStack_1dc = iVar9;

                    iVar11 = FUN_0052aa70();

                    if (iVar11 != 0) {

                      puVar13 = (undefined4 *)auStack_198;

                      for (iVar11 = 0x25; iVar11 != 0; iVar11 = iVar11 + -1) {

                        *puVar13 = 0;

                        puVar13 = puVar13 + 1;

                      }

                      *(undefined2 *)puVar13 = 0;

                      *(undefined1 *)((int)puVar13 + 2) = 0;

                      unique0x00017200 = *(undefined4 *)(iVar6 + 0x188);

                      iVar11 = -iVar9;

                      auStack_198[0] = 0x2d;

                      piVar10 = (int *)(iVar9 + 0x10);

                      iVar9 = 0;

                      do {

                        if (*piVar10 == 0) {

                          *(undefined4 *)(auStack_196 + iVar9 * 4 + 3) = 0;

                        }

                        else {

                          *(undefined4 *)(auStack_196 + iVar9 * 4 + 3) =

                               *(undefined4 *)(*piVar10 + 0x188);

                          *(int *)((int)piVar10 + (int)(auStack_196 + iVar11 + 3)) = piVar10[8];

                          aiStack_193[iVar9 + 2] = *(int *)(*piVar10 + 0x218);

                        }

                        iVar9 = iVar9 + 1;

                        piVar10 = piVar10 + 1;

                      } while (iVar9 < 2);

                      piVar10 = (int *)(iStack_1dc + 8);

                      iVar9 = (int)aiStack_193 + iVar11 + 0x10;

                      iVar7 = 2;

                      do {

                        if (*piVar10 == 0) {

                          *(undefined4 *)(iVar9 + (int)piVar10) = 0;

                        }

                        else {

                          *(undefined4 *)(iVar9 + (int)piVar10) = *(undefined4 *)(*piVar10 + 0x188);

                          *(int *)((int)aiStack_193 + iVar11 + 0x20 + (int)piVar10) = piVar10[8];

                          *(undefined4 *)((int)aiStack_193 + iVar11 + 0x18 + (int)piVar10) =

                               *(undefined4 *)(*piVar10 + 0x218);

                        }

                        piVar10 = piVar10 + 1;

                        iVar7 = iVar7 + -1;

                      } while (iVar7 != 0);

                      iVar9 = 0;

                      piVar10 = (int *)(iStack_1dc + 0x22c);

                      do {

                        if ((*piVar10 == 0) || (iVar11 = *(int *)(*piVar10 + 0x274), iVar11 == 0)) {

                          auStack_15f[iVar9] = 0;

                        }

                        else {

                          auStack_15f[iVar9] = *(undefined4 *)(iVar11 + 0x188);

                        }

                        aiStack_13f[iVar9] = piVar10[4];

                        iVar9 = iVar9 + 1;

                        piVar10 = piVar10 + 7;

                      } while (iVar9 < 8);

                      uStack_163 = 0;

                      if (*(int *)(iStack_1dc + 0x30c) != 0) {

                        uStack_163 = *(undefined4 *)(*(int *)(iStack_1dc + 0x30c) + 0x188);

                      }

                      uStack_10f = *(undefined4 *)(iStack_1dc + 0x158);

                      uStack_10b = *(undefined4 *)(iStack_1dc + 0x15c);

                      uStack_107 = *(undefined4 *)(iVar6 + 0x278);

                      uStack_103 = *(undefined1 *)(iStack_1dc + 0x228);

                      uStack_11b = *(undefined4 *)(iVar6 + 0x10);

                      uStack_117 = *(undefined4 *)(iVar6 + 0x30);

                      uStack_113 = *(undefined4 *)(iVar6 + 0x20);

                      uStack_11f = *(undefined4 *)(iVar6 + 0x24);

                      uStack_102 = 0;

                      FUN_0052b4e0(DAT_005e02e8,0x97,auStack_198);

                      puVar13 = local_238;

                    }

                  }

                }

                else {

                  puVar4 = *(uint **)(iVar6 + 0x100);

                  iVar9 = FUN_0052aa70();

                  if (iVar9 != 0) {

                    puVar13 = (undefined4 *)auStack_234;

                    for (iVar9 = 9; iVar9 != 0; iVar9 = iVar9 + -1) {

                      *puVar13 = 0;

                      puVar13 = puVar13 + 1;

                    }

                    uVar8 = *(undefined4 *)(iVar6 + 0x278);

                    *(undefined2 *)puVar13 = 0;

                    *(undefined1 *)((int)puVar13 + 2) = 0;

                    auStack_234[0] = 0x2c;

                    auStack_234._1_2_ = (undefined2)*(undefined4 *)(iVar6 + 0x188);

                    uStack_231 = (undefined2)((uint)*(undefined4 *)(iVar6 + 0x188) >> 0x10);

                    uStack_22f = (undefined2)uVar8;

                    uStack_22d = (undefined1)((uint)uVar8 >> 0x10);

                    uStack_22c = (undefined1)((uint)uVar8 >> 0x18);

                    if (puVar4[0x33f] == 0) {

                      uStack_212 = 0;

                      uStack_210 = 0;

                      uStack_20f = 0;

                    }

                    else {

                      uVar8 = *(undefined4 *)(puVar4[0x33f] + 0x188);

                      uStack_212 = (undefined2)uVar8;

                      uStack_210 = (undefined1)((uint)uVar8 >> 0x10);

                      uStack_20f = (undefined1)((uint)uVar8 >> 0x18);

                    }

                    if ((int)puVar4[0x36d] < 1) {

                      uStack_22b = 0;

                    }

                    else {

                      uStack_22b = (undefined1)puVar4[puVar4[0x36d] * 2 + 0x35c];

                    }

                    uVar8 = *(undefined4 *)(iVar6 + 0xa0);

                    uVar2 = *(undefined4 *)(iVar6 + 0xa4);

                    uVar3 = *(undefined4 *)(iVar6 + 0xa8);

                    uStack_21e = (undefined2)uVar8;

                    uStack_21c = (undefined1)((uint)uVar8 >> 0x10);

                    uStack_21b = (undefined1)((uint)uVar8 >> 0x18);

                    uStack_21a = (undefined2)uVar2;

                    uStack_218 = (undefined1)((uint)uVar2 >> 0x10);

                    uStack_217 = (undefined1)((uint)uVar2 >> 0x18);

                    uStack_216 = (undefined2)uVar3;

                    uStack_214 = (undefined1)((uint)uVar3 >> 0x10);

                    uStack_213 = (undefined1)((uint)uVar3 >> 0x18);

                    if (puVar4[0x38b] != 0) {

                      uVar5 = puVar4[0x38c];

                      uStack_22a = (undefined2)uVar5;

                      uStack_228 = (undefined1)(uVar5 >> 0x10);

                      uStack_227 = (undefined1)(uVar5 >> 0x18);

                    }

                    iVar9 = FUN_004a6120(*(undefined4 *)(iVar6 + 0x210));

                    if (iVar9 != 0) {

                      uVar8 = *(undefined4 *)(*(int *)(iVar6 + 0x210) + 0x188);

                      uStack_226 = (undefined2)uVar8;

                      uStack_224 = (undefined1)((uint)uVar8 >> 0x10);

                      uStack_223 = (undefined1)((uint)uVar8 >> 0x18);

                    }

                    uStack_222 = 0;

                    uStack_220 = 0;

                    uStack_21f = 0;

                    puVar13 = DAT_00632d6c;

                    if ((*puVar4 & 0x200) != 0) {

                      for (; puVar13 != (undefined4 *)0x0; puVar13 = (undefined4 *)*puVar13) {

                        iVar9 = puVar13[3];

                        if ((*(int *)(iVar9 + 0x1e0) == 0x2c) &&

                           (*(int *)(*(int *)(iVar9 + 0x100) + 0x1c) == iVar6)) {

                          uVar8 = *(undefined4 *)(iVar9 + 0x188);

                          uStack_222 = (undefined2)uVar8;

                          uStack_220 = (undefined1)((uint)uVar8 >> 0x10);

                          uStack_21f = (undefined1)((uint)uVar8 >> 0x18);

                          break;

                        }

                      }

                    }

                    uStack_20e = 0;

                    FUN_0052b4e0(DAT_005e02e8,0x27,auStack_234);

                    puVar13 = local_238;

                  }

                }

              }

              else {

                iVar9 = *(int *)(iVar6 + 0x100);

                iVar11 = FUN_0052aa70();

                if (iVar11 != 0) {

                  uVar8 = *(undefined4 *)(iVar6 + 0x278);

                  puVar13 = (undefined4 *)auStack_208;

                  for (iVar11 = 9; iVar11 != 0; iVar11 = iVar11 + -1) {

                    *puVar13 = 0;

                    puVar13 = puVar13 + 1;

                  }

                  uVar2 = *(undefined4 *)(iVar6 + 0x188);

                  *(undefined1 *)puVar13 = 0;

                  auStack_208[0] = 0x2b;

                  uStack_1ff = *(undefined1 *)(iVar9 + 0x60);

                  iVar11 = *(int *)(iVar9 + 0x17c + *(int *)(iVar9 + 0x60) * 4);

                  uStack_1fe = 0xff;

                  if (iVar11 != -1) {

                    uStack_1fe = (undefined1)iVar11;

                  }

                  uStack_1fd = 0xff;

                  if (*(int *)(iVar9 + 0x18c) != -1) {

                    uStack_1fd = (undefined1)*(int *)(iVar9 + 0x18c);

                  }

                  uStack_1f4 = *(undefined4 *)(iVar6 + 0xa0);

                  uStack_1f0 = *(undefined4 *)(iVar6 + 0xa4);

                  uVar3 = *(undefined4 *)(iVar6 + 0xa8);

                  uStack_1ec = (undefined1)uVar3;

                  uStack_1eb = (undefined1)((uint)uVar3 >> 8);

                  uStack_1ea = (undefined2)((uint)uVar3 >> 0x10);

                  if (*(int *)(iVar9 + 0xd8) == 0) {

                    uStack_1e8 = 0;

                  }

                  else {

                    uStack_1e8 = *(undefined4 *)(*(int *)(iVar9 + 0xd8) + 0x188);

                  }

                  if ((*(uint *)(iVar6 + 0xe0) & 0x2000000) != 0) {

                    uStack_1fc = uStack_1fc | 1;

                  }

                  auStack_208._1_4_ = uVar2;

                  uStack_203 = uVar8;

                  iVar9 = FUN_0047f730(iVar6);

                  if (iVar9 != 0) {

                    uStack_1fc = uStack_1fc | 2;

                    iVar9 = FUN_00482310(iVar6);

                    if (iVar9 != 0) {

                      uStack_1f8 = *(undefined4 *)(iVar9 + 0x188);

                    }

                  }

                  iVar9 = *(int *)(iVar6 + 0x210);

                  if ((iVar9 != 0) && (*(int *)(iVar9 + 4) == 0x3df)) {

                    if ((*(uint *)(iVar9 + 0xe0) & 2) == 0) {

                      if ((*(uint *)(iVar9 + 0xe0) & 4) != 0) {

                        uStack_1fc = uStack_1fc | 8;

                      }

                    }

                    else {

                      uStack_1fc = uStack_1fc | 4;

                    }

                    uStack_1f8 = *(undefined4 *)(iVar9 + 0x188);

                  }

                  puVar13 = DAT_00632d6c;

                  if ((*(uint *)(iVar6 + 0xe0) & 0x20) != 0) {

                    for (; puVar13 != (undefined4 *)0x0; puVar13 = (undefined4 *)*puVar13) {

                      iVar9 = puVar13[3];

                      if ((*(int *)(iVar9 + 0x1e0) == 0x2c) &&

                         (*(int *)(*(int *)(iVar9 + 0x100) + 0x1c) == iVar6)) {

                        uStack_1fc = uStack_1fc | 0x20;

                        uStack_1f8 = *(undefined4 *)(iVar9 + 0x188);

                        break;

                      }

                    }

                  }

                  if ((*(uint *)(iVar6 + 0xe0) & 0x800000) != 0) {

                    uStack_1fc = uStack_1fc | 0x10;

                  }

                  uStack_1e4 = 0;

                  FUN_0052b4e0(DAT_005e02e8,0x25,auStack_208);

                  puVar13 = local_238;

                }

              }

            }

            puVar13 = (undefined4 *)*puVar13;

          } while( true );

        }

        iVar6 = puVar13[3];

        if (-1 < (char)((uint)*(undefined4 *)(iVar6 + 0xd8) >> 8)) {

          iVar9 = *(int *)(iVar6 + 0x1e0);

          if (iVar9 == 0x5f) {

            iVar9 = FUN_0052aa70();

            if (iVar9 != 0) {

              puVar12 = (undefined4 *)auStack_208;

              for (iVar9 = 0xb; iVar9 != 0; iVar9 = iVar9 + -1) {

                *puVar12 = 0;

                puVar12 = puVar12 + 1;

              }

              auStack_208._1_4_ = *(undefined4 *)(iVar6 + 0x188);

              uStack_203 = *(undefined4 *)(iVar6 + 0xa0);

              uVar8 = *(undefined4 *)(iVar6 + 0xa4);

              uStack_1ff = (undefined1)uVar8;

              uStack_1fe = (undefined1)((uint)uVar8 >> 8);

              uStack_1fd = (undefined1)((uint)uVar8 >> 0x10);

              uStack_1fc._1_3_ = (undefined3)*(undefined4 *)(iVar6 + 0xa8);

              uStack_1fc = CONCAT31(uStack_1fc._1_3_,(char)((uint)uVar8 >> 0x18));

              uVar8 = *(undefined4 *)(iVar6 + 200);

              uStack_1f0._1_3_ = (undefined3)*(undefined4 *)(iVar6 + 0x130);

              uStack_1f0 = CONCAT31(uStack_1f0._1_3_,

                                    (char)((uint)*(undefined4 *)(iVar6 + 300) >> 0x18));

              uStack_1ec = (undefined1)((uint)*(undefined4 *)(iVar6 + 0x130) >> 0x18);

              uStack_1f8._1_3_ = (undefined3)*(undefined4 *)(iVar6 + 0x128);

              uStack_1f8 = CONCAT31(uStack_1f8._1_3_,

                                    (char)((uint)*(undefined4 *)(iVar6 + 0xa8) >> 0x18));

              uStack_1f4._0_1_ = (undefined1)((uint)*(undefined4 *)(iVar6 + 0x128) >> 0x18);

              uStack_1f4 = CONCAT31((int3)*(undefined4 *)(iVar6 + 300),(undefined1)uStack_1f4);

              uStack_1eb = (undefined1)uVar8;

              uStack_1ea = (undefined2)((uint)uVar8 >> 8);

              puVar15 = auStack_208;

              uStack_1e8._1_3_ = (undefined3)*(undefined4 *)(iVar6 + 0x278);

              uStack_1e8 = CONCAT31(uStack_1e8._1_3_,(char)((uint)uVar8 >> 0x18));

              uStack_1e4 = (undefined1)((uint)*(undefined4 *)(iVar6 + 0x278) >> 0x18);

              uStack_1df = *(undefined2 *)(iVar6 + 0xe8);

              uStack_1e3 = *(int *)(iVar6 + 0x18c) << 0x10 | *(uint *)(iVar6 + 0xf4);

              auStack_208[0] = 0x2a;

              uStack_1dd = 0;

              uVar8 = 0x2c;

LAB_005347d1:

              FUN_0052b4e0(DAT_005e02e8,uVar8,puVar15);

            }

          }

          else if (iVar9 == 0x5a) {

            iVar9 = FUN_0052aa70();

            if (iVar9 != 0) {

              puVar12 = (undefined4 *)auStack_234;

              for (iVar9 = 10; iVar9 != 0; iVar9 = iVar9 + -1) {

                *puVar12 = 0;

                puVar12 = puVar12 + 1;

              }

              uVar8 = *(undefined4 *)(iVar6 + 0x188);

              *(undefined2 *)puVar12 = 0;

              uVar2 = *(undefined4 *)(iVar6 + 0xa0);

              auStack_234._1_2_ = (undefined2)uVar8;

              uStack_231 = (undefined2)((uint)uVar8 >> 0x10);

              uVar8 = *(undefined4 *)(iVar6 + 0xa4);

              uVar3 = *(undefined4 *)(iVar6 + 0xa8);

              uStack_22f = (undefined2)uVar2;

              uStack_22d = (undefined1)((uint)uVar2 >> 0x10);

              uStack_22c = (undefined1)((uint)uVar2 >> 0x18);

              uStack_22b = (undefined1)uVar8;

              uStack_22a = (undefined2)((uint)uVar8 >> 8);

              uStack_228 = (undefined1)((uint)uVar8 >> 0x18);

              uVar8 = *(undefined4 *)(iVar6 + 0x128);

              uStack_227 = (undefined1)uVar3;

              uStack_226 = (undefined2)((uint)uVar3 >> 8);

              uStack_224 = (undefined1)((uint)uVar3 >> 0x18);

              uVar2 = *(undefined4 *)(iVar6 + 300);

              uVar3 = *(undefined4 *)(iVar6 + 0x130);

              uStack_223 = (undefined1)uVar8;

              uStack_222 = (undefined2)((uint)uVar8 >> 8);

              uStack_220 = (undefined1)((uint)uVar8 >> 0x18);

              uVar8 = *(undefined4 *)(iVar6 + 200);

              uStack_21f = (undefined1)uVar2;

              uStack_21e = (undefined2)((uint)uVar2 >> 8);

              uStack_21c = (undefined1)((uint)uVar2 >> 0x18);

              uVar2 = *(undefined4 *)(iVar6 + 0x278);

              uStack_217 = (undefined1)uVar8;

              uStack_216 = (undefined2)((uint)uVar8 >> 8);

              uStack_214 = (undefined1)((uint)uVar8 >> 0x18);

              puVar15 = auStack_234;

              uStack_21b = (undefined1)uVar3;

              uStack_21a = (undefined2)((uint)uVar3 >> 8);

              uStack_218 = (undefined1)((uint)uVar3 >> 0x18);

              uVar3 = *(undefined4 *)(iVar6 + 0x18c);

              uStack_213 = (undefined1)uVar2;

              uStack_212 = (undefined2)((uint)uVar2 >> 8);

              uStack_210 = (undefined1)((uint)uVar2 >> 0x18);

              uVar8 = 0x2a;

              auStack_234[0] = 0x36;

              uStack_20f = (undefined1)uVar3;

              uStack_20e = (undefined1)((uint)uVar3 >> 8);

              uStack_20d = (undefined1)((uint)uVar3 >> 0x10);

              uStack_20c = (undefined1)((uint)uVar3 >> 0x18);

              uStack_20b = 0;

              goto LAB_005347d1;

            }

          }

          else if (iVar9 == 0x4b) {

            iVar9 = *(int *)(iVar6 + 0x100);

            iVar11 = FUN_0052aa70();

            if (iVar11 != 0) {

              puVar12 = (undefined4 *)auStack_1d8;

              for (iVar11 = 0xf; iVar11 != 0; iVar11 = iVar11 + -1) {

                *puVar12 = 0;

                puVar12 = puVar12 + 1;

              }

              *(undefined2 *)puVar12 = 0;

              auStack_1d8._1_4_ = *(undefined4 *)(iVar6 + 0x188);

              uStack_19b = 0;

              auStack_1d8[0] = 0x39;

              if (*(int *)(iVar9 + 0x7c) == 0) {

                uStack_1bb = 0;

              }

              else {

                uStack_1bb = *(undefined4 *)(*(int *)(iVar9 + 0x7c) + 0x188);

                uStack_1b7 = *(undefined4 *)(*(int *)(iVar9 + 0x7c) + 0x218);

              }

              if (*(int *)(iVar9 + 0x80) == 0) {

                uStack_1b3 = 0;

              }

              else {

                uStack_1b3 = *(undefined4 *)(*(int *)(iVar9 + 0x80) + 0x188);

                uStack_1af = *(undefined4 *)(*(int *)(iVar9 + 0x80) + 0x218);

              }

              uStack_1c7 = *(undefined4 *)(iVar9 + 8);

              uStack_1bf = *(undefined4 *)(iVar6 + 0x278);

              uStack_1c3 = *(undefined4 *)(iVar9 + 0xc);

              uStack_1d3 = *(undefined4 *)(iVar6 + 0xa0);

              uStack_1cf = *(undefined4 *)(iVar6 + 0xa4);

              uStack_1cb = *(undefined4 *)(iVar6 + 0xa8);

              uStack_1a3 = *(undefined4 *)(iVar6 + 0x30);

              uStack_1a7 = *(undefined4 *)(iVar6 + 0x10);

              puVar15 = auStack_1d8;

              uStack_19f = *(undefined4 *)(iVar6 + 0x20);

              uStack_1ab = *(undefined4 *)(iVar6 + 0x24);

              uVar8 = 0x3e;

              goto LAB_005347d1;

            }

          }

        }

        puVar13 = (undefined4 *)*puVar13;

      } while( true );

    }

    local_23a = 0xf;

    local_239 = 0;

    FUN_0052b4e0(DAT_005e02e8,2,&local_23a);

  }

  return;

}

/* ===== FUN_00534ec0 @ 0x00534EC0 ===== */
void FUN_00534ec0(int param_1)



{

  undefined4 uVar1;

  int iVar2;

  undefined4 local_4;

  

  iVar2 = FUN_0052aa70();

  if (iVar2 != 0) {

    local_4 = CONCAT31(CONCAT21(local_4._2_2_,DAT_00633254),0x46);

    uVar1 = local_4;

    local_4._0_3_ = (uint3)(ushort)uVar1;

    if (param_1 != 0) {

      FUN_0052b5a0(param_1,3,&local_4);

      return;

    }

    FUN_0052b780(0,3,&local_4);

  }

  return;

}

/* ===== FUN_00534f10 @ 0x00534F10 ===== */
void FUN_00534f10(int param_1)



{

  int *piVar1;

  undefined4 uVar2;

  int iVar3;

  int *piVar4;

  int iVar5;

  undefined4 *puVar6;

  undefined4 *puVar7;

  

  iVar3 = FUN_0052aa70();

  if (iVar3 != 0) {

    iVar3 = FUN_0052c5c0();

    puVar6 = DAT_005e0304;

    uVar2 = DAT_005e02e8;

    if (iVar3 != 0) {

      if (0x3ff < (int)((int)DAT_005df2c0 + -0x5df2a6)) {

        FUN_005359a0();

      }

      *(char *)DAT_005df2c0 = (char)uVar2;

      DAT_005df2c0 = (undefined4 *)((int)DAT_005df2c0 + 1);

      *(undefined2 *)DAT_005df2c0 = 0x1a;

      DAT_005df2c0 = (undefined4 *)((int)DAT_005df2c0 + 2);

      puVar7 = DAT_005df2c0;

      for (iVar3 = 6; iVar3 != 0; iVar3 = iVar3 + -1) {

        *puVar7 = *puVar6;

        puVar6 = puVar6 + 1;

        puVar7 = puVar7 + 1;

      }

      *(undefined2 *)puVar7 = *(undefined2 *)puVar6;

      DAT_005df2c0 = (undefined4 *)((int)DAT_005df2c0 + 0x1a);

    }

    if ((0xb < DAT_00632f08) && (piVar4 = DAT_00632d68, DAT_00632d68 != (int *)0x0)) {

      while ((iVar3 = piVar4[3], (*(uint *)(iVar3 + 0xd8) & 0x8000) != 0 ||

             (piVar1 = DAT_00632d68, *(int *)(iVar3 + 0x188) != *(int *)(param_1 + 6)))) {

        piVar4 = (int *)*piVar4;

        if (piVar4 == (int *)0x0) {

          return;

        }

      }

      for (; piVar1 != (int *)0x0; piVar1 = (int *)*piVar1) {

        iVar5 = piVar1[3];

        if (((*(uint *)(iVar5 + 0xd8) & 0x8000) == 0) &&

           (*(int *)(iVar5 + 0x188) == *(int *)(param_1 + 2))) goto LAB_00534fe4;

      }

      iVar5 = 0;

LAB_00534fe4:

      FUN_00457100(*(undefined1 *)(param_1 + 1),*(undefined4 *)(param_1 + 0x16),iVar3,iVar5,

                   param_1 + 10,0);

    }

  }

  return;

}

/* ===== FUN_00535010 @ 0x00535010 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_00535010(int param_1,int param_2)



{

  undefined1 uVar1;

  uint uVar2;

  undefined4 uVar3;

  int iVar4;

  int iVar5;

  uint uVar6;

  undefined1 *puVar7;

  undefined4 *puVar8;

  undefined4 *puVar9;

  undefined1 local_8c;

  undefined1 local_80 [128];

  

  uVar2 = *(uint *)((int)DAT_005e0304 + 1);

  uVar3 = *(undefined4 *)((int)DAT_005e0304 + 10);

  uVar1 = *(undefined1 *)((int)DAT_005e0304 + 9);

  iVar4 = *(int *)((int)DAT_005e0304 + 5);

  puVar7 = (undefined1 *)((int)DAT_005e0304 + 0xe);

  if (DAT_00632f08 < 0xc) goto LAB_00535351;

  puVar9 = DAT_00632d68;

  if ((param_2 != 0) &&

     (iVar5 = FUN_0052c5c0(), puVar8 = DAT_005e0304, puVar9 = DAT_00632d68, iVar5 != 0)) {

    local_8c = (undefined1)DAT_005e02e8;

    if (param_1 == 0) {

      if ((0x3ff < (int)((int)DAT_005dfad0 + (uVar2 - 0x5dfad0))) &&

         (iVar5 = FUN_0052aa70(), iVar5 != 0)) {

        iVar5 = FUN_0052c5c0();

        if (iVar5 == 0) {

          if ((DAT_005dfed8 == &DAT_005dfedc) && (DAT_005e2310 == &DAT_005e2314)) {

            if (DAT_006328e8 < _DAT_005e2718 + 1.5) goto LAB_005352a9;

            DAT_005e2314._0_1_ = 0x16;

            DAT_005e2310 = (undefined4 *)((int)&DAT_005e2314 + 1);

          }

          *(undefined1 *)DAT_005dfed8 = 0;

          DAT_005dfed8 = (undefined4 *)((int)DAT_005dfed8 + 1);

          *(undefined1 *)DAT_005e2310 = 0;

          DAT_005e2310 = (undefined4 *)((int)DAT_005e2310 + 1);

          if (1 < (int)DAT_005dfed8 + -0x5dfedc) {

            FUN_0052b8c0((undefined1 *)((int)DAT_005dfed8 + -0x5dfedc),&DAT_005dfedc);

          }

          if (1 < (int)DAT_005e2310 + -0x5e2314) {

            FUN_0052ba30((undefined1 *)((int)DAT_005e2310 + -0x5e2314),&DAT_005e2314);

          }

          DAT_005dfed8 = &DAT_005dfedc;

          DAT_005e2310 = &DAT_005e2314;

        }

        else {

          FUN_005354c0();

        }

      }

LAB_005352a9:

      *(undefined1 *)DAT_005dfad0 = local_8c;

      DAT_005dfad0 = (undefined4 *)((int)DAT_005dfad0 + 1);

      *(short *)DAT_005dfad0 = (short)uVar2;

      DAT_005dfad0 = (undefined4 *)((int)DAT_005dfad0 + 2);

      if (uVar2 != 0) {

        puVar9 = DAT_005dfad0;

        for (uVar6 = uVar2 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {

          *puVar9 = *puVar8;

          puVar8 = puVar8 + 1;

          puVar9 = puVar9 + 1;

        }

        for (uVar6 = uVar2 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {

          *(undefined1 *)puVar9 = *(undefined1 *)puVar8;

          puVar8 = (undefined4 *)((int)puVar8 + 1);

          puVar9 = (undefined4 *)((int)puVar9 + 1);

        }

      }

      DAT_005dfad0 = (undefined4 *)((int)DAT_005dfad0 + uVar2);

      puVar9 = DAT_00632d68;

    }

    else {

      if ((0x3ff < (int)((int)DAT_005df2c0 + (uVar2 - 0x5df2c0))) &&

         (iVar5 = FUN_0052aa70(), iVar5 != 0)) {

        iVar5 = FUN_0052c5c0();

        if (iVar5 == 0) {

          if ((DAT_005dfed8 == &DAT_005dfedc) && (DAT_005e2310 == &DAT_005e2314)) {

            if (DAT_006328e8 < _DAT_005e2718 + 1.5) goto LAB_00535170;

            DAT_005e2314._0_1_ = 0x16;

            DAT_005e2310 = (undefined4 *)((int)&DAT_005e2314 + 1);

          }

          *(undefined1 *)DAT_005dfed8 = 0;

          DAT_005dfed8 = (undefined4 *)((int)DAT_005dfed8 + 1);

          *(undefined1 *)DAT_005e2310 = 0;

          DAT_005e2310 = (undefined4 *)((int)DAT_005e2310 + 1);

          if (1 < (int)DAT_005dfed8 + -0x5dfedc) {

            FUN_0052b8c0((undefined1 *)((int)DAT_005dfed8 + -0x5dfedc),&DAT_005dfedc);

          }

          if (1 < (int)DAT_005e2310 + -0x5e2314) {

            FUN_0052ba30((undefined1 *)((int)DAT_005e2310 + -0x5e2314),&DAT_005e2314);

          }

          DAT_005dfed8 = &DAT_005dfedc;

          DAT_005e2310 = &DAT_005e2314;

        }

        else {

          FUN_005354c0();

        }

      }

LAB_00535170:

      *(undefined1 *)DAT_005df2c0 = local_8c;

      DAT_005df2c0 = (undefined4 *)((int)DAT_005df2c0 + 1);

      *(short *)DAT_005df2c0 = (short)uVar2;

      DAT_005df2c0 = (undefined4 *)((int)DAT_005df2c0 + 2);

      if (uVar2 != 0) {

        puVar9 = DAT_005df2c0;

        for (uVar6 = uVar2 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {

          *puVar9 = *puVar8;

          puVar8 = puVar8 + 1;

          puVar9 = puVar9 + 1;

        }

        for (uVar6 = uVar2 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {

          *(undefined1 *)puVar9 = *(undefined1 *)puVar8;

          puVar8 = (undefined4 *)((int)puVar8 + 1);

          puVar9 = (undefined4 *)((int)puVar9 + 1);

        }

      }

      DAT_005df2c0 = (undefined4 *)((int)DAT_005df2c0 + uVar2);

      puVar9 = DAT_00632d68;

    }

  }

  for (; puVar9 != (undefined4 *)0x0; puVar9 = (undefined4 *)*puVar9) {

    iVar5 = puVar9[3];

    if (((*(uint *)(iVar5 + 0xd8) & 0x8000) == 0) && (*(int *)(iVar5 + 0x188) == iVar4)) {

      FUN_0049a140(iVar5,uVar2 - 0xe,uVar1,uVar3,puVar7);

      goto LAB_00535351;

    }

  }

  FUN_00542f27(local_80,s_bad_object_id__0x_X__for_multi_r_00580198,iVar4,uVar3,uVar1,

               (double)DAT_00632e6c);

  FUN_00425eb0(local_80);

LAB_00535351:

  DAT_005e0304 = (undefined4 *)((int)DAT_005e0304 + uVar2);

  return;

}

/* ===== FUN_00535390 @ 0x00535390 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_00535390(void)



{

  float fVar1;

  int iVar2;

  

  iVar2 = FUN_0052aa70();

  if (iVar2 == 0) {

    return;

  }

  if (DAT_00633040 != 0) {

    return;

  }

  if (DAT_00633210 == 0) {

    fVar1 = 0.05;

  }

  else {

    fVar1 = 0.025;

  }

  if (DAT_006328e8 < _DAT_005e2718 + fVar1) {

    return;

  }

  iVar2 = FUN_0052aa70();

  if (iVar2 != 0) {

    iVar2 = FUN_0052c5c0();

    if (iVar2 == 0) {

      if ((DAT_005dfed8 == &DAT_005dfedc) && (DAT_005e2310 == &DAT_005e2314)) {

        if (DAT_006328e8 < _DAT_005e2718 + 1.5) goto LAB_005354a5;

        DAT_005e2314._0_1_ = 0x16;

        DAT_005e2310 = (undefined4 *)((int)&DAT_005e2314 + 1);

      }

      *(undefined1 *)DAT_005dfed8 = 0;

      DAT_005dfed8 = (undefined4 *)((int)DAT_005dfed8 + 1);

      *(undefined1 *)DAT_005e2310 = 0;

      DAT_005e2310 = (undefined4 *)((int)DAT_005e2310 + 1);

      if (1 < (int)DAT_005dfed8 + -0x5dfedc) {

        FUN_0052b8c0((undefined1 *)((int)DAT_005dfed8 + -0x5dfedc),&DAT_005dfedc);

      }

      if (1 < (int)DAT_005e2310 + -0x5e2314) {

        FUN_0052ba30((undefined1 *)((int)DAT_005e2310 + -0x5e2314),&DAT_005e2314);

      }

      DAT_005dfed8 = &DAT_005dfedc;

      DAT_005e2310 = &DAT_005e2314;

    }

    else {

      FUN_005354c0();

    }

  }

LAB_005354a5:

  _DAT_005e2718 = DAT_006328e8;

  DAT_005e2714 = DAT_005e2714 + 1;

  return;

}

/* ===== FUN_005354c0 @ 0x005354C0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_005354c0(void)



{

  ushort uVar1;

  int iVar2;

  byte *pbVar3;

  byte *pbVar4;

  uint uVar5;

  uint uVar6;

  uint uVar7;

  byte *pbVar8;

  int iVar9;

  int local_24;

  int local_20;

  int local_1c;

  uint local_18;

  int local_14;

  byte *local_10;

  byte *local_c;

  int local_8;

  uint local_4;

  

  iVar2 = FUN_0052aa70();

  if (iVar2 != 0) {

    FUN_0052b460(&local_8,&local_20);

    local_4 = FUN_0052b430();

    local_c = DAT_005e2310;

    local_10 = DAT_005dfed8;

    local_18 = 0;

    if (0 < local_8) {

      local_24 = 0;

      pbVar4 = DAT_005df2c0;

      do {

        uVar7 = local_18;

        if ((local_4 != local_18) && (*(int *)(local_24 + local_20) != 0)) {

          DAT_005dfed8 = local_10;

          local_14 = 0;

          DAT_005e2310 = local_c;

          for (pbVar3 = &DAT_005df2c4; pbVar3 < pbVar4;

              pbVar3 = pbVar3 + *(ushort *)(pbVar3 + 1) + 3) {

            if (*pbVar3 != local_18) {

              local_14 = local_14 + (uint)*(ushort *)(pbVar3 + 1);

            }

          }

          local_1c = 0;

          for (pbVar3 = &DAT_005dfad4; pbVar3 < DAT_005dfad0;

              pbVar3 = pbVar3 + *(ushort *)(pbVar3 + 1) + 3) {

            if (*pbVar3 != local_18) {

              local_1c = local_1c + (uint)*(ushort *)(pbVar3 + 1);

            }

          }

          if (((local_10 == (byte *)&DAT_005dfedc) && (local_c == (byte *)&DAT_005e2314)) &&

             (local_1c + local_14 == 0)) {

            if (DAT_006328e8 < _DAT_005e2718 + 1.5) goto LAB_00535948;

            DAT_005e2314._0_1_ = 0x16;

            DAT_005e2310 = (byte *)((int)&DAT_005e2314 + 1);

            pbVar4 = DAT_005df2c0;

          }

          if ((0 < local_14) && ((int)(local_10 + local_14 + -0x5dfedb) < 0x400)) {

            pbVar3 = &DAT_005df2c4;

            if (&DAT_005df2c4 < pbVar4) {

              do {

                uVar6 = (uint)*(ushort *)(pbVar3 + 1);

                if (*pbVar3 != local_18) {

                  pbVar4 = pbVar3 + 3;

                  pbVar8 = DAT_005dfed8;

                  for (uVar5 = (uint)(*(ushort *)(pbVar3 + 1) >> 2); uVar5 != 0; uVar5 = uVar5 - 1)

                  {

                    *(undefined4 *)pbVar8 = *(undefined4 *)pbVar4;

                    pbVar4 = pbVar4 + 4;

                    pbVar8 = pbVar8 + 4;

                  }

                  for (uVar5 = uVar6 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {

                    *pbVar8 = *pbVar4;

                    pbVar4 = pbVar4 + 1;

                    pbVar8 = pbVar8 + 1;

                  }

                  DAT_005dfed8 = DAT_005dfed8 + uVar6;

                  pbVar4 = DAT_005df2c0;

                }

                pbVar3 = pbVar3 + 3 + uVar6;

              } while (pbVar3 < pbVar4);

            }

            local_14 = 0;

          }

          iVar2 = local_14;

          if ((0 < local_1c) && ((int)(DAT_005e2310 + local_1c + -0x5e2313) < 0x400)) {

            pbVar4 = &DAT_005dfad4;

            if (&DAT_005dfad4 < DAT_005dfad0) {

              do {

                uVar6 = (uint)*(ushort *)(pbVar4 + 1);

                if (*pbVar4 != local_18) {

                  pbVar3 = pbVar4 + 3;

                  pbVar8 = DAT_005e2310;

                  for (uVar5 = (uint)(*(ushort *)(pbVar4 + 1) >> 2); uVar5 != 0; uVar5 = uVar5 - 1)

                  {

                    *(undefined4 *)pbVar8 = *(undefined4 *)pbVar3;

                    pbVar3 = pbVar3 + 4;

                    pbVar8 = pbVar8 + 4;

                  }

                  for (uVar5 = uVar6 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {

                    *pbVar8 = *pbVar3;

                    pbVar3 = pbVar3 + 1;

                    pbVar8 = pbVar8 + 1;

                  }

                  DAT_005e2310 = DAT_005e2310 + uVar6;

                }

                pbVar4 = pbVar4 + 3 + uVar6;

              } while (pbVar4 < DAT_005dfad0);

            }

            local_1c = 0;

          }

          iVar9 = local_1c;

          *DAT_005dfed8 = 0;

          DAT_005dfed8 = DAT_005dfed8 + 1;

          *DAT_005e2310 = 0;

          DAT_005e2310 = DAT_005e2310 + 1;

          if (1 < (int)(DAT_005dfed8 + -0x5dfedc)) {

            FUN_0052b5a0(*(undefined4 *)(local_24 + local_20),DAT_005dfed8 + -0x5dfedc,&DAT_005dfedc

                        );

          }

          if (1 < (int)(DAT_005e2310 + -0x5e2314)) {

            FUN_0052b630(*(undefined4 *)(local_24 + local_20),DAT_005e2310 + -0x5e2314,&DAT_005e2314

                        );

          }

          if (0 < iVar2) {

            pbVar3 = &DAT_005df2c4;

            pbVar4 = &DAT_005df6cc;

            DAT_005df6c8 = &DAT_005df6cc;

            if (&DAT_005df2c4 < DAT_005df2c0) {

              do {

                uVar1 = *(ushort *)(pbVar3 + 1);

                uVar7 = (uint)uVar1;

                if (*pbVar3 != local_18) {

                  if (0x3ff < (int)(pbVar4 + (uVar7 - 0x5df6cb))) {

                    *pbVar4 = 0;

                    pbVar4 = DAT_005df6c8 + -0x5df6cb;

                    DAT_005df6c8 = DAT_005df6c8 + 1;

                    FUN_0052b5a0(*(undefined4 *)(local_24 + local_20),pbVar4,&DAT_005df6cc);

                    pbVar4 = &DAT_005df6cc;

                    DAT_005df6c8 = &DAT_005df6cc;

                  }

                  pbVar8 = pbVar3 + 3;

                  for (uVar6 = (uint)(uVar1 >> 2); uVar6 != 0; uVar6 = uVar6 - 1) {

                    *(undefined4 *)pbVar4 = *(undefined4 *)pbVar8;

                    pbVar8 = pbVar8 + 4;

                    pbVar4 = pbVar4 + 4;

                  }

                  for (uVar6 = uVar7 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {

                    *pbVar4 = *pbVar8;

                    pbVar8 = pbVar8 + 1;

                    pbVar4 = pbVar4 + 1;

                  }

                  pbVar4 = DAT_005df6c8 + uVar7;

                  DAT_005df6c8 = pbVar4;

                }

                pbVar3 = pbVar3 + 3 + uVar7;

                uVar7 = local_18;

              } while (pbVar3 < DAT_005df2c0);

            }

            *pbVar4 = 0;

            pbVar4 = DAT_005df6c8 + -0x5df6cb;

            DAT_005df6c8 = DAT_005df6c8 + 1;

            FUN_0052b5a0(*(undefined4 *)(local_24 + local_20),pbVar4,&DAT_005df6cc);

            iVar9 = local_1c;

          }

          pbVar4 = DAT_005df2c0;

          if (0 < iVar9) {

            pbVar3 = &DAT_005dfad4;

            pbVar4 = &DAT_005df6cc;

            DAT_005df6c8 = &DAT_005df6cc;

            if (&DAT_005dfad4 < DAT_005dfad0) {

              do {

                uVar1 = *(ushort *)(pbVar3 + 1);

                uVar7 = (uint)uVar1;

                if (*pbVar3 != local_18) {

                  if (0x3ff < (int)(pbVar4 + (uVar7 - 0x5df6cb))) {

                    *pbVar4 = 0;

                    pbVar4 = DAT_005df6c8 + -0x5df6cb;

                    DAT_005df6c8 = DAT_005df6c8 + 1;

                    FUN_0052b630(*(undefined4 *)(local_24 + local_20),pbVar4,&DAT_005df6cc);

                    pbVar4 = &DAT_005df6cc;

                    DAT_005df6c8 = &DAT_005df6cc;

                  }

                  pbVar8 = pbVar3 + 3;

                  for (uVar6 = (uint)(uVar1 >> 2); uVar6 != 0; uVar6 = uVar6 - 1) {

                    *(undefined4 *)pbVar4 = *(undefined4 *)pbVar8;

                    pbVar8 = pbVar8 + 4;

                    pbVar4 = pbVar4 + 4;

                  }

                  for (uVar6 = uVar7 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {

                    *pbVar4 = *pbVar8;

                    pbVar8 = pbVar8 + 1;

                    pbVar4 = pbVar4 + 1;

                  }

                  pbVar4 = DAT_005df6c8 + uVar7;

                  DAT_005df6c8 = pbVar4;

                }

                pbVar3 = pbVar3 + 3 + uVar7;

                uVar7 = local_18;

              } while (pbVar3 < DAT_005dfad0);

            }

            *pbVar4 = 0;

            pbVar4 = DAT_005df6c8 + -0x5df6cb;

            DAT_005df6c8 = DAT_005df6c8 + 1;

            FUN_0052b630(*(undefined4 *)(local_24 + local_20),pbVar4,&DAT_005df6cc);

            pbVar4 = DAT_005df2c0;

          }

        }

LAB_00535948:

        local_18 = uVar7 + 1;

        local_24 = local_24 + 4;

      } while ((int)local_18 < local_8);

    }

    DAT_005dfed8 = (byte *)&DAT_005dfedc;

    DAT_005e2310 = (byte *)&DAT_005e2314;

    DAT_005df2c0 = &DAT_005df2c4;

    DAT_005dfad0 = &DAT_005dfad4;

  }

  return;

}

/* ===== FUN_005359a0 @ 0x005359A0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_005359a0(void)



{

  ushort uVar1;

  int iVar2;

  byte *pbVar3;

  byte *pbVar4;

  uint uVar5;

  uint uVar6;

  uint uVar7;

  byte *pbVar8;

  int iVar9;

  int local_24;

  int local_20;

  int local_1c;

  uint local_18;

  int local_14;

  byte *local_10;

  byte *local_c;

  int local_8;

  uint local_4;

  

  iVar2 = FUN_0052aa70();

  if (iVar2 != 0) {

    iVar2 = FUN_0052c5c0();

    if (iVar2 == 0) {

      if ((DAT_005dfed8 == (byte *)&DAT_005dfedc) && (DAT_005e2310 == (byte *)&DAT_005e2314)) {

        if (DAT_006328e8 < _DAT_005e2718 + 1.5) {

          return;

        }

        DAT_005e2314._0_1_ = 0x16;

        DAT_005e2310 = (byte *)((int)&DAT_005e2314 + 1);

      }

      *DAT_005dfed8 = 0;

      DAT_005dfed8 = DAT_005dfed8 + 1;

      *DAT_005e2310 = 0;

      DAT_005e2310 = DAT_005e2310 + 1;

      if (1 < (int)(DAT_005dfed8 + -0x5dfedc)) {

        FUN_0052b8c0(DAT_005dfed8 + -0x5dfedc,&DAT_005dfedc);

      }

      if (1 < (int)(DAT_005e2310 + -0x5e2314)) {

        FUN_0052ba30(DAT_005e2310 + -0x5e2314,&DAT_005e2314);

      }

      DAT_005dfed8 = (byte *)&DAT_005dfedc;

      DAT_005e2310 = (byte *)&DAT_005e2314;

    }

    else {

      iVar2 = FUN_0052aa70();

      if (iVar2 != 0) {

        FUN_0052b460(&local_8,&local_20);

        local_4 = FUN_0052b430();

        local_c = DAT_005e2310;

        local_10 = DAT_005dfed8;

        local_18 = 0;

        if (0 < local_8) {

          local_24 = 0;

          pbVar4 = DAT_005df2c0;

          do {

            uVar7 = local_18;

            if ((local_4 != local_18) && (*(int *)(local_24 + local_20) != 0)) {

              DAT_005dfed8 = local_10;

              local_14 = 0;

              DAT_005e2310 = local_c;

              for (pbVar3 = &DAT_005df2c4; pbVar3 < pbVar4;

                  pbVar3 = pbVar3 + *(ushort *)(pbVar3 + 1) + 3) {

                if (*pbVar3 != local_18) {

                  local_14 = local_14 + (uint)*(ushort *)(pbVar3 + 1);

                }

              }

              local_1c = 0;

              for (pbVar3 = &DAT_005dfad4; pbVar3 < DAT_005dfad0;

                  pbVar3 = pbVar3 + *(ushort *)(pbVar3 + 1) + 3) {

                if (*pbVar3 != local_18) {

                  local_1c = local_1c + (uint)*(ushort *)(pbVar3 + 1);

                }

              }

              if (((local_10 == (byte *)&DAT_005dfedc) && (local_c == (byte *)&DAT_005e2314)) &&

                 (local_1c + local_14 == 0)) {

                if (DAT_006328e8 < _DAT_005e2718 + 1.5) goto LAB_00535e38;

                DAT_005e2314._0_1_ = 0x16;

                DAT_005e2310 = (byte *)((int)&DAT_005e2314 + 1);

                pbVar4 = DAT_005df2c0;

              }

              if ((0 < local_14) && ((int)(local_10 + local_14 + -0x5dfedb) < 0x400)) {

                pbVar3 = &DAT_005df2c4;

                if (&DAT_005df2c4 < pbVar4) {

                  do {

                    uVar6 = (uint)*(ushort *)(pbVar3 + 1);

                    if (*pbVar3 != local_18) {

                      pbVar4 = pbVar3 + 3;

                      pbVar8 = DAT_005dfed8;

                      for (uVar5 = (uint)(*(ushort *)(pbVar3 + 1) >> 2); uVar5 != 0;

                          uVar5 = uVar5 - 1) {

                        *(undefined4 *)pbVar8 = *(undefined4 *)pbVar4;

                        pbVar4 = pbVar4 + 4;

                        pbVar8 = pbVar8 + 4;

                      }

                      for (uVar5 = uVar6 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {

                        *pbVar8 = *pbVar4;

                        pbVar4 = pbVar4 + 1;

                        pbVar8 = pbVar8 + 1;

                      }

                      DAT_005dfed8 = DAT_005dfed8 + uVar6;

                      pbVar4 = DAT_005df2c0;

                    }

                    pbVar3 = pbVar3 + 3 + uVar6;

                  } while (pbVar3 < pbVar4);

                }

                local_14 = 0;

              }

              iVar2 = local_14;

              if ((0 < local_1c) && ((int)(DAT_005e2310 + local_1c + -0x5e2313) < 0x400)) {

                pbVar4 = &DAT_005dfad4;

                if (&DAT_005dfad4 < DAT_005dfad0) {

                  do {

                    uVar6 = (uint)*(ushort *)(pbVar4 + 1);

                    if (*pbVar4 != local_18) {

                      pbVar3 = pbVar4 + 3;

                      pbVar8 = DAT_005e2310;

                      for (uVar5 = (uint)(*(ushort *)(pbVar4 + 1) >> 2); uVar5 != 0;

                          uVar5 = uVar5 - 1) {

                        *(undefined4 *)pbVar8 = *(undefined4 *)pbVar3;

                        pbVar3 = pbVar3 + 4;

                        pbVar8 = pbVar8 + 4;

                      }

                      for (uVar5 = uVar6 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {

                        *pbVar8 = *pbVar3;

                        pbVar3 = pbVar3 + 1;

                        pbVar8 = pbVar8 + 1;

                      }

                      DAT_005e2310 = DAT_005e2310 + uVar6;

                    }

                    pbVar4 = pbVar4 + 3 + uVar6;

                  } while (pbVar4 < DAT_005dfad0);

                }

                local_1c = 0;

              }

              iVar9 = local_1c;

              *DAT_005dfed8 = 0;

              DAT_005dfed8 = DAT_005dfed8 + 1;

              *DAT_005e2310 = 0;

              DAT_005e2310 = DAT_005e2310 + 1;

              if (1 < (int)(DAT_005dfed8 + -0x5dfedc)) {

                FUN_0052b5a0(*(undefined4 *)(local_24 + local_20),DAT_005dfed8 + -0x5dfedc,

                             &DAT_005dfedc);

              }

              if (1 < (int)(DAT_005e2310 + -0x5e2314)) {

                FUN_0052b630(*(undefined4 *)(local_24 + local_20),DAT_005e2310 + -0x5e2314,

                             &DAT_005e2314);

              }

              if (0 < iVar2) {

                pbVar3 = &DAT_005df2c4;

                pbVar4 = &DAT_005df6cc;

                DAT_005df6c8 = &DAT_005df6cc;

                if (&DAT_005df2c4 < DAT_005df2c0) {

                  do {

                    uVar1 = *(ushort *)(pbVar3 + 1);

                    uVar7 = (uint)uVar1;

                    if (*pbVar3 != local_18) {

                      if (0x3ff < (int)(pbVar4 + (uVar7 - 0x5df6cb))) {

                        *pbVar4 = 0;

                        pbVar4 = DAT_005df6c8 + -0x5df6cb;

                        DAT_005df6c8 = DAT_005df6c8 + 1;

                        FUN_0052b5a0(*(undefined4 *)(local_24 + local_20),pbVar4,&DAT_005df6cc);

                        pbVar4 = &DAT_005df6cc;

                        DAT_005df6c8 = &DAT_005df6cc;

                      }

                      pbVar8 = pbVar3 + 3;

                      for (uVar6 = (uint)(uVar1 >> 2); uVar6 != 0; uVar6 = uVar6 - 1) {

                        *(undefined4 *)pbVar4 = *(undefined4 *)pbVar8;

                        pbVar8 = pbVar8 + 4;

                        pbVar4 = pbVar4 + 4;

                      }

                      for (uVar6 = uVar7 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {

                        *pbVar4 = *pbVar8;

                        pbVar8 = pbVar8 + 1;

                        pbVar4 = pbVar4 + 1;

                      }

                      pbVar4 = DAT_005df6c8 + uVar7;

                      DAT_005df6c8 = pbVar4;

                    }

                    pbVar3 = pbVar3 + 3 + uVar7;

                    uVar7 = local_18;

                  } while (pbVar3 < DAT_005df2c0);

                }

                *pbVar4 = 0;

                pbVar4 = DAT_005df6c8 + -0x5df6cb;

                DAT_005df6c8 = DAT_005df6c8 + 1;

                FUN_0052b5a0(*(undefined4 *)(local_24 + local_20),pbVar4,&DAT_005df6cc);

                iVar9 = local_1c;

              }

              pbVar4 = DAT_005df2c0;

              if (0 < iVar9) {

                pbVar3 = &DAT_005dfad4;

                pbVar4 = &DAT_005df6cc;

                DAT_005df6c8 = &DAT_005df6cc;

                if (&DAT_005dfad4 < DAT_005dfad0) {

                  pbVar4 = &DAT_005df6cc;

                  do {

                    uVar1 = *(ushort *)(pbVar3 + 1);

                    uVar7 = (uint)uVar1;

                    if (*pbVar3 != local_18) {

                      if (0x3ff < (int)(pbVar4 + (uVar7 - 0x5df6cb))) {

                        *pbVar4 = 0;

                        pbVar4 = DAT_005df6c8 + -0x5df6cb;

                        DAT_005df6c8 = DAT_005df6c8 + 1;

                        FUN_0052b630(*(undefined4 *)(local_24 + local_20),pbVar4,&DAT_005df6cc);

                        pbVar4 = &DAT_005df6cc;

                        DAT_005df6c8 = &DAT_005df6cc;

                      }

                      pbVar8 = pbVar3 + 3;

                      for (uVar6 = (uint)(uVar1 >> 2); uVar6 != 0; uVar6 = uVar6 - 1) {

                        *(undefined4 *)pbVar4 = *(undefined4 *)pbVar8;

                        pbVar8 = pbVar8 + 4;

                        pbVar4 = pbVar4 + 4;

                      }

                      for (uVar6 = uVar7 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {

                        *pbVar4 = *pbVar8;

                        pbVar8 = pbVar8 + 1;

                        pbVar4 = pbVar4 + 1;

                      }

                      pbVar4 = DAT_005df6c8 + uVar7;

                      DAT_005df6c8 = pbVar4;

                    }

                    pbVar3 = pbVar3 + 3 + uVar7;

                    uVar7 = local_18;

                  } while (pbVar3 < DAT_005dfad0);

                }

                *pbVar4 = 0;

                pbVar4 = DAT_005df6c8 + -0x5df6cb;

                DAT_005df6c8 = DAT_005df6c8 + 1;

                FUN_0052b630(*(undefined4 *)(local_24 + local_20),pbVar4,&DAT_005df6cc);

                pbVar4 = DAT_005df2c0;

              }

            }

LAB_00535e38:

            local_18 = uVar7 + 1;

            local_24 = local_24 + 4;

          } while ((int)local_18 < local_8);

        }

        DAT_005dfed8 = (byte *)&DAT_005dfedc;

        DAT_005df2c0 = &DAT_005df2c4;

        DAT_005dfad0 = &DAT_005dfad4;

        DAT_005e2310 = (byte *)&DAT_005e2314;

        return;

      }

    }

  }

  return;

}

/* ===== FUN_00535f40 @ 0x00535F40 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_00535f40(void)



{

  char cVar1;

  int iVar2;

  char *pcVar3;

  

  if (DAT_00632f08 < 3) {

    if (DAT_0063316c == 0) {

      DAT_00632f10 = 0;

    }

    iVar2 = FUN_005250e0(DAT_00632f10);

    DAT_00632f14 = 2 - (uint)(iVar2 != 0);

    if (DAT_00633168 == 0) {

      DAT_00632f0c = 0;

    }

    if (DAT_0063315c == 0) {

      pcVar3 = &DAT_0063304c;

      do {

        cVar1 = *pcVar3;

        pcVar3[-0x104] = cVar1;

        pcVar3 = pcVar3 + 1;

      } while (cVar1 != '\0');

    }

    if (DAT_00633174 == 0) {

      DAT_00632f18 = 0;

    }

  }

  DAT_00632f1c = FUN_00521350(DAT_00632f18);

  DAT_00632f20 = 0;

  DAT_00632f38 = 1;

  DAT_00632f24 = 1;

  DAT_00632f28 = 5;

  DAT_00632f2c = 0;

  DAT_00632f30 = 0;

  if (DAT_00633170 == 0) {

    DAT_00632f34 = 10;

  }

  DAT_00632f3c = 0;

  DAT_00632f40 = 0;

  DAT_00632fd0 = 0;

  DAT_00632fdc = 0;

  _DAT_00632fe0 = 0;

  DAT_00632fec = 0;

  DAT_00632ff0 = 0;

  DAT_00632fc0 = 1;

  DAT_00632fcc = 0x14;

  DAT_00633010 = 0x44960000;

  return;

}

/* ===== FUN_00536050 @ 0x00536050 ===== */
/* PS2 candidate: atox__FPc (conf 0.506) */



int FUN_00536050(char *param_1)



{

  char cVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int aiStack_50 [20];

  

  if ((*param_1 == '0') && (iVar2 = FUN_005452a0((int)param_1[1]), iVar2 == 0x78)) {

    param_1 = param_1 + 2;

  }

  iVar2 = 0;

  while (((cVar1 = *param_1, '/' < cVar1 && (cVar1 < ':')) ||

         ((iVar3 = FUN_005452a0((int)cVar1), 0x60 < iVar3 &&

          (iVar3 = FUN_005452a0((int)*param_1), iVar3 < 0x67))))) {

    cVar1 = *param_1;

    if ((cVar1 < '0') || ('9' < cVar1)) {

      iVar3 = FUN_005452a0((int)cVar1);

      aiStack_50[iVar2] = iVar3 + -0x57;

      iVar2 = iVar2 + 1;

      param_1 = param_1 + 1;

    }

    else {

      aiStack_50[iVar2] = cVar1 + -0x30;

      iVar2 = iVar2 + 1;

      param_1 = param_1 + 1;

    }

  }

  iVar3 = 0;

  while (iVar2 != 0) {

    iVar2 = iVar2 + -1;

    FUN_00543e70();

    iVar4 = __ftol();

    iVar3 = iVar3 + iVar4 * aiStack_50[iVar2];

  }

  return iVar3;

}

/* ===== FUN_00536120 @ 0x00536120 ===== */
void FUN_00536120(void)



{

  undefined1 *puVar1;

  undefined4 *puVar2;

  

  puVar2 = &DAT_006327e0;

  puVar1 = &DAT_00630ee0;

  do {

    *puVar1 = 0;

    *puVar2 = 0;

    puVar1 = puVar1 + 0x100;

    puVar2 = puVar2 + 1;

  } while ((int)puVar1 < 0x6327e0);

  return;

}

/* ===== FUN_00536150 @ 0x00536150 ===== */
void FUN_00536150(void)



{

  int iVar1;

  undefined4 *puVar2;

  

  puVar2 = &DAT_006327e0;

  for (iVar1 = 0x19; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar2 = 0;

    puVar2 = puVar2 + 1;

  }

  return;

}

/* ===== chat_init @ 0x00536170 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void chat_init(void)



{

  char *pcVar1;

  undefined4 uVar2;

  int iVar3;

  undefined4 *puVar4;

  

  puVar4 = (undefined4 *)&DAT_00630ee0;

  for (iVar3 = 0x672; iVar3 != 0; iVar3 = iVar3 + -1) {

    *puVar4 = 0;

    puVar4 = puVar4 + 1;

  }

  _DAT_006328c4 = 0x1fffff;

  _DAT_006328c8 = 0xf0f01f;

  _DAT_006328cc = 0xd0d0d0;

  _DAT_006328d0 = 0x1f1fff;

  _DAT_006328d4 = 0xff1fff;

  _DAT_006328d8 = 0x1fffff;

  _DAT_006328c0 = 0;

  pcVar1 = (char *)TextGetPtrQ(s_ChatColorSystem_00580248);

  if (*pcVar1 != '?') {

    uVar2 = TextGetPtrQ(s_ChatColorSystem_00580248);

    _DAT_006328c4 = FUN_00536050(uVar2);

  }

  pcVar1 = (char *)TextGetPtrQ(s_ChatColorPlayerAll_00580234);

  if (*pcVar1 != '?') {

    uVar2 = TextGetPtrQ(s_ChatColorPlayerAll_00580234);

    _DAT_006328c8 = FUN_00536050(uVar2);

  }

  pcVar1 = (char *)TextGetPtrQ(s_ChatColorPlayerTeam_00580220);

  if (*pcVar1 != '?') {

    uVar2 = TextGetPtrQ(s_ChatColorPlayerTeam_00580220);

    _DAT_006328cc = FUN_00536050(uVar2);

  }

  pcVar1 = (char *)TextGetPtrQ(s_ChatColorSmartie_0058020c);

  if (*pcVar1 != '?') {

    uVar2 = TextGetPtrQ(s_ChatColorSmartie_0058020c);

    _DAT_006328d0 = FUN_00536050(uVar2);

  }

  pcVar1 = (char *)TextGetPtrQ(s_ChatColorDisciple_005801f8);

  if (*pcVar1 != '?') {

    uVar2 = TextGetPtrQ(s_ChatColorDisciple_005801f8);

    _DAT_006328d4 = FUN_00536050(uVar2);

  }

  pcVar1 = (char *)TextGetPtrQ(s_ChatColorMission_005801e4);

  if (*pcVar1 != '?') {

    uVar2 = TextGetPtrQ(s_ChatColorMission_005801e4);

    _DAT_006328d8 = FUN_00536050(uVar2);

  }

  return;

}

/* ===== FUN_005362d0 @ 0x005362D0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* PS2 candidate: chat_insert (conf 0.58) */



void FUN_005362d0(char *param_1,undefined4 param_2)



{

  int iVar1;

  char *pcVar2;

  

  iVar1 = FUN_00426540();

  if (iVar1 != 0) {

    iVar1 = FUN_00543a11();

    if (iVar1 != 0) {

      FUN_00543b5d(iVar1,s__1_2f___s_00580258,(double)DAT_006328e8,param_1);

      FUN_0054384c(iVar1);

    }

  }

  iVar1 = 0;

  pcVar2 = &DAT_00630ee0;

  do {

    if (*pcVar2 == '\0') break;

    pcVar2 = pcVar2 + 0x100;

    iVar1 = iVar1 + 1;

  } while ((int)pcVar2 < 0x6327e0);

  if (iVar1 == 0x19) {

    FUN_00543270(&DAT_00630ee0,&DAT_00630fe0,0x1800);

    FUN_00543270(&DAT_006327e0,&DAT_006327e4,0x60);

    FUN_00543270(&DAT_00632844,&DAT_00632848,0x60);

    DAT_006326e0 = 0;

    DAT_00632840 = 0;

    _DAT_006328a4 = 0;

    iVar1 = 0x18;

  }

  if ((param_1 == (char *)0x0) || (*param_1 == '\0')) {

    *(undefined2 *)(&DAT_00630ee0 + iVar1 * 0x100) = DAT_0055c728;

  }

  else {

    _strncpy(&DAT_00630ee0 + iVar1 * 0x100,param_1,0xff);

  }

  (&DAT_006327e0)[iVar1] = DAT_00632e6c;

  *(undefined1 *)(iVar1 * 0x100 + 0x630fdf) = 0;

  (&DAT_00632844)[iVar1] = param_2;

  return;

}

/* ===== FUN_005363f0 @ 0x005363F0 ===== */
void FUN_005363f0(char *param_1,undefined4 param_2)



{

  char *pcVar1;

  float fVar2;

  char cVar3;

  char *pcVar4;

  char *pcVar5;

  char *pcVar6;

  char *pcVar7;

  float10 fVar8;

  int local_134;

  float local_130;

  char local_12c [299];

  undefined1 local_1;

  

  _strncpy(local_12c,param_1,300);

  local_1 = 0;

  pcVar6 = local_12c;

  fVar8 = (float10)FUN_004272e0();

  fVar2 = (float)fVar8;

  fVar8 = (float10)FUN_0051bd30(fVar2,local_12c);

  if ((float10)0.6 < fVar8) {

    do {

      if (*pcVar6 == '\0') break;

      pcVar7 = (char *)0x0;

      pcVar5 = (char *)0x0;

      local_130 = 0.0;

      local_134 = 0;

      pcVar4 = pcVar6;

      do {

        fVar8 = (float10)FUN_0051bc90(fVar2,pcVar6,local_134);

        if ((pcVar7 == (char *)0x0) && ((float10)0.6 < fVar8)) {

          pcVar7 = pcVar4;

        }

        if (*pcVar4 == ' ') {

          if ((((float10)0.6 < fVar8) && (pcVar5 != (char *)0x0)) &&

             (local_130 < 0.6 != (local_130 == 0.6))) {

            if (*pcVar4 != '\0') {

              if (pcVar5 == (char *)0x0) goto LAB_00536519;

              *pcVar5 = '\0';

              FUN_005362d0(pcVar6,param_2);

              pcVar6 = pcVar5 + 1;

              goto LAB_0053653b;

            }

            break;

          }

          local_130 = (float)fVar8;

          pcVar5 = pcVar4;

        }

        pcVar1 = pcVar4 + 1;

        pcVar4 = pcVar4 + 1;

        local_134 = local_134 + 1;

      } while (*pcVar1 != '\0');

      if (pcVar5 == (char *)0x0) {

LAB_00536519:

        if (pcVar7 == (char *)0x0) break;

        cVar3 = *pcVar7;

        *pcVar7 = '\0';

        FUN_005362d0(pcVar6,param_2);

        pcVar6 = pcVar7 + 1;

        *pcVar7 = cVar3;

      }

      else {

        *pcVar5 = '\0';

        FUN_005362d0(pcVar6,param_2);

        pcVar6 = pcVar5 + 1;

      }

LAB_0053653b:

      fVar8 = (float10)FUN_0051bd30(fVar2,pcVar6);

    } while ((float10)0.6 < fVar8);

    if (pcVar6 == (char *)0x0) {

      return;

    }

  }

  if (*pcVar6 != '\0') {

    FUN_005362d0(pcVar6,param_2);

  }

  return;

}

/* ===== FUN_00536580 @ 0x00536580 ===== */
/* PS2 candidate: chat_insert_lf (conf 0.375) */



void FUN_00536580(char *param_1,undefined4 param_2)



{

  char *_Source;

  char *pcVar1;

  char *_Str;

  char local_900 [256];

  char local_800 [2047];

  undefined1 local_1;

  

  _strncpy(local_800,param_1,0x800);

  local_1 = 0;

  pcVar1 = _strchr(local_800,10);

  _Source = local_800;

  while (pcVar1 != (char *)0x0) {

    _Str = pcVar1 + 1;

    _strncpy(local_900,_Source,(int)_Str - (int)_Source);

    local_900[((int)_Str - (int)_Source) - 1] = '\0';

    FUN_005362d0(local_900,param_2);

    pcVar1 = _strchr(_Str,10);

    _Source = _Str;

  }

  FUN_005362d0(_Source,param_2);

  return;

}

/* ===== chat_insert_name @ 0x00536620 ===== */
/* PS2 candidate: chat_insert_name (conf 0.8) */



void chat_insert_name(char *param_1,char *param_2,undefined4 param_3,int param_4)



{

  ushort uVar1;

  int iVar2;

  uint uVar3;

  ushort *puVar4;

  ushort *puVar5;

  ushort local_100 [127];

  undefined1 local_1;

  

  local_100[0] = local_100[0] & 0xff00;

  if (param_4 != 0) {

    local_100[0] = DAT_0057fd7c;

  }

  _strncat((char *)local_100,param_1,0xfe);

  if (param_4 != 0) {

    iVar2 = -1;

    puVar5 = local_100;

    do {

      puVar4 = puVar5;

      if (iVar2 == 0) break;

      iVar2 = iVar2 + -1;

      puVar4 = (ushort *)((int)puVar5 + 1);

      uVar1 = *puVar5;

      puVar5 = puVar4;

    } while ((char)uVar1 != '\0');

    *(undefined2 *)((int)puVar4 + -1) = DAT_0057fd78;

  }

  uVar3 = 0xffffffff;

  local_1 = 0;

  puVar5 = local_100;

  do {

    if (uVar3 == 0) break;

    uVar3 = uVar3 - 1;

    uVar1 = *puVar5;

    puVar5 = (ushort *)((int)puVar5 + 1);

  } while ((char)uVar1 != '\0');

  _strncpy((char *)((int)local_100 + (~uVar3 - 1)),(char *)&DAT_00555928,0xff - (~uVar3 - 1));

  uVar3 = 0xffffffff;

  local_1 = 0;

  puVar5 = local_100;

  do {

    if (uVar3 == 0) break;

    uVar3 = uVar3 - 1;

    uVar1 = *puVar5;

    puVar5 = (ushort *)((int)puVar5 + 1);

  } while ((char)uVar1 != '\0');

  _strncpy((char *)((int)local_100 + (~uVar3 - 1)),param_2,0xff - (~uVar3 - 1));

  local_1 = 0;

  FUN_005363f0(local_100,param_3);

  return;

}

/* ===== FUN_00536700 @ 0x00536700 ===== */
/* PS2 candidate: mecc_get_thrust__FP6OBJECTfPfT2 (conf 0.303) */



void FUN_00536700(int param_1)



{

  float fVar1;

  char cVar2;

  bool bVar3;

  undefined4 uVar4;

  uint uVar5;

  int iVar6;

  int iVar7;

  char *pcVar8;

  char *pcVar9;

  undefined *puVar10;

  int iVar11;

  float10 fVar12;

  float fVar13;

  float local_118;

  undefined4 local_114;

  float local_110;

  float local_10c;

  int local_108;

  undefined4 local_104;

  char local_100 [255];

  undefined1 local_1;

  

  fVar12 = (float10)FUN_004272e0();

  fVar1 = (float)fVar12;

  fVar12 = (float10)FUN_0051bc00(fVar1);

  pcVar8 = DAT_00632fb8;

  fVar13 = (float)fVar12;

  bVar3 = false;

  local_10c = fVar13;

  if (DAT_00632fac != 0) {

    local_108 = 0;

    fVar12 = (float10)FUN_0051bc90(fVar13,DAT_00632fb8,DAT_00632fb0);

    if ((float10)0.76 < fVar12) {

      local_108 = 1;

      do {

        pcVar8 = pcVar8 + 1;

        fVar12 = (float10)FUN_0051bc90(fVar13,pcVar8,DAT_00632fb8 + (DAT_00632fb0 - (int)pcVar8));

      } while ((float10)0.76 < fVar12);

    }

    _strncpy(local_100,pcVar8,0x100);

    local_1 = 0;

    fVar12 = (float10)FUN_0051bd30(fVar13,local_100);

    if ((float10)0.76 < fVar12) {

      bVar3 = true;

      do {

        uVar5 = 0xffffffff;

        pcVar9 = local_100;

        do {

          if (uVar5 == 0) break;

          uVar5 = uVar5 - 1;

          cVar2 = *pcVar9;

          pcVar9 = pcVar9 + 1;

        } while (cVar2 != '\0');

        local_100[~uVar5 - 2] = '\0';

        fVar12 = (float10)FUN_0051bd30(fVar13,local_100);

      } while ((float10)0.76 < fVar12);

    }

    FUN_0051b970(0x1fffff,0,fVar1,0x3dcccccd,0x3f733333,local_100);

    uVar5 = __ftol();

    if ((uVar5 & 1) != 0) {

      puVar10 = &DAT_00556004;

      local_110 = fVar1 * 0.1 + 0.95;

      if (DAT_00632fbc == 0) {

        puVar10 = &DAT_00556494;

      }

      fVar12 = (float10)FUN_0051bc90(fVar13,local_100,DAT_00632fb8 + (DAT_00632fb0 - (int)pcVar8));

      local_104 = (float)(fVar12 + (float10)0.1);

      FUN_0051b970(0x1fffff,0,fVar1,local_104,local_110,puVar10);

    }

    if ((bVar3) && (uVar5 = __ftol(), (uVar5 & 1) != 0)) {

      FUN_0051b970(0xf0f01f,0,fVar1,0x3f68f5c3,0x3f733333,&DAT_00556010);

    }

    if ((local_108 != 0) && (uVar5 = __ftol(), (uVar5 & 1) == 0)) {

      FUN_0051b970(0xf0f01f,0,fVar1,0x3d8f5c29,0x3f733333,&DAT_00556014);

    }

  }

  DAT_0063301c = 0;

  if (DAT_00633020 == 0) {

    iVar11 = 0;

    iVar7 = -1;

    iVar6 = 0x18;

    pcVar8 = &DAT_006326e0;

    do {

      if ((*pcVar8 != '\0') && (DAT_00632e6c - (float)(&DAT_006327e0)[iVar6] < 6.0)) {

        DAT_0063301c = (uint)(param_1 == 0);

        iVar6 = iVar6 + -4;

        if (iVar6 < 0) {

          iVar6 = 0;

        }

        iVar7 = iVar6 + 4;

        if (0x18 < iVar7) {

          iVar7 = 0x18;

        }

        iVar11 = iVar6;

        if (iVar6 <= iVar7) {

          pcVar8 = &DAT_00630ee0 + iVar6 * 0x100;

          goto LAB_005369b7;

        }

        break;

      }

      pcVar8 = pcVar8 + -0x100;

      iVar6 = iVar6 + -1;

    } while (0x630edf < (int)pcVar8);

  }

  else {

    DAT_0063301c = (uint)(param_1 == 0);

    iVar7 = 0x18;

    iVar11 = 0;

  }

  goto LAB_005369e7;

  while( true ) {

    if (6.0 <= DAT_00632e6c - (float)(&DAT_006327e0)[iVar6]) {

      iVar11 = iVar11 + 1;

    }

    iVar6 = iVar6 + 1;

    pcVar8 = pcVar8 + 0x100;

    if (iVar7 < iVar6) break;

LAB_005369b7:

    if (*pcVar8 == '\0') {

      iVar7 = iVar6 + -1;

      break;

    }

  }

LAB_005369e7:

  FUN_00500830();

  FUN_005007f0(&local_114,&local_118);

  if (param_1 != 0) {

    local_114 = 0x3dcccccd;

    local_118 = 0.85;

  }

  if ((DAT_00633020 != 0) && (DAT_00633028 == 0)) {

    uVar4 = FUN_00507b00(s_ChatBoxHint_00580264);

    FUN_0051ba00(0x1fffff,0,fVar1 * 0.75,0x3e99999a,local_118 - 0.03,uVar4);

  }

  if (iVar11 <= iVar7) {

    pcVar8 = &DAT_00630ee0 + iVar11 * 0x100;

    do {

      cVar2 = *pcVar8;

      if (cVar2 != '\0') {

        if (cVar2 == '\v') {

          fVar13 = fVar1 * 1.5;

          pcVar9 = pcVar8 + 1;

LAB_00536aeb:

          FUN_0051b970(*(undefined4 *)(&DAT_006328c0 + (&DAT_00632844)[iVar11] * 4),0,fVar13,

                       local_114,local_118,pcVar9);

        }

        else {

          fVar13 = fVar1;

          pcVar9 = pcVar8;

          if (cVar2 != '\f') goto LAB_00536aeb;

          FUN_0051ba00(*(undefined4 *)(&DAT_006328c0 + (&DAT_00632844)[iVar11] * 4),0,fVar1 * 1.5,

                       0x3f000000,local_118,pcVar8 + 1);

        }

        local_118 = local_118 + local_10c;

      }

      iVar11 = iVar11 + 1;

      pcVar8 = pcVar8 + 0x100;

    } while (iVar11 <= iVar7);

  }

  return;

}

/* ===== FUN_00536b20 @ 0x00536B20 ===== */
/* PS2 candidate: multi_draw_health_bar_horizontal__FP6OBJECTff (conf 0.399) */



void FUN_00536b20(float param_1,float param_2,float param_3)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  int iVar7;

  undefined4 uVar8;

  float10 fVar9;

  float10 fVar10;

  

  fVar1 = *(float *)((int)param_1 + 0x278);

  fVar2 = *(float *)((int)param_1 + 0x1c0);

  iVar7 = FUN_004a6220(param_1);

  if (iVar7 == 0) {

    iVar7 = FUN_004a6300(param_1);

    fVar1 = 1.0 - fVar1 / fVar2;

    if (iVar7 == 0) goto LAB_00536b76;

  }

  fVar9 = (float10)FUN_00417f20(param_1);

  fVar10 = (float10)FUN_00418170(param_1);

  fVar1 = (float)((float10)(float)fVar9 / fVar10);

LAB_00536b76:

  param_1 = fVar1;

  uVar8 = 0xff00;

  if (0.001 <= ABS(param_1 - 1.0)) {

    uVar8 = 0xffff00;

  }

  iVar7 = FUN_004a6160(DAT_00632a88);

  if (iVar7 == 0) {

    fVar1 = 0.48;

  }

  else {

    fVar1 = 0.49;

  }

  fVar6 = (float)DAT_00632e84;

  fVar3 = (20.0 / fVar6) * 0.5;

  fVar4 = 0.5 - fVar3;

  fVar5 = param_2 + fVar4;

  fVar2 = 2.0 / (float)DAT_00632e88 + fVar1 + param_3;

  FUN_0042ebf0(0xff0000,fVar5,fVar3 + param_2 + 0.5,fVar1 + param_3,fVar2);

  FUN_0042ebf0(uVar8,fVar5,(20.0 / fVar6) * param_1 + fVar4 + param_2,fVar1 + param_3,fVar2);

  return;

}

/* ===== FUN_00536c60 @ 0x00536C60 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_00536c60(void)



{

  if (((DAT_005e2738 == 0) || (1.0 < DAT_00632e6c - _DAT_005e273c)) ||

     ((char)((uint)*(undefined4 *)(DAT_005e2738 + 0xd8) >> 8) < '\0')) {

    DAT_005e2738 = 0;

  }

  return;

}

/* ===== FUN_00536ca0 @ 0x00536CA0 ===== */
undefined4 FUN_00536ca0(void)



{

  return DAT_005e2738;

}

/* ===== FUN_00536cb0 @ 0x00536CB0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* PS2 candidate: multi_display_player_cursor_info__Fv (conf 0.38) */



void FUN_00536cb0(void)



{

  float fVar1;

  int iVar2;

  int iVar3;

  uint uVar4;

  float10 fVar5;

  undefined1 local_24 [4];

  undefined1 local_20 [4];

  undefined1 local_1c [4];

  undefined1 local_18 [12];

  undefined1 local_c [12];

  

  iVar2 = FUN_00455b70(&LAB_00536e50,0,0,local_18);

  if (iVar2 != 0) {

    FUN_0040d6f0(local_1c,local_20,local_24,local_c);

    iVar3 = FUN_004eed30(local_c,local_18);

    if (iVar3 != 0) {

      _DAT_005e273c = DAT_00632e6c;

      DAT_005e2738 = iVar2;

    }

  }

  if (((DAT_005e2738 != 0) && (DAT_00632a88 != 0)) &&

     (fVar1 = *(float *)(DAT_00632ed8 + 0x1068),

     fVar5 = (float10)FUN_0050a610(DAT_00632a88 + 0xa0,DAT_005e2738 + 0xa0),

     fVar5 < (float10)fVar1 * (float10)fVar1)) {

    uVar4 = FUN_0049a1d0(DAT_005e2738);

    if ((uVar4 & 2) != 0) {

      FUN_00536f60(DAT_005e2738);

    }

    uVar4 = FUN_0049a1d0(DAT_005e2738);

    if (((((((uVar4 & 1) != 0) || (iVar2 = *(int *)(DAT_005e2738 + 4), iVar2 == 0x4b7)) ||

          ((iVar2 == 0x4b8 || ((iVar2 == 0x4b9 || (iVar2 == 0x41a)))))) || (iVar2 == 0x41b)) ||

        ((((iVar2 == 0x3df && (*(int *)(DAT_005e2738 + 0x210) == 0)) || (iVar2 == 0x4be)) ||

         ((iVar2 == 0x493 || (iVar2 == 0x2b1)))))) &&

       (((iVar2 = *(int *)(DAT_005e2738 + 4), iVar2 != 0x342 &&

         ((iVar2 != 0x35a && (iVar2 != 0x2f8)))) &&

        ((iVar2 != 0x359 &&

         ((((iVar2 != 0x447 && (iVar2 != 0x486)) && (iVar2 != 0x2f7)) && (iVar2 != 0x353)))))))) {

      FUN_00536b20(DAT_005e2738,0,-(15.0 / (float)DAT_00632e88));

    }

  }

  return;

}

/* ===== FUN_00536f60 @ 0x00536F60 ===== */
/* PS2 candidate: projectile_logic (conf 0.391) */



void FUN_00536f60(float param_1)



{

  float fVar1;

  int iVar2;

  undefined *puVar3;

  undefined4 uVar4;

  undefined4 uVar5;

  uint uVar6;

  undefined4 local_c;

  undefined4 local_8;

  float local_4;

  

  uVar5 = 1;

  iVar2 = FUN_0052aa70();

  if ((iVar2 == 0) || ((*(byte *)((int)param_1 + 0x1c8) & 1) == 0)) {

    uVar4 = 0x1fffff;

    if (*(int *)((int)param_1 + 0x174) == 0) {

      iVar2 = *(int *)((int)param_1 + 0x18c);

      if ((iVar2 == 1) || (iVar2 == 2)) {

        uVar4 = 1;

      }

      else {

        if (iVar2 != 3) goto LAB_00536fe0;

        uVar4 = 2;

      }

      uVar4 = FUN_0052ac00(uVar4);

    }

LAB_00536fe0:

    iVar2 = FUN_004a6160(param_1);

    if (iVar2 == 0) {

      if (*(int *)((int)param_1 + 0x1e0) == 0x12) {

        puVar3 = (undefined *)(*(int *)((int)param_1 + 0x100) + 0x80);

      }

      else {

        iVar2 = FUN_004a6200(param_1);

        if ((((iVar2 == 0) && (iVar2 = FUN_004a6220(param_1), iVar2 == 0)) &&

            (iVar2 = FUN_004a6290(param_1), iVar2 == 0)) &&

           (iVar2 = FUN_004a6300(param_1), iVar2 == 0)) {

          puVar3 = (undefined *)FUN_0049a180(*(undefined4 *)((int)param_1 + 0x1e0));

        }

        else {

          puVar3 = (undefined *)bldg_get_bldg_name(param_1);

        }

      }

    }

    else {

      puVar3 = (&PTR_DAT_0057a920)[*(int *)((int)param_1 + 0x174)];

    }

    iVar2 = FUN_004a61e0(param_1);

    if ((iVar2 == 0) || (*(int *)((int)param_1 + 0x174) != 0)) goto LAB_00537079;

  }

  else {

    uVar6 = *(uint *)((int)param_1 + 0x188) & 0xff;

    puVar3 = (undefined *)FUN_0052adf0(uVar6);

    uVar5 = FUN_0052ab50(uVar6);

    uVar4 = FUN_0052ac00(uVar5);

  }

  uVar5 = 0;

LAB_00537079:

  local_c = *(undefined4 *)((int)param_1 + 0xa0);

  local_8 = *(undefined4 *)((int)param_1 + 0xa4);

  local_4 = *(float *)((int)param_1 + 0x1ec) * *(float *)((int)param_1 + 0xc4) +

            *(float *)((int)param_1 + 0xa8);

  fVar1 = (float)DAT_00632e88;

  iVar2 = FUN_004a61e0(param_1);

  param_1 = 15.0 / fVar1;

  if (iVar2 != 0) {

    local_4 = local_4 + 3.0;

    param_1 = 20.0 / (float)DAT_00632e88;

  }

  if (DAT_00632ba8 != 0) {

    param_1 = 12.0 / (float)DAT_00632e88;

  }

  FUN_0051bed0(uVar4,&local_c,param_1,puVar3,uVar5);

  return;

}

/* ===== FUN_00537120 @ 0x00537120 ===== */
void FUN_00537120(int param_1,int param_2)



{

  undefined4 uVar1;

  undefined4 uVar2;

  undefined4 local_c;

  undefined4 local_8;

  float local_4;

  

  uVar1 = FUN_0052ac00((*(int *)(param_1 + 4) == 0x343) + '\x01');

  local_c = *(undefined4 *)(param_1 + 0xa0);

  local_8 = *(undefined4 *)(param_1 + 0xa4);

  local_4 = *(float *)(param_1 + 0x1ec) * *(float *)(param_1 + 0xc4) + *(float *)(param_1 + 0xa8);

  if (param_2 != 0) {

    uVar2 = FUN_00507b00(s_BaseHintHomeBase_00580284,0);

    FUN_0051bed0(uVar1,&local_c,15.0 / (float)DAT_00632e88,uVar2);

    return;

  }

  uVar2 = FUN_00507b00(s_BaseHintEnemyBase_00580270,0);

  FUN_0051bed0(uVar1,&local_c,15.0 / (float)DAT_00632e88,uVar2);

  return;

}

/* ===== FUN_005371e0 @ 0x005371E0 ===== */
void FUN_005371e0(void)



{

  undefined4 *puVar1;

  undefined4 uVar2;

  int iVar3;

  undefined4 uVar4;

  undefined4 uVar5;

  undefined1 local_d6;

  undefined1 local_d5;

  undefined1 local_d4;

  undefined4 local_d3;

  int local_cf;

  undefined1 local_cb;

  undefined1 local_c8 [200];

  

  if (DAT_00632f44 == 0) {

    if ((6 < DAT_00632f08) && (DAT_00632f08 < 0xc)) {

      DAT_00633040 = DAT_00633040 | 4;

      return;

    }

    DAT_00632f08 = 6;

    uVar2 = FUN_0052b430(6);

    FUN_0052ac60(uVar2);

    iVar3 = FUN_0052aa70();

    if (iVar3 != 0) {

      local_d4 = 0x11;

      local_d3 = FUN_0052aad0();

      local_cf = DAT_00632f08;

      local_cb = 0;

      iVar3 = FUN_0052c5c0();

      if (iVar3 == 0) {

        FUN_0052b8c0(10,&local_d4);

      }

      else {

        FUN_0052b780(0);

        if ((DAT_00632f08 == 0xe) && (DAT_00633238 == 0)) {

          uVar2 = FUN_0052adf0(0);

          uVar4 = FUN_0052ab50(0);

          uVar4 = FUN_0052ab90(uVar4);

          uVar5 = FUN_00507b00(s_MPChEnterGame_0057fd98);

          FUN_00542f27(local_c8,uVar5,uVar2,uVar4);

          FUN_005363f0(local_c8,1);

        }

      }

    }

  }

  else {

    DAT_00632f08 = 2;

    uVar2 = FUN_0052b430(2);

    FUN_0052ac60(uVar2);

    iVar3 = FUN_0052aa70();

    if (iVar3 != 0) {

      local_d4 = 0x11;

      local_d3 = FUN_0052aad0();

      local_cf = DAT_00632f08;

      local_cb = 0;

      iVar3 = FUN_0052c5c0();

      if (iVar3 == 0) {

        FUN_0052b8c0(10,&local_d4);

      }

      else {

        FUN_0052b780(0);

        if ((DAT_00632f08 == 0xe) && (DAT_00633238 == 0)) {

          uVar2 = FUN_0052adf0(0);

          uVar4 = FUN_0052ab50(0);

          uVar4 = FUN_0052ab90(uVar4);

          uVar5 = FUN_00507b00(s_MPChEnterGame_0057fd98);

          FUN_00542f27(local_c8,uVar5,uVar2,uVar4);

          FUN_005363f0(local_c8,1);

        }

      }

    }

    local_d6 = 9;

    local_d5 = 0;

    FUN_0052b780(0,2,&local_d6);

  }

  FUN_004ff470();

  FUN_004270f0();

  DAT_00632bb4 = 0;

  DAT_00632bb0 = 0;

  DAT_00632bb8 = 0;

  DAT_00632bac = 0;

  DAT_00632ba8 = 0;

  for (puVar1 = DAT_00632d68; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {

    FUN_0049a030(puVar1[3]);

  }

  DAT_00632e40 = 1;

  FUN_005233f0();

  return;

}

/* ===== FUN_00537400 @ 0x00537400 ===== */
void FUN_00537400(int param_1)



{

  float fVar1;

  char cVar2;

  undefined4 *puVar3;

  int iVar4;

  int iVar5;

  char *pcVar6;

  undefined4 uVar7;

  uint uVar8;

  uint uVar9;

  char *pcVar10;

  char *pcVar11;

  float10 fVar12;

  float10 fVar13;

  char local_200 [512];

  

  iVar4 = FUN_0052aa70();

  if (((((iVar4 != 0) && (iVar4 = FUN_0052aa80(param_1), iVar4 != 0)) && (DAT_00632ff0 != 0)) &&

      ((iVar4 = FUN_00521310(DAT_00632f18), iVar4 != 0 && (DAT_00632ff0 != 0)))) &&

     (puVar3 = DAT_00632d9c, DAT_00632ff8 == 0)) {

    for (; puVar3 != (undefined4 *)0x0; puVar3 = (undefined4 *)*puVar3) {

      iVar4 = puVar3[3];

      if ((*(int *)(iVar4 + 0x18c) == *(int *)(param_1 + 0x18c)) &&

         ((iVar5 = FUN_004a6220(iVar4), iVar5 != 0 || (iVar5 = FUN_004a6300(iVar4), iVar5 != 0)))) {

        iVar5 = FUN_004a6300(iVar4);

        if (iVar5 == 0) {

          iVar5 = FUN_0040acf0(iVar4);

          fVar12 = (float10)FUN_0040ad30(iVar4);

          fVar1 = *(float *)(DAT_00632ed8 + 0xb80);

        }

        else {

          iVar5 = FUN_004b6f60();

          fVar12 = (float10)FUN_004b6d60(iVar4);

          fVar1 = *(float *)(DAT_00632ed8 + 0xb80);

        }

        if ((-1 < iVar5) &&

           (fVar13 = (float10)FUN_00417f20(iVar4),

           (float10)(float)((float10)fVar1 * fVar12 * (float10)0.01) < fVar13)) {

          return;

        }

      }

    }

    pcVar6 = (char *)FUN_00507b00(s_WinCondMetDestroy_00580298);

    iVar4 = FUN_0052aa70();

    if (iVar4 == 0) {

      FUN_005362d0(pcVar6,1);

    }

    else {

      uVar7 = FUN_0052aad0();

      iVar4 = FUN_0052ab20(uVar7);

      if ((-1 < iVar4) && (iVar4 <= DAT_00632f34 + -1)) {

        pcVar11 = local_200;

        for (iVar5 = 0x80; iVar5 != 0; iVar5 = iVar5 + -1) {

          pcVar11[0] = '\0';

          pcVar11[1] = '\0';

          pcVar11[2] = '\0';

          pcVar11[3] = '\0';

          pcVar11 = pcVar11 + 4;

        }

        uVar8 = 0xffffffff;

        local_200[1] = (byte)iVar4 | 0x80;

        local_200[3] = 0;

        local_200[0] = '<';

        local_200[2] = 0x81;

        do {

          pcVar11 = pcVar6;

          if (uVar8 == 0) break;

          uVar8 = uVar8 - 1;

          pcVar11 = pcVar6 + 1;

          cVar2 = *pcVar6;

          pcVar6 = pcVar11;

        } while (cVar2 != '\0');

        uVar8 = ~uVar8;

        iVar4 = -1;

        pcVar6 = local_200;

        do {

          pcVar10 = pcVar6;

          if (iVar4 == 0) break;

          iVar4 = iVar4 + -1;

          pcVar10 = pcVar6 + 1;

          cVar2 = *pcVar6;

          pcVar6 = pcVar10;

        } while (cVar2 != '\0');

        pcVar6 = pcVar11 + -uVar8;

        pcVar11 = pcVar10 + -1;

        for (uVar9 = uVar8 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {

          *(undefined4 *)pcVar11 = *(undefined4 *)pcVar6;

          pcVar6 = pcVar6 + 4;

          pcVar11 = pcVar11 + 4;

        }

        for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {

          *pcVar11 = *pcVar6;

          pcVar6 = pcVar6 + 1;

          pcVar11 = pcVar11 + 1;

        }

        FUN_0052e6e0(local_200,0);

      }

    }

    DAT_00632ff8 = 1;

  }

  return;

}

/* ===== FUN_005375e0 @ 0x005375E0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* PS2 candidate: mecc_is_bush_logic__FP6OBJECT (conf 0.583) */



void FUN_005375e0(void)



{

  char cVar1;

  undefined4 *puVar2;

  int iVar3;

  char *pcVar4;

  undefined4 uVar5;

  int iVar6;

  int *piVar7;

  int iVar8;

  float fVar9;

  char *pcVar10;

  uint uVar11;

  uint uVar12;

  float fVar13;

  char *pcVar14;

  float10 fVar15;

  float10 fVar16;

  float local_a9c;

  float local_a98;

  float local_a94;

  undefined1 local_a90;

  float local_a8f;

  float local_a8b;

  undefined1 local_a87;

  int local_a84;

  char local_a80 [512];

  char local_880 [128];

  char local_800 [512];

  char local_600 [512];

  char local_400 [512];

  char local_200 [512];

  

  if (0.0 < DAT_00632f30) {

    fVar15 = (float10)FUN_00518b70(0,0);

    fVar16 = (float10)DAT_00632f30;

    DAT_00632f30 = (float)(fVar16 - fVar15);

    if (fVar16 - fVar15 < (float10)0.0) {

      DAT_00632f30 = 0.0;

      iVar3 = FUN_0052c5c0();

      if (iVar3 != 0) {

        pcVar4 = (char *)FUN_00507b00(s_CommFlagCapsOn_0058030c);

        iVar3 = FUN_0052aa70();

        if (iVar3 == 0) {

          FUN_005362d0(pcVar4,1);

        }

        else {

          uVar5 = FUN_0052aad0();

          iVar3 = FUN_0052ab20(uVar5);

          if ((-1 < iVar3) && (iVar3 <= DAT_00632f34 + -1)) {

            pcVar10 = local_a80;

            for (iVar8 = 0x80; iVar8 != 0; iVar8 = iVar8 + -1) {

              pcVar10[0] = '\0';

              pcVar10[1] = '\0';

              pcVar10[2] = '\0';

              pcVar10[3] = '\0';

              pcVar10 = pcVar10 + 4;

            }

            uVar11 = 0xffffffff;

            local_a80[1] = (byte)iVar3 | 0x80;

            local_a80[0] = '<';

            local_a80[2] = 0x81;

            local_a80[3] = 0;

            do {

              pcVar10 = pcVar4;

              if (uVar11 == 0) break;

              uVar11 = uVar11 - 1;

              pcVar10 = pcVar4 + 1;

              cVar1 = *pcVar4;

              pcVar4 = pcVar10;

            } while (cVar1 != '\0');

            uVar11 = ~uVar11;

            iVar3 = -1;

            pcVar4 = local_a80;

            do {

              pcVar14 = pcVar4;

              if (iVar3 == 0) break;

              iVar3 = iVar3 + -1;

              pcVar14 = pcVar4 + 1;

              cVar1 = *pcVar4;

              pcVar4 = pcVar14;

            } while (cVar1 != '\0');

            pcVar4 = pcVar10 + -uVar11;

            pcVar10 = pcVar14 + -1;

            for (uVar12 = uVar11 >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {

              *(undefined4 *)pcVar10 = *(undefined4 *)pcVar4;

              pcVar4 = pcVar4 + 4;

              pcVar10 = pcVar10 + 4;

            }

            for (uVar11 = uVar11 & 3; uVar11 != 0; uVar11 = uVar11 - 1) {

              *pcVar10 = *pcVar4;

              pcVar4 = pcVar4 + 1;

              pcVar10 = pcVar10 + 1;

            }

            FUN_0052e6e0(local_a80,0);

          }

        }

      }

    }

  }

  if (DAT_00632fc0 != 0) {

    fVar15 = (float10)FUN_00518b70(0,0);

    fVar16 = (float10)DAT_00633010;

    DAT_00633010 = (float)(fVar16 - fVar15);

    if (fVar16 - fVar15 < (float10)0.0) {

      DAT_00633010 = 0.0;

    }

  }

  iVar3 = FUN_0052c5c0();

  if (iVar3 == 0) {

    return;

  }

  fVar16 = (float10)FUN_00518b70(0,0);

  fVar16 = (float10)_DAT_0057f4bc - fVar16;

  _DAT_0057f4bc = (float)fVar16;

  if (fVar16 < (float10)0.0 != (fVar16 == (float10)0.0)) {

    iVar3 = FUN_0052aa70();

    if (iVar3 != 0) {

      local_a90 = 0x30;

      local_a8f = DAT_00632f30;

      local_a8b = DAT_00633010;

      local_a87 = 0;

      FUN_0052b780(0,10,&local_a90);

    }

    _DAT_0057f4bc = 15.0;

  }

  if (DAT_00633014 != 0) {

    if (_DAT_00633018 <= 0.0) {

      return;

    }

    fVar16 = (float10)FUN_00518b70(0,0);

    fVar16 = (float10)_DAT_00633018 - fVar16;

    _DAT_00633018 = (float)fVar16;

    if (fVar16 < (float10)0.0 == (fVar16 == (float10)0.0)) {

      return;

    }

    if (DAT_00632f44 == 0) {

      if ((6 < (int)DAT_00632f08) && ((int)DAT_00632f08 < 0xc)) {

        DAT_00633040 = DAT_00633040 | 4;

        return;

      }

      FUN_0052f0a0(6);

    }

    else {

      DAT_00632f08 = 2.8026e-45;

      uVar5 = FUN_0052b430(2);

      FUN_0052ac60(uVar5);

      iVar3 = FUN_0052aa70();

      if (iVar3 != 0) {

        local_a90 = 0x11;

        local_a8f = (float)FUN_0052aad0();

        local_a8b = DAT_00632f08;

        local_a87 = 0;

        iVar3 = FUN_0052c5c0();

        if (iVar3 == 0) {

          FUN_0052b8c0(10,&local_a90);

        }

        else {

          FUN_0052b780(0,10,&local_a90);

          if ((DAT_00632f08 == 1.96182e-44) && (DAT_00633238 == 0)) {

            FUN_0052f040(0);

          }

        }

      }

      local_a9c = (float)CONCAT22(local_a9c._2_2_,9);

      FUN_0052b780(0,2,&local_a9c);

    }

    FUN_004ff470();

    FUN_004270f0();

    DAT_00632bb4 = 0;

    DAT_00632bb0 = 0;

    DAT_00632bb8 = 0;

    DAT_00632bac = 0;

    DAT_00632ba8 = 0;

    for (puVar2 = DAT_00632d68; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {

      FUN_0049a030(puVar2[3]);

    }

    DAT_00632e40 = 1;

    FUN_005233f0();

    return;

  }

  local_a84 = DAT_00632f34;

  local_a94 = 0.0;

  do {

    iVar3 = local_a84;

    fVar13 = local_a94;

    if (((&DAT_00632fc0)[(int)local_a94 * 4] != 0) && ((&DAT_00632fc8)[(int)local_a94 * 4] == 0)) {

      switch(local_a94) {

      case 0.0:

        if (DAT_00633010 < 0.0 != (DAT_00633010 == 0.0)) {

          pcVar4 = (char *)FUN_00507b00(s_WinCondMetTimer_005802fc);

          iVar3 = FUN_0052aa70();

          if (iVar3 == 0) {

            FUN_005362d0(pcVar4,1);

          }

          else {

            uVar5 = FUN_0052aad0();

            iVar3 = FUN_0052ab20(uVar5);

            if ((-1 < iVar3) && (iVar3 <= DAT_00632f34 + -1)) {

              pcVar10 = local_a80;

              for (iVar8 = 0x80; iVar8 != 0; iVar8 = iVar8 + -1) {

                pcVar10[0] = '\0';

                pcVar10[1] = '\0';

                pcVar10[2] = '\0';

                pcVar10[3] = '\0';

                pcVar10 = pcVar10 + 4;

              }

              uVar11 = 0xffffffff;

              local_a80[1] = (byte)iVar3 | 0x80;

              local_a80[0] = '<';

              local_a80[2] = 0x81;

              local_a80[3] = 0;

              do {

                pcVar10 = pcVar4;

                if (uVar11 == 0) break;

                uVar11 = uVar11 - 1;

                pcVar10 = pcVar4 + 1;

                cVar1 = *pcVar4;

                pcVar4 = pcVar10;

              } while (cVar1 != '\0');

              uVar11 = ~uVar11;

              pcVar10 = pcVar10 + -uVar11;

              iVar3 = -1;

              pcVar4 = local_a80;

              do {

                pcVar14 = pcVar4;

                if (iVar3 == 0) break;

                iVar3 = iVar3 + -1;

                pcVar14 = pcVar4 + 1;

                cVar1 = *pcVar4;

                pcVar4 = pcVar14;

              } while (cVar1 != '\0');

              pcVar4 = local_a80;

              goto LAB_00537de2;

            }

          }

          goto LAB_00537dfb;

        }

        break;

      case 1.4013e-45:

        if ((&DAT_00632fcc)[(int)local_a94 * 4] != 0) {

          iVar8 = 0;

          local_a9c = -1.0;

          if (0 < local_a84) {

            do {

              iVar6 = FUN_0052ab00(iVar8);

              if ((iVar6 != 0) &&

                 (fVar16 = (float10)FUN_0052afc0(iVar8), (float10)local_a9c < fVar16)) {

                fVar16 = (float10)FUN_0052afc0(iVar8);

                local_a9c = (float)fVar16;

              }

              iVar8 = iVar8 + 1;

            } while (iVar8 < iVar3);

          }

          if ((float)(int)(&DAT_00632fcc)[(int)fVar13 * 4] < local_a9c !=

              ((float)(int)(&DAT_00632fcc)[(int)fVar13 * 4] == local_a9c)) {

            pcVar4 = (char *)FUN_00507b00(s_WinCondMetPlayerScore_005802e4);

            iVar3 = FUN_0052aa70();

            if (iVar3 == 0) {

              FUN_005362d0(pcVar4,1);

            }

            else {

              uVar5 = FUN_0052aad0();

              iVar3 = FUN_0052ab20(uVar5);

              if ((-1 < iVar3) && (iVar3 <= DAT_00632f34 + -1)) {

                pcVar10 = local_400;

                for (iVar8 = 0x80; iVar8 != 0; iVar8 = iVar8 + -1) {

                  pcVar10[0] = '\0';

                  pcVar10[1] = '\0';

                  pcVar10[2] = '\0';

                  pcVar10[3] = '\0';

                  pcVar10 = pcVar10 + 4;

                }

                uVar11 = 0xffffffff;

                local_400[1] = (byte)iVar3 | 0x80;

                local_400[0] = '<';

                local_400[2] = 0x81;

                local_400[3] = 0;

                do {

                  pcVar10 = pcVar4;

                  if (uVar11 == 0) break;

                  uVar11 = uVar11 - 1;

                  pcVar10 = pcVar4 + 1;

                  cVar1 = *pcVar4;

                  pcVar4 = pcVar10;

                } while (cVar1 != '\0');

                uVar11 = ~uVar11;

                pcVar10 = pcVar10 + -uVar11;

                iVar3 = -1;

                pcVar4 = local_400;

                do {

                  pcVar14 = pcVar4;

                  if (iVar3 == 0) break;

                  iVar3 = iVar3 + -1;

                  pcVar14 = pcVar4 + 1;

                  cVar1 = *pcVar4;

                  pcVar4 = pcVar14;

                } while (cVar1 != '\0');

                pcVar4 = local_400;

                goto LAB_00537de2;

              }

            }

            goto LAB_00537dfb;

          }

        }

        break;

      case 2.8026e-45:

        if ((&DAT_00632fcc)[(int)local_a94 * 4] != 0) {

          iVar3 = 0;

          local_a9c = -1.0;

          if (0 < local_a84) {

            do {

              iVar8 = FUN_0052ab00(iVar3);

              if (iVar8 != 0) {

                uVar5 = FUN_0052ab50(iVar3);

                fVar16 = (float10)FUN_0052af80(uVar5);

                if ((float10)local_a9c < fVar16) {

                  fVar16 = (float10)FUN_0052af80(uVar5);

                  local_a9c = (float)fVar16;

                }

              }

              iVar3 = iVar3 + 1;

            } while (iVar3 < local_a84);

          }

          if ((float)(int)(&DAT_00632fcc)[(int)fVar13 * 4] < local_a9c !=

              ((float)(int)(&DAT_00632fcc)[(int)fVar13 * 4] == local_a9c)) {

            pcVar4 = (char *)FUN_00507b00(s_WinCondMetTeamScore_005802d0);

            iVar3 = FUN_0052aa70();

            if (iVar3 == 0) {

              FUN_005362d0(pcVar4,1);

            }

            else {

              uVar5 = FUN_0052aad0();

              iVar3 = FUN_0052ab20(uVar5);

              if ((-1 < iVar3) && (iVar3 <= DAT_00632f34 + -1)) {

                pcVar10 = local_800;

                for (iVar8 = 0x80; iVar8 != 0; iVar8 = iVar8 + -1) {

                  pcVar10[0] = '\0';

                  pcVar10[1] = '\0';

                  pcVar10[2] = '\0';

                  pcVar10[3] = '\0';

                  pcVar10 = pcVar10 + 4;

                }

                uVar11 = 0xffffffff;

                local_800[1] = (byte)iVar3 | 0x80;

                local_800[0] = '<';

                local_800[2] = 0x81;

                local_800[3] = 0;

                do {

                  pcVar10 = pcVar4;

                  if (uVar11 == 0) break;

                  uVar11 = uVar11 - 1;

                  pcVar10 = pcVar4 + 1;

                  cVar1 = *pcVar4;

                  pcVar4 = pcVar10;

                } while (cVar1 != '\0');

                uVar11 = ~uVar11;

                pcVar10 = pcVar10 + -uVar11;

                iVar3 = -1;

                pcVar4 = local_800;

                do {

                  pcVar14 = pcVar4;

                  if (iVar3 == 0) break;

                  iVar3 = iVar3 + -1;

                  pcVar14 = pcVar4 + 1;

                  cVar1 = *pcVar4;

                  pcVar4 = pcVar14;

                } while (cVar1 != '\0');

                pcVar4 = local_800;

                goto LAB_00537de2;

              }

            }

            goto LAB_00537dfb;

          }

        }

        break;

      case 4.2039e-45:

        iVar3 = FUN_00521330(DAT_00632f18);

        if (((iVar3 != 0) && (iVar3 = FUN_00521310(DAT_00632f18), iVar3 == 0)) &&

           (piVar7 = DAT_00632d9c, DAT_00632d9c != (int *)0x0)) {

LAB_00537c57:

          iVar3 = piVar7[3];

          if (((*(int *)(iVar3 + 4) != 0x396) && (*(int *)(iVar3 + 4) != 0x484)) ||

             (*(int *)(iVar3 + 0x100) == 0)) goto LAB_00537c91;

          fVar16 = (float10)FUN_00417f20(iVar3);

          local_a98 = (float)fVar16;

          fVar16 = (float10)FUN_00418170(iVar3);

          if (fVar16 != (float10)local_a98) goto LAB_00537c91;

          pcVar4 = (char *)FUN_00507b00(s_WinCondMetBase_005802c0);

          iVar3 = FUN_0052aa70();

          if (iVar3 == 0) {

            FUN_005362d0(pcVar4,1);

            goto LAB_00537dfb;

          }

          uVar5 = FUN_0052aad0();

          iVar3 = FUN_0052ab20(uVar5);

          if ((iVar3 < 0) || (DAT_00632f34 + -1 < iVar3)) goto LAB_00537dfb;

          pcVar10 = local_600;

          for (iVar8 = 0x80; iVar8 != 0; iVar8 = iVar8 + -1) {

            pcVar10[0] = '\0';

            pcVar10[1] = '\0';

            pcVar10[2] = '\0';

            pcVar10[3] = '\0';

            pcVar10 = pcVar10 + 4;

          }

          uVar11 = 0xffffffff;

          local_600[1] = (byte)iVar3 | 0x80;

          local_600[0] = '<';

          local_600[2] = 0x81;

          local_600[3] = 0;

          do {

            pcVar10 = pcVar4;

            if (uVar11 == 0) break;

            uVar11 = uVar11 - 1;

            pcVar10 = pcVar4 + 1;

            cVar1 = *pcVar4;

            pcVar4 = pcVar10;

          } while (cVar1 != '\0');

          uVar11 = ~uVar11;

          pcVar10 = pcVar10 + -uVar11;

          iVar3 = -1;

          pcVar4 = local_600;

          do {

            pcVar14 = pcVar4;

            if (iVar3 == 0) break;

            iVar3 = iVar3 + -1;

            pcVar14 = pcVar4 + 1;

            cVar1 = *pcVar4;

            pcVar4 = pcVar14;

          } while (cVar1 != '\0');

          pcVar4 = local_600;

          goto LAB_00537de2;

        }

        break;

      case 5.60519e-45:

        pcVar4 = (char *)FUN_00507b00(s_WinCondMetEndNow_005802ac);

        iVar3 = FUN_0052aa70();

        if (iVar3 == 0) {

          FUN_005362d0(pcVar4,1);

        }

        else {

          uVar5 = FUN_0052aad0();

          iVar3 = FUN_0052ab20(uVar5);

          if ((-1 < iVar3) && (iVar3 <= DAT_00632f34 + -1)) {

            pcVar10 = local_200;

            for (iVar8 = 0x80; iVar8 != 0; iVar8 = iVar8 + -1) {

              pcVar10[0] = '\0';

              pcVar10[1] = '\0';

              pcVar10[2] = '\0';

              pcVar10[3] = '\0';

              pcVar10 = pcVar10 + 4;

            }

            uVar11 = 0xffffffff;

            local_200[1] = (byte)iVar3 | 0x80;

            local_200[0] = '<';

            local_200[2] = 0x81;

            local_200[3] = 0;

            do {

              pcVar10 = pcVar4;

              if (uVar11 == 0) break;

              uVar11 = uVar11 - 1;

              pcVar10 = pcVar4 + 1;

              cVar1 = *pcVar4;

              pcVar4 = pcVar10;

            } while (cVar1 != '\0');

            uVar11 = ~uVar11;

            pcVar10 = pcVar10 + -uVar11;

            iVar3 = -1;

            pcVar4 = local_200;

            do {

              pcVar14 = pcVar4;

              if (iVar3 == 0) break;

              iVar3 = iVar3 + -1;

              pcVar14 = pcVar4 + 1;

              cVar1 = *pcVar4;

              pcVar4 = pcVar14;

            } while (cVar1 != '\0');

            pcVar4 = local_200;

LAB_00537de2:

            pcVar14 = pcVar14 + -1;

            for (uVar12 = uVar11 >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {

              *(undefined4 *)pcVar14 = *(undefined4 *)pcVar10;

              pcVar10 = pcVar10 + 4;

              pcVar14 = pcVar14 + 4;

            }

            for (uVar11 = uVar11 & 3; uVar11 != 0; uVar11 = uVar11 - 1) {

              *pcVar14 = *pcVar10;

              pcVar10 = pcVar10 + 1;

              pcVar14 = pcVar14 + 1;

            }

            FUN_0052e6e0(pcVar4,0);

          }

        }

LAB_00537dfb:

        (&DAT_00632fc8)[(int)fVar13 * 4] = 1;

      }

    }

switchD_0053793e_default:

    local_a94 = (float)((int)local_a94 + 1);

  } while ((int)local_a94 < 5);

  iVar3 = 0;

  piVar7 = &DAT_00632fc8;

  do {

    if (piVar7[-2] != 0) {

      if (*piVar7 == 0) {

        if (piVar7[-1] != 0) {

          iVar3 = 0;

          break;

        }

      }

      else {

        iVar3 = iVar3 + 1;

      }

    }

    piVar7 = piVar7 + 4;

  } while ((int)piVar7 < 0x633018);

  iVar8 = FUN_00426540();

  if (((iVar8 != 0) && (iVar8 = FUN_00521350(DAT_00632f18), iVar8 == 0)) &&

     (iVar8 = FUN_0051f2d0(), iVar8 < 2)) {

    iVar3 = iVar3 + 1;

  }

  if (iVar3 == 0) {

    return;

  }

  fVar13 = -NAN;

  iVar3 = 0;

  DAT_00633014 = 1;

  _DAT_00633018 = 6.0;

  local_a94 = -9999.0;

  if (0 < DAT_00632f34) {

    do {

      iVar8 = FUN_0052ab00(iVar3);

      if (iVar8 != 0) {

        fVar9 = (float)FUN_0052ab50(iVar3);

        fVar16 = (float10)FUN_0052af80(fVar9);

        if ((float10)local_a94 < fVar16) {

          fVar16 = (float10)FUN_0052af80(fVar9);

          local_a94 = (float)fVar16;

          fVar13 = fVar9;

        }

      }

      iVar3 = iVar3 + 1;

    } while (iVar3 < DAT_00632f34);

    if (-1 < (int)fVar13) {

      iVar3 = 0;

      local_a9c = local_a94;

      if (0 < DAT_00632f34) {

        do {

          iVar8 = FUN_0052ab00(iVar3);

          if (((iVar8 != 0) && (fVar9 = (float)FUN_0052ab50(iVar3), fVar9 != fVar13)) &&

             (fVar16 = (float10)FUN_0052af80(fVar9), fVar16 == (float10)local_a94)) {

            fVar13 = -NAN;

            local_a9c = -1.0;

            break;

          }

          iVar3 = iVar3 + 1;

        } while (iVar3 < DAT_00632f34);

      }

      goto LAB_00537f57;

    }

  }

  fVar13 = 0.0;

  local_a9c = 0.0;

LAB_00537f57:

  iVar3 = FUN_0052aa70();

  if (iVar3 != 0) {

    local_a8b = local_a9c;

    local_a90 = 0x38;

    local_a87 = 0;

    local_a8f = fVar13;

    FUN_0052b780(0,10,&local_a90);

  }

  if (0 < (int)fVar13) {

    pcVar10 = (char *)FUN_0052ab90(fVar13);

    pcVar4 = local_880;

    do {

      cVar1 = *pcVar10;

      pcVar10 = pcVar10 + 1;

      *pcVar4 = cVar1;

      pcVar4 = pcVar4 + 1;

    } while (cVar1 != '\0');

    uVar5 = __ftol();

    uVar5 = FUN_00507b00(s_WinCondTeamWinner_0057ff2c,local_880,uVar5);

    FUN_00542f27(&DAT_00632c10,uVar5);

    _DAT_00632d10 = 0x40c00000;

  }

  DAT_00633000 = 0;

  return;

LAB_00537c91:

  piVar7 = (int *)*piVar7;

  if (piVar7 == (int *)0x0) goto switchD_0053793e_default;

  goto LAB_00537c57;

}

/* ===== FUN_00538010 @ 0x00538010 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_00538010(void)



{

  undefined4 *puVar1;

  int iVar2;

  undefined1 local_c;

  undefined4 local_b;

  float local_7;

  undefined1 local_3;

  

  puVar1 = &DAT_00632fc8;

  do {

    *puVar1 = 0;

    puVar1 = puVar1 + 4;

  } while ((int)puVar1 < 0x633018);

  FUN_0052f170(0);

  _DAT_0057f4bc = 0x41700000;

  if (DAT_00632fc0 != 0) {

    DAT_00633010 = (float)DAT_00632fcc * 60.0;

    iVar2 = FUN_0052aa70();

    if (iVar2 != 0) {

      local_c = 0x30;

      local_b = DAT_00632f30;

      local_7 = DAT_00633010;

      local_3 = 0;

      FUN_0052b780(0,10,&local_c);

    }

  }

  return;

}

/* ===== FUN_005380b0 @ 0x005380B0 ===== */
void FUN_005380b0(void)



{

  WSADATA local_190;

  

  WSAStartup(0x101,&local_190);

  return;

}

/* ===== FUN_005380e0 @ 0x005380E0 ===== */
undefined4 FUN_005380e0(undefined4 param_1)



{

  char cVar1;

  int iVar2;

  char *pcVar3;

  undefined4 uVar4;

  undefined1 *puVar5;

  char local_200 [512];

  

  FUN_00538800();

  iVar2 = FUN_005393e0(DAT_005e2c78,param_1);

  if (iVar2 == 0) {

    return 0;

  }

  cVar1 = *(char *)(iVar2 + 4);

  if (cVar1 == '\0') {

    pcVar3 = s_Bin_Override_00580324;

  }

  else {

    if (cVar1 != '\x01') {

      if (cVar1 == '\x02') {

        if (DAT_005e2a60 != '\0') {

          puVar5 = &DAT_005e2a60;

          goto LAB_0053813b;

        }

      }

      else if (DAT_005e2b60 != '\0') {

        puVar5 = &DAT_005e2b60;

LAB_0053813b:

        FUN_00542f27(&DAT_005e2740,s__s_Bin_00580338,puVar5);

        pcVar3 = &DAT_005e2740;

        goto LAB_00538152;

      }

      local_200[0] = '\0';

      goto LAB_00538194;

    }

    pcVar3 = &DAT_00580334;

  }

LAB_00538152:

  if (*pcVar3 == '\0') {

    pcVar3 = (char *)(iVar2 + 5);

    iVar2 = (int)local_200 - (int)pcVar3;

    do {

      cVar1 = *pcVar3;

      pcVar3[iVar2] = cVar1;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

  }

  else {

    FUN_00542f27(local_200,s__s__s_0058031c,pcVar3,iVar2 + 5);

  }

LAB_00538194:

  uVar4 = FUN_005178a0(local_200);

  return uVar4;

}

/* ===== FUN_00538540 @ 0x00538540 ===== */
bool FUN_00538540(undefined4 param_1)



{

  int iVar1;

  

  iVar1 = FUN_005393e0(DAT_005e2c74,param_1);

  return iVar1 != 0;

}

/* ===== FUN_005387a0 @ 0x005387A0 ===== */
void FUN_005387a0(void)



{

  if (DAT_005e2c88 != 0) {

    FUN_00539cb0();

  }

  DAT_005e2c88 = 0;

  return;

}

/* ===== FUN_005387c0 @ 0x005387C0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_005387c0(void)



{

  if ((DAT_005e2c88 != 0) && (_DAT_005e2c64 = _DAT_005e2c64 - _DAT_006328e4, _DAT_005e2c64 <= 0.0))

  {

    FUN_00539cb0();

    DAT_005e2c88 = 0;

  }

  return;

}

/* ===== FUN_00538800 @ 0x00538800 ===== */
/* PS2 candidate: mecc_disable_repair_gun (conf 0.559) */



void FUN_00538800(void)



{

  char cVar1;

  int iVar2;

  HANDLE pvVar3;

  int iVar4;

  int iVar5;

  BOOL BVar6;

  char *pcVar7;

  HANDLE hFindFile;

  uint uVar8;

  CHAR *pCVar9;

  char *pcVar10;

  undefined1 *puVar11;

  int local_6a8;

  _WIN32_FIND_DATAA local_6a0;

  undefined1 local_560 [32];

  CHAR local_540 [512];

  _WIN32_FIND_DATAA local_340;

  undefined1 local_200 [512];

  

  if (DAT_005e2c6c == 0) {

    DAT_005e2c6c = 1;

    InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_005e2948);

    DAT_005e2c70 = FUN_005391c0(0xdf,4,0);

    DAT_005e2c74 = FUN_005391c0(0x1327,0xc,0);

    DAT_005e2c78 = FUN_005391c0(0x32b,1,0);

    DAT_005e2c7c = FUN_005391c0(0xdf,4,0);

    DAT_005e2c80 = FUN_005394c0(1);

    DAT_005e2a60 = '\0';

    DAT_005e2b60 = '\0';

    FUN_00519d90();

    FUN_0051a1c0(s_DestDir_0057cb14,&DAT_005e2a60,0x100);

    FUN_0051a1c0(s_SrcDir_0057cb0c,&DAT_005e2b60,0x100);

    FUN_0051a1c0(s_Language_0058044c,local_560,0x20);

    FUN_00519ed0();

    if (DAT_005e2c8c == 0) {

      DAT_005e2c8c = FUN_00544223(local_560);

    }

    DAT_005e2c8c = DAT_005e2c8c & 0xff;

    switch(DAT_005e2c8c) {

    case 7:

      DAT_005e2840 = s_German_00580434;

      local_6a8 = 0;

      break;

    default:

      DAT_005e2840 = s_English_0057e354;

      local_6a8 = 0;

      break;

    case 10:

      DAT_005e2840 = s_Spanish_0058042c;

      local_6a8 = 0;

      break;

    case 0xc:

      DAT_005e2840 = s_French_0058043c;

      local_6a8 = 0;

      break;

    case 0x10:

      DAT_005e2840 = s_Italian_00580444;

      local_6a8 = 0;

      break;

    case 0x11:

      DAT_005e2840 = s_Japanese_00580420;

      local_6a8 = 0;

    }

    do {

      if (local_6a8 == 0) {

        FUN_00542f27(local_540,s__s_____00580418,s_Bin_Override_00580324);

        iVar2 = FUN_00539230(DAT_005e2c70,local_540);

        *(undefined4 *)(iVar2 + 4) = 0;

        pvVar3 = FindFirstFileA(local_540,&local_6a0);

        if (pvVar3 == (HANDLE)0xffffffff) goto LAB_00538bf0;

        do {

          DAT_005e2c60 = iVar2;

          iVar4 = FUN_005393e0(DAT_005e2c74,local_6a0.cFileName);

          if (iVar4 == 0) {

            iVar4 = FUN_00539230(DAT_005e2c74,local_6a0.cFileName);

            *(int *)(iVar4 + 4) = DAT_005e2c60;

            *(undefined4 *)(iVar4 + 8) = 0;

            *(undefined4 *)(iVar4 + 0xc) = 0;

          }

          else {

            iVar5 = *(int *)(*(int *)(iVar4 + 4) + 4);

            if ((*(int *)(DAT_005e2c60 + 4) <= iVar5) &&

               ((*(int *)(DAT_005e2c60 + 4) < iVar5 ||

                (iVar5 = FUN_00545650(*(int *)(iVar4 + 4) + 8,DAT_005e2c60 + 8), 0 < iVar5)))) {

              *(int *)(iVar4 + 4) = DAT_005e2c60;

              *(undefined4 *)(iVar4 + 8) = 0;

              *(undefined4 *)(iVar4 + 0xc) = 0;

            }

          }

          BVar6 = FindNextFileA(pvVar3,&local_6a0);

        } while (BVar6 != 0);

LAB_00538bea:

        FindClose(pvVar3);

      }

      else if (local_6a8 == 0) {

        pcVar7 = s_Bin_Override_00580324;

LAB_00538add:

        FUN_00542f27(local_540,s__s___gzp_0058040c,pcVar7);

        pvVar3 = FindFirstFileA(local_540,&local_6a0);

        if (pvVar3 != (HANDLE)0xffffffff) {

          do {

            iVar2 = FUN_00545540(local_6a0.cFileName,s_VO_Sfx_00580404,6);

            if (iVar2 == 0) {

              FUN_00538800();

              FUN_00538800();

              uVar8 = 0xffffffff;

              pcVar10 = DAT_005e2840;

              do {

                if (uVar8 == 0) break;

                uVar8 = uVar8 - 1;

                cVar1 = *pcVar10;

                pcVar10 = pcVar10 + 1;

              } while (cVar1 != '\0');

              iVar2 = FUN_00545540(local_6a0.cFileName + 6,DAT_005e2840,~uVar8 - 1);

              if (iVar2 == 0) goto LAB_00538b60;

            }

            else {

LAB_00538b60:

              iVar2 = FUN_005393e0(DAT_005e2c70,local_6a0.cFileName);

              if (iVar2 == 0) {

                iVar2 = FUN_00539230(DAT_005e2c70,local_6a0.cFileName);

                *(int *)(iVar2 + 4) = local_6a8;

                FUN_00542f27(local_200,s__s__s_0058031c,pcVar7,local_6a0.cFileName);

                iVar4 = FUN_00539b10(local_200);

                if (iVar4 != 0) {

                  DAT_005e2c60 = iVar2;

                  FUN_00539a80(&LAB_00538f60);

                  FUN_00539cb0();

                }

              }

            }

            BVar6 = FindNextFileA(pvVar3,&local_6a0);

          } while (BVar6 != 0);

          goto LAB_00538bea;

        }

      }

      else {

        if (local_6a8 == 1) {

          pcVar7 = &DAT_00580334;

          goto LAB_00538add;

        }

        if (local_6a8 == 2) {

          if (DAT_005e2a60 != '\0') {

            puVar11 = &DAT_005e2a60;

            goto LAB_00538ab8;

          }

        }

        else if (DAT_005e2b60 != '\0') {

          puVar11 = &DAT_005e2b60;

LAB_00538ab8:

          FUN_00542f27(&DAT_005e2740,s__s_Bin_00580338,puVar11);

          pcVar7 = &DAT_005e2740;

          goto LAB_00538add;

        }

      }

LAB_00538bf0:

      local_6a8 = local_6a8 + 1;

    } while (local_6a8 < 4);

    iVar2 = 1;

    do {

      if (iVar2 == 0) {

        pcVar7 = s_Bin_Override_00580324;

LAB_00538c5f:

        FUN_00542f27(local_540,s__s_____00580418,pcVar7);

        pvVar3 = FindFirstFileA(local_540,&local_6a0);

        if (pvVar3 != (HANDLE)0xffffffff) {

          do {

            if (local_6a0.cFileName[0] != '.') {

              uVar8 = 0xffffffff;

              pCVar9 = local_6a0.cFileName;

              do {

                if (uVar8 == 0) break;

                uVar8 = uVar8 - 1;

                cVar1 = *pCVar9;

                pCVar9 = pCVar9 + 1;

              } while (cVar1 != '\0');

              pCVar9 = local_6a0.cFileName + (~uVar8 - 5);

              if ((pCVar9 < local_6a0.cFileName) ||

                 ((iVar4 = FUN_0053a860(pCVar9,&DAT_005803fc), iVar4 == 0 &&

                  (iVar4 = FUN_0053a860(pCVar9,&DAT_005803f4), iVar4 == 0)))) {

                iVar4 = FUN_005393e0(DAT_005e2c78,local_6a0.cFileName);

                if (iVar4 != 0) break;

                iVar4 = FUN_00539230(DAT_005e2c78,local_6a0.cFileName);

                *(char *)(iVar4 + 4) = (char)iVar2;

              }

            }

            BVar6 = FindNextFileA(pvVar3,&local_6a0);

          } while (BVar6 != 0);

          FindClose(pvVar3);

        }

      }

      else {

        if (iVar2 == 1) {

          pcVar7 = &DAT_00580334;

          goto LAB_00538c5f;

        }

        if (iVar2 == 2) {

          if (DAT_005e2a60 != '\0') {

            puVar11 = &DAT_005e2a60;

            goto LAB_00538c3a;

          }

        }

        else if (DAT_005e2b60 != '\0') {

          puVar11 = &DAT_005e2b60;

LAB_00538c3a:

          FUN_00542f27(&DAT_005e2740,s__s_Bin_00580338,puVar11);

          pcVar7 = &DAT_005e2740;

          goto LAB_00538c5f;

        }

      }

      iVar2 = iVar2 + 1;

    } while (iVar2 < 4);

    local_6a8 = 1;

    do {

      switch(local_6a8) {

      case 0:

        break;

      case 1:

        pcVar10 = s_Stream_s_0058036c;

        pcVar7 = DAT_005e2840;

LAB_00538dca:

        FUN_00542f27(&DAT_005e2960,pcVar10,pcVar7);

LAB_00538dd7:

        pcVar7 = &DAT_005e2960;

        goto LAB_00538ddc;

      case 2:

        pcVar7 = s_Stream_00580364;

LAB_00538ddc:

        FUN_00542f27(local_540,s__s_____00580418,pcVar7);

        pvVar3 = FindFirstFileA(local_540,&local_6a0);

        if (pvVar3 != (HANDLE)0xffffffff) {

          do {

            if ((local_6a0.cFileName[0] != '.') && (((byte)local_6a0.dwFileAttributes & 0x10) != 0))

            {

              FUN_00542f27(local_540,s__s__s___wav_005803e8,pcVar7,local_6a0.cFileName);

              hFindFile = FindFirstFileA(local_540,&local_340);

              iVar2 = 0;

              if (hFindFile != (HANDLE)0xffffffff) {

                do {

                  if ((local_340.cFileName[0] != '.') &&

                     (iVar4 = FUN_005393e0(DAT_005e2c7c,local_340.cFileName), iVar4 == 0)) {

                    if (iVar2 == 0) {

                      iVar2 = FUN_00539500(DAT_005e2c80,local_6a0.cFileName);

                      *(undefined1 *)(iVar2 + 4) = (undefined1)local_6a8;

                    }

                    iVar4 = FUN_00539230(DAT_005e2c7c,local_340.cFileName);

                    *(int *)(iVar4 + 4) = iVar2;

                  }

                  BVar6 = FindNextFileA(hFindFile,&local_340);

                } while (BVar6 != 0);

                FindClose(hFindFile);

              }

            }

            BVar6 = FindNextFileA(pvVar3,&local_6a0);

          } while (BVar6 != 0);

          FindClose(pvVar3);

        }

        break;

      case 3:

        if (DAT_005e2a60 != '\0') {

          puVar11 = &DAT_005e2a60;

LAB_00538d9f:

          FUN_00542f27(&DAT_005e2960,s__s_Stream_s_00580358,puVar11,DAT_005e2840);

          goto LAB_00538dd7;

        }

        break;

      case 4:

        if (DAT_005e2a60 != '\0') {

          pcVar7 = &DAT_005e2a60;

LAB_00538dc5:

          pcVar10 = s__s_Stream_0058034c;

          goto LAB_00538dca;

        }

        break;

      case 5:

        if (DAT_005e2b60 != '\0') {

          puVar11 = &DAT_005e2b60;

          goto LAB_00538d9f;

        }

        break;

      default:

        if (DAT_005e2b60 != '\0') {

          pcVar7 = &DAT_005e2b60;

          goto LAB_00538dc5;

        }

      }

      local_6a8 = local_6a8 + 1;

    } while (local_6a8 < 7);

  }

  return;

}

/* ===== FUN_00538ff0 @ 0x00538FF0 ===== */
void FUN_00538ff0(int param_1)



{

  if (param_1 != 0) {

    DAT_005e2c8c = param_1;

  }

  return;

}

/* ===== FUN_00539000 @ 0x00539000 ===== */
undefined4 FUN_00539000(void)



{

  FUN_00538800();

  return DAT_005e2840;

}

/* ===== FUN_00539010 @ 0x00539010 ===== */
bool FUN_00539010(void)



{

  char *pcVar1;

  char cVar2;

  BOOL BVar3;

  int iVar4;

  undefined1 *puVar5;

  CHAR *lpVolumeNameBuffer;

  DWORD nVolumeNameSize;

  DWORD *lpVolumeSerialNumber;

  DWORD *lpMaximumComponentLength;

  DWORD *lpFileSystemFlags;

  CHAR *lpFileSystemNameBuffer;

  DWORD nFileSystemNameSize;

  DWORD local_31c;

  DWORD local_318;

  DWORD local_314;

  DWORD local_310;

  DWORD local_30c;

  DWORD local_308;

  DWORD local_304;

  char local_300 [256];

  CHAR local_200 [256];

  CHAR local_100 [256];

  

  if (DAT_00633238 != 0) {

    return true;

  }

  if (DAT_005e2b60 == '\0') {

    return false;

  }

  puVar5 = &DAT_005e2b60;

  cVar2 = DAT_005e2b60;

  while ((cVar2 != '\\' && (cVar2 != '\0'))) {

    pcVar1 = puVar5 + 1;

    puVar5 = puVar5 + 1;

    cVar2 = *pcVar1;

  }

  _strncpy(local_300,&DAT_005e2b60,(size_t)(puVar5 + -0x5e2b5f));

  nFileSystemNameSize = 0x100;

  lpFileSystemNameBuffer = local_100;

  lpFileSystemFlags = &local_304;

  lpMaximumComponentLength = &local_308;

  lpVolumeSerialNumber = &local_30c;

  nVolumeNameSize = 0x100;

  lpVolumeNameBuffer = local_200;

  (&stack0xffa1d1a1)[(int)puVar5] = 0;

  BVar3 = GetVolumeInformationA

                    (local_300,lpVolumeNameBuffer,nVolumeNameSize,lpVolumeSerialNumber,

                     lpMaximumComponentLength,lpFileSystemFlags,lpFileSystemNameBuffer,

                     nFileSystemNameSize);

  if (BVar3 == 0) {

    return false;

  }

  BVar3 = GetDiskFreeSpaceA(local_300,&local_310,&local_314,&local_31c,&local_318);

  if (BVar3 == 0) {

    return false;

  }

  iVar4 = FUN_00545650();

  if (iVar4 == 0) {

    iVar4 = FUN_00545650();

    if (iVar4 == 0) {

      return local_31c == 0;

    }

    return false;

  }

  return false;

}

/* ===== FUN_00539140 @ 0x00539140 ===== */
bool FUN_00539140(undefined4 param_1)



{

  int iVar1;

  

  iVar1 = FUN_005393e0(DAT_005e2c78,param_1);

  return iVar1 != 0;

}

/* ===== FUN_00539160 @ 0x00539160 ===== */
void FUN_00539160(void)



{

  FUN_00539470(DAT_005e2c78);

  FUN_00539470(DAT_005e2c74);

  FUN_00539470(DAT_005e2c70);

  FUN_005395a0(DAT_005e2c80);

  FUN_00539470(DAT_005e2c7c);

  DAT_005e2c6c = 0;

  DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_005e2948);

  return;

}

/* ===== FUN_005393e0 @ 0x005393E0 ===== */
/* PS2 candidate: strcmp (conf 0.544) */



undefined4 * FUN_005393e0(int param_1,char *param_2)



{

  undefined4 *puVar1;

  uint uVar2;

  int iVar3;

  uint uVar4;

  uint *puVar5;

  uint local_40 [16];

  

  puVar5 = local_40;

  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {

    *puVar5 = 0;

    puVar5 = puVar5 + 1;

  }

  _strncpy((char *)local_40,param_2,0x40);

  uVar2 = 0;

  uVar4 = 0;

  do {

    uVar2 = uVar2 + (local_40[uVar4] & 0xdfdfdfdf);

    uVar4 = uVar4 + 1;

  } while (uVar4 < 0x10);

  puVar1 = *(undefined4 **)

            (param_1 + 0x14 +

            (int)((longlong)(ulonglong)(uVar2 & 0x7fffffff) % (longlong)*(int *)(param_1 + 0xc)) * 4

            );

  while( true ) {

    if (puVar1 == (undefined4 *)0x0) {

      return (undefined4 *)0x0;

    }

    if ((*(byte *)(param_1 + 0x10) & 1) == 0) {

      iVar3 = *(int *)(param_1 + 8) + -1 + (int)puVar1;

    }

    else {

      iVar3 = *(int *)(*(int *)(param_1 + 8) + -4 + (int)puVar1);

    }

    iVar3 = FUN_00545650(param_2,iVar3);

    if (iVar3 == 0) break;

    puVar1 = (undefined4 *)*puVar1;

  }

  return puVar1;

}

/* ===== FUN_00539a80 @ 0x00539A80 ===== */
undefined4 FUN_00539a80(code *param_1)



{

  undefined4 *puVar1;

  undefined4 *puVar2;

  

  puVar2 = DAT_005e6ca4;

  while (puVar2 != (undefined4 *)0x0) {

    puVar1 = (undefined4 *)*puVar2;

    (*param_1)((int)puVar2 + 0x16,puVar2[2],puVar2[1],puVar2[4],puVar2[3]);

    puVar2 = puVar1;

  }

  return 1;

}

/* ===== FUN_00539ac0 @ 0x00539AC0 ===== */
undefined4 FUN_00539ac0(LPCSTR param_1)



{

  if (DAT_005f010c != (HANDLE)0x0) {

    return 0;

  }

  DAT_005f010c = CreateFileA(param_1,0x80000000,1,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);

  if (DAT_005f010c == (HANDLE)0xffffffff) {

    DAT_005f010c = (HANDLE)0x0;

    return 0;

  }

  DAT_005e2c90 = 0;

  return 1;

}

/* ===== FUN_00539de0 @ 0x00539DE0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_00539de0(undefined4 param_1)



{

  if (DAT_005f0164 != 0) {

    FUN_00425eb0();

    return;

  }

  DAT_005f0168 = param_1;

  DAT_005f0164 = 1;

  _DAT_005f011c = 0x71625344;

  _DAT_005f0120 = 0;

  DAT_005f0124 = &DAT_005f011c;

  DAT_005f0128 = &DAT_005f011c;

  DAT_005f0118 = 0;

  DAT_005f0150 = 0;

  DAT_005f015c = 0;

  DAT_005f0154 = 0;

  DAT_005f0158 = 0;

  DAT_005f0110 = 0;

  DAT_005f0160 = 0;

  DAT_005f0114 = 0;

  DAT_00630ed0 = 0;

  return;

}

/* ===== FUN_00539e60 @ 0x00539E60 ===== */
void FUN_00539e60(void)



{

  int *piVar1;

  undefined *puVar2;

  int *piVar3;

  int iVar4;

  int *piVar5;

  int *piVar6;

  bool bVar7;

  undefined1 local_290 [256];

  undefined1 local_190 [200];

  undefined1 local_c8 [200];

  

  if (DAT_005f0168 != 0) {

    iVar4 = *DAT_005f0124;

    piVar1 = DAT_005f0124;

    while (iVar4 != 0x71625344) {

      if (DAT_005f0168 != 0) {

        piVar3 = piVar1 + 0xc;

        if ((*piVar1 != 0x12345678) && (*piVar1 != 0x12345679)) {

          if ((DAT_005f0168 & 1) != 0) {

            piVar3 = piVar1 + 0x10;

          }

          FUN_00542f27(local_c8,s_MemVfy__Bad_magic__lX_from__s_li_005804ec,piVar3,piVar1 + 4,

                       piVar1[0xb]);

          FUN_00425eb0(local_c8);

          DAT_005f0114 = DAT_005f0114 + 1;

          break;

        }

        if ((DAT_005f0168 & 1) != 0) {

          iVar4 = 4;

          bVar7 = true;

          piVar5 = piVar3;

          piVar6 = (int *)PTR_s_0123456789ABCDEF_005804d4;

          do {

            if (iVar4 == 0) break;

            iVar4 = iVar4 + -1;

            bVar7 = *piVar5 == *piVar6;

            piVar5 = piVar5 + 1;

            piVar6 = piVar6 + 1;

          } while (bVar7);

          if (!bVar7) {

            FUN_00542f27(local_190,s_Crpt_strt_pkt_sz_ad__lu__lX_from_00580540,piVar1[1],

                         piVar1 + 0x10,piVar1 + 4);

            FUN_00425eb0(local_190);

            puVar2 = PTR_s_0123456789ABCDEF_005804d4;

            *piVar3 = *(int *)PTR_s_0123456789ABCDEF_005804d4;

            piVar1[0xd] = *(int *)(puVar2 + 4);

            piVar1[0xe] = *(int *)(puVar2 + 8);

            piVar1[0xf] = *(int *)(puVar2 + 0xc);

            DAT_005f0114 = DAT_005f0114 + 1;

          }

          piVar3 = (int *)(piVar1[1] + 0x10 + (int)piVar3);

          iVar4 = 4;

          bVar7 = true;

          piVar5 = piVar3;

          piVar6 = (int *)PTR_s_0123456789ABCDEF_005804d4;

          do {

            if (iVar4 == 0) break;

            iVar4 = iVar4 + -1;

            bVar7 = *piVar5 == *piVar6;

            piVar5 = piVar5 + 1;

            piVar6 = piVar6 + 1;

          } while (bVar7);

          if (!bVar7) {

            FUN_00542f27(local_190,s_Crpt_end_pkt_sz_ad__lu__lX_from___00580514,piVar1[1],

                         piVar1 + 0x10,piVar1 + 4);

            FUN_00425eb0(local_190);

            puVar2 = PTR_s_0123456789ABCDEF_005804d4;

            *piVar3 = *(int *)PTR_s_0123456789ABCDEF_005804d4;

            piVar3[1] = *(int *)(puVar2 + 4);

            piVar3[2] = *(int *)(puVar2 + 8);

            piVar3[3] = *(int *)(puVar2 + 0xc);

            DAT_005f0114 = DAT_005f0114 + 1;

          }

        }

      }

      piVar1 = (int *)piVar1[2];

      iVar4 = *piVar1;

    }

  }

  if ((DAT_005f0168 & 4) != 0) {

    bVar7 = true;

    iVar4 = *DAT_005f0124;

    piVar1 = DAT_005f0124;

    while (iVar4 != 0x71625344) {

      if (bVar7) {

        FUN_00425eb0();

      }

      bVar7 = false;

      piVar3 = piVar1 + 0xc;

      if ((DAT_005f0168 & 1) != 0) {

        piVar3 = piVar1 + 0x10;

      }

      FUN_00542f27(local_290,s_Memory_block_size__6u_at__8X_fro_005807d4,piVar1[1],piVar3,piVar1 + 4

                   ,piVar1[0xb]);

      FUN_00425eb0(local_290);

      piVar1 = (int *)piVar1[2];

      iVar4 = *piVar1;

    }

  }

  if ((DAT_005f0168 & 2) != 0) {

    FUN_00542f27(local_290,s_Total___of_allocations____8lu_005807b0,DAT_005f0118);

    FUN_00425eb0(local_290);

    FUN_00542f27(local_290,s_Max_simultaneous_allocs____8lu_0058078c,DAT_005f0150);

    FUN_00425eb0(local_290);

    FUN_00542f27(local_290,s_Total_allocated_bytes____8lu_00580768,DAT_005f015c);

    FUN_00425eb0(local_290);

    FUN_00542f27(local_290,s_Total_allocated_Mb____8_2f_00580748,

                 (double)((float)DAT_005f015c * 9.536743e-07));

    FUN_00425eb0(local_290);

    FUN_00542f27(local_290,s_Max_simultaneous_bytes____8lu_00580724,DAT_005f0154);

    FUN_00425eb0(local_290);

    FUN_00542f27(local_290,s_Max_simultaneous_Mb____8_2f_00580704,

                 (double)((float)DAT_005f0154 * 9.536743e-07));

    FUN_00425eb0(local_290);

    FUN_00542f27(local_290,s_Largest_allocation____8lu_005806e0,DAT_005f0158);

    FUN_00425eb0(local_290);

    FUN_00542f27(local_290,s_Current_allocated_bytes____8lu_005806bc,DAT_005f0160);

    FUN_00425eb0(local_290);

    FUN_00542f27(local_290,s_Current_allocated_Mb____8_2f_0058069c,

                 (double)((float)DAT_005f0160 * 9.536743e-07));

    FUN_00425eb0(local_290);

    FUN_00542f27(local_290,s_Current_allocs____8lu_00580678,DAT_005f0110);

    FUN_00425eb0(local_290);

    FUN_00542f27(local_290,s_Bad_Pickets____8lu_00580658,DAT_005f0114);

    FUN_00425eb0(local_290);

    if (DAT_005f0110 != 0) {

      FUN_00542f27(local_290,s_Warning__d_Unfreed_Mallocs_See_D_005805f8,DAT_005f0110);

      FUN_0051ea20(local_290);

    }

    if (DAT_005f0114 != 0) {

      FUN_00542f27(local_290,s_Warning__d_Bad_Pickets_See_Debug_00580598,DAT_005f0114);

      FUN_0051ea20(local_290);

    }

  }

  return;

}

/* ===== FUN_0053a270 @ 0x0053A270 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined4 * FUN_0053a270(undefined4 param_1,uint param_2,char *param_3,undefined4 param_4)



{

  undefined *puVar1;

  void *pvVar2;

  char *pcVar3;

  undefined4 *puVar4;

  char cVar5;

  undefined4 *puVar6;

  uint uVar7;

  char *pcVar8;

  char *pcVar9;

  char *pcVar10;

  

  if (DAT_005f0164 == 0) {

    DAT_005f0124 = &DAT_005f011c;

    DAT_005f0128 = (undefined4 *)&DAT_005f011c;

    DAT_005f0164 = 1;

    DAT_005f0168 = 0;

    _DAT_005f011c = 0x71625344;

    _DAT_005f0120 = 0;

    DAT_005f0118 = 0;

    DAT_005f0150 = 0;

    DAT_005f015c = 0;

    DAT_005f0154 = 0;

    DAT_005f0158 = 0;

    DAT_005f0110 = 0;

    DAT_005f0160 = 0;

    DAT_005f0114 = 0;

    DAT_00630ed0 = 0;

  }

  if (param_2 == 0) {

    return (undefined4 *)0x0;

  }

  if (DAT_005f0168 == 0) {

    pvVar2 = _malloc(param_2 + 0x10);

    puVar6 = (undefined4 *)((int)pvVar2 + 0x10U & 0xfffffff0);

    puVar6[-1] = (uint)pvVar2 & 0xf;

    return puVar6;

  }

  DAT_005f0118 = DAT_005f0118 + 1;

  DAT_005f0110 = DAT_005f0110 + 1;

  if (DAT_005f0150 < DAT_005f0110) {

    DAT_005f0150 = DAT_005f0110;

  }

  DAT_005f0160 = DAT_005f0160 + param_2;

  DAT_005f015c = DAT_005f015c + param_2;

  if (DAT_005f0154 < DAT_005f0160) {

    DAT_005f0154 = DAT_005f0160;

  }

  if (DAT_005f0158 < param_2) {

    DAT_005f0158 = param_2;

  }

  uVar7 = param_2;

  if ((DAT_005f0168 & 1) != 0) {

    uVar7 = param_2 + 0x20;

  }

  pvVar2 = _malloc(uVar7 + 0x40);

  puVar6 = (undefined4 *)((int)pvVar2 + 0x10U & 0xfffffff0);

  puVar6[-1] = (uint)pvVar2 & 0xf;

  uVar7 = 0xffffffff;

  puVar6[1] = param_2;

  *puVar6 = 0x12345678;

  pcVar8 = param_3;

  do {

    if (uVar7 == 0) break;

    uVar7 = uVar7 - 1;

    cVar5 = *pcVar8;

    pcVar8 = pcVar8 + 1;

  } while (cVar5 != '\0');

  pcVar3 = param_3 + (~uVar7 - 2);

  cVar5 = *param_3;

  pcVar8 = param_3;

  if (cVar5 != '\0') {

    pcVar9 = param_3 + -1;

    do {

      if ((cVar5 == '\\') || (cVar5 == ':')) {

        pcVar8 = pcVar9 + 2;

      }

      if (cVar5 == '.') {

        pcVar3 = pcVar9;

      }

      cVar5 = pcVar9[2];

      pcVar9 = pcVar9 + 1;

    } while (cVar5 != '\0');

  }

  if (pcVar3 < pcVar8) {

    uVar7 = 0xffffffff;

    pcVar3 = param_3;

    do {

      if (uVar7 == 0) break;

      uVar7 = uVar7 - 1;

      cVar5 = *pcVar3;

      pcVar3 = pcVar3 + 1;

    } while (cVar5 != '\0');

    pcVar3 = param_3 + (~uVar7 - 2);

  }

  if (0x1b < (int)(pcVar3 + (1 - (int)pcVar8))) {

    pcVar3 = pcVar8 + 0x1a;

  }

  pcVar9 = pcVar8;

  pcVar10 = (char *)(puVar6 + 4);

  for (uVar7 = (uint)(pcVar3 + (1 - (int)pcVar8)) >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {

    *(undefined4 *)pcVar10 = *(undefined4 *)pcVar9;

    pcVar9 = pcVar9 + 4;

    pcVar10 = pcVar10 + 4;

  }

  for (uVar7 = (uint)(pcVar3 + (1 - (int)pcVar8)) & 3; uVar7 != 0; uVar7 = uVar7 - 1) {

    *pcVar10 = *pcVar9;

    pcVar9 = pcVar9 + 1;

    pcVar10 = pcVar10 + 1;

  }

  *(char *)((int)(puVar6 + 4) + (int)(pcVar3 + (1 - (int)pcVar8))) = '\0';

  puVar6[0xb] = param_4;

  puVar6[2] = &DAT_005f011c;

  puVar6[3] = DAT_005f0128;

  *(undefined4 **)((int)DAT_005f0128 + 8) = puVar6;

  puVar1 = PTR_s_0123456789ABCDEF_005804d4;

  puVar4 = puVar6 + 0xc;

  DAT_005f0128 = puVar6;

  if ((DAT_005f0168 & 1) != 0) {

    *puVar4 = *(undefined4 *)PTR_s_0123456789ABCDEF_005804d4;

    puVar6[0xd] = *(undefined4 *)(puVar1 + 4);

    puVar6[0xe] = *(undefined4 *)(puVar1 + 8);

    puVar6[0xf] = *(undefined4 *)(puVar1 + 0xc);

    puVar1 = PTR_s_0123456789ABCDEF_005804d4;

    puVar4 = (undefined4 *)((int)puVar6 + param_2 + 0x40);

    *puVar4 = *(undefined4 *)PTR_s_0123456789ABCDEF_005804d4;

    puVar4[1] = *(undefined4 *)(puVar1 + 4);

    puVar4[2] = *(undefined4 *)(puVar1 + 8);

    puVar4[3] = *(undefined4 *)(puVar1 + 0xc);

    puVar4 = puVar6 + 0x10;

  }

  return puVar4;

}

/* ===== mem_free_tagged @ 0x0053A4B0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* PS2 candidate: temp_create_rndr_base__FPUcT0P10ObjectData (conf 0.39) */



void mem_free_tagged(int *param_1)



{

  undefined *puVar1;

  uint uVar2;

  int iVar3;

  int *piVar4;

  int *piVar5;

  int *piVar6;

  bool bVar7;

  undefined1 local_190 [200];

  undefined1 local_c8 [200];

  

  if (DAT_005f0164 == 0) {

    DAT_005f0164 = 1;

    DAT_005f0168 = 0;

    _DAT_005f011c = 0x71625344;

    _DAT_005f0120 = 0;

    DAT_005f0124 = &DAT_005f011c;

    DAT_005f0128 = &DAT_005f011c;

    DAT_005f0118 = 0;

    DAT_005f0150 = 0;

    DAT_005f015c = 0;

    DAT_005f0154 = 0;

    DAT_005f0158 = 0;

    DAT_005f0110 = 0;

    DAT_005f0160 = 0;

    DAT_005f0114 = 0;

    DAT_00630ed0 = 0;

  }

  if (param_1 != (int *)0x0) {

    if (DAT_005f0168 == 0) {

      FUN_005443bf(param_1[-1] + -0x10 + (int)param_1);

      return;

    }

    uVar2 = DAT_005f0168 & 1;

    if (uVar2 != 0) {

      param_1 = param_1 + -4;

    }

    if ((param_1[-0xc] != 0x12345678) && (param_1[-0xc] != 0x12345679)) {

      piVar4 = param_1;

      if (uVar2 != 0) {

        piVar4 = param_1 + 4;

      }

      FUN_00542f27(local_c8,s_MemVfy__Bad_magic__lX_from__s_li_005804ec,piVar4,param_1 + -8,

                   param_1[-1]);

      FUN_00425eb0(local_c8);

      DAT_005f0114 = DAT_005f0114 + 1;

      FUN_0051ea20(s_Bad_Memory_Picket_Found_0058081c);

      return;

    }

    if (uVar2 != 0) {

      iVar3 = 4;

      bVar7 = true;

      piVar4 = param_1;

      piVar5 = (int *)PTR_s_0123456789ABCDEF_005804d4;

      do {

        if (iVar3 == 0) break;

        iVar3 = iVar3 + -1;

        bVar7 = *piVar4 == *piVar5;

        piVar4 = piVar4 + 1;

        piVar5 = piVar5 + 1;

      } while (bVar7);

      if (!bVar7) {

        FUN_00542f27(local_190,s_Crpt_strt_pkt_sz_ad__lu__lX_from_00580540,param_1[-0xb],param_1 + 4

                     ,param_1 + -8,param_1[-1]);

        FUN_00425eb0(local_190);

        puVar1 = PTR_s_0123456789ABCDEF_005804d4;

        *param_1 = *(int *)PTR_s_0123456789ABCDEF_005804d4;

        param_1[1] = *(int *)(puVar1 + 4);

        param_1[2] = *(int *)(puVar1 + 8);

        param_1[3] = *(int *)(puVar1 + 0xc);

        DAT_005f0114 = DAT_005f0114 + 1;

      }

      piVar4 = (int *)(param_1[-0xb] + 0x10 + (int)param_1);

      iVar3 = 4;

      bVar7 = true;

      piVar5 = piVar4;

      piVar6 = (int *)PTR_s_0123456789ABCDEF_005804d4;

      do {

        if (iVar3 == 0) break;

        iVar3 = iVar3 + -1;

        bVar7 = *piVar5 == *piVar6;

        piVar5 = piVar5 + 1;

        piVar6 = piVar6 + 1;

      } while (bVar7);

      if (!bVar7) {

        FUN_00542f27(local_190,s_Crpt_end_pkt_sz_ad__lu__lX_from___00580514,param_1[-0xb],

                     param_1 + 4,param_1 + -8,param_1[-1]);

        FUN_00425eb0(local_190);

        puVar1 = PTR_s_0123456789ABCDEF_005804d4;

        *piVar4 = *(int *)PTR_s_0123456789ABCDEF_005804d4;

        piVar4[1] = *(int *)(puVar1 + 4);

        piVar4[2] = *(int *)(puVar1 + 8);

        piVar4[3] = *(int *)(puVar1 + 0xc);

        DAT_005f0114 = DAT_005f0114 + 1;

      }

    }

    DAT_005f0110 = DAT_005f0110 + -1;

    DAT_005f0160 = DAT_005f0160 - param_1[-0xb];

    *(int *)(param_1[-9] + 8) = param_1[-10];

    *(int *)(param_1[-10] + 0xc) = param_1[-9];

    param_1[-0xc] = 0x33abcdef;

    FUN_005443bf(param_1[-0xd] + -0x40 + (int)param_1);

  }

  return;

}

/* ===== FUN_0053a700 @ 0x0053A700 ===== */
/* PS2 candidate: MemAllocMsg (conf 0.691) */



int FUN_0053a700(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,

                undefined4 param_5)



{

  int iVar1;

  undefined1 local_c8 [200];

  

  iVar1 = FUN_0053a270(param_1,param_2,param_4,param_5);

  if ((iVar1 == 0) && (param_2 != 0)) {

    FUN_00542f27(local_c8,s_Memory_Fail_on__s___ld_bytes___s_00580834,param_3,param_2,param_4,

                 param_5);

    FUN_00425eb0(local_c8);

    FUN_0051ea20(local_c8);

  }

  return iVar1;

}

/* ===== MemString @ 0x0053A780 ===== */
void MemString(undefined4 param_1,char *param_2,int *param_3,undefined4 param_4,undefined4 param_5)



{

  char cVar1;

  int iVar2;

  uint uVar3;

  char *pcVar4;

  undefined1 local_c8 [200];

  

  uVar3 = 0xffffffff;

  pcVar4 = param_2;

  do {

    if (uVar3 == 0) break;

    uVar3 = uVar3 - 1;

    cVar1 = *pcVar4;

    pcVar4 = pcVar4 + 1;

  } while (cVar1 != '\0');

  uVar3 = ~uVar3;

  iVar2 = FUN_0053a270(param_1,uVar3,param_4,param_5);

  if ((iVar2 == 0) && (uVar3 != 0)) {

    FUN_00542f27(local_c8,s_Memory_Fail_on__s___ld_bytes___s_00580834,s_memstr_0058085c,uVar3,

                 param_4,param_5);

    FUN_00425eb0(local_c8);

    FUN_0051ea20(local_c8);

  }

  *param_3 = iVar2;

  iVar2 = iVar2 - (int)param_2;

  do {

    cVar1 = *param_2;

    param_2[iVar2] = cVar1;

    param_2 = param_2 + 1;

  } while (cVar1 != '\0');

  return;

}

/* ===== FUN_0053a830 @ 0x0053A830 ===== */
bool FUN_0053a830(undefined4 param_1,char *param_2)



{

  char cVar1;

  int iVar2;

  uint uVar3;

  char *pcVar4;

  

  uVar3 = 0xffffffff;

  pcVar4 = param_2;

  do {

    if (uVar3 == 0) break;

    uVar3 = uVar3 - 1;

    cVar1 = *pcVar4;

    pcVar4 = pcVar4 + 1;

  } while (cVar1 != '\0');

  iVar2 = FUN_00545540(param_1,param_2,~uVar3 - 1);

  return iVar2 == 0;

}

/* ===== FUN_0053a860 @ 0x0053A860 ===== */
bool FUN_0053a860(undefined4 param_1,undefined4 param_2)



{

  int iVar1;

  

  iVar1 = FUN_00545650(param_1,param_2);

  return iVar1 == 0;

}

/* ===== FUN_0053a880 @ 0x0053A880 ===== */
bool FUN_0053a880(undefined4 param_1,undefined4 param_2,undefined4 param_3)



{

  int iVar1;

  

  iVar1 = FUN_00545540(param_1,param_2,param_3);

  return iVar1 == 0;

}

/* ===== FUN_0053a8a0 @ 0x0053A8A0 ===== */
bool FUN_0053a8a0(byte *param_1,byte *param_2)



{

  byte bVar1;

  bool bVar2;

  

  while( true ) {

    bVar1 = *param_1;

    bVar2 = bVar1 < *param_2;

    if (bVar1 != *param_2) break;

    if (bVar1 == 0) {

      return true;

    }

    bVar1 = param_1[1];

    bVar2 = bVar1 < param_2[1];

    if (bVar1 != param_2[1]) break;

    param_1 = param_1 + 2;

    param_2 = param_2 + 2;

    if (bVar1 == 0) {

      return true;

    }

  }

  return 1 - bVar2 == (uint)(bVar2 != 0);

}

/* ===== FUN_0053a900 @ 0x0053A900 ===== */
void FUN_0053a900(undefined1 *param_1,undefined1 *param_2,int param_3,int param_4)



{

  if (param_4 <= param_3) {

    param_3 = param_4 + -1;

  }

  if (param_3 < 1) {

    *param_1 = 0;

    return;

  }

  do {

    *param_1 = *param_2;

    param_1 = param_1 + 1;

    param_2 = param_2 + 1;

    param_3 = param_3 + -1;

  } while (param_3 != 0);

  *param_1 = 0;

  return;

}

/* ===== FUN_0053ba50 @ 0x0053BA50 ===== */
int FUN_0053ba50(undefined4 param_1,int param_2,int *param_3)



{

  byte bVar1;

  int iVar2;

  undefined4 uVar3;

  int local_10;

  int local_c;

  int *local_8;

  undefined4 local_4;

  

  bVar1 = 0;

  if (param_2 != 0) {

    iVar2 = FUN_00543a11(param_2,&DAT_00555e04);

    if (iVar2 == 0) {

      FUN_00540310(s_Error_loading_ANM_Anim___s__0055b590,param_2);

    }

    else {

      FUN_005438c9(&local_10,8,1,iVar2);

      param_3 = (int *)FUN_0053ffa0(param_1,local_10,0);

      *param_3 = local_10;

      param_3[1] = local_c;

      FUN_005438c9(param_3 + 2,local_10 + -8,1,iVar2);

      FUN_0054384c(iVar2);

      bVar1 = 1;

    }

  }

  if (param_3 == (int *)0x0) {

    return 0;

  }

  uVar3 = FUN_0053feb0(param_1,param_3);

  iVar2 = FUN_0053fea0(uVar3);

  local_4 = 1;

  local_8 = param_3;

  FUN_0053d810(iVar2,&local_8);

  *(uint *)(iVar2 + 8) = (uint)bVar1 | (uint)param_3;

  return iVar2;

}

/* ===== FUN_0053bb30 @ 0x0053BB30 ===== */
uint FUN_0053bb30(int param_1)



{

  return *(uint *)(param_1 + 8) & 0xfffffffe;

}

/* ===== FUN_0053bb40 @ 0x0053BB40 ===== */
void FUN_0053bb40(void)



{

  FUN_005400e0();

  return;

}

/* ===== FUN_0053bb50 @ 0x0053BB50 ===== */
void FUN_0053bb50(int param_1,undefined4 param_2)



{

  int iVar1;

  undefined4 *puVar2;

  

  FUN_005400e0(param_1 + 4,param_2);

  FUN_005400e0(param_1 + 8,param_2);

  iVar1 = 0;

  if (0 < *(int *)(param_1 + 0x10)) {

    puVar2 = (undefined4 *)(param_1 + 0x14);

    do {

      FUN_005400e0(puVar2,param_2);

      FUN_0053bb40(*puVar2,param_2);

      iVar1 = iVar1 + 1;

      puVar2 = puVar2 + 1;

    } while (iVar1 < *(int *)(param_1 + 0x10));

  }

  return;

}

/* ===== FUN_0053bbb0 @ 0x0053BBB0 ===== */
void FUN_0053bbb0(int param_1,int param_2)



{

  undefined4 *puVar1;

  undefined4 uVar2;

  undefined4 uVar3;

  int iVar4;

  undefined4 *puVar5;

  int iVar6;

  

  uVar3 = param_2;

  FUN_005400e0(param_1 + 0xc,param_2);

  FUN_005400e0((undefined4 *)(param_1 + 0x10),param_2);

  puVar1 = (undefined4 *)(param_1 + 0x14);

  FUN_005400e0(puVar1,param_2);

  FUN_005400e0(param_1 + 0x18,param_2);

  FUN_00540530(*(undefined4 *)(param_1 + 0x10),0,param_2);

  FUN_00540530(*puVar1,&LAB_00540520,param_2);

  param_2 = 1;

  iVar4 = FUN_005404e0(*puVar1,0);

  while (iVar4 != 0) {

    puVar5 = (undefined4 *)FUN_005404a0(iVar4);

    uVar2 = *puVar5;

    FUN_00540530(uVar2,&LAB_00540520,uVar3);

    iVar6 = FUN_005404e0(uVar2,0);

    iVar4 = 1;

    while (iVar6 != 0) {

      puVar5 = (undefined4 *)FUN_005404a0(iVar6);

      FUN_0053bb50(*puVar5,uVar3);

      iVar6 = FUN_005404e0(uVar2,iVar4);

      iVar4 = iVar4 + 1;

    }

    iVar4 = FUN_005404e0(*puVar1,param_2);

    param_2 = param_2 + 1;

  }

  return;

}

/* ===== FUN_0053bc90 @ 0x0053BC90 ===== */
int FUN_0053bc90(undefined4 param_1,int param_2,int *param_3)



{

  byte bVar1;

  int iVar2;

  undefined4 uVar3;

  int local_10;

  int local_c;

  int *local_8;

  undefined4 local_4;

  

  bVar1 = 0;

  if (param_2 != 0) {

    iVar2 = FUN_00543a11(param_2,&DAT_00555e04);

    if (iVar2 == 0) {

      FUN_00540310(s_Error_loading_ANM_Skin___s__00580a50,param_2);

    }

    else {

      FUN_005438c9(&local_10,8,1,iVar2);

      param_3 = (int *)FUN_0053ffa0(param_1,local_10,0);

      *param_3 = local_10;

      param_3[1] = local_c;

      FUN_005438c9(param_3 + 2,local_10 + -8,1,iVar2);

      FUN_0054384c(iVar2);

      bVar1 = 1;

    }

  }

  if (param_3 == (int *)0x0) {

    return 0;

  }

  uVar3 = FUN_0053feb0(param_1,param_3);

  iVar2 = FUN_0053fea0(uVar3);

  local_4 = 1;

  local_8 = param_3;

  FUN_0053bbb0(iVar2,&local_8);

  *(uint *)(iVar2 + 8) = (uint)bVar1 | (uint)param_3;

  return iVar2;

}

/* ===== FUN_0053bd70 @ 0x0053BD70 ===== */
void FUN_0053bd70(int param_1)



{

  uint uVar1;

  undefined4 uVar2;

  

  uVar1 = *(uint *)(param_1 + 8);

  uVar2 = *(undefined4 *)(*(int *)(param_1 + 0xc) + 0xc);

  FUN_0053ff60(*(int *)(param_1 + 0xc));

  if ((uVar1 & 1) != 0) {

    FUN_00540020(uVar2,uVar1 & 0xfffffffe);

  }

  return;

}

/* ===== FUN_0053bda0 @ 0x0053BDA0 ===== */
undefined4 FUN_0053bda0(int param_1,int param_2,undefined4 param_3)



{

  int iVar1;

  undefined4 *puVar2;

  

  if (param_2 == 0) {

    iVar1 = FUN_005404e0(*(undefined4 *)(param_1 + 0x18),param_3);

  }

  else {

    iVar1 = FUN_005404c0(*(undefined4 *)(param_1 + 0x14),param_2);

    if (iVar1 == 0) {

      return 0;

    }

    puVar2 = (undefined4 *)FUN_005404a0(iVar1);

    iVar1 = FUN_005404e0(*puVar2,param_3);

  }

  if (iVar1 == 0) {

    return 0;

  }

  puVar2 = (undefined4 *)FUN_005404a0(iVar1);

  return *puVar2;

}

/* ===== FUN_0053be00 @ 0x0053BE00 ===== */
/* PS2 candidate: animGetIndexByName__FP12animSkeletonPc (conf 0.7) */



undefined4 FUN_0053be00(int param_1,int param_2,undefined4 param_3)



{

  int iVar1;

  undefined4 *puVar2;

  

  if (param_2 == 0) {

    iVar1 = FUN_005404c0(*(undefined4 *)(param_1 + 0x24),param_3);

  }

  else {

    iVar1 = FUN_005404c0(*(undefined4 *)(param_1 + 0x20),param_2);

    if (iVar1 == 0) {

      return 0;

    }

    puVar2 = (undefined4 *)FUN_005404a0(iVar1);

    iVar1 = FUN_005404c0(*puVar2,param_3);

  }

  if (iVar1 == 0) {

    return 0;

  }

  puVar2 = (undefined4 *)FUN_005404a0(iVar1);

  return *puVar2;

}

/* ===== FUN_0053be60 @ 0x0053BE60 ===== */
uint FUN_0053be60(uint param_1)



{

  return param_1 & ~-(uint)(*(short *)(param_1 + 4) != 1);

}

/* ===== FUN_0053be80 @ 0x0053BE80 ===== */
float10 FUN_0053be80(float param_1,undefined4 param_2)



{

  int *piVar1;

  int iVar2;

  undefined4 local_1c;

  undefined4 local_18;

  undefined4 local_c;

  

  piVar1 = (int *)((int)param_1 + 0xc);

  iVar2 = *(int *)((int)param_1 + 0xf8);

  param_1 = *(float *)((int)param_1 + 0xec);

  if (iVar2 != 0) {

    if (*(int *)(iVar2 + 8) == 0) {

      return (float10)*(float *)(iVar2 + 0xc);

    }

    local_1c = *(undefined4 *)(*piVar1 + 0x10);

    local_18 = *(undefined4 *)(*piVar1 + 0x14);

    local_c = param_2;

    FUN_0053bf20(&local_1c,iVar2);

    (**(code **)(iVar2 + 4))(&param_1,&local_1c);

  }

  return (float10)param_1;

}

/* ===== FUN_0053bef0 @ 0x0053BEF0 ===== */
int FUN_0053bef0(int param_1,undefined4 param_2,undefined4 param_3)



{

  undefined4 uVar1;

  

  uVar1 = FUN_0053cb50(param_1,param_2,param_3);

  (*(code *)PTR_FUN_00580c1c)(param_1 + 0xa4,uVar1);

  return param_1 + 0xa4;

}

/* ===== FUN_0053bf20 @ 0x0053BF20 ===== */
void FUN_0053bf20(int param_1,int param_2)



{

  byte bVar1;

  int iVar2;

  int iVar3;

  int *piVar4;

  undefined4 uVar5;

  int iVar6;

  uint uVar7;

  int iVar8;

  int iVar9;

  uint uVar10;

  uint local_8;

  uint local_4;

  

  uVar10 = *(uint *)(param_2 + 8);

  iVar2 = **(int **)(param_2 + 0xc);

  iVar8 = *(int *)(param_1 + 0x10);

  local_4 = 0;

  iVar3 = **(int **)(param_2 + 8 + uVar10 * 4);

  iVar9 = iVar3 - iVar2;

  if (((~*(byte *)(param_2 + 3) & 2) != 0) && (iVar9 != 0)) {

    if ((iVar8 < iVar2) && (bVar1 = *(byte *)(param_2 + 1), 1 < bVar1)) {

      if (bVar1 < 4) {

        iVar8 = iVar3 - (iVar3 - iVar8) % iVar9;

      }

      else if ((bVar1 == 4) &&

              (iVar6 = iVar3 - iVar8, iVar8 = iVar3 - iVar6 % iVar9, (iVar6 / iVar9 & 1U) != 0)) {

        iVar8 = (iVar3 - iVar8) + iVar2;

      }

    }

    if ((iVar3 < iVar8) && (bVar1 = *(byte *)(param_2 + 2), 1 < bVar1)) {

      if (bVar1 < 4) {

        iVar8 = (iVar8 - iVar2) % iVar9 + iVar2;

      }

      else if ((bVar1 == 4) &&

              (iVar6 = iVar8 - iVar2, iVar8 = iVar6 % iVar9 + iVar2, (iVar6 / iVar9 & 1U) != 0)) {

        iVar8 = (iVar3 - iVar8) + iVar2;

      }

    }

  }

  uVar7 = uVar10 >> 1;

  local_8 = uVar10;

  if (uVar10 != uVar10 >> 1) {

    do {

      local_8 = uVar7;

      iVar2 = **(int **)(param_2 + 0xc + local_8 * 4);

      if (iVar8 == iVar2) break;

      uVar7 = local_8;

      if (iVar8 - iVar2 < 0) {

        uVar10 = local_8;

        uVar7 = local_4;

      }

      local_4 = uVar7;

      uVar7 = (uVar10 - local_4 >> 1) + local_4;

    } while (local_8 != uVar7);

  }

  piVar4 = *(int **)(param_2 + 0xc + local_8 * 4);

  *(int **)(param_1 + 8) = piVar4;

  if (iVar8 < *piVar4) {

    *(int **)(param_1 + 0xc) = piVar4;

    uVar5 = *(undefined4 *)(param_2 + 8 + *(int *)(param_2 + 8) * 4);

    *(undefined4 *)(param_1 + 0x14) = 0x3f800000;

    *(undefined4 *)(param_1 + 8) = uVar5;

    *(float *)(param_1 + 0x18) = 1.0 - *(float *)(param_1 + 0x14);

    return;

  }

  if (local_8 != *(int *)(param_2 + 8) - 1U) {

    piVar4 = *(int **)(param_2 + 0x10 + local_8 * 4);

    *(int **)(param_1 + 0xc) = piVar4;

    *(float *)(param_1 + 0x14) =

         (float)(iVar8 - **(int **)(param_1 + 8)) / (float)(*piVar4 - **(int **)(param_1 + 8));

    *(float *)(param_1 + 0x18) = 1.0 - *(float *)(param_1 + 0x14);

    return;

  }

  uVar5 = *(undefined4 *)(param_2 + 0xc);

  *(undefined4 *)(param_1 + 0x14) = 0;

  *(undefined4 *)(param_1 + 0xc) = uVar5;

  *(float *)(param_1 + 0x18) = 1.0 - *(float *)(param_1 + 0x14);

  return;

}

/* ===== FUN_0053c5f0 @ 0x0053C5F0 ===== */
void FUN_0053c5f0(void)



{

  __ftol();

  return;

}

/* ===== FUN_0053c610 @ 0x0053C610 ===== */
float10 FUN_0053c610(int param_1,int param_2)



{

  return (float10)(param_2 - *(int *)(param_1 + 0x10)) /

         (float10)(*(int *)(param_1 + 0x1c) * *(int *)(param_1 + 0x18));

}

/* ===== FUN_0053c640 @ 0x0053C640 ===== */
float10 FUN_0053c640(int param_1,int param_2)



{

  return (float10)(param_2 - *(int *)(param_1 + 0x10) / *(int *)(param_1 + 0x18)) /

         (float10)*(int *)(param_1 + 0x1c);

}

/* ===== FUN_0053c660 @ 0x0053C660 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* PS2 candidate: item_get_ammo (conf 0.45) */



int FUN_0053c660(int param_1,int param_2,undefined4 param_3)



{

  float *pfVar1;

  short sVar2;

  undefined4 uVar3;

  int iVar4;

  undefined4 *puVar5;

  undefined4 local_b0;

  undefined4 local_ac;

  undefined4 local_a8;

  undefined4 uStack_a4;

  undefined4 uStack_a0;

  undefined4 uStack_9c;

  undefined4 local_98;

  undefined4 local_94;

  undefined4 *local_90;

  int local_88;

  undefined4 uStack_7c;

  undefined4 uStack_78;

  undefined4 uStack_74;

  undefined4 local_70;

  undefined4 local_6c;

  undefined4 local_68;

  undefined4 local_64;

  undefined4 uStack_60;

  undefined4 uStack_5c;

  undefined4 local_58;

  undefined4 uStack_50;

  undefined4 uStack_4c;

  undefined4 local_48;

  undefined4 uStack_40;

  undefined4 uStack_3c;

  undefined4 local_38;

  undefined1 auStack_20 [16];

  undefined1 auStack_10 [16];

  

  if (*(int *)(param_1 + 0x68) == param_2) goto LAB_0053ca5a;

  local_98 = *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x10);

  local_94 = *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x14);

  sVar2 = *(short *)(param_1 + 6);

  local_88 = param_2;

  if (sVar2 == 1) {

    FUN_0053bf20(&local_98,*(undefined4 *)(param_1 + 0x9c));

    puVar5 = (undefined4 *)(param_1 + 0x6c);

    for (iVar4 = 0xb; local_90 = local_90 + 1, iVar4 != 0; iVar4 = iVar4 + -1) {

      *puVar5 = *local_90;

      puVar5 = puVar5 + 1;

    }

    *(float *)(param_1 + 0x78) = -*(float *)(param_1 + 0x78);

    *(float *)(param_1 + 0x7c) = -*(float *)(param_1 + 0x7c);

    *(float *)(param_1 + 0x80) = -*(float *)(param_1 + 0x80);

    *(int *)(param_1 + 0x68) = param_2;

    return param_1 + 0x6c;

  }

  if (sVar2 == 2) {

    if (*(int *)(param_1 + 0x98) != 0) {

      FUN_0053bf20(&local_98,*(int *)(param_1 + 0x98));

      (**(code **)(*(int *)(param_1 + 0x98) + 4))(param_1 + 0x6c,&local_98);

      *(uint *)(param_1 + 0x94) = *(uint *)(param_1 + 0x94) | 0x10;

    }

    if (*(int *)(param_1 + 0x9c) != 0) {

      FUN_0053bf20(&local_98,*(int *)(param_1 + 0x9c));

      pfVar1 = (float *)(param_1 + 0x78);

      (**(code **)(*(int *)(param_1 + 0x9c) + 4))(pfVar1,&local_98);

      *pfVar1 = -*pfVar1;

      *(float *)(param_1 + 0x7c) = -*(float *)(param_1 + 0x7c);

      *(float *)(param_1 + 0x80) = -*(float *)(param_1 + 0x80);

      *(uint *)(param_1 + 0x94) = *(uint *)(param_1 + 0x94) | 1;

    }

    if (*(int *)(param_1 + 0xa0) != 0) {

      FUN_0053bf20(&local_98,*(int *)(param_1 + 0xa0));

      (**(code **)(*(int *)(param_1 + 0xa0) + 4))(param_1 + 0x88,&local_98);

LAB_0053ca17:

      if ((*(uint *)(param_1 + 0x94) & 8) != 0) {

        *(float *)(param_1 + 0x88) = -*(float *)(param_1 + 0x88);

        *(float *)(param_1 + 0x8c) = -*(float *)(param_1 + 0x8c);

        *(float *)(param_1 + 0x90) = -*(float *)(param_1 + 0x90);

      }

      *(uint *)(param_1 + 0x94) = *(uint *)(param_1 + 0x94) | 2;

    }

  }

  else if (sVar2 == 3) {

    iVar4 = FUN_0053cb50(*(undefined4 *)(param_1 + 0x14),param_2,param_3);

    local_70 = *(undefined4 *)(iVar4 + 0x10);

    local_6c = *(undefined4 *)(iVar4 + 0x20);

    local_68 = *(undefined4 *)(iVar4 + 0x30);

    if (*(int *)(param_1 + 0x10) == 0) {

      puVar5 = &DAT_00580b98;

      local_b0 = local_70;

      local_ac = local_6c;

      local_a8 = local_68;

    }

    else {

      puVar5 = &local_64;

      uVar3 = FUN_0053cb50(*(int *)(param_1 + 0x10),param_2,param_3);

      (*(code *)PTR_FUN_00580c1c)(&local_64,uVar3);

      (*(code *)PTR_FUN_00580c20)(&local_b0,&local_70,1,&local_64);

    }

    if (*(int *)(param_1 + 0x98) != 0) {

      FUN_0053bf20(&local_98,*(int *)(param_1 + 0x98));

      (**(code **)(*(int *)(param_1 + 0x98) + 4))(param_1 + 0x6c,&local_98);

      *(uint *)(param_1 + 0x94) = *(uint *)(param_1 + 0x94) | 0x10;

    }

    FUN_0053e870(&local_b0,param_1 + 0x6c,&local_b0);

    FUN_0053e960(&local_b0,&local_b0);

    uStack_a4 = puVar5[3];

    uStack_a0 = puVar5[7];

    uStack_9c = puVar5[0xb];

    FUN_0053e900(&uStack_7c,&uStack_a4,&local_b0);

    FUN_0053e960(&uStack_7c,&uStack_7c);

    FUN_0053e900(&uStack_a4,&local_b0,&uStack_7c);

    uStack_60 = uStack_7c;

    uStack_50 = uStack_78;

    uStack_5c = uStack_a4;

    uStack_4c = uStack_a0;

    uStack_40 = uStack_74;

    local_58 = local_b0;

    local_48 = local_ac;

    uStack_3c = uStack_9c;

    local_38 = local_a8;

    local_64 = 1;

    FUN_0053e140(auStack_20,&local_64);

    iVar4 = *(int *)(param_1 + 0x9c);

    if (iVar4 != 0) {

      if (*(int *)(iVar4 + 8) == 0) {

        _DAT_005808d8 = *(undefined4 *)(iVar4 + 0xc);

      }

      else {

        FUN_0053bf20(&local_98,iVar4);

        (**(code **)(*(int *)(param_1 + 0x9c) + 4))(&DAT_005808d8,&local_98);

      }

      FUN_0053f650(auStack_10,&DAT_005808cc);

      FUN_0053f9e0(param_1 + 0x78,auStack_20,auStack_10);

    }

    if (*(int *)(param_1 + 0xa0) != 0) {

      FUN_0053bf20(&local_98,*(int *)(param_1 + 0xa0));

      (**(code **)(*(int *)(param_1 + 0xa0) + 4))(param_1 + 0x88,&local_98);

      goto LAB_0053ca17;

    }

  }

  *(int *)(param_1 + 0x68) = param_2;

LAB_0053ca5a:

  return param_1 + 0x6c;

}

/* ===== FUN_0053ca70 @ 0x0053CA70 ===== */
int FUN_0053ca70(void)



{

  DAT_005f0184 = DAT_005f0184 + 1;

  if (DAT_005f0184 == 0) {

    DAT_005f0184 = 1;

    return 1;

  }

  return DAT_005f0184;

}

/* ===== FUN_0053ca90 @ 0x0053CA90 ===== */
void FUN_0053ca90(undefined4 *param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5)



{

  undefined4 *puVar1;

  undefined4 *puVar2;

  undefined4 *puVar3;

  undefined4 uVar4;

  int iVar5;

  undefined4 *puVar6;

  undefined4 local_cc [17];

  undefined4 local_88 [17];

  undefined4 local_44 [17];

  

  uVar4 = FUN_0053c660(param_3,param_4,param_5);

  FUN_0053dfd0(local_cc,uVar4);

  puVar3 = local_cc;

  puVar6 = local_88;

  puVar2 = local_44;

  for (iVar5 = *(int *)(param_3 + 0x10);

      (puVar1 = puVar6, puVar6 = puVar3, iVar5 != 0 && (iVar5 != param_2));

      iVar5 = *(int *)(iVar5 + 0x10)) {

    uVar4 = FUN_0053c660(iVar5,param_4,param_5);

    FUN_0053dfd0(puVar1,uVar4);

    (*(code *)PTR_FUN_00580c18)(puVar2,puVar1,puVar6);

    puVar3 = puVar2;

    puVar2 = puVar1;

  }

  for (iVar5 = 0x11; iVar5 != 0; iVar5 = iVar5 + -1) {

    *param_1 = *puVar6;

    puVar6 = puVar6 + 1;

    param_1 = param_1 + 1;

  }

  return;

}

/* ===== FUN_0053cb50 @ 0x0053CB50 ===== */
/* PS2 candidate: _initterm_cand (conf 0.5) */



int FUN_0053cb50(int param_1,undefined4 param_2,int param_3)



{

  undefined1 *puVar1;

  int iVar2;

  int *piVar3;

  undefined1 local_f0 [44];

  undefined1 local_c4 [68];

  int local_80 [32];

  

  piVar3 = local_80;

  if (param_1 != 0) {

    do {

      if (*(int *)(param_1 + 0x20) == param_3) break;

      *(int *)(param_1 + 0x20) = param_3;

      *piVar3 = param_1;

      param_1 = *(int *)(param_1 + 0x10);

      piVar3 = piVar3 + 1;

    } while (param_1 != 0);

    iVar2 = param_1;

    if (piVar3 != local_80) {

      do {

        piVar3 = piVar3 + -1;

        param_1 = *piVar3;

        puVar1 = (undefined1 *)FUN_0053c660(param_1,param_2,param_3);

        if (*(code **)(param_1 + 0x18) != (code *)0x0) {

          (**(code **)(param_1 + 0x18))(local_f0,puVar1,param_1,iVar2);

          puVar1 = local_f0;

        }

        if (iVar2 == 0) {

          FUN_0053dfd0(param_1 + 0x24,puVar1);

        }

        else {

          FUN_0053dfd0(local_c4,puVar1);

          (*(code *)PTR_FUN_00580c18)(param_1 + 0x24,iVar2 + 0x24,local_c4);

        }

        iVar2 = param_1;

      } while (piVar3 != local_80);

    }

    if (param_1 != 0) {

      return param_1 + 0x24;

    }

  }

  return 0;

}

/* ===== FUN_0053cc20 @ 0x0053CC20 ===== */
int FUN_0053cc20(int param_1,int param_2,int param_3)



{

  int iVar1;

  int *piVar2;

  undefined1 *puVar3;

  undefined1 *puVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  int *piVar9;

  int *local_3d4;

  undefined1 auStack_3c8 [44];

  undefined1 local_39c [44];

  undefined1 auStack_370 [44];

  undefined1 auStack_344 [68];

  int local_300 [96];

  int local_180 [96];

  

  local_3d4 = local_180;

  piVar9 = local_300;

  while (iVar1 = 0, iVar5 = param_1, iVar7 = param_2, *(int *)(param_1 + 0x14) == 0) {

    do {

      iVar8 = iVar7 + -1;

      iVar6 = iVar5;

      if (iVar7 == 0) break;

      if (*(int *)(iVar5 + 0xc) != 0) {

        if ((*(byte *)(*(int *)(iVar5 + 0xc) + 8) & 0x3f) != 0) {

          iVar6 = iVar5 + 0x1c;

          iVar1 = iVar5;

          break;

        }

        if (iVar1 == 0) {

          iVar1 = iVar5;

        }

      }

      piVar2 = (int *)(iVar5 + 0x30);

      iVar6 = iVar5 + 0x1c;

      iVar5 = iVar6;

      iVar7 = iVar8;

    } while (*piVar2 == 0);

    if (iVar1 == 0) break;

    iVar5 = *(int *)(iVar1 + 0xc);

    piVar9[1] = *(int *)(iVar1 + 0x10);

    piVar9[2] = *(int *)(iVar1 + 0x18);

    iVar7 = *(int *)(iVar5 + 0x20);

    *piVar9 = iVar5;

    if (iVar7 == param_3) goto LAB_0053cd8a;

    *(int *)(iVar5 + 0x20) = param_3;

    if (((*(float *)(iVar1 + 0x18) == 0.0) || (iVar8 < 0)) || (iVar1 = 0, iVar8 == 0)) {

LAB_0053cd3b:

      *local_3d4 = 0;

    }

    else {

      do {

        iVar8 = iVar8 + -1;

        iVar5 = iVar1;

        if ((*(int *)(iVar6 + 0x14) != 0) && (*(int *)(iVar6 + 0xc) != 0)) {

          iVar5 = iVar6;

          if ((*(byte *)(*(int *)(iVar6 + 0xc) + 8) & 0x3f) != 0) break;

          iVar5 = iVar1;

          if (iVar1 == 0) {

            iVar5 = iVar6;

          }

        }

        iVar6 = iVar6 + 0x1c;

        iVar1 = iVar5;

      } while (iVar8 != 0);

      if (iVar5 == 0) goto LAB_0053cd3b;

      *local_3d4 = *(int *)(iVar5 + 0xc);

      iVar1 = *(int *)(iVar5 + 0x18);

      piVar9[0x61] = *(int *)(iVar5 + 0x10);

      piVar9[0x62] = iVar1;

    }

    piVar9 = piVar9 + 3;

    local_3d4 = local_3d4 + 3;

    if (param_2 != 0) {

      piVar2 = (int *)(param_1 + 0xc);

      iVar1 = param_2;

      do {

        if (*piVar2 != 0) {

          *piVar2 = *(int *)(*piVar2 + 0x10);

        }

        piVar2 = piVar2 + 7;

        iVar1 = iVar1 + -1;

      } while (iVar1 != 0);

    }

  }

  *piVar9 = 0;

LAB_0053cd8a:

  if (piVar9 != local_300) {

    iVar1 = *piVar9;

    piVar2 = piVar9;

    do {

      piVar9 = piVar2 + -3;

      iVar5 = *piVar9;

      puVar3 = (undefined1 *)FUN_0053c660(iVar5,piVar2[-2],param_3);

      if (*(code **)(iVar5 + 0x18) != (code *)0x0) {

        (**(code **)(iVar5 + 0x18))(local_39c,puVar3,iVar5,iVar1);

        puVar3 = local_39c;

      }

      if (((float)piVar2[-1] != 0.0) && (iVar7 = local_3d4[-3], iVar7 != 0)) {

        puVar4 = (undefined1 *)FUN_0053c660(iVar7,local_3d4[-2],param_3);

        if (*(code **)(iVar7 + 0x18) != (code *)0x0) {

          (**(code **)(iVar7 + 0x18))(auStack_3c8,puVar4,iVar7,iVar1);

          puVar4 = auStack_3c8;

        }

        FUN_0053e090(auStack_370,puVar3,puVar4,piVar2[-1]);

        puVar3 = auStack_370;

      }

      if (iVar1 == 0) {

        FUN_0053dfd0(iVar5 + 0x24,puVar3);

      }

      else {

        FUN_0053dfd0(auStack_344,puVar3);

        (*(code *)PTR_FUN_00580c18)(iVar5 + 0x24,iVar1 + 0x24,auStack_344);

      }

      iVar1 = iVar5;

      piVar2 = piVar9;

      local_3d4 = local_3d4 + -3;

    } while (piVar9 != local_300);

  }

  if (*piVar9 == 0) {

    return 0;

  }

  return *piVar9 + 0x24;

}

/* ===== FUN_0053cec0 @ 0x0053CEC0 ===== */
undefined4 * FUN_0053cec0(int param_1,int param_2,int *param_3)



{

  int iVar1;

  int iVar2;

  undefined4 *puVar3;

  undefined4 uVar4;

  undefined4 uVar5;

  int *piVar6;

  int *piVar7;

  undefined4 local_8;

  int iStack_4;

  

  iVar1 = (int)param_3;

  local_8 = *(undefined4 *)(param_1 + 0x24);

  if (param_2 != 0) {

    iVar2 = FUN_005404c0(*(undefined4 *)(param_1 + 0x20),param_2);

    if (iVar2 == 0) {

      FUN_00540310(s_Can_t_find_tree___s__in_ANM___s__00580b48,param_2,param_1 + 0x4c);

    }

    else {

      puVar3 = (undefined4 *)FUN_005404a0(iVar2);

      local_8 = *puVar3;

    }

  }

  if (*(int *)((int)param_3 + 0x10) != 0) {

    puVar3 = (undefined4 *)(*(code *)PTR_FUN_00580c88)(*(int *)((int)param_3 + 0x10) * 8 + 0xc);

    iStack_4 = 0;

    *puVar3 = local_8;

    puVar3[1] = param_3;

    puVar3[2] = 0;

    piVar7 = puVar3 + 3;

    if (0 < *(int *)((int)param_3 + 0x10)) {

      param_3 = (int *)((int)param_3 + 0x14);

      do {

        iVar2 = *param_3;

        *piVar7 = iVar2;

        uVar4 = FUN_00540500(*(undefined4 *)(*(int *)(iVar1 + 4) + 0x10),

                             CONCAT22((short)((uint)iVar2 >> 0x10),*(undefined2 *)(iVar2 + 8)));

        uVar5 = FUN_005404b0(uVar4);

        iVar2 = FUN_005404c0(local_8,uVar5);

        if (iVar2 == 0) {

          piVar7[1] = 0;

          if (param_2 == 0) {

            uVar4 = FUN_005404b0(uVar4,param_1 + 0x4c);

            FUN_00540310(s_Error_binding___The_SKN___s__ref_00580a70,*(int *)(iVar1 + 4) + 0x28,

                         uVar4);

          }

          else {

            uVar4 = FUN_005404b0(uVar4,param_1 + 0x4c,param_2);

            FUN_00540310(s_Error_binding___The_SKN___s__ref_00580ae0,*(int *)(iVar1 + 4) + 0x28,

                         uVar4);

          }

        }

        else {

          piVar6 = (int *)FUN_005404a0(iVar2);

          piVar7[1] = *piVar6;

        }

        piVar7 = piVar7 + 2;

        puVar3[2] = puVar3[2] + 1;

        iStack_4 = iStack_4 + 1;

        param_3 = param_3 + 1;

      } while (iStack_4 < *(int *)(iVar1 + 0x10));

    }

    return puVar3;

  }

  return (undefined4 *)0x0;

}

/* ===== FUN_0053d050 @ 0x0053D050 ===== */
void FUN_0053d050(int param_1,int param_2,int param_3)



{

  undefined4 *puVar1;

  int *piVar2;

  int iVar3;

  

  piVar2 = *(int **)(param_1 + 8);

  if (piVar2 != (int *)0x0) {

    for (iVar3 = *piVar2; iVar3 != 0; iVar3 = iVar3 + -1) {

      piVar2 = piVar2 + 1;

      puVar1 = (undefined4 *)(*piVar2 * param_3 + param_2);

      *puVar1 = DAT_005f0188;

      puVar1[1] = DAT_005f018c;

      puVar1[2] = DAT_005f0190;

    }

  }

  return;

}

/* ===== FUN_0053d0a0 @ 0x0053D0A0 ===== */
void FUN_0053d0a0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,

                 undefined4 param_5,undefined4 param_6)



{

  undefined4 uVar1;

  int iVar2;

  undefined4 *puVar3;

  

  if (*(int *)(*(int *)(param_1 + 4) + 8) != 0) {

    FUN_0053d050(*(int *)(param_1 + 4),param_3,param_4);

  }

  puVar3 = (undefined4 *)(param_1 + 0xc);

  for (iVar2 = *(int *)(param_1 + 8); iVar2 != 0; iVar2 = iVar2 + -1) {

    if (puVar3[1] != 0) {

      uVar1 = FUN_0053cb50(puVar3[1],param_2,param_6);

      (*(code *)PTR_FUN_0058096c)(*puVar3,uVar1,param_3,param_4,param_5);

    }

    puVar3 = puVar3 + 2;

  }

  return;

}

/* ===== FUN_0053d120 @ 0x0053D120 ===== */
void FUN_0053d120(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,

                 undefined4 param_6)



{

  int iVar1;

  int iVar2;

  undefined4 *puVar3;

  undefined4 uVar4;

  int iVar5;

  int iVar6;

  

  iVar2 = param_1;

  iVar1 = *(int *)(param_1 + 8);

  if (*(int *)(*(int *)(iVar1 + 4) + 8) != 0) {

    FUN_0053d050(*(int *)(iVar1 + 4),param_3,param_4);

  }

  param_1 = *(int *)(iVar1 + 8);

  if (param_1 != 0) {

    iVar6 = param_1 * 8 + 0x10;

    do {

      if (param_2 != 0) {

        puVar3 = (undefined4 *)(iVar2 + 0xc);

        iVar5 = param_2;

        do {

          iVar5 = iVar5 + -1;

          *puVar3 = *(undefined4 *)(iVar6 + -8 + puVar3[-1]);

          puVar3 = puVar3 + 7;

        } while (iVar5 != 0);

      }

      uVar4 = FUN_0053cc20(iVar2,param_2,param_6);

      (*(code *)PTR_FUN_0058096c)

                (*(undefined4 *)(iVar6 + -0xc + iVar1),uVar4,param_3,param_4,param_5);

      param_1 = param_1 + -1;

      iVar6 = iVar6 + -8;

    } while (param_1 != 0);

  }

  return;

}

/* ===== FUN_0053d1c0 @ 0x0053D1C0 ===== */
int FUN_0053d1c0(int param_1,undefined4 param_2,int param_3,undefined4 param_4)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int *piVar4;

  

  if ((param_1 == 0) || (param_3 == 0)) {

    __rt_error_box(s_Anim____Skin_00580b6c,s_C__Giants_LIBS_anm_anm_cpp_00580b7c,0x9f1);

  }

  iVar3 = 0;

  iVar1 = FUN_00540490(*(undefined4 *)(param_3 + 0x18));

  if (iVar1 != 0) {

    iVar3 = (*(code *)PTR_FUN_00580c88)(iVar1 * 4 + 0x18);

    *(int *)(iVar3 + 8) = param_1;

    *(int *)(iVar3 + 0xc) = param_3;

    *(undefined4 *)(iVar3 + 0x10) = 0;

    piVar4 = (int *)(iVar3 + 0x18);

    iVar2 = FUN_0053bda0(param_3,0,0);

    iVar1 = 1;

    while (iVar2 != 0) {

      iVar2 = FUN_0053cec0(param_1,param_2,iVar2,param_4);

      *piVar4 = iVar2;

      if (iVar2 != 0) {

        piVar4 = piVar4 + 1;

        *(int *)(iVar3 + 0x10) = *(int *)(iVar3 + 0x10) + *(int *)(*(int *)(iVar2 + 4) + 0xc);

      }

      iVar2 = FUN_0053bda0(param_3,0,iVar1);

      iVar1 = iVar1 + 1;

    }

    *(int *)(iVar3 + 0x14) = (int)piVar4 + (-0x18 - iVar3) >> 2;

    *(undefined4 *)(iVar3 + 4) = **(undefined4 **)(iVar3 + 0x18);

  }

  return iVar3;

}

/* ===== FUN_0053d2a0 @ 0x0053D2A0 ===== */
void FUN_0053d2a0(int param_1)



{

  undefined4 uVar1;

  undefined4 *puVar2;

  int iVar3;

  

  puVar2 = (undefined4 *)(param_1 + 0x18);

  for (iVar3 = *(int *)(param_1 + 0x14); iVar3 != 0; iVar3 = iVar3 + -1) {

    uVar1 = *puVar2;

    puVar2 = puVar2 + 1;

    thunk_FUN_0053fc50(uVar1);

  }

  (*(code *)PTR_FUN_00580c90)(param_1);

  return;

}

/* ===== FUN_0053d2d0 @ 0x0053D2D0 ===== */
void FUN_0053d2d0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,

                 undefined4 param_5)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int *piVar4;

  

  iVar3 = 0;

  piVar4 = (int *)(param_1 + 0x18);

  for (iVar2 = *(int *)(param_1 + 0x14); iVar2 != 0; iVar2 = iVar2 + -1) {

    FUN_0053d0a0(*piVar4,param_2,param_3,param_4,iVar3,param_5);

    iVar1 = *piVar4;

    piVar4 = piVar4 + 1;

    iVar3 = iVar3 + *(int *)(*(int *)(iVar1 + 4) + 0xc);

  }

  return;

}

/* ===== FUN_0053d330 @ 0x0053D330 ===== */
void FUN_0053d330(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)



{

  int *piVar1;

  int iVar2;

  undefined4 *puVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  

  iVar2 = param_1;

  iVar6 = 0;

  param_1 = *(int *)(*(int *)(param_1 + 4) + 0x14);

  if (0 < param_1) {

    iVar5 = 0x18;

    do {

      if (param_2 != 0) {

        puVar3 = (undefined4 *)(iVar2 + 8 + param_2 * 0x1c);

        iVar4 = param_2;

        do {

          piVar1 = puVar3 + -8;

          puVar3 = puVar3 + -7;

          iVar4 = iVar4 + -1;

          *puVar3 = *(undefined4 *)(iVar5 + *piVar1);

        } while (iVar4 != 0);

      }

      FUN_0053d120(iVar2,param_2,param_3,param_4,iVar6,param_5);

      piVar1 = (int *)(*(int *)(iVar2 + 4) + iVar5);

      iVar5 = iVar5 + 4;

      iVar6 = iVar6 + *(int *)(*(int *)(*piVar1 + 4) + 0xc);

      param_1 = param_1 + -1;

    } while (param_1 != 0);

  }

  return;

}

/* ===== FUN_0053d3b0 @ 0x0053D3B0 ===== */
byte FUN_0053d3b0(int param_1,int param_2,int param_3,int param_4,undefined4 param_5)



{

  float fVar1;

  int iVar2;

  undefined4 uVar3;

  undefined4 *puVar4;

  undefined4 *puVar5;

  undefined4 uVar6;

  int *piVar7;

  byte bVar8;

  int iVar9;

  int *piVar10;

  int *piVar11;

  int local_58;

  float fStack_54;

  float fStack_50;

  float fStack_4c;

  float fStack_48;

  undefined1 local_44 [68];

  

  bVar8 = 1;

  do {

    if (param_4 == 0) {

      return bVar8;

    }

    param_4 = param_4 + -1;

    if (*(int *)(param_3 + 0x1c) == 0) {

      local_58 = 1;

      iVar2 = FUN_005404e0(*(undefined4 *)(*(int *)(param_1 + 4) + 4),0);

      while (iVar2 != 0) {

        uVar3 = FUN_005404b0(iVar2);

        puVar4 = (undefined4 *)FUN_005404a0(iVar2);

        iVar9 = param_2 + -1;

        *(undefined4 *)(param_1 + 0xc) = *puVar4;

        if (iVar9 != 0) {

          puVar4 = (undefined4 *)(param_1 + 0x28);

          do {

            iVar2 = FUN_005404c0(*(undefined4 *)(puVar4[-2] + 4),uVar3);

            if (iVar2 == 0) goto LAB_0053d503;

            puVar5 = (undefined4 *)FUN_005404a0(iVar2);

            *puVar4 = *puVar5;

            puVar4 = puVar4 + 7;

            iVar9 = iVar9 + -1;

          } while (iVar9 != 0);

        }

        if (iVar2 != 0) {

          uVar6 = FUN_0053cc20(param_1,param_2,param_5);

          (*(code *)PTR_FUN_00580c1c)(local_44,uVar6);

          (*(code *)PTR_FUN_00580c20)(&fStack_50,param_3,1,local_44);

          fVar1 = fStack_48 * fStack_48 + fStack_4c * fStack_4c + fStack_50 * fStack_50;

          if ((*(int *)(param_3 + 0x1c) == 0) || (fVar1 < fStack_54)) {

            *(undefined4 *)(param_3 + 0x1c) = uVar3;

            *(float *)(param_3 + 0xc) = fStack_50;

            *(float *)(param_3 + 0x10) = fStack_4c;

            *(float *)(param_3 + 0x14) = fStack_48;

            fStack_54 = fVar1;

          }

        }

LAB_0053d503:

        iVar2 = FUN_005404e0(*(undefined4 *)(*(int *)(param_1 + 4) + 4),local_58);

        local_58 = local_58 + 1;

      }

    }

    piVar10 = *(int **)(param_3 + 0x20);

    if (param_2 != 0) {

      piVar11 = (int *)(param_1 + 4);

      iVar2 = param_2;

      do {

        iVar2 = iVar2 + -1;

        if ((*piVar10 == 0) || (*(int *)(*piVar10 + 0xc) != *(int *)(*piVar11 + 8))) {

          iVar9 = FUN_005404c0(*(undefined4 *)(*piVar11 + 4),*(undefined4 *)(param_3 + 0x1c));

          bVar8 = bVar8 & iVar9 != 0;

          if (bVar8 == 0) {

            return 0;

          }

          piVar7 = (int *)FUN_005404a0(iVar9);

          *piVar10 = *piVar7;

        }

        iVar9 = *piVar10;

        piVar10 = piVar10 + 1;

        piVar11[2] = iVar9;

        piVar11 = piVar11 + 7;

      } while (iVar2 != 0);

    }

    uVar3 = FUN_0053cc20(param_1,param_2,param_5);

    (*(code *)PTR_FUN_00580c20)(param_3,param_3 + 0xc,1,uVar3);

  } while( true );

}

/* ===== FUN_0053d5e0 @ 0x0053D5E0 ===== */
void FUN_0053d5e0(byte *param_1)



{

  if (param_1 != (byte *)0x0) {

    *(undefined4 *)(param_1 + 4) = *(undefined4 *)(&DAT_005808e0 + (uint)*param_1 * 0xc);

  }

  return;

}

/* ===== FUN_0053d600 @ 0x0053D600 ===== */
void FUN_0053d600(int param_1)



{

  short sVar1;

  undefined4 uVar2;

  

  if (param_1 == 0) {

    return;

  }

  sVar1 = *(short *)(param_1 + 6);

  if (sVar1 == 2) {

    FUN_0053d5e0(*(undefined4 *)(param_1 + 0x98));

    FUN_0053d5e0(*(undefined4 *)(param_1 + 0x9c));

    uVar2 = *(undefined4 *)(param_1 + 0xa0);

  }

  else {

    if (sVar1 == 1) {

      FUN_0053d5e0(*(undefined4 *)(param_1 + 0x9c));

      goto LAB_0053d67c;

    }

    if (sVar1 != 3) goto LAB_0053d67c;

    FUN_0053d5e0(*(undefined4 *)(param_1 + 0x98));

    FUN_0053d5e0(*(undefined4 *)(param_1 + 0x9c));

    uVar2 = *(undefined4 *)(param_1 + 0xa0);

  }

  FUN_0053d5e0(uVar2);

LAB_0053d67c:

  if (*(short *)(param_1 + 4) != 1) {

    return;

  }

  FUN_0053d5e0(*(undefined4 *)(param_1 + 0xf8));

  FUN_0053d5e0(*(undefined4 *)(param_1 + 0xfc));

  FUN_0053d5e0();

  return;

}

/* ===== FUN_0053d6b0 @ 0x0053D6B0 ===== */
void FUN_0053d6b0(int *param_1,undefined4 param_2)



{

  int iVar1;

  int iVar2;

  uint uVar3;

  

  FUN_005400e0(param_1,param_2);

  iVar1 = *param_1;

  if ((iVar1 != 0) && (uVar3 = 0, *(int *)(iVar1 + 8) != 0)) {

    iVar2 = iVar1 + 0xc;

    do {

      FUN_005400e0(iVar2,param_2);

      uVar3 = uVar3 + 1;

      iVar2 = iVar2 + 4;

    } while (uVar3 < *(uint *)(iVar1 + 8));

  }

  return;

}

/* ===== FUN_0053d700 @ 0x0053D700 ===== */
void FUN_0053d700(undefined4 *param_1,int param_2)



{

  short sVar1;

  

  *param_1 = 0;

  FUN_005400e0(param_1 + 3,param_2);

  FUN_005400e0(param_1 + 4,param_2);

  FUN_005400e0(param_1 + 5,param_2);

  sVar1 = *(short *)((int)param_1 + 6);

  if (sVar1 == 2) {

    FUN_0053d6b0(param_1 + 0x26,param_2);

    FUN_0053d6b0(param_1 + 0x27,param_2);

  }

  else {

    if (sVar1 == 1) {

      FUN_0053d6b0(param_1 + 0x27,param_2);

      goto LAB_0053d7a7;

    }

    if (sVar1 != 3) goto LAB_0053d7a7;

    FUN_0053d6b0(param_1 + 0x26,param_2);

    FUN_0053d6b0(param_1 + 0x27,param_2);

  }

  FUN_0053d6b0(param_1 + 0x28,param_2);

LAB_0053d7a7:

  if (*(short *)(param_1 + 1) == 1) {

    FUN_0053d6b0(param_1 + 0x3e,param_2);

    FUN_0053d6b0(param_1 + 0x3f,param_2);

    FUN_0053d6b0(param_1 + 0x40,param_2);

  }

  if (*(int *)(param_2 + 4) != 0) {

    param_1[0x1e] = -(float)param_1[0x1e];

    param_1[0x1f] = -(float)param_1[0x1f];

    param_1[0x20] = -(float)param_1[0x20];

  }

  FUN_0053d600(param_1);

  return;

}

/* ===== FUN_0053d810 @ 0x0053D810 ===== */
void FUN_0053d810(int param_1,int param_2)



{

  undefined4 *puVar1;

  undefined4 uVar2;

  undefined4 uVar3;

  int iVar4;

  undefined4 *puVar5;

  int iVar6;

  

  uVar3 = param_2;

  FUN_005400e0(param_1 + 0xc,param_2);

  puVar1 = (undefined4 *)(param_1 + 0x20);

  FUN_005400e0(puVar1,param_2);

  FUN_005400e0(param_1 + 0x24,param_2);

  FUN_00540530(*puVar1,&LAB_00540520,param_2);

  param_2 = 1;

  iVar4 = FUN_005404e0(*puVar1,0);

  while (iVar4 != 0) {

    puVar5 = (undefined4 *)FUN_005404a0(iVar4);

    uVar2 = *puVar5;

    FUN_00540530(uVar2,&LAB_00540520,uVar3);

    iVar6 = FUN_005404e0(uVar2,0);

    iVar4 = 1;

    while (iVar6 != 0) {

      puVar5 = (undefined4 *)FUN_005404a0(iVar6);

      FUN_0053d700(*puVar5,uVar3);

      iVar6 = FUN_005404e0(uVar2,iVar4);

      iVar4 = iVar4 + 1;

    }

    iVar4 = FUN_005404e0(*puVar1,param_2);

    param_2 = param_2 + 1;

  }

  return;

}

/* ===== FUN_0053d8d0 @ 0x0053D8D0 ===== */
byte * FUN_0053d8d0(undefined4 param_1,int param_2,byte param_3)



{

  int iVar1;

  byte *pbVar2;

  byte *pbVar3;

  byte *pbVar4;

  

  iVar1 = *(int *)(&DAT_005808e4 + (uint)param_3 * 0xc);

  pbVar2 = (byte *)FUN_0053ffa0(param_1,(iVar1 + 4) * param_2 + 0xc,1);

  pbVar2[2] = 3;

  pbVar2[1] = 3;

  pbVar2[3] = 3;

  pbVar3 = pbVar2 + 0xc;

  *pbVar2 = param_3;

  *(int *)(pbVar2 + 8) = param_2;

  pbVar4 = pbVar3 + param_2 * 4;

  for (; param_2 != 0; param_2 = param_2 + -1) {

    *(byte **)pbVar3 = pbVar4;

    pbVar3 = pbVar3 + 4;

    pbVar4 = pbVar4 + iVar1;

  }

  FUN_0053d5e0(pbVar2);

  return pbVar2;

}

/* ===== FUN_0053d940 @ 0x0053D940 ===== */
void FUN_0053d940(int param_1,undefined4 param_2,undefined4 param_3)



{

  if (*(int *)(param_1 + 8) != 0) {

    FUN_0053bf20(param_2,param_1);

    (**(code **)(param_1 + 4))(param_3,param_2);

  }

  return;

}

/* ===== FUN_0053d970 @ 0x0053D970 ===== */
void FUN_0053d970(uint *param_1,uint *param_2)



{

  uint uVar1;

  uint *puVar2;

  uint *puVar3;

  int iVar4;

  uint *puVar5;

  int iVar6;

  uint *puVar7;

  uint local_44 [17];

  

  puVar7 = param_1;

  if (param_1 == param_2) {

    puVar7 = local_44;

  }

  puVar2 = param_2 + 1;

  iVar6 = 4;

  puVar5 = puVar7;

  do {

    puVar5 = puVar5 + 1;

    iVar4 = 4;

    puVar3 = puVar5;

    do {

      uVar1 = *puVar2;

      puVar2 = puVar2 + 1;

      *puVar3 = uVar1;

      puVar3 = puVar3 + 4;

      iVar4 = iVar4 + -1;

    } while (iVar4 != 0);

    iVar6 = iVar6 + -1;

  } while (iVar6 != 0);

  uVar1 = *param_2;

  *puVar7 = uVar1 >> 1 & 0x10 | (uVar1 & 0x10) * 2 | uVar1 & 0xffffffcf;

  if (param_1 != puVar7) {

    for (iVar6 = 0x11; iVar6 != 0; iVar6 = iVar6 + -1) {

      *param_1 = *puVar7;

      puVar7 = puVar7 + 1;

      param_1 = param_1 + 1;

    }

  }

  return;

}

/* ===== FUN_0053d9e0 @ 0x0053D9E0 ===== */
/* PS2 candidate: GEO_MatIdentity (conf 0.368) */



void FUN_0053d9e0(undefined4 *param_1)



{

  int iVar1;

  undefined4 *puVar2;

  

  puVar2 = &DAT_00580b98;

  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {

    *param_1 = *puVar2;

    puVar2 = puVar2 + 1;

    param_1 = param_1 + 1;

  }

  return;

}

/* ===== FUN_0053da00 @ 0x0053DA00 ===== */
void FUN_0053da00(float *param_1,float *param_2,float *param_3)



{

  uint uVar1;

  float *pfVar2;

  float *pfVar3;

  float fVar4;

  float *pfVar5;

  float *pfVar6;

  int iVar7;

  int iVar8;

  float *pfVar9;

  int local_48;

  float local_44 [17];

  

  if ((param_1 == param_2) || (pfVar9 = param_1, param_1 == param_3)) {

    pfVar9 = local_44;

  }

  if ((((uint)*param_2 & 0x20) == 0) && (((uint)*param_3 & 0x20) == 0)) {

    uVar1 = (uint)*param_2 & 0xf;

    if ((uVar1 == 0) || (((uint)*param_3 & 0xf) == 0)) {

      pfVar5 = param_2;

      if (uVar1 == 0) {

        pfVar5 = param_3;

      }

      iVar7 = 0xc;

      pfVar3 = pfVar9;

      do {

        pfVar3 = pfVar3 + 1;

        *pfVar3 = *(float *)(((int)pfVar5 - (int)pfVar9) + (int)pfVar3);

        iVar7 = iVar7 + -1;

      } while (iVar7 != 0);

    }

    else {

      pfVar5 = pfVar9 + 1;

      pfVar3 = param_2 + 2;

      local_48 = 3;

      do {

        iVar7 = 3;

        pfVar2 = param_3 + 5;

        pfVar6 = pfVar5;

        do {

          iVar7 = iVar7 + -1;

          *pfVar6 = *pfVar2 * *pfVar3 + pfVar2[4] * pfVar3[1] + pfVar2[-4] * pfVar3[-1];

          pfVar2 = pfVar2 + 1;

          pfVar6 = pfVar6 + 1;

        } while (iVar7 != 0);

        pfVar3 = pfVar3 + 4;

        pfVar5 = pfVar5 + 4;

        local_48 = local_48 + -1;

      } while (local_48 != 0);

    }

    if (((uint)*param_3 & 0x10) == 0) {

      pfVar9[4] = param_2[4];

      pfVar9[8] = param_2[8];

      pfVar9[0xc] = param_2[0xc];

    }

    else {

      iVar7 = 3;

      pfVar3 = param_2 + 2;

      pfVar5 = pfVar9;

      do {

        pfVar5 = pfVar5 + 4;

        iVar7 = iVar7 + -1;

        *pfVar5 = param_3[8] * *pfVar3 + pfVar3[-1] * param_3[4] + pfVar3[1] * param_3[0xc] +

                  pfVar3[2];

        pfVar3 = pfVar3 + 4;

      } while (iVar7 != 0);

    }

    pfVar9[0xf] = 0.0;

    pfVar9[0xe] = 0.0;

    pfVar9[0xd] = 0.0;

    pfVar9[0x10] = 1.0;

  }

  else {

    pfVar5 = pfVar9 + 1;

    pfVar3 = param_2 + 3;

    iVar7 = 4;

    do {

      iVar8 = 4;

      pfVar2 = param_3 + 9;

      pfVar6 = pfVar5;

      do {

        pfVar5 = pfVar6 + 1;

        iVar8 = iVar8 + -1;

        *pfVar6 = *pfVar2 * *pfVar3 +

                  pfVar2[4] * pfVar3[1] + pfVar2[-4] * pfVar3[-1] + pfVar2[-8] * pfVar3[-2];

        pfVar2 = pfVar2 + 1;

        pfVar6 = pfVar5;

      } while (iVar8 != 0);

      pfVar3 = pfVar3 + 4;

      iVar7 = iVar7 + -1;

    } while (iVar7 != 0);

  }

  uVar1 = (uint)*param_3 | (uint)*param_2;

  fVar4 = (float)((uVar1 ^ (uint)*param_3 ^ (uint)*param_2) & 8 ^ uVar1);

  *pfVar9 = fVar4;

  if ((((uint)*param_2 & 2) != 0) && (((uint)*param_3 & 1) != 0)) {

    *pfVar9 = (float)(CONCAT31((int3)(uVar1 >> 8),SUB41(fVar4,0)) | 4);

  }

  if (param_1 != pfVar9) {

    for (iVar7 = 0x11; iVar7 != 0; iVar7 = iVar7 + -1) {

      *param_1 = *pfVar9;

      pfVar9 = pfVar9 + 1;

      param_1 = param_1 + 1;

    }

  }

  return;

}

/* ===== FUN_0053dbb0 @ 0x0053DBB0 ===== */
void FUN_0053dbb0(uint *param_1,uint *param_2,uint *param_3)



{

  int iVar1;

  uint *puVar2;

  uint *puVar3;

  

  puVar2 = param_3;

  puVar3 = param_2;

  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar3 = *puVar2;

    puVar2 = puVar2 + 1;

    puVar3 = puVar3 + 1;

  }

  puVar2 = param_1;

  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar2 = *param_3;

    param_3 = param_3 + 1;

    puVar2 = puVar2 + 1;

  }

  param_2[0xc] = 0;

  param_2[8] = 0;

  param_2[4] = 0;

  *param_2 = *param_2 & 0xffffffef;

  param_1[10] = 0;

  param_1[9] = 0;

  param_1[7] = 0;

  param_1[5] = 0;

  param_1[3] = 0;

  param_1[2] = 0;

  param_1[0xb] = 0x3f800000;

  param_1[6] = 0x3f800000;

  param_1[1] = 0x3f800000;

  *param_1 = *param_1 & 0x10;

  return;

}

/* ===== FUN_0053dc10 @ 0x0053DC10 ===== */
/* PS2 candidate: GEO_MatTranslation (conf 0.316) */



void FUN_0053dc10(undefined4 *param_1,undefined4 *param_2)



{

  int iVar1;

  undefined4 *puVar2;

  undefined4 *puVar3;

  

  puVar2 = &DAT_00580b98;

  puVar3 = param_1;

  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar3 = *puVar2;

    puVar2 = puVar2 + 1;

    puVar3 = puVar3 + 1;

  }

  param_1[4] = *param_2;

  param_1[8] = param_2[1];

  param_1[0xc] = param_2[2];

  *param_1 = 0x10;

  return;

}

/* ===== FUN_0053dc50 @ 0x0053DC50 ===== */
void FUN_0053dc50(undefined4 *param_1,float param_2)



{

  int iVar1;

  undefined4 *puVar2;

  undefined4 *puVar3;

  

  puVar2 = &DAT_00580b98;

  puVar3 = param_1;

  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar3 = *puVar2;

    puVar2 = puVar2 + 1;

    puVar3 = puVar3 + 1;

  }

  param_1[0xb] = param_2;

  param_1[1] = param_2;

  param_1[6] = param_2;

  if (param_2 < 0.0) {

    *param_1 = 10;

    return;

  }

  *param_1 = 2;

  return;

}

/* ===== FUN_0053dca0 @ 0x0053DCA0 ===== */
void FUN_0053dca0(uint *param_1,float *param_2)



{

  int iVar1;

  uint *puVar2;

  uint *puVar3;

  

  puVar2 = &DAT_00580b98;

  puVar3 = param_1;

  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar3 = *puVar2;

    puVar2 = puVar2 + 1;

    puVar3 = puVar3 + 1;

  }

  param_1[1] = (uint)*param_2;

  param_1[6] = (uint)param_2[1];

  param_1[0xb] = (uint)param_2[2];

  if (param_2[2] < 0.0) {

    *param_1 = (uint)(-(param_2[1] >= 0.0 != *param_2 < 0.0) & 8U | 2);

    return;

  }

  *param_1 = (uint)(-(param_2[1] < 0.0 != *param_2 < 0.0) & 8U | 2);

  return;

}

/* ===== FUN_0053dd40 @ 0x0053DD40 ===== */
void FUN_0053dd40(undefined4 *param_1,undefined4 param_2)



{

  int iVar1;

  undefined4 *puVar2;

  undefined4 *puVar3;

  float10 fVar4;

  float10 fVar5;

  

  puVar2 = &DAT_00580b98;

  puVar3 = param_1;

  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar3 = *puVar2;

    puVar2 = puVar2 + 1;

    puVar3 = puVar3 + 1;

  }

  fVar4 = (float10)(*(code *)PTR_FUN_00580c30)(param_2);

  fVar5 = (float10)(*(code *)PTR_FUN_00580c34)(param_2);

  param_1[6] = (float)fVar5;

  param_1[7] = -(float)fVar4;

  param_1[10] = (float)fVar4;

  param_1[0xb] = (float)fVar5;

  *param_1 = 1;

  return;

}

/* ===== FUN_0053dd90 @ 0x0053DD90 ===== */
void FUN_0053dd90(undefined4 *param_1,undefined4 param_2)



{

  int iVar1;

  undefined4 *puVar2;

  undefined4 *puVar3;

  float10 fVar4;

  float10 fVar5;

  

  puVar2 = &DAT_00580b98;

  puVar3 = param_1;

  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar3 = *puVar2;

    puVar2 = puVar2 + 1;

    puVar3 = puVar3 + 1;

  }

  fVar4 = (float10)(*(code *)PTR_FUN_00580c30)(param_2);

  fVar5 = (float10)(*(code *)PTR_FUN_00580c34)(param_2);

  param_1[1] = (float)fVar5;

  param_1[2] = -(float)fVar4;

  param_1[5] = (float)fVar4;

  param_1[6] = (float)fVar5;

  *param_1 = 1;

  return;

}

/* ===== FUN_0053dde0 @ 0x0053DDE0 ===== */
/* PS2 candidate: GEO_MatLookAt (conf 0.364) */



void FUN_0053dde0(undefined4 *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)



{

  undefined4 local_24;

  undefined4 local_20;

  undefined4 local_1c;

  undefined4 local_18;

  undefined4 local_14;

  undefined4 local_10;

  undefined4 local_c;

  undefined4 local_8;

  undefined4 local_4;

  

  FUN_0053e960(&local_18,param_3);

  FUN_0053e900(&local_24,param_4,param_3);

  FUN_0053e960(&local_24,&local_24);

  FUN_0053e900(&local_c,&local_18,&local_24);

  param_1[9] = local_1c;

  param_1[5] = local_20;

  param_1[6] = local_8;

  param_1[1] = local_24;

  param_1[2] = local_c;

  param_1[3] = local_18;

  param_1[10] = local_4;

  param_1[0xb] = local_10;

  param_1[7] = local_14;

  param_1[4] = *param_2;

  param_1[8] = param_2[1];

  param_1[0xc] = param_2[2];

  param_1[0xf] = 0;

  param_1[0xe] = 0;

  param_1[0xd] = 0;

  param_1[0x10] = 0x3f800000;

  *param_1 = 0x11;

  return;

}

/* ===== FUN_0053deb0 @ 0x0053DEB0 ===== */
void FUN_0053deb0(undefined4 *param_1,float *param_2)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  

  fVar1 = *param_2;

  fVar2 = param_2[1];

  fVar3 = param_2[3];

  fVar4 = param_2[2];

  fVar7 = fVar2 + fVar2;

  param_1[0xc] = 0;

  param_1[8] = 0;

  param_1[4] = 0;

  param_1[0xf] = 0;

  fVar8 = fVar4 + fVar4;

  param_1[0xe] = 0;

  param_1[0xd] = 0;

  param_1[0x10] = 0x3f800000;

  fVar6 = (fVar1 + fVar1) * fVar3;

  fVar5 = (fVar1 + fVar1) * fVar1;

  param_1[1] = 1.0 - (fVar7 * fVar2 + fVar8 * fVar4);

  param_1[2] = fVar7 * fVar1 - fVar8 * fVar3;

  param_1[3] = fVar8 * fVar1 + fVar7 * fVar3;

  param_1[5] = fVar7 * fVar1 + fVar8 * fVar3;

  param_1[6] = 1.0 - (fVar8 * fVar4 + fVar5);

  param_1[7] = fVar8 * fVar2 - fVar6;

  param_1[9] = fVar8 * fVar1 - fVar7 * fVar3;

  param_1[10] = fVar8 * fVar2 + fVar6;

  param_1[0xb] = 1.0 - (fVar7 * fVar2 + fVar5);

  *param_1 = 1;

  return;

}

/* ===== FUN_0053dfd0 @ 0x0053DFD0 ===== */
void FUN_0053dfd0(undefined4 *param_1,undefined4 *param_2)



{

  float *pfVar1;

  float *pfVar2;

  undefined4 *extraout_EDX;

  undefined4 *puVar3;

  int iVar4;

  undefined4 *puVar5;

  

  if ((*(byte *)(param_2 + 10) & 1) == 0) {

    puVar3 = &DAT_00580b98;

    puVar5 = param_1;

    for (iVar4 = 0x11; iVar4 != 0; iVar4 = iVar4 + -1) {

      *puVar5 = *puVar3;

      puVar3 = puVar3 + 1;

      puVar5 = puVar5 + 1;

    }

  }

  else {

    FUN_0053deb0(param_1,param_2 + 3);

    param_2 = extraout_EDX;

  }

  if ((*(byte *)(param_2 + 10) & 0x10) != 0) {

    param_1[4] = *param_2;

    param_1[8] = param_2[1];

    param_1[0xc] = param_2[2];

  }

  if ((param_2[10] & 10) == 0) {

    *param_1 = param_2[10];

    return;

  }

  iVar4 = 3;

  pfVar1 = (float *)(param_1 + 5);

  pfVar2 = (float *)(param_2 + 7);

  if ((param_2[10] & 8) == 0) {

    do {

      iVar4 = iVar4 + -1;

      pfVar1[-4] = pfVar1[-4] * *pfVar2;

      *pfVar1 = *pfVar1 * *pfVar2;

      pfVar1[4] = pfVar1[4] * *pfVar2;

      pfVar1 = pfVar1 + 1;

      pfVar2 = pfVar2 + 1;

    } while (iVar4 != 0);

    *param_1 = param_2[10];

    return;

  }

  do {

    iVar4 = iVar4 + -1;

    pfVar1[-4] = -(pfVar1[-4] * *pfVar2);

    *pfVar1 = -(*pfVar2 * *pfVar1);

    pfVar1[4] = -(*pfVar2 * pfVar1[4]);

    pfVar1 = pfVar1 + 1;

    pfVar2 = pfVar2 + 1;

  } while (iVar4 != 0);

  *param_1 = param_2[10];

  return;

}

/* ===== FUN_0053e090 @ 0x0053E090 ===== */
void FUN_0053e090(int param_1,int param_2,int param_3,float param_4)



{

  float *pfVar1;

  float *pfVar2;

  float *pfVar3;

  float *pfVar4;

  int iVar5;

  

  pfVar1 = (float *)(param_3 + 0x28);

  pfVar4 = (float *)(param_1 + 0xc);

  iVar5 = 3;

  pfVar2 = pfVar1;

  do {

    pfVar4 = pfVar4 + -1;

    pfVar3 = pfVar2 + -1;

    iVar5 = iVar5 + -1;

    *pfVar4 = param_4 * pfVar2[-8] + (1.0 - param_4) * *(float *)((param_2 - param_1) + (int)pfVar4)

    ;

    *(float *)((param_1 - param_3) + (int)pfVar3) =

         param_4 * *pfVar3 + (1.0 - param_4) * *(float *)((param_2 - param_3) + (int)pfVar3);

    pfVar2 = pfVar3;

  } while (iVar5 != 0);

  FUN_0053f6a0(param_1 + 0xc,param_2 + 0xc,param_3 + 0xc,param_4);

  if ((((uint)*pfVar1 ^ *(uint *)(param_2 + 0x28)) & 8) != 0) {

    DebugBreak();

  }

  *(uint *)(param_1 + 0x28) = (uint)*pfVar1 | *(uint *)(param_2 + 0x28);

  return;

}

/* ===== FUN_0053e140 @ 0x0053E140 ===== */
void FUN_0053e140(float *param_1,int param_2)



{

  int iVar1;

  int iVar2;

  float fVar3;

  uint uVar4;

  float10 fVar5;

  

  fVar3 = *(float *)(param_2 + 4) + *(float *)(param_2 + 0x18) + *(float *)(param_2 + 0x2c);

  if (0.0 < fVar3) {

    fVar5 = (float10)(*(code *)PTR_FUN_00580c44)(fVar3 + 1.0);

    param_1[3] = (float)((float10)0.5 * fVar5);

    fVar5 = (float10)0.5 / fVar5;

    *param_1 = (float)(((float10)*(float *)(param_2 + 0x28) - (float10)*(float *)(param_2 + 0x1c)) *

                      fVar5);

    param_1[1] = (float)(((float10)*(float *)(param_2 + 0xc) - (float10)*(float *)(param_2 + 0x24))

                        * fVar5);

    param_1[2] = (float)(((float10)*(float *)(param_2 + 0x14) - (float10)*(float *)(param_2 + 8)) *

                        fVar5);

    return;

  }

  uVar4 = (uint)(*(float *)(param_2 + 4) < *(float *)(param_2 + 0x18));

  if (*(float *)(param_2 + 4 + uVar4 * 0x14) < *(float *)(param_2 + 0x2c)) {

    uVar4 = 2;

  }

  iVar1 = *(int *)(&DAT_00580c08 + uVar4 * 4);

  iVar2 = *(int *)(&DAT_00580c08 + iVar1 * 4);

  fVar5 = (float10)(*(code *)PTR_FUN_00580c44)

                             ((*(float *)(param_2 + 4 + uVar4 * 0x14) -

                              (*(float *)(param_2 + 4 + iVar2 * 0x14) +

                              *(float *)(param_2 + 4 + iVar1 * 0x14))) + 1.0);

  param_1[uVar4] = (float)((float10)0.5 * fVar5);

  fVar5 = (float10)0.5 / fVar5;

  param_1[3] = (float)(((float10)*(float *)(param_2 + 4 + (iVar1 + iVar2 * 4) * 4) -

                       (float10)*(float *)(param_2 + 4 + (iVar2 + iVar1 * 4) * 4)) * fVar5);

  param_1[iVar1] =

       (float)(((float10)*(float *)(param_2 + 4 + (uVar4 + iVar1 * 4) * 4) +

               (float10)*(float *)(param_2 + 4 + (iVar1 + uVar4 * 4) * 4)) * fVar5);

  param_1[iVar2] =

       (float)(((float10)*(float *)(param_2 + 4 + (uVar4 + iVar2 * 4) * 4) +

               (float10)*(float *)(param_2 + 4 + (iVar2 + uVar4 * 4) * 4)) * fVar5);

  return;

}

/* ===== FUN_0053e270 @ 0x0053E270 ===== */
void FUN_0053e270(float *param_1,float *param_2,int param_3,uint *param_4,uint param_5)



{

  param_5 = *param_4 & param_5;

  if ((param_5 & 0xb) == 0) {

    if ((param_5 & 0x10) == 0) {

      for (; param_3 != 0; param_3 = param_3 + -1) {

        *param_1 = *param_2;

        param_1[1] = param_2[1];

        param_1[2] = param_2[2];

        param_2 = param_2 + 3;

        param_1 = param_1 + 3;

      }

    }

    else if (param_3 != 0) {

      do {

        param_3 = param_3 + -1;

        *param_1 = (float)param_4[4] + *param_2;

        param_1[1] = param_2[1] + (float)param_4[8];

        param_1[2] = param_2[2] + (float)param_4[0xc];

        param_2 = param_2 + 3;

        param_1 = param_1 + 3;

      } while (param_3 != 0);

      return;

    }

  }

  else if ((param_5 & 0x10) == 0) {

    if (param_3 != 0) {

      do {

        param_3 = param_3 + -1;

        *param_1 = (float)param_4[3] * param_2[2] +

                   (float)param_4[2] * param_2[1] + *param_2 * (float)param_4[1];

        param_1[1] = (float)param_4[6] * param_2[1] +

                     (float)param_4[5] * *param_2 + param_2[2] * (float)param_4[7];

        param_1[2] = (float)param_4[0xb] * param_2[2] +

                     (float)param_4[10] * param_2[1] + (float)param_4[9] * *param_2;

        param_2 = param_2 + 3;

        param_1 = param_1 + 3;

      } while (param_3 != 0);

      return;

    }

  }

  else if (param_3 != 0) {

    do {

      param_3 = param_3 + -1;

      *param_1 = (float)param_4[3] * param_2[2] +

                 (float)param_4[2] * param_2[1] + *param_2 * (float)param_4[1] + (float)param_4[4];

      param_1[1] = (float)param_4[6] * param_2[1] +

                   (float)param_4[5] * *param_2 + param_2[2] * (float)param_4[7] + (float)param_4[8]

      ;

      param_1[2] = (float)param_4[0xb] * param_2[2] +

                   (float)param_4[10] * param_2[1] + (float)param_4[9] * *param_2 +

                   (float)param_4[0xc];

      param_2 = param_2 + 3;

      param_1 = param_1 + 3;

    } while (param_3 != 0);

    return;

  }

  return;

}

/* ===== FUN_0053e3d0 @ 0x0053E3D0 ===== */
void FUN_0053e3d0(void)



{

  int iVar1;

  undefined4 *puVar2;

  undefined4 *puVar3;

  

  puVar2 = &DAT_00580b98;

  puVar3 = &DAT_005f0198;

  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar3 = *puVar2;

    puVar2 = puVar2 + 1;

    puVar3 = puVar3 + 1;

  }

  return;

}

/* ===== FUN_0053e3f0 @ 0x0053E3F0 ===== */
void FUN_0053e3f0(undefined4 *param_1)



{

  int iVar1;

  undefined4 *puVar2;

  

  puVar2 = &DAT_005f0198;

  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {

    *param_1 = *puVar2;

    puVar2 = puVar2 + 1;

    param_1 = param_1 + 1;

  }

  return;

}

/* ===== FUN_0053e410 @ 0x0053E410 ===== */
void FUN_0053e410(undefined4 param_1)



{

  (*(code *)PTR_FUN_00580c18)(&DAT_005f0198,&DAT_005f0198,param_1);

  return;

}

/* ===== FUN_0053e430 @ 0x0053E430 ===== */
void FUN_0053e430(undefined4 param_1)



{

  undefined1 local_44 [68];

  

  FUN_0053dc10(local_44,param_1);

  (*(code *)PTR_FUN_00580c18)(&DAT_005f0198,&DAT_005f0198,local_44);

  return;

}

/* ===== FUN_0053e460 @ 0x0053E460 ===== */
/* PS2 candidate: GEO_MatBuildXYZ (conf 0.444) */



void FUN_0053e460(uint *param_1,float param_2,float param_3,float param_4)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float10 fVar6;

  

  fVar6 = (float10)(*(code *)PTR_FUN_00580c30)(param_2 * 0.017453292);

  fVar1 = (float)fVar6;

  fVar6 = (float10)(*(code *)PTR_FUN_00580c34)(param_2 * 0.017453292);

  fVar2 = (float)fVar6;

  fVar6 = (float10)(*(code *)PTR_FUN_00580c30)(param_3 * 0.017453292);

  fVar3 = (float)fVar6;

  fVar6 = (float10)(*(code *)PTR_FUN_00580c34)(param_3 * 0.017453292);

  fVar4 = (float)fVar6;

  fVar6 = (float10)(*(code *)PTR_FUN_00580c30)(param_4 * 0.017453292);

  fVar5 = (float)fVar6;

  fVar6 = (float10)(*(code *)PTR_FUN_00580c34)(param_4 * 0.017453292);

  param_1[9] = (uint)fVar3;

  param_1[1] = (uint)(float)((float10)fVar4 * fVar6);

  param_1[2] = (uint)(float)(-((float10)fVar1 * (float10)fVar3 * fVar6) -

                            (float10)fVar5 * (float10)fVar2);

  param_1[3] = (uint)(float)((float10)fVar5 * (float10)fVar1 -

                            (float10)fVar3 * fVar6 * (float10)fVar2);

  param_1[5] = (uint)(fVar5 * fVar4);

  param_1[6] = (uint)(float)(fVar6 * (float10)fVar2 -

                            (float10)fVar5 * (float10)fVar3 * (float10)fVar1);

  param_1[7] = (uint)(float)(-((float10)fVar5 * (float10)fVar3 * (float10)fVar2) -

                            fVar6 * (float10)fVar1);

  param_1[10] = (uint)(fVar4 * fVar1);

  param_1[0xb] = (uint)(fVar4 * fVar2);

  *param_1 = *param_1 & 0xfffffffd | 1;

  return;

}

/* ===== FUN_0053e580 @ 0x0053E580 ===== */
void FUN_0053e580(uint *param_1,float param_2,float param_3,float param_4,float param_5)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float10 fVar6;

  

  fVar6 = (float10)(*(code *)PTR_FUN_00580c30)(param_2 * 0.017453292);

  fVar1 = (float)fVar6;

  fVar6 = (float10)(*(code *)PTR_FUN_00580c34)(param_2 * 0.017453292);

  fVar2 = (float)fVar6;

  fVar6 = (float10)(*(code *)PTR_FUN_00580c30)(param_3 * 0.017453292);

  fVar3 = (float)fVar6;

  fVar6 = (float10)(*(code *)PTR_FUN_00580c34)(param_3 * 0.017453292);

  fVar4 = (float)fVar6;

  fVar6 = (float10)(*(code *)PTR_FUN_00580c30)(param_4 * 0.017453292);

  fVar5 = (float)fVar6;

  fVar6 = (float10)(*(code *)PTR_FUN_00580c34)(param_4 * 0.017453292);

  param_1[1] = (uint)(float)((float10)fVar4 * fVar6 * (float10)param_5);

  param_1[2] = (uint)(float)((-((float10)fVar1 * (float10)fVar3 * fVar6) -

                             (float10)fVar5 * (float10)fVar2) * (float10)param_5);

  param_1[3] = (uint)(float)(((float10)fVar5 * (float10)fVar1 -

                             (float10)fVar3 * fVar6 * (float10)fVar2) * (float10)param_5);

  param_1[5] = (uint)(fVar5 * fVar4 * param_5);

  param_1[6] = (uint)(float)((fVar6 * (float10)fVar2 -

                             (float10)fVar5 * (float10)fVar3 * (float10)fVar1) * (float10)param_5);

  param_1[7] = (uint)(float)((-((float10)fVar5 * (float10)fVar3 * (float10)fVar2) -

                             fVar6 * (float10)fVar1) * (float10)param_5);

  param_1[9] = (uint)(fVar3 * param_5);

  *param_1 = *param_1 | 3;

  param_1[10] = (uint)(fVar4 * fVar1 * param_5);

  param_1[0xb] = (uint)(fVar4 * fVar2 * param_5);

  return;

}

/* ===== FUN_0053e6c0 @ 0x0053E6C0 ===== */
void FUN_0053e6c0(int param_1,float *param_2,float *param_3,float *param_4)



{

  float10 fVar1;

  float10 fVar2;

  

  fVar1 = (float10)(*(code *)PTR_FUN_00580c44)

                             (*(float *)(param_1 + 8) * *(float *)(param_1 + 8) +

                              *(float *)(param_1 + 4) * *(float *)(param_1 + 4));

  if ((float10)1e-05 < fVar1) {

    fVar2 = (float10)FUN_0053e780(*(undefined4 *)(param_1 + 0x28),*(undefined4 *)(param_1 + 0x2c));

    *param_2 = (float)fVar2;

    fVar1 = (float10)FUN_0053e780(*(undefined4 *)(param_1 + 0x24),(float)fVar1);

    *param_3 = (float)fVar1;

    fVar1 = (float10)FUN_0053e780(*(undefined4 *)(param_1 + 0x14),*(undefined4 *)(param_1 + 4));

    *param_4 = (float)fVar1;

    return;

  }

  fVar2 = (float10)FUN_0053e780(-*(float *)(param_1 + 0x1c),*(undefined4 *)(param_1 + 0x18));

  *param_2 = (float)fVar2;

  fVar1 = (float10)FUN_0053e780(*(undefined4 *)(param_1 + 0xc),(float)fVar1);

  *param_3 = (float)fVar1;

  *param_4 = 0.0;

  return;

}

/* ===== FUN_0053e780 @ 0x0053E780 ===== */
float10 FUN_0053e780(float param_1,float param_2)



{

  float10 fVar1;

  

  if ((param_2 == 0.0) && (param_1 == 0.0)) {

    return (float10)0.0;

  }

  fVar1 = (float10)(*(code *)PTR_FUN_00580c4c)(param_1,param_2);

  fVar1 = fVar1 * (float10)57.295776;

  if (fVar1 < (float10)0.0) {

    fVar1 = fVar1 + (float10)360.0;

  }

  if ((float10)359.99 < fVar1) {

    fVar1 = (float10)0.0;

  }

  return fVar1;

}

/* ===== FUN_0053e7f0 @ 0x0053E7F0 ===== */
void FUN_0053e7f0(void)



{

  uint uVar1;

  

  uVar1 = 0;

  do {

    (&DAT_00610a18)[uVar1] = (uint)SQRT((float)((uVar1 | 0x3f8000) << 8)) & 0x7fffff;

    (&DAT_005f0a18)[uVar1] = (uint)SQRT((float)((uVar1 | 0x400000) << 8)) & 0x7fffff;

    uVar1 = uVar1 + 1;

  } while (uVar1 < 0x8000);

  return;

}

/* ===== FUN_0053e870 @ 0x0053E870 ===== */
void FUN_0053e870(float *param_1,float *param_2,float *param_3)



{

  *param_1 = *param_2 - *param_3;

  param_1[1] = param_2[1] - param_3[1];

  param_1[2] = param_2[2] - param_3[2];

  return;

}

/* ===== FUN_0053e8a0 @ 0x0053E8A0 ===== */
void FUN_0053e8a0(float *param_1,float *param_2,float param_3)



{

  *param_1 = param_3 * *param_2;

  param_1[1] = param_3 * param_2[1];

  param_1[2] = param_3 * param_2[2];

  return;

}

/* ===== FUN_0053e8d0 @ 0x0053E8D0 ===== */
void FUN_0053e8d0(float *param_1)



{

  (*(code *)PTR_FUN_00580c44)

            (param_1[2] * param_1[2] + param_1[1] * param_1[1] + *param_1 * *param_1);

  return;

}

/* ===== FUN_0053e900 @ 0x0053E900 ===== */
void FUN_0053e900(float *param_1,float *param_2,float *param_3)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  

  fVar1 = *param_3;

  fVar2 = param_2[2];

  fVar3 = param_3[2];

  fVar4 = *param_2;

  fVar5 = param_3[1];

  fVar6 = *param_2;

  fVar7 = *param_3;

  fVar8 = param_2[1];

  *param_1 = param_3[2] * param_2[1] - param_3[1] * param_2[2];

  param_1[1] = fVar1 * fVar2 - fVar3 * fVar4;

  param_1[2] = fVar5 * fVar6 - fVar7 * fVar8;

  return;

}

/* ===== FUN_0053e960 @ 0x0053E960 ===== */
/* PS2 candidate: GEO_Vec3Normalize (conf 0.493) */



float10 FUN_0053e960(undefined4 param_1,undefined4 param_2)



{

  float fVar1;

  float10 fVar2;

  

  fVar2 = (float10)FUN_0053e8d0(param_2);

  fVar1 = (float)fVar2;

  if (fVar2 != (float10)0.0) {

    FUN_0053e8a0(param_1,param_2,1.0 / fVar1);

    return (float10)fVar1;

  }

  FUN_005458a9(s_Zero_length_vector_00580c70);

  return (float10)fVar1;

}

/* ===== FUN_0053e9c0 @ 0x0053E9C0 ===== */
void FUN_0053e9c0(float *param_1,float *param_2,float param_3)



{

  *param_1 = param_3 * *param_2;

  param_1[1] = param_3 * param_2[1];

  param_1[2] = param_3 * param_2[2];

  param_1[3] = param_3 * param_2[3];

  return;

}

/* ===== FUN_0053e9f0 @ 0x0053E9F0 ===== */
void FUN_0053e9f0(int param_1)



{

  int iVar1;

  

  do {

    (**(code **)(param_1 + 0x28))(param_1 + 0x10);

    iVar1 = *(int *)(param_1 + 0x20);

    *(int *)(param_1 + 0x10 + iVar1 * 4) =

         *(int *)(param_1 + 0x10 + iVar1 * 4) + *(int *)(param_1 + 0x18 + iVar1 * 4);

    iVar1 = *(int *)(param_1 + 0xc) - *(int *)(param_1 + 0x18 + *(int *)(param_1 + 0x20) * 4);

    *(int *)(param_1 + 0xc) = iVar1;

  } while (iVar1 != 0);

  return;

}

/* ===== FUN_0053ea30 @ 0x0053EA30 ===== */
void FUN_0053ea30(int *param_1,int *param_2,undefined **param_3,undefined **param_4,int *param_5)



{

  int *piVar1;

  uint uVar2;

  int iVar3;

  int *piVar4;

  int *piVar5;

  int *piVar6;

  undefined **ppuVar7;

  int iVar8;

  undefined **ppuVar9;

  undefined **ppuVar10;

  int local_44;

  int local_40;

  int iStack_34;

  int iStack_30;

  undefined4 local_2c;

  undefined4 local_28;

  uint local_24;

  int local_20;

  int local_1c;

  int local_18;

  undefined4 local_14;

  undefined4 local_10;

  undefined4 local_c;

  undefined4 local_8;

  undefined1 *local_4;

  

  local_2c = param_5;

  local_28 = 0;

  local_24 = 2;

  if (param_3 == (undefined **)0x0) {

    param_3 = &PTR_FUN_00580c50;

  }

  local_4 = (undefined1 *)param_4;

  if (param_4 == (undefined **)0x0) {

    local_4 = &LAB_00425e70;

  }

  local_c = 0;

  local_10 = 1;

  local_14 = 1;

  local_8 = 1;

  piVar4 = param_2;

  piVar5 = param_2;

  param_5 = param_2;

  iVar3 = (int)param_1;

  while (iVar3 = iVar3 + -1, iVar3 != 0) {

    piVar6 = piVar5 + 2;

    piVar1 = piVar5 + 3;

    if (*piVar1 < param_5[1]) {

      param_5 = piVar6;

    }

    piVar5 = piVar6;

    if (piVar4[1] < *piVar1) {

      piVar4 = piVar6;

    }

  }

  iVar3 = (int)param_1 * 2;

  param_4 = (undefined **)(*param_5 << 8);

  local_40 = 0;

  local_18 = param_5[1] >> 5;

  local_44 = 0;

  ppuVar7 = param_3;

  ppuVar9 = param_4;

  ppuVar10 = param_3;

  param_1 = param_5;

  do {

    if (local_44 == 0) {

      do {

        piVar5 = param_1;

        param_1 = piVar5;

        if (piVar5 == piVar4) goto LAB_0053ebb6;

        param_1 = param_2 + iVar3 + -2;

        if (piVar5 != param_2) {

          param_1 = piVar5 + -2;

        }

        ppuVar10 = (undefined **)(*piVar5 * 0x100);

        if ((int)ppuVar10 < (int)param_4) {

          param_4 = ppuVar10;

        }

        local_44 = (param_1[1] >> 5) - (piVar5[1] >> 5);

      } while (local_44 == 0);

      uVar2 = piVar5[1];

      iStack_34 = ((*param_1 - *piVar5) * 0x2000) / (int)(param_1[1] - uVar2);

      if (iStack_34 < 0) {

        ppuVar10 = (undefined **)((int)ppuVar10 + ((int)((~uVar2 & 0x1f) * iStack_34) >> 5));

        param_4 = ppuVar10;

      }

      else {

        ppuVar10 = (undefined **)((int)ppuVar10 - ((int)((uVar2 & 0x1f) * iStack_34) >> 5));

      }

    }

LAB_0053ebb6:

    if (local_40 == 0) {

      do {

        piVar5 = param_5;

        param_5 = piVar5;

        if (piVar5 == piVar4) goto LAB_0053ec5d;

        param_5 = param_2;

        if (piVar5 != param_2 + iVar3 + -2) {

          param_5 = piVar5 + 2;

        }

        ppuVar7 = (undefined **)(*piVar5 * 0x100);

        if ((int)ppuVar9 < (int)ppuVar7) {

          ppuVar9 = ppuVar7;

        }

        local_40 = (param_5[1] >> 5) - (piVar5[1] >> 5);

      } while (local_40 == 0);

      uVar2 = piVar5[1];

      iStack_30 = ((*param_5 - *piVar5) * 0x2000) / (int)(param_5[1] - uVar2);

      if (iStack_30 < 1) {

        ppuVar7 = (undefined **)((int)ppuVar7 - ((int)((uVar2 & 0x1f) * iStack_30) >> 5));

      }

      else {

        ppuVar7 = (undefined **)((int)ppuVar7 + ((int)((~uVar2 & 0x1f) * iStack_30) >> 5));

        ppuVar9 = ppuVar7;

      }

    }

LAB_0053ec5d:

    iVar8 = local_44;

    if (local_40 <= local_44) {

      iVar8 = local_40;

    }

    if (iVar8 == 0) {

      local_1c = (int)param_4 >> 0xd;

      local_24 = local_24 | 2;

      local_20 = (((int)ppuVar9 >> 0xd) - local_1c) + 1;

      (*(code *)*param_3)(&local_2c);

      return;

    }

    local_44 = local_44 - iVar8;

    local_40 = local_40 - iVar8;

    do {

      local_1c = (int)param_4 >> 0xd;

      local_20 = (((int)ppuVar9 >> 0xd) - local_1c) + 1;

      (*(code *)*param_3)(&local_2c);

      param_4 = (undefined **)((int)ppuVar10 + iStack_34);

      ppuVar7 = (undefined **)((int)ppuVar7 + iStack_30);

      local_18 = local_18 + 1;

      iVar8 = iVar8 + -1;

      ppuVar9 = ppuVar7;

      ppuVar10 = param_4;

    } while (iVar8 != 0);

    if ((local_44 == 0) && (iStack_34 < 0)) {

      param_4 = (undefined **)(*param_1 << 8);

    }

    if ((local_40 == 0) && (0 < iStack_30)) {

      ppuVar9 = (undefined **)(*param_5 << 8);

    }

  } while( true );

}

/* ===== FUN_0053ed40 @ 0x0053ED40 ===== */
void FUN_0053ed40(uint param_1,undefined **param_2,undefined **param_3,undefined **param_4,

                 undefined1 *param_5,int param_6)



{

  int iVar1;

  int iVar2;

  uint uVar3;

  undefined **ppuVar4;

  int iVar5;

  int iVar6;

  undefined **ppuVar7;

  undefined **ppuVar8;

  bool bVar9;

  int local_54;

  int local_50;

  int local_4c;

  int local_44;

  int local_40;

  int local_3c;

  int local_38;

  int iStack_34;

  uint local_30;

  undefined4 local_2c;

  uint local_28;

  uint local_24;

  int local_20;

  int aiStack_1c [4];

  uint local_c;

  uint local_8;

  undefined1 *local_4;

  

  local_2c = param_6;

  local_28 = param_1;

  local_24 = 2;

  if (param_4 == (undefined **)0x0) {

    param_4 = &PTR_FUN_00580c50;

  }

  local_4 = param_5;

  if (param_5 == (undefined1 *)0x0) {

    local_4 = &LAB_00425e70;

  }

  local_c = param_1 & 1;

  local_8 = (uint)(local_c == 0);

  local_30 = param_1 & 2;

  aiStack_1c[2] = (uint)(local_30 == 0) * 2 + -1;

  aiStack_1c[3] = (-(uint)((param_1 & 4) != 0) & 0xfffffffe) + 1;

  local_4c = (int)param_3;

  iVar6 = (int)param_3;

  iVar2 = (int)param_3;

  iVar5 = (int)param_2;

  while (iVar5 = iVar5 + -1, iVar5 != 0) {

    iVar6 = iVar6 + 8;

    iVar1 = *(int *)(iVar6 + local_8 * 4);

    param_6 = local_4c;

    if (iVar1 < *(int *)(local_4c + local_8 * 4)) {

      param_6 = iVar6;

    }

    local_4c = param_6;

    if (*(int *)(iVar2 + local_8 * 4) < iVar1) {

      iVar2 = iVar6;

    }

  }

  if ((int)((int)param_1 >> 1 & 2U ^ local_30) >> 1 == local_c) {

    local_38 = (int)param_3;

    local_40 = (int)param_3 + -8 + (int)param_2 * 8;

    local_3c = 1;

  }

  else {

    local_40 = (int)param_3;

    local_38 = (int)param_3 + -8 + (int)param_2 * 8;

    local_3c = -1;

  }

  local_50 = 0;

  local_54 = 0;

  param_6 = iVar2;

  if (0 < aiStack_1c[local_8 + 2]) {

    param_6 = local_4c;

    local_4c = iVar2;

  }

  param_2 = (undefined **)(*(int *)(param_6 + local_c * 4) << 8);

  aiStack_1c[local_8] = *(int *)(param_6 + local_8 * 4) >> 5;

  iVar5 = local_8 * 4;

  local_44 = aiStack_1c[local_8 + 2];

  ppuVar4 = param_4;

  ppuVar7 = param_4;

  param_3 = param_2;

  param_5 = (undefined1 *)param_6;

  do {

    if ((local_54 == 0) && (param_6 != local_4c)) {

      bVar9 = aiStack_1c[local_c + 2] < 0;

      iVar6 = param_6;

      do {

        param_6 = local_40;

        if (iVar6 != local_38) {

          param_6 = iVar6 + local_3c * -8;

        }

        ppuVar7 = (undefined **)(*(int *)(iVar6 + local_c * 4) * 0x100);

        if ((int)ppuVar7 < (int)param_2 != bVar9) {

          param_2 = ppuVar7;

        }

        local_54 = (*(int *)(iVar5 + param_6) >> 5) - (*(int *)(iVar5 + iVar6) >> 5);

        if (local_54 != 0) {

          uVar3 = *(uint *)(iVar5 + iVar6);

          iStack_34 = ((*(int *)(param_6 + local_c * 4) - *(int *)(iVar6 + local_c * 4)) * 0x2000) /

                      (int)(*(int *)(iVar5 + param_6) - uVar3);

          if (local_44 < 1) {

            iStack_34 = -iStack_34;

            if (iStack_34 < 0 != bVar9) goto LAB_0053efdb;

            uVar3 = ~uVar3;

          }

          else if (iStack_34 < 0 != bVar9) {

            uVar3 = ~uVar3;

LAB_0053efdb:

            ppuVar7 = (undefined **)((int)ppuVar7 + ((int)((uVar3 & 0x1f) * iStack_34) >> 5));

            param_2 = ppuVar7;

            break;

          }

          ppuVar7 = (undefined **)((int)ppuVar7 - ((int)((uVar3 & 0x1f) * iStack_34) >> 5));

          break;

        }

        iVar6 = param_6;

      } while (param_6 != local_4c);

    }

    ppuVar8 = param_2;

    if ((local_50 == 0) && (param_5 != (undefined1 *)local_4c)) {

      bVar9 = aiStack_1c[local_c + 2] < 0;

      do {

        iVar6 = local_38;

        if (param_5 != (undefined1 *)local_40) {

          iVar6 = (int)param_5 + local_3c * 8;

        }

        ppuVar4 = (undefined **)(*(int *)((int)param_5 + local_c * 4) * 0x100);

        if ((int)param_3 < (int)ppuVar4 != bVar9) {

          param_3 = ppuVar4;

        }

        local_50 = (*(int *)(iVar5 + iVar6) >> 5) - (*(int *)(iVar5 + (int)param_5) >> 5);

        if (local_50 != 0) {

          uVar3 = *(uint *)(iVar5 + (int)param_5);

          local_30 = ((*(int *)(iVar6 + local_c * 4) - *(int *)((int)param_5 + local_c * 4)) *

                     0x2000) / (int)(*(int *)(iVar5 + iVar6) - uVar3);

          if (local_44 < 1) {

            local_30 = -local_30;

            if (0 < (int)local_30 != bVar9) {

              ppuVar4 = (undefined **)((int)ppuVar4 + ((int)((uVar3 & 0x1f) * local_30) >> 5));

              param_3 = ppuVar4;

              param_5 = (undefined1 *)iVar6;

              break;

            }

            uVar3 = ~uVar3;

          }

          else if (0 < (int)local_30 != bVar9) {

            ppuVar4 = (undefined **)((int)ppuVar4 + ((int)((~uVar3 & 0x1f) * local_30) >> 5));

            param_3 = ppuVar4;

            param_5 = (undefined1 *)iVar6;

            break;

          }

          ppuVar4 = (undefined **)((int)ppuVar4 - ((int)((uVar3 & 0x1f) * local_30) >> 5));

          param_5 = (undefined1 *)iVar6;

          break;

        }

        param_5 = (undefined1 *)iVar6;

      } while (iVar6 != local_4c);

    }

    param_2 = (undefined **)local_54;

    if (local_44 < 1) {

      if (local_54 <= local_50) goto LAB_0053f14f;

    }

    else if (local_50 <= local_54) {

LAB_0053f14f:

      param_2 = (undefined **)local_50;

    }

    if (param_2 == (undefined **)0x0) {

      aiStack_1c[local_c] = (int)ppuVar8 >> 0xd;

      local_24 = local_24 | 2;

      local_20 = (((int)param_3 >> 0xd) - aiStack_1c[local_c]) + aiStack_1c[local_c + 2];

      (*(code *)param_4[param_1])(&local_2c);

      return;

    }

    local_54 = local_54 - (int)param_2;

    local_50 = local_50 - (int)param_2;

    do {

      aiStack_1c[local_c] = (int)ppuVar8 >> 0xd;

      local_20 = (((int)param_3 >> 0xd) - aiStack_1c[local_c]) + aiStack_1c[local_c + 2];

      (*(code *)param_4[param_1])(&local_2c);

      ppuVar8 = (undefined **)((int)ppuVar7 + iStack_34);

      aiStack_1c[local_8] = aiStack_1c[local_8] + aiStack_1c[local_8 + 2];

      ppuVar4 = (undefined **)((int)ppuVar4 + local_30);

      iVar5 = local_8 * 4;

      local_44 = aiStack_1c[local_8 + 2];

      param_2 = (undefined **)((int)param_2 - local_44);

      param_3 = ppuVar4;

      ppuVar7 = ppuVar8;

    } while (param_2 != (undefined **)0x0);

    param_2 = ppuVar8;

    if ((local_54 == 0) && (aiStack_1c[local_c + 2] < 0 != iStack_34 < 0)) {

      param_2 = (undefined **)(*(int *)(param_6 + local_c * 4) << 8);

    }

    if ((local_50 == 0) && (aiStack_1c[local_c + 2] < 0 != 0 < (int)local_30)) {

      param_3 = (undefined **)(*(int *)((int)param_5 + local_c * 4) << 8);

    }

  } while( true );

}

/* ===== FUN_0053f2e0 @ 0x0053F2E0 ===== */
void FUN_0053f2e0(int param_1,undefined4 param_2,int param_3)



{

  undefined4 uVar1;

  undefined4 uVar2;

  int iVar3;

  

  iVar3 = 0;

  if (0 < param_3) {

    do {

      uVar1 = __ftol();

      uVar2 = __ftol();

      *(undefined4 *)(param_1 + iVar3 * 8) = uVar2;

      *(undefined4 *)(param_1 + 4 + iVar3 * 8) = uVar1;

      iVar3 = iVar3 + 1;

    } while (iVar3 < param_3);

  }

  return;

}

/* ===== FUN_0053f330 @ 0x0053F330 ===== */
int FUN_0053f330(float *param_1,int param_2,int param_3,float param_4)



{

  float *extraout_EDX;

  float *pfVar1;

  float *extraout_EDX_00;

  int iVar2;

  float *pfVar3;

  float10 fVar4;

  float10 fVar5;

  float10 fVar6;

  

  pfVar3 = (float *)(param_2 + -0xc + (int)param_4 * 0xc);

  fVar4 = (float10)FUN_00516290(pfVar3,param_3);

  fVar4 = fVar4 + (float10)*(float *)(param_3 + 0xc);

  iVar2 = 0;

  if (param_4 != 0.0) {

    param_2 = (int)param_4;

    pfVar1 = extraout_EDX;

    do {

      param_4 = (float)fVar4;

      fVar4 = (float10)FUN_00516290(pfVar1,param_3);

      fVar4 = fVar4 + (float10)*(float *)(param_3 + 0xc);

      pfVar1 = param_1;

      if (fVar4 < (float10)0.0 != param_4 < 0.0) {

        pfVar1 = param_1 + 3;

        iVar2 = iVar2 + 1;

        fVar5 = (float10)param_4 / ((float10)param_4 - fVar4);

        fVar6 = (float10)1.0 - fVar5;

        *param_1 = (float)(fVar6 * (float10)*pfVar3 + fVar5 * (float10)*extraout_EDX_00);

        param_1[1] = (float)(fVar5 * (float10)extraout_EDX_00[1] + fVar6 * (float10)pfVar3[1]);

        param_1[2] = (float)(fVar5 * (float10)extraout_EDX_00[2] + fVar6 * (float10)pfVar3[2]);

      }

      param_1 = pfVar1;

      if ((float10)0.0 < fVar4) {

        param_1 = pfVar1 + 3;

        iVar2 = iVar2 + 1;

        *pfVar1 = *extraout_EDX_00;

        pfVar1[1] = extraout_EDX_00[1];

        pfVar1[2] = extraout_EDX_00[2];

      }

      pfVar1 = extraout_EDX_00 + 3;

      param_2 = param_2 + -1;

      pfVar3 = extraout_EDX_00;

    } while (param_2 != 0);

  }

  return iVar2;

}

/* ===== FUN_0053f440 @ 0x0053F440 ===== */
undefined4 FUN_0053f440(float *param_1,float *param_2,float *param_3,float *param_4)



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

  float fVar11;

  float fVar12;

  float fVar13;

  float fVar14;

  float fVar15;

  float fVar16;

  float fVar17;

  float fVar18;

  float fVar19;

  float fVar20;

  float fVar21;

  float fVar22;

  float fVar23;

  float fVar24;

  float fVar25;

  

  fVar1 = param_4[2];

  fVar2 = *param_3;

  fVar3 = param_3[2];

  fVar4 = *param_4;

  fVar5 = *param_3;

  fVar6 = param_4[1];

  fVar7 = *param_4;

  fVar8 = param_3[1];

  fVar25 = (fVar5 * fVar6 - fVar7 * fVar8) * param_2[2] +

           ((param_4[2] * param_3[1] - param_3[2] * param_4[1]) * *param_2 -

           (fVar1 * fVar2 - fVar3 * fVar4) * param_2[1]);

  if ((fVar25 <= 1e-06) && (-1e-06 <= fVar25)) {

    *param_1 = 0.0;

    param_1[1] = 0.0;

    param_1[2] = 0.0;

    return 0;

  }

  fVar9 = *param_2;

  fVar10 = param_4[2];

  fVar11 = *param_4;

  fVar12 = param_2[2];

  fVar13 = param_2[1];

  fVar14 = *param_4;

  fVar15 = *param_2;

  fVar16 = param_4[1];

  fVar17 = *param_3;

  fVar18 = param_2[2];

  fVar19 = param_3[2];

  fVar20 = *param_2;

  fVar21 = *param_2;

  fVar22 = param_3[1];

  fVar23 = param_2[1];

  fVar24 = *param_3;

  fVar25 = 1.0 / fVar25;

  *param_1 = -((param_2[2] * param_4[1] - param_2[1] * param_4[2]) * param_3[3] +

              (param_2[1] * param_3[2] - param_2[2] * param_3[1]) * param_4[3] +

              (param_4[2] * param_3[1] - param_3[2] * param_4[1]) * param_2[3]) * fVar25;

  param_1[1] = -((fVar9 * fVar10 - fVar11 * fVar12) * param_3[3] +

                (fVar17 * fVar18 - fVar19 * fVar20) * param_4[3] +

                (fVar3 * fVar4 - fVar1 * fVar2) * param_2[3]) * fVar25;

  param_1[2] = -((fVar13 * fVar14 - fVar15 * fVar16) * param_3[3] +

                (fVar21 * fVar22 - fVar23 * fVar24) * param_4[3] +

                (fVar5 * fVar6 - fVar7 * fVar8) * param_2[3]) * fVar25;

  return 1;

}

/* ===== FUN_0053f5d0 @ 0x0053F5D0 ===== */
void FUN_0053f5d0(float *param_1,float *param_2)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  

  fVar1 = *param_2;

  fVar2 = param_2[3];

  fVar3 = param_2[2];

  fVar4 = param_2[1];

  fVar5 = fVar1 * fVar1 + fVar4 * fVar4 + fVar3 * fVar3 + fVar2 * fVar2;

  if (fVar5 == 0.0) {

    fVar5 = 1.0;

  }

  fVar5 = 1.0 / fVar5;

  *param_1 = -(fVar5 * fVar1);

  param_1[1] = -(fVar4 * fVar5);

  param_1[2] = -(fVar3 * fVar5);

  param_1[3] = fVar5 * fVar2;

  return;

}

/* ===== FUN_0053f650 @ 0x0053F650 ===== */
void FUN_0053f650(float *param_1,float *param_2)



{

  float fVar1;

  float10 fVar2;

  

  fVar1 = param_2[3];

  fVar2 = (float10)(*(code *)PTR_FUN_00580c30)(fVar1 * 0.5);

  *param_1 = (float)(fVar2 * (float10)*param_2);

  param_1[1] = (float)(fVar2 * (float10)param_2[1]);

  param_1[2] = (float)(fVar2 * (float10)param_2[2]);

  fVar2 = (float10)(*(code *)PTR_FUN_00580c34)(fVar1 * 0.5);

  param_1[3] = (float)fVar2;

  return;

}

/* ===== FUN_0053f6a0 @ 0x0053F6A0 ===== */
void FUN_0053f6a0(int param_1,float *param_2,float *param_3,float param_4)



{

  float *pfVar1;

  float fVar2;

  int iVar3;

  int iVar4;

  float10 fVar5;

  float10 fVar6;

  float local_4;

  

  fVar2 = *param_2 * *param_3 +

          param_2[1] * param_3[1] + param_2[2] * param_3[2] + param_2[3] * param_3[3];

  if (0.0 <= fVar2) {

    if (1.0 - fVar2 <= 1e-06) {

      local_4 = 1.0 - param_4;

      fVar5 = (float10)param_4;

    }

    else {

      fVar5 = (float10)(*(code *)PTR_FUN_00580c38)(fVar2);

      fVar2 = (float)fVar5;

      fVar6 = (float10)(*(code *)PTR_FUN_00580c3c)(fVar2);

      fVar5 = (float10)(*(code *)PTR_FUN_00580c30)((1.0 - param_4) * fVar2);

      local_4 = (float)(fVar5 * (float10)(float)fVar6);

      fVar5 = (float10)(*(code *)PTR_FUN_00580c30)(fVar2 * param_4);

      fVar5 = fVar5 * (float10)(float)fVar6;

    }

    iVar4 = (int)param_2 - (int)param_3;

    param_1 = param_1 - (int)param_3;

    iVar3 = 4;

    do {

      pfVar1 = (float *)(iVar4 + (int)param_3);

      fVar2 = *param_3;

      param_3 = param_3 + 1;

      iVar3 = iVar3 + -1;

      *(float *)(param_1 + -4 + (int)param_3) =

           (float)(fVar5 * (float10)fVar2 + (float10)local_4 * (float10)*pfVar1);

    } while (iVar3 != 0);

    return;

  }

  if (fVar2 + 1.0 <= 1e-06) {

    local_4 = 1.0 - param_4;

    fVar5 = (float10)param_4;

  }

  else {

    fVar5 = (float10)(*(code *)PTR_FUN_00580c38)(-fVar2);

    fVar2 = (float)fVar5;

    fVar6 = (float10)(*(code *)PTR_FUN_00580c3c)(fVar2);

    fVar5 = (float10)(*(code *)PTR_FUN_00580c30)((1.0 - param_4) * fVar2);

    local_4 = (float)(fVar5 * (float10)(float)fVar6);

    fVar5 = (float10)(*(code *)PTR_FUN_00580c30)(fVar2 * param_4);

    fVar5 = fVar5 * (float10)(float)fVar6;

  }

  iVar4 = (int)param_3 - (int)param_2;

  param_1 = param_1 - (int)param_2;

  iVar3 = 4;

  do {

    pfVar1 = (float *)(iVar4 + (int)param_2);

    fVar2 = *param_2;

    param_2 = param_2 + 1;

    iVar3 = iVar3 + -1;

    *(float *)(param_1 + -4 + (int)param_2) =

         (float)(fVar5 * (float10)*pfVar1 - (float10)local_4 * (float10)fVar2);

  } while (iVar3 != 0);

  return;

}

/* ===== FUN_0053f9e0 @ 0x0053F9E0 ===== */
void FUN_0053f9e0(float *param_1,float *param_2,float *param_3)



{

  float *pfVar1;

  float local_10 [4];

  

  if ((param_1 == param_2) || (pfVar1 = param_1, param_1 == param_3)) {

    pfVar1 = local_10;

  }

  pfVar1[3] = ((param_3[3] * param_2[3] - *param_2 * *param_3) - param_2[1] * param_3[1]) -

              param_2[2] * param_3[2];

  *pfVar1 = (param_3[3] * *param_2 + param_2[3] * *param_3 + param_2[1] * param_3[2]) -

            param_2[2] * param_3[1];

  pfVar1[1] = (param_2[2] * *param_3 + param_2[1] * param_3[3] + param_2[3] * param_3[1]) -

              *param_2 * param_3[2];

  pfVar1[2] = (*param_2 * param_3[1] + param_2[2] * param_3[3] + param_2[3] * param_3[2]) -

              param_2[1] * *param_3;

  if (param_1 != pfVar1) {

    *param_1 = *pfVar1;

    param_1[1] = pfVar1[1];

    param_1[2] = pfVar1[2];

    param_1[3] = pfVar1[3];

  }

  return;

}

/* ===== FUN_0053faa0 @ 0x0053FAA0 ===== */
void FUN_0053faa0(undefined4 param_1,undefined4 param_2,undefined4 param_3)



{

  undefined1 local_10 [16];

  

  FUN_0053f5d0(local_10,param_3);

  FUN_0053f9e0(param_1,local_10,param_2);

  return;

}

/* ===== FUN_0053fad0 @ 0x0053FAD0 ===== */
void FUN_0053fad0(float *param_1,undefined4 param_2,undefined4 param_3)



{

  float10 fVar1;

  float10 fVar2;

  

  FUN_0053e900(param_1,param_2,param_3);

  fVar1 = (float10)FUN_00516290(param_2,param_3);

  param_1[3] = (float)fVar1;

  fVar1 = (float10)(*(code *)PTR_FUN_00580c44)((float)((fVar1 + (float10)1.0) * (float10)0.5));

  fVar2 = (float10)1.0 / (fVar1 + fVar1);

  *param_1 = (float)(fVar2 * (float10)*param_1);

  param_1[1] = (float)(fVar2 * (float10)param_1[1]);

  param_1[2] = (float)(fVar2 * (float10)param_1[2]);

  param_1[3] = (float)fVar1;

  return;

}

/* ===== FUN_0053fb40 @ 0x0053FB40 ===== */
void FUN_0053fb40(float *param_1,undefined4 param_2,float param_3,float param_4)



{

  float fVar1;

  float10 fVar2;

  float10 fVar3;

  

  FUN_0053e900(param_1,param_2,param_3);

  fVar2 = (float10)FUN_00516290(param_2,param_3);

  param_3 = (float)fVar2;

  if ((float10)1.0 < fVar2) {

    param_3 = 1.0;

  }

  fVar2 = (float10)(*(code *)PTR_FUN_00580c44)(1.0 - param_3 * param_3);

  if (fVar2 != (float10)0.0) {

    fVar3 = (float10)(*(code *)PTR_FUN_00580c38)(param_3);

    fVar1 = (float)(fVar3 * (float10)param_4 * (float10)0.5);

    fVar3 = (float10)(*(code *)PTR_FUN_00580c30)(fVar1);

    fVar3 = fVar3 / (float10)(float)fVar2;

    *param_1 = (float)(fVar3 * (float10)*param_1);

    param_1[1] = (float)(fVar3 * (float10)param_1[1]);

    param_1[2] = (float)(fVar3 * (float10)param_1[2]);

    fVar2 = (float10)(*(code *)PTR_FUN_00580c34)(fVar1);

    param_1[3] = (float)fVar2;

    return;

  }

  param_1[3] = 1.0;

  param_1[2] = 0.0;

  param_1[1] = 0.0;

  *param_1 = 0.0;

  return;

}

/* ===== FUN_0053fc10 @ 0x0053FC10 ===== */
void FUN_0053fc10(undefined *param_1)



{

  PTR__malloc_00580c84 = param_1;

  return;

}

/* ===== FUN_0053fc20 @ 0x0053FC20 ===== */
uint FUN_0053fc20(int param_1)



{

  uint uVar1;

  uint uVar2;

  

  uVar1 = (*(code *)PTR__malloc_00580c84)(param_1 + 0x10);

  uVar2 = uVar1 + 0x10 & 0xfffffff0;

  *(uint *)(uVar2 - 4) = uVar1 & 0xf;

  return uVar2;

}

/* ===== FUN_0053fc40 @ 0x0053FC40 ===== */
void FUN_0053fc40(undefined *param_1)



{

  PTR_FUN_00580c8c = param_1;

  return;

}

/* ===== FUN_0053fc50 @ 0x0053FC50 ===== */
void FUN_0053fc50(void)



{

                    /* WARNING: Could not recover jumptable at 0x0053fc5f. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  (*(code *)PTR_FUN_00580c8c)();

  return;

}

/* ===== FUN_0053fc70 @ 0x0053FC70 ===== */
void FUN_0053fc70(int *param_1,undefined4 param_2)



{

  int *piVar1;

  

  piVar1 = param_1;

  do {

    FUN_005400e0(piVar1,param_2);

    piVar1 = (int *)*piVar1;

  } while (piVar1 != param_1);

  return;

}

/* ===== FUN_0053fca0 @ 0x0053FCA0 ===== */
void FUN_0053fca0(int param_1,undefined4 *param_2)



{

  undefined4 *puVar1;

  int iVar2;

  

  iVar2 = *(int *)(param_1 + 0x20);

  if (iVar2 != 0) {

    puVar1 = (undefined4 *)(*(int *)(param_1 + 0x24) + 0x14);

    do {

      if (param_2 == (undefined4 *)0x0) {

        puVar1[-4] = 0;

        *puVar1 = 0;

      }

      else {

        puVar1[-4] = param_2[1];

        *puVar1 = *param_2;

        param_2 = param_2 + 2;

      }

      puVar1[-3] = 0;

      puVar1[-2] = 0;

      puVar1[1] = 0;

      puVar1 = puVar1 + 7;

      iVar2 = iVar2 + -1;

    } while (iVar2 != 0);

  }

  return;

}

/* ===== FUN_0053fcf0 @ 0x0053FCF0 ===== */
void FUN_0053fcf0(uint *param_1)



{

  uint uVar1;

  uint uVar2;

  uint uVar3;

  

  uVar2 = 0;

  uVar3 = *param_1;

  param_1[2] = uVar3;

  uVar1 = uVar3 >> 1;

  if (uVar3 != uVar1) {

    do {

      param_1[2] = uVar1;

      uVar1 = (*(code *)param_1[1])(param_1);

      param_1[3] = uVar1;

      if (uVar1 == 0) {

        return;

      }

      if ((int)uVar1 < 0) {

        uVar3 = param_1[2];

      }

      else {

        uVar2 = param_1[2];

      }

      uVar1 = (uVar3 - uVar2 >> 1) + uVar2;

    } while (param_1[2] != uVar1);

  }

  return;

}

/* ===== FUN_0053fd40 @ 0x0053FD40 ===== */
void FUN_0053fd40(undefined4 *param_1,undefined4 param_2,int param_3)



{

  undefined4 *puVar1;

  int iVar2;

  int *piVar3;

  int iVar4;

  

  puVar1 = param_1;

  FUN_005400e0(param_1,param_3);

  FUN_005400e0(param_1 + 5,param_3);

  piVar3 = param_1 + 9;

  FUN_005400e0(piVar3,param_3);

  FUN_0053fe70(*param_1,param_3);

  param_1 = (undefined4 *)param_1[8];

  if (param_1 != (undefined4 *)0x0) {

    piVar3 = (int *)(*piVar3 + 0x10);

    do {

      FUN_005400e0(piVar3,param_3);

      iVar4 = *piVar3;

      for (iVar2 = puVar1[7]; iVar2 != 0; iVar2 = iVar2 + -1) {

        FUN_005400e0(iVar4,param_3);

        iVar4 = iVar4 + 4;

      }

      piVar3 = piVar3 + 7;

      param_1 = (undefined4 *)((int)param_1 + -1);

    } while (param_1 != (undefined4 *)0x0);

  }

  if (*(int *)(param_3 + 4) != 0) {

    FUN_0053fca0(puVar1,param_2);

  }

  return;

}

/* ===== FUN_0053fde0 @ 0x0053FDE0 ===== */
undefined4 FUN_0053fde0(int param_1,uint param_2,uint param_3)



{

  if ((param_2 < *(uint *)(param_1 + 0x1c)) && (param_3 < *(uint *)(param_1 + 0x20))) {

    return *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x24) + 0x10 + param_3 * 0x1c) + param_2 * 4)

    ;

  }

  return 0;

}

/* ===== FUN_0053fe20 @ 0x0053FE20 ===== */
undefined4 FUN_0053fe20(int param_1,int param_2,uint param_3)



{

  int *piVar1;

  

  if ((*(int *)(param_1 + 0x1c) != 0) && (param_3 < *(uint *)(param_1 + 0x20))) {

    piVar1 = (int *)(*(int *)(param_1 + 0x24) + param_3 * 0x1c);

    *piVar1 = *(int *)(param_1 + 0x1c);

    piVar1[6] = param_2;

    FUN_0053fcf0(piVar1);

    if (piVar1[3] == 0) {

      return *(undefined4 *)(piVar1[4] + piVar1[2] * 4);

    }

  }

  return 0;

}

/* ===== FUN_0053fe70 @ 0x0053FE70 ===== */
void FUN_0053fe70(int param_1,undefined4 param_2)



{

  FUN_0053fc70(param_1 + 0x10,param_2);

  FUN_005400e0(param_1 + 0x1c,param_2);

  FUN_005400e0(param_1 + 0xc,param_2);

  return;

}

/* ===== FUN_0053fea0 @ 0x0053FEA0 ===== */
undefined4 FUN_0053fea0(int param_1)



{

  return *(undefined4 *)(param_1 + 0x1c);

}

/* ===== FUN_0053feb0 @ 0x0053FEB0 ===== */
int FUN_0053feb0(undefined4 param_1,int param_2)



{

  int iVar1;

  int iVar2;

  int local_8 [2];

  

  if (param_2 != 0) {

    local_8[0] = param_2;

    param_2 = *(int *)(param_2 + 4) + param_2;

    local_8[1] = 1;

    FUN_0053fe70(param_2,local_8);

    *(undefined4 *)(param_2 + 0xc) = param_1;

    return param_2;

  }

  iVar1 = FUN_0053ffa0(param_1,0x24,1);

  iVar2 = iVar1 + 4;

  *(undefined4 *)(iVar1 + 0x10) = param_1;

  *(undefined4 *)(iVar1 + 0x18) = 0;

  *(undefined4 *)(iVar1 + 0x1c) = 0;

  *(int *)(iVar1 + 0x14) = iVar1 + 0x14;

  FUN_0053ff30(iVar2,iVar2,0x24);

  *(int *)(iVar1 + 0x20) = iVar2;

  return iVar2;

}

/* ===== FUN_0053ff30 @ 0x0053FF30 ===== */
void FUN_0053ff30(int param_1,undefined4 *param_2,int param_3)



{

  *param_2 = param_2;

  *param_2 = *(undefined4 *)(param_1 + 0x10);

  *(undefined4 **)(param_1 + 0x10) = param_2;

  param_2[1] = param_3;

  param_2[2] = 1;

  *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + param_3;

  *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 1;

  return;

}

/* ===== FUN_0053ff60 @ 0x0053FF60 ===== */
void FUN_0053ff60(int param_1)



{

  uint *puVar1;

  uint *puVar2;

  

  puVar2 = *(uint **)(param_1 + 0x10);

  puVar1 = (uint *)(-(uint)(puVar2 != (uint *)(param_1 + 0x10U)) & (uint)puVar2);

  puVar2 = (uint *)*puVar2;

  if (puVar1 != (uint *)0x0) {

    while( true ) {

      FUN_00540020(param_1,puVar1 + 3);

      if (puVar2 == (uint *)(param_1 + 0x10U)) break;

      puVar1 = puVar2;

      puVar2 = (uint *)*puVar2;

    }

  }

  return;

}

/* ===== FUN_0053ffa0 @ 0x0053FFA0 ===== */
undefined4 * FUN_0053ffa0(int param_1,uint param_2,int param_3)



{

  undefined4 *puVar1;

  uint uVar2;

  undefined4 *puVar3;

  

  if (param_2 == 0) {

    return (undefined4 *)0x0;

  }

  if (param_1 != 0) {

    param_2 = param_2 + 0x1f & 0xfffffff0;

    if (*(int *)(param_1 + 0xc) != 0) {

      puVar1 = (undefined4 *)FUN_0053ffa0(*(int *)(param_1 + 0xc),param_2,param_3);

      if (puVar1 != (undefined4 *)0x0) goto LAB_0053ffe2;

    }

  }

  puVar1 = (undefined4 *)(*(code *)PTR_FUN_00580c88)(param_2);

LAB_0053ffe2:

  if (param_3 != 0) {

    puVar3 = puVar1;

    for (uVar2 = param_2 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {

      *puVar3 = 0;

      puVar3 = puVar3 + 1;

    }

    for (uVar2 = param_2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {

      *(undefined1 *)puVar3 = 0;

      puVar3 = (undefined4 *)((int)puVar3 + 1);

    }

  }

  if (param_1 != 0) {

    FUN_0053ff30(param_1,puVar1 + 1,param_2);

    return puVar1 + 4;

  }

  return puVar1;

}

