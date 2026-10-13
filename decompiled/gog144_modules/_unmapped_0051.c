/* Giants 1.449 — module _unmapped_0051
 * 186 functions (139 named) — decompiled, names from PS2 symbols
 * Original source: C:\Giants\source\_unmapped_0051.c(pp) (assert-string evidence)
 */

/* ===== FUN_005108f0 @ 0x005108F0 ===== */
undefined4 FUN_005108f0(int param_1)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int *piVar6;

  int iVar7;

  

  iVar4 = param_1;

  iVar2 = *(int *)(param_1 + 0x274);

  iVar7 = 0;

  if (iVar2 == 0) {

    iVar5 = 0;

  }

  else {

    iVar5 = *(int *)(iVar2 + 0x100);

  }

  piVar1 = (int *)(param_1 + 0x100);

  if (((iVar5 != 0) &&

      (iVar5 = *(int *)(*(int *)(iVar5 + 0x30) + *(int *)(*piVar1 + 0x98) * 4),

      *(float *)(iVar5 + 0xfc) != 0.0)) &&

     (param_1 = 0, piVar6 = DAT_00632d90, DAT_00632d90 != (int *)0x0)) {

    do {

      iVar3 = piVar6[3];

      if (((*(int *)(iVar3 + 0x274) == iVar2) && (iVar3 != iVar4)) &&

         ((iVar7 = iVar7 + 1, *(int *)(*(int *)(iVar3 + 0x100) + 0x9c) < *(int *)(*piVar1 + 0x9c) &&

          (*(int *)(iVar3 + 0x210) == 0)))) {

        param_1 = param_1 + 1;

      }

      piVar6 = (int *)*piVar6;

    } while (piVar6 != (int *)0x0);

    if ((iVar7 != 0) && ((1.0 - (float)param_1 / (float)iVar7) * 100.0 < *(float *)(iVar5 + 0xfc)))

    {

      return 1;

    }

  }

  return 0;

}

/* ===== evilreaper_gib__FP6OBJECTT0 @ 0x00510F50 ===== */
/* PS2 candidate: evilreaper_gib__FP6OBJECTT0 (conf 0.382) */



void evilreaper_gib__FP6OBJECTT0(float param_1,float param_2)



{

  float fVar1;

  int iVar2;

  int iVar3;

  float10 fVar4;

  undefined4 uVar5;

  

  fVar1 = param_1;

  iVar3 = *(int *)((int)param_1 + 0x100);

  iVar2 = fx_create(param_1);

  if (iVar2 != 0) {

    if (param_2 == 0.0) {

      fVar4 = (float10)rndfloatrange(0,0x43b40000);

    }

    else {

      fVar4 = (float10)atand2pos(*(float *)((int)param_2 + 0xbc) - *(float *)((int)param_2 + 0xa4),

                                 *(float *)((int)param_2 + 0xb8) - *(float *)((int)param_2 + 0xa0));

      fVar4 = fVar4 - (float10)90.0;

    }

    param_2 = (float)fVar4;

    iVar2 = reaper_0052e4a0(fVar1);

    if (iVar2 != 0) {

      param_1 = param_2;

      reaper_00530bd0(fVar1,1,0,0,0xd,&param_1);

    }

  }

  iVar2 = (int)fVar1 + 0xa0;

  fx_get_free_effect__Fv();

  if (*(int *)(iVar3 + 0x50) == 0x3f800000) {

    iVar3 = crt_rand_scaled(100);

    if (iVar3 < 0x32) {

      uVar5 = 0x607;

    }

    else {

      uVar5 = 0x608;

    }

  }

  else {

    iVar3 = crt_rand_scaled(100);

    if (iVar3 < 0x32) {

      uVar5 = 0x60b;

    }

    else {

      uVar5 = 0x60c;

    }

  }

  sound_play_3dpos(uVar5,iVar2);

  iVar3 = crt_rand_scaled(100);

  if (0x31 < iVar3) {

    sound_play_3dpos(0x550,iVar2);

    return;

  }

  sound_play_3dpos(0x54f,iVar2);

  return;

}

/* ===== herdgen_marker_user @ 0x00511410 ===== */
/* PS2 candidate: vimp_logic (conf 0.374) */



void herdgen_marker_user(float param_1,float *param_2,undefined4 param_3)



{

  undefined4 *puVar1;

  int iVar2;

  int iVar3;

  float fVar4;

  int iVar5;

  int iVar6;

  float10 fVar7;

  float local_34;

  float local_30;

  float local_2c;

  undefined4 local_28;

  undefined4 local_24;

  undefined4 local_20;

  undefined1 local_1c [16];

  undefined4 local_c;

  

  iVar5 = (int)param_1;

  iVar2 = *(int *)((int)param_1 + 0x100);

  iVar6 = fx_create(param_1);

  if (iVar6 == 0) {

    *(undefined4 *)(iVar2 + 0xb4) = param_3;

    goto LAB_005116a3;

  }

  iVar6 = *(int *)(*(int *)(iVar5 + 0x274) + 0x100);

  fVar7 = (float10)rndfloatrange(*(undefined4 *)(DAT_00632ed8 + 0x978),

                                 *(undefined4 *)(DAT_00632ed8 + 0x97c));

  param_1 = (float)fVar7;

  local_28 = *(undefined4 *)(iVar5 + 0x298);

  local_24 = *(undefined4 *)(iVar5 + 0x2a8);

  local_20 = *(undefined4 *)(iVar5 + 0x2b8);

  normalize__FPfN20(&local_28,&local_24,&local_20);

  local_34 = *(float *)(iVar5 + 0xa0) - *param_2;

  local_30 = *(float *)(iVar5 + 0xa4) - param_2[1];

  local_2c = *(float *)(iVar5 + 0xa8) - param_2[2];

  normalize__FPfN20(&local_34,&local_30,&local_2c);

  fVar7 = (float10)Dot__FP3P3DT0(&local_28,&local_34);

  if ((float10)0.0 <= fVar7) {

    param_1 = param_1 + *(float *)(iVar5 + 200);

  }

  else {

    param_1 = *(float *)(iVar5 + 200) - param_1;

  }

  *(float *)(iVar2 + 0xb4) = param_1;

  if (*(float *)(iVar2 + 0xb4) <= 360.0) {

    if (*(float *)(iVar2 + 0xb4) < 0.0) {

      fVar4 = *(float *)(iVar2 + 0xb4) + 360.0;

      goto LAB_00511547;

    }

  }

  else {

    fVar4 = *(float *)(iVar2 + 0xb4) - 360.0;

LAB_00511547:

    *(float *)(iVar2 + 0xb4) = fVar4;

  }

  iVar6 = *(int *)(iVar6 + 0x30);

  param_1 = *(float *)(*(int *)(iVar6 + *(int *)(iVar2 + 0x98) * 4) + 0xf8);

  fVar7 = (float10)distancesq2d__FP3P3DT0

                             (*(int *)(iVar6 + *(int *)(iVar2 + 0x98) * 4) + 0xa0,iVar5 + 0xa0);

  if (fVar7 <= (float10)param_1 * (float10)param_1) {

    if (*(int *)(iVar2 + 0xa0) == 0) {

      *(int *)(iVar2 + 0x9c) = *(int *)(iVar2 + 0x9c) + 1;

    }

    else {

      *(undefined4 *)(iVar2 + 0xa0) = 0;

    }

    herdgen_get_next_marker(*(undefined4 *)(iVar5 + 0x274),(int *)(iVar2 + 0x98));

  }

  vimp_get_wanted_loc__FP6OBJECT(iVar5);

  iVar6 = *(int *)(iVar5 + 0x100);

  if (*(int *)(iVar6 + 0xa8) != 0) {

    puVar1 = (undefined4 *)(iVar6 + 0x40);

    FUN_00414690(puVar1,local_1c);

    crt_euler_to_quat(*(int *)(iVar6 + 0xa8) + 0x294,0,0,0,

                      *(undefined4 *)(*(int *)(iVar6 + 0xa8) + 0xc4));

    iVar3 = *(int *)(iVar6 + 0xa8);

    *(undefined4 *)(iVar3 + 0xa0) = *puVar1;

    *(undefined4 *)(iVar3 + 0xa4) = *(undefined4 *)(iVar6 + 0x44);

    *(undefined4 *)(iVar3 + 0xa8) = *(undefined4 *)(iVar6 + 0x48);

    *(undefined4 *)(*(int *)(iVar6 + 0xa8) + 0xa8) = local_c;

    *(undefined4 *)(*(int *)(iVar6 + 0xa8) + 0x2a4) = *puVar1;

    *(undefined4 *)(*(int *)(iVar6 + 0xa8) + 0x2b4) = *(undefined4 *)(iVar6 + 0x44);

    *(undefined4 *)(*(int *)(iVar6 + 0xa8) + 0x2c4) = local_c;

  }

  iVar6 = reaper_0052e4a0(iVar5);

  if (iVar6 != 0) {

    param_1 = *(float *)(iVar2 + 0xb4);

    comm_chat_send_2(iVar5,1,0,0,8,&param_1);

  }

LAB_005116a3:

  *(undefined4 *)(iVar2 + 0x74) = 2;

  *(undefined4 *)(iVar5 + 0xe4) = 1;

  *(uint *)(iVar5 + 0x1c8) = *(uint *)(iVar5 + 0x1c8) | 0x400;

  *(undefined4 *)(iVar2 + 0xb8) = 0;

  *(undefined4 *)(iVar2 + 0xb0) = 1;

  return;

}

/* ===== vimp_animselect @ 0x005116E0 ===== */
/* PS2 candidate: vimp_animselect (conf 0.455) */



void vimp_animselect(int param_1)



{

  float fVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  float10 fVar5;

  undefined4 local_8;

  undefined4 local_4;

  

  iVar2 = *(int *)(param_1 + 0x100);

  if (*(int *)(param_1 + 0x210) == 0) {

    if (*(int *)(param_1 + 0xd8) < 0) {

      anim_select_user(param_1,0x32);

      return;

    }

    iVar3 = *(int *)(param_1 + 0xe4);

    if (iVar3 == 9) {

      if (*(int *)(param_1 + 0x10) != 0x49) {

        objanim_select_anim(param_1,0x49);

        return;

      }

      if ((*(byte *)(param_1 + 0x30) & 2) != 0) {

        object_destroy(param_1);

        return;

      }

    }

    else {

      if (iVar3 == 5) {

        objanim_select_anim(param_1,0x34);

        return;

      }

      if (iVar3 == 4) {

        iVar2 = *(int *)(param_1 + 0x10);

        if (((iVar2 != 0x20) && (iVar2 != 0x45)) && (iVar2 != 0x46)) {

          iVar2 = crt_rand_scaled(100);

          if (iVar2 < 0x21) {

            objanim_select_anim(param_1,0x20);

            return;

          }

          if (iVar2 < 0x42) {

            objanim_select_anim(param_1,0x45);

            return;

          }

          objanim_select_anim(param_1,0x46);

          return;

        }

      }

      else {

        if (iVar3 == 2) {

          anim_select_user(param_1,0x24);

          return;

        }

        if (iVar3 == 3) {

          objanim_select_anim(param_1,0x22);

          return;

        }

        if (iVar3 == 6) {

          if (*(int *)(param_1 + 0x10) != 0x43) {

            ObjectSetAnim(param_1,0x43,0x20,0,0,0x3f2aaaab);

            return;

          }

          if ((*(byte *)(param_1 + 0x30) & 2) != 0) {

            ObjectSetAnim(param_1,0x44,0x21,0,0,0x3f2aaaab);

            return;

          }

        }

        else if (iVar3 == 7) {

          if ((*(int *)(param_1 + 0x10) != 0x37) && (*(int *)(param_1 + 0x10) != 0x38)) {

            if (*(char *)(iVar2 + 0x88) != '\0') {

              ObjectSetAnim(param_1,0x37,0x20,0,0,0x3f2aaaab);

              return;

            }

            ObjectSetAnim(param_1,0x38,0x20,0,0,0x3f2aaaab);

            return;

          }

          if (((*(byte *)(param_1 + 0x30) & 2) != 0) && (iVar3 = fx_create(param_1), iVar3 != 0)) {

            iVar3 = *(int *)(iVar2 + 0xd4);

            iVar4 = *(int *)(param_1 + 0x100);

            *(undefined4 *)(param_1 + 0xe4) = 1;

            *(undefined4 *)(iVar4 + 0xd4) = 0;

            *(undefined4 *)(iVar4 + 0x94) = 0;

            fVar5 = (float10)rndfloatrange(*(undefined4 *)(DAT_00632ed8 + 0x91c),

                                           *(undefined4 *)(DAT_00632ed8 + 0x920));

            *(float *)(iVar4 + 100) = (float)fVar5;

            *(undefined4 *)(iVar4 + 0x74) = 0;

            *(uint *)(param_1 + 0x1c8) = *(uint *)(param_1 + 0x1c8) | 0x400;

            *(undefined4 *)(iVar4 + 0xac) = 0x3f800000;

            if (1 < iVar3) {

              *(int *)(iVar2 + 0xd4) = iVar3;

              iVar2 = *(int *)(param_1 + 0x100);

              *(uint *)(param_1 + 0x1c8) = *(uint *)(param_1 + 0x1c8) | 0x400;

              *(undefined4 *)(iVar2 + 0x74) = 1;

              *(undefined4 *)(iVar2 + 0xb0) = 1;

              *(undefined4 *)(iVar2 + 0xb8) = 3;

              iVar2 = fx_create(param_1);

              if (iVar2 == 0) {

                *(undefined4 *)(param_1 + 0xec) = 0;

                return;

              }

              fVar5 = (float10)rndfloatrange(*(undefined4 *)(DAT_00632ed8 + 0x98c),

                                             *(undefined4 *)(DAT_00632ed8 + 0x9a8));

              *(float *)(param_1 + 0xec) = (float)fVar5;

              iVar2 = reaper_0052e4a0(param_1);

              if (iVar2 != 0) {

                local_4 = 1;

                local_8 = 0;

                comm_chat_send_2(param_1,1,1,0,0xb,&local_8);

                return;

              }

            }

          }

        }

        else if (*(float *)(param_1 + 0x10c) == 0.0) {

          if ((*(float *)(param_1 + 0x114) != 0.0) && (*(int *)(*(int *)(param_1 + 8) + 0xa0) != 0))

          {

            anim_select_user(param_1,0x26);

            return;

          }

          if (iVar3 == 8) {

            iVar3 = *(int *)(param_1 + 0x10);

            if ((((iVar3 != 0x39) && (iVar3 != 0x23)) && (iVar3 != 0x3d)) &&

               ((iVar3 != 0x3b && (iVar3 != 0x3c)))) {

              anim_select_user(param_1,0x23);

              return;

            }

            if (((*(byte *)(param_1 + 0x30) & 2) != 0) &&

               (((*(byte *)(param_1 + 0xe0) & 1) == 0 ||

                (iVar3 = evilreaper_ai_big(param_1), iVar3 == 0)))) {

              if (*(float *)(iVar2 + 100) < 0.0 != (*(float *)(iVar2 + 100) == 0.0)) {

                iVar3 = *(int *)(*(int *)(param_1 + 0x274) + 0x100);

                iVar4 = fx_create(param_1);

                if (iVar4 != 0) {

                  fVar1 = *(float *)(*(int *)(*(int *)(iVar3 + 0x30) + *(int *)(iVar2 + 0x98) * 4) +

                                    0xf8);

                  fVar5 = (float10)distancesq2d__FP3P3DT0

                                             (*(int *)(*(int *)(iVar3 + 0x30) +

                                                      *(int *)(iVar2 + 0x98) * 4) + 0xa0,

                                              param_1 + 0xa0);

                  if (fVar5 <= (float10)fVar1 * (float10)fVar1) {

                    if (*(int *)(iVar2 + 0xa0) == 0) {

                      *(int *)(iVar2 + 0x9c) = *(int *)(iVar2 + 0x9c) + 1;

                      *(undefined4 *)(iVar2 + 0xa0) = 1;

                    }

                    iVar3 = FUN_005108f0(param_1);

                    if (iVar3 == 0) {

                      herdgen_get_next_marker(*(undefined4 *)(param_1 + 0x274),iVar2 + 0x98);

                      *(undefined4 *)(iVar2 + 0xa0) = 0;

                    }

                  }

                  vimp_get_wanted_loc__FP6OBJECT(param_1);

                }

                *(uint *)(param_1 + 0x1c8) = *(uint *)(param_1 + 0x1c8) | 0x400;

                *(undefined4 *)(iVar2 + 0xac) = 0x3f800000;

                *(undefined4 *)(param_1 + 0xe4) = 1;

                fVar5 = (float10)rndfloatrange(*(undefined4 *)(DAT_00632ed8 + 0x91c),

                                               *(undefined4 *)(DAT_00632ed8 + 0x920));

                *(float *)(iVar2 + 100) = (float)fVar5;

                *(undefined4 *)(iVar2 + 0x58) = 0;

                *(undefined4 *)(iVar2 + 0x68) = 0;

                return;

              }

              iVar2 = crt_rand_scaled(100);

              if (*(int *)(param_1 + 0x10) == 0x23) {

                if (iVar2 < 0x3c) {

                  iVar2 = 0x39;

                }

                else if (iVar2 < 0x50) {

                  iVar2 = 0x23;

                }

                else if (iVar2 < 0x5a) {

                  iVar2 = 0x3d;

                }

                else {

                  iVar2 = (0x5e < iVar2) + 0x3b;

                }

              }

              else {

                iVar2 = ((0x4a < iVar2) - 1 & 0x16) + 0x23;

              }

              if (iVar2 != *(int *)(param_1 + 0x10)) {

                ObjectSetAnim(param_1,iVar2,0x21,0,0,0x3f2aaaab);

                return;

              }

            }

          }

        }

        else if ((*(int *)(param_1 + 0x10) != 0x40) || ((*(byte *)(param_1 + 0x30) & 2) != 0)) {

          if ((**(byte **)(param_1 + 0x104) & 0x40) == 0) {

            if (*(float *)(param_1 + 0x278) <= 0.0) {

              if (*(int *)(iVar2 + 0x74) == 0) {

                fVar1 = *(float *)(DAT_00632ed8 + 0x9b0);

                iVar2 = 2;

              }

              else if (*(int *)(iVar2 + 0x74) == 1) {

                fVar1 = *(float *)(DAT_00632ed8 + 0x9b4);

                iVar2 = 3;

              }

              else {

                fVar1 = *(float *)(DAT_00632ed8 + 0x9b8);

                iVar2 = 4;

              }

            }

            else {

              fVar1 = *(float *)(DAT_00632ed8 + 0x9ac);

              iVar2 = 0x47;

            }

          }

          else {

            fVar1 = *(float *)(DAT_00632ed8 + 0x970);

            iVar2 = 0x48;

          }

          if (iVar2 != *(int *)(param_1 + 0x10)) {

            ObjectSetAnim(param_1,iVar2,0x21,1,fVar1 * *(float *)(param_1 + 0xc4),0x3f000000);

            return;

          }

        }

      }

    }

  }

  return;

}

/* ===== vimp_get_wanted_loc__FP6OBJECT @ 0x00511CF0 ===== */
/* PS2 candidate: vimp_get_wanted_loc__FP6OBJECT (conf 0.423) */



void vimp_get_wanted_loc__FP6OBJECT(int param_1)



{

  undefined4 *puVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  float10 fVar5;

  float local_2c;

  float local_28;

  undefined2 local_24;

  undefined2 local_22;

  undefined2 local_20;

  undefined2 local_1e;

  undefined1 local_1c [16];

  undefined4 local_c;

  

  iVar4 = *(int *)(*(int *)(param_1 + 0x274) + 0x100);

  iVar2 = *(int *)(param_1 + 0x100);

  fVar5 = (float10)rndfloatrange(0,0x43b40000);

  sine_cos_lookup((float)fVar5,&local_28,&local_2c);

  fVar5 = (float10)rndfloatrange(0,*(undefined4 *)

                                    (*(int *)(*(int *)(iVar4 + 0x30) + *(int *)(iVar2 + 0x98) * 4) +

                                    0xf8));

  *(float *)(param_1 + 0x178) = (float)(fVar5 * (float10)local_2c);

  fVar5 = (float10)rndfloatrange(0,*(undefined4 *)

                                    (*(int *)(*(int *)(iVar4 + 0x30) + *(int *)(iVar2 + 0x98) * 4) +

                                    0xf8));

  *(float *)(param_1 + 0x17c) = (float)(fVar5 * (float10)local_28);

  iVar3 = *(int *)(iVar2 + 0x98) * 4;

  *(float *)(iVar2 + 0x40) =

       *(float *)(*(int *)(iVar3 + *(int *)(iVar4 + 0x30)) + 0xa0) + *(float *)(param_1 + 0x178);

  *(float *)(iVar2 + 0x44) =

       *(float *)(*(int *)(iVar3 + *(int *)(iVar4 + 0x30)) + 0xa4) + *(float *)(param_1 + 0x17c);

  iVar4 = reaper_0052e4a0(param_1);

  if (iVar4 != 0) {

    iVar4 = *(int *)(param_1 + 0x100);

    if (8000.0 < *(float *)(param_1 + 0xa0)) {

      *(undefined4 *)(param_1 + 0xa0) = 0x45fa0000;

    }

    if (8000.0 < *(float *)(param_1 + 0xa4)) {

      *(undefined4 *)(param_1 + 0xa4) = 0x45fa0000;

    }

    if (*(float *)(param_1 + 0xa0) < -8000.0) {

      *(undefined4 *)(param_1 + 0xa0) = 0xc5fa0000;

    }

    if (*(float *)(param_1 + 0xa4) < -8000.0) {

      *(undefined4 *)(param_1 + 0xa4) = 0xc5fa0000;

    }

    if (8000.0 < *(float *)(iVar4 + 0x40)) {

      *(undefined4 *)(iVar4 + 0x40) = 0x45fa0000;

    }

    if (8000.0 < *(float *)(iVar4 + 0x44)) {

      *(undefined4 *)(iVar4 + 0x44) = 0x45fa0000;

    }

    if (*(float *)(iVar4 + 0x40) < -8000.0) {

      *(undefined4 *)(iVar4 + 0x40) = 0xc5fa0000;

    }

    if (*(float *)(iVar4 + 0x44) < -8000.0) {

      *(undefined4 *)(iVar4 + 0x44) = 0xc5fa0000;

    }

    local_24 = __ftol();

    local_22 = __ftol();

    local_20 = __ftol();

    local_1e = __ftol();

    comm_chat_send_2(param_1,0,2,0,4,&local_24);

  }

  iVar4 = *(int *)(param_1 + 0x100);

  if (*(int *)(iVar4 + 0xa8) != 0) {

    puVar1 = (undefined4 *)(iVar4 + 0x40);

    FUN_00414690(puVar1,local_1c);

    crt_euler_to_quat(*(int *)(iVar4 + 0xa8) + 0x294,0,0,0,

                      *(undefined4 *)(*(int *)(iVar4 + 0xa8) + 0xc4));

    iVar2 = *(int *)(iVar4 + 0xa8);

    *(undefined4 *)(iVar2 + 0xa0) = *puVar1;

    *(undefined4 *)(iVar2 + 0xa4) = *(undefined4 *)(iVar4 + 0x44);

    *(undefined4 *)(iVar2 + 0xa8) = *(undefined4 *)(iVar4 + 0x48);

    *(undefined4 *)(*(int *)(iVar4 + 0xa8) + 0xa8) = local_c;

    *(undefined4 *)(*(int *)(iVar4 + 0xa8) + 0x2a4) = *puVar1;

    *(undefined4 *)(*(int *)(iVar4 + 0xa8) + 0x2b4) = *(undefined4 *)(iVar4 + 0x44);

    *(undefined4 *)(*(int *)(iVar4 + 0xa8) + 0x2c4) = local_c;

  }

  return;

}

/* ===== vimp_handle_close_area_damage @ 0x00511F80 ===== */
void vimp_handle_close_area_damage(int param_1,int param_2)



{

  int iVar1;

  

  iVar1 = *(int *)(param_1 + 0x100);

  *(undefined4 *)(iVar1 + 200) = *(undefined4 *)(param_2 + 0xa0);

  *(undefined4 *)(iVar1 + 0xcc) = *(undefined4 *)(param_2 + 0xa4);

  *(undefined4 *)(iVar1 + 0xd0) = *(undefined4 *)(param_2 + 0xa8);

  *(undefined4 *)(iVar1 + 0xc4) = DAT_006328e8;

  return;

}

/* ===== evilreaper_ai_big @ 0x00511FF0 ===== */
undefined4 evilreaper_ai_big(int param_1)



{

  uint uVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  float10 fVar6;

  float local_18;

  float local_14;

  float local_10;

  float local_c;

  float local_8;

  float local_4;

  

  iVar2 = param_1;

  iVar4 = *(int *)(param_1 + 0x100);

  iVar3 = fx_create(param_1);

  if (((iVar3 != 0) && ((**(byte **)(iVar2 + 0x104) & 0x40) == 0)) &&

     ((*(byte *)(iVar2 + 0x30) & 2) != 0)) {

    iVar3 = *(int *)(iVar4 + 0xd4);

    if (iVar3 < 5) {

      uVar1 = *(uint *)(iVar2 + 0xe0);

      if ((uVar1 & 0x20) != 0) {

        *(undefined4 *)(iVar4 + 0xd4) = 5;

        *(undefined4 *)(iVar4 + 0xc4) = 0;

        *(undefined4 *)(iVar2 + 0xe0) = 0;

        herdgen_marker_user(iVar2,iVar4 + 200,0xbf800000);

        return 1;

      }

      if (iVar3 < 4) {

        if ((uVar1 & 0x10) != 0) {

          *(undefined4 *)(iVar4 + 0xd4) = 4;

          iVar4 = *(int *)(iVar2 + 0x100);

          *(uint *)(iVar2 + 0x1c8) = *(uint *)(iVar2 + 0x1c8) | 0x400;

          *(undefined4 *)(iVar2 + 0xe0) = 0;

          *(undefined4 *)(iVar4 + 0x74) = 2;

          *(undefined4 *)(iVar4 + 0xb0) = 1;

          *(undefined4 *)(iVar4 + 0xb8) = 3;

          iVar4 = fx_create(iVar2);

          if (iVar4 == 0) {

            *(undefined4 *)(iVar2 + 0xec) = 0;

          }

          else {

            fVar6 = (float10)rndfloatrange(*(undefined4 *)(DAT_00632ed8 + 0x98c),

                                           *(undefined4 *)(DAT_00632ed8 + 0x9a8));

            *(float *)(iVar2 + 0xec) = (float)fVar6;

            iVar4 = reaper_0052e4a0(iVar2);

            if (iVar4 != 0) {

              local_14 = 2.8026e-45;

              local_18 = 0.0;

              comm_chat_send_2(iVar2,1,1,0,0xb,&local_18);

              return 1;

            }

          }

          return 1;

        }

        if (iVar3 < 3) {

          if ((uVar1 & 8) != 0) {

            *(undefined4 *)(iVar4 + 0xd4) = 3;

            iVar4 = *(int *)(iVar2 + 0x100);

            *(uint *)(iVar2 + 0x1c8) = *(uint *)(iVar2 + 0x1c8) | 0x400;

            *(undefined4 *)(iVar2 + 0xe0) = 0;

            *(undefined4 *)(iVar4 + 0x74) = 1;

            *(undefined4 *)(iVar4 + 0xb0) = 1;

            *(undefined4 *)(iVar4 + 0xb8) = 3;

            iVar4 = fx_create(iVar2);

            if (iVar4 == 0) {

              *(undefined4 *)(iVar2 + 0xec) = 0;

            }

            else {

              fVar6 = (float10)rndfloatrange(*(undefined4 *)(DAT_00632ed8 + 0x98c),

                                             *(undefined4 *)(DAT_00632ed8 + 0x9a8));

              *(float *)(iVar2 + 0xec) = (float)fVar6;

              iVar4 = reaper_0052e4a0(iVar2);

              if (iVar4 != 0) {

                local_14 = 1.4013e-45;

                local_18 = 0.0;

                comm_chat_send_2(iVar2,1,1,0,0xb,&local_18);

                return 1;

              }

            }

            return 1;

          }

          if (iVar3 < 2) {

            if (((uVar1 & 4) != 0) && (*(int *)(iVar4 + 0x8c) != 0)) {

              *(undefined4 *)(iVar4 + 0xd4) = 2;

              *(undefined4 *)(iVar2 + 0xe0) = 0;

              iVar4 = *(int *)(iVar4 + 0x8c);

              iVar3 = *(int *)(iVar2 + 0x100);

              *(undefined4 *)(iVar3 + 0x90) = 0;

              *(int *)(iVar3 + 0x78) = iVar4;

              iVar5 = fx_create(iVar2);

              if (iVar5 == 0) {

                *(undefined1 *)(iVar3 + 0x88) = 0;

              }

              else {

                *(float *)(iVar3 + 0x7c) = *(float *)(iVar4 + 0xa0);

                *(undefined4 *)(iVar3 + 0x80) = *(undefined4 *)(iVar4 + 0xa4);

                *(undefined4 *)(iVar3 + 0x84) = *(undefined4 *)(iVar4 + 0xa8);

                local_c = *(float *)(iVar2 + 0x298);

                local_8 = *(float *)(iVar2 + 0x2a8);

                local_4 = *(float *)(iVar2 + 0x2b8);

                normalize__FPfN20(&local_c,&local_8,&local_4);

                local_18 = *(float *)(iVar2 + 0xa0) - *(float *)(iVar4 + 0xa0);

                local_14 = *(float *)(iVar2 + 0xa4) - *(float *)(iVar4 + 0xa4);

                local_10 = *(float *)(iVar2 + 0xa8) - *(float *)(iVar4 + 0xa8);

                normalize__FPfN20(&local_18,&local_14,&local_10);

                fVar6 = (float10)Dot__FP3P3DT0(&local_c,&local_18);

                if ((float10)0.0 <= fVar6) {

                  *(undefined1 *)(iVar3 + 0x88) = 0;

                }

                else {

                  *(undefined1 *)(iVar3 + 0x88) = 1;

                }

              }

              *(undefined4 *)(iVar2 + 0xe4) = 7;

              iVar4 = reaper_0052e4a0(iVar2);

              if (iVar4 != 0) {

                param_1 = CONCAT31(param_1._1_3_,*(undefined1 *)(iVar3 + 0x88));

                comm_chat_send_2(iVar2,0,0,1,7,&param_1);

              }

              return 1;

            }

            if ((iVar3 < 1) && ((uVar1 & 2) != 0)) {

              *(undefined4 *)(iVar4 + 0xd4) = 1;

              iVar4 = *(int *)(iVar2 + 0x100);

              *(undefined4 *)(iVar2 + 0xe0) = 0;

              *(undefined4 *)(iVar4 + 0x90) = 0;

              *(undefined4 *)(iVar4 + 0x78) = 0;

              iVar3 = fx_create(iVar2);

              if (iVar3 == 0) {

                *(undefined1 *)(iVar4 + 0x88) = 0;

              }

              else {

                *(float *)(iVar4 + 0x7c) = DAT_00632b48;

                *(float *)(iVar4 + 0x80) = DAT_00632b4c;

                *(float *)(iVar4 + 0x84) = DAT_00632b50;

                local_18 = *(float *)(iVar2 + 0x298);

                local_14 = *(float *)(iVar2 + 0x2a8);

                local_10 = *(float *)(iVar2 + 0x2b8);

                normalize__FPfN20(&local_18,&local_14,&local_10);

                local_c = *(float *)(iVar2 + 0xa0) - DAT_00632b48;

                local_8 = *(float *)(iVar2 + 0xa4) - DAT_00632b4c;

                local_4 = *(float *)(iVar2 + 0xa8) - DAT_00632b50;

                normalize__FPfN20(&local_c,&local_8,&local_4);

                fVar6 = (float10)Dot__FP3P3DT0(&local_18,&local_c);

                if ((float10)0.0 <= fVar6) {

                  *(undefined1 *)(iVar4 + 0x88) = 0;

                }

                else {

                  *(undefined1 *)(iVar4 + 0x88) = 1;

                }

              }

              *(undefined4 *)(iVar2 + 0xe4) = 7;

              iVar3 = reaper_0052e4a0(iVar2);

              if (iVar3 != 0) {

                param_1 = CONCAT31(param_1._1_3_,*(undefined1 *)(iVar4 + 0x88));

                comm_chat_send_2(iVar2,0,0,1,7,&param_1);

              }

              return 1;

            }

          }

        }

      }

    }

    *(undefined4 *)(iVar2 + 0xe0) = 0;

  }

  return 0;

}

/* ===== obj_proximity_flags @ 0x005124E0 ===== */
bool obj_proximity_flags(int param_1)



{

  int iVar1;

  int iVar2;

  float fVar3;

  undefined4 *puVar4;

  int *piVar5;

  bool bVar6;

  float10 fVar7;

  

  iVar1 = *(int *)(param_1 + 0x100);

  bVar6 = false;

  if (*(int *)(iVar1 + 0xd4) < 5) {

    bVar6 = 0.0 < *(float *)(iVar1 + 0xc4);

    if (bVar6) {

      *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 0x20;

    }

    if (*(int *)(iVar1 + 0xd4) < 4) {

      if (DAT_00632d94 != (int *)0x0) {

        piVar5 = DAT_00632d94;

        do {

          fVar7 = (float10)distancesq2d__FP3P3DT0(param_1 + 0xa0,piVar5[3] + 0xa0);

          if (fVar7 < (float10)*(float *)(DAT_00632ed8 + 0x998) *

                      (float10)*(float *)(DAT_00632ed8 + 0x998)) {

            *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 0x10;

            bVar6 = true;

            break;

          }

          piVar5 = (int *)*piVar5;

        } while (piVar5 != (int *)0x0);

      }

      puVar4 = DAT_00632d90;

      if (*(int *)(iVar1 + 0xd4) < 3) {

        for (; puVar4 != (undefined4 *)0x0; puVar4 = (undefined4 *)*puVar4) {

          iVar2 = *(int *)(puVar4[3] + 0xe4);

          if ((((iVar2 == 4) || (iVar2 == 2)) || (iVar2 == 3)) &&

             (fVar7 = (float10)distancesq2d__FP3P3DT0(param_1 + 0xa0,puVar4[3] + 0xa0),

             fVar7 < (float10)*(float *)(DAT_00632ed8 + 0x99c) *

                     (float10)*(float *)(DAT_00632ed8 + 0x99c))) {

            *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 8;

            bVar6 = true;

            break;

          }

        }

        if (*(int *)(iVar1 + 0xd4) < 2) {

          if ((0.0 < *(float *)(iVar1 + 0x90)) && (*(int *)(iVar1 + 0x8c) != 0)) {

            *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 4;

            bVar6 = true;

          }

          if (((*(int *)(iVar1 + 0xd4) < 1) &&

              (DAT_006328e8 - DAT_00632b44 < 1.0 != (DAT_006328e8 - DAT_00632b44 == 1.0))) &&

             (*(float *)(iVar1 + 0x3c) != DAT_00632b44)) {

            *(float *)(iVar1 + 0x3c) = DAT_00632b44;

            fVar7 = (float10)distancesq2d__FP3P3DT0(param_1 + 0xa0,&DAT_00632b48);

            if ((fVar7 < (float10)*(float *)(DAT_00632ed8 + 0x9a4) *

                         (float10)*(float *)(DAT_00632ed8 + 0x9a4)) &&

               (fVar3 = *(float *)(iVar1 + 0x94) + 1.0, *(float *)(iVar1 + 0x94) = fVar3,

               *(float *)(DAT_00632ed8 + 0x968) <= fVar3)) {

              *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 2;

              bVar6 = true;

            }

          }

        }

      }

    }

  }

  return bVar6;

}

/* ===== evilreaper_speed_dist @ 0x00512700 ===== */
/* PS2 candidate: fx_logic (conf 0.405) */



void evilreaper_speed_dist(int param_1)



{

  int iVar1;

  float fVar2;

  int iVar3;

  float10 fVar4;

  undefined4 uVar5;

  

  iVar1 = *(int *)(param_1 + 0x100);

  if (*(int *)(param_1 + 0xe8) == 1) {

    return;

  }

  if (*(int *)(iVar1 + 0x60) != 0) {

    return;

  }

  iVar3 = fx_create(param_1);

  if (iVar3 == 0) goto LAB_005127e2;

  fVar4 = (float10)FUN_00518b70(param_1,0);

  fVar4 = (float10)*(float *)(iVar1 + 0x54) - fVar4;

  *(float *)(iVar1 + 0x54) = (float)fVar4;

  if (fVar4 < (float10)0.0 == (fVar4 == (float10)0.0)) goto LAB_005127e2;

  if (*(int *)(iVar1 + 0x4c) == 0x3e4ccccd) {

    *(undefined4 *)(param_1 + 0x1c0) = *(undefined4 *)(DAT_00632ed8 + 0xbbc);

    *(undefined4 *)(iVar1 + 0x4c) = 0x3f000000;

    iVar3 = reaper_0052e4a0(param_1);

    if (iVar3 != 0) {

      uVar5 = 0xe;

LAB_005127be:

      reaper_00530bd0(param_1,0,0,0,uVar5,0);

    }

  }

  else if (*(int *)(iVar1 + 0x4c) == 0x3f000000) {

    *(undefined4 *)(param_1 + 0x1c0) = *(undefined4 *)(DAT_00632ed8 + 0xbc0);

    *(undefined4 *)(iVar1 + 0x4c) = 0x3f800000;

    iVar3 = reaper_0052e4a0(param_1);

    if (iVar3 != 0) {

      uVar5 = 0xf;

      goto LAB_005127be;

    }

  }

  fVar4 = (float10)rndfloatrange(0x41200000,0x41f00000);

  *(float *)(iVar1 + 0x54) = (float)fVar4;

LAB_005127e2:

  if (*(float *)(iVar1 + 0x50) < *(float *)(iVar1 + 0x4c)) {

    fVar4 = (float10)FUN_00518b70(param_1,0);

    fVar4 = fVar4 * (float10)0.5 + (float10)*(float *)(iVar1 + 0x50);

    *(float *)(iVar1 + 0x50) = (float)fVar4;

    if ((float10)*(float *)(iVar1 + 0x4c) <= fVar4) {

      *(undefined4 *)(iVar1 + 0x50) = *(undefined4 *)(iVar1 + 0x4c);

      fVar4 = (float10)FUN_004a2be0(param_1);

      *(float *)(param_1 + 0x154) = (float)fVar4;

    }

    fVar2 = *(float *)(iVar1 + 0x50);

    iVar3 = object_find(*(undefined4 *)(param_1 + 4));

    if (iVar3 != 0) {

      *(float *)(param_1 + 0xc4) = fVar2 * *(float *)(iVar3 + 0xc4);

    }

    if (*(int *)(param_1 + 0xe4) == 1) {

      if ((**(byte **)(param_1 + 0x104) & 0x40) == 0) {

        if (*(float *)(param_1 + 0x278) <= 0.0) {

          if (*(int *)(iVar1 + 0x74) == 0) {

            fVar2 = *(float *)(DAT_00632ed8 + 0x9b0);

          }

          else if (*(int *)(iVar1 + 0x74) == 1) {

            fVar2 = *(float *)(DAT_00632ed8 + 0x9b4);

          }

          else {

            fVar2 = *(float *)(DAT_00632ed8 + 0x9b8);

          }

        }

        else {

          fVar2 = *(float *)(DAT_00632ed8 + 0x9ac);

        }

      }

      else {

        fVar2 = *(float *)(DAT_00632ed8 + 0x970);

      }

    }

    else {

      fVar2 = 0.0;

    }

    ObjectUpdateSpeedDist(param_1,fVar2 * *(float *)(param_1 + 0xc4));

  }

  return;

}

/* ===== create_one_vimp_chunk @ 0x005129D0 ===== */
/* PS2 candidate: create_one_vimp_chunk (conf 0.446) */



int create_one_vimp_chunk

              (undefined4 *param_1,uint param_2,int param_3,int param_4,undefined4 param_5)



{

  undefined4 uVar1;

  int iVar2;

  float10 fVar3;

  

  if (param_4 != 0) {

    DAT_0057bffc = param_4;

  }

  iVar2 = object_allocate_type(DAT_0057bffc,0);

  *(undefined4 *)(iVar2 + 0xc4) = param_5;

  if ((param_4 == 0) && (DAT_0057bffc = DAT_0057bffc + 1, 0x45f < DAT_0057bffc)) {

    DAT_0057bffc = 0x45d;

  }

  *(uint *)(iVar2 + 0x1cc) = *(uint *)(iVar2 + 0x1cc) | 1;

  *(undefined4 *)(iVar2 + 0xb8) = *param_1;

  *(undefined4 *)(iVar2 + 0xbc) = param_1[1];

  *(undefined4 *)(iVar2 + 0xc0) = param_1[2];

  *(undefined4 *)(iVar2 + 0xac) = *param_1;

  *(undefined4 *)(iVar2 + 0xb0) = param_1[1];

  *(undefined4 *)(iVar2 + 0xb4) = param_1[2];

  *(undefined4 *)(iVar2 + 0xa0) = *param_1;

  *(undefined4 *)(iVar2 + 0xa4) = param_1[1];

  *(undefined4 *)(iVar2 + 0xa8) = param_1[2];

  fVar3 = (float10)rndfloat(0x43b40000);

  *(float *)(iVar2 + 200) = (float)fVar3;

  fVar3 = (float10)rndfloat(0x43b40000);

  *(float *)(iVar2 + 0xcc) = (float)fVar3;

  fVar3 = (float10)rndfloat(0x43b40000);

  *(float *)(iVar2 + 0xd0) = (float)fVar3;

  if ((param_2 & 4) == 0) {

    *(undefined4 *)(iVar2 + 0x108) = 0;

  }

  else {

    fVar3 = (float10)rndfloatrange(*(undefined4 *)(DAT_00632ed8 + 0x2e8),

                                   *(undefined4 *)(DAT_00632ed8 + 0x2ec));

    *(float *)(iVar2 + 0x108) = (float)(fVar3 * (float10)30.0);

  }

  if ((param_2 & 8) == 0) {

    *(undefined4 *)(iVar2 + 0x110) = 0;

    *(undefined4 *)(iVar2 + 0x10c) = 0;

  }

  else {

    fVar3 = (float10)rndfloatrange(-*(float *)(DAT_00632ed8 + 0x2e4),

                                   *(undefined4 *)(DAT_00632ed8 + 0x2e4));

    *(float *)(iVar2 + 0x10c) = (float)(fVar3 * (float10)15.0);

    fVar3 = (float10)rndfloatrange(-*(float *)(DAT_00632ed8 + 0x2e4),

                                   *(undefined4 *)(DAT_00632ed8 + 0x2e4));

    *(float *)(iVar2 + 0x110) = (float)(fVar3 * (float10)15.0);

  }

  fVar3 = (float10)rndfloatrange(-*(float *)(DAT_00632ed8 + 0x2f4),

                                 *(undefined4 *)(DAT_00632ed8 + 0x2f4));

  *(float *)(iVar2 + 0x114) = (float)fVar3;

  fVar3 = (float10)rndfloatrange(-*(float *)(DAT_00632ed8 + 0x2f0),

                                 *(undefined4 *)(DAT_00632ed8 + 0x2f0));

  *(float *)(iVar2 + 0xf4) = (float)fVar3;

  fVar3 = (float10)rndfloatrange(-*(float *)(DAT_00632ed8 + 0x2f0),

                                 *(undefined4 *)(DAT_00632ed8 + 0x2f0));

  *(float *)(iVar2 + 0xf8) = (float)fVar3;

  *(float *)(iVar2 + 0xfc) = (float)param_3;

  uVar1 = *(undefined4 *)(DAT_00632ed8 + 0x24);

  *(uint *)(iVar2 + 0xe0) = param_2;

  *(undefined4 *)(iVar2 + 0xec) = uVar1;

  *(undefined4 *)(iVar2 + 0xe4) = 0;

  return iVar2;

}

/* ===== vimp_mana_effect @ 0x00512C80 ===== */
/* PS2 candidate: evilreaper_award_item__FP6OBJECT (conf 0.441) */



undefined4 vimp_mana_effect(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)



{

  float fVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int *piVar5;

  float10 fVar6;

  float local_3c;

  

  fVar1 = *(float *)(DAT_00632ed8 + 0xbd0);

  iVar4 = 0;

  local_3c = -1.0;

  piVar5 = DAT_00632d74;

  if (DAT_00632d74 != (int *)0x0) {

    do {

      iVar2 = piVar5[3];

      iVar3 = ObjIsReaper(iVar2);

      if (((((iVar3 != 0) && (*(float *)(iVar2 + 0x278) < *(float *)(iVar2 + 0x1c0))) ||

           ((*(int *)(iVar2 + 4) == 0x438 && (*(float *)(iVar2 + 0x278) < *(float *)(iVar2 + 0x1c0))

            ))) && (fVar6 = (float10)distancesq2d__FP3P3DT0(iVar2 + 0xa0,param_1 + 0xa0),

                   fVar6 < (float10)fVar1 * (float10)fVar1)) &&

         ((fVar6 < (float10)local_3c || (local_3c < 0.0)))) {

        local_3c = (float)fVar6;

        iVar4 = iVar2;

      }

      piVar5 = (int *)*piVar5;

    } while (piVar5 != (int *)0x0);

    if (iVar4 != 0) {

      iVar4 = object_allocate_type(0x332,0x400);

      *(undefined4 *)(iVar4 + 0xa0) = *(undefined4 *)(param_1 + 0xa0);

      *(undefined4 *)(iVar4 + 0xa4) = *(undefined4 *)(param_1 + 0xa4);

      *(undefined4 *)(iVar4 + 0xa8) = *(undefined4 *)(param_1 + 0xa8);

      *(undefined4 *)(iVar4 + 0xf4) = 0;

      *(undefined4 *)(iVar4 + 0xfc) = param_4;

      *(uint *)(iVar4 + 0xd8) = *(uint *)(iVar4 + 0xd8) | 0x40000000;

      object_change_ospec(iVar4,0x54);

      fx_get_free_effect__Fv();

      return 1;

    }

  }

  return 0;

}

/* ===== flk_actor_update @ 0x005137C0 ===== */
void flk_actor_update(int param_1)



{

  char cVar1;

  int iVar2;

  int iVar3;

  uint uVar4;

  byte bVar5;

  undefined4 *puVar6;

  char *pcVar7;

  int iVar8;

  char *pcVar9;

  undefined4 local_30;

  undefined4 local_2c;

  undefined4 local_28;

  undefined1 local_24 [12];

  undefined1 local_18 [24];

  

  if (*(int *)(param_1 + 0x204) != 0) {

    local_30 = *(undefined4 *)(DAT_00632a88 + 0xa0);

    iVar2 = *(int *)(*(int *)(param_1 + 8) + 0x400);

    local_2c = *(undefined4 *)(DAT_00632a88 + 0xa4);

    local_28 = *(undefined4 *)(DAT_00632a88 + 0xa8);

    xformobj_world_local(param_1,&local_30,local_24);

    pcVar7 = *(char **)(param_1 + 0x204);

    *(undefined4 *)(param_1 + 0x270) = 0;

    bVar5 = 0;

    cVar1 = *pcVar7;

    while ((cVar1 != '\0' && (cVar1 != '*'))) {

      iVar8 = 0;

      if (0 < *(int *)(iVar2 + 0x68)) {

        puVar6 = (undefined4 *)(iVar2 + 0x74);

        do {

          iVar3 = FUN_0053a8a0(pcVar7,*puVar6);

          if (iVar3 != 0) break;

          iVar8 = iVar8 + 1;

          puVar6 = puVar6 + 0x14;

        } while (iVar8 < *(int *)(iVar2 + 0x68));

      }

      if (iVar8 < *(int *)(iVar2 + 0x68)) {

        mesh_node_calc_bounds(iVar2,iVar8,local_18);

        iVar8 = collide_pt_bbox(local_24,local_18);

        if (iVar8 != 0) {

          *(uint *)(param_1 + 0x270) = *(uint *)(param_1 + 0x270) | 1 << (bVar5 & 0x1f);

        }

      }

      uVar4 = 0xffffffff;

      pcVar9 = pcVar7;

      do {

        if (uVar4 == 0) break;

        uVar4 = uVar4 - 1;

        cVar1 = *pcVar9;

        pcVar9 = pcVar9 + 1;

      } while (cVar1 != '\0');

      pcVar9 = pcVar7 + ~uVar4;

      cVar1 = pcVar7[~uVar4];

      while (cVar1 != '\0') {

        uVar4 = 0xffffffff;

        pcVar7 = pcVar9;

        do {

          if (uVar4 == 0) break;

          uVar4 = uVar4 - 1;

          cVar1 = *pcVar7;

          pcVar7 = pcVar7 + 1;

        } while (cVar1 != '\0');

        pcVar7 = pcVar9 + ~uVar4;

        pcVar9 = pcVar9 + ~uVar4;

        cVar1 = *pcVar7;

      }

      pcVar7 = pcVar9 + 1;

      bVar5 = bVar5 + 1;

      cVar1 = pcVar9[1];

    }

    if ((*(int *)(param_1 + 0x270) == 0) && (*pcVar7 == '*')) {

      *(int *)(param_1 + 0x270) = 1 << (bVar5 & 0x1f);

    }

  }

  return;

}

/* ===== mesh_node_calc_bounds @ 0x00513920 ===== */
void mesh_node_calc_bounds(int param_1,int param_2,float *param_3)



{

  int iVar1;

  float *pfVar2;

  float fVar3;

  int iVar4;

  uint uVar5;

  int iVar6;

  ushort *puVar7;

  

  iVar4 = *(int *)(param_2 * 0x50 + 0x88 + param_1);

  iVar1 = param_2 * 0x50 + param_1;

  uVar5 = (uint)*(ushort *)(*(int *)(param_1 + 0x34) + iVar4 * 2);

  puVar7 = (ushort *)(*(int *)(param_1 + 0x34) + iVar4 * 2);

  iVar6 = 1;

  fVar3 = *(float *)(*(int *)(param_1 + 0x14) + uVar5 * 0xc);

  iVar4 = *(int *)(param_1 + 0x14) + uVar5 * 0xc;

  param_3[3] = fVar3;

  *param_3 = fVar3;

  fVar3 = *(float *)(iVar4 + 4);

  param_3[4] = fVar3;

  param_3[1] = fVar3;

  fVar3 = *(float *)(iVar4 + 8);

  param_3[5] = fVar3;

  param_3[2] = fVar3;

  if (1 < *(int *)(iVar1 + 0x8c)) {

    do {

      puVar7 = puVar7 + 1;

      pfVar2 = (float *)(*(int *)(param_1 + 0x14) + (uint)*puVar7 * 0xc);

      if (*(float *)(*(int *)(param_1 + 0x14) + (uint)*puVar7 * 0xc) < *param_3) {

        *param_3 = *pfVar2;

      }

      if (pfVar2[1] < param_3[1]) {

        param_3[1] = pfVar2[1];

      }

      if (pfVar2[2] < param_3[2]) {

        param_3[2] = pfVar2[2];

      }

      if (param_3[3] < *pfVar2) {

        param_3[3] = *pfVar2;

      }

      if (param_3[4] < pfVar2[1]) {

        param_3[4] = pfVar2[1];

      }

      if (param_3[5] < pfVar2[2]) {

        param_3[5] = pfVar2[2];

      }

      iVar6 = iVar6 + 1;

    } while (iVar6 < *(int *)(iVar1 + 0x8c));

  }

  return;

}

/* ===== hud_parse_format_codes_2 @ 0x00513A20 ===== */
undefined4 hud_parse_format_codes_2(int param_1)



{

  char cVar1;

  uint uVar2;

  int iVar3;

  uint uVar4;

  byte bVar5;

  char *pcVar6;

  char *pcVar7;

  

  pcVar6 = *(char **)(param_1 + 0x204);

  if (pcVar6 == (char *)0x0) {

    return 0;

  }

  cVar1 = *pcVar6;

  bVar5 = 0;

  do {

    if (cVar1 == '\0') {

      return 1;

    }

    uVar2 = *(uint *)(param_1 + 0x270);

    uVar4 = 0xffffffff;

    pcVar7 = pcVar6;

    do {

      if (uVar4 == 0) break;

      uVar4 = uVar4 - 1;

      cVar1 = *pcVar7;

      pcVar7 = pcVar7 + 1;

    } while (cVar1 != '\0');

    pcVar7 = pcVar6 + ~uVar4;

    cVar1 = pcVar6[~uVar4];

    while (cVar1 != '\0') {

      if (((1 << (bVar5 & 0x1f) & uVar2) != 0) &&

         (iVar3 = FUN_0053a8a0(pcVar7,s_world_0057c050), iVar3 != 0)) {

        return 0;

      }

      uVar4 = 0xffffffff;

      pcVar6 = pcVar7;

      do {

        if (uVar4 == 0) break;

        uVar4 = uVar4 - 1;

        cVar1 = *pcVar6;

        pcVar6 = pcVar6 + 1;

      } while (cVar1 != '\0');

      pcVar6 = pcVar7 + ~uVar4;

      pcVar7 = pcVar7 + ~uVar4;

      cVar1 = *pcVar6;

    }

    cVar1 = pcVar7[1];

    pcVar6 = pcVar7 + 1;

    bVar5 = bVar5 + 1;

  } while( true );

}

/* ===== FUN_00513ac0 @ 0x00513AC0 ===== */
undefined4 FUN_00513ac0(int param_1,int param_2,int param_3)



{

  char cVar1;

  uint uVar2;

  int iVar3;

  uint uVar4;

  byte bVar5;

  char *pcVar6;

  char *pcVar7;

  

  pcVar6 = *(char **)(param_1 + 0x204);

  if (pcVar6 == (char *)0x0) {

    return 0;

  }

  cVar1 = *pcVar6;

  bVar5 = 0;

  do {

    if (cVar1 == '\0') {

      return 1;

    }

    uVar2 = *(uint *)(param_1 + 0x270);

    uVar4 = 0xffffffff;

    pcVar7 = pcVar6;

    do {

      if (uVar4 == 0) break;

      uVar4 = uVar4 - 1;

      cVar1 = *pcVar7;

      pcVar7 = pcVar7 + 1;

    } while (cVar1 != '\0');

    pcVar7 = pcVar6 + ~uVar4;

    cVar1 = pcVar6[~uVar4];

    while (cVar1 != '\0') {

      if (((1 << (bVar5 & 0x1f) & uVar2) != 0) &&

         (iVar3 = FUN_0053a8a0(pcVar7,*(undefined4 *)(param_3 * 0x50 + 0x74 + param_2)), iVar3 != 0)

         ) {

        return 0;

      }

      uVar4 = 0xffffffff;

      pcVar6 = pcVar7;

      do {

        if (uVar4 == 0) break;

        uVar4 = uVar4 - 1;

        cVar1 = *pcVar6;

        pcVar6 = pcVar6 + 1;

      } while (cVar1 != '\0');

      pcVar6 = pcVar7 + ~uVar4;

      pcVar7 = pcVar7 + ~uVar4;

      cVar1 = *pcVar6;

    }

    cVar1 = pcVar7[1];

    pcVar6 = pcVar7 + 1;

    bVar5 = bVar5 + 1;

  } while( true );

}

/* ===== hud_parse_format_codes_3 @ 0x00513B60 ===== */
undefined4 hud_parse_format_codes_3(int param_1,int param_2,int param_3)



{

  char cVar1;

  int iVar2;

  uint uVar3;

  char *pcVar4;

  char *pcVar5;

  

  pcVar4 = *(char **)(param_1 + 0x204);

  if ((pcVar4 != (char *)0x0) && (*pcVar4 != '\0')) {

    do {

      iVar2 = FUN_0053a8a0(pcVar4,*(undefined4 *)(param_3 * 0x50 + 0x74 + param_2));

      if (iVar2 != 0) {

        return 1;

      }

      uVar3 = 0xffffffff;

      pcVar5 = pcVar4;

      do {

        if (uVar3 == 0) break;

        uVar3 = uVar3 - 1;

        cVar1 = *pcVar5;

        pcVar5 = pcVar5 + 1;

      } while (cVar1 != '\0');

      pcVar5 = pcVar4 + ~uVar3;

      cVar1 = pcVar4[~uVar3];

      while (cVar1 != '\0') {

        uVar3 = 0xffffffff;

        pcVar4 = pcVar5;

        do {

          if (uVar3 == 0) break;

          uVar3 = uVar3 - 1;

          cVar1 = *pcVar4;

          pcVar4 = pcVar4 + 1;

        } while (cVar1 != '\0');

        pcVar4 = pcVar5 + ~uVar3;

        pcVar5 = pcVar5 + ~uVar3;

        cVar1 = *pcVar4;

      }

      pcVar4 = pcVar5 + 1;

    } while (pcVar5[1] != '\0');

  }

  return 0;

}

/* ===== wave_effect_calc_verts @ 0x00513EE0 ===== */
int wave_effect_calc_verts(int param_1,float *param_2,float *param_3)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  float10 fVar5;

  float10 extraout_ST0;

  float10 extraout_ST0_00;

  float10 extraout_ST1;

  

  fVar5 = (float10)*(float *)(param_1 + 0x14);

  iVar1 = *(int *)(param_1 + 8);

  iVar2 = *(int *)(param_1 + 0xc);

  *param_2 = (float)((float10)*param_2 - (float10)iVar1 * (float10)0.5 * fVar5);

  *param_3 = (float)((float10)*param_3 - (float10)iVar2 * (float10)0.5 * fVar5);

  fVar5 = (float10)1.0 / (fVar5 + fVar5);

  iVar3 = __ftol();

  fVar5 = (extraout_ST0 - (float10)iVar3) * fVar5;

  *param_2 = (float)((float10)*param_2 - (fVar5 + fVar5));

  iVar4 = __ftol();

  fVar5 = (extraout_ST0_00 - (float10)iVar4) * extraout_ST1;

  *param_3 = (float)((float10)*param_3 - (fVar5 + fVar5));

  return ((iVar4 * 2 + 0x10000000) % iVar2) * iVar1 + (iVar3 * 2 + 0x10000000) % iVar1;

}

/* ===== wave_effect_get_player_position__FP11T_WaveDatasP6OBJECT @ 0x00513FA0 ===== */
/* PS2 candidate: wave_effect_get_player_position__FP11T_WaveDatasP6OBJECT (conf 0.476) */



int wave_effect_get_player_position__FP11T_WaveDatasP6OBJECT(int *param_1,int param_2)



{

  float fVar1;

  float fVar2;

  float fVar3;

  int iVar4;

  float *pfVar5;

  int *piVar6;

  int iVar7;

  int *piVar8;

  int *piVar9;

  float10 fVar10;

  float10 fVar11;

  undefined4 local_8;

  

  piVar6 = (int *)XFGetCameraOrigin();

  fVar1 = 1.0;

  param_1[0x29] = 0;

  param_1[1] = 0x3f800000;

  param_1[2] = 0x3f800000;

  param_1[3] = 0x3e800000;

  param_1[4] = 0x3f800000;

  param_1[6] = *piVar6;

  param_1[7] = piVar6[1];

  local_8 = 0x40000000;

  param_1[8] = piVar6[2];

  param_1[0x2a] = 0x41a00000;

  param_1[0x2b] = 0x40000000;

  if (param_2 != 0) {

    param_1[6] = *(int *)(param_2 + 0xa0);

    param_1[7] = *(int *)(param_2 + 0xa4);

    param_1[8] = *(int *)(param_2 + 0xa8);

    fVar1 = 1.0;

    if ((float)param_1[8] < 0.0) {

      param_1[0x29] = 1;

    }

    iVar7 = *(int *)(param_2 + 0x210);

    while (iVar4 = iVar7, iVar4 != 0) {

      param_2 = iVar4;

      iVar7 = *(int *)(iVar4 + 0x210);

    }

    iVar7 = *(int *)(param_2 + 4);

    if (iVar7 < 0x86) {

      if (iVar7 != 0x85) {

        if (iVar7 == 1) {

          fVar10 = (float10)FUN_0045d2e0(param_2);

          fVar1 = (float)fVar10;

          param_1[0x29] = 0;

          piVar6 = param_1 + 1;

          *piVar6 = 0x40000000;

          param_1[0x2b] = 0x41200000;

          param_1[2] = (int)(fVar1 * 16.0);

          param_1[3] = (int)(1.0 / (fVar1 * 16.0 * 4.0));

          param_1[0x2a] = (int)(fVar1 * 200.0);

          piVar8 = piVar6;

          for (iVar7 = 8; iVar7 != 0; iVar7 = iVar7 + -1) {

            *piVar8 = *piVar6;

            piVar6 = piVar6 + 1;

            piVar8 = piVar8 + 1;

          }

          playerobj_eval_refpt(param_2,8,param_1 + param_1[0x29] * 8 + 6);

          if ((float)param_1[(param_1[0x29] + 1) * 8] < 0.0) {

            param_1[0x29] = param_1[0x29] + 1;

          }

          piVar8 = param_1 + param_1[0x29] * 8 + 1;

          piVar6 = param_1;

          for (iVar7 = 8; piVar6 = piVar6 + 1, iVar7 != 0; iVar7 = iVar7 + -1) {

            *piVar8 = *piVar6;

            piVar8 = piVar8 + 1;

          }

          playerobj_eval_refpt(param_2,9,param_1 + param_1[0x29] * 8 + 6);

          if ((float)param_1[(param_1[0x29] + 1) * 8] < 0.0) {

            param_1[0x29] = param_1[0x29] + 1;

          }

          fVar1 = fVar1 * 8.0;

          *(undefined4 *)(*param_1 + 0x3c) = 0x3dcccccd;

          local_8 = 0x40800000;

          *(undefined4 *)(*param_1 + 0x1c) = 0x3f666666;

          goto LAB_005148d3;

        }

        if (iVar7 != 2) {

          if (iVar7 == 3) {

            param_1[0x29] = 0;

            piVar6 = param_1 + 1;

            piVar8 = param_1 + 1;

            for (iVar7 = 8; iVar7 != 0; iVar7 = iVar7 + -1) {

              *piVar8 = *piVar6;

              piVar6 = piVar6 + 1;

              piVar8 = piVar8 + 1;

            }

            playerobj_eval_refpt(param_2,0,param_1 + param_1[0x29] * 8 + 6);

            if ((float)param_1[(param_1[0x29] + 1) * 8] < 0.0) {

              param_1[param_1[0x29] * 8 + 1] =

                   (int)(1.0 - ABS((float)param_1[(param_1[0x29] + 1) * 8]) * 0.2);

              if ((float)param_1[param_1[0x29] * 8 + 1] < 0.0) {

                param_1[param_1[0x29] * 8 + 1] = 0;

              }

              param_1[0x29] = param_1[0x29] + 1;

            }

            piVar8 = param_1 + param_1[0x29] * 8 + 1;

            piVar6 = param_1;

            for (iVar7 = 8; piVar6 = piVar6 + 1, iVar7 != 0; iVar7 = iVar7 + -1) {

              *piVar8 = *piVar6;

              piVar8 = piVar8 + 1;

            }

            playerobj_eval_refpt(param_2,1,param_1 + param_1[0x29] * 8 + 6);

            if ((float)param_1[(param_1[0x29] + 1) * 8] < 0.0) {

              param_1[param_1[0x29] * 8 + 1] =

                   (int)(1.0 - ABS((float)param_1[(param_1[0x29] + 1) * 8]) * 0.2);

              if ((float)param_1[param_1[0x29] * 8 + 1] < 0.0) {

                param_1[param_1[0x29] * 8 + 1] = 0;

              }

              param_1[0x29] = param_1[0x29] + 1;

            }

            piVar8 = param_1 + param_1[0x29] * 8 + 1;

            piVar6 = param_1;

            for (iVar7 = 8; piVar6 = piVar6 + 1, iVar7 != 0; iVar7 = iVar7 + -1) {

              *piVar8 = *piVar6;

              piVar8 = piVar8 + 1;

            }

            playerobj_eval_refpt(param_2,0xb,param_1 + param_1[0x29] * 8 + 6);

            if ((float)param_1[(param_1[0x29] + 1) * 8] < 0.0) {

              param_1[param_1[0x29] * 8 + 1] =

                   (int)(1.0 - ABS((float)param_1[(param_1[0x29] + 1) * 8]) * 0.15);

              if ((float)param_1[param_1[0x29] * 8 + 1] < 0.0) {

                param_1[param_1[0x29] * 8 + 1] = 0;

              }

              param_1[0x29] = param_1[0x29] + 1;

            }

            piVar8 = param_1 + param_1[0x29] * 8 + 1;

            piVar6 = param_1;

            for (iVar7 = 8; piVar6 = piVar6 + 1, iVar7 != 0; iVar7 = iVar7 + -1) {

              *piVar8 = *piVar6;

              piVar8 = piVar8 + 1;

            }

            playerobj_eval_refpt(param_2,0xc,param_1 + param_1[0x29] * 8 + 6);

            if ((float)param_1[(param_1[0x29] + 1) * 8] < 0.0) {

              param_1[param_1[0x29] * 8 + 1] =

                   (int)(1.0 - ABS((float)param_1[(param_1[0x29] + 1) * 8]) * 0.15);

              if ((float)param_1[param_1[0x29] * 8 + 1] < 0.0) {

                param_1[param_1[0x29] * 8 + 1] = 0;

              }

              param_1[0x29] = param_1[0x29] + 1;

            }

            fVar1 = 0.5;

            local_8 = 0x3fc00000;

            param_1[0x2b] = 0x41000000;

          }

          goto LAB_005148d3;

        }

      }

      param_1[0x29] = 0;

      param_1[2] = 0x40000000;

      param_1[3] = 0x3e000000;

      param_1[0x2b] = 0x40800000;

      piVar6 = param_1 + 1;

      piVar8 = param_1 + 1;

      for (iVar7 = 8; iVar7 != 0; iVar7 = iVar7 + -1) {

        *piVar8 = *piVar6;

        piVar6 = piVar6 + 1;

        piVar8 = piVar8 + 1;

      }

      playerobj_eval_refpt(param_2,8,param_1 + param_1[0x29] * 8 + 6);

      if ((float)param_1[(param_1[0x29] + 1) * 8] < 0.0) {

        param_1[0x29] = param_1[0x29] + 1;

      }

      piVar8 = param_1 + param_1[0x29] * 8 + 1;

      piVar6 = param_1;

      for (iVar7 = 8; piVar6 = piVar6 + 1, iVar7 != 0; iVar7 = iVar7 + -1) {

        *piVar8 = *piVar6;

        piVar8 = piVar8 + 1;

      }

      playerobj_eval_refpt(param_2,9,param_1 + param_1[0x29] * 8 + 6);

      fVar1 = 1.0;

      if ((float)param_1[(param_1[0x29] + 1) * 8] < 0.0) {

        param_1[0x29] = param_1[0x29] + 1;

      }

    }

    else if (((iVar7 == 0xd7) || (iVar7 == 0x434)) || (iVar7 == 0x487)) {

      param_1[0x29] = param_1[0x29] + 4;

      param_1[2] = 0x40800000;

      param_1[3] = 0x3d800000;

      param_1[1] = 0x3f800000;

      param_1[4] = 0;

      if (*(int *)(param_2 + 0x104) == 0) {

        param_1[3] = 0x3d800000;

        param_1[1] = -0x40800000;

      }

      else {

        iVar7 = *param_1;

        fVar10 = (float10)FUN_00518b70(param_2,0);

        fVar11 = (float10)rndfloatrange(0,0x41000000);

        *(float *)(iVar7 + 0x44) =

             (float)(fVar11 * (float10)(float)fVar10 + (float10)*(float *)(iVar7 + 0x44));

        iVar7 = *param_1;

        fVar1 = *(float *)(iVar7 + 0x44);

        while (pfVar5 = (float *)(iVar7 + 0x44), 6.2831855 < fVar1) {

          *pfVar5 = *pfVar5 - 6.2831855;

          iVar7 = *param_1;

          fVar1 = *(float *)(iVar7 + 0x44);

        }

        fVar10 = (float10)*(float *)(*(int *)(param_2 + 0x104) + 0x24) /

                 (float10)*(float *)(DAT_00632ed8 + 0x8b0);

        if ((float10)0.5 < fVar10) {

          fVar10 = (float10)0.5;

        }

        fVar11 = (float10)fsin((float10)*pfVar5);

        fVar11 = fVar11 * fVar10;

        if (fVar11 < (float10)0.0) {

          fVar11 = -fVar11;

        }

        fVar11 = fVar11 * (float10)(float)param_1[1];

        param_1[1] = (int)(float)fVar11;

        if (*(int *)(param_2 + 4) == 0x434) {

          iVar7 = *(int *)(param_2 + 0x104);

          fVar1 = 1.0 / (1.0 / *(float *)(iVar7 + 8));

          fVar2 = fVar1 * *(float *)(iVar7 + 0x18);

          fVar3 = fVar1 * *(float *)(iVar7 + 0x1c);

          fVar1 = fVar1 * *(float *)(iVar7 + 0x20);

          fVar1 = fVar2 * fVar2 + fVar3 * fVar3 + fVar1 * fVar1;

          if (fVar1 == 0.0) {

            fVar10 = (float10)0.0;

          }

          else {

            fVar10 = (float10)(float)((&DAT_005f0a18)[(uint)fVar1 >> 8 & 0xffff] |

                                     ((int)fVar1 + 0xc0800000U >> 1) + 0x3f800000 & 0x7f800000);

          }

          fVar10 = fVar10 * (float10)2e-05;

          if ((float10)1.0 < fVar10) {

            fVar10 = (float10)1.0;

          }

          param_1[1] = (int)(float)(fVar10 + fVar11);

          if ((float10)0.75 < fVar10 + fVar11) {

            param_1[1] = 0x3f400000;

          }

          fVar1 = 2.0;

        }

        else {

          param_1[1] = (int)(float)(fVar11 + (float10)0.25);

          if ((float10)0.5 < fVar11 + (float10)0.25) {

            param_1[1] = 0x3f000000;

          }

          fVar1 = 5.0;

          param_1[2] = 0x41200000;

          param_1[3] = 0x3d088889;

        }

      }

      fVar2 = 1.0;

      if (2.0 < (float)param_1[8]) {

        fVar2 = 0.0;

      }

      piVar6 = param_1 + 1;

      param_1[1] = (int)(fVar2 * (float)param_1[1]);

      piVar8 = piVar6;

      piVar9 = param_1 + 9;

      for (iVar7 = 8; iVar7 != 0; iVar7 = iVar7 + -1) {

        *piVar9 = *piVar8;

        piVar8 = piVar8 + 1;

        piVar9 = piVar9 + 1;

      }

      piVar8 = piVar6;

      piVar9 = param_1 + 0x11;

      for (iVar7 = 8; iVar7 != 0; iVar7 = iVar7 + -1) {

        *piVar9 = *piVar8;

        piVar8 = piVar8 + 1;

        piVar9 = piVar9 + 1;

      }

      piVar8 = piVar6;

      piVar9 = param_1 + 0x19;

      for (iVar7 = 8; iVar7 != 0; iVar7 = iVar7 + -1) {

        *piVar9 = *piVar8;

        piVar8 = piVar8 + 1;

        piVar9 = piVar9 + 1;

      }

      piVar8 = param_1 + 0x21;

      for (iVar7 = 8; iVar7 != 0; iVar7 = iVar7 + -1) {

        *piVar8 = *piVar6;

        piVar6 = piVar6 + 1;

        piVar8 = piVar8 + 1;

      }

      param_1[6] = (int)(*(float *)(param_2 + 0x29c) + *(float *)(param_2 + 0x29c) +

                        (float)param_1[6]);

      param_1[7] = (int)(*(float *)(param_2 + 0x2ac) + *(float *)(param_2 + 0x2ac) +

                        (float)param_1[7]);

      param_1[8] = (int)(*(float *)(param_2 + 700) + *(float *)(param_2 + 700) + (float)param_1[8]);

      param_1[0xe] = (int)(*(float *)(param_2 + 0x298) * 4.0 + *(float *)(param_2 + 0x29c) * 8.0 +

                          (float)param_1[0xe]);

      param_1[0xf] = (int)(*(float *)(param_2 + 0x2a8) * 4.0 + *(float *)(param_2 + 0x2ac) * 8.0 +

                          (float)param_1[0xf]);

      param_1[0x10] =

           (int)(*(float *)(param_2 + 0x2b8) * 4.0 + *(float *)(param_2 + 700) * 8.0 +

                (float)param_1[0x10]);

      param_1[0x16] =

           (int)((*(float *)(param_2 + 0x29c) * 8.0 - *(float *)(param_2 + 0x298) * 4.0) +

                (float)param_1[0x16]);

      param_1[0x17] =

           (int)((*(float *)(param_2 + 0x2ac) * 8.0 - *(float *)(param_2 + 0x2a8) * 4.0) +

                (float)param_1[0x17]);

      param_1[0x18] =

           (int)((*(float *)(param_2 + 700) * 8.0 - *(float *)(param_2 + 0x2b8) * 4.0) +

                (float)param_1[0x18]);

      param_1[0x1e] =

           (int)(*(float *)(param_2 + 0x298) * 4.0 + *(float *)(param_2 + 0x29c) * 10.0 +

                (float)param_1[0x1e]);

      local_8 = 0x41800000;

      param_1[0x1f] =

           (int)(*(float *)(param_2 + 0x2a8) * 4.0 + *(float *)(param_2 + 0x2ac) * 10.0 +

                (float)param_1[0x1f]);

      param_1[0x20] =

           (int)(*(float *)(param_2 + 0x2b8) * 4.0 + *(float *)(param_2 + 700) * 10.0 +

                (float)param_1[0x20]);

      param_1[0x26] =

           (int)((*(float *)(param_2 + 0x29c) * 10.0 - *(float *)(param_2 + 0x298) * 4.0) +

                (float)param_1[0x26]);

      param_1[0x27] =

           (int)((*(float *)(param_2 + 0x2ac) * 10.0 - *(float *)(param_2 + 0x2a8) * 4.0) +

                (float)param_1[0x27]);

      fVar2 = *(float *)(param_2 + 700);

      fVar3 = *(float *)(param_2 + 0x2b8);

      param_1[0x2a] = 0x43480000;

      param_1[0x2b] = 0x41700000;

      param_1[0x28] = (int)((fVar2 * 10.0 - fVar3 * 4.0) + (float)param_1[0x28]);

    }

  }

LAB_005148d3:

  iVar7 = *param_1;

  if (iVar7 == 0) {

    return param_2;

  }

  *(float *)(iVar7 + 0x14) = fVar1;

  *(undefined4 *)(iVar7 + 0x18) = local_8;

  return param_2;

}

/* ===== wave_effect_get_player_origin @ 0x00514900 ===== */
/* PS2 candidate: wave_effect_get_player_origin (conf 0.433) */



void wave_effect_get_player_origin

               (int param_1,int param_2,float *param_3,float *param_4,float param_5,float param_6)



{

  float fVar1;

  float *pfVar2;

  float10 fVar3;

  float10 fVar4;

  float local_c;

  

  fVar1 = *(float *)(param_1 + 0x14);

  if (param_2 != 0) {

    if (*(int *)(param_2 + 0x104) == 0) {

      fVar4 = (float10)FUN_00518b70(param_2,0);

      if (fVar4 <= (float10)0.0001) {

        fVar4 = (float10)0.0;

      }

      else {

        fVar4 = (float10)param_6 / fVar4;

      }

      fVar3 = (float10)*(float *)(param_2 + 0xac) - fVar4 * (float10)*(float *)(param_2 + 0xa0);

      fVar4 = (float10)*(float *)(param_2 + 0xb0) - fVar4 * (float10)*(float *)(param_2 + 0xa4);

    }

    else {

      fVar3 = ((float10)1.0 / (float10)param_6) * (float10)*(float *)(param_2 + 0x128);

      fVar4 = ((float10)1.0 / (float10)param_6) * (float10)*(float *)(param_2 + 300);

    }

    local_c = (float)fVar3;

    if (1.0 < local_c) {

      local_c = 1.0;

    }

    if ((float10)1.0 < fVar4) {

      fVar4 = (float10)1.0;

    }

    if (local_c < -1.0) {

      local_c = -1.0;

    }

    if (fVar4 < (float10)-1.0) {

      fVar4 = (float10)-1.0;

    }

    *param_3 = *(float *)(param_2 + 0xa0) -

               ((float)*(int *)(param_1 + 8) * fVar1 * 0.5 - param_5) * local_c;

    *param_4 = (float)((float10)*(float *)(param_2 + 0xa4) -

                      ((float10)*(int *)(param_1 + 0xc) * (float10)fVar1 * (float10)0.5 -

                      (float10)param_5) * fVar4);

    return;

  }

  pfVar2 = (float *)XFGetCameraOrigin();

  *param_3 = *pfVar2;

  *param_4 = pfVar2[1];

  return;

}

/* ===== terrain_vertex_walk @ 0x00514A50 ===== */
void terrain_vertex_walk(int param_1,int param_2,float param_3,undefined4 param_4,float param_5,

                        float param_6,float param_7,float param_8)



{

  int iVar1;

  int iVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  int iVar9;

  int iVar10;

  int iVar11;

  float10 fVar12;

  float10 fVar13;

  

  iVar1 = *(int *)(param_1 + 0x10);

  iVar2 = *(int *)(param_1 + 0x20);

  iVar6 = __ftol();

  iVar9 = param_2 * 0x10 + iVar2;

  iVar7 = iVar6;

  if (iVar6 != 0) {

    do {

      iVar9 = (uint)*(ushort *)(iVar9 + 10) * 0x10 + iVar2;

      iVar7 = iVar7 + -1;

      iVar8 = iVar6;

    } while (iVar7 != 0);

    for (; iVar8 != 0; iVar8 = iVar8 + -1) {

      iVar9 = (uint)*(ushort *)(iVar9 + 8) * 0x10 + iVar2;

    }

  }

  iVar8 = -iVar6;

  fVar3 = (float)iVar6 * *(float *)(param_1 + 0x14);

  iVar7 = iVar8;

  if (-iVar6 == iVar6 || iVar8 < iVar6) {

    do {

      if (iVar8 <= iVar6) {

        iVar10 = iVar9;

        iVar11 = iVar8;

        do {

          fVar5 = ((float)iVar11 - param_7) * *(float *)(param_1 + 0x14);

          fVar4 = ((float)iVar7 - param_8) * *(float *)(param_1 + 0x14);

          fVar4 = fVar5 * fVar5 + fVar4 * fVar4;

          if (fVar4 == 0.0) {

            fVar12 = (float10)0.0;

          }

          else {

            fVar12 = (float10)(float)((&DAT_005f0a18)[(uint)fVar4 >> 8 & 0xffff] |

                                     ((int)fVar4 + 0xc0800000U >> 1) + 0x3f800000 & 0x7f800000);

          }

          if (fVar12 < (float10)fVar3) {

            fVar13 = (float10)fcos((float10)(param_5 * 6.2831855) * fVar12 +

                                   (float10)(param_6 * 6.2831855));

            *(float *)(iVar10 + iVar1 * 4) =

                 (float)(((float10)1.0 - fVar12 / (float10)fVar3) * fVar13 * (float10)param_3 +

                        (float10)*(float *)(iVar10 + iVar1 * 4));

          }

          iVar10 = (uint)*(ushort *)(iVar10 + 0xc) * 0x10 + iVar2;

          iVar11 = iVar11 + 1;

        } while (iVar11 <= iVar6);

      }

      iVar9 = (uint)*(ushort *)(iVar9 + 0xe) * 0x10 + iVar2;

      iVar7 = iVar7 + 1;

    } while (iVar7 <= iVar6);

  }

  *(undefined4 *)(param_1 + 0x40) = 0x40a00000;

  return;

}

/* ===== wave_effect_zero_edges @ 0x00514C00 ===== */
/* PS2 candidate: wave_effect_zero_edges (conf 0.733) */



void wave_effect_zero_edges(int param_1,uint param_2)



{

  ushort uVar1;

  int iVar2;

  undefined4 *puVar3;

  int iVar4;

  

  iVar2 = *(int *)(param_1 + 0x20);

  for (iVar4 = *(int *)(param_1 + 8); puVar3 = (undefined4 *)(param_2 * 0x10 + iVar2), iVar4 != 0;

      iVar4 = iVar4 + -1) {

    param_2 = (uint)*(ushort *)(puVar3 + 3);

    *puVar3 = 0;

    puVar3[1] = 0;

  }

  for (iVar4 = *(int *)(param_1 + 0xc); iVar4 != 0; iVar4 = iVar4 + -1) {

    *puVar3 = 0;

    puVar3[1] = 0;

    puVar3 = (undefined4 *)((uint)*(ushort *)((int)puVar3 + 0xe) * 0x10 + iVar2);

  }

  uVar1 = *(ushort *)((uint)*(ushort *)(puVar3 + 2) * 0x10 + 10 + iVar2);

  for (iVar4 = *(int *)(param_1 + 8); puVar3 = (undefined4 *)((uint)uVar1 * 0x10 + iVar2),

      iVar4 != 0; iVar4 = iVar4 + -1) {

    uVar1 = *(ushort *)(puVar3 + 3);

    *puVar3 = 0;

    puVar3[1] = 0;

  }

  for (iVar4 = *(int *)(param_1 + 0xc); iVar4 != 0; iVar4 = iVar4 + -1) {

    *puVar3 = 0;

    puVar3[1] = 0;

    puVar3 = (undefined4 *)((uint)*(ushort *)((int)puVar3 + 0xe) * 0x10 + iVar2);

  }

  return;

}

/* ===== wave_effect_calc_edges @ 0x00514CB0 ===== */
void wave_effect_calc_edges(int param_1)



{

  uint uVar1;

  float fVar2;

  int iVar3;

  ushort *puVar4;

  float *pfVar5;

  int iVar6;

  

  fVar2 = *(float *)(param_1 + 0x40) - DAT_006328e0;

  *(float *)(param_1 + 0x40) = fVar2;

  if (fVar2 < 0.0) {

    *(undefined4 *)(param_1 + 0x40) = 0;

  }

  if (*(float *)(param_1 + 0x40) < 0.0 == (*(float *)(param_1 + 0x40) == 0.0)) {

    iVar6 = *(int *)(param_1 + 0xc) * *(int *)(param_1 + 8);

    uVar1 = *(uint *)(param_1 + 0x10);

    fVar2 = *(float *)(param_1 + 0x1c);

    iVar3 = *(int *)(param_1 + 0x20);

    *(uint *)(param_1 + 0x10) = uVar1 ^ 1;

    if (iVar6 != 0) {

      puVar4 = (ushort *)(iVar3 + 0xc);

      pfVar5 = (float *)(iVar3 + (uVar1 ^ 1) * 4);

      do {

        iVar6 = iVar6 + -1;

        *pfVar5 = ((*(float *)(iVar3 + (uVar1 + (uint)puVar4[-2] * 4) * 4) +

                    *(float *)(iVar3 + (uVar1 + (uint)puVar4[-1] * 4) * 4) +

                    *(float *)(iVar3 + (uVar1 + (uint)puVar4[1] * 4) * 4) +

                   *(float *)(iVar3 + (uVar1 + (uint)*puVar4 * 4) * 4)) * 0.5 - *pfVar5) * fVar2;

        puVar4 = puVar4 + 8;

        pfVar5 = pfVar5 + 4;

      } while (iVar6 != 0);

    }

  }

  return;

}

/* ===== terrain_elevation_gen @ 0x00514D60 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void terrain_elevation_gen(int param_1,uint param_2,float param_3,float param_4)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  int iVar5;

  int iVar6;

  float fVar7;

  uint uVar8;

  float *pfVar9;

  float *pfVar10;

  int iVar11;

  int iVar12;

  int iVar13;

  float local_34;

  int local_30;

  int iStack_2c;

  undefined *local_18;

  int local_14;

  undefined4 local_10;

  undefined4 local_c;

  

  iVar5 = DAT_006330e4;

  if (*(float *)(param_1 + 0x40) < 0.0 == (*(float *)(param_1 + 0x40) == 0.0)) {

    if (((DAT_006330e4 == 0) || (iVar12 = *(int *)(DAT_006330e4 + 0x5088), iVar12 == 0)) ||

       ((~*(ushort *)(iVar12 + 0x1e) & 0x1000) == 0)) {

      local_34 = 0.0078125;

    }

    else {

      local_34 = 0.5 / (float)(1 << ((byte)*(undefined4 *)(iVar12 + 0xc) & 0x1f));

    }

    if (DAT_00632ea0 == 0) {

      local_34 = 0.0;

    }

    if ((~DAT_005dc8ce & 0x4000) != 0) {

      local_30 = 4;

      do {

        iVar12 = 0;

        do {

          uVar8 = __ftol();

          (&DAT_005dc8d0)[iVar12] = (uVar8 << 8 | uVar8) << 8 | uVar8;

          iVar12 = iVar12 + 1;

        } while (iVar12 < 0x21);

        iVar12 = 0x20;

        do {

          uVar8 = __ftol();

          (&DAT_005dc8d0)[iVar12] = (uVar8 << 8 | uVar8) << 8 | uVar8;

          iVar12 = iVar12 + 1;

        } while (iVar12 < 0x40);

        local_30 = local_30 + -1;

      } while (local_30 != 0);

      _DAT_005dc8b0 = s_elevation_texture_00561f78;

      _DAT_005dc8b4 = &DAT_005dc8d0;

      _DAT_005dc8b8 = 0;

      _DAT_005dc8bc = 6;

      _DAT_005dc8c0 = 4;

      _DAT_005dc8c8 = 0;

      _DAT_005dc8c4 = 0;

      DAT_005dc8cd = 0;

      DAT_005dc8cc = 0x7f;

      DAT_005dc8ce = 0;

    }

    fVar4 = *(float *)(param_1 + 0x14);

    uVar8 = *(uint *)(param_1 + 0x10);

    local_14 = iVar5 + 0x4ea0;

    local_18 = &DAT_005dc8b0;

    local_10 = 0x124;

    local_c = 0xffffffff;

    (**(code **)(DAT_00656430 + 0x14))(DAT_00656430,&local_18);

    iVar5 = *(int *)(param_1 + 8);

    iVar12 = *(int *)(param_1 + 0xc);

    iVar6 = *(int *)(param_1 + 0x20);

    pfVar9 = (float *)(**(code **)(DAT_0065644c + 0x10))(DAT_0065644c,iVar12 * iVar5);

    fVar7 = (*(float *)(param_1 + 0x3c) - *(float *)(param_1 + 0x38)) / *(float *)(param_1 + 0x3c);

    fVar1 = *(float *)(param_1 + 0x18);

    if (0 < iVar12) {

      iStack_2c = iVar12;

      do {

        iVar13 = param_2 * 0x10 + iVar6;

        pfVar10 = pfVar9;

        iVar11 = iVar5;

        if (0 < iVar5) {

          do {

            *pfVar10 = param_3;

            pfVar9 = pfVar10 + 6;

            pfVar10[1] = param_4;

            fVar2 = *(float *)(iVar13 + (uVar8 ^ 1) * 4);

            fVar3 = *(float *)(iVar13 + uVar8 * 4);

            pfVar10[5] = 0.0;

            fVar2 = fVar7 * fVar3 + (1.0 - fVar7) * fVar2;

            pfVar10[2] = fVar2;

            pfVar10[4] = fVar2 * (0.5 / fVar1) + local_34 + 0.5;

            param_3 = fVar4 + param_3;

            iVar13 = (uint)*(ushort *)(iVar13 + 0xc) * 0x10 + iVar6;

            iVar11 = iVar11 + -1;

            pfVar10 = pfVar9;

          } while (iVar11 != 0);

        }

        param_2 = (uint)*(ushort *)(iVar13 + 0xe);

        param_3 = param_3 - (float)iVar5 * fVar4;

        param_4 = param_4 + fVar4;

        iStack_2c = iStack_2c + -1;

      } while (iStack_2c != 0);

    }

    (**(code **)(DAT_00656420 + 0x18))(DAT_00656420,&DAT_0057c058);

    (**(code **)(DAT_00656430 + 0x10))(DAT_00656430,1);

    (**(code **)(DAT_00656430 + 0xc))(DAT_00656430,0);

    (**(code **)(DAT_00656420 + 0x50))(DAT_00656420,2,0);

    (**(code **)(DAT_0065644c + 0x18))(DAT_0065644c,0);

    (**(code **)(DAT_0065644c + 0x20))

              (DAT_0065644c,(iVar5 * 6 + -6) * (iVar12 + -1),*(undefined4 *)(param_1 + 0x24));

    (**(code **)(DAT_00656420 + 0x50))(DAT_00656420,0,0);

  }

  return;

}

/* ===== MAP_MemGroupSetBase @ 0x00515080 ===== */
void MAP_MemGroupSetBase(int param_1,undefined4 param_2)



{

  *(undefined4 *)(param_1 + 0x48) = param_2;

  return;

}

/* ===== wave_effect_draw @ 0x00515090 ===== */
/* PS2 candidate: wave_effect_draw (conf 0.341) */



void wave_effect_draw(int param_1)



{

  float fVar1;

  int iVar2;

  int iVar3;

  undefined4 *puVar4;

  int iVar5;

  float fVar6;

  float fVar7;

  undefined1 *puVar8;

  float10 extraout_ST0;

  float10 extraout_ST0_00;

  float local_f0;

  float local_ec;

  float local_e8;

  float local_e4;

  float local_e0;

  float local_dc;

  float local_d8;

  float local_d0;

  float local_cc;

  float local_c8;

  int local_c4;

  float local_c0;

  float local_bc;

  float local_b4;

  int local_b0;

  float local_ac [6];

  undefined1 local_94 [136];

  float local_c;

  undefined4 local_8;

  undefined4 local_4;

  

  local_b0 = param_1;

  iVar2 = wave_effect_get_player_position__FP11T_WaveDatasP6OBJECT

                    (&local_b0,*(undefined4 *)(param_1 + 0x48));

  if ((local_c != 0.0) || (*(float *)(param_1 + 0x40) < 0.0 == (*(float *)(param_1 + 0x40) == 0.0)))

  {

    wave_effect_get_player_origin(param_1,iVar2,&local_e0,&local_ec,local_4,local_8);

    if ((iVar2 == 0) || (*(int *)(param_1 + 0x34) == 0)) {

      puVar4 = *(undefined4 **)(param_1 + 0x20);

      for (iVar3 = *(int *)(param_1 + 0xc) * *(int *)(param_1 + 8); iVar3 != 0; iVar3 = iVar3 + -1)

      {

        *puVar4 = 0;

        puVar4[1] = 0;

        puVar4 = puVar4 + 4;

      }

      local_cc = local_e0;

      *(undefined4 *)(param_1 + 0x38) = 0;

      *(undefined4 *)(param_1 + 0x34) = 1;

      local_c8 = local_ec;

      iVar3 = wave_effect_calc_verts(param_1,&local_cc,&local_c8);

      local_c4 = iVar3;

    }

    else {

      local_dc = *(float *)(param_1 + 0x28) - local_e0;

      local_d8 = *(float *)(param_1 + 0x2c) - local_ec;

      local_e4 = local_dc * local_dc + local_d8 * local_d8;

      if (((local_e4 == 0.0) ||

          (local_e4 = (float)((&DAT_005f0a18)[(uint)local_e4 >> 8 & 0xffff] |

                             ((int)local_e4 + 0xc0800000U >> 1) + 0x3f800000 & 0x7f800000),

          local_e4 == 0.0)) || (local_e8 = *(float *)(param_1 + 0x14) / local_e4, 1.0 < local_e8)) {

        local_e8 = 1.0;

      }

      local_f0 = 0.0;

      do {

        fVar6 = local_f0 + local_e8;

        local_f0 = fVar6;

        if (1.0 < fVar6) {

          local_f0 = 1.0;

          local_e8 = local_e8 - (fVar6 - 1.0);

        }

        local_bc = (1.0 - local_f0) * local_d8;

        local_cc = local_dc * (1.0 - local_f0) + local_e0;

        local_c8 = local_bc + local_ec;

        iVar3 = wave_effect_calc_verts(param_1,&local_cc,&local_c8);

        local_c4 = iVar3;

        if (*(int *)(param_1 + 0x30) != iVar3) {

          wave_effect_zero_edges(param_1,iVar3);

          *(int *)(param_1 + 0x30) = iVar3;

        }

      } while (local_f0 < 1.0);

    }

    *(float *)(param_1 + 0x28) = local_e0;

    *(float *)(param_1 + 0x2c) = local_ec;

    *(int *)(param_1 + 0x30) = iVar3;

    if (iVar2 == 0) {

      fVar6 = 0.0;

      local_dc = 0.0;

      local_d8 = 0.0;

    }

    else {

      local_dc = *(float *)(iVar2 + 0xac) - *(float *)(iVar2 + 0xa0);

      local_d8 = *(float *)(iVar2 + 0xb0) - *(float *)(iVar2 + 0xa4);

      fVar6 = *(float *)(iVar2 + 0xb4) - *(float *)(iVar2 + 0xa8);

    }

    fVar1 = local_dc * local_dc + local_d8 * local_d8;

    if (fVar1 == 0.0) {

      local_e4 = 0.0;

    }

    else {

      local_e4 = (float)((&DAT_005f0a18)[(uint)fVar1 >> 8 & 0xffff] |

                        ((int)fVar1 + 0xc0800000U >> 1) + 0x3f800000 & 0x7f800000);

    }

    fVar6 = local_e4 * local_e4 + fVar6 * fVar6;

    if (fVar6 == 0.0) {

      local_ec = 0.0;

    }

    else {

      local_ec = (float)((&DAT_005f0a18)[(uint)fVar6 >> 8 & 0xffff] |

                        ((int)fVar6 + 0xc0800000U >> 1) + 0x3f800000 & 0x7f800000);

    }

    if ((local_e4 == 0.0) || (local_e8 = *(float *)(param_1 + 0x14) / local_e4, 1.0 < local_e8)) {

      local_e8 = 1.0;

    }

    fVar6 = 5.60519e-45;

    local_e4 = 5.60519e-45;

    local_f0 = 0.0;

    do {

      fVar1 = local_f0 + local_e8;

      local_f0 = fVar1;

      if (1.0 < fVar1) {

        local_f0 = 1.0;

        local_e8 = local_e8 - (fVar1 - 1.0);

      }

      local_c0 = local_dc * (1.0 - local_f0);

      local_bc = (1.0 - local_f0) * local_d8;

      if (local_c != 0.0) {

        puVar8 = local_94;

        local_e0 = local_c;

        do {

          iVar2 = *(int *)(param_1 + 8);

          iVar3 = __ftol();

          local_b4 = (float)(extraout_ST0 - (float10)iVar3);

          local_d0 = (float)iVar3;

          iVar5 = __ftol();

          local_d0 = (float)(extraout_ST0_00 - (float10)iVar5);

          terrain_vertex_walk(param_1,((iVar5 + 0x10000000) % *(int *)(param_1 + 0xc)) * iVar2 +

                                      (iVar3 + 0x10000000) % iVar2,

                              local_ec * *(float *)(puVar8 + -0x18) * local_e8,

                              *(undefined4 *)(puVar8 + -0x14),*(undefined4 *)(puVar8 + -0x10),

                              *(undefined4 *)(puVar8 + -0xc),local_b4,local_d0);

          puVar8 = puVar8 + 0x20;

          local_e0 = (float)((int)local_e0 + -1);

        } while (local_e0 != 0.0);

        local_e0 = 0.0;

        fVar6 = local_e4;

        iVar3 = local_c4;

      }

      fVar1 = *(float *)(param_1 + 0x38) - DAT_006328e0 * local_e8;

      *(float *)(param_1 + 0x38) = fVar1;

      fVar7 = local_e4;

      while (fVar1 < 0.0) {

        fVar7 = (float)((int)fVar6 + -1);

        if (fVar6 != 0.0) {

          wave_effect_calc_edges(param_1);

          wave_effect_zero_edges(param_1,iVar3);

        }

        fVar1 = *(float *)(param_1 + 0x38) + *(float *)(param_1 + 0x3c);

        *(float *)(param_1 + 0x38) = fVar1;

        fVar6 = fVar7;

      }

      local_e4 = fVar7;

    } while (local_f0 < 1.0);

    terrain_elevation_gen(param_1,iVar3,local_cc,local_c8);

  }

  return;

}

/* ===== FUN_00515580 @ 0x00515580 ===== */
void FUN_00515580(void)



{

  undefined4 *puVar1;

  undefined4 *puVar2;

  

  puVar2 = (undefined4 *)*DAT_006328f8;

  puVar1 = (undefined4 *)(((undefined4 **)DAT_006328f8 == &DAT_006328f8) - 1 & (uint)DAT_006328f8);

  if (puVar1 != (undefined4 *)0x0) {

    while( true ) {

      if (puVar1[0x12] != 0) {

        wave_effect_draw(puVar1);

      }

      if ((undefined4 **)puVar2 == &DAT_006328f8) break;

      puVar1 = puVar2;

      puVar2 = (undefined4 *)*puVar2;

    }

  }

  return;

}

/* ===== FUN_005155c0 @ 0x005155C0 ===== */
void FUN_005155c0(void)



{

  int iVar1;

  undefined4 *puVar2;

  

  puVar2 = &DAT_005dccd8;

  for (iVar1 = 0x8c; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar2 = 0;

    puVar2 = puVar2 + 1;

  }

  DAT_005dcf08 = 1;

  return;

}

/* ===== object_spawn_class2 @ 0x00515710 ===== */
void object_spawn_class2(int param_1,undefined4 *param_2,float param_3,float param_4,

                        undefined4 param_5)



{

  float fVar1;

  int iVar2;

  int *piVar3;

  int iVar4;

  float10 fVar5;

  

  if (0.0 < param_3) {

    iVar2 = object_allocate_type(*(undefined4 *)(DAT_00632ed8 + 0x1e8),param_5);

    fVar5 = (float10)rndfloatrange(-*(float *)(DAT_00632ed8 + 0x218),

                                   *(undefined4 *)(DAT_00632ed8 + 0x218));

    *(float *)(iVar2 + 0xa0) =

         (float)(fVar5 * (float10)param_4 + (float10)*(float *)(param_1 + 0xa0));

    fVar5 = (float10)rndfloatrange(-*(float *)(DAT_00632ed8 + 0x218),

                                   *(undefined4 *)(DAT_00632ed8 + 0x218));

    fVar1 = *(float *)(param_1 + 0xa4);

    *(undefined4 *)(iVar2 + 0xa8) = 0x3e800000;

    *(float *)(iVar2 + 0xa4) = (float)(fVar5 * (float10)param_4 + (float10)fVar1);

    fVar5 = (float10)rndfloatrange(*(undefined4 *)(DAT_00632ed8 + 0x1f8),

                                   *(undefined4 *)(DAT_00632ed8 + 0x1fc));

    *(float *)(iVar2 + 0xc4) = (float)(fVar5 * (float10)param_3 * (float10)param_4);

    object_copy_posdirinfo(iVar2);

    *param_2 = DAT_006328e8;

    iVar2 = rndintrange(*(int *)(DAT_00632ed8 + 0x200) + -1,*(int *)(DAT_00632ed8 + 0x204) + -1);

    if (0 < iVar2) {

      iVar4 = 0;

      piVar3 = &DAT_005dccd8;

      do {

        if (*piVar3 == 0) break;

        piVar3 = piVar3 + 7;

        iVar4 = iVar4 + 1;

      } while ((int)piVar3 < 0x5dcf08);

      if (iVar4 == 0x14) {

        iVar4 = 0;

      }

      (&DAT_005dccd8)[iVar4 * 7] = iVar2;

      fVar5 = (float10)rndfloatrange(*(undefined4 *)(DAT_00632ed8 + 0x210),

                                     *(undefined4 *)(DAT_00632ed8 + 0x214));

      (&DAT_005dccdc)[iVar4 * 7] = (float)fVar5;

      (&DAT_005dcce0)[iVar4 * 7] = param_3;

      (&DAT_005dcce4)[iVar4 * 7] = param_4;

      (&DAT_005dcce8)[iVar4 * 7] = *(float *)(param_1 + 0xa0);

      (&DAT_005dccec)[iVar4 * 7] = *(undefined4 *)(param_1 + 0xa4);

      *(undefined4 *)(iVar4 * 0x1c + 0x5dccf0) = *(undefined4 *)(param_1 + 0xa8);

    }

  }

  return;

}

/* ===== drip_make @ 0x00515890 ===== */
/* PS2 candidate: drip_make (conf 0.433) */



void drip_make(int param_1,float *param_2,float param_3,float param_4,float param_5,int param_6,

              undefined4 param_7)



{

  float fVar1;

  float *pfVar2;

  undefined4 uVar3;

  int iVar4;

  int iVar5;

  undefined4 *puVar6;

  float10 fVar7;

  float10 fVar8;

  

  pfVar2 = param_2;

  if (DAT_005dcf08 == 0) {

    puVar6 = &DAT_005dccd8;

    for (iVar5 = 0x8c; iVar5 != 0; iVar5 = iVar5 + -1) {

      *puVar6 = 0;

      puVar6 = puVar6 + 1;

    }

    DAT_005dcf08 = 1;

  }

  if (*(float *)(param_1 + 0xa8) <= 0.0) {

    fVar1 = *(float *)(DAT_00632ed8 + 0x208) + *param_2;

    if (fVar1 < DAT_006328e8 != (fVar1 == DAT_006328e8)) {

      param_2 = (float *)0x0;

      if (*(float *)(DAT_00632ed8 + 0x1ec) < param_3 ==

          (*(float *)(DAT_00632ed8 + 0x1ec) == param_3)) {

        iVar5 = ObjIsReaper(param_1);

        if (iVar5 == 0) {

          iVar5 = ObjIsJetski(param_1);

          if ((iVar5 != 0) && ((**(byte **)(param_1 + 0x104) & 0x40) != 0)) {

            param_2 = (float *)0x40000000;

          }

        }

        else if ((**(byte **)(param_1 + 0x104) & 0x40) != 0) {

          param_2 = (float *)0x3f000000;

        }

      }

      else {

        param_2 = (float *)(*(float *)(DAT_00632ed8 + 0x1f0) * param_3);

        if (*(float *)(DAT_00632ed8 + 500) < (float)param_2) {

          param_2 = *(float **)(DAT_00632ed8 + 500);

        }

      }

      uVar3 = param_7;

      if (*(float *)(DAT_00632ed8 + 0x21c) < param_4 !=

          (*(float *)(DAT_00632ed8 + 0x21c) == param_4)) {

        param_4 = *(float *)(DAT_00632ed8 + 0x220) * param_4;

        if (*(float *)(DAT_00632ed8 + 500) < param_4) {

          param_4 = *(float *)(DAT_00632ed8 + 500);

        }

        if ((float)param_2 < param_4) {

          param_2 = (float *)param_4;

        }

      }

      object_spawn_class2(param_1,pfVar2,param_2,param_5,param_7);

      if ((((float)param_2 != 0.0) && (param_6 != 0)) &&

         (iVar5 = rndintrange(*(undefined4 *)(DAT_00632ed8 + 0x224),

                              *(undefined4 *)(DAT_00632ed8 + 0x228)), 0 < iVar5)) {

        do {

          fVar7 = (float10)rndfloatrange(0x3e4ccccd,0x3f333333);

          fVar1 = (float)fVar7;

          fVar7 = (float10)rndfloatrange(*(undefined4 *)(DAT_00632ed8 + 0x234),

                                         *(undefined4 *)(DAT_00632ed8 + 0x238));

          fVar8 = (float10)rndfloat(0x43b40000);

          sine_cos_lookup((float)fVar8,&param_6,&param_7);

          iVar4 = object_allocate_type(0x89,uVar3);

          *(undefined4 *)(iVar4 + 0xa0) = *(undefined4 *)(param_1 + 0xa0);

          *(undefined4 *)(iVar4 + 0xa4) = *(undefined4 *)(param_1 + 0xa4);

          *(undefined4 *)(iVar4 + 0xa8) = 0x3e800000;

          *(float *)(iVar4 + 200) = (float)fVar8;

          *(float *)(iVar4 + 0x108) = fVar1 * *(float *)(iVar4 + 0x1b8) * fVar1 * 0.5;

          *(float *)(iVar4 + 0x10c) = (float)(fVar7 * (float10)param_5) / fVar1;

          object_copy_posdirinfo(iVar4);

          iVar5 = iVar5 + -1;

          *(float *)(iVar4 + 0xc4) = param_5 * 0.5;

        } while (iVar5 != 0);

      }

    }

    return;

  }

  *param_2 = 0.0;

  return;

}

/* ===== FUN_00515b20 @ 0x00515B20 ===== */
/* PS2 candidate: object_water_ripple (conf 0.473) */



void FUN_00515b20(int param_1,undefined4 param_2,undefined4 param_3)



{

  int iVar1;

  undefined4 *puVar2;

  float10 fVar3;

  float10 fVar4;

  

  if (DAT_005dcf08 == 0) {

    puVar2 = &DAT_005dccd8;

    for (iVar1 = 0x8c; iVar1 != 0; iVar1 = iVar1 + -1) {

      *puVar2 = 0;

      puVar2 = puVar2 + 1;

    }

    DAT_005dcf08 = 1;

  }

  fVar3 = (float10)distance3d__FP3P3DT0(param_1 + 0xac,param_1 + 0xa0);

  fVar4 = (float10)FUN_00518b70(param_1,0);

  drip_make(param_1,param_2,(float)((float10)(float)fVar3 / fVar4),ABS(*(float *)(param_1 + 0x114)),

            0x3f800000,1,param_3);

  return;

}

/* ===== object_spawn_class3 @ 0x00515BA0 ===== */
void object_spawn_class3(undefined4 param_1)



{

  float fVar1;

  float fVar2;

  float fVar3;

  int iVar4;

  float *pfVar5;

  float10 fVar6;

  

  pfVar5 = (float *)&DAT_005dcce4;

  do {

    if (pfVar5[-3] != 0.0) {

      fVar1 = pfVar5[-2] - DAT_006328e0;

      pfVar5[-2] = fVar1;

      if (fVar1 < 0.0 != (fVar1 == 0.0)) {

        fVar2 = *pfVar5;

        fVar3 = pfVar5[-1];

        iVar4 = object_allocate_type(*(undefined4 *)(DAT_00632ed8 + 0x1e8),param_1);

        fVar6 = (float10)rndfloatrange(-*(float *)(DAT_00632ed8 + 0x218),

                                       *(undefined4 *)(DAT_00632ed8 + 0x218));

        *(float *)(iVar4 + 0xa0) = (float)(fVar6 * (float10)fVar2 + (float10)pfVar5[1]);

        fVar6 = (float10)rndfloatrange(-*(float *)(DAT_00632ed8 + 0x218),

                                       *(undefined4 *)(DAT_00632ed8 + 0x218));

        fVar1 = pfVar5[2];

        *(undefined4 *)(iVar4 + 0xa8) = 0x3e800000;

        *(float *)(iVar4 + 0xa4) = (float)(fVar6 * (float10)fVar2 + (float10)fVar1);

        fVar6 = (float10)rndfloatrange(*(undefined4 *)(DAT_00632ed8 + 0x1f8),

                                       *(undefined4 *)(DAT_00632ed8 + 0x1fc));

        *(float *)(iVar4 + 0xc4) = (float)(fVar6 * (float10)fVar3 * (float10)fVar2);

        object_copy_posdirinfo(iVar4);

        fVar1 = pfVar5[-3];

        pfVar5[-3] = (float)((int)fVar1 + -1);

        if (0 < (int)fVar1 + -1) {

          fVar6 = (float10)rndfloatrange(*(undefined4 *)(DAT_00632ed8 + 0x210),

                                         *(undefined4 *)(DAT_00632ed8 + 0x214));

          pfVar5[-2] = (float)fVar6;

        }

      }

    }

    pfVar5 = pfVar5 + 7;

  } while ((int)pfVar5 < 0x5dcf14);

  return;

}

/* ===== FUN_00515d90 @ 0x00515D90 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



float10 FUN_00515d90(void)



{

  return (float10)_DAT_0057c0b8;

}

/* ===== FUN_00515da0 @ 0x00515DA0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



float10 FUN_00515da0(void)



{

  return (float10)_DAT_0057c0bc;

}

/* ===== XFGetCameraOrigin @ 0x00515DB0 ===== */
/* PS2 candidate: XFGetCameraOrigin (conf 0.442) */



undefined * XFGetCameraOrigin(void)



{

  return &DAT_005dcf1c;

}

/* ===== XFGetCameraAxis @ 0x00515DC0 ===== */
/* PS2 candidate: XFGetCameraAxis (conf 0.398) */



undefined * XFGetCameraAxis(int param_1)



{

  return &DAT_005dcf28 + param_1 * 0xc;

}

/* ===== FUN_00515dd0 @ 0x00515DD0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



float10 FUN_00515dd0(void)



{

  return (float10)_DAT_005dcf4c;

}

/* ===== render_projection_reset @ 0x00515DE0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void render_projection_reset(float *param_1,float *param_2)



{

  int iVar1;

  undefined4 *puVar2;

  

  puVar2 = &DAT_0057c140;

  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar2 = 0;

    puVar2 = puVar2 + 1;

  }

  DAT_0057c140 = 2.0 / (*param_2 - *param_1);

  _DAT_0057c168 = 0;

  _DAT_0057c17c = 0x3f800000;

  _DAT_0057c154 = 2.0 / (param_2[1] - param_1[1]);

  _DAT_0057c170 = (*param_1 + *param_2) * DAT_0057c140 * -0.5;

  _DAT_0057c178 = 0;

  _DAT_0057c174 = (param_1[1] + param_2[1]) * _DAT_0057c154 * -0.5;

  _DAT_0057c0bc = DAT_0057c140 / _DAT_0057c154;

                    /* WARNING: Could not recover jumptable at 0x00515e89. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  (**(code **)(DAT_00656420 + 0x20))();

  return;

}

/* ===== FNT_StringRender__FPcP14FNT_RenderInfo @ 0x00515E90 ===== */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */



void FNT_StringRender__FPcP14FNT_RenderInfo(char *p0,undefined4 *p1)



{

  DAT_0057c0c0 = p0;

  DAT_0057c0c4 = p1;

  return;

}

/* ===== render_get_clip_nearfar @ 0x00515EB0 ===== */
/* PS2 candidate: fx_free_effect__FP9FXLISTTAG_2 (conf 0.726) */



void render_get_clip_nearfar(undefined4 *param_1,undefined4 *param_2)



{

  *param_1 = DAT_0057c0c0;

  *param_2 = DAT_0057c0c4;

  return;

}

/* ===== AudioMusicStreamPlay__Fiiii @ 0x00515ED0 ===== */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */



void AudioMusicStreamPlay__Fiiii(int p0,int p1,int p2,int p3)



{

  __ftol();

  render_farclip_set();

  return;

}

/* ===== FUN_00515f20 @ 0x00515F20 ===== */
float10 FUN_00515f20(void)



{

  return (float10)DAT_006331bc * (float10)0.07692308;

}

/* ===== ResetFog__Fv @ 0x00515F30 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */



void ResetFog__Fv(void)



{

  _DAT_005dcf5c = 0;

  _DAT_005dcf58 = 0;

  _DAT_005dcf54 = 0;

  DAT_005dcf50 = 0;

  return;

}

/* ===== render_farclip_set @ 0x00515F60 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void render_farclip_set(int param_1)



{

  if (DAT_006330e4 != 0) {

    if (param_1 < 0) {

      param_1 = 0;

    }

    else if (0xc < param_1) {

      param_1 = 0xc;

    }

    DAT_0057c0c4 = (float)(&DAT_0057c0c8)[param_1];

    DAT_006331bc = param_1;

    comm_0051a130(s_FarClipIndex_0055a04c,param_1);

    if ((DAT_005dcf50 == 0.0) && (_DAT_005dcf58 == 0.0)) {

      DAT_005dcf50 = *(float *)(DAT_006330e4 + 0x128);

      _DAT_005dcf58 = *(float *)(DAT_006330e4 + 300);

      _DAT_005dcf54 = *(undefined4 *)(DAT_006330e4 + 0x140);

      _DAT_005dcf5c = *(undefined4 *)(DAT_006330e4 + 0x144);

    }

    *(float *)(DAT_006330e4 + 0x128) = DAT_005dcf50;

    *(float *)(DAT_006330e4 + 300) = _DAT_005dcf58;

    if (DAT_0057c0c4 < *(float *)(DAT_006330e4 + 300)) {

      *(float *)(DAT_006330e4 + 300) = DAT_0057c0c4;

    }

    if (DAT_0057c0c4 * 0.9 < *(float *)(DAT_006330e4 + 0x128)) {

      *(float *)(DAT_006330e4 + 0x128) = DAT_0057c0c4 * 0.9;

    }

    (**(code **)(DAT_00656420 + 0xac))

              (DAT_00656420,*(undefined4 *)(DAT_006330e4 + 0x128),

               *(undefined4 *)(DAT_006330e4 + 300),DAT_006330e4 + 0x130);

  }

  return;

}

/* ===== AudioGetMasterVolume__Fv_8 @ 0x005160A0 ===== */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */



undefined4 AudioGetMasterVolume__Fv_8(void)



{

  return DAT_006331bc;

}

/* ===== render_projection_set @ 0x005160B0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void render_projection_set(float param_1,float param_2,int param_3)



{

  float fVar1;

  float fVar2;

  int iVar3;

  undefined4 *puVar4;

  float10 fVar5;

  float10 fVar6;

  float local_4;

  

  fVar2 = DAT_0057c0c0;

  local_4 = DAT_0057c0c4;

  fVar1 = 12500.0 - (_DAT_005dcf1c * _DAT_005dcf40 +

                    _DAT_005dcf20 * _DAT_005dcf44 + _DAT_005dcf24 * _DAT_005dcf48);

  if ((param_3 == 1) && (fVar1 < DAT_0057c0c4)) {

    local_4 = fVar1;

  }

  _DAT_0057c0b8 = param_1;

  if (param_2 == 0.0) {

    param_2 = DAT_005dcf0c / DAT_005dcf10;

  }

  iVar3 = 0x10;

  fVar5 = (float10)fsin((float10)param_1 * (float10)0.008726646);

  puVar4 = &DAT_0057c140;

  for (; iVar3 != 0; iVar3 = iVar3 + -1) {

    *puVar4 = 0;

    puVar4 = puVar4 + 1;

  }

  _DAT_0057c0bc = param_2;

  _DAT_0057c16c = 0x3f800000;

  _DAT_005dcf4c = (float)fVar5;

  fVar6 = (float10)fcos((float10)param_1 * (float10)0.008726646);

  _DAT_0057c168 = local_4 / (local_4 - fVar2);

  DAT_0057c140 = (float)((fVar6 / (float10)(float)fVar5) / (float10)param_2);

  _DAT_0057c154 = (float)(fVar6 / (float10)(float)fVar5);

  _DAT_0057c178 = -(_DAT_0057c168 * fVar2);

  (**(code **)(DAT_00656420 + 0x20))(DAT_00656420,&DAT_0057c140);

  return;

}

/* ===== XFSetViewportRegion @ 0x005161C0 ===== */
/* PS2 candidate: XFSetViewportRegion (conf 0.587) */



void XFSetViewportRegion(float param_1,float param_2,float param_3,float param_4)



{

  DAT_005dcf0c = param_3 * 0.5;

  DAT_005dcf10 = param_4 * 0.5;

  DAT_005dcf14 = DAT_005dcf0c + param_1;

  DAT_005dcf18 = DAT_005dcf10 + param_2;

  (**(code **)(DAT_00656420 + 0x3c))(DAT_00656420,&DAT_005dcf0c);

  return;

}

/* ===== FUN_00516220 @ 0x00516220 ===== */
void FUN_00516220(undefined4 *param_1)



{

  DAT_005dcf0c = *param_1;

  DAT_005dcf10 = param_1[1];

  DAT_005dcf14 = param_1[2];

  DAT_005dcf18 = param_1[3];

  (**(code **)(DAT_00656420 + 0x3c))(DAT_00656420,&DAT_005dcf0c);

  return;

}

/* ===== XFGetViewport_2 @ 0x00516260 ===== */
/* PS2 candidate: XFGetViewport_2 (conf 0.776) */



void XFGetViewport_2(undefined4 *param_1)



{

  *param_1 = DAT_005dcf0c;

  param_1[1] = DAT_005dcf10;

  param_1[2] = DAT_005dcf14;

  param_1[3] = DAT_005dcf18;

  return;

}

/* ===== Dot__FP3P3DT0 @ 0x00516290 ===== */
/* PS2 candidate: Dot__FP3P3DT0 (conf 0.345) */



float10 Dot__FP3P3DT0(float *param_1,float *param_2)



{

  return (float10)*param_1 * (float10)*param_2 +

         (float10)param_1[1] * (float10)param_2[1] + (float10)param_1[2] * (float10)param_2[2];

}

/* ===== FUN_005162b0 @ 0x005162B0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_005162b0(undefined4 *param_1)



{

  int iVar1;

  undefined4 *puVar2;

  

  puVar2 = &DAT_0057c100;

  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar2 = *param_1;

    param_1 = param_1 + 1;

    puVar2 = puVar2 + 1;

  }

  _DAT_0057c108 = -_DAT_0057c108;

  _DAT_0057c118 = -_DAT_0057c118;

  _DAT_0057c128 = -_DAT_0057c128;

  _DAT_0057c138 = -_DAT_0057c138;

  camera_matrix_from_quat();

  return;

}

/* ===== camera_matrix_from_quat @ 0x00516310 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void camera_matrix_from_quat(float *param_1)



{

  _DAT_005dcf1c =

       ((param_1[3] - param_1[2] * param_1[0xe]) - param_1[0xd] * param_1[1]) -

       param_1[0xc] * *param_1;

  _DAT_005dcf20 =

       ((param_1[7] - param_1[6] * param_1[0xe]) - param_1[0xd] * param_1[5]) -

       param_1[0xc] * param_1[4];

  _DAT_005dcf24 =

       ((param_1[0xb] - param_1[0xe] * param_1[10]) - param_1[0xd] * param_1[9]) -

       param_1[0xc] * param_1[8];

  _DAT_005dcf28 = *param_1;

  _DAT_005dcf2c = param_1[4];

  _DAT_005dcf30 = param_1[8];

  _DAT_005dcf34 = param_1[1];

  _DAT_005dcf38 = param_1[5];

  _DAT_005dcf3c = param_1[9];

  _DAT_005dcf40 = param_1[2];

  _DAT_005dcf44 = param_1[6];

  _DAT_005dcf48 = param_1[10];

  (**(code **)(DAT_00656420 + 0x1c))(DAT_00656420,&DAT_0057c100);

  return;

}

/* ===== FUN_005163e0 @ 0x005163E0 ===== */
void FUN_005163e0(undefined4 *param_1)



{

  int iVar1;

  undefined4 *puVar2;

  undefined4 *puVar3;

  

  puVar2 = &DAT_0057c100;

  puVar3 = param_1;

  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar3 = *puVar2;

    puVar2 = puVar2 + 1;

    puVar3 = puVar3 + 1;

  }

  param_1[2] = -(float)param_1[2];

  param_1[6] = -(float)param_1[6];

  param_1[10] = -(float)param_1[10];

  param_1[0xe] = -(float)param_1[0xe];

  return;

}

/* ===== view_matrix_build @ 0x00516420 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void view_matrix_build(float *param_1,float *param_2,float *param_3)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  

  DAT_0057c1c0 = 1;

  _DAT_0057c108 = *param_2;

  _DAT_0057c118 = param_2[1];

  fVar1 = param_2[2];

  _DAT_0057c128 =

       1.0 / SQRT(_DAT_0057c108 * _DAT_0057c108 + _DAT_0057c118 * _DAT_0057c118 + fVar1 * fVar1);

  _DAT_0057c108 = _DAT_0057c108 * _DAT_0057c128;

  _DAT_0057c118 = _DAT_0057c128 * _DAT_0057c118;

  _DAT_0057c128 = _DAT_0057c128 * fVar1;

  fVar6 = _DAT_0057c128 * param_3[1] - _DAT_0057c118 * param_3[2];

  fVar5 = _DAT_0057c108 * param_3[2] - _DAT_0057c128 * *param_3;

  fVar3 = _DAT_0057c118 * *param_3 - _DAT_0057c108 * param_3[1];

  fVar4 = _DAT_0057c118 * fVar3 - _DAT_0057c128 * fVar5;

  _DAT_0057c114 = _DAT_0057c128 * fVar6 - _DAT_0057c108 * fVar3;

  fVar1 = _DAT_0057c108 * fVar5 - _DAT_0057c118 * fVar6;

  fVar2 = 1.0 / SQRT(fVar6 * fVar6 + fVar5 * fVar5 + fVar3 * fVar3);

  _DAT_0057c124 = 1.0 / SQRT(fVar4 * fVar4 + _DAT_0057c114 * _DAT_0057c114 + fVar1 * fVar1);

  DAT_0057c104 = fVar4 * _DAT_0057c124;

  _DAT_0057c114 = _DAT_0057c114 * _DAT_0057c124;

  _DAT_0057c124 = _DAT_0057c124 * fVar1;

  DAT_0057c100 = -(fVar2 * fVar6);

  _DAT_0057c110 = -(fVar2 * fVar5);

  _DAT_0057c120 = -(fVar2 * fVar3);

  _DAT_0057c130 = fVar2 * fVar6 * *param_1 + fVar2 * fVar5 * param_1[1] + fVar2 * fVar3 * param_1[2]

  ;

  _DAT_0057c134 =

       -(DAT_0057c104 * *param_1 + _DAT_0057c114 * param_1[1] + _DAT_0057c124 * param_1[2]);

  _DAT_0057c10c = 0;

  _DAT_0057c11c = 0;

  _DAT_0057c12c = 0;

  _DAT_0057c13c = 0x3f800000;

  _DAT_0057c138 =

       -(_DAT_0057c108 * *param_1 + _DAT_0057c118 * param_1[1] + _DAT_0057c128 * param_1[2]);

  camera_matrix_from_quat(&DAT_0057c100);

  return;

}

/* ===== XFMatMult @ 0x00516630 ===== */
void XFMatMult(float *param_1,float *param_2,float *param_3)



{

  *param_3 = param_1[3] * param_2[0xc] +

             param_1[1] * param_2[4] + param_2[8] * param_1[2] + *param_1 * *param_2;

  param_3[1] = param_2[0xd] * param_1[3] +

               param_1[1] * param_2[5] + *param_1 * param_2[1] + param_2[9] * param_1[2];

  param_3[2] = param_2[0xe] * param_1[3] +

               param_1[1] * param_2[6] + param_2[10] * param_1[2] + *param_1 * param_2[2];

  param_3[3] = param_2[0xb] * param_1[2] +

               param_2[3] * *param_1 + param_1[1] * param_2[7] + param_1[3] * param_2[0xf];

  param_3[4] = param_1[4] * *param_2 +

               param_2[8] * param_1[6] + param_1[7] * param_2[0xc] + param_1[5] * param_2[4];

  param_3[5] = param_2[9] * param_1[6] +

               param_2[0xd] * param_1[7] + param_1[4] * param_2[1] + param_2[5] * param_1[5];

  param_3[6] = param_1[4] * param_2[2] +

               param_2[10] * param_1[6] + param_2[0xe] * param_1[7] + param_1[5] * param_2[6];

  param_3[7] = param_1[5] * param_2[7] +

               param_1[6] * param_2[0xb] + param_1[7] * param_2[0xf] + param_1[4] * param_2[3];

  param_3[8] = param_1[8] * *param_2 +

               param_2[8] * param_1[10] + param_1[0xb] * param_2[0xc] + param_1[9] * param_2[4];

  param_3[9] = param_2[9] * param_1[10] +

               param_2[0xd] * param_1[0xb] + param_1[8] * param_2[1] + param_2[5] * param_1[9];

  param_3[10] = param_1[8] * param_2[2] +

                param_2[10] * param_1[10] + param_2[0xe] * param_1[0xb] + param_1[9] * param_2[6];

  param_3[0xb] = param_1[9] * param_2[7] +

                 param_1[10] * param_2[0xb] + param_1[0xb] * param_2[0xf] + param_1[8] * param_2[3];

  param_3[0xc] = param_1[0xc] * *param_2 +

                 param_2[8] * param_1[0xe] + param_1[0xf] * param_2[0xc] + param_1[0xd] * param_2[4]

  ;

  param_3[0xd] = param_2[9] * param_1[0xe] +

                 param_2[0xd] * param_1[0xf] + param_1[0xc] * param_2[1] + param_2[5] * param_1[0xd]

  ;

  param_3[0xe] = param_1[0xc] * param_2[2] +

                 param_2[10] * param_1[0xe] +

                 param_2[0xe] * param_1[0xf] + param_1[0xd] * param_2[6];

  param_3[0xf] = param_1[0xd] * param_2[7] +

                 param_1[0xe] * param_2[0xb] +

                 param_1[0xf] * param_2[0xf] + param_1[0xc] * param_2[3];

  return;

}

/* ===== xfmat_mult_a @ 0x00516850 ===== */
void xfmat_mult_a(void)



{

  int iVar1;

  undefined4 *puVar2;

  undefined4 *puVar3;

  

  if (DAT_0057c1c0 != 0) {

    XFMatMult(&DAT_0057c100,&DAT_0057c140,&DAT_0057c180);

    return;

  }

  puVar2 = &DAT_0057c100;

  puVar3 = &DAT_0057c180;

  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar3 = *puVar2;

    puVar2 = puVar2 + 1;

    puVar3 = puVar3 + 1;

  }

  return;

}

/* ===== xfmat_mult_b @ 0x00516890 ===== */
void xfmat_mult_b(void)



{

  int iVar1;

  undefined4 *puVar2;

  undefined4 *puVar3;

  

  if (DAT_0057c1c0 != 0) {

    XFMatMult(&DAT_0057c100,&DAT_0057c140,&DAT_0057c180);

    return;

  }

  puVar2 = &DAT_0057c100;

  puVar3 = &DAT_0057c180;

  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar3 = *puVar2;

    puVar2 = puVar2 + 1;

    puVar3 = puVar3 + 1;

  }

  return;

}

/* ===== AudioDataStreamStatus__Fv_4 @ 0x005168D0 ===== */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */



undefined4 * AudioDataStreamStatus__Fv_4(void)



{

  return &DAT_0057c180;

}

/* ===== AudioDataStreamStatus__Fv_5 @ 0x005168E0 ===== */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */



undefined4 * AudioDataStreamStatus__Fv_5(void)



{

  return &DAT_0057c100;

}

/* ===== hud_clipcode_calc @ 0x005168F0 ===== */
uint hud_clipcode_calc(float *param_1,float *param_2,float *param_3)



{

  float fVar1;

  float fVar2;

  float fVar3;

  uint uVar4;

  

  uVar4 = 0;

  fVar1 = DAT_0057c190 * param_1[1] + DAT_0057c1a0 * param_1[2] + DAT_0057c180 * *param_1 +

          DAT_0057c1b0;

  fVar3 = DAT_0057c194 * param_1[1] + DAT_0057c1a4 * param_1[2] + DAT_0057c184 * *param_1 +

          DAT_0057c1b4;

  fVar2 = DAT_0057c19c * param_1[1] + DAT_0057c1ac * param_1[2] + DAT_0057c18c * *param_1 +

          DAT_0057c1bc;

  if (DAT_0057c0c0 <= fVar2) {

    if (DAT_0057c0c4 < fVar2) {

      uVar4 = 2;

    }

  }

  else {

    uVar4 = 1;

  }

  if (-fVar2 <= fVar1) {

    if (fVar2 < fVar1) {

      uVar4 = uVar4 | 8;

    }

  }

  else {

    uVar4 = uVar4 | 4;

  }

  if (fVar3 < -fVar2) {

    uVar4 = uVar4 | 0x10;

  }

  if (fVar2 < fVar3) {

    uVar4 = uVar4 | 0x20;

  }

  if (fVar2 == 0.0) {

    fVar2 = 1.0;

  }

  *param_2 = DAT_005dcf0c * (1.0 / fVar2) * fVar1 + DAT_005dcf14;

  *param_3 = DAT_005dcf10 * (1.0 / fVar2) * fVar3 + DAT_005dcf18;

  return uVar4;

}

/* ===== hud_screen_project4 @ 0x00516A20 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void hud_screen_project4(float *param_1)



{

  float fVar1;

  float fVar2;

  byte bVar3;

  

  fVar1 = param_1[2] * DAT_0057c1a4 + param_1[1] * DAT_0057c194 + *param_1 * DAT_0057c184 +

          DAT_0057c1b4;

  fVar2 = param_1[2] * DAT_0057c1ac + param_1[1] * DAT_0057c19c + *param_1 * DAT_0057c18c +

          DAT_0057c1bc;

  param_1[3] = param_1[2] * DAT_0057c1a0 + param_1[1] * DAT_0057c190 + *param_1 * DAT_0057c180 +

               DAT_0057c1b0;

  param_1[5] = fVar2;

  param_1[4] = fVar1;

  *(undefined1 *)(param_1 + 0xd) = 0;

  if (DAT_0057c0c0 <= param_1[5]) {

    if (DAT_0057c0c4 < param_1[5]) {

      *(undefined1 *)(param_1 + 0xd) = 2;

    }

  }

  else {

    *(undefined1 *)(param_1 + 0xd) = 1;

  }

  if (-param_1[5] <= param_1[3]) {

    if (param_1[3] <= param_1[5]) goto LAB_00516ae2;

    bVar3 = *(byte *)(param_1 + 0xd) | 8;

  }

  else {

    bVar3 = *(byte *)(param_1 + 0xd) | 4;

  }

  *(byte *)(param_1 + 0xd) = bVar3;

LAB_00516ae2:

  if (param_1[4] < -param_1[5]) {

    *(byte *)(param_1 + 0xd) = *(byte *)(param_1 + 0xd) | 0x10;

  }

  if (param_1[5] < param_1[4]) {

    *(byte *)(param_1 + 0xd) = *(byte *)(param_1 + 0xd) | 0x20;

  }

  if (*(char *)(param_1 + 0xd) == '\0') {

    param_1[9] = 1.0 / param_1[5];

    param_1[6] = (1.0 / param_1[5]) * param_1[3] * DAT_005dcf0c + DAT_005dcf14 + _DAT_0057c1c8;

    param_1[6] = param_1[6] - _DAT_0057c1c8;

    param_1[7] = param_1[4] * param_1[9] * DAT_005dcf10 + DAT_005dcf18 + _DAT_0057c1c8;

    param_1[7] = param_1[7] - _DAT_0057c1c8;

  }

  return;

}

/* ===== textrender_node_transform @ 0x00516B60 ===== */
void textrender_node_transform

               (float *param_1,float param_2,float param_3,float param_4,float param_5,float param_6

               ,int param_7)



{

  float fVar1;

  float fVar2;

  bool bVar3;

  float in_ECX;

  float10 fVar4;

  undefined4 local_4;

  

  bVar3 = param_6 == 0.0;

  local_4 = in_ECX;

  if (!bVar3) {

    fVar4 = (float10)fsin((float10)param_6);

    local_4 = (float)fVar4;

    fVar4 = (float10)fcos((float10)param_6);

    param_6 = (float)fVar4;

  }

  for (; param_7 != 0; param_7 = param_7 + -1) {

    if (bVar3) {

      fVar1 = *param_1;

      fVar2 = param_1[1];

    }

    else {

      fVar1 = param_6 * *param_1 - local_4 * param_1[1];

      fVar2 = param_6 * param_1[1] + local_4 * *param_1;

    }

    param_1[6] = fVar1 * param_2 + param_4;

    param_1[7] = fVar2 * param_3 + param_5;

    param_1 = param_1 + 0xe;

  }

  return;

}

/* ===== xform_view @ 0x00516BF0 ===== */
void xform_view(float *param_1,float *param_2)



{

  *param_2 = DAT_0057c190 * param_1[1] + DAT_0057c1a0 * param_1[2] + DAT_0057c180 * *param_1 +

             DAT_0057c1b0;

  param_2[1] = DAT_0057c194 * param_1[1] + DAT_0057c1a4 * param_1[2] + DAT_0057c184 * *param_1 +

               DAT_0057c1b4;

  param_2[2] = DAT_0057c19c * param_1[1] + DAT_0057c1ac * param_1[2] + DAT_0057c18c * *param_1 +

               DAT_0057c1bc;

  return;

}

/* ===== clipcode_z_calc @ 0x00516C70 ===== */
void clipcode_z_calc(int param_1)



{

  byte bVar1;

  

  *(undefined1 *)(param_1 + 0x34) = 0;

  if (DAT_0057c0c0 <= *(float *)(param_1 + 0x14)) {

    if (DAT_0057c0c4 < *(float *)(param_1 + 0x14)) {

      *(undefined1 *)(param_1 + 0x34) = 2;

    }

  }

  else {

    *(undefined1 *)(param_1 + 0x34) = 1;

  }

  if (-*(float *)(param_1 + 0x14) <= *(float *)(param_1 + 0xc)) {

    if (*(float *)(param_1 + 0xc) <= *(float *)(param_1 + 0x14)) goto LAB_00516ccd;

    bVar1 = *(byte *)(param_1 + 0x34) | 8;

  }

  else {

    bVar1 = *(byte *)(param_1 + 0x34) | 4;

  }

  *(byte *)(param_1 + 0x34) = bVar1;

LAB_00516ccd:

  if (*(float *)(param_1 + 0x10) < -*(float *)(param_1 + 0x14)) {

    *(byte *)(param_1 + 0x34) = *(byte *)(param_1 + 0x34) | 0x10;

  }

  if (*(float *)(param_1 + 0x14) < *(float *)(param_1 + 0x10)) {

    *(byte *)(param_1 + 0x34) = *(byte *)(param_1 + 0x34) | 0x20;

  }

  return;

}

/* ===== dlog_alpha_scale_verts @ 0x00516CF0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void dlog_alpha_scale_verts(int param_1)



{

  float *pfVar1;

  float fVar2;

  float fVar3;

  float *pfVar4;

  

  fVar2 = 1.0 / *(float *)(param_1 + 0x14);

  pfVar1 = (float *)(param_1 + 0x18);

  pfVar4 = (float *)(param_1 + 0x1c);

  *(float *)(param_1 + 0x24) = fVar2;

  fVar3 = fVar2 * *(float *)(param_1 + 0xc);

  *pfVar1 = fVar3;

  fVar2 = fVar2 * *(float *)(param_1 + 0x10);

  *pfVar4 = fVar2;

  *pfVar1 = fVar3 * DAT_005dcf0c;

  *pfVar4 = fVar2 * DAT_005dcf10;

  *pfVar1 = DAT_005dcf14 + *pfVar1;

  *pfVar4 = DAT_005dcf18 + *pfVar4;

  *pfVar1 = *pfVar1 + _DAT_0057c1c4;

  *pfVar4 = *pfVar4 + _DAT_0057c1c4;

  *pfVar1 = *pfVar1 - _DAT_0057c1c4;

  *pfVar4 = *pfVar4 - _DAT_0057c1c4;

  return;

}

/* ===== verts_transform @ 0x00516D80 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void verts_transform(int param_1,int param_2)



{

  float *pfVar1;

  float fVar2;

  byte bVar3;

  float *pfVar4;

  int iVar5;

  byte *pbVar6;

  

  if (0 < param_1) {

    pfVar4 = (float *)(param_2 + 8);

    iVar5 = param_1;

    do {

      iVar5 = iVar5 + -1;

      pfVar4[1] = DAT_0057c180 * pfVar4[-2] + DAT_0057c190 * pfVar4[-1] + DAT_0057c1a0 * *pfVar4 +

                  DAT_0057c1b0;

      pfVar4[2] = DAT_0057c184 * pfVar4[-2] + DAT_0057c194 * pfVar4[-1] + DAT_0057c1a4 * *pfVar4 +

                  DAT_0057c1b4;

      pfVar4[3] = DAT_0057c18c * pfVar4[-2] + DAT_0057c19c * pfVar4[-1] + DAT_0057c1ac * *pfVar4 +

                  DAT_0057c1bc;

      pfVar4 = pfVar4 + 0xe;

    } while (iVar5 != 0);

    if (0 < param_1) {

      pbVar6 = (byte *)(param_2 + 0x34);

      do {

        *pbVar6 = 0;

        if (DAT_0057c0c0 <= *(float *)(pbVar6 + -0x20)) {

          if (DAT_0057c0c4 < *(float *)(pbVar6 + -0x20)) {

            *pbVar6 = 2;

          }

        }

        else {

          *pbVar6 = 1;

        }

        if (-*(float *)(pbVar6 + -0x20) <= *(float *)(pbVar6 + -0x28)) {

          if (*(float *)(pbVar6 + -0x20) < *(float *)(pbVar6 + -0x28)) {

            bVar3 = *pbVar6 | 8;

            goto LAB_00516e72;

          }

        }

        else {

          bVar3 = *pbVar6 | 4;

LAB_00516e72:

          *pbVar6 = bVar3;

        }

        if (*(float *)(pbVar6 + -0x24) < -*(float *)(pbVar6 + -0x20)) {

          *pbVar6 = *pbVar6 | 0x10;

        }

        if (*(float *)(pbVar6 + -0x20) < *(float *)(pbVar6 + -0x24)) {

          *pbVar6 = *pbVar6 | 0x20;

        }

        if (*pbVar6 == 0) {

          pfVar4 = (float *)(pbVar6 + -0x1c);

          fVar2 = 1.0 / *(float *)(pbVar6 + -0x20);

          pfVar1 = (float *)(pbVar6 + -0x18);

          *(float *)(pbVar6 + -0x10) = fVar2;

          *pfVar4 = fVar2 * *(float *)(pbVar6 + -0x28);

          *pfVar1 = fVar2 * *(float *)(pbVar6 + -0x24);

          *pfVar4 = fVar2 * *(float *)(pbVar6 + -0x28) * DAT_005dcf0c;

          *pfVar1 = fVar2 * *(float *)(pbVar6 + -0x24) * DAT_005dcf10;

          *pfVar4 = DAT_005dcf14 + *pfVar4;

          *pfVar1 = DAT_005dcf18 + *pfVar1;

          *pfVar4 = *pfVar4 + _DAT_0057c1c4;

          *pfVar1 = *pfVar1 + _DAT_0057c1c4;

          *pfVar4 = *pfVar4 - _DAT_0057c1c4;

          *pfVar1 = *pfVar1 - _DAT_0057c1c4;

        }

        pbVar6 = pbVar6 + 0x38;

        param_1 = param_1 + -1;

      } while (param_1 != 0);

    }

  }

  return;

}

/* ===== xform_p3d_world_mat @ 0x00516F30 ===== */
void xform_p3d_world_mat(int param_1,undefined4 param_2)



{

  math_euler_to_matrix

            (*(undefined4 *)(param_1 + 0xd0),*(undefined4 *)(param_1 + 0xcc),

             *(undefined4 *)(param_1 + 200),*(undefined4 *)(param_1 + 0xc4),param_2);

  return;

}

/* ===== math_euler_to_matrix @ 0x00516F60 ===== */
void math_euler_to_matrix

               (undefined4 param_1,float param_2,undefined4 param_3,float param_4,float *param_5)



{

  float local_14;

  float local_10;

  float local_c;

  float local_8;

  float local_4;

  

  sine_cos_lookup(-param_2,&param_2,&local_14);

  sine_cos_lookup(param_1,&local_4,&local_8);

  sine_cos_lookup(param_3,&local_10,&local_c);

  *param_5 = local_c * local_8 * param_4;

  param_5[1] = (-(param_2 * local_c * local_4) - local_10 * local_14) * param_4;

  param_5[2] = (local_10 * param_2 - local_c * local_4 * local_14) * param_4;

  param_5[3] = local_10 * local_8 * param_4;

  param_5[4] = (local_c * local_14 - local_10 * local_4 * param_2) * param_4;

  param_5[5] = (-(local_10 * local_4 * local_14) - local_c * param_2) * param_4;

  param_5[6] = local_4 * param_4;

  param_5[7] = local_8 * param_2 * param_4;

  param_5[8] = local_8 * local_14 * param_4;

  return;

}

/* ===== xform_p3d_mat33 @ 0x00517080 ===== */
void xform_p3d_mat33(float *param_1,float *param_2,float *param_3,float *param_4)



{

  *param_4 = *param_1 * *param_3 + param_1[1] * param_3[1] + param_1[2] * param_3[2] + *param_2;

  param_4[1] = param_1[4] * param_3[1] + param_1[3] * *param_3 + param_1[5] * param_3[2] +

               param_2[1];

  param_4[2] = param_1[7] * param_3[1] + param_1[6] * *param_3 + param_1[8] * param_3[2] +

               param_2[2];

  return;

}

/* ===== xformobj_p3d_world @ 0x005170F0 ===== */
/* PS2 candidate: object_get_ref_point__FP6OBJECTP7f32vec3Ui (conf 0.408) */



void xformobj_p3d_world(int param_1,float *param_2,float *param_3)



{

  float local_24;

  float local_20;

  float local_1c;

  float local_18;

  float local_14;

  float local_10;

  float local_c;

  float local_8;

  float local_4;

  

  if ((*(byte *)(param_1 + 0xd8) & 0x20) != 0) {

    *param_3 = *(float *)(param_1 + 0x29c) * param_2[1] +

               *(float *)(param_1 + 0x298) * *param_2 + *(float *)(param_1 + 0x2a0) * param_2[2] +

               *(float *)(param_1 + 0x2a4);

    param_3[1] = *(float *)(param_1 + 0x2ac) * param_2[1] +

                 *(float *)(param_1 + 0x2a8) * *param_2 + *(float *)(param_1 + 0x2b0) * param_2[2] +

                 *(float *)(param_1 + 0x2b4);

    param_3[2] = *(float *)(param_1 + 700) * param_2[1] +

                 *(float *)(param_1 + 0x2b8) * *param_2 + *(float *)(param_1 + 0x2c0) * param_2[2] +

                 *(float *)(param_1 + 0x2c4);

    return;

  }

  math_euler_to_matrix

            (*(undefined4 *)(param_1 + 0xd0),*(undefined4 *)(param_1 + 0xcc),

             *(undefined4 *)(param_1 + 200),*(undefined4 *)(param_1 + 0xc4),&local_24);

  *param_3 = local_24 * *param_2 + local_20 * param_2[1] + local_1c * param_2[2] +

             *(float *)(param_1 + 0xa0);

  param_3[1] = local_18 * *param_2 + local_14 * param_2[1] + local_10 * param_2[2] +

               *(float *)(param_1 + 0xa4);

  param_3[2] = local_c * *param_2 + local_8 * param_2[1] + local_4 * param_2[2] +

               *(float *)(param_1 + 0xa8);

  return;

}

/* ===== xformobj_world_local @ 0x00517220 ===== */
/* PS2 candidate: xformobj_world_local (conf 0.538) */



void xformobj_world_local(int param_1,float *param_2,float *param_3)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float local_44;

  float local_40;

  float local_3c;

  float local_38;

  float local_34;

  float local_30;

  float local_2c;

  float local_28;

  float local_24;

  float fStack_20;

  float fStack_1c;

  float fStack_18;

  float fStack_14;

  

  if ((*(byte *)(param_1 + 0xd8) & 0x20) != 0) {

    (*(code *)PTR_crt_matrix_copy_init_00580c1c)(&local_44,param_1 + 0x294);

    *param_3 = local_40 * *param_2 + local_3c * param_2[1] + local_38 * param_2[2] + local_34;

    param_3[1] = local_30 * *param_2 + local_2c * param_2[1] + local_28 * param_2[2] + local_24;

    param_3[2] = fStack_20 * *param_2 + fStack_1c * param_2[1] + fStack_18 * param_2[2] + fStack_14;

    return;

  }

  fVar1 = *param_2 - *(float *)(param_1 + 0xa0);

  fVar2 = param_2[1] - *(float *)(param_1 + 0xa4);

  fVar3 = param_2[2] - *(float *)(param_1 + 0xa8);

  math_euler_to_matrix

            (*(undefined4 *)(param_1 + 0xd0),*(undefined4 *)(param_1 + 0xcc),

             *(undefined4 *)(param_1 + 200),1.0 / *(float *)(param_1 + 0xc4),&local_44);

  *param_3 = local_44 * fVar1 + local_38 * fVar2 + local_2c * fVar3;

  param_3[1] = local_40 * fVar1 + local_34 * fVar2 + local_28 * fVar3;

  param_3[2] = local_3c * fVar1 + local_30 * fVar2 + local_24 * fVar3;

  return;

}

/* ===== hud_screen_project @ 0x00517370 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void hud_screen_project(float *param_1,float *param_2)



{

  float *pfVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  byte bVar5;

  float *pfVar6;

  

  fVar2 = DAT_0057c194 * param_1[1] + DAT_0057c1a4 * param_1[2] + DAT_0057c184 * *param_1 +

          DAT_0057c1b4;

  fVar3 = DAT_0057c19c * param_1[1] + DAT_0057c1ac * param_1[2] + DAT_0057c18c * *param_1 +

          DAT_0057c1bc;

  fVar4 = DAT_0057c190 * param_1[1] + DAT_0057c1a0 * param_1[2] + DAT_0057c180 * *param_1 +

          DAT_0057c1b0;

  *(undefined1 *)(param_2 + 0xd) = 0;

  param_2[3] = fVar4 + *param_2;

  fVar2 = fVar2 + param_2[2];

  param_2[4] = fVar2;

  fVar3 = fVar3 + param_2[1];

  param_2[5] = fVar3;

  if (DAT_0057c0c0 <= fVar3) {

    if (DAT_0057c0c4 < fVar3) {

      *(undefined1 *)(param_2 + 0xd) = 2;

    }

  }

  else {

    *(undefined1 *)(param_2 + 0xd) = 1;

  }

  if (-fVar3 <= param_2[3]) {

    if (param_2[3] <= fVar3) goto LAB_0051744c;

    bVar5 = *(byte *)(param_2 + 0xd) | 8;

  }

  else {

    bVar5 = *(byte *)(param_2 + 0xd) | 4;

  }

  *(byte *)(param_2 + 0xd) = bVar5;

LAB_0051744c:

  if (fVar2 < -fVar3) {

    *(byte *)(param_2 + 0xd) = *(byte *)(param_2 + 0xd) | 0x10;

  }

  if (fVar3 < fVar2) {

    *(byte *)(param_2 + 0xd) = *(byte *)(param_2 + 0xd) | 0x20;

  }

  if (*(char *)(param_2 + 0xd) == '\0') {

    fVar3 = 1.0 / fVar3;

    pfVar1 = param_2 + 6;

    pfVar6 = param_2 + 7;

    param_2[9] = fVar3;

    *pfVar1 = fVar3 * param_2[3];

    *pfVar6 = fVar3 * fVar2;

    *pfVar1 = fVar3 * param_2[3] * DAT_005dcf0c;

    *pfVar6 = fVar3 * fVar2 * DAT_005dcf10;

    *pfVar1 = DAT_005dcf14 + *pfVar1;

    *pfVar6 = DAT_005dcf18 + *pfVar6;

    *pfVar1 = *pfVar1 + _DAT_0057c1c4;

    *pfVar6 = *pfVar6 + _DAT_0057c1c4;

    *pfVar1 = *pfVar1 - _DAT_0057c1c4;

    *pfVar6 = *pfVar6 - _DAT_0057c1c4;

    return;

  }

  return;

}

/* ===== textrender_3d_project @ 0x00517510 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void textrender_3d_project

               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,

               float *param_5,int param_6,int param_7)



{

  float *pfVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  byte bVar5;

  float *pfVar6;

  byte *pbVar7;

  int iVar8;

  float local_24;

  float local_20;

  float local_1c;

  float local_18;

  float local_14;

  float local_10;

  float local_c;

  float local_8;

  float local_4;

  

  math_euler_to_matrix(param_3,param_2,param_1,param_4,&local_24);

  if (0 < param_6) {

    pfVar6 = (float *)(param_7 + 4);

    iVar8 = param_6;

    do {

      iVar8 = iVar8 + -1;

      fVar2 = local_20 * *pfVar6 + local_1c * pfVar6[1] + local_24 * pfVar6[-1] + *param_5;

      fVar4 = local_14 * *pfVar6 + local_10 * pfVar6[1] + local_18 * pfVar6[-1] + param_5[1];

      fVar3 = local_8 * *pfVar6 + local_4 * pfVar6[1] + local_c * pfVar6[-1] + param_5[2];

      pfVar6[2] = DAT_0057c180 * fVar2 + DAT_0057c190 * fVar4 + DAT_0057c1a0 * fVar3 + DAT_0057c1b0;

      pfVar6[3] = DAT_0057c184 * fVar2 + DAT_0057c194 * fVar4 + DAT_0057c1a4 * fVar3 + DAT_0057c1b4;

      pfVar6[4] = DAT_0057c18c * fVar2 + DAT_0057c19c * fVar4 + DAT_0057c1ac * fVar3 + DAT_0057c1bc;

      pfVar6 = pfVar6 + 0xe;

    } while (iVar8 != 0);

    if (0 < param_6) {

      pbVar7 = (byte *)(param_7 + 0x34);

      do {

        *pbVar7 = 0;

        if (DAT_0057c0c0 <= *(float *)(pbVar7 + -0x20)) {

          if (DAT_0057c0c4 < *(float *)(pbVar7 + -0x20)) {

            *pbVar7 = 2;

          }

        }

        else {

          *pbVar7 = 1;

        }

        if (-*(float *)(pbVar7 + -0x20) <= *(float *)(pbVar7 + -0x28)) {

          if (*(float *)(pbVar7 + -0x20) < *(float *)(pbVar7 + -0x28)) {

            bVar5 = *pbVar7 | 8;

            goto LAB_00517681;

          }

        }

        else {

          bVar5 = *pbVar7 | 4;

LAB_00517681:

          *pbVar7 = bVar5;

        }

        if (*(float *)(pbVar7 + -0x24) < -*(float *)(pbVar7 + -0x20)) {

          *pbVar7 = *pbVar7 | 0x10;

        }

        if (*(float *)(pbVar7 + -0x20) < *(float *)(pbVar7 + -0x24)) {

          *pbVar7 = *pbVar7 | 0x20;

        }

        if (*pbVar7 == 0) {

          pfVar6 = (float *)(pbVar7 + -0x1c);

          fVar2 = 1.0 / *(float *)(pbVar7 + -0x20);

          pfVar1 = (float *)(pbVar7 + -0x18);

          *(float *)(pbVar7 + -0x10) = fVar2;

          *pfVar6 = fVar2 * *(float *)(pbVar7 + -0x28);

          *pfVar1 = fVar2 * *(float *)(pbVar7 + -0x24);

          *pfVar6 = fVar2 * *(float *)(pbVar7 + -0x28) * DAT_005dcf0c;

          *pfVar1 = fVar2 * *(float *)(pbVar7 + -0x24) * DAT_005dcf10;

          *pfVar6 = DAT_005dcf14 + *pfVar6;

          *pfVar1 = DAT_005dcf18 + *pfVar1;

          *pfVar6 = *pfVar6 + _DAT_0057c1c4;

          *pfVar1 = *pfVar1 + _DAT_0057c1c4;

          *pfVar6 = *pfVar6 - _DAT_0057c1c4;

          *pfVar1 = *pfVar1 - _DAT_0057c1c4;

        }

        pbVar7 = pbVar7 + 0x38;

        param_6 = param_6 + -1;

      } while (param_6 != 0);

    }

  }

  return;

}

/* ===== hud_world_to_screen_2 @ 0x00517770 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void hud_world_to_screen_2(float *param_1,float *param_2)



{

  float fVar1;

  float fVar2;

  float fVar3;

  

  fVar1 = param_1[2];

  fVar2 = (((*param_1 - DAT_005dcf14) / DAT_005dcf0c) * fVar1) / DAT_0057c140 - _DAT_0057c130;

  fVar3 = (((param_1[1] - DAT_005dcf18) / DAT_005dcf10) * fVar1) / _DAT_0057c154 - _DAT_0057c134;

  fVar1 = fVar1 / _DAT_0057c16c - _DAT_0057c138;

  *param_2 = DAT_0057c100 * fVar2 + _DAT_0057c108 * fVar1 + DAT_0057c104 * fVar3;

  param_2[1] = _DAT_0057c110 * fVar2 + _DAT_0057c118 * fVar1 + _DAT_0057c114 * fVar3;

  param_2[2] = _DAT_0057c120 * fVar2 + _DAT_0057c128 * fVar1 + _DAT_0057c124 * fVar3;

  return;

}

/* ===== FUN_00517830 @ 0x00517830 ===== */
undefined4 FUN_00517830(int param_1,int param_2,int param_3)



{

  int iVar1;

  undefined4 *puVar2;

  int iVar3;

  undefined4 *puVar4;

  int iVar5;

  undefined4 *puVar6;

  undefined4 *puVar7;

  

  iVar1 = *(int *)(param_3 * 0x50 + 0x88 + param_1);

  iVar5 = *(int *)(param_3 * 0x50 + param_1 + 0x8c);

  puVar2 = (undefined4 *)(**(code **)(DAT_0065643c + 0x10))(DAT_0065643c,iVar5);

  if (iVar5 != 0) {

    puVar4 = (undefined4 *)(param_2 + iVar1 * 0x38 + 0x18);

    do {

      iVar5 = iVar5 + -1;

      puVar6 = puVar4;

      puVar7 = puVar2;

      for (iVar3 = 7; iVar3 != 0; iVar3 = iVar3 + -1) {

        *puVar7 = *puVar6;

        puVar6 = puVar6 + 1;

        puVar7 = puVar7 + 1;

      }

      puVar2 = puVar2 + 7;

      puVar4 = puVar4 + 0xe;

    } while (iVar5 != 0);

  }

  (**(code **)(DAT_0065643c + 0x18))(DAT_0065643c,-iVar1);

  return 0;

}

/* ===== binfile_create_open @ 0x005178A0 ===== */
uint binfile_create_open(LPCSTR param_1)



{

  HANDLE pvVar1;

  

  pvVar1 = CreateFileA(param_1,0x80000000,1,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);

  return (uint)pvVar1 & (pvVar1 == (HANDLE)0xffffffff) - 1;

}

/* ===== BinFileRead @ 0x005178D0 ===== */
/* PS2 candidate: BinFileRead (conf 0.72) */



DWORD BinFileRead(HANDLE param_1,LPVOID param_2,DWORD param_3)



{

  ReadFile(param_1,param_2,param_3,&param_3,(LPOVERLAPPED)0x0);

  return param_3;

}

/* ===== binfile_write @ 0x00517900 ===== */
DWORD binfile_write(HANDLE param_1,LPCVOID param_2,DWORD param_3)



{

  WriteFile(param_1,param_2,param_3,&param_3,(LPOVERLAPPED)0x0);

  return param_3;

}

/* ===== sceSifLoadElf @ 0x00517930 ===== */
void sceSifLoadElf(HANDLE param_1,LONG param_2)



{

  SetFilePointer(param_1,param_2,(PLONG)0x0,0);

  return;

}

/* ===== sceSifLoadElf_2 @ 0x00517950 ===== */
void sceSifLoadElf_2(HANDLE param_1,LONG param_2)



{

  SetFilePointer(param_1,param_2,(PLONG)0x0,1);

  return;

}

/* ===== binfile_seek_cur @ 0x00517970 ===== */
/* PS2 candidate: changeInputVolume__FUi (conf 0.631) */



void binfile_seek_cur(HANDLE param_1)



{

  SetFilePointer(param_1,0,(PLONG)0x0,1);

  return;

}

/* ===== binfile_seek @ 0x00517990 ===== */
DWORD binfile_seek(HANDLE param_1)



{

  DWORD lDistanceToMove;

  DWORD DVar1;

  

  lDistanceToMove = SetFilePointer(param_1,0,(PLONG)0x0,1);

  SetFilePointer(param_1,0,(PLONG)0x0,2);

  DVar1 = SetFilePointer(param_1,0,(PLONG)0x0,1);

  SetFilePointer(param_1,lDistanceToMove,(PLONG)0x0,0);

  return DVar1;

}

/* ===== ANM_BinderDestroy_2 @ 0x005179D0 ===== */
void ANM_BinderDestroy_2(HANDLE param_1)



{

  CloseHandle(param_1);

  return;

}

/* ===== tracer_set_text @ 0x00517A10 ===== */
/* PS2 candidate: tracer_add_trail (conf 0.768) */



void tracer_set_text(LPCSTR param_1)



{

  CHAR local_100 [256];

  

  local_100[0] = '\0';

  wvsprintfA(local_100,param_1,&stack0x00000008);

  lstrcatA(local_100,&DAT_0057c1f8);

  lstrcpyA(&DAT_005dd970,local_100);

  return;

}

/* ===== di_error_trace @ 0x00517A60 ===== */
/* PS2 candidate: AudioMusicStreamResume__Fv (conf 0.579) */



void di_error_trace(undefined4 param_1)



{

  undefined4 uVar1;

  

  uVar1 = di_error_name(DAT_005ddb7c);

  tracer_set_text(param_1,uVar1);

  return;

}

/* ===== _GLOBAL_$D$Game @ 0x00517A80 ===== */
void _GLOBAL__D_Game(void)



{

  dbg_error_printf(&DAT_00555df0,&DAT_005dd970);

  return;

}

/* ===== di_error_name @ 0x00517AA0 ===== */
/* PS2 candidate: PickupTypeToIcon__Fi (conf 0.588) */



char * di_error_name(int param_1)



{

  char *pcVar1;

  

  if (param_1 < -0x7ff8fffd) {

    if (param_1 == -0x7ff8fffe) {

      return s_DIERR_NOTFOUND_0057c30c;

    }

    if (param_1 < -0x7ffbfdfd) {

      if (param_1 == -0x7ffbfdfe) {

        return s_DIERR_MOREDATA_0057c3a0;

      }

      if (param_1 < -0x7ffbfeef) {

        if (param_1 == -0x7ffbfef0) {

          return s_DIERR_NOAGGREGATION_0057c3d8;

        }

        if (param_1 == -0x7fffbfff) {

          return s_DIERR_UNSUPPORTED_0057c3ec;

        }

        if (param_1 == -0x7fffbffe) {

          return s_DIERR_NOINTERFACE_0057c400;

        }

        if (param_1 == -0x7fffbffb) {

          return s_DIERR_GENERIC_0057c414;

        }

      }

      else {

        if (param_1 == -0x7ffbfeac) {

          return s_DIERR_DEVICENOTREG_0057c3b0;

        }

        if (param_1 == -0x7ffbfdff) {

          return s_DIERR_DEVICEFULL_0057c3c4;

        }

      }

    }

    else {

      switch(param_1) {

      case -0x7ffbfdfd:

        return s_DIERR_NOTDOWNLOADED_0057c338;

      case -0x7ffbfdfc:

        return s_DIERR_HASEFFECTS_0057c378;

      case -0x7ffbfdfb:

        return s_DIERR_NOTEXCLUSIVEACQUIRED_0057c31c;

      case -0x7ffbfdfa:

        return s_DIERR_INCOMPLETEEFFECT_0057c360;

      case -0x7ffbfdf9:

        return s_DIERR_NOTBUFFERED_0057c34c;

      case -0x7ffbfdf8:

        return s_DIERR_EFFECTPLAYING_0057c38c;

      }

    }

  }

  else if (param_1 < -0x7ff8ff88) {

    if (param_1 == -0x7ff8ff89) {

      return s_DIERR_BADDRIVERVER_0057c280;

    }

    switch(param_1) {

    case -0x7ff8fffb:

      return s_DIERR_HANDLEEXISTS_0057c2f8;

    case -0x7ff8fff4:

      return s_DIERR_NOTACQUIRED_0057c2c0;

    case -0x7ff8fff2:

      return s_DIERR_OUTOFMEMORY_0057c294;

    case -0x7ff8ffeb:

      return s_DIERR_NOTINITIALIZED_0057c2a8;

    case -0x7ff8ffe2:

      return s_DIERR_INPUTLOST_0057c2e8;

    case -0x7ff8ffa9:

      return s_DIERR_INVALIDPARAM_0057c2d4;

    }

  }

  else if (param_1 < -0x7ff8fb7e) {

    if (param_1 == -0x7ff8fb7f) {

      return s_DIERR_BETADIRECTINPUTVERSION_0057c234;

    }

    if (param_1 == -0x7ff8ff56) {

      return s_DIERR_ACQUIRED_0057c254;

    }

    if (param_1 == -0x7ff8fb82) {

      return s_DIERR_OLDDIRECTINPUTVERSION_0057c264;

    }

  }

  else {

    if (param_1 == -0x7ff8fb21) {

      return s_DIERR_ALREADYINITIALIZED_0057c1fc;

    }

    if (param_1 == 0) {

      pcVar1 = (char *)FUN_00507b00();

      return pcVar1;

    }

  }

  wsprintfA(&DAT_005dcf68,s_Unknown_0x_X_0057c224,param_1);

  return &DAT_005dcf68;

}

/* ===== exception_report_write @ 0x00517CA0 ===== */
undefined4 exception_report_write(int *param_1,undefined4 param_2)



{

  int *piVar1;

  LPSTR pCVar2;

  DWORD DVar3;

  char *pcVar4;

  HANDLE hFile;

  SIZE_T SVar5;

  uint uVar6;

  char *pcVar7;

  BOOL BVar8;

  undefined2 *puVar9;

  int iVar10;

  CHAR *pCVar11;

  undefined4 *puVar12;

  int iVar13;

  undefined4 *puVar14;

  bool bVar15;

  _MEMORY_BASIC_INFORMATION local_ee0;

  PVOID local_ec4;

  uint local_ec0;

  _SYSTEM_INFO local_ebc;

  undefined2 *local_e98;

  undefined4 *local_e94;

  LPSTR local_e90;

  CHAR *local_e8c;

  undefined4 local_e88;

  CHAR local_e84;

  undefined4 local_e83;

  CHAR local_ace [50];

  uint local_a9c;

  undefined4 *local_a98;

  undefined4 *local_a94;

  int local_a90;

  int local_a8c;

  CHAR local_a88 [1000];

  _MEMORYSTATUS local_6a0;

  _SYSTEM_INFO local_680;

  CHAR local_65c [200];

  DWORD local_594;

  CHAR local_590 [260];

  CHAR local_48c [100];

  uint local_428;

  uint local_424;

  _FILETIME local_420;

  _FILETIME local_418;

  int local_410;

  char *local_40c [47];

  CHAR local_350 [260];

  _MEMORY_BASIC_INFORMATION local_24c;

  char *local_230;

  int local_22c;

  HANDLE local_228;

  CHAR local_224 [260];

  char local_120 [4];

  char local_11c [4];

  undefined4 local_118 [63];

  undefined1 *local_1c;

  void *local_14;

  undefined1 *puStack_10;

  undefined *puStack_c;

  undefined4 local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &DAT_00551808;

  puStack_10 = &LAB_00544c84;

  local_14 = ExceptionList;

  local_1c = &stack0xfffff114;

  if (DAT_005dcf90 != 0) {

    return 0;

  }

  DAT_005dcf90 = 1;

  local_120 = (char  [4])s_Unknown_0057c908._0_4_;

  local_11c = (char  [4])s_Unknown_0057c908._4_4_;

  puVar12 = local_118;

  for (iVar10 = 0x3f; iVar10 != 0; iVar10 = iVar10 + -1) {

    *puVar12 = 0;

    puVar12 = puVar12 + 1;

  }

  ExceptionList = &local_14;

  DVar3 = GetModuleFileNameA((HMODULE)0x0,local_224,0x104);

  if (DVar3 == 0) {

    local_224[0] = '\0';

  }

  pcVar4 = _strrchr(local_224,0x5c);

  if (pcVar4 == (char *)0x0) {

    pCVar11 = local_224;

  }

  else {

    pCVar11 = pcVar4 + 1;

  }

  lstrcpyA(local_120,pCVar11);

  pcVar4 = _strrchr(local_120,0x2e);

  if (pcVar4 != (char *)0x0) {

    *pcVar4 = '\0';

  }

  lstrcpyA(pCVar11,s_errorlog_txt_0057c8f8);

  hFile = CreateFileA(local_224,0x40000000,0,(LPSECURITY_ATTRIBUTES)0x0,4,0x80000080,(HANDLE)0x0);

  local_228 = hFile;

  if (hFile == (HANDLE)0xffffffff) {

    OutputDebugStringA(s_Error_creating_exception_report_0057c8d8);

    ExceptionList = local_14;

    return 0;

  }

  SetFilePointer(hFile,0,(PLONG)0x0,2);

  FUN_00518620(hFile,s__0057c8cc);

  piVar1 = (int *)*param_1;

  iVar10 = param_1[1];

  local_230 = s_Unknown_0057c908;

  local_22c = iVar10;

  SVar5 = VirtualQuery(*(LPCVOID *)(iVar10 + 0xb8),&local_24c,0x1c);

  pcVar4 = local_230;

  if ((SVar5 != 0) &&

     (DVar3 = GetModuleFileNameA(local_24c.AllocationBase,local_350,0x104), pcVar4 = local_230,

     DVar3 != 0)) {

    pcVar4 = _strrchr(local_350,0x5c);

    if (pcVar4 == (char *)0x0) {

      pcVar4 = local_350;

    }

    else {

      pcVar4 = pcVar4 + 1;

    }

  }

  local_410 = 0x40010005;

  local_40c[0] = s_a_Control_C_0057c8c0;

  local_40c[1] = (char *)0x40010008;

  local_40c[2] = s_a_Control_Break_0057c8b0;

  local_40c[3] = (char *)0x80000002;

  local_40c[4] = s_a_Datatype_Misalignment_0057c898;

  local_40c[5] = (char *)0x80000003;

  local_40c[6] = s_a_Breakpoint_0057c888;

  local_40c[7] = (char *)0xc0000005;

  local_40c[8] = s_an_Access_Violation_0057c874;

  local_40c[9] = (char *)0xc0000006;

  local_40c[10] = s_an_In_Page_Error_0057c860;

  local_40c[0xb] = (char *)0xc0000017;

  local_40c[0xc] = s_a_No_Memory_0057c854;

  local_40c[0xd] = (char *)0xc000001d;

  local_40c[0xe] = s_an_Illegal_Instruction_0057c83c;

  local_40c[0xf] = (char *)0xc0000025;

  local_40c[0x10] = s_a_Noncontinuable_Exception_0057c820;

  local_40c[0x11] = (char *)0xc0000026;

  local_40c[0x12] = s_an_Invalid_Disposition_0057c808;

  local_40c[0x13] = (char *)0xc000008c;

  local_40c[0x14] = s_a_Array_Bounds_Exceeded_0057c7f0;

  local_40c[0x15] = (char *)0xc000008d;

  local_40c[0x16] = s_a_Float_Denormal_Operand_0057c7d4;

  local_40c[0x17] = (char *)0xc000008e;

  local_40c[0x18] = s_a_Float_Divide_by_Zero_0057c7bc;

  local_40c[0x19] = (char *)0xc000008f;

  local_40c[0x1a] = s_a_Float_Inexact_Result_0057c7a4;

  local_40c[0x1b] = (char *)0xc0000090;

  local_40c[0x1c] = s_a_Float_Invalid_Operation_0057c788;

  local_40c[0x1d] = (char *)0xc0000091;

  local_40c[0x1e] = s_a_Float_Overflow_0057c774;

  local_40c[0x1f] = (char *)0xc0000092;

  local_40c[0x20] = s_a_Float_Stack_Check_0057c760;

  local_40c[0x21] = (char *)0xc0000093;

  local_40c[0x22] = s_a_Float_Underflow_0057c74c;

  local_40c[0x23] = (char *)0xc0000094;

  local_40c[0x24] = s_an_Integer_Divide_by_Zero_0057c730;

  local_40c[0x25] = (char *)0xc0000095;

  local_40c[0x26] = s_an_Integer_Overflow_0057c71c;

  local_40c[0x27] = (char *)0xc0000096;

  local_40c[0x28] = s_a_Privileged_Instruction_0057c700;

  local_40c[0x29] = (char *)0xc00000fd;

  local_40c[0x2a] = s_a_Stack_Overflow_0057c6ec;

  local_40c[0x2b] = (char *)0xc0000142;

  local_40c[0x2c] = s_a_DLL_Initialization_Failed_0057c6d0;

  local_40c[0x2d] = (char *)0xe06d7363;

  local_40c[0x2e] = s_a_Microsoft_C___Exception_0057c6b4;

  uVar6 = 0;

  do {

    if (*piVar1 == (&local_410)[uVar6 * 2]) {

      pcVar7 = (char *)(&local_410)[uVar6 * 2 + 1];

      goto LAB_0051804e;

    }

    uVar6 = uVar6 + 1;

  } while (uVar6 < 0x18);

  pcVar7 = s_Unknown_exception_type_0057c69c;

LAB_0051804e:

  FUN_00518620(hFile,s__s_caused__s_in_module__s_at__04_0057c670,local_120,pcVar7,pcVar4,

               *(undefined4 *)(iVar10 + 0xbc),*(undefined4 *)(iVar10 + 0xb8));

  FUN_00518620(hFile,s_Exception_handler_called_in__s__0057c64c,param_2);

  GetSystemTimeAsFileTime(&local_418);

  local_420.dwLowDateTime = local_418.dwLowDateTime;

  local_420.dwHighDateTime = local_418.dwHighDateTime;

  BVar8 = FileTimeToLocalFileTime(&local_420,&local_420);

  if ((BVar8 == 0) ||

     (BVar8 = FileTimeToDosDateTime(&local_420,(LPWORD)&local_428,(LPWORD)&local_424), BVar8 == 0))

  {

    local_48c[0] = '\0';

  }

  else {

    wsprintfA(local_48c,s__d__d__d__02d__02d__02d_0057c634,(local_428 & 0xffff) >> 5 & 0xf,

              local_428 & 0x1f,((local_428 & 0xffff) >> 9) + 0x7bc,(local_424 & 0xffff) >> 0xb,

              (local_424 & 0xffff) >> 5 & 0x3f,(local_424 & 0x1f) << 1);

  }

  FUN_00518620(hFile,s_Error_occurred_at__s__0057c61c,local_48c);

  DVar3 = GetModuleFileNameA((HMODULE)0x0,local_590,0x104);

  if (DVar3 == 0) {

    lstrcpyA(local_590,s_Unknown_0057c908);

  }

  local_594 = 200;

  BVar8 = GetUserNameA(local_65c,&local_594);

  if (BVar8 == 0) {

    lstrcpyA(local_65c,s_Unknown_0057c908);

  }

  FUN_00518620(hFile,s__s__run_by__s__0057c608,local_590,local_65c);

  GetSystemInfo(&local_680);

  FUN_00518620(hFile,s__d_processor_s___type__d__0057c5ec,local_680.dwNumberOfProcessors,

               local_680.dwProcessorType);

  local_6a0.dwLength = 0x20;

  GlobalMemoryStatus(&local_6a0);

  FUN_00518620(hFile,s__d_MBytes_physical_memory__0057c5cc,local_6a0.dwTotalPhys + 0xfffff >> 0x14);

  if ((*piVar1 == -0x3ffffffb) && (1 < (uint)piVar1[4])) {

    pcVar4 = s_Read_from_0057c5c0;

    if (piVar1[5] != 0) {

      pcVar4 = s_Write_to_0057c5b4;

    }

    wsprintfA(local_a88,s__s_location__08x_caused_an_acces_0057c584,pcVar4,piVar1[6]);

    FUN_00518620(hFile,&DAT_00555df0,local_a88);

  }

  FUN_00518620(hFile,&DAT_0057c1f8);

  FUN_00518620(hFile,s_Registers__0057c574);

  FUN_00518620(hFile,s_EAX__08x_CS__04x_EIP__08x_EFLGS__0057c54c,*(undefined4 *)(iVar10 + 0xb0),

               *(undefined4 *)(iVar10 + 0xbc),*(undefined4 *)(iVar10 + 0xb8),

               *(undefined4 *)(iVar10 + 0xc0));

  FUN_00518620(hFile,s_EBX__08x_SS__04x_ESP__08x_EBP__0_0057c524,*(undefined4 *)(iVar10 + 0xa4),

               *(undefined4 *)(iVar10 + 200),*(undefined4 *)(iVar10 + 0xc4),

               *(undefined4 *)(iVar10 + 0xb4));

  FUN_00518620(hFile,s_ECX__08x_DS__04x_ESI__08x_FS__04_0057c500,*(undefined4 *)(iVar10 + 0xac),

               *(undefined4 *)(iVar10 + 0x98),*(undefined4 *)(iVar10 + 0xa0),

               *(undefined4 *)(iVar10 + 0x90));

  FUN_00518620(hFile,s_EDX__08x_ES__04x_EDI__08x_GS__04_0057c4dc,*(undefined4 *)(iVar10 + 0xa8),

               *(undefined4 *)(iVar10 + 0x94),*(undefined4 *)(iVar10 + 0x9c),

               *(undefined4 *)(iVar10 + 0x8c));

  FUN_00518620(hFile,s_Bytes_at_CS_EIP__0057c4c8);

  local_a8c = *(int *)(iVar10 + 0xb8);

  for (iVar13 = 0; local_a90 = iVar13, iVar13 < 0x10; iVar13 = iVar13 + 1) {

    local_8 = 0;

    FUN_00518620(hFile,s__02x_0057c4c0,*(undefined1 *)(iVar13 + local_a8c));

    local_8 = 0xffffffff;

  }

  FUN_00518620(hFile,s_Stack_dump__0057c4ac);

  local_8 = 1;

  puVar12 = *(undefined4 **)(iVar10 + 0xc4);

  local_a98 = StackBase;

  if (puVar12 + 0x800 < StackBase) {

    local_a98 = puVar12 + 0x800;

  }

  local_a9c = 0;

  local_e84 = DAT_00584374;

  puVar14 = &local_e83;

  local_a94 = puVar12;

  for (iVar10 = 0xf9; iVar10 != 0; iVar10 = iVar10 + -1) {

    *puVar14 = 0;

    puVar14 = puVar14 + 1;

  }

  *(undefined2 *)puVar14 = 0;

  *(undefined1 *)((int)puVar14 + 2) = 0;

  local_e88 = 0x32;

  local_e8c = local_ace;

  do {

    pCVar11 = &local_e84;

    do {

      local_e94 = puVar12 + 1;

      local_e90 = pCVar11;

      if (local_a98 < local_e94) {

        FUN_00518620(hFile,&DAT_00555df0,&local_e84);

        local_8 = 0xffffffff;

        FUN_00518620(hFile,s_Module_list__names__addresses__s_0057c428);

        GetSystemInfo(&local_ebc);

        local_ec0 = (int)(0x40000000 / (ulonglong)local_ebc.dwPageSize) * 4;

        uVar6 = 0;

        local_ec4 = (PVOID)0x0;

        if (local_ec0 != 0) {

          do {

            SVar5 = VirtualQuery((LPCVOID)(uVar6 * local_ebc.dwPageSize),&local_ee0,0x1c);

            if ((SVar5 == 0) || (local_ee0.RegionSize == 0)) {

              uVar6 = uVar6 + (int)(0x10000 / (ulonglong)local_ebc.dwPageSize);

            }

            else {

              uVar6 = uVar6 + local_ee0.RegionSize / local_ebc.dwPageSize;

              if ((local_ee0.State == 0x1000) && (local_ec4 < local_ee0.AllocationBase)) {

                local_ec4 = local_ee0.AllocationBase;

                file_date_log_write(hFile,local_ee0.AllocationBase);

              }

            }

          } while (uVar6 < local_ec0);

        }

        CloseHandle(hFile);

        ExceptionList = local_14;

        return 0;

      }

      uVar6 = local_a9c & 0x80000007;

      bVar15 = uVar6 == 0;

      if ((int)uVar6 < 0) {

        bVar15 = (uVar6 - 1 | 0xfffffff8) == 0xffffffff;

      }

      if (bVar15) {

        iVar10 = wsprintfA(pCVar11,s__08x__0057c4a4,puVar12);

        local_e90 = pCVar11 + iVar10;

      }

      pCVar2 = local_e90;

      puVar9 = &DAT_0055c728;

      local_e98 = &DAT_0055c728;

      local_a9c = local_a9c + 1;

      uVar6 = local_a9c & 0x80000007;

      bVar15 = uVar6 == 0;

      if ((int)uVar6 < 0) {

        bVar15 = (uVar6 - 1 | 0xfffffff8) == 0xffffffff;

      }

      if ((bVar15) || (local_a98 < puVar12 + 2)) {

        puVar9 = (undefined2 *)&DAT_0057c1f8;

        local_e98 = (undefined2 *)&DAT_0057c1f8;

      }

      iVar10 = wsprintfA(local_e90,s__08x_s_0057c49c,*puVar12,puVar9);

      puVar12 = local_e94;

      pCVar11 = pCVar2 + iVar10;

      local_a94 = local_e94;

    } while (pCVar11 <= local_e8c);

    local_e90 = pCVar11;

    FUN_00518620(hFile,&DAT_00555df0,&local_e84);

    local_e84 = '\0';

  } while( true );

}

/* ===== FUN_00518620 @ 0x00518620 ===== */
void FUN_00518620(HANDLE param_1,LPCSTR param_2)



{

  DWORD nNumberOfBytesToWrite;

  DWORD *lpNumberOfBytesWritten;

  LPOVERLAPPED lpOverlapped;

  DWORD local_7d4;

  CHAR local_7d0 [2000];

  

  lpNumberOfBytesWritten = &local_7d4;

  wvsprintfA(local_7d0,param_2,&stack0x0000000c);

  lpOverlapped = (LPOVERLAPPED)0x0;

  nNumberOfBytesToWrite = lstrlenA(local_7d0);

  WriteFile(param_1,local_7d0,nNumberOfBytesToWrite,lpNumberOfBytesWritten,lpOverlapped);

  return;

}

/* ===== file_date_log_write @ 0x00518670 ===== */
void file_date_log_write(undefined4 param_1,HMODULE param_2)



{

  DWORD DVar1;

  HANDLE hFile;

  BOOL BVar2;

  int iVar3;

  int *piVar4;

  undefined4 *puVar5;

  _FILETIME local_19c;

  DWORD local_194;

  CHAR local_190;

  undefined4 local_18f;

  HANDLE local_12c;

  int *local_128;

  HMODULE local_124;

  CHAR local_120 [260];

  undefined1 *local_1c;

  void *local_14;

  undefined1 *puStack_10;

  undefined *puStack_c;

  undefined4 local_8;

  

  puStack_c = &DAT_00551820;

  puStack_10 = &LAB_00544c84;

  local_14 = ExceptionList;

  local_1c = &stack0xfffffe58;

  local_8 = 0;

  ExceptionList = &local_14;

  DVar1 = GetModuleFileNameA(param_2,local_120,0x104);

  if ((DVar1 != 0) && (local_124 = param_2, (short)param_2->unused == 0x5a4d)) {

    piVar4 = (int *)((int)&param_2->unused + param_2[0xf].unused);

    if (*piVar4 == 0x4550) {

      local_128 = piVar4;

      hFile = CreateFileA(local_120,0x80000000,1,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);

      local_190 = DAT_00584374;

      puVar5 = &local_18f;

      local_12c = hFile;

      for (iVar3 = 0x18; iVar3 != 0; iVar3 = iVar3 + -1) {

        *puVar5 = 0;

        puVar5 = puVar5 + 1;

      }

      *(undefined2 *)puVar5 = 0;

      *(undefined1 *)((int)puVar5 + 2) = 0;

      DVar1 = 0;

      local_194 = 0;

      if (hFile != (HANDLE)0xffffffff) {

        DVar1 = GetFileSize(hFile,(LPDWORD)0x0);

        local_194 = DVar1;

        BVar2 = GetFileTime(hFile,(LPFILETIME)0x0,(LPFILETIME)0x0,&local_19c);

        if (BVar2 != 0) {

          wsprintfA(&local_190,s___file_date_is_0057c93c);

          iVar3 = lstrlenA(&local_190);

          datetime_format(&local_190 + iVar3,local_19c.dwLowDateTime,local_19c.dwHighDateTime);

        }

        CloseHandle(hFile);

      }

      FUN_00518620(param_1,s__s__loaded_at_0x_08x____d_bytes___0057c910,local_120,param_2,DVar1,

                   piVar4[2],&local_190);

    }

  }

  ExceptionList = local_14;

  return;

}

/* ===== datetime_format @ 0x005187F0 ===== */
void datetime_format(LPSTR param_1)



{

  BOOL BVar1;

  uint local_8;

  uint local_4;

  

  BVar1 = FileTimeToLocalFileTime((FILETIME *)&stack0x00000008,(LPFILETIME)&stack0x00000008);

  if (BVar1 != 0) {

    BVar1 = FileTimeToDosDateTime((FILETIME *)&stack0x00000008,(LPWORD)&local_4,(LPWORD)&local_8);

    if (BVar1 != 0) {

      wsprintfA(param_1,s__d__d__d__02d__02d__02d_0057c634,(local_4 & 0xffff) >> 5 & 0xf,

                local_4 & 0x1f,((local_4 & 0xffff) >> 9) + 0x7bc,(local_8 & 0xffff) >> 0xb,

                (local_8 & 0xffff) >> 5 & 0x3f,(local_8 & 0x1f) << 1);

      return;

    }

  }

  *param_1 = '\0';

  return;

}

/* ===== time_get_ms @ 0x00518890 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void time_get_ms(void)



{

  DWORD DVar1;

  

  _DAT_006328ec = 0;

  _DAT_006328e4 = 0x3ccccccd;

  DAT_006328e0 = 0.025;

  if (DAT_00633248 != 0) {

    DAT_006328e0 = 0.016666668;

  }

  if (DAT_0063312c != 0) {

    DAT_006328e0 = DAT_006328e0 * 10.0;

  }

  if (DAT_0057c950 == 0xffffffff) {

    DAT_0057c950 = timeGetTime();

  }

  DVar1 = timeGetTime();

  DAT_005dcf98 = 0;

  DAT_006328e8 = (float)(DVar1 - DAT_0057c950) * 0.001;

  return;

}

/* ===== time_frame_update @ 0x00518950 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void time_frame_update(void)



{

  float fVar1;

  DWORD DVar2;

  uint uVar3;

  

  if ((DAT_00632d5c == 0) && (DAT_00632d60 == 0)) {

    if (DAT_0057c950 == 0xffffffff) {

      DAT_0057c950 = timeGetTime();

    }

    DVar2 = timeGetTime();

    uVar3 = DVar2 - DAT_0057c950;

  }

  else {

    uVar3 = DAT_005dcfa4 + 0x32;

  }

  DAT_006328e8 = (float)uVar3 * 0.001;

  if (DAT_005dcf9c == 0) {

    _DAT_006328ec = 0.0;

    _DAT_006328e4 = 0.025;

    DAT_006328e0 = 0.025;

    if (DAT_00633248 != 0) {

      DAT_006328e0 = 0.016666668;

    }

    if (DAT_0063312c != 0) {

      DAT_006328e0 = DAT_006328e0 * 10.0;

    }

    if (DAT_0057c950 == 0xffffffff) {

      DAT_0057c950 = timeGetTime();

    }

    DVar2 = timeGetTime();

    DAT_005dcf9c = uVar3;

    _DAT_005dcfa0 = uVar3 + 0x19;

    DAT_005dcf98 = 0;

    DAT_006328e8 = (float)(DVar2 - DAT_0057c950) * 0.001;

    return;

  }

  if (uVar3 < DAT_005dcf9c) {

    DAT_005dcf9c = uVar3;

  }

  fVar1 = (float)(uVar3 - DAT_005dcf9c) * 0.001;

  if (DAT_005dcf98 < 6) {

    DAT_005dcf98 = DAT_005dcf98 + 1;

    _DAT_006328e4 = fVar1;

  }

  else {

    _DAT_006328e4 = _DAT_006328e4 * _DAT_006328ec + (1.0 - _DAT_006328ec) * fVar1;

    if ((_DAT_006328ec < 0.75) && (_DAT_006328ec = _DAT_006328ec + 0.15, 0.75 < _DAT_006328ec)) {

      _DAT_006328ec = 0.75;

    }

  }

  fVar1 = _DAT_006328e4;

  if (DAT_00633130 != 0) {

    fVar1 = 0.025;

  }

  if (DAT_0063312c != 0) {

    fVar1 = fVar1 * 0.1;

  }

  DAT_006328e0 = _DAT_006328f0 * fVar1;

  if ((DAT_0063312c == 0 && DAT_00633130 == 0) && (0.25 < DAT_006328e0)) {

    DAT_006328e0 = 0.25;

  }

  if (DAT_00633248 != 0) {

    DAT_006328e0 = 0.016666668;

  }

  DAT_005dcf9c = DAT_005dcf9c + (uVar3 - DAT_005dcf9c);

  DAT_005dcfa4 = uVar3;

  _DAT_005dcfa0 = DAT_005dcf9c + 0x19;

  return;

}

/* ===== FUN_00518b70 @ 0x00518B70 ===== */
/* PS2 candidate: FRateGetSecsframe (conf 0.712) */



float10 FUN_00518b70(int param_1,int param_2)



{

  float *pfVar1;

  float10 fVar2;

  int iVar3;

  

  pfVar1 = DAT_005dcfa8;

  do {

    if (pfVar1 == (float *)0x0) {

      return (float10)DAT_006328e0;

    }

    if (param_1 == 0) {

      iVar3 = param_2;

      if (param_2 != 0) goto LAB_00518bb0;

    }

    else if (*(int *)(param_1 + 0x18c) != *(int *)((int)pfVar1[3] + 0x18c)) {

      iVar3 = param_1 + 0xa0;

LAB_00518bb0:

      fVar2 = (float10)distancesq2d__FP3P3DT0(iVar3,pfVar1 + 4);

      if (fVar2 < (float10)*pfVar1 != (fVar2 == (float10)*pfVar1)) {

        return (float10)DAT_006328e0 * (float10)pfVar1[1];

      }

    }

    pfVar1 = (float *)pfVar1[7];

  } while( true );

}

/* ===== gg_dll_name @ 0x00518D30 ===== */
undefined4 gg_dll_name(char *param_1,undefined4 param_2)



{

  HMODULE hLibModule;

  CHAR local_200 [512];

  

  if ((param_1 != (char *)0x0) && (*param_1 != '\0')) {

    crt_sprintf(local_200,s__s_gg__s_0057c98c,param_1,param_2);

    hLibModule = GetModuleHandleA(local_200);

    if ((hLibModule != (HMODULE)0x0) ||

       (hLibModule = LoadLibraryA(local_200), hLibModule != (HMODULE)0x0)) goto LAB_00518dac;

  }

  crt_sprintf(local_200,s_gg__s_0057c984,param_2);

  hLibModule = GetModuleHandleA(local_200);

  if ((hLibModule == (HMODULE)0x0) &&

     (hLibModule = LoadLibraryA(local_200), hLibModule == (HMODULE)0x0)) {

    return 1;

  }

LAB_00518dac:

  FreeLibrary(hLibModule);

  return 1;

}

/* ===== renderer_load_return_site @ 0x00518DD0 ===== */
undefined4 renderer_load_return_site(char *param_1,undefined4 param_2)



{

  HMODULE hModule;

  undefined4 local_20c;

  undefined4 local_208;

  undefined4 local_204;

  CHAR local_200 [512];

  

  if ((param_1 != (char *)0x0) && (*param_1 != '\0')) {

    crt_sprintf(local_200,s__s_gg__s_0057c98c,param_1,param_2);

    hModule = GetModuleHandleA(local_200);

    if (hModule != (HMODULE)0x0) goto LAB_00518e60;

    hModule = LoadLibraryA(local_200);

    if (hModule != (HMODULE)0x0) goto LAB_00518e60;

  }

  crt_sprintf(local_200,s_gg__s_0057c984,param_2);

  hModule = GetModuleHandleA(local_200);

  if (hModule == (HMODULE)0x0) {

    hModule = LoadLibraryA(local_200);

    if (hModule == (HMODULE)0x0) {

      return 0;

    }

  }

LAB_00518e60:

  DAT_005dcfac = GetProcAddress(hModule,s_GDVSysCreate_0057c9dc);

  if (DAT_005dcfac == (FARPROC)0x0) {

    error_screen_exit(s_Failed_to_load_GDVSysCreate_0057c9c0);

    return 0;

  }

  DAT_005dcfb0 = GetProcAddress(hModule,s_UpCallsLoad_0057c9b4);

  if (DAT_005dcfb0 == (FARPROC)0x0) {

    error_screen_exit(s_Failed_to_load_UpCallsLoad_0057c998);

    return 0;

  }

  _lmcGetClientPtr(&local_208,&local_20c,&local_204);

  (*DAT_005dcfb0)(local_208,local_20c,local_204);

  return 1;

}

/* ===== FUN_00518f00 @ 0x00518F00 ===== */
void FUN_00518f00(char *param_1)



{

  char cVar1;

  int iVar2;

  

  iVar2 = (int)&DAT_005dcfb8 - (int)param_1;

  do {

    cVar1 = *param_1;

    param_1[iVar2] = cVar1;

    param_1 = param_1 + 1;

  } while (cVar1 != '\0');

  return;

}

/* ===== fps_display @ 0x00518F20 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined4 fps_display(void)



{

  undefined1 local_20 [32];

  

  if (DAT_0063320c != 0) {

    if (_DAT_006328e4 <= 0.0) {

      local_20[0] = 0;

    }

    else {

      crt_sprintf(local_20,s_FPS__6_2f_0057c9ec,(double)(1.0 / _DAT_006328e4));

    }

    textrender_draw_buffered(0xffffff,0,0x3d000000,0x3f000000,0x3e000000,local_20);

  }

  return 1;

}

/* ===== FUN_00518FA0 @ 0x00518FA0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_00518FA0(void)



{

  int iVar1;

  undefined4 *puVar2;

  

  puVar2 = &DAT_005dd0c0;

  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar2 = 0;

    puVar2 = puVar2 + 1;

  }

  puVar2 = &DAT_005dd0e0;

  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar2 = 0;

    puVar2 = puVar2 + 1;

  }

  puVar2 = &DAT_005dd120;

  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar2 = 0;

    puVar2 = puVar2 + 1;

  }

  puVar2 = &DAT_005dd140;

  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar2 = 0;

    puVar2 = puVar2 + 1;

  }

  puVar2 = &DAT_005dd160;

  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar2 = 0;

    puVar2 = puVar2 + 1;

  }

  _DAT_005dd23c = 0;

  _DAT_005dd240 = 0;

  DAT_005dd244 = 0;

  _DAT_005dd238 = 0;

  return;

}

/* ===== dinput_init @ 0x00519110 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined4 dinput_init(void)



{

  undefined4 uVar1;

  int iVar2;

  undefined4 *puVar3;

  HWND *ppHVar4;

  HWND *ppHStack_72c;

  undefined4 uStack_728;

  HWND *ppHStack_724;

  HWND *ppHStack_720;

  HWND pHStack_71c;

  HWND pHStack_718;

  HWND__ HStack_714;

  undefined1 auStack_5f8 [4];

  HWND apHStack_5f4 [381];

  

  puVar3 = &DAT_005dd0b8;

  for (iVar2 = 100; iVar2 != 0; iVar2 = iVar2 + -1) {

    *puVar3 = 0;

    puVar3 = puVar3 + 1;

  }

  HStack_714.unused = 0x51913f;

  GetModuleHandleA((LPCSTR)0x0);

  HStack_714.unused = 0x519145;

  DAT_005ddb7c = DirectInput8Create();

  if (DAT_005ddb7c != 0) {

    di_error_trace();

    return 0;

  }

  uVar1 = 0;

  if (DAT_005dd180 == (HWND *)0x0) {

    DAT_005ddb7c = (**(code **)(*DAT_005dd0b8 + 0xc))();

    if (DAT_005ddb7c != 0) {

      HStack_714.unused = 0x51919b;

      di_error_trace();

      FUN_0051EA90();

      return 1;

    }

    HStack_714.unused = (int)DAT_005dd180;

    pHStack_718 = (HWND)0x5191c1;

    DAT_005ddb7c = (*(code *)(*DAT_005dd180)[0xb].unused)();

    if (DAT_005ddb7c != 0) {

      pHStack_718 = (HWND)s_DIMouse_SetDataFormat__s_0057caa8;

      pHStack_71c = (HWND)0x5191d4;

      di_error_trace();

      pHStack_718 = (HWND)0x5191dc;

      FUN_0051EA90();

      return 1;

    }

    pHStack_718 = (HWND)0x5;

    pHStack_71c = DAT_005dda78;

    ppHStack_720 = DAT_005dd180;

    ppHStack_724 = (HWND *)0x5191fe;

    DAT_005ddb7c = (*(code *)(*DAT_005dd180)[0xd].unused)();

    if (DAT_005ddb7c != 0) {

      ppHStack_724 = (HWND *)s_DIMouse_SetCooperativeLevel__s_0057ca88;

      uStack_728 = 0x519211;

      di_error_trace();

      ppHStack_724 = (HWND *)0x519219;

      FUN_0051EA90();

      return 1;

    }

    ppHStack_724 = DAT_005dd180;

    uStack_728 = 0x519232;

    uVar1 = (*(code *)(*DAT_005dd180)[7].unused)();

  }

  DAT_005ddb7c = uVar1;

  if (DAT_005dd0bc == (HWND *)0x0) {

    DAT_005ddb7c = (**(code **)(*DAT_005dd0b8 + 0xc))();

    if (DAT_005ddb7c != 0) {

      HStack_714.unused = 0x51926c;

      di_error_trace();

      FUN_0051EA90();

      return 1;

    }

    HStack_714.unused = (int)DAT_005dd0bc;

    pHStack_718 = (HWND)0x519292;

    DAT_005ddb7c = (*(code *)(*DAT_005dd0bc)[0xb].unused)();

    if (DAT_005ddb7c != 0) {

      pHStack_718 = (HWND)s_DIKey_SetDataFormat__s_0057ca58;

      pHStack_71c = (HWND)0x5192a5;

      di_error_trace();

      pHStack_718 = (HWND)0x5192ad;

      FUN_0051EA90();

      return 1;

    }

    pHStack_718 = (HWND)0x6;

    pHStack_71c = DAT_005dda78;

    ppHStack_720 = DAT_005dd0bc;

    ppHStack_724 = (HWND *)0x5192cf;

    DAT_005ddb7c = (*(code *)(*DAT_005dd0bc)[0xd].unused)();

    if (DAT_005ddb7c != 0) {

      ppHStack_724 = (HWND *)s_DIKey_SetCooperativeLevel__s_0057ca38;

      uStack_728 = 0x5192e2;

      di_error_trace();

      ppHStack_724 = (HWND *)0x5192ea;

      FUN_0051EA90();

      return 1;

    }

    ppHStack_724 = &pHStack_718;

    uStack_728 = 1;

    pHStack_718 = (HWND)0x14;

    HStack_714.unused = 0x10;

    ppHStack_72c = DAT_005dd0bc;

    DAT_005ddb7c = (*(code *)(*DAT_005dd0bc)[6].unused)();

    if (DAT_005ddb7c != 0) {

      di_error_trace(s_DIKey_SetProperty__s_0057ca20);

      FUN_0051EA90();

      return 1;

    }

    DAT_005ddb7c = (*(code *)(*DAT_005dd0bc)[7].unused)(DAT_005dd0bc);

  }

  ANM_DumpCluster();

  if (DAT_005dd180 != (HWND *)0x0) {

    SetCapture(DAT_005dda78);

  }

  if (DAT_00633104 != 0) {

    DAT_005dd184 = (int *)0x0;

    HStack_714.unused = 0x5193ba;

    iVar2 = (**(code **)(*DAT_005dd0b8 + 0x10))();

    if (-1 < iVar2) {

      if (DAT_005dd184 != (int *)0x0) {

        HStack_714.unused = 5;

        pHStack_718 = DAT_005dda78;

        pHStack_71c = (HWND)DAT_005dd184;

        ppHStack_720 = (HWND *)0x5193de;

        iVar2 = (**(code **)(*DAT_005dd184 + 0x34))();

        if (-1 < iVar2) {

          ppHStack_720 = (HWND *)&DAT_005dd188;

          _DAT_005dd188 = 0x2c;

          ppHStack_724 = (HWND *)DAT_005dd184;

          uStack_728 = 0x519400;

          iVar2 = (**(code **)(*DAT_005dd184 + 0xc))();

          if (-1 < iVar2) {

            uStack_728 = 0;

            ppHStack_72c = apHStack_5f4;

            ppHVar4 = apHStack_5f4;

            for (iVar2 = 0x173; iVar2 != 0; iVar2 = iVar2 + -1) {

              *ppHVar4 = (HWND)0x0;

              ppHVar4 = ppHVar4 + 1;

            }

            iVar2 = (**(code **)(*DAT_005dd184 + 0x10))(DAT_005dd184,&LAB_00519030);

            if (-1 < iVar2) {

              HStack_714.unused = (int)auStack_5f8;

              pHStack_718 = &HStack_714;

              ppHStack_72c = (HWND *)0x18;

              uStack_728 = 0x10;

              ppHStack_724 = (HWND *)0x1;

              ppHStack_720 = (HWND *)0x34;

              pHStack_71c = (HWND)0x11;

              iVar2 = (**(code **)(*DAT_005dd184 + 0x2c))(DAT_005dd184,&ppHStack_72c);

              if (-1 < iVar2) {

                return 1;

              }

            }

          }

        }

      }

      DAT_00633104 = 0;

    }

  }

  return 1;

}

/* ===== dinput_device_check @ 0x00519750 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



bool dinput_device_check(void)



{

  int iVar1;

  undefined4 *puVar2;

  undefined4 *puVar3;

  

  if (DAT_005dd184 == (int *)0x0) {

    return false;

  }

  (**(code **)(*DAT_005dd184 + 100))(DAT_005dd184);

  puVar2 = &DAT_005dd1b4;

  puVar3 = &DAT_005dd1e8;

  for (iVar1 = 0xd; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar3 = *puVar2;

    puVar2 = puVar2 + 1;

    puVar3 = puVar3 + 1;

  }

  iVar1 = (**(code **)(*DAT_005dd184 + 0x24))(DAT_005dd184,0x34,&DAT_005dd1b4);

  if ((iVar1 == -0x7ff8fff4) || (iVar1 == -0x7ff8ffe2)) {

    (**(code **)(*DAT_005dd184 + 0x1c))(DAT_005dd184);

    iVar1 = (**(code **)(*DAT_005dd184 + 0x24))(DAT_005dd184,0x34,&DAT_005dd1b4);

  }

  if (-1 < iVar1) {

    DAT_005dd1b4 = DAT_005dd1b4 + -0x7dff;

    DAT_005dd1b8 = DAT_005dd1b8 + -0x7dff;

    DAT_005dd1bc = DAT_005dd1bc + -0x7dff;

    DAT_005dd1c0 = DAT_005dd1c0 + -0x7dff;

    DAT_005dd21c = __ftol();

    DAT_005dd220 = __ftol();

    DAT_005dd224 = 0;

    DAT_005dd228 = __ftol();

    DAT_005dd22c = __ftol();

    _DAT_005dd230 = 0;

  }

  return -1 < iVar1;

}

/* ===== dinput_key_poll @ 0x00519930 ===== */
undefined4 dinput_key_poll(void)



{

  byte bVar1;

  int iVar2;

  int *piVar3;

  uint uVar4;

  undefined1 **ppuVar5;

  undefined1 *puStack_510;

  undefined1 *puStack_50c;

  undefined4 uStack_508;

  undefined4 local_504;

  undefined1 local_500 [1280];

  

  puStack_50c = (undefined1 *)&local_504;

  if (DAT_005dd0bc != (int *)0x0) {

    uStack_508 = 0;

    puStack_510 = local_500;

    local_504 = 0x40;

    piVar3 = DAT_005dd0bc;

    DAT_005ddb7c = (**(code **)(*DAT_005dd0bc + 0x28))(DAT_005dd0bc,0x14);

    if ((DAT_005ddb7c == -0x7ff8ffe2) || (DAT_005ddb7c == -0x7ff8fff4)) {

      (**(code **)(*DAT_005dd0bc + 0x1c))(DAT_005dd0bc);

    }

    else {

      if (DAT_005ddb7c == 1) {

        DAT_005ddb7c = 0;

      }

      else if (DAT_005ddb7c != 0) {

        di_error_trace(s_DIKey_GetDeviceData__s_0057caf4);

        return 0;

      }

      if (0 < (int)piVar3) {

        ppuVar5 = &puStack_510;

        do {

          bVar1 = (byte)ppuVar5[-1];

          iVar2 = (int)((uint)ppuVar5[-1] & 0xff) >> 5;

          if (*(char *)ppuVar5 < '\0') {

            uVar4 = 1 << (bVar1 & 0x1f);

            (&DAT_005dd0e0)[iVar2] = (&DAT_005dd0e0)[iVar2] | uVar4;

            (&DAT_005dd0c0)[iVar2] = (&DAT_005dd0c0)[iVar2] | uVar4;

          }

          else {

            (&DAT_005dd0c0)[iVar2] = (&DAT_005dd0c0)[iVar2] & ~(1 << (bVar1 & 0x1f));

          }

          ppuVar5 = ppuVar5 + 5;

          piVar3 = (int *)((int)piVar3 + -1);

        } while (piVar3 != (int *)0x0);

      }

      if (DAT_00633104 != 0) {

        dinput_device_check();

        return 1;

      }

    }

  }

  return 1;

}

/* ===== input_keystate_update @ 0x00519A50 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined4 input_keystate_update(void)



{

  uint *puVar1;

  int *piStack_24;

  int *piStack_20;

  undefined4 uStack_1c;

  undefined1 *puStack_18;

  uint local_14;

  uint local_10;

  undefined4 local_c;

  undefined4 local_8;

  undefined4 local_4;

  

  puStack_18 = (undefined1 *)&local_14;

  puVar1 = &DAT_005dd100;

  do {

    puVar1[0x10] = ~puVar1[0x18] & *puVar1;

    puVar1[8] = ~puVar1[0x18] & puVar1[-8];

    *puVar1 = ~puVar1[-0x10] & puVar1[0x18];

    puVar1[-8] = puVar1[-0x10];

    puVar1[0x18] = puVar1[-0x10];

    puVar1 = puVar1 + 1;

  } while ((int)puVar1 < 0x5dd120);

  if ((DAT_00633104 == 0) && (DAT_005dd180 != (int *)0x0)) {

    local_14 = 0;

    local_10 = 0;

    local_c = 0;

    local_8 = 0;

    local_4 = 0;

    uStack_1c = 0x14;

    piStack_20 = DAT_005dd180;

    piStack_24 = (int *)0x519ad0;

    DAT_005ddb7c = (**(code **)(*DAT_005dd180 + 0x24))();

    if ((DAT_005ddb7c == -0x7ff8ffe2) || (DAT_005ddb7c == -0x7ff8fff4)) {

      piStack_24 = DAT_005dd180;

      (**(code **)(*DAT_005dd180 + 0x1c))();

      DAT_005ddb7c = (**(code **)(*DAT_005dd180 + 0x24))(DAT_005dd180,0x14,&piStack_24);

    }

    if (DAT_005ddb7c == 0) {

      DAT_005dd21c = piStack_20;

      DAT_005dd220 = uStack_1c;

      DAT_005dd224 = puStack_18;

      _DAT_005dd234 =

           (((((local_14 >> 8 & 0x80 | (local_14 & 0xff) >> 1) >> 1 | local_14 >> 0x10 & 0x80) >> 1

             | local_14 >> 0x18 & 0x80) >> 1 | local_10 & 0x80) >> 2 | local_10 >> 0x10 & 0x80) >> 1

           | local_10 >> 0x18 & 0x80;

      _DAT_005dd240 = ~DAT_005dd244 & _DAT_005dd234;

      _DAT_005dd23c = ~_DAT_005dd234 & DAT_005dd244;

      _DAT_005dd238 = _DAT_005dd234;

      DAT_005dd244 = _DAT_005dd234;

    }

  }

  return 1;

}

/* ===== anim_dump_user @ 0x00519BE0 ===== */
undefined4 anim_dump_user(void)



{

  ANM_DumpCluster();

  if (DAT_005dd0bc != (int *)0x0) {

    (**(code **)(*DAT_005dd0bc + 0x20))(DAT_005dd0bc);

    (**(code **)(*DAT_005dd0bc + 8))(DAT_005dd0bc);

    DAT_005dd0bc = (int *)0x0;

  }

  if (DAT_005dd180 != (int *)0x0) {

    ReleaseCapture();

    (**(code **)(*DAT_005dd180 + 0x20))(DAT_005dd180);

    (**(code **)(*DAT_005dd180 + 8))(DAT_005dd180);

    DAT_005dd180 = (int *)0x0;

  }

  if (DAT_005dd184 != (int *)0x0) {

    (**(code **)(*DAT_005dd184 + 0x20))(DAT_005dd184);

    (**(code **)(*DAT_005dd184 + 8))(DAT_005dd184);

    DAT_005dd184 = (int *)0x0;

  }

  if (DAT_005dd0b8 != (int *)0x0) {

    (**(code **)(*DAT_005dd0b8 + 8))(DAT_005dd0b8);

    DAT_005dd0b8 = (int *)0x0;

  }

  return 1;

}

/* ===== wredit_00519c70 @ 0x00519C70 ===== */
void wredit_00519c70(void)



{

  int iVar1;

  undefined4 *puVar2;

  

  puVar2 = (undefined4 *)&DAT_0057c9fc;

  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar2 = 0x20202020;

    puVar2 = puVar2 + 1;

  }

  PTR_DAT_0057ca1c = &DAT_0057c9fc;

  DAT_005dd248 = 0;

  return;

}

/* ===== FUN_00519ca0 @ 0x00519CA0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_00519ca0(int param_1)



{

  if ((0x1f < param_1) || (param_1 == 8)) {

    *PTR_DAT_0057ca1c = (char)param_1;

    PTR_DAT_0057ca1c = PTR_DAT_0057ca1c + 1;

    if ((undefined *)0x57ca1b < PTR_DAT_0057ca1c) {

      PTR_DAT_0057ca1c = &DAT_0057c9fc;

    }

    DAT_005dd248 = DAT_005dd248 + 1;

    _DAT_005dd270 = 1;

  }

  return;

}

/* ===== FUN_00519CF0 @ 0x00519CF0 ===== */
undefined4 * FUN_00519CF0(void)



{

  int iVar1;

  int iVar2;

  undefined4 *puVar3;

  undefined4 *puVar4;

  

  iVar1 = DAT_005dd248;

  puVar3 = (undefined4 *)&DAT_0057c9fc;

  puVar4 = &DAT_005dd24c;

  for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {

    *puVar4 = *puVar3;

    puVar3 = puVar3 + 1;

    puVar4 = puVar4 + 1;

  }

  if (iVar1 < 0x20) {

    *(undefined1 *)((int)&DAT_005dd24c + iVar1) = 0;

    return &DAT_005dd24c;

  }

  DAT_005dd26c._0_1_ = 0;

  return &DAT_005dd24c;

}

/* ===== FUN_00519d30 @ 0x00519D30 ===== */
undefined4 * FUN_00519d30(void)



{

  int iVar1;

  undefined *puVar2;

  uint uVar3;

  uint uVar4;

  undefined4 *puVar5;

  undefined4 *puVar6;

  

  puVar2 = PTR_DAT_0057ca1c;

  iVar1 = -(int)PTR_DAT_0057ca1c;

  uVar3 = (int)&PTR_DAT_0057ca1c + iVar1;

  puVar5 = (undefined4 *)PTR_DAT_0057ca1c;

  puVar6 = &DAT_005dd24c;

  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {

    *puVar6 = *puVar5;

    puVar5 = puVar5 + 1;

    puVar6 = puVar6 + 1;

  }

  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {

    *(undefined1 *)puVar6 = *(undefined1 *)puVar5;

    puVar5 = (undefined4 *)((int)puVar5 + 1);

    puVar6 = (undefined4 *)((int)puVar6 + 1);

  }

  puVar5 = (undefined4 *)&DAT_0057c9fc;

  puVar6 = (undefined4 *)(iVar1 + 0xb59c68);

  for (uVar3 = (uint)(puVar2 + -0x57c9fc) >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {

    *puVar6 = *puVar5;

    puVar5 = puVar5 + 1;

    puVar6 = puVar6 + 1;

  }

  for (uVar3 = (uint)(puVar2 + -0x57c9fc) & 3; uVar3 != 0; uVar3 = uVar3 - 1) {

    *(undefined1 *)puVar6 = *(undefined1 *)puVar5;

    puVar5 = (undefined4 *)((int)puVar5 + 1);

    puVar6 = (undefined4 *)((int)puVar6 + 1);

  }

  DAT_005dd26c._0_1_ = 0;

  return &DAT_005dd26c;

}

/* ===== filecopy_dirs @ 0x00519D90 ===== */
void filecopy_dirs(void)



{

  code *pcVar1;

  code *pcVar2;

  DWORD local_108;

  DWORD local_104;

  BYTE local_100 [256];

  

  pcVar2 = RegCreateKeyExA_exref;

  if (DAT_005dd274 != (HKEY)0x0) {

    return;

  }

  RegCreateKeyExA((HKEY)0x80000001,s_Software_PlanetMoon_Giants_0057cb20,0,(LPSTR)0x0,0,0xf003f,

                  (LPSECURITY_ATTRIBUTES)0x0,&DAT_005dd274,&local_104);

  RegCreateKeyExA(DAT_005dd274,&DAT_0057cb1c,0,(LPSTR)0x0,0,0xf003f,(LPSECURITY_ATTRIBUTES)0x0,

                  &DAT_005dd278,&local_104);

  if (DAT_0063304c != '\0') {

    if (DAT_005dd27c != (HKEY)0x0) {

      RegCloseKey(DAT_005dd27c);

      DAT_005dd27c = (HKEY)0x0;

    }

    RegCreateKeyExA(DAT_005dd278,&DAT_0063304c,0,(LPSTR)0x0,0,0xf003f,(LPSECURITY_ATTRIBUTES)0x0,

                    &DAT_005dd27c,&local_108);

  }

  pcVar1 = RegQueryValueExA_exref;

  local_100[0] = '\0';

  if (DAT_005dd274 != (HKEY)0x0) {

    local_108 = 0x100;

    RegQueryValueExA(DAT_005dd274,s_DestDir_0057cb14,(LPDWORD)0x0,(LPDWORD)0x0,local_100,&local_108)

    ;

    pcVar2 = pcVar1;

    if (local_100[0] != '\0') goto LAB_00519e83;

  }

  PostQuitMessage(0);

  BinFileCreateWrite_4(0);

LAB_00519e83:

  local_104._0_1_ = '\0';

  if ((DAT_005dd274 != (HKEY)0x0) &&

     ((*pcVar2)(DAT_005dd274,s_SrcDir_0057cb0c,0,0,&local_104,&stack0xfffffef4),

     (char)local_104 != '\0')) {

    return;

  }

  PostQuitMessage(0);

  BinFileCreateWrite_4(0);

  return;

}

/* ===== reg_close_key @ 0x00519ED0 ===== */
void reg_close_key(void)



{

  if (DAT_005dd274 != (HKEY)0x0) {

    if (DAT_005dd27c != (HKEY)0x0) {

      RegCloseKey(DAT_005dd27c);

      DAT_005dd27c = (HKEY)0x0;

    }

    RegCloseKey(DAT_005dd278);

    DAT_005dd278 = (HKEY)0x0;

    RegCloseKey(DAT_005dd274);

    DAT_005dd274 = (HKEY)0x0;

  }

  return;

}

/* ===== FUN_00519F20 @ 0x00519F20 ===== */
int FUN_00519F20(DWORD *param_1,DWORD param_2,LPCSTR param_3)



{

  LPCSTR lpSubKey;

  int iVar1;

  DWORD local_4;

  

  lpSubKey = param_3;

  local_4 = param_2;

  iVar1 = RegEnumKeyExA(DAT_005dd278,*param_1,param_3,&local_4,(LPDWORD)0x0,(LPSTR)0x0,(LPDWORD)0x0,

                        (PFILETIME)0x0);

  if (iVar1 == 0) {

    if (DAT_005dd27c != (HKEY)0x0) {

      RegCloseKey(DAT_005dd27c);

      DAT_005dd27c = (HKEY)0x0;

    }

    RegCreateKeyExA(DAT_005dd278,lpSubKey,0,(LPSTR)0x0,0,0xf003f,(LPSECURITY_ATTRIBUTES)0x0,

                    &DAT_005dd27c,(LPDWORD)&param_3);

    param_2 = 0;

    if (DAT_005dd27c != (HKEY)0x0) {

      param_3 = (LPCSTR)0x4;

      RegQueryValueExA(DAT_005dd27c,s_Deleted_0055bf90,(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)&param_2,

                       (LPDWORD)&param_3);

    }

    *param_1 = *param_1 + 1;

    iVar1 = -(uint)(param_2 != 0);

  }

  return iVar1;

}

/* ===== reg_open_key @ 0x00519FE0 ===== */
/* PS2 candidate: tex_freeTexBuf__Fv (conf 0.597) */



void reg_open_key(LPCSTR param_1)



{

  DWORD local_4;

  

  if (DAT_005dd27c != (HKEY)0x0) {

    RegCloseKey(DAT_005dd27c);

    DAT_005dd27c = (HKEY)0x0;

  }

  RegCreateKeyExA(DAT_005dd278,param_1,0,(LPSTR)0x0,0,0xf003f,(LPSECURITY_ATTRIBUTES)0x0,

                  &DAT_005dd27c,&local_4);

  return;

}

/* ===== reg_query_value_2 @ 0x0051A030 ===== */
void reg_query_value_2(LPCSTR param_1,LPBYTE param_2,DWORD param_3)



{

  LPBYTE lpData;

  

  lpData = param_2;

  *param_2 = '\0';

  if (DAT_005dd27c != (HKEY)0x0) {

    param_2 = (LPBYTE)param_3;

    RegQueryValueExA(DAT_005dd27c,param_1,(LPDWORD)0x0,(LPDWORD)0x0,lpData,(LPDWORD)&param_2);

  }

  return;

}

/* ===== reg_query_value_3 @ 0x0051A060 ===== */
void reg_query_value_3(LPCSTR param_1,LPBYTE param_2,DWORD param_3)



{

  if (DAT_005dd27c != (HKEY)0x0) {

    RegQueryValueExA(DAT_005dd27c,param_1,(LPDWORD)0x0,(LPDWORD)0x0,param_2,&param_3);

  }

  return;

}

/* ===== reg_set_value_2 @ 0x0051A090 ===== */
void reg_set_value_2(LPCSTR param_1,BYTE *param_2)



{

  BYTE BVar1;

  uint uVar2;

  BYTE *pBVar3;

  

  if (DAT_005dd27c != (HKEY)0x0) {

    uVar2 = 0xffffffff;

    pBVar3 = param_2;

    do {

      if (uVar2 == 0) break;

      uVar2 = uVar2 - 1;

      BVar1 = *pBVar3;

      pBVar3 = pBVar3 + 1;

    } while (BVar1 != '\0');

    RegSetValueExA(DAT_005dd27c,param_1,0,1,param_2,~uVar2);

  }

  return;

}

/* ===== mission_0051a0c0 @ 0x0051A0C0 ===== */
void mission_0051a0c0(LPCSTR param_1,LPBYTE param_2)



{

  LPBYTE lpData;

  

  lpData = param_2;

  param_2[0] = '\0';

  param_2[1] = '\0';

  param_2[2] = '\0';

  param_2[3] = '\0';

  if (DAT_005dd27c != (HKEY)0x0) {

    param_2 = (LPBYTE)0x4;

    RegQueryValueExA(DAT_005dd27c,param_1,(LPDWORD)0x0,(LPDWORD)0x0,lpData,(LPDWORD)&param_2);

  }

  return;

}

/* ===== keymap_0051a100 @ 0x0051A100 ===== */
void keymap_0051a100(LPCSTR param_1,LPBYTE param_2)



{

  DWORD local_4;

  

  if (DAT_005dd27c != (HKEY)0x0) {

    local_4 = 4;

    RegQueryValueExA(DAT_005dd27c,param_1,(LPDWORD)0x0,(LPDWORD)0x0,param_2,&local_4);

  }

  return;

}

/* ===== comm_0051a130 @ 0x0051A130 ===== */
void comm_0051a130(LPCSTR param_1)



{

  if (DAT_005dd27c != (HKEY)0x0) {

    RegSetValueExA(DAT_005dd27c,param_1,0,4,&stack0x00000008,4);

  }

  return;

}

/* ===== reg_query_value_4 @ 0x0051A160 ===== */
void reg_query_value_4(LPCSTR param_1,LPBYTE param_2,DWORD param_3)



{

  RegQueryValueExA(DAT_005dd27c,param_1,(LPDWORD)0x0,(LPDWORD)0x0,param_2,&param_3);

  return;

}

/* ===== reg_set_value @ 0x0051A190 ===== */
/* PS2 candidate: player_display_info_2 (conf 0.827) */



void reg_set_value(LPCSTR param_1,BYTE *param_2,DWORD param_3)



{

  if (DAT_005dd27c != (HKEY)0x0) {

    RegSetValueExA(DAT_005dd27c,param_1,0,3,param_2,param_3);

  }

  return;

}

/* ===== reg_query_value_5 @ 0x0051A1C0 ===== */
void reg_query_value_5(LPCSTR param_1,LPBYTE param_2,DWORD param_3)



{

  LPBYTE lpData;

  

  lpData = param_2;

  *param_2 = '\0';

  if (DAT_005dd274 != (HKEY)0x0) {

    param_2 = (LPBYTE)param_3;

    RegQueryValueExA(DAT_005dd274,param_1,(LPDWORD)0x0,(LPDWORD)0x0,lpData,(LPDWORD)&param_2);

  }

  return;

}

/* ===== reg_set_value_3 @ 0x0051A1F0 ===== */
void reg_set_value_3(LPCSTR param_1,BYTE *param_2)



{

  BYTE BVar1;

  uint uVar2;

  BYTE *pBVar3;

  

  if (DAT_005dd274 != (HKEY)0x0) {

    uVar2 = 0xffffffff;

    pBVar3 = param_2;

    do {

      if (uVar2 == 0) break;

      uVar2 = uVar2 - 1;

      BVar1 = *pBVar3;

      pBVar3 = pBVar3 + 1;

    } while (BVar1 != '\0');

    RegSetValueExA(DAT_005dd274,param_1,0,1,param_2,~uVar2);

  }

  return;

}

/* ===== reg_query_value_6 @ 0x0051A220 ===== */
void reg_query_value_6(LPCSTR param_1,LPBYTE param_2)



{

  DWORD local_4;

  

  if (DAT_005dd274 != (HKEY)0x0) {

    local_4 = 4;

    RegQueryValueExA(DAT_005dd274,param_1,(LPDWORD)0x0,(LPDWORD)0x0,param_2,&local_4);

  }

  return;

}

/* ===== reg_set_value_4 @ 0x0051A250 ===== */
void reg_set_value_4(LPCSTR param_1)



{

  if (DAT_005dd274 != (HKEY)0x0) {

    RegSetValueExA(DAT_005dd274,param_1,0,4,&stack0x00000008,4);

  }

  return;

}

/* ===== stream_0051a280 @ 0x0051A280 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined4 stream_0051a280(char *param_1,undefined4 param_2)



{

  HMODULE hModule;

  undefined4 local_20c;

  undefined4 local_208;

  undefined4 local_204;

  CHAR local_200 [512];

  

  if ((param_1 != (char *)0x0) && (*param_1 != '\0')) {

    crt_sprintf(local_200,s__s_gs__s_0057d6d4,param_1,param_2);

    hModule = GetModuleHandleA(local_200);

    if (hModule != (HMODULE)0x0) goto LAB_0051a310;

    hModule = LoadLibraryA(local_200);

    if (hModule != (HMODULE)0x0) goto LAB_0051a310;

  }

  crt_sprintf(local_200,s_gs__s_0057d6cc,param_2);

  hModule = GetModuleHandleA(local_200);

  if (hModule == (HMODULE)0x0) {

    hModule = LoadLibraryA(local_200);

    if (hModule == (HMODULE)0x0) {

      return 0;

    }

  }

LAB_0051a310:

  DAT_005dd280 = GetProcAddress(hModule,s_SDVInit_0057d6c4);

  if (DAT_005dd280 == (FARPROC)0x0) {

    error_screen_exit(s_Failed_to_load_SDVInit_0057d6ac);

    return 0;

  }

  DAT_005dd284 = GetProcAddress(hModule,s_SDVFinit_0057d6a0);

  if (DAT_005dd284 == (FARPROC)0x0) {

    error_screen_exit(s_Failed_to_load_SDVFinit_0057d688);

    return 0;

  }

  DAT_005dd288 = GetProcAddress(hModule,s_SDVPause_0057d67c);

  if (DAT_005dd288 == (FARPROC)0x0) {

    error_screen_exit(s_Failed_to_load_SDVPause_0057d664);

    return 0;

  }

  DAT_005dd28c = GetProcAddress(hModule,s_SDVResume_0057d658);

  if (DAT_005dd28c == (FARPROC)0x0) {

    error_screen_exit(s_Failed_to_load_SDVResume_0057d63c);

    return 0;

  }

  DAT_005dd290 = GetProcAddress(hModule,s_SDVSilence_0057d630);

  if (DAT_005dd290 == (FARPROC)0x0) {

    error_screen_exit(s_Failed_to_load_SDVSilence_0057d614);

    return 0;

  }

  DAT_005dd294 = GetProcAddress(hModule,s_SDVProcess_0057d608);

  if (DAT_005dd294 == (FARPROC)0x0) {

    error_screen_exit(s_Failed_to_load_SDVProcess_0057d5ec);

    return 0;

  }

  _DAT_005dd298 = GetProcAddress(hModule,s_SDVPreLoad_0057d5e0);

  if (_DAT_005dd298 == (FARPROC)0x0) {

    error_screen_exit(s_Failed_to_load_SDVPreLoad_0057d5c4);

    return 0;

  }

  DAT_005dd29c = GetProcAddress(hModule,s_SDVUnLoad_0057d5b8);

  if (DAT_005dd29c == (FARPROC)0x0) {

    error_screen_exit(s_Failed_to_load_SDVUnLoad_0057d59c);

    return 0;

  }

  DAT_005dd2a0 = GetProcAddress(hModule,s_SDVStopObject_0057d58c);

  if (DAT_005dd2a0 == (FARPROC)0x0) {

    error_screen_exit(s_Failed_to_load_SDVStopObject_0057d56c);

    return 0;

  }

  _DAT_005dd2a4 = GetProcAddress(hModule,s_SDVStopSample_0057d55c);

  if (_DAT_005dd2a4 == (FARPROC)0x0) {

    error_screen_exit(s_Failed_to_load_SDVStopSample_0057d53c);

    return 0;

  }

  DAT_005dd2a8 = GetProcAddress(hModule,s_SDVStopInstance_0057d52c);

  if (DAT_005dd2a8 == (FARPROC)0x0) {

    error_screen_exit(s_Failed_to_load_SDVStopInstance_0057d50c);

    return 0;

  }

  DAT_005dd2ac = GetProcAddress(hModule,s_SDVStart3DObj_0057d4fc);

  if (DAT_005dd2ac == (FARPROC)0x0) {

    error_screen_exit(s_Failed_to_load_SDVStart3DObj_0057d4dc);

    return 0;

  }

  DAT_005dd2b0 = GetProcAddress(hModule,s_SDVStart3DPos_0057d4cc);

  if (DAT_005dd2b0 == (FARPROC)0x0) {

    error_screen_exit(s_Failed_to_load_SDVStart3DPos_0057d4ac);

    return 0;

  }

  DAT_005dd2b4 = GetProcAddress(hModule,s_SDVStart2DSample_0057d498);

  if (DAT_005dd2b4 == (FARPROC)0x0) {

    error_screen_exit(s_Failed_to_load_SDVStart2DSample_0057d478);

    return 0;

  }

  _DAT_005dd2b8 = GetProcAddress(hModule,s_SDVSetVolumeInstance_0057d460);

  if (_DAT_005dd2b8 == (FARPROC)0x0) {

    error_screen_exit(s_Failed_to_load_SDVSetVolumeInsta_0057d43c);

    return 0;

  }

  DAT_005dd2bc = GetProcAddress(hModule,s_SDVSetVolPCTInstance_0057d424);

  if (DAT_005dd2bc == (FARPROC)0x0) {

    error_screen_exit(s_Failed_to_load_SDVSetVolPCTInsta_0057d400);

    return 0;

  }

  _DAT_005dd2c0 = GetProcAddress(hModule,s_SDVSoundFastIsPlayingInst_0057d3e4);

  if (_DAT_005dd2c0 == (FARPROC)0x0) {

    error_screen_exit(s_Failed_to_load_SDVSoundFastIsPla_0057d3b8);

    return 0;

  }

  DAT_005dd2c4 = GetProcAddress(hModule,s_SDVGetInstance_0057d3a8);

  if (DAT_005dd2c4 == (FARPROC)0x0) {

    error_screen_exit(s_Failed_to_load_SDVGetInstance_0057d388);

    return 0;

  }

  _DAT_005dd2c8 = GetProcAddress(hModule,s_SDVGetMinMaxDistances_0057d370);

  if (_DAT_005dd2c8 == (FARPROC)0x0) {

    error_screen_exit(s_Failed_to_load_SDVGetMinMaxDista_0057d348);

    return 0;

  }

  DAT_005dd2cc = GetProcAddress(hModule,s_SDVSetGlobalVolume_0057d334);

  if (DAT_005dd2cc == (FARPROC)0x0) {

    error_screen_exit(s_Failed_to_load_SDVSetGlobalVolum_0057d310);

    return 0;

  }

  _DAT_005dd2d0 = GetProcAddress(hModule,s_SDVSetGlobalControlF_0057d2f8);

  if (_DAT_005dd2d0 == (FARPROC)0x0) {

    error_screen_exit(s_Failed_to_load_SDVSetGlobalContr_0057d2d4);

    return 0;

  }

  DAT_005dd2d4 = GetProcAddress(hModule,s_SDVSetGlobalControlI_0057d2bc);

  if (DAT_005dd2d4 == (FARPROC)0x0) {

    error_screen_exit(s_Failed_to_load_SDVSetGlobalContr_0057d298);

    return 0;

  }

  DAT_005dd2d8 = GetProcAddress(hModule,s_SDVGetGlobalVolume_0057d284);

  if (DAT_005dd2d8 == (FARPROC)0x0) {

    error_screen_exit(s_Failed_to_load_SDVGetGlobalVolum_0057d260);

    return 0;

  }

  _DAT_005dd2dc = GetProcAddress(hModule,s_SDVGetGlobalControlF_0057d248);

  if (_DAT_005dd2dc == (FARPROC)0x0) {

    error_screen_exit(s_Failed_to_load_SDVGetGlobalContr_0057d224);

    return 0;

  }

  DAT_005dd2e0 = GetProcAddress(hModule,s_SDVGetGlobalControlI_0057d20c);

  if (DAT_005dd2e0 == (FARPROC)0x0) {

    error_screen_exit(s_Failed_to_load_SDVGetGlobalContr_0057d1e8);

    return 0;

  }

  _DAT_005dd2e4 = GetProcAddress(hModule,s_SDVGetListenerPosition_0057d1d0);

  if (_DAT_005dd2e4 == (FARPROC)0x0) {

    error_screen_exit(s_Failed_to_load_SDVGetListenerPos_0057d1a8);

    return 0;

  }

  DAT_005dd2e8 = GetProcAddress(hModule,s_SDVGetTime_0057d19c);

  if (DAT_005dd2e8 == (FARPROC)0x0) {

    error_screen_exit(s_Failed_to_load_SDVGetTime_0057d180);

    return 0;

  }

  _DAT_005dd2ec = GetProcAddress(hModule,s_SDVCalcVolume_0057d170);

  if (_DAT_005dd2ec == (FARPROC)0x0) {

    error_screen_exit(s_Failed_to_load_SDVCalcVolume_0057d150);

    return 0;

  }

  _DAT_005dd2f0 = GetProcAddress(hModule,s_SDVWantLoadOccludes_0057d13c);

  if (_DAT_005dd2f0 == (FARPROC)0x0) {

    error_screen_exit(s_Failed_to_load_SDVWantLoadOcclud_0057d118);

    return 0;

  }

  DAT_005dd2f4 = GetProcAddress(hModule,s_SDVOcclusionBox_0057d108);

  if (DAT_005dd2f4 == (FARPROC)0x0) {

    error_screen_exit(s_Failed_to_load_SDVOcclusionBox_0057d0e8);

    return 0;

  }

  _DAT_005dd2f8 = GetProcAddress(hModule,s_SDVDestroyOcclusionBox_0057d0d0);

  if (_DAT_005dd2f8 == (FARPROC)0x0) {

    error_screen_exit(s_Failed_to_load_SDVDestroyOcclusi_0057d0a8);

    return 0;

  }

  DAT_005dd2fc = GetProcAddress(hModule,s_SDVDestroyOcclusionBoxSet_0057d08c);

  if (DAT_005dd2fc == (FARPROC)0x0) {

    error_screen_exit(s_Failed_to_load_SDVDestroyOcclusi_0057d060);

    return 0;

  }

  _DAT_005dd300 = GetProcAddress(hModule,s_SDVUpdateOcclusionBox_0057d048);

  if (_DAT_005dd300 == (FARPROC)0x0) {

    error_screen_exit(s_Failed_to_load_SDVUpdateOcclusio_0057d020);

    return 0;

  }

  _DAT_005dd304 = GetProcAddress(hModule,s_SDVOcclusionParms_0057d00c);

  if (_DAT_005dd304 == (FARPROC)0x0) {

    error_screen_exit(s_Failed_to_load_SDVOcclusionParms_0057cfe8);

    return 0;

  }

  DAT_005dd308 = GetProcAddress(hModule,s_SDVHWLoadWorld_0057cfd8);

  if (DAT_005dd308 == (FARPROC)0x0) {

    error_screen_exit(s_Failed_to_load_SDVHWLoadWorld_0057cfb8);

    return 0;

  }

  DAT_005dd364 = GetProcAddress(hModule,s_SDVUpCallsLoad_0057cfa8);

  if (DAT_005dd364 == (FARPROC)0x0) {

    error_screen_exit(s_Failed_to_load_SDVUpCallsLoad_0057cf88);

    return 0;

  }

  DAT_005dd30c = GetProcAddress(hModule,s_MDVInit_0057cf80);

  if (DAT_005dd30c == (FARPROC)0x0) {

    error_screen_exit(s_Failed_to_load_MDVInit_0057cf68);

    return 0;

  }

  DAT_005dd310 = GetProcAddress(hModule,s_MDVFinit_0057cf5c);

  if (DAT_005dd310 == (FARPROC)0x0) {

    error_screen_exit(s_Failed_to_load_MDVFinit_0057cf44);

    return 0;

  }

  DAT_005dd314 = GetProcAddress(hModule,s_MDVProcess_0057cf38);

  if (DAT_005dd314 == (FARPROC)0x0) {

    error_screen_exit(s_Failed_to_load_MDVProcess_0057cf1c);

    return 0;

  }

  DAT_005dd318 = GetProcAddress(hModule,s_MDVPlaySong_0057cf10);

  if (DAT_005dd318 == (FARPROC)0x0) {

    error_screen_exit(s_Failed_to_load_MDVPlaySong_0057cef4);

    return 0;

  }

  DAT_005dd31c = GetProcAddress(hModule,s_MDVStopSong_0057cee8);

  if (DAT_005dd31c == (FARPROC)0x0) {

    error_screen_exit(s_Failed_to_load_MDVStopSong_0057cecc);

    return 0;

  }

  _DAT_005dd320 = GetProcAddress(hModule,s_MDVGetPlayList_0057cebc);

  if (_DAT_005dd320 == (FARPROC)0x0) {

    error_screen_exit(s_Failed_to_load_MDVGetPlayList_0057ce9c);

    return 0;

  }

  DAT_005dd324 = GetProcAddress(hModule,s_MDVGetSongPlaying_0057ce88);

  if (DAT_005dd324 == (FARPROC)0x0) {

    error_screen_exit(s_Failed_to_load_MDVGetSongPlaying_0057ce64);

    return 0;

  }

  DAT_005dd328 = GetProcAddress(hModule,s_MDVIsJumping_0057ce54);

  if (DAT_005dd328 == (FARPROC)0x0) {

    error_screen_exit(s_Failed_to_load_MDVIsJumping_0057ce38);

    return 0;

  }

  DAT_005dd32c = GetProcAddress(hModule,s_MDVSetGlobalVolume_0057ce24);

  if (DAT_005dd32c == (FARPROC)0x0) {

    error_screen_exit(s_Failed_to_load_MDVSetGlobalVolum_0057ce00);

    return 0;

  }

  _DAT_005dd330 = GetProcAddress(hModule,s_MDVSetGlobalControlF_0057cde8);

  if (_DAT_005dd330 == (FARPROC)0x0) {

    error_screen_exit(s_Failed_to_load_MDVSetGlobalContr_0057cdc4);

    return 0;

  }

  _DAT_005dd334 = GetProcAddress(hModule,s_MDVSetGlobalControlI_0057cdac);

  if (_DAT_005dd334 == (FARPROC)0x0) {

    error_screen_exit(s_Failed_to_load_MDVSetGlobalContr_0057cd88);

    return 0;

  }

  DAT_005dd338 = GetProcAddress(hModule,s_MDVGetGlobalVolume_0057cd74);

  if (DAT_005dd338 == (FARPROC)0x0) {

    error_screen_exit(s_Failed_to_load_MDVGetGlobalVolum_0057cd50);

    return 0;

  }

  _DAT_005dd33c = GetProcAddress(hModule,s_MDVGetGlobalControlF_0057cd38);

  if (_DAT_005dd33c == (FARPROC)0x0) {

    error_screen_exit(s_Failed_to_load_MDVGetGlobalContr_0057cd14);

    return 0;

  }

  _DAT_005dd340 = GetProcAddress(hModule,s_MDVGetGlobalControlI_0057ccfc);

  if (_DAT_005dd340 == (FARPROC)0x0) {

    error_screen_exit(s_Failed_to_load_MDVGetGlobalContr_0057ccd8);

    return 0;

  }

  DAT_005dd344 = GetProcAddress(hModule,s_VDVSilence_0057cccc);

  if (DAT_005dd344 == (FARPROC)0x0) {

    error_screen_exit(s_Failed_to_load_VDVSilence_0057ccb0);

    return 0;

  }

  _DAT_005dd348 = GetProcAddress(hModule,s_VDVPlayStream_0057cca0);

  if (_DAT_005dd348 == (FARPROC)0x0) {

    error_screen_exit(s_Failed_to_load_VDVPlayStream_0057cc80);

    return 0;

  }

  _DAT_005dd34c = GetProcAddress(hModule,s_VDVPlayStreamSync_0057cc6c);

  if (_DAT_005dd34c == (FARPROC)0x0) {

    error_screen_exit(s_Failed_to_load_VDVPlayStreamSync_0057cc48);

    return 0;

  }

  _DAT_005dd350 = GetProcAddress(hModule,s_VDVGetStreamSyncTime_0057cc30);

  if (_DAT_005dd350 == (FARPROC)0x0) {

    error_screen_exit(s_Failed_to_load_VDVGetStreamSyncT_0057cc0c);

    return 0;

  }

  DAT_005dd354 = GetProcAddress(hModule,s_VDVStopStream_0057cbfc);

  if (DAT_005dd354 == (FARPROC)0x0) {

    error_screen_exit(s_Failed_to_load_VDVStopStream_0057cbdc);

    return 0;

  }

  DAT_005dd358 = GetProcAddress(hModule,s_VDVIsPlayingStream_0057cbc8);

  if (DAT_005dd358 == (FARPROC)0x0) {

    error_screen_exit(s_Failed_to_load_VDVIsPlayingStrea_0057cba4);

    return 0;

  }

  _DAT_005dd35c = GetProcAddress(hModule,s_VDVSetVolPCTStream_0057cb90);

  if (_DAT_005dd35c == (FARPROC)0x0) {

    error_screen_exit(s_Failed_to_load_VDVSetVolPCTStrea_0057cb6c);

    return 0;

  }

  DAT_005dd360 = GetProcAddress(hModule,s_VDVFinitStreams_0057cb5c);

  if (DAT_005dd360 == (FARPROC)0x0) {

    error_screen_exit(s_Failed_to_load_VDVFinitStreams_0057cb3c);

    return 0;

  }

  DAT_005dd364 = GetProcAddress(hModule,s_UpCallsLoad_0057c9b4);

  if (DAT_005dd364 == (FARPROC)0x0) {

    error_screen_exit(s_Failed_to_load_UpCallsLoad_0057c998);

    return 0;

  }

  _DAT_005dd368 = 1;

  _lmcGetClientPtr(&local_208,&local_20c,&local_204);

  (*DAT_005dd364)(local_208,local_20c,local_204);

  return 1;

}

/* ===== FUN_0051ad50 @ 0x0051AD50 ===== */
void FUN_0051ad50(undefined4 param_1)



{

  crt_vobuf_alloc(0,0,&LAB_0051ad70,param_1,0,&param_1);

  return;

}

/* ===== FUN_0051ad80 @ 0x0051AD80 ===== */
void FUN_0051ad80(char *param_1,size_t param_2)



{

  if (0x3f < param_2) {

    param_2 = 0x3f;

  }

  _strncpy(&DAT_005dd8d0,param_1,param_2);

  (&DAT_005dd8d0)[param_2] = 0;

  return;

}

/* ===== textrender_texture_alloc @ 0x0051B1C0 ===== */
void textrender_texture_alloc(int param_1)



{

  uint uVar1;

  int iVar2;

  int iVar3;

  uint uVar4;

  int iVar5;

  byte *pbVar6;

  int iVar7;

  undefined2 *puVar8;

  CHAR local_24 [4];

  uint local_20;

  uint local_1c;

  int local_18;

  int local_14;

  byte *local_10;

  byte *local_c;

  tagSIZE local_8;

  

  local_c = &DAT_005dd3c2 + param_1 * 5;

  if ((&DAT_005dd3c2)[param_1 * 5] == '\0') {

    GdiFlush();

    pbVar6 = DAT_005dd8c0;

    for (iVar2 = 0x100; iVar2 != 0; iVar2 = iVar2 + -1) {

      pbVar6[0] = 0;

      pbVar6[1] = 0;

      pbVar6[2] = 0;

      pbVar6[3] = 0;

      pbVar6 = pbVar6 + 4;

    }

    local_24[1] = 0;

    local_24[0] = (CHAR)param_1;

    GetTextExtentPoint32A(DAT_005dd8c8,local_24,1,&local_8);

    iVar7 = 0;

    TextOutA(DAT_005dd8c8,0,0x20,local_24,1);

    GdiFlush();

    iVar2 = 0x3f;

    local_18 = 0x3f;

    local_14 = 0;

    local_20 = 0x7f;

    local_1c = 0;

    local_10 = DAT_005dd8c0;

    do {

      uVar4 = 0;

      do {

        if (*local_10 != 0) {

          iVar3 = 0;

          uVar1 = uVar4;

          do {

            if (((uint)*local_10 & 0x80 >> ((byte)iVar3 & 0x1f)) != 0) {

              if ((int)uVar1 < (int)local_20) {

                local_20 = uVar1;

              }

              if ((int)local_1c < (int)uVar1) {

                local_1c = uVar1;

              }

              if (iVar7 < iVar2) {

                iVar2 = iVar7;

                local_18 = iVar7;

              }

              if (local_14 < iVar7) {

                local_14 = iVar7;

              }

            }

            iVar3 = iVar3 + 1;

            uVar1 = uVar1 + 1;

          } while (iVar3 < 8);

        }

        local_10 = local_10 + 1;

        uVar4 = uVar4 + 8;

      } while ((int)uVar4 < 0x80);

      iVar7 = iVar7 + 1;

    } while (iVar7 < 0x40);

    if ((int)local_1c < (int)local_20) {

      if (param_1 == 0x20) {

        local_1c = 4;

      }

      else {

        crt_sprintf(&DAT_00657400,s_TextRender_Fail_on__d_0057d7c0,param_1);

        FUN_00425eb0(&DAT_00657400);

        local_1c = 0;

      }

      local_20 = 0;

      local_18 = 0x20;

      local_14 = 0x20;

      iVar2 = 0x20;

    }

    (&DAT_005dd3c0)[param_1 * 5] = ' ' - (char)iVar2;

    (&DAT_005dd3c1)[param_1 * 5] = ((char)local_14 - (char)iVar2) + '\x01';

    *local_c = ((char)local_1c - (char)local_20) + 1;

    if (DAT_005dd398 < local_14 + -0x20) {

      DAT_005dd398 = local_14 + -0x20;

    }

    if (DAT_005dd394 < 0x20 - iVar2) {

      DAT_005dd394 = 0x20 - iVar2;

    }

    if (0x100 - DAT_005dd37c < (int)(uint)*local_c) {

      DAT_005dd378 = DAT_005dd378 + DAT_005dd380;

      DAT_005dd37c = 0;

      DAT_005dd380 = 0;

    }

    if ((int)DAT_005dd380 < (int)(uint)(byte)(&DAT_005dd3c1)[param_1 * 5]) {

      if (0x80 - DAT_005dd378 < (int)(uint)(byte)(&DAT_005dd3c1)[param_1 * 5]) {

        FUN_00425eb0(s_Text_Texture_table_is_full__0057d7a4);

        DAT_005dd378 = 0;

        iVar2 = local_18;

      }

      DAT_005dd380 = (uint)(byte)(&DAT_005dd3c1)[param_1 * 5];

    }

    (&DAT_005dd3c3)[param_1 * 5] = (undefined1)DAT_005dd37c;

    (&DAT_005dd3c4)[param_1 * 5] = (undefined1)DAT_005dd378;

    if (iVar2 <= local_14) {

      iVar3 = iVar2 * 0x80 + local_20;

      iVar7 = iVar2;

      do {

        puVar8 = (undefined2 *)

                 (DAT_005dd39c + (((DAT_005dd378 - iVar2) + iVar7) * 0x100 + DAT_005dd37c) * 2);

        iVar5 = iVar3;

        for (uVar4 = local_20; (int)uVar4 <= (int)local_1c; uVar4 = uVar4 + 1) {

          uVar1 = uVar4 & 0x80000007;

          if ((int)uVar1 < 0) {

            uVar1 = (uVar1 - 1 | 0xfffffff8) + 1;

          }

          if ((DAT_005dd8c0[(int)(iVar5 + (iVar5 >> 0x1f & 7U)) >> 3] &

              (byte)(0x80 >> ((byte)uVar1 & 0x1f))) != 0) {

            *puVar8 = 0xffff;

          }

          puVar8 = puVar8 + 1;

          iVar5 = iVar5 + 1;

          iVar2 = local_18;

        }

        iVar7 = iVar7 + 1;

        iVar3 = iVar3 + 0x80;

      } while (iVar7 <= local_14);

    }

    DAT_005dd390 = 1;

    DAT_005dd37c = DAT_005dd37c + 1 + (uint)*local_c;

  }

  return;

}

/* ===== textrender_text_draw @ 0x0051B500 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void textrender_text_draw

               (uint param_1,undefined4 param_2,float param_3,undefined4 param_4,undefined4 param_5,

               byte *param_6,int param_7)



{

  byte *pbVar1;

  byte bVar2;

  float fVar3;

  float fVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  uint uVar8;

  byte *pbVar9;

  uint uVar10;

  

  win95_text_0051adb0(0x18);

  bVar2 = *param_6;

  pbVar9 = param_6;

  while (bVar2 != 0) {

    textrender_texture_alloc(bVar2);

    pbVar1 = pbVar9 + 1;

    pbVar9 = pbVar9 + 1;

    bVar2 = *pbVar1;

  }

  if (DAT_005dd390 != 0) {

    main_00508840(&DAT_005dd3a0);

    DAT_005dd390 = 0;

  }

  (**(code **)(DAT_00656420 + 0x14))(DAT_00656420);

  iVar5 = __ftol();

  param_1 = param_1 | iVar5 << 0x18;

  (**(code **)(DAT_00656428 + 8))(DAT_00656428,0x6332c,&DAT_005dd3a0,param_1);

  fVar4 = (param_3 / _DAT_005dd8c4) * (float)DAT_00632e88;

  iVar6 = __ftol();

  iVar7 = __ftol();

  param_2 = (float)iVar7;

  uVar10 = param_1;

  fVar3 = (float)iVar6;

  pbVar9 = param_6;

  if (DAT_00632ea0 != 0) {

    param_2 = param_2 + 0.5;

    fVar3 = (float)iVar6 + 0.5;

  }

  do {

    param_6 = (byte *)fVar3;

    if (param_7 < 1) {

      return;

    }

    uVar8 = (uint)*pbVar9;

    param_7 = param_7 + -1;

    if (*pbVar9 < 10) {

      uVar10 = param_1;

      if (uVar8 != 1) {

        uVar10 = *(uint *)(&DAT_0057d6e0 + uVar8 * 4);

      }

      uVar10 = uVar10 | iVar5 << 0x18;

      (**(code **)(DAT_00656428 + 8))(DAT_00656428,0x6332c,&DAT_005dd3a0,uVar10);

    }

    else {

      iVar6 = uVar8 * 5;

      if (&DAT_005dd3c0 + iVar6 == (char *)0x0) {

        return;

      }

      iVar7 = (int)(char)(&DAT_005dd3c0)[iVar6];

      fVar3 = (float)(byte)(&DAT_005dd3c2)[iVar6] * fVar4 + (float)param_6;

      textrender_char_vertex

                (uVar10,param_6,fVar3,param_2 - (float)iVar7 * fVar4,

                 (float)(int)((uint)(byte)(&DAT_005dd3c1)[iVar6] - iVar7) * fVar4 + param_2,uVar8);

      param_6 = (byte *)(fVar3 + fVar4);

    }

    fVar3 = (float)param_6;

    pbVar9 = pbVar9 + 1;

  } while( true );

}

/* ===== textrender_char_vertex @ 0x0051B6E0 ===== */
void textrender_char_vertex

               (undefined4 param_1,undefined4 param_2,undefined4 param_3,float param_4,float param_5

               ,int param_6)



{

  byte bVar1;

  byte bVar2;

  int iVar3;

  undefined4 *puVar4;

  

  iVar3 = param_6 * 5;

  if (iVar3 != -0x5dd3c0) {

    param_4 = (float)DAT_00632e88 - param_4;

    param_5 = (float)DAT_00632e88 - param_5;

    puVar4 = (undefined4 *)(**(code **)(DAT_00656438 + 0x10))(DAT_00656438,4);

    puVar4[1] = param_5;

    *puVar4 = param_2;

    puVar4[4] = param_1;

    puVar4[5] = (float)(byte)(&DAT_005dd3c3)[iVar3] * 0.00390625;

    bVar1 = (&DAT_005dd3c1)[iVar3];

    bVar2 = (&DAT_005dd3c4)[iVar3];

    puVar4[0xb] = param_1;

    puVar4[7] = param_3;

    puVar4[8] = param_5;

    puVar4[6] = (float)((uint)bVar1 + (uint)bVar2) * 0.0078125;

    bVar1 = (&DAT_005dd3c2)[iVar3];

    bVar2 = (&DAT_005dd3c3)[iVar3];

    puVar4[0x12] = param_1;

    puVar4[0xd] = puVar4[6];

    puVar4[0xe] = param_3;

    puVar4[0xf] = param_4;

    puVar4[0xc] = (float)((uint)bVar1 + (uint)bVar2) * 0.00390625;

    puVar4[0x13] = puVar4[0xc];

    bVar1 = (&DAT_005dd3c4)[iVar3];

    puVar4[0x19] = param_1;

    puVar4[0x1a] = puVar4[5];

    puVar4[0x15] = param_2;

    puVar4[0x16] = param_4;

    puVar4[0x14] = (float)bVar1 * 0.0078125;

    puVar4[0x1b] = puVar4[0x14];

    if (DAT_005dd914 != (code *)0x0) {

      (*DAT_005dd914)(param_2,param_3,param_4,param_5,param_6);

    }

  }

  return;

}

/* ===== FUN_0051b810 @ 0x0051B810 ===== */
void FUN_0051b810(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,

                 undefined4 param_5,char *param_6)



{

  char cVar1;

  uint uVar2;

  char *pcVar3;

  

  uVar2 = 0xffffffff;

  pcVar3 = param_6;

  do {

    if (uVar2 == 0) break;

    uVar2 = uVar2 - 1;

    cVar1 = *pcVar3;

    pcVar3 = pcVar3 + 1;

  } while (cVar1 != '\0');

  textrender_text_draw(param_1,param_2,param_3,param_4,param_5,param_6,~uVar2 - 1);

  return;

}

/* ===== textrender_draw_small @ 0x0051B850 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void textrender_draw_small

               (uint param_1,undefined4 param_2,float param_3,float param_4,float param_5,

               int param_6)



{

  int iVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  int iVar6;

  

  fVar2 = param_3 / _DAT_005dd8c4;

  fVar3 = (float)DAT_005dd394;

  textrender_texture_alloc(param_6);

  iVar1 = param_6 * 5;

  if (&DAT_005dd3c0 + iVar1 != (char *)0x0) {

    if (DAT_005dd390 != 0) {

      main_00508840(&DAT_005dd3a0);

      DAT_005dd390 = 0;

    }

    fVar4 = (param_3 / _DAT_005dd8c4) * (float)DAT_00632e88;

    fVar5 = (float)DAT_00632e84;

    fVar2 = (float)DAT_00632e88 * (fVar2 * fVar3 + param_5);

    iVar6 = __ftol();

    param_1 = param_1 | iVar6 << 0x18;

    (**(code **)(DAT_00656428 + 8))(DAT_00656428,0x6332c,&DAT_005dd3a0,param_1);

    iVar6 = (int)(char)(&DAT_005dd3c0)[iVar1];

    textrender_char_vertex

              (param_1,fVar5 * param_4,(float)(byte)(&DAT_005dd3c2)[iVar1] * fVar4 + fVar5 * param_4

               ,fVar2 - (float)iVar6 * fVar4,

               (float)(int)((uint)(byte)(&DAT_005dd3c1)[iVar1] - iVar6) * fVar4 + fVar2,param_6);

  }

  return;

}

/* ===== FUN_0051b970 @ 0x0051B970 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_0051b970(undefined4 param_1,undefined4 param_2,float param_3,undefined4 param_4,

                 float param_5,char *param_6)



{

  char cVar1;

  uint uVar2;

  char *pcVar3;

  

  uVar2 = 0xffffffff;

  pcVar3 = param_6;

  do {

    if (uVar2 == 0) break;

    uVar2 = uVar2 - 1;

    cVar1 = *pcVar3;

    pcVar3 = pcVar3 + 1;

  } while (cVar1 != '\0');

  textrender_text_draw

            (param_1,param_2,param_3,param_4,

             (param_3 / _DAT_005dd8c4) * (float)DAT_005dd394 + param_5,param_6,~uVar2 - 1);

  return;

}

/* ===== FUN_0051b9c0 @ 0x0051B9C0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_0051b9c0(undefined4 param_1,undefined4 param_2,float param_3,undefined4 param_4,

                 float param_5,undefined4 param_6,undefined4 param_7)



{

  textrender_text_draw

            (param_1,param_2,param_3,param_4,

             (param_3 / _DAT_005dd8c4) * (float)DAT_005dd394 + param_5,param_6,param_7);

  return;

}

/* ===== textrender_draw_buffered @ 0x0051BA00 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void textrender_draw_buffered

               (undefined4 param_1,undefined4 param_2,float param_3,float param_4,float param_5,

               byte *param_6)



{

  byte *pbVar1;

  byte bVar2;

  int iVar3;

  float fVar4;

  float fVar5;

  uint uVar6;

  byte *pbVar7;

  

  uVar6 = 0xffffffff;

  pbVar7 = param_6;

  do {

    if (uVar6 == 0) break;

    uVar6 = uVar6 - 1;

    bVar2 = *pbVar7;

    pbVar7 = pbVar7 + 1;

  } while (bVar2 != 0);

  uVar6 = ~uVar6;

  fVar4 = (param_3 / _DAT_005dd8c4) * (float)DAT_00632e88;

  win95_text_0051adb0(0x18);

  bVar2 = *param_6;

  pbVar7 = param_6;

  while (bVar2 != 0) {

    textrender_texture_alloc(bVar2);

    pbVar1 = pbVar7 + 1;

    pbVar7 = pbVar7 + 1;

    bVar2 = *pbVar1;

  }

  fVar5 = 0.0;

  for (pbVar7 = param_6; (uVar6 = uVar6 - 1, 0 < (int)uVar6 && (*pbVar7 != 0)); pbVar7 = pbVar7 + 1)

  {

    if (fVar5 != 0.0) {

      fVar5 = fVar5 + fVar4;

    }

    iVar3 = (uint)*pbVar7 * 5;

    if (iVar3 != -0x5dd3c0) {

      fVar5 = (float)(byte)(&DAT_005dd3c2)[iVar3] * fVar4 + fVar5;

    }

  }

  uVar6 = 0xffffffff;

  pbVar7 = param_6;

  do {

    if (uVar6 == 0) break;

    uVar6 = uVar6 - 1;

    bVar2 = *pbVar7;

    pbVar7 = pbVar7 + 1;

  } while (bVar2 != 0);

  textrender_text_draw

            (param_1,param_2,param_3,param_4 - (fVar5 / (float)DAT_00632e84) * 0.5,

             (param_3 / _DAT_005dd8c4) * (float)DAT_005dd394 + param_5,param_6,~uVar6 - 1);

  return;

}

/* ===== crt_fabs @ 0x0051BC00 ===== */
/* PS2 candidate: lift_logic__FP6OBJECT (conf 0.459) */



float10 crt_fabs(float param_1)



{

  return (float10)param_1;

}

/* ===== textrender_draw_min @ 0x0051BC10 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



float10 textrender_draw_min(float param_1,int param_2)



{

  float fVar1;

  

  fVar1 = (param_1 / _DAT_005dd8c4) * (float)DAT_00632e88;

  textrender_texture_alloc(param_2);

  if (param_2 * 5 == -0x5dd3c0) {

    return (float10)0.0;

  }

  return ((float10)(byte)(&DAT_005dd3c2)[param_2 * 5] * (float10)fVar1 + (float10)fVar1) /

         (float10)DAT_00632e84;

}

/* ===== FUN_0051bc70 @ 0x0051BC70 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



float10 FUN_0051bc70(float param_1)



{

  return ((float10)param_1 / (float10)_DAT_005dd8c4) * (float10)DAT_005dd394;

}

/* ===== textrender_draw_cached @ 0x0051BC90 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



float10 textrender_draw_cached(float param_1,byte *param_2,int param_3)



{

  byte *pbVar1;

  byte bVar2;

  int iVar3;

  float fVar4;

  byte *pbVar5;

  float10 fVar6;

  

  fVar4 = (param_1 / _DAT_005dd8c4) * (float)DAT_00632e88;

  win95_text_0051adb0(0x18);

  bVar2 = *param_2;

  pbVar5 = param_2;

  while (bVar2 != 0) {

    textrender_texture_alloc(bVar2);

    pbVar1 = pbVar5 + 1;

    pbVar5 = pbVar5 + 1;

    bVar2 = *pbVar1;

  }

  fVar6 = (float10)0.0;

  while (0 < param_3) {

    param_3 = param_3 + -1;

    if (*param_2 == 0) break;

    if (fVar6 != (float10)0.0) {

      fVar6 = fVar6 + (float10)fVar4;

    }

    iVar3 = (uint)*param_2 * 5;

    if (iVar3 != -0x5dd3c0) {

      fVar6 = (float10)(byte)(&DAT_005dd3c2)[iVar3] * (float10)fVar4 + fVar6;

    }

    param_2 = param_2 + 1;

  }

  return fVar6 / (float10)DAT_00632e84;

}

/* ===== dlog_0051bd30 @ 0x0051BD30 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



float10 dlog_0051bd30(float param_1,byte *param_2)



{

  byte *pbVar1;

  byte bVar2;

  int iVar3;

  float fVar4;

  uint uVar5;

  byte *pbVar6;

  float10 fVar7;

  

  uVar5 = 0xffffffff;

  pbVar6 = param_2;

  do {

    if (uVar5 == 0) break;

    uVar5 = uVar5 - 1;

    bVar2 = *pbVar6;

    pbVar6 = pbVar6 + 1;

  } while (bVar2 != 0);

  uVar5 = ~uVar5;

  fVar4 = (param_1 / _DAT_005dd8c4) * (float)DAT_00632e88;

  win95_text_0051adb0(0x18);

  bVar2 = *param_2;

  pbVar6 = param_2;

  while (bVar2 != 0) {

    textrender_texture_alloc(bVar2);

    pbVar1 = pbVar6 + 1;

    pbVar6 = pbVar6 + 1;

    bVar2 = *pbVar1;

  }

  fVar7 = (float10)0.0;

  for (; (uVar5 = uVar5 - 1, 0 < (int)uVar5 && (*param_2 != 0)); param_2 = param_2 + 1) {

    if (fVar7 != (float10)0.0) {

      fVar7 = fVar7 + (float10)fVar4;

    }

    iVar3 = (uint)*param_2 * 5;

    if (iVar3 != -0x5dd3c0) {

      fVar7 = (float10)(byte)(&DAT_005dd3c2)[iVar3] * (float10)fVar4 + fVar7;

    }

  }

  return fVar7 / (float10)DAT_00632e84;

}

/* ===== textrender_draw_large @ 0x0051BDE0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



float10 textrender_draw_large(float param_1,byte *param_2)



{

  byte *pbVar1;

  byte bVar2;

  int iVar3;

  float fVar4;

  byte *pbVar5;

  int iVar6;

  float10 fVar7;

  

  bVar2 = *param_2;

  pbVar5 = param_2;

  while ((bVar2 != 0 && (bVar2 != 10))) {

    pbVar1 = pbVar5 + 1;

    pbVar5 = pbVar5 + 1;

    bVar2 = *pbVar1;

  }

  iVar6 = (int)pbVar5 - (int)param_2;

  fVar4 = (param_1 / _DAT_005dd8c4) * (float)DAT_00632e88;

  win95_text_0051adb0(0x18);

  bVar2 = *param_2;

  pbVar5 = param_2;

  while (bVar2 != 0) {

    textrender_texture_alloc(bVar2);

    pbVar1 = pbVar5 + 1;

    pbVar5 = pbVar5 + 1;

    bVar2 = *pbVar1;

  }

  fVar7 = (float10)0.0;

  while (0 < iVar6) {

    iVar6 = iVar6 + -1;

    if (*param_2 == 0) break;

    if (fVar7 != (float10)0.0) {

      fVar7 = fVar7 + (float10)fVar4;

    }

    iVar3 = (uint)*param_2 * 5;

    if (iVar3 != -0x5dd3c0) {

      fVar7 = (float10)(byte)(&DAT_005dd3c2)[iVar3] * (float10)fVar4 + fVar7;

    }

    param_2 = param_2 + 1;

  }

  return fVar7 / (float10)DAT_00632e84;

}

/* ===== FUN_0051bea0 @ 0x0051BEA0 ===== */
/* PS2 candidate: ConvertFwdSlashToBckSlsh__FPc (conf 0.694) */



float10 FUN_0051bea0(float param_1,char *param_2)



{

  char *pcVar1;

  char cVar2;

  int iVar3;

  

  iVar3 = 1;

  cVar2 = *param_2;

  while (cVar2 != '\0') {

    if (cVar2 == '\n') {

      iVar3 = iVar3 + 1;

    }

    pcVar1 = param_2 + 1;

    param_2 = param_2 + 1;

    cVar2 = *pcVar1;

  }

  return (float10)iVar3 * (float10)param_1;

}

/* ===== textrender_draw_main @ 0x0051BED0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void textrender_draw_main(uint param_1,undefined4 *param_2,float param_3,byte *param_4,int param_5)



{

  byte *pbVar1;

  char *pcVar2;

  byte bVar3;

  byte bVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  int iVar8;

  float fVar9;

  float fVar10;

  float fVar11;

  float fVar12;

  float fVar13;

  float fVar14;

  float fVar15;

  float fVar16;

  float fVar17;

  float *pfVar18;

  uint uVar19;

  float *pfVar20;

  byte *pbVar21;

  undefined4 local_78;

  undefined4 local_74;

  undefined4 local_70;

  float fStack_60;

  float fStack_5c;

  float fStack_54;

  char cStack_44;

  float local_40 [3];

  uint local_34;

  float local_30 [12];

  

  local_34 = param_1 | 0xff000000;

  local_30[0] = 2.0;

  local_30[1] = 0.0;

  local_30[2] = 0.0;

  uVar19 = (param_5 != 0) - 1 & 3;

  local_30[3] = 0.0;

  local_30[4] = -2.0;

  local_30[5] = 0.0;

  local_30[6] = 2.0;

  local_30[7] = -2.0;

  local_30[8] = 0.0;

  local_30[9] = 0.0;

  local_30[10] = 0.0;

  local_30[0xb] = 0.0;

  local_40[0] = -1.7014118e+38;

  local_40[1] = -1.7014118e+38;

  local_40[2] = -1.7014118e+38;

  win95_text_0051adb0(0x18);

  bVar3 = *param_4;

  pbVar21 = param_4;

  while (bVar3 != 0) {

    textrender_texture_alloc(bVar3);

    pbVar1 = pbVar21 + 1;

    pbVar21 = pbVar21 + 1;

    bVar3 = *pbVar1;

  }

  if (DAT_005dd390 != 0) {

    main_00508840(&DAT_005dd3a0);

    DAT_005dd390 = 0;

  }

  fVar16 = (param_3 / _DAT_005dd8c4) * (float)DAT_00632e88;

  fVar17 = -fVar16;

  bVar3 = *param_4;

  pbVar21 = param_4;

  while (bVar3 != 0) {

    if ((uint)bVar3 * 5 != -0x5dd3c0) {

      fVar17 = ((float)(byte)(&DAT_005dd3c2)[(uint)bVar3 * 5] + 1.0) * fVar16 + fVar17;

    }

    pbVar1 = pbVar21 + 1;

    pbVar21 = pbVar21 + 1;

    bVar3 = *pbVar1;

  }

  local_78 = *param_2;

  local_74 = param_2[1];

  local_70 = param_2[2];

  hud_screen_project4(&local_78);

  if (uVar19 < 4) {

    pfVar20 = local_30 + uVar19 * 3;

    do {

      fVar5 = local_40[uVar19];

      (**(code **)(DAT_00656428 + 8))(DAT_00656428,0x63328,&DAT_005dd3a0,fVar5);

      bVar3 = *param_4;

      pbVar21 = param_4;

      fVar7 = fVar17 * -0.5;

      while (bVar3 != 0) {

        iVar8 = (uint)*pbVar21 * 5;

        pcVar2 = &DAT_005dd3c0 + iVar8;

        if (pcVar2 != (char *)0x0) {

          fVar6 = (float)(byte)(&DAT_005dd3c2)[iVar8] * fVar16 + fVar7;

          fVar9 = -((float)(int)((uint)(byte)(&DAT_005dd3c1)[iVar8] - (int)*pcVar2) * fVar16) +

                  pfVar20[1];

          fVar10 = (float)(int)*pcVar2 * fVar16 + pfVar20[1];

          fVar11 = fVar6 + *pfVar20;

          fVar7 = fVar7 + *pfVar20;

          if ((((cStack_44 == '\0') && (0.0 <= fStack_60 + fVar7)) &&

              ((float)DAT_00632e84 < fStack_60 + fVar11 ==

               ((float)DAT_00632e84 == fStack_60 + fVar11))) &&

             (((0.0 <= fStack_5c + fVar10 &&

               ((float)DAT_00632e88 < fStack_5c + fVar9 ==

                ((float)DAT_00632e88 == fStack_5c + fVar9))) && (pcVar2 != (char *)0x0)))) {

            pfVar18 = (float *)(**(code **)(DAT_00656438 + 0x10))(DAT_00656438,4);

            fVar12 = (float)(byte)(&DAT_005dd3c3)[iVar8] * 0.00390625;

            bVar3 = (&DAT_005dd3c4)[iVar8];

            bVar4 = (&DAT_005dd3c1)[iVar8];

            fVar13 = (float)((uint)(byte)(&DAT_005dd3c2)[iVar8] + (uint)(byte)(&DAT_005dd3c3)[iVar8]

                            ) * 0.00390625;

            fVar14 = (float)bVar3 * 0.0078125;

            pfVar18[0x15] = fStack_60;

            pfVar18[0xe] = fStack_60;

            pfVar18[7] = fStack_60;

            fVar15 = (float)((uint)bVar4 + (uint)bVar3) * 0.0078125;

            *pfVar18 = fStack_60;

            pfVar18[0x16] = fStack_5c;

            pfVar18[0xf] = fStack_5c;

            pfVar18[8] = fStack_5c;

            pfVar18[1] = fStack_5c;

            pfVar18[0x18] = fStack_54;

            pfVar18[0x11] = fStack_54;

            pfVar18[10] = fStack_54;

            *pfVar18 = fVar7 + *pfVar18;

            pfVar18[3] = fStack_54;

            pfVar18[4] = fVar5;

            pfVar18[0xb] = fVar5;

            pfVar18[0x12] = fVar5;

            pfVar18[1] = fVar10 + pfVar18[1];

            pfVar18[5] = fVar12;

            pfVar18[6] = fVar14;

            pfVar18[7] = fVar7 + pfVar18[7];

            pfVar18[8] = fVar9 + pfVar18[8];

            pfVar18[0xc] = fVar12;

            pfVar18[0xd] = fVar15;

            pfVar18[0xe] = fVar11 + pfVar18[0xe];

            pfVar18[0xf] = fVar9 + pfVar18[0xf];

            pfVar18[0x13] = fVar13;

            pfVar18[0x19] = fVar5;

            pfVar18[0x1b] = fVar14;

            pfVar18[0x14] = fVar15;

            pfVar18[0x15] = fVar11 + pfVar18[0x15];

            pfVar18[0x16] = fVar10 + pfVar18[0x16];

            pfVar18[0x1a] = fVar13;

          }

          fVar7 = fVar6 + fVar16;

        }

        pbVar1 = pbVar21 + 1;

        pbVar21 = pbVar21 + 1;

        bVar3 = *pbVar1;

      }

      uVar19 = uVar19 + 1;

      pfVar20 = pfVar20 + 3;

    } while ((int)uVar19 < 4);

  }

  return;

}

/* ===== _lmcGetClientPtr @ 0x0051C370 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* PS2 candidate: _lmcGetClientPtr (conf 0.576) */



void _lmcGetClientPtr(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)



{

  _DAT_005dd918 = tracer_set_text;

  _DAT_005dd91c = error_screen_exit;

  _DAT_005dd920 = FUN_00425eb0;

  _DAT_005dd924 = FUN_00540310;

  _DAT_005dd928 = &LAB_005179e0;

  _DAT_005dd92c = FUN_00518f00;

  _DAT_005dd930 = &LAB_0051eab0;

  _DAT_005dd934 = &LAB_0049bcd0;

  _DAT_005dd938 = &LAB_0049bcf0;

  _DAT_005dd93c = &LAB_00508090;

  _DAT_005dd940 = texture_destroy;

  _DAT_005dd944 = FUN_00507b00;

  _DAT_005dd948 = XFGetViewportExt;

  _DAT_005dd94c = sine_cos_lookup;

  _DAT_005dd950 = &LAB_00518930;

  _DAT_005dd954 = &LAB_00538450;

  _DAT_005dd958 = &LAB_00538340;

  _DAT_005dd95c = &LAB_005381b0;

  _DAT_005dd960 = &LAB_0051c330;

  _DAT_005dd964 = &LAB_0051c350;

  _DAT_005dd968 = FUN_0051ea20;

  *param_1 = 0x2775;

  *param_2 = 0x15;

  *param_3 = &DAT_005dd918;

  return;

}

/* ===== localization_check @ 0x0051C470 ===== */
int localization_check(void)



{

  int iVar1;

  void *local_14;

  undefined1 *puStack_10;

  undefined *puStack_c;

  undefined4 local_8;

  

  puStack_c = &DAT_00551838;

  puStack_10 = &LAB_00544c84;

  local_14 = ExceptionList;

  local_8 = 0;

  ExceptionList = &local_14;

  iVar1 = CheckSaveGameName__Fv();

  local_8 = 0xffffffff;

  if (iVar1 == 0x1234) {

    MessageBoxA((HWND)0x0,s_Invalid_Localization_0057d828,s_Fatal_Error_0057d840,0);

  }

  if (iVar1 == 0x2345) {

    MessageBoxA((HWND)0x0,s_Security_Violation___Contact_Int_0057d800,s_Fatal_Error_0057d840,0);

  }

  ExceptionList = local_14;

  return iVar1;

}

/* ===== FUN_0051c540 @ 0x0051C540 ===== */
bool FUN_0051c540(void)



{

  DAT_006331c4 = 1;

  if (DAT_005ddb54 == 0) {

    DAT_005ddb58 = 1;

    DAT_005dda80 = 1;

  }

  return DAT_005ddb54 != 0;

}

/* ===== FUN_0051c570 @ 0x0051C570 ===== */
undefined4 FUN_0051c570(void)



{

  if (((DAT_00633220 == 0) && ((DAT_00632e94 & 2) != 0)) && ((char)(DAT_00632e94 >> 8) < '\0')) {

    return 1;

  }

  return 0;

}

/* ===== FUN_0051c590 @ 0x0051C590 ===== */
void FUN_0051c590(int param_1)



{

  if (((DAT_00633220 == 0) && ((DAT_00632e94 & 2) != 0)) && ((char)(DAT_00632e94 >> 8) < '\0')) {

    if (param_1 == DAT_006331ac) {

      DAT_006331ac = (uint)(param_1 == 0);

      drawwrld_scene_link();

      return;

    }

  }

  else if (DAT_006331ac == 0) {

    DAT_006331ac = 1;

    drawwrld_scene_link();

    return;

  }

  return;

}

/* ===== dialog_level_is_base_2 @ 0x0051C5E0 ===== */
bool dialog_level_is_base_2(void)



{

  return DAT_006331ac == 0;

}

/* ===== FUN_0051c5f0 @ 0x0051C5F0 ===== */
undefined4 FUN_0051c5f0(void)



{

  if (((DAT_00633220 == 0) && ((DAT_00632e94 & 4) != 0)) && ((DAT_00632e94 & 0x4000) != 0)) {

    return 1;

  }

  return 0;

}

/* ===== FUN_0051c610 @ 0x0051C610 ===== */
void FUN_0051c610(int param_1)



{

  if (((DAT_00633220 == 0) && ((DAT_00632e94 & 4) != 0)) && ((DAT_00632e94 & 0x4000) != 0)) {

    DAT_0063319c = (uint)(param_1 == 0);

    return;

  }

  DAT_0063319c = 1;

  return;

}

/* ===== dialog_level_is_base_3 @ 0x0051C650 ===== */
bool dialog_level_is_base_3(void)



{

  return DAT_0063319c == 0;

}

/* ===== FUN_0051c660 @ 0x0051C660 ===== */
void FUN_0051c660(int param_1)



{

  int iVar1;

  

  if (((DAT_00633220 != 0) || ((DAT_00632e94 & 0x4000) == 0)) ||

     (iVar1 = 2, (DAT_00632e94 & 0x40000) == 0)) {

    iVar1 = 1;

  }

  if (iVar1 < param_1) {

    param_1 = iVar1;

  }

  DAT_006331a4 = 1;

  if (param_1 == 0) {

    DAT_006331a0 = 1;

    return;

  }

  DAT_006331a0 = 0;

  DAT_006331a4 = (uint)(param_1 == 1);

  return;

}

/* ===== AudioMusicStreamLinkStatusGet__Fv_2 @ 0x0051C6C0 ===== */
/* PS2 candidate: AudioMusicStreamLinkStatusGet__Fv (conf 0.568) */



char AudioMusicStreamLinkStatusGet__Fv_2(void)



{

  if (DAT_006331a0 != 0) {

    return '\0';

  }

  return (DAT_006331a4 == 0) + '\x01';

}

/* ===== FUN_0051c6e0 @ 0x0051C6E0 ===== */
undefined4 FUN_0051c6e0(void)



{

  if (((DAT_00633220 == 0) && ((DAT_00632e94 & 0x40) != 0)) && ((DAT_00632e94 & 0x4000) != 0)) {

    return 1;

  }

  return 0;

}

/* ===== FUN_0051c700 @ 0x0051C700 ===== */
void FUN_0051c700(int param_1)



{

  if (((DAT_00633220 == 0) && ((DAT_00632e94 & 0x40) != 0)) && ((DAT_00632e94 & 0x4000) != 0)) {

    DAT_006331b0 = (uint)(param_1 == 0);

    return;

  }

  DAT_006331b0 = 1;

  return;

}

/* ===== dialog_level_is_base_4 @ 0x0051C740 ===== */
bool dialog_level_is_base_4(void)



{

  return DAT_006331b0 == 0;

}

/* ===== FUN_0051c750 @ 0x0051C750 ===== */
undefined4 FUN_0051c750(void)



{

  if ((DAT_00633220 == 0) && (((byte)DAT_00632e94 & 2) != 0)) {

    return 1;

  }

  return 0;

}

/* ===== FUN_0051c770 @ 0x0051C770 ===== */
void FUN_0051c770(int param_1)



{

  if ((DAT_00633220 == 0) && (((byte)DAT_00632e94 & 2) != 0)) {

    DAT_00633190 = (uint)(param_1 == 0);

    return;

  }

  DAT_00633190 = 1;

  return;

}

/* ===== dialog_level_is_base_5 @ 0x0051C7A0 ===== */
bool dialog_level_is_base_5(void)



{

  return DAT_00633190 == 0;

}

/* ===== FUN_0051c7b0 @ 0x0051C7B0 ===== */
void FUN_0051c7b0(int param_1)



{

  DAT_00633228 = (uint)(param_1 == 0);

  return;

}

/* ===== dialog_level_is_base_6 @ 0x0051C7D0 ===== */
bool dialog_level_is_base_6(void)



{

  return DAT_00633228 == 0;

}

/* ===== FUN_0051c7e0 @ 0x0051C7E0 ===== */
undefined4 FUN_0051c7e0(void)



{

  undefined4 uVar1;

  

  if (((DAT_00633220 != 0) || ((DAT_00632e94 & 0x4000) == 0)) ||

     (uVar1 = 2, (DAT_00632e94 & 0x40000) == 0)) {

    uVar1 = 1;

  }

  return uVar1;

}

/* ===== FUN_0051c810 @ 0x0051C810 ===== */
void FUN_0051c810(int param_1)



{

  int iVar1;

  

  if (((DAT_00633220 != 0) || ((DAT_00632e94 & 0x4000) == 0)) ||

     (iVar1 = 2, (DAT_00632e94 & 0x40000) == 0)) {

    iVar1 = 1;

  }

  if (iVar1 < param_1) {

    param_1 = iVar1;

  }

  DAT_006331c0 = 1;

  if (param_1 == 0) {

    DAT_0063311c = 1;

    return;

  }

  DAT_0063311c = 0;

  DAT_006331c0 = (uint)(param_1 == 1);

  return;

}

/* ===== AudioMusicStreamLinkStatusGet__Fv @ 0x0051C870 ===== */
/* PS2 candidate: AudioMusicStreamLinkStatusGet__Fv_2 (conf 0.568) */



char AudioMusicStreamLinkStatusGet__Fv(void)



{

  if (DAT_0063311c != 0) {

    return '\0';

  }

  return (DAT_006331c0 == 0) + '\x01';

}

/* ===== AudioDataStreamStatus__Fv_6 @ 0x0051C890 ===== */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */



undefined4 AudioDataStreamStatus__Fv_6(void)



{

  return 1;

}

/* ===== FUN_0051c8a0 @ 0x0051C8A0 ===== */
void FUN_0051c8a0(int param_1)



{

  DAT_006331b8 = (uint)(param_1 == 0);

  return;

}

/* ===== dialog_level_is_base_7 @ 0x0051C8C0 ===== */
bool dialog_level_is_base_7(void)



{

  return DAT_006331b8 == 0;

}

/* ===== music_stream_play @ 0x0051C8D0 ===== */
void music_stream_play(void)



{

  int unaff_ESI;

  int unaff_EDI;

  int unaff_retaddr;

  

  DAT_00632e94 = (**(code **)(DAT_00656420 + 0xc4))(DAT_00656420,7);

  if ((DAT_00633220 == 0) && ((DAT_00632e94 & 2) != 0)) {

    DAT_00633190 = 0;

LAB_0051c90f:

    if (((DAT_00632e94 & 2) == 0) || (-1 < (char)(DAT_00632e94 >> 8))) goto LAB_0051c927;

    if (DAT_006331ac == 1) {

      DAT_006331ac = 0;

      goto LAB_0051c935;

    }

LAB_0051c949:

    if (((DAT_00632e94 & 4) == 0) || ((DAT_00632e94 & 0x4000) == 0)) goto LAB_0051c95a;

    DAT_0063319c = 0;

LAB_0051c964:

    if (((DAT_00632e94 & 0x40) != 0) && (DAT_006331b0 = 0, (DAT_00632e94 & 0x4000) != 0))

    goto LAB_0051c979;

  }

  else {

    DAT_00633190 = 1;

    if (DAT_00633220 == 0) goto LAB_0051c90f;

LAB_0051c927:

    if (DAT_006331ac == 0) {

      DAT_006331ac = 1;

LAB_0051c935:

      drawwrld_scene_link();

    }

    if (DAT_00633220 == 0) goto LAB_0051c949;

LAB_0051c95a:

    DAT_0063319c = 1;

    if (DAT_00633220 == 0) goto LAB_0051c964;

  }

  DAT_006331b0 = 1;

LAB_0051c979:

  DAT_00633228 = 0;

  if (((DAT_00633220 == 0) && ((DAT_00632e94 & 0x4000) != 0)) && ((DAT_00632e94 & 0x40000) != 0)) {

    DAT_006331c0 = 0;

  }

  else {

    DAT_006331c0 = 1;

  }

  DAT_0063311c = 0;

  DAT_006331b8 = 0;

  if (((DAT_00633220 == 0) && ((DAT_00632e94 & 0x4000) != 0)) && ((DAT_00632e94 & 0x40000) != 0)) {

    DAT_006331a4 = 0;

  }

  else {

    DAT_006331a4 = 1;

  }

  DAT_006331a0 = 0;

  DAT_00633150 = 2;

  AudioMusicStreamPlay__Fiiii(0,unaff_EDI,unaff_ESI,unaff_retaddr);

  return;

}

/* ===== FUN_0051C9F0 @ 0x0051C9F0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_0051C9F0(void)



{

  int cx;

  int cy;

  undefined4 uVar1;

  

  DAT_005ddb80 = 1;

  DAT_005ddb40 = (**(code **)(DAT_00656420 + 0xc4))(DAT_00656420,0);

  DAT_00632e98 = (uint)(DAT_005ddb40 == 0);

  _DAT_005ddb44 = (**(code **)(DAT_00656420 + 0xc4))(DAT_00656420,1);

  DAT_00632e84 = _DAT_005ddb44;

  _DAT_005ddb48 = (**(code **)(DAT_00656420 + 0xc4))(DAT_00656420,2);

  DAT_00632e88 = _DAT_005ddb48;

  _DAT_00632e8c = (**(code **)(DAT_00656420 + 0xc4))(DAT_00656420,5);

  _DAT_00632e90 = (**(code **)(DAT_00656420 + 0xc4))(DAT_00656420,6);

  DAT_00632e94 = (**(code **)(DAT_00656420 + 0xc4))(DAT_00656420,7);

  DAT_006331d4 = DAT_00632e98;

  DAT_00633244 = (**(code **)(DAT_00656420 + 0xc4))(DAT_00656420,8);

  DAT_00632e9c = DAT_00632e94 >> 9 & 1;

  DAT_0057c0c0 = 0x3f800000;

  if (DAT_00633224 != 0) {

    DAT_0057c0c0 = 0x40a00000;

  }

  DAT_00632ea0 = DAT_00632e94 & 0x400;

  if ((DAT_00632e94 & 0x10) == 0) {

    if ((DAT_00632e94 & 0x20) != 0) {

      _DAT_006330b8 = 0x40000000;

      DAT_006330bc = 0x4000;

      _DAT_006330c0 = 0x3000;

      goto LAB_0051cb4e;

    }

  }

  else if ((DAT_00632e94 & 0x20) != 0) {

    _DAT_006330b8 = 0x3f800000;

    DAT_006330bc = 0x5000;

    _DAT_006330c0 = 0x4000;

    goto LAB_0051cb4e;

  }

  _DAT_006330b8 = 0x40800000;

  DAT_006330bc = 0x3000;

  _DAT_006330c0 = 0x3000;

LAB_0051cb4e:

  if (DAT_005ddb40 != 0) {

    cx = GetSystemMetrics(0);

    cy = GetSystemMetrics(1);

    SetWindowPos(DAT_005dda78,(HWND)0x0,0,0,cx,cy,0x100);

  }

  (**(code **)(DAT_00656420 + 0x44))(DAT_00656420,DAT_00632e9c != 0);

  XFSetViewportRegion(0,0,(float)_DAT_005ddb44,(float)_DAT_005ddb48);

  object_destroy_all__7PS2Game(1);

  uVar1 = AudioDataStreamStatus__Fv_3();

  FUN_00500490(uVar1);

  dlog_frame_reset();

  return;

}

/* ===== CheckSaveGameName__Fv @ 0x0051CC20 ===== */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */



undefined4 CheckSaveGameName__Fv(void)



{

  char *pcVar1;

  ATOM AVar2;

  int iVar3;

  HANDLE hHandle;

  DWORD DVar4;

  BOOL BVar5;

  HACCEL hAccTable;

  WPARAM WVar6;

  int iVar7;

  undefined4 *puVar8;

  _STARTUPINFOA *p_Var9;

  HINSTANCE in_stack_00000004;

  int in_stack_00000010;

  undefined4 uVar10;

  tagMSG local_280;

  _PROCESS_INFORMATION local_264;

  _STARTUPINFOA local_254;

  CHAR local_210 [264];

  CHAR local_108 [264];

  

  iVar3 = 0;

  puVar8 = &DAT_005dda78;

  for (iVar7 = 0x41; iVar7 != 0; iVar7 = iVar7 + -1) {

    *puVar8 = 0;

    puVar8 = puVar8 + 1;

  }

  do {

    pcVar1 = &DAT_0057d970 + iVar3;

    (&DAT_005dda88)[iVar3] = *pcVar1;

    iVar3 = iVar3 + 1;

  } while (*pcVar1 != '\0');

  iVar3 = 0;

  DAT_005dda90 = 0;

  do {

    pcVar1 = &DAT_0057d96c + iVar3;

    (&DAT_005ddae0)[iVar3] = *pcVar1;

    iVar3 = iVar3 + 1;

  } while (*pcVar1 != '\0');

  DAT_005ddae8 = 0;

  puVar8 = &DAT_00632d20;

  for (iVar3 = 0xf1; iVar3 != 0; iVar3 = iVar3 + -1) {

    *puVar8 = 0;

    puVar8 = puVar8 + 1;

  }

  gfx_d3d_0051d0d0();

  hHandle = CreateMutexA((LPSECURITY_ATTRIBUTES)0x0,0,s_Giants_CK_0057d960);

  if (hHandle == (HANDLE)0x0) {

    MessageBoxA((HWND)0x0,s_Error_Creating_Giants_CK_Mutex___0057d914,s_Giants_Fatal_Error_0057d94c,

                0);

    return 0;

  }

  DVar4 = WaitForSingleObject(hHandle,0);

  if (DVar4 == 0x102) {

    MessageBoxA((HWND)0x0,s_Giants_already_running_or_instal_0057d8e4,s_Giants_Fatal_Error_0057d94c,

                0);

    CloseHandle(hHandle);

    return 0;

  }

  GetCurrentDirectoryA(0x105,local_108);

  lstrcpyA(local_210,local_108);

  lstrcatA(local_210,s__ereg_0057d88c);

  SetCurrentDirectoryA(local_210);

  p_Var9 = &local_254;

  for (iVar3 = 0x11; iVar3 != 0; iVar3 = iVar3 + -1) {

    p_Var9->cb = 0;

    p_Var9 = (_STARTUPINFOA *)&p_Var9->lpReserved;

  }

  local_254.cb = 0x44;

  BVar5 = CreateProcessA((LPCSTR)0x0,s_reg32_exe_FALSE_0057d87c,(LPSECURITY_ATTRIBUTES)0x0,

                         (LPSECURITY_ATTRIBUTES)0x0,0,0x20,(LPVOID)0x0,(LPCSTR)0x0,&local_254,

                         &local_264);

  if (BVar5 != 0) {

    WaitForSingleObject(local_264.hProcess,0xffffffff);

    CloseHandle(local_264.hThread);

    CloseHandle(local_264.hProcess);

  }

  SetCurrentDirectoryA(local_108);

  if (DAT_005ddb88 == 0) {

    uVar10 = 0;

  }

  else {

    uVar10 = 0xffffffff;

  }

  FUN_00539de0(uVar10);

  AudioSetSpeakerConfig__F14SPEAKER_SYSTEM_6(&LAB_0051cbe0);

  AudioSetSpeakerConfig__F14SPEAKER_SYSTEM_7(&LAB_0051cc00);

  math_sqrt_table_init();

  if ((DAT_00633214 == 0) && (DAT_00633220 == 0)) {

    if (DAT_00633218 == 0) {

      if (DAT_0063321c == 0) {

        uVar10 = 0xffffffff;

      }

      else {

        uVar10 = 2;

      }

    }

    else {

      uVar10 = 1;

    }

  }

  else {

    uVar10 = 0;

  }

  crt_math_dispatch_init(uVar10);

  DAT_005dda7c = in_stack_00000004;

  local_254.cb = 0;

  local_254.lpReserved = &LAB_0051e3b0;

  local_254.lpDesktop = (LPSTR)0x0;

  local_254.lpTitle = (LPSTR)0x0;

  local_254.dwY = 0;

  local_254.dwXSize = (DWORD)LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);

  local_254.dwYSize = (DWORD)GetStockObject(4);

  local_254.dwXCountChars = (DWORD)s_AppMenu_0057d8dc;

  local_254.dwYCountChars = (DWORD)s_GiantsWinClass_0057d8cc;

  AVar2 = RegisterClassA((WNDCLASSA *)&local_254);

  if (AVar2 != 0) {

    DAT_005dda78 = CreateWindowExA(0x40000,s_GiantsWinClass_0057d8cc,s_Giants_0057d8c4,0x6cf0000,

                                   -0x80000000,-0x80000000,-0x80000000,-0x80000000,(HWND)0x0,

                                   (HMENU)0x0,in_stack_00000004,(LPVOID)0x0);

    ShowWindow(DAT_005dda78,in_stack_00000010);

    if (DAT_005dda78 == (HWND)0x0) {

      error_screen_show(s_CreateWindowEx_failed_0057d8ac);

      return 0;

    }

    UpdateWindow(DAT_005dda78);

    if (DAT_005ddb3c == 0) {

      DAT_005ddb54 = AudioDataStreamStatus__Fv_6();

      iVar3 = startup_options_init(in_stack_00000004);

      if (iVar3 != 0) {

        hAccTable = LoadAcceleratorsA(in_stack_00000004,s_AppAccel_0057d8a0);

        timeBeginPeriod(1);

        DAT_005ddb4c = 1;

        PeekMessageA(&local_280,(HWND)0x0,0,0,0);

        while (local_280.message != 0x12) {

          DAT_0057d7fc = (*(code *)DAT_00656420[0x20])(DAT_00656420,DAT_0057d7fc);

          if (DAT_0057d7fc == 3) {

            game_options_verify();

            FUN_0051C9F0();

          }

          if (DAT_005ddb50 == 0) {

            iVar3 = GetMessageA(&local_280,(HWND)0x0,0,0);

          }

          else {

            iVar3 = PeekMessageA(&local_280,(HWND)0x0,0,0,1);

          }

          if (iVar3 == 0) {

            if (((DAT_0057d7fc == 1) && (DAT_005ddb50 != 0)) && (DAT_005ddb4c != 0)) {

              dinput_key_poll();

              time_frame_update();

              input_keystate_update();

              hud_audio_dlog_screen();

              if (DAT_005dda80 != 0) {

                if (((DAT_0063315c == 0) && (DAT_00633160 == 0)) && (DAT_0063317c == 0)) {

                  loglauncher_process_2(s_outros_bin_0057d894);

                }

                SendMessageA(DAT_005dda78,0x10,0,0);

              }

            }

          }

          else {

            iVar3 = TranslateAcceleratorA(DAT_005dda78,hAccTable,&local_280);

            if (iVar3 == 0) {

              TranslateMessage(&local_280);

              DispatchMessageA(&local_280);

            }

          }

        }

        anim_dump_user();

        shutdown_blood_cleanup();

        if (DAT_005ddb80 != 0) {

          DAT_005ddb80 = 0;

          main_gfxhelp_00452000();

          (*(code *)*DAT_00656420)(DAT_00656420);

        }

        mem_verify();

        ANM_DumpCluster();

        timeEndPeriod(1);

        CloseHandle(hHandle);

        WVar6 = 0x2345;

        if (DAT_005ddb58 == 0) {

          WVar6 = local_280.wParam;

        }

        return WVar6;

      }

      return 0;

    }

  }

  return 0;

}

/* ===== gfx_d3d_0051d0d0 @ 0x0051D0D0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* PS2 candidate: cd_monitor_set_valid (conf 0.722) */



void gfx_d3d_0051d0d0(char *param_1)



{

  char *pcVar1;

  char cVar2;

  int iVar3;

  int iVar4;

  undefined4 uVar5;

  int iVar6;

  char *pcVar7;

  float10 fVar8;

  undefined1 auStack_14 [20];

  

  DAT_005dda70 = 6;

  options_defaults();

  iVar6 = 0;

  _DAT_005ddb84 = 0;

  DAT_005ddb88 = 0;

  do {

    iVar3 = FUN_005451d1((int)*param_1);

    pcVar7 = param_1;

    while (iVar3 != 0) {

      pcVar1 = pcVar7 + 1;

      pcVar7 = pcVar7 + 1;

      iVar3 = FUN_005451d1((int)*pcVar1);

    }

    if (*pcVar7 == '\0') {

      return;

    }

    param_1 = pcVar7;

    if (*pcVar7 == '\"') {

      pcVar1 = pcVar7 + 1;

      pcVar7 = pcVar7 + 1;

      cVar2 = *pcVar1;

      param_1 = pcVar7;

      while ((cVar2 != '\0' && (cVar2 != '\"'))) {

        pcVar1 = param_1 + 1;

        param_1 = param_1 + 1;

        cVar2 = *pcVar1;

      }

    }

    else {

      do {

        iVar3 = FUN_005451d1((int)*param_1);

        if (iVar3 != 0) break;

        pcVar1 = param_1 + 1;

        param_1 = param_1 + 1;

      } while (*pcVar1 != '\0');

    }

    if (iVar6 == 1) {

      strncpynull(&DAT_005dda88,pcVar7,(int)param_1 - (int)pcVar7,8);

      iVar6 = 0;

    }

    else if (iVar6 == 2) {

      strncpynull(&DAT_005dda90,pcVar7,(int)param_1 - (int)pcVar7,0x50);

      iVar6 = 0;

    }

    else if (iVar6 == 3) {

      strncpynull(&DAT_005ddae0,pcVar7,(int)param_1 - (int)pcVar7,8);

      iVar6 = 0;

    }

    else if (iVar6 == 4) {

      strncpynull(&DAT_005ddae8,pcVar7,(int)param_1 - (int)pcVar7,0x50);

      iVar6 = 0;

    }

    else if (iVar6 == 7) {

      strncpynull(&DAT_0063304c,pcVar7,(int)param_1 - (int)pcVar7,0x20);

      iVar6 = 0;

    }

    else if (iVar6 == 8) {

      strncpynull(&DAT_00632f48,pcVar7,(int)param_1 - (int)pcVar7,0x20);

      iVar6 = 0;

    }

    else if (iVar6 == 9) {

      strncpynull(&DAT_00632f68,pcVar7,(int)param_1 - (int)pcVar7,0x40);

      if (DAT_00632f68 != '\0') {

        DAT_00633160 = 1;

      }

      iVar6 = 0;

    }

    else if (iVar6 == 10) {

      strncpynull(auStack_14,pcVar7,(int)param_1 - (int)pcVar7,0x14);

      DAT_00632fa8 = ANM_BinderDestroy_3(auStack_14);

      if ((DAT_00632fa8 < 1) && (0xffff < DAT_00632fa8)) {

        DAT_00633164 = 0;

        DAT_00632fa8 = 0;

        iVar6 = 0;

      }

      else {

        DAT_00633164 = 1;

        iVar6 = 0;

      }

    }

    else if (iVar6 == 0xb) {

      strncpynull(&DAT_00633070,pcVar7,(int)param_1 - (int)pcVar7,0x20);

      strncpynull(&DAT_00632ee8,pcVar7,(int)param_1 - (int)pcVar7,0x20);

      iVar6 = 0;

    }

    else if (iVar6 == 0xc) {

      DAT_00632f0c = ANM_BinderDestroy_3(pcVar7);

      iVar6 = 0;

    }

    else if (iVar6 == 0xd) {

      DAT_00632f10 = ANM_BinderDestroy_3(pcVar7);

      iVar6 = 0;

    }

    else if (iVar6 == 5) {

      DAT_00632f18 = ANM_BinderDestroy_3(pcVar7);

      if ((5 < DAT_00632f18) || (DAT_00632f18 < 0)) {

        DAT_00632f18 = 0;

      }

      iVar6 = 0;

    }

    else if (iVar6 == 6) {

      DAT_00632f34 = ANM_BinderDestroy_3(pcVar7);

      if ((0x14 < DAT_00632f34) || (DAT_00632f34 < 2)) {

        DAT_00632f34 = 10;

      }

      iVar6 = 0;

    }

    else if (iVar6 == 0xe) {

      strncpynull(&DAT_00633030,pcVar7,(int)param_1 - (int)pcVar7,8);

      iVar6 = 0;

    }

    else if (iVar6 == 0xf) {

      _DAT_00633254 = ANM_BinderDestroy_3(pcVar7);

      iVar6 = 0;

      if ((_DAT_00633254 < 0) || (2 < _DAT_00633254)) {

        _DAT_00633254 = 0;

      }

    }

    else if (iVar6 == 0x10) {

      FUN_0051ad80(pcVar7,(int)param_1 - (int)pcVar7);

      iVar6 = 0;

    }

    else if (iVar6 == 0x15) {

      DAT_00633188 = ANM_BinderDestroy_3(pcVar7);

      iVar6 = 0;

    }

    else if (iVar6 == 0x11) {

      fVar8 = (float10)crt_scanf_float2(pcVar7);

      FUN_004257c0((float)fVar8);

      iVar6 = 0;

      DAT_0058c5d0 = 1;

    }

    else if (iVar6 == 0x12) {

      strncpynull(&DAT_00633090,pcVar7,(int)param_1 - (int)pcVar7,0x20);

      iVar6 = 0;

      iVar3 = main_dedicated_00426460();

      if (iVar3 != 0) {

        DAT_00633238 = 1;

        game_options_verify();

        DAT_005dda70 = DAT_005dda70 & 0xfffffff8;

        DAT_006331fc = 1;

        DAT_00633204 = 1;

        DAT_00633208 = 1;

        DAT_00633200 = 1;

        DAT_006331d4 = 1;

        DAT_0063315c = 1;

      }

    }

    else if (iVar6 == 0x13) {

      DAT_0059d994 = atox__FPc(pcVar7);

      iVar6 = 0x14;

    }

    else if (iVar6 == 0x14) {

      DAT_0059d990 = atox__FPc(pcVar7);

      iVar6 = 0;

    }

    else {

      iVar3 = (int)param_1 - (int)pcVar7;

      if (iVar3 == 4) {

        iVar4 = FUN_0053a830(pcVar7,&DAT_0057db6c);

        if (iVar4 == 0) {

          iVar4 = FUN_0053a830(pcVar7,&DAT_0057db64);

          if (iVar4 == 0) goto LAB_0051d50a;

          iVar6 = 1;

        }

        else {

          DAT_0059d998 = 1;

          iVar6 = 0x13;

        }

      }

      else {

LAB_0051d50a:

        if ((iVar3 == 8) && (iVar4 = FUN_0053a830(pcVar7,s__GFXPath_0057db58), iVar4 != 0)) {

          iVar6 = 2;

        }

        else if ((iVar3 == 4) && (iVar4 = FUN_0053a830(pcVar7,&DAT_0057db50), iVar4 != 0)) {

          iVar6 = 3;

        }

        else if ((iVar3 == 8) && (iVar4 = FUN_0053a830(pcVar7,s__SNDPath_0057db44), iVar4 != 0)) {

          iVar6 = 4;

        }

        else if (iVar3 == 7) {

          iVar4 = FUN_0053a830(pcVar7,s__debwin_0057db3c);

          if (iVar4 == 0) {

            iVar4 = FUN_0053a830(pcVar7,s__deberr_0057db34);

            if (iVar4 == 0) goto LAB_0051d5b9;

            DAT_005ddb88 = 1;

          }

          else {

            _DAT_005ddb84 = 1;

          }

        }

        else {

LAB_0051d5b9:

          if ((iVar3 == 9) && (iVar4 = FUN_0053a830(pcVar7,s__noswitch_0057db28), iVar4 != 0)) {

            _DAT_005ddb8c = 1;

          }

          else if ((iVar3 == 6) && (iVar4 = FUN_0053a830(pcVar7,s__lobby_0057db20), iVar4 != 0)) {

            DAT_0063317c = 1;

          }

          else if ((iVar3 == 5) && (iVar4 = FUN_0053a830(pcVar7,s__name_0057db18), iVar4 != 0)) {

            iVar6 = 7;

            DAT_00633154 = 1;

          }

          else if ((iVar3 == 9) && (iVar4 = FUN_0053a830(pcVar7,s__gametype_0057db0c), iVar4 != 0))

          {

            iVar6 = 5;

            DAT_00633174 = 1;

          }

          else if ((iVar3 == 0xb) &&

                  (iVar4 = FUN_0053a830(pcVar7,s__maxplayers_0057db00), iVar4 != 0)) {

            iVar6 = 6;

            DAT_00633170 = 1;

          }

          else if (iVar3 == 5) {

            iVar4 = FUN_0053a830(pcVar7,s__host_0057daf8);

            if (iVar4 == 0) {

              iVar4 = FUN_0053a830(pcVar7,s__join_0057daf0);

              if (iVar4 == 0) {

                iVar4 = FUN_0053a830(pcVar7,s__port_0057dae8);

                if (iVar4 == 0) goto LAB_0051d6f3;

                iVar6 = 10;

              }

              else {

                iVar6 = 9;

              }

            }

            else {

              iVar6 = 8;

              DAT_0063315c = 1;

            }

          }

          else {

LAB_0051d6f3:

            if ((iVar3 == 6) && (iVar4 = FUN_0053a830(pcVar7,s__world_0057dae0), iVar4 != 0)) {

              iVar6 = 0xb;

              DAT_00633158 = 1;

            }

            else if ((iVar3 == 10) &&

                    (iVar4 = FUN_0053a830(pcVar7,s__baselevel_0057dad4), iVar4 != 0)) {

              iVar6 = 0xc;

              DAT_00633168 = 1;

            }

            else if (iVar3 == 9) {

              iVar4 = FUN_0053a830(pcVar7,s__gameteam_0057dac8);

              if (iVar4 == 0) {

                iVar4 = FUN_0053a830(pcVar7,s__location_0057dabc);

                if (iVar4 == 0) goto LAB_0051d79f;

                iVar6 = 0xe;

                DAT_00633180 = 1;

              }

              else {

                iVar6 = 0xd;

                DAT_0063316c = 1;

              }

            }

            else {

LAB_0051d79f:

              if ((iVar3 == 0xe) &&

                 (iVar4 = FUN_0053a830(pcVar7,s__highbandwidth_0057daac), iVar4 != 0)) {

                DAT_00633210 = 1;

              }

              else if (iVar3 == 10) {

                iVar4 = FUN_0053a830(pcVar7,s__nogamespy_0057daa0);

                if (iVar4 == 0) {

                  iVar4 = FUN_0053a830(pcVar7,s__nodxerror_0057da94);

                  if (iVar4 == 0) goto LAB_0051d811;

                  _DAT_0063324c = 1;

                }

                else {

                  DAT_00633184 = 1;

                }

              }

              else {

LAB_0051d811:

                if ((iVar3 == 8) && (iVar4 = FUN_0053a830(pcVar7,s__nosnd3d_0057da88), iVar4 != 0))

                {

                  DAT_005dda70 = DAT_005dda70 & 0xfffffffe;

                }

                else if (iVar3 == 6) {

                  iVar4 = FUN_0053a830(pcVar7,s__snd3d_0057da80);

                  if (iVar4 == 0) {

                    iVar4 = FUN_0053a830(pcVar7,s__noeax_0057da78);

                    if (iVar4 == 0) goto LAB_0051d87a;

                    DAT_005dda70 = DAT_005dda70 & 0xfffffffd;

                  }

                  else {

                    DAT_005dda70 = DAT_005dda70 | 1;

                  }

                }

                else {

LAB_0051d87a:

                  if ((iVar3 == 9) &&

                     (iVar4 = FUN_0053a830(pcVar7,s__noeaxman_0057da6c), iVar4 != 0)) {

                    DAT_005dda70 = DAT_005dda70 & 0xfffffffb;

                  }

                  else if ((iVar3 == 8) &&

                          (iVar4 = FUN_0053a830(pcVar7,s__noaudio_0057da60), iVar4 != 0)) {

                    DAT_006331fc = 1;

                  }

                  else if ((iVar3 == 9) &&

                          (iVar4 = FUN_0053a830(pcVar7,s__nostream_0057da54), iVar4 != 0)) {

                    DAT_00633204 = 1;

                  }

                  else if (iVar3 == 7) {

                    iVar4 = FUN_0053a830(pcVar7,s__noplay_0057da4c);

                    if (iVar4 == 0) {

                      iVar4 = FUN_0053a830(pcVar7,s__noload_0057da44);

                      if (iVar4 == 0) {

                        iVar4 = FUN_0053a830(pcVar7,s__voodoo_0057da3c);

                        if (iVar4 == 0) goto LAB_0051d956;

                        iVar6 = 0x15;

                      }

                      else {

                        DAT_00633208 = 1;

                      }

                    }

                    else {

                      DAT_00633200 = 1;

                    }

                  }

                  else {

LAB_0051d956:

                    if ((iVar3 == 10) &&

                       (iVar4 = FUN_0053a830(pcVar7,s__dedicated_0057da30), iVar4 != 0)) {

                      iVar6 = 0x12;

                    }

                    else if ((iVar3 == 7) &&

                            (iVar4 = FUN_0053a830(pcVar7,s__nophff_0057da28), iVar4 != 0)) {

                      DAT_00633250 = 1;

                    }

                    else if ((iVar3 == 0xe) &&

                            (iVar4 = FUN_0053a830(pcVar7,s__autodesignate_0057da18), iVar4 != 0)) {

                      DAT_0063325c = 1;

                    }

                    else if ((iVar3 == 8) &&

                            (iVar4 = FUN_0053a830(pcVar7,s__novimps_0057da0c), iVar4 != 0)) {

                      _DAT_0063323c = 1;

                    }

                    else if ((iVar3 == 7) &&

                            (iVar4 = FUN_0053a830(pcVar7,s__bbwait_0057da04), iVar4 != 0)) {

                      DAT_00633258 = 1;

                    }

                    else if ((iVar3 == 9) &&

                            (iVar4 = FUN_0053a830(pcVar7,s__pmarkers_0057d9f8), iVar4 != 0)) {

                      iVar6 = 0xf;

                    }

                    else if ((iVar3 == 10) &&

                            (iVar4 = FUN_0053a830(pcVar7,s__gamegauge_0057d9ec), iVar4 != 0)) {

                      DAT_00633248 = 1;

                    }

                    else if ((iVar3 == 8) &&

                            (iVar4 = FUN_0053a830(pcVar7,s__logchat_0057d9e0), iVar4 != 0)) {

                      DAT_00633240 = 1;

                      chat_log_close();

                    }

                    else if (iVar3 == 9) {

                      iVar4 = FUN_0053a830(pcVar7,s__amd3dnow_0057d9d4);

                      if (iVar4 == 0) {

                        iVar4 = FUN_0053a830(pcVar7,s__intelsse_0057d9c8);

                        if (iVar4 == 0) {

                          iVar4 = FUN_0053a830(pcVar7,s__nocpuext_0057d9bc);

                          if (iVar4 == 0) goto LAB_0051daf3;

                          DAT_00633214 = 1;

                        }

                        else {

                          DAT_0063321c = 1;

                        }

                      }

                      else {

                        DAT_00633218 = 1;

                      }

                    }

                    else {

LAB_0051daf3:

                      if ((iVar3 == 5) &&

                         (iVar4 = FUN_0053a830(pcVar7,s__font_0057d9b4), iVar4 != 0)) {

                        iVar6 = 0x10;

                      }

                      else if ((iVar3 == 7) &&

                              (iVar4 = FUN_0053a830(pcVar7,s__mspeed_0057d9ac), iVar4 != 0)) {

                        iVar6 = 0x11;

                      }

                      else if ((iVar3 == 0x10) &&

                              (iVar4 = FUN_0053a830(pcVar7,s__noforcefeedback_0057d998), iVar4 != 0)

                              ) {

                        _DAT_00633360 = 1;

                      }

                      else if ((iVar3 == 9) &&

                              (iVar4 = FUN_0053a830(pcVar7,s__safemode_0057d98c), iVar4 != 0)) {

                        DAT_005dda70 = DAT_005dda70 & 0xfffffff8;

                        DAT_00633220 = 1;

                        DAT_006331fc = 1;

                        DAT_00633204 = 1;

                        DAT_00633200 = 1;

                        DAT_00633208 = 1;

                      }

                      else if ((iVar3 == 10) &&

                              (iVar3 = FUN_0053a830(pcVar7,s__5footclip_0057d980), iVar3 != 0)) {

                        DAT_00633224 = 1;

                      }

                      else {

                        iVar3 = FUN_0053a830(pcVar7,s__lang_0057d978);

                        if (iVar3 == 0) {

                          cVar2 = *param_1;

                          *param_1 = '\0';

                          cmdline_parse(pcVar7);

                          *param_1 = cVar2;

                        }

                        else {

                          uVar5 = FUN_00544fb5(pcVar7 + 5,0,0x10);

                          FUN_00538ff0(uVar5);

                        }

                      }

                    }

                  }

                }

              }

            }

          }

        }

      }

    }

    if (*param_1 == '\"') {

      param_1 = param_1 + 1;

    }

  } while( true );

}

/* ===== startup_options_init @ 0x0051DC20 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined4 startup_options_init(undefined4 param_1,undefined4 param_2)



{

  int iVar1;

  undefined4 uVar2;

  int iVar3;

  int iVar4;

  char *pcVar5;

  int *piVar6;

  char *pcVar7;

  int *piVar8;

  bool bVar9;

  bool bVar10;

  undefined4 *p1;

  undefined4 uStack_6c;

  undefined4 uStack_68;

  char local_64 [100];

  

  AudioSetSpeakerConfig__F14SPEAKER_SYSTEM_8(error_screen_show);

  iVar1 = intro_assets_check();

  if (iVar1 == 0) {

    DAT_005ddb3c = 1;

    return 0;

  }

  if (DAT_005ddb3c != 0) {

    return 0;

  }

  SetEnvironmentVariableA(s_FX_GLIDE_NO_SPLASH_0057dbb8,&DAT_00556244);

  if (DAT_005ddb3c != 0) {

    return 0;

  }

  if (DAT_00633220 != 0) {

    DAT_006331d8 = 0;

    DAT_006331e8 = 0;

    DAT_006331dc = 0;

    DAT_006331ec = 0;

    _DAT_006331e0 = 0;

    _DAT_006331f0 = 0;

    DAT_006331c8 = 0x280;

    DAT_006331cc = 0x1e0;

    DAT_006331d0 = 0x10;

    _DAT_006331e4 = 0;

    _DAT_006331f4 = 0;

  }

  do {

    uVar2 = param_2;

    bVar10 = false;

    iVar1 = renderer_load_return_site(&DAT_005dda90,&DAT_005dda88);

    if (iVar1 == 0) {

      iVar3 = 5;

      bVar9 = true;

      pcVar5 = &DAT_005dda88;

      pcVar7 = &DAT_0057d970;

      do {

        if (iVar3 == 0) break;

        iVar3 = iVar3 + -1;

        bVar9 = *pcVar5 == *pcVar7;

        pcVar5 = pcVar5 + 1;

        pcVar7 = pcVar7 + 1;

      } while (bVar9);

      if (!bVar9) {

        iVar3 = 5;

        bVar9 = true;

        pcVar5 = &DAT_005dda88;

        pcVar7 = &DAT_0057dbb0;

        do {

          if (iVar3 == 0) break;

          iVar3 = iVar3 + -1;

          bVar9 = *pcVar5 == *pcVar7;

          pcVar5 = pcVar5 + 1;

          pcVar7 = pcVar7 + 1;

        } while (bVar9);

        if (!bVar9) {

          uVar2 = FUN_00507b00(s_ErrFailedGFX_0057dba0);

          crt_sprintf(local_64,uVar2,&DAT_005dda88);

          if (DAT_005dda80 != 0) {

            return 0;

          }

          error_screen_show(local_64);

          DAT_005dda80 = 1;

          return 0;

        }

      }

LAB_0051de13:

      if (DAT_00656420 != 0) goto LAB_0051ded4;

    }

    else {

      DAT_00656420 = (*DAT_005dcfac)(uVar2,DAT_005dda78,DAT_006331c8,DAT_006331cc,DAT_006331d0,

                                     DAT_006331d4,1,&DAT_006331d8,&DAT_006331e8);

      if (DAT_00656420 != 0) goto LAB_0051ded4;

      DAT_00656420 = (*DAT_005dcfac)(uVar2,DAT_005dda78,0x280,0x1e0,DAT_006331d0,DAT_006331d4,1,

                                     &DAT_006331d8,&DAT_006331e8);

      if (DAT_00656420 != 0) {

        DAT_006331c8 = 0x280;

        DAT_006331cc = 0x1e0;

        goto LAB_0051de13;

      }

    }

    iVar3 = 5;

    bVar9 = true;

    pcVar5 = &DAT_005dda88;

    pcVar7 = &DAT_0057d970;

    do {

      if (iVar3 == 0) break;

      iVar3 = iVar3 + -1;

      bVar9 = *pcVar5 == *pcVar7;

      pcVar5 = pcVar5 + 1;

      pcVar7 = pcVar7 + 1;

    } while (bVar9);

    if (bVar9) {

LAB_0051de4b:

      if (iVar1 != 0) {

        gg_dll_name(&DAT_005dda90,&DAT_005dda88);

      }

      bVar10 = true;

    }

    else {

      iVar3 = 5;

      bVar9 = true;

      pcVar5 = &DAT_005dda88;

      pcVar7 = &DAT_0057dbb0;

      do {

        if (iVar3 == 0) break;

        iVar3 = iVar3 + -1;

        bVar9 = *pcVar5 == *pcVar7;

        pcVar5 = pcVar5 + 1;

        pcVar7 = pcVar7 + 1;

      } while (bVar9);

      if (bVar9) goto LAB_0051de4b;

    }

    iVar1 = DAT_00656420;

    iVar4 = 5;

    iVar3 = 0;

    bVar9 = true;

    pcVar5 = &DAT_005dda88;

    pcVar7 = &DAT_0057d970;

    do {

      if (iVar4 == 0) break;

      iVar4 = iVar4 + -1;

      bVar9 = *pcVar5 == *pcVar7;

      pcVar5 = pcVar5 + 1;

      pcVar7 = pcVar7 + 1;

    } while (bVar9);

    if (bVar9) {

      do {

        pcVar5 = &DAT_0057db98 + iVar3;

        (&DAT_005dda88)[iVar3] = *pcVar5;

        iVar3 = iVar3 + 1;

      } while (*pcVar5 != '\0');

    }

    iVar4 = 5;

    iVar3 = 0;

    bVar9 = true;

    pcVar5 = &DAT_005dda88;

    pcVar7 = &DAT_0057dbb0;

    do {

      if (iVar4 == 0) break;

      iVar4 = iVar4 + -1;

      bVar9 = *pcVar5 == *pcVar7;

      pcVar5 = pcVar5 + 1;

      pcVar7 = pcVar7 + 1;

    } while (bVar9);

    if (bVar9) {

      do {

        pcVar5 = &DAT_0057db90 + iVar3;

        (&DAT_005dda88)[iVar3] = *pcVar5;

        iVar3 = iVar3 + 1;

      } while (*pcVar5 != '\0');

    }

  } while (bVar10);

  if (iVar1 == 0) {

    _GLOBAL__D_Game();

    return 0;

  }

LAB_0051ded4:

  iVar1 = stream_0051a280(&DAT_005ddae8,&DAT_005ddae0);

  if (iVar1 == 0) {

    uVar2 = FUN_00507b00(s_ErrFailedSND_0057db80);

    crt_sprintf(local_64,uVar2,&DAT_005ddae0);

    if (DAT_005dda80 == 0) {

      error_screen_show(local_64);

      DAT_005dda80 = 1;

    }

    return 0;

  }

  if (DAT_005ddb3c != 0) {

    return 0;

  }

  (*DAT_005dd280)(0x2c,DAT_005dda70);

  (*DAT_005dd30c)();

  p1 = &DAT_005ddb5c;

  (**(code **)(DAT_00656420 + 0x6c))(DAT_00656420,&DAT_005ddb5c,&DAT_005ddb6c);

  iVar1 = 4;

  bVar10 = true;

  piVar6 = &DAT_005ddb5c;

  piVar8 = &DAT_006331d8;

  do {

    if (iVar1 == 0) break;

    iVar1 = iVar1 + -1;

    bVar10 = *piVar6 == *piVar8;

    piVar6 = piVar6 + 1;

    piVar8 = piVar8 + 1;

  } while (bVar10);

  if (bVar10) {

    iVar1 = 4;

    bVar10 = true;

    piVar6 = &DAT_005ddb6c;

    piVar8 = &DAT_006331e8;

    do {

      if (iVar1 == 0) break;

      iVar1 = iVar1 + -1;

      bVar10 = *piVar6 == *piVar8;

      piVar6 = piVar6 + 1;

      piVar8 = piVar8 + 1;

    } while (bVar10);

    if (bVar10) {

      filecopy_dirs();

      iVar1 = 0x51dfb7;

      reg_query_value_5(s_DefPlayer_0055a07c,local_64,0x40);

      if (local_64[0] != '\0') {

        DAT_00632e94 = (**(code **)(DAT_00656420 + 0xc4))();

        reg_open_key(local_64);

        game_options_verify();

        reg_close_key();

        goto LAB_0051e225;

      }

      iVar4 = 0x51dffe;

      iVar3 = DAT_00656420;

      DAT_00632e94 = (**(code **)(DAT_00656420 + 0xc4))(DAT_00656420,7);

      if ((DAT_00633220 == 0) && ((DAT_00632e94 & 2) != 0)) {

        DAT_00633190 = 0;

LAB_0051e032:

        if (((DAT_00632e94 & 2) == 0) || (-1 < (char)(DAT_00632e94 >> 8))) goto LAB_0051e04a;

        if (DAT_006331ac == 1) {

          DAT_006331ac = 0;

          goto LAB_0051e058;

        }

LAB_0051e06c:

        if (((DAT_00632e94 & 4) == 0) || ((DAT_00632e94 & 0x4000) == 0)) goto LAB_0051e07d;

        DAT_0063319c = 0;

LAB_0051e087:

        if (((DAT_00632e94 & 0x40) == 0) || (DAT_006331b0 = 0, (DAT_00632e94 & 0x4000) == 0))

        goto LAB_0051e096;

      }

      else {

        DAT_00633190 = 1;

        if (DAT_00633220 == 0) goto LAB_0051e032;

LAB_0051e04a:

        if (DAT_006331ac == 0) {

          DAT_006331ac = 1;

LAB_0051e058:

          drawwrld_scene_link();

        }

        if (DAT_00633220 == 0) goto LAB_0051e06c;

LAB_0051e07d:

        DAT_0063319c = 1;

        if (DAT_00633220 == 0) goto LAB_0051e087;

LAB_0051e096:

        DAT_006331b0 = 1;

      }

      DAT_00633228 = 0;

      if (((DAT_00633220 == 0) && ((DAT_00632e94 & 0x4000) != 0)) && ((DAT_00632e94 & 0x40000) != 0)

         ) {

        DAT_006331c0 = 0;

      }

      else {

        DAT_006331c0 = 1;

      }

      DAT_0063311c = 0;

      DAT_006331b8 = 0;

      if (((DAT_00633220 == 0) && ((DAT_00632e94 & 0x4000) != 0)) && ((DAT_00632e94 & 0x40000) != 0)

         ) {

        DAT_006331a4 = 0;

      }

      else {

        DAT_006331a4 = 1;

      }

      DAT_006331a0 = 0;

      DAT_00633150 = 2;

      AudioMusicStreamPlay__Fiiii(0,iVar1,iVar4,iVar3);

      reg_close_key();

      goto LAB_0051e225;

    }

  }

  iVar3 = 0x51e11b;

  iVar1 = DAT_00656420;

  DAT_00632e94 = (**(code **)(DAT_00656420 + 0xc4))(DAT_00656420,7);

  if ((DAT_00633220 == 0) && ((DAT_00632e94 & 2) != 0)) {

    DAT_00633190 = 0;

LAB_0051e14f:

    if (((DAT_00632e94 & 2) == 0) || (-1 < (char)(DAT_00632e94 >> 8))) goto LAB_0051e167;

    if (DAT_006331ac == 1) {

      DAT_006331ac = 0;

      goto LAB_0051e175;

    }

LAB_0051e189:

    if (((DAT_00632e94 & 4) == 0) || ((DAT_00632e94 & 0x4000) == 0)) goto LAB_0051e19a;

    DAT_0063319c = 0;

LAB_0051e1a4:

    if (((DAT_00632e94 & 0x40) == 0) || (DAT_006331b0 = 0, (DAT_00632e94 & 0x4000) == 0))

    goto LAB_0051e1b3;

  }

  else {

    DAT_00633190 = 1;

    if (DAT_00633220 == 0) goto LAB_0051e14f;

LAB_0051e167:

    if (DAT_006331ac == 0) {

      DAT_006331ac = 1;

LAB_0051e175:

      drawwrld_scene_link();

    }

    if (DAT_00633220 == 0) goto LAB_0051e189;

LAB_0051e19a:

    DAT_0063319c = 1;

    if (DAT_00633220 == 0) goto LAB_0051e1a4;

LAB_0051e1b3:

    DAT_006331b0 = 1;

  }

  DAT_00633228 = 0;

  if (((DAT_00633220 == 0) && ((DAT_00632e94 & 0x4000) != 0)) && ((DAT_00632e94 & 0x40000) != 0)) {

    DAT_006331c0 = 0;

  }

  else {

    DAT_006331c0 = 1;

  }

  DAT_0063311c = 0;

  DAT_006331b8 = 0;

  if (((DAT_00633220 == 0) && ((DAT_00632e94 & 0x4000) != 0)) && ((DAT_00632e94 & 0x40000) != 0)) {

    DAT_006331a4 = 0;

  }

  else {

    DAT_006331a4 = 1;

  }

  DAT_006331a0 = 0;

  DAT_00633150 = 2;

  AudioMusicStreamPlay__Fiiii(0,(int)p1,iVar3,iVar1);

  game_options_load();

LAB_0051e225:

  FUN_0051C9F0();

  (**(code **)(DAT_00656420 + 0x70))(DAT_00656420,&uStack_68);

  (**(code **)(DAT_00656420 + 0x78))(DAT_00656420,&uStack_6c,&DAT_005ddb5c,&DAT_005ddb6c);

  (**(code **)(DAT_00656420 + 0x7c))(DAT_00656420,uStack_6c);

  (**(code **)(DAT_00656420 + 0x74))(DAT_00656420,uStack_68);

  if (DAT_005ddb3c != 0) {

    return 0;

  }

  win95_text_0051adb0(0x18);

  main_gfxhelp_00451e10();

  ANM_DumpCluster();

  AudioSetSpeakerConfig__F14SPEAKER_SYSTEM_2(DAT_005ddb88);

  iVar1 = dinput_init(param_2);

  if (iVar1 == 0) {

    _GLOBAL__D_Game();

    return 0;

  }

  iVar1 = 0;

  do {

    iVar3 = ShowCursor(0);

    if (iVar3 < 0) break;

    iVar1 = iVar1 + 1;

  } while (iVar1 < 10);

  filecopy_dirs();

  reg_query_value_5(s_DefPlayer_0055a07c,local_64,0x40);

  if (local_64[0] != '\0') {

    reg_open_key(local_64);

    uStack_6c = 0x3f400000;

    param_2 = 0x3f400000;

    keymap_0051a100(s_MusicVolume_0055be24,&param_2);

    (*DAT_005dd32c)(param_2);

    uStack_6c = 0x3f400000;

    param_2 = 0x3f400000;

    keymap_0051a100(s_SoundVolume_0055be18,&param_2);

    (*DAT_005dd2cc)(param_2);

  }

  reg_close_key();

  menu_preview_scale_init();

  if (((DAT_0063315c == 0) && (DAT_00633160 == 0)) && (DAT_0063317c == 0)) {

    loglauncher_process_2(s_intros_bin_0057db74);

  }

  FUN_004907e0();

  return 1;

}

/* ===== Audio3DTestToneUpdate__Fv_4 @ 0x0051E670 ===== */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

/* PS2 candidate: __builtin_new (conf 0.529) */



void Audio3DTestToneUpdate__Fv_4(void)



{

  DAT_005dda80 = 1;

  return;

}

/* ===== error_screen_show @ 0x0051E680 ===== */
void error_screen_show(LPCSTR param_1)



{

  char cVar1;

  LPCSTR pCVar2;

  int iVar3;

  uint uVar4;

  size_t _Count;

  char *_Source;

  char *pcVar5;

  char acStack_3c [60];

  

  pCVar2 = param_1;

  FUN_00425eb0(param_1);

  if ((((DAT_00632f08 < 3) || (0xb < DAT_00632f08)) || (DAT_00632f08 == 6)) && (DAT_005ddb94 == 0))

  {

    if ((DAT_005ddb90 == 0) && (DAT_005ddb80 != 0)) {

      DAT_005ddb90 = 1;

      do {

        (**(code **)(DAT_00656420 + 0x98))(DAT_00656420,0);

        render_scene_begin();

        xfmat_mult_b();

        hud_quad_scaled_write(0xa0d0d0,0,0x3f7fbe77,0,0x3f7fbe77);

        hud_quad_scaled_write(0x102060,0x3eae147b,0x3f2ccccd,0x3d23d70a,0x3e0f5c29);

        hud_quad_scaled_write(0x1020d0,0x3ea8f5c3,0x3f2b851f,0x3d4ccccd,0x3e19999a);

        hud_quad_scaled_write(0x102060,0x3e947ae1,0x3f39999a,0x3f4a3d71,0x3f70a3d7);

        hud_quad_scaled_write(0x1020d0,0x3e8f5c29,0x3f3851ec,0x3f4ccccd,0x3f733333);

        hud_quad_scaled_write(0x102060,0x3e6147ae,0x3f4f5c29,0x3e8f5c29,0x3f2e147b);

        hud_quad_scaled_write(0x1020d0,0x3e4ccccd,0x3f4ccccd,0x3e99999a,0x3f333333);

        (**(code **)(DAT_00656438 + 0x2c))(DAT_00656438);

        cVar1 = *pCVar2;

        param_1 = (LPCSTR)0x3ecccccd;

        _Source = pCVar2;

        while (cVar1 != '\0') {

          uVar4 = 0xffffffff;

          pcVar5 = _Source;

          do {

            if (uVar4 == 0) break;

            uVar4 = uVar4 - 1;

            cVar1 = *pcVar5;

            pcVar5 = pcVar5 + 1;

          } while (cVar1 != '\0');

          _Count = ~uVar4 - 1;

          if (0x3b < (int)_Count) {

            _Count = 0x3b;

          }

          _strncpy(acStack_3c,_Source,_Count);

          acStack_3c[_Count] = '\0';

          textrender_draw_buffered(0xd0d0ff,0,0x3d000000,0x3f000000,param_1,acStack_3c);

          param_1 = (LPCSTR)((float)param_1 + 0.03125);

          pcVar5 = _Source + _Count;

          _Source = _Source + _Count;

          cVar1 = *pcVar5;

        }

        textrender_draw_buffered

                  (0xe0e0ff,0,0x3d000000,0x3f000000,0x3dc00000,s_Giants__Citizen_Kabuto_0057dc24);

        textrender_draw_buffered

                  (0xe0e0ff,0,0x3d000000,0x3f000000,0x3e000000,

                   s_Wintry_Cool_Game_Error_Screen_0057dc04);

        textrender_draw_buffered

                  (0xc0c0df,0,0x3d000000,0x3f000000,0x3f600000,s_Enter_to_Continue_0057dbf0);

        textrender_draw_buffered

                  (0xc0c0df,0,0x3d000000,0x3f000000,0x3f680000,s_Escape_to_Exit_Game_0057dbdc);

        ANM_DumpCluster();

        render_scene_end();

        (**(code **)(DAT_00656420 + 0xa8))(DAT_00656420);

        dinput_key_poll();

        input_keystate_update();

        hud_status_main();

        if (DAT_00632aa8 != '\0') goto LAB_0051e90f;

      } while (DAT_00632aa4._3_1_ == '\0');

      DAT_005dda80 = 1;

      DAT_005ddb94 = 1;

LAB_0051e90f:

      (**(code **)(DAT_00656420 + 0x98))(DAT_00656420,0);

      (**(code **)(DAT_00656420 + 0xa8))(DAT_00656420);

      DAT_005ddb90 = 0;

      return;

    }

    DAT_005ddb38 = DAT_005ddb38 + 1;

    DAT_005ddb4c = (uint)(DAT_005ddb38 == 0);

    if (DAT_005ddb80 != 0) {

      (**(code **)(DAT_00656420 + 0x84))(DAT_00656420,1);

    }

    if (DAT_005ddb38 == 0) {

      time_frame_update();

    }

    SetWindowPos(DAT_005dda78,(HWND)0xfffffffe,0,0,0,0,3);

    iVar3 = MessageBoxA((HWND)0x0,param_1,s_Giants_Error_0057dbcc,1);

    SetWindowPos(DAT_005dda78,(HWND)0xffffffff,0,0,0,0,3);

    DAT_005ddb38 = DAT_005ddb38 + -1;

    DAT_005ddb4c = (uint)(DAT_005ddb38 == 0);

    if (DAT_005ddb80 != 0) {

      (**(code **)(DAT_00656420 + 0x84))(DAT_00656420,0);

    }

    if (DAT_005ddb38 == 0) {

      time_frame_update();

    }

    if ((iVar3 == 2) || (iVar3 == 3)) {

      DAT_005dda80 = 1;

      DAT_005ddb94 = 1;

    }

    DAT_005ddb90 = 0;

  }

  return;

}

/* ===== FUN_0051ea20 @ 0x0051EA20 ===== */
/* PS2 candidate: memcpy (conf 0.658) */



void FUN_0051ea20(void)



{

  int iVar1;

  

  iVar1 = AudioGetMasterVolume__Fv_2();

  if (iVar1 != 0) {

    error_screen_show();

    return;

  }

  return;

}

/* ===== error_screen_exit @ 0x0051EA30 ===== */
void error_screen_exit(undefined4 param_1)



{

  if (DAT_005dda80 == 0) {

    error_screen_show(param_1);

    DAT_005dda80 = 1;

  }

  return;

}

/* ===== dbg_error_printf @ 0x0051EA60 ===== */
/* PS2 candidate: _Error1 (conf 0.547) */



void dbg_error_printf(LPCSTR param_1)



{

  CHAR local_100 [256];

  

  wvsprintfA(local_100,param_1,&stack0x00000008);

  error_screen_show(local_100);

  return;

}

/* ===== FUN_0051EA90 @ 0x0051EA90 ===== */
void FUN_0051EA90(void)



{

  error_screen_show(&DAT_005dd970);

  return;

}

/* ===== Audio3DTestToneUpdate__Fv_5 @ 0x0051EAA0 ===== */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */



void Audio3DTestToneUpdate__Fv_5(void)



{

  DAT_005ddb3c = 1;

  return;

}

/* ===== FUN_0051f2a0 @ 0x0051F2A0 ===== */
void FUN_0051f2a0(void)



{

  if (DAT_00632f44 != 0) {

    comm_0052b780_user_2();

    Sleep(500);

    return;

  }

  comm_0052b430_user();

  Sleep(500);

  return;

}

/* ===== FUN_0051f2d0 @ 0x0051F2D0 ===== */
int FUN_0051f2d0(void)



{

  int iVar1;

  int *piVar2;

  

  iVar1 = 0;

  piVar2 = &DAT_005ddf60;

  do {

    if (*piVar2 != 0) {

      iVar1 = iVar1 + 1;

    }

    piVar2 = piVar2 + 1;

  } while ((int)piVar2 < 0x5ddfb0);

  return iVar1;

}

/* ===== gamespy_shutdown @ 0x0051F2F0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void gamespy_shutdown(void)



{

  int iVar1;

  undefined4 *puVar2;

  

  if (DAT_005def80 == 5) {

    if (DAT_00632f44 == 0) {

      comm_0052b430_user();

    }

    else {

      comm_0052b780_user_2();

    }

    Sleep(500);

  }

  Audio3DTestToneUpdate__Fv_7();

  if (DAT_00632f44 != 0) {

    if (DAT_005def80 != 0) {

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

    return;

  }

  gamespy_interface_release();

  return;

}

/* ===== GiantsInitNewWorld @ 0x0051F470 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* PS2 candidate: GiantsInitNewWorld (conf 0.633) */



void GiantsInitNewWorld(void)



{

  HRESULT HVar1;

  undefined4 uVar2;

  int iVar3;

  undefined4 *puVar4;

  undefined4 uStack_24c;

  undefined4 uStack_248;

  undefined4 uStack_244;

  undefined4 uStack_240;

  undefined4 auStack_23c [6];

  undefined4 uStack_224;

  undefined4 uStack_220;

  undefined4 uStack_21c;

  undefined4 uStack_218;

  undefined4 uStack_214;

  WCHAR *pWStack_20c;

  undefined4 *puStack_1fc;

  undefined4 uStack_1f8;

  WCHAR local_1f4 [250];

  

  DAT_0063303c = 0x578;

  DAT_00633038 = 0x578;

  puVar4 = (undefined4 *)&DAT_005ddfc0;

  for (iVar3 = 0xa0; iVar3 != 0; iVar3 = iVar3 + -1) {

    *puVar4 = 0;

    puVar4 = puVar4 + 1;

  }

  if (DAT_00633164 == 0) {

    DAT_00632fa8 = 0x4cff;

  }

  if (DAT_0063315c == 0) {

    if (DAT_00633160 != 0) {

      DAT_00632f44 = 0;

    }

  }

  else {

    DAT_00632f44 = 1;

  }

  DAT_005def94 = 0;

  if (DAT_00632f44 == 0) {

    DAT_005ddfb4 = 0;

    iVar3 = gamespy_directplay_init();

    if (iVar3 < 0) {

      uVar2 = FUN_00507b00(s_DPlayInitFail_0057ddc0);

      crt_sprintf(local_1f4,uVar2,iVar3);

      error_screen_show(local_1f4);

      gamespy_interface_release();

      DAT_00633160 = 0;

      DAT_0063315c = 0;

      DAT_0063317c = 0;

      menu_keymap_screen();

      return;

    }

    if (DAT_00633160 == 0) {

      comm_tcpip_menu();

      return;

    }

    DAT_005def80 = 2;

    comm_client_connect_menu();

    return;

  }

  if (DAT_005def80 == 0) {

    chat_init();

    DAT_005def60 = (int *)0x0;

    CoInitialize((LPVOID)0x0);

    HVar1 = CoCreateInstance((IID *)&DAT_00551cbc,(LPUNKNOWN)0x0,1,(IID *)&DAT_00551c9c,

                             &DAT_005def60);

    if (((((-1 < HVar1) &&

          (HVar1 = (**(code **)(*DAT_005def60 + 0xc))(DAT_005def60,0,&LAB_0052c5e0,0), -1 < HVar1))

         && (HVar1 = CoCreateInstance((IID *)&DAT_00551cec,(LPUNKNOWN)0x0,7,(IID *)&DAT_00551cdc,

                                      &DAT_005def68), -1 < HVar1)) &&

        (HVar1 = (**(code **)(*DAT_005def68 + 0x34))(DAT_005def68,&DAT_00551c8c), -1 < HVar1)) &&

       ((DAT_00632fa8 == 0 ||

        (HVar1 = (**(code **)(*DAT_005def68 + 0x48))(DAT_005def68,u_port_0057ddd0,&DAT_00632fa8,4,2)

        , -1 < HVar1)))) {

      comm_stats_init();

      DAT_00633040 = 0;

      DAT_005def80 = 5;

      if (-1 < HVar1) goto LAB_0051f6a4;

    }

    uVar2 = FUN_00507b00(s_DPlayInitFail_0057ddc0);

    crt_sprintf(local_1f4,uVar2,HVar1);

    error_screen_show(local_1f4);

    if (DAT_005def80 == 0) goto LAB_0051f868;

    gamespy_shutdown2();

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

    puVar4 = &DAT_005ddf60;

    for (iVar3 = 0x14; iVar3 != 0; iVar3 = iVar3 + -1) {

      *puVar4 = 0;

      puVar4 = puVar4 + 1;

    }

    _DAT_005de2a4 = 0;

    _DAT_005de2a8 = 0;

    _DAT_005de290 = 0;

    _DAT_005ddf38 = 0;

    _DAT_005de2ac = 0;

    _DAT_005de294 = 0;

    _DAT_005de2b0 = 0;

    _DAT_005ddf3c = 0;

    _DAT_005de298 = 0;

    _DAT_005de2b4 = 0;

    _DAT_005ddf40 = 0;

    _DAT_005de29c = 0;

    _DAT_005ddf44 = 0;

    _DAT_005de2a0 = 0;

    puVar4 = &DAT_005ddd48;

    for (iVar3 = 0x14; iVar3 != 0; iVar3 = iVar3 + -1) {

      *puVar4 = 0;

      puVar4 = puVar4 + 1;

    }

  }

  else {

LAB_0051f6a4:

    MultiByteToWideChar(0,0,&DAT_00632f48,-1,local_1f4,0x100);

    puVar4 = auStack_23c;

    for (iVar3 = 0x12; iVar3 != 0; iVar3 = iVar3 + -1) {

      *puVar4 = 0;

      puVar4 = puVar4 + 1;

    }

    auStack_23c[0] = 0x48;

    auStack_23c[1] = 0x41;

    uStack_224 = *(undefined4 *)PTR_DAT_0057dc4c;

    uStack_220 = *(undefined4 *)(PTR_DAT_0057dc4c + 4);

    uStack_21c = *(undefined4 *)(PTR_DAT_0057dc4c + 8);

    uStack_218 = *(undefined4 *)(PTR_DAT_0057dc4c + 0xc);

    uStack_24c = 0;

    pWStack_20c = local_1f4;

    uStack_248 = 0;

    uStack_244 = 0;

    uStack_214 = DAT_00632f34;

    uStack_240 = 0;

    FUN_00529C00(&uStack_24c,&uStack_248,&uStack_244,&uStack_240);

    puStack_1fc = &uStack_24c;

    uStack_1f8 = 0x10;

    iVar3 = (**(code **)(*DAT_005def60 + 0x34))(DAT_005def60,auStack_23c,&DAT_005def68,1,0,0,0,0);

    if (-1 < iVar3) {

      if (((DAT_00632f44 != 0) && (DAT_0063317c == 0)) && (DAT_00633184 == 0)) {

        uStack_24c = 0x65666e32;

        uStack_248 = 0x6d3130;

        if (DAT_005defa0 == 0) {

          iVar3 = net_0052d300(0,0,0x22cf,s_giants_0057dda8,&uStack_24c,&LAB_0052cb90,&LAB_0052cbc0,

                               &LAB_0052ced0,&LAB_0052cfe0,0);

          if (iVar3 == 0) {

            DAT_005defa0 = 1;

            DAT_005defa4 = 0;

          }

          else {

            FUN_0051ea20(s_Error_starting_Gamespy_query_soc_0057dd80);

          }

        }

      }

      comm_show_conn_menu();

      iVar3 = comm_00426540();

      if (iVar3 == 0) {

        return;

      }

      game_options_verify();

      return;

    }

    uVar2 = FUN_00507b00(s_DPlayHostFail_0057ddb0);

    crt_sprintf(local_1f4,uVar2,iVar3);

    error_screen_show(local_1f4);

    if (DAT_005def80 == 0) goto LAB_0051f868;

    gamespy_shutdown2();

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

    puVar4 = &DAT_005ddf60;

    for (iVar3 = 0x14; iVar3 != 0; iVar3 = iVar3 + -1) {

      *puVar4 = 0;

      puVar4 = puVar4 + 1;

    }

    _DAT_005de2a4 = 0;

    _DAT_005de2a8 = 0;

    _DAT_005de2ac = 0;

    _DAT_005de2b0 = 0;

    puVar4 = &DAT_005ddd48;

    for (iVar3 = 0x14; iVar3 != 0; iVar3 = iVar3 + -1) {

      *puVar4 = 0;

      puVar4 = puVar4 + 1;

    }

    _DAT_005de290 = 0;

    _DAT_005ddf38 = 0;

    _DAT_005de294 = 0;

    _DAT_005ddf3c = 0;

    _DAT_005de298 = 0;

    _DAT_005ddf40 = 0;

    _DAT_005de29c = 0;

    _DAT_005ddf44 = 0;

    _DAT_005de2a0 = 0;

    _DAT_005de2b4 = 0;

  }

  _DAT_005ddf48 = 0;

  DAT_005def80 = 0;

LAB_0051f868:

  DAT_00633160 = 0;

  DAT_0063315c = 0;

  DAT_0063317c = 0;

  menu_keymap_screen();

  return;

}

/* ===== gamespy_directplay_init @ 0x0051F9E0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



HRESULT gamespy_directplay_init(void)



{

  HRESULT HVar1;

  int iVar2;

  undefined4 *puVar3;

  

  if (DAT_005def80 == 0) {

    DAT_005def64 = (int *)0x0;

    CoInitialize((LPVOID)0x0);

    HVar1 = CoCreateInstance((IID *)&DAT_00551ccc,(LPUNKNOWN)0x0,1,(IID *)&DAT_00551cac,

                             &DAT_005def64);

    if ((((-1 < HVar1) &&

         (HVar1 = (**(code **)(*DAT_005def64 + 0xc))(DAT_005def64,0,&LAB_0052c5e0,0), -1 < HVar1))

        && (HVar1 = CoCreateInstance((IID *)&DAT_00551cec,(LPUNKNOWN)0x0,7,(IID *)&DAT_00551cdc,

                                     &DAT_005def6c), -1 < HVar1)) &&

       (((HVar1 = (**(code **)(*DAT_005def6c + 0x34))(DAT_005def6c,&DAT_00551c8c), -1 < HVar1 &&

         (HVar1 = CoCreateInstance((IID *)&DAT_00551cec,(LPUNKNOWN)0x0,7,(IID *)&DAT_00551cdc,

                                   &DAT_005def70), -1 < HVar1)) &&

        (HVar1 = (**(code **)(*DAT_005def70 + 0x34))(DAT_005def70,&DAT_00551c8c), -1 < HVar1)))) {

      puVar3 = &DAT_005ddee8;

      for (iVar2 = 0x14; iVar2 != 0; iVar2 = iVar2 + -1) {

        *puVar3 = 0;

        puVar3 = puVar3 + 1;

      }

      puVar3 = &DAT_005ddf60;

      for (iVar2 = 0x14; iVar2 != 0; iVar2 = iVar2 + -1) {

        *puVar3 = 0;

        puVar3 = puVar3 + 1;

      }

      _DAT_005de2a4 = 0;

      _DAT_005de2a8 = 0;

      _DAT_005de2ac = 0;

      _DAT_005de2b0 = 0;

      _DAT_005de290 = 0;

      _DAT_005de2b4 = 0;

      _DAT_005de294 = 0;

      _DAT_005de298 = 0;

      _DAT_005de29c = 0;

      _DAT_005de2a0 = 0;

      puVar3 = (undefined4 *)&DAT_005ddfc0;

      for (iVar2 = 0xa0; iVar2 != 0; iVar2 = iVar2 + -1) {

        *puVar3 = 0;

        puVar3 = puVar3 + 1;

      }

      puVar3 = &DAT_005ddd48;

      for (iVar2 = 0x14; iVar2 != 0; iVar2 = iVar2 + -1) {

        *puVar3 = 0;

        puVar3 = puVar3 + 1;

      }

      _DAT_005ddf38 = 0;

      _DAT_005ddf3c = 0;

      _DAT_005ddf40 = 0;

      _DAT_005ddf44 = 0;

      puVar3 = &DAT_005dde40;

      for (iVar2 = 0x2a; iVar2 != 0; iVar2 = iVar2 + -1) {

        *puVar3 = 0;

        puVar3 = puVar3 + 1;

      }

      puVar3 = &DAT_005ddda0;

      for (iVar2 = 0x14; iVar2 != 0; iVar2 = iVar2 + -1) {

        *puVar3 = 0;

        puVar3 = puVar3 + 1;

      }

      puVar3 = &DAT_005dddf0;

      for (iVar2 = 0x14; iVar2 != 0; iVar2 = iVar2 + -1) {

        *puVar3 = 0;

        puVar3 = puVar3 + 1;

      }

      _DAT_005ddf48 = 0;

      _DAT_005de284 = 0;

      DAT_005de288 = 0;

      _DAT_005ddd3c = 0;

      DAT_005ddd40 = 0;

      _DAT_005de28c = 0;

      _DAT_005ddd44 = 0;

      _DAT_005def54 = 0;

      DAT_00633040 = 0;

      DAT_005def80 = 1;

    }

    return HVar1;

  }

  return 0;

}

/* ===== gamespy_interface_release @ 0x0051FBA0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void gamespy_interface_release(void)



{

  int iVar1;

  undefined4 *puVar2;

  

  if (DAT_005def80 != 0) {

    (**(code **)(*DAT_005def64 + 0x18))(DAT_005def64,0,4);

    if (DAT_005def6c != (int *)0x0) {

      (**(code **)(*DAT_005def6c + 8))(DAT_005def6c);

      DAT_005def6c = (int *)0x0;

    }

    if (DAT_005def70 != (int *)0x0) {

      (**(code **)(*DAT_005def70 + 8))(DAT_005def70);

      DAT_005def70 = (int *)0x0;

    }

    if (DAT_005def64 != (int *)0x0) {

      (**(code **)(*DAT_005def64 + 0x38))(DAT_005def64,0);

      (**(code **)(*DAT_005def64 + 8))(DAT_005def64);

      DAT_005def64 = (int *)0x0;

    }

    CoUninitialize();

    puVar2 = &DAT_005ddf60;

    for (iVar1 = 0x14; iVar1 != 0; iVar1 = iVar1 + -1) {

      *puVar2 = 0;

      puVar2 = puVar2 + 1;

    }

    _DAT_005de2a4 = 0;

    _DAT_005de2a8 = 0;

    _DAT_005de2ac = 0;

    _DAT_005de2b0 = 0;

    puVar2 = &DAT_005ddd48;

    for (iVar1 = 0x14; iVar1 != 0; iVar1 = iVar1 + -1) {

      *puVar2 = 0;

      puVar2 = puVar2 + 1;

    }

    _DAT_005de290 = 0;

    _DAT_005ddf38 = 0;

    _DAT_005de294 = 0;

    _DAT_005ddf3c = 0;

    _DAT_005de298 = 0;

    _DAT_005ddf40 = 0;

    _DAT_005de29c = 0;

    _DAT_005ddf44 = 0;

    _DAT_005de2a0 = 0;

    _DAT_005de2b4 = 0;

    _DAT_005ddf48 = 0;

    DAT_005def80 = 0;

  }

  return;

}

/* ===== comm_tcpip_menu @ 0x0051FC90 ===== */
void comm_tcpip_menu(void)



{

  byte bVar1;

  char cVar2;

  byte *pbVar3;

  int iVar4;

  char *pcVar5;

  byte *pbVar6;

  char *pcVar7;

  uint uVar8;

  bool bVar9;

  

  DAT_00632c0c = 1;

  if (DAT_0059ee98 != 0) {

    object_destroy(DAT_0059ee98);

  }

  DAT_0059ee98 = object_allocate_type(0x403,0x80000000);

  *(uint *)(DAT_0059ee98 + 0xd8) = *(uint *)(DAT_0059ee98 + 0xd8) | 0x40000000;

  camera_override_refpt(DAT_0059ee98,0);

  dlog_push_level(&LAB_0051fe70,&LAB_0051fe60);

  dialog_level_set_textentry_mode();

  DAT_005def84 = main_dlog_00427150();

  reg_query_value_2(s_IPAddress_0057de38,&DAT_00632f68,0x40);

  main_dlog_00427bb0(DAT_005def84,3,0x3f000000,0x3f333333,0x2a000000,s_ButtonSearch_0057de28);

  main_dlog_00427bb0(DAT_005def84,4,0x3f000000,0x3ee66666,0x2a000000,s_ButtonUseAddr_0057de18);

  main_dlog_004273b0(DAT_005def84,0,0x3f000000,0x3e4ccccd,0x2a000000,s_CommTCPIPParams_0057de08);

  main_dlog_004273b0(DAT_005def84,0,0x3f000000,0x3e6b851f,0x2a000000,s_CommTCPIPParams2_0057ddf4);

  main_dlog_004273b0(DAT_005def84,0,0x3f000000,0x3eb33333,0x2a000000,s_CommTCPHostIP_0057dde4);

  uVar8 = 0;

  if (DAT_00632f68 != '\0') {

    pbVar3 = (byte *)FUN_00507b00(s_WN_None_0057dddc);

    pbVar6 = (byte *)&DAT_00632f68;

    do {

      bVar1 = *pbVar6;

      bVar9 = bVar1 < *pbVar3;

      if (bVar1 != *pbVar3) {

LAB_0051fdff:

        iVar4 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);

        goto LAB_0051fe04;

      }

      if (bVar1 == 0) break;

      bVar1 = pbVar6[1];

      bVar9 = bVar1 < pbVar3[1];

      if (bVar1 != pbVar3[1]) goto LAB_0051fdff;

      pbVar6 = pbVar6 + 2;

      pbVar3 = pbVar3 + 2;

    } while (bVar1 != 0);

    iVar4 = 0;

LAB_0051fe04:

    if (iVar4 != 0) goto LAB_0051fe2f;

  }

  pcVar5 = (char *)FUN_00507b00(s_WN_None_0057dddc);

  pcVar7 = &DAT_00632f68;

  do {

    cVar2 = *pcVar5;

    pcVar5 = pcVar5 + 1;

    *pcVar7 = cVar2;

    pcVar7 = pcVar7 + 1;

  } while (cVar2 != '\0');

  uVar8 = 0x20;

LAB_0051fe2f:

  main_dlog_00427970(DAT_005def84,2,0x3f000000,0x3ec28f5c,uVar8 | 0x28000010,&DAT_00632f68,0x20);

  return;

}

