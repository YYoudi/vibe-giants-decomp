/* Giants 1.449 — module main/marker
 * 1 functions (1 named) — decompiled, names from PS2 symbols
 * Original source: C:\Giants\source\main/marker.c(pp) (assert-string evidence)
 */

/* ===== marker_create_path__FP6OBJECTi @ 0x004776C0 ===== */
void marker_create_path__FP6OBJECTi(int param_1,int param_2)



{

  float *pfVar1;

  float *pfVar2;

  int *piVar3;

  int iVar4;

  int *piVar5;

  undefined4 uVar6;

  int iVar7;

  int *piVar8;

  int iVar9;

  int iVar10;

  float *pfVar11;

  int *piVar12;

  bool bVar13;

  int local_1dc;

  int local_1d4;

  int local_1d0;

  int local_1c4 [4];

  undefined4 local_1b4;

  undefined4 local_1b0;

  undefined4 local_1ac;

  int local_1a8;

  int local_19c;

  int local_190 [100];

  

  if (param_1 == 0) {

    return;

  }

  piVar3 = *(int **)(param_1 + 0x100);

  if (piVar3[0x10] != param_1) {

    return;

  }

  piVar8 = local_190;

  for (iVar7 = 100; iVar7 != 0; iVar7 = iVar7 + -1) {

    *piVar8 = 0;

    piVar8 = piVar8 + 1;

  }

  iVar7 = 0;

  local_1d0 = 0;

  piVar8 = DAT_00632d68;

  if (DAT_00632d68 != (int *)0x0) {

    do {

      iVar9 = piVar8[3];

      if (((((*(uint *)(iVar9 + 0x1c8) & 0x8000000) != 0) &&

           ((*(uint *)(iVar9 + 0x1c8) & 0x20000000) != 0)) &&

          (*(int *)(iVar9 + 0xe8) == *(int *)(param_1 + 0xe8))) &&

         ((-1 < (char)((uint)*(undefined4 *)(iVar9 + 0xd8) >> 8) &&

          (*(int *)(param_1 + 4) == *(int *)(iVar9 + 4))))) {

        local_190[*(int *)(iVar9 + 0x174)] = iVar9;

        iVar7 = iVar7 + 1;

      }

      piVar8 = (int *)*piVar8;

    } while (piVar8 != (int *)0x0);

    local_1d0 = iVar7;

    if (0x61 < iVar7) {

      return;

    }

  }

  if ((local_1d0 + 1 == piVar3[0xf]) && (param_2 == 0)) {

    return;

  }

  piVar3[0xf] = local_1d0 + 1;

  if (*piVar3 != 0) {

    FUN_0053ff60(*piVar3);

  }

  mem_free_tagged(piVar3[0x11],s_C__Giants_source_main_marker_c_0055bc18,0x19e);

  *piVar3 = 0;

  piVar3[1] = 0;

  piVar3[0x11] = 0;

  if (piVar3[0xf] < 4) {

    return;

  }

  iVar7 = FUN_0053feb0(0,0);

  *piVar3 = iVar7;

  iVar7 = FUN_0053d8d0(iVar7,piVar3[0xf],5);

  piVar3[1] = iVar7;

  iVar7 = FUN_0053a700(0x14,piVar3[0xf] << 2,s_spline_objs_0055bc38,

                       s_C__Giants_source_main_marker_c_0055bc18,0x1aa);

  piVar3[0x11] = iVar7;

  iVar7 = 0;

  local_1dc = 0;

  piVar3[2] = 0;

  if (0 < local_1d0) {

    piVar8 = local_190;

    local_1d4 = 1;

    do {

      if (99 < local_1d4 + -1) break;

      if (*piVar8 != 0) {

        iVar9 = local_1d4 + -2;

        while( true ) {

          if (iVar9 < 0) {

            iVar9 = 99;

          }

          iVar10 = local_1d4;

          if (local_190[iVar9] != 0) break;

          iVar9 = iVar9 + -1;

        }

        while( true ) {

          if (99 < iVar10) {

            iVar10 = 0;

          }

          if (local_190[iVar10] != 0) break;

          iVar10 = iVar10 + 1;

        }

        iVar10 = local_190[iVar10];

        *(int *)(piVar3[0x11] + iVar7 * 4) = *piVar8;

        iVar4 = *(int *)(*(int *)(piVar3[0x11] + iVar7 * 4) + 0x100);

        piVar12 = *(int **)(piVar3[1] + 0xc + iVar7 * 4);

        iVar7 = local_190[iVar9];

        piVar12[2] = (int)(*(float *)(iVar7 + 0xa0) - *(float *)(iVar10 + 0xa0));

        piVar12[3] = (int)(*(float *)(iVar7 + 0xa4) - *(float *)(iVar10 + 0xa4));

        piVar12[4] = (int)(*(float *)(iVar7 + 0xa8) - *(float *)(iVar10 + 0xa8));

        FUN_0050a810(piVar12 + 2,piVar12 + 3,piVar12 + 4);

        *(int *)(iVar4 + 0x20) = piVar12[2];

        *(int *)(iVar4 + 0x24) = piVar12[3];

        *(int *)(iVar4 + 0x28) = piVar12[4];

        piVar12[2] = (int)(*(float *)(iVar4 + 0x10) * (float)piVar12[2]);

        piVar12[3] = (int)((float)piVar12[3] * *(float *)(iVar4 + 0x10));

        piVar12[4] = (int)((float)piVar12[4] * *(float *)(iVar4 + 0x10));

        piVar12[5] = (int)(*(float *)(iVar10 + 0xa0) - *(float *)(iVar7 + 0xa0));

        piVar12[6] = (int)(*(float *)(iVar10 + 0xa4) - *(float *)(iVar7 + 0xa4));

        piVar12[7] = (int)(*(float *)(iVar10 + 0xa8) - *(float *)(iVar7 + 0xa8));

        FUN_0050a810(piVar12 + 5,piVar12 + 6,piVar12 + 7);

        *(int *)(iVar4 + 0x2c) = piVar12[5];

        iVar9 = *piVar8;

        *(int *)(iVar4 + 0x30) = piVar12[6];

        *(int *)(iVar4 + 0x34) = piVar12[7];

        piVar12[5] = (int)(*(float *)(iVar4 + 0x14) * (float)piVar12[5]);

        piVar12[6] = (int)(*(float *)(iVar4 + 0x14) * (float)piVar12[6]);

        piVar12[7] = (int)((float)piVar12[7] * *(float *)(iVar4 + 0x14));

        piVar12[8] = *(int *)(iVar9 + 0xa0);

        piVar12[9] = *(int *)(iVar9 + 0xa4);

        piVar12[10] = *(int *)(iVar9 + 0xa8);

        if (local_1dc == 0) {

          *piVar12 = 0;

        }

        else {

          piVar5 = *(int **)(piVar3[1] + 8 + local_1dc * 4);

          FUN_0050a580(iVar9 + 0xa0,(float *)(iVar7 + 0xa0));

          iVar7 = __ftol();

          iVar7 = iVar7 + *piVar5;

          *piVar12 = iVar7;

          if (iVar7 == *piVar5) {

            *piVar12 = iVar7 + 1;

          }

        }

        iVar7 = local_1dc + 1;

        piVar12[1] = 0;

        local_1dc = iVar7;

      }

      local_1d4 = local_1d4 + 1;

      piVar8 = piVar8 + 1;

    } while (iVar7 < local_1d0);

  }

  iVar7 = 0;

  if (0 < local_1d0) {

    do {

      iVar9 = *(int *)(piVar3[0x11] + iVar7 * 4);

      iVar10 = *(int *)(iVar9 + 0x100);

      piVar8 = DAT_00632d68;

      if (*(int *)(iVar10 + 0x40) == 0) {

        for (; piVar8 != (int *)0x0; piVar8 = (int *)*piVar8) {

          iVar4 = piVar8[3];

          if (((((*(uint *)(iVar4 + 0x1c8) & 0x8000000) != 0) &&

               ((*(uint *)(iVar4 + 0x1c8) & 0x20000000) != 0)) &&

              (*(int *)(iVar4 + 0xe8) == *(int *)(iVar9 + 0xe8))) &&

             (((*(int *)(iVar4 + 0xe8) != 0 && (*(int *)(iVar4 + 0x174) == 0)) &&

              ((-1 < (char)((uint)*(undefined4 *)(iVar4 + 0xd8) >> 8) &&

               (*(int *)(iVar9 + 4) == *(int *)(iVar4 + 4))))))) {

            *(int *)(iVar10 + 0x40) = iVar4;

            break;

          }

        }

      }

      uVar6 = *(undefined4 *)(iVar10 + 0x18);

      *(undefined4 *)(iVar10 + 0x18) = 0;

      FUN_00477f20(*(undefined4 *)(piVar3[0x11] + iVar7 * 4),uVar6,1);

      uVar6 = *(undefined4 *)(iVar10 + 0x1c);

      *(undefined4 *)(iVar10 + 0x1c) = 0;

      FUN_00477f20(*(undefined4 *)(piVar3[0x11] + iVar7 * 4),uVar6,0);

      iVar7 = iVar7 + 1;

    } while (iVar7 < local_1d0);

  }

  *(int *)(piVar3[0x11] + -4 + piVar3[0xf] * 4) = param_1;

  iVar7 = piVar3[1];

  iVar9 = *(int *)(iVar7 + 0xc);

  piVar8 = *(int **)(iVar7 + 0xc + local_1d0 * 4);

  piVar12 = *(int **)(iVar7 + 8 + local_1d0 * 4);

  piVar8[2] = *(int *)(iVar9 + 8);

  piVar8[3] = *(int *)(iVar9 + 0xc);

  piVar8[4] = *(int *)(iVar9 + 0x10);

  piVar8[5] = *(int *)(iVar9 + 0x14);

  piVar8[6] = *(int *)(iVar9 + 0x18);

  piVar8[7] = *(int *)(iVar9 + 0x1c);

  piVar8[8] = *(int *)(iVar9 + 0x20);

  piVar8[9] = *(int *)(iVar9 + 0x24);

  piVar8[10] = *(int *)(iVar9 + 0x28);

  FUN_0050a580(piVar12 + 8,piVar8 + 8);

  iVar7 = __ftol();

  iVar7 = iVar7 + *piVar12;

  *piVar8 = iVar7;

  if (iVar7 == *piVar12) {

    *piVar8 = iVar7 + 1;

  }

  piVar8[1] = 0;

  piVar3[2] = *piVar8;

  piVar12 = local_190;

  for (iVar7 = 100; iVar7 != 0; iVar7 = iVar7 + -1) {

    *piVar12 = 0;

    piVar12 = piVar12 + 1;

  }

  local_1ac = 0;

  local_1a8 = *piVar8;

  iVar7 = 1;

  local_19c = 0;

  FUN_0053d940(piVar3[1],&local_1ac,local_1c4 + 3);

  local_1dc = 0;

  do {

    local_1a8 = piVar3[2];

    local_19c = local_1dc;

    local_1ac = 0;

    FUN_0053d940(piVar3[1],&local_1ac,local_1c4);

    FUN_0050a580(local_1c4 + 3,local_1c4);

    iVar9 = __ftol();

    local_190[iVar7] = local_190[iVar7] + iVar9;

    local_1c4[3] = local_1c4[0];

    local_1b4 = local_1c4[1];

    local_1b0 = local_1c4[2];

    iVar9 = 3;

    bVar13 = true;

    piVar8 = local_1c4;

    piVar12 = (int *)(*(int *)(piVar3[0x11] + iVar7 * 4) + 0xa0);

    do {

      if (iVar9 == 0) break;

      iVar9 = iVar9 + -1;

      bVar13 = *piVar8 == *piVar12;

      piVar8 = piVar8 + 1;

      piVar12 = piVar12 + 1;

    } while (bVar13);

    if ((bVar13) && (iVar7 = iVar7 + 1, local_1d0 < iVar7)) {

      piVar3[2] = 0;

      piVar3[3] = 0;

      **(undefined4 **)(piVar3[1] + 0xc) = 0;

      iVar7 = 1;

      if (1 < piVar3[0xf]) {

        do {

          if (local_190[iVar7] == 0) {

            local_190[iVar7] = 1;

          }

          iVar9 = local_190[iVar7];

          **(int **)(iVar7 * 4 + 0xc + piVar3[1]) = piVar3[2] + iVar9;

          piVar3[2] = piVar3[2] + iVar9;

          if (iVar7 < piVar3[0xf] + -1) {

            piVar3[3] = piVar3[3] + iVar9;

          }

          iVar7 = iVar7 + 1;

        } while (iVar7 < piVar3[0xf]);

      }

      iVar7 = piVar3[0xf];

      local_1dc = 0;

      if (0 < iVar7) {

        do {

          iVar9 = *(int *)(*(int *)(piVar3[0x11] + local_1dc * 4) + 0x100);

          piVar8 = *(int **)(piVar3[1] + 0xc + local_1dc * 4);

          if (local_1dc != iVar7 + -1) {

            *(int *)(iVar9 + 0x50) = *piVar8;

          }

          pfVar1 = (float *)(piVar8 + 4);

          *piVar8 = *piVar8 * 1000;

          FUN_0050a810(piVar8 + 2,piVar8 + 3,pfVar1);

          pfVar2 = (float *)(piVar8 + 6);

          piVar8[2] = (int)(*(float *)(iVar9 + 0x10) * (float)piVar8[2] * 0.001);

          piVar8[3] = (int)((float)piVar8[3] * *(float *)(iVar9 + 0x10) * 0.001);

          *pfVar1 = *pfVar1 * *(float *)(iVar9 + 0x10) * 0.001;

          pfVar1 = (float *)(piVar8 + 7);

          pfVar11 = (float *)(piVar8 + 5);

          FUN_0050a810(pfVar11,pfVar2,pfVar1);

          local_1dc = local_1dc + 1;

          *pfVar11 = *(float *)(iVar9 + 0x14) * *pfVar11 * 0.001;

          *pfVar2 = *(float *)(iVar9 + 0x14) * *pfVar2 * 0.001;

          *pfVar1 = *(float *)(iVar9 + 0x14) * *pfVar1 * 0.001;

          iVar7 = piVar3[0xf];

        } while (local_1dc < iVar7);

      }

      piVar3[2] = piVar3[2] * 1000;

      piVar3[3] = piVar3[3] * 1000;

      FUN_00477340(param_1);

      return;

    }

    local_1dc = local_1dc + 1;

  } while( true );

}

