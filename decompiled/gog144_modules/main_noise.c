/* Giants 1.449 — module main/noise
 * 4 functions (4 named) — decompiled, names from PS2 symbols
 * Original source: C:\Giants\source\main/noise.c(pp) (assert-string evidence)
 */

/* ===== read_sfx_bin @ 0x004950A0 ===== */
void read_sfx_bin(undefined4 param_1)



{

  int iVar1;

  int iVar2;

  undefined4 uVar3;

  int iVar4;

  uint uVar5;

  int iVar6;

  int *piVar7;

  undefined4 *puVar8;

  int local_24;

  int local_20;

  int local_1c;

  int local_18;

  int local_14;

  int local_10;

  int local_c;

  int local_8;

  undefined4 local_4;

  

  if (DAT_00632dbc == (undefined4 *)0x0) {

    DAT_00632db8 = 2000;

    DAT_00632dbc = (undefined4 *)

                   FUN_0053a700(0x17,88000,s_sounds_0055c990,

                                s_C__Giants_source_main_noise_c_0055c998,0xa6);

    puVar8 = DAT_00632dbc;

    for (uVar5 = (uint)(DAT_00632db8 * 0x2c) >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {

      *puVar8 = 0;

      puVar8 = puVar8 + 1;

    }

    for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {

      *(undefined1 *)puVar8 = 0;

      puVar8 = (undefined4 *)((int)puVar8 + 1);

    }

  }

  if (DAT_006331fc == 0) {

    FUN_005178d0(param_1,&local_24,4);

    if (local_24 == -1) {

      FUN_005178d0(param_1,&local_18,4);

      FUN_005178d0(param_1,&local_24,4);

      FUN_005178d0(param_1,&local_8,4);

      FUN_005178d0(param_1,&local_1c,4);

      local_14 = 0x14;

    }

    else {

      local_1c = local_24 * 0x1c;

      local_18 = 0x33221100;

      local_8 = 0x1c;

      local_14 = 0;

    }

    if (local_24 != 0) {

      iVar6 = FUN_0053a700(0x17,local_1c,s_sfxdef_0055c988,s_C__Giants_source_main_noise_c_0055c998,

                           0xc6);

      local_c = iVar6;

      FUN_005178d0(param_1,iVar6,local_1c - local_14);

      local_10 = 0;

      if (0 < local_24) {

        do {

          iVar1 = *(int *)(local_10 * local_8 + iVar6);

          iVar6 = local_10 * local_8 + iVar6;

          iVar2 = DAT_00632dbc[iVar1 * 0xb + 1];

          mem_free_tagged(DAT_00632dbc[iVar1 * 0xb],s_C__Giants_source_main_noise_c_0055c998,0xe1);

          DAT_00632dbc[iVar1 * 0xb] = 0;

          DAT_00632dbc[iVar1 * 0xb + 3] = *(undefined4 *)(iVar6 + 4);

          if (iVar1 == 0x692) {

            DAT_00632dbc[0x4849] = DAT_00632dbc[0x4849] | 1;

          }

          DAT_00632dbc[iVar1 * 0xb + 7] = *(undefined4 *)(iVar6 + 8);

          DAT_00632dbc[iVar1 * 0xb + 5] = *(undefined4 *)(iVar6 + 0xc);

          DAT_00632dbc[iVar1 * 0xb + 6] = *(undefined4 *)(iVar6 + 0x10);

          if (local_18 == 0x33221100) {

            DAT_00632dbc[iVar1 * 0xb + 9] = 0;

            DAT_00632dbc[iVar1 * 0xb + 10] = 0;

            local_20 = *(int *)(iVar6 + 0x18);

            if (iVar2 == 0) {

              FUN_00517930(param_1,*(undefined4 *)(iVar6 + 0x14));

              uVar3 = FUN_0053a700(0x17,local_20,&PTR_DAT_0055c984,

                                   s_C__Giants_source_main_noise_c_0055c998,0x107);

              DAT_00632dbc[iVar1 * 0xb + 1] = uVar3;

              DAT_00630ed0 = DAT_00630ed0 + local_20;

              FUN_005178d0(param_1,DAT_00632dbc[iVar1 * 0xb + 1],local_20);

            }

          }

          else {

            DAT_00632dbc[iVar1 * 0xb + 9] = *(undefined4 *)(iVar6 + 0x14);

            DAT_00632dbc[iVar1 * 0xb + 10] = *(undefined4 *)(iVar6 + 0x18);

            piVar7 = (int *)(iVar6 + 0x1c);

            if (local_18 == 0x33221102) {

              iVar4 = FUN_0052aa70();

              if (iVar4 != 0) {

                DAT_00632dbc[iVar1 * 0xb + 9] = *piVar7;

              }

              iVar4 = FUN_0052aa70();

              if (iVar4 != 0) {

                DAT_00632dbc[iVar1 * 0xb + 10] = *(undefined4 *)(iVar6 + 0x20);

              }

              piVar7 = (int *)(iVar6 + 0x24);

            }

            iVar6 = (*piVar7 - local_14) + local_c;

            if (iVar2 == 0) {

              vfs_fileread_load(iVar6,&local_4,&local_20);

              DAT_00630ed0 = DAT_00630ed0 + local_20;

              if (local_20 == 0) {

                FUN_00542f27(&DAT_00657400,s_Failed_binread__s_0055c970,iVar6);

                FUN_00425eb0(&DAT_00657400);

              }

              DAT_00632dbc[iVar1 * 0xb + 1] = local_4;

            }

          }

          uVar3 = FUN_0053a700(0x17,8,&DAT_0055c96c,s_C__Giants_source_main_noise_c_0055c998,0x134);

          DAT_00632dbc[iVar1 * 0xb] = uVar3;

          FUN_00542f27(DAT_00632dbc[iVar1 * 0xb],s_SFX_d_0055c964,iVar1);

          local_10 = local_10 + 1;

          iVar6 = local_c;

        } while (local_10 < local_24);

      }

      mem_free_tagged(iVar6,s_C__Giants_source_main_noise_c_0055c998,0x138);

    }

  }

  return;

}

/* ===== main_noise_00495430 @ 0x00495430 ===== */
void main_noise_00495430(void)



{

  int iVar1;

  int iVar2;

  int iVar3;

  

  if (DAT_00632dbc != 0) {

    iVar2 = 0;

    if (0 < DAT_00632db8) {

      iVar3 = 0;

      do {

        iVar1 = iVar3 + DAT_00632dbc;

        if (iVar1 != 0) {

          if (*(int *)(iVar1 + 8) != 0) {

            (*DAT_005dd29c)(iVar1);

          }

          if (*(int *)(iVar1 + 4) != 0) {

            utils_fileread_00538560(*(int *)(iVar1 + 4));

            *(undefined4 *)(iVar1 + 4) = 0;

          }

        }

        if (*(int *)(iVar3 + DAT_00632dbc) != 0) {

          mem_free_tagged(*(int *)(iVar3 + DAT_00632dbc),s_C__Giants_source_main_noise_c_0055c998,

                          0x145);

        }

        *(undefined4 *)(iVar3 + DAT_00632dbc) = 0;

        iVar2 = iVar2 + 1;

        iVar3 = iVar3 + 0x2c;

      } while (iVar2 < DAT_00632db8);

    }

    mem_free_tagged(DAT_00632dbc,s_C__Giants_source_main_noise_c_0055c998,0x148);

    DAT_00632dbc = 0;

  }

  DAT_00630ed0 = 0;

  return;

}

/* ===== sound_get_free_sequence__Fv @ 0x00495F20 ===== */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */



int sound_get_free_sequence__Fv(void)



{

  int iVar1;

  undefined4 *puVar2;

  int *piVar3;

  int iVar4;

  int *piVar5;

  bool bVar6;

  int in_stack_00000004;

  int in_stack_00000008;

  int in_stack_0000000c;

  int in_stack_00000010;

  int in_stack_00000014;

  int *in_stack_00000018;

  uint in_stack_0000001c;

  

  if (DAT_00633200 != 0) {

    return 0;

  }

  piVar3 = DAT_0059f360;

  if (DAT_0059f360 == (int *)0x0) {

    puVar2 = (undefined4 *)

             FUN_0053a700(0x17,0x2d4,s_sequence_list_0055c9c8,

                          s_C__Giants_source_main_noise_c_0055c998,0x346);

    *puVar2 = DAT_0059f364;

    DAT_0059f360 = puVar2 + 1;

    iVar4 = 8;

    piVar3 = DAT_0059f360;

    DAT_0059f364 = puVar2;

    do {

      iVar4 = iVar4 + -1;

      *piVar3 = (int)(piVar3 + 0x12);

      piVar3 = piVar3 + 0x12;

    } while (iVar4 != 0);

    puVar2[0x91] = 0;

    piVar3 = DAT_0059f360;

  }

  DAT_0059f360 = (int *)*piVar3;

  piVar5 = piVar3;

  for (iVar4 = 0x12; iVar4 != 0; iVar4 = iVar4 + -1) {

    *piVar5 = 0;

    piVar5 = piVar5 + 1;

  }

  if ((in_stack_0000001c & 2) == 0) {

    piVar3[10] = in_stack_00000014;

  }

  else {

    if (in_stack_00000014 != 0) {

      iVar4 = *(int *)(in_stack_00000014 + 0x210);

      while (iVar1 = iVar4, iVar1 != 0) {

        in_stack_00000014 = iVar1;

        iVar4 = *(int *)(iVar1 + 0x210);

      }

    }

    if (in_stack_00000014 == DAT_00632a88) {

      in_stack_00000018 = (int *)0x0;

    }

    else {

      piVar3[10] = in_stack_00000014;

    }

  }

  piVar3[2] = in_stack_00000004;

  piVar3[3] = in_stack_00000008;

  piVar3[0xb] = in_stack_00000014;

  if ((in_stack_0000001c & 1) != 0) {

    in_stack_0000000c = 0x3f800000;

  }

  piVar3[8] = in_stack_0000000c;

  piVar3[0x10] = in_stack_0000001c;

  piVar3[4] = in_stack_00000010;

  piVar3[0x11] = DAT_0055c960;

  DAT_0055c960 = DAT_0055c960 + 1;

  if (in_stack_00000018 == (int *)0x0) {

    piVar3[0xf] = 0;

  }

  else {

    piVar3[0xc] = *in_stack_00000018;

    piVar3[0xd] = in_stack_00000018[1];

    piVar3[0xe] = in_stack_00000018[2];

    piVar3[0xf] = 1;

  }

  bVar6 = DAT_0059f368 == (int *)0x0;

  *piVar3 = 0;

  if (bVar6) {

    piVar3[1] = 0;

    DAT_0059f368 = piVar3;

  }

  else {

    piVar3[1] = (int)DAT_0059f36c;

    *DAT_0059f36c = (int)piVar3;

  }

  DAT_0059f36c = piVar3;

  if ((piVar3[0xb] != 0) && (piVar5 = DAT_0059f368, DAT_0059f368 != (int *)0x0)) {

    while (((piVar5 == piVar3 ||

            (((piVar5[0xb] != piVar3[0xb] || (piVar5[2] != piVar3[2])) || (piVar5[3] != piVar3[3])))

            ) || (piVar5[4] != piVar3[4]))) {

      piVar5 = (int *)*piVar5;

      if (piVar5 == (int *)0x0) {

        return DAT_0055c960 + -1;

      }

    }

    iVar4 = piVar5[7];

    if (iVar4 != 0) {

      if (iVar4 != 0) {

        (*DAT_005dd2a8)(iVar4);

      }

      piVar5[7] = 0;

    }

    piVar3 = (int *)piVar5[1];

    piVar5[0x11] = 0;

    if (piVar3 == (int *)0x0) {

      DAT_0059f368 = (int *)*piVar5;

      if (DAT_0059f368 != (int *)0x0) {

        *(undefined4 *)((int)DAT_0059f368 + 4) = 0;

        *piVar5 = (int)DAT_0059f360;

        DAT_0059f360 = piVar5;

        return DAT_0055c960 + -1;

      }

      DAT_0059f36c = (int *)0x0;

      *piVar5 = (int)DAT_0059f360;

      DAT_0059f360 = piVar5;

      return DAT_0055c960 + -1;

    }

    if (*piVar5 == 0) {

      DAT_0059f36c = piVar3;

      *piVar3 = 0;

    }

    else {

      *piVar3 = *piVar5;

      *(int *)(*piVar5 + 4) = piVar5[1];

    }

    *piVar5 = (int)DAT_0059f360;

    DAT_0059f360 = piVar5;

  }

  return DAT_0055c960 + -1;

}

/* ===== main_noise_00496170 @ 0x00496170 ===== */
void main_noise_00496170(void)



{

  undefined4 *puVar1;

  undefined4 *puVar2;

  

  puVar2 = DAT_0059f364;

  while (puVar2 != (undefined4 *)0x0) {

    puVar1 = (undefined4 *)*puVar2;

    mem_free_tagged(puVar2,s_C__Giants_source_main_noise_c_0055c998,0x3d4);

    puVar2 = puVar1;

  }

  DAT_0059f364 = (undefined4 *)0x0;

  DAT_0059f360 = 0;

  DAT_0059f368 = 0;

  DAT_0059f36c = 0;

  return;

}

