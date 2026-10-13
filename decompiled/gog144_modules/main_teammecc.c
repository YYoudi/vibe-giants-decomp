/* Giants 1.449 — module main/teammecc
 * 1 functions (1 named) — decompiled, names from PS2 symbols
 * Original source: C:\Giants\source\main/teammecc.c(pp) (assert-string evidence)
 */

/* ===== teammecc_create @ 0x005011F0 ===== */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

/* WARNING: Struct "OBJECT": ignoring multiple overlapping fields */

/* PS2 candidate: teammecc_create (conf 0.542) */



void teammecc_create(OBJECT *obj)



{

  dword *pdVar1;

  undefined4 *puVar2;

  dword dVar3;

  OBJECT *obj_00;

  int iVar4;

  float10 fVar5;

  int in_stack_00000008;

  OBJECT *pOVar6;

  OBJECT *pOVar7;

  OBJECT *pOVar8;

  OBJECT *pOVar9;

  

  if ((obj != (OBJECT *)0x0) && (obj->field_4 == 2)) {

    if (obj->field_170 == 0) {

      obj->acc_grenade_do_bounce = 0;

      puVar2 = (undefined4 *)

               FUN_0053a700(0xd,0x138,&DAT_0057b5dc,s_C__Giants_source_main_teammecc_c_0057b5e4,

                            0x19d);

      obj->field_170 = (dword)puVar2;

      for (iVar4 = 0x4e; iVar4 != 0; iVar4 = iVar4 + -1) {

        *puVar2 = 0;

        puVar2 = puVar2 + 1;

      }

      *(undefined4 *)obj->field_170 = 1;

      if (((obj->field_4 == 2) && (dVar3 = obj->field_170, dVar3 != 0)) &&

         (obj->acc_grenade_do_bounce == 0)) {

        pdVar1 = &obj->gap_A0;

        fVar5 = (float10)FUN_0050a610(pdVar1,(dword *)(dVar3 + 0x18));

        if ((float10)*(float *)(DAT_00632ed8 + 0x1020) * (float10)*(float *)(DAT_00632ed8 + 0x1020)

            < fVar5) {

          *(undefined4 *)(dVar3 + 0x14) = *(undefined4 *)&obj->field_0xc8;

          *(dword *)(dVar3 + 8) = *pdVar1;

          *(undefined4 *)(dVar3 + 0xc) = *(undefined4 *)&obj->field_0xa4;

          *(undefined4 *)(dVar3 + 0x10) = *(undefined4 *)&obj->field_0xa8;

          *(dword *)(dVar3 + 0x18) = *pdVar1;

          *(undefined4 *)(dVar3 + 0x1c) = *(undefined4 *)&obj->field_0xa4;

          *(undefined4 *)(dVar3 + 0x20) = *(undefined4 *)&obj->field_0xa8;

        }

      }

    }

    dVar3 = FUN_00500fb0(obj);

    iVar4 = dVar3 - 1;

    if (0 < in_stack_00000008) {

      do {

        obj_00 = (OBJECT *)object_allocate_type(obj->field_4,0x13);

        pOVar8 = obj_00;

        pOVar9 = obj;

        object_copy_personality(obj_00);

        pOVar6 = obj_00;

        pOVar7 = obj;

        FUN_00497a50(obj_00);

        *(undefined4 *)(*(int *)&obj_00->field_0x100 + 200) = 0;

        obj_00->field_18C = obj->field_18C;

        obj_00->field_170 = obj->field_170;

        obj_00->acc_grenade_do_bounce = dVar3;

        FUN_00502660(obj,0,dVar3,&obj_00->gap_A0,&obj_00->field_0xc8,pOVar6,pOVar7,pOVar8,pOVar9);

        FUN_00499280(obj_00);

        *(undefined4 *)&obj_00->field_0xec = 0;

        obj_00->field_16C = (dword)&LAB_005013f0;

        FUN_00413820(obj_00);

        FUN_0049b8a0(obj_00);

        dVar3 = dVar3 + 1;

        obj_00->acc_grenade_do_stopped = obj_00->acc_grenade_do_stopped | 1;

        *(uint *)&obj_00->field_0xd8 = *(uint *)&obj_00->field_0xd8 | 0x10000000;

      } while ((int)((-1 - iVar4) + dVar3) < in_stack_00000008);

    }

    *(int *)(obj->field_170 + 4) = iVar4 + in_stack_00000008;

    teammecc_set_mode(obj,2,0);

  }

  return;

}

