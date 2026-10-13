/* Giants 1.449 — module main/readwrls
 * 4 functions (4 named) — decompiled, names from PS2 symbols
 * Original source: C:\Giants\source\main/readwrls.c(pp) (assert-string evidence)
 */

/* ===== worldlist_bin_load @ 0x004B0B70 ===== */
void worldlist_bin_load(void)



{

  char cVar1;

  int iVar2;

  undefined4 uVar3;

  int *piVar4;

  uint uVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  int iVar9;

  undefined4 *puVar10;

  char *pcVar11;

  int *local_44;

  undefined4 local_40 [3];

  int local_34 [5];

  char local_20 [4];

  char local_1c [4];

  char local_18 [4];

  char local_14 [20];

  

  iVar9 = 0;

  do {

    if (iVar9 == 0) {

      local_20[0] = s_worldlist_bin_00560300[0];

      local_20[1] = s_worldlist_bin_00560300[1];

      local_20[2] = s_worldlist_bin_00560300[2];

      local_20[3] = s_worldlist_bin_00560300[3];

      local_1c[0] = s_worldlist_bin_00560300[4];

      local_1c[1] = s_worldlist_bin_00560300[5];

      local_1c[2] = s_worldlist_bin_00560300[6];

      local_1c[3] = s_worldlist_bin_00560300[7];

      local_18[0] = s_worldlist_bin_00560300[8];

      local_18[1] = s_worldlist_bin_00560300[9];

      local_18[2] = s_worldlist_bin_00560300[10];

      local_18[3] = s_worldlist_bin_00560300[0xb];

      local_14[0] = s_worldlist_bin_00560300[0xc];

      local_14[1] = s_worldlist_bin_00560300[0xd];

    }

    else {

      crt_sprintf(local_20,s_worldlist_d_bin_005602f0,iVar9 + 1);

    }

    iVar2 = stream_player_start(local_20);

    if (iVar2 == 0) {

      if (iVar9 < 1) {

        error_screen_show(s_Failed_to_open_worldlist_bin_005602d0);

        return;

      }

    }

    else {

      BinFileRead(iVar2,local_34 + iVar9,4);

      if (local_34[iVar9] != 0x1a0003d0) {

        error_screen_show(s_Bad_version_for_worldlist_00560280);

        ANM_BinderDestroy_2(iVar2);

        return;

      }

      BinFileRead(iVar2,local_40,4);

      uVar3 = MemAllocMsg(0x1a,local_40[0],&DAT_005602a8,s_C__Giants_source_main_readwrls_c_005602ac

                          ,0xb5);

      (&DAT_005a6c2c)[iVar9] = uVar3;

      BinFileRead(iVar2,uVar3,local_40[0]);

      ANM_BinderDestroy_2(iVar2);

    }

    iVar9 = iVar9 + 1;

  } while (iVar9 < 5);

  iVar9 = 0;

  DAT_00632d24 = 0;

  piVar4 = &DAT_005a6c2c;

  do {

    if ((int *)*piVar4 != (int *)0x0) {

      iVar9 = iVar9 + *(int *)*piVar4;

      DAT_00632d24 = iVar9;

    }

    piVar4 = piVar4 + 1;

  } while ((int)piVar4 < 0x5a6c40);

  DAT_00632d28 = (undefined4 *)

                 MemAllocMsg(0x1a,iVar9 * 0x50e4,s_worlddata_0056029c,

                             s_C__Giants_source_main_readwrls_c_005602ac,0xc4);

  puVar10 = DAT_00632d28;

  for (uVar5 = (uint)(DAT_00632d24 * 0x50e4) >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {

    *puVar10 = 0;

    puVar10 = puVar10 + 1;

  }

  for (iVar9 = 0; iVar9 != 0; iVar9 = iVar9 + -1) {

    *(undefined1 *)puVar10 = 0;

    puVar10 = (undefined4 *)((int)puVar10 + 1);

  }

  iVar9 = 0;

  local_44 = &DAT_005a6c2c;

  do {

    if ((int *)*local_44 != (int *)0x0) {

      iVar2 = *(int *)*local_44;

      iVar8 = 0;

      if (0 < iVar2) {

        iVar7 = iVar9 * 0x50e4;

        iVar9 = iVar9 + iVar2;

        do {

          DAT_006330e4 = (undefined4 *)((int)DAT_00632d28 + iVar7);

          iVar6 = *(int *)(*local_44 + 4 + iVar8 * 4) + *local_44;

          DAT_006330e4[1] = iVar6;

          uVar5 = 0xffffffff;

          pcVar11 = (char *)DAT_006330e4[1];

          do {

            if (uVar5 == 0) break;

            uVar5 = uVar5 - 1;

            cVar1 = *pcVar11;

            pcVar11 = pcVar11 + 1;

          } while (cVar1 != '\0');

          puVar10 = (undefined4 *)(iVar6 + ~uVar5);

          DAT_006330e4[2] = *puVar10;

          *DAT_006330e4 = puVar10[1];

          iVar7 = iVar7 + 0x50e4;

          iVar8 = iVar8 + 1;

        } while (iVar8 < iVar2);

      }

    }

    local_44 = local_44 + 1;

    if (0x5a6c3f < (int)local_44) {

      return;

    }

  } while( true );

}

/* ===== bin_load_1a0002e5 @ 0x004B0FC0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* PS2 candidate: read_worlds_bin_fn_PS2 (conf 0.453) */



void bin_load_1a0002e5(char *param_1,float param_2,float param_3)



{

  char *pcVar1;

  uint *puVar2;

  char cVar3;

  undefined1 uVar4;

  float *pfVar5;

  int iVar6;

  undefined4 *puVar7;

  undefined4 *puVar8;

  uint uVar9;

  undefined4 uVar10;

  byte bVar11;

  float *pfVar12;

  uint uVar13;

  int iVar14;

  int iVar15;

  int iVar16;

  float fVar17;

  int *piVar18;

  undefined4 *puVar19;

  float *pfVar20;

  float *pfVar21;

  char *pcVar22;

  float *pfVar23;

  undefined4 *puVar24;

  float10 fVar25;

  char *pcVar26;

  char *local_418;

  int local_414;

  float local_410;

  undefined4 *local_40c;

  int local_408;

  int local_404;

  int local_400;

  char *local_3fc [2];

  undefined4 local_3f4;

  undefined4 local_3f0;

  int local_3ec;

  char *local_3e8;

  int local_3e4;

  undefined4 local_3e0;

  int local_3dc;

  char *local_3d8;

  undefined4 local_3d4;

  undefined4 local_3d0;

  undefined4 local_3cc;

  int local_3c8;

  undefined4 local_3c4;

  float local_3c0 [8];

  undefined4 local_3a0;

  undefined4 local_39c;

  undefined4 local_398;

  undefined4 local_394;

  undefined4 local_390;

  uint local_388 [8];

  undefined4 uStack_368;

  float local_364 [96];

  undefined1 local_1e4 [100];

  undefined4 local_180 [2];

  undefined1 auStack_178 [376];

  

  _DAT_005a6c24 = param_2;

  iVar6 = stream_player_start(param_1);

  local_3ec = iVar6;

  if (iVar6 == 0) {

    crt_sprintf(&DAT_00657400,s_Failed_to_open__s_0055c14c,param_1);

    error_screen_show(&DAT_00657400);

    return;

  }

  BinFileRead(iVar6,&local_3e4,4);

  if (local_3e4 != 0x1a0002e5) {

    crt_sprintf(&DAT_00657400,s_Bad_version_for__s___X_vs__X__00560604,param_1,local_3e4,0x1a0002e5)

    ;

    error_screen_show(&DAT_00657400);

    ANM_BinderDestroy_2(iVar6);

    return;

  }

  BinFileRead(iVar6,&local_3a0,0x1c);

  sceSifLoadElf(iVar6,local_398);

  read_sfx_bin(iVar6);

  sceSifLoadElf(iVar6,local_39c);

  main_texture_00507c50(param_1,iVar6,local_3e4);

  sceSifLoadElf(iVar6,local_390);

  BinFileRead(iVar6,&local_3c8,4);

  if (-1 < local_3c8) {

    if (local_3c8 == 0) {

      pcVar26 = &DAT_0055a0f8;

    }

    else if (local_3c8 == 1) {

      pcVar26 = s_fx_world_dust_005605e4;

    }

    else {

      if (local_3c8 != 2) goto LAB_004b10f8;

      pcVar26 = s_fx_world_snow_005605f4;

    }

    main_fx_004470b0(pcVar26);

  }

LAB_004b10f8:

  if (local_388[0] != 0) {

    sceSifLoadElf(iVar6,local_388[0]);

    BinFileRead(iVar6,&local_404,4);

    local_410 = (param_3 - param_2) / (float)local_404;

    local_418 = (char *)0x0;

    if (0 < local_404) {

      do {

        pcVar26 = local_418;

        BinFileRead(iVar6,local_3c0,0x20);

        crt_sprintf(local_364,s__s_bin_00554384,local_3c0);

        pcVar26 = pcVar26 + 1;

        local_3fc[0] = pcVar26;

        bin_load_1a0002e5(local_364,(float)(int)local_418 * local_410 + param_2,

                          (float)(int)pcVar26 * local_410 + param_2);

        local_418 = pcVar26;

      } while ((int)pcVar26 < local_404);

    }

  }

  sceSifLoadElf(iVar6,local_394);

  read_objects_bin_PS2(iVar6,param_1);

  sceSifLoadElf(iVar6,local_3a0);

  BinFileRead(iVar6,&local_3dc,4);

  if (local_3dc == 0) {

    ANM_BinderDestroy_2(iVar6);

    return;

  }

  pcVar26 = (char *)MemAllocMsg(0x18,local_3dc,&DAT_0055fe48,

                                s_C__Giants_source_main_readwrls_c_005602ac,0x1cb);

  local_3fc[0] = pcVar26;

  BinFileRead(iVar6,pcVar26,local_3dc);

  cVar3 = *pcVar26;

  while (cVar3 != '\0') {

    pcVar22 = pcVar26 + 1;

    pcVar26 = pcVar26 + 1;

    cVar3 = *pcVar22;

  }

  local_3e8 = pcVar26 + 1;

  cVar3 = pcVar26[1];

  pcVar26 = local_3e8;

  while (cVar3 != '\0') {

    pcVar22 = pcVar26 + 1;

    pcVar26 = pcVar26 + 1;

    cVar3 = *pcVar22;

  }

  *(undefined4 *)(DAT_006330e4 + 0x7c) = 0x447a0000;

  *(undefined4 *)(DAT_006330e4 + 0x80) = 0x3d000000;

  *(undefined4 *)(DAT_006330e4 + 0x84) = 0x3f000000;

  *(undefined4 *)(DAT_006330e4 + 0x50a0) = 0x80;

  *(undefined4 *)(DAT_006330e4 + 0x508c) = 0;

  *(undefined4 *)(DAT_006330e4 + 0x5090) = 0;

  *(undefined4 *)(DAT_006330e4 + 0x5094) = 0;

  *(undefined4 *)(DAT_006330e4 + 0x5098) = 0;

  *(undefined4 *)(DAT_006330e4 + 0x509c) = 0;

  *(undefined4 *)(DAT_006330e4 + 0x50a8) = 0x457a0000;

  *(undefined4 *)(DAT_006330e4 + 0x50a4) = 0x42000000;

  *(undefined4 *)(DAT_006330e4 + 0x50b0) = 0x3f800000;

  *(undefined4 *)(DAT_006330e4 + 0x50ac) = 0x3f800000;

  *(undefined4 *)(DAT_006330e4 + 0x50b4) = 0x3fc00000;

  *(undefined4 *)(DAT_006330e4 + 0x50b8) = 0;

  *(undefined4 *)(DAT_006330e4 + 0x1c0) = 0x42480000;

  *(float *)(DAT_006330e4 + 0x1c4) = 1.0 / *(float *)(DAT_006330e4 + 0x1c0);

  fVar25 = (float10)fcos((float10)0.8726646304130554);

  *(undefined4 *)(DAT_006330e4 + 0x1c8) = 0xc59c4000;

  *(undefined4 *)(DAT_006330e4 + 0x1cc) = 0xc59c4000;

  *(undefined4 *)(DAT_006330e4 + 0x1d8) = 0xc9;

  *(undefined4 *)(DAT_006330e4 + 0x1dc) = 0xc9;

  *(float *)(DAT_006330e4 + 0x4e98) = (float)fVar25;

  fVar25 = (float10)fcos((float10)1.0471975803375244);

  *(float *)(DAT_006330e4 + 0x4e9c) = (float)fVar25;

  *(undefined4 *)(DAT_006330e4 + 0x4e8c) = 0x3f800000;

  *(undefined4 *)(DAT_006330e4 + 0x4e90) = 0xbdcccccd;

  *(undefined4 *)(DAT_006330e4 + 0x4e94) = 0xbd4ccccd;

  game_state_camera_init();

  local_400 = 0;

  local_408 = 0;

  local_414 = 0;

  local_418 = (char *)0x0;

  local_404 = 0;

  puVar19 = (undefined4 *)0x0;

  local_40c = (undefined4 *)

              MemAllocMsg(0x18,0xc1000,s_sobjs_005605dc,s_C__Giants_source_main_readwrls_c_005602ac,

                          0x1ff);

  fVar17 = (float)0xffffffff;

  pfVar21 = (float *)(pcVar26 + 1);

LAB_004b1410:

  iVar14 = local_400;

  local_410 = (float)(uint)*(byte *)pfVar21;

  pfVar20 = (float *)((int)pfVar21 + 1);

  if (local_410 != 3.57331e-43) {

    pfVar23 = pfVar20;

    iVar6 = local_3ec;

    switch(local_410) {

    case 2.66247e-44:

      bVar11 = *(byte *)pfVar20;

      pfVar21 = (float *)((int)pfVar21 + 2);

      puVar19[0xc] = 1;

      puVar19[4] = (uint)bVar11;

      fVar17 = local_410;

      goto LAB_004b1410;

    case 2.8026e-44:

    case 2.94273e-44:

    case 3.08286e-44:

    case 3.36312e-44:

    case 3.50325e-44:

    case 3.64338e-44:

    case 3.78351e-44:

    case 3.92364e-44:

    case 1.1911e-43:

    case 1.20512e-43:

    case 1.21913e-43:

    case 1.47136e-43:

    case 1.70958e-43:

    case 1.7236e-43:

    case 1.73761e-43:

    case 1.75162e-43:

    case 1.76564e-43:

    case 1.77965e-43:

    case 1.79366e-43:

    case 1.8357e-43:

    default:

      crt_sprintf(&DAT_00657400,s_Unknown_opcode__d__last__d__in_w_0056033c,local_410,fVar17,

                  (int)pfVar20 - (int)local_3fc[0]);

      FUN_0051ea20(&DAT_00657400);

      mem_free_tagged(local_40c,s_C__Giants_source_main_readwrls_c_005602ac,0x6a1);

      return;

    case 3.22299e-44:

      pfVar21 = (float *)((int)pfVar21 + 5);

      puVar19[0x31] = *pfVar20;

      fVar17 = local_410;

      goto LAB_004b1410;

    case 4.06377e-44:

      MemString(0x1a,pfVar20,&local_3cc,s_C__Giants_source_main_readwrls_c_005602ac,0x218);

      pfVar21 = (float *)((int)pfVar21 + 0x11);

      mem_free_tagged(local_3cc,s_C__Giants_source_main_readwrls_c_005602ac,0x219);

      fVar17 = local_410;

      iVar6 = local_3ec;

      goto LAB_004b1410;

    case 4.2039e-44:

      MemString(0x1a,pfVar20,DAT_006330e4 + 0x50,s_C__Giants_source_main_readwrls_c_005602ac,0x20e);

      pfVar21 = (float *)((int)pfVar21 + 0x11);

      uVar10 = main_texture_00508750(*(undefined4 *)(DAT_006330e4 + 0x50));

      *(undefined4 *)(DAT_006330e4 + 0x4c) = uVar10;

      fVar17 = local_410;

      iVar6 = local_3ec;

      goto LAB_004b1410;

    case 4.34403e-44:

      MemString(0x1a,pfVar20,&local_3c4,s_C__Giants_source_main_readwrls_c_005602ac,0x222);

      pfVar21 = (float *)((int)pfVar21 + 0x11);

      mem_free_tagged(local_3c4,s_C__Giants_source_main_readwrls_c_005602ac,0x223);

      fVar17 = local_410;

      iVar6 = local_3ec;

      goto LAB_004b1410;

    case 4.48416e-44:

      MemString(0x1a,pfVar20,DAT_006330e4 + 0x58,s_C__Giants_source_main_readwrls_c_005602ac,0x228);

      pfVar21 = (float *)((int)pfVar21 + 0x11);

      uVar10 = main_texture_00508750(*(undefined4 *)(DAT_006330e4 + 0x58));

      *(undefined4 *)(DAT_006330e4 + 0x54) = uVar10;

      fVar17 = local_410;

      iVar6 = local_3ec;

      goto LAB_004b1410;

    case 4.62428e-44:

      MemString(0x1a,pfVar20,DAT_006330e4 + 0x60,s_C__Giants_source_main_readwrls_c_005602ac,0x22d);

      pfVar21 = (float *)((int)pfVar21 + 0x11);

      uVar10 = main_texture_00508750(*(undefined4 *)(DAT_006330e4 + 0x60));

      *(undefined4 *)(DAT_006330e4 + 0x5c) = uVar10;

      fVar17 = local_410;

      iVar6 = local_3ec;

      goto LAB_004b1410;

    case 4.76441e-44:

      MemString(0x1a,pfVar20,DAT_006330e4 + 0x68,s_C__Giants_source_main_readwrls_c_005602ac,0x232);

      pfVar21 = (float *)((int)pfVar21 + 0x11);

      uVar10 = main_texture_00508750(*(undefined4 *)(DAT_006330e4 + 0x68));

      *(undefined4 *)(DAT_006330e4 + 100) = uVar10;

      fVar17 = local_410;

      iVar6 = local_3ec;

      goto LAB_004b1410;

    case 4.90454e-44:

    case 8.40779e-44:

      fVar17 = local_410;

      pfVar21 = (float *)((int)pfVar21 + 0x11);

      goto LAB_004b1410;

    case 5.04467e-44:

      MemString(0x1a,pfVar20,&local_3d4,s_C__Giants_source_main_readwrls_c_005602ac,0x240);

      pfVar21 = (float *)((int)pfVar21 + 0x11);

      mem_free_tagged(local_3d4,s_C__Giants_source_main_readwrls_c_005602ac,0x241);

      fVar17 = local_410;

      iVar6 = local_3ec;

      goto LAB_004b1410;

    case 5.1848e-44:

      MemString(0x1a,pfVar20,DAT_006330e4 + 0x78,s_C__Giants_source_main_readwrls_c_005602ac,0x246);

      pfVar21 = (float *)((int)pfVar21 + 0x11);

      uVar10 = main_texture_00508750(*(undefined4 *)(DAT_006330e4 + 0x78));

      *(undefined4 *)(DAT_006330e4 + 0x74) = uVar10;

      fVar17 = local_410;

      iVar6 = local_3ec;

      goto LAB_004b1410;

    case 5.32493e-44:

      MemString(0x1a,pfVar20,DAT_006330e4 + 0x70,s_C__Giants_source_main_readwrls_c_005602ac,0x24b);

      pfVar21 = (float *)((int)pfVar21 + 0x11);

      uVar10 = main_texture_00508750(*(undefined4 *)(DAT_006330e4 + 0x70));

      *(undefined4 *)(DAT_006330e4 + 0x6c) = uVar10;

      fVar17 = local_410;

      iVar6 = local_3ec;

      goto LAB_004b1410;

    case 5.46506e-44:

      bVar11 = *(byte *)pfVar20;

      iVar14 = (uint)bVar11 * 0x10;

      *(undefined4 *)(iVar14 + 0x88 + DAT_006330e4) = *(undefined4 *)((int)pfVar21 + 2);

      *(undefined4 *)(iVar14 + 0x8c + DAT_006330e4) = *(undefined4 *)((int)pfVar21 + 6);

      *(undefined4 *)((bVar11 + 9) * 0x10 + DAT_006330e4) = *(undefined4 *)((int)pfVar21 + 10);

      *(undefined4 *)(iVar14 + 0x94 + DAT_006330e4) = *(undefined4 *)((int)pfVar21 + 0xe);

      fVar17 = local_410;

      pfVar21 = (float *)((int)pfVar21 + 0x12);

      goto LAB_004b1410;

    case 5.60519e-44:

      *(float *)(DAT_006330e4 + 0x4f7c) = (float)*(byte *)pfVar20;

      *(float *)(DAT_006330e4 + 0x4f80) = (float)*(byte *)((int)pfVar21 + 2);

      *(float *)(DAT_006330e4 + 0x4f84) = (float)*(byte *)((int)pfVar21 + 3);

      *(float *)(DAT_006330e4 + 0x4f7c) = *(float *)(DAT_006330e4 + 0x4f7c) * 0.003921569;

      *(float *)(DAT_006330e4 + 0x4f80) = *(float *)(DAT_006330e4 + 0x4f80) * 0.003921569;

      *(float *)(DAT_006330e4 + 0x4f84) = *(float *)(DAT_006330e4 + 0x4f84) * 0.003921569;

      fVar17 = local_410;

      pfVar21 = pfVar21 + 1;

      goto LAB_004b1410;

    case 5.74532e-44:

      *(float *)(DAT_006330e4 + 0x128) = *pfVar20;

      *(undefined4 *)(DAT_006330e4 + 300) = *(undefined4 *)((int)pfVar21 + 5);

      *(float *)(DAT_006330e4 + 0x130) = (float)*(byte *)((int)pfVar21 + 9);

      *(float *)(DAT_006330e4 + 0x134) = (float)*(byte *)((int)pfVar21 + 10);

      *(float *)(DAT_006330e4 + 0x138) = (float)*(byte *)((int)pfVar21 + 0xb);

      *(float *)(DAT_006330e4 + 0x130) = *(float *)(DAT_006330e4 + 0x130) * 0.003921569;

      *(float *)(DAT_006330e4 + 0x134) = *(float *)(DAT_006330e4 + 0x134) * 0.003921569;

      *(float *)(DAT_006330e4 + 0x138) = *(float *)(DAT_006330e4 + 0x138) * 0.003921569;

      if (*(float *)(DAT_006330e4 + 0x128) < 0.0) {

        __rt_error_box(s_World_>fogmin_>__0_0f_005605c4,s_C__Giants_source_main_readwrls_c_005602ac,

                       0x288);

      }

      if (*(float *)(DAT_006330e4 + 300) < 0.0) {

        __rt_error_box(s_World_>fogmax_>__0_0f_005605ac,s_C__Giants_source_main_readwrls_c_005602ac,

                       0x289);

      }

      ResetFog__Fv();

      fVar17 = local_410;

      pfVar21 = pfVar21 + 3;

      iVar6 = local_3ec;

      goto LAB_004b1410;

    case 5.88545e-44:

    case 9.80909e-44:

      if ((((puVar19 != (undefined4 *)0x0) &&

           (piVar18 = (int *)puVar19[0x5c], piVar18 != (int *)0x0)) && (*piVar18 == 5)) &&

         ((piVar18[2] != 0 && (piVar18[5] == 0)))) {

        uVar10 = MemAllocMsg(0x18,piVar18[2] * 0xc,s_flakpts_0056056c,

                             s_C__Giants_source_main_readwrls_c_005602ac,0xe4);

        *(undefined4 *)(puVar19[0x5c] + 0x14) = uVar10;

        pfVar23 = local_364;

        pfVar12 = *(float **)(puVar19[0x5c] + 0x14);

        for (uVar13 = *(int *)(puVar19[0x5c] + 8) * 3 & 0x3fffffff; uVar13 != 0; uVar13 = uVar13 - 1

            ) {

          *pfVar12 = *pfVar23;

          pfVar23 = pfVar23 + 1;

          pfVar12 = pfVar12 + 1;

        }

        for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {

          *(undefined1 *)pfVar12 = *(undefined1 *)pfVar23;

          pfVar23 = (float *)((int)pfVar23 + 1);

          pfVar12 = (float *)((int)pfVar12 + 1);

        }

      }

      fVar17 = *pfVar20;

      pfVar23 = (float *)((int)pfVar21 + 5);

      iVar6 = FUN_00497d70(fVar17);

      if (iVar6 == 0) {

        crt_sprintf(&DAT_00657400,s_Can_t_find_object_type__d__OpObj_0056052c,fVar17);

        FUN_00425eb0(&DAT_00657400);

        iVar6 = object_allocate_type(0x406,0);

        if (iVar6 == 0) {

          iVar6 = DAT_00632d54 + 8;

        }

        else {

          *(undefined4 *)(iVar6 + 0xc4) = 0x41200000;

        }

      }

      iVar14 = local_414;

      if (0x3ff < local_414) {

        FUN_0051ea20(s_Too_many_objects_for_world_00560510);

        local_414 = iVar14 + -1;

      }

      puVar19 = local_40c + local_414 * 0xc1;

      puVar8 = puVar19;

      for (iVar14 = 0xc1; iVar14 != 0; iVar14 = iVar14 + -1) {

        *puVar8 = 0;

        puVar8 = puVar8 + 1;

      }

      local_414 = local_414 + 1;

      if ((puVar19 != (undefined4 *)0x0) && (iVar6 != 0)) {

        object_copy_personality(puVar19,iVar6);

        FUN_00497a50(puVar19,iVar6);

        puVar19[0x28] = *pfVar23;

        puVar19[0x29] = *(undefined4 *)((int)pfVar21 + 9);

        puVar19[0x2a] = *(undefined4 *)((int)pfVar21 + 0xd);

        pfVar23 = (float *)((int)pfVar21 + 0x15);

        puVar19[0x32] = *(undefined4 *)((int)pfVar21 + 0x11);

        if (local_410 == 9.80909e-44) {

          puVar19[0x33] = *pfVar23;

          puVar19[0x34] = *(undefined4 *)((int)pfVar21 + 0x19);

          pfVar23 = (float *)((int)pfVar21 + 0x1d);

        }

        puVar19[0x2b] = puVar19[0x28];

        puVar19[0x2c] = puVar19[0x29];

        puVar19[0x2d] = puVar19[0x2a];

        puVar8 = (undefined4 *)(iVar6 + 400);

        puVar7 = puVar19 + 100;

        for (iVar14 = 0x1e; iVar14 != 0; iVar14 = iVar14 + -1) {

          *puVar7 = *puVar8;

          puVar8 = puVar8 + 1;

          puVar7 = puVar7 + 1;

        }

        if (local_404 != 0) {

          puVar19[0x37] = puVar19[0x37] | 0x20000000;

          fVar17 = local_410;

          pfVar21 = pfVar23;

          iVar6 = local_3ec;

          goto LAB_004b1410;

        }

      }

      break;

    case 6.02558e-44:

      puVar19[5] = *pfVar20;

      fVar17 = local_410;

      pfVar21 = (float *)((int)pfVar21 + 5);

      goto LAB_004b1410;

    case 6.16571e-44:

    case 1.56945e-43:

    case 1.58347e-43:

      goto switchD_004b1431_caseD_2c;

    case 6.30584e-44:

      goto switchD_004b1431_caseD_2d;

    case 6.44597e-44:

      *(float *)(DAT_006330e4 + 0x7c) = *pfVar20;

      *(float *)(DAT_006330e4 + 0x80) = 1.0 / *(float *)((int)pfVar21 + 5);

      *(undefined4 *)(DAT_006330e4 + 0x84) = *(undefined4 *)((int)pfVar21 + 9);

      fVar17 = local_410;

      pfVar21 = (float *)((int)pfVar21 + 0xd);

      goto LAB_004b1410;

    case 6.5861e-44:

      fVar17 = local_410;

      pfVar21 = (float *)((int)pfVar21 + 0x1d);

      goto LAB_004b1410;

    case 6.72623e-44:

      bVar11 = *(byte *)pfVar20;

      iVar14 = (uint)bVar11 * 0x10;

      *(undefined4 *)(iVar14 + 0x178 + DAT_006330e4) = *(undefined4 *)((int)pfVar21 + 3);

      *(undefined4 *)(iVar14 + 0x17c + DAT_006330e4) = *(undefined4 *)((int)pfVar21 + 7);

      *(undefined4 *)((bVar11 + 0x18) * 0x10 + DAT_006330e4) = *(undefined4 *)((int)pfVar21 + 0xb);

      *(undefined4 *)(iVar14 + 0x184 + DAT_006330e4) = *(undefined4 *)((int)pfVar21 + 0xf);

      fVar17 = local_410;

      pfVar21 = (float *)((int)pfVar21 + 0x13);

      goto LAB_004b1410;

    case 6.86636e-44:

      fVar17 = local_410;

      pfVar21 = (float *)((int)pfVar21 + 0x29);

      goto LAB_004b1410;

    case 7.00649e-44:

      if (puVar19[0x78] == 0x24) {

        if (puVar19[0x5c] == 0) {

          puVar7 = (undefined4 *)

                   MemAllocMsg(0x18,0x18,&DAT_00560500,s_C__Giants_source_main_readwrls_c_005602ac,

                               0x3ee);

          puVar8 = puVar7;

          for (iVar6 = 6; iVar6 != 0; iVar6 = iVar6 + -1) {

            *puVar8 = 0;

            puVar8 = puVar8 + 1;

          }

          *puVar7 = 5;

          puVar19[0x5c] = puVar7;

          puVar7[3] = 0x3ecccccd;

          puVar7[4] = 0x3f800000;

          puVar7[2] = 0;

        }

        *(uint *)(puVar19[0x5c] + 4) = (uint)*(byte *)pfVar20;

        fVar17 = local_410;

        pfVar21 = (float *)((int)pfVar21 + 3);

        iVar6 = local_3ec;

      }

      else {

        iVar14 = puVar19[0x40];

        *(uint *)(iVar14 + 8) = (uint)*(byte *)pfVar20;

        *(uint *)(iVar14 + 0x28) = (uint)*(byte *)((int)pfVar21 + 2);

        fVar17 = local_410;

        pfVar21 = (float *)((int)pfVar21 + 3);

      }

      goto LAB_004b1410;

    case 7.14662e-44:

      FUN_0051ea20(s_Obsolete_garden_opcode_005604c0);

      fVar17 = local_410;

      pfVar21 = (float *)((int)pfVar21 + 0x25);

      iVar6 = local_3ec;

      goto LAB_004b1410;

    case 7.28675e-44:

      MemString(0x1a,pfVar20,DAT_006330e4 + 0x1e0,s_C__Giants_source_main_readwrls_c_005602ac,0x43c)

      ;

      *(undefined4 *)(DAT_006330e4 + 0x1e4) = *(undefined4 *)((int)pfVar21 + 0x21);

      if (*(float *)(DAT_006330e4 + 0x1e4) == 0.0) {

        *(undefined4 *)(DAT_006330e4 + 0x1e4) = 0x42480000;

      }

      *(float *)(DAT_006330e4 + 0x1e4) = 1.0 / *(float *)(DAT_006330e4 + 0x1e4);

      fVar17 = local_410;

      pfVar21 = (float *)((int)pfVar21 + 0x2d);

      iVar6 = local_3ec;

      goto LAB_004b1410;

    case 7.42688e-44:

      MemString(0x1a,pfVar20,DAT_006330e4 + 0x1e8,s_C__Giants_source_main_readwrls_c_005602ac,0x447)

      ;

      *(undefined4 *)(DAT_006330e4 + 0x1ec) = *(undefined4 *)((int)pfVar21 + 0x21);

      if (*(float *)(DAT_006330e4 + 0x1ec) == 0.0) {

        *(undefined4 *)(DAT_006330e4 + 0x1ec) = 0x42480000;

      }

      *(float *)(DAT_006330e4 + 0x1ec) = 1.0 / *(float *)(DAT_006330e4 + 0x1ec);

      fVar17 = local_410;

      pfVar21 = (float *)((int)pfVar21 + 0x2d);

      iVar6 = local_3ec;

      goto LAB_004b1410;

    case 7.56701e-44:

      MemString(0x1a,pfVar20,DAT_006330e4 + 0x1f0,s_C__Giants_source_main_readwrls_c_005602ac,0x452)

      ;

      *(undefined4 *)(DAT_006330e4 + 500) = *(undefined4 *)((int)pfVar21 + 0x21);

      if (*(float *)(DAT_006330e4 + 500) == 0.0) {

        *(undefined4 *)(DAT_006330e4 + 500) = 0x42480000;

      }

      *(float *)(DAT_006330e4 + 500) = 1.0 / *(float *)(DAT_006330e4 + 500);

      fVar17 = local_410;

      pfVar21 = (float *)((int)pfVar21 + 0x2d);

      iVar6 = local_3ec;

      goto LAB_004b1410;

    case 7.70714e-44:

      FUN_0051ea20(s_Obsolete_mesh_single_opcode_005604a4);

      fVar17 = local_410;

      pfVar21 = (float *)((int)pfVar21 + 0x25);

      iVar6 = local_3ec;

      goto LAB_004b1410;

    case 7.84727e-44:

      FUN_0051ea20(s_Obsolete_mesh_group_opcode_00560488);

      fVar17 = local_410;

      pfVar21 = (float *)((int)pfVar21 + 0x25);

      iVar6 = local_3ec;

      goto LAB_004b1410;

    case 7.9874e-44:

      *(undefined4 *)(DAT_006330e4 + 0x1a8) = *(undefined4 *)((int)pfVar21 + 0xd);

      *(undefined4 *)(DAT_006330e4 + 0x1ac) = *(undefined4 *)((int)pfVar21 + 0x11);

      *(undefined4 *)(DAT_006330e4 + 0x1b0) = *(undefined4 *)((int)pfVar21 + 0x15);

      *(undefined4 *)(DAT_006330e4 + 0x1b4) = *(undefined4 *)((int)pfVar21 + 0x19);

      pfVar23 = (float *)((int)pfVar21 + 0x1d);

      if (*(float *)(DAT_006330e4 + 0x1ac) != 0.0) {

        *(float *)(DAT_006330e4 + 0x1a8) =

             *(float *)(DAT_006330e4 + 0x1a8) * *(float *)(DAT_006330e4 + 0x1a8);

        *(float *)(DAT_006330e4 + 0x1ac) =

             *(float *)(DAT_006330e4 + 0x1ac) * *(float *)(DAT_006330e4 + 0x1ac);

        *(float *)(DAT_006330e4 + 0x1b8) =

             (*(float *)(DAT_006330e4 + 0x1b4) - *(float *)(DAT_006330e4 + 0x1b0)) /

             (*(float *)(DAT_006330e4 + 0x1ac) - *(float *)(DAT_006330e4 + 0x1a8));

        *(float *)(DAT_006330e4 + 0x1bc) =

             *(float *)(DAT_006330e4 + 0x1b0) -

             *(float *)(DAT_006330e4 + 0x1b8) * *(float *)(DAT_006330e4 + 0x1a8);

        fVar17 = local_410;

        pfVar21 = pfVar23;

        goto LAB_004b1410;

      }

      break;

    case 8.12753e-44:

      puVar19[0x37] = puVar19[0x37] | 0x40;

switchD_004b1431_caseD_2d:

      if ((local_418 != (char *)0x0) && (*(int *)(DAT_006330e4 + 0x20c) == 0)) {

        *(char **)(DAT_006330e4 + 0x208) = local_418;

        uVar13 = (int)local_418 * 3;

        uVar10 = MemAllocMsg(0x1a,(int)local_418 * 0xc,s_walist_00560508,

                             s_C__Giants_source_main_readwrls_c_005602ac,0x6d7);

        *(undefined4 *)(DAT_006330e4 + 0x20c) = uVar10;

        puVar8 = local_180;

        puVar7 = *(undefined4 **)(DAT_006330e4 + 0x20c);

        for (uVar13 = uVar13 & 0x3fffffff; uVar13 != 0; uVar13 = uVar13 - 1) {

          *puVar7 = *puVar8;

          puVar8 = puVar8 + 1;

          puVar7 = puVar7 + 1;

        }

        for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {

          *(undefined1 *)puVar7 = *(undefined1 *)puVar8;

          puVar8 = (undefined4 *)((int)puVar8 + 1);

          puVar7 = (undefined4 *)((int)puVar7 + 1);

        }

      }

      uVar10 = FUN_0049bd10(pfVar20);

      puVar19[0x5e] = puVar19[0x28];

      puVar19[0x5f] = puVar19[0x29];

      puVar19[0x60] = puVar19[0x2a];

      if (puVar19[1] != 0x23f) {

        object_change_ospec(puVar19,0x36);

        *(undefined4 *)puVar19[0x40] = uVar10;

        *(undefined4 *)(puVar19[0x40] + 8) = *(undefined4 *)((int)pfVar21 + 0x21);

      }

      puVar19[0x72] = puVar19[0x72] | 0x400000;

      fVar17 = local_410;

      pfVar21 = (float *)((int)pfVar21 + 0x25);

      iVar6 = local_3ec;

      goto LAB_004b1410;

    case 8.26766e-44:

      puVar19[0x3a] = (uint)*(byte *)pfVar20;

      fVar17 = local_410;

      pfVar21 = (float *)((int)pfVar21 + 2);

      goto LAB_004b1410;

    case 8.54792e-44:

    case 9.3887e-44:

      break;

    case 8.68805e-44:

      fVar17 = local_410;

      pfVar21 = (float *)((int)pfVar21 + 0x15);

      goto LAB_004b1410;

    case 8.82818e-44:

      if (puVar19[0x78] != 0x24) goto LAB_004b2ac0;

      *(float *)(puVar19[0x5c] + 0xc) = *pfVar20;

      *(undefined4 *)(puVar19[0x5c] + 0x10) = *(undefined4 *)((int)pfVar21 + 5);

      fVar17 = local_410;

      pfVar21 = (float *)((int)pfVar21 + 9);

      goto LAB_004b1410;

    case 8.96831e-44:

      fVar17 = *pfVar20;

      pfVar23 = (float *)((int)pfVar21 + 5);

      iVar6 = FUN_00497d70(fVar17);

      if (iVar6 == 0) {

        crt_sprintf(&DAT_00657400,s_Can_t_find_object_type__d__OpAre_00560460,fVar17);

        FUN_0051ea20(&DAT_00657400);

        iVar6 = DAT_00632d54 + 8;

      }

      iVar14 = local_414;

      if (0x3ff < local_414) {

        FUN_0051ea20(s_Too_many_objects_for_world_00560510);

        local_414 = iVar14 + -1;

      }

      puVar19 = local_40c + local_414 * 0xc1;

      puVar8 = puVar19;

      for (iVar14 = 0xc1; iVar14 != 0; iVar14 = iVar14 + -1) {

        *puVar8 = 0;

        puVar8 = puVar8 + 1;

      }

      local_414 = local_414 + 1;

      if ((puVar19 != (undefined4 *)0x0) && (iVar6 != 0)) {

        object_copy_personality(puVar19,iVar6);

        object_change_ospec(puVar19,0x16);

        puVar7 = (undefined4 *)

                 MemAllocMsg(0x18,0x28,s_teamripper_00560454,

                             s_C__Giants_source_main_readwrls_c_005602ac,0x4ec);

        puVar8 = puVar7;

        for (iVar6 = 10; iVar6 != 0; iVar6 = iVar6 + -1) {

          *puVar8 = 0;

          puVar8 = puVar8 + 1;

        }

        *puVar7 = 4;

        puVar19[0x5c] = puVar7;

        puVar8 = puVar19 + 0x28;

        puVar7[3] = (float)*(byte *)pfVar23;

        *puVar8 = *(undefined4 *)((int)pfVar21 + 6);

        puVar19[0x29] = *(undefined4 *)((int)pfVar21 + 10);

        puVar19[0x2a] = *(undefined4 *)((int)pfVar21 + 0xe);

        puVar19[0x2b] = *puVar8;

        puVar19[0x2c] = puVar19[0x29];

        puVar19[0x2d] = puVar19[0x2a];

        puVar7[6] = *puVar8;

        puVar7[7] = puVar19[0x29];

        puVar7[8] = puVar19[0x2a];

        puVar7[4] = *(undefined4 *)((int)pfVar21 + 0x12);

        puVar7[5] = *(undefined4 *)((int)pfVar21 + 0x16);

        puVar7[1] = 0x3f400000;

        puVar7[2] = 0x3f800000;

        fVar17 = local_410;

        pfVar21 = (float *)((int)pfVar21 + 0x1a);

        iVar6 = local_3ec;

        goto LAB_004b1410;

      }

      break;

    case 9.10844e-44:

      *(float *)(puVar19[0x5c] + 4) = *pfVar20;

      *(undefined4 *)(puVar19[0x5c] + 8) = *(undefined4 *)((int)pfVar21 + 5);

      fVar17 = local_410;

      pfVar21 = (float *)((int)pfVar21 + 9);

      goto LAB_004b1410;

    case 9.24857e-44:

      fVar17 = *pfVar20;

      pfVar23 = (float *)((int)pfVar21 + 5);

      iVar6 = FUN_00497d70(fVar17);

      if (iVar6 == 0) {

        crt_sprintf(&DAT_00657400,s_Can_t_find_object_type__d__OpSmo_0056042c,fVar17);

        FUN_0051ea20(&DAT_00657400);

        iVar6 = DAT_00632d54 + 8;

      }

      iVar14 = local_414;

      if (0x3ff < local_414) {

        FUN_0051ea20(s_Too_many_objects_for_world_00560510);

        local_414 = iVar14 + -1;

      }

      puVar19 = local_40c + local_414 * 0xc1;

      puVar8 = puVar19;

      for (iVar14 = 0xc1; iVar14 != 0; iVar14 = iVar14 + -1) {

        *puVar8 = 0;

        puVar8 = puVar8 + 1;

      }

      local_414 = local_414 + 1;

      if ((puVar19 != (undefined4 *)0x0) && (iVar6 != 0)) {

        object_copy_personality(puVar19,iVar6);

        object_change_ospec(puVar19,0x18);

        puVar19[0x28] = *pfVar23;

        puVar19[0x29] = *(undefined4 *)((int)pfVar21 + 9);

        puVar19[0x2a] = *(undefined4 *)((int)pfVar21 + 0xd);

        puVar19[0x2b] = puVar19[0x28];

        puVar19[0x2c] = puVar19[0x29];

        puVar19[0x2d] = puVar19[0x2a];

        puVar8 = (undefined4 *)

                 MemAllocMsg(0x18,0x4c,&DAT_00560428,s_C__Giants_source_main_readwrls_c_005602ac,

                             0x51e);

        *puVar8 = *(undefined4 *)((int)pfVar21 + 0x11);

        puVar8[1] = *(undefined4 *)((int)pfVar21 + 0x15);

        puVar8[2] = *(undefined4 *)((int)pfVar21 + 0x19);

        puVar8[3] = *(undefined4 *)((int)pfVar21 + 0x1d);

        puVar8[4] = *(undefined4 *)((int)pfVar21 + 0x21);

        puVar8[5] = *(undefined4 *)((int)pfVar21 + 0x25);

        puVar8[6] = *(undefined4 *)((int)pfVar21 + 0x29);

        puVar8[7] = *(undefined4 *)((int)pfVar21 + 0x2d);

        puVar8[8] = *(undefined4 *)((int)pfVar21 + 0x31);

        puVar8[9] = *(undefined4 *)((int)pfVar21 + 0x35);

        puVar8[10] = *(undefined4 *)((int)pfVar21 + 0x39);

        puVar8[0xb] = *(undefined4 *)((int)pfVar21 + 0x3d);

        puVar8[0xc] = *(undefined4 *)((int)pfVar21 + 0x41);

        puVar8[0xc] = *(undefined4 *)((int)pfVar21 + 0x45);

        puVar8[0xe] = *(undefined4 *)((int)pfVar21 + 0x49);

        puVar8[0xf] = *(undefined4 *)((int)pfVar21 + 0x4d);

        puVar8[0xf] = *(undefined4 *)((int)pfVar21 + 0x51);

        puVar8[0x11] = *(undefined4 *)((int)pfVar21 + 0x55);

        puVar8[0x12] = *(undefined4 *)((int)pfVar21 + 0x59);

        if ((float)puVar8[0x12] < 0.01) {

          puVar8[0x12] = 0x3c23d70a;

        }

        *(undefined4 **)puVar19[0x40] = puVar8;

        puVar19[0x36] = puVar19[0x36] | 0x40000000;

        puVar19[0x38] = puVar19[0x38] | 4;

        fVar17 = local_410;

        pfVar21 = (float *)((int)pfVar21 + 0x5d);

        iVar6 = local_3ec;

        goto LAB_004b1410;

      }

      break;

    case 9.52883e-44:

      local_404 = 1;

      fVar17 = local_410;

      pfVar21 = pfVar20;

      goto LAB_004b1410;

    case 9.66896e-44:

      local_404 = 0;

      fVar17 = local_410;

      pfVar21 = pfVar20;

      goto LAB_004b1410;

    case 9.94922e-44:

      *(float *)(DAT_006330e4 + 0x1c0) = *pfVar20;

      *(undefined4 *)(DAT_006330e4 + 0x1c8) = *(undefined4 *)((int)pfVar21 + 5);

      *(undefined4 *)(DAT_006330e4 + 0x1cc) = *(undefined4 *)((int)pfVar21 + 0xd);

      local_3d0 = *(undefined4 *)((int)pfVar21 + 0x11);

      *(float *)(DAT_006330e4 + 0x1c4) = 1.0 / *(float *)(DAT_006330e4 + 0x1c0);

      iVar6 = DAT_006330e4;

      iVar14 = __ftol();

      *(int *)(iVar6 + 0x1d8) = iVar14 + 1;

      iVar6 = DAT_006330e4;

      iVar14 = __ftol();

      *(int *)(iVar6 + 0x1dc) = iVar14 + 1;

      fVar17 = local_410;

      pfVar21 = (float *)((int)pfVar21 + 0x15);

      iVar6 = local_3ec;

      goto LAB_004b1410;

    case 1.00893e-43:

      if (0x1f < *(int *)(puVar19[0x5c] + 8)) {

        FUN_0051ea20(s_Too_many_points_in_point_list_fo_005604d8);

        *(int *)(puVar19[0x5c] + 8) = *(int *)(puVar19[0x5c] + 8) + -1;

      }

      iVar6 = puVar19[0x5c];

      iVar14 = *(int *)(iVar6 + 8);

      local_364[iVar14 * 3] = *pfVar20;

      local_364[iVar14 * 3 + 1] = *(float *)((int)pfVar21 + 5);

      local_364[iVar14 * 3 + 2] = *(float *)((int)pfVar21 + 9);

      *(int *)(iVar6 + 8) = iVar14 + 1;

      fVar17 = local_410;

      pfVar21 = (float *)((int)pfVar21 + 0xd);

      iVar6 = local_3ec;

      goto LAB_004b1410;

    case 1.02295e-43:

      *(float *)(DAT_006330e4 + 0x1f8) = *pfVar20;

      fVar17 = local_410;

      pfVar21 = (float *)((int)pfVar21 + 5);

      goto LAB_004b1410;

    case 1.03696e-43:

      *(undefined4 *)(DAT_006330e4 + 0x1fc) = 1;

      fVar17 = local_410;

      pfVar21 = pfVar20;

      goto LAB_004b1410;

    case 1.05097e-43:

      if (0 < *(int *)(DAT_006330e4 + 0x208)) {

        FUN_0051ea20(s_WorldAnims_after_references__00560408);

      }

      pcVar26 = local_418;

      if (0x1f < (int)local_418) {

        FUN_0051ea20(s_Too_many_animations_for_a_world_005603e8);

        pcVar26 = pcVar26 + -1;

      }

      MemString(0x1a,pfVar20,local_180 + (int)pcVar26 * 3,

                s_C__Giants_source_main_readwrls_c_005602ac,0x562);

      cVar3 = *(char *)pfVar20;

      while (cVar3 != '\0') {

        pcVar22 = (char *)((int)pfVar20 + 1);

        pfVar20 = (float *)((int)pfVar20 + 1);

        cVar3 = *pcVar22;

      }

      pcVar22 = (char *)((int)pfVar20 + 1);

      crt_sprintf(local_1e4,s__s_anm_005603e0,pcVar22);

      cVar3 = *pcVar22;

      while (cVar3 != '\0') {

        pcVar1 = pcVar22 + 1;

        pcVar22 = pcVar22 + 1;

        cVar3 = *pcVar1;

      }

      pcVar22 = pcVar22 + 1;

      MemString(0x1a,pcVar22,auStack_178 + (int)pcVar26 * 0xc,

                s_C__Giants_source_main_readwrls_c_005602ac,0x566);

      cVar3 = *pcVar22;

      while (cVar3 != '\0') {

        pcVar1 = pcVar22 + 1;

        pcVar22 = pcVar22 + 1;

        cVar3 = *pcVar1;

      }

      uVar10 = main_animate_00405240(local_1e4);

      local_418 = pcVar26 + 1;

      local_180[(int)pcVar26 * 3 + 1] = uVar10;

      fVar17 = local_410;

      pfVar21 = (float *)(pcVar22 + 1);

      iVar6 = local_3ec;

      goto LAB_004b1410;

    case 1.06499e-43:

      if (7 < local_408) {

        FUN_0051ea20(s_Lock_level_nest_too_deep_005603c4);

        local_408 = local_408 + -1;

      }

      uVar13 = ((int)puVar19 - (int)local_40c) / 0x304;

      if (((puVar19 != (undefined4 *)0x0) && (piVar18 = (int *)puVar19[0x5c], piVar18 != (int *)0x0)

          ) && ((*piVar18 == 5 && ((piVar18[2] != 0 && (piVar18[5] == 0)))))) {

        uVar10 = MemAllocMsg(0x18,piVar18[2] * 0xc,s_flakpts_0056056c,

                             s_C__Giants_source_main_readwrls_c_005602ac,0xe4);

        *(undefined4 *)(puVar19[0x5c] + 0x14) = uVar10;

        pfVar23 = local_364;

        pfVar12 = *(float **)(puVar19[0x5c] + 0x14);

        for (uVar9 = *(int *)(puVar19[0x5c] + 8) * 3 & 0x3fffffff; uVar9 != 0; uVar9 = uVar9 - 1) {

          *pfVar12 = *pfVar23;

          pfVar23 = pfVar23 + 1;

          pfVar12 = pfVar12 + 1;

        }

        for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {

          *(undefined1 *)pfVar12 = *(undefined1 *)pfVar23;

          pfVar23 = (float *)((int)pfVar23 + 1);

          pfVar12 = (float *)((int)pfVar12 + 1);

        }

      }

      fVar17 = *pfVar20;

      local_388[local_408 + 1] = uVar13;

      pfVar23 = (float *)((int)pfVar21 + 5);

      iVar6 = FUN_00497d70(fVar17);

      if (iVar6 == 0) {

        crt_sprintf(&DAT_00657400,s_Can_t_find_object_type__d__OpLoc_0056039c,fVar17);

        FUN_0051ea20(&DAT_00657400);

        iVar6 = DAT_00632d54 + 8;

      }

      iVar14 = local_414;

      if (0x3ff < local_414) {

        FUN_0051ea20(s_Too_many_objects_for_world_00560510);

        local_414 = iVar14 + -1;

      }

      puVar19 = local_40c + local_414 * 0xc1;

      puVar8 = puVar19;

      for (iVar14 = 0xc1; iVar14 != 0; iVar14 = iVar14 + -1) {

        *puVar8 = 0;

        puVar8 = puVar8 + 1;

      }

      local_414 = local_414 + 1;

      if ((puVar19 != (undefined4 *)0x0) && (iVar6 != 0)) {

        object_copy_personality(puVar19,iVar6);

        FUN_00497a50(puVar19,iVar6);

        puVar8 = (undefined4 *)(iVar6 + 400);

        puVar7 = puVar19 + 100;

        for (iVar14 = 0x1e; iVar14 != 0; iVar14 = iVar14 + -1) {

          *puVar7 = *puVar8;

          puVar8 = puVar8 + 1;

          puVar7 = puVar7 + 1;

        }

        if (local_404 != 0) {

          puVar19[0x37] = puVar19[0x37] | 0x20000000;

        }

        puVar19[0x84] = uVar13 | 0x80000000;

        local_408 = local_408 + 1;

        puVar19[0x85] = (uint)*(byte *)pfVar23;

        puVar19[0x86] = (uint)*(byte *)((int)pfVar21 + 6);

        fVar17 = local_410;

        pfVar21 = (float *)((int)pfVar21 + 7);

        iVar6 = local_3ec;

        goto LAB_004b1410;

      }

      break;

    case 1.079e-43:

      if (local_408 == 0) {

        FUN_0051ea20(s_Lock_level_underflow_0055c80c);

        fVar17 = local_410;

        pfVar21 = pfVar20;

        iVar6 = local_3ec;

      }

      else {

        if ((((puVar19 != (undefined4 *)0x0) &&

             (piVar18 = (int *)puVar19[0x5c], piVar18 != (int *)0x0)) && (*piVar18 == 5)) &&

           ((piVar18[2] != 0 && (piVar18[5] == 0)))) {

          uVar10 = MemAllocMsg(0x18,piVar18[2] * 0xc,s_flakpts_0056056c,

                               s_C__Giants_source_main_readwrls_c_005602ac,0xe4);

          *(undefined4 *)(puVar19[0x5c] + 0x14) = uVar10;

          pfVar21 = local_364;

          pfVar23 = *(float **)(puVar19[0x5c] + 0x14);

          for (uVar13 = *(int *)(puVar19[0x5c] + 8) * 3 & 0x3fffffff; uVar13 != 0;

              uVar13 = uVar13 - 1) {

            *pfVar23 = *pfVar21;

            pfVar21 = pfVar21 + 1;

            pfVar23 = pfVar23 + 1;

          }

          for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {

            *(undefined1 *)pfVar23 = *(undefined1 *)pfVar21;

            pfVar21 = (float *)((int)pfVar21 + 1);

            pfVar23 = (float *)((int)pfVar23 + 1);

          }

        }

        puVar2 = local_388 + local_408;

        local_408 = local_408 + -1;

        puVar19 = local_40c + *puVar2 * 0xc1;

        fVar17 = local_410;

        pfVar21 = pfVar20;

        iVar6 = local_3ec;

      }

      goto LAB_004b1410;

    case 1.09301e-43:

      iVar14 = 0;

      iVar6 = 0;

      do {

        iVar15 = match(iVar6 + 0x210 + DAT_006330e4,pfVar20);

        if (iVar15 != 0) break;

        iVar6 = iVar6 + 0x20;

        iVar14 = iVar14 + 1;

      } while (iVar6 < 0x1000);

      if (iVar14 == 0x80) {

        crt_sprintf(&DAT_00657400,s_Error__Flick__s_not_in_world_fli_0055c7e4,pfVar20);

        FUN_0051ea20(&DAT_00657400);

        fVar17 = local_410;

        pfVar21 = (float *)((int)pfVar21 + 0x21);

        iVar6 = local_3ec;

      }

      else {

        bVar11 = (byte)iVar14;

        fVar17 = local_410;

        iVar6 = local_3ec;

        if (iVar14 < 0x20) {

          puVar19[0xba] = puVar19[0xba] | 1 << (bVar11 & 0x1f);

          pfVar21 = (float *)((int)pfVar21 + 0x21);

        }

        else if (iVar14 < 0x40) {

          puVar19[0xbb] = puVar19[0xbb] | 1 << (bVar11 - 0x20 & 0x1f);

          pfVar21 = (float *)((int)pfVar21 + 0x21);

        }

        else if (iVar14 < 0x60) {

          puVar19[0xbc] = puVar19[0xbc] | 1 << (bVar11 - 0x40 & 0x1f);

          pfVar21 = (float *)((int)pfVar21 + 0x21);

        }

        else {

          if (iVar14 < 0x80) {

            puVar19[0xbc] = puVar19[0xbc] | 1 << (bVar11 + 0xa0 & 0x1f);

          }

switchD_004b1431_caseD_2c:

          fVar17 = local_410;

          pfVar21 = (float *)((int)pfVar21 + 0x21);

          iVar6 = local_3ec;

        }

      }

      goto LAB_004b1410;

    case 1.10703e-43:

      if (0x7f < local_400) {

        FUN_0051ea20(s_Too_many_flicks_for_world_00560380);

        local_400 = iVar14 + -1;

      }

      pcVar26 = (char *)(local_400 * 0x20 + 0x210 + DAT_006330e4);

      do {

        cVar3 = *(char *)pfVar20;

        pfVar20 = (float *)((int)pfVar20 + 1);

        *pcVar26 = cVar3;

        pcVar26 = pcVar26 + 1;

      } while (cVar3 != '\0');

      pcVar22 = (char *)((int)pfVar21 + 0x21);

      pcVar26 = (char *)(local_400 * 0x20 + 0x1210 + DAT_006330e4);

      do {

        cVar3 = *pcVar22;

        pcVar22 = pcVar22 + 1;

        *pcVar26 = cVar3;

        pcVar26 = pcVar26 + 1;

      } while (cVar3 != '\0');

      local_400 = local_400 + 1;

      fVar17 = local_410;

      pfVar21 = (float *)((int)pfVar21 + 0x41);

      iVar6 = local_3ec;

      goto LAB_004b1410;

    case 1.12104e-43:

      iVar14 = puVar19[0x40];

      bVar11 = *(byte *)pfVar20;

      pfVar23 = (float *)((int)pfVar21 + 2);

      iVar15 = 0;

      pfVar21 = pfVar23;

      if (bVar11 != 0) {

        do {

          fVar17 = *pfVar21;

          pfVar21 = pfVar21 + 1;

          *(float *)(iVar14 + iVar15 * 4) = fVar17;

          iVar15 = iVar15 + 1;

          fVar17 = local_410;

        } while (iVar15 < (int)(uint)bVar11);

        goto LAB_004b1410;

      }

      break;

    case 1.13505e-43:

      puVar19[0x32] = *pfVar20;

      puVar19[0x33] = *(undefined4 *)((int)pfVar21 + 5);

      puVar19[0x34] = *(undefined4 *)((int)pfVar21 + 9);

      pfVar23 = (float *)((int)pfVar21 + 0xd);

      if (puVar19[0x84] != 0) {

        puVar19[0x37] = puVar19[0x37] | 0x8000;

        fVar17 = local_410;

        pfVar21 = pfVar23;

        goto LAB_004b1410;

      }

      break;

    case 1.14906e-43:

      puVar19[0x5d] = *pfVar20;

      fVar17 = local_410;

      pfVar21 = (float *)((int)pfVar21 + 5);

      goto LAB_004b1410;

    case 1.16308e-43:

      *(float *)(puVar19[0x40] + 4) = *pfVar20;

      fVar17 = local_410;

      pfVar21 = (float *)((int)pfVar21 + 5);

      goto LAB_004b1410;

    case 1.17709e-43:

      if ((local_418 != (char *)0x0) && (*(int *)(DAT_006330e4 + 0x20c) == 0)) {

        *(char **)(DAT_006330e4 + 0x208) = local_418;

        uVar13 = (int)local_418 * 3;

        uVar10 = MemAllocMsg(0x1a,(int)local_418 * 0xc,s_walist_00560508,

                             s_C__Giants_source_main_readwrls_c_005602ac,0x6d7);

        *(undefined4 *)(DAT_006330e4 + 0x20c) = uVar10;

        puVar8 = local_180;

        puVar7 = *(undefined4 **)(DAT_006330e4 + 0x20c);

        for (uVar13 = uVar13 & 0x3fffffff; uVar13 != 0; uVar13 = uVar13 - 1) {

          *puVar7 = *puVar8;

          puVar8 = puVar8 + 1;

          puVar7 = puVar7 + 1;

        }

        for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {

          *(undefined1 *)puVar7 = *(undefined1 *)puVar8;

          puVar8 = (undefined4 *)((int)puVar8 + 1);

          puVar7 = (undefined4 *)((int)puVar7 + 1);

        }

      }

      uVar10 = FUN_0049bd10(pfVar20);

      object_change_ospec(puVar19,0x4f);

      *(undefined4 *)puVar19[0x40] = uVar10;

      *(undefined4 *)(puVar19[0x40] + 8) = *(undefined4 *)((int)pfVar21 + 0x21);

      puVar19[0x72] = puVar19[0x72] | 0x400000;

      *(undefined4 *)(puVar19[0x40] + 0x10) = *(undefined4 *)((int)pfVar21 + 0x25);

      *(undefined4 *)(puVar19[0x40] + 0xc) = *(undefined4 *)((int)pfVar21 + 0x29);

      fVar17 = local_410;

      pfVar21 = (float *)((int)pfVar21 + 0x2d);

      iVar6 = local_3ec;

      goto LAB_004b1410;

    case 1.23314e-43:

      *(float *)(DAT_006330e4 + 0x140) = *pfVar20;

      *(undefined4 *)(DAT_006330e4 + 0x144) = *(undefined4 *)((int)pfVar21 + 5);

      *(float *)(DAT_006330e4 + 0x148) = (float)*(byte *)((int)pfVar21 + 9);

      *(float *)(DAT_006330e4 + 0x14c) = (float)*(byte *)((int)pfVar21 + 10);

      *(float *)(DAT_006330e4 + 0x150) = (float)*(byte *)((int)pfVar21 + 0xb);

      *(float *)(DAT_006330e4 + 0x148) = *(float *)(DAT_006330e4 + 0x148) * 0.003921569;

      *(float *)(DAT_006330e4 + 0x14c) = *(float *)(DAT_006330e4 + 0x14c) * 0.003921569;

      *(float *)(DAT_006330e4 + 0x150) = *(float *)(DAT_006330e4 + 0x150) * 0.003921569;

      if (*(float *)(DAT_006330e4 + 0x140) < 0.0) {

        __rt_error_box(s_World_>waterfogmin_>__0_0f_00560590,

                       s_C__Giants_source_main_readwrls_c_005602ac,0x295);

      }

      if (*(float *)(DAT_006330e4 + 0x144) < 0.0) {

        __rt_error_box(s_World_>waterfogmax_>__0_0f_00560574,

                       s_C__Giants_source_main_readwrls_c_005602ac,0x296);

      }

      ResetFog__Fv();

      fVar17 = local_410;

      pfVar21 = pfVar21 + 3;

      iVar6 = local_3ec;

      goto LAB_004b1410;

    case 1.24716e-43:

      pfVar21 = pfVar20;

      do {

        cVar3 = *(char *)pfVar21;

        pfVar21 = (float *)((int)pfVar21 + 1);

      } while (cVar3 != '\0');

      pcVar26 = (char *)(DAT_006330e4 + 0x4530);

      do {

        cVar3 = *(char *)pfVar20;

        pfVar20 = (float *)((int)pfVar20 + 1);

        *pcVar26 = cVar3;

        pcVar26 = pcVar26 + 1;

        fVar17 = local_410;

      } while (cVar3 != '\0');

      goto LAB_004b1410;

    case 1.26117e-43:

      puVar19[0x3d] = *pfVar20;

      puVar19[0x3e] = *(undefined4 *)((int)pfVar21 + 5);

      puVar19[0x3f] = *(undefined4 *)((int)pfVar21 + 9);

      fVar17 = local_410;

      pfVar21 = (float *)((int)pfVar21 + 0xd);

      goto LAB_004b1410;

    case 1.27518e-43:

      iVar14 = puVar19[0x40];

      *(float *)(iVar14 + 0x1c) = *pfVar20;

      *(undefined4 *)(iVar14 + 0x20) = *(undefined4 *)((int)pfVar21 + 5);

      *(undefined4 *)(iVar14 + 0x24) = *(undefined4 *)((int)pfVar21 + 9);

      fVar17 = local_410;

      pfVar21 = (float *)((int)pfVar21 + 0xd);

      goto LAB_004b1410;

    case 1.28919e-43:

      uVar10 = *(undefined4 *)((int)pfVar21 + 2);

      uVar4 = *(undefined1 *)pfVar20;

      MemString(0x1a,(int)pfVar21 + 6,&local_3e0,s_C__Giants_source_main_readwrls_c_005602ac,0x372);

      scenario_list_load(uVar4,uVar10,local_3e0);

      mem_free_tagged(local_3e0,s_C__Giants_source_main_readwrls_c_005602ac,0x375);

      fVar17 = local_410;

      pfVar21 = (float *)((int)pfVar21 + 0x26);

      iVar6 = local_3ec;

      goto LAB_004b1410;

    case 1.30321e-43:

      MemString(0x1a,pfVar20,&local_3d8,s_C__Giants_source_main_readwrls_c_005602ac,0x37d);

      iVar6 = 0;

      pcVar26 = (char *)(DAT_006330e4 + 0x2210);

      do {

        if (*pcVar26 == '\0') {

          if (iVar6 < 0x20) {

            _strncpy((char *)(iVar6 * 0x118 + 0x2210 + DAT_006330e4),local_3d8,0x20);

          }

          break;

        }

        iVar6 = iVar6 + 1;

        pcVar26 = pcVar26 + 0x118;

      } while (iVar6 < 0x20);

      mem_free_tagged(local_3d8,s_C__Giants_source_main_readwrls_c_005602ac,0x386);

      fVar17 = local_410;

      pfVar21 = (float *)((int)pfVar21 + 0x21);

      iVar6 = local_3ec;

      goto LAB_004b1410;

    case 1.31722e-43:

      iVar14 = 0;

      pcVar26 = (char *)(DAT_006330e4 + 0x4a7c);

      do {

        if (*pcVar26 == '\0') {

          _strncpy((char *)(iVar14 * 0x20 + 0x4a7c + DAT_006330e4),(char *)pfVar20,0x20);

          fVar17 = local_410;

          pfVar21 = (float *)((int)pfVar21 + 0x21);

          iVar6 = local_3ec;

          goto LAB_004b1410;

        }

        iVar14 = iVar14 + 1;

        pcVar26 = pcVar26 + 0x20;

      } while (iVar14 < 0x20);

      fVar17 = local_410;

      pfVar21 = (float *)((int)pfVar21 + 0x21);

      goto LAB_004b1410;

    case 1.33123e-43:

      local_3c0[0] = *pfVar20;

      local_3c0[1] = *(float *)((int)pfVar21 + 5);

      local_3c0[2] = *(float *)((int)pfVar21 + 9);

      obj_orient_set(puVar19,local_3c0);

      fVar17 = local_410;

      pfVar21 = (float *)((int)pfVar21 + 0xd);

      iVar6 = local_3ec;

      goto LAB_004b1410;

    case 1.34525e-43:

      *(float *)(DAT_006330e4 + 0x4e88) = *pfVar20;

      pfVar23 = (float *)((int)pfVar21 + 5);

      if (*(int *)(DAT_006330e4 + 0x4e88) != 0) {

        *(undefined4 *)(DAT_006330e4 + 0x4a60) = 0x1b;

        fVar17 = local_410;

        pfVar21 = pfVar23;

        goto LAB_004b1410;

      }

      break;

    case 1.35926e-43:

      iVar14 = puVar19[0x40];

      uVar10 = *(undefined4 *)((int)pfVar21 + 5);

      *(float *)(iVar14 + 0x10) = *pfVar20;

      *(undefined4 *)(iVar14 + 0x14) = uVar10;

      *(undefined4 *)(iVar14 + 0x38) = 1;

      fVar17 = local_410;

      pfVar21 = (float *)((int)pfVar21 + 9);

      goto LAB_004b1410;

    case 1.37327e-43:

      iVar14 = puVar19[0x40];

      uVar10 = *(undefined4 *)((int)pfVar21 + 5);

      *(float *)(iVar14 + 0x10) = *pfVar20;

      *(undefined4 *)(iVar14 + 0x14) = uVar10;

      fVar17 = local_410;

      pfVar21 = (float *)((int)pfVar21 + 9);

      goto LAB_004b1410;

    case 1.38729e-43:

      *(undefined4 *)(puVar19[0x40] + 0x48) = 1;

      fVar17 = local_410;

      pfVar21 = pfVar20;

      goto LAB_004b1410;

    case 1.4013e-43:

      *(undefined4 *)(puVar19[0x40] + 0x4c) = 1;

      fVar17 = local_410;

      pfVar21 = pfVar20;

      goto LAB_004b1410;

    case 1.41531e-43:

      *(float *)(DAT_006330e4 + 0x4e8c) = *pfVar20;

      *(undefined4 *)(DAT_006330e4 + 0x4e90) = *(undefined4 *)((int)pfVar21 + 5);

      *(undefined4 *)(DAT_006330e4 + 0x4e94) = *(undefined4 *)((int)pfVar21 + 9);

      fVar17 = local_410;

      pfVar21 = (float *)((int)pfVar21 + 0xd);

      goto LAB_004b1410;

    case 1.42932e-43:

      fVar25 = (float10)fcos((float10)*pfVar20 * (float10)0.017453292);

      *(float *)(DAT_006330e4 + 0x4e98) = (float)fVar25;

      fVar25 = (float10)fcos((float10)*(float *)((int)pfVar21 + 5) * (float10)0.017453292);

      *(float *)(DAT_006330e4 + 0x4e9c) = (float)fVar25;

      fVar17 = local_410;

      pfVar21 = (float *)((int)pfVar21 + 9);

      goto LAB_004b1410;

    case 1.44334e-43:

      pfVar5 = (float *)puVar19[0x40];

      pfVar12 = pfVar5 + 1;

      pfVar23 = pfVar12;

      for (iVar14 = 0x14; iVar14 != 0; iVar14 = iVar14 + -1) {

        *pfVar23 = -NAN;

        pfVar23 = pfVar23 + 1;

      }

      fVar17 = *pfVar20;

      pfVar23 = (float *)((int)pfVar21 + 5);

      iVar14 = 0;

      *pfVar5 = fVar17;

      if (0 < (int)fVar17) {

        do {

          *pfVar12 = *pfVar23;

          pfVar21 = pfVar23 + 1;

          iVar14 = iVar14 + 1;

          pfVar12 = pfVar12 + 1;

          fVar17 = local_410;

          pfVar23 = pfVar21;

        } while (iVar14 < (int)*pfVar5);

        goto LAB_004b1410;

      }

      break;

    case 1.45735e-43:

      iVar14 = puVar19[0x40];

      pfVar12 = (float *)(iVar14 + 0xa8);

      pfVar23 = pfVar12;

      for (iVar15 = 0x14; iVar15 != 0; iVar15 = iVar15 + -1) {

        *pfVar23 = -NAN;

        pfVar23 = pfVar23 + 1;

      }

      *(float *)(iVar14 + 0xa4) = *pfVar20;

      pfVar23 = (float *)((int)pfVar21 + 5);

      iVar15 = 0;

      if (0 < *(int *)(iVar14 + 0xa4)) {

        do {

          *pfVar12 = *pfVar23;

          pfVar21 = pfVar23 + 1;

          iVar15 = iVar15 + 1;

          pfVar12 = pfVar12 + 1;

          fVar17 = local_410;

          pfVar23 = pfVar21;

        } while (iVar15 < *(int *)(iVar14 + 0xa4));

        goto LAB_004b1410;

      }

      break;

    case 1.48538e-43:

      if (puVar19[0x78] == 0x33) {

        *(uint *)(puVar19[0x40] + 0x60) = (uint)*(byte *)pfVar20;

        fVar17 = local_410;

        pfVar21 = (float *)((int)pfVar21 + 2);

      }

      else {

        if (puVar19[0x78] == 0x61) {

          *(uint *)(puVar19[0x40] + 0xc) = (uint)*(byte *)pfVar20;

        }

        fVar17 = local_410;

        pfVar21 = (float *)((int)pfVar21 + 2);

      }

      goto LAB_004b1410;

    case 1.49939e-43:

      *(float *)(puVar19[0x40] + 0x50) = *pfVar20;

      fVar17 = local_410;

      pfVar21 = (float *)((int)pfVar21 + 5);

      goto LAB_004b1410;

    case 1.5134e-43:

    case 1.52742e-43:

    case 1.54143e-43:

    case 1.55544e-43:

      fVar17 = local_410;

      pfVar21 = (float *)((int)pfVar21 + 0x41);

      goto LAB_004b1410;

    case 1.59748e-43:

      MemString(0x1a,pfVar20,DAT_006330e4 + 0x4f20,s_C__Giants_source_main_readwrls_c_005602ac,0x45d

               );

      *(undefined4 *)(DAT_006330e4 + 0x4f24) = *(undefined4 *)((int)pfVar21 + 0x21);

      if (*(float *)(DAT_006330e4 + 0x4f24) == 0.0) {

        *(undefined4 *)(DAT_006330e4 + 0x4f24) = 0x42480000;

      }

      *(float *)(DAT_006330e4 + 0x4f24) = 1.0 / *(float *)(DAT_006330e4 + 0x4f24);

      fVar17 = local_410;

      pfVar21 = (float *)((int)pfVar21 + 0x2d);

      iVar6 = local_3ec;

      goto LAB_004b1410;

    case 1.61149e-43:

      MemString(0x1a,pfVar20,DAT_006330e4 + 0x4f28,s_C__Giants_source_main_readwrls_c_005602ac,0x468

               );

      *(undefined4 *)(DAT_006330e4 + 0x4f2c) = *(undefined4 *)((int)pfVar21 + 0x21);

      if (*(float *)(DAT_006330e4 + 0x4f2c) == 0.0) {

        *(undefined4 *)(DAT_006330e4 + 0x4f2c) = 0x42480000;

      }

      *(float *)(DAT_006330e4 + 0x4f2c) = 1.0 / *(float *)(DAT_006330e4 + 0x4f2c);

      fVar17 = local_410;

      pfVar21 = (float *)((int)pfVar21 + 0x2d);

      iVar6 = local_3ec;

      goto LAB_004b1410;

    case 1.62551e-43:

      MemString(0x1a,pfVar20,DAT_006330e4 + 0x4f30,s_C__Giants_source_main_readwrls_c_005602ac,0x473

               );

      *(undefined4 *)(DAT_006330e4 + 0x4f34) = *(undefined4 *)((int)pfVar21 + 0x21);

      if (*(float *)(DAT_006330e4 + 0x4f34) == 0.0) {

        *(undefined4 *)(DAT_006330e4 + 0x4f34) = 0x42480000;

      }

      *(float *)(DAT_006330e4 + 0x4f34) = 1.0 / *(float *)(DAT_006330e4 + 0x4f34);

      fVar17 = local_410;

      pfVar21 = (float *)((int)pfVar21 + 0x2d);

      iVar6 = local_3ec;

      goto LAB_004b1410;

    case 1.63952e-43:

      *(float *)(DAT_006330e4 + 0x4f38) = *pfVar20;

      fVar17 = local_410;

      pfVar21 = (float *)((int)pfVar21 + 5);

      goto LAB_004b1410;

    case 1.65353e-43:

      pfVar21 = pfVar20;

      do {

        pfVar23 = pfVar21;

        pfVar21 = (float *)((int)pfVar23 + 1);

      } while (*(char *)pfVar23 != '\0');

      pcVar26 = (char *)(DAT_006330e4 + 0x4f40);

      do {

        cVar3 = *(char *)pfVar20;

        pfVar20 = (float *)((int)pfVar20 + 1);

        *pcVar26 = cVar3;

        pcVar26 = pcVar26 + 1;

      } while (cVar3 != '\0');

      *(float *)(DAT_006330e4 + 0x4f7c) = *(float *)((int)pfVar23 + 1);

      *(undefined4 *)(DAT_006330e4 + 0x4f80) = *(undefined4 *)((int)pfVar23 + 5);

      *(undefined4 *)(DAT_006330e4 + 0x4f84) = *(undefined4 *)((int)pfVar23 + 9);

      *(undefined4 *)(DAT_006330e4 + 0x4f90) = *(undefined4 *)((int)pfVar23 + 0xd);

      *(undefined4 *)(DAT_006330e4 + 0x4f98) = *(undefined4 *)((int)pfVar23 + 0x11);

      fVar17 = local_410;

      pfVar21 = (float *)((int)pfVar23 + 0x15);

      goto LAB_004b1410;

    case 1.66755e-43:

      *(float *)(DAT_006330e4 + 0x4fb8) = *pfVar20;

      *(undefined4 *)(DAT_006330e4 + 0x4fcc) = *(undefined4 *)((int)pfVar21 + 5);

      *(undefined4 *)(DAT_006330e4 + 0x4fd4) = *(undefined4 *)((int)pfVar21 + 9);

      *(undefined4 *)(DAT_006330e4 + 0x4fdc) = *(undefined4 *)((int)pfVar21 + 0xd);

      *(undefined4 *)(DAT_006330e4 + 0x4fe4) = *(undefined4 *)((int)pfVar21 + 0x11);

      *(undefined4 *)(DAT_006330e4 + 0x4fd0) = *(undefined4 *)((int)pfVar21 + 0x15);

      *(undefined4 *)(DAT_006330e4 + 0x4fd8) = *(undefined4 *)((int)pfVar21 + 0x19);

      *(undefined4 *)(DAT_006330e4 + 0x4fe0) = *(undefined4 *)((int)pfVar21 + 0x1d);

      *(undefined4 *)(DAT_006330e4 + 0x4fe8) = *(undefined4 *)((int)pfVar21 + 0x21);

      *(undefined4 *)(DAT_006330e4 + 0x4fec) = *(undefined4 *)((int)pfVar21 + 0x25);

      *(undefined4 *)(DAT_006330e4 + 0x4ff0) = *(undefined4 *)((int)pfVar21 + 0x29);

      *(undefined4 *)(DAT_006330e4 + 0x4ff4) = *(undefined4 *)((int)pfVar21 + 0x2d);

      fVar17 = local_410;

      pfVar21 = (float *)((int)pfVar21 + 0x31);

      goto LAB_004b1410;

    case 1.68156e-43:

      *(float *)(DAT_006330e4 + 0x4ffc) = *pfVar20;

      *(undefined4 *)(DAT_006330e4 + 0x5010) = *(undefined4 *)((int)pfVar21 + 5);

      *(undefined4 *)(DAT_006330e4 + 0x5018) = *(undefined4 *)((int)pfVar21 + 9);

      *(undefined4 *)(DAT_006330e4 + 0x5020) = *(undefined4 *)((int)pfVar21 + 0xd);

      *(undefined4 *)(DAT_006330e4 + 0x5028) = *(undefined4 *)((int)pfVar21 + 0x11);

      *(undefined4 *)(DAT_006330e4 + 0x5014) = *(undefined4 *)((int)pfVar21 + 0x15);

      *(undefined4 *)(DAT_006330e4 + 0x501c) = *(undefined4 *)((int)pfVar21 + 0x19);

      *(undefined4 *)(DAT_006330e4 + 0x5024) = *(undefined4 *)((int)pfVar21 + 0x1d);

      *(undefined4 *)(DAT_006330e4 + 0x502c) = *(undefined4 *)((int)pfVar21 + 0x21);

      *(undefined4 *)(DAT_006330e4 + 0x5030) = *(undefined4 *)((int)pfVar21 + 0x25);

      *(undefined4 *)(DAT_006330e4 + 0x5034) = *(undefined4 *)((int)pfVar21 + 0x29);

      *(undefined4 *)(DAT_006330e4 + 0x5038) = *(undefined4 *)((int)pfVar21 + 0x2d);

      fVar17 = local_410;

      pfVar21 = (float *)((int)pfVar21 + 0x31);

      goto LAB_004b1410;

    case 1.69557e-43:

      local_3f4 = *(undefined4 *)((int)pfVar21 + 5);

      local_3f0 = *(undefined4 *)((int)pfVar21 + 9);

      iVar6 = __ftol();

      uVar13 = __ftol();

      uVar9 = __ftol();

      *(uint *)(DAT_006330e4 + 0x50a0) = (iVar6 << 8 | uVar13) << 8 | uVar9;

      local_3f4 = *(undefined4 *)((int)pfVar21 + 0x11);

      local_3f0 = *(undefined4 *)((int)pfVar21 + 0x15);

      iVar6 = __ftol();

      uVar13 = __ftol();

      uVar9 = __ftol();

      *(uint *)(DAT_006330e4 + 0x508c) = (iVar6 << 8 | uVar13) << 8 | uVar9;

      local_3f4 = *(undefined4 *)((int)pfVar21 + 0x1d);

      local_3f0 = *(undefined4 *)((int)pfVar21 + 0x21);

      iVar6 = __ftol();

      uVar13 = __ftol();

      uVar9 = __ftol();

      *(uint *)(DAT_006330e4 + 0x5090) = (iVar6 << 8 | uVar13) << 8 | uVar9;

      local_3f4 = *(undefined4 *)((int)pfVar21 + 0x29);

      local_3f0 = *(undefined4 *)((int)pfVar21 + 0x2d);

      iVar6 = __ftol();

      uVar13 = __ftol();

      uVar9 = __ftol();

      *(uint *)(DAT_006330e4 + 0x5094) = (iVar6 << 8 | uVar13) << 8 | uVar9;

      local_3f4 = *(undefined4 *)((int)pfVar21 + 0x35);

      local_3f0 = *(undefined4 *)((int)pfVar21 + 0x39);

      iVar6 = __ftol();

      uVar13 = __ftol();

      uVar9 = __ftol();

      *(uint *)(DAT_006330e4 + 0x5098) = (iVar6 << 8 | uVar13) << 8 | uVar9;

      local_3f4 = *(undefined4 *)((int)pfVar21 + 0x41);

      local_3f0 = *(undefined4 *)((int)pfVar21 + 0x45);

      iVar6 = __ftol();

      uVar13 = __ftol();

      uVar9 = __ftol();

      *(uint *)(DAT_006330e4 + 0x509c) = (iVar6 << 8 | uVar13) << 8 | uVar9;

      *(undefined4 *)(DAT_006330e4 + 0x50a4) = *(undefined4 *)((int)pfVar21 + 0x49);

      *(undefined4 *)(DAT_006330e4 + 0x50a8) = *(undefined4 *)((int)pfVar21 + 0x4d);

      *(undefined4 *)(DAT_006330e4 + 0x50ac) = *(undefined4 *)((int)pfVar21 + 0x51);

      *(undefined4 *)(DAT_006330e4 + 0x50b0) = *(undefined4 *)((int)pfVar21 + 0x55);

      *(undefined4 *)(DAT_006330e4 + 0x50b4) = *(undefined4 *)((int)pfVar21 + 0x59);

      *(undefined4 *)(DAT_006330e4 + 0x50b8) = 0;

      fVar17 = local_410;

      pfVar21 = (float *)((int)pfVar21 + 0x5d);

      iVar6 = local_3ec;

      goto LAB_004b1410;

    case 1.80768e-43:

      *(float *)(DAT_006330e4 + 0x4a78) = *pfVar20;

      fVar17 = local_410;

      pfVar21 = (float *)((int)pfVar21 + 5);

      goto LAB_004b1410;

    case 1.82169e-43:

      _strncpy((char *)(DAT_006330e4 + 0x50c0),(char *)pfVar20,0x20);

      fVar17 = local_410;

      pfVar21 = (float *)((int)pfVar21 + 0x21);

      iVar6 = local_3ec;

      goto LAB_004b1410;

    case 1.84971e-43:

      do {

        cVar3 = *(char *)pfVar23;

        pfVar23 = (float *)((int)pfVar23 + 1);

      } while (cVar3 != '\0');

      if (*(int *)(DAT_006330e4 + 0x50e0) != 0) {

        mem_free_tagged(*(int *)(DAT_006330e4 + 0x50e0),s_C__Giants_source_main_readwrls_c_005602ac,

                        0x698);

      }

      uVar13 = 0xffffffff;

      pfVar21 = pfVar20;

      do {

        if (uVar13 == 0) break;

        uVar13 = uVar13 - 1;

        cVar3 = *(char *)pfVar21;

        pfVar21 = (float *)((int)pfVar21 + 1);

      } while (cVar3 != '\0');

      uVar10 = MemAllocMsg(0x1a,~uVar13,s_vopath_00560378,

                           s_C__Giants_source_main_readwrls_c_005602ac,0x699);

      *(undefined4 *)(DAT_006330e4 + 0x50e0) = uVar10;

      pcVar26 = *(char **)(DAT_006330e4 + 0x50e0);

      do {

        cVar3 = *(char *)pfVar20;

        pfVar20 = (float *)((int)pfVar20 + 1);

        *pcVar26 = cVar3;

        pcVar26 = pcVar26 + 1;

      } while (cVar3 != '\0');

      break;

    case 1.86373e-43:

      MemString(0x1a,pfVar20,DAT_006330e4 + 0x4ef0,s_C__Giants_source_main_readwrls_c_005602ac,0x483

               );

      *(undefined4 *)(DAT_006330e4 + 0x4ef4) = *(undefined4 *)((int)pfVar21 + 0x21);

      if (*(float *)(DAT_006330e4 + 0x4ef4) == 0.0) {

        *(undefined4 *)(DAT_006330e4 + 0x4ef4) = 0x42480000;

      }

      *(float *)(DAT_006330e4 + 0x4ef4) = 1.0 / *(float *)(DAT_006330e4 + 0x4ef4);

      fVar17 = local_410;

      pfVar21 = (float *)((int)pfVar21 + 0x2d);

      iVar6 = local_3ec;

      goto LAB_004b1410;

    case 1.87774e-43:

      MemString(0x1a,pfVar20,DAT_006330e4 + 0x4ef8,s_C__Giants_source_main_readwrls_c_005602ac,0x48e

               );

      *(undefined4 *)(DAT_006330e4 + 0x4efc) = *(undefined4 *)((int)pfVar21 + 0x21);

      if (*(float *)(DAT_006330e4 + 0x4efc) == 0.0) {

        *(undefined4 *)(DAT_006330e4 + 0x4efc) = 0x42480000;

      }

      *(float *)(DAT_006330e4 + 0x4efc) = 1.0 / *(float *)(DAT_006330e4 + 0x4efc);

      fVar17 = local_410;

      pfVar21 = (float *)((int)pfVar21 + 0x2d);

      iVar6 = local_3ec;

      goto LAB_004b1410;

    case 1.89175e-43:

      MemString(0x1a,pfVar20,DAT_006330e4 + 0x4f00,s_C__Giants_source_main_readwrls_c_005602ac,0x499

               );

      *(undefined4 *)(DAT_006330e4 + 0x4f04) = *(undefined4 *)((int)pfVar21 + 0x21);

      if (*(float *)(DAT_006330e4 + 0x4f04) == 0.0) {

        *(undefined4 *)(DAT_006330e4 + 0x4f04) = 0x42480000;

      }

      *(float *)(DAT_006330e4 + 0x4f04) = 1.0 / *(float *)(DAT_006330e4 + 0x4f04);

      fVar17 = local_410;

      pfVar21 = (float *)((int)pfVar21 + 0x2d);

      iVar6 = local_3ec;

      goto LAB_004b1410;

    case 1.90577e-43:

      MemString(0x1a,pfVar20,DAT_006330e4 + 0x4f08,s_C__Giants_source_main_readwrls_c_005602ac,0x4a4

               );

      *(undefined4 *)(DAT_006330e4 + 0x4f0c) = *(undefined4 *)((int)pfVar21 + 0x21);

      if (*(float *)(DAT_006330e4 + 0x4f0c) == 0.0) {

        *(undefined4 *)(DAT_006330e4 + 0x4f0c) = 0x42480000;

      }

      *(float *)(DAT_006330e4 + 0x4f0c) = 1.0 / *(float *)(DAT_006330e4 + 0x4f0c);

      fVar17 = local_410;

      pfVar21 = (float *)((int)pfVar21 + 0x2d);

      iVar6 = local_3ec;

      goto LAB_004b1410;

    case 1.91978e-43:

      goto switchD_004b1431_caseD_89;

    case 1.93379e-43:

      MemString(0x1a,pfVar20,DAT_006330e4 + 0x4f18,s_C__Giants_source_main_readwrls_c_005602ac,0x4ba

               );

      *(undefined4 *)(DAT_006330e4 + 0x4f1c) = *(undefined4 *)((int)pfVar21 + 0x21);

      pfVar20 = (float *)((int)pfVar21 + 0x25);

      if (*(float *)(DAT_006330e4 + 0x4f1c) == 0.0) {

        *(undefined4 *)(DAT_006330e4 + 0x4f1c) = 0x42480000;

      }

      *(float *)(DAT_006330e4 + 0x4f1c) = 1.0 / *(float *)(DAT_006330e4 + 0x4f1c);

LAB_004b2ac0:

      fVar17 = local_410;

      pfVar21 = pfVar20 + 2;

      iVar6 = local_3ec;

      goto LAB_004b1410;

    }

    fVar17 = local_410;

    pfVar21 = pfVar23;

    iVar6 = local_3ec;

    goto LAB_004b1410;

  }

  if ((((puVar19 != (undefined4 *)0x0) && (piVar18 = (int *)puVar19[0x5c], piVar18 != (int *)0x0))

      && (*piVar18 == 5)) && ((piVar18[2] != 0 && (piVar18[5] == 0)))) {

    uVar10 = MemAllocMsg(0x18,piVar18[2] * 0xc,s_flakpts_0056056c,

                         s_C__Giants_source_main_readwrls_c_005602ac,0xe4);

    *(undefined4 *)(puVar19[0x5c] + 0x14) = uVar10;

    pfVar21 = local_364;

    pfVar20 = *(float **)(puVar19[0x5c] + 0x14);

    for (uVar13 = *(int *)(puVar19[0x5c] + 8) * 3 & 0x3fffffff; uVar13 != 0; uVar13 = uVar13 - 1) {

      *pfVar20 = *pfVar21;

      pfVar21 = pfVar21 + 1;

      pfVar20 = pfVar20 + 1;

    }

    for (iVar14 = 0; iVar6 = local_3ec, iVar14 != 0; iVar14 = iVar14 + -1) {

      *(undefined1 *)pfVar20 = *(undefined1 *)pfVar21;

      pfVar21 = (float *)((int)pfVar21 + 1);

      pfVar20 = (float *)((int)pfVar20 + 1);

    }

  }

  *(int *)(DAT_006330e4 + 0x170) = local_414;

  if (0 < *(int *)(DAT_006330e4 + 0x170)) {

    uVar10 = MemAllocMsg(0x18,*(int *)(DAT_006330e4 + 0x170) * 0x304,s_stobj_00560334,

                         s_C__Giants_source_main_readwrls_c_005602ac,0x6ad);

    *(undefined4 *)(DAT_006330e4 + 0x174) = uVar10;

    puVar19 = local_40c;

    puVar8 = *(undefined4 **)(DAT_006330e4 + 0x174);

    for (uVar13 = (uint)(*(int *)(DAT_006330e4 + 0x170) * 0x304) >> 2; uVar13 != 0;

        uVar13 = uVar13 - 1) {

      *puVar8 = *puVar19;

      puVar19 = puVar19 + 1;

      puVar8 = puVar8 + 1;

    }

    for (iVar14 = 0; iVar6 = local_3ec, iVar14 != 0; iVar14 = iVar14 + -1) {

      *(undefined1 *)puVar8 = *(undefined1 *)puVar19;

      puVar19 = (undefined4 *)((int)puVar19 + 1);

      puVar8 = (undefined4 *)((int)puVar8 + 1);

    }

  }

  mem_free_tagged(local_40c,s_C__Giants_source_main_readwrls_c_005602ac,0x6b1);

  iVar15 = 0;

  iVar14 = DAT_006330e4;

  do {

    puVar19 = (undefined4 *)(iVar15 + 0x178 + iVar14);

    if (((*(float *)(iVar15 + 0x178 + iVar14) == 0.0) &&

        (*(float *)(iVar15 + 0x17c + iVar14) == 0.0)) &&

       (*(float *)(iVar15 + 0x180 + iVar14) == 0.0)) {

      *puVar19 = *(undefined4 *)(iVar14 + 0x88);

      puVar19[1] = *(undefined4 *)(iVar14 + 0x8c);

      puVar19[2] = *(undefined4 *)(iVar14 + 0x90);

      puVar19[3] = *(undefined4 *)(iVar14 + 0x94);

      iVar14 = DAT_006330e4;

    }

    iVar15 = iVar15 + 0x10;

  } while (iVar15 < 0x30);

  if ((local_418 != (char *)0x0) && (*(int *)(iVar14 + 0x20c) == 0)) {

    uVar13 = (int)local_418 * 3;

    *(char **)(iVar14 + 0x208) = local_418;

    uVar10 = MemAllocMsg(0x1a,(int)local_418 * 0xc,s_walist_00560508,

                         s_C__Giants_source_main_readwrls_c_005602ac,0x6d7);

    *(undefined4 *)(DAT_006330e4 + 0x20c) = uVar10;

    puVar19 = local_180;

    puVar8 = *(undefined4 **)(DAT_006330e4 + 0x20c);

    for (uVar13 = uVar13 & 0x3fffffff; uVar13 != 0; uVar13 = uVar13 - 1) {

      *puVar8 = *puVar19;

      puVar19 = puVar19 + 1;

      puVar8 = puVar8 + 1;

    }

    for (iVar14 = 0; iVar6 = local_3ec, iVar14 != 0; iVar14 = iVar14 + -1) {

      *(undefined1 *)puVar8 = *(undefined1 *)puVar19;

      puVar19 = (undefined4 *)((int)puVar19 + 1);

      puVar8 = (undefined4 *)((int)puVar8 + 1);

    }

  }

  if (*local_3e8 != '\0') {

    gti_terrain_load(local_3e8);

  }

  mem_free_tagged(local_3fc[0],s_C__Giants_source_main_readwrls_c_005602ac,0x6c5);

  ANM_BinderDestroy_2(iVar6);

  iVar6 = (int)local_364 - (int)param_1;

  do {

    cVar3 = *param_1;

    param_1[iVar6] = cVar3;

    param_1 = param_1 + 1;

  } while (cVar3 != '\0');

  uVar13 = 0xffffffff;

  pfVar21 = local_364;

  do {

    if (uVar13 == 0) break;

    uVar13 = uVar13 - 1;

    cVar3 = *(char *)pfVar21;

    pfVar21 = (float *)((int)pfVar21 + 1);

  } while (cVar3 != '\0');

  *(undefined4 *)((int)&uStack_368 + ~uVar13) = DAT_00560330;

  iVar6 = stream_player_start(local_364);

  puVar19 = DAT_00632d50;

  if (iVar6 != 0) {

    BinFileRead(iVar6,&local_3e8,4);

    if (local_3e8 == (char *)0x1a0002dd) {

      while( true ) {

        local_3fc[0] = (char *)0xffffffff;

        BinFileRead(iVar6,local_3fc,4);

        if (local_3fc[0] == (char *)0xffffffff) break;

        iVar14 = objectset_find(local_3fc[0]);

        BinFileRead(iVar6,local_3c0,0x18);

        piVar18 = (int *)(iVar14 + 0x400);

        local_400 = 10;

        do {

          if ((iVar14 != 0) && (*piVar18 != 0)) {

            pfVar21 = local_3c0;

            pfVar20 = (float *)(*piVar18 + 0x44);

            for (iVar15 = 6; iVar15 != 0; iVar15 = iVar15 + -1) {

              *pfVar20 = *pfVar21;

              pfVar21 = pfVar21 + 1;

              pfVar20 = pfVar20 + 1;

            }

          }

          piVar18 = piVar18 + 1;

          local_400 = local_400 + -1;

        } while (local_400 != 0);

        while( true ) {

          local_418 = (char *)0xffffffff;

          BinFileRead(iVar6,&local_418,4);

          if (local_418 == (char *)0xffffffff) break;

          BinFileRead(iVar6,local_3c0,0x18);

          if ((iVar14 != 0) && (iVar15 = *(int *)(iVar14 + 8 + (int)local_418 * 4), iVar15 != 0)) {

            pfVar21 = local_3c0;

            pfVar20 = (float *)(iVar15 + 0xc);

            for (iVar16 = 6; iVar16 != 0; iVar16 = iVar16 + -1) {

              *pfVar20 = *pfVar21;

              pfVar21 = pfVar21 + 1;

              pfVar20 = pfVar20 + 1;

            }

          }

        }

      }

      ANM_BinderDestroy_2(iVar6);

      puVar19 = DAT_00632d50;

    }

    else {

      crt_sprintf(&DAT_00657400,s_Bad_version_for__s_0055c138,local_364);

      FUN_0051ea20(&DAT_00657400);

      ANM_BinderDestroy_2(iVar6);

      puVar19 = DAT_00632d50;

    }

  }

  for (; puVar19 != (undefined4 *)0x0; puVar19 = (undefined4 *)*puVar19) {

    local_400 = 0;

    if (0 < (int)puVar19[1]) {

      puVar8 = puVar19 + 2;

      do {

        iVar6 = puVar8[0x100];

        if (iVar6 != 0) {

          local_418 = (char *)0x0;

          do {

            iVar14 = puVar8[(int)(local_418 + 2)];

            if ((((iVar14 != 0) && (*(float *)(iVar14 + 0xc) == *(float *)(iVar14 + 0x18))) &&

                (*(float *)(iVar14 + 0x10) == *(float *)(iVar14 + 0x1c))) &&

               (*(float *)(iVar14 + 0x14) == *(float *)(iVar14 + 0x20))) {

              puVar7 = (undefined4 *)(iVar6 + 0x44);

              puVar24 = (undefined4 *)(iVar14 + 0xc);

              for (iVar15 = 6; iVar15 != 0; iVar15 = iVar15 + -1) {

                *puVar24 = *puVar7;

                puVar7 = puVar7 + 1;

                puVar24 = puVar24 + 1;

              }

            }

            local_418 = local_418 + 1;

          } while ((int)local_418 < 0xfe);

        }

        local_400 = local_400 + 1;

        puVar8 = puVar8 + 0x119;

      } while (local_400 < (int)puVar19[1]);

    }

  }

  _DAT_005a6c24 = param_3;

  return;

switchD_004b1431_caseD_89:

  MemString(0x1a,pfVar20,DAT_006330e4 + 0x4f10,s_C__Giants_source_main_readwrls_c_005602ac,0x4af);

  *(undefined4 *)(DAT_006330e4 + 0x4f14) = *(undefined4 *)((int)pfVar21 + 0x21);

  if (*(float *)(DAT_006330e4 + 0x4f14) == 0.0) {

    *(undefined4 *)(DAT_006330e4 + 0x4f14) = 0x42480000;

  }

  *(float *)(DAT_006330e4 + 0x4f14) = 1.0 / *(float *)(DAT_006330e4 + 0x4f14);

  fVar17 = local_410;

  pfVar21 = (float *)((int)pfVar21 + 0x2d);

  iVar6 = local_3ec;

  goto LAB_004b1410;

}

/* ===== main_readwrls_004b42d0 @ 0x004B42D0 ===== */
void main_readwrls_004b42d0(void)



{

  int *piVar1;

  

  piVar1 = &DAT_005a6c2c;

  do {

    if (*piVar1 != 0) {

      mem_free_tagged(*piVar1,s_C__Giants_source_main_readwrls_c_005602ac,0x6e3);

      *piVar1 = 0;

    }

    piVar1 = piVar1 + 1;

  } while ((int)piVar1 < 0x5a6c40);

  if (DAT_00632d28 != 0) {

    mem_free_tagged(DAT_00632d28,s_C__Giants_source_main_readwrls_c_005602ac,0x6ea);

    DAT_00632d28 = 0;

  }

  return;

}

/* ===== main_readwrls_004b4330 @ 0x004B4330 ===== */
void main_readwrls_004b4330(void)



{

  if (DAT_006330e4 != 0) {

    mem_free_tagged(*(undefined4 *)(DAT_006330e4 + 0x20c),

                    s_C__Giants_source_main_readwrls_c_005602ac,0x6f2);

    *(undefined4 *)(DAT_006330e4 + 0x20c) = 0;

    *(undefined4 *)(DAT_006330e4 + 0x208) = 0;

    mem_free_tagged(*(undefined4 *)(DAT_006330e4 + 0x70),s_C__Giants_source_main_readwrls_c_005602ac

                    ,0x6f5);

    *(undefined4 *)(DAT_006330e4 + 0x70) = 0;

    mem_free_tagged(*(undefined4 *)(DAT_006330e4 + 0x78),s_C__Giants_source_main_readwrls_c_005602ac

                    ,0x6f6);

    *(undefined4 *)(DAT_006330e4 + 0x78) = 0;

    mem_free_tagged(*(undefined4 *)(DAT_006330e4 + 0x68),s_C__Giants_source_main_readwrls_c_005602ac

                    ,0x6f8);

    *(undefined4 *)(DAT_006330e4 + 0x68) = 0;

    mem_free_tagged(*(undefined4 *)(DAT_006330e4 + 0x60),s_C__Giants_source_main_readwrls_c_005602ac

                    ,0x6f9);

    *(undefined4 *)(DAT_006330e4 + 0x60) = 0;

    mem_free_tagged(*(undefined4 *)(DAT_006330e4 + 0x58),s_C__Giants_source_main_readwrls_c_005602ac

                    ,0x6fa);

    *(undefined4 *)(DAT_006330e4 + 0x58) = 0;

    mem_free_tagged(*(undefined4 *)(DAT_006330e4 + 0x50),s_C__Giants_source_main_readwrls_c_005602ac

                    ,0x6fd);

    *(undefined4 *)(DAT_006330e4 + 0x50) = 0;

    readobjs_load_object();

    main_noise_00495430();

    return;

  }

  return;

}

