/* Giants 1.449 — module main/collgrid
 * 5 functions (5 named) — decompiled, names from PS2 symbols
 * Original source: C:\Giants\source\main/collgrid.c(pp) (assert-string evidence)
 */

/* ===== collgrid_clear_grid @ 0x004101D0 ===== */
/* PS2 candidate: collgrid_clear_grid (conf 0.5970000000000001) */



void collgrid_clear_grid(int param_1)



{

  mem_free_tagged(*(undefined4 *)(param_1 + 0x21c),s_C__Giants_source_main_collgrid_c_00555464,0xe);

  *(undefined4 *)(param_1 + 0x21c) = 0;

  return;

}

/* ===== main_collgrid_00410200 @ 0x00410200 ===== */
void main_collgrid_00410200(int param_1)



{

  float fVar1;

  uint uVar2;

  int iVar3;

  undefined4 *puVar4;

  float fVar5;

  float fVar6;

  float *pfVar7;

  undefined4 *puVar8;

  char *pcVar9;

  float *pfVar10;

  undefined1 *local_28c;

  float local_288;

  int local_284;

  float local_280;

  int local_27c;

  float local_278 [3];

  int local_26c;

  undefined1 local_260 [5];

  undefined2 local_25b;

  undefined2 local_259;

  char local_257 [595];

  

  if (*(int *)(param_1 + 0x21c) != 0) {

    return;

  }

  uVar2 = *(uint *)(param_1 + 0x1c8) & 0x800;

  if ((*(uint *)(param_1 + 0xd8) & 0x4000c000) != 0 || uVar2 != 0) {

    return;

  }

  if (uVar2 != 0) {

    return;

  }

  if ((*(uint *)(param_1 + 0x1c8) & 0x400000) != 0) {

    return;

  }

  iVar3 = FUN_004a6220();

  if (((iVar3 != 0) || (iVar3 = FUN_004a6300(), iVar3 != 0)) && (iVar3 = FUN_00417f60(), iVar3 != 0)

     ) {

    return;

  }

  if ((*(uint *)(param_1 + 0xd8) & 0x80000) == 0) {

    if (*(float *)(param_1 + 0x14c) == 0.0) {

      return;

    }

    fVar5 = *(float *)(param_1 + 0xa8) - *(float *)(param_1 + 0x140);

  }

  else {

    fVar5 = *(float *)(param_1 + 0x1d4);

  }

  if (fVar5 <= 4.0) {

    uVar2 = *(uint *)(param_1 + 0x1c8);

    if ((uVar2 & 0x80000) != 0) {

      local_28c = local_260 + 1;

      local_260[0] = 1;

      pfVar7 = (float *)(*(int *)(*(int *)(param_1 + 8) + 0x400) + 0x44);

      pfVar10 = local_278;

      for (iVar3 = 6; iVar3 != 0; iVar3 = iVar3 + -1) {

        *pfVar10 = *pfVar7;

        pfVar7 = pfVar7 + 1;

        pfVar10 = pfVar10 + 1;

      }

      main_collgrid_00410720(param_1,CONCAT44(&local_28c,local_278));

      if (600 < (int)local_28c - (int)local_260) {

        FUN_00518f00();

      }

      mem_free_tagged(*(undefined4 *)(param_1 + 0x21c),s_C__Giants_source_main_collgrid_c_00555464,

                      0x136);

      puVar4 = (undefined4 *)

               FUN_0053a700(6,(int)local_28c - (int)local_260,s_collgrid_00555508,

                            s_C__Giants_source_main_collgrid_c_00555464,0x137);

      *(undefined4 **)(param_1 + 0x21c) = puVar4;

      puVar8 = (undefined4 *)local_260;

      for (uVar2 = (uint)((int)local_28c - (int)local_260) >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {

        *puVar4 = *puVar8;

        puVar8 = puVar8 + 1;

        puVar4 = puVar4 + 1;

      }

      for (uVar2 = (int)local_28c - (int)local_260 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {

        *(undefined1 *)puVar4 = *(undefined1 *)puVar8;

        puVar8 = (undefined4 *)((int)puVar8 + 1);

        puVar4 = (undefined4 *)((int)puVar4 + 1);

      }

      return;

    }

    if ((uVar2 & 0x100000) != 0) {

      main_collgrid_00410c70(param_1,&local_284,&local_288,&local_27c);

      local_28c = local_260 + 1;

      local_260[0] = 2;

      pfVar7 = (float *)(*(int *)(*(int *)(param_1 + 8) + 0x400) + 0x44);

      pfVar10 = local_278;

      for (iVar3 = 6; iVar3 != 0; iVar3 = iVar3 + -1) {

        *pfVar10 = *pfVar7;

        pfVar7 = pfVar7 + 1;

        pfVar10 = pfVar10 + 1;

      }

      local_26c = local_284;

      main_collgrid_00410720(param_1,local_278,&local_28c);

      pfVar7 = (float *)(*(int *)(*(int *)(param_1 + 8) + 0x400) + 0x44);

      pfVar10 = local_278;

      for (iVar3 = 6; iVar3 != 0; iVar3 = iVar3 + -1) {

        *pfVar10 = *pfVar7;

        pfVar7 = pfVar7 + 1;

        pfVar10 = pfVar10 + 1;

      }

      local_278[0] = local_288;

      main_collgrid_00410720(param_1,local_278,&local_28c);

      if (600 < (int)local_28c - (int)local_260) {

        FUN_00518f00();

      }

      mem_free_tagged(*(undefined4 *)(param_1 + 0x21c),s_C__Giants_source_main_collgrid_c_00555464,

                      0x1b2);

      puVar4 = (undefined4 *)

               FUN_0053a700(6,(int)local_28c - (int)local_260,s_collgrid_00555508,

                            s_C__Giants_source_main_collgrid_c_00555464,0x1b3);

      *(undefined4 **)(param_1 + 0x21c) = puVar4;

      puVar8 = (undefined4 *)local_260;

      for (uVar2 = (uint)((int)local_28c - (int)local_260) >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {

        *puVar4 = *puVar8;

        puVar8 = puVar8 + 1;

        puVar4 = puVar4 + 1;

      }

      for (uVar2 = (int)local_28c - (int)local_260 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {

        *(undefined1 *)puVar4 = *(undefined1 *)puVar8;

        puVar8 = (undefined4 *)((int)puVar8 + 1);

        puVar4 = (undefined4 *)((int)puVar4 + 1);

      }

      return;

    }

    if ((uVar2 & 8) != 0) {

      main_collgrid_00411140();

      return;

    }

    if ((uVar2 & 0x1000) != 0) {

      main_collgrid_00411a10();

      return;

    }

    local_278[0] = *(float *)(param_1 + 0xa0);

    local_278[1] = *(float *)(param_1 + 0xa4);

    local_278[2] = *(float *)(param_1 + 0xa8);

    local_28c = *(undefined1 **)(param_1 + 0x154);

    local_260[0] = 5;

    main_005435a5((double)((local_278[1] - (float)local_28c) * 0.2 + 0.5));

    fVar5 = (float)__ftol();

    main_005435a5((double)((local_278[1] + (float)local_28c) * 0.2 + 0.5));

    iVar3 = __ftol();

    local_284 = iVar3;

    main_005435a5((double)((local_278[0] - (float)local_28c) * 0.2 + 0.5));

    fVar6 = (float)__ftol();

    main_005435a5((double)((local_278[0] + (float)local_28c) * 0.2 + 0.5));

    local_25b = __ftol();

    local_259 = (undefined2)iVar3;

    local_260._1_2_ = SUB42(fVar6,0);

    local_260._3_2_ = SUB42(fVar5,0);

    pcVar9 = local_257;

    local_288 = fVar5;

    if ((int)fVar5 <= local_284) {

      do {

        fVar1 = ABS(local_278[1] - (float)(int)fVar5 * 5.0);

        if (fVar1 < (float)local_28c) {

          local_280 = SQRT((float)local_28c * (float)local_28c - fVar1 * fVar1);

        }

        else {

          local_280 = 0.0;

        }

        local_288 = fVar6;

        main_005435a5((double)((local_278[0] - local_280) * 0.2 + 0.5));

        fVar6 = (float)__ftol();

        main_005435a5((double)((local_280 + local_278[0]) * 0.2 + 0.5));

        local_27c = __ftol();

        uVar2 = (int)fVar6 - (int)local_288 >> 0x1f;

        if (0x7f < (int)(((int)fVar6 - (int)local_288 ^ uVar2) - uVar2)) {

          FUN_00518f00();

        }

        *pcVar9 = SUB41(fVar6,0) - local_288._0_1_;

        pcVar9[1] = ((char)local_27c - SUB41(fVar6,0)) + '\x01';

        if (0xff < local_27c - (int)fVar6) {

          FUN_00518f00();

        }

        pcVar9 = pcVar9 + 2;

        fVar5 = (float)((int)fVar5 + 1);

        local_288 = fVar5;

      } while ((int)fVar5 <= local_284);

    }

    *pcVar9 = -0x80;

    pcVar9 = pcVar9 + (1 - (int)local_260);

    if (600 < (int)pcVar9) {

      FUN_00518f00();

    }

    mem_free_tagged(*(undefined4 *)(param_1 + 0x21c),s_C__Giants_source_main_collgrid_c_00555464,

                    0x8e);

    puVar4 = (undefined4 *)

             FUN_0053a700(6,pcVar9,s_collgrid_00555508,s_C__Giants_source_main_collgrid_c_00555464,

                          0x8f);

    *(undefined4 **)(param_1 + 0x21c) = puVar4;

    puVar8 = (undefined4 *)local_260;

    for (uVar2 = (uint)pcVar9 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {

      *puVar4 = *puVar8;

      puVar8 = puVar8 + 1;

      puVar4 = puVar4 + 1;

    }

    for (uVar2 = (uint)pcVar9 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {

      *(undefined1 *)puVar4 = *(undefined1 *)puVar8;

      puVar8 = (undefined4 *)((int)puVar8 + 1);

      puVar4 = (undefined4 *)((int)puVar4 + 1);

    }

  }

  return;

}

/* ===== main_collgrid_00410c70 @ 0x00410C70 ===== */
void main_collgrid_00410c70(int param_1,float *param_2,float *param_3,float *param_4)



{

  float *pfVar1;

  float *pfVar2;

  float *pfVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  undefined4 *puVar7;

  int iVar8;

  int iVar9;

  int iVar10;

  uint uVar11;

  undefined4 *puVar12;

  int iVar13;

  uint uVar14;

  undefined4 *puVar15;

  char *pcVar16;

  float fVar17;

  float local_48;

  float local_44;

  float local_40;

  undefined4 *local_34;

  int local_30;

  int local_2c;

  int local_28;

  int local_24;

  undefined4 local_20;

  undefined4 local_1c;

  int local_18;

  int local_14;

  int local_10;

  int local_c;

  

  iVar9 = *(int *)(*(int *)(param_1 + 8) + 0x400);

  local_18 = iVar9;

  main_005435a5((double)*(float *)(iVar9 + 0x44));

  iVar4 = __ftol();

  local_10 = iVar4;

  main_005435a5((double)*(float *)(iVar9 + 0x50));

  iVar5 = __ftol();

  main_005435a5((double)(*(float *)(iVar9 + 0x4c) * 0.25));

  iVar6 = __ftol();

  iVar5 = iVar5 - iVar4;

  iVar13 = iVar5 + 1;

  main_005435a5((double)(*(float *)(iVar9 + 0x58) * 0.25));

  iVar4 = __ftol();

  uVar14 = ((iVar4 - iVar6) + 1) * iVar13;

  puVar7 = (undefined4 *)

           FUN_0053a700(6,uVar14,&DAT_005555ac,s_C__Giants_source_main_collgrid_c_00555464,0x156);

  puVar12 = puVar7;

  for (uVar11 = uVar14 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {

    *puVar12 = 0;

    puVar12 = puVar12 + 1;

  }

  for (uVar14 = uVar14 & 3; uVar14 != 0; uVar14 = uVar14 - 1) {

    *(undefined1 *)puVar12 = 0;

    puVar12 = (undefined4 *)((int)puVar12 + 1);

  }

  local_14 = 0;

  if (0 < *(int *)(iVar9 + 0x68)) {

    local_34 = (undefined4 *)(iVar9 + 0x84);

    do {

      local_1c = *local_34;

      local_20 = 0xffff;

      iVar4 = main_00430e10(&local_1c,&local_20,&local_24,&local_28,&local_2c);

      while (iVar4 != 0) {

        iVar4 = *(int *)(iVar9 + 0x34);

        iVar9 = *(int *)(iVar9 + 0x14);

        uVar11 = (uint)*(ushort *)(iVar4 + local_24 * 2);

        fVar17 = *(float *)(iVar9 + uVar11 * 0xc);

        pfVar1 = (float *)(iVar9 + uVar11 * 0xc);

        uVar11 = (uint)*(ushort *)(iVar4 + local_28 * 2);

        pfVar2 = (float *)(iVar9 + uVar11 * 0xc);

        pfVar3 = (float *)(iVar9 + (uint)*(ushort *)(iVar4 + local_2c * 2) * 0xc);

        if (*(float *)(iVar9 + uVar11 * 0xc) < fVar17) {

          fVar17 = *pfVar2;

        }

        if (*pfVar3 < fVar17) {

          fVar17 = *pfVar3;

        }

        local_44 = *pfVar1;

        if (local_44 < *pfVar2) {

          local_44 = *pfVar2;

        }

        if (local_44 < *pfVar3) {

          local_44 = *pfVar3;

        }

        local_48 = pfVar1[2];

        if (pfVar2[2] < local_48) {

          local_48 = pfVar2[2];

        }

        if (pfVar3[2] < local_48) {

          local_48 = pfVar3[2];

        }

        local_40 = pfVar1[2];

        if (local_40 < pfVar2[2]) {

          local_40 = pfVar2[2];

        }

        if (local_40 < pfVar3[2]) {

          local_40 = pfVar3[2];

        }

        main_005435a5((double)fVar17);

        iVar8 = __ftol();

        iVar9 = local_10;

        iVar8 = iVar8 - local_10;

        main_005435a5((double)local_44);

        iVar4 = __ftol();

        iVar4 = iVar4 - iVar9;

        local_c = iVar4;

        main_005435a5((double)(local_48 * 0.25));

        iVar9 = __ftol();

        iVar9 = iVar9 - iVar6;

        main_005435a5((double)(local_40 * 0.25));

        iVar10 = __ftol();

        if (iVar9 <= iVar10 - iVar6) {

          puVar12 = (undefined4 *)(iVar9 * iVar13 + iVar8 + (int)puVar7);

          local_30 = ((iVar10 - iVar6) - iVar9) + 1;

          do {

            if (iVar8 <= iVar4) {

              uVar14 = (iVar4 - iVar8) + 1;

              puVar15 = puVar12;

              for (uVar11 = uVar14 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {

                *puVar15 = 0x1010101;

                puVar15 = puVar15 + 1;

              }

              for (uVar14 = uVar14 & 3; iVar4 = local_c, uVar14 != 0; uVar14 = uVar14 - 1) {

                *(undefined1 *)puVar15 = 1;

                puVar15 = (undefined4 *)((int)puVar15 + 1);

              }

            }

            puVar12 = (undefined4 *)((int)puVar12 + iVar13);

            local_30 = local_30 + -1;

          } while (local_30 != 0);

        }

        iVar4 = main_00430e10(&local_1c,&local_20,&local_24,&local_28,&local_2c);

        iVar9 = local_18;

      }

      local_14 = local_14 + 1;

      local_34 = local_34 + 0x14;

    } while (local_14 < *(int *)(iVar9 + 0x68));

  }

  iVar9 = 1;

  local_48 = 1.4013e-45;

  if (1 < iVar13) {

    do {

      local_48 = (float)iVar9;

      if (*(char *)(iVar9 + (int)puVar7) == '\0') break;

      iVar9 = iVar9 + 1;

      local_48 = (float)iVar9;

    } while (iVar9 < iVar13);

  }

  for (; (fVar17 = local_48, (int)local_48 <= iVar5 && (*(char *)(iVar5 + (int)puVar7) != '\0'));

      iVar5 = iVar5 + -1) {

  }

  for (; (int)fVar17 <= iVar5; fVar17 = (float)((int)fVar17 + 1)) {

    if (*(char *)((int)fVar17 + (int)puVar7) != '\0') {

      FUN_0051ea20();

    }

  }

  local_44 = 0.0;

  fVar17 = local_48;

  local_14 = (int)local_44;

  do {

    local_44 = (float)local_14;

    local_48 = fVar17;

    iVar9 = iVar5;

    puVar12 = (undefined4 *)((int)local_44 * iVar13 + (int)puVar7);

    pcVar16 = (char *)(((int)local_44 + 1) * iVar13 + iVar9 + (int)puVar7);

    local_c = (int)local_48 - iVar9;

    while ((pcVar16[local_c] == '\0' && (*pcVar16 == '\0'))) {

      local_44 = (float)((int)local_44 + 1);

      pcVar16 = pcVar16 + iVar13;

      puVar12 = (undefined4 *)((int)puVar12 + iVar13);

      for (local_14 = (int)local_48; local_14 <= iVar9; local_14 = local_14 + 1) {

        if (*(char *)((int)puVar12 + local_14) != '\0') {

          FUN_0051ea20();

        }

      }

    }

    fVar17 = local_48;

    if ((int)local_48 <= iVar9) {

      pcVar16 = (char *)(((int)local_44 + 1) * iVar13 + (int)local_48 + (int)puVar7);

      do {

        if (*pcVar16 == '\0') break;

        fVar17 = (float)((int)fVar17 + 1);

        pcVar16 = pcVar16 + 1;

      } while ((int)fVar17 <= iVar9);

    }

    iVar5 = iVar9;

    if ((int)fVar17 <= iVar9) {

      pcVar16 = (char *)(((int)local_44 + 1) * iVar13 + iVar9 + (int)puVar7);

      do {

        if (*pcVar16 == '\0') break;

        iVar5 = iVar5 + -1;

        pcVar16 = pcVar16 + -1;

      } while ((int)fVar17 <= iVar5);

    }

    local_c = (iVar5 - (int)fVar17) + 1;

    local_14 = (int)local_44 + 1;

    if ((float)local_c < (float)local_14 * 8.0) {

      mem_free_tagged(puVar7,s_C__Giants_source_main_collgrid_c_00555464,400);

      *param_2 = (float)((int)local_48 + local_10);

      *param_3 = (float)(iVar9 + local_10) + 0.5;

      *param_4 = ((float)((int)local_44 + iVar6) + 1.0) * 4.0;

      return;

    }

  } while( true );

}

/* ===== main_collgrid_00411140 @ 0x00411140 ===== */
void main_collgrid_00411140(int param_1)



{

  byte *pbVar1;

  byte bVar2;

  ushort uVar3;

  ushort uVar4;

  char *pcVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  int iVar9;

  int iVar10;

  int iVar11;

  undefined4 *puVar12;

  uint uVar13;

  float *pfVar14;

  uint uVar15;

  float *pfVar16;

  undefined4 *puVar17;

  float10 fVar18;

  float local_bc;

  float local_b8;

  float local_b4;

  float local_b0;

  float local_ac;

  float local_a8;

  float local_a4;

  float local_a0;

  float local_9c;

  float local_98;

  float local_94;

  float local_90;

  float local_8c;

  float local_88;

  undefined4 *local_84;

  float local_80;

  int local_7c;

  float local_78;

  float local_74;

  float local_70;

  float local_6c;

  int local_68;

  undefined4 *local_64;

  undefined2 *local_60;

  int local_5c;

  int local_58;

  int local_54;

  int local_50;

  int local_4c;

  undefined4 local_48;

  int local_44;

  undefined4 local_40;

  int local_3c;

  int local_38;

  float local_34;

  float local_30;

  float local_2c;

  float local_28;

  byte *local_24;

  float local_20 [4];

  float local_10;

  

  iVar9 = main_0042b1d0();

  local_7c = *(int *)(*(int *)(param_1 + 8) + 0x400 + iVar9 * 4);

  pfVar14 = (float *)(param_1 + 0x27c);

  pfVar16 = local_20;

  for (iVar9 = 6; iVar9 != 0; iVar9 = iVar9 + -1) {

    *pfVar16 = *pfVar14;

    pfVar14 = pfVar14 + 1;

    pfVar16 = pfVar16 + 1;

  }

  if (local_20[0] != local_20[3]) {

    main_005435a5((double)(local_20[0] * 0.2 + 0.5));

    iVar9 = __ftol();

    local_68 = iVar9;

    main_005435a5((double)(local_20[1] * 0.2 + 0.5));

    iVar10 = __ftol();

    local_4c = iVar10;

    main_005435a5((double)(local_20[3] * 0.2 + 0.5));

    iVar11 = __ftol();

    local_58 = iVar11;

    main_005435a5((double)(local_10 * 0.2 + 0.5));

    local_44 = __ftol();

    local_3c = (iVar11 - iVar9) + 1;

    uVar15 = ((local_44 - iVar10) + 1) * local_3c + 9;

    puVar12 = (undefined4 *)

              FUN_0053a700(6,uVar15,s_collpgrid_005555b4,s_C__Giants_source_main_collgrid_c_00555464

                           ,0x202);

    puVar17 = puVar12;

    for (uVar13 = uVar15 >> 2; uVar13 != 0; uVar13 = uVar13 - 1) {

      *puVar17 = 0;

      puVar17 = puVar17 + 1;

    }

    for (uVar15 = uVar15 & 3; uVar15 != 0; uVar15 = uVar15 - 1) {

      *(undefined1 *)puVar17 = 0;

      puVar17 = (undefined4 *)((int)puVar17 + 1);

    }

    *(undefined4 **)(param_1 + 0x21c) = puVar12;

    *(undefined1 *)puVar12 = 3;

    local_60 = (undefined2 *)((int)puVar12 + 1);

    *(undefined2 *)((int)puVar12 + 3) = (undefined2)local_4c;

    *local_60 = (short)iVar9;

    *(undefined2 *)((int)puVar12 + 5) = (undefined2)local_58;

    *(undefined2 *)((int)puVar12 + 7) = (undefined2)local_44;

    local_5c = 0;

    if (0 < *(int *)(local_7c + 0x68)) {

      local_64 = (undefined4 *)(local_7c + 0x84);

      iVar9 = local_7c;

      do {

        local_48 = *local_64;

        local_40 = 0xffff;

        iVar10 = main_00430e10(&local_48,&local_40,&local_50,&local_38,&local_54);

        fVar6 = local_b8;

        fVar7 = local_b4;

        fVar8 = local_b0;

        while (local_b8 = fVar6, local_b4 = fVar7, local_b0 = fVar8, iVar10 != 0) {

          iVar10 = *(int *)(iVar9 + 0x34);

          iVar9 = *(int *)(iVar9 + 0x14);

          uVar3 = *(ushort *)(iVar10 + local_38 * 2);

          uVar4 = *(ushort *)(iVar10 + local_54 * 2);

          FUN_005170f0(param_1,iVar9 + (uint)*(ushort *)(iVar10 + local_50 * 2) * 0xc);

          FUN_005170f0(param_1,iVar9 + (uint)uVar3 * 0xc,&local_a8);

          FUN_005170f0(param_1,iVar9 + (uint)uVar4 * 0xc,&local_94);

          local_80 = local_90 - fVar7;

          local_78 = (local_8c - fVar8) * (local_a4 - fVar7) - (local_a0 - fVar8) * local_80;

          local_88 = local_94 - fVar6;

          local_84 = (undefined4 *)(local_a8 - fVar6);

          local_74 = local_88 * (local_a0 - fVar8) - (float)local_84 * (local_8c - fVar8);

          local_70 = (float)local_84 * local_80 - local_88 * (local_a4 - fVar7);

          FUN_0050a810(&local_78,&local_74,&local_70);

          local_6c = -(local_70 * fVar8 + local_74 * fVar7 + fVar6 * local_78);

          if (local_a4 < fVar7) {

            local_b8 = local_a8;

            local_b4 = local_a4;

            local_b0 = local_a0;

            local_a8 = fVar6;

            local_a4 = fVar7;

            local_a0 = fVar8;

          }

          fVar8 = local_a0;

          fVar7 = local_a4;

          fVar6 = local_a8;

          if (local_90 < local_a4) {

            local_a8 = local_94;

            local_a4 = local_90;

            local_a0 = local_8c;

            local_94 = fVar6;

            local_90 = fVar7;

            local_8c = fVar8;

          }

          fVar8 = local_a0;

          fVar7 = local_a4;

          fVar6 = local_a8;

          if (local_a4 < local_b4) {

            local_a8 = local_b8;

            local_a4 = local_b4;

            local_a0 = local_b0;

            local_b8 = fVar6;

            local_b4 = fVar7;

            local_b0 = fVar8;

          }

          local_bc = local_b4;

          if (local_b4 < (local_90 + 5.0) - 0.5) {

            do {

              if ((local_a4 < local_bc) && ((local_bc - 5.0) + 0.5 < local_a4)) {

                local_bc = local_a4;

              }

              if (local_90 < local_bc) {

                local_bc = local_90;

              }

              if (local_b4 == local_90) {

                local_98 = local_b8;

                if (local_a8 < local_b8) {

                  local_98 = local_a8;

                }

                if (local_94 < local_98) {

                  local_98 = local_94;

                }

                local_ac = local_b8;

                if (local_b8 < local_a8) {

                  local_ac = local_a8;

                }

                if (local_ac < local_94) {

                  local_ac = local_94;

                }

              }

              else {

                fVar6 = ((local_94 - local_b8) * (local_b4 - local_bc)) / (local_b4 - local_90) +

                        local_b8;

                if ((local_bc < local_a4) || (local_a4 == local_90)) {

                  local_ac = ((local_a8 - local_b8) * (local_b4 - local_bc)) / (local_b4 - local_a4)

                             + local_b8;

                }

                else {

                  local_ac = ((local_94 - local_a8) * (local_a4 - local_bc)) / (local_a4 - local_90)

                             + local_a8;

                }

                local_98 = fVar6;

                if (local_ac < fVar6) {

                  local_98 = local_ac;

                  local_ac = fVar6;

                }

              }

              local_9c = local_98;

              local_80 = (local_ac + 5.0) - 0.5;

              if (local_98 < local_80) {

                local_28 = local_bc * 0.2 + 0.5;

                do {

                  if (local_ac < local_9c) {

                    local_9c = local_ac;

                  }

                  main_005435a5((double)local_28);

                  iVar10 = __ftol();

                  main_005435a5((double)(local_9c * 0.2 + 0.5));

                  iVar11 = __ftol();

                  iVar9 = local_4c;

                  if ((((local_68 <= iVar11) && (iVar11 <= local_58)) && (local_4c <= iVar10)) &&

                     (iVar10 <= local_44)) {

                    local_34 = local_9c;

                    local_30 = local_bc;

                    if (local_70 == 0.0) {

                      local_2c = local_b0;

                    }

                    else {

                      local_2c = -((local_9c * local_78 + local_bc * local_74 + local_6c) / local_70

                                  );

                    }

                    fVar18 = (float10)FUN_00455600();

                    local_88 = (float)fVar18;

                    if (local_70 <= 0.64278) {

                      if (local_2c - local_88 < 8.0 != (local_2c - local_88 == 8.0)) {

                        iVar11 = ((iVar10 - iVar9) * local_3c - local_68) + iVar11;

                        *(byte *)(iVar11 + 8 + (int)local_60) =

                             *(byte *)(iVar11 + 8 + (int)local_60) | 1;

                      }

                    }

                    else {

                      local_24 = (byte *)(((iVar10 - iVar9) * local_3c - local_68) + iVar11 + 8 +

                                         (int)local_60);

                      bVar2 = *local_24;

                      *local_24 = bVar2 | 2;

                      local_84 = DAT_00632d68;

                      if ((((local_9c == local_98) || (local_9c == local_ac)) &&

                          ((local_bc == local_b4 || (local_bc == local_90)))) &&

                         ((local_2c - local_88 < 0.5 && (-2.0 < local_2c - local_88)))) {

                        *local_24 = bVar2 | 6;

                        local_84 = DAT_00632d68;

                      }

                      for (; local_84 != (undefined4 *)0x0; local_84 = (undefined4 *)*local_84) {

                        iVar9 = local_84[3];

                        if ((((-1 < (char)((uint)*(undefined4 *)(iVar9 + 0xd8) >> 8)) &&

                             (iVar9 != param_1)) &&

                            (pcVar5 = *(char **)(iVar9 + 0x21c), pcVar5 != (char *)0x0)) &&

                           (((*(byte *)(iVar9 + 0x1c8) & 8) != 0 && (*pcVar5 == '\x03')))) {

                          iVar9 = (int)*(short *)(pcVar5 + 1);

                          local_88 = (float)(int)*(short *)(pcVar5 + 3);

                          if (((iVar9 <= iVar11) &&

                              (((int)local_88 <= iVar10 && (iVar11 <= *(short *)(pcVar5 + 5))))) &&

                             (iVar10 <= *(short *)(pcVar5 + 7))) {

                            pbVar1 = (byte *)(pcVar5 + (((*(short *)(pcVar5 + 5) - iVar9) + 1) *

                                                        (iVar10 - (int)local_88) - iVar9) + iVar11 +

                                                       9);

                            if (((*pbVar1 & 2) != 0) && ((*pbVar1 & 4) == 0)) {

                              *pbVar1 = *pbVar1 | 8;

                              *local_24 = *local_24 | 8;

                              break;

                            }

                          }

                        }

                      }

                    }

                  }

                  local_9c = local_9c + 5.0;

                } while (local_9c < local_80);

              }

              local_bc = local_bc + 5.0;

            } while (local_bc < (local_90 + 5.0) - 0.5);

          }

          iVar10 = main_00430e10(&local_48,&local_40,&local_50,&local_38,&local_54);

          iVar9 = local_7c;

          fVar6 = local_b8;

          fVar7 = local_b4;

          fVar8 = local_b0;

        }

        local_5c = local_5c + 1;

        local_64 = local_64 + 0x14;

      } while (local_5c < *(int *)(iVar9 + 0x68));

    }

  }

  return;

}

/* ===== main_collgrid_00411a10 @ 0x00411A10 ===== */
void main_collgrid_00411a10(int param_1)



{

  ushort uVar1;

  ushort uVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  undefined4 *puVar9;

  uint uVar10;

  float *pfVar11;

  uint uVar12;

  float *pfVar13;

  undefined4 *puVar14;

  float local_a8;

  float local_a4;

  float local_a0;

  float local_9c;

  float local_94;

  float local_90;

  float local_8c;

  float local_88;

  float local_84;

  float local_80;

  float local_7c;

  float local_78;

  float local_74;

  undefined4 *local_70;

  int local_6c;

  int local_68;

  float local_64;

  float local_60;

  float local_5c;

  float local_58;

  int local_54;

  int local_50;

  undefined4 local_4c;

  int local_48;

  int local_44;

  int local_40;

  int local_3c;

  undefined4 local_38;

  undefined1 *local_34;

  int local_30;

  float local_2c [4];

  float local_1c;

  float local_14;

  float local_10;

  float local_c;

  

  iVar6 = main_0042b1d0();

  local_6c = *(int *)(*(int *)(param_1 + 8) + 0x400 + iVar6 * 4);

  pfVar11 = (float *)(param_1 + 0x27c);

  pfVar13 = local_2c;

  for (iVar6 = 6; iVar6 != 0; iVar6 = iVar6 + -1) {

    *pfVar13 = *pfVar11;

    pfVar11 = pfVar11 + 1;

    pfVar13 = pfVar13 + 1;

  }

  if (local_2c[0] != local_2c[3]) {

    main_005435a5((double)(local_2c[0] * 0.2 + 0.5));

    iVar6 = __ftol();

    main_005435a5((double)(local_2c[1] * 0.2 + 0.5));

    iVar7 = __ftol();

    local_68 = iVar7;

    main_005435a5((double)(local_2c[3] * 0.2 + 0.5));

    iVar8 = __ftol();

    main_005435a5((double)(local_1c * 0.2 + 0.5));

    local_50 = __ftol();

    local_30 = ((int)((iVar8 - iVar6) + (iVar8 - iVar6 >> 0x1f & 7U)) >> 3) + 1;

    uVar12 = ((local_50 - iVar7) + 1) * local_30 + 9;

    local_40 = iVar6 + -1 + local_30 * 8;

    puVar9 = (undefined4 *)

             FUN_0053a700(6,uVar12,s_collmgrid_005555c0,s_C__Giants_source_main_collgrid_c_00555464,

                          0x289);

    puVar14 = puVar9;

    for (uVar10 = uVar12 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {

      *puVar14 = 0;

      puVar14 = puVar14 + 1;

    }

    for (uVar12 = uVar12 & 3; uVar12 != 0; uVar12 = uVar12 - 1) {

      *(undefined1 *)puVar14 = 0;

      puVar14 = (undefined4 *)((int)puVar14 + 1);

    }

    *(undefined4 **)(param_1 + 0x21c) = puVar9;

    *(undefined1 *)puVar9 = 4;

    local_34 = (undefined1 *)((int)puVar9 + 9);

    *(undefined2 *)((int)puVar9 + 3) = (undefined2)local_68;

    *(short *)((int)puVar9 + 1) = (short)iVar6;

    *(undefined2 *)((int)puVar9 + 5) = (undefined2)local_40;

    *(undefined2 *)((int)puVar9 + 7) = (undefined2)local_50;

    local_44 = 0;

    if (0 < *(int *)(local_6c + 0x68)) {

      local_70 = (undefined4 *)(local_6c + 0x84);

      iVar7 = local_6c;

      do {

        local_38 = *local_70;

        local_4c = 0xffff;

        iVar8 = main_00430e10(&local_38,&local_4c,&local_3c,&local_54,&local_48);

        fVar3 = local_a4;

        fVar4 = local_a0;

        fVar5 = local_9c;

        while (local_a4 = fVar3, local_a0 = fVar4, local_9c = fVar5, iVar8 != 0) {

          iVar8 = *(int *)(iVar7 + 0x34);

          iVar7 = *(int *)(iVar7 + 0x14);

          uVar1 = *(ushort *)(iVar8 + local_54 * 2);

          uVar2 = *(ushort *)(iVar8 + local_48 * 2);

          FUN_005170f0(param_1,iVar7 + (uint)*(ushort *)(iVar8 + local_3c * 2) * 0xc);

          FUN_005170f0(param_1,iVar7 + (uint)uVar1 * 0xc,&local_94);

          FUN_005170f0(param_1,iVar7 + (uint)uVar2 * 0xc,&local_80);

          local_74 = local_7c - fVar4;

          local_64 = (local_78 - fVar5) * (local_90 - fVar4) - (local_8c - fVar5) * local_74;

          local_88 = local_94 - fVar3;

          local_60 = (local_80 - fVar3) * (local_8c - fVar5) - local_88 * (local_78 - fVar5);

          local_5c = local_88 * local_74 - (local_80 - fVar3) * (local_90 - fVar4);

          FUN_0050a810(&local_64,&local_60,&local_5c);

          local_58 = -(local_5c * fVar5 + local_60 * fVar4 + fVar3 * local_64);

          if (local_90 < fVar4) {

            local_a4 = local_94;

            local_a0 = local_90;

            local_9c = local_8c;

            local_94 = fVar3;

            local_90 = fVar4;

            local_8c = fVar5;

          }

          fVar5 = local_8c;

          fVar4 = local_90;

          fVar3 = local_94;

          if (local_7c < local_90) {

            local_94 = local_80;

            local_90 = local_7c;

            local_8c = local_78;

            local_80 = fVar3;

            local_7c = fVar4;

            local_78 = fVar5;

            local_2c[2] = fVar5;

          }

          fVar5 = local_8c;

          fVar4 = local_90;

          fVar3 = local_94;

          if (local_90 < local_a0) {

            local_2c[1] = local_a0;

            local_94 = local_a4;

            local_90 = local_a0;

            local_8c = local_9c;

            local_a4 = fVar3;

            local_a0 = fVar4;

            local_9c = fVar5;

          }

          local_a8 = local_a0;

          if (local_a0 < (local_7c + 5.0) - 0.5) {

            do {

              if ((local_90 < local_a8) && ((local_a8 - 5.0) + 0.5 < local_90)) {

                local_a8 = local_90;

              }

              if (local_7c < local_a8) {

                local_a8 = local_7c;

              }

              if (local_a0 == local_7c) {

                local_88 = local_a4;

                if (local_94 < local_a4) {

                  local_88 = local_94;

                }

                if (local_80 < local_88) {

                  local_88 = local_80;

                }

                local_84 = local_a4;

                if (local_a4 < local_94) {

                  local_84 = local_94;

                }

                if (local_84 < local_80) {

                  local_84 = local_80;

                }

              }

              else {

                fVar3 = ((local_80 - local_a4) * (local_a0 - local_a8)) / (local_a0 - local_7c) +

                        local_a4;

                if ((local_a8 < local_90) || (local_90 == local_7c)) {

                  local_84 = ((local_94 - local_a4) * (local_a0 - local_a8)) / (local_a0 - local_90)

                             + local_a4;

                }

                else {

                  local_84 = ((local_80 - local_94) * (local_90 - local_a8)) / (local_90 - local_7c)

                             + local_94;

                }

                local_88 = fVar3;

                if (local_84 < fVar3) {

                  local_88 = local_84;

                  local_84 = fVar3;

                }

              }

              fVar3 = (local_84 + 5.0) - 0.5;

              if (local_88 < fVar3) {

                local_74 = local_a8 * 0.2 + 0.5;

                do {

                  if (local_84 < local_88) {

                    local_88 = local_84;

                  }

                  main_005435a5((double)local_74);

                  iVar7 = __ftol();

                  main_005435a5((double)(local_88 * 0.2 + 0.5));

                  iVar8 = __ftol();

                  if ((((iVar6 <= iVar8) && (iVar8 <= local_40)) && (local_68 <= iVar7)) &&

                     (iVar7 <= local_50)) {

                    local_14 = local_88;

                    local_10 = local_a8;

                    if (local_5c == 0.0) {

                      local_c = local_9c;

                    }

                    else {

                      local_c = -((local_88 * local_64 + local_a8 * local_60 + local_58) / local_5c)

                      ;

                    }

                    FUN_00455600();

                    uVar10 = iVar8 - iVar6;

                    uVar12 = uVar10 & 0x80000007;

                    if ((int)uVar12 < 0) {

                      uVar12 = (uVar12 - 1 | 0xfffffff8) + 1;

                    }

                    local_34[((int)(uVar10 + ((int)uVar10 >> 0x1f & 7U)) >> 3) +

                             (iVar7 - local_68) * local_30] =

                         local_34[((int)(uVar10 + ((int)uVar10 >> 0x1f & 7U)) >> 3) +

                                  (iVar7 - local_68) * local_30] | '\x01' << ((byte)uVar12 & 0x1f);

                  }

                  local_88 = local_88 + 5.0;

                } while (local_88 < fVar3);

              }

              local_a8 = local_a8 + 5.0;

            } while (local_a8 < (local_7c + 5.0) - 0.5);

          }

          iVar8 = main_00430e10(&local_38,&local_4c,&local_3c,&local_54,&local_48);

          iVar7 = local_6c;

          fVar3 = local_a4;

          fVar4 = local_a0;

          fVar5 = local_9c;

        }

        local_44 = local_44 + 1;

        local_70 = local_70 + 0x14;

      } while (local_44 < *(int *)(iVar7 + 0x68));

    }

  }

  return;

}

