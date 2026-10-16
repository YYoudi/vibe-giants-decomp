/* Giants 1.449 — module main/objspec
 * 5 functions (5 named) — decompiled, names from PS2 symbols
 * Original source: C:\Giants\source\main/objspec.c(pp) (assert-string evidence)
 */

/* ===== main_objspec_00499c80 @ 0x00499C80 ===== */
void main_objspec_00499c80(int param_1)



{

  int iVar1;

  

  iVar1 = *(int *)(param_1 + 0x2e0);

  if ((iVar1 != 0) && (*(char *)(iVar1 + 0x1e) < '\0')) {

    main_00508840(iVar1);

    texture_destroy(*(undefined4 *)(param_1 + 0x2e0));

    mem_free_tagged(*(undefined4 *)(param_1 + 0x2e0),s_C__Giants_source_main_objspec_c_0055e774,0xbb

                   );

  }

  *(undefined4 *)(param_1 + 0x2e0) = 0;

  return;

}

/* ===== object_free_all_allocated_data @ 0x00499CD0 ===== */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

/* PS2 candidate: object_free_all_allocated_data (conf 0.468) */



void object_free_all_allocated_data(OBJECT *obj)



{

  dword dVar1;

  

  if ((((int)obj->state < 0x6b) && (*(code **)(&DAT_0055cb28 + obj->state * 0x44) != (code *)0x0))

     && (obj->animate_state != 0)) {

    (**(code **)(&DAT_0055cb28 + obj->state * 0x44))(obj);

  }

  if (obj->animate_state != 0) {

    mem_free_tagged(obj->animate_state,s_C__Giants_source_main_objspec_c_0055e774,0xf9);

    obj->animate_state = 0;

  }

  dVar1 = obj->alloc_data2;

  if ((dVar1 != 0) && (*(char *)(dVar1 + 0x1e) < '\0')) {

    main_00508840(dVar1);

    texture_destroy(obj->alloc_data2);

    mem_free_tagged(obj->alloc_data2,s_C__Giants_source_main_objspec_c_0055e774,0xbb);

  }

  obj->alloc_data2 = 0;

  obj->pad_104 = 0;

  collgrid_clear_grid(obj);

  if (obj->alloc_data1 != 0) {

    mem_free_tagged(obj->alloc_data1,s_C__Giants_source_main_objspec_c_0055e774,0xe1);

  }

  obj->alloc_data1 = 0;

  obj->alloc_data0 = 0;

  return;

}

/* ===== main_objspec_00499da0 @ 0x00499DA0 ===== */
void main_objspec_00499da0(int param_1)



{

  uint uVar1;

  undefined4 *puVar2;

  uint uVar3;

  

  if ((((*(int *)(param_1 + 0x100) == 0) && (*(int *)(param_1 + 0x1e0) < 0x6b)) &&

      (*(code **)(&DAT_0055cb14 + *(int *)(param_1 + 0x1e0) * 0x44) != (code *)0x0)) &&

     (uVar1 = (**(code **)(&DAT_0055cb14 + *(int *)(param_1 + 0x1e0) * 0x44))(param_1), uVar1 != 0))

  {

    puVar2 = (undefined4 *)

             MemAllocMsg(0x18,uVar1,s_ospec_0055e794,s_C__Giants_source_main_objspec_c_0055e774,0xed

                        );

    *(undefined4 **)(param_1 + 0x100) = puVar2;

    for (uVar3 = uVar1 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {

      *puVar2 = 0;

      puVar2 = puVar2 + 1;

    }

    for (uVar1 = uVar1 & 3; uVar1 != 0; uVar1 = uVar1 - 1) {

      *(undefined1 *)puVar2 = 0;

      puVar2 = (undefined4 *)((int)puVar2 + 1);

    }

  }

  return;

}

/* ===== main_objspec_00499e10 @ 0x00499E10 ===== */
void main_objspec_00499e10(int param_1)



{

  if (((*(int *)(param_1 + 0x1e0) < 0x6b) &&

      (*(code **)(&DAT_0055cb28 + *(int *)(param_1 + 0x1e0) * 0x44) != (code *)0x0)) &&

     (*(int *)(param_1 + 0x100) != 0)) {

    (**(code **)(&DAT_0055cb28 + *(int *)(param_1 + 0x1e0) * 0x44))(param_1);

  }

  if (*(int *)(param_1 + 0x100) != 0) {

    mem_free_tagged(*(int *)(param_1 + 0x100),s_C__Giants_source_main_objspec_c_0055e774,0xf9);

    *(undefined4 *)(param_1 + 0x100) = 0;

  }

  return;

}

/* ===== object_change_ospec @ 0x00499E70 ===== */
/* PS2 candidate: object_change_ospec (conf 0.5990000000000001) */



void object_change_ospec(int param_1,int param_2)



{

  uint uVar1;

  undefined4 *puVar2;

  uint uVar3;

  

  if (((*(int *)(param_1 + 0x1e0) < 0x6b) &&

      (*(code **)(&DAT_0055cb28 + *(int *)(param_1 + 0x1e0) * 0x44) != (code *)0x0)) &&

     (*(int *)(param_1 + 0x100) != 0)) {

    (**(code **)(&DAT_0055cb28 + *(int *)(param_1 + 0x1e0) * 0x44))(param_1);

  }

  if (*(int *)(param_1 + 0x100) != 0) {

    mem_free_tagged(*(int *)(param_1 + 0x100),s_C__Giants_source_main_objspec_c_0055e774,0xf9);

    *(undefined4 *)(param_1 + 0x100) = 0;

  }

  *(int *)(param_1 + 0x1e0) = param_2;

  if (((*(int *)(param_1 + 0x100) == 0) && (param_2 < 0x6b)) &&

     ((*(code **)(&DAT_0055cb14 + param_2 * 0x44) != (code *)0x0 &&

      (uVar1 = (**(code **)(&DAT_0055cb14 + param_2 * 0x44))(param_1), uVar1 != 0)))) {

    puVar2 = (undefined4 *)

             MemAllocMsg(0x18,uVar1,s_ospec_0055e794,s_C__Giants_source_main_objspec_c_0055e774,0xed

                        );

    *(undefined4 **)(param_1 + 0x100) = puVar2;

    for (uVar3 = uVar1 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {

      *puVar2 = 0;

      puVar2 = puVar2 + 1;

    }

    for (uVar1 = uVar1 & 3; uVar1 != 0; uVar1 = uVar1 - 1) {

      *(undefined1 *)puVar2 = 0;

      puVar2 = (undefined4 *)((int)puVar2 + 1);

    }

  }

  return;

}

