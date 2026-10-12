/* Giants 1.449 — module game/water
 * 2 functions (2 named) — decompiled, names from PS2 symbols
 * Original source: C:\Giants\source\game/water.c(pp) (assert-string evidence)
 */

/* ===== game_water_00513be0 @ 0x00513BE0 ===== */
undefined4 * game_water_00513be0(int param_1,int param_2)



{

  short sVar1;

  short sVar2;

  uint uVar3;

  undefined4 *puVar4;

  int iVar5;

  uint uVar6;

  int iVar7;

  short *psVar8;

  short sVar9;

  short sVar10;

  uint uVar11;

  uint uVar12;

  short sVar13;

  undefined4 *puVar14;

  int iVar15;

  uint local_14;

  

  if (DAT_005dccd0 == 0) {

    DAT_006328f8 = &DAT_006328f8;

    DAT_006328fc = &DAT_006328f8;

    DAT_005dccd0 = 1;

  }

  uVar12 = param_1 + 1U & 0xfffffffe;

  uVar11 = param_2 + 1U & 0xfffffffe;

  uVar3 = uVar12 * uVar11;

  puVar4 = (undefined4 *)

           FUN_0053a270(0x28,(uVar12 * 0xc + -0xc) * (uVar11 - 1) + 0x4c + uVar3 * 0x10,

                        s__C__Giants_source_game_water_c_0057c097 + 1,0x35);

  puVar14 = puVar4;

  for (iVar7 = 0x13; iVar7 != 0; iVar7 = iVar7 + -1) {

    *puVar14 = 0;

    puVar14 = puVar14 + 1;

  }

  puVar4[1] = puVar4;

  *puVar4 = puVar4;

  puVar4[1] = DAT_006328fc;

  *puVar4 = &DAT_006328f8;

  DAT_006328fc = puVar4;

  *(undefined4 **)puVar4[1] = puVar4;

  puVar14 = puVar4 + 0x13;

  puVar4[9] = puVar14 + uVar3 * 4;

  puVar4[8] = puVar14;

  puVar4[2] = uVar12;

  puVar4[3] = uVar11;

  puVar4[4] = 0;

  puVar4[5] = 0x3f800000;

  puVar4[6] = 0x41000000;

  puVar4[7] = 0x3f4ccccd;

  puVar4[0xf] = 0x3d23d70a;

  for (iVar7 = (uVar3 & 0xfffffff) << 2; iVar7 != 0; iVar7 = iVar7 + -1) {

    *puVar14 = 0;

    puVar14 = puVar14 + 1;

  }

  for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {

    *(undefined1 *)puVar14 = 0;

    puVar14 = (undefined4 *)((int)puVar14 + 1);

  }

  psVar8 = (short *)puVar4[9];

  iVar7 = puVar4[8];

  sVar2 = (short)uVar12;

  if (0 < (int)uVar11) {

    iVar5 = uVar11 + 1;

    do {

      if (0 < (int)uVar12) {

        sVar1 = (short)((iVar5 + -1) % (int)uVar11) * sVar2;

        uVar3 = uVar12;

        iVar15 = iVar7;

        local_14 = uVar12;

        do {

          iVar7 = iVar15 + 0x10;

          sVar13 = (short)((int)uVar3 % (int)uVar12);

          *(short *)(iVar15 + 8) = (short)((iVar5 + -2) % (int)uVar11) * sVar2 + sVar13;

          *(short *)(iVar15 + 10) = (short)((int)(uVar3 - 1) % (int)uVar12) + sVar1;

          *(short *)(iVar15 + 0xc) = (short)((int)(uVar3 + 1) % (int)uVar12) + sVar1;

          *(short *)(iVar15 + 0xe) = (short)(iVar5 % (int)uVar11) * sVar2 + sVar13;

          local_14 = local_14 - 1;

          uVar3 = uVar3 + 1;

          iVar15 = iVar7;

        } while (local_14 != 0);

      }

      iVar5 = iVar5 + 1;

    } while ((int)((-1 - uVar11) + iVar5) < (int)uVar11);

  }

  uVar3 = 0;

  if (0 < (int)(uVar11 - 1)) {

    do {

      uVar6 = 0;

      if (uVar12 != 1 && -1 < (int)(uVar12 - 1)) {

        do {

          sVar1 = (short)uVar6;

          sVar13 = (short)uVar3;

          switch((uVar3 & 1) * 2 + (uVar6 & 1)) {

          case 0:

          case 3:

            sVar9 = sVar1 + sVar13 * sVar2;

            *psVar8 = sVar9;

            sVar10 = (sVar13 + 1) * sVar2;

            psVar8[1] = sVar10 + sVar1;

            sVar10 = sVar1 + 1 + sVar10;

            psVar8[2] = sVar10;

            psVar8[3] = sVar9;

            sVar13 = sVar1 + 1 + sVar13 * sVar2;

            break;

          case 1:

          case 2:

            *psVar8 = sVar1 + sVar13 * sVar2;

            sVar10 = (sVar13 + 1) * sVar2;

            sVar9 = sVar10 + sVar1;

            psVar8[1] = sVar9;

            sVar13 = sVar1 + 1 + sVar13 * sVar2;

            psVar8[2] = sVar13;

            psVar8[3] = sVar9;

            sVar10 = sVar1 + 1 + sVar10;

            break;

          default:

            goto switchD_00513dc3_default;

          }

          psVar8[4] = sVar10;

          psVar8[5] = sVar13;

          psVar8 = psVar8 + 6;

switchD_00513dc3_default:

          uVar6 = uVar6 + 1;

        } while ((int)uVar6 < (int)(uVar12 - 1));

      }

      uVar3 = uVar3 + 1;

    } while ((int)uVar3 < (int)(uVar11 - 1));

  }

  puVar14 = (undefined4 *)puVar4[8];

  for (iVar7 = puVar4[3] * puVar4[2]; iVar7 != 0; iVar7 = iVar7 + -1) {

    *puVar14 = 0;

    puVar14[1] = 0;

    puVar14 = puVar14 + 4;

  }

  puVar4[0xe] = 0;

  return puVar4;

}

/* ===== game_water_00513eb0 @ 0x00513EB0 ===== */
void game_water_00513eb0(int *param_1)



{

  if (param_1 != (int *)0x0) {

    *(int *)param_1[1] = *param_1;

    *(int *)(*param_1 + 4) = param_1[1];

    *param_1 = (int)param_1;

    param_1[1] = (int)param_1;

    mem_free_tagged(param_1,s__C__Giants_source_game_water_c_0057c097 + 1,0xa9);

  }

  return;

}

