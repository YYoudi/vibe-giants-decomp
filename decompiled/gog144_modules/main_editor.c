/* Giants 1.449 — module main/editor
 * 6 functions (5 named) — decompiled, names from PS2 symbols
 * Original source: C:\Giants\source\main/editor.c(pp) (assert-string evidence)
 */

/* ===== FUN_004361b0 @ 0x004361B0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* WARNING: Struct "OBJECT": ignoring multiple overlapping fields */

/* PS2 candidate: rpman_init__FP6OBJECT (conf 0.381) */



void FUN_004361b0(void)



{

  OBJECT *pOVar1;

  bool bVar2;

  float fVar3;

  float fVar4;

  char cVar5;

  int **ppiVar6;

  undefined4 uVar7;

  undefined1 uVar8;

  undefined1 uVar9;

  uint uVar10;

  int iVar11;

  int *piVar12;

  int *piVar13;

  int **ppiVar14;

  uint uVar15;

  undefined4 *puVar16;

  undefined4 *puVar17;

  int iVar18;

  byte bVar19;

  uint uVar20;

  int *piVar21;

  int *piVar22;

  int *piVar23;

  int **ppiVar24;

  float10 fVar25;

  float local_80;

  int *local_7c;

  float local_78;

  float local_74;

  float local_70;

  float local_6c;

  float local_68;

  float local_64;

  float local_60;

  float local_5c;

  float local_58;

  float local_54;

  float local_50;

  undefined1 local_48 [4];

  float local_44;

  float local_38;

  undefined1 local_24 [36];

  

  if ((DAT_00632e74 == 0) && (DAT_0059cd44 != 0)) {

    DAT_0059cd44 = 0;

    while (DAT_0059cbd8 != (int *)0x0) {

      piVar12 = (int *)*DAT_0059cbd8;

      *DAT_0059cbd8 = (int)DAT_0059cd94;

      DAT_0059cd94 = DAT_0059cbd8;

      DAT_0059cbd8 = piVar12;

    }

    DAT_0059cbd8 = (int *)0x0;

    for (puVar16 = DAT_00632d68; puVar16 != (undefined4 *)0x0; puVar16 = (undefined4 *)*puVar16) {

      *(uint *)(puVar16[3] + 0xdc) = *(uint *)(puVar16[3] + 0xdc) & 0xffffdeff;

    }

  }

  puVar16 = DAT_00632d68;

  if (DAT_00632e80 != 0) {

    for (; puVar16 != (undefined4 *)0x0; puVar16 = (undefined4 *)*puVar16) {

      *(uint *)(puVar16[3] + 0xdc) = *(uint *)(puVar16[3] + 0xdc) & 0xffffdeff;

    }

    if (DAT_00632e80 == 0) {

      return;

    }

    uVar15 = DAT_00632e80 - 1;

    cVar5 = (char)DAT_00632e80;

    puVar16 = DAT_00632d68;

    do {

      if (puVar16 == (undefined4 *)0x0) {

        iVar11 = main_editor_00437fa0(0);

        if (iVar11 == 0) {

          return;

        }

        *(uint *)(iVar11 + 0xdc) = *(uint *)(iVar11 + 0xdc) | 0x2000;

        if (DAT_00632aaa == '\0') {

          return;

        }

        if (uVar15 < 0x20) {

          *(uint *)(iVar11 + 0x2e8) = *(uint *)(iVar11 + 0x2e8) ^ 1 << ((byte)uVar15 & 0x1f);

          return;

        }

        if (0x3f < uVar15) {

          if (uVar15 < 0x60) {

            bVar19 = cVar5 + 0xbf;

          }

          else {

            if (0x7f < uVar15) {

              return;

            }

            bVar19 = cVar5 + 0x9f;

          }

          *(uint *)(iVar11 + 0x2f0) = *(uint *)(iVar11 + 0x2f0) ^ 1 << (bVar19 & 0x1f);

          return;

        }

        *(uint *)(iVar11 + 0x2ec) = *(uint *)(iVar11 + 0x2ec) ^ 1 << (cVar5 - 0x21U & 0x1f);

        return;

      }

      iVar11 = puVar16[3];

      if (uVar15 < 0x20) {

        uVar10 = 1 << ((byte)uVar15 & 0x1f);

        uVar20 = *(uint *)(iVar11 + 0x2e8);

LAB_004362b4:

        if ((uVar10 & uVar20) != 0) {

          *(uint *)(iVar11 + 0xdc) = *(uint *)(iVar11 + 0xdc) | 0x100;

        }

      }

      else {

        if (uVar15 < 0x40) {

          uVar10 = 1 << (cVar5 - 0x21U & 0x1f);

          uVar20 = *(uint *)(iVar11 + 0x2ec);

          goto LAB_004362b4;

        }

        if (uVar15 < 0x60) {

          bVar19 = cVar5 + 0xbf;

LAB_004362a7:

          uVar10 = 1 << (bVar19 & 0x1f);

          uVar20 = *(uint *)(iVar11 + 0x2f0);

          goto LAB_004362b4;

        }

        if (uVar15 < 0x80) {

          bVar19 = cVar5 + 0x9f;

          goto LAB_004362a7;

        }

      }

      puVar16 = (undefined4 *)*puVar16;

    } while( true );

  }

  if (DAT_00632e74 == 0) {

    return;

  }

  bVar2 = true;

  if (DAT_0059cd44 == 0) {

    main_editor_00438350();

    DAT_0059cd44 = 1;

  }

  if ((DAT_00632ad6 == '\0') && (DAT_00632ad7 == '\0')) {

    bVar2 = false;

  }

  if (((DAT_0059cbf0 == 0) && (DAT_0059cbec == 0)) && (!bVar2)) {

    iVar11 = main_editor_00437fa0(1);

    if ((DAT_0059cbd8 == (int *)0x0) || (DAT_0059cbd8[0xe] == iVar11)) {

      piVar12 = DAT_0059cbd8;

      if (iVar11 != 0) {

        for (; piVar12 != (int *)0x0; piVar12 = (int *)*piVar12) {

          if (piVar12[0xe] == iVar11) goto LAB_00436453;

        }

        piVar12 = (int *)main_editor_004415d0();

        piVar12[0xe] = iVar11;

        *piVar12 = (int)DAT_0059cbd8;

        DAT_0059cbd8 = piVar12;

      }

    }

    else {

      do {

        piVar12 = DAT_0059cbd8;

        DAT_0059cbd8 = (int *)*piVar12;

        *piVar12 = (int)DAT_0059cd94;

        DAT_0059cd94 = piVar12;

      } while (DAT_0059cbd8 != (int *)0x0);

      DAT_0059cbd8 = (int *)0x0;

      if (iVar11 != 0) {

        piVar12 = (int *)main_editor_004415d0();

        piVar12[0xe] = iVar11;

        *piVar12 = (int)DAT_0059cbd8;

        DAT_0059cbd8 = piVar12;

      }

    }

  }

LAB_00436453:

  if (DAT_00632aad != '\0') {

    if (DAT_0059cbd8 == (int *)0x0) {

      DAT_0059cc38 = 2;

      FUN_004959C0();

      FUN_00426F40(&LAB_00438ef0,&LAB_00438dd0);

      DAT_00632ab0 = 0;

      DAT_00632aad = 0;

      DAT_00632aaa = 0;

      FUN_00519C70();

      main_editor_00438350();

      switch(DAT_0059cc38) {

      case 0:

        goto switchD_004364b2_caseD_0;

      case 1:

switchD_004364b2_caseD_1:

        main_editor_00439df0();

        return;

      case 2:

switchD_004364b2_caseD_2:

        main_editor_0043a440();

        return;

      case 3:

switchD_004364b2_caseD_3:

        wredit_obj_info();

        return;

      case 4:

switchD_004364b2_caseD_4:

        wredit_lock_menu();

        return;

      case 5:

switchD_004364b2_caseD_5:

        wredit_flick_menu();

        return;

      case 6:

switchD_004364b2_caseD_6:

        wredit_lock_list();

        return;

      case 7:

switchD_004364b2_caseD_7:

        wredit_ai_menu();

        return;

      case 8:

switchD_004364b2_caseD_8:

        main_editor_00440230();

        return;

      case 9:

switchD_004364b2_caseD_9:

        wredit_marker_info3();

        return;

      case 10:

switchD_004364b2_caseD_a:

        wredit_marker_info();

        return;

      case 0xb:

switchD_004364b2_caseD_b:

        wredit_marker_info2();

        return;

      case 0xc:

switchD_004364b2_caseD_c:

        wredit_trigger_menu();

        return;

      default:

        return;

      }

    }

    DAT_0059cc38 = 3;

    FUN_004959C0();

    FUN_00426F40(&LAB_00438ef0,&LAB_00438dd0);

    DAT_00632ab0 = 0;

    DAT_00632aad = 0;

    DAT_00632aaa = 0;

    FUN_00519C70();

    main_editor_00438350();

    switch(DAT_0059cc38) {

    case 0:

switchD_004364b2_caseD_0:

      wredit_menu_draw();

      return;

    case 1:

      goto switchD_004364b2_caseD_1;

    case 2:

      goto switchD_004364b2_caseD_2;

    case 3:

      goto switchD_004364b2_caseD_3;

    case 4:

      goto switchD_004364b2_caseD_4;

    case 5:

      goto switchD_004364b2_caseD_5;

    case 6:

      goto switchD_004364b2_caseD_6;

    case 7:

      goto switchD_004364b2_caseD_7;

    case 8:

      goto switchD_004364b2_caseD_8;

    case 9:

      goto switchD_004364b2_caseD_9;

    case 10:

      goto switchD_004364b2_caseD_a;

    case 0xb:

      goto switchD_004364b2_caseD_b;

    case 0xc:

      goto switchD_004364b2_caseD_c;

    default:

      return;

    }

  }

  if ((bVar2) && (DAT_0059cbd8 != (int *)0x0)) {

    iVar11 = DAT_0059cbd8[0xe];

    if (*(int *)(iVar11 + 0x1e0) != 0x34) {

      return;

    }

    if ((DAT_005dd238 & 1) != 0) {

      if (DAT_00632ad6 != '\0') {

        FUN_00455890(&local_60,0x447a0000,&local_70);

        fVar25 = (float10)FUN_0050a520(&local_60,*(int *)(iVar11 + 0x100) + 4);

        **(float **)(iVar11 + 0x100) = (float)fVar25;

      }

      if (DAT_00632ad7 != '\0') {

        FUN_00455890(&local_60,0x447a0000,&local_70);

        iVar18 = *(int *)(iVar11 + 0x100);

        *(float *)(iVar18 + 4) = local_60;

        *(float *)(iVar18 + 8) = local_5c;

        *(float *)(iVar18 + 0xc) = local_58;

      }

    }

    FUN_0042ef40(*(undefined4 **)(iVar11 + 0x100) + 1,**(undefined4 **)(iVar11 + 0x100));

    return;

  }

  if (DAT_0059cbf0 != 0) {

    if (DAT_0059cbe8 != 0) {

      FUN_00455890(&local_54,0x447a0000,&local_70);

      local_5c = local_50;

      local_60 = DAT_0059cc1c;

      local_6c = local_54;

      local_68 = DAT_0059cc20;

      fVar25 = (float10)FUN_00413e40(&local_60);

      local_58 = (float)fVar25;

      fVar25 = (float10)FUN_00413e40(&local_6c);

      local_64 = (float)fVar25;

      FUN_0042eee0(&DAT_0059cc1c,&local_60);

      FUN_0042eee0(&local_60,&local_54);

      FUN_0042eee0(&local_54,&local_6c);

      FUN_0042eee0(&local_6c,&DAT_0059cc1c);

      for (puVar16 = DAT_00632d68; puVar17 = DAT_00632d68, puVar16 != (undefined4 *)0x0;

          puVar16 = (undefined4 *)*puVar16) {

        *(uint *)(puVar16[3] + 0xdc) = *(uint *)(puVar16[3] + 0xdc) & 0xffffdeff;

      }

      for (; puVar17 != (undefined4 *)0x0; puVar17 = (undefined4 *)*puVar17) {

        iVar11 = puVar17[3];

        if ((((*(uint *)(iVar11 + 0xdc) & 0x20000000) != 0) &&

            ((*(uint *)(iVar11 + 0xd8) & 0x8000) == 0)) && (*(int *)(iVar11 + 8) != 0)) {

          fVar3 = local_6c;

          fVar4 = local_60;

          if (local_60 < local_6c) {

            fVar3 = local_60;

            fVar4 = local_6c;

          }

          if (local_68 <= local_5c) {

            local_44 = local_68;

            local_38 = local_5c;

          }

          else {

            local_44 = local_5c;

            local_38 = local_68;

          }

          if (((*(float *)(iVar11 + 0xa0) <= fVar4) && (*(float *)(iVar11 + 0xa4) <= local_38)) &&

             ((fVar3 <= *(float *)(iVar11 + 0xa0) && (local_44 <= *(float *)(iVar11 + 0xa4))))) {

            *(uint *)(iVar11 + 0xdc) = *(uint *)(iVar11 + 0xdc) | 0x100;

          }

        }

      }

      if ((DAT_005dd238 & 1) != 0) {

        return;

      }

      DAT_0059cbf0 = 0;

      DAT_0059cbe8 = 0;

      piVar12 = DAT_0059cbd8;

      puVar16 = DAT_00632d68;

      do {

        if (puVar16 == (undefined4 *)0x0) {

          if (piVar12 == (int *)0x0) {

            return;

          }

          DAT_0059cbec = 1;

          return;

        }

        iVar11 = puVar16[3];

        if ((((*(uint *)(iVar11 + 0xdc) & 0x20000000) != 0) &&

            ((*(uint *)(iVar11 + 0xd8) & 0x8000) == 0)) &&

           ((*(int *)(iVar11 + 8) != 0 &&

            (piVar22 = piVar12, (*(uint *)(iVar11 + 0xdc) & 0x100) != 0)))) {

          for (; piVar22 != (int *)0x0; piVar22 = (int *)*piVar22) {

            if (piVar22[0xe] == iVar11) goto LAB_004374a1;

          }

          piVar12 = DAT_0059cd94;

          if (DAT_0059cd94 == (int *)0x0) {

            puVar17 = (undefined4 *)

                      FUN_0053a700(10,0x3844,s_EditUndoData_00556fe0,

                                   s_C__Giants_source_main_editor_c_00556ff0,0x1011);

            *puVar17 = DAT_0059cd98;

            DAT_0059cd94 = puVar17 + 1;

            iVar18 = 0;

            DAT_0059cd98 = puVar17;

            do {

              *(int *)((int)DAT_0059cd94 + iVar18) = (int)DAT_0059cd94 + iVar18 + 0x48;

              iVar18 = iVar18 + 0x48;

            } while (iVar18 < 0x37b0);

            DAT_0059cd94[0xdec] = 0;

            piVar12 = DAT_0059cd94;

          }

          DAT_0059cd94 = (int *)*piVar12;

          piVar22 = piVar12;

          for (iVar18 = 0x12; iVar18 != 0; iVar18 = iVar18 + -1) {

            *piVar22 = 0;

            piVar22 = piVar22 + 1;

          }

          piVar12[0xe] = iVar11;

          *piVar12 = (int)DAT_0059cbd8;

          DAT_0059cbd8 = piVar12;

        }

LAB_004374a1:

        puVar16 = (undefined4 *)*puVar16;

      } while( true );

    }

    if (DAT_0059cbd8 == (int *)0x0) {

      if ((DAT_005dd238 & 1) != 0) {

        return;

      }

    }

    else if ((DAT_005dd238 & 1) != 0) {

      if ((DAT_0059cc28 != DAT_00632acd) || (DAT_0059cc2c != DAT_00632ad1)) {

        DAT_0059cc2c = (uint)DAT_00632ad1;

        piVar12 = DAT_0059cbd8;

        DAT_0059cc28 = (uint)DAT_00632acd;

        do {

          iVar11 = piVar12[0xe];

          piVar12[1] = *(int *)(iVar11 + 0xa0);

          piVar12[2] = *(int *)(iVar11 + 0xa4);

          piVar12[3] = *(int *)(iVar11 + 0xa8);

          piVar12[4] = *(int *)(iVar11 + 200);

          piVar12[5] = *(int *)(iVar11 + 0xcc);

          piVar12[6] = *(int *)(iVar11 + 0xd0);

          piVar12[7] = *(int *)(iVar11 + 0xc4);

          piVar12[8] = *(int *)(iVar11 + 0x1d4);

          piVar12[0xb] = *(int *)(iVar11 + 0xe8);

          piVar12[0xc] = *(int *)(iVar11 + 0x174);

          piVar12[9] = *(int *)(iVar11 + 0xf8);

          piVar12[10] = *(int *)(iVar11 + 0xfc);

          piVar12[0xd] = *(int *)(iVar11 + 4);

          piVar12 = (int *)*piVar12;

        } while (piVar12 != (int *)0x0);

        FUN_00455890(&DAT_0059cbf8,0x447a0000,&local_70);

        _DAT_0059cc14 = DAT_0059cbfc;

        _DAT_0059cc08 = DAT_0059cbfc;

        _DAT_0059cc10 = DAT_0059cbf8;

        _DAT_0059cc18 = DAT_0059cc00;

        _DAT_0059cc04 = DAT_0059cbf8;

        _DAT_0059cc0c = DAT_0059cc00;

      }

      if (DAT_00632acd != 0) {

        iVar11 = 0;

        piVar12 = DAT_0059cbd8;

        if (DAT_0059cbd8 == (int *)0x0) {

          return;

        }

        do {

          piVar12 = (int *)*piVar12;

          iVar11 = iVar11 + 1;

        } while (piVar12 != (int *)0x0);

        if (iVar11 < 2) {

          piVar12 = DAT_0059cbd8;

          if (DAT_0059cbd8 == (int *)0x0) {

            return;

          }

          do {

            iVar11 = piVar12[0xe];

            if ((*(uint *)(iVar11 + 0x1c8) & 0x20000000) == 0) {

              *(float *)(iVar11 + 200) = _DAT_00632b10 * 0.33333334 + *(float *)(iVar11 + 200);

              collgrid_clear_grid(piVar12[0xe]);

              pOVar1 = (OBJECT *)piVar12[0xe];

              if (*(int *)&pOVar1->field_0x1e0 == 0x5c) {

                FUN_0046fb50(pOVar1);

                iVar11 = kabutoai_is_punch_anim__FP6OBJECT(pOVar1);

                if ((iVar11 != 0) && (DAT_006330e4 != 0)) {

                  FUN_004ee150();

                  FUN_004ee1c0(pOVar1);

                  *(undefined4 *)(DAT_006330e4 + 0x4f3c) = 1;

                }

              }

            }

            else {

              FUN_00477da0(iVar11,_DAT_00632b10 * 0.2,0);

            }

            piVar12 = (int *)*piVar12;

          } while (piVar12 != (int *)0x0);

          return;

        }

        local_7c = (int *)(_DAT_00632b10 * 0.33333334);

        piVar12 = DAT_0059cbd8;

        do {

          iVar11 = piVar12[0xe];

          if ((*(uint *)(iVar11 + 0x1c8) & 0x20000000) == 0) {

            fVar25 = (float10)FUN_0050a400(&DAT_0059cc04,iVar11 + 0xa0);

            local_78 = (float)fVar25;

            fVar25 = (float10)FUN_0050a520(piVar12[0xe] + 0xa0,&DAT_0059cc04);

            local_80 = (float)fVar25;

            FUN_0050ae40(local_78 + (float)local_7c,&local_74,&local_70);

            *(float *)(piVar12[0xe] + 0xa0) = local_74 * local_80 + _DAT_0059cc04;

            *(float *)(piVar12[0xe] + 0xa4) = _DAT_0059cc08 - local_70 * local_80;

            collgrid_clear_grid(piVar12[0xe]);

            FUN_00499280(piVar12[0xe]);

            *(float *)(piVar12[0xe] + 200) = (float)local_7c + *(float *)(piVar12[0xe] + 200);

            pOVar1 = (OBJECT *)piVar12[0xe];

            if (*(int *)&pOVar1->field_0x1e0 == 0x5c) {

              FUN_0046fb50(pOVar1);

              iVar11 = kabutoai_is_punch_anim__FP6OBJECT(pOVar1);

              if ((iVar11 != 0) && (DAT_006330e4 != 0)) {

                FUN_004ee150();

                FUN_004ee1c0(pOVar1);

                *(undefined4 *)(DAT_006330e4 + 0x4f3c) = 1;

              }

            }

          }

          else {

            FUN_00477da0(iVar11,_DAT_00632b10 * 0.2,0);

          }

          piVar12 = (int *)*piVar12;

        } while (piVar12 != (int *)0x0);

        return;

      }

      if (DAT_00632ace != '\0') {

        piVar12 = DAT_0059cbd8;

        if (DAT_0059cbd8 == (int *)0x0) {

          return;

        }

        do {

          *(float *)(piVar12[0xe] + 0xcc) =

               _DAT_00632b10 * 0.33333334 + *(float *)(piVar12[0xe] + 0xcc);

          collgrid_clear_grid(piVar12[0xe]);

          pOVar1 = (OBJECT *)piVar12[0xe];

          if (*(int *)&pOVar1->field_0x1e0 == 0x5c) {

            FUN_0046fb50(pOVar1);

            iVar11 = kabutoai_is_punch_anim__FP6OBJECT(pOVar1);

            if ((iVar11 != 0) && (DAT_006330e4 != 0)) {

              FUN_004ee150();

              FUN_004ee1c0(pOVar1);

              *(undefined4 *)(DAT_006330e4 + 0x4f3c) = 1;

            }

          }

          piVar12 = (int *)*piVar12;

        } while (piVar12 != (int *)0x0);

        return;

      }

      if (DAT_00632acf != '\0') {

        piVar12 = DAT_0059cbd8;

        if (DAT_0059cbd8 == (int *)0x0) {

          return;

        }

        do {

          iVar11 = piVar12[0xe];

          if ((*(uint *)(iVar11 + 0x1c8) & 0x20000000) == 0) {

            *(float *)(iVar11 + 0xd0) = _DAT_00632b10 * 0.33333334 + *(float *)(iVar11 + 0xd0);

            collgrid_clear_grid(piVar12[0xe]);

            pOVar1 = (OBJECT *)piVar12[0xe];

            if (*(int *)&pOVar1->field_0x1e0 == 0x5c) {

              FUN_0046fb50(pOVar1);

              iVar11 = kabutoai_is_punch_anim__FP6OBJECT(pOVar1);

              if ((iVar11 != 0) && (DAT_006330e4 != 0)) {

                FUN_004ee150();

                FUN_004ee1c0(pOVar1);

                *(undefined4 *)(DAT_006330e4 + 0x4f3c) = 1;

              }

            }

          }

          else {

            FUN_00477f20(iVar11,_DAT_00632b10 * 7.2,0);

          }

          piVar12 = (int *)*piVar12;

        } while (piVar12 != (int *)0x0);

        return;

      }

      if (DAT_00632ad1 != 0) {

        iVar11 = 0;

        piVar12 = DAT_0059cbd8;

        if (DAT_0059cbd8 == (int *)0x0) {

          return;

        }

        do {

          piVar12 = (int *)*piVar12;

          iVar11 = iVar11 + 1;

        } while (piVar12 != (int *)0x0);

        piVar12 = DAT_0059cbd8;

        if (iVar11 < 2) {

          if (DAT_0059cbd8 == (int *)0x0) {

            return;

          }

          do {

            iVar11 = piVar12[0xe];

            if ((*(uint *)(iVar11 + 0x1c8) & 0x20000000) == 0) {

              *(float *)(iVar11 + 0xc4) = _DAT_00632b10 * 0.04 + *(float *)(iVar11 + 0xc4);

              if (*(float *)(piVar12[0xe] + 0xc4) < 0.1) {

                *(undefined4 *)(piVar12[0xe] + 0xc4) = 0x3dcccccd;

              }

              *(uint *)(piVar12[0xe] + 0xdc) = *(uint *)(piVar12[0xe] + 0xdc) | 0x80000000;

            }

            else {

              FUN_00477da0(iVar11,_DAT_00632b10 * 0.2,1);

            }

            piVar12 = (int *)*piVar12;

          } while (piVar12 != (int *)0x0);

          return;

        }

        do {

          iVar11 = piVar12[0xe];

          if ((*(uint *)(iVar11 + 0x1c8) & 0x20000000) == 0) {

            local_70 = *(float *)(iVar11 + 0xc4);

            *(float *)(iVar11 + 0xc4) = _DAT_00632b14 * 0.02 + *(float *)(iVar11 + 0xc4);

            if (*(float *)(piVar12[0xe] + 0xc4) < 0.1) {

              *(undefined4 *)(piVar12[0xe] + 0xc4) = 0x3dcccccd;

            }

            fVar25 = (float10)FUN_0050a400(&DAT_0059cc10,piVar12[0xe] + 0xa0);

            local_74 = (float)fVar25;

            fVar25 = (float10)FUN_0050a520(piVar12[0xe] + 0xa0,&DAT_0059cc10);

            local_7c = (int *)(float)(((float10)*(float *)(piVar12[0xe] + 0xc4) / (float10)local_70)

                                     * fVar25);

            FUN_0050ae40(local_74,&local_78,&local_80);

            *(float *)(piVar12[0xe] + 0xa0) = local_78 * (float)local_7c + _DAT_0059cc10;

            *(float *)(piVar12[0xe] + 0xa4) = _DAT_0059cc14 - local_80 * (float)local_7c;

            FUN_00499280(piVar12[0xe]);

            *(uint *)(piVar12[0xe] + 0xdc) = *(uint *)(piVar12[0xe] + 0xdc) | 0x80000000;

          }

          else {

            FUN_00477da0(iVar11,_DAT_00632b10 * 0.2,0);

          }

          piVar12 = (int *)*piVar12;

        } while (piVar12 != (int *)0x0);

        return;

      }

      if (DAT_00632ad0 != '\0') {

        piVar12 = DAT_0059cbd8;

        if (DAT_0059cbd8 == (int *)0x0) {

          return;

        }

        do {

          if ((*(uint *)(piVar12[0xe] + 0x1c8) & 0x20000000) != 0) {

            FUN_00477f20(piVar12[0xe],_DAT_00632b10 * 7.2,1);

          }

          piVar12 = (int *)*piVar12;

        } while (piVar12 != (int *)0x0);

        return;

      }

      if (DAT_00632ad2 != '\0') {

        piVar12 = DAT_0059cbd8;

        if (DAT_0059cbd8 == (int *)0x0) {

          return;

        }

        do {

          *(float *)(piVar12[0xe] + 0x1d4) = *(float *)(piVar12[0xe] + 0x1d4) - _DAT_00632b14 * 0.02

          ;

          iVar11 = piVar12[0xe];

          uVar15 = *(uint *)(iVar11 + 0x1c8);

          *(uint *)(iVar11 + 0x1c8) = uVar15 & 0xfffffff7;

          fVar25 = (float10)FUN_00413e40(iVar11 + 0xa0);

          *(uint *)(iVar11 + 0x1c8) = uVar15;

          *(float *)(iVar11 + 0xa8) = (float)(fVar25 + (float10)*(float *)(iVar11 + 0x1d4));

          FUN_00499280(iVar11);

          *(undefined4 *)(iVar11 + 0x108) = 0;

          *(uint *)(iVar11 + 0xd8) = *(uint *)(iVar11 + 0xd8) | 0x80000;

          *(uint *)(piVar12[0xe] + 0xdc) = *(uint *)(piVar12[0xe] + 0xdc) | 0x80000000;

          if ((*(uint *)(piVar12[0xe] + 0x1c8) & 0x20000000) != 0) {

            marker_spline_adjust_location(piVar12[0xe]);

          }

          pOVar1 = (OBJECT *)piVar12[0xe];

          if (*(int *)&pOVar1->field_0x1e0 == 0x5c) {

            FUN_0046fb50(pOVar1);

            iVar11 = kabutoai_is_punch_anim__FP6OBJECT(pOVar1);

            if ((iVar11 != 0) && (DAT_006330e4 != 0)) {

              FUN_004ee150();

              FUN_004ee1c0(pOVar1);

              *(undefined4 *)(DAT_006330e4 + 0x4f3c) = 1;

            }

          }

          piVar12 = (int *)*piVar12;

        } while (piVar12 != (int *)0x0);

        return;

      }

      FUN_00455890(&local_54,0x447a0000,&local_78);

      piVar12 = DAT_0059cbd8;

      if (DAT_0059cbd8 == (int *)0x0) {

        return;

      }

      do {

        if (((1.0 < ABS(_DAT_00632b10)) || (1.0 < ABS(_DAT_00632b14))) || (1.0 < ABS(_DAT_00632b18))

           ) {

          *(float *)(piVar12[0xe] + 0xa0) = local_54 - (float)piVar12[0xf];

          *(float *)(piVar12[0xe] + 0xa4) = local_50 - (float)piVar12[0x10];

          iVar11 = piVar12[0xe];

          uVar15 = *(uint *)(iVar11 + 0x1c8);

          *(uint *)(iVar11 + 0x1c8) = uVar15 & 0xfffffff7;

          fVar25 = (float10)FUN_00413e40(iVar11 + 0xa0);

          *(uint *)(iVar11 + 0x1c8) = uVar15;

          *(float *)(piVar12[0xe] + 0xa8) = (float)(fVar25 + (float10)*(float *)(iVar11 + 0x1d4));

          iVar11 = piVar12[0xe];

          if ((*(uint *)(iVar11 + 0x1c8) & 0x8000000) == 0) {

            iVar18 = *(int *)(iVar11 + 4);

            if (((iVar18 == 1099) || (iVar18 == 0x44c)) || (iVar18 == 0x44d)) {

              if (2.0 <= *(float *)(iVar11 + 0xa8)) {

                *(float *)(iVar11 + 0xa8) = *(float *)(iVar11 + 0xa8) + 2.0;

              }

              else {

                *(undefined4 *)(iVar11 + 0xa8) = 0x40000000;

              }

            }

            else if (*(int *)(iVar11 + 0x1e0) == 0x3a) goto LAB_00437d68;

          }

          else {

LAB_00437d68:

            if (*(float *)(iVar11 + 0xa8) < 0.0) {

              *(undefined4 *)(iVar11 + 0xa8) = 0;

            }

          }

          FUN_00499280(piVar12[0xe]);

          collgrid_clear_grid(piVar12[0xe]);

          if (DAT_0059cbe0 != 0) {

            FUN_00413820(piVar12[0xe]);

            iVar11 = piVar12[0xe];

            fVar25 = (float10)FUN_0050a390(*(undefined4 *)(iVar11 + 0x148),

                                           *(undefined4 *)(iVar11 + 0x14c));

            local_74 = (float)fVar25;

            fVar25 = (float10)FUN_0050a390(*(undefined4 *)(iVar11 + 0x144),

                                           *(undefined4 *)(iVar11 + 0x14c));

            local_70 = (float)fVar25;

            FUN_0050a8f0(-local_74,local_70,0,local_48);

            FUN_0050a8f0(0,0,*(undefined4 *)(piVar12[0xe] + 200),local_24);

            FUN_0050ac00(local_24,local_48,local_48);

            iVar11 = piVar12[0xe];

            FUN_0050a9e0(local_48,iVar11 + 0xcc,iVar11 + 0xd0,iVar11 + 200);

            *(float *)(piVar12[0xe] + 0xcc) = -*(float *)(piVar12[0xe] + 0xcc);

          }

          if ((*(uint *)(piVar12[0xe] + 0x1c8) & 0x20000000) != 0) {

            marker_spline_adjust_location(piVar12[0xe]);

          }

          pOVar1 = (OBJECT *)piVar12[0xe];

          if (*(int *)&pOVar1->field_0x1e0 == 0x5c) {

            FUN_0046fb50(pOVar1);

            iVar11 = kabutoai_is_punch_anim__FP6OBJECT(pOVar1);

            if ((iVar11 != 0) && (DAT_006330e4 != 0)) {

              FUN_004ee150();

              FUN_004ee1c0(pOVar1);

              *(undefined4 *)(DAT_006330e4 + 0x4f3c) = 1;

            }

          }

        }

        piVar12 = (int *)*piVar12;

        if (piVar12 == (int *)0x0) {

          return;

        }

      } while( true );

    }

    DAT_0059cbf0 = 0;

    return;

  }

  if ((DAT_005dd238 & 1) == 0) {

    if (DAT_00632ad3 != '\0') {

      if (DAT_0059cc44 == (int *)0x0) {

        return;

      }

      uVar7 = 0;

      uVar8 = 0;

      if ((DAT_0059cc40 & 2) != 0) {

        return;

      }

      while (DAT_00632aad = uVar8, DAT_0059cbf0 = uVar7, piVar12 = DAT_0059cbd8,

            piVar12 != (int *)0x0) {

        DAT_0059cbd8 = (int *)*piVar12;

        *piVar12 = (int)DAT_0059cd94;

        uVar7 = DAT_0059cbf0;

        DAT_0059cd94 = piVar12;

        uVar8 = DAT_00632aad;

      }

      DAT_0059cbd8 = (undefined4 *)0x0;

      DAT_0059cbec = 0;

      piVar12 = DAT_0059cc44;

      if ((DAT_0059cc40 & 8) != 0) {

        for (; piVar12 != (int *)0x0; piVar12 = (int *)*piVar12) {

          iVar11 = main_editor_004380e0(piVar12[0xd]);

          piVar12[0xe] = iVar11;

          main_editor_004382b0(iVar11,piVar12);

          if ((*(uint *)(piVar12[0xe] + 0x1c8) & 0x8000000) != 0) {

            piVar22 = (int *)(piVar12[0xe] + 0x174);

            *piVar22 = *piVar22 + 1;

            FUN_00476f90(piVar12[0xe]);

          }

        }

      }

      ppiVar6 = &local_7c;

      for (piVar12 = DAT_0059cc44; piVar12 != (int *)0x0; piVar12 = (int *)*piVar12) {

        ppiVar14 = (int **)main_editor_004415d0();

        piVar22 = piVar12;

        ppiVar24 = ppiVar14;

        for (iVar11 = 0x12; iVar11 != 0; iVar11 = iVar11 + -1) {

          *ppiVar24 = (int *)*piVar22;

          piVar22 = piVar22 + 1;

          ppiVar24 = ppiVar24 + 1;

        }

        *ppiVar6 = (int *)ppiVar14;

        ppiVar6 = ppiVar14;

      }

      *ppiVar6 = (int *)0x0;

      for (piVar12 = local_7c; piVar22 = DAT_0059cc44, piVar21 = DAT_0059cc44, piVar12 != (int *)0x0

          ; piVar12 = (int *)*piVar12) {

        main_editor_00438230(piVar12[0xe],piVar12);

      }

      for (; DAT_0059cc44 = piVar22, piVar21 != (int *)0x0; piVar21 = (int *)*piVar21) {

        main_editor_004382b0(piVar21[0xe],piVar21);

        piVar22 = DAT_0059cc44;

      }

      uVar15 = DAT_0059cc40 | 2;

      DAT_0059cc40 = uVar15;

      FUN_00543270(&DAT_0059cc40,&DAT_0059cc48,0xc0);

      _DAT_0059cd00 = uVar15;

      while (piVar22 != (int *)0x0) {

        piVar12 = (int *)*piVar22;

        *piVar22 = (int)DAT_0059cd94;

        DAT_0059cd94 = piVar22;

        piVar22 = piVar12;

      }

      DAT_0059cd04 = local_7c;

      if ((_DAT_0059cd00 & 4) != 0) {

        piVar12 = local_7c;

        if (local_7c == (int *)0x0) {

          return;

        }

        do {

          iVar11 = piVar12[0xe];

          if (iVar11 != 0) {

            if ((*(uint *)(iVar11 + 0x1c8) & 0x8000000) != 0) {

              FUN_00476ff0(iVar11);

            }

            if (*(int *)(piVar12[0xe] + 0x1e0) == 0x61) {

              FUN_004782f0(piVar12[0xe]);

            }

            FUN_00497510(piVar12[0xe]);

          }

          piVar12[0xe] = 0;

          piVar12 = (int *)*piVar12;

        } while (piVar12 != (int *)0x0);

        return;

      }

      piVar22 = (int *)&DAT_0059cbd8;

      for (piVar12 = local_7c; piVar12 != (int *)0x0; piVar12 = (int *)*piVar12) {

        piVar13 = (int *)main_editor_004415d0();

        piVar21 = piVar12;

        piVar23 = piVar13;

        for (iVar11 = 0x12; iVar11 != 0; iVar11 = iVar11 + -1) {

          *piVar23 = *piVar21;

          piVar21 = piVar21 + 1;

          piVar23 = piVar23 + 1;

        }

        *piVar22 = (int)piVar13;

        piVar22 = piVar13;

      }

      *piVar22 = 0;

      iVar11 = 0;

      for (puVar16 = DAT_0059cbd8; puVar16 != (undefined4 *)0x0; puVar16 = (undefined4 *)*puVar16) {

        iVar11 = iVar11 + 1;

      }

      DAT_0059cbec = (uint)(1 < iVar11);

      return;

    }

    if (DAT_00632ad4 != '\0') {

      if (DAT_0059cd04 == (int *)0x0) {

        return;

      }

      uVar7 = 0;

      uVar8 = 0;

      uVar9 = 0;

      if ((_DAT_0059cd00 & 2) == 0) {

        return;

      }

      while (DAT_00632ad3 = uVar9, DAT_00632aad = uVar8, DAT_0059cbf0 = uVar7,

            piVar12 = DAT_0059cbd8, piVar12 != (int *)0x0) {

        DAT_0059cbd8 = (int *)*piVar12;

        *piVar12 = (int)DAT_0059cd94;

        uVar7 = DAT_0059cbf0;

        DAT_0059cd94 = piVar12;

        uVar8 = DAT_00632aad;

        uVar9 = DAT_00632ad3;

      }

      DAT_0059cbd8 = (undefined4 *)0x0;

      DAT_0059cbec = 0;

      piVar12 = DAT_0059cd04;

      if ((_DAT_0059cd00 & 4) != 0) {

        for (; piVar12 != (int *)0x0; piVar12 = (int *)*piVar12) {

          iVar11 = main_editor_004380e0(piVar12[0xd]);

          piVar12[0xe] = iVar11;

          main_editor_004382b0(iVar11,piVar12);

          if ((*(uint *)(piVar12[0xe] + 0x1c8) & 0x8000000) != 0) {

            piVar22 = (int *)(piVar12[0xe] + 0x174);

            *piVar22 = *piVar22 + 1;

            FUN_00476f90(piVar12[0xe]);

          }

        }

      }

      ppiVar6 = &local_7c;

      for (piVar12 = DAT_0059cd04; piVar12 != (int *)0x0; piVar12 = (int *)*piVar12) {

        ppiVar14 = (int **)main_editor_004415d0();

        piVar22 = piVar12;

        ppiVar24 = ppiVar14;

        for (iVar11 = 0x12; iVar11 != 0; iVar11 = iVar11 + -1) {

          *ppiVar24 = (int *)*piVar22;

          piVar22 = piVar22 + 1;

          ppiVar24 = ppiVar24 + 1;

        }

        *ppiVar6 = (int *)ppiVar14;

        ppiVar6 = ppiVar14;

      }

      *ppiVar6 = (int *)0x0;

      for (piVar12 = local_7c; piVar22 = DAT_0059cd04, piVar21 = DAT_0059cd04, piVar12 != (int *)0x0

          ; piVar12 = (int *)*piVar12) {

        main_editor_00438230(piVar12[0xe],piVar12);

      }

      for (; DAT_0059cd04 = piVar22, piVar21 != (int *)0x0; piVar21 = (int *)*piVar21) {

        main_editor_004382b0(piVar21[0xe],piVar21);

        piVar22 = DAT_0059cd04;

      }

      uVar15 = _DAT_0059cd00 & 0xfffffffd;

      _DAT_0059cd00 = uVar15;

      FUN_00543270(&DAT_0059cc48,&DAT_0059cc40,0xc0);

      DAT_0059cc40 = uVar15;

      while (piVar12 = piVar22, piVar12 != (int *)0x0) {

        piVar22 = (int *)*piVar12;

        *piVar12 = (int)DAT_0059cd94;

        DAT_0059cd94 = piVar12;

      }

      DAT_0059cc44 = local_7c;

      if ((DAT_0059cc40 & 8) != 0) {

        piVar12 = local_7c;

        if (local_7c == (int *)0x0) {

          return;

        }

        do {

          iVar11 = piVar12[0xe];

          if (iVar11 != 0) {

            if ((*(uint *)(iVar11 + 0x1c8) & 0x8000000) != 0) {

              FUN_00476ff0(iVar11);

            }

            if (*(int *)(piVar12[0xe] + 0x1e0) == 0x61) {

              FUN_004782f0(piVar12[0xe]);

            }

            FUN_00497510(piVar12[0xe]);

          }

          piVar12[0xe] = 0;

          piVar12 = (int *)*piVar12;

        } while (piVar12 != (int *)0x0);

        return;

      }

      piVar22 = (int *)&DAT_0059cbd8;

      for (piVar12 = local_7c; piVar12 != (int *)0x0; piVar12 = (int *)*piVar12) {

        piVar21 = DAT_0059cd94;

        if (DAT_0059cd94 == (int *)0x0) {

          puVar16 = (undefined4 *)

                    FUN_0053a700(10,0x3844,s_EditUndoData_00556fe0,

                                 s_C__Giants_source_main_editor_c_00556ff0,0x1011);

          *puVar16 = DAT_0059cd98;

          DAT_0059cd94 = puVar16 + 1;

          iVar11 = 0;

          DAT_0059cd98 = puVar16;

          do {

            *(int *)((int)DAT_0059cd94 + iVar11) = (int)DAT_0059cd94 + iVar11 + 0x48;

            iVar11 = iVar11 + 0x48;

          } while (iVar11 < 0x37b0);

          DAT_0059cd94[0xdec] = 0;

          piVar21 = DAT_0059cd94;

        }

        DAT_0059cd94 = (int *)*piVar21;

        piVar23 = piVar21;

        for (iVar11 = 0x12; iVar11 != 0; iVar11 = iVar11 + -1) {

          *piVar23 = 0;

          piVar23 = piVar23 + 1;

        }

        piVar23 = piVar12;

        piVar13 = piVar21;

        for (iVar11 = 0x12; iVar11 != 0; iVar11 = iVar11 + -1) {

          *piVar13 = *piVar23;

          piVar23 = piVar23 + 1;

          piVar13 = piVar13 + 1;

        }

        *piVar22 = (int)piVar21;

        piVar22 = piVar21;

      }

      *piVar22 = 0;

      iVar11 = 0;

      for (puVar16 = DAT_0059cbd8; puVar16 != (undefined4 *)0x0; puVar16 = (undefined4 *)*puVar16) {

        iVar11 = iVar11 + 1;

      }

      DAT_0059cbec = (uint)(1 < iVar11);

      return;

    }

    DAT_00632aad = 0;

    DAT_0059cbf0 = 0;

    DAT_00632ad3 = 0;

    DAT_00632ad4 = 0;

    piVar12 = DAT_0059cbd8;

    puVar16 = DAT_00632d68;

    if ((DAT_00632ab9 != '\0') && (DAT_0059cbd8 != (int *)0x0)) {

      DAT_00632aad = 0;

      DAT_0059cbf0 = 0;

      DAT_00632ad3 = 0;

      DAT_00632ad4 = 0;

      for (; puVar16 != (undefined4 *)0x0; puVar16 = (undefined4 *)*puVar16) {

        *(uint *)(puVar16[3] + 0xdc) = *(uint *)(puVar16[3] + 0xdc) & 0xffffdeff;

      }

      while (piVar12 = DAT_0059cd04, piVar12 != (int *)0x0) {

        DAT_0059cd04 = (int *)*piVar12;

        *piVar12 = (int)DAT_0059cd94;

        DAT_0059cd94 = piVar12;

      }

      _DAT_0059cd00 = 0;

      DAT_0059cd04 = (int *)0x0;

      FUN_00543270(&DAT_0059cc48,&DAT_0059cc40,0xc0);

      if ((_DAT_0059cd00 & 2) != 0) {

        while (piVar12 = DAT_0059cd04, piVar12 != (int *)0x0) {

          DAT_0059cd04 = (int *)*piVar12;

          *piVar12 = (int)DAT_0059cd94;

          DAT_0059cd94 = piVar12;

        }

        _DAT_0059cd00 = 0;

        DAT_0059cd04 = (int *)0x0;

      }

      DAT_0059cc40 = 8;

      DAT_0059cc44 = (int *)0x0;

      for (piVar12 = DAT_0059cbd8; piVar22 = DAT_0059cbd8, piVar21 = DAT_0059cbd8,

          piVar12 != (int *)0x0; piVar12 = (int *)*piVar12) {

        iVar11 = piVar12[0xe];

        piVar12[1] = *(int *)(iVar11 + 0xa0);

        piVar12[2] = *(int *)(iVar11 + 0xa4);

        piVar12[3] = *(int *)(iVar11 + 0xa8);

        piVar12[4] = *(int *)(iVar11 + 200);

        piVar12[5] = *(int *)(iVar11 + 0xcc);

        piVar12[6] = *(int *)(iVar11 + 0xd0);

        piVar12[7] = *(int *)(iVar11 + 0xc4);

        piVar12[8] = *(int *)(iVar11 + 0x1d4);

        piVar12[0xb] = *(int *)(iVar11 + 0xe8);

        piVar12[0xc] = *(int *)(iVar11 + 0x174);

        piVar12[9] = *(int *)(iVar11 + 0xf8);

        piVar12[10] = *(int *)(iVar11 + 0xfc);

        piVar12[0xd] = *(int *)(iVar11 + 4);

      }

      for (; piVar21 != (int *)0x0; piVar21 = (int *)*piVar21) {

        iVar11 = piVar21[0xe];

        DAT_0059cbd8 = piVar22;

        if (iVar11 != 0) {

          if ((*(uint *)(iVar11 + 0x1c8) & 0x8000000) != 0) {

            FUN_00476ff0(iVar11);

          }

          if (*(int *)(piVar21[0xe] + 0x1e0) == 0x61) {

            FUN_004782f0(piVar21[0xe]);

          }

          FUN_00497510(piVar21[0xe]);

        }

        piVar21[0xe] = 0;

        piVar22 = DAT_0059cbd8;

      }

      DAT_0059cbd8 = (int *)0x0;

      DAT_0059cc44 = piVar22;

      return;

    }

    for (; DAT_0059cbd8 = piVar12, puVar16 != (undefined4 *)0x0; puVar16 = (undefined4 *)*puVar16) {

      *(uint *)(puVar16[3] + 0xdc) = *(uint *)(puVar16[3] + 0xdc) & 0xffffdeff;

      piVar12 = DAT_0059cbd8;

    }

    if (piVar12 == (int *)0x0) {

      return;

    }

    do {

      *(uint *)(piVar12[0xe] + 0xdc) = *(uint *)(piVar12[0xe] + 0xdc) | 0x100;

      piVar12 = (int *)*piVar12;

    } while (piVar12 != (int *)0x0);

    return;

  }

  iVar11 = main_editor_00437fa0(1);

  if (DAT_00632ad5 == '\0') {

    piVar12 = DAT_0059cbd8;

    if (iVar11 != 0) {

      for (; piVar12 != (int *)0x0; piVar12 = (int *)*piVar12) {

        if (piVar12[0xe] == iVar11) goto LAB_0043670e;

      }

    }

    while (piVar12 = DAT_0059cbd8, piVar12 != (int *)0x0) {

      DAT_0059cbd8 = (int *)*piVar12;

      *piVar12 = (int)DAT_0059cd94;

      DAT_0059cd94 = piVar12;

    }

    DAT_0059cbd8 = (int *)0x0;

    DAT_0059cbec = 0;

  }

LAB_0043670e:

  iVar11 = main_editor_00437fa0(1);

  piVar12 = DAT_0059cbd8;

  if (iVar11 == 0) goto LAB_004367b5;

  for (; piVar22 = DAT_0059cbd8, piVar12 != (int *)0x0; piVar12 = (int *)*piVar12) {

    if (piVar12[0xe] == iVar11) {

      if (DAT_00632ad5 == '\0') goto LAB_004367b5;

      if (DAT_0059cbec == 0) goto LAB_004367a6;

      piVar12 = (int *)&DAT_0059cbd8;

      goto LAB_00436780;

    }

  }

  for (; piVar22 != (int *)0x0; piVar22 = (int *)*piVar22) {

    if (piVar22[0xe] == iVar11) goto LAB_004367a6;

  }

  piVar12 = (int *)main_editor_004415d0();

  piVar12[0xe] = iVar11;

  *piVar12 = (int)DAT_0059cbd8;

  DAT_0059cbd8 = piVar12;

  goto LAB_004367a6;

  while (piVar12 = piVar22, *piVar22 != 0) {

LAB_00436780:

    piVar22 = (int *)*piVar12;

    if (piVar22[0xe] == iVar11) {

      *piVar12 = *piVar22;

      *piVar22 = (int)DAT_0059cd94;

      DAT_0059cd94 = piVar22;

      break;

    }

  }

LAB_004367a6:

  if (DAT_00632ad5 != '\0') {

    DAT_0059cbec = 1;

  }

LAB_004367b5:

  if (DAT_00632acc == '\0') {

    if (DAT_0059cbd8 == (int *)0x0) {

      DAT_0059cbe8 = 1;

      FUN_00455890(&DAT_0059cc1c,0x447a0000,&local_70);

    }

    else {

      DAT_0059cbf4 = *(int *)(DAT_0059cbd8[0xe] + 4);

    }

  }

  else {

    piVar12 = DAT_0059cbd8;

    if (DAT_0059cbd8 == (int *)0x0) {

      if ((DAT_0059cbf4 != 0) &&

         (iVar11 = main_editor_004380e0(DAT_0059cbf4), piVar12 = DAT_0059cbd8, iVar11 != 0)) {

        for (; piVar12 != (int *)0x0; piVar12 = (int *)*piVar12) {

          if (piVar12[0xe] == iVar11) goto LAB_004368ab;

        }

        piVar12 = (int *)main_editor_004415d0();

        piVar12[0xe] = iVar11;

        *piVar12 = (int)DAT_0059cbd8;

        DAT_0059cbd8 = piVar12;

      }

    }

    else {

      do {

        main_editor_00438230(piVar12[0xe],piVar12);

        piVar12 = (int *)*piVar12;

        piVar22 = DAT_0059cbd8;

      } while (piVar12 != (int *)0x0);

      for (; piVar22 != (int *)0x0; piVar22 = (int *)*piVar22) {

        iVar11 = main_editor_004380e0(piVar22[0xd]);

        piVar22[0xe] = iVar11;

        main_editor_004382b0(iVar11,piVar22);

        if ((*(uint *)(piVar22[0xe] + 0x1c8) & 0x8000000) != 0) {

          piVar12 = (int *)(piVar22[0xe] + 0x174);

          *piVar12 = *piVar12 + 1;

          FUN_00476f90(piVar22[0xe]);

        }

      }

    }

  }

LAB_004368ab:

  DAT_0059cbf0 = 1;

  if (DAT_0059cbe8 == 0) {

    piVar12 = DAT_0059cbd8;

    puVar16 = DAT_00632d68;

    if (DAT_0059cbd8 == (int *)0x0) {

      for (; DAT_0059cbd8 = piVar12, puVar16 != (undefined4 *)0x0; puVar16 = (undefined4 *)*puVar16)

      {

        *(uint *)(puVar16[3] + 0xdc) = *(uint *)(puVar16[3] + 0xdc) & 0xffffdeff;

        piVar12 = DAT_0059cbd8;

      }

      if (piVar12 != (int *)0x0) {

        do {

          *(uint *)(piVar12[0xe] + 0xdc) = *(uint *)(piVar12[0xe] + 0xdc) | 0x100;

          piVar12 = (int *)*piVar12;

        } while (piVar12 != (int *)0x0);

        return;

      }

    }

    else {

      for (; puVar16 != (undefined4 *)0x0; puVar16 = (undefined4 *)*puVar16) {

        *(uint *)(puVar16[3] + 0xdc) = *(uint *)(puVar16[3] + 0xdc) & 0xffffdeff;

      }

      FUN_00455890(&DAT_0059cbf8,0x447a0000,&local_70);

      DAT_0059cc2c = 0;

      DAT_0059cc28 = 0;

      _DAT_0059cc10 = DAT_0059cbf8;

      _DAT_0059cc04 = DAT_0059cbf8;

      _DAT_0059cc14 = DAT_0059cbfc;

      _DAT_0059cc18 = DAT_0059cc00;

      _DAT_0059cc08 = DAT_0059cbfc;

      _DAT_0059cc0c = DAT_0059cc00;

      while (piVar12 = DAT_0059cd04, piVar12 != (int *)0x0) {

        DAT_0059cd04 = (int *)*piVar12;

        *piVar12 = (int)DAT_0059cd94;

        DAT_0059cd94 = piVar12;

      }

      _DAT_0059cd00 = 0;

      DAT_0059cd04 = (int *)0x0;

      FUN_00543270(&DAT_0059cc48,&DAT_0059cc40,0xc0);

      if ((_DAT_0059cd00 & 2) != 0) {

        while (piVar12 = DAT_0059cd04, piVar12 != (int *)0x0) {

          DAT_0059cd04 = (int *)*piVar12;

          *piVar12 = (int)DAT_0059cd94;

          DAT_0059cd94 = piVar12;

        }

        _DAT_0059cd00 = 0;

        DAT_0059cd04 = (int *)0x0;

      }

      DAT_0059cc40 = 0;

      DAT_0059cc44 = (int *)0x0;

      for (piVar12 = DAT_0059cbd8; piVar12 != (int *)0x0; piVar12 = (int *)*piVar12) {

        main_editor_00438230(piVar12[0xe],piVar12);

      }

      piVar22 = (int *)&DAT_0059cc44;

      for (piVar12 = DAT_0059cbd8; piVar12 != (int *)0x0; piVar12 = (int *)*piVar12) {

        piVar13 = (int *)main_editor_004415d0();

        piVar21 = piVar12;

        piVar23 = piVar13;

        for (iVar11 = 0x12; iVar11 != 0; iVar11 = iVar11 + -1) {

          *piVar23 = *piVar21;

          piVar21 = piVar21 + 1;

          piVar23 = piVar23 + 1;

        }

        *piVar22 = (int)piVar13;

        piVar22 = piVar13;

      }

      *piVar22 = 0;

      if (DAT_00632acc != '\0') {

        DAT_0059cc40 = DAT_0059cc40 | 4;

      }

      piVar12 = DAT_0059cbd8;

      if (DAT_0059cbd8 != (int *)0x0) {

        do {

          iVar11 = piVar12[0xe];

          piVar12[0xf] = (int)(*(float *)(iVar11 + 0xa0) - *(float *)(DAT_0059cbd8[0xe] + 0xa0));

          piVar12[0x10] = (int)(*(float *)(iVar11 + 0xa4) - *(float *)(DAT_0059cbd8[0xe] + 0xa4));

          piVar12[0x11] = (int)(*(float *)(iVar11 + 0xa8) - *(float *)(DAT_0059cbd8[0xe] + 0xa8));

          piVar12 = (int *)*piVar12;

        } while (piVar12 != (int *)0x0);

        return;

      }

    }

  }

  return;

}

/* ===== main_editor_00438350 @ 0x00438350 ===== */
void main_editor_00438350(void)



{

  char cVar1;

  bool bVar2;

  int iVar3;

  int iVar4;

  byte *pbVar5;

  uint uVar6;

  char *pcVar7;

  int *piVar8;

  char *pcVar9;

  uint uVar10;

  int iVar11;

  int iVar12;

  undefined4 *puVar13;

  int local_a8;

  int local_a4;

  char local_a0 [80];

  char local_50 [80];

  

  if (DAT_0059cd34 < 1) {

    puVar13 = &DAT_0059cbd8;

    for (iVar3 = 0x4c; iVar3 != 0; iVar3 = iVar3 + -1) {

      *puVar13 = 0;

      puVar13 = puVar13 + 1;

    }

    DAT_0059cbe4 = 1;

    FUN_004ed9e0(&LAB_004386c0);

    iVar3 = 0;

    DAT_0059cd34 = 0;

    for (puVar13 = DAT_00632d54; puVar13 != (undefined4 *)0x0; puVar13 = (undefined4 *)*puVar13) {

      iVar4 = 0;

      if (0 < (int)puVar13[1]) {

        piVar8 = puVar13 + 3;

        do {

          if (*piVar8 != 0) {

            iVar3 = iVar3 + 1;

            DAT_0059cd34 = iVar3;

          }

          iVar4 = iVar4 + 1;

          piVar8 = piVar8 + 0xc1;

        } while (iVar4 < (int)puVar13[1]);

      }

    }

    DAT_0059cd30 = FUN_0053a700(10,iVar3 * 0x24,s_objids_00557080,

                                s_C__Giants_source_main_editor_c_00556ff0,0x4c4);

    iVar3 = 0;

    uVar10 = 0;

    local_a8 = 0;

    for (puVar13 = DAT_00632d54; puVar13 != (undefined4 *)0x0; puVar13 = (undefined4 *)*puVar13) {

      iVar4 = 0;

      if (0 < (int)puVar13[1]) {

        pbVar5 = (byte *)((int)puVar13 + 0x1fe);

        do {

          if (*(int *)(pbVar5 + -0x1f2) != 0) {

            *(int *)(DAT_0059cd30 + iVar3 * 0x24) = *(int *)(pbVar5 + -0x1f2);

            *(undefined1 *)(DAT_0059cd30 + 4 + local_a8 * 0x24) = 0;

            if (uVar10 < *pbVar5) {

              uVar10 = (uint)*pbVar5;

            }

            iVar3 = local_a8 + 1;

            local_a8 = iVar3;

          }

          iVar4 = iVar4 + 1;

          pbVar5 = pbVar5 + 0x304;

        } while (iVar4 < (int)puVar13[1]);

      }

    }

    DAT_0059cd2c = FUN_0053a700(10,(uVar10 + 1) * 0x24,s_groupids_00557074,

                                s_C__Giants_source_main_editor_c_00556ff0,0x4d5);

    iVar3 = 0;

    iVar4 = 0;

    do {

      FUN_00542f27(iVar4 + 4 + DAT_0059cd2c,s_Group_d_0055706c,iVar3);

      iVar3 = iVar3 + 1;

      iVar4 = iVar4 + 0x24;

    } while (iVar3 <= (int)uVar10);

    DAT_0059cd38 = uVar10 + 1;

    local_a4 = BinFileSeek_2(s_bld_yy_names_bld_00557054,&DAT_00557068);

    if (local_a4 != 0) {

LAB_004384e0:

      iVar3 = FUN_005440c1(local_a0,0x50,local_a4);

      uVar6 = 0xffffffff;

      pcVar9 = local_a0;

      do {

        if (uVar6 == 0) break;

        uVar6 = uVar6 - 1;

        cVar1 = *pcVar9;

        pcVar9 = pcVar9 + 1;

      } while (cVar1 != '\0');

      bVar2 = 0x4b < ~uVar6 - 1;

      iVar4 = 0;

      if (iVar3 != 0) {

        local_a8 = 0;

        FUN_0054408d(iVar3,s__define_ObjObj_s__d_00557040,local_50,&local_a8);

        if (local_a8 == 0) {

          local_a8 = -1;

          FUN_0054408d(iVar3,s__define_ObjGroup_s__d_00557018,local_50,&local_a8);

          if ((-1 < local_a8) && (local_a8 <= (int)uVar10)) {

            if (bVar2) {

              FUN_00542f27(&DAT_00657400,s__s_is_too_long_00557030,local_a0);

              FUN_0051ea20(&DAT_00657400);

            }

            pcVar7 = local_50;

            pcVar9 = (char *)(DAT_0059cd2c + 4 + local_a8 * 0x24);

            do {

              cVar1 = *pcVar7;

              pcVar7 = pcVar7 + 1;

              *pcVar9 = cVar1;

              pcVar9 = pcVar9 + 1;

            } while (cVar1 != '\0');

          }

        }

        else {

          if (bVar2) {

            FUN_00542f27(&DAT_00657400,s__s_is_too_long_00557030,local_a0);

            FUN_0051ea20(&DAT_00657400);

          }

          if (0 < DAT_0059cd34) {

            iVar11 = 0;

            iVar3 = DAT_0059cd30;

            do {

              if (*(int *)(iVar11 + iVar3) == local_a8) {

                pcVar7 = local_50;

                pcVar9 = (char *)(iVar11 + 4 + iVar3);

                do {

                  cVar1 = *pcVar7;

                  pcVar7 = pcVar7 + 1;

                  *pcVar9 = cVar1;

                  pcVar9 = pcVar9 + 1;

                  iVar3 = DAT_0059cd30;

                } while (cVar1 != '\0');

              }

              iVar4 = iVar4 + 1;

              iVar11 = iVar11 + 0x24;

            } while (iVar4 < DAT_0059cd34);

          }

        }

        goto LAB_004384e0;

      }

      FUN_0054384c(local_a4);

    }

    iVar11 = 0;

    iVar3 = DAT_0059cd30;

    iVar4 = DAT_0059cd34;

    if (0 < DAT_0059cd34) {

      iVar12 = 0;

      do {

        if (*(char *)(iVar12 + 4 + iVar3) == '\0') {

          FUN_00542f27(iVar12 + 4 + iVar3,s_Obj_d_00557010,*(undefined4 *)(iVar12 + iVar3));

          iVar3 = DAT_0059cd30;

          iVar4 = DAT_0059cd34;

        }

        iVar11 = iVar11 + 1;

        iVar12 = iVar12 + 0x24;

      } while (iVar11 < iVar4);

    }

    FUN_00543bc3(iVar3,iVar4,0x24,&LAB_004386a0);

  }

  return;

}

/* ===== main_editor_0043a590 @ 0x0043A590 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void main_editor_0043a590(void)



{

  undefined4 *puVar1;

  undefined4 uVar2;

  int iVar3;

  undefined4 *puVar4;

  undefined4 *puVar5;

  undefined4 *puVar6;

  int iVar7;

  undefined4 *puVar8;

  

  uVar2 = main_dlog_00428460(DAT_0059cd54,1);

  iVar3 = main_dlog_00428670(DAT_0059cd54,1,uVar2);

  DAT_0059cd40 = iVar3;

  if (DAT_0059cc3c == 4) {

    DAT_0059cc30 = *(undefined4 *)(DAT_0059cd30 + iVar3 * 0x24);

    main_editor_00439490();

    DAT_0059cc38 = 6;

    FUN_004959C0();

    FUN_00426F40(&LAB_00438ef0,&LAB_00438dd0);

    DAT_00632ab0 = 0;

    DAT_00632aad = 0;

    DAT_00632aaa = 0;

    FUN_00519C70();

    main_editor_00438350();

    switch(DAT_0059cc38) {

    case 0:

      wredit_menu_draw();

      return;

    case 1:

      main_editor_00439df0();

      return;

    case 2:

      main_editor_0043a440();

      return;

    case 3:

      wredit_obj_info();

      return;

    case 4:

      wredit_lock_menu();

      return;

    case 5:

      wredit_flick_menu();

      return;

    case 6:

      wredit_lock_list();

      return;

    case 7:

      wredit_ai_menu();

      return;

    case 8:

      main_editor_00440230();

      return;

    case 9:

      wredit_marker_info3();

      return;

    case 10:

      wredit_marker_info();

      return;

    case 0xb:

      wredit_marker_info2();

      return;

    case 0xc:

      wredit_trigger_menu();

      return;

    }

  }

  else {

    main_editor_00439490();

    if (DAT_0059cbd8 == (undefined4 *)0x0) {

      uVar2 = main_editor_004380e0(*(undefined4 *)(DAT_0059cd30 + iVar3 * 0x24));

      while (puVar5 = DAT_0059cbd8, puVar5 != (undefined4 *)0x0) {

        DAT_0059cbd8 = (undefined4 *)*puVar5;

        *puVar5 = DAT_0059cd94;

        DAT_0059cd94 = puVar5;

      }

      DAT_0059cbd8 = (undefined4 *)0x0;

      puVar5 = (undefined4 *)main_editor_004415d0();

      puVar5[0xe] = uVar2;

      *puVar5 = DAT_0059cbd8;

      DAT_0059cbd8 = puVar5;

      do {

        main_editor_00438230(puVar5[0xe],puVar5);

        puVar5 = (undefined4 *)*puVar5;

      } while (puVar5 != (undefined4 *)0x0);

      while (puVar5 = DAT_0059cd04, puVar5 != (undefined4 *)0x0) {

        DAT_0059cd04 = (undefined4 *)*puVar5;

        *puVar5 = DAT_0059cd94;

        DAT_0059cd94 = puVar5;

      }

      _DAT_0059cd00 = 0;

      DAT_0059cd04 = (undefined4 *)0x0;

      FUN_00543270(&DAT_0059cc48,&DAT_0059cc40,0xc0);

      if ((_DAT_0059cd00 & 2) != 0) {

        while (puVar5 = DAT_0059cd04, puVar5 != (undefined4 *)0x0) {

          DAT_0059cd04 = (undefined4 *)*puVar5;

          *puVar5 = DAT_0059cd94;

          DAT_0059cd94 = puVar5;

        }

        _DAT_0059cd00 = 0;

        DAT_0059cd04 = (undefined4 *)0x0;

      }

      DAT_0059cc40 = 0;

      DAT_0059cc44 = 0;

      puVar1 = &DAT_0059cc44;

      for (puVar5 = DAT_0059cbd8; puVar5 != (undefined4 *)0x0; puVar5 = (undefined4 *)*puVar5) {

        puVar6 = DAT_0059cd94;

        if (DAT_0059cd94 == (undefined4 *)0x0) {

          puVar6 = (undefined4 *)

                   FUN_0053a700(10,0x3844,s_EditUndoData_00556fe0,

                                s_C__Giants_source_main_editor_c_00556ff0,0x1011);

          *puVar6 = DAT_0059cd98;

          DAT_0059cd94 = puVar6 + 1;

          iVar3 = 0;

          DAT_0059cd98 = puVar6;

          do {

            *(int *)(iVar3 + (int)DAT_0059cd94) = iVar3 + 0x48 + (int)DAT_0059cd94;

            iVar3 = iVar3 + 0x48;

          } while (iVar3 < 0x37b0);

          DAT_0059cd94[0xdec] = 0;

          puVar6 = DAT_0059cd94;

        }

        DAT_0059cd94 = (undefined4 *)*puVar6;

        puVar8 = puVar6;

        for (iVar3 = 0x12; iVar3 != 0; iVar3 = iVar3 + -1) {

          *puVar8 = 0;

          puVar8 = puVar8 + 1;

        }

        puVar8 = puVar5;

        puVar4 = puVar6;

        for (iVar3 = 0x12; iVar3 != 0; iVar3 = iVar3 + -1) {

          *puVar4 = *puVar8;

          puVar8 = puVar8 + 1;

          puVar4 = puVar4 + 1;

        }

        *puVar1 = puVar6;

        puVar1 = puVar6;

      }

      *puVar1 = 0;

      DAT_0059cc40 = DAT_0059cc40 | 4;

    }

    else {

      puVar5 = DAT_0059cbd8;

      if (*(int *)(DAT_0059cbd8[0xe] + 4) != *(int *)(iVar3 * 0x24 + DAT_0059cd30)) {

        do {

          main_editor_00438230(puVar5[0xe],puVar5);

          puVar5 = (undefined4 *)*puVar5;

        } while (puVar5 != (undefined4 *)0x0);

        FUN_00497510(DAT_0059cbd8[0xe]);

        while (puVar5 = DAT_0059cd04, puVar5 != (undefined4 *)0x0) {

          DAT_0059cd04 = (undefined4 *)*puVar5;

          *puVar5 = DAT_0059cd94;

          DAT_0059cd94 = puVar5;

        }

        _DAT_0059cd00 = 0;

        DAT_0059cd04 = (undefined4 *)0x0;

        FUN_00543270(&DAT_0059cc48,&DAT_0059cc40,0xc0);

        if ((_DAT_0059cd00 & 2) != 0) {

          while (puVar5 = DAT_0059cd04, puVar5 != (undefined4 *)0x0) {

            DAT_0059cd04 = (undefined4 *)*puVar5;

            *puVar5 = DAT_0059cd94;

            DAT_0059cd94 = puVar5;

          }

          _DAT_0059cd00 = 0;

          DAT_0059cd04 = (undefined4 *)0x0;

        }

        DAT_0059cc40 = 0;

        DAT_0059cc44 = 0;

        puVar1 = &DAT_0059cc44;

        for (puVar5 = DAT_0059cbd8; puVar5 != (undefined4 *)0x0; puVar5 = (undefined4 *)*puVar5) {

          puVar4 = (undefined4 *)main_editor_004415d0();

          puVar6 = puVar5;

          puVar8 = puVar4;

          for (iVar7 = 0x12; iVar7 != 0; iVar7 = iVar7 + -1) {

            *puVar8 = *puVar6;

            puVar6 = puVar6 + 1;

            puVar8 = puVar8 + 1;

          }

          *puVar1 = puVar4;

          puVar1 = puVar4;

        }

        *puVar1 = 0;

        uVar2 = main_editor_004380e0(*(undefined4 *)(iVar3 * 0x24 + DAT_0059cd30));

        DAT_0059cbd8[0xe] = uVar2;

        return;

      }

    }

  }

  return;

}

/* ===== main_editor_00440d90 @ 0x00440D90 ===== */
void main_editor_00440d90(void)



{

  int iVar1;

  int iVar2;

  undefined4 uVar3;

  int *piVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  CHAR local_208 [256];

  CHAR local_108 [260];

  

  FUN_00542f27(local_208,s_bld_WO__s_bld_00558564);

  FUN_00542f27(local_108,s_bld_WO__s_old_00558554,*(undefined4 *)(DAT_006330e4 + 4));

  MoveFileExA(local_208,local_108,1);

  main_editor_00438350();

  iVar2 = BinFileSeek_2(local_208,&DAT_00558550);

  iVar5 = 0;

  if (iVar2 == 0) {

    FUN_00542f27(&DAT_00657400,s_Failed_to_create__s_0055853c,local_208);

    error_screen_show(&DAT_00657400);

    return;

  }

  FUN_00543b5d(iVar2,s___This_file_may_be_generated_by_g_005584f8);

  FUN_00543b5d(iVar2,s___Objects_sorted_from_location___005584c4,

               (double)*(float *)(DAT_00632a88 + 0xa0),(double)*(float *)(DAT_00632a88 + 0xa4),

               (double)*(float *)(DAT_00632a88 + 0xa8));

  FUN_00543b5d(iVar2,s_ObjEditStart_005584b4);

  __ftol();

  uVar3 = __ftol();

  __ftol(uVar3);

  FUN_00543b5d();

  __ftol();

  uVar3 = __ftol();

  __ftol(uVar3);

  FUN_00543b5d();

  FUN_00543b5d(iVar2,s_bumpclampvalue__f_0055846c,(double)*(float *)(DAT_006330e4 + 0x4f38));

  FUN_00543b5d(iVar2,s_DisableScenerios__d_00558454,*(undefined4 *)(DAT_006330e4 + 0x4e88));

  FUN_00543b5d(iVar2,s_WaterColor__f__f__f__f__f__f__f___00558400,

               (double)((float)*(byte *)(DAT_006330e4 + 0x50a2) * 0.003921569),

               (double)((float)*(byte *)(DAT_006330e4 + 0x50a1) * 0.003921569),

               (double)((float)(*(uint *)(DAT_006330e4 + 0x50a0) & 0xff) * 0.003921569),

               (double)((float)*(byte *)(DAT_006330e4 + 0x508e) * 0.003921569),

               (double)((float)*(byte *)(DAT_006330e4 + 0x508d) * 0.003921569),

               (double)((float)(*(uint *)(DAT_006330e4 + 0x508c) & 0xff) * 0.003921569),

               (double)((float)*(byte *)(DAT_006330e4 + 0x5092) * 0.003921569),

               (double)((float)*(byte *)(DAT_006330e4 + 0x5091) * 0.003921569),

               (double)((float)(*(uint *)(DAT_006330e4 + 0x5090) & 0xff) * 0.003921569),

               (double)((float)*(byte *)(DAT_006330e4 + 0x5096) * 0.003921569),

               (double)((float)*(byte *)(DAT_006330e4 + 0x5095) * 0.003921569),

               (double)((float)(*(uint *)(DAT_006330e4 + 0x5094) & 0xff) * 0.003921569),

               (double)((float)*(byte *)(DAT_006330e4 + 0x509a) * 0.003921569),

               (double)((float)*(byte *)(DAT_006330e4 + 0x5099) * 0.003921569),

               (double)((float)(*(uint *)(DAT_006330e4 + 0x5098) & 0xff) * 0.003921569),

               (double)((float)*(byte *)(DAT_006330e4 + 0x509e) * 0.003921569),

               (double)((float)*(byte *)(DAT_006330e4 + 0x509d) * 0.003921569),

               (double)((float)(*(uint *)(DAT_006330e4 + 0x509c) & 0xff) * 0.003921569),

               (double)*(float *)(DAT_006330e4 + 0x50a4),(double)*(float *)(DAT_006330e4 + 0x50a8),

               (double)*(float *)(DAT_006330e4 + 0x50ac),(double)*(float *)(DAT_006330e4 + 0x50b0),

               (double)*(float *)(DAT_006330e4 + 0x50b4));

  iVar6 = 0;

  do {

    if (*(char *)(iVar6 + 0x2210 + DAT_006330e4) == '\0') {

      FUN_00543b5d(iVar2,&DAT_00558214);

      break;

    }

    FUN_00543b5d(iVar2,s_Mission__s_005583f4);

    iVar6 = iVar6 + 0x118;

  } while (iVar6 < 0x2300);

  iVar7 = 0;

  iVar6 = DAT_006330e4;

  do {

    iVar1 = *(int *)(iVar7 + 0x4550 + iVar6);

    if (iVar1 != 0) {

      FUN_00543b5d(iVar2,s_Scenerio__d__d__s_005583e0,iVar1,*(undefined4 *)(iVar7 + 0x4554 + iVar6),

                   iVar7 + 0x4558 + iVar6);

      iVar6 = DAT_006330e4;

    }

    iVar7 = iVar7 + 0x30;

  } while (iVar7 < 0x510);

  FUN_00543b5d(iVar2,&DAT_00558214);

  iVar6 = 0;

  piVar4 = DAT_00632d68;

  if (DAT_00632d68 != (int *)0x0) {

    do {

      if (((*(uint *)(piVar4[3] + 0xdc) & 0x20000000) != 0) &&

         ((*(uint *)(piVar4[3] + 0xd8) & 0x400) == 0)) {

        iVar6 = iVar6 + 1;

      }

      piVar4 = (int *)*piVar4;

    } while (piVar4 != (int *)0x0);

    if (iVar6 != 0) {

      iVar6 = FUN_0053a700(10,iVar6 << 2,&DAT_005583dc,s_C__Giants_source_main_editor_c_00556ff0,

                           0xf77);

      for (piVar4 = DAT_00632d68; piVar4 != (int *)0x0; piVar4 = (int *)*piVar4) {

        iVar7 = piVar4[3];

        if ((((*(uint *)(iVar7 + 0xdc) & 0x20000000) != 0) && (*(int *)(iVar7 + 0x210) == 0)) &&

           ((*(uint *)(iVar7 + 0xd8) & 0x400) == 0)) {

          *(int *)(iVar6 + iVar5 * 4) = iVar7;

          iVar5 = iVar5 + 1;

        }

      }

      FUN_00543bc3(iVar6,iVar5,4,&LAB_00441400);

      iVar7 = 0;

      if (0 < iVar5) {

        do {

          main_editor_00440770(iVar2,*(undefined4 *)(iVar6 + iVar7 * 4),0);

          iVar7 = iVar7 + 1;

        } while (iVar7 < iVar5);

      }

      mem_free_tagged(iVar6,s_C__Giants_source_main_editor_c_00556ff0,0xf8c);

    }

  }

  FUN_00543b5d(iVar2,s_ObjEditEnd_005583cc);

  FUN_0054384c(iVar2);

  return;

}

/* ===== main_editor_004415d0 @ 0x004415D0 ===== */
undefined4 * main_editor_004415d0(void)



{

  undefined4 *puVar1;

  int iVar2;

  undefined4 *puVar3;

  

  puVar1 = DAT_0059cd94;

  if (DAT_0059cd94 == (undefined4 *)0x0) {

    puVar1 = (undefined4 *)

             FUN_0053a700(10,0x3844,s_EditUndoData_00556fe0,

                          s_C__Giants_source_main_editor_c_00556ff0,0x1011);

    *puVar1 = DAT_0059cd98;

    DAT_0059cd94 = puVar1 + 1;

    iVar2 = 0;

    DAT_0059cd98 = puVar1;

    do {

      *(int *)(iVar2 + (int)DAT_0059cd94) = iVar2 + 0x48 + (int)DAT_0059cd94;

      iVar2 = iVar2 + 0x48;

    } while (iVar2 < 0x37b0);

    DAT_0059cd94[0xdec] = 0;

    puVar1 = DAT_0059cd94;

  }

  DAT_0059cd94 = (undefined4 *)*puVar1;

  puVar3 = puVar1;

  for (iVar2 = 0x12; iVar2 != 0; iVar2 = iVar2 + -1) {

    *puVar3 = 0;

    puVar3 = puVar3 + 1;

  }

  return puVar1;

}

/* ===== main_editor_00441660 @ 0x00441660 ===== */
void main_editor_00441660(void)



{

  undefined4 *puVar1;

  undefined4 *puVar2;

  

  puVar2 = DAT_0059cd98;

  while (puVar2 != (undefined4 *)0x0) {

    puVar1 = (undefined4 *)*puVar2;

    mem_free_tagged(puVar2,s_C__Giants_source_main_editor_c_00556ff0,0x104d);

    puVar2 = puVar1;

  }

  DAT_0059cd98 = (undefined4 *)0x0;

  DAT_0059cd94 = 0;

  return;

}

