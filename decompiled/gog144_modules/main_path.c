/* Giants 1.449 — module main/path
 * 4 functions (4 named) — decompiled, names from PS2 symbols
 * Original source: C:\Giants\source\main/path.c(pp) (assert-string evidence)
 */

/* ===== main_path_0049fa90 @ 0x0049FA90 ===== */
void main_path_0049fa90(void)



{

  if (DAT_005a0cec != 0) {

    mem_free_tagged(DAT_005a0cec,s_C__Giants_source_main_path_c_0055e99c,0xc0);

  }

  DAT_005a0cec = 0;

  if (DAT_005a0cd8 != 0) {

    mem_free_tagged(DAT_005a0cd8,s_C__Giants_source_main_path_c_0055e99c,0xc4);

  }

  DAT_005a0cd8 = 0;

  if (DAT_005a0cd4 != 0) {

    mem_free_tagged(DAT_005a0cd4,s_C__Giants_source_main_path_c_0055e99c,200);

  }

  DAT_005a0cd4 = 0;

  return;

}

/* ===== path_world_init__Fv @ 0x0049FD40 ===== */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */



void path_world_init__Fv(void)



{

  int iVar1;

  int iVar2;

  int *piVar3;

  int iVar4;

  int iVar5;

  int *in_stack_00000004;

  undefined4 *in_stack_00000008;

  undefined4 in_stack_0000000c;

  undefined4 in_stack_00000010;

  undefined4 in_stack_00000014;

  undefined4 local_3c;

  float local_38;

  undefined4 local_34;

  undefined4 local_30;

  undefined4 local_2c;

  undefined4 local_28;

  undefined1 local_24 [4];

  undefined1 local_20 [4];

  undefined1 local_1c [4];

  undefined4 local_18;

  undefined4 local_14;

  undefined4 local_10;

  

  local_18 = *in_stack_00000004;

  local_14 = in_stack_00000004[1];

  local_10 = in_stack_00000004[2];

  terrain_grid_lookup();

  local_30 = *in_stack_00000008;

  local_2c = in_stack_00000008[1];

  local_28 = in_stack_00000008[2];

  terrain_grid_lookup(in_stack_00000008,local_24,local_20,local_1c);

  if (DAT_005a0cf8 == 0) {

    DAT_005a0cf8 = 1;

    world_reset_callback_add(&LAB_0049fd00);

    iVar5 = 0;

    DAT_005a0cf4 = 0;

    piVar3 = DAT_00632d7c;

    if (DAT_00632d7c != (int *)0x0) {

      do {

        if ((*(uint *)(piVar3[3] + 0x1c8) & 0x200000) != 0) {

          iVar5 = iVar5 + 1;

          DAT_005a0cf4 = iVar5;

        }

        piVar3 = (int *)*piVar3;

      } while (piVar3 != (int *)0x0);

      if (iVar5 != 0) {

        DAT_005a0cf0 = MemAllocMsg(0x19,iVar5 * 0x30,s_bridge_0055e994,

                                   s_C__Giants_source_main_path_c_0055e99c,0x1fe);

        in_stack_00000004 = DAT_00632d7c;

        if (DAT_00632d7c != (int *)0x0) {

          iVar5 = 0;

          do {

            iVar2 = in_stack_00000004[3];

            if ((*(uint *)(iVar2 + 0x1c8) & 0x200000) != 0) {

              iVar1 = DAT_005a0cf0 + iVar5;

              iVar4 = reaper_has_bow(iVar2);

              iVar4 = *(int *)(*(int *)(iVar2 + 8) + 0x400 + iVar4 * 4);

              local_3c = *(undefined4 *)(iVar4 + 0x44);

              local_38 = (*(float *)(iVar4 + 0x54) + *(float *)(iVar4 + 0x48)) * 0.5;

              local_34 = 0;

              xformobj_p3d_world(iVar2,&local_3c,iVar1);

              local_3c = *(undefined4 *)(iVar4 + 0x50);

              xformobj_p3d_world(iVar2,&local_3c,iVar1 + 0x18);

              terrain_grid_lookup(iVar1,iVar1 + 0xc,iVar1 + 0x10,iVar1 + 0x14);

              terrain_grid_lookup(iVar1 + 0x18,iVar1 + 0x24,iVar1 + 0x28,iVar1 + 0x2c);

              iVar5 = iVar5 + 0x30;

            }

            in_stack_00000004 = (int *)*in_stack_00000004;

          } while (in_stack_00000004 != (int *)0x0);

        }

      }

    }

  }

  DAT_005a0ce8 = 0;

  main_path_0049ff30(&local_18,&local_30,in_stack_0000000c,in_stack_00000010,in_stack_00000014);

  return;

}

/* ===== main_path_0049ff30 @ 0x0049FF30 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint main_path_0049ff30(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4,

                       undefined4 param_5,uint param_6,float param_7,float param_8,float param_9,

                       uint *param_10,undefined4 param_11,uint param_12,float param_13,

                       float param_14,float param_15,uint *param_16,undefined4 param_17,

                       uint param_18,float param_19,float param_20,float param_21,uint *param_22,

                       undefined4 param_23,uint param_24,uint param_25,uint param_26,uint param_27)



{

  float fVar1;

  uint uVar2;

  uint uVar3;

  int iVar4;

  int iVar5;

  byte bVar6;

  int iVar7;

  int iVar8;

  undefined4 *puVar9;

  int iVar10;

  int iVar11;

  float fVar12;

  uint *puVar13;

  uint uVar14;

  uint uVar15;

  int iVar16;

  float *pfVar17;

  undefined4 *puVar18;

  uint *puVar19;

  undefined4 *puVar20;

  bool bVar21;

  float10 fVar22;

  int in_stack_00001334;

  undefined4 *in_stack_00001338;

  int in_stack_0000133c;

  int *in_stack_00001340;

  undefined4 *in_stack_00001344;

  

  crt_chkstk_probe();

  iVar7 = main_path_004a0b70(in_stack_00001334,in_stack_00001338);

  if (iVar7 == 0) {

    *in_stack_00001340 = 1;

    for (iVar7 = 6; iVar7 != 0; iVar7 = iVar7 + -1) {

      *in_stack_00001344 = *in_stack_00001338;

      in_stack_00001338 = in_stack_00001338 + 1;

      in_stack_00001344 = in_stack_00001344 + 1;

    }

    return 0;

  }

  if (DAT_005a0cd8 == 0) {

    DAT_005a0cd8 = MemAllocMsg(0x19,120000,s_nodelist_0055e9d0,

                               s_C__Giants_source_main_path_c_0055e99c,0x16f);

    DAT_005a0cd4 = (undefined4 *)

                   MemAllocMsg(0x19,0x3ec,s_hashtable_0055e9c4,

                               s_C__Giants_source_main_path_c_0055e99c,0x170);

  }

  puVar9 = DAT_005a0cd4;

  for (iVar7 = 0xfb; iVar7 != 0; iVar7 = iVar7 + -1) {

    *puVar9 = 0;

    puVar9 = puVar9 + 1;

  }

  DAT_005a0cb8 = 0;

  DAT_005a0cbc = 0;

  DAT_005a0cdc = 0;

  DAT_005a0ce0 = 5000;

  DAT_005a0ce4 = MemAllocMsg(0x19,0x4e24,s_pqheap_0055e9bc,s_C__Giants_source_main_path_c_0055e99c,

                             0x49a);

  param_8 = 0.0;

  param_10 = (uint *)0x0;

  param_27 = ((*(byte *)(in_stack_00001338 + 5) & 7) << 0xc | in_stack_00001338[3] & 0xfff) << 0xc |

             in_stack_00001338[4] & 0xfff;

  uVar14 = *(uint *)(in_stack_00001334 + 0xc) & 0xfff;

  uVar15 = *(uint *)(in_stack_00001334 + 0x10) & 0xfff;

  param_6 = ((*(byte *)(in_stack_00001334 + 0x14) & 7) << 0xc | uVar14) << 0xc | uVar15;

  fVar1 = (float)(int)(uVar14 - in_stack_00001338[3]);

  fVar12 = (float)(int)(uVar15 - in_stack_00001338[4]);

  param_9 = SQRT(fVar1 * fVar1 + fVar12 * fVar12);

  param_7 = param_9;

  if (DAT_005a0cb8 < 5000) {

    puVar9 = &param_6;

    puVar18 = (undefined4 *)(DAT_005a0cd8 + DAT_005a0cb8 * 0x18);

    for (iVar7 = 6; iVar7 != 0; iVar7 = iVar7 + -1) {

      *puVar18 = *puVar9;

      puVar9 = puVar9 + 1;

      puVar18 = puVar18 + 1;

    }

    puVar19 = (uint *)(DAT_005a0cd8 + DAT_005a0cb8 * 0x18);

    uVar14 = *puVar19 % 0xfb;

    puVar19[5] = DAT_005a0cd4[uVar14];

    DAT_005a0cd4[uVar14] = DAT_005a0cd8 + DAT_005a0cb8 * 0x18;

    iVar7 = DAT_005a0cd8 + DAT_005a0cb8 * 0x18;

    if (DAT_005a0cdc < DAT_005a0ce0) {

      DAT_005a0cdc = DAT_005a0cdc + 1;

      *(int *)(DAT_005a0ce4 + DAT_005a0cdc * 4) = iVar7;

      heap_siftup__FPP5ANODEi(DAT_005a0ce4,DAT_005a0cdc);

      *(uint *)(iVar7 + 0x10) = *(uint *)(iVar7 + 0x10) | 0x80000000;

    }

    DAT_005a0cb8 = DAT_005a0cb8 + 1;

    if (DAT_005a0cbc < DAT_005a0cb8) {

      DAT_005a0cbc = DAT_005a0cb8;

    }

  }

  else {

    DAT_005a0cbc = DAT_005a0cbc + 1;

  }

  while (0 < DAT_005a0cdc) {

    puVar19 = *(uint **)(DAT_005a0ce4 + 4);

    *(undefined4 *)(DAT_005a0ce4 + 4) = *(undefined4 *)(DAT_005a0ce4 + DAT_005a0cdc * 4);

    iVar5 = DAT_005a0ce4;

    iVar8 = DAT_005a0cdc + -1;

    iVar7 = *(int *)(DAT_005a0ce4 + 4);

    iVar10 = 2;

    iVar16 = 1;

    DAT_005a0cdc = iVar8;

    if (1 < iVar8) {

      bVar21 = SBORROW4(2,iVar8);

      iVar4 = 2 - iVar8;

      do {

        iVar11 = iVar10;

        if ((bVar21 != iVar4 < 0) &&

           (*(float *)(*(int *)(iVar5 + 4 + iVar10 * 4) + 4) <

            *(float *)(*(int *)(iVar5 + iVar10 * 4) + 4))) {

          iVar11 = iVar10 + 1;

        }

        fVar12 = *(float *)(iVar7 + 4);

        iVar10 = *(int *)(iVar5 + iVar11 * 4);

        fVar1 = *(float *)(iVar10 + 4);

        if (fVar12 < fVar1 != (fVar12 == fVar1)) break;

        *(int *)(iVar5 + iVar16 * 4) = iVar10;

        iVar10 = iVar11 * 2;

        bVar21 = SBORROW4(iVar10,iVar8);

        iVar4 = iVar10 - iVar8;

        iVar16 = iVar11;

      } while (iVar10 <= iVar8);

    }

    *(int *)(iVar5 + iVar16 * 4) = iVar7;

    puVar19[4] = puVar19[4] & 0x7fffffff;

    uVar14 = *puVar19;

    if (uVar14 == param_27) goto LAB_004a06e5;

    uVar15 = uVar14 & 0xfff;

    uVar14 = uVar14 >> 0xc & 0xfff;

    bVar6 = *(byte *)((int)puVar19 + 3) & 7;

    switch(bVar6) {

    case 0:

      param_4 = 4;

      param_3 = &DAT_0055e954;

      goto switchD_004a0274_default;

    case 1:

      param_3 = &DAT_0055e964;

      break;

    case 2:

      param_3 = &DAT_0055e970;

      break;

    case 3:

      param_3 = &DAT_0055e97c;

      break;

    case 4:

      param_3 = &DAT_0055e988;

      break;

    default:

      goto switchD_004a0274_default;

    }

    param_4 = 3;

switchD_004a0274_default:

    iVar7 = 0;

    if (0 < param_4) {

      do {

        iVar10 = grid_dir_walk(uVar14,uVar15,bVar6,param_3[iVar7],&param_24,&param_25,&param_26);

        if (iVar10 == 0) {

          fVar1 = (float)(int)((*puVar19 >> 0xc & 0xfff) - param_24);

          fVar12 = (float)(int)((*puVar19 & 0xfff) - param_25);

          param_6 = ((param_26 & 7) << 0xc | param_24 & 0xfff) << 0xc | param_25 & 0xfff;

          param_8 = SQRT(fVar1 * fVar1 + fVar12 * fVar12) + (float)puVar19[2];

          for (puVar13 = (uint *)DAT_005a0cd4[param_6 % 0xfb]; puVar13 != (uint *)0x0;

              puVar13 = (uint *)puVar13[5]) {

            if (*puVar13 == param_6) {

              if ((float)puVar13[2] < param_8 != ((float)puVar13[2] == param_8)) goto LAB_004a0425;

              if (-1 < (int)puVar13[4]) goto LAB_004a0391;

              bVar21 = true;

              goto LAB_004a0393;

            }

          }

          puVar13 = (uint *)0x0;

LAB_004a0391:

          bVar21 = false;

LAB_004a0393:

          fVar1 = (float)(int)((param_24 & 0xfff) - in_stack_00001338[3]);

          fVar12 = (float)(int)((param_25 & 0xfff) - in_stack_00001338[4]);

          param_9 = SQRT(fVar1 * fVar1 + fVar12 * fVar12);

          param_7 = param_9 + param_8;

          param_10 = puVar19;

          if (puVar13 == (uint *)0x0) {

            main_path_004a0a00(&param_6);

          }

          else if (bVar21) {

            ObjectTransformIntegrity_2(puVar13,&param_6);

          }

          else {

            path_node_push(puVar13);

          }

        }

LAB_004a0425:

        iVar7 = iVar7 + 1;

      } while (iVar7 < param_4);

    }

    if ((DAT_005a0ce8 == 0) && (param_2 = 0, 0 < DAT_005a0cf4)) {

      iVar10 = 0;

      iVar7 = DAT_005a0cf0;

      do {

        uVar2 = *(uint *)(iVar10 + 0xc + iVar7);

        if ((uVar2 == uVar14) && (*(uint *)(iVar10 + 0x10 + iVar7) == uVar15)) {

          uVar2 = *(uint *)(iVar10 + 0x24 + iVar7);

          uVar3 = *(uint *)(iVar10 + 0x28 + iVar7);

          fVar1 = (float)(int)((*puVar19 >> 0xc & 0xfff) - uVar2);

          fVar12 = (float)(int)((*puVar19 & 0xfff) - uVar3);

          param_12 = uVar3 & 0xfff |

                     ((*(byte *)(iVar10 + 0x2c + iVar7) & 7) << 0xc | uVar2 & 0xfff) << 0xc;

          param_14 = SQRT(fVar1 * fVar1 + fVar12 * fVar12) + (float)puVar19[2];

          for (puVar13 = (uint *)DAT_005a0cd4[param_12 % 0xfb]; puVar13 != (uint *)0x0;

              puVar13 = (uint *)puVar13[5]) {

            if (*puVar13 == param_12) {

              if ((float)puVar13[2] < param_14 != ((float)puVar13[2] == param_14))

              goto LAB_004a06ae;

              if (-1 < (int)puVar13[4]) goto LAB_004a0531;

              bVar21 = true;

              goto LAB_004a0533;

            }

          }

          puVar13 = (uint *)0x0;

LAB_004a0531:

          bVar21 = false;

LAB_004a0533:

          param_16 = puVar19;

          fVar22 = (float10)main_path_004a0b20(&param_12,in_stack_00001338);

          param_15 = (float)fVar22;

          param_13 = (float)(fVar22 + (float10)param_14);

          if (puVar13 == (uint *)0x0) {

            puVar9 = &param_12;

LAB_004a069f:

            main_path_004a0a00(puVar9);

            iVar7 = DAT_005a0cf0;

          }

          else if (bVar21) {

            puVar13[1] = (uint)(float)(fVar22 + (float10)param_14);

            puVar13[2] = (uint)param_14;

            puVar13[3] = (uint)(float)fVar22;

            iVar7 = DAT_005a0cf0;

          }

          else {

LAB_004a0693:

            path_node_push(puVar13);

            iVar7 = DAT_005a0cf0;

          }

        }

        else if ((*(uint *)(iVar10 + 0x24 + iVar7) == uVar14) &&

                (*(uint *)(iVar10 + 0x28 + iVar7) == uVar15)) {

          uVar3 = *(uint *)(iVar10 + 0x10 + iVar7);

          fVar1 = (float)(int)((*puVar19 >> 0xc & 0xfff) - uVar2);

          fVar12 = (float)(int)((*puVar19 & 0xfff) - uVar3);

          param_18 = ((*(byte *)(iVar10 + 0x14 + iVar7) & 7) << 0xc | uVar2 & 0xfff) << 0xc |

                     uVar3 & 0xfff;

          param_20 = SQRT(fVar1 * fVar1 + fVar12 * fVar12) + (float)puVar19[2];

          for (puVar13 = (uint *)DAT_005a0cd4[param_18 % 0xfb]; puVar13 != (uint *)0x0;

              puVar13 = (uint *)puVar13[5]) {

            if (*puVar13 == param_18) {

              if ((float)puVar13[2] < param_20 != ((float)puVar13[2] == param_20))

              goto LAB_004a06ae;

              if (-1 < (int)puVar13[4]) goto LAB_004a064d;

              bVar21 = true;

              goto LAB_004a064f;

            }

          }

          puVar13 = (uint *)0x0;

LAB_004a064d:

          bVar21 = false;

LAB_004a064f:

          param_22 = puVar19;

          fVar22 = (float10)main_path_004a0b20(&param_18,in_stack_00001338);

          param_21 = (float)fVar22;

          param_19 = (float)(fVar22 + (float10)param_20);

          if (puVar13 == (uint *)0x0) {

            puVar9 = &param_18;

            goto LAB_004a069f;

          }

          if (!bVar21) goto LAB_004a0693;

          puVar13[1] = (uint)(float)(fVar22 + (float10)param_20);

          puVar13[2] = (uint)param_20;

          puVar13[3] = (uint)(float)fVar22;

          iVar7 = DAT_005a0cf0;

        }

LAB_004a06ae:

        param_2 = param_2 + 1;

        iVar10 = iVar10 + 0x30;

      } while (param_2 < DAT_005a0cf4);

    }

  }

  puVar19 = (uint *)0x0;

LAB_004a06e5:

  iVar7 = 0;

  bVar6 = 0;

  if (puVar19 != (uint *)0x0) {

LAB_004a079b:

    iVar7 = 1;

    for (uVar14 = puVar19[4]; (uVar14 & 0x7fffffff) != 0;

        uVar14 = *(uint *)((uVar14 & 0x7fffffff) + 0x10)) {

      iVar7 = iVar7 + 1;

    }

    iVar10 = iVar7 + -1;

    pfVar17 = (float *)(&stack0x00000078 + iVar10 * 0x18);

    do {

      if (iVar10 < 200) {

        pfVar17[1] = (float)(*puVar19 >> 0xc & 0xfff);

        fVar12 = (float)(*puVar19 & 0xfff);

        pfVar17[2] = fVar12;

        *(byte *)(pfVar17 + 3) = *(byte *)((int)puVar19 + 3) & 7;

        if (DAT_005a0ce8 == 0) {

          pfVar17[-2] = ((float)(int)pfVar17[1] + 0.5) * *(float *)(DAT_006330e4 + 0x1c0) +

                        *(float *)(DAT_006330e4 + 0x1c8);

          fVar12 = ((float)(int)fVar12 + 0.5) * *(float *)(DAT_006330e4 + 0x1c0) +

                   *(float *)(DAT_006330e4 + 0x1cc);

        }

        else {

          pfVar17[-2] = (float)(int)pfVar17[1] * _DAT_0059f9e8 + _DAT_0059f9f0;

          fVar12 = (float)(int)fVar12 * _DAT_0059f9e8 + _DAT_0059f9ec;

        }

        pfVar17[-1] = fVar12;

        fVar22 = (float10)get_floor_z_point(pfVar17 + -2);

        *pfVar17 = (float)fVar22;

      }

      puVar19 = (uint *)(puVar19[4] & 0x7fffffff);

      iVar10 = iVar10 + -1;

      pfVar17 = pfVar17 + -6;

    } while (puVar19 != (uint *)0x0);

    if (200 < iVar7) {

      iVar7 = 200;

    }

    mem_free_tagged(DAT_005a0ce4,s_C__Giants_source_main_path_c_0055e99c,0x49f);

    DAT_005a0ce4 = 0;

    do {

      bVar21 = false;

      if (iVar7 < 3) break;

      param_1 = 2;

      puVar9 = (undefined4 *)&stack0x000000a0;

      do {

        iVar10 = main_path_004a0b70(puVar9 + -0xc,puVar9);

        if (iVar10 == 0) {

          puVar18 = puVar9;

          puVar20 = puVar9 + -6;

          for (iVar10 = ((iVar7 - param_1) * 3 & 0x1fffffffU) << 1; iVar10 != 0;

              iVar10 = iVar10 + -1) {

            *puVar20 = *puVar18;

            puVar18 = puVar18 + 1;

            puVar20 = puVar20 + 1;

          }

          for (iVar10 = 0; iVar10 != 0; iVar10 = iVar10 + -1) {

            *(undefined1 *)puVar20 = *(undefined1 *)puVar18;

            puVar18 = (undefined4 *)((int)puVar18 + 1);

            puVar20 = (undefined4 *)((int)puVar20 + 1);

          }

          iVar7 = iVar7 + -1;

          bVar21 = true;

        }

        puVar9 = puVar9 + 6;

        param_1 = param_1 + 1;

      } while (param_1 < iVar7);

    } while (bVar21);

    iVar7 = iVar7 + -1;

    if (0 < iVar7) {

      if (in_stack_0000133c < iVar7) {

        iVar7 = in_stack_0000133c;

      }

      puVar9 = (undefined4 *)&stack0x00000088;

      puVar18 = in_stack_00001344;

      for (iVar10 = (iVar7 * 3 & 0x1fffffffU) << 1; iVar10 != 0; iVar10 = iVar10 + -1) {

        *puVar18 = *puVar9;

        puVar9 = puVar9 + 1;

        puVar18 = puVar18 + 1;

      }

      for (iVar10 = 0; iVar10 != 0; iVar10 = iVar10 + -1) {

        *(undefined1 *)puVar18 = *(undefined1 *)puVar9;

        puVar9 = (undefined4 *)((int)puVar9 + 1);

        puVar18 = (undefined4 *)((int)puVar18 + 1);

      }

      *in_stack_00001340 = iVar7;

      if ((in_stack_00001338[3] == in_stack_00001344[iVar7 * 6 + -3]) &&

         (in_stack_00001338[4] == in_stack_00001344[iVar7 * 6 + -2])) {

        puVar9 = in_stack_00001344 + iVar7 * 6 + -6;

        *puVar9 = *in_stack_00001338;

        puVar9[1] = in_stack_00001338[1];

        puVar9[2] = in_stack_00001338[2];

      }

      return (uint)bVar6;

    }

    *in_stack_00001340 = 0;

    return 0xffffffff;

  }

  fVar12 = 999999.0;

  iVar10 = -1;

  bVar6 = 1;

  if (0 < DAT_005a0cb8) {

    pfVar17 = (float *)(DAT_005a0cd8 + 0xc);

    do {

      if ((-1 < (int)pfVar17[1]) && (*pfVar17 < fVar12)) {

        fVar12 = *pfVar17;

        iVar10 = iVar7;

      }

      iVar7 = iVar7 + 1;

      pfVar17 = pfVar17 + 6;

    } while (iVar7 < DAT_005a0cb8);

    if ((iVar10 != -1) && (puVar19 = (uint *)(DAT_005a0cd8 + iVar10 * 0x18), puVar19 != (uint *)0x0)

       ) {

      if ((DAT_005a0ce8 != 0) &&

         (((((int)in_stack_00001338[3] < 0 || ((int)in_stack_00001338[4] < 0)) ||

           (0x3f < (int)in_stack_00001338[3])) || (0x3f < (int)in_stack_00001338[4])))) {

        uVar14 = *puVar19 >> 0xc & 0xfff;

        if ((((uVar14 == 0) || (uVar15 = *puVar19 & 0xfff, uVar15 == 0)) || (uVar14 == 0x3f)) ||

           (uVar15 == 0x3f)) {

          bVar6 = 0;

        }

      }

      goto LAB_004a079b;

    }

  }

  *in_stack_00001340 = 0;

  return 0xffffffff;

}

/* ===== main_path_004a0f40 @ 0x004A0F40 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void main_path_004a0f40(int param_1,undefined4 param_2,float *param_3,float *param_4)



{

  float fVar1;

  float fVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  uint uVar7;

  undefined4 *puVar8;

  

  if (320.0 <= ABS(*param_3 - *param_4)) {

    if (*param_4 <= *param_3) {

      fVar1 = (*param_3 + 48.0) - 320.0;

    }

    else {

      fVar1 = *param_3 - 48.0;

    }

  }

  else {

    fVar1 = (*param_3 + *param_4) * 0.5 - 160.0;

  }

  if (320.0 <= ABS(param_3[1] - param_4[1])) {

    if (param_4[1] <= param_3[1]) {

      fVar2 = (param_3[1] + 48.0) - 320.0;

    }

    else {

      fVar2 = param_3[1] - 48.0;

    }

  }

  else {

    fVar2 = (param_4[1] + param_3[1]) * 0.5 - 160.0;

  }

  if (DAT_005a0cec == (undefined4 *)0x0) {

    DAT_005a0cec = (undefined4 *)

                   MemAllocMsg(0x19,0x1000,s_Table_0055e9dc,s_C__Giants_source_main_path_c_0055e99c,

                               0x433);

  }

  puVar8 = DAT_005a0cec;

  for (iVar6 = 0x400; iVar6 != 0; iVar6 = iVar6 + -1) {

    *puVar8 = 0;

    puVar8 = puVar8 + 1;

  }

  _DAT_0059f9ec = fVar2;

  _DAT_0059f9f0 = fVar1;

  crt_dbl_round((double)(fVar1 * 0.2 + 0.5));

  DAT_005a0cc8 = __ftol();

  crt_dbl_round((double)(_DAT_0059f9ec * 0.2 + 0.5));

  DAT_005a0cc4 = __ftol();

  _DAT_0059f9e8 = 0x40a00000;

  for (puVar8 = DAT_00632d7c; puVar8 != (undefined4 *)0x0; puVar8 = (undefined4 *)*puVar8) {

    iVar6 = puVar8[3];

    uVar7 = *(uint *)(iVar6 + 0x1c8) & 0x800;

    if (((((*(uint *)(iVar6 + 0xd8) & 0x4000c000) == 0 && uVar7 == 0) && (uVar7 == 0)) &&

        (iVar6 != param_1)) && (*(int *)(iVar6 + 0x210) != param_1)) {

      collgrid_collide_walk(iVar6,DAT_005a0cc8,DAT_005a0cc4,0x40,DAT_005a0cec);

    }

  }

  crt_dbl_round((double)((*param_3 - fVar1) * 0.2 + 0.5));

  iVar6 = __ftol();

  crt_dbl_round((double)((param_3[1] - fVar2) * 0.2 + 0.5));

  iVar3 = __ftol();

  crt_dbl_round((double)((*param_4 - fVar1) * 0.2 + 0.5));

  iVar4 = __ftol();

  crt_dbl_round((double)((param_4[1] - fVar2) * 0.2 + 0.5));

  iVar5 = __ftol();

  if (((-1 < iVar6) && (-1 < iVar3)) && ((iVar6 < 0x40 && (iVar3 < 0x40)))) {

    *(undefined1 *)((int)DAT_005a0cec + iVar6 + iVar3 * 0x40) = 0;

  }

  if (((-1 < iVar4) && (-1 < iVar5)) && ((iVar4 < 0x40 && (iVar5 < 0x40)))) {

    *(undefined1 *)((int)DAT_005a0cec + iVar4 + iVar5 * 0x40) = 0;

  }

  DAT_005a0ce8 = 1;

  main_path_0049ff30();

  return;

}

