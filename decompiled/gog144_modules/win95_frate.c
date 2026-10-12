/* Giants 1.449 — module win95/frate
 * 3 functions (3 named) — decompiled, names from PS2 symbols
 * Original source: C:\Giants\source\win95/frate.c(pp) (assert-string evidence)
 */

/* ===== FRateSlowTime @ 0x00518BE0 ===== */
void FRateSlowTime(float param_1,float *param_2,float param_3,float param_4,float param_5)



{

  float *pfVar1;

  float fVar2;

  

  pfVar1 = (float *)FUN_0053a700(0x21,0x24,s_slow_frate_list_0057c954,

                                 s_C__Giants_source_win95_frate_c_0057c964,0xde);

  pfVar1[4] = *param_2;

  pfVar1[5] = param_2[1];

  fVar2 = param_2[2];

  *pfVar1 = param_4 * param_4;

  pfVar1[6] = fVar2;

  pfVar1[1] = param_5;

  pfVar1[2] = param_3;

  pfVar1[3] = param_1;

  pfVar1[8] = 0.0;

  fVar2 = 0.0;

  if (DAT_005dcfa8 != (float *)0x0) {

    *(float **)((int)DAT_005dcfa8 + 0x20) = pfVar1;

    fVar2 = (float)DAT_005dcfa8;

  }

  pfVar1[7] = fVar2;

  DAT_005dcfa8 = pfVar1;

  return;

}

/* ===== win95_frate_00518c60 @ 0x00518C60 ===== */
void win95_frate_00518c60(void)



{

  int iVar1;

  int iVar2;

  float fVar3;

  

  iVar2 = DAT_005dcfa8;

  while (iVar2 != 0) {

    fVar3 = *(float *)(iVar2 + 8) - DAT_006328e0;

    *(float *)(iVar2 + 8) = fVar3;

    if (fVar3 < 0.0 == (fVar3 == 0.0)) {

      iVar2 = *(int *)(iVar2 + 0x1c);

    }

    else {

      iVar1 = *(int *)(iVar2 + 0x1c);

      if (*(int *)(iVar2 + 0x20) != 0) {

        *(int *)(*(int *)(iVar2 + 0x20) + 0x1c) = iVar1;

      }

      if (iVar1 != 0) {

        *(undefined4 *)(iVar1 + 0x20) = *(undefined4 *)(iVar2 + 0x20);

      }

      if (iVar2 == DAT_005dcfa8) {

        DAT_005dcfa8 = iVar1;

      }

      mem_free_tagged(iVar2,s_C__Giants_source_win95_frate_c_0057c964,0x10b);

      iVar2 = iVar1;

    }

  }

  return;

}

/* ===== win95_frate_00518cd0 @ 0x00518CD0 ===== */
void win95_frate_00518cd0(void)



{

  int iVar1;

  int iVar2;

  

  iVar2 = DAT_005dcfa8;

  while (iVar2 != 0) {

    iVar1 = *(int *)(iVar2 + 0x1c);

    if (*(int *)(iVar2 + 0x20) != 0) {

      *(int *)(*(int *)(iVar2 + 0x20) + 0x1c) = iVar1;

    }

    if (iVar1 != 0) {

      *(undefined4 *)(iVar1 + 0x20) = *(undefined4 *)(iVar2 + 0x20);

    }

    if (iVar2 == DAT_005dcfa8) {

      DAT_005dcfa8 = iVar1;

    }

    mem_free_tagged(iVar2,s_C__Giants_source_win95_frate_c_0057c964,0x127);

    iVar2 = iVar1;

  }

  DAT_005dcfa8 = 0;

  return;

}

