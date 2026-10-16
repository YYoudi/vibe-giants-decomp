/* Giants 1.449 — module main/readobjs
 * 1 functions (1 named) — decompiled, names from PS2 symbols
 * Original source: C:\Giants\source\main/readobjs.c(pp) (assert-string evidence)
 */

/* ===== readobjs_load_object @ 0x004B0540 ===== */
void readobjs_load_object(void)



{

  undefined4 *puVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  undefined4 *puVar5;

  int *piVar6;

  undefined4 *puVar7;

  int *local_c;

  int *local_8;

  

  puVar7 = DAT_00632d54;

  while (puVar7 != (undefined4 *)0x0) {

    puVar1 = (undefined4 *)*puVar7;

    iVar3 = 0;

    if (0 < (int)puVar7[1]) {

      puVar5 = puVar7 + 0x79;

      do {

        if (0 < (int)puVar5[-1]) {

          mem_free_tagged(*puVar5,s_C__Giants_source_main_readobjs_c_00560254,0x6ba);

        }

        object_free_all_allocated_data((OBJECT *)(puVar5 + -0x77));

        iVar3 = iVar3 + 1;

        puVar5 = puVar5 + 0xc1;

      } while (iVar3 < (int)puVar7[1]);

    }

    mem_free_tagged(puVar7,s_C__Giants_source_main_readobjs_c_00560254,0x6bf);

    puVar7 = puVar1;

  }

  DAT_00632d54 = (undefined4 *)0x0;

  puVar7 = DAT_00632d50;

  while (puVar7 != (undefined4 *)0x0) {

    puVar1 = (undefined4 *)*puVar7;

    iVar3 = 0;

    if (0 < (int)puVar7[1]) {

      puVar5 = puVar7 + 2;

      do {

        piVar6 = puVar5 + 2;

        local_8 = (int *)0xfe;

        do {

          if ((*piVar6 != 0) && (iVar2 = *(int *)(*piVar6 + 0x24), iVar2 != 0)) {

            mem_free_tagged(iVar2,s_C__Giants_source_main_readobjs_c_00560254,0x6ca);

          }

          piVar6 = piVar6 + 1;

          local_8 = (int *)((int)local_8 + -1);

        } while (local_8 != (int *)0x0);

        mem_free_tagged(puVar5[0x117],s_C__Giants_source_main_readobjs_c_00560254,0x6cb);

        puVar5[0x117] = 0;

        mem_free_tagged(puVar5[0x115],s_C__Giants_source_main_readobjs_c_00560254,0x6cd);

        puVar5[0x115] = 0;

        main_animate_004057d0(puVar5);

        iVar3 = iVar3 + 1;

        puVar5 = puVar5 + 0x119;

      } while (iVar3 < (int)puVar7[1]);

    }

    mem_free_tagged(puVar7,s_C__Giants_source_main_readobjs_c_00560254,0x6d1);

    puVar7 = puVar1;

  }

  DAT_00632d50 = (undefined4 *)0x0;

  local_8 = DAT_00632d4c;

  if (DAT_00632d4c != (int *)0x0) {

    do {

      piVar6 = (int *)*local_8;

      iVar3 = 0;

      if (0 < local_8[1]) {

        local_c = local_8 + 2;

        do {

          iVar2 = *local_c;

          main_animate_00405780(iVar2);

          iVar4 = 0;

          if (0 < *(int *)(iVar2 + 0x68)) {

            puVar7 = (undefined4 *)(iVar2 + 0x74);

            do {

              mem_free_tagged(puVar7[4],s_C__Giants_source_main_readobjs_c_00560254,0x6de);

              mem_free_tagged(*puVar7,s_C__Giants_source_main_readobjs_c_00560254,0x6df);

              iVar4 = iVar4 + 1;

              puVar7 = puVar7 + 0x14;

            } while (iVar4 < *(int *)(iVar2 + 0x68));

          }

          if (*(int *)(iVar2 + 0x40) != 0) {

            mem_free_tagged(*(int *)(iVar2 + 0x40),s_C__Giants_source_main_readobjs_c_00560254,0x6e1

                           );

          }

          if (*(int *)(iVar2 + 0x3c) != 0) {

            mem_free_tagged(*(int *)(iVar2 + 0x3c),s_C__Giants_source_main_readobjs_c_00560254,0x6e2

                           );

          }

          iVar4 = DAT_0059dbdc + *(int *)(iVar2 + 0x10) * -0xc;

          if (*(int *)(iVar2 + 0x20) != 0) {

            iVar4 = iVar4 + *(int *)(iVar2 + 0x18) * -2;

          }

          iVar4 = iVar4 + *(int *)(iVar2 + 0x30) * -2;

          if (*(int *)(iVar2 + 0x38) != 0) {

            iVar4 = iVar4 + *(int *)(iVar2 + 0x30) * -2;

          }

          if (*(int *)(iVar2 + 0x3c) != 0) {

            iVar4 = iVar4 + *(int *)(iVar2 + 0x30) * -8;

          }

          if (*(int *)(iVar2 + 0x40) != 0) {

            iVar4 = iVar4 + *(int *)(iVar2 + 0x30) * -3 + -1;

          }

          DAT_0059dbdc = iVar4 + *(int *)(iVar2 + 8) * -0x24 +

                         *(int *)(iVar2 + 0x68) * -0x50 + -0x74;

          if (*(int *)(iVar2 + 0x20) != 0) {

            DAT_0059dbdc = DAT_0059dbdc + (*(int *)(iVar2 + 0x24) + *(int *)(iVar2 + 0x1c)) * -0xc;

          }

          mem_free_tagged(*(undefined4 *)(iVar2 + 0x2c),s_C__Giants_source_main_readobjs_c_00560254,

                          0x6fd);

          mem_free_tagged(*(undefined4 *)(iVar2 + 0x28),s_C__Giants_source_main_readobjs_c_00560254,

                          0x6fe);

          mem_free_tagged(*(undefined4 *)(iVar2 + 0xc),s_C__Giants_source_main_readobjs_c_00560254,

                          0x6ff);

          mem_free_tagged(*(undefined4 *)(iVar2 + 0x34),s_C__Giants_source_main_readobjs_c_00560254,

                          0x700);

          mem_free_tagged(*(undefined4 *)(iVar2 + 0x38),s_C__Giants_source_main_readobjs_c_00560254,

                          0x701);

          mem_free_tagged(*(undefined4 *)(iVar2 + 0x20),s_C__Giants_source_main_readobjs_c_00560254,

                          0x702);

          mem_free_tagged(*(undefined4 *)(iVar2 + 0x14),s_C__Giants_source_main_readobjs_c_00560254,

                          0x703);

          mem_free_tagged(iVar2,s_C__Giants_source_main_readobjs_c_00560254,0x705);

          iVar3 = iVar3 + 1;

          local_c = local_c + 1;

        } while (iVar3 < local_8[1]);

      }

      mem_free_tagged(local_8,s_C__Giants_source_main_readobjs_c_00560254,0x707);

      local_8 = piVar6;

    } while (piVar6 != (int *)0x0);

    DAT_00632d4c = piVar6;

    return;

  }

  DAT_00632d4c = (int *)0x0;

  return;

}

