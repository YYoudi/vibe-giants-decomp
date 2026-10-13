/* Giants 1.449 — module main/teammecc
 * 1 functions (1 named) — decompiled, names from PS2 symbols
 * Original source: C:\Giants\source\main/teammecc.c(pp) (assert-string evidence)
 */

/* ===== teammecc_create @ 0x005011F0 ===== */
/* PS2 candidate: teammecc_create (conf 0.542) */



void teammecc_create(int param_1,int param_2)



{

  undefined4 *puVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  float10 fVar5;

  

  if ((param_1 != 0) && (*(int *)(param_1 + 4) == 2)) {

    if (*(int *)(param_1 + 0x170) == 0) {

      *(undefined4 *)(param_1 + 0x174) = 0;

      puVar1 = (undefined4 *)

               MemAllocMsg(0xd,0x138,&DAT_0057b5dc,s_C__Giants_source_main_teammecc_c_0057b5e4,0x19d

                          );

      *(undefined4 **)(param_1 + 0x170) = puVar1;

      for (iVar4 = 0x4e; iVar4 != 0; iVar4 = iVar4 + -1) {

        *puVar1 = 0;

        puVar1 = puVar1 + 1;

      }

      **(undefined4 **)(param_1 + 0x170) = 1;

      if (((*(int *)(param_1 + 4) == 2) && (iVar4 = *(int *)(param_1 + 0x170), iVar4 != 0)) &&

         (*(int *)(param_1 + 0x174) == 0)) {

        puVar1 = (undefined4 *)(param_1 + 0xa0);

        fVar5 = (float10)FUN_0050a610(puVar1,(undefined4 *)(iVar4 + 0x18));

        if ((float10)*(float *)(DAT_00632ed8 + 0x1020) * (float10)*(float *)(DAT_00632ed8 + 0x1020)

            < fVar5) {

          *(undefined4 *)(iVar4 + 0x14) = *(undefined4 *)(param_1 + 200);

          *(undefined4 *)(iVar4 + 8) = *puVar1;

          *(undefined4 *)(iVar4 + 0xc) = *(undefined4 *)(param_1 + 0xa4);

          *(undefined4 *)(iVar4 + 0x10) = *(undefined4 *)(param_1 + 0xa8);

          *(undefined4 *)(iVar4 + 0x18) = *puVar1;

          *(undefined4 *)(iVar4 + 0x1c) = *(undefined4 *)(param_1 + 0xa4);

          *(undefined4 *)(iVar4 + 0x20) = *(undefined4 *)(param_1 + 0xa8);

        }

      }

    }

    iVar4 = team_count(param_1);

    iVar2 = iVar4 + -1;

    if (0 < param_2) {

      do {

        iVar3 = object_allocate_type(*(undefined4 *)(param_1 + 4),0x13);

        object_copy_personality(iVar3,param_1);

        object_copy_activedata(iVar3,param_1);

        *(undefined4 *)(*(int *)(iVar3 + 0x100) + 200) = 0;

        *(undefined4 *)(iVar3 + 0x18c) = *(undefined4 *)(param_1 + 0x18c);

        *(undefined4 *)(iVar3 + 0x170) = *(undefined4 *)(param_1 + 0x170);

        *(int *)(iVar3 + 0x174) = iVar4;

        teammecc_get_wantloc_formation(param_1,0,iVar4,iVar3 + 0xa0,iVar3 + 200);

        object_copy_posdirinfo(iVar3);

        *(undefined4 *)(iVar3 + 0xec) = 0;

        *(undefined1 **)(iVar3 + 0x16c) = &LAB_005013f0;

        setMenuSelection__7PS2Gameiiii(iVar3);

        object_setup_specialtype(iVar3);

        iVar4 = iVar4 + 1;

        *(uint *)(iVar3 + 0x1c8) = *(uint *)(iVar3 + 0x1c8) | 1;

        *(uint *)(iVar3 + 0xd8) = *(uint *)(iVar3 + 0xd8) | 0x10000000;

      } while ((-1 - iVar2) + iVar4 < param_2);

    }

    *(int *)(*(int *)(param_1 + 0x170) + 4) = iVar2 + param_2;

    teammecc_set_mode(param_1,2,0);

  }

  return;

}

