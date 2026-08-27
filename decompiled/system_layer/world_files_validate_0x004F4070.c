// GiantsRE system layer - world_files_validate
// VA 0x004F4070 (ghidra name was FUN_004f4070)
// provenance: runtime anchors in scripts/re_db.json + PS2 symbols


undefined4 FUN_004f4070(void)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  
  FUN_0053a660();
  iVar1 = FUN_0053a3a0(s_world_gb2_0056508c);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar1 = FUN_0053b000(s_w_intro_bin_00565080);
    iVar2 = 0;
    if (iVar1 != 0) {
      iVar2 = FUN_0053a3a0(s_story1_gti_00565074);
    }
  }
  if (DAT_00631720 == 0) {
    if (iVar2 != 0) {
      iVar2 = cd_check_bool_wrapper(s_am_ms1_wav_00565068);
      goto LAB_004f40c1;
    }
  }
  else {
LAB_004f40c1:
    if (iVar2 != 0) {
      if (DAT_00631720 == 0) {
        iVar2 = cd_check_bool_wrapper(s_f_getbush_wav_00565020);
        iVar1 = FUN_0053a190(s_mlb_a2_raw_00565014);
        if ((iVar2 != 0) && (iVar1 != 0)) {
LAB_004f4129:
          if (iVar2 == 0) {
            pcVar3 = (char *)FUN_0050d7f0(s_ErrStreamFiles_00565004);
            if (pcVar3 == s_ErrStreamFiles_00565004) {
              pcVar3 = s_Missing_Stream_Files___Bad_Giant_00564fd0;
            }
            FUN_00523700(pcVar3);
            return 0;
          }
          if (iVar1 == 0) {
            pcVar3 = (char *)FUN_0050d7f0(s_ErrMusicFiles_00564fc0);
            if (pcVar3 == s_ErrMusicFiles_00564fc0) {
              pcVar3 = s_Missing_Music_Files___Bad_Giants_00564f90;
            }
            FUN_00523700(pcVar3);
            return 0;
          }
          goto LAB_004f417f;
        }
        iVar4 = FUN_0053afb0();
        if (iVar4 != 0) goto LAB_004f4129;
      }
      else {
LAB_004f417f:
        iVar2 = cd_check();
        if (iVar2 != 0) {
          return 1;
        }
      }
      pcVar3 = (char *)FUN_0050d7f0(s_ErrNeedCD1_00564f84);
      if (pcVar3 == s_ErrNeedCD1_00564f84) {
        pcVar3 = s_Please_put_Giants_CD__1_In_Drive_00564f54;
      }
      goto LAB_004f41a1;
    }
  }
  pcVar3 = (char *)FUN_0050d7f0(s_ErrGameFiles_00565058);
  if (pcVar3 == s_ErrGameFiles_00565058) {
    FUN_00523700(s_Missing_Game_Files___Corrupted_I_00565030);
    return 0;
  }
LAB_004f41a1:
  FUN_00523700(pcVar3);
  return 0;
}


