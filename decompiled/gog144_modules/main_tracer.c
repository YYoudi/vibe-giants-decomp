/* Giants 1.449 — module main/tracer
 * 2 functions (1 named) — decompiled, names from PS2 symbols
 * Original source: C:\Giants\source\main/tracer.c(pp) (assert-string evidence)
 */

/* ===== tracer_get_tracer @ 0x00509BA0 ===== */
/* PS2 candidate: tracer_get_tracer (conf 0.593) */



undefined4 tracer_get_tracer(int *param_1)



{

  int *piVar1;

  undefined4 *puVar2;

  undefined4 uVar3;

  int iVar4;

  int iVar5;

  undefined4 *puVar6;

  

  if (-1 < *param_1) {

    return (&DAT_00632dc8)[*param_1];

  }

  iVar5 = 0;

  while( true ) {

    piVar1 = (int *)(&DAT_00632dc8)[iVar5];

    if (piVar1 == (int *)0x0) {

      puVar2 = (undefined4 *)

               FUN_0053a700(0xd,0x44,s_tracer_0057bf6c,s_C__Giants_source_main_tracer_c_0057bf74,

                            0x49);

      (&DAT_00632dc8)[iVar5] = puVar2;

      puVar6 = puVar2;

      for (iVar4 = 0x11; iVar4 != 0; iVar4 = iVar4 + -1) {

        *puVar6 = 0;

        puVar6 = puVar6 + 1;

      }

      uVar3 = FUN_0053a700(0xd,0x1518,s_seglist_0057bf64,s_C__Giants_source_main_tracer_c_0057bf74,

                           0x4c);

      puVar2[3] = uVar3;

      puVar2[1] = 0x96;

      puVar2[7] = 0x3f800000;

      *param_1 = iVar5;

      return (&DAT_00632dc8)[iVar5];

    }

    if ((piVar1[0x10] == 0) && (*piVar1 < 2)) break;

    iVar5 = iVar5 + 1;

    if (0x1d < iVar5) {

      return 0;

    }

  }

  *param_1 = iVar5;

  *(undefined4 *)(&DAT_00632dc8)[iVar5] = 0;

  *(undefined4 *)((&DAT_00632dc8)[iVar5] + 8) = 0;

  *(undefined4 *)((&DAT_00632dc8)[iVar5] + 0x1c) = 0x3f800000;

  return (&DAT_00632dc8)[iVar5];

}

/* ===== FUN_0050a170 @ 0x0050A170 ===== */
void FUN_0050a170(void)



{

  int *piVar1;

  

  piVar1 = &DAT_00632dc8;

  do {

    if (*piVar1 != 0) {

      mem_free_tagged(*(undefined4 *)(*piVar1 + 0xc),s_C__Giants_source_main_tracer_c_0057bf74,0x183

                     );

      mem_free_tagged(*piVar1,s_C__Giants_source_main_tracer_c_0057bf74,0x184);

      *piVar1 = 0;

    }

    piVar1 = piVar1 + 1;

  } while ((int)piVar1 < 0x632e40);

  return;

}

