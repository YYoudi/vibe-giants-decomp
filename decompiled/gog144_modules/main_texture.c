/* Giants 1.449 — module main/texture
 * 8 functions (0 named) — decompiled, names from PS2 symbols
 * Original source: C:\Giants\source\main/texture.c(pp) (assert-string evidence)
 */

/* ===== FUN_00507c50 @ 0x00507C50 ===== */
void FUN_00507c50(char *param_1,undefined4 param_2)



{

  char cVar1;

  int iVar2;

  int iVar3;

  undefined4 *puVar4;

  char *pcVar5;

  uint uVar6;

  uint uVar7;

  undefined4 *puVar8;

  undefined1 local_29;

  uint local_28;

  uint local_24;

  char local_20 [32];

  

  for (puVar8 = DAT_005a8844; puVar8 != (undefined4 *)0x0; puVar8 = (undefined4 *)*puVar8) {

    iVar2 = FUN_0053a860(puVar8 + 1,param_1);

    if (iVar2 != 0) {

      return;

    }

  }

  iVar3 = FUN_00517970(param_2);

  FUN_005178d0(param_2,&local_28,4);

  iVar2 = 0;

  if (local_28 != 0) {

    uVar7 = 0;

    do {

      FUN_00517950(param_2,1);

      FUN_00517950(param_2,1);

      FUN_005178d0(param_2,&local_24,1);

      FUN_005178d0(param_2,local_20,local_24 & 0xff);

      uVar6 = 0xffffffff;

      pcVar5 = local_20;

      do {

        if (uVar6 == 0) break;

        uVar6 = uVar6 - 1;

        cVar1 = *pcVar5;

        pcVar5 = pcVar5 + 1;

      } while (cVar1 != '\0');

      uVar7 = uVar7 + 1;

      iVar2 = ~uVar6 + iVar2;

    } while (uVar7 < local_28);

  }

  uVar7 = iVar2 + 0x2c + local_28 * 0x24;

  puVar4 = (undefined4 *)

           FUN_0053a700(0x1d,uVar7,&DAT_0057bd08,s_C__Giants_source_main_texture_c_0057bd0c,0xf5);

  puVar8 = puVar4;

  for (uVar6 = uVar7 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {

    *puVar8 = 0;

    puVar8 = puVar8 + 1;

  }

  for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {

    *(undefined1 *)puVar8 = 0;

    puVar8 = (undefined4 *)((int)puVar8 + 1);

  }

  *puVar4 = DAT_005a8844;

  iVar2 = 4 - (int)param_1;

  DAT_005a8844 = puVar4;

  do {

    cVar1 = *param_1;

    param_1[(int)((int)puVar4 + iVar2)] = cVar1;

    param_1 = param_1 + 1;

  } while (cVar1 != '\0');

  puVar4[9] = iVar3;

  puVar4[10] = local_28;

  puVar8 = puVar4 + local_28 * 9 + 0xb;

  FUN_00517930(param_2,iVar3 + 4);

  param_1 = (char *)0x0;

  if (local_28 != 0) {

    puVar4 = puVar4 + 0xb;

    do {

      FUN_005178d0(param_2,&local_29,1);

      *(undefined1 *)(puVar4 + 8) = local_29;

      FUN_005178d0(param_2,&local_29,1);

      *(undefined1 *)((int)puVar4 + 0x23) = local_29;

      FUN_005178d0(param_2,&local_24,1);

      FUN_005178d0(param_2,local_20,local_24 & 0xff);

      *puVar4 = puVar8;

      pcVar5 = local_20;

      do {

        cVar1 = *pcVar5;

        pcVar5[(int)puVar8 - (int)local_20] = cVar1;

        pcVar5 = pcVar5 + 1;

      } while (cVar1 != '\0');

      uVar7 = 0xffffffff;

      pcVar5 = local_20;

      do {

        if (uVar7 == 0) break;

        uVar7 = uVar7 - 1;

        cVar1 = *pcVar5;

        pcVar5 = pcVar5 + 1;

      } while (cVar1 != '\0');

      puVar4[2] = 0;

      puVar4[6] = 8;

      puVar4[5] = 8;

      puVar8 = (undefined4 *)((int)puVar8 + ~uVar7);

      param_1 = (char *)((int)param_1 + 1);

      puVar4 = puVar4 + 9;

    } while (param_1 < local_28);

  }

  return;

}

/* ===== FUN_00507e50 @ 0x00507E50 ===== */
void FUN_00507e50(void)



{

  undefined4 *puVar1;

  undefined4 *puVar2;

  byte *pbVar3;

  uint uVar4;

  undefined4 *puVar5;

  

  for (puVar5 = DAT_005a8844; puVar2 = DAT_005a8844, puVar1 = DAT_005a8848,

      puVar5 != (undefined4 *)0x0; puVar5 = (undefined4 *)*puVar5) {

    uVar4 = 0;

    if (puVar5[10] != 0) {

      puVar2 = puVar5 + 0xb;

      do {

        (**(code **)(DAT_00656420 + 0xb4))(DAT_00656420,puVar2);

        uVar4 = uVar4 + 1;

        puVar2 = puVar2 + 9;

      } while (uVar4 < (uint)puVar5[10]);

    }

  }

  for (; DAT_005a8844 = puVar2, puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {

    (**(code **)(DAT_00656420 + 0xb4))(DAT_00656420,puVar1 + 1);

    puVar2 = DAT_005a8844;

  }

  puVar5 = puVar2;

  puVar1 = DAT_005a8848;

  if (puVar2 != (undefined4 *)0x0) {

    do {

      uVar4 = 0;

      if (puVar5[10] != 0) {

        pbVar3 = (byte *)((int)puVar5 + 0x4a);

        do {

          if ((*(int *)(pbVar3 + -0x1a) != 0) && ((~*pbVar3 & 1) == 0)) {

            mem_free_tagged(*(int *)(pbVar3 + -0x1a),s_C__Giants_source_main_texture_c_0057bd0c,

                            0x243);

            *pbVar3 = *pbVar3 & 0xfe;

            pbVar3[-0xffffffff0000001a] = 0;

            pbVar3[-0xffffffff00000019] = 0;

            pbVar3[-0xffffffff00000018] = 0;

            pbVar3[-0xffffffff00000017] = 0;

          }

          uVar4 = uVar4 + 1;

          pbVar3 = pbVar3 + 0x24;

          puVar2 = DAT_005a8844;

        } while (uVar4 < (uint)puVar5[10]);

      }

      puVar5 = (undefined4 *)*puVar5;

    } while (puVar5 != (undefined4 *)0x0);

    while (puVar1 = DAT_005a8848, puVar2 != (undefined4 *)0x0) {

      puVar5 = (undefined4 *)*puVar2;

      mem_free_tagged(puVar2,s_C__Giants_source_main_texture_c_0057bd0c,0x26a);

      puVar2 = puVar5;

    }

  }

  while (puVar1 != (undefined4 *)0x0) {

    puVar5 = (undefined4 *)*puVar1;

    mem_free_tagged(puVar1,s_C__Giants_source_main_texture_c_0057bd0c,0x26f);

    puVar1 = puVar5;

  }

  DAT_005a8844 = (undefined4 *)0x0;

  DAT_005a884c = 0;

  DAT_005a8848 = (undefined4 *)0x0;

  return;

}

/* ===== FUN_00507fa0 @ 0x00507FA0 ===== */
void FUN_00507fa0(void)



{

  undefined4 *puVar1;

  undefined4 *puVar2;

  byte *pbVar3;

  uint uVar4;

  

  for (puVar1 = DAT_005a8844; puVar2 = DAT_005a8848, puVar1 != (undefined4 *)0x0;

      puVar1 = (undefined4 *)*puVar1) {

    uVar4 = 0;

    if (puVar1[10] != 0) {

      puVar2 = puVar1 + 0xb;

      do {

        (**(code **)(DAT_00656420 + 0xb4))(DAT_00656420,puVar2);

        uVar4 = uVar4 + 1;

        puVar2 = puVar2 + 9;

      } while (uVar4 < (uint)puVar1[10]);

    }

  }

  for (; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {

    (**(code **)(DAT_00656420 + 0xb4))(DAT_00656420,puVar2 + 1);

  }

  if ((DAT_005a884c != (undefined4 *)0x0) ||

     (DAT_005a884c = DAT_005a8844, DAT_005a8844 != (undefined4 *)0x0)) {

    puVar1 = (undefined4 *)*DAT_005a884c;

    while (puVar1 != (undefined4 *)0x0) {

      *DAT_005a884c = *puVar1;

      uVar4 = 0;

      if (puVar1[10] != 0) {

        pbVar3 = (byte *)((int)puVar1 + 0x4a);

        do {

          if ((*(int *)(pbVar3 + -0x1a) != 0) && ((~*pbVar3 & 1) == 0)) {

            mem_free_tagged(*(int *)(pbVar3 + -0x1a),s_C__Giants_source_main_texture_c_0057bd0c,

                            0x243);

            *pbVar3 = *pbVar3 & 0xfe;

            pbVar3[-0xffffffff0000001a] = 0;

            pbVar3[-0xffffffff00000019] = 0;

            pbVar3[-0xffffffff00000018] = 0;

            pbVar3[-0xffffffff00000017] = 0;

          }

          uVar4 = uVar4 + 1;

          pbVar3 = pbVar3 + 0x24;

        } while (uVar4 < (uint)puVar1[10]);

      }

      mem_free_tagged(puVar1,s_C__Giants_source_main_texture_c_0057bd0c,0x293);

      puVar1 = (undefined4 *)*DAT_005a884c;

    }

  }

  return;

}

/* ===== FUN_005080a0 @ 0x005080A0 ===== */
void FUN_005080a0(int *param_1,int param_2)



{

  ushort *puVar1;

  byte *pbVar2;

  char cVar3;

  byte bVar4;

  ushort uVar5;

  uint uVar6;

  uint uVar7;

  bool bVar8;

  int *piVar9;

  int iVar10;

  int *piVar11;

  undefined4 *puVar12;

  int iVar13;

  int iVar14;

  uint uVar15;

  int *piVar16;

  int *piVar17;

  undefined4 *puVar18;

  uint uVar19;

  char *pcVar20;

  undefined4 *puStack_1d8;

  int *piStack_1d4;

  int iStack_1d0;

  int iStack_1cc;

  undefined4 uStack_1c8;

  undefined1 uStack_1c4;

  undefined2 uStack_1c3;

  byte bStack_1c1;

  uint uStack_1c0;

  undefined2 uStack_1bc;

  undefined2 uStack_1ba;

  char cStack_1b8;

  undefined1 uStack_1b7;

  uint *puStack_1b4;

  uint uStack_1b0;

  int iStack_1ac;

  int aiStack_1a8 [31];

  undefined1 auStack_12c [100];

  undefined1 auStack_c8 [100];

  undefined1 auStack_64 [100];

  

  if (param_1[1] != 0) {

    return;

  }

  piVar9 = DAT_005a8844;

  if (DAT_005a8844 != (int *)0x0) {

LAB_005080c7:

    uVar15 = piVar9[10];

    uVar19 = 0;

    if (uVar15 != 0) {

      piVar16 = piVar9 + 0xb;

      do {

        if (param_1 == piVar16) break;

        uVar19 = uVar19 + 1;

        piVar16 = piVar16 + 9;

      } while (uVar19 < uVar15);

    }

    if (uVar15 <= uVar19) {

      piVar9 = (int *)*piVar9;

      if (piVar9 == (int *)0x0) goto LAB_005080ed;

      goto LAB_005080c7;

    }

    iVar10 = (**(code **)(DAT_00656420 + 0xc0))(DAT_00656420,param_1,0,0);

    if ((iVar10 == 0) && ((~*(byte *)((int)piVar9 + uVar19 * 0x24 + 0x4f) & 4) != 0)) {

      FUN_00542f27(auStack_12c,s__s_dds_0057bed4,*param_1);

      iVar10 = FUN_00538540(auStack_12c);

      if ((iVar10 != 0) && ((DAT_00632e94 & 0x2000) != 0)) {

        FUN_00542f27(auStack_64,s__s_dds_0057bed4,piVar9[uVar19 * 9 + 0xb]);

        vfs_fileread_load(auStack_64,&piStack_1d4,&puStack_1d8);

        if (puStack_1d8 == (undefined4 *)0x0) {

          return;

        }

        if (*piStack_1d4 != 0x20534444) {

          FUN_00542f27(&DAT_00657400,s_Failed_to_open_dds_texture_secti_0057be8c,

                       piVar9[uVar19 * 9 + 0xb]);

          FUN_00540310(&DAT_00657400);

          goto LAB_00508353;

        }

        cVar3 = *(char *)((int)piVar9 + uVar19 * 0x24 + 0x4d);

        piVar17 = piStack_1d4 + 0x20;

        piVar11 = aiStack_1a8;

        piVar16 = piStack_1d4;

        for (iVar10 = 0x1f; piVar16 = piVar16 + 1, iVar10 != 0; iVar10 = iVar10 + -1) {

          *piVar11 = *piVar16;

          piVar11 = piVar11 + 1;

        }

        if (cVar3 == '\0') {

          *(undefined1 *)((int)piVar9 + uVar19 * 0x24 + 0x4d) = 1;

          iVar13 = 0;

          iVar10 = 1;

          do {

            if (aiStack_1a8[3] == iVar10) goto LAB_00508263;

            iVar10 = iVar10 * 2;

            iVar13 = iVar13 + 1;

          } while (iVar10 < 0x1001);

          iVar13 = -1;

LAB_00508263:

          piVar9[uVar19 * 9 + 0xe] = iVar13;

          iVar14 = 0;

          iVar10 = 1;

          do {

            if (aiStack_1a8[2] == iVar10) goto LAB_00508282;

            iVar10 = iVar10 * 2;

            iVar14 = iVar14 + 1;

          } while (iVar10 < 0x1001);

          iVar14 = -1;

LAB_00508282:

          piVar9[uVar19 * 9 + 0xf] = iVar14;

          if ((iVar13 < 0) || (iVar14 < 0)) {

            FUN_00542f27(&DAT_00657400,s_Only_support_power_of_2_sizeed_t_0057bd2c,aiStack_1a8[3],

                         aiStack_1a8[2],piVar9[uVar19 * 9 + 0xb]);

            FUN_0051ea20(&DAT_00657400);

          }

          else {

            *(char *)(piVar9 + uVar19 * 9 + 0x12) = (char)piVar9[uVar19 * 9 + 0x13];

            *(undefined1 *)((int)piVar9 + uVar19 * 0x24 + 0x49) = 0;

            puVar1 = (ushort *)((int)piVar9 + uVar19 * 0x24 + 0x4a);

            *puVar1 = *puVar1 | 8;

            piVar9[uVar19 * 9 + 0x10] = 8;

            piVar9[uVar19 * 9 + 0x11] = 8;

          }

        }

        if (param_2 != 0) {

          puStack_1d8 = puStack_1d8 + -2;

          piVar11 = (int *)FUN_0053a700(0x1d,puStack_1d8,s_dds_texture_raw_0057bec4,

                                        s_C__Giants_source_main_texture_c_0057bd0c,0x15c);

          piVar9[uVar19 * 9 + 0xc] = (int)piVar11;

          piVar16 = aiStack_1a8;

          for (iVar10 = 0x1f; iVar10 != 0; iVar10 = iVar10 + -1) {

            *piVar11 = *piVar16;

            piVar16 = piVar16 + 1;

            piVar11 = piVar11 + 1;

          }

          piVar16 = (int *)(piVar9[uVar19 * 9 + 0xc] + 0x7c);

          for (uVar15 = (uint)(puStack_1d8 + -0x1f) >> 2; uVar15 != 0; uVar15 = uVar15 - 1) {

            *piVar16 = *piVar17;

            piVar17 = piVar17 + 1;

            piVar16 = piVar16 + 1;

          }

          for (uVar15 = (uint)(puStack_1d8 + -0x1f) & 3; uVar15 != 0; uVar15 = uVar15 - 1) {

            *(char *)piVar16 = (char)*piVar17;

            piVar17 = (int *)((int)piVar17 + 1);

            piVar16 = (int *)((int)piVar16 + 1);

          }

          pbVar2 = (byte *)((int)piVar9 + uVar19 * 0x24 + 0x4a);

          *pbVar2 = *pbVar2 | 1;

        }

LAB_00508353:

        FUN_00538560(piStack_1d4);

        return;

      }

    }

    FUN_00542f27(auStack_c8,s__s_tga_0057be84,*param_1);

    vfs_fileread_load(auStack_c8,&puStack_1b4,&iStack_1ac);

    if (iStack_1ac == 0) {

      return;

    }

    uVar15 = *puStack_1b4;

    uVar6 = puStack_1b4[1];

    uStack_1c4 = (undefined1)uVar6;

    uStack_1c3 = (undefined2)(uVar6 >> 8);

    bStack_1c1 = (byte)(uVar6 >> 0x18);

    uStack_1c0 = puStack_1b4[2];

    uVar7 = puStack_1b4[3];

    uVar5 = (ushort)puStack_1b4[4];

    puStack_1d8 = (undefined4 *)((int)puStack_1b4 + 0x12);

    uStack_1c8._2_1_ = (char)(uVar15 >> 0x10);

    cStack_1b8 = (char)uVar5;

    uStack_1b7 = (undefined1)(uVar5 >> 8);

    bVar8 = false;

    uStack_1bc = (undefined2)uVar7;

    uStack_1ba = (undefined2)(uVar7 >> 0x10);

    iStack_1d0 = 0;

    iStack_1cc = 0;

    uStack_1c8 = uVar15;

    if (uStack_1c8._2_1_ == '\x01') {

      bVar8 = true;

    }

    else if (uStack_1c8._2_1_ == '\x02') {

      bVar8 = false;

    }

    else {

      if (uStack_1c8._2_1_ != '\x03') {

        FUN_00542f27(&DAT_00657400,s_Only_support_TRUECOLOR_and_COLOR_0057bd6c,*param_1);

        FUN_0051ea20(&DAT_00657400);

        FUN_0051eaa0();

        return;

      }

      iStack_1d0 = 1;

    }

    uStack_1c8._0_1_ = (char)uVar15;

    if ((char)uStack_1c8 != '\0') {

      puStack_1d8 = (undefined4 *)((int)puStack_1d8 + (uVar15 & 0xff));

    }

    uStack_1c8._1_1_ = (char)(uVar15 >> 8);

    if (uStack_1c8._1_1_ != '\0') {

      if (bStack_1c1 < 0x11) {

        puStack_1d8 = (undefined4 *)((int)puStack_1d8 + (uVar6 >> 8 & 0xffff));

      }

      puStack_1d8 = (undefined4 *)((int)puStack_1d8 + (uVar6 >> 8 & 0xffff) * 2);

    }

    if (bVar8) {

      FUN_00542f27(&DAT_00657400,s_Don_t_support_paletted_textures__0057be54,*param_1);

      FUN_0051ea20(&DAT_00657400);

      FUN_0051eaa0();

      return;

    }

    if (iStack_1d0 == 0) {

      if (cStack_1b8 == '\x18') {

        iStack_1cc = 0;

      }

      else {

        if (cStack_1b8 != ' ') {

          FUN_00542f27(&DAT_00657400,s_Only_support_24bpp_with_8bpp_alp_0057bda4,uVar5 & 0xff,

                       *param_1);

          FUN_0051ea20(&DAT_00657400);

          FUN_0051eaa0();

          return;

        }

        iStack_1cc = 1;

      }

    }

    else if (cStack_1b8 != '\b') {

      FUN_00542f27(&DAT_00657400,s_Only_support_black___white_or_si_0057bdf0,uVar5 & 0xff,*param_1);

      FUN_0051ea20(&DAT_00657400);

      FUN_0051eaa0();

      return;

    }

    uStack_1b0 = CONCAT12(cStack_1b8,uStack_1ba) & 0xffff;

    piStack_1d4 = (int *)(uVar7 & 0xffff);

    if (*(char *)((int)piVar9 + uVar19 * 0x24 + 0x4d) != '\0') goto LAB_00508606;

    *(undefined1 *)((int)piVar9 + uVar19 * 0x24 + 0x4d) = 1;

    iVar10 = 0;

    piVar16 = (int *)0x1;

    goto LAB_00508515;

  }

LAB_005080ed:

  piVar9 = DAT_005a8848;

  if (DAT_005a8848 == (int *)0x0) {

LAB_00508111:

    iVar10 = *param_1;

    pcVar20 = s_Failed_to_open_texture_tga___s___0057bf04;

  }

  else {

    do {

      if (param_1 == piVar9 + 1) {

        if (piVar9 == (int *)0x0) goto LAB_00508111;

        iVar10 = *param_1;

        pcVar20 = s_Failed_to_open_texture_tga___s__0057bee4;

        goto LAB_00508123;

      }

      piVar9 = (int *)*piVar9;

    } while (piVar9 != (int *)0x0);

    iVar10 = *param_1;

    pcVar20 = s_Failed_to_open_texture_tga___s___0057bf04;

  }

LAB_00508123:

  FUN_00542f27(&DAT_00657400,pcVar20,iVar10);

  FUN_0051ea20(&DAT_00657400);

  FUN_00542f27(&DAT_00657400,s_Tex__s_0057bedc,*param_1);

  FUN_00425eb0(&DAT_00657400);

  param_1[1] = 0;

  return;

  while( true ) {

    piVar16 = (int *)((int)piVar16 * 2);

    iVar10 = iVar10 + 1;

    if (0x1000 < (int)piVar16) break;

LAB_00508515:

    if (piStack_1d4 == piVar16) goto LAB_00508527;

  }

  iVar10 = -1;

LAB_00508527:

  piVar9[uVar19 * 9 + 0xe] = iVar10;

  iVar13 = 0;

  uVar15 = 1;

  do {

    if (uStack_1b0 == uVar15) goto LAB_00508549;

    uVar15 = uVar15 * 2;

    iVar13 = iVar13 + 1;

  } while ((int)uVar15 < 0x1001);

  iVar13 = -1;

LAB_00508549:

  piVar9[uVar19 * 9 + 0xf] = iVar13;

  if ((iVar10 < 0) || (iVar13 < 0)) {

    FUN_00542f27(&DAT_00657400,s_Only_support_power_of_2_sizeed_t_0057bd2c,piStack_1d4,uStack_1b0,

                 piVar9[uVar19 * 9 + 0xb]);

    FUN_0051ea20(&DAT_00657400);

  }

  else {

    *(char *)(piVar9 + uVar19 * 9 + 0x12) = (char)piVar9[uVar19 * 9 + 0x13];

    *(undefined1 *)((int)piVar9 + uVar19 * 0x24 + 0x49) = 0;

    *(ushort *)((int)param_1 + 0x1e) = *(ushort *)((int)param_1 + 0x1e) | 4;

    if (iStack_1cc == 0) {

      if (iStack_1d0 == 0) {

        param_1[5] = 2;

        if ((*(byte *)((int)piVar9 + uVar19 * 0x24 + 0x4f) & 1) == 0) {

          param_1[6] = 5;

        }

        else {

          param_1[6] = 2;

          *(ushort *)((int)param_1 + 0x1e) = *(ushort *)((int)param_1 + 0x1e) | 0x2000;

        }

      }

      else {

        param_1[5] = 6;

        param_1[6] = 6;

      }

    }

    else {

      param_1[5] = 0;

      bVar4 = *(byte *)((int)piVar9 + uVar19 * 0x24 + 0x4f);

      if ((bVar4 & 1) == 0) {

        if ((bVar4 & 2) == 0) {

          param_1[6] = 3;

        }

        else {

          param_1[6] = 4;

        }

      }

      else {

        param_1[6] = 0;

        *(ushort *)((int)param_1 + 0x1e) = *(ushort *)((int)param_1 + 0x1e) | 0x2000;

      }

    }

  }

LAB_00508606:

  if (param_2 != 0) {

    uVar19 = ((CONCAT11(uStack_1b7,cStack_1b8) & 0xff) >> 3) * (int)piStack_1d4 * uStack_1b0;

    puVar12 = (undefined4 *)

              FUN_0053a700(0x1d,uVar19,s_texraw_0057bde4,s_C__Giants_source_main_texture_c_0057bd0c,

                           0x234);

    param_1[1] = (int)puVar12;

    puVar18 = puStack_1d8;

    for (uVar15 = uVar19 >> 2; uVar15 != 0; uVar15 = uVar15 - 1) {

      *puVar12 = *puVar18;

      puVar18 = puVar18 + 1;

      puVar12 = puVar12 + 1;

    }

    for (uVar19 = uVar19 & 3; uVar19 != 0; uVar19 = uVar19 - 1) {

      *(undefined1 *)puVar12 = *(undefined1 *)puVar18;

      puVar18 = (undefined4 *)((int)puVar18 + 1);

      puVar12 = (undefined4 *)((int)puVar12 + 1);

    }

    *(byte *)((int)param_1 + 0x1e) = *(byte *)((int)param_1 + 0x1e) | 1;

  }

  FUN_00538560(puStack_1b4);

  return;

}

/* ===== FUN_005086e0 @ 0x005086E0 ===== */
/* PS2 candidate: object_finit_ospec (conf 0.421) */



void FUN_005086e0(int param_1)



{

  if ((*(int *)(param_1 + 4) != 0) && ((~*(byte *)(param_1 + 0x1e) & 1) == 0)) {

    mem_free_tagged(*(int *)(param_1 + 4),s_C__Giants_source_main_texture_c_0057bd0c,0x243);

    *(byte *)(param_1 + 0x1e) = *(byte *)(param_1 + 0x1e) & 0xfe;

    *(undefined4 *)(param_1 + 4) = 0;

  }

  return;

}

/* ===== FUN_00508750 @ 0x00508750 ===== */
/* PS2 candidate: texture_read (conf 0.633) */



undefined4 * FUN_00508750(char *param_1)



{

  char cVar1;

  int iVar2;

  undefined4 *puVar3;

  uint uVar4;

  uint uVar5;

  char *pcVar6;

  undefined4 *puVar7;

  

  for (puVar7 = DAT_005a8844; puVar3 = DAT_005a8848, puVar7 != (undefined4 *)0x0;

      puVar7 = (undefined4 *)*puVar7) {

    uVar5 = 0;

    if (puVar7[10] != 0) {

      puVar3 = puVar7 + 0xb;

      uVar5 = 0;

      do {

        iVar2 = FUN_0053a860(param_1,*puVar3);

        if (iVar2 != 0) break;

        uVar5 = uVar5 + 1;

        puVar3 = puVar3 + 9;

      } while (uVar5 < (uint)puVar7[10]);

    }

    if (uVar5 < (uint)puVar7[10]) {

      return puVar7 + uVar5 * 9 + 0xb;

    }

  }

  for (; puVar3 != (undefined4 *)0x0; puVar3 = (undefined4 *)*puVar3) {

    iVar2 = FUN_0053a860(param_1,puVar3[1]);

    if (iVar2 != 0) {

      return puVar3 + 1;

    }

  }

  uVar5 = 0xffffffff;

  pcVar6 = param_1;

  do {

    if (uVar5 == 0) break;

    uVar5 = uVar5 - 1;

    cVar1 = *pcVar6;

    pcVar6 = pcVar6 + 1;

  } while (cVar1 != '\0');

  uVar4 = ~uVar5 + 0x2b;

  puVar3 = (undefined4 *)

           FUN_0053a700(0x1d,uVar4,&DAT_0057bf38,s_C__Giants_source_main_texture_c_0057bd0c,0x2c6);

  puVar7 = puVar3;

  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {

    *puVar7 = 0;

    puVar7 = puVar7 + 1;

  }

  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {

    *(undefined1 *)puVar7 = 0;

    puVar7 = (undefined4 *)((int)puVar7 + 1);

  }

  *puVar3 = DAT_005a8848;

  DAT_005a8848 = puVar3;

  puVar3[1] = puVar3 + 10;

  iVar2 = (int)(puVar3 + 10) - (int)param_1;

  do {

    cVar1 = *param_1;

    param_1[iVar2] = cVar1;

    param_1 = param_1 + 1;

  } while (cVar1 != '\0');

  *(byte *)((int)puVar3 + 0x23) = *(byte *)((int)puVar3 + 0x23) | 0x10;

  return puVar3 + 1;

}

/* ===== FUN_005088d0 @ 0x005088D0 ===== */
undefined4

FUN_005088d0(undefined4 param_1,uint *param_2,uint *param_3,int *param_4,undefined4 *param_5)



{

  ushort uVar1;

  bool bVar2;

  int iVar3;

  uint uVar4;

  undefined4 *puVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  undefined1 *puVar9;

  undefined4 uVar10;

  uint uVar11;

  uint uVar12;

  int iVar13;

  undefined1 *puVar14;

  int iVar15;

  int iVar16;

  uint uVar17;

  undefined4 *puVar18;

  int iVar19;

  uint uVar20;

  undefined4 *puVar21;

  undefined1 *puVar22;

  int iStack_e8;

  int iStack_e4;

  int iStack_e0;

  int iStack_dc;

  int iStack_d4;

  undefined4 *puStack_cc;

  int iStack_b8;

  uint *puStack_ac;

  int iStack_a8;

  int iStack_a4;

  undefined4 uStack_a0;

  undefined1 uStack_9c;

  undefined2 uStack_9b;

  byte bStack_99;

  uint uStack_98;

  undefined2 uStack_94;

  undefined2 uStack_92;

  char cStack_90;

  undefined1 uStack_8f;

  int iStack_8c;

  int iStack_88;

  int iStack_84;

  int iStack_80;

  int iStack_7c;

  int iStack_78;

  undefined4 *puStack_74;

  int iStack_70;

  int iStack_6c;

  uint uStack_68;

  undefined1 auStack_64 [100];

  

  iStack_e0 = (**(code **)(DAT_00656420 + 0xc4))(DAT_00656420,3);

  iStack_e4 = (**(code **)(DAT_00656420 + 0xc4))(DAT_00656420,4);

  if (0x80 < iStack_e0) {

    iStack_e0 = 0x80;

  }

  if (0x80 < iStack_e4) {

    iStack_e4 = 0x80;

  }

  FUN_00542f27(auStack_64,s__s_tga_0057be84,param_1);

  iVar3 = FUN_00538540(auStack_64);

  if (iVar3 == 0) {

    *param_4 = 0;

    *param_3 = 0;

    *param_2 = 0;

    *param_5 = 0;

    return 0;

  }

  vfs_fileread_load(auStack_64,&puStack_ac,&iStack_6c);

  if (iStack_6c != 0) {

    uVar17 = *puStack_ac;

    uVar11 = puStack_ac[1];

    uStack_9c = (undefined1)uVar11;

    uStack_9b = (undefined2)(uVar11 >> 8);

    bStack_99 = (byte)(uVar11 >> 0x18);

    uStack_98 = puStack_ac[2];

    uVar4 = puStack_ac[3];

    uVar1 = (ushort)puStack_ac[4];

    cStack_90 = (char)uVar1;

    uStack_8f = (undefined1)(uVar1 >> 8);

    puVar18 = (undefined4 *)((int)puStack_ac + 0x12);

    uStack_a0._2_1_ = (char)(uVar17 >> 0x10);

    uStack_94 = (undefined2)uVar4;

    uStack_92 = (undefined2)(uVar4 >> 0x10);

    uStack_a0 = uVar17;

    if (uStack_a0._2_1_ == '\x02') {

      if ((char)uVar17 != '\0') {

        puVar18 = (undefined4 *)((int)puVar18 + (uVar17 & 0xff));

      }

      uStack_a0._1_1_ = (char)(uVar17 >> 8);

      if (uStack_a0._1_1_ != '\0') {

        if (bStack_99 < 0x11) {

          puVar18 = (undefined4 *)((uVar11 >> 8 & 0xffff) * 3 + (int)puVar18);

        }

        else {

          puVar18 = (undefined4 *)((int)puVar18 + (uVar11 >> 8 & 0xffff) * 2);

        }

      }

      if (cStack_90 == '\x18') {

        bVar2 = false;

      }

      else {

        if (cStack_90 != ' ') {

          FUN_00542f27(&DAT_00657400,s_Only_support_24bpp_with_8bpp_alp_0057bda4,uVar1 & 0xff,

                       param_1);

          FUN_0051ea20(&DAT_00657400);

          FUN_0051eaa0();

          return 0;

        }

        bVar2 = true;

      }

      uVar4 = uVar4 & 0xffff;

      uVar17 = CONCAT12(cStack_90,uStack_92) & 0xffff;

      uVar11 = (uVar1 & 0xff) >> 3;

      uVar20 = uVar17 * uVar4 * uVar11;

      uStack_68 = uVar17;

      puVar5 = (undefined4 *)

               FUN_0053a700(0x1d,uVar20,s_bmraw_0057bf5c,s_C__Giants_source_main_texture_c_0057bd0c,

                            0x40a);

      puVar21 = puVar5;

      for (uVar12 = uVar20 >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {

        *puVar21 = *puVar18;

        puVar18 = puVar18 + 1;

        puVar21 = puVar21 + 1;

      }

      for (uVar20 = uVar20 & 3; uVar20 != 0; uVar20 = uVar20 - 1) {

        *(undefined1 *)puVar21 = *(undefined1 *)puVar18;

        puVar18 = (undefined4 *)((int)puVar18 + 1);

        puVar21 = (undefined4 *)((int)puVar21 + 1);

      }

      FUN_00538560(puStack_ac);

      iStack_78 = bVar2 + 3;

      iVar3 = (int)(iStack_e0 + -1 + uVar4) / iStack_e0;

      iVar6 = (int)((uVar17 - 1) + iStack_e4) / iStack_e4;

      iVar7 = uVar4 - (iVar3 + -1) * iStack_e0;

      iVar19 = iVar6 * iVar3;

      iStack_a8 = uVar17 - (iVar6 + -1) * iStack_e4;

      iStack_a4 = iVar6;

      iStack_84 = iVar3;

      iStack_70 = iVar19;

      puStack_cc = (undefined4 *)

                   FUN_0053a700(0x1d,iVar19 * 0x20,s_texlist_0057bf54,

                                s_C__Giants_source_main_texture_c_0057bd0c,0x422);

      iStack_d4 = 0;

      puStack_74 = puStack_cc;

      if (0 < iVar6) {

        iStack_7c = iVar3 << 5;

        iStack_8c = uVar4 * uVar11;

        iStack_88 = -(iStack_8c * iStack_e4);

        iVar8 = (uVar17 - 1) * uVar4 * uVar11;

        do {

          iStack_b8 = 0;

          if (0 < iVar3) {

            iStack_80 = uVar11 * iStack_e0;

            iStack_dc = 0;

            puVar18 = puStack_cc;

            do {

              *puVar18 = param_1;

              puVar18[2] = 0;

              if (iStack_b8 == iVar3 + -1) {

                iVar19 = 2;

                iStack_e8 = iVar7;

                if (2 < iVar7) {

                  do {

                    iVar19 = iVar19 * 2;

                  } while (iVar19 < iVar7);

                }

              }

              else {

                iStack_e8 = iStack_e0;

                iVar19 = iStack_e0;

              }

              iVar6 = iStack_e4;

              iVar16 = iStack_e4;

              if ((iStack_d4 == iStack_a4 + -1) && (iVar6 = 2, iVar16 = iStack_a8, 2 < iStack_a8)) {

                do {

                  iVar6 = iVar6 * 2;

                } while (iVar6 < iStack_a8);

              }

              iVar15 = 0;

              iVar13 = 1;

              do {

                if (iVar19 == iVar13) goto LAB_00508c47;

                iVar13 = iVar13 * 2;

                iVar15 = iVar15 + 1;

              } while (iVar13 < 0x1001);

              iVar15 = -1;

LAB_00508c47:

              puVar18[3] = iVar15;

              iVar15 = 0;

              iVar13 = 1;

              do {

                if (iVar6 == iVar13) goto LAB_00508c6d;

                iVar13 = iVar13 * 2;

                iVar15 = iVar15 + 1;

              } while (iVar13 < 0x1001);

              iVar15 = -1;

LAB_00508c6d:

              puVar18[4] = iVar15;

              puVar9 = (undefined1 *)

                       FUN_0053a700(0x1d,iVar6 * iVar19 * iStack_78,s_screen_tiling_texture_0057bf3c

                                    ,s_C__Giants_source_main_texture_c_0057bd0c,0x446);

              puVar18[1] = puVar9;

              *(undefined2 *)((int)puVar18 + 0x1e) = 1;

              *(undefined1 *)((int)puVar18 + 0x1d) = 0;

              if (bVar2) {

                if (0 < iVar16) {

                  puVar22 = (undefined1 *)((int)puVar5 + iStack_dc + iVar8);

                  do {

                    puVar14 = puVar22;

                    iVar3 = iStack_e8;

                    if (0 < iStack_e8) {

                      do {

                        *puVar9 = *puVar14;

                        puVar9[1] = puVar14[1];

                        puVar9[2] = puVar14[2];

                        puVar9[3] = puVar14[3];

                        puVar9 = puVar9 + 4;

                        iVar3 = iVar3 + -1;

                        puVar14 = puVar14 + 4;

                      } while (iVar3 != 0);

                    }

                    puVar9 = puVar9 + (iVar19 - iStack_e8) * 4;

                    puVar22 = puVar22 + -iStack_8c;

                    iVar16 = iVar16 + -1;

                    iVar3 = iStack_84;

                  } while (iVar16 != 0);

                }

                uVar10 = 0;

              }

              else {

                if (0 < iVar16) {

                  puVar22 = (undefined1 *)((int)puVar5 + iStack_dc + iVar8);

                  do {

                    puVar14 = puVar22;

                    iVar3 = iStack_e8;

                    if (0 < iStack_e8) {

                      do {

                        *puVar9 = *puVar14;

                        puVar9[1] = puVar14[1];

                        puVar9[2] = puVar14[2];

                        puVar9 = puVar9 + 3;

                        iVar3 = iVar3 + -1;

                        puVar14 = puVar14 + 3;

                      } while (iVar3 != 0);

                    }

                    puVar9 = puVar9 + (iVar19 - iStack_e8) * 3;

                    puVar22 = puVar22 + -iStack_8c;

                    iVar16 = iVar16 + -1;

                    iVar3 = iStack_84;

                  } while (iVar16 != 0);

                }

                uVar10 = 2;

              }

              puVar18[5] = uVar10;

              puVar18[6] = uVar10;

              iStack_b8 = iStack_b8 + 1;

              puVar18 = puVar18 + 8;

              iStack_dc = iStack_dc + iStack_80;

              uVar17 = uStack_68;

              iVar19 = iStack_70;

              iVar6 = iStack_a4;

            } while (iStack_b8 < iVar3);

          }

          iStack_d4 = iStack_d4 + 1;

          iVar8 = iVar8 + iStack_88;

          puStack_cc = (undefined4 *)((int)puStack_cc + iStack_7c);

        } while (iStack_d4 < iVar6);

      }

      mem_free_tagged(puVar5,s_C__Giants_source_main_texture_c_0057bd0c,0x497);

      *param_2 = uVar4;

      *param_3 = uVar17;

      *param_4 = iVar19;

      *param_5 = puStack_74;

      return 1;

    }

    FUN_00542f27(&DAT_00657400,s_Only_support_TRUECOLOR_and_COLOR_0057bd6c,param_1);

    FUN_0051ea20(&DAT_00657400);

    FUN_0051eaa0();

  }

  return 0;

}

/* ===== FUN_00508eb0 @ 0x00508EB0 ===== */
void FUN_00508eb0(int param_1,int param_2,undefined4 param_3,int param_4)



{

  int iVar1;

  int iVar2;

  undefined4 *puVar3;

  undefined4 *puVar4;

  

  iVar1 = (**(code **)(DAT_00656420 + 0xc4))(DAT_00656420,3);

  iVar2 = (**(code **)(DAT_00656420 + 0xc4))(DAT_00656420,4);

  if (0x80 < iVar1) {

    iVar1 = 0x80;

  }

  if (0x80 < iVar2) {

    iVar2 = 0x80;

  }

  if (param_4 != 0) {

    iVar1 = (iVar1 + -1 + param_1) / iVar1;

    param_1 = (iVar2 + -1 + param_2) / iVar2;

    if (0 < param_1) {

      puVar3 = (undefined4 *)(param_4 + 4);

      do {

        puVar4 = puVar3;

        iVar2 = iVar1;

        if (0 < iVar1) {

          do {

            (**(code **)(DAT_00656420 + 0xb4))(DAT_00656420,puVar4 + -1);

            mem_free_tagged(*puVar4,s_C__Giants_source_main_texture_c_0057bd0c,0x4bf);

            *puVar4 = 0;

            iVar2 = iVar2 + -1;

            puVar4 = puVar4 + 8;

          } while (iVar2 != 0);

        }

        puVar3 = puVar3 + iVar1 * 8;

        param_1 = param_1 + -1;

      } while (param_1 != 0);

    }

    mem_free_tagged(param_4,s_C__Giants_source_main_texture_c_0057bd0c,0x4c3);

  }

  return;

}

