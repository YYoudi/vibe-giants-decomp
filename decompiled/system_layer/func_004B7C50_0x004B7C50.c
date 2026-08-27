// GiantsRE system layer - func_004B7C50
// VA 0x004B7C50
// via GhidraMCP headless bulk decompile (project with PS2 renames)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void bin_load_1a0002e5(char *param_1,float param_2,float param_3)

{
  char *pcVar1;
  char cVar2;
  undefined1 uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  uint uVar7;
  undefined4 uVar8;
  byte bVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  float fVar14;
  int *piVar15;
  undefined4 *puVar16;
  float *pfVar17;
  float *pfVar18;
  char *pcVar19;
  float *pfVar20;
  float *pfVar21;
  undefined4 *puVar22;
  float10 fVar23;
  char *pcVar24;
  int local_41c;
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
  int local_388;
  uint auStack_384 [7];
  undefined4 uStack_368;
  float local_364 [96];
  undefined1 local_1e4 [100];
  undefined4 local_180 [2];
  undefined1 auStack_178 [376];
  
  _DAT_005a5c9c = param_2;
  iVar4 = vfs_load_whole_file(param_1);
  local_3ec = iVar4;
  if (iVar4 == 0) {
    FUN_00544b47(&DAT_006552c0,s_Failed_to_open__s_0055e25c,param_1);
    FUN_00523700(&DAT_006552c0);
    return;
  }
  FUN_0051d750(iVar4,&local_3e4,4);
  if (local_3e4 != 0x1a0002e5) {
    FUN_00544b47(&DAT_006552c0,s_Bad_version_for__s___X_vs__X__005634cc,param_1,local_3e4,0x1a0002e5
                );
    FUN_00523700(&DAT_006552c0);
    FUN_0051d850(iVar4);
    return;
  }
  FUN_0051d750(iVar4,&local_3a0,0x1c);
  FUN_0051d7b0(iVar4,local_398);
  FUN_0049a580(iVar4);
  FUN_0051d7b0(iVar4,local_39c);
  FUN_0050d8f0(param_1,iVar4,local_3e4);
  FUN_0051d7b0(iVar4,local_390);
  FUN_0051d750(iVar4,&local_3c8,4);
  if (-1 < local_3c8) {
    if (local_3c8 == 0) {
      pcVar24 = &DAT_0055c214;
    }
    else if (local_3c8 == 1) {
      pcVar24 = s_fx_world_dust_005634ac;
    }
    else {
      if (local_3c8 != 2) goto LAB_004b7d88;
      pcVar24 = s_fx_world_snow_005634bc;
    }
    FUN_0044ab90(pcVar24);
  }
LAB_004b7d88:
  if (local_388 != 0) {
    FUN_0051d7b0(iVar4,local_388);
    FUN_0051d750(iVar4,&local_404,4);
    local_410 = (param_3 - param_2) / (float)local_404;
    local_418 = (char *)0x0;
    if (0 < local_404) {
      do {
        pcVar24 = local_418;
        FUN_0051d750(iVar4,local_3c0,0x20);
        FUN_00544b47(local_364,s__s_bin_00555384,local_3c0);
        pcVar24 = pcVar24 + 1;
        local_3fc[0] = pcVar24;
        bin_load_1a0002e5(local_364,(float)(int)local_418 * local_410 + param_2,
                          (float)(int)pcVar24 * local_410 + param_2);
        local_418 = pcVar24;
      } while ((int)pcVar24 < local_404);
    }
  }
  FUN_0051d7b0(iVar4,local_394);
  FUN_004b50b0(iVar4,param_1);
  FUN_0051d7b0(iVar4,local_3a0);
  FUN_0051d750(iVar4,&local_3dc,4);
  if (local_3dc == 0) {
    FUN_0051d850(iVar4);
    return;
  }
  pcVar24 = (char *)mem_alloc_tagged(0x18,local_3dc,&DAT_00562d10,
                                     s_C__Giants_Source_main_readwrls_c_00563174,0x1c9);
  local_3fc[0] = pcVar24;
  FUN_0051d750(iVar4,pcVar24,local_3dc);
  cVar2 = *pcVar24;
  while (cVar2 != '\0') {
    pcVar19 = pcVar24 + 1;
    pcVar24 = pcVar24 + 1;
    cVar2 = *pcVar19;
  }
  local_3e8 = pcVar24 + 1;
  cVar2 = pcVar24[1];
  pcVar24 = local_3e8;
  while (cVar2 != '\0') {
    pcVar19 = pcVar24 + 1;
    pcVar24 = pcVar24 + 1;
    cVar2 = *pcVar19;
  }
  *(undefined4 *)(DAT_006316ec + 0x7c) = 0x447a0000;
  *(undefined4 *)(DAT_006316ec + 0x80) = 0x3d000000;
  *(undefined4 *)(DAT_006316ec + 0x84) = 0x3f000000;
  *(undefined4 *)(DAT_006316ec + 0x505c) = 0x80;
  *(undefined4 *)(DAT_006316ec + 0x5048) = 0;
  *(undefined4 *)(DAT_006316ec + 0x504c) = 0;
  *(undefined4 *)(DAT_006316ec + 0x5050) = 0;
  *(undefined4 *)(DAT_006316ec + 0x5054) = 0;
  *(undefined4 *)(DAT_006316ec + 0x5058) = 0;
  *(undefined4 *)(DAT_006316ec + 0x5064) = 0x457a0000;
  *(undefined4 *)(DAT_006316ec + 0x5060) = 0x42000000;
  *(undefined4 *)(DAT_006316ec + 0x506c) = 0x3f800000;
  *(undefined4 *)(DAT_006316ec + 0x5068) = 0x3f800000;
  *(undefined4 *)(DAT_006316ec + 0x5070) = 0x3fc00000;
  *(undefined4 *)(DAT_006316ec + 0x5074) = 0;
  *(undefined4 *)(DAT_006316ec + 0x1c4) = 0x42480000;
  *(float *)(DAT_006316ec + 0x1c8) = 1.0 / *(float *)(DAT_006316ec + 0x1c4);
  fVar23 = (float10)fcos((float10)0.8726646304130554);
  *(undefined4 *)(DAT_006316ec + 0x1cc) = 0xc59c4000;
  *(undefined4 *)(DAT_006316ec + 0x1d0) = 0xc59c4000;
  *(undefined4 *)(DAT_006316ec + 0x1dc) = 0xc9;
  *(undefined4 *)(DAT_006316ec + 0x1e0) = 0xc9;
  *(float *)(DAT_006316ec + 0x4e9c) = (float)fVar23;
  fVar23 = (float10)fcos((float10)1.0471975803375244);
  *(float *)(DAT_006316ec + 0x4ea0) = (float)fVar23;
  *(undefined4 *)(DAT_006316ec + 0x4e90) = 0x3f800000;
  *(undefined4 *)(DAT_006316ec + 0x4e94) = 0xbdcccccd;
  *(undefined4 *)(DAT_006316ec + 0x4e98) = 0xbd4ccccd;
  FUN_004b7b30();
  local_400 = 0;
  local_408 = 0;
  local_414 = 0;
  local_418 = (char *)0x0;
  local_404 = 0;
  puVar16 = (undefined4 *)0x0;
  local_40c = (undefined4 *)
              mem_alloc_tagged(0x18,0xc1000,s_sobjs_005634a4,
                               s_C__Giants_Source_main_readwrls_c_00563174,0x1fd);
  fVar14 = (float)0xffffffff;
  pfVar18 = (float *)(pcVar24 + 1);
LAB_004b809d:
  iVar11 = local_400;
  local_410 = (float)(uint)*(byte *)pfVar18;
  pfVar17 = (float *)((int)pfVar18 + 1);
  if (local_410 != 3.57331e-43) {
    pfVar20 = pfVar17;
    iVar4 = local_3ec;
    switch(local_410) {
    case 2.66247e-44:
      pfVar18 = (float *)((int)pfVar18 + 2);
      puVar16[4] = (uint)*(byte *)pfVar17;
      puVar16[0xc] = 1;
      fVar14 = local_410;
      goto LAB_004b809d;
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
      FUN_00544b47(&DAT_006552c0,s_Unknown_opcode__d__last__d__in_w_00563204,local_410,fVar14,
                   (int)pfVar17 - (int)local_3fc[0]);
      FUN_00523aa0(&DAT_006552c0);
      mem_free_tagged(local_40c,s_C__Giants_Source_main_readwrls_c_00563174,0x655);
      return;
    case 3.22299e-44:
      pfVar18 = (float *)((int)pfVar18 + 5);
      puVar16[0x31] = *pfVar17;
      fVar14 = local_410;
      goto LAB_004b809d;
    case 4.06377e-44:
      FUN_0053c890(0x1a,pfVar17,&local_3cc,s_C__Giants_Source_main_readwrls_c_00563174,0x216);
      pfVar18 = (float *)((int)pfVar18 + 0x11);
      mem_free_tagged(local_3cc,s_C__Giants_Source_main_readwrls_c_00563174,0x217);
      fVar14 = local_410;
      iVar4 = local_3ec;
      goto LAB_004b809d;
    case 4.2039e-44:
      FUN_0053c890(0x1a,pfVar17,DAT_006316ec + 0x50,s_C__Giants_Source_main_readwrls_c_00563174,
                   0x20c);
      pfVar18 = (float *)((int)pfVar18 + 0x11);
      uVar8 = FUN_0050e3c0(*(undefined4 *)(DAT_006316ec + 0x50));
      *(undefined4 *)(DAT_006316ec + 0x4c) = uVar8;
      fVar14 = local_410;
      iVar4 = local_3ec;
      goto LAB_004b809d;
    case 4.34403e-44:
      FUN_0053c890(0x1a,pfVar17,&local_3c4,s_C__Giants_Source_main_readwrls_c_00563174,0x220);
      pfVar18 = (float *)((int)pfVar18 + 0x11);
      mem_free_tagged(local_3c4,s_C__Giants_Source_main_readwrls_c_00563174,0x221);
      fVar14 = local_410;
      iVar4 = local_3ec;
      goto LAB_004b809d;
    case 4.48416e-44:
      FUN_0053c890(0x1a,pfVar17,DAT_006316ec + 0x58,s_C__Giants_Source_main_readwrls_c_00563174,
                   0x226);
      pfVar18 = (float *)((int)pfVar18 + 0x11);
      uVar8 = FUN_0050e3c0(*(undefined4 *)(DAT_006316ec + 0x58));
      *(undefined4 *)(DAT_006316ec + 0x54) = uVar8;
      fVar14 = local_410;
      iVar4 = local_3ec;
      goto LAB_004b809d;
    case 4.62428e-44:
      FUN_0053c890(0x1a,pfVar17,DAT_006316ec + 0x60,s_C__Giants_Source_main_readwrls_c_00563174,
                   0x22b);
      pfVar18 = (float *)((int)pfVar18 + 0x11);
      uVar8 = FUN_0050e3c0(*(undefined4 *)(DAT_006316ec + 0x60));
      *(undefined4 *)(DAT_006316ec + 0x5c) = uVar8;
      fVar14 = local_410;
      iVar4 = local_3ec;
      goto LAB_004b809d;
    case 4.76441e-44:
      FUN_0053c890(0x1a,pfVar17,DAT_006316ec + 0x68,s_C__Giants_Source_main_readwrls_c_00563174,
                   0x230);
      pfVar18 = (float *)((int)pfVar18 + 0x11);
      uVar8 = FUN_0050e3c0(*(undefined4 *)(DAT_006316ec + 0x68));
      *(undefined4 *)(DAT_006316ec + 100) = uVar8;
      fVar14 = local_410;
      iVar4 = local_3ec;
      goto LAB_004b809d;
    case 4.90454e-44:
    case 8.40779e-44:
      fVar14 = local_410;
      pfVar18 = (float *)((int)pfVar18 + 0x11);
      goto LAB_004b809d;
    case 5.04467e-44:
      FUN_0053c890(0x1a,pfVar17,&local_3d4,s_C__Giants_Source_main_readwrls_c_00563174,0x23e);
      pfVar18 = (float *)((int)pfVar18 + 0x11);
      mem_free_tagged(local_3d4,s_C__Giants_Source_main_readwrls_c_00563174,0x23f);
      fVar14 = local_410;
      iVar4 = local_3ec;
      goto LAB_004b809d;
    case 5.1848e-44:
      FUN_0053c890(0x1a,pfVar17,DAT_006316ec + 0x78,s_C__Giants_Source_main_readwrls_c_00563174,
                   0x244);
      pfVar18 = (float *)((int)pfVar18 + 0x11);
      uVar8 = FUN_0050e3c0(*(undefined4 *)(DAT_006316ec + 0x78));
      *(undefined4 *)(DAT_006316ec + 0x74) = uVar8;
      fVar14 = local_410;
      iVar4 = local_3ec;
      goto LAB_004b809d;
    case 5.32493e-44:
      FUN_0053c890(0x1a,pfVar17,DAT_006316ec + 0x70,s_C__Giants_Source_main_readwrls_c_00563174,
                   0x249);
      pfVar18 = (float *)((int)pfVar18 + 0x11);
      uVar8 = FUN_0050e3c0(*(undefined4 *)(DAT_006316ec + 0x70));
      *(undefined4 *)(DAT_006316ec + 0x6c) = uVar8;
      fVar14 = local_410;
      iVar4 = local_3ec;
      goto LAB_004b809d;
    case 5.46506e-44:
      bVar9 = *(byte *)pfVar17;
      iVar11 = (uint)bVar9 * 0x10;
      *(undefined4 *)(iVar11 + 0x88 + DAT_006316ec) = *(undefined4 *)((int)pfVar18 + 2);
      *(undefined4 *)(iVar11 + 0x8c + DAT_006316ec) = *(undefined4 *)((int)pfVar18 + 6);
      *(undefined4 *)((bVar9 + 9) * 0x10 + DAT_006316ec) = *(undefined4 *)((int)pfVar18 + 10);
      *(undefined4 *)(iVar11 + 0x94 + DAT_006316ec) = *(undefined4 *)((int)pfVar18 + 0xe);
      fVar14 = local_410;
      pfVar18 = (float *)((int)pfVar18 + 0x12);
      goto LAB_004b809d;
    case 5.60519e-44:
      *(float *)(DAT_006316ec + 0x4f38) = (float)*(byte *)pfVar17;
      *(float *)(DAT_006316ec + 0x4f3c) = (float)*(byte *)((int)pfVar18 + 2);
      *(float *)(DAT_006316ec + 0x4f40) = (float)*(byte *)((int)pfVar18 + 3);
      *(float *)(DAT_006316ec + 0x4f38) = *(float *)(DAT_006316ec + 0x4f38) * 0.003921569;
      *(float *)(DAT_006316ec + 0x4f3c) = *(float *)(DAT_006316ec + 0x4f3c) * 0.003921569;
      *(float *)(DAT_006316ec + 0x4f40) = *(float *)(DAT_006316ec + 0x4f40) * 0.003921569;
      fVar14 = local_410;
      pfVar18 = pfVar18 + 1;
      goto LAB_004b809d;
    case 5.74532e-44:
      *(float *)(DAT_006316ec + 0x128) = *pfVar17;
      *(undefined4 *)(DAT_006316ec + 300) = *(undefined4 *)((int)pfVar18 + 5);
      *(float *)(DAT_006316ec + 0x130) = (float)*(byte *)((int)pfVar18 + 9);
      *(float *)(DAT_006316ec + 0x134) = (float)*(byte *)((int)pfVar18 + 10);
      *(float *)(DAT_006316ec + 0x138) = (float)*(byte *)((int)pfVar18 + 0xb);
      *(float *)(DAT_006316ec + 0x130) = *(float *)(DAT_006316ec + 0x130) * 0.003921569;
      *(float *)(DAT_006316ec + 0x134) = *(float *)(DAT_006316ec + 0x134) * 0.003921569;
      *(float *)(DAT_006316ec + 0x138) = *(float *)(DAT_006316ec + 0x138) * 0.003921569;
      if (*(float *)(DAT_006316ec + 0x128) < 0.0) {
        FUN_00544b99(s_World_>fogmin_>__0_0f_0056348c,s_C__Giants_Source_main_readwrls_c_00563174,
                     0x286);
      }
      if (*(float *)(DAT_006316ec + 300) < 0.0) {
        FUN_00544b99(s_World_>fogmax_>__0_0f_00563474,s_C__Giants_Source_main_readwrls_c_00563174,
                     0x287);
      }
      FUN_0051bd20();
      fVar14 = local_410;
      pfVar18 = pfVar18 + 3;
      iVar4 = local_3ec;
      goto LAB_004b809d;
    case 5.88545e-44:
    case 9.80909e-44:
      if ((((puVar16 != (undefined4 *)0x0) &&
           (piVar15 = (int *)puVar16[0x5c], piVar15 != (int *)0x0)) && (*piVar15 == 5)) &&
         ((piVar15[2] != 0 && (piVar15[5] == 0)))) {
        uVar8 = mem_alloc_tagged(0x18,piVar15[2] * 0xc,s_flakpts_00563434,
                                 s_C__Giants_Source_main_readwrls_c_00563174,0xe2);
        *(undefined4 *)(puVar16[0x5c] + 0x14) = uVar8;
        pfVar20 = local_364;
        pfVar21 = *(float **)(puVar16[0x5c] + 0x14);
        for (uVar10 = *(int *)(puVar16[0x5c] + 8) * 3 & 0x3fffffff; uVar10 != 0; uVar10 = uVar10 - 1
            ) {
          *pfVar21 = *pfVar20;
          pfVar20 = pfVar20 + 1;
          pfVar21 = pfVar21 + 1;
        }
        for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
          *(undefined1 *)pfVar21 = *(undefined1 *)pfVar20;
          pfVar20 = (float *)((int)pfVar20 + 1);
          pfVar21 = (float *)((int)pfVar21 + 1);
        }
      }
      fVar14 = *pfVar17;
      iVar4 = FUN_0049d2d0(fVar14);
      if (iVar4 == 0) {
        FUN_00544b47(&DAT_006552c0,s_Can_t_find_object_type__d__OpObj_005633f4,fVar14);
        FUN_00429100(&DAT_006552c0);
        iVar4 = FUN_0049c190(0x406,0);
        if (iVar4 == 0) {
          iVar4 = DAT_006313b4 + 8;
        }
        else {
          *(undefined4 *)(iVar4 + 0xc4) = 0x41200000;
        }
      }
      iVar11 = local_414;
      if (0x3ff < local_414) {
        FUN_00523aa0(s_Too_many_objects_for_world_005633d8);
        local_414 = iVar11 + -1;
      }
      puVar16 = local_40c + local_414 * 0xc1;
      puVar6 = puVar16;
      for (iVar11 = 0xc1; iVar11 != 0; iVar11 = iVar11 + -1) {
        *puVar6 = 0;
        puVar6 = puVar6 + 1;
      }
      local_414 = local_414 + 1;
      FUN_0049ccf0(puVar16,iVar4);
      FUN_0049cfd0(puVar16,iVar4);
      puVar16[0x28] = *(undefined4 *)((int)pfVar18 + 5);
      puVar16[0x29] = *(undefined4 *)((int)pfVar18 + 9);
      puVar16[0x2a] = *(undefined4 *)((int)pfVar18 + 0xd);
      pfVar20 = (float *)((int)pfVar18 + 0x15);
      puVar16[0x32] = *(undefined4 *)((int)pfVar18 + 0x11);
      if (local_410 == 9.80909e-44) {
        puVar16[0x33] = *pfVar20;
        pfVar20 = (float *)((int)pfVar18 + 0x1d);
        puVar16[0x34] = *(undefined4 *)((int)pfVar18 + 0x19);
      }
      puVar16[0x2b] = puVar16[0x28];
      puVar16[0x2c] = puVar16[0x29];
      puVar16[0x2d] = puVar16[0x2a];
      puVar6 = (undefined4 *)(iVar4 + 400);
      puVar5 = puVar16 + 100;
      for (iVar11 = 0x1e; iVar11 != 0; iVar11 = iVar11 + -1) {
        *puVar5 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar5 = puVar5 + 1;
      }
      if (local_404 != 0) {
        puVar16[0x37] = puVar16[0x37] | 0x20000000;
        fVar14 = local_410;
        pfVar18 = pfVar20;
        iVar4 = local_3ec;
        goto LAB_004b809d;
      }
      break;
    case 6.02558e-44:
      puVar16[5] = *pfVar17;
      fVar14 = local_410;
      pfVar18 = (float *)((int)pfVar18 + 5);
      goto LAB_004b809d;
    case 6.16571e-44:
    case 1.56945e-43:
    case 1.58347e-43:
      goto switchD_004b80be_caseD_2c;
    case 6.30584e-44:
      goto switchD_004b80be_caseD_2d;
    case 6.44597e-44:
      *(float *)(DAT_006316ec + 0x7c) = *pfVar17;
      *(float *)(DAT_006316ec + 0x80) = 1.0 / *(float *)((int)pfVar18 + 5);
      *(undefined4 *)(DAT_006316ec + 0x84) = *(undefined4 *)((int)pfVar18 + 9);
      fVar14 = local_410;
      pfVar18 = (float *)((int)pfVar18 + 0xd);
      goto LAB_004b809d;
    case 6.5861e-44:
      fVar14 = local_410;
      pfVar18 = (float *)((int)pfVar18 + 0x1d);
      goto LAB_004b809d;
    case 6.72623e-44:
      bVar9 = *(byte *)pfVar17;
      iVar11 = (uint)bVar9 * 0x10;
      *(undefined4 *)(iVar11 + 0x17c + DAT_006316ec) = *(undefined4 *)((int)pfVar18 + 3);
      *(undefined4 *)((bVar9 + 0x18) * 0x10 + DAT_006316ec) = *(undefined4 *)((int)pfVar18 + 7);
      *(undefined4 *)(iVar11 + 0x184 + DAT_006316ec) = *(undefined4 *)((int)pfVar18 + 0xb);
      *(undefined4 *)(iVar11 + 0x188 + DAT_006316ec) = *(undefined4 *)((int)pfVar18 + 0xf);
      fVar14 = local_410;
      pfVar18 = (float *)((int)pfVar18 + 0x13);
      goto LAB_004b809d;
    case 6.86636e-44:
      fVar14 = local_410;
      pfVar18 = (float *)((int)pfVar18 + 0x29);
      goto LAB_004b809d;
    case 7.00649e-44:
      if (puVar16[0x78] == 0x24) {
        if (puVar16[0x5c] == 0) {
          puVar5 = (undefined4 *)
                   mem_alloc_tagged(0x18,0x18,&DAT_005633c8,
                                    s_C__Giants_Source_main_readwrls_c_00563174,0x3ea);
          puVar6 = puVar5;
          for (iVar4 = 6; iVar4 != 0; iVar4 = iVar4 + -1) {
            *puVar6 = 0;
            puVar6 = puVar6 + 1;
          }
          *puVar5 = 5;
          puVar16[0x5c] = puVar5;
          puVar5[3] = 0x3ecccccd;
          puVar5[4] = 0x3f800000;
          puVar5[2] = 0;
        }
        *(uint *)(puVar16[0x5c] + 4) = (uint)*(byte *)pfVar17;
        fVar14 = local_410;
        pfVar18 = (float *)((int)pfVar18 + 3);
        iVar4 = local_3ec;
      }
      else {
        iVar11 = puVar16[0x40];
        *(uint *)(iVar11 + 8) = (uint)*(byte *)pfVar17;
        *(uint *)(iVar11 + 0x28) = (uint)*(byte *)((int)pfVar18 + 2);
        fVar14 = local_410;
        pfVar18 = (float *)((int)pfVar18 + 3);
      }
      goto LAB_004b809d;
    case 7.14662e-44:
      FUN_00523aa0(s_Obsolete_garden_opcode_00563388);
      fVar14 = local_410;
      pfVar18 = (float *)((int)pfVar18 + 0x25);
      iVar4 = local_3ec;
      goto LAB_004b809d;
    case 7.28675e-44:
      FUN_0053c890(0x1a,pfVar17,DAT_006316ec + 0x1e4,s_C__Giants_Source_main_readwrls_c_00563174,
                   0x438);
      *(undefined4 *)(DAT_006316ec + 0x1e8) = *(undefined4 *)((int)pfVar18 + 0x21);
      if (*(float *)(DAT_006316ec + 0x1e8) == 0.0) {
        *(undefined4 *)(DAT_006316ec + 0x1e8) = 0x42480000;
      }
      *(float *)(DAT_006316ec + 0x1e8) = 1.0 / *(float *)(DAT_006316ec + 0x1e8);
      fVar14 = local_410;
      pfVar18 = (float *)((int)pfVar18 + 0x2d);
      iVar4 = local_3ec;
      goto LAB_004b809d;
    case 7.42688e-44:
      FUN_0053c890(0x1a,pfVar17,DAT_006316ec + 0x1ec,s_C__Giants_Source_main_readwrls_c_00563174,
                   0x443);
      *(undefined4 *)(DAT_006316ec + 0x1f0) = *(undefined4 *)((int)pfVar18 + 0x21);
      if (*(float *)(DAT_006316ec + 0x1f0) == 0.0) {
        *(undefined4 *)(DAT_006316ec + 0x1f0) = 0x42480000;
      }
      *(float *)(DAT_006316ec + 0x1f0) = 1.0 / *(float *)(DAT_006316ec + 0x1f0);
      fVar14 = local_410;
      pfVar18 = (float *)((int)pfVar18 + 0x2d);
      iVar4 = local_3ec;
      goto LAB_004b809d;
    case 7.56701e-44:
      FUN_0053c890(0x1a,pfVar17,DAT_006316ec + 500,s_C__Giants_Source_main_readwrls_c_00563174,0x44e
                  );
      *(undefined4 *)(DAT_006316ec + 0x1f8) = *(undefined4 *)((int)pfVar18 + 0x21);
      if (*(float *)(DAT_006316ec + 0x1f8) == 0.0) {
        *(undefined4 *)(DAT_006316ec + 0x1f8) = 0x42480000;
      }
      *(float *)(DAT_006316ec + 0x1f8) = 1.0 / *(float *)(DAT_006316ec + 0x1f8);
      fVar14 = local_410;
      pfVar18 = (float *)((int)pfVar18 + 0x2d);
      iVar4 = local_3ec;
      goto LAB_004b809d;
    case 7.70714e-44:
      FUN_00523aa0(s_Obsolete_mesh_single_opcode_0056336c);
      fVar14 = local_410;
      pfVar18 = (float *)((int)pfVar18 + 0x25);
      iVar4 = local_3ec;
      goto LAB_004b809d;
    case 7.84727e-44:
      FUN_00523aa0(s_Obsolete_mesh_group_opcode_00563350);
      fVar14 = local_410;
      pfVar18 = (float *)((int)pfVar18 + 0x25);
      iVar4 = local_3ec;
      goto LAB_004b809d;
    case 7.9874e-44:
      *(undefined4 *)(DAT_006316ec + 0x1ac) = *(undefined4 *)((int)pfVar18 + 0xd);
      *(undefined4 *)(DAT_006316ec + 0x1b0) = *(undefined4 *)((int)pfVar18 + 0x11);
      *(undefined4 *)(DAT_006316ec + 0x1b4) = *(undefined4 *)((int)pfVar18 + 0x15);
      pfVar20 = (float *)((int)pfVar18 + 0x1d);
      *(undefined4 *)(DAT_006316ec + 0x1b8) = *(undefined4 *)((int)pfVar18 + 0x19);
      if (*(float *)(DAT_006316ec + 0x1b0) != 0.0) {
        *(float *)(DAT_006316ec + 0x1ac) =
             *(float *)(DAT_006316ec + 0x1ac) * *(float *)(DAT_006316ec + 0x1ac);
        *(float *)(DAT_006316ec + 0x1b0) =
             *(float *)(DAT_006316ec + 0x1b0) * *(float *)(DAT_006316ec + 0x1b0);
        *(float *)(DAT_006316ec + 0x1bc) =
             (*(float *)(DAT_006316ec + 0x1b8) - *(float *)(DAT_006316ec + 0x1b4)) /
             (*(float *)(DAT_006316ec + 0x1b0) - *(float *)(DAT_006316ec + 0x1ac));
        *(float *)(DAT_006316ec + 0x1c0) =
             *(float *)(DAT_006316ec + 0x1b4) -
             *(float *)(DAT_006316ec + 0x1bc) * *(float *)(DAT_006316ec + 0x1ac);
        fVar14 = local_410;
        pfVar18 = pfVar20;
        goto LAB_004b809d;
      }
      break;
    case 8.12753e-44:
      puVar16[0x37] = puVar16[0x37] | 0x40;
switchD_004b80be_caseD_2d:
      if ((local_418 != (char *)0x0) && (*(int *)(DAT_006316ec + 0x210) == 0)) {
        *(char **)(DAT_006316ec + 0x20c) = local_418;
        uVar10 = (int)local_418 * 3;
        uVar8 = mem_alloc_tagged(0x1a,(int)local_418 * 0xc,s_walist_005633d0,
                                 s_C__Giants_Source_main_readwrls_c_00563174,0x68b);
        *(undefined4 *)(DAT_006316ec + 0x210) = uVar8;
        puVar6 = local_180;
        puVar5 = *(undefined4 **)(DAT_006316ec + 0x210);
        for (uVar10 = uVar10 & 0x3fffffff; uVar10 != 0; uVar10 = uVar10 - 1) {
          *puVar5 = *puVar6;
          puVar6 = puVar6 + 1;
          puVar5 = puVar5 + 1;
        }
        for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
          *(undefined1 *)puVar5 = *(undefined1 *)puVar6;
          puVar6 = (undefined4 *)((int)puVar6 + 1);
          puVar5 = (undefined4 *)((int)puVar5 + 1);
        }
      }
      uVar8 = FUN_004a1360(pfVar17);
      puVar16[0x5e] = puVar16[0x28];
      puVar16[0x5f] = puVar16[0x29];
      puVar16[0x60] = puVar16[0x2a];
      if (puVar16[1] != 0x23f) {
        FUN_0049f3b0(puVar16,0x36);
        *(undefined4 *)puVar16[0x40] = uVar8;
        *(undefined4 *)(puVar16[0x40] + 8) = *(undefined4 *)((int)pfVar18 + 0x21);
      }
      puVar16[0x72] = puVar16[0x72] | 0x400000;
      fVar14 = local_410;
      pfVar18 = (float *)((int)pfVar18 + 0x25);
      iVar4 = local_3ec;
      goto LAB_004b809d;
    case 8.26766e-44:
      puVar16[0x3a] = (uint)*(byte *)pfVar17;
      fVar14 = local_410;
      pfVar18 = (float *)((int)pfVar18 + 2);
      goto LAB_004b809d;
    case 8.54792e-44:
    case 9.3887e-44:
      break;
    case 8.68805e-44:
      fVar14 = local_410;
      pfVar18 = (float *)((int)pfVar18 + 0x15);
      goto LAB_004b809d;
    case 8.82818e-44:
      if (puVar16[0x78] != 0x24) goto LAB_004b9412;
      *(float *)(puVar16[0x5c] + 0xc) = *pfVar17;
      *(undefined4 *)(puVar16[0x5c] + 0x10) = *(undefined4 *)((int)pfVar18 + 5);
      fVar14 = local_410;
      pfVar18 = (float *)((int)pfVar18 + 9);
      goto LAB_004b809d;
    case 8.96831e-44:
      fVar14 = *pfVar17;
      local_41c = FUN_0049d2d0(fVar14);
      if (local_41c == 0) {
        FUN_00544b47(&DAT_006552c0,s_Can_t_find_object_type__d__OpAre_00563328,fVar14);
        FUN_00523aa0(&DAT_006552c0);
        local_41c = DAT_006313b4 + 8;
      }
      iVar4 = local_414;
      if (0x3ff < local_414) {
        FUN_00523aa0(s_Too_many_objects_for_world_005633d8);
        local_414 = iVar4 + -1;
      }
      puVar16 = local_40c + local_414 * 0xc1;
      puVar6 = puVar16;
      for (iVar4 = 0xc1; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar6 = 0;
        puVar6 = puVar6 + 1;
      }
      local_414 = local_414 + 1;
      FUN_0049ccf0(puVar16,local_41c);
      FUN_0049f3b0(puVar16,0x16);
      puVar5 = (undefined4 *)
               mem_alloc_tagged(0x18,0x28,s_teamripper_0056331c,
                                s_C__Giants_Source_main_readwrls_c_00563174,0x4a4);
      puVar6 = puVar5;
      for (iVar4 = 10; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar6 = 0;
        puVar6 = puVar6 + 1;
      }
      *puVar5 = 4;
      puVar16[0x5c] = puVar5;
      puVar6 = puVar16 + 0x28;
      puVar5[3] = (float)*(byte *)((int)pfVar18 + 5);
      *puVar6 = *(undefined4 *)((int)pfVar18 + 6);
      puVar16[0x29] = *(undefined4 *)((int)pfVar18 + 10);
      puVar16[0x2a] = *(undefined4 *)((int)pfVar18 + 0xe);
      puVar16[0x2b] = *puVar6;
      puVar16[0x2c] = puVar16[0x29];
      puVar16[0x2d] = puVar16[0x2a];
      puVar5[6] = *puVar6;
      puVar5[7] = puVar16[0x29];
      puVar5[8] = puVar16[0x2a];
      puVar5[4] = *(undefined4 *)((int)pfVar18 + 0x12);
      puVar5[5] = *(undefined4 *)((int)pfVar18 + 0x16);
      puVar5[1] = 0x3f400000;
      puVar5[2] = 0x3f800000;
      fVar14 = local_410;
      pfVar18 = (float *)((int)pfVar18 + 0x1a);
      iVar4 = local_3ec;
      goto LAB_004b809d;
    case 9.10844e-44:
      *(float *)(puVar16[0x5c] + 4) = *pfVar17;
      *(undefined4 *)(puVar16[0x5c] + 8) = *(undefined4 *)((int)pfVar18 + 5);
      fVar14 = local_410;
      pfVar18 = (float *)((int)pfVar18 + 9);
      goto LAB_004b809d;
    case 9.24857e-44:
      fVar14 = *pfVar17;
      local_41c = FUN_0049d2d0(fVar14);
      if (local_41c == 0) {
        FUN_00544b47(&DAT_006552c0,s_Can_t_find_object_type__d__OpSmo_005632f4,fVar14);
        FUN_00523aa0(&DAT_006552c0);
        local_41c = DAT_006313b4 + 8;
      }
      iVar4 = local_414;
      if (0x3ff < local_414) {
        FUN_00523aa0(s_Too_many_objects_for_world_005633d8);
        local_414 = iVar4 + -1;
      }
      puVar16 = local_40c + local_414 * 0xc1;
      local_414 = local_414 + 1;
      puVar6 = puVar16;
      for (iVar4 = 0xc1; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar6 = 0;
        puVar6 = puVar6 + 1;
      }
      FUN_0049ccf0(puVar16,local_41c);
      FUN_0049f3b0(puVar16,0x18);
      puVar16[0x28] = *(undefined4 *)((int)pfVar18 + 5);
      puVar16[0x29] = *(undefined4 *)((int)pfVar18 + 9);
      puVar16[0x2a] = *(undefined4 *)((int)pfVar18 + 0xd);
      puVar16[0x2b] = puVar16[0x28];
      puVar16[0x2c] = puVar16[0x29];
      puVar16[0x2d] = puVar16[0x2a];
      puVar6 = (undefined4 *)
               mem_alloc_tagged(0x18,0x4c,&DAT_005632f0,s_C__Giants_Source_main_readwrls_c_00563174,
                                0x4d4);
      *puVar6 = *(undefined4 *)((int)pfVar18 + 0x11);
      puVar6[1] = *(undefined4 *)((int)pfVar18 + 0x15);
      puVar6[2] = *(undefined4 *)((int)pfVar18 + 0x19);
      puVar6[3] = *(undefined4 *)((int)pfVar18 + 0x1d);
      puVar6[4] = *(undefined4 *)((int)pfVar18 + 0x21);
      puVar6[5] = *(undefined4 *)((int)pfVar18 + 0x25);
      puVar6[6] = *(undefined4 *)((int)pfVar18 + 0x29);
      puVar6[7] = *(undefined4 *)((int)pfVar18 + 0x2d);
      puVar6[8] = *(undefined4 *)((int)pfVar18 + 0x31);
      puVar6[9] = *(undefined4 *)((int)pfVar18 + 0x35);
      puVar6[10] = *(undefined4 *)((int)pfVar18 + 0x39);
      puVar6[0xb] = *(undefined4 *)((int)pfVar18 + 0x3d);
      puVar6[0xc] = *(undefined4 *)((int)pfVar18 + 0x41);
      puVar6[0xc] = *(undefined4 *)((int)pfVar18 + 0x45);
      puVar6[0xe] = *(undefined4 *)((int)pfVar18 + 0x49);
      puVar6[0xf] = *(undefined4 *)((int)pfVar18 + 0x4d);
      puVar6[0xf] = *(undefined4 *)((int)pfVar18 + 0x51);
      puVar6[0x11] = *(undefined4 *)((int)pfVar18 + 0x55);
      puVar6[0x12] = *(undefined4 *)((int)pfVar18 + 0x59);
      if ((float)puVar6[0x12] < 0.01) {
        puVar6[0x12] = 0x3c23d70a;
      }
      *(undefined4 **)puVar16[0x40] = puVar6;
      puVar16[0x36] = puVar16[0x36] | 0x40000000;
      puVar16[0x38] = puVar16[0x38] | 4;
      fVar14 = local_410;
      pfVar18 = (float *)((int)pfVar18 + 0x5d);
      iVar4 = local_3ec;
      goto LAB_004b809d;
    case 9.52883e-44:
      local_404 = 1;
      fVar14 = local_410;
      pfVar18 = pfVar17;
      goto LAB_004b809d;
    case 9.66896e-44:
      local_404 = 0;
      fVar14 = local_410;
      pfVar18 = pfVar17;
      goto LAB_004b809d;
    case 9.94922e-44:
      *(float *)(DAT_006316ec + 0x1c4) = *pfVar17;
      *(undefined4 *)(DAT_006316ec + 0x1cc) = *(undefined4 *)((int)pfVar18 + 5);
      *(undefined4 *)(DAT_006316ec + 0x1d0) = *(undefined4 *)((int)pfVar18 + 0xd);
      local_3d0 = *(undefined4 *)((int)pfVar18 + 0x11);
      *(float *)(DAT_006316ec + 0x1c8) = 1.0 / *(float *)(DAT_006316ec + 0x1c4);
      iVar4 = DAT_006316ec;
      iVar11 = __ftol();
      *(int *)(iVar4 + 0x1dc) = iVar11 + 1;
      iVar4 = DAT_006316ec;
      iVar11 = __ftol();
      *(int *)(iVar4 + 0x1e0) = iVar11 + 1;
      fVar14 = local_410;
      pfVar18 = (float *)((int)pfVar18 + 0x15);
      iVar4 = local_3ec;
      goto LAB_004b809d;
    case 1.00893e-43:
      if (0x1f < *(int *)(puVar16[0x5c] + 8)) {
        FUN_00523aa0(s_Too_many_points_in_point_list_fo_005633a0);
        *(int *)(puVar16[0x5c] + 8) = *(int *)(puVar16[0x5c] + 8) + -1;
      }
      iVar4 = puVar16[0x5c];
      iVar11 = *(int *)(iVar4 + 8);
      local_364[iVar11 * 3] = *pfVar17;
      local_364[iVar11 * 3 + 1] = *(float *)((int)pfVar18 + 5);
      local_364[iVar11 * 3 + 2] = *(float *)((int)pfVar18 + 9);
      *(int *)(iVar4 + 8) = iVar11 + 1;
      fVar14 = local_410;
      pfVar18 = (float *)((int)pfVar18 + 0xd);
      iVar4 = local_3ec;
      goto LAB_004b809d;
    case 1.02295e-43:
      *(float *)(DAT_006316ec + 0x1fc) = *pfVar17;
      fVar14 = local_410;
      pfVar18 = (float *)((int)pfVar18 + 5);
      goto LAB_004b809d;
    case 1.03696e-43:
      *(undefined4 *)(DAT_006316ec + 0x200) = 1;
      fVar14 = local_410;
      pfVar18 = pfVar17;
      goto LAB_004b809d;
    case 1.05097e-43:
      if (0 < *(int *)(DAT_006316ec + 0x20c)) {
        FUN_00523aa0(s_WorldAnims_after_references__005632d0);
      }
      pcVar24 = local_418;
      if (0x1f < (int)local_418) {
        FUN_00523aa0(s_Too_many_animations_for_a_world_005632b0);
        pcVar24 = pcVar24 + -1;
      }
      FUN_0053c890(0x1a,pfVar17,local_180 + (int)pcVar24 * 3,
                   s_C__Giants_Source_main_readwrls_c_00563174,0x518);
      cVar2 = *(char *)pfVar17;
      while (cVar2 != '\0') {
        pcVar19 = (char *)((int)pfVar17 + 1);
        pfVar17 = (float *)((int)pfVar17 + 1);
        cVar2 = *pcVar19;
      }
      pcVar19 = (char *)((int)pfVar17 + 1);
      FUN_00544b47(local_1e4,s__s_anm_005632a8,pcVar19);
      cVar2 = *pcVar19;
      while (cVar2 != '\0') {
        pcVar1 = pcVar19 + 1;
        pcVar19 = pcVar19 + 1;
        cVar2 = *pcVar1;
      }
      pcVar19 = pcVar19 + 1;
      FUN_0053c890(0x1a,pcVar19,auStack_178 + (int)pcVar24 * 0xc,
                   s_C__Giants_Source_main_readwrls_c_00563174,0x51c);
      cVar2 = *pcVar19;
      while (cVar2 != '\0') {
        pcVar1 = pcVar19 + 1;
        pcVar19 = pcVar19 + 1;
        cVar2 = *pcVar1;
      }
      uVar8 = FUN_00405080(local_1e4);
      local_418 = pcVar24 + 1;
      local_180[(int)pcVar24 * 3 + 1] = uVar8;
      fVar14 = local_410;
      pfVar18 = (float *)(pcVar19 + 1);
      iVar4 = local_3ec;
      goto LAB_004b809d;
    case 1.06499e-43:
      if (7 < local_408) {
        FUN_00523aa0(s_Lock_level_nest_too_deep_0056328c);
        local_408 = local_408 + -1;
      }
      uVar10 = ((int)puVar16 - (int)local_40c) / 0x304;
      if (((puVar16 != (undefined4 *)0x0) && (piVar15 = (int *)puVar16[0x5c], piVar15 != (int *)0x0)
          ) && ((*piVar15 == 5 && ((piVar15[2] != 0 && (piVar15[5] == 0)))))) {
        uVar8 = mem_alloc_tagged(0x18,piVar15[2] * 0xc,s_flakpts_00563434,
                                 s_C__Giants_Source_main_readwrls_c_00563174,0xe2);
        *(undefined4 *)(puVar16[0x5c] + 0x14) = uVar8;
        pfVar20 = local_364;
        pfVar21 = *(float **)(puVar16[0x5c] + 0x14);
        for (uVar7 = *(int *)(puVar16[0x5c] + 8) * 3 & 0x3fffffff; uVar7 != 0; uVar7 = uVar7 - 1) {
          *pfVar21 = *pfVar20;
          pfVar20 = pfVar20 + 1;
          pfVar21 = pfVar21 + 1;
        }
        for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
          *(undefined1 *)pfVar21 = *(undefined1 *)pfVar20;
          pfVar20 = (float *)((int)pfVar20 + 1);
          pfVar21 = (float *)((int)pfVar21 + 1);
        }
      }
      fVar14 = *pfVar17;
      auStack_384[local_408] = uVar10;
      iVar4 = FUN_0049d2d0(fVar14);
      if (iVar4 == 0) {
        FUN_00544b47(&DAT_006552c0,s_Can_t_find_object_type__d__OpLoc_00563264,fVar14);
        FUN_00523aa0(&DAT_006552c0);
        iVar4 = DAT_006313b4 + 8;
      }
      if (0x3ff < local_414) {
        FUN_00523aa0(s_Too_many_objects_for_world_005633d8);
        local_414 = local_414 + -1;
      }
      puVar16 = local_40c + local_414 * 0xc1;
      local_414 = local_414 + 1;
      puVar6 = puVar16;
      for (iVar11 = 0xc1; iVar11 != 0; iVar11 = iVar11 + -1) {
        *puVar6 = 0;
        puVar6 = puVar6 + 1;
      }
      FUN_0049ccf0(puVar16,iVar4);
      FUN_0049cfd0(puVar16,iVar4);
      puVar6 = (undefined4 *)(iVar4 + 400);
      puVar5 = puVar16 + 100;
      for (iVar11 = 0x1e; iVar11 != 0; iVar11 = iVar11 + -1) {
        *puVar5 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar5 = puVar5 + 1;
      }
      if (local_404 != 0) {
        puVar16[0x37] = puVar16[0x37] | 0x20000000;
      }
      puVar16[0x84] = uVar10 | 0x80000000;
      puVar16[0x85] = (uint)*(byte *)((int)pfVar18 + 5);
      local_408 = local_408 + 1;
      puVar16[0x86] = (uint)*(byte *)((int)pfVar18 + 6);
      fVar14 = local_410;
      pfVar18 = (float *)((int)pfVar18 + 7);
      iVar4 = local_3ec;
      goto LAB_004b809d;
    case 1.079e-43:
      if (local_408 == 0) {
        FUN_00523aa0(s_Lock_level_underflow_0055ea50);
        fVar14 = local_410;
        pfVar18 = pfVar17;
        iVar4 = local_3ec;
      }
      else {
        if ((((puVar16 != (undefined4 *)0x0) &&
             (piVar15 = (int *)puVar16[0x5c], piVar15 != (int *)0x0)) && (*piVar15 == 5)) &&
           ((piVar15[2] != 0 && (piVar15[5] == 0)))) {
          uVar8 = mem_alloc_tagged(0x18,piVar15[2] * 0xc,s_flakpts_00563434,
                                   s_C__Giants_Source_main_readwrls_c_00563174,0xe2);
          *(undefined4 *)(puVar16[0x5c] + 0x14) = uVar8;
          pfVar18 = local_364;
          pfVar20 = *(float **)(puVar16[0x5c] + 0x14);
          for (uVar10 = *(int *)(puVar16[0x5c] + 8) * 3 & 0x3fffffff; uVar10 != 0;
              uVar10 = uVar10 - 1) {
            *pfVar20 = *pfVar18;
            pfVar18 = pfVar18 + 1;
            pfVar20 = pfVar20 + 1;
          }
          for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
            *(undefined1 *)pfVar20 = *(undefined1 *)pfVar18;
            pfVar18 = (float *)((int)pfVar18 + 1);
            pfVar20 = (float *)((int)pfVar20 + 1);
          }
        }
        local_408 = local_408 + -1;
        puVar16 = local_40c + auStack_384[local_408] * 0xc1;
        fVar14 = local_410;
        pfVar18 = pfVar17;
        iVar4 = local_3ec;
      }
      goto LAB_004b809d;
    case 1.09301e-43:
      iVar11 = 0;
      iVar4 = 0;
      do {
        iVar12 = FUN_0053c970(iVar4 + 0x214 + DAT_006316ec,pfVar17);
        if (iVar12 != 0) break;
        iVar4 = iVar4 + 0x20;
        iVar11 = iVar11 + 1;
      } while (iVar4 < 0x1000);
      if (iVar11 == 0x80) {
        FUN_00544b47(&DAT_006552c0,s_Error__Flick__s_not_in_world_fli_0055ea28,pfVar17);
        FUN_00523aa0(&DAT_006552c0);
        fVar14 = local_410;
        pfVar18 = (float *)((int)pfVar18 + 0x21);
        iVar4 = local_3ec;
      }
      else {
        bVar9 = (byte)iVar11;
        fVar14 = local_410;
        iVar4 = local_3ec;
        if (iVar11 < 0x20) {
          puVar16[0xba] = puVar16[0xba] | 1 << (bVar9 & 0x1f);
          pfVar18 = (float *)((int)pfVar18 + 0x21);
        }
        else if (iVar11 < 0x40) {
          puVar16[0xbb] = puVar16[0xbb] | 1 << (bVar9 - 0x20 & 0x1f);
          pfVar18 = (float *)((int)pfVar18 + 0x21);
        }
        else if (iVar11 < 0x60) {
          puVar16[0xbc] = puVar16[0xbc] | 1 << (bVar9 - 0x40 & 0x1f);
          pfVar18 = (float *)((int)pfVar18 + 0x21);
        }
        else {
          if (iVar11 < 0x80) {
            puVar16[0xbc] = puVar16[0xbc] | 1 << (bVar9 + 0xa0 & 0x1f);
          }
switchD_004b80be_caseD_2c:
          fVar14 = local_410;
          pfVar18 = (float *)((int)pfVar18 + 0x21);
          iVar4 = local_3ec;
        }
      }
      goto LAB_004b809d;
    case 1.10703e-43:
      if (0x7f < local_400) {
        FUN_00523aa0(s_Too_many_flicks_for_world_00563248);
        local_400 = iVar11 + -1;
      }
      pcVar24 = (char *)(local_400 * 0x20 + 0x214 + DAT_006316ec);
      do {
        cVar2 = *(char *)pfVar17;
        pfVar17 = (float *)((int)pfVar17 + 1);
        *pcVar24 = cVar2;
        pcVar24 = pcVar24 + 1;
      } while (cVar2 != '\0');
      pcVar19 = (char *)((int)pfVar18 + 0x21);
      pcVar24 = (char *)(local_400 * 0x20 + 0x1214 + DAT_006316ec);
      do {
        cVar2 = *pcVar19;
        pcVar19 = pcVar19 + 1;
        *pcVar24 = cVar2;
        pcVar24 = pcVar24 + 1;
      } while (cVar2 != '\0');
      local_400 = local_400 + 1;
      fVar14 = local_410;
      pfVar18 = (float *)((int)pfVar18 + 0x41);
      iVar4 = local_3ec;
      goto LAB_004b809d;
    case 1.12104e-43:
      iVar11 = puVar16[0x40];
      bVar9 = *(byte *)pfVar17;
      pfVar20 = (float *)((int)pfVar18 + 2);
      iVar12 = 0;
      pfVar18 = pfVar20;
      if (bVar9 != 0) {
        do {
          fVar14 = *pfVar18;
          pfVar18 = pfVar18 + 1;
          *(float *)(iVar11 + iVar12 * 4) = fVar14;
          iVar12 = iVar12 + 1;
          fVar14 = local_410;
        } while (iVar12 < (int)(uint)bVar9);
        goto LAB_004b809d;
      }
      break;
    case 1.13505e-43:
      puVar16[0x32] = *pfVar17;
      puVar16[0x33] = *(undefined4 *)((int)pfVar18 + 5);
      pfVar20 = (float *)((int)pfVar18 + 0xd);
      puVar16[0x34] = *(undefined4 *)((int)pfVar18 + 9);
      if (puVar16[0x84] != 0) {
        puVar16[0x37] = puVar16[0x37] | 0x8000;
        fVar14 = local_410;
        pfVar18 = pfVar20;
        goto LAB_004b809d;
      }
      break;
    case 1.14906e-43:
      puVar16[0x5d] = *pfVar17;
      fVar14 = local_410;
      pfVar18 = (float *)((int)pfVar18 + 5);
      goto LAB_004b809d;
    case 1.16308e-43:
      *(float *)(puVar16[0x40] + 4) = *pfVar17;
      fVar14 = local_410;
      pfVar18 = (float *)((int)pfVar18 + 5);
      goto LAB_004b809d;
    case 1.17709e-43:
      if ((local_418 != (char *)0x0) && (*(int *)(DAT_006316ec + 0x210) == 0)) {
        *(char **)(DAT_006316ec + 0x20c) = local_418;
        uVar10 = (int)local_418 * 3;
        uVar8 = mem_alloc_tagged(0x1a,(int)local_418 * 0xc,s_walist_005633d0,
                                 s_C__Giants_Source_main_readwrls_c_00563174,0x68b);
        *(undefined4 *)(DAT_006316ec + 0x210) = uVar8;
        puVar6 = local_180;
        puVar5 = *(undefined4 **)(DAT_006316ec + 0x210);
        for (uVar10 = uVar10 & 0x3fffffff; uVar10 != 0; uVar10 = uVar10 - 1) {
          *puVar5 = *puVar6;
          puVar6 = puVar6 + 1;
          puVar5 = puVar5 + 1;
        }
        for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
          *(undefined1 *)puVar5 = *(undefined1 *)puVar6;
          puVar6 = (undefined4 *)((int)puVar6 + 1);
          puVar5 = (undefined4 *)((int)puVar5 + 1);
        }
      }
      uVar8 = FUN_004a1360(pfVar17);
      FUN_0049f3b0(puVar16,0x4f);
      *(undefined4 *)puVar16[0x40] = uVar8;
      *(undefined4 *)(puVar16[0x40] + 8) = *(undefined4 *)((int)pfVar18 + 0x21);
      puVar16[0x72] = puVar16[0x72] | 0x400000;
      *(undefined4 *)(puVar16[0x40] + 0x10) = *(undefined4 *)((int)pfVar18 + 0x25);
      *(undefined4 *)(puVar16[0x40] + 0xc) = *(undefined4 *)((int)pfVar18 + 0x29);
      fVar14 = local_410;
      pfVar18 = (float *)((int)pfVar18 + 0x2d);
      iVar4 = local_3ec;
      goto LAB_004b809d;
    case 1.23314e-43:
      *(float *)(DAT_006316ec + 0x140) = *pfVar17;
      *(undefined4 *)(DAT_006316ec + 0x144) = *(undefined4 *)((int)pfVar18 + 5);
      *(float *)(DAT_006316ec + 0x148) = (float)*(byte *)((int)pfVar18 + 9);
      *(float *)(DAT_006316ec + 0x14c) = (float)*(byte *)((int)pfVar18 + 10);
      *(float *)(DAT_006316ec + 0x150) = (float)*(byte *)((int)pfVar18 + 0xb);
      *(float *)(DAT_006316ec + 0x148) = *(float *)(DAT_006316ec + 0x148) * 0.003921569;
      *(float *)(DAT_006316ec + 0x14c) = *(float *)(DAT_006316ec + 0x14c) * 0.003921569;
      *(float *)(DAT_006316ec + 0x150) = *(float *)(DAT_006316ec + 0x150) * 0.003921569;
      if (*(float *)(DAT_006316ec + 0x140) < 0.0) {
        FUN_00544b99(s_World_>waterfogmin_>__0_0f_00563458,
                     s_C__Giants_Source_main_readwrls_c_00563174,0x293);
      }
      if (*(float *)(DAT_006316ec + 0x144) < 0.0) {
        FUN_00544b99(s_World_>waterfogmax_>__0_0f_0056343c,
                     s_C__Giants_Source_main_readwrls_c_00563174,0x294);
      }
      FUN_0051bd20();
      fVar14 = local_410;
      pfVar18 = pfVar18 + 3;
      iVar4 = local_3ec;
      goto LAB_004b809d;
    case 1.24716e-43:
      pfVar18 = pfVar17;
      do {
        cVar2 = *(char *)pfVar18;
        pfVar18 = (float *)((int)pfVar18 + 1);
      } while (cVar2 != '\0');
      pcVar24 = (char *)(DAT_006316ec + 0x4534);
      do {
        cVar2 = *(char *)pfVar17;
        pfVar17 = (float *)((int)pfVar17 + 1);
        *pcVar24 = cVar2;
        pcVar24 = pcVar24 + 1;
        fVar14 = local_410;
      } while (cVar2 != '\0');
      goto LAB_004b809d;
    case 1.26117e-43:
      puVar16[0x3d] = *pfVar17;
      puVar16[0x3e] = *(undefined4 *)((int)pfVar18 + 5);
      puVar16[0x3f] = *(undefined4 *)((int)pfVar18 + 9);
      fVar14 = local_410;
      pfVar18 = (float *)((int)pfVar18 + 0xd);
      goto LAB_004b809d;
    case 1.27518e-43:
      iVar11 = puVar16[0x40];
      *(float *)(iVar11 + 0x1c) = *pfVar17;
      *(undefined4 *)(iVar11 + 0x20) = *(undefined4 *)((int)pfVar18 + 5);
      *(undefined4 *)(iVar11 + 0x24) = *(undefined4 *)((int)pfVar18 + 9);
      fVar14 = local_410;
      pfVar18 = (float *)((int)pfVar18 + 0xd);
      goto LAB_004b809d;
    case 1.28919e-43:
      uVar8 = *(undefined4 *)((int)pfVar18 + 2);
      uVar3 = *(undefined1 *)pfVar17;
      FUN_0053c890(0x1a,(int)pfVar18 + 6,&local_3e0,s_C__Giants_Source_main_readwrls_c_00563174,
                   0x36e);
      FUN_00491830(uVar3,uVar8,local_3e0);
      mem_free_tagged(local_3e0,s_C__Giants_Source_main_readwrls_c_00563174,0x371);
      fVar14 = local_410;
      pfVar18 = (float *)((int)pfVar18 + 0x26);
      iVar4 = local_3ec;
      goto LAB_004b809d;
    case 1.30321e-43:
      FUN_0053c890(0x1a,pfVar17,&local_3d8,s_C__Giants_Source_main_readwrls_c_00563174,0x379);
      iVar4 = 0;
      pcVar24 = (char *)(DAT_006316ec + 0x2214);
      do {
        if (*pcVar24 == '\0') {
          if (iVar4 < 0x20) {
            _strncpy((char *)(DAT_006316ec + 0x2214 + iVar4 * 0x118),local_3d8,0x20);
          }
          break;
        }
        iVar4 = iVar4 + 1;
        pcVar24 = pcVar24 + 0x118;
      } while (iVar4 < 0x20);
      mem_free_tagged(local_3d8,s_C__Giants_Source_main_readwrls_c_00563174,0x382);
      fVar14 = local_410;
      pfVar18 = (float *)((int)pfVar18 + 0x21);
      iVar4 = local_3ec;
      goto LAB_004b809d;
    case 1.31722e-43:
      iVar11 = 0;
      pcVar24 = (char *)(DAT_006316ec + 0x4a80);
      do {
        if (*pcVar24 == '\0') {
          _strncpy((char *)((iVar11 + 0x254) * 0x20 + DAT_006316ec),(char *)pfVar17,0x20);
          fVar14 = local_410;
          pfVar18 = (float *)((int)pfVar18 + 0x21);
          iVar4 = local_3ec;
          goto LAB_004b809d;
        }
        iVar11 = iVar11 + 1;
        pcVar24 = pcVar24 + 0x20;
      } while (iVar11 < 0x20);
      fVar14 = local_410;
      pfVar18 = (float *)((int)pfVar18 + 0x21);
      goto LAB_004b809d;
    case 1.33123e-43:
      local_3c0[0] = *pfVar17;
      local_3c0[1] = *(float *)((int)pfVar18 + 5);
      local_3c0[2] = *(float *)((int)pfVar18 + 9);
      FUN_00472560(puVar16,local_3c0);
      fVar14 = local_410;
      pfVar18 = (float *)((int)pfVar18 + 0xd);
      iVar4 = local_3ec;
      goto LAB_004b809d;
    case 1.34525e-43:
      pfVar20 = (float *)((int)pfVar18 + 5);
      *(float *)(DAT_006316ec + 0x4e8c) = *pfVar17;
      if (*(int *)(DAT_006316ec + 0x4e8c) != 0) {
        *(undefined4 *)(DAT_006316ec + 0x4a64) = 0x1b;
        fVar14 = local_410;
        pfVar18 = pfVar20;
        goto LAB_004b809d;
      }
      break;
    case 1.35926e-43:
      uVar8 = *(undefined4 *)((int)pfVar18 + 5);
      iVar11 = puVar16[0x40];
      *(float *)(iVar11 + 0x10) = *pfVar17;
      *(undefined4 *)(iVar11 + 0x38) = 1;
      *(undefined4 *)(iVar11 + 0x14) = uVar8;
      fVar14 = local_410;
      pfVar18 = (float *)((int)pfVar18 + 9);
      goto LAB_004b809d;
    case 1.37327e-43:
      uVar8 = *(undefined4 *)((int)pfVar18 + 5);
      iVar11 = puVar16[0x40];
      *(float *)(iVar11 + 0x10) = *pfVar17;
      *(undefined4 *)(iVar11 + 0x14) = uVar8;
      fVar14 = local_410;
      pfVar18 = (float *)((int)pfVar18 + 9);
      goto LAB_004b809d;
    case 1.38729e-43:
      *(undefined4 *)(puVar16[0x40] + 0x48) = 1;
      fVar14 = local_410;
      pfVar18 = pfVar17;
      goto LAB_004b809d;
    case 1.4013e-43:
      *(undefined4 *)(puVar16[0x40] + 0x4c) = 1;
      fVar14 = local_410;
      pfVar18 = pfVar17;
      goto LAB_004b809d;
    case 1.41531e-43:
      *(float *)(DAT_006316ec + 0x4e90) = *pfVar17;
      *(undefined4 *)(DAT_006316ec + 0x4e94) = *(undefined4 *)((int)pfVar18 + 5);
      *(undefined4 *)(DAT_006316ec + 0x4e98) = *(undefined4 *)((int)pfVar18 + 9);
      fVar14 = local_410;
      pfVar18 = (float *)((int)pfVar18 + 0xd);
      goto LAB_004b809d;
    case 1.42932e-43:
      fVar23 = (float10)fcos((float10)*pfVar17 * (float10)0.017453292);
      *(float *)(DAT_006316ec + 0x4e9c) = (float)fVar23;
      fVar23 = (float10)fcos((float10)*(float *)((int)pfVar18 + 5) * (float10)0.017453292);
      *(float *)(DAT_006316ec + 0x4ea0) = (float)fVar23;
      fVar14 = local_410;
      pfVar18 = (float *)((int)pfVar18 + 9);
      goto LAB_004b809d;
    case 1.44334e-43:
      piVar15 = (int *)puVar16[0x40];
      pfVar20 = (float *)((int)pfVar18 + 5);
      pfVar17 = (float *)(piVar15 + 1);
      pfVar21 = pfVar17;
      for (iVar11 = 0x14; iVar11 != 0; iVar11 = iVar11 + -1) {
        *pfVar21 = -NAN;
        pfVar21 = pfVar21 + 1;
      }
      iVar11 = *(int *)((int)pfVar18 + 1);
      iVar12 = 0;
      *piVar15 = iVar11;
      if (0 < iVar11) {
        do {
          pfVar18 = pfVar20 + 1;
          *pfVar17 = *pfVar20;
          iVar12 = iVar12 + 1;
          pfVar17 = pfVar17 + 1;
          fVar14 = local_410;
          pfVar20 = pfVar18;
        } while (iVar12 < *piVar15);
        goto LAB_004b809d;
      }
      break;
    case 1.45735e-43:
      iVar11 = puVar16[0x40];
      pfVar20 = (float *)((int)pfVar18 + 5);
      pfVar17 = (float *)(iVar11 + 0xa8);
      pfVar21 = pfVar17;
      for (iVar12 = 0x14; iVar12 != 0; iVar12 = iVar12 + -1) {
        *pfVar21 = -NAN;
        pfVar21 = pfVar21 + 1;
      }
      *(undefined4 *)(iVar11 + 0xa4) = *(undefined4 *)((int)pfVar18 + 1);
      iVar12 = 0;
      if (0 < *(int *)(iVar11 + 0xa4)) {
        do {
          pfVar18 = pfVar20 + 1;
          *pfVar17 = *pfVar20;
          iVar12 = iVar12 + 1;
          pfVar17 = pfVar17 + 1;
          fVar14 = local_410;
          pfVar20 = pfVar18;
        } while (iVar12 < *(int *)(iVar11 + 0xa4));
        goto LAB_004b809d;
      }
      break;
    case 1.48538e-43:
      if (puVar16[0x78] == 0x33) {
        *(uint *)(puVar16[0x40] + 0x60) = (uint)*(byte *)pfVar17;
        fVar14 = local_410;
        pfVar18 = (float *)((int)pfVar18 + 2);
      }
      else {
        if (puVar16[0x78] == 0x61) {
          *(uint *)(puVar16[0x40] + 0xc) = (uint)*(byte *)pfVar17;
        }
        fVar14 = local_410;
        pfVar18 = (float *)((int)pfVar18 + 2);
      }
      goto LAB_004b809d;
    case 1.49939e-43:
      *(float *)(puVar16[0x40] + 0x50) = *pfVar17;
      fVar14 = local_410;
      pfVar18 = (float *)((int)pfVar18 + 5);
      goto LAB_004b809d;
    case 1.5134e-43:
    case 1.52742e-43:
    case 1.54143e-43:
    case 1.55544e-43:
      fVar14 = local_410;
      pfVar18 = (float *)((int)pfVar18 + 0x41);
      goto LAB_004b809d;
    case 1.59748e-43:
      FUN_0053c890(0x1a,pfVar17,DAT_006316ec + 0x4edc,s_C__Giants_Source_main_readwrls_c_00563174,
                   0x459);
      *(undefined4 *)(DAT_006316ec + 0x4ee0) = *(undefined4 *)((int)pfVar18 + 0x21);
      if (*(float *)(DAT_006316ec + 0x4ee0) == 0.0) {
        *(undefined4 *)(DAT_006316ec + 0x4ee0) = 0x42480000;
      }
      *(float *)(DAT_006316ec + 0x4ee0) = 1.0 / *(float *)(DAT_006316ec + 0x4ee0);
      fVar14 = local_410;
      pfVar18 = (float *)((int)pfVar18 + 0x2d);
      iVar4 = local_3ec;
      goto LAB_004b809d;
    case 1.61149e-43:
      FUN_0053c890(0x1a,pfVar17,DAT_006316ec + 0x4ee4,s_C__Giants_Source_main_readwrls_c_00563174,
                   0x464);
      *(undefined4 *)(DAT_006316ec + 0x4ee8) = *(undefined4 *)((int)pfVar18 + 0x21);
      if (*(float *)(DAT_006316ec + 0x4ee8) == 0.0) {
        *(undefined4 *)(DAT_006316ec + 0x4ee8) = 0x42480000;
      }
      *(float *)(DAT_006316ec + 0x4ee8) = 1.0 / *(float *)(DAT_006316ec + 0x4ee8);
      fVar14 = local_410;
      pfVar18 = (float *)((int)pfVar18 + 0x2d);
      iVar4 = local_3ec;
      goto LAB_004b809d;
    case 1.62551e-43:
      FUN_0053c890(0x1a,pfVar17,DAT_006316ec + 0x4eec,s_C__Giants_Source_main_readwrls_c_00563174,
                   0x46f);
      *(undefined4 *)(DAT_006316ec + 0x4ef0) = *(undefined4 *)((int)pfVar18 + 0x21);
      pfVar17 = (float *)((int)pfVar18 + 0x25);
      if (*(float *)(DAT_006316ec + 0x4ef0) == 0.0) {
        *(undefined4 *)(DAT_006316ec + 0x4ef0) = 0x42480000;
      }
      *(float *)(DAT_006316ec + 0x4ef0) = 1.0 / *(float *)(DAT_006316ec + 0x4ef0);
LAB_004b9412:
      fVar14 = local_410;
      pfVar18 = pfVar17 + 2;
      iVar4 = local_3ec;
      goto LAB_004b809d;
    case 1.63952e-43:
      *(float *)(DAT_006316ec + 0x4ef4) = *pfVar17;
      fVar14 = local_410;
      pfVar18 = (float *)((int)pfVar18 + 5);
      goto LAB_004b809d;
    case 1.65353e-43:
      pfVar18 = pfVar17;
      do {
        pfVar20 = pfVar18;
        pfVar18 = (float *)((int)pfVar20 + 1);
      } while (*(char *)pfVar20 != '\0');
      pcVar24 = (char *)(DAT_006316ec + 0x4efc);
      do {
        cVar2 = *(char *)pfVar17;
        pfVar17 = (float *)((int)pfVar17 + 1);
        *pcVar24 = cVar2;
        pcVar24 = pcVar24 + 1;
      } while (cVar2 != '\0');
      *(float *)(DAT_006316ec + 0x4f38) = *(float *)((int)pfVar20 + 1);
      *(undefined4 *)(DAT_006316ec + 0x4f3c) = *(undefined4 *)((int)pfVar20 + 5);
      *(undefined4 *)(DAT_006316ec + 0x4f40) = *(undefined4 *)((int)pfVar20 + 9);
      *(undefined4 *)(DAT_006316ec + 0x4f4c) = *(undefined4 *)((int)pfVar20 + 0xd);
      *(undefined4 *)(DAT_006316ec + 0x4f54) = *(undefined4 *)((int)pfVar20 + 0x11);
      fVar14 = local_410;
      pfVar18 = (float *)((int)pfVar20 + 0x15);
      goto LAB_004b809d;
    case 1.66755e-43:
      *(float *)(DAT_006316ec + 0x4f74) = *pfVar17;
      *(undefined4 *)(DAT_006316ec + 0x4f88) = *(undefined4 *)((int)pfVar18 + 5);
      *(undefined4 *)(DAT_006316ec + 0x4f90) = *(undefined4 *)((int)pfVar18 + 9);
      *(undefined4 *)(DAT_006316ec + 0x4f98) = *(undefined4 *)((int)pfVar18 + 0xd);
      *(undefined4 *)(DAT_006316ec + 0x4fa0) = *(undefined4 *)((int)pfVar18 + 0x11);
      *(undefined4 *)(DAT_006316ec + 0x4f8c) = *(undefined4 *)((int)pfVar18 + 0x15);
      *(undefined4 *)(DAT_006316ec + 0x4f94) = *(undefined4 *)((int)pfVar18 + 0x19);
      *(undefined4 *)(DAT_006316ec + 0x4f9c) = *(undefined4 *)((int)pfVar18 + 0x1d);
      *(undefined4 *)(DAT_006316ec + 0x4fa4) = *(undefined4 *)((int)pfVar18 + 0x21);
      *(undefined4 *)(DAT_006316ec + 0x4fa8) = *(undefined4 *)((int)pfVar18 + 0x25);
      *(undefined4 *)(DAT_006316ec + 0x4fac) = *(undefined4 *)((int)pfVar18 + 0x29);
      *(undefined4 *)(DAT_006316ec + 0x4fb0) = *(undefined4 *)((int)pfVar18 + 0x2d);
      fVar14 = local_410;
      pfVar18 = (float *)((int)pfVar18 + 0x31);
      goto LAB_004b809d;
    case 1.68156e-43:
      *(float *)(DAT_006316ec + 0x4fb8) = *pfVar17;
      *(undefined4 *)(DAT_006316ec + 0x4fcc) = *(undefined4 *)((int)pfVar18 + 5);
      *(undefined4 *)(DAT_006316ec + 0x4fd4) = *(undefined4 *)((int)pfVar18 + 9);
      *(undefined4 *)(DAT_006316ec + 0x4fdc) = *(undefined4 *)((int)pfVar18 + 0xd);
      *(undefined4 *)(DAT_006316ec + 0x4fe4) = *(undefined4 *)((int)pfVar18 + 0x11);
      *(undefined4 *)(DAT_006316ec + 0x4fd0) = *(undefined4 *)((int)pfVar18 + 0x15);
      *(undefined4 *)(DAT_006316ec + 0x4fd8) = *(undefined4 *)((int)pfVar18 + 0x19);
      *(undefined4 *)(DAT_006316ec + 0x4fe0) = *(undefined4 *)((int)pfVar18 + 0x1d);
      *(undefined4 *)(DAT_006316ec + 0x4fe8) = *(undefined4 *)((int)pfVar18 + 0x21);
      *(undefined4 *)(DAT_006316ec + 0x4fec) = *(undefined4 *)((int)pfVar18 + 0x25);
      *(undefined4 *)(DAT_006316ec + 0x4ff0) = *(undefined4 *)((int)pfVar18 + 0x29);
      *(undefined4 *)(DAT_006316ec + 0x4ff4) = *(undefined4 *)((int)pfVar18 + 0x2d);
      fVar14 = local_410;
      pfVar18 = (float *)((int)pfVar18 + 0x31);
      goto LAB_004b809d;
    case 1.69557e-43:
      local_3f4 = *(undefined4 *)((int)pfVar18 + 5);
      local_3f0 = *(undefined4 *)((int)pfVar18 + 9);
      iVar4 = __ftol();
      uVar10 = __ftol();
      uVar7 = __ftol();
      *(uint *)(DAT_006316ec + 0x505c) = (iVar4 << 8 | uVar10) << 8 | uVar7;
      local_3f4 = *(undefined4 *)((int)pfVar18 + 0x11);
      local_3f0 = *(undefined4 *)((int)pfVar18 + 0x15);
      iVar4 = __ftol();
      uVar10 = __ftol();
      uVar7 = __ftol();
      *(uint *)(DAT_006316ec + 0x5048) = (iVar4 << 8 | uVar10) << 8 | uVar7;
      local_3f4 = *(undefined4 *)((int)pfVar18 + 0x1d);
      local_3f0 = *(undefined4 *)((int)pfVar18 + 0x21);
      iVar4 = __ftol();
      uVar10 = __ftol();
      uVar7 = __ftol();
      *(uint *)(DAT_006316ec + 0x504c) = (iVar4 << 8 | uVar10) << 8 | uVar7;
      local_3f4 = *(undefined4 *)((int)pfVar18 + 0x29);
      local_3f0 = *(undefined4 *)((int)pfVar18 + 0x2d);
      iVar4 = __ftol();
      uVar10 = __ftol();
      uVar7 = __ftol();
      *(uint *)(DAT_006316ec + 0x5050) = (iVar4 << 8 | uVar10) << 8 | uVar7;
      local_3f4 = *(undefined4 *)((int)pfVar18 + 0x35);
      local_3f0 = *(undefined4 *)((int)pfVar18 + 0x39);
      iVar4 = __ftol();
      uVar10 = __ftol();
      uVar7 = __ftol();
      *(uint *)(DAT_006316ec + 0x5054) = (iVar4 << 8 | uVar10) << 8 | uVar7;
      local_3f4 = *(undefined4 *)((int)pfVar18 + 0x41);
      local_3f0 = *(undefined4 *)((int)pfVar18 + 0x45);
      iVar4 = __ftol();
      uVar10 = __ftol();
      uVar7 = __ftol();
      *(uint *)(DAT_006316ec + 0x5058) = (iVar4 << 8 | uVar10) << 8 | uVar7;
      *(undefined4 *)(DAT_006316ec + 0x5060) = *(undefined4 *)((int)pfVar18 + 0x49);
      *(undefined4 *)(DAT_006316ec + 0x5064) = *(undefined4 *)((int)pfVar18 + 0x4d);
      *(undefined4 *)(DAT_006316ec + 0x5068) = *(undefined4 *)((int)pfVar18 + 0x51);
      *(undefined4 *)(DAT_006316ec + 0x506c) = *(undefined4 *)((int)pfVar18 + 0x55);
      *(undefined4 *)(DAT_006316ec + 0x5070) = *(undefined4 *)((int)pfVar18 + 0x59);
      *(undefined4 *)(DAT_006316ec + 0x5074) = 0;
      fVar14 = local_410;
      pfVar18 = (float *)((int)pfVar18 + 0x5d);
      iVar4 = local_3ec;
      goto LAB_004b809d;
    case 1.80768e-43:
      *(float *)(DAT_006316ec + 0x4a7c) = *pfVar17;
      fVar14 = local_410;
      pfVar18 = (float *)((int)pfVar18 + 5);
      goto LAB_004b809d;
    case 1.82169e-43:
      goto switchD_004b80be_caseD_82;
    case 1.84971e-43:
      do {
        cVar2 = *(char *)pfVar20;
        pfVar20 = (float *)((int)pfVar20 + 1);
      } while (cVar2 != '\0');
      if (*(int *)(DAT_006316ec + 0x509c) != 0) {
        mem_free_tagged(*(int *)(DAT_006316ec + 0x509c),s_C__Giants_Source_main_readwrls_c_00563174,
                        0x64c);
      }
      uVar10 = 0xffffffff;
      pfVar18 = pfVar17;
      do {
        if (uVar10 == 0) break;
        uVar10 = uVar10 - 1;
        cVar2 = *(char *)pfVar18;
        pfVar18 = (float *)((int)pfVar18 + 1);
      } while (cVar2 != '\0');
      uVar8 = mem_alloc_tagged(0x1a,~uVar10,s_vopath_00563240,
                               s_C__Giants_Source_main_readwrls_c_00563174,0x64d);
      *(undefined4 *)(DAT_006316ec + 0x509c) = uVar8;
      pcVar24 = *(char **)(DAT_006316ec + 0x509c);
      do {
        cVar2 = *(char *)pfVar17;
        pfVar17 = (float *)((int)pfVar17 + 1);
        *pcVar24 = cVar2;
        pcVar24 = pcVar24 + 1;
      } while (cVar2 != '\0');
    }
    fVar14 = local_410;
    pfVar18 = pfVar20;
    iVar4 = local_3ec;
    goto LAB_004b809d;
  }
  if (((puVar16 != (undefined4 *)0x0) && (piVar15 = (int *)puVar16[0x5c], piVar15 != (int *)0x0)) &&
     ((*piVar15 == 5 && ((piVar15[2] != 0 && (piVar15[5] == 0)))))) {
    uVar8 = mem_alloc_tagged(0x18,piVar15[2] * 0xc,s_flakpts_00563434,
                             s_C__Giants_Source_main_readwrls_c_00563174,0xe2);
    *(undefined4 *)(puVar16[0x5c] + 0x14) = uVar8;
    pfVar18 = local_364;
    pfVar17 = *(float **)(puVar16[0x5c] + 0x14);
    for (uVar10 = *(int *)(puVar16[0x5c] + 8) * 3 & 0x3fffffff; uVar10 != 0; uVar10 = uVar10 - 1) {
      *pfVar17 = *pfVar18;
      pfVar18 = pfVar18 + 1;
      pfVar17 = pfVar17 + 1;
    }
    for (iVar11 = 0; iVar4 = local_3ec, iVar11 != 0; iVar11 = iVar11 + -1) {
      *(undefined1 *)pfVar17 = *(undefined1 *)pfVar18;
      pfVar18 = (float *)((int)pfVar18 + 1);
      pfVar17 = (float *)((int)pfVar17 + 1);
    }
  }
  *(int *)(DAT_006316ec + 0x174) = local_414;
  if (0 < *(int *)(DAT_006316ec + 0x174)) {
    uVar8 = mem_alloc_tagged(0x18,*(int *)(DAT_006316ec + 0x174) * 0x304,s_stobj_005631fc,
                             s_C__Giants_Source_main_readwrls_c_00563174,0x661);
    *(undefined4 *)(DAT_006316ec + 0x178) = uVar8;
    puVar16 = local_40c;
    puVar6 = *(undefined4 **)(DAT_006316ec + 0x178);
    for (uVar10 = *(int *)(DAT_006316ec + 0x174) * 0xc1 & 0x3fffffff; uVar10 != 0;
        uVar10 = uVar10 - 1) {
      *puVar6 = *puVar16;
      puVar16 = puVar16 + 1;
      puVar6 = puVar6 + 1;
    }
    for (iVar11 = 0; iVar4 = local_3ec, iVar11 != 0; iVar11 = iVar11 + -1) {
      *(undefined1 *)puVar6 = *(undefined1 *)puVar16;
      puVar16 = (undefined4 *)((int)puVar16 + 1);
      puVar6 = (undefined4 *)((int)puVar6 + 1);
    }
  }
  mem_free_tagged(local_40c,s_C__Giants_Source_main_readwrls_c_00563174,0x665);
  iVar12 = 0;
  iVar11 = DAT_006316ec;
  do {
    puVar16 = (undefined4 *)(iVar12 + 0x17c + iVar11);
    if (((*(float *)(iVar12 + 0x17c + iVar11) == 0.0) &&
        (*(float *)(iVar12 + 0x180 + iVar11) == 0.0)) &&
       (*(float *)(iVar12 + 0x184 + iVar11) == 0.0)) {
      *puVar16 = *(undefined4 *)(iVar11 + 0x88);
      puVar16[1] = *(undefined4 *)(iVar11 + 0x8c);
      puVar16[2] = *(undefined4 *)(iVar11 + 0x90);
      puVar16[3] = *(undefined4 *)(iVar11 + 0x94);
      iVar11 = DAT_006316ec;
    }
    iVar12 = iVar12 + 0x10;
  } while (iVar12 < 0x30);
  if ((local_418 != (char *)0x0) && (*(int *)(iVar11 + 0x210) == 0)) {
    uVar10 = (int)local_418 * 3;
    *(char **)(iVar11 + 0x20c) = local_418;
    uVar8 = mem_alloc_tagged(0x1a,(int)local_418 * 0xc,s_walist_005633d0,
                             s_C__Giants_Source_main_readwrls_c_00563174,0x68b);
    *(undefined4 *)(DAT_006316ec + 0x210) = uVar8;
    puVar16 = local_180;
    puVar6 = *(undefined4 **)(DAT_006316ec + 0x210);
    for (uVar10 = uVar10 & 0x3fffffff; uVar10 != 0; uVar10 = uVar10 - 1) {
      *puVar6 = *puVar16;
      puVar16 = puVar16 + 1;
      puVar6 = puVar6 + 1;
    }
    for (iVar11 = 0; iVar4 = local_3ec, iVar11 != 0; iVar11 = iVar11 + -1) {
      *(undefined1 *)puVar6 = *(undefined1 *)puVar16;
      puVar16 = (undefined4 *)((int)puVar16 + 1);
      puVar6 = (undefined4 *)((int)puVar6 + 1);
    }
  }
  if (*local_3e8 != '\0') {
    gti_terrain_load(local_3e8);
  }
  mem_free_tagged(local_3fc[0],s_C__Giants_Source_main_readwrls_c_00563174,0x679);
  FUN_0051d850(iVar4);
  iVar4 = (int)local_364 - (int)param_1;
  do {
    cVar2 = *param_1;
    param_1[iVar4] = cVar2;
    param_1 = param_1 + 1;
  } while (cVar2 != '\0');
  uVar10 = 0xffffffff;
  pfVar18 = local_364;
  do {
    if (uVar10 == 0) break;
    uVar10 = uVar10 - 1;
    cVar2 = *(char *)pfVar18;
    pfVar18 = (float *)((int)pfVar18 + 1);
  } while (cVar2 != '\0');
  *(undefined4 *)((int)&uStack_368 + ~uVar10) = DAT_005631f8;
  iVar4 = vfs_load_whole_file(local_364);
  puVar16 = DAT_006313b0;
  if (iVar4 != 0) {
    FUN_0051d750(iVar4,&local_3e8,4);
    if (local_3e8 == (char *)0x1a0002dd) {
      while( true ) {
        local_3fc[0] = (char *)0xffffffff;
        FUN_0051d750(iVar4,local_3fc,4);
        if (local_3fc[0] == (char *)0xffffffff) break;
        iVar11 = FUN_0049d280(local_3fc[0]);
        FUN_0051d750(iVar4,local_3c0,0x18);
        piVar15 = (int *)(iVar11 + 0x400);
        local_400 = 10;
        do {
          if ((iVar11 != 0) && (*piVar15 != 0)) {
            pfVar18 = local_3c0;
            pfVar17 = (float *)(*piVar15 + 0x44);
            for (iVar12 = 6; iVar12 != 0; iVar12 = iVar12 + -1) {
              *pfVar17 = *pfVar18;
              pfVar18 = pfVar18 + 1;
              pfVar17 = pfVar17 + 1;
            }
          }
          piVar15 = piVar15 + 1;
          local_400 = local_400 + -1;
        } while (local_400 != 0);
        while( true ) {
          local_418 = (char *)0xffffffff;
          FUN_0051d750(iVar4,&local_418,4);
          if (local_418 == (char *)0xffffffff) break;
          FUN_0051d750(iVar4,local_3c0,0x18);
          if ((iVar11 != 0) && (iVar12 = *(int *)(iVar11 + 8 + (int)local_418 * 4), iVar12 != 0)) {
            pfVar18 = local_3c0;
            pfVar17 = (float *)(iVar12 + 0xc);
            for (iVar13 = 6; iVar13 != 0; iVar13 = iVar13 + -1) {
              *pfVar17 = *pfVar18;
              pfVar18 = pfVar18 + 1;
              pfVar17 = pfVar17 + 1;
            }
          }
        }
      }
      FUN_0051d850(iVar4);
      puVar16 = DAT_006313b0;
    }
    else {
      FUN_00544b47(&DAT_006552c0,s_Bad_version_for__s_0055e248,local_364);
      FUN_00523aa0(&DAT_006552c0);
      FUN_0051d850(iVar4);
      puVar16 = DAT_006313b0;
    }
  }
  for (; puVar16 != (undefined4 *)0x0; puVar16 = (undefined4 *)*puVar16) {
    local_400 = 0;
    if (0 < (int)puVar16[1]) {
      puVar6 = puVar16 + 2;
      do {
        iVar4 = puVar6[0x100];
        if (iVar4 != 0) {
          local_418 = (char *)0x0;
          do {
            iVar11 = puVar6[(int)(local_418 + 2)];
            if ((((iVar11 != 0) && (*(float *)(iVar11 + 0xc) == *(float *)(iVar11 + 0x18))) &&
                (*(float *)(iVar11 + 0x10) == *(float *)(iVar11 + 0x1c))) &&
               (*(float *)(iVar11 + 0x14) == *(float *)(iVar11 + 0x20))) {
              puVar5 = (undefined4 *)(iVar4 + 0x44);
              puVar22 = (undefined4 *)(iVar11 + 0xc);
              for (iVar12 = 6; iVar12 != 0; iVar12 = iVar12 + -1) {
                *puVar22 = *puVar5;
                puVar5 = puVar5 + 1;
                puVar22 = puVar22 + 1;
              }
            }
            local_418 = local_418 + 1;
          } while ((int)local_418 < 0xfe);
        }
        local_400 = local_400 + 1;
        puVar6 = puVar6 + 0x119;
      } while (local_400 < (int)puVar16[1]);
    }
  }
  _DAT_005a5c9c = param_3;
  return;
switchD_004b80be_caseD_82:
  _strncpy((char *)(DAT_006316ec + 0x507c),(char *)pfVar17,0x20);
  fVar14 = local_410;
  pfVar18 = (float *)((int)pfVar18 + 0x21);
  iVar4 = local_3ec;
  goto LAB_004b809d;
}

