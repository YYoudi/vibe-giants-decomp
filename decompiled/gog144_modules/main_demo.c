/* Giants 1.449 — module main/demo
 * 2 functions (0 named) — decompiled, names from PS2 symbols
 * Original source: C:\Giants\source\main/demo.c(pp) (assert-string evidence)
 */

/* ===== FUN_004267a0 @ 0x004267A0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_004267a0(void)



{

  int iVar1;

  int *piVar2;

  int iVar3;

  int iVar4;

  undefined4 *puVar5;

  

  if (DAT_005989c0 != 0) {

    iVar4 = 0;

    if (0 < DAT_0059998c) {

      puVar5 = (undefined4 *)&DAT_0058c694;

      do {

        if ((&DAT_005991a8)[iVar4] != 0) {

          iVar3 = (&DAT_005989d8)[iVar4];

          if ((char)((uint)*(undefined4 *)(iVar3 + 0xd8) >> 8) < '\0') {

            (&DAT_005991a8)[iVar4] = 0;

            (&DAT_005989d8)[iVar4] = 0;

          }

          else {

            iVar1 = FUN_004a6180(iVar3);

            if ((((iVar1 != 0) || (iVar1 = FUN_004a6160(iVar3), iVar1 != 0)) ||

                (iVar1 = FUN_004a61a0(iVar3), iVar1 != 0)) &&

               ((iVar1 = FUN_004a6160(iVar3), iVar1 == 0 || (*(int *)(iVar3 + 0x174) == 0)))) {

              if (puVar5[-8] == 1) {

                if (DAT_00632d60 != 0) {

                  DAT_00632d60 = 0;

                  for (puVar5 = DAT_00632d68; puVar5 != (undefined4 *)0x0;

                      puVar5 = (undefined4 *)*puVar5) {

                    iVar4 = puVar5[3];

                    if ((*(uint *)(iVar4 + 0xd8) & 0x800000) != 0) {

                      iVar3 = FUN_0052e4a0(iVar4);

                      if (iVar3 != 0) {

                        iVar3 = FUN_004a6180(iVar4);

                        if (((iVar3 == 0) && (iVar3 = FUN_004a6160(iVar4), iVar3 == 0)) &&

                           (iVar3 = FUN_004a61a0(iVar4), iVar3 == 0)) {

                          FUN_00530b70(iVar4);

                        }

                        else {

                          FUN_00530b10(iVar4);

                        }

                      }

                      FUN_00497510(iVar4);

                    }

                  }

                  mem_free_tagged(DAT_005989c0,s_C__Giants_source_main_demo_c_00556474,0x3cd);

                  DAT_005989c0 = 0;

                  mem_free_tagged(DAT_005989cc,s_C__Giants_source_main_demo_c_00556474,0x3cf);

                  _DAT_00599988 = 0;

                  DAT_0059998c = 0;

                  DAT_005989cc = 0;

                  _DAT_00599990 = 0;

                }

                break;

              }

              iVar3 = (&DAT_005989d8)[iVar4];

              *(undefined4 *)(iVar3 + 200) = puVar5[-1];

              *(undefined4 *)(iVar3 + 0xd4) = *puVar5;

              *(undefined4 *)(iVar3 + 0xcc) = puVar5[1];

              *(undefined4 *)(iVar3 + 0xd0) = puVar5[2];

              *(undefined4 *)(iVar3 + 0x108) = puVar5[3];

              *(undefined4 *)(iVar3 + 0x10c) = puVar5[4];

              *(undefined4 *)(iVar3 + 0x110) = puVar5[5];

              *(undefined4 *)(iVar3 + 0x114) = puVar5[7];

              *(undefined4 *)(iVar3 + 0x208) = puVar5[-6];

              *(undefined4 *)(iVar3 + 0x20c) = puVar5[-5];

              *(undefined4 *)(iVar3 + 0xb8) = *(undefined4 *)(iVar3 + 0xac);

              *(undefined4 *)(iVar3 + 0xbc) = *(undefined4 *)(iVar3 + 0xb0);

              *(undefined4 *)(iVar3 + 0xc0) = *(undefined4 *)(iVar3 + 0xb4);

              *(undefined4 *)(iVar3 + 0xac) = *(undefined4 *)(iVar3 + 0xa0);

              *(undefined4 *)(iVar3 + 0xb0) = *(undefined4 *)(iVar3 + 0xa4);

              *(undefined4 *)(iVar3 + 0xb4) = *(undefined4 *)(iVar3 + 0xa8);

              *(undefined4 *)(iVar3 + 0x118) = *(undefined4 *)(iVar3 + 0x108);

              *(undefined4 *)(iVar3 + 0x11c) = *(undefined4 *)(iVar3 + 0x10c);

              *(undefined4 *)(iVar3 + 0x120) = *(undefined4 *)(iVar3 + 0x110);

              *(undefined4 *)(iVar3 + 0x124) = *(undefined4 *)(iVar3 + 0x114);

              iVar1 = FUN_004a6180(iVar3);

              if (iVar1 == 0) {

                iVar1 = FUN_004a6160(iVar3);

                if (iVar1 != 0) {

                  iVar1 = puVar5[0xc];

                  iVar3 = *(int *)(iVar3 + 0x100);

                  if ((iVar1 < 0) || ((&DAT_005991a8)[iVar1] == 0)) {

                    *(undefined4 *)(iVar3 + 0xdc) = 0;

                  }

                  else {

                    *(undefined4 *)(iVar3 + 0xdc) = (&DAT_005989d8)[iVar1];

                  }

                  *(undefined4 *)(iVar3 + 0xe0) = puVar5[9];

                  *(undefined4 *)(iVar3 + 0xe4) = puVar5[10];

                  *(undefined4 *)(iVar3 + 0xe8) = puVar5[0xb];

                }

              }

              else {

                iVar3 = *(int *)(iVar3 + 0x100);

                *(undefined4 *)(iVar3 + 0xdb0) = puVar5[0xd];

                *(undefined4 *)(iVar3 + 0xcec) = puVar5[0xe];

              }

            }

          }

        }

        iVar4 = iVar4 + 1;

        puVar5 = puVar5 + 0x19;

      } while (iVar4 < DAT_0059998c);

    }

    if (DAT_00599978 == DAT_005999bc) {

      do {

        FUN_0049a140((&DAT_005989d8)[DAT_0059997c],DAT_00599980,DAT_00599984,

                     *(undefined4 *)((&DAT_005989d8)[DAT_0059997c] + 0x1e0),

                     DAT_005989d4 + DAT_005989cc);

        DAT_005989d4 = DAT_005989d4 + DAT_00599980;

        if (DAT_005989d0 < DAT_005989d4 + 0x10) {

          DAT_00599978 = -1;

        }

        else {

          piVar2 = (int *)(DAT_005989d4 + DAT_005989cc);

          DAT_00599978 = *piVar2;

          DAT_0059997c = piVar2[1];

          DAT_00599980 = piVar2[2];

          DAT_00599984 = piVar2[3];

          DAT_005989d4 = DAT_005989d4 + 0x10;

        }

      } while (DAT_00599978 == DAT_005999bc);

    }

    DAT_005999bc = DAT_005999bc + 1;

    iVar4 = FUN_00426c10();

    if ((iVar4 == 0) && (DAT_00632d60 != 0)) {

      DAT_00632d60 = 0;

      for (puVar5 = DAT_00632d68; puVar5 != (undefined4 *)0x0; puVar5 = (undefined4 *)*puVar5) {

        iVar4 = puVar5[3];

        if ((*(uint *)(iVar4 + 0xd8) & 0x800000) != 0) {

          iVar3 = FUN_0052e4a0(iVar4);

          if (iVar3 != 0) {

            iVar3 = FUN_004a6180(iVar4);

            if (((iVar3 == 0) && (iVar3 = FUN_004a6160(iVar4), iVar3 == 0)) &&

               (iVar3 = FUN_004a61a0(iVar4), iVar3 == 0)) {

              FUN_00530b70(iVar4);

            }

            else {

              FUN_00530b10(iVar4);

            }

          }

          FUN_00497510(iVar4);

        }

      }

      mem_free_tagged(DAT_005989c0,s_C__Giants_source_main_demo_c_00556474,0x3cd);

      DAT_005989c0 = 0;

      mem_free_tagged(DAT_005989cc,s_C__Giants_source_main_demo_c_00556474,0x3cf);

      _DAT_00599988 = 0;

      DAT_0059998c = 0;

      DAT_005989cc = 0;

      _DAT_00599990 = 0;

    }

  }

  return;

}

/* ===== FUN_00426c10 @ 0x00426C10 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined4 FUN_00426c10(void)



{

  undefined4 *puVar1;

  bool bVar2;

  undefined4 uVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  int *piVar7;

  int *piVar8;

  int local_64 [25];

  

  bVar2 = false;

  do {

    iVar6 = DAT_005989c8 + 100;

    if (DAT_005989c4 < iVar6) {

      if (DAT_00632d60 != 0) {

        DAT_00632d60 = 0;

        for (puVar1 = DAT_00632d68; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {

          iVar6 = puVar1[3];

          if ((*(uint *)(iVar6 + 0xd8) & 0x800000) != 0) {

            iVar5 = FUN_0052e4a0(iVar6);

            if (iVar5 != 0) {

              iVar5 = FUN_004a6180(iVar6);

              if (((iVar5 == 0) && (iVar5 = FUN_004a6160(iVar6), iVar5 == 0)) &&

                 (iVar5 = FUN_004a61a0(iVar6), iVar5 == 0)) {

                FUN_00530b70(iVar6);

              }

              else {

                FUN_00530b10(iVar6);

              }

            }

            FUN_00497510(iVar6);

          }

        }

        mem_free_tagged(DAT_005989c0,s_C__Giants_source_main_demo_c_00556474,0x3cd);

        DAT_005989c0 = 0;

        mem_free_tagged(DAT_005989cc,s_C__Giants_source_main_demo_c_00556474,0x3cf);

        _DAT_00599988 = 0;

        DAT_0059998c = 0;

        DAT_005989cc = 0;

        _DAT_00599990 = 0;

      }

      return 0;

    }

    piVar7 = (int *)(DAT_005989c0 + DAT_005989c8);

    piVar8 = local_64;

    for (iVar5 = 0x19; iVar5 != 0; iVar5 = iVar5 + -1) {

      *piVar8 = *piVar7;

      piVar7 = piVar7 + 1;

      piVar8 = piVar8 + 1;

    }

    if (local_64[1] != 0) {

      bVar2 = true;

    }

    DAT_005989c8 = iVar6;

    if ((&DAT_005991a8)[local_64[0]] != 0) {

      iVar5 = local_64[0] * 100;

      piVar7 = local_64;

      piVar8 = (int *)(&DAT_0058c66c + iVar5);

      for (iVar6 = 0x19; iVar6 != 0; iVar6 = iVar6 + -1) {

        *piVar8 = *piVar7;

        piVar7 = piVar7 + 1;

        piVar8 = piVar8 + 1;

      }

      iVar6 = (&DAT_005989d8)[local_64[0]];

      iVar4 = FUN_004a6180(iVar6);

      if ((((iVar4 != 0) || (iVar4 = FUN_004a6160(iVar6), iVar4 != 0)) ||

          (iVar4 = FUN_004a61a0(iVar6), iVar4 != 0)) &&

         ((iVar4 = FUN_004a6160(iVar6), iVar4 == 0 || (*(int *)(iVar6 + 0x174) == 0)))) {

        if (*(int *)(&DAT_0058c674 + iVar5) == 1) {

          if (DAT_00632d60 != 0) {

            DAT_00632d60 = 0;

            for (puVar1 = DAT_00632d68; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1)

            {

              iVar6 = puVar1[3];

              if ((*(uint *)(iVar6 + 0xd8) & 0x800000) != 0) {

                iVar5 = FUN_0052e4a0(iVar6);

                if (iVar5 != 0) {

                  iVar5 = FUN_004a6180(iVar6);

                  if (((iVar5 == 0) && (iVar5 = FUN_004a6160(iVar6), iVar5 == 0)) &&

                     (iVar5 = FUN_004a61a0(iVar6), iVar5 == 0)) {

                    FUN_00530b70(iVar6);

                  }

                  else {

                    FUN_00530b10(iVar6);

                  }

                }

                FUN_00497510(iVar6);

              }

            }

            mem_free_tagged(DAT_005989c0,s_C__Giants_source_main_demo_c_00556474,0x3cd);

            DAT_005989c0 = 0;

            mem_free_tagged(DAT_005989cc,s_C__Giants_source_main_demo_c_00556474,0x3cf);

            _DAT_00599988 = 0;

            DAT_0059998c = 0;

            DAT_005989cc = 0;

            _DAT_00599990 = 0;

          }

          return 1;

        }

        iVar6 = FUN_004a6180(iVar6);

        if (iVar6 != 0) {

          uVar3 = *(undefined4 *)(&DAT_0058c6cc + iVar5);

          *(undefined4 *)(&DAT_0058c6cc + iVar5) = DAT_0059ab78;

          DAT_0059ab78 = uVar3;

        }

      }

    }

  } while (!bVar2);

  return 1;

}

