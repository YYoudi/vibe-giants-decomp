/* Giants 1.449 — module main/makeobj
 * 3 functions (1 named) — decompiled, names from PS2 symbols
 * Original source: C:\Giants\source\main/makeobj.c(pp) (assert-string evidence)
 */

/* ===== FUN_00471e10 @ 0x00471E10 ===== */
undefined4 * FUN_00471e10(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)



{

  uint uVar1;

  uint uVar2;

  int *piVar3;

  int iVar4;

  undefined4 uVar5;

  undefined4 *puVar6;

  uint uVar7;

  int iVar8;

  uint uVar9;

  undefined4 *puVar10;

  uint *puVar11;

  int iVar12;

  uint *puVar13;

  uint *puVar14;

  undefined4 *puVar15;

  int *local_40;

  uint *local_3c;

  uint local_38;

  uint local_34;

  int local_30;

  int local_2c;

  int local_28;

  undefined4 *local_24;

  undefined4 local_20;

  undefined4 local_1c;

  undefined4 local_18;

  undefined4 local_14;

  uint local_10;

  uint local_c;

  uint local_8;

  uint local_4;

  

  vfs_fileread_load(param_1,&local_40,&local_2c);

  piVar3 = local_40;

  if (local_2c != 0) {

    local_30 = *local_40;

    if ((local_30 != -0x55feff55) && (local_30 != -0x55feff56)) {

      FUN_0051e680(s_Bad_version_of_GB2_file_0055b7c4);

      FUN_0051eaa0();

      return (undefined4 *)0x0;

    }

    iVar8 = local_40[1];

    iVar12 = 0;

    if (0 < iVar8) {

      do {

        puVar10 = (undefined4 *)(piVar3[iVar12 + 2] + (int)local_40);

        local_20 = *puVar10;

        local_1c = puVar10[1];

        local_18 = puVar10[2];

        local_14 = puVar10[3];

        iVar4 = FUN_0053a860(&local_20,param_2);

        if (iVar4 != 0) {

          local_24 = (undefined4 *)puVar10[4];

          local_28 = puVar10[5];

          puVar11 = puVar10 + 6;

          local_34 = (uint)local_24 & 4;

          if (local_34 == 0) {

            param_2 = (undefined4 *)0x0;

          }

          else {

            param_2 = (undefined4 *)*puVar11;

            puVar11 = puVar10 + 7;

          }

          if (local_30 == -0x55feff56) {

            local_3c = (uint *)0x101;

          }

          else {

            local_3c = (uint *)*puVar11;

            puVar11 = puVar11 + 1;

          }

          local_38 = (uint)local_24 & 2;

          if (local_38 != 0) {

            local_10 = *puVar11;

            local_c = puVar11[1];

            local_8 = puVar11[2];

            local_4 = puVar11[3];

            puVar11 = puVar11 + 4;

          }

          uVar1 = *puVar11;

          uVar2 = puVar11[1];

          if (param_3 != (undefined4 *)0x0) {

            if (local_38 != 0) {

              uVar5 = FUN_00508750(&local_10);

              *param_3 = uVar5;

            }

            param_3[1] = local_28;

            param_3[2] = param_2;

            param_3[3] = local_3c;

          }

          local_28 = uVar1 * 0xc;

          local_3c = (uint *)FUN_0053a700(0x11,local_28,s_objp3d_0055b780,

                                          s_C__Giants_source_main_makeobj_c_0055b788,0x57);

          local_30 = FUN_0053a700(0x11,uVar2 * 6,s_objtri_0055b778,

                                  s_C__Giants_source_main_makeobj_c_0055b788,0x58);

          if (local_38 == 0) {

            param_2 = (undefined4 *)0x0;

          }

          else {

            param_2 = (undefined4 *)

                      FUN_0053a700(0x11,uVar1 * 8,s_objuv_0055b770,

                                   s_C__Giants_source_main_makeobj_c_0055b788,0x5a);

          }

          if (local_34 == 0) {

            param_3 = (undefined4 *)0x0;

          }

          else {

            param_3 = (undefined4 *)

                      FUN_0053a700(0x11,uVar1 * 3 + 1,s_objrgb_0055b768,

                                   s_C__Giants_source_main_makeobj_c_0055b788,0x60);

          }

          puVar13 = puVar11 + 2;

          puVar14 = local_3c;

          for (uVar7 = uVar1 * 3 & 0x3fffffff; uVar7 != 0; uVar7 = uVar7 - 1) {

            *puVar14 = *puVar13;

            puVar13 = puVar13 + 1;

            puVar14 = puVar14 + 1;

          }

          for (iVar8 = 0; iVar8 != 0; iVar8 = iVar8 + -1) {

            *(char *)puVar14 = (char)*puVar13;

            puVar13 = (uint *)((int)puVar13 + 1);

            puVar14 = (uint *)((int)puVar14 + 1);

          }

          puVar10 = (undefined4 *)((int)(puVar11 + 2) + local_28);

          if (((uint)local_24 & 1) != 0) {

            puVar10 = (undefined4 *)((int)puVar10 + local_28);

          }

          if (local_38 != 0) {

            puVar6 = puVar10;

            puVar15 = param_2;

            for (iVar8 = (uVar1 & 0x1fffffff) << 1; iVar8 != 0; iVar8 = iVar8 + -1) {

              *puVar15 = *puVar6;

              puVar6 = puVar6 + 1;

              puVar15 = puVar15 + 1;

            }

            for (iVar8 = 0; iVar8 != 0; iVar8 = iVar8 + -1) {

              *(undefined1 *)puVar15 = *(undefined1 *)puVar6;

              puVar6 = (undefined4 *)((int)puVar6 + 1);

              puVar15 = (undefined4 *)((int)puVar15 + 1);

            }

            puVar10 = puVar10 + uVar1 * 2;

          }

          if (local_34 != 0) {

            uVar7 = uVar1 * 3;

            puVar6 = puVar10;

            puVar15 = param_3;

            for (uVar9 = uVar7 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {

              *puVar15 = *puVar6;

              puVar6 = puVar6 + 1;

              puVar15 = puVar15 + 1;

            }

            for (uVar9 = uVar7 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {

              *(undefined1 *)puVar15 = *(undefined1 *)puVar6;

              puVar6 = (undefined4 *)((int)puVar6 + 1);

              puVar15 = (undefined4 *)((int)puVar15 + 1);

            }

            puVar10 = (undefined4 *)((int)puVar10 + uVar7);

          }

          puVar6 = (undefined4 *)

                   FUN_0053a700(0x11,uVar2 * 0xc,s_objtri_temp_0055b75c,

                                s_C__Giants_source_main_makeobj_c_0055b788,0x75);

          puVar15 = puVar6;

          for (uVar7 = uVar2 * 3 & 0x3fffffff; uVar7 != 0; uVar7 = uVar7 - 1) {

            *puVar15 = *puVar10;

            puVar10 = puVar10 + 1;

            puVar15 = puVar15 + 1;

          }

          for (iVar8 = 0; iVar8 != 0; iVar8 = iVar8 + -1) {

            *(undefined1 *)puVar15 = *(undefined1 *)puVar10;

            puVar10 = (undefined4 *)((int)puVar10 + 1);

            puVar15 = (undefined4 *)((int)puVar15 + 1);

          }

          iVar8 = 0;

          local_24 = puVar6;

          if (0 < (int)(uVar2 * 3)) {

            do {

              if ((uint)puVar6[iVar8] < 0x10000) {

                *(short *)(local_30 + iVar8 * 2) = (short)puVar6[iVar8];

              }

              else {

                FUN_0051ea20(s_index_too_big_in_single_object_d_0055b738);

                FUN_0051eaa0();

                puVar6 = local_24;

              }

              iVar8 = iVar8 + 1;

            } while (iVar8 < (int)(uVar2 * 3));

          }

          mem_free_tagged(puVar6,s_C__Giants_source_main_makeobj_c_0055b788,0x85);

          puVar6 = (undefined4 *)

                   FUN_0053a700(0x11,0x1c,&DAT_0055b734,s_C__Giants_source_main_makeobj_c_0055b788,

                                0x89);

          puVar10 = puVar6;

          for (iVar8 = 7; iVar8 != 0; iVar8 = iVar8 + -1) {

            *puVar10 = 0;

            puVar10 = puVar10 + 1;

          }

          puVar6[1] = uVar1;

          puVar6[3] = local_3c;

          puVar6[2] = uVar2;

          puVar6[4] = param_2;

          puVar6[5] = param_3;

          puVar6[6] = local_30;

          FUN_00538560(local_40);

          return puVar6;

        }

        iVar12 = iVar12 + 1;

      } while (iVar12 < iVar8);

    }

    FUN_00542f27(&DAT_00657400,s_Missing_object__s_in_GB2_0055b7a8,param_2);

    FUN_0051ea20(&DAT_00657400);

    FUN_0051eaa0();

  }

  return (undefined4 *)0x0;

}

/* ===== object_clone_objectset @ 0x004721D0 ===== */
undefined4 * object_clone_objectset(undefined4 param_1)



{

  uint uVar1;

  float fVar2;

  uint uVar3;

  uint *puVar4;

  uint *puVar5;

  undefined4 *puVar6;

  undefined4 *puVar7;

  uint *puVar8;

  undefined4 uVar9;

  uint uVar10;

  int iVar11;

  uint uVar12;

  uint uVar13;

  int iVar14;

  float *pfVar15;

  int iVar16;

  undefined1 *puVar17;

  uint *puVar18;

  int *piVar19;

  undefined4 *puVar20;

  int *piVar21;

  int *piVar22;

  uint *puVar23;

  char *pcVar24;

  uint local_d0;

  uint local_c4;

  uint local_bc;

  int *local_b8;

  int *local_b4;

  int *local_a4;

  int local_a0;

  uint local_9c;

  undefined4 uStack_98;

  int *local_94;

  undefined4 uStack_90;

  int *local_8c;

  undefined4 uStack_88;

  uint local_84;

  uint local_80;

  int local_7c;

  int local_78;

  uint local_74 [4];

  undefined4 local_64;

  char local_60 [32];

  char local_40 [32];

  uint local_20 [8];

  

  vfs_fileread_load(param_1,&local_a4,&local_7c);

  if (local_7c == 0) {

    return (undefined4 *)0x0;

  }

  if (*local_a4 != -0x55feff42) {

    FUN_0051ea20(s_Old_gbs_binary_detected_0055b848);

    return (undefined4 *)0x0;

  }

  uVar1 = local_a4[1];

  uVar3 = local_a4[2];

  piVar22 = local_a4 + 3;

  local_9c = uVar3;

  local_8c = (int *)FUN_0053a700(0x11,uVar3 * 0xc,s_averts_0055b840,

                                 s_C__Giants_source_main_makeobj_c_0055b788,0xf6);

  DAT_0059dbdc = DAT_0059dbdc + uVar3 * 0xc;

  piVar19 = piVar22;

  piVar21 = local_8c;

  for (uVar10 = uVar3 * 3 & 0x3fffffff; uVar10 != 0; uVar10 = uVar10 - 1) {

    *piVar21 = *piVar19;

    piVar19 = piVar19 + 1;

    piVar21 = piVar21 + 1;

  }

  puVar18 = (uint *)(piVar22 + uVar3 * 3);

  uVar3 = uVar1 & 1;

  for (iVar11 = 0; iVar11 != 0; iVar11 = iVar11 + -1) {

    *(char *)piVar21 = (char)*piVar19;

    piVar19 = (int *)((int)piVar19 + 1);

    piVar21 = (int *)((int)piVar21 + 1);

  }

  if (uVar3 == 0) {

LAB_004722ee:

    puVar4 = (uint *)0x0;

    local_c4 = 0;

    local_d0 = 0;

  }

  else {

    if (((byte)DAT_00632e94 & 1) == 0) {

      puVar18 = (uint *)((int)puVar18 + puVar18[1] * 2 + 8);

      goto LAB_004722ee;

    }

    local_d0 = *puVar18;

    local_c4 = puVar18[1];

    uVar10 = local_c4 * 2;

    puVar4 = (uint *)FUN_0053a700(0x11,uVar10,s_normal_defs_0055b834,

                                  s_C__Giants_source_main_makeobj_c_0055b788,0x104);

    DAT_0059dbdc = DAT_0059dbdc + uVar10;

    puVar8 = puVar18 + 2;

    puVar23 = puVar4;

    for (uVar12 = (local_c4 & 0x7fffffff) >> 1; uVar12 != 0; uVar12 = uVar12 - 1) {

      *puVar23 = *puVar8;

      puVar8 = puVar8 + 1;

      puVar23 = puVar23 + 1;

    }

    for (uVar12 = uVar10 & 3; uVar12 != 0; uVar12 = uVar12 - 1) {

      *(char *)puVar23 = (char)*puVar8;

      puVar8 = (uint *)((int)puVar8 + 1);

      puVar23 = (uint *)((int)puVar23 + 1);

    }

    puVar18 = (uint *)((int)(puVar18 + 2) + uVar10);

  }

  uVar10 = *puVar18;

  uVar12 = uVar10 * 2;

  puVar5 = (uint *)FUN_0053a700(0x11,uVar12,s_iverts_0055b82c,

                                s_C__Giants_source_main_makeobj_c_0055b788,0x123);

  DAT_0059dbdc = DAT_0059dbdc + uVar12;

  puVar8 = puVar18 + 1;

  puVar23 = puVar5;

  for (uVar13 = (uVar10 & 0x7fffffff) >> 1; uVar13 != 0; uVar13 = uVar13 - 1) {

    *puVar23 = *puVar8;

    puVar8 = puVar8 + 1;

    puVar23 = puVar23 + 1;

  }

  piVar19 = (int *)((int)(puVar18 + 1) + uVar12);

  for (uVar13 = uVar12 & 3; uVar13 != 0; uVar13 = uVar13 - 1) {

    *(char *)puVar23 = (char)*puVar8;

    puVar8 = (uint *)((int)puVar8 + 1);

    puVar23 = (uint *)((int)puVar23 + 1);

  }

  if (uVar3 != 0) {

    if (((byte)DAT_00632e94 & 1) != 0) {

      local_b8 = (int *)FUN_0053a700(0x11,uVar12,s_inorms_0055b824,

                                     s_C__Giants_source_main_makeobj_c_0055b788,300);

      DAT_0059dbdc = DAT_0059dbdc + uVar12;

      piVar21 = piVar19;

      piVar22 = local_b8;

      for (uVar13 = (uVar10 & 0x7fffffff) >> 1; uVar13 != 0; uVar13 = uVar13 - 1) {

        *piVar22 = *piVar21;

        piVar21 = piVar21 + 1;

        piVar22 = piVar22 + 1;

      }

      for (uVar13 = uVar12 & 3; uVar13 != 0; uVar13 = uVar13 - 1) {

        *(char *)piVar22 = (char)*piVar21;

        piVar21 = (int *)((int)piVar21 + 1);

        piVar22 = (int *)((int)piVar22 + 1);

      }

      piVar19 = (int *)((int)piVar19 + uVar12);

      goto LAB_004723a2;

    }

    piVar19 = (int *)((int)piVar19 + uVar12);

  }

  local_b8 = (int *)0x0;

LAB_004723a2:

  local_84 = uVar1 & 2;

  if (local_84 == 0) {

    local_94 = (int *)0x0;

  }

  else {

    local_94 = (int *)FUN_0053a700(0x11,uVar10 * 8,s_vertuv_0055b81c,

                                   s_C__Giants_source_main_makeobj_c_0055b788,0x13e);

    DAT_0059dbdc = DAT_0059dbdc + uVar10 * 8;

    piVar21 = piVar19;

    piVar22 = local_94;

    for (iVar11 = (uVar10 & 0x1fffffff) << 1; iVar11 != 0; iVar11 = iVar11 + -1) {

      *piVar22 = *piVar21;

      piVar21 = piVar21 + 1;

      piVar22 = piVar22 + 1;

    }

    for (iVar11 = 0; iVar11 != 0; iVar11 = iVar11 + -1) {

      *(char *)piVar22 = (char)*piVar21;

      piVar21 = (int *)((int)piVar21 + 1);

      piVar22 = (int *)((int)piVar22 + 1);

    }

    piVar19 = piVar19 + uVar10 * 2;

  }

  local_80 = uVar1 & 4;

  if (local_80 == 0) {

    local_b4 = (int *)0x0;

  }

  else {

    uVar1 = uVar10 * 3;

    local_b4 = (int *)FUN_0053a700(0x11,uVar1 + 1,s_vertrgb_0055b814,

                                   s_C__Giants_source_main_makeobj_c_0055b788,0x149);

    DAT_0059dbdc = DAT_0059dbdc + 1 + uVar1;

    piVar21 = piVar19;

    piVar22 = local_b4;

    for (uVar12 = uVar1 >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {

      *piVar22 = *piVar21;

      piVar21 = piVar21 + 1;

      piVar22 = piVar22 + 1;

    }

    for (uVar12 = uVar1 & 3; uVar12 != 0; uVar12 = uVar12 - 1) {

      *(char *)piVar22 = (char)*piVar21;

      piVar21 = (int *)((int)piVar21 + 1);

      piVar22 = (int *)((int)piVar22 + 1);

    }

    piVar19 = (int *)((int)piVar19 + uVar1);

  }

  iVar11 = *piVar19;

  puVar18 = (uint *)(piVar19 + 1);

  local_78 = iVar11;

  local_a0 = FUN_0053a700(0x11,iVar11 * 0x24,s_Max_Objs_0055b808,

                          s_C__Giants_source_main_makeobj_c_0055b788,0x153);

  DAT_0059dbdc = DAT_0059dbdc + iVar11 * 0x24;

  if (iVar11 != 0) {

    puVar6 = (undefined4 *)(local_a0 + 8);

    iVar16 = iVar11;

    do {

      puVar8 = puVar18;

      puVar23 = local_74;

      for (iVar14 = 5; iVar14 != 0; iVar14 = iVar14 + -1) {

        *puVar23 = *puVar8;

        puVar8 = puVar8 + 1;

        puVar23 = puVar23 + 1;

      }

      puVar6[-2] = local_74[0];

      puVar6[-1] = local_74[1];

      *puVar6 = local_74[2];

      puVar6[1] = local_74[3];

      puVar6[2] = local_64;

      puVar6[4] = 0;

      puVar6[3] = 0;

      puVar6[6] = 0;

      puVar6[5] = 0;

      puVar18 = puVar18 + 5;

      puVar6 = puVar6 + 9;

      iVar16 = iVar16 + -1;

    } while (iVar16 != 0);

  }

  uVar1 = *puVar18;

  uVar12 = uVar1 * 0x50 + 0x74;

  puVar7 = (undefined4 *)

           FUN_0053a700(0x11,uVar12,&DAT_0055b804,s_C__Giants_source_main_makeobj_c_0055b788,0x176);

  DAT_0059dbdc = DAT_0059dbdc + uVar12;

  puVar6 = puVar7;

  for (uVar12 = uVar12 >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {

    *puVar6 = 0;

    puVar6 = puVar6 + 1;

  }

  for (iVar16 = 0; iVar16 != 0; iVar16 = iVar16 + -1) {

    *(undefined1 *)puVar6 = 0;

    puVar6 = (undefined4 *)((int)puVar6 + 1);

  }

  puVar7[6] = local_c4;

  puVar7[7] = local_d0;

  puVar7[8] = puVar4;

  puVar7[0xc] = uVar10;

  puVar7[0xd] = puVar5;

  puVar7[0xe] = local_b8;

  puVar7[0xf] = local_94;

  puVar7[3] = local_a0;

  puVar7[2] = iVar11;

  puVar7[0x10] = local_b4;

  puVar7[4] = local_9c;

  puVar7[5] = local_8c;

  puVar7[0x1a] = uVar1;

  local_b4 = (int *)0x0;

  if (0 < (int)local_9c) {

    pfVar15 = (float *)(local_8c + 2);

    do {

      if (local_b4 == (int *)0x0) {

        puVar7[0x14] = pfVar15[-2];

        puVar7[0x15] = pfVar15[-1];

        puVar7[0x16] = *pfVar15;

        puVar7[0x11] = pfVar15[-2];

        puVar7[0x12] = pfVar15[-1];

        puVar7[0x13] = *pfVar15;

      }

      if (pfVar15[-2] < (float)puVar7[0x11]) {

        puVar7[0x11] = pfVar15[-2];

      }

      if (pfVar15[-1] < (float)puVar7[0x12]) {

        puVar7[0x12] = pfVar15[-1];

      }

      if (*pfVar15 < (float)puVar7[0x13]) {

        puVar7[0x13] = *pfVar15;

      }

      if ((float)puVar7[0x14] < pfVar15[-2]) {

        puVar7[0x14] = pfVar15[-2];

      }

      if ((float)puVar7[0x15] < pfVar15[-1]) {

        puVar7[0x15] = pfVar15[-1];

      }

      if ((float)puVar7[0x16] < *pfVar15) {

        puVar7[0x16] = *pfVar15;

      }

      local_b4 = (int *)((int)local_b4 + 1);

      pfVar15 = pfVar15 + 3;

    } while ((int)local_b4 < (int)local_9c);

  }

  local_c4 = 0;

  local_bc = 0;

  local_b8 = (int *)0x0;

  if (0 < (int)uVar1) {

    puVar17 = (undefined1 *)((int)puVar7 + 0xa6);

    do {

      puVar8 = local_20;

      puVar4 = puVar18;

      for (iVar11 = 8; puVar4 = puVar4 + 1, iVar11 != 0; iVar11 = iVar11 + -1) {

        *puVar8 = *puVar4;

        puVar8 = puVar8 + 1;

      }

      MemString(0x11,local_20,puVar17 + -0x32,s_C__Giants_source_main_makeobj_c_0055b788,0x1a9);

      *(uint *)(puVar17 + -0x2e) = puVar18[9];

      *(uint *)(puVar17 + -0x26) = puVar18[10];

      uVar10 = puVar18[0xb];

      puVar8 = (uint *)FUN_0053a700(0x11,uVar10 * 2 + 2,&DAT_0055b7fc,

                                    s_C__Giants_source_main_makeobj_c_0055b788,0x1b6);

      uVar12 = uVar10 * 2;

      *(uint **)(puVar17 + -0x22) = puVar8;

      puVar4 = puVar18 + 0xc;

      for (uVar10 = (uVar10 & 0x7fffffff) >> 1; uVar10 != 0; uVar10 = uVar10 - 1) {

        *puVar8 = *puVar4;

        puVar4 = puVar4 + 1;

        puVar8 = puVar8 + 1;

      }

      for (uVar10 = uVar12 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {

        *(char *)puVar8 = (char)*puVar4;

        puVar4 = (uint *)((int)puVar4 + 1);

        puVar8 = (uint *)((int)puVar8 + 1);

      }

      puVar20 = (undefined4 *)((int)(puVar18 + 0xc) + uVar12);

      *(undefined2 *)(uVar12 + *(int *)(puVar17 + -0x22)) = 0;

      *(undefined4 *)(puVar17 + -0x1e) = *puVar20;

      *(undefined4 *)(puVar17 + -0x1a) = puVar20[1];

      puVar6 = puVar20 + 2;

      if (local_84 != 0) {

        pcVar24 = local_40;

        for (iVar11 = 8; iVar11 != 0; iVar11 = iVar11 + -1) {

          *(undefined4 *)pcVar24 = *puVar6;

          puVar6 = puVar6 + 1;

          pcVar24 = pcVar24 + 4;

        }

        if (local_40[0] != '\0') {

          uVar9 = FUN_00508750(local_40);

          *(undefined4 *)(puVar17 + -0x16) = uVar9;

        }

        puVar6 = puVar20 + 10;

        pcVar24 = local_60;

        for (iVar11 = 8; iVar11 != 0; iVar11 = iVar11 + -1) {

          *(undefined4 *)pcVar24 = *puVar6;

          puVar6 = puVar6 + 1;

          pcVar24 = pcVar24 + 4;

        }

        puVar6 = puVar20 + 0x12;

        if (local_60[0] != '\0') {

          uVar9 = FUN_00508750(local_60);

          *(undefined4 *)(puVar17 + -0x12) = uVar9;

        }

      }

      *(undefined4 *)(puVar17 + -0xe) = *puVar6;

      puVar18 = puVar6 + 1;

      if (local_80 != 0) {

        *(uint *)(puVar17 + -10) = *puVar18;

        puVar18 = puVar6 + 2;

      }

      uVar10 = *puVar18;

      *(uint *)(puVar17 + -6) = uVar10;

      uVar12 = puVar18[1];

      local_bc = local_bc | uVar10;

      *(uint *)(puVar17 + -2) = uVar12;

      local_8c = (int *)(uVar12 & 0xff);

      uStack_88 = 0;

      iVar11 = __ftol();

      uVar10 = __ftol();

      uVar12 = __ftol();

      uVar13 = __ftol();

      *(uint *)(puVar17 + -2) = ((iVar11 << 8 | uVar10) << 8 | uVar12) << 8 | uVar13;

      local_9c = puVar18[2] & 0xff;

      *(uint *)(puVar17 + 2) = puVar18[2];

      uStack_98 = 0;

      iVar11 = __ftol();

      uVar10 = __ftol();

      uVar12 = __ftol();

      uVar13 = __ftol();

      *(uint *)(puVar17 + 2) = ((iVar11 << 8 | uVar10) << 8 | uVar12) << 8 | uVar13;

      *(uint *)(puVar17 + 6) = puVar18[3];

      iVar11 = __ftol();

      uVar10 = __ftol();

      uVar12 = __ftol();

      uVar13 = __ftol();

      *(uint *)(puVar17 + 6) = ((iVar11 << 8 | uVar10) << 8 | uVar12) << 8 | uVar13;

      uVar10 = puVar18[4];

      *(uint *)(puVar17 + 10) = uVar10;

      local_94 = (int *)(uVar10 & 0xff);

      uStack_90 = 0;

      puVar18 = puVar18 + 5;

      iVar11 = __ftol();

      uVar10 = __ftol();

      uVar12 = __ftol();

      uVar13 = __ftol();

      *(uint *)(puVar17 + 10) = ((iVar11 << 8 | uVar10) << 8 | uVar12) << 8 | uVar13;

      *(uint *)(puVar17 + 0xe) = *puVar18;

      iVar11 = *(int *)(puVar17 + -0x1a);

      *(undefined4 *)(puVar17 + 0x1a) = 0;

      *(undefined4 *)(puVar17 + 0x16) = 0;

      *(undefined4 *)(puVar17 + 0x12) = 0;

      if (0 < iVar11) {

        iVar16 = *(int *)(puVar17 + -0x1e) << 1;

        do {

          *(float *)(puVar17 + 0x12) =

               *(float *)(puVar7[5] + (uint)*(ushort *)(iVar16 + puVar7[0xd]) * 0xc) +

               *(float *)(puVar17 + 0x12);

          iVar11 = iVar11 + -1;

          *(float *)(puVar17 + 0x16) =

               *(float *)(puVar7[5] + 4 + (uint)*(ushort *)(iVar16 + puVar7[0xd]) * 0xc) +

               *(float *)(puVar17 + 0x16);

          *(float *)(puVar17 + 0x1a) =

               *(float *)(puVar7[5] + 8 + (uint)*(ushort *)(iVar16 + puVar7[0xd]) * 0xc) +

               *(float *)(puVar17 + 0x1a);

          iVar16 = iVar16 + 2;

        } while (iVar11 != 0);

      }

      if (0 < *(int *)(puVar17 + -0x1a)) {

        fVar2 = 1.0 / (float)*(int *)(puVar17 + -0x1a);

        *(float *)(puVar17 + 0x12) = fVar2 * *(float *)(puVar17 + 0x12);

        *(float *)(puVar17 + 0x16) = fVar2 * *(float *)(puVar17 + 0x16);

        *(float *)(puVar17 + 0x1a) = fVar2 * *(float *)(puVar17 + 0x1a);

      }

      local_c4 = local_c4 + *(int *)(puVar17 + -0x26);

      iVar11 = puVar7[3] + *(int *)(puVar17 + -0x2e) * 0x24;

      *(int *)(iVar11 + 0x18) = *(int *)(iVar11 + 0x18) + *(int *)(puVar17 + -0x26);

      if (*(int *)(iVar11 + 0x20) == 0) {

        *(int **)(iVar11 + 0x1c) = local_b8;

      }

      *(int *)(iVar11 + 0x20) = *(int *)(iVar11 + 0x20) + 1;

      local_b8 = (int *)((int)local_b8 + 1);

      puVar17 = puVar17 + 0x50;

    } while ((int)local_b8 < (int)uVar1);

  }

  iVar11 = 0;

  if (local_78 != 0) {

    piVar19 = (int *)(local_a0 + 0x18);

    iVar16 = local_78;

    do {

      piVar19[-1] = iVar11;

      iVar11 = iVar11 + *piVar19;

      piVar19 = piVar19 + 9;

      iVar16 = iVar16 + -1;

    } while (iVar16 != 0);

  }

  puVar7[1] = local_bc;

  puVar7[9] = local_c4;

  if ((uVar3 == 0) || (((byte)DAT_00632e94 & 1) == 0)) {

    puVar7[0xb] = 0;

    puVar7[10] = 0;

  }

  else {

    uVar9 = FUN_0053a700(0x11,local_c4 * 0xc,s_face_normals_0055b7ec,

                         s_C__Giants_source_main_makeobj_c_0055b788,0x23f);

    puVar7[10] = uVar9;

    uVar9 = FUN_0053a700(0x11,puVar7[7] * 0xc,s_vertex_normals_0055b7dc,

                         s_C__Giants_source_main_makeobj_c_0055b788,0x240);

    puVar7[0xb] = uVar9;

    DAT_0059dbdc = DAT_0059dbdc + (puVar7[7] + puVar7[9]) * 0xc;

  }

  FUN_00538560(local_a4);

  return puVar7;

}

/* ===== FUN_00472dd0 @ 0x00472DD0 ===== */
void FUN_00472dd0(int param_1)



{

  if (param_1 != 0) {

    mem_free_tagged(*(undefined4 *)(param_1 + 0x14),s_C__Giants_source_main_makeobj_c_0055b788,0x3a6

                   );

    mem_free_tagged(*(undefined4 *)(param_1 + 0x10),s_C__Giants_source_main_makeobj_c_0055b788,0x3a7

                   );

    mem_free_tagged(*(undefined4 *)(param_1 + 0x18),s_C__Giants_source_main_makeobj_c_0055b788,0x3a8

                   );

    mem_free_tagged(*(undefined4 *)(param_1 + 0xc),s_C__Giants_source_main_makeobj_c_0055b788,0x3a9)

    ;

    mem_free_tagged(param_1,s_C__Giants_source_main_makeobj_c_0055b788,0x3aa);

  }

  return;

}

