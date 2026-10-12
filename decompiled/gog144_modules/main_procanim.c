/* Giants 1.449 — module main/procanim
 * 3 functions (2 named) — decompiled, names from PS2 symbols
 * Original source: C:\Giants\source\main/procanim.c(pp) (assert-string evidence)
 */

/* ===== FUN_004a8150 @ 0x004A8150 ===== */
void FUN_004a8150(int param_1)



{

  if ((param_1 != 0) && (*(int *)(param_1 + 0x460) != 0)) {

    mem_free_tagged(*(int *)(param_1 + 0x460),s_C__Giants_source_main_procanim_c_0055f4c8,0xb6);

    *(undefined4 *)(param_1 + 0x460) = 0;

  }

  return;

}

/* ===== ProcAnimsCreate__FP9ObjectSetP9UsrAnmDef @ 0x004A8190 ===== */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */



void ProcAnimsCreate__FP9ObjectSetP9UsrAnmDef(undefined4 *p0,undefined4 *p1)



{

  int *piVar1;

  undefined4 *puVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  undefined4 uVar6;

  undefined4 *puVar7;

  undefined4 local_64;

  undefined4 local_60;

  undefined4 local_5c;

  undefined4 local_58;

  undefined1 local_54 [16];

  undefined1 local_44 [68];

  

  if (p0 != (undefined4 *)0x0) {

    iVar3 = 0;

    iVar4 = *p1;

    puVar7 = p1;

    while (iVar4 != 0) {

      piVar1 = puVar7 + 6;

      puVar7 = puVar7 + 6;

      iVar3 = iVar3 + 1;

      iVar4 = *piVar1;

    }

    iVar4 = FUN_0053a700(2,iVar3 << 5,s_UsrAnm_Memory_0055f4ec,

                         s_C__Giants_source_main_procanim_c_0055f4c8,0xc6);

    p0[0x118] = iVar4;

    if (*p1 != 0) {

      puVar7 = (undefined4 *)(iVar4 + 8);

      do {

        iVar4 = p0[p1[5] + 2];

        if (((iVar4 != 0) && (iVar3 = FUN_0053be00(*(undefined4 *)(iVar4 + 0x28),0,*p1), iVar3 != 0)

            ) && (*(int *)(iVar3 + 0x18) == 0)) {

          *(uint *)(iVar4 + 8) = *(uint *)(iVar4 + 8) | 6;

          *(undefined1 **)(iVar3 + 0x18) = &LAB_004a7e50;

          *(uint *)(iVar3 + 8) = *(uint *)(iVar3 + 8) | 0x20;

          *(undefined4 **)(iVar3 + 0x1c) = puVar7 + -2;

          puVar7[-2] = 0;

          puVar7[-1] = 0;

          puVar2 = (undefined4 *)p1[2];

          *puVar7 = *puVar2;

          puVar7[1] = puVar2[1];

          puVar7[2] = puVar2[2];

          if (p1[3] != 0) {

            puVar7[-2] = 1;

            puVar2 = (undefined4 *)p1[3];

            puVar7[3] = *puVar2;

            puVar7[4] = puVar2[1];

            puVar7[5] = puVar2[2];

          }

          if ((p1[1] != 0) &&

             (iVar5 = FUN_0053be00(*(undefined4 *)(iVar4 + 0x28),0,p1[1]), iVar5 != 0)) {

            uVar6 = FUN_0053ca70();

            if (p1[4] == 0) {

              FUN_0053ca90(local_44,iVar3,iVar5,*(undefined4 *)(*(int *)(iVar4 + 0x28) + 0x10),uVar6

                          );

              puVar2 = (undefined4 *)p1[2];

              local_58 = 0;

              local_64 = *puVar2;

              local_60 = puVar2[1];

              local_5c = puVar2[2];

              (*(code *)PTR_FUN_00580c28)(local_54,&local_64,1,local_44);

              FUN_0053e960(puVar7,local_54);

              puVar2 = (undefined4 *)p1[3];

              if (puVar2 != (undefined4 *)0x0) {

                local_64 = *puVar2;

                local_60 = puVar2[1];

                local_5c = puVar2[2];

                (*(code *)PTR_FUN_00580c28)(local_54,&local_64,1,local_44);

                FUN_0053e960(puVar7 + 3,local_54);

              }

            }

            else {

              puVar7[-1] = iVar5;

            }

          }

        }

        piVar1 = p1 + 6;

        p1 = p1 + 6;

        puVar7 = puVar7 + 8;

      } while (*piVar1 != 0);

    }

  }

  return;

}

/* ===== KabutoProcAnimsCreate @ 0x004A8E10 ===== */
void KabutoProcAnimsCreate(int param_1)



{

  int iVar1;

  int iVar2;

  int *piVar3;

  int iVar4;

  int *piVar5;

  int *local_4;

  

  if (param_1 != 0) {

    iVar2 = 0;

    iVar1 = DAT_0055f220;

    while (-1 < iVar1) {

      piVar3 = &DAT_0055f224 + iVar2;

      iVar2 = iVar2 + 1;

      iVar1 = *piVar3;

    }

    piVar3 = (int *)FUN_0053a700(2,iVar2 * 0x38,s_Kabuto_UsrAnm_Memory_0055f50c,

                                 s_C__Giants_source_main_procanim_c_0055f4c8,0x3c9);

    *(int **)(param_1 + 0x460) = piVar3;

    local_4 = &DAT_0055f220;

    iVar1 = DAT_0055f220;

    while (-1 < iVar1) {

      iVar1 = *(int *)(param_1 + 8 + *local_4 * 4);

      if (iVar1 != 0) {

        *(uint *)(iVar1 + 8) = *(uint *)(iVar1 + 8) | 2;

        iVar2 = 0;

        do {

          piVar5 = piVar3;

          for (iVar4 = 7; iVar4 != 0; iVar4 = iVar4 + -1) {

            *piVar5 = 0;

            piVar5 = piVar5 + 1;

          }

          *piVar3 = iVar2;

          iVar4 = FUN_0053be00(*(undefined4 *)(iVar1 + 0x28),0,(&PTR_s_l_ankle01_0055f4ac)[iVar2]);

          piVar3[2] = iVar4;

          if ((iVar4 != 0) && (*(int *)(iVar4 + 0x18) == 0)) {

            *(uint *)(iVar4 + 8) = *(uint *)(iVar4 + 8) | 0x20;

            *(undefined1 **)(iVar4 + 0x18) = &LAB_004a8430;

            *(int **)(iVar4 + 0x1c) = piVar3;

          }

          iVar4 = *(int *)(piVar3[2] + 0x10);

          if ((iVar4 != 0) && (*(int *)(iVar4 + 0x18) == 0)) {

            *(uint *)(iVar4 + 8) = *(uint *)(iVar4 + 8) | 0x20;

            *(undefined1 **)(iVar4 + 0x18) = &LAB_004a8430;

            *(int **)(iVar4 + 0x1c) = piVar3;

          }

          iVar4 = *(int *)(*(int *)(piVar3[2] + 0x10) + 0x10);

          if ((iVar4 != 0) && (*(int *)(iVar4 + 0x18) == 0)) {

            *(uint *)(iVar4 + 8) = *(uint *)(iVar4 + 8) | 0x20;

            *(undefined1 **)(iVar4 + 0x18) = &LAB_004a8430;

            *(int **)(iVar4 + 0x1c) = piVar3;

          }

          piVar3 = piVar3 + 7;

          iVar2 = iVar2 + 1;

        } while (iVar2 < 2);

      }

      piVar5 = local_4 + 1;

      local_4 = local_4 + 1;

      iVar1 = *piVar5;

    }

  }

  return;

}

