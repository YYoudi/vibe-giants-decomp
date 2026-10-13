/* Giants 1.449 — module comm/multi
 * 2 functions (2 named) — decompiled, names from PS2 symbols
 * Original source: C:\Giants\source\comm/multi.c(pp) (assert-string evidence)
 */

/* ===== comm_multi_00533280 @ 0x00533280 ===== */
void comm_multi_00533280(int param_1)



{

  int iVar1;

  undefined4 *puVar2;

  int iVar3;

  

  iVar3 = FUN_0052aa70();

  if ((iVar3 != 0) && (puVar2 = DAT_00632d68, 9 < DAT_00632f08)) {

    for (; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {

      if (((*(uint *)(puVar2[3] + 0xd8) & 0x8000) == 0) &&

         (*(int *)(puVar2[3] + 0x188) == *(int *)(param_1 + 5))) {

        return;

      }

    }

    iVar3 = object_allocate_type(*(undefined4 *)(param_1 + 1),0x80000000);

    *(undefined4 *)(iVar3 + 0x274) = 0;

    *(undefined4 *)(iVar3 + 0x188) = *(undefined4 *)(param_1 + 5);

    *(undefined4 *)(iVar3 + 0xe8) = 4;

    *(undefined4 *)(*(int *)(iVar3 + 0x100) + 0x54) = *(undefined4 *)(param_1 + 0xd);

    puVar2 = DAT_00632d68;

    if (*(int *)(param_1 + 9) != 0) {

      while( true ) {

        if (puVar2 == (undefined4 *)0x0) {

          __rt_error_box(s_player_0057ff40,s_C__Giants_source_comm_multi_c_0057ff48,0x8ec);

          return;

        }

        iVar1 = puVar2[3];

        if (((*(uint *)(iVar1 + 0xd8) & 0x8000) == 0) &&

           (*(int *)(iVar1 + 0x188) == *(int *)(param_1 + 9))) break;

        puVar2 = (undefined4 *)*puVar2;

      }

      smartie_lock_to_player(iVar3,iVar1,1);

    }

  }

  return;

}

/* ===== comm_multi_00533370 @ 0x00533370 ===== */
void comm_multi_00533370(int param_1,int param_2)



{

  undefined4 *puVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  

  iVar3 = FUN_0052aa70();

  if ((iVar3 != 0) && (puVar1 = DAT_00632d68, 9 < DAT_00632f08)) {

    for (; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {

      if (((*(uint *)(puVar1[3] + 0xd8) & 0x8000) == 0) &&

         (*(int *)(puVar1[3] + 0x188) == *(int *)(param_1 + 5))) {

        return;

      }

    }

    puVar1 = DAT_00632d68;

    if (param_2 != 0) {

      for (; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {

        iVar3 = puVar1[3];

        if (((*(uint *)(iVar3 + 0xd8) & 0x8000) == 0) &&

           (*(int *)(iVar3 + 0x188) == *(int *)(param_1 + 9))) goto LAB_005333ee;

      }

      iVar3 = 0;

LAB_005333ee:

      iVar4 = object_allocate_type(*(undefined4 *)(param_1 + 1),0x80000000);

      *(undefined4 *)(iVar4 + 0x188) = *(undefined4 *)(param_1 + 5);

      if (iVar3 == 0) {

        __rt_error_box(&DAT_0057ff68,s_C__Giants_source_comm_multi_c_0057ff48,0x906);

      }

      FUN_0041b390(iVar4,iVar3);

      return;

    }

    iVar3 = object_allocate_type(*(undefined4 *)(param_1 + 1),0x80000000);

    *(undefined4 *)(iVar3 + 0x188) = *(undefined4 *)(param_1 + 5);

    for (puVar1 = DAT_00632d68; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {

      iVar4 = puVar1[3];

      if (((*(uint *)(iVar4 + 0xd8) & 0x8000) == 0) &&

         (*(int *)(iVar4 + 0x188) == *(int *)(param_1 + 9))) goto LAB_00533499;

    }

    iVar4 = 0;

    __rt_error_box(&DAT_0057ff68,s_C__Giants_source_comm_multi_c_0057ff48,0x90f);

LAB_00533499:

    iVar2 = *(int *)(iVar3 + 0x100);

    *(uint *)(iVar3 + 0xe0) = *(uint *)(iVar3 + 0xe0) | 8;

    *(int *)(iVar3 + 0x274) = iVar4;

    *(undefined4 *)(iVar2 + 0x1c) = 0xffffffff;

    *(undefined4 *)(iVar2 + 0x20) = 0xffffffff;

    *(undefined4 *)(iVar2 + 0x24) = 0xffffffff;

    *(undefined4 *)(iVar2 + 0x28) = 0xffffffff;

    *(undefined4 *)(iVar2 + 0x18) = *(undefined4 *)(param_1 + 0xd);

    *(undefined4 *)(iVar3 + 0xe4) = 0x1e;

    if ((*(byte *)(param_1 + 0x11) & 1) != 0) {

      *(undefined4 *)(iVar3 + 0xe4) = 0x37;

    }

    *(undefined4 *)(iVar3 + 0xe8) = 4;

  }

  return;

}

