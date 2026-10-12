/* Giants 1.449 — module main/flame
 * 1 functions (0 named) — decompiled, names from PS2 symbols
 * Original source: C:\Giants\source\main/flame.c(pp) (assert-string evidence)
 */

/* ===== FUN_00442f70 @ 0x00442F70 ===== */
/* PS2 candidate: texture_object_debug_dump (conf 0.333) */



void FUN_00442f70(undefined4 *param_1,float param_2)



{

  float fVar1;

  int iVar2;

  undefined4 *puVar3;

  uint uVar4;

  int iVar5;

  float *pfVar6;

  undefined4 *puVar7;

  float10 fVar8;

  

  if (DAT_0059cda8 == 0) {

    DAT_0059cda8 = main_texture_00508750(s_b_flames_0055859c);

  }

  iVar2 = FUN_004d5740(*(undefined4 *)(DAT_00632ed8 + 0x150),*(undefined4 *)(DAT_00632ed8 + 0x154));

  uVar4 = iVar2 * 0x14 + 0x1c;

  puVar3 = (undefined4 *)

           FUN_0053a700(0xb,uVar4,s_flame_00558574,s_C__Giants_source_main_flame_c_0055857c,0x2a);

  puVar7 = puVar3;

  for (uVar4 = uVar4 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {

    *puVar7 = 0;

    puVar7 = puVar7 + 1;

  }

  for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {

    *(undefined1 *)puVar7 = 0;

    puVar7 = (undefined4 *)((int)puVar7 + 1);

  }

  *puVar3 = DAT_0059cda4;

  DAT_0059cda4 = puVar3;

  fVar8 = (float10)FUN_004d5780(*(undefined4 *)(DAT_00632ed8 + 0x170),

                                *(undefined4 *)(DAT_00632ed8 + 0x174));

  puVar3[1] = (float)fVar8;

  puVar3[2] = *param_1;

  puVar3[3] = param_1[1];

  puVar3[4] = param_1[2];

  puVar3[5] = *(undefined4 *)(DAT_00632ed8 + 0x178);

  puVar3[6] = iVar2;

  if (0 < iVar2) {

    pfVar6 = (float *)(puVar3 + 8);

    do {

      fVar8 = (float10)FUN_004d5780(0xbf666666,0x3f666666);

      fVar8 = fVar8 * fVar8 * fVar8 * (float10)param_2;

      fVar1 = (float)fVar8;

      pfVar6[-1] = (float)fVar8;

      fVar8 = (float10)FUN_004d5780(*(undefined4 *)(DAT_00632ed8 + 0x158),

                                    *(undefined4 *)(DAT_00632ed8 + 0x15c));

      *pfVar6 = (float)(fVar8 * (float10)param_2);

      fVar8 = (float10)FUN_004d5780(*(undefined4 *)(DAT_00632ed8 + 0x160),

                                    *(undefined4 *)(DAT_00632ed8 + 0x164));

      pfVar6[1] = (float)(SQRT((float10)(param_2 * param_2) - (float10)fVar1 * (float10)fVar1) *

                          fVar8 * (float10)param_2);

      fVar8 = (float10)FUN_004d5780(0,0x3f800000);

      pfVar6[2] = (float)fVar8;

      fVar8 = (float10)FUN_004d5780(*(undefined4 *)(DAT_00632ed8 + 0x168),

                                    *(undefined4 *)(DAT_00632ed8 + 0x16c));

      pfVar6[3] = (float)fVar8;

      pfVar6 = pfVar6 + 5;

      iVar2 = iVar2 + -1;

    } while (iVar2 != 0);

  }

  return;

}

