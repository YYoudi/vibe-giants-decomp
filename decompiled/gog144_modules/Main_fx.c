/* Giants 1.449 — module Main/fx
 * 9 functions (9 named) — decompiled, names from PS2 symbols
 * Original source: C:\Giants\source\Main/fx.c(pp) (assert-string evidence)
 */

/* ===== main_fx_004470b0 @ 0x004470B0 ===== */
void main_fx_004470b0(undefined4 param_1)



{

  int iVar1;

  int local_30;

  undefined1 local_2c [44];

  

  DAT_0059ce60 = 0;

  DAT_0059ce6c = 0;

  DAT_0059ce64 = 0;

  DAT_0059ce58 = 0;

  crt_sprintf(local_2c,s__s_bin_00554384,param_1);

  iVar1 = stream_player_start(local_2c);

  if (iVar1 == 0) {

    error_screen_show(s_Failed_to_open_Fx_bin_00558874);

    return;

  }

  BinFileRead(iVar1,&local_30,4);

  if (local_30 != 1) {

    error_screen_show(s_Bad_version_for_Fx_bin_0055885c);

    ANM_BinderDestroy_2(iVar1);

    return;

  }

  BinFileRead(iVar1,&param_1,4);

  BinFileRead(iVar1,&DAT_0059ce60,4);

  DAT_0059ce6c = MemAllocMsg(0xc,param_1,s_fx_bin_00558838,s_C__Giants_source_Main_fx_c_00558840,

                             0xbe);

  BinFileRead(iVar1,DAT_0059ce6c,param_1);

  ANM_BinderDestroy_2(iVar1);

  return;

}

/* ===== main_fx_004471a0 @ 0x004471A0 ===== */
void main_fx_004471a0(void)



{

  undefined4 *puVar1;

  undefined4 *puVar2;

  

  if (DAT_006330e4 != 0) {

    world_fx_release();

    if (DAT_0059ce6c != 0) {

      mem_free_tagged(DAT_0059ce6c,s_C__Giants_source_Main_fx_c_00558840,0xdf);

    }

    DAT_0059ce6c = 0;

    DAT_0059ce64 = 0;

    puVar2 = DAT_0059ce74;

    while (puVar2 != (undefined4 *)0x0) {

      puVar1 = (undefined4 *)*puVar2;

      mem_free_tagged(puVar2,s_C__Giants_source_Main_fx_c_00558840,0xe9);

      puVar2 = puVar1;

    }

    DAT_0059ce74 = (undefined4 *)0x0;

    DAT_0059ce70 = 0;

  }

  return;

}

/* ===== fx_setupWeather__Fi @ 0x00447270 ===== */
int fx_setupWeather__Fi(undefined4 param_1)



{

  int iVar1;

  int iVar2;

  undefined4 *puVar3;

  int iVar4;

  

  iVar2 = object_allocate_type(param_1,0);

  iVar1 = *(int *)(iVar2 + 0x100);

  *(uint *)(iVar2 + 0x1c8) = *(uint *)(iVar2 + 0x1c8) & 0xfffdffff | 0x800;

  *(uint *)(iVar2 + 0xd8) = *(uint *)(iVar2 + 0xd8) | 0x40010020;

  *(uint *)(iVar2 + 0x294) = *(uint *)(iVar2 + 0x294) | 0x10;

  *(uint *)(iVar2 + 0xe4) = *(uint *)(iVar2 + 0xe4) | 1;

  puVar3 = (undefined4 *)

           MemAllocMsg(0xc,0xa0,s_fx_weather_0055888c,s_C__Giants_source_Main_fx_c_00558840,0x13e);

  *(undefined4 **)(iVar1 + 0x100) = puVar3;

  for (iVar4 = 0x28; iVar4 != 0; iVar4 = iVar4 + -1) {

    *puVar3 = 0;

    puVar3 = puVar3 + 1;

  }

  **(undefined4 **)(iVar1 + 0x100) = 0x43fa0000;

  *(undefined4 *)(*(int *)(iVar1 + 0x100) + 4) = 0x43480000;

  *(undefined4 *)(*(int *)(iVar1 + 0x100) + 0x14) = 100;

  *(undefined4 *)(*(int *)(iVar1 + 0x100) + 0x10) = 0;

  *(undefined4 *)(*(int *)(iVar1 + 0x100) + 0xc) = 0x40800000;

  *(int *)(iVar2 + 0x104) = iVar1 + 0xa0;

  PhysicsExZeroForce(iVar2);

  *(uint *)(iVar2 + 0xd8) = *(uint *)(iVar2 + 0xd8) | 0x10;

  *(undefined4 *)(iVar2 + 0x1e8) = 0x42480000;

  return iVar2;

}

/* ===== fx_get_free_effect__Fv @ 0x004481E0 ===== */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

/* PS2 candidate: fx_create (conf 0.622) */



undefined4 * fx_get_free_effect__Fv(void)



{

  int iVar1;

  int *piVar2;

  undefined4 uVar3;

  int *piVar4;

  int iVar5;

  undefined4 *puVar6;

  int *piVar7;

  undefined4 *puVar8;

  int iVar9;

  bool bVar10;

  float10 fVar11;

  char *in_stack_00000004;

  uint in_stack_00000008;

  int *in_stack_0000000c;

  int local_25c;

  float local_258;

  int local_254;

  int local_250;

  int local_24c;

  int local_248;

  uint local_244;

  undefined1 local_240 [64];

  undefined1 local_200 [512];

  

  iVar1 = comm_00426540();

  if ((iVar1 != 0) && ((in_stack_00000008 & 2) == 0)) {

    return (undefined4 *)0x0;

  }

  local_244 = in_stack_00000008 & 8;

  if (local_244 == 0) {

    if ((in_stack_00000008 & 4) == 0) {

      piVar2 = (int *)XFGetCameraOrigin();

      local_250 = *piVar2;

      local_24c = piVar2[1];

      local_248 = piVar2[2];

    }

    else {

      iVar1 = in_stack_0000000c[6];

      local_250 = *(int *)(iVar1 + 0xa0);

      local_24c = *(int *)(iVar1 + 0xa4);

      local_248 = *(int *)(iVar1 + 0xa8);

    }

  }

  else {

    local_250 = in_stack_0000000c[1];

    local_24c = in_stack_0000000c[2];

    local_248 = in_stack_0000000c[3];

  }

  if ((in_stack_00000008 & 0x10) == 0) {

    local_254 = object_get_num_objects(&local_25c);

    if ((float)local_254 / (float)local_25c <= *(float *)(DAT_00632ed8 + 0x13e0)) {

      local_258 = *(float *)(DAT_00632ed8 + 0x1570);

      uVar3 = XFGetCameraOrigin(&local_250);

      fVar11 = (float10)FUN_0050a610(uVar3);

      if (fVar11 <= (float10)local_258 * (float10)local_258) {

        iVar1 = 0;

        piVar2 = DAT_0059ce6c;

        piVar4 = DAT_0059ce6c;

        if (0 < DAT_0059ce60) {

          do {

            do {

              piVar7 = piVar2;

              piVar2 = (int *)((int)piVar7 + 1);

            } while ((char)*piVar7 != '\0');

            iVar9 = *(int *)((int)piVar7 + 1);

            iVar5 = FUN_00545650(piVar4,in_stack_00000004);

            if (iVar5 == 0) goto LAB_00448378;

            iVar1 = iVar1 + 1;

            piVar2 = (int *)((int)piVar7 + 5);

            piVar4 = (int *)((int)piVar7 + 5);

          } while (iVar1 < DAT_0059ce60);

        }

        goto LAB_0044838a;

      }

    }

    crt_sprintf(local_240,s__s_lite_00558c74,in_stack_00000004);

    iVar1 = 0;

    piVar2 = DAT_0059ce6c;

    piVar4 = DAT_0059ce6c;

    if (0 < DAT_0059ce60) {

      do {

        do {

          piVar7 = piVar2;

          piVar2 = (int *)((int)piVar7 + 1);

        } while ((char)*piVar7 != '\0');

        iVar9 = *(int *)((int)piVar7 + 1);

        iVar5 = FUN_00545650(piVar4,local_240);

        if (iVar5 == 0) {

          if (iVar9 != -1) goto LAB_00448378;

          break;

        }

        iVar1 = iVar1 + 1;

        piVar2 = (int *)((int)piVar7 + 5);

        piVar4 = (int *)((int)piVar7 + 5);

      } while (iVar1 < DAT_0059ce60);

    }

    iVar1 = 0;

    piVar2 = DAT_0059ce6c;

    piVar4 = DAT_0059ce6c;

    if (0 < DAT_0059ce60) {

      do {

        do {

          piVar7 = piVar2;

          piVar2 = (int *)((int)piVar7 + 1);

        } while ((char)*piVar7 != '\0');

        iVar9 = *(int *)((int)piVar7 + 1);

        iVar5 = FUN_00545650(piVar4,in_stack_00000004);

        if (iVar5 == 0) goto LAB_00448378;

        iVar1 = iVar1 + 1;

        piVar2 = (int *)((int)piVar7 + 5);

        piVar4 = (int *)((int)piVar7 + 5);

      } while (iVar1 < DAT_0059ce60);

    }

    goto LAB_0044838a;

  }

  local_258 = (float)object_get_num_objects(&local_254);

  local_25c = *in_stack_0000000c;

  if (*(float *)(DAT_00632ed8 + 0x13e0) < (float)(int)local_258 / (float)local_254) {

LAB_004482f1:

    iVar1 = 0;

    piVar2 = DAT_0059ce6c;

    piVar4 = DAT_0059ce6c;

    if (0 < DAT_0059ce60) {

      do {

        do {

          piVar7 = piVar2;

          piVar2 = (int *)((int)piVar7 + 1);

        } while ((char)*piVar7 != '\0');

        if (*in_stack_0000000c == *(int *)((int)piVar7 + 1)) goto LAB_0044831d;

        iVar1 = iVar1 + 1;

        piVar2 = (int *)((int)piVar7 + 5);

        piVar4 = (int *)((int)piVar7 + 5);

      } while (iVar1 < DAT_0059ce60);

    }

    piVar4 = (int *)0x0;

LAB_0044831d:

    crt_sprintf(local_240,s__s_lite_00558c74,piVar4);

    iVar1 = 0;

    piVar2 = DAT_0059ce6c;

    piVar4 = DAT_0059ce6c;

    if (0 < DAT_0059ce60) {

      do {

        do {

          piVar7 = piVar2;

          piVar2 = (int *)((int)piVar7 + 1);

        } while ((char)*piVar7 != '\0');

        iVar9 = *(int *)((int)piVar7 + 1);

        iVar5 = FUN_00545650(piVar4,local_240);

        if (iVar5 == 0) {

          if (iVar9 != -1) {

LAB_00448378:

            local_25c = iVar9;

          }

          break;

        }

        iVar1 = iVar1 + 1;

        piVar2 = (int *)((int)piVar7 + 5);

        piVar4 = (int *)((int)piVar7 + 5);

      } while (iVar1 < DAT_0059ce60);

    }

  }

  else {

    local_258 = *(float *)(DAT_00632ed8 + 0x1570);

    uVar3 = XFGetCameraOrigin(&local_250);

    fVar11 = (float10)FUN_0050a610(uVar3);

    if ((float10)local_258 * (float10)local_258 < fVar11) goto LAB_004482f1;

  }

  if (0 < local_25c) {

    puVar8 = DAT_0059ce70;

    if (DAT_0059ce70 == (undefined4 *)0x0) {

      puVar6 = (undefined4 *)

               MemAllocMsg(0xc,0x5144,s_fx_list_00558c4c,s_C__Giants_source_Main_fx_c_00558840,0x4c2

                          );

      *puVar6 = DAT_0059ce74;

      DAT_0059ce70 = puVar6 + 1;

      iVar1 = 0x62;

      puVar8 = DAT_0059ce70;

      DAT_0059ce74 = puVar6;

      do {

        iVar1 = iVar1 + -1;

        *puVar8 = puVar8 + 0x34;

        puVar8 = puVar8 + 0x34;

      } while (iVar1 != 0);

      puVar6[0x13e9] = 0;

      puVar8 = DAT_0059ce70;

    }

    DAT_0059ce70 = (undefined4 *)*puVar8;

    bVar10 = DAT_0059ce64 == (undefined4 *)0x0;

    *puVar8 = 0;

    if (bVar10) {

      puVar8[1] = 0;

      DAT_0059ce64 = puVar8;

    }

    else {

      puVar8[1] = DAT_0059ce58;

      *DAT_0059ce58 = puVar8;

    }

    puVar6 = puVar8 + 2;

    DAT_0059ce58 = puVar8;

    for (iVar1 = 0x32; iVar1 != 0; iVar1 = iVar1 + -1) {

      *puVar6 = 0;

      puVar6 = puVar6 + 1;

    }

    if (in_stack_00000004 == (char *)0x0) {

      iVar1 = 0;

      piVar2 = DAT_0059ce6c;

      piVar4 = DAT_0059ce6c;

      if (0 < DAT_0059ce60) {

        do {

          do {

            piVar7 = piVar2;

            piVar2 = (int *)((int)piVar7 + 1);

          } while ((char)*piVar7 != '\0');

          if (local_25c == *(int *)((int)piVar7 + 1)) goto LAB_004485e3;

          iVar1 = iVar1 + 1;

          piVar2 = (int *)((int)piVar7 + 5);

          piVar4 = (int *)((int)piVar7 + 5);

        } while (iVar1 < DAT_0059ce60);

      }

      piVar4 = (int *)0x0;

LAB_004485e3:

      _strncpy((char *)(puVar8 + 10),(char *)piVar4,0x10);

    }

    else {

      _strncpy((char *)(puVar8 + 10),in_stack_00000004,0x10);

    }

    puVar8[2] = (char *)((int)DAT_0059ce6c + local_25c);

    puVar8[5] = 0;

    if (local_244 != 0) {

      puVar8[7] = in_stack_0000000c[1];

      puVar8[8] = in_stack_0000000c[2];

      puVar8[9] = in_stack_0000000c[3];

    }

    if ((in_stack_00000008 & 1) != 0) {

      puVar8[6] = puVar8[6] | 0x1000;

      GEO_MatBuildXYZ(puVar8 + 0x1f,in_stack_0000000c[8],in_stack_0000000c[9],in_stack_0000000c[7]);

    }

    if ((in_stack_00000008 & 2) != 0) {

      puVar8[0x30] = in_stack_0000000c[10];

      puVar8[0x31] = in_stack_0000000c[0xb];

    }

    if ((in_stack_00000008 & 4) != 0) {

      puVar8[6] = puVar8[6] | 4;

      puVar8[0x11] = in_stack_0000000c[6];

      puVar8[0x12] = in_stack_0000000c[5];

      if ((*(uint *)(in_stack_0000000c[6] + 0xd8) & 0x400) != 0) {

        if ((in_stack_00000008 & 0x20) == 0) {

          in_stack_00000008 = in_stack_00000008 | 0x20;

          in_stack_0000000c[4] = 0;

        }

        in_stack_0000000c[4] = in_stack_0000000c[4] | 1;

      }

    }

    if ((in_stack_00000008 & 0x40) != 0) {

      puVar8[4] = in_stack_0000000c[0xc];

    }

    if ((in_stack_00000008 & 0x20) != 0) {

      if ((*(byte *)(in_stack_0000000c + 4) & 2) != 0) {

        puVar8[6] = puVar8[6] | 0x4000;

      }

      if ((*(byte *)(in_stack_0000000c + 4) & 4) != 0) {

        puVar8[6] = puVar8[6] | 0x8000;

      }

      if ((*(byte *)(in_stack_0000000c + 4) & 1) != 0) {

        puVar8[6] = puVar8[6] | 0x10000;

      }

      if ((*(byte *)(in_stack_0000000c + 4) & 0x10) != 0) {

        puVar8[6] = puVar8[6] | 0x200000;

      }

      if ((*(byte *)(in_stack_0000000c + 4) & 8) != 0) {

        puVar8[6] = puVar8[6] | 0x20000;

      }

    }

    puVar6 = puVar8 + 0x19;

    iVar1 = 6;

    do {

      puVar6[-6] = 0;

      *puVar6 = 0xffffffff;

      puVar6 = puVar6 + 1;

      iVar1 = iVar1 + -1;

    } while (iVar1 != 0);

    fx_processOpCodes(puVar8 + 2,1,0);

    return puVar8;

  }

LAB_0044838a:

  crt_sprintf(local_200,s_fx_create_failed_to_find___s__00558c54,in_stack_00000004);

  FUN_0051ea20(local_200);

  return (undefined4 *)0x0;

}

/* ===== fx_stackPop__FPP10FXSTACKTAGT0 @ 0x00448A40 ===== */
/* PS2 candidate: fx_stackPop__FPP10FXSTACKTAGT0 (conf 0.521) */



void fx_stackPop__FPP10FXSTACKTAGT0(int *param_1,undefined4 *param_2)



{

  undefined4 *puVar1;

  undefined4 *puVar2;

  int iVar3;

  undefined4 *puVar4;

  

  puVar1 = (undefined4 *)*param_2;

  puVar2 = (undefined4 *)*param_1;

  if (puVar2 == puVar1) {

    iVar3 = puVar2[1];

    if ((char)((uint)*(undefined4 *)(iVar3 + 0xe0) >> 8) < '\0') {

      fxobj_delete__FP6OBJECTP7FxOspeci(iVar3,*(undefined4 *)(iVar3 + 0x100),0);

    }

    mem_free_tagged(*param_1,s_C__Giants_source_Main_fx_c_00558840,0x66a);

    *param_1 = 0;

    *param_2 = 0;

    return;

  }

  for (puVar4 = (undefined4 *)*puVar1; puVar4 != puVar2; puVar4 = (undefined4 *)*puVar4) {

    puVar1 = puVar4;

  }

  *puVar1 = 0;

  iVar3 = *(int *)(*param_1 + 4);

  if ((char)((uint)*(undefined4 *)(iVar3 + 0xe0) >> 8) < '\0') {

    fxobj_delete__FP6OBJECTP7FxOspeci(iVar3,*(undefined4 *)(iVar3 + 0x100),0);

  }

  mem_free_tagged(*param_1,s_C__Giants_source_Main_fx_c_00558840,0x680);

  *param_1 = (int)puVar1;

  return;

}

/* ===== fx_setupEmitter__FP6FxDataP10FXSTACKTAGifiiiiii @ 0x00449400 ===== */
void fx_setupEmitter__FP6FxDataP10FXSTACKTAGifiiiiii

               (int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,

               undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9,

               undefined4 param_10)



{

  uint *puVar1;

  int *piVar2;

  int *piVar3;

  int iVar4;

  undefined4 *puVar5;

  int iVar6;

  int iVar7;

  int *piVar8;

  undefined4 *puVar9;

  int local_204;

  undefined1 local_200 [512];

  

  if (param_2 == 0) {

    crt_sprintf(local_200,s_Failed_to_emit_particle_for_fx___00559708,DAT_0059ce5c + 0x20);

    FUN_0051ea20(local_200);

    return;

  }

  local_204 = 0;

  piVar2 = DAT_0059ce6c;

  piVar8 = DAT_0059ce6c;

  if (0 < DAT_0059ce60) {

    do {

      do {

        piVar3 = piVar2;

        piVar2 = (int *)((int)piVar3 + 1);

      } while ((char)*piVar3 != '\0');

      iVar7 = *(int *)((int)piVar3 + 1);

      iVar4 = FUN_00545650(piVar8,param_3);

      if (iVar4 == 0) {

        if (-1 < iVar7) {

          iVar4 = *(int *)(*(int *)(param_2 + 4) + 0x100);

          if (*(int *)(iVar4 + 0x104) == 0) {

            puVar5 = (undefined4 *)

                     MemAllocMsg(0xc,0x4dc,s_fx_emitter_00559784,

                                 s_C__Giants_source_Main_fx_c_00558840,0xbd3);

            *(undefined4 **)(iVar4 + 0x104) = puVar5;

            for (iVar6 = 0x137; iVar6 != 0; iVar6 = iVar6 + -1) {

              *puVar5 = 0;

              puVar5 = puVar5 + 1;

            }

          }

          if (9 < *(int *)(*(int *)(iVar4 + 0x104) + 400)) {

            crt_sprintf(local_200,s_Failed_to_emit_particle_for_fx___00559740,DAT_0059ce5c + 0x20,10

                       );

            FUN_0051ea20(local_200);

            return;

          }

          puVar1 = (uint *)(*(int *)(param_2 + 4) + 0xe0);

          *puVar1 = *puVar1 | 0x2000;

          *(int *)(*(int *)(iVar4 + 0x104) + *(int *)(*(int *)(iVar4 + 0x104) + 400) * 4) = iVar7;

          *(undefined4 *)

           (*(int *)(iVar4 + 0x104) + 0x28 + *(int *)(*(int *)(iVar4 + 0x104) + 400) * 4) = param_4;

          *(undefined4 *)

           (*(int *)(iVar4 + 0x104) + 0x78 + *(int *)(*(int *)(iVar4 + 0x104) + 400) * 4) = param_5;

          *(undefined4 *)

           (*(int *)(iVar4 + 0x104) + 0xa0 + *(int *)(*(int *)(iVar4 + 0x104) + 400) * 4) = param_6;

          *(undefined4 *)

           (*(int *)(iVar4 + 0x104) + 200 + *(int *)(*(int *)(iVar4 + 0x104) + 400) * 4) = param_7;

          *(undefined4 *)

           (*(int *)(iVar4 + 0x104) + 0xf0 + *(int *)(*(int *)(iVar4 + 0x104) + 400) * 4) = param_8;

          *(undefined4 *)

           (*(int *)(iVar4 + 0x104) + 0x118 + *(int *)(*(int *)(iVar4 + 0x104) + 400) * 4) = param_9

          ;

          *(undefined4 *)

           (*(int *)(iVar4 + 0x104) + 0x140 + *(int *)(*(int *)(iVar4 + 0x104) + 400) * 4) =

               param_10;

          *(undefined4 *)

           (*(int *)(iVar4 + 0x104) + 0x50 + *(int *)(*(int *)(iVar4 + 0x104) + 400) * 4) = 0;

          *(undefined4 *)

           (*(int *)(iVar4 + 0x104) + 0x168 + *(int *)(*(int *)(iVar4 + 0x104) + 400) * 4) =

               0xbf800000;

          iVar7 = *(int *)(param_2 + 4);

          puVar5 = (undefined4 *)

                   (*(int *)(iVar4 + 0x104) + 0x43c + *(int *)(*(int *)(iVar4 + 0x104) + 400) * 0xc)

          ;

          *puVar5 = *(undefined4 *)(iVar7 + 0xa0);

          puVar5[1] = *(undefined4 *)(iVar7 + 0xa4);

          puVar5[2] = *(undefined4 *)(iVar7 + 0xa8);

          if ((*(uint *)(param_1 + 0x10) & 0x1000) != 0) {

            puVar1 = (uint *)(*(int *)(param_2 + 4) + 0xe0);

            *puVar1 = *puVar1 | 0x800;

            puVar5 = (undefined4 *)(param_1 + 0x74);

            puVar9 = (undefined4 *)(iVar4 + 0x3c);

            for (iVar7 = 0x11; iVar7 != 0; iVar7 = iVar7 + -1) {

              *puVar9 = *puVar5;

              puVar5 = puVar5 + 1;

              puVar9 = puVar9 + 1;

            }

          }

          *(int *)(*(int *)(iVar4 + 0x104) + 400) = *(int *)(*(int *)(iVar4 + 0x104) + 400) + 1;

          return;

        }

        break;

      }

      local_204 = local_204 + 1;

      piVar2 = (int *)((int)piVar3 + 5);

      piVar8 = (int *)((int)piVar3 + 5);

    } while (local_204 < DAT_0059ce60);

  }

  crt_sprintf(local_200,s_Failed_to_emit_particle_for_fx___00559790,DAT_0059ce5c + 0x20,param_3);

  FUN_0051ea20(local_200);

  return;

}

/* ===== fx_setupTracer__FP10FXSTACKTAG @ 0x004496D0 ===== */
void fx_setupTracer__FP10FXSTACKTAG(int param_1)



{

  uint *puVar1;

  int iVar2;

  undefined4 *puVar3;

  undefined4 uVar4;

  undefined1 local_200 [512];

  

  if (param_1 == 0) {

    crt_sprintf(local_200,s_Failed_to_setup_tracer_fx___s____005597cc,DAT_0059ce5c + 0x20);

    FUN_0051ea20(local_200);

  }

  else {

    iVar2 = *(int *)(*(int *)(param_1 + 4) + 0x100);

    if (*(int *)(iVar2 + 0xf8) == 0) {

      puVar3 = (undefined4 *)

               MemAllocMsg(0xc,0x14,s_fx_tracer_00559800,s_C__Giants_source_Main_fx_c_00558840,0xc15

                          );

      *(undefined4 **)(iVar2 + 0xf8) = puVar3;

      *puVar3 = 0;

      puVar3[1] = 0;

      puVar3[2] = 0;

      puVar3[3] = 0;

      puVar3[4] = 0;

    }

    if (**(int **)(iVar2 + 0xf8) == 0) {

      (*(int **)(iVar2 + 0xf8))[1] = -1;

      *(undefined4 *)(*(int *)(iVar2 + 0xf8) + 8) = 0;

      uVar4 = tracer_get_tracer(*(int *)(iVar2 + 0xf8) + 4);

      **(undefined4 **)(iVar2 + 0xf8) = uVar4;

      if (**(int **)(iVar2 + 0xf8) != 0) {

        puVar1 = (uint *)(*(int *)(param_1 + 4) + 0xe0);

        *puVar1 = *puVar1 | 0x4000;

        puVar1 = (uint *)(*(int *)(param_1 + 4) + 0xe4);

        *puVar1 = *puVar1 | 0x2000;

        *(undefined4 *)(**(int **)(iVar2 + 0xf8) + 0x3c) = 0x40400000;

        *(undefined4 *)(**(int **)(iVar2 + 0xf8) + 0x38) = 0x3dcccccd;

        tracer_add_ref(**(undefined4 **)(iVar2 + 0xf8));

        return;

      }

    }

  }

  return;

}

/* ===== fx_setupTextureAnimtion__FP10FXSTACKTAGif @ 0x004498E0 ===== */
void fx_setupTextureAnimtion__FP10FXSTACKTAGif(int param_1,int param_2,undefined4 param_3)



{

  undefined4 uVar1;

  char *pcVar2;

  int iVar3;

  char local_280 [128];

  undefined1 local_200 [512];

  

  if (param_1 == 0) {

    crt_sprintf(local_200,s_Failed_to_setup_texture_animatio_00559a00,DAT_0059ce5c + 0x20);

    FUN_0051ea20(local_200);

  }

  else {

    *(uint *)(*(int *)(param_1 + 4) + 0xe0) = *(uint *)(*(int *)(param_1 + 4) + 0xe0) | 0x10000;

    uVar1 = MemAllocMsg(0xc,0x14,s_Fx_Texture_Animation_00559a60,

                        s_C__Giants_source_Main_fx_c_00558840,0xd25);

    *(undefined4 *)(*(int *)(param_1 + 4) + 0x2f4) = uVar1;

    *(int *)(*(int *)(*(int *)(param_1 + 4) + 0x2f4) + 4) = param_2;

    *(undefined4 *)(*(int *)(*(int *)(param_1 + 4) + 0x2f4) + 0xc) = param_3;

    *(undefined4 *)(*(int *)(*(int *)(param_1 + 4) + 0x2f4) + 8) = 0;

    *(undefined4 *)(*(int *)(*(int *)(param_1 + 4) + 0x2f4) + 0x10) = 0;

    uVar1 = MemAllocMsg(0xc,param_2 * 4,s_Fx_Texture_Frames_00559a4c,

                        s_C__Giants_source_Main_fx_c_00558840,0xd2b);

    **(undefined4 **)(*(int *)(param_1 + 4) + 0x2f4) = uVar1;

    *(undefined4 *)**(undefined4 **)(*(int *)(param_1 + 4) + 0x2f4) =

         *(undefined4 *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 8) + 0x400) + 0x90);

    crt_sprintf(local_280,&DAT_00555df0,

                **(undefined4 **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 8) + 0x400) + 0x90));

    for (pcVar2 = local_280; (*pcVar2 < '0' || ('9' < *pcVar2)); pcVar2 = pcVar2 + 1) {

    }

    iVar3 = 0;

    *pcVar2 = '\0';

    if (0 < param_2) {

      do {

        crt_sprintf(local_200,s__s_02d_00559a44,local_280,iVar3);

        uVar1 = main_texture_00508750(local_200);

        *(undefined4 *)(**(int **)(*(int *)(param_1 + 4) + 0x2f4) + iVar3 * 4) = uVar1;

        iVar3 = iVar3 + 1;

      } while (iVar3 < param_2);

      return;

    }

  }

  return;

}

/* ===== fx_setupVerticleFade__FP10FXSTACKTAGfffff @ 0x00449BA0 ===== */
void fx_setupVerticleFade__FP10FXSTACKTAGfffff

               (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,

               undefined4 param_5,undefined4 param_6)



{

  int *piVar1;

  uint *puVar2;

  int iVar3;

  undefined4 *puVar4;

  int iVar5;

  char *pcVar6;

  undefined1 local_200 [512];

  

  if (param_1 == 0) {

    pcVar6 = s_Failed_to_setup_verticle_fade_fo_00559ba0;

  }

  else {

    iVar3 = *(int *)(*(int *)(param_1 + 4) + 0x100);

    if (*(int *)(iVar3 + 0xfc) == 0) {

      puVar4 = (undefined4 *)

               MemAllocMsg(0xc,0x78,s_fx_vfade_00559c1c,s_C__Giants_source_Main_fx_c_00558840,0xe2c)

      ;

      *(undefined4 **)(iVar3 + 0xfc) = puVar4;

      for (iVar5 = 0x1e; iVar5 != 0; iVar5 = iVar5 + -1) {

        *puVar4 = 0;

        puVar4 = puVar4 + 1;

      }

      puVar2 = (uint *)(*(int *)(param_1 + 4) + 0xdc);

      *puVar2 = *puVar2 | 0x40000;

      *(uint *)(*(int *)(param_1 + 4) + 0xe0) = *(uint *)(*(int *)(param_1 + 4) + 0xe0) | 0x200000;

    }

    iVar5 = *(int *)(*(int *)(iVar3 + 0xfc) + 100);

    if (iVar5 < 5) {

      *(undefined4 *)(*(int *)(iVar3 + 0xfc) + 0x14 + iVar5 * 4) = param_2;

      *(undefined4 *)(*(int *)(iVar3 + 0xfc) + 0x28 + *(int *)(*(int *)(iVar3 + 0xfc) + 100) * 4) =

           param_3;

      *(undefined4 *)(*(int *)(iVar3 + 0xfc) + 0x3c + *(int *)(*(int *)(iVar3 + 0xfc) + 100) * 4) =

           param_4;

      *(undefined4 *)(*(int *)(iVar3 + 0xfc) + 0x50 + *(int *)(*(int *)(iVar3 + 0xfc) + 100) * 4) =

           param_5;

      *(undefined4 *)(*(int *)(iVar3 + 0xfc) + *(int *)(*(int *)(iVar3 + 0xfc) + 100) * 4) = param_6

      ;

      piVar1 = (int *)(*(int *)(iVar3 + 0xfc) + 100);

      *piVar1 = *piVar1 + 1;

      return;

    }

    pcVar6 = s_Failed_to_setup_verticle_fade_fo_00559be0;

  }

  crt_sprintf(local_200,pcVar6,DAT_0059ce5c + 0x20);

  FUN_0051ea20(local_200);

  return;

}

