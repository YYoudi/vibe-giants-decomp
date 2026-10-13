/* Giants 1.449 — module Main/kabuto
 * 1 functions (1 named) — decompiled, names from PS2 symbols
 * Original source: C:\Giants\source\Main/kabuto.c(pp) (assert-string evidence)
 */

/* ===== kabuto_laser_texture_init @ 0x00467270 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* PS2 candidate: kabuto_laser_texture_init (conf 0.85) */



undefined4 *

kabuto_laser_texture_init(undefined4 param_1,int param_2,int param_3,undefined4 param_4)



{

  float fVar1;

  int iVar2;

  undefined4 *puVar3;

  int *piVar4;

  int iVar5;

  int iVar6;

  uint uVar7;

  float *pfVar8;

  int *piVar9;

  int iVar10;

  undefined4 *puVar11;

  int iVar12;

  int *local_1c;

  int local_14;

  

  iVar2 = ((param_3 + -1) * 6 + 3) * param_2;

  iVar10 = param_2 * param_3 + 1;

  puVar3 = (undefined4 *)

           MemAllocMsg(0xe,(iVar10 * 0x10 + iVar2) * 2 + 0x5c,&DAT_0055b400,

                       s_C__Giants_source_Main_kabuto_c_0055b318,0x1eb0);

  puVar11 = puVar3;

  for (iVar6 = 0x17; iVar6 != 0; iVar6 = iVar6 + -1) {

    *puVar11 = 0;

    puVar11 = puVar11 + 1;

  }

  if (DAT_0059da1c == 0) {

    DAT_00632a80 = &DAT_00632a80;

    DAT_00632a84 = &DAT_00632a80;

    if ((~DAT_00632a7e & 0x4000) != 0) {

      piVar4 = (int *)MemAllocMsg(0xe,0x2000,s_Laser_texture_data_0055b3ec,

                                  s_C__Giants_source_Main_kabuto_c_0055b318,0x1ec1);

      local_14 = 0x80;

      local_1c = piVar4;

      do {

        iVar6 = rndintrange(0xffffffc0,0x20);

        iVar12 = 0;

        piVar9 = local_1c;

        do {

          iVar5 = __ftol();

          uVar7 = -iVar5 - iVar6;

          if ((int)uVar7 < 0) {

            uVar7 = 0;

          }

          else if (0xff < (int)uVar7) {

            uVar7 = 0xff;

          }

          iVar12 = iVar12 + 1;

          *piVar9 = (uVar7 ^ 0xff) << 0x10;

          piVar9 = piVar9 + 0x80;

        } while (iVar12 < 0x10);

        local_1c = local_1c + 1;

        local_14 = local_14 + -1;

      } while (local_14 != 0);

      _DAT_00632a60 = s_laser_texture_0055b3dc;

      _DAT_00632a68 = 0;

      _DAT_00632a6c = 7;

      _DAT_00632a70 = 4;

      _DAT_00632a78 = 0;

      _DAT_00632a74 = 0;

      DAT_00632a7d = 0;

      DAT_00632a7c = 0x7f;

      DAT_00632a7e = 0;

      DAT_00632a64 = piVar4;

    }

    DAT_0059da1c = 1;

  }

  puVar3[1] = puVar3;

  *puVar3 = puVar3;

  puVar3[1] = DAT_00632a84;

  *puVar3 = &DAT_00632a80;

  DAT_00632a84 = puVar3;

  *(undefined4 **)puVar3[1] = puVar3;

  puVar3[7] = iVar2;

  puVar3[2] = param_1;

  puVar3[6] = iVar10;

  puVar11 = puVar3 + 0x17;

  puVar3[9] = puVar11;

  puVar3[8] = puVar11 + iVar10 * 8;

  puVar3[3] = param_2;

  puVar3[4] = param_3;

  puVar3[5] = param_4;

  fx_arc_math(puVar11 + iVar10 * 8,puVar11,param_2,param_3,param_4,0x3f800000,2,0x3f800000,

              0xbf800000);

  if (0 < param_2) {

    iVar2 = 0;

    iVar6 = (param_3 + -1) * param_2 * 0x20;

    do {

      iVar10 = iVar2 + 0x3c;

      iVar12 = iVar2 + 0x3c;

      iVar2 = iVar2 + 0x20;

      *(float *)(iVar12 + puVar3[9]) = *(float *)(iVar10 + puVar3[9]) + 0.03125;

      iVar10 = iVar6 + 0x3c;

      iVar12 = iVar6 + 0x3c;

      iVar6 = iVar6 + 0x20;

      param_2 = param_2 + -1;

      *(float *)(iVar12 + puVar3[9]) = *(float *)(iVar10 + puVar3[9]) - 0.03125;

    } while (param_2 != 0);

  }

  iVar2 = 0;

  pfVar8 = (float *)puVar3[9];

  if (0 < (int)puVar3[6]) {

    do {

      fVar1 = 1.0 - pfVar8[2];

      if (fVar1 < 0.1) {

        fVar1 = 0.1;

      }

      iVar2 = iVar2 + 1;

      *pfVar8 = fVar1 * *pfVar8;

      pfVar8[1] = fVar1 * pfVar8[1];

      pfVar8 = pfVar8 + 8;

    } while (iVar2 < (int)puVar3[6]);

  }

  return puVar3;

}

