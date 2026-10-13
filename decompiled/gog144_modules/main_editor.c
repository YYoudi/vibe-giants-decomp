/* Giants 1.449 — module main/editor
 * 6 functions (6 named) — decompiled, names from PS2 symbols
 * Original source: C:\Giants\source\main/editor.c(pp) (assert-string evidence)
 */

/* ===== rpman_init__FP6OBJECT @ 0x004361B0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* PS2 candidate: rpman_init__FP6OBJECT (conf 0.381) */



void rpman_init__FP6OBJECT(void)



{

  bool bVar1;

  float fVar2;

  float fVar3;

  char cVar4;

  int **ppiVar5;

  undefined4 uVar6;

  undefined1 uVar7;

  undefined1 uVar8;

  uint uVar9;

  int iVar10;

  int *piVar11;

  int *piVar12;

  int **ppiVar13;

  uint uVar14;

  undefined4 *puVar15;

  undefined4 *puVar16;

  int iVar17;

  byte bVar18;

  uint uVar19;

  int *piVar20;

  int *piVar21;

  int *piVar22;

  int **ppiVar23;

  float10 fVar24;

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

      piVar11 = (int *)*DAT_0059cbd8;

      *DAT_0059cbd8 = (int)DAT_0059cd94;

      DAT_0059cd94 = DAT_0059cbd8;

      DAT_0059cbd8 = piVar11;

    }

    DAT_0059cbd8 = (int *)0x0;

    for (puVar15 = DAT_00632d68; puVar15 != (undefined4 *)0x0; puVar15 = (undefined4 *)*puVar15) {

      *(uint *)(puVar15[3] + 0xdc) = *(uint *)(puVar15[3] + 0xdc) & 0xffffdeff;

    }

  }

  puVar15 = DAT_00632d68;

  if (DAT_00632e80 != 0) {

    for (; puVar15 != (undefined4 *)0x0; puVar15 = (undefined4 *)*puVar15) {

      *(uint *)(puVar15[3] + 0xdc) = *(uint *)(puVar15[3] + 0xdc) & 0xffffdeff;

    }

    if (DAT_00632e80 == 0) {

      return;

    }

    uVar14 = DAT_00632e80 - 1;

    cVar4 = (char)DAT_00632e80;

    puVar15 = DAT_00632d68;

    do {

      if (puVar15 == (undefined4 *)0x0) {

        iVar10 = editor_cursor_pick_point(0);

        if (iVar10 == 0) {

          return;

        }

        *(uint *)(iVar10 + 0xdc) = *(uint *)(iVar10 + 0xdc) | 0x2000;

        if (DAT_00632aaa == '\0') {

          return;

        }

        if (uVar14 < 0x20) {

          *(uint *)(iVar10 + 0x2e8) = *(uint *)(iVar10 + 0x2e8) ^ 1 << ((byte)uVar14 & 0x1f);

          return;

        }

        if (0x3f < uVar14) {

          if (uVar14 < 0x60) {

            bVar18 = cVar4 + 0xbf;

          }

          else {

            if (0x7f < uVar14) {

              return;

            }

            bVar18 = cVar4 + 0x9f;

          }

          *(uint *)(iVar10 + 0x2f0) = *(uint *)(iVar10 + 0x2f0) ^ 1 << (bVar18 & 0x1f);

          return;

        }

        *(uint *)(iVar10 + 0x2ec) = *(uint *)(iVar10 + 0x2ec) ^ 1 << (cVar4 - 0x21U & 0x1f);

        return;

      }

      iVar10 = puVar15[3];

      if (uVar14 < 0x20) {

        uVar9 = 1 << ((byte)uVar14 & 0x1f);

        uVar19 = *(uint *)(iVar10 + 0x2e8);

LAB_004362b4:

        if ((uVar9 & uVar19) != 0) {

          *(uint *)(iVar10 + 0xdc) = *(uint *)(iVar10 + 0xdc) | 0x100;

        }

      }

      else {

        if (uVar14 < 0x40) {

          uVar9 = 1 << (cVar4 - 0x21U & 0x1f);

          uVar19 = *(uint *)(iVar10 + 0x2ec);

          goto LAB_004362b4;

        }

        if (uVar14 < 0x60) {

          bVar18 = cVar4 + 0xbf;

LAB_004362a7:

          uVar9 = 1 << (bVar18 & 0x1f);

          uVar19 = *(uint *)(iVar10 + 0x2f0);

          goto LAB_004362b4;

        }

        if (uVar14 < 0x80) {

          bVar18 = cVar4 + 0x9f;

          goto LAB_004362a7;

        }

      }

      puVar15 = (undefined4 *)*puVar15;

    } while( true );

  }

  if (DAT_00632e74 == 0) {

    return;

  }

  bVar1 = true;

  if (DAT_0059cd44 == 0) {

    main_editor_00438350();

    DAT_0059cd44 = 1;

  }

  if ((DAT_00632ad6 == '\0') && (DAT_00632ad7 == '\0')) {

    bVar1 = false;

  }

  if (((DAT_0059cbf0 == 0) && (DAT_0059cbec == 0)) && (!bVar1)) {

    iVar10 = editor_cursor_pick_point(1);

    if ((DAT_0059cbd8 == (int *)0x0) || (DAT_0059cbd8[0xe] == iVar10)) {

      piVar11 = DAT_0059cbd8;

      if (iVar10 != 0) {

        for (; piVar11 != (int *)0x0; piVar11 = (int *)*piVar11) {

          if (piVar11[0xe] == iVar10) goto LAB_00436453;

        }

        piVar11 = (int *)main_editor_004415d0();

        piVar11[0xe] = iVar10;

        *piVar11 = (int)DAT_0059cbd8;

        DAT_0059cbd8 = piVar11;

      }

    }

    else {

      do {

        piVar11 = DAT_0059cbd8;

        DAT_0059cbd8 = (int *)*piVar11;

        *piVar11 = (int)DAT_0059cd94;

        DAT_0059cd94 = piVar11;

      } while (DAT_0059cbd8 != (int *)0x0);

      DAT_0059cbd8 = (int *)0x0;

      if (iVar10 != 0) {

        piVar11 = (int *)main_editor_004415d0();

        piVar11[0xe] = iVar10;

        *piVar11 = (int)DAT_0059cbd8;

        DAT_0059cbd8 = piVar11;

      }

    }

  }

LAB_00436453:

  if (DAT_00632aad != '\0') {

    if (DAT_0059cbd8 == (int *)0x0) {

      DAT_0059cc38 = 2;

      wredit_004959c0();

      dlog_push_level(&LAB_00438ef0,&LAB_00438dd0);

      DAT_00632ab0 = 0;

      DAT_00632aad = 0;

      DAT_00632aaa = 0;

      wredit_00519c70();

      main_editor_00438350();

      switch(DAT_0059cc38) {

      case 0:

        goto switchD_004364b2_caseD_0;

      case 1:

switchD_004364b2_caseD_1:

        wredit_group_select();

        return;

      case 2:

switchD_004364b2_caseD_2:

        wredit_object_select();

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

        wredit_marker_menu_full();

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

    wredit_004959c0();

    dlog_push_level(&LAB_00438ef0,&LAB_00438dd0);

    DAT_00632ab0 = 0;

    DAT_00632aad = 0;

    DAT_00632aaa = 0;

    wredit_00519c70();

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

  if ((bVar1) && (DAT_0059cbd8 != (int *)0x0)) {

    iVar10 = DAT_0059cbd8[0xe];

    if (*(int *)(iVar10 + 0x1e0) != 0x34) {

      return;

    }

    if ((DAT_005dd238 & 1) != 0) {

      if (DAT_00632ad6 != '\0') {

        project_cursor_to_ground(&local_60,0x447a0000,&local_70);

        fVar24 = (float10)distance2d__FP3P3DT0(&local_60,*(int *)(iVar10 + 0x100) + 4);

        **(float **)(iVar10 + 0x100) = (float)fVar24;

      }

      if (DAT_00632ad7 != '\0') {

        project_cursor_to_ground(&local_60,0x447a0000,&local_70);

        iVar17 = *(int *)(iVar10 + 0x100);

        *(float *)(iVar17 + 4) = local_60;

        *(float *)(iVar17 + 8) = local_5c;

        *(float *)(iVar17 + 0xc) = local_58;

      }

    }

    FUN_0042ef40(*(undefined4 **)(iVar10 + 0x100) + 1,**(undefined4 **)(iVar10 + 0x100));

    return;

  }

  if (DAT_0059cbf0 != 0) {

    if (DAT_0059cbe8 != 0) {

      project_cursor_to_ground(&local_54,0x447a0000,&local_70);

      local_5c = local_50;

      local_60 = DAT_0059cc1c;

      local_6c = local_54;

      local_68 = DAT_0059cc20;

      fVar24 = (float10)get_floor_z_point(&local_60);

      local_58 = (float)fVar24;

      fVar24 = (float10)get_floor_z_point(&local_6c);

      local_64 = (float)fVar24;

      FUN_0042eee0(&DAT_0059cc1c,&local_60);

      FUN_0042eee0(&local_60,&local_54);

      FUN_0042eee0(&local_54,&local_6c);

      FUN_0042eee0(&local_6c,&DAT_0059cc1c);

      for (puVar15 = DAT_00632d68; puVar16 = DAT_00632d68, puVar15 != (undefined4 *)0x0;

          puVar15 = (undefined4 *)*puVar15) {

        *(uint *)(puVar15[3] + 0xdc) = *(uint *)(puVar15[3] + 0xdc) & 0xffffdeff;

      }

      for (; puVar16 != (undefined4 *)0x0; puVar16 = (undefined4 *)*puVar16) {

        iVar10 = puVar16[3];

        if ((((*(uint *)(iVar10 + 0xdc) & 0x20000000) != 0) &&

            ((*(uint *)(iVar10 + 0xd8) & 0x8000) == 0)) && (*(int *)(iVar10 + 8) != 0)) {

          fVar2 = local_6c;

          fVar3 = local_60;

          if (local_60 < local_6c) {

            fVar2 = local_60;

            fVar3 = local_6c;

          }

          if (local_68 <= local_5c) {

            local_44 = local_68;

            local_38 = local_5c;

          }

          else {

            local_44 = local_5c;

            local_38 = local_68;

          }

          if (((*(float *)(iVar10 + 0xa0) <= fVar3) && (*(float *)(iVar10 + 0xa4) <= local_38)) &&

             ((fVar2 <= *(float *)(iVar10 + 0xa0) && (local_44 <= *(float *)(iVar10 + 0xa4))))) {

            *(uint *)(iVar10 + 0xdc) = *(uint *)(iVar10 + 0xdc) | 0x100;

          }

        }

      }

      if ((DAT_005dd238 & 1) != 0) {

        return;

      }

      DAT_0059cbf0 = 0;

      DAT_0059cbe8 = 0;

      piVar11 = DAT_0059cbd8;

      puVar15 = DAT_00632d68;

      do {

        if (puVar15 == (undefined4 *)0x0) {

          if (piVar11 == (int *)0x0) {

            return;

          }

          DAT_0059cbec = 1;

          return;

        }

        iVar10 = puVar15[3];

        if ((((*(uint *)(iVar10 + 0xdc) & 0x20000000) != 0) &&

            ((*(uint *)(iVar10 + 0xd8) & 0x8000) == 0)) &&

           ((*(int *)(iVar10 + 8) != 0 &&

            (piVar21 = piVar11, (*(uint *)(iVar10 + 0xdc) & 0x100) != 0)))) {

          for (; piVar21 != (int *)0x0; piVar21 = (int *)*piVar21) {

            if (piVar21[0xe] == iVar10) goto LAB_004374a1;

          }

          piVar11 = DAT_0059cd94;

          if (DAT_0059cd94 == (int *)0x0) {

            puVar16 = (undefined4 *)

                      MemAllocMsg(10,0x3844,s_EditUndoData_00556fe0,

                                  s_C__Giants_source_main_editor_c_00556ff0,0x1011);

            *puVar16 = DAT_0059cd98;

            DAT_0059cd94 = puVar16 + 1;

            iVar17 = 0;

            DAT_0059cd98 = puVar16;

            do {

              *(int *)((int)DAT_0059cd94 + iVar17) = (int)DAT_0059cd94 + iVar17 + 0x48;

              iVar17 = iVar17 + 0x48;

            } while (iVar17 < 0x37b0);

            DAT_0059cd94[0xdec] = 0;

            piVar11 = DAT_0059cd94;

          }

          DAT_0059cd94 = (int *)*piVar11;

          piVar21 = piVar11;

          for (iVar17 = 0x12; iVar17 != 0; iVar17 = iVar17 + -1) {

            *piVar21 = 0;

            piVar21 = piVar21 + 1;

          }

          piVar11[0xe] = iVar10;

          *piVar11 = (int)DAT_0059cbd8;

          DAT_0059cbd8 = piVar11;

        }

LAB_004374a1:

        puVar15 = (undefined4 *)*puVar15;

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

        piVar11 = DAT_0059cbd8;

        DAT_0059cc28 = (uint)DAT_00632acd;

        do {

          iVar10 = piVar11[0xe];

          piVar11[1] = *(int *)(iVar10 + 0xa0);

          piVar11[2] = *(int *)(iVar10 + 0xa4);

          piVar11[3] = *(int *)(iVar10 + 0xa8);

          piVar11[4] = *(int *)(iVar10 + 200);

          piVar11[5] = *(int *)(iVar10 + 0xcc);

          piVar11[6] = *(int *)(iVar10 + 0xd0);

          piVar11[7] = *(int *)(iVar10 + 0xc4);

          piVar11[8] = *(int *)(iVar10 + 0x1d4);

          piVar11[0xb] = *(int *)(iVar10 + 0xe8);

          piVar11[0xc] = *(int *)(iVar10 + 0x174);

          piVar11[9] = *(int *)(iVar10 + 0xf8);

          piVar11[10] = *(int *)(iVar10 + 0xfc);

          piVar11[0xd] = *(int *)(iVar10 + 4);

          piVar11 = (int *)*piVar11;

        } while (piVar11 != (int *)0x0);

        project_cursor_to_ground(&DAT_0059cbf8,0x447a0000,&local_70);

        _DAT_0059cc14 = DAT_0059cbfc;

        _DAT_0059cc08 = DAT_0059cbfc;

        _DAT_0059cc10 = DAT_0059cbf8;

        _DAT_0059cc18 = DAT_0059cc00;

        _DAT_0059cc04 = DAT_0059cbf8;

        _DAT_0059cc0c = DAT_0059cc00;

      }

      if (DAT_00632acd != 0) {

        iVar10 = 0;

        piVar11 = DAT_0059cbd8;

        if (DAT_0059cbd8 == (int *)0x0) {

          return;

        }

        do {

          piVar11 = (int *)*piVar11;

          iVar10 = iVar10 + 1;

        } while (piVar11 != (int *)0x0);

        if (iVar10 < 2) {

          piVar11 = DAT_0059cbd8;

          if (DAT_0059cbd8 == (int *)0x0) {

            return;

          }

          do {

            iVar10 = piVar11[0xe];

            if ((*(uint *)(iVar10 + 0x1c8) & 0x20000000) == 0) {

              *(float *)(iVar10 + 200) = _DAT_00632b10 * 0.33333334 + *(float *)(iVar10 + 200);

              collgrid_clear_grid(piVar11[0xe]);

              iVar10 = piVar11[0xe];

              if (*(int *)(iVar10 + 0x1e0) == 0x5c) {

                obj_5c_mount_slot3(iVar10);

                iVar17 = kabutoai_is_punch_anim__FP6OBJECT(iVar10);

                if ((iVar17 != 0) && (DAT_006330e4 != 0)) {

                  FUN_004ee150();

                  fx_spawn_checked(iVar10);

                  *(undefined4 *)(DAT_006330e4 + 0x4f3c) = 1;

                }

              }

            }

            else {

              marker_spline_adjust_scale(iVar10,_DAT_00632b10 * 0.2,0);

            }

            piVar11 = (int *)*piVar11;

          } while (piVar11 != (int *)0x0);

          return;

        }

        local_7c = (int *)(_DAT_00632b10 * 0.33333334);

        piVar11 = DAT_0059cbd8;

        do {

          iVar10 = piVar11[0xe];

          if ((*(uint *)(iVar10 + 0x1c8) & 0x20000000) == 0) {

            fVar24 = (float10)dirfcalcp3d__FP3P3DT0(&DAT_0059cc04,iVar10 + 0xa0);

            local_78 = (float)fVar24;

            fVar24 = (float10)distance2d__FP3P3DT0(piVar11[0xe] + 0xa0,&DAT_0059cc04);

            local_80 = (float)fVar24;

            sine_cos_lookup(local_78 + (float)local_7c,&local_74,&local_70);

            *(float *)(piVar11[0xe] + 0xa0) = local_74 * local_80 + _DAT_0059cc04;

            *(float *)(piVar11[0xe] + 0xa4) = _DAT_0059cc08 - local_70 * local_80;

            collgrid_clear_grid(piVar11[0xe]);

            object_copy_posdirinfo(piVar11[0xe]);

            *(float *)(piVar11[0xe] + 200) = (float)local_7c + *(float *)(piVar11[0xe] + 200);

            iVar10 = piVar11[0xe];

            if (*(int *)(iVar10 + 0x1e0) == 0x5c) {

              obj_5c_mount_slot3(iVar10);

              iVar17 = kabutoai_is_punch_anim__FP6OBJECT(iVar10);

              if ((iVar17 != 0) && (DAT_006330e4 != 0)) {

                FUN_004ee150();

                fx_spawn_checked(iVar10);

                *(undefined4 *)(DAT_006330e4 + 0x4f3c) = 1;

              }

            }

          }

          else {

            marker_spline_adjust_scale(iVar10,_DAT_00632b10 * 0.2,0);

          }

          piVar11 = (int *)*piVar11;

        } while (piVar11 != (int *)0x0);

        return;

      }

      if (DAT_00632ace != '\0') {

        piVar11 = DAT_0059cbd8;

        if (DAT_0059cbd8 == (int *)0x0) {

          return;

        }

        do {

          *(float *)(piVar11[0xe] + 0xcc) =

               _DAT_00632b10 * 0.33333334 + *(float *)(piVar11[0xe] + 0xcc);

          collgrid_clear_grid(piVar11[0xe]);

          iVar10 = piVar11[0xe];

          if (*(int *)(iVar10 + 0x1e0) == 0x5c) {

            obj_5c_mount_slot3(iVar10);

            iVar17 = kabutoai_is_punch_anim__FP6OBJECT(iVar10);

            if ((iVar17 != 0) && (DAT_006330e4 != 0)) {

              FUN_004ee150();

              fx_spawn_checked(iVar10);

              *(undefined4 *)(DAT_006330e4 + 0x4f3c) = 1;

            }

          }

          piVar11 = (int *)*piVar11;

        } while (piVar11 != (int *)0x0);

        return;

      }

      if (DAT_00632acf != '\0') {

        piVar11 = DAT_0059cbd8;

        if (DAT_0059cbd8 == (int *)0x0) {

          return;

        }

        do {

          iVar10 = piVar11[0xe];

          if ((*(uint *)(iVar10 + 0x1c8) & 0x20000000) == 0) {

            *(float *)(iVar10 + 0xd0) = _DAT_00632b10 * 0.33333334 + *(float *)(iVar10 + 0xd0);

            collgrid_clear_grid(piVar11[0xe]);

            iVar10 = piVar11[0xe];

            if (*(int *)(iVar10 + 0x1e0) == 0x5c) {

              obj_5c_mount_slot3(iVar10);

              iVar17 = kabutoai_is_punch_anim__FP6OBJECT(iVar10);

              if ((iVar17 != 0) && (DAT_006330e4 != 0)) {

                FUN_004ee150();

                fx_spawn_checked(iVar10);

                *(undefined4 *)(DAT_006330e4 + 0x4f3c) = 1;

              }

            }

          }

          else {

            marker_spline_rotate_tangent(iVar10,_DAT_00632b10 * 7.2,0);

          }

          piVar11 = (int *)*piVar11;

        } while (piVar11 != (int *)0x0);

        return;

      }

      if (DAT_00632ad1 != 0) {

        iVar10 = 0;

        piVar11 = DAT_0059cbd8;

        if (DAT_0059cbd8 == (int *)0x0) {

          return;

        }

        do {

          piVar11 = (int *)*piVar11;

          iVar10 = iVar10 + 1;

        } while (piVar11 != (int *)0x0);

        piVar11 = DAT_0059cbd8;

        if (iVar10 < 2) {

          if (DAT_0059cbd8 == (int *)0x0) {

            return;

          }

          do {

            iVar10 = piVar11[0xe];

            if ((*(uint *)(iVar10 + 0x1c8) & 0x20000000) == 0) {

              *(float *)(iVar10 + 0xc4) = _DAT_00632b10 * 0.04 + *(float *)(iVar10 + 0xc4);

              if (*(float *)(piVar11[0xe] + 0xc4) < 0.1) {

                *(undefined4 *)(piVar11[0xe] + 0xc4) = 0x3dcccccd;

              }

              *(uint *)(piVar11[0xe] + 0xdc) = *(uint *)(piVar11[0xe] + 0xdc) | 0x80000000;

            }

            else {

              marker_spline_adjust_scale(iVar10,_DAT_00632b10 * 0.2,1);

            }

            piVar11 = (int *)*piVar11;

          } while (piVar11 != (int *)0x0);

          return;

        }

        do {

          iVar10 = piVar11[0xe];

          if ((*(uint *)(iVar10 + 0x1c8) & 0x20000000) == 0) {

            local_70 = *(float *)(iVar10 + 0xc4);

            *(float *)(iVar10 + 0xc4) = _DAT_00632b14 * 0.02 + *(float *)(iVar10 + 0xc4);

            if (*(float *)(piVar11[0xe] + 0xc4) < 0.1) {

              *(undefined4 *)(piVar11[0xe] + 0xc4) = 0x3dcccccd;

            }

            fVar24 = (float10)dirfcalcp3d__FP3P3DT0(&DAT_0059cc10,piVar11[0xe] + 0xa0);

            local_74 = (float)fVar24;

            fVar24 = (float10)distance2d__FP3P3DT0(piVar11[0xe] + 0xa0,&DAT_0059cc10);

            local_7c = (int *)(float)(((float10)*(float *)(piVar11[0xe] + 0xc4) / (float10)local_70)

                                     * fVar24);

            sine_cos_lookup(local_74,&local_78,&local_80);

            *(float *)(piVar11[0xe] + 0xa0) = local_78 * (float)local_7c + _DAT_0059cc10;

            *(float *)(piVar11[0xe] + 0xa4) = _DAT_0059cc14 - local_80 * (float)local_7c;

            object_copy_posdirinfo(piVar11[0xe]);

            *(uint *)(piVar11[0xe] + 0xdc) = *(uint *)(piVar11[0xe] + 0xdc) | 0x80000000;

          }

          else {

            marker_spline_adjust_scale(iVar10,_DAT_00632b10 * 0.2,0);

          }

          piVar11 = (int *)*piVar11;

        } while (piVar11 != (int *)0x0);

        return;

      }

      if (DAT_00632ad0 != '\0') {

        piVar11 = DAT_0059cbd8;

        if (DAT_0059cbd8 == (int *)0x0) {

          return;

        }

        do {

          if ((*(uint *)(piVar11[0xe] + 0x1c8) & 0x20000000) != 0) {

            marker_spline_rotate_tangent(piVar11[0xe],_DAT_00632b10 * 7.2,1);

          }

          piVar11 = (int *)*piVar11;

        } while (piVar11 != (int *)0x0);

        return;

      }

      if (DAT_00632ad2 != '\0') {

        piVar11 = DAT_0059cbd8;

        if (DAT_0059cbd8 == (int *)0x0) {

          return;

        }

        do {

          *(float *)(piVar11[0xe] + 0x1d4) = *(float *)(piVar11[0xe] + 0x1d4) - _DAT_00632b14 * 0.02

          ;

          iVar10 = piVar11[0xe];

          uVar14 = *(uint *)(iVar10 + 0x1c8);

          *(uint *)(iVar10 + 0x1c8) = uVar14 & 0xfffffff7;

          fVar24 = (float10)get_floor_z_point(iVar10 + 0xa0);

          *(uint *)(iVar10 + 0x1c8) = uVar14;

          *(float *)(iVar10 + 0xa8) = (float)(fVar24 + (float10)*(float *)(iVar10 + 0x1d4));

          object_copy_posdirinfo(iVar10);

          *(undefined4 *)(iVar10 + 0x108) = 0;

          *(uint *)(iVar10 + 0xd8) = *(uint *)(iVar10 + 0xd8) | 0x80000;

          *(uint *)(piVar11[0xe] + 0xdc) = *(uint *)(piVar11[0xe] + 0xdc) | 0x80000000;

          if ((*(uint *)(piVar11[0xe] + 0x1c8) & 0x20000000) != 0) {

            marker_spline_adjust_location(piVar11[0xe]);

          }

          iVar10 = piVar11[0xe];

          if (*(int *)(iVar10 + 0x1e0) == 0x5c) {

            obj_5c_mount_slot3(iVar10);

            iVar17 = kabutoai_is_punch_anim__FP6OBJECT(iVar10);

            if ((iVar17 != 0) && (DAT_006330e4 != 0)) {

              FUN_004ee150();

              fx_spawn_checked(iVar10);

              *(undefined4 *)(DAT_006330e4 + 0x4f3c) = 1;

            }

          }

          piVar11 = (int *)*piVar11;

        } while (piVar11 != (int *)0x0);

        return;

      }

      project_cursor_to_ground(&local_54,0x447a0000,&local_78);

      piVar11 = DAT_0059cbd8;

      if (DAT_0059cbd8 == (int *)0x0) {

        return;

      }

      do {

        if (((1.0 < ABS(_DAT_00632b10)) || (1.0 < ABS(_DAT_00632b14))) || (1.0 < ABS(_DAT_00632b18))

           ) {

          *(float *)(piVar11[0xe] + 0xa0) = local_54 - (float)piVar11[0xf];

          *(float *)(piVar11[0xe] + 0xa4) = local_50 - (float)piVar11[0x10];

          iVar10 = piVar11[0xe];

          uVar14 = *(uint *)(iVar10 + 0x1c8);

          *(uint *)(iVar10 + 0x1c8) = uVar14 & 0xfffffff7;

          fVar24 = (float10)get_floor_z_point(iVar10 + 0xa0);

          *(uint *)(iVar10 + 0x1c8) = uVar14;

          *(float *)(piVar11[0xe] + 0xa8) = (float)(fVar24 + (float10)*(float *)(iVar10 + 0x1d4));

          iVar10 = piVar11[0xe];

          if ((*(uint *)(iVar10 + 0x1c8) & 0x8000000) == 0) {

            iVar17 = *(int *)(iVar10 + 4);

            if (((iVar17 == 1099) || (iVar17 == 0x44c)) || (iVar17 == 0x44d)) {

              if (2.0 <= *(float *)(iVar10 + 0xa8)) {

                *(float *)(iVar10 + 0xa8) = *(float *)(iVar10 + 0xa8) + 2.0;

              }

              else {

                *(undefined4 *)(iVar10 + 0xa8) = 0x40000000;

              }

            }

            else if (*(int *)(iVar10 + 0x1e0) == 0x3a) goto LAB_00437d68;

          }

          else {

LAB_00437d68:

            if (*(float *)(iVar10 + 0xa8) < 0.0) {

              *(undefined4 *)(iVar10 + 0xa8) = 0;

            }

          }

          object_copy_posdirinfo(piVar11[0xe]);

          collgrid_clear_grid(piVar11[0xe]);

          if (DAT_0059cbe0 != 0) {

            setMenuSelection__7PS2Gameiiii(piVar11[0xe]);

            iVar10 = piVar11[0xe];

            fVar24 = (float10)atand2pos(*(undefined4 *)(iVar10 + 0x148),

                                        *(undefined4 *)(iVar10 + 0x14c));

            local_74 = (float)fVar24;

            fVar24 = (float10)atand2pos(*(undefined4 *)(iVar10 + 0x144),

                                        *(undefined4 *)(iVar10 + 0x14c));

            local_70 = (float)fVar24;

            math_sincos_lut(-local_74,local_70,0,local_48);

            math_sincos_lut(0,0,*(undefined4 *)(piVar11[0xe] + 200),local_24);

            matrix_mult__FPfN20(local_24,local_48,local_48);

            iVar10 = piVar11[0xe];

            vec_to_angles(local_48,iVar10 + 0xcc,iVar10 + 0xd0,iVar10 + 200);

            *(float *)(piVar11[0xe] + 0xcc) = -*(float *)(piVar11[0xe] + 0xcc);

          }

          if ((*(uint *)(piVar11[0xe] + 0x1c8) & 0x20000000) != 0) {

            marker_spline_adjust_location(piVar11[0xe]);

          }

          iVar10 = piVar11[0xe];

          if (*(int *)(iVar10 + 0x1e0) == 0x5c) {

            obj_5c_mount_slot3(iVar10);

            iVar17 = kabutoai_is_punch_anim__FP6OBJECT(iVar10);

            if ((iVar17 != 0) && (DAT_006330e4 != 0)) {

              FUN_004ee150();

              fx_spawn_checked(iVar10);

              *(undefined4 *)(DAT_006330e4 + 0x4f3c) = 1;

            }

          }

        }

        piVar11 = (int *)*piVar11;

        if (piVar11 == (int *)0x0) {

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

      uVar6 = 0;

      uVar7 = 0;

      if ((DAT_0059cc40 & 2) != 0) {

        return;

      }

      while (DAT_00632aad = uVar7, DAT_0059cbf0 = uVar6, piVar11 = DAT_0059cbd8,

            piVar11 != (int *)0x0) {

        DAT_0059cbd8 = (int *)*piVar11;

        *piVar11 = (int)DAT_0059cd94;

        uVar6 = DAT_0059cbf0;

        DAT_0059cd94 = piVar11;

        uVar7 = DAT_00632aad;

      }

      DAT_0059cbd8 = (undefined4 *)0x0;

      DAT_0059cbec = 0;

      piVar11 = DAT_0059cc44;

      if ((DAT_0059cc40 & 8) != 0) {

        for (; piVar11 != (int *)0x0; piVar11 = (int *)*piVar11) {

          iVar10 = object_spawn_42(piVar11[0xd]);

          piVar11[0xe] = iVar10;

          main_editor_004382b0(iVar10,piVar11);

          if ((*(uint *)(piVar11[0xe] + 0x1c8) & 0x8000000) != 0) {

            piVar21 = (int *)(piVar11[0xe] + 0x174);

            *piVar21 = *piVar21 + 1;

            FUN_00476f90(piVar11[0xe]);

          }

        }

      }

      ppiVar5 = &local_7c;

      for (piVar11 = DAT_0059cc44; piVar11 != (int *)0x0; piVar11 = (int *)*piVar11) {

        ppiVar13 = (int **)main_editor_004415d0();

        piVar21 = piVar11;

        ppiVar23 = ppiVar13;

        for (iVar10 = 0x12; iVar10 != 0; iVar10 = iVar10 + -1) {

          *ppiVar23 = (int *)*piVar21;

          piVar21 = piVar21 + 1;

          ppiVar23 = ppiVar23 + 1;

        }

        *ppiVar5 = (int *)ppiVar13;

        ppiVar5 = ppiVar13;

      }

      *ppiVar5 = (int *)0x0;

      for (piVar11 = local_7c; piVar21 = DAT_0059cc44, piVar20 = DAT_0059cc44, piVar11 != (int *)0x0

          ; piVar11 = (int *)*piVar11) {

        main_editor_00438230(piVar11[0xe],piVar11);

      }

      for (; DAT_0059cc44 = piVar21, piVar20 != (int *)0x0; piVar20 = (int *)*piVar20) {

        main_editor_004382b0(piVar20[0xe],piVar20);

        piVar21 = DAT_0059cc44;

      }

      uVar14 = DAT_0059cc40 | 2;

      DAT_0059cc40 = uVar14;

      FUN_00543270(&DAT_0059cc40,&DAT_0059cc48,0xc0);

      _DAT_0059cd00 = uVar14;

      while (piVar21 != (int *)0x0) {

        piVar11 = (int *)*piVar21;

        *piVar21 = (int)DAT_0059cd94;

        DAT_0059cd94 = piVar21;

        piVar21 = piVar11;

      }

      DAT_0059cd04 = local_7c;

      if ((_DAT_0059cd00 & 4) != 0) {

        piVar11 = local_7c;

        if (local_7c == (int *)0x0) {

          return;

        }

        do {

          iVar10 = piVar11[0xe];

          if (iVar10 != 0) {

            if ((*(uint *)(iVar10 + 0x1c8) & 0x8000000) != 0) {

              FUN_00476ff0(iVar10);

            }

            if (*(int *)(piVar11[0xe] + 0x1e0) == 0x61) {

              FUN_004782f0(piVar11[0xe]);

            }

            object_destroy(piVar11[0xe]);

          }

          piVar11[0xe] = 0;

          piVar11 = (int *)*piVar11;

        } while (piVar11 != (int *)0x0);

        return;

      }

      piVar21 = (int *)&DAT_0059cbd8;

      for (piVar11 = local_7c; piVar11 != (int *)0x0; piVar11 = (int *)*piVar11) {

        piVar12 = (int *)main_editor_004415d0();

        piVar20 = piVar11;

        piVar22 = piVar12;

        for (iVar10 = 0x12; iVar10 != 0; iVar10 = iVar10 + -1) {

          *piVar22 = *piVar20;

          piVar20 = piVar20 + 1;

          piVar22 = piVar22 + 1;

        }

        *piVar21 = (int)piVar12;

        piVar21 = piVar12;

      }

      *piVar21 = 0;

      iVar10 = 0;

      for (puVar15 = DAT_0059cbd8; puVar15 != (undefined4 *)0x0; puVar15 = (undefined4 *)*puVar15) {

        iVar10 = iVar10 + 1;

      }

      DAT_0059cbec = (uint)(1 < iVar10);

      return;

    }

    if (DAT_00632ad4 != '\0') {

      if (DAT_0059cd04 == (int *)0x0) {

        return;

      }

      uVar6 = 0;

      uVar7 = 0;

      uVar8 = 0;

      if ((_DAT_0059cd00 & 2) == 0) {

        return;

      }

      while (DAT_00632ad3 = uVar8, DAT_00632aad = uVar7, DAT_0059cbf0 = uVar6,

            piVar11 = DAT_0059cbd8, piVar11 != (int *)0x0) {

        DAT_0059cbd8 = (int *)*piVar11;

        *piVar11 = (int)DAT_0059cd94;

        uVar6 = DAT_0059cbf0;

        DAT_0059cd94 = piVar11;

        uVar7 = DAT_00632aad;

        uVar8 = DAT_00632ad3;

      }

      DAT_0059cbd8 = (undefined4 *)0x0;

      DAT_0059cbec = 0;

      piVar11 = DAT_0059cd04;

      if ((_DAT_0059cd00 & 4) != 0) {

        for (; piVar11 != (int *)0x0; piVar11 = (int *)*piVar11) {

          iVar10 = object_spawn_42(piVar11[0xd]);

          piVar11[0xe] = iVar10;

          main_editor_004382b0(iVar10,piVar11);

          if ((*(uint *)(piVar11[0xe] + 0x1c8) & 0x8000000) != 0) {

            piVar21 = (int *)(piVar11[0xe] + 0x174);

            *piVar21 = *piVar21 + 1;

            FUN_00476f90(piVar11[0xe]);

          }

        }

      }

      ppiVar5 = &local_7c;

      for (piVar11 = DAT_0059cd04; piVar11 != (int *)0x0; piVar11 = (int *)*piVar11) {

        ppiVar13 = (int **)main_editor_004415d0();

        piVar21 = piVar11;

        ppiVar23 = ppiVar13;

        for (iVar10 = 0x12; iVar10 != 0; iVar10 = iVar10 + -1) {

          *ppiVar23 = (int *)*piVar21;

          piVar21 = piVar21 + 1;

          ppiVar23 = ppiVar23 + 1;

        }

        *ppiVar5 = (int *)ppiVar13;

        ppiVar5 = ppiVar13;

      }

      *ppiVar5 = (int *)0x0;

      for (piVar11 = local_7c; piVar21 = DAT_0059cd04, piVar20 = DAT_0059cd04, piVar11 != (int *)0x0

          ; piVar11 = (int *)*piVar11) {

        main_editor_00438230(piVar11[0xe],piVar11);

      }

      for (; DAT_0059cd04 = piVar21, piVar20 != (int *)0x0; piVar20 = (int *)*piVar20) {

        main_editor_004382b0(piVar20[0xe],piVar20);

        piVar21 = DAT_0059cd04;

      }

      uVar14 = _DAT_0059cd00 & 0xfffffffd;

      _DAT_0059cd00 = uVar14;

      FUN_00543270(&DAT_0059cc48,&DAT_0059cc40,0xc0);

      DAT_0059cc40 = uVar14;

      while (piVar11 = piVar21, piVar11 != (int *)0x0) {

        piVar21 = (int *)*piVar11;

        *piVar11 = (int)DAT_0059cd94;

        DAT_0059cd94 = piVar11;

      }

      DAT_0059cc44 = local_7c;

      if ((DAT_0059cc40 & 8) != 0) {

        piVar11 = local_7c;

        if (local_7c == (int *)0x0) {

          return;

        }

        do {

          iVar10 = piVar11[0xe];

          if (iVar10 != 0) {

            if ((*(uint *)(iVar10 + 0x1c8) & 0x8000000) != 0) {

              FUN_00476ff0(iVar10);

            }

            if (*(int *)(piVar11[0xe] + 0x1e0) == 0x61) {

              FUN_004782f0(piVar11[0xe]);

            }

            object_destroy(piVar11[0xe]);

          }

          piVar11[0xe] = 0;

          piVar11 = (int *)*piVar11;

        } while (piVar11 != (int *)0x0);

        return;

      }

      piVar21 = (int *)&DAT_0059cbd8;

      for (piVar11 = local_7c; piVar11 != (int *)0x0; piVar11 = (int *)*piVar11) {

        piVar20 = DAT_0059cd94;

        if (DAT_0059cd94 == (int *)0x0) {

          puVar15 = (undefined4 *)

                    MemAllocMsg(10,0x3844,s_EditUndoData_00556fe0,

                                s_C__Giants_source_main_editor_c_00556ff0,0x1011);

          *puVar15 = DAT_0059cd98;

          DAT_0059cd94 = puVar15 + 1;

          iVar10 = 0;

          DAT_0059cd98 = puVar15;

          do {

            *(int *)((int)DAT_0059cd94 + iVar10) = (int)DAT_0059cd94 + iVar10 + 0x48;

            iVar10 = iVar10 + 0x48;

          } while (iVar10 < 0x37b0);

          DAT_0059cd94[0xdec] = 0;

          piVar20 = DAT_0059cd94;

        }

        DAT_0059cd94 = (int *)*piVar20;

        piVar22 = piVar20;

        for (iVar10 = 0x12; iVar10 != 0; iVar10 = iVar10 + -1) {

          *piVar22 = 0;

          piVar22 = piVar22 + 1;

        }

        piVar22 = piVar11;

        piVar12 = piVar20;

        for (iVar10 = 0x12; iVar10 != 0; iVar10 = iVar10 + -1) {

          *piVar12 = *piVar22;

          piVar22 = piVar22 + 1;

          piVar12 = piVar12 + 1;

        }

        *piVar21 = (int)piVar20;

        piVar21 = piVar20;

      }

      *piVar21 = 0;

      iVar10 = 0;

      for (puVar15 = DAT_0059cbd8; puVar15 != (undefined4 *)0x0; puVar15 = (undefined4 *)*puVar15) {

        iVar10 = iVar10 + 1;

      }

      DAT_0059cbec = (uint)(1 < iVar10);

      return;

    }

    DAT_00632aad = 0;

    DAT_0059cbf0 = 0;

    DAT_00632ad3 = 0;

    DAT_00632ad4 = 0;

    piVar11 = DAT_0059cbd8;

    puVar15 = DAT_00632d68;

    if ((DAT_00632ab9 != '\0') && (DAT_0059cbd8 != (int *)0x0)) {

      DAT_00632aad = 0;

      DAT_0059cbf0 = 0;

      DAT_00632ad3 = 0;

      DAT_00632ad4 = 0;

      for (; puVar15 != (undefined4 *)0x0; puVar15 = (undefined4 *)*puVar15) {

        *(uint *)(puVar15[3] + 0xdc) = *(uint *)(puVar15[3] + 0xdc) & 0xffffdeff;

      }

      while (piVar11 = DAT_0059cd04, piVar11 != (int *)0x0) {

        DAT_0059cd04 = (int *)*piVar11;

        *piVar11 = (int)DAT_0059cd94;

        DAT_0059cd94 = piVar11;

      }

      _DAT_0059cd00 = 0;

      DAT_0059cd04 = (int *)0x0;

      FUN_00543270(&DAT_0059cc48,&DAT_0059cc40,0xc0);

      if ((_DAT_0059cd00 & 2) != 0) {

        while (piVar11 = DAT_0059cd04, piVar11 != (int *)0x0) {

          DAT_0059cd04 = (int *)*piVar11;

          *piVar11 = (int)DAT_0059cd94;

          DAT_0059cd94 = piVar11;

        }

        _DAT_0059cd00 = 0;

        DAT_0059cd04 = (int *)0x0;

      }

      DAT_0059cc40 = 8;

      DAT_0059cc44 = (int *)0x0;

      for (piVar11 = DAT_0059cbd8; piVar21 = DAT_0059cbd8, piVar20 = DAT_0059cbd8,

          piVar11 != (int *)0x0; piVar11 = (int *)*piVar11) {

        iVar10 = piVar11[0xe];

        piVar11[1] = *(int *)(iVar10 + 0xa0);

        piVar11[2] = *(int *)(iVar10 + 0xa4);

        piVar11[3] = *(int *)(iVar10 + 0xa8);

        piVar11[4] = *(int *)(iVar10 + 200);

        piVar11[5] = *(int *)(iVar10 + 0xcc);

        piVar11[6] = *(int *)(iVar10 + 0xd0);

        piVar11[7] = *(int *)(iVar10 + 0xc4);

        piVar11[8] = *(int *)(iVar10 + 0x1d4);

        piVar11[0xb] = *(int *)(iVar10 + 0xe8);

        piVar11[0xc] = *(int *)(iVar10 + 0x174);

        piVar11[9] = *(int *)(iVar10 + 0xf8);

        piVar11[10] = *(int *)(iVar10 + 0xfc);

        piVar11[0xd] = *(int *)(iVar10 + 4);

      }

      for (; piVar20 != (int *)0x0; piVar20 = (int *)*piVar20) {

        iVar10 = piVar20[0xe];

        DAT_0059cbd8 = piVar21;

        if (iVar10 != 0) {

          if ((*(uint *)(iVar10 + 0x1c8) & 0x8000000) != 0) {

            FUN_00476ff0(iVar10);

          }

          if (*(int *)(piVar20[0xe] + 0x1e0) == 0x61) {

            FUN_004782f0(piVar20[0xe]);

          }

          object_destroy(piVar20[0xe]);

        }

        piVar20[0xe] = 0;

        piVar21 = DAT_0059cbd8;

      }

      DAT_0059cbd8 = (int *)0x0;

      DAT_0059cc44 = piVar21;

      return;

    }

    for (; DAT_0059cbd8 = piVar11, puVar15 != (undefined4 *)0x0; puVar15 = (undefined4 *)*puVar15) {

      *(uint *)(puVar15[3] + 0xdc) = *(uint *)(puVar15[3] + 0xdc) & 0xffffdeff;

      piVar11 = DAT_0059cbd8;

    }

    if (piVar11 == (int *)0x0) {

      return;

    }

    do {

      *(uint *)(piVar11[0xe] + 0xdc) = *(uint *)(piVar11[0xe] + 0xdc) | 0x100;

      piVar11 = (int *)*piVar11;

    } while (piVar11 != (int *)0x0);

    return;

  }

  iVar10 = editor_cursor_pick_point(1);

  if (DAT_00632ad5 == '\0') {

    piVar11 = DAT_0059cbd8;

    if (iVar10 != 0) {

      for (; piVar11 != (int *)0x0; piVar11 = (int *)*piVar11) {

        if (piVar11[0xe] == iVar10) goto LAB_0043670e;

      }

    }

    while (piVar11 = DAT_0059cbd8, piVar11 != (int *)0x0) {

      DAT_0059cbd8 = (int *)*piVar11;

      *piVar11 = (int)DAT_0059cd94;

      DAT_0059cd94 = piVar11;

    }

    DAT_0059cbd8 = (int *)0x0;

    DAT_0059cbec = 0;

  }

LAB_0043670e:

  iVar10 = editor_cursor_pick_point(1);

  piVar11 = DAT_0059cbd8;

  if (iVar10 == 0) goto LAB_004367b5;

  for (; piVar21 = DAT_0059cbd8, piVar11 != (int *)0x0; piVar11 = (int *)*piVar11) {

    if (piVar11[0xe] == iVar10) {

      if (DAT_00632ad5 == '\0') goto LAB_004367b5;

      if (DAT_0059cbec == 0) goto LAB_004367a6;

      piVar11 = (int *)&DAT_0059cbd8;

      goto LAB_00436780;

    }

  }

  for (; piVar21 != (int *)0x0; piVar21 = (int *)*piVar21) {

    if (piVar21[0xe] == iVar10) goto LAB_004367a6;

  }

  piVar11 = (int *)main_editor_004415d0();

  piVar11[0xe] = iVar10;

  *piVar11 = (int)DAT_0059cbd8;

  DAT_0059cbd8 = piVar11;

  goto LAB_004367a6;

  while (piVar11 = piVar21, *piVar21 != 0) {

LAB_00436780:

    piVar21 = (int *)*piVar11;

    if (piVar21[0xe] == iVar10) {

      *piVar11 = *piVar21;

      *piVar21 = (int)DAT_0059cd94;

      DAT_0059cd94 = piVar21;

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

      project_cursor_to_ground(&DAT_0059cc1c,0x447a0000,&local_70);

    }

    else {

      DAT_0059cbf4 = *(int *)(DAT_0059cbd8[0xe] + 4);

    }

  }

  else {

    piVar11 = DAT_0059cbd8;

    if (DAT_0059cbd8 == (int *)0x0) {

      if ((DAT_0059cbf4 != 0) &&

         (iVar10 = object_spawn_42(DAT_0059cbf4), piVar11 = DAT_0059cbd8, iVar10 != 0)) {

        for (; piVar11 != (int *)0x0; piVar11 = (int *)*piVar11) {

          if (piVar11[0xe] == iVar10) goto LAB_004368ab;

        }

        piVar11 = (int *)main_editor_004415d0();

        piVar11[0xe] = iVar10;

        *piVar11 = (int)DAT_0059cbd8;

        DAT_0059cbd8 = piVar11;

      }

    }

    else {

      do {

        main_editor_00438230(piVar11[0xe],piVar11);

        piVar11 = (int *)*piVar11;

        piVar21 = DAT_0059cbd8;

      } while (piVar11 != (int *)0x0);

      for (; piVar21 != (int *)0x0; piVar21 = (int *)*piVar21) {

        iVar10 = object_spawn_42(piVar21[0xd]);

        piVar21[0xe] = iVar10;

        main_editor_004382b0(iVar10,piVar21);

        if ((*(uint *)(piVar21[0xe] + 0x1c8) & 0x8000000) != 0) {

          piVar11 = (int *)(piVar21[0xe] + 0x174);

          *piVar11 = *piVar11 + 1;

          FUN_00476f90(piVar21[0xe]);

        }

      }

    }

  }

LAB_004368ab:

  DAT_0059cbf0 = 1;

  if (DAT_0059cbe8 == 0) {

    piVar11 = DAT_0059cbd8;

    puVar15 = DAT_00632d68;

    if (DAT_0059cbd8 == (int *)0x0) {

      for (; DAT_0059cbd8 = piVar11, puVar15 != (undefined4 *)0x0; puVar15 = (undefined4 *)*puVar15)

      {

        *(uint *)(puVar15[3] + 0xdc) = *(uint *)(puVar15[3] + 0xdc) & 0xffffdeff;

        piVar11 = DAT_0059cbd8;

      }

      if (piVar11 != (int *)0x0) {

        do {

          *(uint *)(piVar11[0xe] + 0xdc) = *(uint *)(piVar11[0xe] + 0xdc) | 0x100;

          piVar11 = (int *)*piVar11;

        } while (piVar11 != (int *)0x0);

        return;

      }

    }

    else {

      for (; puVar15 != (undefined4 *)0x0; puVar15 = (undefined4 *)*puVar15) {

        *(uint *)(puVar15[3] + 0xdc) = *(uint *)(puVar15[3] + 0xdc) & 0xffffdeff;

      }

      project_cursor_to_ground(&DAT_0059cbf8,0x447a0000,&local_70);

      DAT_0059cc2c = 0;

      DAT_0059cc28 = 0;

      _DAT_0059cc10 = DAT_0059cbf8;

      _DAT_0059cc04 = DAT_0059cbf8;

      _DAT_0059cc14 = DAT_0059cbfc;

      _DAT_0059cc18 = DAT_0059cc00;

      _DAT_0059cc08 = DAT_0059cbfc;

      _DAT_0059cc0c = DAT_0059cc00;

      while (piVar11 = DAT_0059cd04, piVar11 != (int *)0x0) {

        DAT_0059cd04 = (int *)*piVar11;

        *piVar11 = (int)DAT_0059cd94;

        DAT_0059cd94 = piVar11;

      }

      _DAT_0059cd00 = 0;

      DAT_0059cd04 = (int *)0x0;

      FUN_00543270(&DAT_0059cc48,&DAT_0059cc40,0xc0);

      if ((_DAT_0059cd00 & 2) != 0) {

        while (piVar11 = DAT_0059cd04, piVar11 != (int *)0x0) {

          DAT_0059cd04 = (int *)*piVar11;

          *piVar11 = (int)DAT_0059cd94;

          DAT_0059cd94 = piVar11;

        }

        _DAT_0059cd00 = 0;

        DAT_0059cd04 = (int *)0x0;

      }

      DAT_0059cc40 = 0;

      DAT_0059cc44 = (int *)0x0;

      for (piVar11 = DAT_0059cbd8; piVar11 != (int *)0x0; piVar11 = (int *)*piVar11) {

        main_editor_00438230(piVar11[0xe],piVar11);

      }

      piVar21 = (int *)&DAT_0059cc44;

      for (piVar11 = DAT_0059cbd8; piVar11 != (int *)0x0; piVar11 = (int *)*piVar11) {

        piVar12 = (int *)main_editor_004415d0();

        piVar20 = piVar11;

        piVar22 = piVar12;

        for (iVar10 = 0x12; iVar10 != 0; iVar10 = iVar10 + -1) {

          *piVar22 = *piVar20;

          piVar20 = piVar20 + 1;

          piVar22 = piVar22 + 1;

        }

        *piVar21 = (int)piVar12;

        piVar21 = piVar12;

      }

      *piVar21 = 0;

      if (DAT_00632acc != '\0') {

        DAT_0059cc40 = DAT_0059cc40 | 4;

      }

      piVar11 = DAT_0059cbd8;

      if (DAT_0059cbd8 != (int *)0x0) {

        do {

          iVar10 = piVar11[0xe];

          piVar11[0xf] = (int)(*(float *)(iVar10 + 0xa0) - *(float *)(DAT_0059cbd8[0xe] + 0xa0));

          piVar11[0x10] = (int)(*(float *)(iVar10 + 0xa4) - *(float *)(DAT_0059cbd8[0xe] + 0xa4));

          piVar11[0x11] = (int)(*(float *)(iVar10 + 0xa8) - *(float *)(DAT_0059cbd8[0xe] + 0xa8));

          piVar11 = (int *)*piVar11;

        } while (piVar11 != (int *)0x0);

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

    world_reset_callback_add(&LAB_004386c0);

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

    DAT_0059cd30 = MemAllocMsg(10,iVar3 * 0x24,s_objids_00557080,

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

    DAT_0059cd2c = MemAllocMsg(10,(uVar10 + 1) * 0x24,s_groupids_00557074,

                               s_C__Giants_source_main_editor_c_00556ff0,0x4d5);

    iVar3 = 0;

    iVar4 = 0;

    do {

      crt_sprintf(iVar4 + 4 + DAT_0059cd2c,s_Group_d_0055706c,iVar3);

      iVar3 = iVar3 + 1;

      iVar4 = iVar4 + 0x24;

    } while (iVar3 <= (int)uVar10);

    DAT_0059cd38 = uVar10 + 1;

    local_a4 = BinFileSeek_2(s_bld_yy_names_bld_00557054,&DAT_00557068);

    if (local_a4 != 0) {

LAB_004384e0:

      iVar3 = crt_scanf_getchar2(local_a0,0x50,local_a4);

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

        crt_scanf_entry(iVar3,s__define_ObjObj_s__d_00557040,local_50,&local_a8);

        if (local_a8 == 0) {

          local_a8 = -1;

          crt_scanf_entry(iVar3,s__define_ObjGroup_s__d_00557018,local_50,&local_a8);

          if ((-1 < local_a8) && (local_a8 <= (int)uVar10)) {

            if (bVar2) {

              crt_sprintf(&DAT_00657400,s__s_is_too_long_00557030,local_a0);

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

            crt_sprintf(&DAT_00657400,s__s_is_too_long_00557030,local_a0);

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

      editor_0054384c(local_a4);

    }

    iVar11 = 0;

    iVar3 = DAT_0059cd30;

    iVar4 = DAT_0059cd34;

    if (0 < DAT_0059cd34) {

      iVar12 = 0;

      do {

        if (*(char *)(iVar12 + 4 + iVar3) == '\0') {

          crt_sprintf(iVar12 + 4 + iVar3,s_Obj_d_00557010,*(undefined4 *)(iVar12 + iVar3));

          iVar3 = DAT_0059cd30;

          iVar4 = DAT_0059cd34;

        }

        iVar11 = iVar11 + 1;

        iVar12 = iVar12 + 0x24;

      } while (iVar11 < iVar4);

    }

    crt_qsort_helper(iVar3,iVar4,0x24,&LAB_004386a0);

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

  

  uVar2 = wredit_00428460(DAT_0059cd54,1);

  iVar3 = wredit_00428670(DAT_0059cd54,1,uVar2);

  DAT_0059cd40 = iVar3;

  if (DAT_0059cc3c == 4) {

    DAT_0059cc30 = *(undefined4 *)(DAT_0059cd30 + iVar3 * 0x24);

    wredit_00439490();

    DAT_0059cc38 = 6;

    wredit_004959c0();

    dlog_push_level(&LAB_00438ef0,&LAB_00438dd0);

    DAT_00632ab0 = 0;

    DAT_00632aad = 0;

    DAT_00632aaa = 0;

    wredit_00519c70();

    main_editor_00438350();

    switch(DAT_0059cc38) {

    case 0:

      wredit_menu_draw();

      return;

    case 1:

      wredit_group_select();

      return;

    case 2:

      wredit_object_select();

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

      wredit_marker_menu_full();

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

    wredit_00439490();

    if (DAT_0059cbd8 == (undefined4 *)0x0) {

      uVar2 = object_spawn_42(*(undefined4 *)(DAT_0059cd30 + iVar3 * 0x24));

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

                   MemAllocMsg(10,0x3844,s_EditUndoData_00556fe0,

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

        object_destroy(DAT_0059cbd8[0xe]);

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

        uVar2 = object_spawn_42(*(undefined4 *)(iVar3 * 0x24 + DAT_0059cd30));

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

  

  crt_sprintf(local_208,s_bld_WO__s_bld_00558564);

  crt_sprintf(local_108,s_bld_WO__s_old_00558554,*(undefined4 *)(DAT_006330e4 + 4));

  MoveFileExA(local_208,local_108,1);

  main_editor_00438350();

  iVar2 = BinFileSeek_2(local_208,&DAT_00558550);

  iVar5 = 0;

  if (iVar2 == 0) {

    crt_sprintf(&DAT_00657400,s_Failed_to_create__s_0055853c,local_208);

    error_screen_show(&DAT_00657400);

    return;

  }

  crt_file_free_init(iVar2,s___This_file_may_be_generated_by_g_005584f8);

  crt_file_free_init(iVar2,s___Objects_sorted_from_location___005584c4,

                     (double)*(float *)(DAT_00632a88 + 0xa0),(double)*(float *)(DAT_00632a88 + 0xa4)

                     ,(double)*(float *)(DAT_00632a88 + 0xa8));

  crt_file_free_init(iVar2,s_ObjEditStart_005584b4);

  __ftol();

  uVar3 = __ftol();

  __ftol(uVar3);

  crt_file_free_init();

  __ftol();

  uVar3 = __ftol();

  __ftol(uVar3);

  crt_file_free_init();

  crt_file_free_init(iVar2,s_bumpclampvalue__f_0055846c,(double)*(float *)(DAT_006330e4 + 0x4f38));

  crt_file_free_init(iVar2,s_DisableScenerios__d_00558454,*(undefined4 *)(DAT_006330e4 + 0x4e88));

  crt_file_free_init(iVar2,s_WaterColor__f__f__f__f__f__f__f___00558400,

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

                     (double)*(float *)(DAT_006330e4 + 0x50a4),

                     (double)*(float *)(DAT_006330e4 + 0x50a8),

                     (double)*(float *)(DAT_006330e4 + 0x50ac),

                     (double)*(float *)(DAT_006330e4 + 0x50b0),

                     (double)*(float *)(DAT_006330e4 + 0x50b4));

  iVar6 = 0;

  do {

    if (*(char *)(iVar6 + 0x2210 + DAT_006330e4) == '\0') {

      crt_file_free_init(iVar2,&DAT_00558214);

      break;

    }

    crt_file_free_init(iVar2,s_Mission__s_005583f4);

    iVar6 = iVar6 + 0x118;

  } while (iVar6 < 0x2300);

  iVar7 = 0;

  iVar6 = DAT_006330e4;

  do {

    iVar1 = *(int *)(iVar7 + 0x4550 + iVar6);

    if (iVar1 != 0) {

      crt_file_free_init(iVar2,s_Scenerio__d__d__s_005583e0,iVar1,

                         *(undefined4 *)(iVar7 + 0x4554 + iVar6),iVar7 + 0x4558 + iVar6);

      iVar6 = DAT_006330e4;

    }

    iVar7 = iVar7 + 0x30;

  } while (iVar7 < 0x510);

  crt_file_free_init(iVar2,&DAT_00558214);

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

      iVar6 = MemAllocMsg(10,iVar6 << 2,&DAT_005583dc,s_C__Giants_source_main_editor_c_00556ff0,

                          0xf77);

      for (piVar4 = DAT_00632d68; piVar4 != (int *)0x0; piVar4 = (int *)*piVar4) {

        iVar7 = piVar4[3];

        if ((((*(uint *)(iVar7 + 0xdc) & 0x20000000) != 0) && (*(int *)(iVar7 + 0x210) == 0)) &&

           ((*(uint *)(iVar7 + 0xd8) & 0x400) == 0)) {

          *(int *)(iVar6 + iVar5 * 4) = iVar7;

          iVar5 = iVar5 + 1;

        }

      }

      crt_qsort_helper(iVar6,iVar5,4,&LAB_00441400);

      iVar7 = 0;

      if (0 < iVar5) {

        do {

          wredit_minishop_icons(iVar2,*(undefined4 *)(iVar6 + iVar7 * 4),0);

          iVar7 = iVar7 + 1;

        } while (iVar7 < iVar5);

      }

      mem_free_tagged(iVar6,s_C__Giants_source_main_editor_c_00556ff0,0xf8c);

    }

  }

  crt_file_free_init(iVar2,s_ObjEditEnd_005583cc);

  editor_0054384c(iVar2);

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

             MemAllocMsg(10,0x3844,s_EditUndoData_00556fe0,s_C__Giants_source_main_editor_c_00556ff0

                         ,0x1011);

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

