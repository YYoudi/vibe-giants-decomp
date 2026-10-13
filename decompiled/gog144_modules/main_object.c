/* Giants 1.449 — module main/object
 * 6 functions (6 named) — decompiled, names from PS2 symbols
 * Original source: C:\Giants\source\main/object.c(pp) (assert-string evidence)
 */

/* ===== object_allocate_init @ 0x00496B30 ===== */
void object_allocate_init(void)



{

  int iVar1;

  

  DAT_0059f370 = FUN_0053a700(0x18,0x2356e0,s_bigobj_0055c9e4,

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

        uVar1 = FUN_0053a700(0x18,iVar3 * 0x44,s_Transform_Ref_Mats_0055ca74,

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
/* WARNING: Struct "OBJECT": ignoring multiple overlapping fields */

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

  FUN_0044eff0();

  FUN_00536c60();

  for (piVar4 = DAT_00632d68; piVar2 = DAT_00632d68, piVar4 != (int *)0x0; piVar4 = (int *)*piVar4)

  {

    FUN_00499fa0((OBJECT *)piVar4[3]);

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

       ((iVar4 = FUN_004a6160(iVar1), iVar4 != 0 || (iVar4 = FUN_004a6180(iVar1), iVar4 != 0)))) {

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
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

/* WARNING: Struct "OBJECT": ignoring multiple overlapping fields */

/* PS2 candidate: object_copy_personality (conf 0.374) */



void object_copy_personality(OBJECT *obj)



{

  dword dVar1;

  undefined4 uVar2;

  OBJECT *pOVar3;

  undefined4 uVar4;

  dword *pdVar5;

  undefined4 *puVar6;

  int iVar7;

  uint uVar8;

  int iVar9;

  dword *pdVar10;

  dword *pdVar11;

  int in_stack_00000008;

  

  pOVar3 = obj;

  if ((obj != (OBJECT *)0x0) && (in_stack_00000008 != 0)) {

    if (*(int *)(in_stack_00000008 + 0x1e0) != *(int *)&obj->field_0x1e0) {

      main_objspec_00499e10(obj);

    }

    pdVar5 = (dword *)(in_stack_00000008 + 400);

    pdVar10 = &obj->field_190;

    for (iVar7 = 0x1e; iVar7 != 0; iVar7 = iVar7 + -1) {

      *pdVar10 = *pdVar5;

      pdVar5 = pdVar5 + 1;

      pdVar10 = pdVar10 + 1;

    }

    dVar1 = *(dword *)(in_stack_00000008 + 8);

    if ((dVar1 == 0) || (*(int *)(dVar1 + 0x450) == 0)) {

      mem_free_tagged(*(undefined4 *)&obj->field_0x2dc,s_C__Giants_source_main_object_c_0055c9ec,

                      0x161);

      *(undefined4 *)&obj->field_0x2dc = 0;

      *(undefined4 *)&obj->field_0x2d8 = 0;

    }

    else {

      if (*(int *)&obj->field_0x2d8 != *(int *)(dVar1 + 0x450)) {

        object_set_objectset(obj,0);

        iVar7 = *(int *)(dVar1 + 0x450);

        *(int *)&obj->field_0x2d8 = iVar7;

        uVar4 = FUN_0053a700(0x18,iVar7 * 0x44,s_Transform_Ref_Mats_0055ca74,

                             s_C__Giants_source_main_object_c_0055c9ec,0x15a);

        *(undefined4 *)&obj->field_0x2dc = uVar4;

      }

      puVar6 = *(undefined4 **)&obj->field_0x2dc;

      for (uVar8 = (uint)(*(int *)&obj->field_0x2d8 * 0x44) >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {

        *puVar6 = 0;

        puVar6 = puVar6 + 1;

      }

      for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {

        *(undefined1 *)puVar6 = 0;

        puVar6 = (undefined4 *)((int)puVar6 + 1);

      }

    }

    obj->field_8 = dVar1;

    obj->field_4 = *(dword *)(in_stack_00000008 + 4);

    *(undefined4 *)&obj->field_0xc4 = *(undefined4 *)(in_stack_00000008 + 0xc4);

    obj->gap_178 = *(dword *)(in_stack_00000008 + 0x178);

    obj->acc_mecc_set_fire = *(dword *)(in_stack_00000008 + 0x17c);

    obj->field_180 = *(dword *)(in_stack_00000008 + 0x180);

    main_objspec_00499da0(obj);

    FUN_00499f30(obj);

    pdVar5 = &obj->field_10;

    iVar7 = in_stack_00000008 - (int)obj;

    obj = (OBJECT *)&DAT_00000004;

    do {

      pdVar10 = (dword *)(iVar7 + (int)pdVar5);

      pdVar11 = pdVar5;

      for (iVar9 = 9; iVar9 != 0; iVar9 = iVar9 + -1) {

        *pdVar11 = *pdVar10;

        pdVar10 = pdVar10 + 1;

        pdVar11 = pdVar11 + 1;

      }

      pdVar5 = pdVar5 + 9;

      obj = (OBJECT *)((int)&obj[-1].field_6B60 + 3);

    } while (obj != (OBJECT *)0x0);

    *(undefined4 *)&pOVar3->field_0x2e4 = *(undefined4 *)(in_stack_00000008 + 0x2e4);

    iVar7 = *(int *)(in_stack_00000008 + 0x2e0);

    if (iVar7 != 0) {

      if (*(char *)(iVar7 + 0x1e) < '\0') {

        uVar4 = *(undefined4 *)(iVar7 + 0x10);

        uVar2 = *(undefined4 *)(iVar7 + 0xc);

        puVar6 = (undefined4 *)

                 FUN_0053a700(0x18,0x20,s_Dynamic_shadow_texture_0055ca88,

                              s_C__Giants_source_main_object_c_0055c9ec,0x23d);

        puVar6[4] = uVar4;

        *puVar6 = s_Dynamic_shadow_texture_0055ca88;

        puVar6[1] = 0;

        puVar6[2] = 0;

        puVar6[3] = uVar2;

        puVar6[6] = 5;

        puVar6[5] = 5;

        *(undefined1 *)((int)puVar6 + 0x1d) = 0;

        *(undefined1 *)(puVar6 + 7) = 0x20;

        *(undefined2 *)((int)puVar6 + 0x1e) = 0x80;

        iVar7 = *(int *)&pOVar3->field_0x2e0;

        if ((iVar7 != 0) && (*(char *)(iVar7 + 0x1e) < '\0')) {

          mem_free_tagged(iVar7,s_C__Giants_source_main_object_c_0055c9ec,0x24c);

        }

        *(undefined4 **)&pOVar3->field_0x2e0 = puVar6;

      }

      else {

        *(int *)&pOVar3->field_0x2e0 = iVar7;

      }

    }

    if ((0 < *(int *)(in_stack_00000008 + 0x2fc)) && (*(int *)(DAT_006330e4 + 0x174) != 0)) {

      fx_get_free_effect__Fv();

    }

  }

  return;

}

