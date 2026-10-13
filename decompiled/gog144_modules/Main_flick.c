/* Giants 1.449 — module Main/flick
 * 1 functions (1 named) — decompiled, names from PS2 symbols
 * Original source: C:\Giants\source\Main/flick.c(pp) (assert-string evidence)
 */

/* ===== main_flick_00443740 @ 0x00443740 ===== */
undefined4 main_flick_00443740(undefined4 *param_1)



{

  int iVar1;

  undefined4 uVar2;

  int iVar3;

  int iVar4;

  int *piVar5;

  int *piVar6;

  int iVar7;

  int iVar8;

  int *piVar9;

  

  iVar1 = param_1[0x21];

  uVar2 = param_1[0x32];

  iVar8 = param_1[0x25];

  if (iVar8 != 0) {

    piVar6 = (int *)(param_1[0x28] + 0x2ec);

    do {

      if (piVar6[0x13a] == 0) {

        main_objspec_00499c80(piVar6 + -0xb8);

      }

      else if (*piVar6 != 0) {

        (**(code **)(DAT_00656420 + 0xb4))(DAT_00656420,*piVar6);

        map_memfree(*param_1,*piVar6);

        *piVar6 = 0;

      }

      FUN_00499cd0(piVar6 + -0xb8);

      piVar6[-0x82] = piVar6[-0x82] | 0x8000;

      piVar6 = piVar6 + 0x21d;

      iVar8 = iVar8 + -1;

    } while (iVar8 != 0);

  }

  (*DAT_005dd294)(0);

  iVar8 = param_1[0x25];

  piVar6 = (int *)param_1[0x28];

  do {

    if (iVar8 == 0) {

      piVar6 = (int *)param_1[0x27];

      for (iVar8 = param_1[0x24]; iVar8 != 0; iVar8 = iVar8 + -1) {

        if (*piVar6 != 0) {

          FUN_0053bd70(*piVar6);

        }

        piVar6 = piVar6 + 3;

      }

      map_memfree(*param_1,param_1[0x28]);

      map_memfree(*param_1,param_1[0x27]);

      map_memfree(*param_1,param_1[0x29]);

      map_alloc_cleanup(*param_1);

      if (iVar1 != 0) {

        FUN_005443bf(iVar1);

      }

      return uVar2;

    }

    if (*piVar6 != 0) {

      iVar3 = piVar6[5];

      iVar4 = *(int *)(iVar3 + 8);

      if (iVar4 != 0) {

        map_memfree(*param_1,*(undefined4 *)(iVar4 + 0x54));

        iVar7 = 0;

        piVar9 = (int *)(iVar4 + 0x2c);

        piVar5 = (int *)(iVar3 + 0x400);

        do {

          if (*piVar5 == 0) break;

          if (*piVar9 != 0) {

            FUN_0053d2a0(*piVar9);

          }

          iVar7 = iVar7 + 1;

          piVar5 = piVar5 + 1;

          piVar9 = piVar9 + 1;

        } while (iVar7 < 10);

        mem_free_tagged(iVar4,s_C__Giants_source_Main_flick_cpp_005585b8,0x164);

      }

    }

    piVar6 = piVar6 + 0x21d;

    iVar8 = iVar8 + -1;

  } while( true );

}

