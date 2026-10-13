/* Giants 1.449 — module _unmapped_0046
 * 84 functions (75 named) — decompiled, names from PS2 symbols
 * Original source: C:\Giants\source\_unmapped_0046.c(pp) (assert-string evidence)
 */

/* ===== sound_player_voice @ 0x00465030 ===== */
void sound_player_voice(undefined4 param_1,undefined4 param_2)



{

  undefined4 uVar1;

  int iVar2;

  

  uVar1 = param_2;

  sound_play_player(param_1,param_2);

  iVar2 = reaper_0052e4a0(uVar1);

  if (iVar2 != 0) {

    param_2 = param_1;

    reaper_00530bd0(uVar1,0,1,0,0x11,&param_2);

  }

  return;

}

/* ===== FUN_00465070 @ 0x00465070 ===== */
void FUN_00465070(int param_1)



{

  int iVar1;

  undefined4 local_14;

  undefined4 local_10;

  undefined4 local_c;

  undefined4 local_8;

  undefined4 local_4;

  

  iVar1 = comm_send_gate_check(param_1);

  if (iVar1 != 0) {

    local_14 = *(undefined4 *)(param_1 + 0xa0);

    local_10 = *(undefined4 *)(param_1 + 0xa4);

    local_c = *(undefined4 *)(param_1 + 0xa8);

    local_8 = *(undefined4 *)(param_1 + 200);

    local_4 = DAT_006328e8;

    comm_chat_send_2(param_1,5,0,0,0x10,&local_14);

  }

  return;

}

/* ===== ai_spread_select @ 0x004650D0 ===== */
int ai_spread_select(undefined4 param_1,float *param_2,float *param_3,float param_4,float param_5,

                    float *param_6)



{

  float fVar1;

  float fVar2;

  float fVar3;

  int iVar4;

  undefined4 *puVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  int iVar10;

  int local_28;

  

  fVar1 = *param_2;

  fVar2 = param_2[1];

  fVar3 = param_2[2];

  local_28 = 0;

  for (puVar5 = DAT_00632d68; puVar5 != (undefined4 *)0x0; puVar5 = (undefined4 *)*puVar5) {

    iVar4 = puVar5[3];

    iVar10 = ai_target_classify(param_1,iVar4,7);

    if ((iVar10 != 0) && ((*(uint *)(iVar4 + 0xd8) & 0x4000c000) == 0)) {

      fVar6 = (*(float *)(iVar4 + 0x288) + *(float *)(iVar4 + 0x27c)) * 0.5 - fVar1;

      fVar7 = (*(float *)(iVar4 + 0x28c) + *(float *)(iVar4 + 0x280)) * 0.5 - fVar2;

      fVar8 = (*(float *)(iVar4 + 0x290) + *(float *)(iVar4 + 0x284)) * 0.5 - fVar3;

      fVar9 = fVar6 * *param_3 + fVar7 * param_3[1] + fVar8 * param_3[2];

      if ((0.0 <= fVar9) &&

         ((fVar9 < param_4 &&

          (fVar6 = (fVar6 * fVar6 + fVar7 * fVar7 + fVar8 * fVar8) - fVar9 * fVar9, fVar6 < param_5)

          ))) {

        param_5 = fVar6;

        local_28 = iVar4;

      }

    }

  }

  if (param_6 != (float *)0x0) {

    *param_6 = param_5;

  }

  return local_28;

}

/* ===== ChooseAnim__FP6OBJECTT0PfP10T_AnimInfoUi @ 0x00465230 ===== */
/* PS2 candidate: ChooseAnim__FP6OBJECTT0PfP10T_AnimInfoUi (conf 0.504) */



int ChooseAnim__FP6OBJECTT0PfP10T_AnimInfoUi

              (float param_1,undefined4 param_2,float *param_3,int *param_4,uint param_5)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  float fVar6;

  int *piVar7;

  int iVar8;

  float10 fVar9;

  int local_18;

  undefined1 local_c [12];

  

  fVar6 = param_1;

  iVar2 = *param_4;

  iVar8 = -1;

  local_18 = 0;

  piVar7 = param_4;

  while (iVar2 != 0xfe) {

    if ((piVar7[4] & param_5) != 0) {

      iVar2 = *(int *)(*(int *)(piVar7[6] + 0xc) + 0x1c);

      iVar3 = *(int *)(*(int *)(piVar7[6] + 0xc) + 0x18);

      iVar4 = piVar7[2];

      iVar5 = piVar7[1];

      param_4 = (int *)0x3f800000;

      do {

        fVar9 = (float10)anim_dump_related(piVar7[6],

                                           (float)piVar7[1] * (float)param_4 +

                                           (1.0 - (float)param_4) * (float)piVar7[2],local_c,fVar6,

                                           param_2,(float)piVar7[1]);

        if ((iVar8 < 0) || (fVar9 < (float10)param_1)) {

          param_1 = (float)fVar9;

          iVar8 = local_18;

        }

        param_4 = (int *)((float)param_4 - (float)(iVar2 * iVar3) / ((float)(iVar4 - iVar5) * 240.0)

                         );

      } while (0.0 <= (float)param_4);

    }

    piVar1 = piVar7 + 7;

    piVar7 = piVar7 + 7;

    local_18 = local_18 + 1;

    iVar2 = *piVar1;

  }

  if (param_3 != (float *)0x0) {

    *param_3 = param_1;

  }

  return iVar8;

}

/* ===== anim_dump_related @ 0x00465350 ===== */
float10 anim_dump_related(int param_1,undefined4 param_2,float *param_3,int param_4,int param_5,

                         float param_6)



{

  float fVar1;

  float fVar2;

  undefined4 uVar3;

  int iVar4;

  float10 fVar5;

  float fStack_18;

  float fStack_14;

  undefined4 local_c;

  undefined4 local_8;

  undefined4 local_4;

  

  if (param_1 == 0) {

    return (float10)0.0;

  }

  uVar3 = __ftol(*(undefined4 *)(param_4 + 0xc));

  iVar4 = ANM_NodeGetMat(param_1,uVar3);

  local_c = *(undefined4 *)(iVar4 + 0x10);

  local_8 = *(undefined4 *)(iVar4 + 0x20);

  local_4 = *(undefined4 *)(iVar4 + 0x30);

  (*(code *)PTR_S_GEO_Vec3Transform_00580c20)(param_3,&local_c,1,param_4 + 0x294);

  fStack_18 = *(float *)(param_5 + 0x128);

  fStack_14 = *(float *)(param_5 + 300);

  fVar1 = *(float *)(param_5 + 0x130);

  if (*(int *)(param_5 + 0x104) == 0) {

    fStack_18 = *(float *)(param_5 + 0x2a0) * *(float *)(param_5 + 0x108) +

                (*(float *)(param_5 + 0x298) * *(float *)(param_5 + 0x110) -

                *(float *)(param_5 + 0x29c) * *(float *)(param_5 + 0x10c)) + fStack_18;

    fVar2 = *(float *)(param_5 + 0x2b0) * *(float *)(param_5 + 0x108);

    fStack_14 = (*(float *)(param_5 + 0x2a8) * *(float *)(param_5 + 0x110) -

                *(float *)(param_5 + 0x2ac) * *(float *)(param_5 + 0x10c)) + fVar2 + fStack_14;

    fVar1 = (*(float *)(param_5 + 0x2b8) * *(float *)(param_5 + 0x110) -

            *(float *)(param_5 + 700) * *(float *)(param_5 + 0x10c)) + fVar2 + fVar1;

  }

  fVar2 = (param_6 - (float)*(int *)(*(int *)(param_1 + 0xc) + 0x10)) * 0.00020833334;

  *param_3 = (*(float *)(param_4 + 0x128) - fStack_18) * fVar2 + *param_3;

  param_3[1] = (*(float *)(param_4 + 300) - fStack_14) * fVar2 + param_3[1];

  param_3[2] = (*(float *)(param_4 + 0x130) - fVar1) * fVar2 + param_3[2];

  fVar5 = (float10)ANM_DumpCluster_2(param_3,param_5);

  return fVar5;

}

/* ===== fx_rect_interp @ 0x004654C0 ===== */
undefined4

fx_rect_interp(undefined4 param_1,int param_2,int param_3,int param_4,float param_5,float *param_6,

              undefined4 *param_7,float param_8)



{

  int iVar1;

  int iVar2;

  float fVar3;

  int iVar4;

  float10 fVar5;

  float local_14;

  undefined4 local_c;

  undefined4 local_8;

  undefined4 local_4;

  

  iVar4 = (int)param_5;

  if (param_2 != 0) {

    iVar1 = *(int *)((int)param_5 + 4);

    iVar2 = *(int *)((int)param_5 + 8);

    if ((byte)(((param_3 < iVar1) << 1 | iVar2 < param_3) &

              ((param_4 < iVar1) << 1 | iVar2 < param_4)) == 0) {

      fVar3 = 0.0;

      local_14 = 1.0;

      if (param_3 < iVar1) {

        fVar3 = (float)(iVar1 - param_3) / (float)(param_4 - param_3);

      }

      if (iVar2 < param_4) {

        local_14 = (float)(iVar2 - param_3) / (float)(param_4 - param_3);

      }

      iVar1 = *(int *)(*(int *)((int)param_5 + 0x18) + 0xc);

      iVar2 = *(int *)(iVar1 + 0x1c);

      iVar1 = *(int *)(iVar1 + 0x18);

      if (fVar3 < local_14 != (fVar3 == local_14)) {

        param_5 = fVar3;

        do {

          fVar5 = (float10)anim_dump_related(*(undefined4 *)(iVar4 + 0x18),

                                             (float)param_4 * param_5 +

                                             (1.0 - param_5) * (float)param_3,&local_c,param_1,

                                             param_2,0);

          if (*param_6 < 0.0) {

            *param_6 = (float)fVar5;

            *param_7 = local_c;

            param_7[1] = local_8;

            param_7[2] = local_4;

          }

          if (fVar5 <= (float10)*param_6 + (float10)0.2) {

            *param_6 = (float)fVar5;

            param_7[3] = *param_7;

            param_7[4] = param_7[1];

            param_7[5] = param_7[2];

            *param_7 = local_c;

            param_7[1] = local_8;

            param_7[2] = local_4;

          }

          else if (*param_6 < param_8) {

            return 1;

          }

          param_5 = param_5 + (float)(iVar2 * iVar1) / ((float)(param_4 - param_3) * 240.0);

        } while (param_5 < local_14 != (param_5 == local_14));

      }

      if ((*(int *)(iVar4 + 8) <= param_4) && (*param_6 < param_8)) {

        return 1;

      }

    }

  }

  return 0;

}

/* ===== reaper_lock_user_3 @ 0x004656B0 ===== */
void reaper_lock_user_3(undefined4 param_1,int param_2,float param_3,int param_4)



{

  int iVar1;

  float local_8;

  undefined4 local_4;

  

  if (param_4 != 0) {

    iVar1 = reaper_0052e4a0(param_1);

    if (iVar1 != 0) {

      local_4 = *(undefined4 *)(param_2 + 0x188);

      local_8 = param_3;

      reaper_00530bd0(param_1,1,1,0,8,&local_8);

    }

  }

  if (param_3 != 0.0) {

    *(float *)(param_2 + 0xc4) = *(float *)(param_2 + 0xc4) / param_3;

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

    iVar1 = ObjIsReaper(param_2);

    if (iVar1 != 0) {

      *(undefined4 *)(param_2 + 0xc4) = *(undefined4 *)(*(int *)(param_2 + 0x100) + 0xfac);

    }

  }

  *(uint *)(param_2 + 0xd8) = *(uint *)(param_2 + 0xd8) & 0xfff7ffff | 0x10000000;

  return;

}

/* ===== reaper_eat_finish @ 0x00465790 ===== */
void reaper_eat_finish(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,

                      float param_5,int param_6,float param_7)



{

  int iVar1;

  float10 fVar2;

  

  if (param_7 != 0.0) {

    *(float *)(param_2 + 0xc4) = *(float *)(param_2 + 0xc4) / param_7;

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

    iVar1 = ObjIsReaper(param_2);

    if (iVar1 != 0) {

      *(undefined4 *)(param_2 + 0xc4) = *(undefined4 *)(*(int *)(param_2 + 0x100) + 0xfac);

    }

  }

  *(uint *)(param_2 + 0xd8) = *(uint *)(param_2 + 0xd8) & 0xfff7ffff | 0x10000000;

  *(int *)(param_2 + 0x210) = param_6;

  *(undefined4 *)(param_2 + 0x218) = 0xffffffff;

  FUN_0050a610(param_6 + 0xa0,param_3);

  fVar2 = (float10)powf();

  reaper_ospec_init(param_6,param_3,param_4,(float)(fVar2 / (float10)param_5),0x3f400000);

  return;

}

/* ===== reaper_update_xhair_status__FP6OBJECT @ 0x00465880 ===== */
/* PS2 candidate: reaper_update_xhair_status__FP6OBJECT (conf 0.376) */



void reaper_update_xhair_status__FP6OBJECT

               (int param_1,int param_2,int param_3,undefined4 param_4,float param_5,float param_6)



{

  float fVar1;

  float *pfVar2;

  int iVar3;

  int iVar4;

  float10 fVar5;

  float local_44;

  float local_40;

  float local_3c;

  float local_38;

  float local_34;

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

  

  iVar4 = param_3;

  if (param_3 == 0) {

    iVar4 = project_cursor_to_ground(&local_38,0x459c4000,&param_3);

    if (iVar4 == 0) {

      pfVar2 = (float *)XFGetCameraOrigin();

      local_44 = *pfVar2;

      local_40 = pfVar2[1];

      local_3c = pfVar2[2];

      pfVar2 = (float *)XFGetCameraAxis(2);

      local_2c = *pfVar2;

      local_28 = pfVar2[1];

      local_24 = pfVar2[2];

      if (*(int *)(param_2 + 4) == 0x2a5) {

        fVar1 = 1000.0;

      }

      else {

        if ((**(byte **)(param_1 + 0x100) & 1) == 0) {

          fVar1 = 1.0;

        }

        else {

          fVar1 = *(float *)(*(byte **)(param_1 + 0x100) + 0x1d0);

        }

        fVar1 = fVar1 * 1000.0;

        param_5 = param_5 * 0.4;

      }

      local_38 = local_2c * fVar1 + local_44;

      local_34 = local_28 * fVar1 + local_40;

      local_30 = local_24 * fVar1 + local_3c;

    }

    iVar4 = object_0046e830(param_1,param_2);

    if (iVar4 != 0) {

      iVar3 = reaper_0052e4a0(param_1);

      if (iVar3 != 0) {

        local_1c = local_34;

        local_10 = param_6;

        local_20 = local_38;

        local_18 = local_30;

        local_c = *(undefined4 *)(iVar4 + 0x188);

        local_14 = param_5;

        local_8 = *(undefined4 *)(param_2 + 0x188);

        local_4 = 0;

        reaper_00530bd0(param_1,5,3,0,6,&local_20);

      }

      reaper_ospec_ptr48_set(iVar4,&LAB_0045afe0);

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

        iVar3 = ObjIsReaper(param_2);

        if (iVar3 != 0) {

          *(undefined4 *)(param_2 + 0xc4) = *(undefined4 *)(*(int *)(param_2 + 0x100) + 0xfac);

        }

      }

      *(uint *)(param_2 + 0xd8) = *(uint *)(param_2 + 0xd8) & 0xfff7ffff | 0x10000000;

      *(int *)(param_2 + 0x210) = iVar4;

      *(undefined4 *)(param_2 + 0x218) = 0xffffffff;

      FUN_0050a610(iVar4 + 0xa0,&local_38);

      fVar5 = (float10)powf();

      param_5 = (float)(fVar5 / (float10)param_5);

      reaper_ospec_init(iVar4,&local_38,0,param_5,0x3f400000);

    }

    return;

  }

  pfVar2 = (float *)XFGetCameraOrigin();

  local_2c = *pfVar2;

  local_28 = pfVar2[1];

  local_24 = pfVar2[2];

  pfVar2 = (float *)XFGetCameraAxis(2);

  local_44 = *pfVar2 * 50000.0 + local_2c;

  local_40 = pfVar2[1] * 50000.0 + local_28;

  local_3c = pfVar2[2] * 50000.0 + local_24;

  iVar3 = collide_line_bbox(&local_38,&local_2c,&local_44,(float *)(iVar4 + 0x27c));

  if (iVar3 != 0) {

    if ((*(uint *)(iVar4 + 0x1c8) & 0x1000000) != 0) goto LAB_00465986;

    iVar3 = los_line_check(&local_2c,&local_44,iVar4,&local_38,0);

    if (iVar3 != 0) goto LAB_00465986;

  }

  local_38 = (*(float *)(iVar4 + 0x288) + *(float *)(iVar4 + 0x27c)) * 0.5;

  local_34 = (*(float *)(iVar4 + 0x28c) + *(float *)(iVar4 + 0x280)) * 0.5;

  local_30 = (*(float *)(iVar4 + 0x290) + *(float *)(iVar4 + 0x284)) * 0.5;

LAB_00465986:

  reaper_spawn_ospec_1(param_1,param_2,&local_38,iVar4,param_5,param_6);

  return;

}

/* ===== reaper_collect_food @ 0x00465BF0 ===== */
/* PS2 candidate: reaper_collect_food (conf 0.513) */



void reaper_collect_food(float param_1,float param_2,undefined4 param_3,float param_4)



{

  undefined4 uVar1;

  float fVar2;

  int iVar3;

  float fVar4;

  undefined4 uVar5;

  undefined4 local_18;

  float local_14;

  undefined4 local_10;

  undefined1 local_c [12];

  

  fVar2 = param_2;

  if (param_2 == 0.0) {

LAB_00465d3b:

    iVar3 = crt_rand_scaled(100);

    if (iVar3 < 0x32) {

      uVar5 = 0x411;

    }

    else {

      uVar5 = 0x412;

    }

  }

  else {

    if (*(int *)((int)param_2 + 0x1e0) == 0x12) {

      iVar3 = crt_rand_scaled(100);

      fVar4 = param_1;

      if (iVar3 < 0x32) {

        uVar5 = 0x474;

      }

      else {

        uVar5 = 0x475;

      }

      sound_play_player(uVar5,param_1);

      iVar3 = *(int *)((int)fVar4 + 0x2dc);

      local_18 = *(undefined4 *)(iVar3 + 0x120);

      local_14 = *(float *)(iVar3 + 0x130);

      local_10 = *(undefined4 *)(iVar3 + 0x140);

      (*(code *)PTR_S_GEO_Vec3Transform_00580c20)(local_c,&local_18,1,(int)fVar4 + 0x294);

      param_1 = *(float *)((int)fVar4 + 200) + 90.0;

      uVar5 = *(undefined4 *)(DAT_00632ed8 + 0x2b4);

      uVar1 = *(undefined4 *)(DAT_00632ed8 + 0x2b8);

      param_2 = *(float *)((int)fVar4 + 200) - 90.0;

      *(undefined4 *)(DAT_00632ed8 + 0x2b4) = 0x3e99999a;

      *(undefined4 *)(DAT_00632ed8 + 0x2b8) = 0x3f4ccccd;

      blood_from_point(local_c,0x1e,0x32,param_2,param_1,0x41200000,0x42340000,0,0x41700000);

      *(undefined4 *)(DAT_00632ed8 + 0x2b4) = uVar5;

      *(undefined4 *)(DAT_00632ed8 + 0x2b8) = uVar1;

      goto LAB_00465d63;

    }

    if (*(int *)((int)param_2 + 0x1e0) != 0x15) goto LAB_00465d3b;

    iVar3 = crt_rand_scaled(100);

    if (iVar3 < 0x32) {

      uVar5 = 0x481;

    }

    else {

      uVar5 = 0x482;

    }

  }

  fVar4 = param_1;

  sound_play_player(uVar5,param_1);

LAB_00465d63:

  iVar3 = reaper_0052e4a0(fVar4);

  if (iVar3 == 0) {

    *(undefined4 *)((int)fVar4 + 0x278) = param_3;

  }

  else {

    if (fVar2 == 0.0) {

      return;

    }

    local_10 = *(undefined4 *)((int)fVar2 + 0x188);

    local_18 = param_3;

    local_14 = param_4;

    reaper_00530bd0(fVar4,2,1,0,3,&local_18);

  }

  if (fVar2 != 0.0) {

    if (param_4 != 0.0) {

      *(float *)((int)fVar2 + 0xc4) = *(float *)((int)fVar2 + 0xc4) / param_4;

    }

    *(undefined4 *)((int)fVar2 + 0x210) = 0;

    if (*(int *)((int)fVar2 + 0x1e0) == 0x59) {

      if (*(int *)((int)fVar2 + 0x218) < 2) {

        FUN_00425850(fVar2);

      }

    }

    else if (*(int *)((int)fVar2 + 0x1e0) == 0x12) {

      smartie_release_to_bldg();

    }

    else {

      iVar3 = ObjIsReaper(fVar2);

      if (iVar3 != 0) {

        *(undefined4 *)((int)fVar2 + 0xc4) = *(undefined4 *)(*(int *)((int)fVar2 + 0x100) + 0xfac);

      }

    }

    *(uint *)((int)fVar2 + 0xd8) = *(uint *)((int)fVar2 + 0xd8) & 0xfff7ffff | 0x10000000;

    if (*(int *)((int)fVar2 + 4) != 0xb) {

      sine_cos_lookup(*(undefined4 *)((int)fVar4 + 200),&param_1,&param_4);

      if (*(int *)((int)fVar2 + 0x104) == 0) {

        *(float *)((int)fVar2 + 0x128) = param_1 * 100.0;

        *(undefined4 *)((int)fVar2 + 0x108) = 0x41f00000;

        *(float *)((int)fVar2 + 300) = param_4 * -100.0;

      }

      else {

        *(float *)((int)fVar2 + 0x128) = param_1 * 100.0 + *(float *)((int)fVar2 + 0x128);

        *(float *)((int)fVar2 + 300) = *(float *)((int)fVar2 + 300) - param_4 * 100.0;

        *(float *)((int)fVar2 + 0x130) = *(float *)((int)fVar2 + 0x130) + 30.0;

      }

    }

    iVar3 = fx_create(fVar4);

    if (iVar3 != 0) {

      obj_damage_apply(7,0x461c4000,fVar2,fVar4,0,0);

    }

  }

  return;

}

/* ===== camera_ref_anode @ 0x00465F10 ===== */
void camera_ref_anode(int param_1,undefined4 param_2,int param_3,int *param_4)



{

  int iVar1;

  int *piVar2;

  undefined1 local_44 [68];

  

  iVar1 = param_1;

  if (param_4 == (int *)0x0) {

    if ((*(byte *)(param_1 + 0x20c) & 1) != 0) {

      param_1 = 0;

      ref_get_anode2(local_44,&param_1,iVar1,1,7,0);

      camera_override_begin(local_44);

      AudioSetSpeakerConfig__F14SPEAKER_SYSTEM(param_1);

      return;

    }

  }

  else if ((*(byte *)(param_1 + 0x20c) & 1) != 0) {

    iVar1 = *param_4;

    for (piVar2 = param_4; (-1 < iVar1 && ((param_3 < piVar2[1] || (piVar2[2] <= param_3))));

        piVar2 = piVar2 + 3) {

      iVar1 = piVar2[3];

    }

    camera_override_refpt(param_1,*piVar2);

    return;

  }

  camera_override_done();

  return;

}

/* ===== kabutoai_death_handler_c1 @ 0x00465FB0 ===== */
void kabutoai_death_handler_c1(int param_1,int param_2,undefined4 param_3,float *param_4)



{

  byte bVar1;

  char cVar2;

  undefined1 uVar3;

  uint *puVar4;

  float fVar5;

  float fVar6;

  undefined2 uVar7;

  float *pfVar8;

  float *pfVar9;

  undefined4 uVar10;

  int iVar11;

  int iVar12;

  int iVar13;

  float *pfVar14;

  float10 fVar15;

  float fStack_10;

  float fStack_c;

  float fStack_8;

  undefined1 uStack_4;

  

  kabuto_init(param_1);

  pfVar8 = param_4;

  switch(param_2) {

  case 1:

    *(float *)(param_1 + 0xa0) = *param_4;

    *(float *)(param_1 + 0xa4) = param_4[1];

    *(float *)(param_1 + 0xa8) = param_4[2];

    *(float *)(param_1 + 0x128) = param_4[3];

    *(float *)(param_1 + 300) = param_4[4];

    *(float *)(param_1 + 0x130) = param_4[5];

    *(float *)(param_1 + 0x114) = param_4[6];

    *(float *)(param_1 + 200) = param_4[7];

    goto LAB_0046615e;

  case 2:

    *(float *)(param_1 + 0x128) = *param_4;

    *(float *)(param_1 + 300) = param_4[1];

    *(float *)(param_1 + 0x130) = param_4[2];

    *(float *)(param_1 + 200) = param_4[3];

    return;

  case 3:

    uVar10 = objanim_select_animloop(param_4[2]);

    reaper_collect_food(param_1,uVar10,*pfVar8,pfVar8[1]);

    return;

  case 4:

    iVar12 = objanim_select_animloop(param_4[7]);

    if (iVar12 != 0) {

      param_2 = objanim_select_animloop(pfVar8[8]);

      if (param_2 == 0) {

        param_2 = param_1;

      }

      fVar5 = *pfVar8;

      bVar1 = *(byte *)(pfVar8 + 9);

      pfVar14 = pfVar8 + 1;

      if (pfVar14 != (float *)0x0) {

        if ((~bVar1 & 0x10) != 0) {

          param_4 = (float *)0x3f000000;

          if (param_1 != 0) {

            iVar13 = ObjIsKabuto(param_1);

            if (iVar13 == 0) {

              param_4 = (float *)0x3f800000;

            }

            else {

              param_4 = *(float **)(*(int *)(param_1 + 0x100) + 0x1d0);

            }

          }

          pfVar9 = param_4;

          iVar13 = 3;

          do {

            fStack_10 = *pfVar14;

            fStack_c = pfVar8[2];

            fStack_8 = pfVar8[3];

            fVar15 = (float10)rndfloatrange(0xc1200000,0x41200000);

            fStack_10 = (float)(fVar15 + (float10)fStack_10);

            fVar15 = (float10)rndfloatrange(0xc1200000,0x41200000);

            fStack_c = (float)(fVar15 + (float10)fStack_c);

            fVar15 = (float10)rndfloatrange(0xc1200000,0x41200000);

            fStack_8 = (float)(fVar15 + (float10)fStack_8);

            make_dust_ball(&fStack_10,pfVar9);

            iVar13 = iVar13 + -1;

          } while (iVar13 != 0);

        }

        anm_binder_free(pfVar14,*(undefined1 *)(iVar12 + 0x1f5),0,6);

      }

      iVar13 = param_2;

      iVar11 = fx_create(param_2);

      if ((bVar1 & 0xc) == 0) {

        if (iVar11 != 0) {

          obj_damage_apply(4,fVar5,iVar12,iVar13,pfVar14,0);

          return;

        }

      }

      else if (iVar11 != 0) {

        obj_damage_apply(6,fVar5,iVar12,iVar13,pfVar14,0);

        return;

      }

    }

    break;

  case 5:

    iVar12 = objanim_select_animloop(param_4[1]);

    if (iVar12 != 0) {

      iVar13 = objanim_select_animloop(pfVar8[2]);

      if (iVar13 == 0) {

        iVar13 = param_1;

      }

      param_4 = (float *)*pfVar8;

      if (((uint)pfVar8[3] & 0xc) == 0) {

        iVar11 = fx_create(iVar13);

        if (iVar11 != 0) {

          obj_damage_apply(4,param_4,iVar12,iVar13,0,0);

          return;

        }

      }

      else {

        iVar11 = fx_create(iVar13);

        if (iVar11 != 0) {

          obj_damage_apply(6,param_4,iVar12,iVar13,0,0);

          return;

        }

      }

    }

    break;

  case 6:

    iVar12 = objanim_select_animloop(param_4[6]);

    if ((iVar12 != 0) && (iVar13 = object_0046e830(param_1,iVar12), iVar13 != 0)) {

      uVar10 = objanim_select_animloop(pfVar8[7]);

      *(float *)(iVar13 + 0x188) = pfVar8[5];

      *(uint *)(iVar13 + 0x1c8) = *(uint *)(iVar13 + 0x1c8) | 0xe00;

      reaper_ospec_ptr48_set(iVar13,&LAB_0045afe0);

      param_4 = (float *)pfVar8[3];

      if (pfVar8[4] != 0.0) {

        *(float *)(iVar12 + 0xc4) = *(float *)(iVar12 + 0xc4) / pfVar8[4];

      }

      *(undefined4 *)(iVar12 + 0x210) = 0;

      if (*(int *)(iVar12 + 0x1e0) == 0x59) {

        if (*(int *)(iVar12 + 0x218) < 2) {

          FUN_00425850(iVar12);

        }

      }

      else if (*(int *)(iVar12 + 0x1e0) == 0x12) {

        smartie_release_to_bldg();

      }

      else {

        iVar11 = ObjIsReaper(iVar12);

        if (iVar11 != 0) {

          *(undefined4 *)(iVar12 + 0xc4) = *(undefined4 *)(*(int *)(iVar12 + 0x100) + 0xfac);

        }

      }

      *(uint *)(iVar12 + 0xd8) = *(uint *)(iVar12 + 0xd8) & 0xfff7ffff | 0x10000000;

      *(int *)(iVar12 + 0x210) = iVar13;

      *(undefined4 *)(iVar12 + 0x218) = 0xffffffff;

      FUN_0050a610(iVar13 + 0xa0,pfVar8);

      fVar15 = (float10)powf();

      param_4 = (float *)(float)(fVar15 / (float10)(float)param_4);

      reaper_ospec_init(iVar13,pfVar8,uVar10,param_4,0x3f400000);

      return;

    }

    break;

  case 7:

    iVar12 = objanim_select_animloop(param_4[1]);

    if (iVar12 != 0) {

      reaper_lock_short_5(param_1,iVar12,*pfVar8,*(undefined1 *)(pfVar8 + 2),0);

      return;

    }

    break;

  case 8:

    iVar12 = objanim_select_animloop(param_4[1]);

    if (iVar12 != 0) {

      if (*pfVar8 != 0.0) {

        *(float *)(iVar12 + 0xc4) = *(float *)(iVar12 + 0xc4) / *pfVar8;

      }

      *(undefined4 *)(iVar12 + 0x210) = 0;

      if (*(int *)(iVar12 + 0x1e0) == 0x59) {

        if (*(int *)(iVar12 + 0x218) < 2) {

          FUN_00425850(iVar12);

        }

      }

      else if (*(int *)(iVar12 + 0x1e0) == 0x12) {

        smartie_release_to_bldg();

      }

      else {

        iVar13 = ObjIsReaper(iVar12);

        if (iVar13 != 0) {

          *(undefined4 *)(iVar12 + 0xc4) = *(undefined4 *)(*(int *)(iVar12 + 0x100) + 0xfac);

        }

      }

      *(uint *)(iVar12 + 0xd8) = *(uint *)(iVar12 + 0xd8) & 0xfff7ffff | 0x10000000;

      return;

    }

    break;

  case 9:

    ObjectSetAnim(param_1,param_4[2],param_4[3],param_4[4],*param_4,param_4[1]);

    return;

  case 10:

    iVar12 = object_spawn_init_usage(param_1,param_4,param_4 + 3);

    if (iVar12 != 0) {

      *(float *)(iVar12 + 0x188) = pfVar8[6];

      *(undefined4 *)(iVar12 + 0x18c) = *(undefined4 *)(param_1 + 0x18c);

      return;

    }

    break;

  case 0xb:

    cVar2 = *(char *)((int)param_4 + 1);

    uVar7 = *(undefined2 *)param_4;

    iVar12 = *(int *)(param_1 + 0x100);

    param_4 = (float *)(float)*(byte *)param_4;

    if ((*(float *)(iVar12 + 0x158) != (float)param_4) || (cVar2 != '\0')) {

      sound_play_player(0x6e4,param_1);

      iVar13 = reaper_0052e4a0(param_1);

      if (iVar13 != 0) {

        param_2 = 0x6e4;

        reaper_00530bd0(param_1,0,1,0,0x11,&param_2);

      }

      *(float **)(iVar12 + 0x158) = param_4;

      if (cVar2 != '\0') {

        *(float **)(iVar12 + 0x15c) = param_4;

        obj_lod_lerp_update(param_1);

      }

      iVar12 = reaper_0052e4a0(param_1);

      if (iVar12 != 0) {

        param_4 = (float *)CONCAT22(param_4._2_2_,uVar7);

        reaper_00530bd0(param_1,0,0,2,0xb,&param_4);

        return;

      }

    }

    break;

  case 0xc:

    iVar12 = objanim_select_animloop(*param_4);

    if (iVar12 != 0) {

      object_destroy(iVar12);

      return;

    }

    break;

  case 0xd:

    iVar12 = objanim_select_animloop(param_4[3]);

    if (iVar12 != 0) {

      reaper_spell_user(param_1,iVar12,pfVar8);

      return;

    }

    break;

  case 0xe:

    iVar12 = 0;

    if (*param_4 != 0.0) {

      iVar12 = objanim_select_animloop(*param_4);

    }

    iVar13 = *(int *)(param_1 + 0x100);

    if (*(int *)(iVar13 + 0x30c) != iVar12) {

      iVar11 = reaper_0052e4a0(param_1);

      if (iVar11 != 0) {

        param_4 = (float *)0x0;

        if (iVar12 != 0) {

          param_4 = *(float **)(iVar12 + 0x188);

        }

        reaper_00530bd0(param_1,0,1,0,0xe,&param_4);

      }

      *(int *)(iVar13 + 0x30c) = iVar12;

      *(undefined4 *)(iVar13 + 0x310) = 0;

      return;

    }

    break;

  case 0xf:

    *(undefined1 *)(*(int *)(param_1 + 0x100) + 0x228) = *(undefined1 *)param_4;

    return;

  case 0x10:

    puVar4 = *(uint **)(param_1 + 0x100);

    if ((*puVar4 & 0x400000) == 0) {

      puVar4[0xd3] = (uint)param_4[4];

      *(float *)(param_1 + 0xa0) = *param_4;

      *(float *)(param_1 + 0xa4) = param_4[1];

      *(float *)(param_1 + 0xa8) = param_4[2];

      *(float *)(param_1 + 200) = param_4[3];

      *puVar4 = *puVar4 | 0x400000;

    }

    else {

      fVar5 = param_4[4] - (float)puVar4[0xd3];

      if (fVar5 < 0.0 != (fVar5 == 0.0)) {

        return;

      }

      if (1.0 < fVar5) {

        fVar5 = 1.0;

      }

      puVar4[0xd4] = (uint)(fVar5 * 1.2);

      if (fVar5 <= 0.005) {

        param_4 = (float *)0x43480000;

      }

      else {

        pfVar14 = param_4 + 4;

        param_4 = (float *)(1.0 / fVar5);

        puVar4[0xd3] = (uint)*pfVar14;

      }

      *(float *)(param_1 + 0x128) = (*pfVar8 - *(float *)(param_1 + 0xa0)) * (float)param_4;

      *(float *)(param_1 + 300) = (pfVar8[1] - *(float *)(param_1 + 0xa4)) * (float)param_4;

      *(float *)(param_1 + 0x130) = (pfVar8[2] - *(float *)(param_1 + 0xa8)) * (float)param_4;

      fVar15 = (float10)playerobj_turn(pfVar8[3],*(undefined4 *)(param_1 + 200));

      *(float *)(param_1 + 0x114) = (float)(fVar15 * (float10)(float)param_4);

    }

LAB_0046615e:

    if ((*(uint *)(param_1 + 0xd8) & 0x4000) != 0) {

      obj_children_flag_clear(param_1);

      return;

    }

    break;

  case 0x11:

    sound_play_obj(*param_4,param_1);

    return;

  case 0x12:

    sound_stop_obj(*param_4,param_1);

    return;

  case 0x13:

    if ((*param_4 != 0.0) && (iVar12 = objanim_select_animloop(*param_4), iVar12 != 0)) {

      sound_play_obj(pfVar8[1],iVar12);

      return;

    }

    break;

  case 0x14:

    if ((*param_4 != 0.0) && (iVar12 = objanim_select_animloop(*param_4), iVar12 != 0)) {

      sound_stop_obj(pfVar8[1],iVar12);

      return;

    }

    break;

  case 0x15:

    fVar5 = param_4[2];

    fVar6 = param_4[1];

    uVar3 = *(undefined1 *)(param_4 + 3);

    param_4 = (float *)*param_4;

    iVar12 = kabuto_corpse_create__FP6OBJECTi(0,fVar5);

    iVar13 = reaper_0052e4a0(param_1);

    if (iVar13 == 0) {

      *(float *)(iVar12 + 0x188) = fVar6;

    }

    else {

      fStack_c = *(float *)(iVar12 + 0x188);

      fStack_10 = (float)param_4;

      fStack_8 = fVar5;

      uStack_4 = uVar3;

      reaper_00530bd0(param_1,1,2,1,0x15,&fStack_10);

    }

    reaper_lock_short_5(param_1,iVar12,param_4,uVar3,0);

    return;

  }

  return;

}

/* ===== teammecc_get_slavecount @ 0x00466980 ===== */
/* PS2 candidate: kabuto_get_kbos (conf 0.309) */



undefined4 teammecc_get_slavecount(int param_1,int param_2)



{

  if (param_2 == 0) {

    return *(undefined4 *)(*(int *)(param_1 + 0x100) + 800);

  }

  return *(undefined4 *)(*(int *)(param_1 + 0x100) + 0x324);

}

/* ===== kabuto_create_kbos @ 0x004669A0 ===== */
/* PS2 candidate: kabuto_create_kbos (conf 0.438) */



void kabuto_create_kbos(float param_1,int param_2)



{

  int iVar1;

  int iVar2;

  int iVar3;

  float10 fVar4;

  float local_18;

  float local_14 [3];

  float local_8;

  float local_4;

  

  iVar2 = (int)param_1;

  iVar1 = *(int *)((int)param_1 + 0x100);

  if (param_2 == 0) {

    param_1 = *(float *)((int)param_1 + 200) + 40.0;

    if (360.0 < param_1) {

      param_1 = param_1 - 360.0;

    }

  }

  else {

    param_1 = *(float *)((int)param_1 + 200) - 40.0;

    if (param_1 < 0.0) {

      param_1 = param_1 + 360.0;

    }

  }

  sine_cos_lookup(param_1,&local_18,local_14);

  local_4 = *(float *)(iVar2 + 0xa8);

  local_14[0] = -local_14[0];

  local_14[1] = 0.0;

  local_14[2] = local_18 * 50.0 + *(float *)(iVar2 + 0xa0);

  local_8 = local_14[0] * 50.0 + *(float *)(iVar2 + 0xa4);

  fVar4 = (float10)ground_get_z(local_14 + 2);

  local_4 = (float)fVar4;

  if (param_2 == 0) {

    iVar3 = kbos_offspring_create(local_14 + 2);

    *(int *)(iVar1 + 800) = iVar3;

  }

  else {

    iVar3 = kbos_offspring_create(local_14 + 2);

    *(int *)(iVar1 + 0x324) = iVar3;

  }

  *(undefined4 *)(iVar3 + 0x18c) = *(undefined4 *)(iVar2 + 0x18c);

  return;

}

/* ===== reaper_death_broadcaster_c1 @ 0x00466AB0 ===== */
void reaper_death_broadcaster_c1

               (int param_1,float param_2,int param_3,int param_4,float *param_5,int param_6)



{

  float fVar1;

  float fVar2;

  uint uVar3;

  float fVar4;

  bool bVar5;

  undefined4 *puVar6;

  int iVar7;

  int iVar8;

  float *pfVar9;

  undefined4 *puVar10;

  undefined4 uVar11;

  float fStack_d8;

  int iStack_d4;

  float fStack_d0;

  float fStack_cc;

  undefined4 uStack_c8;

  undefined4 uStack_c4;

  undefined4 uStack_c0;

  float fStack_bc;

  float fStack_b8;

  float fStack_b4;

  undefined4 auStack_b0 [7];

  int iStack_94;

  float *pfStack_90;

  undefined1 auStack_70 [112];

  

  fVar1 = *(float *)(param_3 + 0x278);

  iStack_d4 = *(int *)(param_3 + 0x100);

  fVar2 = *(float *)(param_3 + 0x1c0);

  iVar7 = FUN_00494f90();

  if (iVar7 != 0) {

    return;

  }

  if (60.0 < param_2) {

    hurt_pusher(param_1,param_2,param_2,param_3,param_4,param_5);

  }

  if (param_1 == 0xc) {

    param_2 = *(float *)(DAT_00632ed8 + 0x1598) * param_2;

  }

  fVar4 = param_2 + *(float *)(param_3 + 0x278);

  *(float *)(param_3 + 0x278) = fVar4;

  if (fVar4 < 0.0) {

    *(undefined4 *)(param_3 + 0x278) = 0;

  }

  if (*(float *)(param_3 + 0x278) < *(float *)(param_3 + 0x1c0)) {

    if ((140.0 < param_2) || (param_1 == 0xc)) {

      iVar7 = crt_rand_scaled(100);

      if (iVar7 < 0x32) {

        uVar11 = 0x43d;

      }

      else {

        uVar11 = 0x43e;

      }

    }

    else if (param_2 <= 70.0) {

      iVar7 = crt_rand_scaled(100);

      if (iVar7 < 0x32) {

        uVar11 = 0x445;

      }

      else {

        uVar11 = 0x446;

      }

    }

    else {

      iVar7 = crt_rand_scaled(100);

      if (iVar7 < 0x32) {

        uVar11 = 0x457;

      }

      else {

        uVar11 = 0x458;

      }

    }

    sound_play_player(uVar11,param_3);

    iVar7 = fx_create(param_3);

    if (iVar7 == 0) {

      return;

    }

    if ((0x30 < param_1) && (param_1 < 0x45)) {

      if (param_2 < 500.0) {

        return;

      }

      if (param_5 == (float *)0x0) {

        if (param_4 == 0) {

          return;

        }

        param_5 = (float *)(param_4 + 0xa0);

        if (param_5 == (float *)0x0) {

          return;

        }

      }

      pfVar9 = (float *)(param_3 + 0xa0);

      if ((*(int *)(param_3 + 0x10) != 0xfe) &&

         (iVar7 = *(int *)(*(int *)(param_3 + 8) + 8 + *(int *)(param_3 + 0x10) * 4), iVar7 != 0)) {

        fStack_bc = (*(float *)(iVar7 + 0x18) + *(float *)(iVar7 + 0xc)) * 0.5;

        fStack_b8 = (*(float *)(iVar7 + 0x1c) + *(float *)(iVar7 + 0x10)) * 0.5;

        fStack_b4 = (*(float *)(iVar7 + 0x20) + *(float *)(iVar7 + 0x14)) * 0.5;

        xformobj_p3d_world(param_3,&fStack_bc,&fStack_cc);

        pfVar9 = &fStack_cc;

      }

      if (0.0 <= -*(float *)(param_3 + 0x29c) * (*pfVar9 - *param_5) +

                 -*(float *)(param_3 + 0x2ac) * (pfVar9[1] - param_5[1]) +

                 -*(float *)(param_3 + 700) * (pfVar9[2] - param_5[2])) {

        *(undefined4 *)(iStack_d4 + 0x98) = 0xb6;

      }

      else {

        *(undefined4 *)(iStack_d4 + 0x98) = 0xb7;

      }

      *(undefined4 *)(iStack_d4 + 0x9c) = 0xd;

      *(undefined4 *)(iStack_d4 + 4) = 0x41200000;

      return;

    }

    if (param_1 == 0xc) {

      if (param_2 < 300.0) {

        return;

      }

      *(undefined4 *)(iStack_d4 + 0x9c) = 0xd;

      *(undefined4 *)(iStack_d4 + 0x98) = 0xb5;

      *(undefined4 *)(iStack_d4 + 4) = 0x41200000;

      return;

    }

    if (param_2 <= 80.0) {

      return;

    }

    if (param_6 == 0) {

      if (param_5 == (float *)0x0) {

        return;

      }

      puVar10 = auStack_b0;

      for (iVar7 = 9; iVar7 != 0; iVar7 = iVar7 + -1) {

        *puVar10 = 0;

        puVar10 = puVar10 + 1;

      }

      fStack_cc = 0.0;

      uStack_c8 = 0;

      uStack_c4 = 0;

      pfStack_90 = &fStack_cc;

      uStack_c0 = 0;

      xformobj_world_local(param_3,param_5,auStack_b0);

      uVar11 = anm_apply_nodes(param_3,0,auStack_70);

      nam_lookup_full(auStack_70,uVar11,auStack_b0,1,*(undefined4 *)(param_3 + 0xc));

      param_6 = iStack_94;

      if (iStack_94 == 0) {

        return;

      }

    }

    bVar5 = false;

    puVar10 = (undefined4 *)0x55abc8;

    iVar7 = iRam0055abc8;

    while ((iVar7 != 0xfe && (!bVar5))) {

      iVar7 = puVar10[1];

      bVar5 = false;

      puVar6 = puVar10;

      while ((iVar7 != 0 && (!bVar5))) {

        iVar7 = FUN_00545650(puVar6[1],param_6);

        if (iVar7 == 0) {

          *(undefined4 *)(iStack_d4 + 0x9c) = 0xd;

          *(undefined4 *)(iStack_d4 + 0x98) = *puVar10;

          *(undefined4 *)(iStack_d4 + 4) = 0x41200000;

          bVar5 = true;

        }

        iVar7 = puVar6[2];

        puVar6 = puVar6 + 1;

      }

      iVar7 = puVar10[0x15];

      puVar10 = puVar10 + 0x15;

    }

    crt_sprintf(auStack_b0,s_Hit_bone___s_0055b3cc,param_6);

    str_copy_to_static(auStack_b0);

    return;

  }

  *(undefined4 *)(param_3 + 0x278) = *(undefined4 *)(param_3 + 0x1c0);

  if (fVar2 <= fVar1) {

    return;

  }

  *(undefined4 *)(iStack_d4 + 0x318) = 0;

  *(undefined4 *)(iStack_d4 + 0x31c) = 0;

  if (DAT_00632f08 == 0) {

    hud_feed_buffer_clear();

    DAT_00632c00 = 1;

  }

  iVar7 = crt_rand_scaled(100);

  if (iVar7 < 0x32) {

    sound_play_player(0x40d,param_3);

    iVar7 = reaper_0052e4a0(param_3);

    if (iVar7 == 0) goto code_r0x00466d6b;

    fStack_d8 = 1.45315e-42;

    uVar11 = 0x11;

  }

  else {

    sound_play_player(0x40e,param_3);

    iVar7 = reaper_0052e4a0(param_3);

    if (iVar7 != 0) {

      fStack_d8 = 1.45455e-42;

      reaper_00530bd0(param_3,0,1,0,0x11,&fStack_d8);

    }

    uVar3 = **(uint **)(param_3 + 0x100);

    if ((uVar3 & 0x800000) != 0) {

      **(uint **)(param_3 + 0x100) = uVar3 & 0xff7fffff;

      sound_stop_obj(0x486,param_3);

      iVar7 = reaper_0052e4a0(param_3);

      if (iVar7 != 0) {

        fStack_d8 = 1.6227e-42;

        reaper_00530bd0(param_3,0,1,0,0x12,&fStack_d8);

      }

    }

    uVar3 = **(uint **)(param_3 + 0x100);

    if ((uVar3 & 0x1000000) != 0) {

      **(uint **)(param_3 + 0x100) = uVar3 & 0xfeffffff;

      sound_stop_obj(0x472,param_3);

      iVar7 = reaper_0052e4a0(param_3);

      if (iVar7 != 0) {

        fStack_d8 = 1.59468e-42;

        reaper_00530bd0(param_3,0,1,0,0x12,&fStack_d8);

      }

    }

    uVar3 = **(uint **)(param_3 + 0x100);

    if ((uVar3 & 0x4000000) != 0) {

      **(uint **)(param_3 + 0x100) = uVar3 & 0xfbffffff;

      sound_stop_obj(0x6dd,param_3);

      iVar7 = reaper_0052e4a0(param_3);

      if (iVar7 != 0) {

        fStack_d8 = 2.46208e-42;

        reaper_00530bd0(param_3,0,1,0,0x12,&fStack_d8);

      }

    }

    uVar3 = **(uint **)(param_3 + 0x100);

    if ((uVar3 & 0x2000000) == 0) goto code_r0x00466d6b;

    **(uint **)(param_3 + 0x100) = uVar3 & 0xfdffffff;

    sound_stop_obj(0x6dc,param_3);

    iVar7 = reaper_0052e4a0(param_3);

    if (iVar7 == 0) goto code_r0x00466d6b;

    fStack_d8 = 2.46068e-42;

    uVar11 = 0x12;

  }

  reaper_00530bd0(param_3,0,1,0,uVar11,&fStack_d8);

code_r0x00466d6b:

  iVar7 = fx_create(param_3);

  if (iVar7 == 0) {

    return;

  }

  iVar7 = *(int *)(param_3 + 0x100);

  if (*(int *)(iVar7 + 800) != 0) {

    func_0x0046c230(*(int *)(iVar7 + 800));

    *(undefined4 *)(iVar7 + 800) = 0;

  }

  if (*(int *)(iVar7 + 0x324) != 0) {

    func_0x0046c230(*(int *)(iVar7 + 0x324));

    *(undefined4 *)(iVar7 + 0x324) = 0;

  }

  func_0x0045c010(param_3);

  iVar7 = reaper_0052e4a0(param_3);

  if ((iVar7 != 0) && ((*(byte *)(param_3 + 0x1c8) & 1) != 0)) {

    if ((param_4 != 0) && (*(int *)(param_4 + 0x274) != 0)) {

      param_4 = *(int *)(param_4 + 0x274);

    }

    if (param_1 != 0x13) {

      if (param_4 == 0) {

        iVar7 = 0;

      }

      else {

        iVar7 = *(int *)(param_4 + 0x18c) + -1;

      }

      fStack_d0 = (float)DAT_00632f24;

      if (iVar7 < 0) {

        iVar7 = 0;

      }

      iVar8 = ObjIsTurret(param_4);

      if (iVar8 == 0) {

        comm_kill_message(param_4,param_3,param_1);

      }

      else {

        comm_kill_message2(*(int *)(param_4 + 0x18c) + -1,param_3,0x30);

        param_4 = 0;

      }

      if ((iVar7 == 1) || (iVar7 == 2)) {

        fStack_d0 = (float)DAT_00632f28;

      }

      iVar8 = game_mode_set2_check(DAT_00632f18);

      if (iVar8 == 0) {

        fStack_d8 = fStack_d0;

      }

      else {

        fStack_d8 = 0.0;

      }

      comm_death_packet_build

                (param_4,param_3,iVar7,*(int *)(param_3 + 0x18c) + -1,fStack_d0,fStack_d8,0x3f800000

                 ,0x3f800000);

    }

  }

  *(undefined4 *)(iStack_d4 + 0x9c) = 0xc;

  if (param_1 != 0xc) {

    *(undefined4 *)(iStack_d4 + 0x98) = 0x93;

    return;

  }

  *(undefined4 *)(iStack_d4 + 0x98) = 0x94;

  return;

}

/* ===== cspec_00467250 @ 0x00467250 ===== */
undefined4 cspec_00467250(void)



{

  return 0x358;

}

/* ===== AudioDataStreamStatus__Fv @ 0x00467260 ===== */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */



undefined4 AudioDataStreamStatus__Fv(void)



{

  return 0;

}

/* ===== obj_skinning_eval @ 0x00467510 ===== */
void obj_skinning_eval(int param_1)



{

  undefined4 *puVar1;

  uint uVar2;

  undefined4 *puVar3;

  undefined4 *puVar4;

  int iVar5;

  int iVar6;

  undefined4 *puVar7;

  undefined4 *puVar8;

  undefined4 *puVar9;

  float10 fVar10;

  undefined4 local_178;

  undefined4 local_174;

  undefined4 local_170;

  undefined *puStack_16c;

  undefined4 uStack_168;

  uint uStack_164;

  int iStack_160;

  undefined1 local_154 [68];

  undefined1 local_110 [68];

  undefined1 auStack_cc [68];

  undefined1 auStack_88 [68];

  undefined1 auStack_44 [4];

  undefined1 auStack_40 [64];

  

  if (*(int *)(param_1 + 0x50) != 0) {

    local_178 = 0;

    local_174 = 0;

    local_170 = 0x3f800000;

    GEO_MatFromQuat(local_154,param_1 + 0x44);

    fVar10 = (float10)rndfloat(0x40c90fdb);

    GEO_MatFromQuat_2(local_110,(float)fVar10);

    (*(code *)PTR_crt_matrix_mul_00580c18)(local_154,local_154,local_110);

    GEO_MatLookAt(auStack_88,param_1 + 0x2c,param_1 + 0x38,&local_178);

    (*(code *)PTR_crt_matrix_mul_00580c18)(auStack_cc,auStack_88,local_154);

    GEO_MatTranspose(auStack_44,auStack_cc);

    (**(code **)(DAT_00656420 + 0x18))(DAT_00656420,auStack_40);

    (**(code **)(DAT_00656430 + 0x10))(DAT_00656430,1);

    (**(code **)(DAT_00656430 + 0xc))(DAT_00656430,*(undefined4 *)(param_1 + 0x58));

    uStack_164 = *(uint *)(param_1 + 0x54) | 0x21104;

    puStack_16c = &DAT_00632a60;

    uStack_168 = 0;

    uVar2 = __ftol();

    iStack_160 = (uVar2 | 0xffffff00) << 0x10;

    (**(code **)(DAT_00656430 + 0x14))(DAT_00656430,&puStack_16c);

    puVar1 = *(undefined4 **)(param_1 + 0x24);

    puVar3 = (undefined4 *)

             (**(code **)(DAT_00656450 + 0x10))(DAT_00656450,*(undefined4 *)(param_1 + 0x18));

    iVar6 = *(int *)(param_1 + 0x18);

    while (iVar6 != 0) {

      puVar4 = puVar3 + 8;

      puVar7 = puVar1 + 8;

      iVar6 = iVar6 + -1;

      puVar8 = puVar1;

      puVar9 = puVar3;

      for (iVar5 = 8; puVar1 = puVar7, puVar3 = puVar4, iVar5 != 0; iVar5 = iVar5 + -1) {

        *puVar9 = *puVar8;

        puVar8 = puVar8 + 1;

        puVar9 = puVar9 + 1;

      }

    }

    (**(code **)(DAT_00656450 + 0x18))(DAT_00656450,0);

    (**(code **)(DAT_00656450 + 0x20))

              (DAT_00656450,*(undefined4 *)(param_1 + 0x1c),*(undefined4 *)(param_1 + 0x20));

  }

  return;

}

/* ===== FUN_004676a0 @ 0x004676A0 ===== */
void FUN_004676a0(void)



{

  undefined4 *puVar1;

  undefined4 *puVar2;

  

  if (DAT_0059da1c != 0) {

    puVar1 = (undefined4 *)(((undefined4 **)DAT_00632a80 == &DAT_00632a80) - 1 & (uint)DAT_00632a80)

    ;

    puVar2 = (undefined4 *)*DAT_00632a80;

    if (puVar1 != (undefined4 *)0x0) {

      while( true ) {

        obj_skinning_eval(puVar1);

        if ((undefined4 **)puVar2 == &DAT_00632a80) break;

        puVar1 = puVar2;

        puVar2 = (undefined4 *)*puVar2;

      }

    }

  }

  return;

}

/* ===== kabuto_ai_main_c15 @ 0x004676E0 ===== */
/* WARNING: Type propagation algorithm not settling */



void kabuto_ai_main_c15(float param_1)



{

  int *piVar1;

  float fVar2;

  undefined4 *puVar3;

  int iVar4;

  undefined1 uVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  undefined4 uVar9;

  float10 fVar10;

  float10 fVar11;

  undefined4 uVar12;

  undefined4 uVar13;

  float fStack_18;

  float fStack_14;

  float fStack_10;

  float fStack_c;

  float afStack_8 [2];

  

  iVar4 = (int)param_1;

  iVar8 = *(int *)((int)param_1 + 0x100);

  if (DAT_00632e74 != 0) {

    return;

  }

  *(undefined1 *)((int)param_1 + 0x208) = 0;

  *(undefined1 *)((int)param_1 + 0x20b) = 0;

  *(undefined1 *)((int)param_1 + 0x20a) = 0;

  *(uint *)((int)param_1 + 0xd8) = *(uint *)((int)param_1 + 0xd8) & 0xfcffffff;

  if (*(int *)((int)param_1 + 0xe4) == 0) {

    if (*(int *)((int)param_1 + 0xe8) == 0) {

      object_change_ospec(param_1,1);

      return;

    }

    *(undefined4 *)((int)param_1 + 0x18c) = 100;

    *(undefined4 *)((int)param_1 + 0xc4) = 0x3f800000;

    *(int *)((int)param_1 + 0x104) = iVar8;

    PhysicsExZeroForce(param_1);

    *(undefined4 *)(*(int *)((int)param_1 + 0x104) + 8) = *(undefined4 *)(DAT_00632ed8 + 0x6b8);

    *(undefined4 *)(*(int *)((int)param_1 + 0x104) + 4) = *(undefined4 *)(DAT_00632ed8 + 0x6b4);

    *(undefined4 *)(*(int *)((int)param_1 + 0x104) + 0x28) = *(undefined4 *)(DAT_00632ed8 + 0x5f8);

    *(undefined4 *)(*(int *)((int)param_1 + 0x104) + 0xc) = *(undefined4 *)(DAT_00632ed8 + 0x604);

    *(undefined4 *)(*(int *)((int)param_1 + 0x104) + 0x30) = *(undefined4 *)(DAT_00632ed8 + 0x608);

    *(undefined4 *)(*(int *)((int)param_1 + 0x104) + 0x38) = 0;

    *(undefined4 *)(*(int *)((int)param_1 + 0x104) + 0x34) = 0;

    *(undefined4 *)(iVar8 + 0x44) = 0;

    *(undefined4 *)(iVar8 + 0x40) = 0;

    *(float *)(iVar8 + 0x48) =

         (*(float *)(*(int *)((int)param_1 + 0x104) + 4) /

         *(float *)(*(int *)((int)param_1 + 0x104) + 8)) * -32.17405;

    *(undefined4 *)((int)param_1 + 0x1a4) = *(undefined4 *)(DAT_00632ed8 + 0x1464);

    *(undefined4 *)((int)param_1 + 0x1a8) = *(undefined4 *)(DAT_00632ed8 + 0x1468);

    *(undefined4 *)((int)param_1 + 0x1ac) = *(undefined4 *)(DAT_00632ed8 + 0x146c);

    *(undefined4 *)((int)param_1 + 0x194) = *(undefined4 *)(DAT_00632ed8 + 0x147c);

    *(undefined4 *)((int)param_1 + 400) = *(undefined4 *)(DAT_00632ed8 + 0x1480);

    iVar6 = object_allocate_type(0x2ed,1);

    *(undefined4 *)(iVar6 + 0x214) = 0;

    *(float *)(iVar6 + 0x210) = param_1;

    *(undefined4 *)(iVar6 + 0x218) = 10;

    *(undefined4 *)(iVar6 + 0x18c) = *(undefined4 *)((int)param_1 + 0x18c);

    *(uint *)(iVar6 + 0xd8) = *(uint *)(iVar6 + 0xd8) | 0x400000;

    *(uint *)(iVar6 + 0x1c8) = *(uint *)(iVar6 + 0x1c8) | 0x24000000;

    *(uint *)(iVar6 + 0xdc) = *(uint *)(iVar6 + 0xdc) | 0x2000000;

    iVar6 = object_allocate_type(0x3fa,1);

    *(float *)(iVar6 + 0x210) = param_1;

    *(undefined4 *)(iVar6 + 0x214) = 0;

    *(undefined4 *)(iVar6 + 0x218) = 10;

    *(undefined4 *)(iVar6 + 0x18c) = *(undefined4 *)((int)param_1 + 0x18c);

    *(uint *)(iVar6 + 0xd8) = *(uint *)(iVar6 + 0xd8) | 0x400000;

    *(uint *)(iVar6 + 0x1c8) = *(uint *)(iVar6 + 0x1c8) | 0x20000000;

    *(uint *)(iVar6 + 0xdc) = *(uint *)(iVar6 + 0xdc) | 0x2000000;

    *(undefined4 *)(iVar6 + 0x14) = 0x3f800000;

    ObjectSetAnim(iVar6,1,0x84,0,0,0);

    *(undefined4 *)(iVar8 + 100) = 3;

    *(undefined4 *)(iVar8 + 0x58) = 0;

    *(undefined4 *)(iVar8 + 0x4c) = 0;

    *(undefined4 *)(iVar8 + 0x5c) = 0;

    *(undefined4 *)(iVar8 + 0x50) = 0;

    *(undefined4 *)(iVar8 + 0x60) = 0x3f800000;

    *(undefined4 *)(iVar8 + 0x54) = 0x3f800000;

    puVar3 = DAT_00632d68;

    if (*(int *)((int)param_1 + 0xe8) == 1) {

      *(undefined4 *)((int)param_1 + 0xe4) = 1;

    }

    else {

      for (; puVar3 != (undefined4 *)0x0; puVar3 = (undefined4 *)*puVar3) {

        if (*(int *)(puVar3[3] + 4) == 0x4bf) {

          *(undefined4 *)(iVar8 + 0x3c) = puVar3[3];

          break;

        }

      }

      *(undefined4 *)((int)param_1 + 0xe4) = 10;

    }

  }

  uVar9 = 2;

  switch(*(undefined4 *)((int)param_1 + 0xe4)) {

  case 1:

    if (*(int *)(DAT_00632a88 + 4) == 0) break;

    *(undefined4 *)((int)param_1 + 0xe4) = 2;

    goto LAB_004679d8;

  case 2:

    ai_move_force_goal(param_1,DAT_00632a88 + 0xa0);

    ai_goal_process(param_1);

    uVar9 = 0x71;

    if (*(int *)((int)param_1 + 0x10) == 0x71) {

      iVar8 = AddHud__4cHudP8cHudIcon_4

                        (*(undefined4 *)(*(int *)(*(int *)((int)param_1 + 8) + 0x1cc) + 0x28),

                         *(undefined4 *)((int)param_1 + 0x18));

      iVar6 = AddHud__4cHudP8cHudIcon_4

                        (*(undefined4 *)

                          (*(int *)(*(int *)((int)param_1 + 8) + 8 +

                                   *(int *)((int)param_1 + 0x10) * 4) + 0x28),

                         *(undefined4 *)((int)param_1 + 0x14));

      if ((0xa9f < iVar6) && (iVar8 < 0xaa0)) {

        playerobj_eval_refpt(param_1,0xffffffff,&fStack_c);

        fVar2 = *(float *)(DAT_00632ed8 + 0x13f0);

        fVar11 = (float10)distancesq2d__FP3P3DT0(&fStack_c,DAT_00632a88 + 0xa0);

        if (fVar11 < (float10)fVar2 * (float10)fVar2) {

          obj_damage_apply(0x14,*(undefined4 *)(DAT_00632ed8 + 0x13e8),DAT_00632a88,param_1,0,0);

          fStack_18 = -*(float *)((int)param_1 + 0x29c);

          fStack_14 = -*(float *)((int)param_1 + 0x2ac);

          fStack_10 = 0.0;

          normalize__FPfN20(&fStack_18,&fStack_14,&fStack_10);

          *(float *)(DAT_00632a88 + 0x128) =

               *(float *)(DAT_00632ed8 + 0x13f4) * fStack_18 + *(float *)(DAT_00632a88 + 0x128);

          *(float *)(DAT_00632a88 + 300) =

               *(float *)(DAT_00632ed8 + 0x13f4) * fStack_14 + *(float *)(DAT_00632a88 + 300);

          *(float *)(DAT_00632a88 + 0x130) =

               *(float *)(DAT_00632ed8 + 0x13f8) + *(float *)(DAT_00632a88 + 0x130);

          *(uint *)((int)param_1 + 0xe0) = *(uint *)((int)param_1 + 0xe0) | 2;

        }

      }

      if ((*(byte *)((int)param_1 + 0x30) & 2) != 0) {

        if ((*(byte *)((int)param_1 + 0xe0) & 2) == 0) {

          if ((*(int *)((int)param_1 + 0x10) != 2) &&

             (*(int *)(*(int *)((int)param_1 + 8) + 0x10) != 0)) {

            ObjectSetAnim(param_1,2,0x21,1,

                          *(float *)(DAT_00632ed8 + 0x9d4) * *(float *)((int)param_1 + 0xc4),

                          0x3e2aaaab);

            sound_stop_obj(0x6dc,param_1);

            sound_stop_obj(0x6dd,param_1);

          }

          *(uint *)((int)param_1 + 0xe0) = *(uint *)((int)param_1 + 0xe0) & 0xfffffffd;

        }

        else {

          ai_clear_move_goal(param_1);

          *(undefined4 *)((int)param_1 + 0x128) = 0;

          *(undefined4 *)((int)param_1 + 300) = 0;

          *(undefined4 *)((int)param_1 + 0x130) = 0;

          iVar8 = crt_rand_scaled(100);

          if (iVar8 < 0x32) {

            uVar9 = 0x467;

          }

          else {

            uVar9 = 0x468;

          }

          sound_play_obj(uVar9,param_1);

          iVar8 = crt_rand_scaled(100);

          if (iVar8 < 0x19) {

            iVar8 = 0xb8;

          }

          else if (iVar8 < 0x32) {

            iVar8 = 0xb9;

          }

          else {

            iVar8 = (0x4a < iVar8) + 0xba;

          }

          if ((*(int *)((int)param_1 + 0x10) != iVar8) &&

             (*(int *)(*(int *)((int)param_1 + 8) + 8 + iVar8 * 4) != 0)) {

            ObjectSetAnim(param_1,iVar8,0x20,0,*(float *)((int)param_1 + 0xc4) * 0.0,0x3e2aaaab);

            sound_stop_obj(0x6dc,param_1);

            sound_stop_obj(0x6dd,param_1);

          }

          *(undefined4 *)((int)param_1 + 0xe4) = 3;

          *(uint *)((int)param_1 + 0xe0) = *(uint *)((int)param_1 + 0xe0) & 0xfffffffd;

        }

      }

      break;

    }

    playerobj_eval_refpt(param_1,0xffffffff,&fStack_c);

    fVar2 = *(float *)(DAT_00632ed8 + 0x13ec);

    fVar11 = (float10)distancesq2d__FP3P3DT0(&fStack_c,DAT_00632a88 + 0xa0);

    if ((float10)fVar2 * (float10)fVar2 <= fVar11) break;

    iVar8 = crt_rand_scaled(100);

    if (iVar8 < 0x32) {

      uVar12 = 0x402;

    }

    else {

      uVar12 = 0x403;

    }

    sound_play_obj(uVar12,param_1);

    if (*(int *)((int)param_1 + 0x10) == 0x71) break;

    iVar8 = *(int *)(*(int *)((int)param_1 + 8) + 0x1cc);

    goto LAB_004695c8;

  case 3:

    if ((*(byte *)((int)param_1 + 0x30) & 2) != 0) {

      if ((*(int *)((int)param_1 + 0x10) != 2) && (*(int *)(*(int *)((int)param_1 + 8) + 0x10) != 0)

         ) {

        ObjectSetAnim(param_1,2,0x21,1,

                      *(float *)(DAT_00632ed8 + 0x9d4) * *(float *)((int)param_1 + 0xc4),0x3e2aaaab)

        ;

        sound_stop_obj(0x6dc,param_1);

        sound_stop_obj(0x6dd,param_1);

      }

      *(undefined4 *)((int)param_1 + 0xe4) = 2;

    }

    break;

  case 4:

    if ((*(byte *)((int)param_1 + 0x30) & 2) != 0) {

      voice_event_trigger(param_1);

      *(undefined4 *)((int)param_1 + 0xe4) = 5;

    }

    break;

  case 10:

    if (*(int *)(DAT_00632a88 + 4) != 0) {

      *(undefined4 *)((int)param_1 + 0xe4) = 0xb;

    }

    break;

  case 0xb:

    if (*(int *)((int)param_1 + 0xf8) != 1) {

      uVar9 = rndintrange(*(undefined4 *)(DAT_00632ed8 + 0x13fc),

                          *(undefined4 *)(DAT_00632ed8 + 0x1400));

      *(undefined4 *)((int)param_1 + 0xf4) = uVar9;

    }

    *(undefined4 *)((int)param_1 + 0xf8) = 1;

    loglauncher_process(param_1);

    break;

  case 0xc:

    iVar6 = AddHud__4cHudP8cHudIcon_4

                      (*(undefined4 *)

                        (*(int *)(*(int *)((int)param_1 + 8) + 8 + *(int *)((int)param_1 + 0x10) * 4

                                 ) + 0x28),*(undefined4 *)((int)param_1 + 0x14));

    iVar8 = *(int *)((int)param_1 + 0x10);

    if (iVar8 == 0xfa) {

LAB_004680a8:

      fVar11 = (float10)FUN_00518b70(param_1,0);

      fVar11 = (float10)*(float *)((int)param_1 + 0xf0) - fVar11;

      *(float *)((int)param_1 + 0xf0) = (float)fVar11;

      if ((float10)0.0 < fVar11) {

        iVar8 = *(int *)((int)param_1 + 0x100);

        iVar6 = *(int *)((int)param_1 + 0x274) + 0xa0;

        FUN_0050a610((int)param_1 + 0xa0,iVar6);

        fVar11 = (float10)powf();

        trajectory_calculate

                  ((int)param_1 + 0x128,(int)param_1 + 0xa0,iVar6,iVar8 + 0x40,

                   (float)(fVar11 * (float10)0.1));

      }

      if (((**(byte **)((int)param_1 + 0x104) & 0x2c) != 0) ||

         ((*(int *)((int)param_1 + 0x220) != 0 && (*(int *)((int)param_1 + 0x220) != DAT_00632a88)))

         ) {

        line_damage_with_slope

                  (4,param_1,0,(int)param_1 + 0xa0,*(undefined4 *)(DAT_00632ed8 + 0x1444),

                   *(undefined4 *)(DAT_00632ed8 + 0x1448),*(undefined4 *)(DAT_00632ed8 + 0x144c),

                   *(undefined4 *)(DAT_00632ed8 + 0x1450),*(undefined4 *)((int)param_1 + 0x18c));

        get_free_world_ripple__Fv_2

                  ((int)param_1 + 0xa0,*(undefined4 *)(DAT_00632ed8 + 0x1454),

                   *(undefined4 *)(DAT_00632ed8 + 0x1458),*(undefined4 *)(DAT_00632ed8 + 0x145c),

                   *(undefined4 *)(DAT_00632ed8 + 0x1460));

        *(undefined4 *)((int)param_1 + 0x274) = 0;

        *(undefined4 *)((int)param_1 + 0x128) = 0;

        *(undefined4 *)((int)param_1 + 300) = 0;

        *(undefined4 *)((int)param_1 + 0x130) = 0;

        *(undefined4 *)((int)param_1 + 0xf0) = 0x40a00000;

        *(undefined4 *)((int)param_1 + 0xe4) = 0xf;

      }

      break;

    }

    if (iVar8 == 0xa8) {

      fVar11 = (float10)FUN_00518b70(param_1,0);

      fVar11 = (float10)*(float *)((int)param_1 + 0xf0) - fVar11;

      *(float *)((int)param_1 + 0xf0) = (float)fVar11;

      if ((float10)0.0 < fVar11) {

        iVar8 = *(int *)((int)param_1 + 0x100);

        iVar6 = *(int *)((int)param_1 + 0x274) + 0xa0;

        FUN_0050a610((int)param_1 + 0xa0,iVar6);

        fVar11 = (float10)powf();

        trajectory_calculate

                  ((int)param_1 + 0x128,(int)param_1 + 0xa0,iVar6,iVar8 + 0x40,

                   (float)(fVar11 * (float10)0.1));

      }

      if (((*(float *)((int)param_1 + 0x130) < 0.0 != (*(float *)((int)param_1 + 0x130) == 0.0)) &&

          (*(int *)((int)param_1 + 0x10) != 0xfa)) &&

         (*(int *)(*(int *)((int)param_1 + 8) + 0x3f0) != 0)) {

        ObjectSetAnim(param_1,0xfa,0x21,0,*(float *)((int)param_1 + 0xc4) * 0.0,0x3e2aaaab);

        sound_stop_obj(0x6dc,param_1);

        sound_stop_obj(0x6dd,param_1);

      }

      goto LAB_004680a8;

    }

    if (iVar8 == 0xa6) {

      iVar7 = 0x960;

    }

    else {

      iVar7 = 0x780;

      if (iVar8 != 0xa7) {

        iVar7 = (int)param_1;

      }

    }

    if (iVar7 <= iVar6) {

      iVar8 = *(int *)((int)param_1 + 0x100);

      iVar6 = *(int *)((int)param_1 + 0x274) + 0xa0;

      FUN_0050a610((int)param_1 + 0xa0,iVar6);

      fVar11 = (float10)powf();

      trajectory_calculate

                ((int)param_1 + 0x128,(int)param_1 + 0xa0,iVar6,iVar8 + 0x40,

                 (float)(fVar11 * (float10)0.1));

      *(float *)((int)param_1 + 0xf0) = (float)(fVar11 * (float10)0.1) * 0.75;

      if (((*(float *)((int)param_1 + 0x130) < 0.0 != (*(float *)((int)param_1 + 0x130) == 0.0)) &&

          (*(int *)((int)param_1 + 0x10) != 0xfa)) &&

         (*(int *)(*(int *)((int)param_1 + 8) + 0x3f0) != 0)) {

        ObjectSetAnim(param_1,0xfa,0x21,0,*(float *)((int)param_1 + 0xc4) * 0.0,0x3e2aaaab);

        sound_stop_obj(0x6dc,param_1);

        sound_stop_obj(0x6dd,param_1);

      }

    }

    if ((((*(byte *)((int)param_1 + 0x30) & 2) == 0) || (*(int *)((int)param_1 + 0x10) == 0xa8)) ||

       (*(int *)(*(int *)((int)param_1 + 8) + 0x2a8) == 0)) break;

    param_1 = *(float *)((int)param_1 + 0xc4) * 0.0;

    uVar13 = 0;

    uVar12 = 0x21;

    uVar9 = 0xa8;

    goto LAB_00469149;

  case 0xd:

    if ((*(byte *)((int)param_1 + 0x30) & 2) == 0) break;

    goto LAB_004683c4;

  case 0xe:

    goto LAB_004683d5;

  case 0xf:

    fVar11 = (float10)dirfcalcp3d__FP3P3DT0((int)param_1 + 0xa0,DAT_00632a88 + 0xa0);

    fVar10 = (float10)playerobj_turn((float)fVar11,*(undefined4 *)((int)param_1 + 200));

    fVar2 = (float)ABS(fVar10);

    if (ABS(fVar10) == (float10)0.0) {

      fVar2 = 0.0;

    }

    else {

      *(uint *)((int)param_1 + 0xd8) = *(uint *)((int)param_1 + 0xd8) | 0x1000000;

      *(float *)((int)param_1 + 0x158) = (float)fVar11;

      uVar5 = __ftol();

      *(undefined1 *)((int)param_1 + 0x208) = uVar5;

    }

    if (fVar2 < 10.0) {

      iVar8 = crt_rand_scaled(100);

      if (iVar8 < 0x32) {

        uVar9 = 0x467;

      }

      else {

        uVar9 = 0x468;

      }

      sound_play_obj(uVar9,param_1);

      iVar8 = crt_rand_scaled(100);

      if (iVar8 < 0x19) {

        iVar8 = 0xb8;

      }

      else if (iVar8 < 0x32) {

        iVar8 = 0xb9;

      }

      else {

        iVar8 = (0x4a < iVar8) + 0xba;

      }

      if ((*(int *)((int)param_1 + 0x10) != iVar8) &&

         (*(int *)(*(int *)((int)param_1 + 8) + 8 + iVar8 * 4) != 0)) {

        ObjectSetAnim(param_1,iVar8,0x20,0,*(float *)((int)param_1 + 0xc4) * 0.0,0x3e2aaaab);

        sound_stop_obj(0x6dc,param_1);

        sound_stop_obj(0x6dd,param_1);

      }

      *(undefined4 *)((int)param_1 + 0xe4) = 0xd;

      break;

    }

    fVar11 = (float10)FUN_00518b70(param_1,0);

    fVar11 = (float10)*(float *)((int)param_1 + 0xf0) - fVar11;

    *(float *)((int)param_1 + 0xf0) = (float)fVar11;

    if (fVar11 < (float10)0.0 == (fVar11 == (float10)0.0)) {

      iVar6 = *(int *)((int)param_1 + 0x10);

      goto LAB_00468372;

    }

LAB_004683c4:

    piVar1 = (int *)((int)param_1 + 0xf4);

    *piVar1 = *piVar1 + -1;

    if ((*piVar1 == 0) || ((*(byte *)((int)param_1 + 0xe0) & 1) != 0)) {

      if ((*(uint *)((int)param_1 + 0xe0) & 1) == 0) {

        if (*(float *)((int)param_1 + 0x278) < *(float *)(DAT_00632ed8 + 0x159c)) {

          *(undefined4 *)((int)param_1 + 0xe4) = 0x14;

          break;

        }

      }

      else {

        *(uint *)((int)param_1 + 0xe0) = *(uint *)((int)param_1 + 0xe0) & 0xfffffffe;

      }

      *(undefined4 *)((int)param_1 + 0xe4) = 0x1e;

    }

    else {

LAB_004683d5:

      loglauncher_process(param_1);

    }

    break;

  case 0x14:

    puVar3 = DAT_00632d68;

    iVar8 = (int)param_1;

    if (*(int *)((int)param_1 + 0x274) == 0) {

      while ((puVar3 != (undefined4 *)0x0 &&

             ((iVar8 = puVar3[3], *(int *)(iVar8 + 4) != 0x2a7 ||

              (*(int *)(iVar8 + 0xe8) != *(int *)(DAT_00632ed8 + 0x1410)))))) {

        puVar3 = (undefined4 *)*puVar3;

      }

      *(int *)((int)param_1 + 0x274) = iVar8;

    }

    *(undefined4 *)((int)param_1 + 0xf8) = 2;

    fVar11 = (float10)dirfcalcp3d__FP3P3DT0

                                ((int)param_1 + 0xa0,*(int *)((int)param_1 + 0x274) + 0xa0);

    fVar11 = (float10)FUN_00469950(param_1,(float)fVar11);

    if ((float10)5.0 <= fVar11) {

      kabutoai_change_anim__FP6OBJECTii4SDKYfi

                (param_1,0x26,1,3,*(undefined4 *)(DAT_00632ed8 + 0x15dc),0);

    }

    else {

      fVar11 = (float10)distancesq2d__FP3P3DT0

                                  ((int)param_1 + 0xa0,*(int *)((int)param_1 + 0x274) + 0xa0);

      if ((float10)*(float *)(DAT_00632ed8 + 0x11c0) * (float10)*(float *)(DAT_00632ed8 + 0x11c0) <=

          fVar11) {

        kabutoai_change_anim__FP6OBJECTii4SDKYfi(param_1,0xa7,0,0,0,0);

      }

      else if ((*(int *)((int)param_1 + 0x10) != 0xa6) &&

              (*(int *)(*(int *)((int)param_1 + 8) + 0x2a0) != 0)) {

        ObjectSetAnim(param_1,0xa6,0x20,0,*(float *)((int)param_1 + 0xc4) * 0.0,0x3e2aaaab);

        sound_stop_obj(0x6dc,param_1);

        sound_stop_obj(0x6dd,param_1);

      }

      sound_play_obj(0x442,param_1);

      FUN_004698f0(param_1,*(int *)((int)param_1 + 0x274) + 0xa0);

      uVar9 = rndintrange(*(undefined4 *)(DAT_00632ed8 + 0x1408),

                          *(undefined4 *)(DAT_00632ed8 + 0x140c));

      *(undefined4 *)((int)param_1 + 0xf4) = uVar9;

      *(undefined4 *)((int)param_1 + 0xe4) = 0x15;

    }

    break;

  case 0x15:

    iVar8 = *(int *)((int)param_1 + 0x10);

    if (iVar8 == 0xa6) {

      iVar6 = 0x960;

    }

    else {

      iVar6 = 0x780;

      if (iVar8 != 0xa7) {

        iVar6 = (int)param_1;

      }

    }

    if (iVar8 == 0xa8) {

      if ((**(byte **)((int)param_1 + 0x104) & 0xc) != 0) {

        *(undefined4 *)((int)param_1 + 0x128) = 0;

        *(undefined4 *)((int)param_1 + 300) = 0;

        *(undefined4 *)((int)param_1 + 0x130) = 0;

        iVar8 = *(int *)((int)param_1 + 0x104);

        *(undefined4 *)(iVar8 + 0x18) = 0;

        *(undefined4 *)(iVar8 + 0x1c) = 0;

        *(undefined4 *)(iVar8 + 0x20) = 0;

        iVar8 = *(int *)((int)param_1 + 0x274);

        object_set_location(param_1,*(undefined4 *)(iVar8 + 0xa0),*(undefined4 *)(iVar8 + 0xa4),

                            *(undefined4 *)(iVar8 + 0xa8));

        if ((*(int *)((int)param_1 + 0x10) != 0x9b) &&

           (*(int *)(*(int *)((int)param_1 + 8) + 0x274) != 0)) {

          ObjectSetAnim(param_1,0x9b,0x20,0,*(float *)((int)param_1 + 0xc4) * 0.0,0x3e2aaaab);

          sound_stop_obj(0x6dc,param_1);

          sound_stop_obj(0x6dd,param_1);

        }

        *(undefined4 *)((int)param_1 + 0xe4) = 0x1d;

        sound_play_obj(0x444,param_1);

      }

    }

    else {

      if (((*(byte *)((int)param_1 + 0x30) & 2) != 0) &&

         (*(int *)(*(int *)((int)param_1 + 8) + 0x2a8) != 0)) {

        ObjectSetAnim(param_1,0xa8,0x21,0,*(float *)((int)param_1 + 0xc4) * 0.0,0x3e2aaaab);

        sound_stop_obj(0x6dc,param_1);

        sound_stop_obj(0x6dd,param_1);

      }

      iVar8 = AddHud__4cHudP8cHudIcon_4

                        (*(undefined4 *)

                          (*(int *)(*(int *)((int)param_1 + 8) + 8 +

                                   *(int *)((int)param_1 + 0x10) * 4) + 0x28),

                         *(undefined4 *)((int)param_1 + 0x14));

      if (iVar6 <= iVar8) {

        iVar8 = *(int *)((int)param_1 + 0x100);

        iVar6 = *(int *)((int)param_1 + 0x274) + 0xa0;

        FUN_0050a610((int)param_1 + 0xa0,iVar6);

        fVar11 = (float10)powf();

        trajectory_calculate

                  ((int)param_1 + 0x128,(int)param_1 + 0xa0,iVar6,iVar8 + 0x40,

                   (float)(fVar11 * (float10)0.1));

      }

    }

    break;

  case 0x16:

    iVar6 = AddHud__4cHudP8cHudIcon_4

                      (*(undefined4 *)

                        (*(int *)(*(int *)((int)param_1 + 8) + 8 + *(int *)((int)param_1 + 0x10) * 4

                                 ) + 0x28),*(undefined4 *)((int)param_1 + 0x18));

    iVar7 = AddHud__4cHudP8cHudIcon_4

                      (*(undefined4 *)

                        (*(int *)(*(int *)((int)param_1 + 8) + 8 + *(int *)((int)param_1 + 0x10) * 4

                                 ) + 0x28),*(undefined4 *)((int)param_1 + 0x14));

    if ((799 < iVar7) && (iVar6 < 800)) {

      fVar11 = (float10)FUN_0045b610(param_1,*(undefined4 *)(*(int *)(iVar8 + 0x3c) + 0x274),

                                     0x40400000);

      *(float *)(iVar8 + 0x68) = (float)fVar11;

      reaper_lock_short_5(param_1,*(undefined4 *)(*(int *)(iVar8 + 0x3c) + 0x274),(float)fVar11,3);

      iVar8 = *(int *)(*(int *)(iVar8 + 0x3c) + 0x274);

      *(int *)((int)param_1 + 0x274) = iVar8;

      *(uint *)(iVar8 + 0xd8) = *(uint *)(iVar8 + 0xd8) & 0xffffffef;

    }

    if ((*(byte *)((int)param_1 + 0x30) & 2) != 0) {

      *(undefined4 *)((int)param_1 + 0xe4) = 0x17;

    }

    break;

  case 0x17:

    if (*(int *)((int)param_1 + 0x10) == 0x5f) {

      fVar11 = (float10)dirfcalcp3d__FP3P3DT0((int)param_1 + 0xa0,DAT_00632a88 + 0xa0);

      fVar10 = (float10)playerobj_turn((float)fVar11,*(undefined4 *)((int)param_1 + 200));

      if (ABS(fVar10) != (float10)0.0) {

        *(uint *)((int)param_1 + 0xd8) = *(uint *)((int)param_1 + 0xd8) | 0x1000000;

        *(float *)((int)param_1 + 0x158) = (float)fVar11;

        uVar5 = __ftol();

        *(undefined1 *)((int)param_1 + 0x208) = uVar5;

      }

      iVar6 = AddHud__4cHudP8cHudIcon_4

                        (*(undefined4 *)

                          (*(int *)(*(int *)((int)param_1 + 8) + 8 +

                                   *(int *)((int)param_1 + 0x10) * 4) + 0x28),

                         *(undefined4 *)((int)param_1 + 0x18));

      iVar7 = AddHud__4cHudP8cHudIcon_4

                        (*(undefined4 *)

                          (*(int *)(*(int *)((int)param_1 + 8) + 8 +

                                   *(int *)((int)param_1 + 0x10) * 4) + 0x28),

                         *(undefined4 *)((int)param_1 + 0x14));

      if ((0xbdf < iVar7) && (iVar6 < 0xbe0)) {

        *(int *)((int)param_1 + 0xf4) = *(int *)((int)param_1 + 0xf4) + -1;

        reaper_spawn_ospec_2

                  (param_1,*(undefined4 *)((int)param_1 + 0x274),DAT_00632a88,

                   *(undefined4 *)(DAT_00632ed8 + 0x1660),*(undefined4 *)(iVar8 + 0x68));

        *(undefined4 *)((int)param_1 + 0x274) = 0;

      }

      if ((*(byte *)((int)param_1 + 0x30) & 2) != 0) {

        if ((*(int *)((int)param_1 + 0xf4) == 0) ||

           (*(float *)(DAT_00632ed8 + 0x159c) <= *(float *)((int)param_1 + 0x278))) {

          *(uint *)((int)param_1 + 0xe0) = *(uint *)((int)param_1 + 0xe0) | 1;

          *(undefined4 *)((int)param_1 + 0xe4) = 0xb;

        }

        else {

          *(undefined4 *)((int)param_1 + 0xe4) = 0x19;

        }

      }

      break;

    }

    fVar11 = (float10)dirfcalcp3d__FP3P3DT0((int)param_1 + 0xa0,DAT_00632a88 + 0xa0);

    fVar10 = (float10)playerobj_turn((float)fVar11,*(undefined4 *)((int)param_1 + 200));

    fVar2 = (float)ABS(fVar10);

    if (ABS(fVar10) == (float10)0.0) {

      fVar2 = 0.0;

    }

    else {

      *(uint *)((int)param_1 + 0xd8) = *(uint *)((int)param_1 + 0xd8) | 0x1000000;

      *(float *)((int)param_1 + 0x158) = (float)fVar11;

      uVar5 = __ftol();

      *(undefined1 *)((int)param_1 + 0x208) = uVar5;

    }

    if (fVar2 < 5.0) goto LAB_004695b6;

    goto LAB_00468e13;

  case 0x18:

    if ((*(byte *)((int)param_1 + 0x30) & 2) != 0) {

      *(undefined4 *)((int)param_1 + 0xe4) = 0x19;

    }

    break;

  case 0x19:

    fVar11 = (float10)dirfcalcp3d__FP3P3DT0((int)param_1 + 0xa0,*(int *)(iVar8 + 0x3c) + 0xa0);

    fVar10 = (float10)playerobj_turn((float)fVar11,*(undefined4 *)((int)param_1 + 200));

    fVar2 = (float)ABS(fVar10);

    if (ABS(fVar10) == (float10)0.0) {

      fVar2 = 0.0;

    }

    else {

      *(uint *)((int)param_1 + 0xd8) = *(uint *)((int)param_1 + 0xd8) | 0x1000000;

      *(float *)((int)param_1 + 0x158) = (float)fVar11;

      uVar5 = __ftol();

      *(undefined1 *)((int)param_1 + 0x208) = uVar5;

    }

    iVar6 = *(int *)((int)param_1 + 0x10);

    if (fVar2 < 5.0) {

LAB_00468af7:

      if (iVar6 != 1) {

        iVar8 = *(int *)(*(int *)((int)param_1 + 8) + 0xc);

LAB_00468b04:

        if (iVar8 != 0) {

          ObjectSetAnim(param_1,1,0x21,0,*(float *)((int)param_1 + 0xc4) * 0.0,0x3e2aaaab);

          sound_stop_obj(0x6dc,param_1);

          sound_stop_obj(0x6dd,param_1);

        }

      }

      goto LAB_00468b40;

    }

    goto LAB_00468372;

  case 0x1a:

    fVar11 = (float10)dirfcalcp3d__FP3P3DT0((int)param_1 + 0xa0,*(int *)(iVar8 + 0x3c) + 0xa0);

    fVar10 = (float10)playerobj_turn((float)fVar11,*(undefined4 *)((int)param_1 + 200));

    fVar2 = (float)ABS(fVar10);

    if (ABS(fVar10) == (float10)0.0) {

      fVar2 = 0.0;

    }

    else {

      *(uint *)((int)param_1 + 0xd8) = *(uint *)((int)param_1 + 0xd8) | 0x1000000;

      *(float *)((int)param_1 + 0x158) = (float)fVar11;

      uVar5 = __ftol();

      *(undefined1 *)((int)param_1 + 0x208) = uVar5;

    }

    iVar6 = *(int *)((int)param_1 + 0x10);

    if (fVar2 < 5.0) {

      if ((iVar6 != 0x71) && (*(int *)(*(int *)((int)param_1 + 8) + 0x1cc) != 0)) {

        ObjectSetAnim(param_1,0x71,0x20,0,*(float *)((int)param_1 + 0xc4) * 0.0,0x3e2aaaab);

        sound_stop_obj(0x6dc,param_1);

        sound_stop_obj(0x6dd,param_1);

      }

      iVar6 = AddHud__4cHudP8cHudIcon_4

                        (*(undefined4 *)

                          (*(int *)(*(int *)((int)param_1 + 8) + 8 +

                                   *(int *)((int)param_1 + 0x10) * 4) + 0x28),

                         *(undefined4 *)((int)param_1 + 0x18));

      iVar7 = AddHud__4cHudP8cHudIcon_4

                        (*(undefined4 *)

                          (*(int *)(*(int *)((int)param_1 + 8) + 8 +

                                   *(int *)((int)param_1 + 0x10) * 4) + 0x28),

                         *(undefined4 *)((int)param_1 + 0x14));

      if ((0xa9f < iVar7) && (iVar6 < 0xaa0)) {

        obj_damage_apply(4,0,*(undefined4 *)(iVar8 + 0x3c),param_1,0,0);

      }

      if ((*(byte *)((int)param_1 + 0x30) & 2) == 0) break;

      iVar6 = *(int *)((int)param_1 + 0x10);

      *(uint *)((int)param_1 + 0xe0) = *(uint *)((int)param_1 + 0xe0) | 4;

      goto LAB_00468af7;

    }

LAB_00468372:

    if (iVar6 == 0x26) break;

    iVar8 = *(int *)(*(int *)((int)param_1 + 8) + 0xa0);

    param_1 = *(float *)(DAT_00632ed8 + 0x15dc);

    goto LAB_00468394;

  case 0x1b:

    fVar11 = (float10)dirfcalcp3d__FP3P3DT0((int)param_1 + 0xa0,*(int *)(iVar8 + 0x3c) + 0xa0);

    fVar10 = (float10)playerobj_turn((float)fVar11,*(undefined4 *)((int)param_1 + 200));

    fVar2 = (float)ABS(fVar10);

    if (ABS(fVar10) == (float10)0.0) {

      fVar2 = 0.0;

    }

    else {

      *(float *)((int)param_1 + 0x158) = (float)fVar11;

      *(uint *)((int)param_1 + 0xd8) = *(uint *)((int)param_1 + 0xd8) | 0x1000000;

      uVar5 = __ftol();

      *(undefined1 *)((int)param_1 + 0x208) = uVar5;

    }

    if (fVar2 < 5.0) {

      if (*(int *)(*(int *)(iVar8 + 0x3c) + 0xe4) == 1) {

        sound_play_obj(0x43c,param_1);

        if ((*(int *)((int)param_1 + 0x10) != 0x2b) &&

           (*(int *)(*(int *)((int)param_1 + 8) + 0xb4) != 0)) {

          ObjectSetAnim(param_1,0x2b,0x20,0,*(float *)((int)param_1 + 0xc4) * 0.0,0x3e2aaaab);

          sound_stop_obj(0x6dc,param_1);

          sound_stop_obj(0x6dd,param_1);

        }

        *(undefined4 *)((int)param_1 + 0xe4) = 0x16;

      }

      break;

    }

    goto LAB_00468e13;

  case 0x1c:

    fVar11 = (float10)dirfcalcp3d__FP3P3DT0((int)param_1 + 0xa0,DAT_00632a88 + 0xa0);

    fVar10 = (float10)playerobj_turn((float)fVar11,*(undefined4 *)((int)param_1 + 200));

    fVar2 = (float)ABS(fVar10);

    if (ABS(fVar10) == (float10)0.0) {

      fVar2 = 0.0;

    }

    else {

      *(float *)((int)param_1 + 0x158) = (float)fVar11;

      *(uint *)((int)param_1 + 0xd8) = *(uint *)((int)param_1 + 0xd8) | 0x1000000;

      uVar5 = __ftol();

      *(undefined1 *)((int)param_1 + 0x208) = uVar5;

    }

    if (fVar2 < 10.0) {

      iVar8 = crt_rand_scaled(100);

      if (iVar8 < 0x32) {

        uVar9 = 0x467;

      }

      else {

        uVar9 = 0x468;

      }

      sound_play_obj(uVar9,param_1);

      iVar8 = crt_rand_scaled(100);

      if (iVar8 < 0x19) {

        iVar8 = 0xb8;

      }

      else if (iVar8 < 0x32) {

        iVar8 = 0xb9;

      }

      else {

        iVar8 = (0x4a < iVar8) + 0xba;

      }

      if ((*(int *)((int)param_1 + 0x10) != iVar8) &&

         (*(int *)(*(int *)((int)param_1 + 8) + 8 + iVar8 * 4) != 0)) {

        ObjectSetAnim(param_1,iVar8,0x20,0,*(float *)((int)param_1 + 0xc4) * 0.0,0x3e2aaaab);

        sound_stop_obj(0x6dc,param_1);

        sound_stop_obj(0x6dd,param_1);

      }

      *(undefined4 *)((int)param_1 + 0xe4) = 0x18;

      break;

    }

    fVar11 = (float10)FUN_00518b70(param_1,0);

    fVar11 = (float10)*(float *)((int)param_1 + 0xf0) - fVar11;

    *(float *)((int)param_1 + 0xf0) = (float)fVar11;

    if (fVar11 < (float10)0.0 != (fVar11 == (float10)0.0)) {

      *(undefined4 *)((int)param_1 + 0xe4) = 0x19;

      break;

    }

LAB_00468e13:

    if (*(int *)((int)param_1 + 0x10) != 0x26) {

      iVar8 = *(int *)(*(int *)((int)param_1 + 8) + 0xa0);

      param_1 = *(float *)(DAT_00632ed8 + 0x15dc);

LAB_00468394:

      if (iVar8 != 0) {

        param_1 = param_1 * *(float *)(iVar4 + 0xc4);

        uVar13 = 3;

        uVar12 = 0x21;

        uVar9 = 0x26;

LAB_00469149:

        ObjectSetAnim(iVar4,uVar9,uVar12,uVar13,param_1,0x3e2aaaab);

        sound_stop_obj(0x6dc,iVar4);

        sound_stop_obj(0x6dd,iVar4);

      }

    }

    break;

  case 0x1d:

    if ((*(byte *)((int)param_1 + 0x30) & 2) == 0) break;

    if ((*(byte *)((int)param_1 + 0xe0) & 4) == 0) {

      *(undefined4 *)((int)param_1 + 0xe4) = 0x1a;

      break;

    }

    if (*(int *)((int)param_1 + 0x10) != 1) {

      iVar8 = *(int *)(*(int *)((int)param_1 + 8) + 0xc);

      goto LAB_00468b04;

    }

LAB_00468b40:

    *(undefined4 *)((int)param_1 + 0xe4) = 0x1b;

    break;

  case 0x1e:

    if (*(int *)((int)param_1 + 0xf8) != 3) {

      uVar12 = rndintrange(*(undefined4 *)(DAT_00632ed8 + 0x1414),

                           *(undefined4 *)(DAT_00632ed8 + 0x166c));

      *(undefined4 *)((int)param_1 + 0xf4) = uVar12;

    }

    *(undefined4 *)((int)param_1 + 0xf8) = 3;

    *(undefined4 *)((int)param_1 + 0xe4) = 0x1f;

LAB_004679d8:

    if ((*(int *)((int)param_1 + 0x10) == 2) || (*(int *)(*(int *)((int)param_1 + 8) + 0x10) == 0))

    break;

    param_1 = *(float *)(DAT_00632ed8 + 0x9d4) * *(float *)((int)param_1 + 0xc4);

    uVar13 = 1;

    uVar12 = 0x21;

    goto LAB_00469149;

  case 0x1f:

    ai_move_force_goal(param_1,DAT_00632a88 + 0xa0);

    ai_goal_process(param_1);

    uVar9 = 0xc5;

    if (*(int *)((int)param_1 + 0x10) != 0xc4) {

      if (*(int *)((int)param_1 + 0x10) != 0xc5) {

        playerobj_eval_refpt(param_1,0xffffffff,&fStack_c);

        fVar2 = *(float *)(DAT_00632ed8 + 0x142c);

        fVar11 = (float10)distancesq2d__FP3P3DT0(&fStack_c,DAT_00632a88 + 0xa0);

        if ((float10)fVar2 * (float10)fVar2 <= fVar11) break;

        iVar8 = crt_rand_scaled(100);

        if (iVar8 < 0x32) {

          sound_play_obj(0x43c,param_1);

          if ((*(int *)((int)param_1 + 0x10) == 0xc4) ||

             (*(int *)(*(int *)((int)param_1 + 8) + 0x318) == 0)) break;

          param_1 = *(float *)((int)param_1 + 0xc4) * 0.0;

          uVar13 = 0;

          uVar12 = 0x20;

          uVar9 = 0xc4;

        }

        else {

          sound_play_obj(0x465,param_1);

          if ((*(int *)((int)param_1 + 0x10) == 0xc5) ||

             (*(int *)(*(int *)((int)param_1 + 8) + 0x31c) == 0)) break;

          param_1 = *(float *)((int)param_1 + 0xc4) * 0.0;

          uVar13 = 0;

          uVar12 = 0x20;

        }

        goto LAB_00469149;

      }

      iVar6 = AddHud__4cHudP8cHudIcon_4

                        (*(undefined4 *)(*(int *)(*(int *)((int)param_1 + 8) + 0x31c) + 0x28),

                         *(undefined4 *)((int)param_1 + 0x18));

      iVar7 = AddHud__4cHudP8cHudIcon_4

                        (*(undefined4 *)

                          (*(int *)(*(int *)((int)param_1 + 8) + 8 +

                                   *(int *)((int)param_1 + 0x10) * 4) + 0x28),

                         *(undefined4 *)((int)param_1 + 0x14));

      if ((0x1df < iVar7) && (iVar6 < 0x1e0)) {

        playerobj_eval_refpt(param_1,0xffffffff,&fStack_c);

        fVar2 = *(float *)(DAT_00632ed8 + 0x1430);

        fVar11 = (float10)distancesq2d__FP3P3DT0(&fStack_c,DAT_00632a88 + 0xa0);

        if ((fVar11 < (float10)fVar2 * (float10)fVar2) && (*(int *)((int)param_1 + 0x10) == 0xc5)) {

          obj_damage_apply(0x14,*(undefined4 *)(DAT_00632ed8 + 0x1428),DAT_00632a88,param_1,0,0);

          fStack_18 = -*(float *)((int)param_1 + 0x29c);

          fStack_14 = -*(float *)((int)param_1 + 0x2ac);

          fStack_10 = 0.0;

          normalize__FPfN20(&fStack_18,&fStack_14,&fStack_10);

          *(float *)(DAT_00632a88 + 0x128) =

               *(float *)(DAT_00632ed8 + 0x1434) * fStack_18 + *(float *)(DAT_00632a88 + 0x128);

          *(float *)(DAT_00632a88 + 300) =

               *(float *)(DAT_00632ed8 + 0x1434) * fStack_14 + *(float *)(DAT_00632a88 + 300);

          *(float *)(DAT_00632a88 + 0x130) =

               *(float *)(DAT_00632ed8 + 0x1438) + *(float *)(DAT_00632a88 + 0x130);

        }

      }

    }

    if ((*(byte *)((int)param_1 + 0x30) & 2) != 0) {

      playerobj_eval_refpt(param_1,0xffffffff,&fStack_c);

      fVar2 = *(float *)(DAT_00632ed8 + 0x1430);

      fVar11 = (float10)distancesq2d__FP3P3DT0(&fStack_c,DAT_00632a88 + 0xa0);

      if (((float10)fVar2 * (float10)fVar2 <= fVar11) || (*(int *)((int)param_1 + 0x10) == 0xc5)) {

        iVar8 = crt_rand_scaled(100);

        if (iVar8 < 0x32) {

          uVar9 = 0x467;

        }

        else {

          uVar9 = 0x468;

        }

        sound_play_obj(uVar9,param_1);

        iVar8 = crt_rand_scaled(100);

        if (iVar8 < 0x19) {

          iVar8 = 0xb8;

        }

        else if (iVar8 < 0x32) {

          iVar8 = 0xb9;

        }

        else {

          iVar8 = (0x4a < iVar8) + 0xba;

        }

        if ((*(int *)((int)param_1 + 0x10) != iVar8) &&

           (*(int *)(*(int *)((int)param_1 + 8) + 8 + iVar8 * 4) != 0)) {

          ObjectSetAnim(param_1,iVar8,0x20,0,*(float *)((int)param_1 + 0xc4) * 0.0,0x3e2aaaab);

          sound_stop_obj(0x6dc,param_1);

          sound_stop_obj(0x6dd,param_1);

        }

        *(undefined4 *)((int)param_1 + 0xe4) = 0x20;

      }

      else {

        sound_play_obj(0x462,param_1);

        fVar11 = (float10)FUN_0045b610(param_1,DAT_00632a88,0x40400000);

        *(float *)(iVar8 + 0x68) = (float)fVar11;

        reaper_lock_short_5(param_1,DAT_00632a88,(float)fVar11,3);

        *(undefined4 *)((int)param_1 + 0xe4) = 0x21;

      }

      *(undefined4 *)((int)param_1 + 0x128) = 0;

      *(undefined4 *)((int)param_1 + 300) = 0;

      *(undefined4 *)((int)param_1 + 0x130) = 0;

      ai_clear_move_goal(param_1);

    }

    break;

  case 0x20:

    if ((*(byte *)((int)param_1 + 0x30) & 2) != 0) {

      piVar1 = (int *)((int)param_1 + 0xf4);

      *piVar1 = *piVar1 + -1;

      if (*piVar1 == 0) {

        *(undefined4 *)((int)param_1 + 0xe4) = 0xb;

      }

      else {

        sound_play_obj(0x6dc,param_1);

        if ((*(int *)((int)param_1 + 0x10) != 2) &&

           (*(int *)(*(int *)((int)param_1 + 8) + 0x10) != 0)) {

          ObjectSetAnim(param_1,2,0x21,1,

                        *(float *)(DAT_00632ed8 + 0x9d4) * *(float *)((int)param_1 + 0xc4),

                        0x3e2aaaab);

          sound_stop_obj(0x6dc,param_1);

          sound_stop_obj(0x6dd,param_1);

        }

        *(undefined4 *)((int)param_1 + 0xe4) = 0x1f;

      }

    }

    break;

  case 0x21:

    if (*(int *)((int)param_1 + 0x10) == 0x5f) {

      if ((*(byte *)((int)param_1 + 0x30) & 2) != 0) {

        fStack_c = -*(float *)((int)param_1 + 0x29c);

        afStack_8[0] = -*(float *)((int)param_1 + 0x2ac);

        afStack_8[1] = 0.0;

        normalize__FPfN20(&fStack_c,afStack_8,afStack_8 + 1);

        playerobj_eval_refpt(param_1,0xffffffff,&fStack_18);

        fVar11 = (float10)rndfloatrange(*(undefined4 *)(DAT_00632ed8 + 0x1420),

                                        *(undefined4 *)(DAT_00632ed8 + 0x1424));

        fStack_18 = (float)((float10)fStack_18 + fVar11 * (float10)fStack_c);

        fStack_14 = (float)(fVar11 * (float10)fStack_c + (float10)fStack_14);

        fVar11 = (float10)terrain_query_z(&fStack_18);

        fStack_10 = (float)fVar11;

        reaper_spawn_ospec_1

                  (param_1,DAT_00632a88,&fStack_18,0,*(undefined4 *)(DAT_00632ed8 + 0x1660),

                   *(undefined4 *)(iVar8 + 0x68));

        iVar8 = crt_rand_scaled(100);

        if (iVar8 < 0x32) {

          uVar9 = 0x467;

        }

        else {

          uVar9 = 0x468;

        }

        sound_play_obj(uVar9,param_1);

        iVar8 = crt_rand_scaled(100);

        if (iVar8 < 0x19) {

          iVar8 = 0xb8;

        }

        else if (iVar8 < 0x32) {

          iVar8 = 0xb9;

        }

        else {

          iVar8 = (0x4a < iVar8) + 0xba;

        }

        if ((*(int *)((int)param_1 + 0x10) != iVar8) &&

           (*(int *)(*(int *)((int)param_1 + 8) + 8 + iVar8 * 4) != 0)) {

          ObjectSetAnim(param_1,iVar8,0x20,0,*(float *)((int)param_1 + 0xc4) * 0.0,0x3e2aaaab);

          sound_stop_obj(0x6dc,param_1);

          sound_stop_obj(0x6dd,param_1);

        }

        *(undefined4 *)((int)param_1 + 0xe4) = 0x20;

      }

      break;

    }

    sound_play_obj(0x480,param_1);

LAB_004695b6:

    uVar9 = 0x5f;

    if (*(int *)((int)param_1 + 0x10) == 0x5f) break;

    iVar8 = *(int *)(*(int *)((int)param_1 + 8) + 0x184);

LAB_004695c8:

    if (iVar8 == 0) break;

    param_1 = *(float *)((int)param_1 + 0xc4) * 0.0;

    uVar13 = 0;

    uVar12 = 0x20;

    goto LAB_00469149;

  case 0x28:

    if ((*(byte *)((int)param_1 + 0x30) & 2) != 0) {

      *(uint *)((int)param_1 + 0xe4) = (-(uint)(*(int *)((int)param_1 + 0xf8) != 1) & 0x13) + 0xb;

    }

    break;

  case 0x32:

    if ((*(byte *)((int)param_1 + 0x30) & 2) != 0) {

      voice_event_trigger(param_1);

      *(undefined4 *)((int)param_1 + 0xe4) = 0x33;

    }

  }

  if ((*(int *)(iVar4 + 0x10) == 2) &&

     (fVar2 = *(float *)(*(int *)(iVar4 + 0x104) + 0x24),

     *(float *)(DAT_00632ed8 + 0x1484) < fVar2 != (*(float *)(DAT_00632ed8 + 0x1484) == fVar2))) {

    if (*(int *)(*(int *)(iVar4 + 8) + 0x29c) != 0) {

      ObjectSetAnim(iVar4,0xa5,0x21,1,*(float *)(DAT_00632ed8 + 0x9dc) * *(float *)(iVar4 + 0xc4),

                    0x3e2aaaab);

      sound_stop_obj(0x6dc,iVar4);

      sound_stop_obj(0x6dd,iVar4);

    }

    sound_play_obj(0x6dd,iVar4);

  }

  obj_alpha_fade_update(iVar4);

  player_pitch_update(iVar4);

  obj_vel_reset(iVar4);

  PhysicsExApplyLocation(iVar4);

  PhysicsExCalcControledModelSpeeds

            (iVar4,*(undefined4 *)(DAT_00632ed8 + 0x6e4),*(undefined4 *)(DAT_00632ed8 + 0x6e0));

  obj_gravity_apply(iVar4,1);

  PhysicsExApplyMoveControls(iVar4);

  fVar11 = (float10)FUN_00518b70(iVar4,0);

  object_animate_process(iVar4,(float)fVar11);

  *(uint *)(iVar4 + 0xd8) = *(uint *)(iVar4 + 0xd8) | 0x40;

  return;

}

/* ===== kabutoai_change_anim__FP6OBJECTii4SDKYfi @ 0x00469860 ===== */
/* PS2 candidate: kabutoai_change_anim__FP6OBJECTii4SDKYfi (conf 0.461) */



void kabutoai_change_anim__FP6OBJECTii4SDKYfi

               (int param_1,int param_2,int param_3,undefined4 param_4,float param_5,int param_6)



{

  byte bVar1;

  float10 fVar2;

  

  if ((*(int *)(param_1 + 0x10) != param_2) &&

     (*(int *)(*(int *)(param_1 + 8) + 8 + param_2 * 4) != 0)) {

    if (param_6 == 0) {

      bVar1 = param_3 != 0 | 0x20;

    }

    else {

      fVar2 = (float10)rndfloatrange(0,0x3f800000);

      *(float *)(param_1 + 0x14) = (float)fVar2;

      bVar1 = param_3 != 0 | 0x80;

    }

    ObjectSetAnim(param_1,param_2,bVar1,param_4,param_5 * *(float *)(param_1 + 0xc4),0x3e2aaaab);

    sound_stop_obj(0x6dc,param_1);

    sound_stop_obj(0x6dd,param_1);

  }

  return;

}

/* ===== FUN_004698f0 @ 0x004698F0 ===== */
float10 FUN_004698f0(int param_1,undefined4 param_2)



{

  int iVar1;

  float10 fVar2;

  

  iVar1 = *(int *)(param_1 + 0x100);

  FUN_0050a610(param_1 + 0xa0,param_2);

  fVar2 = (float10)powf();

  trajectory_calculate

            (param_1 + 0x128,param_1 + 0xa0,param_2,iVar1 + 0x40,(float)(fVar2 * (float10)0.1));

  return (float10)(float)(fVar2 * (float10)0.1);

}

/* ===== FUN_00469950 @ 0x00469950 ===== */
float10 FUN_00469950(int param_1,undefined4 param_2)



{

  undefined1 uVar1;

  float10 fVar2;

  

  fVar2 = (float10)playerobj_turn(param_2,*(undefined4 *)(param_1 + 200));

  if (ABS(fVar2) == (float10)0.0) {

    return (float10)0.0;

  }

  *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) | 0x1000000;

  *(undefined4 *)(param_1 + 0x158) = param_2;

  uVar1 = __ftol();

  *(undefined1 *)(param_1 + 0x208) = uVar1;

  return (float10)(float)ABS(fVar2);

}

/* ===== loglauncher_process @ 0x004699E0 ===== */
/* PS2 candidate: loglauncher_process (conf 0.419) */



void loglauncher_process(int param_1)



{

  float fVar1;

  int iVar2;

  undefined1 uVar3;

  float10 fVar4;

  float10 fVar5;

  undefined4 uVar6;

  

  iVar2 = DAT_00632a88;

  *(int *)(param_1 + 0x274) = DAT_00632a88;

  fVar4 = (float10)dirfcalcp3d__FP3P3DT0(param_1 + 0xa0,iVar2 + 0xa0);

  fVar5 = (float10)playerobj_turn((float)fVar4,*(undefined4 *)(param_1 + 200));

  fVar1 = (float)ABS(fVar5);

  if (ABS(fVar5) == (float10)0.0) {

    fVar1 = 0.0;

  }

  else {

    *(float *)(param_1 + 0x158) = (float)fVar4;

    *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) | 0x1000000;

    uVar3 = __ftol();

    *(undefined1 *)(param_1 + 0x208) = uVar3;

  }

  if (5.0 <= fVar1) {

    if ((*(int *)(param_1 + 0x10) != 0x26) && (*(int *)(*(int *)(param_1 + 8) + 0xa0) != 0)) {

      ObjectSetAnim(param_1,0x26,0x21,3,

                    *(float *)(DAT_00632ed8 + 0x15dc) * *(float *)(param_1 + 0xc4),0x3e2aaaab);

      sound_stop_obj(0x6dc,param_1);

      sound_stop_obj(0x6dd,param_1);

    }

    *(undefined4 *)(param_1 + 0xe4) = 0xe;

    return;

  }

  fVar4 = (float10)distancesq2d__FP3P3DT0(param_1 + 0xa0,*(int *)(param_1 + 0x274) + 0xa0);

  if ((float10)*(float *)(DAT_00632ed8 + 0x11c0) * (float10)*(float *)(DAT_00632ed8 + 0x11c0) <=

      fVar4) {

    if ((*(int *)(param_1 + 0x10) == 0xa7) || (*(int *)(*(int *)(param_1 + 8) + 0x2a4) == 0))

    goto LAB_00469b54;

    fVar1 = *(float *)(param_1 + 0xc4);

    uVar6 = 0xa7;

  }

  else {

    if ((*(int *)(param_1 + 0x10) == 0xa6) || (*(int *)(*(int *)(param_1 + 8) + 0x2a0) == 0))

    goto LAB_00469b54;

    fVar1 = *(float *)(param_1 + 0xc4);

    uVar6 = 0xa6;

  }

  ObjectSetAnim(param_1,uVar6,0x20,0,fVar1 * 0.0,0x3e2aaaab);

  sound_stop_obj(0x6dc,param_1);

  sound_stop_obj(0x6dd,param_1);

LAB_00469b54:

  *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xfffffff7;

  *(undefined4 *)(param_1 + 0xe4) = 0xc;

  return;

}

/* ===== kabuto_death_shots_c15 @ 0x00469BE0 ===== */
void kabuto_death_shots_c15(int param_1,float param_2,int param_3)



{

  float fVar1;

  int iVar2;

  undefined4 uVar3;

  

  if (*(int *)(param_3 + 0xe8) != 1) {

    if (((param_1 < 0x31) || (0x44 < param_1)) && (param_1 == 0xc)) {

      param_2 = param_2 * 10.0;

      fVar1 = param_2 + *(float *)(param_3 + 0x278);

      *(float *)(param_3 + 0x278) = fVar1;

      if (fVar1 < *(float *)(param_3 + 0x1c0)) {

        if (*(float *)(DAT_00632ed8 + 0x143c) < param_2) {

          if (*(int *)(param_3 + 0xf8) != 2) {

            if ((*(int *)(param_3 + 0x10) != 0xb5) && (*(int *)(*(int *)(param_3 + 8) + 0x2dc) != 0)

               ) {

              ObjectSetAnim(param_3,0xb5,0x20,0,*(float *)(param_3 + 0xc4) * 0.0,0x3e2aaaab);

              sound_stop_obj(0x6dc,param_3);

              sound_stop_obj(0x6dd,param_3);

            }

            *(undefined4 *)(param_3 + 0xe4) = 0x28;

          }

          iVar2 = crt_rand_scaled(100);

          if (0x31 < iVar2) {

            sound_play_player(0x43e,param_3);

            return;

          }

          sound_play_player(0x43d,param_3);

          return;

        }

        if (*(float *)(DAT_00632ed8 + 0x1440) < param_2) {

          iVar2 = crt_rand_scaled(100);

          if (0x31 < iVar2) {

            sound_play_player(0x458,param_3);

            return;

          }

          sound_play_player(0x457,param_3);

          return;

        }

        iVar2 = crt_rand_scaled(100);

        if (iVar2 < 0x32) {

          sound_play_player(0x445,param_3);

          return;

        }

        sound_play_player(0x446,param_3);

      }

      else {

        *(undefined4 *)(param_3 + 0x278) = *(undefined4 *)(param_3 + 0x1c0);

        if ((*(int *)(param_3 + 0x10) != 0x93) && (*(int *)(param_3 + 0x10) != 0x94)) {

          iVar2 = crt_rand_scaled(100);

          if (iVar2 < 0x32) {

            uVar3 = 0x40d;

          }

          else {

            uVar3 = 0x40e;

          }

          sound_play_3dpos(uVar3,param_3 + 0xa0);

          if ((*(int *)(param_3 + 0x10) != 0xb5) && (*(int *)(*(int *)(param_3 + 8) + 0x2dc) != 0))

          {

            ObjectSetAnim(param_3,0xb5,0x20,0,*(float *)(param_3 + 0xc4) * 0.0,0x3e2aaaab);

            sound_stop_obj(0x6dc,param_3);

            sound_stop_obj(0x6dd,param_3);

          }

          *(undefined4 *)(param_3 + 0xe4) = 0x32;

          return;

        }

      }

    }

    return;

  }

  if (*(int *)(param_3 + 0x10) == 0x93) {

    return;

  }

  if (*(int *)(param_3 + 0x10) == 0x94) {

    return;

  }

  iVar2 = crt_rand_scaled(100);

  if (iVar2 < 0x32) {

    uVar3 = 0x40d;

  }

  else {

    uVar3 = 0x40e;

  }

  sound_play_3dpos(uVar3,param_3 + 0xa0);

  if (param_1 == 0xc) {

    if ((*(int *)(param_3 + 0x10) == 0x94) || (*(int *)(*(int *)(param_3 + 8) + 600) == 0))

    goto code_r0x00469ccd;

    fVar1 = *(float *)(param_3 + 0xc4);

    uVar3 = 0x94;

  }

  else {

    if ((*(int *)(param_3 + 0x10) == 0x93) || (*(int *)(*(int *)(param_3 + 8) + 0x254) == 0))

    goto code_r0x00469ccd;

    fVar1 = *(float *)(param_3 + 0xc4);

    uVar3 = 0x93;

  }

  ObjectSetAnim(param_3,uVar3,0x20,0,fVar1 * 0.0,0x3e2aaaab);

  sound_stop_obj(0x6dc,param_3);

  sound_stop_obj(0x6dd,param_3);

code_r0x00469ccd:

  *(undefined4 *)(param_3 + 0xe4) = 4;

  return;

}

/* ===== cspec_00469f00 @ 0x00469F00 ===== */
/* WARNING: Type propagation algorithm not settling */



undefined4 cspec_00469f00(int param_1,int param_2)



{

  float fStack_c;

  float afStack_8 [2];

  

  if ((*(int *)(param_1 + 0xe4) == 0xc) && (param_2 == DAT_00632a88)) {

    if ((*(byte *)(param_1 + 0xe0) & 8) == 0) {

      obj_damage_apply(0x16,*(undefined4 *)(DAT_00632ed8 + 0x1470),DAT_00632a88,0,0,0);

      *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 8;

    }

    fStack_c = -*(float *)(param_1 + 0x29c);

    afStack_8[0] = -*(float *)(param_1 + 0x2ac);

    afStack_8[1] = 0.0;

    normalize__FPfN20(&fStack_c,afStack_8,afStack_8 + 1);

    *(float *)(DAT_00632a88 + 0x128) =

         *(float *)(DAT_00632ed8 + 0x1418) * fStack_c + *(float *)(DAT_00632a88 + 0x128);

    *(float *)(DAT_00632a88 + 300) =

         *(float *)(DAT_00632ed8 + 0x1418) * afStack_8[0] + *(float *)(DAT_00632a88 + 300);

    *(float *)(DAT_00632a88 + 0x130) =

         *(float *)(DAT_00632ed8 + 0x141c) + *(float *)(DAT_00632a88 + 0x130);

    return 1;

  }

  return 0;

}

/* ===== cspec_0046a010 @ 0x0046A010 ===== */
void cspec_0046a010(int param_1)



{

  int iVar1;

  int *piVar2;

  

  piVar2 = (int *)(*(int *)(param_1 + 0x100) + 0x3c);

  iVar1 = *piVar2;

  if ((iVar1 != 0) && ((char)((uint)*(undefined4 *)(iVar1 + 0xd8) >> 8) < '\0')) {

    *piVar2 = 0;

  }

  return;

}

/* ===== cspec_0046a030 @ 0x0046A030 ===== */
undefined4 cspec_0046a030(void)



{

  return 0x6c;

}

/* ===== cspec_0046a040 @ 0x0046A040 ===== */
void cspec_0046a040(int param_1)



{

  undefined4 *puVar1;

  undefined4 uVar2;

  int iVar3;

  float10 fVar4;

  

  iVar3 = *(int *)(param_1 + 0xe4);

  if (iVar3 == 0) {

    puVar1 = *(undefined4 **)(param_1 + 0x100);

    uVar2 = fx_get_free_effect__Fv();

    *puVar1 = uVar2;

    *(undefined4 *)(param_1 + 0xe4) = 3;

    return;

  }

  if (iVar3 == 1) {

    if ((*(int *)(param_1 + 0x274) != 0) && (*(int *)(*(int *)(param_1 + 0x274) + 0x210) == 0)) {

      return;

    }

    if (*(int *)(param_1 + 0xe8) == 0) {

      uVar2 = *(undefined4 *)(DAT_00632ed8 + 0x1474);

    }

    else {

      uVar2 = *(undefined4 *)(DAT_00632ed8 + 0x150c);

    }

  }

  else {

    if (iVar3 == 2) {

      iVar3 = fx_create(param_1);

      if (iVar3 == 0) {

        return;

      }

      fVar4 = (float10)FUN_00518b70(param_1,0);

      fVar4 = (float10)*(float *)(param_1 + 0xec) - fVar4;

      *(float *)(param_1 + 0xec) = (float)fVar4;

      if (fVar4 < (float10)0.0 == (fVar4 == (float10)0.0)) {

        return;

      }

      func_0x0046a210(param_1,0xffffffff);

      return;

    }

    if (iVar3 != 4) {

      return;

    }

    if ((*(int *)(param_1 + 0x274) != 0) && (*(int *)(*(int *)(param_1 + 0x274) + 0x210) == 0)) {

      fVar4 = (float10)FUN_00518b70(param_1,0);

      fVar4 = (float10)*(float *)(param_1 + 0xf0) - fVar4;

      *(float *)(param_1 + 0xf0) = (float)fVar4;

      if (fVar4 < (float10)0.0 == (fVar4 == (float10)0.0)) {

        iVar3 = *(int *)(param_1 + 0x274);

        fVar4 = (float10)FUN_00518b70(param_1,0);

        *(float *)(iVar3 + 0xa8) =

             (float)(fVar4 * (float10)*(float *)(param_1 + 0xf4) + (float10)*(float *)(iVar3 + 0xa8)

                    );

        return;

      }

      playerobj_eval_refpt(param_1,1,*(int *)(param_1 + 0x274) + 0xa0);

      *(undefined4 *)(param_1 + 0xe4) = 1;

      return;

    }

    if (*(int *)(param_1 + 0xe8) == 0) {

      uVar2 = *(undefined4 *)(DAT_00632ed8 + 0x1474);

    }

    else {

      uVar2 = *(undefined4 *)(DAT_00632ed8 + 0x150c);

    }

  }

  *(undefined4 *)(param_1 + 0xec) = uVar2;

  *(undefined4 *)(param_1 + 0xe4) = 2;

  iVar3 = dialog_level_is_base();

  if (iVar3 != 0) {

    reaper_00530bd0(param_1,0,0,0,1,0);

  }

  return;

}

/* ===== cspec_0046a370 @ 0x0046A370 ===== */
undefined4 cspec_0046a370(void)



{

  return 4;

}

/* ===== cspec_0046a380 @ 0x0046A380 ===== */
void cspec_0046a380(int param_1,undefined4 param_2,int param_3)



{

  undefined4 uVar1;

  undefined4 *puVar2;

  

  if ((*(int *)(param_3 + 0xe4) == 3) && (param_1 == 4)) {

    puVar2 = *(undefined4 **)(param_3 + 0x100);

    FUN_00448c20(*puVar2);

    *puVar2 = 0;

    if (*(int *)(param_3 + 0xe8) == 0) {

      uVar1 = *(undefined4 *)(DAT_00632ed8 + 0x1474);

    }

    else {

      uVar1 = *(undefined4 *)(DAT_00632ed8 + 0x150c);

    }

    *(undefined4 *)(param_3 + 0xec) = uVar1;

    *(undefined4 *)(param_3 + 0xe4) = 2;

    sound_play_3dpos(0x615,param_3 + 0xa0);

  }

  return;

}

/* ===== cspec_0046a400 @ 0x0046A400 ===== */
void cspec_0046a400(int param_1,int param_2,undefined4 param_3,undefined4 *param_4)



{

  undefined4 uVar1;

  

  if (param_2 == 1) {

    if (*(int *)(param_1 + 0xe8) == 0) {

      uVar1 = *(undefined4 *)(DAT_00632ed8 + 0x1474);

      *(undefined4 *)(param_1 + 0xe4) = 2;

      *(undefined4 *)(param_1 + 0xec) = uVar1;

      return;

    }

    uVar1 = *(undefined4 *)(DAT_00632ed8 + 0x150c);

    *(undefined4 *)(param_1 + 0xe4) = 2;

    *(undefined4 *)(param_1 + 0xec) = uVar1;

  }

  else if (param_2 == 2) {

    func_0x0046a210(param_1,*param_4);

    return;

  }

  return;

}

/* ===== cspec_0046a470 @ 0x0046A470 ===== */
undefined4 cspec_0046a470(void)



{

  return 200;

}

/* ===== kbos_sizer @ 0x0046A480 ===== */
/* PS2 candidate: kbos_sizer (conf 0.608) */



void kbos_sizer(int param_1,float param_2)



{

  int iVar1;

  int iVar2;

  float fVar3;

  

  iVar1 = *(int *)(param_1 + 0x100);

  iVar2 = *(int *)(iVar1 + 4);

  if (iVar2 != 0) {

    fVar3 = param_2 * *(float *)(iVar2 + 0x194);

    *(float *)(iVar1 + 0x88) = fVar3;

    fVar3 = fVar3 * 0.5;

    *(float *)(iVar1 + 0x84) = fVar3;

    *(float *)(iVar1 + 0x8c) = fVar3 * 0.15915494;

    *(float *)(param_1 + 0xc4) = param_2 * *(float *)(iVar2 + 0xc4);

    obj_sub100_transform(param_1);

  }

  return;

}

/* ===== hud_icon_add_2 @ 0x0046A4E0 ===== */
void hud_icon_add_2(int param_1,int param_2)



{

  int iVar1;

  undefined4 uVar2;

  

  *(undefined4 *)(param_2 + 0x30) = *(undefined4 *)(param_1 + 0xe4);

  *(undefined4 *)(param_2 + 4) = *(undefined4 *)(param_1 + 0x10);

  *(uint *)(param_2 + 0xc) = *(uint *)(param_1 + 0x30) & 2;

  *(undefined4 *)(param_2 + 0x40) = 0;

  if ((*(int *)(param_1 + 0x10) < 0xfe) &&

     (iVar1 = *(int *)(*(int *)(param_1 + 8) + 8 + *(int *)(param_1 + 0x10) * 4), iVar1 != 0)) {

    *(undefined4 *)(param_2 + 0x40) = *(undefined4 *)(iVar1 + 0x28);

  }

  if (*(int *)(param_2 + 0x40) != 0) {

    uVar2 = AddHud__4cHudP8cHudIcon_4(*(int *)(param_2 + 0x40),*(undefined4 *)(param_1 + 0x18));

    *(undefined4 *)(param_2 + 0x38) = uVar2;

    uVar2 = AddHud__4cHudP8cHudIcon_4

                      (*(undefined4 *)(param_2 + 0x40),*(undefined4 *)(param_1 + 0x14));

    *(undefined4 *)(param_2 + 0x3c) = uVar2;

    return;

  }

  *(undefined4 *)(param_2 + 0x3c) = 0;

  *(undefined4 *)(param_2 + 0x38) = 0;

  return;

}

/* ===== reaper_lock_short_2 @ 0x0046A710 ===== */
uint reaper_lock_short_2(int param_1,undefined4 *param_2,int param_3)



{

  int iVar1;

  undefined4 uVar2;

  undefined4 uVar3;

  undefined4 uVar4;

  uint uVar5;

  undefined4 local_14;

  undefined4 local_10;

  int local_c;

  uint local_8;

  undefined4 local_4;

  

  iVar1 = param_2[2];

  uVar5 = 0;

  *param_2 = 0;

  param_2[6] = param_2[6] & 0xfffffeff;

  if ((-1 < iVar1) && ((param_2[1] != iVar1 || (param_2[0xb] != 0)))) {

    uVar2 = param_2[9];

    uVar3 = param_2[7];

    uVar5 = ~param_2[5] & param_2[4];

    uVar4 = param_2[8];

    ObjectSetAnim(param_1,iVar1,uVar5,uVar3,uVar4,uVar2);

    if (param_3 != 0) {

      local_14 = uVar4;

      local_10 = uVar2;

      local_c = iVar1;

      local_8 = uVar5;

      local_4 = uVar3;

      reaper_00530bd0(param_1,3,3,0,4,&local_14);

    }

    if ((char)uVar5 < '\0') {

      *(undefined4 *)(param_1 + 0x14) = param_2[10];

    }

    object_animate_process(param_1,0);

    uVar5 = 1;

  }

  iVar1 = param_2[0xd];

  if ((-1 < iVar1) && (param_2[0xc] != iVar1)) {

    *(int *)(param_1 + 0xe4) = iVar1;

    uVar5 = uVar5 | 2;

  }

  return uVar5;

}

/* ===== obj_anim_flags_update @ 0x0046A800 ===== */
void obj_anim_flags_update(uint param_1,float *param_2)



{

  uint *puVar1;

  uint uVar2;

  uint uVar3;

  float10 fVar4;

  float10 fVar5;

  float local_c;

  float local_8;

  uint local_4;

  

  uVar3 = param_1;

  puVar1 = *(uint **)(param_1 + 0x100);

  uVar2 = puVar1[4];

  if ((uVar2 == 0) || ((*puVar1 & 0x10) == 0)) {

    *puVar1 = *puVar1 & 0xffffffef;

  }

  else {

    puVar1[5] = *(uint *)(uVar2 + 0xa0);

    puVar1[6] = *(uint *)(uVar2 + 0xa4);

    puVar1[7] = *(uint *)(uVar2 + 0xa8);

  }

  if ((uVar2 == 0) || ((*puVar1 & 0x20) == 0)) {

    *puVar1 = *puVar1 & 0xffffffdf;

  }

  else {

    local_c = (float)puVar1[5] - *(float *)(param_1 + 0xa0);

    local_8 = (float)puVar1[6] - *(float *)(param_1 + 0xa4);

    fVar4 = (float10)atand2pos(local_8,local_c);

    puVar1[0xc] = (uint)(float)(fVar4 + (float10)90.0);

  }

  uVar2 = *puVar1;

  *puVar1 = uVar2 | 0xc0;

  puVar1[8] = (uint)DAT_0059da70;

  puVar1[9] = DAT_0059da74;

  puVar1[10] = DAT_0059da78;

  puVar1[0xb] = 0;

  if ((uVar2 & 4) != 0) {

    fVar4 = (float10)FUN_004a2650(&local_c,&param_1,puVar1 + 5,uVar3 + 0xa0,

                                  (float)puVar1[0x24] * (float)puVar1[0x21],

                                  (float)puVar1[0x22] * (float)puVar1[0x24],0x3f800000);

    puVar1[0xd] = (uint)(float)fVar4;

    fVar5 = (float10)*param_2;

    if ((float10)0.25 < fVar5) {

      fVar5 = (float10)0.25;

    }

    if ((float10)(float)puVar1[0x24] * (float10)(float)puVar1[0x21] * fVar5 * (float10)4.0 < fVar4)

    {

      fVar4 = (float10)atand2pos(local_8,local_c);

      puVar1[0xc] = (uint)(float)(fVar4 + (float10)90.0);

      puVar1[8] = (uint)local_c;

      puVar1[9] = (uint)local_8;

      puVar1[10] = local_4;

      puVar1[0xb] = param_1;

      *puVar1 = *puVar1 & 0xffffffbf | 8;

    }

  }

  *(undefined4 *)(uVar3 + 0x114) = 0;

  if ((*puVar1 & 8) != 0) {

    fVar4 = (float10)playerobj_turn(puVar1[0xc],*(undefined4 *)(uVar3 + 200));

    puVar1[0xe] = (uint)(float)fVar4;

    if ((float10)-90.0 <= fVar4) {

      if ((float10)90.0 < fVar4) {

        fVar4 = (float10)90.0;

      }

    }

    else {

      fVar4 = (float10)-90.0;

    }

    *(float *)(uVar3 + 0x114) = (float)((float10)5.0 * fVar4);

    puVar1[0x28] = 0x3e4ccccd;

    if (fVar4 < (float10)-1.0) {

      *puVar1 = *puVar1 & 0xffffff7f;

    }

    else if ((float10)1.0 < fVar4) {

      *puVar1 = *puVar1 & 0xffffff7f;

      return;

    }

  }

  return;

}

/* ===== gfx_d3d_0046aa30 @ 0x0046AA30 ===== */
void gfx_d3d_0046aa30(int param_1,int param_2)



{

  uint *puVar1;

  bool bVar2;

  bool bVar3;

  undefined4 uVar4;

  int iVar5;

  char *pcVar6;

  undefined4 uVar7;

  undefined1 *puVar8;

  undefined1 local_50 [8];

  float local_48;

  undefined1 local_34 [4];

  undefined4 local_30;

  undefined4 local_2c;

  undefined4 local_28;

  undefined4 local_24;

  undefined4 local_20;

  int local_1c;

  

  puVar1 = *(uint **)(param_1 + 0x100);

  if ((*(byte *)(param_1 + 0xe0) & 1) != 0) {

    return;

  }

  if ((~*puVar1 & 0x40) == 0) {

    return;

  }

  if ((float)puVar1[3] * 3.0 <=

      (*(float *)(param_1 + 0xa8) - *(float *)(param_1 + 0x1d4) * *(float *)(param_1 + 0xc4)) -

      *(float *)(param_1 + 0x140)) {

    if (0.5 <= (float)puVar1[3]) {

      *(undefined4 *)(param_2 + 8) = 0x46;

      *(uint *)(param_2 + 0x10) = *(uint *)(param_2 + 0x10) | 1;

      return;

    }

    *(undefined4 *)(param_2 + 8) = 0x2a;

    *(uint *)(param_2 + 0x10) = *(uint *)(param_2 + 0x10) | 1;

    return;

  }

  *(undefined4 *)(param_2 + 0x1c) = 1;

  if (puVar1[0x1f] == 0) {

    bVar2 = *(float *)(param_1 + 0xa8) < 0.0;

    bVar3 = *(float *)(param_1 + 0xa8) == 0.0;

    if ((float)puVar1[0x22] * 1.5 < *(float *)(param_1 + 0x10c)) {

      if (0.5 <= (float)puVar1[3]) {

        if (bVar2 == bVar3) {

          ground_height_at((undefined4 *)(param_1 + 0xa0),local_50);

          if (0.64278 <= local_48) {

            *(undefined4 *)(param_2 + 8) = 0x48;

            *(uint *)(param_2 + 0x10) = *(uint *)(param_2 + 0x10) | 1;

            *(float *)(param_2 + 0x20) = *(float *)(param_1 + 0xc4) * 75.0;

            if (*(int *)(param_2 + 4) != 0x48) {

              return;

            }

            if (*(int *)(param_2 + 0x3c) < 0xd20) {

              return;

            }

            if (0xd1f < *(int *)(param_2 + 0x38)) {

              return;

            }

            local_30 = *(undefined4 *)(param_1 + 0xa0);

            local_2c = *(undefined4 *)(param_1 + 0xa4);

            local_28 = *(undefined4 *)(param_1 + 0xa8);

            fx_get_free_effect__Fv();

            return;

          }

          goto LAB_0046ac2e;

        }

      }

      else if (bVar2 == bVar3) {

        ground_height_at(param_1 + 0xa0,local_50);

        if (0.64278 <= local_48) {

          *(undefined4 *)(param_2 + 8) = 0x2c;

          goto LAB_0046acf5;

        }

LAB_0046ac2e:

        *(undefined4 *)(param_2 + 8) = 99;

        *(uint *)(param_2 + 0x10) = *(uint *)(param_2 + 0x10) | 1;

        iVar5 = *(int *)(param_1 + 0x100);

        *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 1;

        *(undefined4 *)(iVar5 + 0xb8) = *(undefined4 *)(param_1 + 0xe4);

LAB_0046ad71:

        puVar8 = local_34;

        *(undefined4 *)(iVar5 + 0xbc) = 0x3f800000;

        uVar7 = 0x24;

        pcVar6 = s_fx_ripper_dirt_0055b4d8;

        *(undefined4 *)(param_1 + 0xe4) = 0xc;

        local_1c = param_1;

        local_20 = 0xffffffff;

        local_24 = 8;

        uVar4 = fx_get_free_effect__Fv();

        *(undefined4 *)(iVar5 + 0xc0) = uVar4;

        *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) | 0x40000000;

        *(uint *)(*(int *)(iVar5 + 0xb0) + 0xd8) =

             *(uint *)(*(int *)(iVar5 + 0xb0) + 0xd8) | 0x40000000;

        iVar5 = reaper_0052e4a0(param_1,pcVar6,uVar7,puVar8);

        if (iVar5 == 0) {

          return;

        }

        reaper_00530bd0(param_1,0,0,0,9,0);

        return;

      }

    }

    else if (0.5 <= (float)puVar1[3]) {

      if (bVar2 == bVar3) {

        ground_height_at(param_1 + 0xa0,local_50);

        if (0.64278 <= local_48) {

          *(undefined4 *)(param_2 + 8) = 0x47;

          *(uint *)(param_2 + 0x10) = *(uint *)(param_2 + 0x10) | 1;

          *(float *)(param_2 + 0x20) = *(float *)(param_1 + 0xc4) * 25.0;

          return;

        }

        *(undefined4 *)(param_2 + 8) = 99;

        *(uint *)(param_2 + 0x10) = *(uint *)(param_2 + 0x10) | 1;

        iVar5 = *(int *)(param_1 + 0x100);

        *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 1;

        *(undefined4 *)(iVar5 + 0xb8) = *(undefined4 *)(param_1 + 0xe4);

        goto LAB_0046ad71;

      }

    }

    else if (bVar2 == bVar3) {

      ground_height_at(param_1 + 0xa0,local_50);

      if (0.64278 <= local_48) {

        *(undefined4 *)(param_2 + 8) = 0x2b;

        *(uint *)(param_2 + 0x10) = *(uint *)(param_2 + 0x10) | 1;

        *(float *)(param_2 + 0x20) = *(float *)(param_1 + 0xc4) * 20.0;

        return;

      }

      goto LAB_0046ad3d;

    }

  }

  else if (*(float *)(param_1 + 0xa8) < 0.0 == (*(float *)(param_1 + 0xa8) == 0.0)) {

    ground_height_at((undefined4 *)(param_1 + 0xa0),local_50);

    if (0.64278 <= local_48) {

      *(undefined4 *)(param_2 + 8) = 0x59;

      *(uint *)(param_2 + 0x10) = *(uint *)(param_2 + 0x10) | 1;

      *(float *)(param_2 + 0x20) = *(float *)(param_1 + 0xc4) * 50.0;

      if (*(int *)(param_2 + 4) != 0x59) {

        return;

      }

      if (*(int *)(param_2 + 0x3c) < 0xe60) {

        return;

      }

      if (0xe5f < *(int *)(param_2 + 0x38)) {

        return;

      }

      local_30 = *(undefined4 *)(param_1 + 0xa0);

      local_2c = *(undefined4 *)(param_1 + 0xa4);

      local_28 = *(undefined4 *)(param_1 + 0xa8);

      fx_get_free_effect__Fv();

      return;

    }

LAB_0046ad3d:

    *(undefined4 *)(param_2 + 8) = 99;

    *(uint *)(param_2 + 0x10) = *(uint *)(param_2 + 0x10) | 1;

    iVar5 = *(int *)(param_1 + 0x100);

    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 1;

    *(undefined4 *)(iVar5 + 0xb8) = *(undefined4 *)(param_1 + 0xe4);

    goto LAB_0046ad71;

  }

  *(undefined4 *)(param_2 + 8) = 100;

LAB_0046acf5:

  *(uint *)(param_2 + 0x10) = *(uint *)(param_2 + 0x10) | 1;

  *(float *)(param_2 + 0x20) = *(float *)(param_1 + 0xc4) * 60.0;

  return;

}

/* ===== kbos_init @ 0x0046AEB0 ===== */
/* PS2 candidate: kbos_init (conf 0.471) */



void kbos_init(int param_1)



{

  float fVar1;

  uint *puVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  uint uVar6;

  float10 fVar7;

  

  puVar2 = *(uint **)(param_1 + 0x100);

  if ((~*puVar2 & 1) != 0) {

    *(uint **)(param_1 + 0x104) = puVar2 + 0x10;

    PhysicsExZeroForce(param_1);

    *(undefined4 *)(*(int *)(param_1 + 0x104) + 8) = *(undefined4 *)(param_1 + 0x200);

    fVar1 = *(float *)(param_1 + 0x200) * *(float *)(param_1 + 0x1b8);

    *(float *)(*(int *)(param_1 + 0x104) + 4) = fVar1 + fVar1;

    *(undefined4 *)(*(int *)(param_1 + 0x104) + 0x30) = *(undefined4 *)(param_1 + 0x1bc);

    puVar2[8] = DAT_0059da70;

    puVar2[9] = DAT_0059da74;

    puVar2[10] = DAT_0059da78;

    puVar2[0xb] = 0;

    uVar6 = object_find(*(undefined4 *)(param_1 + 4));

    puVar2[1] = uVar6;

    puVar2[0x26] = 0;

    puVar2[0x25] = 0;

    puVar2[0x27] = (uint)(*(float *)(param_1 + 0x1b8) * -64.3481);

    fVar1 = *(float *)(param_1 + 400);

    puVar2[0x2a] = 0;

    puVar2[0x29] = (uint)(fVar1 * 30.0);

    if (*(int *)(param_1 + 4) == 0x2e9) {

      uVar6 = object_allocate_type(0x3b1,1);

      puVar2[0x2c] = uVar6;

      *(int *)(uVar6 + 0x210) = param_1;

      *(undefined4 *)(puVar2[0x2c] + 0x214) = 0;

      *(undefined4 *)(puVar2[0x2c] + 0x218) = 0;

      *(undefined4 *)(puVar2[0x2c] + 0x18c) = *(undefined4 *)(param_1 + 0x18c);

      *(uint *)(puVar2[0x2c] + 0xd8) = *(uint *)(puVar2[0x2c] + 0xd8) | 0x400000;

      *(uint *)(puVar2[0x2c] + 0x1c8) = *(uint *)(puVar2[0x2c] + 0x1c8) | 0x4000000;

      *(uint *)(puVar2[0x2c] + 0xdc) = *(uint *)(puVar2[0x2c] + 0xdc) | 0x2000000;

      *(uint *)(puVar2[0x2c] + 0xd8) = *(uint *)(puVar2[0x2c] + 0xd8) | 0x20000000;

    }

    *puVar2 = *puVar2 | 1;

  }

  if (((*(int *)(param_1 + 0xe4) != 0) && (puVar2[0xf] == *(uint *)(param_1 + 0xe8))) ||

     (puVar2[0xf] = *(uint *)(param_1 + 0xe8), *(int *)(param_1 + 0xe4) != 0)) {

    return;

  }

  fVar7 = (float10)rndfloatrange(0x41700000,0x41f00000);

  *(float *)(param_1 + 0xf0) = (float)fVar7;

  **(uint **)(param_1 + 0x100) = **(uint **)(param_1 + 0x100) & 0xffffffc3;

  *(undefined4 *)(param_1 + 0x178) = *(undefined4 *)(param_1 + 0xa0);

  *(undefined4 *)(param_1 + 0x17c) = *(undefined4 *)(param_1 + 0xa4);

  *(undefined4 *)(param_1 + 0x180) = *(undefined4 *)(param_1 + 0xa8);

  iVar3 = *(int *)(param_1 + 4);

  if (iVar3 != 0x2e9) {

    if (iVar3 == 0x2eb) {

      *(undefined4 *)(param_1 + 0xec) = 0x41f00000;

      *(undefined4 *)(param_1 + 0xe4) = 0x1d;

    }

    else {

      if (iVar3 != 0x2ec) {

        if (iVar3 != 0x2ea) {

          *(undefined4 *)(param_1 + 0xe4) = 1;

          return;

        }

        if (*(int *)(param_1 + 0xe8) == 1) {

          sound_play_3dpos(0x4b2,(undefined4 *)(param_1 + 0xa0));

          *(undefined4 *)(param_1 + 0xe4) = 3;

        }

        else {

          sound_play_obj(0x4b1,param_1);

          *(undefined4 *)(param_1 + 0xe4) = 2;

        }

        *puVar2 = *puVar2 | 2;

        *(uint *)(param_1 + 0x1cc) = *(uint *)(param_1 + 0x1cc) | 1;

        *(uint *)(param_1 + 0x1c8) = *(uint *)(param_1 + 0x1c8) & 0xfffffdff | 0x400;

        return;

      }

      fVar7 = (float10)rndfloatrange(0xc20c0000,0x420c0000);

      *(float *)(param_1 + 0x128) = (float)fVar7;

      fVar7 = (float10)rndfloatrange(0xc20c0000,0x420c0000);

      *(float *)(param_1 + 300) = (float)fVar7;

      fVar7 = (float10)rndfloatrange(0x41700000,0x41c80000);

      *(float *)(param_1 + 0x130) = (float)fVar7;

      *(undefined4 *)(*(int *)(param_1 + 0x104) + 0xc) = 0x3f800000;

      *(undefined4 *)(*(int *)(param_1 + 0x104) + 0x10) = 0x3e800000;

      fVar7 = (float10)rndfloat(0x43b40000);

      *(float *)(param_1 + 200) = (float)fVar7;

      fVar7 = (float10)rndfloatrange(0x3f800000,0x40400000);

      *(float *)(param_1 + 0xec) = (float)fVar7;

      *(undefined4 *)(param_1 + 0xe4) = 0x1b;

    }

    *puVar2 = *puVar2 | 2;

    *(uint *)(param_1 + 0x1c8) = *(uint *)(param_1 + 0x1c8) & 0xfffffdff | 0xc00;

    return;

  }

  iVar3 = *(int *)(param_1 + 0xe8);

  if (iVar3 == 0) {

    puVar2[2] = 0x3e800000;

    puVar2[3] = 0x3e4ccccd;

    iVar3 = *(int *)(param_1 + 0x100);

    iVar4 = *(int *)(iVar3 + 4);

    if (iVar4 != 0) {

      fVar1 = *(float *)(iVar4 + 0x194) * 0.2;

      *(float *)(iVar3 + 0x88) = fVar1;

      fVar1 = fVar1 * 0.5;

      *(float *)(iVar3 + 0x84) = fVar1;

      *(float *)(iVar3 + 0x8c) = fVar1 * 0.15915494;

      *(float *)(param_1 + 0xc4) = *(float *)(iVar4 + 0xc4) * 0.2;

      obj_sub100_transform(param_1);

    }

    *(undefined4 *)(param_1 + 0xe4) = 6;

    return;

  }

  if (iVar3 != 1) {

    puVar2[3] = 0x3f000000;

    puVar2[2] = 0x3f000000;

    iVar4 = *(int *)(param_1 + 0x100);

    iVar5 = *(int *)(iVar4 + 4);

    if (iVar3 != 2) {

      if (iVar5 != 0) {

        fVar1 = *(float *)(iVar5 + 0x194) * 0.5;

        *(float *)(iVar4 + 0x88) = fVar1;

        fVar1 = fVar1 * 0.5;

        *(float *)(iVar4 + 0x84) = fVar1;

        *(float *)(iVar4 + 0x8c) = fVar1 * 0.15915494;

        *(float *)(param_1 + 0xc4) = *(float *)(iVar5 + 0xc4) * 0.5;

        obj_sub100_transform(param_1);

      }

      ObjectSetAnim(param_1,0x49,0x21,3,0x42b40000,0);

      *(undefined4 *)(param_1 + 0xe4) = 1;

      *(undefined1 *)(param_1 + 0x208) = 0xec;

      return;

    }

    if (iVar5 != 0) {

      fVar1 = *(float *)(iVar5 + 0x194) * 0.5;

      *(float *)(iVar4 + 0x88) = fVar1;

      fVar1 = fVar1 * 0.5;

      *(float *)(iVar4 + 0x84) = fVar1;

      *(float *)(iVar4 + 0x8c) = fVar1 * 0.15915494;

      *(float *)(param_1 + 0xc4) = *(float *)(iVar5 + 0xc4) * 0.5;

      obj_sub100_transform(param_1);

    }

    ObjectSetAnim(param_1,0x49,0x21,3,0x42b40000,0);

    *(undefined4 *)(param_1 + 0xe4) = 1;

    *(undefined1 *)(param_1 + 0x208) = 0x14;

    return;

  }

  puVar2[2] = 0x3f800000;

  puVar2[3] = 0x3f800000;

  iVar3 = *(int *)(param_1 + 0x100);

  iVar4 = *(int *)(iVar3 + 4);

  if (iVar4 != 0) {

    fVar1 = *(float *)(iVar4 + 0x194);

    *(float *)(iVar3 + 0x88) = fVar1;

    fVar1 = fVar1 * 0.5;

    *(float *)(iVar3 + 0x84) = fVar1;

    *(float *)(iVar3 + 0x8c) = fVar1 * 0.15915494;

    *(undefined4 *)(param_1 + 0xc4) = *(undefined4 *)(iVar4 + 0xc4);

    obj_sub100_transform(param_1);

  }

  ObjectSetAnim(param_1,5,0x21,0,0,0);

  *(undefined4 *)(param_1 + 0xe4) = 1;

  return;

}

/* ===== Init__7PS2Game @ 0x0046B3F0 ===== */
/* PS2 candidate: Init__7PS2Game (conf 0.581) */



void Init__7PS2Game(undefined4 param_1,undefined4 param_2)



{

  object_init_usage(param_1);

  object_set_location_p3d(param_1,param_2);

  ObjectCalculateTransform(param_1);

  PROJ_ObjectFinalize(param_1);

  kbos_init(param_1);

  return;

}

/* ===== FUN_0046b420 @ 0x0046B420 ===== */
float10 FUN_0046b420(int param_1)



{

  if ((param_1 != 0) && (*(int *)(param_1 + 4) == 0x2e9)) {

    return (float10)*(float *)(*(int *)(param_1 + 0x100) + 0xc);

  }

  return (float10)0.0;

}

/* ===== FUN_0046b450 @ 0x0046B450 ===== */
float10 FUN_0046b450(int param_1)



{

  if ((param_1 != 0) && (*(int *)(param_1 + 4) == 0x2e9)) {

    return (float10)*(float *)(*(int *)(param_1 + 0x100) + 8);

  }

  return (float10)0.0;

}

/* ===== reaper_lock_user_4 @ 0x0046B480 ===== */
undefined4 reaper_lock_user_4(int param_1,undefined4 param_2,char param_3)



{

  float fVar1;

  int iVar2;

  float fVar3;

  int iVar4;

  undefined4 local_8;

  char local_4;

  

  if ((param_1 != 0) && (*(int *)(param_1 + 4) == 0x2e9)) {

    iVar2 = *(int *)(param_1 + 0x100);

    *(undefined4 *)(iVar2 + 8) = param_2;

    iVar4 = reaper_0052e4a0(param_1);

    if (iVar4 != 0) {

      local_8 = *(undefined4 *)(iVar2 + 8);

      local_4 = param_3;

      reaper_00530bd0(param_1,1,0,1,3,&local_8);

    }

    if (param_3 != '\0') {

      fVar1 = *(float *)(iVar2 + 8);

      *(float *)(iVar2 + 0xc) = fVar1;

      iVar2 = *(int *)(param_1 + 0x100);

      iVar4 = *(int *)(iVar2 + 4);

      if (iVar4 != 0) {

        fVar3 = fVar1 * *(float *)(iVar4 + 0x194);

        *(float *)(iVar2 + 0x88) = fVar3;

        fVar3 = fVar3 * 0.5;

        *(float *)(iVar2 + 0x84) = fVar3;

        *(float *)(iVar2 + 0x8c) = fVar3 * 0.15915494;

        *(float *)(param_1 + 0xc4) = fVar1 * *(float *)(iVar4 + 0xc4);

        obj_sub100_transform(param_1);

        return 1;

      }

    }

    return 1;

  }

  return 0;

}

/* ===== object_spawn_init_usage @ 0x0046B560 ===== */
int object_spawn_init_usage(undefined4 param_1,undefined4 param_2,undefined4 *param_3)



{

  int iVar1;

  

  iVar1 = object_allocate_type(0x2ea,0x80000000);

  *(undefined4 *)(iVar1 + 0xe8) = 1;

  object_init_usage(iVar1);

  object_set_location_p3d(iVar1,param_2);

  ObjectCalculateTransform(iVar1);

  PROJ_ObjectFinalize(iVar1);

  kbos_init(iVar1);

  if (param_3 != (undefined4 *)0x0) {

    *(undefined4 *)(iVar1 + 0x128) = *param_3;

    *(undefined4 *)(iVar1 + 300) = param_3[1];

    *(undefined4 *)(iVar1 + 0x130) = param_3[2];

    *(undefined4 *)(iVar1 + 0x274) = param_1;

    return iVar1;

  }

  *(undefined4 *)(iVar1 + 0x274) = param_1;

  return iVar1;

}

/* ===== kbos_offspring_create @ 0x0046B5E0 ===== */
/* PS2 candidate: kbos_offspring_create (conf 0.522) */



int kbos_offspring_create(undefined4 param_1)



{

  int iVar1;

  

  iVar1 = object_allocate_type(0x2e9,0x80000000);

  if (iVar1 != 0) {

    object_change_ospec(iVar1,0x4b);

    *(undefined4 *)(iVar1 + 0xe8) = 0;

    object_init_usage(iVar1);

    object_set_location_p3d(iVar1,param_1);

    ObjectCalculateTransform(iVar1);

    PROJ_ObjectFinalize(iVar1);

    kbos_init(iVar1);

  }

  return iVar1;

}

/* ===== kbos_offspring_process_2 @ 0x0046B640 ===== */
undefined4 kbos_offspring_process_2(int param_1,uint *param_2)



{

  uint uVar1;

  uint uVar2;

  uint *puVar3;

  float10 fVar4;

  

  if (((*(float *)(param_1 + 0x278) < *(float *)(param_1 + 0x1c0)) &&

      (*(int *)(*(int *)(param_1 + 0x100) + 0x7c) == 0)) &&

     (*(int *)(*(int *)(param_1 + 0x100) + 0x80) == 0)) {

    uVar1 = *param_2;

    uVar2 = param_2[1];

    fVar4 = (float10)terrain_query_z(param_2);

    *(uint *)(param_1 + 0x178) = uVar1;

    *(uint *)(param_1 + 0x17c) = uVar2;

    *(float *)(param_1 + 0x180) = (float)fVar4;

    puVar3 = *(uint **)(param_1 + 0x100);

    *puVar3 = *puVar3 & 0xffffffcf | 0xc;

    puVar3[5] = uVar1;

    puVar3[6] = uVar2;

    puVar3[7] = (uint)(float)fVar4;

    *(undefined4 *)(param_1 + 0xe4) = 0x10;

    return 1;

  }

  return 0;

}

/* ===== kbos_offspring_process @ 0x0046B6F0 ===== */
undefined4 kbos_offspring_process(int param_1,uint *param_2,undefined4 param_3)



{

  int iVar1;

  uint uVar2;

  uint uVar3;

  uint *puVar4;

  float10 fVar5;

  

  iVar1 = *(int *)(param_1 + 0x100);

  if ((((*(float *)(param_1 + 0x278) < *(float *)(param_1 + 0x1c0)) &&

       (*(int *)(param_1 + 4) == 0x2e9)) && (*(int *)(param_1 + 0xe4) != 0)) &&

     ((*(int *)(iVar1 + 0x7c) == 0 && (*(int *)(iVar1 + 0x80) == 0)))) {

    uVar2 = *param_2;

    uVar3 = param_2[1];

    fVar5 = (float10)terrain_query_z(param_2);

    *(uint *)(param_1 + 0x178) = uVar2;

    *(uint *)(param_1 + 0x17c) = uVar3;

    *(float *)(param_1 + 0x180) = (float)fVar5;

    puVar4 = *(uint **)(param_1 + 0x100);

    *puVar4 = *puVar4 & 0xffffffcf | 0xc;

    puVar4[5] = uVar2;

    puVar4[6] = uVar3;

    puVar4[7] = (uint)(float)fVar5;

    if ((*(byte *)(param_1 + 0xe0) & 1) == 0) {

      *(undefined4 *)(param_1 + 0xe4) = 10;

      *(undefined4 *)(iVar1 + 0xc4) = param_3;

      return 1;

    }

    *(undefined4 *)(iVar1 + 0xb8) = 10;

    *(undefined4 *)(iVar1 + 0xc4) = param_3;

    return 1;

  }

  return 0;

}

/* ===== FUN_0046b7f0 @ 0x0046B7F0 ===== */
undefined4 FUN_0046b7f0(int param_1,uint param_2,undefined4 param_3)



{

  uint *puVar1;

  

  puVar1 = *(uint **)(param_1 + 0x100);

  if (((*(float *)(param_1 + 0x278) < *(float *)(param_1 + 0x1c0)) && (puVar1[0x1f] == 0)) &&

     (puVar1[0x20] == 0)) {

    *puVar1 = *puVar1 | 0x3c;

    puVar1[4] = param_2;

    *(undefined4 *)(param_1 + 0xf4) = 0;

    *(undefined4 *)(param_1 + 0xf8) = param_3;

    *(undefined4 *)(param_1 + 0xe4) = 0x14;

    return 1;

  }

  return 0;

}

/* ===== FUN_0046b850 @ 0x0046B850 ===== */
undefined4 FUN_0046b850(int param_1)



{

  uint *puVar1;

  float10 fVar2;

  

  if (((*(float *)(param_1 + 0x278) < *(float *)(param_1 + 0x1c0)) &&

      (*(int *)(*(int *)(param_1 + 0x100) + 0x7c) == 0)) &&

     (*(int *)(*(int *)(param_1 + 0x100) + 0x80) == 0)) {

    fVar2 = (float10)dirfcalcp3d__FP3P3DT0(param_1 + 0xa0,DAT_00632a88 + 0xa0);

    puVar1 = *(uint **)(param_1 + 0x100);

    puVar1[0xc] = (uint)(float)fVar2;

    *puVar1 = *puVar1 & 0xffffffcb | 8;

    *(undefined4 *)(param_1 + 0xec) = 0x40a00000;

    *(undefined4 *)(param_1 + 0xe4) = 0x13;

    return 1;

  }

  return 0;

}

/* ===== cspec_0046b8d0 @ 0x0046B8D0 ===== */
void cspec_0046b8d0(int param_1)



{

  int iVar1;

  

  iVar1 = *(int *)(param_1 + 0x100);

  obj_ptr_clear_if_dead(iVar1 + 0x10);

  obj_ptr_clear_if_dead(iVar1 + 0x7c);

  obj_ptr_clear_if_dead(iVar1 + 0x80);

  obj_ptr_clear_if_dead(iVar1 + 4);

  obj_ptr_clear_if_dead(iVar1 + 0xb4);

  obj_ptr_clear_if_dead(iVar1 + 0xb0);

  obj_ptr_clear_if_dead(param_1 + 0x274);

  return;

}

/* ===== death_handler_c75 @ 0x0046B930 ===== */
void death_handler_c75(int param_1,float param_2,int param_3,uint param_4,undefined4 param_5)



{

  float fVar1;

  float fVar2;

  uint *puVar3;

  float fVar4;

  int iVar5;

  undefined4 uVar6;

  

  fVar4 = param_2;

  if (param_1 == 0xc) {

    fVar4 = param_2 * 4.0;

  }

  fVar1 = *(float *)(param_3 + 0x278);

  fVar2 = *(float *)(param_3 + 0x1c0);

  fVar4 = fVar4 + *(float *)(param_3 + 0x278);

  *(float *)(param_3 + 0x278) = fVar4;

  if (fVar4 < *(float *)(param_3 + 0x1c0)) {

    iVar5 = crt_rand_scaled(100);

    if (iVar5 < 0x32) {

      uVar6 = 0x686;

    }

    else {

      uVar6 = 0x687;

    }

    sound_play_obj(uVar6,param_3);

    wound_from_object_world(param_3,param_5);

    hurt_pusher(param_1,param_2,param_2,param_3,param_4,param_5);

    iVar5 = crt_rand_scaled(100);

    if (0x50 < iVar5) {

      if ((param_1 != 0x17) && (param_1 != 0xd)) {

        if (param_4 == 0) {

          return;

        }

        if (*(uint *)(param_4 + 0x274) != 0) {

          param_4 = *(uint *)(param_4 + 0x274);

        }

      }

      if ((((param_4 != 0) && ((*(byte *)(param_4 + 0x1d0) & 0xf) != 0)) &&

          (*(int *)(param_4 + 4) != 1)) &&

         (((iVar5 = fx_create(param_3), iVar5 != 0 &&

           (puVar3 = *(uint **)(param_3 + 0x100),

           *(float *)(param_3 + 0x278) < *(float *)(param_3 + 0x1c0))) &&

          ((puVar3[0x1f] == 0 && (puVar3[0x20] == 0)))))) {

        *puVar3 = *puVar3 | 0x3c;

        puVar3[4] = param_4;

        *(undefined4 *)(param_3 + 0xf4) = 0;

        *(undefined4 *)(param_3 + 0xf8) = 1;

        *(undefined4 *)(param_3 + 0xe4) = 0x14;

      }

    }

  }

  else {

    *(undefined4 *)(param_3 + 0x278) = *(undefined4 *)(param_3 + 0x1c0);

    blood_from_object(param_3);

    if (fVar1 < fVar2) {

      iVar5 = *(int *)(*(int *)(param_3 + 0x100) + 0xc0);

      if (iVar5 != 0) {

        fx_delete(iVar5);

      }

      *(undefined4 *)(param_3 + 0xe4) = 0x12;

      *(undefined4 *)(param_3 + 0xec) = 0x41f00000;

      iVar5 = crt_rand_scaled(100);

      if (0x31 < iVar5) {

        sound_play_3dpos(0x685,param_3 + 0xa0);

        return;

      }

      sound_play_3dpos(0x684,param_3 + 0xa0);

      return;

    }

  }

  return;

}

/* ===== kbos_attach_object @ 0x0046BAF0 ===== */
/* PS2 candidate: kbos_attach_object (conf 0.388) */



undefined4 kbos_attach_object(undefined4 param_1,int param_2,char param_3,byte param_4,int param_5)



{

  uint *puVar1;

  uint uVar2;

  int iVar3;

  int *piVar4;

  int *piVar5;

  undefined4 local_8;

  char local_4;

  byte local_3;

  

  if ((((param_2 != 0) && (*(int *)(param_2 + 4) == 3)) && (*(int *)(param_2 + 0x210) != 0)) &&

     (*(int *)(*(int *)(param_2 + 0x210) + 4) == 0x434)) {

    return 0;

  }

  if ((param_5 != 0) && (iVar3 = reaper_0052e4a0(param_1), iVar3 != 0)) {

    local_8 = *(undefined4 *)(param_2 + 0x188);

    local_4 = param_3;

    local_3 = param_4;

    reaper_00530bd0(param_1,0,1,2,5,&local_8);

  }

  *(uint *)(param_2 + 0x218) = (uint)param_4;

  piVar4 = &DAT_0055b428;

  if (-1 < DAT_0055b428) {

    iVar3 = DAT_0055b428;

    do {

      if (iVar3 == *(int *)(param_2 + 4)) break;

      iVar3 = piVar4[0xb];

      piVar4 = piVar4 + 0xb;

    } while (-1 < iVar3);

  }

  if (*piVar4 == *(int *)(param_2 + 4)) {

    if (param_3 == '\0') {

      *(float *)(param_2 + 0xc4) = *(float *)(param_2 + 0xc4) / (float)piVar4[1];

      goto LAB_0046bc13;

    }

    piVar5 = piVar4 + 5;

    iVar3 = 0;

    uVar2 = piVar4[5];

    while ((uVar2 != param_4 && (-1 < (int)uVar2))) {

      puVar1 = (uint *)(piVar5 + 1);

      piVar5 = piVar5 + 1;

      iVar3 = iVar3 + 1;

      uVar2 = *puVar1;

    }

    *(float *)(param_2 + 0xc4) = (float)piVar4[1] * *(float *)(param_2 + 0xc4);

    *(int *)(param_2 + 0x214) = piVar4[iVar3 + 2];

    if (*(int *)(param_2 + 0x10) != piVar4[iVar3 + 8]) {

      ObjectSetAnim(param_2,piVar4[iVar3 + 8],0x21,0,0,0);

      object_animate_process(param_2,0);

    }

  }

  else {

    *(undefined4 *)(param_2 + 0x214) = 0xffffffff;

  }

  if (param_3 != '\0') {

    *(undefined4 *)(param_2 + 0x210) = param_1;

    return 1;

  }

LAB_0046bc13:

  *(undefined4 *)(param_2 + 0x210) = 0;

  return 1;

}

/* ===== kbos_scan_food__FP6OBJECTP14ObjProcessInfo @ 0x0046BC60 ===== */
/* PS2 candidate: kbos_scan_food__FP6OBJECTP14ObjProcessInfo (conf 0.347) */



undefined4 kbos_scan_food__FP6OBJECTP14ObjProcessInfo(float param_1,int *param_2)



{

  float fVar1;

  int iVar2;

  uint *puVar3;

  float fVar4;

  int iVar5;

  int iVar6;

  float10 fVar7;

  float local_24;

  float local_1c;

  float local_18;

  float local_14;

  undefined1 local_10;

  float local_c;

  float local_8;

  undefined4 local_4;

  

  iVar5 = (int)param_2;

  fVar4 = param_1;

  local_24 = 0.0;

  if ((*(uint *)((int)param_2 + 0x18) & 0x100) != 0) {

    fVar1 = *(float *)(*(int *)((int)param_1 + 0x100) + 8);

    local_14 = *(float *)(*(int *)((int)param_1 + 0x100) + 8) * 40.0;

    param_2 = DAT_00632d68;

    if (DAT_00632d68 != (int *)0x0) {

      iVar6 = 0;

      do {

        iVar2 = param_2[3];

        if ((((-1 < (char)((uint)*(undefined4 *)(iVar2 + 0xd8) >> 8)) &&

             (0x45c < *(int *)(iVar2 + 4))) && (*(int *)(iVar2 + 4) < 0x460)) &&

           ((*(byte *)(iVar2 + 0xe0) & 1) != 0)) {

          local_c = *(float *)(iVar2 + 0xa0) - *(float *)((int)fVar4 + 0xa0);

          local_4 = 0;

          local_8 = *(float *)(iVar2 + 0xa4) - *(float *)((int)fVar4 + 0xa4);

          fVar7 = (float10)vec2_len(&local_c);

          param_1 = (float)fVar7;

          if (fVar7 <= (float10)(fVar1 * 300.0)) {

            local_c = local_c * (1.0 / param_1);

            local_8 = (1.0 / param_1) * local_8;

            sine_cos_lookup(*(undefined4 *)((int)fVar4 + 200),&local_1c,&local_18);

            if ((0.0 <= local_1c * local_c - local_18 * local_8) &&

               ((param_1 < local_24 || (iVar6 == 0)))) {

              local_24 = param_1;

              iVar6 = iVar2;

            }

          }

        }

        param_2 = (int *)*param_2;

      } while (param_2 != (int *)0x0);

      if (iVar6 != 0) {

        if (local_14 <= local_24) {

          if (*(int *)(iVar5 + 0x30) == 0xd) {

            return 1;

          }

          puVar3 = *(uint **)((int)fVar4 + 0x100);

          *puVar3 = *puVar3 & 0xffffffcf | 0xc;

          puVar3[5] = *(uint *)(iVar6 + 0xa0);

          puVar3[6] = *(uint *)(iVar6 + 0xa4);

          puVar3[7] = *(uint *)(iVar6 + 0xa8);

          *(undefined4 *)(iVar5 + 0x34) = 0xd;

          return 0;

        }

        if ((*(int *)(iVar5 + 4) != 0x30) || (*(int *)(iVar5 + 0x3c) < 0xb41)) {

          fVar7 = (float10)dirfcalcp3d__FP3P3DT0((int)fVar4 + 0xa0,iVar6 + 0xa0);

          param_1 = (float)fVar7;

          fVar7 = (float10)playerobj_turn(param_1,*(undefined4 *)((int)fVar4 + 200));

          if ((float10)5.0 <= ABS(fVar7)) {

            if (*(int *)(iVar5 + 0x30) == 0xe) {

              return 1;

            }

            puVar3 = *(uint **)((int)fVar4 + 0x100);

            *puVar3 = *puVar3 & 0xffffffcb | 8;

            puVar3[0xc] = (uint)param_1;

            *(undefined4 *)(iVar5 + 0x34) = 0xe;

            return 0;

          }

          if (*(int *)(iVar5 + 0x30) == 0xf) {

            return 1;

          }

          sound_play_obj(0x4ab,fVar4);

          **(uint **)((int)fVar4 + 0x100) = **(uint **)((int)fVar4 + 0x100) & 0xffffffc3;

          *(undefined4 *)(iVar5 + 8) = 0x30;

          *(undefined4 *)(iVar5 + 0x34) = 0xf;

          return 0;

        }

        param_1 = *(float *)(DAT_00632ed8 + 0x2b4);

        param_2 = *(int **)(DAT_00632ed8 + 0x2b8);

        *(undefined4 *)(DAT_00632ed8 + 0x2b4) = 0x3e99999a;

        *(undefined4 *)(DAT_00632ed8 + 0x2b8) = 0x3f666666;

        blood_from_point(iVar6 + 0xa0,0x3c,0x3c,0,0x43b40000,0x40a00000,0x41f00000,0x41200000,

                         0x42200000);

        *(float *)(DAT_00632ed8 + 0x2b4) = param_1;

        *(int **)(DAT_00632ed8 + 0x2b8) = param_2;

        iVar5 = reaper_0052e4a0(fVar4);

        if (iVar5 != 0) {

          param_1 = *(float *)(iVar6 + 0x188);

          reaper_00530bd0(fVar4,0,1,0,6,&param_1);

        }

        object_destroy(iVar6);

        iVar5 = *(int *)((int)fVar4 + 0x100);

        if (*(float *)((int)fVar4 + 0x1c0) <= *(float *)((int)fVar4 + 0x278)) {

          return 1;

        }

        if (1.0 <= *(float *)(iVar5 + 8)) {

          return 1;

        }

        if (*(int *)((int)fVar4 + 4) != 0x2e9) {

          return 1;

        }

        *(float *)(iVar5 + 8) = *(float *)(iVar5 + 8) + 0.25;

        iVar6 = reaper_0052e4a0(fVar4);

        if (iVar6 == 0) {

          return 1;

        }

        local_14 = *(float *)(iVar5 + 8);

        local_10 = 0;

        reaper_00530bd0(fVar4,1,0,1,3,&local_14);

        return 1;

      }

    }

    if ((*(int *)(iVar5 + 0x30) == 0xd) || (*(int *)(iVar5 + 0x30) == 0xe)) {

      **(uint **)((int)fVar4 + 0x100) = **(uint **)((int)fVar4 + 0x100) & 0xffffffc3;

    }

  }

  return 1;

}

/* ===== obj_3dsound_scan @ 0x0046C060 ===== */
undefined4 obj_3dsound_scan(int param_1,int param_2)



{

  float fVar1;

  uint uVar2;

  uint *puVar3;

  float fVar4;

  uint uVar5;

  int *piVar6;

  float10 fVar7;

  float local_18;

  float local_14;

  float local_10;

  float local_c;

  float local_8;

  undefined4 local_4;

  

  uVar5 = 0;

  local_18 = 0.0;

  if ((*(int *)(*(int *)(param_1 + 0x100) + 0xc4) != 0) &&

     ((*(uint *)(param_2 + 0x18) & 0x100) != 0)) {

    fVar4 = *(float *)(*(int *)(param_1 + 0x100) + 8) * 300.0;

    piVar6 = DAT_00632d68;

    if (DAT_00632d68 != (int *)0x0) {

      do {

        uVar2 = piVar6[3];

        if (((((*(uint *)(uVar2 + 0xd8) & 0x4000c000) == 0) &&

             (*(float *)(uVar2 + 0x278) < *(float *)(uVar2 + 0x1c0))) &&

            ((*(uint *)(uVar2 + 0x1c8) & 0x400000) != 0)) && ((*(byte *)(uVar2 + 0x1d0) & 0xf) != 0)

           ) {

          local_c = *(float *)(uVar2 + 0xa0) - *(float *)(param_1 + 0xa0);

          local_4 = 0;

          local_8 = *(float *)(uVar2 + 0xa4) - *(float *)(param_1 + 0xa4);

          fVar7 = (float10)vec2_lensq(&local_c);

          fVar1 = (float)fVar7;

          if (fVar7 <= (float10)(fVar4 * fVar4)) {

            local_c = local_c * (1.0 / fVar1);

            local_8 = (1.0 / fVar1) * local_8;

            sine_cos_lookup(*(undefined4 *)(param_1 + 200),&local_14,&local_10);

            if ((0.0 <= local_14 * local_c - local_10 * local_8) &&

               ((fVar1 < local_18 || (uVar5 == 0)))) {

              uVar5 = uVar2;

              local_18 = fVar1;

            }

          }

        }

        piVar6 = (int *)*piVar6;

      } while (piVar6 != (int *)0x0);

      if (uVar5 != 0) {

        puVar3 = *(uint **)(param_1 + 0x100);

        if (((*(float *)(param_1 + 0x278) < *(float *)(param_1 + 0x1c0)) && (puVar3[0x1f] == 0)) &&

           (puVar3[0x20] == 0)) {

          *puVar3 = *puVar3 | 0x3c;

          puVar3[4] = uVar2;

          *(undefined4 *)(param_1 + 0xf4) = 0;

          *(undefined4 *)(param_1 + 0xf8) = 1;

          *(undefined4 *)(param_1 + 0xe4) = 0x14;

        }

        return 0;

      }

    }

  }

  return 1;

}

/* ===== kbos_ai_main_c75 @ 0x0046C2B0 ===== */
void kbos_ai_main_c75(int param_1)



{

  uint *puVar1;

  uint uVar2;

  float fVar3;

  int iVar4;

  int iVar5;

  uint *puVar6;

  uint uVar7;

  float fVar8;

  float10 fVar9;

  float10 fVar10;

  undefined4 uVar11;

  undefined4 uVar12;

  undefined4 uVar13;

  int *piVar14;

  int iStack_184;

  float afStack_180 [2];

  int iStack_178;

  int iStack_174;

  uint uStack_170;

  undefined4 uStack_16c;

  undefined4 uStack_164;

  undefined4 uStack_160;

  float fStack_15c;

  undefined4 uStack_158;

  undefined4 uStack_154;

  undefined4 uStack_150;

  undefined4 uStack_14c;

  int iStack_148;

  int iStack_144;

  float fStack_13c;

  float fStack_138;

  float fStack_134;

  float fStack_130;

  float fStack_12c;

  float fStack_128;

  float fStack_124;

  undefined4 uStack_120;

  undefined1 uStack_11c;

  float fStack_118;

  float fStack_114;

  float fStack_110;

  float fStack_10c;

  float fStack_108;

  float fStack_104;

  float fStack_100;

  float fStack_fc;

  int aiStack_f8 [4];

  undefined4 uStack_e8;

  undefined4 uStack_e4;

  undefined4 uStack_e0;

  int aiStack_dc [4];

  undefined1 auStack_cc [12];

  undefined1 auStack_c0 [12];

  undefined1 auStack_b4 [12];

  undefined1 auStack_a8 [12];

  undefined1 auStack_9c [12];

  undefined1 auStack_90 [16];

  undefined4 uStack_80;

  undefined4 uStack_7c;

  undefined4 uStack_78;

  undefined4 uStack_4c;

  undefined4 uStack_48;

  undefined4 uStack_44;

  undefined1 auStack_1c [8];

  float fStack_14;

  

  puVar1 = *(uint **)(param_1 + 0x100);

  kbos_init(param_1);

  if (DAT_00632e74 == 0) {

    if (((~*puVar1 & 2) == 0) || (iVar4 = reaper_0052e4a0(param_1), iVar4 == 0)) {

      iVar4 = 0;

    }

    else {

      iVar4 = 1;

    }

    fStack_138 = (float)iVar4;

    if (((~*puVar1 & 2) != 0) && (iVar5 = fx_create(param_1), iVar5 == 0)) {

      fStack_138 = *(float *)(*(int *)(param_1 + 0x100) + 0x84) * 0.5;

      fVar9 = (float10)FUN_00518b70(param_1,0);

      fVar10 = (float10)FUN_00518b70(param_1,0);

      *(float *)(param_1 + 0xa0) =

           (float)(((float10)*(float *)(param_1 + 0x134) + (float10)*(float *)(param_1 + 0x128)) *

                   fVar10 * (float10)0.5 + (float10)*(float *)(param_1 + 0xa0));

      *(float *)(param_1 + 0xa4) =

           (float)(((float10)*(float *)(param_1 + 0x138) + (float10)*(float *)(param_1 + 300)) *

                   fVar10 * (float10)0.5 + (float10)*(float *)(param_1 + 0xa4));

      fVar8 = *(float *)(param_1 + 0x13c);

      *(undefined4 *)(param_1 + 0x134) = *(undefined4 *)(param_1 + 0x128);

      *(undefined4 *)(param_1 + 0x138) = *(undefined4 *)(param_1 + 300);

      *(undefined4 *)(param_1 + 0x13c) = *(undefined4 *)(param_1 + 0x130);

      *(uint *)(param_1 + 0x1c8) = *(uint *)(param_1 + 0x1c8) | 0x400;

      *(float *)(param_1 + 0xa8) =

           (float)(((float10)fVar8 + (float10)*(float *)(param_1 + 0x130)) * fVar10 * (float10)0.5 +

                  (float10)*(float *)(param_1 + 0xa8));

      PhysicsExApplyLocation(param_1);

      obj_velocity_normalize(param_1,1,0,fStack_138,fStack_138);

      object_animate_process(param_1,(float)fVar9);

      iVar4 = *(int *)(param_1 + 0x100);

      *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) | 0x40;

      if (*(float *)(iVar4 + 0xc) < *(float *)(iVar4 + 8)) {

        fVar9 = (float10)FUN_00518b70(param_1,0);

        fVar9 = fVar9 * (float10)0.1 + (float10)*(float *)(iVar4 + 0xc);

        *(float *)(iVar4 + 0xc) = (float)fVar9;

        if ((float10)*(float *)(iVar4 + 8) < fVar9) {

          *(undefined4 *)(iVar4 + 0xc) = *(undefined4 *)(iVar4 + 8);

        }

        kbos_sizer(param_1,*(undefined4 *)(iVar4 + 0xc));

      }

      func_0x0046da60(param_1);

      return;

    }

    fVar8 = fStack_124;

    if (((*puVar1 & 0x30) != 0) && (uVar7 = puVar1[4], uVar7 != 0)) {

      fVar8 = *(float *)(uVar7 + 0x1c8);

      *(uint *)(uVar7 + 0x1c8) = (uint)fVar8 | 0x800;

    }

    fVar9 = (float10)FUN_00518b70(param_1,0,iVar4);

    func_0x0046a560(param_1,afStack_180,(float)fVar9);

    if (((*puVar1 & 0x30) != 0) && (puVar1[4] != 0)) {

      *(float *)(puVar1[4] + 0x1c8) = fVar8;

    }

    do {

      iStack_178 = -1;

      uStack_14c = 0xffffffff;

      uStack_164 = 0;

      uStack_160 = 0;

      fStack_15c = 0.25;

      uStack_154 = 0;

      uStack_170 = 0x20;

      uStack_16c = 0;

      hud_icon_add_2(param_1,afStack_180);

      iVar4 = *(int *)(param_1 + 0x100);

      fStack_15c = 1.0 / (7.0 - (float)puVar1[3] * 3.0);

      if (((*(float *)(param_1 + 0x278) < *(float *)(param_1 + 0x1c0)) &&

          (iVar5 = dialog_level_is_base(), iVar5 != 0)) && (*(float *)(iVar4 + 8) < 1.0)) {

        fVar9 = (float10)FUN_00518b70(param_1,0);

        fVar9 = (float10)*(float *)(iVar4 + 0xac) - fVar9;

        *(float *)(iVar4 + 0xac) = (float)fVar9;

        if (fVar9 < (float10)0.0) {

          *(float *)(iVar4 + 0xac) = (float)(fVar9 + (float10)5.0);

          iVar4 = *(int *)(param_1 + 0x100);

          if (((*(float *)(param_1 + 0x278) < *(float *)(param_1 + 0x1c0)) &&

              (*(float *)(iVar4 + 8) < 1.0)) && (*(int *)(param_1 + 4) == 0x2e9)) {

            *(float *)(iVar4 + 8) = *(float *)(iVar4 + 8) + 0.25;

            iVar5 = reaper_0052e4a0(param_1);

            if (iVar5 != 0) {

              uStack_120 = *(undefined4 *)(iVar4 + 8);

              uStack_11c = 0;

              reaper_00530bd0(param_1,1,0,1,3,&uStack_120);

            }

          }

        }

      }

      iVar4 = *(int *)(param_1 + 0x100);

      if (*(float *)(iVar4 + 0xc) < *(float *)(iVar4 + 8)) {

        fVar9 = (float10)FUN_00518b70(param_1,0);

        fVar9 = fVar9 * (float10)0.1 + (float10)*(float *)(iVar4 + 0xc);

        *(float *)(iVar4 + 0xc) = (float)fVar9;

        if ((float10)*(float *)(iVar4 + 8) < fVar9) {

          *(undefined4 *)(iVar4 + 0xc) = *(undefined4 *)(iVar4 + 8);

        }

        iVar5 = *(int *)(param_1 + 0x100);

        fVar8 = *(float *)(iVar4 + 0xc);

        iVar4 = *(int *)(iVar5 + 4);

        if (iVar4 != 0) {

          fVar3 = fVar8 * *(float *)(iVar4 + 0x194);

          *(float *)(iVar5 + 0x88) = fVar3;

          fVar3 = fVar3 * 0.5;

          *(float *)(iVar5 + 0x84) = fVar3;

          *(float *)(iVar5 + 0x8c) = fVar3 * 0.15915494;

          *(float *)(param_1 + 0xc4) = fVar8 * *(float *)(iVar4 + 0xc4);

          obj_sub100_transform(param_1);

        }

      }

      if ((*(int *)(param_1 + 4) == 0x2e9) &&

         (*(float *)(param_1 + 0x1c0) <= *(float *)(param_1 + 0x278))) {

        **(uint **)(param_1 + 0x100) = **(uint **)(param_1 + 0x100) & 0xffffffc3;

      }

      obj_anim_flags_update(param_1,afStack_180);

      iVar5 = iStack_144;

      iVar4 = iStack_148;

      puVar1[0x24] = 0x3f800000;

      switch(uStack_150) {

      case 2:

        if (iStack_174 != 0) {

          *(undefined4 *)(param_1 + 0xec) = 0x40000000;

          goto LAB_0046c6ed;

        }

        fStack_15c = 0.0;

        iStack_178 = 10;

        break;

      case 3:

        *(undefined4 *)(param_1 + 0xec) = 0x40000000;

LAB_0046c6ed:

        uStack_170 = uStack_170 | 5;

        iStack_178 = 1;

        uStack_14c = 4;

        break;

      case 4:

        fVar8 = *(float *)(param_1 + 0xec) - afStack_180[0];

        *(float *)(param_1 + 0xec) = fVar8;

        if (fVar8 < 0.0) {

          *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) & 0xfffffffb;

          uStack_14c = 5;

        }

        break;

      case 5:

        if ((iStack_174 != 0) && (iVar4 = fx_create(param_1), iVar4 != 0)) {

          iVar4 = object_allocate_type(0x2e9,0x80000000);

          if (iVar4 != 0) {

            object_change_ospec(iVar4,0x4b);

            *(undefined4 *)(iVar4 + 0xe8) = 0;

            object_init_usage(iVar4);

            object_set_location_p3d(iVar4,param_1 + 0xa0);

            ObjectCalculateTransform(iVar4);

            PROJ_ObjectFinalize(iVar4);

            kbos_init(iVar4);

            *(undefined4 *)(iVar4 + 0x274) = *(undefined4 *)(param_1 + 0x274);

            *(undefined4 *)(iVar4 + 0x18c) = *(undefined4 *)(param_1 + 0x18c);

            FUN_0045da90(*(undefined4 *)(param_1 + 0x274),param_1,iVar4);

            uVar11 = object_allocate_type(0x2eb,0x80000000);

            object_init_usage(uVar11);

            object_set_location_p3d(uVar11,param_1 + 0xa0);

            ObjectCalculateTransform(uVar11);

            PROJ_ObjectFinalize(uVar11);

            kbos_init(uVar11);

            iStack_184 = 0xf;

            do {

              uVar11 = object_allocate_type(0x2ec,0x80000000);

              object_init_usage(uVar11);

              object_set_location_p3d(uVar11,param_1 + 0xa0);

              ObjectCalculateTransform(uVar11);

              PROJ_ObjectFinalize(uVar11);

              kbos_init(uVar11);

              iStack_184 = iStack_184 + -1;

            } while (iStack_184 != 0);

            iVar5 = reaper_0052e4a0(param_1);

            if (iVar5 != 0) {

              uStack_e8 = *(undefined4 *)(param_1 + 0xa4);

              aiStack_f8[3] = *(undefined4 *)(param_1 + 0xa0);

              uStack_e4 = *(undefined4 *)(param_1 + 0xa8);

              piVar14 = aiStack_f8 + 3;

              uVar13 = 2;

              uStack_e0 = *(undefined4 *)(iVar4 + 0x188);

              uVar12 = 1;

              uVar11 = 3;

LAB_0046d980:

              reaper_00530bd0(param_1,uVar11,uVar12,0,uVar13,piVar14);

            }

          }

LAB_0046d989:

          object_destroy(param_1);

        }

        break;

      case 6:

        if (iStack_174 == 0) {

          uStack_170 = uStack_170 | 1;

          iStack_178 = 0x28;

        }

        else {

          iVar4 = crt_rand_scaled(100);

          if (iVar4 < 0x1e) {

            iStack_178 = 0x29;

            uStack_14c = 7;

          }

        }

        break;

      case 7:

        if (iStack_174 != 0) {

          uVar11 = 0x40400000;

LAB_0046cbbd:

          fVar9 = (float10)rndfloatrange(uVar11,0x40a00000);

          *(float *)(param_1 + 0xec) = (float)fVar9;

          uStack_14c = 8;

        }

        break;

      case 8:

        iVar4 = kbos_scan_food__FP6OBJECTP14ObjProcessInfo(param_1,afStack_180);

        if ((iVar4 != 0) && (iVar4 = obj_3dsound_scan(param_1,afStack_180), iVar4 != 0)) {

          fVar8 = *(float *)(param_1 + 0xec) - afStack_180[0];

          *(float *)(param_1 + 0xec) = fVar8;

          if (fVar8 < 0.0 == (fVar8 == 0.0)) {

            if (0.5 <= (float)puVar1[3]) {

              uStack_170 = uStack_170 | 1;

              iStack_178 = 0x46;

            }

            else {

              uStack_170 = uStack_170 | 1;

              iStack_178 = 0x2a;

            }

          }

          else {

            iVar4 = crt_rand_scaled(100);

            if (iVar4 < 0x32) {

              fStack_114 = (float)puVar1[2] * 40.0;

              fStack_13c = (float)puVar1[2] * 80.0;

              do {

                fVar9 = (float10)rndfloatrange(fStack_114,fStack_13c);

                fVar10 = (float10)rndfloat(0x43b40000);

                fStack_128 = (float)fVar10;

                sine_cos_lookup(fStack_128,&fStack_124,&fStack_118);

                fStack_12c = *(float *)(param_1 + 0x180);

                fStack_134 = fStack_118 * (float)fVar9 + *(float *)(param_1 + 0x178);

                fStack_130 = fStack_124 * (float)fVar9 + *(float *)(param_1 + 0x17c);

                fVar9 = (float10)terrain_query_z(&fStack_134);

                fStack_12c = (float)fVar9;

                fVar9 = (float10)distance2d__FP3P3DT0(param_1 + 0xa0,&fStack_134);

              } while (fVar9 < (float10)(float)puVar1[2] * (float10)40.0);

              puVar6 = *(uint **)(param_1 + 0x100);

              *puVar6 = *puVar6 & 0xffffffcf | 0xc;

              puVar6[5] = (uint)fStack_134;

              puVar6[6] = (uint)fStack_130;

              puVar6[7] = (uint)fStack_12c;

              uStack_14c = 10;

            }

            else if (0.5 <= (float)puVar1[3]) {

              aiStack_f8[0] = 0x51;

              aiStack_f8[1] = 0x50;

              aiStack_f8[2] = 0x52;

              iVar4 = crt_rand_scaled(3);

              iStack_178 = aiStack_f8[iVar4];

              uStack_14c = 9;

            }

            else {

              aiStack_dc[0] = 0x35;

              aiStack_dc[1] = 0x36;

              aiStack_dc[2] = 0x37;

              aiStack_dc[3] = 0x2f;

              iVar4 = crt_rand_scaled(4);

              iStack_178 = aiStack_dc[iVar4];

              uStack_14c = 9;

            }

          }

        }

        break;

      case 9:

        iVar4 = kbos_scan_food__FP6OBJECTP14ObjProcessInfo(param_1,afStack_180);

        if ((iVar4 == 0) || (iVar4 = obj_3dsound_scan(param_1,afStack_180), iVar4 == 0)) {

          fVar9 = (float10)FUN_00518b70(param_1,0);

          fVar9 = (float10)*(float *)(param_1 + 0xf0) - fVar9;

          *(float *)(param_1 + 0xf0) = (float)fVar9;

          if (fVar9 < (float10)0.0) {

            fVar9 = (float10)rndfloatrange(0x41700000,0x41f00000);

            *(float *)(param_1 + 0xf0) = (float)fVar9;

            iVar4 = crt_rand_scaled(100);

            if (iVar4 < 0x32) {

              sound_play_obj(0x4b3,param_1);

            }

            else {

              sound_play_obj(0x4b4,param_1);

            }

          }

        }

        else if (iStack_174 != 0) {

LAB_0046cbb7:

          uVar11 = 0x3f800000;

          goto LAB_0046cbbd;

        }

        break;

      case 10:

        iVar4 = kbos_scan_food__FP6OBJECTP14ObjProcessInfo(param_1,afStack_180);

        if ((iVar4 != 0) && (iVar4 = obj_3dsound_scan(param_1,afStack_180), iVar4 != 0)) {

          if ((~*puVar1 & 0xc0) == 0) {

            iVar4 = crt_rand_scaled(5);

            if ((iVar4 == 0) || ((float)puVar1[3] < 0.5)) goto LAB_0046cbb7;

            iStack_178 = iVar4 + 0x4a;

            uStack_14c = 9;

          }

          else {

            gfx_d3d_0046aa30(param_1,afStack_180);

          }

        }

        break;

      case 0xb:

        obj_anim_flags_update(param_1,afStack_180);

        if (puVar1[0x2d] == 0) {

          fVar9 = (float10)FUN_00518b70(param_1,0);

          fVar9 = (float10)(float)puVar1[0x2f] - fVar9;

          puVar1[0x2f] = (uint)(float)fVar9;

          if (fVar9 < (float10)0.0 != (fVar9 == (float10)0.0)) {

            *(uint *)(param_1 + 0xe4) = puVar1[0x2e];

            *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xfffffffe;

            *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) & 0xbfffffff;

            *(uint *)(puVar1[0x2c] + 0xd8) = *(uint *)(puVar1[0x2c] + 0xd8) & 0xbfffffff;

            gfx_d3d_0046aa30(param_1,afStack_180);

            fx_delete(puVar1[0x30]);

            puVar1[0x30] = 0;

            iVar4 = reaper_0052e4a0(param_1);

            if (iVar4 != 0) {

              reaper_00530bd0(param_1,0,0,0,10,0);

              puVar1[0x2d] = 0;

              break;

            }

          }

        }

        else {

          puVar1[0x2f] = 0x3f800000;

        }

        puVar1[0x2d] = 0;

        break;

      case 0xc:

        obj_anim_flags_update(param_1,afStack_180);

        ground_height_at(param_1 + 0xa0,auStack_1c);

        if (fStack_14 < 0.64278) {

          puVar1[0x2f] = 0x3f800000;

        }

        else {

          fVar9 = (float10)FUN_00518b70(param_1,0);

          fVar9 = (float10)(float)puVar1[0x2f] - fVar9;

          puVar1[0x2f] = (uint)(float)fVar9;

          if (fVar9 < (float10)0.0 != (fVar9 == (float10)0.0)) {

            *(uint *)(param_1 + 0xe4) = puVar1[0x2e];

            *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xfffffffe;

            *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) & 0xbfffffff;

            *(uint *)(puVar1[0x2c] + 0xd8) = *(uint *)(puVar1[0x2c] + 0xd8) & 0xbfffffff;

            gfx_d3d_0046aa30(param_1,afStack_180);

            fx_delete(puVar1[0x30]);

            puVar1[0x30] = 0;

            iVar4 = reaper_0052e4a0(param_1);

            if (iVar4 != 0) {

              reaper_00530bd0(param_1,0,0,0,10,0);

            }

          }

        }

        break;

      case 0xd:

      case 0xe:

        iVar4 = kbos_scan_food__FP6OBJECTP14ObjProcessInfo(param_1,afStack_180);

        if (iVar4 != 0) {

          if ((~*puVar1 & 0xc0) == 0) {

            *(undefined4 *)(param_1 + 0xec) = 0x3f800000;

            uStack_14c = 8;

          }

          else {

            gfx_d3d_0046aa30(param_1,afStack_180);

          }

        }

        break;

      case 0xf:

        iVar4 = kbos_scan_food__FP6OBJECTP14ObjProcessInfo(param_1,afStack_180);

        if ((iVar4 != 0) && (iStack_174 != 0)) {

          uStack_14c = 8;

        }

        break;

      case 0x10:

        iVar4 = kbos_scan_food__FP6OBJECTP14ObjProcessInfo(param_1,afStack_180);

        if (iVar4 != 0) {

          if ((~*puVar1 & 0xc0) != 0) goto LAB_0046d1a5;

          *(undefined4 *)(param_1 + 0xec) = 0x41200000;

          uStack_14c = 0x11;

        }

        break;

      case 0x11:

        fVar8 = *(float *)(param_1 + 0xec) - afStack_180[0];

        *(float *)(param_1 + 0xec) = fVar8;

        if (fVar8 < 0.0 == (fVar8 == 0.0)) {

          iVar4 = kbos_scan_food__FP6OBJECTP14ObjProcessInfo(param_1,afStack_180);

          if (iVar4 != 0) {

            iStack_178 = 0x32;

            uStack_170 = uStack_170 | 1;

          }

        }

        else {

          uStack_14c = 8;

        }

        break;

      case 0x12:

        iStack_178 = 0x56;

      case 0x1c:

        *(undefined4 *)(param_1 + 0xec) = 0x41f00000;

        uStack_14c = 0x1d;

        break;

      case 0x13:

        fVar8 = *(float *)(param_1 + 0xec) - afStack_180[0];

        *(float *)(param_1 + 0xec) = fVar8;

        if (fVar8 < 0.0 == (fVar8 == 0.0)) {

          uStack_170 = uStack_170 | 1;

          iStack_178 = 0x5f;

        }

        else {

          *(undefined4 *)(param_1 + 0xec) = 0x3f800000;

          uStack_14c = 8;

        }

        break;

      case 0x14:

        if (puVar1[4] == 0) {

LAB_0046d390:

          puVar6 = *(uint **)(param_1 + 0x100);

LAB_0046d396:

          *puVar6 = *puVar6 & 0xffffffc3;

LAB_0046d399:

          iStack_178 = 0x4b;

          uStack_14c = 9;

        }

        else {

          playerobj_eval_refpt(param_1,1,auStack_cc);

          bbox_center_calc(auStack_c0,puVar1[4]);

          fVar9 = (float10)FUN_0050a610(auStack_cc,auStack_c0);

          fStack_13c = (float)fVar9;

          fVar8 = (float)puVar1[3] * 120.0 * (float)puVar1[3] * 120.0;

          if ((fVar8 <= fStack_13c) ||

             (((~*puVar1 & 8) == 0 &&

              (((float)puVar1[0xe] <= -10.0 || (10.0 <= (float)puVar1[0xe])))))) {

LAB_0046d1a5:

            gfx_d3d_0046aa30(param_1,afStack_180);

            puVar1[0x24] = 0x40000000;

          }

          else if (fVar8 * 0.25 <= fStack_13c) {

            *puVar1 = *puVar1 & 0xfffffffb;

            fStack_128 = SQRT(fStack_13c / fVar8) * 0.5;

            *(float *)(param_1 + 0xec) = fStack_128;

            trajectory_calculate(param_1 + 0x128,auStack_cc,auStack_c0,puVar1 + 0x25,fStack_128);

            *(undefined4 *)(*(int *)(param_1 + 0x104) + 0x1c) = 0;

            *(undefined4 *)(*(int *)(param_1 + 0x104) + 0x18) = 0;

            iStack_178 = 0x5c;

            uStack_14c = 0x15;

            *(float *)(*(int *)(param_1 + 0x104) + 0x20) =

                 *(float *)(*(int *)(param_1 + 0x104) + 4) * -32.17405;

          }

          else {

            if (400.0 <= fStack_13c) goto LAB_0046d1a5;

            iVar4 = kbos_attach_object(param_1,puVar1[4],1,1,1);

            if (iVar4 == 0) goto LAB_0046d299;

            puVar1[0x20] = puVar1[4];

            **(uint **)(param_1 + 0x100) = **(uint **)(param_1 + 0x100) & 0xffffffc3;

            if (*(int *)(param_1 + 0xf8) == 0) {

              iStack_178 = 0x5d;

              uStack_14c = 0x16;

            }

            else {

              iStack_178 = 0x60;

              uStack_14c = 0x17;

            }

            uStack_170 = uStack_170 | 0x80;

            uStack_158 = 0;

            puVar1[4] = 0;

          }

        }

        break;

      case 0x15:

        if (puVar1[4] == 0) {

          if (puVar1[0x20] == 0) goto LAB_0046d703;

          if ((**(byte **)(param_1 + 0x104) & 0x94) != 0) {

            if (*(int *)(param_1 + 0xf8) == 0) {

              iStack_178 = 0x5d;

              uStack_14c = 0x16;

            }

            else {

              iStack_178 = 0x60;

              uStack_14c = 0x17;

            }

            uStack_170 = uStack_170 | 0x80;

            uStack_158 = 0;

          }

        }

        else {

          fVar8 = *(float *)(param_1 + 0xec) - afStack_180[0];

          *(float *)(param_1 + 0xec) = fVar8;

          if (0.12 < fVar8) {

            playerobj_eval_refpt(param_1,1,auStack_b4);

            bbox_center_calc(auStack_a8,puVar1[4]);

            trajectory_calculate

                      (param_1 + 0x128,auStack_b4,auStack_a8,puVar1 + 0x25,

                       *(undefined4 *)(param_1 + 0xec));

            *(undefined4 *)(*(int *)(param_1 + 0x104) + 0x1c) = 0;

            *(undefined4 *)(*(int *)(param_1 + 0x104) + 0x18) = 0;

            *(float *)(*(int *)(param_1 + 0x104) + 0x20) =

                 *(float *)(*(int *)(param_1 + 0x104) + 4) * -32.17405;

          }

          fVar9 = (float10)ObjectGetWorldRefPoint__FP3P3DiP6OBJECT(param_1,1,puVar1[4]);

          if ((float10)400.0 <= fVar9) {

            if ((**(char **)(param_1 + 0x104) < '\0') &&

               (*(float *)(param_1 + 0xec) < 0.0 != (*(float *)(param_1 + 0xec) == 0.0))) {

              fVar8 = *(float *)(param_1 + 0xf4);

              *(float *)(param_1 + 0xf4) = *(float *)(param_1 + 0xf4) + 1.0;

              puVar6 = *(uint **)(param_1 + 0x100);

              if (0.0 <= fVar8) goto LAB_0046d396;

              uVar7 = puVar1[4];

              *puVar6 = *puVar6 | 0x3c;

              puVar6[4] = uVar7;

              uStack_14c = 0x14;

            }

          }

          else {

            iVar4 = kbos_attach_object(param_1,puVar1[4],1,1,1);

            if (iVar4 == 0) {

LAB_0046d299:

              **(uint **)(param_1 + 0x100) = **(uint **)(param_1 + 0x100) & 0xffffffc3;

              iStack_178 = 0x4b;

              uStack_14c = 9;

              puVar1[4] = 0;

            }

            else {

              puVar1[0x20] = puVar1[4];

              puVar1[4] = 0;

            }

          }

        }

        break;

      case 0x16:

        if (iStack_144 < 0xf00) {

          fVar8 = 3.0;

        }

        else {

          fVar8 = 30.0;

        }

        puVar1[0x29] = (uint)(*(float *)(param_1 + 400) * fVar8);

        if ((0x13f < iStack_144) && (iStack_148 < 0x140)) {

          uStack_80 = *(undefined4 *)(param_1 + 0xa0);

          uStack_7c = *(undefined4 *)(param_1 + 0xa4);

          uStack_78 = *(undefined4 *)(param_1 + 0xa8);

          fx_get_free_effect__Fv();

        }

        uVar7 = DAT_00632a88;

        if (puVar1[0x20] == 0) {

          if (puVar1[0x1f] == 0) goto LAB_0046d703;

          if (iStack_174 != 0) {

            puVar6 = *(uint **)(param_1 + 0x100);

            *puVar6 = *puVar6 | 0x3c;

            puVar6[4] = uVar7;

            uStack_14c = 0x18;

          }

        }

        else {

          if ((0xeff < iVar5) && (iVar4 < 0x2620)) {

            playerobj_eval_refpt(param_1,1,auStack_90);

            blood_from_point(auStack_90,0x1e,0x32,*(float *)(param_1 + 200) - 90.0,

                             *(float *)(param_1 + 200) + 90.0,0x41200000,0x42340000,0,0x41700000);

          }

          if ((0x2b1f < iVar5) && (iVar4 < 0x2b20)) {

            kbos_attach_object(param_1,puVar1[0x20],1,3,1);

            puVar1[0x1f] = puVar1[0x20];

            puVar1[0x20] = 0;

            **(uint **)(param_1 + 0x100) = **(uint **)(param_1 + 0x100) & 0xffffffc3;

          }

        }

        break;

      case 0x17:

        if ((0x13f < iStack_144) && (iStack_148 < 0x140)) {

          uStack_4c = *(undefined4 *)(param_1 + 0xa0);

          uStack_48 = *(undefined4 *)(param_1 + 0xa4);

          uStack_44 = *(undefined4 *)(param_1 + 0xa8);

          fx_get_free_effect__Fv();

        }

        if (puVar1[0x20] == 0) {

LAB_0046d703:

          iVar4 = crt_rand_scaled(100);

          if (iVar4 < 0x32) {

            uVar11 = 0x68a;

          }

          else {

            uVar11 = 0x68b;

          }

          sound_play_obj(uVar11,param_1);

          goto LAB_0046d390;

        }

        if ((0xeff < iVar5) && (iVar4 < 0x21c0)) {

          playerobj_eval_refpt(param_1,1,auStack_9c);

          blood_from_point(auStack_9c,0x1e,0x32,*(float *)(param_1 + 200) - 90.0,

                           *(float *)(param_1 + 200) + 90.0,0x41200000,0x42340000,0,0x41700000);

        }

        if ((0x27ff < iVar5) && (iVar4 < 0x2800)) {

          iVar4 = crt_rand_scaled(100);

          if (iVar4 < 0x32) {

            uVar11 = 0x68a;

          }

          else {

            uVar11 = 0x68b;

          }

          sound_play_obj(uVar11,param_1);

          kbos_attach_object(param_1,puVar1[0x20],0,3,1);

          obj_damage_apply(0x15,0x461c4000,puVar1[0x20],param_1,0,0);

          puVar1[0x20] = 0;

          **(uint **)(param_1 + 0x100) = **(uint **)(param_1 + 0x100) & 0xffffffc3;

          iStack_178 = 0x4c;

          uStack_14c = 9;

        }

        break;

      case 0x18:

        if (puVar1[0x1f] == 0) goto LAB_0046d703;

        if ((float)puVar1[3] * 150.0 <= (float)puVar1[0xd]) {

          gfx_d3d_0046aa30(param_1,afStack_180);

          puVar1[0x24] = 0x3f800000;

        }

        else {

          *puVar1 = *puVar1 & 0xfffffffb;

          uStack_170 = uStack_170 | 1;

          *(undefined4 *)(param_1 + 0x178) = *(undefined4 *)(param_1 + 0xa0);

          *(undefined4 *)(param_1 + 0x17c) = *(undefined4 *)(param_1 + 0xa4);

          iStack_178 = 0x5e;

          *(undefined4 *)(param_1 + 0x180) = *(undefined4 *)(param_1 + 0xa8);

          *(undefined4 *)(param_1 + 0xec) = 0x3f800000;

          uStack_14c = 0x19;

        }

        break;

      case 0x19:

        if (puVar1[0x1f] == 0) goto LAB_0046d390;

        if ((((~*puVar1 & 8) != 0) || ((-5.0 < (float)puVar1[0xe] && ((float)puVar1[0xe] < 5.0))))

           && (fVar8 = *(float *)(param_1 + 0xec) - afStack_180[0],

              *(float *)(param_1 + 0xec) = fVar8, fVar8 < 0.0)) {

          uStack_14c = 0x1a;

        }

        break;

      case 0x1a:

        uVar7 = puVar1[0x1f];

        if (uVar7 == 0) {

          if ((iStack_144 < 0x8c0) || (iStack_174 != 0)) goto LAB_0046d399;

        }

        else {

          uStack_170 = uStack_170 | 0x80;

          iStack_178 = 0x5b;

          uStack_158 = 0;

          if ((0x8bf < iStack_144) && (iStack_148 < 0x8c0)) {

            uVar2 = puVar1[4];

            fStack_110 = (*(float *)(uVar2 + 0xa0) - *(float *)(uVar7 + 0xa0)) * 0.75;

            fStack_10c = (*(float *)(uVar2 + 0xa4) - *(float *)(uVar7 + 0xa4)) * 0.75;

            fStack_108 = (*(float *)(uVar2 + 0xa8) - *(float *)(uVar7 + 0xa8)) * 0.75;

            vec3_len(&fStack_110);

            fStack_104 = fStack_110 + *(float *)(uVar7 + 0xa0);

            fStack_100 = fStack_10c + *(float *)(uVar7 + 0xa4);

            fVar9 = (float10)terrain_query_z(&fStack_104);

            fStack_fc = (float)fVar9;

            kbos_attach_object(param_1,uVar7,0,3,1);

            object_set_location_p3d(uVar7,&fStack_104);

            puVar1[0x1f] = 0;

          }

        }

        break;

      case 0x1b:

        if ((**(byte **)(param_1 + 0x104) & 4) != 0) {

          uStack_14c = 0x1c;

        }

        break;

      case 0x1d:

        *(float *)(param_1 + 0x278) = *(float *)(param_1 + 0x1c0);

        if (*(float *)(param_1 + 0x1c0) <= *(float *)(param_1 + 0x1c0)) {

          fVar9 = (float10)FUN_00518b70(param_1,0);

          fVar9 = (float10)*(float *)(param_1 + 0xec) - fVar9;

          *(float *)(param_1 + 0xec) = (float)fVar9;

          if (fVar9 < (float10)0.0 != (fVar9 == (float10)0.0)) {

            *(undefined4 *)(param_1 + 0xec) = 0;

          }

          if (*(float *)(param_1 + 0xec) < 2.0 != (*(float *)(param_1 + 0xec) == 2.0)) {

            *(float *)(param_1 + 0x184) = 1.0 - *(float *)(param_1 + 0xec) * 0.5;

          }

          if (*(float *)(param_1 + 0xec) == 0.0) {

            if ((fStack_138 != 0.0) && (iVar4 = reaper_0052e4a0(param_1), iVar4 != 0)) {

              piVar14 = (int *)0x0;

              uVar13 = 7;

              uVar12 = 0;

              uVar11 = 0;

              goto LAB_0046d980;

            }

            goto LAB_0046d989;

          }

        }

      }

      uVar7 = reaper_lock_short_2(param_1,afStack_180,fStack_138);

    } while ((uVar7 & 2) != 0);

    iVar4 = *(int *)(param_1 + 0x100);

    *(undefined1 *)(param_1 + 0x20a) = 0x20;

    obj_bone_update(param_1,*(undefined4 *)(iVar4 + 0x2c),0,*(undefined4 *)(iVar4 + 0xa4),

                    *(undefined4 *)(iVar4 + 0xa8),0);

  }

  return;

}

/* ===== kbos_death_handler_c75 @ 0x0046DAF0 ===== */
void kbos_death_handler_c75(int param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)



{

  uint *puVar1;

  float fVar2;

  char cVar3;

  float fVar4;

  undefined4 *puVar5;

  undefined4 uVar6;

  int iVar7;

  int iVar8;

  undefined4 uStack_3c;

  char cStack_38;

  undefined4 uStack_24;

  undefined4 uStack_20;

  int iStack_1c;

  

  puVar5 = param_4;

  kbos_init(param_1);

  iVar8 = *(int *)(param_1 + 0x100);

  switch(param_2) {

  case 0:

    *(undefined4 *)(param_1 + 0xa0) = *param_4;

    *(undefined4 *)(param_1 + 0xa4) = param_4[1];

    *(undefined4 *)(param_1 + 0xa8) = param_4[2];

    *(undefined4 *)(param_1 + 0x128) = param_4[3];

    *(undefined4 *)(param_1 + 300) = param_4[4];

    *(undefined4 *)(param_1 + 0x130) = param_4[5];

    *(undefined4 *)(param_1 + 0x114) = param_4[6];

    *(undefined4 *)(param_1 + 200) = param_4[7];

    return;

  case 1:

    *(undefined4 *)(param_1 + 0x128) = *param_4;

    *(undefined4 *)(param_1 + 300) = param_4[1];

    *(undefined4 *)(param_1 + 0x130) = param_4[2];

    *(undefined4 *)(param_1 + 200) = param_4[3];

    return;

  case 2:

    iVar8 = object_allocate_type(0x2e9,0x80000000);

    if (iVar8 != 0) {

      object_change_ospec(iVar8,0x4b);

      *(undefined4 *)(iVar8 + 0xe8) = 0;

      object_init_usage(iVar8);

      object_set_location_p3d(iVar8,param_4);

      ObjectCalculateTransform(iVar8);

      PROJ_ObjectFinalize(iVar8);

      kbos_init(iVar8);

      *(undefined4 *)(iVar8 + 0x274) = *(undefined4 *)(param_1 + 0x274);

      *(undefined4 *)(iVar8 + 0x18c) = *(undefined4 *)(param_1 + 0x18c);

      FUN_0045da90(*(undefined4 *)(param_1 + 0x274),param_1,iVar8);

      uVar6 = object_allocate_type(0x2eb,0x80000000);

      object_init_usage(uVar6);

      object_set_location_p3d(uVar6,param_4);

      ObjectCalculateTransform(uVar6);

      PROJ_ObjectFinalize(uVar6);

      kbos_init(uVar6);

      param_4 = (undefined4 *)0xf;

      do {

        uVar6 = object_allocate_type(0x2ec,0x80000000);

        object_init_usage(uVar6);

        object_set_location_p3d(uVar6,puVar5);

        ObjectCalculateTransform(uVar6);

        PROJ_ObjectFinalize(uVar6);

        kbos_init(uVar6);

        param_4 = (undefined4 *)((int)param_4 + -1);

      } while (param_4 != (undefined4 *)0x0);

      *(undefined4 *)(iVar8 + 0x188) = puVar5[3];

    }

  case 7:

    object_destroy(param_1);

    return;

  case 3:

    cVar3 = *(char *)(param_4 + 1);

    if (*(int *)(param_1 + 4) == 0x2e9) {

      *(undefined4 *)(iVar8 + 8) = *param_4;

      iVar7 = reaper_0052e4a0(param_1);

      if (iVar7 != 0) {

        uStack_3c = *(undefined4 *)(iVar8 + 8);

        cStack_38 = cVar3;

        reaper_00530bd0(param_1,1,0,1,3,&uStack_3c);

      }

      if (cVar3 != '\0') {

        fVar2 = *(float *)(iVar8 + 8);

        *(float *)(iVar8 + 0xc) = fVar2;

        iVar8 = *(int *)(param_1 + 0x100);

        iVar7 = *(int *)(iVar8 + 4);

        if (iVar7 != 0) {

          fVar4 = fVar2 * *(float *)(iVar7 + 0x194);

          *(float *)(iVar8 + 0x88) = fVar4;

          fVar4 = fVar4 * 0.5;

          *(float *)(iVar8 + 0x84) = fVar4;

          *(float *)(iVar8 + 0x8c) = fVar4 * 0.15915494;

          *(float *)(param_1 + 0xc4) = fVar2 * *(float *)(iVar7 + 0xc4);

          obj_sub100_transform(param_1);

          return;

        }

      }

    }

    break;

  case 4:

    ObjectSetAnim(param_1,param_4[2],param_4[3],param_4[4],*param_4,param_4[1]);

    return;

  case 5:

    iVar8 = objanim_select_animloop(*param_4);

    if (iVar8 != 0) {

      kbos_attach_object(param_1,iVar8,*(undefined1 *)(param_4 + 1),

                         *(undefined1 *)((int)param_4 + 5),0);

      return;

    }

    break;

  case 6:

    iVar8 = objanim_select_animloop(*param_4);

    if (iVar8 != 0) {

      object_destroy(iVar8);

      return;

    }

    break;

  case 8:

    if (*(int *)(param_1 + 0x1e0) == 0x4b) {

      iVar8 = reaper_0052e4a0(param_1);

      if (iVar8 != 0) {

        reaper_00530bd0(param_1,0,0,0,8,0);

      }

      if ((*(int *)(param_1 + 0xe4) != 0x12) && (*(int *)(param_1 + 0xe4) != 0x1d)) {

        *(undefined4 *)(param_1 + 0x278) = *(undefined4 *)(param_1 + 0x1c0);

        *(undefined4 *)(param_1 + 0xec) = 0x41f00000;

        *(uint *)(param_1 + 0xe4) = ((*(int *)(param_1 + 4) != 0x2e9) - 1 & 0xfffffff5) + 0x1d;

        return;

      }

    }

    break;

  case 9:

    iStack_1c = param_1;

    uStack_20 = 0xffffffff;

    uStack_24 = 8;

    uVar6 = fx_get_free_effect__Fv();

    *(undefined4 *)(iVar8 + 0xc0) = uVar6;

    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 1;

    *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) | 0x40000000;

    *(uint *)(*(int *)(iVar8 + 0xb0) + 0xd8) = *(uint *)(*(int *)(iVar8 + 0xb0) + 0xd8) | 0x40000000

    ;

    return;

  case 10:

    *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) & 0xbfffffff;

    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xfffffffe;

    puVar1 = (uint *)(*(int *)(iVar8 + 0xb0) + 0xd8);

    *puVar1 = *puVar1 & 0xbfffffff;

    fx_delete(*(undefined4 *)(iVar8 + 0xc0));

    *(undefined4 *)(iVar8 + 0xc0) = 0;

    return;

  }

  return;

}

/* ===== cspec_0046df40 @ 0x0046DF40 ===== */
undefined4 cspec_0046df40(void)



{

  return 0x70;

}

/* ===== cspec_0046df50 @ 0x0046DF50 ===== */
undefined4 cspec_0046df50(int param_1,int param_2)



{

  undefined4 uVar1;

  int iVar2;

  char *pcVar3;

  undefined4 uVar4;

  undefined1 *puVar5;

  undefined1 auStack_34 [16];

  undefined4 uStack_24;

  undefined4 uStack_20;

  int iStack_1c;

  

  iVar2 = *(int *)(param_1 + 0x100);

  if ((param_2 != 0) && ((*(uint *)(param_2 + 0xd8) & 0x4000c000) == 0)) {

    if ((*(uint *)(param_1 + 0xe0) & 1) != 0) {

      *(int *)(iVar2 + 0xb4) = param_2;

      return 1;

    }

    if (*(int *)(param_2 + 0x1e0) == 0x3c) {

      *(int *)(param_2 + 0x220) = param_1;

    }

    else if ((*(uint *)(param_2 + 0x1c8) & 0x800) == 0) {

      if ((*(uint *)(param_2 + 0x1c8) & 0x400000) == 0) {

        *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 1;

        *(undefined4 *)(iVar2 + 0xb8) = *(undefined4 *)(param_1 + 0xe4);

        *(undefined4 *)(iVar2 + 0xbc) = 0x3f800000;

        *(undefined4 *)(param_1 + 0xe4) = 0xb;

        *(int *)(iVar2 + 0xb4) = param_2;

        puVar5 = auStack_34;

        uVar4 = 0x24;

        pcVar3 = s_fx_ripper_dirt_0055b4d8;

        iStack_1c = param_1;

        uStack_20 = 0xffffffff;

        uStack_24 = 8;

        uVar1 = fx_get_free_effect__Fv();

        *(undefined4 *)(iVar2 + 0xc0) = uVar1;

        *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) | 0x40000000;

        *(uint *)(*(int *)(iVar2 + 0xb0) + 0xd8) =

             *(uint *)(*(int *)(iVar2 + 0xb0) + 0xd8) | 0x40000000;

        iVar2 = reaper_0052e4a0(param_1,pcVar3,uVar4,puVar5);

        if (iVar2 != 0) {

          reaper_00530bd0(param_1,0,0,0,9,0);

        }

      }

      return 1;

    }

  }

  return 0;

}

/* ===== cspec_0046e070 @ 0x0046E070 ===== */
int cspec_0046e070(int param_1,int param_2)



{

  int iVar1;

  int iVar2;

  undefined4 uStack_8;

  undefined4 uStack_4;

  

  iVar1 = fx_create(param_1);

  if (iVar1 == 0) {

    return 1;

  }

  iVar1 = *(int *)(param_1 + 0x100);

  if (((iVar1 != 0) && (*(code **)(iVar1 + 0x48) != (code *)0x0)) && (*(int *)(iVar1 + 0x44) != 0))

  {

    iVar1 = (**(code **)(iVar1 + 0x48))(param_1,*(int *)(iVar1 + 0x44),param_2);

    if (iVar1 == 0) {

      iVar2 = reaper_0052e4a0(param_1);

      if (iVar2 != 0) {

        uStack_8 = *(undefined4 *)(param_1 + 0x188);

        uStack_4 = 0;

        if (param_2 != 0) {

          uStack_4 = *(undefined4 *)(param_2 + 0x188);

        }

        reaper_00530bd0(param_1,0,2,0,3,&uStack_8);

      }

    }

    return iVar1;

  }

  return 1;

}

/* ===== reaper_ospec_ptr48_set @ 0x0046E120 ===== */
void reaper_ospec_ptr48_set(int param_1,undefined4 param_2)



{

  if ((param_1 != 0) && (*(int *)(param_1 + 0x100) != 0)) {

    *(undefined4 *)(*(int *)(param_1 + 0x100) + 0x48) = param_2;

  }

  return;

}

/* ===== projectile_motion_c76 @ 0x0046E170 ===== */
void projectile_motion_c76(int param_1)



{

  float fVar1;

  undefined4 *puVar2;

  bool bVar3;

  int iVar4;

  undefined4 *puVar5;

  float10 fVar6;

  undefined1 *puVar7;

  undefined4 uVar8;

  undefined4 uVar9;

  undefined4 uStack_f0;

  undefined4 uStack_ec;

  float fStack_e8;

  undefined4 uStack_e4;

  undefined4 uStack_e0;

  undefined4 uStack_dc;

  undefined4 uStack_d8;

  undefined4 uStack_d4;

  float fStack_d0;

  undefined1 auStack_cc [68];

  undefined1 auStack_88 [68];

  undefined1 auStack_44 [68];

  

  puVar2 = *(undefined4 **)(param_1 + 0x100);

  if ((~puVar2[0x10] & 1) != 0) {

    puVar5 = puVar2;

    for (iVar4 = 0x1c; iVar4 != 0; iVar4 = iVar4 + -1) {

      *puVar5 = 0;

      puVar5 = puVar5 + 1;

    }

    *(undefined4 **)(param_1 + 0x104) = puVar2;

    *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) & 0xffffffef;

    *(uint *)(param_1 + 0x1c8) = *(uint *)(param_1 + 0x1c8) & 0xfffff1ff;

    PhysicsExZeroForce(param_1);

    puVar2[0x10] = puVar2[0x10] | 3;

  }

  if ((*(int *)(param_1 + 0xe4) == 0) || (puVar2[0xf] != *(int *)(param_1 + 0xe8))) {

    puVar2[0xf] = *(undefined4 *)(param_1 + 0xe8);

  }

  if (DAT_00632e74 != 0) {

    return;

  }

  iVar4 = fx_create(param_1);

  if ((iVar4 != 0) && (puVar2[0x11] == 0)) {

    reaper_00530bd0(param_1,0,0,0,4,0);

    object_destroy(param_1);

    return;

  }

  if (((~puVar2[0x10] & 2) == 0) || (iVar4 = reaper_0052e4a0(param_1), iVar4 == 0)) {

    bVar3 = false;

  }

  else {

    bVar3 = true;

  }

  if (((~puVar2[0x10] & 2) != 0) && (iVar4 = fx_create(param_1), iVar4 == 0)) {

    fVar6 = (float10)FUN_00518b70(param_1,0);

    fStack_d0 = (float)fVar6;

    fVar6 = (float10)FUN_00518b70(param_1,0);

    *(float *)(param_1 + 0xa0) =

         (float)(((float10)*(float *)(param_1 + 0x128) + (float10)*(float *)(param_1 + 0x134)) *

                 fVar6 * (float10)0.5 + (float10)*(float *)(param_1 + 0xa0));

    *(float *)(param_1 + 0xa4) =

         (float)(((float10)*(float *)(param_1 + 0x138) + (float10)*(float *)(param_1 + 300)) * fVar6

                 * (float10)0.5 + (float10)*(float *)(param_1 + 0xa4));

    fVar1 = *(float *)(param_1 + 0x13c);

    *(undefined4 *)(param_1 + 0x134) = *(undefined4 *)(param_1 + 0x128);

    *(undefined4 *)(param_1 + 0x138) = *(undefined4 *)(param_1 + 300);

    *(undefined4 *)(param_1 + 0x13c) = *(undefined4 *)(param_1 + 0x130);

    *(float *)(param_1 + 0xa8) =

         (float)(((float10)fVar1 + (float10)*(float *)(param_1 + 0x130)) * fVar6 * (float10)0.5 +

                (float10)*(float *)(param_1 + 0xa8));

    PhysicsExApplyLocation(param_1);

    obj_velocity_normalize(param_1,1,0,0,0);

    object_animate_process(param_1,fStack_d0);

    *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) | 0x40;

    fVar6 = (float10)FUN_00518b70(param_1,0);

    GEO_MatFromQuat_2(auStack_44,(float)(fVar6 * (float10)12.566371));

    fVar6 = (float10)FUN_00518b70(param_1,0);

    GEO_MatFromQuat_3(auStack_88,(float)(fVar6 * (float10)3.1415927));

    (*(code *)PTR_crt_matrix_mul_00580c18)(auStack_cc,auStack_44,auStack_88);

    puVar7 = auStack_cc;

    goto code_r0x0046e613;

  }

  if (((puVar2[0x10] & 4) != 0) || (0.0 < (float)puVar2[0x1b])) {

    if (((puVar2[0x10] & 4) != 0) && (puVar2[0x13] != 0)) {

      (*(code *)PTR_crt_matrix_copy_init_00580c1c)(auStack_cc,puVar2[0x13] + 0x294);

      (*(code *)PTR_S_GEO_Vec3Transform_00580c20)(puVar2 + 0x17,puVar2 + 0x14,1,auStack_cc);

    }

    puVar2[0x10] = puVar2[0x10] & 0xfffffffb;

    if (puVar2[0x13] != 0) {

      (*(code *)PTR_S_GEO_Vec3Transform_00580c20)

                (puVar2 + 0x14,puVar2 + 0x17,1,puVar2[0x13] + 0x294);

    }

    uStack_f0 = 0;

    uStack_ec = 0;

    fStack_e8 = (*(float *)(*(int *)(param_1 + 0x104) + 4) /

                *(float *)(*(int *)(param_1 + 0x104) + 8)) * -32.17405;

    trajectory_calculate(param_1 + 0x128,param_1 + 0xa0,puVar2 + 0x14,&uStack_f0,puVar2[0x1a]);

    FUN_00518b70(param_1,0);

    fVar6 = (float10)FUN_00518b70(param_1,0);

    fVar1 = (float)puVar2[0x1a];

    puVar2[0x1a] = (float)((float10)fVar1 - fVar6);

    if ((float10)fVar1 - fVar6 < (float10)0.0) {

      puVar2[0x1a] = 0;

    }

    fVar6 = (float10)FUN_00518b70(param_1,0);

    fVar1 = (float)puVar2[0x1b];

    puVar2[0x1b] = (float)((float10)fVar1 - fVar6);

    if ((float10)fVar1 - fVar6 < (float10)0.0) {

      puVar2[0x1b] = 0;

    }

  }

  obj_vel_reset(param_1);

  if (bVar3) {

    iVar4 = comm_send_gate_check_2(param_1);

    if (iVar4 == 0) {

      iVar4 = comm_send_gate_check(param_1);

      if (iVar4 == 0) goto code_r0x0046e56a;

      uStack_f0 = *(undefined4 *)(param_1 + 0x128);

      uStack_ec = *(undefined4 *)(param_1 + 300);

      fStack_e8 = *(float *)(param_1 + 0x130);

      uVar9 = 1;

      uStack_e4 = *(undefined4 *)(param_1 + 200);

      uVar8 = 4;

    }

    else {

      uStack_f0 = *(undefined4 *)(param_1 + 0xa0);

      uStack_ec = *(undefined4 *)(param_1 + 0xa4);

      fStack_e8 = *(float *)(param_1 + 0xa8);

      uStack_e4 = *(undefined4 *)(param_1 + 0x128);

      uStack_e0 = *(undefined4 *)(param_1 + 300);

      uStack_dc = *(undefined4 *)(param_1 + 0x130);

      uVar9 = 0;

      uStack_d8 = *(undefined4 *)(param_1 + 0x114);

      uStack_d4 = *(undefined4 *)(param_1 + 200);

      uVar8 = 8;

    }

    comm_chat_send_2(param_1,uVar8,0,0,uVar9,&uStack_f0);

  }

code_r0x0046e56a:

  PhysicsExApplyLocation(param_1);

  obj_velocity_normalize(param_1,1,0,0,0);

  fVar6 = (float10)FUN_00518b70(param_1,0);

  object_animate_process(param_1,(float)fVar6);

  obj_gravity_apply(param_1,~puVar2[0x10] & 4);

  *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) | 0x40;

  fVar6 = (float10)FUN_00518b70(param_1,0);

  GEO_MatFromQuat_2(auStack_44,(float)(fVar6 * (float10)12.566371));

  fVar6 = (float10)FUN_00518b70(param_1,0);

  GEO_MatFromQuat_3(auStack_cc,(float)(fVar6 * (float10)3.1415927));

  (*(code *)PTR_crt_matrix_mul_00580c18)(auStack_88,auStack_44,auStack_cc);

  puVar7 = auStack_88;

code_r0x0046e613:

  (*(code *)PTR_crt_matrix_mul_00580c18)(param_1 + 0x294,param_1 + 0x294,puVar7);

  return;

}

/* ===== cspec_0046e630 @ 0x0046E630 ===== */
void cspec_0046e630(int param_1)



{

  int iVar1;

  

  iVar1 = *(int *)(*(int *)(param_1 + 0x100) + 0x44);

  if (iVar1 != 0) {

    *(undefined4 *)(iVar1 + 0x210) = 0;

  }

  return;

}

/* ===== cspec_0046e650 @ 0x0046E650 ===== */
void cspec_0046e650(int param_1)



{

  int iVar1;

  

  iVar1 = *(int *)(param_1 + 0x100);

  obj_ptr_clear_if_dead(iVar1 + 0x44);

  obj_ptr_clear_if_dead(param_1 + 0x274);

  obj_ptr_clear_if_dead(iVar1 + 0x4c);

  return;

}

/* ===== cspec_0046e680 @ 0x0046E680 ===== */
void cspec_0046e680(int param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)



{

  byte bVar1;

  char cVar2;

  int iVar3;

  int iVar4;

  undefined4 uVar5;

  undefined4 uStack_8;

  char cStack_4;

  byte bStack_3;

  

  switch(param_2) {

  case 0:

    *(undefined4 *)(param_1 + 0xa0) = *param_4;

    *(undefined4 *)(param_1 + 0xa4) = param_4[1];

    *(undefined4 *)(param_1 + 0xa8) = param_4[2];

    *(undefined4 *)(param_1 + 0x128) = param_4[3];

    *(undefined4 *)(param_1 + 300) = param_4[4];

    *(undefined4 *)(param_1 + 0x130) = param_4[5];

    *(undefined4 *)(param_1 + 0x114) = param_4[6];

    *(undefined4 *)(param_1 + 200) = param_4[7];

    return;

  case 1:

    *(undefined4 *)(param_1 + 0x128) = *param_4;

    *(undefined4 *)(param_1 + 300) = param_4[1];

    *(undefined4 *)(param_1 + 0x130) = param_4[2];

    *(undefined4 *)(param_1 + 200) = param_4[3];

    return;

  case 2:

    iVar4 = objanim_select_animloop(*param_4);

    if (iVar4 != 0) {

      bVar1 = *(byte *)((int)param_4 + 5);

      cVar2 = *(char *)(param_4 + 1);

      iVar3 = reaper_0052e4a0(param_1);

      if (iVar3 != 0) {

        uStack_8 = *(undefined4 *)(iVar4 + 0x188);

        cStack_4 = cVar2;

        bStack_3 = bVar1;

        reaper_00530bd0(param_1,0,1,2,2,&uStack_8);

      }

      *(uint *)(iVar4 + 0x214) = (uint)bVar1;

      *(undefined4 *)(iVar4 + 0x218) = 0xffffffff;

      if (cVar2 == '\0') {

        *(undefined4 *)(iVar4 + 0x210) = 0;

        return;

      }

      *(int *)(iVar4 + 0x210) = param_1;

      return;

    }

    break;

  case 3:

    iVar4 = objanim_select_animloop(*param_4);

    uVar5 = 0;

    if (param_4[1] != 0) {

      uVar5 = objanim_select_animloop(param_4[1]);

    }

    iVar3 = *(int *)(iVar4 + 0x100);

    if (((iVar3 != 0) && (*(code **)(iVar3 + 0x48) != (code *)0x0)) && (*(int *)(iVar3 + 0x44) != 0)

       ) {

      (**(code **)(iVar3 + 0x48))(iVar4,*(int *)(iVar3 + 0x44),uVar5);

      return;

    }

    break;

  case 4:

    object_destroy(param_1);

  }

  return;

}

/* ===== object_0046e830 @ 0x0046E830 ===== */
/* PS2 candidate: formation_create_sonak__FP6OBJECTi (conf 0.4) */



int object_0046e830(int param_1,int param_2)



{

  undefined4 uVar1;

  int iVar2;

  int iVar3;

  undefined4 *puVar4;

  undefined4 *puVar5;

  

  iVar2 = object_allocate_type(0x374,0x80000000);

  object_change_ospec(iVar2,0x4c);

  *(undefined4 *)(iVar2 + 0xe8) = 0;

  *(uint *)(iVar2 + 0xd8) = *(uint *)(iVar2 + 0xd8) | 0x10000;

  iVar3 = *(int *)(param_2 + 0x210);

  if (iVar3 == 0) {

    puVar4 = (undefined4 *)(param_1 + 0x294);

    puVar5 = (undefined4 *)(iVar2 + 0x294);

    for (iVar3 = 0x11; iVar3 != 0; iVar3 = iVar3 + -1) {

      *puVar5 = *puVar4;

      puVar4 = puVar4 + 1;

      puVar5 = puVar5 + 1;

    }

  }

  else {

    (*(code *)PTR_crt_matrix_mul_00580c18)

              (iVar2 + 0x294,iVar3 + 0x294,

               *(int *)(param_2 + 0x218) * 0x44 + *(int *)(iVar3 + 0x2dc));

  }

  object_init_usage(iVar2);

  object_set_location(iVar2,*(undefined4 *)(iVar2 + 0x2a4),*(undefined4 *)(iVar2 + 0x2b4),

                      *(undefined4 *)(iVar2 + 0x2c4));

  ObjectCalculateTransform(iVar2);

  PROJ_ObjectFinalize(iVar2);

  puVar4 = *(undefined4 **)(iVar2 + 0x100);

  if ((~puVar4[0x10] & 1) != 0) {

    puVar5 = puVar4;

    for (iVar3 = 0x1c; iVar3 != 0; iVar3 = iVar3 + -1) {

      *puVar5 = 0;

      puVar5 = puVar5 + 1;

    }

    *(undefined4 **)(iVar2 + 0x104) = puVar4;

    *(uint *)(iVar2 + 0xd8) = *(uint *)(iVar2 + 0xd8) & 0xffffffef;

    *(uint *)(iVar2 + 0x1c8) = *(uint *)(iVar2 + 0x1c8) & 0xfffff1ff;

    PhysicsExZeroForce(iVar2);

    puVar4[0x10] = puVar4[0x10] | 3;

  }

  if ((*(int *)(iVar2 + 0xe4) == 0) || (puVar4[0xf] != *(int *)(iVar2 + 0xe8))) {

    puVar4[0xf] = *(undefined4 *)(iVar2 + 0xe8);

  }

  **(uint **)(iVar2 + 0x104) = **(uint **)(iVar2 + 0x104) | 0x300;

  *(undefined4 *)(*(int *)(iVar2 + 0x104) + 0x10) = 0;

  *(float *)(iVar2 + 0x154) = *(float *)(param_2 + 0x154) + *(float *)(param_2 + 0x154);

  *(float *)(iVar2 + 0x1ec) = (2.0 / *(float *)(param_1 + 0xc4)) * *(float *)(param_2 + 0x154);

  uVar1 = *(undefined4 *)(param_1 + 0xc4);

  *(int *)(iVar2 + 0x274) = param_1;

  *(undefined4 *)(iVar2 + 0xc4) = uVar1;

  *(int *)(*(int *)(iVar2 + 0x100) + 0x44) = param_2;

  return iVar2;

}

/* ===== reaper_ospec_init @ 0x0046E9D0 ===== */
void reaper_ospec_init(int param_1,undefined4 *param_2,undefined4 param_3,float param_4,

                      float param_5)



{

  undefined4 *puVar1;

  undefined4 uVar2;

  int iVar3;

  undefined4 *puVar4;

  

  puVar1 = *(undefined4 **)(param_1 + 0x100);

  if ((~puVar1[0x10] & 1) != 0) {

    puVar4 = puVar1;

    for (iVar3 = 0x1c; iVar3 != 0; iVar3 = iVar3 + -1) {

      *puVar4 = 0;

      puVar4 = puVar4 + 1;

    }

    *(undefined4 **)(param_1 + 0x104) = puVar1;

    *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) & 0xffffffef;

    *(uint *)(param_1 + 0x1c8) = *(uint *)(param_1 + 0x1c8) & 0xfffff1ff;

    PhysicsExZeroForce(param_1);

    puVar1[0x10] = puVar1[0x10] | 3;

  }

  if ((*(int *)(param_1 + 0xe4) == 0) || (puVar1[0xf] != *(int *)(param_1 + 0xe8))) {

    puVar1[0xf] = *(undefined4 *)(param_1 + 0xe8);

  }

  puVar1[0x14] = *param_2;

  puVar1[0x15] = param_2[1];

  uVar2 = param_2[2];

  puVar1[0x1b] = param_4 * param_5;

  puVar1[0x16] = uVar2;

  puVar1[0x1a] = param_4;

  puVar1[0x13] = param_3;

  puVar1[0x10] = puVar1[0x10] | 4;

  return;

}

/* ===== lift_rider_dispatcher_c104 @ 0x0046EA90 ===== */
void lift_rider_dispatcher_c104(int *param_1)



{

  float fVar1;

  float fVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int *piVar6;

  int *piVar7;

  float10 fVar8;

  undefined4 uStack_18;

  undefined4 uStack_14;

  float fStack_10;

  undefined1 auStack_c [8];

  float fStack_4;

  

  iVar3 = (int)param_1;

  piVar7 = *(int **)((int)param_1 + 0x100);

  if (DAT_00632e74 == 0) {

    switch(*(undefined4 *)((int)param_1 + 0xe4)) {

    case 0:

      *(uint *)((int)param_1 + 0x1c8) = *(uint *)((int)param_1 + 0x1c8) | 0x600;

      *(undefined4 *)((int)param_1 + 0x14) = 0;

      ObjectSetAnim(param_1,1,0x84,0,0,0);

      object_animate_process(iVar3,0);

      playerobj_eval_refpt(iVar3,0,&uStack_18);

      fVar8 = (float10)get_floor_z_point(&uStack_18);

      fStack_10 = (float)fVar8;

      if (*piVar7 == 0) {

        iVar4 = object_allocate_type(0x446,0x80000000);

        *piVar7 = iVar4;

      }

      *(uint *)(*piVar7 + 0x1c8) = *(uint *)(*piVar7 + 0x1c8) | 0x600;

      object_set_location(*piVar7,uStack_18,uStack_14,fStack_10);

      *(undefined4 *)(*piVar7 + 200) = *(undefined4 *)(iVar3 + 200);

      if (piVar7[1] == 0) {

        iVar4 = object_allocate_type(0x429,0x80000000);

        piVar7[1] = iVar4;

      }

      *(uint *)(piVar7[1] + 0x1c8) = *(uint *)(piVar7[1] + 0x1c8) | 0x600;

      if (*(int *)(iVar3 + 0xe8) != 0) {

        *(undefined4 *)(iVar3 + 0xe4) = 1;

        return;

      }

      object_set_location(piVar7[1],uStack_18,uStack_14,fStack_10);

      *(undefined4 *)(piVar7[1] + 200) = *(undefined4 *)(iVar3 + 200);

      *(undefined4 *)(iVar3 + 0xe4) = 4;

      return;

    case 1:

      iVar4 = fx_create(param_1);

      if ((iVar4 != 0) && (param_1 = DAT_00632d6c, DAT_00632d6c != (int *)0x0)) {

        while( true ) {

          piVar6 = param_1;

          iVar4 = param_1[3];

          iVar5 = ObjIsMecc(iVar4);

          if ((iVar5 != 0) || (iVar5 = ObjIsReaper(iVar4), iVar5 != 0)) break;

LAB_0046ec90:

          param_1 = (int *)*piVar6;

          if (param_1 == (int *)0x0) {

            return;

          }

        }

        playerobj_eval_refpt(piVar7[1],1,&uStack_18);

        fVar8 = (float10)FUN_0050a610(iVar4 + 0xa0,&uStack_18);

        if (fVar8 < (float10)100.0 == (fVar8 == (float10)100.0)) {

          playerobj_eval_refpt(*piVar7,1,&uStack_18);

          fVar8 = (float10)FUN_0050a610(iVar4 + 0xa0,&uStack_18);

          piVar6 = param_1;

          if (fVar8 < (float10)100.0 == (fVar8 == (float10)100.0)) goto LAB_0046ec90;

          piVar7 = *(int **)(iVar3 + 0x100);

          fVar1 = *(float *)(piVar7[1] + 0xa8);

          fVar2 = *(float *)(*piVar7 + 0xa8);

          *(undefined4 *)(iVar3 + 0xf4) = *(undefined4 *)(iVar3 + 200);

          *(float *)(iVar3 + 0xf8) = 180.0 / ((fVar1 - fVar2) * 0.1);

          *(undefined4 *)(piVar7[1] + 0x108) = 0xc1200000;

          *(undefined4 *)(iVar3 + 0xe4) = 2;

          iVar4 = reaper_0052e4a0(iVar3);

          if (iVar4 == 0) goto LAB_0046ed2d;

          param_1 = (int *)0xffffffff;

        }

        else {

          piVar7 = *(int **)(iVar3 + 0x100);

          fVar1 = *(float *)(piVar7[1] + 0xa8);

          fVar2 = *(float *)(*piVar7 + 0xa8);

          *(undefined4 *)(iVar3 + 0xf4) = *(undefined4 *)(iVar3 + 200);

          *(float *)(iVar3 + 0xf8) = 180.0 / ((fVar1 - fVar2) * 0.1);

          *(undefined4 *)(piVar7[1] + 0x108) = 0xc1200000;

          *(undefined4 *)(iVar3 + 0xe4) = 2;

          iVar5 = reaper_0052e4a0(iVar3);

          if (iVar5 == 0) goto LAB_0046ed2d;

          if (iVar4 == 0) {

            param_1 = (int *)0xffffffff;

          }

          else {

            param_1 = *(int **)(iVar4 + 0x188);

          }

        }

        reaper_00530bd0(iVar3,0,1,0,2,&param_1);

LAB_0046ed2d:

        iVar3 = sound_get_free_sequence__Fv();

        piVar7[2] = iVar3;

        return;

      }

      break;

    case 2:

      FUN_004a7400(piVar7[1]);

      *(undefined4 *)(piVar7[1] + 0xf4) = *(undefined4 *)(piVar7[1] + 200);

      fVar8 = (float10)FUN_00518b70(0,0,0x461c4000,*(undefined4 *)(iVar3 + 0xf4),piVar7[1] + 200);

      chase_angle((float)(fVar8 * (float10)*(float *)(iVar3 + 0xf8)));

      lift_update_rider_position__FP6OBJECT(iVar3);

      if (*(float *)(piVar7[1] + 0xa8) <= *(float *)(*piVar7 + 0xa8)) {

        *(undefined4 *)(piVar7[1] + 0xa8) = *(undefined4 *)(*piVar7 + 0xa8);

        *(undefined4 *)(iVar3 + 0xfc) = 4;

LAB_0046efd0:

        *(undefined4 *)(iVar3 + 0xec) = 0x41200000;

        *(undefined4 *)(iVar3 + 0xe4) = 5;

        sound_interrupt_sequence(piVar7 + 2);

        return;

      }

      break;

    case 3:

      FUN_004a7400(piVar7[1]);

      *(undefined4 *)(piVar7[1] + 0xf4) = *(undefined4 *)(piVar7[1] + 200);

      fVar8 = (float10)FUN_00518b70(0,0,0x461c4000,*(undefined4 *)(iVar3 + 0xf4),piVar7[1] + 200);

      chase_angle((float)(fVar8 * (float10)*(float *)(iVar3 + 0xf8)));

      lift_update_rider_position__FP6OBJECT(iVar3);

      playerobj_eval_refpt(piVar7[1],0,&uStack_18);

      playerobj_eval_refpt(iVar3,0,auStack_c);

      if (fStack_4 <= fStack_10) {

        *(float *)(piVar7[1] + 0xa8) = *(float *)(piVar7[1] + 0xa8) - (fStack_10 - fStack_4);

        *(undefined4 *)(iVar3 + 0xfc) = 1;

        goto LAB_0046efd0;

      }

      break;

    case 4:

      iVar4 = fx_create(param_1);

      if ((iVar4 != 0) && (param_1 = DAT_00632d6c, DAT_00632d6c != (int *)0x0)) {

        do {

          piVar6 = param_1;

          iVar4 = param_1[3];

          iVar5 = ObjIsMecc(iVar4);

          if ((iVar5 != 0) || (iVar5 = ObjIsReaper(iVar4), iVar5 != 0)) {

            playerobj_eval_refpt(piVar7[1],1,&uStack_18);

            fVar8 = (float10)FUN_0050a610(iVar4 + 0xa0,&uStack_18);

            if (fVar8 < (float10)100.0 != (fVar8 == (float10)100.0)) {

              sound_sequence_alloc(iVar3,iVar4);

              return;

            }

            playerobj_eval_refpt(iVar3,1,&uStack_18);

            fVar8 = (float10)FUN_0050a610(iVar4 + 0xa0,&uStack_18);

            piVar6 = param_1;

            if (fVar8 < (float10)100.0 != (fVar8 == (float10)100.0)) {

              sound_sequence_alloc(iVar3,0);

              return;

            }

          }

          param_1 = (int *)*piVar6;

          if (param_1 == (int *)0x0) {

            return;

          }

        } while( true );

      }

      break;

    case 5:

      fVar8 = (float10)FUN_00518b70(0,0);

      fVar8 = (float10)*(float *)(iVar3 + 0xec) - fVar8;

      *(float *)(iVar3 + 0xec) = (float)fVar8;

      if (fVar8 < (float10)0.0 != (fVar8 == (float10)0.0)) {

        *(undefined4 *)(iVar3 + 0xe4) = *(undefined4 *)(iVar3 + 0xfc);

      }

    }

  }

  return;

}

/* ===== lift_update_rider_position__FP6OBJECT @ 0x0046F050 ===== */
/* PS2 candidate: lift_update_rider_position__FP6OBJECT (conf 0.596) */



void lift_update_rider_position__FP6OBJECT(int param_1)



{

  float *pfVar1;

  float fVar2;

  float fVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  undefined4 *puVar7;

  float fVar8;

  float10 fVar9;

  float local_170;

  float local_16c;

  float local_168;

  float local_164;

  undefined1 local_160 [8];

  float local_158;

  undefined1 auStack_154 [16];

  float fStack_144;

  float fStack_134;

  float fStack_124;

  undefined1 local_110 [68];

  undefined1 local_cc [68];

  undefined1 local_88 [68];

  undefined1 auStack_44 [68];

  

  iVar4 = *(int *)(param_1 + 0x100);

  playerobj_eval_refpt(*(undefined4 *)(iVar4 + 4),1,local_160);

  for (puVar7 = DAT_00632d6c; puVar7 != (undefined4 *)0x0; puVar7 = (undefined4 *)*puVar7) {

    iVar5 = puVar7[3];

    if ((*(float *)(iVar5 + 0xa8) <= local_158 + 2.0) &&

       (local_158 - 2.0 < *(float *)(iVar5 + 0xa8) != (local_158 - 2.0 == *(float *)(iVar5 + 0xa8)))

       ) {

      pfVar1 = (float *)(iVar5 + 0xa0);

      fVar9 = (float10)distancesq2d__FP3P3DT0(pfVar1,local_160);

      if (fVar9 < (float10)900.0) {

        iVar6 = *(int *)(iVar4 + 4);

        fVar2 = *(float *)(iVar6 + 0xa0) - *(float *)(iVar6 + 0xac);

        fVar3 = *(float *)(iVar6 + 0xa4) - *(float *)(iVar6 + 0xb0);

        fVar8 = *(float *)(iVar6 + 0xa8) - *(float *)(iVar6 + 0xb4);

        local_170 = fVar2 + *pfVar1;

        *pfVar1 = local_170;

        local_16c = fVar3 + *(float *)(iVar5 + 0xa4);

        *(float *)(iVar5 + 0xa4) = local_16c;

        local_164 = fVar8 + *(float *)(iVar5 + 0xa8);

        *(float *)(iVar5 + 0xa8) = local_164;

        *(float *)(iVar5 + 0x2a4) = fVar2 + *(float *)(iVar5 + 0x2a4);

        *(float *)(iVar5 + 0x2b4) = fVar3 + *(float *)(iVar5 + 0x2b4);

        *(float *)(iVar5 + 0x2c4) = fVar8 + *(float *)(iVar5 + 0x2c4);

        iVar6 = *(int *)(iVar4 + 4);

        local_170 = *(float *)(iVar6 + 0xa0) - local_170;

        local_16c = *(float *)(iVar6 + 0xa4) - local_16c;

        local_168 = *(float *)(iVar6 + 0xa8) - local_164;

        FUN_0053dc10(local_88,&local_170);

        GEO_MatFromQuat_2(local_110,

                          (*(float *)(*(int *)(iVar4 + 4) + 0xf4) -

                          *(float *)(*(int *)(iVar4 + 4) + 200)) * 0.017453292);

        (*(code *)PTR_crt_matrix_mul_00580c18)(local_cc,local_110,local_88);

        local_170 = -local_170;

        local_16c = -local_16c;

        local_168 = -local_168;

        FUN_0053dc10(auStack_44,&local_170);

        (*(code *)PTR_crt_matrix_mul_00580c18)(auStack_154,auStack_44,local_cc);

        *pfVar1 = fStack_144 + *pfVar1;

        *(float *)(iVar5 + 0xa4) = fStack_134 + *(float *)(iVar5 + 0xa4);

        *(float *)(iVar5 + 0xa8) = fStack_124 + *(float *)(iVar5 + 0xa8);

        *(float *)(iVar5 + 0x2a4) = fStack_144 + *(float *)(iVar5 + 0x2a4);

        *(float *)(iVar5 + 0x2b4) = fStack_134 + *(float *)(iVar5 + 0x2b4);

        *(float *)(iVar5 + 0x2c4) = fStack_124 + *(float *)(iVar5 + 0x2c4);

        fVar2 = *(float *)(*(int *)(iVar4 + 4) + 200);

        fVar3 = *(float *)(*(int *)(iVar4 + 4) + 0xf4);

        *(uint *)(iVar5 + 0xd8) = *(uint *)(iVar5 + 0xd8) | 0x10000000;

        *(float *)(iVar5 + 200) = (fVar2 - fVar3) + *(float *)(iVar5 + 200);

      }

    }

  }

  return;

}

/* ===== sound_sequence_alloc @ 0x0046F2E0 ===== */
void sound_sequence_alloc(int param_1,int param_2)



{

  int iVar1;

  int iVar2;

  int iVar3;

  undefined4 uVar4;

  undefined1 local_18 [8];

  float local_10;

  undefined1 local_c [8];

  float local_4;

  

  iVar2 = param_1;

  iVar1 = *(int *)(param_1 + 0x100);

  playerobj_eval_refpt(*(undefined4 *)(iVar1 + 4),0,local_c);

  playerobj_eval_refpt(iVar2,0,local_18);

  *(float *)(iVar2 + 0xf4) = *(float *)(iVar2 + 200) + 180.0;

  *(float *)(iVar2 + 0xf8) = 180.0 / ((local_10 - local_4) * 0.1);

  *(undefined4 *)(*(int *)(iVar1 + 4) + 0x108) = 0x41200000;

  *(undefined4 *)(iVar2 + 0xe4) = 3;

  iVar3 = reaper_0052e4a0(iVar2);

  if (iVar3 != 0) {

    if (param_2 == 0) {

      param_1 = -1;

    }

    else {

      param_1 = *(int *)(param_2 + 0x188);

    }

    reaper_00530bd0(iVar2,0,1,0,1,&param_1);

  }

  uVar4 = sound_get_free_sequence__Fv();

  *(undefined4 *)(iVar1 + 8) = uVar4;

  return;

}

/* ===== cspec_0046f3c0 @ 0x0046F3C0 ===== */
undefined4 cspec_0046f3c0(void)



{

  return 0xc;

}

/* ===== cspec_0046f3d0 @ 0x0046F3D0 ===== */
void cspec_0046f3d0(int param_1)



{

  int *piVar1;

  int iVar2;

  

  piVar1 = *(int **)(param_1 + 0x100);

  iVar2 = *piVar1;

  if (iVar2 != 0) {

    object_destroy(iVar2);

  }

  iVar2 = piVar1[1];

  if (iVar2 != 0) {

    object_destroy(iVar2);

  }

  return;

}

/* ===== cspec_0046f400 @ 0x0046F400 ===== */
void cspec_0046f400(int param_1)



{

  int iVar1;

  

  iVar1 = *(int *)(param_1 + 0x100);

  obj_ptr_clear_if_dead(iVar1);

  obj_ptr_clear_if_dead(iVar1 + 4);

  return;

}

/* ===== cspec_0046f420 @ 0x0046F420 ===== */
void cspec_0046f420(int param_1,int param_2,undefined4 param_3,int *param_4)



{

  float fVar1;

  float fVar2;

  int *piVar3;

  int iVar4;

  undefined4 uVar5;

  int iVar6;

  

  if (param_2 == 1) {

    if (*param_4 == -1) {

      sound_sequence_alloc(param_1,0);

      return;

    }

    uVar5 = objanim_select_animloop(*param_4);

    sound_sequence_alloc(param_1,uVar5);

  }

  else if (param_2 == 2) {

    if (*param_4 == -1) {

      iVar6 = 0;

    }

    else {

      iVar6 = objanim_select_animloop(*param_4);

    }

    piVar3 = *(int **)(param_1 + 0x100);

    fVar1 = *(float *)(piVar3[1] + 0xa8);

    fVar2 = *(float *)(*piVar3 + 0xa8);

    *(undefined4 *)(param_1 + 0xf4) = *(undefined4 *)(param_1 + 200);

    *(float *)(param_1 + 0xf8) = 180.0 / ((fVar1 - fVar2) * 0.1);

    *(undefined4 *)(piVar3[1] + 0x108) = 0xc1200000;

    *(undefined4 *)(param_1 + 0xe4) = 2;

    iVar4 = reaper_0052e4a0(param_1);

    if (iVar4 != 0) {

      if (iVar6 == 0) {

        param_4 = (int *)0xffffffff;

      }

      else {

        param_4 = *(int **)(iVar6 + 0x188);

      }

      reaper_00530bd0(param_1,0,1,0,2,&param_4);

    }

    iVar6 = sound_get_free_sequence__Fv();

    piVar3[2] = iVar6;

    return;

  }

  return;

}

/* ===== FUN_0046f540 @ 0x0046F540 ===== */
/* PS2 candidate: getMenuSelection__7PS2Game (conf 0.703) */



undefined * FUN_0046f540(int param_1)



{

  uint uVar1;

  

  uVar1 = *(uint *)(param_1 + 0xe8);

  if (4 < uVar1) {

    uVar1 = 0;

  }

  return (&PTR_s_Illegal_0055b518)[uVar1];

}

/* ===== cspec_0046f560 @ 0x0046F560 ===== */
void cspec_0046f560(int param_1)



{

  int *piVar1;

  uint *puVar2;

  int iVar3;

  undefined4 *puVar4;

  int iVar5;

  int aiStack_c [3];

  

  puVar2 = *(uint **)(param_1 + 0x100);

  if ((~*puVar2 & 1) != 0) {

    if (*(int *)(param_1 + 0xe8) == 0) {

      aiStack_c[0] = 0;

      aiStack_c[1] = 0;

      aiStack_c[2] = 0;

      for (puVar4 = DAT_00632d68; puVar4 != (undefined4 *)0x0; puVar4 = (undefined4 *)*puVar4) {

        iVar5 = puVar4[3];

        if (((*(int *)(iVar5 + 0x1e0) == 0x5c) && (iVar3 = *(int *)(iVar5 + 0xe8), 0 < iVar3)) &&

           (iVar3 < 4)) {

          *(int *)(&stack0xfffffff0 + iVar3 * 4) = iVar5;

        }

      }

      iVar5 = 0;

      do {

        piVar1 = aiStack_c + iVar5;

        iVar5 = iVar5 + 1;

        if (*piVar1 == 0) goto code_r0x0046f5e0;

      } while (iVar5 < 3);

      iVar5 = 0;

code_r0x0046f5e0:

      *(int *)(param_1 + 0xe8) = iVar5;

    }

    puVar2[1] = 3;

    if ((~*puVar2 & 8) != 0) {

      puVar2[4] = 0x3f800000;

      puVar2[3] = 0x3f800000;

      puVar2[2] = 0x3f800000;

      *puVar2 = *puVar2 | 8;

    }

    if ((~*puVar2 & 4) != 0) {

      puVar2[10] = puVar2[2];

      puVar2[0xb] = puVar2[3];

      puVar2[0xc] = puVar2[4];

      puVar2[0xd] = puVar2[5];

      puVar2[6] = puVar2[2];

      puVar2[7] = puVar2[3];

      puVar2[8] = puVar2[4];

      puVar2[9] = puVar2[5];

      *puVar2 = *puVar2 | 4;

    }

    puVar2[0x16] = 0x3f800000;

    puVar2[0x14] = 0x5f7fffff;

    *(undefined4 *)(param_1 + 0xf4) = 1;

    *puVar2 = *puVar2 & 0xfffffffd | 1;

  }

  *(undefined4 *)(param_1 + 0xf4) = 0;

  obj_ai_recognize(param_1,1);

  return;

}

/* ===== cspec_0046f6a0 @ 0x0046F6A0 ===== */
void cspec_0046f6a0(int param_1)



{

  int *piVar1;

  uint *puVar2;

  int iVar3;

  undefined4 *puVar4;

  uint uVar5;

  int iVar6;

  int aiStack_c [3];

  

  puVar2 = *(uint **)(param_1 + 0x100);

  if ((~*puVar2 & 1) != 0) {

    if (*(int *)(param_1 + 0xe8) == 0) {

      aiStack_c[0] = 0;

      aiStack_c[1] = 0;

      aiStack_c[2] = 0;

      for (puVar4 = DAT_00632d68; puVar4 != (undefined4 *)0x0; puVar4 = (undefined4 *)*puVar4) {

        iVar6 = puVar4[3];

        if (((*(int *)(iVar6 + 0x1e0) == 0x5c) && (iVar3 = *(int *)(iVar6 + 0xe8), 0 < iVar3)) &&

           (iVar3 < 4)) {

          *(int *)(&stack0xfffffff0 + iVar3 * 4) = iVar6;

        }

      }

      iVar6 = 0;

      do {

        piVar1 = aiStack_c + iVar6;

        iVar6 = iVar6 + 1;

        if (*piVar1 == 0) goto code_r0x0046f720;

      } while (iVar6 < 3);

      iVar6 = 0;

code_r0x0046f720:

      *(int *)(param_1 + 0xe8) = iVar6;

    }

    puVar2[1] = 3;

    if ((~*puVar2 & 8) != 0) {

      puVar2[4] = 0x3f800000;

      puVar2[3] = 0x3f800000;

      puVar2[2] = 0x3f800000;

      *puVar2 = *puVar2 | 8;

    }

    if ((~*puVar2 & 4) != 0) {

      puVar2[10] = puVar2[2];

      puVar2[0xb] = puVar2[3];

      puVar2[0xc] = puVar2[4];

      puVar2[0xd] = puVar2[5];

      puVar2[6] = puVar2[2];

      puVar2[7] = puVar2[3];

      puVar2[8] = puVar2[4];

      puVar2[9] = puVar2[5];

      *puVar2 = *puVar2 | 4;

    }

    puVar2[0x16] = 0x3f800000;

    puVar2[0x14] = 0x5f7fffff;

    *(undefined4 *)(param_1 + 0xf4) = 1;

    *puVar2 = *puVar2 & 0xfffffffd | 1;

  }

  if (DAT_00632e74 == 0) {

    uVar5 = *(uint *)(param_1 + 0xd8) | 0x40000000;

  }

  else {

    uVar5 = *(uint *)(param_1 + 0xd8) & 0xbfffffff;

  }

  *(uint *)(param_1 + 0xd8) = uVar5;

  obj_ai_recognize(param_1,0);

  return;

}

/* ===== vec3_clamp01 @ 0x0046F7F0 ===== */
void vec3_clamp01(float *param_1)



{

  float fVar1;

  

  if (1.0 < *param_1) {

    *param_1 = 1.0;

  }

  if (1.0 < param_1[1]) {

    param_1[1] = 1.0;

  }

  if (1.0 < param_1[2]) {

    param_1[2] = 1.0;

  }

  if (*param_1 < 0.0) {

    *param_1 = 0.0;

  }

  if (param_1[1] < 0.0) {

    param_1[1] = 0.0;

  }

  if (param_1[2] < 0.0) {

    param_1[2] = 0.0;

  }

  fVar1 = SQRT(*param_1 * *param_1 + param_1[1] * param_1[1] + param_1[2] * param_1[2]);

  param_1[3] = fVar1;

  if (1.0 < fVar1) {

    param_1[3] = 1.0;

  }

  return;

}

/* ===== kabutoai_is_punch_anim__FP6OBJECT @ 0x0046F8B0 ===== */
bool kabutoai_is_punch_anim__FP6OBJECT(int param_1)



{

  return *(int *)(param_1 + 0xe8) == 1;

}

/* ===== obj_5c_slot_scan @ 0x0046F8D0 ===== */
void obj_5c_slot_scan(int param_1,uint *param_2)



{

  int *piVar1;

  uint *puVar2;

  int iVar3;

  undefined4 *puVar4;

  int iVar5;

  int local_c [3];

  

  puVar2 = *(uint **)(param_1 + 0x100);

  if ((~*puVar2 & 1) != 0) {

    if (*(int *)(param_1 + 0xe8) == 0) {

      local_c[0] = 0;

      local_c[1] = 0;

      local_c[2] = 0;

      for (puVar4 = DAT_00632d68; puVar4 != (undefined4 *)0x0; puVar4 = (undefined4 *)*puVar4) {

        iVar5 = puVar4[3];

        if (((*(int *)(iVar5 + 0x1e0) == 0x5c) && (iVar3 = *(int *)(iVar5 + 0xe8), 0 < iVar3)) &&

           (iVar3 < 4)) {

          *(int *)(&stack0xfffffff0 + iVar3 * 4) = iVar5;

        }

      }

      iVar5 = 0;

      do {

        piVar1 = local_c + iVar5;

        iVar5 = iVar5 + 1;

        if (*piVar1 == 0) goto LAB_0046f950;

      } while (iVar5 < 3);

      iVar5 = 0;

LAB_0046f950:

      *(int *)(param_1 + 0xe8) = iVar5;

    }

    puVar2[1] = 3;

    if ((~*puVar2 & 8) != 0) {

      puVar2[4] = 0x3f800000;

      puVar2[3] = 0x3f800000;

      puVar2[2] = 0x3f800000;

      *puVar2 = *puVar2 | 8;

    }

    if ((~*puVar2 & 4) != 0) {

      puVar2[10] = puVar2[2];

      puVar2[0xb] = puVar2[3];

      puVar2[0xc] = puVar2[4];

      puVar2[0xd] = puVar2[5];

      puVar2[6] = puVar2[2];

      puVar2[7] = puVar2[3];

      puVar2[8] = puVar2[4];

      puVar2[9] = puVar2[5];

      *puVar2 = *puVar2 | 4;

    }

    puVar2[0x16] = 0x3f800000;

    puVar2[0x14] = 0x5f7fffff;

    *(undefined4 *)(param_1 + 0xf4) = 1;

    *puVar2 = *puVar2 & 0xfffffffd | 1;

  }

  *param_2 = puVar2[2];

  param_2[1] = puVar2[3];

  param_2[2] = puVar2[4];

  param_2[3] = puVar2[5];

  return;

}

/* ===== obj_5c_mount_check @ 0x0046FA10 ===== */
void obj_5c_mount_check(int param_1,uint *param_2)



{

  int *piVar1;

  uint *puVar2;

  int iVar3;

  undefined4 *puVar4;

  int iVar5;

  int local_c [3];

  

  puVar2 = *(uint **)(param_1 + 0x100);

  if ((~*puVar2 & 1) != 0) {

    if (*(int *)(param_1 + 0xe8) == 0) {

      local_c[0] = 0;

      local_c[1] = 0;

      local_c[2] = 0;

      for (puVar4 = DAT_00632d68; puVar4 != (undefined4 *)0x0; puVar4 = (undefined4 *)*puVar4) {

        iVar5 = puVar4[3];

        if (((*(int *)(iVar5 + 0x1e0) == 0x5c) && (iVar3 = *(int *)(iVar5 + 0xe8), 0 < iVar3)) &&

           (iVar3 < 4)) {

          *(int *)(&stack0xfffffff0 + iVar3 * 4) = iVar5;

        }

      }

      iVar5 = 0;

      do {

        piVar1 = local_c + iVar5;

        iVar5 = iVar5 + 1;

        if (*piVar1 == 0) goto LAB_0046fa90;

      } while (iVar5 < 3);

      iVar5 = 0;

LAB_0046fa90:

      *(int *)(param_1 + 0xe8) = iVar5;

    }

    puVar2[1] = 3;

    if ((~*puVar2 & 8) != 0) {

      puVar2[4] = 0x3f800000;

      puVar2[3] = 0x3f800000;

      puVar2[2] = 0x3f800000;

      *puVar2 = *puVar2 | 8;

    }

    if ((~*puVar2 & 4) != 0) {

      puVar2[10] = puVar2[2];

      puVar2[0xb] = puVar2[3];

      puVar2[0xc] = puVar2[4];

      puVar2[0xd] = puVar2[5];

      puVar2[6] = puVar2[2];

      puVar2[7] = puVar2[3];

      puVar2[8] = puVar2[4];

      puVar2[9] = puVar2[5];

      *puVar2 = *puVar2 | 4;

    }

    puVar2[0x16] = 0x3f800000;

    puVar2[0x14] = 0x5f7fffff;

    *(undefined4 *)(param_1 + 0xf4) = 1;

    *puVar2 = *puVar2 & 0xfffffffd | 1;

  }

  *param_2 = puVar2[0x11];

  param_2[1] = puVar2[0x12];

  param_2[2] = puVar2[0x13];

  return;

}

/* ===== obj_5c_mount_slot3 @ 0x0046FB50 ===== */
void obj_5c_mount_slot3(int param_1)



{

  int *piVar1;

  uint *puVar2;

  int iVar3;

  undefined4 *puVar4;

  int iVar5;

  int local_c [3];

  

  puVar2 = *(uint **)(param_1 + 0x100);

  if ((~*puVar2 & 1) != 0) {

    if (*(int *)(param_1 + 0xe8) == 0) {

      local_c[0] = 0;

      local_c[1] = 0;

      local_c[2] = 0;

      for (puVar4 = DAT_00632d68; puVar4 != (undefined4 *)0x0; puVar4 = (undefined4 *)*puVar4) {

        iVar5 = puVar4[3];

        if (((*(int *)(iVar5 + 0x1e0) == 0x5c) && (iVar3 = *(int *)(iVar5 + 0xe8), 0 < iVar3)) &&

           (iVar3 < 4)) {

          *(int *)(&stack0xfffffff0 + iVar3 * 4) = iVar5;

        }

      }

      iVar5 = 0;

      do {

        piVar1 = local_c + iVar5;

        iVar5 = iVar5 + 1;

        if (*piVar1 == 0) goto LAB_0046fbd0;

      } while (iVar5 < 3);

      iVar5 = 0;

LAB_0046fbd0:

      *(int *)(param_1 + 0xe8) = iVar5;

    }

    puVar2[1] = 3;

    if ((~*puVar2 & 8) != 0) {

      puVar2[4] = 0x3f800000;

      puVar2[3] = 0x3f800000;

      puVar2[2] = 0x3f800000;

      *puVar2 = *puVar2 | 8;

    }

    if ((~*puVar2 & 4) != 0) {

      puVar2[10] = puVar2[2];

      puVar2[0xb] = puVar2[3];

      puVar2[0xc] = puVar2[4];

      puVar2[0xd] = puVar2[5];

      puVar2[6] = puVar2[2];

      puVar2[7] = puVar2[3];

      puVar2[8] = puVar2[4];

      puVar2[9] = puVar2[5];

      *puVar2 = *puVar2 | 4;

    }

    puVar2[0x16] = 0x3f800000;

    puVar2[0x14] = 0x5f7fffff;

    *(undefined4 *)(param_1 + 0xf4) = 1;

    *puVar2 = *puVar2 & 0xfffffffd | 1;

  }

  *puVar2 = *puVar2 & 0xfffffffd;

  return;

}

/* ===== obj_orient_set @ 0x0046FC80 ===== */
void obj_orient_set(int param_1,uint *param_2)



{

  uint *puVar1;

  uint *puVar2;

  uint *puVar3;

  int iVar4;

  undefined4 *puVar5;

  int iVar6;

  uint local_10 [4];

  

  local_10[0] = *param_2;

  local_10[1] = param_2[1];

  local_10[2] = param_2[2];

  puVar2 = *(uint **)(param_1 + 0x100);

  local_10[3] = param_2[3];

  vec3_clamp01(local_10);

  *puVar2 = *puVar2 | 0xc;

  puVar2[2] = local_10[0];

  puVar2[3] = local_10[1];

  puVar2[4] = local_10[2];

  puVar2[5] = local_10[3];

  puVar2[6] = local_10[0];

  puVar2[7] = local_10[1];

  puVar2[8] = local_10[2];

  puVar2[9] = local_10[3];

  puVar2[10] = local_10[0];

  puVar2[0xb] = local_10[1];

  puVar2[0xc] = local_10[2];

  puVar2[0xd] = local_10[3];

  puVar3 = *(uint **)(param_1 + 0x100);

  if ((~*puVar3 & 1) != 0) {

    if (*(int *)(param_1 + 0xe8) == 0) {

      local_10[0] = 0;

      local_10[1] = 0;

      local_10[2] = 0;

      for (puVar5 = DAT_00632d68; puVar5 != (undefined4 *)0x0; puVar5 = (undefined4 *)*puVar5) {

        iVar6 = puVar5[3];

        if (((*(int *)(iVar6 + 0x1e0) == 0x5c) && (iVar4 = *(int *)(iVar6 + 0xe8), 0 < iVar4)) &&

           (iVar4 < 4)) {

          *(int *)(&stack0xffffffec + iVar4 * 4) = iVar6;

        }

      }

      iVar6 = 0;

      do {

        puVar1 = local_10 + iVar6;

        iVar6 = iVar6 + 1;

        if (*puVar1 == 0) goto LAB_0046fd76;

      } while (iVar6 < 3);

      iVar6 = 0;

LAB_0046fd76:

      *(int *)(param_1 + 0xe8) = iVar6;

    }

    puVar3[1] = 3;

    if ((~*puVar3 & 8) != 0) {

      puVar3[4] = 0x3f800000;

      puVar3[3] = 0x3f800000;

      puVar3[2] = 0x3f800000;

      *puVar3 = *puVar3 | 8;

    }

    if ((~*puVar3 & 4) != 0) {

      puVar3[10] = puVar3[2];

      puVar3[0xb] = puVar3[3];

      puVar3[0xc] = puVar3[4];

      puVar3[0xd] = puVar3[5];

      puVar3[6] = puVar3[2];

      puVar3[7] = puVar3[3];

      puVar3[8] = puVar3[4];

      puVar3[9] = puVar3[5];

      *puVar3 = *puVar3 | 4;

    }

    puVar3[0x16] = 0x3f800000;

    puVar3[0x14] = 0x5f7fffff;

    *(undefined4 *)(param_1 + 0xf4) = 1;

    *puVar3 = *puVar3 & 0xfffffffd | 1;

  }

  *puVar2 = *puVar2 & 0xfffffffd;

  return;

}

/* ===== obj_orient_flags @ 0x0046FE30 ===== */
void obj_orient_flags(int param_1,uint *param_2)



{

  int *piVar1;

  uint *puVar2;

  uint *puVar3;

  int iVar4;

  undefined4 *puVar5;

  int iVar6;

  int local_c [3];

  

  puVar2 = *(uint **)(param_1 + 0x100);

  *puVar2 = *puVar2 | 8;

  puVar2[2] = *param_2;

  puVar2[3] = param_2[1];

  puVar2[4] = param_2[2];

  puVar2[5] = param_2[3];

  vec3_clamp01(puVar2 + 2);

  puVar3 = *(uint **)(param_1 + 0x100);

  if ((~*puVar3 & 1) != 0) {

    if (*(int *)(param_1 + 0xe8) == 0) {

      local_c[0] = 0;

      local_c[1] = 0;

      local_c[2] = 0;

      for (puVar5 = DAT_00632d68; puVar5 != (undefined4 *)0x0; puVar5 = (undefined4 *)*puVar5) {

        iVar6 = puVar5[3];

        if (((*(int *)(iVar6 + 0x1e0) == 0x5c) && (iVar4 = *(int *)(iVar6 + 0xe8), 0 < iVar4)) &&

           (iVar4 < 4)) {

          *(int *)(&stack0xfffffff0 + iVar4 * 4) = iVar6;

        }

      }

      iVar6 = 0;

      do {

        piVar1 = local_c + iVar6;

        iVar6 = iVar6 + 1;

        if (*piVar1 == 0) goto LAB_0046fee0;

      } while (iVar6 < 3);

      iVar6 = 0;

LAB_0046fee0:

      *(int *)(param_1 + 0xe8) = iVar6;

    }

    puVar3[1] = 3;

    if ((~*puVar3 & 8) != 0) {

      puVar3[4] = 0x3f800000;

      puVar3[3] = 0x3f800000;

      puVar3[2] = 0x3f800000;

      *puVar3 = *puVar3 | 8;

    }

    if ((~*puVar3 & 4) != 0) {

      puVar3[10] = puVar3[2];

      puVar3[0xb] = puVar3[3];

      puVar3[0xc] = puVar3[4];

      puVar3[0xd] = puVar3[5];

      puVar3[6] = puVar3[2];

      puVar3[7] = puVar3[3];

      puVar3[8] = puVar3[4];

      puVar3[9] = puVar3[5];

      *puVar3 = *puVar3 | 4;

    }

    puVar3[0x16] = 0x3f800000;

    puVar3[0x14] = 0x5f7fffff;

    *(undefined4 *)(param_1 + 0xf4) = 1;

    *puVar3 = *puVar3 & 0xfffffffd | 1;

  }

  *puVar2 = *puVar2 & 0xfffffffd;

  return;

}

/* ===== obj_ai_recognize @ 0x0046FF90 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void obj_ai_recognize(uint param_1,int param_2)



{

  int *piVar1;

  uint *puVar2;

  int iVar3;

  undefined4 *puVar4;

  int iVar5;

  uint *puVar6;

  uint *puVar7;

  int local_74 [4];

  float local_64;

  float local_60;

  float local_5c;

  float local_58;

  float local_54;

  float local_50;

  float local_4c;

  float local_48;

  float local_44;

  float local_40;

  float local_3c;

  float local_38;

  

  puVar2 = *(uint **)(param_1 + 0x100);

  if ((~*puVar2 & 1) != 0) {

    if (*(int *)(param_1 + 0xe8) == 0) {

      local_74[0] = 0;

      local_74[1] = 0;

      local_74[2] = 0;

      for (puVar4 = DAT_00632d68; puVar4 != (undefined4 *)0x0; puVar4 = (undefined4 *)*puVar4) {

        iVar5 = puVar4[3];

        if (((*(int *)(iVar5 + 0x1e0) == 0x5c) && (iVar3 = *(int *)(iVar5 + 0xe8), 0 < iVar3)) &&

           (iVar3 < 4)) {

          *(int *)(&stack0xffffff88 + iVar3 * 4) = iVar5;

        }

      }

      iVar5 = 0;

      do {

        piVar1 = local_74 + iVar5;

        iVar5 = iVar5 + 1;

        if (*piVar1 == 0) goto LAB_00470010;

      } while (iVar5 < 3);

      iVar5 = 0;

LAB_00470010:

      *(int *)(param_1 + 0xe8) = iVar5;

    }

    puVar2[1] = 3;

    if ((~*puVar2 & 8) != 0) {

      puVar2[4] = 0x3f800000;

      puVar2[3] = 0x3f800000;

      puVar2[2] = 0x3f800000;

      *puVar2 = *puVar2 | 8;

    }

    if ((~*puVar2 & 4) != 0) {

      puVar2[10] = puVar2[2];

      puVar2[0xb] = puVar2[3];

      puVar2[0xc] = puVar2[4];

      puVar2[0xd] = puVar2[5];

      puVar2[6] = puVar2[2];

      puVar2[7] = puVar2[3];

      puVar2[8] = puVar2[4];

      puVar2[9] = puVar2[5];

      *puVar2 = *puVar2 | 4;

    }

    puVar2[0x16] = 0x3f800000;

    puVar2[0x14] = 0x5f7fffff;

    *(undefined4 *)(param_1 + 0xf4) = 1;

    *puVar2 = *puVar2 & 0xfffffffd | 1;

  }

  if ((*(int *)(param_1 + 0xe8) != 0) && (((~*puVar2 & 2) != 0 || (param_2 != 0)))) {

    puVar2[0xe] = *(uint *)(param_1 + 0xa0);

    puVar2[0xf] = *(uint *)(param_1 + 0xa4);

    puVar2[0x10] = *(uint *)(param_1 + 0xa8);

    ObjectCalculateTransform(param_1);

    puVar2[0x11] = (uint)-*(float *)(param_1 + 0x29c);

    puVar2[0x12] = (uint)-*(float *)(param_1 + 0x2ac);

    puVar2[0x13] = (uint)-*(float *)(param_1 + 700);

    puVar7 = (uint *)(local_74 + 3);

    puVar6 = puVar2;

    for (iVar5 = 0x1a; puVar6 = puVar6 + 1, iVar5 != 0; iVar5 = iVar5 + -1) {

      *puVar7 = *puVar6;

      puVar7 = puVar7 + 1;

    }

    local_64 = _DAT_006330b8 * local_64;

    local_60 = _DAT_006330b8 * local_60;

    local_5c = _DAT_006330b8 * local_5c;

    local_58 = _DAT_006330b8 * local_58;

    local_54 = _DAT_006330b8 * local_54;

    local_50 = _DAT_006330b8 * local_50;

    local_4c = _DAT_006330b8 * local_4c;

    local_48 = _DAT_006330b8 * local_48;

    local_44 = _DAT_006330b8 * local_44;

    local_40 = _DAT_006330b8 * local_40;

    local_3c = _DAT_006330b8 * local_3c;

    local_38 = _DAT_006330b8 * local_38;

    (**(code **)(DAT_00656420 + 0x5c))

              (DAT_00656420,*(int *)(param_1 + 0xe8) + -1,*(undefined4 *)(param_1 + 0xf4),

               local_74 + 3);

    if (*(int *)(param_1 + 0xe8) == 1) {

      DAT_006330b4 = -(uint)(*(int *)(param_1 + 0xf4) != 0) & param_1;

    }

    *puVar2 = *puVar2 | 2;

    puVar2[0x1b] = puVar2[0x1b] + 1;

  }

  return;

}

