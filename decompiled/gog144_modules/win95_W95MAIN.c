/* Giants 1.449 — module win95/W95MAIN
 * 1 functions (1 named) — decompiled, names from PS2 symbols
 * Original source: C:\Giants\source\win95/W95MAIN.c(pp) (assert-string evidence)
 */

/* ===== loglauncher_process_2 @ 0x0051EAC0 ===== */
/* PS2 candidate: loglauncher_process (conf 0.271) */



undefined4 loglauncher_process_2(undefined4 param_1)



{

  char *pcVar1;

  char cVar2;

  float fVar3;

  bool bVar4;

  float fVar5;

  float fVar6;

  int iVar7;

  char *pcVar8;

  char *pcVar9;

  undefined4 uVar10;

  int iVar11;

  uint uVar12;

  uint uVar13;

  char *pcVar14;

  char *pcVar15;

  int *piVar16;

  char *pcVar17;

  char *pcVar18;

  float fStack_5e0;

  float fStack_5dc;

  int iStack_5d8;

  int iStack_5d4;

  char local_5c8 [4];

  char acStack_5c4 [128];

  undefined1 auStack_544 [4];

  int iStack_540;

  undefined1 auStack_53c [4];

  undefined1 auStack_538 [1336];

  

  pcVar17 = local_5c8;

  for (iVar11 = 0x172; iVar11 != 0; iVar11 = iVar11 + -1) {

    pcVar17[0] = '\0';

    pcVar17[1] = '\0';

    pcVar17[2] = '\0';

    pcVar17[3] = '\0';

    pcVar17 = pcVar17 + 4;

  }

  (**(code **)(DAT_00656420 + 0x98))(DAT_00656420,0);

  (**(code **)(DAT_00656420 + 0xa8))(DAT_00656420);

  iVar11 = stream_player_start(param_1);

  if (iVar11 == 0) {

    return 0;

  }

  iVar7 = FUN_00517990(iVar11);

  pcVar8 = (char *)MemAllocMsg(0x13,iVar7 + 1,s_intro_0057dc44,

                               s_C__Giants_source_win95_W95MAIN_C_0057d858,0x7be);

  BinFileRead(iVar11,pcVar8,iVar7);

  ANM_BinderDestroy_2(iVar11);

  pcVar17 = pcVar8 + iVar7;

  *pcVar17 = '\0';

  iStack_5d8 = 0;

  if (pcVar8 < pcVar17) {

    iStack_5d4 = 0;

    pcVar14 = pcVar8;

    do {

      iVar11 = FUN_005451d1((int)*pcVar14);

      while (iVar11 != 0) {

        pcVar9 = pcVar14 + 1;

        pcVar14 = pcVar14 + 1;

        iVar11 = FUN_005451d1((int)*pcVar9);

      }

      cVar2 = *pcVar14;

      pcVar9 = pcVar14;

      while (((cVar2 != '\0' && (*pcVar9 != '.')) &&

             (iVar11 = FUN_005451d1((int)*pcVar9), iVar11 == 0))) {

        cVar2 = pcVar9[1];

        pcVar9 = pcVar9 + 1;

      }

      pcVar1 = acStack_5c4 + iStack_5d4;

      pcVar15 = pcVar14;

      pcVar18 = pcVar1;

      for (uVar12 = (uint)((int)pcVar9 - (int)pcVar14) >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {

        *(undefined4 *)pcVar18 = *(undefined4 *)pcVar15;

        pcVar15 = pcVar15 + 4;

        pcVar18 = pcVar18 + 4;

      }

      for (uVar12 = (int)pcVar9 - (int)pcVar14 & 3; uVar12 != 0; uVar12 = uVar12 - 1) {

        *pcVar18 = *pcVar15;

        pcVar15 = pcVar15 + 1;

        pcVar18 = pcVar18 + 1;

      }

      acStack_5c4[(int)(pcVar9 + (iStack_5d4 - (int)pcVar14))] = '\0';

      iVar11 = FUN_00545650(pcVar1,s_legal_0057dc3c);

      if (iVar11 == 0) {

        pcVar14 = (char *)__default_unexpected__Fv();

        uVar12 = 0xffffffff;

        do {

          pcVar15 = pcVar14;

          if (uVar12 == 0) break;

          uVar12 = uVar12 - 1;

          pcVar15 = pcVar14 + 1;

          cVar2 = *pcVar14;

          pcVar14 = pcVar15;

        } while (cVar2 != '\0');

        uVar12 = ~uVar12;

        iVar11 = -1;

        pcVar14 = pcVar1;

        do {

          pcVar18 = pcVar14;

          if (iVar11 == 0) break;

          iVar11 = iVar11 + -1;

          pcVar18 = pcVar14 + 1;

          cVar2 = *pcVar14;

          pcVar14 = pcVar18;

        } while (cVar2 != '\0');

        pcVar14 = pcVar15 + -uVar12;

        pcVar15 = pcVar18 + -1;

        for (uVar13 = uVar12 >> 2; uVar13 != 0; uVar13 = uVar13 - 1) {

          *(undefined4 *)pcVar15 = *(undefined4 *)pcVar14;

          pcVar14 = pcVar14 + 4;

          pcVar15 = pcVar15 + 4;

        }

        for (uVar12 = uVar12 & 3; uVar12 != 0; uVar12 = uVar12 - 1) {

          *pcVar15 = *pcVar14;

          pcVar14 = pcVar14 + 1;

          pcVar15 = pcVar15 + 1;

        }

      }

      uVar10 = main_texture_005088d0

                         (pcVar1,auStack_544 + iStack_5d4,(int)&iStack_540 + iStack_5d4,

                          auStack_53c + iStack_5d4,auStack_538 + iStack_5d4);

      *(undefined4 *)(acStack_5c4 + iStack_5d4 + -4) = uVar10;

      iStack_5d4 = iStack_5d4 + 0x94;

      iStack_5d8 = iStack_5d8 + 1;

      if (0x5c7 < iStack_5d4) break;

      cVar2 = *pcVar9;

      pcVar14 = pcVar9;

      while (((cVar2 != '\0' && (cVar2 != '\n')) && (cVar2 != '\r'))) {

        pcVar9 = pcVar14 + 1;

        pcVar14 = pcVar14 + 1;

        cVar2 = *pcVar9;

      }

    } while (pcVar14 < pcVar17);

  }

  if (0 < iStack_5d8) {

    piVar16 = &iStack_540;

    do {

      if (piVar16[-0x22] != 0) {

        (**(code **)(DAT_00656420 + 0x98))(DAT_00656420,0);

        FUN_00451cf0();

        fStack_5dc = (float)piVar16[-1] / (float)DAT_00632e84;

        fStack_5e0 = (float)*piVar16 / (float)DAT_00632e88;

        if (1.0 < fStack_5dc) {

          fStack_5dc = 1.0;

        }

        if (1.0 < fStack_5e0) {

          fStack_5e0 = 1.0;

        }

        dlog_alpha_blend(fStack_5dc,fStack_5e0,piVar16[-1],*piVar16,0x3f800000,piVar16[2]);

        FUN_00451da0();

        (**(code **)(DAT_00656420 + 0xa8))(DAT_00656420);

        time_frame_update();

        fVar5 = DAT_006328e8;

        fVar3 = DAT_006328e8;

        while (DAT_006328e8 - fVar5 < 0.2) {

          time_frame_update();

          fVar6 = DAT_006328e8;

          if (0.01 <= DAT_006328e8 - fVar3) {

            fVar3 = DAT_006328e8 - fVar5;

            (**(code **)(DAT_00656420 + 0x98))(DAT_00656420,0);

            FUN_00451cf0();

            fStack_5dc = (float)piVar16[-1] / (float)DAT_00632e84;

            fStack_5e0 = (float)*piVar16 / (float)DAT_00632e88;

            if (1.0 < fStack_5dc) {

              fStack_5dc = 1.0;

            }

            if (1.0 < fStack_5e0) {

              fStack_5e0 = 1.0;

            }

            dlog_alpha_blend(fStack_5dc,fStack_5e0,piVar16[-1],*piVar16,1.0 - fVar3 * 5.0,piVar16[2]

                            );

            FUN_00451da0();

            (**(code **)(DAT_00656420 + 0xa8))(DAT_00656420);

            dinput_key_poll();

            input_keystate_update();

            hud_status_main();

            if (((DAT_00632aa8 != '\0') || (DAT_00632aab != '\0')) ||

               ((DAT_00632aae != '\0' || (fVar3 = fVar6, DAT_00632aa4._3_1_ != '\0')))) break;

          }

        }

        (**(code **)(DAT_00656420 + 0x98))(DAT_00656420,0);

        FUN_00451cf0();

        fStack_5dc = (float)piVar16[-1] / (float)DAT_00632e84;

        fStack_5e0 = (float)*piVar16 / (float)DAT_00632e88;

        if (1.0 < fStack_5dc) {

          fStack_5dc = 1.0;

        }

        if (1.0 < fStack_5e0) {

          fStack_5e0 = 1.0;

        }

        dlog_alpha_blend(fStack_5dc,fStack_5e0,piVar16[-1],*piVar16,0,piVar16[2]);

        FUN_00451da0();

        (**(code **)(DAT_00656420 + 0xa8))(DAT_00656420);

        (**(code **)(DAT_00656420 + 0x98))(DAT_00656420,0);

        FUN_00451cf0();

        fStack_5dc = (float)piVar16[-1] / (float)DAT_00632e84;

        fStack_5e0 = (float)*piVar16 / (float)DAT_00632e88;

        if (1.0 < fStack_5dc) {

          fStack_5dc = 1.0;

        }

        if (1.0 < fStack_5e0) {

          fStack_5e0 = 1.0;

        }

        dlog_alpha_blend(fStack_5dc,fStack_5e0,piVar16[-1],*piVar16,0,piVar16[2]);

        FUN_00451da0();

        (**(code **)(DAT_00656420 + 0xa8))(DAT_00656420);

        time_frame_update();

        fVar5 = DAT_006328e8;

        bVar4 = false;

        fVar3 = DAT_006328e8;

        do {

          do {

            if (12.0 <= DAT_006328e8 - fVar5) goto LAB_0051f08e;

            time_frame_update();

            fVar6 = DAT_006328e8;

          } while (DAT_006328e8 - fVar3 < 0.01);

          dinput_key_poll();

          input_keystate_update();

          hud_status_main();

        } while ((((DAT_00632aa8 == '\0') && (DAT_00632aab == '\0')) && (DAT_00632aae == '\0')) &&

                (fVar3 = fVar6, DAT_00632aa4._3_1_ == '\0'));

        bVar4 = true;

LAB_0051f08e:

        time_frame_update();

        fVar5 = DAT_006328e8;

        fVar3 = DAT_006328e8;

        do {

          do {

            if (0.2 <= DAT_006328e8 - fVar5) goto LAB_0051f1b8;

            time_frame_update();

            fVar6 = DAT_006328e8;

          } while (DAT_006328e8 - fVar3 < 0.01);

          fVar3 = DAT_006328e8 - fVar5;

          (**(code **)(DAT_00656420 + 0x98))(DAT_00656420,0);

          FUN_00451cf0();

          fStack_5dc = (float)piVar16[-1] / (float)DAT_00632e84;

          fStack_5e0 = (float)*piVar16 / (float)DAT_00632e88;

          if (1.0 < fStack_5dc) {

            fStack_5dc = 1.0;

          }

          if (1.0 < fStack_5e0) {

            fStack_5e0 = 1.0;

          }

          dlog_alpha_blend(fStack_5dc,fStack_5e0,piVar16[-1],*piVar16,fVar3 * 5.0,piVar16[2]);

          FUN_00451da0();

          (**(code **)(DAT_00656420 + 0xa8))(DAT_00656420);

          fVar3 = fVar6;

        } while (!bVar4);

LAB_0051f1b8:

        (**(code **)(DAT_00656420 + 0x98))(DAT_00656420,0);

        FUN_00451cf0();

        fStack_5dc = (float)piVar16[-1] / (float)DAT_00632e84;

        fStack_5e0 = (float)*piVar16 / (float)DAT_00632e88;

        if (1.0 < fStack_5dc) {

          fStack_5dc = 1.0;

        }

        if (1.0 < fStack_5e0) {

          fStack_5e0 = 1.0;

        }

        dlog_alpha_blend(fStack_5dc,fStack_5e0,piVar16[-1],*piVar16,0x3f800000,piVar16[2]);

        FUN_00451da0();

        (**(code **)(DAT_00656420 + 0xa8))(DAT_00656420);

        main_texture_00508eb0(piVar16[-1],*piVar16,piVar16[1],piVar16[2]);

      }

      piVar16 = piVar16 + 0x25;

      iStack_5d8 = iStack_5d8 + -1;

    } while (iStack_5d8 != 0);

  }

  mem_free_tagged(pcVar8,s_C__Giants_source_win95_W95MAIN_C_0057d858,0x824);

  return 1;

}

