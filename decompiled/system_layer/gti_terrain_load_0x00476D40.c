// GiantsRE system layer - gti_terrain_load
// VA 0x00476D40 (ghidra name was gti_terrain_load)
// provenance: runtime anchors in scripts/re_db.json + PS2 symbols


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void gti_terrain_load(undefined4 param_1)

{
  float fVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  char cVar11;
  int iVar12;
  int iVar13;
  undefined1 *puVar14;
  int *piVar15;
  int *piVar16;
  int iVar17;
  ushort *puVar18;
  int iVar19;
  undefined4 *puVar20;
  int iVar21;
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
  puVar8 = DAT_0059cc40;
  for (iVar12 = 0x80; iVar12 != 0; iVar12 = iVar12 + -1) {
    *puVar8 = 0;
    puVar8 = puVar8 + 1;
  }
  vfs_fileread_load(param_1,&local_60,&local_34);
  if (local_34 == 0) {
    return;
  }
  iVar12 = *local_60;
  piVar15 = local_60 + 1;
  if (iVar12 == -0x6b69afff) {
    *(undefined4 *)(DAT_006316ec + 0x204) = 0;
  }
  else {
    if ((iVar12 != -0x6b69affe) && (iVar12 != -0x6b69affd)) {
      FUN_00523aa0(s_Bad_version_for_world_data_0055d9fc);
      FUN_005236f0();
      return;
    }
    iVar12 = *piVar15;
    piVar15 = local_60 + 2;
    *(int *)(DAT_006316ec + 0x204) = iVar12;
  }
  if (*(int *)(DAT_006316ec + 0x204) == 0) {
    *(undefined4 *)(DAT_006316ec + 0x208) = 0;
  }
  else {
    uVar6 = mem_alloc_tagged(0x12,*(int *)(DAT_006316ec + 0x204) * 0x38,s_wbboxes_0055d9f4,
                             s_C__Giants_Source_main_makewrld_c_0055d974,0x234);
    *(undefined4 *)(DAT_006316ec + 0x208) = uVar6;
    iVar12 = 0;
    if (0 < *(int *)(DAT_006316ec + 0x204)) {
      iVar21 = 0;
      piVar5 = piVar15;
      do {
        piVar15 = piVar5;
        piVar16 = (int *)(*(int *)(DAT_006316ec + 0x208) + iVar21);
        for (iVar17 = 8; iVar17 != 0; iVar17 = iVar17 + -1) {
          *piVar16 = *piVar15;
          piVar15 = piVar15 + 1;
          piVar16 = piVar16 + 1;
        }
        iVar21 = iVar21 + 0x38;
        *(int *)(*(int *)(DAT_006316ec + 0x208) + -0x18 + iVar21) = piVar5[8];
        *(int *)(*(int *)(DAT_006316ec + 0x208) + -0x14 + iVar21) = piVar5[9];
        piVar15 = piVar5 + 0xe;
        iVar12 = iVar12 + 1;
        *(int *)(*(int *)(DAT_006316ec + 0x208) + -0x10 + iVar21) = piVar5[10];
        *(int *)(*(int *)(DAT_006316ec + 0x208) + -0xc + iVar21) = piVar5[0xb];
        *(int *)(*(int *)(DAT_006316ec + 0x208) + -8 + iVar21) = piVar5[0xc];
        *(int *)(*(int *)(DAT_006316ec + 0x208) + -4 + iVar21) = piVar5[0xd];
        piVar5 = piVar15;
      } while (iVar12 < *(int *)(DAT_006316ec + 0x204));
    }
  }
  *(int *)(DAT_006316ec + 0x1cc) = *piVar15;
  *(int *)(DAT_006316ec + 0x1d0) = piVar15[1];
  *(int *)(DAT_006316ec + 0x1d4) = piVar15[2];
  *(int *)(DAT_006316ec + 0x1d8) = piVar15[3];
  *(int *)(DAT_006316ec + 0x1dc) = piVar15[4];
  fVar1 = _DAT_005522c0;
  *(int *)(DAT_006316ec + 0x1e0) = piVar15[5];
  *(int *)(DAT_006316ec + 0x1c4) = piVar15[6];
  *(float *)(DAT_006316ec + 0x1c8) = fVar1 / *(float *)(DAT_006316ec + 0x1c4);
  *(float *)(DAT_006316ec + 0x1cc) =
       *(float *)(DAT_006316ec + 0x1cc) - *(float *)(DAT_006316ec + 0x1c4);
  *(float *)(DAT_006316ec + 0x1d0) =
       *(float *)(DAT_006316ec + 0x1d0) - *(float *)(DAT_006316ec + 0x1c4);
  *(int *)(DAT_006316ec + 0x1dc) = *(int *)(DAT_006316ec + 0x1dc) + 2;
  *(int *)(DAT_006316ec + 0x1e0) = *(int *)(DAT_006316ec + 0x1e0) + 2;
  local_7c = (undefined1)piVar15[0xb];
  _local_38 = CONCAT31(uStack_37,*(byte *)((int)piVar15 + 0x2d));
  *(uint *)(DAT_006316ec + 0x48) =
       (uint)*(byte *)((int)piVar15 + 0x2e) << 4 | (uint)*(byte *)((int)piVar15 + 0x2d);
  *(uint *)(DAT_006316ec + 0x1c) = CONCAT12(cStack_7a,CONCAT11(uStack_7b,local_7c)) & 0xff;
  *(int *)(DAT_006316ec + 0x40) = piVar15[0xc];
  *(int *)(DAT_006316ec + 0x44) = piVar15[0xd];
  piVar5 = piVar15 + 0xe;
  piVar16 = local_20;
  for (iVar12 = 8; iVar12 != 0; iVar12 = iVar12 + -1) {
    *piVar16 = *piVar5;
    piVar5 = piVar5 + 1;
    piVar16 = piVar16 + 1;
  }
  piVar15 = piVar15 + 0x16;
  *(undefined4 *)(DAT_006316ec + 0x3c) = 0;
  piVar5 = *(int **)(DAT_006316ec + 0x1e4);
  if (piVar5 == (int *)0x0) {
    piVar5 = local_20;
  }
  uVar6 = FUN_0050e3c0(piVar5);
  *(undefined4 *)(DAT_006316ec + 0x4ec4) = uVar6;
  *(undefined4 *)(DAT_006316ec + 0x3c) = *(undefined4 *)(DAT_006316ec + 0x4ec4);
  if (*(int *)(DAT_006316ec + 0x1ec) != 0) {
    uVar6 = FUN_0050e3c0(*(int *)(DAT_006316ec + 0x1ec));
    *(undefined4 *)(DAT_006316ec + 0x4ec8) = uVar6;
  }
  if (*(int *)(DAT_006316ec + 500) != 0) {
    uVar6 = FUN_0050e3c0(*(int *)(DAT_006316ec + 500));
    *(undefined4 *)(DAT_006316ec + 0x4ecc) = uVar6;
  }
  if (*(int *)(DAT_006316ec + 0x4ec4) != 0) {
    puVar18 = (ushort *)(*(int *)(DAT_006316ec + 0x4ec4) + 0x1e);
    *puVar18 = *puVar18 | 0x300;
  }
  if (*(int *)(DAT_006316ec + 0x4ec8) != 0) {
    puVar18 = (ushort *)(*(int *)(DAT_006316ec + 0x4ec8) + 0x1e);
    *puVar18 = *puVar18 | 0x300;
  }
  if (*(int *)(DAT_006316ec + 0x4ecc) != 0) {
    puVar18 = (ushort *)(*(int *)(DAT_006316ec + 0x4ecc) + 0x1e);
    *puVar18 = *puVar18 | 0x300;
  }
  if (*(int *)(DAT_006316ec + 0x4edc) != 0) {
    uVar6 = FUN_0050e3c0(*(int *)(DAT_006316ec + 0x4edc));
    *(undefined4 *)(DAT_006316ec + 0x4ed0) = uVar6;
  }
  if (*(int *)(DAT_006316ec + 0x4ee4) != 0) {
    uVar6 = FUN_0050e3c0(*(int *)(DAT_006316ec + 0x4ee4));
    *(undefined4 *)(DAT_006316ec + 0x4ed4) = uVar6;
  }
  if (*(int *)(DAT_006316ec + 0x4eec) != 0) {
    uVar6 = FUN_0050e3c0(*(int *)(DAT_006316ec + 0x4eec));
    *(undefined4 *)(DAT_006316ec + 0x4ed8) = uVar6;
  }
  puVar8 = *(undefined4 **)(DAT_006316ec + 0x4ed0);
  piVar5 = (int *)(DAT_006316ec + 0x4ed0);
  if ((puVar8 == (undefined4 *)0x0) || (puVar8 == *(undefined4 **)(DAT_006316ec + 0x4ec4))) {
    puVar7 = *(undefined4 **)(DAT_006316ec + 0x4ec4);
    if ((puVar8 == puVar7) && (puVar7 != (undefined4 *)0x0)) {
      iVar12 = mem_alloc_tagged(0x12,0x20,s_ground_bump_texture_0055d960,
                                s_C__Giants_Source_main_makewrld_c_0055d974,0x2c);
      *piVar5 = iVar12;
      FUN_0050e3a0(puVar7);
      puVar8 = puVar7;
      puVar20 = (undefined4 *)*piVar5;
      for (iVar12 = 8; iVar12 != 0; iVar12 = iVar12 + -1) {
        *puVar20 = *puVar8;
        puVar8 = puVar8 + 1;
        puVar20 = puVar20 + 1;
      }
      *(undefined4 **)(*piVar5 + 4) = puVar7;
      *(undefined4 *)(*piVar5 + 0x18) = 2;
      *(ushort *)(*piVar5 + 0x1e) = *(ushort *)(*piVar5 + 0x1e) | 0x410;
      *(ushort *)(*piVar5 + 0x1e) = *(ushort *)(*piVar5 + 0x1e) & 0xfdfe;
    }
  }
  else {
    *(ushort *)((int)puVar8 + 0x1e) = *(ushort *)((int)puVar8 + 0x1e) | 0x110;
    *(undefined4 *)(*(int *)(DAT_006316ec + 0x4ed0) + 0x18) = 2;
  }
  puVar8 = *(undefined4 **)(DAT_006316ec + 0x4ed4);
  piVar5 = (int *)(DAT_006316ec + 0x4ed4);
  if ((puVar8 == (undefined4 *)0x0) || (puVar8 == *(undefined4 **)(DAT_006316ec + 0x4ec8))) {
    puVar7 = *(undefined4 **)(DAT_006316ec + 0x4ec8);
    local_7c = SUB41(puVar7,0);
    uStack_7b = (undefined1)((uint)puVar7 >> 8);
    cStack_7a = (char)((uint)puVar7 >> 0x10);
    uStack_79 = (undefined1)((uint)puVar7 >> 0x18);
    if ((puVar8 == puVar7) && (puVar7 != (undefined4 *)0x0)) {
      iVar12 = mem_alloc_tagged(0x12,0x20,s_ground_bump_texture_0055d960,
                                s_C__Giants_Source_main_makewrld_c_0055d974,0x2c);
      *piVar5 = iVar12;
      FUN_0050e3a0(puVar7);
      puVar8 = (undefined4 *)*piVar5;
      for (iVar12 = 8; iVar12 != 0; iVar12 = iVar12 + -1) {
        *puVar8 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar8 = puVar8 + 1;
      }
      *(uint *)(*piVar5 + 4) = CONCAT13(uStack_79,CONCAT12(cStack_7a,CONCAT11(uStack_7b,local_7c)));
      *(undefined4 *)(*piVar5 + 0x18) = 2;
      *(ushort *)(*piVar5 + 0x1e) = *(ushort *)(*piVar5 + 0x1e) | 0x410;
      *(ushort *)(*piVar5 + 0x1e) = *(ushort *)(*piVar5 + 0x1e) & 0xfdfe;
    }
  }
  else {
    *(ushort *)((int)puVar8 + 0x1e) = *(ushort *)((int)puVar8 + 0x1e) | 0x110;
    *(undefined4 *)(*(int *)(DAT_006316ec + 0x4ed4) + 0x18) = 2;
  }
  puVar8 = *(undefined4 **)(DAT_006316ec + 0x4ed8);
  piVar5 = (int *)(DAT_006316ec + 0x4ed8);
  if ((puVar8 == (undefined4 *)0x0) || (puVar8 == *(undefined4 **)(DAT_006316ec + 0x4ecc))) {
    puVar7 = *(undefined4 **)(DAT_006316ec + 0x4ecc);
    local_7c = SUB41(puVar7,0);
    uStack_7b = (undefined1)((uint)puVar7 >> 8);
    cStack_7a = (char)((uint)puVar7 >> 0x10);
    uStack_79 = (undefined1)((uint)puVar7 >> 0x18);
    if ((puVar8 == puVar7) && (puVar7 != (undefined4 *)0x0)) {
      iVar12 = mem_alloc_tagged(0x12,0x20,s_ground_bump_texture_0055d960,
                                s_C__Giants_Source_main_makewrld_c_0055d974,0x2c);
      *piVar5 = iVar12;
      FUN_0050e3a0(puVar7);
      puVar8 = (undefined4 *)*piVar5;
      for (iVar12 = 8; iVar12 != 0; iVar12 = iVar12 + -1) {
        *puVar8 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar8 = puVar8 + 1;
      }
      *(uint *)(*piVar5 + 4) = CONCAT13(uStack_79,CONCAT12(cStack_7a,CONCAT11(uStack_7b,local_7c)));
      *(undefined4 *)(*piVar5 + 0x18) = 2;
      *(ushort *)(*piVar5 + 0x1e) = *(ushort *)(*piVar5 + 0x1e) | 0x410;
      *(ushort *)(*piVar5 + 0x1e) = *(ushort *)(*piVar5 + 0x1e) & 0xfdfe;
    }
  }
  else {
    *(ushort *)((int)puVar8 + 0x1e) = *(ushort *)((int)puVar8 + 0x1e) | 0x110;
    *(undefined4 *)(*(int *)(DAT_006316ec + 0x4ed8) + 0x18) = 2;
  }
  puVar7 = (undefined4 *)
           mem_alloc_tagged(0x1a,*(int *)(DAT_006316ec + 0x1e0) * *(int *)(DAT_006316ec + 0x1dc) *
                                 0x10,s_World_0055d9ec,s_C__Giants_Source_main_makewrld_c_0055d974,
                            0x2af);
  puVar8 = puVar7;
  for (iVar12 = (*(int *)(DAT_006316ec + 0x1e0) * *(int *)(DAT_006316ec + 0x1dc) & 0xfffffffU) << 2;
      iVar12 != 0; iVar12 = iVar12 + -1) {
    *puVar8 = 0;
    puVar8 = puVar8 + 1;
  }
  for (iVar12 = 0; iVar12 != 0; iVar12 = iVar12 + -1) {
    *(undefined1 *)puVar8 = 0;
    puVar8 = (undefined4 *)((int)puVar8 + 1);
  }
  iVar21 = 0;
  iVar12 = DAT_006316ec;
  if (0 < *(int *)(DAT_006316ec + 0x1e0)) {
    iVar17 = *(int *)(DAT_006316ec + 0x1dc);
    puVar8 = puVar7;
    do {
      iVar13 = 0;
      if (0 < iVar17) {
        do {
          *puVar8 = 0xc5800000;
          puVar8 = puVar8 + 4;
          iVar13 = iVar13 + 1;
          iVar17 = *(int *)(DAT_006316ec + 0x1dc);
          iVar12 = DAT_006316ec;
        } while (iVar13 < iVar17);
      }
      iVar21 = iVar21 + 1;
    } while (iVar21 < *(int *)(iVar12 + 0x1e0));
  }
  uVar6 = mem_alloc_tagged(0x1a,*(int *)(iVar12 + 0x1e0) << 2,s_YROWS_0055d9e4,
                           s_C__Giants_Source_main_makewrld_c_0055d974,700);
  *(undefined4 *)(DAT_006316ec + 0x10) = uVar6;
  iVar12 = 0;
  if (0 < *(int *)(DAT_006316ec + 0x1e0)) {
    do {
      *(undefined4 **)(*(int *)(DAT_006316ec + 0x10) + iVar12 * 4) =
           puVar7 + *(int *)(DAT_006316ec + 0x1dc) * iVar12 * 4;
      iVar12 = iVar12 + 1;
    } while (iVar12 < *(int *)(DAT_006316ec + 0x1e0));
  }
  uVar6 = mem_alloc_tagged(0x1a,*(int *)(DAT_006316ec + 0x1e0) << 2,&DAT_0055d9e0,
                           s_C__Giants_Source_main_makewrld_c_0055d974,0x2c1);
  *(undefined4 *)(DAT_006316ec + 0x14) = uVar6;
  uVar6 = mem_alloc_tagged(0x1a,*(int *)(DAT_006316ec + 0x1e0) << 2,&DAT_0055d9dc,
                           s_C__Giants_Source_main_makewrld_c_0055d974,0x2c2);
  iVar17 = 1;
  *(undefined4 *)(DAT_006316ec + 0x18) = uVar6;
  iVar21 = 1;
  iVar12 = DAT_006316ec;
  if (1 < *(int *)(DAT_006316ec + 0x1e0) + -1) {
    do {
      cVar11 = (char)*piVar15;
      piVar15 = (int *)((int)piVar15 + 1);
      if (cVar11 < '\0') {
        iVar21 = iVar21 - cVar11;
        iVar13 = *(int *)(iVar12 + 0x1dc);
        if (iVar13 + -1 <= iVar21) {
          do {
            iVar21 = iVar21 + (2 - iVar13);
            iVar17 = iVar17 + 1;
          } while (iVar13 + -1 <= iVar21);
        }
      }
      else {
        local_84 = cVar11 + 1;
        piVar5 = piVar15;
        if (0 < local_84) {
          do {
            piVar16 = (int *)((int)piVar5 + 5);
            puVar7[(*(int *)(iVar12 + 0x1dc) * iVar17 + iVar21) * 4] = *piVar5;
            *(ushort *)(puVar7 + (*(int *)(DAT_006316ec + 0x1dc) * iVar17 + iVar21) * 4 + 3) =
                 (ushort)*(byte *)(piVar5 + 1);
            piVar15 = piVar16;
            if ((*(uint *)(DAT_006316ec + 0x1c) & 2) != 0) {
              if ((*(uint *)(DAT_006316ec + 0x1c) & 4) == 0) {
                piVar15 = piVar5 + 2;
                local_7c = (undefined1)*(undefined2 *)piVar16;
                uStack_7b = (undefined1)((ushort)*(undefined2 *)piVar16 >> 8);
                cStack_7a = *(char *)((int)piVar5 + 7);
                cVar11 = -1;
              }
              else {
                piVar15 = (int *)((int)piVar5 + 9);
                local_7c = (undefined1)*(undefined2 *)piVar16;
                uStack_7b = (undefined1)((ushort)*(undefined2 *)piVar16 >> 8);
                cVar11 = (char)piVar5[2];
                cStack_7a = *(char *)((int)piVar5 + 7);
              }
              puVar7[(*(int *)(DAT_006316ec + 0x1dc) * iVar17 + iVar21) * 4 + 1] =
                   ((uint)CONCAT11(cVar11,local_7c) << 8 |
                   CONCAT12(uStack_79,CONCAT11(cStack_7a,uStack_7b)) & 0xff) << 8 |
                   CONCAT11(uStack_79,cStack_7a) & 0xff;
            }
            iVar21 = iVar21 + 1;
            if (*(int *)(DAT_006316ec + 0x1dc) + -1 <= iVar21) {
              iVar21 = 1;
              iVar17 = iVar17 + 1;
            }
            local_84 = local_84 + -1;
            piVar5 = piVar15;
            iVar12 = DAT_006316ec;
          } while (local_84 != 0);
        }
      }
    } while (iVar17 < *(int *)(iVar12 + 0x1e0) + -1);
  }
  *(undefined4 **)(iVar12 + 0xc) = puVar7;
  iVar21 = 0;
  iVar12 = DAT_006316ec;
  if (0 < *(int *)(DAT_006316ec + 0x1e0)) {
    do {
      *(undefined4 *)(*(int *)(iVar12 + 0x18) + iVar21 * 4) = 0xffffffff;
      piVar15 = *(int **)(*(int *)(DAT_006316ec + 0x10) + iVar21 * 4);
      iVar17 = 0;
      if (0 < *(int *)(DAT_006316ec + 0x1dc)) {
        do {
          if (*piVar15 != -0x3a800000) break;
          iVar17 = iVar17 + 1;
          piVar15 = piVar15 + 4;
        } while (iVar17 < *(int *)(DAT_006316ec + 0x1dc));
      }
      *(int *)(*(int *)(DAT_006316ec + 0x14) + iVar21 * 4) = iVar17;
      iVar12 = DAT_006316ec;
      if (iVar17 < *(int *)(DAT_006316ec + 0x1dc)) {
        do {
          if (*piVar15 != -0x3a800000) {
            *(int *)(*(int *)(iVar12 + 0x18) + iVar21 * 4) = iVar17;
            iVar12 = DAT_006316ec;
          }
          iVar17 = iVar17 + 1;
          piVar15 = piVar15 + 4;
        } while (iVar17 < *(int *)(iVar12 + 0x1dc));
      }
      iVar21 = iVar21 + 1;
    } while (iVar21 < *(int *)(iVar12 + 0x1e0));
  }
  FUN_0053a3c0(local_60);
  local_84 = 0;
  iVar12 = DAT_006316ec;
  if (0 < *(int *)(DAT_006316ec + 0x1e0)) {
    do {
      iVar21 = 0;
      if (0 < *(int *)(iVar12 + 0x1dc)) {
        puVar18 = (ushort *)(*(int *)(*(int *)(iVar12 + 0x10) + local_84 * 4) + 0xc);
        do {
          if (*puVar18 == 0) goto switchD_00477728_default;
          FUN_00458ab0(iVar21,local_84,local_5c);
          FUN_00458ab0(iVar21 + 1,local_84,local_44);
          FUN_00458ab0(iVar21,local_84 + 1,&local_7c);
          FUN_00458ab0(iVar21 + 1,local_84 + 1,local_50);
          switch(*puVar18 & 7) {
          case 1:
            puVar10 = local_5c;
            puVar14 = &local_7c;
            puVar9 = local_44;
            break;
          case 2:
            puVar10 = local_50;
            puVar14 = local_44;
            puVar9 = &local_7c;
            break;
          case 3:
            puVar10 = local_44;
            puVar14 = local_5c;
            puVar9 = local_50;
            break;
          case 5:
            FUN_00454620(local_5c,local_50,&local_7c,local_70);
            puVar10 = local_44;
            puVar14 = local_5c;
            puVar9 = local_50;
            goto LAB_00477785;
          case 6:
            FUN_00454620(local_44,&local_7c,local_5c,local_70);
            puVar10 = local_50;
            puVar14 = local_44;
            puVar9 = &local_7c;
LAB_00477785:
            FUN_00454620(puVar9,puVar14,puVar10,&local_30);
            sVar2 = FUN_004778f0(local_70);
            sVar3 = FUN_004778f0(&local_30);
            goto LAB_0047781d;
          case 7:
            *puVar18 = *puVar18 & 0xfffc | 4;
          case 4:
            puVar10 = &local_7c;
            puVar14 = local_50;
            puVar9 = local_5c;
            break;
          default:
            goto switchD_00477728_default;
          }
          FUN_00454620(puVar9,puVar14,puVar10,local_70);
          sVar2 = FUN_004778f0(local_70);
          sVar3 = FUN_004778f0(0);
LAB_0047781d:
          *puVar18 = *puVar18 | (sVar2 + sVar3 * 9) * 8;
switchD_00477728_default:
          iVar21 = iVar21 + 1;
          puVar18 = puVar18 + 8;
          iVar12 = DAT_006316ec;
        } while (iVar21 < *(int *)(DAT_006316ec + 0x1dc));
      }
      local_84 = local_84 + 1;
    } while (local_84 < *(int *)(iVar12 + 0x1e0));
  }
  *(undefined4 *)(iVar12 + 0x20) = 0;
  *(int *)(DAT_006316ec + 0x24) = *(int *)(DAT_006316ec + 0x1dc) + -2;
  *(undefined4 *)(DAT_006316ec + 0x28) = 0;
  *(int *)(DAT_006316ec + 0x2c) = *(int *)(DAT_006316ec + 0x1e0) + -2;
  *(undefined4 *)(DAT_006316ec + 0x30) = 0xc2746666;
  *(undefined4 *)(DAT_006316ec + 0x34) = *(undefined4 *)(DAT_006316ec + 0x1d8);
  *(undefined4 *)(DAT_006316ec + 0x4ef8) = 1;
  FUN_00436960();
  local_8 = 0;
  iVar12 = DAT_006316ec;
  if (0 < *(int *)(DAT_006316ec + 0x1e0)) {
    do {
      iVar17 = 0;
      iVar21 = local_8;
      if (0 < *(int *)(iVar12 + 0x1dc)) {
        local_c = (undefined1 *)(*(int *)(*(int *)(iVar12 + 0x10) + local_8 * 4) + 0xe);
        do {
          local_20[0] = 0;
          local_34 = 0x476c79;
          local_30 = iVar17;
          iStack_2c = iVar21;
          iStack_28 = iVar17;
          iStack_24 = iVar21;
          iVar12 = FUN_004768e0();
          if (iVar12 == 0) {
            *local_c = 1;
            iVar12 = DAT_006316ec;
          }
          else {
            local_4 = -1;
            iVar12 = DAT_006316ec;
            do {
              iVar13 = -1;
              iVar19 = local_4 + iVar17;
              iVar21 = iVar21 + -1;
              do {
                if ((((-1 < iVar19) && (-1 < iVar21)) && (iVar19 < *(int *)(iVar12 + 0x1dc))) &&
                   (iVar21 < *(int *)(iVar12 + 0x1e0))) {
                  local_20[0] = 1;
                  iStack_24 = local_8;
                  local_34 = 0x476cc9;
                  local_30 = iVar19;
                  iStack_2c = iVar21;
                  iStack_28 = iVar17;
                  iVar4 = FUN_004768e0();
                  iVar12 = DAT_006316ec;
                  if (iVar4 == 0) {
                    *local_c = 1;
                    iVar12 = DAT_006316ec;
                    break;
                  }
                }
                iVar13 = iVar13 + 1;
                iVar21 = iVar21 + 1;
              } while (iVar13 < 2);
              local_4 = local_4 + 1;
              iVar21 = local_8;
            } while (local_4 < 2);
          }
          iVar17 = iVar17 + 1;
          local_c = local_c + 0x10;
        } while (iVar17 < *(int *)(iVar12 + 0x1dc));
      }
      local_8 = iVar21 + 1;
    } while (local_8 < *(int *)(iVar12 + 0x1e0));
  }
  return;
}


