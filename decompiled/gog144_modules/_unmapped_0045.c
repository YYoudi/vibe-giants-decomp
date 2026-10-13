/* Giants 1.449 — module _unmapped_0045
 * 145 functions (86 named) — decompiled, names from PS2 symbols
 * Original source: C:\Giants\source\_unmapped_0045.c(pp) (assert-string evidence)
 */

/* ===== FUN_00450aa0 @ 0x00450AA0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_00450aa0(void)



{

  int iVar1;

  undefined4 *puVar2;

  

  _DAT_0059ce80 = DAT_006328e8;

  _DAT_0059ce88 = DAT_006328e8;

  puVar2 = &DAT_0059ce90;

  for (iVar1 = 600; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar2 = 0;

    puVar2 = puVar2 + 1;

  }

  DAT_0059ce7c = 0;

  DAT_0059d7f4 = 0;

  DAT_0059ce78 = 0;

  DAT_0059d7f8 = 0x7fffffff;

  DAT_0059ce84 = 0;

  DAT_0059d7fc = 0;

  DAT_0059d7f0 = 0;

  return;

}

/* ===== fps_log_write @ 0x00450AF0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void fps_log_write(void)



{

  undefined4 *puVar1;

  int iVar2;

  int iVar3;

  

  iVar2 = BinFileSeek_2(s_fps_txt_00559d88,&DAT_00558550);

  if (iVar2 != 0) {

    crt_file_free_init(iVar2,s__3_2f_Giants_v_1_3f_00559d70,

                       (double)((float)DAT_0059ce7c / (DAT_006328e8 - _DAT_0059ce88)),0x60000000,

                       0x3ff66666);

    crt_file_free_init(iVar2,s__d_Min_00559d68,DAT_0059d7f8);

    crt_file_free_init(iVar2,s__d_Max_00559d60,DAT_0059ce84);

    iVar3 = 0;

    if (0 < DAT_0059ce78) {

      do {

        puVar1 = &DAT_0059ce90 + iVar3;

        iVar3 = iVar3 + 1;

        crt_file_free_init(iVar2,s__d_Second__d_00559d50,*puVar1,iVar3);

      } while (iVar3 < DAT_0059ce78);

    }

    editor_0054384c(iVar2);

  }

  Audio3DTestToneUpdate__Fv_4();

  return;

}

/* ===== FUN_00450bb0 @ 0x00450BB0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_00450bb0(void)



{

  int iVar1;

  

  DAT_0059ce7c = DAT_0059ce7c + 1;

  DAT_0059d7f4 = DAT_0059d7f4 + 1;

  iVar1 = (**(code **)(DAT_00656420 + 0xc4))(DAT_00656420,9);

  DAT_0059d7fc = DAT_0059d7fc + iVar1;

  if (1.0 <= DAT_006328e8 - _DAT_0059ce80) {

    if (DAT_0059d800 == 0) {

      if (1 < DAT_0059d7f4) {

        DAT_0059d800 = 1;

        FUN_00450aa0();

      }

    }

    else {

      if (DAT_0059d7f4 < DAT_0059d7f8) {

        DAT_0059d7f8 = DAT_0059d7f4;

      }

      if (DAT_0059ce84 < DAT_0059d7f4) {

        DAT_0059ce84 = DAT_0059d7f4;

      }

      if (DAT_0059ce78 < 600) {

        (&DAT_0059ce90)[DAT_0059ce78] = DAT_0059d7f4;

        DAT_0059ce78 = DAT_0059ce78 + 1;

      }

      DAT_0059d7f0 = DAT_0059d7fc;

      DAT_0059d7fc = 0;

    }

    DAT_0059d7f4 = 0;

    _DAT_0059ce80 = DAT_006328e8;

  }

  return;

}

/* ===== FUN_00450c90 @ 0x00450C90 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



float10 FUN_00450c90(void)



{

  return (float10)DAT_0059ce7c / ((float10)DAT_006328e8 - (float10)_DAT_0059ce88);

}

/* ===== AudioGetMasterVolume__Fv_7 @ 0x00450CB0 ===== */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */



undefined4 AudioGetMasterVolume__Fv_7(void)



{

  return DAT_0059d7f0;

}

/* ===== FUN_00450cc0 @ 0x00450CC0 ===== */
void FUN_00450cc0(void)



{

  (**(code **)(DAT_00656420 + 0xc4))(DAT_00656420,9);

  return;

}

/* ===== AudioGetMasterVolume__Fv_4 @ 0x00450CE0 ===== */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */



undefined4 AudioGetMasterVolume__Fv_4(void)



{

  return DAT_0059ce7c;

}

/* ===== AudioGetMasterVolume__Fv_5 @ 0x00450CF0 ===== */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */



undefined4 AudioGetMasterVolume__Fv_5(void)



{

  return DAT_0059ce84;

}

/* ===== AudioGetMasterVolume__Fv_6 @ 0x00450D00 ===== */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */



undefined4 AudioGetMasterVolume__Fv_6(void)



{

  return DAT_0059d7f8;

}

/* ===== gameover_menu @ 0x00450D10 ===== */
void gameover_menu(void)



{

  dlog_push_level(&LAB_00450db0,&LAB_00450e60);

  dialog_level_set_textentry_mode();

  DAT_0059d804 = FUN_00497cd0(0x127);

  DAT_0059d808 = main_dlog_00427150();

  main_dlog_004273b0(DAT_0059d808,0,0x3f000000,0x3ecccccd,0xa000000,s_GameOverRestart_00559da8);

  main_dlog_00427e80(DAT_0059d808,1,0x3f000000,0x3f19999a,0x8000062);

  main_dlog_00428340(DAT_0059d808,1,s_AGameOverQuit_00559d96 + 2);

  main_dlog_00428340(DAT_0059d808,1,s_GameOverRestart_00559da8);

  DAT_00632aa4._3_1_ = 0;

  return;

}

/* ===== calc_tri_weighted_plane @ 0x004511D0 ===== */
/* PS2 candidate: calc_tri_plane (conf 0.591) */



void calc_tri_weighted_plane(float *param_1,float *param_2,float *param_3,float *param_4)



{

  float *pfVar1;

  float *pfVar2;

  

  pfVar1 = param_4 + 1;

  pfVar2 = param_4 + 2;

  *param_4 = (param_3[2] - param_1[2]) * (param_2[1] - param_1[1]) -

             (param_3[1] - param_1[1]) * (param_2[2] - param_1[2]);

  *pfVar1 = (*param_3 - *param_1) * (param_2[2] - param_1[2]) -

            (*param_2 - *param_1) * (param_3[2] - param_1[2]);

  *pfVar2 = (param_3[1] - param_1[1]) * (*param_2 - *param_1) -

            (*param_3 - *param_1) * (param_2[1] - param_1[1]);

  normalize__FPfN20(param_4,pfVar1,pfVar2);

  param_4[3] = -(*pfVar1 * param_1[1] + param_1[2] * *pfVar2 + *param_1 * *param_4);

  return;

}

/* ===== FUN_00451270 @ 0x00451270 ===== */
void FUN_00451270(float param_1,float param_2,float param_3,float *param_4)



{

  float fVar1;

  

  if (*param_4 <= param_3) {

    if (*param_4 < param_3) {

      fVar1 = *param_4;

      *param_4 = param_1 + fVar1;

      if (param_3 < param_1 + fVar1) {

        *param_4 = param_3;

      }

      if (param_2 < param_3 - *param_4) {

        *param_4 = param_3 - param_2;

      }

    }

  }

  else {

    param_1 = *param_4 - param_1;

    *param_4 = param_1;

    if (param_1 < param_3) {

      *param_4 = param_3;

    }

    if (param_2 < *param_4 - param_3) {

      *param_4 = param_2 + param_3;

      return;

    }

  }

  return;

}

/* ===== FUN_00451300 @ 0x00451300 ===== */
/* PS2 candidate: chase_value_time (conf 0.408) */



void FUN_00451300(float param_1,float param_2,float param_3,float param_4,float *param_5)



{

  float fVar1;

  float10 fVar2;

  float10 fVar3;

  

  fVar2 = (float10)FUN_00518b70(0,0);

  fVar3 = fVar2 * (float10)param_2;

  fVar2 = (ABS((float10)*param_5 - (float10)param_4) / (float10)param_1) * (float10)(float)fVar2;

  if (fVar3 < fVar2) {

    fVar3 = (float10)(float)fVar2;

  }

  if (*param_5 <= param_4) {

    if (*param_5 < param_4) {

      fVar1 = *param_5;

      *param_5 = (float)(fVar3 + (float10)fVar1);

      if ((float10)param_4 < fVar3 + (float10)fVar1) {

        *param_5 = param_4;

      }

      if (param_3 < param_4 - *param_5) {

        *param_5 = param_4 - param_3;

        return;

      }

    }

  }

  else {

    fVar1 = *param_5;

    *param_5 = (float)((float10)fVar1 - fVar3);

    if ((float10)fVar1 - fVar3 < (float10)param_4) {

      *param_5 = param_4;

    }

    if (param_3 < *param_5 - param_4) {

      *param_5 = param_3 + param_4;

      return;

    }

  }

  return;

}

/* ===== vec_lerp_approach @ 0x004513C0 ===== */
void vec_lerp_approach(float param_1,float *param_2,float *param_3,float *param_4)



{

  float fVar1;

  float fVar2;

  float10 fVar3;

  

  param_1 = 1.0 / param_1;

  fVar1 = *param_2;

  fVar2 = *param_3;

  fVar3 = (float10)FUN_00518b70(0,0);

  fVar3 = ABS((float10)fVar1 - (float10)fVar2) * (float10)param_1 * fVar3;

  if (*param_4 <= fVar2) {

    if ((*param_4 < fVar2) &&

       (fVar3 = fVar3 + (float10)*param_4, *param_4 = (float)fVar3, (float10)fVar2 < fVar3)) {

      *param_4 = fVar2;

    }

  }

  else {

    fVar3 = (float10)*param_4 - fVar3;

    *param_4 = (float)fVar3;

    if (fVar3 < (float10)fVar2) {

      *param_4 = fVar2;

    }

  }

  fVar1 = param_3[1];

  fVar2 = param_2[1];

  fVar3 = (float10)FUN_00518b70(0,0);

  fVar3 = ABS((float10)fVar2 - (float10)fVar1) * (float10)param_1 * fVar3;

  if (param_4[1] <= fVar1) {

    if ((param_4[1] < fVar1) &&

       (fVar3 = fVar3 + (float10)param_4[1], param_4[1] = (float)fVar3, (float10)fVar1 < fVar3)) {

      param_4[1] = fVar1;

    }

  }

  else {

    fVar3 = (float10)param_4[1] - fVar3;

    param_4[1] = (float)fVar3;

    if (fVar3 < (float10)fVar1) {

      param_4[1] = fVar1;

    }

  }

  fVar1 = param_3[2];

  fVar2 = param_2[2];

  fVar3 = (float10)FUN_00518b70(0,0);

  fVar3 = ABS((float10)fVar2 - (float10)fVar1) * (float10)param_1 * fVar3;

  if (param_4[2] <= fVar1) {

    if ((param_4[2] < fVar1) &&

       (fVar3 = fVar3 + (float10)param_4[2], param_4[2] = (float)fVar3, (float10)fVar1 < fVar3)) {

      param_4[2] = fVar1;

      return;

    }

  }

  else {

    fVar3 = (float10)param_4[2] - fVar3;

    param_4[2] = (float)fVar3;

    if (fVar3 < (float10)fVar1) {

      param_4[2] = fVar1;

      return;

    }

  }

  return;

}

/* ===== FUN_00451560 @ 0x00451560 ===== */
/* PS2 candidate: diff_rangle__Fff (conf 0.316) */



void FUN_00451560(float *param_1)



{

  float10 fVar1;

  

  if (*param_1 < 0.0) {

    fVar1 = (float10)AddHud__4cHudP8cHudIcon_6();

    *param_1 = (float)(fVar1 + (float10)360.0);

    return;

  }

  if (360.0 <= *param_1) {

    fVar1 = (float10)AddHud__4cHudP8cHudIcon_6();

    *param_1 = (float)fVar1;

  }

  return;

}

/* ===== FUN_004515b0 @ 0x004515B0 ===== */
/* PS2 candidate: chase_angle (conf 0.317) */



void FUN_004515b0(float param_1,float param_2,float param_3,float *param_4)



{

  float *pfVar1;

  float10 fVar2;

  

  pfVar1 = param_4;

  param_4 = (float *)*param_4;

  if (0.0 <= param_3) {

    if (360.0 <= param_3) {

      fVar2 = (float10)AddHud__4cHudP8cHudIcon_6();

      goto LAB_00451603;

    }

  }

  else {

    fVar2 = (float10)AddHud__4cHudP8cHudIcon_6();

    fVar2 = fVar2 + (float10)360.0;

LAB_00451603:

    param_3 = (float)fVar2;

  }

  if (0.0 <= (float)param_4) {

    if ((float)param_4 < 360.0) goto LAB_00451653;

    fVar2 = (float10)AddHud__4cHudP8cHudIcon_6();

  }

  else {

    fVar2 = (float10)AddHud__4cHudP8cHudIcon_6();

    fVar2 = fVar2 + (float10)360.0;

  }

  param_4 = (float *)(float)fVar2;

LAB_00451653:

  if (param_3 - (float)param_4 <= 180.0) {

    if (param_3 - (float)param_4 < -180.0) {

      param_4 = (float *)((float)param_4 - 360.0);

    }

  }

  else {

    param_4 = (float *)((float)param_4 + 360.0);

  }

  if ((float)param_4 <= param_3) {

    if ((float)param_4 < param_3) {

      param_4 = (float *)((float)param_4 + param_1);

      if (param_3 < (float)param_4) {

        param_4 = (float *)param_3;

      }

      if (param_2 < param_3 - (float)param_4) {

        param_4 = (float *)(param_3 - param_2);

      }

    }

  }

  else {

    param_4 = (float *)((float)param_4 - param_1);

    if ((float)param_4 < param_3) {

      param_4 = (float *)param_3;

    }

    if (param_2 < (float)param_4 - param_3) {

      param_4 = (float *)(param_2 + param_3);

    }

  }

  if (0.0 <= (float)param_4) {

    if ((float)param_4 < 360.0) {

      *pfVar1 = (float)param_4;

      return;

    }

    fVar2 = (float10)AddHud__4cHudP8cHudIcon_6();

    *pfVar1 = (float)fVar2;

    return;

  }

  fVar2 = (float10)AddHud__4cHudP8cHudIcon_6();

  *pfVar1 = (float)(fVar2 + (float10)360.0);

  return;

}

/* ===== FUN_00451780 @ 0x00451780 ===== */
void FUN_00451780(float *param_1,float *param_2)



{

  if (180.0 < *param_1) {

    *param_2 = *param_2 + 360.0;

    *param_1 = 360.0 - *param_1;

    return;

  }

  if (*param_1 < -180.0) {

    *param_2 = *param_2 - 360.0;

    *param_1 = *param_1 + 360.0;

  }

  return;

}

/* ===== hud_render_icons @ 0x004517E0 ===== */
void hud_render_icons(float param_1,float param_2,float param_3,float param_4,float param_5,

                     float param_6,float param_7,float *param_8,float *param_9,float *param_10)



{

  float fVar1;

  float *pfVar2;

  float *pfVar3;

  float10 fVar4;

  float10 fVar5;

  float local_8;

  float local_4;

  

  pfVar2 = param_8;

  param_8 = (float *)*param_8;

  local_8 = param_5;

  local_4 = param_2;

  if (0.0 <= param_2) {

    if (360.0 <= param_2) {

      fVar4 = (float10)AddHud__4cHudP8cHudIcon_6();

      goto LAB_00451846;

    }

  }

  else {

    fVar4 = (float10)AddHud__4cHudP8cHudIcon_6();

    fVar4 = fVar4 + (float10)360.0;

LAB_00451846:

    local_4 = (float)fVar4;

  }

  if (0.0 <= param_5) {

    if (360.0 <= param_5) {

      fVar4 = (float10)AddHud__4cHudP8cHudIcon_6();

      goto LAB_00451892;

    }

  }

  else {

    fVar4 = (float10)AddHud__4cHudP8cHudIcon_6();

    fVar4 = fVar4 + (float10)360.0;

LAB_00451892:

    local_8 = (float)fVar4;

  }

  if (0.0 <= (float)param_8) {

    if (360.0 <= (float)param_8) {

      fVar4 = (float10)AddHud__4cHudP8cHudIcon_6();

      goto LAB_004518de;

    }

  }

  else {

    fVar4 = (float10)AddHud__4cHudP8cHudIcon_6();

    fVar4 = fVar4 + (float10)360.0;

LAB_004518de:

    param_8 = (float *)(float)fVar4;

  }

  fVar4 = (float10)FUN_00518b70(0,0);

  fVar5 = (float10)local_4 - (float10)local_8;

  if (fVar5 <= (float10)180.0) {

    if (fVar5 < (float10)-180.0) {

      local_8 = local_8 - 360.0;

      fVar5 = fVar5 + (float10)360.0;

    }

  }

  else {

    local_8 = local_8 + 360.0;

    fVar5 = (float10)360.0 - fVar5;

  }

  fVar1 = (float)((float10)1.0 / (float10)param_1);

  param_2 = (float)(ABS(((float10)1.0 / (float10)param_1) * fVar5) * fVar4);

  param_5 = local_8 - (float)param_8;

  FUN_00451780(&param_5,&param_8);

  if ((float)param_8 <= local_8) {

    if (((float)param_8 < local_8) &&

       (param_8 = (float *)(param_2 + (float)param_8), local_8 < (float)param_8)) {

      param_8 = (float *)local_8;

    }

  }

  else {

    param_8 = (float *)((float)param_8 - param_2);

    if ((float)param_8 < local_8) {

      param_8 = (float *)local_8;

    }

  }

  FUN_00451560(&param_8);

  pfVar3 = param_9;

  *pfVar2 = (float)param_8;

  param_2 = *param_9;

  param_5 = param_6;

  param_8 = (float *)param_3;

  if (0.0 <= param_3) {

    if (360.0 <= param_3) {

      fVar4 = (float10)AddHud__4cHudP8cHudIcon_6();

      goto LAB_00451a41;

    }

  }

  else {

    fVar4 = (float10)AddHud__4cHudP8cHudIcon_6();

    fVar4 = fVar4 + (float10)360.0;

LAB_00451a41:

    param_8 = (float *)(float)fVar4;

  }

  if (0.0 <= param_6) {

    if (360.0 <= param_6) {

      fVar4 = (float10)AddHud__4cHudP8cHudIcon_6();

      goto LAB_00451a8d;

    }

  }

  else {

    fVar4 = (float10)AddHud__4cHudP8cHudIcon_6();

    fVar4 = fVar4 + (float10)360.0;

LAB_00451a8d:

    param_5 = (float)fVar4;

  }

  if (0.0 <= param_2) {

    if (360.0 <= param_2) {

      fVar4 = (float10)AddHud__4cHudP8cHudIcon_6();

      goto LAB_00451ad9;

    }

  }

  else {

    fVar4 = (float10)AddHud__4cHudP8cHudIcon_6();

    fVar4 = fVar4 + (float10)360.0;

LAB_00451ad9:

    param_2 = (float)fVar4;

  }

  param_3 = (float)param_8 - param_5;

  FUN_00451780(&param_3,&param_5);

  fVar4 = (float10)FUN_00518b70(0,0);

  param_6 = (float)(ABS((float10)fVar1 * (float10)param_3) * fVar4);

  param_3 = param_5 - param_2;

  FUN_00451780(&param_3,&param_2);

  if (param_2 <= param_5) {

    if ((param_2 < param_5) && (param_2 = param_6 + param_2, param_5 < param_2)) {

      param_2 = param_5;

    }

  }

  else {

    param_2 = param_2 - param_6;

    if (param_2 < param_5) {

      param_2 = param_5;

    }

  }

  FUN_00451560(&param_2);

  pfVar2 = param_10;

  *pfVar3 = param_2;

  param_2 = *param_10;

  param_3 = param_4;

  param_5 = param_7;

  if (0.0 <= param_4) {

    if (param_4 < 360.0) goto LAB_00451c06;

    fVar4 = (float10)AddHud__4cHudP8cHudIcon_6();

  }

  else {

    fVar4 = (float10)AddHud__4cHudP8cHudIcon_6();

    fVar4 = fVar4 + (float10)360.0;

  }

  param_3 = (float)fVar4;

LAB_00451c06:

  FUN_00451560(&param_5);

  FUN_00451560(&param_2);

  param_3 = param_3 - param_5;

  FUN_00451780(&param_3,&param_5);

  fVar4 = (float10)FUN_00518b70(0,0);

  param_6 = (float)(ABS((float10)fVar1 * (float10)param_3) * fVar4);

  param_3 = param_5 - param_2;

  FUN_00451780(&param_3,&param_2);

  if (param_2 <= param_5) {

    if ((param_2 < param_5) && (param_2 = param_6 + param_2, param_5 < param_2)) {

      param_2 = param_5;

    }

  }

  else {

    param_2 = param_2 - param_6;

    if (param_2 < param_5) {

      param_2 = param_5;

    }

  }

  FUN_00451560(&param_2);

  *pfVar2 = param_2;

  return;

}

/* ===== FUN_00451cf0 @ 0x00451CF0 ===== */
undefined4 FUN_00451cf0(void)



{

  int iVar1;

  bool bVar2;

  

  iVar1 = DAT_0059d80c + 1;

  bVar2 = DAT_0059d80c == 0;

  DAT_0059d80c = iVar1;

  if (bVar2) {

    (**(code **)(DAT_00656420 + 0x90))(DAT_00656420);

    (**(code **)(DAT_00656434 + 4))(DAT_00656434,1,0);

    (**(code **)(DAT_00656440 + 4))(DAT_00656440,2,0);

    (**(code **)(DAT_00656438 + 4))(DAT_00656438,1,4);

    (**(code **)(DAT_00656448 + 4))(DAT_00656448,2,4);

    (**(code **)(DAT_00656444 + 4))(DAT_00656444,2,2);

    (**(code **)(DAT_0065643c + 4))(DAT_0065643c,1,5);

    (**(code **)(DAT_0065644c + 4))(DAT_0065644c,0,5);

    (**(code **)(DAT_00656450 + 4))(DAT_00656450,0,5);

    (**(code **)(DAT_00656454 + 4))(DAT_00656454,0,5);

  }

  return 1;

}

/* ===== FUN_00451da0 @ 0x00451DA0 ===== */
undefined4 FUN_00451da0(void)



{

  DAT_0059d80c = DAT_0059d80c + -1;

  if (DAT_0059d80c == 0) {

    (**(code **)(DAT_0065644c + 8))(DAT_0065644c);

    (**(code **)(DAT_00656444 + 8))(DAT_00656444);

    (**(code **)(DAT_00656448 + 8))(DAT_00656448);

    (**(code **)(DAT_00656434 + 8))(DAT_00656434);

    (**(code **)(DAT_00656440 + 8))(DAT_00656440);

    (**(code **)(DAT_00656438 + 8))(DAT_00656438);

    (**(code **)(DAT_0065643c + 8))(DAT_0065643c);

    (**(code **)(DAT_00656450 + 8))(DAT_00656450);

    (**(code **)(DAT_00656454 + 8))(DAT_00656454);

    (**(code **)(DAT_00656420 + 0x94))(DAT_00656420);

  }

  return 1;

}

/* ===== FUN_00452030 @ 0x00452030 ===== */
void FUN_00452030(void)



{

  DAT_00633150 = DAT_00633150 + 1;

  if (2 < DAT_00633150) {

    DAT_00633150 = 0;

  }

  return;

}

/* ===== FUN_00452050 @ 0x00452050 ===== */
void FUN_00452050(int param_1)



{

  DAT_00633194 = (uint)(param_1 == 0);

  return;

}

/* ===== FUN_00452070 @ 0x00452070 ===== */
void FUN_00452070(int param_1)



{

  DAT_00633190 = (uint)(param_1 == 0);

  return;

}

/* ===== FUN_00452090 @ 0x00452090 ===== */
/* PS2 candidate: __main_2 (conf 0.6) */



void FUN_00452090(int param_1)



{

  if (param_1 == DAT_006331ac) {

    DAT_006331ac = (uint)(param_1 == 0);

    drawwrld_scene_link();

    return;

  }

  return;

}

/* ===== FUN_004520b0 @ 0x004520B0 ===== */
void FUN_004520b0(int param_1)



{

  DAT_0063319c = (uint)(param_1 == 0);

  return;

}

/* ===== FUN_004520d0 @ 0x004520D0 ===== */
void FUN_004520d0(int param_1)



{

  DAT_006331b0 = (uint)(param_1 == 0);

  return;

}

/* ===== FUN_004520f0 @ 0x004520F0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_004520f0(int param_1)



{

  _DAT_006331b4 = (uint)(param_1 == 0);

  return;

}

/* ===== FUN_00452110 @ 0x00452110 ===== */
void FUN_00452110(int param_1)



{

  DAT_0063311c = (uint)(param_1 == 0);

  return;

}

/* ===== options_menu_apply @ 0x00452130 ===== */
void options_menu_apply(undefined4 param_1)



{

  int iVar1;

  int *piVar2;

  int *piVar3;

  bool bVar4;

  int local_20 [4];

  int local_10 [4];

  

  DAT_006331d4 = param_1;

  DAT_005ddb4c = 0;

  (**(code **)(DAT_00656420 + 0x6c))(DAT_00656420,local_20,local_10);

  (**(code **)(DAT_00656420 + 0x68))

            (DAT_00656420,DAT_006331c8,DAT_006331cc,DAT_006331d0,DAT_006331d4,1,&DAT_006331d8,

             &DAT_006331e8);

  (**(code **)(DAT_00656420 + 0x6c))(DAT_00656420,&DAT_005ddb5c,&DAT_005ddb6c);

  iVar1 = 4;

  bVar4 = true;

  piVar2 = &DAT_005ddb5c;

  piVar3 = local_20;

  do {

    if (iVar1 == 0) break;

    iVar1 = iVar1 + -1;

    bVar4 = *piVar2 == *piVar3;

    piVar2 = piVar2 + 1;

    piVar3 = piVar3 + 1;

  } while (bVar4);

  if (bVar4) {

    iVar1 = 4;

    bVar4 = true;

    piVar2 = &DAT_005ddb6c;

    piVar3 = local_10;

    do {

      if (iVar1 == 0) break;

      iVar1 = iVar1 + -1;

      bVar4 = *piVar2 == *piVar3;

      piVar2 = piVar2 + 1;

      piVar3 = piVar3 + 1;

    } while (bVar4);

    if (bVar4) {

      game_options_verify();

      goto LAB_004521d9;

    }

  }

  music_stream_play();

  game_options_load();

LAB_004521d9:

  FUN_0051C9F0();

  win95_text_0051b160();

  win95_text_0051adb0(0x18);

  DAT_005ddb4c = 1;

  return;

}

/* ===== fx_arc_math @ 0x00452200 ===== */
void fx_arc_math(short *param_1,float *param_2,int param_3,int param_4,float param_5,float param_6,

                int param_7,float param_8,float param_9)



{

  short sVar1;

  short sVar2;

  short sVar3;

  short sVar4;

  short sVar5;

  float *pfVar6;

  float10 fVar7;

  float10 fVar8;

  float10 fVar9;

  float10 fVar10;

  float10 fVar11;

  float10 fVar12;

  float local_8;

  int local_4;

  

  if (param_7 == 1) {

    fVar7 = (float10)1.5707964 / (float10)param_4;

    local_8 = (float)fVar7;

    fVar8 = (float10)fcos(fVar7);

    fVar8 = fVar8 * (float10)param_5 + (float10)param_6;

    fVar9 = (float10)fsin(fVar7);

    fVar9 = fVar9 * (float10)param_5;

  }

  else if (param_7 == 0) {

    fVar9 = (float10)param_5 / (float10)param_4;

    fVar8 = (float10)param_6;

    fVar7 = fVar9;

  }

  else {

    fVar7 = (float10)param_6 / (float10)(param_4 + -1);

    fVar8 = (float10)param_6;

    fVar9 = (float10)param_5;

  }

  local_4 = 0;

  if (0 < param_4) {

    do {

      pfVar6 = param_2;

      if (local_4 == 0) {

        *param_2 = 0.0;

        param_2[1] = 0.0;

        if (param_7 == 1) {

          param_2[2] = param_5 + param_6;

        }

        else {

          param_2[2] = param_6;

        }

        param_2[3] = 0.0;

        param_2[4] = 0.0;

        param_2[5] = 1.0;

        param_2[6] = 0.0;

        param_2[7] = 0.0;

        pfVar6 = param_2 + 8;

      }

      param_2 = (float *)0x0;

      if (0 < param_3) {

        do {

          pfVar6[3] = 0.0;

          pfVar6[4] = 0.0;

          pfVar6[5] = 1.0;

          fVar10 = ((float10)(int)param_2 * (float10)6.2831855) / (float10)param_3;

          fVar11 = (float10)fsin((float10)param_9 * fVar10);

          fVar12 = (float10)fcos((float10)param_9 * fVar10);

          *pfVar6 = (float)(fVar11 * fVar9);

          pfVar6[1] = (float)((float10)(float)fVar12 * fVar9);

          pfVar6[2] = (float)fVar8;

          if (param_7 == 1) {

            pfVar6[6] = (float)(fVar10 * (float10)0.15915494);

            fVar10 = (float10)local_8 * (float10)0.63661975;

          }

          else if (param_7 == 0) {

            pfVar6[6] = (float)(fVar11 * fVar9) * param_8;

            fVar10 = (float10)(float)((float10)(float)fVar12 * fVar9) * (float10)param_8;

          }

          else {

            pfVar6[6] = (float)(fVar10 * (float10)0.15915494);

            fVar10 = (float10)param_6 - fVar8;

          }

          pfVar6[7] = (float)fVar10;

          pfVar6 = pfVar6 + 8;

          sVar4 = (short)param_3;

          sVar3 = (short)param_2;

          if (local_4 == 0) {

            *param_1 = 0;

            if (param_2 == (float *)0x0) {

              param_1[1] = sVar4;

              param_1[2] = 1;

              param_1 = param_1 + 3;

            }

            else {

              param_1[1] = sVar3;

              param_1[2] = sVar3 + 1;

              param_1 = param_1 + 3;

            }

          }

          else {

            sVar1 = (short)local_4;

            if (param_2 == (float *)0x0) {

              sVar3 = sVar1 * sVar4;

              *param_1 = sVar3;

              param_1[1] = (sVar1 + 1) * sVar4;

              param_1[2] = sVar3 + 1;

              param_1[3] = sVar3;

              param_1[4] = sVar3 + 1;

              sVar3 = (sVar1 + -1) * sVar4 + 1;

            }

            else {

              sVar2 = (sVar1 + -1) * sVar4;

              sVar5 = sVar2 + sVar3;

              *param_1 = sVar5;

              param_1[1] = sVar1 * sVar4 + sVar3;

              sVar4 = sVar1 * sVar4 + 1 + sVar3;

              param_1[2] = sVar4;

              param_1[3] = sVar5;

              param_1[4] = sVar4;

              sVar3 = sVar2 + 1 + sVar3;

            }

            param_1[5] = sVar3;

            param_1 = param_1 + 6;

          }

          param_2 = (float *)((int)param_2 + 1);

        } while ((int)param_2 < param_3);

      }

      if (param_7 == 1) {

        fVar8 = (float10)local_8;

        local_8 = (float)(fVar8 + fVar7);

        fVar8 = (float10)fcos(fVar8 + fVar7);

        fVar8 = fVar8 * (float10)param_5 + (float10)param_6;

        fVar9 = (float10)fsin((float10)local_8);

        fVar9 = fVar9 * (float10)param_5;

      }

      else if (param_7 == 0) {

        fVar9 = fVar9 + fVar7;

      }

      else {

        fVar8 = fVar8 - fVar7;

      }

      local_4 = local_4 + 1;

      param_2 = pfVar6;

    } while (local_4 < param_4);

  }

  return;

}

/* ===== giftshopview_enable @ 0x00452490 ===== */
/* PS2 candidate: giftshopview_enable (conf 0.524) */



void giftshopview_enable(int *param_1,int *param_2)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  int *piVar7;

  undefined4 uVar8;

  

  if (((DAT_00632e74 != 0) && (DAT_00632e7c == 0)) && (DAT_00632bd8 == 0)) {

    return;

  }

  if (DAT_00632a88 == 0) {

    return;

  }

  iVar2 = ObjIsMecc(DAT_00632a88);

  if ((iVar2 == 0) && (iVar2 = ObjIsReaper(DAT_00632a88), iVar2 == 0)) {

    return;

  }

  piVar7 = param_1;

  if (DAT_00632bb4 != 0) {

    return;

  }

  DAT_0059d984 = 0;

  if (param_1 != (int *)0x0) {

    if (DAT_00632bbc == 0) {

      DAT_0059d984 = 0;

      return;

    }

    if (param_1[0x39] < 4) {

      DAT_0059d984 = 0;

      return;

    }

    if ((param_1[1] == 0x3da) || (DAT_0059d984 = 0, param_1[1] == 0x3dd)) {

      DAT_0059d984 = 1;

    }

  }

  dlog_push_level(&LAB_00454820,&LAB_00454360);

  dialog_level_set_textentry_mode();

  piVar1 = param_2;

  DAT_00632bb4 = 1;

  DAT_00633020 = 0;

  DAT_0059d96c = piVar7;

  DAT_0059d970 = param_2;

  DAT_00656408 = (int *)0x0;

  if (DAT_00632bbc == 0) {

    DAT_00656404 = 0;

  }

  else {

    DAT_00656404 = FUN_004188e0(DAT_00632bbc);

  }

  if (DAT_0059d970 != (int *)0x0) {

    DAT_00656408 = DAT_0059d970 + 0x3d;

  }

  if (DAT_0059d96c != (int *)0x0) {

    DAT_00656408 = DAT_0059d96c + 0x3d;

  }

  DAT_0059d860 = 0xffffffff;

  DAT_0059d85c = 0xffffffff;

  DAT_0059d858 = 0xffffffff;

  iVar2 = ObjIsMecc(DAT_00632a88);

  if (iVar2 == 0) {

    iVar2 = ObjIsReaper(DAT_00632a88);

    if (iVar2 != 0) {

      obj_snap_variant_a(DAT_00632a88);

      piVar1 = param_2;

      iVar2 = *(int *)(DAT_00632a88 + 0x100);

      piVar7 = (int *)(iVar2 + 0xd84);

      iVar3 = 3;

      do {

        if ((DAT_0059d984 == 0) && (piVar1 == (int *)0x0)) {

          iVar5 = IconDefMaxAmmo(piVar7[-1]);

LAB_0045289f:

          *piVar7 = iVar5;

        }

        else {

          iVar5 = IconDefGiveAmmo(piVar7[-1]);

          if (*piVar7 < iVar5) goto LAB_0045289f;

        }

        piVar7 = piVar7 + 2;

        iVar3 = iVar3 + -1;

      } while (iVar3 != 0);

      if ((DAT_0059d984 == 0) && (piVar1 == (int *)0x0)) {

        uVar8 = 0xffffffff;

      }

      else {

        uVar8 = 1;

      }

      reaper_give_all_spell_energy(DAT_00632a88,uVar8);

      if ((DAT_0059d984 == 0) && (piVar1 == (int *)0x0)) {

        piVar7 = (int *)(iVar2 + 0xd98);

        iVar2 = 2;

        do {

          iVar3 = *piVar7;

          if ((-1 < iVar3) && ((iVar3 != 0x3f || (DAT_0059d97c < 0x14)))) {

            iVar3 = IconDefMaxAmmo(iVar3);

            piVar7[1] = iVar3;

          }

          piVar7 = piVar7 + 2;

          iVar2 = iVar2 + -1;

        } while (iVar2 != 0);

      }

      else {

        piVar7 = (int *)(iVar2 + 0xd98);

        iVar2 = 2;

        do {

          iVar3 = *piVar7;

          if (-1 < iVar3) {

            if (iVar3 == 0x3f) {

              if (DAT_0059d97c < 0x14) {

                iVar3 = 0x3f;

LAB_0045294e:

                iVar3 = IconDefGiveAmmo(iVar3);

                piVar7[1] = iVar3;

              }

            }

            else {

              iVar3 = IconDefGiveAmmo(iVar3);

              if (piVar7[1] < iVar3) {

                iVar3 = *piVar7;

                goto LAB_0045294e;

              }

            }

          }

          piVar7 = piVar7 + 2;

          iVar2 = iVar2 + -1;

        } while (iVar2 != 0);

      }

    }

  }

  else {

    mecc_stop_looping_effects();

    mecc_disable_repair_gun(DAT_00632a88);

    if ((DAT_0059d984 == 0) && (piVar1 == (int *)0x0)) {

      iVar2 = 0;

      do {

        iVar3 = FUN_00457fb0(DAT_00632a88,iVar2);

        if ((iVar3 != -1) && (iVar3 = IconDefAmmoIcon(iVar3), iVar3 != -1)) {

          inv_award_item(DAT_00632a88,0xffffffff,iVar3,999999,1);

        }

        iVar2 = iVar2 + 1;

      } while (iVar2 < 4);

    }

    else {

      iVar2 = 0;

      do {

        iVar3 = FUN_00457fb0(DAT_00632a88,iVar2);

        if (((iVar3 != -1) && (iVar5 = IconDefAmmoIcon(iVar3), iVar5 != -1)) &&

           (iVar5 = IconDefAmmoIcon(iVar3), iVar5 != -1)) {

          param_1 = (int *)0x0;

          item_get_ammo(DAT_00632a88,iVar5,&param_1);

          if (param_1 != (int *)0x0) {

            if (iVar3 == 5) {

              iVar6 = __ftol();

            }

            else {

              iVar6 = *param_1;

            }

            iVar4 = IconDefGiveAmmo(iVar3);

            if (iVar6 < iVar4) {

              *param_1 = 0;

              uVar8 = IconDefGiveAmmo(iVar3,1);

              inv_award_item(DAT_00632a88,0xffffffff,iVar5,uVar8);

            }

          }

        }

        iVar2 = iVar2 + 1;

      } while (iVar2 < 4);

    }

    if ((DAT_0059d984 == 0) && (param_2 == (int *)0x0)) {

      iVar2 = 0;

      do {

        iVar3 = FUN_004582d0(DAT_00632a88,iVar2);

        if (iVar3 != -1) {

          if (iVar3 == 9) {

            if (0x13 < DAT_0059d97c) goto LAB_0045276d;

            iVar3 = 9;

          }

          inv_award_item(DAT_00632a88,iVar2,iVar3,999999,1);

        }

LAB_0045276d:

        iVar2 = iVar2 + 1;

      } while (iVar2 < 3);

    }

    else {

      iVar2 = 0;

      do {

        iVar3 = FUN_004582d0(DAT_00632a88,iVar2);

        if ((iVar3 != -1) && (iVar3 != 0)) {

          param_2 = (int *)0x0;

          item_get_ammo(DAT_00632a88,iVar3,&param_2);

          if (param_2 != (int *)0x0) {

            if (iVar3 == 5) {

              iVar5 = __ftol();

            }

            else {

              iVar5 = *param_2;

            }

            iVar6 = IconDefGiveAmmo(iVar3);

            if (iVar5 < iVar6) {

              *param_2 = 0;

              if (iVar3 == 9) {

                if (0x13 < DAT_0059d97c) goto LAB_0045282a;

                uVar8 = IconDefGiveAmmo(9,1);

              }

              else {

                uVar8 = IconDefGiveAmmo(iVar3,1);

              }

              inv_award_item(DAT_00632a88,iVar2,iVar3,uVar8);

            }

          }

        }

LAB_0045282a:

        iVar2 = iVar2 + 1;

      } while (iVar2 < 3);

    }

  }

  iVar2 = main_status_00500520(&DAT_00632900);

  if (iVar2 == 0) {

    dialog_level_pop(&LAB_00454820);

    DAT_00632bb4 = 0;

    if (DAT_00632e7c != 0) {

      wredit_spawn_object();

      return;

    }

    if (DAT_00632bd8 == 0) {

      DAT_00632bb4 = 0;

      return;

    }

    mission_type_dispatch();

    return;

  }

  BinFileCreateWrite(0x42700000);

  iVar2 = ObjIsMecc(DAT_00632a88);

  DAT_0063291c = 10 - (uint)(iVar2 != 0);

  DAT_00632928 = DAT_00632e88;

  DAT_00632920 = 0xffffffff;

  DAT_00632924 = DAT_00632e84;

  if (DAT_0059d96c == (int *)0x0) {

    if (DAT_0059d970 == (int *)0x0) goto LAB_00452a14;

    uVar8 = 2;

    piVar7 = DAT_0059d970;

  }

  else {

    uVar8 = 10;

    piVar7 = DAT_0059d96c;

  }

  camera_override_refpt(piVar7,uVar8);

LAB_00452a14:

  sound_play(0x673);

  return;

}

/* ===== FUN_00452a30 @ 0x00452A30 ===== */
void FUN_00452a30(int param_1,int param_2)



{

  int iVar1;

  undefined4 *puVar2;

  

  DAT_0059d98c = DAT_0059d994;

  DAT_0059d988 = DAT_0059d990;

  if ((DAT_0059d998 == 0) || (param_2 != 0)) {

    puVar2 = &DAT_0059d868;

    for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {

      *puVar2 = 0xffffffff;

      puVar2 = puVar2 + 1;

    }

    DAT_0059d988 = 0;

    DAT_0059d98c = 0;

    puVar2 = &DAT_0059d8e8;

    for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {

      *puVar2 = 0xffffffff;

      puVar2 = puVar2 + 1;

    }

    DAT_0059d99c = 0;

  }

  else {

    puVar2 = &DAT_0059d868;

    for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {

      *puVar2 = 0xffffffff;

      puVar2 = puVar2 + 1;

    }

    puVar2 = &DAT_0059d8e8;

    for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {

      *puVar2 = 0xffffffff;

      puVar2 = puVar2 + 1;

    }

    if (param_1 != 0) {

      fx_emitter_flags_setup(DAT_0059d988,DAT_0059d98c,0);

      DAT_0059d99c = 1;

      return;

    }

  }

  return;

}

/* ===== FUN_00452ae0 @ 0x00452AE0 ===== */
/* PS2 candidate: fx_free_effect__FP9FXLISTTAG (conf 0.726) */



void FUN_00452ae0(undefined4 *param_1,undefined4 *param_2)



{

  *param_1 = DAT_0059d988;

  *param_2 = DAT_0059d98c;

  return;

}

/* ===== fx_emitter_flags_setup @ 0x00452B00 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void fx_emitter_flags_setup(uint param_1,uint param_2,int param_3)



{

  int iVar1;

  undefined4 *puVar2;

  

  if ((DAT_0059d998 == 0) || (param_3 != 0)) {

    DAT_0059d99c = 0;

  }

  puVar2 = &DAT_0059d868;

  for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar2 = 0xffffffff;

    puVar2 = puVar2 + 1;

  }

  puVar2 = &DAT_0059d8e8;

  for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar2 = 0xffffffff;

    puVar2 = puVar2 + 1;

  }

  DAT_0059d988 = param_1;

  iVar1 = 0;

  do {

    if ((param_1 & 1 << ((byte)iVar1 & 0x1f)) != 0) {

      switch(iVar1) {

      case 0:

        DAT_0059d868 = 0x15;

        break;

      case 1:

        DAT_0059d86c = 0x16;

        break;

      case 2:

        _DAT_0059d870 = 0x17;

        break;

      case 3:

        _DAT_0059d874 = 0x18;

        break;

      case 4:

        _DAT_0059d878 = 0x19;

        break;

      case 5:

        _DAT_0059d87c = 0x1b;

        break;

      case 6:

        _DAT_0059d880 = 0x1c;

        break;

      case 7:

        _DAT_0059d884 = 0x1d;

        break;

      case 8:

        _DAT_0059d888 = 0x1e;

        break;

      case 9:

        _DAT_0059d88c = 0x1f;

        break;

      case 10:

        _DAT_0059d890 = 0x21;

        break;

      case 0xb:

        _DAT_0059d894 = 0x3f;

        break;

      case 0xc:

        _DAT_0059d898 = 0x48;

        break;

      case 0xd:

        _DAT_0059d89c = 0x3b;

        break;

      case 0xe:

        _DAT_0059d8a0 = 0x2d;

        break;

      case 0xf:

        _DAT_0059d8a4 = 0x2f;

        break;

      case 0x10:

        _DAT_0059d8a8 = 0x2e;

        break;

      case 0x11:

        _DAT_0059d8ac = 0x30;

        break;

      case 0x12:

        _DAT_0059d8b0 = 0x45;

        break;

      case 0x13:

        _DAT_0059d8b4 = 0x46;

        break;

      case 0x14:

        _DAT_0059d8b8 = 0x41;

        break;

      case 0x15:

        _DAT_0059d8bc = 0x44;

        break;

      case 0x16:

        _DAT_0059d8c0 = 0x43;

        break;

      case 0x17:

        _DAT_0059d8c4 = 0x47;

        break;

      case 0x18:

        _DAT_0059d8c8 = 0x42;

      }

    }

    iVar1 = iVar1 + 1;

  } while (iVar1 < 0x20);

  DAT_0059d98c = param_2;

  iVar1 = 0;

  do {

    if ((param_2 & 1 << ((byte)iVar1 & 0x1f)) != 0) {

      switch(iVar1) {

      case 0:

        DAT_0059d8e8 = 3;

        break;

      case 1:

        DAT_0059d8ec = 6;

        break;

      case 2:

        _DAT_0059d8f0 = 0xf;

        break;

      case 3:

        _DAT_0059d8f4 = 0x10;

        break;

      case 4:

        _DAT_0059d8f8 = 0xe;

        break;

      case 5:

        _DAT_0059d8fc = 0;

        break;

      case 6:

        _DAT_0059d900 = 9;

        break;

      case 7:

        _DAT_0059d904 = 0x40;

        break;

      case 8:

        _DAT_0059d908 = 8;

        break;

      case 9:

        _DAT_0059d90c = 0x14;

        break;

      case 10:

        _DAT_0059d910 = 10;

        break;

      case 0xb:

        _DAT_0059d914 = 0xb;

        break;

      case 0xc:

        _DAT_0059d918 = 0x12;

        break;

      case 0xd:

        _DAT_0059d91c = 0x11;

        break;

      case 0xe:

        _DAT_0059d920 = 5;

        break;

      case 0xf:

        _DAT_0059d924 = 7;

        break;

      case 0x10:

        _DAT_0059d928 = 0x35;

        break;

      case 0x11:

        _DAT_0059d92c = 0x36;

        break;

      case 0x12:

        _DAT_0059d930 = 0x34;

        break;

      case 0x13:

        _DAT_0059d934 = 0x31;

        break;

      case 0x14:

        _DAT_0059d938 = 0x32;

        break;

      case 0x15:

        _DAT_0059d93c = 0x33;

      }

    }

    iVar1 = iVar1 + 1;

  } while (iVar1 < 0x20);

  return;

}

/* ===== FUN_00452ee0 @ 0x00452EE0 ===== */
undefined4 FUN_00452ee0(int param_1)



{

  int iVar1;

  

  iVar1 = dialog_level_is_base();

  if (iVar1 != 0) {

    iVar1 = 0;

    do {

      if ((*(int *)((int)&DAT_0059d868 + iVar1) == param_1) ||

         (*(int *)((int)&DAT_0059d8e8 + iVar1) == param_1)) {

        return 1;

      }

      iVar1 = iVar1 + 4;

    } while (iVar1 < 0x80);

  }

  return 0;

}

/* ===== IconIsAvailable__Fi @ 0x00452F20 ===== */
/* PS2 candidate: IconIsAvailable__Fi (conf 0.521) */



uint IconIsAvailable__Fi(int param_1)



{

  int iVar1;

  uint uVar2;

  bool bVar3;

  

  if (param_1 != -1) {

    iVar1 = dialog_level_is_base();

    if (iVar1 != 0) {

      iVar1 = 0;

      do {

        if (*(int *)((int)&DAT_0059d868 + iVar1) == param_1) {

          return 0;

        }

        if (*(int *)((int)&DAT_0059d8e8 + iVar1) == param_1) {

          return 0;

        }

        iVar1 = iVar1 + 4;

      } while (iVar1 < 0x80);

    }

    if (DAT_0059d96c == 0) {

      if (DAT_0059d970 == 0) {

        return 1;

      }

LAB_00452f80:

      uVar2 = FUN_00454a40(DAT_0059d970,param_1);

      return uVar2;

    }

    if (DAT_0059d970 != 0) goto LAB_00452f80;

    if (DAT_00632e7c != 0) {

      return 1;

    }

    if (DAT_0059d984 != 0) {

      if (param_1 == DAT_0059d858) {

        return 1;

      }

      if (param_1 == DAT_0059d85c) {

        return 1;

      }

      if (param_1 == DAT_0059d860) {

        return 1;

      }

      if (((DAT_0059d99c != 0) && (iVar1 = FUN_005213a0(DAT_00632f18), iVar1 == 0)) &&

         (iVar1 = FUN_00521330(DAT_00632f18), iVar1 == 0)) {

        return 1;

      }

      if (param_1 != 0x21) {

        return (uint)(param_1 != 10);

      }

      return 0;

    }

    if (param_1 == DAT_0059d858) {

      return 1;

    }

    if (param_1 == DAT_0059d85c) {

      return 1;

    }

    if (param_1 == DAT_0059d860) {

      return 1;

    }

    switch(param_1) {

    case 0:

    case 1:

    case 2:

    case 3:

    case 5:

    case 0x11:

    case 0x13:

    case 0x15:

    case 0x16:

    case 0x18:

    case 0x2c:

    case 0x2d:

    case 0x2e:

    case 0x3b:

    case 0x48:

    case 0x49:

      goto switchD_0045302d_caseD_0;

    default:

      goto switchD_0045302d_caseD_4;

    case 6:

    case 8:

    case 0xe:

    case 0x10:

    case 0x14:

      return (uint)(*(int *)(DAT_0059d96c + 4) != 0x2c6);

    case 7:

    case 10:

    case 0xc:

    case 0xd:

    case 0xf:

    case 0x12:

    case 0x40:

      bVar3 = *(int *)(DAT_0059d96c + 4) == 0x2cc;

      break;

    case 9:

    case 0x3f:

      return (uint)(DAT_0059d97c < 0x14);

    case 0xb:

      return (uint)(DAT_0059d974 < 5);

    case 0x17:

    case 0x19:

    case 0x1a:

    case 0x1b:

    case 0x1c:

    case 0x1d:

    case 0x1e:

    case 0x1f:

    case 0x2f:

      return (uint)(*(int *)(DAT_0059d96c + 4) == 0x2e0);

    case 0x21:

    case 0x30:

      bVar3 = *(int *)(DAT_0059d96c + 4) == 0x2e0;

    }

    if ((bVar3) && (DAT_00656404 != 0)) {

switchD_0045302d_caseD_0:

      return 1;

    }

  }

switchD_0045302d_caseD_4:

  return 0;

}

/* ===== fx_time_budget @ 0x004543C0 ===== */
void fx_time_budget(void)



{

  int iVar1;

  float10 fVar2;

  

  iVar1 = dialog_level_is_base();

  if (iVar1 == 0) {

    if (DAT_00656408 == (float *)0x0) {

      return;

    }

    if (*DAT_00656408 <= 0.0) {

      return;

    }

    if (*(float *)(DAT_00632a88 + 0x278) <= 0.0) {

      return;

    }

    fVar2 = (float10)FUN_00518b70(DAT_00632a88,0);

    fVar2 = fVar2 * (float10)*(float *)(DAT_00632ed8 + 0x10e4);

    if ((float10)*(float *)(DAT_00632a88 + 0x278) < fVar2) {

      fVar2 = (float10)*(float *)(DAT_00632a88 + 0x278);

    }

    if ((float10)*DAT_00656408 <= fVar2) {

      *(float *)(DAT_00632a88 + 0x278) = *(float *)(DAT_00632a88 + 0x278) - *DAT_00656408;

      *DAT_00656408 = 0.0;

    }

    else {

      *DAT_00656408 = (float)((float10)*DAT_00656408 - fVar2);

      *(float *)(DAT_00632a88 + 0x278) = (float)((float10)*(float *)(DAT_00632a88 + 0x278) - fVar2);

    }

  }

  else {

    fVar2 = (float10)FUN_00518b70(DAT_00632a88,0);

    fVar2 = fVar2 * (float10)*(float *)(DAT_00632ed8 + 0x10e4);

    if ((float10)*(float *)(DAT_00632a88 + 0x278) < fVar2) {

      fVar2 = (float10)*(float *)(DAT_00632a88 + 0x278);

    }

    *(float *)(DAT_00632a88 + 0x278) = (float)((float10)*(float *)(DAT_00632a88 + 0x278) - fVar2);

  }

  if (*(float *)(DAT_00632a88 + 0x278) < 0.0) {

    *(undefined4 *)(DAT_00632a88 + 0x278) = 0;

  }

  return;

}

/* ===== giftshop_exit__Fv @ 0x004544F0 ===== */
/* PS2 candidate: giftshop_exit__Fv (conf 0.426) */



void giftshop_exit__Fv(void)



{

  int iVar1;

  undefined4 uVar2;

  float10 fVar3;

  float10 fVar4;

  undefined1 local_18 [12];

  undefined1 local_c [12];

  

  DAT_00632ae7 = 0;

  DAT_00632aa4._3_1_ = 0;

  DAT_00632aeb = 0;

  camera_fov_update();

  dialog_level_pop(&LAB_00454820);

  DAT_00632bb4 = 0;

  if ((((DAT_0059d96c == 0) ||

       ((*(int *)(DAT_0059d96c + 4) != 0x3da && (*(int *)(DAT_0059d96c + 4) != 0x3dd)))) &&

      (DAT_00632a88 != 0)) && (DAT_00632bbc != 0)) {

    iVar1 = fx_create(DAT_00632bbc);

    if (iVar1 == 0) {

      iVar1 = dialog_level_is_base();

      if (iVar1 != 0) {

        reaper_state_check_f(DAT_00632bbc,DAT_00632a88);

      }

    }

    else {

      base_giftshop_exit(DAT_00632bbc,DAT_00632a88);

    }

  }

  if (((DAT_0059d96c == 0) || (DAT_00632a88 == 0)) || (DAT_00632bbc == 0)) {

    if ((DAT_0059d970 != 0) && (DAT_00632a88 != 0)) {

      FUN_004186c0(DAT_0059d970,1,DAT_00632a88 + 0xa0,DAT_00632a88 + 200);

      object_copy_posdirinfo(DAT_00632a88);

      FUN_0040d790();

      iVar1 = ObjIsReaper(DAT_00632a88);

      if (iVar1 != 0) {

        *(uint *)(DAT_00632a88 + 0xe0) = *(uint *)(DAT_00632a88 + 0xe0) | 1;

      }

      *(undefined4 *)(DAT_0059d970 + 0x274) = 0;

      *(undefined4 *)(DAT_00632a88 + 0x210) = 0;

      iVar1 = reaper_0052e4a0(DAT_00632a88);

      if (iVar1 != 0) {

        reaper_00530bd0(DAT_0059d970,0,0,0,6,0);

      }

    }

  }

  else {

    if ((*(int *)(DAT_0059d96c + 4) == 0x3da) || (*(int *)(DAT_0059d96c + 4) == 0x3dd)) {

      iVar1 = fx_create(DAT_00632bbc);

      if (iVar1 == 0) {

        iVar1 = dialog_level_is_base();

        if (iVar1 != 0) {

          reaper_state_check_h(DAT_00632bbc,DAT_00632a88,DAT_0059d96c);

        }

      }

      else {

        base_partyhouse_exit(DAT_00632a88,DAT_0059d96c);

      }

    }

    uVar2 = 0xc;

    if (*(int *)(DAT_0059d96c + 4) == 0x2cc) {

      FUN_00418630(DAT_0059d96c,0xc,local_c);

      FUN_00418630(DAT_0059d96c,0xe,local_18);

      fVar3 = (float10)FUN_0050a610(local_18,DAT_00632a88 + 0xa0);

      fVar4 = (float10)FUN_0050a610(local_c,DAT_00632a88 + 0xa0);

      if ((float10)(float)fVar3 < fVar4) {

        uVar2 = 0xe;

      }

    }

    else if (*(int *)(DAT_0059d96c + 4) == 0x2e0) {

      FUN_00418630(DAT_0059d96c,0xc,local_18);

      FUN_00418630(DAT_0059d96c,0x12,local_c);

      fVar3 = (float10)FUN_0050a610(local_c,DAT_00632a88 + 0xa0);

      fVar4 = (float10)FUN_0050a610(local_18,DAT_00632a88 + 0xa0);

      if ((float10)(float)fVar3 < fVar4) {

        uVar2 = 0x12;

      }

    }

    if (DAT_0059d984 != 0) {

      uVar2 = 1;

    }

    FUN_004186c0(DAT_0059d96c,uVar2,DAT_00632a88 + 0xa0,DAT_00632a88 + 200);

    object_copy_posdirinfo(DAT_00632a88);

    FUN_0040d790();

  }

  DAT_0059d96c = 0;

  DAT_0059d970 = 0;

  if (DAT_00632e7c == 0) {

    if (DAT_00632bd8 != 0) {

      mission_type_dispatch();

    }

    sound_play(0x674);

    return;

  }

  wredit_spawn_object();

  sound_play(0x674);

  return;

}

/* ===== FUN_00454a40 @ 0x00454A40 ===== */
/* PS2 candidate: minishop_icon_is_available (conf 0.703) */



undefined4 FUN_00454a40(int param_1,int param_2)



{

  float fVar1;

  int *piVar2;

  int iVar3;

  int *piVar4;

  

  piVar2 = *(int **)(param_1 + 0x100);

  iVar3 = dialog_level_is_base();

  if (iVar3 != 0) {

    return 1;

  }

  iVar3 = ObjIsReaper(DAT_00632a88);

  if (iVar3 == 0) {

    if (param_2 == 1) {

      return 1;

    }

    if (param_2 == DAT_0059d858) {

      return 1;

    }

    if (param_2 == DAT_0059d85c) {

      return 1;

    }

    if (param_2 == DAT_0059d860) {

      return 1;

    }

    iVar3 = 0;

    if (piVar2[0x29] < 1) {

      return 0;

    }

    piVar4 = piVar2 + 0x2a;

    while (*piVar4 != param_2) {

      iVar3 = iVar3 + 1;

      piVar4 = piVar4 + 1;

      if (piVar2[0x29] <= iVar3) {

        return 0;

      }

    }

    fVar1 = (float)piVar2[iVar3 + 0x3e];

  }

  else {

    if (param_2 == 0x2c) {

      return 1;

    }

    if (param_2 == DAT_0059d858) {

      return 1;

    }

    if (param_2 == DAT_0059d85c) {

      return 1;

    }

    if (param_2 == DAT_0059d860) {

      return 1;

    }

    iVar3 = 0;

    piVar4 = piVar2;

    if (*piVar2 < 1) {

      return 0;

    }

    while (piVar4[1] != param_2) {

      iVar3 = iVar3 + 1;

      piVar4 = piVar4 + 1;

      if (*piVar2 <= iVar3) {

        return 0;

      }

    }

    fVar1 = (float)piVar2[iVar3 + 0x15];

  }

  if (fVar1 < 0.0 == (fVar1 == 0.0)) {

    return 0;

  }

  return 1;

}

/* ===== reaper_bldg_check @ 0x00454B10 ===== */
void reaper_bldg_check(int param_1,int param_2,int param_3)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  int *piVar4;

  undefined4 uVar5;

  

  iVar2 = param_3;

  piVar1 = *(int **)(param_1 + 0x100);

  if (param_2 == 0) {

    iVar3 = 0;

    if (piVar1[0x29] < 1) {

      return;

    }

    piVar4 = piVar1 + 0x2a;

    while (*piVar4 != param_3) {

      iVar3 = iVar3 + 1;

      piVar4 = piVar4 + 1;

      if (piVar1[0x29] <= iVar3) {

        return;

      }

    }

    piVar1[iVar3 + 0x3e] = *(int *)(DAT_00632ed8 + 0x374);

    iVar3 = fx_create(param_1);

    if (iVar3 != 0) {

      return;

    }

    uVar5 = 4;

  }

  else {

    iVar3 = 0;

    piVar4 = piVar1;

    if (*piVar1 < 1) {

      return;

    }

    while (piVar4[1] != param_3) {

      iVar3 = iVar3 + 1;

      piVar4 = piVar4 + 1;

      if (*piVar1 <= iVar3) {

        return;

      }

    }

    piVar1[iVar3 + 0x15] = *(int *)(DAT_00632ed8 + 0x374);

    iVar3 = fx_create(param_1);

    if (iVar3 != 0) {

      return;

    }

    uVar5 = 2;

  }

  param_3 = CONCAT31(param_3._1_3_,(char)iVar2);

  reaper_00530bd0(param_1,0,0,1,uVar5,&param_3);

  return;

}

/* ===== minishop_update_mecc_icons_2 @ 0x00454D80 ===== */
/* PS2 candidate: minishop_update_mecc_icons (conf 0.845) */



void minishop_update_mecc_icons_2(int param_1,uint param_2)



{

  undefined4 *puVar1;

  int iVar2;

  

  puVar1 = (undefined4 *)(*(int *)(param_1 + 0x100) + 0x54);

  iVar2 = 0x14;

  do {

    if ((param_2 & 1) == 0) {

      *puVar1 = 0x4426aaa0;

    }

    else {

      *puVar1 = 0;

    }

    param_2 = (int)param_2 >> 1;

    puVar1 = puVar1 + 1;

    iVar2 = iVar2 + -1;

  } while (iVar2 != 0);

  return;

}

/* ===== minishop_update_mecc_icons @ 0x00454DC0 ===== */
/* PS2 candidate: minishop_update_mecc_icons_2 (conf 0.845) */



void minishop_update_mecc_icons(int param_1,uint param_2)



{

  undefined4 *puVar1;

  int iVar2;

  

  puVar1 = (undefined4 *)(*(int *)(param_1 + 0x100) + 0xf8);

  iVar2 = 0x14;

  do {

    if ((param_2 & 1) == 0) {

      *puVar1 = 0x4426aaa0;

    }

    else {

      *puVar1 = 0;

    }

    param_2 = (int)param_2 >> 1;

    puVar1 = puVar1 + 1;

    iVar2 = iVar2 + -1;

  } while (iVar2 != 0);

  return;

}

/* ===== reaper_spell_big @ 0x00454E00 ===== */
void reaper_spell_big(int param_1,undefined4 param_2,undefined4 param_3,byte *param_4)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  float *pfVar5;

  undefined4 local_8;

  uint local_4;

  

  switch(param_2) {

  case 1:

    iVar3 = fx_create(param_1);

    if (((iVar3 != 0) && (*(int *)(param_1 + 0x274) == 0)) &&

       (iVar3 = FUN_0052e5b0(*(undefined4 *)param_4), *(int *)(iVar3 + 0x210) == 0)) {

      iVar2 = ObjIsReaper(iVar3);

      if (iVar2 != 0) {

        piVar1 = *(int **)(param_1 + 0x100);

        *(int *)(param_1 + 0x274) = iVar3;

        local_4 = 0;

        iVar2 = 0;

        if (0 < *piVar1) {

          pfVar5 = (float *)(piVar1 + 0x15);

          do {

            if (*pfVar5 < 0.0 != (*pfVar5 == 0.0)) {

              local_4 = local_4 | 1 << ((byte)iVar2 & 0x1f);

            }

            iVar2 = iVar2 + 1;

            pfVar5 = pfVar5 + 1;

          } while (iVar2 < *piVar1);

        }

        local_8 = *(undefined4 *)(param_1 + 0x188);

        reaper_00530bd0(iVar3,0,2,0,0x30,&local_8);

        reaper_animselect(iVar3,0x30,8,&local_8);

        return;

      }

      iVar2 = ObjIsMecc(iVar3);

      if (iVar2 != 0) {

        iVar2 = *(int *)(param_1 + 0x100);

        *(int *)(param_1 + 0x274) = iVar3;

        local_4 = 0;

        iVar4 = 0;

        if (0 < *(int *)(iVar2 + 0xa4)) {

          pfVar5 = (float *)(iVar2 + 0xf8);

          do {

            if (*pfVar5 < 0.0 != (*pfVar5 == 0.0)) {

              local_4 = local_4 | 1 << ((byte)iVar4 & 0x1f);

            }

            iVar4 = iVar4 + 1;

            pfVar5 = pfVar5 + 1;

          } while (iVar4 < *(int *)(iVar2 + 0xa4));

        }

        local_8 = *(undefined4 *)(param_1 + 0x188);

        reaper_00530bd0(iVar3,0,2,0,0x1b,&local_8);

        kbos_move(iVar3,0x1b,8,&local_8);

        return;

      }

    }

    break;

  case 2:

    iVar3 = fx_create(param_1);

    if (iVar3 != 0) {

      reaper_bldg_check(param_1,1,*param_4);

      return;

    }

    break;

  case 3:

    *(undefined4 *)(*(int *)(param_1 + 0x100) + 0x54 + (uint)*param_4 * 4) = 0;

    return;

  case 4:

    iVar3 = fx_create(param_1);

    if (iVar3 != 0) {

      reaper_bldg_check(param_1,0,*param_4);

      return;

    }

    break;

  case 5:

    *(undefined4 *)(*(int *)(param_1 + 0x100) + 0xf8 + (uint)*param_4 * 4) = 0;

    break;

  case 6:

    if (*(int *)(param_1 + 0x274) != 0) {

      *(undefined4 *)(*(int *)(param_1 + 0x274) + 0x210) = 0;

    }

    *(undefined4 *)(param_1 + 0x274) = 0;

    return;

  }

  return;

}

/* ===== in_fov @ 0x00455070 ===== */
/* PS2 candidate: in_fov (conf 0.452) */



undefined4 in_fov(int param_1,int param_2,float param_3)



{

  float10 fVar1;

  float local_18;

  float local_14;

  float local_10;

  float local_c;

  float local_8;

  float local_4;

  

  if ((param_2 != 0) && (param_1 != 0)) {

    local_c = -*(float *)(param_1 + 0x29c);

    local_8 = -*(float *)(param_1 + 0x2ac);

    local_4 = -*(float *)(param_1 + 700);

    normalize__FPfN20(&local_c,&local_8,&local_4);

    local_18 = *(float *)(param_2 + 0xa0) - *(float *)(param_1 + 0xa0);

    local_14 = *(float *)(param_2 + 0xa4) - *(float *)(param_1 + 0xa4);

    local_10 = *(float *)(param_2 + 0xa8) - *(float *)(param_1 + 0xa8);

    normalize__FPfN20(&local_18,&local_14,&local_10);

    FUN_00516290(&local_c,&local_18);

    fVar1 = (float10)FUN_005445f0();

    if ((float10)57.339447 * fVar1 < (float10)param_3 * (float10)0.5) {

      return 1;

    }

  }

  return 0;

}

/* ===== FUN_00455150 @ 0x00455150 ===== */
void FUN_00455150(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)



{

  undefined4 uVar1;

  

  uVar1 = __ftol();

  *param_2 = uVar1;

  uVar1 = __ftol();

  *param_3 = uVar1;

  return;

}

/* ===== grid_get_conntype @ 0x00455190 ===== */
/* PS2 candidate: grid_get_conntype (conf 0.534) */



byte grid_get_conntype(int param_1,int param_2)



{

  return *(byte *)(*(int *)(*(int *)(DAT_006330e4 + 0x10) + param_2 * 4) + 0xc + param_1 * 0x10) & 7

  ;

}

/* ===== physics_vec_math @ 0x004551B0 ===== */
int physics_vec_math(float *param_1,float *param_2,uint *param_3,float *param_4,int param_5)



{

  bool bVar1;

  bool bVar2;

  bool bVar3;

  float fVar4;

  float fVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  uint uVar9;

  int iVar10;

  uint uVar11;

  int iVar12;

  bool bVar13;

  float10 extraout_ST0;

  float10 fVar14;

  float local_44;

  float local_30;

  float local_2c;

  float local_28;

  float local_24;

  float local_20;

  float local_1c;

  float local_18;

  float local_14;

  float local_10;

  float local_c;

  float local_8;

  float local_4;

  

  iVar6 = DAT_006330e4;

  local_44 = (*param_1 - *(float *)(DAT_006330e4 + 0x1c8)) * *(float *)(DAT_006330e4 + 0x1c4);

  fVar4 = (param_1[1] - *(float *)(DAT_006330e4 + 0x1cc)) * *(float *)(DAT_006330e4 + 0x1c4);

  bVar1 = (float)(*(int *)(DAT_006330e4 + 0x1d8) + -1) <= local_44;

  if (bVar1) {

    local_44 = (float)(*(int *)(DAT_006330e4 + 0x1d8) + -2);

  }

  bVar2 = (float)(*(int *)(DAT_006330e4 + 0x1dc) + -1) <= fVar4;

  if (bVar2) {

    fVar4 = (float)(*(int *)(DAT_006330e4 + 0x1dc) + -2);

  }

  bVar3 = local_44 < 0.0;

  if (bVar3) {

    local_44 = 0.0;

  }

  iVar7 = __ftol();

  iVar8 = __ftol();

  fVar5 = (float)iVar7;

  bVar13 = (float10)1.0 - (extraout_ST0 - (float10)iVar8) < (float10)(local_44 - fVar5);

  iVar10 = iVar7 * 0x10;

  iVar12 = *(int *)(*(int *)(iVar6 + 0x10) + iVar8 * 4) + iVar10;

  uVar9 = *(byte *)(iVar12 + 0xc) & 7;

  switch(uVar9) {

  case 1:

  case 6:

    uVar11 = bVar13 + 1;

    break;

  case 2:

    uVar11 = bVar13 + 1;

    break;

  case 3:

  case 4:

  case 5:

    uVar11 = 4 - (extraout_ST0 - (float10)iVar8 < (float10)(local_44 - fVar5));

    break;

  default:

    uVar11 = 0;

  }

  if ((uVar11 != uVar9) && (uVar9 < 5)) {

    uVar11 = 0;

  }

  local_18 = fVar5 * *(float *)(iVar6 + 0x1c0) + *(float *)(iVar6 + 0x1c8);

  local_14 = (float)iVar8 * *(float *)(iVar6 + 0x1c0) + *(float *)(iVar6 + 0x1cc);

  local_10 = *(float *)(iVar10 + *(int *)(*(int *)(iVar6 + 0x10) + iVar8 * 4));

  iVar7 = iVar7 + 1;

  local_24 = (float)iVar7 * *(float *)(iVar6 + 0x1c0) + *(float *)(iVar6 + 0x1c8);

  local_20 = (float)iVar8 * *(float *)(iVar6 + 0x1c0) + *(float *)(iVar6 + 0x1cc);

  local_1c = *(float *)(iVar7 * 0x10 + *(int *)(*(int *)(iVar6 + 0x10) + iVar8 * 4));

  iVar8 = iVar8 + 1;

  local_30 = fVar5 * *(float *)(iVar6 + 0x1c0) + *(float *)(iVar6 + 0x1c8);

  local_2c = (float)iVar8 * *(float *)(iVar6 + 0x1c0) + *(float *)(iVar6 + 0x1cc);

  local_28 = *(float *)(iVar10 + *(int *)(*(int *)(iVar6 + 0x10) + iVar8 * 4));

  local_c = (float)iVar7 * *(float *)(iVar6 + 0x1c0) + *(float *)(iVar6 + 0x1c8);

  local_8 = (float)iVar8 * *(float *)(iVar6 + 0x1c0) + *(float *)(iVar6 + 0x1cc);

  local_4 = *(float *)(iVar7 * 0x10 + *(int *)(*(int *)(iVar6 + 0x10) + iVar8 * 4));

  if ((DAT_00632b90 != 0) && (param_5 != 0)) {

    fVar14 = (float10)world_ripple_xform(&local_18);

    local_10 = (float)fVar14;

    fVar14 = (float10)world_ripple_xform(&local_24);

    local_1c = (float)fVar14;

    fVar14 = (float10)world_ripple_xform(&local_30);

    local_28 = (float)fVar14;

    fVar14 = (float10)world_ripple_xform(&local_c);

    local_4 = (float)fVar14;

  }

  switch(uVar11) {

  case 1:

    tri_to_plane__FP3P3DN20P7PLANE3D(&local_24,&local_30,&local_18,param_2);

    break;

  case 2:

    tri_to_plane__FP3P3DN20P7PLANE3D(&local_30,&local_24,&local_c,param_2);

    break;

  case 3:

    tri_to_plane__FP3P3DN20P7PLANE3D(&local_c,&local_18,&local_24,param_2);

    break;

  case 4:

    tri_to_plane__FP3P3DN20P7PLANE3D(&local_18,&local_c,&local_30,param_2);

    break;

  default:

    param_2[1] = 0.0;

    *param_2 = 0.0;

    param_2[2] = 1.0;

    param_2[3] = 61.1;

  }

  if (param_3 != (uint *)0x0) {

    *param_3 = uVar11;

  }

  if (param_4 != (float *)0x0) {

    if (0.0 <= fVar4 && (!bVar3 && (!bVar2 && !bVar1))) {

      if (param_2[2] == 0.0) {

        *param_4 = 0.0;

        return iVar12;

      }

      fVar4 = -((*param_1 * *param_2 + param_2[1] * param_1[1] + param_2[3]) / param_2[2]);

      *param_4 = fVar4;

      if (fVar4 < -61.1) {

        *param_4 = -61.1;

        return iVar12;

      }

    }

    else {

      *param_4 = -61.1;

    }

  }

  return iVar12;

}

/* ===== ai_fly_update_goal_4 @ 0x004555E0 ===== */
void ai_fly_update_goal_4(undefined4 param_1,undefined4 param_2,undefined4 param_3)



{

  physics_vec_math(param_1,param_2,0,param_3,1);

  return;

}

/* ===== FUN_00455600 @ 0x00455600 ===== */
/* PS2 candidate: ground_get_z (conf 0.399) */



float10 FUN_00455600(float param_1)



{

  undefined1 local_10 [16];

  

  physics_vec_math(param_1,local_10,0,&param_1,1);

  return (float10)param_1;

}

/* ===== fx_shape_gen @ 0x00455630 ===== */
int fx_shape_gen(float *param_1,float param_2,float *param_3,float *param_4,undefined4 param_5,

                float *param_6)



{

  float fVar1;

  float *pfVar2;

  float *pfVar3;

  int iVar4;

  int iVar5;

  float local_34;

  float *local_30;

  float local_2c;

  float local_28;

  float local_24;

  float local_20;

  float local_1c;

  float local_18;

  float local_14;

  undefined1 local_10 [16];

  

  pfVar3 = param_4;

  pfVar2 = param_3;

  local_34 = *(float *)(DAT_006330e4 + 0x1c0) * 0.5;

  if (local_34 < param_2) {

    do {

      local_2c = local_34 * *pfVar3 + *param_3;

      local_28 = local_34 * pfVar3[1] + param_3[1];

      local_24 = local_34 * pfVar3[2] + param_3[2];

      physics_vec_math(&local_2c,local_10,0,&param_4,1);

      if (local_24 <= (float)param_4) break;

      local_34 = *(float *)(DAT_006330e4 + 0x1c0) * 0.5 + local_34;

    } while (local_34 < param_2);

    if (local_34 < param_2) {

      iVar4 = 1;

      goto LAB_004556f2;

    }

  }

  iVar4 = 0;

LAB_004556f2:

  param_2 = local_34;

  param_3 = (float *)(local_34 - *(float *)(DAT_006330e4 + 0x1c0) * 0.5);

  fVar1 = 1.0;

  if (iVar4 != 0) {

    iVar5 = 8;

    do {

      fVar1 = (param_2 + (float)param_3) * 0.5;

      local_2c = fVar1 * *pfVar3 + *pfVar2;

      local_28 = fVar1 * pfVar3[1] + pfVar2[1];

      local_24 = fVar1 * pfVar3[2] + pfVar2[2];

      physics_vec_math(&local_2c,local_10,0,&param_4,1);

      local_30 = param_4;

      if (local_24 <= (float)param_4) {

        param_2 = fVar1;

        fVar1 = (float)param_3;

      }

      param_3 = (float *)fVar1;

      iVar5 = iVar5 + -1;

    } while (iVar5 != 0);

    local_2c = param_2 * *pfVar3 + *pfVar2;

    local_34 = param_2;

    local_28 = param_2 * pfVar3[1] + pfVar2[1];

    local_24 = param_2 * pfVar3[2] + pfVar2[2];

    physics_vec_math(&local_2c,&local_20,0,&local_30,1);

    fVar1 = (local_2c - *pfVar2) * local_20 +

            (local_28 - pfVar2[1]) * local_1c + (local_24 - pfVar2[2]) * local_18;

    if (0.0001 <= ABS(fVar1)) {

      fVar1 = -((local_1c * pfVar2[1] + local_18 * pfVar2[2] + local_20 * *pfVar2 + local_14) /

               fVar1);

    }

    else {

      fVar1 = 1.0;

    }

  }

  *param_1 = (local_2c - *pfVar2) * fVar1 + *pfVar2;

  param_1[1] = (local_28 - pfVar2[1]) * fVar1 + pfVar2[1];

  param_1[2] = (local_24 - pfVar2[2]) * fVar1 + pfVar2[2];

  *param_6 = local_34;

  return iVar4;

}

/* ===== project_cursor_to_ground @ 0x00455890 ===== */
/* PS2 candidate: project_cursor_to_ground (conf 0.602) */



void project_cursor_to_ground(undefined4 param_1,undefined4 param_2,undefined4 param_3)



{

  float local_34;

  undefined4 local_30;

  undefined4 local_2c;

  float local_28;

  float local_24;

  undefined4 local_20;

  undefined1 local_1c [4];

  float local_18;

  float local_14;

  undefined4 local_10;

  undefined1 local_c [12];

  

  XFGetViewportExt(&local_30,&local_2c,local_1c,local_c);

  sine_cos_lookup(local_30,&local_28,&local_24);

  sine_cos_lookup(local_2c,&local_20,&local_34);

  local_18 = local_34 * local_28;

  local_10 = local_20;

  local_14 = -(local_34 * local_24);

  fx_shape_gen(param_1,param_2,local_c,&local_18,local_c,param_3);

  return;

}

/* ===== FUN_00455920 @ 0x00455920 ===== */
/* PS2 candidate: project_vector_to_object (conf 0.398) */



int FUN_00455920(code *param_1,undefined4 param_2,int *param_3,float *param_4,float *param_5,

                float *param_6)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  float10 fVar6;

  undefined4 uStack_48;

  undefined4 uStack_44;

  undefined4 uStack_40;

  float local_3c;

  float local_38;

  float local_34;

  undefined1 auStack_30 [12];

  undefined4 uStack_24;

  undefined4 uStack_20;

  undefined4 uStack_1c;

  undefined1 auStack_18 [12];

  undefined1 auStack_c [12];

  

  if ((float)param_3 == 0.0) {

    param_3 = (int *)0x460ca000;

  }

  local_3c = (float)param_3 * *param_6 + *param_5;

  iVar5 = 0;

  local_38 = (float)param_3 * param_6[1] + param_5[1];

  local_34 = (float)param_3 * param_6[2];

  param_3 = DAT_00632d68;

  local_34 = local_34 + param_5[2];

  iVar4 = DAT_00632a88;

  if (DAT_00632d68 != (int *)0x0) {

    do {

      iVar1 = param_3[3];

      if (((-1 < (char)((uint)*(undefined4 *)(iVar1 + 0xd8) >> 8)) && (*(int *)(iVar1 + 8) != 0)) &&

         (iVar1 != iVar4)) {

        iVar3 = iVar1;

        for (iVar2 = *(int *)(iVar1 + 0x210); (iVar2 != 0 && (iVar2 != iVar4));

            iVar2 = *(int *)(iVar2 + 0x210)) {

          iVar3 = iVar2;

        }

        if ((*(int *)(iVar3 + 0x210) != iVar4) &&

           ((param_1 == (code *)0x0 ||

            (iVar3 = (*param_1)(iVar1,param_2), iVar4 = DAT_00632a88, iVar3 != 0)))) {

          if ((*(int *)(iVar1 + 0x10) == 0xfe) ||

             (iVar3 = *(int *)(*(int *)(iVar1 + 8) + 8 + *(int *)(iVar1 + 0x10) * 4),

             iVar4 = iVar3 + 0xc, iVar3 == 0)) {

            iVar4 = *(int *)(*(int *)(iVar1 + 8) + 0x400) + 0x44;

          }

          xformobj_world_local(iVar1,param_5,auStack_c);

          xformobj_world_local(iVar1,&local_3c,auStack_18);

          iVar3 = collide_line_bbox(&uStack_48,auStack_c,auStack_18,iVar4);

          iVar4 = DAT_00632a88;

          if (iVar3 != 0) {

            xformobj_p3d_world(iVar1,&uStack_48,auStack_30);

            fVar6 = (float10)FUN_0050a610(param_5,auStack_30);

            if (((iVar5 == 0) || (iVar4 = DAT_00632a88, fVar6 < (float10)(float)param_6)) &&

               (((*(uint *)(iVar1 + 0x1c8) & 0x1000000) != 0 ||

                (iVar3 = collgrid_anim_audio_user(auStack_c,auStack_18,iVar1,&uStack_48,0),

                iVar4 = DAT_00632a88, iVar3 != 0)))) {

              xformobj_p3d_world(iVar1,&uStack_48,auStack_30);

              fVar6 = (float10)FUN_0050a610(param_5,auStack_30);

              iVar4 = DAT_00632a88;

              if ((iVar5 == 0) || (fVar6 < (float10)(float)param_6)) {

                param_6 = (float *)(float)fVar6;

                uStack_24 = uStack_48;

                uStack_20 = uStack_44;

                uStack_1c = uStack_40;

                iVar5 = iVar1;

              }

            }

          }

        }

      }

      param_3 = (int *)*param_3;

    } while (param_3 != (int *)0x0);

    if (iVar5 != 0) {

      if (param_4 == (float *)0x0) {

        return iVar5;

      }

      xformobj_p3d_world(iVar5,&uStack_24,param_4);

      return iVar5;

    }

  }

  if (param_4 != (float *)0x0) {

    *param_4 = local_3c;

    param_4[1] = local_38;

    param_4[2] = local_34;

  }

  return 0;

}

/* ===== project_cursor_to_object @ 0x00455B70 ===== */
/* PS2 candidate: project_cursor_to_object (conf 0.447) */



void project_cursor_to_object

               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)



{

  undefined4 *puVar1;

  undefined4 local_18;

  undefined4 local_14;

  undefined4 local_10;

  undefined4 local_c;

  undefined4 local_8;

  undefined4 local_4;

  

  puVar1 = (undefined4 *)XFGetCameraOrigin();

  local_c = *puVar1;

  local_8 = puVar1[1];

  local_4 = puVar1[2];

  puVar1 = (undefined4 *)FUN_00515dc0(2);

  local_18 = *puVar1;

  local_14 = puVar1[1];

  local_10 = puVar1[2];

  FUN_00455920(param_1,param_2,param_3,param_4,&local_c,&local_18);

  return;

}

/* ===== grid_get_point @ 0x00455BD0 ===== */
void grid_get_point(int param_1,int param_2,float *param_3)



{

  *param_3 = (float)param_1 * *(float *)(DAT_006330e4 + 0x1c0) + *(float *)(DAT_006330e4 + 0x1c8);

  param_3[1] = (float)param_2 * *(float *)(DAT_006330e4 + 0x1c0) + *(float *)(DAT_006330e4 + 0x1cc);

  param_3[2] = *(float *)(param_1 * 0x10 + *(int *)(*(int *)(DAT_006330e4 + 0x10) + param_2 * 4));

  return;

}

/* ===== object_create_child @ 0x00455C80 ===== */
/* PS2 candidate: object_create_child (conf 0.467) */



void object_create_child(int param_1,int param_2,int param_3)



{

  undefined4 *puVar1;

  int iVar2;

  int iVar3;

  int local_4;

  

  local_4 = -1;

  for (puVar1 = DAT_00632d80; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {

    iVar3 = puVar1[3];

    if ((((*(uint *)(iVar3 + 0xd8) & 0x8000) == 0) && (*(int *)(iVar3 + 0x210) == param_1)) &&

       (*(int *)(iVar3 + 0x218) == param_2)) {

      if (iVar3 != 0) {

        local_4 = *(int *)(iVar3 + 4);

        puVar1 = DAT_00632d80;

        if (local_4 == param_3) {

          return;

        }

        goto joined_r0x00455cee;

      }

      break;

    }

  }

LAB_00455d20:

  if (0 < param_3) {

    iVar3 = object_allocate_type_end(param_3,0x20);

    *(undefined4 *)(iVar3 + 0x18c) = *(undefined4 *)(param_1 + 0x18c);

    *(undefined4 *)(iVar3 + 0xa0) = *(undefined4 *)(param_1 + 0xa0);

    *(undefined4 *)(iVar3 + 0xa4) = *(undefined4 *)(param_1 + 0xa4);

    *(undefined4 *)(iVar3 + 0xa8) = *(undefined4 *)(param_1 + 0xa8);

    *(undefined4 *)(iVar3 + 200) = *(undefined4 *)(param_1 + 200);

    *(undefined4 *)(iVar3 + 0x214) = 0;

    *(int *)(iVar3 + 0x218) = param_2;

    *(int *)(iVar3 + 0x210) = param_1;

    *(uint *)(iVar3 + 0xd8) = *(uint *)(iVar3 + 0xd8) | 0x20400000;

    iVar3 = ObjIsMecc(param_1);

    if (iVar3 != 0) {

      iVar3 = *(int *)(param_1 + 0x100);

      iVar2 = *(int *)(iVar3 + 0x19c);

      if (iVar2 != 0) {

        fx_delete(iVar2);

        *(undefined4 *)(iVar3 + 0x19c) = 0;

      }

    }

    if (param_3 == 0x382) {

      iVar3 = player_find_weapon_obj_type__FP6OBJECTii(param_1,10,0x382);

      if (iVar3 != 0) {

        *(undefined4 *)(iVar3 + 0x184) = 0x3f800000;

        return;

      }

    }

    else if (local_4 == 0x382) {

      iVar3 = player_find_weapon_obj_type__FP6OBJECTii(param_1,10,0x382);

      if (iVar3 != 0) {

        *(undefined4 *)(iVar3 + 0x184) = 0;

      }

      FUN_004804d0(param_1);

    }

  }

  return;

joined_r0x00455cee:

  if (puVar1 == (undefined4 *)0x0) goto LAB_00455d20;

  iVar3 = puVar1[3];

  if ((((*(uint *)(iVar3 + 0xd8) & 0x8000) == 0) && (*(int *)(iVar3 + 0x210) == param_1)) &&

     (*(int *)(iVar3 + 0x218) == param_2)) {

    if (iVar3 != 0) {

      object_destroy(iVar3);

    }

    goto LAB_00455d20;

  }

  puVar1 = (undefined4 *)*puVar1;

  goto joined_r0x00455cee;

}

/* ===== FUN_00455e20 @ 0x00455E20 ===== */
void FUN_00455e20(int param_1)



{

  int iVar1;

  undefined4 *puVar2;

  

  puVar2 = DAT_00632d80;

  while( true ) {

    if (puVar2 == (undefined4 *)0x0) {

      return;

    }

    iVar1 = puVar2[3];

    if ((((*(uint *)(iVar1 + 0xd8) & 0x8000) == 0) && (*(int *)(iVar1 + 0x210) == param_1)) &&

       (*(int *)(iVar1 + 0x218) == 0)) break;

    puVar2 = (undefined4 *)*puVar2;

  }

  if (iVar1 == 0) {

    return;

  }

  object_destroy();

  return;

}

/* ===== FUN_00455e70 @ 0x00455E70 ===== */
void FUN_00455e70(int param_1)



{

  int iVar1;

  undefined4 *puVar2;

  

  puVar2 = DAT_00632d80;

  while( true ) {

    if (puVar2 == (undefined4 *)0x0) {

      return;

    }

    iVar1 = puVar2[3];

    if (((-1 < (char)((uint)*(undefined4 *)(iVar1 + 0xd8) >> 8)) &&

        (*(int *)(iVar1 + 0x210) == param_1)) && (*(int *)(iVar1 + 0x218) == 1)) break;

    puVar2 = (undefined4 *)*puVar2;

  }

  if (iVar1 == 0) {

    return;

  }

  object_destroy();

  return;

}

/* ===== object_create_gun_2 @ 0x00455EC0 ===== */
/* PS2 candidate: object_create_gun (conf 0.825) */



void object_create_gun_2(int param_1,int param_2)



{

  param_2 = param_2 + -1;

  if (-1 < param_2) {

    param_2 = *(int *)(*(int *)(param_1 + 0x1dc) + param_2 * 4);

  }

  object_create_child(param_1,1,param_2);

  return;

}

/* ===== object_create_gun @ 0x00455EF0 ===== */
/* PS2 candidate: object_create_gun_2 (conf 0.825) */



void object_create_gun(int param_1,int param_2)



{

  param_2 = param_2 + -1;

  if (-1 < param_2) {

    param_2 = *(int *)(*(int *)(param_1 + 0x1dc) + param_2 * 4);

  }

  object_create_child(param_1,0,param_2);

  return;

}

/* ===== FUN_00455f20 @ 0x00455F20 ===== */
int FUN_00455f20(int param_1)



{

  int iVar1;

  int iVar2;

  int *piVar3;

  

  if (DAT_00632d80 != (int *)0x0) {

    iVar2 = 1;

    piVar3 = DAT_00632d80;

    while (((iVar1 = piVar3[3], (*(uint *)(iVar1 + 0xd8) & 0x8000) != 0 ||

            (*(int *)(iVar1 + 0x210) != param_1)) || (*(int *)(iVar1 + 0x218) != 1))) {

      piVar3 = (int *)*piVar3;

      if (piVar3 == (int *)0x0) {

        return 0;

      }

    }

    if ((iVar1 != 0) && (0 < *(int *)(param_1 + 0x1d8))) {

      piVar3 = *(int **)(param_1 + 0x1dc);

      do {

        if (*piVar3 == *(int *)(iVar1 + 4)) {

          return iVar2;

        }

        iVar2 = iVar2 + 1;

        piVar3 = piVar3 + 1;

      } while (iVar2 <= *(int *)(param_1 + 0x1d8));

    }

  }

  return 0;

}

/* ===== FUN_00455fa0 @ 0x00455FA0 ===== */
int FUN_00455fa0(int param_1)



{

  int iVar1;

  int *piVar2;

  int iVar3;

  

  piVar2 = DAT_00632d80;

  if (DAT_00632d80 != (int *)0x0) {

    while (((iVar1 = piVar2[3], (*(uint *)(iVar1 + 0xd8) & 0x8000) != 0 ||

            (*(int *)(iVar1 + 0x210) != param_1)) || (*(int *)(iVar1 + 0x218) != 0))) {

      piVar2 = (int *)*piVar2;

      if (piVar2 == (int *)0x0) {

        return 0;

      }

    }

    if (iVar1 != 0) {

      iVar3 = 1;

      if (0 < *(int *)(param_1 + 0x1d8)) {

        piVar2 = *(int **)(param_1 + 0x1dc);

        do {

          if (*piVar2 == *(int *)(iVar1 + 4)) {

            return iVar3;

          }

          iVar3 = iVar3 + 1;

          piVar2 = piVar2 + 1;

        } while (iVar3 <= *(int *)(param_1 + 0x1d8));

      }

    }

  }

  return 0;

}

/* ===== gun_find_left @ 0x00456010 ===== */
/* PS2 candidate: gun_find_left (conf 0.482) */



int gun_find_left(int param_1)



{

  int iVar1;

  undefined4 *puVar2;

  

  puVar2 = DAT_00632d80;

  while( true ) {

    if (puVar2 == (undefined4 *)0x0) {

      return 0;

    }

    iVar1 = puVar2[3];

    if ((((*(uint *)(iVar1 + 0xd8) & 0x8000) == 0) && (*(int *)(iVar1 + 0x210) == param_1)) &&

       (*(int *)(iVar1 + 0x218) == 0)) break;

    puVar2 = (undefined4 *)*puVar2;

  }

  return iVar1;

}

/* ===== gun_find_right @ 0x00456050 ===== */
/* PS2 candidate: gun_find_right (conf 0.43) */



int gun_find_right(int param_1)



{

  int iVar1;

  undefined4 *puVar2;

  

  puVar2 = DAT_00632d80;

  while( true ) {

    if (puVar2 == (undefined4 *)0x0) {

      return 0;

    }

    iVar1 = puVar2[3];

    if (((-1 < (char)((uint)*(undefined4 *)(iVar1 + 0xd8) >> 8)) &&

        (*(int *)(iVar1 + 0x210) == param_1)) && (*(int *)(iVar1 + 0x218) == 1)) break;

    puVar2 = (undefined4 *)*puVar2;

  }

  return iVar1;

}

/* ===== FUN_00456090 @ 0x00456090 ===== */
undefined4 FUN_00456090(int param_1)



{

  int iVar1;

  undefined4 *puVar2;

  

  puVar2 = DAT_00632d80;

  do {

    if (puVar2 == (undefined4 *)0x0) {

      return 0;

    }

    iVar1 = puVar2[3];

    if ((-1 < (char)((uint)*(undefined4 *)(iVar1 + 0xd8) >> 8)) &&

       (*(int *)(iVar1 + 0x210) == param_1)) {

      if (*(int *)(iVar1 + 0x218) == 0) {

        return 2;

      }

      if (*(int *)(iVar1 + 0x218) == 1) {

        iVar1 = *(int *)(iVar1 + 4);

        if ((iVar1 == 0x16) || (iVar1 == 0x313)) {

          return 1;

        }

        if (iVar1 == 0x311) {

          return 3;

        }

      }

    }

    puVar2 = (undefined4 *)*puVar2;

  } while( true );

}

/* ===== herdgen_get_next_marker @ 0x00456110 ===== */
void herdgen_get_next_marker(int param_1,int *param_2)



{

  int iVar1;

  int iVar2;

  bool bVar3;

  

  iVar2 = *param_2;

  iVar1 = *(int *)(param_1 + 0x100);

  bVar3 = iVar2 != *(int *)(iVar1 + 0x2c);

  do {

    *param_2 = iVar2 + 1;

    if (*(int *)(iVar1 + 0x1c) <= iVar2 + 1) {

      *param_2 = 0;

    }

    iVar2 = *param_2;

  } while (*(int *)(*(int *)(iVar1 + 0x30) + iVar2 * 4) == 0);

  if (bVar3) {

    *(int *)(iVar1 + 0x2c) = iVar2;

  }

  iVar2 = *(int *)(*(int *)(iVar1 + 0x30) + *(int *)(iVar1 + 0x2c) * 4);

  *(undefined4 *)(param_1 + 0xa0) = *(undefined4 *)(iVar2 + 0xa0);

  *(undefined4 *)(param_1 + 0xa4) = *(undefined4 *)(iVar2 + 0xa4);

  *(undefined4 *)(param_1 + 0xa8) = *(undefined4 *)(iVar2 + 0xa8);

  return;

}

/* ===== herd_create_one @ 0x00456470 ===== */
/* PS2 candidate: herd_create_one (conf 0.486) */



int herd_create_one(int param_1,undefined4 param_2,int param_3)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  float10 fVar5;

  undefined4 local_10;

  undefined2 local_c;

  undefined2 local_a;

  undefined2 local_8;

  undefined2 local_6;

  undefined4 local_4;

  

  iVar4 = *(int *)(param_1 + 0x100);

  iVar2 = object_allocate_type(*(undefined4 *)(iVar4 + 4),0x80000000);

  *(int *)(iVar2 + 0x274) = param_1;

  object_set_location_p3d(iVar2,param_2);

  *(undefined4 *)(iVar2 + 0x15c) = *(undefined4 *)(iVar2 + 0xa0);

  *(undefined4 *)(iVar2 + 0x160) = *(undefined4 *)(iVar2 + 0xa4);

  *(undefined4 *)(iVar2 + 0x164) = *(undefined4 *)(iVar2 + 0xa8);

  fVar5 = (float10)rndfloatrange(0x41200000,0x41f00000);

  *(float *)(iVar2 + 0xec) = (float)fVar5;

  *(undefined4 *)(iVar2 + 0xe8) = *(undefined4 *)(param_1 + 0xe8);

  if (param_3 != 0) {

    *(int *)(iVar2 + 0x188) = param_3;

  }

  if (*(int *)(iVar4 + 4) == 8) {

    iVar1 = *(int *)(iVar2 + 0x100);

    if (*(int *)(iVar2 + 0xe8) == 1) {

      iVar3 = crt_rand_scaled(100);

      if (iVar3 < 0x21) {

        *(undefined4 *)(iVar2 + 0x1c0) = *(undefined4 *)(DAT_00632ed8 + 3000);

        *(undefined4 *)(iVar1 + 0x4c) = 0x3e4ccccd;

        *(undefined4 *)(iVar1 + 0x50) = *(undefined4 *)(iVar1 + 0x4c);

        *(undefined4 *)(iVar1 + 0x54) = 0x497423f0;

      }

      else if (iVar3 < 0x42) {

        *(undefined4 *)(iVar2 + 0x1c0) = *(undefined4 *)(DAT_00632ed8 + 0xbbc);

        *(undefined4 *)(iVar1 + 0x4c) = 0x3f000000;

        *(undefined4 *)(iVar1 + 0x50) = *(undefined4 *)(iVar1 + 0x4c);

        *(undefined4 *)(iVar1 + 0x54) = 0x497423f0;

      }

      else {

        *(undefined4 *)(iVar2 + 0x1c0) = *(undefined4 *)(DAT_00632ed8 + 0xbc0);

        *(undefined4 *)(iVar1 + 0x4c) = 0x3f800000;

        *(undefined4 *)(iVar1 + 0x50) = *(undefined4 *)(iVar1 + 0x4c);

        *(undefined4 *)(iVar1 + 0x54) = 0x497423f0;

      }

    }

    else {

      *(undefined4 *)(iVar2 + 0x1c0) = *(undefined4 *)(DAT_00632ed8 + 3000);

      *(undefined4 *)(iVar1 + 0x50) = 0x3e4ccccd;

      *(undefined4 *)(iVar1 + 0x4c) = 0x3e4ccccd;

      fVar5 = (float10)rndfloatrange(0x41200000,0x41f00000);

      *(float *)(iVar1 + 0x54) = (float)fVar5;

    }

    *(undefined4 *)(iVar1 + 0xa4) = *(undefined4 *)(iVar4 + 0x28);

    iVar4 = reaper_0052e4a0(param_1);

    if (iVar4 != 0) {

      local_10 = *(undefined4 *)(*(int *)(iVar2 + 0x100) + 0x4c);

      local_c = __ftol();

      local_a = __ftol();

      local_8 = __ftol();

      local_6 = __ftol();

      local_4 = *(undefined4 *)(iVar2 + 0x188);

      reaper_00530bd0(param_1,1,3,0,1,&local_10);

    }

  }

  return iVar2;

}

/* ===== reaper_spell_small @ 0x00456900 ===== */
void reaper_spell_small(undefined4 param_1,int param_2,undefined4 param_3,int param_4)



{

  uint uVar1;

  undefined2 local_18;

  undefined2 local_16;

  undefined2 local_14;

  undefined2 local_12;

  undefined2 local_10;

  undefined2 local_e;

  undefined2 local_c;

  undefined4 local_a;

  uint local_6;

  

  local_18 = __ftol();

  local_16 = __ftol();

  local_14 = __ftol();

  local_12 = __ftol();

  local_10 = __ftol();

  local_e = __ftol();

  local_c = __ftol();

  local_a = *(undefined4 *)(param_2 + 0x188);

  uVar1 = __ftol();

  local_6 = ((uVar1 | *(int *)(param_2 + 0xe0) << 8) << 8 | *(uint *)(param_2 + 0xe4)) << 8 |

            *(int *)(param_2 + 4) - 0x45dU;

  if (param_4 == 2) {

    local_6 = local_6 | 0x40000000;

  }

  else if (param_4 == 1) {

    local_6 = local_6 | 0x80000000;

  }

  reaper_00530bd0(param_1,0,0,0x16,2,&local_18);

  return;

}

/* ===== hurt_pusher @ 0x00456A10 ===== */
/* PS2 candidate: hurt_pusher (conf 0.419) */



void hurt_pusher(int param_1,float param_2,float param_3,int param_4,int param_5,float *param_6)



{

  int iVar1;

  float *pfVar2;

  float local_24;

  float local_20;

  float local_1c;

  float local_18;

  float local_14;

  float local_10;

  float local_c [3];

  

  local_24 = 0.0;

  local_20 = 0.0;

  local_1c = 0.0;

  if ((param_1 < 0x31) || (0x44 < param_1)) {

    iVar1 = param_4;

    if (param_5 != 0) {

      iVar1 = param_5;

    }

    local_24 = *(float *)(iVar1 + 0xa0) - *(float *)(iVar1 + 0xac);

    local_20 = *(float *)(iVar1 + 0xa4) - *(float *)(iVar1 + 0xb0);

    local_1c = *(float *)(iVar1 + 0xa8) - *(float *)(iVar1 + 0xb4);

  }

  else if ((param_6 != (float *)0x0) ||

          ((param_5 != 0 && (param_6 = (float *)(param_5 + 0xa0), param_6 != (float *)0x0)))) {

    pfVar2 = (float *)(param_4 + 0xa0);

    if ((*(int *)(param_4 + 0x10) != 0xfe) &&

       (iVar1 = *(int *)(*(int *)(param_4 + 8) + 8 + *(int *)(param_4 + 0x10) * 4), iVar1 != 0)) {

      local_18 = (*(float *)(iVar1 + 0x18) + *(float *)(iVar1 + 0xc)) * 0.5;

      local_14 = (*(float *)(iVar1 + 0x1c) + *(float *)(iVar1 + 0x10)) * 0.5;

      local_10 = (*(float *)(iVar1 + 0x20) + *(float *)(iVar1 + 0x14)) * 0.5;

      xformobj_p3d_world(param_4,&local_18,local_c);

      pfVar2 = local_c;

    }

    local_24 = *pfVar2 - *param_6;

    local_20 = pfVar2[1] - param_6[1];

    local_1c = pfVar2[2] - param_6[2];

  }

  if (0.001 < local_24 * local_24 + local_20 * local_20 + local_1c * local_1c) {

    normalize__FPfN20(&local_24,&local_20,&local_1c);

    if (100.0 < param_2) {

      param_2 = 100.0;

    }

    if (200.0 < param_3) {

      param_3 = 200.0;

    }

    *(float *)(param_4 + 0x128) = local_24 * param_2 + *(float *)(param_4 + 0x128);

    *(float *)(param_4 + 300) = local_20 * param_2 + *(float *)(param_4 + 300);

    *(float *)(param_4 + 0x130) = local_1c * param_3 + *(float *)(param_4 + 0x130);

  }

  return;

}

/* ===== FUN_00456d00 @ 0x00456D00 ===== */
/* PS2 candidate: playerobj_lookud (conf 0.412) */



void FUN_00456d00(undefined4 param_1,undefined4 param_2,undefined4 param_3,float param_4,

                 undefined4 param_5,undefined4 param_6)



{

  float10 fVar1;

  

  fVar1 = (float10)FUN_00518b70(param_1,0);

  obj_damage_apply(param_3,(float)(fVar1 * (float10)param_4),param_1,param_2,param_5,param_6);

  return;

}

/* ===== vimp_close_damage @ 0x00456D40 ===== */
void vimp_close_damage(undefined4 param_1,float param_2,int param_3,float param_4,float param_5,

                      float param_6,float param_7,float param_8,float param_9,int param_10)



{

  int iVar1;

  undefined4 *puVar2;

  undefined4 uVar3;

  undefined4 uVar4;

  int iVar5;

  float10 fVar6;

  

  uVar4 = param_4;

  uVar3 = param_2;

  puVar2 = DAT_00632d6c;

  if (param_8 != 0.0) {

    for (; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {

      iVar1 = puVar2[3];

      if ((*(int *)(iVar1 + 0x18c) != param_10) || (DAT_0063318c != 0)) {

        iVar5 = FUN_004a6220(iVar1);

        if ((iVar5 == 0) &&

           (((iVar5 = meccbasepit_bldg_from_object(iVar1), iVar5 == 0 &&

             (iVar5 = FUN_004a6300(iVar1), iVar5 == 0)) &&

            (iVar5 = reaperbase_bldg_from_object(iVar1), iVar5 == 0)))) {

          if (((*(uint *)(iVar1 + 0xd8) & 0x4000c000) == 0) &&

             (*(float *)(iVar1 + 0x278) < *(float *)(iVar1 + 0x1c0))) {

LAB_00456e0a:

            if (param_3 == iVar1) {

              return;

            }

            fVar6 = (float10)distance3d__FP3P3DT0(iVar1 + 0xa0,uVar4);

            param_4 = (float)(fVar6 - (float10)*(float *)(iVar1 + 0x154) * (float10)0.5);

            if (param_4 < 0.0) {

              param_4 = 0.0;

            }

            if ((*(int *)(iVar1 + 4) == 8) && (param_4 < *(float *)(DAT_00632ed8 + 0x9c0))) {

              vimp_handle_close_area_damage(iVar1,uVar3);

            }

            if (param_4 <= param_6) {

              if (param_5 <= param_4) {

                param_2 = param_4 * param_8 + param_9;

              }

              else {

                param_2 = param_7;

              }

              obj_damage_apply(param_1,param_2,iVar1,uVar3,uVar4,0);

            }

          }

        }

        else if ((~*(uint *)(iVar1 + 0x1c8) >> 0x11 & 1) == 0 &&

                 (*(uint *)(iVar1 + 0xd8) & 0x4000c000) == 0) goto LAB_00456e0a;

      }

    }

  }

  return;

}

/* ===== FUN_00456ee0 @ 0x00456EE0 ===== */
void FUN_00456ee0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,

                 float param_5,float param_6,float param_7,float param_8,undefined4 param_9)



{

  float fVar1;

  

  fVar1 = (param_7 - param_8) / (param_5 - param_6);

  vimp_close_damage(param_1,param_2,param_3,param_4,param_5,param_6,param_7,fVar1,

                    param_7 - fVar1 * param_5,param_9);

  return;

}

/* ===== obj_damage_apply @ 0x00456F80 ===== */
/* PS2 candidate: hurt_object (conf 0.457) */



void obj_damage_apply(int param_1,undefined4 param_2,int param_3,int param_4,undefined4 param_5,

                     undefined4 param_6)



{

  uint *puVar1;

  int iVar2;

  

  if (DAT_00632c00 != 0) {

    return;

  }

  if (DAT_00632c04 != 0) {

    return;

  }

  if ((((*(uint *)(param_3 + 0x1cc) & 0x4000000) != 0) && (param_1 != 4)) && (param_1 != 6)) {

    return;

  }

  if (((param_1 < 0x31) || (0x44 < param_1)) && (*(int *)(param_3 + 0x210) != 0)) {

    puVar1 = (uint *)(param_3 + 0x1c8);

    do {

      if ((*puVar1 & 0x4000000) == 0) break;

      if (param_1 == 0xf) {

        return;

      }

      param_3 = *(int *)(param_3 + 0x210);

      param_1 = 0xc;

    } while (*(int *)(param_3 + 0x210) != 0);

  }

  if ((*(uint *)(param_3 + 0x1c8) & 0x4000000) == 0) {

    iVar2 = dialog_level_is_base();

    if (iVar2 != 0) {

      comm_chat_send_3(param_1,param_2,param_3,param_4,param_5,param_6);

    }

    objspec_has_shot_function(param_1,param_2,param_3,param_4,param_5,param_6);

    if (*(float *)(param_3 + 0x1c0) <= *(float *)(param_3 + 0x278)) {

      if (param_4 == 0) goto LAB_004570b5;

      if (((*(int *)(param_4 + 0x274) != 0) &&

          (iVar2 = ObjIsMecc(*(int *)(param_4 + 0x274)), iVar2 != 0)) &&

         (*(int *)(*(int *)(param_4 + 0x274) + 0x174) != 0)) {

        puVar1 = (uint *)(*(int *)(param_4 + 0x274) + 0xe0);

        *puVar1 = *puVar1 | 0x80000;

      }

    }

    if (((param_4 != 0) && (param_1 == 0)) && (*(int *)(param_4 + 0x1e0) == 6)) {

      object_destroy(param_4);

    }

  }

LAB_004570b5:

  if (((*(uint *)(param_3 + 0xd8) & 0x400) != 0) &&

     ((*(float *)(param_3 + 0x1c0) <= *(float *)(param_3 + 0x278) ||

      ((char)(*(uint *)(param_3 + 0xd8) >> 8) < '\0')))) {

    *(int *)(DAT_006330e4 + 0x4a64) = *(int *)(DAT_006330e4 + 0x4a64) + *(int *)(param_3 + 0x1c4);

    *(undefined4 *)(param_3 + 0x1c4) = 0;

  }

  FUN_00494030(param_3);

  return;

}

/* ===== FUN_00457100 @ 0x00457100 ===== */
void FUN_00457100(int param_1,undefined4 param_2,int param_3,int param_4,undefined4 param_5,

                 undefined4 param_6)



{

  uint *puVar1;

  int iVar2;

  

  objspec_has_shot_function(param_1,param_2,param_3,param_4,param_5,param_6);

  if ((param_3 != 0) && (*(float *)(param_3 + 0x1c0) <= *(float *)(param_3 + 0x278))) {

    if (param_4 == 0) {

      return;

    }

    if (((*(int *)(param_4 + 0x274) != 0) &&

        (iVar2 = ObjIsMecc(*(int *)(param_4 + 0x274)), iVar2 != 0)) &&

       (*(int *)(*(int *)(param_4 + 0x274) + 0x174) != 0)) {

      puVar1 = (uint *)(*(int *)(param_4 + 0x274) + 0xe0);

      *puVar1 = *puVar1 | 0x80000;

    }

  }

  if (((param_4 != 0) && (param_1 == 0)) && (*(int *)(param_4 + 0x1e0) == 6)) {

    object_destroy(param_4);

  }

  return;

}

/* ===== FUN_004571a0 @ 0x004571A0 ===== */
int FUN_004571a0(int param_1,int *param_2,int param_3)



{

  undefined4 uVar1;

  int iVar2;

  undefined4 *puVar3;

  undefined4 local_a4;

  undefined4 local_a0;

  undefined4 local_9c;

  undefined4 local_98;

  undefined4 local_94 [7];

  int local_78;

  undefined4 *local_74;

  undefined1 local_70 [112];

  

  if (param_3 != 0) {

    local_a4 = 0;

    local_a0 = 0;

    local_9c = 0;

    puVar3 = local_94;

    for (iVar2 = 9; iVar2 != 0; iVar2 = iVar2 + -1) {

      *puVar3 = 0;

      puVar3 = puVar3 + 1;

    }

    local_98 = 0;

    local_74 = &local_a4;

    xformobj_world_local(param_1,param_3,local_94);

    uVar1 = FUN_00403a70(param_1,0,local_70);

    nam_lookup_full(local_70,uVar1,local_94,1,*(undefined4 *)(param_1 + 0xc));

    if (local_78 != 0) {

      iVar2 = *param_2;

      while( true ) {

        if (iVar2 < 0) {

          return -1;

        }

        iVar2 = FUN_00545650(param_2[1],local_78);

        if (iVar2 == 0) break;

        iVar2 = param_2[2];

        param_2 = param_2 + 2;

      }

      return *param_2;

    }

  }

  return 0;

}

/* ===== comm_options_defaults @ 0x00457270 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void comm_options_defaults(void)



{

  keymap_0051a100(s_PlayerTeam_0055a040,&DAT_00632f14);

  if (DAT_0063316c == 0) {

    keymap_0051a100(s_GameTeam_0055a034,&DAT_00632f10);

  }

  if (DAT_00633168 == 0) {

    keymap_0051a100(s_GameBaseLevel_0055a024,&DAT_00632f0c);

  }

  if (DAT_0063315c == 0) {

    FUN_0051a060(s_SessionName_0055a018,&DAT_00632f48,0x20);

  }

  if (DAT_00633174 == 0) {

    keymap_0051a100(s_GameType_0055a00c,&DAT_00632f18);

  }

  keymap_0051a100(s_AllowJoiners_00559ffc,&DAT_00632f1c);

  keymap_0051a100(s_DamageTeammates_00559fec,&DAT_00632f20);

  keymap_0051a100(s_LockTeams_00559fe0,&DAT_00632f38);

  keymap_0051a100(s_PointsPerKill_00559fd0,&DAT_00632f24);

  keymap_0051a100(s_PointsPerCapture_00559fbc,&DAT_00632f28);

  keymap_0051a100(s_CapturePreventTime_00559fa8,&DAT_00632f2c);

  DAT_00632f30 = (float)DAT_00632f2c * 60.0;

  if (DAT_00633170 == 0) {

    keymap_0051a100(s_MaxPlayers_00559f9c,&DAT_00632f34);

  }

  keymap_0051a100(s_SmartieDifficulty_00559f88,&DAT_00632f3c);

  keymap_0051a100(s_VimpMeatDifficulty_00559f74,&DAT_00632f40);

  keymap_0051a100(s_TimeLimit_00559f68,&DAT_00632fcc);

  DAT_00633010 = (float)DAT_00632fcc * 60.0;

  DAT_00632fc0 = (uint)(0 < DAT_00632fcc);

  keymap_0051a100(s_PlayerScoreLimit_00559f54,&DAT_00632fdc);

  DAT_00632fd0 = (uint)(0 < DAT_00632fdc);

  keymap_0051a100(s_TeamScoreLimit_00559f44,&DAT_00632fec);

  _DAT_00632fe0 = (uint)(0 < DAT_00632fec);

  keymap_0051a100(s__BaseComplete_00559f33 + 1,&DAT_00632ff0);

  FUN_00452a30(1,0);

  if (DAT_00633238 != 0) {

    comm_game_setup_big();

    return;

  }

  return;

}

/* ===== level_config_load @ 0x00457440 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void level_config_load(void)



{

  if (DAT_00633180 == 0) {

    _DAT_00633030 = DAT_0055a074;

    _DAT_00633034 = DAT_0055a078;

  }

  if (DAT_00633158 == 0) {

    FUN_0051a030(s_WorldName_0055a068,&DAT_00633070,0x20);

    FUN_0051a030(s_MPWorldName_0055a05c,&DAT_00632ee8,0x20);

  }

  DAT_00632d20 = session_table_lookup(&DAT_00633070);

  DAT_00632ee4 = session_table_lookup(&DAT_00632ee8);

  mission_0051a0c0(s_FarClipIndex_0055a04c,&DAT_006331bc);

  FUN_00535f40();

  comm_options_defaults();

  game_options_verify();

  return;

}

/* ===== defaults_reset_menu @ 0x004574D0 ===== */
void defaults_reset_menu(void)



{

  DAT_00632f08 = 0;

  filecopy_dirs();

  if (DAT_00633154 == 0) {

    FUN_0051a1c0(s_DefPlayer_0055a07c,&DAT_0063304c,0x20);

    if ((((DAT_00633154 == 0) && (DAT_0063317c == 0)) && (DAT_0063315c == 0)) &&

       (((DAT_00633160 == 0 && (DAT_00633248 == 0)) && (DAT_00633104 == 0)))) {

      mission_intro_load();

      return;

    }

  }

  player_defaults_load_all();

  DAT_00633154 = 0;

  return;

}

/* ===== menu_keymap_screen @ 0x00457550 ===== */
void menu_keymap_screen(void)



{

  if ((((DAT_0063315c == 0) && (DAT_00633160 == 0)) && (DAT_0063317c == 0)) && (DAT_00633248 == 0))

  {

    menu_mission_launch();

    return;

  }

  keymap_load();

  if (DAT_0063315c != 0) {

    mission_load_full(0xd);

    return;

  }

  if (DAT_00633160 != 0) {

    mission_load_full(0xc);

    return;

  }

  if (DAT_00633248 != 0) {

    mission_load_full(0xf);

    return;

  }

  mission_load_full(0xb);

  return;

}

/* ===== mission_load_full @ 0x004575D0 ===== */
void mission_load_full(int param_1)



{

  char cVar1;

  int iVar2;

  char *pcVar3;

  char *pcVar4;

  undefined4 uVar5;

  

  if (param_1 == 0xd) {

    if (DAT_00633238 == 0) {

      uVar5 = 0;

LAB_004575ee:

      FUN_00452a30(1,uVar5);

    }

  }

  else if (param_1 == 0xc) {

    uVar5 = 1;

    goto LAB_004575ee;

  }

  if (((DAT_0063315c == 0) && (DAT_00633160 == 0)) && (DAT_0063317c == 0)) {

    if (param_1 == 0xb) {

      iVar2 = FUN_0051c540();

      if (iVar2 != 0) {

        DAT_00632d20 = 0;

        iVar2 = world_get_pointer(0);

        pcVar3 = *(char **)(iVar2 + 4);

        pcVar4 = &DAT_00633070;

        do {

          cVar1 = *pcVar3;

          pcVar3 = pcVar3 + 1;

          *pcVar4 = cVar1;

          pcVar4 = pcVar4 + 1;

        } while (cVar1 != '\0');

        AudioSetSpeakerConfig__F14SPEAKER_SYSTEM_4(DAT_00632d20);

        mission_texture_audio();

        DAT_00632f08 = 0;

      }

    }

    else {

      if (param_1 != 0xf) {

        if (param_1 == 0xe) {

          FUN_00489D40();

          return;

        }

        DAT_00632f44 = (uint)(param_1 == 0xd);

        goto LAB_004576b1;

      }

      iVar2 = FUN_0051c540();

      if (iVar2 != 0) {

        mission_load_world2();

        DAT_00632f08 = 0;

        return;

      }

    }

    return;

  }

LAB_004576b1:

  DAT_00632f08 = 1;

  GiantsInitNewWorld();

  return;

}

/* ===== AudioSetSpeakerConfig__F14SPEAKER_SYSTEM_4 @ 0x004576D0 ===== */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */



void AudioSetSpeakerConfig__F14SPEAKER_SYSTEM_4(undefined4 p0)



{

  DAT_0059d9f0 = p0;

  return;

}

/* ===== mission_texture_audio @ 0x004576E0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void mission_texture_audio(void)



{

  int iVar1;

  int iVar2;

  undefined *puVar3;

  

  main_texture_00508860();

  DAT_006330dc = 1;

  DAT_0059da14 = 0;

  DAT_0059d9f8 = 0;

  _DAT_0059da10 = 0x3f800000;

  _DAT_0059da0c = 0x3f800000;

  main_texture_00508eb0(DAT_0059d9fc,DAT_0059da00,DAT_0059da04,DAT_0059da08);

  DAT_0059d9fc = 0;

  DAT_0059da00 = 0;

  DAT_0059da04 = 0;

  DAT_0059da08 = 0;

  iVar1 = world_get_pointer(DAT_0059d9f0);

  if ((iVar1 == 0) ||

     (((iVar2 = crt_lock_simple((int)**(char **)(iVar1 + 4)), puVar3 = PTR_s_kabuto_loading_0055a0b0

       , iVar2 != 0x4b &&

       (iVar2 = crt_lock_simple((int)**(char **)(iVar1 + 4)), puVar3 = PTR_s_reaper_loading_0055a0ac

       , iVar2 != 0x52)) &&

      (iVar1 = crt_lock_simple((int)**(char **)(iVar1 + 4)), puVar3 = PTR_s_giants_loading_0055a0b4,

      iVar1 != 0x49)))) {

    puVar3 = PTR_s_mecc_loading_0055a0a8;

  }

  main_texture_005088d0(puVar3,&DAT_0059d9fc,&DAT_0059da00,&DAT_0059da04,&DAT_0059da08);

  Audio3DTestToneUpdate__Fv();

  dlog_push_level(&LAB_004577f0,&LAB_00457970);

  return;

}

/* ===== FUN_00457a70 @ 0x00457A70 ===== */
bool FUN_00457a70(int param_1,int param_2)



{

  int iVar1;

  int iVar2;

  

  iVar1 = *(int *)(param_1 + 0x1e0);

  if (iVar1 == 2) {

    iVar2 = *(int *)(*(int *)(param_1 + 0x100) + 0x17c);

  }

  else {

    iVar2 = 0;

  }

  if (param_2 == iVar2) {

    return true;

  }

  if (iVar1 == 2) {

    iVar2 = *(int *)(*(int *)(param_1 + 0x100) + 0x180);

  }

  else {

    iVar2 = 0;

  }

  if (param_2 == iVar2) {

    return true;

  }

  if (iVar1 == 2) {

    iVar2 = *(int *)(*(int *)(param_1 + 0x100) + 0x184);

  }

  else {

    iVar2 = 0;

  }

  if (param_2 == iVar2) {

    return true;

  }

  if (iVar1 == 2) {

    return param_2 == *(int *)(*(int *)(param_1 + 0x100) + 0x188);

  }

  return param_2 == 0;

}

/* ===== player_needs_ammo__FP6OBJECTi @ 0x00457BD0 ===== */
/* PS2 candidate: player_needs_ammo__FP6OBJECTi (conf 0.412) */



bool player_needs_ammo__FP6OBJECTi(int param_1,undefined4 param_2)



{

  int iVar1;

  int iVar2;

  

  iVar1 = ObjIsMecc(param_1);

  if ((iVar1 != 0) && (iVar1 = FUN_004a90d0(param_2), iVar1 == 4)) {

    iVar1 = *(int *)(param_1 + 0x100);

    switch(param_2) {

    case 0x25:

      iVar2 = IconDefMaxAmmo(param_2);

      return *(int *)(iVar1 + 0x148) < iVar2;

    case 0x26:

      iVar2 = IconDefMaxAmmo(param_2);

      if (*(float *)(iVar1 + 0x158) < (float)iVar2) {

        return true;

      }

      break;

    case 0x27:

      iVar2 = IconDefMaxAmmo(param_2);

      return *(int *)(iVar1 + 0x15c) < iVar2;

    case 0x28:

      iVar2 = IconDefMaxAmmo(param_2);

      return *(int *)(iVar1 + 0x160) < iVar2;

    case 0x29:

      iVar2 = IconDefMaxAmmo(param_2);

      return *(int *)(iVar1 + 0x164) < iVar2;

    case 0x2a:

      iVar2 = IconDefMaxAmmo(param_2);

      return *(int *)(iVar1 + 0x168) < iVar2;

    case 0x2b:

      iVar2 = IconDefMaxAmmo(param_2);

      return *(int *)(iVar1 + 0x16c) < iVar2;

    }

  }

  return false;

}

/* ===== FUN_00457d10 @ 0x00457D10 ===== */
undefined4 FUN_00457d10(int param_1)



{

  int iVar1;

  

  iVar1 = 0x180;

  while ((*(int *)(param_1 + 0x1e0) != 2 || (-1 < *(int *)(iVar1 + *(int *)(param_1 + 0x100))))) {

    iVar1 = iVar1 + 4;

    if (0x18b < iVar1) {

      return 0;

    }

  }

  return 1;

}

/* ===== FUN_00457d50 @ 0x00457D50 ===== */
int FUN_00457d50(int param_1)



{

  int iVar1;

  int iVar2;

  

  iVar1 = 1;

  iVar2 = 0x180;

  while ((*(int *)(param_1 + 0x1e0) != 2 || (-1 < *(int *)(iVar2 + *(int *)(param_1 + 0x100))))) {

    iVar2 = iVar2 + 4;

    iVar1 = iVar1 + 1;

    if (0x18b < iVar2) {

      return *(int *)(*(int *)(param_1 + 0x100) + 0x60);

    }

  }

  if (iVar1 == -1) {

    iVar1 = *(int *)(*(int *)(param_1 + 0x100) + 0x60);

  }

  return iVar1;

}

/* ===== reaper_lock_short_2 @ 0x00457F00 ===== */
void reaper_lock_short_2(undefined4 param_1,undefined1 param_2)



{

  undefined4 uVar1;

  int iVar2;

  

  uVar1 = param_1;

  iVar2 = reaper_0052e4a0(param_1);

  if (iVar2 != 0) {

    param_1 = CONCAT31(param_1._1_3_,param_2);

    reaper_00530bd0(uVar1,0,0,1,10,&param_1);

  }

  return;

}

/* ===== FUN_00457f40 @ 0x00457F40 ===== */
/* PS2 candidate: WeaponIdSet__FP6OBJECTii (conf 0.378) */



void FUN_00457f40(int param_1,int param_2,int param_3)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  

  iVar4 = param_3;

  iVar3 = param_2;

  iVar2 = param_1;

  if (*(int *)(param_1 + 0x1e0) == 2) {

    iVar1 = *(int *)(param_1 + 0x100);

    if ((*(int *)(iVar1 + 0x60) == param_2) && (*(int *)(iVar1 + 0x17c + param_2 * 4) != param_3)) {

      iVar5 = reaper_0052e4a0(param_1);

      if (iVar5 != 0) {

        param_1 = CONCAT31(param_1._1_3_,(char)iVar4);

        reaper_00530bd0(iVar2,0,0,1,10,&param_1);

      }

    }

    *(int *)(iVar1 + 0x17c + iVar3 * 4) = iVar4;

  }

  return;

}

/* ===== FUN_00457fb0 @ 0x00457FB0 ===== */
/* PS2 candidate: WeaponIdGetPresent__FP6OBJECT_2 (conf 0.713) */



undefined4 FUN_00457fb0(int param_1,int param_2)



{

  if (*(int *)(param_1 + 0x1e0) == 2) {

    return *(undefined4 *)(*(int *)(param_1 + 0x100) + 0x17c + param_2 * 4);

  }

  return 0;

}

/* ===== reaper_lock_short_3 @ 0x00457FE0 ===== */
void reaper_lock_short_3(int param_1,int param_2)



{

  int iVar1;

  undefined4 uVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  

  iVar4 = param_2;

  iVar3 = param_1;

  if (*(int *)(param_1 + 0x1e0) == 2) {

    iVar1 = *(int *)(param_1 + 0x100);

    if (param_2 != *(int *)(iVar1 + 0x60)) {

      uVar2 = *(undefined4 *)(iVar1 + 0x17c + param_2 * 4);

      iVar5 = reaper_0052e4a0(param_1);

      if (iVar5 != 0) {

        param_1 = CONCAT31(param_1._1_3_,(char)uVar2);

        reaper_00530bd0(iVar3,0,0,1,10,&param_1);

      }

    }

    *(int *)(iVar1 + 0x60) = iVar4;

  }

  return;

}

/* ===== WeaponIdCycleToNext__FP6OBJECTi @ 0x00458040 ===== */
/* PS2 candidate: WeaponIdCycleToNext__FP6OBJECTi (conf 0.452) */



int WeaponIdCycleToNext__FP6OBJECTi(int param_1,int param_2)



{

  uint uVar1;

  int iVar2;

  uint uVar3;

  uint uVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  

  if (*(int *)(param_1 + 0x1e0) != 2) {

    return 0;

  }

  iVar2 = *(int *)(param_1 + 0x100);

  if (param_2 == 0) {

    uVar4 = *(uint *)(iVar2 + 0x60);

    iVar7 = 1;

    uVar3 = uVar4 + 3;

    iVar5 = uVar4 * 4;

    while( true ) {

      uVar4 = uVar4 - 1;

      uVar1 = uVar4;

      iVar6 = iVar5 + -4;

      if ((int)uVar4 < 0) {

        iVar6 = iVar5 + 0xc;

        uVar1 = uVar3;

      }

      if (*(int *)(iVar6 + 0x17c + iVar2) != -1) break;

      iVar7 = iVar7 + 1;

      uVar3 = uVar3 - 1;

      iVar5 = iVar5 + -4;

      if (3 < iVar7) {

        return *(int *)(iVar2 + 0x17c + *(int *)(iVar2 + 0x60) * 4);

      }

    }

  }

  else {

    uVar3 = *(uint *)(iVar2 + 0x60);

    iVar5 = 1;

    while( true ) {

      uVar3 = uVar3 + 1;

      uVar1 = uVar3 & 0x80000003;

      if ((int)uVar1 < 0) {

        uVar1 = (uVar1 - 1 | 0xfffffffc) + 1;

      }

      if (*(int *)(iVar2 + 0x17c + uVar1 * 4) != -1) break;

      iVar5 = iVar5 + 1;

      if (3 < iVar5) {

        return *(int *)(iVar2 + 0x17c + *(int *)(iVar2 + 0x60) * 4);

      }

    }

  }

  iVar5 = *(int *)(iVar2 + 0x17c + uVar1 * 4);

  if (iVar5 != -1) {

    *(uint *)(iVar2 + 0x60) = uVar1;

    iVar2 = reaper_0052e4a0(param_1);

    if (iVar2 != 0) {

      param_2 = CONCAT31(param_2._1_3_,(char)iVar5);

      reaper_00530bd0(param_1,0,0,1,10,&param_2);

    }

    mecc_play_weapon_select_snd(param_1,iVar5);

    return iVar5;

  }

  return *(int *)(iVar2 + 0x17c + *(int *)(iVar2 + 0x60) * 4);

}

/* ===== WeaponIdGetPresent__FP6OBJECT @ 0x00458150 ===== */
/* PS2 candidate: WeaponIdGetCurrent__FP6OBJECT (conf 0.544) */



undefined4 WeaponIdGetPresent__FP6OBJECT(int param_1)



{

  if (*(int *)(param_1 + 0x1e0) == 2) {

    return *(undefined4 *)

            (*(int *)(param_1 + 0x100) + 0x17c + *(int *)(*(int *)(param_1 + 0x100) + 0x60) * 4);

  }

  return 0;

}

/* ===== WeaponIdSetCurrent__FP6OBJECTi @ 0x00458180 ===== */
/* PS2 candidate: WeaponIdSetCurrent__FP6OBJECTi (conf 0.49) */



void WeaponIdSetCurrent__FP6OBJECTi(int param_1,int param_2)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  

  iVar3 = param_2;

  iVar2 = param_1;

  if (*(int *)(param_1 + 0x1e0) == 2) {

    iVar1 = *(int *)(param_1 + 0x100);

    if (*(int *)(iVar1 + 0x17c + *(int *)(iVar1 + 0x60) * 4) != param_2) {

      iVar4 = reaper_0052e4a0(param_1);

      if (iVar4 != 0) {

        param_1 = CONCAT31(param_1._1_3_,(char)iVar3);

        reaper_00530bd0(iVar2,0,0,1,10,&param_1);

      }

    }

    *(int *)(iVar1 + 0x17c + *(int *)(iVar1 + 0x60) * 4) = iVar3;

  }

  return;

}

/* ===== WeaponIdGetPresent__FP6OBJECT @ 0x004581E0 ===== */
undefined4 WeaponIdGetPresent__FP6OBJECT(int param_1)



{

  if (*(int *)(param_1 + 0x1e0) == 2) {

    return *(undefined4 *)(*(int *)(param_1 + 0x100) + 0x5c);

  }

  return 0;

}

/* ===== WeaponIdCheck__FP6OBJECT @ 0x00458200 ===== */
/* PS2 candidate: WeaponIdCheck__FP6OBJECT (conf 0.744) */



bool WeaponIdCheck__FP6OBJECT(int param_1)



{

  int iVar1;

  

  if (*(int *)(param_1 + 0x1e0) == 2) {

    iVar1 = *(int *)(param_1 + 0x100);

    return *(int *)(iVar1 + 0x5c) == *(int *)(iVar1 + 0x17c + *(int *)(iVar1 + 0x60) * 4);

  }

  return true;

}

/* ===== FUN_00458230 @ 0x00458230 ===== */
/* PS2 candidate: WeaponIdSetPresent__FP6OBJECTi (conf 0.374) */



void FUN_00458230(int param_1)



{

  undefined4 uVar1;

  undefined4 uVar2;

  

  if (*(int *)(param_1 + 0x1e0) == 2) {

    uVar1 = *(undefined4 *)

             (*(int *)(param_1 + 0x100) + 0x17c + *(int *)(*(int *)(param_1 + 0x100) + 0x60) * 4);

    uVar2 = IconDefWieldType(uVar1,0);

    object_create_child(param_1,0,uVar2);

    uVar2 = IconDefWieldType(uVar1,1);

    object_create_child(param_1,1,uVar2);

    if (*(int *)(param_1 + 0x1e0) == 2) {

      *(undefined4 *)(*(int *)(param_1 + 0x100) + 0x5c) = uVar1;

      *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xfffe03ff;

    }

  }

  return;

}

/* ===== WeaponIdSetSlot__FP6OBJECTi @ 0x004582A0 ===== */
/* PS2 candidate: OtherInvIdSet__FP6OBJECTii (conf 0.42) */



void WeaponIdSetSlot__FP6OBJECTi(int param_1,int param_2,undefined4 param_3)



{

  if (*(int *)(param_1 + 0x1e0) == 2) {

    *(undefined4 *)(*(int *)(param_1 + 0x100) + 0x170 + param_2 * 4) = param_3;

  }

  return;

}

/* ===== FUN_004582d0 @ 0x004582D0 ===== */
/* PS2 candidate: OtherInvIdGet__FP6OBJECTi (conf 0.465) */



undefined4 FUN_004582d0(int param_1,int param_2)



{

  if (*(int *)(param_1 + 0x1e0) == 2) {

    return *(undefined4 *)(*(int *)(param_1 + 0x100) + 0x170 + param_2 * 4);

  }

  return 0;

}

/* ===== player_find_weapon_obj_type__FP6OBJECTii @ 0x00458300 ===== */
/* PS2 candidate: player_find_weapon_obj_type__FP6OBJECTii (conf 0.49) */



int player_find_weapon_obj_type__FP6OBJECTii(int param_1,int param_2,int param_3)



{

  int iVar1;

  undefined4 *puVar2;

  

  puVar2 = DAT_00632d80;

  while( true ) {

    if (puVar2 == (undefined4 *)0x0) {

      return 0;

    }

    iVar1 = puVar2[3];

    if (((((*(uint *)(iVar1 + 0xd8) & 0x8000) == 0) && (*(int *)(iVar1 + 0x210) == param_1)) &&

        (*(int *)(iVar1 + 4) == param_3)) && (*(int *)(iVar1 + 0x218) == param_2)) break;

    puVar2 = (undefined4 *)*puVar2;

  }

  return iVar1;

}

/* ===== SpecialWeaponIdSet__FP6OBJECTi @ 0x00458350 ===== */
/* PS2 candidate: SpecialWeaponIdSet__FP6OBJECTi (conf 0.619) */



int SpecialWeaponIdSet__FP6OBJECTi(int param_1,int param_2)



{

  int iVar1;

  int *piVar2;

  int iVar3;

  int iVar4;

  undefined4 uVar5;

  int *piVar6;

  int iVar7;

  int local_8;

  undefined1 local_4;

  

  iVar7 = 0;

  iVar3 = ObjIsMecc(param_1);

  if (iVar3 == 0) {

    return 0;

  }

  iVar3 = *(int *)(param_1 + 0x100);

  iVar4 = *(int *)(iVar3 + 0x18c);

  if (iVar4 == param_2) {

    iVar3 = IconDefWieldType(iVar4,1);

    if (iVar3 < 1) {

      return 0;

    }

    piVar6 = DAT_00632d80;

    if (DAT_00632d80 == (int *)0x0) {

      return 0;

    }

    while ((((iVar7 = piVar6[3], (*(uint *)(iVar7 + 0xd8) & 0x8000) != 0 ||

             (*(int *)(iVar7 + 0x210) != param_1)) || (*(int *)(iVar7 + 4) != iVar3)) ||

           (*(int *)(iVar7 + 0x218) != 10))) {

      piVar6 = (int *)*piVar6;

      if (piVar6 == (int *)0x0) {

        return 0;

      }

    }

    return iVar7;

  }

  iVar4 = IconDefWieldType(iVar4,1);

  local_8 = IconDefWieldType(param_2,1);

  *(uint *)(param_1 + 0xdc) = *(uint *)(param_1 + 0xdc) & 0xffbfffff;

  piVar6 = DAT_00632d80;

  if (0 < iVar4) {

    for (; piVar6 != (int *)0x0; piVar6 = (int *)*piVar6) {

      iVar1 = piVar6[3];

      if ((((*(byte *)(iVar1 + 0xd9) & 0x80) == 0) && (*(int *)(iVar1 + 0x210) == param_1)) &&

         ((*(int *)(iVar1 + 4) == iVar4 && (*(int *)(iVar1 + 0x218) == 10)))) {

        *(undefined4 *)(iVar1 + 0x274) = 0;

        *(undefined4 *)(iVar1 + 0x210) = 0;

        object_destroy(iVar1);

        break;

      }

    }

    iVar4 = *(int *)(iVar3 + 0x18c);

    if (iVar4 == 0x11) {

      mecc_disable_personal_shield(param_1);

    }

    else if (iVar4 == 0x14) {

      mecc_exit_bush(param_1);

    }

    else if (iVar4 == 0x13) {

      mecc_disable_repair_gun(param_1);

      for (piVar6 = DAT_00632d80; piVar2 = DAT_00632d80, piVar6 != (int *)0x0;

          piVar6 = (int *)*piVar6) {

        iVar4 = piVar6[3];

        if ((((*(uint *)(iVar4 + 0xd8) & 0x8000) == 0) && (*(int *)(iVar4 + 0x210) == param_1)) &&

           ((*(int *)(iVar4 + 4) == 0x381 && (*(int *)(iVar4 + 0x218) == 10)))) goto LAB_00458511;

      }

      for (; piVar2 != (int *)0x0; piVar2 = (int *)*piVar2) {

        iVar4 = piVar2[3];

        if (((((*(uint *)(iVar4 + 0xd8) & 0x8000) == 0) && (*(int *)(iVar4 + 0x210) == param_1)) &&

            (*(int *)(iVar4 + 4) == 0x381)) && (*(int *)(iVar4 + 0x218) == 2)) goto LAB_00458511;

      }

    }

  }

LAB_00458528:

  if (local_8 < 1) goto LAB_0045867f;

  uVar5 = *(undefined4 *)(param_1 + 0x18c);

  if (param_2 == 0xb) {

    iVar7 = object_allocate_type_end(0x3c,0x21);

    *(undefined4 *)(iVar7 + 0x18c) = uVar5;

    *(uint *)(iVar7 + 0x1c8) = *(uint *)(iVar7 + 0x1c8) | 0x600;

    *(undefined4 *)(iVar7 + 0x214) = 8;

  }

  else if (param_2 == 10) {

    uVar5 = IconDefProjectile(10,uVar5);

    iVar7 = PROJ_CreateBasic(uVar5);

    *(int *)(iVar7 + 0x274) = param_1;

    ObjectSetAnim(iVar7,1,0x20,0,0,0);

LAB_0045863f:

    *(undefined4 *)(iVar7 + 0x214) = 0;

  }

  else if (param_2 == 0x13) {

    iVar7 = object_allocate_type_end(0x381,0x20);

    *(undefined4 *)(iVar7 + 0x214) = 0;

    *(undefined4 *)(iVar7 + 0x218) = 10;

    *(int *)(iVar7 + 0x210) = param_1;

    *(int *)(iVar7 + 0x274) = param_1;

    *(uint *)(iVar7 + 0xd8) = *(uint *)(iVar7 + 0xd8) | 0x400000;

    uVar5 = IconDefWieldType(0x13,1,0x20);

    iVar7 = object_allocate_type_end(uVar5);

    *(undefined4 *)(iVar7 + 0x214) = 2;

  }

  else if (((param_2 == 0x11) || (param_2 == 0x12)) || (param_2 == 0x14)) {

    uVar5 = IconDefWieldType(param_2,1,0x20);

    iVar7 = object_allocate_type_end(uVar5);

    goto LAB_0045863f;

  }

  *(undefined4 *)(iVar7 + 0x218) = 10;

  *(int *)(iVar7 + 0x210) = param_1;

  *(int *)(iVar7 + 0x274) = param_1;

  *(uint *)(iVar7 + 0xd8) = *(uint *)(iVar7 + 0xd8) | 0x400000;

  *(uint *)(param_1 + 0xdc) = *(uint *)(param_1 + 0xdc) | 0x400000;

LAB_0045867f:

  *(int *)(iVar3 + 0x18c) = param_2;

  iVar3 = reaper_0052e4a0(param_1);

  if (iVar3 != 0) {

    local_4 = (undefined1)param_2;

    if (iVar7 == 0) {

      local_8 = 0;

    }

    else {

      local_8 = *(int *)(iVar7 + 0x188);

    }

    reaper_00530bd0(param_1,0,1,1,0x11,&local_8);

  }

  return iVar7;

LAB_00458511:

  *(undefined4 *)(iVar4 + 0x274) = 0;

  *(undefined4 *)(iVar4 + 0x210) = 0;

  object_destroy(iVar4);

  goto LAB_00458528;

}

/* ===== SpecialWeaponIdGet__FP6OBJECT @ 0x004586E0 ===== */
/* PS2 candidate: SpecialWeaponIdGet__FP6OBJECT (conf 0.46) */



undefined4 SpecialWeaponIdGet__FP6OBJECT(int param_1)



{

  int iVar1;

  

  iVar1 = ObjIsMecc(param_1);

  if (iVar1 != 0) {

    return *(undefined4 *)(*(int *)(param_1 + 0x100) + 0x18c);

  }

  return 0;

}

/* ===== FUN_00458710 @ 0x00458710 ===== */
/* PS2 candidate: TeamMemberInitWeapons__FP6OBJECT (conf 0.378) */



void FUN_00458710(int param_1)



{

  int iVar1;

  undefined4 uVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  

  iVar3 = param_1;

  iVar1 = *(int *)(param_1 + 0x100);

  if (param_1 == DAT_00632a88) {

    if (*(int *)(param_1 + 0x1e0) == 2) {

      if (((*(int *)(iVar1 + 0x60) == 0) && (*(int *)(iVar1 + 0x17c) != 1)) &&

         (iVar4 = reaper_0052e4a0(param_1), iVar4 != 0)) {

        param_1 = CONCAT31(param_1._1_3_,1);

        reaper_00530bd0(iVar3,0,0,1,10,&param_1);

      }

      *(undefined4 *)(iVar1 + 0x17c) = 1;

    }

  }

  else if (*(int *)(param_1 + 0x1e0) == 2) {

    if (((*(int *)(iVar1 + 0x60) == 0) && (*(int *)(iVar1 + 0x17c) != 2)) &&

       (iVar4 = reaper_0052e4a0(param_1), iVar4 != 0)) {

      param_1 = CONCAT31(param_1._1_3_,2);

      reaper_00530bd0(iVar3,0,0,1,10,&param_1);

    }

    *(undefined4 *)(iVar1 + 0x17c) = 2;

  }

  if (*(int *)(iVar3 + 0x1e0) == 2) {

    iVar4 = *(int *)(iVar3 + 0x100);

    if (*(int *)(iVar4 + 0x60) != 0) {

      uVar2 = *(undefined4 *)(iVar4 + 0x17c);

      iVar5 = reaper_0052e4a0(iVar3);

      if (iVar5 != 0) {

        param_1 = CONCAT31(param_1._1_3_,(char)uVar2);

        reaper_00530bd0(iVar3,0,0,1,10,&param_1);

      }

    }

    *(undefined4 *)(iVar4 + 0x60) = 0;

  }

  *(undefined4 *)(iVar1 + 0x148) = 0;

  *(undefined4 *)(iVar1 + 0x14c) = 0;

  *(undefined4 *)(iVar1 + 0x150) = 0;

  *(undefined4 *)(iVar1 + 0x154) = 0;

  *(undefined4 *)(iVar1 + 0x158) = 0;

  *(undefined4 *)(iVar1 + 0x15c) = 0;

  *(undefined4 *)(iVar1 + 0x160) = 0;

  *(undefined4 *)(iVar1 + 0x164) = 0;

  *(undefined4 *)(iVar1 + 0x168) = 0;

  *(undefined4 *)(iVar1 + 0x16c) = 0;

  iVar4 = dialog_level_is_base();

  if (iVar4 == 0) {

    if (*(int *)(iVar3 + 0x1e0) == 2) {

      iVar1 = *(int *)(iVar3 + 0x100);

      if (((*(int *)(iVar1 + 0x60) == 1) && (*(int *)(iVar1 + 0x180) != -1)) &&

         (iVar4 = reaper_0052e4a0(iVar3), iVar4 != 0)) {

        param_1 = CONCAT31(param_1._1_3_,0xff);

        reaper_00530bd0(iVar3,0,0,1,10,&param_1);

      }

      *(undefined4 *)(iVar1 + 0x180) = 0xffffffff;

    }

  }

  else {

    iVar4 = FUN_00452ee0(3);

    if (iVar4 == 0) {

      *(undefined4 *)(iVar1 + 0x180) = 3;

      *(undefined4 *)(iVar1 + 0x148) = 0x1e;

      if (*(int *)(iVar3 + 0x1e0) == 2) {

        iVar1 = *(int *)(iVar3 + 0x100);

        if (*(int *)(iVar1 + 0x60) != 1) {

          uVar2 = *(undefined4 *)(iVar1 + 0x180);

          iVar4 = reaper_0052e4a0(iVar3);

          if (iVar4 != 0) {

            param_1 = CONCAT31(param_1._1_3_,(char)uVar2);

            reaper_00530bd0(iVar3,0,0,1,10,&param_1);

          }

        }

        *(undefined4 *)(iVar1 + 0x60) = 1;

      }

    }

    else if (*(int *)(iVar3 + 0x1e0) == 2) {

      iVar1 = *(int *)(iVar3 + 0x100);

      if (((*(int *)(iVar1 + 0x60) == 1) && (*(int *)(iVar1 + 0x180) != -1)) &&

         (iVar4 = reaper_0052e4a0(iVar3), iVar4 != 0)) {

        param_1 = CONCAT31(param_1._1_3_,0xff);

        reaper_00530bd0(iVar3,0,0,1,10,&param_1);

      }

      *(undefined4 *)(iVar1 + 0x180) = 0xffffffff;

    }

  }

  if (*(int *)(iVar3 + 0x1e0) == 2) {

    iVar1 = *(int *)(iVar3 + 0x100);

    if ((*(int *)(iVar1 + 0x60) == 2) && (*(int *)(iVar1 + 0x184) != -1)) {

      reaper_lock_short_2(iVar3,0xffffffff);

    }

    *(undefined4 *)(iVar1 + 0x184) = 0xffffffff;

    if (*(int *)(iVar3 + 0x1e0) == 2) {

      iVar1 = *(int *)(iVar3 + 0x100);

      if ((*(int *)(iVar1 + 0x60) == 3) && (*(int *)(iVar1 + 0x188) != -1)) {

        reaper_lock_short_2(iVar3,0xffffffff);

      }

      *(undefined4 *)(iVar1 + 0x188) = 0xffffffff;

      if ((*(int *)(iVar3 + 0x1e0) == 2) &&

         (*(undefined4 *)(*(int *)(iVar3 + 0x100) + 0x170) = 0xffffffff,

         *(int *)(iVar3 + 0x1e0) == 2)) {

        *(undefined4 *)(*(int *)(iVar3 + 0x100) + 0x174) = 0xffffffff;

      }

    }

  }

  WeaponIdSetSlot__FP6OBJECTi(iVar3,2,0xffffffff);

  SpecialWeaponIdSet__FP6OBJECTi(iVar3,0xffffffff);

  return;

}

/* ===== TeamMemberClearWeapons__FP6OBJECT @ 0x00458A10 ===== */
/* PS2 candidate: TeamMemberClearWeapons__FP6OBJECT (conf 0.459) */



void TeamMemberClearWeapons__FP6OBJECT(int param_1)



{

  int iVar1;

  undefined4 uVar2;

  int iVar3;

  int iVar4;

  

  iVar3 = param_1;

  if (*(int *)(param_1 + 0x1e0) == 2) {

    iVar1 = *(int *)(param_1 + 0x100);

    if (((*(int *)(iVar1 + 0x60) == 0) && (*(int *)(iVar1 + 0x17c) != -1)) &&

       (iVar4 = reaper_0052e4a0(param_1), iVar4 != 0)) {

      param_1 = CONCAT31(param_1._1_3_,0xff);

      reaper_00530bd0(iVar3,0,0,1,10,&param_1);

    }

    *(undefined4 *)(iVar1 + 0x17c) = 0xffffffff;

  }

  if (*(int *)(iVar3 + 0x1e0) == 2) {

    iVar1 = *(int *)(iVar3 + 0x100);

    if (*(int *)(iVar1 + 0x60) != 0) {

      uVar2 = *(undefined4 *)(iVar1 + 0x17c);

      iVar4 = reaper_0052e4a0(iVar3);

      if (iVar4 != 0) {

        param_1 = CONCAT31(param_1._1_3_,(char)uVar2);

        reaper_00530bd0(iVar3,0,0,1,10,&param_1);

      }

    }

    *(undefined4 *)(iVar1 + 0x60) = 0;

    if (*(int *)(iVar3 + 0x1e0) == 2) {

      iVar1 = *(int *)(iVar3 + 0x100);

      if (((*(int *)(iVar1 + 0x60) == 1) && (*(int *)(iVar1 + 0x180) != -1)) &&

         (iVar4 = reaper_0052e4a0(iVar3), iVar4 != 0)) {

        param_1 = CONCAT31(param_1._1_3_,0xff);

        reaper_00530bd0(iVar3,0,0,1,10,&param_1);

      }

      *(undefined4 *)(iVar1 + 0x180) = 0xffffffff;

      if (*(int *)(iVar3 + 0x1e0) == 2) {

        iVar1 = *(int *)(iVar3 + 0x100);

        if (((*(int *)(iVar1 + 0x60) == 2) && (*(int *)(iVar1 + 0x184) != -1)) &&

           (iVar4 = reaper_0052e4a0(iVar3), iVar4 != 0)) {

          param_1 = CONCAT31(param_1._1_3_,0xff);

          reaper_00530bd0(iVar3,0,0,1,10,&param_1);

        }

        *(undefined4 *)(iVar1 + 0x184) = 0xffffffff;

        if (*(int *)(iVar3 + 0x1e0) == 2) {

          iVar1 = *(int *)(iVar3 + 0x100);

          if (((*(int *)(iVar1 + 0x60) == 3) && (*(int *)(iVar1 + 0x188) != -1)) &&

             (iVar4 = reaper_0052e4a0(iVar3), iVar4 != 0)) {

            param_1 = CONCAT31(param_1._1_3_,0xff);

            reaper_00530bd0(iVar3,0,0,1,10,&param_1);

          }

          *(undefined4 *)(iVar1 + 0x188) = 0xffffffff;

          if (((*(int *)(iVar3 + 0x1e0) == 2) &&

              (*(undefined4 *)(*(int *)(iVar3 + 0x100) + 0x170) = 0xffffffff,

              *(int *)(iVar3 + 0x1e0) == 2)) &&

             (*(undefined4 *)(*(int *)(iVar3 + 0x100) + 0x174) = 0xffffffff,

             *(int *)(iVar3 + 0x1e0) == 2)) {

            *(undefined4 *)(*(int *)(iVar3 + 0x100) + 0x178) = 0xffffffff;

          }

        }

      }

    }

  }

  SpecialWeaponIdSet__FP6OBJECTi(iVar3,0xffffffff);

  return;

}

/* ===== FUN_00458bf0 @ 0x00458BF0 ===== */
void FUN_00458bf0(int param_1,int param_2)



{

  int iVar1;

  int iVar2;

  

  if ((*(int *)(param_1 + 0x1e0) == 2) && (*(int *)(param_2 + 0x1e0) == 2)) {

    iVar1 = *(int *)(param_2 + 0x100);

    iVar2 = *(int *)(param_1 + 0x100);

    *(undefined4 *)(iVar2 + 0x17c) = *(undefined4 *)(iVar1 + 0x17c);

    *(undefined4 *)(iVar2 + 0x180) = *(undefined4 *)(iVar1 + 0x180);

    *(undefined4 *)(iVar2 + 0x184) = *(undefined4 *)(iVar1 + 0x184);

    *(undefined4 *)(iVar2 + 0x188) = *(undefined4 *)(iVar1 + 0x188);

    *(undefined4 *)(iVar2 + 0x18c) = *(undefined4 *)(iVar1 + 0x18c);

    *(undefined4 *)(iVar2 + 0x170) = *(undefined4 *)(iVar1 + 0x170);

    *(undefined4 *)(iVar2 + 0x174) = *(undefined4 *)(iVar1 + 0x174);

    *(undefined4 *)(iVar2 + 0x178) = *(undefined4 *)(iVar1 + 0x178);

    *(undefined4 *)(iVar2 + 0x60) = *(undefined4 *)(iVar1 + 0x60);

    *(undefined4 *)(iVar2 + 0x5c) = *(undefined4 *)(iVar1 + 0x5c);

  }

  return;

}

/* ===== FUN_00458c90 @ 0x00458C90 ===== */
bool FUN_00458c90(undefined4 param_1)



{

  int iVar1;

  

  iVar1 = FUN_004a90d0(param_1);

  return iVar1 == 1;

}

/* ===== FUN_00458cb0 @ 0x00458CB0 ===== */
bool FUN_00458cb0(undefined4 param_1)



{

  int iVar1;

  

  iVar1 = FUN_004a90d0(param_1);

  return iVar1 == 2;

}

/* ===== FUN_00458cd0 @ 0x00458CD0 ===== */
bool FUN_00458cd0(undefined4 param_1)



{

  int iVar1;

  

  iVar1 = FUN_004a90d0(param_1);

  return iVar1 == 4;

}

/* ===== FUN_00458cf0 @ 0x00458CF0 ===== */
undefined4 FUN_00458cf0(undefined4 param_1)



{

  int iVar1;

  

  iVar1 = FUN_004a9100(param_1);

  if (iVar1 != 2) {

    iVar1 = FUN_004a9100(param_1);

    if (iVar1 != 1) {

      return 0;

    }

  }

  return 1;

}

/* ===== FUN_00458d20 @ 0x00458D20 ===== */
undefined4 FUN_00458d20(undefined4 param_1)



{

  int iVar1;

  

  iVar1 = FUN_004a9100(param_1);

  if (iVar1 != 3) {

    iVar1 = FUN_004a9100(param_1);

    if (iVar1 != 1) {

      return 0;

    }

  }

  return 1;

}

/* ===== FUN_00458d50 @ 0x00458D50 ===== */
bool FUN_00458d50(undefined4 param_1)



{

  int iVar1;

  

  iVar1 = FUN_004a90d0(param_1);

  return iVar1 == 5;

}

/* ===== FUN_00458d70 @ 0x00458D70 ===== */
bool FUN_00458d70(undefined4 param_1)



{

  int iVar1;

  

  iVar1 = FUN_004a90d0(param_1);

  return iVar1 == 3;

}

/* ===== inv_check_pickup @ 0x00459540 ===== */
/* PS2 candidate: inv_check_pickup (conf 0.422) */



bool inv_check_pickup(int param_1,uint *param_2)



{

  uint uVar1;

  uint *puVar2;

  int iVar3;

  int iVar4;

  uint uVar5;

  int iVar6;

  undefined4 uVar7;

  float10 fVar8;

  

  puVar2 = param_2;

  iVar6 = param_1;

  uVar1 = *param_2;

  iVar3 = ObjIsMecc(param_1);

  if (iVar3 == 0) {

    iVar3 = ObjIsReaper(iVar6);

    if (iVar3 == 0) {

      iVar3 = ObjIsKabuto(iVar6);

      if (iVar3 == 0) {

        return false;

      }

      if (uVar1 != 0x24) {

        return true;

      }

    }

    else {

      iVar3 = FUN_00458d20(uVar1);

      if (iVar3 == 0) {

        return false;

      }

      iVar3 = FUN_00458c90(uVar1);

      if ((iVar3 != 0) &&

         ((iVar3 = reaper_has_bow_2(iVar6,uVar1), iVar3 != 0 ||

          (iVar3 = reaper_has_bow_2(iVar6), iVar3 < 0)))) {

        iVar3 = FUN_00458c90(uVar1);

        if (iVar3 == 0) {

          return false;

        }

        iVar3 = reaper_has_bow_2(iVar6,uVar1);

        if (iVar3 == 0) {

          return false;

        }

        uVar5 = IconDefAmmoIcon(uVar1);

        iVar3 = reaper_needs_ammo(iVar6,uVar5);

        if (iVar3 == 0) {

          return false;

        }

        *puVar2 = uVar5;

      }

      iVar3 = FUN_00458cd0(uVar1);

      if ((iVar3 != 0) && (iVar3 = reaper_needs_ammo(iVar6,uVar1), iVar3 == 0)) {

        return false;

      }

      iVar3 = FUN_00458d50(uVar1);

      if (iVar3 != 0) {

        uVar7 = IconDefMaxAmmo(uVar1);

        iVar3 = reaper_needs_other(iVar6,uVar1,uVar7);

        if (iVar3 == 0) {

          return false;

        }

      }

      iVar3 = FUN_00458d70(uVar1);

      if (iVar3 != 0) {

        iVar3 = reaper_has_bow(iVar6,uVar1);

        if (iVar3 == 0) {

          iVar3 = reaper_has_bow_3(iVar6,uVar1);

          if (iVar3 == 0) {

            return false;

          }

        }

        else {

          iVar3 = IconDefGiveAmmo();

          param_2 = (uint *)(float)iVar3;

          fVar8 = (float10)reaper_get_ammo(iVar6,uVar1);

          if ((float10)(float)param_2 <= fVar8) {

            return false;

          }

        }

      }

      if (uVar1 != 0x24) {

        return true;

      }

    }

    if (*(float *)(iVar6 + 0x278) <= 0.0) {

      return false;

    }

    return true;

  }

  iVar3 = *(int *)(iVar6 + 0x100);

  param_2 = (uint *)iVar3;

  iVar4 = FUN_00458cf0(uVar1);

  if (iVar4 == 0) {

    return false;

  }

  iVar4 = FUN_00458c90(uVar1);

  if ((iVar4 == 0) || (iVar4 = FUN_00457a70(iVar6,uVar1), iVar4 == 0)) {

    iVar4 = FUN_00458c90(uVar1);

    if ((iVar4 != 0) && (iVar4 = FUN_00457d10(iVar6), iVar4 == 0)) {

      return false;

    }

  }

  else {

    iVar3 = FUN_00457a70(iVar6,uVar1);

    if (iVar3 == 0) {

      return false;

    }

    uVar5 = IconDefAmmoIcon(uVar1);

    iVar3 = player_needs_ammo__FP6OBJECTi(iVar6,uVar5);

    if (iVar3 == 0) {

      return false;

    }

    *puVar2 = uVar5;

    iVar3 = (int)param_2;

  }

  iVar4 = FUN_00458cd0(uVar1);

  if ((iVar4 != 0) && (iVar4 = player_needs_ammo__FP6OBJECTi(iVar6,uVar1), iVar4 == 0)) {

    return false;

  }

  iVar4 = FUN_00458d70(uVar1);

  if (iVar4 != 0) {

    if (((*(uint *)(iVar6 + 0xdc) & 0x400000) != 0) && (DAT_00632bb4 == 0)) {

      return false;

    }

    if (uVar1 == 0xb) {

      param_2 = (uint *)0x0;

      param_1 = 0;

      turret_count_portables(&param_2,&param_1,*(undefined4 *)(iVar6 + 0x18c));

      if (4 < (int)param_2) {

        return false;

      }

      goto LAB_00459677;

    }

  }

  if (uVar1 == 10) {

    if ((*(uint *)(iVar6 + 0xdc) & 0x800000) != 0) {

      return false;

    }

  }

  else if (0x40 < uVar1) {

    return true;

  }

LAB_00459677:

                    /* WARNING (jumptable): Sanity check requires truncation of jumptable */

                    /* WARNING: Could not find normalized switch variable to match jumptable */

  switch((&DAT_004598ec)[uVar1]) {

  case 0:

    iVar3 = 0;

    while (iVar4 = FUN_004582d0(iVar6,iVar3), iVar4 != 0) {

      iVar4 = FUN_004582d0(iVar6,iVar3);

      if (iVar4 < 0) {

        if (2 < iVar3) {

          return false;

        }

        return true;

      }

      iVar3 = iVar3 + 1;

      if (2 < iVar3) {

        return false;

      }

    }

    break;

  case 1:

    if (uVar1 == 0x40) {

      iVar3 = *(int *)(iVar3 + 0x154);

    }

    else if (uVar1 == 9) {

      iVar3 = *(int *)(iVar3 + 0x150);

    }

    else {

      iVar3 = *(int *)(iVar3 + 0x14c);

    }

    iVar4 = 0;

    do {

      uVar5 = FUN_004582d0(iVar6,iVar4);

      if (uVar5 == uVar1) {

        iVar6 = IconDefMaxAmmo(uVar1);

        return iVar3 < iVar6;

      }

      iVar4 = iVar4 + 1;

    } while (iVar4 < 3);

    iVar3 = 0;

    do {

      iVar4 = FUN_004582d0(iVar6,iVar3);

      if (iVar4 == -1) {

        return true;

      }

      iVar3 = iVar3 + 1;

    } while (iVar3 < 3);

    return false;

  case 2:

    if ((0.0 < *(float *)(iVar6 + 0x278)) && (*(float *)(iVar6 + 0x278) < *(float *)(iVar6 + 0x1c0))

       ) {

      return true;

    }

    break;

  case 3:

    return true;

  }

  return false;

}

/* ===== inv_award_item @ 0x00459930 ===== */
void inv_award_item(int param_1,int param_2,int param_3,int param_4,uint param_5)



{

  float fVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  undefined4 uVar6;

  undefined4 uVar7;

  undefined4 *local_104;

  undefined1 local_100 [256];

  

  iVar2 = ObjIsMecc(param_1);

  if (iVar2 == 0) {

    iVar2 = ObjIsReaper(param_1);

    if (iVar2 != 0) {

      iVar2 = FUN_00458cd0(param_3);

      if (iVar2 == 0) {

        iVar2 = FUN_00458c90(param_3);

        if (iVar2 == 0) {

          iVar2 = FUN_00458d50(param_3);

          if (iVar2 == 0) {

            iVar2 = FUN_00458d70(param_3);

            if (iVar2 != 0) {

              FUN_004b8d30(param_1,param_3,0xffffffff);

            }

          }

          else {

            if (param_4 < 0) {

              param_4 = IconDefGiveAmmo(param_3);

            }

            reaper_give_other(param_1,param_3,0xffffffff,param_4,0);

          }

        }

        else {

          if (param_4 < 0) {

            param_4 = IconDefGiveAmmo(param_3);

          }

          iVar2 = reaper_has_bow_2(param_1);

          if (-1 < iVar2) {

            reaper_set_bow(param_1,param_3,iVar2,param_4,0);

          }

        }

      }

      else {

        if (param_4 < 0) {

          param_4 = IconDefGiveAmmo(param_3);

        }

        reaper_give_ammo(param_1,param_3,param_4);

      }

    }

  }

  else {

    iVar2 = *(int *)(param_1 + 0x100);

    iVar3 = FUN_00458d70(param_3);

    if (iVar3 == 0) {

      iVar3 = FUN_00458cd0(param_3);

      if (iVar3 == 0) {

        iVar3 = FUN_00458c90(param_3);

        if (iVar3 == 0) {

          iVar3 = FUN_00458cb0(param_3);

          if ((iVar3 == 0) && (iVar3 = FUN_00458d50(param_3), iVar3 == 0)) {

            if ((param_3 == 0x24) &&

               (fVar1 = *(float *)(param_1 + 0x278) - 25.0, *(float *)(param_1 + 0x278) = fVar1,

               fVar1 < 0.0)) {

              *(undefined4 *)(param_1 + 0x278) = 0;

            }

          }

          else {

            iVar3 = param_2;

            if (param_2 == -1) {

              iVar3 = 0;

              do {

                iVar4 = FUN_004582d0(param_1,iVar3);

                if (iVar4 == param_3) {

                  if (iVar3 != -1) goto LAB_00459ce0;

                  break;

                }

                iVar3 = iVar3 + 1;

              } while (iVar3 < 3);

              iVar4 = 0;

              param_2 = 0;

              do {

                iVar5 = FUN_004582d0(param_1,iVar4);

                iVar3 = iVar4;

                if (iVar5 < 0) break;

                iVar4 = iVar4 + 1;

                iVar3 = param_2;

              } while (iVar4 < 3);

            }

LAB_00459ce0:

            param_2 = iVar3;

            WeaponIdSetSlot__FP6OBJECTi(param_1,param_2,param_3);

            if (param_4 < 0) {

              param_4 = IconDefGiveAmmo(param_3);

            }

            if (param_3 == 8) {

              *(int *)(iVar2 + 0x14c) = *(int *)(iVar2 + 0x14c) + param_4;

              iVar3 = IconDefMaxAmmo(8);

              if (iVar3 < *(int *)(iVar2 + 0x14c)) {

                uVar6 = IconDefMaxAmmo(8);

                *(undefined4 *)(iVar2 + 0x14c) = uVar6;

              }

            }

            else if (param_3 == 9) {

              *(int *)(iVar2 + 0x150) = *(int *)(iVar2 + 0x150) + param_4;

              iVar3 = IconDefMaxAmmo(9);

              if (iVar3 < *(int *)(iVar2 + 0x150)) {

                uVar6 = IconDefMaxAmmo(9);

                *(undefined4 *)(iVar2 + 0x150) = uVar6;

              }

            }

            else if (param_3 == 0x40) {

              *(int *)(iVar2 + 0x154) = *(int *)(iVar2 + 0x154) + param_4;

              iVar3 = IconDefMaxAmmo(0x40);

              if (iVar3 < *(int *)(iVar2 + 0x154)) {

                uVar6 = IconDefMaxAmmo(0x40);

                *(undefined4 *)(iVar2 + 0x154) = uVar6;

              }

            }

          }

        }

        else {

          mecc_disable_repair_gun(param_1);

          iVar2 = FUN_00457a70(param_1,param_3);

          if (iVar2 == 0) {

            local_104 = (undefined4 *)0x0;

            if (param_2 == -1) {

              param_2 = FUN_00457d50(param_1);

            }

            reaper_lock_short_3(param_1,param_2);

            WeaponIdSetCurrent__FP6OBJECTi(param_1,param_3);

            local_104 = (undefined4 *)0x0;

            item_get_ammo(param_1,param_3,&local_104);

            if (local_104 != (undefined4 *)0x0) {

              *local_104 = 0;

            }

          }

          else {

            iVar2 = 1;

            do {

              iVar3 = FUN_00457fb0(param_1,iVar2);

              if (iVar3 == param_3) {

                reaper_lock_short_3(param_1,iVar2);

                break;

              }

              iVar2 = iVar2 + 1;

            } while (iVar2 < 4);

          }

          iVar2 = IconDefAmmoIcon(param_3);

          if (iVar2 != -1) {

            if (param_4 < 0) {

              param_4 = IconDefGiveAmmo(param_3);

            }

            inv_award_item(param_1,0xffffffff,iVar2,param_4,param_5 | 1);

          }

        }

      }

      else {

        if (param_4 < 0) {

          param_4 = IconDefGiveAmmo(param_3);

        }

        switch(param_3) {

        case 0x25:

          *(int *)(iVar2 + 0x148) = *(int *)(iVar2 + 0x148) + param_4;

          iVar3 = IconDefMaxAmmo(param_3);

          if (iVar3 < *(int *)(iVar2 + 0x148)) {

            uVar6 = IconDefMaxAmmo(param_3);

            *(undefined4 *)(iVar2 + 0x148) = uVar6;

          }

          break;

        case 0x26:

          *(float *)(iVar2 + 0x158) = (float)param_4 + *(float *)(iVar2 + 0x158);

          local_104 = (undefined4 *)IconDefMaxAmmo(param_3);

          if ((float)(int)local_104 < *(float *)(iVar2 + 0x158)) {

            local_104 = (undefined4 *)IconDefMaxAmmo(param_3);

            *(float *)(iVar2 + 0x158) = (float)(int)local_104;

          }

          break;

        case 0x27:

          *(int *)(iVar2 + 0x15c) = *(int *)(iVar2 + 0x15c) + param_4;

          iVar3 = IconDefMaxAmmo(param_3);

          if (iVar3 < *(int *)(iVar2 + 0x15c)) {

            uVar6 = IconDefMaxAmmo(param_3);

            *(undefined4 *)(iVar2 + 0x15c) = uVar6;

          }

          break;

        case 0x28:

          *(int *)(iVar2 + 0x160) = *(int *)(iVar2 + 0x160) + param_4;

          iVar3 = IconDefMaxAmmo(param_3);

          if (iVar3 < *(int *)(iVar2 + 0x160)) {

            uVar6 = IconDefMaxAmmo(param_3);

            *(undefined4 *)(iVar2 + 0x160) = uVar6;

          }

          break;

        case 0x29:

          *(int *)(iVar2 + 0x164) = *(int *)(iVar2 + 0x164) + param_4;

          iVar3 = IconDefMaxAmmo(param_3);

          if (iVar3 < *(int *)(iVar2 + 0x164)) {

            uVar6 = IconDefMaxAmmo(param_3);

            *(undefined4 *)(iVar2 + 0x164) = uVar6;

          }

          break;

        case 0x2a:

          *(int *)(iVar2 + 0x168) = *(int *)(iVar2 + 0x168) + param_4;

          iVar3 = IconDefMaxAmmo(param_3);

          if (iVar3 < *(int *)(iVar2 + 0x168)) {

            uVar6 = IconDefMaxAmmo(param_3);

            *(undefined4 *)(iVar2 + 0x168) = uVar6;

          }

          break;

        case 0x2b:

          *(int *)(iVar2 + 0x16c) = *(int *)(iVar2 + 0x16c) + param_4;

          iVar3 = IconDefMaxAmmo(param_3);

          if (iVar3 < *(int *)(iVar2 + 0x16c)) {

            uVar6 = IconDefMaxAmmo(param_3);

            *(undefined4 *)(iVar2 + 0x16c) = uVar6;

          }

        }

      }

    }

    else {

      SpecialWeaponIdSet__FP6OBJECTi(param_1);

    }

  }

  if ((((param_5 & 1) == 0) && (param_1 == DAT_00632a88)) && (param_3 != -1)) {

    uVar6 = FUN_00507b00(s_InvChPickupItem_0055a148);

    uVar7 = FUN_004a9130(param_3);

    crt_sprintf(local_100,uVar6,uVar7);

    chat_insert(local_100,1);

  }

  return;

}

/* ===== FUN_00459f10 @ 0x00459F10 ===== */
/* PS2 candidate: inv_remove_item (conf 0.404) */



void FUN_00459f10(int param_1,undefined4 *param_2,undefined4 param_3,int param_4)



{

  int *piVar1;

  int iVar2;

  float fVar3;

  undefined4 uVar4;

  int iVar5;

  int iVar6;

  

  uVar4 = param_3;

  iVar2 = *(int *)(param_1 + 0x100);

  iVar5 = FUN_00458d70(param_3);

  if (iVar5 != 0) {

    SpecialWeaponIdSet__FP6OBJECTi(param_1,0xffffffff);

    return;

  }

  iVar5 = FUN_00458cd0(uVar4);

  if (iVar5 == 0) {

    iVar6 = FUN_00458c90(uVar4);

    iVar5 = (int)param_2;

    if (iVar6 == 0) {

      iVar5 = FUN_00458cb0(uVar4);

      if ((iVar5 != 0) || (iVar5 = FUN_00458d50(uVar4), iVar5 != 0)) {

        iVar5 = param_4;

        if (param_4 < 0) {

          iVar5 = IconDefGiveAmmo(uVar4);

        }

        switch(uVar4) {

        case 0:

          WeaponIdSetSlot__FP6OBJECTi(param_1,param_2,0xffffffff);

          break;

        case 8:

          iVar5 = *(int *)(iVar2 + 0x14c) - iVar5;

          *(int *)(iVar2 + 0x14c) = iVar5;

          if (iVar5 < 1) {

            WeaponIdSetSlot__FP6OBJECTi(param_1,param_2,0xffffffff);

            *(undefined4 *)(iVar2 + 0x14c) = 0;

            return;

          }

          break;

        case 9:

          iVar5 = *(int *)(iVar2 + 0x150) - iVar5;

          *(int *)(iVar2 + 0x150) = iVar5;

          if (iVar5 < 1) {

            WeaponIdSetSlot__FP6OBJECTi(param_1,param_2,0xffffffff);

            *(undefined4 *)(iVar2 + 0x150) = 0;

            return;

          }

          break;

        case 0x40:

          iVar5 = *(int *)(iVar2 + 0x154) - iVar5;

          *(int *)(iVar2 + 0x154) = iVar5;

          if (iVar5 < 1) {

            WeaponIdSetSlot__FP6OBJECTi(param_1,param_2,0xffffffff);

            *(undefined4 *)(iVar2 + 0x154) = 0;

            return;

          }

        }

      }

    }

    else if (param_2 != (undefined4 *)0xffffffff) {

      param_2 = (undefined4 *)0x0;

      item_get_ammo(param_1,uVar4,&param_2);

      if (param_2 != (undefined4 *)0x0) {

        *param_2 = 0;

      }

      FUN_00457f40(param_1,iVar5,0xffffffff);

      WeaponIdCycleToNext__FP6OBJECTi(param_1,1);

      return;

    }

  }

  else {

    if (param_4 < 0) {

      param_4 = IconDefGiveAmmo(uVar4);

    }

    switch(uVar4) {

    case 0x25:

      piVar1 = (int *)(iVar2 + 0x148);

      *piVar1 = *piVar1 - param_4;

      if (*piVar1 < 0) {

        *(undefined4 *)(iVar2 + 0x148) = 0;

        return;

      }

      break;

    case 0x26:

      fVar3 = *(float *)(iVar2 + 0x158) - (float)param_4;

      *(float *)(iVar2 + 0x158) = fVar3;

      if (fVar3 < 0.0) {

        *(undefined4 *)(iVar2 + 0x158) = 0;

        return;

      }

      break;

    case 0x27:

      piVar1 = (int *)(iVar2 + 0x15c);

      *piVar1 = *piVar1 - param_4;

      if (*piVar1 < 0) {

        *(undefined4 *)(iVar2 + 0x15c) = 0;

        return;

      }

      break;

    case 0x28:

      piVar1 = (int *)(iVar2 + 0x160);

      *piVar1 = *piVar1 - param_4;

      if (*piVar1 < 0) {

        *(undefined4 *)(iVar2 + 0x160) = 0;

        return;

      }

      break;

    case 0x29:

      piVar1 = (int *)(iVar2 + 0x164);

      *piVar1 = *piVar1 - param_4;

      if (*piVar1 < 0) {

        *(undefined4 *)(iVar2 + 0x164) = 0;

        return;

      }

      break;

    case 0x2a:

      piVar1 = (int *)(iVar2 + 0x168);

      *piVar1 = *piVar1 - param_4;

      if (*piVar1 < 0) {

        *(undefined4 *)(iVar2 + 0x168) = 0;

        return;

      }

      break;

    case 0x2b:

      piVar1 = (int *)(iVar2 + 0x16c);

      *piVar1 = *piVar1 - param_4;

      if (*piVar1 < 0) {

        *(undefined4 *)(iVar2 + 0x16c) = 0;

        return;

      }

    }

  }

  return;

}

/* ===== item_get_ammo @ 0x0045A2B0 ===== */
/* PS2 candidate: item_get_ammo (conf 0.457) */



int item_get_ammo(int param_1,undefined4 param_2,int *param_3)



{

  int iVar1;

  

  iVar1 = *(int *)(param_1 + 0x100);

  if (*(int *)(param_1 + 0x1e0) != 2) {

    return 0;

  }

  switch(param_2) {

  case 0:

    break;

  case 1:

  case 2:

  case 4:

    if (param_3 != (int *)0x0) {

      *param_3 = 0;

    }

    break;

  case 3:

  case 0x25:

    if (param_3 != (int *)0x0) {

      *param_3 = iVar1 + 0x148;

    }

    return *(int *)(iVar1 + 0x148);

  case 5:

  case 0x26:

    if (param_3 != (int *)0x0) {

      *param_3 = iVar1 + 0x158;

    }

    iVar1 = __ftol();

    return iVar1;

  case 6:

  case 0x27:

    if (param_3 != (int *)0x0) {

      *param_3 = iVar1 + 0x15c;

    }

    return *(int *)(iVar1 + 0x15c);

  case 7:

  case 0x2b:

    if (param_3 != (int *)0x0) {

      *param_3 = iVar1 + 0x16c;

    }

    return *(int *)(iVar1 + 0x16c);

  case 8:

    if (param_3 != (int *)0x0) {

      *param_3 = iVar1 + 0x14c;

    }

    return *(int *)(iVar1 + 0x14c);

  case 9:

    if (param_3 != (int *)0x0) {

      *param_3 = iVar1 + 0x150;

    }

    return *(int *)(iVar1 + 0x150);

  default:

    if (param_3 != (int *)0x0) {

      *param_3 = 0;

    }

    iVar1 = mecc_in_gyro(param_1);

    if (iVar1 != 0) {

      iVar1 = FUN_00482310(param_1);

      if ((iVar1 != 0) && (0 < *(int *)(iVar1 + 0xe8))) {

        return *(int *)(iVar1 + 0xe8);

      }

      return 0;

    }

    break;

  case 0xe:

  case 0x28:

    if (param_3 != (int *)0x0) {

      *param_3 = iVar1 + 0x160;

    }

    return *(int *)(iVar1 + 0x160);

  case 0xf:

  case 0x29:

    if (param_3 != (int *)0x0) {

      *param_3 = iVar1 + 0x164;

    }

    return *(int *)(iVar1 + 0x164);

  case 0x10:

  case 0x2a:

    if (param_3 != (int *)0x0) {

      *param_3 = iVar1 + 0x168;

    }

    return *(int *)(iVar1 + 0x168);

  case 0x13:

    if (param_3 != (int *)0x0) {

      *param_3 = 0;

    }

    return 999;

  case 0x40:

    if (param_3 != (int *)0x0) {

      *param_3 = iVar1 + 0x154;

    }

    return *(int *)(iVar1 + 0x154);

  }

  return 1;

}

/* ===== item_use_ammo @ 0x0045A4C0 ===== */
/* PS2 candidate: item_use_ammo (conf 0.475) */



void item_use_ammo(int param_1,undefined4 param_2)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  float10 fVar4;

  

  iVar2 = *(int *)(param_1 + 0x100);

  if (*(int *)(param_1 + 0x1e0) == 2) {

    switch(param_2) {

    case 3:

      piVar1 = (int *)(iVar2 + 0x148);

      *piVar1 = *piVar1 + -1;

      if (*piVar1 < 0) {

        *(undefined4 *)(iVar2 + 0x148) = 0;

        return;

      }

      break;

    default:

      iVar2 = mecc_in_gyro(param_1);

      if ((((iVar2 != 0) && (iVar2 = FUN_00482310(param_1), iVar2 != 0)) &&

          (0 < *(int *)(iVar2 + 0xe8))) &&

         (iVar3 = *(int *)(iVar2 + 0xe8) + -1, *(int *)(iVar2 + 0xe8) = iVar3, iVar3 < 0)) {

        *(undefined4 *)(iVar2 + 0xe8) = 0;

      }

      break;

    case 5:

      fVar4 = (float10)FUN_00518b70(param_1,0);

      fVar4 = (float10)*(float *)(iVar2 + 0x158) - fVar4 * (float10)100.0;

      *(float *)(iVar2 + 0x158) = (float)fVar4;

      if (fVar4 < (float10)1.0) {

        *(undefined4 *)(iVar2 + 0x158) = 0;

        return;

      }

      break;

    case 6:

      piVar1 = (int *)(iVar2 + 0x15c);

      *piVar1 = *piVar1 + -1;

      if (*piVar1 < 0) {

        *(undefined4 *)(iVar2 + 0x15c) = 0;

        return;

      }

      break;

    case 7:

      piVar1 = (int *)(iVar2 + 0x16c);

      *piVar1 = *piVar1 + -1;

      if (*piVar1 < 0) {

        *(undefined4 *)(iVar2 + 0x16c) = 0;

        return;

      }

      break;

    case 8:

      iVar3 = *(int *)(iVar2 + 0x14c) + -1;

      *(int *)(iVar2 + 0x14c) = iVar3;

      if (iVar3 < 1) {

        *(undefined4 *)(iVar2 + 0x14c) = 0;

        iVar2 = 0;

        do {

          iVar3 = FUN_004582d0(param_1,iVar2);

          if (iVar3 == 8) {

            WeaponIdSetSlot__FP6OBJECTi(param_1,iVar2,0xffffffff);

          }

          iVar2 = iVar2 + 1;

        } while (iVar2 < 3);

        return;

      }

      break;

    case 9:

      iVar3 = *(int *)(iVar2 + 0x150) + -1;

      *(int *)(iVar2 + 0x150) = iVar3;

      if (iVar3 < 1) {

        *(undefined4 *)(iVar2 + 0x150) = 0;

        iVar2 = 0;

        do {

          iVar3 = FUN_004582d0(param_1,iVar2);

          if (iVar3 == 9) {

            WeaponIdSetSlot__FP6OBJECTi(param_1,iVar2,0xffffffff);

          }

          iVar2 = iVar2 + 1;

        } while (iVar2 < 3);

        return;

      }

      break;

    case 0xe:

      piVar1 = (int *)(iVar2 + 0x160);

      *piVar1 = *piVar1 + -1;

      if (*piVar1 < 0) {

        *(undefined4 *)(iVar2 + 0x160) = 0;

        return;

      }

      break;

    case 0xf:

      piVar1 = (int *)(iVar2 + 0x164);

      *piVar1 = *piVar1 + -1;

      if (*piVar1 < 0) {

        *(undefined4 *)(iVar2 + 0x164) = 0;

        return;

      }

      break;

    case 0x10:

      piVar1 = (int *)(iVar2 + 0x168);

      *piVar1 = *piVar1 + -1;

      if (*piVar1 < 0) {

        *(undefined4 *)(iVar2 + 0x168) = 0;

        return;

      }

      break;

    case 0x40:

      iVar3 = *(int *)(iVar2 + 0x154) + -1;

      *(int *)(iVar2 + 0x154) = iVar3;

      if (iVar3 < 1) {

        *(undefined4 *)(iVar2 + 0x154) = 0;

        iVar2 = 0;

        do {

          iVar3 = FUN_004582d0(param_1,iVar2);

          if (iVar3 == 0x40) {

            WeaponIdSetSlot__FP6OBJECTi(param_1,iVar2,0xffffffff);

          }

          iVar2 = iVar2 + 1;

        } while (iVar2 < 3);

        return;

      }

    }

  }

  return;

}

/* ===== item_create_base_pickup @ 0x0045A740 ===== */
/* PS2 candidate: item_create_base_pickup (conf 0.625) */



void item_create_base_pickup(undefined4 *param_1,undefined4 param_2,int param_3)



{

  undefined4 *puVar1;

  int iVar2;

  float10 fVar3;

  

  iVar2 = FUN_004a8fe0(param_2);

  if (iVar2 < 0) {

    iVar2 = 0x311;

  }

  iVar2 = object_allocate_type(iVar2,0);

  object_change_ospec(iVar2,0x25);

  puVar1 = *(undefined4 **)(iVar2 + 0x100);

  puVar1[6] = param_3;

  if (param_3 == -1) {

    puVar1[7] = 0;

  }

  else {

    puVar1[7] = 1;

  }

  *(undefined4 *)(iVar2 + 0xa0) = *param_1;

  *(undefined4 *)(iVar2 + 0xa4) = param_1[1];

  *(undefined4 *)(iVar2 + 0xa8) = param_1[2];

  fVar3 = (float10)FUN_00455600((undefined4 *)(iVar2 + 0xa0));

  if ((float10)*(float *)(iVar2 + 0xa8) < fVar3) {

    *(float *)(iVar2 + 0xa8) = (float)fVar3;

  }

  *puVar1 = param_2;

  puVar1[1] = 0xffffffff;

  puVar1[5] = 0;

  *(undefined4 *)(iVar2 + 0xe8) = 1;

  *(uint *)(iVar2 + 0xe0) = *(uint *)(iVar2 + 0xe0) | 1;

  if (DAT_00632f08 != 0) {

    comm_0052b780_user_6(iVar2,0);

  }

  return;

}

/* ===== item_drop_item @ 0x0045A820 ===== */
/* PS2 candidate: item_drop_item (conf 0.512) */



int item_drop_item(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,

                  undefined4 param_5,undefined4 param_6,undefined4 param_7)



{

  float fVar1;

  undefined4 *puVar2;

  int iVar3;

  int iVar4;

  

  iVar3 = FUN_004a8fe0(param_2);

  if (iVar3 < 0) {

    iVar3 = 0x311;

  }

  iVar3 = object_allocate_type(iVar3,0);

  object_change_ospec(iVar3,0x25);

  puVar2 = *(undefined4 **)(iVar3 + 0x100);

  *(undefined4 *)(iVar3 + 0xa0) = *(undefined4 *)(param_1 + 0xa0);

  *(undefined4 *)(iVar3 + 0xa4) = *(undefined4 *)(param_1 + 0xa4);

  *(undefined4 *)(iVar3 + 0xa8) = *(undefined4 *)(param_1 + 0xa8);

  fVar1 = *(float *)(param_1 + 0x290);

  *(undefined4 *)(iVar3 + 0x128) = param_4;

  *(float *)(iVar3 + 0xa8) = fVar1 - 1.0;

  *(undefined4 *)(iVar3 + 300) = param_5;

  *(undefined4 *)(iVar3 + 0x130) = param_6;

  *(uint *)(iVar3 + 0xe0) = *(uint *)(iVar3 + 0xe0) | 1;

  puVar2[1] = param_3;

  puVar2[3] = param_1;

  puVar2[4] = 0x3f800000;

  *puVar2 = param_2;

  puVar2[5] = param_7;

  *(undefined4 *)(iVar3 + 0xe8) = 0;

  iVar4 = reaper_0052e4a0(param_1);

  if (iVar4 != 0) {

    comm_0052b780_user_6(iVar3,0);

  }

  return iVar3;

}

/* ===== item_drop_backheld @ 0x0045A900 ===== */
/* PS2 candidate: item_drop_backheld (conf 0.637) */



void item_drop_backheld(int param_1)



{

  undefined4 *puVar1;

  int iVar2;

  int iVar3;

  undefined4 uVar4;

  undefined4 uVar5;

  undefined1 local_100 [256];

  

  iVar2 = ObjIsMecc(param_1);

  if ((iVar2 != 0) && (iVar2 = mecc_in_gyro(param_1), iVar2 != 0)) {

    obj_swap_link(param_1);

    return;

  }

  if (((*(int *)(param_1 + 0x210) != 0) && (*(int *)(*(int *)(param_1 + 0x210) + 0x1e0) == 0x5f)) &&

     (iVar2 = ObjIsMecc(param_1), iVar2 != 0)) {

    obj_swap_link(param_1);

    return;

  }

  iVar2 = ObjIsReaper(param_1);

  if ((((iVar2 != 0) && (*(int *)(param_1 + 0x210) != 0)) &&

      (iVar2 = ObjIsJetski(*(int *)(param_1 + 0x210)), iVar2 != 0)) &&

     (((*(int *)(DAT_006330e4 + 0x50bc) < 0 ||

       (*(int *)(*(int *)(DAT_006330e4 + 0x50bc) * 0x118 + 0x2320 + DAT_006330e4) == 0)) ||

      (DAT_00632e74 != 0)))) {

    rpboat_unlock_from_boat__FP6OBJECTT0(param_1,*(undefined4 *)(param_1 + 0x210));

    return;

  }

  puVar1 = DAT_00632d98;

  if ((*(uint *)(param_1 + 0xdc) & 0x800000) != 0) {

    for (; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {

      iVar2 = puVar1[3];

      if ((((-1 < (char)(*(uint *)(iVar2 + 0xd8) >> 8)) &&

           ((((iVar3 = *(int *)(iVar2 + 4), iVar3 == 0xb || (iVar3 == 0x248)) || (iVar3 == 0x2e6))

            && ((*(int *)(iVar2 + 0x210) == param_1 || (*(int *)(iVar2 + 0x274) == param_1)))))) &&

          (*(int *)(iVar2 + 0xe8) != 5)) &&

         (((*(uint *)(iVar2 + 0xd8) & 0x400) == 0 && (*(int *)(*(int *)(iVar2 + 0x100) + 0x54) == 0)

          ))) {

        smartie_unlock_from_player(iVar2,param_1,1);

        iVar3 = reaper_0052e4a0(param_1);

        if (iVar3 == 0) {

          return;

        }

        reaper_lock_4f(iVar2,param_1,0,0);

        return;

      }

    }

  }

  if ((*(uint *)(param_1 + 0xdc) & 0x400000) != 0) {

    iVar2 = SpecialWeaponIdGet__FP6OBJECT(param_1);

    iVar3 = ObjIsMecc(param_1);

    if ((iVar3 != 0) && (-1 < iVar2)) {

      if (param_1 == DAT_00632a88) {

        uVar4 = FUN_00507b00(s_InvChDropItem_0055a158);

        uVar5 = FUN_004a9130(iVar2);

        crt_sprintf(local_100,uVar4,uVar5);

        chat_insert(local_100,1);

      }

      item_drop_item(param_1,iVar2,1,*(float *)(param_1 + 0x29c) * -30.0,

                     *(float *)(param_1 + 0x2ac) * -30.0,0x41700000,0x41f00000);

      SpecialWeaponIdSet__FP6OBJECTi(param_1,0xffffffff);

    }

  }

  return;

}

/* ===== item_drop_curweap @ 0x0045AB30 ===== */
/* PS2 candidate: item_drop_curweap (conf 0.504) */



void item_drop_curweap(int param_1)



{

  int iVar1;

  undefined4 uVar2;

  undefined4 uVar3;

  undefined4 *local_104;

  undefined1 local_100 [256];

  

  if (*(float *)(param_1 + 0x278) < *(float *)(param_1 + 0x1c0)) {

    iVar1 = ObjIsMecc(param_1);

    if (iVar1 != 0) {

      iVar1 = WeaponIdGetPresent__FP6OBJECT(param_1);

      if (((iVar1 != 1) && (iVar1 != 0x13)) && (-1 < iVar1)) {

        if (param_1 == DAT_00632a88) {

          uVar2 = FUN_00507b00(s_InvChDropItem_0055a158);

          uVar3 = FUN_004a9130(iVar1);

          crt_sprintf(local_100,uVar2,uVar3);

          chat_insert(local_100,1);

        }

        sound_play_player(0x578,param_1);

        local_104 = (undefined4 *)0x0;

        uVar2 = item_get_ammo(param_1,iVar1,&local_104,*(float *)(param_1 + 0x29c) * -30.0,

                              *(float *)(param_1 + 0x2ac) * -30.0,0x41700000,0x41f00000);

        item_drop_item(param_1,iVar1,uVar2);

        if (local_104 != (undefined4 *)0x0) {

          *local_104 = 0;

        }

        WeaponIdSetCurrent__FP6OBJECTi(param_1,0xffffffff);

        WeaponIdCycleToNext__FP6OBJECTi(param_1,1);

      }

    }

  }

  return;

}

/* ===== item_drop_all_random @ 0x0045AC50 ===== */
/* PS2 candidate: item_drop_all_random (conf 0.435) */



void item_drop_all_random(undefined4 *param_1)



{

  float fVar1;

  undefined4 *puVar2;

  int iVar3;

  undefined4 uVar4;

  int iVar5;

  float10 fVar6;

  float10 fVar7;

  

  puVar2 = param_1;

  iVar3 = ObjIsMecc(param_1);

  if (iVar3 != 0) {

    iVar3 = WeaponIdGetPresent__FP6OBJECT(puVar2);

    if (((-1 < iVar3) && (iVar3 = WeaponIdGetPresent__FP6OBJECT(puVar2), iVar3 != 1)) &&

       ((iVar3 = dialog_level_is_base(), iVar3 == 0 ||

        (iVar3 = WeaponIdGetPresent__FP6OBJECT(puVar2), iVar3 != 3)))) {

      fVar6 = (float10)rndfloatrange(0,0x40c8f5c3);

      fVar1 = (float)fVar6;

      param_1 = (undefined4 *)fVar1;

      fVar6 = (float10)FUN_0050adb0(fVar1);

      fVar7 = (float10)FUN_0050ade0(fVar1);

      param_1 = (undefined4 *)0x0;

      uVar4 = WeaponIdGetPresent__FP6OBJECT

                        (puVar2,&param_1,(float)fVar6 * 6.0,(float)(fVar7 * (float10)6.0),0x41280000

                         ,0x41f00000);

      uVar4 = item_get_ammo(puVar2,uVar4);

      uVar4 = WeaponIdGetPresent__FP6OBJECT(puVar2,uVar4);

      item_drop_item(puVar2,uVar4);

      if (param_1 != (undefined4 *)0x0) {

        *param_1 = 0;

      }

    }

    iVar3 = 0;

    do {

      iVar5 = FUN_004582d0(puVar2,iVar3);

      if (-1 < iVar5) {

        fVar6 = (float10)rndfloatrange(0,0x40c8f5c3);

        fVar1 = (float)fVar6;

        param_1 = (undefined4 *)fVar1;

        fVar6 = (float10)FUN_0050adb0(fVar1);

        fVar7 = (float10)FUN_0050ade0(fVar1);

        param_1 = (undefined4 *)0x0;

        uVar4 = FUN_004582d0(puVar2,iVar3,&param_1,(float)fVar6 * 6.0,(float)(fVar7 * (float10)6.0),

                             0x41280000,0x41f00000);

        uVar4 = item_get_ammo(puVar2,uVar4);

        uVar4 = FUN_004582d0(puVar2,iVar3,uVar4);

        item_drop_item(puVar2,uVar4);

        if (param_1 != (undefined4 *)0x0) {

          *param_1 = 0;

        }

      }

      iVar3 = iVar3 + 1;

    } while (iVar3 < 3);

    iVar3 = SpecialWeaponIdGet__FP6OBJECT(puVar2);

    if (-1 < iVar3) {

      fVar6 = (float10)rndfloatrange(0,0x40c8f5c3);

      fVar1 = (float)fVar6;

      param_1 = (undefined4 *)fVar1;

      fVar6 = (float10)FUN_0050adb0(fVar1);

      fVar7 = (float10)FUN_0050ade0(fVar1);

      uVar4 = SpecialWeaponIdGet__FP6OBJECT

                        (puVar2,1,(float)fVar6 * 6.0,(float)(fVar7 * (float10)6.0),0x41280000,

                         0x41f00000);

      item_drop_item(puVar2,uVar4);

    }

    return;

  }

  return;

}

/* ===== ai_target_classify @ 0x0045AE90 ===== */
byte ai_target_classify(int param_1,int param_2,byte param_3)



{

  int iVar1;

  int iVar2;

  byte bVar3;

  

  bVar3 = 0;

  if (param_2 == 0) {

    return 0;

  }

  if (param_2 == param_1) {

    return 0;

  }

  if ((*(uint *)(param_2 + 0xd8) & 0x4000c000) != 0) {

    return 0;

  }

  iVar2 = FUN_004a6220(param_2);

  if (iVar2 == 0) {

    iVar2 = FUN_004a6300(param_2);

    if (((iVar2 == 0) || (iVar2 = meccbasepit_bldg_from_object(param_2), iVar2 < 0)) ||

       (iVar2 = dialog_level_is_base(), iVar2 == 0)) goto LAB_0045af46;

    iVar2 = FUN_00521330(DAT_00632f18);

  }

  else {

    iVar2 = meccbasepit_bldg_from_object();

    if ((iVar2 < 0) || (iVar2 = dialog_level_is_base(), iVar2 == 0)) goto LAB_0045af46;

    iVar2 = FUN_00521330(DAT_00632f18);

  }

  if ((iVar2 == 0) && (iVar2 = FUN_00521310(DAT_00632f18), iVar2 == 0)) {

    return 0;

  }

LAB_0045af46:

  iVar2 = *(int *)(param_2 + 0x210);

  if (((iVar2 == 0) || ((*(int *)(iVar2 + 0x1e0) != 1 && (*(int *)(iVar2 + 0x1e0) != 0x4c)))) &&

     (*(int *)(param_1 + 0x210) != param_2)) {

    iVar1 = *(int *)(param_1 + 0x100);

    if ((param_3 & 1) != 0) {

      if (((*(uint *)(param_2 + 0x1d0) & *(uint *)(iVar1 + 0x334)) == 0) ||

         ((iVar2 != 0 && (*(int *)(param_2 + 0x1e0) != 0x33)))) {

        bVar3 = 0;

      }

      else {

        bVar3 = 1;

      }

    }

    if ((param_3 & 2) != 0) {

      bVar3 = bVar3 | (*(uint *)(iVar1 + 0x338) & *(uint *)(param_2 + 0x1d0)) != 0;

    }

    if ((param_3 & 4) != 0) {

      bVar3 = bVar3 | (*(uint *)(iVar1 + 0x33c) & *(uint *)(param_2 + 0x1d0)) != 0;

    }

  }

  return bVar3;

}

/* ===== reaper_spawn_ospec_1 @ 0x0045B2B0 ===== */
void reaper_spawn_ospec_1

               (undefined4 param_1,int param_2,undefined4 *param_3,int param_4,float param_5,

               float param_6)



{

  int iVar1;

  int iVar2;

  float10 fVar3;

  undefined4 local_20;

  undefined4 local_1c;

  undefined4 local_18;

  float local_14;

  float local_10;

  undefined4 local_c;

  undefined4 local_8;

  undefined4 local_4;

  

  iVar1 = object_0046e830(param_1,param_2);

  if (iVar1 != 0) {

    iVar2 = reaper_0052e4a0(param_1);

    if (iVar2 != 0) {

      local_20 = *param_3;

      local_1c = param_3[1];

      local_18 = param_3[2];

      local_4 = 0;

      if (param_4 != 0) {

        local_4 = *(undefined4 *)(param_4 + 0x188);

      }

      local_c = *(undefined4 *)(iVar1 + 0x188);

      local_10 = param_6;

      local_14 = param_5;

      local_8 = *(undefined4 *)(param_2 + 0x188);

      reaper_00530bd0(param_1,5,3,0,6,&local_20);

    }

    FUN_0046e120(iVar1,&LAB_0045afe0);

    if (param_6 != 0.0) {

      *(float *)(param_2 + 0xc4) = *(float *)(param_2 + 0xc4) / param_6;

    }

    *(undefined4 *)(param_2 + 0x210) = 0;

    if (*(int *)(param_2 + 0x1e0) == 0x59) {

      if (*(int *)(param_2 + 0x218) < 2) {

        FUN_00425850(param_2);

      }

    }

    else if (*(int *)(param_2 + 0x1e0) == 0x12) {

      FUN_004f4150();

    }

    else {

      iVar2 = ObjIsReaper(param_2);

      if (iVar2 != 0) {

        *(undefined4 *)(param_2 + 0xc4) = *(undefined4 *)(*(int *)(param_2 + 0x100) + 0xfac);

      }

    }

    *(uint *)(param_2 + 0xd8) = *(uint *)(param_2 + 0xd8) & 0xfff7ffff | 0x10000000;

    *(int *)(param_2 + 0x210) = iVar1;

    *(undefined4 *)(param_2 + 0x218) = 0xffffffff;

    FUN_0050a610(iVar1 + 0xa0,param_3);

    fVar3 = (float10)FUN_00543e70();

    FUN_0046e9d0(iVar1,param_3,param_4,(float)(fVar3 / (float10)param_5),0x3f400000);

  }

  return;

}

/* ===== reaper_spawn_ospec_2 @ 0x0045B440 ===== */
void reaper_spawn_ospec_2(undefined4 param_1,int param_2,int param_3,float param_4,float param_5)



{

  int iVar1;

  int iVar2;

  float10 fVar3;

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

  

  local_2c = (*(float *)(param_3 + 0x288) + *(float *)(param_3 + 0x27c)) * 0.5;

  local_28 = (*(float *)(param_3 + 0x28c) + *(float *)(param_3 + 0x280)) * 0.5;

  local_24 = (*(float *)(param_3 + 0x290) + *(float *)(param_3 + 0x284)) * 0.5;

  iVar1 = object_0046e830(param_1,param_2);

  if (iVar1 != 0) {

    iVar2 = reaper_0052e4a0(param_1);

    if (iVar2 != 0) {

      local_18 = local_24;

      local_10 = param_5;

      local_20 = local_2c;

      local_4 = *(undefined4 *)(param_3 + 0x188);

      local_1c = local_28;

      local_c = *(undefined4 *)(iVar1 + 0x188);

      local_14 = param_4;

      local_8 = *(undefined4 *)(param_2 + 0x188);

      reaper_00530bd0(param_1,5,3,0,6,&local_20);

    }

    FUN_0046e120(iVar1,&LAB_0045afe0);

    if (param_5 != 0.0) {

      *(float *)(param_2 + 0xc4) = *(float *)(param_2 + 0xc4) / param_5;

    }

    *(undefined4 *)(param_2 + 0x210) = 0;

    if (*(int *)(param_2 + 0x1e0) == 0x59) {

      if (*(int *)(param_2 + 0x218) < 2) {

        FUN_00425850(param_2);

      }

    }

    else if (*(int *)(param_2 + 0x1e0) == 0x12) {

      FUN_004f4150();

    }

    else {

      iVar2 = ObjIsReaper(param_2);

      if (iVar2 != 0) {

        *(undefined4 *)(param_2 + 0xc4) = *(undefined4 *)(*(int *)(param_2 + 0x100) + 0xfac);

      }

    }

    *(uint *)(param_2 + 0xd8) = *(uint *)(param_2 + 0xd8) & 0xfff7ffff | 0x10000000;

    *(int *)(param_2 + 0x210) = iVar1;

    *(undefined4 *)(param_2 + 0x218) = 0xffffffff;

    FUN_0050a610(iVar1 + 0xa0,&local_2c);

    fVar3 = (float10)FUN_00543e70();

    FUN_0046e9d0(iVar1,&local_2c,param_3,(float)(fVar3 / (float10)param_4),0x3f400000);

  }

  return;

}

/* ===== FUN_0045b610 @ 0x0045B610 ===== */
float10 FUN_0045b610(undefined4 param_1,int param_2,float param_3)



{

  int iVar1;

  int *piVar2;

  

  piVar2 = &DAT_0055a168;

  if (-1 < DAT_0055a168) {

    iVar1 = DAT_0055a168;

    do {

      if (iVar1 == *(int *)(param_2 + 4)) break;

      iVar1 = piVar2[0xe];

      piVar2 = piVar2 + 0xe;

    } while (-1 < iVar1);

  }

  if (*piVar2 == *(int *)(param_2 + 4)) {

    return (float10)param_3 * (float10)0.33333334 * (float10)(float)piVar2[2] +

           ((float10)1.0 - (float10)param_3 * (float10)0.33333334) * (float10)(float)piVar2[1];

  }

  return (float10)1.0;

}

/* ===== reaper_lock_short_5 @ 0x0045B670 ===== */
void reaper_lock_short_5(undefined4 param_1,int param_2,float param_3,int param_4,int param_5)



{

  int iVar1;

  int *piVar2;

  float local_c;

  undefined4 local_8;

  undefined1 local_4;

  

  iVar1 = ObjIsReaper(param_2);

  if (iVar1 == 0) {

    if (*(int *)(param_2 + 0x1e0) == 99) {

      FUN_004cc7a0(param_2);

    }

  }

  else {

    obj_snap_variant_c(param_2);

  }

  if ((param_5 != 0) && (iVar1 = reaper_0052e4a0(param_1), iVar1 != 0)) {

    local_8 = *(undefined4 *)(param_2 + 0x188);

    local_c = param_3;

    local_4 = (undefined1)param_4;

    reaper_00530bd0(param_1,1,1,1,7,&local_c);

  }

  *(undefined4 *)(param_2 + 0x210) = param_1;

  *(int *)(param_2 + 0x218) = param_4;

  piVar2 = &DAT_0055a168;

  if (-1 < DAT_0055a168) {

    iVar1 = DAT_0055a168;

    do {

      if (iVar1 == *(int *)(param_2 + 4)) break;

      iVar1 = piVar2[0xe];

      piVar2 = piVar2 + 0xe;

    } while (-1 < iVar1);

  }

  if (*piVar2 == *(int *)(param_2 + 4)) {

    *(int *)(param_2 + 0x214) = piVar2[param_4 + 3];

    if (*(int *)(param_2 + 0x10) != piVar2[param_4 + 8]) {

      ObjectSetAnim(param_2,piVar2[param_4 + 8],0x21,0,0,0);

    }

  }

  else {

    *(undefined4 *)(param_2 + 0x214) = 0xffffffff;

  }

  *(float *)(param_2 + 0xc4) = param_3 * *(float *)(param_2 + 0xc4);

  if (((param_4 < 2) && ((*(byte *)(param_2 + 0x1c8) & 1) != 0)) &&

     (iVar1 = fx_create(param_1), iVar1 != 0)) {

    obj_damage_apply(2,0x41a00000,param_2,param_1,0,0);

  }

  return;

}

/* ===== reaper_lock_short_6 @ 0x0045B7A0 ===== */
void reaper_lock_short_6(undefined4 param_1,int param_2)



{

  undefined4 uVar1;

  int iVar2;

  int iVar3;

  

  uVar1 = param_1;

  iVar3 = reaper_0052e4a0(param_1);

  iVar2 = param_2;

  if (iVar3 != 0) {

    param_1 = *(undefined4 *)(param_2 + 0x188);

    reaper_00530bd0(uVar1,0,1,0,0xc,&param_1);

  }

  object_destroy(iVar2);

  return;

}

/* ===== FUN_0045b7f0 @ 0x0045B7F0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* PS2 candidate: FootDust (conf 0.415) */



void FUN_0045b7f0(float param_1,float param_2,float param_3,float param_4)



{

  float fVar1;

  int iVar2;

  float10 fVar3;

  float10 fVar4;

  undefined1 auStack_44 [4];

  float fStack_40;

  float fStack_3c;

  float fStack_38;

  float local_34;

  float fStack_30;

  float fStack_2c;

  float fStack_28;

  float fStack_24;

  float fStack_20;

  undefined4 local_1c;

  undefined4 local_18;

  undefined4 local_14;

  float fStack_10;

  float fStack_c;

  float fStack_8;

  float fStack_4;

  

  fVar1 = param_1;

  iVar2 = (int)param_2 * 0x44 + *(int *)((int)param_1 + 0x2dc);

  local_1c = *(undefined4 *)(iVar2 + 0x10);

  local_18 = *(undefined4 *)(iVar2 + 0x20);

  local_14 = *(undefined4 *)(iVar2 + 0x30);

  (*(code *)PTR_S_GEO_Vec3Transform_00580c20)(&local_34,&local_1c,1,(int)param_1 + 0x294);

  physics_vec_math(&local_34,&fStack_10,0,auStack_44,1);

  fStack_4 = fStack_10 * local_34 + fStack_c * fStack_30 + fStack_8 * fStack_2c + fStack_4;

  if (fStack_4 < 12.0) {

    fStack_40 = local_34 - fStack_10 * fStack_4;

    fStack_3c = fStack_30 - fStack_c * fStack_4;

    fStack_38 = fStack_2c - fStack_8 * fStack_4;

    local_34 = fStack_40;

    fStack_30 = fStack_3c;

    fStack_2c = fStack_38;

    if (param_3 == 0.0) {

      param_2 = *(float *)(*(int *)((int)fVar1 + 0x104) + 0x24) * 0.01;

      GEO_Vec2Cross(&fStack_28,&DAT_0055abbc,&fStack_10);

      GEO_Vec3Normalize(&fStack_28,&fStack_28);

      GEO_Vec2Cross(&DAT_0055abbc,&fStack_10,&fStack_28);

      fVar3 = (float10)rndfloatrange(0,0x43b40000);

      fVar4 = (float10)rndfloatrange(0,0x41200000);

      fVar1 = (float)fVar4;

      sine_cos_lookup((float)fVar3,&param_3,&param_1);

      fStack_40 = (param_3 * _DAT_0055abbc + fStack_28 * param_1) * fVar1 * param_2 + fStack_40;

      fStack_3c = (param_3 * _DAT_0055abc0 + fStack_24 * param_1) * fVar1 * param_2 + fStack_3c;

      fStack_38 = (param_3 * _DAT_0055abc4 + fStack_20 * param_1) * fVar1 * param_2 + fStack_38;

    }

    else {

      param_2 = (1.0 - fStack_8) *

                SQRT(*(float *)((int)fVar1 + 0x110) * *(float *)((int)fVar1 + 0x110) +

                     *(float *)((int)fVar1 + 0x10c) * *(float *)((int)fVar1 + 0x10c)) * 0.04;

    }

    if (0.4 < param_2) {

      fStack_40 = param_2 * fStack_10 * 6.0 + fStack_40;

      fStack_3c = param_2 * fStack_c * 6.0 + fStack_3c;

      fStack_38 = param_2 * fStack_8 * 6.0 + fStack_38;

      make_dust_ball(&fStack_40,param_2 * param_4);

      return;

    }

  }

  return;

}

/* ===== AttackObject__FP6OBJECTT0P3P3DT2fi @ 0x0045BA70 ===== */
void AttackObject__FP6OBJECTT0P3P3DT2fi

               (int param_1,int param_2,float *param_3,undefined4 *param_4,float param_5,

               byte param_6)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  undefined4 uVar5;

  float10 fVar6;

  char *pcVar7;

  float local_38;

  float local_34;

  float local_30;

  byte local_2c;

  float local_28;

  float local_24;

  float local_20;

  float local_1c;

  undefined4 local_18;

  undefined4 local_14;

  undefined4 local_10;

  undefined4 local_c;

  byte local_4;

  

  iVar2 = param_2;

  if (param_2 == 0) {

    return;

  }

  iVar3 = ObjIsKabuto(param_1);

  iVar4 = param_1;

  if ((iVar3 == 0) && (iVar3 = FUN_004a61c0(param_1), iVar3 == 0)) {

    iVar4 = ObjIsKabuto(*(undefined4 *)(param_1 + 0x274));

    if ((iVar4 == 0) && (iVar4 = FUN_004a61c0(*(undefined4 *)(param_1 + 0x274)), iVar4 == 0)) {

      return;

    }

    iVar4 = *(int *)(param_1 + 0x274);

  }

  if (iVar4 == 0) {

    return;

  }

  iVar3 = *(int *)(param_2 + 4);

  iVar1 = *(int *)(iVar4 + 0x100);

  if ((((iVar3 == 0x4b7) && (*(float *)(iVar1 + 0x15c) < 1.0)) ||

      ((iVar3 == 0x4b8 && (*(float *)(iVar1 + 0x15c) < 2.0)))) ||

     ((iVar3 == 0x4b9 && (*(float *)(iVar1 + 0x15c) < 3.0)))) {

    pcVar7 = s_Kabutomessage1_0055b308;

LAB_0045bb57:

    uVar5 = FUN_00507b00(pcVar7,0x3f000000,0x3e4ccccd,0x3f000000,0x3f800000,0x40a00000,1);

    FUN_00446f70(uVar5);

    return;

  }

  if ((iVar3 == 0x4fd) && ((~param_6 & 0x40) != 0)) {

    pcVar7 = s_Kabutomessage2_0055b2f8;

    goto LAB_0045bb57;

  }

  iVar3 = reaper_0052e4a0(iVar4);

  if (((iVar3 != 0) && (*(int *)(iVar4 + 0x1e0) == 1)) && ((~param_6 & 0x20) != 0)) {

    if (param_3 == (float *)0x0) {

      local_34 = *(float *)(param_2 + 0x188);

      local_38 = param_5;

      local_2c = param_6;

      reaper_00530bd0(iVar4,1,2,1,5,&local_38);

      goto LAB_0045bd2c;

    }

    local_c = *(undefined4 *)(param_2 + 0x188);

    local_28 = param_5;

    local_24 = *param_3;

    local_20 = param_3[1];

    local_1c = param_3[2];

    local_18 = *param_4;

    local_14 = param_4[1];

    local_10 = param_4[2];

    local_4 = param_6;

    reaper_00530bd0(iVar4,7,2,1,4,&local_28);

  }

  if (param_3 != (float *)0x0) {

    if ((~param_6 & 0x10) != 0) {

      iVar3 = ObjIsKabuto(iVar4);

      if (iVar3 == 0) {

        param_2 = 0x3f800000;

      }

      else {

        param_2 = *(undefined4 *)(*(int *)(iVar4 + 0x100) + 0x1d0);

      }

      iVar4 = 3;

      do {

        local_38 = *param_3;

        local_34 = param_3[1];

        local_30 = param_3[2];

        fVar6 = (float10)rndfloatrange(0xc1200000,0x41200000);

        local_38 = (float)(fVar6 + (float10)local_38);

        fVar6 = (float10)rndfloatrange(0xc1200000,0x41200000);

        local_34 = (float)(fVar6 + (float10)local_34);

        fVar6 = (float10)rndfloatrange(0xc1200000,0x41200000);

        local_30 = (float)(fVar6 + (float10)local_30);

        make_dust_ball(&local_38,param_2);

        iVar4 = iVar4 + -1;

      } while (iVar4 != 0);

    }

    anm_binder_free(param_3,*(undefined1 *)(iVar2 + 0x1f5),0,6);

  }

LAB_0045bd2c:

  if ((param_6 & 0xc) == 0) {

    iVar4 = fx_create(param_1);

    if (iVar4 != 0) {

      obj_damage_apply(4,param_5,iVar2,param_1,param_3,0);

    }

  }

  else {

    iVar4 = fx_create(param_1);

    if (iVar4 != 0) {

      obj_damage_apply(6,param_5,iVar2,param_1,param_3,0);

      return;

    }

  }

  return;

}

/* ===== FUN_0045bd90 @ 0x0045BD90 ===== */
undefined4 FUN_0045bd90(int param_1,float param_2,byte param_3)



{

  int iVar1;

  int iVar2;

  

  iVar1 = (int)param_2;

  if ((param_2 != 0.0) && ((~*(uint *)((int)param_2 + 0x1cc) & 1) != 0)) {

    if (((*(uint *)((int)param_2 + 0x1cc) & 0x3c00000) != 0) && ((param_3 & 1) != 0)) {

      param_2 = *(float *)(DAT_00632ed8 + 0x119c);

      iVar2 = fx_create(param_1);

      if (iVar2 != 0) {

        if ((param_1 != 0) && (*(int *)(param_1 + 0x1e0) == 1)) {

          param_2 = param_2 * *(float *)(*(int *)(param_1 + 0x100) + 0x1d0);

        }

        obj_damage_apply(0xb,param_2,iVar1,param_1,0,0);

      }

    }

    if ((~*(uint *)(iVar1 + 0x1cc) & 2) != 0) {

      *(int *)(iVar1 + 0x220) = param_1;

      return 0;

    }

  }

  return 0;

}

/* ===== reaper_spell_user @ 0x0045BF10 ===== */
void reaper_spell_user(int param_1,int param_2,float *param_3)



{

  float fVar1;

  int iVar2;

  float local_1c;

  float local_18;

  float local_14;

  float local_10;

  float local_c;

  float local_8;

  undefined4 local_4;

  

  if ((param_2 != 0) &&

     ((((iVar2 = *(int *)(param_2 + 0x1e0), iVar2 == 0x12 || (iVar2 == 0x17)) || (iVar2 == 0x15)) ||

      (((iVar2 == 0x33 || (iVar2 == 0x35)) || ((iVar2 == 3 || (iVar2 == 2)))))))) {

    if (param_3 == (float *)0x0) {

      param_3 = &local_1c;

      fVar1 = (3.0 / *(float *)(param_1 + 0xc4)) * *(float *)(*(int *)(param_1 + 0x104) + 0x24);

      local_1c = -(fVar1 * *(float *)(param_1 + 0x29c));

      local_18 = -(fVar1 * *(float *)(param_1 + 0x2ac));

      local_14 = fVar1 * 0.25;

    }

    *(float *)(param_2 + 0x128) = *(float *)(param_2 + 0x128) + *param_3;

    *(float *)(param_2 + 300) = param_3[1] + *(float *)(param_2 + 300);

    *(float *)(param_2 + 0x130) = param_3[2] + *(float *)(param_2 + 0x130);

    iVar2 = reaper_0052e4a0(param_1);

    if (iVar2 != 0) {

      local_c = param_3[1];

      local_10 = *param_3;

      local_4 = *(undefined4 *)(param_2 + 0x188);

      local_8 = param_3[2];

      reaper_00530bd0(param_1,3,1,0,0xd,&local_10);

    }

  }

  return;

}

/* ===== obj_lod_lerp_update @ 0x0045C3E0 ===== */
void obj_lod_lerp_update(int param_1)



{

  float fVar1;

  float fVar2;

  int iVar3;

  float fVar4;

  

  iVar3 = *(int *)(param_1 + 0x100);

  if (*(int *)(iVar3 + 0x354) == 0) {

    fVar2 = (*(float *)(iVar3 + 0x15c) + 1.0) * 0.25;

    *(float *)(iVar3 + 0x1d0) = fVar2;

    fVar4 = *(float *)(iVar3 + 0x15c) * 0.33333334;

    if (*(int *)(iVar3 + 0x154) != 0) {

      fVar1 = *(float *)(iVar3 + 0x15c);

      if (fVar1 < 1.0 == (fVar1 == 1.0)) {

        if (fVar1 < 2.0 == (fVar1 == 2.0)) {

          fVar1 = (3.0 - fVar1) * *(float *)(DAT_00632ed8 + 0x1338) +

                  (fVar1 - 2.0) * *(float *)(DAT_00632ed8 + 0x133c);

        }

        else {

          fVar1 = (fVar1 - 1.0) * *(float *)(DAT_00632ed8 + 0x1338) +

                  (2.0 - fVar1) * *(float *)(DAT_00632ed8 + 0x1334);

        }

      }

      else {

        fVar1 = fVar1 * *(float *)(DAT_00632ed8 + 0x1334) +

                (1.0 - fVar1) * *(float *)(DAT_00632ed8 + 0x9f4);

      }

      *(float *)(iVar3 + 0x164) = fVar1;

      fVar1 = *(float *)(iVar3 + 0x15c);

      if (fVar1 < 1.0 == (fVar1 == 1.0)) {

        if (fVar1 < 2.0 == (fVar1 == 2.0)) {

          fVar1 = (3.0 - fVar1) * *(float *)(DAT_00632ed8 + 0x1350) +

                  (fVar1 - 2.0) * *(float *)(DAT_00632ed8 + 0x1354);

        }

        else {

          fVar1 = (fVar1 - 1.0) * *(float *)(DAT_00632ed8 + 0x1350) +

                  (2.0 - fVar1) * *(float *)(DAT_00632ed8 + 0x134c);

        }

      }

      else {

        fVar1 = fVar1 * *(float *)(DAT_00632ed8 + 0x134c) +

                (1.0 - fVar1) * *(float *)(DAT_00632ed8 + 0x9f8);

      }

      *(float *)(iVar3 + 0x168) = fVar1;

      fVar1 = *(float *)(iVar3 + 0x15c);

      if (fVar1 < 1.0 == (fVar1 == 1.0)) {

        if (fVar1 < 2.0 == (fVar1 == 2.0)) {

          fVar1 = (3.0 - fVar1) * *(float *)(DAT_00632ed8 + 0x1344) +

                  (fVar1 - 2.0) * *(float *)(DAT_00632ed8 + 0x1348);

        }

        else {

          fVar1 = (fVar1 - 1.0) * *(float *)(DAT_00632ed8 + 0x1344) +

                  (2.0 - fVar1) * *(float *)(DAT_00632ed8 + 0x1340);

        }

      }

      else {

        fVar1 = fVar1 * *(float *)(DAT_00632ed8 + 0x1340) +

                (1.0 - fVar1) * *(float *)(DAT_00632ed8 + 0x9fc);

      }

      *(float *)(iVar3 + 0x16c) = fVar1;

      fVar1 = *(float *)(iVar3 + 0x15c);

      if (fVar1 < 1.0 == (fVar1 == 1.0)) {

        if (fVar1 < 2.0 == (fVar1 == 2.0)) {

          fVar1 = (3.0 - fVar1) * *(float *)(DAT_00632ed8 + 0x135c) +

                  (fVar1 - 2.0) * *(float *)(DAT_00632ed8 + 0x1360);

        }

        else {

          fVar1 = (fVar1 - 1.0) * *(float *)(DAT_00632ed8 + 0x135c) +

                  (2.0 - fVar1) * *(float *)(DAT_00632ed8 + 0x1358);

        }

      }

      else {

        fVar1 = fVar1 * *(float *)(DAT_00632ed8 + 0x1358) +

                (1.0 - fVar1) * *(float *)(DAT_00632ed8 + 0xa00);

      }

      *(float *)(iVar3 + 0x170) = fVar1;

      *(undefined4 *)(iVar3 + 0x174) = *(undefined4 *)(DAT_00632ed8 + 0x9d4);

      *(undefined4 *)(iVar3 + 0x178) = *(undefined4 *)(DAT_00632ed8 + 0x9d8);

      *(undefined4 *)(iVar3 + 0x17c) = *(undefined4 *)(DAT_00632ed8 + 0x9dc);

      *(float *)(iVar3 + 0x180) = *(float *)(DAT_00632ed8 + 0x1220) * fVar2;

      *(float *)(iVar3 + 0x184) = *(float *)(DAT_00632ed8 + 0x1224) * fVar2;

      *(float *)(iVar3 + 0x188) = *(float *)(DAT_00632ed8 + 0x1228) * fVar2;

      *(float *)(iVar3 + 0x18c) = *(float *)(DAT_00632ed8 + 0x122c) * fVar2;

      *(float *)(iVar3 + 400) = *(float *)(DAT_00632ed8 + 0x118c) * fVar2;

      *(float *)(iVar3 + 0x194) = *(float *)(DAT_00632ed8 + 0x1190) * fVar2;

      *(float *)(iVar3 + 0x198) =

           *(float *)(DAT_00632ed8 + 0x15d8) * (1.0 - fVar4) +

           *(float *)(DAT_00632ed8 + 0x15e0) * fVar4;

      *(float *)(iVar3 + 0x19c) = fVar2 * 20.0;

      *(float *)(iVar3 + 0x1b8) = fVar2 * *(float *)(DAT_00632ed8 + 0x3a8);

      *(float *)(iVar3 + 0x1bc) = fVar2 * *(float *)(DAT_00632ed8 + 0x3ac);

      *(float *)(iVar3 + 0x1c0) = fVar2 * *(float *)(DAT_00632ed8 + 0x3b0);

      *(float *)(iVar3 + 0x1c4) = fVar2 * *(float *)(DAT_00632ed8 + 0x3b4);

      *(float *)(iVar3 + 0x1c8) = fVar2 * 200.0;

      *(float *)(iVar3 + 0x1cc) = fVar2 * 2500.0;

      fVar2 = *(float *)(iVar3 + 0x15c);

      if (fVar2 < 1.0 == (fVar2 == 1.0)) {

        if (fVar2 < 2.0 == (fVar2 == 2.0)) {

          fVar2 = (3.0 - fVar2) * *(float *)(DAT_00632ed8 + 0x11bc) +

                  (fVar2 - 2.0) * *(float *)(DAT_00632ed8 + 0x11c0);

        }

        else {

          fVar2 = (fVar2 - 1.0) * *(float *)(DAT_00632ed8 + 0x11bc) +

                  (2.0 - fVar2) * *(float *)(DAT_00632ed8 + 0x11b8);

        }

      }

      else {

        fVar2 = fVar2 * *(float *)(DAT_00632ed8 + 0x11b8) +

                (1.0 - fVar2) * *(float *)(DAT_00632ed8 + 0x11b4);

      }

      *(float *)(iVar3 + 0x1a0) = fVar2;

      fVar2 = *(float *)(iVar3 + 0x15c);

      if (fVar2 < 1.0 == (fVar2 == 1.0)) {

        if (fVar2 < 2.0 == (fVar2 == 2.0)) {

          fVar2 = (3.0 - fVar2) * *(float *)(DAT_00632ed8 + 0x11cc) +

                  (fVar2 - 2.0) * *(float *)(DAT_00632ed8 + 0x11d0);

        }

        else {

          fVar2 = (fVar2 - 1.0) * *(float *)(DAT_00632ed8 + 0x11cc) +

                  (2.0 - fVar2) * *(float *)(DAT_00632ed8 + 0x11c8);

        }

      }

      else {

        fVar2 = fVar2 * *(float *)(DAT_00632ed8 + 0x11c8) +

                (1.0 - fVar2) * *(float *)(DAT_00632ed8 + 0x11c4);

      }

      *(float *)(iVar3 + 0x1a4) = fVar2;

      fVar2 = *(float *)(iVar3 + 0x15c);

      if (fVar2 < 1.0 == (fVar2 == 1.0)) {

        if (fVar2 < 2.0 == (fVar2 == 2.0)) {

          fVar4 = (fVar2 - 2.0) * *(float *)(DAT_00632ed8 + 0x11e0);

          fVar2 = (3.0 - fVar2) * *(float *)(DAT_00632ed8 + 0x11dc);

        }

        else {

          fVar4 = (fVar2 - 1.0) * *(float *)(DAT_00632ed8 + 0x11dc);

          fVar2 = (2.0 - fVar2) * *(float *)(DAT_00632ed8 + 0x11d8);

        }

        fVar2 = fVar2 + fVar4;

      }

      else {

        fVar2 = fVar2 * *(float *)(DAT_00632ed8 + 0x11d8) +

                (1.0 - fVar2) * *(float *)(DAT_00632ed8 + 0x11d4);

      }

      *(float *)(iVar3 + 0x1a8) = fVar2;

      fVar2 = *(float *)(iVar3 + 0x15c);

      if (fVar2 < 1.0 == (fVar2 == 1.0)) {

        if (fVar2 < 2.0 == (fVar2 == 2.0)) {

          fVar4 = (fVar2 - 2.0) * *(float *)(DAT_00632ed8 + 0x11f0);

          fVar2 = (3.0 - fVar2) * *(float *)(DAT_00632ed8 + 0x11ec);

        }

        else {

          fVar4 = (fVar2 - 1.0) * *(float *)(DAT_00632ed8 + 0x11ec);

          fVar2 = (2.0 - fVar2) * *(float *)(DAT_00632ed8 + 0x11e8);

        }

        fVar2 = fVar2 + fVar4;

      }

      else {

        fVar2 = fVar2 * *(float *)(DAT_00632ed8 + 0x11e8) +

                (1.0 - fVar2) * *(float *)(DAT_00632ed8 + 0x11e4);

      }

      *(float *)(iVar3 + 0x1ac) = fVar2;

      fVar2 = *(float *)(iVar3 + 0x15c);

      if (fVar2 < 1.0 == (fVar2 == 1.0)) {

        if (fVar2 < 2.0 == (fVar2 == 2.0)) {

          fVar4 = (fVar2 - 2.0) * *(float *)(DAT_00632ed8 + 0x12c4);

          fVar2 = (3.0 - fVar2) * *(float *)(DAT_00632ed8 + 0x12c0);

        }

        else {

          fVar4 = (fVar2 - 1.0) * *(float *)(DAT_00632ed8 + 0x12c0);

          fVar2 = (2.0 - fVar2) * *(float *)(DAT_00632ed8 + 0x12bc);

        }

        fVar2 = fVar2 + fVar4;

      }

      else {

        fVar2 = fVar2 * *(float *)(DAT_00632ed8 + 0x12bc) +

                (1.0 - fVar2) * *(float *)(DAT_00632ed8 + 0x12b8);

      }

      *(float *)(iVar3 + 0x1b0) = fVar2;

      fVar2 = *(float *)(iVar3 + 0x15c);

      if (fVar2 < 1.0 == (fVar2 == 1.0)) {

        if (fVar2 < 2.0 == (fVar2 == 2.0)) {

          fVar4 = (fVar2 - 2.0) * *(float *)(DAT_00632ed8 + 0x15b4);

          fVar2 = (3.0 - fVar2) * *(float *)(DAT_00632ed8 + 0x15b0);

        }

        else {

          fVar4 = (fVar2 - 1.0) * *(float *)(DAT_00632ed8 + 0x15b0);

          fVar2 = (2.0 - fVar2) * *(float *)(DAT_00632ed8 + 0x15ac);

        }

        fVar2 = fVar2 + fVar4;

      }

      else {

        fVar2 = fVar2 * *(float *)(DAT_00632ed8 + 0x15ac) +

                (1.0 - fVar2) * *(float *)(DAT_00632ed8 + 0x15a8);

      }

      *(float *)(iVar3 + 0x1b4) = fVar2;

      fVar2 = *(float *)(iVar3 + 0x15c);

      if (fVar2 < 1.0 == (fVar2 == 1.0)) {

        if (fVar2 < 2.0 == (fVar2 == 2.0)) {

          fVar2 = (3.0 - fVar2) * *(float *)(DAT_00632ed8 + 0x10cc) +

                  (fVar2 - 2.0) * *(float *)(DAT_00632ed8 + 0x10d0);

        }

        else {

          fVar2 = (2.0 - fVar2) * *(float *)(DAT_00632ed8 + 0x10c8) +

                  (fVar2 - 1.0) * *(float *)(DAT_00632ed8 + 0x10cc);

        }

      }

      else {

        fVar2 = fVar2 * *(float *)(DAT_00632ed8 + 0x10c8) +

                (1.0 - fVar2) * *(float *)(DAT_00632ed8 + 0x10c4);

      }

      *(float *)(param_1 + 0xc4) = fVar2 * *(float *)(*(int *)(iVar3 + 0x154) + 0xc4);

      *(undefined4 *)(iVar3 + 0x1d4) = *(undefined4 *)(DAT_00632ed8 + 0x1230);

      *(undefined4 *)(iVar3 + 0x1d8) = *(undefined4 *)(DAT_00632ed8 + 0x1234);

      *(undefined4 *)(iVar3 + 0x1f0) = *(undefined4 *)(DAT_00632ed8 + 0x12c8);

      *(undefined4 *)(iVar3 + 500) = *(undefined4 *)(DAT_00632ed8 + 0x12cc);

      *(undefined4 *)(iVar3 + 0x1f8) = *(undefined4 *)(DAT_00632ed8 + 0x12d4);

      *(undefined4 *)(iVar3 + 0x1fc) = *(undefined4 *)(DAT_00632ed8 + 0x12d0);

      *(undefined4 *)(iVar3 + 0x200) = *(undefined4 *)(DAT_00632ed8 + 0x12dc);

      *(undefined4 *)(iVar3 + 0x204) = *(undefined4 *)(DAT_00632ed8 + 0x12d8);

      *(undefined4 *)(iVar3 + 0x208) = *(undefined4 *)(DAT_00632ed8 + 0x12e0);

      *(undefined4 *)(iVar3 + 0x20c) = *(undefined4 *)(DAT_00632ed8 + 0x12e4);

      *(undefined4 *)(iVar3 + 0x210) = *(undefined4 *)(DAT_00632ed8 + 0x12e8);

      *(undefined4 *)(iVar3 + 0x214) = *(undefined4 *)(DAT_00632ed8 + 0x12ec);

      *(undefined4 *)(iVar3 + 0x218) = *(undefined4 *)(DAT_00632ed8 + 0x12f0);

      *(undefined4 *)(iVar3 + 0x21c) = *(undefined4 *)(DAT_00632ed8 + 0x12f4);

      fVar2 = *(float *)(iVar3 + 0x15c);

      if (fVar2 < 1.0 == (fVar2 == 1.0)) {

        if (fVar2 < 2.0 == (fVar2 == 2.0)) {

          fVar4 = (fVar2 - 2.0) * *(float *)(DAT_00632ed8 + 0x130c);

          fVar2 = (3.0 - fVar2) * *(float *)(DAT_00632ed8 + 0x1308);

        }

        else {

          fVar4 = (fVar2 - 1.0) * *(float *)(DAT_00632ed8 + 0x1308);

          fVar2 = (2.0 - fVar2) * *(float *)(DAT_00632ed8 + 0x1304);

        }

        fVar2 = fVar2 + fVar4;

      }

      else {

        fVar2 = fVar2 * *(float *)(DAT_00632ed8 + 0x1304) +

                (1.0 - fVar2) * *(float *)(DAT_00632ed8 + 0x1238);

      }

      *(float *)(iVar3 + 0x1dc) = fVar2;

      fVar2 = *(float *)(iVar3 + 0x15c);

      if (fVar2 < 1.0 == (fVar2 == 1.0)) {

        if (fVar2 < 2.0 == (fVar2 == 2.0)) {

          fVar4 = (fVar2 - 2.0) * *(float *)(DAT_00632ed8 + 0x1318);

          fVar2 = (3.0 - fVar2) * *(float *)(DAT_00632ed8 + 0x1314);

        }

        else {

          fVar4 = (fVar2 - 1.0) * *(float *)(DAT_00632ed8 + 0x1314);

          fVar2 = (2.0 - fVar2) * *(float *)(DAT_00632ed8 + 0x1310);

        }

        fVar2 = fVar2 + fVar4;

      }

      else {

        fVar2 = fVar2 * *(float *)(DAT_00632ed8 + 0x1310) +

                (1.0 - fVar2) * *(float *)(DAT_00632ed8 + 0x123c);

      }

      *(float *)(iVar3 + 0x1e0) = fVar2;

      fVar2 = *(float *)(iVar3 + 0x15c);

      if (fVar2 < 1.0 == (fVar2 == 1.0)) {

        if (fVar2 < 2.0 == (fVar2 == 2.0)) {

          fVar4 = (fVar2 - 2.0) * *(float *)(DAT_00632ed8 + 0x1300);

          fVar2 = (3.0 - fVar2) * *(float *)(DAT_00632ed8 + 0x12fc);

        }

        else {

          fVar4 = (fVar2 - 1.0) * *(float *)(DAT_00632ed8 + 0x12fc);

          fVar2 = (2.0 - fVar2) * *(float *)(DAT_00632ed8 + 0x12f8);

        }

        fVar2 = fVar2 + fVar4;

      }

      else {

        fVar2 = fVar2 * *(float *)(DAT_00632ed8 + 0x12f8) +

                (1.0 - fVar2) * *(float *)(DAT_00632ed8 + 0x1240);

      }

      *(float *)(iVar3 + 0x1e4) = fVar2;

      fVar2 = *(float *)(iVar3 + 0x15c);

      if (fVar2 < 1.0 == (fVar2 == 1.0)) {

        if (fVar2 < 2.0 == (fVar2 == 2.0)) {

          fVar2 = (3.0 - fVar2) * *(float *)(DAT_00632ed8 + 0x132c) +

                  (fVar2 - 2.0) * *(float *)(DAT_00632ed8 + 0x1330);

        }

        else {

          fVar2 = (fVar2 - 1.0) * *(float *)(DAT_00632ed8 + 0x132c) +

                  (2.0 - fVar2) * *(float *)(DAT_00632ed8 + 0x1328);

        }

      }

      else {

        fVar2 = fVar2 * *(float *)(DAT_00632ed8 + 0x1328) +

                (1.0 - fVar2) * *(float *)(DAT_00632ed8 + 0x1244);

      }

      *(float *)(iVar3 + 0x1e8) = fVar2;

      fVar2 = *(float *)(iVar3 + 0x15c);

      if (fVar2 < 1.0 == (fVar2 == 1.0)) {

        if (fVar2 < 2.0 == (fVar2 == 2.0)) {

          fVar2 = (3.0 - fVar2) * *(float *)(DAT_00632ed8 + 0x1320) +

                  (fVar2 - 2.0) * *(float *)(DAT_00632ed8 + 0x1324);

        }

        else {

          fVar2 = (fVar2 - 1.0) * *(float *)(DAT_00632ed8 + 0x1320) +

                  (2.0 - fVar2) * *(float *)(DAT_00632ed8 + 0x131c);

        }

      }

      else {

        fVar2 = fVar2 * *(float *)(DAT_00632ed8 + 0x131c) +

                (1.0 - fVar2) * *(float *)(DAT_00632ed8 + 0x1248);

      }

      *(float *)(iVar3 + 0x1ec) = fVar2;

      fVar2 = *(float *)(iVar3 + 0x15c);

      if (fVar2 < 1.0 == (fVar2 == 1.0)) {

        if (fVar2 < 2.0 == (fVar2 == 2.0)) {

          fVar2 = (3.0 - fVar2) * *(float *)(DAT_00632ed8 + 0x13d8) +

                  (fVar2 - 2.0) * *(float *)(DAT_00632ed8 + 0x13dc);

        }

        else {

          fVar2 = (fVar2 - 1.0) * *(float *)(DAT_00632ed8 + 0x13d8) +

                  (2.0 - fVar2) * *(float *)(DAT_00632ed8 + 0x13d4);

        }

      }

      else {

        fVar2 = fVar2 * *(float *)(DAT_00632ed8 + 0x13d4) +

                (1.0 - fVar2) * *(float *)(DAT_00632ed8 + 0x13d0);

      }

      *(float *)(param_1 + 0x1c0) = fVar2;

      fVar2 = *(float *)(iVar3 + 0x15c);

      if (fVar2 < 1.0 == (fVar2 == 1.0)) {

        if (fVar2 < 2.0 == (fVar2 == 2.0)) {

          fVar2 = (3.0 - fVar2) * *(float *)(DAT_00632ed8 + 0x14a8) +

                  (fVar2 - 2.0) * *(float *)(DAT_00632ed8 + 0x14ac);

        }

        else {

          fVar2 = (fVar2 - 1.0) * *(float *)(DAT_00632ed8 + 0x14a8) +

                  (2.0 - fVar2) * *(float *)(DAT_00632ed8 + 0x14a4);

        }

      }

      else {

        fVar2 = fVar2 * *(float *)(DAT_00632ed8 + 0x14a4) +

                (1.0 - fVar2) * *(float *)(DAT_00632ed8 + 0x14a0);

      }

      *(float *)(iVar3 + 0x330) = fVar2;

      obj_sub100_transform(param_1);

      if (*(float *)(iVar3 + 0x158) < 1.0) {

        *(undefined4 *)(iVar3 + 0x334) = 0x10;

        *(undefined4 *)(iVar3 + 0x338) = 1;

        *(undefined4 *)(iVar3 + 0x33c) = 0x100;

        return;

      }

      if (*(float *)(iVar3 + 0x158) < 2.0) {

        *(undefined4 *)(iVar3 + 0x334) = 0x20;

        *(undefined4 *)(iVar3 + 0x338) = 2;

        *(undefined4 *)(iVar3 + 0x33c) = 0x200;

        return;

      }

      if (3.0 <= *(float *)(iVar3 + 0x158)) {

        *(undefined4 *)(iVar3 + 0x334) = 0x80;

        *(undefined4 *)(iVar3 + 0x338) = 8;

        *(undefined4 *)(iVar3 + 0x33c) = 0x800;

        return;

      }

      *(undefined4 *)(iVar3 + 0x334) = 0x40;

      *(undefined4 *)(iVar3 + 0x338) = 4;

      *(undefined4 *)(iVar3 + 0x33c) = 0x400;

      return;

    }

  }

  return;

}

/* ===== reaper_ability_playersound4 @ 0x0045D190 ===== */
void reaper_ability_playersound4(int param_1,byte param_2,undefined4 param_3)



{

  float fVar1;

  char cVar2;

  int iVar3;

  int iVar4;

  

  cVar2 = (char)param_3;

  fVar1 = (float)param_2;

  iVar4 = *(int *)(param_1 + 0x100);

  if ((*(float *)(iVar4 + 0x158) != fVar1) || ((char)param_3 != '\0')) {

    sound_play_player(0x6e4,param_1);

    iVar3 = reaper_0052e4a0(param_1);

    if (iVar3 != 0) {

      param_3 = 0x6e4;

      reaper_00530bd0(param_1,0,1,0,0x11,&param_3);

    }

    *(float *)(iVar4 + 0x158) = fVar1;

    if (cVar2 != '\0') {

      *(float *)(iVar4 + 0x15c) = fVar1;

      obj_lod_lerp_update(param_1);

    }

    iVar4 = reaper_0052e4a0(param_1);

    if (iVar4 != 0) {

      param_3._0_2_ = CONCAT11(cVar2,param_2);

      reaper_00530bd0(param_1,0,0,2,0xb,&param_3);

    }

  }

  return;

}

/* ===== FUN_0045d290 @ 0x0045D290 ===== */
byte FUN_0045d290(int param_1)



{

  byte *pbVar1;

  

  if ((((param_1 != 0) && (*(int *)(param_1 + 0x1e0) == 1)) &&

      (pbVar1 = *(byte **)(param_1 + 0x100), pbVar1 != (byte *)0x0)) && ((*pbVar1 & 1) != 0)) {

    return pbVar1[0x228];

  }

  return 0;

}

/* ===== AddHud__4cHudP8cHudIcon @ 0x0045D2C0 ===== */
void AddHud__4cHudP8cHudIcon(void)



{

  __ftol();

  return;

}

/* ===== FUN_0045d2e0 @ 0x0045D2E0 ===== */
float10 FUN_0045d2e0(int param_1)



{

  if ((**(byte **)(param_1 + 0x100) & 1) != 0) {

    return (float10)*(float *)(*(byte **)(param_1 + 0x100) + 0x1d0);

  }

  return (float10)1.0;

}

/* ===== kabuto_init @ 0x0045D300 ===== */
/* PS2 candidate: kabuto_init (conf 0.461) */



undefined4 kabuto_init(uint *param_1)



{

  int *piVar1;

  uint *puVar2;

  uint *puVar3;

  int iVar4;

  int iVar5;

  uint uVar6;

  int *piVar7;

  uint *puVar8;

  int local_4;

  

  puVar3 = param_1;

  puVar2 = (uint *)param_1[0x40];

  if (param_1[0x3a] != 0) {

    object_change_ospec(param_1,0xf);

    return 0;

  }

  if (DAT_0059da20 == 0) {

    world_reset_callback_add(&LAB_0045d870);

    if (DAT_0055a4d8 != 0xfe) {

      piVar7 = &DAT_0055a4e4;

      do {

        if (-1 < *piVar7) {

          iVar5 = *(int *)(puVar3[2] + 8 + piVar7[-3] * 4);

          if (iVar5 != 0) {

            iVar4 = ref_get_anode(iVar5,puVar3[2],*piVar7);

            piVar7[3] = iVar4;

            iVar5 = *(int *)(*(int *)(iVar4 + 0xc) + 0x10);

            if (piVar7[-2] < iVar5) {

              piVar7[-2] = iVar5;

            }

            iVar5 = *(int *)(*(int *)(iVar4 + 0xc) + 0x14) + -1;

            if (iVar5 < piVar7[-1]) {

              piVar7[-1] = iVar5;

            }

          }

        }

        piVar1 = piVar7 + 4;

        piVar7 = piVar7 + 7;

      } while (*piVar1 != 0xfe);

    }

    DAT_0059da20 = 1;

  }

  if ((~*puVar2 & 1) == 0) goto LAB_0045d769;

  uVar6 = FUN_00497d70(puVar3[1]);

  puVar2[0x55] = uVar6;

  puVar2[0x1f] = 0xbf800000;

  puVar2[0x1e] = 0xbf800000;

  puVar2[0x24] = 0xffffffff;

  puVar2[0x26] = 0xffffffff;

  puVar2[0x27] = 0xffffffff;

  puVar2[1] = 0;

  puVar2[0x21] = 0xfe;

  puVar2[3] = 0;

  puVar2[2] = 0;

  puVar2[0x22] = 0;

  puVar2[0x14] = 0;

  puVar2[0x17] = 0;

  puVar2[0x15] = 0;

  *(undefined2 *)(puVar2 + 0x23) = 0;

  *(undefined2 *)((int)puVar2 + 0x8e) = 0;

  puVar2[4] = 0;

  puVar2[5] = 0;

  puVar2[0x36] = 3;

  puVar2[0x33] = 0;

  puVar2[0x30] = 0;

  puVar2[0x34] = 0;

  puVar2[0x31] = 0;

  puVar2[0x35] = 0x3f800000;

  puVar2[0x32] = 0x3f800000;

  puVar2[0x38] = 0;

  puVar2[0x4b] = 0;

  puVar2[0x4c] = 0;

  puVar2[0x4a] = 0x3f800000;

  puVar2[0x4d] = 0x3f800000;

  puVar2[0x4e] = 0;

  puVar2[0x4f] = 0;

  puVar2[0x50] = 0;

  puVar2[0x58] = puVar2[0x59];

  iVar5 = object_allocate_type(0x2ed,1);

  *(uint **)(iVar5 + 0x210) = puVar3;

  *(undefined4 *)(iVar5 + 0x214) = 0;

  *(undefined4 *)(iVar5 + 0x218) = 10;

  *(uint *)(iVar5 + 0x18c) = puVar3[99];

  *(uint *)(iVar5 + 0x1c8) = *(uint *)(iVar5 + 0x1c8) | 0x24000000;

  *(uint *)(iVar5 + 0xd8) = *(uint *)(iVar5 + 0xd8) | 0x400000;

  *(uint *)(iVar5 + 0xdc) = *(uint *)(iVar5 + 0xdc) | 0x2000000;

  uVar6 = object_allocate_type(0x3fa,1);

  puVar2[0x54] = uVar6;

  *(uint **)(uVar6 + 0x210) = puVar3;

  *(undefined4 *)(puVar2[0x54] + 0x214) = 0;

  *(undefined4 *)(puVar2[0x54] + 0x218) = 10;

  *(uint *)(puVar2[0x54] + 0x18c) = puVar3[99];

  *(uint *)(puVar2[0x54] + 0xd8) = *(uint *)(puVar2[0x54] + 0xd8) | 0x400000;

  *(uint *)(puVar2[0x54] + 0x1c8) = *(uint *)(puVar2[0x54] + 0x1c8) | 0x20000000;

  *(uint *)(puVar2[0x54] + 0xdc) = *(uint *)(puVar2[0x54] + 0xdc) | 0x2000000;

  param_1 = puVar2 + 0x8b;

  local_4 = 8;

  do {

    uVar6 = object_allocate_type_end(0x362,0);

    object_change_ospec(uVar6,0);

    *(uint *)(uVar6 + 0x18c) = puVar3[99];

    *(uint *)(uVar6 + 0x1c8) = *(uint *)(uVar6 + 0x1c8) | 0xe00;

    *(uint *)(uVar6 + 0xd8) = *(uint *)(uVar6 + 0xd8) | 0x40010000;

    FUN_0053d9e0(uVar6 + 0x294);

    *param_1 = uVar6;

    param_1 = param_1 + 7;

    local_4 = local_4 + -1;

  } while (local_4 != 0);

  uVar6 = object_allocate_type_end(0x3d4,0);

  object_change_ospec(uVar6,0);

  *(uint *)(uVar6 + 0x18c) = puVar3[99];

  *(uint *)(uVar6 + 0x1c8) = *(uint *)(uVar6 + 0x1c8) | 0xe00;

  *(uint *)(uVar6 + 0xd8) = *(uint *)(uVar6 + 0xd8) | 0x40010000;

  FUN_0053d9e0(uVar6 + 0x294);

  puVar2[0xc5] = uVar6;

  iVar5 = dialog_level_is_base();

  if (iVar5 == 0) {

LAB_0045d6d4:

    uVar6 = puVar3[0x40];

    sound_play_player(0x6e4,puVar3);

    iVar5 = reaper_0052e4a0(puVar3);

    if (iVar5 != 0) {

      param_1 = (uint *)0x6e4;

      reaper_00530bd0(puVar3,0,1,0,0x11,&param_1);

    }

    *(undefined4 *)(uVar6 + 0x158) = 0;

    *(undefined4 *)(uVar6 + 0x15c) = 0;

    obj_lod_lerp_update(puVar3);

    iVar5 = reaper_0052e4a0(puVar3);

    if (iVar5 != 0) {

      param_1 = (uint *)((uint)param_1 & 0xffffff00);

LAB_0045d736:

      param_1._0_2_ = CONCAT11(1,param_1._0_1_);

      reaper_00530bd0(puVar3,0,0,2,0xb,&param_1);

    }

  }

  else {

    iVar5 = FUN_005213a0(DAT_00632f18);

    if (iVar5 == 0) goto LAB_0045d6d4;

    uVar6 = puVar3[0x40];

    sound_play_player(0x6e4,puVar3);

    iVar5 = reaper_0052e4a0(puVar3);

    if (iVar5 != 0) {

      param_1 = (uint *)0x6e4;

      reaper_00530bd0(puVar3,0,1,0,0x11,&param_1);

    }

    *(undefined4 *)(uVar6 + 0x158) = 0x40400000;

    *(undefined4 *)(uVar6 + 0x15c) = 0x40400000;

    obj_lod_lerp_update(puVar3);

    iVar5 = reaper_0052e4a0(puVar3);

    if (iVar5 != 0) {

      param_1 = (uint *)CONCAT31(param_1._1_3_,3);

      goto LAB_0045d736;

    }

  }

  uVar6 = FUN_00467270(puVar3,0x20,2,0x40800000);

  puVar2[0x88] = uVar6;

  *puVar2 = *puVar2 | 1;

LAB_0045d769:

  if (puVar2[0x48] != DAT_00632ed0) {

    puVar2[0x48] = DAT_00632ed0;

    if (puVar3[0x41] == 0) {

      puVar3[0x41] = (uint)(puVar2 + 0x39);

      puVar8 = puVar2 + 0x39;

      for (iVar5 = 0xf; iVar5 != 0; iVar5 = iVar5 + -1) {

        *puVar8 = 0;

        puVar8 = puVar8 + 1;

      }

      PhysicsExZeroForce(puVar3);

    }

    *(undefined4 *)(puVar3[0x41] + 8) = *(undefined4 *)(DAT_00632ed8 + 0x6b8);

    *(undefined4 *)(puVar3[0x41] + 4) = *(undefined4 *)(DAT_00632ed8 + 0x6b4);

    *(undefined4 *)(puVar3[0x41] + 0x28) = *(undefined4 *)(DAT_00632ed8 + 0x5f8);

    *(undefined4 *)(puVar3[0x41] + 0xc) = *(undefined4 *)(DAT_00632ed8 + 0x604);

    *(undefined4 *)(puVar3[0x41] + 0x30) = *(undefined4 *)(DAT_00632ed8 + 0x608);

    *(undefined4 *)(puVar3[0x41] + 0x38) = 0;

    *(undefined4 *)(puVar3[0x41] + 0x34) = 0;

    *(uint *)puVar3[0x41] = *(uint *)puVar3[0x41] | 0x400;

    puVar2[0x52] = 0;

    puVar2[0x51] = 0;

    puVar2[0x53] = (uint)((*(float *)(puVar3[0x41] + 4) / *(float *)(puVar3[0x41] + 8)) * -32.17405)

    ;

    obj_lod_lerp_update(puVar3);

  }

  return 1;

}

/* ===== FUN_0045da90 @ 0x0045DA90 ===== */
void FUN_0045da90(int param_1,int param_2,int param_3)



{

  int iVar1;

  

  if (((param_1 != 0) && (param_2 != 0)) && (param_3 != 0)) {

    iVar1 = fx_create(param_1);

    if (iVar1 != 0) {

      iVar1 = *(int *)(param_1 + 0x100);

      if (*(int *)(iVar1 + 800) == param_2) {

        *(int *)(iVar1 + 800) = param_3;

      }

      if (*(int *)(iVar1 + 0x324) == param_2) {

        *(int *)(iVar1 + 0x324) = param_3;

      }

    }

  }

  return;

}

/* ===== fx_lightning_strike @ 0x0045DAE0 ===== */
void fx_lightning_strike(float param_1)



{

  int iVar1;

  float fVar2;

  undefined4 *puVar3;

  bool bVar4;

  undefined4 *puVar5;

  float10 fVar6;

  

  iVar1 = *(int *)((int)param_1 + 0x100);

  if (*(int *)(iVar1 + 0x150) == 0) {

    return;

  }

  fVar2 = *(float *)(iVar1 + 0x330);

  if (param_1 == (float)DAT_00632a88) {

    bVar4 = false;

    param_1 = 0.0;

    for (puVar3 = DAT_00632d70; puVar5 = DAT_00632d74, puVar3 != (undefined4 *)0x0;

        puVar3 = (undefined4 *)*puVar3) {

      fVar6 = (float10)FUN_0050a610(*(int *)(iVar1 + 0x150) + 0xa0,puVar3[3] + 0xa0);

      if ((fVar6 < (float10)param_1) || (!bVar4)) {

        param_1 = (float)fVar6;

        bVar4 = true;

      }

    }

    for (; puVar5 != (undefined4 *)0x0; puVar5 = (undefined4 *)*puVar5) {

      fVar6 = (float10)FUN_0050a610(*(int *)(iVar1 + 0x150) + 0xa0,puVar5[3] + 0xa0);

      if ((fVar6 < (float10)param_1) || (!bVar4)) {

        param_1 = (float)fVar6;

        bVar4 = true;

      }

    }

    if (bVar4) {

      fVar6 = (float10)param_1 / ((float10)fVar2 * (float10)fVar2);

      goto LAB_0045dbf4;

    }

  }

  else {

    fVar6 = (float10)FUN_0050a610(*(int *)(iVar1 + 0x150) + 0xa0,DAT_00632a88 + 0xa0);

    fVar6 = fVar6 / ((float10)fVar2 * (float10)fVar2);

LAB_0045dbf4:

    if (fVar6 <= (float10)1.0) goto LAB_0045dc09;

  }

  fVar6 = (float10)1.0;

LAB_0045dc09:

  *(float *)(*(int *)(iVar1 + 0x150) + 0x14) = (float)((float10)1.0 - fVar6);

  ObjectSetAnim(*(undefined4 *)(iVar1 + 0x150),1,0x84,0,0,0);

  return;

}

/* ===== reaper_lock_short_4 @ 0x0045DC40 ===== */
void reaper_lock_short_4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4

                        ,undefined4 param_5,undefined4 param_6,int param_7)



{

  undefined4 local_14;

  undefined4 local_10;

  undefined4 local_c;

  undefined4 local_8;

  undefined4 local_4;

  

  ObjectSetAnim(param_1,param_2,param_3,param_4,param_5,param_6);

  if (param_7 != 0) {

    local_c = param_2;

    local_8 = param_3;

    local_4 = param_4;

    local_14 = param_5;

    local_10 = param_6;

    reaper_00530bd0(param_1,3,3,0,9,&local_14);

  }

  return;

}

/* ===== marker_process__FP6OBJECT @ 0x0045DCB0 ===== */
/* PS2 candidate: marker_process__FP6OBJECT (conf 0.536) */



void marker_process__FP6OBJECT(int param_1)



{

  int iVar1;

  float fVar2;

  bool bVar3;

  int iVar4;

  int iVar5;

  int *piVar6;

  int iVar7;

  int *piVar8;

  float10 fVar9;

  float local_b8;

  int local_b0;

  undefined4 local_ac;

  undefined4 local_a8;

  undefined4 local_a4;

  undefined4 local_a0;

  undefined4 local_8c;

  undefined4 local_88;

  int local_84;

  undefined4 local_64;

  undefined4 local_60;

  undefined4 local_5c;

  int local_50;

  undefined4 local_24;

  undefined4 local_20;

  undefined4 local_1c;

  

  iVar1 = *(int *)(param_1 + 0x100);

  iVar4 = *(int *)(iVar1 + 0x30c);

  if (iVar4 != 0) {

    piVar8 = (int *)0x0;

    iVar7 = 0;

    piVar6 = (int *)(iVar1 + 0x22c);

    do {

      if (*piVar6 != 0) {

        iVar5 = *(int *)(*piVar6 + 0x274);

        if (iVar5 == 0) {

          if ((float)piVar6[4] < 0.0 != ((float)piVar6[4] == 0.0)) {

            piVar8 = piVar6;

          }

        }

        else if (*(int *)(iVar5 + 0x188) == *(int *)(iVar4 + 0x188)) goto LAB_0045dd27;

      }

      iVar7 = iVar7 + 1;

      piVar6 = piVar6 + 7;

    } while (iVar7 < 8);

    if (piVar8 != (int *)0x0) {

      *(int *)(*piVar8 + 0x274) = iVar4;

    }

LAB_0045dd27:

    *(float *)(iVar1 + 0x310) = DAT_006328e0 + *(float *)(iVar1 + 0x310);

  }

  piVar6 = (int *)(iVar1 + 0x238);

  local_b0 = 8;

  do {

    iVar4 = piVar6[-3];

    if (((iVar4 == 0) || (iVar7 = *(int *)(iVar4 + 0x274), iVar7 == 0)) ||

       (*(float *)(iVar7 + 0x1c0) <= *(float *)(iVar7 + 0x278))) {

      if ((float)piVar6[1] != 0.0) {

        iVar7 = object_allocate_type_end(0x4ba,0x80000000);

        if (iVar7 != 0) {

          *(float *)(iVar7 + 0xc4) = *(float *)(iVar7 + 0xc4) * 3.0;

          fVar9 = (float10)FUN_00455600((undefined4 *)(iVar4 + 0xa0));

          object_set_location(iVar7,*(undefined4 *)(iVar4 + 0xa0),*(undefined4 *)(iVar4 + 0xa4),

                              (float)fVar9);

        }

        local_64 = *(undefined4 *)(iVar4 + 0xa0);

        local_60 = *(undefined4 *)(iVar4 + 0xa4);

        local_5c = *(undefined4 *)(iVar4 + 0xa8);

        local_50 = iVar4;

        fx_get_free_effect__Fv();

      }

      *(uint *)(piVar6[-3] + 0xd8) = *(uint *)(piVar6[-3] + 0xd8) | 0x40000000;

      if (piVar6[-1] != 0) {

        fx_delete(piVar6[-1]);

        piVar6[-1] = 0;

      }

      if (*piVar6 != 0) {

        fx_delete(*piVar6);

        *piVar6 = 0;

      }

      piVar6[2] = 0;

      piVar6[1] = 0;

    }

    else {

      if ((*(int *)(iVar1 + 0x30c) == 0) ||

         (*(int *)(*(int *)(iVar1 + 0x30c) + 0x188) != *(int *)(iVar7 + 0x188))) {

        bVar3 = false;

        fVar2 = (float)piVar6[1] - DAT_006328e0;

        piVar6[1] = (int)fVar2;

        if (fVar2 < 0.0) {

          piVar6[1] = 0;

        }

      }

      else {

        bVar3 = true;

        fVar2 = DAT_006328e0 + (float)piVar6[1];

        piVar6[1] = (int)fVar2;

        if (10.0 < fVar2) {

          piVar6[1] = 0x41200000;

        }

      }

      if ((*(float *)(DAT_00632ed8 + 0x14b0) <= 0.001) || (iVar4 = __ftol(), 4 < iVar4)) {

        iVar4 = 4;

      }

      iVar7 = fx_create(param_1);

      if (iVar7 != 0) {

        fVar2 = (float)piVar6[2] - DAT_006328e0;

        piVar6[2] = (int)fVar2;

        if (fVar2 < 0.0 != (fVar2 == 0.0)) {

          do {

            piVar6[2] = (int)((float)piVar6[2] + 0.5);

            if (iVar4 < 4) {

              if (2 < iVar4) {

                local_b8 = *(float *)(DAT_00632ed8 + 0x14bc);

                goto LAB_0045de98;

              }

              if (1 < iVar4) {

                local_b8 = *(float *)(DAT_00632ed8 + 0x14b8);

                goto LAB_0045de98;

              }

              if (0 < iVar4) {

                local_b8 = *(float *)(DAT_00632ed8 + 0x14b4);

                goto LAB_0045de98;

              }

            }

            else {

              local_b8 = *(float *)(DAT_00632ed8 + 0x14c0);

LAB_0045de98:

              if ((0.0 < local_b8) && (bVar3)) {

                if ((piVar6[-3] != 0) &&

                   (fVar9 = (float10)distance3d__FP3P3DT0(piVar6[-3] + 0xa0,param_1 + 0xa0),

                   fVar9 < (float10)1000.0)) {

                  fVar9 = fVar9 - (float10)100.0;

                  if (fVar9 < (float10)0.0) {

                    fVar9 = (float10)0.0;

                  }

                  local_b8 = (float)((((float10)1.0 - fVar9 * (float10)0.0011111111) * (float10)4.0

                                     + (float10)1.0) * (float10)local_b8);

                }

                AttackObject__FP6OBJECTT0P3P3DT2fi

                          (param_1,*(int *)(piVar6[-3] + 0x274),*(int *)(piVar6[-3] + 0x274) + 0xa0,

                           param_1 + 0xa0,local_b8,0x50);

              }

            }

          } while ((float)piVar6[2] < 0.0 != ((float)piVar6[2] == 0.0));

        }

      }

      if ((bVar3) && (0 < iVar4)) {

        if ((float)piVar6[3] == 0.0) {

          iVar7 = piVar6[-3];

          if (iVar7 != 0) {

            sound_play_obj(0x407,iVar7);

            iVar5 = reaper_0052e4a0(param_1);

            if (iVar5 != 0) {

              local_ac = *(undefined4 *)(iVar7 + 0x188);

              local_a8 = 0x407;

              reaper_00530bd0(param_1,0,2,0,0x13,&local_ac);

            }

          }

          piVar6[3] = 0x3f800000;

        }

      }

      else if ((float)piVar6[3] != 0.0) {

        iVar7 = piVar6[-3];

        if (iVar7 != 0) {

          sound_stop_obj(0x407,iVar7);

          iVar5 = reaper_0052e4a0(param_1);

          if (iVar5 != 0) {

            local_a4 = *(undefined4 *)(iVar7 + 0x188);

            local_a0 = 0x407;

            reaper_00530bd0(param_1,0,2,0,0x14,&local_a4);

          }

        }

        piVar6[3] = 0;

      }

      if ((bVar3) && (*(int *)(*(int *)(piVar6[-3] + 0x274) + 4) == 0x4fd)) {

        if (*piVar6 == 0) {

          local_1c = *(undefined4 *)(piVar6[-3] + 0x274);

          local_20 = 0;

          local_24 = 8;

          iVar7 = fx_get_free_effect__Fv();

          *piVar6 = iVar7;

        }

      }

      else if (*piVar6 != 0) {

        fx_delete(*piVar6);

        *piVar6 = 0;

      }

      if ((piVar6[-2] != iVar4) && (piVar6[-1] != 0)) {

        fx_delete(piVar6[-1]);

        piVar6[-1] = 0;

      }

      piVar6[-2] = iVar4;

      if (piVar6[-1] == 0) {

        local_84 = piVar6[-3];

        local_88 = 0xffffffff;

        local_8c = 8;

        switch(iVar4) {

        case 1:

          break;

        case 2:

          break;

        case 3:

          break;

        case 4:

          break;

        default:

          goto switchD_0045e0e5_default;

        }

        iVar4 = fx_get_free_effect__Fv();

        piVar6[-1] = iVar4;

      }

switchD_0045e0e5_default:

      if ((float)piVar6[1] < 0.0 != ((float)piVar6[1] == 0.0)) {

        *(undefined4 *)(piVar6[-3] + 0x274) = 0;

      }

    }

    piVar6 = piVar6 + 7;

    local_b0 = local_b0 + -1;

    if (local_b0 == 0) {

      return;

    }

  } while( true );

}

/* ===== reaper_state_machine @ 0x0045E250 ===== */
undefined1 reaper_state_machine(int param_1,int param_2)



{

  uint *puVar1;

  float fVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  byte bVar6;

  

  iVar3 = param_1;

  puVar1 = *(uint **)(param_1 + 0x100);

  bVar6 = (byte)puVar1[0x8a];

  if (((puVar1 == (uint *)0x0) || ((*puVar1 & 1) == 0)) || ((*puVar1 & 0x80000) == 0)) {

LAB_0045e393:

    puVar1[0x89] = 0;

    bVar6 = 0;

    *(undefined4 *)(puVar1[0x88] + 0x28) = 0;

LAB_0045e3a4:

    iVar5 = *(int *)(param_1 + 0x100);

    if (*(int *)(iVar5 + 0x30c) == 0) goto LAB_0045e3eb;

    iVar4 = reaper_0052e4a0(param_1);

    if (iVar4 != 0) {

      param_2 = 0;

      reaper_00530bd0(iVar3,0,1,0,0xe,&param_2);

    }

    iVar4 = 0;

    *(undefined4 *)(iVar5 + 0x310) = 0;

  }

  else {

    if ((*(uint *)(param_1 + 0x20c) & 0x2000) != 0) {

      bVar6 = bVar6 ^ 1;

    }

    if (bVar6 == 0) goto LAB_0045e393;

    if ((*(uint *)(param_1 + 0x20c) & 4) == 0) {

      fVar2 = (float)puVar1[0x89] - DAT_006328e0;

      puVar1[0x89] = (uint)fVar2;

      if (fVar2 < 0.0) {

        puVar1[0x89] = 0;

      }

      bVar6 = bVar6 & 0xfd;

    }

    else {

      fVar2 = DAT_006328e0 + (float)puVar1[0x89];

      puVar1[0x89] = (uint)fVar2;

      if (2.0 < fVar2) {

        puVar1[0x89] = 0x40000000;

      }

      bVar6 = bVar6 | 2;

    }

    if ((float)puVar1[0x89] < 0.0 != ((float)puVar1[0x89] == 0.0)) {

      param_2 = 0;

    }

    *puVar1 = *puVar1 | 0x100;

    *(float *)(puVar1[0x88] + 0x28) = (float)puVar1[0x89] * 0.5;

    if (bVar6 == 0) goto LAB_0045e3a4;

    iVar5 = *(int *)(param_1 + 0x100);

    if (*(int *)(iVar5 + 0x30c) == param_2) goto LAB_0045e3eb;

    iVar4 = reaper_0052e4a0(param_1);

    if (iVar4 != 0) {

      param_1 = 0;

      if (param_2 != 0) {

        param_1 = *(int *)(param_2 + 0x188);

      }

      reaper_00530bd0(iVar3,0,1,0,0xe,&param_1);

    }

    *(undefined4 *)(iVar5 + 0x310) = 0;

    iVar4 = param_2;

  }

  *(int *)(iVar5 + 0x30c) = iVar4;

LAB_0045e3eb:

  if ((byte)puVar1[0x8a] != bVar6) {

    *(byte *)(puVar1 + 0x8a) = bVar6;

    iVar5 = reaper_0052e4a0(iVar3);

    if (iVar5 != 0) {

      param_2 = CONCAT31(param_2._1_3_,bVar6);

      reaper_00530bd0(iVar3,0,0,1,0xf,&param_2);

    }

  }

  return (char)puVar1[0x8a];

}

/* ===== laser_ghost__FP6OBJECT @ 0x0045E440 ===== */
/* PS2 candidate: laser_ghost__FP6OBJECT (conf 0.495) */



void laser_ghost__FP6OBJECT(int param_1)



{

  float fVar1;

  float fVar2;

  char cVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  float *pfVar7;

  float *pfVar8;

  float10 fVar9;

  undefined4 uVar10;

  undefined4 uVar11;

  undefined4 uVar12;

  undefined4 uStack_c;

  undefined4 uStack_8;

  float fStack_4;

  

  iVar4 = *(int *)(param_1 + 0x100);

  cVar3 = *(char *)(iVar4 + 0x228);

  if (cVar3 != '\0') {

    if (cVar3 != '\x01') {

      if (cVar3 == '\x03') {

        if (*(int *)(param_1 + 0x10) != 0xca) {

          sound_play_player(0x453,param_1);

          ObjectSetAnim(param_1,0xca,0x20,0,0,0x3e800000);

        }

        if (*(int *)(iVar4 + 0x32c) == 0) {

          iVar5 = *(int *)(param_1 + 0x100);

          iVar6 = object_allocate_type(0x4af,0x80000000);

          *(int *)(iVar5 + 0x32c) = iVar6;

          *(uint *)(iVar6 + 0xdc) = *(uint *)(iVar6 + 0xdc) | 0x2000000;

          if (*(int *)(iVar5 + 0x32c) != 0) {

            *(int *)(*(int *)(iVar5 + 0x32c) + 0x210) = param_1;

            *(undefined4 *)(*(int *)(iVar5 + 0x32c) + 0x218) = 3;

            *(undefined4 *)(*(int *)(iVar5 + 0x32c) + 0x214) = 0;

          }

        }

      }

      goto LAB_0045e789;

    }

    iVar5 = *(int *)(param_1 + 0x10);

    if (iVar5 != 200) {

      if (iVar5 == 0xca) {

        sound_stop_player(0x453,param_1);

LAB_0045e62f:

        uVar12 = 0x3e800000;

        uVar10 = 0x21;

        uVar11 = 200;

      }

      else if (iVar5 == 199) {

        if ((*(uint *)(param_1 + 0x30) & 0x10) == 0) {

          if ((*(uint *)(param_1 + 0x30) & 2) == 0) goto LAB_0045e648;

          sound_play_player(0x453,param_1);

          goto LAB_0045e62f;

        }

        sound_play_player(0x455,param_1);

        uVar12 = 0;

        uVar10 = 0;

        uVar11 = 199;

      }

      else {

        sound_play_player(0x455,param_1);

        uVar12 = 0x3e800000;

        uVar10 = 0x20;

        uVar11 = 199;

      }

      ObjectSetAnim(param_1,uVar11,uVar10,0,0,uVar12);

    }

LAB_0045e648:

    if (*(int *)(param_1 + 0x10) == 199) {

      iVar5 = AddHud__4cHudP8cHudIcon_4

                        (*(undefined4 *)(*(int *)(*(int *)(param_1 + 8) + 0x324) + 0x28),

                         *(undefined4 *)(param_1 + 0x14));

      if ((float)iVar5 <= 1600.0) goto LAB_0045e789;

    }

    if (*(int *)(iVar4 + 0x32c) == 0) {

      iVar5 = *(int *)(param_1 + 0x100);

      iVar6 = object_allocate_type(0x4af,0x80000000);

      *(int *)(iVar5 + 0x32c) = iVar6;

      *(uint *)(iVar6 + 0xdc) = *(uint *)(iVar6 + 0xdc) | 0x2000000;

      if (*(int *)(iVar5 + 0x32c) != 0) {

        *(int *)(*(int *)(iVar5 + 0x32c) + 0x210) = param_1;

        *(undefined4 *)(*(int *)(iVar5 + 0x32c) + 0x218) = 3;

        *(undefined4 *)(*(int *)(iVar5 + 0x32c) + 0x214) = 0;

      }

    }

    goto LAB_0045e789;

  }

  iVar5 = *(int *)(param_1 + 0x10);

  if (iVar5 == 200) {

LAB_0045e47a:

    if (iVar5 == 199) {

LAB_0045e4b5:

      if ((~*(uint *)(param_1 + 0x30) & 0x10) == 0) {

        if ((*(uint *)(param_1 + 0x30) & 2) != 0) {

          if (*(int *)(iVar4 + 0xc) == 0) {

            if (*(int *)(iVar4 + 8) != 0) {

              uVar11 = 0x7d;

              goto LAB_0045e51d;

            }

          }

          else {

            uVar11 = 0x5e;

LAB_0045e51d:

            ObjectSetAnim(param_1,uVar11,0x20,0,0,0x3e800000);

          }

          if (*(float *)(iVar4 + 4) == 0.0) {

            uVar11 = 1;

          }

          else {

            uVar11 = 0x68;

          }

          ObjectSetAnim(param_1,uVar11,0x20,0,0,0x3e800000);

        }

      }

      else {

        sound_play_player(0x452,param_1);

        sound_stop_player(0x453,param_1);

        ObjectSetAnim(param_1,199,0x10,0,0,0);

      }

    }

    else {

      sound_play_player(0x452,param_1);

      sound_stop_player(0x453,param_1);

      ObjectSetAnim(param_1,199,0x30,0,0,0x3e800000);

    }

  }

  else {

    if (iVar5 == 199) goto LAB_0045e4b5;

    if (iVar5 == 0xca) goto LAB_0045e47a;

  }

  if (*(int *)(param_1 + 0x10) == 199) {

    iVar5 = AddHud__4cHudP8cHudIcon_4

                      (*(undefined4 *)(*(int *)(*(int *)(param_1 + 8) + 0x324) + 0x28),

                       *(undefined4 *)(param_1 + 0x14));

    if (1600.0 <= (float)iVar5) goto LAB_0045e789;

  }

  if (*(int *)(iVar4 + 0x32c) != 0) {

    object_destroy(*(int *)(iVar4 + 0x32c));

    *(undefined4 *)(iVar4 + 0x32c) = 0;

  }

LAB_0045e789:

  if ((*(uint *)(param_1 + 0x30) & 0x100) != 0) {

    fVar9 = (float10)FUN_00518b70(param_1,0);

    FUN_00403e60(param_1,(float)fVar9);

  }

  iVar5 = *(int *)(iVar4 + 0x220);

  *(undefined4 *)(iVar5 + 0x50) = 0;

  if ((DAT_00632a88 == param_1) && (*(char *)(iVar4 + 0x228) != '\0')) {

    pfVar7 = (float *)FUN_00515dc0(2);

    *(float *)(iVar5 + 0x38) = *pfVar7;

    *(float *)(iVar5 + 0x3c) = pfVar7[1];

    *(float *)(iVar5 + 0x40) = pfVar7[2];

    pfVar8 = (float *)XFGetCameraOrigin();

    pfVar7 = (float *)(iVar5 + 0x2c);

    *pfVar7 = *pfVar8;

    *(float *)(iVar5 + 0x30) = pfVar8[1];

    *(float *)(iVar5 + 0x34) = pfVar8[2];

    *(undefined4 *)(iVar5 + 0x4c) = 0x42480000;

    *pfVar7 = *(float *)(iVar5 + 0x38) * 20.0 + *pfVar7;

    *(undefined4 *)(iVar5 + 0x50) = 1;

    *(undefined4 *)(iVar5 + 0x54) = 0x60;

    *(undefined4 *)(iVar5 + 0x58) = 2;

    *(float *)(iVar5 + 0x30) = *(float *)(iVar5 + 0x3c) * 20.0 + *(float *)(iVar5 + 0x30);

    *(float *)(iVar5 + 0x34) = *(float *)(iVar5 + 0x40) * 20.0 + *(float *)(iVar5 + 0x34);

    fVar1 = 0.5 - *(float *)(iVar5 + 0x28) * 0.4;

    *(float *)(iVar5 + 0x44) = fVar1;

    *(float *)(iVar5 + 0x48) = fVar1;

    return;

  }

  if (1 < *(byte *)(iVar4 + 0x228)) {

    *(undefined4 *)(iVar5 + 0x2c) = *(undefined4 *)(param_1 + 0xa0);

    *(undefined4 *)(iVar5 + 0x30) = *(undefined4 *)(param_1 + 0xa4);

    *(float *)(iVar5 + 0x34) =

         *(float *)(param_1 + 0x1ec) * *(float *)(param_1 + 0xc4) + *(float *)(param_1 + 0xa8);

    iVar6 = *(int *)(param_1 + 0x2dc);

    uStack_c = *(undefined4 *)(iVar6 + 0x120);

    uStack_8 = *(undefined4 *)(iVar6 + 0x130);

    fStack_4 = *(float *)(iVar6 + 0x140);

    (*(code *)PTR_S_GEO_Vec3Transform_00580c20)((float *)(iVar5 + 0x2c),&uStack_c,1,param_1 + 0x294)

    ;

    pfVar7 = (float *)(iVar5 + 0x38);

    *pfVar7 = -*(float *)(param_1 + 0x29c);

    *(float *)(iVar5 + 0x3c) = -*(float *)(param_1 + 0x2ac);

    *(float *)(iVar5 + 0x40) = -*(float *)(param_1 + 700);

    fVar1 = (3.0 - *(float *)(iVar5 + 0x28)) * *(float *)(param_1 + 0xc4);

    *(float *)(iVar5 + 0x44) = fVar1;

    *(float *)(iVar5 + 0x48) = fVar1;

    *(float *)(iVar5 + 0x4c) = *(float *)(param_1 + 0xc4) * 200.0;

    iVar4 = *(int *)(iVar4 + 0x30c);

    if (iVar4 != 0) {

      fVar1 = *(float *)(iVar4 + 0x28c);

      fVar2 = *(float *)(iVar4 + 0x280);

      fStack_4 = (*(float *)(iVar4 + 0x290) + *(float *)(iVar4 + 0x284)) * 0.5;

      *pfVar7 = (*(float *)(iVar4 + 0x288) + *(float *)(iVar4 + 0x27c)) * 0.5 -

                *(float *)(iVar5 + 0x2c);

      *(float *)(iVar5 + 0x3c) = (fVar1 + fVar2) * 0.5 - *(float *)(iVar5 + 0x30);

      *(float *)(iVar5 + 0x40) = fStack_4 - *(float *)(iVar5 + 0x34);

      fVar9 = (float10)distancesq3d1p__FP3P3D(pfVar7);

      *(float *)(iVar5 + 0x4c) = (float)fVar9;

      *(undefined4 *)(iVar5 + 0x50) = 1;

    }

    *(undefined4 *)(iVar5 + 0x54) = 0;

    *(undefined4 *)(iVar5 + 0x58) = 1;

  }

  return;

}

/* ===== validate_eat__FP6OBJECTT0 @ 0x0045E9B0 ===== */
undefined4 validate_eat__FP6OBJECTT0(int param_1,float param_2)



{

  int iVar1;

  undefined4 uVar2;

  int iVar3;

  int *piVar4;

  float10 fVar5;

  

  iVar1 = *(int *)((int)param_2 + 4);

  iVar3 = 0;

  if (iVar1 != 0x2a5) {

    if ((iVar1 != 0x2e6) && (iVar1 != 0x248)) {

      return 1;

    }

    piVar4 = DAT_00632d68;

    if (DAT_00632d68 != (int *)0x0) {

      do {

        iVar1 = piVar4[3];

        if (((iVar1 != 0) && (*(int *)(iVar1 + 4) == 0x536)) &&

           ((fVar5 = (float10)distancesq2d__FP3P3DT0(param_1 + 0xa0,iVar1 + 0xa0), iVar3 == 0 ||

            (fVar5 < (float10)param_2)))) {

          param_2 = (float)fVar5;

          iVar3 = iVar1;

        }

        piVar4 = (int *)*piVar4;

      } while (piVar4 != (int *)0x0);

      if ((iVar3 != 0) && (param_2 < 1225.0)) {

        return 1;

      }

    }

    uVar2 = FUN_00507b00(s_Kabutomessage3_0055b39c,0x3f000000,0x3e4ccccd,0x3f000000,0x3f800000,

                         0x40a00000,1);

    FUN_00446f70(uVar2);

  }

  return 0;

}

/* ===== vec_bounds_calc @ 0x0045EA90 ===== */
void vec_bounds_calc(float *param_1,float *param_2,float *param_3,float *param_4,float *param_5,

                    float param_6)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float local_c;

  float local_8;

  

  fVar1 = param_3[1];

  fVar2 = param_2[1];

  fVar3 = param_3[2];

  fVar4 = param_2[2];

  fVar6 = 1.0 / param_6;

  fVar5 = fVar6 * (*param_3 - *param_2);

  *param_1 = fVar5 - param_6 * *param_4 * 0.5;

  fVar1 = fVar6 * (fVar1 - fVar2);

  param_1[1] = fVar1 - param_6 * param_4[1] * 0.5;

  fVar6 = fVar6 * (fVar3 - fVar4);

  fVar2 = fVar6 - param_6 * param_4[2] * 0.5;

  param_1[2] = fVar2;

  if (*param_4 == 0.0) {

    local_c = 0.0;

  }

  else {

    local_c = -((*param_1 * *param_1) / (*param_4 + *param_4));

  }

  if (param_4[1] == 0.0) {

    local_8 = 0.0;

  }

  else {

    local_8 = -((param_1[1] * param_1[1]) / (param_4[1] + param_4[1]));

  }

  if (param_4[2] == 0.0) {

    fVar2 = 0.0;

  }

  else {

    fVar2 = -((fVar2 * fVar2) / (param_4[2] + param_4[2]));

  }

  if (*param_5 < local_c) {

    local_c = *param_5;

  }

  if (param_5[1] < local_8) {

    local_8 = param_5[1];

  }

  if (param_5[2] < fVar2) {

    fVar2 = param_5[2];

  }

  if (*param_4 != 0.0) {

    *param_4 = (local_c * -2.0) / (-(*param_1 / *param_4) * -(*param_1 / *param_4));

  }

  if (param_4[1] != 0.0) {

    param_4[1] = (local_8 * -2.0) / (-(param_1[1] / param_4[1]) * -(param_1[1] / param_4[1]));

  }

  if (param_4[2] != 0.0) {

    param_4[2] = (fVar2 * -2.0) / (-(param_1[2] / param_4[2]) * -(param_1[2] / param_4[2]));

  }

  *param_1 = fVar5 - param_6 * *param_4 * 0.5;

  param_1[1] = fVar1 - param_6 * param_4[1] * 0.5;

  param_1[2] = fVar6 - param_6 * param_4[2] * 0.5;

  return;

}

/* ===== FUN_0045eca0 @ 0x0045ECA0 ===== */
float10 FUN_0045eca0(int param_1)



{

  int iVar1;

  

  if ((param_1 != 0) && (*(int *)(param_1 + 0x1e0) == 1)) {

    iVar1 = *(int *)(*(int *)(param_1 + 0x100) + 0xc);

    if ((iVar1 != 0) && ((*(byte *)(iVar1 + 0x1c8) & 1) != 0)) {

      return (float10)*(float *)(*(int *)(param_1 + 0x100) + 0x340);

    }

  }

  return (float10)0.0;

}

