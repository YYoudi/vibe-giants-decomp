/* Giants 1.449 — module region_004c
 * 87 functions (87 named) — decompiled, names from PS2 symbols
 * Original source: C:\Giants\source\region_004c.c(pp) (assert-string evidence)
 */

/* ===== fxb_firecircle_create @ 0x004C0210 ===== */
void fxb_firecircle_create(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)



{

  undefined4 *puVar1;

  int iVar2;

  undefined4 uVar3;

  int iVar4;

  char *pcVar5;

  undefined4 uVar6;

  undefined1 *puVar7;

  undefined4 local_3c;

  undefined4 local_38;

  undefined1 local_34 [4];

  undefined4 local_30;

  undefined4 local_2c;

  undefined4 local_28;

  undefined4 local_24;

  undefined1 *local_c;

  int local_8;

  

  iVar2 = object_allocate_type(0x399,0);

  object_change_ospec(iVar2,0x58);

  *(undefined4 *)(iVar2 + 0x18c) = *(undefined4 *)(param_1 + 0x18c);

  *(int *)(iVar2 + 0x274) = param_1;

  *(uint *)(iVar2 + 0xd8) = *(uint *)(iVar2 + 0xd8) | 0x40000000;

  *(uint *)(iVar2 + 0x1c8) = *(uint *)(iVar2 + 0x1c8) & 0xfffdffff | 0x800;

  *(undefined4 *)(iVar2 + 0xec) = *(undefined4 *)(DAT_00632ed8 + 0x83c);

  *(int *)(iVar2 + 0x274) = param_1;

  object_set_location_p3d(iVar2,param_2);

  puVar1 = *(undefined4 **)(iVar2 + 0x100);

  local_30 = *(undefined4 *)(iVar2 + 0xa0);

  local_2c = *(undefined4 *)(iVar2 + 0xa4);

  puVar7 = local_34;

  local_28 = *(undefined4 *)(iVar2 + 0xa8);

  uVar6 = 0x2a;

  pcVar5 = s_FXB_FireCircle_00561058;

  local_c = &LAB_004c6fe0;

  local_24 = 8;

  local_8 = iVar2;

  uVar3 = fx_get_free_effect__Fv();

  *puVar1 = uVar3;

  iVar4 = object_allocate_type(0x39b,0,pcVar5,uVar6,puVar7);

  puVar1[1] = iVar4;

  *(undefined4 *)(iVar4 + 0x18c) = *(undefined4 *)(param_1 + 0x18c);

  *(int *)(puVar1[1] + 0x274) = param_1;

  iVar4 = fx_create(param_1);

  if (iVar4 == 0) {

    *(undefined4 *)(iVar2 + 0x188) = param_3;

    *(undefined4 *)(puVar1[1] + 0x188) = param_4;

  }

  object_set_location_p3d(puVar1[1],param_2);

  *(undefined4 *)(puVar1[1] + 0xc4) = 0x40a00000;

  iVar4 = reaper_0052e4a0(param_1);

  if (iVar4 != 0) {

    local_3c = *(undefined4 *)(iVar2 + 0x188);

    local_38 = *(undefined4 *)(puVar1[1] + 0x188);

    reaper_00530bd0(param_1,0,2,0,0x1b,&local_3c);

  }

  uVar3 = sound_get_free_sequence__Fv();

  puVar1[3] = uVar3;

  return;

}

/* ===== reaper_finish_cloak @ 0x004C03A0 ===== */
/* PS2 candidate: reaper_finish_cloak (conf 0.4) */



void reaper_finish_cloak(int param_1,undefined4 param_2)



{

  undefined4 uVar1;

  uint *puVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  code *pcVar6;

  float fStack_5c;

  float fStack_58;

  float fStack_54;

  undefined4 uStack_50;

  undefined4 uStack_4c;

  undefined4 uStack_48;

  undefined1 local_44 [16];

  undefined4 uStack_34;

  undefined4 uStack_24;

  undefined4 uStack_14;

  

  puVar2 = *(uint **)(param_1 + 0x100);

  if (((*(uint *)(param_1 + 0xd8) & 0x80000) == 0) || ((**(byte **)(param_1 + 0x104) & 0x40) != 0))

  {

    iVar3 = fx_create(param_1);

    if (iVar3 != 0) {

      reaper_fire_spell__FP6OBJECTiP3P3DT0i(param_1,0x2c,param_2,0,0xffffffff);

    }

    *puVar2 = *puVar2 & 0xffffffbf;

    return;

  }

  iVar3 = fx_create(param_1);

  if (iVar3 == 0) {

    *puVar2 = *puVar2 | 0x40;

  }

  else {

    iVar4 = PROJ_DefGet(0x2c);

    iVar5 = PROJ_GetCustom(0x2c);

    pcVar6 = reaper_xhair_validate__FP6OBJECTPv;

    iVar3 = param_1;

    if (iVar5 != 0) {

      pcVar6 = *(code **)(iVar5 + 8);

      iVar3 = param_1 + 0x18c;

    }

    if (iVar4 != 0) {

      uVar1 = *(undefined4 *)(DAT_00632ed8 + 0x1058);

      iVar4 = camera_cursor_fire();

      if (iVar4 == 0) {

        iVar4 = gun_find_right(param_1);

        (*(code *)PTR_crt_matrix_mul_00580c18)

                  (local_44,iVar4 + 0x294,*(undefined4 *)(iVar4 + 0x2dc));

        fStack_5c = -*(float *)(param_1 + 0x29c);

        fStack_58 = -*(float *)(param_1 + 0x2ac);

        fStack_54 = -*(float *)(param_1 + 700);

        normalize__FPfN20(&fStack_5c,&fStack_58,&fStack_54);

        uStack_50 = uStack_34;

        uStack_4c = uStack_24;

        uStack_48 = uStack_14;

        project_vector_to_object(pcVar6,iVar3,uVar1,puVar2 + 0x393,&uStack_50,&fStack_5c);

      }

      else {

        project_cursor_to_object(pcVar6,iVar3,uVar1,puVar2 + 0x393);

      }

      *puVar2 = *puVar2 | 0x40;

      iVar3 = reaper_0052e4a0(param_1);

      if (iVar3 != 0) {

        reaper_00530bd0(param_1,0,0,0,0x27,0);

        return;

      }

    }

  }

  return;

}

/* ===== reaper_create_fake_reaper__FP6OBJECTP3P3Dfi @ 0x004C0550 ===== */
/* PS2 candidate: reaper_create_fake_reaper__FP6OBJECTP3P3Dfi (conf 0.44) */



void reaper_create_fake_reaper__FP6OBJECTP3P3Dfi(float *param_1,float *param_2)



{

  float *pfVar1;

  int iVar2;

  int iVar3;

  OBJECT *obj;

  int iVar4;

  float10 fVar5;

  float10 fVar6;

  float local_58;

  float local_54;

  float local_50;

  undefined1 local_4c [16];

  float local_3c;

  float local_30 [9];

  float afStack_c [3];

  

  iVar2 = (int)param_1;

  pfVar1 = (float *)((int)param_1 + 0xa0);

  *pfVar1 = *param_2;

  *(float *)((int)param_1 + 0xa4) = param_2[1];

  *(float *)((int)param_1 + 0xa8) = param_2[2];

  *(float *)((int)param_1 + 0xac) = *param_2;

  *(float *)((int)param_1 + 0xb0) = param_2[1];

  *(float *)((int)param_1 + 0xb4) = param_2[2];

  sound_play_player(0x3c0,param_1);

  param_1 = local_30;

  iVar4 = 0;

  do {

    fVar5 = (float10)rndfloatrange(0x40a00000,0x41200000);

    fVar6 = (float10)rndfloatrange(-*(float *)(DAT_00632ed8 + 0x75c),

                                   *(undefined4 *)(DAT_00632ed8 + 0x75c));

    local_58 = (float)(fVar6 + (float10)*pfVar1);

    fVar6 = (float10)rndfloatrange(-*(float *)(DAT_00632ed8 + 0x75c),

                                   *(undefined4 *)(DAT_00632ed8 + 0x75c));

    local_50 = *(float *)(iVar2 + 0xa8);

    local_54 = (float)(fVar6 + (float10)*(float *)(iVar2 + 0xa4));

    ground_height_at(&local_58,local_4c);

    local_50 = local_3c;

    iVar3 = reaper_0052e4a0(iVar2);

    if (iVar3 != 0) {

      *param_1 = local_58;

      param_1[1] = local_54;

      param_1[2] = local_50;

      afStack_c[iVar4] = (float)fVar5;

    }

    iVar3 = fx_create(iVar2);

    if (iVar3 != 0) {

      obj = (OBJECT *)object_allocate_type(*(undefined4 *)(iVar2 + 4),0x80000000);

      obj->ai_state_b = *(dword *)(iVar2 + 0x18c);

      object_create_child(obj,1,0x29d);

      object_change_ospec(obj,0x55);

      *(float *)&obj->field_0xf4 = (float)fVar5;

      object_set_location_p3d(obj,&local_58);

      *(uint *)&obj->field_0x1c8 = *(uint *)&obj->field_0x1c8 | 0x20000;

      *(int *)&obj->field_0x274 = iVar2;

      if ((DAT_00560c50 != 0xfe) && (*(int *)(*(int *)(iVar2 + 8) + 8 + DAT_00560c50 * 4) != 0)) {

        ObjectSetAnim(obj);

      }

      sound_play_obj(0x3c0);

    }

    iVar4 = iVar4 + 1;

    param_1 = param_1 + 3;

  } while (iVar4 < 3);

  iVar4 = reaper_0052e4a0(iVar2);

  if (iVar4 != 0) {

    reaper_00530bd0(iVar2,0xc,0,0,0x14,local_30);

  }

  return;

}

/* ===== reaper_fire_sword__FP6OBJECT @ 0x004C0810 ===== */
/* PS2 candidate: reaper_fire_sword__FP6OBJECT (conf 0.456) */



void reaper_fire_sword__FP6OBJECT(float param_1)



{

  float fVar1;

  bool bVar2;

  int iVar3;

  int *piVar4;

  int iVar5;

  uint uVar6;

  int iVar7;

  undefined4 uVar8;

  uint uVar9;

  byte bVar10;

  float10 fVar11;

  float local_58;

  int *local_54;

  float local_50;

  float local_4c;

  float local_48;

  float local_44;

  float local_40;

  float local_3c;

  float local_38;

  float local_30;

  undefined4 local_2c;

  float local_28;

  float local_18;

  undefined4 local_14;

  undefined4 local_10;

  

  iVar3 = (int)param_1;

  fVar1 = *(float *)((int)param_1 + 0x14);

  iVar5 = *(int *)((int)param_1 + 0x100);

  iVar7 = *(int *)(iVar5 + 0x5c);

  if ((((*(int *)(iVar5 + 0xf20) != 0) || (*(int *)(iVar5 + 0xf24) != 0)) ||

      ((0x30 < iVar7 && ((iVar7 < 0x38 || (iVar7 == 0x4c)))))) || (*(int *)(iVar5 + 0xe2c) != 0)) {

    *(uint *)((int)param_1 + 0x20c) = *(uint *)((int)param_1 + 0x20c) & 0xfdfffeff;

  }

  if (((*(uint *)((int)param_1 + 0x20c) & 0x100) != 0) &&

     ((*(uint *)((int)param_1 + 0xdc) & 0x8000000) == 0)) {

    *(uint *)((int)param_1 + 0xe0) = *(uint *)((int)param_1 + 0xe0) | 0x200;

    *(int *)(iVar5 + 4) = *(int *)(iVar5 + 4) + 1;

    param_1 = fVar1;

    iVar5 = reaper_0052e4a0(iVar3);

    fVar1 = param_1;

    if (iVar5 != 0) {

      reaper_00530bd0(iVar3,0,0,0,0x29,0);

      fVar1 = param_1;

    }

  }

  param_1 = fVar1;

  if ((*(uint *)(iVar3 + 0x20c) & 0x100) == 0) {

    uVar6 = *(uint *)(iVar3 + 0xdc) & 0xf7ffffff;

  }

  else {

    uVar6 = *(uint *)(iVar3 + 0xdc) | 0x8000000;

  }

  uVar9 = *(uint *)(iVar3 + 0xe0);

  *(uint *)(iVar3 + 0xdc) = uVar6;

  if ((uVar9 & 0x400) != 0) {

    return;

  }

  if (iVar7 == 0xc) {

    bVar2 = param_1 < 0.2;

LAB_004c0a9a:

    if (bVar2) goto LAB_004c0920;

    bVar10 = param_1 < 0.3 | (byte)((ushort)((ushort)(param_1 == 0.3) << 0xe) >> 8);

LAB_004c0915:

    if ((POPCOUNT(bVar10) & 1U) != 0) {

LAB_004c0b10:

      uVar9 = uVar9 | 0x2000;

      goto LAB_004c0926;

    }

  }

  else {

    if (iVar7 == 0xd) {

      if (param_1 < 0.26666668) goto LAB_004c0920;

      bVar10 = param_1 < 0.36666667 | (byte)((ushort)((ushort)(param_1 == 0.36666667) << 0xe) >> 8);

      goto LAB_004c0915;

    }

    if (iVar7 == 0xe) {

      bVar2 = param_1 < 0.2;

      goto LAB_004c0a9a;

    }

    if (iVar7 != 0xf) {

      if (iVar7 == 0x10) {

LAB_004c0a67:

        if (0.1 <= param_1) {

          bVar10 = param_1 < 0.2 | (byte)((ushort)((ushort)(param_1 == 0.2) << 0xe) >> 8);

          goto LAB_004c0915;

        }

        goto LAB_004c0920;

      }

      if (iVar7 == 0x12) {

        if (0.3 <= param_1) {

          bVar10 = param_1 < 0.4 | (byte)((ushort)((ushort)(param_1 == 0.4) << 0xe) >> 8);

          goto LAB_004c0915;

        }

        goto LAB_004c0920;

      }

      if (iVar7 == 0x1f) goto LAB_004c0a67;

      if (iVar7 == 0x1a) {

        bVar2 = param_1 < 0.16666667;

        goto LAB_004c0a9a;

      }

      if (iVar7 == 0x16) {

        if (0.2 <= param_1) {

          bVar10 = param_1 < 0.33333334 |

                   (byte)((ushort)((ushort)(param_1 == 0.33333334) << 0xe) >> 8);

          goto LAB_004c0915;

        }

        goto LAB_004c0920;

      }

      if (((iVar7 != 7) || (param_1 < 0.22222222)) ||

         (param_1 < 0.5555556 == (param_1 == 0.5555556))) goto LAB_004c0920;

      goto LAB_004c0b10;

    }

    if (0.1 <= param_1) {

      bVar10 = param_1 < 0.23333333 | (byte)((ushort)((ushort)(param_1 == 0.23333333) << 0xe) >> 8);

      goto LAB_004c0915;

    }

  }

LAB_004c0920:

  uVar9 = uVar9 & 0xffffdfff;

LAB_004c0926:

  *(uint *)(iVar3 + 0xe0) = uVar9;

  if ((uVar9 & 0x2000) != 0) {

    mecc_indicate_shots_fired__FP6OBJECT(iVar3);

    local_58 = *(float *)(DAT_00632ed8 + 0xaf0);

    iVar5 = 0;

    local_54 = DAT_00632d68;

    piVar4 = local_54;

    if (DAT_00632d68 != (int *)0x0) {

      do {

        iVar7 = local_54[3];

        if ((((~*(uint *)(iVar7 + 0x1c8) >> 0x11 & 1) == 0 &&

              (*(uint *)(iVar7 + 0xd8) & 0x4000c000) == 0) && (iVar7 != iVar3)) &&

           ((*(int *)(iVar7 + 0x210) != iVar3 && (*(int *)(iVar7 + 0x274) != iVar3)))) {

          fVar11 = (float10)distance2d__FP3P3DT0(iVar3 + 0xa0,iVar7 + 0xa0);

          param_1 = (float)(fVar11 - (float10)*(float *)(iVar7 + 0x154));

          fVar1 = local_58;

          if (iVar5 != 0) {

            if (*(char *)(iVar5 + 0x1f5) == '\0') {

              if (*(char *)(iVar7 + 0x1f5) != '\0') goto LAB_004c0b9c;

            }

            else if (*(char *)(iVar7 + 0x1f5) == '\0') {

              fVar1 = *(float *)(DAT_00632ed8 + 0xaf0);

            }

          }

          if ((param_1 <= fVar1) &&

             (ABS(*(float *)(iVar3 + 0xa8) - *(float *)(iVar7 + 0xa8)) <=

              *(float *)(DAT_00632ed8 + 0x1024))) {

            fVar11 = (float10)dirfcalcp3d__FP3P3DT0(iVar3 + 0xa0,iVar7 + 0xa0);

            local_50 = (float)fVar11;

            fVar11 = (float10)playerobj_turn(local_50,*(undefined4 *)(iVar3 + 200));

            if (ABS(fVar11) <= (float10)90.0) {

              local_58 = param_1;

              iVar5 = iVar7;

            }

          }

        }

LAB_004c0b9c:

        local_54 = (int *)*local_54;

      } while (local_54 != (int *)0x0);

      piVar4 = (int *)0x0;

      if (iVar5 != 0) {

        iVar7 = fx_create(iVar3);

        if (iVar7 == 0) {

          return;

        }

        if ((~*(uint *)(iVar5 + 0x1c8) >> 0x11 & 1) != 0 ||

            (*(uint *)(iVar5 + 0xd8) & 0x4000c000) != 0) {

          local_4c = *(float *)(iVar5 + 0xa0);

          local_48 = *(float *)(iVar5 + 0xa4);

          local_44 = *(float *)(iVar5 + 0x1e8) * *(float *)(iVar5 + 0xc4) + *(float *)(iVar5 + 0xa8)

          ;

          uVar8 = gun_find_right(iVar3);

          playerobj_eval_refpt(uVar8,0,&local_40);

          if (local_38 < local_44) {

            local_44 = local_38;

          }

          if (*(int *)(iVar5 + 4) == 0x43b) {

            sound_play_3dpos(0x18e,&local_4c);

          }

          sound_play_3dpos(0x3c9,&local_4c);

          *(uint *)(iVar3 + 0xe0) = *(uint *)(iVar3 + 0xe0) | 0x1000;

          sine_cos_lookup(*(float *)(iVar3 + 200) + 180.0,&local_50,&param_1);

          if (*(char *)(iVar5 + 0x1f5) != '\0') {

            local_18 = *(float *)(iVar3 + 200) + 180.0;

            local_30 = local_4c;

            local_10 = 0;

            local_14 = 0;

            local_2c = local_48;

            local_28 = local_44;

            fx_get_free_effect__Fv();

          }

          *(uint *)(iVar3 + 0xe0) = *(uint *)(iVar3 + 0xe0) | 0x400;

          return;

        }

        if (*(int *)(iVar5 + 4) == 0x232) {

          uVar8 = *(undefined4 *)(DAT_00632ed8 + 0x8ec);

        }

        else {

          uVar8 = *(undefined4 *)(DAT_00632ed8 + 0x8e8);

        }

        obj_damage_apply(0x17,uVar8,iVar5,iVar3,0,0);

        *(uint *)(iVar3 + 0xe0) = *(uint *)(iVar3 + 0xe0) | 0x400;

        local_4c = *(float *)(iVar5 + 0xa0);

        local_48 = *(float *)(iVar5 + 0xa4);

        local_44 = *(float *)(iVar5 + 0x1e8) * *(float *)(iVar5 + 0xc4) + *(float *)(iVar5 + 0xa8);

        uVar8 = gun_find_right(iVar3);

        playerobj_eval_refpt(uVar8,0,&local_40);

        if (local_38 < local_44) {

          local_44 = local_38;

        }

        if (*(int *)(iVar5 + 4) == 0x43b) {

          sound_play_3dpos(0x18e,&local_4c);

        }

        if (*(char *)(iVar5 + 0x1f5) != '\0') {

          sound_play_3dpos(0x3c9,&local_4c);

          *(uint *)(iVar3 + 0xe0) = *(uint *)(iVar3 + 0xe0) | 0x1000;

          sine_cos_lookup(*(float *)(iVar3 + 200) + 180.0,&local_50,&param_1);

          if (*(char *)(iVar5 + 0x1f5) == '\0') {

            return;

          }

          local_18 = *(float *)(iVar3 + 200) + 180.0;

          local_30 = local_4c;

          local_10 = 0;

          local_14 = 0;

          local_2c = local_48;

          local_28 = local_44;

          fx_get_free_effect__Fv();

          return;

        }

        iVar5 = crt_rand_scaled(100);

        if (iVar5 < 0x21) {

          sound_play_3dpos(0x3ca,&local_4c);

          return;

        }

        if (iVar5 < 0x42) {

          sound_play_3dpos(0x690,&local_4c);

          return;

        }

        sound_play_3dpos(0x691,&local_4c);

        return;

      }

    }

    local_54 = piVar4;

    sine_cos_lookup(*(undefined4 *)(iVar3 + 200),&param_1,&local_54);

    local_4c = *(float *)(iVar3 + 0xa0);

    local_48 = *(float *)(iVar3 + 0xa4);

    local_44 = *(float *)(iVar3 + 0x1e8) * *(float *)(iVar3 + 0xc4) + *(float *)(iVar3 + 0xa8);

    local_40 = param_1 * 18.0 + local_4c;

    local_3c = local_48 - (float)local_54 * 18.0;

    local_38 = local_44;

    iVar5 = line_of_sight_grid(&local_4c,&local_40);

    if (iVar5 == 0) {

      *(uint *)(iVar3 + 0xe0) = *(uint *)(iVar3 + 0xe0) | 0x1000;

      *(float *)(iVar3 + 0x128) = *(float *)(iVar3 + 0x128) - param_1 * 40.0;

      *(float *)(iVar3 + 300) = (float)local_54 * 40.0 + *(float *)(iVar3 + 300);

      smoke_object_spawn(&local_40);

    }

  }

  return;

}

/* ===== reaper_tornado_create @ 0x004C0FC0 ===== */
/* PS2 candidate: reaper_tornado_create (conf 0.493) */



void reaper_tornado_create(int param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)



{

  int iVar1;

  OBJECT *obj;

  int iVar2;

  undefined4 local_14;

  undefined4 local_10;

  undefined4 local_c;

  undefined4 local_8;

  undefined4 local_4;

  

  iVar1 = object_allocate_type(0x28,0x80000000);

  if (param_1 != 0) {

    *(undefined4 *)(iVar1 + 0x18c) = *(undefined4 *)(param_1 + 0x18c);

  }

  object_set_location_p3d(iVar1,param_2);

  *(uint *)(iVar1 + 0xd8) = *(uint *)(iVar1 + 0xd8) | 0x40000000;

  *(undefined4 *)(iVar1 + 0xec) = *(undefined4 *)(DAT_00632ed8 + 0x314);

  *(undefined4 *)(iVar1 + 0xe4) = 0;

  *(undefined4 *)(iVar1 + 0xf4) = 0;

  *(undefined4 *)(iVar1 + 0xfc) = 0x3f000000;

  obj = (OBJECT *)object_spawn_small(iVar1,0x18,0,0,0);

  *(undefined4 *)&obj->field_0x210 = 0;

  obj->flags = obj->flags | 0x14;

  ObjectSetAnim(obj);

  obj->pad_184 = 0x3f800000;

  *(undefined4 *)&obj->field_0xfc = 0x3f000000;

  *(OBJECT **)(iVar1 + 0x274) = obj;

  if (param_1 != 0) {

    *(int *)(param_1 + 0x274) = iVar1;

    if ((**(byte **)(param_1 + 0x104) & 0x40) == 0) {

      sound_play_player(0x39e,param_1);

      *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 0x10000000;

    }

    iVar2 = reaper_0052e4a0(param_1);

    if (iVar2 == 0) {

      iVar2 = fx_create(param_1);

      if (iVar2 == 0) {

        *(undefined4 *)&obj->field_0x188 = param_3;

        *(undefined4 *)(iVar1 + 0x188) = param_4;

      }

    }

    else {

      local_14 = *param_2;

      local_10 = param_2[1];

      local_c = param_2[2];

      local_8 = *(undefined4 *)&obj->field_0x188;

      local_4 = *(undefined4 *)(iVar1 + 0x188);

      reaper_00530bd0(param_1,3,2,0,10,&local_14);

    }

  }

  sound_get_free_sequence__Fv();

  return;

}

/* ===== reaper_check_enter_jet_ski__FP6OBJECT @ 0x004C1170 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* PS2 candidate: reaper_check_enter_jet_ski__FP6OBJECT (conf 0.463) */



void reaper_check_enter_jet_ski__FP6OBJECT(int param_1)



{

  char cVar1;

  int iVar2;

  undefined4 *puVar3;

  int iVar4;

  int *piVar5;

  int iVar6;

  char *pcVar7;

  int iVar8;

  char *pcVar9;

  float10 fVar10;

  float local_5c;

  float local_58;

  float local_54;

  float local_50;

  float local_4c;

  float local_48;

  undefined4 local_44 [2];

  float local_3c;

  float local_2c;

  float local_1c;

  

  iVar4 = param_1;

  iVar2 = *(int *)(param_1 + 0x100);

  fxb_splash_create(param_1);

  if (((*(byte *)(iVar4 + 0x20c) & 8) != 0) && (-1 < *(int *)(iVar2 + 0xdb0))) {

    obj_link_slot_clear(iVar4,*(undefined4 *)(iVar2 + 0xd3c + *(int *)(iVar2 + 0xdb0) * 0xc),

                        0xffffffff,0);

  }

  if ((*(byte *)(iVar4 + 0x20c) & 0x10) != 0) {

    reaper_ability_sound(iVar4);

  }

  if ((*(byte *)(iVar4 + 0x20c) & 0x20) != 0) {

    reaper_cast_cloak_firecircle

              (iVar4,*(undefined4 *)(iVar2 + 0xd3c + *(int *)(iVar2 + 0xdb0) * 0xc));

    *(uint *)(iVar4 + 0x20c) = *(uint *)(iVar4 + 0x20c) & 0xffff83ff;

  }

  fVar10 = (float10)FRateGetSecsframe(iVar4,0);

  fVar10 = fVar10 + (float10)*(float *)(iVar2 + 4000);

  *(float *)(iVar2 + 4000) = (float)fVar10;

  if (((*(uint *)(iVar4 + 0x20c) & 0x400000) != 0) &&

     ((float10)*(float *)(DAT_00632ed8 + 0x1568) <= fVar10)) {

    iVar8 = 0;

    piVar5 = (int *)(*(int *)(iVar4 + 0x100) + 0xd9c);

    do {

      if ((piVar5[-1] == 0x3f) && (0 < *piVar5)) {

        if ((**(byte **)(iVar4 + 0x104) & 0x40) == 0) {

          reaper_cast_cloak_firecircle(iVar4,0x3f);

        }

        break;

      }

      iVar8 = iVar8 + 1;

      piVar5 = piVar5 + 2;

    } while (iVar8 < 2);

  }

  if ((*(uint *)(iVar4 + 0x20c) & 0x800000) != 0) {

    iVar8 = 0;

    piVar5 = (int *)(*(int *)(iVar4 + 0x100) + 0xd9c);

    do {

      if ((piVar5[-1] == 0x48) && (0 < *piVar5)) {

        local_44[0] = 0;

        GEO_MatBuildXYZ(local_44,-*(float *)(DAT_00632ed8 + 0x120c),0,*(undefined4 *)(iVar4 + 200));

        playerobj_eval_refpt(iVar4,0xffffffff,&local_5c);

        local_50 = local_3c * -1000.0 + local_5c;

        local_4c = local_2c * -1000.0 + local_58;

        local_48 = local_1c * -1000.0 + local_54;

        reaper_fire_spell__FP6OBJECTiP3P3DT0i(iVar4,0x32,&local_50,0,0xffffffff);

        break;

      }

      iVar8 = iVar8 + 1;

      piVar5 = piVar5 + 2;

    } while (iVar8 < 2);

  }

  if (((*(uint *)(iVar4 + 0x20c) & 0x400) != 0) && (*(int *)(iVar2 + 0xd3c) != -1)) {

    if ((*(int *)(iVar2 + 0xdb0) == 0) && (DAT_00633104 == 0)) {

      reaper_cast_cloak_firecircle(iVar4,*(int *)(iVar2 + 0xd3c));

    }

    else {

      *(undefined4 *)(iVar2 + 0xdb0) = 0;

    }

  }

  if (((*(uint *)(iVar4 + 0x20c) & 0x800) != 0) && (*(int *)(iVar2 + 0xd48) != -1)) {

    if ((*(int *)(iVar2 + 0xdb0) == 1) && (DAT_00633104 == 0)) {

      reaper_cast_cloak_firecircle(iVar4,*(int *)(iVar2 + 0xd48));

    }

    else {

      *(undefined4 *)(iVar2 + 0xdb0) = 1;

    }

  }

  if (((*(uint *)(iVar4 + 0x20c) & 0x1000) != 0) && (*(int *)(iVar2 + 0xd54) != -1)) {

    if ((*(int *)(iVar2 + 0xdb0) == 2) && (DAT_00633104 == 0)) {

      reaper_cast_cloak_firecircle(iVar4,*(int *)(iVar2 + 0xd54));

    }

    else {

      *(undefined4 *)(iVar2 + 0xdb0) = 2;

    }

  }

  if (((*(uint *)(iVar4 + 0x20c) & 0x2000) != 0) && (*(int *)(iVar2 + 0xd60) != -1)) {

    if ((*(int *)(iVar2 + 0xdb0) == 3) && (DAT_00633104 == 0)) {

      reaper_cast_cloak_firecircle(iVar4,*(int *)(iVar2 + 0xd60));

    }

    else {

      *(undefined4 *)(iVar2 + 0xdb0) = 3;

    }

  }

  if (((*(uint *)(iVar4 + 0x20c) & 0x4000) != 0) && (*(int *)(iVar2 + 0xd6c) != -1)) {

    if ((*(int *)(iVar2 + 0xdb0) == 4) && (DAT_00633104 == 0)) {

      reaper_cast_cloak_firecircle(iVar4,*(int *)(iVar2 + 0xd6c));

    }

    else {

      *(undefined4 *)(iVar2 + 0xdb0) = 4;

    }

  }

  iVar2 = *(int *)(iVar4 + 0x100);

  iVar8 = fx_create(iVar4);

  if (iVar8 != 0) {

    fVar10 = (float10)FRateGetSecsframe(0,0);

    fVar10 = (float10)*(float *)(iVar2 + 0xfa8) - fVar10;

    *(float *)(iVar2 + 0xfa8) = (float)fVar10;

    puVar3 = DAT_00632d68;

    if (fVar10 < (float10)0.0) {

      for (; puVar3 != (undefined4 *)0x0; puVar3 = (undefined4 *)*puVar3) {

        iVar8 = puVar3[3];

        if ((((-1 < (char)((uint)*(undefined4 *)(iVar8 + 0xd8) >> 8)) &&

             (iVar6 = ObjIsJetski(iVar8), iVar6 != 0)) &&

            ((*(int *)(iVar8 + 0x18c) == *(int *)(iVar4 + 0x18c) || (*(int *)(iVar8 + 0x18c) == 0)))

            ) && (((*(int *)(iVar8 + 0x274) == 0 &&

                   (fVar10 = (float10)distancesq3d(iVar4 + 0xa0,iVar8 + 0xa0),

                   fVar10 <= (float10)100.0)) && (*(int *)(iVar8 + 0x210) == 0)))) {

          iVar6 = reaper_has_linked_smartie(iVar4);

          if (iVar6 == 0) {

            if ((*(byte *)(iVar4 + 0xe0) & 2) == 0) {

              iVar6 = reaper_0052e4a0(iVar4);

              if (iVar6 == 0) {

                object_attach_target(iVar4,iVar8);

              }

              else {

                param_1 = *(undefined4 *)(iVar4 + 0x188);

                comm_chat_send_2(iVar8,0,1,0,4,&param_1);

                charger_do_fx__FP6OBJECTiii(iVar8,4,4,&param_1);

              }

            }

            goto LAB_004c157c;

          }

          pcVar7 = (char *)TextGetPtr(s_FlagHintDriveGyro_0055bccc);

          pcVar9 = &DAT_00632c10;

          do {

            cVar1 = *pcVar7;

            pcVar7 = pcVar7 + 1;

            *pcVar9 = cVar1;

            pcVar9 = pcVar9 + 1;

          } while (cVar1 != '\0');

          _DAT_00632d10 = 0x3f800000;

        }

      }

      *(uint *)(iVar4 + 0xe0) = *(uint *)(iVar4 + 0xe0) & 0xfffffffd;

LAB_004c157c:

      *(undefined4 *)(iVar2 + 0xfa8) = 0x3f000000;

    }

  }

  return;

}

/* ===== reaper_cast_cloak_firecircle @ 0x004C15F0 ===== */
/* PS2 candidate: evilreaper_can_cast_spell__FP6OBJECT (conf 0.473) */



void reaper_cast_cloak_firecircle(int param_1,int param_2)



{

  int iVar1;

  int iVar2;

  int *piVar3;

  int iVar4;

  int iVar5;

  float local_34;

  float local_30;

  float local_2c;

  float local_28;

  float local_24;

  float local_20;

  undefined1 local_1c [16];

  float local_c;

  

  iVar1 = param_1;

  iVar2 = *(int *)(param_1 + 0x100);

  if (*(int *)(iVar2 + 0xf38) == 0) {

    if (param_2 != 0x3f) {

      return;

    }

    iVar5 = 0;

    piVar3 = (int *)(iVar2 + 0xd9c);

    while ((piVar3[-1] != 0x3f || (*piVar3 < 1))) {

      iVar5 = iVar5 + 1;

      piVar3 = piVar3 + 2;

      if (1 < iVar5) {

        return;

      }

    }

  }

  switch(param_2) {

  case 0x15:

    iVar5 = *(int *)(iVar2 + 0xf48);

    iVar4 = reaper_0052e4a0(param_1);

    if (iVar4 != 0) {

      param_1 = *(int *)(iVar5 + 0x188);

      reaper_00530bd0(iVar1,0,1,0,0x16,&param_1);

    }

    *(int *)(iVar2 + 0xea4) = iVar5;

    iVar5 = reaper_can_do_spell_anim__FP6OBJECT(iVar1);

    if (iVar5 == 0) {

      reaper_finish_smartie_grab__FP6OBJECT();

    }

    else {

      sound_play_player(0x39c,iVar1);

      *(uint *)(iVar1 + 0xe0) = *(uint *)(iVar1 + 0xe0) | 0x80000;

    }

    iVar5 = *(int *)(iVar1 + 0x100);

    iVar1 = *(int *)(iVar5 + 0xdb0) * 3 + 0x351;

    *(float *)(iVar5 + iVar1 * 4) =

         *(float *)(iVar5 + iVar1 * 4) - *(float *)(iVar5 + 0xd40 + *(int *)(iVar5 + 0xdb0) * 0xc);

    *(undefined4 *)(iVar2 + 0xda8) = *(undefined4 *)(DAT_00632ed8 + 0x14e8);

    return;

  case 0x16:

    iVar1 = *(int *)(iVar2 + 0xdb0) * 3 + 0x351;

    *(float *)(iVar2 + iVar1 * 4) =

         *(float *)(iVar2 + iVar1 * 4) - *(float *)(iVar2 + 0xd40 + *(int *)(iVar2 + 0xdb0) * 0xc);

    reaper_ability_playersound2(param_1,iVar2 + 0xf4c);

    *(undefined4 *)(iVar2 + 0xda8) = *(undefined4 *)(DAT_00632ed8 + 0x14f8);

    return;

  case 0x17:

    iVar5 = *(int *)(iVar2 + 0xdb0) * 3 + 0x351;

    *(float *)(iVar2 + iVar5 * 4) =

         *(float *)(iVar2 + iVar5 * 4) - *(float *)(iVar2 + 0xd40 + *(int *)(iVar2 + 0xdb0) * 0xc);

    iVar5 = reaper_can_do_spell_anim__FP6OBJECT(param_1);

    if (iVar5 == 0) {

      fxb_cloak_create();

    }

    else {

      sound_play_player(0x39d,iVar1);

      *(uint *)(iVar1 + 0xe0) = *(uint *)(iVar1 + 0xe0) | 0x80000000;

    }

    iVar5 = reaper_0052e4a0(iVar1);

    if (iVar5 != 0) {

      reaper_00530bd0(iVar1,0,0,0,0x12,0);

    }

    *(undefined4 *)(iVar2 + 0xda8) = *(undefined4 *)(DAT_00632ed8 + 0x14ec);

    return;

  case 0x18:

    reaper_finish_teleport(param_1,iVar2 + 0xf4c);

    reaper_mana_decrement(iVar1);

    *(undefined4 *)(iVar2 + 0xda8) = *(undefined4 *)(DAT_00632ed8 + 0x1508);

    return;

  case 0x19:

    reaper_mana_decrement(param_1);

    reaper_ability_playersound(iVar1,iVar2 + 0xf4c);

    *(undefined4 *)(iVar2 + 0xda8) = *(undefined4 *)(DAT_00632ed8 + 0x14fc);

    return;

  case 0x1b:

    iVar1 = *(int *)(iVar2 + 0xdb0) * 3 + 0x351;

    *(float *)(iVar2 + iVar1 * 4) =

         *(float *)(iVar2 + iVar1 * 4) - *(float *)(iVar2 + 0xd40 + *(int *)(iVar2 + 0xdb0) * 0xc);

    reaper_update_spell_status__FP6OBJECT(param_1,iVar2 + 0xf4c);

    *(undefined4 *)(iVar2 + 0xda8) = *(undefined4 *)(DAT_00632ed8 + 0x14f4);

    return;

  case 0x1c:

    reaper_mana_decrement(param_1);

    reaper_ability_playersound3(iVar1,iVar2 + 0xf4c);

    *(undefined4 *)(iVar2 + 0xda8) = *(undefined4 *)(DAT_00632ed8 + 0x1504);

    return;

  case 0x1d:

    iVar5 = *(int *)(iVar2 + 0xdb0) * 3 + 0x351;

    *(float *)(iVar2 + iVar5 * 4) =

         *(float *)(iVar2 + iVar5 * 4) - *(float *)(iVar2 + 0xd40 + *(int *)(iVar2 + 0xdb0) * 0xc);

    iVar5 = *(int *)(param_1 + 0x100);

    iVar4 = reaper_can_do_spell_anim__FP6OBJECT(param_1);

    if (iVar4 == 0) {

      *(uint *)(iVar1 + 0xe0) = *(uint *)(iVar1 + 0xe0) & 0xffefffff;

      iVar4 = fx_create();

      if (iVar4 != 0) {

        reaper_fire_spell__FP6OBJECTiP3P3DT0i(iVar1,0x24,(undefined4 *)(iVar2 + 0xf4c),0,0xffffffff)

        ;

      }

    }

    else {

      sound_play_player(0x3a4,iVar1);

      *(uint *)(iVar1 + 0xe0) = *(uint *)(iVar1 + 0xe0) | 0x100000;

    }

    iVar4 = fx_create(iVar1);

    if (iVar4 != 0) {

      *(undefined4 *)(iVar5 + 0xe98) = *(undefined4 *)(iVar2 + 0xf4c);

      *(undefined4 *)(iVar5 + 0xe9c) = *(undefined4 *)(iVar2 + 0xf50);

      *(undefined4 *)(iVar5 + 0xea0) = *(undefined4 *)(iVar2 + 0xf54);

      iVar5 = reaper_0052e4a0(iVar1);

      if (iVar5 != 0) {

        reaper_00530bd0(iVar1,0,0,0,0x11,0);

      }

    }

    *(undefined4 *)(iVar2 + 0xda8) = *(undefined4 *)(DAT_00632ed8 + 0x14f0);

    return;

  case 0x1e:

    iVar5 = *(int *)(iVar2 + 0xf48);

    *(int *)(iVar2 + 0xf28) = iVar5;

    iVar4 = reaper_can_do_spell_anim__FP6OBJECT(param_1);

    if (iVar4 == 0) {

      iVar4 = fx_create();

      if (iVar4 != 0) {

        iVar4 = dialog_level_is_base_dup0052aa70();

        if (iVar4 != 0) {

          param_1 = *(int *)(iVar5 + 0x188);

          reaper_00530bd0(iVar1,0,1,0,0x18,&param_1);

        }

        reaper_finish_slow_follow__FP6OBJECTPUi(iVar1,0);

      }

    }

    else {

      *(uint *)(iVar1 + 0xe0) = *(uint *)(iVar1 + 0xe0) | 0x20000;

      iVar4 = reaper_0052e4a0(iVar1);

      if (iVar4 != 0) {

        param_1 = *(undefined4 *)(iVar5 + 0x188);

        reaper_00530bd0(iVar1,0,1,0,0x18,&param_1);

      }

    }

    iVar5 = *(int *)(iVar1 + 0x100);

    iVar1 = *(int *)(iVar5 + 0xdb0) * 3 + 0x351;

    *(float *)(iVar5 + iVar1 * 4) =

         *(float *)(iVar5 + iVar1 * 4) - *(float *)(iVar5 + 0xd40 + *(int *)(iVar5 + 0xdb0) * 0xc);

    *(undefined4 *)(iVar2 + 0xda8) = *(undefined4 *)(DAT_00632ed8 + 0x14e4);

    return;

  case 0x1f:

    local_34 = -*(float *)(param_1 + 0x29c);

    local_30 = -*(float *)(param_1 + 0x2ac);

    local_2c = -*(float *)(param_1 + 700);

    normalize__FPfN20(&local_34,&local_30,&local_2c);

    local_34 = *(float *)(DAT_00632ed8 + 0x834) * local_34 + *(float *)(iVar1 + 0xa0);

    local_30 = *(float *)(DAT_00632ed8 + 0x834) * local_30 + *(float *)(iVar1 + 0xa4);

    local_2c = *(float *)(DAT_00632ed8 + 0x834) * local_2c + *(float *)(iVar1 + 0xa8);

    ground_height_at(&local_34,local_1c);

    iVar5 = *(int *)(iVar1 + 0x100);

    local_2c = local_c;

    *(float *)(iVar5 + 0xf2c) = local_34;

    *(float *)(iVar5 + 0xf30) = local_30;

    *(float *)(iVar5 + 0xf34) = local_c;

    if (((*(uint *)(iVar1 + 0xd8) & 0x80000) == 0) || ((**(byte **)(iVar1 + 0x104) & 0x40) != 0)) {

      iVar4 = fx_create(iVar1);

      if (iVar4 != 0) {

        iVar4 = dialog_level_is_base_dup0052aa70();

        if (iVar4 != 0) {

          local_28 = local_34;

          local_24 = local_30;

          local_20 = local_2c;

          reaper_00530bd0(iVar1,3,0,0,0x19,&local_28);

        }

        *(uint *)(iVar1 + 0xe0) = *(uint *)(iVar1 + 0xe0) & 0xfffeffff;

        fxb_firecircle_create(iVar1,(float *)(iVar5 + 0xf2c),0xffffffff,0xffffffff);

      }

    }

    else {

      sound_play_player(0x39c,iVar1);

      *(uint *)(iVar1 + 0xe0) = *(uint *)(iVar1 + 0xe0) | 0x10000;

      iVar5 = reaper_0052e4a0(iVar1);

      if (iVar5 != 0) {

        local_28 = local_34;

        local_24 = local_30;

        local_20 = local_2c;

        reaper_00530bd0(iVar1,3,0,0,0x19,&local_28);

      }

    }

    iVar5 = *(int *)(iVar1 + 0x100);

    iVar1 = *(int *)(iVar5 + 0xdb0) * 3 + 0x351;

    *(float *)(iVar5 + iVar1 * 4) =

         *(float *)(iVar5 + iVar1 * 4) - *(float *)(iVar5 + 0xd40 + *(int *)(iVar5 + 0xdb0) * 0xc);

    *(undefined4 *)(iVar2 + 0xda8) = *(undefined4 *)(DAT_00632ed8 + 0x14e0);

    return;

  case 0x21:

    reaper_mana_decrement(param_1);

    reaper_tornado_create(iVar1,iVar2 + 0xf4c,0xffffffff,0xffffffff);

    *(undefined4 *)(iVar2 + 0xda8) = *(undefined4 *)(DAT_00632ed8 + 0x1500);

    return;

  case 0x3f:

    reaper_finish_cloak(param_1,iVar2 + 0xf4c);

    break;

  case 0x49:

    if (((*(uint *)(param_1 + 0xd8) & 0x80000) == 0) || ((**(byte **)(param_1 + 0x104) & 0x40) != 0)

       ) {

      iVar5 = fx_create(param_1);

      if (iVar5 != 0) {

        reaper_fire_spell__FP6OBJECTiP3P3DT0i(iVar1,0x33,(undefined4 *)(iVar2 + 0xf4c),0,0xffffffff)

        ;

      }

      *(uint *)(iVar1 + 0xe0) = *(uint *)(iVar1 + 0xe0) & 0xbfffffff;

    }

    else {

      sound_play_player(0x3af,param_1);

      *(uint *)(iVar1 + 0xe0) = *(uint *)(iVar1 + 0xe0) | 0x20000000;

      iVar5 = fx_create(iVar1);

      if (iVar5 != 0) {

        *(undefined4 *)(iVar2 + 0xe58) = *(undefined4 *)(iVar2 + 0xf4c);

        *(undefined4 *)(iVar2 + 0xe5c) = *(undefined4 *)(iVar2 + 0xf50);

        *(undefined4 *)(iVar2 + 0xe60) = *(undefined4 *)(iVar2 + 0xf54);

        iVar5 = reaper_0052e4a0(iVar1);

        if (iVar5 != 0) {

          reaper_00530bd0(iVar1,0,0,0,0x35,0);

        }

      }

    }

    iVar5 = *(int *)(iVar1 + 0x100);

    iVar1 = *(int *)(iVar5 + 0xdb0) * 3 + 0x351;

    *(float *)(iVar5 + iVar1 * 4) =

         *(float *)(iVar5 + iVar1 * 4) - *(float *)(iVar5 + 0xd40 + *(int *)(iVar5 + 0xdb0) * 0xc);

    *(undefined4 *)(iVar2 + 0xda8) = *(undefined4 *)(DAT_00632ed8 + 0x14dc);

    return;

  }

  return;

}

/* ===== reaper_can_do_spell_anim__FP6OBJECT @ 0x004C1DE0 ===== */
/* PS2 candidate: reaper_can_do_spell_anim__FP6OBJECT (conf 0.706) */



undefined4 reaper_can_do_spell_anim__FP6OBJECT(int param_1)



{

  if (((*(uint *)(param_1 + 0xd8) & 0x80000) != 0) && ((**(byte **)(param_1 + 0x104) & 0x40) == 0))

  {

    return 1;

  }

  return 0;

}

/* ===== reaper_ability_playersound @ 0x004C1E10 ===== */
void reaper_ability_playersound(int param_1,undefined4 *param_2)



{

  int iVar1;

  int iVar2;

  

  iVar2 = *(int *)(param_1 + 0x100);

  iVar1 = fx_create(param_1);

  if (iVar1 != 0) {

    *(undefined4 *)(iVar2 + 0xe64) = *param_2;

    *(undefined4 *)(iVar2 + 0xe68) = param_2[1];

    *(undefined4 *)(iVar2 + 0xe6c) = param_2[2];

    iVar2 = reaper_0052e4a0(param_1);

    if (iVar2 != 0) {

      reaper_00530bd0(param_1,0,0,0,0x15,0);

    }

  }

  if (((*(uint *)(param_1 + 0xd8) & 0x80000) == 0) || ((**(byte **)(param_1 + 0x104) & 0x40) != 0))

  {

    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xfeffffff;

    iVar2 = fx_create(param_1);

    if (iVar2 != 0) {

      reaper_fire_spell__FP6OBJECTiP3P3DT0i(param_1,0x27,param_2,0,0xffffffff);

      return;

    }

  }

  else {

    sound_play_player(0x3a4,param_1);

    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 0x1000000;

  }

  return;

}

/* ===== reaper_finish_smartie_grab__FP6OBJECT @ 0x004C1EE0 ===== */
/* PS2 candidate: reaper_finish_smartie_grab__FP6OBJECT (conf 0.542) */



void reaper_finish_smartie_grab__FP6OBJECT(int param_1)



{

  int iVar1;

  int iVar2;

  

  iVar1 = *(int *)(param_1 + 0x100);

  *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xfff7ffff;

  iVar2 = *(int *)(iVar1 + 0xea4);

  if (iVar2 == 0) goto LAB_004c1f71;

  if (*(int *)(iVar2 + 0x274) == 0) {

    ObjIsKabuto(*(undefined4 *)(iVar2 + 0x210));

  }

  else {

    iVar2 = ObjIsMecc(*(int *)(iVar2 + 0x274));

    if (iVar2 == 0) {

      iVar2 = ObjIsReaper(*(undefined4 *)(*(int *)(iVar1 + 0xea4) + 0x274));

      if (iVar2 == 0) goto LAB_004c1f61;

    }

    smartie_unlock_from_player

              (*(int *)(iVar1 + 0xea4),*(undefined4 *)(*(int *)(iVar1 + 0xea4) + 0x274),4);

  }

LAB_004c1f61:

  fx_reaper_bubble_create(*(undefined4 *)(iVar1 + 0xea4),param_1);

LAB_004c1f71:

  *(undefined4 *)(iVar1 + 0xea4) = 0;

  return;

}

/* ===== reaper_update_spell_status__FP6OBJECT @ 0x004C1F80 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* PS2 candidate: reaper_update_spell_status__FP6OBJECT (conf 0.458) */



void reaper_update_spell_status__FP6OBJECT(int param_1,undefined4 *param_2)



{

  int iVar1;

  char *pcVar2;

  undefined4 uVar3;

  undefined1 *puVar4;

  undefined1 local_34 [4];

  undefined4 local_30;

  undefined4 local_2c;

  undefined4 local_28;

  

  iVar1 = *(int *)(param_1 + 0x100);

  *(undefined4 *)(iVar1 + 0xea8) = 0;

  *(undefined4 *)(iVar1 + 0xf10) = *param_2;

  *(undefined4 *)(iVar1 + 0xf14) = param_2[1];

  *(undefined4 *)(iVar1 + 0xf18) = param_2[2];

  if (((*(uint *)(param_1 + 0xd8) & 0x80000) == 0) || ((**(byte **)(param_1 + 0x104) & 0x40) != 0))

  {

    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xfffbffff;

    iVar1 = fx_create(param_1);

    if (iVar1 != 0) {

      _DAT_00632bc8 = 0;

      DAT_00632bc4 = 1;

      sound_play(0x3b9);

    }

  }

  else {

    sound_play_player(0x39c,param_1);

    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 0x40000;

  }

  local_30 = *param_2;

  local_2c = param_2[1];

  local_28 = param_2[2];

  puVar4 = local_34;

  uVar3 = 8;

  pcVar2 = s_fx_hailstorm_short_00561074;

  fx_get_free_effect__Fv();

  iVar1 = reaper_0052e4a0(param_1,pcVar2,uVar3,puVar4);

  if (iVar1 != 0) {

    reaper_00530bd0(param_1,0,0,0,0x1a,0);

  }

  return;

}

/* ===== reaper_ability_playersound2 @ 0x004C2080 ===== */
void reaper_ability_playersound2(int param_1,undefined4 *param_2)



{

  int iVar1;

  int iVar2;

  

  iVar1 = *(int *)(param_1 + 0x100);

  if (((*(uint *)(param_1 + 0xd8) & 0x80000) != 0) && ((**(byte **)(param_1 + 0x104) & 0x40) == 0))

  {

    sound_play_player(0x3a4,param_1);

    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 0x40000000;

    iVar2 = fx_create(param_1);

    if (iVar2 != 0) {

      *(undefined4 *)(iVar1 + 0xe40) = *param_2;

      *(undefined4 *)(iVar1 + 0xe44) = param_2[1];

      *(undefined4 *)(iVar1 + 0xe48) = param_2[2];

      iVar1 = reaper_0052e4a0(param_1);

      if (iVar1 != 0) {

        reaper_00530bd0(param_1,0,0,0,0x10,0);

      }

    }

    return;

  }

  iVar1 = fx_create(param_1);

  if (iVar1 != 0) {

    reaper_fire_spell__FP6OBJECTiP3P3DT0i(param_1,0x26,param_2,0,0xffffffff);

  }

  *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xbfffffff;

  return;

}

/* ===== reaper_finish_teleport @ 0x004C2140 ===== */
/* PS2 candidate: reaper_finish_teleport (conf 0.432) */



void reaper_finish_teleport(int param_1,undefined4 *param_2)



{

  undefined4 *puVar1;

  int iVar2;

  int iVar3;

  undefined4 local_c;

  undefined4 local_8;

  undefined4 local_4;

  

  iVar2 = *(int *)(param_1 + 0x100);

  puVar1 = (undefined4 *)(iVar2 + 0x30);

  *puVar1 = *param_2;

  *(undefined4 *)(iVar2 + 0x34) = param_2[1];

  *(undefined4 *)(iVar2 + 0x38) = param_2[2];

  if (((*(uint *)(param_1 + 0xd8) & 0x80000) != 0) && ((**(byte **)(param_1 + 0x104) & 0x40) == 0))

  {

    sound_play_player(0x39d,param_1);

    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 0x800000;

    iVar3 = reaper_0052e4a0(param_1);

    if (iVar3 != 0) {

      local_c = *puVar1;

      local_8 = *(undefined4 *)(iVar2 + 0x34);

      local_4 = *(undefined4 *)(iVar2 + 0x38);

      reaper_00530bd0(param_1,3,0,0,0x13,&local_c);

    }

    return;

  }

  iVar3 = reaper_0052e4a0(param_1);

  if (iVar3 != 0) {

    local_c = *puVar1;

    local_8 = *(undefined4 *)(iVar2 + 0x34);

    local_4 = *(undefined4 *)(iVar2 + 0x38);

    reaper_00530bd0(param_1,3,0,0,0x13,&local_c);

  }

  *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xff7fffff;

  reaper_create_fake_reaper__FP6OBJECTP3P3Dfi(param_1,puVar1);

  *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 8;

  return;

}

/* ===== reaper_ability_playersound3 @ 0x004C2250 ===== */
void reaper_ability_playersound3(int param_1,undefined4 *param_2)



{

  int iVar1;

  int iVar2;

  

  iVar2 = *(int *)(param_1 + 0x100);

  iVar1 = fx_create(param_1);

  if (iVar1 != 0) {

    *(undefined4 *)(iVar2 + 0xe8c) = *param_2;

    *(undefined4 *)(iVar2 + 0xe90) = param_2[1];

    *(undefined4 *)(iVar2 + 0xe94) = param_2[2];

    iVar2 = reaper_0052e4a0(param_1);

    if (iVar2 != 0) {

      reaper_00530bd0(param_1,0,0,0,0xf,0);

    }

  }

  if (((*(uint *)(param_1 + 0xd8) & 0x80000) == 0) || ((**(byte **)(param_1 + 0x104) & 0x40) != 0))

  {

    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xffdfffff;

    iVar2 = fx_create(param_1);

    if (iVar2 != 0) {

      reaper_fire_spell__FP6OBJECTiP3P3DT0i(param_1,0x25,param_2,0,0xffffffff);

      return;

    }

  }

  else {

    sound_play_player(0x3a4,param_1);

    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 0x200000;

  }

  return;

}

/* ===== reaper_mana_decrement @ 0x004C2320 ===== */
void reaper_mana_decrement(int param_1)



{

  int iVar1;

  int iVar2;

  

  iVar2 = *(int *)(param_1 + 0x100);

  iVar1 = *(int *)(iVar2 + 0xdb0) * 3 + 0x351;

  *(float *)(iVar2 + iVar1 * 4) =

       *(float *)(iVar2 + iVar1 * 4) - *(float *)(iVar2 + 0xd40 + *(int *)(iVar2 + 0xdb0) * 0xc);

  return;

}

/* ===== reaper_mecc_combat_c3 @ 0x004C2430 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void reaper_mecc_combat_c3

               (int param_1,float param_2,int param_3,int param_4,undefined4 param_5,

               undefined4 param_6)



{

  uint *puVar1;

  bool bVar2;

  bool bVar3;

  int iVar4;

  int iVar5;

  undefined4 uVar6;

  

  bVar3 = true;

  if (DAT_00632e74 != 0) {

    return;

  }

  iVar4 = ObjIsJetski(*(undefined4 *)(param_3 + 0x210));

  if (iVar4 != 0) {

    iVar4 = fx_create(param_3);

    if (iVar4 != 0) {

      obj_damage_apply(param_1,param_2,*(undefined4 *)(param_3 + 0x210),param_4,param_5,param_6);

    }

    if (param_1 != 0x13) {

      return;

    }

  }

  if (0.0 <= param_2) {

    iVar4 = param_4;

    if (param_4 == 0) {

LAB_004c24e1:

      bVar2 = false;

    }

    else {

      if (*(int *)(param_4 + 0x274) != 0) {

        iVar4 = *(int *)(param_4 + 0x274);

      }

      if ((iVar4 == 0) || (*(int *)(iVar4 + 0x18c) != *(int *)(param_3 + 0x18c))) goto LAB_004c24e1;

      bVar2 = true;

    }

    iVar5 = dialog_level_is_base_dup0052aa70();

    if ((iVar5 != 0) && (DAT_00632f20 != 0)) {

      bVar2 = false;

    }

    if (((iVar4 != 0) && (bVar2)) &&

       ((iVar5 = ObjIsReaper(iVar4), iVar5 != 0 || (iVar4 = ObjIsTurret(iVar4), iVar4 != 0)))) {

      bVar3 = false;

    }

  }

  if (*(float *)(param_3 + 0x1c0) <= *(float *)(param_3 + 0x278)) {

    return;

  }

  puVar1 = *(uint **)(param_3 + 0x100);

  if (puVar1[0x38b] != 0) {

    if (param_1 != 0x13) goto LAB_004c25c6;

    sound_interrupt_sequence(puVar1 + 0x3fc);

    fx_delete(puVar1[0x38d]);

    puVar1[0x38d] = 0;

    puVar1[0x38b] = 0;

    *(uint *)(param_3 + 0xd8) = *(uint *)(param_3 + 0xd8) & 0xbfffffff;

    if ((*puVar1 & 2) == 0) {

      iVar4 = gun_find_right(param_3);

      *(uint *)(iVar4 + 0xd8) = *(uint *)(iVar4 + 0xd8) & 0xbfffffff;

    }

  }

  if ((bVar3) && (iVar4 = cutscene_active_check(), iVar4 == 0)) {

    *(float *)(param_3 + 0x278) = param_2 + *(float *)(param_3 + 0x278);

  }

LAB_004c25c6:

  if (*(float *)(param_3 + 0x1c0) <= *(float *)(param_3 + 0x278)) {

    mecc_shot(param_1,param_2,param_3,param_4,param_5,param_6);

  }

  if (param_1 == 0x17) {

    *puVar1 = *puVar1 | 0x100;

  }

  if (((((param_4 == 0) || (*(int *)(param_4 + 4) != 0x26)) || (*(int *)(param_4 + 0x274) == 0)) ||

      (*(int *)(*(int *)(param_4 + 0x274) + 0x1e0) != 0x33)) &&

     (((0.0 <= param_2 && (param_1 != 0x12)) && ((param_1 != 0x1a && (param_1 != 0x13)))))) {

    hurt_pusher(param_1,param_2,param_2,param_3,param_4,param_5);

  }

  if ((0.0 < param_2) && (_DAT_00560f40 < 0.0)) {

    iVar4 = crt_rand_scaled(100);

    if (iVar4 < 0x19) {

      uVar6 = 0x69c;

    }

    else if (iVar4 < 0x32) {

      uVar6 = 0x69d;

    }

    else if (iVar4 < 0x4b) {

      uVar6 = 0x69e;

    }

    else {

      uVar6 = 0x69f;

    }

    sound_play_player(uVar6,param_3);

    _DAT_00560f40 = 10.0;

  }

  return;

}

/* ===== reaper_init_trails @ 0x004C26D0 ===== */
/* PS2 candidate: reaper_init_trails (conf 0.432) */



void reaper_init_trails(int param_1,undefined4 *param_2)



{

  int iVar1;

  int iVar2;

  

  *param_2 = 0xffffffff;

  param_2 = (undefined4 *)0x0;

  if (0 < *(int *)(DAT_00632ed8 + 0x4fc)) {

    do {

      iVar1 = ObjIsReaper(param_1);

      if (iVar1 == 0) {

        iVar1 = *(int *)(param_1 + 4);

        if (iVar1 == 0x438) {

          iVar1 = object_allocate_type(0x4d7,4);

        }

        else if (iVar1 == 0x29a) {

          iVar1 = object_allocate_type(0x4d8,4);

        }

        else {

          iVar1 = object_allocate_type(iVar1,4);

          object_change_ospec(iVar1,0x3e);

        }

      }

      else {

        iVar1 = object_allocate_type(0x137,4);

      }

      object_set_location_p3d(iVar1,param_1 + 0xa0);

      *(undefined4 *)(iVar1 + 0x18c) = *(undefined4 *)(param_1 + 0x18c);

      *(int *)(iVar1 + 0x274) = param_1;

      *(undefined4 *)(iVar1 + 0xc4) = *(undefined4 *)(param_1 + 0xc4);

      *(undefined4 **)(iVar1 + 0x174) = param_2;

      *(float *)(iVar1 + 0x184) =

           (*(float *)(DAT_00632ed8 + 0x508) - *(float *)(DAT_00632ed8 + 0x504)) *

           ((float)(int)param_2 / (float)(*(int *)(DAT_00632ed8 + 0x4fc) + -1)) +

           *(float *)(DAT_00632ed8 + 0x504);

      *(uint *)(iVar1 + 0xd8) = *(uint *)(iVar1 + 0xd8) | 0x40400010;

      *(uint *)(iVar1 + 0x1c8) = *(uint *)(iVar1 + 0x1c8) | 0xe00;

      object_create_child(iVar1,1,0x29d);

      iVar2 = gun_find_right(iVar1);

      *(undefined4 *)(iVar2 + 0x184) = *(undefined4 *)(iVar1 + 0x184);

      *(uint *)(iVar2 + 0xd8) = *(uint *)(iVar2 + 0xd8) | 0x40000010;

      *(uint *)(iVar2 + 0x1c8) = *(uint *)(iVar2 + 0x1c8) | 0xe00;

      param_2 = (undefined4 *)((int)param_2 + 1);

    } while ((int)param_2 < *(int *)(DAT_00632ed8 + 0x4fc));

  }

  return;

}

/* ===== obj_yaw_turn @ 0x004C2850 ===== */
void obj_yaw_turn(int param_1,int *param_2,int param_3,undefined4 param_4)



{

  undefined4 *puVar1;

  float *pfVar2;

  float fVar3;

  int iVar4;

  int iVar5;

  float10 fVar6;

  

  if ((DAT_00632a88 == param_1) && (DAT_00632bb4 != 0)) {

    return;

  }

  if (*(float *)(param_1 + 200) < 360.0) {

    if (*(float *)(param_1 + 200) < 0.0) {

      fVar3 = *(float *)(param_1 + 200) + 360.0;

      goto LAB_004c28a8;

    }

  }

  else {

    fVar3 = *(float *)(param_1 + 200) - 360.0;

LAB_004c28a8:

    *(float *)(param_1 + 200) = fVar3;

  }

  if (*param_2 == -1) {

    *param_2 = 0;

    do {

      puVar1 = (undefined4 *)(param_3 + *param_2 * 0x28);

      *puVar1 = *(undefined4 *)(param_1 + 0xa0);

      puVar1[1] = *(undefined4 *)(param_1 + 0xa4);

      puVar1[2] = *(undefined4 *)(param_1 + 0xa8);

      puVar1[3] = *(undefined4 *)(param_1 + 200);

      puVar1[4] = *(undefined4 *)(param_1 + 0x10);

      puVar1[5] = *(undefined4 *)(param_1 + 0x14);

      puVar1[6] = *(undefined4 *)(param_1 + 0x2c);

      puVar1[7] = *(undefined4 *)(param_1 + 0x58);

      puVar1[8] = *(undefined4 *)(param_1 + 0x5c);

      *(float *)(param_3 + 0x24 + *param_2 * 0x28) = (float)*param_2 * 0.025;

      iVar4 = *param_2;

      *param_2 = iVar4 + 1;

    } while (iVar4 + 1 < 0x50);

    *param_2 = 0x4f;

  }

  else if (*param_2 == 0) {

    iVar4 = param_3 + 0xc58;

    iVar5 = 0;

    goto LAB_004c2940;

  }

  iVar5 = *param_2;

  iVar4 = param_3 + -0x28 + iVar5 * 0x28;

LAB_004c2940:

  puVar1 = (undefined4 *)(param_3 + iVar5 * 0x28);

  if (*(float *)(param_3 + 0x24 + iVar5 * 0x28) - *(float *)(iVar4 + 0x24) < 0.025) {

    *puVar1 = *(undefined4 *)(param_1 + 0xa0);

    puVar1[1] = *(undefined4 *)(param_1 + 0xa4);

    puVar1[2] = *(undefined4 *)(param_1 + 0xa8);

    puVar1[3] = *(undefined4 *)(param_1 + 200);

    puVar1[4] = *(undefined4 *)(param_1 + 0x10);

    puVar1[5] = *(undefined4 *)(param_1 + 0x14);

    puVar1[6] = *(undefined4 *)(param_1 + 0x2c);

    puVar1[7] = *(undefined4 *)(param_1 + 0x58);

    puVar1[8] = *(undefined4 *)(param_1 + 0x5c);

    pfVar2 = (float *)(param_3 + 0x24 + *param_2 * 0x28);

    fVar6 = (float10)FRateGetSecsframe(param_1,0);

    *pfVar2 = (float)(fVar6 + (float10)*pfVar2);

    puVar1 = DAT_00632d74;

  }

  else {

    fVar3 = (float)puVar1[9];

    *param_2 = iVar5 + 1;

    if (0x4f < iVar5 + 1) {

      *param_2 = 0;

    }

    puVar1 = (undefined4 *)(param_3 + *param_2 * 0x28);

    *puVar1 = *(undefined4 *)(param_1 + 0xa0);

    puVar1[1] = *(undefined4 *)(param_1 + 0xa4);

    puVar1[2] = *(undefined4 *)(param_1 + 0xa8);

    puVar1[3] = *(undefined4 *)(param_1 + 200);

    puVar1[4] = *(undefined4 *)(param_1 + 0x10);

    puVar1[5] = *(undefined4 *)(param_1 + 0x14);

    puVar1[6] = *(undefined4 *)(param_1 + 0x2c);

    puVar1[7] = *(undefined4 *)(param_1 + 0x58);

    puVar1[8] = *(undefined4 *)(param_1 + 0x5c);

    fVar6 = (float10)FRateGetSecsframe(param_1,0);

    *(float *)(param_3 + 0x24 + *param_2 * 0x28) = (float)(fVar6 + (float10)fVar3);

    puVar1 = DAT_00632d74;

  }

  for (; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {

    iVar4 = puVar1[3];

    if ((*(int *)(iVar4 + 0x1e0) == 0x3e) && (*(int *)(iVar4 + 0x274) == param_1)) {

      reaper_set_trail__FP6OBJECTT0fiiP8TimeSnap

                (param_1,iVar4,

                 (float)(*(int *)(iVar4 + 0x174) + 1) * *(float *)(DAT_00632ed8 + 0x500),param_4,

                 *param_2,param_3);

    }

  }

  return;

}

/* ===== reaper_set_trail__FP6OBJECTT0fiiP8TimeSnap @ 0x004C2AB0 ===== */
/* PS2 candidate: reaper_set_trail__FP6OBJECTT0fiiP8TimeSnap (conf 0.443) */



void reaper_set_trail__FP6OBJECTT0fiiP8TimeSnap

               (undefined4 param_1,OBJECT *param_2,float param_3,int param_4,int param_5,

               float *param_6)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  int iVar5;

  int iVar6;

  float *pfVar7;

  float *pfVar8;

  dword *pdVar9;

  dword *pdVar10;

  

  iVar5 = gun_find_right(param_2);

  if ((param_4 != 0) && (iVar6 = object_volume_sfx(param_1), iVar6 == 0)) {

    pfVar8 = param_6 + param_5 * 10;

    while( true ) {

      pfVar7 = pfVar8;

      pfVar8 = param_6 + 0x316;

      if (pfVar7 != param_6) {

        pfVar8 = pfVar7 + -10;

      }

      if (pfVar8 == param_6 + param_5 * 10) break;

      if (pfVar8[9] <= param_6[param_5 * 10 + 9] - param_3) {

        fVar3 = ((param_6[param_5 * 10 + 9] - param_3) - pfVar8[9]) / (pfVar7[9] - pfVar8[9]);

        fVar4 = 1.0 - fVar3;

        *(float *)&param_2->field_0xa0 = fVar3 * *pfVar7 + fVar4 * *pfVar8;

        *(float *)&param_2->field_0xa4 = fVar3 * pfVar7[1] + fVar4 * pfVar8[1];

        *(float *)&param_2->field_0xa8 = fVar3 * pfVar7[2] + fVar4 * pfVar8[2];

        if (ABS(pfVar8[3] - pfVar7[3]) <= 180.0) {

          *(float *)&param_2->field_0xc8 = fVar4 * pfVar8[3] + fVar3 * pfVar7[3];

        }

        else {

          fVar1 = pfVar8[3];

          if (pfVar8[3] < 180.0) {

            fVar1 = fVar1 + 360.0;

          }

          fVar2 = pfVar7[3];

          if (pfVar7[3] < 180.0) {

            fVar2 = fVar2 + 360.0;

          }

          fVar1 = fVar2 * fVar3 + fVar4 * fVar1;

          *(float *)&param_2->field_0xc8 = fVar1;

          if (360.0 <= fVar1) {

            *(float *)&param_2->field_0xc8 = fVar1 - 360.0;

          }

        }

        if (pfVar7[4] != 3.5593e-43) {

          ObjectSetAnim(param_2);

          if (pfVar8[4] == pfVar7[4]) {

            param_2->pad_14 = (dword)(fVar3 * pfVar7[5] + fVar4 * pfVar8[5]);

            fVar3 = fVar3 * pfVar7[6] + fVar4 * pfVar8[6];

            *(float *)&param_2->field_0x2c = fVar3;

            if (0.0 < fVar3) {

              pdVar9 = &param_2->anim;

              pdVar10 = (dword *)&param_2->field_0x58;

              for (iVar5 = 9; iVar5 != 0; iVar5 = iVar5 + -1) {

                *pdVar10 = *pdVar9;

                pdVar9 = pdVar9 + 1;

                pdVar10 = pdVar10 + 1;

              }

              *(float *)&param_2->field_0x58 = pfVar7[7];

              *(float *)&param_2->field_0x5c = pfVar7[8];

            }

          }

          else {

            param_2->pad_14 = (dword)(fVar3 * pfVar7[5]);

            if (pfVar7[6] <= 0.0) {

              *(undefined4 *)&param_2->field_0x2c = 0;

            }

            else {

              pdVar9 = &param_2->anim;

              pdVar10 = (dword *)&param_2->field_0x58;

              for (iVar5 = 9; iVar5 != 0; iVar5 = iVar5 + -1) {

                *pdVar10 = *pdVar9;

                pdVar9 = pdVar9 + 1;

                pdVar10 = pdVar10 + 1;

              }

              *(float *)&param_2->field_0x58 = pfVar7[7];

              *(float *)&param_2->field_0x5c = pfVar7[8];

              *(float *)&param_2->field_0x2c = fVar3 * pfVar7[6] + fVar4;

            }

          }

        }

        param_2->flags = param_2->flags & 0xbfffffff;

        return;

      }

    }

  }

  param_2->flags = param_2->flags | 0x40000000;

  if (iVar5 != 0) {

    *(uint *)(iVar5 + 0xd8) = *(uint *)(iVar5 + 0xd8) | 0x40000000;

  }

  return;

}

/* ===== reaper_ally_tick_c62 @ 0x004C2D00 ===== */
void reaper_ally_tick_c62(int param_1)



{

  if ((char)((uint)*(undefined4 *)(*(int *)(param_1 + 0x274) + 0xd8) >> 8) < '\0') {

    *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) | 0x8000;

    return;

  }

  return;

}

/* ===== reaper_spellcast_ai_main @ 0x004C2D20 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void reaper_spellcast_ai_main(OBJECT *param_1)



{

  float fVar1;

  uint *puVar2;

  uint uVar3;

  uint *puVar4;

  dword dVar5;

  int iVar6;

  uint uVar7;

  uint uVar8;

  char cVar9;

  uint uVar10;

  uint uVar11;

  uint uVar12;

  bool bVar13;

  float10 fVar14;

  float10 fVar15;

  undefined4 uVar16;

  uint uStack_58;

  char cStack_54;

  float fStack_40;

  float fStack_3c;

  float fStack_38;

  undefined4 uStack_30;

  undefined4 uStack_2c;

  undefined4 uStack_28;

  undefined4 uStack_24;

  undefined4 uStack_20;

  OBJECT *pOStack_1c;

  

  puVar2 = (uint *)param_1->animate_state;

  iVar6 = *(int *)&param_1->field_0x210;

  if (iVar6 != 0) {

    if (*(int *)(iVar6 + 0x1e0) == 1) {

      return;

    }

    if (*(int *)(iVar6 + 0x1e0) == 0x4c) {

      return;

    }

  }

  iVar6 = ObjIsJetski(iVar6);

  if (iVar6 != 0) {

    return;

  }

  uVar12 = puVar2[0x17];

  uVar10 = *(uint *)&param_1->field_0x30 & 2;

  uStack_58 = (uint)(0 < (int)puVar2[0x36d]);

  uVar8 = param_1->coll_radius;

  uVar7 = uVar8 & 0xfbffffff;

  param_1->coll_radius = uVar7;

  uVar11 = uVar12;

  if (*(float *)&param_1->field_0x278 < *(float *)&param_1->field_0x1c0) {

    cVar9 = (char)uVar7;

    if ((uVar8 & 0x20) == 0) {

      uVar3 = *puVar2;

      if ((uVar3 & 0x20) == 0) {

        if (((*(byte *)param_1->pad_104 & 0x40) != 0) && ((param_1->flags & 0x100) == 0)) {

          puVar4 = (uint *)param_1->animate_state;

          param_1->coll_radius = uVar8 & 0xfbfff7ff;

          uVar7 = puVar4[0x17];

          if (((int)uVar7 < 0x31) || ((0x37 < (int)uVar7 && (uVar7 != 0x4c)))) {

            if ((uVar8 & 0x2000000) == 0) {

              param_1->coll_radius = uVar8 & 0xfbfff77f;

              if (puVar4[0x38e] != 0) {

                fx_delete(puVar4[0x38e]);

                puVar4[0x38e] = 0;

              }

              param_1->coll_radius = param_1->coll_radius & 0xffffffbf;

              *puVar4 = *puVar4 & 0xfffffffe;

              iVar6 = gun_find_right(param_1);

              if (iVar6 != 0) {

                *puVar2 = *puVar2 | 2;

                *(uint *)(iVar6 + 0xd8) = *(uint *)(iVar6 + 0xd8) | 0x40000000;

              }

              param_1->coll_radius = param_1->coll_radius | 0x2000000;

            }

            uVar8 = param_1->coll_radius;

            if (((uVar8 & 0x4000) != 0) && (0.0 < (float)param_1->vel1)) {

              param_1->coll_radius = uVar8 & 0xffffbfff;

              uVar11 = 0x27;

              goto LAB_004c2e20;

            }

            if ((char)(uVar8 >> 8) < '\0') {

              if ((uVar12 != 0x27) || (uVar10 != 0)) {

                if ((float)param_1->vel1 <= 0.0) {

                  if (0.0 <= (float)param_1->vel1) {

                    if ((float)param_1->vel2 <= 0.0) {

                      if (0.0 <= (float)param_1->vel2) {

                        uVar8 = *(uint *)(DAT_00632ed8 + 0x828);

                        goto LAB_004c318b;

                      }

                      uVar11 = 0x2d;

                    }

                    else {

                      uVar11 = 0x2c;

                    }

                  }

                  else {

                    uVar11 = 0x2e;

                  }

                }

                else {

                  uVar11 = 0x28;

                }

              }

            }

            else {

              iVar6 = *(int *)(param_1->animate_state + 0x5c);

              if ((iVar6 < 0x31) || ((0x37 < iVar6 && (iVar6 != 0x4c)))) goto LAB_004c3eb0;

            }

          }

          else if (puVar2[0x3c9] == 0) {

            if (uVar10 != 0) {

LAB_004c3eb0:

              if ((float)param_1->vel1 <= 0.0) {

                if (0.0 <= (float)param_1->vel1) {

                  if ((float)param_1->vel2 <= 0.0) {

                    uVar11 = 0x2a;

                    if (0.0 <= (float)param_1->vel2) {

                      uVar11 = 0x26;

                    }

                  }

                  else {

                    uVar11 = 0x29;

                  }

                }

                else {

                  uVar11 = 0x2b;

                }

              }

              else {

                uVar11 = 0x25;

              }

            }

          }

          else if ((float)param_1->vel1 <= 0.0) {

            if (0.0 <= (float)param_1->vel1) {

              if ((float)param_1->vel2 <= 0.0) {

                if (0.0 <= (float)param_1->vel2) {

                  uVar8 = *(uint *)(DAT_00632ed8 + 0x828);

LAB_004c318b:

                  puVar2[0x3c7] = uVar8;

                  param_1->coll_radius = param_1->coll_radius & 0xffff3fff;

                  sound_stop_player(0x34c,param_1);

                  puVar2[0x3c9] = 0;

                  uVar11 = 0x26;

                }

                else {

                  uVar11 = 0x2d;

                }

              }

              else {

                uVar11 = 0x2c;

              }

            }

            else {

              uVar11 = 0x2e;

            }

          }

          else {

            uVar11 = 0x28;

          }

          goto LAB_004c4317;

        }

        if ((uVar8 & 0x10000000) == 0) {

          if ((uVar8 & 0x100) == 0) {

            if ((uVar3 & 4) == 0) {

              if ((uVar8 & 0x10000) == 0) {

                if ((uVar8 & 0x20000) == 0) {

                  if ((uVar8 & 0x40000) == 0) {

                    if ((uVar8 & 0x40000000) == 0) {

                      if ((uVar8 & 0x20000000) == 0) {

                        if ((uVar3 & 0x40) == 0) {

                          if ((int)uVar7 < 0) {

                            uVar11 = 0x53;

                            if ((uVar12 == 0x53) && (uVar10 != 0)) {

                              fxb_cloak_create(param_1);

                            }

                          }

                          else if ((uVar8 & 0x800000) == 0) {

                            if ((uVar8 & 0x1000000) == 0) {

                              if ((uVar8 & 0x200000) == 0) {

                                if ((uVar8 & 0x100000) == 0) {

                                  if ((uVar8 & 0x80000) == 0) {

                                    cStack_54 = (char)uVar3;

                                    if (uVar12 == 9) {

                                      if ((puVar2[0x3d7] != 0) || (-1 < cStack_54))

                                      goto LAB_004c3980;

                                      if (uVar10 == 0) goto LAB_004c4317;

                                      uVar16 = IconDefWieldType(puVar2[puVar2[0x36d] * 2 + 0x35c],1)

                                      ;

                                      object_create_child(param_1,1,uVar16);

                                      *puVar2 = *puVar2 & 0xffffff7f;

                                      uStack_58 = 1;

                                    }

                                    else if (uVar12 == 0x38) {

                                      if ((puVar2[0x3d7] == 0) && ((uVar8 & 0x8000000) != 0)) {

                                        if (0.33333334 < (float)param_1->pad_14) {

                                          iVar6 = camera_is_sniper();

                                          if (iVar6 == 0) {

                                            uVar16 = gun_find_right(param_1);

                                            playerobj_eval_refpt(uVar16,0,&uStack_30);

                                            fx_get_free_effect__Fv();

                                          }

                                          uVar16 = IconDefWieldType(puVar2[puVar2[0x36d] * 2 + 0x35c

                                                                          ],1);

                                          object_create_child(param_1,1,uVar16);

                                        }

                                        if (uVar10 == 0) goto LAB_004c4317;

                                        param_1->coll_radius = param_1->coll_radius & 0xf7ffffff;

                                        uStack_58 = 1;

                                      }

                                      else {

LAB_004c3980:

                                        if ((uVar8 & 0x200) == 0) {

                                          if ((uVar12 == 0x11) || (uVar12 == 0x13)) {

                                            bVar13 = uVar10 == 0;

                                            goto LAB_004c4315;

                                          }

                                          if ((uVar8 & 0x40) == 0) {

                                            uVar3 = param_1->flags;

                                            if ((uVar3 & 0x100) == 0) {

                                              if (0.0 <= (float)param_1->loc_accum0) {

                                                if ((uVar3 & 0x80000) != 0) {

                                                  if ((((uVar12 == 0x20) || (uVar12 == 0x1e)) ||

                                                      (uVar12 == 0x21)) || (uVar12 == 0x22)) {

LAB_004c430f:

                                                    bVar13 = uVar10 == 0;

                                                    goto LAB_004c4315;

                                                  }

                                                  if ((float)param_1->vel1 == 0.0) {

                                                    if ((float)param_1->vel2 == 0.0) {

                                                      if ((float)param_1->vel_w == 0.0) {

                                                        if (cStack_54 < '\0') {

                                                          uVar11 = 9;

                                                        }

                                                        else if ((uVar8 & 0x8000000) == 0) {

                                                          if ((uVar8 & 0x10) == 0) {

                                                            if ((uVar12 == 1) || (uVar12 == 2))

                                                            goto LAB_004c430f;

                                                            if (((uVar12 != 0) || (uVar10 == 0)) ||

                                                               (iVar6 = crt_rand_scaled(100),

                                                               iVar6 < 0x60)) goto LAB_004c4320;

                                                            iVar6 = crt_rand_scaled(100);

                                                            uVar11 = (0x31 < iVar6) + 1;

                                                          }

                                                          else {

                                                            uVar11 = 10;

                                                          }

                                                        }

                                                        else {

                                                          uVar11 = 0x38;

                                                        }

                                                      }

                                                      else {

                                                        uVar11 = 8;

                                                      }

                                                      goto LAB_004c2e20;

                                                    }

                                                    if ((float)param_1->vel2 <= 0.0) {

                                                      uVar11 = 4;

                                                    }

                                                    else {

                                                      uVar11 = 3;

                                                    }

                                                  }

                                                  else {

                                                    if (uVar12 == 0x23) {

                                                      if (uVar10 == 0) goto LAB_004c4317;

                                                    }

                                                    else if ((uVar12 == 5) && (uVar10 != 0)) {

                                                      iVar6 = crt_rand_scaled(100);

                                                      uVar11 = 0x23;

                                                      if ((float)iVar6 < 10.0) goto LAB_004c4317;

                                                    }

                                                    uVar11 = 5;

                                                  }

                                                  goto LAB_004c4317;

                                                }

                                              }

                                              else if ((uVar8 & 0x800) == 0) {

                                                if (((float)param_1->loc_accum0 <

                                                     -*(float *)(DAT_00632ed8 + 0xc10)) &&

                                                   (*(float *)(DAT_00632ed8 + 0x117c) <

                                                    (*(float *)&param_1->field_0xa8 -

                                                    (float)param_1->pad_140) -

                                                    *(float *)&param_1->field_0x1d4 *

                                                    *(float *)&param_1->field_0xc4)) {

                                                  param_1->coll_radius = uVar7 | 0x4000000;

                                                  if (uVar12 == 0x1c) {

                                                    if (uVar10 != 0) {

                                                      uVar11 = 0x1d;

                                                      goto LAB_004c2e20;

                                                    }

                                                  }

                                                  else if (uVar12 == 0x1d) goto LAB_004c4317;

                                                  uVar11 = 0x1c;

                                                  goto LAB_004c2e20;

                                                }

                                              }

                                              else {

                                                if (uVar12 == 0x4c) goto LAB_004c40de;

                                                bVar13 = (uVar3 & 0x80000) == 0;

LAB_004c4315:

                                                if (bVar13) goto LAB_004c4317;

                                              }

                                              goto LAB_004c4320;

                                            }

                                            iVar6 = *(int *)(param_1->animate_state + 0x5c);

                                            if ((iVar6 < 0x31) ||

                                               ((0x37 < iVar6 && (iVar6 != 0x4c)))) {

                                              if (puVar2[0x3c8] == 0) {

                                                if (((uVar12 != 0x19) && (uVar12 != 0x15)) &&

                                                   (uVar11 = 0x19, (float)param_1->vel1 == 0.0)) {

                                                  uVar11 = 0x15;

                                                }

                                              }

                                              else {

                                                if (puVar2[0x3c9] == 0) {

                                                  if ((float)param_1->vel1 <= 0.0) {

                                                    if (0.0 <= (float)param_1->vel1) {

                                                      if ((float)param_1->vel2 <= 0.0) {

                                                        if (0.0 <= (float)param_1->vel2)

                                                        goto LAB_004c4037;

                                                        uVar11 = 0x34;

                                                      }

                                                      else {

                                                        uVar11 = 0x33;

                                                      }

                                                    }

                                                    else {

LAB_004c4037:

                                                      uVar11 = 0x15;

                                                    }

                                                  }

                                                  else {

                                                    uVar11 = 0x32;

                                                  }

                                                  goto LAB_004c2e20;

                                                }

                                                if ((float)param_1->vel1 <= 0.0) {

                                                  if (0.0 <= (float)param_1->vel1) {

                                                    if ((float)param_1->vel2 <= 0.0) {

                                                      if ((float)param_1->vel2 < 0.0) {

                                                        uVar11 = 0x37;

                                                      }

                                                    }

                                                    else {

                                                      uVar11 = 0x36;

                                                    }

                                                  }

                                                  else {

                                                    uVar11 = 0x35;

                                                  }

                                                }

                                                else {

                                                  if (uVar12 == 0x4c) goto LAB_004c40de;

                                                  if (uVar12 != 0x31) {

                                                    uVar11 = 0x4c;

                                                    goto LAB_004c2e20;

                                                  }

                                                }

                                              }

                                            }

                                            else if (puVar2[0x3c9] == 0) {

                                              if (uVar10 != 0) {

                                                param_1->flags = uVar3 & 0xfffffeff;

                                                goto LAB_004c3eb0;

                                              }

                                            }

                                            else if (uVar12 == 0x4c) {

LAB_004c40de:

                                              if (uVar10 != 0) {

                                                uVar11 = 0x31;

                                                goto LAB_004c2e20;

                                              }

                                            }

                                          }

                                          else {

                                            bVar13 = (float)param_1->vel1 == 0.0;

                                            if ((param_1->flags & 0x80000) == 0) {

                                              if (cVar9 < '\0') {

                                                if ((!bVar13) ||

                                                   (uVar11 = 0x3e, (float)param_1->vel2 != 0.0)) {

                                                  uVar11 = 0x40;

                                                }

                                              }

                                              else if ((!bVar13) ||

                                                      (uVar11 = 0x3f, (float)param_1->vel2 != 0.0))

                                              {

                                                uVar11 = 0x41;

                                              }

                                            }

                                            else {

                                              if (-1 < cVar9) goto joined_r0x004c3c32;

                                              if (bVar13) {

                                                if ((float)param_1->vel2 <= 0.0) {

                                                  if (0.0 <= (float)param_1->vel2) {

                                                    uVar11 = 0x3c;

                                                  }

                                                  else {

                                                    uVar11 = 0x46;

                                                  }

                                                }

                                                else {

                                                  uVar11 = 0x44;

                                                }

                                              }

                                              else {

                                                uVar11 = 0x3a;

                                              }

                                            }

                                          }

                                        }

                                        else if (puVar2[0x36d] == 0) {

                                          if ((param_1->flags & 0x80000) == 0) {

                                            if (((int)uVar12 < 0x14) || (0x1b < (int)uVar12)) {

                                              uVar11 = 0x1f;

                                              param_1->coll_radius = uVar8 & 0xfbfffbff;

                                            }

                                            else {

                                              param_1->coll_radius = uVar8 & 0xfbfffbff;

                                              if ((float)param_1->vel1 == 0.0) {

                                                uVar11 = 0x16;

                                              }

                                              else {

                                                uVar11 = 0x1a;

                                              }

                                            }

                                            if ((uVar11 == uVar12) && (uVar10 != 0)) {

                                              puVar2[1] = 0;

                                              param_1->coll_radius =

                                                   param_1->coll_radius & 0xfffffdff;

                                              if ((float)param_1->vel1 == 0.0) goto LAB_004c4037;

                                              uVar11 = 0x19;

                                              goto LAB_004c2e20;

                                            }

                                          }

                                          else {

                                            if (uVar12 != 0x12) {

                                              if (uVar12 == 0xc) {

                                                if ((uVar8 & 0x1000) == 0) {

                                                  if (uVar10 == 0) goto LAB_004c4317;

                                                  if ((int)puVar2[1] < 2) goto LAB_004c3bcf;

                                                  param_1->coll_radius = uVar8 & 0xfbfffbff;

                                                  uVar11 = 0xd;

                                                }

                                                else {

                                                  param_1->coll_radius = uVar8 & 0xfbffefff;

                                                  puVar2[1] = 0;

                                                  param_1->coll_radius =

                                                       param_1->coll_radius & 0xfffffdff;

                                                  uVar11 = 0x11;

                                                }

                                              }

                                              else if (uVar12 == 0xd) {

                                                if ((uVar8 & 0x1000) == 0) {

                                                  if (uVar10 != 0) {

                                                    if (2 < (int)puVar2[1]) {

                                                      param_1->coll_radius = uVar8 & 0xfbfffbff;

                                                      uVar11 = 0xe;

                                                      goto LAB_004c2e20;

                                                    }

LAB_004c3bcf:

                                                    puVar2[1] = 0;

LAB_004c3bd2:

                                                    param_1->coll_radius =

                                                         param_1->coll_radius & 0xfffffdff;

                                                  }

                                                  goto LAB_004c4317;

                                                }

                                                param_1->coll_radius = uVar8 & 0xfbffefff;

                                                puVar2[1] = 0;

                                                param_1->coll_radius =

                                                     param_1->coll_radius & 0xfffffdff;

                                                uVar11 = 0x11;

                                              }

                                              else {

                                                if (((uVar12 == 0xe) || (uVar12 == 0xf)) ||

                                                   (uVar12 == 0x10)) {

                                                  if ((uVar8 & 0x1000) != 0) {

                                                    uVar11 = 0x11;

                                                    goto LAB_004c3b40;

                                                  }

                                                  if (uVar10 != 0) goto LAB_004c3bcf;

                                                  goto LAB_004c4317;

                                                }

                                                if ((float)param_1->vel1 == 0.0) {

                                                  if (((uVar12 == 0x1f) || (uVar12 == 0x1a)) ||

                                                     (uVar12 == 0x16)) {

                                                    if (uVar10 != 0) {

                                                      puVar2[1] = 0;

                                                      goto LAB_004c3bd2;

                                                    }

                                                    goto LAB_004c4317;

                                                  }

                                                  param_1->coll_radius = uVar8 & 0xfbfffbff;

                                                  uVar11 = 0xc;

                                                }

                                                else {

                                                  param_1->coll_radius = uVar8 & 0xfbfffbff;

                                                  uVar11 = 0x12;

                                                }

                                              }

                                              goto LAB_004c2e20;

                                            }

                                            if ((uVar8 & 0x1000) != 0) {

                                              uVar11 = 0x13;

LAB_004c3b40:

                                              param_1->coll_radius = uVar8 & 0xfbffefff;

                                              puVar2[1] = 0;

                                              goto LAB_004c3b4f;

                                            }

                                            if (uVar10 != 0) {

                                              param_1->coll_radius = uVar8 & 0xfbfffbff;

                                              puVar2[1] = 0;

                                              param_1->coll_radius =

                                                   param_1->coll_radius & 0xfffffdff;

                                            }

                                          }

                                        }

                                        else {

                                          dVar5 = param_1->animate_state;

                                          param_1->coll_radius = uVar8 & 0xfbfffd7f;

                                          iVar6 = *(int *)(dVar5 + 0xe38);

                                          if (iVar6 != 0) {

                                            fx_delete(iVar6);

                                            *(undefined4 *)(dVar5 + 0xe38) = 0;

                                          }

                                          bVar13 = (float)param_1->vel1 == 0.0;

                                          if ((param_1->flags & 0x80000) == 0) {

                                            if ((bVar13) && ((float)param_1->vel2 == 0.0)) {

                                              uVar11 = 0x3f;

                                            }

                                            else {

                                              uVar11 = 0x41;

                                            }

                                            goto LAB_004c2e20;

                                          }

joined_r0x004c3c32:

                                          if (bVar13) {

                                            if ((float)param_1->vel2 <= 0.0) {

                                              if (0.0 <= (float)param_1->vel2) {

                                                uVar11 = 0x3d;

                                              }

                                              else {

                                                uVar11 = 0x47;

                                              }

                                            }

                                            else {

                                              uVar11 = 0x45;

                                            }

                                          }

                                          else {

                                            uVar11 = 0x3b;

                                          }

                                        }

LAB_004c4317:

                                        if (uVar11 != 0xffffffff) goto LAB_004c2e20;

                                      }

                                    }

                                    else {

                                      if (((uVar12 != 10) || (puVar2[0x3d7] != 0)) ||

                                         ((uVar8 & 0x10) == 0)) goto LAB_004c3980;

                                      if (uVar10 == 0) goto LAB_004c4317;

                                      object_create_child(param_1,1,0x29d);

                                      param_1->coll_radius = param_1->coll_radius & 0xffffffef;

                                      uStack_58 = 0;

                                    }

LAB_004c4320:

                                    fStack_40 = (float)param_1->pad_128 - (float)param_1->loc_accum1

                                    ;

                                    fStack_3c = *(float *)&param_1->field_0x12c -

                                                (float)param_1->loc_accum2;

                                    cVar9 = '\0';

                                    param_1->coll_radius = param_1->coll_radius & 0xfffff7ff;

                                    fStack_38 = (float)param_1->loc_accum0 -

                                                (float)param_1->loc_accum3;

                                    fVar14 = (float10)vec3_len(&fStack_40);

                                    fVar1 = (float)fVar14;

                                    if ((float10)*(float *)(DAT_00632ed8 + 0xbc8) <= fVar14) {

                                      fVar14 = (float10)vec3_len(&param_1->loc_accum1);

                                      fVar15 = (float10)vec3_len(&param_1->pad_128);

                                      if (fVar15 < (float10)(float)fVar14) {

                                        cVar9 = (*(float *)(DAT_00632ed8 + 0x864) < fVar1 !=

                                                (*(float *)(DAT_00632ed8 + 0x864) == fVar1)) +

                                                (*(float *)(DAT_00632ed8 + 0xbc8) < fVar1 !=

                                                (*(float *)(DAT_00632ed8 + 0xbc8) == fVar1));

                                      }

                                    }

                                    if ((((uVar12 == 0x1d) || (uVar12 == 0x1c)) && (cVar9 != '\0'))

                                       && (iVar6 = fx_create(param_1), iVar6 != 0)) {

                                      obj_damage_apply(0x1a,(fVar1 - *(float *)(DAT_00632ed8 + 0xbc8

                                                                               )) *

                                                            *(float *)(DAT_00632ed8 + 0x1180) +

                                                            *(float *)(DAT_00632ed8 + 0xc08),param_1

                                                       ,0,&param_1->field_0xa0,0);

                                      sound_play_player(0x6a0,param_1);

                                    }

                                    if ((((param_1->flags & 0x80000) == 0) &&

                                        ((*(byte *)param_1->pad_104 & 2) == 0)) ||

                                       ((-*(float *)(DAT_00632ed8 + 0x1174) <=

                                         (float)param_1->loc_accum0 &&

                                        ((uVar12 != 0x1d ||

                                         (-*(float *)(DAT_00632ed8 + 0x1178) <=

                                          (float)param_1->loc_accum0)))))) {

                                      if (cVar9 == '\0') {

                                        if (((((uVar12 == 0x20) || (uVar12 == 0x1e)) ||

                                             (uVar12 == 0x21)) || (uVar12 == 0x22)) &&

                                           (uVar11 = uVar12, uVar10 == 0)) goto LAB_004c4528;

                                      }

                                      else {

                                        uStack_30 = *(undefined4 *)&param_1->field_0xa0;

                                        uStack_2c = *(undefined4 *)&param_1->field_0xa4;

                                        uStack_28 = *(undefined4 *)&param_1->field_0xa8;

                                        fx_get_free_effect__Fv();

                                        if (cVar9 == '\x02') {

                                          uVar11 = 0x22;

                                          if ((float)puVar2[0x36e] == 0.0) {

                                            uVar11 = 0x21;

                                          }

                                          if ((uVar12 == 0x1d) || (uVar12 == 0x1c)) {

                                            iVar6 = crt_rand_scaled(100);

                                            if (iVar6 < 0x32) {

                                              uVar16 = 0x36e;

                                            }

                                            else {

                                              uVar16 = 0x36f;

                                            }

LAB_004c4520:

                                            sound_play_player(uVar16,param_1);

                                          }

                                        }

                                        else {

                                          if (cVar9 != '\x01') goto LAB_004c4539;

                                          uVar11 = 0x1e;

                                          if ((float)puVar2[0x36e] == 0.0) {

                                            uVar11 = 0x20;

                                          }

                                          if ((uVar12 == 0x1d) || (uVar12 == 0x1c)) {

                                            iVar6 = crt_rand_scaled(100);

                                            if (iVar6 < 0x32) {

                                              uVar16 = 0x338;

                                            }

                                            else {

                                              uVar16 = 0x339;

                                            }

                                            goto LAB_004c4520;

                                          }

                                        }

LAB_004c4528:

                                        if (uVar11 != 0xffffffff) goto LAB_004c2e20;

                                      }

LAB_004c4539:

                                      uVar8 = *puVar2;

                                      if ((char)uVar8 < '\0') {

                                        uVar12 = 9;

                                      }

                                      else if ((param_1->coll_radius & 0x8000000) == 0) {

                                        if ((param_1->coll_radius & 0x10) == 0) {

                                          if ((uVar12 == 0x4e) || ((uVar8 & 0x10) != 0)) {

                                            if (param_1->field_0x20a != '\0') goto LAB_004c4796;

                                            if ((char)param_1->field_0x20b < '\x01') {

                                              if ((char)param_1->field_0x20b < '\0')

                                              goto LAB_004c47d6;

                                              if ((uVar12 != 0x4e) || (uVar10 == 0)) {

                                                uVar12 = 0x4e;

                                                *puVar2 = uVar8 & 0xffffffef;

                                                goto LAB_004c2e2c;

                                              }

                                              uVar12 = 0;

                                            }

                                            else {

                                              uVar12 = 3;

                                            }

                                          }

                                          else if ((float)param_1->vel1 == 0.0) {

                                            if (0.0 < (float)param_1->vel2) {

                                              uVar12 = 3;

                                            }

                                            else if ((float)param_1->vel2 < 0.0) {

LAB_004c47d6:

                                              uVar12 = 4;

                                            }

                                            else {

                                              if ((float)param_1->vel_w == 0.0) {

                                                if ((uVar8 & 0x100) == 0) {

                                                  if (((uVar12 != 0x5c) && (uVar12 != 0x5d)) ||

                                                     (uVar10 != 0)) {

                                                    uVar12 = -(uint)((param_1->flags & 0x800) != 0)

                                                             & 0x48;

                                                    goto LAB_004c46c3;

                                                  }

                                                }

                                                else {

                                                  *puVar2 = uVar8 & 0xfffffeff;

                                                  if ((uVar12 != 0x5c) && (uVar12 != 0x5d)) {

                                                    iVar6 = crt_rand_scaled(100);

                                                    goto LAB_004c46b2;

                                                  }

                                                }

                                              }

                                              else if ((uVar8 & 0x100) == 0) {

                                                if (((uVar12 != 0x5c) && (uVar12 != 0x5d)) ||

                                                   (uVar10 != 0)) {

                                                  if ((param_1->flags & 0x800) == 0) {

                                                    uVar12 = 8;

                                                  }

                                                  else {

                                                    uVar12 = 0x48;

                                                  }

                                                  goto LAB_004c46c3;

                                                }

                                              }

                                              else {

                                                *puVar2 = uVar8 & 0xfffffeff;

                                                if ((uVar12 != 0x5c) && (uVar12 != 0x5d)) {

                                                  iVar6 = crt_rand_scaled(100);

LAB_004c46b2:

                                                  uVar12 = (0x31 < iVar6) + 0x5c;

                                                }

                                              }

                                              if (uVar12 == 0x4e) goto LAB_004c2e2c;

                                            }

                                          }

                                          else {

LAB_004c4796:

                                            uVar12 = 5;

                                          }

                                        }

                                        else {

                                          uVar12 = 10;

                                        }

                                      }

                                      else {

                                        uVar12 = 0x38;

                                      }

LAB_004c46c3:

                                      *puVar2 = *puVar2 & 0xffffffef;

                                      goto LAB_004c2e2c;

                                    }

                                    uVar11 = 0x4d;

                                  }

                                  else {

                                    uVar11 = 0x51;

                                    if ((uVar12 == 0x51) && (uVar10 != 0)) {

                                      dVar5 = param_1->animate_state;

                                      param_1->coll_radius = uVar8 & 0xfbf7ffff;

                                      iVar6 = *(int *)(dVar5 + 0xea4);

                                      if (iVar6 != 0) {

                                        if (*(int *)(iVar6 + 0x274) == 0) {

                                          ObjIsKabuto(*(undefined4 *)(iVar6 + 0x210));

                                        }

                                        else {

                                          iVar6 = ObjIsMecc(*(int *)(iVar6 + 0x274));

                                          if ((iVar6 != 0) ||

                                             (iVar6 = ObjIsReaper(*(undefined4 *)

                                                                   (*(int *)(dVar5 + 0xea4) + 0x274)

                                                                 ), iVar6 != 0)) {

                                            smartie_unlock_from_player

                                                      (*(int *)(dVar5 + 0xea4),

                                                       *(undefined4 *)

                                                        (*(int *)(dVar5 + 0xea4) + 0x274),4);

                                          }

                                        }

                                        fx_reaper_bubble_create

                                                  (*(undefined4 *)(dVar5 + 0xea4),param_1);

                                      }

                                      *(undefined4 *)(dVar5 + 0xea4) = 0;

                                    }

                                  }

                                }

                                else {

                                  uVar11 = 0x58;

                                  if (uVar12 == 0x58) {

                                    if (uVar10 != 0) {

                                      param_1->coll_radius = uVar8 & 0xfbefffff;

                                    }

                                    if (((0.33333334 <= (float)param_1->pad_14) &&

                                        (*(float *)&param_1->field_0x18 < 0.33333334)) &&

                                       (iVar6 = fx_create(param_1), iVar6 != 0)) {

                                      reaper_fire_spell__FP6OBJECTiP3P3DT0i

                                                (param_1,0x24,puVar2 + 0x3a6,0,0xffffffff);

                                    }

                                  }

                                }

                              }

                              else {

                                uVar11 = 0x57;

                                if (uVar12 == 0x57) {

                                  if (uVar10 != 0) {

                                    param_1->coll_radius = uVar8 & 0xfbdfffff;

                                  }

                                  if (((0.33333334 <= (float)param_1->pad_14) &&

                                      (*(float *)&param_1->field_0x18 < 0.33333334)) &&

                                     (iVar6 = fx_create(param_1), iVar6 != 0)) {

                                    reaper_fire_spell__FP6OBJECTiP3P3DT0i

                                              (param_1,0x25,puVar2 + 0x3a3,0,0xffffffff);

                                  }

                                }

                              }

                            }

                            else {

                              uVar11 = 0x55;

                              if (uVar12 == 0x55) {

                                if (uVar10 != 0) {

                                  param_1->coll_radius = uVar8 & 0xfaffffff;

                                }

                                if (((0.33333334 <= (float)param_1->pad_14) &&

                                    (*(float *)&param_1->field_0x18 < 0.33333334)) &&

                                   (iVar6 = fx_create(param_1), iVar6 != 0)) {

                                  reaper_fire_spell__FP6OBJECTiP3P3DT0i

                                            (param_1,0x27,puVar2 + 0x399,0,0xffffffff);

                                }

                              }

                            }

                          }

                          else {

                            uVar11 = 0x54;

                            if ((uVar12 == 0x54) && (uVar10 != 0)) {

                              param_1->coll_radius = uVar8 & 0xfb7fffff;

                              reaper_create_fake_reaper__FP6OBJECTP3P3Dfi(param_1,puVar2 + 0xc);

                              param_1->coll_radius = param_1->coll_radius | 8;

                            }

                          }

                        }

                        else {

                          uVar11 = 0x50;

                          if (uVar12 == 0x50) {

                            if (uVar10 != 0) {

                              *puVar2 = uVar3 & 0xffffffbf;

                            }

                            if (((0.33333334 <= (float)param_1->pad_14) &&

                                (*(float *)&param_1->field_0x18 < 0.33333334)) &&

                               (iVar6 = fx_create(param_1), iVar6 != 0)) {

                              reaper_fire_spell__FP6OBJECTiP3P3DT0i

                                        (param_1,0x2c,puVar2 + 0x393,0,0xffffffff);

                            }

                          }

                        }

                      }

                      else {

                        uVar11 = 0x5b;

                        if (uVar12 == 0x5b) {

                          if (uVar10 != 0) {

                            param_1->coll_radius = uVar8 & 0xdbffffff;

                          }

                          if (((0.33333334 <= (float)param_1->pad_14) &&

                              (*(float *)&param_1->field_0x18 < 0.33333334)) &&

                             (iVar6 = fx_create(param_1), iVar6 != 0)) {

                            reaper_fire_spell__FP6OBJECTiP3P3DT0i

                                      (param_1,0x33,puVar2 + 0x396,0,0xffffffff);

                          }

                        }

                      }

                    }

                    else {

                      uVar11 = 0x52;

                      if (uVar12 == 0x52) {

                        if (uVar10 != 0) {

                          param_1->coll_radius = uVar8 & 0xbbffffff;

                        }

                        if (((0.33333334 <= (float)param_1->pad_14) &&

                            (*(float *)&param_1->field_0x18 < 0.33333334)) &&

                           (iVar6 = fx_create(param_1), iVar6 != 0)) {

                          reaper_fire_spell__FP6OBJECTiP3P3DT0i

                                    (param_1,0x26,puVar2 + 0x390,0,0xffffffff);

                        }

                      }

                    }

                  }

                  else {

                    uVar11 = 0x56;

                    if ((uVar12 == 0x56) && (uVar10 != 0)) {

                      param_1->coll_radius = uVar8 & 0xfbfbffff;

                      iVar6 = fx_create(param_1);

                      if (iVar6 != 0) {

                        _DAT_00632bc8 = 0;

                        DAT_00632bc4 = 1;

                        sound_play(0x3b9);

                      }

                    }

                  }

                }

                else {

                  uVar11 = 0x59;

                  if (uVar12 == 0x59) {

                    if (uVar10 != 0) {

                      param_1->coll_radius = uVar8 & 0xfbfdffff;

                      uVar11 = 0xffffffff;

                    }

                    if (((0.33333334 <= (float)param_1->pad_14) &&

                        (*(float *)&param_1->field_0x18 < 0.33333334)) &&

                       (iVar6 = fx_create(param_1), iVar6 != 0)) {

                      reaper_finish_slow_follow__FP6OBJECTPUi(param_1,0);

                    }

                    goto LAB_004c4317;

                  }

                }

              }

              else {

                uVar11 = 0x5a;

                if ((uVar12 == 0x5a) && (uVar10 != 0)) {

                  iVar6 = fx_create(param_1);

                  if (iVar6 == 0) {

                    param_1->coll_radius = param_1->coll_radius & 0xfffeffff;

                    goto LAB_004c4320;

                  }

                  param_1->coll_radius = param_1->coll_radius & 0xfffeffff;

                  fxb_firecircle_create(param_1,puVar2 + 0x3cb,0xffffffff,0xffffffff);

                }

              }

            }

            else {

              if ((uVar12 == 0xb) && (uVar10 != 0)) goto LAB_004c4317;

              uVar11 = 0xb;

            }

          }

          else if (puVar2[0x36d] == 0) {

            if ((uVar8 & 0x200) == 0) {

LAB_004c326c:

              uVar11 = 6;

            }

            else if ((uVar12 == 7) && (uVar10 != 0)) {

              uVar11 = 6;

              puVar2[1] = 0;

LAB_004c3b4f:

              param_1->coll_radius = param_1->coll_radius & 0xfffffdff;

            }

            else {

              uVar11 = 7;

            }

          }

          else if ((uVar8 & 0x200) == 0) {

            if ((uVar8 & 0x40) == 0) goto LAB_004c326c;

            if (-1 < cVar9) goto LAB_004c4317;

            uVar11 = 0x42;

          }

          else {

            dVar5 = param_1->animate_state;

            param_1->coll_radius = uVar8 & 0xfbfffd7f;

            iVar6 = *(int *)(dVar5 + 0xe38);

            if (iVar6 != 0) {

              fx_delete(iVar6);

              *(undefined4 *)(dVar5 + 0xe38) = 0;

            }

            uVar11 = 0x43;

          }

        }

        else {

          uVar11 = 0xb;

          if ((uVar12 == 0xb) && (uVar10 != 0)) {

            param_1->coll_radius = uVar8 & 0xebffffff;

          }

        }

      }

      else {

        if ((uVar12 == 0x4f) && (uVar10 != 0)) {

          *puVar2 = uVar3 & 0xffffffdf;

          goto LAB_004c4317;

        }

        uVar11 = 0x4f;

      }

    }

    else if ((uVar12 != 0x2f) || (uVar10 == 0)) {

      uVar11 = 0x2f;

    }

  }

  else {

    fVar14 = (float10)get_floor_z_point(&param_1->field_0xa0);

    if (((float10)*(float *)&param_1->field_0xa8 < (float10)0.5 + fVar14 !=

         ((float10)*(float *)&param_1->field_0xa8 == (float10)0.5 + fVar14)) ||

       (*(float *)&param_1->field_0xa8 < 0.0)) {

      if ((uVar12 == 0x4a) || (uVar12 == 0x4b)) {

        uVar11 = 0x4b;

      }

      else {

        if ((uVar12 == 0x49) || (uVar12 == 0x24)) goto LAB_004c4317;

        if ((param_1->flags & 0x800) == 0) {

          uVar11 = 0x24;

        }

        else {

          uVar11 = 0x49;

        }

      }

    }

    else {

      uVar11 = 0x4a;

    }

  }

LAB_004c2e20:

  *puVar2 = *puVar2 & 0xfffffeef;

  uVar12 = uVar11;

LAB_004c2e2c:

  if ((&DAT_00560c50)[uStack_58 + uVar12 * 2] != param_1->anim) {

    uVar8 = puVar2[0x3f4];

    if (uVar12 == 0x4d) {

      if (uVar8 == 0) {

        pOStack_1c = param_1;

        uStack_20 = 0xffffffff;

        uStack_24 = 8;

        uVar8 = fx_get_free_effect__Fv();

        puVar2[0x3f4] = uVar8;

      }

    }

    else {

      if (uVar8 != 0) {

        fx_delete(uVar8);

      }

      puVar2[0x3f4] = 0;

    }

    puVar2[0x17] = uVar12;

    ObjectSetAnim(param_1);

  }

  return;

}

/* ===== ret_const_x1004_c3 @ 0x004C4870 ===== */
undefined4 ret_const_x1004_c3(void)



{

  return 0x1004;

}

/* ===== obj_snap_variant_a @ 0x004C4880 ===== */
void obj_snap_variant_a(int param_1)



{

  int iVar1;

  undefined4 *puVar2;

  int iVar3;

  float *pfVar4;

  int iVar5;

  float fVar6;

  int iVar7;

  int iVar8;

  float10 fVar9;

  

  *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xfffffeff;

  iVar5 = *(int *)(param_1 + 0x100);

  iVar1 = iVar5 + 0x6c;

  if ((DAT_00632a88 == param_1) && (DAT_00632bb4 != 0)) goto LAB_004c4aab;

  if (*(float *)(param_1 + 200) < 360.0) {

    if (*(float *)(param_1 + 200) < 0.0) {

      fVar6 = *(float *)(param_1 + 200) + 360.0;

      goto LAB_004c48ea;

    }

  }

  else {

    fVar6 = *(float *)(param_1 + 200) - 360.0;

LAB_004c48ea:

    *(float *)(param_1 + 200) = fVar6;

  }

  if (*(int *)(iVar5 + 0x68) == -1) {

    *(undefined4 *)(iVar5 + 0x68) = 0;

    do {

      puVar2 = (undefined4 *)(iVar1 + *(int *)(iVar5 + 0x68) * 0x28);

      *puVar2 = *(undefined4 *)(param_1 + 0xa0);

      puVar2[1] = *(undefined4 *)(param_1 + 0xa4);

      puVar2[2] = *(undefined4 *)(param_1 + 0xa8);

      puVar2[3] = *(undefined4 *)(param_1 + 200);

      puVar2[4] = *(undefined4 *)(param_1 + 0x10);

      puVar2[5] = *(undefined4 *)(param_1 + 0x14);

      puVar2[6] = *(undefined4 *)(param_1 + 0x2c);

      puVar2[7] = *(undefined4 *)(param_1 + 0x58);

      puVar2[8] = *(undefined4 *)(param_1 + 0x5c);

      *(float *)(iVar5 + 0x90 + *(int *)(iVar5 + 0x68) * 0x28) =

           (float)*(int *)(iVar5 + 0x68) * 0.025;

      iVar7 = *(int *)(iVar5 + 0x68) + 1;

      *(int *)(iVar5 + 0x68) = iVar7;

    } while (iVar7 < 0x50);

    *(undefined4 *)(iVar5 + 0x68) = 0x4f;

LAB_004c4978:

    iVar8 = *(int *)(iVar5 + 0x68);

    iVar7 = iVar5 + 0x44 + iVar8 * 0x28;

  }

  else {

    if (*(int *)(iVar5 + 0x68) != 0) goto LAB_004c4978;

    iVar7 = iVar5 + 0xcc4;

    iVar8 = 0;

  }

  iVar3 = iVar1 + iVar8 * 0x28;

  if (*(float *)(iVar5 + 0x90 + iVar8 * 0x28) - *(float *)(iVar7 + 0x24) < 0.025) {

    fillin_snap__FP6OBJECTP8TimeSnap(param_1,iVar3);

    pfVar4 = (float *)(iVar5 + 0x90 + *(int *)(iVar5 + 0x68) * 0x28);

    fVar9 = (float10)FRateGetSecsframe(param_1,0);

    *pfVar4 = (float)(fVar9 + (float10)*pfVar4);

    puVar2 = DAT_00632d74;

  }

  else {

    fVar6 = *(float *)(iVar3 + 0x24);

    *(int *)(iVar5 + 0x68) = iVar8 + 1;

    if (0x4f < iVar8 + 1) {

      *(undefined4 *)(iVar5 + 0x68) = 0;

    }

    puVar2 = (undefined4 *)(iVar1 + *(int *)(iVar5 + 0x68) * 0x28);

    *puVar2 = *(undefined4 *)(param_1 + 0xa0);

    puVar2[1] = *(undefined4 *)(param_1 + 0xa4);

    puVar2[2] = *(undefined4 *)(param_1 + 0xa8);

    puVar2[3] = *(undefined4 *)(param_1 + 200);

    puVar2[4] = *(undefined4 *)(param_1 + 0x10);

    puVar2[5] = *(undefined4 *)(param_1 + 0x14);

    puVar2[6] = *(undefined4 *)(param_1 + 0x2c);

    puVar2[7] = *(undefined4 *)(param_1 + 0x58);

    puVar2[8] = *(undefined4 *)(param_1 + 0x5c);

    fVar9 = (float10)FRateGetSecsframe(param_1,0);

    *(float *)(iVar5 + 0x90 + *(int *)(iVar5 + 0x68) * 0x28) = (float)(fVar9 + (float10)fVar6);

    puVar2 = DAT_00632d74;

  }

  for (; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {

    iVar7 = puVar2[3];

    if ((*(int *)(iVar7 + 0x1e0) == 0x3e) && (*(int *)(iVar7 + 0x274) == param_1)) {

      reaper_set_trail__FP6OBJECTT0fiiP8TimeSnap

                (param_1,iVar7,

                 (float)(*(int *)(iVar7 + 0x174) + 1) * *(float *)(DAT_00632ed8 + 0x500),0,

                 *(undefined4 *)(iVar5 + 0x68),iVar1);

    }

  }

LAB_004c4aab:

  if (*(int *)(iVar5 + 0xfec) != 0) {

    sound_interrupt_sequence(iVar5 + 0xfec);

  }

  if (*(int *)(iVar5 + 0xff0) != 0) {

    sound_interrupt_sequence(iVar5 + 0xff0);

  }

  if (*(int *)(iVar5 + 0xff4) != 0) {

    sound_stop_player(0x36c,param_1);

    *(undefined4 *)(iVar5 + 0xff4) = 0;

  }

  return;

}

/* ===== fillin_snap__FP6OBJECTP8TimeSnap @ 0x004C4B10 ===== */
void fillin_snap__FP6OBJECTP8TimeSnap(int param_1,undefined4 *param_2)



{

  *param_2 = *(undefined4 *)(param_1 + 0xa0);

  param_2[1] = *(undefined4 *)(param_1 + 0xa4);

  param_2[2] = *(undefined4 *)(param_1 + 0xa8);

  param_2[3] = *(undefined4 *)(param_1 + 200);

  param_2[4] = *(undefined4 *)(param_1 + 0x10);

  param_2[5] = *(undefined4 *)(param_1 + 0x14);

  param_2[6] = *(undefined4 *)(param_1 + 0x2c);

  param_2[7] = *(undefined4 *)(param_1 + 0x58);

  param_2[8] = *(undefined4 *)(param_1 + 0x5c);

  return;

}

/* ===== obj_snap_variant_b @ 0x004C4B60 ===== */
void obj_snap_variant_b(int param_1)



{

  int iVar1;

  undefined4 *puVar2;

  int iVar3;

  float *pfVar4;

  int iVar5;

  float fVar6;

  int iVar7;

  int iVar8;

  float10 fVar9;

  

  *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xfffffeff;

  iVar5 = *(int *)(param_1 + 0x100);

  iVar1 = iVar5 + 0x6c;

  if ((DAT_00632a88 == param_1) && (DAT_00632bb4 != 0)) goto LAB_004c4d8b;

  if (*(float *)(param_1 + 200) < 360.0) {

    if (*(float *)(param_1 + 200) < 0.0) {

      fVar6 = *(float *)(param_1 + 200) + 360.0;

      goto LAB_004c4bca;

    }

  }

  else {

    fVar6 = *(float *)(param_1 + 200) - 360.0;

LAB_004c4bca:

    *(float *)(param_1 + 200) = fVar6;

  }

  if (*(int *)(iVar5 + 0x68) == -1) {

    *(undefined4 *)(iVar5 + 0x68) = 0;

    do {

      puVar2 = (undefined4 *)(iVar1 + *(int *)(iVar5 + 0x68) * 0x28);

      *puVar2 = *(undefined4 *)(param_1 + 0xa0);

      puVar2[1] = *(undefined4 *)(param_1 + 0xa4);

      puVar2[2] = *(undefined4 *)(param_1 + 0xa8);

      puVar2[3] = *(undefined4 *)(param_1 + 200);

      puVar2[4] = *(undefined4 *)(param_1 + 0x10);

      puVar2[5] = *(undefined4 *)(param_1 + 0x14);

      puVar2[6] = *(undefined4 *)(param_1 + 0x2c);

      puVar2[7] = *(undefined4 *)(param_1 + 0x58);

      puVar2[8] = *(undefined4 *)(param_1 + 0x5c);

      *(float *)(iVar5 + 0x90 + *(int *)(iVar5 + 0x68) * 0x28) =

           (float)*(int *)(iVar5 + 0x68) * 0.025;

      iVar7 = *(int *)(iVar5 + 0x68) + 1;

      *(int *)(iVar5 + 0x68) = iVar7;

    } while (iVar7 < 0x50);

    *(undefined4 *)(iVar5 + 0x68) = 0x4f;

LAB_004c4c58:

    iVar8 = *(int *)(iVar5 + 0x68);

    iVar7 = iVar5 + 0x44 + iVar8 * 0x28;

  }

  else {

    if (*(int *)(iVar5 + 0x68) != 0) goto LAB_004c4c58;

    iVar7 = iVar5 + 0xcc4;

    iVar8 = 0;

  }

  iVar3 = iVar1 + iVar8 * 0x28;

  if (*(float *)(iVar5 + 0x90 + iVar8 * 0x28) - *(float *)(iVar7 + 0x24) < 0.025) {

    fillin_snap__FP6OBJECTP8TimeSnap(param_1,iVar3);

    pfVar4 = (float *)(iVar5 + 0x90 + *(int *)(iVar5 + 0x68) * 0x28);

    fVar9 = (float10)FRateGetSecsframe(param_1,0);

    *pfVar4 = (float)(fVar9 + (float10)*pfVar4);

    puVar2 = DAT_00632d74;

  }

  else {

    fVar6 = *(float *)(iVar3 + 0x24);

    *(int *)(iVar5 + 0x68) = iVar8 + 1;

    if (0x4f < iVar8 + 1) {

      *(undefined4 *)(iVar5 + 0x68) = 0;

    }

    puVar2 = (undefined4 *)(iVar1 + *(int *)(iVar5 + 0x68) * 0x28);

    *puVar2 = *(undefined4 *)(param_1 + 0xa0);

    puVar2[1] = *(undefined4 *)(param_1 + 0xa4);

    puVar2[2] = *(undefined4 *)(param_1 + 0xa8);

    puVar2[3] = *(undefined4 *)(param_1 + 200);

    puVar2[4] = *(undefined4 *)(param_1 + 0x10);

    puVar2[5] = *(undefined4 *)(param_1 + 0x14);

    puVar2[6] = *(undefined4 *)(param_1 + 0x2c);

    puVar2[7] = *(undefined4 *)(param_1 + 0x58);

    puVar2[8] = *(undefined4 *)(param_1 + 0x5c);

    fVar9 = (float10)FRateGetSecsframe(param_1,0);

    *(float *)(iVar5 + 0x90 + *(int *)(iVar5 + 0x68) * 0x28) = (float)(fVar9 + (float10)fVar6);

    puVar2 = DAT_00632d74;

  }

  for (; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {

    iVar7 = puVar2[3];

    if ((*(int *)(iVar7 + 0x1e0) == 0x3e) && (*(int *)(iVar7 + 0x274) == param_1)) {

      reaper_set_trail__FP6OBJECTT0fiiP8TimeSnap

                (param_1,iVar7,

                 (float)(*(int *)(iVar7 + 0x174) + 1) * *(float *)(DAT_00632ed8 + 0x500),0,

                 *(undefined4 *)(iVar5 + 0x68),iVar1);

    }

  }

LAB_004c4d8b:

  if (*(int *)(iVar5 + 0xfec) != 0) {

    sound_interrupt_sequence(iVar5 + 0xfec);

  }

  if (*(int *)(iVar5 + 0xff0) != 0) {

    sound_interrupt_sequence(iVar5 + 0xff0);

  }

  if (*(int *)(iVar5 + 0xff4) != 0) {

    sound_stop_player(0x36c,param_1);

    *(undefined4 *)(iVar5 + 0xff4) = 0;

  }

  return;

}

/* ===== reaper_fx_at_bldg_b @ 0x004C4DF0 ===== */
void reaper_fx_at_bldg_b(int param_1)



{

  int iVar1;

  int iVar2;

  float10 fVar3;

  float10 fVar4;

  undefined1 local_c [12];

  

  iVar2 = *(int *)(param_1 + 0x100);

  iVar1 = fx_create(param_1);

  if ((((iVar1 != 0) && (DAT_00632bb0 == 0)) &&

      ((iVar1 = dialog_level_is_base_dup0052aa70(), iVar1 == 0 ||

       (iVar1 = game_mode_set3_check(DAT_00632f18), iVar1 == 0)))) &&

     ((iVar2 = *(int *)(iVar2 + 0xcfc), iVar2 != 0 && (iVar2 = base_slot9or1_get(iVar2), iVar2 != 0)

      ))) {

    bldg_get_refpt_worldloc(iVar2,10,local_c);

    fVar3 = (float10)distancesq3d(local_c,param_1 + 0xa0);

    fVar4 = (float10)distancesq3d(local_c,param_1 + 0xac);

    if (((float)fVar3 < 36.0 != ((float)fVar3 == 36.0)) && ((float10)36.0 < fVar4)) {

      evilreaper_award_flow(param_1);

      return;

    }

  }

  return;

}

/* ===== mecc_drop_carried_object_2 @ 0x004C4EC0 ===== */
void mecc_drop_carried_object_2(int param_1,int param_2)



{

  int iVar1;

  int iVar2;

  undefined4 *puVar3;

  int iVar4;

  int iVar5;

  undefined1 local_c [12];

  

  iVar1 = *(int *)(param_2 + 0x100);

  iVar2 = *(int *)(param_1 + 0x100);

  iVar4 = fx_create(param_2);

  if ((((iVar4 == 0) || (iVar5 = *(int *)(iVar1 + 0x10), iVar5 == 0)) ||

      (iVar5 == *(int *)(param_1 + 0x188))) || (iVar5 = objanim_select_animloop(iVar5), iVar5 == 0))

  {

    lift_logic__FP6OBJECT(param_2);

    bldg_get_refpt_worldloc(param_2,0xb,local_c);

    object_set_location_p3d(param_1,local_c);

    *(undefined1 *)(param_1 + 0x208) = 0;

    *(undefined1 *)(param_1 + 0x20b) = 0;

    *(undefined1 *)(param_1 + 0x20a) = 0;

    if (iVar4 != 0) {

      puVar3 = DAT_00632d98;

      if ((*(uint *)(param_1 + 0xdc) & 0x800000) != 0) {

        for (; puVar3 != (undefined4 *)0x0; puVar3 = (undefined4 *)*puVar3) {

          iVar4 = puVar3[3];

          if ((((*(uint *)(iVar4 + 0xd8) & 0x8000) == 0) && (*(int *)(iVar4 + 4) == 0xb)) &&

             (*(int *)(iVar4 + 0x274) == param_1)) {

            *(undefined4 *)(*(int *)(iVar4 + 0x100) + 0x54) = 0;

            smartie_from_back_to_partyhouse(iVar4,param_1,*(undefined4 *)(iVar2 + 0xcfc),param_2);

            break;

          }

        }

      }

      *(undefined4 *)(iVar1 + 0x10) = *(undefined4 *)(param_1 + 0x188);

    }

  }

  return;

}

/* ===== reaper_fx_at_bldg_a @ 0x004C4FD0 ===== */
void reaper_fx_at_bldg_a(int param_1)



{

  undefined4 uVar1;

  int iVar2;

  int iVar3;

  float10 fVar4;

  float10 fVar5;

  undefined1 local_c [12];

  

  iVar3 = *(int *)(param_1 + 0x100);

  if ((*(int *)(iVar3 + 0xcfc) != 0) && (iVar2 = fx_create(param_1), iVar2 != 0)) {

    uVar1 = *(undefined4 *)(iVar3 + 0xcfc);

    iVar3 = base_slot8_get_2(uVar1);

    if (iVar3 != 0) {

      bldg_get_refpt_worldloc(iVar3,0xb,local_c);

      fVar4 = (float10)distancesq3d(local_c,param_1 + 0xa0);

      fVar5 = (float10)distancesq3d(local_c,param_1 + 0xac);

      if (((float)fVar4 < 36.0 != ((float)fVar4 == 36.0)) && ((float10)36.0 < fVar5)) {

        iVar2 = fx_create(uVar1);

        if (iVar2 != 0) {

          mecc_drop_carried_object_2(param_1,iVar3);

          return;

        }

        iVar2 = dialog_level_is_base_dup0052aa70();

        if (iVar2 != 0) {

          reaper_state_check_i(uVar1,param_1,iVar3);

          return;

        }

      }

    }

  }

  return;

}

/* ===== obj_give_carried_item_2 @ 0x004C50B0 ===== */
void obj_give_carried_item_2(int param_1,int param_2)



{

  int iVar1;

  bool bVar2;

  int iVar3;

  

  iVar1 = *(int *)(param_2 + 0x100);

  if ((DAT_00632bbc == 0) || (iVar3 = fx_create(DAT_00632bbc), iVar3 == 0)) {

    bVar2 = false;

  }

  else {

    iVar3 = *(int *)(iVar1 + 0x10);

    bVar2 = true;

    if (((iVar3 != 0) && (iVar3 != *(int *)(param_1 + 0x188))) &&

       (iVar3 = objanim_select_animloop(iVar3), iVar3 != 0)) {

      return;

    }

  }

  giftshopview_enable(param_2,0);

  *(undefined1 *)(param_1 + 0x208) = 0;

  *(undefined1 *)(param_1 + 0x20b) = 0;

  *(undefined1 *)(param_1 + 0x20a) = 0;

  if (bVar2) {

    *(undefined4 *)(iVar1 + 0x10) = *(undefined4 *)(param_1 + 0x188);

  }

  return;

}

/* ===== lzo_checked_alloc @ 0x004C5130 ===== */
void lzo_checked_alloc(int param_1)



{

  int iVar1;

  undefined4 uVar2;

  undefined4 *puVar3;

  bool bVar4;

  int iVar5;

  int iVar6;

  float10 fVar7;

  float10 fVar8;

  undefined1 local_c [12];

  

  iVar1 = *(int *)(param_1 + 0x100);

  if ((*(int *)(iVar1 + 0xcfc) != 0) && (iVar5 = fx_create(param_1), iVar5 != 0)) {

    uVar2 = *(undefined4 *)(iVar1 + 0xcfc);

    for (puVar3 = DAT_00632d9c; puVar3 != (undefined4 *)0x0; puVar3 = (undefined4 *)*puVar3) {

      iVar1 = puVar3[3];

      if (((*(int *)(iVar1 + 4) == 0x3dd) && (iVar5 = lzo_assert(iVar1), iVar5 != 0)) &&

         ((*(int *)(iVar1 + 0x18c) == 1 || (*(int *)(iVar1 + 0x18c) == *(int *)(param_1 + 0x18c)))))

      {

        bldg_get_refpt_worldloc(iVar1,0,local_c);

        fVar7 = (float10)distancesq3d(local_c,param_1 + 0xa0);

        fVar8 = (float10)distancesq3d(local_c,param_1 + 0xac);

        if (((float)fVar7 < 36.0 != ((float)fVar7 == 36.0)) && ((float10)36.0 < fVar8)) {

          iVar5 = fx_create(uVar2);

          if (iVar5 == 0) {

            iVar5 = dialog_level_is_base_dup0052aa70();

            if (iVar5 != 0) {

              reaper_state_check_g(uVar2,param_1,iVar1);

            }

          }

          else {

            iVar5 = *(int *)(iVar1 + 0x100);

            if ((DAT_00632bbc == 0) || (iVar6 = fx_create(DAT_00632bbc), iVar6 == 0)) {

              bVar4 = false;

            }

            else {

              iVar6 = *(int *)(iVar5 + 0x10);

              bVar4 = true;

              if (((iVar6 != 0) && (iVar6 != *(int *)(param_1 + 0x188))) &&

                 (iVar6 = objanim_select_animloop(iVar6), iVar6 != 0)) goto LAB_004c52ae;

            }

            giftshopview_enable(iVar1,0);

            *(undefined1 *)(param_1 + 0x208) = 0;

            *(undefined1 *)(param_1 + 0x20b) = 0;

            *(undefined1 *)(param_1 + 0x20a) = 0;

            if (bVar4) {

              *(undefined4 *)(iVar5 + 0x10) = *(undefined4 *)(param_1 + 0x188);

            }

          }

        }

      }

LAB_004c52ae:

    }

  }

  return;

}

/* ===== lzo_spawn_checked @ 0x004C52D0 ===== */
/* PS2 candidate: base_startup__Fi (conf 0.335) */



void lzo_spawn_checked(int param_1)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int *piVar5;

  float10 fVar6;

  float local_28;

  undefined4 local_24;

  undefined4 local_20;

  undefined1 local_1c [4];

  undefined1 local_18 [12];

  undefined1 local_c [12];

  

  iVar2 = param_1;

  iVar1 = *(int *)(param_1 + 0x100);

  param_1 = 0;

  if ((((*(int *)(iVar1 + 0xcfc) != 0) && (iVar3 = fx_create(iVar2), iVar3 != 0)) &&

      (iVar1 = *(int *)(*(int *)(*(int *)(iVar1 + 0xcfc) + 0x100) + 0x580), iVar1 != 0)) &&

     (iVar3 = lzo_assert(iVar1), iVar3 != 0)) {

    bldg_get_refpt_worldloc(iVar1,0,local_18);

    fVar6 = (float10)distancesq3d(local_18,iVar2 + 0xa0);

    local_28 = (float)fVar6;

    fVar6 = (float10)distancesq3d(local_18,iVar2 + 0xac);

    if (((local_28 < 400.0 != (local_28 == 400.0)) && ((float10)400.0 < fVar6)) &&

       (*(int *)(iVar1 + 0xe4) == 9)) {

      bldg_get_refpt_worldlocdir(iVar1,2,local_c,local_1c);

      piVar5 = DAT_00632d68;

      if (DAT_00632d68 != (int *)0x0) {

        do {

          iVar3 = piVar5[3];

          iVar4 = ObjIsJetski(iVar3);

          if (iVar4 != 0) {

            fVar6 = (float10)distancesq3d(iVar3 + 0xa0,local_c);

            if (fVar6 < (float10)100.0) {

              return;

            }

            param_1 = param_1 + 1;

          }

          piVar5 = (int *)*piVar5;

        } while (piVar5 != (int *)0x0);

        if (4 < param_1) {

          return;

        }

      }

      local_28 = 0.0;

      local_24 = 0;

      local_20 = 0;

      param_1 = 0;

      bldg_get_refpt_worldlocdir(iVar1,2,&local_28,&param_1);

      iVar3 = object_allocate_type(0x434,0x80000000);

      object_set_location_p3d(iVar3,&local_28);

      *(int *)(iVar3 + 200) = param_1;

      *(uint *)(iVar3 + 0x1d0) = *(uint *)(iVar3 + 0x1d0) | 0xf0f;

      *(undefined4 *)(iVar3 + 0x18c) = *(undefined4 *)(iVar2 + 0x18c);

      iVar4 = reaper_0052e4a0(iVar2);

      if (iVar4 != 0) {

        local_24 = *(undefined4 *)(iVar3 + 0x188);

        local_28 = *(float *)(iVar1 + 0x188);

        reaper_00530bd0(iVar2,0,2,0,0x33,&local_28);

        return;

      }

    }

  }

  return;

}

/* ===== reaper_check_enter_teleport__FP6OBJECT @ 0x004C54D0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* PS2 candidate: reaper_check_enter_teleport__FP6OBJECT (conf 0.518) */



void reaper_check_enter_teleport__FP6OBJECT(int param_1)



{

  char cVar1;

  bool bVar2;

  int iVar3;

  int iVar4;

  char *pcVar5;

  int iVar6;

  int iVar7;

  char *pcVar8;

  undefined4 *puVar9;

  float10 fVar10;

  float10 fVar11;

  undefined4 local_1c;

  undefined4 local_18;

  undefined4 local_14;

  undefined4 local_10;

  undefined4 local_c;

  undefined4 local_8;

  undefined4 local_4;

  

  iVar3 = param_1;

  iVar7 = *(int *)(param_1 + 0x100);

  if ((((*(int *)(iVar7 + 0xcfc) != 0) && (iVar4 = fx_create(param_1), iVar4 != 0)) &&

      (iVar7 = *(int *)(*(int *)(*(int *)(iVar7 + 0xcfc) + 0x100) + 0x584), iVar7 != 0)) &&

     (iVar4 = lzo_assert(iVar7), iVar4 != 0)) {

    bldg_get_refpt_worldloc(iVar7,0,&local_1c);

    bVar2 = false;

    while( true ) {

      fVar10 = (float10)distancesq3d(&local_1c,iVar3 + 0xa0);

      fVar11 = (float10)distancesq3d(&local_1c,iVar3 + 0xac);

      if (((float)fVar10 < 36.0 != ((float)fVar10 == 36.0)) && ((float10)36.0 < fVar11)) break;

      if (bVar2) {

        return;

      }

      bVar2 = true;

      puVar9 = DAT_00632d9c;

      while( true ) {

        if (puVar9 == (undefined4 *)0x0) {

          return;

        }

        iVar4 = puVar9[3];

        if (((*(int *)(iVar4 + 4) == 0x4a8) &&

            (((*(int *)(iVar4 + 0x18c) == 1 || (*(int *)(iVar4 + 0x18c) == *(int *)(iVar3 + 0x18c)))

             && (iVar4 != iVar7)))) && (iVar6 = lzo_assert(iVar4), iVar6 != 0)) break;

        puVar9 = (undefined4 *)*puVar9;

      }

      bldg_get_refpt_worldloc(iVar4,0,&local_1c);

      iVar7 = iVar4;

    }

    iVar4 = reaper_has_linked_smartie(iVar3);

    if (iVar4 != 0) {

      pcVar5 = (char *)TextGetPtr(s_AFlagHintTeleport_0055bc47 + 1);

      pcVar8 = &DAT_00632c10;

      do {

        cVar1 = *pcVar5;

        pcVar5 = pcVar5 + 1;

        *pcVar8 = cVar1;

        pcVar8 = pcVar8 + 1;

      } while (cVar1 != '\0');

      _DAT_00632d10 = 0x3f800000;

      return;

    }

    param_1 = *(undefined4 *)(iVar3 + 200);

    puVar9 = DAT_00632d9c;

    if (DAT_00632d9c != (undefined4 *)0x0) {

      while (((iVar4 = puVar9[3], *(int *)(iVar4 + 4) != 0x4a8 ||

              ((*(int *)(iVar4 + 0x18c) != 1 && (*(int *)(iVar4 + 0x18c) != *(int *)(iVar3 + 0x18c))

               ))) || ((iVar4 == iVar7 || (iVar6 = lzo_assert(iVar4), iVar6 == 0))))) {

        puVar9 = (undefined4 *)*puVar9;

        if (puVar9 == (undefined4 *)0x0) {

          return;

        }

      }

      bldg_get_refpt_worldlocdir(iVar4,1,&local_1c,&param_1);

      sound_play_player(0x6ea,iVar3);

      object_set_location_p3d(iVar3,&local_1c);

      *(int *)(iVar3 + 200) = param_1;

      playerobj_zap_movement(iVar3);

      iVar7 = reaper_0052e4a0(iVar3);

      if (iVar7 != 0) {

        local_4 = *(undefined4 *)(iVar3 + 200);

        local_10 = local_1c;

        local_c = local_18;

        local_8 = local_14;

        reaper_00530bd0(iVar3,4,0,0,0x37,&local_10);

      }

    }

  }

  return;

}

/* ===== reaper_replenish_basepit_energy__FP6OBJECT @ 0x004C5810 ===== */
/* PS2 candidate: reaper_replenish_basepit_energy__FP6OBJECT (conf 0.455) */



void reaper_replenish_basepit_energy__FP6OBJECT(float param_1)



{

  int iVar1;

  float fVar2;

  float fVar3;

  undefined1 uVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  float10 fVar8;

  float10 fVar9;

  undefined1 local_5c [4];

  float local_58;

  float local_54;

  float local_50;

  float local_4c;

  float local_48;

  float local_44;

  undefined1 local_40 [32];

  undefined4 local_20;

  undefined4 local_1c;

  

  fVar3 = param_1;

  iVar7 = *(int *)((int)param_1 + 0x100);

  iVar1 = *(int *)(iVar7 + 0xcfc);

  if (iVar1 != 0) {

    iVar5 = base_has_partyhouse(iVar1);

    if (iVar5 == 0) {

      iVar5 = base_get_base_building(iVar1);

      if (iVar1 != iVar5) {

        if (*(int *)(iVar7 + 0xcf4) != 0) {

          param_1 = *(float *)(iVar7 + 0xcf8) * 0.33333334;

          bldg_get_refpt_worldloc(iVar5,0x14,&local_58);

          bldg_get_refpt_worldloc(iVar5,0x55,&local_4c);

          fVar8 = (float10)1.0 - (float10)param_1;

          fVar9 = (float10)fsin((float10)DAT_006328e8 * (float10)5.0);

          object_set_location(*(undefined4 *)(iVar7 + 0xcf4),

                              (float)((float10)local_4c * (float10)param_1 +

                                     fVar8 * (float10)local_58),

                              (float)((float10)local_48 * (float10)param_1 +

                                     (float10)local_54 * fVar8),

                              (float)((float10)local_44 * (float10)param_1 +

                                      fVar8 * (float10)local_50 + fVar9 + (float10)3.0));

          fVar8 = (float10)FRateGetSecsframe(fVar3,0);

          fVar8 = fVar8 + (float10)*(float *)(iVar7 + 0xcf8);

          *(float *)(iVar7 + 0xcf8) = (float)fVar8;

          if ((float10)3.0 <= fVar8) {

            object_destroy(*(undefined4 *)(iVar7 + 0xcf4));

            *(undefined4 *)(iVar7 + 0xcf4) = 0;

          }

        }

        iVar6 = fx_create(fVar3);

        if ((iVar6 != 0) && (*(float *)(iVar7 + 0xcec) != 0.0)) {

          fVar8 = (float10)FRateGetSecsframe(fVar3,0);

          fVar8 = (float10)*(float *)(iVar7 + 0xcf0) - fVar8;

          *(float *)(iVar7 + 0xcf0) = (float)fVar8;

          if (fVar8 <= (float10)0.0) {

            fVar8 = (float10)bldg_get_energy(iVar1);

            param_1 = (float)fVar8;

            fVar8 = (float10)bldg_get_max_energy_dup00418170(iVar1);

            if (fVar8 < (float10)param_1 == (fVar8 == (float10)param_1)) {

              bldg_get_refpt_worldlocdir(iVar5,0x14,local_40,local_5c);

              fVar8 = (float10)distancesq2d__FP3P3DT0(local_40,(int)fVar3 + 0xa0);

              if (fVar8 <= (float10)9.0) {

                sound_play_player(0x3ce,fVar3);

                *(undefined4 *)(iVar7 + 0xcf0) = *(undefined4 *)(DAT_00632ed8 + 0x620);

                fVar2 = *(float *)(iVar7 + 0xcec) - 1.0;

                *(float *)(iVar7 + 0xcec) = fVar2;

                if (fVar2 < 0.0) {

                  *(undefined4 *)(iVar7 + 0xcec) = 0;

                }

                iVar5 = dialog_level_is_base_dup0052aa70();

                if (iVar5 == 0) {

                  fVar8 = (float10)1.0;

                }

                else {

                  fVar8 = (float10)kbos_food_value__Fi(DAT_00632f40);

                }

                obj_maxspeed_lookup(iVar1,(float)((float10)*(float *)(DAT_00632ed8 + 0x61c) * fVar8)

                                   );

                if (*(int *)(iVar7 + 0xcf4) == 0) {

                  local_1c = object_allocate_type(0x45d,0);

                  *(undefined4 *)(iVar7 + 0xcf4) = local_1c;

                  local_20 = 0xffffffff;

                  fx_get_free_effect__Fv();

                  *(undefined4 *)(*(int *)(iVar7 + 0xcf4) + 0xc4) = 0x3f000000;

                  *(uint *)(*(int *)(iVar7 + 0xcf4) + 0xd8) =

                       *(uint *)(*(int *)(iVar7 + 0xcf4) + 0xd8) | 0x40000000;

                }

                *(undefined4 *)(iVar7 + 0xcf8) = 0;

                iVar7 = reaper_0052e4a0(fVar3);

                if (iVar7 != 0) {

                  uVar4 = __ftol();

                  param_1 = (float)CONCAT31(param_1._1_3_,uVar4);

                  reaper_00530bd0(fVar3,0,0,1,0xe,&param_1);

                }

              }

            }

          }

        }

      }

    }

  }

  return;

}

/* ===== reaperbase_dock_check @ 0x004C5B10 ===== */
void reaperbase_dock_check(int param_1)



{

  int iVar1;

  int iVar2;

  float10 fVar3;

  float10 fVar4;

  undefined1 local_c [12];

  

  iVar2 = *(int *)(param_1 + 0x100);

  iVar1 = fx_create(param_1);

  if (((((iVar1 != 0) && (DAT_00632bb0 == 0)) && (DAT_00632ba8 == 0)) &&

      (*(int *)(iVar2 + 0xcfc) != 0)) &&

     (((*(int *)(param_1 + 0x210) == 0 ||

       (iVar1 = ObjIsJetski(*(int *)(param_1 + 0x210)), iVar1 == 0)) &&

      (iVar2 = base_slot9_get(*(undefined4 *)(iVar2 + 0xcfc)), iVar2 != 0)))) {

    bldg_get_refpt_worldloc(iVar2,0xc,local_c);

    fVar3 = (float10)distancesq3d(local_c,param_1 + 0xa0);

    fVar4 = (float10)distancesq3d(local_c,param_1 + 0xac);

    if (((float)fVar3 < 36.0 != ((float)fVar3 == 36.0)) && ((float10)36.0 < fVar4)) {

      mecc_bubble_show(param_1);

      return;

    }

  }

  return;

}

/* ===== reaper_lock_user_2 @ 0x004C5BF0 ===== */
void reaper_lock_user_2(int param_1)



{

  int iVar1;

  undefined4 *puVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  float10 fVar6;

  undefined1 local_c [12];

  

  iVar3 = param_1;

  iVar1 = *(int *)(param_1 + 0x100);

  iVar4 = fx_create(param_1);

  if (iVar4 != 0) {

    fVar6 = (float10)FRateGetSecsframe(0,0);

    fVar6 = (float10)*(float *)(iVar1 + 0xfb0) - fVar6;

    *(float *)(iVar1 + 0xfb0) = (float)fVar6;

    puVar2 = DAT_00632d68;

    if (fVar6 < (float10)0.0) {

      for (; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {

        iVar4 = puVar2[3];

        if ((*(int *)(iVar4 + 0x1e0) == 0x66) &&

           (((*(int *)(iVar4 + 0x18c) == *(int *)(iVar3 + 0x18c) || (*(int *)(iVar4 + 0x18c) == 0))

            && (*(float *)(iVar4 + 0x278) < *(float *)(iVar4 + 0x1c0))))) {

          bldg_get_refpt_worldloc(iVar4,0,local_c);

          fVar6 = (float10)distancesq3d(local_c,iVar3 + 0xa0);

          if (fVar6 < (float10)25.0 != (fVar6 == (float10)25.0)) {

            if ((*(byte *)(iVar3 + 0xe0) & 1) == 0) {

              iVar5 = reaper_0052e4a0(iVar3);

              if (iVar5 == 0) {

                iVar5 = fx_create(iVar3);

                if (iVar5 != 0) {

                  giftshopview_enable(0,iVar4);

                  fVar6 = (float10)tracer_entry_angle(iVar4,0);

                  *(float *)(iVar3 + 200) = (float)fVar6;

                  playerobj_eval_refpt(iVar3,0,(undefined4 *)(iVar3 + 0xa0));

                  object_set_location(iVar3,*(undefined4 *)(iVar3 + 0xa0),

                                      *(undefined4 *)(iVar3 + 0xa4),*(undefined4 *)(iVar3 + 0xa8));

                  *(undefined1 *)(iVar3 + 0x20a) = 0;

                  *(undefined1 *)(iVar3 + 0x20b) = 0;

                  *(undefined1 *)(iVar3 + 0x208) = 0;

                }

              }

              else {

                param_1 = *(undefined4 *)(iVar3 + 0x188);

                comm_chat_send_2(iVar4,0,1,0,1,&param_1);

                reaper_spell_big(iVar4,1,4,&param_1);

              }

            }

            goto LAB_004c5cb5;

          }

        }

      }

      *(uint *)(iVar3 + 0xe0) = *(uint *)(iVar3 + 0xe0) & 0xfffffffe;

LAB_004c5cb5:

      *(undefined4 *)(iVar1 + 0xfb0) = 0x3f000000;

    }

  }

  return;

}

/* ===== obj_release_carried_slot @ 0x004C5D80 ===== */
void obj_release_carried_slot(int param_1,int param_2,undefined4 param_3,int param_4)



{

  int iVar1;

  int iVar2;

  undefined1 local_c [12];

  

  iVar1 = *(int *)(param_1 + 0x100);

  iVar2 = fx_create(param_1);

  if ((iVar2 == 0) || (*(int *)(iVar1 + 0x5bc + param_4 * 4) == 0)) {

    giftshopview_enable(param_3,0);

    bldg_get_refpt_worldloc(param_3,param_4 * 2 + 0xb,local_c);

    object_set_location_p3d(param_2,local_c);

    *(undefined1 *)(param_2 + 0x20a) = 0;

    *(undefined1 *)(param_2 + 0x20b) = 0;

    *(undefined1 *)(param_2 + 0x208) = 0;

    if (iVar2 != 0) {

      *(undefined4 *)(iVar1 + 0x5bc + param_4 * 4) = *(undefined4 *)(param_2 + 0x188);

    }

  }

  return;

}

/* ===== ai_proximity_scan @ 0x004C5E10 ===== */
void ai_proximity_scan(int param_1)



{

  undefined4 uVar1;

  int iVar2;

  int iVar3;

  float10 fVar4;

  float10 fVar5;

  undefined1 local_18 [12];

  undefined1 local_c [12];

  

  iVar3 = *(int *)(param_1 + 0x100);

  if ((*(int *)(iVar3 + 0xcfc) != 0) && (iVar2 = fx_create(param_1), iVar2 != 0)) {

    uVar1 = *(undefined4 *)(iVar3 + 0xcfc);

    iVar3 = base_slot11_get(uVar1);

    if (iVar3 != 0) {

      bldg_get_refpt_worldloc(iVar3,0xb,local_18);

      if (*(int *)(iVar3 + 4) == 0x2e0) {

        bldg_get_refpt_worldloc(iVar3,0x11,local_c);

      }

      fVar4 = (float10)distancesq3d(local_18,param_1 + 0xa0);

      fVar5 = (float10)distancesq3d(local_18,param_1 + 0xac);

      if (((float)fVar4 < 36.0 == ((float)fVar4 == 36.0)) || (fVar5 <= (float10)36.0)) {

        if (*(int *)(iVar3 + 4) == 0x2e0) {

          fVar4 = (float10)distancesq3d(local_c,param_1 + 0xa0);

          fVar5 = (float10)distancesq3d(local_c,param_1 + 0xac);

          if (((float)fVar4 < 36.0 != ((float)fVar4 == 36.0)) && ((float10)36.0 < fVar5)) {

            iVar2 = fx_create(uVar1);

            if (iVar2 != 0) {

              obj_release_carried_slot(uVar1,param_1,iVar3,1);

              return;

            }

            iVar3 = dialog_level_is_base_dup0052aa70();

            if (iVar3 != 0) {

              reaper_state_check_e(uVar1,param_1,1);

              return;

            }

          }

        }

      }

      else {

        iVar2 = fx_create(uVar1);

        if (iVar2 != 0) {

          obj_release_carried_slot(uVar1,param_1,iVar3,0);

          return;

        }

        iVar3 = dialog_level_is_base_dup0052aa70();

        if (iVar3 != 0) {

          reaper_state_check_e(uVar1,param_1,0);

          return;

        }

      }

    }

  }

  return;

}

/* ===== reaper_lock_pair @ 0x004C5FB0 ===== */
void reaper_lock_pair(int param_1,int param_2)



{

  int iVar1;

  int iVar2;

  int iVar3;

  undefined4 local_10;

  undefined4 local_c;

  undefined4 local_8;

  undefined4 local_4;

  

  iVar1 = *(int *)(param_2 + 0x100);

  iVar2 = *(int *)(param_1 + 0x100);

  if (*(int *)(iVar2 + 0xfd4) == 0) {

    iVar3 = reaper_summon_spawn(param_1,(undefined4 *)(param_1 + 0xa0),0xffffffff);

    *(int *)(iVar2 + 0xfd4) = iVar3;

    if (iVar3 != 0) {

      iVar3 = reaper_0052e4a0(param_1);

      if (iVar3 != 0) {

        local_4 = *(undefined4 *)(*(int *)(iVar2 + 0xfd4) + 0x188);

        local_10 = *(undefined4 *)(param_1 + 0xa0);

        local_c = *(undefined4 *)(param_1 + 0xa4);

        local_8 = *(undefined4 *)(param_1 + 0xa8);

        reaper_00530bd0(param_1,3,1,0,0xb,&local_10);

      }

      *(uint *)(param_2 + 0xe0) = *(uint *)(param_2 + 0xe0) & 0xffffffdf;

      *(uint *)(param_2 + 0x1c8) = *(uint *)(param_2 + 0x1c8) & 0xfffdffff | 0x800;

      *(undefined4 *)(param_2 + 0xe4) = 0x13;

      *(undefined4 *)(iVar1 + 0x54) = 0;

      *(undefined4 *)(param_2 + 0xec) = 0;

    }

  }

  return;

}

/* ===== destroy_only_c3 @ 0x004C6090 ===== */
void destroy_only_c3(int param_1)



{

  int iVar1;

  int iVar2;

  

  iVar1 = *(int *)(param_1 + 0x100);

  iVar2 = *(int *)(iVar1 + 0xf90);

  if (iVar2 != 0) {

    object_destroy(iVar2);

  }

  iVar1 = *(int *)(iVar1 + 0x50);

  if (iVar1 != 0) {

    object_destroy(iVar1);

  }

  return;

}

/* ===== reaper_ptr_clear_c3 @ 0x004C60C0 ===== */
void reaper_ptr_clear_c3(int param_1)



{

  int iVar1;

  int iVar2;

  int iVar3;

  

  iVar1 = *(int *)(param_1 + 0x100);

  iVar3 = iVar1 + 0xdbc;

  iVar2 = 4;

  do {

    obj_ptr_clear_if_dead(iVar3);

    iVar3 = iVar3 + 0x1c;

    iVar2 = iVar2 + -1;

  } while (iVar2 != 0);

  iVar3 = 0;

  if (0 < *(int *)(iVar1 + 0xdac)) {

    iVar2 = iVar1 + 0xf60;

    do {

      obj_ptr_clear_if_dead(iVar2 + 0x14);

      obj_ptr_clear_if_dead(iVar2);

      iVar3 = iVar3 + 1;

      iVar2 = iVar2 + 4;

    } while (iVar3 < *(int *)(iVar1 + 0xdac));

  }

  obj_ptr_clear_if_dead(iVar1 + 0xf44);

  obj_ptr_clear_if_dead(iVar1 + 0xcf4);

  obj_ptr_clear_if_dead(iVar1 + 0xe80);

  obj_ptr_clear_if_dead(iVar1 + 0xea4);

  obj_ptr_clear_if_dead(iVar1 + 0xf28);

  obj_ptr_clear_if_dead(iVar1 + 8);

  obj_ptr_clear_if_dead(iVar1 + 0xcfc);

  obj_ptr_clear_if_dead(iVar1 + 0xf8c);

  obj_ptr_clear_if_dead(iVar1 + 0xf90);

  obj_ptr_clear_if_dead(iVar1 + 0xc);

  obj_ptr_clear_if_dead(iVar1 + 0x50);

  obj_ptr_clear_if_dead(iVar1 + 0xfd4);

  obj_ptr_clear_if_dead(iVar1 + 0xf48);

  return;

}

/* ===== fx_death_c85 @ 0x004C61C0 ===== */
void fx_death_c85(undefined4 param_1,undefined4 param_2,int param_3)



{

  char *pcVar1;

  undefined4 uVar2;

  undefined1 *puVar3;

  undefined1 auStack_34 [4];

  undefined4 uStack_30;

  undefined4 uStack_2c;

  undefined4 uStack_28;

  

  puVar3 = auStack_34;

  uStack_30 = *(undefined4 *)(param_3 + 0xa0);

  uStack_2c = *(undefined4 *)(param_3 + 0xa4);

  uStack_28 = *(undefined4 *)(param_3 + 0xa8);

  uVar2 = 8;

  pcVar1 = s_fx_mana_005562bc;

  fx_get_free_effect__Fv();

  object_destroy(param_3,pcVar1,uVar2,puVar3);

  return;

}

/* ===== destroy_only_c85 @ 0x004C6210 ===== */
void destroy_only_c85(int param_1)



{

  float10 fVar1;

  

  fVar1 = (float10)FRateGetSecsframe(param_1,0);

  fVar1 = (float10)*(float *)(param_1 + 0xf4) - fVar1;

  *(float *)(param_1 + 0xf4) = (float)fVar1;

  if (fVar1 < (float10)0.0 != (fVar1 == (float10)0.0)) {

    object_destroy(param_1);

    return;

  }

  if (*(int *)(param_1 + 0x274) != 0) {

    *(undefined4 *)(param_1 + 200) = *(undefined4 *)(*(int *)(param_1 + 0x274) + 200);

  }

  return;

}

/* ===== animloop_tick_c86 @ 0x004C6260 ===== */
void animloop_tick_c86(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)



{

  undefined4 uVar1;

  

  if (param_2 == 1) {

    uVar1 = objanim_select_animloop(*param_4);

    firewall_create_fire__FP6OBJECTT0Uifffi

              (param_1,uVar1,param_4[1],*(undefined4 *)(DAT_00632ed8 + 0x79c),

               *(undefined4 *)(DAT_00632ed8 + 0x794),*(undefined4 *)(DAT_00632ed8 + 0x798),0);

  }

  return;

}

/* ===== firewall_create_fire__FP6OBJECTT0Uifffi @ 0x004C62C0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void firewall_create_fire__FP6OBJECTT0Uifffi

               (int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,

               undefined4 param_6,int param_7)



{

  char cVar1;

  undefined4 *puVar2;

  int iVar3;

  int iVar4;

  char *pcVar5;

  char *pcVar6;

  undefined4 uVar7;

  undefined4 uVar8;

  undefined4 uVar9;

  undefined4 uVar10;

  undefined4 uVar11;

  undefined4 uVar12;

  undefined1 *puVar13;

  undefined4 uVar14;

  undefined4 local_3c;

  undefined4 local_38;

  undefined1 local_34 [20];

  undefined4 local_20;

  int local_1c;

  

  if (param_2 != 0) {

    iVar3 = object_allocate_type(0x374,0);

    object_change_ospec(iVar3,0x57);

    puVar2 = *(undefined4 **)(iVar3 + 0x100);

    *(undefined4 *)(iVar3 + 0x18c) = *(undefined4 *)(param_1 + 0x18c);

    *(undefined4 *)(iVar3 + 0x274) = *(undefined4 *)(param_1 + 0x274);

    iVar4 = fx_create(param_1);

    if (iVar4 == 0) {

      *(undefined4 *)(iVar3 + 0x188) = param_3;

    }

    *(int *)(iVar3 + 0x210) = param_2;

    *(undefined4 *)(iVar3 + 0x218) = 0xffffffff;

    *(undefined4 *)(iVar3 + 0x214) = 0xffffffff;

    *(uint *)(iVar3 + 0xd8) = *(uint *)(iVar3 + 0xd8) | 0x400000;

    *(uint *)(param_2 + 0xdc) = *(uint *)(param_2 + 0xdc) | 0x4000000;

    if (param_2 == DAT_00632a88) {

      pcVar5 = (char *)TextGetPtr(s_SpellHintFire_005610c8);

      pcVar6 = &DAT_00632c10;

      do {

        cVar1 = *pcVar5;

        pcVar5 = pcVar5 + 1;

        *pcVar6 = cVar1;

        pcVar6 = pcVar6 + 1;

      } while (cVar1 != '\0');

      _DAT_00632d10 = 0x40800000;

    }

    *(undefined4 *)(iVar3 + 0xec) = param_4;

    puVar13 = local_34;

    *(undefined4 *)(iVar3 + 0xf0) = 0;

    *(undefined4 *)(iVar3 + 0xf4) = param_6;

    *(undefined4 *)(iVar3 + 0xf8) = param_5;

    uVar11 = 4;

    pcVar5 = s_FXB_onfire_005610bc;

    local_20 = 0;

    local_1c = iVar3;

    fx_get_free_effect__Fv();

    iVar4 = ObjIsKabuto(param_2,pcVar5,uVar11,puVar13);

    if (iVar4 != 0) {

      sound_play_player(0x409,param_2);

    }

    uVar14 = 3;

    uVar12 = 0;

    uVar10 = 0x65c;

    uVar9 = 0;

    uVar8 = 0x65b;

    uVar7 = 0x65d;

    iVar4 = param_2;

    uVar11 = sound_get_free_sequence__Fv();

    *puVar2 = uVar11;

    iVar4 = reaper_0052e4a0(param_1,uVar7,uVar8,uVar9,uVar10,iVar4,uVar12,uVar14);

    if (iVar4 != 0) {

      local_38 = *(undefined4 *)(iVar3 + 0x188);

      local_3c = *(undefined4 *)(param_2 + 0x188);

      if (param_7 == 0) {

        uVar11 = 1;

      }

      else {

        uVar11 = 2;

      }

      reaper_00530bd0(param_1,0,2,0,uVar11,&local_3c);

    }

  }

  return;

}

/* ===== ground_patrol_ai_c86 @ 0x004C6450 ===== */
void ground_patrol_ai_c86(int param_1)



{

  undefined4 *puVar1;

  int iVar2;

  int iVar3;

  int *piVar4;

  float10 fVar5;

  float10 fVar6;

  undefined1 auStack_1c [16];

  float fStack_c;

  

  fVar5 = (float10)FRateGetSecsframe(param_1,0);

  fVar6 = (float10)*(float *)(param_1 + 0xec) - fVar5;

  *(float *)(param_1 + 0xec) = (float)fVar6;

  if (fVar6 < (float10)0.0 != (fVar6 == (float10)0.0)) {

    object_destroy(param_1);

    return;

  }

  puVar1 = (undefined4 *)(param_1 + 0xa0);

  *(undefined4 *)(param_1 + 0xac) = *puVar1;

  *(undefined4 *)(param_1 + 0xb0) = *(undefined4 *)(param_1 + 0xa4);

  *(undefined4 *)(param_1 + 0xb4) = *(undefined4 *)(param_1 + 0xa8);

  object_add_location(param_1,(float)(fVar5 * (float10)*(float *)(param_1 + 0xf4)),

                      (float)(fVar5 * (float10)*(float *)(param_1 + 0xf8)),0);

  ground_height_at(puVar1,auStack_1c);

  *(float *)(param_1 + 0xa8) = fStack_c;

  if (fStack_c < *(float *)(DAT_00632ed8 + 0x790)) {

    object_destroy(param_1);

  }

  iVar2 = fx_create(param_1);

  if (((iVar2 != 0) && (*(int *)(param_1 + 0xe0) == 0)) &&

     (piVar4 = DAT_00632d6c, DAT_00632d6c != (int *)0x0)) {

    while (((iVar2 = piVar4[3], *(int *)(iVar2 + 0x1e0) == 0x56 || (*(int *)(iVar2 + 8) == 0)) ||

           (((~*(uint *)(iVar2 + 0x1c8) >> 0x11 & 1) != 0 ||

             (*(uint *)(iVar2 + 0xd8) & 0x4000c000) != 0 ||

            (iVar3 = collide_line_bbox(0,param_1 + 0xac,puVar1,iVar2 + 0x27c), iVar3 == 0))))) {

      piVar4 = (int *)*piVar4;

      if (piVar4 == (int *)0x0) {

        return;

      }

    }

    if ((*(uint *)(iVar2 + 0xdc) & 0x4000000) != 0) {

      return;

    }

    iVar3 = dialog_level_is_base_dup0052aa70();

    if (((iVar3 == 0) || (DAT_00632f20 != 0)) ||

       (*(int *)(iVar2 + 0x18c) != *(int *)(param_1 + 0x18c))) {

      firewall_create_fire__FP6OBJECTT0Uifffi

                (param_1,iVar2,0xffffffff,*(undefined4 *)(DAT_00632ed8 + 0x79c),

                 *(undefined4 *)(DAT_00632ed8 + 0x794),*(undefined4 *)(DAT_00632ed8 + 0x798),0);

    }

    object_destroy(param_1);

    return;

  }

  return;

}

/* ===== reaperbase_attacker_ai_c87 @ 0x004C6610 ===== */
void reaperbase_attacker_ai_c87(int param_1)



{

  float fVar1;

  int iVar2;

  float10 fVar3;

  undefined4 uVar4;

  undefined4 uVar5;

  

  uVar5 = *(undefined4 *)(param_1 + 0x100);

  iVar2 = fx_create(*(undefined4 *)(param_1 + 0x210));

  if (iVar2 == 0) {

    fVar3 = (float10)FRateGetSecsframe(0,0);

    fVar3 = fVar3 + (float10)*(float *)(param_1 + 0xf0);

    *(float *)(param_1 + 0xf0) = (float)fVar3;

    if ((float10)60.0 < fVar3) {

      iVar2 = ObjIsKabuto(*(undefined4 *)(param_1 + 0x210));

      if (iVar2 != 0) {

        if (0.0 <= *(float *)(param_1 + 0xec)) {

          sound_play_player(0x408,*(undefined4 *)(param_1 + 0x210));

        }

        sound_stop_player(0x409,*(undefined4 *)(param_1 + 0x210));

      }

      sound_interrupt_sequence(uVar5);

      *(uint *)(*(int *)(param_1 + 0x210) + 0xdc) =

           *(uint *)(*(int *)(param_1 + 0x210) + 0xdc) & 0xfbffffff;

      object_destroy(param_1);

    }

    return;

  }

  fVar3 = (float10)FRateGetSecsframe(param_1,0);

  fVar1 = *(float *)(param_1 + 0xec) - (float)fVar3;

  *(float *)(param_1 + 0xec) = fVar1;

  if ((0.0 <= fVar1) && (*(float *)(DAT_00632ed8 + 0x790) <= *(float *)(param_1 + 0xa8))) {

    fVar1 = *(float *)(param_1 + 0xf0) - (float)fVar3;

    *(float *)(param_1 + 0xf0) = fVar1;

    if (fVar1 < 0.0 != (fVar1 == 0.0)) {

      iVar2 = ObjIsMeccBldg(*(undefined4 *)(param_1 + 0x210));

      if ((iVar2 == 0) && (iVar2 = ObjIsReaperBldg(*(undefined4 *)(param_1 + 0x210)), iVar2 == 0)) {

        uVar5 = *(undefined4 *)(param_1 + 0x210);

        uVar4 = *(undefined4 *)(param_1 + 0xf4);

      }

      else {

        uVar5 = *(undefined4 *)(param_1 + 0x210);

        uVar4 = 0x41400000;

      }

      obj_damage_apply(0xf,uVar4,uVar5,param_1,0,0);

      *(undefined4 *)(param_1 + 0xf0) = *(undefined4 *)(param_1 + 0xf8);

      return;

    }

    return;

  }

  iVar2 = ObjIsKabuto(*(undefined4 *)(param_1 + 0x210));

  if (iVar2 != 0) {

    if (0.0 <= *(float *)(param_1 + 0xec)) {

      sound_play_player(0x408,*(undefined4 *)(param_1 + 0x210));

    }

    sound_stop_player(0x409,*(undefined4 *)(param_1 + 0x210));

  }

  sound_interrupt_sequence(uVar5);

  *(uint *)(*(int *)(param_1 + 0x210) + 0xdc) =

       *(uint *)(*(int *)(param_1 + 0x210) + 0xdc) & 0xfbffffff;

  object_destroy(param_1);

  iVar2 = reaper_0052e4a0(*(undefined4 *)(param_1 + 0x210));

  if (iVar2 == 0) {

    return;

  }

  reaper_00530bd0(param_1,0,0,0,1,0);

  return;

}

/* ===== reaperbase_kabuto_watch_c87 @ 0x004C6840 ===== */
void reaperbase_kabuto_watch_c87(int param_1,int param_2)



{

  undefined4 uVar1;

  int iVar2;

  

  if (param_2 == 1) {

    uVar1 = *(undefined4 *)(param_1 + 0x100);

    iVar2 = ObjIsKabuto(*(undefined4 *)(param_1 + 0x210));

    if (iVar2 != 0) {

      if (0.0 <= *(float *)(param_1 + 0xec)) {

        sound_play_player(0x408,*(undefined4 *)(param_1 + 0x210));

      }

      sound_stop_player(0x409,*(undefined4 *)(param_1 + 0x210));

    }

    sound_interrupt_sequence(uVar1);

    *(uint *)(*(int *)(param_1 + 0x210) + 0xdc) =

         *(uint *)(*(int *)(param_1 + 0x210) + 0xdc) & 0xfbffffff;

    object_destroy(param_1);

  }

  return;

}

/* ===== reaperbase_death_handler_c88 @ 0x004C68D0 ===== */
void reaperbase_death_handler_c88

               (int param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)



{

  int *piVar1;

  uint *puVar2;

  int iVar3;

  undefined4 uVar4;

  int iVar5;

  

  switch(param_2) {

  case 1:

    fxn_firering(param_1);

    return;

  case 2:

    uVar4 = objanim_select_animloop(*param_4);

    firewall_create_fire__FP6OBJECTT0Uifffi

              (param_1,uVar4,param_4[1],*(undefined4 *)(DAT_00632ed8 + 0x6bc),

               *(undefined4 *)(DAT_00632ed8 + 0x6c0),*(undefined4 *)(DAT_00632ed8 + 0x6c4),1);

    return;

  case 3:

    type58_death_cleanup(param_1);

  case 5:

    piVar1 = *(int **)(param_1 + 0x100);

    if (piVar1[1] != 0) {

      object_destroy(piVar1[1]);

    }

    piVar1[1] = 0;

    if (*piVar1 != 0) {

      sound_stop_sequence(piVar1 + 3);

      fx_anchor_toggle_ops(*piVar1);

      *piVar1 = 0;

    }

    iVar5 = ObjIsReaper(*(undefined4 *)(param_1 + 0x274));

    if (iVar5 != 0) {

      puVar2 = *(uint **)(*(int *)(param_1 + 0x274) + 0x100);

      *puVar2 = *puVar2 & 0xfffffffb;

      object_destroy(param_1);

      return;

    }

    break;

  case 4:

    iVar5 = *(int *)(param_1 + 0x100);

    iVar3 = *(int *)(iVar5 + 8);

    if (iVar3 != 0) {

      fx_delete(iVar3);

    }

    *(undefined4 *)(iVar5 + 8) = 0;

    iVar5 = ObjIsReaper(*(undefined4 *)(param_1 + 0x274));

    if (iVar5 != 0) {

      puVar2 = *(uint **)(*(int *)(param_1 + 0x274) + 0x100);

      *puVar2 = *puVar2 & 0xfffffffb;

    }

    break;

  default:

    goto code_r0x004c6a0a;

  }

  object_destroy(param_1);

code_r0x004c6a0a:

  return;

}

/* ===== fxn_firering @ 0x004C6A30 ===== */
/* PS2 candidate: reaper_firecircle_detonate__FP6OBJECT (conf 0.375) */



void fxn_firering(int param_1)



{

  undefined4 *puVar1;

  uint *puVar2;

  undefined4 uVar3;

  int iVar4;

  char *pcVar5;

  undefined4 uVar6;

  undefined1 *puVar7;

  undefined1 local_34 [4];

  undefined4 local_30;

  undefined4 local_2c;

  undefined4 local_28;

  undefined4 local_24;

  

  local_30 = *(undefined4 *)(param_1 + 0xa0);

  local_2c = *(undefined4 *)(param_1 + 0xa4);

  local_28 = *(undefined4 *)(param_1 + 0xa8);

  puVar1 = *(undefined4 **)(param_1 + 0x100);

  puVar7 = local_34;

  uVar6 = 0x28;

  pcVar5 = s_FXN_firering_005610d8;

  local_24 = 8;

  uVar3 = fx_get_free_effect__Fv();

  puVar1[2] = uVar3;

  iVar4 = reaper_0052e4a0(param_1,pcVar5,uVar6,puVar7);

  if (iVar4 != 0) {

    reaper_00530bd0(param_1,0,0,0,1,0);

  }

  fx_anchor_toggle_ops(*puVar1);

  *puVar1 = 0;

  object_destroy(puVar1[1]);

  *(undefined4 *)(param_1 + 0xe0) = 1;

  *(undefined4 *)(param_1 + 0xfc) = 0x40800000;

  iVar4 = ObjIsReaper(*(undefined4 *)(param_1 + 0x274));

  if (iVar4 != 0) {

    puVar2 = *(uint **)(*(int *)(param_1 + 0x274) + 0x100);

    *puVar2 = *puVar2 | 4;

    sound_interrupt_sequence(puVar1 + 3);

    return;

  }

  *(uint *)(*(int *)(param_1 + 0x274) + 0xe0) = *(uint *)(*(int *)(param_1 + 0x274) + 0xe0) | 0x40;

  sound_interrupt_sequence(puVar1 + 3);

  return;

}

/* ===== reaperbase_firecircle_ai_c88 @ 0x004C6B20 ===== */
void reaperbase_firecircle_ai_c88(int param_1)



{

  uint *puVar1;

  undefined4 *puVar2;

  float fVar3;

  int iVar4;

  int iVar5;

  int *piVar6;

  float10 fVar7;

  undefined4 uStack_c;

  undefined4 uStack_8;

  undefined4 uStack_4;

  

  if (*(int *)(param_1 + 0xe0) == 0) {

    if (*(int *)(param_1 + 0x274) == 0) {

      *(undefined4 *)(param_1 + 0xec) = 0;

    }

    fVar7 = (float10)FRateGetSecsframe(param_1,0);

    fVar7 = (float10)*(float *)(param_1 + 0xec) - fVar7;

    *(float *)(param_1 + 0xec) = (float)fVar7;

    if (fVar7 < (float10)0.0) {

      puVar2 = *(undefined4 **)(param_1 + 0x100);

      sound_stop_sequence(puVar2 + 3);

      fx_anchor_toggle_ops(*puVar2);

      *puVar2 = 0;

      iVar4 = fx_create(param_1);

      if (iVar4 != 0) {

        iVar4 = reaper_0052e4a0(param_1);

        if (iVar4 != 0) {

          reaper_00530bd0(param_1,0,0,0,5,0);

        }

        object_destroy(puVar2[1]);

        object_destroy(param_1);

        return;

      }

      if (puVar2[1] != 0) {

        puVar1 = (uint *)(puVar2[1] + 0xd8);

        *puVar1 = *puVar1 | 0x40000000;

      }

      *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) | 0x40000000;

      return;

    }

    iVar4 = fx_create(param_1);

    if ((iVar4 != 0) &&

       (fVar7 = (float10)distancesq3d(*(int *)(param_1 + 0x274) + 0xa0,param_1 + 0xa0),

       fVar7 < (float10)*(float *)(DAT_00632ed8 + 0x838) * (float10)*(float *)(DAT_00632ed8 + 0x838)

       )) {

      fxn_firering(param_1);

      return;

    }

  }

  else {

    iVar4 = *(int *)(param_1 + 0x100);

    iVar5 = fx_create(param_1);

    if (iVar5 == 0) {

      fVar7 = (float10)FRateGetSecsframe(param_1,0);

      fVar7 = (float10)*(float *)(param_1 + 0xfc) - fVar7;

      *(float *)(param_1 + 0xfc) = (float)fVar7;

      if (fVar7 < (float10)0.0 != (fVar7 == (float10)0.0)) {

        if (*(int *)(iVar4 + 8) != 0) {

          fx_delete(*(int *)(iVar4 + 8));

        }

        *(undefined4 *)(iVar4 + 8) = 0;

        *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) | 0x40000000;

      }

    }

    else {

      puVar2 = DAT_00632da0;

      while( true ) {

        if (puVar2 == (undefined4 *)0x0) {

          if (*(int *)(param_1 + 0xf4) == 0x3f800000) {

            if (*(int *)(param_1 + 0x274) != 0) {

              iVar5 = ObjIsReaper(*(int *)(param_1 + 0x274));

              if (iVar5 == 0) {

                puVar1 = (uint *)(*(int *)(param_1 + 0x274) + 0xe0);

                *puVar1 = *puVar1 & 0xffffffbf;

              }

              else {

                puVar1 = *(uint **)(*(int *)(param_1 + 0x274) + 0x100);

                *puVar1 = *puVar1 & 0xfffffffb;

              }

            }

            iVar5 = reaper_0052e4a0(param_1);

            if (iVar5 != 0) {

              reaper_00530bd0(param_1,0,0,0,4,0);

            }

            object_destroy(param_1);

            fx_delete(*(undefined4 *)(iVar4 + 8));

            return;

          }

          *(undefined4 *)(param_1 + 0xf4) = 0x3f800000;

          return;

        }

        iVar5 = puVar2[3];

        if (**(int **)(iVar5 + 0x100) == *(int *)(iVar4 + 8) + 8) break;

        puVar2 = (undefined4 *)*puVar2;

      }

      fVar7 = (float10)FRateGetSecsframe(param_1,0);

      fVar7 = (float10)*(float *)(param_1 + 0xfc) - fVar7;

      *(float *)(param_1 + 0xfc) = (float)fVar7;

      if (fVar7 < (float10)0.0 != (fVar7 == (float10)0.0)) {

        if (*(int *)(param_1 + 0x274) != 0) {

          iVar5 = ObjIsReaper(*(int *)(param_1 + 0x274));

          if (iVar5 == 0) {

            puVar1 = (uint *)(*(int *)(param_1 + 0x274) + 0xe0);

            *puVar1 = *puVar1 & 0xffffffbf;

          }

          else {

            puVar1 = *(uint **)(*(int *)(param_1 + 0x274) + 0x100);

            *puVar1 = *puVar1 & 0xfffffffb;

          }

        }

        iVar5 = reaper_0052e4a0(param_1);

        if (iVar5 != 0) {

          reaper_00530bd0(param_1,0,0,0,4,0);

        }

        fx_delete(*(undefined4 *)(iVar4 + 8));

        object_destroy(param_1);

        return;

      }

      fVar3 = *(float *)(iVar5 + 0xc4) * 0.5;

      uStack_c = *(undefined4 *)(iVar5 + 0xa0);

      uStack_8 = *(undefined4 *)(iVar5 + 0xa4);

      uStack_4 = *(undefined4 *)(iVar5 + 0xa8);

      piVar6 = DAT_00632d6c;

      if (DAT_00632d6c != (int *)0x0) {

        do {

          iVar4 = piVar6[3];

          if (((((*(int *)(iVar4 + 0x18c) != *(int *)(param_1 + 0x18c)) &&

                (iVar5 = *(int *)(iVar4 + 0x1e0), iVar5 != 0x56)) && (iVar5 != 0x58)) &&

              ((iVar5 != 0x4e &&

               ((~*(uint *)(iVar4 + 0x1c8) >> 0x11 & 1) == 0 &&

                (*(uint *)(iVar4 + 0xd8) & 0x4000c000) == 0)))) &&

             (((*(uint *)(iVar4 + 0xdc) & 0x4000000) == 0 &&

              ((((iVar5 = dialog_level_is_base_dup0052aa70(), iVar5 == 0 || (DAT_00632f20 != 0)) ||

                (*(int *)(iVar4 + 0x18c) != *(int *)(param_1 + 0x18c))) &&

               (fVar7 = (float10)distancesq3d(&uStack_c,iVar4 + 0xa0),

               fVar7 <= (float10)fVar3 * (float10)fVar3)))))) {

            firewall_create_fire__FP6OBJECTT0Uifffi

                      (param_1,iVar4,0xffffffff,*(undefined4 *)(DAT_00632ed8 + 0x6bc),

                       *(undefined4 *)(DAT_00632ed8 + 0x6c0),*(undefined4 *)(DAT_00632ed8 + 0x6c4),1

                      );

          }

          piVar6 = (int *)*piVar6;

        } while (piVar6 != (int *)0x0);

        return;

      }

    }

  }

  return;

}

/* ===== ret_const_x10_c25 @ 0x004C6F30 ===== */
undefined4 ret_const_x10_c25(void)



{

  return 0x10;

}

/* ===== type58_death_cleanup @ 0x004C6F40 ===== */
void type58_death_cleanup(int param_1)



{

  uint *puVar1;

  int *piVar2;

  int iVar3;

  undefined4 *puVar4;

  

  if (*(int *)(param_1 + 0xe0) == 0) {

    if (-1 < (char)((uint)*(undefined4 *)(param_1 + 0xd8) >> 8)) {

      piVar2 = *(int **)(param_1 + 0x100);

      if (*(int *)(param_1 + 0x1e0) != 0x58) {

        return;

      }

      if (piVar2 == (int *)0x0) {

        return;

      }

      iVar3 = *piVar2;

      for (puVar4 = DAT_00632da0; puVar4 != (undefined4 *)0x0; puVar4 = (undefined4 *)*puVar4) {

        if (**(int **)(puVar4[3] + 0x100) == iVar3 + 8) {

          puVar1 = (uint *)(puVar4[3] + 0x1c8);

          *puVar1 = *puVar1 & 0xfffdffff;

        }

      }

      fx_anchor_toggle_ops(*piVar2);

      *piVar2 = 0;

      sound_stop_sequence(piVar2 + 3);

      object_destroy(piVar2[1]);

      object_destroy(param_1);

    }

    *(undefined4 *)(param_1 + 0xe0) = 2;

  }

  return;

}

/* ===== bldg_power_drain_ai_c40 @ 0x004C7020 ===== */
void bldg_power_drain_ai_c40(int param_1)



{

  float fVar1;

  undefined4 *puVar2;

  bool bVar3;

  int iVar4;

  int iVar5;

  float10 fVar6;

  float10 fVar7;

  

  iVar4 = fx_create(param_1);

  if (iVar4 != 0) {

    if (*(int *)(param_1 + 0xe4) == 0) {

      *(undefined4 *)(param_1 + 0xe4) = 1;

      *(undefined4 *)(param_1 + 0xec) = *(undefined4 *)(DAT_00632ed8 + 0x138c);

      if (*(int *)(param_1 + 0x274) != 0) {

        *(undefined4 *)(param_1 + 0xe0) = 1;

      }

      *(undefined4 *)(param_1 + 0xf0) = *(undefined4 *)(DAT_00632ed8 + 0xfb0);

      return;

    }

    if ((*(int *)(param_1 + 0xe0) != 0) && (*(int *)(param_1 + 0x274) == 0)) {

      iVar4 = reaper_0052e4a0(param_1);

      if (iVar4 != 0) {

        reaper_00530bd0(param_1,0,0,0,1,0);

      }

      object_destroy(param_1);

      return;

    }

    bVar3 = false;

    fVar6 = (float10)FRateGetSecsframe(param_1,0);

    *(float *)(param_1 + 0xf0) = (float)((float10)*(float *)(param_1 + 0xf0) - fVar6);

    for (puVar2 = DAT_00632d6c; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {

      iVar4 = puVar2[3];

      iVar5 = ObjIsReaperBldg(iVar4);

      if ((iVar5 == 0) && (iVar5 = ObjIsMeccBldg(iVar4), iVar5 == 0)) {

        if (((0.0 < *(float *)(iVar4 + 0x278)) &&

            (*(float *)(iVar4 + 0x278) < *(float *)(iVar4 + 0x1c0))) &&

           (fVar1 = *(float *)(DAT_00632ed8 + 0x1398),

           fVar6 = (float10)distancesq3d(iVar4 + 0xa0,param_1 + 0xa0),

           fVar6 < (float10)fVar1 * (float10)fVar1)) {

          if ((*(float *)(param_1 + 0xf0) < 0.0 != (*(float *)(param_1 + 0xf0) == 0.0)) &&

             (fVar1 = *(float *)(iVar4 + 0x278),

             obj_damage_apply(0x12,-*(float *)(DAT_00632ed8 + 0x1394) -

                                   -(*(float *)(DAT_00632ed8 + 0x1394) * *(float *)(param_1 + 0xf0))

                              ,iVar4,0,0,0), *(float *)(iVar4 + 0x278) < fVar1)) {

            bVar3 = true;

          }

          if (*(float *)(iVar4 + 0x278) < 0.0) {

            *(undefined4 *)(iVar4 + 0x278) = 0;

          }

        }

      }

      else {

        iVar5 = ObjIsReaperBldg(iVar4);

        if (iVar5 == 0) {

          fVar6 = (float10)meccbase_get_max_energy(iVar4);

        }

        else {

          fVar6 = (float10)reaperbase_get_max_energy();

        }

        fVar7 = (float10)bldg_get_energy(iVar4);

        if ((fVar7 < (float10)(float)fVar6) &&

           ((*(int *)(param_1 + 0x274) == iVar4 ||

            (fVar1 = *(float *)(DAT_00632ed8 + 0x1398),

            fVar6 = (float10)distancesq3d(iVar4 + 0xa0,param_1 + 0xa0),

            fVar6 < (float10)fVar1 * (float10)fVar1)))) {

          if (*(float *)(param_1 + 0xf0) < 0.0 != (*(float *)(param_1 + 0xf0) == 0.0)) {

            obj_damage_apply(0x12,-*(float *)(DAT_00632ed8 + 0x1390) -

                                  -(*(float *)(DAT_00632ed8 + 0x1390) * *(float *)(param_1 + 0xf0)),

                             iVar4,0,0,0);

          }

          fVar6 = (float10)bldg_get_energy(iVar4);

          if (fVar6 != (float10)(float)fVar7) {

            bVar3 = true;

          }

        }

      }

    }

    if (*(float *)(param_1 + 0xf0) < 0.0 != (*(float *)(param_1 + 0xf0) == 0.0)) {

      do {

        fVar1 = *(float *)(DAT_00632ed8 + 0xfb0) + *(float *)(param_1 + 0xf0);

        *(float *)(param_1 + 0xf0) = fVar1;

      } while (fVar1 < 0.0 != (fVar1 == 0.0));

    }

    if (bVar3) {

      *(undefined4 *)(param_1 + 0xec) = *(undefined4 *)(DAT_00632ed8 + 0x138c);

    }

    else {

      fVar6 = (float10)FRateGetSecsframe(param_1,0);

      fVar6 = (float10)*(float *)(param_1 + 0xec) - fVar6;

      *(float *)(param_1 + 0xec) = (float)fVar6;

      if (fVar6 < (float10)0.0 != (fVar6 == (float10)0.0)) {

        iVar4 = reaper_0052e4a0(param_1);

        if (iVar4 != 0) {

          reaper_00530bd0(param_1,0,0,0,1,0);

        }

        object_destroy(param_1);

        return;

      }

    }

  }

  return;

}

/* ===== death_destroy_c40 @ 0x004C73A0 ===== */
void death_destroy_c40(undefined4 param_1,int param_2)



{

  if (param_2 == 1) {

    object_destroy(param_1);

  }

  return;

}

/* ===== obj_snap_variant_c @ 0x004C73C0 ===== */
void obj_snap_variant_c(int param_1)



{

  int iVar1;

  undefined4 *puVar2;

  int iVar3;

  float *pfVar4;

  int iVar5;

  float fVar6;

  int iVar7;

  int iVar8;

  float10 fVar9;

  

  iVar5 = *(int *)(param_1 + 0x100);

  if ((*(uint *)(param_1 + 0xe0) & 0x100) == 0) {

    return;

  }

  iVar1 = iVar5 + 0x6c;

  if ((DAT_00632a88 == param_1) && (DAT_00632bb4 != 0)) goto LAB_004c75eb;

  if (*(float *)(param_1 + 200) < 360.0) {

    if (*(float *)(param_1 + 200) < 0.0) {

      fVar6 = *(float *)(param_1 + 200) + 360.0;

      goto LAB_004c742f;

    }

  }

  else {

    fVar6 = *(float *)(param_1 + 200) - 360.0;

LAB_004c742f:

    *(float *)(param_1 + 200) = fVar6;

  }

  if (*(int *)(iVar5 + 0x68) == -1) {

    *(undefined4 *)(iVar5 + 0x68) = 0;

    do {

      puVar2 = (undefined4 *)(iVar1 + *(int *)(iVar5 + 0x68) * 0x28);

      *puVar2 = *(undefined4 *)(param_1 + 0xa0);

      puVar2[1] = *(undefined4 *)(param_1 + 0xa4);

      puVar2[2] = *(undefined4 *)(param_1 + 0xa8);

      puVar2[3] = *(undefined4 *)(param_1 + 200);

      puVar2[4] = *(undefined4 *)(param_1 + 0x10);

      puVar2[5] = *(undefined4 *)(param_1 + 0x14);

      puVar2[6] = *(undefined4 *)(param_1 + 0x2c);

      puVar2[7] = *(undefined4 *)(param_1 + 0x58);

      puVar2[8] = *(undefined4 *)(param_1 + 0x5c);

      *(float *)(iVar5 + 0x90 + *(int *)(iVar5 + 0x68) * 0x28) =

           (float)*(int *)(iVar5 + 0x68) * 0.025;

      iVar7 = *(int *)(iVar5 + 0x68) + 1;

      *(int *)(iVar5 + 0x68) = iVar7;

    } while (iVar7 < 0x50);

    *(undefined4 *)(iVar5 + 0x68) = 0x4f;

LAB_004c74bd:

    iVar8 = *(int *)(iVar5 + 0x68);

    iVar7 = iVar5 + 0x44 + iVar8 * 0x28;

  }

  else {

    if (*(int *)(iVar5 + 0x68) != 0) goto LAB_004c74bd;

    iVar7 = iVar5 + 0xcc4;

    iVar8 = 0;

  }

  iVar3 = iVar1 + iVar8 * 0x28;

  if (*(float *)(iVar5 + 0x90 + iVar8 * 0x28) - *(float *)(iVar7 + 0x24) < 0.025) {

    fillin_snap__FP6OBJECTP8TimeSnap(param_1,iVar3);

    pfVar4 = (float *)(iVar5 + 0x90 + *(int *)(iVar5 + 0x68) * 0x28);

    fVar9 = (float10)FRateGetSecsframe(param_1,0);

    *pfVar4 = (float)(fVar9 + (float10)*pfVar4);

    puVar2 = DAT_00632d74;

  }

  else {

    fVar6 = *(float *)(iVar3 + 0x24);

    *(int *)(iVar5 + 0x68) = iVar8 + 1;

    if (0x4f < iVar8 + 1) {

      *(undefined4 *)(iVar5 + 0x68) = 0;

    }

    puVar2 = (undefined4 *)(iVar1 + *(int *)(iVar5 + 0x68) * 0x28);

    *puVar2 = *(undefined4 *)(param_1 + 0xa0);

    puVar2[1] = *(undefined4 *)(param_1 + 0xa4);

    puVar2[2] = *(undefined4 *)(param_1 + 0xa8);

    puVar2[3] = *(undefined4 *)(param_1 + 200);

    puVar2[4] = *(undefined4 *)(param_1 + 0x10);

    puVar2[5] = *(undefined4 *)(param_1 + 0x14);

    puVar2[6] = *(undefined4 *)(param_1 + 0x2c);

    puVar2[7] = *(undefined4 *)(param_1 + 0x58);

    puVar2[8] = *(undefined4 *)(param_1 + 0x5c);

    fVar9 = (float10)FRateGetSecsframe(param_1,0);

    *(float *)(iVar5 + 0x90 + *(int *)(iVar5 + 0x68) * 0x28) = (float)(fVar9 + (float10)fVar6);

    puVar2 = DAT_00632d74;

  }

  for (; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {

    iVar7 = puVar2[3];

    if ((*(int *)(iVar7 + 0x1e0) == 0x3e) && (*(int *)(iVar7 + 0x274) == param_1)) {

      reaper_set_trail__FP6OBJECTT0fiiP8TimeSnap

                (param_1,iVar7,

                 (float)(*(int *)(iVar7 + 0x174) + 1) * *(float *)(DAT_00632ed8 + 0x500),0,

                 *(undefined4 *)(iVar5 + 0x68),iVar1);

    }

  }

LAB_004c75eb:

  *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xfffffeff;

  return;

}

/* ===== evilreaper_ai_main_c99 @ 0x004C7610 ===== */
void evilreaper_ai_main_c99(OBJECT *param_1)



{

  float *pfVar1;

  undefined1 *puVar2;

  uint *puVar3;

  undefined4 *puVar4;

  float fVar5;

  dword dVar6;

  int iVar7;

  int iVar8;

  undefined1 uVar9;

  undefined4 uVar10;

  int iVar11;

  uint uVar12;

  int iVar13;

  int *piVar14;

  float *pfVar15;

  dword dVar16;

  int iVar17;

  dword dVar18;

  byte bVar19;

  float10 fVar20;

  OBJECT *pOVar21;

  undefined4 uVar22;

  undefined4 uVar23;

  undefined4 uVar24;

  undefined4 uVar25;

  float fVar26;

  undefined4 uVar27;

  undefined4 uVar28;

  float *pfStack_5c;

  float fStack_58;

  float fStack_54;

  undefined4 uStack_50;

  undefined4 uStack_4c;

  float fStack_48;

  float fStack_44;

  float fStack_40;

  float fStack_3c;

  undefined1 auStack_34 [16];

  float fStack_24;

  undefined4 uStack_20;

  OBJECT *pOStack_1c;

  

  dVar6 = param_1->animate_state;

  if (DAT_00632e74 != 0) {

    return;

  }

  if (*(int *)&param_1->field_0x210 != 0) {

    iVar11 = *(int *)(*(int *)&param_1->field_0x210 + 0x1e0);

    if (iVar11 == 1) {

      return;

    }

    if (iVar11 == 0x4c) {

      return;

    }

  }

  if (param_1->pad_E4 == 0) {

    param_1->ai_state_b = 100;

    *(undefined4 *)(dVar6 + 0xddc) = 0x41200000;

    fVar20 = (float10)get_floor_z_point(&param_1->field_0xa0);

    *(float *)&param_1->field_0xa8 = (float)fVar20;

    object_copy_posdirinfo(param_1);

    param_1->pad_104 = dVar6;

    PhysicsExZeroForce(param_1);

    *(undefined4 *)(param_1->pad_104 + 4) = *(undefined4 *)(DAT_00632ed8 + 0xe9c);

    *(undefined4 *)(param_1->pad_104 + 8) = *(undefined4 *)(DAT_00632ed8 + 0xea0);

    *(undefined4 *)(param_1->pad_104 + 0x28) = *(undefined4 *)(DAT_00632ed8 + 0xea4);

    *(undefined4 *)(param_1->pad_104 + 0xc) = *(undefined4 *)(DAT_00632ed8 + 0xea8);

    *(undefined4 *)(param_1->pad_104 + 0x30) = *(undefined4 *)(DAT_00632ed8 + 0xeac);

    *(undefined4 *)(param_1->pad_104 + 0x34) = *(undefined4 *)(DAT_00632ed8 + 0xeb0);

    *(undefined4 *)(param_1->pad_104 + 0x38) = *(undefined4 *)(DAT_00632ed8 + 0xeb4);

    param_1->pad_190 = *(dword *)(DAT_00632ed8 + 0xeb8);

    *(undefined4 *)&param_1->field_0x194 = *(undefined4 *)(DAT_00632ed8 + 0xebc);

    *(undefined4 *)&param_1->field_0x1a0 = *(undefined4 *)(DAT_00632ed8 + 0xec0);

    uVar10 = object_spawn_small(param_1,0x1e,0,1,0);

    *(undefined4 *)(dVar6 + 0xa8) = uVar10;

    iVar11 = object_spawn_small(param_1,0x29d,0,1,0);

    *(int *)(dVar6 + 0xac) = iVar11;

    *(uint *)(iVar11 + 0xd8) = *(uint *)(iVar11 + 0xd8) | 0x40000000;

    reaper_init_trails(param_1,dVar6 + 0xb8);

    param_1->pad_E4 = 10;

    pOStack_1c = param_1;

    uStack_20 = 9;

    fx_get_free_effect__Fv();

    return;

  }

  if ((param_1->flags & 0x800) == 0) {

    if ((param_1->anim == 0x89) && (iVar11 = *(int *)(dVar6 + 0xb4), iVar11 != 0x89)) {

      ObjectSetAnim(param_1);

      *(int *)(dVar6 + 0xb4) = iVar11;

    }

  }

  else {

    dVar16 = param_1->anim;

    if ((((dVar16 == 1) || (dVar16 == 0x35)) || (dVar16 == 0x5c)) &&

       (*(dword *)(dVar6 + 0xb4) = dVar16, param_1->anim != 0x89)) {

      ObjectSetAnim(param_1);

    }

  }

  iVar11 = *(int *)(dVar6 + 0x3c);

  *(undefined4 *)(dVar6 + 0x4c) = *(undefined4 *)&param_1->field_0xc8;

  if (iVar11 != 0) {

    *(undefined4 *)(dVar6 + 0x40) = *(undefined4 *)(iVar11 + 0xa0);

    *(undefined4 *)(dVar6 + 0x44) = *(undefined4 *)(iVar11 + 0xa4);

    *(undefined4 *)(dVar6 + 0x48) = *(undefined4 *)(iVar11 + 0xa8);

    fVar20 = (float10)distancesq3d(&param_1->field_0xa0,(undefined4 *)(iVar11 + 0xa0));

    *(float *)(dVar6 + 0x50) = (float)fVar20;

  }

  fVar20 = (float10)FRateGetSecsframe(param_1,0);

  fVar26 = (float)fVar20;

  *(float *)(dVar6 + 0xa0) = *(float *)(dVar6 + 0xa0) - fVar26;

  *(float *)(dVar6 + 0xa4) = *(float *)(dVar6 + 0xa4) - fVar26;

  *(float *)(dVar6 + 0x68) = *(float *)(dVar6 + 0x68) - fVar26;

  *(float *)(dVar6 + 0xddc) = *(float *)(dVar6 + 0xddc) - fVar26;

  param_1->field_0x208 = 0;

  param_1->field_0x20b = 0;

  param_1->field_0x20a = 0;

  param_1->flags = param_1->flags & 0xfcffffff;

  switch(param_1->pad_E4) {

  case 0xb:

    fVar5 = *(float *)&param_1->field_0xec - fVar26;

    *(float *)&param_1->field_0xec = fVar5;

    bVar19 = fVar5 < 0.0 | (byte)((ushort)((ushort)NAN(fVar5) << 10) >> 8);

    goto LAB_004c79af;

  case 0xc:

    evilreaper_verify_enemy__FP6OBJECTf(param_1,*(undefined4 *)(DAT_00632ed8 + 0xe98));

    if (*(int *)(dVar6 + 0x3c) == 0) {

      param_1->pad_E4 = 0x3c;

      break;

    }

    dVar16 = param_1->animate_state;

    if (*(float *)(dVar16 + 0xa4) < 0.0 == (*(float *)(dVar16 + 0xa4) == 0.0)) {

LAB_004c8331:

      if (*(float *)(dVar6 + 0xa0) <= 0.0) {

        if (*(int *)&param_1->field_0xe8 == 2) {

          sound_obj_seq_bigger(param_1);

        }

        else if ((*(float *)(dVar6 + 0x50) <

                  *(float *)(DAT_00632ed8 + 0xe30) * *(float *)(DAT_00632ed8 + 0xe30)) ||

                (iVar11 = crt_rand_scaled(100), *(int *)(DAT_00632ed8 + 0xe74) <= iVar11)) {

          sound_obj_seq_big(param_1);

        }

        else {

          sound_obj_seq_bigger(param_1);

        }

      }

      else {

        dVar16 = param_1->animate_state;

        if (param_1->anim != 1) {

          ObjectSetAnim(param_1);

          *(undefined4 *)(dVar16 + 0xb4) = 1;

        }

        fVar20 = (float10)dirfcalcp3d__FP3P3DT0(&param_1->field_0xa0,*(int *)(dVar6 + 0x3c) + 0xa0);

        pfStack_5c = (float *)(float)fVar20;

        fVar20 = (float10)playerobj_turn(pfStack_5c,*(undefined4 *)&param_1->field_0xc8);

        if (ABS(fVar20) != (float10)0.0) {

          param_1->flags = param_1->flags | 0x1000000;

          param_1->waypoint2 = (dword)pfStack_5c;

          uVar9 = __ftol();

          param_1->field_0x208 = uVar9;

        }

      }

    }

    else {

      if ((*(int *)&param_1->field_0xe8 == 1) || (*(int *)&param_1->field_0xe8 == 4)) {

        iVar11 = *(int *)(DAT_00632ed8 + 0x1640);

      }

      else {

        iVar11 = *(int *)(DAT_00632ed8 + 0xe64);

      }

      iVar13 = crt_rand_scaled(100);

      if (iVar13 < iVar11) {

        sound_play_obj(0x3a4);

        dVar16 = param_1->animate_state;

        fVar20 = (float10)rndfloatrange(*(undefined4 *)(DAT_00632ed8 + 0xee8),

                                        *(undefined4 *)(DAT_00632ed8 + 0xeec));

        pfStack_5c = (float *)(float)fVar20;

        fVar20 = (float10)rndfloatrange(0,0x43b40000,&fStack_58,&fStack_54);

        sine_cos_lookup((float)fVar20);

        iVar11 = *(int *)(dVar16 + 0x3c);

        *(float *)(dVar16 + 0xdb4) = fStack_58 * (float)pfStack_5c + *(float *)(iVar11 + 0xa0);

        *(float *)(dVar16 + 0xdb8) = *(float *)(iVar11 + 0xa4) - fStack_54 * (float)pfStack_5c;

        *(undefined4 *)(dVar16 + 0xdbc) = *(undefined4 *)(iVar11 + 0xa8);

        evilreaper_change_anim__FP6OBJECTii4SDKYf(param_1,0x60,0,0,0);

        param_1->pad_E4 = 0x53;

        break;

      }

      iVar7 = *(int *)&param_1->field_0xe8;

      if ((iVar7 == 1) || (iVar7 == 4)) {

        iVar8 = *(int *)(DAT_00632ed8 + 0x1644);

      }

      else {

        iVar8 = *(int *)(DAT_00632ed8 + 0xe5c);

      }

      if (iVar13 < iVar11 + iVar8) {

        evilreaper_select_firewall_loc__FP6OBJECT(param_1);

        sound_play_player(0x3a4,param_1);

        evilreaper_change_anim__FP6OBJECTii4SDKYf(param_1,0x60,0,0,0);

        param_1->pad_E4 = 0x54;

        break;

      }

      if ((iVar7 == 1) || (iVar7 == 4)) {

        iVar17 = *(int *)(DAT_00632ed8 + 0x1648);

      }

      else {

        iVar17 = *(int *)(DAT_00632ed8 + 0xe60);

      }

      iVar17 = iVar11 + iVar8 + iVar17;

      if (iVar13 < iVar17) {

        if (iVar7 != 1) {

          if ((iVar7 != 4) && (iVar7 != 2)) {

            uVar10 = 0x39d;

            pOVar21 = param_1;

            sound_play_obj(0x39d);

            evilreaper_change_anim__FP6OBJECTii4SDKYf(param_1,0x61,0,0,0,uVar10,pOVar21);

            param_1->pad_E4 = 0x52;

            break;

          }

          goto LAB_004c8149;

        }

LAB_004c815b:

        iVar11 = *(int *)(DAT_00632ed8 + 0x164c);

      }

      else {

LAB_004c8149:

        if ((iVar7 == 1) || (iVar7 == 4)) goto LAB_004c815b;

        iVar11 = *(int *)(DAT_00632ed8 + 0xe68);

      }

      iVar17 = iVar17 + iVar11;

      if (iVar13 < iVar17) {

        uVar10 = 0x3a4;

        pOVar21 = param_1;

        sound_play_obj(0x3a4);

        evilreaper_change_anim__FP6OBJECTii4SDKYf(param_1,0x60,0,0,0,uVar10,pOVar21);

        param_1->pad_E4 = 0x50;

        break;

      }

      if ((iVar7 == 1) || (iVar7 == 4)) {

        iVar11 = *(int *)(DAT_00632ed8 + 0x1650);

      }

      else {

        iVar11 = *(int *)(DAT_00632ed8 + 0xed8);

      }

      if (((iVar13 < iVar17 + iVar11) || (iVar7 == 1)) || (iVar7 == 4)) {

        uVar10 = 0x3a4;

        pOVar21 = param_1;

        sound_play_obj(0x3a4);

        evilreaper_change_anim__FP6OBJECTii4SDKYf(param_1,0x60,0,0,0,uVar10,pOVar21);

        param_1->pad_E4 = 0x51;

        break;

      }

      pfVar1 = (float *)(dVar16 + 0xdb4);

      pfStack_5c = (float *)(dVar16 + 0xdb8);

      pfVar15 = (float *)(dVar16 + 0xdbc);

      *pfVar1 = *(float *)(DAT_00632a88 + 0xa0) - *(float *)&param_1->field_0xa0;

      *pfStack_5c = *(float *)(DAT_00632a88 + 0xa4) - *(float *)&param_1->field_0xa4;

      *pfVar15 = *(float *)(DAT_00632a88 + 0xa8) - *(float *)&param_1->field_0xa8;

      normalize__FPfN20(pfVar1,pfStack_5c,pfVar15);

      *pfVar1 = *(float *)(DAT_00632ed8 + 0x834) * *pfVar1;

      *pfStack_5c = *(float *)(DAT_00632ed8 + 0x834) * *pfStack_5c;

      *pfVar15 = *(float *)(DAT_00632ed8 + 0x834) * *pfVar15;

      *pfVar1 = *pfVar1 + *(float *)&param_1->field_0xa0;

      *pfStack_5c = *pfStack_5c + *(float *)&param_1->field_0xa4;

      *pfVar15 = *(float *)&param_1->field_0xa8 + *pfVar15;

      ground_height_at(pfVar1,auStack_34);

      *pfVar15 = fStack_24;

      if (((param_1->coll_radius & 0x800) == 0) &&

         ((ai_fly_update_goal_4(pfVar1,&fStack_44,&pfStack_5c), fStack_3c < 0.64278 ||

          ((float)pfStack_5c < -3.0 != ((float)pfStack_5c == -3.0))))) {

        if (*(int *)&param_1->field_0xe8 != 2) goto LAB_004c8331;

        evilreaper_find_turbo_marker__FP6OBJECTP3P3Di(param_1,pfVar1,100);

      }

      uVar10 = 0x39c;

      pOVar21 = param_1;

      sound_play_obj(0x39c);

      evilreaper_change_anim__FP6OBJECTii4SDKYf(param_1,0x62,0,0,0,uVar10,pOVar21);

      param_1->pad_E4 = 0x55;

    }

    break;

  case 0xd:

    evilreaper_verify_enemy__FP6OBJECTf(param_1,0xbf800000);

    if (*(int *)(dVar6 + 0x3c) == 0) {

      param_1->pad_E4 = 0x3c;

      break;

    }

    if ((*(int *)&param_1->field_0xe8 != 1) && (*(int *)&param_1->field_0xe8 != 4)) {

      fVar20 = (float10)rndfloatrange(0x40000000,0x40e00000);

      *(float *)(dVar6 + 0x60) = (float)fVar20;

      evilreaper_set_new_location__FP6OBJECTi(param_1,0);

      ai_goal_process(param_1);

      if (*(int *)&param_1->field_0x168 == 0) {

        physics_reset_a(param_1);

      }

      else {

        dVar16 = param_1->animate_state;

        if (param_1->anim != 2) {

          ObjectSetAnim(param_1);

          *(undefined4 *)(dVar16 + 0xb4) = 2;

        }

        param_1->pad_E4 = 0xe;

      }

      break;

    }

    goto LAB_004c9051;

  case 0xe:

    if (*(int *)(dVar6 + 0x3c) == 0) {

      param_1->pad_E4 = 0x3c;

      break;

    }

    param_1->anim_selector = (dword)&LAB_004cb930;

    ai_goal_process(param_1);

    fVar5 = *(float *)(dVar6 + 0x60) - fVar26;

    *(float *)(dVar6 + 0x60) = fVar5;

    if ((*(int *)&param_1->field_0x168 != 0) && (0.0 <= fVar5)) break;

    ai_clear_move_goal(param_1);

    fVar20 = (float10)dirfcalcp3d__FP3P3DT0(&param_1->field_0xa0,*(int *)(dVar6 + 0x3c) + 0xa0);

    pfStack_5c = (float *)(float)fVar20;

    fVar20 = (float10)playerobj_turn(pfStack_5c,*(undefined4 *)&param_1->field_0xc8);

    fStack_54 = (float)ABS(fVar20);

    if (ABS(fVar20) == (float10)0.0) {

      fVar5 = 0.0;

    }

    else {

      param_1->flags = param_1->flags | 0x1000000;

      param_1->waypoint2 = (dword)pfStack_5c;

      uVar9 = __ftol();

      param_1->field_0x208 = uVar9;

      fVar5 = fStack_54;

    }

    if (fVar5 < 5.0) {

      evilreaper_verify_enemy__FP6OBJECTf(param_1,*(undefined4 *)(DAT_00632ed8 + 0xe98));

      if (*(int *)(dVar6 + 0x3c) == 0) goto LAB_004c99d7;

      if ((*(float *)(dVar6 + 0xa0) < 0.0 == (*(float *)(dVar6 + 0xa0) == 0.0)) &&

         (*(float *)(dVar6 + 0xa4) < 0.0 == (*(float *)(dVar6 + 0xa4) == 0.0))) {

        if (*(float *)(dVar6 + 100) < 0.0 == (*(float *)(dVar6 + 100) == 0.0)) {

          dVar16 = param_1->animate_state;

          if (param_1->anim != 0x35) {

            ObjectSetAnim(param_1);

            *(undefined4 *)(dVar16 + 0xb4) = 0x35;

          }

          *(float *)(dVar6 + 100) = *(float *)(dVar6 + 100) - fVar26;

          break;

        }

        iVar11 = crt_rand_scaled(100);

        if (*(int *)(DAT_00632ed8 + 0xee0) <= iVar11) {

          dVar16 = param_1->animate_state;

          if (param_1->anim != 2) {

            ObjectSetAnim(param_1);

            *(undefined4 *)(dVar16 + 0xb4) = 2;

          }

          fVar20 = (float10)rndfloatrange(0x40000000,0x40e00000);

          *(float *)(dVar6 + 0x60) = (float)fVar20;

          evilreaper_set_new_location__FP6OBJECTi(param_1,1);

          break;

        }

        goto LAB_004c8d7e;

      }

      goto LAB_004c9051;

    }

    dVar16 = param_1->animate_state;

    dVar18 = 0x5c;

    if (param_1->anim == 0x5c) break;

    goto LAB_004c9894;

  case 0xf:

    evilreaper_verify_enemy__FP6OBJECTf(param_1,0xbf800000);

    if (*(int *)(dVar6 + 0x3c) == 0) {

      param_1->pad_E4 = 0x3c;

    }

    else {

      evilreaper_get_turbo_loc__FP6OBJECTP3P3DfffT1

                (param_1,*(int *)(dVar6 + 0x3c) + 0xa0,0x41a00000,

                 *(undefined4 *)(DAT_00632ed8 + 0xe7c),*(undefined4 *)(DAT_00632ed8 + 0xe80),

                 &fStack_44);

      dVar16 = param_1->animate_state;

      if (param_1->anim != 0x5c) {

        ObjectSetAnim(param_1);

        *(undefined4 *)(dVar16 + 0xb4) = 0x5c;

      }

      ai_moveonly_set_goal(param_1,&fStack_44);

      param_1->pad_E4 = 0x11;

    }

    break;

  case 0x10:

  case 0x12:

  case 0x13:

    evilreaper_verify_enemy__FP6OBJECTf(param_1,0xbf800000);

    if (*(int *)(dVar6 + 0x3c) == 0) {

      param_1->pad_E4 = 0x3c;

      break;

    }

    iVar11 = physics_reset_d(param_1);

    if (iVar11 == 0) break;

    uVar12 = param_1->coll_radius;

    if (param_1->pad_E4 != 0x13) {

      if (((uVar12 & 0x800) != 0) ||

         ((ai_fly_update_goal_4(&param_1->field_0xa0,&fStack_44,&fStack_58), 0.64278 <= fStack_3c &&

          (fStack_58 < -3.0 == (fStack_58 == -3.0))))) {

        if ((param_1->coll_radius & 0x800) == 0) {

          fVar20 = (float10)rndfloatrange(*(undefined4 *)(DAT_00632ed8 + 0x136c),

                                          *(undefined4 *)(DAT_00632ed8 + 0x1370));

          *(float *)(dVar6 + 100) = (float)fVar20;

          param_1->pad_E4 = 0xd;

        }

        else {

          *(undefined4 *)(dVar6 + 0xa0) = 0;

          param_1->pad_E4 = 0xc;

        }

        break;

      }

      goto LAB_004c8d7e;

    }

    if ((uVar12 & 0x40) == 0) {

      ai_clear_move_goal(param_1);

      ai_moveonly_set_goal(param_1,dVar6 + 0xdb4);

      goto LAB_004c9ee1;

    }

    goto LAB_004c7d68;

  case 0x11:

    evilreaper_verify_enemy__FP6OBJECTf(param_1,0xbf800000);

    if (*(int *)(dVar6 + 0x3c) == 0) {

      param_1->pad_E4 = 0x3c;

    }

    else {

      ai_get_goal_location(param_1,&uStack_50);

      fVar20 = (float10)dirfcalcp3d__FP3P3DT0(&param_1->field_0xa0,&uStack_50);

      pfStack_5c = (float *)(float)fVar20;

      fVar20 = (float10)playerobj_turn(pfStack_5c,*(undefined4 *)&param_1->field_0xc8);

      fStack_58 = (float)ABS(fVar20);

      if (ABS(fVar20) == (float10)0.0) {

        fVar5 = 0.0;

      }

      else {

        param_1->flags = param_1->flags | 0x1000000;

        param_1->waypoint2 = (dword)pfStack_5c;

        uVar9 = __ftol();

        param_1->field_0x208 = uVar9;

        fVar5 = fStack_58;

      }

      if (fVar5 < 2.0) {

        ai_clear_move_goal(param_1);

        dVar16 = param_1->animate_state;

        *(undefined4 *)(param_1->pad_104 + 4) = *(undefined4 *)(DAT_00632ed8 + 0xfe4);

        *(undefined4 *)(param_1->pad_104 + 8) = *(undefined4 *)(DAT_00632ed8 + 0xfe8);

        *(undefined4 *)(dVar16 + 0xdcc) = uStack_50;

        *(undefined4 *)(dVar16 + 0xdd0) = uStack_4c;

        *(float *)(dVar16 + 0xdd4) = fStack_48;

        dVar18 = param_1->animate_state;

        PhysicsExZeroForce_dup004a17a0(param_1);

        iVar11 = dVar18 + 0xdcc;

        fVar20 = (float10)distancesq3d(&param_1->field_0xa0,iVar11);

        pfStack_5c = (float *)(float)fVar20;

        if ((*(int *)&param_1->field_0xe8 == 1) || (*(int *)&param_1->field_0xe8 == 4)) {

          fVar20 = (float10)powf();

          fVar20 = fVar20 * (float10)*(float *)(DAT_00632ed8 + 0x1654);

        }

        else {

          fVar20 = (float10)powf();

          fVar20 = fVar20 * (float10)*(float *)(DAT_00632ed8 + 0xfe0);

        }

        pfStack_5c = (float *)(float)fVar20;

        fStack_40 = 0.0;

        fStack_44 = 0.0;

        fStack_3c = (*(float *)(param_1->pad_104 + 4) / *(float *)(param_1->pad_104 + 8)) *

                    -32.17405;

        trajectory_calculate(&param_1->pad_128,&param_1->field_0xa0,iVar11,&fStack_44,pfStack_5c);

        uVar28 = 3;

        uVar27 = 0;

        uVar25 = 0x33c;

        *(float *)&param_1->field_0xf0 = (float)pfStack_5c * 0.85;

        uVar24 = 0;

        uVar23 = 0x33d;

        uVar22 = 0x33e;

        param_1->coll_radius = param_1->coll_radius | 4;

        pOVar21 = param_1;

        uVar10 = sound_get_free_sequence__Fv();

        *(undefined4 *)(dVar16 + 0xde0) = uVar10;

        evilreaper_change_anim__FP6OBJECTii4SDKYf

                  (param_1,0x5a,1,0,0,uVar22,uVar23,uVar24,uVar25,pOVar21,uVar27,uVar28);

        param_1->pad_E4 = 0x10;

      }

    }

    break;

  case 0x14:

    evilreaper_verify_enemy__FP6OBJECTf(param_1,0xbf800000);

    if (*(int *)(dVar6 + 0x3c) == 0) {

      if (*(int *)&param_1->field_0xe8 == 2) {

        uVar10 = 0xbf800000;

      }

      else {

        uVar10 = *(undefined4 *)(DAT_00632ed8 + 0xe94);

      }

      evilreaper_scan_for_enemy__FP6OBJECTf(param_1,uVar10);

    }

    else {

      fVar20 = (float10)dirfcalcp3d__FP3P3DT0(&param_1->field_0xa0,*(int *)(dVar6 + 0x3c) + 0xa0);

      pfStack_5c = (float *)(float)fVar20;

      fVar20 = (float10)playerobj_turn(pfStack_5c,*(undefined4 *)&param_1->field_0xc8);

      if (ABS(fVar20) != (float10)0.0) {

        param_1->flags = param_1->flags | 0x1000000;

        param_1->waypoint2 = (dword)pfStack_5c;

        uVar9 = __ftol();

        param_1->field_0x208 = uVar9;

      }

      if (((0 < *(int *)(dVar6 + 0x98)) && (*(float *)(dVar6 + 0xa0) < 0.0)) &&

         ((param_1->field_0x30 & 2) != 0)) {

        if (*(int *)(dVar6 + 0x9c) < 1) {

          uVar10 = rndintrange(*(undefined4 *)(dVar6 + 0x74),*(undefined4 *)(dVar6 + 0x78));

          *(undefined4 *)(dVar6 + 0x9c) = uVar10;

        }

        evilreaper_fire_bow__FP6OBJECT(param_1);

        if (*(int *)(dVar6 + 0x9c) < 1) {

          iVar11 = *(int *)(dVar6 + 0x98) + -1;

          *(int *)(dVar6 + 0x98) = iVar11;

          if (0 < iVar11) {

            fVar20 = (float10)rndfloatrange(*(undefined4 *)(dVar6 + 0x84),

                                            *(undefined4 *)(dVar6 + 0x88));

            *(float *)(dVar6 + 0xa0) = (float)fVar20;

          }

        }

        else {

          fVar20 = (float10)rndfloatrange(*(undefined4 *)(dVar6 + 0x7c),

                                          *(undefined4 *)(dVar6 + 0x80));

          *(float *)(dVar6 + 0xa0) = (float)fVar20;

        }

      }

    }

    iVar11 = physics_reset_d(param_1);

    if (iVar11 == 0) break;

    if ((param_1->coll_radius & 0x800) == 0) {

      puVar2 = &param_1->field_0xa0;

      ai_fly_update_goal_4(puVar2,&fStack_44,&fStack_54);

      if ((fStack_3c < 0.64278) || (fStack_54 < -3.0 != (fStack_54 == -3.0))) {

        dVar16 = param_1->animate_state;

        evilreaper_get_turbo_loc__FP6OBJECTP3P3DfffT1

                  (param_1,*(int *)(dVar16 + 0x3c) + 0xa0,0x41a00000,

                   *(undefined4 *)(DAT_00632ed8 + 0xe7c),*(undefined4 *)(DAT_00632ed8 + 0xe80),

                   &uStack_50);

        collgrid_collide_d(param_1,puVar2,&uStack_50);

        fVar20 = (float10)dirfcalcp3d__FP3P3DT0(puVar2,&uStack_50);

        *(float *)&param_1->field_0xc8 = (float)fVar20;

        dVar18 = param_1->animate_state;

        *(undefined4 *)(param_1->pad_104 + 4) = *(undefined4 *)(DAT_00632ed8 + 0xfe4);

        *(undefined4 *)(param_1->pad_104 + 8) = *(undefined4 *)(DAT_00632ed8 + 0xfe8);

        *(undefined4 *)(dVar18 + 0xdcc) = uStack_50;

        *(undefined4 *)(dVar18 + 0xdd0) = uStack_4c;

        *(float *)(dVar18 + 0xdd4) = fStack_48;

        fVar20 = (float10)physics_reset_c(param_1);

        *(float *)&param_1->field_0xf0 = (float)(fVar20 * (float10)0.85);

        param_1->coll_radius = param_1->coll_radius | 4;

        uVar10 = sound_get_free_sequence__Fv();

        *(undefined4 *)(dVar18 + 0xde0) = uVar10;

        evilreaper_change_anim__FP6OBJECTii4SDKYf(param_1,0x5a,1,0,0);

        uVar10 = 0x38f;

        pOVar21 = param_1;

        sound_play_obj(0x38f);

        evilreaper_change_anim__FP6OBJECTii4SDKYf(param_1,0x81,1,0,0,uVar10,pOVar21);

        fVar20 = (float10)rndfloatrange(*(undefined4 *)(dVar16 + 0x7c),

                                        *(undefined4 *)(dVar16 + 0x80));

        *(float *)(dVar16 + 0xa0) = (float)fVar20;

        param_1->pad_E4 = 0x14;

        break;

      }

    }

    if (((0 < *(int *)(dVar6 + 0x98)) || (0 < *(int *)(dVar6 + 0x9c))) &&

       (*(int *)(dVar6 + 0x3c) != 0)) goto LAB_004c879d;

    fVar20 = (float10)rndfloatrange(*(undefined4 *)(DAT_00632ed8 + 0x136c),

                                    *(undefined4 *)(DAT_00632ed8 + 0x1370));

    *(float *)(dVar6 + 100) = (float)fVar20;

    fVar20 = (float10)rndfloatrange(*(undefined4 *)(dVar6 + 0x8c),*(undefined4 *)(dVar6 + 0x90));

    goto LAB_004c8a56;

  case 0x28:

    evilreaper_verify_enemy__FP6OBJECTf(param_1,0xbf800000);

    if (*(int *)(dVar6 + 0x3c) == 0) {

      param_1->pad_E4 = 0x3c;

      break;

    }

    if ((param_1->field_0x30 & 2) == 0) break;

    puVar3 = (uint *)(*(int *)(dVar6 + 0xa8) + 0xd8);

    *puVar3 = *puVar3 & 0xbfffffff;

    *(uint *)(*(int *)(dVar6 + 0xac) + 0xd8) = *(uint *)(*(int *)(dVar6 + 0xac) + 0xd8) | 0x40000000

    ;

    iVar11 = crt_rand_scaled(100);

    if (iVar11 < *(int *)(DAT_00632ed8 + 0x1368)) {

      dVar16 = param_1->animate_state;

      evilreaper_get_turbo_loc__FP6OBJECTP3P3DfffT1

                (param_1,*(int *)(dVar16 + 0x3c) + 0xa0,0x41a00000,

                 *(undefined4 *)(DAT_00632ed8 + 0xe7c),*(undefined4 *)(DAT_00632ed8 + 0xe80),

                 &uStack_50);

      collgrid_collide_d(param_1,&param_1->field_0xa0,&uStack_50);

      fVar20 = (float10)dirfcalcp3d__FP3P3DT0(&param_1->field_0xa0,&uStack_50);

      *(float *)&param_1->field_0xc8 = (float)fVar20;

      dVar18 = param_1->animate_state;

      *(undefined4 *)(param_1->pad_104 + 4) = *(undefined4 *)(DAT_00632ed8 + 0xfe4);

      *(undefined4 *)(param_1->pad_104 + 8) = *(undefined4 *)(DAT_00632ed8 + 0xfe8);

      *(undefined4 *)(dVar18 + 0xdcc) = uStack_50;

      *(undefined4 *)(dVar18 + 0xdd0) = uStack_4c;

      *(float *)(dVar18 + 0xdd4) = fStack_48;

      fVar20 = (float10)physics_reset_c(param_1);

      *(float *)&param_1->field_0xf0 = (float)(fVar20 * (float10)0.85);

      param_1->coll_radius = param_1->coll_radius | 4;

      uVar10 = sound_get_free_sequence__Fv();

      *(undefined4 *)(dVar18 + 0xde0) = uVar10;

      evilreaper_change_anim__FP6OBJECTii4SDKYf(param_1,0x5a,1,0,0);

      sound_play_obj(0x38f);

      dVar18 = param_1->animate_state;

      if (param_1->anim != 0x81) {

        ObjectSetAnim(param_1);

        *(undefined4 *)(dVar18 + 0xb4) = 0x81;

      }

      fVar20 = (float10)rndfloatrange(*(undefined4 *)(dVar16 + 0x7c),*(undefined4 *)(dVar16 + 0x80))

      ;

      *(float *)(dVar16 + 0xa0) = (float)fVar20;

      param_1->pad_E4 = 0x14;

      break;

    }

LAB_004c879d:

    sound_play_obj(0x38f);

    goto LAB_004c8bb4;

  case 0x29:

    evilreaper_verify_enemy__FP6OBJECTf(param_1,0xbf800000);

    if (*(int *)(dVar6 + 0x3c) == 0) {

      param_1->pad_E4 = 0x3c;

      break;

    }

    if ((param_1->field_0x30 & 2) == 0) break;

    puVar3 = (uint *)(*(int *)(dVar6 + 0xac) + 0xd8);

    *puVar3 = *puVar3 & 0xbfffffff;

    puVar3 = (uint *)(*(int *)(dVar6 + 0xa8) + 0xd8);

    *puVar3 = *puVar3 | 0x40000000;

    dVar16 = param_1->animate_state;

    if (*(float *)(DAT_00632ed8 + 0xe30) * *(float *)(DAT_00632ed8 + 0xe30) <

        *(float *)(dVar16 + 0x50)) {

      iVar11 = *(int *)(dVar16 + 0x3c);

      *(undefined4 *)(param_1->pad_104 + 4) = *(undefined4 *)(DAT_00632ed8 + 0xfe4);

      *(undefined4 *)(param_1->pad_104 + 8) = *(undefined4 *)(DAT_00632ed8 + 0xfe8);

      *(undefined4 *)(dVar16 + 0xdcc) = *(undefined4 *)(iVar11 + 0xa0);

      *(undefined4 *)(dVar16 + 0xdd0) = *(undefined4 *)(iVar11 + 0xa4);

      *(undefined4 *)(dVar16 + 0xdd4) = *(undefined4 *)(iVar11 + 0xa8);

      fVar20 = (float10)physics_reset_c(param_1);

      uVar28 = 3;

      uVar27 = 0;

      *(float *)&param_1->field_0xf0 = (float)(fVar20 * (float10)0.85);

      uVar25 = 0x33c;

      uVar24 = 0;

      uVar23 = 0x33d;

      uVar22 = 0x33e;

      param_1->coll_radius = param_1->coll_radius | 4;

      pOVar21 = param_1;

      uVar10 = sound_get_free_sequence__Fv();

      *(undefined4 *)(dVar16 + 0xde0) = uVar10;

      evilreaper_change_anim__FP6OBJECTii4SDKYf

                (param_1,0x5a,1,0,0,uVar22,uVar23,uVar24,uVar25,pOVar21,uVar27,uVar28);

      param_1->pad_E4 = 0x46;

      break;

    }

    goto LAB_004c93bf;

  case 0x32:

    evilreaper_verify_enemy__FP6OBJECTf(param_1,0xbf800000);

    if (*(int *)(dVar6 + 0x3c) != 0) {

      fVar20 = (float10)dirfcalcp3d__FP3P3DT0(&param_1->field_0xa0,*(int *)(dVar6 + 0x3c) + 0xa0);

      pfStack_5c = (float *)(float)fVar20;

      fVar20 = (float10)playerobj_turn(pfStack_5c,*(undefined4 *)&param_1->field_0xc8);

      if (ABS(fVar20) != (float10)0.0) {

        param_1->flags = param_1->flags | 0x1000000;

        param_1->waypoint2 = (dword)pfStack_5c;

        uVar9 = __ftol();

        param_1->field_0x208 = uVar9;

      }

      if ((*(float *)(dVar6 + 0xa0) < 0.0) && ((param_1->field_0x30 & 2) != 0)) {

        evilreaper_fire_bow__FP6OBJECT(param_1);

        dVar16 = param_1->animate_state;

        if (param_1->anim != 0x7c) {

          ObjectSetAnim(param_1);

          *(undefined4 *)(dVar16 + 0xb4) = 0x7c;

        }

        param_1->pad_E4 = 0x33;

      }

      break;

    }

LAB_004c8901:

    uVar10 = *(undefined4 *)(dVar6 + 0x90);

    uVar22 = *(undefined4 *)(dVar6 + 0x8c);

LAB_004c8a4e:

    fVar20 = (float10)rndfloatrange(uVar22,uVar10);

LAB_004c8a56:

    *(float *)(dVar6 + 0xa0) = (float)fVar20;

    goto LAB_004c8a5c;

  case 0x33:

    evilreaper_verify_enemy__FP6OBJECTf(param_1,0xbf800000);

    if (*(int *)(dVar6 + 0x3c) == 0) goto LAB_004c8901;

    fVar20 = (float10)dirfcalcp3d__FP3P3DT0(&param_1->field_0xa0,*(int *)(dVar6 + 0x3c) + 0xa0);

    pfStack_5c = (float *)(float)fVar20;

    fVar20 = (float10)playerobj_turn(pfStack_5c,*(undefined4 *)&param_1->field_0xc8);

    if (ABS(fVar20) != (float10)0.0) {

      param_1->flags = param_1->flags | 0x1000000;

      param_1->waypoint2 = (dword)pfStack_5c;

      uVar9 = __ftol();

      param_1->field_0x208 = uVar9;

    }

    if ((param_1->field_0x30 & 2) == 0) break;

    if (*(int *)(dVar6 + 0x9c) < 1) {

      iVar11 = *(int *)(dVar6 + 0x98) + -1;

      *(int *)(dVar6 + 0x98) = iVar11;

      if (0 < iVar11) {

        fVar20 = (float10)rndfloatrange(*(undefined4 *)(dVar6 + 0x84),*(undefined4 *)(dVar6 + 0x88))

        ;

        *(float *)(dVar6 + 0xa0) = (float)fVar20;

        dVar16 = param_1->animate_state;

        if (param_1->anim != 1) {

          ObjectSetAnim(param_1);

          *(undefined4 *)(dVar16 + 0xb4) = 1;

        }

        param_1->pad_E4 = 0x34;

        break;

      }

      goto LAB_004c8a40;

    }

    fVar20 = (float10)rndfloatrange(*(undefined4 *)(dVar6 + 0x7c),*(undefined4 *)(dVar6 + 0x80));

    *(float *)(dVar6 + 0xa0) = (float)fVar20;

    sound_play_obj(0x38f);

    dVar16 = param_1->animate_state;

    if (param_1->anim != 0x7b) {

      ObjectSetAnim(param_1);

      *(undefined4 *)(dVar16 + 0xb4) = 0x7b;

      param_1->pad_E4 = 0x32;

      break;

    }

    goto LAB_004c8bef;

  case 0x34:

    evilreaper_verify_enemy__FP6OBJECTf(param_1,0xbf800000);

    if (*(int *)(dVar6 + 0x3c) == 0) {

LAB_004c8a40:

      uVar10 = *(undefined4 *)(dVar6 + 0x90);

      uVar22 = *(undefined4 *)(dVar6 + 0x8c);

      goto LAB_004c8a4e;

    }

    fVar20 = (float10)dirfcalcp3d__FP3P3DT0(&param_1->field_0xa0,*(int *)(dVar6 + 0x3c) + 0xa0);

    pfStack_5c = (float *)(float)fVar20;

    fVar20 = (float10)playerobj_turn(pfStack_5c,*(undefined4 *)&param_1->field_0xc8);

    if (ABS(fVar20) != (float10)0.0) {

      param_1->flags = param_1->flags | 0x1000000;

      param_1->waypoint2 = (dword)pfStack_5c;

      uVar9 = __ftol();

      param_1->field_0x208 = uVar9;

    }

    if (*(float *)(dVar6 + 0xa0) < 0.0 == (*(float *)(dVar6 + 0xa0) == 0.0)) break;

    uVar10 = rndintrange(*(undefined4 *)(dVar6 + 0x74),*(undefined4 *)(dVar6 + 0x78));

    *(undefined4 *)(dVar6 + 0x9c) = uVar10;

    sound_play_obj(0x38f);

LAB_004c8bb4:

    dVar16 = param_1->animate_state;

    if (param_1->anim != 0x7b) {

      ObjectSetAnim(param_1);

      *(undefined4 *)(dVar16 + 0xb4) = 0x7b;

    }

LAB_004c8bef:

    param_1->pad_E4 = 0x32;

    break;

  case 0x3c:

    if ((*(int *)&param_1->field_0xe8 != 1) && (*(int *)&param_1->field_0xe8 != 4)) {

      dVar16 = param_1->animate_state;

      if (param_1->anim != 2) {

        ObjectSetAnim(param_1);

        *(undefined4 *)(dVar16 + 0xb4) = 2;

      }

      dVar16 = param_1->animate_state;

      fVar20 = (float10)rndfloatrange(0,0x43b40000);

      fStack_54 = (float)fVar20;

      sine_cos_lookup(fStack_54,&fStack_58,&pfStack_5c);

      fVar20 = (float10)rndfloatrange(0x41a00000,0x42960000);

      fStack_44 = (float)(fVar20 * (float10)fStack_58 + (float10)*(float *)(dVar16 + 0x40));

      fVar20 = (float10)rndfloatrange(0x41a00000,0x42960000);

      fStack_40 = (float)((float10)*(float *)(dVar16 + 0x44) - fVar20 * (float10)(float)pfStack_5c);

      fStack_3c = *(float *)(dVar16 + 0x48);

      ai_clear_move_goal(param_1);

      ai_moveonly_set_goal(param_1,&fStack_44);

      param_1->pad_E4 = 0x3d;

      break;

    }

  case 10:

    dVar16 = param_1->animate_state;

    if (param_1->anim != 0x35) {

      ObjectSetAnim(param_1);

      *(undefined4 *)(dVar16 + 0xb4) = 0x35;

    }

    *(undefined4 *)&param_1->field_0xec = 0x3f800000;

    param_1->pad_E4 = 0xb;

    break;

  case 0x3d:

    fVar5 = *(float *)&param_1->field_0xec - fVar26;

    *(float *)&param_1->field_0xec = fVar5;

    if (fVar5 < 0.0) {

      evilreaper_scan_for_enemy__FP6OBJECTf(param_1,*(undefined4 *)(DAT_00632ed8 + 0xe94));

      *(undefined4 *)&param_1->field_0xec = 0x3f800000;

    }

    if (*(int *)(dVar6 + 0x3c) == 0) {

      param_1->anim_selector = (dword)&LAB_004cb930;

      ai_goal_process(param_1);

      if (*(int *)&param_1->field_0x168 == 0) {

        dVar16 = param_1->animate_state;

        if (param_1->anim != 0x35) {

          ObjectSetAnim(param_1);

          *(undefined4 *)(dVar16 + 0xb4) = 0x35;

        }

        fVar20 = (float10)rndfloatrange(0x41200000,0x41f00000);

        *(float *)(dVar6 + 0x60) = (float)fVar20;

        param_1->pad_E4 = 0x3e;

      }

      break;

    }

    goto LAB_004c79df;

  case 0x3e:

    fVar5 = *(float *)&param_1->field_0xec - fVar26;

    *(float *)&param_1->field_0xec = fVar5;

    bVar19 = fVar5 < 0.0 | (byte)((ushort)((ushort)(fVar5 == 0.0) << 0xe) >> 8);

LAB_004c79af:

    if ((POPCOUNT(bVar19) & 1U) != 0) {

      evilreaper_scan_for_enemy__FP6OBJECTf(param_1,*(undefined4 *)(DAT_00632ed8 + 0xe94));

      *(undefined4 *)&param_1->field_0xec = 0x3f800000;

    }

    if (*(int *)(dVar6 + 0x3c) != 0) {

LAB_004c79df:

      dVar16 = param_1->animate_state;

      iVar11 = crt_rand_scaled(100);

      if (iVar11 < *(int *)(DAT_00632ed8 + 0xe8c)) {

        if ((*(int *)&param_1->field_0xe8 == 3) || (*(int *)&param_1->field_0xe8 == 4)) {

          uVar10 = *(undefined4 *)(DAT_00632ed8 + 0x15fc);

          uVar22 = *(undefined4 *)(DAT_00632ed8 + 0x15f8);

        }

        else {

          uVar10 = *(undefined4 *)(DAT_00632ed8 + 0xe3c);

          uVar22 = *(undefined4 *)(DAT_00632ed8 + 0xe38);

        }

        fVar20 = (float10)rndfloatrange(uVar22,uVar10);

        *(float *)(dVar16 + 0xa4) = (float)fVar20;

LAB_004c9051:

        param_1->pad_E4 = 0xc;

      }

      else {

LAB_004c8a5c:

        param_1->pad_E4 = 0xd;

      }

    }

    break;

  case 0x46:

    iVar11 = physics_reset_d(param_1);

    if (iVar11 == 0) break;

    if (((param_1->coll_radius & 0x800) == 0) &&

       ((ai_fly_update_goal_4(&param_1->field_0xa0,&fStack_44,&fStack_54), fStack_3c < 0.64278 ||

        (fStack_54 < -3.0 != (fStack_54 == -3.0))))) {

LAB_004c8d7e:

      physics_reset_a(param_1);

      break;

    }

    dVar16 = param_1->animate_state;

LAB_004c93bf:

    if (param_1->anim != 2) {

      ObjectSetAnim(param_1);

      *(undefined4 *)(dVar16 + 0xb4) = 2;

    }

    param_1->pad_E4 = 0x47;

    break;

  case 0x47:

    evilreaper_verify_enemy__FP6OBJECTf(param_1,*(undefined4 *)(DAT_00632ed8 + 0xe98));

    iVar11 = *(int *)(dVar6 + 0x3c);

    if (iVar11 == 0) {

      param_1->coll_radius = param_1->coll_radius & 0xfffffff7;

      param_1->pad_E4 = 0x3c;

      break;

    }

    if ((param_1->coll_radius & 8) == 0) {

      if (*(float *)(dVar6 + 0xa0) < 0.0 != (*(float *)(dVar6 + 0xa0) == 0.0)) {

        fVar20 = (float10)rndfloatrange(*(undefined4 *)(dVar6 + 0x8c),*(undefined4 *)(dVar6 + 0x90))

        ;

        *(float *)(dVar6 + 0xa0) = (float)fVar20;

        iVar11 = crt_rand_scaled(100);

        param_1->pad_E4 = (uint)(iVar11 < *(int *)(DAT_00632ed8 + 0xedc)) * 2 + 0xd;

        break;

      }

      ai_move_update_goal(param_1,iVar11 + 0xa0);

      param_1->anim_selector = (dword)&LAB_004cb930;

      iVar11 = ai_goal_process(param_1);

      if (iVar11 == -1) {

        *(undefined4 *)(dVar6 + 0xa0) = 0;

      }

      if ((param_1->coll_radius & 0x10) != 0) break;

      iVar11 = ObjIsMecc(*(undefined4 *)(dVar6 + 0x3c));

      if (iVar11 == 0) {

        iVar11 = ObjIsReaper(*(undefined4 *)(dVar6 + 0x3c));

        if (iVar11 == 0) {

          fVar5 = *(float *)(DAT_00632ed8 + 0x1378);

        }

        else {

          fVar5 = *(float *)(DAT_00632ed8 + 0x1374);

        }

      }

      else {

        fVar5 = *(float *)(DAT_00632ed8 + 0xe34);

      }

      if (fVar5 * fVar5 <= *(float *)(dVar6 + 0x50)) break;

      dVar16 = param_1->animate_state;

      param_1->coll_radius = param_1->coll_radius | 8;

      iVar11 = *(int *)(dVar16 + 0x94);

      if (iVar11 == 0) {

        dVar18 = 0x28;

      }

      else {

        if (iVar11 != 1) {

          if (iVar11 != 2) {

            if (iVar11 != 3) {

              if (iVar11 == 4) {

                evilreaper_change_anim__FP6OBJECTii4SDKYf(param_1,0x37,0,0,0);

              }

              break;

            }

            goto LAB_004c98ae;

          }

          goto LAB_004c986d;

        }

        dVar18 = 0x41;

      }

    }

    else {

      fVar20 = (float10)dirfcalcp3d__FP3P3DT0(&param_1->field_0xa0,iVar11 + 0xa0);

      pfStack_5c = (float *)(float)fVar20;

      fVar20 = (float10)playerobj_turn(pfStack_5c,*(undefined4 *)&param_1->field_0xc8);

      if (ABS(fVar20) != (float10)0.0) {

        param_1->flags = param_1->flags | 0x1000000;

        param_1->waypoint2 = (dword)pfStack_5c;

        uVar9 = __ftol();

        param_1->field_0x208 = uVar9;

      }

      ai_move_update_goal(param_1,*(int *)(dVar6 + 0x3c) + 0xa0);

      iVar11 = *(int *)(dVar6 + 0x94);

      if (iVar11 == 0) {

        if (0.2 <= (float)param_1->pad_14) {

          bVar19 = (float)param_1->pad_14 < 0.3 |

                   (byte)((ushort)((ushort)((float)param_1->pad_14 == 0.3) << 0xe) >> 8);

          goto LAB_004c9700;

        }

      }

      else if (iVar11 == 1) {

        if (0.26666668 <= (float)param_1->pad_14) {

          bVar19 = (float)param_1->pad_14 < 0.36666667 |

                   (byte)((ushort)((ushort)((float)param_1->pad_14 == 0.36666667) << 0xe) >> 8);

          goto LAB_004c9700;

        }

      }

      else if (iVar11 == 2) {

        if (0.2 <= (float)param_1->pad_14) {

          bVar19 = (float)param_1->pad_14 < 0.3 |

                   (byte)((ushort)((ushort)((float)param_1->pad_14 == 0.3) << 0xe) >> 8);

          goto LAB_004c9700;

        }

      }

      else if (iVar11 == 3) {

        if (0.1 <= (float)param_1->pad_14) {

          bVar19 = (float)param_1->pad_14 < 0.23333333 |

                   (byte)((ushort)((ushort)((float)param_1->pad_14 == 0.23333333) << 0xe) >> 8);

LAB_004c9700:

          if ((POPCOUNT(bVar19) & 1U) != 0) {

            iVar11 = ObjIsMecc(*(undefined4 *)(dVar6 + 0x3c));

            if (iVar11 == 0) {

              iVar11 = ObjIsReaper(*(undefined4 *)(dVar6 + 0x3c));

              if (iVar11 == 0) {

                fVar5 = *(float *)(DAT_00632ed8 + 0x1378);

              }

              else {

                fVar5 = *(float *)(DAT_00632ed8 + 0x1374);

              }

            }

            else {

              fVar5 = *(float *)(DAT_00632ed8 + 0xe34);

            }

            if (*(float *)(dVar6 + 0x50) < fVar5 * fVar5) {

              obj_damage_apply(2,*(undefined4 *)(DAT_00632ed8 + 0xe2c),*(undefined4 *)(dVar6 + 0x3c)

                               ,param_1,0,0);

            }

          }

        }

      }

      else if ((iVar11 == 4) && (0.1 <= (float)param_1->pad_14)) {

        bVar19 = (float)param_1->pad_14 < 0.2 |

                 (byte)((ushort)((ushort)((float)param_1->pad_14 == 0.2) << 0xe) >> 8);

        goto LAB_004c9700;

      }

      if ((param_1->field_0x30 & 2) != 0) {

        iVar11 = *(int *)(dVar6 + 0x9c) + -1;

        *(int *)(dVar6 + 0x9c) = iVar11;

        if (iVar11 < 1) {

          fVar20 = (float10)rndfloatrange(*(undefined4 *)(dVar6 + 0x8c),

                                          *(undefined4 *)(dVar6 + 0x90));

          *(float *)(dVar6 + 0xa0) = (float)fVar20;

          iVar13 = crt_rand_scaled(100);

          iVar11 = *(int *)(DAT_00632ed8 + 0xedc);

          param_1->coll_radius = param_1->coll_radius & 0xfffffff7;

          param_1->pad_E4 = (uint)(iVar13 < iVar11) * 2 + 0xd;

        }

        else {

          dVar16 = param_1->animate_state;

          if (param_1->anim != 2) {

            ObjectSetAnim(param_1);

            *(undefined4 *)(dVar16 + 0xb4) = 2;

          }

          iVar11 = *(int *)(dVar6 + 0x94) + 1;

          *(int *)(dVar6 + 0x94) = iVar11;

          if (4 < iVar11) {

            *(undefined4 *)(dVar6 + 0x94) = 0;

          }

          param_1->coll_radius = param_1->coll_radius & 0xfffffff7;

        }

        break;

      }

      dVar16 = param_1->animate_state;

      iVar11 = *(int *)(dVar16 + 0x94);

      if (iVar11 == 0) {

        dVar18 = 0x28;

      }

      else if (iVar11 == 1) {

        dVar18 = 0x41;

      }

      else {

        if (iVar11 != 2) {

          if (iVar11 != 3) {

            if (iVar11 == 4) {

              evilreaper_change_anim__FP6OBJECTii4SDKYf(param_1,0x37,0,0,0);

            }

            break;

          }

LAB_004c98ae:

          evilreaper_change_anim__FP6OBJECTii4SDKYf(param_1,0x2a,0,0,0);

          break;

        }

LAB_004c986d:

        dVar18 = 0x29;

      }

    }

    if (param_1->anim == dVar18) break;

LAB_004c9894:

    ObjectSetAnim(param_1);

    *(dword *)(dVar16 + 0xb4) = dVar18;

    break;

  case 0x50:

    if ((param_1->field_0x30 & 2) != 0) {

      if (*(int *)(dVar6 + 0x3c) == 0) {

LAB_004c99d7:

        param_1->pad_E4 = 0x3c;

        break;

      }

      if ((*(int *)&param_1->field_0xe8 == 3) || (*(int *)&param_1->field_0xe8 == 4)) {

        uVar10 = *(undefined4 *)(DAT_00632ed8 + 0x15fc);

        uVar22 = *(undefined4 *)(DAT_00632ed8 + 0x15f8);

      }

      else {

        uVar10 = *(undefined4 *)(DAT_00632ed8 + 0xe3c);

        uVar22 = *(undefined4 *)(DAT_00632ed8 + 0xe38);

      }

      fVar20 = (float10)rndfloatrange(uVar22,uVar10);

      *(float *)(dVar6 + 0xa4) = (float)fVar20;

      iVar11 = *(int *)&param_1->field_0xe8;

      if ((iVar11 == 1) || (iVar11 == 4)) {

        param_1->pad_E4 = 0xc;

      }

      else if (iVar11 == 2) {

        sound_obj_seq_bigger();

      }

      else {

        sound_obj_seq_big(param_1);

      }

    }

    if (((0.33333334 <= (float)param_1->pad_14) && (*(float *)&param_1->field_0x18 < 0.33333334)) &&

       (iVar11 = *(int *)(dVar6 + 0x3c), iVar11 != 0)) {

      uStack_50 = *(undefined4 *)(iVar11 + 0xa0);

      uStack_4c = *(undefined4 *)(iVar11 + 0xa4);

      fStack_48 = *(float *)(iVar11 + 0x1e8) * *(float *)(iVar11 + 0xc4) + *(float *)(iVar11 + 0xa8)

      ;

      sound_obj_seq_small(param_1,0x20,&uStack_50,iVar11);

    }

    break;

  case 0x51:

    if ((param_1->field_0x30 & 2) != 0) {

      if ((*(int *)&param_1->field_0xe8 == 3) || (*(int *)&param_1->field_0xe8 == 4)) {

        uVar10 = *(undefined4 *)(DAT_00632ed8 + 0x15fc);

        uVar22 = *(undefined4 *)(DAT_00632ed8 + 0x15f8);

      }

      else {

        uVar10 = *(undefined4 *)(DAT_00632ed8 + 0xe3c);

        uVar22 = *(undefined4 *)(DAT_00632ed8 + 0xe38);

      }

      fVar20 = (float10)rndfloatrange(uVar22,uVar10);

      *(float *)(dVar6 + 0xa4) = (float)fVar20;

      iVar11 = *(int *)&param_1->field_0xe8;

      if ((iVar11 == 1) || (iVar11 == 4)) {

        param_1->pad_E4 = 0xc;

      }

      else if (iVar11 == 2) {

        sound_obj_seq_bigger();

      }

      else {

        sound_obj_seq_big(param_1);

      }

    }

    if ((0.33333334 <= (float)param_1->pad_14) && (*(float *)&param_1->field_0x18 < 0.33333334)) {

      iVar11 = *(int *)(dVar6 + 0x3c);

      if (iVar11 == 0) {

        uStack_50 = *(undefined4 *)(dVar6 + 0x40);

        uStack_4c = *(undefined4 *)(dVar6 + 0x44);

        fStack_48 = *(float *)(dVar6 + 0x48);

      }

      else {

        uStack_50 = *(undefined4 *)(iVar11 + 0xa0);

        uStack_4c = *(undefined4 *)(iVar11 + 0xa4);

        fStack_48 = *(float *)(iVar11 + 0xa8);

      }

      sound_obj_seq_small(param_1,0x21,&uStack_50,0);

    }

    break;

  case 0x52:

    if ((param_1->field_0x30 & 2) != 0) {

      dVar16 = param_1->animate_state;

      if (*(int *)(dVar16 + 0xdb0) == 0) {

        pOStack_1c = param_1;

        uStack_20 = 0;

        fStack_24 = 1.12104e-44;

        uVar10 = fx_get_free_effect__Fv();

        *(undefined4 *)(dVar16 + 0xdb0) = uVar10;

      }

      *(undefined4 *)(dVar16 + 0xdac) = *(undefined4 *)(DAT_00632ed8 + 0xe40);

      *(uint *)(*(int *)(dVar16 + 0xa8) + 0xd8) =

           *(uint *)(*(int *)(dVar16 + 0xa8) + 0xd8) | 0x40000000;

      *(uint *)(*(int *)(dVar16 + 0xac) + 0xd8) =

           *(uint *)(*(int *)(dVar16 + 0xac) + 0xd8) | 0x40000000;

      param_1->flags = param_1->flags | 0x40000000;

      param_1->coll_radius = param_1->coll_radius | 0x10;

      uVar10 = sound_get_free_sequence__Fv();

      *(undefined4 *)(dVar16 + 0xde4) = uVar10;

      if ((*(int *)&param_1->field_0xe8 == 3) || (*(int *)&param_1->field_0xe8 == 4)) {

        uVar10 = *(undefined4 *)(DAT_00632ed8 + 0x15fc);

        uVar22 = *(undefined4 *)(DAT_00632ed8 + 0x15f8);

      }

      else {

        uVar10 = *(undefined4 *)(DAT_00632ed8 + 0xe3c);

        uVar22 = *(undefined4 *)(DAT_00632ed8 + 0xe38);

      }

      fVar20 = (float10)rndfloatrange(uVar22,uVar10);

      *(float *)(dVar6 + 0xa4) = (float)fVar20;

      sound_obj_seq_big(param_1);

    }

    break;

  case 0x53:

    if ((param_1->field_0x30 & 2) != 0) {

      if ((*(int *)&param_1->field_0xe8 == 3) || (*(int *)&param_1->field_0xe8 == 4)) {

        uVar10 = *(undefined4 *)(DAT_00632ed8 + 0x15fc);

        uVar22 = *(undefined4 *)(DAT_00632ed8 + 0x15f8);

      }

      else {

        uVar10 = *(undefined4 *)(DAT_00632ed8 + 0xe3c);

        uVar22 = *(undefined4 *)(DAT_00632ed8 + 0xe38);

      }

      fVar20 = (float10)rndfloatrange(uVar22,uVar10);

      *(float *)(dVar6 + 0xa4) = (float)fVar20;

      param_1->pad_E4 = 0xd;

    }

    if ((0.33333334 <= (float)param_1->pad_14) && (*(float *)&param_1->field_0x18 < 0.33333334)) {

      sound_obj_seq_small(param_1,0x22,dVar6 + 0xdb4,0);

    }

    break;

  case 0x54:

    if ((param_1->field_0x30 & 2) != 0) {

      if ((*(int *)&param_1->field_0xe8 == 3) || (*(int *)&param_1->field_0xe8 == 4)) {

        uVar10 = *(undefined4 *)(DAT_00632ed8 + 0x15fc);

        uVar22 = *(undefined4 *)(DAT_00632ed8 + 0x15f8);

      }

      else {

        uVar10 = *(undefined4 *)(DAT_00632ed8 + 0xe3c);

        uVar22 = *(undefined4 *)(DAT_00632ed8 + 0xe38);

      }

      fVar20 = (float10)rndfloatrange(uVar22,uVar10);

      *(float *)(dVar6 + 0xa4) = (float)fVar20;

      physics_reset_a(param_1);

    }

    if ((0.33333334 <= (float)param_1->pad_14) && (*(float *)&param_1->field_0x18 < 0.33333334)) {

      sound_obj_seq_small(param_1,0x23,dVar6 + 0xdb4,0);

    }

    break;

  case 0x55:

    if ((param_1->field_0x30 & 2) == 0) break;

    puVar4 = (undefined4 *)(dVar6 + 0xdb4);

    fxb_firecircle_create(param_1,puVar4,0xffffffff,0xffffffff);

    ai_moveonly_set_goal(param_1,puVar4);

    ai_goal_process(param_1);

    param_1->coll_radius = param_1->coll_radius & 0xffffffbf;

    iVar11 = crt_rand_scaled(100);

    if ((iVar11 < *(int *)(DAT_00632ed8 + 0xee4)) || (*(int *)&param_1->field_0x168 == 0)) {

      dVar16 = param_1->animate_state;

      *(undefined4 *)(param_1->pad_104 + 4) = *(undefined4 *)(DAT_00632ed8 + 0xfe4);

      *(undefined4 *)(param_1->pad_104 + 8) = *(undefined4 *)(DAT_00632ed8 + 0xfe8);

      *(undefined4 *)(dVar16 + 0xdcc) = *puVar4;

      *(undefined4 *)(dVar16 + 0xdd0) = *(undefined4 *)(dVar6 + 0xdb8);

      *(undefined4 *)(dVar16 + 0xdd4) = *(undefined4 *)(dVar6 + 0xdbc);

      dVar18 = param_1->animate_state;

      PhysicsExZeroForce_dup004a17a0(param_1);

      iVar11 = dVar18 + 0xdcc;

      fVar20 = (float10)distancesq3d(&param_1->field_0xa0,iVar11);

      pfStack_5c = (float *)(float)fVar20;

      if ((*(int *)&param_1->field_0xe8 == 1) || (*(int *)&param_1->field_0xe8 == 4)) {

        fVar20 = (float10)powf();

        fVar20 = fVar20 * (float10)*(float *)(DAT_00632ed8 + 0x1654);

      }

      else {

        fVar20 = (float10)powf();

        fVar20 = fVar20 * (float10)*(float *)(DAT_00632ed8 + 0xfe0);

      }

      pfStack_5c = (float *)(float)fVar20;

      fStack_40 = 0.0;

      fStack_44 = 0.0;

      fStack_3c = (*(float *)(param_1->pad_104 + 4) / *(float *)(param_1->pad_104 + 8)) * -32.17405;

      trajectory_calculate(&param_1->pad_128,&param_1->field_0xa0,iVar11,&fStack_44,pfStack_5c);

      *(float *)&param_1->field_0xf0 = (float)pfStack_5c * 0.85;

      param_1->coll_radius = param_1->coll_radius | 4;

      uVar10 = sound_get_free_sequence__Fv();

      *(undefined4 *)(dVar16 + 0xde0) = uVar10;

      dVar16 = param_1->animate_state;

      if (param_1->anim != 0x5a) {

        ObjectSetAnim(param_1);

        *(undefined4 *)(dVar16 + 0xb4) = 0x5a;

      }

      param_1->pad_E4 = 0x13;

      break;

    }

LAB_004c9ee1:

    dVar16 = param_1->animate_state;

    if (param_1->anim != 2) {

      ObjectSetAnim(param_1);

      *(undefined4 *)(dVar16 + 0xb4) = 2;

    }

    param_1->pad_E4 = 0x56;

    break;

  case 0x56:

    param_1->anim_selector = (dword)&LAB_004cb930;

    ai_goal_process(param_1);

    uVar12 = param_1->coll_radius;

    if ((uVar12 & 0x40) == 0) {

      if (*(int *)&param_1->field_0x168 == 0) {

        if ((*(int *)&param_1->field_0xe8 == 3) || (*(int *)&param_1->field_0xe8 == 4)) {

          uVar10 = *(undefined4 *)(DAT_00632ed8 + 0x15fc);

          uVar22 = *(undefined4 *)(DAT_00632ed8 + 0x15f8);

        }

        else {

          uVar10 = *(undefined4 *)(DAT_00632ed8 + 0xe3c);

          uVar22 = *(undefined4 *)(DAT_00632ed8 + 0xe38);

        }

        fVar20 = (float10)rndfloatrange(uVar22,uVar10);

        *(float *)(dVar6 + 0xa4) = (float)fVar20;

        param_1->pad_E4 = 0xd;

      }

      break;

    }

LAB_004c7d68:

    dVar16 = param_1->animate_state;

    param_1->coll_radius = uVar12 & 0xffffffbf;

    if (param_1->anim != 0xb) {

      ObjectSetAnim(param_1);

      *(undefined4 *)(dVar16 + 0xb4) = 0xb;

    }

    if ((*(int *)&param_1->field_0xe8 == 3) || (*(int *)&param_1->field_0xe8 == 4)) {

      uVar10 = *(undefined4 *)(DAT_00632ed8 + 0x15fc);

      uVar22 = *(undefined4 *)(DAT_00632ed8 + 0x15f8);

    }

    else {

      uVar10 = *(undefined4 *)(DAT_00632ed8 + 0xe3c);

      uVar22 = *(undefined4 *)(DAT_00632ed8 + 0xe38);

    }

    fVar20 = (float10)rndfloatrange(uVar22,uVar10);

    *(float *)(dVar6 + 0xa4) = (float)fVar20;

    param_1->pad_E4 = 0x57;

    break;

  case 0x57:

    if ((param_1->field_0x30 & 2) != 0) {

      param_1->pad_E4 = 0xd;

    }

    break;

  case 0x58:

    if ((param_1->field_0x30 & 2) != 0) {

      reaper_create_fake_reaper__FP6OBJECTP3P3Dfi(param_1,dVar6 + 0xdb4);

      param_1->pad_E4 = 0xc;

    }

    break;

  case 100:

    if (param_1->anim == 0x6e) {

      if ((param_1->field_0x30 & 2) != 0) {

        dVar16 = param_1->animate_state;

        ObjectSetAnim(param_1);

        *(undefined4 *)(dVar16 + 0xb4) = 0x55;

      }

    }

    else if (param_1->anim != 0x55) {

      dVar16 = param_1->animate_state;

      ObjectSetAnim(param_1);

      *(undefined4 *)(dVar16 + 0xb4) = 0x6e;

    }

    break;

  case 0x6e:

    if ((param_1->field_0x30 & 2) != 0) {

      *(undefined4 *)(dVar6 + 0x68) = 0x41200000;

      dVar16 = param_1->animate_state;

      fVar20 = (float10)rndfloatrange(*(undefined4 *)(DAT_00632ed8 + 0xf08),

                                      *(undefined4 *)(DAT_00632ed8 + 0xf0c));

      pfStack_5c = (float *)(float)fVar20;

      fVar20 = (float10)rndfloatrange(0,0x43b40000,&fStack_54,&fStack_58);

      sine_cos_lookup((float)fVar20);

      *(float *)(dVar16 + 0xdb4) = fStack_54 * (float)pfStack_5c + *(float *)&param_1->field_0xa0;

      *(float *)(dVar16 + 0xdb8) = *(float *)&param_1->field_0xa4 - fStack_58 * (float)pfStack_5c;

      fVar20 = (float10)get_floor_z_point((float *)(dVar16 + 0xdb4));

      *(float *)(dVar16 + 0xdbc) = (float)fVar20;

      dVar16 = param_1->animate_state;

      if (param_1->anim != 0x61) {

        ObjectSetAnim(param_1);

        *(undefined4 *)(dVar16 + 0xb4) = 0x61;

      }

      param_1->pad_E4 = 0x58;

    }

    break;

  case 200:

    if (((param_1->field_0x30 & 2) != 0) && ((param_1->pad_DC & 0x20000) == 0)) {

      iVar11 = 0;

      piVar14 = (int *)(dVar6 + 0xd3c);

      do {

        if (*piVar14 != 0) {

          if (iVar11 < 4) {

            param_1->pad_DC = param_1->pad_DC | 0x20000;

            *(undefined4 *)&param_1->field_0xec = DAT_00632e6c;

          }

          break;

        }

        iVar11 = iVar11 + 1;

        piVar14 = piVar14 + 7;

      } while (iVar11 < 4);

    }

    if ((-1 < (char)param_1->coll_radius) &&

       (iVar11 = vimp_mana_effect(param_1,param_1,0,*(undefined4 *)(DAT_00632ed8 + 0x10fc),2),

       iVar11 != 0)) {

      param_1->coll_radius = param_1->coll_radius | 0x80;

    }

  }

  obj_alpha_fade_update(param_1);

  player_pitch_update(param_1);

  obj_vel_reset(param_1);

  PhysicsExApplyLocation(param_1);

  PhysicsExCalcControledModelSpeeds(param_1,0x41a00000,0x41a00000);

  obj_gravity_apply(param_1,1);

  PhysicsExApplyMoveControls(param_1);

  if (((param_1->coll_radius & 4) == 0) || ((param_1->coll_radius & 0x10) != 0)) {

    uVar10 = 0;

  }

  else {

    uVar10 = 1;

  }

  obj_yaw_turn(param_1,dVar6 + 0xb8,dVar6 + 0xbc,uVar10);

  pOVar21 = param_1;

  object_animate_process(param_1);

  param_1->flags = param_1->flags | 0x40;

  sound_player_user(param_1,dVar6 + 0xd3c,pOVar21,fVar26);

  reaper_firewall_hit(param_1,dVar6 + 0xdc0,dVar6 + 0xdc4,dVar6 + 0xdc8,0x20);

  dVar6 = param_1->animate_state;

  if ((param_1->coll_radius & 0x10) != 0) {

    fVar20 = (float10)FRateGetSecsframe(param_1,0);

    fVar20 = (float10)*(float *)(dVar6 + 0xdac) - fVar20;

    *(float *)(dVar6 + 0xdac) = (float)fVar20;

    if (fVar20 < (float10)0.0 != (fVar20 == (float10)0.0)) {

      fx_delete(*(undefined4 *)(dVar6 + 0xdb0));

      *(undefined4 *)(dVar6 + 0xdb0) = 0;

      param_1->flags = param_1->flags & 0xbfffffff;

      param_1->coll_radius = param_1->coll_radius & 0xffffffef;

      *(uint *)(*(int *)(dVar6 + 0xac) + 0xd8) =

           *(uint *)(*(int *)(dVar6 + 0xac) + 0xd8) & 0xbfffffff;

      sound_interrupt_sequence(dVar6 + 0xde4);

      return;

    }

    reaperbase_enemy_scan

              (param_1,*(undefined4 *)(DAT_00632ed8 + 0xf18),*(undefined4 *)(DAT_00632ed8 + 0xf1c));

  }

  return;

}

/* ===== evilreaper_get_turbo_loc__FP6OBJECTP3P3DfffT1 @ 0x004CA560 ===== */
/* PS2 candidate: evilreaper_get_turbo_loc__FP6OBJECTP3P3DfffT1 (conf 0.457) */



void evilreaper_get_turbo_loc__FP6OBJECTP3P3DfffT1

               (int param_1,float *param_2,float param_3,undefined4 param_4,undefined4 param_5,

               float *param_6)



{

  float *pfVar1;

  float *pfVar2;

  int iVar3;

  float10 fVar4;

  float10 fVar5;

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

  float local_34;

  undefined1 local_30 [8];

  float local_28;

  undefined1 local_20 [8];

  float local_18;

  undefined1 local_10 [8];

  float local_8;

  

  pfVar2 = param_6;

  if ((*(int *)(param_1 + 0xe8) != 2) ||

     (iVar3 = evilreaper_find_turbo_marker__FP6OBJECTP3P3Di

                        (param_1,param_6,*(undefined4 *)(DAT_00632ed8 + 0x121c)), iVar3 == 0)) {

    param_6 = (float *)0x0;

    pfVar1 = (float *)(param_1 + 0xa0);

    while( true ) {

      fVar4 = (float10)rndfloatrange(param_4,param_5);

      fVar5 = (float10)dirfcalcp3d__FP3P3DT0(pfVar1,param_2);

      fVar5 = (float10)rndfloatrange((float)(fVar5 - (float10)param_3),

                                     (float)((float10)param_3 + fVar5));

      sine_cos_lookup((float)fVar5,&local_5c,&local_58);

      *pfVar2 = local_5c * (float)fVar4 + *param_2;

      pfVar2[1] = param_2[1] - local_58 * (float)fVar4;

      fVar4 = (float10)get_floor_z_point(pfVar2);

      pfVar2[2] = (float)fVar4;

      if ((*(uint *)(param_1 + 0xe0) & 0x800) != 0) break;

      ai_fly_update_goal_4(pfVar2,local_30,&local_54);

      if (local_28 < 0.64278) {

        local_48 = *pfVar1 - *pfVar2;

        local_44 = *(float *)(param_1 + 0xa4) - pfVar2[1];

        local_40 = *(float *)(param_1 + 0xa8) - pfVar2[2];

        normalize__FPfN20(&local_48,&local_44,&local_40);

        local_3c = local_48 * *(float *)(DAT_006330e4 + 0x1c0) + *pfVar2;

        local_38 = local_44 * *(float *)(DAT_006330e4 + 0x1c0) + pfVar2[1];

        fVar4 = (float10)get_floor_z_point(&local_3c);

        local_34 = (float)fVar4;

        if (((*(uint *)(param_1 + 0xe0) & 0x800) != 0) ||

           ((ai_fly_update_goal_4(&local_3c,local_20,&local_50), 0.64278 <= local_18 &&

            (local_50 < -3.0 == (local_50 == -3.0))))) {

LAB_004ca808:

          *pfVar2 = local_3c;

          pfVar2[1] = local_38;

          pfVar2[2] = local_34;

          return;

        }

        local_48 = *pfVar2 - *pfVar1;

        local_44 = pfVar2[1] - *(float *)(param_1 + 0xa4);

        local_40 = pfVar2[2] - *(float *)(param_1 + 0xa8);

        normalize__FPfN20(&local_48,&local_44,&local_40);

        local_3c = local_48 * *(float *)(DAT_006330e4 + 0x1c0) + *pfVar2;

        local_38 = local_44 * *(float *)(DAT_006330e4 + 0x1c0) + pfVar2[1];

        fVar4 = (float10)get_floor_z_point(&local_3c);

        local_34 = (float)fVar4;

        if (((*(uint *)(param_1 + 0xe0) & 0x800) != 0) ||

           ((ai_fly_update_goal_4(&local_3c,local_10,&local_4c), 0.64278 <= local_8 &&

            (local_4c < -3.0 == (local_4c == -3.0))))) goto LAB_004ca808;

      }

      else if (local_54 < -3.0 == (local_54 == -3.0)) {

        return;

      }

      param_6 = (float *)((int)param_6 + 1);

      if (4 < (int)param_6) {

        return;

      }

    }

  }

  return;

}

/* ===== evilreaper_change_anim__FP6OBJECTii4SDKYf @ 0x004CA830 ===== */
/* PS2 candidate: evilreaper_change_anim__FP6OBJECTii4SDKYf (conf 0.797) */



void evilreaper_change_anim__FP6OBJECTii4SDKYf(OBJECT *param_1,dword param_2)



{

  dword dVar1;

  

  dVar1 = param_1->animate_state;

  if ((param_1->anim != param_2) && (ObjectSetAnim(param_1), param_2 != 0x89)) {

    *(dword *)(dVar1 + 0xb4) = param_2;

  }

  return;

}

/* ===== evilreaper_scan_for_enemy__FP6OBJECTf @ 0x004CA890 ===== */
/* PS2 candidate: evilreaper_scan_for_enemy__FP6OBJECTf (conf 0.392) */



void evilreaper_scan_for_enemy__FP6OBJECTf(float param_1,float param_2)



{

  undefined4 *puVar1;

  undefined4 *puVar2;

  int iVar3;

  bool bVar4;

  undefined4 *puVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  float10 fVar9;

  float local_2c;

  undefined4 local_18;

  undefined4 local_14;

  float local_10;

  undefined4 local_c;

  undefined4 local_8;

  float local_4;

  

  iVar6 = (int)param_1;

  iVar3 = *(int *)((int)param_1 + 0x100);

  bVar4 = false;

  iVar7 = ObjIsMecc(DAT_00632a88);

  if ((iVar7 == 0) || ((*(uint *)(DAT_00632a88 + 0x20c) & 0x40000) == 0)) {

    *(undefined4 *)(iVar3 + 0x3c) = 0;

    puVar5 = DAT_00632d6c;

    if (*(int *)((int)param_1 + 0xe8) == 2) {

      param_2 = -1.0;

      local_2c = -1.0;

    }

    else {

      local_2c = param_2;

      if (0.0 <= param_2) {

        local_2c = param_2 * param_2;

      }

    }

    for (; puVar5 != (undefined4 *)0x0; puVar5 = (undefined4 *)*puVar5) {

      iVar7 = puVar5[3];

      iVar8 = ObjIsPlayer(iVar7);

      if (((((iVar8 != 0) || (*(int *)(iVar7 + 0x1e0) == 0x55)) &&

           ((*(uint *)(iVar7 + 0xd8) & 0x4000c000) == 0)) &&

          (*(float *)(iVar7 + 0x278) < *(float *)(iVar7 + 0x1c0))) &&

         ((iVar8 = ObjIsMecc(iVar7), iVar8 == 0 || ((*(uint *)(iVar7 + 0xe0) & 0x2000000) == 0)))) {

        puVar1 = (undefined4 *)(iVar7 + 0xa0);

        puVar2 = (undefined4 *)(iVar6 + 0xa0);

        fVar9 = (float10)distancesq3d(puVar2,puVar1);

        param_1 = (float)fVar9;

        if (local_2c < 0.0) {

          local_2c = param_1 + 1.0;

        }

        iVar8 = ObjIsKabuto(iVar7);

        if (iVar8 != 0) {

          param_1 = param_1 * 0.25;

        }

        if (param_1 <= local_2c) {

          if (param_1 < 144.0) {

            bVar4 = true;

          }

          iVar8 = ObjIsKabuto(iVar7);

          if ((iVar8 != 0) && (param_1 < 10000.0)) {

            bVar4 = true;

          }

          if ((DAT_006328e8 - DAT_00632b44 < 1.0 == (DAT_006328e8 - DAT_00632b44 == 1.0)) ||

             (*(float *)(iVar3 + 0x54) == DAT_00632b44)) {

LAB_004caa99:

            if ((!bVar4) && (0.0 < param_2)) {

              fVar9 = (float10)dirfcalcp3d__FP3P3DT0(puVar2,puVar1);

              fVar9 = (float10)diff_angle((float)fVar9,*(undefined4 *)(iVar3 + 0x4c));

              if (fVar9 <= (float10)*(float *)(DAT_00632ed8 + 0xe90)) {

                local_c = *puVar2;

                local_8 = *(undefined4 *)(iVar6 + 0xa4);

                local_4 = *(float *)(iVar6 + 0x1e8) * *(float *)(iVar6 + 0xc4) +

                          *(float *)(iVar6 + 0xa8);

                local_18 = *puVar1;

                local_14 = *(undefined4 *)(iVar7 + 0xa4);

                local_10 = *(float *)(iVar7 + 0x1e8) * *(float *)(iVar7 + 0xc4) +

                           *(float *)(iVar7 + 0xa8);

                iVar8 = ai_class_filter(&local_c,&local_18,5,&DAT_005610e8,0);

                if (iVar8 != 0) goto LAB_004cab5d;

              }

              goto LAB_004cab6c;

            }

          }

          else {

            *(float *)(iVar3 + 0x54) = DAT_00632b44;

            fVar9 = (float10)distancesq2d__FP3P3DT0(puVar2,&DAT_00632b48);

            if ((float10)14400.0 <= fVar9) goto LAB_004caa99;

            bVar4 = true;

          }

LAB_004cab5d:

          local_2c = param_1;

          *(int *)(iVar3 + 0x3c) = iVar7;

        }

      }

LAB_004cab6c:

    }

    if (*(int *)(iVar3 + 0x3c) != 0) {

      fVar9 = (float10)distancesq3d(iVar6 + 0xa0,*(int *)(iVar3 + 0x3c) + 0xa0);

      *(float *)(iVar3 + 0x50) = (float)fVar9;

    }

  }

  return;

}

/* ===== evilreaper_verify_enemy__FP6OBJECTf @ 0x004CABB0 ===== */
/* PS2 candidate: evilreaper_verify_enemy__FP6OBJECTf (conf 0.45) */



void evilreaper_verify_enemy__FP6OBJECTf(int param_1,float param_2)



{

  int iVar1;

  int iVar2;

  float fVar3;

  int iVar4;

  uint uVar5;

  byte bVar6;

  float10 fVar7;

  undefined4 local_18;

  undefined4 local_14;

  float local_10;

  undefined4 local_c;

  undefined4 local_8;

  float local_4;

  

  iVar1 = *(int *)(param_1 + 0x100);

  iVar4 = ObjIsMecc(DAT_00632a88);

  if ((iVar4 != 0) && ((*(uint *)(DAT_00632a88 + 0x20c) & 0x40000) != 0)) {

    *(undefined4 *)(iVar1 + 0x3c) = 0;

  }

  iVar4 = ObjIsMecc(*(undefined4 *)(iVar1 + 0x3c));

  if ((iVar4 != 0) && ((*(uint *)(*(int *)(iVar1 + 0x3c) + 0xe0) & 0x2000000) != 0)) {

    *(undefined4 *)(iVar1 + 0x3c) = 0;

  }

  iVar4 = ObjIsReaper(*(undefined4 *)(iVar1 + 0x3c));

  if (iVar4 != 0) {

    if ((*(byte *)(*(int *)(iVar1 + 0x3c) + 0xe0) & 8) == 0) {

      *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xfffffbff;

    }

    else if ((*(uint *)(param_1 + 0xe0) & 0x400) == 0) {

      *(undefined4 *)(iVar1 + 0x3c) = 0;

      *(undefined4 *)(param_1 + 0xec) = 0;

      *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 0x400;

    }

  }

  if (*(int *)(param_1 + 0xe8) == 2) {

    return;

  }

  iVar4 = *(int *)(iVar1 + 0x3c);

  if ((((iVar4 == 0) || ((*(uint *)(iVar4 + 0xd8) & 0x4000c000) != 0)) ||

      (*(float *)(iVar4 + 0x1c0) <= *(float *)(iVar4 + 0x278))) ||

     (iVar4 = ObjIsPlayer(iVar4), iVar4 == 0)) {

LAB_004cacea:

    *(undefined4 *)(iVar1 + 0x3c) = 0;

  }

  else {

    iVar4 = ObjIsKabuto(*(undefined4 *)(iVar1 + 0x3c));

    if (iVar4 == 0) {

      if (0.0 < param_2) {

        bVar6 = param_2 * param_2 < *(float *)(iVar1 + 0x50) |

                (byte)((ushort)((ushort)(NAN(param_2 * param_2) || NAN(*(float *)(iVar1 + 0x50))) <<

                               10) >> 8);

        goto LAB_004cace3;

      }

    }

    else if (0.0 < param_2) {

      fVar3 = *(float *)(iVar1 + 0x50) * 0.25;

      bVar6 = param_2 * param_2 < fVar3 |

              (byte)((ushort)((ushort)(NAN(param_2 * param_2) || NAN(fVar3)) << 10) >> 8);

LAB_004cace3:

      if ((POPCOUNT(bVar6) & 1U) != 0) goto LAB_004cacea;

    }

  }

  fVar7 = (float10)FRateGetSecsframe(param_1,0);

  fVar7 = (float10)*(float *)(param_1 + 0xec) - fVar7;

  *(float *)(param_1 + 0xec) = (float)fVar7;

  if (fVar7 < (float10)0.0) {

    iVar4 = *(int *)(iVar1 + 0x3c);

    evilreaper_scan_for_enemy__FP6OBJECTf(param_1,param_2);

    iVar2 = *(int *)(iVar1 + 0x3c);

    if ((iVar2 != 0) && (iVar2 != iVar4)) {

      fVar7 = (float10)distancesq3d(param_1 + 0xa0,iVar2 + 0xa0);

      *(float *)(iVar1 + 0x50) = (float)fVar7;

    }

    if (*(int *)(iVar1 + 0x3c) == 0) {

      *(int *)(iVar1 + 0x3c) = iVar4;

    }

    *(undefined4 *)(param_1 + 0xec) = 0x40a00000;

  }

  if (*(int *)(iVar1 + 0x3c) == 0) {

    return;

  }

  fVar7 = (float10)FRateGetSecsframe(param_1,0);

  fVar7 = (float10)*(float *)(iVar1 + 0x58) - fVar7;

  *(float *)(iVar1 + 0x58) = (float)fVar7;

  if ((float10)0.0 <= fVar7) goto LAB_004cae45;

  if ((*(byte *)(param_1 + 0xe0) & 2) == 0) {

    *(undefined4 *)(iVar1 + 0x58) = 0x3f800000;

  }

  else {

    *(undefined4 *)(iVar1 + 0x58) = 0x3e800000;

  }

  iVar4 = *(int *)(*(int *)(param_1 + 0x100) + 0x3c);

  if (iVar4 == 0) {

LAB_004cae37:

    uVar5 = *(uint *)(param_1 + 0xe0) | 1;

  }

  else {

    local_c = *(undefined4 *)(param_1 + 0xa0);

    local_8 = *(undefined4 *)(param_1 + 0xa4);

    local_4 = *(float *)(param_1 + 0x1e8) * *(float *)(param_1 + 0xc4) + *(float *)(param_1 + 0xa8);

    local_18 = *(undefined4 *)(iVar4 + 0xa0);

    local_14 = *(undefined4 *)(iVar4 + 0xa4);

    local_10 = *(float *)(iVar4 + 0x1e8) * *(float *)(iVar4 + 0xc4) + *(float *)(iVar4 + 0xa8);

    iVar4 = ai_class_filter(&local_c,&local_18,5,&DAT_005610e8,0);

    if (iVar4 == 0) goto LAB_004cae37;

    uVar5 = *(uint *)(param_1 + 0xe0) & 0xfffffffe;

  }

  *(uint *)(param_1 + 0xe0) = uVar5;

LAB_004cae45:

  if ((*(byte *)(param_1 + 0xe0) & 1) == 0) {

    *(undefined4 *)(iVar1 + 0x5c) = 0;

  }

  else {

    fVar7 = (float10)FRateGetSecsframe(param_1,0);

    fVar7 = fVar7 + (float10)*(float *)(iVar1 + 0x5c);

    *(float *)(iVar1 + 0x5c) = (float)fVar7;

    if ((float10)20.0 < fVar7) {

      *(undefined4 *)(iVar1 + 0x3c) = 0;

      return;

    }

  }

  return;

}

/* ===== physics_reset_c @ 0x004CAE90 ===== */
float10 physics_reset_c(int param_1)



{

  int iVar1;

  float10 fVar2;

  undefined4 local_c;

  undefined4 local_8;

  float local_4;

  

  iVar1 = *(int *)(param_1 + 0x100);

  PhysicsExZeroForce_dup004a17a0(param_1);

  iVar1 = iVar1 + 0xdcc;

  distancesq3d(param_1 + 0xa0,iVar1);

  if ((*(int *)(param_1 + 0xe8) == 1) || (*(int *)(param_1 + 0xe8) == 4)) {

    fVar2 = (float10)powf();

    fVar2 = fVar2 * (float10)*(float *)(DAT_00632ed8 + 0x1654);

  }

  else {

    fVar2 = (float10)powf();

    fVar2 = fVar2 * (float10)*(float *)(DAT_00632ed8 + 0xfe0);

  }

  local_8 = 0;

  local_c = 0;

  local_4 = (*(float *)(*(int *)(param_1 + 0x104) + 4) / *(float *)(*(int *)(param_1 + 0x104) + 8))

            * -32.17405;

  trajectory_calculate(param_1 + 0x128,param_1 + 0xa0,iVar1,&local_c,(float)fVar2);

  return (float10)(float)fVar2;

}

/* ===== sound_obj_seq_big @ 0x004CAF60 ===== */
void sound_obj_seq_big(OBJECT *param_1)



{

  dword dVar1;

  int iVar2;

  undefined4 uVar3;

  float10 fVar4;

  

  dVar1 = param_1->animate_state;

  if ((*(int *)&param_1->field_0xe8 == 3) || (*(int *)&param_1->field_0xe8 == 4)) {

    *(undefined4 *)(dVar1 + 0x74) = *(undefined4 *)(DAT_00632ed8 + 0x1628);

    *(undefined4 *)(dVar1 + 0x78) = *(undefined4 *)(DAT_00632ed8 + 0x162c);

    *(undefined4 *)(dVar1 + 0x7c) = *(undefined4 *)(DAT_00632ed8 + 0x1630);

    *(undefined4 *)(dVar1 + 0x80) = *(undefined4 *)(DAT_00632ed8 + 0x1634);

    *(undefined4 *)(dVar1 + 0x8c) = *(undefined4 *)(DAT_00632ed8 + 0x1638);

    uVar3 = *(undefined4 *)(DAT_00632ed8 + 0x163c);

  }

  else {

    *(undefined4 *)(dVar1 + 0x74) = *(undefined4 *)(DAT_00632ed8 + 0xe14);

    *(undefined4 *)(dVar1 + 0x78) = *(undefined4 *)(DAT_00632ed8 + 0xe18);

    *(undefined4 *)(dVar1 + 0x7c) = *(undefined4 *)(DAT_00632ed8 + 0xe1c);

    *(undefined4 *)(dVar1 + 0x80) = *(undefined4 *)(DAT_00632ed8 + 0xe20);

    *(undefined4 *)(dVar1 + 0x8c) = *(undefined4 *)(DAT_00632ed8 + 0xe24);

    uVar3 = *(undefined4 *)(DAT_00632ed8 + 0xe28);

  }

  *(undefined4 *)(dVar1 + 0x90) = uVar3;

  uVar3 = rndintrange(*(undefined4 *)(dVar1 + 0x74),*(undefined4 *)(dVar1 + 0x78));

  *(undefined4 *)(dVar1 + 0x9c) = uVar3;

  fVar4 = (float10)rndfloatrange(*(undefined4 *)(dVar1 + 0x7c),*(undefined4 *)(dVar1 + 0x80));

  *(float *)(dVar1 + 0xa0) = (float)fVar4;

  *(undefined4 *)(dVar1 + 0x94) = 0;

  if (((*(uint *)(*(int *)(dVar1 + 0xac) + 0xd8) & 0x40000000) != 0) &&

     ((param_1->coll_radius & 0x10) == 0)) {

    sound_play_obj(0x334);

    dVar1 = param_1->animate_state;

    if (param_1->anim != 0x3e) {

      ObjectSetAnim(param_1);

      *(undefined4 *)(dVar1 + 0xb4) = 0x3e;

    }

    param_1->pad_E4 = 0x29;

    return;

  }

  dVar1 = param_1->animate_state;

  if (*(float *)(DAT_00632ed8 + 0xe30) * *(float *)(DAT_00632ed8 + 0xe30) < *(float *)(dVar1 + 0x50)

     ) {

    iVar2 = *(int *)(dVar1 + 0x3c);

    *(undefined4 *)(param_1->pad_104 + 4) = *(undefined4 *)(DAT_00632ed8 + 0xfe4);

    *(undefined4 *)(param_1->pad_104 + 8) = *(undefined4 *)(DAT_00632ed8 + 0xfe8);

    *(undefined4 *)(dVar1 + 0xdcc) = *(undefined4 *)(iVar2 + 0xa0);

    *(undefined4 *)(dVar1 + 0xdd0) = *(undefined4 *)(iVar2 + 0xa4);

    *(undefined4 *)(dVar1 + 0xdd4) = *(undefined4 *)(iVar2 + 0xa8);

    fVar4 = (float10)physics_reset_c(param_1);

    *(float *)&param_1->field_0xf0 = (float)(fVar4 * (float10)0.85);

    param_1->coll_radius = param_1->coll_radius | 4;

    uVar3 = sound_get_free_sequence__Fv();

    *(undefined4 *)(dVar1 + 0xde0) = uVar3;

    dVar1 = param_1->animate_state;

    if (param_1->anim != 0x5a) {

      ObjectSetAnim(param_1);

      *(undefined4 *)(dVar1 + 0xb4) = 0x5a;

    }

    param_1->pad_E4 = 0x46;

    return;

  }

  if (param_1->anim != 2) {

    ObjectSetAnim(param_1);

    *(undefined4 *)(dVar1 + 0xb4) = 2;

  }

  param_1->pad_E4 = 0x47;

  return;

}

/* ===== sound_obj_seq_bigger @ 0x004CB220 ===== */
void sound_obj_seq_bigger(OBJECT *param_1)



{

  dword dVar1;

  dword dVar2;

  undefined4 uVar3;

  int iVar4;

  float10 fVar5;

  undefined4 local_c;

  undefined4 local_8;

  undefined4 local_4;

  

  dVar1 = param_1->animate_state;

  if ((*(int *)&param_1->field_0xe8 == 3) || (*(int *)&param_1->field_0xe8 == 4)) {

    *(undefined4 *)(dVar1 + 0x6c) = *(undefined4 *)(DAT_00632ed8 + 0x1600);

    *(undefined4 *)(dVar1 + 0x70) = *(undefined4 *)(DAT_00632ed8 + 0x1604);

    *(undefined4 *)(dVar1 + 0x74) = *(undefined4 *)(DAT_00632ed8 + 0x1608);

    *(undefined4 *)(dVar1 + 0x78) = *(undefined4 *)(DAT_00632ed8 + 0x160c);

    *(undefined4 *)(dVar1 + 0x7c) = *(undefined4 *)(DAT_00632ed8 + 0x1610);

    *(undefined4 *)(dVar1 + 0x80) = *(undefined4 *)(DAT_00632ed8 + 0x1614);

    *(undefined4 *)(dVar1 + 0x84) = *(undefined4 *)(DAT_00632ed8 + 0x1658);

    *(undefined4 *)(dVar1 + 0x88) = *(undefined4 *)(DAT_00632ed8 + 0x165c);

    *(undefined4 *)(dVar1 + 0x8c) = *(undefined4 *)(DAT_00632ed8 + 0x1620);

    uVar3 = *(undefined4 *)(DAT_00632ed8 + 0x1624);

  }

  else {

    *(undefined4 *)(dVar1 + 0x6c) = *(undefined4 *)(DAT_00632ed8 + 0xe4c);

    *(undefined4 *)(dVar1 + 0x70) = *(undefined4 *)(DAT_00632ed8 + 0xe50);

    *(undefined4 *)(dVar1 + 0x74) = *(undefined4 *)(DAT_00632ed8 + 0xe44);

    *(undefined4 *)(dVar1 + 0x78) = *(undefined4 *)(DAT_00632ed8 + 0xe48);

    *(undefined4 *)(dVar1 + 0x7c) = *(undefined4 *)(DAT_00632ed8 + 0xe54);

    *(undefined4 *)(dVar1 + 0x80) = *(undefined4 *)(DAT_00632ed8 + 0xed4);

    *(undefined4 *)(dVar1 + 0x84) = *(undefined4 *)(DAT_00632ed8 + 0xed0);

    *(undefined4 *)(dVar1 + 0x88) = *(undefined4 *)(DAT_00632ed8 + 0xecc);

    *(undefined4 *)(dVar1 + 0x8c) = *(undefined4 *)(DAT_00632ed8 + 0xec8);

    uVar3 = *(undefined4 *)(DAT_00632ed8 + 0xec4);

  }

  *(undefined4 *)(dVar1 + 0x90) = uVar3;

  uVar3 = rndintrange(*(undefined4 *)(dVar1 + 0x6c),*(undefined4 *)(dVar1 + 0x70));

  *(undefined4 *)(dVar1 + 0x98) = uVar3;

  uVar3 = rndintrange(*(undefined4 *)(dVar1 + 0x74),*(undefined4 *)(dVar1 + 0x78));

  *(undefined4 *)(dVar1 + 0x9c) = uVar3;

  if ((*(uint *)(*(int *)(dVar1 + 0xa8) + 0xd8) & 0x40000000) == 0) {

    iVar4 = crt_rand_scaled(100);

    if (((iVar4 < *(int *)(DAT_00632ed8 + 0x1368)) && (*(int *)&param_1->field_0xe8 != 1)) &&

       (*(int *)&param_1->field_0xe8 != 4)) {

      dVar1 = param_1->animate_state;

      evilreaper_get_turbo_loc__FP6OBJECTP3P3DfffT1

                (param_1,*(int *)(dVar1 + 0x3c) + 0xa0,0x41a00000,

                 *(undefined4 *)(DAT_00632ed8 + 0xe7c),*(undefined4 *)(DAT_00632ed8 + 0xe80),

                 &local_c);

      collgrid_collide_d(param_1,&param_1->field_0xa0,&local_c);

      fVar5 = (float10)dirfcalcp3d__FP3P3DT0(&param_1->field_0xa0,&local_c);

      *(float *)&param_1->field_0xc8 = (float)fVar5;

      dVar2 = param_1->animate_state;

      *(undefined4 *)(param_1->pad_104 + 4) = *(undefined4 *)(DAT_00632ed8 + 0xfe4);

      *(undefined4 *)(param_1->pad_104 + 8) = *(undefined4 *)(DAT_00632ed8 + 0xfe8);

      *(undefined4 *)(dVar2 + 0xdcc) = local_c;

      *(undefined4 *)(dVar2 + 0xdd0) = local_8;

      *(undefined4 *)(dVar2 + 0xdd4) = local_4;

      fVar5 = (float10)physics_reset_c(param_1);

      *(float *)&param_1->field_0xf0 = (float)(fVar5 * (float10)0.85);

      param_1->coll_radius = param_1->coll_radius | 4;

      uVar3 = sound_get_free_sequence__Fv();

      *(undefined4 *)(dVar2 + 0xde0) = uVar3;

      evilreaper_change_anim__FP6OBJECTii4SDKYf(param_1,0x5a,1,0,0);

      sound_play_obj(0x38f);

      dVar2 = param_1->animate_state;

      if (param_1->anim != 0x81) {

        ObjectSetAnim(param_1);

        *(undefined4 *)(dVar2 + 0xb4) = 0x81;

      }

      fVar5 = (float10)rndfloatrange(*(undefined4 *)(dVar1 + 0x7c),*(undefined4 *)(dVar1 + 0x80));

      *(float *)(dVar1 + 0xa0) = (float)fVar5;

      param_1->pad_E4 = 0x14;

      return;

    }

    sound_play_obj(0x38f);

    dVar1 = param_1->animate_state;

    if (param_1->anim != 0x7b) {

      ObjectSetAnim(param_1);

      *(undefined4 *)(dVar1 + 0xb4) = 0x7b;

    }

    param_1->pad_E4 = 0x32;

    return;

  }

  sound_play_obj(0x3c7);

  dVar1 = param_1->animate_state;

  if (param_1->anim != 0x3d) {

    ObjectSetAnim(param_1);

    *(undefined4 *)(dVar1 + 0xb4) = 0x3d;

  }

  param_1->pad_E4 = 0x28;

  return;

}

/* ===== sound_obj_seq_small @ 0x004CB630 ===== */
void sound_obj_seq_small(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)



{

  int iVar1;

  float10 fVar2;

  float10 fVar3;

  undefined4 local_50;

  undefined4 local_4c;

  undefined4 local_48;

  uint local_44 [4];

  undefined4 local_34;

  undefined4 local_24;

  undefined4 local_14;

  

  playerobj_eval_refpt(param_1,0,&local_50);

  fVar2 = (float10)dirucalcp3d__FP3P3DT0(&local_50,param_3);

  fVar3 = (float10)dirfcalcp3d__FP3P3DT0(&local_50,param_3);

  local_44[0] = 0;

  GEO_MatBuildXYZ(local_44,-(float)fVar2,0,(float)fVar3);

  local_24 = local_4c;

  local_44[0] = local_44[0] | 0x10;

  local_34 = local_50;

  local_14 = local_48;

  iVar1 = PROJ_Create3(param_2,*(undefined4 *)(param_1 + 0x18c),param_1,0,local_44,param_4);

  *(int *)(iVar1 + 0x274) = param_1;

  switch(param_2) {

  case 0x20:

  case 0x21:

  case 0x23:

    sound_play_obj(0x3ad);

    break;

  case 0x22:

    sound_play_obj(0x3a3);

    return;

  }

  return;

}

/* ===== evilreaper_fire_bow__FP6OBJECT @ 0x004CB730 ===== */
/* PS2 candidate: evilreaper_fire_bow__FP6OBJECT (conf 0.533) */



void evilreaper_fire_bow__FP6OBJECT(int param_1)



{

  int iVar1;

  int iVar2;

  float10 fVar3;

  float10 fVar4;

  undefined4 local_5c;

  undefined4 local_58;

  float local_54;

  undefined4 local_50;

  undefined4 local_4c;

  undefined4 local_48;

  uint local_44 [4];

  undefined4 local_34;

  undefined4 local_24;

  undefined4 local_14;

  

  iVar1 = *(int *)(param_1 + 0x100);

  playerobj_eval_refpt(*(undefined4 *)(iVar1 + 0xa8),0,&local_50);

  iVar2 = *(int *)(iVar1 + 0x3c);

  if (iVar2 == 0) {

    local_5c = *(undefined4 *)(iVar1 + 0x40);

    local_58 = *(undefined4 *)(iVar1 + 0x44);

    local_54 = *(float *)(iVar1 + 0x48);

  }

  else {

    local_5c = *(undefined4 *)(iVar2 + 0xa0);

    local_58 = *(undefined4 *)(iVar2 + 0xa4);

    local_54 = *(float *)(*(int *)(iVar1 + 0x3c) + 0x1e8) *

               *(float *)(*(int *)(iVar1 + 0x3c) + 0xc4) + *(float *)(iVar2 + 0xa8);

  }

  fVar3 = (float10)dirucalcp3d__FP3P3DT0(&local_50,&local_5c);

  fVar4 = (float10)dirfcalcp3d__FP3P3DT0(&local_50,&local_5c);

  local_44[0] = 0;

  GEO_MatBuildXYZ(local_44,-(float)fVar3,0,(float)fVar4);

  local_24 = local_4c;

  local_34 = local_50;

  local_44[0] = local_44[0] | 0x10;

  local_14 = local_48;

  iVar2 = PROJ_Create3(0x16,*(undefined4 *)(param_1 + 0x18c),param_1,0,local_44,0);

  *(int *)(iVar2 + 0x274) = param_1;

  *(int *)(iVar1 + 0x9c) = *(int *)(iVar1 + 0x9c) + -1;

  sound_play_obj(0x38d);

  return;

}

/* ===== evilreaper_select_firewall_loc__FP6OBJECT @ 0x004CB860 ===== */
/* PS2 candidate: evilreaper_select_firewall_loc__FP6OBJECT (conf 0.435) */



void evilreaper_select_firewall_loc__FP6OBJECT(int param_1)



{

  int iVar1;

  int iVar2;

  float10 fVar3;

  float10 fVar4;

  float local_8;

  float local_4;

  

  iVar1 = *(int *)(param_1 + 0x100);

  fVar3 = (float10)rndfloatrange(*(undefined4 *)(DAT_00632ed8 + 0xef0),

                                 *(undefined4 *)(DAT_00632ed8 + 0xef4));

  fVar4 = (float10)dirfcalcp3d__FP3P3DT0(*(int *)(iVar1 + 0x3c) + 0xa0,param_1 + 0xa0);

  fVar4 = (float10)rndfloatrange((float)(fVar4 - (float10)*(float *)(DAT_00632ed8 + 0xef8)),

                                 (float)((float10)*(float *)(DAT_00632ed8 + 0xef8) + fVar4));

  sine_cos_lookup((float)fVar4,&local_8,&local_4);

  iVar2 = *(int *)(iVar1 + 0x3c);

  *(float *)(iVar1 + 0xdb4) = local_8 * (float)fVar3 + *(float *)(iVar2 + 0xa0);

  *(float *)(iVar1 + 0xdb8) = *(float *)(iVar2 + 0xa4) - local_4 * (float)fVar3;

  *(undefined4 *)(iVar1 + 0xdbc) = *(undefined4 *)(iVar2 + 0xa8);

  return;

}

/* ===== evilreaper_set_new_location__FP6OBJECTi @ 0x004CB960 ===== */
/* PS2 candidate: evilreaper_set_new_location__FP6OBJECTi (conf 0.467) */



void evilreaper_set_new_location__FP6OBJECTi(int param_1,int param_2)



{

  undefined4 uVar1;

  int iVar2;

  int iVar3;

  float10 fVar4;

  float10 fVar5;

  undefined4 uVar6;

  float local_14;

  float local_10;

  float local_c;

  float local_8;

  undefined4 local_4;

  

  iVar2 = *(int *)(param_1 + 0x100);

  if (*(int *)(iVar2 + 0x3c) != 0) {

    if (param_2 == 0) {

      iVar3 = crt_rand_scaled(100);

    }

    else {

      iVar3 = *(int *)(iVar2 + 0xb0);

    }

    if (iVar3 < *(int *)(DAT_00632ed8 + 0xe78)) {

      uVar6 = *(undefined4 *)(DAT_00632ed8 + 0xe80);

      uVar1 = *(undefined4 *)(DAT_00632ed8 + 0xe7c);

    }

    else {

      uVar6 = *(undefined4 *)(DAT_00632ed8 + 0xe88);

      uVar1 = *(undefined4 *)(DAT_00632ed8 + 0xe84);

    }

    fVar4 = (float10)rndfloatrange(uVar1,uVar6);

    *(int *)(iVar2 + 0xb0) = iVar3;

    fVar5 = (float10)dirfcalcp3d__FP3P3DT0(*(int *)(iVar2 + 0x3c) + 0xa0,param_1 + 0xa0);

    fVar5 = (float10)rndfloatrange((float)(fVar5 - (float10)20.0),(float)((float10)20.0 + fVar5));

    sine_cos_lookup((float)fVar5,&local_14,&local_10);

    local_c = local_14 * (float)fVar4 + *(float *)(*(int *)(iVar2 + 0x3c) + 0xa0);

    local_8 = *(float *)(*(int *)(iVar2 + 0x3c) + 0xa4) - local_10 * (float)fVar4;

    local_4 = *(undefined4 *)(*(int *)(iVar2 + 0x3c) + 0xa8);

    collgrid_collide_d(param_1,param_1 + 0xa0,&local_c);

    *(undefined1 **)(param_1 + 0x16c) = &LAB_004cb930;

    ai_moveonly_set_goal(param_1,&local_c);

  }

  return;

}

/* ===== evilreaper_find_turbo_marker__FP6OBJECTP3P3Di @ 0x004CBA90 ===== */
/* PS2 candidate: evilreaper_find_turbo_marker__FP6OBJECTP3P3Di (conf 0.452) */



undefined4

evilreaper_find_turbo_marker__FP6OBJECTP3P3Di(int param_1,undefined4 *param_2,float param_3)



{

  int iVar1;

  bool bVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int *piVar6;

  float10 fVar7;

  

  iVar1 = *(int *)(param_1 + 0x100);

  iVar5 = 0;

  iVar3 = crt_rand_scaled(100);

  bVar2 = (int)param_3 <= iVar3;

  piVar6 = DAT_00632d68;

  if (DAT_00632d68 != (int *)0x0) {

    do {

      iVar3 = piVar6[3];

      if ((((*(int *)(iVar3 + 4) == 0x2a7) && (iVar4 = __ftol(), *(int *)(iVar3 + 0xe8) == iVar4))

          && ((*(int *)(iVar3 + 0x174) == 0 || (bVar2)))) &&

         (((fVar7 = (float10)distancesq2d__FP3P3DT0(iVar3 + 0xa0,param_1 + 0xa0), iVar5 == 0 ||

           ((float10)param_3 < fVar7)) && ((float10)25.0 < fVar7)))) {

        param_3 = (float)fVar7;

        iVar5 = iVar3;

      }

      piVar6 = (int *)*piVar6;

    } while (piVar6 != (int *)0x0);

    if (iVar5 != 0) {

      *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 0x100;

      *param_2 = *(undefined4 *)(iVar5 + 0xa0);

      param_2[1] = *(undefined4 *)(iVar5 + 0xa4);

      param_2[2] = *(undefined4 *)(iVar5 + 0xa8);

      *(int *)(iVar1 + 0xdd8) = iVar5;

      return 1;

    }

  }

  return 0;

}

/* ===== physics_reset_a @ 0x004CBB90 ===== */
void physics_reset_a(OBJECT *param_1)



{

  undefined1 *puVar1;

  dword dVar2;

  dword dVar3;

  int iVar4;

  undefined4 uVar5;

  float10 fVar6;

  undefined4 uVar7;

  undefined4 local_18;

  undefined4 local_14;

  undefined4 local_10;

  undefined4 local_c;

  undefined4 local_8;

  float local_4;

  

  dVar2 = param_1->animate_state;

  if ((*(int *)&param_1->field_0xe8 != 1) && (*(int *)&param_1->field_0xe8 != 4)) {

    iVar4 = crt_rand_scaled(100);

    if (iVar4 < *(int *)(DAT_00632ed8 + 0xe78)) {

      uVar5 = *(undefined4 *)(DAT_00632ed8 + 0xe80);

      uVar7 = *(undefined4 *)(DAT_00632ed8 + 0xe7c);

      iVar4 = *(int *)(dVar2 + 0x3c);

    }

    else {

      uVar5 = *(undefined4 *)(DAT_00632ed8 + 0xe88);

      iVar4 = *(int *)(dVar2 + 0x3c);

      uVar7 = *(undefined4 *)(DAT_00632ed8 + 0xe84);

    }

    evilreaper_get_turbo_loc__FP6OBJECTP3P3DfffT1

              (param_1,iVar4 + 0xa0,0x41a00000,uVar7,uVar5,&local_18);

    puVar1 = &param_1->field_0xa0;

    collgrid_collide_d(param_1,puVar1,&local_18);

    fVar6 = (float10)dirfcalcp3d__FP3P3DT0(puVar1,&local_18);

    *(float *)&param_1->field_0xc8 = (float)fVar6;

    dVar2 = param_1->animate_state;

    *(undefined4 *)(param_1->pad_104 + 4) = *(undefined4 *)(DAT_00632ed8 + 0xfe4);

    *(undefined4 *)(param_1->pad_104 + 8) = *(undefined4 *)(DAT_00632ed8 + 0xfe8);

    *(undefined4 *)(dVar2 + 0xdcc) = local_18;

    *(undefined4 *)(dVar2 + 0xdd0) = local_14;

    *(undefined4 *)(dVar2 + 0xdd4) = local_10;

    dVar3 = param_1->animate_state;

    PhysicsExZeroForce_dup004a17a0(param_1);

    iVar4 = dVar3 + 0xdcc;

    distancesq3d(puVar1,iVar4);

    if ((*(int *)&param_1->field_0xe8 == 1) || (*(int *)&param_1->field_0xe8 == 4)) {

      fVar6 = (float10)powf();

      fVar6 = fVar6 * (float10)*(float *)(DAT_00632ed8 + 0x1654);

    }

    else {

      fVar6 = (float10)powf();

      fVar6 = fVar6 * (float10)*(float *)(DAT_00632ed8 + 0xfe0);

    }

    local_8 = 0;

    local_c = 0;

    local_4 = (*(float *)(param_1->pad_104 + 4) / *(float *)(param_1->pad_104 + 8)) * -32.17405;

    trajectory_calculate(&param_1->pad_128,puVar1,iVar4,&local_c,(float)fVar6);

    *(float *)&param_1->field_0xf0 = (float)fVar6 * 0.85;

    param_1->coll_radius = param_1->coll_radius | 4;

    uVar5 = sound_get_free_sequence__Fv();

    *(undefined4 *)(dVar2 + 0xde0) = uVar5;

    dVar2 = param_1->animate_state;

    if (param_1->anim != 0x5a) {

      ObjectSetAnim(param_1);

      *(undefined4 *)(dVar2 + 0xb4) = 0x5a;

    }

    param_1->pad_E4 = 0x12;

    return;

  }

  param_1->pad_E4 = 0xc;

  return;

}

/* ===== physics_reset_d @ 0x004CBDF0 ===== */
undefined4 physics_reset_d(int param_1)



{

  int iVar1;

  uint uVar2;

  float10 fVar3;

  undefined4 local_c;

  undefined4 local_8;

  float local_4;

  

  iVar1 = *(int *)(param_1 + 0x100);

  if ((*(uint *)(param_1 + 0xe0) & 0x200) == 0) {

    if (((*(float *)(param_1 + 0xf0) < 0.0 != (*(float *)(param_1 + 0xf0) == 0.0)) &&

        ((**(byte **)(param_1 + 0x104) & 0x44) != 0)) || (*(int *)(param_1 + 0x220) != 0)) {

      *(undefined4 *)(*(int *)(param_1 + 0x104) + 4) = *(undefined4 *)(DAT_00632ed8 + 0x704);

      *(undefined4 *)(*(int *)(param_1 + 0x104) + 8) = *(undefined4 *)(DAT_00632ed8 + 0x708);

      *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xfffffffb;

      sound_interrupt_sequence(iVar1 + 0xde0);

      *(undefined4 *)(param_1 + 0x128) = 0;

      *(undefined4 *)(param_1 + 300) = 0;

      *(undefined4 *)(param_1 + 0x130) = 0;

      uVar2 = *(uint *)(param_1 + 0xe0);

      if ((uVar2 & 0x100) != 0) {

        *(uint *)(param_1 + 0xe0) = uVar2 & 0xfffffeff | 0x800;

        iVar1 = *(int *)(iVar1 + 0xdd8);

        if (*(int *)(iVar1 + 0x174) != 0) {

          *(undefined4 *)(param_1 + 0xa0) = *(undefined4 *)(iVar1 + 0xa0);

          *(undefined4 *)(param_1 + 0xa4) = *(undefined4 *)(iVar1 + 0xa4);

          *(undefined4 *)(param_1 + 0xa8) = *(undefined4 *)(iVar1 + 0xa8);

        }

        *(undefined4 *)(param_1 + 0x128) = 0;

        *(undefined4 *)(param_1 + 300) = 0;

        *(undefined4 *)(param_1 + 0x130) = 0;

        return 1;

      }

      *(uint *)(param_1 + 0xe0) = uVar2 & 0xfffff7ff;

      return 1;

    }

    if (0.0 < *(float *)(param_1 + 0xf0)) {

      PhysicsExZeroForce_dup004a17a0(param_1);

      distancesq3d(param_1 + 0xa0,iVar1 + 0xdcc);

      if ((*(int *)(param_1 + 0xe8) == 1) || (*(int *)(param_1 + 0xe8) == 4)) {

        fVar3 = (float10)powf();

        fVar3 = fVar3 * (float10)*(float *)(DAT_00632ed8 + 0x1654);

      }

      else {

        fVar3 = (float10)powf();

        fVar3 = fVar3 * (float10)*(float *)(DAT_00632ed8 + 0xfe0);

      }

      local_8 = 0;

      local_c = 0;

      local_4 = (*(float *)(*(int *)(param_1 + 0x104) + 4) /

                *(float *)(*(int *)(param_1 + 0x104) + 8)) * -32.17405;

      trajectory_calculate(param_1 + 0x128,param_1 + 0xa0,iVar1 + 0xdcc,&local_c,(float)fVar3);

      fVar3 = (float10)FRateGetSecsframe(param_1,0);

      *(float *)(param_1 + 0xf0) = (float)((float10)*(float *)(param_1 + 0xf0) - fVar3);

    }

  }

  else {

    ai_goal_process(param_1);

    if (*(int *)(param_1 + 0x168) == 0) {

      iVar1 = *(int *)(iVar1 + 0xdd8);

      *(undefined4 *)(param_1 + 0xa0) = *(undefined4 *)(iVar1 + 0xa0);

      *(undefined4 *)(param_1 + 0xa4) = *(undefined4 *)(iVar1 + 0xa4);

      *(undefined4 *)(param_1 + 0xa8) = *(undefined4 *)(iVar1 + 0xa8);

      *(undefined4 *)(param_1 + 0x128) = 0;

      *(undefined4 *)(param_1 + 300) = 0;

      *(undefined4 *)(param_1 + 0x130) = 0;

      *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xfffffdff | 0x800;

      return 1;

    }

  }

  return 0;

}

/* ===== health_full_check_c100 @ 0x004CC050 ===== */
void health_full_check_c100(int param_1)



{

  if (*(float *)(param_1 + 0x1c0) <= *(float *)(param_1 + 0x278)) {

    *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) | 0x40000000;

    *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) | 0x8000;

    return;

  }

  return;

}

/* ===== ret_const_xde8_c99 @ 0x004CC080 ===== */
undefined4 ret_const_xde8_c99(void)



{

  return 0xde8;

}

/* ===== reaper_shrink_handler_c99 @ 0x004CC090 ===== */
void reaper_shrink_handler_c99(int param_1,float param_2,OBJECT *param_3,float param_4)



{

  dword dVar1;

  undefined4 *puVar2;

  float fVar3;

  OBJECT *obj;

  int iVar4;

  int iVar5;

  uint uVar6;

  dword dVar7;

  dword dVar8;

  float10 fVar9;

  undefined4 uVar10;

  OBJECT *pOVar11;

  

  iVar4 = (int)param_4;

  obj = param_3;

  dVar1 = param_3->animate_state;

  if (param_3->pad_E4 == 200) {

    if ((*(int *)&param_3->field_0xe8 != 2) &&

       (fVar3 = param_2 + *(float *)&param_3->field_0x278, *(float *)&param_3->field_0x278 = fVar3,

       *(float *)(DAT_00632ed8 + 0xc50) + *(float *)&param_3->field_0x1c0 <= fVar3)) {

      func_0x004cc610(param_3,param_4);

      return;

    }

  }

  else if ((*(float *)&param_3->field_0x278 < *(float *)&param_3->field_0x1c0) &&

          ((param_4 == 0.0 || (*(OBJECT **)((int)param_4 + 0x274) != param_3)))) {

    uVar6 = param_3->coll_radius & 0x10;

    if (uVar6 == 0) {

      *(float *)&param_3->field_0x278 = param_2 + *(float *)&param_3->field_0x278;

    }

    if (*(float *)&param_3->field_0x1c0 <= *(float *)&param_3->field_0x278) {

      reaper_release_shrink(param_3,dVar1 + 0xd3c);

      uVar10 = 0x6a8;

      pOVar11 = obj;

      sound_play_obj(0x6a8);

      sound_stop_obj(0x6a3,obj,uVar10,pOVar11);

      sound_stop_obj(0x6a4,obj);

      sound_stop_obj(0x6a5,obj);

      sound_stop_obj(0x6a6,obj);

      sound_stop_obj(0x6a7,obj);

      iVar4 = ObjIsKabuto(DAT_00632a88);

      if (iVar4 == 0) {

        fVar9 = (float10)rndfloatrange(0,0x40c8f5c3);

        pOVar11 = (OBJECT *)(float)fVar9;

        param_3 = pOVar11;

        math_sin_lut_read_b(pOVar11);

        math_sin_lut_read_a(pOVar11);

        iVar4 = object_allocate_type(0x311,0);

        object_change_ospec(iVar4,0x25);

        puVar2 = *(undefined4 **)(iVar4 + 0x100);

        *(undefined4 *)(iVar4 + 0xa0) = *(undefined4 *)&obj->field_0xa0;

        *(undefined4 *)(iVar4 + 0xa4) = *(undefined4 *)&obj->field_0xa4;

        *(undefined4 *)(iVar4 + 0xa8) = *(undefined4 *)&obj->field_0xa8;

        *(uint *)(iVar4 + 0xd8) = *(uint *)(iVar4 + 0xd8) | 0x40000000;

        *(uint *)(iVar4 + 0xe0) = *(uint *)(iVar4 + 0xe0) | 1;

        puVar2[3] = obj;

        puVar2[4] = 0x3f800000;

        puVar2[5] = 0x41f00000;

        *puVar2 = 0x24;

        fx_get_free_effect__Fv();

        puVar2[1] = *(undefined4 *)(DAT_00632ed8 + 0x1078);

        *(uint *)(iVar4 + 0xe0) = *(uint *)(iVar4 + 0xe0) | 2;

      }

      fVar3 = param_2 + *(float *)&obj->field_0x278;

      *(float *)&obj->field_0x278 = fVar3;

      if (((fVar3 < *(float *)(DAT_00632ed8 + 0xc50) + *(float *)&obj->field_0x1c0) ||

          (*(int *)&obj->field_0xe8 == 2)) &&

         ((*(int *)&obj->field_0x210 == 0 ||

          ((iVar4 = *(int *)(*(int *)&obj->field_0x210 + 0x1e0), iVar4 != 1 && (iVar4 != 0x4c))))))

      {

        dVar8 = obj->animate_state;

        *(undefined4 *)&obj->field_0x278 = *(undefined4 *)&obj->field_0x1c0;

        dVar7 = 0x8a;

        if ((obj->flags & 0x800) == 0) {

          dVar7 = 99;

        }

        if (obj->anim != dVar7) {

          ObjectSetAnim(obj);

          *(dword *)(dVar8 + 0xb4) = dVar7;

        }

        *(undefined4 *)(dVar1 + 0x3c) = 0;

        obj->pad_E4 = 200;

        return;

      }

      func_0x004cc610(obj,param_4);

      *(undefined4 *)(dVar1 + 0x3c) = 0;

      return;

    }

    if ((*(int *)&param_3->field_0x210 == 0) ||

       ((iVar5 = *(int *)(*(int *)&param_3->field_0x210 + 0x1e0), iVar5 != 1 && (iVar5 != 0x4c)))) {

      if ((param_1 == 0x17) &&

         (((((param_3->coll_radius & 4) == 0 && (uVar6 == 0)) && (param_3->pad_E4 != 0x6e)) &&

          (*(float *)(dVar1 + 0x68) < 0.0 != (*(float *)(dVar1 + 0x68) == 0.0))))) {

        iVar4 = crt_rand_scaled(100);

        dVar1 = obj->animate_state;

        dVar8 = 0xa0;

        if (0x31 < iVar4) {

          dVar8 = 0x9f;

        }

        if (obj->anim != dVar8) {

          ObjectSetAnim(obj);

          *(dword *)(dVar1 + 0xb4) = dVar8;

        }

        obj->pad_E4 = 0x6e;

        return;

      }

      if ((0.0 < param_2) && (*(float *)(dVar1 + 0xddc) < 0.0)) {

        iVar5 = crt_rand_scaled(100);

        if (iVar5 < 0x14) {

          iVar5 = 0x6a3;

        }

        else if (iVar5 < 0x28) {

          iVar5 = 0x6a4;

        }

        else if (iVar5 < 0x3c) {

          iVar5 = 0x6a5;

        }

        else if (iVar5 < 0x50) {

          iVar5 = 0x6a6;

        }

        else {

          iVar5 = 0x6a7;

        }

        sound_play_obj(iVar5);

        *(undefined4 *)(dVar1 + 0xddc) = 0x41200000;

      }

      if (*(int *)(dVar1 + 0x3c) == 0) {

        if ((iVar4 == 0) || (iVar4 = *(int *)(iVar4 + 0x274), iVar4 == 0)) {

          iVar4 = DAT_00632a88;

        }

        *(int *)(dVar1 + 0x3c) = iVar4;

        obj->pad_E4 = 0xd;

        *(undefined4 *)(dVar1 + 0x58) = 0x3f800000;

      }

      if ((((*(float *)(DAT_00632ed8 + 0xf00) <

             *(float *)&obj->field_0x278 / *(float *)&obj->field_0x1c0) &&

           (*(int *)&obj->field_0xe8 != 1)) && (*(int *)&obj->field_0xe8 != 4)) &&

         ((iVar4 = crt_rand_scaled(100), iVar4 < *(int *)(DAT_00632ed8 + 0xf04) &&

          (((int)obj->pad_E4 < 0x50 || (0x58 < (int)obj->pad_E4)))))) {

        dVar1 = obj->animate_state;

        fVar9 = (float10)rndfloatrange(*(undefined4 *)(DAT_00632ed8 + 0xf08),

                                       *(undefined4 *)(DAT_00632ed8 + 0xf0c));

        param_4 = (float)fVar9;

        fVar9 = (float10)rndfloatrange(0,0x43b40000,&param_2,&param_3);

        sine_cos_lookup((float)fVar9);

        *(float *)(dVar1 + 0xdb4) = param_2 * param_4 + *(float *)&obj->field_0xa0;

        *(float *)(dVar1 + 0xdb8) = *(float *)&obj->field_0xa4 - (float)param_3 * param_4;

        fVar9 = (float10)get_floor_z_point((float *)(dVar1 + 0xdb4));

        *(float *)(dVar1 + 0xdbc) = (float)fVar9;

        dVar1 = obj->animate_state;

        if (obj->anim != 0x61) {

          ObjectSetAnim(obj);

          *(undefined4 *)(dVar1 + 0xb4) = 0x61;

        }

        obj->pad_E4 = 0x58;

      }

    }

  }

  return;

}

/* ===== ptr_clear_c99 @ 0x004CC6F0 ===== */
void ptr_clear_c99(int param_1)



{

  int iVar1;

  int iVar2;

  

  iVar1 = *(int *)(param_1 + 0x100);

  obj_ptr_clear_if_dead(iVar1 + 0x3c);

  obj_ptr_clear_if_dead(iVar1 + 0xdc0);

  obj_ptr_clear_if_dead(iVar1 + 0xdd8);

  iVar1 = iVar1 + 0xd3c;

  iVar2 = 4;

  do {

    obj_ptr_clear_if_dead(iVar1);

    iVar1 = iVar1 + 0x1c;

    iVar2 = iVar2 + -1;

  } while (iVar2 != 0);

  return;

}

/* ===== destroy_only_c99 @ 0x004CC750 ===== */
void destroy_only_c99(int param_1)



{

  int iVar1;

  undefined4 *puVar2;

  

  for (puVar2 = DAT_00632d68; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {

    iVar1 = puVar2[3];

    if ((*(int *)(iVar1 + 0x1e0) == 0x3e) &&

       ((*(int *)(iVar1 + 0x274) == param_1 || (*(int *)(iVar1 + 0x274) == 0)))) {

      func_0x00455c30(iVar1,1);

      object_destroy(iVar1);

    }

  }

  return;

}

/* ===== yaw_turn_spec_once @ 0x004CC7A0 ===== */
void yaw_turn_spec_once(int param_1)



{

  if ((*(byte *)(param_1 + 0xe0) & 4) != 0) {

    obj_yaw_turn(param_1,*(int *)(param_1 + 0x100) + 0xb8,*(int *)(param_1 + 0x100) + 0xbc,0);

    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xfffffffb;

  }

  return;

}

/* ===== ai_island_init @ 0x004CC7E0 ===== */
void ai_island_init(void)



{

  audio_register_sound_name(s_AIsland_005611c7 + 1);

  if (0 < DAT_00633244) {

    dlog_entry_alloc();

  }

  audio_stream_tied();

  return;

}

/* ===== dome_render_text @ 0x004CC810 ===== */
void dome_render_text(void)



{

  float10 fVar1;

  char *pcStack_8;

  undefined4 *puStack_4;

  

  audio_register_sound_name(s_InDome_005611d0);

  (**(code **)(DAT_00656420 + 0x18))(DAT_00656420,&DAT_00561138);

  (**(code **)(DAT_00656430 + 0xc))(DAT_00656430,1);

  (**(code **)(DAT_00656430 + 0x10))(DAT_00656430,1);

  render_get_clip_nearfar(&pcStack_8,&puStack_4);

  FNT_StringRender__FPcP14FNT_RenderInfo(pcStack_8,(undefined4 *)0x46dac000);

  fVar1 = (float10)render_get_aspect(0);

  fVar1 = (float10)render_get_fov((float)fVar1);

  render_projection_set((float)fVar1);

  dlog_scene_submit();

  FNT_StringRender__FPcP14FNT_RenderInfo(pcStack_8,puStack_4);

  fVar1 = (float10)render_get_aspect(1);

  fVar1 = (float10)render_get_fov((float)fVar1);

  render_projection_set((float)fVar1);

  if (DAT_00633244 < 1) {

    dlog_entry_alloc();

    return;

  }

  return;

}

/* ===== controlShutdown__Fv @ 0x004CC8D0 ===== */
/* PS2 candidate: controlShutdown__Fv (conf 0.695) */



void controlShutdown__Fv(void)



{

  int *piVar1;

  

  piVar1 = &DAT_005a6c8c;

  do {

    if (*piVar1 != 0) {

      object_free_all_allocated_data((OBJECT *)(piVar1 + -1));

    }

    *piVar1 = 0;

    piVar1 = piVar1 + 0xc1;

  } while ((int)piVar1 < 0x5a84ac);

  return;

}

/* ===== ShopMenuSlotCollision__Fi @ 0x004CC900 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* PS2 candidate: ShopMenuSlotCollision__Fi (conf 0.41) */



void ShopMenuSlotCollision__Fi(void)



{

  float fVar1;

  int iVar2;

  int iVar3;

  undefined4 uVar4;

  int iVar5;

  int iVar6;

  int *piVar7;

  undefined *puVar8;

  dword *pdVar9;

  int *piVar10;

  int *piVar11;

  float *pfVar12;

  float *pfVar13;

  float10 fVar14;

  dword *pdStack_244;

  int iStack_240;

  int iStack_23c;

  float fStack_238;

  int *local_234;

  undefined *local_22c;

  float fStack_228;

  float fStack_224;

  float fStack_220;

  undefined4 uStack_21c;

  undefined4 uStack_218;

  int iStack_214;

  float fStack_210;

  float local_20c;

  float local_208;

  float local_204;

  float local_1fc [4];

  float fStack_1ec;

  float fStack_1e8;

  float fStack_1e4;

  float fStack_1e0;

  undefined4 uStack_1d4;

  int iStack_1d0;

  undefined4 uStack_1cc;

  undefined4 *puStack_1c8;

  int iStack_1c4;

  char *pcStack_1c0;

  dword local_1bc [2];

  float fStack_1b4;

  float fStack_1b0;

  float fStack_1ac;

  float fStack_1a8;

  undefined4 local_178;

  undefined4 local_174;

  undefined4 local_170;

  int aiStack_16c [8];

  int aiStack_14c [8];

  int local_12c [8];

  undefined1 auStack_10c [64];

  undefined1 auStack_cc [68];

  undefined1 auStack_88 [68];

  undefined1 auStack_44 [68];

  

  local_234 = (int *)0x0;

  local_22c = (undefined *)0x0;

  if (DAT_005a84dc == 0) {

    local_20c = 0.0;

    local_208 = 5.0;

    local_204 = 0.0;

    local_1fc[0] = 0.0;

    local_1fc[1] = 1.0;

    local_1fc[2] = 0.0;

    local_178 = 0;

    local_174 = 0;

    local_170 = 0x3f800000;

    GEO_MatLookAt(local_1bc,&local_20c,local_1fc,&local_178);

    (*(code *)PTR_crt_matrix_copy_init_00580c1c)(local_1bc,local_1bc);

    GEO_MatTranspose(&DAT_005a6c40,local_1bc);

    DAT_005a84dc = 1;

  }

  piVar7 = local_12c;

  for (iVar6 = 8; iVar6 != 0; iVar6 = iVar6 + -1) {

    *piVar7 = -1;

    piVar7 = piVar7 + 1;

  }

  iStack_240 = 0;

  if (DAT_00632a88 == 0) {

    return;

  }

  iVar6 = ObjIsMecc(DAT_00632a88);

  if (iVar6 == 0) {

    iVar6 = ObjIsReaper(DAT_00632a88);

    if (iVar6 == 0) {

      iVar6 = ObjIsKabuto(DAT_00632a88);

      if (iVar6 != 0) {

        fVar14 = (float10)reaper_spec_float_get(DAT_00632a88);

        if (fVar14 <= (float10)0.0) {

          return;

        }

        uVar4 = __ftol(&local_20c,10);

        crt_itoa_wrapper(uVar4);

        object_stop_movement((OBJECT *)local_1bc);

        fStack_1b4 = fStack_1b4 * 0.25;

        fStack_1ac = 0.9;

        fStack_1b0 = fStack_1b0 * 0.25;

        fStack_1a8 = 0.1;

        FNT_RenderInfoProcess__FP14FNT_RenderInfof(local_1bc,DAT_006328e0);

        pdVar9 = local_1bc;

        pfVar12 = &local_20c;

        uVar4 = AudioGetMasterVolume__Fv_3();

        flick_text_layout(uVar4,pfVar12,pdVar9);

        return;

      }

      if (*(int *)(DAT_00632a88 + 0x1e0) != 0x2c) {

        return;

      }

      aiStack_16c[0] = 0x287;

      aiStack_14c[0] = NAM_DictionaryGetTotalNames_2(DAT_00632a88);

      iStack_240 = 1;

      goto LAB_004ccbc0;

    }

    local_234 = (int *)&DAT_00577584;

    local_22c = &DAT_005775a4;

    iVar6 = ObjIsJetski(*(undefined4 *)(DAT_00632a88 + 0x210));

    if (iVar6 != 0) {

      iVar6 = *(int *)(*(int *)(DAT_00632a88 + 0x210) + 0x100);

      aiStack_14c[0] = *(int *)(iVar6 + 0x70);

      aiStack_14c[1] = *(undefined4 *)(iVar6 + 0x6c);

      aiStack_14c[2] = *(undefined4 *)(iVar6 + 0x74);

      aiStack_16c[0] = 0x44c;

      aiStack_16c[1] = 1099;

      aiStack_16c[2] = 0x44d;

      iStack_240 = 3;

      goto LAB_004ccbc0;

    }

    iVar6 = *(int *)(DAT_00632a88 + 0x100);

    pdStack_244 = (dword *)(aiStack_14c + 1);

    iStack_240 = 1;

    aiStack_16c[0] = 0x29d;

    local_12c[0] = 0x4a;

    local_1bc[0] = 0x3f800000;

    aiStack_14c[0] = -1;

    piVar7 = aiStack_16c + 1;

    pdVar9 = local_1bc + 1;

    piVar10 = local_12c + 1;

    iVar5 = 0;

    do {

      iVar2 = IconDefWieldType(*(undefined4 *)(iVar6 + 0xd78 + iVar5 * 8),1);

      *piVar7 = iVar2;

      *piVar10 = *(int *)(iVar6 + 0xd78 + iVar5 * 8);

      *pdVar9 = 0x3f800000;

      if (iVar5 == 0) {

        *pdStack_244 = -1;

      }

      else {

        *pdStack_244 = *(int *)(iVar6 + 0xd7c + iVar5 * 8);

      }

      pdStack_244 = pdStack_244 + 1;

      piVar7 = piVar7 + 1;

      pdVar9 = pdVar9 + 1;

      piVar10 = piVar10 + 1;

      iStack_240 = iStack_240 + 1;

      iVar5 = iVar5 + 1;

    } while (iVar5 < 4);

    piVar11 = (int *)(iVar6 + 0xd98);

    fStack_238 = 2.8026e-45;

    do {

      if (*piVar11 != -1) {

        iVar2 = IconDef_0x50_get(*piVar11);

        iVar6 = piVar11[1];

        iVar5 = *piVar11;

        *piVar7 = iVar2;

        *pdStack_244 = iVar6;

        pdStack_244 = pdStack_244 + 1;

        *piVar10 = iVar5;

        *pdVar9 = 0x3f4ccccd;

        piVar7 = piVar7 + 1;

        pdVar9 = pdVar9 + 1;

        piVar10 = piVar10 + 1;

        iStack_240 = iStack_240 + 1;

      }

      piVar11 = piVar11 + 2;

      fStack_238 = (float)((int)fStack_238 + -1);

    } while (fStack_238 != 0.0);

  }

  else {

    pdStack_244 = local_1bc;

    piVar7 = aiStack_16c;

    piVar10 = aiStack_14c;

    piVar11 = local_12c;

    local_234 = &DAT_00577544;

    local_22c = &DAT_00577564;

    iStack_23c = 0;

    do {

      iVar6 = WeaponIdGetPresent(DAT_00632a88,iStack_23c);

      if (iVar6 < 0x4b) {

        *pdStack_244 = 0x3f800000;

        *piVar11 = iVar6;

        iVar5 = IconDef_0x50_get(iVar6);

        *piVar7 = iVar5;

        if (iStack_23c == 0) {

          iVar6 = mecc_in_gyro(DAT_00632a88);

          if ((iVar6 == 0) || (iVar6 = mine_find_of_owner(DAT_00632a88), iVar6 == 0)) {

            *piVar10 = -1;

          }

          else {

            iVar6 = *(int *)(iVar6 + 0xe8);

            *piVar7 = 0x288;

            *piVar10 = iVar6;

            *piVar11 = 5;

          }

        }

        else {

          iVar6 = item_get_ammo(DAT_00632a88,iVar6,0);

          *piVar10 = iVar6;

        }

        pdStack_244 = pdStack_244 + 1;

        piVar7 = piVar7 + 1;

        piVar11 = piVar11 + 1;

        piVar10 = piVar10 + 1;

        iStack_240 = iStack_240 + 1;

      }

      else {

        error_msg_show(s_Error__Bad_gun_index_005611d8);

      }

      iStack_23c = iStack_23c + 1;

    } while (iStack_23c < 4);

    iStack_23c = 0;

    do {

      iVar6 = OtherInvIdGet(DAT_00632a88,iStack_23c);

      if (iVar6 < 0x4b) {

        *pdStack_244 = 0x3f4ccccd;

        *piVar11 = iVar6;

        iVar5 = IconDef_0x50_get(iVar6);

        *piVar7 = iVar5;

        iVar6 = item_get_ammo(DAT_00632a88,iVar6,0);

        *piVar10 = iVar6;

        pdStack_244 = pdStack_244 + 1;

        piVar7 = piVar7 + 1;

        piVar11 = piVar11 + 1;

        piVar10 = piVar10 + 1;

        iStack_240 = iStack_240 + 1;

      }

      else {

        error_msg_show(s_Error__Bad_gun_index_005611d8);

      }

      iStack_23c = iStack_23c + 1;

    } while (iStack_23c < 3);

    iVar6 = mecc_in_gyro(DAT_00632a88);

    if ((iVar6 != 0) && (iVar6 = mine_find_of_owner(DAT_00632a88), iVar6 != 0)) {

      *piVar10 = *(int *)(iVar6 + 0xf4);

      iStack_240 = iStack_240 + 1;

      *piVar7 = 0x328;

    }

  }

  if (iStack_240 == 0) {

    return;

  }

LAB_004ccbc0:

  fVar14 = (float10)render_get_fov();

  fStack_228 = (float)fVar14;

  fVar14 = (float10)render_get_aspect();

  fStack_224 = (float)fVar14;

  XFGetViewport_2(&fStack_1e4);

  view_matrix_get(auStack_10c);

  render_get_clip_nearfar(&pcStack_1c0,&puStack_1c8);

  FNT_StringRender__FPcP14FNT_RenderInfo((char *)0x40400000,(undefined4 *)0x4b989680);

  iStack_23c = 0;

  if (0 < iStack_240) {

    iStack_1c4 = (int)local_1bc - (int)local_234;

    iStack_1d0 = (int)aiStack_16c - (int)local_234;

    iVar6 = (int)local_12c - (int)local_234;

    puVar8 = &DAT_005a6f1c;

    piVar7 = local_234;

    iStack_214 = iVar6;

    do {

      iVar5 = *(int *)(iStack_1d0 + (int)piVar7);

      if (iVar5 != 0) {

        iVar6 = *(int *)(iVar6 + (int)piVar7);

        if (local_234 == (int *)0x0) {

          pdStack_244 = (dword *)(fStack_1e4 * _DAT_005611b8);

          fStack_238 = fStack_1e0 * _DAT_005611b8;

          if (iVar6 < 0) {

            fStack_220 = (fStack_1e0 * (float)(&DAT_0056117c)[iStack_23c * 2] +

                         fStack_1e0 * (float)(&DAT_0056117c)[iStack_23c * 2]) - fStack_238 * 0.5;

            fStack_210 = (fStack_1e4 * (float)(&DAT_00561178)[iStack_23c * 2] +

                         fStack_1e4 * (float)(&DAT_00561178)[iStack_23c * 2]) -

                         (float)pdStack_244 * 0.5;

            XFSetViewportRegion(fStack_210,fStack_220,pdStack_244,fStack_238);

            (**(code **)(DAT_00656420 + 0xa4))

                      (DAT_00656420,fStack_210,fStack_220,pdStack_244,fStack_238);

          }

        }

        else {

          iVar2 = *piVar7 * 0x58;

          uStack_21c = *(undefined4 *)(&DAT_00562544 + iVar2);

          pdStack_244 = (dword *)(*(float *)(&DAT_00562550 + iVar2) -

                                 *(float *)(&DAT_00562544 + iVar2));

          uStack_218 = *(undefined4 *)(&DAT_00562548 + iVar2);

          fStack_238 = *(float *)(&DAT_00562554 + iVar2) - *(float *)(&DAT_00562548 + iVar2);

          if (iVar6 < 0) {

            XFSetViewportRegion(uStack_21c,uStack_218,pdStack_244,fStack_238);

            (**(code **)(DAT_00656420 + 0xa4))

                      (DAT_00656420,uStack_21c,uStack_218,pdStack_244,fStack_238);

          }

          if ((((DAT_00633104 != 0) && (iVar2 = ObjIsMecc(DAT_00632a88), iVar2 != 0)) &&

              (iVar2 = player_can_use_ammo__FP6OBJECTi(), iVar2 == iVar6)) &&

             (iVar2 = player_can_use_ammo__FP6OBJECTi(), -1 < iVar2)) {

            iVar3 = *piVar7 * 0x58;

            iVar2 = *(int *)(*(int *)(DAT_00632918 + 0x510) + 8);

            shopmenu_slot_text_draw

                      (&DAT_00632900,0x24,2,0,0x3f800000,0x3f800000,

                       ((*(float *)(&DAT_00562550 + iVar3) + *(float *)(&DAT_00562544 + iVar3)) *

                        0.5 - (*(float *)(iVar2 + 0x40) - *(float *)(iVar2 + 0x34)) * 0.5) /

                       (float)DAT_00632924,

                       ((*(float *)(&DAT_00562554 + iVar3) + *(float *)(&DAT_00562548 + iVar3)) *

                        0.5 - (*(float *)(iVar2 + 0x44) - *(float *)(iVar2 + 0x38)) * 0.5) /

                       (float)DAT_00632928);

            shopmenu_slot_entries_push(&DAT_00632900,0x24,2);

          }

        }

        if (iVar6 < 0) {

          view_matrix_reset(&DAT_005a6c44);

          render_projection_set(0x42700000,(float)pdStack_244 / fStack_238,0);

          xfmat_mult_a();

          if (*(int *)(puVar8 + -0x290) == 0) {

            objobj_type_lookup(iVar5,puVar8 + -0x294);

          }

          else if (*(int *)(puVar8 + -0x290) != iVar5) {

            object_free_all_allocated_data((OBJECT *)(puVar8 + -0x294));

            objobj_type_lookup(iVar5,(OBJECT *)(puVar8 + -0x294));

          }

          pfVar12 = (float *)(*(int *)(*(int *)(puVar8 + -0x28c) + 0x400) + 0x44);

          pfVar13 = local_1fc;

          for (iVar6 = 6; iVar6 != 0; iVar6 = iVar6 + -1) {

            *pfVar13 = *pfVar12;

            pfVar12 = pfVar12 + 1;

            pfVar13 = pfVar13 + 1;

          }

          local_20c = (local_1fc[3] + local_1fc[0]) * -0.5;

          local_208 = (fStack_1ec + local_1fc[1]) * -0.5;

          local_204 = (fStack_1e8 + local_1fc[2]) * -0.5;

          GEO_MatIdentityScale

                    (auStack_88,

                     5.0 / SQRT((fStack_1e8 - local_1fc[2]) * (fStack_1e8 - local_1fc[2]) +

                                (fStack_1ec - local_1fc[1]) * (fStack_1ec - local_1fc[1]) +

                                (local_1fc[3] - local_1fc[0]) * (local_1fc[3] - local_1fc[0])));

          mat_identity_translation(auStack_cc,&local_20c);

          GEO_MatFromQuat_2(auStack_44,DAT_005a84e0);

          (*(code *)PTR_crt_matrix_mul_00580c18)(puVar8,auStack_cc,auStack_88);

          (*(code *)PTR_crt_matrix_mul_00580c18)(puVar8,auStack_44,puVar8);

          *(uint *)(puVar8 + -0x1bc) = *(uint *)(puVar8 + -0x1bc) | 0x20;

          uVar4 = BinFileSeek(puVar8 + -0x294,0x461c4000);

          AudioSetSpeakerConfig__F14SPEAKER_SYSTEM_3(uVar4);

          status_hud_render(puVar8 + -0x294,0xffff,0xffffffff);

          Audio3DTestToneUpdate__Fv_3();

          iVar6 = iStack_214;

        }

        else {

          XFSetViewport(&fStack_1e4);

          uVar4 = AudioDataStreamStatus__Fv_3();

          mission_004fe2d0(uVar4,&PTR_DAT_00562510 + *piVar7 * 0x16,0x3e19999a,0x3e4ccccd,

                           &uStack_1d4,&uStack_1cc);

          fVar1 = *(float *)(iStack_1c4 + (int)piVar7) * 0.7;

          terrain_uv_sample(uVar4,iVar6,fVar1,fVar1,uStack_1d4,uStack_1cc,0);

          iVar6 = iStack_214;

        }

      }

      iStack_23c = iStack_23c + 1;

      puVar8 = puVar8 + 0x304;

      piVar7 = piVar7 + 1;

    } while (iStack_23c < iStack_240);

  }

  DAT_005a84e0 = DAT_006328e0 * 6.2831855 + DAT_005a84e0;

  if (6.2831855 < DAT_005a84e0) {

    DAT_005a84e0 = DAT_005a84e0 - 6.2831855;

  }

  XFSetViewport(&fStack_1e4);

  view_matrix_reset(auStack_10c);

  FNT_StringRender__FPcP14FNT_RenderInfo(pcStack_1c0,puStack_1c8);

  render_projection_set(fStack_228,fStack_224,1);

  xfmat_mult_a();

  if (iStack_240 < 1) {

    return;

  }

  iVar6 = 0;

  do {

    if (aiStack_16c[iVar6] != 0) {

      iVar5 = aiStack_14c[iVar6];

      crt_itoa_wrapper(iVar5,&local_20c,10);

      object_stop_movement((OBJECT *)local_1bc);

      if (local_22c == (undefined *)0x0) {

        fStack_1ac = (float)(&DAT_00561178)[iVar6 * 2];

        fStack_1a8 = (float)(&DAT_0056117c)[iVar6 * 2] + 0.05;

        fStack_1b0 = _DAT_005611b8 * 0.25;

        fStack_1b4 = _DAT_005611b8 * 0.25;

      }

      else {

        iVar2 = *(int *)(local_22c + iVar6 * 4) * 0x58;

        local_1bc[0] = 0x3f800000;

        local_1bc[1] = 0x3f2ccccd;

        fStack_1ac = *(float *)(&DAT_00562550 + iVar2) / (fStack_1e4 + fStack_1e4);

        fStack_1a8 = *(float *)(&DAT_00562548 + iVar2) / (fStack_1e0 + fStack_1e0);

        fStack_1b4 = ((*(float *)(&DAT_00562550 + iVar2) - *(float *)(&DAT_00562544 + iVar2)) * 0.45

                     ) / (fStack_1e4 + fStack_1e4);

        fStack_1b0 = ((*(float *)(&DAT_00562554 + iVar2) - *(float *)(&DAT_00562548 + iVar2)) * 0.45

                     ) / (fStack_1e0 + fStack_1e0);

      }

      if (iVar5 < 0) {

        if (local_22c != (undefined *)0x0) {

          iVar5 = AudioDataStreamStatus__Fv_3();

          mission_004fe2d0(iVar5,&PTR_DAT_00562510 + *(int *)(local_22c + iVar6 * 4) * 0x16,

                           0x3f000000,0,&fStack_224,&fStack_228);

          textrender_glyph_quad

                    (iVar5,&PTR_s_infinity_005744c8,0,0x3f800000,0x3f800000,

                     (float)*(int *)(iVar5 + 0x24) * fStack_224,

                     (float)*(int *)(iVar5 + 0x28) * fStack_228);

          hurt_pusher_2(iVar5,&PTR_s_infinity_005744c8);

        }

      }

      else {

        fStack_1a8 = 1.0 - fStack_1a8;

        FNT_RenderInfoProcess__FP14FNT_RenderInfof(local_1bc,DAT_006328e0);

        pdVar9 = local_1bc;

        pfVar12 = &local_20c;

        uVar4 = AudioGetMasterVolume__Fv_3();

        flick_text_layout(uVar4,pfVar12,pdVar9);

      }

    }

    iVar6 = iVar6 + 1;

  } while (iVar6 < iStack_240);

  return;

}

/* ===== lens_effects_process__Fv @ 0x004CD5D0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* PS2 candidate: lens_effects_process__Fv (conf 0.401) */



void lens_effects_process__Fv(void)



{

  uint *puVar1;

  int iVar2;

  float fVar3;

  int iVar4;

  int iVar5;

  float *pfVar6;

  int iVar7;

  int *piVar8;

  int iVar9;

  int iVar10;

  float10 fVar11;

  int local_48;

  uint *local_44;

  float local_3c;

  float local_38;

  float local_34;

  float local_30;

  float local_2c;

  float local_28;

  float local_24;

  float local_20;

  float local_1c;

  float afStack_18 [6];

  

  iVar5 = DAT_006330e4;

  puVar1 = (uint *)(DAT_006330e4 + 0x4f70);

  iVar4 = FLK_FlickPlaying();

  iVar10 = 0;

  if (DAT_006331b8 != 0) {

    piVar8 = (int *)(iVar5 + 0x4fbc);

    iVar5 = 0;

    do {

      if (*piVar8 != 0) {

        puVar1 = (uint *)(*piVar8 + 0xd8);

        *puVar1 = *puVar1 | 0x40000000;

        *(undefined4 *)((int)&DAT_005a84b4 + iVar5) = 0;

        *(undefined4 *)((int)&DAT_005a84b8 + iVar5) = 0;

        *(undefined4 *)((int)afStack_18 + iVar5 + 8) = 0;

        *(undefined4 *)((int)afStack_18 + iVar5 + 0xc) = 0;

      }

      iVar5 = iVar5 + 8;

      piVar8 = piVar8 + 0x11;

    } while (iVar5 < 0x10);

    return;

  }

  if (DAT_006330b4 == 0) {

    return;

  }

  pfVar6 = (float *)XFGetCameraOrigin();

  local_3c = *(float *)(DAT_006330e4 + 0x4f60) - *pfVar6;

  local_38 = *(float *)(DAT_006330e4 + 0x4f64) - pfVar6[1];

  local_34 = *(float *)(DAT_006330e4 + 0x4f68) - pfVar6[2];

  normalize__FPfN20(&local_3c,&local_38,&local_34);

  local_24 = local_3c * 10.0 + *pfVar6;

  local_20 = local_38 * 10.0 + pfVar6[1];

  local_1c = local_34 * 10.0 + pfVar6[2];

  local_30 = *(float *)(DAT_006330e4 + 0x4f60) - local_3c * 1000.0;

  local_2c = *(float *)(DAT_006330e4 + 0x4f64) - local_38 * 1000.0;

  local_28 = *(float *)(DAT_006330e4 + 0x4f68) - local_34 * 1000.0;

  iVar7 = ai_class_filter(&local_24,&local_30,0,0,1);

  if (iVar7 != 0) {

    pfVar6 = (float *)XFGetCameraAxis(2);

    fVar3 = local_3c * *pfVar6 + local_38 * pfVar6[1] + local_34 * pfVar6[2];

    if ((0.0 <= fVar3) && (_DAT_005a84a8 = 1, 0.0 < fVar3)) goto LAB_004cd778;

  }

  _DAT_005a84a8 = 0;

LAB_004cd778:

  local_48 = 0;

  iVar7 = 0xc;

  local_44 = puVar1;

  while( true ) {

    do {

      iVar2 = local_48 + iVar10;

      iVar9 = iVar2 * 4;

      afStack_18[iVar2] = 0.0;

      if ((iVar10 != 1) || ((~*local_44 & 1) == 0)) {

        fVar11 = (float10)powf();

        afStack_18[iVar2] = (float)fVar11;

        fVar11 = fVar11 - (float10)*(float *)(&DAT_005a84ac + iVar9);

        if ((float10)0.0 <= fVar11) {

          fVar11 = fVar11 * (float10)(float)puVar1[iVar7 + iVar10];

          *(float *)(&DAT_005a84c4 + iVar9) = (float)fVar11;

        }

        else {

          fVar11 = fVar11 * (float10)(float)puVar1[iVar7 + iVar10];

          *(float *)(&DAT_005a84c4 + iVar9) = (float)fVar11;

        }

        fVar11 = fVar11 * (float10)DAT_006328e0 + (float10)*(float *)(&DAT_005a84ac + iVar9);

        *(float *)(&DAT_005a84ac + iVar9) = (float)fVar11;

        if (0.0 <= *(float *)(&DAT_005a84c4 + iVar9)) {

          if ((float10)afStack_18[iVar2] < fVar11) {

            *(float *)(&DAT_005a84ac + iVar9) = afStack_18[iVar2];

          }

        }

        else if (fVar11 < (float10)afStack_18[iVar2]) {

          *(float *)(&DAT_005a84ac + iVar9) = afStack_18[iVar2];

        }

      }

      iVar10 = iVar10 + 1;

    } while (iVar10 < 2);

    local_48 = local_48 + 2;

    local_44 = local_44 + 0x11;

    iVar7 = iVar7 + 0x11;

    if (0x3e < iVar7) break;

    iVar10 = 0;

  }

  piVar8 = (int *)(iVar5 + 0x4fbc);

  pfVar6 = (float *)&DAT_005a84b8;

  do {

    if (*piVar8 != 0) {

      *(float *)(*piVar8 + 0x184) = 1.0 - (float)piVar8[8] * pfVar6[-1];

      *(float *)(*piVar8 + 0xd0) =

           DAT_006328e0 * (float)piVar8[0xe] * 360.0 + *(float *)(*piVar8 + 0xd0);

      *(undefined4 *)(*piVar8 + 0xcc) = 0;

      *(undefined4 *)(*piVar8 + 200) = 0;

      fVar11 = (float10)fsin((float10)_DAT_005a84e4);

      *(float *)(*piVar8 + 0xc4) =

           (float)((float10)(float)piVar8[9] * (float10)*pfVar6 + (float10)(float)piVar8[5] +

                  fVar11 * (float10)(float)piVar8[0xc]);

      fVar11 = (float10)rndfloatrange(0x3f000000,0x3fc00000);

      fVar11 = fVar11 * (float10)(float)piVar8[0xd] * (float10)DAT_006328e0 * (float10)3.1415927 +

               (float10)_DAT_005a84e4;

      if ((float10)6.2831855 < fVar11) {

        do {

          fVar11 = fVar11 - (float10)6.2831855;

        } while ((float10)6.2831855 < fVar11);

      }

      _DAT_005a84e4 = (float)fVar11;

      *(uint *)(*piVar8 + 0xd8) = *(uint *)(*piVar8 + 0xd8) & 0xbfffffff;

      if (iVar4 != 0) {

        alpha_queue_push(*piVar8);

      }

    }

    pfVar6 = pfVar6 + 2;

    piVar8 = piVar8 + 0x11;

  } while ((int)pfVar6 < 0x5a84c8);

  return;

}

/* ===== render_fog_color_set @ 0x004CD990 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void render_fog_color_set(void)



{

  float fVar1;

  uint uVar2;

  uint uVar3;

  uint uVar4;

  undefined4 *puVar5;

  

  if (0.003921569 <

      _DAT_005a84ac * *(float *)(DAT_006330e4 + 0x4f98) + *(float *)(DAT_006330e4 + 0x4f88)) {

    __ftol();

    uVar2 = __ftol();

    uVar3 = __ftol();

    uVar4 = __ftol();

    uVar4 = ((uVar2 | 0xffffff00) << 8 | uVar3) << 8 | uVar4;

    (**(code **)(DAT_00656428 + 8))(DAT_00656428,0x201e0,0,uVar4 != 0);

    puVar5 = (undefined4 *)(**(code **)(DAT_00656438 + 0x10))(DAT_00656438,4);

    *puVar5 = 0;

    puVar5[1] = 0;

    puVar5[4] = uVar4;

    fVar1 = (float)DAT_00632e84;

    puVar5[8] = 0;

    puVar5[0xb] = uVar4;

    puVar5[7] = fVar1;

    puVar5[0xe] = (float)DAT_00632e84;

    fVar1 = (float)DAT_00632e88;

    puVar5[0x12] = uVar4;

    puVar5[0x15] = 0;

    puVar5[0xf] = fVar1;

    fVar1 = (float)DAT_00632e88;

    puVar5[0x19] = uVar4;

    puVar5[0x16] = fVar1;

    return;

  }

  return;

}

/* ===== dev_debug_flags @ 0x004CDA80 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined4 dev_debug_flags(void)



{

  float fVar1;

  undefined4 *puVar2;

  undefined4 *puVar3;

  int *piVar4;

  int iVar5;

  float *pfVar6;

  int iVar7;

  undefined4 uVar8;

  int iVar9;

  char *pcVar10;

  int *piVar11;

  float10 fVar12;

  undefined8 uVar13;

  undefined1 *puVar14;

  undefined8 uVar15;

  undefined *puVar16;

  char *local_218;

  int local_214;

  undefined4 *local_210;

  float fStack_20c;

  float local_208;

  float local_204;

  float local_200;

  int *local_1fc;

  int local_1f8;

  int local_1f4;

  float fStack_1f0;

  undefined1 local_1ec [8];

  float local_1e4;

  undefined1 local_1e0 [32];

  undefined4 local_1c0;

  undefined4 uStack_1bc;

  undefined4 uStack_1b8;

  undefined1 auStack_170 [4];

  undefined1 auStack_16c [100];

  undefined1 auStack_108 [260];

  

  if (((DAT_0063311c == 0) && (DAT_006331c0 == 0)) && (iVar5 = comm_00426540(), iVar5 == 0)) {

    iVar5 = 1;

    local_214 = 1;

    pfVar6 = (float *)XFGetCameraOrigin();

    local_208 = *pfVar6;

    local_204 = pfVar6[1];

    local_200 = pfVar6[2];

    XFGetViewport_2();

    view_matrix_get(&local_1c0);

    fVar12 = (float10)render_get_fov();

    local_210 = (undefined4 *)(float)fVar12;

    fVar12 = (float10)render_get_aspect();

    local_1e4 = (float)fVar12;

    render_scene_end();

    local_1fc = DAT_00632d68;

    if (DAT_00632d68 != (int *)0x0) {

      do {

        iVar9 = local_1fc[3];

        if (((((*(uint *)(iVar9 + 0xd8) & 0x4000c000) == 0) &&

             (*(int *)(iVar9 + 0x184) != 0x3f800000)) &&

            ((local_1f4 = *(int *)(iVar9 + 0x2e0), local_1f4 != 0 &&

             ((*(char *)(local_1f4 + 0x1e) < '\0' && ((*(uint *)(iVar9 + 0x1c8) & 0x40000000) == 0))

             )))) && (*(int *)(*(int *)(iVar9 + 8) + 8 + *(int *)(iVar9 + 0x10) * 4) != 0)) {

          if (iVar5 != 0) {

            local_214 = (**(code **)(DAT_00656420 + 0x8c))();

          }

          (**(code **)(DAT_00656420 + 0xc0))(DAT_00656420,local_1f4,local_1ec);

          pcVar10 = (char *)(1 << ((byte)local_1ec._0_4_ & 0x1f));

          local_1f8 = 1 << ((byte)local_1ec._4_4_ & 0x1f);

          fVar1 = (float)local_1f8;

          fStack_20c = (float)(int)pcVar10;

          local_218 = pcVar10;

          fStack_1f0 = fVar1;

          XFSetViewportRegion(0,0,fStack_20c);

          (**(code **)(DAT_00656420 + 0xa0))(DAT_00656420,0,0,fStack_20c,fVar1,0);

          iVar5 = *(int *)(*(int *)(iVar9 + 8) + 8 + *(int *)(iVar9 + 0x10) * 4);

          render_projection_reset(iVar5 + 0xc,iVar5 + 0x18);

          GEO_MatIdentity();

          view_matrix_reset(auStack_16c);

          xfmat_mult_b();

          render_scene_begin();

          (**(code **)(DAT_00656420 + 0x14))();

          animate_core_caller(iVar9,0,0,auStack_170,&local_208);

          render_scene_end();

          ANM_DumpCluster();

          if (local_214 == 0) {

            (**(code **)(DAT_00656420 + 0xb8))(DAT_00656420,local_1f4,0,0,pcVar10);

          }

          (**(code **)(DAT_00656420 + 0xa4))();

          iVar5 = local_214;

        }

        local_1fc = (int *)*local_1fc;

      } while (local_1fc != (int *)0x0);

      if (iVar5 == 0) {

        (**(code **)(DAT_00656420 + 0xa0))(DAT_00656420,0,0,(float)(int)local_218,(float)local_1f8);

      }

    }

    uVar13 = 0;

    iVar5 = DAT_00656420;

    (**(code **)(DAT_00656420 + 0x8c))();

    XFSetViewport(local_1e0,iVar5,uVar13);

    view_matrix_reset();

    render_projection_set(local_210,local_1e4,1);

    render_scene_begin();

  }

  if (DAT_00632e74 != 0) {

    object_destroy_all__7PS2Game();

  }

  xfmat_mult_b();

  piVar11 = DAT_00632d68;

  while ((piVar11 != (int *)0x0 &&

         ((*(int *)(piVar11[3] + 0x204) == 0 || (iVar5 = hud_parse_format_codes_2(), iVar5 != 0)))))

  {

    piVar11 = (int *)*piVar11;

  }

  main_drawobj_0042d490();

  XFGetViewport();

  iVar5 = comm_00426540();

  if (iVar5 == 0) {

    audio_register_sound_name();

    if (0 < DAT_00633244) {

      dlog_entry_alloc();

    }

    audio_stream_tied();

    input_device_poll();

    iVar5 = AudioGetMasterVolume__Fv();

    audio_register_sound_name();

    for (piVar11 = DAT_00632d68; piVar4 = DAT_00632d68, piVar11 != (int *)0x0;

        piVar11 = (int *)*piVar11) {

      if ((*(uint *)(piVar11[3] + 0xd8) & 0x4000c000) == 0) {

        sine_cosine_table_gen();

      }

    }

    for (; piVar4 != (int *)0x0; piVar4 = (int *)*piVar4) {

      iVar9 = piVar4[3];

      if (((((*(int *)(iVar9 + 8) != 0) && ((*(uint *)(iVar9 + 0xd8) & 0x4000c000) == 0)) &&

           (*(int *)(iVar9 + 0x184) != 0x3f800000)) &&

          ((iVar9 != DAT_00632a88 || (DAT_00633108 != 0)))) &&

         ((*(int *)(iVar9 + 0x1e0) != 0x4e || (iVar7 = Main_fx_00447fa0(iVar9), iVar7 == 0)))) {

        if (((iVar9 == iVar5) || (*(int *)(iVar9 + 0x210) == iVar5)) ||

           ((iVar7 = ObjIsJetski(), iVar7 != 0 && (*(int *)(iVar9 + 0x274) == iVar5)))) {

          vimp_death_fx();

        }

        else {

          iVar7 = BinFileCreateWrite_3();

          if ((-1 < (char)*(uint *)(iVar9 + 0xd8)) &&

             (*(int *)(*(int *)(iVar9 + 8) + 0x400 + iVar7 * 4) != 0)) {

            if (((*(uint *)(iVar9 + 0x1c8) & 0x40000040) == 0) &&

               (((*(uint *)(iVar9 + 0xd8) & 0x10) == 0 && (DAT_0063311c == 0)))) {

              rp_spark_hud_setup();

            }

            alpha_queue_push();

          }

        }

      }

    }

    piVar11 = DAT_00632d68;

    if (DAT_00632e74 != 0) {

      for (; piVar11 != (int *)0x0; piVar11 = (int *)*piVar11) {

        iVar5 = piVar11[3];

        if ((((*(uint *)(iVar5 + 0x1c8) & 0x8000000) != 0) || (*(int *)(iVar5 + 0x1e0) == 0x61)) ||

           (*(int *)(iVar5 + 0x1e0) == 0x3a)) {

          if ((*(int *)(iVar5 + 0x174) == 0) && (*(int *)(iVar5 + 0x1e0) != 0x3a)) {

            showchat_mission_objective__Fi_2(iVar5);

          }

          sine_cosine_table_gen();

          if (-1 < *(char *)(iVar5 + 0xd8)) {

            if ((*(int *)(iVar5 + 0x1e0) != 0x61) && (*(int *)(iVar5 + 0x1e0) != 0x3a)) {

              uVar8 = showchat_mission_objective__Fi(*(int *)(iVar5 + 0xe8));

              *(undefined4 *)(iVar5 + 0xf4) = uVar8;

            }

            *(uint *)(iVar5 + 0x1c8) = *(uint *)(iVar5 + 0x1c8) | 0x4000;

            alpha_queue_push();

            if (((*(uint *)(iVar5 + 0xd8) & 0x200000) != 0) && (*(int *)(iVar5 + 0x1e0) != 0x3a)) {

              puVar14 = local_1e0;

              uVar13 = CONCAT44(*(undefined4 *)(iVar5 + 0x174),&DAT_00557088);

              crt_sprintf();

              local_1c0 = *(undefined4 *)(iVar5 + 0xa0);

              uStack_1bc = *(undefined4 *)(iVar5 + 0xa4);

              uStack_1b8 = *(undefined4 *)(iVar5 + 0xa8);

              hud_screen_project4(&local_1c0,puVar14,uVar13);

              textrender_draw_main();

            }

          }

        }

      }

    }

    input_device_poll_2();

    cleanup_00436060();

    pcVar10 = s_InDome_005611d0;

    audio_register_sound_name();

    uVar15 = CONCAT44(pcVar10,&DAT_00561138);

    iVar5 = DAT_00656420;

    (**(code **)(DAT_00656420 + 0x18))();

    uVar13 = CONCAT44(iVar5,1);

    iVar5 = DAT_00656430;

    (**(code **)(DAT_00656430 + 0xc))();

    (**(code **)(DAT_00656430 + 0x10))(DAT_00656430,1,iVar5,uVar13,uVar15);

    render_get_clip_nearfar(&local_218,&local_210);

    FNT_StringRender__FPcP14FNT_RenderInfo(local_218,(undefined4 *)0x46dac000);

    fVar12 = (float10)render_get_aspect();

    render_get_fov((float)fVar12);

    render_projection_set();

    dlog_scene_submit();

    FNT_StringRender__FPcP14FNT_RenderInfo(local_218,local_210);

    fVar12 = (float10)render_get_aspect();

    render_get_fov((float)fVar12);

    render_projection_set();

    if (DAT_00633244 < 1) {

      dlog_entry_alloc();

    }

    alpha_queue_push_2();

    lens_effects_process__Fv();

    main_drawwatr_00431700();

    render_view_xform();

    multi_display_player_cursor_info__Fv();

    iVar5 = dialog_level_is_base_dup0052aa70();

    if ((iVar5 != 0) && (puVar2 = DAT_00632d70, _DAT_00633254 < 2)) {

      for (; puVar3 = DAT_00632d74, puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {

        if ((-1 < *(char *)(puVar2[3] + 0xd8)) && (iVar5 = ObjIsMecc(), iVar5 != 0)) {

          status_update_entry();

        }

      }

      for (; puVar2 = DAT_00632d78, puVar3 != (undefined4 *)0x0; puVar3 = (undefined4 *)*puVar3) {

        if ((-1 < *(char *)(puVar3[3] + 0xd8)) && (iVar5 = ObjIsReaper(), iVar5 != 0)) {

          status_update_entry();

        }

      }

      for (; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {

        if ((-1 < *(char *)(puVar2[3] + 0xd8)) && (iVar5 = ObjIsKabuto(), iVar5 != 0)) {

          status_update_entry();

        }

      }

    }

    piVar11 = &DAT_00632d14;

    do {

      iVar5 = *piVar11;

      if (iVar5 != 0) {

        if ((*(uint *)(iVar5 + 0xd8) & 0x8000) == 0) {

          if (((DAT_00632a88 != 0) && (iVar9 = BinFileCreateWrite_3(), -1 < *(char *)(iVar5 + 0xd8))

              ) && (*(int *)(*(int *)(iVar5 + 8) + 0x400 + iVar9 * 4) != 0)) {

            base_hint_menu(iVar5,*(int *)(DAT_00632a88 + 0x18c) == *(int *)(iVar5 + 0x18c));

          }

        }

        else {

          *piVar11 = 0;

        }

      }

      piVar11 = piVar11 + 1;

    } while ((int)piVar11 < 0x632d1c);

    iVar5 = player_pet_follow_tick();

    if (iVar5 != 0) {

      dlog_text_draw_wrap(0x1fffff,0,0x3d2aaaab,0x3dcccccd,0x3f4ccccd,iVar5);

    }

    player_draw_missile_lock();

    dev_debug_overlay_draw();

    particle_lifespan_render();

    status_update_3obj();

    status_timer_update();

    texture_object_debug_dump();

    if (DAT_00633228 == 0) {

      MAP_MemGroupSetBase(DAT_006328f4,DAT_00632a88);

      wave_effects_draw_all();

    }

    render_fog_color_set();

    kabuto_skinning_eval_all();

    status_draw_panel();

    if (DAT_00632fac == 0) {

      ShopMenuSlotCollision__Fi();

    }

    dlog_fade_control();

    if (((DAT_00632bc0 != 0) || (DAT_00632e48 != 0)) || (DAT_00632bc4 != 0)) {

      hud_cursor_status_draw();

    }

    dlog_alpha_big_render();

    Audio3DTestToneStop__Fv();

  }

  SetupCameraHail__Fv();

  dev_debug_text_draw();

  if ((DAT_006331c4 == 0) && (iVar5 = net_active_players_get(), iVar5 != 0)) {

    textrender_draw_buffered

              (0,0,0x3d0f5c29,0x3f000000,0x3f000000,s_Dongle_check_skipped_____00561350);

  }

  if (DAT_00632bd8 != 0) {

    puVar14 = auStack_108;

    uVar13 = CONCAT44(DAT_00632bfc * 0x118 + 0x2210 + DAT_006330e4,s_Mission_Edit_Mode___s_00561338)

    ;

    crt_sprintf();

    textrender_draw_buffered(0,0,0x3d0f5c29,0x3f000000,0x3d4ccccd,auStack_108,puVar14,uVar13);

  }

  if ((DAT_00632c00 == 0) && (0.0 < _DAT_00632bdc)) {

    story_flick_open();

    crt_sprintf(&local_1c0,s__8_0f_00561330,(double)_DAT_00632bdc);

    if (10.0 <= _DAT_00632bdc) {

      if (30.0 <= _DAT_00632bdc) {

        uVar15 = CONCAT44(&local_1c0,0x3d4ccccd);

        uVar13 = 0xff00;

      }

      else {

        uVar15 = CONCAT44(&local_1c0,0x3d4ccccd);

        uVar13 = 0xffff00;

      }

    }

    else {

      uVar15 = CONCAT44(&local_1c0,0x3d4ccccd);

      uVar13 = 0xff0000;

    }

    textrender_draw_buffered(uVar13,0x3f0000003d3851ec,uVar15);

  }

  if (0 < DAT_00632f08) {

    if (2.0 < _DAT_00632b60) {

      uVar8 = TextGetPtr();

      textrender_draw_buffered(0x1fff1f,0,0x3d4ccccd,0x3f000000,0x3f000000,uVar8);

    }

    if (DAT_00632fc0 != 0) {

      iVar5 = __ftol();

      if (iVar5 / 0xe10 == 0) {

        crt_sprintf(local_1e0,s__d__02d_0056130c,(iVar5 % 0xe10) / 0x3c,(iVar5 % 0xe10) % 0x3c);

      }

      else {

        crt_sprintf();

      }

      textrender_draw_buffered(0x1fff1f,0,0x3d4ccccd,0x3f000000,0x3ca3d70a,local_1e0);

    }

    if (0.0 < DAT_00632f30) {

      iVar5 = __ftol();

      if (iVar5 / 0xe10 == 0) {

        crt_sprintf(local_1e0,s__d__02d_0056130c,(iVar5 % 0xe10) / 0x3c,(iVar5 % 0xe10) % 0x3c);

      }

      else {

        crt_sprintf();

      }

      uVar8 = TextGetPtr(s_CapsAllowedTimer_005612f8,local_1e0);

      crt_sprintf(auStack_170,s__s__s_0055c280,uVar8);

      textrender_draw_buffered(0xff1f1f,0,0x3cf5c28f,0x3f000000,0x3d75c28f,auStack_170);

    }

    if (((DAT_00632f08 < 7) || (9 < DAT_00632f08)) &&

       ((((byte)DAT_00633040 & 1) != 0 ||

        ((((((byte)DAT_00633040 & 4) != 0 || (((byte)DAT_00633040 & 8) != 0)) ||

          (((byte)DAT_00633040 & 0x10) != 0)) || (((byte)DAT_00633040 & 2) != 0)))))) {

      uVar8 = TextGetPtr();

      textrender_draw_buffered(0x1fff1f,0,0x3d4ccccd,0x3f000000,0x3f000000,uVar8);

    }

  }

  if (DAT_00633234 == 0) goto LAB_004ce7b8;

  iVar5 = project_cursor_to_object(&LAB_004ce810,0,0x47afc800,local_1e0);

  if (iVar5 == 0) {

    puVar16 = &DAT_0055c72c;

  }

  else {

    iVar9 = *(int *)(iVar5 + 0x210);

    while ((iVar9 != 0 && ((*(uint *)(iVar5 + 0x1c8) & 0x400000) == 0))) {

      iVar5 = *(int *)(iVar5 + 0x210);

      iVar9 = *(int *)(iVar5 + 0x210);

    }

    if ((*(int *)(iVar5 + 4) == 0xd7) || (*(int *)(iVar5 + 4) != 2)) {

      crt_sprintf();

      puVar16 = &DAT_00657400;

    }

    else {

      local_208 = 0.0;

      local_204 = 0.0;

      local_200 = 0.0;

      ai_get_goal_location(iVar5,&local_208);

      iVar9 = fx_logic(2,iVar5);

      if (iVar9 == 0) {

        iVar9 = fx_logic(1,iVar5);

        uVar8 = 0;

        if (iVar9 != 0) goto LAB_004ce6e4;

      }

      else {

LAB_004ce6e4:

        uVar8 = 1;

      }

      crt_sprintf(&DAT_00657400,s_ost__d_otmr__1_3f_scn__d_hp__1_2_00561218,

                  *(undefined4 *)(iVar5 + 0xe4),(double)*(float *)(iVar5 + 0xec),uVar8,

                  (double)*(float *)(iVar5 + 0x278),(int)*(char *)(iVar5 + 0x20a),

                  (int)*(char *)(iVar5 + 0x20b),*(uint *)(iVar5 + 0xd8) >> 0x19 & 1,

                  *(byte *)(iVar5 + 0xdb) & 1,*(int *)(iVar5 + 0x168) != 0,(double)local_208,

                  (double)local_204,(double)local_200);

      puVar16 = &DAT_00657400;

    }

  }

  dlog_text_draw_wrap(0xffffff,0,0x3d1a6b51,0x3dcccccd,0x3dcccccd,puVar16);

LAB_004ce7b8:

  ANM_DumpCluster();

  mecc_get_thrust__FP6OBJECTfPfT2_2();

  iVar5 = fps_display();

  if (iVar5 == 0) {

    return 0;

  }

  if (DAT_00633100 != 0) {

    comm_net_stats_dump();

  }

  if (DAT_00632c0c != 0) {

    dlog_page_process();

  }

  return 1;

}

/* ===== comm_004ce880 @ 0x004CE880 ===== */
void comm_004ce880(int param_1,undefined4 param_2)



{

  if (param_1 / 0xe10 != 0) {

    crt_sprintf(param_2,s__d__02d__02d_00561314,param_1 / 0xe10);

    return;

  }

  crt_sprintf(param_2,s__d__02d_0056130c,(param_1 % 0xe10) / 0x3c,(param_1 % 0xe10) % 0x3c);

  return;

}

/* ===== object_spawn_4c @ 0x004CE8D0 ===== */
void object_spawn_4c(int param_1)



{

  int iVar1;

  int iVar2;

  undefined4 *puVar3;

  int iVar4;

  int iVar5;

  float10 fVar6;

  float10 fVar7;

  int local_1c;

  int local_18;

  float local_c;

  float local_8;

  undefined4 local_4;

  

  iVar1 = *(int *)(param_1 + 0x170);

  *(int *)(iVar1 + 0x24) = param_1;

  *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) | 0x40000000;

  local_1c = 0;

  iVar5 = param_1;

  if (0.0 < *(float *)(iVar1 + 0xc)) {

    do {

      iVar4 = object_allocate_type(*(undefined4 *)(param_1 + 4),0x11);

      *(int *)(iVar4 + 0x170) = iVar1;

      fVar6 = (float10)rndfloatrange(*(undefined4 *)(iVar1 + 4),*(undefined4 *)(iVar1 + 8));

      *(float *)(iVar4 + 0xc4) = (float)fVar6;

      *(uint *)(iVar4 + 0x1c8) = *(uint *)(iVar4 + 0x1c8) | 0x840;

      iVar2 = *(int *)(*(int *)(iVar4 + 8) + 0x400);

      fVar6 = (float10)distancesq2d__FP3P3DT0(iVar2 + 0x44,iVar2 + 0x50);

      iVar2 = *(int *)(iVar4 + 0x170);

      if (iVar2 != 0) {

        local_18 = 0;

        do {

          fVar7 = (float10)rndfloatrange(-*(float *)(iVar2 + 0x10),*(undefined4 *)(iVar2 + 0x10));

          local_c = (float)(fVar7 + (float10)*(float *)(iVar2 + 0x18));

          fVar7 = (float10)rndfloatrange(-*(float *)(iVar2 + 0x10),*(undefined4 *)(iVar2 + 0x10));

          local_8 = (float)(fVar7 + (float10)*(float *)(iVar2 + 0x1c));

          local_4 = *(undefined4 *)(iVar2 + 0x20);

          puVar3 = DAT_00632d6c;

          while ((puVar3 != (undefined4 *)0x0 &&

                 (((iVar5 = puVar3[3], iVar5 == iVar4 || (*(int *)(iVar5 + 0x170) != iVar2)) ||

                  (fVar7 = (float10)distancesq2d__FP3P3DT0(iVar5 + 0xa0,&local_c),

                  (float10)(float)fVar6 <= fVar7))))) {

            puVar3 = (undefined4 *)*puVar3;

          }

        } while ((iVar5 != 0) && (local_18 = local_18 + 1, local_18 < 10));

        object_set_location_p3d(iVar4,&local_c);

      }

      *(undefined4 *)(iVar4 + 0xe4) = *(undefined4 *)(param_1 + 0xe4);

      local_1c = local_1c + 1;

    } while ((float)local_1c < *(float *)(iVar1 + 0xc));

  }

  return;

}

/* ===== smartie_move_turn @ 0x004CEA60 ===== */
/* PS2 candidate: ObjIsMeccBaseWall (conf 0.509) */



void smartie_move_turn(int param_1)



{

  int iVar1;

  

  smartie_move(param_1);

  iVar1 = *(int *)(param_1 + 0xe4);

  if ((((iVar1 != 0x14) && (iVar1 != 0x67)) && (iVar1 != 0x68)) && (iVar1 != 0x6c)) {

    obj_turn_update(param_1);

  }

  return;

}

/* ===== smartie_move @ 0x004CEAA0 ===== */
/* PS2 candidate: smartie_move (conf 0.445) */



void smartie_move(OBJECT *param_1)



{

  int *piVar1;

  undefined1 *puVar2;

  float fVar3;

  dword dVar4;

  dword dVar5;

  uint uVar6;

  OBJECT *obj;

  undefined1 uVar7;

  int iVar8;

  undefined4 uVar9;

  int iVar10;

  undefined4 *puVar11;

  float *pfVar12;

  uint uVar13;

  dword *pdVar14;

  float10 fVar15;

  OBJECT *pOVar16;

  float fVar17;

  float *local_4c;

  float local_48;

  float local_44;

  float local_40;

  float local_3c;

  float local_38;

  float local_34;

  float local_30;

  undefined4 local_2c;

  undefined1 local_28 [12];

  undefined1 local_1c [16];

  undefined4 local_c;

  

  obj = param_1;

  dVar4 = param_1->animate_state;

  if (DAT_00632e74 != 0) {

    return;

  }

  if ((param_1->coll_radius & 1) != 0) {

    return;

  }

  iVar8 = fx_create(param_1);

  iVar10 = DAT_00632a88;

  if (iVar8 == 0) {

    return;

  }

  if (*(int *)&obj->field_0x210 != 0) {

    iVar8 = *(int *)(*(int *)&obj->field_0x210 + 0x1e0);

    if (iVar8 == 1) {

      return;

    }

    if (iVar8 == 0x4c) {

      return;

    }

  }

  dVar5 = obj->animate_state;

  fVar15 = (float10)FRateGetSecsframe(obj,0);

  fVar15 = (float10)*(float *)(dVar5 + 0x54) - fVar15;

  *(float *)(dVar5 + 0x54) = (float)fVar15;

  if (fVar15 < (float10)0.0) {

    *(undefined4 *)(dVar5 + 0x54) = 0;

  }

  iVar8 = ObjIsMecc(iVar10);

  if ((iVar8 == 0) || ((*(uint *)(iVar10 + 0xe0) & 0x2000000) == 0)) {

    *(undefined4 *)(dVar5 + 0x54) = 0;

  }

  else if (((*(float *)(iVar10 + 0x10c) != 0.0) || (*(float *)(iVar10 + 0x110) != 0.0)) &&

          (fVar15 = (float10)distancesq3d(&obj->field_0xa0,iVar10 + 0xa0), fVar15 < (float10)57600.0

          )) {

    fVar15 = (float10)FRateGetSecsframe(obj,0);

    *(float *)(dVar5 + 0x54) = (float)(fVar15 + fVar15 + (float10)*(float *)(dVar5 + 0x54));

  }

  if (*(int *)&obj->field_0xe8 == 1) {

    switch(obj->pad_E4) {

    case 0:

      obj->ai_state_b = 100;

      puVar11 = DAT_00632d68;

      do {

        if (puVar11 == (undefined4 *)0x0) {

LAB_004cec2d:

          fVar15 = (float10)rndfloatrange(*(undefined4 *)(DAT_00632ed8 + 0xd0c),

                                          *(undefined4 *)(DAT_00632ed8 + 0xd10));

          *(float *)&obj->field_0xf0 = (float)fVar15;

          obj->pad_E4 = 0x14;

          return;

        }

        iVar10 = puVar11[3];

        if (((*(int *)(iVar10 + 0x1e0) == 0x60) && (*(int *)(iVar10 + 4) == 0x41c)) &&

           ((*(int *)(iVar10 + 0x174) == 0 && (iVar8 = __ftol(), *(int *)(iVar10 + 0xe8) == iVar8)))

           ) {

          *(int *)(dVar4 + 0x24) = iVar10;

          goto LAB_004cec2d;

        }

        puVar11 = (undefined4 *)*puVar11;

      } while( true );

    default:

      return;

    case 0x14:

      if (*(int *)(dVar4 + 0x24) == 0) {

        *(undefined4 *)&obj->field_0xe8 = 0;

        obj->pad_E4 = 0;

        return;

      }

      iVar10 = *(int *)(dVar4 + 0x24);

      fVar15 = (float10)FRateGetSecsframe(obj,0);

      puVar2 = &obj->field_0xa0;

      fVar15 = fVar15 * (float10)*(float *)(iVar10 + 0xfc) + (float10)*(float *)(dVar4 + 0x2c);

      param_1 = (OBJECT *)(float)fVar15;

      *(float *)(dVar4 + 0x2c) = (float)fVar15;

      ai_move_ground_common(iVar10,param_1,param_1,puVar2);

      ground_height_at(puVar2,local_1c);

      *(undefined4 *)&obj->field_0xa8 = local_c;

      if ((*(float *)&obj->field_0xb8 != *(float *)puVar2) ||

         (*(float *)&obj->field_0xbc != *(float *)&obj->field_0xa4)) {

        fVar15 = (float10)dirfcalcp3d__FP3P3DT0(&obj->field_0xb8,puVar2);

        *(float *)&obj->field_0xc8 = (float)fVar15;

      }

      obj->flags = obj->flags | 0x40;

      objspec_dispatch_gate(obj);

      fVar15 = (float10)FRateGetSecsframe(obj,0);

      fVar17 = (float)fVar15;

      pOVar16 = obj;

      object_animate_process(obj);

      ObjectCalculateTransform(obj,pOVar16,fVar17);

      obj->flags = obj->flags | 0x20;

      if (obj->type_id == 0xe6) {

        uVar9 = *(undefined4 *)(DAT_00632ed8 + 0xfc);

      }

      else if (obj->type_id == 0x49) {

        uVar9 = *(undefined4 *)(DAT_00632ed8 + 0xe0);

      }

      else {

        uVar9 = *(undefined4 *)(DAT_00632ed8 + 0x88);

      }

      injured_target_scan(obj,uVar9);

      if (*(int *)(dVar4 + 0xc) != 0) {

        *(undefined4 *)&obj->field_0xe8 = 0;

        if (obj->type_id == 0xe6) {

          obj->pad_E4 = 0x40;

          return;

        }

        obj->pad_E4 = ((obj->type_id != 0x49) - 1 & 0x1a) + 7;

        return;

      }

      fVar15 = (float10)FRateGetSecsframe(obj,0);

      fVar15 = (float10)*(float *)&obj->field_0xf0 - fVar15;

      *(float *)&obj->field_0xf0 = (float)fVar15;

      if (fVar15 < (float10)0.0 == (fVar15 == (float10)0.0)) {

        return;

      }

      smartie_target_filter(obj,*(undefined4 *)(DAT_00632ed8 + 0xfc));

      if (*(int *)(dVar4 + 0xc) != 0) {

        *(undefined4 *)&obj->field_0xfc = *(undefined4 *)&obj->field_0xc8;

        obj->pad_E4 = 0x16;

        return;

      }

LAB_004cf690:

      fVar15 = (float10)rndfloatrange(*(undefined4 *)(DAT_00632ed8 + 0xd0c),

                                      *(undefined4 *)(DAT_00632ed8 + 0xd10));

      *(float *)&obj->field_0xf0 = (float)fVar15;

      return;

    case 0x15:

      fVar15 = (float10)FRateGetSecsframe(obj,0);

      fVar15 = (float10)*(float *)&obj->field_0xf0 - fVar15;

      *(float *)&obj->field_0xf0 = (float)fVar15;

      if (fVar15 < (float10)0.0 != (fVar15 == (float10)0.0)) {

        if (*(int *)(dVar4 + 0xc) == 0) {

          *(undefined4 *)&obj->field_0xf4 = 0;

        }

        else if (obj->anim != 0x32) {

          anim_select_check2(obj,0x32);

        }

      }

      if (*(int *)&obj->field_0xf4 < 1) {

        *(undefined4 *)(dVar4 + 0xc) = 0;

        fVar15 = (float10)rndfloatrange(*(undefined4 *)(DAT_00632ed8 + 0xd0c),

                                        *(undefined4 *)(DAT_00632ed8 + 0xd10));

        *(float *)&obj->field_0xf0 = (float)fVar15;

        obj->pad_E4 = 0x16;

        return;

      }

      return;

    case 0x16:

      if (*(float *)&obj->field_0xf0 < 0.0 == (*(float *)&obj->field_0xf0 == 0.0)) {

        local_48 = *(float *)&obj->field_0xfc;

        obj->field_0x208 = 0;

        fVar15 = (float10)playerobj_turn(local_48,*(undefined4 *)&obj->field_0xc8);

        param_1 = (OBJECT *)(float)fVar15;

        if (ABS(fVar15) == (float10)0.0) {

          param_1 = (OBJECT *)0x0;

        }

        else {

          uVar7 = math_sign_of((float)param_1 * 0.05,0x3e800000);

          obj->field_0x208 = uVar7;

          obj->waypoint2 = (dword)local_48;

          obj->flags = obj->flags | 0x1000000;

        }

        if (ABS((float)param_1) < 3.0 == (ABS((float)param_1) == 3.0)) {

          return;

        }

        obj->pad_E4 = 0x14;

      }

      else if (*(int *)(dVar4 + 0xc) == 0) {

        fVar15 = (float10)rndfloatrange(*(undefined4 *)(DAT_00632ed8 + 0xd0c),

                                        *(undefined4 *)(DAT_00632ed8 + 0xd10));

        *(float *)&obj->field_0xf0 = (float)fVar15;

        obj->pad_E4 = 0x14;

      }

      else {

        iVar10 = *(int *)(dVar4 + 0xc) + 0xa0;

        obj->field_0x208 = 0;

        if (iVar10 == 0) {

          param_1 = (OBJECT *)0x0;

        }

        else {

          fVar15 = (float10)dirfcalcp3d__FP3P3DT0(&obj->field_0xa0,iVar10);

          param_1 = (OBJECT *)(float)fVar15;

        }

        fVar15 = (float10)playerobj_turn(param_1,*(undefined4 *)&obj->field_0xc8);

        local_4c = (float *)(float)fVar15;

        if (ABS(fVar15) == (float10)0.0) {

          pfVar12 = (float *)0x0;

        }

        else {

          uVar7 = math_sign_of((float)local_4c * 0.05,0x3e800000);

          obj->field_0x208 = uVar7;

          obj->waypoint2 = (dword)param_1;

          obj->flags = obj->flags | 0x1000000;

          pfVar12 = local_4c;

        }

        if (ABS((float)pfVar12) < 3.0 == (ABS((float)pfVar12) == 3.0)) {

          return;

        }

        uVar9 = rndintrange(*(undefined4 *)(DAT_00632ed8 + 0xd18),

                            *(undefined4 *)(DAT_00632ed8 + 0xd1c));

        *(undefined4 *)&obj->field_0xf4 = uVar9;

        fVar15 = (float10)rndfloatrange(0,*(undefined4 *)(DAT_00632ed8 + 0xd14));

        *(float *)&obj->field_0xf0 = (float)fVar15;

        obj->pad_E4 = 0x15;

      }

    }

LAB_004cf539:

    obj->flags = obj->flags & 0xfcffffff;

    obj->field_0x208 = 0;

    return;

  }

  if (*(int *)&obj->field_0xe8 == 100) {

    switch(obj->pad_E4) {

    case 0:

      obj->ai_state_b = 100;

      iVar10 = *(int *)(*(int *)(dVar4 + 0x24) + 0x100);

      for (puVar11 = DAT_00632d68; puVar11 != (undefined4 *)0x0; puVar11 = (undefined4 *)*puVar11) {

        iVar8 = puVar11[3];

        if (((*(int *)(iVar8 + 4) == 0x48a) &&

            (*(int *)(iVar8 + 0xe8) == *(int *)(*(int *)(iVar10 + 0x18) + 0xe8))) &&

           ((*(int *)(dVar4 + 0x3c) == 0 ||

            (*(int *)(*(int *)(dVar4 + 0x3c) + 0x174) < *(int *)(iVar8 + 0x174))))) {

          *(int *)(dVar4 + 0x3c) = iVar8;

        }

      }

      *(uint *)&obj->field_0x1c8 = *(uint *)&obj->field_0x1c8 | 0xe00;

      obj->flags = obj->flags | 0x10;

      obj->coll_radius = obj->coll_radius | 4;

      fVar15 = (float10)rndfloatrange(*(undefined4 *)(DAT_00632ed8 + 0xd0c),

                                      *(undefined4 *)(DAT_00632ed8 + 0xd10));

      *(float *)&obj->field_0xf0 = (float)fVar15;

      obj->pad_E4 = 100;

      return;

    case 100:

      ai_goal_process(obj);

      if (*(int *)&obj->field_0x168 == 0) {

        *(uint *)&obj->field_0x1c8 = *(uint *)&obj->field_0x1c8 & 0xfffff1ff;

        obj->flags = obj->flags & 0xffffffef;

        playerobj_eval_refpt(*(undefined4 *)(dVar4 + 0x24),*(undefined4 *)(dVar4 + 0x28),&local_34);

        main_ai_move_004014b0(obj,&local_34,*(undefined4 *)(*(int *)(dVar4 + 0x24) + 200));

        obj->pad_E4 = 0x65;

        return;

      }

      break;

    case 0x65:

      ai_goal_process(obj);

      if (*(int *)&obj->field_0x168 == 0) {

        piVar1 = (int *)(*(int *)(*(int *)(dVar4 + 0x24) + 0x100) + 8);

        *piVar1 = *piVar1 + 1;

        obj->coll_radius = obj->coll_radius & 0xfffffffb;

        obj->pad_E4 = 0x66;

        return;

      }

      break;

    case 0x66:

      iVar10 = *(int *)(*(int *)(dVar4 + 0x24) + 0x100);

      puVar11 = DAT_00632d6c;

      if (*(int *)(iVar10 + 8) == *(int *)(iVar10 + 4)) {

        for (; puVar11 != (undefined4 *)0x0; puVar11 = (undefined4 *)*puVar11) {

          iVar10 = puVar11[3];

          if ((*(int *)(iVar10 + 4) == 0xe6) &&

             (*(int *)(*(int *)(iVar10 + 0x100) + 0x24) == *(int *)(dVar4 + 0x24))) {

            *(undefined4 *)(iVar10 + 0xe4) = 0x67;

          }

        }

        *(undefined4 *)(*(int *)(dVar4 + 0x24) + 0xe4) = 2;

        return;

      }

      break;

    case 0x68:

      obj_follow_owner_refpt(obj);

      if (*(int *)(dVar4 + 0x40) == 0) {

        fVar15 = (float10)FRateGetSecsframe(obj,0);

        fVar15 = (float10)*(float *)&obj->field_0xf0 - fVar15;

        *(float *)&obj->field_0xf0 = (float)fVar15;

        if (fVar15 < (float10)0.0 != (fVar15 == (float10)0.0)) {

          smartie_target_filter(obj,*(undefined4 *)(DAT_00632ed8 + 0xfc));

          *(undefined4 *)(*(int *)(dVar4 + 0x24) + 0x274) = *(undefined4 *)(dVar4 + 0xc);

          fVar15 = (float10)rndfloatrange(*(undefined4 *)(DAT_00632ed8 + 0xd0c),

                                          *(undefined4 *)(DAT_00632ed8 + 0xd10));

          *(float *)&obj->field_0xf0 = (float)fVar15;

        }

      }

      else {

        *(undefined4 *)(dVar4 + 0xc) = *(undefined4 *)(*(int *)(dVar4 + 0x24) + 0x274);

      }

      if (*(int *)(dVar4 + 0xc) != 0) {

        piVar1 = (int *)(*(int *)(*(int *)(dVar4 + 0x24) + 0x100) + 8);

        *piVar1 = *piVar1 + -1;

        obj->coll_radius = obj->coll_radius | 4;

        *(undefined4 *)&obj->field_0xfc = *(undefined4 *)&obj->field_0xc8;

        obj->pad_E4 = 0x69;

        *(undefined4 *)&obj->field_0xf0 = 0;

        *(undefined4 *)(*(int *)(dVar4 + 0x24) + 0xe4) = 3;

        return;

      }

      break;

    case 0x69:

      if (*(float *)&obj->field_0xf0 < 0.0 != (*(float *)&obj->field_0xf0 == 0.0)) {

        if (*(int *)(dVar4 + 0xc) == 0) {

          fVar15 = (float10)rndfloatrange(*(undefined4 *)(DAT_00632ed8 + 0xd0c),

                                          *(undefined4 *)(DAT_00632ed8 + 0xd10));

          *(float *)&obj->field_0xf0 = (float)fVar15;

          obj->pad_E4 = 0x68;

        }

        else {

          iVar10 = *(int *)(dVar4 + 0xc) + 0xa0;

          obj->field_0x208 = 0;

          if (iVar10 == 0) {

            param_1 = (OBJECT *)0x0;

          }

          else {

            fVar15 = (float10)dirfcalcp3d__FP3P3DT0(&obj->field_0xa0,iVar10);

            param_1 = (OBJECT *)(float)fVar15;

          }

          fVar15 = (float10)playerobj_turn(param_1,*(undefined4 *)&obj->field_0xc8);

          local_4c = (float *)(float)fVar15;

          if (ABS(fVar15) == (float10)0.0) {

            pfVar12 = (float *)0x0;

          }

          else {

            uVar7 = math_sign_of((float)local_4c * 0.05,0x3e800000);

            obj->field_0x208 = uVar7;

            obj->waypoint2 = (dword)param_1;

            obj->flags = obj->flags | 0x1000000;

            pfVar12 = local_4c;

          }

          if (ABS((float)pfVar12) < 3.0 == (ABS((float)pfVar12) == 3.0)) {

            return;

          }

          uVar9 = rndintrange(*(undefined4 *)(DAT_00632ed8 + 0xd18),

                              *(undefined4 *)(DAT_00632ed8 + 0xd1c));

          *(undefined4 *)&obj->field_0xf4 = uVar9;

          obj->pad_E4 = 0x6a;

        }

        goto LAB_004cf539;

      }

      local_48 = *(float *)&obj->field_0xfc;

      obj->field_0x208 = 0;

      fVar15 = (float10)playerobj_turn(local_48,*(undefined4 *)&obj->field_0xc8);

      param_1 = (OBJECT *)(float)fVar15;

      if (ABS(fVar15) == (float10)0.0) {

        param_1 = (OBJECT *)0x0;

      }

      else {

        uVar7 = math_sign_of((float)param_1 * 0.05,0x3e800000);

        obj->field_0x208 = uVar7;

        obj->waypoint2 = (dword)local_48;

        obj->flags = obj->flags | 0x1000000;

      }

      if (ABS((float)param_1) < 3.0 != (ABS((float)param_1) == 3.0)) {

        piVar1 = (int *)(*(int *)(*(int *)(dVar4 + 0x24) + 0x100) + 8);

        *piVar1 = *piVar1 + 1;

        obj->coll_radius = obj->coll_radius & 0xfffffffb;

        obj->pad_E4 = 0x6b;

        return;

      }

      break;

    case 0x6a:

      fVar15 = (float10)FRateGetSecsframe(obj,0);

      fVar15 = (float10)*(float *)&obj->field_0xf0 - fVar15;

      *(float *)&obj->field_0xf0 = (float)fVar15;

      if (fVar15 < (float10)0.0 != (fVar15 == (float10)0.0)) {

        if (*(int *)(dVar4 + 0xc) == 0) {

          *(undefined4 *)&obj->field_0xf4 = 0;

        }

        else if (obj->anim != 0x32) {

          anim_select_check2(obj,0x32);

        }

      }

      if (*(int *)&obj->field_0xf4 < 1) {

        *(undefined4 *)(dVar4 + 0xc) = 0;

        *(undefined4 *)(*(int *)(dVar4 + 0x24) + 0x274) = 0;

        fVar15 = (float10)rndfloatrange(*(undefined4 *)(DAT_00632ed8 + 0xd0c),

                                        *(undefined4 *)(DAT_00632ed8 + 0xd10));

        *(float *)&obj->field_0xf0 = (float)fVar15;

        obj->pad_E4 = 0x69;

        return;

      }

      break;

    case 0x6b:

      iVar10 = *(int *)(*(int *)(dVar4 + 0x24) + 0x100);

      if (*(int *)(iVar10 + 8) == *(int *)(iVar10 + 4)) {

        obj->pad_E4 = 0x68;

        obj->flags = obj->flags & 0xfcffffff;

        obj->field_0x208 = 0;

        *(undefined4 *)(*(int *)(dVar4 + 0x24) + 0xe4) = 2;

        goto LAB_004cf690;

      }

      break;

    case 0x6c:

      if ((obj->field_0x30 & 2) != 0) {

        obj->pad_E4 = 0x67;

      }

    case 0x67:

      iVar10 = obj_follow_owner_refpt(obj);

      if (iVar10 == *(int *)(dVar4 + 0x3c)) {

        iVar10 = *(int *)(*(int *)(dVar4 + 0x24) + 0x100);

        puVar11 = DAT_00632d68;

        if (DAT_00632d68 != (undefined4 *)0x0) {

          while (((iVar8 = puVar11[3], *(int *)(iVar8 + 4) != 0x41c ||

                  (*(int *)(iVar8 + 0xe8) != *(int *)(iVar10 + 0x14))) ||

                 (*(int *)(iVar8 + 0x174) != 0))) {

            puVar11 = (undefined4 *)*puVar11;

            if (puVar11 == (undefined4 *)0x0) {

              obj->pad_E4 = 0x68;

              return;

            }

          }

          *(int *)(iVar10 + 0x18) = iVar8;

          *(undefined4 *)(iVar10 + 0x20) = 0;

          *(undefined4 *)(iVar10 + 0x24) = *(undefined4 *)(iVar8 + 0xfc);

        }

        obj->pad_E4 = 0x68;

        return;

      }

    }

    return;

  }

  iVar10 = *(int *)(dVar4 + 0x10);

  if ((iVar10 != 0) &&

     (((char)((uint)*(undefined4 *)(iVar10 + 0xd8) >> 8) < '\0' ||

      ((*(int *)(iVar10 + 0x1e0) != 0x31 && (*(int *)(iVar10 + 0x1e0) != 0x2f)))))) {

    *(undefined4 *)(dVar4 + 0x10) = 0;

  }

  obj->flags = obj->flags & 0xfcffffff;

  obj->field_0x208 = 0;

  obj->field_0x20a = 0;

  switch(obj->pad_E4) {

  case 0:

    obj->ai_state_b = 100;

    if (*(int *)&obj->field_0xe8 == 2) {

      obj->pad_E4 = 0x55;

      *(undefined4 *)&obj->field_0x1bc = 0;

    }

    else if (*(int *)&obj->field_0xe8 == 0x65) {

      uVar9 = 0x4ff;

      pOVar16 = obj;

      sound_play_obj(0x4ff);

      *(uint *)&obj->field_0x1c8 = *(uint *)&obj->field_0x1c8 | 0xe00;

      obj->flags = obj->flags | 0x10;

      puVar11 = (undefined4 *)(dVar4 + 0x48);

      fVar15 = (float10)dirfcalcp3d__FP3P3DT0(&obj->field_0xa0,puVar11,uVar9,pOVar16);

      *(float *)&obj->field_0xc8 = (float)fVar15;

      ai_move_force_goal(obj,puVar11);

      *puVar11 = *(undefined4 *)&obj->field_0xa0;

      *(undefined4 *)(dVar4 + 0x4c) = *(undefined4 *)&obj->field_0xa4;

      *(undefined4 *)(dVar4 + 0x50) = *(undefined4 *)&obj->field_0xa8;

      obj->pad_E4 = 0x96;

      *(undefined4 *)(dVar4 + 0x20) = *(undefined4 *)&obj->field_0x194;

      *(undefined4 *)&obj->field_0x1bc = 0;

    }

    else if (obj->type_id == 0xe6) {

      sound_play_obj(0x4d3);

      obj->pad_E4 = 0x3d;

      *(undefined4 *)&obj->field_0x1bc = 0;

    }

    else if (obj->type_id == 0x49) {

      sound_play_obj(0x4ea);

      obj->pad_E4 = 0x1f;

      *(undefined4 *)(dVar4 + 0x20) = *(undefined4 *)&obj->field_0x194;

      *(undefined4 *)&obj->field_0x1bc = 0;

    }

    else {

      obj->pad_E4 = 5;

      *(undefined4 *)&obj->field_0x1bc = 0;

    }

    break;

  case 0x55:

    iVar10 = *(int *)(dVar4 + 0xc);

    dVar5 = obj->animate_state;

    if (((((iVar10 != 0) && (*(int *)(iVar10 + 4) != 0)) &&

         ((*(uint *)(iVar10 + 0xd8) & 0x4000c000) == 0)) &&

        (*(float *)(iVar10 + 0x278) < *(float *)(iVar10 + 0x1c0))) &&

       (((iVar8 = ObjIsMecc(iVar10), iVar8 == 0 || ((*(uint *)(iVar10 + 0xe0) & 0x2000000) == 0)) ||

        (4.0 <= *(float *)(dVar5 + 0x54))))) {

      iVar8 = ObjIsReaper(iVar10);

      if (iVar8 == 0) goto LAB_004cf982;

      uVar13 = obj->coll_radius;

      if ((*(byte *)(iVar10 + 0xe0) & 8) == 0) {

        obj->coll_radius = uVar13 & 0xffffffef;

        goto LAB_004cf982;

      }

      if ((uVar13 & 0x10) != 0) goto LAB_004cf982;

      obj->coll_radius = uVar13 | 0x10;

    }

    *(undefined4 *)(dVar4 + 0xc) = 0;

LAB_004cf982:

    fVar15 = (float10)FRateGetSecsframe(obj,0);

    fVar15 = (float10)*(float *)&obj->field_0xf0 - fVar15;

    *(float *)&obj->field_0xf0 = (float)fVar15;

    if (*(int *)(dVar4 + 0xc) == 0) {

      if (fVar15 < (float10)0.0) {

        injured_target_scan(obj,*(undefined4 *)(DAT_00632ed8 + 0xfc));

        if (*(int *)(dVar4 + 0xc) == 0) {

          fVar15 = (float10)rndfloatrange(0x3f000000,0x3fc00000);

          *(float *)&obj->field_0xf0 = (float)fVar15;

        }

        else {

          fVar15 = (float10)rndfloatrange(*(undefined4 *)(DAT_00632ed8 + 0xd0c),

                                          *(undefined4 *)(DAT_00632ed8 + 0xd10));

          *(float *)&obj->field_0xf0 = (float)fVar15;

        }

      }

    }

    else {

      param_1 = *(OBJECT **)(DAT_00632ed8 + 0xfc);

      fVar15 = (float10)distancesq2d__FP3P3DT0(&obj->field_0xa0,*(int *)(dVar4 + 0xc) + 0xa0);

      if ((float10)(float)param_1 * (float10)(float)param_1 < fVar15) {

        *(undefined4 *)(dVar4 + 0xc) = 0;

      }

    }

    fVar15 = (float10)dirfcalcp3d__FP3P3DT0(&obj->field_0xa0,DAT_00632a88 + 0xa0);

    *(float *)&obj->field_0xc8 = (float)fVar15;

    return;

  case 0x96:

    ai_goal_process(obj);

    if (*(int *)&obj->field_0x168 == 0) {

      fVar15 = (float10)rndfloatrange(0xc32a0000,0xc1200000);

      param_1 = (OBJECT *)(float)(fVar15 + (float10)*(float *)&obj->field_0xc8);

      sine_cos_lookup(param_1,&local_4c,&local_48);

      fVar15 = (float10)rndfloatrange(*(undefined4 *)(DAT_00632ed8 + 0xc98),

                                      *(undefined4 *)(DAT_00632ed8 + 0xc9c));

      local_34 = (float)(fVar15 * (float10)local_48 + (float10)*(float *)(dVar4 + 0x48));

      fVar15 = (float10)rndfloatrange(*(undefined4 *)(DAT_00632ed8 + 0xc98),

                                      *(undefined4 *)(DAT_00632ed8 + 0xc9c));

      local_30 = (float)(fVar15 * (float10)(float)local_4c + (float10)*(float *)(dVar4 + 0x4c));

      fVar15 = (float10)dirfcalcp3d__FP3P3DT0(&local_34,(float *)(dVar4 + 0x48));

      param_1 = (OBJECT *)(float)fVar15;

      main_ai_move_004014b0(obj,&local_34,param_1);

      *(uint *)&obj->field_0x1c8 = *(uint *)&obj->field_0x1c8 & 0xfffff1ff;

      obj->flags = obj->flags & 0xffffffef;

      obj->pad_E4 = 0x97;

    }

    break;

  case 0x97:

    ai_goal_process(obj);

    if (*(int *)&obj->field_0x168 == 0) {

      if (obj->type_id == 0xe6) {

        sound_play_obj(0x4d3);

        obj->pad_E4 = 0x3d;

      }

      else if (obj->type_id == 0x49) {

        sound_play_obj(0x4ea);

        obj->pad_E4 = 0x1f;

      }

      else {

        obj->pad_E4 = 5;

      }

    }

  }

  if (obj->type_id != 0xe6) {

    if (obj->type_id == 0x49) {

      verm_control(obj);

      dVar5 = obj->pad_E4;

      *(undefined4 *)&obj->field_0x194 = *(undefined4 *)(dVar4 + 0x20);

      if (((dVar5 != 0x1f) && (dVar5 != 0x22)) && (dVar5 != 0x24)) {

        return;

      }

      *(float *)&obj->field_0x194 =

           *(float *)(DAT_00632ed8 + 0x288) * *(float *)(dVar4 + 0x20) * 0.01;

      return;

    }

    pfVar12 = (float *)obj->animate_state;

    uVar13 = *(uint *)&obj->field_0x30 & 2;

    if (pfVar12[3] == 0.0) {

LAB_004d0a94:

      if (((byte)DAT_00632e70 & 3) != 3) {

LAB_004d0a9e:

        injured_target_scan(obj,*(undefined4 *)(DAT_00632ed8 + 0x88));

      }

    }

    else {

      if (((byte)DAT_00632e70 & 0xf) != 0xf) goto LAB_004d0a9e;

      if (pfVar12[3] == 0.0) goto LAB_004d0a94;

    }

    fVar17 = pfVar12[3];

    if (fVar17 == 0.0) {

      local_48 = 9.99998e+11;

      local_4c = (float *)0x5368d487;

      local_38 = 99999.0;

      local_3c = 99999.0;

      local_40 = 99999.0;

    }

    else {

      local_40 = *(float *)((int)fVar17 + 0xa0);

      local_3c = *(float *)((int)fVar17 + 0xa4);

      local_38 = *(float *)((int)fVar17 + 0xa8);

      fVar15 = (float10)distancesq2d__FP3P3DT0(&local_40,&obj->field_0xa0);

      local_48 = (float)fVar15;

      fVar15 = (float10)distancesq3d(&local_40,&obj->field_0xa0);

      local_4c = (float *)(float)fVar15;

      local_38 = *(float *)((int)fVar17 + 0x1e8) * *(float *)((int)fVar17 + 0xc4) + local_38;

    }

    fVar15 = (float10)distancesq2d__FP3P3DT0(&obj->field_0xa0,pfVar12 + 5);

    param_1 = (OBJECT *)(float)fVar15;

    if ((pfVar12[4] != 0.0) && (*(int *)((int)pfVar12[4] + 4) == 0xfd)) {

      param_1 = (OBJECT *)((float)param_1 * 0.010000001);

    }

    switch(obj->pad_E4) {

    case 5:

      if (*pfVar12 <= 0.0) {

        obj->pad_E4 = 6;

      }

      else {

        fVar15 = (float10)FRateGetSecsframe(obj,0);

        *pfVar12 = (float)((float10)*pfVar12 - fVar15);

        obj->field_0x20a = 0x18;

        if (*(float *)&obj->field_0xc8 != pfVar12[1]) {

          obj->flags = obj->flags | 0x1000000;

          obj->waypoint2 = (dword)pfVar12[1];

          fVar15 = (float10)playerobj_turn(pfVar12[1],*(undefined4 *)&obj->field_0xc8);

          uVar7 = 0x18;

          if (fVar15 <= (float10)0.0) {

            uVar7 = 0xe8;

          }

          obj->field_0x208 = uVar7;

        }

      }

      goto LAB_004d0e26;

    case 6:

      if (*pfVar12 <= 0.0) {

        local_44 = (float)crt_rand_scaled(100);

        if ((float)(int)local_44 <= *(float *)(DAT_00632ed8 + 0x98)) {

          fVar15 = (float10)dirfcalcp3d__FP3P3DT0(&obj->field_0xa0,pfVar12 + 5);

          fVar3 = *(float *)(DAT_00632ed8 + 0x90) * 0.75;

          if (fVar3 * fVar3 <= (float)param_1) {

            fVar15 = (float10)rndfloatrange((float)(fVar15 - (float10)60.0),

                                            (float)((float10)60.0 + fVar15));

            pfVar12[1] = (float)fVar15;

            diff_rangle__Fff(pfVar12 + 1);

          }

          else {

            fVar15 = (float10)rndfloat(0x43b40000);

            pfVar12[1] = (float)fVar15;

          }

          fVar15 = (float10)rndfloatrange(*(undefined4 *)(DAT_00632ed8 + 0xa0),

                                          *(undefined4 *)(DAT_00632ed8 + 0xa4));

          *pfVar12 = (float)fVar15;

          obj->pad_E4 = 5;

        }

        else {

          fVar15 = (float10)rndfloat(0x43b40000);

          pfVar12[1] = (float)fVar15;

          fVar15 = (float10)rndfloatrange(*(undefined4 *)(DAT_00632ed8 + 0xa8),

                                          *(undefined4 *)(DAT_00632ed8 + 0xac));

          *pfVar12 = (float)fVar15;

          obj->pad_E4 = 6;

        }

      }

      else {

        fVar15 = (float10)FRateGetSecsframe(obj,0);

        *pfVar12 = (float)((float10)*pfVar12 - fVar15);

        obj->field_0x20a = 1;

        if (*(float *)&obj->field_0xc8 != pfVar12[1]) {

          obj->flags = obj->flags | 0x1000000;

          obj->waypoint2 = (dword)pfVar12[1];

          playerobj_turn(pfVar12[1],*(undefined4 *)&obj->field_0xc8);

          uVar7 = __ftol();

          obj->field_0x208 = uVar7;

        }

      }

LAB_004d0e26:

      if (fVar17 != 0.0) {

        obj->pad_E4 = 7;

      }

      break;

    case 7:

      dVar4 = obj->animate_state;

      if (((((fVar17 == 0.0) || (*(int *)((int)fVar17 + 4) == 0)) ||

           ((*(uint *)((int)fVar17 + 0xd8) & 0x4000c000) != 0)) ||

          (*(float *)((int)fVar17 + 0x1c0) <= *(float *)((int)fVar17 + 0x278))) ||

         (((iVar10 = ObjIsMecc(fVar17), iVar10 != 0 &&

           ((*(uint *)((int)fVar17 + 0xe0) & 0x2000000) != 0)) && (*(float *)(dVar4 + 0x54) < 4.0)))

         ) goto LAB_004d10ab;

      iVar10 = ObjIsReaper(fVar17);

      if (iVar10 != 0) {

        uVar13 = obj->coll_radius;

        if ((*(byte *)((int)fVar17 + 0xe0) & 8) == 0) {

          obj->coll_radius = uVar13 & 0xffffffef;

        }

        else if ((uVar13 & 0x10) == 0) {

          obj->coll_radius = uVar13 | 0x10;

          goto LAB_004d10ab;

        }

      }

      local_44 = *(float *)(DAT_00632ed8 + 0xb0) * 0.25;

      fVar15 = (float10)distance2d__FP3P3DT0(&obj->field_0xa0,&local_40);

      param_1 = (OBJECT *)(float)fVar15;

      if ((float10)local_44 <= fVar15) {

        fVar15 = (float10)obj_face_target_move(obj,&local_40,0);

        obj->waypoint3 = (dword)local_40;

        obj->pad_160 = (dword)local_3c;

        obj->flags = obj->flags | 0x2000000;

        *(float *)&obj->field_0x164 = local_38;

        if ((float10)10.0 <= ABS(fVar15)) {

          obj->field_0x20a = 3;

        }

        else {

          uVar7 = math_sign_of((float)param_1 * 0.1,0x3e4ccccd);

          obj->field_0x20a = uVar7;

        }

      }

      if (*(float *)(DAT_00632ed8 + 0xb0) * *(float *)(DAT_00632ed8 + 0xb0) <= local_48) break;

      param_1 = (OBJECT *)crt_rand_scaled(100);

      if (*(float *)(DAT_00632ed8 + 0x94) < (float)(int)param_1) {

        obj->pad_E4 = 9;

        break;

      }

      goto LAB_004d135c;

    case 8:

      iVar10 = EnemyIsInvalid__FP6OBJECTT0(obj,fVar17);

      if (iVar10 == 0) {

        param_1 = *(OBJECT **)(DAT_00632ed8 + 0xb0);

        sine_cos_lookup(pfVar12[1],&local_44,&local_48);

        local_34 = local_44 * (float)param_1 + local_40;

        local_30 = local_3c - local_48 * (float)param_1;

        ai_face_move(obj,&local_34,0);

        fVar15 = (float10)dirfcalcp3d__FP3P3DT0((int)fVar17 + 0xa0,&obj->field_0xa0);

        param_1 = (OBJECT *)(float)fVar15;

        fVar15 = (float10)diff_angle(param_1,pfVar12[1]);

        if (fVar15 < (float10)10.0) {

          obj->pad_E4 = 9;

        }

        break;

      }

      goto LAB_004d10ab;

    case 9:

      iVar10 = EnemyIsInvalid__FP6OBJECTT0(obj,fVar17);

      if (iVar10 == 0) {

        fVar15 = (float10)dirfcalcp3d__FP3P3DT0(&obj->field_0xa0,(dword *)((int)fVar17 + 0xa0));

        param_1 = (OBJECT *)(float)fVar15;

        fVar15 = (float10)playerobj_turn(param_1,*(undefined4 *)&obj->field_0xc8);

        if (*(float *)&obj->field_0xc8 != (float)param_1) {

          obj->flags = obj->flags | 0x1000000;

          obj->waypoint2 = (dword)param_1;

          uVar7 = 0x20;

          if (fVar15 <= (float10)0.0) {

            uVar7 = 0xe0;

          }

          obj->field_0x208 = uVar7;

        }

        if (ABS(fVar15) < (float10)5.0) {

          obj->field_0x20a = 0x20;

        }

        *(uint *)&obj->field_0x1c8 = *(uint *)&obj->field_0x1c8 | 0x400;

        obj->waypoint3 = *(dword *)((int)fVar17 + 0xa0);

        obj->pad_160 = *(dword *)((int)fVar17 + 0xa4);

        *(undefined4 *)&obj->field_0x164 = *(undefined4 *)((int)fVar17 + 0xa8);

        obj->flags = obj->flags | 0x2000000;

        if ((float)local_4c < *(float *)(DAT_00632ed8 + 0xb8) * *(float *)(DAT_00632ed8 + 0xb8)) {

          *(float *)&obj->field_0x210 = fVar17;

          *(undefined4 *)&obj->field_0x214 = 1;

          uVar9 = crt_rand_scaled(4);

          *(undefined4 *)&obj->field_0x218 = uVar9;

          *(undefined4 *)&obj->field_0xec = *(undefined4 *)(DAT_00632ed8 + 0x9c);

          obj->pad_E4 = 10;

          iVar10 = crt_rand_scaled(100);

          if (iVar10 < 0x32) {

            sound_play_obj(0x4f7);

          }

          else {

            sound_play_obj(0x4f8);

          }

        }

        break;

      }

LAB_004d10ab:

      *pfVar12 = 0.0;

      obj->pad_E4 = 6;

      pfVar12[3] = 0.0;

      break;

    case 10:

      if (fVar17 == 0.0) {

        *(uint *)&obj->field_0x1c8 = *(uint *)&obj->field_0x1c8 & 0xfffffbff;

        obj->pad_E4 = 0x50;

        break;

      }

      fVar15 = (float10)FRateGetSecsframe(obj,0);

      iVar10 = *(int *)&obj->field_0x210;

      *(float *)&obj->field_0xec = (float)((float10)*(float *)&obj->field_0xec - fVar15);

      if (iVar10 != 0) {

        if (*(float *)(DAT_00632ed8 + 0x3ec) <

            *(float *)(iVar10 + 0xa8) - *(float *)(iVar10 + 0x140)) {

          *(undefined4 *)&obj->field_0xec = 0;

        }

        if (iVar10 != 0) {

          playerobj_lookud(iVar10,0,1,*(undefined4 *)(DAT_00632ed8 + 0x3f0),0,0);

        }

      }

      if (*(float *)&obj->field_0xec < 0.0 == (*(float *)&obj->field_0xec == 0.0)) break;

      *(undefined4 *)&obj->field_0x210 = 0;

      *(uint *)&obj->field_0x1c8 = *(uint *)&obj->field_0x1c8 & 0xfffffbff;

      pfVar12[3] = 0.0;

      iVar10 = crt_rand_scaled(100);

      if (iVar10 < 0x32) {

        iVar10 = 0x4f7;

      }

      else {

        iVar10 = 0x4f8;

      }

      sound_play_obj(iVar10);

      param_1 = (OBJECT *)crt_rand_scaled(100);

      if (*(float *)(DAT_00632ed8 + 0x94) < (float)(int)param_1) {

        obj->pad_E4 = 9;

        fVar15 = (float10)rndfloatrange(0xc1c80000,0x41c80000);

        obj->pad_128 = (dword)(float)fVar15;

        fVar15 = (float10)rndfloatrange(0xc1c80000,0x41c80000);

        *(float *)&obj->field_0x12c = (float)fVar15;

        obj->loc_accum0 = 0x41a00000;

        break;

      }

LAB_004d135c:

      obj->pad_E4 = 8;

      fVar15 = (float10)dirfcalcp3d__FP3P3DT0((int)fVar17 + 0xa0,&obj->field_0xa0);

      fVar15 = (float10)rndfloatrange((float)(fVar15 + (float10)90.0),

                                      (float)((float10)270.0 + fVar15));

      pfVar12[1] = (float)fVar15;

      diff_rangle__Fff(pfVar12 + 1);

      break;

    case 0xb:

      *pfVar12 = 0.0;

      obj->pad_E4 = (fVar17 != 0.0) + 6;

      break;

    case 0x50:

      obj->field_0x20a = 0x18;

      obj->field_0x208 = 0;

      fVar15 = (float10)FRateGetSecsframe(obj,0);

      fVar3 = *pfVar12;

      *pfVar12 = (float)((float10)fVar3 - fVar15);

      if ((float10)fVar3 - fVar15 < (float10)0.0) {

        obj->pad_E4 = (fVar17 != 0.0) + 6;

      }

      break;

    case 0x5a:

      if (uVar13 != 0) {

        obj->pad_E4 = 7;

        injured_target_scan(obj,*(undefined4 *)(DAT_00632ed8 + 0x140));

      }

      break;

    case 0x5b:

      obj->pad_184 = 0;

      *(uint *)&obj->field_0x1c8 = *(uint *)&obj->field_0x1c8 & 0xfffff3bf;

      obj->coll_radius = obj->coll_radius & 0xfffffffd;

      if (uVar13 != 0) {

        obj->pad_E4 = 0x5c;

        fVar15 = (float10)rndfloatrange(*(undefined4 *)(DAT_00632ed8 + 0x134),

                                        *(undefined4 *)(DAT_00632ed8 + 0x138));

        *(float *)&obj->field_0xec = (float)fVar15;

      }

      break;

    case 0x5c:

      fVar15 = (float10)FRateGetSecsframe(obj,0);

      fVar15 = (float10)*(float *)&obj->field_0xec - fVar15;

      *(float *)&obj->field_0xec = (float)fVar15;

      if (fVar15 < (float10)0.0) {

        obj->pad_E4 = 0x5d;

      }

      break;

    case 0x5d:

      if (uVar13 != 0) {

        obj->pad_E4 = 7;

        injured_target_scan(obj,*(undefined4 *)(DAT_00632ed8 + 0x140));

      }

      break;

    case 0x5e:

      smartie_mana_timer(obj);

    }

    if (obj->anim != 2) {

      return;

    }

    if (((float)obj->pad_14 < 0.6333333) || (0.6333333 <= *(float *)&obj->field_0x18)) {

      if ((float)obj->pad_14 < 1.9666667) {

        return;

      }

      if (1.9666667 <= *(float *)&obj->field_0x18) {

        return;

      }

    }

    sound_play_obj(0x4fe);

    return;

  }

  pfVar12 = (float *)obj->animate_state;

  local_44 = (float)obj->anim;

  uVar13 = *(uint *)&obj->field_0x30 & 2;

  if ((pfVar12[3] != 0.0) && ((char)((uint)*(undefined4 *)((int)pfVar12[3] + 0xd8) >> 8) < '\0')) {

    pfVar12[3] = 0.0;

  }

  local_4c = pfVar12;

  if (pfVar12[3] == 0.0) {

    injured_target_scan(obj,*(undefined4 *)(DAT_00632ed8 + 0xfc));

  }

  fVar17 = pfVar12[3];

  if (fVar17 == 0.0) {

    param_1 = (OBJECT *)0x5368d487;

    local_48 = 9.99998e+11;

    local_38 = 99999.0;

    local_3c = 99999.0;

    local_40 = 99999.0;

  }

  else {

    local_40 = *(float *)((int)fVar17 + 0xa0);

    local_3c = *(float *)((int)fVar17 + 0xa4);

    local_38 = *(float *)((int)fVar17 + 0xa8);

    fVar15 = (float10)distancesq2d__FP3P3DT0(&local_40,&obj->field_0xa0);

    param_1 = (OBJECT *)(float)fVar15;

    fVar15 = (float10)distancesq3d(&local_40,&obj->field_0xa0);

    local_48 = (float)fVar15;

    local_38 = *(float *)((int)fVar17 + 0x1e8) * *(float *)((int)fVar17 + 0xc4) + local_38;

    pfVar12 = local_4c;

  }

  switch(obj->pad_E4) {

  case 0x3d:

    XFGetViewport(local_28);

    param_1 = *(OBJECT **)(DAT_00632ed8 + 0x144);

    fVar15 = (float10)distancesq3d(local_28,&obj->field_0xa0);

    if (fVar15 <= (float10)(float)param_1 * (float10)(float)param_1) {

      obj->pad_184 = 0;

    }

    else {

      obj->pad_184 = 0x3f800000;

    }

    fVar15 = (float10)FRateGetSecsframe(obj,0);

    fVar3 = *pfVar12;

    *pfVar12 = (float)((float10)fVar3 - fVar15);

    if (((float10)fVar3 - fVar15 < (float10)0.0) && (fVar17 != 0.0)) {

      uVar9 = 0x4de;

      pOVar16 = obj;

      sound_play_obj(0x4de);

      obj->pad_E4 = 0x3e;

      obj->pad_184 = 0;

      *(uint *)&obj->field_0x1c8 = *(uint *)&obj->field_0x1c8 & 0xfffff7ff;

      ANM_DumpCluster(&obj->field_0xa0,uVar9,pOVar16);

      iVar10 = object_allocate_type(0xdb,0x11);

      object_copy_posdirinfo_2(iVar10,obj);

      *(undefined4 *)(iVar10 + 0xc4) = *(undefined4 *)&obj->field_0xc4;

      *(undefined4 *)(iVar10 + 0xe4) = 0;

      *(int *)&obj->field_0x274 = iVar10;

      *(OBJECT **)(iVar10 + 0x274) = obj;

      sound_stop_obj(0x4d3,obj);

    }

    break;

  case 0x3e:

    obj->field_0x208 = 0;

    fVar15 = (float10)dirfcalcp3d__FP3P3DT0(&obj->field_0xa0,&local_40);

    param_1 = (OBJECT *)(float)fVar15;

    fVar15 = (float10)playerobj_turn(param_1,*(undefined4 *)&obj->field_0xc8);

    if (ABS(fVar15) != (float10)0.0) {

      uVar7 = math_sign_of((float)(fVar15 * (float10)0.05),0x3e800000);

      obj->field_0x208 = uVar7;

      obj->waypoint2 = (dword)param_1;

      obj->flags = obj->flags | 0x1000000;

    }

    *(uint *)&obj->field_0x1c8 = *(uint *)&obj->field_0x1c8 & 0xffffffbf;

    if (uVar13 != 0) {

      obj->pad_E4 = 0x3f;

    }

    break;

  case 0x3f:

    dVar4 = obj->animate_state;

    if ((((fVar17 != 0.0) && (*(int *)((int)fVar17 + 4) != 0)) &&

        (((*(uint *)((int)fVar17 + 0xd8) & 0x4000c000) == 0 &&

         (*(float *)((int)fVar17 + 0x278) < *(float *)((int)fVar17 + 0x1c0))))) &&

       (((iVar10 = ObjIsMecc(fVar17), iVar10 == 0 ||

         ((*(uint *)((int)fVar17 + 0xe0) & 0x2000000) == 0)) || (4.0 <= *(float *)(dVar4 + 0x54)))))

    {

      iVar10 = ObjIsReaper(fVar17);

      if (iVar10 != 0) {

        uVar13 = obj->coll_radius;

        if ((*(byte *)((int)fVar17 + 0xe0) & 8) == 0) {

          obj->coll_radius = uVar13 & 0xffffffef;

        }

        else if ((uVar13 & 0x10) == 0) {

          obj->coll_radius = uVar13 | 0x10;

          goto LAB_004d0695;

        }

      }

      if (*(float *)(DAT_00632ed8 + 0x3d8) * *(float *)(DAT_00632ed8 + 0x3d8) <= (float)param_1) {

        if (*(float *)(DAT_00632ed8 + 0x100) * *(float *)(DAT_00632ed8 + 0x100) <= (float)param_1) {

          obj->pad_E4 = 0x40;

        }

        else {

          obj->pad_E4 = 0x41;

        }

      }

      else {

        obj->pad_E4 = 0x43;

      }

      break;

    }

    goto LAB_004d0695;

  case 0x40:

    dVar4 = obj->animate_state;

    if (((((fVar17 != 0.0) && (*(int *)((int)fVar17 + 4) != 0)) &&

         ((*(uint *)((int)fVar17 + 0xd8) & 0x4000c000) == 0)) &&

        (*(float *)((int)fVar17 + 0x278) < *(float *)((int)fVar17 + 0x1c0))) &&

       (((iVar10 = ObjIsMecc(fVar17), iVar10 == 0 ||

         ((*(uint *)((int)fVar17 + 0xe0) & 0x2000000) == 0)) || (4.0 <= *(float *)(dVar4 + 0x54)))))

    {

      iVar10 = ObjIsReaper(fVar17);

      if (iVar10 != 0) {

        uVar13 = obj->coll_radius;

        if ((*(byte *)((int)fVar17 + 0xe0) & 8) == 0) {

          obj->coll_radius = uVar13 & 0xffffffef;

        }

        else if ((uVar13 & 0x10) == 0) {

          obj->coll_radius = uVar13 | 0x10;

          goto LAB_004d0695;

        }

      }

      local_34 = *(float *)((int)fVar17 + 0xa0);

      local_30 = *(float *)((int)fVar17 + 0xa4);

      local_2c = *(undefined4 *)((int)fVar17 + 0xa8);

      fVar15 = (float10)distance2d__FP3P3DT0(&obj->field_0xa0,&local_34);

      local_48 = (float)fVar15;

      if ((float10)0.0 <= fVar15) {

        fVar15 = (float10)obj_face_target_move(obj,&local_34,0);

        obj->waypoint3 = (dword)local_34;

        obj->pad_160 = (dword)local_30;

        *(undefined4 *)&obj->field_0x164 = local_2c;

        obj->flags = obj->flags | 0x2000000;

        if ((float10)10.0 <= ABS(fVar15)) {

          obj->field_0x20a = 3;

        }

        else {

          uVar7 = math_sign_of(local_48 * 0.1,0x3e4ccccd);

          obj->field_0x20a = uVar7;

        }

      }

      if ((float)param_1 < *(float *)(DAT_00632ed8 + 0x100) * *(float *)(DAT_00632ed8 + 0x100)) {

        obj->pad_E4 = 0x41;

      }

      break;

    }

    goto LAB_004d0695;

  case 0x41:

    local_48 = (float)obj->animate_state;

    if (((fVar17 != 0.0) && (*(int *)((int)fVar17 + 4) != 0)) &&

       ((((*(uint *)((int)fVar17 + 0xd8) & 0x4000c000) == 0 &&

         (*(float *)((int)fVar17 + 0x278) < *(float *)((int)fVar17 + 0x1c0))) &&

        (((iVar10 = ObjIsMecc(fVar17), iVar10 == 0 ||

          ((*(uint *)((int)fVar17 + 0xe0) & 0x2000000) == 0)) ||

         (4.0 <= *(float *)((int)local_48 + 0x54))))))) {

      iVar10 = ObjIsReaper(fVar17);

      if (iVar10 != 0) {

        uVar6 = obj->coll_radius;

        if ((*(byte *)((int)fVar17 + 0xe0) & 8) == 0) {

          obj->coll_radius = uVar6 & 0xffffffef;

        }

        else if ((uVar6 & 0x10) == 0) {

          obj->coll_radius = uVar6 | 0x10;

          goto LAB_004d0695;

        }

      }

      obj->field_0x208 = 0;

      if ((int)fVar17 + 0xa0 == 0) {

        local_4c = (float *)0x0;

      }

      else {

        fVar15 = (float10)dirfcalcp3d__FP3P3DT0(&obj->field_0xa0,(int)fVar17 + 0xa0);

        local_4c = (float *)(float)fVar15;

      }

      fVar15 = (float10)playerobj_turn(local_4c,*(undefined4 *)&obj->field_0xc8);

      if (ABS(fVar15) != (float10)0.0) {

        uVar7 = math_sign_of((float)(fVar15 * (float10)0.05),0x3e800000);

        obj->field_0x208 = uVar7;

        obj->waypoint2 = (dword)local_4c;

        obj->flags = obj->flags | 0x1000000;

      }

      if (uVar13 == 0) {

        if ((*(float *)&obj->field_0x18 < 0.43333334) && (0.43333334 <= (float)obj->pad_14)) {

          make_spit__FP6OBJECTP3P3Df(obj,&local_40,*(undefined4 *)(DAT_00632ed8 + 0x11c));

        }

      }

      else if (*(float *)(DAT_00632ed8 + 0x3d8) * *(float *)(DAT_00632ed8 + 0x3d8) <= (float)param_1

              ) {

        if ((*(float *)(DAT_00632ed8 + 0x104) * *(float *)(DAT_00632ed8 + 0x104) <= (float)param_1)

           || (param_1 = (OBJECT *)crt_rand_scaled(100),

              *(float *)(DAT_00632ed8 + 0x108) <= (float)(int)param_1)) {

          *pfVar12 = *(float *)(DAT_00632ed8 + 0x10c);

          obj->pad_E4 = 0x42;

        }

        else {

          obj->pad_E4 = 0x43;

        }

      }

      else {

        obj->pad_E4 = 0x43;

      }

      break;

    }

    goto LAB_004d0695;

  case 0x42:

    fVar15 = (float10)FRateGetSecsframe(obj,0);

    fVar17 = *pfVar12;

    *pfVar12 = (float)((float10)fVar17 - fVar15);

    if ((float10)fVar17 - fVar15 < (float10)0.0) {

      if (*(float *)(DAT_00632ed8 + 0x3d8) * *(float *)(DAT_00632ed8 + 0x3d8) <= (float)param_1) {

        sound_play_obj(0x4e0);

        obj->pad_E4 = 0x47;

        fVar15 = (float10)rndfloatrange(*(undefined4 *)(DAT_00632ed8 + 0x110),

                                        *(undefined4 *)(DAT_00632ed8 + 0x114));

        *pfVar12 = (float)fVar15;

      }

      else {

        obj->pad_E4 = 0x43;

      }

    }

    break;

  case 0x43:

    dVar4 = obj->animate_state;

    if ((((fVar17 != 0.0) && (*(int *)((int)fVar17 + 4) != 0)) &&

        ((*(uint *)((int)fVar17 + 0xd8) & 0x4000c000) == 0)) &&

       ((*(float *)((int)fVar17 + 0x278) < *(float *)((int)fVar17 + 0x1c0) &&

        (((iVar10 = ObjIsMecc(fVar17), iVar10 == 0 ||

          ((*(uint *)((int)fVar17 + 0xe0) & 0x2000000) == 0)) || (4.0 <= *(float *)(dVar4 + 0x54))))

        ))) {

      iVar10 = ObjIsReaper(fVar17);

      if (iVar10 != 0) {

        uVar13 = obj->coll_radius;

        if ((*(byte *)((int)fVar17 + 0xe0) & 8) == 0) {

          obj->coll_radius = uVar13 & 0xffffffef;

        }

        else if ((uVar13 & 0x10) == 0) {

          obj->coll_radius = uVar13 | 0x10;

          goto LAB_004d0695;

        }

      }

      pdVar14 = (dword *)((int)fVar17 + 0xa0);

      obj->field_0x208 = 0;

      if (pdVar14 == (dword *)0x0) {

        local_4c = (float *)0x0;

      }

      else {

        fVar15 = (float10)dirfcalcp3d__FP3P3DT0(&obj->field_0xa0,pdVar14);

        local_4c = (float *)(float)fVar15;

      }

      fVar15 = (float10)playerobj_turn(local_4c,*(undefined4 *)&obj->field_0xc8);

      local_48 = (float)fVar15;

      if (ABS(fVar15) == (float10)0.0) {

        fVar3 = 0.0;

      }

      else {

        uVar7 = math_sign_of(local_48 * 0.05,0x3e800000);

        obj->field_0x208 = uVar7;

        obj->waypoint2 = (dword)local_4c;

        obj->flags = obj->flags | 0x1000000;

        fVar3 = local_48;

      }

      if (ABS(fVar3) < 5.0) {

        obj->field_0x20a = 0x20;

      }

      obj->waypoint3 = *pdVar14;

      obj->pad_160 = *(dword *)((int)fVar17 + 0xa4);

      uVar9 = *(undefined4 *)((int)fVar17 + 0xa8);

      obj->flags = obj->flags | 0x2000000;

      *(undefined4 *)&obj->field_0x164 = uVar9;

      if ((float)param_1 < *(float *)(DAT_00632ed8 + 0x118) * *(float *)(DAT_00632ed8 + 0x118)) {

        param_1 = (OBJECT *)crt_rand_scaled(100);

        if (*(float *)(DAT_00632ed8 + 0x128) <= (float)(int)param_1) {

          sound_play_obj(0x4cf);

          obj->pad_E4 = 0x44;

        }

        else {

          obj->pad_E4 = 0x45;

        }

      }

      break;

    }

    goto LAB_004d0695;

  case 0x44:

    iVar10 = EnemyIsInvalid__FP6OBJECTT0(obj,fVar17);

    if (iVar10 == 0) {

      obj_face_target_move(obj,(int)fVar17 + 0xa0,0);

      if ((uVar13 != 0) &&

         (obj->pad_E4 = 0x42,

         local_48 < *(float *)(DAT_00632ed8 + 0x118) * *(float *)(DAT_00632ed8 + 0x118))) {

        obj_damage_apply(2,*(undefined4 *)(DAT_00632ed8 + 0x3dc),fVar17,obj,0,0);

      }

      break;

    }

    goto LAB_004d0695;

  case 0x45:

    iVar10 = EnemyIsInvalid__FP6OBJECTT0(obj,fVar17);

    if (iVar10 == 0) {

      obj_face_target_move(obj,(int)fVar17 + 0xa0,0);

      if ((local_44 == 7.14662e-44) && (0.6666667 <= (float)obj->pad_14)) {

        iVar10 = enemy_check_player_grab__FP6OBJECTif(obj,0,0x41000000);

        if ((iVar10 == 0) || (*(int *)(iVar10 + 4) == 1)) {

          if (1.2333333 <= (float)obj->pad_14) {

            obj->pad_E4 = 0x42;

          }

        }

        else {

          sound_play_3dpos(0x4cf,&obj->field_0xa0);

          obj->pad_E4 = 0x46;

          *(OBJECT **)(iVar10 + 0x210) = obj;

          *(undefined4 *)(iVar10 + 0x214) = 4;

          *(undefined4 *)(iVar10 + 0x218) = 0;

        }

      }

      break;

    }

LAB_004d0695:

    sound_play_obj(0x4e0);

    obj->pad_E4 = 0x47;

    pfVar12[3] = 0.0;

    break;

  case 0x46:

    if ((3.4333334 <= (float)obj->pad_14) && (iVar10 = smartie_injured_pet_find(obj), iVar10 != 0))

    {

      *(undefined4 *)(iVar10 + 0x210) = 0;

      sine_cos_lookup(*(undefined4 *)&obj->field_0xc8,&param_1,&local_44);

      *(float *)(iVar10 + 0x128) =

           *(float *)(DAT_00632ed8 + 300) * (float)param_1 * *(float *)&obj->field_0xc4;

      *(float *)(iVar10 + 300) =

           -(*(float *)(DAT_00632ed8 + 300) * local_44 * *(float *)&obj->field_0xc4);

      *(float *)(iVar10 + 0x130) = *(float *)(DAT_00632ed8 + 0x130) * *(float *)&obj->field_0xc4;

      obj_damage_apply(2,*(undefined4 *)(DAT_00632ed8 + 1000),iVar10,obj,0,0);

    }

    if (uVar13 != 0) {

      obj->pad_E4 = 0x42;

    }

    break;

  case 0x47:

    if (0.73333335 < (float)obj->pad_14) {

      iVar10 = *(int *)&obj->field_0x274;

      *(uint *)&obj->field_0x1c8 = *(uint *)&obj->field_0x1c8 | 0x40;

      if ((iVar10 != 0) && (*(int *)(iVar10 + 4) == 0xdb)) {

        *(undefined4 *)(iVar10 + 0xe4) = 2;

      }

    }

    if (uVar13 != 0) {

      ANM_DumpCluster(&obj->field_0xa0);

      sound_play_obj(0x4d3);

      obj->pad_E4 = 0x3d;

      *(uint *)&obj->field_0x1c8 = *(uint *)&obj->field_0x1c8 | 0x840;

    }

    break;

  case 0x50:

    obj->field_0x20a = 0x18;

    obj->field_0x208 = 0;

    fVar15 = (float10)FRateGetSecsframe(obj,0);

    fVar17 = *pfVar12;

    *pfVar12 = (float)((float10)fVar17 - fVar15);

    if ((float10)fVar17 - fVar15 < (float10)0.0) {

      injured_target_scan(obj,*(undefined4 *)(DAT_00632ed8 + 0x140));

      if (pfVar12[3] == 0.0) {

        sound_play_obj(0x4e0);

        obj->pad_E4 = 0x47;

      }

      else {

        obj->pad_E4 = 0x3f;

      }

    }

    break;

  case 0x5a:

    if (uVar13 != 0) {

      obj->pad_E4 = 0x3f;

      injured_target_scan(obj,*(undefined4 *)(DAT_00632ed8 + 0x140));

    }

    break;

  case 0x5b:

    obj->pad_184 = 0;

    *(uint *)&obj->field_0x1c8 = *(uint *)&obj->field_0x1c8 & 0xfffff3bf;

    obj->coll_radius = obj->coll_radius & 0xfffffffd;

    if (uVar13 != 0) {

      obj->pad_E4 = 0x5c;

      fVar15 = (float10)rndfloatrange(*(undefined4 *)(DAT_00632ed8 + 0x134),

                                      *(undefined4 *)(DAT_00632ed8 + 0x138));

      *(float *)&obj->field_0xec = (float)fVar15;

    }

    break;

  case 0x5c:

    fVar15 = (float10)FRateGetSecsframe(obj,0);

    fVar15 = (float10)*(float *)&obj->field_0xec - fVar15;

    *(float *)&obj->field_0xec = (float)fVar15;

    if (fVar15 < (float10)0.0) {

      obj->pad_E4 = 0x5d;

    }

    break;

  case 0x5d:

    if (uVar13 != 0) {

      obj->pad_E4 = 0x3f;

      injured_target_scan(obj,*(undefined4 *)(DAT_00632ed8 + 0x140));

    }

    break;

  case 0x5e:

    smartie_mana_timer(obj);

  }

  if (obj->anim != 2) {

    return;

  }

  if (((float)obj->pad_14 < 0.6333333) || (0.6333333 <= *(float *)&obj->field_0x18)) {

    if ((float)obj->pad_14 < 1.9666667) {

      return;

    }

    if (1.9666667 <= *(float *)&obj->field_0x18) {

      return;

    }

  }

  sound_play_obj(0x4d6);

  return;

}

