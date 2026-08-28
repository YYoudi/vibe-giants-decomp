// sound init (FUN_0051f900) — ErrFailedSND source

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0051f900(char *param_1,undefined4 param_2)

{
  HMODULE hModule;
  undefined4 local_20c;
  undefined4 local_208;
  undefined4 local_204;
  CHAR local_200 [512];
  
  if ((param_1 != (char *)0x0) && (*param_1 != '\0')) {
    FUN_00544b47(local_200,s__s_gs__s_0057f938,param_1,param_2);
    hModule = GetModuleHandleA(local_200);
    if (hModule != (HMODULE)0x0) goto LAB_0051f990;
    hModule = LoadLibraryA(local_200);
    if (hModule != (HMODULE)0x0) goto LAB_0051f990;
  }
  FUN_00544b47(local_200,s_gs__s_0057f930,param_2);
  hModule = GetModuleHandleA(local_200);
  if (hModule == (HMODULE)0x0) {
    hModule = LoadLibraryA(local_200);
    if (hModule == (HMODULE)0x0) {
      return 0;
    }
  }
LAB_0051f990:
  DAT_005dc24c = GetProcAddress(hModule,s_SDVInit_0057f928);
  if (DAT_005dc24c == (FARPROC)0x0) {
    FUN_00523ad0(s_Failed_to_load_SDVInit_0057f910);
    return 0;
  }
  DAT_005dc250 = GetProcAddress(hModule,s_SDVFinit_0057f904);
  if (DAT_005dc250 == (FARPROC)0x0) {
    FUN_00523ad0(s_Failed_to_load_SDVFinit_0057f8ec);
    return 0;
  }
  DAT_005dc254 = GetProcAddress(hModule,s_SDVPause_0057f8e0);
  if (DAT_005dc254 == (FARPROC)0x0) {
    FUN_00523ad0(s_Failed_to_load_SDVPause_0057f8c8);
    return 0;
  }
  DAT_005dc258 = GetProcAddress(hModule,s_SDVResume_0057f8bc);
  if (DAT_005dc258 == (FARPROC)0x0) {
    FUN_00523ad0(s_Failed_to_load_SDVResume_0057f8a0);
    return 0;
  }
  DAT_005dc25c = GetProcAddress(hModule,s_SDVSilence_0057f894);
  if (DAT_005dc25c == (FARPROC)0x0) {
    FUN_00523ad0(s_Failed_to_load_SDVSilence_0057f878);
    return 0;
  }
  DAT_005dc260 = GetProcAddress(hModule,s_SDVProcess_0057f86c);
  if (DAT_005dc260 == (FARPROC)0x0) {
    FUN_00523ad0(s_Failed_to_load_SDVProcess_0057f850);
    return 0;
  }
  _DAT_005dc264 = GetProcAddress(hModule,s_SDVPreLoad_0057f844);
  if (_DAT_005dc264 == (FARPROC)0x0) {
    FUN_00523ad0(s_Failed_to_load_SDVPreLoad_0057f828);
    return 0;
  }
  DAT_005dc268 = GetProcAddress(hModule,s_SDVUnLoad_0057f81c);
  if (DAT_005dc268 == (FARPROC)0x0) {
    FUN_00523ad0(s_Failed_to_load_SDVUnLoad_0057f800);
    return 0;
  }
  DAT_005dc26c = GetProcAddress(hModule,s_SDVStopObject_0057f7f0);
  if (DAT_005dc26c == (FARPROC)0x0) {
    FUN_00523ad0(s_Failed_to_load_SDVStopObject_0057f7d0);
    return 0;
  }
  DAT_005dc270 = GetProcAddress(hModule,s_SDVStopSample_0057f7c0);
  if (DAT_005dc270 == (FARPROC)0x0) {
    FUN_00523ad0(s_Failed_to_load_SDVStopSample_0057f7a0);
    return 0;
  }
  DAT_005dc274 = GetProcAddress(hModule,s_SDVStopInstance_0057f790);
  if (DAT_005dc274 == (FARPROC)0x0) {
    FUN_00523ad0(s_Failed_to_load_SDVStopInstance_0057f770);
    return 0;
  }
  DAT_005dc278 = GetProcAddress(hModule,s_SDVStart3DObj_0057f760);
  if (DAT_005dc278 == (FARPROC)0x0) {
    FUN_00523ad0(s_Failed_to_load_SDVStart3DObj_0057f740);
    return 0;
  }
  DAT_005dc27c = GetProcAddress(hModule,s_SDVStart3DPos_0057f730);
  if (DAT_005dc27c == (FARPROC)0x0) {
    FUN_00523ad0(s_Failed_to_load_SDVStart3DPos_0057f710);
    return 0;
  }
  DAT_005dc280 = GetProcAddress(hModule,s_SDVStart2DSample_0057f6fc);
  if (DAT_005dc280 == (FARPROC)0x0) {
    FUN_00523ad0(s_Failed_to_load_SDVStart2DSample_0057f6dc);
    return 0;
  }
  _DAT_005dc284 = GetProcAddress(hModule,s_SDVSetVolumeInstance_0057f6c4);
  if (_DAT_005dc284 == (FARPROC)0x0) {
    FUN_00523ad0(s_Failed_to_load_SDVSetVolumeInsta_0057f6a0);
    return 0;
  }
  DAT_005dc288 = GetProcAddress(hModule,s_SDVSetVolPCTInstance_0057f688);
  if (DAT_005dc288 == (FARPROC)0x0) {
    FUN_00523ad0(s_Failed_to_load_SDVSetVolPCTInsta_0057f664);
    return 0;
  }
  _DAT_005dc28c = GetProcAddress(hModule,s_SDVSoundFastIsPlayingInst_0057f648);
  if (_DAT_005dc28c == (FARPROC)0x0) {
    FUN_00523ad0(s_Failed_to_load_SDVSoundFastIsPla_0057f61c);
    return 0;
  }
  DAT_005dc290 = GetProcAddress(hModule,s_SDVGetInstance_0057f60c);
  if (DAT_005dc290 == (FARPROC)0x0) {
    FUN_00523ad0(s_Failed_to_load_SDVGetInstance_0057f5ec);
    return 0;
  }
  _DAT_005dc294 = GetProcAddress(hModule,s_SDVGetMinMaxDistances_0057f5d4);
  if (_DAT_005dc294 == (FARPROC)0x0) {
    FUN_00523ad0(s_Failed_to_load_SDVGetMinMaxDista_0057f5ac);
    return 0;
  }
  DAT_005dc298 = GetProcAddress(hModule,s_SDVSetGlobalVolume_0057f598);
  if (DAT_005dc298 == (FARPROC)0x0) {
    FUN_00523ad0(s_Failed_to_load_SDVSetGlobalVolum_0057f574);
    return 0;
  }
  _DAT_005dc29c = GetProcAddress(hModule,s_SDVSetGlobalControlF_0057f55c);
  if (_DAT_005dc29c == (FARPROC)0x0) {
    FUN_00523ad0(s_Failed_to_load_SDVSetGlobalContr_0057f538);
    return 0;
  }
  DAT_005dc2a0 = GetProcAddress(hModule,s_SDVSetGlobalControlI_0057f520);
  if (DAT_005dc2a0 == (FARPROC)0x0) {
    FUN_00523ad0(s_Failed_to_load_SDVSetGlobalContr_0057f4fc);
    return 0;
  }
  DAT_005dc2a4 = GetProcAddress(hModule,s_SDVGetGlobalVolume_0057f4e8);
  if (DAT_005dc2a4 == (FARPROC)0x0) {
    FUN_00523ad0(s_Failed_to_load_SDVGetGlobalVolum_0057f4c4);
    return 0;
  }
  _DAT_005dc2a8 = GetProcAddress(hModule,s_SDVGetGlobalControlF_0057f4ac);
  if (_DAT_005dc2a8 == (FARPROC)0x0) {
    FUN_00523ad0(s_Failed_to_load_SDVGetGlobalContr_0057f488);
    return 0;
  }
  DAT_005dc2ac = GetProcAddress(hModule,s_SDVGetGlobalControlI_0057f470);
  if (DAT_005dc2ac == (FARPROC)0x0) {
    FUN_00523ad0(s_Failed_to_load_SDVGetGlobalContr_0057f44c);
    return 0;
  }
  _DAT_005dc2b0 = GetProcAddress(hModule,s_SDVGetListenerPosition_0057f434);
  if (_DAT_005dc2b0 == (FARPROC)0x0) {
    FUN_00523ad0(s_Failed_to_load_SDVGetListenerPos_0057f40c);
    return 0;
  }
  DAT_005dc2b4 = GetProcAddress(hModule,s_SDVGetTime_0057f400);
  if (DAT_005dc2b4 == (FARPROC)0x0) {
    FUN_00523ad0(s_Failed_to_load_SDVGetTime_0057f3e4);
    return 0;
  }
  _DAT_005dc2b8 = GetProcAddress(hModule,s_SDVCalcVolume_0057f3d4);
  if (_DAT_005dc2b8 == (FARPROC)0x0) {
    FUN_00523ad0(s_Failed_to_load_SDVCalcVolume_0057f3b4);
    return 0;
  }
  _DAT_005dc2bc = GetProcAddress(hModule,s_SDVWantLoadOccludes_0057f3a0);
  if (_DAT_005dc2bc == (FARPROC)0x0) {
    FUN_00523ad0(s_Failed_to_load_SDVWantLoadOcclud_0057f37c);
    return 0;
  }
  DAT_005dc2c0 = GetProcAddress(hModule,s_SDVOcclusionBox_0057f36c);
  if (DAT_005dc2c0 == (FARPROC)0x0) {
    FUN_00523ad0(s_Failed_to_load_SDVOcclusionBox_0057f34c);
    return 0;
  }
  _DAT_005dc2c4 = GetProcAddress(hModule,s_SDVDestroyOcclusionBox_0057f334);
  if (_DAT_005dc2c4 == (FARPROC)0x0) {
    FUN_00523ad0(s_Failed_to_load_SDVDestroyOcclusi_0057f30c);
    return 0;
  }
  DAT_005dc2c8 = GetProcAddress(hModule,s_SDVDestroyOcclusionBoxSet_0057f2f0);
  if (DAT_005dc2c8 == (FARPROC)0x0) {
    FUN_00523ad0(s_Failed_to_load_SDVDestroyOcclusi_0057f2c4);
    return 0;
  }
  _DAT_005dc2cc = GetProcAddress(hModule,s_SDVUpdateOcclusionBox_0057f2ac);
  if (_DAT_005dc2cc == (FARPROC)0x0) {
    FUN_00523ad0(s_Failed_to_load_SDVUpdateOcclusio_0057f284);
    return 0;
  }
  _DAT_005dc2d0 = GetProcAddress(hModule,s_SDVOcclusionParms_0057f270);
  if (_DAT_005dc2d0 == (FARPROC)0x0) {
    FUN_00523ad0(s_Failed_to_load_SDVOcclusionParms_0057f24c);
    return 0;
  }
  DAT_005dc2d4 = GetProcAddress(hModule,s_SDVHWLoadWorld_0057f23c);
  if (DAT_005dc2d4 == (FARPROC)0x0) {
    FUN_00523ad0(s_Failed_to_load_SDVHWLoadWorld_0057f21c);
    return 0;
  }
  DAT_005dc330 = GetProcAddress(hModule,s_SDVUpCallsLoad_0057f20c);
  if (DAT_005dc330 == (FARPROC)0x0) {
    FUN_00523ad0(s_Failed_to_load_SDVUpCallsLoad_0057f1ec);
    return 0;
  }
  DAT_005dc2d8 = GetProcAddress(hModule,s_MDVInit_0057f1e4);
  if (DAT_005dc2d8 == (FARPROC)0x0) {
    FUN_00523ad0(s_Failed_to_load_MDVInit_0057f1cc);
    return 0;
  }
  DAT_005dc2dc = GetProcAddress(hModule,s_MDVFinit_0057f1c0);
  if (DAT_005dc2dc == (FARPROC)0x0) {
    FUN_00523ad0(s_Failed_to_load_MDVFinit_0057f1a8);
    return 0;
  }
  DAT_005dc2e0 = GetProcAddress(hModule,s_MDVProcess_0057f19c);
  if (DAT_005dc2e0 == (FARPROC)0x0) {
    FUN_00523ad0(s_Failed_to_load_MDVProcess_0057f180);
    return 0;
  }
  DAT_005dc2e4 = GetProcAddress(hModule,s_MDVPlaySong_0057f174);
  if (DAT_005dc2e4 == (FARPROC)0x0) {
    FUN_00523ad0(s_Failed_to_load_MDVPlaySong_0057f158);
    return 0;
  }
  DAT_005dc2e8 = GetProcAddress(hModule,s_MDVStopSong_0057f14c);
  if (DAT_005dc2e8 == (FARPROC)0x0) {
    FUN_00523ad0(s_Failed_to_load_MDVStopSong_0057f130);
    return 0;
  }
  DAT_005dc2ec = GetProcAddress(hModule,s_MDVGetPlayList_0057f120);
  if (DAT_005dc2ec == (FARPROC)0x0) {
    FUN_00523ad0(s_Failed_to_load_MDVGetPlayList_0057f100);
    return 0;
  }
  DAT_005dc2f0 = GetProcAddress(hModule,s_MDVGetSongPlaying_0057f0ec);
  if (DAT_005dc2f0 == (FARPROC)0x0) {
    FUN_00523ad0(s_Failed_to_load_MDVGetSongPlaying_0057f0c8);
    return 0;
  }
  DAT_005dc2f4 = GetProcAddress(hModule,s_MDVIsJumping_0057f0b8);
  if (DAT_005dc2f4 == (FARPROC)0x0) {
    FUN_00523ad0(s_Failed_to_load_MDVIsJumping_0057f09c);
    return 0;
  }
  DAT_005dc2f8 = GetProcAddress(hModule,s_MDVSetGlobalVolume_0057f088);
  if (DAT_005dc2f8 == (FARPROC)0x0) {
    FUN_00523ad0(s_Failed_to_load_MDVSetGlobalVolum_0057f064);
    return 0;
  }
  _DAT_005dc2fc = GetProcAddress(hModule,s_MDVSetGlobalControlF_0057f04c);
  if (_DAT_005dc2fc == (FARPROC)0x0) {
    FUN_00523ad0(s_Failed_to_load_MDVSetGlobalContr_0057f028);
    return 0;
  }
  _DAT_005dc300 = GetProcAddress(hModule,s_MDVSetGlobalControlI_0057f010);
  if (_DAT_005dc300 == (FARPROC)0x0) {
    FUN_00523ad0(s_Failed_to_load_MDVSetGlobalContr_0057efec);
    return 0;
  }
  DAT_005dc304 = GetProcAddress(hModule,s_MDVGetGlobalVolume_0057efd8);
  if (DAT_005dc304 == (FARPROC)0x0) {
    FUN_00523ad0(s_Failed_to_load_MDVGetGlobalVolum_0057efb4);
    return 0;
  }
  _DAT_005dc308 = GetProcAddress(hModule,s_MDVGetGlobalControlF_0057ef9c);
  if (_DAT_005dc308 == (FARPROC)0x0) {
    FUN_00523ad0(s_Failed_to_load_MDVGetGlobalContr_0057ef78);
    return 0;
  }
  _DAT_005dc30c = GetProcAddress(hModule,s_MDVGetGlobalControlI_0057ef60);
  if (_DAT_005dc30c == (FARPROC)0x0) {
    FUN_00523ad0(s_Failed_to_load_MDVGetGlobalContr_0057ef3c);
    return 0;
  }
  DAT_005dc310 = GetProcAddress(hModule,s_VDVSilence_0057ef30);
  if (DAT_005dc310 == (FARPROC)0x0) {
    FUN_00523ad0(s_Failed_to_load_VDVSilence_0057ef14);
    return 0;
  }
  _DAT_005dc314 = GetProcAddress(hModule,s_VDVPlayStream_0057ef04);
  if (_DAT_005dc314 == (FARPROC)0x0) {
    FUN_00523ad0(s_Failed_to_load_VDVPlayStream_0057eee4);
    return 0;
  }
  _DAT_005dc318 = GetProcAddress(hModule,s_VDVPlayStreamSync_0057eed0);
  if (_DAT_005dc318 == (FARPROC)0x0) {
    FUN_00523ad0(s_Failed_to_load_VDVPlayStreamSync_0057eeac);
    return 0;
  }
  _DAT_005dc31c = GetProcAddress(hModule,s_VDVGetStreamSyncTime_0057ee94);
  if (_DAT_005dc31c == (FARPROC)0x0) {
    FUN_00523ad0(s_Failed_to_load_VDVGetStreamSyncT_0057ee70);
    return 0;
  }
  DAT_005dc320 = GetProcAddress(hModule,s_VDVStopStream_0057ee60);
  if (DAT_005dc320 == (FARPROC)0x0) {
    FUN_00523ad0(s_Failed_to_load_VDVStopStream_0057ee40);
    return 0;
  }
  DAT_005dc324 = GetProcAddress(hModule,s_VDVIsPlayingStream_0057ee2c);
  if (DAT_005dc324 == (FARPROC)0x0) {
    FUN_00523ad0(s_Failed_to_load_VDVIsPlayingStrea_0057ee08);
    return 0;
  }
  _DAT_005dc328 = GetProcAddress(hModule,s_VDVSetVolPCTStream_0057edf4);
  if (_DAT_005dc328 == (FARPROC)0x0) {
    FUN_00523ad0(s_Failed_to_load_VDVSetVolPCTStrea_0057edd0);
    return 0;
  }
  DAT_005dc32c = GetProcAddress(hModule,s_VDVFinitStreams_0057edc0);
  if (DAT_005dc32c == (FARPROC)0x0) {
    FUN_00523ad0(s_Failed_to_load_VDVFinitStreams_0057eda0);
    return 0;
  }
  DAT_005dc330 = GetProcAddress(hModule,s_UpCallsLoad_0057ec00);
  if (DAT_005dc330 == (FARPROC)0x0) {
    FUN_00523ad0(s_Failed_to_load_UpCallsLoad_0057ebe4);
    return 0;
  }
  _DAT_005dc334 = 1;
  FUN_00521a60(&local_208,&local_20c,&local_204);
  (*DAT_005dc330)(local_208,local_20c,local_204);
  return 1;
}

