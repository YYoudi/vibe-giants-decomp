/* Giants 1.449 — module main/setupgam
 * 1 functions (1 named) — decompiled, names from PS2 symbols
 * Original source: C:\Giants\source\main/setupgam.c(pp) (assert-string evidence)
 */

/* ===== main_setupgam_004eda20 @ 0x004EDA20 ===== */
void main_setupgam_004eda20(void)



{

  undefined4 uVar1;

  int iVar2;

  uint uVar3;

  int iVar4;

  undefined4 *puVar5;

  undefined4 *puVar6;

  undefined4 *puVar7;

  undefined4 *local_4;

  

  DAT_00633044 = 0;

  FUN_004a4510();

  main_cleaner_0040f390();

  game_water_00513eb0(DAT_006328f4);

  DAT_006328f4 = 0;

  if (DAT_006330e4 != 0) {

    if (*(int *)(DAT_006330e4 + 0x5080) != 0) {

      main_00508840(*(int *)(DAT_006330e4 + 0x5080));

      FUN_005086e0(*(undefined4 *)(DAT_006330e4 + 0x5080));

    }

    main_00508840(DAT_006330e4 + 0x5040);

    FUN_005086e0(DAT_006330e4 + 0x5040);

    if (*(int *)(DAT_006330e4 + 0x5088) != 0) {

      main_00508840(*(int *)(DAT_006330e4 + 0x5088));

      FUN_005086e0(*(undefined4 *)(DAT_006330e4 + 0x5088));

    }

    if (DAT_006330e4 != 0) {

      main_00508840(DAT_006330e4 + 0x4ea0);

      FUN_005086e0(DAT_006330e4 + 0x4ea0);

    }

  }

  main_drawwrld_00435e20();

  FLK_ReplayFileNameClear();

  FUN_00446620();

  FUN_004cc8d0();

  FUN_00447060();

  uVar1 = FUN_00497d20(2);

  main_procanim_004a8150(uVar1);

  uVar1 = FUN_00497d20(0x85);

  main_procanim_004a8150(uVar1);

  uVar1 = FUN_00497d20(0x248);

  main_procanim_004a8150(uVar1);

  uVar1 = FUN_00497d20(0x270);

  main_procanim_004a8150(uVar1);

  uVar1 = FUN_00497d20(0x349);

  main_procanim_004a8150(uVar1);

  uVar1 = FUN_00497d20(0x34b);

  main_procanim_004a8150(uVar1);

  uVar1 = FUN_00497d20(0x34a);

  main_procanim_004a8150(uVar1);

  uVar1 = FUN_00497d20(0x3b5);

  main_procanim_004a8150(uVar1);

  uVar1 = FUN_00497d20(0x3b);

  main_procanim_004a8150(uVar1);

  uVar1 = FUN_00497d20(0x42f);

  main_procanim_004a8150(uVar1);

  uVar1 = FUN_00497d20(0x42e);

  main_procanim_004a8150(uVar1);

  uVar1 = FUN_00497d20(0x4ab);

  main_procanim_004a8150(uVar1);

  uVar1 = FUN_00497d20(0x4aa);

  main_procanim_004a8150(uVar1);

  uVar1 = FUN_00497d20(0x4ac);

  main_procanim_004a8150(uVar1);

  uVar1 = FUN_00497d20(0x4ad);

  main_procanim_004a8150(uVar1);

  uVar1 = FUN_00497d20(1);

  main_procanim_004a8150(uVar1);

  iVar4 = 0;

  if (0 < DAT_00632ea4) {

    puVar5 = &DAT_00632ea8;

    local_4 = (undefined4 *)&DAT_00632eac;

    do {

      iVar2 = (*(code *)*puVar5)(0);

      if (iVar2 == 0) {

        DAT_00632ea4 = DAT_00632ea4 + -1;

        if (iVar4 < DAT_00632ea4) {

          puVar6 = local_4;

          puVar7 = puVar5;

          for (uVar3 = DAT_00632ea4 - iVar4 & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {

            *puVar7 = *puVar6;

            puVar6 = puVar6 + 1;

            puVar7 = puVar7 + 1;

          }

          for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {

            *(undefined1 *)puVar7 = *(undefined1 *)puVar6;

            puVar6 = (undefined4 *)((int)puVar6 + 1);

            puVar7 = (undefined4 *)((int)puVar7 + 1);

          }

        }

        iVar4 = iVar4 + -1;

        local_4 = local_4 + -1;

        puVar5 = puVar5 + -1;

      }

      iVar4 = iVar4 + 1;

      local_4 = local_4 + 1;

      puVar5 = puVar5 + 1;

    } while (iVar4 < DAT_00632ea4);

  }

  win95_frate_00518cd0();

  main_object_004976e0();

  readobjs_load_object();

  main_fx_004471a0();

  (*DAT_005dd290)();

  (*DAT_005dd31c)();

  (*DAT_005dd360)();

  main_noise_00495430();

  main_noise_00496170();

  main_tracer_0050a170();

  if (DAT_006330e4 != 0) {

    FUN_00495090();

    if (*(int *)(DAT_006330e4 + 0x170) != 0) {

      iVar4 = 0;

      if (0 < *(int *)(DAT_006330e4 + 0x170)) {

        iVar2 = 0;

        do {

          FUN_00499cd0(*(int *)(DAT_006330e4 + 0x174) + iVar2);

          iVar4 = iVar4 + 1;

          iVar2 = iVar2 + 0x304;

        } while (iVar4 < *(int *)(DAT_006330e4 + 0x170));

      }

      mem_free_tagged(*(undefined4 *)(DAT_006330e4 + 0x174),

                      s_C__Giants_source_main_setupgam_c_00561fd4,0x98);

      *(undefined4 *)(DAT_006330e4 + 0x174) = 0;

      *(undefined4 *)(DAT_006330e4 + 0x170) = 0;

    }

    main_makewrld_00472e40();

  }

  main_readwrls_004b4330();

  FUN_0040b300();

  main_texture_00507fa0();

  main_mission_00490970();

  DAT_006330e4 = 0;

  DAT_00632a88 = 0;

  main_drawobj_0042d500();

  main_linkage_00470610();

  main_ai_move_00403460();

  main_path_0049fa90();

  main_editor_00441660();

  return;

}

