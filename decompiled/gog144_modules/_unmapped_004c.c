/* Giants 1.449 — module _unmapped_004c
 * 64 functions (27 named) — decompiled, names from PS2 symbols
 * Original source: C:\Giants\source\_unmapped_004c.c(pp) (assert-string evidence)
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

  FUN_004993c0(iVar2,param_2);

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

  iVar4 = FUN_0052e480(param_1);

  if (iVar4 == 0) {

    *(undefined4 *)(iVar2 + 0x188) = param_3;

    *(undefined4 *)(puVar1[1] + 0x188) = param_4;

  }

  FUN_004993c0(puVar1[1],param_2);

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

/* ===== FUN_004c03a0 @ 0x004C03A0 ===== */
/* PS2 candidate: reaper_finish_cloak (conf 0.4) */



void FUN_004c03a0(int param_1,undefined4 param_2)



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

    iVar3 = FUN_0052e480(param_1);

    if (iVar3 != 0) {

      FUN_004bea70(param_1,0x2c,param_2,0,0xffffffff);

    }

    *puVar2 = *puVar2 & 0xffffffbf;

    return;

  }

  iVar3 = FUN_0052e480(param_1);

  if (iVar3 == 0) {

    *puVar2 = *puVar2 | 0x40;

  }

  else {

    iVar4 = FUN_004a8f50(0x2c);

    iVar5 = FUN_004add50(0x2c);

    pcVar6 = FUN_004ba1a0;

    iVar3 = param_1;

    if (iVar5 != 0) {

      pcVar6 = *(code **)(iVar5 + 8);

      iVar3 = param_1 + 0x18c;

    }

    if (iVar4 != 0) {

      uVar1 = *(undefined4 *)(DAT_00632ed8 + 0x1058);

      iVar4 = FUN_0040ce90();

      if (iVar4 == 0) {

        iVar4 = FUN_00456050(param_1);

        (*(code *)PTR_FUN_00580c18)(local_44,iVar4 + 0x294,*(undefined4 *)(iVar4 + 0x2dc));

        fStack_5c = -*(float *)(param_1 + 0x29c);

        fStack_58 = -*(float *)(param_1 + 0x2ac);

        fStack_54 = -*(float *)(param_1 + 700);

        FUN_0050a810(&fStack_5c,&fStack_58,&fStack_54);

        uStack_50 = uStack_34;

        uStack_4c = uStack_24;

        uStack_48 = uStack_14;

        FUN_00455920(pcVar6,iVar3,uVar1,puVar2 + 0x393,&uStack_50,&fStack_5c);

      }

      else {

        FUN_00455b70(pcVar6,iVar3,uVar1,puVar2 + 0x393);

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

/* ===== FUN_004c0550 @ 0x004C0550 ===== */
/* PS2 candidate: reaper_create_fake_reaper__FP6OBJECTP3P3Dfi (conf 0.44) */



void FUN_004c0550(float *param_1,float *param_2)



{

  float *pfVar1;

  int iVar2;

  int iVar3;

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

    fVar5 = (float10)FUN_004d5780(0x40a00000,0x41200000);

    fVar6 = (float10)FUN_004d5780(-*(float *)(DAT_00632ed8 + 0x75c),

                                  *(undefined4 *)(DAT_00632ed8 + 0x75c));

    local_58 = (float)(fVar6 + (float10)*pfVar1);

    fVar6 = (float10)FUN_004d5780(-*(float *)(DAT_00632ed8 + 0x75c),

                                  *(undefined4 *)(DAT_00632ed8 + 0x75c));

    local_50 = *(float *)(iVar2 + 0xa8);

    local_54 = (float)(fVar6 + (float10)*(float *)(iVar2 + 0xa4));

    FUN_00414690(&local_58,local_4c);

    local_50 = local_3c;

    iVar3 = reaper_0052e4a0(iVar2);

    if (iVar3 != 0) {

      *param_1 = local_58;

      param_1[1] = local_54;

      param_1[2] = local_50;

      afStack_c[iVar4] = (float)fVar5;

    }

    iVar3 = FUN_0052e480(iVar2);

    if (iVar3 != 0) {

      iVar3 = object_allocate_type(*(undefined4 *)(iVar2 + 4),0x80000000);

      *(undefined4 *)(iVar3 + 0x18c) = *(undefined4 *)(iVar2 + 0x18c);

      FUN_00455c80(iVar3,1,0x29d);

      object_change_ospec(iVar3,0x55);

      *(float *)(iVar3 + 0xf4) = (float)fVar5;

      FUN_004993c0(iVar3,&local_58);

      *(uint *)(iVar3 + 0x1c8) = *(uint *)(iVar3 + 0x1c8) | 0x20000;

      *(int *)(iVar3 + 0x274) = iVar2;

      if ((DAT_00560c50 != 0xfe) && (*(int *)(*(int *)(iVar2 + 8) + 8 + DAT_00560c50 * 4) != 0)) {

        FUN_004034a0(iVar3,DAT_00560c50,1,0,0,0x3e2aaaab);

      }

      sound_play_obj(0x3c0,iVar3);

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

/* ===== FUN_004c0810 @ 0x004C0810 ===== */
/* PS2 candidate: reaper_fire_sword__FP6OBJECT (conf 0.456) */



void FUN_004c0810(float param_1)



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

          fVar11 = (float10)FUN_0050a520(iVar3 + 0xa0,iVar7 + 0xa0);

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

            fVar11 = (float10)FUN_0050a400(iVar3 + 0xa0,iVar7 + 0xa0);

            local_50 = (float)fVar11;

            fVar11 = (float10)FUN_0050a7c0(local_50,*(undefined4 *)(iVar3 + 200));

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

        iVar7 = FUN_0052e480(iVar3);

        if (iVar7 == 0) {

          return;

        }

        if ((~*(uint *)(iVar5 + 0x1c8) >> 0x11 & 1) != 0 ||

            (*(uint *)(iVar5 + 0xd8) & 0x4000c000) != 0) {

          local_4c = *(float *)(iVar5 + 0xa0);

          local_48 = *(float *)(iVar5 + 0xa4);

          local_44 = *(float *)(iVar5 + 0x1e8) * *(float *)(iVar5 + 0xc4) + *(float *)(iVar5 + 0xa8)

          ;

          uVar8 = FUN_00456050(iVar3);

          FUN_004a76e0(uVar8,0,&local_40);

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

        FUN_00456f80(0x17,uVar8,iVar5,iVar3,0,0);

        *(uint *)(iVar3 + 0xe0) = *(uint *)(iVar3 + 0xe0) | 0x400;

        local_4c = *(float *)(iVar5 + 0xa0);

        local_48 = *(float *)(iVar5 + 0xa4);

        local_44 = *(float *)(iVar5 + 0x1e8) * *(float *)(iVar5 + 0xc4) + *(float *)(iVar5 + 0xa8);

        uVar8 = FUN_00456050(iVar3);

        FUN_004a76e0(uVar8,0,&local_40);

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

    iVar5 = FUN_004eed30(&local_4c,&local_40);

    if (iVar5 == 0) {

      *(uint *)(iVar3 + 0xe0) = *(uint *)(iVar3 + 0xe0) | 0x1000;

      *(float *)(iVar3 + 0x128) = *(float *)(iVar3 + 0x128) - param_1 * 40.0;

      *(float *)(iVar3 + 300) = (float)local_54 * 40.0 + *(float *)(iVar3 + 300);

      smoke_object_spawn(&local_40);

    }

  }

  return;

}

/* ===== FUN_004c0fc0 @ 0x004C0FC0 ===== */
/* PS2 candidate: reaper_tornado_create (conf 0.493) */



void FUN_004c0fc0(int param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)



{

  int iVar1;

  int iVar2;

  int iVar3;

  undefined4 local_14;

  undefined4 local_10;

  undefined4 local_c;

  undefined4 local_8;

  undefined4 local_4;

  

  iVar1 = object_allocate_type(0x28,0x80000000);

  if (param_1 != 0) {

    *(undefined4 *)(iVar1 + 0x18c) = *(undefined4 *)(param_1 + 0x18c);

  }

  FUN_004993c0(iVar1,param_2);

  *(uint *)(iVar1 + 0xd8) = *(uint *)(iVar1 + 0xd8) | 0x40000000;

  *(undefined4 *)(iVar1 + 0xec) = *(undefined4 *)(DAT_00632ed8 + 0x314);

  *(undefined4 *)(iVar1 + 0xe4) = 0;

  *(undefined4 *)(iVar1 + 0xf4) = 0;

  *(undefined4 *)(iVar1 + 0xfc) = 0x3f000000;

  iVar2 = object_spawn_small(iVar1,0x18,0,0,0);

  *(undefined4 *)(iVar2 + 0x210) = 0;

  *(uint *)(iVar2 + 0xd8) = *(uint *)(iVar2 + 0xd8) | 0x14;

  FUN_004034a0(iVar2,10,0x24,0,0,0);

  *(undefined4 *)(iVar2 + 0x184) = 0x3f800000;

  *(undefined4 *)(iVar2 + 0xfc) = 0x3f000000;

  *(int *)(iVar1 + 0x274) = iVar2;

  if (param_1 != 0) {

    *(int *)(param_1 + 0x274) = iVar1;

    if ((**(byte **)(param_1 + 0x104) & 0x40) == 0) {

      sound_play_player(0x39e,param_1);

      *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 0x10000000;

    }

    iVar3 = reaper_0052e4a0(param_1);

    if (iVar3 == 0) {

      iVar3 = FUN_0052e480(param_1);

      if (iVar3 == 0) {

        *(undefined4 *)(iVar2 + 0x188) = param_3;

        *(undefined4 *)(iVar1 + 0x188) = param_4;

      }

    }

    else {

      local_14 = *param_2;

      local_10 = param_2[1];

      local_c = param_2[2];

      local_8 = *(undefined4 *)(iVar2 + 0x188);

      local_4 = *(undefined4 *)(iVar1 + 0x188);

      reaper_00530bd0(param_1,3,2,0,10,&local_14);

    }

  }

  sound_get_free_sequence__Fv();

  return;

}

/* ===== FUN_004c1170 @ 0x004C1170 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* PS2 candidate: reaper_check_enter_jet_ski__FP6OBJECT (conf 0.463) */



void FUN_004c1170(int param_1)



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

    FUN_004b9390(iVar4,*(undefined4 *)(iVar2 + 0xd3c + *(int *)(iVar2 + 0xdb0) * 0xc),0xffffffff,0);

  }

  if ((*(byte *)(iVar4 + 0x20c) & 0x10) != 0) {

    reaper_ability_sound(iVar4);

  }

  if ((*(byte *)(iVar4 + 0x20c) & 0x20) != 0) {

    reaper_cast_cloak_firecircle

              (iVar4,*(undefined4 *)(iVar2 + 0xd3c + *(int *)(iVar2 + 0xdb0) * 0xc));

    *(uint *)(iVar4 + 0x20c) = *(uint *)(iVar4 + 0x20c) & 0xffff83ff;

  }

  fVar10 = (float10)FUN_00518b70(iVar4,0);

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

        FUN_0053e460(local_44,-*(float *)(DAT_00632ed8 + 0x120c),0,*(undefined4 *)(iVar4 + 200));

        FUN_004a76e0(iVar4,0xffffffff,&local_5c);

        local_50 = local_3c * -1000.0 + local_5c;

        local_4c = local_2c * -1000.0 + local_58;

        local_48 = local_1c * -1000.0 + local_54;

        FUN_004bea70(iVar4,0x32,&local_50,0,0xffffffff);

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

  iVar8 = FUN_0052e480(iVar4);

  if (iVar8 != 0) {

    fVar10 = (float10)FUN_00518b70(0,0);

    fVar10 = (float10)*(float *)(iVar2 + 0xfa8) - fVar10;

    *(float *)(iVar2 + 0xfa8) = (float)fVar10;

    puVar3 = DAT_00632d68;

    if (fVar10 < (float10)0.0) {

      for (; puVar3 != (undefined4 *)0x0; puVar3 = (undefined4 *)*puVar3) {

        iVar8 = puVar3[3];

        if ((((-1 < (char)((uint)*(undefined4 *)(iVar8 + 0xd8) >> 8)) &&

             (iVar6 = FUN_004a6120(iVar8), iVar6 != 0)) &&

            ((*(int *)(iVar8 + 0x18c) == *(int *)(iVar4 + 0x18c) || (*(int *)(iVar8 + 0x18c) == 0)))

            ) && (((*(int *)(iVar8 + 0x274) == 0 &&

                   (fVar10 = (float10)FUN_0050a610(iVar4 + 0xa0,iVar8 + 0xa0),

                   fVar10 <= (float10)100.0)) && (*(int *)(iVar8 + 0x210) == 0)))) {

          iVar6 = FUN_004a63a0(iVar4);

          if (iVar6 == 0) {

            if ((*(byte *)(iVar4 + 0xe0) & 2) == 0) {

              iVar6 = reaper_0052e4a0(iVar4);

              if (iVar6 == 0) {

                object_attach_target(iVar4,iVar8);

              }

              else {

                param_1 = *(undefined4 *)(iVar4 + 0x188);

                FUN_00530f10(iVar8,0,1,0,4,&param_1);

                FUN_004d77e0(iVar8,4,4,&param_1);

              }

            }

            goto LAB_004c157c;

          }

          pcVar7 = (char *)FUN_00507b00(s_FlagHintDriveGyro_0055bccc);

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

    iVar5 = FUN_004c1de0(iVar1);

    if (iVar5 == 0) {

      FUN_004c1ee0();

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

    iVar5 = FUN_004c1de0(param_1);

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

    FUN_004c2140(param_1,iVar2 + 0xf4c);

    FUN_004c2320(iVar1);

    *(undefined4 *)(iVar2 + 0xda8) = *(undefined4 *)(DAT_00632ed8 + 0x1508);

    return;

  case 0x19:

    FUN_004c2320(param_1);

    reaper_ability_playersound(iVar1,iVar2 + 0xf4c);

    *(undefined4 *)(iVar2 + 0xda8) = *(undefined4 *)(DAT_00632ed8 + 0x14fc);

    return;

  case 0x1b:

    iVar1 = *(int *)(iVar2 + 0xdb0) * 3 + 0x351;

    *(float *)(iVar2 + iVar1 * 4) =

         *(float *)(iVar2 + iVar1 * 4) - *(float *)(iVar2 + 0xd40 + *(int *)(iVar2 + 0xdb0) * 0xc);

    FUN_004c1f80(param_1,iVar2 + 0xf4c);

    *(undefined4 *)(iVar2 + 0xda8) = *(undefined4 *)(DAT_00632ed8 + 0x14f4);

    return;

  case 0x1c:

    FUN_004c2320(param_1);

    reaper_ability_playersound3(iVar1,iVar2 + 0xf4c);

    *(undefined4 *)(iVar2 + 0xda8) = *(undefined4 *)(DAT_00632ed8 + 0x1504);

    return;

  case 0x1d:

    iVar5 = *(int *)(iVar2 + 0xdb0) * 3 + 0x351;

    *(float *)(iVar2 + iVar5 * 4) =

         *(float *)(iVar2 + iVar5 * 4) - *(float *)(iVar2 + 0xd40 + *(int *)(iVar2 + 0xdb0) * 0xc);

    iVar5 = *(int *)(param_1 + 0x100);

    iVar4 = FUN_004c1de0(param_1);

    if (iVar4 == 0) {

      *(uint *)(iVar1 + 0xe0) = *(uint *)(iVar1 + 0xe0) & 0xffefffff;

      iVar4 = FUN_0052e480();

      if (iVar4 != 0) {

        FUN_004bea70(iVar1,0x24,(undefined4 *)(iVar2 + 0xf4c),0,0xffffffff);

      }

    }

    else {

      sound_play_player(0x3a4,iVar1);

      *(uint *)(iVar1 + 0xe0) = *(uint *)(iVar1 + 0xe0) | 0x100000;

    }

    iVar4 = FUN_0052e480(iVar1);

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

    iVar4 = FUN_004c1de0(param_1);

    if (iVar4 == 0) {

      iVar4 = FUN_0052e480();

      if (iVar4 != 0) {

        iVar4 = FUN_0052aa70();

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

    FUN_0050a810(&local_34,&local_30,&local_2c);

    local_34 = *(float *)(DAT_00632ed8 + 0x834) * local_34 + *(float *)(iVar1 + 0xa0);

    local_30 = *(float *)(DAT_00632ed8 + 0x834) * local_30 + *(float *)(iVar1 + 0xa4);

    local_2c = *(float *)(DAT_00632ed8 + 0x834) * local_2c + *(float *)(iVar1 + 0xa8);

    FUN_00414690(&local_34,local_1c);

    iVar5 = *(int *)(iVar1 + 0x100);

    local_2c = local_c;

    *(float *)(iVar5 + 0xf2c) = local_34;

    *(float *)(iVar5 + 0xf30) = local_30;

    *(float *)(iVar5 + 0xf34) = local_c;

    if (((*(uint *)(iVar1 + 0xd8) & 0x80000) == 0) || ((**(byte **)(iVar1 + 0x104) & 0x40) != 0)) {

      iVar4 = FUN_0052e480(iVar1);

      if (iVar4 != 0) {

        iVar4 = FUN_0052aa70();

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

    FUN_004c2320(param_1);

    FUN_004c0fc0(iVar1,iVar2 + 0xf4c,0xffffffff,0xffffffff);

    *(undefined4 *)(iVar2 + 0xda8) = *(undefined4 *)(DAT_00632ed8 + 0x1500);

    return;

  case 0x3f:

    FUN_004c03a0(param_1,iVar2 + 0xf4c);

    break;

  case 0x49:

    if (((*(uint *)(param_1 + 0xd8) & 0x80000) == 0) || ((**(byte **)(param_1 + 0x104) & 0x40) != 0)

       ) {

      iVar5 = FUN_0052e480(param_1);

      if (iVar5 != 0) {

        FUN_004bea70(iVar1,0x33,(undefined4 *)(iVar2 + 0xf4c),0,0xffffffff);

      }

      *(uint *)(iVar1 + 0xe0) = *(uint *)(iVar1 + 0xe0) & 0xbfffffff;

    }

    else {

      sound_play_player(0x3af,param_1);

      *(uint *)(iVar1 + 0xe0) = *(uint *)(iVar1 + 0xe0) | 0x20000000;

      iVar5 = FUN_0052e480(iVar1);

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

/* ===== FUN_004c1de0 @ 0x004C1DE0 ===== */
/* PS2 candidate: reaper_can_do_spell_anim__FP6OBJECT (conf 0.706) */



undefined4 FUN_004c1de0(int param_1)



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

  iVar1 = FUN_0052e480(param_1);

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

    iVar2 = FUN_0052e480(param_1);

    if (iVar2 != 0) {

      FUN_004bea70(param_1,0x27,param_2,0,0xffffffff);

      return;

    }

  }

  else {

    sound_play_player(0x3a4,param_1);

    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 0x1000000;

  }

  return;

}

/* ===== FUN_004c1ee0 @ 0x004C1EE0 ===== */
/* PS2 candidate: reaper_finish_smartie_grab__FP6OBJECT (conf 0.542) */



void FUN_004c1ee0(int param_1)



{

  int iVar1;

  int iVar2;

  

  iVar1 = *(int *)(param_1 + 0x100);

  *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xfff7ffff;

  iVar2 = *(int *)(iVar1 + 0xea4);

  if (iVar2 == 0) goto LAB_004c1f71;

  if (*(int *)(iVar2 + 0x274) == 0) {

    FUN_004a61a0(*(undefined4 *)(iVar2 + 0x210));

  }

  else {

    iVar2 = FUN_004a6160(*(int *)(iVar2 + 0x274));

    if (iVar2 == 0) {

      iVar2 = FUN_004a6180(*(undefined4 *)(*(int *)(iVar1 + 0xea4) + 0x274));

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

/* ===== FUN_004c1f80 @ 0x004C1F80 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* PS2 candidate: reaper_update_spell_status__FP6OBJECT (conf 0.458) */



void FUN_004c1f80(int param_1,undefined4 *param_2)



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

    iVar1 = FUN_0052e480(param_1);

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

    iVar2 = FUN_0052e480(param_1);

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

  iVar1 = FUN_0052e480(param_1);

  if (iVar1 != 0) {

    FUN_004bea70(param_1,0x26,param_2,0,0xffffffff);

  }

  *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xbfffffff;

  return;

}

/* ===== FUN_004c2140 @ 0x004C2140 ===== */
/* PS2 candidate: reaper_finish_teleport (conf 0.432) */



void FUN_004c2140(int param_1,undefined4 *param_2)



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

  FUN_004c0550(param_1,puVar1);

  *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 8;

  return;

}

/* ===== reaper_ability_playersound3 @ 0x004C2250 ===== */
void reaper_ability_playersound3(int param_1,undefined4 *param_2)



{

  int iVar1;

  int iVar2;

  

  iVar2 = *(int *)(param_1 + 0x100);

  iVar1 = FUN_0052e480(param_1);

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

    iVar2 = FUN_0052e480(param_1);

    if (iVar2 != 0) {

      FUN_004bea70(param_1,0x25,param_2,0,0xffffffff);

      return;

    }

  }

  else {

    sound_play_player(0x3a4,param_1);

    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 0x200000;

  }

  return;

}

/* ===== FUN_004c2320 @ 0x004C2320 ===== */
void FUN_004c2320(int param_1)



{

  int iVar1;

  int iVar2;

  

  iVar2 = *(int *)(param_1 + 0x100);

  iVar1 = *(int *)(iVar2 + 0xdb0) * 3 + 0x351;

  *(float *)(iVar2 + iVar1 * 4) =

       *(float *)(iVar2 + iVar1 * 4) - *(float *)(iVar2 + 0xd40 + *(int *)(iVar2 + 0xdb0) * 0xc);

  return;

}

/* ===== FUN_004c26d0 @ 0x004C26D0 ===== */
/* PS2 candidate: reaper_init_trails (conf 0.432) */



void FUN_004c26d0(int param_1,undefined4 *param_2)



{

  int iVar1;

  int iVar2;

  

  *param_2 = 0xffffffff;

  param_2 = (undefined4 *)0x0;

  if (0 < *(int *)(DAT_00632ed8 + 0x4fc)) {

    do {

      iVar1 = FUN_004a6180(param_1);

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

      FUN_004993c0(iVar1,param_1 + 0xa0);

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

      FUN_00455c80(iVar1,1,0x29d);

      iVar2 = FUN_00456050(iVar1);

      *(undefined4 *)(iVar2 + 0x184) = *(undefined4 *)(iVar1 + 0x184);

      *(uint *)(iVar2 + 0xd8) = *(uint *)(iVar2 + 0xd8) | 0x40000010;

      *(uint *)(iVar2 + 0x1c8) = *(uint *)(iVar2 + 0x1c8) | 0xe00;

      param_2 = (undefined4 *)((int)param_2 + 1);

    } while ((int)param_2 < *(int *)(DAT_00632ed8 + 0x4fc));

  }

  return;

}

/* ===== FUN_004c2850 @ 0x004C2850 ===== */
void FUN_004c2850(int param_1,int *param_2,int param_3,undefined4 param_4)



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

    fVar6 = (float10)FUN_00518b70(param_1,0);

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

    fVar6 = (float10)FUN_00518b70(param_1,0);

    *(float *)(param_3 + 0x24 + *param_2 * 0x28) = (float)(fVar6 + (float10)fVar3);

    puVar1 = DAT_00632d74;

  }

  for (; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {

    iVar4 = puVar1[3];

    if ((*(int *)(iVar4 + 0x1e0) == 0x3e) && (*(int *)(iVar4 + 0x274) == param_1)) {

      FUN_004c2ab0(param_1,iVar4,

                   (float)(*(int *)(iVar4 + 0x174) + 1) * *(float *)(DAT_00632ed8 + 0x500),param_4,

                   *param_2,param_3);

    }

  }

  return;

}

/* ===== FUN_004c2ab0 @ 0x004C2AB0 ===== */
/* PS2 candidate: reaper_set_trail__FP6OBJECTT0fiiP8TimeSnap (conf 0.443) */



void FUN_004c2ab0(undefined4 param_1,int param_2,float param_3,int param_4,int param_5,

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

  float *pfVar9;

  

  iVar5 = FUN_00456050(param_2);

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

        *(float *)(param_2 + 0xa0) = fVar3 * *pfVar7 + fVar4 * *pfVar8;

        *(float *)(param_2 + 0xa4) = fVar3 * pfVar7[1] + fVar4 * pfVar8[1];

        *(float *)(param_2 + 0xa8) = fVar3 * pfVar7[2] + fVar4 * pfVar8[2];

        if (ABS(pfVar8[3] - pfVar7[3]) <= 180.0) {

          *(float *)(param_2 + 200) = fVar4 * pfVar8[3] + fVar3 * pfVar7[3];

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

          *(float *)(param_2 + 200) = fVar1;

          if (360.0 <= fVar1) {

            *(float *)(param_2 + 200) = fVar1 - 360.0;

          }

        }

        if (pfVar7[4] != 3.5593e-43) {

          FUN_004034a0(param_2,pfVar7[4],4,0,0,0);

          if (pfVar8[4] == pfVar7[4]) {

            *(float *)(param_2 + 0x14) = fVar3 * pfVar7[5] + fVar4 * pfVar8[5];

            fVar3 = fVar3 * pfVar7[6] + fVar4 * pfVar8[6];

            *(float *)(param_2 + 0x2c) = fVar3;

            if (0.0 < fVar3) {

              pfVar8 = (float *)(param_2 + 0x10);

              pfVar9 = (float *)(param_2 + 0x58);

              for (iVar5 = 9; iVar5 != 0; iVar5 = iVar5 + -1) {

                *pfVar9 = *pfVar8;

                pfVar8 = pfVar8 + 1;

                pfVar9 = pfVar9 + 1;

              }

              *(float *)(param_2 + 0x58) = pfVar7[7];

              *(float *)(param_2 + 0x5c) = pfVar7[8];

            }

          }

          else {

            *(float *)(param_2 + 0x14) = fVar3 * pfVar7[5];

            if (pfVar7[6] <= 0.0) {

              *(undefined4 *)(param_2 + 0x2c) = 0;

            }

            else {

              pfVar8 = (float *)(param_2 + 0x10);

              pfVar9 = (float *)(param_2 + 0x58);

              for (iVar5 = 9; iVar5 != 0; iVar5 = iVar5 + -1) {

                *pfVar9 = *pfVar8;

                pfVar8 = pfVar8 + 1;

                pfVar9 = pfVar9 + 1;

              }

              *(float *)(param_2 + 0x58) = pfVar7[7];

              *(float *)(param_2 + 0x5c) = pfVar7[8];

              *(float *)(param_2 + 0x2c) = fVar3 * pfVar7[6] + fVar4;

            }

          }

        }

        *(uint *)(param_2 + 0xd8) = *(uint *)(param_2 + 0xd8) & 0xbfffffff;

        return;

      }

    }

  }

  *(uint *)(param_2 + 0xd8) = *(uint *)(param_2 + 0xd8) | 0x40000000;

  if (iVar5 != 0) {

    *(uint *)(iVar5 + 0xd8) = *(uint *)(iVar5 + 0xd8) | 0x40000000;

  }

  return;

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

    fVar9 = (float10)FUN_00518b70(param_1,0);

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

    fVar9 = (float10)FUN_00518b70(param_1,0);

    *(float *)(iVar5 + 0x90 + *(int *)(iVar5 + 0x68) * 0x28) = (float)(fVar9 + (float10)fVar6);

    puVar2 = DAT_00632d74;

  }

  for (; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {

    iVar7 = puVar2[3];

    if ((*(int *)(iVar7 + 0x1e0) == 0x3e) && (*(int *)(iVar7 + 0x274) == param_1)) {

      FUN_004c2ab0(param_1,iVar7,

                   (float)(*(int *)(iVar7 + 0x174) + 1) * *(float *)(DAT_00632ed8 + 0x500),0,

                   *(undefined4 *)(iVar5 + 0x68),iVar1);

    }

  }

LAB_004c4aab:

  if (*(int *)(iVar5 + 0xfec) != 0) {

    FUN_00495ee0(iVar5 + 0xfec);

  }

  if (*(int *)(iVar5 + 0xff0) != 0) {

    FUN_00495ee0(iVar5 + 0xff0);

  }

  if (*(int *)(iVar5 + 0xff4) != 0) {

    FUN_00495700(0x36c,param_1);

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

    fVar9 = (float10)FUN_00518b70(param_1,0);

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

    fVar9 = (float10)FUN_00518b70(param_1,0);

    *(float *)(iVar5 + 0x90 + *(int *)(iVar5 + 0x68) * 0x28) = (float)(fVar9 + (float10)fVar6);

    puVar2 = DAT_00632d74;

  }

  for (; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {

    iVar7 = puVar2[3];

    if ((*(int *)(iVar7 + 0x1e0) == 0x3e) && (*(int *)(iVar7 + 0x274) == param_1)) {

      FUN_004c2ab0(param_1,iVar7,

                   (float)(*(int *)(iVar7 + 0x174) + 1) * *(float *)(DAT_00632ed8 + 0x500),0,

                   *(undefined4 *)(iVar5 + 0x68),iVar1);

    }

  }

LAB_004c4d8b:

  if (*(int *)(iVar5 + 0xfec) != 0) {

    FUN_00495ee0(iVar5 + 0xfec);

  }

  if (*(int *)(iVar5 + 0xff0) != 0) {

    FUN_00495ee0(iVar5 + 0xff0);

  }

  if (*(int *)(iVar5 + 0xff4) != 0) {

    FUN_00495700(0x36c,param_1);

    *(undefined4 *)(iVar5 + 0xff4) = 0;

  }

  return;

}

/* ===== FUN_004c4df0 @ 0x004C4DF0 ===== */
void FUN_004c4df0(int param_1)



{

  int iVar1;

  int iVar2;

  float10 fVar3;

  float10 fVar4;

  undefined1 local_c [12];

  

  iVar2 = *(int *)(param_1 + 0x100);

  iVar1 = FUN_0052e480(param_1);

  if ((((iVar1 != 0) && (DAT_00632bb0 == 0)) &&

      ((iVar1 = FUN_0052aa70(), iVar1 == 0 || (iVar1 = FUN_005213a0(DAT_00632f18), iVar1 == 0)))) &&

     ((iVar2 = *(int *)(iVar2 + 0xcfc), iVar2 != 0 && (iVar2 = FUN_004b6e20(iVar2), iVar2 != 0)))) {

    FUN_00418630(iVar2,10,local_c);

    fVar3 = (float10)FUN_0050a610(local_c,param_1 + 0xa0);

    fVar4 = (float10)FUN_0050a610(local_c,param_1 + 0xac);

    if (((float)fVar3 < 36.0 != ((float)fVar3 == 36.0)) && ((float10)36.0 < fVar4)) {

      FUN_00416240(param_1);

      return;

    }

  }

  return;

}

/* ===== FUN_004c4ec0 @ 0x004C4EC0 ===== */
void FUN_004c4ec0(int param_1,int param_2)



{

  int iVar1;

  int iVar2;

  undefined4 *puVar3;

  int iVar4;

  int iVar5;

  undefined1 local_c [12];

  

  iVar1 = *(int *)(param_2 + 0x100);

  iVar2 = *(int *)(param_1 + 0x100);

  iVar4 = FUN_0052e480(param_2);

  if ((((iVar4 == 0) || (iVar5 = *(int *)(iVar1 + 0x10), iVar5 == 0)) ||

      (iVar5 == *(int *)(param_1 + 0x188))) || (iVar5 = FUN_0052e5b0(iVar5), iVar5 == 0)) {

    FUN_0049e4a0(param_2);

    FUN_00418630(param_2,0xb,local_c);

    FUN_004993c0(param_1,local_c);

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

            FUN_004f40a0(iVar4,param_1,*(undefined4 *)(iVar2 + 0xcfc),param_2);

            break;

          }

        }

      }

      *(undefined4 *)(iVar1 + 0x10) = *(undefined4 *)(param_1 + 0x188);

    }

  }

  return;

}

/* ===== FUN_004c4fd0 @ 0x004C4FD0 ===== */
void FUN_004c4fd0(int param_1)



{

  undefined4 uVar1;

  int iVar2;

  int iVar3;

  float10 fVar4;

  float10 fVar5;

  undefined1 local_c [12];

  

  iVar3 = *(int *)(param_1 + 0x100);

  if ((*(int *)(iVar3 + 0xcfc) != 0) && (iVar2 = FUN_0052e480(param_1), iVar2 != 0)) {

    uVar1 = *(undefined4 *)(iVar3 + 0xcfc);

    iVar3 = FUN_004b6ef0(uVar1);

    if (iVar3 != 0) {

      FUN_00418630(iVar3,0xb,local_c);

      fVar4 = (float10)FUN_0050a610(local_c,param_1 + 0xa0);

      fVar5 = (float10)FUN_0050a610(local_c,param_1 + 0xac);

      if (((float)fVar4 < 36.0 != ((float)fVar4 == 36.0)) && ((float10)36.0 < fVar5)) {

        iVar2 = FUN_0052e480(uVar1);

        if (iVar2 != 0) {

          FUN_004c4ec0(param_1,iVar3);

          return;

        }

        iVar2 = FUN_0052aa70();

        if (iVar2 != 0) {

          reaper_state_check_i(uVar1,param_1,iVar3);

          return;

        }

      }

    }

  }

  return;

}

/* ===== FUN_004c50b0 @ 0x004C50B0 ===== */
void FUN_004c50b0(int param_1,int param_2)



{

  int iVar1;

  bool bVar2;

  int iVar3;

  

  iVar1 = *(int *)(param_2 + 0x100);

  if ((DAT_00632bbc == 0) || (iVar3 = FUN_0052e480(DAT_00632bbc), iVar3 == 0)) {

    bVar2 = false;

  }

  else {

    iVar3 = *(int *)(iVar1 + 0x10);

    bVar2 = true;

    if (((iVar3 != 0) && (iVar3 != *(int *)(param_1 + 0x188))) &&

       (iVar3 = FUN_0052e5b0(iVar3), iVar3 != 0)) {

      return;

    }

  }

  FUN_00452490(param_2,0);

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

  if ((*(int *)(iVar1 + 0xcfc) != 0) && (iVar5 = FUN_0052e480(param_1), iVar5 != 0)) {

    uVar2 = *(undefined4 *)(iVar1 + 0xcfc);

    for (puVar3 = DAT_00632d9c; puVar3 != (undefined4 *)0x0; puVar3 = (undefined4 *)*puVar3) {

      iVar1 = puVar3[3];

      if (((*(int *)(iVar1 + 4) == 0x3dd) && (iVar5 = lzo_assert(iVar1), iVar5 != 0)) &&

         ((*(int *)(iVar1 + 0x18c) == 1 || (*(int *)(iVar1 + 0x18c) == *(int *)(param_1 + 0x18c)))))

      {

        FUN_00418630(iVar1,0,local_c);

        fVar7 = (float10)FUN_0050a610(local_c,param_1 + 0xa0);

        fVar8 = (float10)FUN_0050a610(local_c,param_1 + 0xac);

        if (((float)fVar7 < 36.0 != ((float)fVar7 == 36.0)) && ((float10)36.0 < fVar8)) {

          iVar5 = FUN_0052e480(uVar2);

          if (iVar5 == 0) {

            iVar5 = FUN_0052aa70();

            if (iVar5 != 0) {

              reaper_state_check_g(uVar2,param_1,iVar1);

            }

          }

          else {

            iVar5 = *(int *)(iVar1 + 0x100);

            if ((DAT_00632bbc == 0) || (iVar6 = FUN_0052e480(DAT_00632bbc), iVar6 == 0)) {

              bVar4 = false;

            }

            else {

              iVar6 = *(int *)(iVar5 + 0x10);

              bVar4 = true;

              if (((iVar6 != 0) && (iVar6 != *(int *)(param_1 + 0x188))) &&

                 (iVar6 = FUN_0052e5b0(iVar6), iVar6 != 0)) goto LAB_004c52ae;

            }

            FUN_00452490(iVar1,0);

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

  if ((((*(int *)(iVar1 + 0xcfc) != 0) && (iVar3 = FUN_0052e480(iVar2), iVar3 != 0)) &&

      (iVar1 = *(int *)(*(int *)(*(int *)(iVar1 + 0xcfc) + 0x100) + 0x580), iVar1 != 0)) &&

     (iVar3 = lzo_assert(iVar1), iVar3 != 0)) {

    FUN_00418630(iVar1,0,local_18);

    fVar6 = (float10)FUN_0050a610(local_18,iVar2 + 0xa0);

    local_28 = (float)fVar6;

    fVar6 = (float10)FUN_0050a610(local_18,iVar2 + 0xac);

    if (((local_28 < 400.0 != (local_28 == 400.0)) && ((float10)400.0 < fVar6)) &&

       (*(int *)(iVar1 + 0xe4) == 9)) {

      FUN_004186c0(iVar1,2,local_c,local_1c);

      piVar5 = DAT_00632d68;

      if (DAT_00632d68 != (int *)0x0) {

        do {

          iVar3 = piVar5[3];

          iVar4 = FUN_004a6120(iVar3);

          if (iVar4 != 0) {

            fVar6 = (float10)FUN_0050a610(iVar3 + 0xa0,local_c);

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

      FUN_004186c0(iVar1,2,&local_28,&param_1);

      iVar3 = object_allocate_type(0x434,0x80000000);

      FUN_004993c0(iVar3,&local_28);

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

  if ((((*(int *)(iVar7 + 0xcfc) != 0) && (iVar4 = FUN_0052e480(param_1), iVar4 != 0)) &&

      (iVar7 = *(int *)(*(int *)(*(int *)(iVar7 + 0xcfc) + 0x100) + 0x584), iVar7 != 0)) &&

     (iVar4 = lzo_assert(iVar7), iVar4 != 0)) {

    FUN_00418630(iVar7,0,&local_1c);

    bVar2 = false;

    while( true ) {

      fVar10 = (float10)FUN_0050a610(&local_1c,iVar3 + 0xa0);

      fVar11 = (float10)FUN_0050a610(&local_1c,iVar3 + 0xac);

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

      FUN_00418630(iVar4,0,&local_1c);

      iVar7 = iVar4;

    }

    iVar4 = FUN_004a63a0(iVar3);

    if (iVar4 != 0) {

      pcVar5 = (char *)FUN_00507b00(s_AFlagHintTeleport_0055bc47 + 1);

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

      FUN_004186c0(iVar4,1,&local_1c,&param_1);

      sound_play_player(0x6ea,iVar3);

      FUN_004993c0(iVar3,&local_1c);

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

/* ===== FUN_004c5810 @ 0x004C5810 ===== */
/* PS2 candidate: reaper_replenish_basepit_energy__FP6OBJECT (conf 0.455) */



void FUN_004c5810(float param_1)



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

    iVar5 = FUN_004188e0(iVar1);

    if (iVar5 == 0) {

      iVar5 = FUN_004188a0(iVar1);

      if (iVar1 != iVar5) {

        if (*(int *)(iVar7 + 0xcf4) != 0) {

          param_1 = *(float *)(iVar7 + 0xcf8) * 0.33333334;

          FUN_00418630(iVar5,0x14,&local_58);

          FUN_00418630(iVar5,0x55,&local_4c);

          fVar8 = (float10)1.0 - (float10)param_1;

          fVar9 = (float10)fsin((float10)DAT_006328e8 * (float10)5.0);

          FUN_00499310(*(undefined4 *)(iVar7 + 0xcf4),

                       (float)((float10)local_4c * (float10)param_1 + fVar8 * (float10)local_58),

                       (float)((float10)local_48 * (float10)param_1 + (float10)local_54 * fVar8),

                       (float)((float10)local_44 * (float10)param_1 +

                               fVar8 * (float10)local_50 + fVar9 + (float10)3.0));

          fVar8 = (float10)FUN_00518b70(fVar3,0);

          fVar8 = fVar8 + (float10)*(float *)(iVar7 + 0xcf8);

          *(float *)(iVar7 + 0xcf8) = (float)fVar8;

          if ((float10)3.0 <= fVar8) {

            FUN_00497510(*(undefined4 *)(iVar7 + 0xcf4));

            *(undefined4 *)(iVar7 + 0xcf4) = 0;

          }

        }

        iVar6 = FUN_0052e480(fVar3);

        if ((iVar6 != 0) && (*(float *)(iVar7 + 0xcec) != 0.0)) {

          fVar8 = (float10)FUN_00518b70(fVar3,0);

          fVar8 = (float10)*(float *)(iVar7 + 0xcf0) - fVar8;

          *(float *)(iVar7 + 0xcf0) = (float)fVar8;

          if (fVar8 <= (float10)0.0) {

            fVar8 = (float10)FUN_00417f20(iVar1);

            param_1 = (float)fVar8;

            fVar8 = (float10)FUN_00418170(iVar1);

            if (fVar8 < (float10)param_1 == (fVar8 == (float10)param_1)) {

              FUN_004186c0(iVar5,0x14,local_40,local_5c);

              fVar8 = (float10)FUN_0050a5e0(local_40,(int)fVar3 + 0xa0);

              if (fVar8 <= (float10)9.0) {

                sound_play_player(0x3ce,fVar3);

                *(undefined4 *)(iVar7 + 0xcf0) = *(undefined4 *)(DAT_00632ed8 + 0x620);

                fVar2 = *(float *)(iVar7 + 0xcec) - 1.0;

                *(float *)(iVar7 + 0xcec) = fVar2;

                if (fVar2 < 0.0) {

                  *(undefined4 *)(iVar7 + 0xcec) = 0;

                }

                iVar5 = FUN_0052aa70();

                if (iVar5 == 0) {

                  fVar8 = (float10)1.0;

                }

                else {

                  fVar8 = (float10)FUN_00522130(DAT_00632f40);

                }

                FUN_00417880(iVar1,(float)((float10)*(float *)(DAT_00632ed8 + 0x61c) * fVar8));

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

/* ===== FUN_004c5b10 @ 0x004C5B10 ===== */
void FUN_004c5b10(int param_1)



{

  int iVar1;

  int iVar2;

  float10 fVar3;

  float10 fVar4;

  undefined1 local_c [12];

  

  iVar2 = *(int *)(param_1 + 0x100);

  iVar1 = FUN_0052e480(param_1);

  if (((((iVar1 != 0) && (DAT_00632bb0 == 0)) && (DAT_00632ba8 == 0)) &&

      (*(int *)(iVar2 + 0xcfc) != 0)) &&

     (((*(int *)(param_1 + 0x210) == 0 ||

       (iVar1 = FUN_004a6120(*(int *)(param_1 + 0x210)), iVar1 == 0)) &&

      (iVar2 = FUN_004b6e80(*(undefined4 *)(iVar2 + 0xcfc)), iVar2 != 0)))) {

    FUN_00418630(iVar2,0xc,local_c);

    fVar3 = (float10)FUN_0050a610(local_c,param_1 + 0xa0);

    fVar4 = (float10)FUN_0050a610(local_c,param_1 + 0xac);

    if (((float)fVar3 < 36.0 != ((float)fVar3 == 36.0)) && ((float10)36.0 < fVar4)) {

      FUN_00475350(param_1);

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

  iVar4 = FUN_0052e480(param_1);

  if (iVar4 != 0) {

    fVar6 = (float10)FUN_00518b70(0,0);

    fVar6 = (float10)*(float *)(iVar1 + 0xfb0) - fVar6;

    *(float *)(iVar1 + 0xfb0) = (float)fVar6;

    puVar2 = DAT_00632d68;

    if (fVar6 < (float10)0.0) {

      for (; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {

        iVar4 = puVar2[3];

        if ((*(int *)(iVar4 + 0x1e0) == 0x66) &&

           (((*(int *)(iVar4 + 0x18c) == *(int *)(iVar3 + 0x18c) || (*(int *)(iVar4 + 0x18c) == 0))

            && (*(float *)(iVar4 + 0x278) < *(float *)(iVar4 + 0x1c0))))) {

          FUN_00418630(iVar4,0,local_c);

          fVar6 = (float10)FUN_0050a610(local_c,iVar3 + 0xa0);

          if (fVar6 < (float10)25.0 != (fVar6 == (float10)25.0)) {

            if ((*(byte *)(iVar3 + 0xe0) & 1) == 0) {

              iVar5 = reaper_0052e4a0(iVar3);

              if (iVar5 == 0) {

                iVar5 = FUN_0052e480(iVar3);

                if (iVar5 != 0) {

                  FUN_00452490(0,iVar4);

                  fVar6 = (float10)FUN_004a7630(iVar4,0);

                  *(float *)(iVar3 + 200) = (float)fVar6;

                  FUN_004a76e0(iVar3,0,(undefined4 *)(iVar3 + 0xa0));

                  FUN_00499310(iVar3,*(undefined4 *)(iVar3 + 0xa0),*(undefined4 *)(iVar3 + 0xa4),

                               *(undefined4 *)(iVar3 + 0xa8));

                  *(undefined1 *)(iVar3 + 0x20a) = 0;

                  *(undefined1 *)(iVar3 + 0x20b) = 0;

                  *(undefined1 *)(iVar3 + 0x208) = 0;

                }

              }

              else {

                param_1 = *(undefined4 *)(iVar3 + 0x188);

                FUN_00530f10(iVar4,0,1,0,1,&param_1);

                FUN_00454e00(iVar4,1,4,&param_1);

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

/* ===== FUN_004c5d80 @ 0x004C5D80 ===== */
void FUN_004c5d80(int param_1,int param_2,undefined4 param_3,int param_4)



{

  int iVar1;

  int iVar2;

  undefined1 local_c [12];

  

  iVar1 = *(int *)(param_1 + 0x100);

  iVar2 = FUN_0052e480(param_1);

  if ((iVar2 == 0) || (*(int *)(iVar1 + 0x5bc + param_4 * 4) == 0)) {

    FUN_00452490(param_3,0);

    FUN_00418630(param_3,param_4 * 2 + 0xb,local_c);

    FUN_004993c0(param_2,local_c);

    *(undefined1 *)(param_2 + 0x20a) = 0;

    *(undefined1 *)(param_2 + 0x20b) = 0;

    *(undefined1 *)(param_2 + 0x208) = 0;

    if (iVar2 != 0) {

      *(undefined4 *)(iVar1 + 0x5bc + param_4 * 4) = *(undefined4 *)(param_2 + 0x188);

    }

  }

  return;

}

/* ===== FUN_004c5e10 @ 0x004C5E10 ===== */
void FUN_004c5e10(int param_1)



{

  undefined4 uVar1;

  int iVar2;

  int iVar3;

  float10 fVar4;

  float10 fVar5;

  undefined1 local_18 [12];

  undefined1 local_c [12];

  

  iVar3 = *(int *)(param_1 + 0x100);

  if ((*(int *)(iVar3 + 0xcfc) != 0) && (iVar2 = FUN_0052e480(param_1), iVar2 != 0)) {

    uVar1 = *(undefined4 *)(iVar3 + 0xcfc);

    iVar3 = FUN_004b6de0(uVar1);

    if (iVar3 != 0) {

      FUN_00418630(iVar3,0xb,local_18);

      if (*(int *)(iVar3 + 4) == 0x2e0) {

        FUN_00418630(iVar3,0x11,local_c);

      }

      fVar4 = (float10)FUN_0050a610(local_18,param_1 + 0xa0);

      fVar5 = (float10)FUN_0050a610(local_18,param_1 + 0xac);

      if (((float)fVar4 < 36.0 == ((float)fVar4 == 36.0)) || (fVar5 <= (float10)36.0)) {

        if (*(int *)(iVar3 + 4) == 0x2e0) {

          fVar4 = (float10)FUN_0050a610(local_c,param_1 + 0xa0);

          fVar5 = (float10)FUN_0050a610(local_c,param_1 + 0xac);

          if (((float)fVar4 < 36.0 != ((float)fVar4 == 36.0)) && ((float10)36.0 < fVar5)) {

            iVar2 = FUN_0052e480(uVar1);

            if (iVar2 != 0) {

              FUN_004c5d80(uVar1,param_1,iVar3,1);

              return;

            }

            iVar3 = FUN_0052aa70();

            if (iVar3 != 0) {

              reaper_state_check_e(uVar1,param_1,1);

              return;

            }

          }

        }

      }

      else {

        iVar2 = FUN_0052e480(uVar1);

        if (iVar2 != 0) {

          FUN_004c5d80(uVar1,param_1,iVar3,0);

          return;

        }

        iVar3 = FUN_0052aa70();

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

    iVar3 = FUN_004ec1f0(param_1,(undefined4 *)(param_1 + 0xa0),0xffffffff);

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

    iVar4 = FUN_0052e480(param_1);

    if (iVar4 == 0) {

      *(undefined4 *)(iVar3 + 0x188) = param_3;

    }

    *(int *)(iVar3 + 0x210) = param_2;

    *(undefined4 *)(iVar3 + 0x218) = 0xffffffff;

    *(undefined4 *)(iVar3 + 0x214) = 0xffffffff;

    *(uint *)(iVar3 + 0xd8) = *(uint *)(iVar3 + 0xd8) | 0x400000;

    *(uint *)(param_2 + 0xdc) = *(uint *)(param_2 + 0xdc) | 0x4000000;

    if (param_2 == DAT_00632a88) {

      pcVar5 = (char *)FUN_00507b00(s_SpellHintFire_005610c8);

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

    iVar4 = FUN_004a61a0(param_2,pcVar5,uVar11,puVar13);

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

  FUN_00448c20(*puVar1);

  *puVar1 = 0;

  FUN_00497510(puVar1[1]);

  *(undefined4 *)(param_1 + 0xe0) = 1;

  *(undefined4 *)(param_1 + 0xfc) = 0x40800000;

  iVar4 = FUN_004a6180(*(undefined4 *)(param_1 + 0x274));

  if (iVar4 != 0) {

    puVar2 = *(uint **)(*(int *)(param_1 + 0x274) + 0x100);

    *puVar2 = *puVar2 | 4;

    FUN_00495ee0(puVar1 + 3);

    return;

  }

  *(uint *)(*(int *)(param_1 + 0x274) + 0xe0) = *(uint *)(*(int *)(param_1 + 0x274) + 0xe0) | 0x40;

  FUN_00495ee0(puVar1 + 3);

  return;

}

/* ===== FUN_004c6f40 @ 0x004C6F40 ===== */
void FUN_004c6f40(int param_1)



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

      FUN_00448c20(*piVar2);

      *piVar2 = 0;

      FUN_00495e10(piVar2 + 3);

      FUN_00497510(piVar2[1]);

      FUN_00497510(param_1);

    }

    *(undefined4 *)(param_1 + 0xe0) = 2;

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

    fVar9 = (float10)FUN_00518b70(param_1,0);

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

    fVar9 = (float10)FUN_00518b70(param_1,0);

    *(float *)(iVar5 + 0x90 + *(int *)(iVar5 + 0x68) * 0x28) = (float)(fVar9 + (float10)fVar6);

    puVar2 = DAT_00632d74;

  }

  for (; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {

    iVar7 = puVar2[3];

    if ((*(int *)(iVar7 + 0x1e0) == 0x3e) && (*(int *)(iVar7 + 0x274) == param_1)) {

      FUN_004c2ab0(param_1,iVar7,

                   (float)(*(int *)(iVar7 + 0x174) + 1) * *(float *)(DAT_00632ed8 + 0x500),0,

                   *(undefined4 *)(iVar5 + 0x68),iVar1);

    }

  }

LAB_004c75eb:

  *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xfffffeff;

  return;

}

/* ===== FUN_004ca560 @ 0x004CA560 ===== */
/* PS2 candidate: evilreaper_get_turbo_loc__FP6OBJECTP3P3DfffT1 (conf 0.457) */



void FUN_004ca560(int param_1,float *param_2,float param_3,undefined4 param_4,undefined4 param_5,

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

     (iVar3 = FUN_004cba90(param_1,param_6,*(undefined4 *)(DAT_00632ed8 + 0x121c)), iVar3 == 0)) {

    param_6 = (float *)0x0;

    pfVar1 = (float *)(param_1 + 0xa0);

    while( true ) {

      fVar4 = (float10)FUN_004d5780(param_4,param_5);

      fVar5 = (float10)FUN_0050a400(pfVar1,param_2);

      fVar5 = (float10)FUN_004d5780((float)(fVar5 - (float10)param_3),

                                    (float)((float10)param_3 + fVar5));

      sine_cos_lookup((float)fVar5,&local_5c,&local_58);

      *pfVar2 = local_5c * (float)fVar4 + *param_2;

      pfVar2[1] = param_2[1] - local_58 * (float)fVar4;

      fVar4 = (float10)FUN_00413e40(pfVar2);

      pfVar2[2] = (float)fVar4;

      if ((*(uint *)(param_1 + 0xe0) & 0x800) != 0) break;

      ai_fly_update_goal_4(pfVar2,local_30,&local_54);

      if (local_28 < 0.64278) {

        local_48 = *pfVar1 - *pfVar2;

        local_44 = *(float *)(param_1 + 0xa4) - pfVar2[1];

        local_40 = *(float *)(param_1 + 0xa8) - pfVar2[2];

        FUN_0050a810(&local_48,&local_44,&local_40);

        local_3c = local_48 * *(float *)(DAT_006330e4 + 0x1c0) + *pfVar2;

        local_38 = local_44 * *(float *)(DAT_006330e4 + 0x1c0) + pfVar2[1];

        fVar4 = (float10)FUN_00413e40(&local_3c);

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

        FUN_0050a810(&local_48,&local_44,&local_40);

        local_3c = local_48 * *(float *)(DAT_006330e4 + 0x1c0) + *pfVar2;

        local_38 = local_44 * *(float *)(DAT_006330e4 + 0x1c0) + pfVar2[1];

        fVar4 = (float10)FUN_00413e40(&local_3c);

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

/* ===== FUN_004ca830 @ 0x004CA830 ===== */
/* PS2 candidate: evilreaper_change_anim__FP6OBJECTii4SDKYf (conf 0.797) */



void FUN_004ca830(int param_1,int param_2,int param_3,undefined4 param_4,float param_5)



{

  int iVar1;

  undefined4 uVar2;

  

  iVar1 = *(int *)(param_1 + 0x100);

  if (*(int *)(param_1 + 0x10) != param_2) {

    uVar2 = 0x20;

    if (param_3 != 0) {

      uVar2 = 0x21;

    }

    FUN_004034a0(param_1,param_2,uVar2,param_4,param_5 * *(float *)(param_1 + 0xc4),0x3e2aaaab);

    if (param_2 != 0x89) {

      *(int *)(iVar1 + 0xb4) = param_2;

    }

  }

  return;

}

/* ===== FUN_004ca890 @ 0x004CA890 ===== */
/* PS2 candidate: evilreaper_scan_for_enemy__FP6OBJECTf (conf 0.392) */



void FUN_004ca890(float param_1,float param_2)



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

  iVar7 = FUN_004a6160(DAT_00632a88);

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

      iVar8 = FUN_004a61e0(iVar7);

      if (((((iVar8 != 0) || (*(int *)(iVar7 + 0x1e0) == 0x55)) &&

           ((*(uint *)(iVar7 + 0xd8) & 0x4000c000) == 0)) &&

          (*(float *)(iVar7 + 0x278) < *(float *)(iVar7 + 0x1c0))) &&

         ((iVar8 = FUN_004a6160(iVar7), iVar8 == 0 || ((*(uint *)(iVar7 + 0xe0) & 0x2000000) == 0)))

         ) {

        puVar1 = (undefined4 *)(iVar7 + 0xa0);

        puVar2 = (undefined4 *)(iVar6 + 0xa0);

        fVar9 = (float10)FUN_0050a610(puVar2,puVar1);

        param_1 = (float)fVar9;

        if (local_2c < 0.0) {

          local_2c = param_1 + 1.0;

        }

        iVar8 = FUN_004a61a0(iVar7);

        if (iVar8 != 0) {

          param_1 = param_1 * 0.25;

        }

        if (param_1 <= local_2c) {

          if (param_1 < 144.0) {

            bVar4 = true;

          }

          iVar8 = FUN_004a61a0(iVar7);

          if ((iVar8 != 0) && (param_1 < 10000.0)) {

            bVar4 = true;

          }

          if ((DAT_006328e8 - DAT_00632b44 < 1.0 == (DAT_006328e8 - DAT_00632b44 == 1.0)) ||

             (*(float *)(iVar3 + 0x54) == DAT_00632b44)) {

LAB_004caa99:

            if ((!bVar4) && (0.0 < param_2)) {

              fVar9 = (float10)FUN_0050a400(puVar2,puVar1);

              fVar9 = (float10)FUN_0050a770((float)fVar9,*(undefined4 *)(iVar3 + 0x4c));

              if (fVar9 <= (float10)*(float *)(DAT_00632ed8 + 0xe90)) {

                local_c = *puVar2;

                local_8 = *(undefined4 *)(iVar6 + 0xa4);

                local_4 = *(float *)(iVar6 + 0x1e8) * *(float *)(iVar6 + 0xc4) +

                          *(float *)(iVar6 + 0xa8);

                local_18 = *puVar1;

                local_14 = *(undefined4 *)(iVar7 + 0xa4);

                local_10 = *(float *)(iVar7 + 0x1e8) * *(float *)(iVar7 + 0xc4) +

                           *(float *)(iVar7 + 0xa8);

                iVar8 = FUN_004ef070(&local_c,&local_18,5,&DAT_005610e8,0);

                if (iVar8 != 0) goto LAB_004cab5d;

              }

              goto LAB_004cab6c;

            }

          }

          else {

            *(float *)(iVar3 + 0x54) = DAT_00632b44;

            fVar9 = (float10)FUN_0050a5e0(puVar2,&DAT_00632b48);

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

      fVar9 = (float10)FUN_0050a610(iVar6 + 0xa0,*(int *)(iVar3 + 0x3c) + 0xa0);

      *(float *)(iVar3 + 0x50) = (float)fVar9;

    }

  }

  return;

}

/* ===== FUN_004cabb0 @ 0x004CABB0 ===== */
/* PS2 candidate: evilreaper_verify_enemy__FP6OBJECTf (conf 0.45) */



void FUN_004cabb0(int param_1,float param_2)



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

  iVar4 = FUN_004a6160(DAT_00632a88);

  if ((iVar4 != 0) && ((*(uint *)(DAT_00632a88 + 0x20c) & 0x40000) != 0)) {

    *(undefined4 *)(iVar1 + 0x3c) = 0;

  }

  iVar4 = FUN_004a6160(*(undefined4 *)(iVar1 + 0x3c));

  if ((iVar4 != 0) && ((*(uint *)(*(int *)(iVar1 + 0x3c) + 0xe0) & 0x2000000) != 0)) {

    *(undefined4 *)(iVar1 + 0x3c) = 0;

  }

  iVar4 = FUN_004a6180(*(undefined4 *)(iVar1 + 0x3c));

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

     (iVar4 = FUN_004a61e0(iVar4), iVar4 == 0)) {

LAB_004cacea:

    *(undefined4 *)(iVar1 + 0x3c) = 0;

  }

  else {

    iVar4 = FUN_004a61a0(*(undefined4 *)(iVar1 + 0x3c));

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

  fVar7 = (float10)FUN_00518b70(param_1,0);

  fVar7 = (float10)*(float *)(param_1 + 0xec) - fVar7;

  *(float *)(param_1 + 0xec) = (float)fVar7;

  if (fVar7 < (float10)0.0) {

    iVar4 = *(int *)(iVar1 + 0x3c);

    FUN_004ca890(param_1,param_2);

    iVar2 = *(int *)(iVar1 + 0x3c);

    if ((iVar2 != 0) && (iVar2 != iVar4)) {

      fVar7 = (float10)FUN_0050a610(param_1 + 0xa0,iVar2 + 0xa0);

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

  fVar7 = (float10)FUN_00518b70(param_1,0);

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

    iVar4 = FUN_004ef070(&local_c,&local_18,5,&DAT_005610e8,0);

    if (iVar4 == 0) goto LAB_004cae37;

    uVar5 = *(uint *)(param_1 + 0xe0) & 0xfffffffe;

  }

  *(uint *)(param_1 + 0xe0) = uVar5;

LAB_004cae45:

  if ((*(byte *)(param_1 + 0xe0) & 1) == 0) {

    *(undefined4 *)(iVar1 + 0x5c) = 0;

  }

  else {

    fVar7 = (float10)FUN_00518b70(param_1,0);

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

  PhysicsExZeroForce(param_1);

  iVar1 = iVar1 + 0xdcc;

  FUN_0050a610(param_1 + 0xa0,iVar1);

  if ((*(int *)(param_1 + 0xe8) == 1) || (*(int *)(param_1 + 0xe8) == 4)) {

    fVar2 = (float10)FUN_00543e70();

    fVar2 = fVar2 * (float10)*(float *)(DAT_00632ed8 + 0x1654);

  }

  else {

    fVar2 = (float10)FUN_00543e70();

    fVar2 = fVar2 * (float10)*(float *)(DAT_00632ed8 + 0xfe0);

  }

  local_8 = 0;

  local_c = 0;

  local_4 = (*(float *)(*(int *)(param_1 + 0x104) + 4) / *(float *)(*(int *)(param_1 + 0x104) + 8))

            * -32.17405;

  FUN_004a4480(param_1 + 0x128,param_1 + 0xa0,iVar1,&local_c,(float)fVar2);

  return (float10)(float)fVar2;

}

/* ===== sound_obj_seq_big @ 0x004CAF60 ===== */
void sound_obj_seq_big(int param_1)



{

  int iVar1;

  int iVar2;

  undefined4 uVar3;

  float10 fVar4;

  

  iVar1 = *(int *)(param_1 + 0x100);

  if ((*(int *)(param_1 + 0xe8) == 3) || (*(int *)(param_1 + 0xe8) == 4)) {

    *(undefined4 *)(iVar1 + 0x74) = *(undefined4 *)(DAT_00632ed8 + 0x1628);

    *(undefined4 *)(iVar1 + 0x78) = *(undefined4 *)(DAT_00632ed8 + 0x162c);

    *(undefined4 *)(iVar1 + 0x7c) = *(undefined4 *)(DAT_00632ed8 + 0x1630);

    *(undefined4 *)(iVar1 + 0x80) = *(undefined4 *)(DAT_00632ed8 + 0x1634);

    *(undefined4 *)(iVar1 + 0x8c) = *(undefined4 *)(DAT_00632ed8 + 0x1638);

    uVar3 = *(undefined4 *)(DAT_00632ed8 + 0x163c);

  }

  else {

    *(undefined4 *)(iVar1 + 0x74) = *(undefined4 *)(DAT_00632ed8 + 0xe14);

    *(undefined4 *)(iVar1 + 0x78) = *(undefined4 *)(DAT_00632ed8 + 0xe18);

    *(undefined4 *)(iVar1 + 0x7c) = *(undefined4 *)(DAT_00632ed8 + 0xe1c);

    *(undefined4 *)(iVar1 + 0x80) = *(undefined4 *)(DAT_00632ed8 + 0xe20);

    *(undefined4 *)(iVar1 + 0x8c) = *(undefined4 *)(DAT_00632ed8 + 0xe24);

    uVar3 = *(undefined4 *)(DAT_00632ed8 + 0xe28);

  }

  *(undefined4 *)(iVar1 + 0x90) = uVar3;

  uVar3 = FUN_004d5740(*(undefined4 *)(iVar1 + 0x74),*(undefined4 *)(iVar1 + 0x78));

  *(undefined4 *)(iVar1 + 0x9c) = uVar3;

  fVar4 = (float10)FUN_004d5780(*(undefined4 *)(iVar1 + 0x7c),*(undefined4 *)(iVar1 + 0x80));

  *(float *)(iVar1 + 0xa0) = (float)fVar4;

  *(undefined4 *)(iVar1 + 0x94) = 0;

  if (((*(uint *)(*(int *)(iVar1 + 0xac) + 0xd8) & 0x40000000) != 0) &&

     ((*(byte *)(param_1 + 0xe0) & 0x10) == 0)) {

    sound_play_obj(0x334,param_1);

    iVar1 = *(int *)(param_1 + 0x100);

    if (*(int *)(param_1 + 0x10) != 0x3e) {

      FUN_004034a0(param_1,0x3e,0x20,0,*(float *)(param_1 + 0xc4) * 0.0,0x3e2aaaab);

      *(undefined4 *)(iVar1 + 0xb4) = 0x3e;

    }

    *(undefined4 *)(param_1 + 0xe4) = 0x29;

    return;

  }

  iVar1 = *(int *)(param_1 + 0x100);

  if (*(float *)(DAT_00632ed8 + 0xe30) * *(float *)(DAT_00632ed8 + 0xe30) < *(float *)(iVar1 + 0x50)

     ) {

    iVar2 = *(int *)(iVar1 + 0x3c);

    *(undefined4 *)(*(int *)(param_1 + 0x104) + 4) = *(undefined4 *)(DAT_00632ed8 + 0xfe4);

    *(undefined4 *)(*(int *)(param_1 + 0x104) + 8) = *(undefined4 *)(DAT_00632ed8 + 0xfe8);

    *(undefined4 *)(iVar1 + 0xdcc) = *(undefined4 *)(iVar2 + 0xa0);

    *(undefined4 *)(iVar1 + 0xdd0) = *(undefined4 *)(iVar2 + 0xa4);

    *(undefined4 *)(iVar1 + 0xdd4) = *(undefined4 *)(iVar2 + 0xa8);

    fVar4 = (float10)physics_reset_c(param_1);

    *(float *)(param_1 + 0xf0) = (float)(fVar4 * (float10)0.85);

    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 4;

    uVar3 = sound_get_free_sequence__Fv();

    *(undefined4 *)(iVar1 + 0xde0) = uVar3;

    iVar1 = *(int *)(param_1 + 0x100);

    if (*(int *)(param_1 + 0x10) != 0x5a) {

      FUN_004034a0(param_1,0x5a,0x21,0,*(float *)(param_1 + 0xc4) * 0.0,0x3e2aaaab);

      *(undefined4 *)(iVar1 + 0xb4) = 0x5a;

    }

    *(undefined4 *)(param_1 + 0xe4) = 0x46;

    return;

  }

  if (*(int *)(param_1 + 0x10) != 2) {

    FUN_004034a0(param_1,2,0x21,1,*(float *)(param_1 + 0xc4) * 30.0,0x3e2aaaab);

    *(undefined4 *)(iVar1 + 0xb4) = 2;

  }

  *(undefined4 *)(param_1 + 0xe4) = 0x47;

  return;

}

/* ===== sound_obj_seq_bigger @ 0x004CB220 ===== */
void sound_obj_seq_bigger(int param_1)



{

  int iVar1;

  undefined4 uVar2;

  int iVar3;

  float10 fVar4;

  undefined4 local_c;

  undefined4 local_8;

  undefined4 local_4;

  

  iVar3 = *(int *)(param_1 + 0x100);

  if ((*(int *)(param_1 + 0xe8) == 3) || (*(int *)(param_1 + 0xe8) == 4)) {

    *(undefined4 *)(iVar3 + 0x6c) = *(undefined4 *)(DAT_00632ed8 + 0x1600);

    *(undefined4 *)(iVar3 + 0x70) = *(undefined4 *)(DAT_00632ed8 + 0x1604);

    *(undefined4 *)(iVar3 + 0x74) = *(undefined4 *)(DAT_00632ed8 + 0x1608);

    *(undefined4 *)(iVar3 + 0x78) = *(undefined4 *)(DAT_00632ed8 + 0x160c);

    *(undefined4 *)(iVar3 + 0x7c) = *(undefined4 *)(DAT_00632ed8 + 0x1610);

    *(undefined4 *)(iVar3 + 0x80) = *(undefined4 *)(DAT_00632ed8 + 0x1614);

    *(undefined4 *)(iVar3 + 0x84) = *(undefined4 *)(DAT_00632ed8 + 0x1658);

    *(undefined4 *)(iVar3 + 0x88) = *(undefined4 *)(DAT_00632ed8 + 0x165c);

    *(undefined4 *)(iVar3 + 0x8c) = *(undefined4 *)(DAT_00632ed8 + 0x1620);

    uVar2 = *(undefined4 *)(DAT_00632ed8 + 0x1624);

  }

  else {

    *(undefined4 *)(iVar3 + 0x6c) = *(undefined4 *)(DAT_00632ed8 + 0xe4c);

    *(undefined4 *)(iVar3 + 0x70) = *(undefined4 *)(DAT_00632ed8 + 0xe50);

    *(undefined4 *)(iVar3 + 0x74) = *(undefined4 *)(DAT_00632ed8 + 0xe44);

    *(undefined4 *)(iVar3 + 0x78) = *(undefined4 *)(DAT_00632ed8 + 0xe48);

    *(undefined4 *)(iVar3 + 0x7c) = *(undefined4 *)(DAT_00632ed8 + 0xe54);

    *(undefined4 *)(iVar3 + 0x80) = *(undefined4 *)(DAT_00632ed8 + 0xed4);

    *(undefined4 *)(iVar3 + 0x84) = *(undefined4 *)(DAT_00632ed8 + 0xed0);

    *(undefined4 *)(iVar3 + 0x88) = *(undefined4 *)(DAT_00632ed8 + 0xecc);

    *(undefined4 *)(iVar3 + 0x8c) = *(undefined4 *)(DAT_00632ed8 + 0xec8);

    uVar2 = *(undefined4 *)(DAT_00632ed8 + 0xec4);

  }

  *(undefined4 *)(iVar3 + 0x90) = uVar2;

  uVar2 = FUN_004d5740(*(undefined4 *)(iVar3 + 0x6c),*(undefined4 *)(iVar3 + 0x70));

  *(undefined4 *)(iVar3 + 0x98) = uVar2;

  uVar2 = FUN_004d5740(*(undefined4 *)(iVar3 + 0x74),*(undefined4 *)(iVar3 + 0x78));

  *(undefined4 *)(iVar3 + 0x9c) = uVar2;

  if ((*(uint *)(*(int *)(iVar3 + 0xa8) + 0xd8) & 0x40000000) == 0) {

    iVar3 = crt_rand_scaled(100);

    if (((iVar3 < *(int *)(DAT_00632ed8 + 0x1368)) && (*(int *)(param_1 + 0xe8) != 1)) &&

       (*(int *)(param_1 + 0xe8) != 4)) {

      iVar3 = *(int *)(param_1 + 0x100);

      FUN_004ca560(param_1,*(int *)(iVar3 + 0x3c) + 0xa0,0x41a00000,

                   *(undefined4 *)(DAT_00632ed8 + 0xe7c),*(undefined4 *)(DAT_00632ed8 + 0xe80),

                   &local_c);

      collgrid_collide_d(param_1,param_1 + 0xa0,&local_c);

      fVar4 = (float10)FUN_0050a400(param_1 + 0xa0,&local_c);

      *(float *)(param_1 + 200) = (float)fVar4;

      iVar1 = *(int *)(param_1 + 0x100);

      *(undefined4 *)(*(int *)(param_1 + 0x104) + 4) = *(undefined4 *)(DAT_00632ed8 + 0xfe4);

      *(undefined4 *)(*(int *)(param_1 + 0x104) + 8) = *(undefined4 *)(DAT_00632ed8 + 0xfe8);

      *(undefined4 *)(iVar1 + 0xdcc) = local_c;

      *(undefined4 *)(iVar1 + 0xdd0) = local_8;

      *(undefined4 *)(iVar1 + 0xdd4) = local_4;

      fVar4 = (float10)physics_reset_c(param_1);

      *(float *)(param_1 + 0xf0) = (float)(fVar4 * (float10)0.85);

      *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 4;

      uVar2 = sound_get_free_sequence__Fv();

      *(undefined4 *)(iVar1 + 0xde0) = uVar2;

      FUN_004ca830(param_1,0x5a,1,0,0);

      sound_play_obj(0x38f,param_1);

      iVar1 = *(int *)(param_1 + 0x100);

      if (*(int *)(param_1 + 0x10) != 0x81) {

        FUN_004034a0(param_1,0x81,0x21,0,*(float *)(param_1 + 0xc4) * 0.0,0x3e2aaaab);

        *(undefined4 *)(iVar1 + 0xb4) = 0x81;

      }

      fVar4 = (float10)FUN_004d5780(*(undefined4 *)(iVar3 + 0x7c),*(undefined4 *)(iVar3 + 0x80));

      *(float *)(iVar3 + 0xa0) = (float)fVar4;

      *(undefined4 *)(param_1 + 0xe4) = 0x14;

      return;

    }

    sound_play_obj(0x38f,param_1);

    iVar3 = *(int *)(param_1 + 0x100);

    if (*(int *)(param_1 + 0x10) != 0x7b) {

      FUN_004034a0(param_1,0x7b,0x20,0,*(float *)(param_1 + 0xc4) * 0.0,0x3e2aaaab);

      *(undefined4 *)(iVar3 + 0xb4) = 0x7b;

    }

    *(undefined4 *)(param_1 + 0xe4) = 0x32;

    return;

  }

  sound_play_obj(0x3c7,param_1);

  iVar3 = *(int *)(param_1 + 0x100);

  if (*(int *)(param_1 + 0x10) != 0x3d) {

    FUN_004034a0(param_1,0x3d,0x20,0,*(float *)(param_1 + 0xc4) * 0.0,0x3e2aaaab);

    *(undefined4 *)(iVar3 + 0xb4) = 0x3d;

  }

  *(undefined4 *)(param_1 + 0xe4) = 0x28;

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

  

  FUN_004a76e0(param_1,0,&local_50);

  fVar2 = (float10)FUN_0050a490(&local_50,param_3);

  fVar3 = (float10)FUN_0050a400(&local_50,param_3);

  local_44[0] = 0;

  FUN_0053e460(local_44,-(float)fVar2,0,(float)fVar3);

  local_24 = local_4c;

  local_44[0] = local_44[0] | 0x10;

  local_34 = local_50;

  local_14 = local_48;

  iVar1 = FUN_004aa550(param_2,*(undefined4 *)(param_1 + 0x18c),param_1,0,local_44,param_4);

  *(int *)(iVar1 + 0x274) = param_1;

  switch(param_2) {

  case 0x20:

  case 0x21:

  case 0x23:

    sound_play_obj(0x3ad,param_1);

    break;

  case 0x22:

    sound_play_obj(0x3a3,param_1);

    return;

  }

  return;

}

/* ===== FUN_004cb730 @ 0x004CB730 ===== */
/* PS2 candidate: evilreaper_fire_bow__FP6OBJECT (conf 0.533) */



void FUN_004cb730(int param_1)



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

  FUN_004a76e0(*(undefined4 *)(iVar1 + 0xa8),0,&local_50);

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

  fVar3 = (float10)FUN_0050a490(&local_50,&local_5c);

  fVar4 = (float10)FUN_0050a400(&local_50,&local_5c);

  local_44[0] = 0;

  FUN_0053e460(local_44,-(float)fVar3,0,(float)fVar4);

  local_24 = local_4c;

  local_34 = local_50;

  local_44[0] = local_44[0] | 0x10;

  local_14 = local_48;

  iVar2 = FUN_004aa550(0x16,*(undefined4 *)(param_1 + 0x18c),param_1,0,local_44,0);

  *(int *)(iVar2 + 0x274) = param_1;

  *(int *)(iVar1 + 0x9c) = *(int *)(iVar1 + 0x9c) + -1;

  sound_play_obj(0x38d,param_1);

  return;

}

/* ===== FUN_004cb860 @ 0x004CB860 ===== */
/* PS2 candidate: evilreaper_select_firewall_loc__FP6OBJECT (conf 0.435) */



void FUN_004cb860(int param_1)



{

  int iVar1;

  int iVar2;

  float10 fVar3;

  float10 fVar4;

  float local_8;

  float local_4;

  

  iVar1 = *(int *)(param_1 + 0x100);

  fVar3 = (float10)FUN_004d5780(*(undefined4 *)(DAT_00632ed8 + 0xef0),

                                *(undefined4 *)(DAT_00632ed8 + 0xef4));

  fVar4 = (float10)FUN_0050a400(*(int *)(iVar1 + 0x3c) + 0xa0,param_1 + 0xa0);

  fVar4 = (float10)FUN_004d5780((float)(fVar4 - (float10)*(float *)(DAT_00632ed8 + 0xef8)),

                                (float)((float10)*(float *)(DAT_00632ed8 + 0xef8) + fVar4));

  sine_cos_lookup((float)fVar4,&local_8,&local_4);

  iVar2 = *(int *)(iVar1 + 0x3c);

  *(float *)(iVar1 + 0xdb4) = local_8 * (float)fVar3 + *(float *)(iVar2 + 0xa0);

  *(float *)(iVar1 + 0xdb8) = *(float *)(iVar2 + 0xa4) - local_4 * (float)fVar3;

  *(undefined4 *)(iVar1 + 0xdbc) = *(undefined4 *)(iVar2 + 0xa8);

  return;

}

/* ===== FUN_004cb960 @ 0x004CB960 ===== */
/* PS2 candidate: evilreaper_set_new_location__FP6OBJECTi (conf 0.467) */



void FUN_004cb960(int param_1,int param_2)



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

    fVar4 = (float10)FUN_004d5780(uVar1,uVar6);

    *(int *)(iVar2 + 0xb0) = iVar3;

    fVar5 = (float10)FUN_0050a400(*(int *)(iVar2 + 0x3c) + 0xa0,param_1 + 0xa0);

    fVar5 = (float10)FUN_004d5780((float)(fVar5 - (float10)20.0),(float)((float10)20.0 + fVar5));

    sine_cos_lookup((float)fVar5,&local_14,&local_10);

    local_c = local_14 * (float)fVar4 + *(float *)(*(int *)(iVar2 + 0x3c) + 0xa0);

    local_8 = *(float *)(*(int *)(iVar2 + 0x3c) + 0xa4) - local_10 * (float)fVar4;

    local_4 = *(undefined4 *)(*(int *)(iVar2 + 0x3c) + 0xa8);

    collgrid_collide_d(param_1,param_1 + 0xa0,&local_c);

    *(undefined1 **)(param_1 + 0x16c) = &LAB_004cb930;

    FUN_00401610(param_1,&local_c);

  }

  return;

}

/* ===== FUN_004cba90 @ 0x004CBA90 ===== */
/* PS2 candidate: evilreaper_find_turbo_marker__FP6OBJECTP3P3Di (conf 0.452) */



undefined4 FUN_004cba90(int param_1,undefined4 *param_2,float param_3)



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

         (((fVar7 = (float10)FUN_0050a5e0(iVar3 + 0xa0,param_1 + 0xa0), iVar5 == 0 ||

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
void physics_reset_a(int param_1)



{

  int iVar1;

  int iVar2;

  undefined4 uVar3;

  int iVar4;

  float10 fVar5;

  undefined4 uVar6;

  undefined4 local_18;

  undefined4 local_14;

  undefined4 local_10;

  undefined4 local_c;

  undefined4 local_8;

  float local_4;

  

  iVar1 = *(int *)(param_1 + 0x100);

  if ((*(int *)(param_1 + 0xe8) != 1) && (*(int *)(param_1 + 0xe8) != 4)) {

    iVar2 = crt_rand_scaled(100);

    if (iVar2 < *(int *)(DAT_00632ed8 + 0xe78)) {

      uVar3 = *(undefined4 *)(DAT_00632ed8 + 0xe80);

      uVar6 = *(undefined4 *)(DAT_00632ed8 + 0xe7c);

      iVar1 = *(int *)(iVar1 + 0x3c);

    }

    else {

      uVar3 = *(undefined4 *)(DAT_00632ed8 + 0xe88);

      iVar1 = *(int *)(iVar1 + 0x3c);

      uVar6 = *(undefined4 *)(DAT_00632ed8 + 0xe84);

    }

    FUN_004ca560(param_1,iVar1 + 0xa0,0x41a00000,uVar6,uVar3,&local_18);

    iVar1 = param_1 + 0xa0;

    collgrid_collide_d(param_1,iVar1,&local_18);

    fVar5 = (float10)FUN_0050a400(iVar1,&local_18);

    *(float *)(param_1 + 200) = (float)fVar5;

    iVar2 = *(int *)(param_1 + 0x100);

    *(undefined4 *)(*(int *)(param_1 + 0x104) + 4) = *(undefined4 *)(DAT_00632ed8 + 0xfe4);

    *(undefined4 *)(*(int *)(param_1 + 0x104) + 8) = *(undefined4 *)(DAT_00632ed8 + 0xfe8);

    *(undefined4 *)(iVar2 + 0xdcc) = local_18;

    *(undefined4 *)(iVar2 + 0xdd0) = local_14;

    *(undefined4 *)(iVar2 + 0xdd4) = local_10;

    iVar4 = *(int *)(param_1 + 0x100);

    PhysicsExZeroForce(param_1);

    iVar4 = iVar4 + 0xdcc;

    FUN_0050a610(iVar1,iVar4);

    if ((*(int *)(param_1 + 0xe8) == 1) || (*(int *)(param_1 + 0xe8) == 4)) {

      fVar5 = (float10)FUN_00543e70();

      fVar5 = fVar5 * (float10)*(float *)(DAT_00632ed8 + 0x1654);

    }

    else {

      fVar5 = (float10)FUN_00543e70();

      fVar5 = fVar5 * (float10)*(float *)(DAT_00632ed8 + 0xfe0);

    }

    local_8 = 0;

    local_c = 0;

    local_4 = (*(float *)(*(int *)(param_1 + 0x104) + 4) / *(float *)(*(int *)(param_1 + 0x104) + 8)

              ) * -32.17405;

    FUN_004a4480(param_1 + 0x128,iVar1,iVar4,&local_c,(float)fVar5);

    *(float *)(param_1 + 0xf0) = (float)fVar5 * 0.85;

    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 4;

    uVar3 = sound_get_free_sequence__Fv();

    *(undefined4 *)(iVar2 + 0xde0) = uVar3;

    iVar1 = *(int *)(param_1 + 0x100);

    if (*(int *)(param_1 + 0x10) != 0x5a) {

      FUN_004034a0(param_1,0x5a,0x21,0,*(float *)(param_1 + 0xc4) * 0.0,0x3e2aaaab);

      *(undefined4 *)(iVar1 + 0xb4) = 0x5a;

    }

    *(undefined4 *)(param_1 + 0xe4) = 0x12;

    return;

  }

  *(undefined4 *)(param_1 + 0xe4) = 0xc;

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

      FUN_00495ee0(iVar1 + 0xde0);

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

      PhysicsExZeroForce(param_1);

      FUN_0050a610(param_1 + 0xa0,iVar1 + 0xdcc);

      if ((*(int *)(param_1 + 0xe8) == 1) || (*(int *)(param_1 + 0xe8) == 4)) {

        fVar3 = (float10)FUN_00543e70();

        fVar3 = fVar3 * (float10)*(float *)(DAT_00632ed8 + 0x1654);

      }

      else {

        fVar3 = (float10)FUN_00543e70();

        fVar3 = fVar3 * (float10)*(float *)(DAT_00632ed8 + 0xfe0);

      }

      local_8 = 0;

      local_c = 0;

      local_4 = (*(float *)(*(int *)(param_1 + 0x104) + 4) /

                *(float *)(*(int *)(param_1 + 0x104) + 8)) * -32.17405;

      FUN_004a4480(param_1 + 0x128,param_1 + 0xa0,iVar1 + 0xdcc,&local_c,(float)fVar3);

      fVar3 = (float10)FUN_00518b70(param_1,0);

      *(float *)(param_1 + 0xf0) = (float)((float10)*(float *)(param_1 + 0xf0) - fVar3);

    }

  }

  else {

    FUN_00402270(param_1);

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

/* ===== FUN_004cc7a0 @ 0x004CC7A0 ===== */
void FUN_004cc7a0(int param_1)



{

  if ((*(byte *)(param_1 + 0xe0) & 4) != 0) {

    FUN_004c2850(param_1,*(int *)(param_1 + 0x100) + 0xb8,*(int *)(param_1 + 0x100) + 0xbc,0);

    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xfffffffb;

  }

  return;

}

/* ===== ai_island_init @ 0x004CC7E0 ===== */
void ai_island_init(void)



{

  FUN_004a13c0(s_AIsland_005611c7 + 1);

  if (0 < DAT_00633244) {

    main_drawwatr_00430fd0();

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

  

  FUN_004a13c0(s_InDome_005611d0);

  (**(code **)(DAT_00656420 + 0x18))(DAT_00656420,&DAT_00561138);

  (**(code **)(DAT_00656430 + 0xc))(DAT_00656430,1);

  (**(code **)(DAT_00656430 + 0x10))(DAT_00656430,1);

  FUN_00515eb0(&pcStack_8,&puStack_4);

  FNT_StringRender__FPcP14FNT_RenderInfo(pcStack_8,(undefined4 *)0x46dac000);

  fVar1 = (float10)FUN_00515da0(0);

  fVar1 = (float10)FUN_00515d90((float)fVar1);

  FUN_005160b0((float)fVar1);

  FUN_0042a4f0();

  FNT_StringRender__FPcP14FNT_RenderInfo(pcStack_8,puStack_4);

  fVar1 = (float10)FUN_00515da0(1);

  fVar1 = (float10)FUN_00515d90((float)fVar1);

  FUN_005160b0((float)fVar1);

  if (DAT_00633244 < 1) {

    main_drawwatr_00430fd0();

    return;

  }

  return;

}

/* ===== FUN_004cc8d0 @ 0x004CC8D0 ===== */
/* PS2 candidate: controlShutdown__Fv (conf 0.695) */



void FUN_004cc8d0(void)



{

  int *piVar1;

  

  piVar1 = &DAT_005a6c8c;

  do {

    if (*piVar1 != 0) {

      FUN_00499cd0(piVar1 + -1);

    }

    *piVar1 = 0;

    piVar1 = piVar1 + 0xc1;

  } while ((int)piVar1 < 0x5a84ac);

  return;

}

/* ===== FUN_004cc900 @ 0x004CC900 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* PS2 candidate: ShopMenuSlotCollision__Fi (conf 0.41) */



void FUN_004cc900(void)



{

  float fVar1;

  int iVar2;

  int iVar3;

  undefined4 uVar4;

  int iVar5;

  int iVar6;

  int *piVar7;

  undefined *puVar8;

  float *pfVar9;

  int *piVar10;

  int *piVar11;

  float *pfVar12;

  float10 fVar13;

  undefined4 *puVar14;

  int *piStack_244;

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

  undefined4 local_1bc;

  float afStack_1b8 [16];

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

    FUN_0053dde0(&local_1bc,&local_20c,local_1fc,&local_178);

    (*(code *)PTR_FUN_00580c1c)(&local_1bc,&local_1bc);

    FUN_0053d970(&DAT_005a6c40,&local_1bc);

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

  iVar6 = FUN_004a6160(DAT_00632a88);

  if (iVar6 == 0) {

    iVar6 = FUN_004a6180(DAT_00632a88);

    if (iVar6 == 0) {

      iVar6 = FUN_004a61a0(DAT_00632a88);

      if (iVar6 != 0) {

        fVar13 = (float10)FUN_0045eca0(DAT_00632a88);

        if (fVar13 <= (float10)0.0) {

          return;

        }

        uVar4 = __ftol(&local_20c,10);

        FUN_00544a37(uVar4);

        FUN_00446a90(&local_1bc);

        afStack_1b8[1] = afStack_1b8[1] * 0.25;

        afStack_1b8[3] = 0.9;

        afStack_1b8[2] = afStack_1b8[2] * 0.25;

        afStack_1b8[4] = 0.1;

        FNT_RenderInfoProcess__FP14FNT_RenderInfof(&local_1bc,DAT_006328e0);

        puVar14 = &local_1bc;

        pfVar9 = &local_20c;

        uVar4 = AudioGetMasterVolume__Fv_3();

        FUN_00446ce0(uVar4,pfVar9,puVar14);

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

    iVar6 = FUN_004a6120(*(undefined4 *)(DAT_00632a88 + 0x210));

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

    piStack_244 = aiStack_14c + 1;

    iStack_240 = 1;

    aiStack_16c[0] = 0x29d;

    local_12c[0] = 0x4a;

    local_1bc = 0x3f800000;

    aiStack_14c[0] = -1;

    piVar7 = aiStack_16c + 1;

    pfVar9 = afStack_1b8;

    piVar10 = local_12c + 1;

    iVar5 = 0;

    do {

      iVar2 = FUN_004a8fb0(*(undefined4 *)(iVar6 + 0xd78 + iVar5 * 8),1);

      *piVar7 = iVar2;

      *piVar10 = *(int *)(iVar6 + 0xd78 + iVar5 * 8);

      *pfVar9 = 1.0;

      if (iVar5 == 0) {

        *piStack_244 = -1;

      }

      else {

        *piStack_244 = *(int *)(iVar6 + 0xd7c + iVar5 * 8);

      }

      piStack_244 = piStack_244 + 1;

      piVar7 = piVar7 + 1;

      pfVar9 = pfVar9 + 1;

      piVar10 = piVar10 + 1;

      iStack_240 = iStack_240 + 1;

      iVar5 = iVar5 + 1;

    } while (iVar5 < 4);

    piVar11 = (int *)(iVar6 + 0xd98);

    fStack_238 = 2.8026e-45;

    do {

      if (*piVar11 != -1) {

        iVar2 = FUN_004a8fe0(*piVar11);

        iVar6 = piVar11[1];

        iVar5 = *piVar11;

        *piVar7 = iVar2;

        *piStack_244 = iVar6;

        piStack_244 = piStack_244 + 1;

        *piVar10 = iVar5;

        *pfVar9 = 0.8;

        piVar7 = piVar7 + 1;

        pfVar9 = pfVar9 + 1;

        piVar10 = piVar10 + 1;

        iStack_240 = iStack_240 + 1;

      }

      piVar11 = piVar11 + 2;

      fStack_238 = (float)((int)fStack_238 + -1);

    } while (fStack_238 != 0.0);

  }

  else {

    piStack_244 = &local_1bc;

    piVar7 = aiStack_16c;

    piVar10 = aiStack_14c;

    piVar11 = local_12c;

    local_234 = &DAT_00577544;

    local_22c = &DAT_00577564;

    iStack_23c = 0;

    do {

      iVar6 = FUN_00457fb0(DAT_00632a88,iStack_23c);

      if (iVar6 < 0x4b) {

        *piStack_244 = 0x3f800000;

        *piVar11 = iVar6;

        iVar5 = FUN_004a8fe0(iVar6);

        *piVar7 = iVar5;

        if (iStack_23c == 0) {

          iVar6 = FUN_0047f730(DAT_00632a88);

          if ((iVar6 == 0) || (iVar6 = FUN_00482310(DAT_00632a88), iVar6 == 0)) {

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

          iVar6 = FUN_0045a2b0(DAT_00632a88,iVar6,0);

          *piVar10 = iVar6;

        }

        piStack_244 = piStack_244 + 1;

        piVar7 = piVar7 + 1;

        piVar11 = piVar11 + 1;

        piVar10 = piVar10 + 1;

        iStack_240 = iStack_240 + 1;

      }

      else {

        FUN_0051ea20(s_Error__Bad_gun_index_005611d8);

      }

      iStack_23c = iStack_23c + 1;

    } while (iStack_23c < 4);

    iStack_23c = 0;

    do {

      iVar6 = FUN_004582d0(DAT_00632a88,iStack_23c);

      if (iVar6 < 0x4b) {

        *piStack_244 = 0x3f4ccccd;

        *piVar11 = iVar6;

        iVar5 = FUN_004a8fe0(iVar6);

        *piVar7 = iVar5;

        iVar6 = FUN_0045a2b0(DAT_00632a88,iVar6,0);

        *piVar10 = iVar6;

        piStack_244 = piStack_244 + 1;

        piVar7 = piVar7 + 1;

        piVar11 = piVar11 + 1;

        piVar10 = piVar10 + 1;

        iStack_240 = iStack_240 + 1;

      }

      else {

        FUN_0051ea20(s_Error__Bad_gun_index_005611d8);

      }

      iStack_23c = iStack_23c + 1;

    } while (iStack_23c < 3);

    iVar6 = FUN_0047f730(DAT_00632a88);

    if ((iVar6 != 0) && (iVar6 = FUN_00482310(DAT_00632a88), iVar6 != 0)) {

      *piVar10 = *(int *)(iVar6 + 0xf4);

      iStack_240 = iStack_240 + 1;

      *piVar7 = 0x328;

    }

  }

  if (iStack_240 == 0) {

    return;

  }

LAB_004ccbc0:

  fVar13 = (float10)FUN_00515d90();

  fStack_228 = (float)fVar13;

  fVar13 = (float10)FUN_00515da0();

  fStack_224 = (float)fVar13;

  FUN_00516260(&fStack_1e4);

  FUN_005163e0(auStack_10c);

  FUN_00515eb0(&pcStack_1c0,&puStack_1c8);

  FNT_StringRender__FPcP14FNT_RenderInfo((char *)0x40400000,(undefined4 *)0x4b989680);

  iStack_23c = 0;

  if (0 < iStack_240) {

    iStack_1c4 = (int)afStack_1b8 + (-4 - (int)local_234);

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

          piStack_244 = (int *)(fStack_1e4 * _DAT_005611b8);

          fStack_238 = fStack_1e0 * _DAT_005611b8;

          if (iVar6 < 0) {

            fStack_220 = (fStack_1e0 * (float)(&DAT_0056117c)[iStack_23c * 2] +

                         fStack_1e0 * (float)(&DAT_0056117c)[iStack_23c * 2]) - fStack_238 * 0.5;

            fStack_210 = (fStack_1e4 * (float)(&DAT_00561178)[iStack_23c * 2] +

                         fStack_1e4 * (float)(&DAT_00561178)[iStack_23c * 2]) -

                         (float)piStack_244 * 0.5;

            FUN_005161c0(fStack_210,fStack_220,piStack_244,fStack_238);

            (**(code **)(DAT_00656420 + 0xa4))

                      (DAT_00656420,fStack_210,fStack_220,piStack_244,fStack_238);

          }

        }

        else {

          iVar2 = *piVar7 * 0x58;

          uStack_21c = *(undefined4 *)(&DAT_00562544 + iVar2);

          piStack_244 = (int *)(*(float *)(&DAT_00562550 + iVar2) -

                               *(float *)(&DAT_00562544 + iVar2));

          uStack_218 = *(undefined4 *)(&DAT_00562548 + iVar2);

          fStack_238 = *(float *)(&DAT_00562554 + iVar2) - *(float *)(&DAT_00562548 + iVar2);

          if (iVar6 < 0) {

            FUN_005161c0(uStack_21c,uStack_218,piStack_244,fStack_238);

            (**(code **)(DAT_00656420 + 0xa4))

                      (DAT_00656420,uStack_21c,uStack_218,piStack_244,fStack_238);

          }

          if ((((DAT_00633104 != 0) && (iVar2 = FUN_004a6160(DAT_00632a88), iVar2 != 0)) &&

              (iVar2 = FUN_00420260(), iVar2 == iVar6)) && (iVar2 = FUN_00420260(), -1 < iVar2)) {

            iVar3 = *piVar7 * 0x58;

            iVar2 = *(int *)(*(int *)(DAT_00632918 + 0x510) + 8);

            FUN_004fa490(&DAT_00632900,0x24,2,0,0x3f800000,0x3f800000,

                         ((*(float *)(&DAT_00562550 + iVar3) + *(float *)(&DAT_00562544 + iVar3)) *

                          0.5 - (*(float *)(iVar2 + 0x40) - *(float *)(iVar2 + 0x34)) * 0.5) /

                         (float)DAT_00632924,

                         ((*(float *)(&DAT_00562554 + iVar3) + *(float *)(&DAT_00562548 + iVar3)) *

                          0.5 - (*(float *)(iVar2 + 0x44) - *(float *)(iVar2 + 0x38)) * 0.5) /

                         (float)DAT_00632928);

            FUN_004fa720(&DAT_00632900,0x24,2);

          }

        }

        if (iVar6 < 0) {

          FUN_005162b0(&DAT_005a6c44);

          FUN_005160b0(0x42700000,(float)piStack_244 / fStack_238,0);

          xfmat_mult_a();

          if (*(int *)(puVar8 + -0x290) == 0) {

            objobj_type_lookup(iVar5,puVar8 + -0x294);

          }

          else if (*(int *)(puVar8 + -0x290) != iVar5) {

            FUN_00499cd0(puVar8 + -0x294);

            objobj_type_lookup(iVar5,puVar8 + -0x294);

          }

          pfVar9 = (float *)(*(int *)(*(int *)(puVar8 + -0x28c) + 0x400) + 0x44);

          pfVar12 = local_1fc;

          for (iVar6 = 6; iVar6 != 0; iVar6 = iVar6 + -1) {

            *pfVar12 = *pfVar9;

            pfVar9 = pfVar9 + 1;

            pfVar12 = pfVar12 + 1;

          }

          local_20c = (local_1fc[3] + local_1fc[0]) * -0.5;

          local_208 = (fStack_1ec + local_1fc[1]) * -0.5;

          local_204 = (fStack_1e8 + local_1fc[2]) * -0.5;

          FUN_0053dc50(auStack_88,

                       5.0 / SQRT((fStack_1e8 - local_1fc[2]) * (fStack_1e8 - local_1fc[2]) +

                                  (fStack_1ec - local_1fc[1]) * (fStack_1ec - local_1fc[1]) +

                                  (local_1fc[3] - local_1fc[0]) * (local_1fc[3] - local_1fc[0])));

          FUN_0053dc10(auStack_cc,&local_20c);

          FUN_0053dd90(auStack_44,DAT_005a84e0);

          (*(code *)PTR_FUN_00580c18)(puVar8,auStack_cc,auStack_88);

          (*(code *)PTR_FUN_00580c18)(puVar8,auStack_44,puVar8);

          *(uint *)(puVar8 + -0x1bc) = *(uint *)(puVar8 + -0x1bc) | 0x20;

          uVar4 = BinFileSeek(puVar8 + -0x294,0x461c4000);

          AudioSetSpeakerConfig__F14SPEAKER_SYSTEM_3(uVar4);

          status_hud_render(puVar8 + -0x294,0xffff,0xffffffff);

          Audio3DTestToneUpdate__Fv_3();

          iVar6 = iStack_214;

        }

        else {

          FUN_00516220(&fStack_1e4);

          uVar4 = AudioDataStreamStatus__Fv_3();

          mission_004fe2d0(uVar4,&PTR_DAT_00562510 + *piVar7 * 0x16,0x3e19999a,0x3e4ccccd,

                           &uStack_1d4,&uStack_1cc);

          fVar1 = *(float *)(iStack_1c4 + (int)piVar7) * 0.7;

          FUN_004fe0f0(uVar4,iVar6,fVar1,fVar1,uStack_1d4,uStack_1cc,0);

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

  FUN_00516220(&fStack_1e4);

  FUN_005162b0(auStack_10c);

  FNT_StringRender__FPcP14FNT_RenderInfo(pcStack_1c0,puStack_1c8);

  FUN_005160b0(fStack_228,fStack_224,1);

  xfmat_mult_a();

  if (iStack_240 < 1) {

    return;

  }

  iVar6 = 0;

  do {

    if (aiStack_16c[iVar6] != 0) {

      iVar5 = aiStack_14c[iVar6];

      FUN_00544a37(iVar5,&local_20c,10);

      FUN_00446a90(&local_1bc);

      if (local_22c == (undefined *)0x0) {

        afStack_1b8[3] = (float)(&DAT_00561178)[iVar6 * 2];

        afStack_1b8[4] = (float)(&DAT_0056117c)[iVar6 * 2] + 0.05;

        afStack_1b8[2] = _DAT_005611b8 * 0.25;

        afStack_1b8[1] = _DAT_005611b8 * 0.25;

      }

      else {

        iVar2 = *(int *)(local_22c + iVar6 * 4) * 0x58;

        local_1bc = 0x3f800000;

        afStack_1b8[0] = 0.675;

        afStack_1b8[3] = *(float *)(&DAT_00562550 + iVar2) / (fStack_1e4 + fStack_1e4);

        afStack_1b8[4] = *(float *)(&DAT_00562548 + iVar2) / (fStack_1e0 + fStack_1e0);

        afStack_1b8[1] =

             ((*(float *)(&DAT_00562550 + iVar2) - *(float *)(&DAT_00562544 + iVar2)) * 0.45) /

             (fStack_1e4 + fStack_1e4);

        afStack_1b8[2] =

             ((*(float *)(&DAT_00562554 + iVar2) - *(float *)(&DAT_00562548 + iVar2)) * 0.45) /

             (fStack_1e0 + fStack_1e0);

      }

      if (iVar5 < 0) {

        if (local_22c != (undefined *)0x0) {

          iVar5 = AudioDataStreamStatus__Fv_3();

          mission_004fe2d0(iVar5,&PTR_DAT_00562510 + *(int *)(local_22c + iVar6 * 4) * 0x16,

                           0x3f000000,0,&fStack_224,&fStack_228);

          FUN_004fa380(iVar5,&PTR_s_infinity_005744c8,0,0x3f800000,0x3f800000,

                       (float)*(int *)(iVar5 + 0x24) * fStack_224,

                       (float)*(int *)(iVar5 + 0x28) * fStack_228);

          FUN_004fa520(iVar5,&PTR_s_infinity_005744c8);

        }

      }

      else {

        afStack_1b8[4] = 1.0 - afStack_1b8[4];

        FNT_RenderInfoProcess__FP14FNT_RenderInfof(&local_1bc,DAT_006328e0);

        puVar14 = &local_1bc;

        pfVar9 = &local_20c;

        uVar4 = AudioGetMasterVolume__Fv_3();

        FUN_00446ce0(uVar4,pfVar9,puVar14);

      }

    }

    iVar6 = iVar6 + 1;

  } while (iVar6 < iStack_240);

  return;

}

/* ===== FUN_004cd5d0 @ 0x004CD5D0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* PS2 candidate: lens_effects_process__Fv (conf 0.401) */



void FUN_004cd5d0(void)



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

  iVar4 = FUN_004469e0();

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

  pfVar6 = (float *)FUN_00515db0();

  local_3c = *(float *)(DAT_006330e4 + 0x4f60) - *pfVar6;

  local_38 = *(float *)(DAT_006330e4 + 0x4f64) - pfVar6[1];

  local_34 = *(float *)(DAT_006330e4 + 0x4f68) - pfVar6[2];

  FUN_0050a810(&local_3c,&local_38,&local_34);

  local_24 = local_3c * 10.0 + *pfVar6;

  local_20 = local_38 * 10.0 + pfVar6[1];

  local_1c = local_34 * 10.0 + pfVar6[2];

  local_30 = *(float *)(DAT_006330e4 + 0x4f60) - local_3c * 1000.0;

  local_2c = *(float *)(DAT_006330e4 + 0x4f64) - local_38 * 1000.0;

  local_28 = *(float *)(DAT_006330e4 + 0x4f68) - local_34 * 1000.0;

  iVar7 = FUN_004ef070(&local_24,&local_30,0,0,1);

  if (iVar7 != 0) {

    pfVar6 = (float *)FUN_00515dc0(2);

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

        fVar11 = (float10)FUN_00543e70();

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

      fVar11 = (float10)FUN_004d5780(0x3f000000,0x3fc00000);

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

/* ===== FUN_004cd990 @ 0x004CD990 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_004cd990(void)



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

    pfVar6 = (float *)FUN_00515db0();

    local_208 = *pfVar6;

    local_204 = pfVar6[1];

    local_200 = pfVar6[2];

    FUN_00516260();

    FUN_005163e0(&local_1c0);

    fVar12 = (float10)FUN_00515d90();

    local_210 = (undefined4 *)(float)fVar12;

    fVar12 = (float10)FUN_00515da0();

    local_1e4 = (float)fVar12;

    FUN_00451da0();

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

          FUN_005161c0(0,0,fStack_20c);

          (**(code **)(DAT_00656420 + 0xa0))(DAT_00656420,0,0,fStack_20c,fVar1,0);

          iVar5 = *(int *)(*(int *)(iVar9 + 8) + 8 + *(int *)(iVar9 + 0x10) * 4);

          FUN_00515de0(iVar5 + 0xc,iVar5 + 0x18);

          FUN_0053d9e0();

          FUN_005162b0(auStack_16c);

          xfmat_mult_b();

          FUN_00451cf0();

          (**(code **)(DAT_00656420 + 0x14))();

          animate_core_caller(iVar9,0,0,auStack_170,&local_208);

          FUN_00451da0();

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

    FUN_00516220(local_1e0,iVar5,uVar13);

    FUN_005162b0();

    FUN_005160b0(local_210,local_1e4,1);

    FUN_00451cf0();

  }

  if (DAT_00632e74 != 0) {

    FUN_00470220();

  }

  xfmat_mult_b();

  piVar11 = DAT_00632d68;

  while ((piVar11 != (int *)0x0 &&

         ((*(int *)(piVar11[3] + 0x204) == 0 || (iVar5 = FUN_00513a20(), iVar5 != 0))))) {

    piVar11 = (int *)*piVar11;

  }

  main_drawobj_0042d490();

  FUN_0040d6b0();

  iVar5 = comm_00426540();

  if (iVar5 == 0) {

    FUN_004a13c0();

    if (0 < DAT_00633244) {

      main_drawwatr_00430fd0();

    }

    audio_stream_tied();

    FUN_00435f30();

    iVar5 = AudioGetMasterVolume__Fv();

    FUN_004a13c0();

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

           ((iVar7 = FUN_004a6120(), iVar7 != 0 && (*(int *)(iVar9 + 0x274) == iVar5)))) {

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

              FUN_00542f27();

              local_1c0 = *(undefined4 *)(iVar5 + 0xa0);

              uStack_1bc = *(undefined4 *)(iVar5 + 0xa4);

              uStack_1b8 = *(undefined4 *)(iVar5 + 0xa8);

              FUN_00516a20(&local_1c0,puVar14,uVar13);

              FUN_0051bed0();

            }

          }

        }

      }

    }

    FUN_00435fd0();

    cleanup_00436060();

    pcVar10 = s_InDome_005611d0;

    FUN_004a13c0();

    uVar15 = CONCAT44(pcVar10,&DAT_00561138);

    iVar5 = DAT_00656420;

    (**(code **)(DAT_00656420 + 0x18))();

    uVar13 = CONCAT44(iVar5,1);

    iVar5 = DAT_00656430;

    (**(code **)(DAT_00656430 + 0xc))();

    (**(code **)(DAT_00656430 + 0x10))(DAT_00656430,1,iVar5,uVar13,uVar15);

    FUN_00515eb0(&local_218,&local_210);

    FNT_StringRender__FPcP14FNT_RenderInfo(local_218,(undefined4 *)0x46dac000);

    fVar12 = (float10)FUN_00515da0();

    FUN_00515d90((float)fVar12);

    FUN_005160b0();

    FUN_0042a4f0();

    FNT_StringRender__FPcP14FNT_RenderInfo(local_218,local_210);

    fVar12 = (float10)FUN_00515da0();

    FUN_00515d90((float)fVar12);

    FUN_005160b0();

    if (DAT_00633244 < 1) {

      main_drawwatr_00430fd0();

    }

    alpha_queue_push_2();

    FUN_004cd5d0();

    main_drawwatr_00431700();

    render_view_xform();

    FUN_00536cb0();

    iVar5 = FUN_0052aa70();

    if ((iVar5 != 0) && (puVar2 = DAT_00632d70, _DAT_00633254 < 2)) {

      for (; puVar3 = DAT_00632d74, puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {

        if ((-1 < *(char *)(puVar2[3] + 0xd8)) && (iVar5 = FUN_004a6160(), iVar5 != 0)) {

          status_update_entry();

        }

      }

      for (; puVar2 = DAT_00632d78, puVar3 != (undefined4 *)0x0; puVar3 = (undefined4 *)*puVar3) {

        if ((-1 < *(char *)(puVar3[3] + 0xd8)) && (iVar5 = FUN_004a6180(), iVar5 != 0)) {

          status_update_entry();

        }

      }

      for (; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {

        if ((-1 < *(char *)(puVar2[3] + 0xd8)) && (iVar5 = FUN_004a61a0(), iVar5 != 0)) {

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

    iVar5 = FUN_00501090();

    if (iVar5 != 0) {

      FUN_0051b970(0x1fffff,0,0x3d2aaaab,0x3dcccccd,0x3f4ccccd,iVar5);

    }

    player_draw_missile_lock();

    FUN_004a5eb0();

    FUN_0040b8f0();

    FUN_004431c0();

    main_tracer_00509dd0();

    FUN_0042ea60();

    if (DAT_00633228 == 0) {

      MAP_MemGroupSetBase(DAT_006328f4,DAT_00632a88);

      FUN_00515580();

    }

    FUN_004cd990();

    FUN_004676a0();

    status_draw_panel();

    if (DAT_00632fac == 0) {

      FUN_004cc900();

    }

    FUN_0042f310();

    if (((DAT_00632bc0 != 0) || (DAT_00632e48 != 0)) || (DAT_00632bc4 != 0)) {

      FUN_00427100();

    }

    FUN_0042ef80();

    FUN_004a14b0();

  }

  SetupCameraHail__Fv();

  FUN_00482350();

  if ((DAT_006331c4 == 0) && (iVar5 = FUN_0052c5c0(), iVar5 != 0)) {

    FUN_0051ba00(0,0,0x3d0f5c29,0x3f000000,0x3f000000,s_Dongle_check_skipped_____00561350);

  }

  if (DAT_00632bd8 != 0) {

    puVar14 = auStack_108;

    uVar13 = CONCAT44(DAT_00632bfc * 0x118 + 0x2210 + DAT_006330e4,s_Mission_Edit_Mode___s_00561338)

    ;

    FUN_00542f27();

    FUN_0051ba00(0,0,0x3d0f5c29,0x3f000000,0x3d4ccccd,auStack_108,puVar14,uVar13);

  }

  if ((DAT_00632c00 == 0) && (0.0 < _DAT_00632bdc)) {

    story_flick_open();

    FUN_00542f27(&local_1c0,s__8_0f_00561330,(double)_DAT_00632bdc);

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

    FUN_0051ba00(uVar13,0x3f0000003d3851ec,uVar15);

  }

  if (0 < DAT_00632f08) {

    if (2.0 < _DAT_00632b60) {

      uVar8 = FUN_00507b00();

      FUN_0051ba00(0x1fff1f,0,0x3d4ccccd,0x3f000000,0x3f000000,uVar8);

    }

    if (DAT_00632fc0 != 0) {

      iVar5 = __ftol();

      if (iVar5 / 0xe10 == 0) {

        FUN_00542f27(local_1e0,s__d__02d_0056130c,(iVar5 % 0xe10) / 0x3c,(iVar5 % 0xe10) % 0x3c);

      }

      else {

        FUN_00542f27();

      }

      FUN_0051ba00(0x1fff1f,0,0x3d4ccccd,0x3f000000,0x3ca3d70a,local_1e0);

    }

    if (0.0 < DAT_00632f30) {

      iVar5 = __ftol();

      if (iVar5 / 0xe10 == 0) {

        FUN_00542f27(local_1e0,s__d__02d_0056130c,(iVar5 % 0xe10) / 0x3c,(iVar5 % 0xe10) % 0x3c);

      }

      else {

        FUN_00542f27();

      }

      uVar8 = FUN_00507b00(s_CapsAllowedTimer_005612f8,local_1e0);

      FUN_00542f27(auStack_170,s__s__s_0055c280,uVar8);

      FUN_0051ba00(0xff1f1f,0,0x3cf5c28f,0x3f000000,0x3d75c28f,auStack_170);

    }

    if (((DAT_00632f08 < 7) || (9 < DAT_00632f08)) &&

       ((((byte)DAT_00633040 & 1) != 0 ||

        ((((((byte)DAT_00633040 & 4) != 0 || (((byte)DAT_00633040 & 8) != 0)) ||

          (((byte)DAT_00633040 & 0x10) != 0)) || (((byte)DAT_00633040 & 2) != 0)))))) {

      uVar8 = FUN_00507b00();

      FUN_0051ba00(0x1fff1f,0,0x3d4ccccd,0x3f000000,0x3f000000,uVar8);

    }

  }

  if (DAT_00633234 == 0) goto LAB_004ce7b8;

  iVar5 = FUN_00455b70(&LAB_004ce810,0,0x47afc800,local_1e0);

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

      FUN_00542f27();

      puVar16 = &DAT_00657400;

    }

    else {

      local_208 = 0.0;

      local_204 = 0.0;

      local_200 = 0.0;

      ai_get_goal_location(iVar5,&local_208);

      iVar9 = FUN_004eba40(2,iVar5);

      if (iVar9 == 0) {

        iVar9 = FUN_004eba40(1,iVar5);

        uVar8 = 0;

        if (iVar9 != 0) goto LAB_004ce6e4;

      }

      else {

LAB_004ce6e4:

        uVar8 = 1;

      }

      FUN_00542f27(&DAT_00657400,s_ost__d_otmr__1_3f_scn__d_hp__1_2_00561218,

                   *(undefined4 *)(iVar5 + 0xe4),(double)*(float *)(iVar5 + 0xec),uVar8,

                   (double)*(float *)(iVar5 + 0x278),(int)*(char *)(iVar5 + 0x20a),

                   (int)*(char *)(iVar5 + 0x20b),*(uint *)(iVar5 + 0xd8) >> 0x19 & 1,

                   *(byte *)(iVar5 + 0xdb) & 1,*(int *)(iVar5 + 0x168) != 0,(double)local_208,

                   (double)local_204,(double)local_200);

      puVar16 = &DAT_00657400;

    }

  }

  FUN_0051b970(0xffffff,0,0x3d1a6b51,0x3dcccccd,0x3dcccccd,puVar16);

LAB_004ce7b8:

  ANM_DumpCluster();

  FUN_00536700();

  iVar5 = fps_display();

  if (iVar5 == 0) {

    return 0;

  }

  if (DAT_00633100 != 0) {

    comm_net_stats_dump();

  }

  if (DAT_00632c0c != 0) {

    FUN_004829d0();

  }

  return 1;

}

/* ===== comm_004ce880 @ 0x004CE880 ===== */
void comm_004ce880(int param_1,undefined4 param_2)



{

  if (param_1 / 0xe10 != 0) {

    FUN_00542f27(param_2,s__d__02d__02d_00561314,param_1 / 0xe10);

    return;

  }

  FUN_00542f27(param_2,s__d__02d_0056130c,(param_1 % 0xe10) / 0x3c,(param_1 % 0xe10) % 0x3c);

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

      fVar6 = (float10)FUN_004d5780(*(undefined4 *)(iVar1 + 4),*(undefined4 *)(iVar1 + 8));

      *(float *)(iVar4 + 0xc4) = (float)fVar6;

      *(uint *)(iVar4 + 0x1c8) = *(uint *)(iVar4 + 0x1c8) | 0x840;

      iVar2 = *(int *)(*(int *)(iVar4 + 8) + 0x400);

      fVar6 = (float10)FUN_0050a5e0(iVar2 + 0x44,iVar2 + 0x50);

      iVar2 = *(int *)(iVar4 + 0x170);

      if (iVar2 != 0) {

        local_18 = 0;

        do {

          fVar7 = (float10)FUN_004d5780(-*(float *)(iVar2 + 0x10),*(undefined4 *)(iVar2 + 0x10));

          local_c = (float)(fVar7 + (float10)*(float *)(iVar2 + 0x18));

          fVar7 = (float10)FUN_004d5780(-*(float *)(iVar2 + 0x10),*(undefined4 *)(iVar2 + 0x10));

          local_8 = (float)(fVar7 + (float10)*(float *)(iVar2 + 0x1c));

          local_4 = *(undefined4 *)(iVar2 + 0x20);

          puVar3 = DAT_00632d6c;

          while ((puVar3 != (undefined4 *)0x0 &&

                 (((iVar5 = puVar3[3], iVar5 == iVar4 || (*(int *)(iVar5 + 0x170) != iVar2)) ||

                  (fVar7 = (float10)FUN_0050a5e0(iVar5 + 0xa0,&local_c),

                  (float10)(float)fVar6 <= fVar7))))) {

            puVar3 = (undefined4 *)*puVar3;

          }

        } while ((iVar5 != 0) && (local_18 = local_18 + 1, local_18 < 10));

        FUN_004993c0(iVar4,&local_c);

      }

      *(undefined4 *)(iVar4 + 0xe4) = *(undefined4 *)(param_1 + 0xe4);

      local_1c = local_1c + 1;

    } while ((float)local_1c < *(float *)(iVar1 + 0xc));

  }

  return;

}

/* ===== FUN_004cea60 @ 0x004CEA60 ===== */
/* PS2 candidate: ObjIsMeccBaseWall (conf 0.509) */



void FUN_004cea60(int param_1)



{

  int iVar1;

  

  FUN_004ceaa0(param_1);

  iVar1 = *(int *)(param_1 + 0xe4);

  if ((((iVar1 != 0x14) && (iVar1 != 0x67)) && (iVar1 != 0x68)) && (iVar1 != 0x6c)) {

    FUN_004a6730(param_1);

  }

  return;

}

/* ===== FUN_004ceaa0 @ 0x004CEAA0 ===== */
/* PS2 candidate: smartie_move (conf 0.445) */



void FUN_004ceaa0(float param_1)



{

  int *piVar1;

  float fVar2;

  float fVar3;

  uint uVar4;

  float fVar5;

  undefined1 uVar6;

  int iVar7;

  int iVar8;

  undefined4 uVar9;

  int iVar10;

  int iVar11;

  float *pfVar12;

  uint uVar13;

  undefined4 *puVar14;

  float10 fVar15;

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

  

  fVar5 = param_1;

  iVar11 = *(int *)((int)param_1 + 0x100);

  if (DAT_00632e74 != 0) {

    return;

  }

  if ((*(byte *)((int)param_1 + 0xe0) & 1) != 0) {

    return;

  }

  iVar7 = FUN_0052e480(param_1);

  iVar10 = DAT_00632a88;

  if (iVar7 == 0) {

    return;

  }

  if (*(int *)((int)fVar5 + 0x210) != 0) {

    iVar7 = *(int *)(*(int *)((int)fVar5 + 0x210) + 0x1e0);

    if (iVar7 == 1) {

      return;

    }

    if (iVar7 == 0x4c) {

      return;

    }

  }

  iVar7 = *(int *)((int)fVar5 + 0x100);

  fVar15 = (float10)FUN_00518b70(fVar5,0);

  fVar15 = (float10)*(float *)(iVar7 + 0x54) - fVar15;

  *(float *)(iVar7 + 0x54) = (float)fVar15;

  if (fVar15 < (float10)0.0) {

    *(undefined4 *)(iVar7 + 0x54) = 0;

  }

  iVar8 = FUN_004a6160(iVar10);

  if ((iVar8 == 0) || ((*(uint *)(iVar10 + 0xe0) & 0x2000000) == 0)) {

    *(undefined4 *)(iVar7 + 0x54) = 0;

  }

  else if (((*(float *)(iVar10 + 0x10c) != 0.0) || (*(float *)(iVar10 + 0x110) != 0.0)) &&

          (fVar15 = (float10)FUN_0050a610((int)fVar5 + 0xa0,iVar10 + 0xa0),

          fVar15 < (float10)57600.0)) {

    fVar15 = (float10)FUN_00518b70(fVar5,0);

    *(float *)(iVar7 + 0x54) = (float)(fVar15 + fVar15 + (float10)*(float *)(iVar7 + 0x54));

  }

  if (*(int *)((int)fVar5 + 0xe8) == 1) {

    switch(*(undefined4 *)((int)fVar5 + 0xe4)) {

    case 0:

      *(undefined4 *)((int)fVar5 + 0x18c) = 100;

      puVar14 = DAT_00632d68;

      do {

        if (puVar14 == (undefined4 *)0x0) {

LAB_004cec2d:

          fVar15 = (float10)FUN_004d5780(*(undefined4 *)(DAT_00632ed8 + 0xd0c),

                                         *(undefined4 *)(DAT_00632ed8 + 0xd10));

          *(float *)((int)fVar5 + 0xf0) = (float)fVar15;

          *(undefined4 *)((int)fVar5 + 0xe4) = 0x14;

          return;

        }

        iVar10 = puVar14[3];

        if (((*(int *)(iVar10 + 0x1e0) == 0x60) && (*(int *)(iVar10 + 4) == 0x41c)) &&

           ((*(int *)(iVar10 + 0x174) == 0 && (iVar7 = __ftol(), *(int *)(iVar10 + 0xe8) == iVar7)))

           ) {

          *(int *)(iVar11 + 0x24) = iVar10;

          goto LAB_004cec2d;

        }

        puVar14 = (undefined4 *)*puVar14;

      } while( true );

    default:

      return;

    case 0x14:

      if (*(int *)(iVar11 + 0x24) == 0) {

        *(undefined4 *)((int)fVar5 + 0xe8) = 0;

        *(undefined4 *)((int)fVar5 + 0xe4) = 0;

        return;

      }

      iVar10 = *(int *)(iVar11 + 0x24);

      fVar15 = (float10)FUN_00518b70(fVar5,0);

      pfVar12 = (float *)((int)fVar5 + 0xa0);

      fVar15 = fVar15 * (float10)*(float *)(iVar10 + 0xfc) + (float10)*(float *)(iVar11 + 0x2c);

      param_1 = (float)fVar15;

      *(float *)(iVar11 + 0x2c) = (float)fVar15;

      FUN_00478080(iVar10,param_1,param_1,pfVar12);

      FUN_00414690(pfVar12,local_1c);

      *(undefined4 *)((int)fVar5 + 0xa8) = local_c;

      if ((*(float *)((int)fVar5 + 0xb8) != *pfVar12) ||

         (*(float *)((int)fVar5 + 0xbc) != *(float *)((int)fVar5 + 0xa4))) {

        fVar15 = (float10)FUN_0050a400((int)fVar5 + 0xb8,pfVar12);

        *(float *)((int)fVar5 + 200) = (float)fVar15;

      }

      *(uint *)((int)fVar5 + 0xd8) = *(uint *)((int)fVar5 + 0xd8) | 0x40;

      FUN_004967b0(fVar5);

      fVar15 = (float10)FUN_00518b70(fVar5,0);

      FUN_00403e60(fVar5,(float)fVar15);

      FUN_004a7440(fVar5);

      *(uint *)((int)fVar5 + 0xd8) = *(uint *)((int)fVar5 + 0xd8) | 0x20;

      if (*(int *)((int)fVar5 + 4) == 0xe6) {

        uVar9 = *(undefined4 *)(DAT_00632ed8 + 0xfc);

      }

      else if (*(int *)((int)fVar5 + 4) == 0x49) {

        uVar9 = *(undefined4 *)(DAT_00632ed8 + 0xe0);

      }

      else {

        uVar9 = *(undefined4 *)(DAT_00632ed8 + 0x88);

      }

      FUN_004d1a00(fVar5,uVar9);

      if (*(int *)(iVar11 + 0xc) != 0) {

        *(undefined4 *)((int)fVar5 + 0xe8) = 0;

        if (*(int *)((int)fVar5 + 4) == 0xe6) {

          *(undefined4 *)((int)fVar5 + 0xe4) = 0x40;

          return;

        }

        *(uint *)((int)fVar5 + 0xe4) = ((*(int *)((int)fVar5 + 4) != 0x49) - 1 & 0x1a) + 7;

        return;

      }

      fVar15 = (float10)FUN_00518b70(fVar5,0);

      fVar15 = (float10)*(float *)((int)fVar5 + 0xf0) - fVar15;

      *(float *)((int)fVar5 + 0xf0) = (float)fVar15;

      if (fVar15 < (float10)0.0 == (fVar15 == (float10)0.0)) {

        return;

      }

      FUN_004d1840(fVar5,*(undefined4 *)(DAT_00632ed8 + 0xfc));

      if (*(int *)(iVar11 + 0xc) != 0) {

        *(undefined4 *)((int)fVar5 + 0xfc) = *(undefined4 *)((int)fVar5 + 200);

        *(undefined4 *)((int)fVar5 + 0xe4) = 0x16;

        return;

      }

LAB_004cf690:

      fVar15 = (float10)FUN_004d5780(*(undefined4 *)(DAT_00632ed8 + 0xd0c),

                                     *(undefined4 *)(DAT_00632ed8 + 0xd10));

      *(float *)((int)fVar5 + 0xf0) = (float)fVar15;

      return;

    case 0x15:

      fVar15 = (float10)FUN_00518b70(fVar5,0);

      fVar15 = (float10)*(float *)((int)fVar5 + 0xf0) - fVar15;

      *(float *)((int)fVar5 + 0xf0) = (float)fVar15;

      if (fVar15 < (float10)0.0 != (fVar15 == (float10)0.0)) {

        if (*(int *)(iVar11 + 0xc) == 0) {

          *(undefined4 *)((int)fVar5 + 0xf4) = 0;

        }

        else if (*(int *)((int)fVar5 + 0x10) != 0x32) {

          anim_select_check2(fVar5,0x32);

        }

      }

      if (*(int *)((int)fVar5 + 0xf4) < 1) {

        *(undefined4 *)(iVar11 + 0xc) = 0;

        fVar15 = (float10)FUN_004d5780(*(undefined4 *)(DAT_00632ed8 + 0xd0c),

                                       *(undefined4 *)(DAT_00632ed8 + 0xd10));

        *(float *)((int)fVar5 + 0xf0) = (float)fVar15;

        *(undefined4 *)((int)fVar5 + 0xe4) = 0x16;

        return;

      }

      return;

    case 0x16:

      if (*(float *)((int)fVar5 + 0xf0) < 0.0 == (*(float *)((int)fVar5 + 0xf0) == 0.0)) {

        local_48 = *(float *)((int)fVar5 + 0xfc);

        *(undefined1 *)((int)fVar5 + 0x208) = 0;

        fVar15 = (float10)FUN_0050a7c0(local_48,*(undefined4 *)((int)fVar5 + 200));

        param_1 = (float)fVar15;

        if (ABS(fVar15) == (float10)0.0) {

          param_1 = 0.0;

        }

        else {

          uVar6 = FUN_004a7cb0(param_1 * 0.05,0x3e800000);

          *(undefined1 *)((int)fVar5 + 0x208) = uVar6;

          *(float *)((int)fVar5 + 0x158) = local_48;

          *(uint *)((int)fVar5 + 0xd8) = *(uint *)((int)fVar5 + 0xd8) | 0x1000000;

        }

        if (ABS(param_1) < 3.0 == (ABS(param_1) == 3.0)) {

          return;

        }

        *(undefined4 *)((int)fVar5 + 0xe4) = 0x14;

      }

      else if (*(int *)(iVar11 + 0xc) == 0) {

        fVar15 = (float10)FUN_004d5780(*(undefined4 *)(DAT_00632ed8 + 0xd0c),

                                       *(undefined4 *)(DAT_00632ed8 + 0xd10));

        *(float *)((int)fVar5 + 0xf0) = (float)fVar15;

        *(undefined4 *)((int)fVar5 + 0xe4) = 0x14;

      }

      else {

        iVar11 = *(int *)(iVar11 + 0xc) + 0xa0;

        *(undefined1 *)((int)fVar5 + 0x208) = 0;

        if (iVar11 == 0) {

          param_1 = 0.0;

        }

        else {

          fVar15 = (float10)FUN_0050a400((int)fVar5 + 0xa0,iVar11);

          param_1 = (float)fVar15;

        }

        fVar15 = (float10)FUN_0050a7c0(param_1,*(undefined4 *)((int)fVar5 + 200));

        local_4c = (float *)(float)fVar15;

        if (ABS(fVar15) == (float10)0.0) {

          pfVar12 = (float *)0x0;

        }

        else {

          uVar6 = FUN_004a7cb0((float)local_4c * 0.05,0x3e800000);

          *(undefined1 *)((int)fVar5 + 0x208) = uVar6;

          *(float *)((int)fVar5 + 0x158) = param_1;

          *(uint *)((int)fVar5 + 0xd8) = *(uint *)((int)fVar5 + 0xd8) | 0x1000000;

          pfVar12 = local_4c;

        }

        if (ABS((float)pfVar12) < 3.0 == (ABS((float)pfVar12) == 3.0)) {

          return;

        }

        uVar9 = FUN_004d5740(*(undefined4 *)(DAT_00632ed8 + 0xd18),

                             *(undefined4 *)(DAT_00632ed8 + 0xd1c));

        *(undefined4 *)((int)fVar5 + 0xf4) = uVar9;

        fVar15 = (float10)FUN_004d5780(0,*(undefined4 *)(DAT_00632ed8 + 0xd14));

        *(float *)((int)fVar5 + 0xf0) = (float)fVar15;

        *(undefined4 *)((int)fVar5 + 0xe4) = 0x15;

      }

    }

LAB_004cf539:

    *(uint *)((int)fVar5 + 0xd8) = *(uint *)((int)fVar5 + 0xd8) & 0xfcffffff;

    *(undefined1 *)((int)fVar5 + 0x208) = 0;

    return;

  }

  if (*(int *)((int)fVar5 + 0xe8) == 100) {

    switch(*(undefined4 *)((int)fVar5 + 0xe4)) {

    case 0:

      *(undefined4 *)((int)fVar5 + 0x18c) = 100;

      iVar10 = *(int *)(*(int *)(iVar11 + 0x24) + 0x100);

      for (puVar14 = DAT_00632d68; puVar14 != (undefined4 *)0x0; puVar14 = (undefined4 *)*puVar14) {

        iVar7 = puVar14[3];

        if (((*(int *)(iVar7 + 4) == 0x48a) &&

            (*(int *)(iVar7 + 0xe8) == *(int *)(*(int *)(iVar10 + 0x18) + 0xe8))) &&

           ((*(int *)(iVar11 + 0x3c) == 0 ||

            (*(int *)(*(int *)(iVar11 + 0x3c) + 0x174) < *(int *)(iVar7 + 0x174))))) {

          *(int *)(iVar11 + 0x3c) = iVar7;

        }

      }

      *(uint *)((int)fVar5 + 0x1c8) = *(uint *)((int)fVar5 + 0x1c8) | 0xe00;

      *(uint *)((int)fVar5 + 0xd8) = *(uint *)((int)fVar5 + 0xd8) | 0x10;

      *(uint *)((int)fVar5 + 0xe0) = *(uint *)((int)fVar5 + 0xe0) | 4;

      fVar15 = (float10)FUN_004d5780(*(undefined4 *)(DAT_00632ed8 + 0xd0c),

                                     *(undefined4 *)(DAT_00632ed8 + 0xd10));

      *(float *)((int)fVar5 + 0xf0) = (float)fVar15;

      *(undefined4 *)((int)fVar5 + 0xe4) = 100;

      return;

    case 100:

      FUN_00402270(fVar5);

      if (*(int *)((int)fVar5 + 0x168) == 0) {

        *(uint *)((int)fVar5 + 0x1c8) = *(uint *)((int)fVar5 + 0x1c8) & 0xfffff1ff;

        *(uint *)((int)fVar5 + 0xd8) = *(uint *)((int)fVar5 + 0xd8) & 0xffffffef;

        FUN_004a76e0(*(undefined4 *)(iVar11 + 0x24),*(undefined4 *)(iVar11 + 0x28),&local_34);

        main_ai_move_004014b0(fVar5,&local_34,*(undefined4 *)(*(int *)(iVar11 + 0x24) + 200));

        *(undefined4 *)((int)fVar5 + 0xe4) = 0x65;

        return;

      }

      break;

    case 0x65:

      FUN_00402270(fVar5);

      if (*(int *)((int)fVar5 + 0x168) == 0) {

        piVar1 = (int *)(*(int *)(*(int *)(iVar11 + 0x24) + 0x100) + 8);

        *piVar1 = *piVar1 + 1;

        *(uint *)((int)fVar5 + 0xe0) = *(uint *)((int)fVar5 + 0xe0) & 0xfffffffb;

        *(undefined4 *)((int)fVar5 + 0xe4) = 0x66;

        return;

      }

      break;

    case 0x66:

      iVar10 = *(int *)(*(int *)(iVar11 + 0x24) + 0x100);

      puVar14 = DAT_00632d6c;

      if (*(int *)(iVar10 + 8) == *(int *)(iVar10 + 4)) {

        for (; puVar14 != (undefined4 *)0x0; puVar14 = (undefined4 *)*puVar14) {

          iVar10 = puVar14[3];

          if ((*(int *)(iVar10 + 4) == 0xe6) &&

             (*(int *)(*(int *)(iVar10 + 0x100) + 0x24) == *(int *)(iVar11 + 0x24))) {

            *(undefined4 *)(iVar10 + 0xe4) = 0x67;

          }

        }

        *(undefined4 *)(*(int *)(iVar11 + 0x24) + 0xe4) = 2;

        return;

      }

      break;

    case 0x68:

      FUN_004d3720(fVar5);

      if (*(int *)(iVar11 + 0x40) == 0) {

        fVar15 = (float10)FUN_00518b70(fVar5,0);

        fVar15 = (float10)*(float *)((int)fVar5 + 0xf0) - fVar15;

        *(float *)((int)fVar5 + 0xf0) = (float)fVar15;

        if (fVar15 < (float10)0.0 != (fVar15 == (float10)0.0)) {

          FUN_004d1840(fVar5,*(undefined4 *)(DAT_00632ed8 + 0xfc));

          *(undefined4 *)(*(int *)(iVar11 + 0x24) + 0x274) = *(undefined4 *)(iVar11 + 0xc);

          fVar15 = (float10)FUN_004d5780(*(undefined4 *)(DAT_00632ed8 + 0xd0c),

                                         *(undefined4 *)(DAT_00632ed8 + 0xd10));

          *(float *)((int)fVar5 + 0xf0) = (float)fVar15;

        }

      }

      else {

        *(undefined4 *)(iVar11 + 0xc) = *(undefined4 *)(*(int *)(iVar11 + 0x24) + 0x274);

      }

      if (*(int *)(iVar11 + 0xc) != 0) {

        piVar1 = (int *)(*(int *)(*(int *)(iVar11 + 0x24) + 0x100) + 8);

        *piVar1 = *piVar1 + -1;

        *(uint *)((int)fVar5 + 0xe0) = *(uint *)((int)fVar5 + 0xe0) | 4;

        *(undefined4 *)((int)fVar5 + 0xfc) = *(undefined4 *)((int)fVar5 + 200);

        *(undefined4 *)((int)fVar5 + 0xe4) = 0x69;

        *(undefined4 *)((int)fVar5 + 0xf0) = 0;

        *(undefined4 *)(*(int *)(iVar11 + 0x24) + 0xe4) = 3;

        return;

      }

      break;

    case 0x69:

      if (*(float *)((int)fVar5 + 0xf0) < 0.0 != (*(float *)((int)fVar5 + 0xf0) == 0.0)) {

        if (*(int *)(iVar11 + 0xc) == 0) {

          fVar15 = (float10)FUN_004d5780(*(undefined4 *)(DAT_00632ed8 + 0xd0c),

                                         *(undefined4 *)(DAT_00632ed8 + 0xd10));

          *(float *)((int)fVar5 + 0xf0) = (float)fVar15;

          *(undefined4 *)((int)fVar5 + 0xe4) = 0x68;

        }

        else {

          iVar11 = *(int *)(iVar11 + 0xc) + 0xa0;

          *(undefined1 *)((int)fVar5 + 0x208) = 0;

          if (iVar11 == 0) {

            param_1 = 0.0;

          }

          else {

            fVar15 = (float10)FUN_0050a400((int)fVar5 + 0xa0,iVar11);

            param_1 = (float)fVar15;

          }

          fVar15 = (float10)FUN_0050a7c0(param_1,*(undefined4 *)((int)fVar5 + 200));

          local_4c = (float *)(float)fVar15;

          if (ABS(fVar15) == (float10)0.0) {

            pfVar12 = (float *)0x0;

          }

          else {

            uVar6 = FUN_004a7cb0((float)local_4c * 0.05,0x3e800000);

            *(undefined1 *)((int)fVar5 + 0x208) = uVar6;

            *(float *)((int)fVar5 + 0x158) = param_1;

            *(uint *)((int)fVar5 + 0xd8) = *(uint *)((int)fVar5 + 0xd8) | 0x1000000;

            pfVar12 = local_4c;

          }

          if (ABS((float)pfVar12) < 3.0 == (ABS((float)pfVar12) == 3.0)) {

            return;

          }

          uVar9 = FUN_004d5740(*(undefined4 *)(DAT_00632ed8 + 0xd18),

                               *(undefined4 *)(DAT_00632ed8 + 0xd1c));

          *(undefined4 *)((int)fVar5 + 0xf4) = uVar9;

          *(undefined4 *)((int)fVar5 + 0xe4) = 0x6a;

        }

        goto LAB_004cf539;

      }

      local_48 = *(float *)((int)fVar5 + 0xfc);

      *(undefined1 *)((int)fVar5 + 0x208) = 0;

      fVar15 = (float10)FUN_0050a7c0(local_48,*(undefined4 *)((int)fVar5 + 200));

      param_1 = (float)fVar15;

      if (ABS(fVar15) == (float10)0.0) {

        param_1 = 0.0;

      }

      else {

        uVar6 = FUN_004a7cb0(param_1 * 0.05,0x3e800000);

        *(undefined1 *)((int)fVar5 + 0x208) = uVar6;

        *(float *)((int)fVar5 + 0x158) = local_48;

        *(uint *)((int)fVar5 + 0xd8) = *(uint *)((int)fVar5 + 0xd8) | 0x1000000;

      }

      if (ABS(param_1) < 3.0 != (ABS(param_1) == 3.0)) {

        piVar1 = (int *)(*(int *)(*(int *)(iVar11 + 0x24) + 0x100) + 8);

        *piVar1 = *piVar1 + 1;

        *(uint *)((int)fVar5 + 0xe0) = *(uint *)((int)fVar5 + 0xe0) & 0xfffffffb;

        *(undefined4 *)((int)fVar5 + 0xe4) = 0x6b;

        return;

      }

      break;

    case 0x6a:

      fVar15 = (float10)FUN_00518b70(fVar5,0);

      fVar15 = (float10)*(float *)((int)fVar5 + 0xf0) - fVar15;

      *(float *)((int)fVar5 + 0xf0) = (float)fVar15;

      if (fVar15 < (float10)0.0 != (fVar15 == (float10)0.0)) {

        if (*(int *)(iVar11 + 0xc) == 0) {

          *(undefined4 *)((int)fVar5 + 0xf4) = 0;

        }

        else if (*(int *)((int)fVar5 + 0x10) != 0x32) {

          anim_select_check2(fVar5,0x32);

        }

      }

      if (*(int *)((int)fVar5 + 0xf4) < 1) {

        *(undefined4 *)(iVar11 + 0xc) = 0;

        *(undefined4 *)(*(int *)(iVar11 + 0x24) + 0x274) = 0;

        fVar15 = (float10)FUN_004d5780(*(undefined4 *)(DAT_00632ed8 + 0xd0c),

                                       *(undefined4 *)(DAT_00632ed8 + 0xd10));

        *(float *)((int)fVar5 + 0xf0) = (float)fVar15;

        *(undefined4 *)((int)fVar5 + 0xe4) = 0x69;

        return;

      }

      break;

    case 0x6b:

      iVar10 = *(int *)(*(int *)(iVar11 + 0x24) + 0x100);

      if (*(int *)(iVar10 + 8) == *(int *)(iVar10 + 4)) {

        *(undefined4 *)((int)fVar5 + 0xe4) = 0x68;

        *(uint *)((int)fVar5 + 0xd8) = *(uint *)((int)fVar5 + 0xd8) & 0xfcffffff;

        *(undefined1 *)((int)fVar5 + 0x208) = 0;

        *(undefined4 *)(*(int *)(iVar11 + 0x24) + 0xe4) = 2;

        goto LAB_004cf690;

      }

      break;

    case 0x6c:

      if ((*(byte *)((int)fVar5 + 0x30) & 2) != 0) {

        *(undefined4 *)((int)fVar5 + 0xe4) = 0x67;

      }

    case 0x67:

      iVar10 = FUN_004d3720(fVar5);

      if (iVar10 == *(int *)(iVar11 + 0x3c)) {

        iVar11 = *(int *)(*(int *)(iVar11 + 0x24) + 0x100);

        puVar14 = DAT_00632d68;

        if (DAT_00632d68 != (undefined4 *)0x0) {

          while (((iVar10 = puVar14[3], *(int *)(iVar10 + 4) != 0x41c ||

                  (*(int *)(iVar10 + 0xe8) != *(int *)(iVar11 + 0x14))) ||

                 (*(int *)(iVar10 + 0x174) != 0))) {

            puVar14 = (undefined4 *)*puVar14;

            if (puVar14 == (undefined4 *)0x0) {

              *(undefined4 *)((int)fVar5 + 0xe4) = 0x68;

              return;

            }

          }

          *(int *)(iVar11 + 0x18) = iVar10;

          *(undefined4 *)(iVar11 + 0x20) = 0;

          *(undefined4 *)(iVar11 + 0x24) = *(undefined4 *)(iVar10 + 0xfc);

        }

        *(undefined4 *)((int)fVar5 + 0xe4) = 0x68;

        return;

      }

    }

    return;

  }

  iVar10 = *(int *)(iVar11 + 0x10);

  if ((iVar10 != 0) &&

     (((char)((uint)*(undefined4 *)(iVar10 + 0xd8) >> 8) < '\0' ||

      ((*(int *)(iVar10 + 0x1e0) != 0x31 && (*(int *)(iVar10 + 0x1e0) != 0x2f)))))) {

    *(undefined4 *)(iVar11 + 0x10) = 0;

  }

  *(uint *)((int)fVar5 + 0xd8) = *(uint *)((int)fVar5 + 0xd8) & 0xfcffffff;

  *(undefined1 *)((int)fVar5 + 0x208) = 0;

  *(undefined1 *)((int)fVar5 + 0x20a) = 0;

  switch(*(undefined4 *)((int)fVar5 + 0xe4)) {

  case 0:

    *(undefined4 *)((int)fVar5 + 0x18c) = 100;

    if (*(int *)((int)fVar5 + 0xe8) == 2) {

      *(undefined4 *)((int)fVar5 + 0xe4) = 0x55;

      *(undefined4 *)((int)fVar5 + 0x1bc) = 0;

    }

    else if (*(int *)((int)fVar5 + 0xe8) == 0x65) {

      sound_play_obj(0x4ff,fVar5);

      *(uint *)((int)fVar5 + 0x1c8) = *(uint *)((int)fVar5 + 0x1c8) | 0xe00;

      *(uint *)((int)fVar5 + 0xd8) = *(uint *)((int)fVar5 + 0xd8) | 0x10;

      puVar14 = (undefined4 *)(iVar11 + 0x48);

      fVar15 = (float10)FUN_0050a400((undefined4 *)((int)fVar5 + 0xa0),puVar14);

      *(float *)((int)fVar5 + 200) = (float)fVar15;

      FUN_00401050(fVar5,puVar14);

      *puVar14 = *(undefined4 *)((int)fVar5 + 0xa0);

      *(undefined4 *)(iVar11 + 0x4c) = *(undefined4 *)((int)fVar5 + 0xa4);

      *(undefined4 *)(iVar11 + 0x50) = *(undefined4 *)((int)fVar5 + 0xa8);

      *(undefined4 *)((int)fVar5 + 0xe4) = 0x96;

      *(undefined4 *)(iVar11 + 0x20) = *(undefined4 *)((int)fVar5 + 0x194);

      *(undefined4 *)((int)fVar5 + 0x1bc) = 0;

    }

    else if (*(int *)((int)fVar5 + 4) == 0xe6) {

      sound_play_obj(0x4d3,fVar5);

      *(undefined4 *)((int)fVar5 + 0xe4) = 0x3d;

      *(undefined4 *)((int)fVar5 + 0x1bc) = 0;

    }

    else if (*(int *)((int)fVar5 + 4) == 0x49) {

      sound_play_obj(0x4ea,fVar5);

      *(undefined4 *)((int)fVar5 + 0xe4) = 0x1f;

      *(undefined4 *)(iVar11 + 0x20) = *(undefined4 *)((int)fVar5 + 0x194);

      *(undefined4 *)((int)fVar5 + 0x1bc) = 0;

    }

    else {

      *(undefined4 *)((int)fVar5 + 0xe4) = 5;

      *(undefined4 *)((int)fVar5 + 0x1bc) = 0;

    }

    break;

  case 0x55:

    iVar10 = *(int *)(iVar11 + 0xc);

    iVar7 = *(int *)((int)fVar5 + 0x100);

    if (((((iVar10 != 0) && (*(int *)(iVar10 + 4) != 0)) &&

         ((*(uint *)(iVar10 + 0xd8) & 0x4000c000) == 0)) &&

        (*(float *)(iVar10 + 0x278) < *(float *)(iVar10 + 0x1c0))) &&

       (((iVar8 = FUN_004a6160(iVar10), iVar8 == 0 || ((*(uint *)(iVar10 + 0xe0) & 0x2000000) == 0))

        || (4.0 <= *(float *)(iVar7 + 0x54))))) {

      iVar7 = FUN_004a6180(iVar10);

      if (iVar7 == 0) goto LAB_004cf982;

      uVar13 = *(uint *)((int)fVar5 + 0xe0);

      if ((*(byte *)(iVar10 + 0xe0) & 8) == 0) {

        *(uint *)((int)fVar5 + 0xe0) = uVar13 & 0xffffffef;

        goto LAB_004cf982;

      }

      if ((uVar13 & 0x10) != 0) goto LAB_004cf982;

      *(uint *)((int)fVar5 + 0xe0) = uVar13 | 0x10;

    }

    *(undefined4 *)(iVar11 + 0xc) = 0;

LAB_004cf982:

    fVar15 = (float10)FUN_00518b70(fVar5,0);

    fVar15 = (float10)*(float *)((int)fVar5 + 0xf0) - fVar15;

    *(float *)((int)fVar5 + 0xf0) = (float)fVar15;

    if (*(int *)(iVar11 + 0xc) == 0) {

      if (fVar15 < (float10)0.0) {

        FUN_004d1a00(fVar5,*(undefined4 *)(DAT_00632ed8 + 0xfc));

        if (*(int *)(iVar11 + 0xc) == 0) {

          fVar15 = (float10)FUN_004d5780(0x3f000000,0x3fc00000);

          *(float *)((int)fVar5 + 0xf0) = (float)fVar15;

        }

        else {

          fVar15 = (float10)FUN_004d5780(*(undefined4 *)(DAT_00632ed8 + 0xd0c),

                                         *(undefined4 *)(DAT_00632ed8 + 0xd10));

          *(float *)((int)fVar5 + 0xf0) = (float)fVar15;

        }

      }

    }

    else {

      param_1 = *(float *)(DAT_00632ed8 + 0xfc);

      fVar15 = (float10)FUN_0050a5e0((int)fVar5 + 0xa0,*(int *)(iVar11 + 0xc) + 0xa0);

      if ((float10)param_1 * (float10)param_1 < fVar15) {

        *(undefined4 *)(iVar11 + 0xc) = 0;

      }

    }

    fVar15 = (float10)FUN_0050a400((int)fVar5 + 0xa0,DAT_00632a88 + 0xa0);

    *(float *)((int)fVar5 + 200) = (float)fVar15;

    return;

  case 0x96:

    FUN_00402270(fVar5);

    if (*(int *)((int)fVar5 + 0x168) == 0) {

      fVar15 = (float10)FUN_004d5780(0xc32a0000,0xc1200000);

      param_1 = (float)(fVar15 + (float10)*(float *)((int)fVar5 + 200));

      sine_cos_lookup(param_1,&local_4c,&local_48);

      fVar15 = (float10)FUN_004d5780(*(undefined4 *)(DAT_00632ed8 + 0xc98),

                                     *(undefined4 *)(DAT_00632ed8 + 0xc9c));

      local_34 = (float)(fVar15 * (float10)local_48 + (float10)*(float *)(iVar11 + 0x48));

      fVar15 = (float10)FUN_004d5780(*(undefined4 *)(DAT_00632ed8 + 0xc98),

                                     *(undefined4 *)(DAT_00632ed8 + 0xc9c));

      local_30 = (float)(fVar15 * (float10)(float)local_4c + (float10)*(float *)(iVar11 + 0x4c));

      fVar15 = (float10)FUN_0050a400(&local_34,(float *)(iVar11 + 0x48));

      param_1 = (float)fVar15;

      main_ai_move_004014b0(fVar5,&local_34,param_1);

      *(uint *)((int)fVar5 + 0x1c8) = *(uint *)((int)fVar5 + 0x1c8) & 0xfffff1ff;

      *(uint *)((int)fVar5 + 0xd8) = *(uint *)((int)fVar5 + 0xd8) & 0xffffffef;

      *(undefined4 *)((int)fVar5 + 0xe4) = 0x97;

    }

    break;

  case 0x97:

    FUN_00402270(fVar5);

    if (*(int *)((int)fVar5 + 0x168) == 0) {

      if (*(int *)((int)fVar5 + 4) == 0xe6) {

        sound_play_obj(0x4d3,fVar5);

        *(undefined4 *)((int)fVar5 + 0xe4) = 0x3d;

      }

      else if (*(int *)((int)fVar5 + 4) == 0x49) {

        sound_play_obj(0x4ea,fVar5);

        *(undefined4 *)((int)fVar5 + 0xe4) = 0x1f;

      }

      else {

        *(undefined4 *)((int)fVar5 + 0xe4) = 5;

      }

    }

  }

  if (*(int *)((int)fVar5 + 4) != 0xe6) {

    if (*(int *)((int)fVar5 + 4) == 0x49) {

      FUN_004d1bd0(fVar5);

      iVar10 = *(int *)((int)fVar5 + 0xe4);

      *(undefined4 *)((int)fVar5 + 0x194) = *(undefined4 *)(iVar11 + 0x20);

      if (((iVar10 != 0x1f) && (iVar10 != 0x22)) && (iVar10 != 0x24)) {

        return;

      }

      *(float *)((int)fVar5 + 0x194) =

           *(float *)(DAT_00632ed8 + 0x288) * *(float *)(iVar11 + 0x20) * 0.01;

      return;

    }

    pfVar12 = *(float **)((int)fVar5 + 0x100);

    uVar13 = *(uint *)((int)fVar5 + 0x30) & 2;

    if (pfVar12[3] == 0.0) {

LAB_004d0a94:

      if (((byte)DAT_00632e70 & 3) != 3) {

LAB_004d0a9e:

        FUN_004d1a00(fVar5,*(undefined4 *)(DAT_00632ed8 + 0x88));

      }

    }

    else {

      if (((byte)DAT_00632e70 & 0xf) != 0xf) goto LAB_004d0a9e;

      if (pfVar12[3] == 0.0) goto LAB_004d0a94;

    }

    fVar3 = pfVar12[3];

    if (fVar3 == 0.0) {

      local_48 = 9.99998e+11;

      local_4c = (float *)0x5368d487;

      local_38 = 99999.0;

      local_3c = 99999.0;

      local_40 = 99999.0;

    }

    else {

      local_40 = *(float *)((int)fVar3 + 0xa0);

      local_3c = *(float *)((int)fVar3 + 0xa4);

      local_38 = *(float *)((int)fVar3 + 0xa8);

      fVar15 = (float10)FUN_0050a5e0(&local_40,(int)fVar5 + 0xa0);

      local_48 = (float)fVar15;

      fVar15 = (float10)FUN_0050a610(&local_40,(int)fVar5 + 0xa0);

      local_4c = (float *)(float)fVar15;

      local_38 = *(float *)((int)fVar3 + 0x1e8) * *(float *)((int)fVar3 + 0xc4) + local_38;

    }

    fVar15 = (float10)FUN_0050a5e0((int)fVar5 + 0xa0,pfVar12 + 5);

    param_1 = (float)fVar15;

    if ((pfVar12[4] != 0.0) && (*(int *)((int)pfVar12[4] + 4) == 0xfd)) {

      param_1 = param_1 * 0.010000001;

    }

    switch(*(undefined4 *)((int)fVar5 + 0xe4)) {

    case 5:

      if (*pfVar12 <= 0.0) {

        *(undefined4 *)((int)fVar5 + 0xe4) = 6;

      }

      else {

        fVar15 = (float10)FUN_00518b70(fVar5,0);

        *pfVar12 = (float)((float10)*pfVar12 - fVar15);

        *(undefined1 *)((int)fVar5 + 0x20a) = 0x18;

        if (*(float *)((int)fVar5 + 200) != pfVar12[1]) {

          *(uint *)((int)fVar5 + 0xd8) = *(uint *)((int)fVar5 + 0xd8) | 0x1000000;

          *(float *)((int)fVar5 + 0x158) = pfVar12[1];

          fVar15 = (float10)FUN_0050a7c0(pfVar12[1],*(undefined4 *)((int)fVar5 + 200));

          uVar6 = 0x18;

          if (fVar15 <= (float10)0.0) {

            uVar6 = 0xe8;

          }

          *(undefined1 *)((int)fVar5 + 0x208) = uVar6;

        }

      }

      goto LAB_004d0e26;

    case 6:

      if (*pfVar12 <= 0.0) {

        local_44 = (float)crt_rand_scaled(100);

        if ((float)(int)local_44 <= *(float *)(DAT_00632ed8 + 0x98)) {

          fVar15 = (float10)FUN_0050a400((int)fVar5 + 0xa0,pfVar12 + 5);

          fVar2 = *(float *)(DAT_00632ed8 + 0x90) * 0.75;

          if (fVar2 * fVar2 <= param_1) {

            fVar15 = (float10)FUN_004d5780((float)(fVar15 - (float10)60.0),

                                           (float)((float10)60.0 + fVar15));

            pfVar12[1] = (float)fVar15;

            FUN_00451560(pfVar12 + 1);

          }

          else {

            fVar15 = (float10)FUN_004d5760(0x43b40000);

            pfVar12[1] = (float)fVar15;

          }

          fVar15 = (float10)FUN_004d5780(*(undefined4 *)(DAT_00632ed8 + 0xa0),

                                         *(undefined4 *)(DAT_00632ed8 + 0xa4));

          *pfVar12 = (float)fVar15;

          *(undefined4 *)((int)fVar5 + 0xe4) = 5;

        }

        else {

          fVar15 = (float10)FUN_004d5760(0x43b40000);

          pfVar12[1] = (float)fVar15;

          fVar15 = (float10)FUN_004d5780(*(undefined4 *)(DAT_00632ed8 + 0xa8),

                                         *(undefined4 *)(DAT_00632ed8 + 0xac));

          *pfVar12 = (float)fVar15;

          *(undefined4 *)((int)fVar5 + 0xe4) = 6;

        }

      }

      else {

        fVar15 = (float10)FUN_00518b70(fVar5,0);

        *pfVar12 = (float)((float10)*pfVar12 - fVar15);

        *(undefined1 *)((int)fVar5 + 0x20a) = 1;

        if (*(float *)((int)fVar5 + 200) != pfVar12[1]) {

          *(uint *)((int)fVar5 + 0xd8) = *(uint *)((int)fVar5 + 0xd8) | 0x1000000;

          *(float *)((int)fVar5 + 0x158) = pfVar12[1];

          FUN_0050a7c0(pfVar12[1],*(undefined4 *)((int)fVar5 + 200));

          uVar6 = __ftol();

          *(undefined1 *)((int)fVar5 + 0x208) = uVar6;

        }

      }

LAB_004d0e26:

      if (fVar3 != 0.0) {

        *(undefined4 *)((int)fVar5 + 0xe4) = 7;

      }

      break;

    case 7:

      iVar11 = *(int *)((int)fVar5 + 0x100);

      if (((((fVar3 == 0.0) || (*(int *)((int)fVar3 + 4) == 0)) ||

           ((*(uint *)((int)fVar3 + 0xd8) & 0x4000c000) != 0)) ||

          (*(float *)((int)fVar3 + 0x1c0) <= *(float *)((int)fVar3 + 0x278))) ||

         (((iVar10 = FUN_004a6160(fVar3), iVar10 != 0 &&

           ((*(uint *)((int)fVar3 + 0xe0) & 0x2000000) != 0)) && (*(float *)(iVar11 + 0x54) < 4.0)))

         ) goto LAB_004d10ab;

      iVar11 = FUN_004a6180(fVar3);

      if (iVar11 != 0) {

        uVar13 = *(uint *)((int)fVar5 + 0xe0);

        if ((*(byte *)((int)fVar3 + 0xe0) & 8) == 0) {

          *(uint *)((int)fVar5 + 0xe0) = uVar13 & 0xffffffef;

        }

        else if ((uVar13 & 0x10) == 0) {

          *(uint *)((int)fVar5 + 0xe0) = uVar13 | 0x10;

          goto LAB_004d10ab;

        }

      }

      local_44 = *(float *)(DAT_00632ed8 + 0xb0) * 0.25;

      fVar15 = (float10)FUN_0050a520((int)fVar5 + 0xa0,&local_40);

      param_1 = (float)fVar15;

      if ((float10)local_44 <= fVar15) {

        fVar15 = (float10)FUN_004d4580(fVar5,&local_40,0);

        *(float *)((int)fVar5 + 0x15c) = local_40;

        *(float *)((int)fVar5 + 0x160) = local_3c;

        *(uint *)((int)fVar5 + 0xd8) = *(uint *)((int)fVar5 + 0xd8) | 0x2000000;

        *(float *)((int)fVar5 + 0x164) = local_38;

        if ((float10)10.0 <= ABS(fVar15)) {

          *(undefined1 *)((int)fVar5 + 0x20a) = 3;

        }

        else {

          uVar6 = FUN_004a7cb0(param_1 * 0.1,0x3e4ccccd);

          *(undefined1 *)((int)fVar5 + 0x20a) = uVar6;

        }

      }

      if (*(float *)(DAT_00632ed8 + 0xb0) * *(float *)(DAT_00632ed8 + 0xb0) <= local_48) break;

      param_1 = (float)crt_rand_scaled(100);

      if (*(float *)(DAT_00632ed8 + 0x94) < (float)(int)param_1) {

        *(undefined4 *)((int)fVar5 + 0xe4) = 9;

        break;

      }

      goto LAB_004d135c;

    case 8:

      iVar11 = FUN_004d1790(fVar5,fVar3);

      if (iVar11 == 0) {

        param_1 = *(float *)(DAT_00632ed8 + 0xb0);

        sine_cos_lookup(pfVar12[1],&local_44,&local_48);

        local_34 = local_44 * param_1 + local_40;

        local_30 = local_3c - local_48 * param_1;

        FUN_004d4630(fVar5,&local_34,0);

        fVar15 = (float10)FUN_0050a400((int)fVar3 + 0xa0,(int)fVar5 + 0xa0);

        param_1 = (float)fVar15;

        fVar15 = (float10)FUN_0050a770(param_1,pfVar12[1]);

        if (fVar15 < (float10)10.0) {

          *(undefined4 *)((int)fVar5 + 0xe4) = 9;

        }

        break;

      }

      goto LAB_004d10ab;

    case 9:

      iVar11 = FUN_004d1790(fVar5,fVar3);

      if (iVar11 == 0) {

        fVar15 = (float10)FUN_0050a400((int)fVar5 + 0xa0,(undefined4 *)((int)fVar3 + 0xa0));

        param_1 = (float)fVar15;

        fVar15 = (float10)FUN_0050a7c0(param_1,*(undefined4 *)((int)fVar5 + 200));

        if (*(float *)((int)fVar5 + 200) != param_1) {

          *(uint *)((int)fVar5 + 0xd8) = *(uint *)((int)fVar5 + 0xd8) | 0x1000000;

          *(float *)((int)fVar5 + 0x158) = param_1;

          uVar6 = 0x20;

          if (fVar15 <= (float10)0.0) {

            uVar6 = 0xe0;

          }

          *(undefined1 *)((int)fVar5 + 0x208) = uVar6;

        }

        if (ABS(fVar15) < (float10)5.0) {

          *(undefined1 *)((int)fVar5 + 0x20a) = 0x20;

        }

        *(uint *)((int)fVar5 + 0x1c8) = *(uint *)((int)fVar5 + 0x1c8) | 0x400;

        *(undefined4 *)((int)fVar5 + 0x15c) = *(undefined4 *)((int)fVar3 + 0xa0);

        *(undefined4 *)((int)fVar5 + 0x160) = *(undefined4 *)((int)fVar3 + 0xa4);

        *(undefined4 *)((int)fVar5 + 0x164) = *(undefined4 *)((int)fVar3 + 0xa8);

        *(uint *)((int)fVar5 + 0xd8) = *(uint *)((int)fVar5 + 0xd8) | 0x2000000;

        if ((float)local_4c < *(float *)(DAT_00632ed8 + 0xb8) * *(float *)(DAT_00632ed8 + 0xb8)) {

          *(float *)((int)fVar5 + 0x210) = fVar3;

          *(undefined4 *)((int)fVar5 + 0x214) = 1;

          uVar9 = crt_rand_scaled(4);

          *(undefined4 *)((int)fVar5 + 0x218) = uVar9;

          *(undefined4 *)((int)fVar5 + 0xec) = *(undefined4 *)(DAT_00632ed8 + 0x9c);

          *(undefined4 *)((int)fVar5 + 0xe4) = 10;

          iVar11 = crt_rand_scaled(100);

          if (iVar11 < 0x32) {

            sound_play_obj(0x4f7,fVar5);

          }

          else {

            sound_play_obj(0x4f8,fVar5);

          }

        }

        break;

      }

LAB_004d10ab:

      *pfVar12 = 0.0;

      *(undefined4 *)((int)fVar5 + 0xe4) = 6;

      pfVar12[3] = 0.0;

      break;

    case 10:

      if (fVar3 == 0.0) {

        *(uint *)((int)fVar5 + 0x1c8) = *(uint *)((int)fVar5 + 0x1c8) & 0xfffffbff;

        *(undefined4 *)((int)fVar5 + 0xe4) = 0x50;

        break;

      }

      fVar15 = (float10)FUN_00518b70(fVar5,0);

      iVar11 = *(int *)((int)fVar5 + 0x210);

      *(float *)((int)fVar5 + 0xec) = (float)((float10)*(float *)((int)fVar5 + 0xec) - fVar15);

      if (iVar11 != 0) {

        if (*(float *)(DAT_00632ed8 + 0x3ec) <

            *(float *)(iVar11 + 0xa8) - *(float *)(iVar11 + 0x140)) {

          *(undefined4 *)((int)fVar5 + 0xec) = 0;

        }

        if (iVar11 != 0) {

          FUN_00456d00(iVar11,0,1,*(undefined4 *)(DAT_00632ed8 + 0x3f0),0,0);

        }

      }

      if (*(float *)((int)fVar5 + 0xec) < 0.0 == (*(float *)((int)fVar5 + 0xec) == 0.0)) break;

      *(undefined4 *)((int)fVar5 + 0x210) = 0;

      *(uint *)((int)fVar5 + 0x1c8) = *(uint *)((int)fVar5 + 0x1c8) & 0xfffffbff;

      pfVar12[3] = 0.0;

      iVar11 = crt_rand_scaled(100);

      if (iVar11 < 0x32) {

        uVar9 = 0x4f7;

      }

      else {

        uVar9 = 0x4f8;

      }

      sound_play_obj(uVar9,fVar5);

      param_1 = (float)crt_rand_scaled(100);

      if (*(float *)(DAT_00632ed8 + 0x94) < (float)(int)param_1) {

        *(undefined4 *)((int)fVar5 + 0xe4) = 9;

        fVar15 = (float10)FUN_004d5780(0xc1c80000,0x41c80000);

        *(float *)((int)fVar5 + 0x128) = (float)fVar15;

        fVar15 = (float10)FUN_004d5780(0xc1c80000,0x41c80000);

        *(float *)((int)fVar5 + 300) = (float)fVar15;

        *(undefined4 *)((int)fVar5 + 0x130) = 0x41a00000;

        break;

      }

LAB_004d135c:

      *(undefined4 *)((int)fVar5 + 0xe4) = 8;

      fVar15 = (float10)FUN_0050a400((int)fVar3 + 0xa0,(int)fVar5 + 0xa0);

      fVar15 = (float10)FUN_004d5780((float)(fVar15 + (float10)90.0),

                                     (float)((float10)270.0 + fVar15));

      pfVar12[1] = (float)fVar15;

      FUN_00451560(pfVar12 + 1);

      break;

    case 0xb:

      *pfVar12 = 0.0;

      *(uint *)((int)fVar5 + 0xe4) = (fVar3 != 0.0) + 6;

      break;

    case 0x50:

      *(undefined1 *)((int)fVar5 + 0x20a) = 0x18;

      *(undefined1 *)((int)fVar5 + 0x208) = 0;

      fVar15 = (float10)FUN_00518b70(fVar5,0);

      fVar2 = *pfVar12;

      *pfVar12 = (float)((float10)fVar2 - fVar15);

      if ((float10)fVar2 - fVar15 < (float10)0.0) {

        *(uint *)((int)fVar5 + 0xe4) = (fVar3 != 0.0) + 6;

      }

      break;

    case 0x5a:

      if (uVar13 != 0) {

        *(undefined4 *)((int)fVar5 + 0xe4) = 7;

        FUN_004d1a00(fVar5,*(undefined4 *)(DAT_00632ed8 + 0x140));

      }

      break;

    case 0x5b:

      *(undefined4 *)((int)fVar5 + 0x184) = 0;

      *(uint *)((int)fVar5 + 0x1c8) = *(uint *)((int)fVar5 + 0x1c8) & 0xfffff3bf;

      *(uint *)((int)fVar5 + 0xe0) = *(uint *)((int)fVar5 + 0xe0) & 0xfffffffd;

      if (uVar13 != 0) {

        *(undefined4 *)((int)fVar5 + 0xe4) = 0x5c;

        fVar15 = (float10)FUN_004d5780(*(undefined4 *)(DAT_00632ed8 + 0x134),

                                       *(undefined4 *)(DAT_00632ed8 + 0x138));

        *(float *)((int)fVar5 + 0xec) = (float)fVar15;

      }

      break;

    case 0x5c:

      fVar15 = (float10)FUN_00518b70(fVar5,0);

      fVar15 = (float10)*(float *)((int)fVar5 + 0xec) - fVar15;

      *(float *)((int)fVar5 + 0xec) = (float)fVar15;

      if (fVar15 < (float10)0.0) {

        *(undefined4 *)((int)fVar5 + 0xe4) = 0x5d;

      }

      break;

    case 0x5d:

      if (uVar13 != 0) {

        *(undefined4 *)((int)fVar5 + 0xe4) = 7;

        FUN_004d1a00(fVar5,*(undefined4 *)(DAT_00632ed8 + 0x140));

      }

      break;

    case 0x5e:

      FUN_004d1b30(fVar5);

    }

    if (*(int *)((int)fVar5 + 0x10) != 2) {

      return;

    }

    if ((*(float *)((int)fVar5 + 0x14) < 0.6333333) || (0.6333333 <= *(float *)((int)fVar5 + 0x18)))

    {

      if (*(float *)((int)fVar5 + 0x14) < 1.9666667) {

        return;

      }

      if (1.9666667 <= *(float *)((int)fVar5 + 0x18)) {

        return;

      }

    }

    sound_play_obj(0x4fe,fVar5);

    return;

  }

  pfVar12 = *(float **)((int)fVar5 + 0x100);

  local_44 = *(float *)((int)fVar5 + 0x10);

  uVar13 = *(uint *)((int)fVar5 + 0x30) & 2;

  if ((pfVar12[3] != 0.0) && ((char)((uint)*(undefined4 *)((int)pfVar12[3] + 0xd8) >> 8) < '\0')) {

    pfVar12[3] = 0.0;

  }

  local_4c = pfVar12;

  if (pfVar12[3] == 0.0) {

    FUN_004d1a00(fVar5,*(undefined4 *)(DAT_00632ed8 + 0xfc));

  }

  fVar3 = pfVar12[3];

  if (fVar3 == 0.0) {

    param_1 = 9.99998e+11;

    local_48 = 9.99998e+11;

    local_38 = 99999.0;

    local_3c = 99999.0;

    local_40 = 99999.0;

  }

  else {

    local_40 = *(float *)((int)fVar3 + 0xa0);

    local_3c = *(float *)((int)fVar3 + 0xa4);

    local_38 = *(float *)((int)fVar3 + 0xa8);

    fVar15 = (float10)FUN_0050a5e0(&local_40,(int)fVar5 + 0xa0);

    param_1 = (float)fVar15;

    fVar15 = (float10)FUN_0050a610(&local_40,(int)fVar5 + 0xa0);

    local_48 = (float)fVar15;

    local_38 = *(float *)((int)fVar3 + 0x1e8) * *(float *)((int)fVar3 + 0xc4) + local_38;

    pfVar12 = local_4c;

  }

  switch(*(undefined4 *)((int)fVar5 + 0xe4)) {

  case 0x3d:

    FUN_0040d6b0(local_28);

    param_1 = *(float *)(DAT_00632ed8 + 0x144);

    fVar15 = (float10)FUN_0050a610(local_28,(int)fVar5 + 0xa0);

    if (fVar15 <= (float10)param_1 * (float10)param_1) {

      *(undefined4 *)((int)fVar5 + 0x184) = 0;

    }

    else {

      *(undefined4 *)((int)fVar5 + 0x184) = 0x3f800000;

    }

    fVar15 = (float10)FUN_00518b70(fVar5,0);

    fVar2 = *pfVar12;

    *pfVar12 = (float)((float10)fVar2 - fVar15);

    if (((float10)fVar2 - fVar15 < (float10)0.0) && (fVar3 != 0.0)) {

      sound_play_obj(0x4de,fVar5);

      *(undefined4 *)((int)fVar5 + 0xe4) = 0x3e;

      *(undefined4 *)((int)fVar5 + 0x184) = 0;

      *(uint *)((int)fVar5 + 0x1c8) = *(uint *)((int)fVar5 + 0x1c8) & 0xfffff7ff;

      ANM_DumpCluster((int)fVar5 + 0xa0);

      iVar11 = object_allocate_type(0xdb,0x11);

      FUN_004979b0(iVar11,fVar5);

      *(undefined4 *)(iVar11 + 0xc4) = *(undefined4 *)((int)fVar5 + 0xc4);

      *(undefined4 *)(iVar11 + 0xe4) = 0;

      *(int *)((int)fVar5 + 0x274) = iVar11;

      *(float *)(iVar11 + 0x274) = fVar5;

      FUN_00495750(0x4d3,fVar5);

    }

    break;

  case 0x3e:

    *(undefined1 *)((int)fVar5 + 0x208) = 0;

    fVar15 = (float10)FUN_0050a400((int)fVar5 + 0xa0,&local_40);

    param_1 = (float)fVar15;

    fVar15 = (float10)FUN_0050a7c0(param_1,*(undefined4 *)((int)fVar5 + 200));

    if (ABS(fVar15) != (float10)0.0) {

      uVar6 = FUN_004a7cb0((float)(fVar15 * (float10)0.05),0x3e800000);

      *(undefined1 *)((int)fVar5 + 0x208) = uVar6;

      *(float *)((int)fVar5 + 0x158) = param_1;

      *(uint *)((int)fVar5 + 0xd8) = *(uint *)((int)fVar5 + 0xd8) | 0x1000000;

    }

    *(uint *)((int)fVar5 + 0x1c8) = *(uint *)((int)fVar5 + 0x1c8) & 0xffffffbf;

    if (uVar13 != 0) {

      *(undefined4 *)((int)fVar5 + 0xe4) = 0x3f;

    }

    break;

  case 0x3f:

    iVar11 = *(int *)((int)fVar5 + 0x100);

    if ((((fVar3 != 0.0) && (*(int *)((int)fVar3 + 4) != 0)) &&

        (((*(uint *)((int)fVar3 + 0xd8) & 0x4000c000) == 0 &&

         (*(float *)((int)fVar3 + 0x278) < *(float *)((int)fVar3 + 0x1c0))))) &&

       (((iVar10 = FUN_004a6160(fVar3), iVar10 == 0 ||

         ((*(uint *)((int)fVar3 + 0xe0) & 0x2000000) == 0)) || (4.0 <= *(float *)(iVar11 + 0x54)))))

    {

      iVar11 = FUN_004a6180(fVar3);

      if (iVar11 != 0) {

        uVar13 = *(uint *)((int)fVar5 + 0xe0);

        if ((*(byte *)((int)fVar3 + 0xe0) & 8) == 0) {

          *(uint *)((int)fVar5 + 0xe0) = uVar13 & 0xffffffef;

        }

        else if ((uVar13 & 0x10) == 0) {

          *(uint *)((int)fVar5 + 0xe0) = uVar13 | 0x10;

          goto LAB_004d0695;

        }

      }

      if (*(float *)(DAT_00632ed8 + 0x3d8) * *(float *)(DAT_00632ed8 + 0x3d8) <= param_1) {

        if (*(float *)(DAT_00632ed8 + 0x100) * *(float *)(DAT_00632ed8 + 0x100) <= param_1) {

          *(undefined4 *)((int)fVar5 + 0xe4) = 0x40;

        }

        else {

          *(undefined4 *)((int)fVar5 + 0xe4) = 0x41;

        }

      }

      else {

        *(undefined4 *)((int)fVar5 + 0xe4) = 0x43;

      }

      break;

    }

    goto LAB_004d0695;

  case 0x40:

    iVar11 = *(int *)((int)fVar5 + 0x100);

    if (((((fVar3 != 0.0) && (*(int *)((int)fVar3 + 4) != 0)) &&

         ((*(uint *)((int)fVar3 + 0xd8) & 0x4000c000) == 0)) &&

        (*(float *)((int)fVar3 + 0x278) < *(float *)((int)fVar3 + 0x1c0))) &&

       (((iVar10 = FUN_004a6160(fVar3), iVar10 == 0 ||

         ((*(uint *)((int)fVar3 + 0xe0) & 0x2000000) == 0)) || (4.0 <= *(float *)(iVar11 + 0x54)))))

    {

      iVar11 = FUN_004a6180(fVar3);

      if (iVar11 != 0) {

        uVar13 = *(uint *)((int)fVar5 + 0xe0);

        if ((*(byte *)((int)fVar3 + 0xe0) & 8) == 0) {

          *(uint *)((int)fVar5 + 0xe0) = uVar13 & 0xffffffef;

        }

        else if ((uVar13 & 0x10) == 0) {

          *(uint *)((int)fVar5 + 0xe0) = uVar13 | 0x10;

          goto LAB_004d0695;

        }

      }

      local_34 = *(float *)((int)fVar3 + 0xa0);

      local_30 = *(float *)((int)fVar3 + 0xa4);

      local_2c = *(undefined4 *)((int)fVar3 + 0xa8);

      fVar15 = (float10)FUN_0050a520((int)fVar5 + 0xa0,&local_34);

      local_48 = (float)fVar15;

      if ((float10)0.0 <= fVar15) {

        fVar15 = (float10)FUN_004d4580(fVar5,&local_34,0);

        *(float *)((int)fVar5 + 0x15c) = local_34;

        *(float *)((int)fVar5 + 0x160) = local_30;

        *(undefined4 *)((int)fVar5 + 0x164) = local_2c;

        *(uint *)((int)fVar5 + 0xd8) = *(uint *)((int)fVar5 + 0xd8) | 0x2000000;

        if ((float10)10.0 <= ABS(fVar15)) {

          *(undefined1 *)((int)fVar5 + 0x20a) = 3;

        }

        else {

          uVar6 = FUN_004a7cb0(local_48 * 0.1,0x3e4ccccd);

          *(undefined1 *)((int)fVar5 + 0x20a) = uVar6;

        }

      }

      if (param_1 < *(float *)(DAT_00632ed8 + 0x100) * *(float *)(DAT_00632ed8 + 0x100)) {

        *(undefined4 *)((int)fVar5 + 0xe4) = 0x41;

      }

      break;

    }

    goto LAB_004d0695;

  case 0x41:

    local_48 = *(float *)((int)fVar5 + 0x100);

    if (((fVar3 != 0.0) && (*(int *)((int)fVar3 + 4) != 0)) &&

       ((((*(uint *)((int)fVar3 + 0xd8) & 0x4000c000) == 0 &&

         (*(float *)((int)fVar3 + 0x278) < *(float *)((int)fVar3 + 0x1c0))) &&

        (((iVar11 = FUN_004a6160(fVar3), iVar11 == 0 ||

          ((*(uint *)((int)fVar3 + 0xe0) & 0x2000000) == 0)) ||

         (4.0 <= *(float *)((int)local_48 + 0x54))))))) {

      iVar11 = FUN_004a6180(fVar3);

      if (iVar11 != 0) {

        uVar4 = *(uint *)((int)fVar5 + 0xe0);

        if ((*(byte *)((int)fVar3 + 0xe0) & 8) == 0) {

          *(uint *)((int)fVar5 + 0xe0) = uVar4 & 0xffffffef;

        }

        else if ((uVar4 & 0x10) == 0) {

          *(uint *)((int)fVar5 + 0xe0) = uVar4 | 0x10;

          goto LAB_004d0695;

        }

      }

      *(undefined1 *)((int)fVar5 + 0x208) = 0;

      if ((int)fVar3 + 0xa0 == 0) {

        local_4c = (float *)0x0;

      }

      else {

        fVar15 = (float10)FUN_0050a400((int)fVar5 + 0xa0,(int)fVar3 + 0xa0);

        local_4c = (float *)(float)fVar15;

      }

      fVar15 = (float10)FUN_0050a7c0(local_4c,*(undefined4 *)((int)fVar5 + 200));

      if (ABS(fVar15) != (float10)0.0) {

        uVar6 = FUN_004a7cb0((float)(fVar15 * (float10)0.05),0x3e800000);

        *(undefined1 *)((int)fVar5 + 0x208) = uVar6;

        *(float **)((int)fVar5 + 0x158) = local_4c;

        *(uint *)((int)fVar5 + 0xd8) = *(uint *)((int)fVar5 + 0xd8) | 0x1000000;

      }

      if (uVar13 == 0) {

        if ((*(float *)((int)fVar5 + 0x18) < 0.43333334) &&

           (0.43333334 <= *(float *)((int)fVar5 + 0x14))) {

          FUN_004d4350(fVar5,&local_40,*(undefined4 *)(DAT_00632ed8 + 0x11c));

        }

      }

      else if (*(float *)(DAT_00632ed8 + 0x3d8) * *(float *)(DAT_00632ed8 + 0x3d8) <= param_1) {

        if ((*(float *)(DAT_00632ed8 + 0x104) * *(float *)(DAT_00632ed8 + 0x104) <= param_1) ||

           (param_1 = (float)crt_rand_scaled(100),

           *(float *)(DAT_00632ed8 + 0x108) <= (float)(int)param_1)) {

          *pfVar12 = *(float *)(DAT_00632ed8 + 0x10c);

          *(undefined4 *)((int)fVar5 + 0xe4) = 0x42;

        }

        else {

          *(undefined4 *)((int)fVar5 + 0xe4) = 0x43;

        }

      }

      else {

        *(undefined4 *)((int)fVar5 + 0xe4) = 0x43;

      }

      break;

    }

    goto LAB_004d0695;

  case 0x42:

    fVar15 = (float10)FUN_00518b70(fVar5,0);

    fVar3 = *pfVar12;

    *pfVar12 = (float)((float10)fVar3 - fVar15);

    if ((float10)fVar3 - fVar15 < (float10)0.0) {

      if (*(float *)(DAT_00632ed8 + 0x3d8) * *(float *)(DAT_00632ed8 + 0x3d8) <= param_1) {

        sound_play_obj(0x4e0,fVar5);

        *(undefined4 *)((int)fVar5 + 0xe4) = 0x47;

        fVar15 = (float10)FUN_004d5780(*(undefined4 *)(DAT_00632ed8 + 0x110),

                                       *(undefined4 *)(DAT_00632ed8 + 0x114));

        *pfVar12 = (float)fVar15;

      }

      else {

        *(undefined4 *)((int)fVar5 + 0xe4) = 0x43;

      }

    }

    break;

  case 0x43:

    iVar11 = *(int *)((int)fVar5 + 0x100);

    if ((((fVar3 != 0.0) && (*(int *)((int)fVar3 + 4) != 0)) &&

        ((*(uint *)((int)fVar3 + 0xd8) & 0x4000c000) == 0)) &&

       ((*(float *)((int)fVar3 + 0x278) < *(float *)((int)fVar3 + 0x1c0) &&

        (((iVar10 = FUN_004a6160(fVar3), iVar10 == 0 ||

          ((*(uint *)((int)fVar3 + 0xe0) & 0x2000000) == 0)) || (4.0 <= *(float *)(iVar11 + 0x54))))

        ))) {

      iVar11 = FUN_004a6180(fVar3);

      if (iVar11 != 0) {

        uVar13 = *(uint *)((int)fVar5 + 0xe0);

        if ((*(byte *)((int)fVar3 + 0xe0) & 8) == 0) {

          *(uint *)((int)fVar5 + 0xe0) = uVar13 & 0xffffffef;

        }

        else if ((uVar13 & 0x10) == 0) {

          *(uint *)((int)fVar5 + 0xe0) = uVar13 | 0x10;

          goto LAB_004d0695;

        }

      }

      puVar14 = (undefined4 *)((int)fVar3 + 0xa0);

      *(undefined1 *)((int)fVar5 + 0x208) = 0;

      if (puVar14 == (undefined4 *)0x0) {

        local_4c = (float *)0x0;

      }

      else {

        fVar15 = (float10)FUN_0050a400((int)fVar5 + 0xa0,puVar14);

        local_4c = (float *)(float)fVar15;

      }

      fVar15 = (float10)FUN_0050a7c0(local_4c,*(undefined4 *)((int)fVar5 + 200));

      local_48 = (float)fVar15;

      if (ABS(fVar15) == (float10)0.0) {

        fVar2 = 0.0;

      }

      else {

        uVar6 = FUN_004a7cb0(local_48 * 0.05,0x3e800000);

        *(undefined1 *)((int)fVar5 + 0x208) = uVar6;

        *(float **)((int)fVar5 + 0x158) = local_4c;

        *(uint *)((int)fVar5 + 0xd8) = *(uint *)((int)fVar5 + 0xd8) | 0x1000000;

        fVar2 = local_48;

      }

      if (ABS(fVar2) < 5.0) {

        *(undefined1 *)((int)fVar5 + 0x20a) = 0x20;

      }

      *(undefined4 *)((int)fVar5 + 0x15c) = *puVar14;

      *(undefined4 *)((int)fVar5 + 0x160) = *(undefined4 *)((int)fVar3 + 0xa4);

      uVar9 = *(undefined4 *)((int)fVar3 + 0xa8);

      *(uint *)((int)fVar5 + 0xd8) = *(uint *)((int)fVar5 + 0xd8) | 0x2000000;

      *(undefined4 *)((int)fVar5 + 0x164) = uVar9;

      if (param_1 < *(float *)(DAT_00632ed8 + 0x118) * *(float *)(DAT_00632ed8 + 0x118)) {

        param_1 = (float)crt_rand_scaled(100);

        if (*(float *)(DAT_00632ed8 + 0x128) <= (float)(int)param_1) {

          sound_play_obj(0x4cf,fVar5);

          *(undefined4 *)((int)fVar5 + 0xe4) = 0x44;

        }

        else {

          *(undefined4 *)((int)fVar5 + 0xe4) = 0x45;

        }

      }

      break;

    }

    goto LAB_004d0695;

  case 0x44:

    iVar11 = FUN_004d1790(fVar5,fVar3);

    if (iVar11 == 0) {

      FUN_004d4580(fVar5,(int)fVar3 + 0xa0,0);

      if ((uVar13 != 0) &&

         (*(undefined4 *)((int)fVar5 + 0xe4) = 0x42,

         local_48 < *(float *)(DAT_00632ed8 + 0x118) * *(float *)(DAT_00632ed8 + 0x118))) {

        FUN_00456f80(2,*(undefined4 *)(DAT_00632ed8 + 0x3dc),fVar3,fVar5,0,0);

      }

      break;

    }

    goto LAB_004d0695;

  case 0x45:

    iVar11 = FUN_004d1790(fVar5,fVar3);

    if (iVar11 == 0) {

      FUN_004d4580(fVar5,(int)fVar3 + 0xa0,0);

      if ((local_44 == 7.14662e-44) && (0.6666667 <= *(float *)((int)fVar5 + 0x14))) {

        iVar11 = FUN_004d4760(fVar5,0,0x41000000);

        if ((iVar11 == 0) || (*(int *)(iVar11 + 4) == 1)) {

          if (1.2333333 <= *(float *)((int)fVar5 + 0x14)) {

            *(undefined4 *)((int)fVar5 + 0xe4) = 0x42;

          }

        }

        else {

          sound_play_3dpos(0x4cf,(int)fVar5 + 0xa0);

          *(undefined4 *)((int)fVar5 + 0xe4) = 0x46;

          *(float *)(iVar11 + 0x210) = fVar5;

          *(undefined4 *)(iVar11 + 0x214) = 4;

          *(undefined4 *)(iVar11 + 0x218) = 0;

        }

      }

      break;

    }

LAB_004d0695:

    sound_play_obj(0x4e0,fVar5);

    *(undefined4 *)((int)fVar5 + 0xe4) = 0x47;

    pfVar12[3] = 0.0;

    break;

  case 0x46:

    if ((3.4333334 <= *(float *)((int)fVar5 + 0x14)) && (iVar11 = FUN_004d4930(fVar5), iVar11 != 0))

    {

      *(undefined4 *)(iVar11 + 0x210) = 0;

      sine_cos_lookup(*(undefined4 *)((int)fVar5 + 200),&param_1,&local_44);

      *(float *)(iVar11 + 0x128) =

           *(float *)(DAT_00632ed8 + 300) * param_1 * *(float *)((int)fVar5 + 0xc4);

      *(float *)(iVar11 + 300) =

           -(*(float *)(DAT_00632ed8 + 300) * local_44 * *(float *)((int)fVar5 + 0xc4));

      *(float *)(iVar11 + 0x130) = *(float *)(DAT_00632ed8 + 0x130) * *(float *)((int)fVar5 + 0xc4);

      FUN_00456f80(2,*(undefined4 *)(DAT_00632ed8 + 1000),iVar11,fVar5,0,0);

    }

    if (uVar13 != 0) {

      *(undefined4 *)((int)fVar5 + 0xe4) = 0x42;

    }

    break;

  case 0x47:

    if (0.73333335 < *(float *)((int)fVar5 + 0x14)) {

      iVar11 = *(int *)((int)fVar5 + 0x274);

      *(uint *)((int)fVar5 + 0x1c8) = *(uint *)((int)fVar5 + 0x1c8) | 0x40;

      if ((iVar11 != 0) && (*(int *)(iVar11 + 4) == 0xdb)) {

        *(undefined4 *)(iVar11 + 0xe4) = 2;

      }

    }

    if (uVar13 != 0) {

      ANM_DumpCluster((int)fVar5 + 0xa0);

      sound_play_obj(0x4d3,fVar5);

      *(undefined4 *)((int)fVar5 + 0xe4) = 0x3d;

      *(uint *)((int)fVar5 + 0x1c8) = *(uint *)((int)fVar5 + 0x1c8) | 0x840;

    }

    break;

  case 0x50:

    *(undefined1 *)((int)fVar5 + 0x20a) = 0x18;

    *(undefined1 *)((int)fVar5 + 0x208) = 0;

    fVar15 = (float10)FUN_00518b70(fVar5,0);

    fVar3 = *pfVar12;

    *pfVar12 = (float)((float10)fVar3 - fVar15);

    if ((float10)fVar3 - fVar15 < (float10)0.0) {

      FUN_004d1a00(fVar5,*(undefined4 *)(DAT_00632ed8 + 0x140));

      if (pfVar12[3] == 0.0) {

        sound_play_obj(0x4e0,fVar5);

        *(undefined4 *)((int)fVar5 + 0xe4) = 0x47;

      }

      else {

        *(undefined4 *)((int)fVar5 + 0xe4) = 0x3f;

      }

    }

    break;

  case 0x5a:

    if (uVar13 != 0) {

      *(undefined4 *)((int)fVar5 + 0xe4) = 0x3f;

      FUN_004d1a00(fVar5,*(undefined4 *)(DAT_00632ed8 + 0x140));

    }

    break;

  case 0x5b:

    *(undefined4 *)((int)fVar5 + 0x184) = 0;

    *(uint *)((int)fVar5 + 0x1c8) = *(uint *)((int)fVar5 + 0x1c8) & 0xfffff3bf;

    *(uint *)((int)fVar5 + 0xe0) = *(uint *)((int)fVar5 + 0xe0) & 0xfffffffd;

    if (uVar13 != 0) {

      *(undefined4 *)((int)fVar5 + 0xe4) = 0x5c;

      fVar15 = (float10)FUN_004d5780(*(undefined4 *)(DAT_00632ed8 + 0x134),

                                     *(undefined4 *)(DAT_00632ed8 + 0x138));

      *(float *)((int)fVar5 + 0xec) = (float)fVar15;

    }

    break;

  case 0x5c:

    fVar15 = (float10)FUN_00518b70(fVar5,0);

    fVar15 = (float10)*(float *)((int)fVar5 + 0xec) - fVar15;

    *(float *)((int)fVar5 + 0xec) = (float)fVar15;

    if (fVar15 < (float10)0.0) {

      *(undefined4 *)((int)fVar5 + 0xe4) = 0x5d;

    }

    break;

  case 0x5d:

    if (uVar13 != 0) {

      *(undefined4 *)((int)fVar5 + 0xe4) = 0x3f;

      FUN_004d1a00(fVar5,*(undefined4 *)(DAT_00632ed8 + 0x140));

    }

    break;

  case 0x5e:

    FUN_004d1b30(fVar5);

  }

  if (*(int *)((int)fVar5 + 0x10) != 2) {

    return;

  }

  if ((*(float *)((int)fVar5 + 0x14) < 0.6333333) || (0.6333333 <= *(float *)((int)fVar5 + 0x18))) {

    if (*(float *)((int)fVar5 + 0x14) < 1.9666667) {

      return;

    }

    if (1.9666667 <= *(float *)((int)fVar5 + 0x18)) {

      return;

    }

  }

  sound_play_obj(0x4d6,fVar5);

  return;

}

