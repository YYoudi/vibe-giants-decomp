/* Giants 1.449 — module _unmapped_0045
 * 166 functions (151 named) — decompiled, names from PS2 symbols
 * Original source: C:\Giants\source\_unmapped_0045.c(pp) (assert-string evidence)
 */

/* ===== cspec_004503d0 @ 0x004503D0 ===== */
undefined4 cspec_004503d0(void)



{

  return 0x10c;

}

/* ===== cspec_004503e0 @ 0x004503E0 ===== */
void cspec_004503e0(int param_1)



{

  int iVar1;

  int iVar2;

  

  if (*(undefined4 **)(param_1 + 0x2f4) != (undefined4 *)0x0) {

    mem_free_tagged(**(undefined4 **)(param_1 + 0x2f4),s_C__Giants_source_Main_fx_c_00558840,0x1aa2)

    ;

    mem_free_tagged(*(undefined4 *)(param_1 + 0x2f4),s_C__Giants_source_Main_fx_c_00558840,0x1aa3);

  }

  *(undefined4 *)(param_1 + 0x2f4) = 0;

  iVar1 = *(int *)(param_1 + 0x100);

  if (*(int *)(iVar1 + 0x100) != 0) {

    mem_free_tagged(*(int *)(iVar1 + 0x100),s_C__Giants_source_Main_fx_c_00558840,0x1aaa);

  }

  *(undefined4 *)(iVar1 + 0x100) = 0;

  if (*(int **)(iVar1 + 0xf8) != (int *)0x0) {

    iVar2 = **(int **)(iVar1 + 0xf8);

    if (iVar2 != 0) {

      func_0x00509b90(iVar2);

    }

    mem_free_tagged(*(undefined4 *)(iVar1 + 0xf8),s_C__Giants_source_Main_fx_c_00558840,0x1ab2);

  }

  *(undefined4 *)(iVar1 + 0xf8) = 0;

  if (*(int *)(iVar1 + 0xfc) != 0) {

    mem_free_tagged(*(int *)(iVar1 + 0xfc),s_C__Giants_source_Main_fx_c_00558840,0x1ab7);

  }

  *(undefined4 *)(iVar1 + 0xfc) = 0;

  if (*(int *)(iVar1 + 0x104) != 0) {

    mem_free_tagged(*(int *)(iVar1 + 0x104),s_C__Giants_source_Main_fx_c_00558840,0x1abb);

  }

  *(undefined4 *)(iVar1 + 0x104) = 0;

  return;

}

/* ===== cspec_004504d0 @ 0x004504D0 ===== */
void cspec_004504d0(int param_1)



{

  undefined4 *puVar1;

  float fVar2;

  int *piVar3;

  float *pfVar4;

  float10 fVar5;

  undefined4 uStack_18;

  undefined4 uStack_14;

  undefined4 uStack_10;

  undefined1 auStack_c [12];

  

  piVar3 = *(int **)(param_1 + 0x100);

  if (*piVar3 != 0) {

    if ((*(uint *)(param_1 + 0xe0) & 1) == 0) {

      *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 1;

      main_linkage_00470250(&DAT_00632d88,param_1);

    }

    puVar1 = (undefined4 *)(param_1 + 0xa0);

    uStack_18 = *puVar1;

    uStack_14 = *(undefined4 *)(param_1 + 0xa4);

    uStack_10 = *(undefined4 *)(param_1 + 0xa8);

    func_0x00404c90(piVar3,puVar1,auStack_c);

    if ((*(byte *)(param_1 + 0xdc) & 0x40) != 0) {

      fVar5 = (float10)get_floor_z_point(puVar1);

      *(float *)(param_1 + 0xa8) = (float)fVar5;

    }

    *(float *)(param_1 + 0xa8) = *(float *)(param_1 + 0x1d4) + *(float *)(param_1 + 0xa8);

    object_copy_posdirinfo(param_1);

    object_copy_posdirinfo(param_1);

    fVar5 = (float10)dirfcalcp3d__FP3P3DT0(&uStack_18,puVar1);

    *(float *)(param_1 + 200) = (float)fVar5;

    fVar5 = (float10)FUN_00518b70(param_1,0);

    fVar2 = (float)(fVar5 * (float10)(float)piVar3[2] + (float10)(float)piVar3[1]);

    piVar3[1] = (int)fVar2;

    pfVar4 = *(float **)(*piVar3 + 4);

    if (*pfVar4 <= fVar2) {

      if (*(char *)(param_1 + 0xdc) < '\0') {

        piVar3[1] = (int)*pfVar4;

        return;

      }

      piVar3[1] = (int)(fVar2 - *pfVar4);

    }

  }

  return;

}

/* ===== cspec_004505d0 @ 0x004505D0 ===== */
void cspec_004505d0(int param_1)



{

  if (*(int *)(param_1 + 0xe4) == 0) {

    ObjectSetAnim(param_1,1,0x84,0,0,0);

    *(undefined4 *)(param_1 + 0x14) = 0x3f800000;

    *(undefined4 *)(param_1 + 0xe4) = 1;

  }

  obj_health_ratio_update(param_1);

  return;

}

/* ===== cspec_00450620 @ 0x00450620 ===== */
void cspec_00450620(undefined4 param_1,float param_2,int param_3,int param_4,int param_5)



{

  float fVar1;

  int *piVar2;

  float fVar3;

  float fVar4;

  int iVar5;

  int iVar6;

  undefined4 *puVar7;

  undefined4 *puVar8;

  

  fVar1 = *(float *)(param_3 + 0x278);

  piVar2 = *(int **)(param_3 + 0x100);

  if ((piVar2[3] == 0) ||

     ((param_4 != 0 && ((*(int *)(param_4 + 4) == 0x336 || (*(int *)(param_4 + 0x1e0) == 8)))))) {

    param_2 = param_2 + *(float *)(param_3 + 0x278);

    *(float *)(param_3 + 0x278) = param_2;

    if (*(float *)(param_3 + 0x1c0) < param_2) {

      *(undefined4 *)(param_3 + 0x278) = *(undefined4 *)(param_3 + 0x1c0);

    }

    if (*(float *)(param_3 + 0x1c0) <= *(float *)(param_3 + 0x278)) {

      if ((*(int *)(param_3 + 4) == 0x2a5) && (iVar5 = ObjIsKabuto(DAT_00632a88), iVar5 == 0)) {

        func_0x004e76d0(param_3);

      }

      if (0 < piVar2[1]) {

        fx_get_free_effect__Fv();

      }

      if (0 < *piVar2) {

        iVar5 = object_allocate_type(*piVar2,0x80000000);

        *(undefined4 *)(iVar5 + 0x188) = *(undefined4 *)(param_3 + 0x188);

        *(undefined4 *)(iVar5 + 200) = *(undefined4 *)(param_3 + 200);

        *(undefined4 *)(iVar5 + 0xc4) = *(undefined4 *)(param_3 + 0xc4);

        object_set_location(iVar5,*(undefined4 *)(param_3 + 0xa0),*(undefined4 *)(param_3 + 0xa4),

                            *(undefined4 *)(param_3 + 0xa8));

        if ((*(int *)(param_3 + 0x1e0) == 0x3c) && (*(int *)(iVar5 + 0x1e0) == 0x3c)) {

          puVar7 = (undefined4 *)(*(int *)(param_3 + 0x100) + 0x10);

          puVar8 = (undefined4 *)(*(int *)(iVar5 + 0x100) + 0x10);

          for (iVar6 = 0xf; iVar6 != 0; iVar6 = iVar6 + -1) {

            *puVar8 = *puVar7;

            puVar7 = puVar7 + 1;

            puVar8 = puVar8 + 1;

          }

        }

        if ((*(uint *)(param_3 + 0xd8) & 0x400) != 0) {

          *(uint *)(iVar5 + 0xd8) = *(uint *)(iVar5 + 0xd8) | 0x400;

        }

      }

      object_destroy(param_3);

      return;

    }

    fVar3 = 1.0 / *(float *)(param_3 + 0x1c0);

    fVar4 = (1.0 - fVar1 * fVar3) * 100.0;

    fVar1 = (1.0 - fVar3 * *(float *)(param_3 + 0x278)) * 100.0 - 0.01;

    if (((param_5 != 0) &&

        ((((*(float *)(DAT_00632ed8 + 0xb74) < fVar4 && (fVar1 <= *(float *)(DAT_00632ed8 + 0xb74)))

          || ((*(float *)(DAT_00632ed8 + 0xb78) < fVar4 &&

              (fVar1 <= *(float *)(DAT_00632ed8 + 0xb78))))) ||

         ((*(float *)(DAT_00632ed8 + 0xb7c) < fVar4 && (fVar1 <= *(float *)(DAT_00632ed8 + 0xb7c))))

         ))) && (0 < piVar2[2])) {

      fx_get_free_effect__Fv();

    }

  }

  return;

}

/* ===== cspec_004508a0 @ 0x004508A0 ===== */
void cspec_004508a0(int param_1)



{

  float fVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  uint uVar5;

  undefined4 *puVar6;

  undefined4 uVar7;

  uint uVar8;

  float10 fVar9;

  float10 fVar10;

  

  iVar2 = *(int *)(param_1 + 0x100);

  if (*(int *)(param_1 + 0xe4) == 0) {

    if (*(float *)(param_1 + 0xec) < 0.0 == (*(float *)(param_1 + 0xec) == 0.0)) {

      fVar9 = (float10)FUN_00518b70(param_1,0);

      *(float *)(param_1 + 0xec) = (float)((float10)*(float *)(param_1 + 0xec) - fVar9);

    }

    else {

      fVar1 = *(float *)(iVar2 + 8);

      fVar9 = (float10)distancesq2d__FP3P3DT0(DAT_00632a88 + 0xa0,param_1 + 0xa0);

      if (fVar9 < (float10)fVar1 * (float10)fVar1) {

        uVar7 = fx_get_free_effect__Fv();

        *(undefined4 *)(iVar2 + 0x10) = uVar7;

        if (0 < *(int *)(iVar2 + 0x14)) {

          sound_play_obj(*(int *)(iVar2 + 0x14),param_1);

        }

        *(undefined4 *)(param_1 + 0xe4) = 1;

        return;

      }

    }

  }

  else if (*(int *)(param_1 + 0xe4) == 1) {

    if (((*(int *)(iVar2 + 0x20) == 0) && (0 < *(int *)(iVar2 + 0x18))) &&

       ((*(byte *)(param_1 + 0x30) & 2) != 0)) {

      *(undefined4 *)(iVar2 + 0x20) = 1;

      sound_play_obj(*(int *)(iVar2 + 0x18),param_1);

    }

    fVar1 = *(float *)(iVar2 + 8);

    fVar9 = (float10)distancesq2d__FP3P3DT0(DAT_00632a88 + 0xa0,param_1 + 0xa0);

    fVar10 = (float10)fVar1 * (float10)fVar1;

    if (fVar10 < fVar9 != (fVar10 == fVar9)) {

      iVar3 = *(int *)(iVar2 + 0x10);

      if (iVar3 != 0) {

        if (*(int *)(iVar3 + 0x14) == 4) {

          for (puVar6 = DAT_00632da0; puVar6 != (undefined4 *)0x0; puVar6 = (undefined4 *)*puVar6) {

            iVar4 = puVar6[3];

            if (**(int **)(iVar4 + 0x100) == iVar3 + 8) {

              uVar5 = *(uint *)(iVar4 + 0xe0);

              uVar8 = uVar5 | 0x400000;

              *(uint *)(iVar4 + 0xe0) = uVar8;

              if (uVar8 != 0) {

                *(uint *)(iVar4 + 0xe0) = uVar5 & 0xffbfffff;

                fx_processOpCodes(iVar3 + 8,0,iVar4);

              }

            }

          }

          *(undefined4 *)(iVar3 + 0x14) = 0;

        }

        else {

          *(uint *)(iVar3 + 0x18) = *(uint *)(iVar3 + 0x18) | 0x80000;

        }

      }

      *(undefined4 *)(iVar2 + 0x10) = 0;

      if (*(int *)(iVar2 + 0x20) != 0) {

        *(undefined4 *)(iVar2 + 0x20) = 0;

        sound_stop_obj(*(undefined4 *)(iVar2 + 0x1c),param_1);

      }

      if (*(int *)(iVar2 + 0x1c) != 0) {

        sound_play_obj(*(int *)(iVar2 + 0x1c),param_1);

      }

      uVar7 = *(undefined4 *)(iVar2 + 0xc);

      *(undefined4 *)(param_1 + 0xe4) = 0;

      *(undefined4 *)(param_1 + 0xec) = uVar7;

      return;

    }

  }

  return;

}

/* ===== render_stats_reset @ 0x00450AA0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void render_stats_reset(void)



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

/* ===== render_stats_update @ 0x00450BB0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void render_stats_update(void)



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

        render_stats_reset();

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

/* ===== render_fps_get @ 0x00450C90 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



float10 render_fps_get(void)



{

  return (float10)DAT_0059ce7c / ((float10)DAT_006328e8 - (float10)_DAT_0059ce88);

}

/* ===== AudioGetMasterVolume__Fv_7 @ 0x00450CB0 ===== */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */



undefined4 AudioGetMasterVolume__Fv_7(void)



{

  return DAT_0059d7f0;

}

/* ===== gfx_polycount_get @ 0x00450CC0 ===== */
void gfx_polycount_get(void)



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

  DAT_0059d804 = objectset_find_2(0x127);

  DAT_0059d808 = main_dlog_00427150();

  main_dlog_004273b0(DAT_0059d808,0,0x3f000000,0x3ecccccd,0xa000000,s_GameOverRestart_00559da8);

  main_dlog_00427e80(DAT_0059d808,1,0x3f000000,0x3f19999a,0x8000062);

  main_dlog_00428340(DAT_0059d808,1,s_AGameOverQuit_00559d96 + 2);

  main_dlog_00428340(DAT_0059d808,1,s_GameOverRestart_00559da8);

  DAT_00632aa4._3_1_ = 0;

  return;

}

/* ===== cspec_00450fa0 @ 0x00450FA0 ===== */
void cspec_00450fa0(int param_1)



{

  int iVar1;

  uint uVar2;

  float *pfVar3;

  float fVar4;

  bool bVar5;

  int iVar6;

  int *piVar7;

  float10 fVar8;

  

  iVar1 = *(int *)(param_1 + 0xe8);

  if (iVar1 == 0) {

    *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) & 0xfffffffe;

    return;

  }

  if (iVar1 == 1) {

    pfVar3 = *(float **)(param_1 + 0x100);

    uVar2 = *(uint *)(param_1 + 0x30);

    *(uint *)(param_1 + 0x30) = uVar2 & 0xfffffffe;

    if ((uVar2 & 2) == 0) {

      return;

    }

    fVar8 = (float10)FUN_00518b70(param_1,0);

    fVar8 = (float10)*(float *)(param_1 + 0xec) - fVar8;

    *(float *)(param_1 + 0xec) = (float)fVar8;

    if ((float10)0.0 < fVar8) {

      return;

    }

    *(undefined4 *)(param_1 + 0xec) = 0x3f800000;

    bVar5 = false;

    piVar7 = DAT_00632d70;

    if (DAT_00632d70 != (int *)0x0) {

      do {

        iVar1 = piVar7[3];

        if ((((-1 < (char)((uint)*(undefined4 *)(iVar1 + 0xd8) >> 8)) &&

             (iVar6 = ObjIsMecc(iVar1), iVar6 != 0)) && ((*(uint *)(iVar1 + 0xe0) & 0x2000000) == 0)

            ) && (fVar4 = *pfVar3,

                 fVar8 = (float10)distancesq2d__FP3P3DT0(iVar1 + 0xa0,param_1 + 0xa0),

                 fVar8 < (float10)fVar4 * (float10)fVar4)) {

          bVar5 = true;

        }

        piVar7 = (int *)*piVar7;

      } while (piVar7 != (int *)0x0);

      if (bVar5) {

        if (*(int *)(param_1 + 0x10) == 10) {

          return;

        }

        anim_select_check2(param_1,10);

        return;

      }

    }

  }

  else {

    if (iVar1 != 2) {

      return;

    }

    uVar2 = *(uint *)(param_1 + 0x30);

    pfVar3 = *(float **)(param_1 + 0x100);

    *(uint *)(param_1 + 0x30) = uVar2 & 0xfffffffe;

    if ((uVar2 & 2) == 0) {

      return;

    }

    fVar8 = (float10)FUN_00518b70(param_1,0);

    fVar8 = (float10)*(float *)(param_1 + 0xec) - fVar8;

    *(float *)(param_1 + 0xec) = (float)fVar8;

    if ((float10)0.0 < fVar8) {

      return;

    }

    *(undefined4 *)(param_1 + 0xec) = 0x3f800000;

    bVar5 = false;

    piVar7 = DAT_00632d68;

    if (DAT_00632d68 != (int *)0x0) {

      do {

        iVar1 = piVar7[3];

        if ((((((*(uint *)(iVar1 + 0xd8) & 0x4000c000) == 0) &&

              (*(float *)(iVar1 + 0x278) < *(float *)(iVar1 + 0x1c0))) &&

             (((~*(uint *)(iVar1 + 0x1c8) & 0x20000) == 0 &&

              ((*(int *)(iVar1 + 0x18c) != 1 && (*(int *)(iVar1 + 0x18c) != 9)))))) &&

            (*(char *)(iVar1 + 0x1f5) == '\0')) &&

           (fVar4 = *pfVar3, fVar8 = (float10)distancesq2d__FP3P3DT0(iVar1 + 0xa0,pfVar3 + 1),

           fVar8 < (float10)fVar4 * (float10)fVar4)) {

          bVar5 = true;

        }

        piVar7 = (int *)*piVar7;

      } while (piVar7 != (int *)0x0);

      if (bVar5) {

        if (*(int *)(param_1 + 0x10) == 10) {

          return;

        }

        anim_select_check2(param_1,10);

        return;

      }

    }

  }

  if (*(int *)(param_1 + 0x10) == 1) {

    return;

  }

  anim_select_check2(param_1,1);

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

/* ===== chase_value_time @ 0x00451300 ===== */
/* PS2 candidate: chase_value_time (conf 0.408) */



void chase_value_time(float param_1,float param_2,float param_3,float param_4,float *param_5)



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

/* ===== diff_rangle__Fff @ 0x00451560 ===== */
/* PS2 candidate: diff_rangle__Fff (conf 0.316) */



void diff_rangle__Fff(float *param_1)



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

/* ===== chase_angle @ 0x004515B0 ===== */
/* PS2 candidate: chase_angle (conf 0.317) */



void chase_angle(float param_1,float param_2,float param_3,float *param_4)



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

/* ===== angle_wrap_180 @ 0x00451780 ===== */
void angle_wrap_180(float *param_1,float *param_2)



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

  angle_wrap_180(&param_5,&param_8);

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

  diff_rangle__Fff(&param_8);

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

  angle_wrap_180(&param_3,&param_5);

  fVar4 = (float10)FUN_00518b70(0,0);

  param_6 = (float)(ABS((float10)fVar1 * (float10)param_3) * fVar4);

  param_3 = param_5 - param_2;

  angle_wrap_180(&param_3,&param_2);

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

  diff_rangle__Fff(&param_2);

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

  diff_rangle__Fff(&param_5);

  diff_rangle__Fff(&param_2);

  param_3 = param_3 - param_5;

  angle_wrap_180(&param_3,&param_5);

  fVar4 = (float10)FUN_00518b70(0,0);

  param_6 = (float)(ABS((float10)fVar1 * (float10)param_3) * fVar4);

  param_3 = param_5 - param_2;

  angle_wrap_180(&param_3,&param_2);

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

  diff_rangle__Fff(&param_2);

  *pfVar2 = param_2;

  return;

}

/* ===== render_scene_begin @ 0x00451CF0 ===== */
undefined4 render_scene_begin(void)



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

/* ===== render_scene_end @ 0x00451DA0 ===== */
undefined4 render_scene_end(void)



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

/* ===== option_set_633194 @ 0x00452050 ===== */
void option_set_633194(int param_1)



{

  DAT_00633194 = (uint)(param_1 == 0);

  return;

}

/* ===== option_set_633190 @ 0x00452070 ===== */
void option_set_633190(int param_1)



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

/* ===== option_set_63319c @ 0x004520B0 ===== */
void option_set_63319c(int param_1)



{

  DAT_0063319c = (uint)(param_1 == 0);

  return;

}

/* ===== option_set_6331b0 @ 0x004520D0 ===== */
void option_set_6331b0(int param_1)



{

  DAT_006331b0 = (uint)(param_1 == 0);

  return;

}

/* ===== option_set_6331b4 @ 0x004520F0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void option_set_6331b4(int param_1)



{

  _DAT_006331b4 = (uint)(param_1 == 0);

  return;

}

/* ===== audio_link_option_set @ 0x00452110 ===== */
void audio_link_option_set(int param_1)



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

  video_options_apply();

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

    DAT_00656404 = base_has_partyhouse(DAT_00632bbc);

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

/* ===== icon_slots_reset @ 0x00452A30 ===== */
void icon_slots_reset(int param_1,int param_2)



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

/* ===== icon_slot_in_use_check @ 0x00452EE0 ===== */
undefined4 icon_slot_in_use_check(int param_1)



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

      if (((DAT_0059d99c != 0) && (iVar1 = game_mode_set3_check(DAT_00632f18), iVar1 == 0)) &&

         (iVar1 = game_mode_set6_check(DAT_00632f18), iVar1 == 0)) {

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

      bldg_get_refpt_worldlocdir(DAT_0059d970,1,DAT_00632a88 + 0xa0,DAT_00632a88 + 200);

      object_copy_posdirinfo(DAT_00632a88);

      camera_override_done();

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

      bldg_get_refpt_worldloc(DAT_0059d96c,0xc,local_c);

      bldg_get_refpt_worldloc(DAT_0059d96c,0xe,local_18);

      fVar3 = (float10)FUN_0050a610(local_18,DAT_00632a88 + 0xa0);

      fVar4 = (float10)FUN_0050a610(local_c,DAT_00632a88 + 0xa0);

      if ((float10)(float)fVar3 < fVar4) {

        uVar2 = 0xe;

      }

    }

    else if (*(int *)(DAT_0059d96c + 4) == 0x2e0) {

      bldg_get_refpt_worldloc(DAT_0059d96c,0xc,local_18);

      bldg_get_refpt_worldloc(DAT_0059d96c,0x12,local_c);

      fVar3 = (float10)FUN_0050a610(local_c,DAT_00632a88 + 0xa0);

      fVar4 = (float10)FUN_0050a610(local_18,DAT_00632a88 + 0xa0);

      if ((float10)(float)fVar3 < fVar4) {

        uVar2 = 0x12;

      }

    }

    if (DAT_0059d984 != 0) {

      uVar2 = 1;

    }

    bldg_get_refpt_worldlocdir(DAT_0059d96c,uVar2,DAT_00632a88 + 0xa0,DAT_00632a88 + 200);

    object_copy_posdirinfo(DAT_00632a88);

    camera_override_done();

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

/* ===== cspec_00454be0 @ 0x00454BE0 ===== */
void cspec_00454be0(float param_1)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int *piVar4;

  float *pfVar5;

  float10 fVar6;

  

  iVar1 = (int)param_1;

  piVar4 = *(int **)((int)param_1 + 0x100);

  iVar3 = 0;

  if (*(int *)((int)param_1 + 0xe4) == 0) {

    *(undefined4 *)((int)param_1 + 0xf4) = *(undefined4 *)(DAT_00632ed8 + 0x10e0);

    *(undefined4 *)((int)param_1 + 0xe4) = 1;

    *(undefined4 *)((int)param_1 + 0x278) = 0;

    ObjectSetAnim(param_1,1,0x84,0,0,0);

    *(undefined4 *)(iVar1 + 0x14) = 0x3f800000;

    iVar1 = fx_create(iVar1);

    if (iVar1 == 0) {

      piVar4 = piVar4 + 0x15;

      for (iVar1 = 0x14; iVar1 != 0; iVar1 = iVar1 + -1) {

        *piVar4 = 0;

        piVar4 = piVar4 + 1;

      }

      return;

    }

  }

  else {

    iVar2 = fx_create(param_1);

    if (iVar2 != 0) {

      fVar6 = (float10)FUN_00518b70(iVar1,0);

      if (0 < *piVar4) {

        pfVar5 = (float *)(piVar4 + 0x15);

        do {

          if (0.0 < *pfVar5) {

            param_1 = *pfVar5 - (float)fVar6;

            *pfVar5 = param_1;

            if ((*(int *)(iVar1 + 0x274) != 0) && (param_1 < 0.0 != (param_1 == 0.0))) {

              iVar2 = fx_create(*(int *)(iVar1 + 0x274));

              if (iVar2 == 0) {

                param_1 = (float)CONCAT31(param_1._1_3_,(char)iVar3);

                reaper_00530bd0(iVar1,0,0,1,3,&param_1);

              }

            }

          }

          iVar3 = iVar3 + 1;

          pfVar5 = pfVar5 + 1;

        } while (iVar3 < *piVar4);

      }

      iVar3 = 0;

      if (0 < piVar4[0x29]) {

        pfVar5 = (float *)(piVar4 + 0x3e);

        do {

          if (0.0 < *pfVar5) {

            param_1 = *pfVar5 - (float)fVar6;

            *pfVar5 = param_1;

            if ((*(int *)(iVar1 + 0x274) != 0) && (param_1 < 0.0 != (param_1 == 0.0))) {

              iVar2 = fx_create(*(int *)(iVar1 + 0x274));

              if (iVar2 == 0) {

                param_1 = (float)CONCAT31(param_1._1_3_,(char)iVar3);

                reaper_00530bd0(iVar1,0,0,1,5,&param_1);

              }

            }

          }

          iVar3 = iVar3 + 1;

          pfVar5 = pfVar5 + 1;

        } while (iVar3 < piVar4[0x29]);

      }

    }

  }

  return;

}

/* ===== cspec_00454d70 @ 0x00454D70 ===== */
undefined4 cspec_00454d70(void)



{

  return 0x148;

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

       (iVar3 = objanim_select_animloop(*(undefined4 *)param_4), *(int *)(iVar3 + 0x210) == 0)) {

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

    Dot__FP3P3DT0(&local_c,&local_18);

    fVar1 = (float10)crt_pow_special1();

    if ((float10)57.339447 * fVar1 < (float10)param_3 * (float10)0.5) {

      return 1;

    }

  }

  return 0;

}

/* ===== grid_coords_from_floats @ 0x00455150 ===== */
void grid_coords_from_floats(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)



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

/* ===== ground_get_z @ 0x00455600 ===== */
/* PS2 candidate: ground_get_z (conf 0.399) */



float10 ground_get_z(float param_1)



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

/* ===== project_vector_to_object @ 0x00455920 ===== */
/* PS2 candidate: project_vector_to_object (conf 0.398) */



int project_vector_to_object

              (code *param_1,undefined4 param_2,int *param_3,float *param_4,float *param_5,

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

  puVar1 = (undefined4 *)XFGetCameraAxis(2);

  local_18 = *puVar1;

  local_14 = puVar1[1];

  local_10 = puVar1[2];

  project_vector_to_object(param_1,param_2,param_3,param_4,&local_c,&local_18);

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

      mecc_repairwand_off(param_1);

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

/* ===== obj_children_destroy @ 0x00455E20 ===== */
void obj_children_destroy(int param_1)



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

/* ===== obj_children_destroy_2 @ 0x00455E70 ===== */
void obj_children_destroy_2(int param_1)



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

/* ===== cspec_00456180 @ 0x00456180 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void cspec_00456180(int param_1)



{

  float fVar1;

  float *pfVar2;

  undefined4 *puVar3;

  int iVar4;

  int iVar5;

  uint uVar6;

  int iVar7;

  int *piVar8;

  bool bVar9;

  float10 fVar10;

  float10 fVar11;

  float10 fVar12;

  float fStack_c;

  float fStack_8;

  float fStack_4;

  

  iVar4 = *(int *)(param_1 + 0x100);

  if (*(int *)(iVar4 + 0x30) != 0) {

code_r0x0045629a:

    iVar7 = fx_create(param_1);

    if (iVar7 != 0) {

      if ((*(int *)(param_1 + 0xe4) == 0) && (*(int *)(param_1 + 0xe8) == 1)) {

        *(uint *)(iVar4 + 0x14) = *(uint *)(iVar4 + 0x14) | 0x20;

      }

      pfVar2 = *(float **)(param_1 + 0x100);

      if ((_DAT_0063323c == 0) || (iVar4 = dialog_level_is_base(), iVar4 == 0)) {

        if ((*(float *)(param_1 + 0xec) == 0.0) && (*(int *)(param_1 + 0xe4) != 0)) {

          fVar10 = (float10)FUN_00518b70(param_1,0);

          fVar1 = *pfVar2;

          *pfVar2 = (float)((float10)fVar1 - fVar10);

          if ((float10)fVar1 - fVar10 <= (float10)0.0) {

            *pfVar2 = 2.0;

            puVar3 = DAT_00632d90;

            while( true ) {

              if (puVar3 == (undefined4 *)0x0) {

                *(undefined4 *)(param_1 + 0xec) = 0x40a00000;

                return;

              }

              if (*(int *)(puVar3[3] + 0x274) == param_1) break;

              puVar3 = (undefined4 *)*puVar3;

            }

          }

        }

        else {

          fVar10 = (float10)FUN_00518b70(param_1,0);

          fVar10 = (float10)*(float *)(param_1 + 0xec) - fVar10;

          *(float *)(param_1 + 0xec) = (float)fVar10;

          if (fVar10 < (float10)0.0 != (fVar10 == (float10)0.0)) {

            iVar4 = *(int *)(param_1 + 0x100);

            iVar7 = *(int *)(iVar4 + 8);

            if (0 < iVar7) {

              do {

                iVar5 = *(int *)(*(int *)(iVar4 + 0x30) + *(int *)(iVar4 + 0x2c) * 4);

                fVar10 = (float10)rndfloatrange(-*(float *)(iVar5 + 0xf8),

                                                *(undefined4 *)(iVar5 + 0xf8));

                iVar5 = *(int *)(*(int *)(iVar4 + 0x30) + *(int *)(iVar4 + 0x2c) * 4);

                fVar11 = (float10)rndfloatrange(-*(float *)(iVar5 + 0xf8),

                                                *(undefined4 *)(iVar5 + 0xf8));

                fStack_c = (float)fVar10 + *(float *)(param_1 + 0xa0);

                fStack_8 = (float)fVar11 + *(float *)(param_1 + 0xa4);

                fVar12 = (float10)get_floor_z_point((float *)(param_1 + 0xa0));

                fStack_4 = (float)fVar12;

                iVar5 = herd_create_one(param_1,&fStack_c,0);

                iVar7 = iVar7 + -1;

                *(float *)(iVar5 + 0x178) = (float)fVar10;

                *(float *)(iVar5 + 0x17c) = (float)fVar11;

              } while (iVar7 != 0);

            }

            *(undefined4 *)(param_1 + 0xec) = 0;

            *pfVar2 = 2.0;

            if (*(int *)(param_1 + 0xe4) == 0) {

              *(undefined4 *)(param_1 + 0xe4) = 1;

            }

          }

        }

      }

    }

    return;

  }

  if (*(int *)(iVar4 + 0x1c) == 0) {

    object_destroy(param_1);

    return;

  }

  puVar3 = (undefined4 *)

           MemAllocMsg(0xd,*(int *)(iVar4 + 0x1c) << 2,s_herd_markers_00559efc,

                       s_C__Giants_source_main_herd_c_00559f0c,0x68);

  *(undefined4 **)(iVar4 + 0x30) = puVar3;

  for (uVar6 = *(uint *)(iVar4 + 0x1c) & 0x3fffffff; uVar6 != 0; uVar6 = uVar6 - 1) {

    *puVar3 = 0;

    puVar3 = puVar3 + 1;

  }

  for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {

    *(undefined1 *)puVar3 = 0;

    puVar3 = (undefined4 *)((int)puVar3 + 1);

  }

  iVar7 = 0;

  piVar8 = DAT_00632d68;

  if (DAT_00632d68 != (int *)0x0) {

    do {

      iVar5 = piVar8[3];

      if ((((*(uint *)(iVar5 + 0x1c8) & 0x8000000) != 0) &&

          (*(int *)(iVar5 + 0xe8) == *(int *)(iVar4 + 0x20))) &&

         (*(int *)(iVar5 + 0x174) < *(int *)(iVar4 + 0x1c))) {

        *(int *)(*(int *)(iVar4 + 0x30) + *(int *)(iVar5 + 0x174) * 4) = iVar5;

        iVar7 = iVar7 + 1;

      }

      piVar8 = (int *)*piVar8;

    } while (piVar8 != (int *)0x0);

    if (iVar7 != 0) {

      iVar7 = *(int *)(iVar4 + 0x1c);

      *(int *)(iVar4 + 0x2c) = iVar7;

      iVar5 = *(int *)(param_1 + 0x100);

      bVar9 = iVar7 != *(int *)(iVar5 + 0x2c);

      do {

        *(int *)(iVar4 + 0x2c) = iVar7 + 1;

        if (*(int *)(iVar5 + 0x1c) <= iVar7 + 1) {

          *(undefined4 *)(iVar4 + 0x2c) = 0;

        }

        iVar7 = *(int *)(iVar4 + 0x2c);

      } while (*(int *)(*(int *)(iVar5 + 0x30) + iVar7 * 4) == 0);

      if (bVar9) {

        *(int *)(iVar5 + 0x2c) = iVar7;

      }

      iVar7 = *(int *)(*(int *)(iVar5 + 0x30) + *(int *)(iVar5 + 0x2c) * 4);

      *(undefined4 *)(param_1 + 0xa0) = *(undefined4 *)(iVar7 + 0xa0);

      *(undefined4 *)(param_1 + 0xa4) = *(undefined4 *)(iVar7 + 0xa4);

      *(undefined4 *)(param_1 + 0xa8) = *(undefined4 *)(iVar7 + 0xa8);

      goto code_r0x0045629a;

    }

  }

  object_destroy(param_1);

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

/* ===== cspec_00456660 @ 0x00456660 ===== */
undefined4 cspec_00456660(void)



{

  return 0x34;

}

/* ===== cspec_00456670 @ 0x00456670 ===== */
void cspec_00456670(int param_1)



{

  int iVar1;

  

  iVar1 = *(int *)(*(int *)(param_1 + 0x100) + 0x30);

  if (iVar1 != 0) {

    mem_free_tagged(iVar1,s_C__Giants_source_main_herd_c_00559f0c,0x138);

  }

  return;

}

/* ===== cspec_004566a0 @ 0x004566A0 ===== */
void cspec_004566a0(undefined4 param_1,int param_2,undefined4 param_3,int *param_4)



{

  byte bVar1;

  byte bVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  uint uVar6;

  undefined1 uVar7;

  float10 fVar8;

  float fStack_18;

  float fStack_14;

  float fStack_10;

  float fStack_c;

  float fStack_8;

  float fStack_4;

  

  if (param_2 == 1) {

    iVar4 = objanim_select_animloop(param_4[3]);

    if (iVar4 == 0) {

      fStack_c = (float)(int)(short)param_4[1] * 0.5;

      fStack_8 = (float)(int)*(short *)((int)param_4 + 6) * 0.5;

      fVar8 = (float10)ground_get_z(&fStack_c);

      fStack_4 = (float)fVar8;

      iVar5 = herd_create_one(param_1,&fStack_c,param_4[3]);

      fStack_18 = (float)(int)(short)param_4[2] * 0.5;

      fStack_14 = (float)(int)*(short *)((int)param_4 + 10) * 0.5;

      fVar8 = (float10)ground_get_z(&fStack_18);

      iVar3 = *(int *)(iVar5 + 0x100);

      *(float *)(iVar3 + 0x40) = fStack_18;

      *(float *)(iVar3 + 0x44) = fStack_14;

      *(float *)(iVar3 + 0x48) = (float)fVar8;

      iVar4 = *param_4;

      *(int *)(iVar3 + 0x50) = iVar4;

      *(int *)(iVar3 + 0x4c) = iVar4;

      if (*param_4 == 0x3e4ccccd) {

        *(undefined4 *)(iVar5 + 0x1c0) = *(undefined4 *)(DAT_00632ed8 + 3000);

        return;

      }

      if (*param_4 == 0x3f000000) {

        *(undefined4 *)(iVar5 + 0x1c0) = *(undefined4 *)(DAT_00632ed8 + 0xbbc);

        return;

      }

      *(undefined4 *)(iVar5 + 0x1c0) = *(undefined4 *)(DAT_00632ed8 + 0xbc0);

    }

  }

  else if (param_2 == 2) {

    bVar1 = *(byte *)((int)param_4 + 0x15);

    uVar6 = (uint)(char)bVar1;

    fStack_18 = (float)(int)(short)*param_4 * 0.5;

    bVar2 = *(byte *)(param_4 + 5);

    fStack_14 = (float)(int)*(short *)((int)param_4 + 2) * 0.5;

    fStack_10 = (float)(int)(short)param_4[1] * 0.5;

    iVar4 = create_one_vimp_chunk

                      (&fStack_18,uVar6,bVar2,(*(uint *)((int)param_4 + 0x12) & 0xff) + 0x45d,

                       (float)(int)(short)param_4[3] * 0.1);

    *(float *)(iVar4 + 0x10c) = (float)(int)*(short *)((int)param_4 + 6) * 0.0625;

    *(float *)(iVar4 + 0x110) = (float)(int)(short)param_4[2] * 0.0625;

    *(float *)(iVar4 + 0x108) = (float)(int)*(short *)((int)param_4 + 10) * 0.0625;

    *(undefined4 *)(iVar4 + 0x188) = *(undefined4 *)((int)param_4 + 0xe);

    if ((uVar6 & 0x10) != 0) {

      if ((bVar1 & 0x40) == 0) {

        uVar7 = (bVar1 & 0x80) != 0;

      }

      else {

        uVar7 = 2;

      }

      func_0x00512950(&fStack_18,uVar6 & 0x20,(float)bVar2,uVar7);

      return;

    }

  }

  return;

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

/* ===== playerobj_lookud @ 0x00456D00 ===== */
/* PS2 candidate: playerobj_lookud (conf 0.412) */



void playerobj_lookud(undefined4 param_1,undefined4 param_2,undefined4 param_3,float param_4,

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

             (iVar5 = ObjIsReaperBldg(iVar1), iVar5 == 0)) &&

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

/* ===== line_damage_with_slope @ 0x00456EE0 ===== */
void line_damage_with_slope

               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,

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

  damage_voice_trigger(param_3);

  return;

}

/* ===== obj_shot_expire_destroy @ 0x00457100 ===== */
void obj_shot_expire_destroy

               (int param_1,undefined4 param_2,int param_3,int param_4,undefined4 param_5,

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

/* ===== death_pose_setup @ 0x004571A0 ===== */
int death_pose_setup(int param_1,int *param_2,int param_3)



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

    uVar1 = anm_apply_nodes(param_1,0,local_70);

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

    reg_query_value_3(s_SessionName_0055a018,&DAT_00632f48,0x20);

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

  icon_slots_reset(1,0);

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

    reg_query_value_2(s_WorldName_0055a068,&DAT_00633070,0x20);

    reg_query_value_2(s_MPWorldName_0055a05c,&DAT_00632ee8,0x20);

  }

  DAT_00632d20 = session_table_lookup(&DAT_00633070);

  DAT_00632ee4 = session_table_lookup(&DAT_00632ee8);

  mission_0051a0c0(s_FarClipIndex_0055a04c,&DAT_006331bc);

  comm_session_init();

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

    reg_query_value_5(s_DefPlayer_0055a07c,&DAT_0063304c,0x20);

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

      icon_slots_reset(1,uVar5);

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

/* ===== player_has_weapon @ 0x00457A70 ===== */
bool player_has_weapon(int param_1,int param_2)



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

  if ((iVar1 != 0) && (iVar1 = IconDef_0x68_get(param_2), iVar1 == 4)) {

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

/* ===== mecc_slot_scan @ 0x00457D10 ===== */
undefined4 mecc_slot_scan(int param_1)



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

/* ===== WeaponIdSet__FP6OBJECTii @ 0x00457F40 ===== */
/* PS2 candidate: WeaponIdSet__FP6OBJECTii (conf 0.378) */



void WeaponIdSet__FP6OBJECTii(int param_1,int param_2,int param_3)



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

/* ===== WeaponIdSetPresent__FP6OBJECTi @ 0x00458230 ===== */
/* PS2 candidate: WeaponIdSetPresent__FP6OBJECTi (conf 0.374) */



void WeaponIdSetPresent__FP6OBJECTi(int param_1)



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

/* ===== TeamMemberInitWeapons__FP6OBJECT @ 0x00458710 ===== */
/* PS2 candidate: TeamMemberInitWeapons__FP6OBJECT (conf 0.378) */



void TeamMemberInitWeapons__FP6OBJECT(int param_1)



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

    iVar4 = icon_slot_in_use_check(3);

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

/* ===== teammate_copy_weapons @ 0x00458BF0 ===== */
void teammate_copy_weapons(int param_1,int param_2)



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

/* ===== IconDef_wield_eq1 @ 0x00458C90 ===== */
bool IconDef_wield_eq1(undefined4 param_1)



{

  int iVar1;

  

  iVar1 = IconDef_0x68_get(param_1);

  return iVar1 == 1;

}

/* ===== IconDef_wield_eq2 @ 0x00458CB0 ===== */
bool IconDef_wield_eq2(undefined4 param_1)



{

  int iVar1;

  

  iVar1 = IconDef_0x68_get(param_1);

  return iVar1 == 2;

}

/* ===== IconDef_wield_eq4 @ 0x00458CD0 ===== */
bool IconDef_wield_eq4(undefined4 param_1)



{

  int iVar1;

  

  iVar1 = IconDef_0x68_get(param_1);

  return iVar1 == 4;

}

/* ===== IconDef_wield_is12 @ 0x00458CF0 ===== */
undefined4 IconDef_wield_is12(undefined4 param_1)



{

  int iVar1;

  

  iVar1 = IconDef_0x6c_get(param_1);

  if (iVar1 != 2) {

    iVar1 = IconDef_0x6c_get(param_1);

    if (iVar1 != 1) {

      return 0;

    }

  }

  return 1;

}

/* ===== IconDef_wield_is13 @ 0x00458D20 ===== */
undefined4 IconDef_wield_is13(undefined4 param_1)



{

  int iVar1;

  

  iVar1 = IconDef_0x6c_get(param_1);

  if (iVar1 != 3) {

    iVar1 = IconDef_0x6c_get(param_1);

    if (iVar1 != 1) {

      return 0;

    }

  }

  return 1;

}

/* ===== IconDef_wield_eq5 @ 0x00458D50 ===== */
bool IconDef_wield_eq5(undefined4 param_1)



{

  int iVar1;

  

  iVar1 = IconDef_0x68_get(param_1);

  return iVar1 == 5;

}

/* ===== IconDef_wield_eq3 @ 0x00458D70 ===== */
bool IconDef_wield_eq3(undefined4 param_1)



{

  int iVar1;

  

  iVar1 = IconDef_0x68_get(param_1);

  return iVar1 == 3;

}

/* ===== cspec_00458f60 @ 0x00458F60 ===== */
void cspec_00458f60(int param_1)



{

  float *pfVar1;

  float *pfVar2;

  float fVar3;

  undefined4 *puVar4;

  undefined4 uVar5;

  int iVar6;

  int iVar7;

  float10 fVar8;

  char *pcVar9;

  int *piStack_1c;

  int *piStack_18;

  undefined4 uStack_14;

  undefined4 uStack_10;

  undefined1 auStack_c [12];

  

  puVar4 = *(undefined4 **)(param_1 + 0x100);

  *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) | 0x40;

  fVar8 = (float10)FUN_00518b70(param_1,0);

  object_animate_process(param_1,(float)fVar8);

  ObjectCalculateTransform(param_1);

  if (DAT_00632e74 == 0) {

    if ((*(byte *)(param_1 + 0xe0) & 1) == 0) {

      uVar5 = func_0x00457da0(*(undefined4 *)(param_1 + 4));

      *puVar4 = uVar5;

      puVar4[1] = 0xffffffff;

      *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 1;

    }

    if (*(int *)(param_1 + 0xe4) == 1) {

      iVar6 = fx_create(param_1);

      if (iVar6 != 0) {

        fVar8 = (float10)FUN_00518b70(param_1,0);

        fVar8 = (float10)*(float *)(param_1 + 0xec) - fVar8;

        *(float *)(param_1 + 0xec) = (float)fVar8;

        if (fVar8 < (float10)0.0) {

          if ((puVar4[7] == 0) || (iVar6 = objanim_select_animloop(puVar4[6]), iVar6 != 0)) {

            *(undefined4 *)(param_1 + 0xe4) = 0;

            *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) & 0xbfffffff;

            iVar6 = reaper_0052e4a0(param_1);

            if (iVar6 != 0) {

              reaper_00530bd0(param_1,0,0,0,1,0);

              return;

            }

          }

          else {

            object_destroy(param_1);

            iVar6 = reaper_0052e4a0(param_1);

            if (iVar6 != 0) {

              reaper_00530bd0(param_1,0,0,0,3,0);

              return;

            }

          }

        }

      }

    }

    else {

      iVar6 = *(int *)(param_1 + 4);

      if (((iVar6 != 0x44d) && (iVar6 != 0x44c)) && (iVar6 != 1099)) {

        if ((*(float *)(param_1 + 0x140) + 3.0 < *(float *)(param_1 + 0xa8)) || (DAT_00632b90 != 0))

        {

          fVar8 = (float10)ground_get_z(param_1 + 0xa0);

          *(float *)(param_1 + 0x140) = (float)fVar8;

        }

        if (*(float *)(param_1 + 0x140) + 3.0 < *(float *)(param_1 + 0xa8)) {

          pfVar1 = (float *)(param_1 + 0xa0);

          pfVar2 = (float *)(param_1 + 0xac);

          *pfVar2 = *pfVar1;

          *(undefined4 *)(param_1 + 0xb0) = *(undefined4 *)(param_1 + 0xa4);

          *(undefined4 *)(param_1 + 0xb4) = *(undefined4 *)(param_1 + 0xa8);

          fVar8 = (float10)FUN_00518b70(param_1,0);

          *(float *)(param_1 + 0xa8) =

               (float)(fVar8 * (float10)*(float *)(param_1 + 0x130) +

                      (float10)*(float *)(param_1 + 0xa8));

          fVar8 = (float10)FUN_00518b70(param_1,0);

          *(float *)(param_1 + 0x130) =

               (float)((float10)*(float *)(param_1 + 0x130) - fVar8 * (float10)40.0);

          fVar8 = (float10)FUN_00518b70(param_1,0);

          *pfVar1 = (float)(fVar8 * (float10)*(float *)(param_1 + 0x128) + (float10)*pfVar1);

          fVar8 = (float10)FUN_00518b70(param_1,0);

          *(float *)(param_1 + 0xa4) =

               (float)(fVar8 * (float10)*(float *)(param_1 + 300) +

                      (float10)*(float *)(param_1 + 0xa4));

          for (piStack_18 = DAT_00632d7c; piStack_18 != (int *)0x0; piStack_18 = (int *)*piStack_18)

          {

            iVar6 = piStack_18[3];

            if ((((param_1 != iVar6) && (*(int *)(iVar6 + 0x210) == 0)) &&

                ((puVar4[3] != iVar6 &&

                 (((~*(uint *)(iVar6 + 0x1c8) >> 0x11 & 1) == 0 &&

                   (*(uint *)(iVar6 + 0xd8) & 0x4000c000) == 0 &&

                  (iVar7 = collide_line_bbox(auStack_c,pfVar2,pfVar1,iVar6 + 0x27c), iVar7 != 0)))))

                ) && ((uStack_10 = 0, (*(uint *)(iVar6 + 0x1c8) & 0x1000000) != 0 ||

                      (iVar6 = los_line_check(pfVar2,pfVar1,iVar6,auStack_c,&uStack_10), iVar6 != 0)

                      ))) {

              *pfVar1 = *pfVar2;

              *(undefined4 *)(param_1 + 0xa4) = *(undefined4 *)(param_1 + 0xb0);

              *(undefined4 *)(param_1 + 0xa8) = *(undefined4 *)(param_1 + 0xb4);

              break;

            }

          }

        }

        fVar3 = *(float *)(param_1 + 0x140) + 3.0;

        if (*(float *)(param_1 + 0xa8) <= fVar3) {

          *(float *)(param_1 + 0xa8) = fVar3;

          *(undefined4 *)(param_1 + 0x128) = 0;

          *(undefined4 *)(param_1 + 300) = 0;

          *(undefined4 *)(param_1 + 0x130) = 0;

        }

      }

      if (*(int *)(param_1 + 0xe4) == 0) {

        if (*(float *)(param_1 + 0x1d4) == 0.0) {

          *(undefined4 *)(param_1 + 0x1d4) = 0x40000000;

        }

        fVar8 = (float10)FUN_00518b70(param_1,0);

        fVar8 = fVar8 * (float10)90.0 + (float10)*(float *)(param_1 + 200);

        *(float *)(param_1 + 200) = (float)fVar8;

        if ((float10)360.0 < fVar8) {

          do {

            fVar8 = fVar8 - (float10)360.0;

          } while ((float10)360.0 < fVar8);

          *(float *)(param_1 + 200) = (float)fVar8;

        }

        if ((*(int *)(param_1 + 0xe8) == 0) && (0.0 < (float)puVar4[5])) {

          fVar8 = (float10)FUN_00518b70(param_1,0);

          fVar8 = (float10)(float)puVar4[5] - fVar8;

          puVar4[5] = (float)fVar8;

          if (fVar8 < (float10)0.0 != (fVar8 == (float10)0.0)) {

            object_destroy(param_1);

            iVar6 = reaper_0052e4a0(param_1);

            if (iVar6 != 0) {

              reaper_00530bd0(param_1,0,0,0,3,0);

            }

          }

        }

      }

      fVar8 = (float10)FUN_00518b70(param_1,0);

      fVar3 = (float)puVar4[4];

      puVar4[4] = (float)((float10)fVar3 - fVar8);

      if ((float10)fVar3 - fVar8 < (float10)0.0) {

        puVar4[4] = 0;

      }

      iVar6 = DAT_00632a88;

      piStack_1c = (int *)*puVar4;

      iVar7 = ObjIsKabuto(DAT_00632a88);

      if (((((iVar7 == 0) && ((*(uint *)(iVar6 + 0xd8) & 0x4000c000) == 0)) &&

           ((*(byte *)(iVar6 + 0x1c8) & 1) != 0)) &&

          (*(float *)(iVar6 + 0x278) < *(float *)(iVar6 + 0x1c0))) &&

         (((puVar4[3] != iVar6 || ((float)puVar4[4] <= 0.0)) &&

          ((iVar7 = inv_check_pickup(iVar6,&piStack_1c), iVar7 != 0 &&

           (iVar7 = collide_bbox_bbox(iVar6 + 0x27c,param_1 + 0x27c), iVar7 != 0)))))) {

        if ((*(byte *)(param_1 + 0xe0) & 6) == 0) {

          uStack_14 = *(undefined4 *)(iVar6 + 0x188);

          piStack_18 = piStack_1c;

          reaper_00530bd0(param_1,0,2,0,2,&piStack_18);

          inv_award_item(iVar6,0xffffffff,piStack_1c,puVar4[1],0);

          func_0x00458d90(iVar6,piStack_1c);

          if (*(int *)(param_1 + 0xe8) != 0) {

            *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) | 0x40000000;

            *(undefined4 *)(param_1 + 0xe4) = 1;

            *(undefined4 *)(param_1 + 0xec) =

                 *(undefined4 *)(s_WorldLoading_0055a0fc + *(int *)(param_1 + 0xe8) * 4 + 0xc);

            return;

          }

          object_destroy(param_1);

          return;

        }

        sound_play_player(0x63c,iVar6);

        iVar7 = ObjIsKabuto(iVar6);

        fVar3 = (float)(int)puVar4[1];

        if (iVar7 != 0) {

          fVar3 = fVar3 * 10.0;

        }

        *(float *)(iVar6 + 0x278) = *(float *)(iVar6 + 0x278) - fVar3;

        if (*(float *)(iVar6 + 0x278) < 0.0) {

          *(undefined4 *)(iVar6 + 0x278) = 0;

        }

        object_destroy(param_1);

        if ((*(uint *)(param_1 + 0xe0) & 2) == 0) {

          if ((*(uint *)(param_1 + 0xe0) & 4) == 0) {

            return;

          }

          pcVar9 = s_CInstantHealthLarge_0055a11f + 1;

        }

        else {

          pcVar9 = s_InstantHealthMed_0055a134;

        }

        uVar5 = FUN_00507b00(pcVar9);

        chat_insert(uVar5,1);

      }

    }

  }

  return;

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

      iVar3 = IconDef_wield_is13(uVar1);

      if (iVar3 == 0) {

        return false;

      }

      iVar3 = IconDef_wield_eq1(uVar1);

      if ((iVar3 != 0) &&

         ((iVar3 = reaper_has_bow_2(iVar6,uVar1), iVar3 != 0 ||

          (iVar3 = reaper_has_bow_2(iVar6), iVar3 < 0)))) {

        iVar3 = IconDef_wield_eq1(uVar1);

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

      iVar3 = IconDef_wield_eq4(uVar1);

      if ((iVar3 != 0) && (iVar3 = reaper_needs_ammo(iVar6,uVar1), iVar3 == 0)) {

        return false;

      }

      iVar3 = IconDef_wield_eq5(uVar1);

      if (iVar3 != 0) {

        uVar7 = IconDefMaxAmmo(uVar1);

        iVar3 = reaper_needs_other(iVar6,uVar1,uVar7);

        if (iVar3 == 0) {

          return false;

        }

      }

      iVar3 = IconDef_wield_eq3(uVar1);

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

  iVar4 = IconDef_wield_is12(uVar1);

  if (iVar4 == 0) {

    return false;

  }

  iVar4 = IconDef_wield_eq1(uVar1);

  if ((iVar4 == 0) || (iVar4 = player_has_weapon(iVar6,uVar1), iVar4 == 0)) {

    iVar4 = IconDef_wield_eq1(uVar1);

    if ((iVar4 != 0) && (iVar4 = mecc_slot_scan(iVar6), iVar4 == 0)) {

      return false;

    }

  }

  else {

    iVar3 = player_has_weapon(iVar6,uVar1);

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

  iVar4 = IconDef_wield_eq4(uVar1);

  if ((iVar4 != 0) && (iVar4 = player_needs_ammo__FP6OBJECTi(iVar6,uVar1), iVar4 == 0)) {

    return false;

  }

  iVar4 = IconDef_wield_eq3(uVar1);

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

      iVar2 = IconDef_wield_eq4(param_3);

      if (iVar2 == 0) {

        iVar2 = IconDef_wield_eq1(param_3);

        if (iVar2 == 0) {

          iVar2 = IconDef_wield_eq5(param_3);

          if (iVar2 == 0) {

            iVar2 = IconDef_wield_eq3(param_3);

            if (iVar2 != 0) {

              reaper_item_find_slot(param_1,param_3,0xffffffff);

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

    iVar3 = IconDef_wield_eq3(param_3);

    if (iVar3 == 0) {

      iVar3 = IconDef_wield_eq4(param_3);

      if (iVar3 == 0) {

        iVar3 = IconDef_wield_eq1(param_3);

        if (iVar3 == 0) {

          iVar3 = IconDef_wield_eq2(param_3);

          if ((iVar3 == 0) && (iVar3 = IconDef_wield_eq5(param_3), iVar3 == 0)) {

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

          iVar2 = player_has_weapon(param_1,param_3);

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

/* ===== inv_remove_item @ 0x00459F10 ===== */
/* PS2 candidate: inv_remove_item (conf 0.404) */



void inv_remove_item(int param_1,undefined4 *param_2,undefined4 param_3,int param_4)



{

  int *piVar1;

  int iVar2;

  float fVar3;

  undefined4 uVar4;

  int iVar5;

  int iVar6;

  

  uVar4 = param_3;

  iVar2 = *(int *)(param_1 + 0x100);

  iVar5 = IconDef_wield_eq3(param_3);

  if (iVar5 != 0) {

    SpecialWeaponIdSet__FP6OBJECTi(param_1,0xffffffff);

    return;

  }

  iVar5 = IconDef_wield_eq4(uVar4);

  if (iVar5 == 0) {

    iVar6 = IconDef_wield_eq1(uVar4);

    iVar5 = (int)param_2;

    if (iVar6 == 0) {

      iVar5 = IconDef_wield_eq2(uVar4);

      if ((iVar5 != 0) || (iVar5 = IconDef_wield_eq5(uVar4), iVar5 != 0)) {

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

      WeaponIdSet__FP6OBJECTii(param_1,iVar5,0xffffffff);

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

/* ===== cspec_0045a1f0 @ 0x0045A1F0 ===== */
void cspec_0045a1f0(int param_1,int param_2,undefined4 param_3,undefined4 *param_4)



{

  int iVar1;

  int iVar2;

  

  if (param_2 == 1) {

    *(undefined4 *)(param_1 + 0xec) = 0;

    *(undefined4 *)(param_1 + 0xe4) = 0;

    *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) & 0xbfffffff;

  }

  else {

    if (param_2 == 2) {

      iVar1 = *(int *)(param_1 + 0x100);

      iVar2 = objanim_select_animloop(param_4[1]);

      if (iVar2 != 0) {

        inv_award_item(iVar2,0xffffffff,*param_4,*(undefined4 *)(iVar1 + 4),0);

        func_0x00458d90(iVar2,*param_4);

      }

      if (*(int *)(param_1 + 0xe8) == 0) {

        object_destroy(param_1);

        return;

      }

      *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) | 0x40000000;

      *(undefined4 *)(param_1 + 0xe4) = 1;

      *(undefined4 *)(param_1 + 0xec) =

           *(undefined4 *)(s_WorldLoading_0055a0fc + *(int *)(param_1 + 0xe8) * 4 + 0xc);

      return;

    }

    if (param_2 == 3) {

      object_destroy(param_1);

      return;

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

      iVar1 = mine_find_of_owner(param_1);

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

      if ((((iVar2 != 0) && (iVar2 = mine_find_of_owner(param_1), iVar2 != 0)) &&

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

  

  iVar2 = IconDef_0x50_get(param_2);

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

  fVar3 = (float10)ground_get_z((undefined4 *)(iVar2 + 0xa0));

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

  

  iVar3 = IconDef_0x50_get(param_2);

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

      fVar6 = (float10)math_sin_lut_read_b(fVar1);

      fVar7 = (float10)math_sin_lut_read_a(fVar1);

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

        fVar6 = (float10)math_sin_lut_read_b(fVar1);

        fVar7 = (float10)math_sin_lut_read_a(fVar1);

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

      fVar6 = (float10)math_sin_lut_read_b(fVar1);

      fVar7 = (float10)math_sin_lut_read_a(fVar1);

      uVar4 = SpecialWeaponIdGet__FP6OBJECT

                        (puVar2,1,(float)fVar6 * 6.0,(float)(fVar7 * (float10)6.0),0x41280000,

                         0x41f00000);

      item_drop_item(puVar2,uVar4);

    }

    return;

  }

  return;

}

/* ===== cspec_0045ae60 @ 0x0045AE60 ===== */
undefined4 cspec_0045ae60(void)



{

  return 0x20;

}

/* ===== cspec_0045ae70 @ 0x0045AE70 ===== */
void cspec_0045ae70(int param_1)



{

  int iVar1;

  int *piVar2;

  

  piVar2 = (int *)(*(int *)(param_1 + 0x100) + 0xc);

  iVar1 = *piVar2;

  if ((iVar1 != 0) && ((char)((uint)*(undefined4 *)(iVar1 + 0xd8) >> 8) < '\0')) {

    *piVar2 = 0;

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

    iVar2 = ObjIsReaperBldg(param_2);

    if (((iVar2 == 0) || (iVar2 = meccbasepit_bldg_from_object(param_2), iVar2 < 0)) ||

       (iVar2 = dialog_level_is_base(), iVar2 == 0)) goto LAB_0045af46;

    iVar2 = game_mode_set6_check(DAT_00632f18);

  }

  else {

    iVar2 = meccbasepit_bldg_from_object();

    if ((iVar2 < 0) || (iVar2 = dialog_level_is_base(), iVar2 == 0)) goto LAB_0045af46;

    iVar2 = game_mode_set6_check(DAT_00632f18);

  }

  if ((iVar2 == 0) && (iVar2 = game_mode_set5_check(DAT_00632f18), iVar2 == 0)) {

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

    reaper_ospec_ptr48_set(iVar1,&LAB_0045afe0);

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

      smartie_release_to_bldg();

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

    fVar3 = (float10)powf();

    reaper_ospec_init(iVar1,param_3,param_4,(float)(fVar3 / (float10)param_5),0x3f400000);

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

    reaper_ospec_ptr48_set(iVar1,&LAB_0045afe0);

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

      smartie_release_to_bldg();

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

    fVar3 = (float10)powf();

    reaper_ospec_init(iVar1,&local_2c,param_3,(float)(fVar3 / (float10)param_4),0x3f400000);

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

/* ===== FootDust @ 0x0045B7F0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* PS2 candidate: FootDust (conf 0.415) */



void FootDust(float param_1,float param_2,float param_3,float param_4)



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

  if ((iVar3 == 0) && (iVar3 = obj_is_type0f(param_1), iVar3 == 0)) {

    iVar4 = ObjIsKabuto(*(undefined4 *)(param_1 + 0x274));

    if ((iVar4 == 0) && (iVar4 = obj_is_type0f(*(undefined4 *)(param_1 + 0x274)), iVar4 == 0)) {

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

    attack_fx_spawn(uVar5);

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

/* ===== kabuto_bite_damage @ 0x0045BD90 ===== */
undefined4 kabuto_bite_damage(int param_1,float param_2,byte param_3)



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

/* ===== cspec_0045be30 @ 0x0045BE30 ===== */
bool cspec_0045be30(int param_1,int param_2)



{

  uint uVar1;

  uint uVar2;

  

  if ((param_2 == 0) || (*(int *)(param_2 + 4) == 0x29d)) {

    return true;

  }

  if (*(float *)(param_2 + 0x290) <= *(float *)(param_1 + 0xc4) * 35.0 + *(float *)(param_1 + 0xa8))

  {

    if ((*(float *)(param_1 + 0xc4) * 20.0 + *(float *)(param_1 + 0xa8) <

         *(float *)(param_2 + 0x290)) ||

       (uVar2 = 1, 20.0 < *(float *)(param_2 + 0x154) * *(float *)(param_1 + 0xc4))) {

      uVar2 = 3;

    }

  }

  else {

    uVar2 = 7;

  }

  uVar1 = *(uint *)(param_2 + 0x1cc);

  if ((~uVar1 & 1) == 0) {

    uVar2 = 0;

  }

  else {

    if ((uVar1 & 0x3c00) != 0) {

      uVar2 = uVar2 & 0xfffffffe;

    }

    if ((uVar1 & 0x3c0) != 0) {

      uVar2 = uVar2 & 0xfffffffd;

    }

    if ((uVar1 & 0x3c) != 0) {

      uVar2 = uVar2 & 0xfffffffb;

    }

    if ((~uVar1 & 2) != 0) {

      *(int *)(param_2 + 0x220) = param_1;

      return uVar2 == 0;

    }

  }

  return uVar2 == 0;

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

/* ===== obj_scale_flag_get @ 0x0045D2E0 ===== */
float10 obj_scale_flag_get(int param_1)



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

  uVar6 = object_find(puVar3[1]);

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

    GEO_MatIdentity(uVar6 + 0x294);

    *param_1 = uVar6;

    param_1 = param_1 + 7;

    local_4 = local_4 + -1;

  } while (local_4 != 0);

  uVar6 = object_allocate_type_end(0x3d4,0);

  object_change_ospec(uVar6,0);

  *(uint *)(uVar6 + 0x18c) = puVar3[99];

  *(uint *)(uVar6 + 0x1c8) = *(uint *)(uVar6 + 0x1c8) | 0xe00;

  *(uint *)(uVar6 + 0xd8) = *(uint *)(uVar6 + 0xd8) | 0x40010000;

  GEO_MatIdentity(uVar6 + 0x294);

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

    iVar5 = game_mode_set3_check(DAT_00632f18);

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

/* ===== cspec_0045d880 @ 0x0045D880 ===== */
void cspec_0045d880(int param_1)



{

  int *piVar1;

  int iVar2;

  int *piVar3;

  int iVar4;

  int *piVar5;

  

  iVar2 = *(int *)(param_1 + 0x100);

  obj_ptr_clear_if_dead(iVar2 + 0x54);

  obj_ptr_clear_if_dead(iVar2 + 0x50);

  obj_ptr_clear_if_dead(iVar2 + 0x4c);

  obj_ptr_clear_if_dead(iVar2 + 0x5c);

  obj_ptr_clear_if_dead(iVar2 + 0x88);

  piVar3 = (int *)(iVar2 + 0x10);

  iVar4 = 2;

  piVar5 = piVar3;

  do {

    obj_ptr_clear_if_dead(piVar5);

    piVar5 = piVar5 + 1;

    iVar4 = iVar4 + -1;

  } while (iVar4 != 0);

  piVar5 = (int *)(iVar2 + 8);

  obj_ptr_clear_if_dead(piVar5);

  piVar1 = (int *)(iVar2 + 0xc);

  obj_ptr_clear_if_dead(piVar1);

  obj_ptr_clear_if_dead(iVar2 + 0x150);

  iVar4 = 2;

  do {

    if ((*piVar3 != 0) && (*(int *)(*piVar3 + 0x210) != param_1)) {

      *piVar3 = 0;

    }

    piVar3 = piVar3 + 1;

    iVar4 = iVar4 + -1;

  } while (iVar4 != 0);

  if ((*piVar5 != 0) && (*(int *)(*piVar5 + 0x210) != param_1)) {

    *piVar5 = 0;

  }

  if ((*piVar1 != 0) && (*(int *)(*piVar1 + 0x210) != param_1)) {

    *piVar1 = 0;

  }

  obj_ptr_clear_if_dead(iVar2 + 800);

  obj_ptr_clear_if_dead(iVar2 + 0x324);

  return;

}

/* ===== cspec_0045d980 @ 0x0045D980 ===== */
void cspec_0045d980(int param_1)



{

  int iVar1;

  undefined4 *puVar2;

  int *piVar3;

  int iVar4;

  

  iVar1 = *(int *)(param_1 + 0x100);

  for (puVar2 = DAT_00632d68; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {

    if (*(int *)(puVar2[3] + 0x210) == param_1) {

      object_destroy(puVar2[3]);

    }

  }

  piVar3 = (int *)(iVar1 + 0x22c);

  iVar4 = 8;

  do {

    if (*piVar3 != 0) {

      object_destroy(*piVar3);

    }

    piVar3 = piVar3 + 7;

    iVar4 = iVar4 + -1;

  } while (iVar4 != 0);

  if (*(int *)(iVar1 + 0x314) != 0) {

    object_destroy(*(int *)(iVar1 + 0x314));

  }

  piVar3 = *(int **)(iVar1 + 0x220);

  if (piVar3 != (int *)0x0) {

    *(int *)piVar3[1] = *piVar3;

    *(int *)(*piVar3 + 4) = piVar3[1];

    *piVar3 = (int)piVar3;

    piVar3[1] = (int)piVar3;

    iVar4 = LNK_DNodeInDList(&DAT_00632a80);

    if (iVar4 == 0) {

      mem_free_tagged(DAT_00632a64,s_C__Giants_source_Main_kabuto_c_0055b318,0x1f25);

      DAT_00632a64 = 0;

      main_00508840(&DAT_00632a60);

      DAT_0059da1c = 0;

    }

    mem_free_tagged(piVar3,s_C__Giants_source_Main_kabuto_c_0055b318,0x1f2c);

  }

  if (*(int *)(iVar1 + 0x32c) != 0) {

    object_destroy(*(int *)(iVar1 + 0x32c));

    *(undefined4 *)(iVar1 + 0x32c) = 0;

  }

  return;

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

          fVar9 = (float10)ground_get_z((undefined4 *)(iVar4 + 0xa0));

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

    object_animate_process(param_1,(float)fVar9);

  }

  iVar5 = *(int *)(iVar4 + 0x220);

  *(undefined4 *)(iVar5 + 0x50) = 0;

  if ((DAT_00632a88 == param_1) && (*(char *)(iVar4 + 0x228) != '\0')) {

    pfVar7 = (float *)XFGetCameraAxis(2);

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

    attack_fx_spawn(uVar2);

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

/* ===== reaper_ai_main @ 0x0045ECE0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void reaper_ai_main(int param_1)



{

  ushort uVar1;

  uint *puVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  undefined4 *puVar6;

  byte bVar7;

  int iVar8;

  undefined4 uVar9;

  uint uVar10;

  int iVar11;

  uint *puVar12;

  float *pfVar13;

  int iVar14;

  int iVar15;

  char *pcVar16;

  ushort uVar17;

  uint uVar18;

  uint uVar19;

  char cVar20;

  float fVar21;

  uint uVar22;

  float fVar23;

  bool bVar24;

  bool bVar25;

  float10 fVar26;

  uint uStack_1f4;

  float fStack_1f0;

  float fStack_1ec;

  float fStack_1e8;

  float fStack_1e4;

  float fStack_1e0;

  float fStack_1dc;

  uint uStack_1d8;

  float fStack_1d4;

  float fStack_1d0;

  float fStack_1cc;

  uint uStack_1c8;

  int iStack_1c4;

  float fStack_1c0;

  float fStack_1bc;

  float fStack_1b8;

  float fStack_1b4;

  uint uStack_1b0;

  uint uStack_1ac;

  float fStack_1a8;

  int iStack_1a4;

  float fStack_1a0;

  uint uStack_19c;

  float fStack_198;

  float fStack_194;

  float fStack_190;

  undefined1 uStack_18c;

  int iStack_188;

  float fStack_184;

  uint uStack_180;

  float fStack_17c;

  uint uStack_178;

  float fStack_174;

  float fStack_170;

  undefined4 uStack_16c;

  float fStack_168;

  float fStack_164;

  float fStack_160;

  float fStack_15c;

  float fStack_158;

  float fStack_154;

  undefined4 uStack_150;

  undefined4 uStack_14c;

  int iStack_148;

  undefined1 auStack_144 [12];

  float fStack_138;

  float fStack_134;

  float fStack_128;

  float fStack_124;

  float fStack_118;

  float fStack_114;

  undefined1 auStack_100 [256];

  

  puVar2 = *(uint **)(param_1 + 0x100);

  fStack_17c = 0.0;

  if (DAT_00633124 != 0) {

    *(undefined4 *)(param_1 + 0x208) = 0;

    *(undefined4 *)(param_1 + 0x20c) = 0;

  }

  iVar8 = kabuto_init(param_1);

  if (iVar8 == 0) {

    return;

  }

  if ((DAT_00633104 == 0) || ((*(uint *)(param_1 + 0x20c) & 0x100) == 0)) goto code_r0x0045edd2;

  *(uint *)(param_1 + 0x20c) = *(uint *)(param_1 + 0x20c) & 0xfffffeff;

  uVar9 = player_can_use_ammo__FP6OBJECTi();

  switch(uVar9) {

  case 0:

    uVar10 = *(uint *)(param_1 + 0x20c) | 0x100;

    break;

  case 1:

    uVar10 = *(uint *)(param_1 + 0x20c) | 0x200;

    break;

  case 2:

    uVar10 = *(uint *)(param_1 + 0x20c) | 0x400;

    break;

  case 3:

    puVar2[0x4e] = 0x3ea8f5c3;

    puVar2[0x4d] = 0x3ea8f5c3;

    goto LAB_0045edc4;

  case 4:

    puVar2[0x4e] = 0x3f28f5c3;

    puVar2[0x4d] = 0x3f28f5c3;

    goto LAB_0045edc4;

  case 5:

    puVar2[0x4e] = 0x3f800000;

    puVar2[0x4d] = 0x3f800000;

LAB_0045edc4:

    uVar10 = *(uint *)(param_1 + 0x20c) | 8;

    break;

  default:

    goto code_r0x0045edd2;

  }

  *(uint *)(param_1 + 0x20c) = uVar10;

code_r0x0045edd2:

  if (100.0 <= (float)puVar2[0x25]) {

    iVar8 = *(int *)(param_1 + 0x100);

    bVar7 = __ftol();

    if (3 < bVar7) {

      uVar10 = (uint)(byte)(((byte)(bVar7 - 4) >> 2) + 1);

      do {

        bVar7 = bVar7 - 4;

        uVar10 = uVar10 - 1;

      } while (uVar10 != 0);

    }

    fStack_1e8 = (float)(uint)bVar7;

    fStack_1f0 = fStack_1e8;

    fStack_1e8 = (float)(int)fStack_1e8;

    if (*(float *)(iVar8 + 0x158) != fStack_1e8) {

      sound_play_player(0x6e4,param_1);

      iVar11 = reaper_0052e4a0(param_1);

      if (iVar11 != 0) {

        fStack_1f0 = 2.47189e-42;

        reaper_00530bd0(param_1,0,1,0,0x11,&fStack_1f0);

      }

      *(float *)(iVar8 + 0x158) = fStack_1e8;

      iVar8 = reaper_0052e4a0(param_1);

      if (iVar8 != 0) {

        uStack_1f4._0_2_ = (ushort)bVar7;

        reaper_00530bd0(param_1,0,0,2,0xb,&uStack_1f4);

      }

    }

    puVar2[0x25] = 0;

  }

  iVar8 = *(int *)(param_1 + 0x100);

  *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) | 0x10000000;

  if ((*(float *)(param_1 + 0x278) < *(float *)(param_1 + 0x1c0)) &&

     (*(float *)(iVar8 + 0x15c) != *(float *)(iVar8 + 0x158))) {

    fVar26 = (float10)FUN_00518b70(param_1,0);

    if (*(float *)(iVar8 + 0x158) <= *(float *)(iVar8 + 0x15c)) {

      fVar26 = (float10)*(float *)(iVar8 + 0x15c) - fVar26 * (float10)0.4;

      *(float *)(iVar8 + 0x15c) = (float)fVar26;

      if (fVar26 < (float10)*(float *)(iVar8 + 0x158)) {

        *(undefined4 *)(iVar8 + 0x15c) = *(undefined4 *)(iVar8 + 0x158);

      }

    }

    else {

      fVar26 = fVar26 * (float10)0.4 + (float10)*(float *)(iVar8 + 0x15c);

      *(float *)(iVar8 + 0x15c) = (float)fVar26;

      if ((float10)*(float *)(iVar8 + 0x158) < fVar26) {

        *(undefined4 *)(iVar8 + 0x15c) = *(undefined4 *)(iVar8 + 0x158);

      }

    }

    obj_lod_lerp_update(param_1);

  }

  fx_lightning_strike(param_1);

  marker_process__FP6OBJECT(param_1);

  iVar8 = fx_create(param_1);

  if (iVar8 == 0) {

    iVar8 = *(int *)(param_1 + 0x100);

    fVar26 = (float10)FUN_00518b70(param_1,0);

    fStack_17c = (float)fVar26;

    fVar21 = *(float *)(iVar8 + 0x350) - fStack_17c;

    *(float *)(iVar8 + 0x350) = fVar21;

    if (fVar21 < 0.0 != (fVar21 == 0.0)) {

      *(undefined4 *)(param_1 + 0x114) = 0;

      *(undefined4 *)(param_1 + 0x130) = 0;

      *(undefined4 *)(param_1 + 300) = 0;

      *(undefined4 *)(param_1 + 0x128) = 0;

    }

    fVar26 = (float10)FUN_00518b70(param_1,0);

    *(uint *)(param_1 + 0x1c8) = *(uint *)(param_1 + 0x1c8) | 0x400;

    *(float *)(param_1 + 0xa0) =

         (float)(((float10)*(float *)(param_1 + 0x128) + (float10)*(float *)(param_1 + 0x134)) *

                 fVar26 * (float10)0.5 + (float10)*(float *)(param_1 + 0xa0));

    *(float *)(param_1 + 0xa4) =

         (float)(((float10)*(float *)(param_1 + 0x138) + (float10)*(float *)(param_1 + 300)) *

                 fVar26 * (float10)0.5 + (float10)*(float *)(param_1 + 0xa4));

    fVar21 = *(float *)(param_1 + 0x13c);

    *(undefined4 *)(param_1 + 0x134) = *(undefined4 *)(param_1 + 0x128);

    *(undefined4 *)(param_1 + 0x138) = *(undefined4 *)(param_1 + 300);

    *(undefined4 *)(param_1 + 0x13c) = *(undefined4 *)(param_1 + 0x130);

    *(float *)(param_1 + 0xa8) =

         (float)(((float10)fVar21 + (float10)*(float *)(param_1 + 0x130)) * fVar26 * (float10)0.5 +

                (float10)*(float *)(param_1 + 0xa8));

    *(float *)(param_1 + 200) =

         (float)(((float10)*(float *)(param_1 + 0x124) + (float10)*(float *)(param_1 + 0x114)) *

                 fVar26 * (float10)0.5 + (float10)*(float *)(param_1 + 200));

    PhysicsExApplyLocation(param_1);

    obj_velocity_normalize

              (param_1,0,0,*(undefined4 *)(DAT_00632ed8 + 0x6e4),

               *(undefined4 *)(DAT_00632ed8 + 0x6e0));

    *(float *)(param_1 + 0x10c) = (*(float *)(param_1 + 0x11c) + *(float *)(param_1 + 0x10c)) * 0.5;

    *(float *)(param_1 + 0x110) = (*(float *)(param_1 + 0x120) + *(float *)(param_1 + 0x110)) * 0.5;

    *(float *)(param_1 + 0x108) = (*(float *)(param_1 + 0x118) + *(float *)(param_1 + 0x108)) * 0.5;

    object_animate_process(param_1,fStack_17c);

    *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) | 0x40;

    laser_ghost__FP6OBJECT(param_1);

    return;

  }

  if ((char)*puVar2 < '\0') {

    *(undefined1 *)(param_1 + 0x20a) = 0x20;

    *puVar2 = *puVar2 & 0xffffff7f;

  }

  if ((*puVar2 & 0x300) != 0) {

    *(uint *)(param_1 + 0x20c) = *(uint *)(param_1 + 0x20c) & 0xfffffffd;

  }

  if ((*puVar2 & 0x100) != 0) {

    *(undefined1 *)(param_1 + 0x20b) = 0;

    *(undefined1 *)(param_1 + 0x20a) = 0;

    *puVar2 = *puVar2 & 0xfffffcff;

  }

  if ((*puVar2 & 0x200) != 0) {

    *(undefined1 *)(param_1 + 0x208) = 0;

    *puVar2 = *puVar2 & 0xfffffcff;

  }

  if ((*puVar2 & 0x400) != 0) {

    *(undefined1 *)(param_1 + 0x209) = 0;

    *puVar2 = *puVar2 & 0xfffffcff;

  }

  if (((*(int *)(param_1 + 0xe4) != 0xc) &&

      (*(float *)(param_1 + 0xa8) <= (float)puVar2[0x74] * -30.0)) && ((puVar2[0x39] & 0x40) != 0))

  {

    *(undefined4 *)(param_1 + 0xe4) = 0xe;

  }

  obj_alpha_fade_update(param_1);

  player_pitch_update(param_1);

  obj_vel_reset(param_1);

  obj_speed_sq_calc(param_1);

  PhysicsExApplyLocation(param_1);

  collide_objects_kabuto__FP6OBJECTP3P3D(param_1,0);

  PhysicsExCalcControledModelSpeeds

            (param_1,*(undefined4 *)(DAT_00632ed8 + 0x6e4),*(undefined4 *)(DAT_00632ed8 + 0x6e0));

  fVar26 = (float10)FUN_00518b70(param_1,0);

  object_animate_process(param_1,(float)fVar26);

  if ((*(char *)(param_1 + 0x20a) == '\0') && (*(char *)(param_1 + 0x20b) == '\0')) {

    uVar9 = 1;

  }

  else {

    uVar9 = 0;

  }

  obj_gravity_apply(param_1,uVar9);

  fStack_1e8 = *(float *)(DAT_00632ed8 + 0x5fc);

  fStack_1f0 = *(float *)(DAT_00632ed8 + 0x600);

  fStack_1a8 = *(float *)(*(int *)(param_1 + 0x100) + 0x160);

  fVar21 = -((*(float *)(param_1 + 0xa8) - *(float *)(param_1 + 0x1d4) * *(float *)(param_1 + 0xc4))

            / (*(float *)(param_1 + 0x1e8) * *(float *)(param_1 + 0xc4)));

  if (0.0 < fVar21) {

    if (1.0 < fVar21) {

      fVar21 = 1.0;

    }

    fStack_1a8 = (1.0 - fVar21 * 0.5) * fStack_1a8;

  }

  if ((*(uint *)(param_1 + 0xd8) & 0x8000000) != 0) {

    fStack_1a8 = fStack_1a8 * 0.8;

  }

  obj_bone_update(param_1,fStack_1a8,fStack_1a8,fStack_1e8,fStack_1f0,

                  *(uint *)(param_1 + 0xd8) & 0x10);

  sine_cos_lookup(*(undefined4 *)(param_1 + 200),&fStack_174,&fStack_170);

  uVar10 = *(uint *)(param_1 + 0xd8);

  fStack_170 = -fStack_170;

  *(uint *)(param_1 + 0xd8) = uVar10 | 0x40;

  uStack_16c = 0;

  if (*(float *)(param_1 + 0x1c0) <= *(float *)(param_1 + 0x278)) {

    if (param_1 == DAT_00632a88) {

      if (((uVar10 & 0x80000) != 0) || ((**(byte **)(param_1 + 0x104) & 0x68) != 0)) {

        _DAT_00632b60 = _DAT_00632b60 + DAT_006328e0;

      }

      if (DAT_00632f08 == 0) {

        if (5.0 < _DAT_00632b60) {

          voice_quota_check();

          return;

        }

      }

      else if ((2.0 < _DAT_00632b60) && ((*(byte *)(param_1 + 0x20c) & 4) != 0)) {

        iVar8 = *(int *)(param_1 + 0x100);

        bVar7 = __ftol();

        fStack_1e8 = (float)(uint)bVar7;

        if ((char)bVar7 < '\0') {

          bVar7 = 0;

          fStack_1e8 = 0.0;

        }

        fStack_1f0 = fStack_1e8;

        fStack_1e8 = (float)(int)fStack_1e8;

        if (*(float *)(iVar8 + 0x158) != fStack_1e8) {

          sound_play_player(0x6e4,param_1);

          iVar11 = reaper_0052e4a0(param_1);

          if (iVar11 != 0) {

            fStack_1f0 = 2.47189e-42;

            reaper_00530bd0(param_1,0,1,0,0x11,&fStack_1f0);

          }

          *(float *)(iVar8 + 0x158) = fStack_1e8;

          iVar11 = reaper_0052e4a0(param_1);

          if (iVar11 != 0) {

            uStack_1f4._0_2_ = (ushort)bVar7;

            reaper_00530bd0(param_1,0,0,2,0xb,&uStack_1f4);

          }

        }

        iVar11 = ObjIsKabuto(param_1);

        if (iVar11 == 0) {

          uVar9 = 1;

        }

        else {

          uVar9 = *(undefined4 *)(iVar8 + 0x348);

        }

        cam_mode_full(param_1,uVar9);

      }

    }

    iVar8 = ObjIsKabuto(param_1);

    if (iVar8 == 0) {

      return;

    }

  }

  fVar26 = (float10)FUN_00518b70(param_1,0);

  uStack_180 = 0xffffffff;

  puVar2[0x38] = (uint)(float)(fVar26 + (float10)(float)puVar2[0x38]);

  iStack_188 = *(int *)(param_1 + 0xe4);

  uStack_19c = *(uint *)(param_1 + 0x10);

  fStack_1b4 = (float)puVar2[0x24];

  uStack_1f4 = 0xffffffff;

  uStack_1ac = 0xffffffff;

  fStack_1f0 = (float)(*(uint *)(param_1 + 0x30) & 0x10);

  uStack_1c8 = *(uint *)(param_1 + 0x30) & 2;

  iVar8 = *(int *)(*(int *)(*(int *)(param_1 + 8) + 8 + uStack_19c * 4) + 0x28);

  fStack_184 = 0.0;

  fStack_1a8 = 0.25;

  uStack_1b0 = 0;

  uStack_1d8 = 0x20;

  uStack_178 = 0;

  iStack_148 = iVar8;

  iStack_1a4 = AddHud__4cHudP8cHudIcon_4(iVar8,*(undefined4 *)(param_1 + 0x18));

  iStack_1c4 = AddHud__4cHudP8cHudIcon_4(iVar8,*(undefined4 *)(param_1 + 0x14));

  uVar17 = (ushort)(*(float *)(param_1 + 0x114) != 0.0);

  uVar1 = *(ushort *)((int)puVar2 + 0x8e);

  *(ushort *)((int)puVar2 + 0x8e) = (uVar1 & 7) << 1 | uVar17;

  *(ushort *)(puVar2 + 0x23) = (short)puVar2[0x23] + (uVar17 - ((uVar1 & 0x7fff) >> 3));

  fVar26 = (float10)FUN_00518b70(param_1,0);

  fVar21 = (float)puVar2[1];

  puVar2[1] = (uint)(float)((float10)fVar21 - fVar26);

  if ((float10)fVar21 - fVar26 < (float10)0.0) {

    puVar2[1] = 0;

    *puVar2 = *puVar2 & 0xffffffbf;

  }

  fStack_1a0 = (float)((uint)(*(float *)(param_1 + 0x10c) != 0.0) |

                       ((uint)(2 < (ushort)puVar2[0x23]) << 1 |

                       (uint)(*(float *)(param_1 + 0x110) != 0.0)) << 1 |

                      (uint)((float)puVar2[1] != 0.0) << 3);

  if (((*(uint *)(param_1 + 0x20c) & 0x800) != 0) &&

     (*(float *)(DAT_00632ed8 + 0x9e8) < (float)puVar2[0x4a] !=

      (*(float *)(DAT_00632ed8 + 0x9e8) == (float)puVar2[0x4a]))) {

    puVar2[0x4b] = 1;

  }

  if (puVar2[0x4b] == 0) {

LAB_0045f799:

    puVar2[0x4b] = 0;

    fStack_1e8 = (*(float *)(DAT_00632ed8 + 0x10b0) * *(float *)(param_1 + 0x278) +

                 (*(float *)(param_1 + 0x1c0) - *(float *)(param_1 + 0x278)) *

                 *(float *)(DAT_00632ed8 + 0x10b4)) / *(float *)(param_1 + 0x1c0);

    if (fStack_1e8 == 0.0) {

      puVar2[0x4a] = 0x3f800000;

    }

    else {

      fVar26 = (float10)FUN_00518b70(param_1,0);

      puVar2[0x4a] = (uint)(float)(fVar26 / (float10)fStack_1e8 + (float10)(float)puVar2[0x4a]);

    }

    if (1.0 < (float)puVar2[0x4a]) {

      puVar2[0x4a] = 0x3f800000;

    }

  }

  else {

    if ((float)puVar2[0x4a] <= 0.0) {

      if (puVar2[0x4b] != 0) {

        sound_play_player(0x40a,param_1);

        iVar8 = reaper_0052e4a0(param_1);

        if (iVar8 != 0) {

          fStack_1e8 = 1.44894e-42;

          reaper_00530bd0(param_1,0,1,0,0x11,&fStack_1e8);

        }

      }

      goto LAB_0045f799;

    }

    fStack_1e8 = (*(float *)(DAT_00632ed8 + 0x10b8) * *(float *)(param_1 + 0x278) +

                 (*(float *)(param_1 + 0x1c0) - *(float *)(param_1 + 0x278)) *

                 *(float *)(DAT_00632ed8 + 0x10bc)) / *(float *)(param_1 + 0x1c0);

    if (fStack_1e8 == 0.0) {

      puVar2[0x4a] = 0;

    }

    else {

      fVar26 = (float10)FUN_00518b70(param_1,0);

      puVar2[0x4a] = (uint)(float)((float10)(float)puVar2[0x4a] - fVar26 / (float10)fStack_1e8);

    }

    if ((float)puVar2[0x4a] < 0.0) {

      puVar2[0x4a] = 0;

    }

  }

  if (DAT_00633104 == 0) {

    fVar26 = (float10)FUN_00518b70(param_1,0);

    fVar21 = (float)puVar2[0x50];

    puVar2[0x50] = (uint)(float)((float10)fVar21 - fVar26);

    if ((float10)fVar21 - fVar26 < (float10)0.0) {

      puVar2[0x50] = 0;

    }

    if (((float)puVar2[0x50] == 0.0) && (3.0 <= (float)puVar2[0x57])) {

      fStack_1e8 = (*(float *)(DAT_00632ed8 + 0x11a4) * *(float *)(param_1 + 0x278) +

                   (*(float *)(param_1 + 0x1c0) - *(float *)(param_1 + 0x278)) *

                   *(float *)(DAT_00632ed8 + 0x11a0)) / *(float *)(param_1 + 0x1c0);

      if (fStack_1e8 == 0.0) {

        puVar2[0x4d] = 0x3f800000;

      }

      else {

        fVar26 = (float10)FUN_00518b70(param_1,0);

        puVar2[0x4d] = (uint)(float)(fVar26 / (float10)fStack_1e8 + (float10)(float)puVar2[0x4d]);

      }

      if (1.0 < (float)puVar2[0x4d]) {

        puVar2[0x4d] = 0x3f800000;

      }

    }

    if ((((*(byte *)(param_1 + 0x20c) & 0x10) == 0) || ((float)puVar2[0x50] != 0.0)) ||

       ((float)puVar2[0x57] < 3.0)) {

      puVar2[0x4f] = 0;

      puVar2[0x4e] = 0;

    }

    else {

      fVar26 = (float10)FUN_00518b70(param_1,0);

      fVar21 = (float)puVar2[0x4f];

      puVar2[0x4f] = (uint)(float)(fVar26 + (float10)fVar21);

      if ((float10)*(float *)(DAT_00632ed8 + 0x11a8) < fVar26 + (float10)fVar21) {

        puVar2[0x4f] = *(uint *)(DAT_00632ed8 + 0x11a8);

      }

      if (*(float *)(DAT_00632ed8 + 0x9e0) < (float)puVar2[0x4f]) {

        if ((float)puVar2[0x4f] <= *(float *)(DAT_00632ed8 + 0x9e4)) {

          fVar21 = ((float)puVar2[0x4f] - *(float *)(DAT_00632ed8 + 0x9e0)) /

                   ((*(float *)(DAT_00632ed8 + 0x9e4) - *(float *)(DAT_00632ed8 + 0x9e0)) * 3.0) +

                   0.33333334;

          goto LAB_0045fa0b;

        }

        if ((float)puVar2[0x4f] <= *(float *)(DAT_00632ed8 + 0x11a8)) {

          fVar21 = ((float)puVar2[0x4f] - *(float *)(DAT_00632ed8 + 0x9e4)) /

                   ((*(float *)(DAT_00632ed8 + 0x11a8) - *(float *)(DAT_00632ed8 + 0x9e4)) * 3.0) +

                   0.6666667;

          goto LAB_0045fa0b;

        }

      }

      else {

        fVar21 = (float)puVar2[0x4f] / (*(float *)(DAT_00632ed8 + 0x9e0) * 3.0);

LAB_0045fa0b:

        puVar2[0x4e] = (uint)fVar21;

      }

      if (0.99 <= (float)puVar2[0x4e]) {

        puVar2[0x4e] = 0x3f800000;

      }

    }

  }

  fStack_1ec = (float)puVar2[0x4e];

  if ((float)puVar2[0x4d] < fStack_1ec) {

    fStack_1ec = (float)puVar2[0x4d];

    puVar2[0x4e] = (uint)fStack_1ec;

  }

  if (puVar2[0x4b] == 0) {

    if (*(float *)(DAT_00632ed8 + 0x9f0) == 0.0) {

      puVar2[0x4c] = 0;

    }

    else {

      fVar26 = (float10)FUN_00518b70(param_1,0);

      puVar2[0x4c] = (uint)(float)((float10)(float)puVar2[0x4c] -

                                  fVar26 / (float10)*(float *)(DAT_00632ed8 + 0x9f0));

    }

    if ((float)puVar2[0x4c] < 0.0) {

      puVar2[0x4c] = 0;

    }

  }

  else {

    if (*(float *)(DAT_00632ed8 + 0x9ec) == 0.0) {

      puVar2[0x4c] = 0x3f800000;

    }

    else {

      fVar26 = (float10)FUN_00518b70(param_1,0);

      puVar2[0x4c] = (uint)(float)(fVar26 / (float10)*(float *)(DAT_00632ed8 + 0x9ec) +

                                  (float10)(float)puVar2[0x4c]);

    }

    if (1.0 < (float)puVar2[0x4c]) {

      puVar2[0x4c] = 0x3f800000;

    }

  }

  puVar2[0x58] = (uint)(((float)puVar2[0x5c] - (float)puVar2[0x59]) * (float)puVar2[0x4c] +

                       (float)puVar2[0x59]);

  if (param_1 == DAT_00632a88) {

    if ((puVar2[3] == 0) || ((*(byte *)(puVar2[3] + 0x1c8) & 1) == 0)) {

      puVar2[0xd0] = 0x41200000;

    }

    else {

      fVar26 = (float10)FUN_00518b70(param_1,0);

      fVar21 = (float)puVar2[0xd0];

      puVar2[0xd0] = (uint)(float)((float10)fVar21 - fVar26);

      if ((float10)fVar21 - fVar26 < (float10)0.0) {

        puVar2[0xd0] = 0;

      }

      if ((float)puVar2[0xd0] < 0.0 != ((float)puVar2[0xd0] == 0.0)) {

        fStack_1dc = (float)puVar2[0xb];

        uVar10 = puVar2[3];

        iVar8 = reaper_0052e4a0(param_1);

        if (iVar8 != 0) {

          fStack_1e4 = *(float *)(uVar10 + 0x188);

          fStack_1e8 = fStack_1dc;

          reaper_00530bd0(param_1,1,1,0,8,&fStack_1e8);

        }

        if (fStack_1dc != 0.0) {

          *(float *)(uVar10 + 0xc4) = *(float *)(uVar10 + 0xc4) / fStack_1dc;

        }

        *(undefined4 *)(uVar10 + 0x210) = 0;

        if (*(int *)(uVar10 + 0x1e0) == 0x59) {

          if (*(int *)(uVar10 + 0x218) < 2) {

            FUN_00425850(uVar10);

          }

        }

        else if (*(int *)(uVar10 + 0x1e0) == 0x12) {

          smartie_release_to_bldg();

        }

        else {

          iVar8 = ObjIsReaper(uVar10);

          if (iVar8 != 0) {

            *(undefined4 *)(uVar10 + 0xc4) = *(undefined4 *)(*(int *)(uVar10 + 0x100) + 0xfac);

          }

        }

        *(uint *)(uVar10 + 0xd8) = *(uint *)(uVar10 + 0xd8) & 0xfff7ffff | 0x10000000;

        uVar10 = puVar2[3];

        fStack_1d4 = *(float *)(uVar10 + 0xa0) - *(float *)(param_1 + 0xa0);

        fStack_1d0 = *(float *)(uVar10 + 0xa4) - *(float *)(param_1 + 0xa4);

        fStack_1cc = *(float *)(uVar10 + 0xa8) - *(float *)(param_1 + 0xa8);

        normalize__FPfN20(&fStack_1d4,&fStack_1d0,&fStack_1cc);

        fStack_1d4 = fStack_1d4 * 50.0;

        fStack_1d0 = fStack_1d0 * 50.0;

        fStack_1cc = fStack_1cc * 50.0;

        reaper_spell_user(param_1,puVar2[3],&fStack_1d4);

        puVar2[3] = 0;

      }

    }

    if (puVar2[3] == 0) {

      iVar8 = mecc_zoom_out__FRC10CntrlInputif_2();

      if (iVar8 == 0) {

        iVar8 = camera_is_sniper();

        if (iVar8 == 0) {

          fStack_1e8 = (float)puVar2[0x73];

          fStack_1dc = (float)puVar2[0x72];

          goto LAB_0045fe69;

        }

        fStack_1e8 = (float)puVar2[0x6f];

        fStack_1dc = (float)puVar2[0x6e];

      }

      else {

        fStack_1e8 = (float)puVar2[0x71];

        fStack_1dc = (float)puVar2[0x70];

      }

      pfVar13 = (float *)XFGetCameraOrigin();

      fStack_1d4 = *pfVar13;

      fStack_1d0 = pfVar13[1];

      fStack_1cc = pfVar13[2];

LAB_0045fdcf:

      pfVar13 = (float *)XFGetCameraAxis(2);

      fStack_1c0 = *pfVar13;

      fStack_1bc = pfVar13[1];

      fStack_1b8 = pfVar13[2];

      fStack_1d4 = fStack_1c0 * fStack_1dc + fStack_1d4;

      fVar23 = 10000.0;

      fStack_1d0 = fStack_1bc * fStack_1dc + fStack_1d0;

      fStack_1cc = fStack_1b8 * fStack_1dc + fStack_1cc;

      fVar21 = fStack_1e8 - fStack_1dc;

    }

    else {

      iVar8 = mecc_zoom_out__FRC10CntrlInputif_2();

      if ((iVar8 != 0) || (iVar8 = camera_is_sniper(), iVar8 != 0)) {

        fStack_1e8 = (float)puVar2[0x71];

        fStack_1dc = (float)puVar2[0x70];

        pfVar13 = (float *)XFGetCameraOrigin();

        fStack_1d4 = *pfVar13;

        fStack_1d0 = pfVar13[1];

        fStack_1cc = pfVar13[2];

        goto LAB_0045fdcf;

      }

      fStack_1e8 = (float)puVar2[0x73];

      fStack_1dc = (float)puVar2[0x72];

LAB_0045fe69:

      fStack_1c0 = -*(float *)(param_1 + 0x29c);

      fStack_1bc = -*(float *)(param_1 + 0x2ac);

      fStack_1b8 = -*(float *)(param_1 + 700);

      fStack_1d4 = (*(float *)(param_1 + 0x288) + *(float *)(param_1 + 0x27c)) * 0.5;

      fStack_1d0 = (*(float *)(param_1 + 0x28c) + *(float *)(param_1 + 0x280)) * 0.5;

      fStack_1cc = (*(float *)(param_1 + 0x290) + *(float *)(param_1 + 0x284)) * 0.5;

      fVar21 = fStack_1dc;

      fVar23 = fStack_1e8;

    }

    pfVar13 = (float *)(puVar2 + 0x16);

    uVar10 = ai_spread_select(param_1,&fStack_1d4,&fStack_1c0,fVar21,fVar23,pfVar13);

    puVar2[0x15] = uVar10;

    puVar2[0x14] = uVar10;

    if (((uVar10 != 0) && (0.0 < *pfVar13)) &&

       (fVar21 = (*(float *)(uVar10 + 0x288) - *(float *)(uVar10 + 0x27c)) * 0.5,

       fVar3 = (*(float *)(uVar10 + 0x28c) - *(float *)(uVar10 + 0x280)) * 0.5,

       fVar23 = (*(float *)(uVar10 + 0x290) - *(float *)(uVar10 + 0x284)) * 0.5,

       fVar23 * fVar23 + fVar3 * fVar3 + fVar21 * fVar21 < *pfVar13)) {

      puVar2[0x14] = 0;

    }

    fVar26 = (float10)FUN_00518b70(param_1,0);

    fStack_1dc = (float)fVar26;

    fVar21 = (float)puVar2[0x12];

    puVar2[0x12] = (uint)(fVar21 - fStack_1dc);

    if (fVar21 - fStack_1dc < 0.0) {

      puVar2[0x12] = 0;

      puVar2[0x13] = 0;

    }

    if (puVar2[0x14] != 0) {

      _DAT_00632ba0 = 1;

      if (puVar2[0x13] != puVar2[0x14]) {

        *(undefined4 *)(puVar2[0xc5] + 0x184) = 0x3f800000;

      }

      puVar2[0x13] = puVar2[0x14];

      puVar2[0x12] = 0x3fc00000;

    }

    if (puVar2[3] == 0) {

      puVar2[0x13] = 0;

    }

    if (((puVar2[0x13] != 0) && (iVar8 = *(int *)(puVar2[0x13] + 0x210), iVar8 != 0)) &&

       (iVar8 == param_1)) {

      puVar2[0x13] = 0;

    }

    uVar10 = puVar2[0x13];

    if (uVar10 != 0) {

      fStack_1e8 = 1.0 / *(float *)(param_1 + 0xc4);

      fStack_190 = *(float *)(param_1 + 0x1ec) * *(float *)(param_1 + 0xc4) +

                   *(float *)(param_1 + 0xa8);

      fStack_1bc = (*(float *)(uVar10 + 0x28c) + *(float *)(uVar10 + 0x280)) * 0.5;

      fStack_1b8 = (*(float *)(uVar10 + 0x290) + *(float *)(uVar10 + 0x284)) * 0.5;

      fStack_1d4 = (*(float *)(uVar10 + 0x288) + *(float *)(uVar10 + 0x27c)) * 0.5 -

                   *(float *)(param_1 + 0xa0);

      fStack_1d0 = fStack_1bc - *(float *)(param_1 + 0xa4);

      fStack_1cc = fStack_1b8 - fStack_190;

      normalize__FPfN20(&fStack_1d4,&fStack_1d0,&fStack_1cc);

      if ((fStack_1d0 * *(float *)(param_1 + 0x2ac) +

          (*(float *)(param_1 + 700) + *(float *)(param_1 + 0x29c)) * fStack_1d4) * fStack_1e8 *

          -1.0 < 0.707) {

        puVar2[0x13] = 0;

      }

    }

    if (puVar2[0x13] == 0) {

      puVar2[0x13] = 0;

      *(float *)(puVar2[0xc5] + 0x184) = fStack_1dc * 3.0 + *(float *)(puVar2[0xc5] + 0x184);

      if (1.0 < *(float *)(puVar2[0xc5] + 0x184)) {

        *(undefined4 *)(puVar2[0xc5] + 0x184) = 0x3f800000;

        uVar10 = puVar2[0xc5];

        uVar18 = *(uint *)(uVar10 + 0xd8) | 0x40000000;

        goto LAB_00460189;

      }

    }

    else {

      SphereFitToObject(puVar2[0xc5] + 0x294,puVar2[0x13],0x40000000);

      ObjectTransformIntegrity(puVar2[0xc5]);

      *(float *)(puVar2[0xc5] + 0x184) = *(float *)(puVar2[0xc5] + 0x184) - fStack_1dc * 3.0;

      if (*(float *)(puVar2[0xc5] + 0x184) < 0.0) {

        *(undefined4 *)(puVar2[0xc5] + 0x184) = 0;

      }

      uVar10 = puVar2[0xc5];

      uVar18 = *(uint *)(uVar10 + 0xd8) & 0xbfffffff;

LAB_00460189:

      *(uint *)(uVar10 + 0xd8) = uVar18;

    }

    reaper_state_machine(param_1,puVar2[0x14]);

    laser_ghost__FP6OBJECT(param_1);

    if ((char)puVar2[0x8a] != '\0') goto LAB_0046477f;

  }

  uVar10 = *puVar2;

  uVar18 = (uVar10 & 2) << 1 |

           (uVar10 & 8) << 1 | (uVar10 & 0x1000) << 1 | (uVar10 & 0x4000) << 1 | uVar10 & 0xffff0fe1

  ;

  uVar19 = *(uint *)(param_1 + 0x20c) & 4;

  uVar22 = *(uint *)(param_1 + 0x20c) & 8;

  *puVar2 = uVar18;

  if ((((uVar10 & 0x800) == 0) && ((puVar2[0x14] == 0 || (*(int *)(puVar2[0x14] + 4) != 0x2e9)))) ||

     ((*(byte *)(param_1 + 0x20c) & 2) == 0)) {

    *puVar2 = -(uint)(uVar22 != 0) & 2 | -(uint)(uVar19 != 0) & 8 | uVar18;

  }

  else {

    *puVar2 = -(uint)(uVar19 != 0) & 0x4000 | -(uint)(uVar22 != 0) & 0x1000 | uVar18;

  }

  iVar8 = 0;

  puVar12 = puVar2 + 4;

  do {

    if (*puVar12 != 0) {

      if ((iVar8 < 2) && (-1 < iVar8)) {

        uVar10 = 0;

        iVar8 = 1;

        puVar12 = puVar2 + 5;

        do {

          uVar18 = *puVar12;

          puVar12 = puVar12 + -1;

          uVar10 = uVar10 | (uint)(uVar18 != 0) << ((byte)iVar8 & 1);

          iVar8 = iVar8 + -1;

        } while (-1 < iVar8);

        fVar26 = (float10)FUN_00518b70(param_1,0);

        fVar26 = (float10)*(float *)(param_1 + 0xec) - fVar26;

        *(float *)(param_1 + 0xec) = (float)fVar26;

        if (fVar26 < (float10)0.0) {

          uVar10 = uVar10 | (uVar10 * 2 & uVar10) << 1;

          fVar26 = (float10)rndfloatrange(0x3e99999a,0x3f800000);

          *(float *)(param_1 + 0xec) = (float)fVar26;

          uVar18 = ~uVar10;

          if ((uVar18 & 4) != 0) {

            *(float *)(param_1 + 0xec) = (float)(fVar26 + fVar26);

          }

          uVar19 = crt_rand_scaled(2);

          iVar8 = (uVar19 & uVar10 >> 2 ^ uVar18 & 1) * 0x44 + *(int *)(param_1 + 0x2dc);

          fStack_1c0 = *(float *)(iVar8 + 0x10);

          fStack_1bc = *(float *)(iVar8 + 0x20);

          fStack_1b8 = *(float *)(iVar8 + 0x30);

          (*(code *)PTR_S_GEO_Vec3Transform_00580c20)(&fStack_198,&fStack_1c0,1,param_1 + 0x294);

          blood_from_point(&fStack_198,5,0xf,*(float *)(param_1 + 200) - 30.0,

                           *(float *)(param_1 + 200) + 30.0,0x41200000,0x42340000,0,0x41700000);

          blood_from_point(&fStack_198,5,0xf,(*(float *)(param_1 + 200) + 180.0) - 30.0,

                           *(float *)(param_1 + 200) + 210.0,0x41200000,0x42340000,0,0x41700000);

        }

        puVar2[1] = 0x41200000;

      }

      break;

    }

    iVar8 = iVar8 + 1;

    puVar12 = puVar12 + 1;

  } while (iVar8 < 2);

  if ((*(byte *)(param_1 + 0x20c) & 0x40) != 0) {

    uVar10 = puVar2[0x14];

    puVar6 = DAT_00632d68;

    if ((uVar10 == 0) || (*(int *)(uVar10 + 4) != 0x2e9)) {

      for (; puVar6 != (undefined4 *)0x0; puVar6 = (undefined4 *)*puVar6) {

        iVar8 = puVar6[3];

        if (*(int *)(iVar8 + 0x1e0) == 0x4b) {

          sound_play_obj(0x4ac,iVar8);

          iVar11 = reaper_0052e4a0(param_1);

          if (iVar11 != 0) {

            fStack_1d4 = *(float *)(iVar8 + 0x188);

            fStack_1d0 = 1.67595e-42;

            reaper_00530bd0(param_1,0,2,0,0x13,&fStack_1d4);

          }

          sound_play_player(0x41a,param_1);

          iVar11 = reaper_0052e4a0(param_1);

          if (iVar11 != 0) {

            fStack_1e8 = 1.47136e-42;

            reaper_00530bd0(param_1,0,1,0,0x11,&fStack_1e8);

          }

          fStack_1dc = *(float *)(param_1 + 200);

          if (fStack_1dc < 0.0) {

            fStack_1dc = fStack_1dc + 360.0;

          }

          if (360.0 < fStack_1dc) {

            fStack_1dc = fStack_1dc - 360.0;

          }

          sine_cos_lookup(fStack_1dc,&fStack_1c0,&fStack_1bc);

          fStack_190 = *(float *)(param_1 + 0xa8);

          fStack_1bc = -fStack_1bc;

          fStack_1b8 = 0.0;

          fStack_198 = fStack_1c0 * 70.0 + *(float *)(param_1 + 0xa0);

          fStack_194 = fStack_1bc * 70.0 + *(float *)(param_1 + 0xa4);

          sound_play_player(0x460,param_1);

          iVar11 = reaper_0052e4a0(param_1);

          if (iVar11 != 0) {

            fStack_1e8 = 1.56945e-42;

            reaper_00530bd0(param_1,0,1,0,0x11,&fStack_1e8);

          }

          kbos_offspring_process(iVar8,&fStack_198,0);

        }

      }

    }

    else {

      if (uVar10 != 0) {

        sound_play_obj(0x4ac,uVar10);

        iVar8 = reaper_0052e4a0(param_1);

        if (iVar8 != 0) {

          fStack_1e8 = *(float *)(uVar10 + 0x188);

          fStack_1e4 = 1.67595e-42;

          reaper_00530bd0(param_1,0,2,0,0x13,&fStack_1e8);

        }

      }

      sound_play_player(0x460,param_1);

      iVar8 = reaper_0052e4a0(param_1);

      if (iVar8 != 0) {

        fStack_1e8 = 1.56945e-42;

        reaper_00530bd0(param_1,0,1,0,0x11,&fStack_1e8);

      }

      fStack_1b8 = *(float *)(param_1 + 0xa8);

      fStack_1c0 = fStack_174 * 70.0 + *(float *)(param_1 + 0xa0);

      fStack_1bc = fStack_170 * 70.0 + *(float *)(param_1 + 0xa4);

      sound_play_player(0x460,param_1);

      iVar8 = reaper_0052e4a0(param_1);

      if (iVar8 != 0) {

        fStack_1e8 = 1.56945e-42;

        reaper_00530bd0(param_1,0,1,0,0x11,&fStack_1e8);

      }

      kbos_offspring_process(puVar2[0x14],&fStack_1c0,0);

    }

  }

  uVar10 = puVar2[0x26];

  if (-1 < (int)uVar10) {

    uStack_1b0 = puVar2[0x27];

    puVar2[0x26] = 0xffffffff;

    puVar2[0x27] = 0xffffffff;

    uStack_1f4 = uVar10;

    goto LAB_004630ec;

  }

  if (iStack_188 != 0xc) {

    if (iStack_188 != 0xe) goto LAB_004609f9;

    if ((puVar2[0x39] & 0x40) == 0) {

      if (uStack_19c != 0x9c) {

        sound_play_player(0x41b,param_1);

        iVar8 = reaper_0052e4a0(param_1);

        if (iVar8 != 0) {

          fStack_1e8 = 1.47276e-42;

          reaper_00530bd0(param_1,0,1,0,0x11,&fStack_1e8);

        }

      }

      uStack_1f4 = 0x9c;

      goto LAB_0046081e;

    }

    if (uStack_19c != 0xc6) {

      uVar10 = **(uint **)(param_1 + 0x100);

      if ((uVar10 & 0x800000) == 0) {

        **(uint **)(param_1 + 0x100) = uVar10 | 0x800000;

        sound_play_player(0x486,param_1);

        iVar8 = reaper_0052e4a0(param_1);

        if (iVar8 != 0) {

          fStack_1f0 = 1.6227e-42;

          reaper_00530bd0(param_1,0,1,0,0x11,&fStack_1f0);

        }

      }

    }

    uStack_1f4 = 0xc6;

    uStack_1d8 = 0x21;

    fVar26 = (float10)FUN_00518b70(param_1,0);

    fVar26 = (float10)(float)puVar2[0xca] - fVar26;

    puVar2[0xca] = (uint)(float)fVar26;

    if (fVar26 < (float10)0.0 != (fVar26 == (float10)0.0)) {

      do {

        puVar2[0xca] = (uint)((float)puVar2[0xca] + 0.25);

        obj_damage_apply(0x18,*(float *)(param_1 + 0x1c0) * 0.05,param_1,0,0,0);

      } while ((float)puVar2[0xca] < 0.0 != ((float)puVar2[0xca] == 0.0));

    }

    goto LAB_004630f8;

  }

  if (*(float *)(param_1 + 0x1c0) <= *(float *)(param_1 + 0x278)) {

    *puVar2 = *puVar2 | 0x300;

    goto LAB_0046477f;

  }

LAB_004609f9:

  uVar10 = **(uint **)(param_1 + 0x100);

  if ((uVar10 & 0x800000) != 0) {

    **(uint **)(param_1 + 0x100) = uVar10 & 0xff7fffff;

    sound_stop_obj(0x486,param_1);

    iVar8 = reaper_0052e4a0(param_1);

    if (iVar8 != 0) {

      fStack_1e8 = 1.6227e-42;

      reaper_00530bd0(param_1,0,1,0,0x12,&fStack_1e8);

    }

  }

  if ((iStack_188 == 0xd) && (uStack_1c8 == 0)) {

    *puVar2 = *puVar2 | 0x300;

    goto LAB_0046477f;

  }

LAB_0046081e:

  if ((*(uint *)(param_1 + 0x20c) & 0x1000) != 0) {

    if ((((~*puVar2 & 0x20000) == 0) || ((float)puVar2[0xd1] < 0.0 == ((float)puVar2[0xd1] == 0.0)))

       || (((*(uint *)(param_1 + 0xd8) & 0x80000) == 0 && ((puVar2[0x39] & 8) == 0))))

    goto LAB_00460c08;

    *puVar2 = *puVar2 | 0x20000;

    pfVar13 = (float *)(param_1 + 0xa0);

    ground_height_at(pfVar13,&fStack_168);

    if (((~*puVar2 & 0x10000) == 0) ||

       (fVar26 = (float10)(*(code *)PTR_AddHud__4cHudP8cHudIcon_5_00580c38)(fStack_160),

       (float10)*(float *)(DAT_00632ed8 + 0x15d4) * (float10)0.017453292 <= fVar26))

    goto LAB_00460c08;

    if (*(float *)(DAT_00632ed8 + 0x6e0) * 0.0625 <= ABS(*(float *)(param_1 + 0x10c))) {

      fStack_1ec = (float)puVar2[0x42] / (float)puVar2[0x59];

      if (1.0 < fStack_1ec) {

        fStack_1ec = 1.0;

      }

      fStack_1ec = fStack_1ec * (float)puVar2[0x6a];

      if (fStack_1ec < (float)puVar2[0x69]) {

        fStack_1ec = (float)puVar2[0x69];

      }

      fVar21 = ((float)puVar2[0x42] - (float)puVar2[0x59]) /

               ((float)puVar2[0x5c] - (float)puVar2[0x59]);

      if (0.0 <= fVar21) {

        if (1.0 < fVar21) {

          fVar21 = 1.0;

        }

      }

      else {

        fVar21 = 0.0;

      }

      fStack_1ec = ((float)puVar2[0x6b] - (float)puVar2[0x6a]) * fVar21 + fStack_1ec;

      puVar2[0x18] = (uint)(fStack_1ec * fStack_174 + *pfVar13);

      puVar2[0x19] = (uint)(fStack_1ec * fStack_170 + *(float *)(param_1 + 0xa4));

      puVar2[0x1a] = *(uint *)(param_1 + 0xa8);

      fVar26 = (float10)ground_get_z(puVar2 + 0x18);

      puVar2[0x1a] = (uint)(float)fVar26;

      if ((float10)(float)puVar2[0x6d] < fVar26 - (float10)*(float *)(param_1 + 0xa8)) {

        puVar2[0x1a] = (uint)((float)puVar2[0x6d] + *(float *)(param_1 + 0xa8));

      }

      if (0.0 < fStack_1ec * fStack_1ec) {

        sound_play_player(0x442,param_1);

        iVar8 = reaper_0052e4a0(param_1);

        if (iVar8 != 0) {

          fStack_1f0 = 1.52742e-42;

          reaper_00530bd0(param_1,0,1,0,0x11,&fStack_1f0);

        }

        uStack_1f4 = 0xaa;

LAB_00460bec:

        puVar2[0xd1] = *(uint *)(DAT_00632ed8 + 0x15d0);

        goto LAB_004630f8;

      }

    }

    else {

      iVar8 = project_cursor_to_ground(puVar2 + 0x18,0x459c4000,&fStack_1a0);

      if (iVar8 != 0) {

        fVar26 = (float10)distancesq2d__FP3P3DT0(pfVar13,puVar2 + 0x18);

        fStack_1e8 = (float)fVar26;

        if ((float)puVar2[0x6d] < (float)puVar2[0x1a] - *(float *)(param_1 + 0xa8)) {

          puVar2[0x1a] = (uint)((float)puVar2[0x6d] + *(float *)(param_1 + 0xa8));

        }

        if (fVar26 < (float10)(float)puVar2[0x69] * (float10)(float)puVar2[0x69]) {

          sound_play_player(0x442,param_1);

          iVar8 = reaper_0052e4a0(param_1);

          if (iVar8 != 0) {

            fStack_1f0 = 1.52742e-42;

            reaper_00530bd0(param_1,0,1,0,0x11,&fStack_1f0);

          }

          if (fStack_1e8 < (float)puVar2[0x68] * (float)puVar2[0x68]) {

            sound_play_player(0x442,param_1);

            iVar8 = reaper_0052e4a0(param_1);

            if (iVar8 != 0) {

              fStack_1f0 = 1.52742e-42;

              reaper_00530bd0(param_1,0,1,0,0x11,&fStack_1f0);

            }

            uStack_1f4 = 0xa6;

            puVar2[0xd1] = *(uint *)(DAT_00632ed8 + 0x15d0);

            goto LAB_004630f8;

          }

          sound_play_player(0x442,param_1);

          iVar8 = reaper_0052e4a0(param_1);

          if (iVar8 != 0) {

            fStack_1f0 = 1.52742e-42;

            reaper_00530bd0(param_1,0,1,0,0x11,&fStack_1f0);

          }

          uStack_1f4 = 0xa7;

          goto LAB_00460bec;

        }

      }

    }

    goto LAB_004630ec;

  }

  *puVar2 = *puVar2 & 0xfffdffff;

LAB_00460c08:

  uVar10 = uStack_19c;

  if (uStack_19c == 0xa6) {

    iVar8 = 0x960;

LAB_00464b27:

    if ((iStack_1a4 < iVar8) && (iVar8 <= iStack_1c4)) {

LAB_00464b3b:

      fStack_190 = (float)puVar2[0x6d];

      fStack_1c0 = (float)puVar2[0x51];

      fStack_1bc = (float)puVar2[0x52];

      fStack_1b8 = (float)puVar2[0x53];

      fStack_198 = 1000.0;

      fStack_194 = 1000.0;

      FUN_0050a610(param_1 + 0xa0,puVar2 + 0x18);

      fVar26 = (float10)powf();

      fStack_1f0 = (float)(fVar26 * (float10)0.1);

      vec_bounds_calc(param_1 + 0x128,param_1 + 0xa0,puVar2 + 0x18,&fStack_1c0,&fStack_198,

                      fStack_1f0);

      fStack_17c = 1.4013e-45;

      puVar2[0x3a] = (uint)(fStack_1b8 * (float)puVar2[0x3b] * -0.03108095);

      *puVar2 = *puVar2 | 0x10000;

    }

    if (uStack_1c8 == 0) {

LAB_004630ec:

      if ((int)uStack_1f4 < 0) goto LAB_0046477f;

LAB_004630f8:

      if (uStack_19c == uStack_1f4) goto LAB_0046477f;

      if (uStack_180 < 4) goto LAB_00463114;

    }

    else {

      uStack_1d8 = 0x21;

      if (uStack_19c != 0xaa) {

        uStack_1f4 = 0xa8;

        goto LAB_004630f8;

      }

      uStack_1f4 = 0xab;

    }

LAB_004646d7:

    fStack_184 = 0.0;

  }

  else {

    if (uStack_19c == 0xa7) {

      iVar8 = 0x780;

      goto LAB_00464b27;

    }

    if (uStack_19c == 0xaa) goto LAB_00464b3b;

    if (((*(uint *)(param_1 + 0xd8) & 0x80000) != 0) || ((char)puVar2[0x39] < '\0')) {

      fVar26 = (float10)FUN_00518b70(param_1,0);

      fVar21 = (float)puVar2[0xd1];

      puVar2[0xd1] = (uint)(float)((float10)fVar21 - fVar26);

      if ((float10)fVar21 - fVar26 < (float10)0.0) {

        puVar2[0xd1] = 0;

      }

      puVar2[0x3a] = *(uint *)(DAT_00632ed8 + 0x6b4);

      *puVar2 = *puVar2 & 0xfffeffff;

    }

    fVar21 = fStack_1b4;

    if ((((uVar10 == 0xa8) || (uVar10 == 0xab)) &&

        (*(float *)(param_1 + 0x130) < 0.0 != (*(float *)(param_1 + 0x130) == 0.0))) &&

       (25.0 < *(float *)(param_1 + 0xa8) - *(float *)(param_1 + 0x140))) {

      uStack_1f4 = 0xa9;

      goto LAB_004630f8;

    }

    if ((uVar10 != 0xa9) || ((*puVar2 & 0x10000) == 0)) {

      if (-1 < (int)fStack_1b4) {

        iVar8 = (int)fStack_1b4 * 0x1c;

        if ((*(uint *)(&DAT_0055a4e8 + iVar8) & 0x400) == 0) {

LAB_00460e81:

          if ((*(uint *)(&DAT_0055a4e8 + iVar8) & 0x300) != 0) {

            *puVar2 = *puVar2 | 0x300;

            if (((int)(&DAT_0055a4e0)[(int)fVar21 * 7] < iStack_1a4) ||

               (iStack_1c4 < (int)(&DAT_0055a4e0)[(int)fVar21 * 7])) {

              if (uStack_1c8 == 0) goto LAB_004630ec;

            }

            else {

              iVar11 = (&DAT_0055a4e4)[(int)fVar21 * 7];

              if ((*(uint *)(&DAT_0055a4e8 + iVar8) & 0x100) == 0) {

                if (-1 < iVar11) {

                  fStack_198 = *(float *)(iVar11 * 0x44 + 0x10 + *(int *)(param_1 + 0x2dc));

                  iVar8 = iVar11 * 0x44 + *(int *)(param_1 + 0x2dc);

                  fStack_194 = *(float *)(iVar8 + 0x20);

                  fStack_190 = *(float *)(iVar8 + 0x30);

                  (*(code *)PTR_S_GEO_Vec3Transform_00580c20)

                            (&fStack_1d4,&fStack_198,1,param_1 + 0x294);

                }

                iVar8 = ObjIsKabuto(param_1);

                if (iVar8 == 0) {

                  fStack_1e8 = 1.0;

                }

                else {

                  fStack_1e8 = *(float *)(*(int *)(param_1 + 0x100) + 0x1d0);

                }

                fVar21 = fStack_1e8;

                iVar8 = 3;

                do {

                  fStack_1e8 = fStack_1d4;

                  fStack_1e4 = fStack_1d0;

                  fStack_1e0 = fStack_1cc;

                  fVar26 = (float10)rndfloatrange(0xc1200000,0x41200000);

                  fStack_1e8 = (float)(fVar26 + (float10)fStack_1e8);

                  fVar26 = (float10)rndfloatrange(0xc1200000,0x41200000);

                  fStack_1e4 = (float)(fVar26 + (float10)fStack_1e4);

                  fVar26 = (float10)rndfloatrange(0xc1200000,0x41200000);

                  fStack_1e0 = (float)(fVar26 + (float10)fStack_1e0);

                  make_dust_ball(&fStack_1e8,fVar21);

                  iVar8 = iVar8 + -1;

                } while (iVar8 != 0);

                puVar2[0x17] = 0;

                line_damage_with_slope

                          (4,param_1,0,&fStack_1d4,puVar2[0x80],puVar2[0x82],puVar2[0x81],

                           puVar2[0x83],*(undefined4 *)(param_1 + 0x18c));

                get_free_world_ripple__Fv_2

                          (&fStack_1d4,*(undefined4 *)(DAT_00632ed8 + 0x13ac),

                           *(undefined4 *)(DAT_00632ed8 + 0x13b0),

                           *(undefined4 *)(DAT_00632ed8 + 0x13b4),

                           *(undefined4 *)(DAT_00632ed8 + 0x13b8));

                puVar2[0x17] = 0;

              }

              else {

                if (-1 < iVar11) {

                  iVar8 = iVar11 * 0x44 + *(int *)(param_1 + 0x2dc);

                  fStack_198 = *(float *)(iVar8 + 0x10);

                  fStack_194 = *(float *)(iVar8 + 0x20);

                  fStack_190 = *(float *)(iVar8 + 0x30);

                  (*(code *)PTR_S_GEO_Vec3Transform_00580c20)

                            (&fStack_1d4,&fStack_198,1,param_1 + 0x294);

                }

                iVar8 = ObjIsKabuto(param_1);

                if (iVar8 == 0) {

                  fStack_1e8 = 1.0;

                }

                else {

                  fStack_1e8 = *(float *)(*(int *)(param_1 + 0x100) + 0x1d0);

                }

                fVar21 = fStack_1e8;

                iVar8 = 3;

                do {

                  fStack_1e8 = fStack_1d4;

                  fStack_1e4 = fStack_1d0;

                  fStack_1e0 = fStack_1cc;

                  fVar26 = (float10)rndfloatrange(0xc1200000,0x41200000);

                  fStack_1e8 = (float)(fVar26 + (float10)fStack_1e8);

                  fVar26 = (float10)rndfloatrange(0xc1200000,0x41200000);

                  fStack_1e4 = (float)(fVar26 + (float10)fStack_1e4);

                  fVar26 = (float10)rndfloatrange(0xc1200000,0x41200000);

                  fStack_1e0 = (float)(fVar26 + (float10)fStack_1e0);

                  make_dust_ball(&fStack_1e8,fVar21);

                  iVar8 = iVar8 + -1;

                } while (iVar8 != 0);

                puVar2[0x17] = 0;

                line_damage_with_slope

                          (4,param_1,0,&fStack_1d4,puVar2[0x7c],puVar2[0x7e],puVar2[0x7d],

                           puVar2[0x7f],*(undefined4 *)(param_1 + 0x18c));

                get_free_world_ripple__Fv_2

                          (&fStack_1d4,*(undefined4 *)(DAT_00632ed8 + 0x139c),

                           *(undefined4 *)(DAT_00632ed8 + 0x13a0),

                           *(undefined4 *)(DAT_00632ed8 + 0x13a4),

                           *(undefined4 *)(DAT_00632ed8 + 0x13a8));

                puVar2[0x17] = 0;

              }

            }

          }

          goto LAB_00461198;

        }

        iVar11 = (&DAT_0055a4dc)[(int)fStack_1b4 * 7];

        fStack_1e8 = (float)((&DAT_0055a4e0)[(int)fStack_1b4 * 7] - iVar11);

        if (((fStack_1e8 != 0.0) && (iStack_1a4 <= iVar11)) && (iVar11 <= iStack_1c4)) {

          PhysicsExZeroVelocity(param_1);

          PhysicsExZeroForce(param_1);

          if (puVar2[0x17] == 0) {

            puVar12 = puVar2 + 0x1b;

          }

          else {

            puVar12 = (uint *)(puVar2[0x17] + 0xa0);

          }

          trajectory_calculate

                    (param_1 + 0x128,param_1 + 0xa0,puVar12,puVar2 + 0x51,

                     (float)(int)fStack_1e8 * 0.00020833334);

          fStack_17c = 1.4013e-45;

        }

        if ((iStack_1a4 <= (int)(&DAT_0055a4e0)[(int)fVar21 * 7]) &&

           ((int)(&DAT_0055a4e0)[(int)fVar21 * 7] <= iStack_1c4)) {

          iVar11 = param_1 + 0xa0;

          AttackObject__FP6OBJECTT0P3P3DT2fi

                    (param_1,puVar2[0x17],iVar11,param_1 + 0xac,0x461c4000,8);

          line_damage_with_slope

                    (4,param_1,puVar2[0x17],iVar11,puVar2[0x84],puVar2[0x86],puVar2[0x85],

                     puVar2[0x87],*(undefined4 *)(param_1 + 0x18c));

          get_free_world_ripple__Fv_2

                    (iVar11,*(undefined4 *)(DAT_00632ed8 + 0x13c0),

                     *(undefined4 *)(DAT_00632ed8 + 0x13bc),*(undefined4 *)(DAT_00632ed8 + 0x13c4),

                     *(undefined4 *)(DAT_00632ed8 + 0x13c8));

          make_explosion_large(iVar11);

          puVar2[0x17] = 0;

          goto LAB_00460e81;

        }

        if (uStack_1c8 != 0) goto LAB_00460e81;

        goto LAB_004630e3;

      }

LAB_00461198:

      uVar10 = puVar2[0x17];

      if ((uVar10 != 0) && (*(int *)(uVar10 + 4) != 0x2e9)) {

        *puVar2 = *puVar2 & 0xfffff7ff;

      }

      uVar18 = *puVar2;

      if ((uVar18 & 0x5000) == 0) {

        if ((uVar18 & 0x800) != 0) {

          uVar18 = uVar18 >> 0xf & 1;

          if (uVar10 != 0) {

            if (uVar18 == 0) {

              sound_play_obj(0x41a,uVar10);

              iVar8 = reaper_0052e4a0(param_1);

              if (iVar8 != 0) {

                fStack_1d4 = *(float *)(uVar10 + 0x188);

                fStack_1d0 = 1.47136e-42;

                goto LAB_00461417;

              }

            }

            else {

              sound_play_obj(0x3fb,uVar10);

              iVar8 = reaper_0052e4a0(param_1);

              if (iVar8 != 0) {

                fStack_1d4 = *(float *)(uVar10 + 0x188);

                fStack_1d0 = 1.42792e-42;

LAB_00461417:

                reaper_00530bd0(param_1,0,2,0,0x13,&fStack_1d4);

              }

            }

            uVar19 = puVar2[0x14];

            if ((uVar19 == 0) ||

               ((((((iVar8 = *(int *)(uVar19 + 4), iVar8 != 3 || (*(int *)(uVar19 + 0x210) != 0)) &&

                   (iVar8 != 0x425)) &&

                  (((iVar8 != 0x426 && (iVar8 != 0x4a1)) &&

                   ((iVar8 != 0x4a2 && ((iVar8 != 0x4a4 && (iVar8 != 0x4a3)))))))) &&

                 ((iVar8 != 0x3c && (((iVar8 != 2 && (iVar8 != 1)) && (iVar8 != 0xe6)))))) &&

                (((iVar8 != 0x49 && (iVar8 != 0xe5)) &&

                 (((iVar8 != 0x438 && ((iVar8 != 8 && (iVar8 != 0xb)))) && (iVar8 != 0xd7)))))))) {

              project_cursor_to_ground(&fStack_198,0x459c4000,&fStack_1e8);

              kbos_offspring_process(uVar10,&fStack_198,0);

            }

            else {

              FUN_0046b7f0(uVar10,uVar19,uVar18);

            }

          }

          puVar2[0x17] = 0;

          uVar10 = *puVar2 & 0xfffff7ff;

LAB_004614e8:

          *puVar2 = uVar10;

        }

      }

      else {

        uVar19 = puVar2[0x14];

        if ((uVar19 == 0) || (*(int *)(uVar19 + 4) != 0x2e9)) {

          if ((uVar18 & 0xa000) == 0) {

            uVar10 = puVar2[200];

            uVar18 = uVar18 >> 0xf & 1;

            if ((uVar10 != 0) || (uVar10 = puVar2[0xc9], uVar10 != 0)) {

              if (uVar18 == 0) {

                if (uVar10 != 0) {

                  sound_play_obj(0x41a,uVar10);

                  iVar8 = reaper_0052e4a0(param_1);

                  if (iVar8 != 0) {

                    fStack_1d4 = *(float *)(uVar10 + 0x188);

                    fStack_1d0 = 1.47136e-42;

                    goto LAB_004612d0;

                  }

                }

              }

              else if (uVar10 != 0) {

                sound_play_obj(0x3fb,uVar10);

                iVar8 = reaper_0052e4a0(param_1);

                if (iVar8 != 0) {

                  fStack_1d4 = *(float *)(uVar10 + 0x188);

                  fStack_1d0 = 1.42792e-42;

LAB_004612d0:

                  reaper_00530bd0(param_1,0,2,0,0x13,&fStack_1d4);

                }

              }

              uVar19 = puVar2[0x14];

              if ((uVar19 == 0) ||

                 (((((((((iVar8 = *(int *)(uVar19 + 4), iVar8 != 3 ||

                         (*(int *)(uVar19 + 0x210) != 0)) && (iVar8 != 0x425)) &&

                       ((iVar8 != 0x426 && (iVar8 != 0x4a1)))) && (iVar8 != 0x4a2)) &&

                     ((iVar8 != 0x4a4 && (iVar8 != 0x4a3)))) &&

                    ((iVar8 != 0x3c && (((iVar8 != 2 && (iVar8 != 1)) && (iVar8 != 0xe6)))))) &&

                   ((((iVar8 != 0x49 && (iVar8 != 0xe5)) && (iVar8 != 0x438)) &&

                    ((iVar8 != 8 && (iVar8 != 0xb)))))) && (iVar8 != 0xd7)))) {

                project_cursor_to_ground(&fStack_198,0x459c4000,&fStack_1e8);

                kbos_offspring_process(uVar10,&fStack_198,0);

              }

              else {

                FUN_0046b7f0(uVar10,uVar19,uVar18);

              }

            }

          }

        }

        else if (puVar2[3] == 0) {

          if ((((~uVar18 & 0x800) != 0) && (uVar10 == 0)) &&

             (iVar8 = FUN_0046b850(uVar19), iVar8 != 0)) {

            puVar2[0x17] = puVar2[0x14];

            uVar10 = *puVar2 | 0x800;

            goto LAB_004614e8;

          }

        }

        else if ((uStack_19c != 0x87) && (uStack_19c != 0x88)) {

          puVar2[0x17] = uVar19;

          iVar8 = crt_rand_scaled(2);

          uStack_1f4 = iVar8 + 0x87;

          goto LAB_004630ec;

        }

      }

      iVar8 = iStack_188;

      if (((*puVar2 & 2) != 0) && ((iStack_188 == 8 || (iStack_188 == 9)))) {

        *puVar2 = *puVar2 | 0x300;

        fStack_1a0 = (float)((uint)fStack_1a0 & 0xfffffffc);

      }

      uVar10 = *puVar2;

      if (((((uVar10 & 8) == 0) || ((~uVar10 & 0x10) == 0)) &&

          (((uVar10 & 2) == 0 || ((~uVar10 & 4) == 0)))) || (fStack_1ec <= 0.0)) {

        if ((uVar10 & 8) != 0) {

          *puVar2 = uVar10 & 0xffdfffff;

          if ((~(uVar10 & 0xffdfffff) & 0x100000) == 0) goto LAB_00461d6c;

          puVar2[1] = 0x41200000;

          if ((puVar2[3] != 0) &&

             (iVar11 = validate_eat__FP6OBJECTT0(param_1,puVar2[3]), iVar11 != 0)) {

            if (((~*puVar2 & 0x10) != 0) &&

               (((iVar8 != 8 && (*(char *)(param_1 + 0x20a) == '\0')) &&

                (*(char *)(param_1 + 0x20b) == '\0')))) {

              uStack_1b0 = 8;

              iVar8 = crt_rand_scaled(100);

              if (iVar8 < 0x4b) {

                uVar9 = crt_rand_scaled(4);

                switch(uVar9) {

                case 0:

                  uStack_1f4 = 0xbd;

                  uVar10 = *puVar2 | 0x100000;

                  break;

                case 1:

                  uStack_1f4 = 0xbe;

                  uVar10 = *puVar2 | 0x100000;

                  break;

                case 2:

                  uStack_1f4 = 0xbf;

                  uVar10 = *puVar2 | 0x100000;

                  break;

                case 3:

                  uStack_1ac = 0x33;

                  uStack_1f4 = DAT_0055aa6c;

                default:

                  uVar10 = *puVar2 | 0x100000;

                }

              }

              else {

                uStack_1f4 = 0x60;

                uVar10 = *puVar2 | 0x100000;

              }

              goto LAB_004630ea;

            }

            goto LAB_00461d6c;

          }

          puVar2[1] = 0x41200000;

          if (((-1 < (int)fStack_1b4) &&

              ((*(uint *)(&DAT_0055a4e8 + (int)fStack_1b4 * 0x1c) & 0x14f0) != 0)) ||

             (iVar8 = ai_target_classify(param_1,puVar2[0x15],2), iVar8 == 0)) goto LAB_00461d6c;

          if ((float)puVar2[0x4c] <= 0.0) {

            uVar10 = 0x30;

            iVar8 = crt_rand_scaled(100);

            if (0x4b < iVar8) {

              uVar10 = 0xc0;

            }

            if (((~*puVar2 & 0x40) == 0) && (puVar2[2] == 0)) {

              uVar10 = uVar10 & 0xffffffdf;

            }

            else {

              uVar10 = uVar10 & 0xffffffef;

            }

          }

          else {

            uVar10 = 0x1000;

          }

          uVar19 = ChooseAnim__FP6OBJECTT0PfP10T_AnimInfoUi

                             (param_1,puVar2[0x15],&fStack_1e8,&DAT_0055a4d8,uVar10);

          uVar18 = puVar2[0x15];

          if ((*(int *)(uVar18 + 0x10) == 0xfe) ||

             (iVar8 = *(int *)(*(int *)(uVar18 + 8) + 8 + *(int *)(uVar18 + 0x10) * 4), iVar8 == 0))

          {

            pfVar13 = (float *)(*(int *)(*(int *)(uVar18 + 8) + 0x400) + 0x44);

          }

          else {

            pfVar13 = (float *)(iVar8 + 0xc);

          }

          fVar21 = (pfVar13[5] - pfVar13[2]) * (pfVar13[5] - pfVar13[2]) +

                   (pfVar13[4] - pfVar13[1]) * (pfVar13[4] - pfVar13[1]) +

                   (pfVar13[3] - *pfVar13) * (pfVar13[3] - *pfVar13);

          fStack_1ec = (float)puVar2[0x66] * (float)puVar2[0x66];

          if (fVar21 < fStack_1ec) {

            fVar21 = fStack_1ec;

          }

          if (fVar21 * 0.8 <= fStack_1e8) goto LAB_00461d6c;

          if ((uVar10 & 0x30) != 0) {

            *puVar2 = *puVar2 ^ 0x40;

          }

          if ((int)uVar19 < 0) goto LAB_00461d6c;

          puVar2[0x1f] = (uint)fVar21;

          puVar2[0x1e] = 0xbf800000;

          puVar2[0x17] = uVar18;

          uStack_1f4 = (&DAT_0055a4d8)[uVar19 * 7];

          uStack_1b0 = 6;

          uStack_1ac = uVar19;

          goto LAB_004630ec;

        }

        if ((uVar10 & 2) == 0) {

          *puVar2 = uVar10 & 0xffcfffff;

        }

        else {

          uVar10 = uVar10 & 0xffefffff;

          *puVar2 = uVar10;

          if ((~uVar10 & 0x200000) != 0) {

            puVar2[1] = 0x41200000;

            if (puVar2[2] == 0) {

              if (puVar2[3] == 0) {

                if (((((int)fStack_1b4 < 0) ||

                     ((*(uint *)(&DAT_0055a4e8 + (int)fStack_1b4 * 0x1c) & 0x80f) == 0)) &&

                    (iVar8 = ai_target_classify(param_1,puVar2[0x15],1), iVar8 != 0)) &&

                   (((uVar10 = puVar2[0x15], *(int *)(uVar10 + 0x1e0) != 0x12 ||

                     (*(int *)(uVar10 + 0x274) == 0)) ||

                    (*(int *)(*(int *)(uVar10 + 0x274) + 4) != 3)))) {

                  if ((float)puVar2[0x4c] <= 0.0) {

                    uVar9 = 1;

                  }

                  else {

                    uVar9 = 0x800;

                  }

                  uVar18 = ChooseAnim__FP6OBJECTT0PfP10T_AnimInfoUi

                                     (param_1,uVar10,&fStack_1e8,&DAT_0055a4d8,uVar9);

                  uVar10 = puVar2[0x15];

                  if ((*(int *)(uVar10 + 0x10) == 0xfe) ||

                     (iVar8 = *(int *)(*(int *)(uVar10 + 8) + 8 + *(int *)(uVar10 + 0x10) * 4),

                     iVar8 == 0)) {

                    pfVar13 = (float *)(*(int *)(*(int *)(uVar10 + 8) + 0x400) + 0x44);

                  }

                  else {

                    pfVar13 = (float *)(iVar8 + 0xc);

                  }

                  fVar21 = (pfVar13[5] - pfVar13[2]) * (pfVar13[5] - pfVar13[2]) +

                           (pfVar13[4] - pfVar13[1]) * (pfVar13[4] - pfVar13[1]) +

                           (pfVar13[3] - *pfVar13) * (pfVar13[3] - *pfVar13);

                  fStack_1ec = (float)puVar2[0x66] * (float)puVar2[0x66];

                  if (fVar21 < fStack_1ec) {

                    fVar21 = fStack_1ec;

                  }

                  if (fStack_1e8 < fVar21 * 0.8) {

                    puVar2[0x1f] = (uint)fVar21;

                    puVar2[0x1e] = 0xbf800000;

                    puVar2[0x17] = uVar10;

                    if ((*(uint *)(&DAT_0055a4e8 + uVar18 * 0x1c) & 0x800) != 0) {

                      sound_play_player(0x462,param_1);

                      iVar8 = reaper_0052e4a0(param_1);

                      if (iVar8 != 0) {

                        fStack_1f0 = 1.57226e-42;

                        reaper_00530bd0(param_1,0,1,0,0x11,&fStack_1f0);

                      }

                    }

                    uStack_1f4 = (&DAT_0055a4d8)[uVar18 * 7];

                    uStack_1b0 = 7;

                    uStack_1ac = uVar18;

                    goto LAB_004630ec;

                  }

                }

              }

              else if ((puVar2[3] != 0) && ((~uVar10 & 4) != 0)) {

                uStack_1b0 = 9;

                uStack_1f4 = 0x5f;

                *puVar2 = uVar10 | 0x200000;

                goto LAB_004630f8;

              }

            }

            else if (((((int)fStack_1b4 < 0) || (((&DAT_0055a4e8)[(int)fStack_1b4 * 0x1c] & 8) == 0)

                      ) && (uVar10 = puVar2[0x15], uVar10 != 0)) &&

                    ((**(int **)(uVar10 + 8) == 0x2b0 &&

                     (uVar10 = ChooseAnim__FP6OBJECTT0PfP10T_AnimInfoUi

                                         (param_1,uVar10,&fStack_1e8,&DAT_0055a4d8,8),

                     fStack_1e8 < 625.0)))) {

              puVar2[0x1e] = 0xbf800000;

              puVar2[0x1f] = 0x41a00000;

              puVar2[0x17] = puVar2[0x15];

              PhysicsExZeroVelocity(param_1);

              *(undefined4 *)(param_1 + 0x10c) = 0;

              *(undefined4 *)(param_1 + 0x114) = 0;

              *(undefined4 *)(param_1 + 0x110) = 0;

              sound_play_player(0x43c,param_1);

              iVar8 = reaper_0052e4a0(param_1);

              if (iVar8 != 0) {

                fStack_1f0 = 1.51901e-42;

                reaper_00530bd0(param_1,0,1,0,0x11,&fStack_1f0);

              }

              uStack_1f4 = (&DAT_0055a4d8)[uVar10 * 7];

              uStack_1b0 = 7;

              uStack_1ac = uVar10;

              goto LAB_004630e3;

            }

          }

        }

LAB_00461d6c:

        uVar10 = uStack_19c;

        if (uStack_19c == 0x9d) {

          fVar26 = (float10)FUN_00518b70(param_1,0);

          fVar26 = (float10)(float)puVar2[0x37] - fVar26 * (float10)(float)puVar2[0x42];

          puVar2[0x37] = (uint)(float)fVar26;

          if (fVar26 < (float10)0.0 != (fVar26 == (float10)0.0)) {

            FootDust(param_1,(fStack_174 * *(float *)(param_1 + 300) -

                              fStack_170 * *(float *)(param_1 + 0x128) < 0.0) + '\b',0,puVar2[0x74])

            ;

            puVar2[0x37] = 0x41a00000;

          }

        }

        else {

          uVar18 = **(uint **)(param_1 + 0x100);

          if ((uVar18 & 0x1000000) != 0) {

            **(uint **)(param_1 + 0x100) = uVar18 & 0xfeffffff;

            sound_stop_obj(0x472,param_1);

            iVar8 = reaper_0052e4a0(param_1);

            if (iVar8 != 0) {

              fStack_1e8 = 1.59468e-42;

              reaper_00530bd0(param_1,0,1,0,0x12,&fStack_1e8);

            }

          }

        }

        if ((*(float *)(DAT_00632ed8 + 0x6ec) < *(float *)(param_1 + 0x130)) &&

           ((*puVar2 & 0x10000) != 0)) goto LAB_004630ec;

        if (*(float *)(param_1 + 0x130) < *(float *)(DAT_00632ed8 + 0x6ec)) {

          if (*(float *)(param_1 + 0xa8) - *(float *)(param_1 + 0x140) <= 50.0) {

            if (((((puVar2[0x39] & 2) == 0) ||

                 (*(float *)(DAT_00632ed8 + 0x6e8) <= *(float *)(param_1 + 0x130))) ||

                ((uVar10 == 0x9a || (uVar10 == 0xa9)))) &&

               (((puVar2[0x39] & 2) == 0 || ((uVar10 != 0x9a && (uVar10 != 0xa9))))))

            goto LAB_004630ec;

            uVar10 = **(uint **)(param_1 + 0x100);

            if ((uVar10 & 0x1000000) == 0) {

              **(uint **)(param_1 + 0x100) = uVar10 | 0x1000000;

              sound_play_player(0x472,param_1);

              iVar8 = reaper_0052e4a0(param_1);

              if (iVar8 != 0) {

                fStack_1f0 = 1.59468e-42;

                reaper_00530bd0(param_1,0,1,0,0x11,&fStack_1f0);

              }

            }

            uStack_1f4 = 0x9d;

            uStack_1d8 = 0x21;

          }

          else {

            if (*(float *)(DAT_00632ed8 + 0x6e8) <= *(float *)(param_1 + 0x130)) goto LAB_004630ec;

            uStack_1f4 = 0x9a;

            uStack_1d8 = 0x21;

            uStack_180 = 0;

          }

          goto LAB_004630f8;

        }

        if ((((uVar10 == 0x9a) || (uVar10 == 0xa9)) || (uVar10 == 0xa8)) || (uVar10 == 0xab)) {

          fVar21 = *(float *)(param_1 + 0x130) - *(float *)(param_1 + 0x13c);

          cVar20 = (*(float *)(DAT_00632ed8 + 0x6f0) <= fVar21) +

                   (*(float *)(DAT_00632ed8 + 0x6f4) <= fVar21);

          make_dust_ball(param_1 + 0xa0,fVar21 * (float)puVar2[0x74] * 0.01);

          sound_play_player(0x444,param_1);

          iVar8 = reaper_0052e4a0(param_1);

          if (cVar20 == '\x02') {

            if (iVar8 != 0) {

              fStack_1e8 = 1.53022e-42;

              reaper_00530bd0(param_1,0,1,0,0x11,&fStack_1e8);

            }

            uStack_1f4 = 0x9b;

          }

          else if (cVar20 == '\x01') {

            if (iVar8 != 0) {

              fStack_1e8 = 1.53022e-42;

              reaper_00530bd0(param_1,0,1,0,0x11,&fStack_1e8);

            }

            uStack_1f4 = 0xa2;

          }

          else {

            if (iVar8 != 0) {

              fStack_1e8 = 1.53022e-42;

              reaper_00530bd0(param_1,0,1,0,0x11,&fStack_1e8);

            }

            uStack_1f4 = 0xbc;

          }

          fStack_1e8 = (float)(int)*(char *)(param_1 + 0x20a);

          if (((float)(int)fStack_1e8 == 0.0) &&

             (fStack_1e8 = (float)(int)*(char *)(param_1 + 0x20b), (float)(int)fStack_1e8 == 0.0))

          goto LAB_004630ec;

        }

        iVar8 = iStack_188;

        uVar18 = uStack_1c8;

        if ((uVar10 == 0x9d) && ((float)puVar2[0x38] < 0.5)) goto LAB_004630ec;

        if ((((float)puVar2[0xc6] != 0.0) || ((float)puVar2[199] != 0.0)) &&

           ((*(byte *)(param_1 + 0x20c) & 0x20) != 0)) {

          iVar8 = crt_rand_scaled(100);

          if (iVar8 < 0x32) {

            sound_play_player(0x415,param_1);

            iVar8 = reaper_0052e4a0(param_1);

            if (iVar8 != 0) {

              fStack_1f0 = 1.46436e-42;

LAB_00462186:

              reaper_00530bd0(param_1,0,1,0,0x11,&fStack_1f0);

            }

          }

          else {

            sound_play_player(0x416,param_1);

            iVar8 = reaper_0052e4a0(param_1);

            if (iVar8 != 0) {

              fStack_1f0 = 1.46576e-42;

              goto LAB_00462186;

            }

          }

          uStack_1ac = 0x37;

          uStack_1f4 = DAT_0055aadc;

          goto LAB_004630e3;

        }

        if ((fStack_1b4 == 7.70714e-44) && (uStack_1c8 == 0)) {

          if ((iStack_1a4 < 0x4b00) && (0x4aff < iStack_1c4)) {

            (*(code *)PTR_crt_matrix_mul_00580c18)

                      (auStack_144,param_1 + 0x294,*(int *)(param_1 + 0x2dc) + 0x2a8);

            fStack_1e8 = fStack_138 * 0.0;

            iVar8 = *(int *)(param_1 + 0x100);

            fStack_1e4 = fStack_128 * 0.0;

            fStack_1e0 = fStack_118 * 0.0;

            fStack_1d4 = fStack_134 - fStack_138 * 10.0;

            fStack_1d0 = fStack_124 - fStack_128 * 10.0;

            fStack_1cc = fStack_114 - fStack_118 * 10.0;

            if ((*(float *)(iVar8 + 0x318) < 1.0) || (*(int *)(iVar8 + 800) != 0)) {

              if ((1.0 <= *(float *)(iVar8 + 0x31c)) && (*(int *)(iVar8 + 0x324) == 0)) {

                iVar11 = object_spawn_init_usage(param_1,&fStack_1d4,&fStack_1e8);

                if (iVar11 != 0) {

                  *(undefined4 *)(iVar11 + 0x18c) = *(undefined4 *)(param_1 + 0x18c);

                  iVar14 = reaper_0052e4a0(param_1);

                  if (iVar14 != 0) {

                    fStack_164 = fStack_1d0;

                    fStack_158 = fStack_1e4;

                    fStack_168 = fStack_1d4;

                    fStack_160 = fStack_1cc;

                    fStack_15c = fStack_1e8;

                    uStack_150 = *(undefined4 *)(iVar11 + 0x188);

                    fStack_154 = fStack_1e0;

                    reaper_00530bd0(param_1,6,1,0,10,&fStack_168);

                  }

                }

                *(int *)(iVar8 + 0x324) = iVar11;

                *(undefined4 *)(iVar8 + 0x31c) = 0;

              }

            }

            else {

              iVar11 = object_spawn_init_usage(param_1,&fStack_1d4,&fStack_1e8);

              if (iVar11 != 0) {

                *(undefined4 *)(iVar11 + 0x18c) = *(undefined4 *)(param_1 + 0x18c);

                iVar14 = reaper_0052e4a0(param_1);

                if (iVar14 != 0) {

                  fStack_164 = fStack_1d0;

                  fStack_158 = fStack_1e4;

                  fStack_168 = fStack_1d4;

                  fStack_160 = fStack_1cc;

                  fStack_15c = fStack_1e8;

                  uStack_150 = *(undefined4 *)(iVar11 + 0x188);

                  fStack_154 = fStack_1e0;

                  reaper_00530bd0(param_1,6,1,0,10,&fStack_168);

                }

              }

              *(int *)(iVar8 + 800) = iVar11;

              *(undefined4 *)(iVar8 + 0x318) = 0;

            }

          }

          goto LAB_004630e3;

        }

        if ((iStack_188 != 6) && (iStack_188 != 7)) {

          if (((uint)fStack_1a0 & 2) != 0) {

            uStack_1b0 = 4;

            uStack_180 = 2;

            if ((puVar2[3] == 0) && (puVar2[2] != 0)) {

              if (*(float *)(param_1 + 0x110) <= 0.0) {

                uStack_1f4 = 0x7f;

                uStack_1d8 = 0x21;

              }

              else {

                uStack_1f4 = 0x7e;

                uStack_1d8 = 0x31;

              }

            }

            else if (*(float *)(param_1 + 0x110) <= 0.0) {

              uStack_1f4 = 0x74;

              uStack_1d8 = 0x21;

            }

            else {

              uStack_1f4 = 0x73;

              uStack_1d8 = 0x31;

            }

            goto LAB_004630f8;

          }

          if (((uint)fStack_1a0 & 1) != 0) {

            fStack_184 = (float)puVar2[0x5d];

            uStack_1b0 = 3;

            uStack_180 = 1;

            if ((uStack_1c8 != 0) || (iStack_188 != 3)) {

              if (puVar2[3] == 0) {

                if (puVar2[2] != 0) {

                  uStack_178 = 0x20;

                  fStack_1e8 = 0.25;

                  uStack_1f4 = 0x7c;

                  uStack_1d8 = 0xa1;

                  goto LAB_004630f8;

                }

                crt_rand_scaled(100);

                if (iVar8 != 3) {

                  uStack_1d8 = 0xa0;

                  uStack_178 = 0x20;

                  fStack_1e8 = 0.25;

                }

                if (ABS(*(float *)(param_1 + 0x10c)) < (float)puVar2[0x5b]) {

                  if (ABS(*(float *)(param_1 + 0x10c)) < (float)puVar2[0x5a]) {

                    if ((uVar18 != 0) || (iVar8 != 3)) {

                      uVar10 = **(uint **)(param_1 + 0x100);

                      if ((uVar10 & 0x2000000) == 0) {

                        **(uint **)(param_1 + 0x100) = uVar10 | 0x2000000;

                        sound_play_player(0x6dc,param_1);

                        iVar8 = reaper_0052e4a0(param_1);

                        if (iVar8 != 0) {

                          fStack_1f0 = 2.46068e-42;

                          reaper_00530bd0(param_1,0,1,0,0x11,&fStack_1f0);

                        }

                      }

                      uVar10 = **(uint **)(param_1 + 0x100);

                      if ((uVar10 & 0x4000000) != 0) {

                        **(uint **)(param_1 + 0x100) = uVar10 & 0xfbffffff;

                        sound_stop_obj(0x6dd,param_1);

                        iVar8 = reaper_0052e4a0(param_1);

                        if (iVar8 != 0) {

                          fStack_1f0 = 2.46208e-42;

                          reaper_00530bd0(param_1,0,1,0,0x12,&fStack_1f0);

                        }

                      }

                      uStack_1d8 = uStack_1d8 | 1;

                      uStack_1f4 = 2;

                      goto LAB_004630f8;

                    }

                  }

                  else {

                    fStack_184 = (float)puVar2[0x5e];

                    if ((uVar18 != 0) || (iVar8 != 3)) {

                      uStack_1f4 = 0xa4;

                      goto LAB_00462744;

                    }

                  }

                }

                else {

                  fStack_184 = (float)puVar2[0x5f];

                  if ((uVar18 != 0) || (iVar8 != 3)) {

                    uVar10 = **(uint **)(param_1 + 0x100);

                    if ((uVar10 & 0x4000000) == 0) {

                      **(uint **)(param_1 + 0x100) = uVar10 | 0x4000000;

                      sound_play_player(0x6dd,param_1);

                      iVar8 = reaper_0052e4a0(param_1);

                      if (iVar8 != 0) {

                        fStack_1f0 = 2.46208e-42;

                        reaper_00530bd0(param_1,0,1,0,0x11,&fStack_1f0);

                      }

                    }

                    uVar10 = **(uint **)(param_1 + 0x100);

                    if ((uVar10 & 0x2000000) != 0) {

                      **(uint **)(param_1 + 0x100) = uVar10 & 0xfdffffff;

                      sound_stop_obj(0x6dc,param_1);

                      iVar8 = reaper_0052e4a0(param_1);

                      if (iVar8 != 0) {

                        fStack_1f0 = 2.46068e-42;

                        reaper_00530bd0(param_1,0,1,0,0x12,&fStack_1f0);

                      }

                    }

                    uStack_1f4 = 0xa5;

LAB_00462744:

                    uStack_1d8 = uStack_1d8 | 1;

                    fStack_1a8 = 0.125;

                    goto LAB_004630f8;

                  }

                }

              }

              else {

                if (iStack_188 != 3) {

                  uStack_1d8 = 0xa0;

                  uStack_178 = 0x20;

                  fStack_1e8 = 0.25;

                }

                if (ABS(*(float *)(param_1 + 0x10c)) < (float)puVar2[0x5b]) {

                  if ((uStack_1c8 != 0) || (iStack_188 != 3)) {

                    uStack_1d8 = uStack_1d8 | 1;

                    uStack_1ac = 0x35;

                    uStack_1f4 = DAT_0055aaa4;

                    fStack_1a8 = 0.125;

                  }

                }

                else if ((uStack_1c8 != 0) || (iStack_188 != 3)) {

                  fStack_184 = (float)puVar2[0x5f];

                  uStack_1d8 = uStack_1d8 | 1;

                  uStack_1f4 = 0xcb;

                  fStack_1a8 = 0.125;

                  goto LAB_004630f8;

                }

              }

            }

            goto LAB_004630ec;

          }

        }

        if (iStack_188 != 3) {

          uVar10 = **(uint **)(param_1 + 0x100);

          if ((uVar10 & 0x4000000) != 0) {

            **(uint **)(param_1 + 0x100) = uVar10 & 0xfbffffff;

            sound_stop_obj(0x6dd,param_1);

            iVar8 = reaper_0052e4a0(param_1);

            if (iVar8 != 0) {

              fStack_1e8 = 2.46208e-42;

              reaper_00530bd0(param_1,0,1,0,0x12,&fStack_1e8);

            }

          }

          uVar10 = **(uint **)(param_1 + 0x100);

          if ((uVar10 & 0x2000000) != 0) {

            **(uint **)(param_1 + 0x100) = uVar10 & 0xfdffffff;

            sound_stop_obj(0x6dc,param_1);

            iVar8 = reaper_0052e4a0(param_1);

            if (iVar8 != 0) {

              fStack_1e8 = 2.46068e-42;

              reaper_00530bd0(param_1,0,1,0,0x12,&fStack_1e8);

            }

          }

        }

        if ((*(char *)(param_1 + 0x20c) < '\0') && (3.0 <= (float)puVar2[0x57])) {

          uVar10 = puVar2[3];

          if (uVar10 == 0) {

LAB_0046297c:

            uVar10 = 0;

            puVar12 = puVar2 + 4;

            do {

              if (*puVar12 != 0) {

                if (((int)uVar10 < 2) && (-1 < (int)uVar10)) {

                  uStack_1ac = (uVar10 & 1) + 0x31;

                  uStack_1f4 = (&DAT_0055a4d8)[uStack_1ac * 7];

                  uStack_1b0 = 10;

                  goto LAB_004630ec;

                }

                break;

              }

              uVar10 = uVar10 + 1;

              puVar12 = puVar12 + 1;

            } while ((int)uVar10 < 2);

          }

          else if (*(int *)(uVar10 + 4) != 0x2a5) {

            if (uVar10 == 0) goto LAB_0046297c;

            uVar10 = 0;

            puVar12 = puVar2 + 4;

            do {

              if (*puVar12 == 0) {

                if (((int)uVar10 < 2) && (-1 < (int)uVar10)) {

                  uStack_1b0 = 0xb;

                  uStack_1ac = (uVar10 & 1) + 0x2f;

                  goto LAB_0046452d;

                }

                break;

              }

              uVar10 = uVar10 + 1;

              puVar12 = puVar12 + 1;

            } while ((int)uVar10 < 2);

          }

        }

        if (((float)puVar2[0x57] != (float)puVar2[0x56]) && (iStack_188 != 0x10)) {

          uStack_1b0 = 0x10;

          iVar8 = crt_rand_scaled(3);

          if (iVar8 == 0) {

            uStack_1ac = 0x36;

            uStack_1f4 = DAT_0055aac0;

          }

          else if ((iVar8 == 1) || (iVar8 == 2)) {

            uStack_1f4 = 0xba;

          }

          iVar8 = crt_rand_scaled(100);

          if (iVar8 < 0x32) {

            sound_play_player(0x467,param_1);

            iVar8 = reaper_0052e4a0(param_1);

            if (iVar8 != 0) {

              fStack_1e8 = 1.57926e-42;

LAB_00462a25:

              reaper_00530bd0(param_1,0,1,0,0x11,&fStack_1e8);

            }

          }

          else {

            sound_play_player(0x468,param_1);

            iVar8 = reaper_0052e4a0(param_1);

            if (iVar8 != 0) {

              fStack_1e8 = 1.58066e-42;

              goto LAB_00462a25;

            }

          }

        }

        uVar10 = *(uint *)(param_1 + 0x20c);

        if ((uVar10 & 0x100) != 0) {

          iVar8 = crt_rand_scaled(100);

          if (iVar8 < 0x32) {

            sound_play_player(0x467,param_1);

            iVar8 = reaper_0052e4a0(param_1);

            if (iVar8 != 0) {

              fStack_1f0 = 1.57926e-42;

LAB_00462a8b:

              reaper_00530bd0(param_1,0,1,0,0x11,&fStack_1f0);

            }

          }

          else {

            sound_play_player(0x468,param_1);

            iVar8 = reaper_0052e4a0(param_1);

            if (iVar8 != 0) {

              fStack_1f0 = 1.58066e-42;

              goto LAB_00462a8b;

            }

          }

          uStack_1ac = 0x36;

          uStack_1f4 = DAT_0055aac0;

          goto LAB_004630ec;

        }

        if ((uVar10 & 0x200) != 0) {

          iVar8 = crt_rand_scaled(100);

          if (iVar8 < 0x32) {

            sound_play_player(0x467,param_1);

            iVar8 = reaper_0052e4a0(param_1);

            if (iVar8 != 0) {

              fStack_1f0 = 1.57926e-42;

LAB_00462b01:

              reaper_00530bd0(param_1,0,1,0,0x11,&fStack_1f0);

            }

          }

          else {

            sound_play_player(0x468,param_1);

            iVar8 = reaper_0052e4a0(param_1);

            if (iVar8 != 0) {

              fStack_1f0 = 1.58066e-42;

              goto LAB_00462b01;

            }

          }

          uStack_1f4 = 0xba;

          goto LAB_004630f8;

        }

        if ((uVar10 & 0x400) != 0) {

          iVar8 = crt_rand_scaled(100);

          if (iVar8 < 0x32) {

            sound_play_player(0x467,param_1);

            iVar8 = reaper_0052e4a0(param_1);

            if (iVar8 != 0) {

              fStack_1f0 = 1.57926e-42;

LAB_00462b6e:

              reaper_00530bd0(param_1,0,1,0,0x11,&fStack_1f0);

            }

          }

          else {

            sound_play_player(0x468,param_1);

            iVar8 = reaper_0052e4a0(param_1);

            if (iVar8 != 0) {

              fStack_1f0 = 1.58066e-42;

              goto LAB_00462b6e;

            }

          }

          uStack_1f4 = 0xbb;

          goto LAB_004630f8;

        }

        if (iStack_188 == 0xb) {

          if ((0x12bf < iStack_1c4) && (puVar2[3] != 0)) {

            uVar10 = 0;

            puVar12 = puVar2 + 4;

            do {

              if (*puVar12 == 0) {

                if (((int)uVar10 < 2) && (-1 < (int)uVar10)) {

                  puVar2[uVar10 + 4] = puVar2[3];

                  puVar2[uVar10 + 0xc] = puVar2[0xb];

                  puVar2[3] = 0;

                  iVar8 = dialog_level_is_base();

                  if ((iVar8 == 0) || ((*(byte *)(puVar2[uVar10 + 4] + 0x1c8) & 1) == 0)) {

                    reaper_lock_short_5(param_1,puVar2[uVar10 + 4],0x3f800000,uVar10 & 1,1);

                  }

                  else {

                    fStack_1f0 = *(float *)(puVar2[uVar10 + 4] + 4);

                    fStack_1e8 = (float)puVar2[uVar10 + 0xc];

                    fStack_1ec = (float)kabuto_corpse_create__FP6OBJECTi(0,fStack_1f0);

                    iVar8 = reaper_0052e4a0(param_1);

                    if (iVar8 == 0) {

                      *(undefined4 *)((int)fStack_1ec + 0x188) = 0;

                    }

                    else {

                      fStack_194 = *(float *)((int)fStack_1ec + 0x188);

                      fStack_198 = fStack_1e8;

                      fStack_190 = fStack_1f0;

                      uStack_18c = (undefined1)(uVar10 & 1);

                      reaper_00530bd0(param_1,1,2,1,0x15,&fStack_198);

                    }

                    reaper_lock_short_5(param_1,fStack_1ec,fStack_1e8,uVar10 & 1,0);

                    fStack_1a0 = (float)puVar2[uVar10 + 0xc];

                    uVar18 = puVar2[uVar10 + 4];

                    iVar8 = reaper_0052e4a0(param_1);

                    if (iVar8 != 0) {

                      fStack_1d0 = *(float *)(uVar18 + 0x188);

                      fStack_1d4 = fStack_1a0;

                      reaper_00530bd0(param_1,1,1,0,8,&fStack_1d4);

                    }

                    if (fStack_1a0 != 0.0) {

                      *(float *)(uVar18 + 0xc4) = *(float *)(uVar18 + 0xc4) / fStack_1a0;

                    }

                    *(undefined4 *)(uVar18 + 0x210) = 0;

                    if (*(int *)(uVar18 + 0x1e0) == 0x59) {

                      if (*(int *)(uVar18 + 0x218) < 2) {

                        FUN_00425850(uVar18);

                      }

                    }

                    else if (*(int *)(uVar18 + 0x1e0) == 0x12) {

                      smartie_release_to_bldg();

                    }

                    else {

                      iVar8 = ObjIsReaper(uVar18);

                      if (iVar8 != 0) {

                        *(undefined4 *)(uVar18 + 0xc4) =

                             *(undefined4 *)(*(int *)(uVar18 + 0x100) + 0xfac);

                      }

                    }

                    *(uint *)(uVar18 + 0xd8) = *(uint *)(uVar18 + 0xd8) & 0xfff7ffff | 0x10000000;

                    uVar18 = puVar2[uVar10 + 4];

                    iVar8 = fx_create(param_1);

                    if (iVar8 != 0) {

                      obj_damage_apply(5,0x461c4000,uVar18,param_1,0,0);

                    }

                    puVar2[uVar10 + 4] = (uint)fStack_1ec;

                  }

                  goto LAB_004630ec;

                }

                break;

              }

              uVar10 = uVar10 + 1;

              puVar12 = puVar12 + 1;

            } while ((int)uVar10 < 2);

          }

        }

        else if (iStack_188 == 10) {

          iVar8 = 0;

          puVar12 = puVar2 + 4;

          do {

            if (*puVar12 != 0) {

              if ((iVar8 < 2) && (-1 < iVar8)) {

                if ((iStack_1a4 < 0x1040) && (0x103f < iStack_1c4)) {

                  uVar10 = puVar2[iVar8 + 4];

                  puVar2[3] = uVar10;

                  puVar2[0xb] = puVar2[iVar8 + 0xc];

                  reaper_lock_short_5(param_1,uVar10,0x3f800000,3,1);

                  puVar2[iVar8 + 4] = 0;

                }

                if (uStack_1c8 == 0) goto LAB_004630ec;

              }

              break;

            }

            iVar8 = iVar8 + 1;

            puVar12 = puVar12 + 1;

          } while (iVar8 < 2);

        }

        iVar8 = iStack_1a4;

        if (uStack_19c != 0xbd) {

          if (uStack_19c == 0xbe) {

            if ((iStack_1c4 < 0xb8f) || (puVar2[3] == 0)) {

              if (iStack_1c4 < 0x321) goto LAB_00463ff9;

              bVar25 = SBORROW4(iStack_1c4,0xb8f);

              bVar24 = iStack_1c4 + -0xb8f < 0;

              goto LAB_004630d1;

            }

            iVar8 = *(int *)(param_1 + 0x100);

            iVar11 = *(int *)(iVar8 + 0xc);

            if (iVar11 != 0) {

              fStack_1ec = 2.0;

              fStack_1e8 = 0.0;

              iVar15 = dialog_level_is_base();

              iVar14 = *(int *)(iVar11 + 4);

              if (iVar15 == 0) {

                if ((iVar14 == 0xb) || (iVar14 == 0x539)) {

                  uVar18 = 1;

                  uVar10 = uVar18;

                }

                else {

                  uVar18 = 0;

                  uVar10 = uVar18;

                }

              }

              else {

                if ((iVar14 == 0x2e6) || (iVar14 == 0x248)) {

                  fStack_1e8 = 1.4013e-45;

                  iVar14 = reaper_0052e4a0(param_1);

                  if (iVar14 != 0) {

                    comm_death_packet_build

                              (param_1,0,*(int *)(param_1 + 0x18c) + -1,

                               *(int *)(iVar11 + 0x18c) + -1,(float)DAT_00632f28,0x3f800000,0,0);

                    rpman_move(param_1,*(int *)(iVar11 + 0x18c) + -1);

                  }

                }

                uVar18 = ObjIsPlayer(iVar11);

                uVar10 = (uint)(*(int *)(iVar11 + 4) == 0xb);

                if (*(int *)(iVar11 + 4) == 0xb) {

                  uVar18 = 1;

                  fStack_1ec = 1.0;

                }

              }

              if (3.0 <= *(float *)(iVar8 + 0x158)) {

                if (uVar10 != 0) {

                  if ((1.0 <= *(float *)(iVar8 + 0x318)) || (*(int *)(iVar8 + 800) != 0)) {

                    if ((*(float *)(iVar8 + 0x31c) < 1.0) && (*(int *)(iVar8 + 0x324) == 0)) {

                      *(float *)(iVar8 + 0x31c) = *(float *)(iVar8 + 0x31c) + 1.0;

                    }

                  }

                  else {

                    *(float *)(iVar8 + 0x318) = *(float *)(iVar8 + 0x318) + 1.0;

                  }

                }

              }

              else if (fStack_1e8 == 0.0) {

                if (uVar18 != 0) {

                  fVar21 = *(float *)(DAT_00632ed8 + 0x10ac);

                  if (1.0 <= *(float *)(iVar8 + 0x158)) {

                    fVar21 = *(float *)(DAT_00632ed8 + 0x10a4);

                  }

                  if (2.0 <= *(float *)(iVar8 + 0x158)) {

                    fVar21 = *(float *)(DAT_00632ed8 + 0x10a8);

                  }

                  fVar21 = (fStack_1ec / fVar21) * 100.0 + *(float *)(iVar8 + 0x94);

                  *(float *)(iVar8 + 0x94) = fVar21;

                  if (99.0 <= fVar21) {

                    *(undefined4 *)(iVar8 + 0x94) = 0x42c80000;

                  }

                }

              }

              else {

                *(undefined4 *)(iVar8 + 0x94) = 0x42c80000;

              }

              if (*(int *)(iVar11 + 4) == 0xd7) {

                fVar21 = *(float *)(DAT_00632ed8 + 0x148c);

              }

              else if (*(int *)(iVar11 + 4) == 8) {

                fVar21 = *(float *)(DAT_00632ed8 + 0x1488);

              }

              else {

                fVar21 = *(float *)(DAT_00632ed8 + 0x10c0);

              }

              *(float *)(param_1 + 0x278) = *(float *)(param_1 + 0x278) - fVar21;

              if (*(float *)(param_1 + 0x278) < 0.0) {

                *(undefined4 *)(param_1 + 0x278) = 0;

              }

            }

            reaper_collect_food(param_1,iVar11,*(undefined4 *)(param_1 + 0x278),

                                *(undefined4 *)(iVar8 + 0x2c));

            *(undefined4 *)(iVar8 + 0xc) = 0;

          }

          else {

            if (uStack_19c != 0xbf) {

              if (uStack_19c != 0x60) {

                if (uStack_19c == 99) {

                  bVar25 = SBORROW4(iStack_1c4,0x10e3);

                  bVar24 = iStack_1c4 + -0x10e3 < 0;

                  goto LAB_004630d1;

                }

                if (uStack_19c == 0x7a) {

                  if ((0x167f < iStack_1c4) && (puVar2[3] != 0)) {

                    iVar8 = *(int *)(param_1 + 0x100);

                    iVar11 = *(int *)(iVar8 + 0xc);

                    if (iVar11 != 0) {

                      fStack_1ec = 2.0;

                      fStack_1e8 = 0.0;

                      iVar15 = dialog_level_is_base();

                      iVar14 = *(int *)(iVar11 + 4);

                      if (iVar15 == 0) {

                        if ((iVar14 == 0xb) || (iVar14 == 0x539)) {

                          uVar18 = 1;

                          uVar10 = uVar18;

                        }

                        else {

                          uVar18 = 0;

                          uVar10 = uVar18;

                        }

                      }

                      else {

                        if ((iVar14 == 0x2e6) || (iVar14 == 0x248)) {

                          fStack_1e8 = 1.4013e-45;

                          iVar14 = reaper_0052e4a0(param_1);

                          if (iVar14 != 0) {

                            comm_death_packet_build

                                      (param_1,0,*(int *)(param_1 + 0x18c) + -1,

                                       *(int *)(iVar11 + 0x18c) + -1,(float)DAT_00632f28,0x3f800000,

                                       0,0);

                            rpman_move(param_1,*(int *)(iVar11 + 0x18c) + -1);

                          }

                        }

                        uVar18 = ObjIsPlayer(iVar11);

                        uVar10 = (uint)(*(int *)(iVar11 + 4) == 0xb);

                        if (*(int *)(iVar11 + 4) == 0xb) {

                          uVar18 = 1;

                          fStack_1ec = 1.0;

                        }

                      }

                      if (3.0 <= *(float *)(iVar8 + 0x158)) {

                        if (uVar10 != 0) {

                          if ((1.0 <= *(float *)(iVar8 + 0x318)) || (*(int *)(iVar8 + 800) != 0)) {

                            if ((*(float *)(iVar8 + 0x31c) < 1.0) && (*(int *)(iVar8 + 0x324) == 0))

                            {

                              *(float *)(iVar8 + 0x31c) = *(float *)(iVar8 + 0x31c) + 1.0;

                            }

                          }

                          else {

                            *(float *)(iVar8 + 0x318) = *(float *)(iVar8 + 0x318) + 1.0;

                          }

                        }

                      }

                      else if (fStack_1e8 == 0.0) {

                        if (uVar18 != 0) {

                          fVar21 = *(float *)(DAT_00632ed8 + 0x10ac);

                          if (1.0 <= *(float *)(iVar8 + 0x158)) {

                            fVar21 = *(float *)(DAT_00632ed8 + 0x10a4);

                          }

                          if (2.0 <= *(float *)(iVar8 + 0x158)) {

                            fVar21 = *(float *)(DAT_00632ed8 + 0x10a8);

                          }

                          fVar21 = (fStack_1ec / fVar21) * 100.0 + *(float *)(iVar8 + 0x94);

                          *(float *)(iVar8 + 0x94) = fVar21;

                          if (99.0 <= fVar21) {

                            *(undefined4 *)(iVar8 + 0x94) = 0x42c80000;

                          }

                        }

                      }

                      else {

                        *(undefined4 *)(iVar8 + 0x94) = 0x42c80000;

                      }

                      if (*(int *)(iVar11 + 4) == 0xd7) {

                        fVar21 = *(float *)(DAT_00632ed8 + 0x148c);

                      }

                      else if (*(int *)(iVar11 + 4) == 8) {

                        fVar21 = *(float *)(DAT_00632ed8 + 0x1488);

                      }

                      else {

                        fVar21 = *(float *)(DAT_00632ed8 + 0x10c0);

                      }

                      *(float *)(param_1 + 0x278) = *(float *)(param_1 + 0x278) - fVar21;

                      if (*(float *)(param_1 + 0x278) < 0.0) {

                        *(undefined4 *)(param_1 + 0x278) = 0;

                      }

                    }

                    reaper_collect_food(param_1,iVar11,*(undefined4 *)(param_1 + 0x278),

                                        *(undefined4 *)(iVar8 + 0x2c));

                    *(undefined4 *)(iVar8 + 0xc) = 0;

                    goto LAB_004630e3;

                  }

                  if (0x80c < iStack_1c4) {

                    bVar25 = SBORROW4(iStack_1c4,0x1680);

                    bVar24 = iStack_1c4 + -0x1680 < 0;

                    goto LAB_004630d1;

                  }

                }

                else if (uStack_19c == 0x5f) {

                  if (iStack_1c4 < 0xaa0) {

                    if (800 < iStack_1c4) {

                      *puVar2 = *puVar2 | 0x300;

                    }

                  }

                  else if (puVar2[3] != 0) {

                    if (param_1 != DAT_00632a88) goto LAB_00463f45;

                    iVar8 = mecc_zoom_out__FRC10CntrlInputif_2();

                    if (iVar8 == 0) {

                      iVar8 = camera_is_sniper();

                      fVar23 = (float)puVar2[0xb];

                      fVar21 = *(float *)(DAT_00632ed8 + 0x3c0);

                      if (iVar8 == 0) {

                        uVar10 = puVar2[3];

                        uVar18 = puVar2[0x13];

                        fStack_1ec = fVar23;

                        fStack_1dc = fVar21;

                        if (uVar18 == 0) {

                          fStack_1d4 = *(float *)(param_1 + 0xa0) -

                                       *(float *)(param_1 + 0x29c) * 200.0;

                          fStack_1d0 = *(float *)(param_1 + 0xa4) -

                                       *(float *)(param_1 + 0x2ac) * 200.0;

                          fStack_1cc = *(float *)(param_1 + 0xa8) -

                                       *(float *)(param_1 + 700) * 200.0;

                          iVar8 = object_0046e830(param_1,uVar10);

                          if (iVar8 != 0) {

                            iVar11 = reaper_0052e4a0(param_1);

                            if (iVar11 != 0) {

                              fStack_164 = fStack_1d0;

                              fStack_158 = fStack_1ec;

                              fStack_168 = fStack_1d4;

                              fStack_160 = fStack_1cc;

                              fStack_154 = *(float *)(iVar8 + 0x188);

                              fStack_15c = fStack_1dc;

                              uStack_150 = *(undefined4 *)(uVar10 + 0x188);

                              uStack_14c = 0;

                              reaper_00530bd0(param_1,5,3,0,6,&fStack_168);

                            }

                            reaper_ospec_ptr48_set(iVar8,&LAB_0045afe0);

                            reaper_lock_user_3(param_1,uVar10,fStack_1ec,0);

                            *(int *)(uVar10 + 0x210) = iVar8;

                            *(undefined4 *)(uVar10 + 0x218) = 0xffffffff;

                            FUN_0050a610(iVar8 + 0xa0,&fStack_1d4);

                            fVar26 = (float10)powf();

                            fStack_1e8 = (float)(fVar26 / (float10)fStack_1dc);

                            reaper_ospec_init(iVar8,&fStack_1d4,0,fStack_1e8,0x3f400000);

                          }

                        }

                        else {

                          fStack_1c0 = (*(float *)(uVar18 + 0x288) + *(float *)(uVar18 + 0x27c)) *

                                       0.5;

                          fStack_1bc = (*(float *)(uVar18 + 0x28c) + *(float *)(uVar18 + 0x280)) *

                                       0.5;

                          fStack_1b8 = (*(float *)(uVar18 + 0x290) + *(float *)(uVar18 + 0x284)) *

                                       0.5;

                          fStack_1e8 = (float)object_0046e830(param_1,uVar10);

                          if (fStack_1e8 != 0.0) {

                            iVar8 = reaper_0052e4a0(param_1);

                            if (iVar8 != 0) {

                              fStack_168 = fStack_1c0;

                              uStack_14c = *(undefined4 *)(uVar18 + 0x188);

                              fStack_164 = fStack_1bc;

                              fStack_15c = fStack_1dc;

                              fStack_154 = *(float *)((int)fStack_1e8 + 0x188);

                              fStack_160 = fStack_1b8;

                              fStack_158 = fStack_1ec;

                              uStack_150 = *(undefined4 *)(uVar10 + 0x188);

                              reaper_00530bd0(param_1,5,3,0,6,&fStack_168);

                            }

                            reaper_ospec_ptr48_set(fStack_1e8,&LAB_0045afe0);

                            reaper_eat_finish(param_1,uVar10,&fStack_1c0,uVar18,fStack_1dc,

                                              fStack_1e8,fStack_1ec);

                            puVar2[3] = 0;

                            goto LAB_00463f5b;

                          }

                        }

LAB_00463f45:

                        puVar2[3] = 0;

                      }

                      else {

                        reaper_update_xhair_status__FP6OBJECT

                                  (param_1,puVar2[3],puVar2[0x13],

                                   *(undefined4 *)(DAT_00632ed8 + 0x3bc),fVar21,fVar23);

                        puVar2[3] = 0;

                      }

                    }

                    else {

                      reaper_update_xhair_status__FP6OBJECT

                                (param_1,puVar2[3],puVar2[0x13],

                                 *(undefined4 *)(DAT_00632ed8 + 0x3bc),

                                 *(undefined4 *)(DAT_00632ed8 + 0x3c0),puVar2[0xb]);

                      puVar2[3] = 0;

                    }

                  }

LAB_00463f5b:

                  if (uStack_1c8 == 0) goto LAB_004630ec;

                  goto LAB_00463f67;

                }

LAB_00463ff9:

                if ((uStack_1c8 == 0) && ((uStack_19c == 0x87 || (uStack_19c == 0x88)))) {

                  if ((param_1 == DAT_00632a88) && (uVar10 = puVar2[3], uVar10 != 0)) {

                    if (uStack_19c == 0x87) {

                      fStack_1e8 = 1.0762e-41;

                      iVar11 = 0x1e00;

                      iVar14 = 0x1a40;

                    }

                    else {

                      iVar11 = iStack_148;

                      iVar14 = iStack_148;

                      if (uStack_19c == 0x88) {

                        fStack_1e8 = 9.19252e-42;

                        iVar11 = 0x19a0;

                        iVar14 = 0x12c0;

                      }

                    }

                    if ((iStack_1a4 < iVar11) && (iVar14 <= iStack_1c4)) {

                      fStack_1f0 = (float)(iStack_1c4 - iStack_1a4);

                      uVar9 = __ftol();

                      fStack_1f0 = *(float *)(uVar10 + 200) + 90.0;

                      fStack_1ec = *(float *)(DAT_00632ed8 + 0x2b4);

                      fStack_1a0 = *(float *)(uVar10 + 200) - 90.0;

                      fStack_1dc = *(float *)(DAT_00632ed8 + 0x2b8);

                      *(undefined4 *)(DAT_00632ed8 + 0x2b4) = 0x3e99999a;

                      *(undefined4 *)(DAT_00632ed8 + 0x2b8) = 0x3f4ccccd;

                      blood_from_point(uVar10 + 0xa0,uVar9,uVar9,fStack_1a0,fStack_1f0,0x41200000,

                                       0x42340000,0,0x41a00000);

                      *(float *)(DAT_00632ed8 + 0x2b4) = fStack_1ec;

                      *(float *)(DAT_00632ed8 + 0x2b8) = fStack_1dc;

                    }

                    if ((iVar8 < (int)fStack_1e8) && ((int)fStack_1e8 <= iStack_1c4)) {

                      uVar10 = puVar2[0x17];

                      if (uVar10 != 0) {

                        if (*(int *)(uVar10 + 4) == 0x2e9) {

                          fStack_190 = *(float *)(param_1 + 0xa8);

                          fStack_198 = fStack_174 * 70.0 + *(float *)(param_1 + 0xa0);

                          fStack_194 = fStack_170 * 70.0 + *(float *)(param_1 + 0xa4);

                          if (uVar10 != 0) {

                            sound_play_obj(0x4ac,uVar10);

                            iVar8 = reaper_0052e4a0(param_1);

                            if (iVar8 != 0) {

                              fStack_1d4 = *(float *)(uVar10 + 0x188);

                              fStack_1d0 = 1.67595e-42;

                              reaper_00530bd0(param_1,0,2,0,0x13,&fStack_1d4);

                            }

                          }

                          sound_play_player(0x460,param_1);

                          iVar8 = reaper_0052e4a0(param_1);

                          if (iVar8 != 0) {

                            fStack_1f0 = 1.56945e-42;

                            reaper_00530bd0(param_1,0,1,0,0x11,&fStack_1f0);

                          }

                          kbos_offspring_process_2(puVar2[0x17],&fStack_198);

                          sound_play_player(0x460,param_1);

                          iVar8 = reaper_0052e4a0(param_1);

                          if (iVar8 != 0) {

                            fStack_1f0 = 1.56945e-42;

                            reaper_00530bd0(param_1,0,1,0,0x11,&fStack_1f0);

                          }

                        }

                        puVar2[0x17] = 0;

                      }

                      fStack_1e8 = (float)puVar2[0xb];

                      uVar10 = puVar2[3];

                      iVar8 = reaper_0052e4a0(param_1);

                      if (iVar8 != 0) {

                        fStack_1d0 = *(float *)(uVar10 + 0x188);

                        fStack_1d4 = fStack_1e8;

                        reaper_00530bd0(param_1,1,1,0,8,&fStack_1d4);

                      }

                      if (fStack_1e8 != 0.0) {

                        *(float *)(uVar10 + 0xc4) = *(float *)(uVar10 + 0xc4) / fStack_1e8;

                      }

                      *(undefined4 *)(uVar10 + 0x210) = 0;

                      if (*(int *)(uVar10 + 0x1e0) == 0x59) {

                        if (*(int *)(uVar10 + 0x218) < 2) {

                          FUN_00425850(uVar10);

                        }

                      }

                      else if (*(int *)(uVar10 + 0x1e0) == 0x12) {

                        smartie_release_to_bldg();

                      }

                      else {

                        iVar8 = ObjIsReaper(uVar10);

                        if (iVar8 != 0) {

                          *(undefined4 *)(uVar10 + 0xc4) =

                               *(undefined4 *)(*(int *)(uVar10 + 0x100) + 0xfac);

                        }

                      }

                      *(uint *)(uVar10 + 0xd8) = *(uint *)(uVar10 + 0xd8) & 0xfff7ffff | 0x10000000;

                      AttackObject__FP6OBJECTT0P3P3DT2fi(param_1,puVar2[3],0,0,0x461c4000,2);

                      puVar2[3] = 0;

                    }

                  }

                  goto LAB_004630ec;

                }

                goto LAB_00463f67;

              }

              if ((0xd1f < iStack_1c4) && (puVar2[3] != 0)) {

                iVar8 = *(int *)(param_1 + 0x100);

                iVar11 = *(int *)(iVar8 + 0xc);

                if (iVar11 != 0) {

                  fStack_1ec = 2.0;

                  fStack_1e8 = 0.0;

                  iVar15 = dialog_level_is_base();

                  iVar14 = *(int *)(iVar11 + 4);

                  if (iVar15 == 0) {

                    if ((iVar14 == 0xb) || (iVar14 == 0x539)) {

                      uVar18 = 1;

                      uVar10 = uVar18;

                    }

                    else {

                      uVar18 = 0;

                      uVar10 = uVar18;

                    }

                  }

                  else {

                    if ((iVar14 == 0x2e6) || (iVar14 == 0x248)) {

                      fStack_1e8 = 1.4013e-45;

                      iVar14 = reaper_0052e4a0(param_1);

                      if (iVar14 != 0) {

                        comm_death_packet_build

                                  (param_1,0,*(int *)(param_1 + 0x18c) + -1,

                                   *(int *)(iVar11 + 0x18c) + -1,(float)DAT_00632f28,0x3f800000,0,0)

                        ;

                        rpman_move(param_1,*(int *)(iVar11 + 0x18c) + -1);

                      }

                    }

                    uVar18 = ObjIsPlayer(iVar11);

                    uVar10 = (uint)(*(int *)(iVar11 + 4) == 0xb);

                    if (*(int *)(iVar11 + 4) == 0xb) {

                      uVar18 = 1;

                      fStack_1ec = 1.0;

                    }

                  }

                  if (3.0 <= *(float *)(iVar8 + 0x158)) {

                    if (uVar10 != 0) {

                      if ((1.0 <= *(float *)(iVar8 + 0x318)) || (*(int *)(iVar8 + 800) != 0)) {

                        if ((*(float *)(iVar8 + 0x31c) < 1.0) && (*(int *)(iVar8 + 0x324) == 0)) {

                          *(float *)(iVar8 + 0x31c) = *(float *)(iVar8 + 0x31c) + 1.0;

                        }

                      }

                      else {

                        *(float *)(iVar8 + 0x318) = *(float *)(iVar8 + 0x318) + 1.0;

                      }

                    }

                  }

                  else if (fStack_1e8 == 0.0) {

                    if (uVar18 != 0) {

                      fVar21 = *(float *)(DAT_00632ed8 + 0x10ac);

                      if (1.0 <= *(float *)(iVar8 + 0x158)) {

                        fVar21 = *(float *)(DAT_00632ed8 + 0x10a4);

                      }

                      if (2.0 <= *(float *)(iVar8 + 0x158)) {

                        fVar21 = *(float *)(DAT_00632ed8 + 0x10a8);

                      }

                      fVar21 = (fStack_1ec / fVar21) * 100.0 + *(float *)(iVar8 + 0x94);

                      *(float *)(iVar8 + 0x94) = fVar21;

                      if (99.0 <= fVar21) {

                        *(undefined4 *)(iVar8 + 0x94) = 0x42c80000;

                      }

                    }

                  }

                  else {

                    *(undefined4 *)(iVar8 + 0x94) = 0x42c80000;

                  }

                  if (*(int *)(iVar11 + 4) == 0xd7) {

                    fVar21 = *(float *)(DAT_00632ed8 + 0x148c);

                  }

                  else if (*(int *)(iVar11 + 4) == 8) {

                    fVar21 = *(float *)(DAT_00632ed8 + 0x1488);

                  }

                  else {

                    fVar21 = *(float *)(DAT_00632ed8 + 0x10c0);

                  }

                  *(float *)(param_1 + 0x278) = *(float *)(param_1 + 0x278) - fVar21;

                  if (*(float *)(param_1 + 0x278) < 0.0) {

                    *(undefined4 *)(param_1 + 0x278) = 0;

                  }

                }

                reaper_collect_food(param_1,iVar11,*(undefined4 *)(param_1 + 0x278),

                                    *(undefined4 *)(iVar8 + 0x2c));

                *(undefined4 *)(iVar8 + 0xc) = 0;

                goto LAB_004630e3;

              }

              if ((iStack_1c4 < 0x7d2) || (0xd1f < iStack_1c4)) {

                if (uStack_1c8 == 0) goto LAB_00463f67;

              }

              else if (uStack_1c8 == 0) goto LAB_004630e3;

              uStack_1f4 = 99;

              iVar8 = crt_rand_scaled(3);

              fVar21 = *(float *)(&DAT_0055b01c + iVar8 * 4);

              sound_play_player(fVar21,param_1);

              iVar8 = reaper_0052e4a0(param_1);

              if (iVar8 != 0) {

                fStack_1f0 = fVar21;

                reaper_00530bd0(param_1,0,1,0,0x11,&fStack_1f0);

              }

              goto LAB_004646d7;

            }

            if ((iStack_1c4 < 0xb03) || (puVar2[3] == 0)) {

              if (iStack_1c4 < 0x5a6) goto LAB_00463ff9;

              bVar25 = SBORROW4(iStack_1c4,0xb03);

              bVar24 = iStack_1c4 + -0xb03 < 0;

              goto LAB_004630d1;

            }

            iVar8 = *(int *)(param_1 + 0x100);

            iVar11 = *(int *)(iVar8 + 0xc);

            if (iVar11 != 0) {

              fStack_1ec = 2.0;

              fStack_1e8 = 0.0;

              iVar15 = dialog_level_is_base();

              iVar14 = *(int *)(iVar11 + 4);

              if (iVar15 == 0) {

                if ((iVar14 == 0xb) || (iVar14 == 0x539)) {

                  uVar18 = 1;

                  uVar10 = uVar18;

                }

                else {

                  uVar18 = 0;

                  uVar10 = uVar18;

                }

              }

              else {

                if ((iVar14 == 0x2e6) || (iVar14 == 0x248)) {

                  fStack_1e8 = 1.4013e-45;

                  iVar14 = reaper_0052e4a0(param_1);

                  if (iVar14 != 0) {

                    comm_death_packet_build

                              (param_1,0,*(int *)(param_1 + 0x18c) + -1,

                               *(int *)(iVar11 + 0x18c) + -1,(float)DAT_00632f28,0x3f800000,0,0);

                    rpman_move(param_1,*(int *)(iVar11 + 0x18c) + -1);

                  }

                }

                uVar18 = ObjIsPlayer(iVar11);

                uVar10 = (uint)(*(int *)(iVar11 + 4) == 0xb);

                if (*(int *)(iVar11 + 4) == 0xb) {

                  uVar18 = 1;

                  fStack_1ec = 1.0;

                }

              }

              if (3.0 <= *(float *)(iVar8 + 0x158)) {

                if (uVar10 != 0) {

                  if ((1.0 <= *(float *)(iVar8 + 0x318)) || (*(int *)(iVar8 + 800) != 0)) {

                    if ((*(float *)(iVar8 + 0x31c) < 1.0) && (*(int *)(iVar8 + 0x324) == 0)) {

                      *(float *)(iVar8 + 0x31c) = *(float *)(iVar8 + 0x31c) + 1.0;

                    }

                  }

                  else {

                    *(float *)(iVar8 + 0x318) = *(float *)(iVar8 + 0x318) + 1.0;

                  }

                }

              }

              else if (fStack_1e8 == 0.0) {

                if (uVar18 != 0) {

                  fVar21 = *(float *)(DAT_00632ed8 + 0x10ac);

                  if (1.0 <= *(float *)(iVar8 + 0x158)) {

                    fVar21 = *(float *)(DAT_00632ed8 + 0x10a4);

                  }

                  if (2.0 <= *(float *)(iVar8 + 0x158)) {

                    fVar21 = *(float *)(DAT_00632ed8 + 0x10a8);

                  }

                  fVar21 = (fStack_1ec / fVar21) * 100.0 + *(float *)(iVar8 + 0x94);

                  *(float *)(iVar8 + 0x94) = fVar21;

                  if (99.0 <= fVar21) {

                    *(undefined4 *)(iVar8 + 0x94) = 0x42c80000;

                  }

                }

              }

              else {

                *(undefined4 *)(iVar8 + 0x94) = 0x42c80000;

              }

              if (*(int *)(iVar11 + 4) == 0xd7) {

                fVar21 = *(float *)(DAT_00632ed8 + 0x148c);

              }

              else if (*(int *)(iVar11 + 4) == 8) {

                fVar21 = *(float *)(DAT_00632ed8 + 0x1488);

              }

              else {

                fVar21 = *(float *)(DAT_00632ed8 + 0x10c0);

              }

              *(float *)(param_1 + 0x278) = *(float *)(param_1 + 0x278) - fVar21;

              if (*(float *)(param_1 + 0x278) < 0.0) {

                *(undefined4 *)(param_1 + 0x278) = 0;

              }

            }

            reaper_collect_food(param_1,iVar11,*(undefined4 *)(param_1 + 0x278),

                                *(undefined4 *)(iVar8 + 0x2c));

            *(undefined4 *)(iVar8 + 0xc) = 0;

          }

LAB_004630e3:

          uVar10 = *puVar2 | 0x300;

          goto LAB_004630ea;

        }

        if ((0x10f7 < iStack_1c4) && (puVar2[3] != 0)) {

          iVar8 = *(int *)(param_1 + 0x100);

          iVar11 = *(int *)(iVar8 + 0xc);

          if (iVar11 != 0) {

            fStack_1ec = 2.0;

            fStack_1e8 = 0.0;

            iVar15 = dialog_level_is_base();

            iVar14 = *(int *)(iVar11 + 4);

            if (iVar15 == 0) {

              if ((iVar14 == 0xb) || (iVar14 == 0x539)) {

                uVar18 = 1;

                uVar10 = uVar18;

              }

              else {

                uVar18 = 0;

                uVar10 = uVar18;

              }

            }

            else {

              if ((iVar14 == 0x2e6) || (iVar14 == 0x248)) {

                fStack_1e8 = 1.4013e-45;

                iVar14 = reaper_0052e4a0(param_1);

                if (iVar14 != 0) {

                  comm_death_packet_build

                            (param_1,0,*(int *)(param_1 + 0x18c) + -1,*(int *)(iVar11 + 0x18c) + -1,

                             (float)DAT_00632f28,0x3f800000,0,0);

                  rpman_move(param_1,*(int *)(iVar11 + 0x18c) + -1);

                }

              }

              uVar18 = ObjIsPlayer(iVar11);

              uVar10 = (uint)(*(int *)(iVar11 + 4) == 0xb);

              if (*(int *)(iVar11 + 4) == 0xb) {

                uVar18 = 1;

                fStack_1ec = 1.0;

              }

            }

            if (3.0 <= *(float *)(iVar8 + 0x158)) {

              if (uVar10 != 0) {

                if ((1.0 <= *(float *)(iVar8 + 0x318)) || (*(int *)(iVar8 + 800) != 0)) {

                  if ((*(float *)(iVar8 + 0x31c) < 1.0) && (*(int *)(iVar8 + 0x324) == 0)) {

                    *(float *)(iVar8 + 0x31c) = *(float *)(iVar8 + 0x31c) + 1.0;

                  }

                }

                else {

                  *(float *)(iVar8 + 0x318) = *(float *)(iVar8 + 0x318) + 1.0;

                }

              }

            }

            else if (fStack_1e8 == 0.0) {

              if (uVar18 != 0) {

                fVar21 = *(float *)(DAT_00632ed8 + 0x10ac);

                if (1.0 <= *(float *)(iVar8 + 0x158)) {

                  fVar21 = *(float *)(DAT_00632ed8 + 0x10a4);

                }

                if (2.0 <= *(float *)(iVar8 + 0x158)) {

                  fVar21 = *(float *)(DAT_00632ed8 + 0x10a8);

                }

                fVar21 = (fStack_1ec / fVar21) * 100.0 + *(float *)(iVar8 + 0x94);

                *(float *)(iVar8 + 0x94) = fVar21;

                if (99.0 <= fVar21) {

                  *(undefined4 *)(iVar8 + 0x94) = 0x42c80000;

                }

              }

            }

            else {

              *(undefined4 *)(iVar8 + 0x94) = 0x42c80000;

            }

            if (*(int *)(iVar11 + 4) == 0xd7) {

              fVar21 = *(float *)(DAT_00632ed8 + 0x148c);

            }

            else if (*(int *)(iVar11 + 4) == 8) {

              fVar21 = *(float *)(DAT_00632ed8 + 0x1488);

            }

            else {

              fVar21 = *(float *)(DAT_00632ed8 + 0x10c0);

            }

            *(float *)(param_1 + 0x278) = *(float *)(param_1 + 0x278) - fVar21;

            if (*(float *)(param_1 + 0x278) < 0.0) {

              *(undefined4 *)(param_1 + 0x278) = 0;

            }

          }

          reaper_collect_food(param_1,iVar11,*(undefined4 *)(param_1 + 0x278),

                              *(undefined4 *)(iVar8 + 0x2c));

          *(undefined4 *)(iVar8 + 0xc) = 0;

          goto LAB_004630e3;

        }

        if (iStack_1c4 < 0xaec) goto LAB_00463ff9;

        bVar25 = SBORROW4(iStack_1c4,0x10f8);

        bVar24 = iStack_1c4 + -0x10f8 < 0;

LAB_004630d1:

        if (bVar25 == bVar24) goto LAB_00463ff9;

        if (uStack_1c8 == 0) goto LAB_004630e3;

LAB_00463f67:

        fVar21 = fStack_1b4;

        if ((int)fStack_1b4 < 0) {

LAB_004645bd:

          if (uStack_1c8 == 0) {

            bVar24 = (*(byte *)(param_1 + 0x30) & 1) == 0;

            goto LAB_004645c9;

          }

        }

        else {

          iVar8 = (int)fStack_1b4 * 0x1c;

          if ((*(uint *)(&DAT_0055a4e8 + iVar8) & 0x10f0) != 0) {

            if (puVar2[0x17] != 0) {

              iVar11 = fx_rect_interp(param_1,puVar2[0x17],iStack_1a4,iStack_1c4,

                                      &DAT_0055a4d8 + (int)fStack_1b4 * 7,puVar2 + 0x1e,

                                      puVar2 + 0x18,puVar2[0x1f]);

              if (iVar11 != 0) {

                fStack_1e8 = (float)puVar2[0x77];

                if ((*(uint *)(&DAT_0055a4e8 + iVar8) & 0x1000) == 0) {

                  if ((*(uint *)(&DAT_0055a4e8 + iVar8) & 0xc0) != 0) {

                    fStack_1e8 = (float)puVar2[0x78];

                  }

                }

                else {

                  fStack_1e8 = (float)puVar2[0x79];

                  reaper_spell_user(param_1,puVar2[0x17],0);

                }

                AttackObject__FP6OBJECTT0P3P3DT2fi

                          (param_1,puVar2[0x17],puVar2 + 0x18,param_1 + 0xa0,fStack_1e8,0);

                puVar2[0x17] = 0;

              }

            }

            if (uStack_1c8 == 0) goto LAB_004630ec;

          }

          uVar10 = *(uint *)(&DAT_0055a4e8 + iVar8);

          if ((uVar10 & 0x801) != 0) {

            if (((puVar2[3] == 0) && (puVar2[0x17] != 0)) &&

               (iVar11 = fx_rect_interp(param_1,puVar2[0x17],iStack_1a4,iStack_1c4,

                                        &DAT_0055a4d8 + (int)fVar21 * 7,puVar2 + 0x1e,puVar2 + 0x18,

                                        puVar2[0x1f]), iVar11 != 0)) {

              uVar10 = puVar2[0x17];

              if (*(int *)(uVar10 + 4) == 0x4af) {

                *puVar2 = *puVar2 | 0x80000;

                reaper_lock_short_6(param_1,uVar10);

              }

              else if ((*(int *)(uVar10 + 0x1e0) != 0x17) ||

                      (((((iVar11 = *(int *)(uVar10 + 0xe4), iVar11 != 0x1f && (iVar11 != 0x22)) &&

                         ((iVar11 != 0x24 && ((iVar11 != 0x2c && (iVar11 != 0x20)))))) &&

                        (iVar11 != 0x2d)) && (iVar11 != 0x3d)))) {

                puVar2[3] = uVar10;

                fVar26 = (float10)FUN_0045b610(param_1,uVar10,puVar2[0x56]);

                puVar2[0xb] = (uint)(float)fVar26;

                if ((*(int *)(uVar10 + 0x1e0) == 0x33) && (*(int *)(uVar10 + 0x210) != 0)) {

                  *(undefined4 *)(uVar10 + 0xe8) = 2;

                }

                iVar11 = dialog_level_is_base();

                if (iVar11 != 0) {

                  iVar11 = *(int *)(puVar2[3] + 4);

                  if ((iVar11 == 0x2e6) || (iVar11 == 0x248)) {

                    iVar11 = base_which_team(puVar2[3]);

                    pcVar16 = s_Borjoyzee_0055b3c0;

                    if (iVar11 != 1) {

                      pcVar16 = &DAT_0055b3bc;

                    }

                    uVar9 = comm_player_name4(param_1,pcVar16);

                    uVar9 = TextGetPtrRandom(s_MPChFlagTaken_0055b3ac,uVar9);

                    crt_sprintf(auStack_100,uVar9);

                    comm_audio_volume_user(auStack_100,1,0,0);

                  }

                }

                reaper_lock_short_5(param_1,puVar2[3],puVar2[0xb],3,1);

              }

              puVar2[0x17] = 0;

            }

            if (uStack_1c8 != 0) {

              uVar10 = *(uint *)(&DAT_0055a4e8 + iVar8);

              if ((uVar10 & 1) == 0) goto LAB_00464543;

              uStack_1ac = (-(uint)(puVar2[3] != 0) & 9) + 9 + (int)fStack_1b4;

LAB_0046452d:

              uStack_1f4 = (&DAT_0055a4d8)[uStack_1ac * 7];

            }

            goto LAB_004630ec;

          }

LAB_00464543:

          if ((uVar10 & 4) == 0) goto LAB_004645bd;

          if (((puVar2[2] == 0) && (puVar2[0x17] != 0)) &&

             (iVar8 = fx_rect_interp(param_1,puVar2[0x17],iStack_1a4,iStack_1c4,

                                     &DAT_0055a4d8 + (int)fVar21 * 7,puVar2 + 0x1e,puVar2 + 0x18,

                                     puVar2[0x1f]), iVar8 != 0)) {

            uVar10 = puVar2[0x17];

            puVar2[2] = uVar10;

            fVar26 = (float10)FUN_0045b610(param_1,uVar10,puVar2[0x56]);

            fStack_1e8 = (float)fVar26;

            puVar2[10] = (uint)(float)fVar26;

            reaper_lock_short_5(param_1,uVar10,fStack_1e8,2,1);

            puVar2[0x17] = 0;

          }

          bVar24 = uStack_1c8 == 0;

LAB_004645c9:

          if (bVar24) goto LAB_004630ec;

        }

        if (((uint)fStack_1a0 & 4) != 0) {

          uStack_1b0 = 5;

          uStack_180 = 3;

          uStack_1d8 = 0x21;

          if (puVar2[3] == 0) {

            if (puVar2[2] == 0) {

              if ((float)puVar2[1] == 0.0) {

                uStack_1f4 = 0x26;

              }

              else {

                uStack_1f4 = 0x6b;

              }

            }

            else {

              uStack_1f4 = 0x80;

            }

          }

          else {

            uStack_1f4 = 0x6a;

          }

          goto LAB_004630f8;

        }

        uStack_1b0 = 1;

        if (puVar2[3] != 0) {

          uStack_1ac = 0x34;

          uStack_1f4 = DAT_0055aa88;

          uStack_1d8 = 0x21;

          goto LAB_004630ec;

        }

        if (puVar2[2] != 0) {

          uStack_1f4 = 0x7d;

          uStack_1d8 = 0x21;

          goto LAB_004630f8;

        }

        if ((float)puVar2[1] == 0.0) {

          if (uStack_19c == 0x68) {

            if (uStack_1c8 != 0) {

              uStack_1f4 = 0x67;

              goto LAB_004646d7;

            }

          }

          else if (uStack_19c == 0x67) {

            if (uStack_1c8 != 0) {

code_r0x0046488b:

              if ((iStack_188 != 2) || (uStack_1c8 != 0)) {

                uStack_1f4 = 1;

                uStack_1d8 = 0x21;

                goto LAB_004630f8;

              }

            }

          }

          else if (uStack_19c == 1) {

            if (uStack_1c8 != 0) {

              iVar8 = crt_rand_scaled(100);

              if (iVar8 < 0x33) {

                iVar8 = crt_rand_scaled(100);

                if (iVar8 < 0x1a) {

                  iVar8 = crt_rand_scaled(100);

                  if (iVar8 < 0x5b) goto LAB_004630ec;

                  uStack_1f4 = 0xb1;

                }

                else {

                  fVar26 = (float10)func_0x0045c310(param_1 + 0xa0,&fStack_174,0x41200000,10);

                  if ((float10)-40.0 <= fVar26 * (float10)0.01) goto LAB_004630ec;

                  fStack_1a8 = 0.5;

                  uStack_1f4 = 0x97;

                }

              }

              else {

                uStack_1b0 = 2;

                uVar9 = crt_rand_scaled(5);

                switch(uVar9) {

                case 0:

                  sound_player_voice(0x406,param_1);

                  uStack_1f4 = 0;

                  break;

                case 1:

                  sound_player_voice(0x470,param_1);

                  uStack_1f4 = 0xad;

                  break;

                case 2:

                  sound_player_voice(0x470,param_1);

                  uStack_1f4 = 0xae;

                  break;

                case 3:

                  sound_player_voice(0x478,param_1);

                  uStack_1f4 = 0xaf;

                  break;

                case 4:

                  sound_player_voice(0x489,param_1);

                  uStack_1f4 = 0xb0;

                  break;

                default:

                  goto LAB_004630ec;

                }

              }

              goto LAB_004646d7;

            }

          }

          else if (uStack_19c == 0x97) {

            if (uStack_1c8 != 0) {

              uStack_1d8 = 0x21;

              if (fStack_1f0 == 0.0) {

                uStack_1f4 = 0x98;

              }

              else {

                uStack_1f4 = 1;

              }

              goto LAB_004646d7;

            }

          }

          else if (uStack_19c == 0x98) {

            if ((uStack_1c8 != 0) && (iVar8 = crt_rand_scaled(100), 0x32 < iVar8)) {

              uStack_1f4 = 0x97;

              uStack_1d8 = 0x30;

              goto LAB_004646d7;

            }

          }

          else if (uStack_19c == 0xb1) {

            if (uStack_1c8 != 0) {

              uStack_1d8 = 0x21;

              if (fStack_1f0 == 0.0) {

                uStack_1f4 = 0xb2;

              }

              else {

                uStack_1f4 = 1;

              }

              goto LAB_004646d7;

            }

          }

          else if (uStack_19c == 0xb2) {

            if (uStack_1c8 != 0) {

              iVar8 = crt_rand_scaled(100);

              if (iVar8 < 0x4c) {

                iVar8 = crt_rand_scaled(100);

                if (iVar8 < 0x1a) goto LAB_004630ec;

                uStack_1f4 = 0xb1;

                uStack_1d8 = 0x30;

              }

              else {

                uStack_1f4 = 0xb3;

                sound_player_voice(0x471,param_1);

              }

              goto LAB_004646d7;

            }

          }

          else {

            if (uStack_19c != 0xb3) goto code_r0x0046488b;

            if (uStack_1c8 != 0) {

              uStack_1f4 = 0xb2;

              goto code_r0x004646cf;

            }

          }

          goto LAB_004630ec;

        }

        if (uStack_19c != 1) {

          if (uStack_19c == 0x66) {

            if (uStack_1c8 != 0) {

              uStack_1f4 = 0x68;

code_r0x004646cf:

              uStack_1d8 = 0x21;

              goto LAB_004646d7;

            }

          }

          else if (uStack_19c == 0x68) {

            if ((uStack_1c8 != 0) && (iVar8 = crt_rand_scaled(100), 0x32 < iVar8)) {

              uStack_1f4 = 0xb4;

              goto LAB_004646d7;

            }

          }

          else if ((uStack_19c != 0xb4) || (uStack_1c8 != 0)) {

            uStack_1f4 = 0x68;

            uStack_1d8 = 0x21;

            goto LAB_004630f8;

          }

          goto LAB_004630ec;

        }

        uStack_1f4 = 0x66;

        goto LAB_004646d7;

      }

      fVar23 = 0.0;

      fVar21 = 0.0;

      fStack_1dc = 0.0;

      puVar2[1] = 0x41200000;

      if (((-1 < (int)fStack_1b4) &&

          ((*(uint *)(&DAT_0055a4e8 + (int)fStack_1b4 * 0x1c) & 0x14f0) != 0)) ||

         (fStack_1ec < 0.33)) goto LAB_00461d6c;

      iVar8 = ai_target_classify(param_1,puVar2[0x14],2);

      if (iVar8 == 0) {

        fStack_1b4 = 0.0;

      }

      else {

        uVar10 = puVar2[0x15];

        fVar3 = *(float *)(param_1 + 0xa0) - *(float *)(uVar10 + 0xa0);

        fVar21 = (float)puVar2[0x14];

        fVar5 = *(float *)(param_1 + 0xa4) - *(float *)(uVar10 + 0xa4);

        fVar4 = *(float *)(param_1 + 0xa8) - *(float *)(uVar10 + 0xa8);

        fStack_1b4 = fVar4 * fVar4 + fVar5 * fVar5 + fVar3 * fVar3;

      }

      if (0.66 <= fStack_1ec) {

        if (1.0 <= fStack_1ec) {

          iVar8 = crt_rand_scaled(2);

          if ((*puVar2 & 8) == 0) {

            bVar24 = fStack_1b4 < (float)puVar2[100] * (float)puVar2[100];

            if (iVar8 == 0) {

              if (bVar24) {

                fVar23 = fVar21;

                fStack_1dc = fVar21;

              }

              uStack_1ac = 0x28;

            }

            else {

              if (bVar24) {

                fVar23 = fVar21;

                fStack_1dc = fVar21;

              }

              uStack_1ac = 0x29;

            }

          }

          else if (((fVar21 != 0.0) && ((float)puVar2[0x65] * (float)puVar2[0x65] <= fStack_1b4)) ||

                  (iVar8 != 0)) {

            if (fStack_1b4 < (float)puVar2[100] * (float)puVar2[100]) {

              fVar23 = fVar21;

              fStack_1dc = fVar21;

            }

            uStack_1ac = 0x2a;

          }

          else {

            if (fStack_1b4 < (float)puVar2[0x65] * (float)puVar2[0x65]) {

              fVar23 = fVar21;

              fStack_1dc = fVar21;

            }

            uStack_1ac = 0x2b;

          }

          if (fVar23 != 0.0) {

            *(uint *)((int)fVar23 + 0x1ccU) = *(uint *)((int)fVar23 + 0x1ccU) | 1;

          }

          puVar2[0x50] = (uint)((float)puVar2[0x50] + 1.5);

        }

        else if ((*puVar2 & 8) == 0) {

          if (fStack_1b4 < (float)puVar2[99] * (float)puVar2[99]) {

            fStack_1dc = fVar21;

          }

          uStack_1ac = 0x3b;

        }

        else {

          if (fStack_1b4 < (float)puVar2[0x61] * (float)puVar2[0x61]) {

            fStack_1dc = fVar21;

          }

          uStack_1ac = 0x39;

        }

      }

      else if ((*puVar2 & 8) == 0) {

        if (fStack_1b4 < (float)puVar2[0x62] * (float)puVar2[0x62]) {

          fStack_1dc = fVar21;

        }

        uStack_1ac = 0x3a;

      }

      else {

        if (fStack_1b4 < (float)puVar2[0x60] * (float)puVar2[0x60]) {

          fStack_1dc = fVar21;

        }

        uStack_1ac = 0x38;

      }

      puVar2[0x18] = *(uint *)(param_1 + 0xa0);

      puVar2[0x19] = *(uint *)(param_1 + 0xa4);

      puVar2[0x1a] = *(uint *)(param_1 + 0xa8);

      puVar2[0x1b] = *(uint *)(param_1 + 0xa0);

      puVar2[0x1c] = *(uint *)(param_1 + 0xa4);

      uVar10 = *(uint *)(param_1 + 0xa8);

      puVar2[0x4d] = (uint)((float)puVar2[0x4d] - fStack_1ec);

      puVar2[0x50] = (uint)((float)puVar2[0x50] + 1.5);

      puVar2[0x1d] = uVar10;

      puVar2[0x4f] = 0;

      puVar2[0x4e] = 0;

      puVar2[0x1f] = 0;

      puVar2[0x1e] = 0xbf800000;

      puVar2[0x17] = (uint)fStack_1dc;

      uStack_1f4 = (&DAT_0055a4d8)[uStack_1ac * 7];

      uStack_1b0 = 6;

      uVar10 = *puVar2 | 0x100000;

LAB_004630ea:

      *puVar2 = uVar10;

      goto LAB_004630ec;

    }

    if ((uStack_1c8 == 0) || (*(float *)(param_1 + 0xa8) - *(float *)(param_1 + 0x140) <= 25.0))

    goto LAB_004630ec;

    uStack_1f4 = 0x9a;

    uStack_1d8 = 0x21;

    uStack_180 = 0;

LAB_00463114:

    switch(uStack_180) {

    default:

      fStack_184 = 200.0;

      break;

    case 1:

      break;

    case 2:

      fStack_184 = -40.0;

      break;

    case 3:

      fStack_184 = -90.0;

    }

  }

  uVar10 = ~uStack_178 & uStack_1d8;

  uVar9 = reaper_0052e4a0(param_1);

  reaper_lock_short_4(param_1,uStack_1f4,uVar10,uStack_180,fStack_184 * *(float *)(param_1 + 0xc4),

                      fStack_1a8,uVar9);

  *(uint *)(param_1 + 0xe4) = uStack_1b0;

  puVar2[0x24] = uStack_1ac;

  if ((char)uVar10 < '\0') {

    *(float *)(param_1 + 0x14) = fStack_1e8;

  }

  object_animate_process(param_1,0);

  iVar8 = iStack_148;

  iStack_1a4 = AddHud__4cHudP8cHudIcon_4(iStack_148,*(undefined4 *)(param_1 + 0x18));

  iStack_1c4 = AddHud__4cHudP8cHudIcon_4(iVar8,*(undefined4 *)(param_1 + 0x14));

  puVar2[0x38] = 0;

LAB_0046477f:

  if (((puVar2[0x22] != 0) && (puVar2[0x21] != 0xfe)) && (puVar2[0x21] != *(uint *)(param_1 + 0x10))

     ) {

    object_destroy(puVar2[0x22]);

    puVar2[0x22] = 0;

    puVar2[0x21] = 0xfe;

  }

  if (param_1 == DAT_00632a88) {

    uVar9 = 0;

    if (-1 < (int)puVar2[0x24]) {

      uVar9 = *(undefined4 *)(&DAT_0055a4ec + puVar2[0x24] * 0x1c);

    }

    camera_ref_anode(param_1,iStack_1a4,iStack_1c4,uVar9);

    if ((puVar2[0x14] == 0) || (*(int *)(puVar2[0x14] + 4) != 0x2e9)) {

      bVar24 = false;

    }

    else {

      bVar24 = true;

    }

    FUN_004fa780(0x2d,3.0 <= (float)puVar2[0x57]);

    FUN_004fa780(0x2e,3.0 <= (float)puVar2[0x57]);

    FUN_004fa780(0x2f,3.0 <= (float)puVar2[0x57]);

    FUN_004fa780(0x30e,*puVar2 & 0x80000);

    if (((float)puVar2[0x57] < 3.0) || (puVar2[200] != 0)) {

      uVar9 = 0;

    }

    else {

      uVar9 = 1;

    }

    FUN_004fa780(0x317,uVar9);

    if (((float)puVar2[0x57] < 3.0) || (puVar2[200] != 0)) {

      uVar9 = 0;

    }

    else {

      uVar9 = 1;

    }

    FUN_004fa780(0x318,uVar9);

    if (((float)puVar2[0x57] < 3.0) || (puVar2[0xc9] != 0)) {

      uVar9 = 0;

    }

    else {

      uVar9 = 1;

    }

    FUN_004fa780(0x319,uVar9);

    if (((float)puVar2[0x57] < 3.0) || (puVar2[0xc9] != 0)) {

      uVar9 = 0;

    }

    else {

      uVar9 = 1;

    }

    FUN_004fa780(0x31a,uVar9);

    FUN_004fa780(0x31b,puVar2[200] != 0);

    FUN_004fa780(0x31c,puVar2[200] != 0);

    FUN_004fa780(0x31d,puVar2[0xc9] != 0);

    FUN_004fa780(0x31e,puVar2[0xc9] != 0);

    FUN_004fa780(0x2d3,(float)puVar2[0x57] < 3.0);

    FUN_004fa780(0x2d4,(float)puVar2[0x57] < 3.0);

    if (((puVar2[3] == 0) || (!bVar24)) || ((*(byte *)(param_1 + 0x20c) & 2) == 0)) {

      uVar9 = 0;

    }

    else {

      uVar9 = 1;

    }

    FUN_004fa780(0x85,uVar9);

    if (((*puVar2 & 0x800) == 0) || ((*puVar2 & 0x4000) == 0)) {

      uVar9 = 0;

    }

    else {

      uVar9 = 1;

    }

    FUN_004fa780(200,uVar9);

    if (((*puVar2 & 0x800) == 0) || ((*puVar2 & 0x1000) == 0)) {

      uVar9 = 0;

    }

    else {

      uVar9 = 1;

    }

    FUN_004fa780(0xc9,uVar9);

    if ((((~*puVar2 & 0x800) == 0) || (!bVar24)) || ((*(byte *)(param_1 + 0x20c) & 2) == 0)) {

      uVar9 = 0;

    }

    else {

      uVar9 = 1;

    }

    FUN_004fa780(0x82,uVar9);

    FUN_004fa780(0x83,0);

    if ((puVar2[0x14] == 0) || (bVar24)) {

      uVar9 = 1;

    }

    else {

      uVar9 = 0;

    }

    FUN_004fa780(0x13,uVar9);

    if ((*puVar2 & 0x800) == 0) {

      if ((puVar2[0x14] == 0) || (bVar24)) {

        uVar9 = 0;

      }

      else {

        uVar9 = 1;

      }

    }

    else {

      uVar9 = ai_target_classify(param_1,puVar2[0x14],2);

    }

    FUN_004fa780(0x35,uVar9);

  }

  uVar10 = puVar2[200];

  if ((uVar10 != 0) && (*(float *)(uVar10 + 0x1c0) <= *(float *)(uVar10 + 0x278))) {

    sound_player_voice(0x45b,param_1);

    puVar2[200] = 0;

  }

  uVar10 = puVar2[0xc9];

  if ((uVar10 != 0) && (*(float *)(uVar10 + 0x1c0) <= *(float *)(uVar10 + 0x278))) {

    sound_player_voice(0x45b,param_1);

    puVar2[0xc9] = 0;

  }

  if ((iStack_188 == 0xc) || (iStack_188 == 0xd)) {

    *puVar2 = *puVar2 | 0x300;

  }

  FUN_00465070(param_1,fStack_17c);

  return;

}

