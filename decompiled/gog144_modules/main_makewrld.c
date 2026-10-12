/* Giants 1.449 — module main/makewrld
 * 3 functions (3 named) — decompiled, names from PS2 symbols
 * Original source: C:\Giants\source\main/makewrld.c(pp) (assert-string evidence)
 */

/* ===== main_makewrld_00472e40 @ 0x00472E40 ===== */
void main_makewrld_00472e40(void)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  

  if (DAT_006330e4 != 0) {

    main_readobjs_004b0540();

    main_noise_00495430();

    mem_free_tagged(*(undefined4 *)(DAT_006330e4 + 0x18),s_C__Giants_source_main_makewrld_c_0055b874

                    ,0x54);

    mem_free_tagged(*(undefined4 *)(DAT_006330e4 + 0x14),s_C__Giants_source_main_makewrld_c_0055b874

                    ,0x55);

    mem_free_tagged(*(undefined4 *)(DAT_006330e4 + 0x10),s_C__Giants_source_main_makewrld_c_0055b874

                    ,0x56);

    mem_free_tagged(*(undefined4 *)(DAT_006330e4 + 0xc),s_C__Giants_source_main_makewrld_c_0055b874,

                    0x57);

    if (DAT_0059dbe0 != 0) {

      mem_free_tagged(DAT_0059dbe0,s_C__Giants_source_main_makewrld_c_0055b874,0x5a);

      DAT_0059dbe0 = 0;

    }

    main_drawwrld_00432e10();

    piVar1 = (int *)(DAT_006330e4 + 0x4eec);

    if (*(int *)(DAT_006330e4 + 0x4eec) != 0) {

      main_texture_00508840(*(int *)(DAT_006330e4 + 0x4eec));

      iVar3 = *piVar1;

      if ((*(ushort *)(iVar3 + 0x1e) & 0x400) == 0) {

        FUN_005086e0(iVar3);

      }

      else {

        mem_free_tagged(iVar3,s_C__Giants_source_main_makewrld_c_0055b874,0x40);

      }

      *piVar1 = 0;

    }

    piVar1 = (int *)(DAT_006330e4 + 0x4ee8);

    if (*piVar1 != 0) {

      main_texture_00508840(*piVar1);

      iVar3 = *piVar1;

      if ((*(ushort *)(iVar3 + 0x1e) & 0x400) == 0) {

        FUN_005086e0(iVar3);

      }

      else {

        mem_free_tagged(iVar3,s_C__Giants_source_main_makewrld_c_0055b874,0x40);

      }

      *piVar1 = 0;

    }

    piVar1 = (int *)(DAT_006330e4 + 0x4ee4);

    if (*(int *)(DAT_006330e4 + 0x4ee4) != 0) {

      main_texture_00508840(*(int *)(DAT_006330e4 + 0x4ee4));

      iVar3 = *piVar1;

      if ((*(ushort *)(iVar3 + 0x1e) & 0x400) == 0) {

        FUN_005086e0(iVar3);

      }

      else {

        mem_free_tagged(iVar3,s_C__Giants_source_main_makewrld_c_0055b874,0x40);

      }

      *piVar1 = 0;

    }

    piVar1 = (int *)(DAT_006330e4 + 0x4ee0);

    if (*(int *)(DAT_006330e4 + 0x4ee0) != 0) {

      main_texture_00508840(*(int *)(DAT_006330e4 + 0x4ee0));

      iVar3 = *piVar1;

      if ((*(ushort *)(iVar3 + 0x1e) & 0x400) == 0) {

        FUN_005086e0(iVar3);

      }

      else {

        mem_free_tagged(iVar3,s_C__Giants_source_main_makewrld_c_0055b874,0x40);

      }

      *piVar1 = 0;

    }

    piVar1 = (int *)(DAT_006330e4 + 0x4edc);

    if (*piVar1 != 0) {

      main_texture_00508840(*piVar1);

      iVar3 = *piVar1;

      if ((*(ushort *)(iVar3 + 0x1e) & 0x400) == 0) {

        FUN_005086e0(iVar3);

      }

      else {

        mem_free_tagged(iVar3,s_C__Giants_source_main_makewrld_c_0055b874,0x40);

      }

      *piVar1 = 0;

    }

    piVar1 = (int *)(DAT_006330e4 + 0x4ed8);

    if (*(int *)(DAT_006330e4 + 0x4ed8) != 0) {

      main_texture_00508840(*(int *)(DAT_006330e4 + 0x4ed8));

      iVar3 = *piVar1;

      if ((*(ushort *)(iVar3 + 0x1e) & 0x400) == 0) {

        FUN_005086e0(iVar3);

      }

      else {

        mem_free_tagged(iVar3,s_C__Giants_source_main_makewrld_c_0055b874,0x40);

      }

      *piVar1 = 0;

    }

    piVar1 = (int *)(DAT_006330e4 + 0x4ed4);

    if (*(int *)(DAT_006330e4 + 0x4ed4) != 0) {

      main_texture_00508840(*(int *)(DAT_006330e4 + 0x4ed4));

      iVar3 = *piVar1;

      if ((*(ushort *)(iVar3 + 0x1e) & 0x400) == 0) {

        FUN_005086e0(iVar3);

      }

      else {

        mem_free_tagged(iVar3,s_C__Giants_source_main_makewrld_c_0055b874,0x40);

      }

      *piVar1 = 0;

    }

    piVar1 = (int *)(DAT_006330e4 + 0x4ed0);

    if (*piVar1 != 0) {

      main_texture_00508840(*piVar1);

      iVar3 = *piVar1;

      if ((*(ushort *)(iVar3 + 0x1e) & 0x400) == 0) {

        FUN_005086e0(iVar3);

      }

      else {

        mem_free_tagged(iVar3,s_C__Giants_source_main_makewrld_c_0055b874,0x40);

      }

      *piVar1 = 0;

    }

    piVar1 = (int *)(DAT_006330e4 + 0x4ecc);

    if (*(int *)(DAT_006330e4 + 0x4ecc) != 0) {

      main_texture_00508840(*(int *)(DAT_006330e4 + 0x4ecc));

      iVar3 = *piVar1;

      if ((*(ushort *)(iVar3 + 0x1e) & 0x400) == 0) {

        FUN_005086e0(iVar3);

      }

      else {

        mem_free_tagged(iVar3,s_C__Giants_source_main_makewrld_c_0055b874,0x40);

      }

      *piVar1 = 0;

    }

    piVar1 = (int *)(DAT_006330e4 + 0x4ec8);

    if (*(int *)(DAT_006330e4 + 0x4ec8) != 0) {

      main_texture_00508840(*(int *)(DAT_006330e4 + 0x4ec8));

      iVar3 = *piVar1;

      if ((*(ushort *)(iVar3 + 0x1e) & 0x400) == 0) {

        FUN_005086e0(iVar3);

      }

      else {

        mem_free_tagged(iVar3,s_C__Giants_source_main_makewrld_c_0055b874,0x40);

      }

      *piVar1 = 0;

    }

    piVar1 = (int *)(DAT_006330e4 + 0x4ec4);

    if (*piVar1 != 0) {

      main_texture_00508840(*piVar1);

      iVar3 = *piVar1;

      if ((*(ushort *)(iVar3 + 0x1e) & 0x400) == 0) {

        FUN_005086e0(iVar3);

      }

      else {

        mem_free_tagged(iVar3,s_C__Giants_source_main_makewrld_c_0055b874,0x40);

      }

      *piVar1 = 0;

    }

    piVar1 = (int *)(DAT_006330e4 + 0x4ec0);

    if (*(int *)(DAT_006330e4 + 0x4ec0) != 0) {

      main_texture_00508840(*(int *)(DAT_006330e4 + 0x4ec0));

      iVar3 = *piVar1;

      if ((*(ushort *)(iVar3 + 0x1e) & 0x400) == 0) {

        FUN_005086e0(iVar3);

      }

      else {

        mem_free_tagged(iVar3,s_C__Giants_source_main_makewrld_c_0055b874,0x40);

      }

      *piVar1 = 0;

    }

    mem_free_tagged(*(undefined4 *)(DAT_006330e4 + 0x4f08),

                    s_C__Giants_source_main_makewrld_c_0055b874,0x70);

    *(undefined4 *)(DAT_006330e4 + 0x4f08) = 0;

    mem_free_tagged(*(undefined4 *)(DAT_006330e4 + 0x4f10),

                    s_C__Giants_source_main_makewrld_c_0055b874,0x71);

    *(undefined4 *)(DAT_006330e4 + 0x4f10) = 0;

    mem_free_tagged(*(undefined4 *)(DAT_006330e4 + 0x4f18),

                    s_C__Giants_source_main_makewrld_c_0055b874,0x72);

    *(undefined4 *)(DAT_006330e4 + 0x4f18) = 0;

    mem_free_tagged(*(undefined4 *)(DAT_006330e4 + 0x4ef0),

                    s_C__Giants_source_main_makewrld_c_0055b874,0x73);

    *(undefined4 *)(DAT_006330e4 + 0x4ef0) = 0;

    mem_free_tagged(*(undefined4 *)(DAT_006330e4 + 0x4ef8),

                    s_C__Giants_source_main_makewrld_c_0055b874,0x74);

    *(undefined4 *)(DAT_006330e4 + 0x4ef8) = 0;

    mem_free_tagged(*(undefined4 *)(DAT_006330e4 + 0x4f00),

                    s_C__Giants_source_main_makewrld_c_0055b874,0x75);

    *(undefined4 *)(DAT_006330e4 + 0x4f00) = 0;

    mem_free_tagged(*(undefined4 *)(DAT_006330e4 + 0x4f20),

                    s_C__Giants_source_main_makewrld_c_0055b874,0x76);

    *(undefined4 *)(DAT_006330e4 + 0x4f20) = 0;

    mem_free_tagged(*(undefined4 *)(DAT_006330e4 + 0x4f28),

                    s_C__Giants_source_main_makewrld_c_0055b874,0x77);

    *(undefined4 *)(DAT_006330e4 + 0x4f28) = 0;

    mem_free_tagged(*(undefined4 *)(DAT_006330e4 + 0x4f30),

                    s_C__Giants_source_main_makewrld_c_0055b874,0x78);

    *(undefined4 *)(DAT_006330e4 + 0x4f30) = 0;

    mem_free_tagged(*(undefined4 *)(DAT_006330e4 + 0x1e0),

                    s_C__Giants_source_main_makewrld_c_0055b874,0x79);

    *(undefined4 *)(DAT_006330e4 + 0x1e0) = 0;

    mem_free_tagged(*(undefined4 *)(DAT_006330e4 + 0x1e8),

                    s_C__Giants_source_main_makewrld_c_0055b874,0x7a);

    *(undefined4 *)(DAT_006330e4 + 0x1e8) = 0;

    mem_free_tagged(*(undefined4 *)(DAT_006330e4 + 0x1f0),

                    s_C__Giants_source_main_makewrld_c_0055b874,0x7b);

    *(undefined4 *)(DAT_006330e4 + 0x1f0) = 0;

    mem_free_tagged(*(undefined4 *)(DAT_006330e4 + 0x70),s_C__Giants_source_main_makewrld_c_0055b874

                    ,0x7c);

    *(undefined4 *)(DAT_006330e4 + 0x70) = 0;

    mem_free_tagged(*(undefined4 *)(DAT_006330e4 + 0x78),s_C__Giants_source_main_makewrld_c_0055b874

                    ,0x7d);

    *(undefined4 *)(DAT_006330e4 + 0x78) = 0;

    mem_free_tagged(*(undefined4 *)(DAT_006330e4 + 0x68),s_C__Giants_source_main_makewrld_c_0055b874

                    ,0x7e);

    *(undefined4 *)(DAT_006330e4 + 0x68) = 0;

    mem_free_tagged(*(undefined4 *)(DAT_006330e4 + 0x60),s_C__Giants_source_main_makewrld_c_0055b874

                    ,0x7f);

    *(undefined4 *)(DAT_006330e4 + 0x60) = 0;

    mem_free_tagged(*(undefined4 *)(DAT_006330e4 + 0x58),s_C__Giants_source_main_makewrld_c_0055b874

                    ,0x80);

    *(undefined4 *)(DAT_006330e4 + 0x58) = 0;

    mem_free_tagged(*(undefined4 *)(DAT_006330e4 + 0x50),s_C__Giants_source_main_makewrld_c_0055b874

                    ,0x81);

    *(undefined4 *)(DAT_006330e4 + 0x50) = 0;

    mem_free_tagged(*(undefined4 *)(DAT_006330e4 + 0x50e0),

                    s_C__Giants_source_main_makewrld_c_0055b874,0x82);

    *(undefined4 *)(DAT_006330e4 + 0x50e0) = 0;

    iVar3 = 0;

    if (0 < *(int *)(DAT_006330e4 + 0x208)) {

      iVar2 = 0;

      do {

        mem_free_tagged(*(undefined4 *)(*(int *)(DAT_006330e4 + 0x20c) + iVar2),

                        s_C__Giants_source_main_makewrld_c_0055b874,0x87);

        mem_free_tagged(*(undefined4 *)(*(int *)(DAT_006330e4 + 0x20c) + 8 + iVar2),

                        s_C__Giants_source_main_makewrld_c_0055b874,0x88);

        mem_free_tagged(*(undefined4 *)(*(int *)(DAT_006330e4 + 0x20c) + 4 + iVar2),

                        s_C__Giants_source_main_makewrld_c_0055b874,0x89);

        iVar3 = iVar3 + 1;

        iVar2 = iVar2 + 0xc;

      } while (iVar3 < *(int *)(DAT_006330e4 + 0x208));

    }

    mem_free_tagged(*(undefined4 *)(DAT_006330e4 + 0x20c),

                    s_C__Giants_source_main_makewrld_c_0055b874,0x8c);

    *(undefined4 *)(DAT_006330e4 + 0x20c) = 0;

    *(undefined4 *)(DAT_006330e4 + 0x208) = 0;

  }

  return;

}

/* ===== main_makewrld_00473600 @ 0x00473600 ===== */
void main_makewrld_00473600(float *param_1)



{

  undefined4 *puVar1;

  byte *pbVar2;

  uint uVar3;

  uint uVar4;

  int iVar5;

  float fVar6;

  float fVar7;

  int iVar8;

  undefined4 *puVar9;

  int iVar10;

  float *pfVar11;

  float local_70;

  int local_6c;

  uint *local_68;

  int local_64;

  undefined1 local_60 [12];

  undefined1 local_54 [12];

  undefined1 local_48 [12];

  undefined1 local_3c [12];

  float local_30;

  float local_2c;

  float local_28;

  float local_24;

  float local_20;

  float local_1c;

  float local_18;

  float local_14;

  float local_10;

  undefined4 local_c;

  undefined4 local_8;

  undefined4 local_4;

  

  puVar1 = (undefined4 *)

           FUN_0053a700(0x12,*(int *)(DAT_006330e4 + 0x1dc) * *(int *)(DAT_006330e4 + 0x1d8) * 0xc,

                        s_temp_ground_normals_0055b8c8,s_C__Giants_source_main_makewrld_c_0055b874,

                        0xa5);

  puVar9 = puVar1;

  for (uVar4 = *(int *)(DAT_006330e4 + 0x1dc) * *(int *)(DAT_006330e4 + 0x1d8) * 3 & 0x3fffffff;

      uVar4 != 0; uVar4 = uVar4 - 1) {

    *puVar9 = 0;

    puVar9 = puVar9 + 1;

  }

  for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {

    *(undefined1 *)puVar9 = 0;

    puVar9 = (undefined4 *)((int)puVar9 + 1);

  }

  iVar8 = 0;

  iVar5 = DAT_006330e4;

  if (0 < *(int *)(DAT_006330e4 + 0x1dc)) {

    do {

      iVar10 = 0;

      if (0 < *(int *)(iVar5 + 0x1d8)) {

        pbVar2 = (byte *)(*(int *)(*(int *)(iVar5 + 0x10) + iVar8 * 4) + 0xc);

        do {

          if (*(short *)pbVar2 != 0) {

            FUN_00455bd0(iVar10,iVar8,local_48);

            iVar5 = iVar10 + 1;

            FUN_00455bd0(iVar5,iVar8,local_54);

            FUN_00455bd0(iVar10,iVar8 + 1,local_3c);

            FUN_00455bd0(iVar5,iVar8 + 1,local_60);

            switch(*pbVar2 & 7) {

            case 1:

              main_makewrld_00473570

                        (local_48,local_54,local_3c,puVar1,iVar10,iVar8,

                         *(undefined4 *)(DAT_006330e4 + 0x1d8));

              main_makewrld_00473570

                        (local_54,local_3c,local_48,puVar1,iVar5,iVar8,

                         *(undefined4 *)(DAT_006330e4 + 0x1d8));

              main_makewrld_00473570

                        (local_3c,local_48,local_54,puVar1,iVar10,iVar8 + 1,

                         *(undefined4 *)(DAT_006330e4 + 0x1d8));

              break;

            case 4:

              main_makewrld_00473570

                        (local_3c,local_48,local_60,puVar1,iVar10,iVar8 + 1,

                         *(undefined4 *)(DAT_006330e4 + 0x1d8));

              main_makewrld_00473570

                        (local_48,local_60,local_3c,puVar1,iVar10,iVar8,

                         *(undefined4 *)(DAT_006330e4 + 0x1d8));

              main_makewrld_00473570

                        (local_60,local_3c,local_48,puVar1,iVar5,iVar8 + 1,

                         *(undefined4 *)(DAT_006330e4 + 0x1d8));

              break;

            case 5:

              main_makewrld_00473570

                        (local_3c,local_48,local_60,puVar1,iVar10,iVar8 + 1,

                         *(undefined4 *)(DAT_006330e4 + 0x1d8));

              main_makewrld_00473570

                        (local_48,local_60,local_3c,puVar1,iVar10,iVar8,

                         *(undefined4 *)(DAT_006330e4 + 0x1d8));

              main_makewrld_00473570

                        (local_60,local_3c,local_48,puVar1,iVar5,iVar8 + 1,

                         *(undefined4 *)(DAT_006330e4 + 0x1d8));

            case 3:

              main_makewrld_00473570

                        (local_54,local_60,local_48,puVar1,iVar5,iVar8,

                         *(undefined4 *)(DAT_006330e4 + 0x1d8));

              main_makewrld_00473570

                        (local_48,local_54,local_60,puVar1,iVar10,iVar8,

                         *(undefined4 *)(DAT_006330e4 + 0x1d8));

              main_makewrld_00473570

                        (local_60,local_48,local_54,puVar1,iVar5,iVar8 + 1,

                         *(undefined4 *)(DAT_006330e4 + 0x1d8));

              break;

            case 6:

              main_makewrld_00473570

                        (local_48,local_54,local_3c,puVar1,iVar10,iVar8,

                         *(undefined4 *)(DAT_006330e4 + 0x1d8));

              main_makewrld_00473570

                        (local_54,local_3c,local_48,puVar1,iVar5,iVar8,

                         *(undefined4 *)(DAT_006330e4 + 0x1d8));

              main_makewrld_00473570

                        (local_3c,local_48,local_54,puVar1,iVar10,iVar8 + 1,

                         *(undefined4 *)(DAT_006330e4 + 0x1d8));

            case 2:

              main_makewrld_00473570

                        (local_60,local_3c,local_54,puVar1,iVar5,iVar8 + 1,

                         *(undefined4 *)(DAT_006330e4 + 0x1d8));

              main_makewrld_00473570

                        (local_3c,local_54,local_60,puVar1,iVar10,iVar8 + 1,

                         *(undefined4 *)(DAT_006330e4 + 0x1d8));

              main_makewrld_00473570

                        (local_54,local_60,local_3c,puVar1,iVar5,iVar8,

                         *(undefined4 *)(DAT_006330e4 + 0x1d8));

              break;

            default:

              FUN_0051ea20(s_Bad_landscape_topology_in_bump_m_0055b898);

            }

          }

          iVar10 = iVar10 + 1;

          pbVar2 = pbVar2 + 0x10;

          iVar5 = DAT_006330e4;

        } while (iVar10 < *(int *)(DAT_006330e4 + 0x1d8));

      }

      iVar8 = iVar8 + 1;

    } while (iVar8 < *(int *)(iVar5 + 0x1dc));

  }

  local_c = 0x3f800000;

  local_8 = 0;

  local_4 = 0;

  local_64 = 0;

  if (0 < *(int *)(iVar5 + 0x1dc)) {

    do {

      pfVar11 = (float *)(puVar1 + *(int *)(iVar5 + 0x1d8) * local_64 * 3);

      local_6c = 0;

      if (0 < *(int *)(iVar5 + 0x1d8)) {

        local_68 = (uint *)(*(int *)(*(int *)(iVar5 + 0x10) + local_64 * 4) + 8);

        do {

          fVar6 = pfVar11[2] * pfVar11[2] + pfVar11[1] * pfVar11[1] + *pfVar11 * *pfVar11;

          fVar7 = 0.0;

          if (fVar6 != 0.0) {

            fVar6 = (float)((&DAT_005f0a18)[(uint)fVar6 >> 8 & 0xffff] |

                           ((int)fVar6 + 0xc0800000U >> 1) + 0x3f800000 & 0x7f800000);

            fVar7 = 0.0;

            if (0.0 < fVar6) {

              fVar7 = 1.0 / fVar6;

            }

          }

          *pfVar11 = fVar7 * *pfVar11;

          pfVar11[1] = fVar7 * pfVar11[1];

          pfVar11[2] = fVar7 * pfVar11[2];

          FUN_0053e900(&local_30,pfVar11,&local_c);

          FUN_0053e900(&local_24,&local_30,pfVar11);

          fVar6 = local_24 * local_24 + local_20 * local_20 + local_1c * local_1c;

          fVar7 = 0.0;

          if (fVar6 != 0.0) {

            fVar6 = (float)((&DAT_005f0a18)[(uint)fVar6 >> 8 & 0xffff] |

                           ((int)fVar6 + 0xc0800000U >> 1) + 0x3f800000 & 0x7f800000);

            fVar7 = 0.0;

            if (0.0 < fVar6) {

              fVar7 = 1.0 / fVar6;

            }

          }

          local_24 = local_24 * fVar7;

          local_20 = local_20 * fVar7;

          local_1c = fVar7 * local_1c;

          fVar6 = local_30 * local_30 + local_2c * local_2c + local_28 * local_28;

          fVar7 = 0.0;

          if (fVar6 != 0.0) {

            fVar6 = (float)((&DAT_005f0a18)[(uint)fVar6 >> 8 & 0xffff] |

                           ((int)fVar6 + 0xc0800000U >> 1) + 0x3f800000 & 0x7f800000);

            fVar7 = 0.0;

            if (0.0 < fVar6) {

              fVar7 = 1.0 / fVar6;

            }

          }

          local_70 = 0.0;

          local_30 = local_30 * fVar7;

          local_2c = local_2c * fVar7;

          local_28 = fVar7 * local_28;

          local_18 = local_24 * *param_1 + local_20 * param_1[1] + local_1c * param_1[2];

          local_14 = param_1[1] * pfVar11[1] + param_1[2] * pfVar11[2] + *param_1 * *pfVar11;

          local_10 = local_30 * *param_1 + local_2c * param_1[1] + local_28 * param_1[2];

          fVar7 = local_18 * local_18 + local_14 * local_14 + local_10 * local_10;

          if ((fVar7 != 0.0) &&

             (fVar7 = (float)((&DAT_005f0a18)[(uint)fVar7 >> 8 & 0xffff] |

                             ((int)fVar7 + 0xc0800000U >> 1) + 0x3f800000 & 0x7f800000), 0.0 < fVar7

             )) {

            local_70 = 1.0 / fVar7;

          }

          local_18 = local_70 * local_18;

          local_10 = local_70 * local_10;

          iVar5 = __ftol();

          uVar4 = __ftol();

          uVar3 = __ftol();

          *local_68 = (iVar5 << 8 | uVar4) << 8 | uVar3;

          local_68 = local_68 + 4;

          pfVar11 = pfVar11 + 3;

          local_6c = local_6c + 1;

          iVar5 = DAT_006330e4;

        } while (local_6c < *(int *)(DAT_006330e4 + 0x1d8));

      }

      local_64 = local_64 + 1;

    } while (local_64 < *(int *)(iVar5 + 0x1dc));

  }

  mem_free_tagged(puVar1,s_C__Giants_source_main_makewrld_c_0055b874,0x138);

  return;

}

/* ===== gti_terrain_load @ 0x00474440 ===== */
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

  int iVar15;

  ushort *puVar16;

  int iVar17;

  int *piVar18;

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

  

  DAT_0059dbe0 = (undefined4 *)

                 FUN_0053a700(0x12,0x200,&DAT_0055b918,s_C__Giants_source_main_makewrld_c_0055b874,

                              0x21c);

  puVar7 = DAT_0059dbe0;

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

    *(undefined4 *)(DAT_006330e4 + 0x200) = 0;

  }

  else {

    if ((iVar11 != -0x6b69affe) && (iVar11 != -0x6b69affd)) {

      FUN_0051ea20(s_Bad_version_for_world_data_0055b8fc);

      FUN_0051e670();

      return;

    }

    *(int *)(DAT_006330e4 + 0x200) = *piVar14;

    piVar14 = local_60 + 2;

  }

  if (*(int *)(DAT_006330e4 + 0x200) == 0) {

    *(undefined4 *)(DAT_006330e4 + 0x204) = 0;

  }

  else {

    uVar5 = FUN_0053a700(0x12,*(int *)(DAT_006330e4 + 0x200) * 0x38,s_wbboxes_0055b8f4,

                         s_C__Giants_source_main_makewrld_c_0055b874,0x242);

    *(undefined4 *)(DAT_006330e4 + 0x204) = uVar5;

    iVar11 = 0;

    if (0 < *(int *)(DAT_006330e4 + 0x200)) {

      iVar20 = 0;

      do {

        piVar4 = piVar14;

        piVar18 = (int *)(*(int *)(DAT_006330e4 + 0x204) + iVar20);

        for (iVar15 = 8; iVar15 != 0; iVar15 = iVar15 + -1) {

          *piVar18 = *piVar4;

          piVar4 = piVar4 + 1;

          piVar18 = piVar18 + 1;

        }

        *(int *)(*(int *)(DAT_006330e4 + 0x204) + 0x20 + iVar20) = piVar14[8];

        *(int *)(*(int *)(DAT_006330e4 + 0x204) + 0x24 + iVar20) = piVar14[9];

        *(int *)(*(int *)(DAT_006330e4 + 0x204) + 0x28 + iVar20) = piVar14[10];

        *(int *)(*(int *)(DAT_006330e4 + 0x204) + 0x2c + iVar20) = piVar14[0xb];

        *(int *)(*(int *)(DAT_006330e4 + 0x204) + 0x30 + iVar20) = piVar14[0xc];

        *(int *)(*(int *)(DAT_006330e4 + 0x204) + 0x34 + iVar20) = piVar14[0xd];

        piVar14 = piVar14 + 0xe;

        iVar11 = iVar11 + 1;

        iVar20 = iVar20 + 0x38;

      } while (iVar11 < *(int *)(DAT_006330e4 + 0x200));

    }

  }

  *(int *)(DAT_006330e4 + 0x1c8) = *piVar14;

  *(int *)(DAT_006330e4 + 0x1cc) = piVar14[1];

  *(int *)(DAT_006330e4 + 0x1d0) = piVar14[2];

  *(int *)(DAT_006330e4 + 0x1d4) = piVar14[3];

  *(int *)(DAT_006330e4 + 0x1d8) = piVar14[4];

  *(int *)(DAT_006330e4 + 0x1dc) = piVar14[5];

  *(int *)(DAT_006330e4 + 0x1c0) = piVar14[6];

  *(float *)(DAT_006330e4 + 0x1c4) = 1.0 / *(float *)(DAT_006330e4 + 0x1c0);

  *(float *)(DAT_006330e4 + 0x1c8) =

       *(float *)(DAT_006330e4 + 0x1c8) - *(float *)(DAT_006330e4 + 0x1c0);

  *(float *)(DAT_006330e4 + 0x1cc) =

       *(float *)(DAT_006330e4 + 0x1cc) - *(float *)(DAT_006330e4 + 0x1c0);

  *(int *)(DAT_006330e4 + 0x1d8) = *(int *)(DAT_006330e4 + 0x1d8) + 2;

  *(int *)(DAT_006330e4 + 0x1dc) = *(int *)(DAT_006330e4 + 0x1dc) + 2;

  local_7c = (undefined1)piVar14[0xb];

  _local_38 = CONCAT31(uStack_37,*(byte *)((int)piVar14 + 0x2d));

  *(uint *)(DAT_006330e4 + 0x48) =

       (uint)*(byte *)((int)piVar14 + 0x2e) << 4 | (uint)*(byte *)((int)piVar14 + 0x2d);

  *(uint *)(DAT_006330e4 + 0x1c) = CONCAT12(cStack_7a,CONCAT11(uStack_7b,local_7c)) & 0xff;

  *(int *)(DAT_006330e4 + 0x40) = piVar14[0xc];

  *(int *)(DAT_006330e4 + 0x44) = piVar14[0xd];

  piVar4 = piVar14 + 0xe;

  piVar18 = local_20;

  for (iVar11 = 8; iVar11 != 0; iVar11 = iVar11 + -1) {

    *piVar18 = *piVar4;

    piVar4 = piVar4 + 1;

    piVar18 = piVar18 + 1;

  }

  *(undefined4 *)(DAT_006330e4 + 0x3c) = 0;

  piVar4 = *(int **)(DAT_006330e4 + 0x1e0);

  piVar14 = piVar14 + 0x16;

  if (piVar4 == (int *)0x0) {

    piVar4 = local_20;

  }

  uVar5 = main_texture_00508750(piVar4);

  *(undefined4 *)(DAT_006330e4 + 0x4ec0) = uVar5;

  *(undefined4 *)(DAT_006330e4 + 0x3c) = *(undefined4 *)(DAT_006330e4 + 0x4ec0);

  if (*(int *)(DAT_006330e4 + 0x1e8) != 0) {

    uVar5 = main_texture_00508750(*(int *)(DAT_006330e4 + 0x1e8));

    *(undefined4 *)(DAT_006330e4 + 0x4ec4) = uVar5;

  }

  if (*(int *)(DAT_006330e4 + 0x1f0) != 0) {

    uVar5 = main_texture_00508750(*(int *)(DAT_006330e4 + 0x1f0));

    *(undefined4 *)(DAT_006330e4 + 0x4ec8) = uVar5;

  }

  if (*(int *)(DAT_006330e4 + 0x4ec0) != 0) {

    puVar16 = (ushort *)(*(int *)(DAT_006330e4 + 0x4ec0) + 0x1e);

    *puVar16 = *puVar16 | 0x300;

  }

  if (*(int *)(DAT_006330e4 + 0x4ec4) != 0) {

    puVar16 = (ushort *)(*(int *)(DAT_006330e4 + 0x4ec4) + 0x1e);

    *puVar16 = *puVar16 | 0x300;

  }

  if (*(int *)(DAT_006330e4 + 0x4ec8) != 0) {

    puVar16 = (ushort *)(*(int *)(DAT_006330e4 + 0x4ec8) + 0x1e);

    *puVar16 = *puVar16 | 0x300;

  }

  if (*(int *)(DAT_006330e4 + 0x4f20) != 0) {

    uVar5 = main_texture_00508750(*(int *)(DAT_006330e4 + 0x4f20));

    *(undefined4 *)(DAT_006330e4 + 0x4ecc) = uVar5;

  }

  if (*(int *)(DAT_006330e4 + 0x4f28) != 0) {

    uVar5 = main_texture_00508750(*(int *)(DAT_006330e4 + 0x4f28));

    *(undefined4 *)(DAT_006330e4 + 0x4ed0) = uVar5;

  }

  if (*(int *)(DAT_006330e4 + 0x4f30) != 0) {

    uVar5 = main_texture_00508750(*(int *)(DAT_006330e4 + 0x4f30));

    *(undefined4 *)(DAT_006330e4 + 0x4ed4) = uVar5;

  }

  puVar7 = *(undefined4 **)(DAT_006330e4 + 0x4ecc);

  piVar4 = (int *)(DAT_006330e4 + 0x4ecc);

  if ((puVar7 == (undefined4 *)0x0) || (puVar7 == *(undefined4 **)(DAT_006330e4 + 0x4ec0))) {

    puVar6 = *(undefined4 **)(DAT_006330e4 + 0x4ec0);

    if ((puVar7 == puVar6) && (puVar6 != (undefined4 *)0x0)) {

      iVar11 = FUN_0053a700(0x12,0x20,s_ground_bump_texture_0055b860,

                            s_C__Giants_source_main_makewrld_c_0055b874,0x2c);

      *piVar4 = iVar11;

      main_texture_00508720(puVar6);

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

    *(undefined4 *)(*(int *)(DAT_006330e4 + 0x4ecc) + 0x18) = 2;

  }

  puVar7 = *(undefined4 **)(DAT_006330e4 + 0x4ed0);

  piVar4 = (int *)(DAT_006330e4 + 0x4ed0);

  if ((puVar7 == (undefined4 *)0x0) || (puVar7 == *(undefined4 **)(DAT_006330e4 + 0x4ec4))) {

    puVar6 = *(undefined4 **)(DAT_006330e4 + 0x4ec4);

    local_7c = SUB41(puVar6,0);

    uStack_7b = (undefined1)((uint)puVar6 >> 8);

    cStack_7a = (char)((uint)puVar6 >> 0x10);

    uStack_79 = (undefined1)((uint)puVar6 >> 0x18);

    if ((puVar7 == puVar6) && (puVar6 != (undefined4 *)0x0)) {

      iVar11 = FUN_0053a700(0x12,0x20,s_ground_bump_texture_0055b860,

                            s_C__Giants_source_main_makewrld_c_0055b874,0x2c);

      *piVar4 = iVar11;

      main_texture_00508720(puVar6);

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

    *(undefined4 *)(*(int *)(DAT_006330e4 + 0x4ed0) + 0x18) = 2;

  }

  puVar7 = *(undefined4 **)(DAT_006330e4 + 0x4ed4);

  piVar4 = (int *)(DAT_006330e4 + 0x4ed4);

  if ((puVar7 == (undefined4 *)0x0) || (puVar7 == *(undefined4 **)(DAT_006330e4 + 0x4ec8))) {

    puVar6 = *(undefined4 **)(DAT_006330e4 + 0x4ec8);

    local_7c = SUB41(puVar6,0);

    uStack_7b = (undefined1)((uint)puVar6 >> 8);

    cStack_7a = (char)((uint)puVar6 >> 0x10);

    uStack_79 = (undefined1)((uint)puVar6 >> 0x18);

    if ((puVar7 == puVar6) && (puVar6 != (undefined4 *)0x0)) {

      iVar11 = FUN_0053a700(0x12,0x20,s_ground_bump_texture_0055b860,

                            s_C__Giants_source_main_makewrld_c_0055b874,0x2c);

      *piVar4 = iVar11;

      main_texture_00508720(puVar6);

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

    *(undefined4 *)(*(int *)(DAT_006330e4 + 0x4ed4) + 0x18) = 2;

  }

  if (*(int *)(DAT_006330e4 + 0x4ef0) != 0) {

    uVar5 = main_texture_00508750(*(int *)(DAT_006330e4 + 0x4ef0));

    *(undefined4 *)(DAT_006330e4 + 0x4ed8) = uVar5;

  }

  if (*(int *)(DAT_006330e4 + 0x4ef8) != 0) {

    uVar5 = main_texture_00508750(*(int *)(DAT_006330e4 + 0x4ef8));

    *(undefined4 *)(DAT_006330e4 + 0x4edc) = uVar5;

  }

  if (*(int *)(DAT_006330e4 + 0x4f00) != 0) {

    uVar5 = main_texture_00508750(*(int *)(DAT_006330e4 + 0x4f00));

    *(undefined4 *)(DAT_006330e4 + 0x4ee0) = uVar5;

  }

  iVar11 = *(int *)(DAT_006330e4 + 0x4ed8);

  if ((iVar11 != 0) && (iVar11 != *(int *)(DAT_006330e4 + 0x4ec0))) {

    *(ushort *)(iVar11 + 0x1e) = *(ushort *)(iVar11 + 0x1e) | 0x100;

    *(undefined4 *)(*(int *)(DAT_006330e4 + 0x4ed8) + 0x18) = 2;

  }

  iVar11 = *(int *)(DAT_006330e4 + 0x4edc);

  if ((iVar11 != 0) && (iVar11 != *(int *)(DAT_006330e4 + 0x4ec4))) {

    *(ushort *)(iVar11 + 0x1e) = *(ushort *)(iVar11 + 0x1e) | 0x100;

    *(undefined4 *)(*(int *)(DAT_006330e4 + 0x4edc) + 0x18) = 2;

  }

  iVar11 = *(int *)(DAT_006330e4 + 0x4ee0);

  if ((iVar11 != 0) && (iVar11 != *(int *)(DAT_006330e4 + 0x4ec8))) {

    *(ushort *)(iVar11 + 0x1e) = *(ushort *)(iVar11 + 0x1e) | 0x100;

    *(undefined4 *)(*(int *)(DAT_006330e4 + 0x4ee0) + 0x18) = 2;

  }

  if (*(int *)(DAT_006330e4 + 0x4f08) != 0) {

    uVar5 = main_texture_00508750(*(int *)(DAT_006330e4 + 0x4f08));

    *(undefined4 *)(DAT_006330e4 + 0x4ee4) = uVar5;

  }

  if (*(int *)(DAT_006330e4 + 0x4f10) != 0) {

    uVar5 = main_texture_00508750(*(int *)(DAT_006330e4 + 0x4f10));

    *(undefined4 *)(DAT_006330e4 + 0x4ee8) = uVar5;

  }

  if (*(int *)(DAT_006330e4 + 0x4f18) != 0) {

    uVar5 = main_texture_00508750(*(int *)(DAT_006330e4 + 0x4f18));

    *(undefined4 *)(DAT_006330e4 + 0x4eec) = uVar5;

  }

  iVar11 = *(int *)(DAT_006330e4 + 0x4ee4);

  if ((iVar11 != 0) && (iVar11 != *(int *)(DAT_006330e4 + 0x4ec0))) {

    *(ushort *)(iVar11 + 0x1e) = *(ushort *)(iVar11 + 0x1e) | 0x100;

    *(undefined4 *)(*(int *)(DAT_006330e4 + 0x4ee4) + 0x18) = 2;

  }

  iVar11 = *(int *)(DAT_006330e4 + 0x4ee8);

  if ((iVar11 != 0) && (iVar11 != *(int *)(DAT_006330e4 + 0x4ec4))) {

    *(ushort *)(iVar11 + 0x1e) = *(ushort *)(iVar11 + 0x1e) | 0x100;

    *(undefined4 *)(*(int *)(DAT_006330e4 + 0x4ee8) + 0x18) = 2;

  }

  iVar11 = *(int *)(DAT_006330e4 + 0x4eec);

  if ((iVar11 != 0) && (iVar11 != *(int *)(DAT_006330e4 + 0x4ec8))) {

    *(ushort *)(iVar11 + 0x1e) = *(ushort *)(iVar11 + 0x1e) | 0x100;

    *(undefined4 *)(*(int *)(DAT_006330e4 + 0x4eec) + 0x18) = 2;

  }

  puVar6 = (undefined4 *)

           FUN_0053a700(0x1a,*(int *)(DAT_006330e4 + 0x1dc) * *(int *)(DAT_006330e4 + 0x1d8) * 0x10,

                        s_World_0055b8ec,s_C__Giants_source_main_makewrld_c_0055b874,0x329);

  puVar7 = puVar6;

  for (iVar11 = (*(int *)(DAT_006330e4 + 0x1dc) * *(int *)(DAT_006330e4 + 0x1d8) & 0xfffffffU) << 2;

      iVar11 != 0; iVar11 = iVar11 + -1) {

    *puVar7 = 0;

    puVar7 = puVar7 + 1;

  }

  for (iVar11 = 0; iVar11 != 0; iVar11 = iVar11 + -1) {

    *(undefined1 *)puVar7 = 0;

    puVar7 = (undefined4 *)((int)puVar7 + 1);

  }

  iVar20 = 0;

  iVar11 = DAT_006330e4;

  if (0 < *(int *)(DAT_006330e4 + 0x1dc)) {

    iVar15 = *(int *)(DAT_006330e4 + 0x1d8);

    puVar7 = puVar6;

    do {

      iVar12 = 0;

      if (0 < iVar15) {

        do {

          *puVar7 = 0xc5800000;

          iVar15 = *(int *)(DAT_006330e4 + 0x1d8);

          puVar7 = puVar7 + 4;

          iVar12 = iVar12 + 1;

          iVar11 = DAT_006330e4;

        } while (iVar12 < iVar15);

      }

      iVar20 = iVar20 + 1;

    } while (iVar20 < *(int *)(iVar11 + 0x1dc));

  }

  uVar5 = FUN_0053a700(0x1a,*(int *)(iVar11 + 0x1dc) << 2,s_YROWS_0055b8e4,

                       s_C__Giants_source_main_makewrld_c_0055b874,0x336);

  *(undefined4 *)(DAT_006330e4 + 0x10) = uVar5;

  iVar11 = 0;

  if (0 < *(int *)(DAT_006330e4 + 0x1dc)) {

    do {

      *(undefined4 **)(*(int *)(DAT_006330e4 + 0x10) + iVar11 * 4) =

           puVar6 + *(int *)(DAT_006330e4 + 0x1d8) * iVar11 * 4;

      iVar11 = iVar11 + 1;

    } while (iVar11 < *(int *)(DAT_006330e4 + 0x1dc));

  }

  uVar5 = FUN_0053a700(0x1a,*(int *)(DAT_006330e4 + 0x1dc) << 2,&DAT_0055b8e0,

                       s_C__Giants_source_main_makewrld_c_0055b874,0x33b);

  *(undefined4 *)(DAT_006330e4 + 0x14) = uVar5;

  uVar5 = FUN_0053a700(0x1a,*(int *)(DAT_006330e4 + 0x1dc) << 2,&DAT_0055b8dc,

                       s_C__Giants_source_main_makewrld_c_0055b874,0x33c);

  *(undefined4 *)(DAT_006330e4 + 0x18) = uVar5;

  iVar15 = 1;

  iVar20 = 1;

  iVar11 = DAT_006330e4;

  if (1 < *(int *)(DAT_006330e4 + 0x1dc) + -1) {

    do {

      cVar10 = (char)*piVar14;

      piVar14 = (int *)((int)piVar14 + 1);

      if (cVar10 < '\0') {

        iVar20 = iVar20 - cVar10;

        iVar12 = *(int *)(iVar11 + 0x1d8);

        if (iVar12 + -1 <= iVar20) {

          do {

            iVar20 = iVar20 + (2 - iVar12);

            iVar15 = iVar15 + 1;

          } while (iVar12 + -1 <= iVar20);

        }

      }

      else {

        local_84 = cVar10 + 1;

        piVar4 = piVar14;

        if (0 < local_84) {

          do {

            puVar6[(*(int *)(iVar11 + 0x1d8) * iVar15 + iVar20) * 4] = *piVar4;

            *(ushort *)(puVar6 + (*(int *)(DAT_006330e4 + 0x1d8) * iVar15 + iVar20) * 4 + 3) =

                 (ushort)*(byte *)(piVar4 + 1);

            piVar14 = (int *)((int)piVar4 + 5);

            if ((*(uint *)(DAT_006330e4 + 0x1c) & 2) != 0) {

              if ((*(uint *)(DAT_006330e4 + 0x1c) & 4) == 0) {

                cStack_7a = *(char *)((int)piVar4 + 7);

                cVar10 = -1;

                local_7c = (undefined1)*(undefined2 *)piVar14;

                uStack_7b = (undefined1)((ushort)*(undefined2 *)piVar14 >> 8);

                piVar14 = piVar4 + 2;

              }

              else {

                cStack_7a = *(char *)((int)piVar4 + 7);

                local_7c = (undefined1)*(undefined2 *)piVar14;

                uStack_7b = (undefined1)((ushort)*(undefined2 *)piVar14 >> 8);

                cVar10 = (char)piVar4[2];

                piVar14 = (int *)((int)piVar4 + 9);

              }

              puVar6[(*(int *)(DAT_006330e4 + 0x1d8) * iVar15 + iVar20) * 4 + 1] =

                   ((uint)CONCAT11(cVar10,local_7c) << 8 |

                   CONCAT12(uStack_79,CONCAT11(cStack_7a,uStack_7b)) & 0xff) << 8 |

                   CONCAT11(uStack_79,cStack_7a) & 0xff;

            }

            iVar20 = iVar20 + 1;

            if (*(int *)(DAT_006330e4 + 0x1d8) + -1 <= iVar20) {

              iVar20 = 1;

              iVar15 = iVar15 + 1;

            }

            local_84 = local_84 + -1;

            piVar4 = piVar14;

            iVar11 = DAT_006330e4;

          } while (local_84 != 0);

        }

      }

    } while (iVar15 < *(int *)(iVar11 + 0x1dc) + -1);

  }

  *(undefined4 **)(iVar11 + 0xc) = puVar6;

  iVar20 = 0;

  iVar11 = DAT_006330e4;

  if (0 < *(int *)(DAT_006330e4 + 0x1dc)) {

    do {

      *(undefined4 *)(*(int *)(iVar11 + 0x18) + iVar20 * 4) = 0xffffffff;

      piVar14 = *(int **)(*(int *)(DAT_006330e4 + 0x10) + iVar20 * 4);

      iVar15 = 0;

      if (0 < *(int *)(DAT_006330e4 + 0x1d8)) {

        do {

          if (*piVar14 != -0x3a800000) break;

          iVar15 = iVar15 + 1;

          piVar14 = piVar14 + 4;

        } while (iVar15 < *(int *)(DAT_006330e4 + 0x1d8));

      }

      *(int *)(*(int *)(DAT_006330e4 + 0x14) + iVar20 * 4) = iVar15;

      iVar11 = DAT_006330e4;

      if (iVar15 < *(int *)(DAT_006330e4 + 0x1d8)) {

        do {

          if (*piVar14 != -0x3a800000) {

            *(int *)(*(int *)(iVar11 + 0x18) + iVar20 * 4) = iVar15;

            iVar11 = DAT_006330e4;

          }

          iVar15 = iVar15 + 1;

          piVar14 = piVar14 + 4;

        } while (iVar15 < *(int *)(iVar11 + 0x1d8));

      }

      iVar20 = iVar20 + 1;

    } while (iVar20 < *(int *)(iVar11 + 0x1dc));

  }

  utils_fileread_00538560(local_60);

  local_84 = 0;

  iVar11 = DAT_006330e4;

  if (0 < *(int *)(DAT_006330e4 + 0x1dc)) {

    do {

      iVar20 = 0;

      if (0 < *(int *)(iVar11 + 0x1d8)) {

        puVar16 = (ushort *)(*(int *)(*(int *)(iVar11 + 0x10) + local_84 * 4) + 0xc);

        do {

          if (*puVar16 == 0) goto switchD_0047500c_default;

          FUN_00455bd0(iVar20,local_84,local_5c);

          FUN_00455bd0(iVar20 + 1,local_84,local_44);

          FUN_00455bd0(iVar20,local_84 + 1,&local_7c);

          FUN_00455bd0(iVar20 + 1,local_84 + 1,local_50);

          switch(*puVar16 & 7) {

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

            FUN_004511d0(local_5c,local_50,&local_7c,local_70);

            puVar9 = local_44;

            puVar13 = local_5c;

            puVar8 = local_50;

            goto LAB_00475069;

          case 6:

            FUN_004511d0(local_44,&local_7c,local_5c,local_70);

            puVar9 = local_50;

            puVar13 = local_44;

            puVar8 = &local_7c;

LAB_00475069:

            FUN_004511d0(puVar8,puVar13,puVar9,&local_30);

            sVar1 = FUN_004751d0(local_70);

            sVar2 = FUN_004751d0(&local_30);

            goto LAB_00475102;

          case 7:

            *puVar16 = *puVar16 & 0xfffc | 4;

          case 4:

            puVar9 = &local_7c;

            puVar13 = local_50;

            puVar8 = local_5c;

            break;

          default:

            goto switchD_0047500c_default;

          }

          FUN_004511d0(puVar8,puVar13,puVar9,local_70);

          sVar1 = FUN_004751d0(local_70);

          sVar2 = FUN_004751d0(0);

LAB_00475102:

          *puVar16 = *puVar16 | (sVar1 + sVar2 * 9) * 8;

switchD_0047500c_default:

          iVar20 = iVar20 + 1;

          puVar16 = puVar16 + 8;

          iVar11 = DAT_006330e4;

        } while (iVar20 < *(int *)(DAT_006330e4 + 0x1d8));

      }

      local_84 = local_84 + 1;

    } while (local_84 < *(int *)(iVar11 + 0x1dc));

  }

  *(undefined4 *)(iVar11 + 0x20) = 0;

  *(int *)(DAT_006330e4 + 0x24) = *(int *)(DAT_006330e4 + 0x1d8) + -2;

  *(undefined4 *)(DAT_006330e4 + 0x28) = 0;

  *(int *)(DAT_006330e4 + 0x2c) = *(int *)(DAT_006330e4 + 0x1dc) + -2;

  *(undefined4 *)(DAT_006330e4 + 0x30) = 0xc2746666;

  *(undefined4 *)(DAT_006330e4 + 0x34) = *(undefined4 *)(DAT_006330e4 + 0x1d4);

  *(undefined4 *)(DAT_006330e4 + 0x4f3c) = 1;

  main_drawwrld_004329b0();

  local_8 = 0;

  iVar11 = DAT_006330e4;

  if (0 < *(int *)(DAT_006330e4 + 0x1dc)) {

    do {

      iVar15 = 0;

      iVar20 = local_8;

      if (0 < *(int *)(iVar11 + 0x1d8)) {

        local_c = (undefined1 *)(*(int *)(*(int *)(iVar11 + 0x10) + local_8 * 4) + 0xe);

        do {

          local_20[0] = 0;

          local_34 = 0x47437b;

          local_30 = iVar15;

          iStack_2c = iVar20;

          iStack_28 = iVar15;

          iStack_24 = iVar20;

          iVar11 = main_makewrld_00473ff0();

          if (iVar11 == 0) {

            *local_c = 1;

            iVar11 = DAT_006330e4;

          }

          else {

            local_4 = -1;

            iVar11 = DAT_006330e4;

            do {

              iVar12 = -1;

              iVar17 = local_4 + iVar15;

              iVar20 = iVar20 + -1;

              do {

                if ((((-1 < iVar17) && (-1 < iVar20)) && (iVar17 < *(int *)(iVar11 + 0x1d8))) &&

                   (iVar20 < *(int *)(iVar11 + 0x1dc))) {

                  local_20[0] = 1;

                  iStack_24 = local_8;

                  local_34 = 0x4743cd;

                  local_30 = iVar17;

                  iStack_2c = iVar20;

                  iStack_28 = iVar15;

                  iVar3 = main_makewrld_00473ff0();

                  iVar11 = DAT_006330e4;

                  if (iVar3 == 0) {

                    *local_c = 1;

                    iVar11 = DAT_006330e4;

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

          iVar15 = iVar15 + 1;

          local_c = local_c + 0x10;

        } while (iVar15 < *(int *)(iVar11 + 0x1d8));

      }

      local_8 = iVar20 + 1;

    } while (local_8 < *(int *)(iVar11 + 0x1dc));

  }

  return;

}

