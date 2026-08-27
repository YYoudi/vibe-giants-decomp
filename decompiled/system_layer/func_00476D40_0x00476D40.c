// GiantsRE system layer - func_00476D40
// VA 0x00476D40
// via GhidraMCP headless bulk decompile (project with PS2 renames)


void gti_terrain_load(undefined4 param_1)

{
  short sVar1;
  short sVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  char cVar10;
  int iVar11;
  int iVar12;
  undefined1 *puVar13;
  int *piVar14;
  int *piVar15;
  int iVar16;
  ushort *puVar17;
  int iVar18;
  undefined4 *puVar19;
  int iVar20;
  int local_84;
  undefined1 local_7c;
  undefined1 uStack_7b;
  char cStack_7a;
  undefined1 uStack_79;
  undefined1 local_70 [16];
  int *local_60;
  undefined1 local_5c [12];
  undefined1 local_50 [12];
  undefined1 local_44 [12];
  byte local_38;
  undefined3 uStack_37;
  int local_34;
  int local_30;
  int iStack_2c;
  int iStack_28;
  int iStack_24;
  int local_20 [5];
  undefined1 *local_c;
  int local_8;
  int local_4;
  
  DAT_0059cc40 = (undefined4 *)
                 mem_alloc_tagged(0x12,0x200,&DAT_0055da18,
                                  s_C__Giants_Source_main_makewrld_c_0055d974,0x20e);
  puVar7 = DAT_0059cc40;
  for (iVar11 = 0x80; iVar11 != 0; iVar11 = iVar11 + -1) {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  }
  vfs_fileread_load(param_1,&local_60,&local_34);
  if (local_34 == 0) {
    return;
  }
  iVar11 = *local_60;
  piVar14 = local_60 + 1;
  if (iVar11 == -0x6b69afff) {
    *(undefined4 *)(DAT_006316ec + 0x204) = 0;
  }
  else {
    if ((iVar11 != -0x6b69affe) && (iVar11 != -0x6b69affd)) {
      FUN_00523aa0(s_Bad_version_for_world_data_0055d9fc);
      FUN_005236f0();
      return;
    }
    iVar11 = *piVar14;
    piVar14 = local_60 + 2;
    *(int *)(DAT_006316ec + 0x204) = iVar11;
  }
  if (*(int *)(DAT_006316ec + 0x204) == 0) {
    *(undefined4 *)(DAT_006316ec + 0x208) = 0;
  }
  else {
    uVar5 = mem_alloc_tagged(0x12,*(int *)(DAT_006316ec + 0x204) * 0x38,s_wbboxes_0055d9f4,
                             s_C__Giants_Source_main_makewrld_c_0055d974,0x234);
    *(undefined4 *)(DAT_006316ec + 0x208) = uVar5;
    iVar11 = 0;
    if (0 < *(int *)(DAT_006316ec + 0x204)) {
      iVar20 = 0;
      piVar4 = piVar14;
      do {
        piVar14 = piVar4;
        piVar15 = (int *)(*(int *)(DAT_006316ec + 0x208) + iVar20);
        for (iVar16 = 8; iVar16 != 0; iVar16 = iVar16 + -1) {
          *piVar15 = *piVar14;
          piVar14 = piVar14 + 1;
          piVar15 = piVar15 + 1;
        }
        iVar20 = iVar20 + 0x38;
        *(int *)(*(int *)(DAT_006316ec + 0x208) + -0x18 + iVar20) = piVar4[8];
        *(int *)(*(int *)(DAT_006316ec + 0x208) + -0x14 + iVar20) = piVar4[9];
        piVar14 = piVar4 + 0xe;
        iVar11 = iVar11 + 1;
        *(int *)(*(int *)(DAT_006316ec + 0x208) + -0x10 + iVar20) = piVar4[10];
        *(int *)(*(int *)(DAT_006316ec + 0x208) + -0xc + iVar20) = piVar4[0xb];
        *(int *)(*(int *)(DAT_006316ec + 0x208) + -8 + iVar20) = piVar4[0xc];
        *(int *)(*(int *)(DAT_006316ec + 0x208) + -4 + iVar20) = piVar4[0xd];
        piVar4 = piVar14;
      } while (iVar11 < *(int *)(DAT_006316ec + 0x204));
    }
  }
  *(int *)(DAT_006316ec + 0x1cc) = *piVar14;
  *(int *)(DAT_006316ec + 0x1d0) = piVar14[1];
  *(int *)(DAT_006316ec + 0x1d4) = piVar14[2];
  *(int *)(DAT_006316ec + 0x1d8) = piVar14[3];
  *(int *)(DAT_006316ec + 0x1dc) = piVar14[4];
  *(int *)(DAT_006316ec + 0x1e0) = piVar14[5];
  *(int *)(DAT_006316ec + 0x1c4) = piVar14[6];
  *(float *)(DAT_006316ec + 0x1c8) = 1.0 / *(float *)(DAT_006316ec + 0x1c4);
  *(float *)(DAT_006316ec + 0x1cc) =
       *(float *)(DAT_006316ec + 0x1cc) - *(float *)(DAT_006316ec + 0x1c4);
  *(float *)(DAT_006316ec + 0x1d0) =
       *(float *)(DAT_006316ec + 0x1d0) - *(float *)(DAT_006316ec + 0x1c4);
  *(int *)(DAT_006316ec + 0x1dc) = *(int *)(DAT_006316ec + 0x1dc) + 2;
  *(int *)(DAT_006316ec + 0x1e0) = *(int *)(DAT_006316ec + 0x1e0) + 2;
  local_7c = (undefined1)piVar14[0xb];
  _local_38 = CONCAT31(uStack_37,*(byte *)((int)piVar14 + 0x2d));
  *(uint *)(DAT_006316ec + 0x48) =
       (uint)*(byte *)((int)piVar14 + 0x2e) << 4 | (uint)*(byte *)((int)piVar14 + 0x2d);
  *(uint *)(DAT_006316ec + 0x1c) = CONCAT12(cStack_7a,CONCAT11(uStack_7b,local_7c)) & 0xff;
  *(int *)(DAT_006316ec + 0x40) = piVar14[0xc];
  *(int *)(DAT_006316ec + 0x44) = piVar14[0xd];
  piVar4 = piVar14 + 0xe;
  piVar15 = local_20;
  for (iVar11 = 8; iVar11 != 0; iVar11 = iVar11 + -1) {
    *piVar15 = *piVar4;
    piVar4 = piVar4 + 1;
    piVar15 = piVar15 + 1;
  }
  piVar14 = piVar14 + 0x16;
  *(undefined4 *)(DAT_006316ec + 0x3c) = 0;
  piVar4 = *(int **)(DAT_006316ec + 0x1e4);
  if (piVar4 == (int *)0x0) {
    piVar4 = local_20;
  }
  uVar5 = FUN_0050e3c0(piVar4);
  *(undefined4 *)(DAT_006316ec + 0x4ec4) = uVar5;
  *(undefined4 *)(DAT_006316ec + 0x3c) = *(undefined4 *)(DAT_006316ec + 0x4ec4);
  if (*(int *)(DAT_006316ec + 0x1ec) != 0) {
    uVar5 = FUN_0050e3c0(*(int *)(DAT_006316ec + 0x1ec));
    *(undefined4 *)(DAT_006316ec + 0x4ec8) = uVar5;
  }
  if (*(int *)(DAT_006316ec + 500) != 0) {
    uVar5 = FUN_0050e3c0(*(int *)(DAT_006316ec + 500));
    *(undefined4 *)(DAT_006316ec + 0x4ecc) = uVar5;
  }
  if (*(int *)(DAT_006316ec + 0x4ec4) != 0) {
    puVar17 = (ushort *)(*(int *)(DAT_006316ec + 0x4ec4) + 0x1e);
    *puVar17 = *puVar17 | 0x300;
  }
  if (*(int *)(DAT_006316ec + 0x4ec8) != 0) {
    puVar17 = (ushort *)(*(int *)(DAT_006316ec + 0x4ec8) + 0x1e);
    *puVar17 = *puVar17 | 0x300;
  }
  if (*(int *)(DAT_006316ec + 0x4ecc) != 0) {
    puVar17 = (ushort *)(*(int *)(DAT_006316ec + 0x4ecc) + 0x1e);
    *puVar17 = *puVar17 | 0x300;
  }
  if (*(int *)(DAT_006316ec + 0x4edc) != 0) {
    uVar5 = FUN_0050e3c0(*(int *)(DAT_006316ec + 0x4edc));
    *(undefined4 *)(DAT_006316ec + 0x4ed0) = uVar5;
  }
  if (*(int *)(DAT_006316ec + 0x4ee4) != 0) {
    uVar5 = FUN_0050e3c0(*(int *)(DAT_006316ec + 0x4ee4));
    *(undefined4 *)(DAT_006316ec + 0x4ed4) = uVar5;
  }
  if (*(int *)(DAT_006316ec + 0x4eec) != 0) {
    uVar5 = FUN_0050e3c0(*(int *)(DAT_006316ec + 0x4eec));
    *(undefined4 *)(DAT_006316ec + 0x4ed8) = uVar5;
  }
  puVar7 = *(undefined4 **)(DAT_006316ec + 0x4ed0);
  piVar4 = (int *)(DAT_006316ec + 0x4ed0);
  if ((puVar7 == (undefined4 *)0x0) || (puVar7 == *(undefined4 **)(DAT_006316ec + 0x4ec4))) {
    puVar6 = *(undefined4 **)(DAT_006316ec + 0x4ec4);
    if ((puVar7 == puVar6) && (puVar6 != (undefined4 *)0x0)) {
      iVar11 = mem_alloc_tagged(0x12,0x20,s_ground_bump_texture_0055d960,
                                s_C__Giants_Source_main_makewrld_c_0055d974,0x2c);
      *piVar4 = iVar11;
      FUN_0050e3a0(puVar6);
      puVar7 = puVar6;
      puVar19 = (undefined4 *)*piVar4;
      for (iVar11 = 8; iVar11 != 0; iVar11 = iVar11 + -1) {
        *puVar19 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar19 = puVar19 + 1;
      }
      *(undefined4 **)(*piVar4 + 4) = puVar6;
      *(undefined4 *)(*piVar4 + 0x18) = 2;
      *(ushort *)(*piVar4 + 0x1e) = *(ushort *)(*piVar4 + 0x1e) | 0x410;
      *(ushort *)(*piVar4 + 0x1e) = *(ushort *)(*piVar4 + 0x1e) & 0xfdfe;
    }
  }
  else {
    *(ushort *)((int)puVar7 + 0x1e) = *(ushort *)((int)puVar7 + 0x1e) | 0x110;
    *(undefined4 *)(*(int *)(DAT_006316ec + 0x4ed0) + 0x18) = 2;
  }
  puVar7 = *(undefined4 **)(DAT_006316ec + 0x4ed4);
  piVar4 = (int *)(DAT_006316ec + 0x4ed4);
  if ((puVar7 == (undefined4 *)0x0) || (puVar7 == *(undefined4 **)(DAT_006316ec + 0x4ec8))) {
    puVar6 = *(undefined4 **)(DAT_006316ec + 0x4ec8);
    local_7c = SUB41(puVar6,0);
    uStack_7b = (undefined1)((uint)puVar6 >> 8);
    cStack_7a = (char)((uint)puVar6 >> 0x10);
    uStack_79 = (undefined1)((uint)puVar6 >> 0x18);
    if ((puVar7 == puVar6) && (puVar6 != (undefined4 *)0x0)) {
      iVar11 = mem_alloc_tagged(0x12,0x20,s_ground_bump_texture_0055d960,
                                s_C__Giants_Source_main_makewrld_c_0055d974,0x2c);
      *piVar4 = iVar11;
      FUN_0050e3a0(puVar6);
      puVar7 = (undefined4 *)*piVar4;
      for (iVar11 = 8; iVar11 != 0; iVar11 = iVar11 + -1) {
        *puVar7 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar7 = puVar7 + 1;
      }
      *(uint *)(*piVar4 + 4) = CONCAT13(uStack_79,CONCAT12(cStack_7a,CONCAT11(uStack_7b,local_7c)));
      *(undefined4 *)(*piVar4 + 0x18) = 2;
      *(ushort *)(*piVar4 + 0x1e) = *(ushort *)(*piVar4 + 0x1e) | 0x410;
      *(ushort *)(*piVar4 + 0x1e) = *(ushort *)(*piVar4 + 0x1e) & 0xfdfe;
    }
  }
  else {
    *(ushort *)((int)puVar7 + 0x1e) = *(ushort *)((int)puVar7 + 0x1e) | 0x110;
    *(undefined4 *)(*(int *)(DAT_006316ec + 0x4ed4) + 0x18) = 2;
  }
  puVar7 = *(undefined4 **)(DAT_006316ec + 0x4ed8);
  piVar4 = (int *)(DAT_006316ec + 0x4ed8);
  if ((puVar7 == (undefined4 *)0x0) || (puVar7 == *(undefined4 **)(DAT_006316ec + 0x4ecc))) {
    puVar6 = *(undefined4 **)(DAT_006316ec + 0x4ecc);
    local_7c = SUB41(puVar6,0);
    uStack_7b = (undefined1)((uint)puVar6 >> 8);
    cStack_7a = (char)((uint)puVar6 >> 0x10);
    uStack_79 = (undefined1)((uint)puVar6 >> 0x18);
    if ((puVar7 == puVar6) && (puVar6 != (undefined4 *)0x0)) {
      iVar11 = mem_alloc_tagged(0x12,0x20,s_ground_bump_texture_0055d960,
                                s_C__Giants_Source_main_makewrld_c_0055d974,0x2c);
      *piVar4 = iVar11;
      FUN_0050e3a0(puVar6);
      puVar7 = (undefined4 *)*piVar4;
      for (iVar11 = 8; iVar11 != 0; iVar11 = iVar11 + -1) {
        *puVar7 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar7 = puVar7 + 1;
      }
      *(uint *)(*piVar4 + 4) = CONCAT13(uStack_79,CONCAT12(cStack_7a,CONCAT11(uStack_7b,local_7c)));
      *(undefined4 *)(*piVar4 + 0x18) = 2;
      *(ushort *)(*piVar4 + 0x1e) = *(ushort *)(*piVar4 + 0x1e) | 0x410;
      *(ushort *)(*piVar4 + 0x1e) = *(ushort *)(*piVar4 + 0x1e) & 0xfdfe;
    }
  }
  else {
    *(ushort *)((int)puVar7 + 0x1e) = *(ushort *)((int)puVar7 + 0x1e) | 0x110;
    *(undefined4 *)(*(int *)(DAT_006316ec + 0x4ed8) + 0x18) = 2;
  }
  puVar6 = (undefined4 *)
           mem_alloc_tagged(0x1a,*(int *)(DAT_006316ec + 0x1e0) * *(int *)(DAT_006316ec + 0x1dc) *
                                 0x10,s_World_0055d9ec,s_C__Giants_Source_main_makewrld_c_0055d974,
                            0x2af);
  puVar7 = puVar6;
  for (iVar11 = (*(int *)(DAT_006316ec + 0x1e0) * *(int *)(DAT_006316ec + 0x1dc) & 0xfffffffU) << 2;
      iVar11 != 0; iVar11 = iVar11 + -1) {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  }
  for (iVar11 = 0; iVar11 != 0; iVar11 = iVar11 + -1) {
    *(undefined1 *)puVar7 = 0;
    puVar7 = (undefined4 *)((int)puVar7 + 1);
  }
  iVar20 = 0;
  iVar11 = DAT_006316ec;
  if (0 < *(int *)(DAT_006316ec + 0x1e0)) {
    iVar16 = *(int *)(DAT_006316ec + 0x1dc);
    puVar7 = puVar6;
    do {
      iVar12 = 0;
      if (0 < iVar16) {
        do {
          *puVar7 = 0xc5800000;
          puVar7 = puVar7 + 4;
          iVar12 = iVar12 + 1;
          iVar16 = *(int *)(DAT_006316ec + 0x1dc);
          iVar11 = DAT_006316ec;
        } while (iVar12 < iVar16);
      }
      iVar20 = iVar20 + 1;
    } while (iVar20 < *(int *)(iVar11 + 0x1e0));
  }
  uVar5 = mem_alloc_tagged(0x1a,*(int *)(iVar11 + 0x1e0) << 2,s_YROWS_0055d9e4,
                           s_C__Giants_Source_main_makewrld_c_0055d974,700);
  *(undefined4 *)(DAT_006316ec + 0x10) = uVar5;
  iVar11 = 0;
  if (0 < *(int *)(DAT_006316ec + 0x1e0)) {
    do {
      *(undefined4 **)(*(int *)(DAT_006316ec + 0x10) + iVar11 * 4) =
           puVar6 + *(int *)(DAT_006316ec + 0x1dc) * iVar11 * 4;
      iVar11 = iVar11 + 1;
    } while (iVar11 < *(int *)(DAT_006316ec + 0x1e0));
  }
  uVar5 = mem_alloc_tagged(0x1a,*(int *)(DAT_006316ec + 0x1e0) << 2,&DAT_0055d9e0,
                           s_C__Giants_Source_main_makewrld_c_0055d974,0x2c1);
  *(undefined4 *)(DAT_006316ec + 0x14) = uVar5;
  uVar5 = mem_alloc_tagged(0x1a,*(int *)(DAT_006316ec + 0x1e0) << 2,&DAT_0055d9dc,
                           s_C__Giants_Source_main_makewrld_c_0055d974,0x2c2);
  iVar16 = 1;
  *(undefined4 *)(DAT_006316ec + 0x18) = uVar5;
  iVar20 = 1;
  iVar11 = DAT_006316ec;
  if (1 < *(int *)(DAT_006316ec + 0x1e0) + -1) {
    do {
      cVar10 = (char)*piVar14;
      piVar14 = (int *)((int)piVar14 + 1);
      if (cVar10 < '\0') {
        iVar20 = iVar20 - cVar10;
        iVar12 = *(int *)(iVar11 + 0x1dc);
        if (iVar12 + -1 <= iVar20) {
          do {
            iVar20 = iVar20 + (2 - iVar12);
            iVar16 = iVar16 + 1;
          } while (iVar12 + -1 <= iVar20);
        }
      }
      else {
        local_84 = cVar10 + 1;
        piVar4 = piVar14;
        if (0 < local_84) {
          do {
            piVar15 = (int *)((int)piVar4 + 5);
            puVar6[(*(int *)(iVar11 + 0x1dc) * iVar16 + iVar20) * 4] = *piVar4;
            *(ushort *)(puVar6 + (*(int *)(DAT_006316ec + 0x1dc) * iVar16 + iVar20) * 4 + 3) =
                 (ushort)*(byte *)(piVar4 + 1);
            piVar14 = piVar15;
            if ((*(uint *)(DAT_006316ec + 0x1c) & 2) != 0) {
              if ((*(uint *)(DAT_006316ec + 0x1c) & 4) == 0) {
                piVar14 = piVar4 + 2;
                local_7c = (undefined1)*(undefined2 *)piVar15;
                uStack_7b = (undefined1)((ushort)*(undefined2 *)piVar15 >> 8);
                cStack_7a = *(char *)((int)piVar4 + 7);
                cVar10 = -1;
              }
              else {
                piVar14 = (int *)((int)piVar4 + 9);
                local_7c = (undefined1)*(undefined2 *)piVar15;
                uStack_7b = (undefined1)((ushort)*(undefined2 *)piVar15 >> 8);
                cVar10 = (char)piVar4[2];
                cStack_7a = *(char *)((int)piVar4 + 7);
              }
              puVar6[(*(int *)(DAT_006316ec + 0x1dc) * iVar16 + iVar20) * 4 + 1] =
                   ((uint)CONCAT11(cVar10,local_7c) << 8 |
                   CONCAT12(uStack_79,CONCAT11(cStack_7a,uStack_7b)) & 0xff) << 8 |
                   CONCAT11(uStack_79,cStack_7a) & 0xff;
            }
            iVar20 = iVar20 + 1;
            if (*(int *)(DAT_006316ec + 0x1dc) + -1 <= iVar20) {
              iVar20 = 1;
              iVar16 = iVar16 + 1;
            }
            local_84 = local_84 + -1;
            piVar4 = piVar14;
            iVar11 = DAT_006316ec;
          } while (local_84 != 0);
        }
      }
    } while (iVar16 < *(int *)(iVar11 + 0x1e0) + -1);
  }
  *(undefined4 **)(iVar11 + 0xc) = puVar6;
  iVar20 = 0;
  iVar11 = DAT_006316ec;
  if (0 < *(int *)(DAT_006316ec + 0x1e0)) {
    do {
      *(undefined4 *)(*(int *)(iVar11 + 0x18) + iVar20 * 4) = 0xffffffff;
      piVar14 = *(int **)(*(int *)(DAT_006316ec + 0x10) + iVar20 * 4);
      iVar16 = 0;
      if (0 < *(int *)(DAT_006316ec + 0x1dc)) {
        do {
          if (*piVar14 != -0x3a800000) break;
          iVar16 = iVar16 + 1;
          piVar14 = piVar14 + 4;
        } while (iVar16 < *(int *)(DAT_006316ec + 0x1dc));
      }
      *(int *)(*(int *)(DAT_006316ec + 0x14) + iVar20 * 4) = iVar16;
      iVar11 = DAT_006316ec;
      if (iVar16 < *(int *)(DAT_006316ec + 0x1dc)) {
        do {
          if (*piVar14 != -0x3a800000) {
            *(int *)(*(int *)(iVar11 + 0x18) + iVar20 * 4) = iVar16;
            iVar11 = DAT_006316ec;
          }
          iVar16 = iVar16 + 1;
          piVar14 = piVar14 + 4;
        } while (iVar16 < *(int *)(iVar11 + 0x1dc));
      }
      iVar20 = iVar20 + 1;
    } while (iVar20 < *(int *)(iVar11 + 0x1e0));
  }
  FUN_0053a3c0(local_60);
  local_84 = 0;
  iVar11 = DAT_006316ec;
  if (0 < *(int *)(DAT_006316ec + 0x1e0)) {
    do {
      iVar20 = 0;
      if (0 < *(int *)(iVar11 + 0x1dc)) {
        puVar17 = (ushort *)(*(int *)(*(int *)(iVar11 + 0x10) + local_84 * 4) + 0xc);
        do {
          if (*puVar17 == 0) goto switchD_00477728_default;
          FUN_00458ab0(iVar20,local_84,local_5c);
          FUN_00458ab0(iVar20 + 1,local_84,local_44);
          FUN_00458ab0(iVar20,local_84 + 1,&local_7c);
          FUN_00458ab0(iVar20 + 1,local_84 + 1,local_50);
          switch(*puVar17 & 7) {
          case 1:
            puVar9 = local_5c;
            puVar13 = &local_7c;
            puVar8 = local_44;
            break;
          case 2:
            puVar9 = local_50;
            puVar13 = local_44;
            puVar8 = &local_7c;
            break;
          case 3:
            puVar9 = local_44;
            puVar13 = local_5c;
            puVar8 = local_50;
            break;
          case 5:
            FUN_00454620(local_5c,local_50,&local_7c,local_70);
            puVar9 = local_44;
            puVar13 = local_5c;
            puVar8 = local_50;
            goto LAB_00477785;
          case 6:
            FUN_00454620(local_44,&local_7c,local_5c,local_70);
            puVar9 = local_50;
            puVar13 = local_44;
            puVar8 = &local_7c;
LAB_00477785:
            FUN_00454620(puVar8,puVar13,puVar9,&local_30);
            sVar1 = FUN_004778f0(local_70);
            sVar2 = FUN_004778f0(&local_30);
            goto LAB_0047781d;
          case 7:
            *puVar17 = *puVar17 & 0xfffc | 4;
          case 4:
            puVar9 = &local_7c;
            puVar13 = local_50;
            puVar8 = local_5c;
            break;
          default:
            goto switchD_00477728_default;
          }
          FUN_00454620(puVar8,puVar13,puVar9,local_70);
          sVar1 = FUN_004778f0(local_70);
          sVar2 = FUN_004778f0(0);
LAB_0047781d:
          *puVar17 = *puVar17 | (sVar1 + sVar2 * 9) * 8;
switchD_00477728_default:
          iVar20 = iVar20 + 1;
          puVar17 = puVar17 + 8;
          iVar11 = DAT_006316ec;
        } while (iVar20 < *(int *)(DAT_006316ec + 0x1dc));
      }
      local_84 = local_84 + 1;
    } while (local_84 < *(int *)(iVar11 + 0x1e0));
  }
  *(undefined4 *)(iVar11 + 0x20) = 0;
  *(int *)(DAT_006316ec + 0x24) = *(int *)(DAT_006316ec + 0x1dc) + -2;
  *(undefined4 *)(DAT_006316ec + 0x28) = 0;
  *(int *)(DAT_006316ec + 0x2c) = *(int *)(DAT_006316ec + 0x1e0) + -2;
  *(undefined4 *)(DAT_006316ec + 0x30) = 0xc2746666;
  *(undefined4 *)(DAT_006316ec + 0x34) = *(undefined4 *)(DAT_006316ec + 0x1d8);
  *(undefined4 *)(DAT_006316ec + 0x4ef8) = 1;
  FUN_00436960();
  local_8 = 0;
  iVar11 = DAT_006316ec;
  if (0 < *(int *)(DAT_006316ec + 0x1e0)) {
    do {
      iVar16 = 0;
      iVar20 = local_8;
      if (0 < *(int *)(iVar11 + 0x1dc)) {
        local_c = (undefined1 *)(*(int *)(*(int *)(iVar11 + 0x10) + local_8 * 4) + 0xe);
        do {
          local_20[0] = 0;
          local_34 = 0x476c79;
          local_30 = iVar16;
          iStack_2c = iVar20;
          iStack_28 = iVar16;
          iStack_24 = iVar20;
          iVar11 = FUN_004768e0();
          if (iVar11 == 0) {
            *local_c = 1;
            iVar11 = DAT_006316ec;
          }
          else {
            local_4 = -1;
            iVar11 = DAT_006316ec;
            do {
              iVar12 = -1;
              iVar18 = local_4 + iVar16;
              iVar20 = iVar20 + -1;
              do {
                if ((((-1 < iVar18) && (-1 < iVar20)) && (iVar18 < *(int *)(iVar11 + 0x1dc))) &&
                   (iVar20 < *(int *)(iVar11 + 0x1e0))) {
                  local_20[0] = 1;
                  iStack_24 = local_8;
                  local_34 = 0x476cc9;
                  local_30 = iVar18;
                  iStack_2c = iVar20;
                  iStack_28 = iVar16;
                  iVar3 = FUN_004768e0();
                  iVar11 = DAT_006316ec;
                  if (iVar3 == 0) {
                    *local_c = 1;
                    iVar11 = DAT_006316ec;
                    break;
                  }
                }
                iVar12 = iVar12 + 1;
                iVar20 = iVar20 + 1;
              } while (iVar12 < 2);
              local_4 = local_4 + 1;
              iVar20 = local_8;
            } while (local_4 < 2);
          }
          iVar16 = iVar16 + 1;
          local_c = local_c + 0x10;
        } while (iVar16 < *(int *)(iVar11 + 0x1dc));
      }
      local_8 = iVar20 + 1;
    } while (local_8 < *(int *)(iVar11 + 0x1e0));
  }
  return;
}

