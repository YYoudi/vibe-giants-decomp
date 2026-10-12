/* Giants 1.449 — module main/drawwatr
 * 2 functions (2 named) — decompiled, names from PS2 symbols
 * Original source: C:\Giants\source\main/drawwatr.c(pp) (assert-string evidence)
 */

/* ===== main_drawwatr_00430f30 @ 0x00430F30 ===== */
void main_drawwatr_00430f30(float param_1)



{

  float *pfVar1;

  undefined4 uVar2;

  int iVar3;

  int iVar4;

  

  if (*(int *)(DAT_00632d3c + 0x10) == 0) {

    uVar2 = FUN_0053a700(9,*(int *)(DAT_00632d3c + 4) << 3,s_seauv_00556740,

                         s_C__Giants_source_main_drawwatr_c_00556748,0xf);

    *(undefined4 *)(DAT_00632d3c + 0x10) = uVar2;

  }

  iVar3 = 0;

  if (0 < *(int *)(DAT_00632d3c + 4)) {

    iVar4 = 0;

    do {

      pfVar1 = (float *)(*(int *)(DAT_00632d3c + 0xc) + iVar4);

      iVar3 = iVar3 + 1;

      iVar4 = iVar4 + 0xc;

      *(float *)(*(int *)(DAT_00632d3c + 0x10) + -8 + iVar3 * 8) = (1.0 / param_1) * *pfVar1;

      *(float *)(*(int *)(DAT_00632d3c + 0x10) + -4 + iVar3 * 8) =

           (1.0 / param_1) * *(float *)(*(int *)(DAT_00632d3c + 0xc) + -8 + iVar4);

    } while (iVar3 < *(int *)(DAT_00632d3c + 4));

  }

  DAT_005566f8 = 0;

  return;

}

/* ===== main_drawwatr_00431700 @ 0x00431700 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void main_drawwatr_00431700(void)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  int iVar8;

  short *psVar9;

  float *pfVar10;

  float *pfVar11;

  undefined4 uVar12;

  int iVar13;

  undefined4 *puVar14;

  short sVar15;

  undefined4 *puVar16;

  float *pfVar17;

  int iVar18;

  undefined4 *puVar19;

  float fStack_70;

  int iStack_6c;

  int iStack_68;

  float afStack_54 [6];

  float fStack_3c;

  undefined4 uStack_34;

  float fStack_30;

  float fStack_2c;

  float fStack_28;

  float fStack_24;

  float fStack_20;

  float fStack_1c;

  float fStack_18;

  char *pcStack_14;

  char *pcStack_10;

  

  pcStack_10 = (char *)0x43170f;

  (**(code **)((int)DAT_00656420 + 0x18))();

  pcStack_10 = (char *)0x1;

  pcStack_14 = (char *)DAT_00656430;

  fStack_18 = 6.161266e-39;

  (**(code **)((int)DAT_00656430 + 0xc))();

  fStack_18 = 1.4013e-45;

  fStack_1c = DAT_00656430;

  fStack_20 = 6.161281e-39;

  (**(code **)((int)DAT_00656430 + 0x10))();

  iVar13 = DAT_006330e4;

  if (DAT_006331b0 == 0) {

    if (*(int *)(DAT_006330e4 + 0x50b8) == 0) {

      _DAT_0059c9d0 = 0;

      DAT_0059ca00 = 0x3f800000;

      iStack_6c = 1;

      do {

        fVar2 = (float)iStack_6c;

        iStack_6c = iStack_6c + 1;

        *(float *)(iStack_6c * 4 + 0x59c9cc) = ((fVar2 - 1.0) - 5.0) * 0.1 * 0.25 + 0.5;

      } while (iStack_6c < 0xc);

      iVar18 = 0;

      do {

        fStack_70 = (float)(iVar18 + -0x10) * *(float *)(iVar13 + 0x50ac) * 0.09817477;

        if (-1.5707964 <= fStack_70) {

          if (1.5707964 < fStack_70) {

            fStack_70 = 1.5707964;

          }

        }

        else {

          fStack_70 = -1.5707964;

        }

        fcos((float10)fStack_70);

        FUN_00543e70();

        iVar8 = __ftol();

        (&DAT_0059ca08)[iVar18] = iVar8 << 0x18 | *(uint *)(iVar13 + 0x50a0);

        iVar18 = iVar18 + 1;

      } while (iVar18 < 0x21);

      psVar9 = &DAT_0059b7d0;

      iVar18 = 0;

      do {

        iVar8 = 0;

        do {

          sVar15 = (short)iVar18 + (short)iVar8;

          *psVar9 = sVar15;

          psVar9[1] = sVar15 + 1;

          psVar9[2] = sVar15 + 0x21;

          psVar9[3] = sVar15 + 1;

          psVar9[4] = sVar15 + 0x22;

          psVar9[5] = sVar15 + 0x21;

          psVar9 = psVar9 + 6;

          iVar8 = iVar8 + 1;

        } while (iVar8 < 0x20);

        iVar18 = iVar18 + 0x21;

      } while (iVar18 < 0x18c);

      *(undefined4 *)(iVar13 + 0x50b8) = 1;

    }

    fVar2 = 1.0 / *(float *)(DAT_006330e4 + 0x7c);

    fVar3 = *(float *)(DAT_006330e4 + 0x50a8) * 0.5;

    pfVar10 = (float *)FUN_00515db0();

    fStack_30 = *pfVar10;

    fStack_2c = pfVar10[1];

    fStack_28 = 0.0;

    fStack_24 = *(float *)(DAT_006330e4 + 0x4f60);

    fStack_20 = *(float *)(DAT_006330e4 + 0x4f64);

    fStack_1c = 0.0;

    FUN_0050a810(&fStack_24,&fStack_20,&fStack_1c);

    fStack_24 = fStack_24 * 12500.0;

    fStack_20 = fStack_20 * 12500.0;

    fStack_1c = fStack_1c * 12500.0;

    fVar4 = fStack_24 - fStack_30;

    afStack_54[3] = fStack_20 - fStack_2c;

    fVar6 = fStack_1c - fStack_28;

    fVar5 = SQRT(fVar4 * fVar4 + afStack_54[3] * afStack_54[3] + fVar6 * fVar6);

    fVar1 = 1.0 / fVar5;

    fVar4 = fVar1 * fVar4;

    afStack_54[3] = fVar1 * afStack_54[3];

    fVar7 = fVar1 * fVar6 * fStack_28 + fVar4 * fStack_30 + afStack_54[3] * fStack_2c;

    fVar5 = fVar7 + fVar7 + fVar5;

    fStack_30 = fStack_30 - fVar4 * fVar5;

    fStack_2c = fStack_2c - fVar5 * afStack_54[3];

    fStack_28 = fStack_28 - fVar5 * fVar1 * fVar6;

    afStack_54[3] = -afStack_54[3];

    (**(code **)((int)DAT_00656420 + 0x10))(DAT_00656420);

    afStack_54[0] = 0.0;

    afStack_54[1] = 0.0;

    afStack_54[2] = 0.0;

    (**(code **)((int)DAT_00656420 + 0xac))

              (DAT_00656420,*(undefined4 *)(DAT_006330e4 + 0x140),

               *(undefined4 *)(DAT_006330e4 + 0x144),afStack_54);

    pcStack_10 = (char *)((DAT_00632e94 & 0x800) << 4 | 0x71134);

    fStack_18 = (float)((*(int *)(DAT_006330e4 + 0x503c) + 0x282) * 0x20 + DAT_006330e4);

    pcStack_14 = (char *)0x0;

    if ((0 < DAT_00633244) && ((*(byte *)(DAT_006330e4 + 0x4ebf) & 0x40) != 0)) {

      pcStack_14 = (char *)(DAT_006330e4 + 0x4ea0);

    }

    (**(code **)((int)DAT_00656430 + 0x14))(DAT_00656430,&fStack_18);

    pfVar10 = (float *)(**(code **)((int)DAT_0065644c + 0x10))(DAT_0065644c,0x1ad);

    pfVar17 = (float *)&DAT_0059ca00;

    do {

      iStack_68 = 0;

      pfVar11 = pfVar10;

      do {

        fVar1 = *pfVar17;

        pfVar10 = pfVar11 + 6;

        iVar13 = iStack_68 + 1;

        fStack_3c = fVar1 * fStack_24 + fStack_30 * (1.0 - fVar1);

        pfVar11[2] = 0.0;

        afStack_54[0] =

             (fStack_3c - afStack_54[3] * fVar3) + afStack_54[3] * (float)iStack_68 * 0.0625 * fVar3

        ;

        *pfVar11 = afStack_54[0];

        fVar1 = (float)iStack_68 * 0.0625 * fVar4 * fVar3 +

                ((fVar1 * fStack_20 + (1.0 - fVar1) * fStack_2c) - fVar4 * fVar3);

        pfVar11[1] = fVar1;

        pfVar11[3] = *(float *)(iVar13 * 4 + 0x59ca04);

        pfVar11[4] = afStack_54[0] * fVar2;

        pfVar11[5] = fVar1 * fVar2;

        pfVar11 = pfVar10;

        iStack_68 = iVar13;

      } while (iVar13 < 0x21);

      pfVar17 = pfVar17 + -1;

    } while (0x59c9cf < (int)pfVar17);

    (**(code **)((int)DAT_0065644c + 0x18))(DAT_0065644c,0);

    (**(code **)((int)DAT_0065644c + 0x20))(DAT_0065644c,0x900,&DAT_0059b7d0);

    (**(code **)((int)DAT_00656420 + 0x10))(DAT_00656420);

    (**(code **)((int)DAT_00656420 + 0xac))

              (DAT_00656420,*(undefined4 *)(DAT_006330e4 + 0x128),

               *(undefined4 *)(DAT_006330e4 + 300),DAT_006330e4 + 0x130);

    return;

  }

  if (DAT_005566f8 != 0) {

    fVar2 = *(float *)(DAT_006330e4 + 0x7c);

    if (*(int *)(DAT_00632d3c + 0x10) == 0) {

      pcStack_10 = s_C__Giants_source_main_drawwatr_c_00556748;

      pcStack_14 = s_seauv_00556740;

      fStack_18 = (float)(*(int *)(DAT_00632d3c + 4) << 3);

      fStack_1c = 1.26117e-44;

      fStack_20 = 6.161394e-39;

      uVar12 = FUN_0053a700();

      *(undefined4 *)(DAT_00632d3c + 0x10) = uVar12;

    }

    fVar2 = 1.0 / fVar2;

    iVar13 = 0;

    if (0 < *(int *)(DAT_00632d3c + 4)) {

      iVar18 = 0;

      do {

        pfVar10 = (float *)(*(int *)(DAT_00632d3c + 0xc) + iVar18);

        iVar13 = iVar13 + 1;

        iVar18 = iVar18 + 0xc;

        *(float *)(*(int *)(DAT_00632d3c + 0x10) + -8 + iVar13 * 8) = fVar2 * *pfVar10;

        *(float *)(*(int *)(DAT_00632d3c + 0x10) + -4 + iVar13 * 8) =

             fVar2 * *(float *)(*(int *)(DAT_00632d3c + 0xc) + -8 + iVar18);

      } while (iVar13 < *(int *)(DAT_00632d3c + 4));

    }

    DAT_005566f8 = 0;

  }

  iVar13 = 0;

  if (0 < *(int *)(DAT_00632d3c + 4)) {

    do {

      pfVar10 = (float *)(*(int *)(DAT_00632d3c + 0x10) + iVar13 * 8);

      *pfVar10 = DAT_006328e0 * *(float *)(DAT_006330e4 + 0x80) + *pfVar10;

      pfVar10 = (float *)(*(int *)(DAT_00632d3c + 0x10) + 4 + iVar13 * 8);

      iVar13 = iVar13 + 1;

      *pfVar10 = DAT_006328e0 * *(float *)(DAT_006330e4 + 0x80) + *pfVar10;

    } while (iVar13 < *(int *)(DAT_00632d3c + 4));

  }

  if ((100.0 < *(float *)(*(int *)(DAT_00632d3c + 0x10) + 4)) &&

     (iVar13 = 0, 0 < *(int *)(DAT_00632d3c + 4))) {

    do {

      *(float *)(*(int *)(DAT_00632d3c + 0x10) + iVar13 * 8) =

           *(float *)(*(int *)(DAT_00632d3c + 0x10) + iVar13 * 8) - 100.0;

      iVar18 = iVar13 * 8;

      iVar8 = iVar13 * 8;

      iVar13 = iVar13 + 1;

      *(float *)(*(int *)(DAT_00632d3c + 0x10) + 4 + iVar8) =

           *(float *)(*(int *)(DAT_00632d3c + 0x10) + 4 + iVar18) - 100.0;

    } while (iVar13 < *(int *)(DAT_00632d3c + 4));

  }

  pcStack_10 = *(char **)(DAT_006330e4 + 0x144);

  pcStack_14 = *(char **)(DAT_006330e4 + 0x140);

  fStack_18 = DAT_00656420;

  fStack_1c = 6.161862e-39;

  (**(code **)((int)DAT_00656420 + 0xac))();

  iVar13 = DAT_006330e4;

  fStack_1c = 6.161903e-39;

  iVar18 = __ftol();

  fStack_1c = (float)(iVar18 << 0x18);

  fStack_20 = *(float *)(iVar13 + 0x74);

  fStack_24 = 3.67774e-40;

  fStack_28 = DAT_00656430;

  fStack_2c = 6.161934e-39;

  (**(code **)((int)DAT_00656430 + 8))();

  fStack_2c = *(float *)(DAT_00632d3c + 4);

  fStack_30 = DAT_0065644c;

  uStack_34 = 0x43190a;

  puVar14 = (undefined4 *)(**(code **)((int)DAT_0065644c + 0x10))();

  puVar19 = *(undefined4 **)(DAT_00632d3c + 0x10);

  puVar16 = *(undefined4 **)(DAT_00632d3c + 0xc);

  iVar13 = *(int *)(DAT_00632d3c + 4);

  if (0 < iVar13) {

    do {

      *puVar14 = *puVar16;

      puVar14[1] = puVar16[1];

      puVar14[2] = puVar16[2];

      puVar14[4] = *puVar19;

      puVar14[5] = puVar19[1];

      puVar14[3] = 0xffffff;

      puVar16 = puVar16 + 3;

      puVar19 = puVar19 + 2;

      puVar14 = puVar14 + 6;

      iVar13 = iVar13 + -1;

    } while (iVar13 != 0);

  }

  pcStack_10 = (char *)DAT_0065644c;

  pcStack_14 = (char *)0x43195b;

  (**(code **)((int)DAT_0065644c + 0x18))();

  pcStack_14 = *(char **)(DAT_00632d3c + 0x18);

  fStack_18 = (float)(*(int *)(DAT_00632d3c + 8) * 3);

  fStack_1c = DAT_0065644c;

  fStack_20 = 6.162109e-39;

  (**(code **)((int)DAT_0065644c + 0x20))();

  fStack_20 = DAT_00656420;

  fStack_24 = 6.162122e-39;

  (**(code **)((int)DAT_00656420 + 0x10))();

  pcStack_10 = *(char **)(DAT_006330e4 + 300);

  pcStack_14 = *(char **)(DAT_006330e4 + 0x128);

  fStack_18 = DAT_00656420;

  fStack_1c = 6.16219e-39;

  (**(code **)((int)DAT_00656420 + 0xac))();

  return;

}

