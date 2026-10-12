/* Giants 1.449 — module main/cleaner
 * 3 functions (0 named) — decompiled, names from PS2 symbols
 * Original source: C:\Giants\source\main/cleaner.c(pp) (assert-string evidence)
 */

/* ===== FUN_0040f390 @ 0x0040F390 ===== */
void FUN_0040f390(void)



{

  if (DAT_00584320 != 0) {

    mem_free_tagged(DAT_00584320,s_C__Giants_source_main_cleaner_c_00555438,0x30);

    DAT_00584320 = 0;

  }

  return;

}

/* ===== FUN_0040f3c0 @ 0x0040F3C0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* PS2 candidate: cleaner_go_obj (conf 0.36) */



void FUN_0040f3c0(void)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  undefined4 *puVar5;

  float fVar6;

  int iVar7;

  int iVar8;

  int iVar9;

  int iVar10;

  float10 extraout_ST0;

  float10 fVar11;

  float10 fVar12;

  float10 extraout_ST1;

  float local_14;

  float local_10;

  float local_c;

  float local_8;

  float local_4;

  

  _DAT_0058431c = _DAT_0058431c - DAT_006328e0;

  if (_DAT_0058431c <= 0.0) {

    _DAT_0058431c = 1.5;

    iVar7 = FUN_0052aa70();

    if (iVar7 == 0) {

      iVar7 = 0;

      for (puVar5 = DAT_00632d68; puVar5 != (undefined4 *)0x0; puVar5 = (undefined4 *)*puVar5) {

        iVar10 = puVar5[3];

        iVar8 = iVar7;

        if ((((*(uint *)(iVar10 + 0xd8) & 0x8000) == 0) &&

            ((((*(uint *)(iVar10 + 0xdc) & 0x20000) == 0 ||

              (*(float *)(iVar10 + 0x278) < *(float *)(iVar10 + 0x1c0))) ||

             (iVar8 = iVar10, DAT_00632e6c <= *(float *)(iVar10 + 0xec) + 3.0)))) &&

           (iVar8 = iVar7, *(int *)(iVar10 + 4) == 0x2ad)) {

          return;

        }

        iVar7 = iVar8;

      }

      if (DAT_00584320 != 0) {

        mem_free_tagged(DAT_00584320,s_C__Giants_source_main_cleaner_c_00555438,0x74);

        DAT_00584320 = 0;

      }

      if ((iVar7 != 0) && (*(float *)(iVar7 + 0x1c0) <= *(float *)(iVar7 + 0x278))) {

        FUN_0040f750(iVar7);

        iVar10 = DAT_00632ed8;

        fVar6 = DAT_00584300 - DAT_005842f4;

        fVar3 = DAT_005842fc - DAT_005842f0;

        iVar8 = __ftol();

        fVar11 = ((float10)*(float *)(iVar10 + 0x528) - (float10)*(float *)(iVar10 + 0x530)) /

                 extraout_ST0;

        fVar11 = fVar11 * extraout_ST1 +

                 ((float10)*(float *)(iVar10 + 0x528) - (float10)*(float *)(iVar10 + 0x524) * fVar11

                 );

        local_8 = (float)(((float10)_DAT_00584304 - (float10)DAT_005842f8) / fVar11);

        local_4 = (float)(fVar11 - (float10)*(float *)(iVar10 + 0x534));

        fVar11 = ((float10)*(float *)(iVar10 + 0x550) - (float10)*(float *)(iVar10 + 0x54c)) /

                 extraout_ST0;

        local_c = (float)(fVar11 * extraout_ST1 +

                         ((float10)*(float *)(iVar10 + 0x550) -

                         (float10)*(float *)(iVar10 + 0x524) * fVar11));

        fVar11 = ((float10)*(float *)(iVar10 + 0x558) - (float10)*(float *)(iVar10 + 0x554)) /

                 extraout_ST0;

        fVar1 = *(float *)(iVar10 + 0x558);

        fVar2 = *(float *)(iVar10 + 0x524);

        if (fVar6 < fVar3) {

          fVar6 = fVar3;

        }

        fVar3 = *(float *)(iVar7 + 0xc4);

        iVar10 = 0;

        if (0 < iVar8) {

          do {

            iVar9 = FUN_00496c00(0x2ad,0x80000000);

            fVar12 = (float10)FUN_004d5760(*(undefined4 *)(DAT_00632ed8 + 0x538));

            fVar4 = (float)(fVar12 + (float10)(fVar6 * fVar3 * 0.5));

            fVar12 = (float10)FUN_004d5760(0x43b40000);

            FUN_0050ae40((float)fVar12,&local_14,&local_10);

            *(float *)(iVar9 + 0xa0) = local_14 * fVar4 + *(float *)(iVar7 + 0xa0);

            *(float *)(iVar9 + 0xa4) = *(float *)(iVar7 + 0xa4) - local_10 * fVar4;

            *(undefined4 *)(iVar9 + 0xa8) = *(undefined4 *)(iVar7 + 0xa8);

            fVar12 = (float10)FUN_004d5760(0x43b40000);

            *(float *)(iVar9 + 200) = (float)fVar12;

            fVar12 = (float10)FUN_004d5780(local_c,(float)(fVar11 * extraout_ST1 +

                                                          ((float10)fVar1 - (float10)fVar2 * fVar11)

                                                          ));

            *(float *)(iVar9 + 0xc4) = (float)fVar12;

            FUN_00499280(iVar9);

            *(int *)(iVar9 + 0x274) = iVar7;

            *(undefined4 *)(iVar9 + 0xe4) = 0;

            *(float *)(iVar9 + 0xf4) = local_8;

            *(float *)(iVar9 + 0xf8) = local_4;

            *(undefined4 *)(iVar9 + 0xfc) = 0x3f800000;

            fVar12 = (float10)FUN_004d5760(0x3f800000);

            *(float *)(iVar9 + 0xec) = (float)fVar12;

            FUN_004034a0(iVar9,0xb,0x24,0,0,0);

            iVar10 = iVar10 + 1;

            *(int *)(iVar9 + 0x174) = iVar10;

          } while (iVar10 < iVar8);

        }

      }

    }

  }

  return;

}

/* ===== FUN_0040f750 @ 0x0040F750 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_0040f750(int param_1)



{

  int iVar1;

  int iVar2;

  int iVar3;

  float *pfVar4;

  int iVar5;

  float *pfVar6;

  float10 extraout_ST0;

  float10 fVar7;

  float10 extraout_ST1;

  float10 extraout_ST1_00;

  float10 extraout_ST1_01;

  float10 fVar8;

  int local_44;

  float local_3c;

  float local_38;

  float local_34;

  float local_30;

  float local_2c;

  undefined4 local_28;

  float local_24;

  float local_20;

  float local_1c;

  float local_18 [4];

  float local_8;

  float local_4;

  

  iVar1 = param_1;

  iVar2 = FUN_0042b1d0(param_1);

  FUN_0042b010(iVar2);

  FUN_00404b60(param_1,0xffffffff);

  FUN_0042b030();

  iVar2 = *(int *)(*(int *)(param_1 + 8) + 0x400 + iVar2 * 4);

  FUN_005170f0(param_1,*(undefined4 *)(iVar2 + 0x14),local_18 + 3);

  local_18[0] = local_18[3];

  local_18[1] = local_8;

  local_18[2] = local_4;

  iVar5 = 1;

  if (1 < *(int *)(iVar2 + 0x10)) {

    iVar3 = 0xc;

    do {

      FUN_005170f0(param_1,*(int *)(iVar2 + 0x14) + iVar3,&local_3c);

      if (local_3c < local_18[0]) {

        local_18[0] = local_3c;

      }

      if (local_38 < local_18[1]) {

        local_18[1] = local_38;

      }

      if (local_34 < local_18[2]) {

        local_18[2] = local_34;

      }

      if (local_18[3] < local_3c) {

        local_18[3] = local_3c;

      }

      if (local_8 < local_38) {

        local_8 = local_38;

      }

      if (local_4 < local_34) {

        local_4 = local_34;

      }

      iVar5 = iVar5 + 1;

      iVar3 = iVar3 + 0xc;

    } while (iVar5 < *(int *)(iVar2 + 0x10));

  }

  pfVar4 = local_18;

  pfVar6 = &DAT_005842f0;

  for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {

    *pfVar6 = *pfVar4;

    pfVar4 = pfVar4 + 1;

    pfVar6 = pfVar6 + 1;

  }

  param_1 = __ftol();

  local_44 = __ftol();

  fVar7 = extraout_ST0;

  fVar8 = extraout_ST1;

  if (0x96 < local_44 * param_1) {

    param_1 = __ftol();

    param_1 = param_1 + 1;

    fVar8 = extraout_ST1_00;

    local_44 = __ftol();

    local_44 = local_44 + 1;

    fVar7 = extraout_ST1_01;

  }

  _DAT_00584308 = (float)(fVar8 / (float10)param_1);

  if ((float10)_DAT_00584308 < fVar7 / (float10)local_44) {

    _DAT_00584308 = (float)(fVar7 / (float10)local_44);

  }

  DAT_00584314 = __ftol();

  DAT_0058430c = __ftol();

  if (DAT_00584320 != 0) {

    mem_free_tagged(DAT_00584320,s_C__Giants_source_main_cleaner_c_00555438,0xaa);

  }

  iVar2 = DAT_0058430c * DAT_00584314;

  DAT_00584320 = FUN_0053a700(5,iVar2 * 4,s_cleanhgt_00555458,

                              s_C__Giants_source_main_cleaner_c_00555438,0xac);

  iVar5 = 0;

  if (0 < iVar2) {

    do {

      *(undefined4 *)(DAT_00584320 + iVar5 * 4) = 0xc47a0000;

      iVar5 = iVar5 + 1;

    } while (iVar5 < iVar2);

  }

  local_44 = 0;

  iVar2 = DAT_00584314;

  if (0 < DAT_0058430c) {

    do {

      param_1 = 0;

      if (0 < iVar2) {

        do {

          local_28 = DAT_005842f8;

          local_30 = ((float)param_1 + 0.5) * _DAT_00584308 + DAT_005842f0;

          local_2c = ((float)local_44 + 0.5) * _DAT_00584308 + DAT_005842f4;

          local_1c = _DAT_00584304 + 10.0;

          local_24 = local_30;

          local_20 = local_2c;

          iVar2 = FUN_0049bf60(&local_24,&local_30,iVar1,&local_30,0);

          if (iVar2 != 0) {

            *(undefined4 *)(DAT_00584320 + (DAT_00584314 * local_44 + param_1) * 4) = local_28;

          }

          param_1 = param_1 + 1;

          iVar2 = DAT_00584314;

        } while (param_1 < DAT_00584314);

      }

      local_44 = local_44 + 1;

    } while (local_44 < DAT_0058430c);

  }

  _DAT_00584310 = 0;

  return;

}

