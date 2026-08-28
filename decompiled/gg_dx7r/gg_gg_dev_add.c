// gg_dx7r.dll - gg_dev_add @ 0x10001300

undefined4 FUN_10001300(undefined4 param_1,LPCSTR param_2,uint *param_3,LPCSTR param_4)

{
  uint uVar1;
  undefined4 uVar2;
  void *pvVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  uint uVar9;
  uint *puVar10;
  LPCSTR pCVar11;
  undefined4 *puVar12;
  LPSTR pCVar13;
  uint *puVar14;
  undefined4 *puVar15;
  uint uStack_80;
  undefined4 auStack_7c [21];
  int iStack_28;
  uint uStack_10;
  
  iVar6 = DAT_10028450;
  DAT_1002844c = DAT_1002844c + 1;
  iVar8 = DAT_10028450 * 0x900;
  pCVar13 = &DAT_1001d048 + iVar8;
  for (iVar4 = 0x240; iVar4 != 0; iVar4 = iVar4 + -1) {
    pCVar13[0] = '\0';
    pCVar13[1] = '\0';
    pCVar13[2] = '\0';
    pCVar13[3] = '\0';
    pCVar13 = pCVar13 + 4;
  }
  *(uint *)(&DAT_1001d160 + iVar8) = *param_3 & 0x80000;
  puVar10 = param_3;
  puVar14 = (uint *)(&DAT_1001d074 + iVar8);
  for (iVar4 = 0x3b; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar14 = *puVar10;
    puVar10 = puVar10 + 1;
    puVar14 = puVar14 + 1;
  }
  pCVar11 = param_4 + 0x418;
  puVar7 = (undefined4 *)(&DAT_1001d460 + iVar8);
  for (iVar4 = 0x10c; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar7 = *(undefined4 *)pCVar11;
    pCVar11 = pCVar11 + 4;
    puVar7 = puVar7 + 1;
  }
  *(undefined4 *)(&DAT_1001d940 + iVar8) = *(undefined4 *)(param_4 + 0x8f8);
  pCVar11 = param_4 + 0x120;
  puVar7 = (undefined4 *)(&DAT_1001d168 + iVar8);
  for (iVar4 = 0x5f; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar7 = *(undefined4 *)pCVar11;
    pCVar11 = pCVar11 + 4;
    puVar7 = puVar7 + 1;
  }
  pCVar11 = param_4 + 0x29c;
  puVar7 = (undefined4 *)(&DAT_1001d2e4 + iVar8);
  for (iVar4 = 0x5f; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar7 = *(undefined4 *)pCVar11;
    pCVar11 = pCVar11 + 4;
    puVar7 = puVar7 + 1;
  }
  *(uint *)(&DAT_1001d914 + iVar8) = param_3[0x31];
  *(uint *)(&DAT_1001d918 + iVar8) = param_3[0x32];
  *(uint *)(&DAT_1001d91c + iVar8) = param_3[0x33];
  uVar1 = param_3[0x34];
  *(undefined **)(&DAT_1001d070 + iVar8) = &DAT_1001d914 + iVar8;
  *(uint *)(&DAT_1001d920 + iVar8) = uVar1;
  pvVar3 = operator_new(*(int *)(param_4 + 0x8f0) * 0x7c);
  (&DAT_1001d934)[iVar6 * 0x240] = pvVar3;
  if (*(int *)(param_4 + 0x11c) == 0) {
    *(undefined4 *)(&DAT_1001d164 + iVar8) = 0;
  }
  else {
    *(undefined4 *)(&DAT_1001d924 + iVar8) = *(undefined4 *)(param_4 + 0x8dc);
    *(undefined4 *)(&DAT_1001d928 + iVar8) = *(undefined4 *)(param_4 + 0x8e0);
    *(undefined4 *)(&DAT_1001d92c + iVar8) = *(undefined4 *)(param_4 + 0x8e4);
    uVar2 = *(undefined4 *)(param_4 + 0x8e8);
    *(undefined **)(&DAT_1001d164 + iVar8) = &DAT_1001d924 + iVar8;
    *(undefined4 *)(&DAT_1001d930 + iVar8) = uVar2;
    param_2 = param_4;
  }
  lstrcpynA(&DAT_1001d048 + iVar8,param_2,0x27);
  if (((*(int *)(&DAT_1001d164 + iVar8) == 0) || (*(int *)(&DAT_1001d160 + iVar8) != 0)) &&
     ((DAT_10028448 == (code *)0x0 ||
      (iVar4 = (*DAT_10028448)(&DAT_1001d168 + iVar8,&DAT_1001d074 + iVar8), -1 < iVar4)))) {
    uStack_80 = 0;
    if (*(int *)(param_4 + 0x8f0) != 0) {
      iVar4 = 0;
      do {
        puVar7 = (undefined4 *)(*(int *)(param_4 + 0x8ec) + iVar4);
        puVar12 = auStack_7c;
        for (iVar5 = 0x1f; iVar5 != 0; iVar5 = iVar5 + -1) {
          *puVar12 = *puVar7;
          puVar7 = puVar7 + 1;
          puVar12 = puVar12 + 1;
        }
        uVar1 = *(uint *)(&DAT_1001d0e8 + iVar8);
        if (iStack_28 == 0x20) {
          uVar1 = uVar1 & 0x100;
joined_r0x100014af:
          if (uVar1 != 0) {
            puVar7 = auStack_7c;
            puVar12 = (undefined4 *)
                      ((&DAT_1001d934)[iVar6 * 0x240] + *(int *)(&DAT_1001d938 + iVar8) * 0x7c);
            for (iVar5 = 0x1f; iVar5 != 0; iVar5 = iVar5 + -1) {
              *puVar12 = *puVar7;
              puVar7 = puVar7 + 1;
              puVar12 = puVar12 + 1;
            }
            *(int *)(&DAT_1001d938 + iVar8) = *(int *)(&DAT_1001d938 + iVar8) + 1;
            if ((uStack_10 & 0x80000) != 0) {
              *(undefined4 *)(&DAT_1001d944 + iVar8) = 1;
            }
          }
        }
        else {
          if (iStack_28 == 0x18) {
            uVar1 = uVar1 & 0x200;
            goto joined_r0x100014af;
          }
          if (iStack_28 == 0x10) {
            uVar1 = uVar1 & 0x400;
            goto joined_r0x100014af;
          }
        }
        uStack_80 = uStack_80 + 1;
        iVar4 = iVar4 + 0x7c;
      } while (uStack_80 < *(uint *)(param_4 + 0x8f0));
    }
    uVar1 = *(uint *)(&DAT_1001d938 + iVar8);
    if (uVar1 != 0) {
      uVar9 = 0;
      if (uVar1 != 0) {
        puVar7 = (undefined4 *)(&DAT_1001d934)[iVar6 * 0x240];
        do {
          if (((puVar7[3] == 0x280) && (puVar7[2] == 0x1e0)) && (puVar7[0x15] == 0x10)) {
            puVar12 = puVar7;
            puVar15 = (undefined4 *)(&DAT_1001d890 + iVar8);
            for (iVar6 = 0x1f; iVar6 != 0; iVar6 = iVar6 + -1) {
              *puVar15 = *puVar12;
              puVar12 = puVar12 + 1;
              puVar15 = puVar15 + 1;
            }
            *(uint *)(&DAT_1001d93c + iVar8) = uVar9;
          }
          uVar9 = uVar9 + 1;
          puVar7 = puVar7 + 0x1f;
        } while (uVar9 < uVar1);
      }
      DAT_10028450 = DAT_10028450 + 1;
      *(undefined4 *)(&DAT_1001d90c + iVar8) = *(undefined4 *)(&DAT_1001d940 + iVar8);
    }
  }
  return 1;
}

