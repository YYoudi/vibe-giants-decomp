/* Giants 1.449 — module _unmapped_0052
 * 162 functions (89 named) — decompiled, names from PS2 symbols
 * Original source: C:\Giants\source\_unmapped_0052.c(pp) (assert-string evidence)
 */

/* ===== comm_client_connect_menu @ 0x00520050 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void comm_client_connect_menu(void)



{

  byte bVar1;

  byte *pbVar2;

  int iVar3;

  int iVar4;

  undefined4 uVar5;

  byte *pbVar6;

  undefined4 *puVar7;

  bool bVar8;

  char *pcVar9;

  undefined4 auStack_348 [6];

  undefined4 uStack_330;

  undefined4 uStack_32c;

  undefined4 uStack_328;

  undefined4 uStack_324;

  undefined1 auStack_300 [256];

  WCHAR local_200 [256];

  

  if ((DAT_005def80 == 2) && (DAT_00632f68 != '\0')) {

    pbVar2 = (byte *)FUN_00507b00();

    pbVar6 = (byte *)&DAT_00632f68;

    do {

      bVar1 = *pbVar6;

      bVar8 = bVar1 < *pbVar2;

      if (bVar1 != *pbVar2) {

LAB_005200b6:

        iVar3 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);

        goto LAB_005200bb;

      }

      if (bVar1 == 0) break;

      bVar1 = pbVar6[1];

      bVar8 = bVar1 < pbVar2[1];

      if (bVar1 != pbVar2[1]) goto LAB_005200b6;

      pbVar6 = pbVar6 + 2;

      pbVar2 = pbVar2 + 2;

    } while (bVar1 != 0);

    iVar3 = 0;

LAB_005200bb:

    if (iVar3 != 0) {

      MultiByteToWideChar(0,0,&DAT_00632f68,-1,local_200,0x200);

      iVar3 = *DAT_005def70;

      iVar4 = FUN_005451f9(local_200,1);

      iVar3 = (**(code **)(iVar3 + 0x48))(DAT_005def70,u_hostname_0057dec0,local_200,iVar4 * 2 + 2);

      if (iVar3 < 0) {

        return;

      }

      FUN_0051a090(s_IPAddress_0057de38,&DAT_00632f68);

    }

  }

  if (DAT_00632fa8 != 0) {

    iVar3 = (**(code **)(*DAT_005def70 + 0x48))(DAT_005def70,u_port_0057ddd0,&DAT_00632fa8,4,2);

    if (iVar3 < 0) {

      return;

    }

    FUN_00542f27(auStack_300,&DAT_00557088,DAT_00632fa8);

    FUN_0051a090(s_IPPort_0057deb8,auStack_300);

  }

  DAT_00632c0c = 1;

  if (DAT_0059ee98 != 0) {

    FUN_00497510();

  }

  DAT_0059ee98 = object_allocate_type(0x403,0x80000000);

  *(uint *)(DAT_0059ee98 + 0xd8) = *(uint *)(DAT_0059ee98 + 0xd8) | 0x40000000;

  camera_override_refpt(DAT_0059ee98,0);

  dlog_push_level(&LAB_005207c0,&LAB_00520480);

  DAT_005def88 = main_dlog_00427150();

  uVar5 = FUN_00507b00(&DAT_0057deb0);

  uVar5 = FUN_00507b00(s_ReturnToMainMenu_0057de9c,uVar5);

  FUN_00542f27(auStack_300,s__s___s__0057de94,uVar5);

  main_dlog_00427890(DAT_005def88,1000,0x3f000000,0xc0000000,0x88000002,auStack_300);

  comm_00427860(DAT_005def88,1000,0xc8c832);

  if (((DAT_005def80 == 2) || (DAT_00633160 != 0)) && (DAT_00632f68 != '\0')) {

    pbVar2 = (byte *)FUN_00507b00();

    pbVar6 = (byte *)&DAT_00632f68;

    do {

      bVar1 = *pbVar6;

      bVar8 = bVar1 < *pbVar2;

      if (bVar1 != *pbVar2) {

LAB_0052029c:

        iVar3 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);

        goto LAB_005202a1;

      }

      if (bVar1 == 0) break;

      bVar1 = pbVar6[1];

      bVar8 = bVar1 < pbVar2[1];

      if (bVar1 != pbVar2[1]) goto LAB_0052029c;

      pbVar6 = pbVar6 + 2;

      pbVar2 = pbVar2 + 2;

    } while (bVar1 != 0);

    iVar3 = 0;

LAB_005202a1:

    if (iVar3 != 0) {

      pcVar9 = s_CommWaitingHost_0057de84;

      goto LAB_005202e6;

    }

  }

  pcVar9 = s_CommSelectGame_0057de74;

LAB_005202e6:

  main_dlog_004273b0(DAT_005def88,0x3e9,0x3f000000,0x40000000,CONCAT44(pcVar9,0x8a000000));

  uVar5 = FUN_00507b00(s_CommClientVersion_0057de60,(double)((float)DAT_0063303c * 0.001));

  FUN_00542f27(auStack_300,s__s__1_3f_0057de54,uVar5);

  main_dlog_00427890(DAT_005def88,0x3eb,0x3c23d70a,0,0x81000000,auStack_300);

  comm_00427860(DAT_005def88,0x3eb,0xc8c832);

  main_dlog_00427e80(DAT_005def88,1,0x3f000000,0x40800000,0x88000020);

  DAT_00632ee4 = 0xffffffff;

  _DAT_005def98 = DAT_00632e6c;

  if (DAT_00633180 == 0) {

    puVar7 = auStack_348;

    for (iVar3 = 0x12; iVar3 != 0; iVar3 = iVar3 + -1) {

      *puVar7 = 0;

      puVar7 = puVar7 + 1;

    }

    auStack_348[0] = 0x48;

    uStack_330 = *(undefined4 *)PTR_DAT_0057dc4c;

    uStack_32c = *(undefined4 *)(PTR_DAT_0057dc4c + 4);

    uStack_328 = *(undefined4 *)(PTR_DAT_0057dc4c + 8);

    uStack_324 = *(undefined4 *)(PTR_DAT_0057dc4c + 0xc);

    if (DAT_005def74 != 0) {

      (**(code **)(*DAT_005def64 + 0x18))(DAT_005def64,DAT_005def74,0);

      DAT_005def74 = 0;

    }

    iVar3 = (**(code **)(*DAT_005def64 + 0x14))

                      (DAT_005def64,auStack_348,DAT_005def70,DAT_005def6c,0,0,0xffffffff,0,

                       0xffffffff,0,&DAT_005def74,0);

    if (((-1 < iVar3) && (iVar3 = main_dlog_00428490(DAT_005def88,1), iVar3 == 0)) &&

       (DAT_00633160 == 0)) {

      main_dlog_00428340(DAT_005def88,1,s_CommNoSessions_0057de44);

    }

    _DAT_005def44 = 0x40000000;

    return;

  }

  comm_comm_00520490();

  return;

}

/* ===== gamespy_send_statechange @ 0x00520B90 ===== */
void gamespy_send_statechange(void)



{

  char cVar1;

  int iVar2;

  char *pcVar3;

  undefined4 uVar4;

  char *pcVar5;

  char local_28 [40];

  

  if ((DAT_005def80 == 5) && (DAT_00632f44 == 0)) {

    comm_audio_vol_e();

    return;

  }

  if (DAT_00632f2c < 5) {

    DAT_00632f2c = DAT_00632f2c + 1;

  }

  else {

    DAT_00632f2c = DAT_00632f2c + 5;

  }

  if (0x1e < DAT_00632f2c) {

    DAT_00632f2c = 0;

  }

  iVar2 = DAT_00632f2c;

  if (((DAT_005def80 != 5) || (DAT_00632f44 != 0)) && (1 < DAT_00632f08)) {

    comm_0051a130(s_CapturePreventTime_00559fa8,DAT_00632f2c);

  }

  if (DAT_005def8c != 0) {

    if (iVar2 == 0) {

      pcVar3 = (char *)FUN_00507b00(s_ButtonNone_0057df64);

      pcVar5 = local_28;

      do {

        cVar1 = *pcVar3;

        pcVar3 = pcVar3 + 1;

        *pcVar5 = cVar1;

        pcVar5 = pcVar5 + 1;

      } while (cVar1 != '\0');

    }

    else {

      comm_004ce880(iVar2 * 0x3c,local_28);

    }

    main_dlog_00427230(DAT_005def8c,0x19a);

    main_dlog_00427890(DAT_005def8c,0x19a,DAT_0057dc98,0x41a80000,0x81000002,local_28);

    if ((((DAT_005def80 == 5) && (DAT_00632f44 == 0)) || (DAT_00632f08 < 2)) &&

       ((DAT_005def94 != DAT_005def5c || (DAT_00632f08 < 2)))) {

      uVar4 = 0xa0a0a0;

    }

    else {

      uVar4 = 0xc8c832;

    }

    comm_00427860(DAT_005def8c,0x19a,uVar4);

  }

  comm_comm_00529e00();

  DAT_00632f30 = (float)DAT_00632f2c * 60.0;

  comm_0052b780_user_3(0);

  if (((DAT_00632f44 != 0) && (DAT_0063317c == 0)) && (DAT_00633184 == 0)) {

    if (DAT_005defa4 != 0) {

      FUN_0051ea20(s_gamespy_send_statechange_called_a_0057df34);

      sound_play(0x65a);

      return;

    }

    if (DAT_005defa0 == 0) {

      FUN_0051ea20(s_gamespy_send_statechange_called_w_0057df04);

      sound_play(0x65a);

      return;

    }

    gamespy_0052daa0(0);

  }

  sound_play(0x65a);

  return;

}

/* ===== FUN_00520D70 @ 0x00520D70 ===== */
void FUN_00520D70(void)



{

  undefined4 uVar1;

  

  if ((DAT_005def80 == 5) && (DAT_00632f44 == 0)) {

    comm_audio_vol_f();

    if (0xd < DAT_00632f08) {

      if ((float)DAT_00632e88 < 480.0 != ((float)DAT_00632e88 == 480.0)) {

        win95_text_0051b160();

        win95_text_0051adb0(0x18);

      }

      if (DAT_00632f08 < 0xe) {

        if (DAT_005def8c != 0) {

          main_dlog_00427180(DAT_005def8c);

        }

        DAT_005def8c = 0;

        dialog_level_pop(&LAB_00525460);

        goto LAB_00520ebe;

      }

      if (DAT_005def8c != 0) {

        main_dlog_00427180(DAT_005def8c);

      }

      DAT_005def8c = 0;

      dialog_level_pop(&LAB_00525460);

      DAT_00632e44 = 0;

      if ((DAT_00632f44 != 0) || (DAT_005def94 == DAT_005def5c)) {

        comm_change_options_menu();

        return;

      }

    }

  }

  else {

    DAT_00633000 = 1;

    if (DAT_005def8c != 0) {

      if ((((DAT_005def80 == 5) && (DAT_00632f44 == 0)) || (DAT_00632f08 < 0xe)) &&

         ((DAT_005def94 != DAT_005def5c || (DAT_00632f08 < 0xe)))) {

        uVar1 = 0xa0a0a0;

      }

      else {

        uVar1 = 0xc8c832;

      }

      comm_00427860(DAT_005def8c,0x1fd,uVar1);

    }

    comm_0052b780_user_1(0);

    sound_play(0x65a);

    if ((0xd < DAT_00632f08) && (DAT_005def8c != 0)) {

      if ((float)DAT_00632e88 < 480.0 != ((float)DAT_00632e88 == 480.0)) {

        win95_text_0051b160();

        win95_text_0051adb0(0x18);

      }

      if (DAT_00632f08 < 0xe) {

        if (DAT_005def8c != 0) {

          main_dlog_00427180(DAT_005def8c);

        }

        DAT_005def8c = 0;

        dialog_level_pop(&LAB_00525460);

LAB_00520ebe:

        main_texture_00508eb0(DAT_005ddf4c,DAT_005ddf50,DAT_005ddf54,DAT_005ddf58);

        DAT_005ddf58 = 0;

        if (DAT_00632f44 != 0) {

          comm_0052b780_user_2();

          Sleep(500);

          gamespy_host_game();

          return;

        }

        comm_0052b430_user();

        Sleep(500);

        gamespy_host_game();

        return;

      }

      if (DAT_005def8c != 0) {

        main_dlog_00427180(DAT_005def8c);

      }

      DAT_005def8c = 0;

      dialog_level_pop(&LAB_00525460);

      DAT_00632e44 = 0;

      if ((DAT_00632f44 != 0) || (DAT_005def94 == DAT_005def5c)) {

        comm_change_options_menu();

        return;

      }

    }

  }

  return;

}

/* ===== comm_damage_teams_menu @ 0x00520FD0 ===== */
void comm_damage_teams_menu(void)



{

  uint uVar1;

  char *pcVar2;

  undefined4 uVar3;

  

  if ((DAT_005def80 == 5) && (DAT_00632f44 == 0)) {

    comm_audio_vol_b();

    return;

  }

  uVar1 = DAT_00632f20 ^ 1;

  DAT_00632f20 = uVar1;

  if (((DAT_005def80 != 5) || (DAT_00632f44 != 0)) && (1 < DAT_00632f08)) {

    comm_0051a130(s_DamageTeammates_00559fec,uVar1);

  }

  if (DAT_005def8c != 0) {

    pcVar2 = s_ButtonYes_0057df7c;

    if (uVar1 == 0) {

      pcVar2 = s_ButtonNo_0057df70;

    }

    uVar3 = FUN_00507b00(pcVar2);

    main_dlog_00427230(DAT_005def8c,0x194);

    main_dlog_00427890(DAT_005def8c,0x194,DAT_0057dc98,0x41900000,0x81000002,uVar3);

    if ((((DAT_005def80 == 5) && (DAT_00632f44 == 0)) || (DAT_00632f08 < 2)) &&

       ((DAT_005def94 != DAT_005def5c || (DAT_00632f08 < 2)))) {

      uVar3 = 0xa0a0a0;

    }

    else {

      uVar3 = 0xc8c832;

    }

    comm_00427860(DAT_005def8c,0x194,uVar3);

  }

  comm_comm_00529e00();

  if (((DAT_00632f44 != 0) && (DAT_0063317c == 0)) && (DAT_00633184 == 0)) {

    if (DAT_005defa4 != 0) {

      FUN_0051ea20(s_gamespy_send_statechange_called_a_0057df34);

      sound_play(0x65a);

      return;

    }

    if (DAT_005defa0 == 0) {

      FUN_0051ea20(s_gamespy_send_statechange_called_w_0057df04);

      sound_play(0x65a);

      return;

    }

    gamespy_0052daa0(0);

  }

  sound_play(0x65a);

  return;

}

/* ===== comm_player_name @ 0x00521150 ===== */
void comm_player_name(int param_1,int param_2)



{

  char cVar1;

  int iVar2;

  undefined4 uVar3;

  char *pcVar4;

  uint uVar5;

  uint uVar6;

  char *pcVar7;

  char *pcVar8;

  char local_200 [256];

  char local_100 [256];

  

  if ((DAT_005def80 == 5) && (DAT_00632f44 == 0)) {

    if (param_1 < 0) {

      comm_audio_vol_a(0);

      return;

    }

    comm_audio_vol_a((&DAT_005ddf60)[param_1]);

  }

  else {

    if (param_1 < 0) {

      iVar2 = 0;

    }

    else {

      iVar2 = (&DAT_005ddf60)[param_1];

    }

    if (iVar2 != DAT_005def5c) {

      if (param_2 == 0) {

        if (param_1 < 0) {

          pcVar4 = &DAT_005561ac;

        }

        else {

          pcVar4 = &DAT_005ddfc0 + param_1 * 0x20;

          if (*pcVar4 == '\0') {

            if ((DAT_00632f44 != 0) &&

               (iVar2 = comm_comm_0052acc0((&DAT_005ddf60)[param_1],local_100,0x100), iVar2 != 0)) {

              _strncpy(pcVar4,local_100,0x20);

              (&DAT_005ddfdf)[param_1 * 0x20] = 0;

            }

            if (*pcVar4 == '\0') {

              uVar3 = FUN_00507b00(s_CommUnnamedPlayer_0057df98,param_1);

              FUN_00542f27(pcVar4,s__s__d_00555f38,uVar3);

            }

          }

        }

        pcVar7 = local_200;

        do {

          cVar1 = *pcVar4;

          pcVar4 = pcVar4 + 1;

          *pcVar7 = cVar1;

          pcVar7 = pcVar7 + 1;

        } while (cVar1 != '\0');

        iVar2 = -1;

        pcVar4 = local_200;

        do {

          pcVar7 = pcVar4;

          if (iVar2 == 0) break;

          iVar2 = iVar2 + -1;

          pcVar7 = pcVar4 + 1;

          cVar1 = *pcVar4;

          pcVar4 = pcVar7;

        } while (cVar1 != '\0');

        *(undefined2 *)(pcVar7 + -1) = DAT_0055c728;

        pcVar4 = (char *)FUN_00507b00(s_CommWasKicked_0057df88);

        uVar5 = 0xffffffff;

        do {

          pcVar7 = pcVar4;

          if (uVar5 == 0) break;

          uVar5 = uVar5 - 1;

          pcVar7 = pcVar4 + 1;

          cVar1 = *pcVar4;

          pcVar4 = pcVar7;

        } while (cVar1 != '\0');

        uVar5 = ~uVar5;

        iVar2 = -1;

        pcVar4 = local_200;

        do {

          pcVar8 = pcVar4;

          if (iVar2 == 0) break;

          iVar2 = iVar2 + -1;

          pcVar8 = pcVar4 + 1;

          cVar1 = *pcVar4;

          pcVar4 = pcVar8;

        } while (cVar1 != '\0');

        pcVar4 = pcVar7 + -uVar5;

        pcVar7 = pcVar8 + -1;

        for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {

          *(undefined4 *)pcVar7 = *(undefined4 *)pcVar4;

          pcVar4 = pcVar4 + 4;

          pcVar7 = pcVar7 + 4;

        }

        for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {

          *pcVar7 = *pcVar4;

          pcVar4 = pcVar4 + 1;

          pcVar7 = pcVar7 + 1;

        }

        comm_audio_volume_user(local_200,1,0,0);

        sound_play(0x65a);

      }

      else {

        FUN_0052f6e0(param_1);

      }

      if (param_1 < 0) {

        uVar3 = 0;

      }

      else {

        uVar3 = (&DAT_005ddf60)[param_1];

      }

      if (DAT_00632f44 != 0) {

        (**(code **)(*DAT_005def60 + 0x60))(DAT_005def60,uVar3,0,0,0);

        return;

      }

    }

  }

  return;

}

/* ===== FUN_00521310 @ 0x00521310 ===== */
undefined4 FUN_00521310(int param_1)



{

  if ((param_1 != 6) && (param_1 != 7)) {

    return 0;

  }

  return 1;

}

/* ===== FUN_00521330 @ 0x00521330 ===== */
undefined4 FUN_00521330(int param_1)



{

  if ((param_1 != 4) && (param_1 != 5)) {

    return 0;

  }

  return 1;

}

/* ===== FUN_00521350 @ 0x00521350 ===== */
undefined4 FUN_00521350(int param_1)



{

  if (((param_1 < 0) || (3 < param_1)) && ((param_1 < 6 || (7 < param_1)))) {

    return 0;

  }

  return 1;

}

/* ===== FUN_00521370 @ 0x00521370 ===== */
undefined4 FUN_00521370(int param_1)



{

  if ((((param_1 != 2) && (param_1 != 3)) && (param_1 != 5)) && (param_1 != 7)) {

    return 0;

  }

  return 1;

}

/* ===== FUN_005213a0 @ 0x005213A0 ===== */
undefined4 FUN_005213a0(int param_1)



{

  if ((((param_1 != 1) && (param_1 != 3)) && (param_1 != 6)) && (param_1 != 7)) {

    return 0;

  }

  return 1;

}

/* ===== comm_session_menu @ 0x005213D0 ===== */
void comm_session_menu(char *param_1,int param_2)



{

  byte bVar1;

  int iVar2;

  

  if (param_2 != 0) {

    FUN_0051a090(s_SessionName_0055a018,&DAT_00632f48);

  }

  if (DAT_005def8c != 0) {

    main_dlog_00427230(DAT_005def8c,300);

    if ((param_1 == (char *)0x0) || (*param_1 == '\0')) {

      param_1 = s__None__0057dfac;

    }

    main_dlog_00427890(DAT_005def8c,300,DAT_0057dc9c,0x41100000,0x81000002,param_1);

    iVar2 = comm_00426540();

    if (iVar2 != 0) {

      comm_00427860(DAT_005def8c,300,0xa0a0a0);

      return;

    }

    if (((DAT_005def80 == 5) && (DAT_00632f44 == 0)) || (DAT_00632f08 != 2)) {

      bVar1 = 0;

    }

    else {

      bVar1 = 1;

    }

    comm_00427860(DAT_005def8c,300,(-(uint)bVar1 & 0x282792) + 0xa0a0a0);

  }

  return;

}

/* ===== comm_gtype_name @ 0x005214B0 ===== */
void comm_gtype_name(int param_1,char *param_2)



{

  char cVar1;

  char *pcVar2;

  undefined1 local_3c [60];

  

  FUN_00542f27(local_3c,s_GType_s_0057dfb4,(&PTR_DAT_0057dc6c)[param_1]);

  pcVar2 = (char *)FUN_00507b00(local_3c);

  do {

    cVar1 = *pcVar2;

    pcVar2 = pcVar2 + 1;

    *param_2 = cVar1;

    param_2 = param_2 + 1;

  } while (cVar1 != '\0');

  return;

}

/* ===== comm_gametype_menu @ 0x005214F0 ===== */
void comm_gametype_menu(int param_1)



{

  char cVar1;

  byte bVar2;

  char *pcVar3;

  int iVar4;

  char *pcVar5;

  undefined1 local_bc [60];

  char local_80 [128];

  

  if (((DAT_005def80 != 5) || (DAT_00632f44 != 0)) && (DAT_00632f08 == 2)) {

    comm_0051a130(s_GameType_0055a00c,param_1);

  }

  if (DAT_005def8c != 0) {

    main_dlog_00427230(DAT_005def8c,0x12e);

    FUN_00542f27(local_bc,s_GType_s_0057dfb4,(&PTR_DAT_0057dc6c)[param_1]);

    pcVar3 = (char *)FUN_00507b00(local_bc);

    pcVar5 = local_80;

    do {

      cVar1 = *pcVar3;

      pcVar3 = pcVar3 + 1;

      *pcVar5 = cVar1;

      pcVar5 = pcVar5 + 1;

    } while (cVar1 != '\0');

    main_dlog_00427890(DAT_005def8c,0x12e,DAT_0057dc9c,0x41200000,0x81000002,local_80);

    iVar4 = comm_00426540();

    if (iVar4 != 0) {

      comm_00427860(DAT_005def8c,0x12e,0xa0a0a0);

      return;

    }

    if (((DAT_005def80 == 5) && (DAT_00632f44 == 0)) || (DAT_00632f08 != 2)) {

      bVar2 = 0;

    }

    else {

      bVar2 = 1;

    }

    comm_00427860(DAT_005def8c,0x12e,(-(uint)bVar2 & 0x282792) + 0xa0a0a0);

  }

  return;

}

/* ===== comm_00521620 @ 0x00521620 ===== */
void comm_00521620(int param_1)



{

  byte bVar1;

  bool bVar2;

  undefined4 uVar3;

  int iVar4;

  undefined1 local_80 [128];

  

  if (((DAT_005def80 != 5) || (DAT_00632f44 != 0)) && (DAT_00632f08 == 2)) {

    comm_0051a130(s_GameTeam_0055a034,param_1);

  }

  if (DAT_005def8c == 0) {

    return;

  }

  main_dlog_00427230(DAT_005def8c,0x130);

  FUN_00542f27(local_80,s_GameTeam_s_0057dfbc,(&PTR_PTR_0057dc54)[param_1]);

  uVar3 = TextGetPtrQ(local_80);

  main_dlog_00427890(DAT_005def8c,0x130,DAT_0057dc9c,0x41300000,0x81000002,uVar3);

  iVar4 = comm_00426540();

  if (iVar4 == 0) {

    if (((DAT_005def80 == 5) && (DAT_00632f44 == 0)) || (DAT_00632f08 != 2)) {

      bVar1 = 0;

    }

    else {

      bVar1 = 1;

    }

    iVar4 = (-(uint)bVar1 & 0x282792) + 0xa0a0a0;

  }

  else {

    iVar4 = 0xa0a0a0;

  }

  comm_00427860(DAT_005def8c,0x130,iVar4);

  iVar4 = FUN_00525140(DAT_00632f14,DAT_00632f14);

  if (iVar4 == 0) {

    if ((DAT_00632f10 == 0) || ((1 < DAT_00632f10 && (DAT_00632f10 < 5)))) {

      bVar2 = true;

    }

    else {

      bVar2 = false;

    }

    iVar4 = 0;

    DAT_00632f14 = !bVar2 + 1;

    if (0 < DAT_00632f34) {

      do {

        if ((&DAT_005ddf60)[iVar4] == DAT_005def5c) {

          if (iVar4 < DAT_00632f34) goto LAB_00521787;

          break;

        }

        iVar4 = iVar4 + 1;

      } while (iVar4 < DAT_00632f34);

    }

    iVar4 = DAT_00632f34 + -1;

LAB_00521787:

    FUN_0052EF00(iVar4,DAT_00632f14);

  }

  comm_team_status();

  return;

}

/* ===== comm_worldname_menu @ 0x005217B0 ===== */
undefined4 comm_worldname_menu(undefined4 param_1,char *param_2)



{

  char cVar1;

  int iVar2;

  char *pcVar3;

  undefined1 local_28 [40];

  

  iVar2 = FUN_004B09C0(param_1);

  if (iVar2 == 0) {

    pcVar3 = (char *)FUN_00507b00(s_WN_None_0057dddc);

    do {

      cVar1 = *pcVar3;

      pcVar3 = pcVar3 + 1;

      *param_2 = cVar1;

      param_2 = param_2 + 1;

    } while (cVar1 != '\0');

    return 0;

  }

  FUN_00542f27(local_28,&DAT_0055bfe4,*(undefined4 *)(iVar2 + 4));

  pcVar3 = (char *)FUN_00507b00(local_28);

  do {

    cVar1 = *pcVar3;

    pcVar3 = pcVar3 + 1;

    *param_2 = cVar1;

    param_2 = param_2 + 1;

  } while (cVar1 != '\0');

  return 1;

}

/* ===== comm_worldname_menu2 @ 0x00521830 ===== */
void comm_worldname_menu2(int param_1)



{

  char cVar1;

  byte bVar2;

  int iVar3;

  char *pcVar4;

  char *pcVar5;

  undefined4 uVar6;

  undefined1 local_78 [40];

  char local_50 [80];

  

  uVar6 = 0x81000002;

  if (DAT_005def8c != 0) {

    iVar3 = FUN_004B09C0(param_1);

    if (iVar3 == 0) {

      pcVar4 = (char *)FUN_00507b00(s_WN_None_0057dddc);

      pcVar5 = local_50;

      do {

        cVar1 = *pcVar4;

        pcVar4 = pcVar4 + 1;

        *pcVar5 = cVar1;

        pcVar5 = pcVar5 + 1;

      } while (cVar1 != '\0');

      uVar6 = 0x8100000a;

    }

    else {

      FUN_00542f27(local_78,&DAT_0055bfe4,*(undefined4 *)(iVar3 + 4));

      pcVar4 = (char *)FUN_00507b00(local_78);

      pcVar5 = local_50;

      do {

        cVar1 = *pcVar4;

        pcVar4 = pcVar4 + 1;

        *pcVar5 = cVar1;

        pcVar5 = pcVar5 + 1;

      } while (cVar1 != '\0');

    }

    main_dlog_00427230(DAT_005def8c,0x134);

    main_dlog_00427890(DAT_005def8c,0x134,DAT_0057dc9c,0x41400000,uVar6,local_50);

    iVar3 = comm_00426540();

    if (iVar3 == 0) {

      if (((DAT_005def80 == 5) && (DAT_00632f44 == 0)) || (DAT_00632f08 != 2)) {

        bVar2 = 0;

      }

      else {

        bVar2 = 1;

      }

      iVar3 = (-(uint)bVar2 & 0x282792) + 0xa0a0a0;

    }

    else {

      iVar3 = 0xa0a0a0;

    }

    comm_00427860(DAT_005def8c,0x134,iVar3);

    if (((param_1 < 0) && (DAT_005def8c != 0)) && (DAT_005de67c != 0)) {

      DAT_005de67c = 0;

      main_dlog_00427230(DAT_005def8c,1);

    }

  }

  return;

}

/* ===== FUN_00521980 @ 0x00521980 ===== */
void FUN_00521980(int *param_1)



{

  int iVar1;

  int iVar2;

  int iVar3;

  

  iVar1 = FUN_004B0B40();

  iVar3 = 0;

  if (-1 < iVar1) {

    do {

      iVar2 = FUN_004B0900(iVar3,DAT_00632f10,DAT_00632f44);

      if (iVar2 != 0) {

        *param_1 = iVar3;

        return;

      }

      iVar3 = iVar3 + 1;

    } while (iVar3 <= iVar1);

  }

  *param_1 = -1;

  return;

}

/* ===== comm_team_name @ 0x005219D0 ===== */
void comm_team_name(int param_1,int param_2,int param_3)



{

  int iVar1;

  char *pcVar2;

  undefined4 uVar3;

  undefined1 local_28 [40];

  

  if ((param_1 == -1) && (param_1 = DAT_005ddfb8, DAT_005ddfb8 == -1)) {

    return;

  }

  if (((&DAT_005ddc98)[param_1] == 0) && (DAT_00633238 != 0)) {

    return;

  }

  if (DAT_005def8c == 0) {

    return;

  }

  iVar1 = param_1 + 100;

  main_dlog_00427230(DAT_005def8c,iVar1);

  switch(DAT_00632f10) {

  case 0:

  case 1:

    pcVar2 = s_CommTeamNo_d_0057dfe4;

    break;

  case 2:

  case 3:

  case 4:

  case 5:

    pcVar2 = s_CommTeamNo_dA_0057dfd4;

    break;

  default:

    goto switchD_00521a33_default;

  }

  FUN_00542f27(local_28,pcVar2,param_2);

switchD_00521a33_default:

  pcVar2 = (char *)FUN_00507b00(local_28);

  uVar3 = 0x81000002;

  if (*pcVar2 == '?') {

    uVar3 = 0x8100000a;

  }

  main_dlog_00427890(DAT_005def8c,iVar1,0x3f028f5c,(float)param_1 + 13.0,uVar3,pcVar2);

  if (param_3 == 0) {

    if (param_2 == 1) {

      param_3 = 0x70ff;

    }

    else if (param_2 == 2) {

      param_3 = 0x20ff20;

    }

    else {

      param_3 = ((param_2 != 3) - 1 & 0xffff3051) + 0xffffff;

    }

  }

  comm_00427860(DAT_005def8c,iVar1,param_3);

  if (param_1 == DAT_005ddfb8) {

    comm_0051a130(s_PlayerTeam_0055a040,param_2);

  }

  return;

}

/* ===== comm_maxplayers_dlog @ 0x00521B40 ===== */
void comm_maxplayers_dlog(undefined4 param_1)



{

  undefined4 uVar1;

  undefined1 local_28 [40];

  

  if (((DAT_005def80 != 5) || (DAT_00632f44 != 0)) && (1 < DAT_00632f08)) {

    comm_0051a130(s_MaxPlayers_00559f9c,param_1);

  }

  if (DAT_005def8c != 0) {

    FUN_00542f27(local_28,&DAT_00557088,param_1);

    main_dlog_00427230(DAT_005def8c,400);

    main_dlog_00427890(DAT_005def8c,400,DAT_0057dc98,0x41700000,0x81000002,local_28);

    if (((DAT_005def80 == 5) && (DAT_00632f44 == 0)) ||

       ((DAT_00632f08 < 2 || (uVar1 = 0xc8c832, DAT_00633238 != 0)))) {

      uVar1 = 0xa0a0a0;

    }

    comm_00427860(DAT_005def8c,400,uVar1);

  }

  return;

}

/* ===== comm_allowjoiners_menu @ 0x00521C20 ===== */
void comm_allowjoiners_menu(int param_1,int param_2)



{

  char *pcVar1;

  undefined4 uVar2;

  

  if (((DAT_005def80 != 5) || (DAT_00632f44 != 0)) && (1 < DAT_00632f08)) {

    comm_0051a130(s_AllowJoiners_00559ffc,param_1);

  }

  if (DAT_005def8c != 0) {

    pcVar1 = s_ButtonYes_0057df7c;

    if (param_1 == 0) {

      pcVar1 = s_ButtonNo_0057df70;

    }

    uVar2 = FUN_00507b00(pcVar1);

    main_dlog_00427230(DAT_005def8c,0x192);

    main_dlog_00427890(DAT_005def8c,0x192,DAT_0057dc98,0x41800000,0x81000002,uVar2);

    if (((DAT_005def80 == 5) && (DAT_00632f44 == 0)) ||

       ((DAT_00632f08 < 2 || (uVar2 = 0xc8c832, param_2 == 0)))) {

      uVar2 = 0xa0a0a0;

    }

    comm_00427860(DAT_005def8c,0x192,uVar2);

  }

  return;

}

/* ===== comm_damagemates_menu @ 0x00521CF0 ===== */
void comm_damagemates_menu(int param_1)



{

  char *pcVar1;

  undefined4 uVar2;

  

  if (((DAT_005def80 != 5) || (DAT_00632f44 != 0)) && (1 < DAT_00632f08)) {

    comm_0051a130(s_DamageTeammates_00559fec,param_1);

  }

  if (DAT_005def8c != 0) {

    pcVar1 = s_ButtonYes_0057df7c;

    if (param_1 == 0) {

      pcVar1 = s_ButtonNo_0057df70;

    }

    uVar2 = FUN_00507b00(pcVar1);

    main_dlog_00427230(DAT_005def8c,0x194);

    main_dlog_00427890(DAT_005def8c,0x194,DAT_0057dc98,0x41900000,0x81000002,uVar2);

    if ((((DAT_005def80 == 5) && (DAT_00632f44 == 0)) || (DAT_00632f08 < 2)) &&

       ((DAT_005def94 != DAT_005def5c || (DAT_00632f08 < 2)))) {

      uVar2 = 0xa0a0a0;

    }

    else {

      uVar2 = 0xc8c832;

    }

    comm_00427860(DAT_005def8c,0x194,uVar2);

  }

  return;

}

/* ===== comm_capture_points_menu @ 0x00521DD0 ===== */
void comm_capture_points_menu(int param_1,int param_2)



{

  char cVar1;

  char *pcVar2;

  undefined4 uVar3;

  char *pcVar4;

  char local_28 [40];

  

  if (((DAT_005def80 != 5) || (DAT_00632f44 != 0)) && (1 < DAT_00632f08)) {

    comm_0051a130(s_PointsPerCapture_00559fbc,param_1);

  }

  if (DAT_005def8c != 0) {

    if (param_1 == 0) {

      pcVar2 = (char *)FUN_00507b00(s_ButtonNone_0057df64);

      pcVar4 = local_28;

      do {

        cVar1 = *pcVar2;

        pcVar2 = pcVar2 + 1;

        *pcVar4 = cVar1;

        pcVar4 = pcVar4 + 1;

      } while (cVar1 != '\0');

    }

    else {

      FUN_00542f27(local_28,&DAT_00557088,param_1);

    }

    main_dlog_00427230(DAT_005def8c,0x198);

    main_dlog_00427890(DAT_005def8c,0x198,DAT_0057dc98,0x41a00000,0x81000002,local_28);

    if (((DAT_005def80 == 5) && (DAT_00632f44 == 0)) ||

       ((DAT_00632f08 < 2 || (uVar3 = 0xc8c832, param_2 == 0)))) {

      uVar3 = 0xa0a0a0;

    }

    comm_00427860(DAT_005def8c,0x198,uVar3);

  }

  return;

}

/* ===== comm_capture_time_menu @ 0x00521ED0 ===== */
void comm_capture_time_menu(int param_1,int param_2)



{

  char cVar1;

  char *pcVar2;

  undefined4 uVar3;

  char *pcVar4;

  char local_28 [40];

  

  if (((DAT_005def80 != 5) || (DAT_00632f44 != 0)) && (1 < DAT_00632f08)) {

    comm_0051a130(s_CapturePreventTime_00559fa8,param_1);

  }

  if (DAT_005def8c != 0) {

    if (param_1 == 0) {

      pcVar2 = (char *)FUN_00507b00(s_ButtonNone_0057df64);

      pcVar4 = local_28;

      do {

        cVar1 = *pcVar2;

        pcVar2 = pcVar2 + 1;

        *pcVar4 = cVar1;

        pcVar4 = pcVar4 + 1;

      } while (cVar1 != '\0');

    }

    else {

      comm_004ce880(param_1 * 0x3c,local_28);

    }

    main_dlog_00427230(DAT_005def8c,0x19a);

    main_dlog_00427890(DAT_005def8c,0x19a,DAT_0057dc98,0x41a80000,0x81000002,local_28);

    if (((((DAT_005def80 == 5) && (DAT_00632f44 == 0)) || (DAT_00632f08 < 2)) &&

        ((DAT_005def94 != DAT_005def5c || (DAT_00632f08 < 2)))) || (uVar3 = 0xc8c832, param_2 == 0))

    {

      uVar3 = 0xa0a0a0;

    }

    comm_00427860(DAT_005def8c,0x19a,uVar3);

  }

  return;

}

/* ===== comm_smartie_diff_dlog @ 0x00522020 ===== */
void comm_smartie_diff_dlog(int param_1)



{

  byte bVar1;

  undefined4 uVar2;

  undefined1 local_28 [40];

  

  if (((DAT_005def80 != 5) || (DAT_00632f44 != 0)) && (1 < DAT_00632f08)) {

    comm_0051a130(s_SmartieDifficulty_00559f88,param_1);

  }

  if (DAT_005def8c != 0) {

    if (param_1 == 0) {

      uVar2 = *(undefined4 *)(DAT_00632ed8 + 0x11f4);

    }

    else if (param_1 == 1) {

      uVar2 = *(undefined4 *)(DAT_00632ed8 + 0x11f8);

    }

    else {

      uVar2 = *(undefined4 *)(DAT_00632ed8 + 0x11fc);

    }

    FUN_00542f27(local_28,&DAT_00557088,uVar2);

    main_dlog_00427230(DAT_005def8c,0x1a0);

    main_dlog_00427890(DAT_005def8c,0x1a0,DAT_0057dc98,0x41b00000,0x81000002,local_28);

    if (((DAT_005def80 == 5) && (DAT_00632f44 == 0)) || (DAT_00632f08 < 2)) {

      bVar1 = 0;

    }

    else {

      bVar1 = 1;

    }

    comm_00427860(DAT_005def8c,0x1a0,(-(uint)bVar1 & 0x282792) + 0xa0a0a0);

  }

  return;

}

/* ===== FUN_00522130 @ 0x00522130 ===== */
/* PS2 candidate: kbos_food_value__Fi (conf 0.7) */



float10 FUN_00522130(int param_1)



{

  if (param_1 == 0) {

    return (float10)*(float *)(DAT_00632ed8 + 0x1200);

  }

  if (param_1 != 1) {

    return (float10)*(float *)(DAT_00632ed8 + 0x1208);

  }

  return (float10)*(float *)(DAT_00632ed8 + 0x1204);

}

/* ===== comm_difficulty_menu @ 0x00522170 ===== */
void comm_difficulty_menu(int param_1)



{

  byte bVar1;

  undefined4 uVar2;

  char *pcVar3;

  

  if (((DAT_005def80 != 5) || (DAT_00632f44 != 0)) && (1 < DAT_00632f08)) {

    comm_0051a130(s_VimpMeatDifficulty_00559f74,param_1);

  }

  if (DAT_005def8c != 0) {

    if (param_1 == 0) {

      pcVar3 = s_CommDiffEasy_0057dff4;

    }

    else if (param_1 == 1) {

      pcVar3 = s_CommDiffMedium_0057e004;

    }

    else {

      pcVar3 = s_CommDiffHard_0057e014;

    }

    uVar2 = FUN_00507b00(pcVar3);

    main_dlog_00427230(DAT_005def8c,0x1a2);

    main_dlog_00427890(DAT_005def8c,0x1a2,DAT_0057dc98,0x41b80000,0x81000002,uVar2);

    if (((DAT_005def80 == 5) && (DAT_00632f44 == 0)) || (DAT_00632f08 < 2)) {

      bVar1 = 0;

    }

    else {

      bVar1 = 1;

    }

    comm_00427860(DAT_005def8c,0x1a2,(-(uint)bVar1 & 0x282792) + 0xa0a0a0);

  }

  return;

}

/* ===== comm_timelimit_dlog @ 0x00522260 ===== */
void comm_timelimit_dlog(int param_1)



{

  char cVar1;

  byte bVar2;

  char *pcVar3;

  char *pcVar4;

  char local_28 [40];

  

  if (((DAT_005def80 != 5) || (DAT_00632f44 != 0)) && (1 < DAT_00632f08)) {

    comm_0051a130(s_TimeLimit_00559f68,param_1);

  }

  if (DAT_005def8c != 0) {

    if (param_1 == 0) {

      pcVar3 = (char *)FUN_00507b00(s_ButtonNone_0057df64);

      pcVar4 = local_28;

      do {

        cVar1 = *pcVar3;

        pcVar3 = pcVar3 + 1;

        *pcVar4 = cVar1;

        pcVar4 = pcVar4 + 1;

      } while (cVar1 != '\0');

    }

    else {

      comm_004ce880(param_1 * 0x3c,local_28);

    }

    main_dlog_00427230(DAT_005def8c,500);

    main_dlog_00427890(DAT_005def8c,500,DAT_0057dc98,0x41d00000,0x81000002,local_28);

    if (((DAT_005def80 == 5) && (DAT_00632f44 == 0)) || (DAT_00632f08 < 2)) {

      bVar2 = 0;

    }

    else {

      bVar2 = 1;

    }

    comm_00427860(DAT_005def8c,500,(-(uint)bVar2 & 0x282792) + 0xa0a0a0);

  }

  return;

}

/* ===== comm_playerscore_menu @ 0x00522360 ===== */
void comm_playerscore_menu(int param_1)



{

  char cVar1;

  byte bVar2;

  char *pcVar3;

  char *pcVar4;

  char local_28 [40];

  

  if (((DAT_005def80 != 5) || (DAT_00632f44 != 0)) && (1 < DAT_00632f08)) {

    comm_0051a130(s_PlayerScoreLimit_00559f54,param_1);

  }

  if (DAT_005def8c != 0) {

    if (param_1 == 0) {

      pcVar3 = (char *)FUN_00507b00(s_ButtonNone_0057df64);

      pcVar4 = local_28;

      do {

        cVar1 = *pcVar3;

        pcVar3 = pcVar3 + 1;

        *pcVar4 = cVar1;

        pcVar4 = pcVar4 + 1;

      } while (cVar1 != '\0');

    }

    else {

      FUN_00542f27(local_28,&DAT_00557088,param_1);

    }

    main_dlog_00427230(DAT_005def8c,0x1f6);

    main_dlog_00427890(DAT_005def8c,0x1f6,DAT_0057dc98,0x41e00000,0x81000002,local_28);

    if (((DAT_005def80 == 5) && (DAT_00632f44 == 0)) || (DAT_00632f08 < 2)) {

      bVar2 = 0;

    }

    else {

      bVar2 = 1;

    }

    comm_00427860(DAT_005def8c,0x1f6,(-(uint)bVar2 & 0x282792) + 0xa0a0a0);

  }

  return;

}

/* ===== comm_teamscore_menu @ 0x00522470 ===== */
void comm_teamscore_menu(int param_1)



{

  char cVar1;

  byte bVar2;

  char *pcVar3;

  char *pcVar4;

  char local_28 [40];

  

  if (((DAT_005def80 != 5) || (DAT_00632f44 != 0)) && (1 < DAT_00632f08)) {

    comm_0051a130(s_TeamScoreLimit_00559f44,param_1);

  }

  if (DAT_005def8c != 0) {

    if (param_1 == 0) {

      pcVar3 = (char *)FUN_00507b00(s_ButtonNone_0057df64);

      pcVar4 = local_28;

      do {

        cVar1 = *pcVar3;

        pcVar3 = pcVar3 + 1;

        *pcVar4 = cVar1;

        pcVar4 = pcVar4 + 1;

      } while (cVar1 != '\0');

    }

    else {

      FUN_00542f27(local_28,&DAT_00557088,param_1);

    }

    main_dlog_00427230(DAT_005def8c,0x1f8);

    main_dlog_00427890(DAT_005def8c,0x1f8,DAT_0057dc98,0x41e80000,0x81000002,local_28);

    if (((DAT_005def80 == 5) && (DAT_00632f44 == 0)) || (DAT_00632f08 < 2)) {

      bVar2 = 0;

    }

    else {

      bVar2 = 1;

    }

    comm_00427860(DAT_005def8c,0x1f8,(-(uint)bVar2 & 0x282792) + 0xa0a0a0);

  }

  return;

}

/* ===== comm_base_status_menu @ 0x00522580 ===== */
void comm_base_status_menu(int param_1,int param_2)



{

  char *pcVar1;

  undefined4 uVar2;

  

  if (((DAT_005def80 != 5) || (DAT_00632f44 != 0)) && (1 < DAT_00632f08)) {

    comm_0051a130(s__BaseComplete_00559f33 + 1,param_1);

  }

  if (DAT_005def8c != 0) {

    pcVar1 = s_ButtonYes_0057df7c;

    if (param_1 == 0) {

      pcVar1 = s_ButtonNo_0057df70;

    }

    uVar2 = FUN_00507b00(pcVar1);

    main_dlog_00427230(DAT_005def8c,0x1fa);

    main_dlog_00427890(DAT_005def8c,0x1fa,DAT_0057dc98,0x41f00000,0x81000002,uVar2);

    if (((DAT_005def80 == 5) && (DAT_00632f44 == 0)) ||

       ((DAT_00632f08 < 2 || (uVar2 = 0xc8c832, param_2 == 0)))) {

      uVar2 = 0xa0a0a0;

    }

    comm_00427860(DAT_005def8c,0x1fa,uVar2);

    main_dlog_00427230(DAT_005def8c,0x1fb);

    if ((DAT_00632f18 == 6) || (DAT_00632f18 == 7)) {

      pcVar1 = s_CommShowConnLBaseDestroyed_0057e040;

    }

    else {

      pcVar1 = s_CommShowConnLBaseComplete_0057e024;

    }

    uVar2 = TextGetPtrQ(pcVar1);

    main_dlog_00427890(DAT_005def8c,0x1fb,DAT_0057dc98 - 0.01,0x41f00000,0x85000002,uVar2);

  }

  return;

}

/* ===== comm_gametype_pop @ 0x005226B0 ===== */
void comm_gametype_pop(void)



{

  if (DAT_005def8c != 0) {

    if ((((DAT_005def80 == 5) && (DAT_00632f44 == 0)) || (DAT_00632f08 < 0xe)) &&

       ((DAT_005def94 != DAT_005def5c || (DAT_00632f08 < 0xe)))) {

      comm_00427860(DAT_005def8c,0x1fd,0xa0a0a0);

      return;

    }

    comm_00427860(DAT_005def8c,0x1fd,0xc8c832);

  }

  return;

}

/* ===== comm_version_check @ 0x00522720 ===== */
void comm_version_check(int param_1)



{

  undefined4 uVar1;

  undefined1 local_28 [40];

  

  if (DAT_005def8c != 0) {

    uVar1 = FUN_00507b00(s_CommVersion_0057e068,(double)((float)param_1 * 0.001));

    FUN_00542f27(local_28,s__s___1_3f_0057e05c,uVar1);

    main_dlog_00427230(DAT_005def8c,0x1a4);

    main_dlog_00427890(DAT_005def8c,0x1a4,0x3f7d70a4,0xbf800000,0x85000000,local_28);

    comm_00427860(DAT_005def8c,0x1a4,0x8fffff);

  }

  return;

}

/* ===== comm_scorelimit_menu @ 0x005227B0 ===== */
void comm_scorelimit_menu(uint *param_1,uint *param_2,undefined4 param_3)



{

  char cVar1;

  uint uVar2;

  byte bVar3;

  char *pcVar4;

  char *pcVar5;

  char local_28 [40];

  

  switch(param_3) {

  case 0:

    uVar2 = param_2[3];

    if (param_1[3] != uVar2) {

      if (((DAT_005def80 != 5) || (DAT_00632f44 != 0)) && (1 < DAT_00632f08)) {

        comm_0051a130(s_TimeLimit_00559f68,uVar2);

      }

      if (DAT_005def8c != 0) {

        if (uVar2 == 0) {

          pcVar4 = (char *)FUN_00507b00(s_ButtonNone_0057df64);

          pcVar5 = local_28;

          do {

            cVar1 = *pcVar4;

            pcVar4 = pcVar4 + 1;

            *pcVar5 = cVar1;

            pcVar5 = pcVar5 + 1;

          } while (cVar1 != '\0');

        }

        else {

          comm_004ce880(uVar2 * 0x3c,local_28);

        }

        main_dlog_00427230(DAT_005def8c,500);

        main_dlog_00427890(DAT_005def8c,500,DAT_0057dc98,0x41d00000,0x81000002,local_28);

        if (((DAT_005def80 == 5) && (DAT_00632f44 == 0)) || (DAT_00632f08 < 2)) {

          bVar3 = 0;

        }

        else {

          bVar3 = 1;

        }

        comm_00427860(DAT_005def8c,500,(-(uint)bVar3 & 0x282792) + 0xa0a0a0);

      }

    }

    *param_2 = (uint)(0 < (int)param_2[3]);

    return;

  case 1:

    uVar2 = param_2[3];

    if (param_1[3] != uVar2) {

      if (((DAT_005def80 != 5) || (DAT_00632f44 != 0)) && (1 < DAT_00632f08)) {

        comm_0051a130(s_PlayerScoreLimit_00559f54,uVar2);

      }

      if (DAT_005def8c != 0) {

        if (uVar2 == 0) {

          pcVar4 = (char *)FUN_00507b00(s_ButtonNone_0057df64);

          pcVar5 = local_28;

          do {

            cVar1 = *pcVar4;

            pcVar4 = pcVar4 + 1;

            *pcVar5 = cVar1;

            pcVar5 = pcVar5 + 1;

          } while (cVar1 != '\0');

        }

        else {

          FUN_00542f27(local_28,&DAT_00557088,uVar2);

        }

        main_dlog_00427230(DAT_005def8c,0x1f6);

        main_dlog_00427890(DAT_005def8c,0x1f6,DAT_0057dc98,0x41e00000,0x81000002,local_28);

        if (((DAT_005def80 == 5) && (DAT_00632f44 == 0)) || (DAT_00632f08 < 2)) {

          bVar3 = 0;

        }

        else {

          bVar3 = 1;

        }

        comm_00427860(DAT_005def8c,0x1f6,(-(uint)bVar3 & 0x282792) + 0xa0a0a0);

      }

    }

    *param_2 = (uint)(0 < (int)param_2[3]);

    return;

  case 2:

    uVar2 = param_2[3];

    if (param_1[3] != uVar2) {

      if (((DAT_005def80 != 5) || (DAT_00632f44 != 0)) && (1 < DAT_00632f08)) {

        comm_0051a130(s_TeamScoreLimit_00559f44,uVar2);

      }

      if (DAT_005def8c != 0) {

        if (uVar2 == 0) {

          pcVar4 = (char *)FUN_00507b00(s_ButtonNone_0057df64);

          pcVar5 = local_28;

          do {

            cVar1 = *pcVar4;

            pcVar4 = pcVar4 + 1;

            *pcVar5 = cVar1;

            pcVar5 = pcVar5 + 1;

          } while (cVar1 != '\0');

        }

        else {

          FUN_00542f27(local_28,&DAT_00557088,uVar2);

        }

        main_dlog_00427230(DAT_005def8c,0x1f8);

        main_dlog_00427890(DAT_005def8c,0x1f8,DAT_0057dc98,0x41e80000,0x81000002,local_28);

        if (((DAT_005def80 == 5) && (DAT_00632f44 == 0)) || (DAT_00632f08 < 2)) {

          bVar3 = 0;

        }

        else {

          bVar3 = 1;

        }

        comm_00427860(DAT_005def8c,0x1f8,(-(uint)bVar3 & 0x282792) + 0xa0a0a0);

      }

    }

    *param_2 = (uint)(0 < (int)param_2[3]);

    return;

  case 3:

    uVar2 = *param_2;

    if (*param_1 != uVar2) {

      if ((((DAT_00632f18 != 4) && (DAT_00632f18 != 5)) && (DAT_00632f18 != 6)) &&

         (DAT_00632f18 != 7)) {

        comm_base_status_menu(uVar2,0);

        return;

      }

      comm_base_status_menu(uVar2,1);

    }

  }

  return;

}

/* ===== comm_game_setup_menu @ 0x00522B80 ===== */
void comm_game_setup_menu(void)



{

  char cVar1;

  byte bVar2;

  bool bVar3;

  char *pcVar4;

  int iVar5;

  int iVar6;

  char *pcVar7;

  undefined4 uVar8;

  char local_80 [128];

  

  if (DAT_005def8c != 0) {

    main_dlog_00427230(DAT_005def8c,300);

    pcVar4 = &DAT_00632f48;

    if (DAT_00632f48 == '\0') {

      pcVar4 = s__None__0057dfac;

    }

    main_dlog_00427890(DAT_005def8c,300,DAT_0057dc9c,0x41100000,0x81000002,pcVar4);

    iVar5 = comm_00426540();

    if (iVar5 == 0) {

      if (((DAT_005def80 == 5) && (DAT_00632f44 == 0)) || (DAT_00632f08 != 2)) {

        bVar2 = 0;

      }

      else {

        bVar2 = 1;

      }

      iVar5 = (-(uint)bVar2 & 0x282792) + 0xa0a0a0;

    }

    else {

      iVar5 = 0xa0a0a0;

    }

    comm_00427860(DAT_005def8c,300,iVar5);

    iVar5 = DAT_00632f18;

    if (((DAT_005def80 != 5) || (DAT_00632f44 != 0)) && (DAT_00632f08 == 2)) {

      comm_0051a130(s_GameType_0055a00c,DAT_00632f18);

    }

    if (DAT_005def8c != 0) {

      main_dlog_00427230(DAT_005def8c,0x12e);

      comm_gtype_name(iVar5,local_80);

      main_dlog_00427890(DAT_005def8c,0x12e,DAT_0057dc9c,0x41200000,0x81000002,local_80);

      iVar5 = comm_00426540();

      if (iVar5 == 0) {

        if (((DAT_005def80 == 5) && (DAT_00632f44 == 0)) || (DAT_00632f08 != 2)) {

          bVar2 = 0;

        }

        else {

          bVar2 = 1;

        }

        iVar5 = (-(uint)bVar2 & 0x282792) + 0xa0a0a0;

      }

      else {

        iVar5 = 0xa0a0a0;

      }

      comm_00427860(DAT_005def8c,0x12e,iVar5);

    }

    comm_00521620(DAT_00632f10);

    iVar5 = DAT_00632ee4;

    uVar8 = 0x81000002;

    if (DAT_005def8c != 0) {

      iVar6 = comm_worldname_menu(DAT_00632ee4,local_80);

      if (iVar6 == 0) {

        uVar8 = 0x8100000a;

      }

      main_dlog_00427230(DAT_005def8c,0x134);

      main_dlog_00427890(DAT_005def8c,0x134,DAT_0057dc9c,0x41400000,uVar8,local_80);

      iVar6 = comm_00426540();

      if (iVar6 == 0) {

        if (((DAT_005def80 == 5) && (DAT_00632f44 == 0)) || (DAT_00632f08 != 2)) {

          bVar2 = 0;

        }

        else {

          bVar2 = 1;

        }

        iVar6 = (-(uint)bVar2 & 0x282792) + 0xa0a0a0;

      }

      else {

        iVar6 = 0xa0a0a0;

      }

      comm_00427860(DAT_005def8c,0x134,iVar6);

      if (((iVar5 < 0) && (DAT_005def8c != 0)) && (DAT_005de67c != 0)) {

        DAT_005de67c = 0;

        main_dlog_00427230(DAT_005def8c,1);

      }

    }

    uVar8 = DAT_00632f34;

    if (((DAT_005def80 != 5) || (DAT_00632f44 != 0)) && (1 < DAT_00632f08)) {

      comm_0051a130(s_MaxPlayers_00559f9c,DAT_00632f34);

    }

    if (DAT_005def8c != 0) {

      FUN_00542f27(local_80,&DAT_00557088,uVar8);

      main_dlog_00427230(DAT_005def8c,400);

      main_dlog_00427890(DAT_005def8c,400,DAT_0057dc98,0x41700000,0x81000002,local_80);

      if ((((DAT_005def80 == 5) && (DAT_00632f44 == 0)) || (DAT_00632f08 < 2)) ||

         (uVar8 = 0xc8c832, DAT_00633238 != 0)) {

        uVar8 = 0xa0a0a0;

      }

      comm_00427860(DAT_005def8c,400,uVar8);

    }

    iVar5 = DAT_00632f1c;

    if (((DAT_00632f18 < 0) || (3 < DAT_00632f18)) && ((DAT_00632f18 < 6 || (7 < DAT_00632f18)))) {

      bVar3 = false;

    }

    else {

      bVar3 = true;

    }

    if (((DAT_005def80 != 5) || (DAT_00632f44 != 0)) && (1 < DAT_00632f08)) {

      comm_0051a130(s_AllowJoiners_00559ffc,DAT_00632f1c);

    }

    if (DAT_005def8c != 0) {

      pcVar4 = s_ButtonYes_0057df7c;

      if (iVar5 == 0) {

        pcVar4 = s_ButtonNo_0057df70;

      }

      uVar8 = FUN_00507b00(pcVar4);

      main_dlog_00427230(DAT_005def8c,0x192);

      main_dlog_00427890(DAT_005def8c,0x192,DAT_0057dc98,0x41800000,0x81000002,uVar8);

      if ((((DAT_005def80 == 5) && (DAT_00632f44 == 0)) || (DAT_00632f08 < 2)) ||

         (uVar8 = 0xc8c832, !bVar3)) {

        uVar8 = 0xa0a0a0;

      }

      comm_00427860(DAT_005def8c,0x192,uVar8);

    }

    iVar5 = DAT_00632f38;

    if (((DAT_005def80 != 5) || (DAT_00632f44 != 0)) && (1 < DAT_00632f08)) {

      comm_0051a130(s_LockTeams_00559fe0,DAT_00632f38);

    }

    if (DAT_005def8c != 0) {

      pcVar4 = s_ButtonNo_0057df70;

      if (iVar5 == 0) {

        pcVar4 = s_ButtonYes_0057df7c;

      }

      uVar8 = FUN_00507b00(pcVar4);

      main_dlog_00427230(DAT_005def8c,0x19e);

      main_dlog_00427890(DAT_005def8c,0x19e,DAT_0057dc98,0x41880000,0x81000002,uVar8);

      if (((DAT_005def80 == 5) && (DAT_00632f44 == 0)) || (DAT_00632f08 < 2)) {

        bVar2 = 0;

      }

      else {

        bVar2 = 1;

      }

      comm_00427860(DAT_005def8c,0x19e,(-(uint)bVar2 & 0x282792) + 0xa0a0a0);

    }

    iVar5 = DAT_00632f20;

    if (((DAT_005def80 != 5) || (DAT_00632f44 != 0)) && (1 < DAT_00632f08)) {

      comm_0051a130(s_DamageTeammates_00559fec,DAT_00632f20);

    }

    if (DAT_005def8c != 0) {

      pcVar4 = s_ButtonYes_0057df7c;

      if (iVar5 == 0) {

        pcVar4 = s_ButtonNo_0057df70;

      }

      uVar8 = FUN_00507b00(pcVar4);

      main_dlog_00427230(DAT_005def8c,0x194);

      main_dlog_00427890(DAT_005def8c,0x194,DAT_0057dc98,0x41900000,0x81000002,uVar8);

      if ((((DAT_005def80 == 5) && (DAT_00632f44 == 0)) || (DAT_00632f08 < 2)) &&

         ((DAT_005def94 != DAT_005def5c || (DAT_00632f08 < 2)))) {

        uVar8 = 0xa0a0a0;

      }

      else {

        uVar8 = 0xc8c832;

      }

      comm_00427860(DAT_005def8c,0x194,uVar8);

    }

    iVar5 = DAT_00632f24;

    if (((DAT_005def80 != 5) || (DAT_00632f44 != 0)) && (1 < DAT_00632f08)) {

      comm_0051a130(s_PointsPerKill_00559fd0,DAT_00632f24);

    }

    if (DAT_005def8c != 0) {

      if (iVar5 == 0) {

        pcVar7 = (char *)FUN_00507b00(s_ButtonNone_0057df64);

        pcVar4 = local_80;

        do {

          cVar1 = *pcVar7;

          pcVar7 = pcVar7 + 1;

          *pcVar4 = cVar1;

          pcVar4 = pcVar4 + 1;

        } while (cVar1 != '\0');

      }

      else {

        FUN_00542f27(local_80,&DAT_00557088,iVar5);

      }

      main_dlog_00427230(DAT_005def8c,0x196);

      main_dlog_00427890(DAT_005def8c,0x196,DAT_0057dc98,0x41980000,0x81000002,local_80);

      if (((DAT_005def80 == 5) && (DAT_00632f44 == 0)) || (DAT_00632f08 < 2)) {

        bVar2 = 0;

      }

      else {

        bVar2 = 1;

      }

      comm_00427860(DAT_005def8c,0x196,(-(uint)bVar2 & 0x282792) + 0xa0a0a0);

    }

    if (((DAT_00632f18 == 2) || (DAT_00632f18 == 3)) || ((DAT_00632f18 == 5 || (DAT_00632f18 == 7)))

       ) {

      uVar8 = 1;

    }

    else {

      uVar8 = 0;

    }

    comm_capture_points_menu(DAT_00632f28,uVar8);

    comm_capture_time_menu(DAT_00632f2c,1);

    comm_smartie_diff_dlog(DAT_00632f3c);

    comm_difficulty_menu(DAT_00632f40);

    if (((DAT_005def80 == 5) && (DAT_00632f44 == 0)) || (DAT_00632f08 < 0xe)) {

      bVar2 = 0;

    }

    else {

      bVar2 = 1;

    }

    comm_00427860(DAT_005def8c,0x19d,(-(uint)bVar2 & 0x282792) + 0xa0a0a0);

    comm_timelimit_dlog(DAT_00632fcc);

    comm_playerscore_menu(DAT_00632fdc);

    comm_teamscore_menu(DAT_00632fec);

    if (((DAT_00632f18 == 4) || (DAT_00632f18 == 5)) || ((DAT_00632f18 == 6 || (DAT_00632f18 == 7)))

       ) {

      uVar8 = 1;

    }

    else {

      uVar8 = 0;

    }

    comm_base_status_menu(DAT_00632ff0,uVar8);

    comm_gametype_pop(DAT_00633000);

    iVar5 = FUN_004B09C0(DAT_00632ee4);

    if (iVar5 != 0) {

      iVar5 = FUN_004B0900(DAT_00632ee4,DAT_00632f10,DAT_00632f44);

      if (iVar5 == 0) {

        FUN_00521980(&DAT_00632ee4);

        comm_worldname_menu2(DAT_00632ee4);

        if (((DAT_00632ee4 < 0) && (DAT_005def8c != 0)) && (DAT_005de67c != 0)) {

          DAT_005de67c = 0;

          main_dlog_00427230(DAT_005def8c,1);

        }

      }

    }

    gamespy_statechange3();

    return;

  }

  return;

}

/* ===== comm_show_conn_menu @ 0x005233F0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void comm_show_conn_menu(void)



{

  char cVar1;

  byte bVar2;

  undefined4 uVar3;

  int iVar4;

  int iVar5;

  char *pcVar6;

  int iVar7;

  int iVar8;

  undefined4 *puVar9;

  undefined4 *puVar10;

  bool bVar11;

  char *pcVar12;

  char local_bc [60];

  char local_80 [128];

  

  pcVar12 = s_English_0057e354;

  uVar3 = __default_unexpected__Fv();

  iVar4 = FUN_00545650(uVar3,pcVar12);

  if (iVar4 != 0) {

    DAT_0057dc98 = 0.844;

    DAT_0057dc9c = 0.79;

  }

  iVar4 = 5;

  DAT_00632fb0 = 0;

  DAT_00632fb8 = &DAT_005ddb98;

  DAT_00632fb4 = 0x100;

  if (DAT_005def80 == 5) {

    if ((float)DAT_00632e88 < 480.0 != ((float)DAT_00632e88 == 480.0)) {

      win95_text_0051b160();

      win95_text_0051adb0();

    }

    dlog_push_level(&LAB_00525460,&LAB_00524d90);

    FUN_00426FA0();

    DAT_005def8c = main_dlog_00427150();

    uVar3 = TextGetPtrQ(s_CommShowConnTitle_0057e340);

    main_dlog_00427890(DAT_005def8c,5,0x3d3851ec,0x40666666,0x80000000,uVar3);

    uVar3 = TextGetPtrQ(s_CommShowConnHPlayers_0057e328);

    main_dlog_00427890(DAT_005def8c,0xb,0x3da3d70a,0x41400000,0x81000000,uVar3);

    uVar3 = TextGetPtrQ();

    main_dlog_00427890(DAT_005def8c,0xc,0x3e800000,0x41400000,0x81000000,uVar3);

    uVar3 = TextGetPtrQ(s_CommShowConnHPing_0057e300);

    main_dlog_00427890(DAT_005def8c,0xd,0x3ed70a3d,0x41400000,0x89000000,uVar3);

    uVar3 = TextGetPtrQ(s_CommShowConnHScore_0057e2ec);

    main_dlog_00427890(DAT_005def8c,0xe,0x3ef0a3d7,0x41400000,0x89000000,uVar3);

    uVar3 = TextGetPtrQ();

    main_dlog_00427890(DAT_005def8c,0xf,0x3f028f5c,0x41400000,0x81000000,uVar3);

    uVar3 = TextGetPtrQ(s_CommShowConnHTeams_0057e2c4);

    main_dlog_00427890(DAT_005def8c,7,0x3da3d70a,0x40e00000,0x81000000,uVar3);

    uVar3 = TextGetPtrQ(s_CommShowConnHCount_0057e2b0);

    main_dlog_00427890(DAT_005def8c,8,0x3e6147ae,0x40e00000,0x89000000,uVar3);

    uVar3 = TextGetPtrQ();

    main_dlog_00427890(DAT_005def8c,9,0x3e8f5c29,0x40e00000,0x89000000,uVar3);

    uVar3 = TextGetPtrQ(s_CommShowConnHDeaths_0057e29c);

    main_dlog_00427890(DAT_005def8c,10,0x3eae147b,0x40e00000,0x89000000,uVar3);

    uVar3 = TextGetPtrQ(s_CommShowConnHGame_0057e288);

    main_dlog_00427890(DAT_005def8c,0x10,0x3f4ccccd,0x40e00000,0x89000000,uVar3);

    uVar3 = TextGetPtrQ();

    main_dlog_00427890(DAT_005def8c,0x12d,DAT_0057dc9c - 0.01,0x41100000,0x85000002,uVar3);

    if (DAT_005def8c != 0) {

      main_dlog_00427230(DAT_005def8c,300);

      pcVar12 = &DAT_00632f48;

      if (DAT_00632f48 == '\0') {

        pcVar12 = s__None__0057dfac;

      }

      main_dlog_00427890(DAT_005def8c,300,DAT_0057dc9c,0x41100000,0x81000002,pcVar12);

      iVar5 = comm_00426540();

      if (iVar5 == 0) {

        if (((DAT_005def80 == 5) && (DAT_00632f44 == 0)) || (DAT_00632f08 != 2)) {

          bVar2 = 0;

        }

        else {

          bVar2 = 1;

        }

        iVar5 = (-(uint)bVar2 & 0x282792) + 0xa0a0a0;

      }

      else {

        iVar5 = 0xa0a0a0;

      }

      comm_00427860(DAT_005def8c,CONCAT44(iVar5,300));

    }

    uVar3 = TextGetPtrQ();

    main_dlog_00427890(DAT_005def8c,0x12f,DAT_0057dc9c - 0.01,0x41200000,0x85000002,uVar3);

    iVar5 = DAT_00632f18;

    if (((DAT_005def80 != 5) || (DAT_00632f44 != 0)) && (DAT_00632f08 == 2)) {

      comm_0051a130(s_GameType_0055a00c,DAT_00632f18);

    }

    if (DAT_005def8c != 0) {

      main_dlog_00427230(DAT_005def8c,0x12e);

      FUN_00542f27(local_bc,s_GType_s_0057dfb4,(&PTR_DAT_0057dc6c)[iVar5]);

      pcVar6 = (char *)FUN_00507b00(local_bc);

      pcVar12 = local_80;

      do {

        cVar1 = *pcVar6;

        pcVar6 = pcVar6 + 1;

        *pcVar12 = cVar1;

        pcVar12 = pcVar12 + 1;

      } while (cVar1 != '\0');

      main_dlog_00427890(DAT_005def8c,0x12e,DAT_0057dc9c,0x41200000,0x81000002,local_80);

      iVar5 = comm_00426540();

      if (iVar5 == 0) {

        if (((DAT_005def80 == 5) && (DAT_00632f44 == 0)) || (DAT_00632f08 != 2)) {

          bVar2 = 0;

        }

        else {

          bVar2 = 1;

        }

        iVar5 = (-(uint)bVar2 & 0x282792) + 0xa0a0a0;

      }

      else {

        iVar5 = 0xa0a0a0;

      }

      comm_00427860(DAT_005def8c,CONCAT44(iVar5,0x12e));

    }

    uVar3 = TextGetPtrQ();

    main_dlog_00427890(DAT_005def8c,0x131,DAT_0057dc9c - 0.01,0x41300000,0x85000002,uVar3);

    comm_00521620(DAT_00632f10);

    iVar5 = FUN_004B09C0(DAT_00632ee4);

    if (iVar5 == 0) {

      DAT_00632ee4 = 0x13;

    }

    iVar7 = FUN_004B09C0();

    iVar5 = DAT_00632ee4;

    if ((iVar7 != 0) &&

       (iVar7 = FUN_004B0900(DAT_00632ee4,DAT_00632f10,DAT_00632f44), iVar5 = DAT_00632ee4,

       iVar7 == 0)) {

      iVar7 = FUN_004B0B40();

      iVar5 = 0;

      if (-1 < iVar7) {

        do {

          iVar8 = FUN_004B0900(iVar5,DAT_00632f10,DAT_00632f44);

          if (iVar8 != 0) goto LAB_00523950;

          iVar5 = iVar5 + 1;

        } while (iVar5 <= iVar7);

      }

      DAT_00632ee4 = -1;

      iVar5 = DAT_00632ee4;

    }

LAB_00523950:

    DAT_00632ee4 = iVar5;

    uVar3 = TextGetPtrQ();

    main_dlog_00427890(DAT_005def8c,0x135,DAT_0057dc9c - 0.01,0x41400000,0x85000002,uVar3);

    iVar5 = DAT_00632ee4;

    uVar3 = 0x81000002;

    if (DAT_005def8c != 0) {

      iVar7 = FUN_004B09C0();

      if (iVar7 == 0) {

        pcVar6 = (char *)FUN_00507b00();

        pcVar12 = local_80;

        do {

          cVar1 = *pcVar6;

          pcVar6 = pcVar6 + 1;

          *pcVar12 = cVar1;

          pcVar12 = pcVar12 + 1;

        } while (cVar1 != '\0');

        uVar3 = 0x8100000a;

      }

      else {

        FUN_00542f27(local_bc,&DAT_0055bfe4,*(undefined4 *)(iVar7 + 4));

        pcVar6 = (char *)FUN_00507b00(local_bc);

        pcVar12 = local_80;

        do {

          cVar1 = *pcVar6;

          pcVar6 = pcVar6 + 1;

          *pcVar12 = cVar1;

          pcVar12 = pcVar12 + 1;

        } while (cVar1 != '\0');

      }

      main_dlog_00427230(DAT_005def8c,0x134);

      main_dlog_00427890(DAT_005def8c,0x134,DAT_0057dc9c,0x41400000,uVar3,local_80);

      iVar7 = comm_00426540();

      if (iVar7 == 0) {

        if (((DAT_005def80 == 5) && (DAT_00632f44 == 0)) || (DAT_00632f08 != 2)) {

          bVar2 = 0;

        }

        else {

          bVar2 = 1;

        }

        iVar7 = (-(uint)bVar2 & 0x282792) + 0xa0a0a0;

      }

      else {

        iVar7 = 0xa0a0a0;

      }

      comm_00427860(DAT_005def8c,CONCAT44(iVar7,0x134));

      if (((iVar5 < 0) && (DAT_005def8c != 0)) && (DAT_005de67c != 0)) {

        DAT_005de67c = 0;

        main_dlog_00427230(DAT_005def8c,1);

      }

    }

    uVar3 = TextGetPtrQ();

    main_dlog_00427890(DAT_005def8c,0x11,0x3f4ccccd,0x41600000,0x89000000,uVar3);

    uVar3 = TextGetPtrQ(s_CommShowConnLMaxPl_0057e20c);

    main_dlog_00427890(DAT_005def8c,0x191,DAT_0057dc98 - 0.01,0x41700000,0x85000002,uVar3);

    uVar3 = DAT_00632f34;

    if (((DAT_005def80 != 5) || (DAT_00632f44 != 0)) && (1 < DAT_00632f08)) {

      comm_0051a130(s_MaxPlayers_00559f9c,DAT_00632f34);

    }

    if (DAT_005def8c != 0) {

      FUN_00542f27(local_bc,&DAT_00557088,uVar3);

      main_dlog_00427230(DAT_005def8c,400);

      main_dlog_00427890(DAT_005def8c,400,DAT_0057dc98,0x41700000,0x81000002,local_bc);

      if ((((DAT_005def80 == 5) && (DAT_00632f44 == 0)) || (DAT_00632f08 < 2)) ||

         (uVar3 = 0xc8c832, DAT_00633238 != 0)) {

        uVar3 = 0xa0a0a0;

      }

      comm_00427860(DAT_005def8c,400,uVar3);

    }

    if ((DAT_00632f18 == 4) || (DAT_00632f18 == 5)) {

      DAT_00632f1c = 0;

    }

    uVar3 = TextGetPtrQ();

    main_dlog_00427890(DAT_005def8c,0x193,DAT_0057dc98 - 0.01,0x41800000,0x85000002,uVar3);

    if (((DAT_00632f18 < 0) || (3 < DAT_00632f18)) && ((DAT_00632f18 < 6 || (7 < DAT_00632f18)))) {

      bVar11 = false;

    }

    else {

      bVar11 = true;

    }

    if (((DAT_005def80 != 5) || (DAT_00632f44 != 0)) && (1 < DAT_00632f08)) {

      comm_0051a130(s_AllowJoiners_00559ffc,DAT_00632f1c);

    }

    if (DAT_005def8c != 0) {

      uVar3 = FUN_00507b00();

      main_dlog_00427230(DAT_005def8c,0x192);

      main_dlog_00427890(DAT_005def8c,0x192,DAT_0057dc98,0x41800000,0x81000002,uVar3);

      if (((DAT_005def80 == 5) && (DAT_00632f44 == 0)) ||

         ((DAT_00632f08 < 2 || (uVar3 = 0xc8c832, !bVar11)))) {

        uVar3 = 0xa0a0a0;

      }

      comm_00427860(DAT_005def8c,0x192,uVar3);

    }

    uVar3 = TextGetPtrQ();

    main_dlog_00427890(DAT_005def8c,0x19f,DAT_0057dc98 - 0.01,0x41880000,0x85000002,uVar3);

    if (((DAT_005def80 != 5) || (DAT_00632f44 != 0)) && (1 < DAT_00632f08)) {

      comm_0051a130(s_LockTeams_00559fe0,DAT_00632f38);

    }

    if (DAT_005def8c != 0) {

      uVar3 = FUN_00507b00();

      main_dlog_00427230(DAT_005def8c,0x19e);

      main_dlog_00427890(DAT_005def8c,0x19e,DAT_0057dc98,0x41880000,0x81000002,uVar3);

      if (((DAT_005def80 == 5) && (DAT_00632f44 == 0)) || (DAT_00632f08 < 2)) {

        bVar2 = 0;

      }

      else {

        bVar2 = 1;

      }

      comm_00427860(DAT_005def8c,0x19e,(-(uint)bVar2 & 0x282792) + 0xa0a0a0);

    }

    uVar3 = TextGetPtrQ();

    main_dlog_00427890(DAT_005def8c,0x195,DAT_0057dc98 - 0.01,0x41900000,0x85000002,uVar3);

    if (((DAT_005def80 != 5) || (DAT_00632f44 != 0)) && (1 < DAT_00632f08)) {

      comm_0051a130(s_DamageTeammates_00559fec,DAT_00632f20);

    }

    if (DAT_005def8c != 0) {

      uVar3 = FUN_00507b00();

      main_dlog_00427230(DAT_005def8c,0x194);

      main_dlog_00427890(DAT_005def8c,0x194,DAT_0057dc98,0x41900000,0x81000002,uVar3);

      if ((((DAT_005def80 == 5) && (DAT_00632f44 == 0)) || (DAT_00632f08 < 2)) &&

         ((DAT_005def94 != DAT_005def5c || (DAT_00632f08 < 2)))) {

        uVar3 = 0xa0a0a0;

      }

      else {

        uVar3 = 0xc8c832;

      }

      comm_00427860(DAT_005def8c,0x194,uVar3);

    }

    uVar3 = TextGetPtrQ();

    main_dlog_00427890(DAT_005def8c,0x197,DAT_0057dc98 - 0.01,0x41980000,0x85000002,uVar3);

    iVar5 = DAT_00632f24;

    if (((DAT_005def80 != 5) || (DAT_00632f44 != 0)) && (1 < DAT_00632f08)) {

      comm_0051a130(s_PointsPerKill_00559fd0,DAT_00632f24);

    }

    if (DAT_005def8c != 0) {

      if (iVar5 == 0) {

        pcVar6 = (char *)FUN_00507b00();

        pcVar12 = local_bc;

        do {

          cVar1 = *pcVar6;

          pcVar6 = pcVar6 + 1;

          *pcVar12 = cVar1;

          pcVar12 = pcVar12 + 1;

        } while (cVar1 != '\0');

      }

      else {

        FUN_00542f27(local_bc,&DAT_00557088,iVar5);

      }

      main_dlog_00427230(DAT_005def8c,0x196);

      main_dlog_00427890(DAT_005def8c,0x196,DAT_0057dc98,0x41980000,0x81000002,local_bc);

      if (((DAT_005def80 == 5) && (DAT_00632f44 == 0)) || (DAT_00632f08 < 2)) {

        bVar2 = 0;

      }

      else {

        bVar2 = 1;

      }

      comm_00427860(DAT_005def8c,0x196,(-(uint)bVar2 & 0x282792) + 0xa0a0a0);

    }

    uVar3 = TextGetPtrQ();

    main_dlog_00427890(DAT_005def8c,0x199,DAT_0057dc98 - 0.01,0x41a00000,0x85000002,uVar3);

    iVar5 = DAT_00632f28;

    if (((DAT_00632f18 == 2) || (DAT_00632f18 == 3)) || ((DAT_00632f18 == 5 || (DAT_00632f18 == 7)))

       ) {

      bVar11 = true;

    }

    else {

      bVar11 = false;

    }

    if (((DAT_005def80 != 5) || (DAT_00632f44 != 0)) && (1 < DAT_00632f08)) {

      comm_0051a130(s_PointsPerCapture_00559fbc,DAT_00632f28);

    }

    if (DAT_005def8c != 0) {

      if (iVar5 == 0) {

        pcVar6 = (char *)FUN_00507b00();

        pcVar12 = local_bc;

        do {

          cVar1 = *pcVar6;

          pcVar6 = pcVar6 + 1;

          *pcVar12 = cVar1;

          pcVar12 = pcVar12 + 1;

        } while (cVar1 != '\0');

      }

      else {

        FUN_00542f27(local_bc,&DAT_00557088,iVar5);

      }

      main_dlog_00427230(DAT_005def8c,0x198);

      main_dlog_00427890(DAT_005def8c,0x198,DAT_0057dc98,0x41a00000,0x81000002,local_bc);

      if (((DAT_005def80 == 5) && (DAT_00632f44 == 0)) ||

         ((DAT_00632f08 < 2 || (uVar3 = 0xc8c832, !bVar11)))) {

        uVar3 = 0xa0a0a0;

      }

      comm_00427860(DAT_005def8c,0x198,uVar3);

    }

    uVar3 = TextGetPtrQ();

    main_dlog_00427890(DAT_005def8c,0x19b,DAT_0057dc98 - 0.01,0x41a80000,0x85000002,uVar3);

    iVar5 = DAT_00632f2c;

    if (((DAT_005def80 != 5) || (DAT_00632f44 != 0)) && (1 < DAT_00632f08)) {

      comm_0051a130(s_CapturePreventTime_00559fa8,DAT_00632f2c);

    }

    if (DAT_005def8c != 0) {

      if (iVar5 == 0) {

        pcVar6 = (char *)FUN_00507b00();

        pcVar12 = local_bc;

        do {

          cVar1 = *pcVar6;

          pcVar6 = pcVar6 + 1;

          *pcVar12 = cVar1;

          pcVar12 = pcVar12 + 1;

        } while (cVar1 != '\0');

      }

      else {

        comm_004ce880(iVar5 * 0x3c,local_bc);

      }

      main_dlog_00427230(DAT_005def8c,0x19a);

      main_dlog_00427890(DAT_005def8c,0x19a,DAT_0057dc98,0x41a80000,0x81000002,local_bc);

      if ((((DAT_005def80 == 5) && (DAT_00632f44 == 0)) || (DAT_00632f08 < 2)) &&

         ((DAT_005def94 != DAT_005def5c || (DAT_00632f08 < 2)))) {

        uVar3 = 0xa0a0a0;

      }

      else {

        uVar3 = 0xc8c832;

      }

      comm_00427860(DAT_005def8c,0x19a,uVar3);

    }

    uVar3 = TextGetPtrQ();

    main_dlog_00427890(DAT_005def8c,0x1a1,DAT_0057dc98 - 0.01,0x41b00000,0x85000002,uVar3);

    iVar5 = DAT_00632f3c;

    if (((DAT_005def80 != 5) || (DAT_00632f44 != 0)) && (1 < DAT_00632f08)) {

      comm_0051a130(s_SmartieDifficulty_00559f88,DAT_00632f3c);

    }

    if (DAT_005def8c != 0) {

      if (iVar5 == 0) {

        uVar3 = *(undefined4 *)(DAT_00632ed8 + 0x11f4);

      }

      else if (iVar5 == 1) {

        uVar3 = *(undefined4 *)(DAT_00632ed8 + 0x11f8);

      }

      else {

        uVar3 = *(undefined4 *)(DAT_00632ed8 + 0x11fc);

      }

      FUN_00542f27(local_bc,&DAT_00557088,uVar3);

      main_dlog_00427230(DAT_005def8c,0x1a0);

      main_dlog_00427890(DAT_005def8c,0x1a0,DAT_0057dc98,0x41b00000,0x81000002,local_bc);

      if (((DAT_005def80 == 5) && (DAT_00632f44 == 0)) || (DAT_00632f08 < 2)) {

        bVar2 = 0;

      }

      else {

        bVar2 = 1;

      }

      comm_00427860(DAT_005def8c,0x1a0,(-(uint)bVar2 & 0x282792) + 0xa0a0a0);

    }

    uVar3 = TextGetPtrQ();

    main_dlog_00427890(DAT_005def8c,0x1a3,DAT_0057dc98 - 0.01,0x41b80000,0x85000002,uVar3);

    if (((DAT_005def80 != 5) || (DAT_00632f44 != 0)) && (1 < DAT_00632f08)) {

      comm_0051a130(s_VimpMeatDifficulty_00559f74,DAT_00632f40);

    }

    if (DAT_005def8c != 0) {

      uVar3 = FUN_00507b00();

      main_dlog_00427230(DAT_005def8c,0x1a2);

      main_dlog_00427890(DAT_005def8c,0x1a2,DAT_0057dc98,0x41b80000,0x81000002,uVar3);

      if (((DAT_005def80 == 5) && (DAT_00632f44 == 0)) || (DAT_00632f08 < 2)) {

        bVar2 = 0;

      }

      else {

        bVar2 = 1;

      }

      comm_00427860(DAT_005def8c,0x1a2,(-(uint)bVar2 & 0x282792) + 0xa0a0a0);

    }

    uVar3 = TextGetPtrQ();

    main_dlog_00427890(DAT_005def8c,0x12,0x3f4ccccd,0x41c80000,0x89000000,uVar3);

    uVar3 = TextGetPtrQ(s_CommShowConnLTimeLimit_0057e118);

    main_dlog_00427890(DAT_005def8c,0x1f5,DAT_0057dc98 - 0.01,0x41d00000,0x85000002,uVar3);

    iVar5 = DAT_00632fcc;

    if (((DAT_005def80 != 5) || (DAT_00632f44 != 0)) && (1 < DAT_00632f08)) {

      comm_0051a130(s_TimeLimit_00559f68,DAT_00632fcc);

    }

    if (DAT_005def8c != 0) {

      if (iVar5 == 0) {

        pcVar6 = (char *)FUN_00507b00();

        pcVar12 = local_bc;

        do {

          cVar1 = *pcVar6;

          pcVar6 = pcVar6 + 1;

          *pcVar12 = cVar1;

          pcVar12 = pcVar12 + 1;

        } while (cVar1 != '\0');

      }

      else {

        comm_004ce880(iVar5 * 0x3c,local_bc);

      }

      main_dlog_00427230(DAT_005def8c,500);

      main_dlog_00427890(DAT_005def8c,500,DAT_0057dc98,0x41d00000,0x81000002,local_bc);

      if (((DAT_005def80 == 5) && (DAT_00632f44 == 0)) || (DAT_00632f08 < 2)) {

        bVar2 = 0;

      }

      else {

        bVar2 = 1;

      }

      comm_00427860(DAT_005def8c,500,(-(uint)bVar2 & 0x282792) + 0xa0a0a0);

    }

    uVar3 = TextGetPtrQ();

    main_dlog_00427890(DAT_005def8c,0x19d,DAT_0057dc98,0x41d80000,0x81000002,uVar3);

    if (((DAT_005def80 == 5) && (DAT_00632f44 == 0)) || (DAT_00632f08 < 0xe)) {

      bVar2 = 0;

    }

    else {

      bVar2 = 1;

    }

    comm_00427860(DAT_005def8c,0x19d,(-(uint)bVar2 & 0x282792) + 0xa0a0a0);

    uVar3 = TextGetPtrQ(s_CommShowConnLPScoreLimit_0057e0e4);

    main_dlog_00427890(DAT_005def8c,0x1f7,DAT_0057dc98 - 0.01,0x41e00000,0x85000002,uVar3);

    iVar5 = DAT_00632fdc;

    if (((DAT_005def80 != 5) || (DAT_00632f44 != 0)) && (1 < DAT_00632f08)) {

      comm_0051a130(s_PlayerScoreLimit_00559f54,DAT_00632fdc);

    }

    if (DAT_005def8c != 0) {

      if (iVar5 == 0) {

        pcVar6 = (char *)FUN_00507b00();

        pcVar12 = local_bc;

        do {

          cVar1 = *pcVar6;

          pcVar6 = pcVar6 + 1;

          *pcVar12 = cVar1;

          pcVar12 = pcVar12 + 1;

        } while (cVar1 != '\0');

      }

      else {

        FUN_00542f27(local_bc,&DAT_00557088,iVar5);

      }

      main_dlog_00427230(DAT_005def8c,0x1f6);

      main_dlog_00427890(DAT_005def8c,0x1f6,DAT_0057dc98,0x41e00000,0x81000002,local_bc);

      if (((DAT_005def80 == 5) && (DAT_00632f44 == 0)) || (DAT_00632f08 < 2)) {

        bVar2 = 0;

      }

      else {

        bVar2 = 1;

      }

      comm_00427860(DAT_005def8c,0x1f6,(-(uint)bVar2 & 0x282792) + 0xa0a0a0);

    }

    uVar3 = TextGetPtrQ();

    main_dlog_00427890(DAT_005def8c,0x1f9,DAT_0057dc98 - 0.01,0x41e80000,0x85000002,uVar3);

    iVar5 = DAT_00632fec;

    if (((DAT_005def80 != 5) || (DAT_00632f44 != 0)) && (1 < DAT_00632f08)) {

      comm_0051a130(s_TeamScoreLimit_00559f44,DAT_00632fec);

    }

    if (DAT_005def8c != 0) {

      if (iVar5 == 0) {

        pcVar6 = (char *)FUN_00507b00();

        pcVar12 = local_bc;

        do {

          cVar1 = *pcVar6;

          pcVar6 = pcVar6 + 1;

          *pcVar12 = cVar1;

          pcVar12 = pcVar12 + 1;

        } while (cVar1 != '\0');

      }

      else {

        FUN_00542f27(local_bc,&DAT_00557088,iVar5);

      }

      main_dlog_00427230(DAT_005def8c,0x1f8);

      main_dlog_00427890(DAT_005def8c,0x1f8,DAT_0057dc98,0x41e80000,0x81000002,local_bc);

      if (((DAT_005def80 == 5) && (DAT_00632f44 == 0)) || (DAT_00632f08 < 2)) {

        bVar2 = 0;

      }

      else {

        bVar2 = 1;

      }

      comm_00427860(DAT_005def8c,0x1f8,(-(uint)bVar2 & 0x282792) + 0xa0a0a0);

    }

    if (((DAT_00632f18 != 4) && (DAT_00632f18 != 5)) && ((DAT_00632f18 != 6 && (DAT_00632f18 != 7)))

       ) {

      DAT_00632ff0 = 0;

    }

    uVar3 = TextGetPtrQ();

    main_dlog_00427890(DAT_005def8c,0x1fb,DAT_0057dc98 - 0.01,0x41f00000,0x85000002,uVar3);

    if (((DAT_00632f18 == 4) || (DAT_00632f18 == 5)) || ((DAT_00632f18 == 6 || (DAT_00632f18 == 7)))

       ) {

      uVar3 = 1;

    }

    else {

      uVar3 = 0;

    }

    comm_base_status_menu(DAT_00632ff0,uVar3);

    uVar3 = TextGetPtrQ(s_CommShowConnLEndGameNow_0057e0b0);

    main_dlog_00427890(DAT_005def8c,0x1fd,DAT_0057dc98,0x41f80000,0x81000002,uVar3);

    if (DAT_005def8c != 0) {

      if ((((DAT_005def80 == 5) && (DAT_00632f44 == 0)) || (DAT_00632f08 < 0xe)) &&

         ((DAT_005def94 != DAT_005def5c || (DAT_00632f08 < 0xe)))) {

        uVar3 = 0xa0a0a0;

      }

      else {

        uVar3 = 0xc8c832;

      }

      comm_00427860(DAT_005def8c,0x1fd,uVar3);

    }

    if (DAT_005def8c != 0) {

      uVar3 = FUN_00507b00(s_CommVersion_0057e068,(double)((float)DAT_00633038 * 0.001));

      FUN_00542f27(local_bc,s__s___1_3f_0057e05c,uVar3);

      main_dlog_00427230(DAT_005def8c,0x1a4);

      main_dlog_00427890(DAT_005def8c,0x1a4,0x3f7d70a4,0xbf800000,0x85000000,local_bc);

      comm_00427860(DAT_005def8c,0x1a4,0x8fffff);

    }

    do {

      comm_00427860(DAT_005def8c,iVar4,0xffffff);

      iVar4 = iVar4 + 1;

    } while (iVar4 < 7);

    iVar4 = 7;

    do {

      comm_00427860(DAT_005def8c,iVar4,0x8fffff);

      iVar4 = iVar4 + 1;

    } while (iVar4 < 0x13);

    main_dlog_004273b0(DAT_005def8c,0x15,0x3c23d70a,0xbf800000,0x81000000,&DAT_00584374);

    if (DAT_00632f08 < 0xe) {

      main_dlog_004273b0(DAT_005def8c,4,0x3d4ccccd,0x42000000,0x83000002,s_CommStatChat_0057e0a0);

      main_dlog_00427970(DAT_005def8c,3,0x3dcccccd,0x42000000,0x81000000,&DAT_005ddb98,0x100);

    }

    DAT_005ddd38 = (uint)(0xd < DAT_00632f08);

    DAT_005ddfb8 = 0xffffffff;

    DAT_005def50 = 0x3f800000;

    DAT_005de67c = 0;

    DAT_005def58 = 0;

    DAT_005def40 = 0;

    comm_player_name2();

    _DAT_005def48 = 0x3f400000;

    DAT_005ddf58 = 0;

    if (DAT_00632f08 < 0xe) {

      DAT_005ddf58 = 0;

      main_texture_005088d0

                (s_MP_screen_0057e074,&DAT_005ddf4c,&DAT_005ddf50,&DAT_005ddf54,&DAT_005ddf58);

      MAP_MemGroupSetBase_2(DAT_005def8c,0);

      if (DAT_00632f44 != 0) {

        iVar4 = FUN_00525140(DAT_00632f14,DAT_00632f14);

        if (iVar4 == 0) {

          if ((DAT_00632f10 == 0) || ((1 < DAT_00632f10 && (DAT_00632f10 < 5)))) {

            bVar11 = true;

          }

          else {

            bVar11 = false;

          }

          DAT_00632f14 = !bVar11 + 1;

        }

        iVar4 = comm_00426540();

        if (iVar4 != 0) {

          DAT_00632f14 = 0;

        }

      }

    }

    else {

      DAT_005de67c = 1;

      iVar4 = comm_00426540();

      if ((iVar4 == 0) || (0xd < DAT_00632f08)) {

        main_dlog_00427bb0(DAT_005def8c,1,0x3f451eb8,0xc0800000,0x86000000,s_ButtonContinue_0057e090

                          );

        MAP_MemGroupSetBase_2(DAT_005def8c,1);

      }

      DAT_00632e44 = 1;

      if (DAT_00632f44 == 0) {

        if (DAT_005def94 == DAT_005def5c) {

          puVar9 = &DAT_00632d20;

          puVar10 = &DAT_005de2b8;

          for (iVar4 = 0xf1; iVar4 != 0; iVar4 = iVar4 + -1) {

            *puVar10 = *puVar9;

            puVar9 = puVar9 + 1;

            puVar10 = puVar10 + 1;

          }

          return;

        }

      }

      else {

        bVar11 = DAT_005def40 == 0;

        puVar9 = &DAT_00632d20;

        puVar10 = &DAT_005de2b8;

        for (iVar4 = 0xf1; iVar4 != 0; iVar4 = iVar4 + -1) {

          *puVar10 = *puVar9;

          puVar9 = puVar9 + 1;

          puVar10 = puVar10 + 1;

        }

        if ((bVar11) && (iVar4 = comm_00426540(), iVar4 == 0)) {

          main_dlog_00427bb0(DAT_005def8c,0x14,0x3f656042,0xc0a00000,0x8a000000,

                             s_ButtonDefaults_0057e080);

          DAT_005def40 = 1;

          return;

        }

      }

    }

  }

  return;

}

/* ===== gamespy_host_game @ 0x00524DE0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void gamespy_host_game(void)



{

  int iVar1;

  undefined4 *puVar2;

  

  main_texture_00508eb0(DAT_005ddf4c,DAT_005ddf50,DAT_005ddf54,DAT_005ddf58);

  DAT_005ddf58 = 0;

  if (DAT_00632f44 == 0) {

    DAT_00633238 = 0;

    FUN_0051fba0();

  }

  else if (DAT_005def80 != 0) {

    if ((DAT_0063317c == 0) && (DAT_00633184 == 0)) {

      if (DAT_005defa4 == 0) {

        if (DAT_005defa0 == 0) {

          FUN_0051ea20(s_gamespy_shutdown_called_without_i_0057dd30);

        }

        else {

          DAT_00632f08 = 9999;

          gamespy_0052daa0(0);

          gamespy_0052db50(0);

          DAT_005defa4 = 1;

          DAT_005defa0 = 0;

        }

      }

      else {

        FUN_0051ea20(s_gamespy_shutdown_called_more_tha_0057dd58);

      }

    }

    (**(code **)(*DAT_005def60 + 0x14))(DAT_005def60,0,4);

    if (DAT_005def68 != (int *)0x0) {

      (**(code **)(*DAT_005def68 + 8))(DAT_005def68);

      DAT_005def68 = (int *)0x0;

    }

    if (DAT_005def60 != (int *)0x0) {

      (**(code **)(*DAT_005def60 + 0x5c))(DAT_005def60,0);

      (**(code **)(*DAT_005def60 + 8))(DAT_005def60);

      DAT_005def60 = (int *)0x0;

    }

    CoUninitialize();

    puVar2 = &DAT_005ddf60;

    for (iVar1 = 0x14; iVar1 != 0; iVar1 = iVar1 + -1) {

      *puVar2 = 0;

      puVar2 = puVar2 + 1;

    }

    _DAT_005de2a4 = 0;

    _DAT_005de2a8 = 0;

    _DAT_005de290 = 0;

    _DAT_005de2ac = 0;

    _DAT_005ddf38 = 0;

    _DAT_005de294 = 0;

    _DAT_005de2b0 = 0;

    _DAT_005ddf3c = 0;

    _DAT_005de298 = 0;

    _DAT_005de2b4 = 0;

    _DAT_005de29c = 0;

    _DAT_005ddf40 = 0;

    _DAT_005ddf44 = 0;

    puVar2 = &DAT_005ddd48;

    for (iVar1 = 0x14; iVar1 != 0; iVar1 = iVar1 + -1) {

      *puVar2 = 0;

      puVar2 = puVar2 + 1;

    }

    _DAT_005de2a0 = 0;

    _DAT_005ddf48 = 0;

    DAT_005def80 = 0;

  }

  DAT_00633160 = 0;

  DAT_0063315c = 0;

  DAT_0063317c = 0;

  iVar1 = FUN_004a6160(DAT_00632a88);

  if (iVar1 == 0) {

    iVar1 = FUN_004a6180(DAT_00632a88);

    if (iVar1 != 0) {

      obj_snap_variant_a(DAT_00632a88);

    }

  }

  else {

    FUN_00480a60(DAT_00632a88);

  }

  if (DAT_005def8c != 0) {

    main_dlog_00427180(DAT_005def8c);

    DAT_005def8c = 0;

    dialog_level_pop(&LAB_00525460);

  }

  comm_options_defaults();

  FUN_004ff470();

  Audio3DTestToneUpdate__Fv();

  if (DAT_006330e4 != 0) {

    iVar1 = FUN_00545650(*(undefined4 *)(DAT_006330e4 + 4),s_intro_island_0055be84);

    if (iVar1 != 0) {

      main_setupgam_004eda20();

    }

    if ((DAT_006330e4 != 0) &&

       (iVar1 = FUN_00545650(*(undefined4 *)(DAT_006330e4 + 4),s_intro_island_0055be84), iVar1 == 0)

       ) {

      menu_keymap_screen();

      return;

    }

  }

  FUN_004907e0();

  return;

}

/* ===== Audio3DTestToneUpdate__Fv_6 @ 0x00525030 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */



void Audio3DTestToneUpdate__Fv_6(void)



{

  _DAT_005ddd98 = 0x3fc00000;

  return;

}

/* ===== comm_entergame_msg4 @ 0x00525040 ===== */
void comm_entergame_msg4(void)



{

  if (DAT_00632f08 == 10) {

    comm_entergame_msg_2(0xc);

  }

  return;

}

/* ===== dlog_user_525060 @ 0x00525060 ===== */
void dlog_user_525060(void)



{

  int iVar1;

  

  iVar1 = 0;

  if (0 < DAT_00632f34) {

    do {

      if ((&DAT_005ddf60)[iVar1] == DAT_005def5c) {

        if (iVar1 < DAT_00632f34) goto LAB_00525089;

        break;

      }

      iVar1 = iVar1 + 1;

    } while (iVar1 < DAT_00632f34);

  }

  iVar1 = DAT_00632f34 + -1;

LAB_00525089:

  if ((((-1 < iVar1) && ((&DAT_005de2a4)[iVar1] != 0)) && ((byte)(&DAT_005de2a4)[iVar1] < 4)) &&

     (DAT_00632f08 == 0xc)) {

    DAT_005ddd38 = 1;

    return;

  }

  DAT_005de67c = 0;

  main_dlog_00427230(DAT_005def8c,1);

  main_dlog_00427230(DAT_005def8c,19999);

  return;

}

/* ===== FUN_005250e0 @ 0x005250E0 ===== */
undefined4 FUN_005250e0(int param_1)



{

  if ((param_1 != 0) && ((param_1 < 2 || (4 < param_1)))) {

    return 0;

  }

  return 1;

}

/* ===== FUN_00525100 @ 0x00525100 ===== */
undefined4 FUN_00525100(int param_1)



{

  if ((0 < param_1) && ((param_1 < 4 || (param_1 == 5)))) {

    return 1;

  }

  return 0;

}

/* ===== FUN_00525120 @ 0x00525120 ===== */
undefined4 FUN_00525120(int param_1)



{

  if ((2 < param_1) && (param_1 < 6)) {

    return 1;

  }

  return 0;

}

/* ===== FUN_00525140 @ 0x00525140 ===== */
undefined4 FUN_00525140(int param_1,int param_2)



{

  uint uVar1;

  int iVar2;

  bool bVar3;

  

  if (DAT_00632f10 == 3) {

    if (param_1 == param_2) goto LAB_00525308;

    iVar2 = 0;

    for (uVar1 = (uint)(DAT_00633238 != 0); (int)uVar1 < DAT_00632f34; uVar1 = uVar1 + 1) {

      if (((-1 < (int)uVar1) && ((&DAT_005ddf60)[uVar1] != 0)) && ((&DAT_005de2a4)[uVar1] == '\x03')

         ) {

        iVar2 = iVar2 + 1;

      }

    }

    if (param_2 != 3) goto LAB_00525308;

    if (0 < iVar2) {

      return 0;

    }

  }

  else {

    if (DAT_00632f10 == 4) {

      if ((param_1 == param_2) && (param_2 == 3)) {

        iVar2 = 0;

        for (uVar1 = (uint)(DAT_00633238 != 0); (int)uVar1 < DAT_00632f34; uVar1 = uVar1 + 1) {

          if (((-1 < (int)uVar1) && ((&DAT_005ddf60)[uVar1] != 0)) &&

             ((&DAT_005de2a4)[uVar1] == '\x03')) {

            iVar2 = iVar2 + 1;

          }

        }

        goto LAB_00525202;

      }

      iVar2 = 0;

      for (uVar1 = (uint)(DAT_00633238 != 0); (int)uVar1 < DAT_00632f34; uVar1 = uVar1 + 1) {

        if (((-1 < (int)uVar1) && ((&DAT_005ddf60)[uVar1] != 0)) &&

           ((&DAT_005de2a4)[uVar1] == '\x03')) {

          iVar2 = iVar2 + 1;

        }

      }

      if (param_2 != 3) {

        bVar3 = param_2 == 1;

LAB_00525302:

        if (!bVar3) {

          return 0;

        }

        goto LAB_00525308;

      }

    }

    else {

      if (DAT_00632f10 != 5) goto LAB_00525308;

      if ((param_1 != param_2) || (param_2 != 3)) {

        iVar2 = 0;

        for (uVar1 = (uint)(DAT_00633238 != 0); (int)uVar1 < DAT_00632f34; uVar1 = uVar1 + 1) {

          if (((-1 < (int)uVar1) && ((&DAT_005ddf60)[uVar1] != 0)) &&

             ((&DAT_005de2a4)[uVar1] == '\x03')) {

            iVar2 = iVar2 + 1;

          }

        }

        if (param_2 != 3) {

          bVar3 = param_2 == 2;

          goto LAB_00525302;

        }

        goto LAB_00525205;

      }

      iVar2 = 0;

      for (uVar1 = (uint)(DAT_00633238 != 0); (int)uVar1 < DAT_00632f34; uVar1 = uVar1 + 1) {

        if (((-1 < (int)uVar1) && ((&DAT_005ddf60)[uVar1] != 0)) &&

           ((&DAT_005de2a4)[uVar1] == '\x03')) {

          iVar2 = iVar2 + 1;

        }

      }

LAB_00525202:

      iVar2 = iVar2 + -1;

    }

LAB_00525205:

    if (0 < iVar2) {

      return 0;

    }

LAB_00525308:

    if (param_2 < 0) {

      return 0;

    }

    if (((DAT_00632f10 == 0) || (DAT_00632f10 == 1)) || (DAT_00632f10 == 2)) {

      iVar2 = 2;

      goto LAB_0052532a;

    }

  }

  iVar2 = 3;

LAB_0052532a:

  if (iVar2 < param_2) {

    return 0;

  }

  return 1;

}

/* ===== dlog_user_525340 @ 0x00525340 ===== */
void dlog_user_525340(void)



{

  if (((DAT_005def8c != 0) && ((DAT_00632f18 < 0 || (3 < DAT_00632f18)))) &&

     ((DAT_00632f18 < 6 || (7 < DAT_00632f18)))) {

    DAT_005de67c = 0;

    main_dlog_00427230(DAT_005def8c,1);

  }

  return;

}

/* ===== FUN_00525380 @ 0x00525380 ===== */
void FUN_00525380(int param_1)



{

  if (param_1 == 2) {

    FUN_00507b00();

    return;

  }

  if (param_1 == 6) {

    FUN_00507b00();

    return;

  }

  if ((((param_1 == 3) || (param_1 == 4)) || (param_1 == 8)) || (param_1 == 7)) {

    FUN_00507b00();

    return;

  }

  if ((param_1 == 10) || (param_1 == 0xb)) {

    FUN_00507b00();

    return;

  }

  if ((param_1 == 9) || (param_1 == 5)) {

    FUN_00507b00();

    return;

  }

  if (param_1 == 0xc) {

    FUN_00507b00();

    return;

  }

  if (param_1 == 0xd) {

    FUN_00507b00();

    return;

  }

  if (param_1 == 0xe) {

    FUN_00507b00();

    return;

  }

  if (param_1 == 0xf) {

    FUN_00507b00();

    return;

  }

  FUN_00507b00();

  return;

}

/* ===== gamespy_statechange2 @ 0x00528620 ===== */
void gamespy_statechange2(void)



{

  if ((DAT_00633238 == 0) || (DAT_00632f44 == 0)) {

    game_mode_update();

  }

  if ((float)DAT_00632e88 < 480.0 != ((float)DAT_00632e88 == 480.0)) {

    win95_text_0051b160();

    win95_text_0051adb0(0x18);

  }

  if (DAT_005def8c != 0) {

    main_dlog_00427180(DAT_005def8c);

  }

  DAT_005def8c = 0;

  dialog_level_pop(&LAB_00525460);

  DAT_005dde58 = 0;

  DAT_005dde5c = 0;

  DAT_005dde78 = 0;

  DAT_005dde7c = 0;

  DAT_005dde98 = 0;

  DAT_005dde9c = 0;

  comm_entergame_msg_2(0xe);

  if (((DAT_00632f44 != 0) && (DAT_0063317c == 0)) && (DAT_00633184 == 0)) {

    if (DAT_005defa4 == 0) {

      if (DAT_005defa0 == 0) {

        FUN_0051ea20(s_gamespy_send_statechange_called_w_0057df04);

      }

      else {

        gamespy_0052daa0(0);

      }

    }

    else {

      FUN_0051ea20(s_gamespy_send_statechange_called_a_0057df34);

    }

  }

  main_texture_00508eb0(DAT_005ddf4c,DAT_005ddf50,DAT_005ddf54,DAT_005ddf58);

  DAT_005ddf58 = 0;

  return;

}

/* ===== FUN_00528720 @ 0x00528720 ===== */
undefined4 FUN_00528720(void)



{

  uint uVar1;

  

  if (((DAT_00632f18 < 0) || (3 < DAT_00632f18)) && ((DAT_00632f18 < 6 || (7 < DAT_00632f18)))) {

    for (uVar1 = (uint)(DAT_00633238 != 0); (int)uVar1 < DAT_00632f34; uVar1 = uVar1 + 1) {

      if (((&DAT_005ddf60)[uVar1] != 0) && ((&DAT_005de2a4)[uVar1] == '\0')) {

        return 0;

      }

    }

  }

  return 1;

}

/* ===== FUN_00528780 @ 0x00528780 ===== */
undefined4 FUN_00528780(void)



{

  uint uVar1;

  

  if (((DAT_00632f18 < 0) || (3 < DAT_00632f18)) && ((DAT_00632f18 < 6 || (7 < DAT_00632f18)))) {

    if (((DAT_00632f18 < 0) || (3 < DAT_00632f18)) && ((DAT_00632f18 < 6 || (7 < DAT_00632f18)))) {

      for (uVar1 = (uint)(DAT_00633238 != 0); (int)uVar1 < DAT_00632f34; uVar1 = uVar1 + 1) {

        if (((&DAT_005ddf60)[uVar1] != 0) && ((&DAT_005de2a4)[uVar1] == '\0')) {

          return 0;

        }

      }

    }

    for (uVar1 = (uint)(DAT_00633238 != 0); (int)uVar1 < DAT_00632f34; uVar1 = uVar1 + 1) {

      if (((&DAT_005ddf60)[uVar1] != 0) && ((byte)(&DAT_005de290)[uVar1] < 0xc)) {

        return 0;

      }

    }

  }

  return 1;

}

/* ===== comm_player_name2 @ 0x00528820 ===== */
void comm_player_name2(void)



{

  undefined4 uVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  char *pcVar5;

  int unaff_EDI;

  int *piVar6;

  undefined4 local_154;

  int local_150 [16];

  char acStack_110 [16];

  char local_100 [256];

  

  DAT_005def4c = 0;

  DAT_005ddfb8 = 0xffffffff;

  if (DAT_00632f44 == 0) {

    iVar2 = 0;

    if (0 < DAT_00632f34) {

      pcVar5 = &DAT_005ddfc0;

      do {

        if ((0x5ddfbf < (int)pcVar5) && ((&DAT_005ddf60)[iVar2] != 0)) {

          if (*pcVar5 == '\0') {

            if ((DAT_00632f44 != 0) &&

               (iVar3 = comm_comm_0052acc0((&DAT_005ddf60)[iVar2],local_100,0x100), iVar3 != 0)) {

              _strncpy(pcVar5,local_100,0x20);

              pcVar5[0x1f] = '\0';

            }

            if (*pcVar5 == '\0') {

              uVar1 = FUN_00507b00(s_CommUnnamedPlayer_0057df98,iVar2);

              FUN_00542f27(pcVar5,s__s__d_00555f38,uVar1);

            }

          }

          comm_progress_display((&DAT_005ddf60)[iVar2],pcVar5);

        }

        iVar2 = iVar2 + 1;

        pcVar5 = pcVar5 + 0x20;

      } while (iVar2 < DAT_00632f34);

    }

  }

  else {

    local_154 = 0x14;

    piVar6 = local_150;

    for (iVar2 = 0x14; iVar2 != 0; iVar2 = iVar2 + -1) {

      *piVar6 = 0;

      piVar6 = piVar6 + 1;

    }

    iVar2 = (**(code **)(*DAT_005def60 + 0x54))(DAT_005def60,local_150,&local_154,1);

    if ((-1 < iVar2) && (iVar3 = 0, iVar2 = DAT_00632f34, 0 < unaff_EDI)) {

      do {

        iVar4 = 0;

        if (0 < iVar2) {

          do {

            if ((&DAT_005ddf60)[iVar4] == local_150[iVar3 + -4]) {

              if (-1 < iVar4) {

                pcVar5 = &DAT_005ddfc0 + iVar4 * 0x20;

                if (*pcVar5 == '\0') {

                  if ((DAT_00632f44 != 0) &&

                     (iVar2 = comm_comm_0052acc0((&DAT_005ddf60)[iVar4],acStack_110,0x100),

                     iVar2 != 0)) {

                    _strncpy(pcVar5,acStack_110,0x20);

                    (&DAT_005ddfdf)[iVar4 * 0x20] = 0;

                  }

                  if (*pcVar5 == '\0') {

                    uVar1 = FUN_00507b00(s_CommUnnamedPlayer_0057df98,iVar4);

                    FUN_00542f27(pcVar5,s__s__d_00555f38,uVar1);

                  }

                }

                comm_progress_display(local_150[iVar3 + -4],pcVar5);

                iVar2 = DAT_00632f34;

              }

              break;

            }

            iVar4 = iVar4 + 1;

          } while (iVar4 < iVar2);

        }

        iVar3 = iVar3 + 1;

        if (unaff_EDI <= iVar3) {

          return;

        }

      } while( true );

    }

  }

  return;

}

/* ===== comm_progress_display @ 0x00528A00 ===== */
void comm_progress_display(int param_1,char *param_2)



{

  float fVar1;

  char cVar2;

  char cVar3;

  int iVar4;

  float fVar5;

  int iVar6;

  undefined1 *puVar7;

  char *pcVar8;

  undefined4 uVar9;

  uint uVar10;

  char *pcVar11;

  char cVar12;

  char local_64 [100];

  

  cVar12 = '\0';

  iVar6 = 0;

  if (0 < DAT_00632f34) {

    do {

      if ((&DAT_005ddf60)[iVar6] == param_1) {

        if (iVar6 < 0) {

          cVar2 = '\0';

        }

        else {

          cVar2 = (&DAT_005de2a4)[iVar6];

        }

        goto LAB_00528a4f;

      }

      iVar6 = iVar6 + 1;

    } while (iVar6 < DAT_00632f34);

  }

  iVar6 = -1;

  cVar2 = '\0';

LAB_00528a4f:

  if ((param_2 == (char *)0x0) || (*param_2 == '\0')) {

    param_2 = (char *)FUN_00507b00();

  }

  iVar4 = -(int)param_2;

  do {

    cVar3 = *param_2;

    param_2[(int)(local_64 + iVar4)] = cVar3;

    param_2 = param_2 + 1;

  } while (cVar3 != '\0');

  fVar5 = (float)DAT_005def4c + 13.0;

  if (param_1 == DAT_005ddfb4) {

    if (DAT_00633238 != 0) {

      return;

    }

    main_dlog_00427490(DAT_005def8c,DAT_005def4c + 0x8c,0x3c23d70a,fVar5,0x81000003,&DAT_0057e8a4,4)

    ;

LAB_00528b2e:

    comm_00427860(DAT_005def8c,DAT_005def4c + 0x8c,0);

  }

  else if ((DAT_00633238 != 0) && (DAT_005def94 == param_1)) {

    main_dlog_00427490(DAT_005def8c,DAT_005def4c + 0x8c,0x3c23d70a,fVar5,0x81000003,&DAT_0057e8a4,4)

    ;

    goto LAB_00528b2e;

  }

  if (param_1 != DAT_005def5c) {

    main_dlog_00427490(DAT_005def8c,DAT_005def4c + 0xa0,0x3cf5c28f,fVar5,0x81000003,&DAT_0057e8a4,

                       ((&DAT_005ddd48)[iVar6] != 0) + '\x01');

    comm_00427860(DAT_005def8c,DAT_005def4c + 0xa0,0);

  }

  if ((DAT_00632f44 == 0) || (param_1 == DAT_005ddfb4)) {

    if ((DAT_005def5c != DAT_005def94) || (param_1 == DAT_005def5c)) goto LAB_00528c3a;

    main_dlog_00427490(DAT_005def8c,DAT_005def4c + 0xb4,0x3d4ccccd,fVar5,0x81000003,&DAT_0057e8a4,3)

    ;

  }

  else {

    main_dlog_00427490(DAT_005def8c,DAT_005def4c + 0xb4,0x3d4ccccd,fVar5,0x81000003,&DAT_0057e8a4,3)

    ;

  }

  comm_00427860(DAT_005def8c,DAT_005def4c + 0xb4,0);

LAB_00528c3a:

  main_dlog_00427890(DAT_005def8c,DAT_005def4c + 0x28,0x3da3d70a,fVar5,0x81000002,local_64);

  comm_00427860(DAT_005def8c,DAT_005def4c + 0x28,

                ((param_1 != DAT_005def5c) - 1 & 0x282792) + 0xa0a0a0);

  if (param_1 == DAT_005def5c) {

    DAT_005ddfb8 = DAT_005def4c;

  }

  (&DAT_005ddc98)[DAT_005def4c] = iVar6;

  if ((-1 < iVar6) && (iVar6 < 0x14)) {

    cVar12 = (&DAT_005de290)[iVar6];

  }

  puVar7 = (undefined1 *)FUN_00525380();

  if (((cVar12 == '\x04') || (cVar12 == '\b')) && (param_1 == DAT_005def5c)) {

    pcVar8 = (char *)FUN_00507b00();

    pcVar11 = &DAT_005ddce8;

    do {

      cVar12 = *pcVar8;

      pcVar8 = pcVar8 + 1;

      *pcVar11 = cVar12;

      pcVar11 = pcVar11 + 1;

    } while (cVar12 != '\0');

    uVar9 = __ftol();

    uVar10 = 0xffffffff;

    pcVar8 = &DAT_005ddce8;

    do {

      if (uVar10 == 0) break;

      uVar10 = uVar10 - 1;

      cVar12 = *pcVar8;

      pcVar8 = pcVar8 + 1;

    } while (cVar12 != '\0');

    FUN_00542f27(~uVar10 + 0x5ddce7,s__d___0057e87c,uVar9);

    puVar7 = &DAT_005ddce8;

  }

  main_dlog_00427890(DAT_005def8c,DAT_005def4c + 0x3c,0x3e800000,fVar5,0x81000002,puVar7);

  comm_00427860(DAT_005def8c,DAT_005def4c + 0x3c,

                ((param_1 != DAT_005def5c) - 1 & 0x282792) + 0xa0a0a0);

  comm_team_name(DAT_005def4c,cVar2,0);

  if (iVar6 < 0) {

    uVar9 = 0;

  }

  else {

    uVar9 = (&DAT_005ddee8)[iVar6];

  }

  FUN_00542f27(local_64,&DAT_00557088,uVar9);

  main_dlog_00427890(DAT_005def8c,DAT_005def4c + 0x50,0x3ed70a3d,fVar5,0x89000000,local_64);

  comm_00427860(DAT_005def8c,DAT_005def4c + 0x50,

                ((param_1 != DAT_005def5c) - 1 & 0x282792) + 0xa0a0a0);

  if (iVar6 < 0) {

    fVar1 = 0.0;

  }

  else {

    fVar1 = (float)(&DAT_005ddda0)[iVar6];

  }

  if (cVar2 == '\x03') {

    FUN_00542f27(local_64,s__1_1f_0057e89c,(double)fVar1);

  }

  else {

    uVar9 = __ftol();

    FUN_00542f27(local_64,&DAT_00557088,uVar9);

  }

  main_dlog_00427890(DAT_005def8c,DAT_005def4c + 0x78,0x3ef0a3d7,fVar5,0x81000000,local_64);

  comm_00427860(DAT_005def8c,DAT_005def4c + 0x78,

                ((param_1 != DAT_005def5c) - 1 & 0x282792) + 0xa0a0a0);

  DAT_005def4c = DAT_005def4c + 1;

  return;

}

/* ===== comm_team_status @ 0x00528EE0 ===== */
/* WARNING (jumptable): Unable to track spacebase fully for stack */



void comm_team_status(void)



{

  int iVar1;

  uint uVar2;

  float fVar3;

  char *pcVar4;

  undefined4 uVar5;

  int iVar6;

  uint uVar7;

  int local_144;

  int local_140;

  float local_13c;

  undefined1 local_130 [40];

  undefined1 local_108 [260];

  

  iVar6 = 0xcb;

  do {

    main_dlog_00427230(DAT_005def8c,iVar6 + -3);

    main_dlog_00427230(DAT_005def8c,iVar6);

    main_dlog_00427230(DAT_005def8c,iVar6 + 3);

    main_dlog_00427230(DAT_005def8c,iVar6 + 6);

    iVar1 = iVar6 + -0xc9;

    iVar6 = iVar6 + 1;

  } while (iVar1 < 4);

  if (((DAT_00632f10 == 0) || (DAT_00632f10 == 1)) || (DAT_00632f10 == 2)) {

    local_144 = 2;

  }

  else {

    local_144 = 3;

    if (((DAT_00632f10 < 1) || ((3 < DAT_00632f10 && (DAT_00632f10 != 5)))) ||

       ((DAT_00632f10 != 0 && ((DAT_00632f10 < 2 || (4 < DAT_00632f10)))))) {

      local_144 = 2;

    }

  }

  local_140 = 1;

  if (local_144 != 0) {

    do {

      if (((DAT_00632f10 < 1) || ((3 < DAT_00632f10 && (DAT_00632f10 != 5)))) && (local_140 == 2)) {

        if (DAT_00632f10 == 0) goto LAB_00528ffa;

        if ((DAT_00632f10 == 1) || (DAT_00632f10 == 2)) goto LAB_00528fd7;

        iVar6 = 1;

      }

      else {

LAB_00528fd7:

        if ((DAT_00632f10 == 0) ||

           ((((1 < DAT_00632f10 && (DAT_00632f10 < 5)) || (DAT_00632f10 == 0)) ||

            ((DAT_00632f10 == 1 || (DAT_00632f10 == 2)))))) {

LAB_00528ffa:

          iVar6 = 0;

        }

        else {

          iVar6 = 1;

        }

      }

      uVar2 = iVar6 + local_140;

      switch(DAT_00632f10) {

      case 0:

      case 1:

        pcVar4 = s_CommTeamNo_d_0057dfe4;

        break;

      case 2:

      case 3:

      case 4:

      case 5:

        pcVar4 = s_CommTeamNo_dA_0057dfd4;

        break;

      default:

        goto switchD_00529004_default;

      }

      FUN_00542f27(local_130,CONCAT44(uVar2,pcVar4));

switchD_00529004_default:

      FUN_00507b00();

      iVar6 = 0;

      for (uVar7 = (uint)(DAT_00633238 != 0); (int)uVar7 < DAT_00632f34; uVar7 = uVar7 + 1) {

        if (((-1 < (int)uVar7) && ((&DAT_005ddf60)[uVar7] != 0)) &&

           ((byte)(&DAT_005de2a4)[uVar7] == uVar2)) {

          iVar6 = iVar6 + 1;

        }

      }

      if (((int)uVar2 < 1) || (3 < (int)uVar2)) {

        local_13c = 0.0;

      }

      else {

        local_13c = *(float *)(&DAT_005de280 + uVar2 * 4);

      }

      uVar5 = FUN_00507b00(s_CommStatPlrTeam_0057e8a8);

      FUN_00542f27(local_108,s__s__s_0055c280,uVar5);

      fVar3 = ((float)local_140 + 8.0) - 1.0;

      main_dlog_00427890(DAT_005def8c,local_140 + 199,0x3da3d70a,fVar3,0x81000002,local_108);

      comm_00427860(DAT_005def8c,local_140 + 199);

      FUN_00542f27(local_108,&DAT_00557088,iVar6);

      main_dlog_00427890(DAT_005def8c,local_140 + 0xca,0x3e6147ae,fVar3,0x81000000,local_108);

      comm_00427860(DAT_005def8c,local_140 + 0xca);

      if ((((uVar2 == 3) && (DAT_00632f18 != 2)) && (DAT_00632f18 != 3)) &&

         ((DAT_00632f18 != 5 && (DAT_00632f18 != 7)))) {

        FUN_00542f27(local_108,s__1_1f_0057e89c,(double)local_13c);

      }

      else {

        __ftol();

        FUN_00542f27(local_108,&DAT_00557088);

      }

      main_dlog_00427890(DAT_005def8c,local_140 + 0xcd,0x3e8f5c29,fVar3,0x81000000);

      comm_00427860(DAT_005def8c,local_140 + 0xcd);

      uVar5 = __ftol();

      FUN_00542f27(local_108,&DAT_00557088,uVar5);

      main_dlog_00427890(DAT_005def8c,local_140 + 0xd0,0x3eae147b,fVar3,0x81000000,local_108);

      comm_00427860(DAT_005def8c,local_140 + 0xd0);

      local_140 = local_140 + 1;

    } while (local_140 <= local_144);

  }

  return;

}

/* ===== comm_change_options_menu @ 0x00529320 ===== */
void comm_change_options_menu(void)



{

  char cVar1;

  undefined4 uVar2;

  int iVar3;

  undefined1 *puVar4;

  char *pcVar5;

  char *pcVar6;

  char *pcVar7;

  char local_128 [256];

  undefined1 local_28 [40];

  

  if ((DAT_00632f44 != 0) && (DAT_00632f1c != DAT_005de4b4)) {

    if (DAT_00632f1c == 0) {

      pcVar6 = s_CommChgJoinersNo_0057e4d0;

    }

    else {

      pcVar6 = s_CommChgJoinersYes_0057e4e4;

    }

    pcVar6 = (char *)FUN_00507b00(pcVar6);

    pcVar5 = local_128;

    do {

      cVar1 = *pcVar6;

      pcVar6 = pcVar6 + 1;

      *pcVar5 = cVar1;

      pcVar5 = pcVar5 + 1;

    } while (cVar1 != '\0');

    comm_audio_volume_user(local_128,1,0,0);

  }

  if (DAT_00632f20 != DAT_005de4b8) {

    if (DAT_00632f20 == 0) {

      pcVar6 = s_CommChgDmgMatesNo_0057e4a8;

    }

    else {

      pcVar6 = s_CommChgDmgMatesYes_0057e4bc;

    }

    pcVar6 = (char *)FUN_00507b00(pcVar6);

    pcVar5 = local_128;

    do {

      cVar1 = *pcVar6;

      pcVar6 = pcVar6 + 1;

      *pcVar5 = cVar1;

      pcVar5 = pcVar5 + 1;

    } while (cVar1 != '\0');

    comm_audio_volume_user(local_128,1,0,0);

  }

  if ((DAT_00632f44 != 0) && (DAT_00632f38 != DAT_005de4d0)) {

    if (DAT_00632f38 == 0) {

      pcVar6 = s_CommChgLockTeamsNo_0057e480;

    }

    else {

      pcVar6 = s_CommChgLockTeamsYes_0057e494;

    }

    pcVar6 = (char *)FUN_00507b00(pcVar6);

    pcVar5 = local_128;

    do {

      cVar1 = *pcVar6;

      pcVar6 = pcVar6 + 1;

      *pcVar5 = cVar1;

      pcVar5 = pcVar5 + 1;

    } while (cVar1 != '\0');

    comm_audio_volume_user(local_128,1,0,0);

  }

  if (DAT_00632f2c != DAT_005de4c4) {

    comm_004ce880(DAT_00632f2c * 0x3c,local_28);

    if (DAT_00632f2c < 1) {

      pcVar6 = (char *)FUN_00507b00(s_CommChgCapPrevNone_0057e45c);

      pcVar5 = local_128;

      do {

        cVar1 = *pcVar6;

        pcVar6 = pcVar6 + 1;

        *pcVar5 = cVar1;

        pcVar5 = pcVar5 + 1;

      } while (cVar1 != '\0');

    }

    else {

      uVar2 = FUN_00507b00(s_CommChgCapPrev_0057e470,local_28);

      FUN_00542f27(local_128,uVar2);

    }

    comm_audio_volume_user(local_128,1,0,0);

  }

  pcVar6 = local_128;

  pcVar5 = local_128;

  if (DAT_00632f44 != 0) {

    if (DAT_00632f24 != DAT_005de4bc) {

      uVar2 = FUN_00507b00(s_CommChgPtsKill_0057e44c,DAT_00632f24);

      FUN_00542f27(local_128,uVar2);

      comm_audio_volume_user(local_128,1,0,0);

    }

    if (DAT_00632f28 != DAT_005de4c0) {

      uVar2 = FUN_00507b00(s_CommChgPtsCap_0057e43c,DAT_00632f28);

      FUN_00542f27(local_128,uVar2);

      comm_audio_volume_user(local_128,1,0,0);

    }

    if (DAT_00632f3c != DAT_005de4d4) {

      if (DAT_00632f3c == 0) {

        uVar2 = *(undefined4 *)(DAT_00632ed8 + 0x11f4);

      }

      else if (DAT_00632f3c == 1) {

        uVar2 = *(undefined4 *)(DAT_00632ed8 + 0x11f8);

      }

      else {

        uVar2 = *(undefined4 *)(DAT_00632ed8 + 0x11fc);

      }

      uVar2 = FUN_00507b00(s_CommChgSmDiff_0057e42c,uVar2);

      FUN_00542f27(local_128,uVar2);

      comm_audio_volume_user(local_128,1,0,0);

    }

    if (DAT_00632f40 != DAT_005de4d8) {

      if (DAT_00632f40 == 0) {

        pcVar7 = s_CommDiffEasy_0057dff4;

      }

      else if (DAT_00632f40 == 1) {

        pcVar7 = s_CommDiffMedium_0057e004;

      }

      else {

        pcVar7 = s_CommDiffHard_0057e014;

      }

      uVar2 = FUN_00507b00(pcVar7);

      uVar2 = FUN_00507b00(s_CommChgVimpDiff_0057e41c,uVar2);

      FUN_00542f27(local_128,uVar2);

      comm_audio_volume_user(local_128,1,0,0);

    }

    if (DAT_00632f34 != DAT_005de4cc) {

      uVar2 = FUN_00507b00(s_CommChgMaxPlayers_0057e408,DAT_00632f34);

      FUN_00542f27(local_128,uVar2);

      comm_audio_volume_user(local_128,1,0,0);

    }

    iVar3 = FUN_00545650(&DAT_00632f48,&DAT_005de4e0);

    if (iVar3 != 0) {

      uVar2 = FUN_00507b00(s_CommChgSessName_0057e3f8,&DAT_00632f48);

      FUN_00542f27(local_128,uVar2);

      comm_audio_volume_user(local_128,1,0,0);

    }

    if (DAT_00632fcc != DAT_005de564) {

      comm_004ce880(DAT_00632fcc * 0x3c,local_28);

      if (DAT_00632fcc == 0) {

        puVar4 = (undefined1 *)FUN_00507b00(s_ButtonNone_0057df64);

      }

      else {

        puVar4 = local_28;

      }

      uVar2 = FUN_00507b00(s_CommChgTimeLimit_0057e3e4,puVar4);

      FUN_00542f27(local_128,uVar2);

      comm_audio_volume_user(local_128,1,0,0);

    }

    if (DAT_00632fdc != DAT_005de574) {

      uVar2 = FUN_00507b00(s_CommChgPScoreLimit_0057e3d0,DAT_00632fdc);

      FUN_00542f27(local_128,uVar2);

      comm_audio_volume_user(local_128,1,0,0);

    }

    if (DAT_00632fec != DAT_005de584) {

      uVar2 = FUN_00507b00(s_CommChgTScoreLimit_0057e3bc,DAT_00632fec);

      FUN_00542f27(local_128,uVar2);

      comm_audio_volume_user(local_128,1,0,0);

    }

    if (DAT_00632ff0 != DAT_005de588) {

      if ((DAT_00632f18 == 6) || (DAT_00632f18 == 7)) {

        if (DAT_00632ff0 == 0) {

          pcVar5 = s_CommChgBaseDestroyNo_0057e38c;

        }

        else {

          pcVar5 = s_CommChgBaseDestroyYes_0057e3a4;

        }

        pcVar5 = (char *)FUN_00507b00(pcVar5);

        do {

          cVar1 = *pcVar5;

          pcVar5 = pcVar5 + 1;

          *pcVar6 = cVar1;

          pcVar6 = pcVar6 + 1;

        } while (cVar1 != '\0');

      }

      else {

        if (DAT_00632ff0 == 0) {

          pcVar6 = s_CommChgBaseCompleteNo_0057e35c;

        }

        else {

          pcVar6 = s_CommChgBaseCompleteYes_0057e374;

        }

        pcVar6 = (char *)FUN_00507b00(pcVar6);

        do {

          cVar1 = *pcVar6;

          pcVar6 = pcVar6 + 1;

          *pcVar5 = cVar1;

          pcVar5 = pcVar5 + 1;

        } while (cVar1 != '\0');

      }

      comm_audio_volume_user(local_128,1,0,0);

    }

  }

  return;

}

/* ===== FUN_00529b20 @ 0x00529B20 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_00529b20(void)



{

  int iVar1;

  undefined4 *puVar2;

  

  puVar2 = &DAT_005ddee8;

  for (iVar1 = 0x14; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar2 = 0;

    puVar2 = puVar2 + 1;

  }

  puVar2 = &DAT_005ddf60;

  for (iVar1 = 0x14; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar2 = 0;

    puVar2 = puVar2 + 1;

  }

  _DAT_005de2a4 = 0;

  _DAT_005de2a8 = 0;

  _DAT_005de2ac = 0;

  _DAT_005de2b0 = 0;

  _DAT_005de2b4 = 0;

  _DAT_005de290 = 0;

  _DAT_005de294 = 0;

  _DAT_005de298 = 0;

  _DAT_005de29c = 0;

  puVar2 = (undefined4 *)&DAT_005ddfc0;

  for (iVar1 = 0xa0; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar2 = 0;

    puVar2 = puVar2 + 1;

  }

  puVar2 = &DAT_005ddd48;

  for (iVar1 = 0x14; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar2 = 0;

    puVar2 = puVar2 + 1;

  }

  puVar2 = &DAT_005dde40;

  for (iVar1 = 0x2a; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar2 = 0;

    puVar2 = puVar2 + 1;

  }

  puVar2 = &DAT_005ddda0;

  for (iVar1 = 0x14; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar2 = 0;

    puVar2 = puVar2 + 1;

  }

  _DAT_005ddf38 = 0;

  puVar2 = &DAT_005dddf0;

  for (iVar1 = 0x14; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar2 = 0;

    puVar2 = puVar2 + 1;

  }

  _DAT_005ddf3c = 0;

  _DAT_005de2a0 = 0;

  _DAT_005ddf40 = 0;

  _DAT_005de284 = 0;

  _DAT_005ddd3c = 0;

  DAT_005ddd40 = 0;

  _DAT_005ddf44 = 0;

  DAT_005de288 = 0;

  _DAT_005ddf48 = 0;

  _DAT_005de28c = 0;

  _DAT_005ddd44 = 0;

  _DAT_005def54 = 0;

  return;

}

/* ===== FUN_00529C00 @ 0x00529C00 ===== */
void FUN_00529C00(uint *param_1,uint *param_2,uint *param_3,uint *param_4)



{

  int iVar1;

  uint uVar2;

  uint uVar3;

  

  *param_1 = ((DAT_00632f0c << 8 | DAT_00632f10) << 8 | DAT_00632f18) << 8;

  iVar1 = FUN_004B09C0(DAT_00632ee4);

  if (iVar1 == 0) {

    uVar2 = *param_1 | 0xff;

  }

  else {

    uVar2 = *param_1 | DAT_00632ee4;

  }

  *param_1 = uVar2;

  *param_2 = 0;

  if (DAT_00632f1c != 0) {

    *param_2 = 0x80000000;

  }

  if (DAT_00632f20 != 0) {

    *param_2 = *param_2 | 0x40000000;

  }

  if (DAT_00632f38 != 0) {

    *param_2 = *param_2 | 0x20000000;

  }

  if (DAT_00633238 != 0) {

    *param_2 = *param_2 | 0x10000000;

  }

  uVar2 = *param_2 | (DAT_00632f3c & 0xf) << 0x14;

  *param_2 = uVar2;

  uVar2 = (DAT_00632f40 & 0xf) << 0x10 | uVar2;

  *param_2 = uVar2;

  *param_2 = DAT_00633038 & 0xffff | uVar2;

  *param_3 = DAT_00632f28 & 0xffff ^ DAT_00632f24 << 0x10;

  uVar3 = DAT_00632f2c << 0x10;

  uVar2 = __ftol();

  *param_4 = uVar2 & 0xffff ^ uVar3;

  return;

}

/* ===== FUN_00529d10 @ 0x00529D10 ===== */
void FUN_00529d10(uint param_1,uint param_2,uint param_3,uint param_4)



{

  DAT_00632f0c = param_1 >> 0x18;

  DAT_00632ee4 = param_1 & 0xff;

  DAT_00632f10 = param_1 >> 0x10 & 0xff;

  DAT_00632f18 = param_1 >> 8 & 0xff;

  if (DAT_00632ee4 == 0xff) {

    DAT_00632ee4 = 0xffffffff;

  }

  DAT_00632f1c = param_2 >> 0x1f;

  DAT_00632f20 = param_2 >> 0x1e & 1;

  DAT_00632f38 = param_2 >> 0x1d & 1;

  DAT_00633238 = param_2 >> 0x1c & 1;

  DAT_00633038 = param_2 & 0xffff;

  DAT_00632f3c = param_2 >> 0x14 & 0xf;

  DAT_00632f28 = param_3 & 0xffff;

  DAT_00632f40 = param_2 >> 0x10 & 0xf;

  DAT_00632f24 = param_3 >> 0x10;

  DAT_00632f2c = param_4 >> 0x10;

  DAT_00632f30 = (float)(param_4 & 0xffff);

  return;

}

/* ===== FUN_0052a050 @ 0x0052A050 ===== */
/* PS2 candidate: showchat_mission_objective__Fi (conf 0.333) */



void FUN_0052a050(int param_1)



{

  char cVar1;

  undefined4 *puVar2;

  byte bVar3;

  undefined4 uVar4;

  int iVar5;

  char *pcVar6;

  char *pcVar7;

  int iVar8;

  undefined4 *puVar9;

  undefined4 *puVar10;

  char local_4c4 [128];

  CHAR local_444 [127];

  undefined1 local_3c5;

  undefined4 local_3c4 [113];

  int local_200;

  int local_1d8;

  int local_1d4;

  int local_1cc;

  int local_1c8;

  int local_1c4;

  int local_1c0;

  int local_1bc;

  int local_1b8;

  int local_1ac;

  int local_1a8;

  int local_1a4;

  int local_ac;

  

  puVar2 = *(undefined4 **)(param_1 + 0x40);

  if (puVar2 != (undefined4 *)0x0) {

    uVar4 = puVar2[2];

    puVar9 = &DAT_00632d20;

    puVar10 = local_3c4;

    for (iVar8 = 0xf1; iVar8 != 0; iVar8 = iVar8 + -1) {

      *puVar10 = *puVar9;

      puVar9 = puVar9 + 1;

      puVar10 = puVar10 + 1;

    }

    FUN_00529d10(*puVar2,puVar2[1],uVar4,puVar2[3]);

    iVar8 = DAT_00632f0c;

    if (DAT_00632f0c != local_1d8) {

      if (((DAT_005def80 != 5) || (DAT_00632f44 != 0)) && (DAT_00632f08 == 2)) {

        comm_0051a130(s_GameBaseLevel_0055a024,DAT_00632f0c);

      }

      if (DAT_005def8c != 0) {

        main_dlog_00427230(DAT_005def8c,0x132);

        FUN_00542f27(local_4c4,s_BaseLevel_s_0057dfc8,(&PTR_DAT_0057dc8c)[iVar8]);

        uVar4 = TextGetPtrQ(local_4c4);

        main_dlog_00427890(DAT_005def8c,0x132,DAT_0057dc9c,0x41400000,0x81000002,uVar4);

        iVar8 = comm_00426540();

        if (iVar8 == 0) {

          if (((DAT_005def80 == 5) && (DAT_00632f44 == 0)) || (DAT_00632f08 != 2)) {

            bVar3 = 0;

          }

          else {

            bVar3 = 1;

          }

          iVar8 = (-(uint)bVar3 & 0x282792) + 0xa0a0a0;

        }

        else {

          iVar8 = 0xa0a0a0;

        }

        comm_00427860(DAT_005def8c,0x132,iVar8);

      }

    }

    if (DAT_00632f10 != local_1d4) {

      comm_00521620(DAT_00632f10);

    }

    iVar8 = DAT_00632ee4;

    if ((DAT_00632ee4 != local_200) && (uVar4 = 0x81000002, DAT_005def8c != 0)) {

      iVar5 = comm_worldname_menu(DAT_00632ee4,local_4c4);

      if (iVar5 == 0) {

        uVar4 = 0x8100000a;

      }

      main_dlog_00427230(DAT_005def8c,0x134);

      main_dlog_00427890(DAT_005def8c,0x134,DAT_0057dc9c,0x41400000,uVar4,local_4c4);

      iVar5 = comm_00426540();

      if (iVar5 == 0) {

        if (((DAT_005def80 == 5) && (DAT_00632f44 == 0)) || (DAT_00632f08 != 2)) {

          bVar3 = 0;

        }

        else {

          bVar3 = 1;

        }

        iVar5 = (-(uint)bVar3 & 0x282792) + 0xa0a0a0;

      }

      else {

        iVar5 = 0xa0a0a0;

      }

      comm_00427860(DAT_005def8c,0x134,iVar5);

      if (((iVar8 < 0) && (DAT_005def8c != 0)) && (DAT_005de67c != 0)) {

        DAT_005de67c = 0;

        main_dlog_00427230(DAT_005def8c,1);

      }

    }

    iVar8 = DAT_00632f18;

    if (DAT_00632f18 != local_1cc) {

      if (((DAT_005def80 != 5) || (DAT_00632f44 != 0)) && (DAT_00632f08 == 2)) {

        comm_0051a130(s_GameType_0055a00c,DAT_00632f18);

      }

      if (DAT_005def8c != 0) {

        main_dlog_00427230(DAT_005def8c,0x12e);

        comm_gtype_name(iVar8,local_4c4);

        main_dlog_00427890(DAT_005def8c,0x12e,DAT_0057dc9c,0x41200000,0x81000002,local_4c4);

        iVar8 = comm_00426540();

        if (iVar8 == 0) {

          if (((DAT_005def80 == 5) && (DAT_00632f44 == 0)) || (DAT_00632f08 != 2)) {

            bVar3 = 0;

          }

          else {

            bVar3 = 1;

          }

          comm_00427860(DAT_005def8c,0x12e,(-(uint)bVar3 & 0x282792) + 0xa0a0a0);

        }

        else {

          comm_00427860(DAT_005def8c,0x12e,0xa0a0a0);

        }

      }

    }

    iVar8 = DAT_00632f1c;

    if (DAT_00632f1c != local_1c8) {

      if (((DAT_005def80 != 5) || (DAT_00632f44 != 0)) && (1 < DAT_00632f08)) {

        comm_0051a130(s_AllowJoiners_00559ffc,DAT_00632f1c);

      }

      if (DAT_005def8c != 0) {

        pcVar6 = s_ButtonYes_0057df7c;

        if (iVar8 == 0) {

          pcVar6 = s_ButtonNo_0057df70;

        }

        uVar4 = FUN_00507b00(pcVar6);

        main_dlog_00427230(DAT_005def8c,0x192);

        main_dlog_00427890(DAT_005def8c,0x192,DAT_0057dc98,0x41800000,0x81000002,uVar4);

        comm_00427860(DAT_005def8c,0x192,0xa0a0a0);

      }

    }

    iVar8 = DAT_00632f20;

    if (DAT_00632f20 != local_1c4) {

      if (((DAT_005def80 != 5) || (DAT_00632f44 != 0)) && (1 < DAT_00632f08)) {

        comm_0051a130(s_DamageTeammates_00559fec,DAT_00632f20);

      }

      if (DAT_005def8c != 0) {

        pcVar6 = s_ButtonYes_0057df7c;

        if (iVar8 == 0) {

          pcVar6 = s_ButtonNo_0057df70;

        }

        uVar4 = FUN_00507b00(pcVar6);

        main_dlog_00427230(DAT_005def8c,0x194);

        main_dlog_00427890(DAT_005def8c,0x194,DAT_0057dc98,0x41900000,0x81000002,uVar4);

        if ((((DAT_005def80 == 5) && (DAT_00632f44 == 0)) || (DAT_00632f08 < 2)) &&

           ((DAT_005def94 != DAT_005def5c || (DAT_00632f08 < 2)))) {

          uVar4 = 0xa0a0a0;

        }

        else {

          uVar4 = 0xc8c832;

        }

        comm_00427860(DAT_005def8c,0x194,uVar4);

      }

    }

    iVar8 = DAT_00632f38;

    if (DAT_00632f38 != local_1ac) {

      if (((DAT_005def80 != 5) || (DAT_00632f44 != 0)) && (1 < DAT_00632f08)) {

        comm_0051a130(s_LockTeams_00559fe0,DAT_00632f38);

      }

      if (DAT_005def8c != 0) {

        pcVar6 = s_ButtonNo_0057df70;

        if (iVar8 == 0) {

          pcVar6 = s_ButtonYes_0057df7c;

        }

        uVar4 = FUN_00507b00(pcVar6);

        main_dlog_00427230(DAT_005def8c,0x19e);

        main_dlog_00427890(DAT_005def8c,0x19e,DAT_0057dc98,0x41880000,0x81000002,uVar4);

        if (((DAT_005def80 == 5) && (DAT_00632f44 == 0)) || (DAT_00632f08 < 2)) {

          bVar3 = 0;

        }

        else {

          bVar3 = 1;

        }

        comm_00427860(DAT_005def8c,0x19e,(-(uint)bVar3 & 0x282792) + 0xa0a0a0);

      }

    }

    iVar8 = DAT_00632f2c;

    if (DAT_00632f2c != local_1b8) {

      if (((DAT_005def80 != 5) || (DAT_00632f44 != 0)) && (1 < DAT_00632f08)) {

        comm_0051a130(s_CapturePreventTime_00559fa8,DAT_00632f2c);

      }

      if (DAT_005def8c != 0) {

        if (iVar8 == 0) {

          pcVar7 = (char *)FUN_00507b00(s_ButtonNone_0057df64);

          pcVar6 = local_4c4;

          do {

            cVar1 = *pcVar7;

            pcVar7 = pcVar7 + 1;

            *pcVar6 = cVar1;

            pcVar6 = pcVar6 + 1;

          } while (cVar1 != '\0');

        }

        else {

          comm_004ce880(iVar8 * 0x3c,local_4c4);

        }

        main_dlog_00427230(DAT_005def8c,0x19a);

        main_dlog_00427890(DAT_005def8c,0x19a,DAT_0057dc98,0x41a80000,0x81000002,local_4c4);

        if ((((DAT_005def80 == 5) && (DAT_00632f44 == 0)) || (DAT_00632f08 < 2)) &&

           ((DAT_005def94 != DAT_005def5c || (DAT_00632f08 < 2)))) {

          uVar4 = 0xa0a0a0;

        }

        else {

          uVar4 = 0xc8c832;

        }

        comm_00427860(DAT_005def8c,0x19a,uVar4);

      }

    }

    iVar8 = DAT_00632f24;

    if (DAT_00632f24 != local_1c0) {

      if (((DAT_005def80 != 5) || (DAT_00632f44 != 0)) && (1 < DAT_00632f08)) {

        comm_0051a130(s_PointsPerKill_00559fd0,DAT_00632f24);

      }

      if (DAT_005def8c != 0) {

        if (iVar8 == 0) {

          pcVar7 = (char *)FUN_00507b00(s_ButtonNone_0057df64);

          pcVar6 = local_4c4;

          do {

            cVar1 = *pcVar7;

            pcVar7 = pcVar7 + 1;

            *pcVar6 = cVar1;

            pcVar6 = pcVar6 + 1;

          } while (cVar1 != '\0');

        }

        else {

          FUN_00542f27(local_4c4,&DAT_00557088,iVar8);

        }

        main_dlog_00427230(DAT_005def8c,0x196);

        main_dlog_00427890(DAT_005def8c,0x196,DAT_0057dc98,0x41980000,0x81000002,local_4c4);

        if (((DAT_005def80 == 5) && (DAT_00632f44 == 0)) || (DAT_00632f08 < 2)) {

          bVar3 = 0;

        }

        else {

          bVar3 = 1;

        }

        comm_00427860(DAT_005def8c,0x196,(-(uint)bVar3 & 0x282792) + 0xa0a0a0);

      }

    }

    if (DAT_00632f28 != local_1bc) {

      if (((DAT_00632f18 == 2) || (DAT_00632f18 == 3)) ||

         ((DAT_00632f18 == 5 || (DAT_00632f18 == 7)))) {

        uVar4 = 1;

      }

      else {

        uVar4 = 0;

      }

      comm_capture_points_menu(DAT_00632f28,uVar4);

    }

    if (DAT_00632f3c != local_1a8) {

      comm_smartie_diff_dlog(DAT_00632f3c);

    }

    if (DAT_00632f40 != local_1a4) {

      comm_difficulty_menu(DAT_00632f40);

    }

    if (DAT_00633038 != local_ac) {

      comm_version_check(DAT_00633038);

    }

    iVar8 = *(int *)(param_1 + 0x28);

    if (DAT_00632f34 != iVar8) {

      DAT_00632f34 = iVar8;

      if (iVar8 == 0) {

        DAT_00632f34 = 0x14;

      }

      comm_maxplayers_dlog(DAT_00632f34);

    }

    if (*(LPCWSTR *)(param_1 + 0x30) != (LPCWSTR)0x0) {

      WideCharToMultiByte(0,0,*(LPCWSTR *)(param_1 + 0x30),-1,local_444,0x80,(LPCSTR)0x0,(LPBOOL)0x0

                         );

      local_3c5 = 0;

      iVar8 = crt_file_lock_ops(&DAT_00632f48,local_444,0x20);

      if (iVar8 != 0) {

        _strncpy(&DAT_00632f48,local_444,0x20);

        DAT_00632f67 = 0;

        comm_session_menu(&DAT_00632f48,0);

      }

    }

  }

  return;

}

/* ===== comm_server_heartbeat @ 0x0052A940 ===== */
int comm_server_heartbeat(int param_1)



{

  int iVar1;

  char *pcVar2;

  int iVar3;

  char local_100 [256];

  

  iVar3 = -1;

  iVar1 = 0;

  if (0 < DAT_00632f34) {

    do {

      if ((&DAT_005ddf60)[iVar1] == param_1) {

        if (iVar1 < DAT_00632f34) {

          return -1;

        }

        break;

      }

      if ((iVar3 == -1) && ((&DAT_005ddf60)[iVar1] == 0)) {

        iVar3 = iVar1;

      }

      iVar1 = iVar1 + 1;

    } while (iVar1 < DAT_00632f34);

    if (-1 < iVar3) {

      if (iVar3 == 0) {

        DAT_005def5c = param_1;

        DAT_005ddfb4 = param_1;

        if (DAT_00633238 == 0) {

          _strncpy(&DAT_005ddfc0,&DAT_0063304c,0x20);

          DAT_005ddfdf = 0;

        }

        else {

          pcVar2 = (char *)FUN_00507b00(s_CommServer_0057ea48);

          _strncpy(&DAT_005ddfc0,pcVar2,0x20);

          DAT_005ddfdf = 0;

        }

      }

      else {

        iVar1 = comm_comm_0052acc0(param_1,local_100,0x100);

        if (iVar1 == 0) {

          pcVar2 = s___wtf___0057ea40;

        }

        else {

          pcVar2 = local_100;

        }

        _strncpy(&DAT_005ddfc0 + iVar3 * 0x20,pcVar2,0x20);

        (&DAT_005ddfdf)[iVar3 * 0x20] = 0;

      }

      (&DAT_005de2a4)[iVar3] = 0;

      (&DAT_005dddf0)[iVar3] = 0;

      (&DAT_005ddda0)[iVar3] = 0;

      (&DAT_005ddf60)[iVar3] = param_1;

      (&DAT_005de290)[iVar3] = 1;

      (&DAT_005de6dc)[iVar3 * 0x1c] = 0;

      return iVar3;

    }

  }

  return -1;

}

/* ===== FUN_0052aa70 @ 0x0052AA70 ===== */
/* PS2 candidate: hurt_object (conf 0.621) */



bool FUN_0052aa70(void)



{

  return DAT_005def80 == 5;

}

/* ===== FUN_0052aa80 @ 0x0052AA80 ===== */
bool FUN_0052aa80(int param_1)



{

  int iVar1;

  

  if (DAT_005def80 != 5) {

    return true;

  }

  iVar1 = 0;

  if (0 < DAT_00632f34) {

    do {

      if ((&DAT_005ddf60)[iVar1] == DAT_005def5c) {

        if (iVar1 < DAT_00632f34) goto LAB_0052aab8;

        break;

      }

      iVar1 = iVar1 + 1;

    } while (iVar1 < DAT_00632f34);

  }

  iVar1 = DAT_00632f34 + -1;

LAB_0052aab8:

  return (char)*(undefined4 *)(param_1 + 0x188) == (char)iVar1;

}

/* ===== AudioGetMasterVolume__Fv_9 @ 0x0052AAD0 ===== */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */



undefined4 AudioGetMasterVolume__Fv_9(void)



{

  return DAT_005def5c;

}

/* ===== FUN_0052aae0 @ 0x0052AAE0 ===== */
void FUN_0052aae0(int param_1)



{

  if (param_1 != 0) {

    DAT_005def5c = param_1;

  }

  return;

}

/* ===== AudioGetMasterVolume__Fv_10 @ 0x0052AAF0 ===== */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */



undefined4 AudioGetMasterVolume__Fv_10(void)



{

  return DAT_005ddfb4;

}

/* ===== FUN_0052ab00 @ 0x0052AB00 ===== */
undefined4 FUN_0052ab00(int param_1)



{

  if (param_1 < 0) {

    return 0;

  }

  return (&DAT_005ddf60)[param_1];

}

/* ===== comm_0052ab20 @ 0x0052AB20 ===== */
int comm_0052ab20(int param_1)



{

  int iVar1;

  

  iVar1 = 0;

  if (0 < DAT_00632f34) {

    do {

      if ((&DAT_005ddf60)[iVar1] == param_1) {

        return iVar1;

      }

      iVar1 = iVar1 + 1;

    } while (iVar1 < DAT_00632f34);

  }

  return -1;

}

/* ===== comm_0052ab50 @ 0x0052AB50 ===== */
undefined1 comm_0052ab50(int param_1)



{

  if (param_1 < 0) {

    return 0;

  }

  return (&DAT_005de2a4)[param_1];

}

/* ===== FUN_0052ab70 @ 0x0052AB70 ===== */
/* PS2 candidate: ObjectGetWorldRefPoint__FP3P3DiP6OBJECT_2 (conf 0.675) */



void FUN_0052ab70(int param_1,undefined1 param_2)



{

  if (-1 < param_1) {

    (&DAT_005de2a4)[param_1] = param_2;

  }

  return;

}

/* ===== comm_team_name2 @ 0x0052AB90 ===== */
void comm_team_name2(undefined4 param_1)



{

  char *pcVar1;

  undefined1 local_28 [40];

  

  switch(DAT_00632f10) {

  case 0:

  case 1:

    pcVar1 = s_CommTeamNo_d_0057dfe4;

    break;

  case 2:

  case 3:

  case 4:

  case 5:

    pcVar1 = s_CommTeamNo_dA_0057dfd4;

    break;

  default:

    goto switchD_0052ab9d_default;

  }

  FUN_00542f27(local_28,pcVar1,param_1);

switchD_0052ab9d_default:

  FUN_00507b00(local_28);

  return;

}

/* ===== FUN_0052ac00 @ 0x0052AC00 ===== */
int FUN_0052ac00(int param_1)



{

  if (param_1 == 1) {

    return 0x70ff;

  }

  if (param_1 == 2) {

    return 0x20ff20;

  }

  return ((param_1 != 3) - 1 & 0xffff3051) + 0xffffff;

}

/* ===== FUN_0052ac40 @ 0x0052AC40 ===== */
undefined1 FUN_0052ac40(int param_1)



{

  if ((-1 < param_1) && (param_1 < 0x14)) {

    return (&DAT_005de290)[param_1];

  }

  return 0;

}

/* ===== comm_0052ac60 @ 0x0052AC60 ===== */
void comm_0052ac60(int param_1,undefined1 param_2)



{

  if ((-1 < param_1) && (param_1 < 0x14)) {

    (&DAT_005de290)[param_1] = param_2;

  }

  return;

}

/* ===== FUN_0052ac80 @ 0x0052AC80 ===== */
void FUN_0052ac80(int param_1,undefined1 param_2)



{

  if ((-1 < param_1) && (param_1 < 0x14)) {

    (&DAT_005ddf38)[param_1] = param_2;

  }

  return;

}

/* ===== FUN_0052aca0 @ 0x0052ACA0 ===== */
undefined1 FUN_0052aca0(int param_1)



{

  if ((-1 < param_1) && (param_1 < 0x14)) {

    return (&DAT_005ddf38)[param_1];

  }

  return 0;

}

/* ===== FUN_0052adc0 @ 0x0052ADC0 ===== */
/* PS2 candidate: ObjectGetWorldRefPoint__FP3P3DiP6OBJECT_3 (conf 0.643) */



void FUN_0052adc0(int param_1,char *param_2)



{

  if (-1 < param_1) {

    _strncpy(&DAT_005ddfc0 + param_1 * 0x20,param_2,0x20);

    (&DAT_005ddfdf)[param_1 * 0x20] = 0;

  }

  return;

}

/* ===== comm_player_name3 @ 0x0052ADF0 ===== */
/* PS2 candidate: smartie_check_follow__FP6OBJECTf (conf 0.598) */



char * comm_player_name3(int param_1)



{

  char *_Dest;

  int iVar1;

  undefined4 uVar2;

  char local_100 [256];

  

  if (param_1 < 0) {

    return &DAT_005561ac;

  }

  _Dest = &DAT_005ddfc0 + param_1 * 0x20;

  if (*_Dest == '\0') {

    if (DAT_00632f44 != 0) {

      iVar1 = comm_comm_0052acc0((&DAT_005ddf60)[param_1],local_100,0x100);

      if (iVar1 != 0) {

        _strncpy(_Dest,local_100,0x20);

        (&DAT_005ddfdf)[param_1 * 0x20] = 0;

      }

    }

    if (*_Dest == '\0') {

      uVar2 = FUN_00507b00(s_CommUnnamedPlayer_0057df98,param_1);

      FUN_00542f27(_Dest,s__s__d_00555f38,uVar2);

    }

  }

  return _Dest;

}

/* ===== FUN_0052ae90 @ 0x0052AE90 ===== */
void FUN_0052ae90(int param_1)



{

  int iVar1;

  undefined4 *puVar2;

  

  if (-1 < param_1) {

    puVar2 = (undefined4 *)(&DAT_005ddfc0 + param_1 * 0x20);

    for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {

      *puVar2 = 0;

      puVar2 = puVar2 + 1;

    }

    (&DAT_005de290)[param_1] = 0;

    (&DAT_005de2a4)[param_1] = 0;

    (&DAT_005ddf60)[param_1] = 0;

  }

  return;

}

/* ===== comm_player_name4 @ 0x0052AED0 ===== */
/* WARNING: Removing unreachable block (ram,0x0052aee9) */



char * comm_player_name4(int param_1)



{

  char *_Dest;

  int iVar1;

  undefined4 uVar2;

  int iVar3;

  uint uVar4;

  char local_100 [256];

  

  uVar4 = *(uint *)(param_1 + 0x188) & 0xff;

  iVar3 = uVar4 * 0x20;

  _Dest = &DAT_005ddfc0 + iVar3;

  if ((&DAT_005ddfc0)[iVar3] == '\0') {

    if ((DAT_00632f44 != 0) &&

       (iVar1 = comm_comm_0052acc0((&DAT_005ddf60)[uVar4],local_100,0x100), iVar1 != 0)) {

      _strncpy(_Dest,local_100,0x20);

      (&DAT_005ddfdf)[iVar3] = 0;

    }

    if (*_Dest == '\0') {

      uVar2 = FUN_00507b00(s_CommUnnamedPlayer_0057df98,uVar4);

      FUN_00542f27(_Dest,s__s__d_00555f38,uVar2);

    }

  }

  return _Dest;

}

/* ===== FUN_0052af80 @ 0x0052AF80 ===== */
float10 FUN_0052af80(int param_1)



{

  if ((0 < param_1) && (param_1 < 4)) {

    return (float10)*(float *)(&DAT_005de280 + param_1 * 4);

  }

  return (float10)0.0;

}

/* ===== FUN_0052afa0 @ 0x0052AFA0 ===== */
float10 FUN_0052afa0(int param_1)



{

  if ((0 < param_1) && (param_1 < 4)) {

    return (float10)(float)(&DAT_005ddd38)[param_1];

  }

  return (float10)0.0;

}

/* ===== FUN_0052afc0 @ 0x0052AFC0 ===== */
float10 FUN_0052afc0(int param_1)



{

  if (param_1 < 0) {

    return (float10)0.0;

  }

  return (float10)(float)(&DAT_005ddda0)[param_1];

}

/* ===== FUN_0052afe0 @ 0x0052AFE0 ===== */
float10 FUN_0052afe0(int param_1)



{

  if (param_1 < 0) {

    return (float10)0.0;

  }

  return (float10)(float)(&DAT_005dddf0)[param_1];

}

/* ===== FUN_0052b000 @ 0x0052B000 ===== */
void FUN_0052b000(int param_1)



{

  if (-1 < param_1) {

    *(float *)(&DAT_005de6ec + param_1 * 0x70) = DAT_006328e8 + 60.0;

  }

  return;

}

/* ===== comm_chatlog_write @ 0x0052B020 ===== */
void comm_chatlog_write(void)



{

  uint uVar1;

  int iVar2;

  int iVar3;

  char *pcVar4;

  undefined4 uVar5;

  char *_Dest;

  int iVar6;

  int *piVar7;

  char acStack_108 [260];

  

  if (DAT_005def80 == 5) {

    iVar6 = 1;

    _Dest = &DAT_005ddfe0;

    piVar7 = &DAT_005de74c;

    do {

      uVar1 = (&DAT_005ddf60)[iVar6];

      if (((uVar1 != 0) && (0xd < (byte)(&DAT_005de290)[iVar6])) &&

         (15.0 <= DAT_006328e8 - (float)piVar7[4])) {

        iVar2 = *piVar7;

        piVar7[4] = (int)DAT_006328e8;

        iVar3 = piVar7[1];

        *piVar7 = iVar3;

        if ((99 < iVar3) && (iVar2 <= iVar3)) {

          if ((DAT_005def80 == 5) && (DAT_00632f44 == 0)) {

            comm_audio_vol_a(((int)piVar7 < 0x5de6dc) - 1 & uVar1);

          }

          else if ((((int)piVar7 < 0x5de6dc) - 1 & uVar1) != DAT_005def5c) {

            FUN_0052f6e0(iVar6);

            if ((int)piVar7 < 0x5de6dc) {

              uVar5 = 0;

            }

            else {

              uVar5 = (&DAT_005ddf60)[iVar6];

            }

            if (DAT_00632f44 != 0) {

              (**(code **)(*DAT_005def60 + 0x60))(DAT_005def60,uVar5,0,0,0);

            }

          }

          if ((DAT_00633240 != 0) &&

             (iVar2 = BinFileSeek_2(s_chatlog_txt_0055e874,&DAT_00556384), iVar2 != 0)) {

            if ((int)piVar7 < 0x5de6dc) {

              pcVar4 = &DAT_005561ac;

            }

            else {

              pcVar4 = _Dest;

              if (*_Dest == '\0') {

                if ((DAT_00632f44 != 0) && (iVar3 = comm_comm_0052acc0(), iVar3 != 0)) {

                  _strncpy(_Dest,acStack_108,0x20);

                  _Dest[0x1f] = '\0';

                }

                if (*_Dest == '\0') {

                  uVar5 = FUN_00507b00(s_CommUnnamedPlayer_0057df98,iVar6);

                  FUN_00542f27(_Dest,s__s__d_00555f38,uVar5);

                }

              }

            }

            crt_file_free_init(iVar2,s_____________Time__5_2f__player___0057ead8,

                               (double)DAT_006328e8,iVar6,pcVar4);

            editor_0054384c(iVar2);

          }

        }

      }

      piVar7 = piVar7 + 0x1c;

      iVar6 = iVar6 + 1;

      _Dest = _Dest + 0x20;

    } while ((int)piVar7 < 0x5def9c);

  }

  return;

}

/* ===== FUN_0052b200 @ 0x0052B200 ===== */
void FUN_0052b200(int param_1,undefined4 param_2)



{

  if ((0 < param_1) && (param_1 < 4)) {

    *(undefined4 *)(&DAT_005de280 + param_1 * 4) = param_2;

  }

  return;

}

/* ===== FUN_0052b220 @ 0x0052B220 ===== */
void FUN_0052b220(int param_1,undefined4 param_2)



{

  if ((0 < param_1) && (param_1 < 4)) {

    (&DAT_005ddd38)[param_1] = param_2;

  }

  return;

}

/* ===== FUN_0052b240 @ 0x0052B240 ===== */
void FUN_0052b240(int param_1,undefined4 param_2)



{

  if ((-1 < param_1) && (param_1 < DAT_00632f34)) {

    (&DAT_005ddda0)[param_1] = param_2;

  }

  return;

}

/* ===== FUN_0052b260 @ 0x0052B260 ===== */
void FUN_0052b260(int param_1,undefined4 param_2)



{

  if ((-1 < param_1) && (param_1 < DAT_00632f34)) {

    (&DAT_005dddf0)[param_1] = param_2;

  }

  return;

}

/* ===== FUN_0052b280 @ 0x0052B280 ===== */
void FUN_0052b280(int param_1,int param_2)



{

  ushort uVar1;

  int iVar2;

  undefined4 *puVar3;

  undefined4 *puVar4;

  undefined4 uStack_68;

  undefined4 local_5c [23];

  

  iVar2 = 0;

  if (0 < param_1) {

    do {

      uVar1 = *(ushort *)(param_2 + iVar2 * 2);

      (&DAT_005ddee8)[iVar2] = (uint)uVar1;

      if (999 < uVar1) {

        (&DAT_005ddee8)[iVar2] = 999;

      }

      if ((int)(&DAT_005ddee8)[iVar2] < 0) {

        (&DAT_005ddee8)[iVar2] = 0;

      }

      iVar2 = iVar2 + 1;

    } while (iVar2 < param_1);

  }

  if (DAT_00632f44 == 0) {

    uStack_68 = 0;

    puVar3 = local_5c;

    for (iVar2 = 0x17; iVar2 != 0; iVar2 = iVar2 + -1) {

      *puVar3 = 0;

      puVar3 = puVar3 + 1;

    }

    local_5c[0] = 0x5c;

    iVar2 = (**(code **)(*DAT_005def64 + 0x50))(DAT_005def64,local_5c);

    if (-1 < iVar2) {

      puVar3 = &uStack_68;

      puVar4 = &DAT_005de680;

      for (iVar2 = 0x17; iVar2 != 0; iVar2 = iVar2 + -1) {

        *puVar4 = *puVar3;

        puVar3 = puVar3 + 1;

        puVar4 = puVar4 + 1;

      }

    }

  }

  return;

}

/* ===== FUN_0052b320 @ 0x0052B320 ===== */
int FUN_0052b320(int param_1)



{

  int iVar1;

  int iVar2;

  int iVar3;

  uint *puVar4;

  int iVar5;

  uint *puVar6;

  int local_60;

  uint local_5c [23];

  

  local_60 = 0;

  iVar3 = 0;

  do {

    iVar2 = (&DAT_005ddf60)[iVar3];

    if (((iVar2 != 0) && (0 < iVar3)) && (DAT_00632f44 != 0)) {

      puVar4 = local_5c;

      for (iVar1 = 0x17; iVar1 != 0; iVar1 = iVar1 + -1) {

        *puVar4 = 0;

        puVar4 = puVar4 + 1;

      }

      local_5c[0] = 0x5c;

      iVar1 = (**(code **)(*DAT_005def60 + 0x80))(DAT_005def60,iVar2,local_5c,0);

      iVar5 = 0;

      if (0 < DAT_00632f34) {

        do {

          if ((&DAT_005ddf60)[iVar5] == iVar2) {

            if (-1 < iVar5) {

              (&DAT_005ddee8)[iVar5] = (iVar1 < 0) - 1 & local_5c[1];

              puVar4 = local_5c;

              puVar6 = &DAT_005de680 + iVar5 * 0x1c;

              for (iVar2 = 0x17; iVar2 != 0; iVar2 = iVar2 + -1) {

                *puVar6 = *puVar4;

                puVar4 = puVar4 + 1;

                puVar6 = puVar6 + 1;

              }

            }

            break;

          }

          iVar5 = iVar5 + 1;

        } while (iVar5 < DAT_00632f34);

      }

    }

    *(undefined2 *)(param_1 + iVar3 * 2) = *(undefined2 *)(&DAT_005ddee8 + iVar3);

    if ((&DAT_005ddf60)[iVar3] != 0) {

      local_60 = iVar3;

    }

    iVar3 = iVar3 + 1;

    if (0x13 < iVar3) {

      return local_60 + 1;

    }

  } while( true );

}

/* ===== FUN_0052b400 @ 0x0052B400 ===== */
/* PS2 candidate: base_get_sweep_falloff__Fv (conf 0.563) */



undefined4 FUN_0052b400(void)



{

  undefined4 uVar1;

  

  if (((DAT_00632f10 == 0) || (DAT_00632f10 == 1)) || (uVar1 = 3, DAT_00632f10 == 2)) {

    uVar1 = 2;

  }

  return uVar1;

}

/* ===== FUN_0052b420 @ 0x0052B420 ===== */
void FUN_0052b420(int param_1)



{

  if (param_1 != 0) {

    DAT_005ddfb4 = param_1;

  }

  return;

}

/* ===== comm_0052b430 @ 0x0052B430 ===== */
int comm_0052b430(void)



{

  int iVar1;

  

  iVar1 = 0;

  if (0 < DAT_00632f34) {

    while ((&DAT_005ddf60)[iVar1] != DAT_005def5c) {

      iVar1 = iVar1 + 1;

      if (DAT_00632f34 <= iVar1) {

        return DAT_00632f34 + -1;

      }

    }

    if (iVar1 < DAT_00632f34) {

      return iVar1;

    }

  }

  return DAT_00632f34 + -1;

}

/* ===== FUN_0052b460 @ 0x0052B460 ===== */
void FUN_0052b460(int *param_1,undefined4 *param_2)



{

  int iVar1;

  int iVar2;

  

  iVar2 = 0;

  iVar1 = 0;

  if (DAT_00632f34 < 1) {

    *param_1 = 0;

    *param_2 = &DAT_005ddf60;

    return;

  }

  do {

    if ((&DAT_005ddf60)[iVar1] != 0) {

      iVar2 = iVar1 + 1;

    }

    iVar1 = iVar1 + 1;

  } while (iVar1 < DAT_00632f34);

  *param_1 = iVar2;

  *param_2 = &DAT_005ddf60;

  return;

}

/* ===== FUN_0052b4b0 @ 0x0052B4B0 ===== */
void FUN_0052b4b0(int param_1,undefined4 *param_2)



{

  int iVar1;

  undefined4 *puVar2;

  

  puVar2 = &DAT_005ddf60;

  for (iVar1 = 0x14; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar2 = 0;

    puVar2 = puVar2 + 1;

  }

  puVar2 = &DAT_005ddf60;

  for (; param_1 != 0; param_1 = param_1 + -1) {

    *puVar2 = *param_2;

    param_2 = param_2 + 1;

    puVar2 = puVar2 + 1;

  }

  return;

}

/* ===== FUN_0052b4e0 @ 0x0052B4E0 ===== */
void FUN_0052b4e0(int param_1,int param_2,undefined4 param_3)



{

  int local_8;

  undefined4 local_4;

  

  if ((-1 < param_1) && ((&DAT_005ddf60)[param_1] != 0)) {

    DAT_005dde44 = DAT_005dde44 + param_2;

    DAT_005dde40 = DAT_005dde40 + 1;

    DAT_005dde4c = DAT_005dde4c + param_2;

    local_8 = param_2;

    local_4 = param_3;

    DAT_005dde48 = DAT_005dde48 + 1;

    if (DAT_00632f44 != 0) {

      (**(code **)(*DAT_005def60 + 0x38))

                (DAT_005def60,(&DAT_005ddf60)[param_1],&local_8,1,0,0,&param_1);

      return;

    }

    (**(code **)(*DAT_005def64 + 0x20))(DAT_005def64,&local_8,1,0,0,&param_1,0x28);

  }

  return;

}

/* ===== FUN_0052b5a0 @ 0x0052B5A0 ===== */
void FUN_0052b5a0(undefined4 param_1,int param_2,undefined4 param_3)



{

  int local_8;

  undefined4 local_4;

  

  DAT_005dde40 = DAT_005dde40 + 1;

  DAT_005dde44 = DAT_005dde44 + param_2;

  DAT_005dde48 = DAT_005dde48 + 1;

  DAT_005dde4c = DAT_005dde4c + param_2;

  local_8 = param_2;

  local_4 = param_3;

  if (DAT_00632f44 != 0) {

    (**(code **)(*DAT_005def60 + 0x38))(DAT_005def60,param_1);

    return;

  }

  (**(code **)(*DAT_005def64 + 0x20))(DAT_005def64,&local_8,1,0,0,&param_2,0x28);

  return;

}

/* ===== FUN_0052b630 @ 0x0052B630 ===== */
/* WARNING: Type propagation algorithm not settling */



void FUN_0052b630(int *param_1)



{

  int iVar1;

  undefined4 *puVar2;

  int *piStack_24;

  undefined1 *puStack_1c;

  undefined4 uStack_18;

  undefined4 local_10;

  undefined1 *local_c;

  undefined4 uStack_8;

  

  puStack_1c = (undefined1 *)&local_10;

  uStack_18 = 1;

  local_c = (undefined1 *)0x0;

  local_10 = 0;

  if (DAT_00632f44 == 0) {

    piStack_24 = DAT_005def64;

    (**(code **)(*DAT_005def64 + 0x24))();

    puVar2 = &DAT_005de680;

LAB_0052b70d:

    puVar2[0x19] = piStack_24;

    puVar2[0x18] = &local_c;

    if (&local_c < (undefined1 **)0x5) {

      puVar2[0x1a] = 0;

    }

    if (DAT_006328e8 < (float)puVar2[0x1a]) {

      return;

    }

    if ((undefined1 **)0xf < &local_c) {

      puVar2[0x1a] = DAT_006328e8 + 4.0;

      return;

    }

  }

  else {

    piStack_24 = param_1;

    puStack_1c = (undefined1 *)&local_10;

    (**(code **)(*DAT_005def60 + 0x18))(DAT_005def60);

    iVar1 = 0;

    if (0 < DAT_00632f34) {

      do {

        if ((int *)(&DAT_005ddf60)[iVar1] == param_1) {

          if ((-1 < iVar1) && (puVar2 = &DAT_005de680 + iVar1 * 0x1c, puVar2 != (undefined4 *)0x0))

          goto LAB_0052b70d;

          break;

        }

        iVar1 = iVar1 + 1;

      } while (iVar1 < DAT_00632f34);

    }

  }

  DAT_005dde64 = DAT_005dde64 + (int)local_c;

  DAT_005dde6c = DAT_005dde6c + (int)local_c;

  uStack_18 = uStack_8;

  DAT_005dde60 = DAT_005dde60 + 1;

  puStack_1c = local_c;

  DAT_005dde68 = DAT_005dde68 + 1;

  if (DAT_00632f44 == 0) {

    (**(code **)(*DAT_005def64 + 0x20))(DAT_005def64,&puStack_1c,1,1000,0,&local_10,0x22);

    return;

  }

  (**(code **)(*DAT_005def60 + 0x38))(DAT_005def60,param_1);

  return;

}

/* ===== comm_0052b780 @ 0x0052B780 ===== */
void comm_0052b780(int param_1,int param_2,undefined4 param_3)



{

  int iVar1;

  undefined4 uVar2;

  int iVar3;

  int local_8;

  undefined4 local_4;

  

  uVar2 = param_3;

  iVar3 = 0;

  if (0 < DAT_00632f34) {

    do {

      iVar1 = (&DAT_005ddf60)[iVar3];

      if (((iVar1 != 0) && (iVar1 != DAT_005def5c)) && (iVar1 != param_1)) {

        DAT_005dde40 = DAT_005dde40 + 1;

        DAT_005dde44 = DAT_005dde44 + param_2;

        DAT_005dde48 = DAT_005dde48 + 1;

        DAT_005dde4c = DAT_005dde4c + param_2;

        local_8 = param_2;

        local_4 = uVar2;

        if (DAT_00632f44 == 0) {

          (**(code **)(*DAT_005def64 + 0x20))(DAT_005def64,&local_8,1,0,0,&param_3,0x28);

        }

        else {

          (**(code **)(*DAT_005def60 + 0x38))(DAT_005def60,iVar1,&local_8,1,0,0,&param_3);

        }

      }

      iVar3 = iVar3 + 1;

    } while (iVar3 < DAT_00632f34);

  }

  return;

}

/* ===== FUN_0052b860 @ 0x0052B860 ===== */
void FUN_0052b860(int param_1,undefined4 param_2,undefined4 param_3)



{

  int iVar1;

  int iVar2;

  

  iVar2 = 0;

  if (0 < DAT_00632f34) {

    do {

      iVar1 = (&DAT_005ddf60)[iVar2];

      if (((iVar1 != 0) && (iVar1 != DAT_005def5c)) && (iVar1 != param_1)) {

        FUN_0052b630(iVar1,param_2,param_3);

      }

      iVar2 = iVar2 + 1;

    } while (iVar2 < DAT_00632f34);

  }

  return;

}

/* ===== comm_dp_send @ 0x0052B8C0 ===== */
void comm_dp_send(int param_1,undefined4 param_2)



{

  int iVar1;

  int iVar2;

  int iVar3;

  undefined4 uVar4;

  int iVar5;

  int local_8;

  undefined4 local_4;

  

  uVar4 = param_2;

  iVar3 = param_1;

  iVar2 = DAT_005def5c;

  if (DAT_00632f44 == 0) {

    if (DAT_005ddfb4 != 0) {

      DAT_005dde40 = DAT_005dde40 + 1;

      DAT_005dde44 = DAT_005dde44 + param_1;

      DAT_005dde4c = DAT_005dde4c + param_1;

      local_8 = param_1;

      local_4 = param_2;

      DAT_005dde48 = DAT_005dde48 + 1;

      (**(code **)(*DAT_005def64 + 0x20))(DAT_005def64,&local_8,1,0,0,&param_1,0x28);

    }

  }

  else {

    iVar5 = 0;

    if (0 < DAT_00632f34) {

      do {

        iVar1 = (&DAT_005ddf60)[iVar5];

        if (((iVar1 != 0) && (iVar1 != DAT_005def5c)) && (iVar1 != iVar2)) {

          DAT_005dde40 = DAT_005dde40 + 1;

          DAT_005dde44 = DAT_005dde44 + iVar3;

          DAT_005dde48 = DAT_005dde48 + 1;

          DAT_005dde4c = DAT_005dde4c + iVar3;

          local_8 = iVar3;

          local_4 = uVar4;

          if (DAT_00632f44 == 0) {

            (**(code **)(*DAT_005def64 + 0x20))(DAT_005def64,&local_8,1,0,0,&param_1,0x28);

          }

          else {

            (**(code **)(*DAT_005def60 + 0x38))(DAT_005def60,iVar1,&local_8,1,0,0,&param_1);

          }

        }

        iVar5 = iVar5 + 1;

      } while (iVar5 < DAT_00632f34);

      return;

    }

  }

  return;

}

/* ===== FUN_0052ba30 @ 0x0052BA30 ===== */
void FUN_0052ba30(undefined4 param_1,undefined4 param_2)



{

  int iVar1;

  int iVar2;

  int iVar3;

  

  iVar2 = DAT_005def5c;

  if (DAT_00632f44 == 0) {

    if (DAT_005ddfb4 != 0) {

      FUN_0052b630(DAT_005ddfb4,param_1,param_2);

    }

  }

  else {

    iVar3 = 0;

    if (0 < DAT_00632f34) {

      do {

        iVar1 = (&DAT_005ddf60)[iVar3];

        if (((iVar1 != 0) && (iVar1 != DAT_005def5c)) && (iVar1 != iVar2)) {

          FUN_0052b630(iVar1,param_1,param_2);

        }

        iVar3 = iVar3 + 1;

      } while (iVar3 < DAT_00632f34);

      return;

    }

  }

  return;

}

/* ===== comm_net_stats_dump @ 0x0052BAB0 ===== */
void comm_net_stats_dump(void)



{

  float fVar1;

  int iVar2;

  undefined4 uVar3;

  char *pcVar4;

  int iVar5;

  char *pcVar6;

  int *piVar7;

  int iVar8;

  float10 fVar9;

  float local_1cc;

  undefined1 local_1c8 [200];

  char local_100 [256];

  

  fVar9 = (float10)main_dlog_004272e0();

  fVar1 = (float)fVar9;

  if ((DAT_00632f44 != 0) && (DAT_00633100 == 99)) {

    local_1cc = 0.97;

    iVar8 = 1;

    piVar7 = &DAT_005de74c;

    pcVar6 = &DAT_005ddfe0;

    iVar2 = DAT_00632f44;

    do {

      if (((&DAT_005ddf60)[iVar8] != 0) || (*piVar7 != 0)) {

        if (iVar8 < 0) {

          pcVar4 = &DAT_005561ac;

        }

        else {

          pcVar4 = pcVar6;

          if (*pcVar6 == '\0') {

            if ((iVar2 != 0) &&

               (iVar2 = comm_comm_0052acc0((&DAT_005ddf60)[iVar8],local_100,0x100), iVar2 != 0)) {

              _strncpy(pcVar6,local_100,0x20);

              pcVar6[0x1f] = '\0';

            }

            if (*pcVar6 == '\0') {

              uVar3 = FUN_00507b00(s_CommUnnamedPlayer_0057df98,iVar8);

              FUN_00542f27(pcVar6,s__s__d_00555f38,uVar3);

            }

          }

        }

        FUN_00542f27(local_1c8,s__2d__q__4d_lastq__4d_p__4d_______0057ee24,iVar8,piVar7[1],*piVar7,

                     piVar7[-0x16],pcVar4);

        FUN_0051b970(0xf0f0f0,0,fVar1,0x3c23d70a,local_1cc,local_1c8);

        local_1cc = local_1cc - 0.025;

        iVar2 = DAT_00632f44;

      }

      iVar8 = iVar8 + 1;

      pcVar6 = pcVar6 + 0x20;

      piVar7 = piVar7 + 0x1c;

    } while (iVar8 < 0x14);

    return;

  }

  if (DAT_00633100 == 100) {

    FUN_0051b970(0xf0f0f0,0,fVar1,0x3c23d70a,0x3f19999a,s__________Aggregate_Info__________0057ee00)

    ;

    FUN_0051b970(0xf0f0f0,0,fVar1,0x3c23d70a,0x3f23d70b,s_Guaranteed__0057edf4);

    FUN_00542f27(local_1c8,s_S_s___4d__B_s___5d__St___6d__Bt__0057eda8,DAT_005dde50,DAT_005dde54,

                 DAT_005dde40,DAT_005dde44,DAT_005dde58,DAT_005dde5c);

    FUN_0051b970(0xf0f0f0,0,fVar1,0x3d23d70a,0x3f2a3d71,local_1c8);

    FUN_0051b970(0xf0f0f0,0,fVar1,0x3c23d70a,0x3f347ae2,s_Non_Guaranteed__0057ed98);

    FUN_00542f27(local_1c8,s_S_s___4d__B_s___5d__St___6d__Bt__0057eda8,DAT_005dde70,DAT_005dde74,

                 DAT_005dde60,DAT_005dde64,DAT_005dde78,DAT_005dde7c);

    FUN_0051b970(0xf0f0f0,0,fVar1,0x3d23d70a,0x3f3ae148,local_1c8);

    FUN_0051b970(0xf0f0f0,0,fVar1,0x3c23d70a,0x3f451eb9,s_Total_Sends__0057ed88);

    FUN_00542f27(local_1c8,s_S_s___4d__B_s___5d__St___6d__Bt__0057ed54,DAT_005dde70 + DAT_005dde50,

                 DAT_005dde74 + DAT_005dde54,DAT_005dde60 + DAT_005dde40,DAT_005dde64 + DAT_005dde44

                );

    FUN_0051b970(0xf0f0f0,0,fVar1,0x3d23d70a,0x3f4b851f,local_1c8);

    FUN_0051b970(0xf0f0f0,0,fVar1,0x3c23d70a,0x3f55c290,s_Total_Receives__0057ed44);

    FUN_00542f27(local_1c8,s_R_s___4d__B_s___5d__Rt___6d__Bt__0057ecf8,DAT_005dde90,DAT_005dde94,

                 DAT_005dde80,DAT_005dde84,DAT_005dde98,DAT_005dde9c);

    FUN_0051b970(0xf0f0f0,0,fVar1,0x3d23d70a,0x3f5c28f6,local_1c8);

    return;

  }

  if (DAT_00632f44 == 0) {

    if (DAT_00633100 == 1) {

      FUN_00542f27(local_1c8,s________Client________0057eb24);

      FUN_0051b970(0xf0f0f0,0,fVar1,0x3c23d70a,0x3ecccccd,local_1c8);

      FUN_00542f27(local_1c8,s_ping_ms____4d__BPS___5d__Peak_BP_0057ec88,DAT_005de684,DAT_005de688,

                   DAT_005de68c,DAT_005de6d8);

      FUN_0051b970(0xf0f0f0,0,fVar1,0x3d23d70a,0x3ed9999a,local_1c8);

      FUN_0051b970(0xf0f0f0,0,fVar1,0x3c23d70a,0x3eee147b,s_Guaranteed__0057edf4);

      FUN_00542f27(local_1c8,s_Bytes_Sent___7d__Bytes_Rec___7d__0057ec38,DAT_005de690,DAT_005de6c8,

                   DAT_005de694,DAT_005de6cc);

      FUN_0051b970(0xf0f0f0,0,fVar1,0x3d23d70a,0x3efae148,local_1c8);

      FUN_0051b970(0xf0f0f0,0,fVar1,0x3c23d70a,0x3f07ae15,s_Non_Guaranteed__0057ed98);

      FUN_00542f27(local_1c8,s_Bytes_Sent___7d__Bytes_Rec___7d__0057ec38,DAT_005de698,DAT_005de6d0,

                   DAT_005de69c,DAT_005de6d4);

      FUN_0051b970(0xf0f0f0,0,fVar1,0x3d23d70a,0x3f0e147b,local_1c8);

      FUN_0051b970(0xf0f0f0,0,fVar1,0x3c23d70a,0x3f1851ec,s_Packet_Loss__0057ec28);

      FUN_00542f27(local_1c8,s_Bytes_Retried___7d__Bytes_Droppe_0057ebc8,DAT_005de6a0,DAT_005de6a8,

                   DAT_005de6a4,DAT_005de6ac);

      FUN_0051b970(0xf0f0f0,0,fVar1,0x3d23d70a,0x3f1eb852,local_1c8);

      FUN_0051b970(0xf0f0f0,0,fVar1,0x3c23d70a,0x3f28f5c3,s_Priority_High__0057ebb8);

      FUN_00542f27(local_1c8,s_Msgs_Sent___4d__Msgs_Timed_Out___0057eb90,DAT_005de6b0,DAT_005de6b4);

      FUN_0051b970(0xf0f0f0,0,fVar1,0x3d23d70a,0x3f2f5c29,local_1c8);

      FUN_0051b970(0xf0f0f0,0,fVar1,0x3c23d70a,0x3f39999a,s_Priority_Medium__0057eb7c);

      FUN_00542f27(local_1c8,s_Msgs_Sent___4d__Msgs_Timed_Out___0057eb90,DAT_005de6b8,DAT_005de6bc);

      FUN_0051b970(0xf0f0f0,0,fVar1,0x3d23d70a,0x3f400000,local_1c8);

      FUN_0051b970(0xf0f0f0,0,fVar1,0x3c23d70a,0x3f4a3d71,s_Priority_Low__0057eb6c);

      FUN_00542f27(local_1c8,s_Msgs_Sent___4d__Msgs_Timed_Out___0057eb90,DAT_005de6c0,DAT_005de6c4);

      FUN_0051b970(0xf0f0f0,0,fVar1,0x3d23d70a,0x3f50a3d7,local_1c8);

      FUN_0051b970(0xf0f0f0,0,fVar1,0x3c23d70a,0x3f5ae148,s_Send_Queue__0057eb60);

      FUN_00542f27(local_1c8,s_Num_Msgs___4d__Num_Bytes___4d_0057eb3c,DAT_005de6e0,DAT_005de6e4);

      FUN_0051b970(0xf0f0f0,0,fVar1,0x3d23d70a,0x3f6147ae,local_1c8);

    }

  }

  else if ((0 < DAT_00633100) && (DAT_00633100 < 0x15)) {

    iVar2 = DAT_00633100 + -1;

    if (iVar2 < 0) {

      pcVar6 = &DAT_005561ac;

    }

    else {

      iVar8 = iVar2 * 0x20;

      pcVar6 = &DAT_005ddfc0 + iVar8;

      if ((&DAT_005ddfc0)[iVar8] == '\0') {

        iVar5 = comm_comm_0052acc0((&DAT_005ddf60)[iVar2],local_100,0x100);

        if (iVar5 != 0) {

          _strncpy(pcVar6,local_100,0x20);

          (&DAT_005ddfdf)[iVar8] = 0;

        }

        if (*pcVar6 == '\0') {

          uVar3 = FUN_00507b00(s_CommUnnamedPlayer_0057df98,iVar2);

          FUN_00542f27(pcVar6,s__s__d_00555f38,uVar3);

        }

      }

    }

    FUN_00542f27(local_1c8,s________Client__d__name____s______0057eccc,iVar2,pcVar6);

    FUN_0051b970(0xf0f0f0,0,fVar1,0x3c23d70a,0x3ecccccd,local_1c8);

    FUN_00542f27(local_1c8,s_ping_ms____4d__BPS___5d__Peak_BP_0057ec88,(&DAT_005de684)[iVar2 * 0x1c]

                 ,(&DAT_005de688)[iVar2 * 0x1c],(&DAT_005de68c)[iVar2 * 0x1c],

                 (&DAT_005de6d8)[iVar2 * 0x1c]);

    FUN_0051b970(0xf0f0f0,0,fVar1,0x3d23d70a,0x3ed9999a,local_1c8);

    FUN_0051b970(0xf0f0f0,0,fVar1,0x3c23d70a,0x3eee147b,s_Guaranteed__0057edf4);

    FUN_00542f27(local_1c8,s_Bytes_Sent___7d__Bytes_Rec___7d__0057ec38,(&DAT_005de690)[iVar2 * 0x1c]

                 ,(&DAT_005de6c8)[iVar2 * 0x1c],(&DAT_005de694)[iVar2 * 0x1c],

                 (&DAT_005de6cc)[iVar2 * 0x1c]);

    FUN_0051b970(0xf0f0f0,0,fVar1,0x3d23d70a,0x3efae148,local_1c8);

    FUN_0051b970(0xf0f0f0,0,fVar1,0x3c23d70a,0x3f07ae15,s_Non_Guaranteed__0057ed98);

    FUN_00542f27(local_1c8,s_Bytes_Sent___7d__Bytes_Rec___7d__0057ec38,(&DAT_005de698)[iVar2 * 0x1c]

                 ,(&DAT_005de6d0)[iVar2 * 0x1c],(&DAT_005de69c)[iVar2 * 0x1c],

                 (&DAT_005de6d4)[iVar2 * 0x1c]);

    FUN_0051b970(0xf0f0f0,0,fVar1,0x3d23d70a,0x3f0e147b,local_1c8);

    FUN_0051b970(0xf0f0f0,0,fVar1,0x3c23d70a,0x3f1851ec,s_Packet_Loss__0057ec28);

    FUN_00542f27(local_1c8,s_Bytes_Retried___7d__Bytes_Droppe_0057ebc8,(&DAT_005de6a0)[iVar2 * 0x1c]

                 ,(&DAT_005de6a8)[iVar2 * 0x1c],(&DAT_005de6a4)[iVar2 * 0x1c],

                 (&DAT_005de6ac)[iVar2 * 0x1c]);

    FUN_0051b970(0xf0f0f0,0,fVar1,0x3d23d70a,0x3f1eb852,local_1c8);

    FUN_0051b970(0xf0f0f0,0,fVar1,0x3c23d70a,0x3f28f5c3,s_Priority_High__0057ebb8);

    FUN_00542f27(local_1c8,s_Msgs_Sent___4d__Msgs_Timed_Out___0057eb90,(&DAT_005de6b0)[iVar2 * 0x1c]

                 ,(&DAT_005de6b4)[iVar2 * 0x1c]);

    FUN_0051b970(0xf0f0f0,0,fVar1,0x3d23d70a,0x3f2f5c29,local_1c8);

    FUN_0051b970(0xf0f0f0,0,fVar1,0x3c23d70a,0x3f39999a,s_Priority_Medium__0057eb7c);

    FUN_00542f27(local_1c8,s_Msgs_Sent___4d__Msgs_Timed_Out___0057eb90,(&DAT_005de6b8)[iVar2 * 0x1c]

                 ,(&DAT_005de6bc)[iVar2 * 0x1c]);

    FUN_0051b970(0xf0f0f0,0,fVar1,0x3d23d70a,0x3f400000,local_1c8);

    FUN_0051b970(0xf0f0f0,0,fVar1,0x3c23d70a,0x3f4a3d71,s_Priority_Low__0057eb6c);

    FUN_00542f27(local_1c8,s_Msgs_Sent___4d__Msgs_Timed_Out___0057eb90,(&DAT_005de6c0)[iVar2 * 0x1c]

                 ,(&DAT_005de6c4)[iVar2 * 0x1c]);

    FUN_0051b970(0xf0f0f0,0,fVar1,0x3d23d70a,0x3f50a3d7,local_1c8);

    FUN_0051b970(0xf0f0f0,0,fVar1,0x3c23d70a,0x3f5ae148,s_Send_Queue__0057eb60);

    FUN_00542f27(local_1c8,s_Num_Msgs___4d__Num_Bytes___4d_0057eb3c,(&DAT_005de6e0)[iVar2 * 0x1c],

                 (&DAT_005de6e4)[iVar2 * 0x1c]);

    FUN_0051b970(0xf0f0f0,0,fVar1,0x3d23d70a,0x3f6147ae,local_1c8);

    return;

  }

  return;

}

/* ===== FUN_0052c4d0 @ 0x0052C4D0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_0052c4d0(void)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  

  iVar6 = DAT_005dde8c;

  iVar5 = DAT_005dde88;

  iVar4 = DAT_005dde6c;

  iVar3 = DAT_005dde68;

  iVar2 = DAT_005dde4c;

  iVar1 = DAT_005dde48;

  if (1.0 <= DAT_006328e8 - _DAT_005ddea0) {

    _DAT_005ddea0 = DAT_006328e8;

    DAT_005dde48 = 0;

    DAT_005dde4c = 0;

    DAT_005dde68 = 0;

    DAT_005dde6c = 0;

    DAT_005dde88 = 0;

    DAT_005dde8c = 0;

    DAT_005dde50 = iVar1;

    DAT_005dde54 = iVar2;

    DAT_005dde70 = iVar3;

    DAT_005dde74 = iVar4;

    DAT_005dde90 = iVar5;

    DAT_005dde94 = iVar6;

    if (DAT_005dde58 < iVar1) {

      DAT_005dde58 = iVar1;

    }

    if (DAT_005dde5c < iVar2) {

      DAT_005dde5c = iVar2;

    }

    if (DAT_005dde78 < iVar3) {

      DAT_005dde78 = iVar3;

    }

    if (DAT_005dde7c < iVar4) {

      DAT_005dde7c = iVar4;

    }

    if (DAT_005dde98 < iVar5) {

      DAT_005dde98 = iVar5;

    }

    if (DAT_005dde9c < iVar6) {

      DAT_005dde9c = iVar6;

    }

  }

  return;

}

/* ===== FUN_0052c5c0 @ 0x0052C5C0 ===== */
/* PS2 candidate: __tfSc (conf 0.76) */



undefined4 FUN_0052c5c0(void)



{

  undefined4 uVar1;

  

  uVar1 = 1;

  if (DAT_005def80 == 5) {

    uVar1 = DAT_00632f44;

  }

  return uVar1;

}

/* ===== FUN_0052d1c0 @ 0x0052D1C0 ===== */
/* PS2 candidate: marker_follow_path (conf 0.475) */



void FUN_0052d1c0(void)



{

  if (((DAT_00632f44 != 0) && (DAT_0063317c == 0)) && (DAT_00633184 == 0)) {

    if (DAT_005defa4 != 0) {

      FUN_0051ea20(s_gamespy_process_queries_called_a_0057f07c);

      return;

    }

    if (DAT_005defa0 == 0) {

      FUN_0051ea20(s_gamespy_process_queries_called_w_0057f050);

      return;

    }

    comm_socket_recv_loop(0);

  }

  return;

}

/* ===== gamespy_statechange3 @ 0x0052D220 ===== */
void gamespy_statechange3(void)



{

  if (((DAT_00632f44 != 0) && (DAT_0063317c == 0)) && (DAT_00633184 == 0)) {

    if (DAT_005defa4 != 0) {

      FUN_0051ea20(s_gamespy_send_statechange_called_a_0057df34);

      return;

    }

    if (DAT_005defa0 == 0) {

      FUN_0051ea20(s_gamespy_send_statechange_called_w_0057df04);

      return;

    }

    gamespy_0052daa0(0);

  }

  return;

}

/* ===== gamespy_shutdown2 @ 0x0052D280 ===== */
/* PS2 candidate: TreeBendCreate (conf 0.476) */



void gamespy_shutdown2(void)



{

  if (((DAT_00632f44 != 0) && (DAT_0063317c == 0)) && (DAT_00633184 == 0)) {

    if (DAT_005defa4 != 0) {

      FUN_0051ea20(s_gamespy_shutdown_called_more_tha_0057dd58);

      return;

    }

    if (DAT_005defa0 == 0) {

      FUN_0051ea20(s_gamespy_shutdown_called_without_i_0057dd30);

      return;

    }

    DAT_00632f08 = 9999;

    gamespy_0052daa0(0);

    gamespy_0052db50(0);

    DAT_005defa4 = 1;

    DAT_005defa0 = 0;

  }

  return;

}

/* ===== net_0052d300 @ 0x0052D300 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined4

net_0052d300(undefined4 *param_1,char *param_2,uint param_3,char *param_4,char *param_5,

            undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9,

            undefined4 param_10)



{

  char cVar1;

  u_short uVar2;

  SOCKET s;

  ulong uVar3;

  u_long uVar4;

  undefined4 *puVar5;

  int iVar6;

  hostent *phVar7;

  int iVar8;

  char *pcVar9;

  char *pcVar10;

  bool bVar11;

  int local_14;

  sockaddr local_10;

  

  if (param_1 != (undefined4 *)0x0) {

    *param_1 = 0;

  }

  FUN_005380b0();

  s = socket(2,2,0x11);

  if (s == 0xffffffff) {

    return 1;

  }

  iVar6 = param_3 + 100;

  puVar5 = param_1;

  for (; (int)param_3 < iVar6; param_3 = param_3 + 1) {

    local_10.sa_family = 2;

    local_10.sa_data._0_2_ = htons((u_short)param_3);

    if (param_2 == (char *)0x0) {

      local_10.sa_data[2] = '\0';

      local_10.sa_data[3] = '\0';

      local_10.sa_data[4] = '\0';

      local_10.sa_data[5] = '\0';

    }

    else {

      uVar3 = inet_addr(param_2);

      local_10.sa_data._2_2_ = SUB42(uVar3,0);

      local_10.sa_data._4_2_ = SUB42(uVar3 >> 0x10,0);

      if (uVar3 == 0xffffffff) {

        iVar8 = 0x10;

        bVar11 = true;

        pcVar9 = param_2;

        pcVar10 = &DAT_0057f218;

        do {

          if (iVar8 == 0) break;

          iVar8 = iVar8 + -1;

          bVar11 = *pcVar9 == *pcVar10;

          pcVar9 = pcVar9 + 1;

          pcVar10 = pcVar10 + 1;

        } while (bVar11);

        if ((!bVar11) && (phVar7 = gethostbyname(param_2), phVar7 != (hostent *)0x0)) {

          local_10.sa_data._2_2_ = SUB42(*(undefined4 *)*phVar7->h_addr_list,0);

          local_10.sa_data._4_2_ = SUB42((uint)*(undefined4 *)*phVar7->h_addr_list >> 0x10,0);

        }

      }

    }

    uVar4 = htonl(0x7f000001);

    if (CONCAT22(local_10.sa_data._4_2_,local_10.sa_data._2_2_) == uVar4) {

      local_10.sa_data[2] = '\0';

      local_10.sa_data[3] = '\0';

      local_10.sa_data[4] = '\0';

      local_10.sa_data[5] = '\0';

    }

    puVar5 = (undefined4 *)bind(s,&local_10,0x10);

    if (puVar5 == (undefined4 *)0x0) goto LAB_0052d3f9;

  }

  if (puVar5 != (undefined4 *)0x0) {

    return 2;

  }

LAB_0052d3f9:

  if (param_3 == 0) {

    local_14 = 0x10;

    iVar6 = getsockname(s,&local_10,&local_14);

    if (iVar6 != 0) {

      return 2;

    }

    uVar2 = ntohs(local_10.sa_data._0_2_);

    param_3 = (uint)uVar2;

  }

  if (param_1 == (undefined4 *)0x0) {

    PTR_DAT_0057f1c8 = (undefined *)&DAT_0057f0d8;

  }

  else {

    PTR_DAT_0057f1c8 = _malloc(0xf0);

    *param_1 = PTR_DAT_0057f1c8;

  }

  pcVar9 = PTR_DAT_0057f1c8 + 8;

  do {

    cVar1 = *param_4;

    param_4 = param_4 + 1;

    *pcVar9 = cVar1;

    pcVar9 = pcVar9 + 1;

  } while (cVar1 != '\0');

  pcVar9 = PTR_DAT_0057f1c8 + 0x48;

  do {

    cVar1 = *param_5;

    param_5 = param_5 + 1;

    *pcVar9 = cVar1;

    pcVar9 = pcVar9 + 1;

  } while (cVar1 != '\0');

  *(uint *)(PTR_DAT_0057f1c8 + 0xe4) = param_3;

  *(undefined4 *)(PTR_DAT_0057f1c8 + 0xd8) = 0;

  *(SOCKET *)(PTR_DAT_0057f1c8 + 4) = s;

  *(SOCKET *)PTR_DAT_0057f1c8 = s;

  *(undefined4 *)(PTR_DAT_0057f1c8 + 0xe0) = 0;

  *(undefined4 *)(PTR_DAT_0057f1c8 + 0xdc) = 1;

  PTR_DAT_0057f1c8[0xe8] = 1;

  *(undefined4 *)(PTR_DAT_0057f1c8 + 0xec) = param_10;

  *(undefined4 *)(PTR_DAT_0057f1c8 + 200) = param_6;

  *(undefined4 *)(PTR_DAT_0057f1c8 + 0xcc) = param_7;

  *(undefined4 *)(PTR_DAT_0057f1c8 + 0xd4) = param_9;

  *(undefined4 *)(PTR_DAT_0057f1c8 + 0xd0) = param_8;

  _DAT_005df2b0 = 2;

  _DAT_005df2b2 = htons(0x6cfc);

  _DAT_005df2b4 = inet_addr(s_master_gamespy_com_0057f204);

  if (_DAT_005df2b4 == 0xffffffff) {

    iVar6 = 0x13;

    bVar11 = true;

    pcVar9 = s_master_gamespy_com_0057f204;

    pcVar10 = &DAT_0057f218;

    do {

      if (iVar6 == 0) break;

      iVar6 = iVar6 + -1;

      bVar11 = *pcVar9 == *pcVar10;

      pcVar9 = pcVar9 + 1;

      pcVar10 = pcVar10 + 1;

    } while (bVar11);

    if ((!bVar11) &&

       (phVar7 = gethostbyname(s_master_gamespy_com_0057f204), phVar7 != (hostent *)0x0)) {

      _DAT_005df2b4 = *(ulong *)*phVar7->h_addr_list;

    }

  }

  return 0;

}

/* ===== comm_socket_recv_loop @ 0x0052D5B0 ===== */
void comm_socket_recv_loop(SOCKET *param_1)



{

  char *pcVar1;

  SOCKET SVar2;

  DWORD DVar3;

  int iVar4;

  char *pcVar5;

  char *pcVar6;

  int iVar7;

  char cVar8;

  uint uVar9;

  char *pcVar10;

  undefined4 *puVar11;

  sockaddr local_8a4;

  int local_894;

  undefined **local_890;

  int local_88c;

  uint local_888;

  timeval local_884;

  char local_87c;

  undefined4 local_87b;

  undefined2 local_77c;

  undefined4 local_77a [63];

  char local_67c;

  undefined4 local_67b;

  fd_set local_104;

  

  if (param_1 == (SOCKET *)0x0) {

    param_1 = (SOCKET *)PTR_DAT_0057f1c8;

  }

  DVar3 = GetTickCount();

  if (param_1[1] != 0xffffffff) {

    uVar9 = param_1[0x36];

    if (((DVar3 - uVar9 < 0x493e1) && (uVar9 != 0)) && (uVar9 <= DVar3)) {

      if (('\0' < (char)param_1[0x3a]) && (30000 < DVar3 - uVar9)) {

        FUN_00542f27(&local_87c,s__heartbeat__d_gamename__s_0057f22c,param_1[0x39],param_1 + 2);

        uVar9 = 0xffffffff;

        pcVar5 = &local_87c;

        do {

          if (uVar9 == 0) break;

          uVar9 = uVar9 - 1;

          cVar8 = *pcVar5;

          pcVar5 = pcVar5 + 1;

        } while (cVar8 != '\0');

        sendto(param_1[1],&local_87c,~uVar9 - 1,0,(sockaddr *)&DAT_005df2b0,0x10);

        DVar3 = GetTickCount();

        cVar8 = (char)param_1[0x3a] + '\x01';

        param_1[0x36] = DVar3;

        *(char *)(param_1 + 0x3a) = cVar8;

        if ('\n' < cVar8) {

          *(undefined1 *)(param_1 + 0x3a) = 0;

        }

      }

    }

    else {

      FUN_00542f27(&local_87c,s__heartbeat__d_gamename__s_0057f22c,param_1[0x39],param_1 + 2);

      uVar9 = 0xffffffff;

      pcVar5 = &local_87c;

      do {

        if (uVar9 == 0) break;

        uVar9 = uVar9 - 1;

        cVar8 = *pcVar5;

        pcVar5 = pcVar5 + 1;

      } while (cVar8 != '\0');

      sendto(param_1[1],&local_87c,~uVar9 - 1,0,(sockaddr *)&DAT_005df2b0,0x10);

      DVar3 = GetTickCount();

      param_1[0x36] = DVar3;

    }

  }

  local_104.fd_array[0] = *param_1;

  local_88c = 0x10;

  local_884.tv_sec = 0;

  local_884.tv_usec = 0;

  if (local_104.fd_array[0] != 0xffffffff) {

    local_104.fd_count = 1;

    while ((iVar4 = select(0x40,&local_104,(fd_set *)0x0,(fd_set *)0x0,&local_884), iVar4 != -1 &&

           (iVar4 != 0))) {

      iVar4 = recvfrom(*param_1,&DAT_005defa8,0xff,0,&local_8a4,&local_88c);

      cVar8 = DAT_00584374;

      if (iVar4 != -1) {

        (&DAT_005defa8)[iVar4] = 0;

        local_67c = cVar8;

        puVar11 = &local_67b;

        for (iVar4 = 0x15d; iVar4 != 0; iVar4 = iVar4 + -1) {

          *puVar11 = 0;

          puVar11 = puVar11 + 1;

        }

        *(undefined2 *)puVar11 = 0;

        *(undefined1 *)((int)puVar11 + 2) = 0;

        local_87c = cVar8;

        puVar11 = &local_87b;

        for (iVar4 = 0x3f; iVar4 != 0; iVar4 = iVar4 + -1) {

          *puVar11 = 0;

          puVar11 = puVar11 + 1;

        }

        SVar2 = param_1[0x37];

        *(undefined2 *)puVar11 = 0;

        *(undefined1 *)((int)puVar11 + 2) = 0;

        param_1[0x37] = SVar2 + 1;

        param_1[0x38] = 0;

        if ('\0' < (char)param_1[0x3a]) {

          *(undefined1 *)(param_1 + 0x3a) = 0;

        }

        local_894 = 0;

        local_890 = &PTR_s_basic_0057f0b4;

        do {

          local_77c = DAT_0057f228;

          puVar11 = local_77a;

          for (iVar4 = 0x3f; iVar4 != 0; iVar4 = iVar4 + -1) {

            *puVar11 = 0;

            puVar11 = puVar11 + 1;

          }

          DAT_005df0a8 = DAT_005df0a8 ^ 1;

          *(undefined2 *)puVar11 = 0;

          local_888 = 0xffffffff;

          pcVar5 = *local_890;

          do {

            pcVar6 = pcVar5;

            if (local_888 == 0) break;

            local_888 = local_888 - 1;

            pcVar6 = pcVar5 + 1;

            cVar8 = *pcVar5;

            pcVar5 = pcVar6;

          } while (cVar8 != '\0');

          local_888 = ~local_888;

          iVar4 = -1;

          pcVar5 = (char *)&local_77c;

          do {

            pcVar10 = pcVar5;

            if (iVar4 == 0) break;

            iVar4 = iVar4 + -1;

            pcVar10 = pcVar5 + 1;

            cVar8 = *pcVar5;

            pcVar5 = pcVar10;

          } while (cVar8 != '\0');

          pcVar5 = pcVar6 + -local_888;

          pcVar6 = pcVar10 + -1;

          for (uVar9 = local_888 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {

            *(undefined4 *)pcVar6 = *(undefined4 *)pcVar5;

            pcVar5 = pcVar5 + 4;

            pcVar6 = pcVar6 + 4;

          }

          for (uVar9 = local_888 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {

            *pcVar6 = *pcVar5;

            pcVar5 = pcVar5 + 1;

            pcVar6 = pcVar6 + 1;

          }

          iVar4 = -1;

          pcVar5 = (char *)&local_77c;

          do {

            pcVar6 = pcVar5;

            if (iVar4 == 0) break;

            iVar4 = iVar4 + -1;

            pcVar6 = pcVar5 + 1;

            cVar8 = *pcVar5;

            pcVar5 = pcVar6;

          } while (cVar8 != '\0');

          *(undefined2 *)(pcVar6 + -1) = DAT_0057f228;

          pcVar5 = _strstr(&DAT_005defa8,(char *)&local_77c);

          if (pcVar5 != (char *)0x0) {

            uVar9 = 0xffffffff;

            pcVar6 = (char *)&local_77c;

            do {

              if (uVar9 == 0) break;

              uVar9 = uVar9 - 1;

              cVar8 = *pcVar6;

              pcVar6 = pcVar6 + 1;

            } while (cVar8 != '\0');

            pcVar5 = pcVar5 + (~uVar9 - 1);

            pcVar6 = &DAT_005df0b0 + DAT_005df0a8 * 0x100;

            cVar8 = *pcVar5;

            pcVar10 = pcVar6;

            while ((cVar8 != '\0' && (cVar8 != '\\'))) {

              *pcVar10 = cVar8;

              pcVar1 = pcVar5 + 1;

              pcVar10 = pcVar10 + 1;

              pcVar5 = pcVar5 + 1;

              cVar8 = *pcVar1;

            }

            *pcVar10 = '\0';

            if (pcVar6 != (char *)0x0) {

              switch(local_894) {

              case 0:

                FUN_0052e030(param_1,&local_8a4,&local_67c);

                break;

              case 1:

                FUN_0052e0a0(param_1,&local_8a4,&local_67c);

                break;

              case 2:

                FUN_0052e110(param_1,&local_8a4,&local_67c);

                break;

              case 3:

                FUN_0052e180(param_1,&local_8a4,&local_67c);

                break;

              case 4:

                FUN_0052e030(param_1,&local_8a4,&local_67c);

                FUN_0052e0a0(param_1,&local_8a4,&local_67c);

                FUN_0052e110(param_1,&local_8a4,&local_67c);

                FUN_0052e180(param_1,&local_8a4,&local_67c);

                break;

              case 5:

                FUN_0052e030(param_1,&local_8a4,&local_67c);

                FUN_0052ddf0(param_1,&local_8a4,&local_67c);

                FUN_0052e0a0(param_1,&local_8a4,&local_67c);

                FUN_0052ddf0(param_1,&local_8a4,&local_67c);

                FUN_0052e110(param_1,&local_8a4,&local_67c);

                FUN_0052ddf0(param_1,&local_8a4,&local_67c);

                FUN_0052e180(param_1,&local_8a4,&local_67c);

                break;

              case 6:

                FUN_0052e1f0(param_1,&local_8a4,&local_67c,pcVar6);

                break;

              case 7:

                iVar4 = -(int)pcVar6;

                do {

                  cVar8 = *pcVar6;

                  pcVar6[(int)(&local_87c + iVar4)] = cVar8;

                  pcVar6 = pcVar6 + 1;

                } while (cVar8 != '\0');

              }

            }

          }

          local_890 = local_890 + 1;

          iVar4 = local_894 + 1;

          iVar7 = local_894 + 2;

          local_894 = iVar4;

        } while (iVar7 < 9);

        FUN_0052e250(param_1,&local_8a4,&local_67c,&local_87c);

      }

    }

  }

  return;

}

/* ===== gamespy_0052daa0 @ 0x0052DAA0 ===== */
void gamespy_0052daa0(undefined *param_1)



{

  char cVar1;

  DWORD DVar2;

  int iVar3;

  uint uVar4;

  char *pcVar5;

  char *pcVar6;

  char local_100 [256];

  

  if (param_1 == (undefined *)0x0) {

    param_1 = PTR_DAT_0057f1c8;

  }

  FUN_00542f27(local_100,s__heartbeat__d_gamename__s_0057f22c,*(undefined4 *)(param_1 + 0xe4),

               param_1 + 8);

  iVar3 = -1;

  pcVar6 = local_100;

  do {

    pcVar5 = pcVar6;

    if (iVar3 == 0) break;

    iVar3 = iVar3 + -1;

    pcVar5 = pcVar6 + 1;

    cVar1 = *pcVar6;

    pcVar6 = pcVar5;

  } while (cVar1 != '\0');

  *(undefined4 *)(pcVar5 + -1) = s__statechanged__0057f248._0_4_;

  *(undefined4 *)(pcVar5 + 3) = s__statechanged__0057f248._4_4_;

  *(undefined4 *)(pcVar5 + 7) = s__statechanged__0057f248._8_4_;

  *(undefined2 *)(pcVar5 + 0xb) = s__statechanged__0057f248._12_2_;

  pcVar5[0xd] = s__statechanged__0057f248[0xe];

  uVar4 = 0xffffffff;

  pcVar6 = local_100;

  do {

    if (uVar4 == 0) break;

    uVar4 = uVar4 - 1;

    cVar1 = *pcVar6;

    pcVar6 = pcVar6 + 1;

  } while (cVar1 != '\0');

  sendto(*(SOCKET *)(param_1 + 4),local_100,~uVar4 - 1,0,(sockaddr *)&DAT_005df2b0,0x10);

  DVar2 = GetTickCount();

  *(DWORD *)(param_1 + 0xd8) = DVar2;

  return;

}

/* ===== gamespy_0052db50 @ 0x0052DB50 ===== */
void gamespy_0052db50(SOCKET *param_1)



{

  SOCKET s;

  

  if (param_1 == (SOCKET *)0x0) {

    param_1 = (SOCKET *)PTR_DAT_0057f1c8;

  }

  if (*param_1 != 0xffffffff) {

    closesocket(*param_1);

  }

  s = param_1[1];

  if ((s != 0xffffffff) && (s != *param_1)) {

    closesocket(s);

  }

  param_1[1] = 0xffffffff;

  *param_1 = 0xffffffff;

  param_1[0x36] = 0;

  if (param_1 != &DAT_0057f0d8) {

    crt_free_ext(param_1);

  }

  WSACleanup();

  return;

}

/* ===== FUN_0052dbb0 @ 0x0052DBB0 ===== */
void FUN_0052dbb0(undefined1 *param_1,uint param_2,byte *param_3)



{

  int iVar1;

  byte bVar2;

  int iVar3;

  byte *pbVar4;

  int iVar5;

  

  iVar1 = param_2;

  iVar5 = 0;

  pbVar4 = param_3;

  if ((int)param_2 < 1) {

    *param_3 = 0;

    return;

  }

  do {

    iVar3 = 0;

    do {

      if (iVar5 < iVar1) {

        *(undefined1 *)((int)&param_3 + iVar3) = *param_1;

        param_1 = param_1 + 1;

      }

      else {

        *(undefined1 *)((int)&param_3 + iVar3) = 0;

      }

      iVar3 = iVar3 + 1;

      iVar5 = iVar5 + 1;

    } while (iVar3 < 3);

    param_2._0_3_ =

         CONCAT12((param_3._1_1_ & 0xf) * '\x04' + (param_3._2_1_ >> 6),

                  CONCAT11(((byte)param_3 & 3) * '\x10' + (param_3._1_1_ >> 4),(byte)param_3 >> 2));

    param_2 = CONCAT13(param_3._2_1_,(undefined3)param_2) & 0x3fffffff;

    iVar3 = 0;

    do {

      bVar2 = *(byte *)((int)&param_2 + iVar3);

      if (bVar2 < 0x1a) {

        bVar2 = bVar2 + 0x41;

      }

      else if (bVar2 < 0x34) {

        bVar2 = bVar2 + 0x47;

      }

      else if (bVar2 < 0x3e) {

        bVar2 = bVar2 - 4;

      }

      else if (bVar2 == 0x3e) {

        bVar2 = 0x2b;

      }

      else {

        bVar2 = (bVar2 != 0x3f) - 1U & 0x2f;

      }

      *pbVar4 = bVar2;

      pbVar4 = pbVar4 + 1;

      iVar3 = iVar3 + 1;

    } while (iVar3 < 4);

  } while (iVar5 < iVar1);

  *pbVar4 = 0;

  return;

}

/* ===== comm_packet_decode @ 0x0052DC80 ===== */
/* WARNING: Removing unreachable block (ram,0x0052dd6b) */

/* WARNING: Removing unreachable block (ram,0x0052dd47) */

/* WARNING: Removing unreachable block (ram,0x0052dcdb) */

/* WARNING: Removing unreachable block (ram,0x0052dda7) */



void comm_packet_decode(int param_1,int param_2,int param_3,int param_4)



{

  byte bVar1;

  byte bVar2;

  uint uVar3;

  byte *pbVar4;

  short sVar5;

  uint uVar6;

  int iVar7;

  uint local_108;

  byte local_100 [256];

  

  sVar5 = 0;

  pbVar4 = local_100;

  do {

    *pbVar4 = (byte)sVar5;

    sVar5 = sVar5 + 1;

    pbVar4 = pbVar4 + 1;

  } while (sVar5 < 0x100);

  local_108 = 0;

  uVar3 = 0;

  iVar7 = 0x100;

  pbVar4 = local_100;

  do {

    uVar3 = (uint)*pbVar4 + uVar3 + *(byte *)(local_108 + param_1) & 0x800000ff;

    iVar7 = iVar7 + -1;

    local_108 = (uint)(byte)((longlong)(ulonglong)(local_108 + 1) % (longlong)param_2);

    bVar1 = *pbVar4;

    *pbVar4 = local_100[uVar3];

    local_100[uVar3] = bVar1;

    pbVar4 = pbVar4 + 1;

  } while (iVar7 != 0);

  sVar5 = 0;

  if (0 < param_4) {

    uVar3 = 0;

    uVar6 = 0;

    iVar7 = 0;

    do {

      bVar1 = *(byte *)(iVar7 + param_3);

      uVar3 = bVar1 + 1 + uVar3 & 0x800000ff;

      uVar6 = local_100[uVar3] + uVar6 & 0x800000ff;

      bVar2 = local_100[uVar3];

      local_100[uVar3] = local_100[uVar6];

      local_100[uVar6] = bVar2;

      sVar5 = sVar5 + 1;

      *(byte *)(iVar7 + param_3) =

           local_100[(uint)local_100[uVar3] + (uint)local_100[uVar6] & 0xff] ^ bVar1;

      iVar7 = (int)sVar5;

    } while (iVar7 < param_4);

  }

  return;

}

/* ===== FUN_0052ddf0 @ 0x0052DDF0 ===== */
void FUN_0052ddf0(SOCKET *param_1,sockaddr *param_2,char *param_3)



{

  char cVar1;

  SOCKET SVar2;

  int iVar3;

  uint uVar4;

  uint uVar5;

  char *pcVar6;

  char *pcVar7;

  char *pcVar8;

  char local_50 [80];

  

  iVar3 = -1;

  pcVar6 = param_3;

  do {

    if (iVar3 == 0) break;

    iVar3 = iVar3 + -1;

    cVar1 = *pcVar6;

    pcVar6 = pcVar6 + 1;

  } while (cVar1 != '\0');

  if (iVar3 != -2) {

    SVar2 = param_1[0x38];

    param_1[0x38] = SVar2 + 1;

    FUN_00542f27(local_50,s__queryid__d__d_0057f258,param_1[0x37],SVar2 + 1);

    uVar4 = 0xffffffff;

    pcVar6 = local_50;

    do {

      pcVar8 = pcVar6;

      if (uVar4 == 0) break;

      uVar4 = uVar4 - 1;

      pcVar8 = pcVar6 + 1;

      cVar1 = *pcVar6;

      pcVar6 = pcVar8;

    } while (cVar1 != '\0');

    uVar4 = ~uVar4;

    iVar3 = -1;

    pcVar6 = param_3;

    do {

      pcVar7 = pcVar6;

      if (iVar3 == 0) break;

      iVar3 = iVar3 + -1;

      pcVar7 = pcVar6 + 1;

      cVar1 = *pcVar6;

      pcVar6 = pcVar7;

    } while (cVar1 != '\0');

    pcVar6 = pcVar8 + -uVar4;

    pcVar8 = pcVar7 + -1;

    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {

      *(undefined4 *)pcVar8 = *(undefined4 *)pcVar6;

      pcVar6 = pcVar6 + 4;

      pcVar8 = pcVar8 + 4;

    }

    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {

      *pcVar8 = *pcVar6;

      pcVar6 = pcVar6 + 1;

      pcVar8 = pcVar8 + 1;

    }

    uVar4 = 0xffffffff;

    pcVar6 = param_3;

    do {

      if (uVar4 == 0) break;

      uVar4 = uVar4 - 1;

      cVar1 = *pcVar6;

      pcVar6 = pcVar6 + 1;

    } while (cVar1 != '\0');

    sendto(*param_1,param_3,~uVar4 - 1,0,param_2,0x10);

    *param_3 = '\0';

  }

  return;

}

/* ===== comm_socket_sendto @ 0x0052DE90 ===== */
void comm_socket_sendto(SOCKET *param_1,sockaddr *param_2,char *param_3,char *param_4)



{

  char cVar1;

  SOCKET SVar2;

  char *pcVar3;

  uint uVar4;

  uint uVar5;

  int iVar6;

  char *pcVar7;

  char *pcVar8;

  bool bVar9;

  char local_50 [80];

  

  uVar4 = 0xffffffff;

  pcVar3 = param_3;

  do {

    if (uVar4 == 0) break;

    uVar4 = uVar4 - 1;

    cVar1 = *pcVar3;

    pcVar3 = pcVar3 + 1;

  } while (cVar1 != '\0');

  uVar5 = 0xffffffff;

  pcVar3 = param_4;

  do {

    if (uVar5 == 0) break;

    uVar5 = uVar5 - 1;

    cVar1 = *pcVar3;

    pcVar3 = pcVar3 + 1;

  } while (cVar1 != '\0');

  for (uVar4 = ~uVar4 + (~uVar5 - 2); 0x545 < uVar4; uVar4 = ~uVar4 + (~uVar5 - 2)) {

    uVar5 = 0;

    uVar4 = 0xffffffff;

    pcVar3 = param_4;

    do {

      if (uVar4 == 0) break;

      uVar4 = uVar4 - 1;

      cVar1 = *pcVar3;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

    if (~uVar4 - 1 < 0x547) {

      iVar6 = -1;

      pcVar3 = param_3;

      goto code_r0x0052df88;

    }

    iVar6 = 0;

    pcVar3 = param_4;

    pcVar8 = param_4;

    do {

      if (*pcVar3 == '\\') {

        uVar4 = uVar5 & 0x80000001;

        bVar9 = uVar4 == 0;

        if ((int)uVar4 < 0) {

          bVar9 = (uVar4 - 1 | 0xfffffffe) == 0xffffffff;

        }

        if (bVar9) {

          pcVar8 = pcVar3;

        }

        uVar5 = uVar5 + 1;

      }

      pcVar3 = pcVar3 + 1;

      iVar6 = iVar6 + 1;

    } while (iVar6 < 0x546);

    if (pcVar8 == param_4) {

      return;

    }

    *pcVar8 = '\0';

    comm_socket_sendto(param_1,param_2,param_3,param_4);

    uVar4 = 0xffffffff;

    *pcVar8 = '\\';

    pcVar3 = pcVar8;

    do {

      if (uVar4 == 0) break;

      uVar4 = uVar4 - 1;

      cVar1 = *pcVar3;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

    uVar5 = 0xffffffff;

    pcVar3 = param_3;

    do {

      if (uVar5 == 0) break;

      uVar5 = uVar5 - 1;

      cVar1 = *pcVar3;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

    param_4 = pcVar8;

  }

  uVar4 = 0xffffffff;

  do {

    pcVar3 = param_4;

    if (uVar4 == 0) break;

    uVar4 = uVar4 - 1;

    pcVar3 = param_4 + 1;

    cVar1 = *param_4;

    param_4 = pcVar3;

  } while (cVar1 != '\0');

  uVar4 = ~uVar4;

  iVar6 = -1;

  do {

    pcVar8 = param_3;

    if (iVar6 == 0) break;

    iVar6 = iVar6 + -1;

    pcVar8 = param_3 + 1;

    cVar1 = *param_3;

    param_3 = pcVar8;

  } while (cVar1 != '\0');

  pcVar3 = pcVar3 + -uVar4;

  pcVar8 = pcVar8 + -1;

  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {

    *(undefined4 *)pcVar8 = *(undefined4 *)pcVar3;

    pcVar3 = pcVar3 + 4;

    pcVar8 = pcVar8 + 4;

  }

  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {

    *pcVar8 = *pcVar3;

    pcVar3 = pcVar3 + 1;

    pcVar8 = pcVar8 + 1;

  }

  return;

  while( true ) {

    iVar6 = iVar6 + -1;

    cVar1 = *pcVar3;

    pcVar3 = pcVar3 + 1;

    if (cVar1 == '\0') break;

code_r0x0052df88:

    if (iVar6 == 0) break;

  }

  if (iVar6 != -2) {

    SVar2 = param_1[0x38];

    param_1[0x38] = SVar2 + 1;

    FUN_00542f27(local_50,s__queryid__d__d_0057f258,param_1[0x37],SVar2 + 1);

    uVar4 = 0xffffffff;

    pcVar3 = local_50;

    do {

      pcVar8 = pcVar3;

      if (uVar4 == 0) break;

      uVar4 = uVar4 - 1;

      pcVar8 = pcVar3 + 1;

      cVar1 = *pcVar3;

      pcVar3 = pcVar8;

    } while (cVar1 != '\0');

    uVar4 = ~uVar4;

    iVar6 = -1;

    pcVar3 = param_3;

    do {

      pcVar7 = pcVar3;

      if (iVar6 == 0) break;

      iVar6 = iVar6 + -1;

      pcVar7 = pcVar3 + 1;

      cVar1 = *pcVar3;

      pcVar3 = pcVar7;

    } while (cVar1 != '\0');

    pcVar3 = pcVar8 + -uVar4;

    pcVar8 = pcVar7 + -1;

    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {

      *(undefined4 *)pcVar8 = *(undefined4 *)pcVar3;

      pcVar3 = pcVar3 + 4;

      pcVar8 = pcVar8 + 4;

    }

    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {

      *pcVar8 = *pcVar3;

      pcVar3 = pcVar3 + 1;

      pcVar8 = pcVar8 + 1;

    }

    uVar4 = 0xffffffff;

    pcVar3 = param_3;

    do {

      if (uVar4 == 0) break;

      uVar4 = uVar4 - 1;

      cVar1 = *pcVar3;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

    sendto(*param_1,param_3,~uVar4 - 1,0,param_2,0x10);

    *param_3 = '\0';

  }

  iVar6 = (int)param_3 - (int)param_4;

  do {

    cVar1 = *param_4;

    param_4[iVar6] = cVar1;

    param_4 = param_4 + 1;

  } while (cVar1 != '\0');

  return;

}

/* ===== FUN_0052e030 @ 0x0052E030 ===== */
void FUN_0052e030(int param_1,undefined4 param_2,undefined4 param_3)



{

  undefined4 uVar1;

  int iVar2;

  undefined4 *puVar3;

  undefined1 local_578;

  undefined4 local_577;

  

  local_578 = DAT_00584374;

  puVar3 = &local_577;

  for (iVar2 = 0x15d; iVar2 != 0; iVar2 = iVar2 + -1) {

    *puVar3 = 0;

    puVar3 = puVar3 + 1;

  }

  uVar1 = *(undefined4 *)(param_1 + 0xec);

  *(undefined2 *)puVar3 = 0;

  *(undefined1 *)((int)puVar3 + 2) = 0;

  (**(code **)(param_1 + 200))(&local_578,0x578,uVar1);

  comm_socket_sendto(param_1,param_2,param_3,&local_578);

  return;

}

/* ===== FUN_0052e0a0 @ 0x0052E0A0 ===== */
void FUN_0052e0a0(int param_1,undefined4 param_2,undefined4 param_3)



{

  undefined4 uVar1;

  int iVar2;

  undefined4 *puVar3;

  undefined1 local_578;

  undefined4 local_577;

  

  local_578 = DAT_00584374;

  puVar3 = &local_577;

  for (iVar2 = 0x15d; iVar2 != 0; iVar2 = iVar2 + -1) {

    *puVar3 = 0;

    puVar3 = puVar3 + 1;

  }

  uVar1 = *(undefined4 *)(param_1 + 0xec);

  *(undefined2 *)puVar3 = 0;

  *(undefined1 *)((int)puVar3 + 2) = 0;

  (**(code **)(param_1 + 0xcc))(&local_578,0x578,uVar1);

  comm_socket_sendto(param_1,param_2,param_3,&local_578);

  return;

}

/* ===== FUN_0052e110 @ 0x0052E110 ===== */
void FUN_0052e110(int param_1,undefined4 param_2,undefined4 param_3)



{

  undefined4 uVar1;

  int iVar2;

  undefined4 *puVar3;

  undefined1 local_578;

  undefined4 local_577;

  

  local_578 = DAT_00584374;

  puVar3 = &local_577;

  for (iVar2 = 0x15d; iVar2 != 0; iVar2 = iVar2 + -1) {

    *puVar3 = 0;

    puVar3 = puVar3 + 1;

  }

  uVar1 = *(undefined4 *)(param_1 + 0xec);

  *(undefined2 *)puVar3 = 0;

  *(undefined1 *)((int)puVar3 + 2) = 0;

  (**(code **)(param_1 + 0xd0))(&local_578,0x578,uVar1);

  comm_socket_sendto(param_1,param_2,param_3,&local_578);

  return;

}

/* ===== FUN_0052e180 @ 0x0052E180 ===== */
void FUN_0052e180(int param_1,undefined4 param_2,undefined4 param_3)



{

  undefined4 uVar1;

  int iVar2;

  undefined4 *puVar3;

  undefined1 local_578;

  undefined4 local_577;

  

  local_578 = DAT_00584374;

  puVar3 = &local_577;

  for (iVar2 = 0x15d; iVar2 != 0; iVar2 = iVar2 + -1) {

    *puVar3 = 0;

    puVar3 = puVar3 + 1;

  }

  uVar1 = *(undefined4 *)(param_1 + 0xec);

  *(undefined2 *)puVar3 = 0;

  *(undefined1 *)((int)puVar3 + 2) = 0;

  (**(code **)(param_1 + 0xd4))(&local_578,0x578,uVar1);

  comm_socket_sendto(param_1,param_2,param_3,&local_578);

  return;

}

/* ===== FUN_0052e1f0 @ 0x0052E1F0 ===== */
void FUN_0052e1f0(undefined4 param_1,undefined4 param_2,undefined4 param_3,char *param_4)



{

  char cVar1;

  uint uVar2;

  char *pcVar3;

  undefined1 local_578 [1400];

  

  uVar2 = 0xffffffff;

  pcVar3 = param_4;

  do {

    if (uVar2 == 0) break;

    uVar2 = uVar2 - 1;

    cVar1 = *pcVar3;

    pcVar3 = pcVar3 + 1;

  } while (cVar1 != '\0');

  if (~uVar2 - 1 < 0x547) {

    FUN_00542f27(local_578,s__echo__s_0057f268,param_4);

    comm_socket_sendto(param_1,param_2,param_3,local_578);

  }

  return;

}

/* ===== FUN_0052e250 @ 0x0052E250 ===== */
/* PS2 candidate: new_fire__FP6OBJECTiPfT0P3P3Df (conf 0.495) */



void FUN_0052e250(SOCKET *param_1,sockaddr *param_2,char *param_3,char *param_4)



{

  char cVar1;

  int iVar2;

  SOCKET SVar3;

  uint uVar4;

  int iVar5;

  uint uVar6;

  char *pcVar7;

  SOCKET *pSVar8;

  char *pcVar9;

  char *pcVar10;

  char local_248 [128];

  undefined1 local_1c8 [256];

  undefined1 local_c8 [200];

  

  if (*param_4 != '\0') {

    uVar4 = 0xffffffff;

    pcVar7 = param_4;

    do {

      if (uVar4 == 0) break;

      uVar4 = uVar4 - 1;

      cVar1 = *pcVar7;

      pcVar7 = pcVar7 + 1;

    } while (cVar1 != '\0');

    iVar5 = ~uVar4 - 1;

    if (0x80 < iVar5) {

      return;

    }

    iVar2 = -(int)param_4;

    do {

      cVar1 = *param_4;

      param_4[(int)(local_248 + iVar2)] = cVar1;

      param_4 = param_4 + 1;

    } while (cVar1 != '\0');

    uVar4 = 0xffffffff;

    pSVar8 = param_1 + 0x12;

    do {

      if (uVar4 == 0) break;

      uVar4 = uVar4 - 1;

      SVar3 = *pSVar8;

      pSVar8 = (SOCKET *)((int)pSVar8 + 1);

    } while ((char)SVar3 != '\0');

    comm_packet_decode(param_1 + 0x12,~uVar4 - 1,local_248,iVar5);

    FUN_0052dbb0(local_248,iVar5,local_c8);

    FUN_00542f27(local_1c8,s__validate__s_0057f27c,local_c8);

    comm_socket_sendto(param_1,param_2,param_3,local_1c8);

  }

  FUN_00542f27(local_1c8,s__final__0057f274);

  comm_socket_sendto(param_1,param_2,param_3,local_1c8);

  iVar5 = -1;

  pcVar7 = param_3;

  do {

    if (iVar5 == 0) break;

    iVar5 = iVar5 + -1;

    cVar1 = *pcVar7;

    pcVar7 = pcVar7 + 1;

  } while (cVar1 != '\0');

  if (iVar5 != -2) {

    SVar3 = param_1[0x38];

    param_1[0x38] = SVar3 + 1;

    FUN_00542f27(local_248,s__queryid__d__d_0057f258,param_1[0x37],SVar3 + 1);

    uVar4 = 0xffffffff;

    pcVar7 = local_248;

    do {

      pcVar10 = pcVar7;

      if (uVar4 == 0) break;

      uVar4 = uVar4 - 1;

      pcVar10 = pcVar7 + 1;

      cVar1 = *pcVar7;

      pcVar7 = pcVar10;

    } while (cVar1 != '\0');

    uVar4 = ~uVar4;

    iVar5 = -1;

    pcVar7 = param_3;

    do {

      pcVar9 = pcVar7;

      if (iVar5 == 0) break;

      iVar5 = iVar5 + -1;

      pcVar9 = pcVar7 + 1;

      cVar1 = *pcVar7;

      pcVar7 = pcVar9;

    } while (cVar1 != '\0');

    pcVar7 = pcVar10 + -uVar4;

    pcVar10 = pcVar9 + -1;

    for (uVar6 = uVar4 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {

      *(undefined4 *)pcVar10 = *(undefined4 *)pcVar7;

      pcVar7 = pcVar7 + 4;

      pcVar10 = pcVar10 + 4;

    }

    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {

      *pcVar10 = *pcVar7;

      pcVar7 = pcVar7 + 1;

      pcVar10 = pcVar10 + 1;

    }

    uVar4 = 0xffffffff;

    pcVar7 = param_3;

    do {

      if (uVar4 == 0) break;

      uVar4 = uVar4 - 1;

      cVar1 = *pcVar7;

      pcVar7 = pcVar7 + 1;

    } while (cVar1 != '\0');

    sendto(*param_1,param_3,~uVar4 - 1,0,param_2,0x10);

    *param_3 = '\0';

  }

  return;

}

/* ===== FUN_0052e3d0 @ 0x0052E3D0 ===== */
void FUN_0052e3d0(void)



{

  int iVar1;

  undefined4 *puVar2;

  

  puVar2 = &DAT_005dfed8;

  for (iVar1 = 0x101; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar2 = 0;

    puVar2 = puVar2 + 1;

  }

  puVar2 = &DAT_005e2310;

  for (iVar1 = 0x101; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar2 = 0;

    puVar2 = puVar2 + 1;

  }

  puVar2 = &DAT_005df2c0;

  for (iVar1 = 0x101; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar2 = 0;

    puVar2 = puVar2 + 1;

  }

  puVar2 = &DAT_005dfad0;

  for (iVar1 = 0x101; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar2 = 0;

    puVar2 = puVar2 + 1;

  }

  puVar2 = &DAT_005df6c8;

  for (iVar1 = 0x101; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar2 = 0;

    puVar2 = puVar2 + 1;

  }

  puVar2 = &DAT_005e02e0;

  for (iVar1 = 0x80b; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar2 = 0;

    puVar2 = puVar2 + 1;

  }

  DAT_005dfed8 = &DAT_005dfedc;

  DAT_005e2310 = &DAT_005e2314;

  DAT_005df2c0 = &DAT_005df2c4;

  DAT_005dfad0 = &DAT_005dfad4;

  DAT_005df6c8 = &DAT_005df6cc;

  DAT_005e0308 = &DAT_005e030c;

  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_005e02ec);

  return;

}

/* ===== FUN_0052E470 @ 0x0052E470 ===== */
void FUN_0052E470(void)



{

  DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_005e02ec);

  return;

}

/* ===== FUN_0052e480 @ 0x0052E480 ===== */
/* PS2 candidate: fx_create (conf 0.587) */



undefined4 FUN_0052e480(void)



{

  int iVar1;

  undefined4 uVar2;

  

  iVar1 = FUN_0052aa70();

  if (iVar1 == 0) {

    return 1;

  }

  uVar2 = FUN_0052aa80();

  return uVar2;

}

/* ===== reaper_0052e4a0 @ 0x0052E4A0 ===== */
/* PS2 candidate: ObjectSetAnim (conf 0.491) */



void reaper_0052e4a0(void)



{

  int iVar1;

  

  iVar1 = FUN_0052aa70();

  if (iVar1 == 0) {

    return;

  }

  FUN_0052aa80();

  return;

}

/* ===== FUN_0052e4b0 @ 0x0052E4B0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined4 FUN_0052e4b0(undefined4 param_1)



{

  int iVar1;

  

  iVar1 = FUN_0052aa70();

  if (iVar1 == 0) {

    return 0;

  }

  iVar1 = FUN_0052aa80(param_1);

  if (iVar1 == 0) {

    return 0;

  }

  if (DAT_005e2720 != DAT_00632e70) {

    if (DAT_00632e6c < _DAT_005e271c) {

      return 0;

    }

    if (DAT_00633210 != 0) {

      DAT_005e2720 = DAT_00632e70;

      _DAT_005e271c = DAT_00632e6c + 0.5;

      return 1;

    }

    _DAT_005e271c = DAT_00632e6c + 1.0;

    DAT_005e2720 = DAT_00632e70;

  }

  return 1;

}

/* ===== FUN_0052e530 @ 0x0052E530 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined4 FUN_0052e530(undefined4 param_1)



{

  int iVar1;

  

  iVar1 = FUN_0052aa70();

  if (iVar1 == 0) {

    return 0;

  }

  iVar1 = FUN_0052aa80(param_1);

  if (iVar1 == 0) {

    return 0;

  }

  if (DAT_005e2728 != DAT_00632e70) {

    if (DAT_00632e6c < _DAT_005e2724) {

      return 0;

    }

    if (DAT_00633210 != 0) {

      DAT_005e2728 = DAT_00632e70;

      _DAT_005e2724 = DAT_00632e6c + 0.05;

      return 1;

    }

    _DAT_005e2724 = DAT_00632e6c + 0.1;

    DAT_005e2728 = DAT_00632e70;

  }

  return 1;

}

/* ===== FUN_0052e5b0 @ 0x0052E5B0 ===== */
/* PS2 candidate: objanim_select_animloop (conf 0.378) */



int FUN_0052e5b0(int param_1)



{

  int iVar1;

  undefined4 *puVar2;

  

  puVar2 = DAT_00632d68;

  while( true ) {

    if (puVar2 == (undefined4 *)0x0) {

      return 0;

    }

    iVar1 = puVar2[3];

    if (((*(uint *)(iVar1 + 0xd8) & 0x8000) == 0) && (*(int *)(iVar1 + 0x188) == param_1)) break;

    puVar2 = (undefined4 *)*puVar2;

  }

  return iVar1;

}

/* ===== comm_player_name_user @ 0x0052E5E0 ===== */
void comm_player_name_user(void)



{

  char cVar1;

  int iVar2;

  char *pcVar3;

  size_t _Count;

  int local_108;

  int local_104;

  undefined1 local_100;

  undefined1 local_ff;

  char local_fe [32];

  undefined1 local_de;

  

  iVar2 = FUN_0052aa70();

  if (iVar2 != 0) {

    FUN_0052b460(&local_108,&local_104);

    iVar2 = 0;

    local_100 = 3;

    local_ff = (undefined1)local_108;

    pcVar3 = local_fe;

    if (0 < local_108) {

      do {

        *(undefined4 *)pcVar3 = *(undefined4 *)(local_104 + iVar2 * 4);

        pcVar3 = pcVar3 + 4;

        iVar2 = iVar2 + 1;

      } while (iVar2 < local_108);

    }

    iVar2 = 0;

    if (0 < local_108) {

      do {

        cVar1 = FUN_0052ac40(iVar2);

        *pcVar3 = cVar1;

        pcVar3 = pcVar3 + 1;

        iVar2 = iVar2 + 1;

      } while (iVar2 < local_108);

    }

    iVar2 = 0;

    if (0 < local_108) {

      do {

        cVar1 = comm_0052ab50(iVar2);

        *pcVar3 = cVar1;

        pcVar3 = pcVar3 + 1;

        iVar2 = iVar2 + 1;

      } while (iVar2 < local_108);

    }

    *pcVar3 = '\0';

    comm_0052b780(0,pcVar3 + (1 - (int)&local_100),&local_100);

    iVar2 = 0;

    if (0 < local_108) {

      do {

        if (*(int *)(local_104 + iVar2 * 4) != 0) {

          _Count = 0x20;

          local_100 = 0x44;

          local_ff = (undefined1)iVar2;

          pcVar3 = (char *)comm_player_name3(iVar2);

          _strncpy(local_fe,pcVar3,_Count);

          local_de = 0;

          comm_0052b780(0,0x23,&local_100);

        }

        iVar2 = iVar2 + 1;

      } while (iVar2 < local_108);

    }

  }

  return;

}

/* ===== comm_0052e6e0 @ 0x0052E6E0 ===== */
void comm_0052e6e0(char *param_1,int param_2)



{

  char cVar1;

  byte bVar2;

  int iVar3;

  int iVar4;

  undefined4 uVar5;

  char *pcVar6;

  uint uVar7;

  uint uVar8;

  uint uVar9;

  char *pcVar10;

  undefined4 local_304;

  undefined2 local_300;

  undefined1 local_201;

  char local_200 [512];

  

  iVar3 = FUN_0052c5c0();

  if (iVar3 == 0) {

    uVar8 = 0xffffffff;

    pcVar6 = param_1;

    do {

      if (uVar8 == 0) break;

      uVar8 = uVar8 - 1;

      cVar1 = *pcVar6;

      pcVar6 = pcVar6 + 1;

    } while (cVar1 != '\0');

    comm_dp_send(~uVar8 + 1,param_1);

    bVar2 = param_1[2];

    if ((int)((byte)param_1[1] & 0x7f) <= DAT_00632f34 + -1) {

      pcVar6 = (char *)comm_player_name3((byte)param_1[1] & 0x7f);

      if ((bVar2 & 0x40) != 0) {

        local_300 = (ushort)local_300._1_1_ << 8;

        if ((bVar2 & 0x20) != 0) {

          local_300 = DAT_0057fd7c;

        }

        _strncat((char *)&local_300,pcVar6,0xfe);

        if ((bVar2 & 0x20) != 0) {

          iVar3 = -1;

          pcVar6 = (char *)&local_300;

          do {

            pcVar10 = pcVar6;

            if (iVar3 == 0) break;

            iVar3 = iVar3 + -1;

            pcVar10 = pcVar6 + 1;

            cVar1 = *pcVar6;

            pcVar6 = pcVar10;

          } while (cVar1 != '\0');

          *(undefined2 *)(pcVar10 + -1) = DAT_0057fd78;

        }

        uVar8 = 0xffffffff;

        local_201 = 0;

        pcVar6 = (char *)&local_300;

        do {

          if (uVar8 == 0) break;

          uVar8 = uVar8 - 1;

          cVar1 = *pcVar6;

          pcVar6 = pcVar6 + 1;

        } while (cVar1 != '\0');

        _strncpy((char *)((int)&local_304 + ~uVar8 + 3),(char *)&DAT_00555928,0xff - (~uVar8 - 1));

        uVar8 = 0xffffffff;

        local_201 = 0;

        pcVar6 = (char *)&local_300;

        do {

          if (uVar8 == 0) break;

          uVar8 = uVar8 - 1;

          cVar1 = *pcVar6;

          pcVar6 = pcVar6 + 1;

        } while (cVar1 != '\0');

        _strncpy((char *)((int)&local_304 + ~uVar8 + 3),param_1 + 3,0xff - (~uVar8 - 1));

        local_201 = 0;

        comm_005363f0(&local_300,bVar2 & 0xf);

        return;

      }

      comm_005363f0(param_1 + 3,bVar2 & 0xf);

    }

  }

  else {

    uVar8 = (byte)param_1[1] & 0x7f;

    local_304 = (byte)param_1[2] & 0x20;

    if ((int)uVar8 <= DAT_00632f34 + -1) {

      pcVar6 = local_200;

      for (iVar3 = 0x80; iVar3 != 0; iVar3 = iVar3 + -1) {

        pcVar6[0] = '\0';

        pcVar6[1] = '\0';

        pcVar6[2] = '\0';

        pcVar6[3] = '\0';

        pcVar6 = pcVar6 + 4;

      }

      iVar3 = -(int)param_1;

      do {

        cVar1 = *param_1;

        param_1[(int)(local_200 + iVar3)] = cVar1;

        param_1 = param_1 + 1;

      } while (cVar1 != '\0');

      uVar7 = 0xffffffff;

      pcVar6 = local_200;

      do {

        if (uVar7 == 0) break;

        uVar7 = uVar7 - 1;

        cVar1 = *pcVar6;

        pcVar6 = pcVar6 + 1;

      } while (cVar1 != '\0');

      uVar9 = 1;

      local_200[~uVar7] = '\0';

      if (1 < DAT_00632f34) {

        do {

          iVar3 = FUN_0052ab00(uVar9);

          if ((iVar3 != 0) && (uVar9 != uVar8)) {

            if (local_304 != 0) {

              iVar3 = comm_0052ab50(uVar9);

              iVar4 = comm_0052ab50(uVar8);

              if (iVar3 != iVar4) goto LAB_0052e7e9;

            }

            if ((param_2 == 0) || (iVar3 = FUN_0052ab00(uVar9), iVar3 == param_2)) {

              uVar7 = 0xffffffff;

              pcVar6 = local_200;

              do {

                if (uVar7 == 0) break;

                uVar7 = uVar7 - 1;

                cVar1 = *pcVar6;

                pcVar6 = pcVar6 + 1;

              } while (cVar1 != '\0');

              uVar5 = FUN_0052ab00(uVar9,~uVar7 + 1,local_200);

              FUN_0052b5a0(uVar5);

            }

          }

LAB_0052e7e9:

          uVar9 = uVar9 + 1;

        } while ((int)uVar9 < DAT_00632f34);

      }

      if (local_304 != 0) {

        iVar3 = comm_0052ab50(uVar8);

        iVar4 = comm_0052ab50(0);

        if ((iVar4 != iVar3) && (DAT_00633238 == 0)) {

          return;

        }

      }

      if ((int)((byte)local_200[1] & 0x7f) <= DAT_00632f34 + -1) {

        pcVar6 = (char *)comm_player_name3((byte)local_200[1] & 0x7f);

        if ((local_200[2] & 0x40U) == 0) {

          comm_005363f0(local_200 + 3,local_200[2] & 0xfU);

          return;

        }

        local_300 = (ushort)local_300._1_1_ << 8;

        if ((local_200[2] & 0x20U) != 0) {

          local_300 = DAT_0057fd7c;

        }

        _strncat((char *)&local_300,pcVar6,0xfe);

        if ((local_200[2] & 0x20U) != 0) {

          iVar3 = -1;

          pcVar6 = (char *)&local_300;

          do {

            pcVar10 = pcVar6;

            if (iVar3 == 0) break;

            iVar3 = iVar3 + -1;

            pcVar10 = pcVar6 + 1;

            cVar1 = *pcVar6;

            pcVar6 = pcVar10;

          } while (cVar1 != '\0');

          *(undefined2 *)(pcVar10 + -1) = DAT_0057fd78;

        }

        uVar8 = 0xffffffff;

        local_201 = 0;

        pcVar6 = (char *)&local_300;

        do {

          if (uVar8 == 0) break;

          uVar8 = uVar8 - 1;

          cVar1 = *pcVar6;

          pcVar6 = pcVar6 + 1;

        } while (cVar1 != '\0');

        _strncpy((char *)((int)&local_304 + ~uVar8 + 3),(char *)&DAT_00555928,0xff - (~uVar8 - 1));

        uVar8 = 0xffffffff;

        local_201 = 0;

        pcVar6 = (char *)&local_300;

        do {

          if (uVar8 == 0) break;

          uVar8 = uVar8 - 1;

          cVar1 = *pcVar6;

          pcVar6 = pcVar6 + 1;

        } while (cVar1 != '\0');

        _strncpy((char *)((int)&local_304 + ~uVar8 + 3),local_200 + 3,0xff - (~uVar8 - 1));

        local_201 = 0;

        comm_005363f0(&local_300,local_200[2] & 0xfU);

        return;

      }

    }

  }

  return;

}

/* ===== comm_audio_volume_user @ 0x0052EA80 ===== */
void comm_audio_volume_user(char *param_1,undefined4 param_2,byte param_3,undefined4 param_4)



{

  char cVar1;

  int iVar2;

  undefined4 uVar3;

  int iVar4;

  uint uVar5;

  uint uVar6;

  char *pcVar7;

  char *pcVar8;

  char *pcVar9;

  char local_200 [512];

  

  iVar2 = FUN_0052aa70();

  if (iVar2 == 0) {

    FUN_005362d0(param_1,param_2);

    return;

  }

  uVar3 = AudioGetMasterVolume__Fv_9();

  iVar2 = comm_0052ab20(uVar3);

  if ((-1 < iVar2) && (iVar2 <= DAT_00632f34 + -1)) {

    pcVar7 = local_200;

    for (iVar4 = 0x80; iVar4 != 0; iVar4 = iVar4 + -1) {

      *(undefined4 *)pcVar7 = 0;

      pcVar7 = (char *)((int)pcVar7 + 4);

    }

    local_200[1] = (byte)iVar2 | 0x80;

    local_200[2] = (byte)param_2 | param_3 | 0x80;

    local_200[3] = 0;

    local_200[0] = '<';

    uVar5 = 0xffffffff;

    do {

      pcVar7 = param_1;

      if (uVar5 == 0) break;

      uVar5 = uVar5 - 1;

      pcVar7 = param_1 + 1;

      cVar1 = *param_1;

      param_1 = pcVar7;

    } while (cVar1 != '\0');

    uVar5 = ~uVar5;

    iVar2 = -1;

    pcVar9 = local_200;

    do {

      pcVar8 = pcVar9;

      if (iVar2 == 0) break;

      iVar2 = iVar2 + -1;

      pcVar8 = pcVar9 + 1;

      cVar1 = *pcVar9;

      pcVar9 = pcVar8;

    } while (cVar1 != '\0');

    pcVar7 = pcVar7 + -uVar5;

    pcVar9 = pcVar8 + -1;

    for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {

      *(undefined4 *)pcVar9 = *(undefined4 *)pcVar7;

      pcVar7 = pcVar7 + 4;

      pcVar9 = pcVar9 + 4;

    }

    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {

      *pcVar9 = *pcVar7;

      pcVar7 = pcVar7 + 1;

      pcVar9 = pcVar9 + 1;

    }

    comm_0052e6e0(local_200,param_4);

  }

  return;

}

/* ===== comm_team_broadcast_send @ 0x0052EB60 ===== */
void comm_team_broadcast_send(undefined4 param_1,undefined1 param_2)



{

  int iVar1;

  uint uVar2;

  undefined1 local_8;

  undefined1 local_7;

  undefined4 local_6;

  char local_2;

  undefined1 local_1;

  

  iVar1 = FUN_0052aa70();

  if (iVar1 != 0) {

    iVar1 = FUN_0052c5c0();

    if (iVar1 != 0) {

      local_8 = 0x12;

      local_6 = FUN_0052ab00(param_1);

      local_7 = param_2;

      uVar2 = FUN_0052ac40(param_1);

      local_2 = '\x01' - (uVar2 < 0xe);

      local_1 = 0;

      comm_team_broadcast_menu(&local_8);

      comm_0052b780(0,8,&local_8);

    }

  }

  return;

}

/* ===== comm_team_broadcast_menu @ 0x0052EBD0 ===== */
void comm_team_broadcast_menu(int param_1)



{

  char cVar1;

  undefined4 *puVar2;

  uint uVar3;

  int iVar4;

  uint uVar5;

  uint uVar6;

  undefined4 uVar7;

  int iVar8;

  int iVar9;

  char *pcVar10;

  char *pcVar11;

  char *pcVar12;

  char local_280 [128];

  char local_200 [512];

  

  uVar3 = comm_0052ab20(*(undefined4 *)(param_1 + 2));

  iVar4 = FUN_0052aa70();

  if (iVar4 == 0) {

    return;

  }

  if ((int)uVar3 < 0) {

    return;

  }

  uVar5 = comm_0052ab50(uVar3);

  uVar6 = comm_0052b430();

  if (uVar3 == uVar6) {

    DAT_00632f14 = (uint)*(byte *)(param_1 + 1);

    comm_team_name(0xffffffff,*(undefined1 *)(param_1 + 1),0);

  }

  FUN_0052ab70(uVar3,*(undefined1 *)(param_1 + 1));

  if ((((DAT_00632f08 < 0xe) || (uVar5 == *(byte *)(param_1 + 1))) || (*(byte *)(param_1 + 1) == 0))

     || (*(char *)(param_1 + 6) == '\0')) goto LAB_0052eee6;

  iVar4 = FUN_0052c5c0();

  if (iVar4 != 0) {

    uVar7 = comm_team_name2(*(undefined1 *)(param_1 + 1));

    uVar7 = comm_player_name3(uVar3,uVar7);

    uVar7 = FUN_00507b00(s_CommChgTeamBroadcast_0057fd80,uVar7);

    FUN_00542f27(local_280,uVar7);

    iVar4 = FUN_0052aa70();

    if (iVar4 == 0) {

      FUN_005362d0(local_280,1);

    }

    else {

      uVar7 = AudioGetMasterVolume__Fv_9();

      iVar4 = comm_0052ab20(uVar7);

      if ((-1 < iVar4) && (iVar4 <= DAT_00632f34 + -1)) {

        pcVar10 = local_200;

        for (iVar9 = 0x80; iVar9 != 0; iVar9 = iVar9 + -1) {

          pcVar10[0] = '\0';

          pcVar10[1] = '\0';

          pcVar10[2] = '\0';

          pcVar10[3] = '\0';

          pcVar10 = pcVar10 + 4;

        }

        uVar5 = 0xffffffff;

        local_200[1] = (byte)iVar4 | 0x80;

        local_200[3] = 0;

        local_200[0] = '<';

        local_200[2] = 0x81;

        pcVar10 = local_280;

        do {

          pcVar12 = pcVar10;

          if (uVar5 == 0) break;

          uVar5 = uVar5 - 1;

          pcVar12 = pcVar10 + 1;

          cVar1 = *pcVar10;

          pcVar10 = pcVar12;

        } while (cVar1 != '\0');

        uVar5 = ~uVar5;

        iVar4 = -1;

        pcVar10 = local_200;

        do {

          pcVar11 = pcVar10;

          if (iVar4 == 0) break;

          iVar4 = iVar4 + -1;

          pcVar11 = pcVar10 + 1;

          cVar1 = *pcVar10;

          pcVar10 = pcVar11;

        } while (cVar1 != '\0');

        pcVar10 = pcVar12 + -uVar5;

        pcVar12 = pcVar11 + -1;

        for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {

          *(undefined4 *)pcVar12 = *(undefined4 *)pcVar10;

          pcVar10 = pcVar10 + 4;

          pcVar12 = pcVar12 + 4;

        }

        for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {

          *pcVar12 = *pcVar10;

          pcVar10 = pcVar10 + 1;

          pcVar12 = pcVar12 + 1;

        }

        comm_0052e6e0(local_200,0);

      }

    }

  }

  iVar4 = 2;

  puVar2 = DAT_00632d68;

  if (DAT_00632f10 != 0) {

    if (DAT_00632f10 == 1) {

      iVar4 = 3;

    }

    else if (DAT_00632f10 == 2) {

      iVar4 = (*(char *)(param_1 + 1) != '\x01') + 2;

    }

    else if (DAT_00632f10 == 3) {

LAB_0052edc5:

      if (*(char *)(param_1 + 1) == '\x01') {

        iVar4 = 2;

      }

      else {

        iVar4 = (uint)(*(char *)(param_1 + 1) == '\x02') * 2 + 1;

      }

    }

    else if (DAT_00632f10 == 4) {

      if (*(char *)(param_1 + 1) == '\x01') {

        iVar4 = 2;

      }

      else {

        iVar4 = (uint)(*(char *)(param_1 + 1) == '\x02') * 2 + 1;

      }

    }

    else if (DAT_00632f10 == 5) goto LAB_0052edc5;

  }

  while( true ) {

    if (puVar2 == (undefined4 *)0x0) {

      return;

    }

    iVar9 = puVar2[3];

    iVar8 = FUN_004a61e0(iVar9);

    if ((iVar8 != 0) && ((*(uint *)(iVar9 + 0x188) & 0xff) == uVar3)) break;

    puVar2 = (undefined4 *)*puVar2;

  }

  iVar8 = FUN_004a6160(iVar9);

  if (iVar8 == 0) {

    iVar8 = FUN_004a6180(iVar9);

    if (iVar8 == 0) {

      iVar8 = FUN_004a61a0(iVar9);

      if (iVar8 != 0) {

        *(int *)(*(int *)(iVar9 + 0x100) + 0x348) = iVar4;

      }

    }

    else {

      *(int *)(*(int *)(iVar9 + 0x100) + 0xffc) = iVar4;

    }

  }

  else {

    *(int *)(*(int *)(iVar9 + 0x100) + 0x20c) = iVar4;

  }

  *(uint *)(iVar9 + 0x18c) = *(byte *)(param_1 + 1) + 1;

  iVar4 = FUN_004a6160(iVar9);

  if (iVar4 != 0) {

    *(undefined4 *)(*(int *)(iVar9 + 0x100) + 0xd8) = 0;

  }

  iVar4 = FUN_004a6180(iVar9);

  if (iVar4 != 0) {

    *(undefined4 *)(*(int *)(iVar9 + 0x100) + 0xcfc) = 0;

  }

  iVar4 = FUN_0052aa70();

  if ((iVar4 == 0) || (iVar4 = FUN_0052aa80(iVar9), iVar4 != 0)) {

    obj_damage_apply(0x13,0x461c4000,iVar9,0,0,0);

  }

LAB_0052eee6:

  gamespy_statechange3();

  return;

}

/* ===== FUN_0052EF00 @ 0x0052EF00 ===== */
void FUN_0052EF00(undefined4 param_1,undefined4 param_2)



{

  int iVar1;

  undefined4 uVar2;

  uint uVar3;

  undefined1 local_18;

  undefined4 local_17;

  undefined1 uStack_13;

  char cStack_12;

  undefined1 uStack_11;

  undefined1 uStack_10;

  undefined4 local_f;

  undefined1 local_b;

  undefined1 local_8;

  byte local_7;

  undefined4 local_6;

  undefined1 local_1;

  

  iVar1 = FUN_0052aa70();

  if (iVar1 != 0) {

    local_8 = 0x31;

    local_6 = FUN_0052ab00(param_1);

    local_7 = (DAT_005ddb54 != 0) << 7 | (byte)param_2;

    local_1 = 0;

    iVar1 = FUN_0052c5c0();

    if (iVar1 == 0) {

      iVar1 = AudioGetMasterVolume__Fv_9();

      if (DAT_005def94 == iVar1) {

        iVar1 = FUN_00525140(0xffffffff,param_2);

        if (iVar1 != 0) {

          uVar2 = FUN_0052ab00(param_1);

          iVar1 = FUN_0052aa70();

          if (iVar1 != 0) {

            local_18 = 0x4e;

            local_17 = AudioGetMasterVolume__Fv_9();

            uStack_13 = (undefined1)uVar2;

            cStack_12 = (char)((uint)uVar2 >> 8);

            uStack_11 = (undefined1)((uint)uVar2 >> 0x10);

            uStack_10 = (undefined1)((uint)uVar2 >> 0x18);

            local_f = param_2;

            local_b = 0;

            comm_dp_send(0xe,&local_18);

            return;

          }

        }

      }

      else {

        comm_dp_send(8,&local_8);

      }

    }

    else {

      iVar1 = FUN_00525140(0xffffffff,param_2);

      if (iVar1 != 0) {

        iVar1 = FUN_0052aa70();

        if (iVar1 != 0) {

          iVar1 = FUN_0052c5c0();

          if (iVar1 != 0) {

            local_18 = 0x12;

            uVar2 = FUN_0052ab00(param_1);

            uStack_13 = (undefined1)((uint)uVar2 >> 0x18);

            local_17 = CONCAT31((int3)uVar2,(byte)param_2);

            uVar3 = FUN_0052ac40(param_1);

            cStack_12 = '\x01' - (uVar3 < 0xe);

            uStack_11 = 0;

            comm_team_broadcast_menu(&local_18);

            comm_0052b780(0,8,&local_18);

            return;

          }

        }

      }

    }

  }

  return;

}

/* ===== comm_entergame_msg_1 @ 0x0052F040 ===== */
void comm_entergame_msg_1(undefined4 param_1)



{

  undefined4 uVar1;

  undefined4 uVar2;

  undefined4 uVar3;

  undefined1 local_c8 [200];

  

  uVar1 = comm_player_name3(param_1);

  uVar2 = comm_0052ab50(param_1);

  uVar2 = comm_team_name2(uVar2);

  uVar3 = FUN_00507b00(s_MPChEnterGame_0057fd98);

  FUN_00542f27(local_c8,uVar3,uVar1,uVar2);

  comm_005363f0(local_c8,1);

  return;

}

/* ===== comm_entergame_msg_2 @ 0x0052F0A0 ===== */
void comm_entergame_msg_2(int param_1)



{

  undefined4 uVar1;

  int iVar2;

  undefined4 uVar3;

  undefined4 uVar4;

  undefined1 local_d4;

  undefined4 local_d3;

  int local_cf;

  undefined1 local_cb;

  undefined1 local_c8 [200];

  

  DAT_00632f08 = param_1;

  uVar1 = comm_0052b430(param_1);

  comm_0052ac60(uVar1);

  iVar2 = FUN_0052aa70();

  if (iVar2 != 0) {

    local_d4 = 0x11;

    local_d3 = AudioGetMasterVolume__Fv_9();

    local_cf = DAT_00632f08;

    local_cb = 0;

    iVar2 = FUN_0052c5c0();

    if (iVar2 == 0) {

      comm_dp_send(10,&local_d4);

    }

    else {

      comm_0052b780(0);

      if ((DAT_00632f08 == 0xe) && (DAT_00633238 == 0)) {

        uVar1 = comm_player_name3(0);

        uVar3 = comm_0052ab50(0);

        uVar3 = comm_team_name2(uVar3);

        uVar4 = FUN_00507b00(s_MPChEnterGame_0057fd98);

        FUN_00542f27(local_c8,uVar4,uVar1,uVar3);

        comm_005363f0(local_c8,1);

        return;

      }

    }

  }

  return;

}

/* ===== comm_0052b780_user_1 @ 0x0052F170 ===== */
void comm_0052b780_user_1(int param_1)



{

  uint *puVar1;

  int iVar2;

  int *piVar3;

  undefined1 local_18;

  uint local_17 [5];

  undefined1 local_3;

  

  puVar1 = local_17;

  piVar3 = &DAT_00632fc4;

  do {

    iVar2 = piVar3[-1];

    local_18 = 0x2e;

    local_3 = 0;

    *puVar1 = 0;

    if (iVar2 != 0) {

      *puVar1 = 0x80000000;

    }

    if (*piVar3 != 0) {

      *puVar1 = *puVar1 | 0x40000000;

    }

    if (piVar3[1] != 0) {

      *puVar1 = *puVar1 | 0x20000000;

    }

    *puVar1 = *puVar1 | piVar3[2] & 0xffffU;

    piVar3 = piVar3 + 4;

    puVar1 = puVar1 + 1;

  } while ((int)piVar3 < 0x633014);

  iVar2 = FUN_0052aa70();

  if (iVar2 != 0) {

    if (param_1 != 0) {

      FUN_0052b4e0(param_1,0x16,&local_18);

      return;

    }

    comm_0052b780(0,0x16,&local_18);

  }

  return;

}

/* ===== FUN_0052f210 @ 0x0052F210 ===== */
void FUN_0052f210(void)



{

  int iVar1;

  undefined4 uStack_4;

  

  iVar1 = FUN_0052aa70();

  if (iVar1 != 0) {

    uStack_4 = (uint)CONCAT12(0x2f,(undefined2)uStack_4);

    comm_dp_send(2,(int)&uStack_4 + 2);

  }

  return;

}

/* ===== comm_0052b780_user_2 @ 0x0052F240 ===== */
void comm_0052b780_user_2(void)



{

  undefined2 in_CX;

  undefined4 uStack_4;

  

  if (DAT_00632f44 != 0) {

    uStack_4 = (uint)CONCAT12(0x3d,in_CX);

    comm_0052b780(0,2,(int)&uStack_4 + 2);

  }

  return;

}

/* ===== comm_0052b430_user @ 0x0052F270 ===== */
void comm_0052b430_user(void)



{

  undefined4 uVar1;

  undefined1 uVar2;

  undefined4 in_ECX;

  undefined1 local_4;

  undefined3 local_3;

  

  if (DAT_00632f44 == 0) {

    _local_4 = CONCAT31((int3)((uint)in_ECX >> 8),0x41);

    uVar2 = comm_0052b430();

    uVar1 = _local_4;

    local_3._2_1_ = SUB41(uVar1,3);

    _local_4 = (uint3)CONCAT11(uVar2,local_4);

    comm_dp_send(3,&local_4);

  }

  return;

}

/* ===== comm_0052b780_user_3 @ 0x0052F2A0 ===== */
void comm_0052b780_user_3(int param_1)



{

  int iVar1;

  undefined1 local_c;

  undefined4 local_b;

  undefined4 local_7;

  undefined1 local_3;

  

  iVar1 = FUN_0052aa70();

  if (iVar1 != 0) {

    local_b = DAT_00632f30;

    local_c = 0x30;

    local_7 = DAT_00633010;

    local_3 = 0;

    if (param_1 != 0) {

      FUN_0052b5a0(param_1,10,&local_c);

      return;

    }

    comm_0052b780(0,10,&local_c);

  }

  return;

}

/* ===== comm_0052b780_user_4 @ 0x0052F300 ===== */
void comm_0052b780_user_4(int param_1)



{

  int iVar1;

  undefined1 local_8;

  undefined4 local_7;

  undefined1 local_3;

  

  iVar1 = FUN_0052aa70();

  if (iVar1 != 0) {

    local_7 = DAT_00633250;

    local_8 = 0x45;

    local_3 = 0;

    if (param_1 != 0) {

      FUN_0052b5a0(param_1,6,&local_8);

      return;

    }

    comm_0052b780(0,6,&local_8);

  }

  return;

}

/* ===== comm_fakehost_menu_user @ 0x0052F350 ===== */
void comm_fakehost_menu_user(int param_1,undefined4 param_2)



{

  int iVar1;

  undefined1 local_8;

  undefined4 local_7;

  undefined1 local_3;

  

  iVar1 = FUN_0052aa70();

  if (iVar1 != 0) {

    local_7 = param_2;

    local_8 = 0x47;

    local_3 = 0;

    if (param_1 != 0) {

      FUN_0052b5a0(param_1,6,&local_8);

      return;

    }

    comm_0052b780(0,6,&local_8);

    comm_fakehost_menu(&local_8);

  }

  return;

}

/* ===== comm_fakehost_menu @ 0x0052F3B0 ===== */
void comm_fakehost_menu(int param_1)



{

  int iVar1;

  undefined4 uVar2;

  int iVar3;

  undefined1 local_100 [256];

  

  if (*(int *)(param_1 + 1) == DAT_005def94) {

    return;

  }

  if ((DAT_005def94 != 0) && (iVar3 = 0, 0 < DAT_00632f34)) {

    do {

      iVar1 = FUN_0052ab00(iVar3);

      if (iVar1 == DAT_005def94) {

        iVar1 = AudioGetMasterVolume__Fv_9();

        if (iVar1 == DAT_005def94) {

          uVar2 = FUN_00507b00(s_CommFakeHostYouOff_0057fddc);

        }

        else {

          uVar2 = comm_player_name3(iVar3);

          uVar2 = FUN_00507b00(s_CommFakeHostOff_0057fdcc,uVar2);

        }

        FUN_00542f27(local_100,uVar2);

        comm_005363f0(local_100,1);

        break;

      }

      iVar3 = iVar3 + 1;

    } while (iVar3 < DAT_00632f34);

  }

  DAT_005def94 = *(int *)(param_1 + 1);

  iVar3 = 0;

  if (0 < DAT_00632f34) {

    while (iVar1 = FUN_0052ab00(iVar3), iVar1 != DAT_005def94) {

      iVar3 = iVar3 + 1;

      if (DAT_00632f34 <= iVar3) {

        comm_game_setup_menu();

        return;

      }

    }

    iVar1 = AudioGetMasterVolume__Fv_9();

    if (DAT_005def94 == iVar1) {

      uVar2 = comm_player_name3(iVar3);

      uVar2 = FUN_00507b00(s_CommFakeHostYouOn_0057fdb8,uVar2);

    }

    else {

      uVar2 = comm_player_name3(iVar3);

      uVar2 = FUN_00507b00(s_CommFakeHostOn_0057fda8,uVar2);

    }

    FUN_00542f27(local_100,uVar2);

    comm_005363f0(local_100,1);

  }

  comm_game_setup_menu();

  return;

}

/* ===== comm_fakehost_player @ 0x0052F510 ===== */
void comm_fakehost_player(undefined4 param_1)



{

  int iVar1;

  int iVar2;

  undefined4 uVar3;

  undefined1 local_8;

  undefined4 local_7;

  undefined1 local_3;

  

  iVar1 = comm_00426540();

  if ((iVar1 != 0) && (iVar1 = 0, 0 < DAT_00632f34)) {

    do {

      iVar2 = FUN_0052ab00(iVar1);

      if (iVar2 != 0) {

        uVar3 = comm_player_name3(iVar1);

        iVar2 = FUN_00545650(uVar3,param_1);

        if (iVar2 == 0) {

          uVar3 = FUN_0052ab00(iVar1);

          iVar1 = FUN_0052aa70();

          if (iVar1 == 0) {

            return;

          }

          local_8 = 0x47;

          local_3 = 0;

          local_7 = uVar3;

          comm_0052b780(0,6,&local_8);

          comm_fakehost_menu(&local_8);

          return;

        }

      }

      iVar1 = iVar1 + 1;

    } while (iVar1 < DAT_00632f34);

    return;

  }

  return;

}

/* ===== comm_fakehost_toggle @ 0x0052F5B0 ===== */
void comm_fakehost_toggle(void)



{

  int iVar1;

  int iVar2;

  undefined4 uVar3;

  undefined1 local_108;

  undefined4 local_107;

  undefined1 local_103;

  undefined1 local_100 [256];

  

  iVar1 = comm_00426540();

  if ((iVar1 == 0) || (iVar1 = FUN_0052aa70(), iVar1 == 0)) {

    return;

  }

  local_108 = 0x4d;

  local_107 = AudioGetMasterVolume__Fv_9();

  local_103 = 0;

  comm_0052b780(0,6,&local_108);

  if ((DAT_005def94 != 0) && (iVar1 = 0, 0 < DAT_00632f34)) {

    do {

      iVar2 = FUN_0052ab00(iVar1);

      if (iVar2 == DAT_005def94) {

        iVar2 = AudioGetMasterVolume__Fv_9();

        if (iVar2 == DAT_005def94) {

          uVar3 = FUN_00507b00(s_CommFakeHostYouOff_0057fddc);

        }

        else {

          uVar3 = comm_player_name3(iVar1);

          uVar3 = FUN_00507b00(s_CommFakeHostOff_0057fdcc,uVar3);

        }

        FUN_00542f27(local_100,uVar3);

        comm_005363f0(local_100,1);

        break;

      }

      iVar1 = iVar1 + 1;

    } while (iVar1 < DAT_00632f34);

  }

  DAT_005def94 = 0;

  comm_game_setup_menu();

  return;

}

/* ===== comm_audio_vol_a @ 0x0052F6A0 ===== */
void comm_audio_vol_a(undefined4 param_1)



{

  int iVar1;

  undefined1 local_c;

  undefined4 local_b;

  undefined4 local_7;

  undefined1 local_3;

  

  iVar1 = FUN_0052aa70();

  if (iVar1 != 0) {

    local_c = 0x48;

    local_b = param_1;

    local_7 = AudioGetMasterVolume__Fv_9();

    local_3 = 0;

    comm_dp_send(10,&local_c);

  }

  return;

}

/* ===== FUN_0052f6e0 @ 0x0052F6E0 ===== */
void FUN_0052f6e0(undefined4 param_1)



{

  undefined2 in_CX;

  undefined4 uStack_4;

  

  if (DAT_00632f44 != 0) {

    uStack_4 = (uint)CONCAT12(0x51,in_CX);

    FUN_0052b4e0(param_1,2,(int)&uStack_4 + 2);

  }

  return;

}

/* ===== comm_audio_vol_b @ 0x0052F710 ===== */
void comm_audio_vol_b(void)



{

  int iVar1;

  undefined1 local_8;

  undefined4 local_7;

  undefined1 local_3;

  

  iVar1 = FUN_0052aa70();

  if (iVar1 != 0) {

    local_8 = 0x49;

    local_7 = AudioGetMasterVolume__Fv_9();

    local_3 = 0;

    comm_dp_send(6,&local_8);

  }

  return;

}

/* ===== comm_audio_vol_c @ 0x0052F750 ===== */
void comm_audio_vol_c(void)



{

  int iVar1;

  undefined1 local_8;

  undefined4 local_7;

  undefined1 local_3;

  

  iVar1 = FUN_0052aa70();

  if (iVar1 != 0) {

    local_8 = 0x4a;

    local_7 = AudioGetMasterVolume__Fv_9();

    local_3 = 0;

    comm_dp_send(6,&local_8);

  }

  return;

}

/* ===== comm_player_marker_menu @ 0x0052F790 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void comm_player_marker_menu(void)



{

  undefined1 auVar1 [4];

  int iVar2;

  undefined4 uVar3;

  undefined1 local_4 [4];

  

  _DAT_00633254 = _DAT_00633254 + 1;

  if (2 < _DAT_00633254) {

    _DAT_00633254 = 0;

  }

  iVar2 = FUN_0052aa70();

  auVar1 = local_4;

  if (iVar2 != 0) {

    local_4[1] = DAT_00633254;

    local_4[0] = 0x46;

    local_4[3] = auVar1[3];

    local_4[2] = 0;

    comm_0052b780(0,3,local_4);

  }

  if (_DAT_00633254 == 0) {

    uVar3 = FUN_00507b00(s_CommPlayerMarkerLarge_0057fe20,1);

    comm_005363f0(uVar3);

    return;

  }

  if (_DAT_00633254 == 1) {

    uVar3 = FUN_00507b00(s_CommPlayerMarkerSmall_0057fe08,1);

    comm_005363f0(uVar3);

    return;

  }

  uVar3 = FUN_00507b00(s_CommPlayerMarkerNone_0057fdf0,1);

  comm_005363f0(uVar3);

  return;

}

/* ===== comm_audio_vol_d @ 0x0052F830 ===== */
void comm_audio_vol_d(void)



{

  int iVar1;

  undefined1 local_8;

  undefined4 local_7;

  undefined1 local_3;

  

  iVar1 = FUN_0052aa70();

  if (iVar1 != 0) {

    local_8 = 0x50;

    local_7 = AudioGetMasterVolume__Fv_9();

    local_3 = 0;

    comm_dp_send(6,&local_8);

  }

  return;

}

/* ===== comm_audio_vol_f @ 0x0052F870 ===== */
void comm_audio_vol_f(void)



{

  int iVar1;

  undefined1 local_8;

  undefined4 local_7;

  undefined1 local_3;

  

  iVar1 = FUN_0052aa70();

  if (iVar1 != 0) {

    local_8 = 0x4b;

    local_7 = AudioGetMasterVolume__Fv_9();

    local_3 = 0;

    comm_dp_send(6,&local_8);

  }

  return;

}

/* ===== comm_audio_vol_e @ 0x0052F8B0 ===== */
void comm_audio_vol_e(void)



{

  int iVar1;

  undefined1 local_8;

  undefined4 local_7;

  undefined1 local_3;

  

  iVar1 = FUN_0052aa70();

  if (iVar1 != 0) {

    local_8 = 0x4c;

    local_7 = AudioGetMasterVolume__Fv_9();

    local_3 = 0;

    comm_dp_send(6,&local_8);

  }

  return;

}

/* ===== comm_0052b780_user_5 @ 0x0052F8F0 ===== */
void comm_0052b780_user_5(int param_1)



{

  int iVar1;

  undefined1 local_8;

  undefined1 local_7;

  undefined1 local_6;

  undefined1 local_5;

  undefined1 local_4;

  undefined1 local_3;

  undefined1 local_2;

  undefined1 local_1;

  

  iVar1 = FUN_0052aa70();

  if (iVar1 != 0) {

    iVar1 = FUN_0052c5c0();

    if (iVar1 != 0) {

      local_7 = (undefined1)DAT_006330c4;

      local_4 = (undefined1)DAT_006330d0;

      local_6 = (undefined1)DAT_006330c8;

      local_5 = (undefined1)DAT_006330cc;

      local_8 = 0x33;

      local_3 = (undefined1)DAT_006330d4;

      local_2 = (undefined1)DAT_006330d8;

      local_1 = 0;

      if (param_1 != 0) {

        FUN_0052b4e0(param_1,8,&local_8);

        return;

      }

      comm_0052b780(0,8,&local_8);

    }

  }

  return;

}

/* ===== cam_mode_full @ 0x0052F980 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void cam_mode_full(int param_1,int param_2)



{

  uint *puVar1;

  undefined4 *puVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  undefined1 local_18;

  undefined4 local_17;

  int local_13;

  undefined4 local_f;

  undefined4 local_b;

  undefined4 local_7;

  undefined1 local_3;

  

  iVar5 = param_1;

  *(undefined4 *)(param_1 + 0x278) = 0;

  *(undefined4 *)(param_1 + 0x1d4) = 0;

  *(undefined4 *)(param_1 + 0xcc) = 0;

  *(undefined4 *)(param_1 + 0x210) = 0;

  *(undefined4 *)(param_1 + 0x108) = 0;

  *(undefined4 *)(param_1 + 0x184) = 0;

  *(undefined4 *)(param_1 + 0x128) = 0;

  *(undefined4 *)(param_1 + 300) = 0;

  *(undefined4 *)(param_1 + 0x130) = 0;

  *(undefined4 *)(param_1 + 0x134) = 0;

  *(undefined4 *)(param_1 + 0x138) = 0;

  *(undefined4 *)(param_1 + 0x13c) = 0;

  *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) & 0xbfffffff;

  iVar3 = FUN_004a6160(param_1);

  if (iVar3 == 0) {

    iVar3 = FUN_004a6180(iVar5);

    puVar2 = DAT_00632d68;

    if (iVar3 != 0) {

      puVar1 = *(uint **)(iVar5 + 0x100);

      *(uint *)(iVar5 + 0xc4) = puVar1[0x3eb];

      iVar3 = FUN_00456050(iVar5);

      if (iVar3 != 0) {

        *(uint *)(iVar3 + 0xd8) = *(uint *)(iVar3 + 0xd8) & 0xbfffffff;

      }

      *puVar1 = *puVar1 & 0xfffffbff;

      puVar1[0x3fe] = 0;

      puVar2 = DAT_00632d68;

    }

  }

  else {

    iVar3 = *(int *)(iVar5 + 0x100);

    FUN_00448920(*(undefined4 *)(iVar3 + 0xf4));

    *(undefined4 *)(iVar3 + 0xf4) = 0;

    FUN_0047bdf0(iVar5);

    *(uint *)(iVar5 + 0xe0) = *(uint *)(iVar5 + 0xe0) & 0xffbfffff;

    *(undefined4 *)(iVar3 + 0x208) = 0;

    puVar2 = DAT_00632d68;

  }

  do {

    if (puVar2 == (undefined4 *)0x0) {

LAB_0052fabe:

      if (iVar5 == DAT_00632a88) {

        mission_0051a0c0(s_CamMode_00555a28,&param_1);

        FUN_0040d130(param_1);

      }

      iVar3 = param_2;

      if ((*(int *)(iVar5 + 4) != param_2) && (param_2 != 0)) {

        iVar4 = FUN_004a6160(iVar5);

        if (iVar4 != 0) {

          *(undefined4 *)(*(int *)(iVar5 + 0x100) + 0xd8) = 0;

        }

        iVar4 = FUN_004a6180(iVar5);

        if (iVar4 != 0) {

          *(undefined4 *)(*(int *)(iVar5 + 0x100) + 0xcfc) = 0;

        }

        object_spawn_from_linkage(iVar3,*(undefined4 *)(iVar5 + 0x188));

      }

      iVar4 = FUN_0052aa70();

      if ((iVar4 != 0) && (iVar4 = FUN_0052aa80(iVar5), iVar4 != 0)) {

        comm_packet_big(iVar5);

        FUN_00499280(iVar5);

        FUN_004a7440(iVar5);

        FUN_0049a1f0(iVar5);

        _DAT_00632b60 = 0;

        local_17 = *(undefined4 *)(iVar5 + 0x188);

        local_f = *(undefined4 *)(iVar5 + 0xa0);

        local_b = *(undefined4 *)(iVar5 + 0xa4);

        local_7 = *(undefined4 *)(iVar5 + 0xa8);

        local_18 = 0x17;

        local_13 = iVar3;

        local_3 = 0;

        iVar5 = FUN_0052aa70();

        if (iVar5 != 0) {

          iVar5 = FUN_0052c5c0();

          if (iVar5 != 0) {

            comm_0052b780(0,0x16,&local_18);

            return;

          }

          comm_dp_send(0x16,&local_18);

        }

      }

      return;

    }

    iVar3 = puVar2[3];

    if ((*(int *)(iVar3 + 0x1e0) == 0x59) && (*(int *)(iVar3 + 0x210) == iVar5)) {

      *(undefined4 *)(iVar3 + 0x210) = 0;

      *(undefined4 *)(iVar3 + 0x218) = 0;

      *(undefined4 *)(iVar3 + 0x214) = 0;

      if (*(int *)(iVar5 + 0x174) != 0) {

        FUN_00497510(iVar3);

      }

      goto LAB_0052fabe;

    }

    puVar2 = (undefined4 *)*puVar2;

  } while( true );

}

/* ===== comm_0052b780_user_6 @ 0x0052FBF0 ===== */
void comm_0052b780_user_6(int param_1,int param_2)



{

  int *piVar1;

  undefined4 *puVar2;

  int iVar3;

  undefined1 local_30 [5];

  undefined4 local_2b;

  undefined4 local_27;

  undefined4 local_23;

  undefined4 local_1f;

  undefined4 local_1b;

  undefined4 local_17;

  undefined4 local_13;

  uint local_f;

  int local_b;

  int local_7;

  undefined1 local_3;

  

  iVar3 = FUN_0052aa70();

  if (iVar3 != 0) {

    puVar2 = (undefined4 *)local_30;

    for (iVar3 = 0xb; iVar3 != 0; iVar3 = iVar3 + -1) {

      *puVar2 = 0;

      puVar2 = puVar2 + 1;

    }

    *(undefined2 *)puVar2 = 0;

    local_2b = *(undefined4 *)(param_1 + 0x188);

    local_27 = *(undefined4 *)(param_1 + 0xa0);

    local_23 = *(undefined4 *)(param_1 + 0xa4);

    local_1f = *(undefined4 *)(param_1 + 0xa8);

    local_30._1_4_ = *(undefined4 *)(param_1 + 4);

    local_1b = *(undefined4 *)(param_1 + 0x128);

    local_17 = *(undefined4 *)(param_1 + 300);

    local_13 = *(undefined4 *)(param_1 + 0x130);

    piVar1 = *(int **)(param_1 + 0x100);

    local_30[0] = 0x25;

    local_f = *(uint *)(param_1 + 0xe8) & 0xffff | *piVar1 << 0x10;

    local_b = piVar1[1];

    local_7 = piVar1[6];

    local_3 = 0;

    if (param_2 != 0) {

      FUN_0052b4e0(DAT_005e02e8,0x2e,local_30);

      return;

    }

    iVar3 = FUN_0052c5c0();

    if (iVar3 != 0) {

      comm_0052b780(0,0x2e,local_30);

      return;

    }

    comm_dp_send(0x2e,local_30);

  }

  return;

}

/* ===== comm_0052b780_user_7 @ 0x0052FCE0 ===== */
void comm_0052b780_user_7(int param_1)



{

  int iVar1;

  undefined1 local_c;

  undefined3 uStack_b;

  undefined4 local_8;

  undefined1 local_4;

  undefined1 uStack_3;

  

  iVar1 = FUN_0052aa70();

  if (iVar1 != 0) {

    local_4 = (undefined1)((uint)*(undefined4 *)(param_1 + 4) >> 0x18);

    _local_c = CONCAT31((int3)*(undefined4 *)(param_1 + 0x188),7);

    local_8._0_1_ = (undefined1)((uint)*(undefined4 *)(param_1 + 0x188) >> 0x18);

    local_8 = CONCAT31((int3)*(undefined4 *)(param_1 + 4),(undefined1)local_8);

    uStack_3 = 0;

    iVar1 = FUN_0052c5c0();

    if (iVar1 != 0) {

      comm_0052b780(0,10,&local_c);

      return;

    }

    comm_dp_send(10,&local_c);

  }

  return;

}

/* ===== comm_obj_sync @ 0x0052FD50 ===== */
void comm_obj_sync(int param_1)



{

  undefined4 uVar1;

  undefined4 uVar2;

  byte bVar3;

  int iVar4;

  int iVar5;

  undefined4 local_18;

  undefined4 local_14;

  uint local_10;

  uint local_c;

  undefined1 local_8;

  undefined1 uStack_7;

  undefined2 uStack_6;

  undefined1 local_4;

  undefined1 uStack_3;

  

  iVar4 = FUN_0052aa70();

  if (iVar4 != 0) {

    if (((*(uint *)(param_1 + 0xe0) & 8) != 0) && (*(int *)(param_1 + 0x274) == 0)) {

      *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xfffffff7;

    }

    local_14._1_3_ = (undefined3)*(undefined4 *)(param_1 + 0x188);

    bVar3 = (byte)((uint)*(undefined4 *)(param_1 + 0x188) >> 0x18);

    if ((*(byte *)(param_1 + 0xe0) & 8) != 0) {

      local_14 = CONCAT31(local_14._1_3_,(char)((uint)*(undefined4 *)(param_1 + 4) >> 0x18));

      local_18 = CONCAT31((int3)*(undefined4 *)(param_1 + 4),

                          (*(int *)(param_1 + 0xe8) == 10) * '\b' + ' ');

      uVar1 = *(undefined4 *)(*(int *)(param_1 + 0x274) + 0x188);

      local_10._1_3_ = (undefined3)uVar1;

      local_10 = CONCAT31(local_10._1_3_,bVar3);

      uVar2 = *(undefined4 *)(*(int *)(param_1 + 0x100) + 0x18);

      uStack_7 = *(int *)(param_1 + 0xe4) == 0x37;

      local_c._1_3_ = (undefined3)uVar2;

      local_c = CONCAT31(local_c._1_3_,(char)((uint)uVar1 >> 0x18));

      local_8 = (undefined1)((uint)uVar2 >> 0x18);

      local_4 = 0;

      uStack_6 = 0;

      uStack_3 = 0;

      FUN_0052b4e0(DAT_005e02e8,0x16,&local_18);

      return;

    }

    iVar4 = *(int *)(param_1 + 0x100);

    local_8 = 0;

    uStack_7 = 0;

    local_18 = CONCAT31((int3)*(undefined4 *)(param_1 + 4),0x1a);

    local_14 = CONCAT31(local_14._1_3_,(char)((uint)*(undefined4 *)(param_1 + 4) >> 0x18));

    local_10 = (uint)bVar3;

    local_c = 0;

    if ((*(int *)(param_1 + 0x210) == 0) ||

       (iVar5 = FUN_004a6160(*(int *)(param_1 + 0x210)), iVar5 == 0)) {

      if ((*(int *)(param_1 + 0x274) != 0) &&

         (iVar5 = FUN_004a6180(*(int *)(param_1 + 0x274)), iVar5 != 0)) {

        local_c = *(uint *)(*(int *)(param_1 + 0x274) + 0x188);

        local_10._1_3_ = (undefined3)local_c;

        local_c = local_c >> 0x18;

      }

    }

    else {

      local_c = *(uint *)(*(int *)(param_1 + 0x210) + 0x188);

      local_10._1_3_ = (undefined3)local_c;

      local_c = local_c >> 0x18;

    }

    uVar1 = *(undefined4 *)(iVar4 + 0x54);

    local_c._1_3_ = (undefined3)uVar1;

    local_8 = (undefined1)((uint)uVar1 >> 0x18);

    uStack_7 = 0;

    FUN_0052b4e0(DAT_005e02e8,0x12,&local_18);

  }

  return;

}

/* ===== FUN_0052fed0 @ 0x0052FED0 ===== */
void FUN_0052fed0(void)



{

  int iVar1;

  undefined2 in_CX;

  undefined4 uStack_4;

  

  uStack_4 = (uint)CONCAT12(0xe,in_CX);

  iVar1 = FUN_0052aa70();

  if (iVar1 != 0) {

    iVar1 = FUN_0052c5c0();

    if (iVar1 == 0) {

      comm_dp_send(2,(int)&uStack_4 + 2);

    }

  }

  return;

}

/* ===== comm_0052b780_user_8 @ 0x0052FF00 ===== */
void comm_0052b780_user_8(undefined4 *param_1,uint param_2)



{

  int iVar1;

  uint uVar2;

  undefined4 *puVar3;

  undefined1 local_100;

  undefined1 local_ff;

  undefined4 local_fe [63];

  

  iVar1 = FUN_0052aa70();

  if (iVar1 != 0) {

    if (param_2 + 3 < 0x101) {

      local_ff = (undefined1)param_2;

      local_100 = 0x32;

      puVar3 = local_fe;

      for (uVar2 = param_2 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {

        *puVar3 = *param_1;

        param_1 = param_1 + 1;

        puVar3 = puVar3 + 1;

      }

      for (uVar2 = param_2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {

        *(undefined1 *)puVar3 = *(undefined1 *)param_1;

        param_1 = (undefined4 *)((int)param_1 + 1);

        puVar3 = (undefined4 *)((int)puVar3 + 1);

      }

      *(undefined1 *)((int)local_fe + param_2) = 0;

      comm_0052b780(0,param_2 + 3,&local_100);

    }

  }

  return;

}

/* ===== FUN_0052ff70 @ 0x0052FF70 ===== */
void FUN_0052ff70(char *param_1)



{

  char cVar1;

  undefined4 *puVar2;

  

  puVar2 = DAT_00632d68;

  if (9 < DAT_00632f08) {

    for (; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {

      if (((*(uint *)(puVar2[3] + 0xd8) & 0x8000) == 0) &&

         (*(int *)(puVar2[3] + 0x188) == *(int *)(param_1 + 1))) {

        cVar1 = *param_1;

        if (cVar1 == '\x1c') {

          obj_group_spread();

          return;

        }

        if (cVar1 != '\x1d') {

          if (cVar1 != ')') {

            return;

          }

          FUN_0041e960();

          return;

        }

        FUN_0041e720();

        return;

      }

    }

  }

  return;

}

/* ===== FUN_0052ffe0 @ 0x0052FFE0 ===== */
/* PS2 candidate: IconIsKabutoIcon__Fi (conf 0.511) */



void FUN_0052ffe0(void)



{

  int iVar1;

  undefined4 uStack_4;

  

  iVar1 = FUN_0052aa70();

  if (iVar1 != 0) {

    iVar1 = FUN_0052c5c0();

    if (iVar1 != 0) {

      uStack_4 = (uint)CONCAT12(0x13,(undefined2)uStack_4);

      comm_0052b780(0,2,(int)&uStack_4 + 2);

    }

  }

  return;

}

