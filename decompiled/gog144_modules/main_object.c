/* Giants 1.449 — module main/object
 * 6 functions (6 named) — decompiled, names from PS2 symbols
 * Original source: C:\Giants\source\main/object.c(pp) (assert-string evidence)
 */

/* ===== object_allocate_init @ 0x00496B30 ===== */
void object_allocate_init(void)



{

  int iVar1;

  

  DAT_0059f370 = MemAllocMsg(0x18,0x2356e0,s_bigobj_0055c9e4,

                             s_C__Giants_source_main_object_c_0055c9ec,0x1c);

  iVar1 = 0;

  do {

    *(int *)(iVar1 + DAT_0059f370) = iVar1 + 0x304 + DAT_0059f370;

    iVar1 = iVar1 + 0x304;

  } while (iVar1 < 0x2353dc);

  *(undefined4 *)(DAT_0059f370 + 0x2353dc) = 0;

  DAT_00632da4 = DAT_0059f370;

  main_linkage_004705c0();

  return;

}

/* ===== main_object_00496b90 @ 0x00496B90 ===== */
void main_object_00496b90(void)



{

  mem_free_tagged(DAT_0059f370,s_C__Giants_source_main_object_c_0055c9ec,0x28);

  DAT_0059f370 = 0;

  DAT_00632da4 = 0;

  main_linkage_004705c0();

  return;

}

/* ===== object_set_objectset @ 0x00497450 ===== */
/* PS2 candidate: object_set_objectset (conf 0.479) */



void object_set_objectset(int param_1,int param_2)



{

  undefined4 uVar1;

  uint uVar2;

  int iVar3;

  undefined4 *puVar4;

  

  if (param_1 != 0) {

    if ((param_2 != 0) && (*(int *)(param_2 + 0x450) != 0)) {

      if (*(int *)(param_1 + 0x2d8) != *(int *)(param_2 + 0x450)) {

        object_set_objectset(param_1,0);

        iVar3 = *(int *)(param_2 + 0x450);

        *(int *)(param_1 + 0x2d8) = iVar3;

        uVar1 = MemAllocMsg(0x18,iVar3 * 0x44,s_Transform_Ref_Mats_0055ca74,

                            s_C__Giants_source_main_object_c_0055c9ec,0x15a);

        *(undefined4 *)(param_1 + 0x2dc) = uVar1;

      }

      puVar4 = *(undefined4 **)(param_1 + 0x2dc);

      for (uVar2 = (uint)(*(int *)(param_1 + 0x2d8) * 0x44) >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {

        *puVar4 = 0;

        puVar4 = puVar4 + 1;

      }

      for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {

        *(undefined1 *)puVar4 = 0;

        puVar4 = (undefined4 *)((int)puVar4 + 1);

      }

      *(int *)(param_1 + 8) = param_2;

      return;

    }

    mem_free_tagged(*(undefined4 *)(param_1 + 0x2dc),s_C__Giants_source_main_object_c_0055c9ec,0x161

                   );

    *(int *)(param_1 + 8) = param_2;

    *(undefined4 *)(param_1 + 0x2dc) = 0;

    *(undefined4 *)(param_1 + 0x2d8) = 0;

  }

  return;

}

/* ===== object_list_update @ 0x004975C0 ===== */
/* PS2 candidate: object_list_update (conf 0.46199999999999997) */



void object_list_update(void)



{

  int iVar1;

  int *piVar2;

  bool bVar3;

  int *piVar4;

  

  do {

    bVar3 = true;

    piVar4 = DAT_00632d68;

    if (DAT_00632d68 == (int *)0x0) break;

    do {

      iVar1 = piVar4[3];

      if ((*(int *)(iVar1 + 0x210) != 0) &&

         ((*(uint *)(*(int *)(iVar1 + 0x210) + 0xd8) & 0x8000) != 0)) {

        *(undefined4 *)(iVar1 + 0x210) = 0;

        if ((*(uint *)(iVar1 + 0xd8) & 0x400000) != 0) {

          *(uint *)(iVar1 + 0xd8) = *(uint *)(iVar1 + 0xd8) | 0x8000;

          bVar3 = false;

        }

      }

      if ((*(int *)(iVar1 + 0x224) != 0) &&

         ((*(uint *)(*(int *)(iVar1 + 0x224) + 0xd8) & 0x8000) != 0)) {

        *(undefined4 *)(iVar1 + 0x224) = 0;

      }

      piVar4 = (int *)*piVar4;

    } while (piVar4 != (int *)0x0);

  } while (!bVar3);

  wredit_obj_cleanup();

  FUN_00536c60();

  for (piVar4 = DAT_00632d68; piVar2 = DAT_00632d68, piVar4 != (int *)0x0; piVar4 = (int *)*piVar4)

  {

    FUN_00499fa0(piVar4[3]);

  }

  while (piVar2 != (int *)0x0) {

    piVar4 = (int *)piVar2[3];

    piVar2 = (int *)*piVar2;

    if ((char)((uint)piVar4[0x36] >> 8) < '\0') {

      FUN_00499cd0(piVar4);

      main_linkage_00470480(piVar4);

      *piVar4 = (int)DAT_00632da4;

      DAT_0059f374 = DAT_0059f374 + -1;

      DAT_00632da4 = piVar4;

      if ((*(byte *)(piVar4 + 0x72) & 0x20) != 0) {

        mem_free_tagged(piVar4[2],s_C__Giants_source_main_object_c_0055c9ec,0x1db);

        piVar4[0x72] = piVar4[0x72] & 0xffffffdf;

        piVar4[2] = 0;

      }

    }

  }

  return;

}

/* ===== main_object_004976e0 @ 0x004976E0 ===== */
void main_object_004976e0(void)



{

  int iVar1;

  undefined4 *puVar2;

  undefined4 *puVar3;

  int iVar4;

  

  for (puVar2 = DAT_00632d68; puVar3 = DAT_00632d68, puVar2 != (undefined4 *)0x0;

      puVar2 = (undefined4 *)*puVar2) {

    iVar1 = puVar2[3];

    if (((*(int *)(iVar1 + 0x174) == 0) && (*(int *)(iVar1 + 0x170) != 0)) &&

       ((iVar4 = ObjIsMecc(iVar1), iVar4 != 0 || (iVar4 = FUN_004a6180(iVar1), iVar4 != 0)))) {

      mem_free_tagged(*(undefined4 *)(iVar1 + 0x170),s_C__Giants_source_main_object_c_0055c9ec,0x1f0

                     );

    }

  }

  for (; puVar3 != (undefined4 *)0x0; puVar3 = (undefined4 *)*puVar3) {

    *(uint *)(puVar3[3] + 0xd8) = *(uint *)(puVar3[3] + 0xd8) | 0x8000;

  }

  object_list_update();

  return;

}

/* ===== object_copy_personality @ 0x00497770 ===== */
/* PS2 candidate: object_copy_personality (conf 0.374) */



void object_copy_personality(int param_1,int param_2)



{

  undefined4 uVar1;

  int iVar2;

  undefined4 uVar3;

  undefined4 *puVar4;

  int iVar5;

  uint uVar6;

  int iVar7;

  undefined4 *puVar8;

  undefined4 *puVar9;

  

  iVar2 = param_1;

  if ((param_1 != 0) && (param_2 != 0)) {

    if (*(int *)(param_2 + 0x1e0) != *(int *)(param_1 + 0x1e0)) {

      main_objspec_00499e10(param_1);

    }

    puVar4 = (undefined4 *)(param_2 + 400);

    puVar8 = (undefined4 *)(param_1 + 400);

    for (iVar5 = 0x1e; iVar5 != 0; iVar5 = iVar5 + -1) {

      *puVar8 = *puVar4;

      puVar4 = puVar4 + 1;

      puVar8 = puVar8 + 1;

    }

    iVar5 = *(int *)(param_2 + 8);

    if ((iVar5 == 0) || (*(int *)(iVar5 + 0x450) == 0)) {

      mem_free_tagged(*(undefined4 *)(param_1 + 0x2dc),s_C__Giants_source_main_object_c_0055c9ec,

                      0x161);

      *(undefined4 *)(param_1 + 0x2dc) = 0;

      *(undefined4 *)(param_1 + 0x2d8) = 0;

    }

    else {

      if (*(int *)(param_1 + 0x2d8) != *(int *)(iVar5 + 0x450)) {

        object_set_objectset(param_1,0);

        iVar7 = *(int *)(iVar5 + 0x450);

        *(int *)(param_1 + 0x2d8) = iVar7;

        uVar3 = MemAllocMsg(0x18,iVar7 * 0x44,s_Transform_Ref_Mats_0055ca74,

                            s_C__Giants_source_main_object_c_0055c9ec,0x15a);

        *(undefined4 *)(param_1 + 0x2dc) = uVar3;

      }

      puVar4 = *(undefined4 **)(param_1 + 0x2dc);

      for (uVar6 = (uint)(*(int *)(param_1 + 0x2d8) * 0x44) >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {

        *puVar4 = 0;

        puVar4 = puVar4 + 1;

      }

      for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {

        *(undefined1 *)puVar4 = 0;

        puVar4 = (undefined4 *)((int)puVar4 + 1);

      }

    }

    *(int *)(param_1 + 8) = iVar5;

    *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_2 + 4);

    *(undefined4 *)(param_1 + 0xc4) = *(undefined4 *)(param_2 + 0xc4);

    *(undefined4 *)(param_1 + 0x178) = *(undefined4 *)(param_2 + 0x178);

    *(undefined4 *)(param_1 + 0x17c) = *(undefined4 *)(param_2 + 0x17c);

    *(undefined4 *)(param_1 + 0x180) = *(undefined4 *)(param_2 + 0x180);

    main_objspec_00499da0(param_1);

    FUN_00499f30(param_1,param_2);

    puVar4 = (undefined4 *)(param_1 + 0x10);

    iVar5 = param_2 - param_1;

    param_1 = 4;

    do {

      puVar8 = (undefined4 *)(iVar5 + (int)puVar4);

      puVar9 = puVar4;

      for (iVar7 = 9; iVar7 != 0; iVar7 = iVar7 + -1) {

        *puVar9 = *puVar8;

        puVar8 = puVar8 + 1;

        puVar9 = puVar9 + 1;

      }

      puVar4 = puVar4 + 9;

      param_1 = param_1 + -1;

    } while (param_1 != 0);

    *(undefined4 *)(iVar2 + 0x2e4) = *(undefined4 *)(param_2 + 0x2e4);

    iVar5 = *(int *)(param_2 + 0x2e0);

    if (iVar5 != 0) {

      if (*(char *)(iVar5 + 0x1e) < '\0') {

        uVar3 = *(undefined4 *)(iVar5 + 0x10);

        uVar1 = *(undefined4 *)(iVar5 + 0xc);

        puVar4 = (undefined4 *)

                 MemAllocMsg(0x18,0x20,s_Dynamic_shadow_texture_0055ca88,

                             s_C__Giants_source_main_object_c_0055c9ec,0x23d);

        puVar4[4] = uVar3;

        *puVar4 = s_Dynamic_shadow_texture_0055ca88;

        puVar4[1] = 0;

        puVar4[2] = 0;

        puVar4[3] = uVar1;

        puVar4[6] = 5;

        puVar4[5] = 5;

        *(undefined1 *)((int)puVar4 + 0x1d) = 0;

        *(undefined1 *)(puVar4 + 7) = 0x20;

        *(undefined2 *)((int)puVar4 + 0x1e) = 0x80;

        iVar5 = *(int *)(iVar2 + 0x2e0);

        if ((iVar5 != 0) && (*(char *)(iVar5 + 0x1e) < '\0')) {

          mem_free_tagged(iVar5,s_C__Giants_source_main_object_c_0055c9ec,0x24c);

        }

        *(undefined4 **)(iVar2 + 0x2e0) = puVar4;

      }

      else {

        *(int *)(iVar2 + 0x2e0) = iVar5;

      }

    }

    if ((0 < *(int *)(param_2 + 0x2fc)) && (*(int *)(DAT_006330e4 + 0x174) != 0)) {

      fx_get_free_effect__Fv();

    }

  }

  return;

}

