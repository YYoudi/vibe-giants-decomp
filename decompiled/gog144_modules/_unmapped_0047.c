/* Giants 1.449 — module _unmapped_0047
 * 75 functions (70 named) — decompiled, names from PS2 symbols
 * Original source: C:\Giants\source\_unmapped_0047.c(pp) (assert-string evidence)
 */

/* ===== object_destroy_all__7PS2Game @ 0x00470220 ===== */
/* PS2 candidate: object_destroy_all__7PS2Game (conf 0.642) */



void object_destroy_all__7PS2Game(undefined4 param_1)



{

  undefined4 *puVar1;

  

  for (puVar1 = DAT_00632d68; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {

    if (*(int *)(puVar1[3] + 0x1e0) == 0x5c) {

      obj_ai_recognize(puVar1[3],param_1);

    }

  }

  return;

}

/* ===== main/linkage_00470480 @ 0x00470480 ===== */
void main_linkage_00470480(undefined4 *param_1)



{

  int *piVar1;

  int *piVar2;

  int *piVar3;

  

  piVar2 = (int *)*param_1;

  while (piVar3 = piVar2, piVar3 != (int *)0x0) {

    piVar1 = (int *)piVar3[3];

    piVar2 = (int *)*piVar3;

    *(int *)piVar1[1] = *piVar1;

    if (*piVar1 != 0) {

      *(int *)(*piVar1 + 4) = piVar1[1];

    }

    *piVar1 = (int)DAT_0059da7c;

    DAT_0059da7c = piVar1;

    *(int *)piVar3[1] = *piVar3;

    if (*piVar3 != 0) {

      *(int *)(*piVar3 + 4) = piVar3[1];

    }

    *piVar3 = (int)DAT_0059da7c;

    DAT_0059da7c = piVar3;

  }

  return;

}

/* ===== main/linkage_004704e0 @ 0x004704E0 ===== */
void main_linkage_004704e0(int *param_1,int *param_2)



{

  int *piVar1;

  

  param_2 = (int *)*param_2;

  if (param_2 != (int *)0x0) {

    while (param_2[3] != *param_1) {

      param_2 = (int *)*param_2;

      if (param_2 == (int *)0x0) {

        return;

      }

    }

    piVar1 = (int *)param_2[3];

    *(int *)piVar1[1] = *piVar1;

    if (*piVar1 != 0) {

      *(int *)(*piVar1 + 4) = piVar1[1];

    }

    *piVar1 = (int)DAT_0059da7c;

    DAT_0059da7c = piVar1;

    *(int *)param_2[1] = *param_2;

    if (*param_2 != 0) {

      *(int *)(*param_2 + 4) = param_2[1];

    }

    *param_2 = (int)DAT_0059da7c;

    DAT_0059da7c = param_2;

  }

  return;

}

/* ===== main/linkage_004705c0 @ 0x004705C0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* PS2 candidate: ANM_DumpCluster_10 (conf 0.777) */



void main_linkage_004705c0(void)



{

  DAT_00632d68 = 0;

  DAT_00632d6c = 0;

  DAT_00632d70 = 0;

  DAT_00632d74 = 0;

  DAT_00632d78 = 0;

  DAT_00632d7c = 0;

  DAT_00632d80 = 0;

  DAT_00632d84 = 0;

  _DAT_00632d88 = 0;

  DAT_00632d8c = 0;

  DAT_00632d90 = 0;

  DAT_00632d94 = 0;

  DAT_00632d98 = 0;

  DAT_00632d9c = 0;

  DAT_00632da0 = 0;

  return;

}

/* ===== map_entry_lookup @ 0x00470670 ===== */
undefined4 map_entry_lookup(int param_1,int *param_2)



{

  int iVar1;

  int local_c [3];

  

  local_c[0] = *param_2;

  if (local_c[0] != 0) {

    iVar1 = MAP_MappingFind(*(undefined4 *)(param_1 + 0xc),local_c,0);

    if ((iVar1 != 0) && (iVar1 = (uint)*(ushort *)(iVar1 + 2) + iVar1, iVar1 != 0)) {

      *param_2 = *(int *)(iVar1 + 4);

      return 1;

    }

    *param_2 = 0;

  }

  return 0;

}

/* ===== FUN_004706d0 @ 0x004706D0 ===== */
int FUN_004706d0(int param_1,int *param_2)



{

  int *piVar1;

  

  if (*(int *)(param_1 + 8) < 0) {

    if (*param_2 != 0) {

      piVar1 = (int *)(*(int *)(*(int *)(param_1 + 4) + 8) + -0x308 + *param_2 * 0x308);

      *param_2 = *piVar1;

      return *piVar1;

    }

  }

  return 0;

}

/* ===== object_lock_logic @ 0x00470710 ===== */
/* PS2 candidate: object_lock_logic (conf 0.6110000000000001) */



void object_lock_logic(int param_1)



{

  float fVar1;

  int iVar2;

  int iVar3;

  undefined4 *puVar4;

  undefined4 *puVar5;

  float local_1d0;

  undefined4 local_1cc [4];

  undefined4 uStack_1bc;

  undefined4 uStack_1ac;

  undefined4 uStack_19c;

  undefined1 local_188 [68];

  undefined1 auStack_144 [16];

  undefined4 uStack_134;

  undefined4 uStack_124;

  undefined4 uStack_114;

  undefined1 local_100 [256];

  

  iVar3 = *(int *)(param_1 + 0x210);

  if (iVar3 != 0) {

    if ((*(uint *)(param_1 + 0xd8) & 0x20000000) != 0) {

      *(undefined4 *)(param_1 + 0x184) = *(undefined4 *)(iVar3 + 0x184);

    }

    iVar2 = *(int *)(param_1 + 0x218);

    if (((char)iVar2 < '\0') || (*(int *)(iVar3 + 0x2dc) == 0)) {

      puVar4 = (undefined4 *)(iVar3 + 0x294);

      puVar5 = local_1cc;

      for (iVar2 = 0x11; iVar2 != 0; iVar2 = iVar2 + -1) {

        *puVar5 = *puVar4;

        puVar4 = puVar4 + 1;

        puVar5 = puVar5 + 1;

      }

    }

    else {

      if (*(int *)(iVar3 + 0x2d8) <= iVar2) {

        crt_sprintf(local_100,s_Lock_error_d_Object__d__LObject___0055b5b0,1,

                    *(undefined4 *)(param_1 + 4),*(undefined4 *)(iVar3 + 4),

                    *(undefined4 *)(param_1 + 0x214),iVar2);

        goto LAB_00470793;

      }

      (*(code *)PTR_crt_matrix_mul_00580c18)

                (local_1cc,iVar3 + 0x294,iVar2 * 0x44 + *(int *)(iVar3 + 0x2dc));

    }

    local_1d0 = *(float *)(param_1 + 0xc4);

    if ((*(uint *)(param_1 + 0xdc) & 0x2000000) == 0) {

      local_1d0 = local_1d0 / *(float *)(iVar3 + 0xc4);

    }

    GEO_MatIdentityScale(local_188,local_1d0);

    (*(code *)PTR_crt_matrix_mul_00580c18)(local_1cc,local_1cc,local_188);

    if ((char)((uint)*(undefined4 *)(param_1 + 0xdc) >> 8) < '\0') {

      ObjectCalculateTransform(param_1);

      iVar2 = *(int *)(param_1 + 0x214);

      if ((char)iVar2 < '\0') {

        *(undefined4 *)(param_1 + 0x2a4) = uStack_1bc;

        *(undefined4 *)(param_1 + 0x2b4) = uStack_1ac;

        *(undefined4 *)(param_1 + 0x2c4) = uStack_19c;

      }

      else {

        if (*(int *)(param_1 + 0x2d8) <= iVar2) {

          crt_sprintf(local_100,s_Lock_error_d_Object__d__LObject___0055b5b0,2,

                      *(undefined4 *)(param_1 + 4),*(undefined4 *)(iVar3 + 4),iVar2,

                      *(undefined4 *)(param_1 + 0x218));

          FUN_0051ea20(local_100);

          *(undefined4 *)(param_1 + 0x210) = 0;

          return;

        }

        (*(code *)PTR_crt_matrix_copy_init_00580c1c)

                  (local_188,iVar2 * 0x44 + *(int *)(param_1 + 0x2dc));

        (*(code *)PTR_crt_matrix_mul_00580c18)(auStack_144,local_1cc,local_188);

        *(undefined4 *)(param_1 + 0x2a4) = uStack_134;

        *(undefined4 *)(param_1 + 0x2b4) = uStack_124;

        *(undefined4 *)(param_1 + 0x2c4) = uStack_114;

      }

    }

    else {

      iVar2 = *(int *)(param_1 + 0x214);

      if ((char)iVar2 < '\0') {

        puVar4 = local_1cc;

        puVar5 = (undefined4 *)(param_1 + 0x294);

        for (iVar3 = 0x11; iVar3 != 0; iVar3 = iVar3 + -1) {

          *puVar5 = *puVar4;

          puVar4 = puVar4 + 1;

          puVar5 = puVar5 + 1;

        }

      }

      else {

        if (*(int *)(param_1 + 0x2d8) <= iVar2) {

          crt_sprintf(local_100,s_Lock_error_d_Object__d__LObject___0055b5b0,3,

                      *(undefined4 *)(param_1 + 4),*(undefined4 *)(iVar3 + 4),iVar2,

                      *(undefined4 *)(param_1 + 0x218));

LAB_00470793:

          FUN_0051ea20(local_100);

          *(undefined4 *)(param_1 + 0x210) = 0;

          return;

        }

        (*(code *)PTR_crt_matrix_copy_init_00580c1c)

                  (local_188,iVar2 * 0x44 + *(int *)(param_1 + 0x2dc));

        (*(code *)PTR_crt_matrix_mul_00580c18)(param_1 + 0x294,local_1cc,local_188);

      }

    }

    if ((*(uint *)(param_1 + 0xdc) & 0x1000) != 0) {

      *(undefined4 *)(param_1 + 0x210) = 0;

      *(uint *)(param_1 + 0xdc) = *(uint *)(param_1 + 0xdc) & 0xffffefff;

    }

    fVar1 = *(float *)(param_1 + 0x1d4) + *(float *)(param_1 + 0x2c4);

    *(float *)(param_1 + 0x2c4) = fVar1;

    object_set_location(param_1,*(undefined4 *)(param_1 + 0x2a4),*(undefined4 *)(param_1 + 0x2b4),

                        fVar1);

  }

  return;

}

/* ===== cspec_00470a10 @ 0x00470A10 ===== */
void cspec_00470a10(float param_1)



{

  float fVar1;

  float fVar2;

  int iVar3;

  int iVar4;

  undefined4 uVar5;

  int iVar6;

  float10 fVar7;

  float10 fVar8;

  float fStack_3c;

  float fStack_38;

  float fStack_34;

  float fStack_30;

  float fStack_2c;

  undefined1 auStack_28 [4];

  float fStack_24;

  float fStack_20;

  float fStack_1c;

  float fStack_18;

  float fStack_14;

  float fStack_10;

  undefined1 auStack_c [12];

  

  iVar3 = (int)param_1;

  if (DAT_00632e74 == 0) {

    if (*(int *)((int)param_1 + 0xe4) == 0) {

      if (*(int *)((int)param_1 + 4) == 0x2b1) {

        iVar4 = object_spawn_small(param_1,0x2b0,1,0,0);

        *(int *)(iVar3 + 0x274) = iVar4;

        *(undefined4 *)(iVar3 + 0xe4) = 0x14;

        *(uint *)(iVar4 + 0xdc) = *(uint *)(iVar4 + 0xdc) | 0x8000;

        uVar5 = object_spawn_small(iVar4,0x2ab,0,0,0);

        *(undefined4 *)(iVar4 + 0x274) = uVar5;

        ObjectSetAnim(iVar4,1,0x24,0,0,0);

        iVar4 = 0;

        if (0 < *(int *)(iVar3 + 0xe8)) {

          do {

            iVar4 = iVar4 + 1;

            iVar6 = object_spawn_small(uVar5,0xd7,2,iVar4,0);

            *(undefined4 *)(iVar6 + 0xe8) = 8;

            object_spawn_small(iVar6,0x2b2,0,7,0);

          } while (iVar4 < *(int *)(iVar3 + 0xe8));

        }

      }

      else {

        *(undefined4 *)((int)param_1 + 0xe4) = 10;

      }

    }

    if (*(int *)(iVar3 + 0xe4) == 0xb) {

      iVar6 = *(int *)(iVar3 + 0x274);

      iVar4 = iVar6 + 0xa0;

      fVar7 = (float10)dirfcalcp3d__FP3P3DT0(iVar4,iVar3 + 0x178);

      fStack_3c = (float)fVar7;

      fVar7 = (float10)distance2d__FP3P3DT0(iVar4,iVar3 + 0x178);

      fVar7 = (float10)fpatan((((float10)*(float *)(iVar3 + 0x180) -

                               (float10)*(float *)(iVar6 + 0xa8)) + (float10)100.0) /

                              (fVar7 / (float10)*(float *)(iVar6 + 0x194)),

                              (float10)*(float *)(iVar6 + 0x194));

      param_1 = (float)(fVar7 * (float10)57.295776);

      if (fVar7 * (float10)57.295776 < (float10)0.0) {

        param_1 = param_1 + 360.0;

      }

      do {

        sine_cos_lookup(fStack_3c,&fStack_30,&fStack_2c);

        sine_cos_lookup(param_1,&fStack_38,&fStack_34);

        fStack_18 = fStack_34 * fStack_30;

        fStack_10 = fStack_38;

        fStack_1c = fStack_34;

        fStack_14 = -(fStack_34 * fStack_2c);

        fStack_24 = -(fStack_38 * fStack_30);

        fStack_20 = fStack_38 * fStack_2c;

        iVar6 = fx_shape_gen(auStack_c,0x460ca000,iVar4,&fStack_18,&fStack_24,auStack_28);

        if (iVar6 == 0) break;

        param_1 = param_1 + 5.0;

      } while (70.0 <= param_1);

      diff_rangle__Fff(&fStack_3c);

      diff_rangle__Fff(&param_1);

      fVar7 = (float10)FUN_00518b70(iVar3,0,0x43b40000,fStack_3c,(float *)(iVar3 + 200));

      chase_angle((float)(fVar7 * (float10)90.0));

      fVar7 = (float10)FUN_00518b70(iVar3,0,0x43b40000,param_1,(float *)(iVar3 + 0xcc));

      chase_angle((float)(fVar7 * (float10)30.0));

      if ((fStack_3c == *(float *)(iVar3 + 200)) && (param_1 == *(float *)(iVar3 + 0xcc))) {

        sound_stop_obj(0x593,iVar3);

        *(undefined4 *)(iVar3 + 0xe4) = 0xc;

      }

    }

    else if (*(int *)(iVar3 + 0xe4) == 0xc) {

      iVar4 = *(int *)(iVar3 + 0x274);

      if (iVar4 != 0) {

        sound_play_obj(0x61c,iVar3);

        sound_play_obj(0x634,iVar4);

        fVar7 = (float10)dirfcalcp3d__FP3P3DT0(iVar4 + 0xa0,iVar3 + 0x178);

        fStack_2c = (float)fVar7;

        fVar7 = (float10)distance2d__FP3P3DT0(iVar4 + 0xa0,iVar3 + 0x178);

        fVar2 = *(float *)(iVar4 + 0x194);

        fVar1 = *(float *)(iVar3 + 0x180);

        *(float *)(iVar4 + 0x11c) = fVar2;

        *(float *)(iVar4 + 200) = fStack_2c;

        *(undefined4 *)(iVar4 + 0x210) = 0;

        *(float *)(iVar4 + 0x10c) = fVar2;

        fVar8 = (((float10)fVar1 - (float10)*(float *)(iVar4 + 0xa8)) + (float10)100.0) /

                (fVar7 / (float10)fVar2);

        *(uint *)(iVar4 + 0x1c8) = *(uint *)(iVar4 + 0x1c8) & 0xfffffff7 | 0x600;

        *(float *)(iVar4 + 0x118) = (float)fVar8;

        *(float *)(iVar4 + 0x108) = (float)fVar8;

        fVar8 = (float10)fpatan(fVar8,(float10)fVar2);

        *(float *)(iVar4 + 0xcc) = (float)(fVar8 * (float10)57.295776);

        *(float *)(iVar4 + 0xec) = (float)(fVar7 / (float10)fVar2);

        *(undefined4 *)(iVar3 + 0x274) = 0;

        *(undefined4 *)(iVar3 + 0xe4) = 0xd;

        *(uint *)(iVar3 + 0x30) = *(uint *)(iVar3 + 0x30) & 0xfffffffb;

        return;

      }

      *(undefined4 *)(iVar3 + 0xe4) = 10;

      return;

    }

  }

  return;

}

/* ===== cspec_00470dd0 @ 0x00470DD0 ===== */
void cspec_00470dd0(undefined4 param_1,float param_2,int param_3)



{

  char *pcVar1;

  undefined4 uVar2;

  undefined1 *puVar3;

  undefined1 auStack_34 [4];

  undefined4 uStack_30;

  undefined4 uStack_2c;

  undefined4 uStack_28;

  

  param_2 = param_2 + *(float *)(param_3 + 0x278);

  *(float *)(param_3 + 0x278) = param_2;

  if (*(float *)(param_3 + 0x1c0) <= param_2) {

    uStack_30 = *(undefined4 *)(param_3 + 0xa0);

    uStack_2c = *(undefined4 *)(param_3 + 0xa4);

    uStack_28 = *(undefined4 *)(param_3 + 0xa8);

    puVar3 = auStack_34;

    uVar2 = 8;

    pcVar1 = s_fx_launcher_explode_0055b5ec;

    fx_get_free_effect__Fv();

    sound_play_3dpos(0x610,(undefined4 *)(param_3 + 0xa0),pcVar1,uVar2,puVar3);

    object_destroy(param_3);

  }

  return;

}

/* ===== sound_obj_event @ 0x00470E40 ===== */
undefined4 sound_obj_event(undefined4 *param_1)



{

  int iVar1;

  undefined4 *puVar2;

  int iVar3;

  int *piVar4;

  float10 fVar5;

  

  puVar2 = param_1;

  iVar3 = 0;

  if (DAT_00632d68 != (int *)0x0) {

    fVar5 = (float10)(float)param_1;

    piVar4 = DAT_00632d68;

    do {

      iVar1 = piVar4[3];

      if ((((*(int *)(iVar1 + 4) == 0x2b0) && (*(int *)(iVar1 + 0x274) != 0)) &&

          (*(int *)(iVar1 + 0xe4) == 10)) &&

         ((fVar5 = (float10)distancesq2d__FP3P3DT0(puVar2,iVar1 + 0xa0), iVar3 == 0 ||

          (fVar5 < (float10)(float)param_1)))) {

        param_1 = (undefined4 *)(float)fVar5;

        iVar3 = iVar1;

      }

      piVar4 = (int *)*piVar4;

    } while (piVar4 != (int *)0x0);

    if ((iVar3 != 0) &&

       (fVar5 < (float10)*(float *)(DAT_00632ed8 + 0xc3c) *

                (float10)*(float *)(DAT_00632ed8 + 0xc3c))) {

      sound_play_obj(0x593,iVar3);

      *(undefined4 *)(iVar3 + 0xe4) = 0xb;

      *(undefined4 *)(iVar3 + 0x178) = *puVar2;

      *(undefined4 *)(iVar3 + 0x17c) = puVar2[1];

      *(undefined4 *)(iVar3 + 0x180) = puVar2[2];

      return 1;

    }

  }

  return 0;

}

/* ===== cspec_00470f10 @ 0x00470F10 ===== */
void cspec_00470f10(float param_1)



{

  undefined4 *puVar1;

  float fVar2;

  int iVar3;

  int iVar4;

  float in_ECX;

  float10 fVar5;

  undefined4 uVar6;

  float fStack_4;

  

  fVar2 = param_1;

  if (*(int *)((int)param_1 + 0x210) != 0) {

    *(undefined4 *)((int)param_1 + 0xcc) = *(undefined4 *)(*(int *)((int)param_1 + 0x210) + 0xcc);

    return;

  }

  fStack_4 = in_ECX;

  if (*(int *)((int)param_1 + 0xe4) == 0) {

    fVar5 = (float10)FUN_00518b70(param_1,0);

    fVar5 = (float10)*(float *)((int)fVar2 + 0xec) - fVar5;

    *(float *)((int)fVar2 + 0xec) = (float)fVar5;

    puVar1 = DAT_00632d6c;

    if ((float10)0.0 <= fVar5) {

      if ((fVar5 < (float10)0.75) &&

         (iVar4 = crt_rand_scaled(100), puVar1 = DAT_00632d6c, iVar4 < 0x1e)) {

        for (; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {

          iVar4 = puVar1[3];

          if ((*(int *)(iVar4 + 4) == 0xd7) && (*(float *)(iVar4 + 0x210) == fVar2)) {

            *(undefined4 *)(iVar4 + 0x210) = 0;

            iVar3 = crt_rand_scaled(100);

            if (iVar3 < 0x32) {

              uVar6 = 0x86;

            }

            else {

              uVar6 = 0x87;

            }

            sound_play_obj(uVar6,iVar4);

            break;

          }

        }

      }

    }

    else {

      for (; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {

        iVar4 = puVar1[3];

        if ((*(int *)(iVar4 + 4) == 0xd7) && (*(float *)(iVar4 + 0x210) == fVar2)) {

          *(undefined4 *)(iVar4 + 0x210) = 0;

          iVar3 = crt_rand_scaled(100);

          if (iVar3 < 0x21) {

            iVar3 = crt_rand_scaled(100);

            if (iVar3 < 0x32) {

              uVar6 = 0x86;

            }

            else {

              uVar6 = 0x87;

            }

            sound_play_obj(uVar6,iVar4);

          }

        }

      }

      *(undefined4 *)((int)fVar2 + 0xe4) = 1;

      *(uint *)((int)fVar2 + 0x1c8) = *(uint *)((int)fVar2 + 0x1c8) & 0xfffff9ff;

    }

  }

  sine_cos_lookup(*(undefined4 *)((int)fVar2 + 200),&fStack_4,&param_1);

  fVar5 = (float10)FUN_00518b70(fVar2,0);

  fVar5 = fVar5 * (float10)*(float *)((int)fVar2 + 0x10c);

  object_add_location(fVar2,(float)(fVar5 * (float10)fStack_4),(float)-((float10)param_1 * fVar5),0)

  ;

  if (*(int *)((int)fVar2 + 0xe4) == 1) {

    FUN_004a73a0(fVar2);

  }

  FUN_004a7400(fVar2);

  fVar5 = (float10)fpatan((float10)*(float *)((int)fVar2 + 0x108),

                          (float10)*(float *)((int)fVar2 + 0x10c));

  *(float *)((int)fVar2 + 0xcc) = (float)(fVar5 * (float10)57.295776);

  if (((*(uint *)((int)fVar2 + 0xd8) & 0x80000) != 0) || (*(float *)((int)fVar2 + 0xa8) < 0.0)) {

    *(undefined4 *)((int)fVar2 + 0xe4) = 1;

    func_0x004eeb00((int)fVar2 + 0xa0,0x19,*(undefined1 *)((int)fVar2 + 0x1f5));

    object_destroy(fVar2);

  }

  return;

}

/* ===== water_draw_dump @ 0x00471130 ===== */
void water_draw_dump(void)



{

  int iVar1;

  float fVar2;

  float fVar3;

  int iVar4;

  int local_8c;

  int iStack_88;

  int iStack_84;

  int local_80;

  undefined4 local_78;

  undefined4 local_74;

  undefined4 local_70;

  undefined4 local_6c;

  undefined4 local_68;

  undefined4 local_64;

  undefined1 auStack_60 [4];

  float fStack_5c;

  float fStack_58;

  undefined1 auStack_54 [4];

  undefined4 local_50;

  undefined4 local_4c;

  undefined4 local_48;

  undefined1 auStack_44 [4];

  undefined1 auStack_40 [64];

  

  iVar4 = DAT_006330e4;

  if ((((DAT_0063319c == 0) || (DAT_006331a8 != 0)) && (DAT_006330e4 != 0)) &&

     ((~*(ushort *)(DAT_006330e4 + 0x4ebe) & 0x4000) != 0)) {

    iVar1 = DAT_006330e4 + 0x4ea0;

    local_8c = 1;

    local_80 = 0;

    do {

      local_4c = 0;

      local_50 = 0;

      local_48 = 0x44480000;

      local_64 = 0;

      local_68 = 0;

      local_6c = 0;

      local_70 = 0;

      local_74 = 0;

      local_78 = 0;

      switch(local_80) {

      case 0:

        local_78 = 0xbf800000;

        break;

      case 1:

        local_78 = 0x3f800000;

        break;

      case 2:

        local_74 = 0x3f800000;

        local_64 = 0xbf800000;

        goto switchD_004711dd_default;

      case 3:

        local_74 = 0xbf800000;

        local_64 = 0x3f800000;

        goto switchD_004711dd_default;

      case 4:

        local_70 = 0x3f800000;

        break;

      case 5:

        local_70 = 0xbf800000;

        break;

      default:

        goto switchD_004711dd_default;

      }

      local_68 = 0x3f800000;

switchD_004711dd_default:

      if ((iVar1 != 0) && (*(char *)(iVar4 + 0x4ebe) < '\0')) {

        if (local_8c != 0) {

          local_8c = (**(code **)(DAT_00656420 + 0x8c))(DAT_00656420,iVar1,local_80);

        }

        (**(code **)(DAT_00656420 + 0xc0))(DAT_00656420,iVar1,auStack_54,auStack_60);

        iStack_84 = 1 << (auStack_54[0] & 0x1f);

        iStack_88 = 1 << (auStack_60[0] & 0x1f);

        fVar2 = (float)iStack_88;

        fVar3 = (float)iStack_84;

        fStack_5c = fVar2;

        fStack_58 = fVar3;

        XFSetViewportRegion(0,0,fVar3,fVar2);

        view_matrix_build(&local_50,&local_78,&local_6c);

        render_projection_set(0x42b40000,0,1);

        GEO_MatIdentity(auStack_44);

        (**(code **)(DAT_00656420 + 0x18))(DAT_00656420,auStack_40);

        (**(code **)(DAT_00656420 + 0xa0))(DAT_00656420,0,0,fVar3,fVar2,0);

        (**(code **)(DAT_00656420 + 0x14))(DAT_00656420);

        xfmat_mult_b();

        render_scene_begin();

        ai_island_init(0,0);

        dome_render_text(0,0);

        main_drawwatr_00431700();

        render_scene_end();

        ANM_DumpCluster();

        if (local_8c == 0) {

          (**(code **)(DAT_00656420 + 0xb8))(DAT_00656420,iVar1,0,0,iStack_84,iStack_88);

        }

      }

      local_80 = local_80 + 1;

    } while (local_80 < 6);

    if (local_8c == 0) {

      (**(code **)(DAT_00656420 + 0x9c))(DAT_00656420,0,0,(float)iStack_84,(float)iStack_88,0);

    }

    else {

      (**(code **)(DAT_00656420 + 0xa4))(DAT_00656420,0,0,(float)iStack_84,(float)iStack_88);

    }

    (**(code **)(DAT_00656420 + 0x8c))(DAT_00656420,0,0);

    *(byte *)(DAT_006330e4 + 0x4ebf) = *(byte *)(DAT_006330e4 + 0x4ebf) | 0x40;

  }

  return;

}

/* ===== fx_weather_system @ 0x00471420 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void fx_weather_system(void)



{

  float fVar1;

  float fVar2;

  float fVar3;

  bool bVar4;

  int iVar5;

  float *pfVar6;

  float *pfVar7;

  undefined4 *puVar8;

  float *pfVar9;

  int iVar10;

  int iVar11;

  int iVar12;

  undefined4 *puVar13;

  float10 fVar14;

  float10 fVar15;

  int iStack_80;

  int local_7c;

  undefined1 auStack_6c [4];

  undefined1 auStack_68 [4];

  int iStack_64;

  int iStack_60;

  undefined4 uStack_5c;

  undefined4 uStack_58;

  undefined4 uStack_54;

  undefined4 uStack_50;

  undefined1 auStack_44 [4];

  undefined1 auStack_40 [64];

  

  local_7c = 1;

  bVar4 = true;

  if (((DAT_006331b0 == 0) && (DAT_006330e4 != 0)) && (*(int *)(DAT_006330e4 + 0x5080) != 0)) {

    (**(code **)(DAT_00656420 + 0x18))(DAT_00656420,&DAT_0055b600);

    (**(code **)(DAT_00656430 + 0xc))(DAT_00656430,2);

    (**(code **)(DAT_00656430 + 0x10))(DAT_00656430,1);

    iStack_80 = 0x508c;

    iVar10 = 0;

    do {

      iVar12 = (*(int *)(DAT_006330e4 + 0x503c) + 0x282) * 0x20 + DAT_006330e4;

      iStack_60 = iVar12;

      if (local_7c != 0) {

        local_7c = (**(code **)(DAT_00656420 + 0x8c))(DAT_00656420,iVar12,0);

      }

      (**(code **)(DAT_00656420 + 0xc0))(DAT_00656420,iVar12,auStack_6c,auStack_68);

      iVar11 = 1 << (auStack_6c[0] & 0x1f);

      iVar5 = 1 << (auStack_68[0] & 0x1f);

      iStack_64 = iVar11;

      XFSetViewportRegion(0,0,(float)iVar11,(float)iVar5);

      render_projection_reset(&DAT_0055b640,&DAT_0055b64c);

      GEO_MatIdentity(auStack_44);

      view_matrix_reset(auStack_40);

      render_scene_begin();

      iVar12 = DAT_006330e4;

      fVar1 = *(float *)((int)&DAT_0059dbb0 + iVar10);

      fVar2 = *(float *)(&DAT_00556680 + iStack_80);

      uStack_5c = *(undefined4 *)(DAT_006330e4 + 0x5080);

      fVar3 = *(float *)((int)&DAT_0059dbb4 + iVar10);

      pfVar6 = (float *)&DAT_0055b6c8;

      pfVar9 = (float *)&DAT_0055b66c;

      do {

        pfVar9[-2] = -NAN;

        pfVar7 = pfVar6 + 2;

        pfVar9[-1] = (fVar1 + pfVar6[-1]) * fVar2;

        *pfVar9 = (fVar3 + *pfVar6) * fVar2;

        pfVar6 = pfVar7;

        pfVar9 = pfVar9 + 6;

      } while ((int)pfVar7 < 0x55b6e8);

      uStack_50 = *(undefined4 *)(iStack_80 + iVar12);

      uStack_58 = 0;

      if (bVar4) {

        uStack_54 = 0x21064;

        bVar4 = false;

      }

      else {

        uStack_54 = 0x21564;

      }

      (**(code **)(DAT_00656430 + 0x14))(DAT_00656430,&uStack_5c);

      puVar8 = (undefined4 *)(**(code **)(DAT_0065644c + 0x10))(DAT_0065644c,4);

      puVar13 = &DAT_0055b658;

      for (iVar12 = 0x18; iVar12 != 0; iVar12 = iVar12 + -1) {

        *puVar8 = *puVar13;

        puVar13 = puVar13 + 1;

        puVar8 = puVar8 + 1;

      }

      (**(code **)(DAT_0065644c + 0x18))(DAT_0065644c,0);

      (**(code **)(DAT_0065644c + 0x20))(DAT_0065644c,6,&DAT_0055b6b8);

      iVar12 = DAT_006330e4;

      fVar14 = (float10)*(float *)((int)&DAT_0055b6e4 + iVar10) * (float10)31.415928 +

               (float10)_DAT_0059dbd8;

      if ((float10)6.2831855 < fVar14) {

        do {

          fVar14 = fVar14 - (float10)6.2831855;

        } while ((float10)6.2831855 < fVar14);

      }

      fVar15 = (float10)fsin(fVar14);

      *(float *)((int)&DAT_0059dbb0 + iVar10) =

           (float)(fVar15 * (float10)*(float *)((int)&DAT_0055b6e8 + iVar10) * (float10)DAT_006328e0

                   * (float10)*(float *)(DAT_006330e4 + 0x50b4) +

                  (float10)*(float *)((int)&DAT_0059dbb0 + iVar10));

      fVar14 = (float10)fcos(fVar14);

      *(float *)((int)&DAT_0059dbb4 + iVar10) =

           (float)(fVar14 * (float10)*(float *)((int)&DAT_0055b6e8 + iVar10) * (float10)DAT_006328e0

                   * (float10)*(float *)(iVar12 + 0x50b4) +

                  (float10)*(float *)((int)&DAT_0059dbb4 + iVar10));

      fVar1 = *(float *)((int)&DAT_0059dbb0 + iVar10);

      if (1.0 < fVar1) {

        do {

          fVar1 = fVar1 - 1.0;

        } while (1.0 < fVar1);

        *(float *)((int)&DAT_0059dbb0 + iVar10) = fVar1;

      }

      fVar1 = *(float *)((int)&DAT_0059dbb4 + iVar10);

      if (1.0 < fVar1) {

        do {

          fVar1 = fVar1 - 1.0;

        } while (1.0 < fVar1);

        *(float *)((int)&DAT_0059dbb4 + iVar10) = fVar1;

      }

      render_scene_end();

      if (local_7c == 0) {

        (**(code **)(DAT_00656420 + 0xb8))(DAT_00656420,iStack_60,0,0,iVar11,iVar5);

      }

      iStack_80 = iStack_80 + 4;

      iVar10 = iVar10 + 8;

    } while (iStack_80 < 0x509d);

    (**(code **)(DAT_00656420 + 0x8c))(DAT_00656420,0,0);

    (**(code **)(DAT_00656430 + 0xc))(DAT_00656430,1);

    (**(code **)(DAT_00656430 + 0x10))(DAT_00656430,1);

  }

  return;

}

/* ===== hud_audio_dlog_screen @ 0x00471780 ===== */
undefined4 hud_audio_dlog_screen(void)



{

  undefined4 uVar1;

  int iVar2;

  int iVar3;

  uint uVar4;

  uint uVar5;

  float10 fVar6;

  float10 fVar7;

  undefined1 *puVar8;

  undefined1 *puVar9;

  float fVar10;

  undefined1 auStack_50 [16];

  undefined1 auStack_40 [64];

  

  endDisplay__Fv();

  audio_register_sound_name(&DAT_0055b720);

  if (DAT_00633128 == 0) {

    DAT_00632e6c = DAT_00632e6c + DAT_006328e0;

    DAT_00632e70 = DAT_00632e70 + 1;

  }

  hud_status_main();

  lzss_compress_387c();

  if (DAT_00633044 == 0) {

    uVar1 = 0;

  }

  else {

    uVar1 = AudioDataStreamStatus__Fv_5();

  }

  (*DAT_005dd294)(uVar1);

  (*DAT_005dd314)();

  (**(code **)(DAT_00656420 + 0x88))(DAT_00656420);

  if ((DAT_006330e4 != 0) && (DAT_00633044 != 0)) {

    if (DAT_006330dc != 0) goto LAB_00471872;

    puVar9 = auStack_50;

    XFGetViewport_2(puVar9);

    puVar8 = auStack_40;

    view_matrix_get(puVar8);

    fVar6 = (float10)render_get_fov();

    fVar7 = (float10)render_get_aspect();

    fVar10 = (float)fVar7;

    fx_weather_system(puVar8,puVar9,fVar10);

    water_draw_dump();

    XFSetViewport(auStack_50);

    view_matrix_reset(auStack_40);

    render_projection_set((float)fVar6,fVar10,1);

  }

  if (DAT_006330dc == 0) {

    iVar2 = FLK_FlickPlaying();

    if (iVar2 != 0) {

      iVar2 = flick_objects_reload();

      if (iVar2 == 0) {

        screenshot_helper();

        return 1;

      }

      FUN_00490d40();

      if (DAT_00632b98 != 0) {

        return 1;

      }

    }

    DAT_0063302c = DAT_0063302c + 1;

    if ((DAT_00633028 == 0) || (DAT_0063302c < 4)) {

      iVar2 = scenerio_process__Fv();

      if (iVar2 != 0) {

        iVar2 = FLK_FlickPlaying();

        if (iVar2 != 0) {

          return 1;

        }

        dialog_level_process();

        return 1;

      }

      iVar2 = FLK_FlickPlaying();

      if (iVar2 == 0) {

        dialog_level_process();

      }

    }

    if (((DAT_00633044 != 0) && (ref_anode_user(), iVar2 = DAT_006330e4, DAT_006330e4 != 0)) &&

       (*(int *)(DAT_006330e4 + 0x13c) == 0)) {

      iVar3 = __ftol();

      uVar4 = __ftol();

      uVar5 = __ftol();

      *(uint *)(iVar2 + 0x13c) = (iVar3 << 8 | uVar4) << 8 | uVar5;

    }

    if (DAT_006330e0 == 0) {

      if ((((DAT_006330e4 == 0) || (DAT_00633044 == 0)) ||

          (iVar2 = dialog_level_is_base(), iVar2 == 0)) || (DAT_00633048 != 0)) {

        uVar1 = 0;

      }

      else {

        uVar1 = *(undefined4 *)(DAT_006330e4 + 0x13c);

      }

      (**(code **)(DAT_00656420 + 0x98))(DAT_00656420,uVar1);

    }

    render_scene_begin();

    render_error_poll();

    AddHud__4cHudP8cHudIcon_2();

    render_scene_end();

    (**(code **)(DAT_00656420 + 0xa8))(DAT_00656420);

    return 1;

  }

LAB_00471872:

  dialog_level_process();

  if (DAT_006330e0 == 0) {

    if ((((DAT_006330e4 == 0) || (DAT_00633044 == 0)) ||

        (iVar2 = dialog_level_is_base(), iVar2 == 0)) || (DAT_00633048 != 0)) {

      uVar1 = 0;

    }

    else {

      uVar1 = *(undefined4 *)(DAT_006330e4 + 0x13c);

    }

    (**(code **)(DAT_00656420 + 0x98))(DAT_00656420,uVar1);

  }

  render_scene_begin();

  render_error_poll();

  AddHud__4cHudP8cHudIcon_2();

  render_scene_end();

  (**(code **)(DAT_00656420 + 0xa8))(DAT_00656420);

  return 1;

}

/* ===== game_loop_run @ 0x00471A60 ===== */
/* PS2 candidate: game_loop_run (conf 0.48) */



void game_loop_run(int param_1)



{

  undefined4 *puVar1;

  undefined4 uVar2;

  int iVar3;

  float10 fVar4;

  

  if ((DAT_00633044 != 0) && ((param_1 == 0 || (DAT_00632e40 == 0)))) {

    if ((DAT_00632b98 != 0) && (iVar3 = FLK_FlickPlaying(), iVar3 == 0)) {

      DAT_00632b8c = 1;

      DAT_00632b98 = 0;

    }

    if ((DAT_00633248 != 0) && (iVar3 = FLK_FlickPlaying(), iVar3 == 0)) {

      fps_log_write();

    }

    if ((DAT_00632b8c != 0) && (fx_logic(3,0), DAT_00632b8c != 0)) {

      DAT_00632b8c = 0;

      FUN_004EE800();

      return;

    }

    if ((param_1 != 0) && (DAT_00633128 != 0)) {

      comm_game_session_update();

      return;

    }

    if (DAT_00632a88 != 0) {

      iVar3 = FUN_0045d290(DAT_00632a88);

      puVar1 = DAT_00632d68;

      if (iVar3 != 0) {

        DAT_00632adf = 1;

      }

      for (; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {

        if ((*(uint *)(puVar1[3] + 0xdc) & 0x80000000) != 0) {

          object_init_usage(puVar1[3]);

        }

      }

      FUN_00531470();

      for (puVar1 = DAT_00632d68; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {

        if ((*(uint *)(puVar1[3] + 0xd8) & 0xc000) == 0) {

          object_copy_posdirinfo(puVar1[3]);

        }

      }

      if (DAT_00633044 != 0) {

        if (DAT_00632d60 != 0) {

          main_demo_004267a0();

        }

        if (param_1 != 0) {

          comm_game_session_update();

        }

        if ((DAT_00632a88 != 0) && (DAT_00633044 != 0)) {

          input_mouse_world_check();

          kabutoai_select_target__FP6OBJECT();

          obj_float_chase_update();

          weapon_id_inventory_update();

          match_start_big();

          for (puVar1 = DAT_00632d70; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {

            uVar2 = puVar1[3];

            FUN_00501050(uVar2);

            teammecc_enemies_helper(uVar2);

          }

          cleaner_go_obj();

          piranha_go();

          comm_stats_reset();

          win95_frate_00518c60();

          for (puVar1 = DAT_00632d68; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {

            iVar3 = puVar1[3];

            if ((*(uint *)(iVar3 + 0xd8) & 0xc000) == 0) {

              *(uint *)(iVar3 + 0xd8) = *(uint *)(iVar3 + 0xd8) & 0xffffffbf;

              obj_velocity_commit(iVar3);

              if (DAT_00632a88 == 0) {

                return;

              }

              if ((*(uint *)(iVar3 + 0xd8) & 0xc000) == 0) {

                if ((*(uint *)(iVar3 + 0xd8) & 0x40) == 0) {

                  objspec_dispatch_gate(iVar3);

                  fVar4 = (float10)FUN_00518b70(iVar3,0);

                  object_animate_process(iVar3,(float)fVar4);

                  object_apply_location(iVar3);

                }

                *(uint *)(iVar3 + 0xd8) = *(uint *)(iVar3 + 0xd8) & 0xfffff7ff;

              }

            }

          }

          object_spawn_class3(0);

          mecc_logic();

          FUN_0049b810();

          for (puVar1 = DAT_00632d68; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {

            if ((*(uint *)(puVar1[3] + 0xd8) & 0xc000) == 0) {

              object_lock_with_volume(puVar1[3]);

            }

          }

          puVar1 = DAT_00632d68;

          if (DAT_00632a88 != 0) {

            for (; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {

              if ((*(uint *)(puVar1[3] + 0xd8) & 0x8000) == 0) {

                PROJ_ObjectFinalize(puVar1[3]);

              }

            }

            process_wound();

            particles_decay_update();

            FUN_00443110();

            fx_process(0);

            sound_checked_big(0);

            ANM_DumpCluster();

            comm_heartbeat_send();

            if (DAT_00632a88 != 0) {

              if (DAT_00632d5c != 0) {

                dlog_objname_menu();

              }

              object_list_update();

              FUN_0040b2c0();

              puVar1 = DAT_00632d68;

              if (DAT_00632a88 != 0) {

                for (; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {

                  iVar3 = puVar1[3];

                  mission_check_obj_proximity__FP6OBJECT(iVar3);

                  if ((*(int *)(iVar3 + 0x204) != 0) && ((*(uint *)(iVar3 + 0xd8) & 0xc000) == 0)) {

                    flk_actor_update(iVar3);

                  }

                }

                iVar3 = dialog_level_is_base();

                if (iVar3 != 0) {

                  FUN_005375e0();

                  return;

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

/* ===== render_error_dialog_check @ 0x00471DC0 ===== */
/* PS2 candidate: __main_3 (conf 0.574) */



void render_error_dialog_check(void)



{

  if (DAT_00633048 != 0) {

    DAT_00633048 = 0;

    return;

  }

  if (DAT_00633044 == 0) {

    textrender_draw_buffered(0xffffff,0,0x3dcccccd,0x3f000000,0x3f000000,s_Render_Error_0055b724);

    return;

  }

  dev_debug_flags();

  return;

}

/* ===== BinFileSeek_5 @ 0x004721B0 ===== */
void BinFileSeek_5(undefined4 param_1,undefined4 param_2)



{

  main_makeobj_00471e10(param_1,param_2,0);

  return;

}

/* ===== main/makewrld_00473570 @ 0x00473570 ===== */
/* PS2 candidate: calc_tri_weighted_plane (conf 0.611) */



void main_makewrld_00473570

               (float *param_1,float *param_2,float *param_3,int param_4,int param_5,int param_6,

               int param_7)



{

  float *pfVar1;

  

  pfVar1 = (float *)(param_4 + (param_6 * param_7 + param_5) * 0xc);

  *pfVar1 = ((param_3[2] - param_1[2]) * (param_2[1] - param_1[1]) -

            (param_3[1] - param_1[1]) * (param_2[2] - param_1[2])) + *pfVar1;

  pfVar1[1] = ((*param_3 - *param_1) * (param_2[2] - param_1[2]) -

              (*param_2 - *param_1) * (param_3[2] - param_1[2])) + pfVar1[1];

  pfVar1[2] = ((param_3[1] - param_1[1]) * (*param_2 - *param_1) -

              (*param_3 - *param_1) * (param_2[1] - param_1[1])) + pfVar1[2];

  return;

}

/* ===== grid_point_user @ 0x00473E10 ===== */
void grid_point_user(int param_1,int param_2,float *param_3,float *param_4,undefined4 param_5)



{

  float local_30;

  float local_2c;

  float local_24;

  float local_20;

  float local_18;

  float local_14;

  float local_c;

  float local_8;

  

  grid_get_point(param_1,param_2,&local_c);

  grid_get_point(param_1 + 1,param_2,&local_18);

  grid_get_point(param_1,param_2 + 1,&local_24);

  grid_get_point(param_1 + 1,param_2 + 1,&local_30);

  switch(param_5) {

  case 1:

    *param_3 = (local_24 + local_18 + local_c) * 0.33333334;

    param_4 = param_3;

    local_2c = local_20;

    break;

  case 2:

    *param_3 = (local_30 + local_24 + local_18) * 0.33333334;

    param_3[1] = (local_2c + local_20 + local_14) * 0.33333334;

    return;

  case 3:

    *param_3 = (local_30 + local_18 + local_c) * 0.33333334;

    param_4 = param_3;

    break;

  case 4:

    *param_3 = (local_30 + local_24 + local_c) * 0.33333334;

    param_3[1] = (local_2c + local_20 + local_8) * 0.33333334;

    return;

  case 5:

    *param_3 = (local_30 + local_24 + local_c) * 0.33333334;

    param_3[1] = (local_2c + local_20 + local_8) * 0.33333334;

    *param_4 = (local_30 + local_18 + local_c) * 0.33333334;

    break;

  case 6:

    *param_3 = (local_24 + local_18 + local_c) * 0.33333334;

    param_3[1] = (local_20 + local_14 + local_8) * 0.33333334;

    *param_4 = (local_30 + local_24 + local_18) * 0.33333334;

    param_4[1] = (local_2c + local_20 + local_14) * 0.33333334;

    return;

  default:

    goto switchD_00473e6b_default;

  }

  param_4[1] = (local_2c + local_14 + local_8) * 0.33333334;

switchD_00473e6b_default:

  return;

}

/* ===== landscape_bump_check @ 0x00473FF0 ===== */
undefined4 landscape_bump_check(int param_1,int param_2,int param_3,int param_4,int param_5)



{

  float fVar1;

  undefined1 *puVar2;

  int iVar3;

  float local_88;

  float local_84;

  float local_80;

  undefined1 local_7c [8];

  float local_74;

  undefined1 local_6c [8];

  float local_64;

  undefined1 local_60 [8];

  float local_58;

  undefined1 local_54 [8];

  float local_4c;

  undefined1 local_48 [8];

  float local_40;

  undefined1 local_3c [8];

  float local_34;

  undefined1 local_30 [8];

  float local_28;

  undefined1 local_24 [8];

  float local_1c;

  undefined1 local_18 [12];

  undefined1 local_c [12];

  

  iVar3 = param_1 * 0x10 + *(int *)(*(int *)(DAT_006330e4 + 0x10) + param_2 * 4);

  if (*(short *)(iVar3 + 0xc) != 0) {

    if (param_5 != 0) {

      grid_get_point(param_1,param_2,local_48);

      grid_get_point(param_1 + 1,param_2,local_3c);

      grid_get_point(param_1,param_2 + 1,local_30);

      grid_get_point(param_1 + 1,param_2 + 1,local_6c);

      local_88 = local_40;

      if (local_34 < local_40) {

        local_88 = local_34;

      }

      if (local_28 < local_88) {

        local_88 = local_28;

      }

      if (local_64 < local_88) {

        local_88 = local_64;

      }

      local_80 = local_40;

      if (local_40 < local_34) {

        local_80 = local_34;

      }

      if (local_80 < local_28) {

        local_80 = local_28;

      }

      if (local_80 < local_64) {

        local_80 = local_64;

      }

      grid_get_point(param_3,param_4,local_24);

      local_84 = (float)(param_3 + 1);

      grid_get_point(local_84,param_4,local_60);

      grid_get_point(param_3,param_4 + 1,local_54);

      grid_get_point(local_84,param_4 + 1,local_7c);

      fVar1 = local_1c;

      if (local_58 < local_1c) {

        fVar1 = local_58;

      }

      if (local_4c < fVar1) {

        fVar1 = local_4c;

      }

      if (local_74 < fVar1) {

        fVar1 = local_74;

      }

      local_84 = local_1c;

      if (local_1c < local_58) {

        local_84 = local_58;

      }

      if (local_84 < local_4c) {

        local_84 = local_4c;

      }

      if (local_84 < local_74) {

        local_84 = local_74;

      }

      if ((fVar1 < local_80 + 20.0) && (local_84 - 20.0 < local_88)) {

        return 1;

      }

    }

    grid_point_user(param_1,param_2,local_18,local_c,*(byte *)(iVar3 + 0xc) & 7);

    switch(*(byte *)(iVar3 + 0xc) & 7) {

    case 1:

    case 2:

    case 3:

    case 4:

      puVar2 = local_18;

      break;

    case 5:

    case 6:

      ai_fly_update_goal_4(local_18,local_7c,&local_88);

      if (local_74 < 0.64278) {

        return 0;

      }

      if (local_88 < -3.0 != (local_88 == -3.0)) {

        return 0;

      }

      puVar2 = local_c;

      break;

    default:

      FUN_0051ea20(s_Bad_landscape_topology_in_bump_m_0055b898);

      return 1;

    }

    ai_fly_update_goal_4(puVar2,local_7c,&local_88);

    if ((0.64278 <= local_74) && (local_88 < -3.0 == (local_88 == -3.0))) {

      return 1;

    }

  }

  return 0;

}

/* ===== world_edge_quadrant @ 0x004751D0 ===== */
undefined4 world_edge_quadrant(float *param_1)



{

  undefined4 uVar1;

  

  if (param_1 == (float *)0x0) {

    return 0;

  }

  if (*(float *)(DAT_006330e4 + 0x4e98) <= param_1[2]) {

    return 0;

  }

  if (*(float *)(DAT_006330e4 + 0x4e9c) <= param_1[2]) {

    if (ABS(param_1[1]) <= ABS(*param_1)) {

      if (*param_1 < 0.0) {

        return 3;

      }

      return 4;

    }

    if (param_1[1] < 0.0) {

      return 1;

    }

    return 2;

  }

  if (ABS(param_1[1]) <= ABS(*param_1)) {

    uVar1 = 7;

    if (0.0 <= *param_1) {

      uVar1 = 8;

    }

    return uVar1;

  }

  if (param_1[1] < 0.0) {

    return 5;

  }

  return 6;

}

/* ===== obj_float_chase_update @ 0x00475290 ===== */
void obj_float_chase_update(void)



{

  float fVar1;

  int iVar2;

  float fVar3;

  int iVar4;

  int iVar5;

  float *pfVar6;

  

  iVar4 = 0;

  iVar5 = DAT_0059dbe0;

  do {

    if (*(int *)(iVar4 + 0xc + iVar5) != 0) {

      fVar1 = *(float *)(iVar4 + 8 + iVar5);

      iVar2 = *(int *)(*(int *)(DAT_006330e4 + 0x10) + *(int *)(iVar4 + 4 + iVar5) * 4);

      iVar5 = *(int *)(iVar4 + iVar5) * 0x10;

      pfVar6 = (float *)(iVar5 + iVar2);

      if (fVar1 <= *(float *)(iVar5 + iVar2)) {

        fVar3 = *pfVar6 - DAT_006328e0 * 250.0;

        *pfVar6 = fVar3;

        iVar5 = DAT_0059dbe0;

        if (fVar3 < fVar1 != (fVar3 == fVar1)) goto LAB_00475302;

      }

      else {

        fVar3 = DAT_006328e0 * 30.0 + *pfVar6;

        *pfVar6 = fVar3;

        iVar5 = DAT_0059dbe0;

        if (fVar1 <= fVar3) {

LAB_00475302:

          *(undefined4 *)

           (*(int *)(iVar4 + DAT_0059dbe0) * 0x10 +

           *(int *)(*(int *)(DAT_006330e4 + 0x10) + *(int *)(iVar4 + 4 + DAT_0059dbe0) * 4)) =

               *(undefined4 *)(iVar4 + 8 + DAT_0059dbe0);

          *(undefined4 *)(iVar4 + 0xc + DAT_0059dbe0) = 0;

          iVar5 = DAT_0059dbe0;

        }

      }

    }

    iVar4 = iVar4 + 0x10;

    if (0x1ff < iVar4) {

      return;

    }

  } while( true );

}

/* ===== FUN_00475350 @ 0x00475350 ===== */
void FUN_00475350(int param_1)



{

  int iVar1;

  

  if ((param_1 != 0) && (DAT_00632bbc != 0)) {

    iVar1 = dialog_level_is_base();

    if (iVar1 != 0) {

      iVar1 = fx_create(DAT_00632bbc);

      if (iVar1 == 0) {

        FUN_0041a1c0(param_1,DAT_00632bbc);

        return;

      }

      *(undefined4 *)(*(int *)(DAT_00632bbc + 0x100) + 0x570) = *(undefined4 *)(param_1 + 0x188);

    }

    dlog_text_render_screen();

    DAT_00632bac = 1;

  }

  return;

}

/* ===== dlog_text_render_screen @ 0x004753C0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void dlog_text_render_screen(void)



{

  byte *pbVar1;

  float fVar2;

  float fVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  float10 fVar9;

  float local_24;

  float local_20;

  float local_1c;

  undefined4 local_18;

  undefined4 local_14;

  undefined4 local_10;

  undefined4 local_c;

  undefined4 local_8;

  undefined4 local_4;

  

  if (DAT_00632a88 != 0) {

    iVar4 = dialog_level_is_base();

    if ((iVar4 != 0) && (iVar4 = 0, 0 < *(int *)(DAT_006330e4 + 0x1dc))) {

      iVar8 = *(int *)(DAT_006330e4 + 0x1d8);

      iVar7 = DAT_006330e4;

      do {

        iVar5 = 0;

        if (0 < iVar8) {

          iVar6 = 0;

          do {

            iVar8 = *(int *)(*(int *)(iVar7 + 0x10) + iVar4 * 4);

            *(byte *)(iVar8 + 0xf + iVar6) = *(byte *)(iVar8 + 0xf + iVar6) | 0x80;

            iVar8 = *(int *)(DAT_006330e4 + 0x1d8);

            iVar5 = iVar5 + 1;

            iVar6 = iVar6 + 0x10;

            iVar7 = DAT_006330e4;

          } while (iVar5 < iVar8);

        }

        iVar4 = iVar4 + 1;

      } while (iVar4 < *(int *)(iVar7 + 0x1dc));

    }

    iVar4 = ObjIsMecc(DAT_00632a88);

    if (iVar4 == 0) {

      iVar4 = ObjIsReaper(DAT_00632a88);

      if (iVar4 != 0) {

        obj_snap_variant_a(DAT_00632a88);

      }

    }

    else {

      mecc_stop_looping_effects(DAT_00632a88);

    }

    DAT_00632ba8 = 1;

    DAT_00633020 = 0;

    dlog_push_level(&LAB_00475b40,&LAB_00476150);

    DAT_0059dbf4 = (float)*(int *)(DAT_006330e4 + 0x1d8) * *(float *)(DAT_006330e4 + 0x1c0) * 0.5 +

                   *(float *)(DAT_006330e4 + 0x1c8);

    DAT_0059dbf8 = (float)*(int *)(DAT_006330e4 + 0x1dc) * *(float *)(DAT_006330e4 + 0x1c0) * 0.5 +

                   *(float *)(DAT_006330e4 + 0x1cc);

    DAT_0059dbe8 = DAT_0059dc9c;

    DAT_0059dbec = DAT_0059dca0;

    _DAT_0059dbf0 = DAT_0059dca4;

    camera_state_save();

    cam_mode_switch(1);

    fVar9 = (float10)render_get_fov();

    DAT_0059dc20 = (float)fVar9;

    fVar9 = (float10)render_get_aspect();

    DAT_0059dc24 = (float)fVar9;

    view_matrix_get(&DAT_0059dc40);

    render_get_clip_nearfar(&DAT_0059dc28,&DAT_0059dc2c);

    local_24 = DAT_0059dbe8 + DAT_0059dbf4;

    local_20 = DAT_0059dbec + DAT_0059dbf8;

    local_18 = 0;

    local_14 = 0x3f800000;

    local_10 = 0;

    local_c = 0;

    local_8 = 0;

    local_1c = _DAT_0059dc18 * 800.0 + 2000.0;

    local_4 = 0xbf800000;

    FNT_StringRender__FPcP14FNT_RenderInfo((char *)0x447a0000,(undefined4 *)0x464b2000);

    view_matrix_build(&local_24,&local_c,&local_18);

    render_projection_set(0x42700000,0x3fa66666,1);

    iVar8 = 0;

    iVar4 = DAT_006330e4;

    if (0 < *(int *)(DAT_006330e4 + 0x1dc)) {

      do {

        iVar7 = 0;

        if (0 < *(int *)(iVar4 + 0x1d8)) {

          iVar5 = 0;

          do {

            if ((*(byte *)(*(int *)(*(int *)(iVar4 + 0x10) + iVar8 * 4) + 0xf + iVar5) & 0x40) != 0)

            {

              screen_coord_calc(iVar7,iVar8);

              pbVar1 = (byte *)(*(int *)(*(int *)(DAT_006330e4 + 0x10) + iVar8 * 4) + 0xf + iVar5);

              *pbVar1 = *pbVar1 & 0xbf;

              iVar4 = DAT_006330e4;

            }

            iVar7 = iVar7 + 1;

            iVar5 = iVar5 + 0x10;

          } while (iVar7 < *(int *)(iVar4 + 0x1d8));

        }

        iVar8 = iVar8 + 1;

      } while (iVar8 < *(int *)(iVar4 + 0x1dc));

    }

    DAT_00632920 = 0xffffffff;

    fVar2 = (float)*(int *)(iVar4 + 0x1d8) * *(float *)(iVar4 + 0x1c0);

    fVar3 = (float)*(int *)(iVar4 + 0x1dc) * *(float *)(iVar4 + 0x1c0);

    fVar9 = (float10)fptan((float10)0.5220000147819519);

    if (fVar3 < fVar2 * 0.75) {

      fVar3 = fVar2;

    }

    fVar9 = (((float10)fVar3 * (float10)0.5) / fVar9 - (float10)2000.0) * (float10)0.00125;

    DAT_0059dc1c = (float)fVar9;

    if (fVar9 < (float10)1.3 != (fVar9 == (float10)1.3)) {

      DAT_0059dc1c = 1.3;

    }

    _DAT_0059dc18 = DAT_0059dc1c;

  }

  return;

}

/* ===== dlog_text_pop_screen @ 0x00475700 ===== */
void dlog_text_pop_screen(int param_1)



{

  int iVar1;

  

  if (((param_1 != 0) && (DAT_00632bbc != 0)) && (DAT_00632a88 != 0)) {

    iVar1 = dialog_level_is_base();

    if ((iVar1 != 0) && (DAT_00632bac != 0)) {

      reaper_state_check_d(DAT_00632a88,DAT_00632bbc);

      *(undefined4 *)(*(int *)(DAT_00632bbc + 0x100) + 0x570) = 0;

    }

  }

  dialog_level_pop(&LAB_00475b40);

  DAT_00632ba8 = 0;

  DAT_00632bac = 0;

  camera_state_restore();

  FNT_StringRender__FPcP14FNT_RenderInfo(DAT_0059dc28,DAT_0059dc2c);

  view_matrix_reset(&DAT_0059dc40);

  render_projection_set(DAT_0059dc20,DAT_0059dc24,1);

  xfmat_mult_a();

  return;

}

/* ===== screen_coord_calc @ 0x004757C0 ===== */
void screen_coord_calc(int param_1,int param_2)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  float local_3c;

  int local_38;

  int local_34;

  int local_30;

  int local_2c;

  float local_28;

  float local_24;

  float local_20;

  float local_1c;

  float local_18;

  float local_10;

  float local_c;

  float local_8;

  float local_4;

  

  iVar3 = DAT_006330e4;

  iVar1 = __ftol();

  local_28 = (float)param_1 * *(float *)(iVar3 + 0x1c0) + *(float *)(iVar3 + 0x1c8);

  local_24 = (float)param_2 * *(float *)(iVar3 + 0x1c0) + *(float *)(iVar3 + 0x1cc);

  local_34 = iVar1;

  physics_vec_math(&local_28,&local_10,0,&local_3c,0);

  local_20 = local_3c + 20.0;

  iVar3 = param_2 - iVar1;

  local_2c = iVar1 + param_2;

  if (iVar3 < local_2c) {

    param_2 = iVar3 - param_2;

    do {

      if (*(int *)(DAT_006330e4 + 0x1dc) + -1 <= iVar3) {

        return;

      }

      if (-1 < iVar3) {

        iVar4 = param_1 - iVar1;

        local_30 = iVar1 + param_1;

        local_18 = (float)iVar3 * *(float *)(DAT_006330e4 + 0x1c0) +

                   *(float *)(DAT_006330e4 + 0x1cc);

        if (iVar4 < local_30) {

          iVar5 = iVar4 * 0x10;

          iVar2 = iVar4 - param_1;

          do {

            iVar1 = local_34;

            if (*(int *)(DAT_006330e4 + 0x1d8) + -1 <= iVar4) break;

            if ((-1 < iVar5) && (iVar2 * iVar2 + param_2 * param_2 <= local_34 * local_34)) {

              local_1c = (float)iVar4 * *(float *)(DAT_006330e4 + 0x1c0) +

                         *(float *)(DAT_006330e4 + 0x1c8);

              local_38 = iVar4;

              physics_vec_math(&local_1c,&local_10,0,&local_3c,0);

              if (-local_4 < local_8 * local_20 + local_c * local_24 + local_10 * local_28) {

                iVar1 = *(int *)(*(int *)(DAT_006330e4 + 0x10) + iVar3 * 4);

                *(byte *)(iVar1 + 0xf + iVar5) = *(byte *)(iVar1 + 0xf + iVar5) | 0x80;

              }

            }

            iVar4 = iVar4 + 1;

            iVar2 = iVar2 + 1;

            iVar5 = iVar5 + 0x10;

            iVar1 = local_34;

          } while (iVar4 < local_30);

        }

      }

      iVar3 = iVar3 + 1;

      param_2 = param_2 + 1;

    } while (iVar3 < local_2c);

  }

  return;

}

/* ===== input_mouse_world_check @ 0x004759A0 ===== */
void input_mouse_world_check(void)



{

  int iVar1;

  int iVar2;

  int iVar3;

  

  iVar1 = DAT_006330e4;

  if (DAT_00632a88 != 0) {

    iVar2 = __ftol();

    iVar3 = __ftol();

    if ((((iVar2 < *(int *)(iVar1 + 0x1d8) + -1) && (iVar3 < *(int *)(iVar1 + 0x1dc) + -1)) &&

        (-1 < iVar2)) && (-1 < iVar3)) {

      if (DAT_00632ba8 != 0) {

        screen_coord_calc(iVar2,iVar3);

        return;

      }

      iVar1 = *(int *)(*(int *)(iVar1 + 0x10) + iVar3 * 4);

      *(byte *)(iVar1 + 0xf + iVar2 * 0x10) = *(byte *)(iVar1 + 0xf + iVar2 * 0x10) | 0x40;

    }

  }

  return;

}

/* ===== turret_find_team_at_point @ 0x00475A40 ===== */
int turret_find_team_at_point(float param_1,float param_2)



{

  int iVar1;

  undefined4 *puVar2;

  float fVar3;

  float fVar4;

  int iVar5;

  int iVar6;

  

  fVar4 = param_2;

  fVar3 = param_1;

  puVar2 = DAT_00632d6c;

  iVar6 = DAT_00632a88;

  while( true ) {

    if (puVar2 == (undefined4 *)0x0) {

      return 0;

    }

    iVar1 = puVar2[3];

    if ((((*(int *)(iVar1 + 0x1e0) == 0x2c) &&

         ((((*(int *)(iVar1 + 4) != 0x3c || (*(int *)(iVar1 + 0x210) == 0)) && (iVar6 != 0)) &&

          ((*(int *)(iVar1 + 0x18c) == *(int *)(iVar6 + 0x18c) &&

           ((*(uint *)(iVar1 + 0xd8) & 0x4000c000) == 0)))))) &&

        (*(int *)(iVar1 + 0x184) != 0x3f800000)) &&

       ((iVar5 = hud_clipcode_calc(iVar1 + 0xa0,&param_1,&param_2), iVar6 = DAT_00632a88, iVar5 == 0

        && (iVar5 = rect2d_normalize(param_1 - 6.0,param_2 - 6.0,param_1 + 6.0,param_2 + 6.0,fVar3,

                                     fVar4,fVar3,fVar4), iVar6 = DAT_00632a88, iVar5 != 0)))) break;

    puVar2 = (undefined4 *)*puVar2;

  }

  return iVar1;

}

/* ===== AudioDataStreamStatus__Fv_2 @ 0x00476DC0 ===== */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */



undefined4 AudioDataStreamStatus__Fv_2(void)



{

  return 0x1b;

}

/* ===== marker_get_name @ 0x00476DD0 ===== */
char * marker_get_name(int param_1,int param_2)



{

  int iVar1;

  char *pcVar2;

  

  if (param_2 == 0) {

    return s____Uninitialized____0055bc04;

  }

  if ((param_2 < 0) || (0x1b < param_2)) {

    return s____Unused____0055bb78;

  }

  if (*(int *)(param_1 + 0x1e0) == 0x60) {

    iVar1 = *(int *)(param_1 + 4);

    if (iVar1 == 0x44a) {

      param_2 = param_2 + -1;

      pcVar2 = s_Buoy_d_0055bbfc;

    }

    else if (iVar1 == 0x48a) {

      if (param_2 < 10) {

        pcVar2 = s_Army_Platoon__d_0055bbec;

      }

      else if (param_2 < 0xc) {

        pcVar2 = s_Flying_Patrol__d_0055bbd8;

      }

      else if (param_2 < 0xe) {

        pcVar2 = s_Sniper__d_0055bbcc;

      }

      else if (param_2 < 0x10) {

        pcVar2 = s_Ripper__d_0055bbc0;

      }

      else if (param_2 < 0x13) {

        pcVar2 = s_Kamikaze__d_0055bbb4;

      }

      else {

        pcVar2 = s_Army_Generic__d_0055bba4;

      }

    }

    else {

      if (iVar1 == 0x41c) goto LAB_00476e62;

      pcVar2 = s_Unknown__But_Usable___d__0055bb88;

    }

    crt_sprintf(&DAT_0059dca8,pcVar2,param_2);

    return &DAT_0059dca8;

  }

LAB_00476e62:

  return *(char **)(&DAT_0055b9d4 + param_2 * 4);

}

/* ===== showchat_mission_objective__Fi @ 0x00476E90 ===== */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

/* PS2 candidate: showchat_mission_objective__Fi (conf 0.383) */



undefined4 showchat_mission_objective__Fi(int p0)



{

  if ((0 < p0) && (p0 < 0x1c)) {

    return *(undefined4 *)(s_MissionObjective_0055b954 + p0 * 4 + 0x10);

  }

  return 0xffffff;

}

/* ===== FUN_00476eb0 @ 0x00476EB0 ===== */
void FUN_00476eb0(int param_1)



{

  int iVar1;

  undefined4 *puVar2;

  int iVar3;

  

  iVar3 = -1;

  iVar1 = param_1;

  for (puVar2 = DAT_00632d68; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {

    iVar1 = puVar2[3];

    if (((((*(uint *)(iVar1 + 0x1c8) & 0x8000000) != 0) && (iVar1 != param_1)) &&

        (*(int *)(iVar1 + 0xe8) == *(int *)(param_1 + 0xe8))) &&

       ((*(int *)(iVar1 + 4) == *(int *)(param_1 + 4) && (iVar3 < *(int *)(iVar1 + 0x174))))) {

      iVar3 = *(int *)(iVar1 + 0x174);

    }

  }

  *(int *)(param_1 + 0x174) = iVar3 + 1;

  if (((*(int *)(param_1 + 0x1e0) == 0x60) && (*(int *)(param_1 + 4) == *(int *)(iVar1 + 4))) &&

     (puVar2 = DAT_00632d68, DAT_00632d68 != (undefined4 *)0x0)) {

    while( true ) {

      iVar1 = puVar2[3];

      if ((((((*(uint *)(iVar1 + 0x1c8) & 0x8000000) != 0) &&

            ((*(uint *)(iVar1 + 0x1c8) & 0x20000000) != 0)) &&

           (*(int *)(iVar1 + 0xe8) == *(int *)(param_1 + 0xe8))) &&

          ((*(int *)(iVar1 + 0xe8) != 0 && (*(int *)(iVar1 + 0x174) == 0)))) &&

         ((-1 < (char)((uint)*(undefined4 *)(iVar1 + 0xd8) >> 8) &&

          (*(int *)(param_1 + 4) == *(int *)(iVar1 + 4))))) break;

      puVar2 = (undefined4 *)*puVar2;

      if (puVar2 == (undefined4 *)0x0) {

        return;

      }

    }

    *(int *)(*(int *)(param_1 + 0x100) + 0x40) = iVar1;

  }

  return;

}

/* ===== spawn_marker_scan_b @ 0x00476F90 ===== */
void spawn_marker_scan_b(int param_1)



{

  int iVar1;

  undefined4 *puVar2;

  

  for (puVar2 = DAT_00632d68; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {

    iVar1 = puVar2[3];

    if (((((*(uint *)(iVar1 + 0x1c8) & 0x8000000) != 0) && (iVar1 != param_1)) &&

        (*(int *)(iVar1 + 0xe8) == *(int *)(param_1 + 0xe8))) &&

       ((*(int *)(iVar1 + 4) == *(int *)(param_1 + 4) &&

        (*(int *)(param_1 + 0x174) <= *(int *)(iVar1 + 0x174))))) {

      *(int *)(iVar1 + 0x174) = *(int *)(iVar1 + 0x174) + 1;

    }

  }

  return;

}

/* ===== spawn_marker_scan_a @ 0x00476FF0 ===== */
void spawn_marker_scan_a(int param_1)



{

  int iVar1;

  undefined4 *puVar2;

  

  for (puVar2 = DAT_00632d68; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {

    iVar1 = puVar2[3];

    if (((((*(uint *)(iVar1 + 0x1c8) & 0x8000000) != 0) && (iVar1 != param_1)) &&

        (*(int *)(iVar1 + 0xe8) == *(int *)(param_1 + 0xe8))) &&

       ((*(int *)(iVar1 + 4) == *(int *)(param_1 + 4) &&

        (*(int *)(param_1 + 0x174) < *(int *)(iVar1 + 0x174))))) {

      *(int *)(iVar1 + 0x174) = *(int *)(iVar1 + 0x174) + -1;

    }

  }

  return;

}

/* ===== showchat_mission_objective__Fi_2 @ 0x00477050 ===== */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

/* PS2 candidate: showchat_mission_objective__Fi_2 (conf 0.383) */



void showchat_mission_objective__Fi_2(int p0)



{

  int *piVar1;

  undefined4 *puVar2;

  int iVar3;

  int iVar4;

  undefined4 uVar5;

  int iVar6;

  int iVar7;

  float *pfVar8;

  int iVar9;

  int iStack_98;

  float fStack_88;

  float fStack_84;

  float fStack_80;

  int iStack_7c;

  undefined4 local_78;

  undefined4 local_74;

  undefined4 local_70;

  undefined4 local_6c;

  undefined4 local_68;

  undefined4 local_64;

  undefined4 local_60;

  undefined4 local_5c;

  undefined4 local_58;

  undefined4 local_54;

  undefined4 local_50;

  undefined4 local_4c;

  undefined4 local_48;

  undefined4 local_44;

  undefined4 local_40;

  undefined4 local_3c;

  undefined4 uStack_38;

  int iStack_34;

  int iStack_28;

  undefined1 auStack_1c [16];

  float fStack_c;

  

  piVar1 = *(int **)(p0 + 0x100);

  local_78 = 0x3f800000;

  local_74 = 0;

  local_70 = 0;

  local_6c = 0;

  local_68 = 0;

  local_64 = 0x3f800000;

  local_60 = 0;

  local_5c = 0;

  local_58 = 0;

  local_54 = 0;

  local_50 = 0x3f800000;

  local_4c = 0;

  local_48 = 0;

  local_44 = 0;

  local_40 = 0;

  local_3c = 0x3f800000;

  if ((((*(int *)(p0 + 0x174) == 0) && (piVar1 != (int *)0x0)) && (piVar1[1] != 0)) &&

     (*piVar1 != 0)) {

    (**(code **)(DAT_00656420 + 0x18))(DAT_00656420,&local_78);

    puVar2 = (undefined4 *)(**(code **)(DAT_00656420 + 0xc))(DAT_00656420,0,0x100,10);

    (**(code **)(DAT_00656430 + 0x10))(DAT_00656430,1);

    iVar6 = *(int *)(p0 + 0xe8);

    if ((iVar6 < 1) || (0x1b < iVar6)) {

      uVar5 = 0xffffff;

    }

    else {

      uVar5 = *(undefined4 *)(s_MissionObjective_0055b954 + iVar6 * 4 + 0x10);

    }

    (*(code *)puVar2[1])(puVar2,0,1);

    (**(code **)(DAT_00656430 + 8))(DAT_00656430,0x20000,0,uVar5);

    iVar6 = 0;

    if (*(int *)(p0 + 4) == 0x48a) {

      iVar4 = piVar1[3];

    }

    else {

      iVar4 = piVar1[2];

    }

    iStack_7c = iVar4 / 16000;

    iStack_98 = iVar4;

    while (1 < iStack_7c) {

      iVar9 = iStack_7c;

      if (0x100 < iStack_7c) {

        iVar9 = 0x100;

      }

      iVar3 = (*(code *)puVar2[4])(puVar2,iVar9);

      iVar7 = 0;

      if (0 < iVar9) {

        pfVar8 = (float *)(iVar3 + 8);

        do {

          iStack_34 = iStack_98;

          uStack_38 = 0;

          iStack_28 = iVar6;

          ObjectUpdateSpeedDist(piVar1[1],&uStack_38,&fStack_88);

          pfVar8[-2] = fStack_88;

          pfVar8[-1] = fStack_84;

          ground_height_at(&fStack_88,auStack_1c);

          if (fStack_c <= fStack_80) {

            *pfVar8 = fStack_80;

          }

          else {

            *pfVar8 = fStack_c;

          }

          iVar6 = iVar6 + 16000;

          if (iVar4 <= iVar6) {

            (*(code *)puVar2[5])(puVar2,iVar9 - iVar7);

            break;

          }

          iVar7 = iVar7 + 1;

          pfVar8 = pfVar8 + 6;

        } while (iVar7 < iVar9);

      }

      if (iVar4 <= iVar6) break;

      iVar6 = iVar6 + -16000;

      iStack_98 = iStack_98 + 16000;

    }

    (*(code *)puVar2[0xb])(puVar2);

    (*(code *)puVar2[2])(puVar2);

    (*(code *)*puVar2)(puVar2);

  }

  return;

}

/* ===== cspec_004772d0 @ 0x004772D0 ===== */
void cspec_004772d0(int param_1)



{

  int *piVar1;

  

  piVar1 = *(int **)(param_1 + 0x100);

  if (piVar1[0x11] != 0) {

    mem_free_tagged(piVar1[0x11],s_C__Giants_source_main_marker_c_0055bc18,0x10b);

  }

  piVar1[0x11] = 0;

  if (*piVar1 != 0) {

    map_alloc_cleanup(*piVar1);

  }

  *piVar1 = 0;

  piVar1[1] = 0;

  if (piVar1[0x15] != 0) {

    object_destroy(piVar1[0x15]);

  }

  piVar1[0x15] = 0;

  if (piVar1[0x16] != 0) {

    object_destroy(piVar1[0x16]);

  }

  piVar1[0x16] = 0;

  return;

}

/* ===== marker_spline_adjust_buoy @ 0x00477340 ===== */
/* PS2 candidate: marker_spline_adjust_buoy (conf 0.6) */



void marker_spline_adjust_buoy(int param_1)



{

  float fVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  float fVar6;

  undefined4 uVar7;

  int iVar8;

  int iVar9;

  float10 fVar10;

  

  if (*(int *)(param_1 + 4) == 0x44a) {

    iVar2 = *(int *)(*(int *)(*(int *)(param_1 + 0x100) + 0x40) + 0x100);

    iVar8 = 0;

    iVar9 = 0;

    if (*(int *)(iVar2 + 0x3c) != 1 && -1 < *(int *)(iVar2 + 0x3c) + -1) {

      do {

        if (*(int *)(iVar2 + 0x44) != 0) {

          iVar3 = *(int *)(*(int *)(iVar2 + 0x44) + iVar9 * 4);

          iVar4 = *(int *)(iVar3 + 0x100);

          iVar5 = *(int *)(iVar4 + 0x54);

          if (*(float *)(iVar3 + 0xf8) == 0.0) {

            if (iVar5 == 0) {

              uVar7 = object_allocate_type(0x449,0x80000000);

              *(undefined4 *)(iVar4 + 0x54) = uVar7;

            }

            if (*(int *)(iVar4 + 0x58) == 0) {

              uVar7 = object_allocate_type(0x449,0x80000000);

              *(undefined4 *)(iVar4 + 0x58) = uVar7;

            }

            *(undefined4 *)(*(int *)(iVar4 + 0x54) + 0xe4) = 0;

            *(undefined4 *)(*(int *)(iVar4 + 0x58) + 0xe4) = 0;

            fVar1 = *(float *)(iVar4 + 0x24);

            fVar6 = *(float *)(iVar4 + 0x20);

            iVar3 = *(int *)(*(int *)(iVar2 + 0x44) + iVar9 * 4);

            *(float *)(*(int *)(iVar4 + 0x54) + 0xa0) =

                 -fVar1 * *(float *)(iVar3 + 0xfc) + *(float *)(iVar3 + 0xa0);

            iVar3 = *(int *)(*(int *)(iVar2 + 0x44) + iVar9 * 4);

            *(float *)(*(int *)(iVar4 + 0x54) + 0xa4) =

                 fVar6 * *(float *)(iVar3 + 0xfc) + *(float *)(iVar3 + 0xa4);

            fVar10 = (float10)get_floor_z_point(*(int *)(iVar4 + 0x54) + 0xa0);

            *(float *)(*(int *)(iVar4 + 0x54) + 0xa8) = (float)fVar10;

            if (*(float *)(*(int *)(iVar4 + 0x54) + 0xa8) < 0.0) {

              *(undefined4 *)(*(int *)(iVar4 + 0x54) + 0xa8) = 0;

            }

            *(int *)(*(int *)(iVar4 + 0x54) + 0x174) = iVar8;

            *(undefined4 *)(*(int *)(iVar4 + 0x54) + 0xe8) =

                 *(undefined4 *)(*(int *)(*(int *)(iVar2 + 0x44) + iVar9 * 4) + 0xe8);

            *(undefined4 *)(*(int *)(iVar4 + 0x54) + 200) =

                 *(undefined4 *)(*(int *)(*(int *)(iVar2 + 0x44) + iVar9 * 4) + 200);

            iVar3 = *(int *)(*(int *)(iVar2 + 0x44) + iVar9 * 4);

            *(float *)(*(int *)(iVar4 + 0x58) + 0xa0) =

                 *(float *)(iVar3 + 0xa0) - -fVar1 * *(float *)(iVar3 + 0xfc);

            iVar3 = *(int *)(*(int *)(iVar2 + 0x44) + iVar9 * 4);

            *(float *)(*(int *)(iVar4 + 0x58) + 0xa4) =

                 *(float *)(iVar3 + 0xa4) - fVar6 * *(float *)(iVar3 + 0xfc);

            fVar10 = (float10)get_floor_z_point(*(int *)(iVar4 + 0x58) + 0xa0);

            *(float *)(*(int *)(iVar4 + 0x58) + 0xa8) = (float)fVar10;

            if (*(float *)(*(int *)(iVar4 + 0x58) + 0xa8) < 0.0) {

              *(undefined4 *)(*(int *)(iVar4 + 0x58) + 0xa8) = 0;

            }

            *(int *)(*(int *)(iVar4 + 0x58) + 0x174) = iVar8 + 1;

            *(undefined4 *)(*(int *)(iVar4 + 0x58) + 0xe8) =

                 *(undefined4 *)(*(int *)(*(int *)(iVar2 + 0x44) + iVar9 * 4) + 0xe8);

            *(undefined4 *)(*(int *)(iVar4 + 0x58) + 200) =

                 *(undefined4 *)(*(int *)(*(int *)(iVar2 + 0x44) + iVar9 * 4) + 200);

            iVar3 = *(int *)(iVar4 + 0x54);

            object_set_location(iVar3,*(undefined4 *)(iVar3 + 0xa0),*(undefined4 *)(iVar3 + 0xa4),

                                *(undefined4 *)(iVar3 + 0xa8));

            iVar3 = *(int *)(iVar4 + 0x58);

            object_set_location(iVar3,*(undefined4 *)(iVar3 + 0xa0),*(undefined4 *)(iVar3 + 0xa4),

                                *(undefined4 *)(iVar3 + 0xa8));

            iVar8 = iVar8 + 2;

          }

          else {

            if (iVar5 != 0) {

              object_destroy(iVar5);

            }

            if (*(int *)(iVar4 + 0x58) != 0) {

              object_destroy(*(int *)(iVar4 + 0x58));

            }

            *(undefined4 *)(iVar4 + 0x54) = 0;

            *(undefined4 *)(iVar4 + 0x58) = 0;

          }

        }

        iVar9 = iVar9 + 1;

      } while (iVar9 < *(int *)(iVar2 + 0x3c) + -1);

    }

  }

  return;

}

/* ===== marker_path_create @ 0x004775E0 ===== */
void marker_path_create(int param_1)



{

  int iVar1;

  int iVar2;

  undefined4 *puVar3;

  

  if (*(int *)(param_1 + 0xe4) == 0) {

    iVar1 = *(int *)(param_1 + 0x100);

    for (puVar3 = DAT_00632d68; puVar3 != (undefined4 *)0x0; puVar3 = (undefined4 *)*puVar3) {

      iVar2 = puVar3[3];

      if ((((((*(uint *)(iVar2 + 0x1c8) & 0x8000000) != 0) &&

            ((*(uint *)(iVar2 + 0x1c8) & 0x20000000) != 0)) &&

           (*(int *)(iVar2 + 0xe8) == *(int *)(param_1 + 0xe8))) &&

          ((*(int *)(iVar2 + 0xe8) != 0 && (*(int *)(iVar2 + 0x174) == 0)))) &&

         ((-1 < (char)((uint)*(undefined4 *)(iVar2 + 0xd8) >> 8) &&

          (*(int *)(param_1 + 4) == *(int *)(iVar2 + 4))))) {

        *(int *)(iVar1 + 0x40) = iVar2;

        break;

      }

    }

    if (*(int *)(iVar1 + 0x38) == 0) {

      *(undefined4 *)(iVar1 + 0x10) = 0x3f800000;

      *(undefined4 *)(iVar1 + 0x14) = 0x3f800000;

    }

    if (*(int *)(iVar1 + 0x40) != 0) {

      *(undefined4 *)(param_1 + 0xe4) = 1;

    }

  }

  else {

    if (*(int *)(param_1 + 0xe4) == 1) {

      marker_create_path__FP6OBJECTi(param_1,0);

      *(undefined4 *)(param_1 + 0xe4) = 2;

      return;

    }

    if ((DAT_00632e74 != 0) && (*(int *)(param_1 + 0x174) == 0)) {

      marker_create_path__FP6OBJECTi(param_1,0);

      return;

    }

  }

  return;

}

/* ===== marker_spline_adjust_scale @ 0x00477DA0 ===== */
/* PS2 candidate: marker_spline_adjust_scale (conf 0.436) */



void marker_spline_adjust_scale(int param_1,float param_2,int param_3)



{

  int iVar1;

  int iVar2;

  int *piVar3;

  undefined4 uVar4;

  int iVar5;

  int iVar6;

  undefined4 uVar7;

  

  iVar1 = *(int *)(param_1 + 0x100);

  iVar2 = *(int *)(*(int *)(iVar1 + 0x40) + 0x100);

  piVar3 = *(int **)(iVar2 + 0x44);

  iVar5 = 0;

  do {

    if (*piVar3 == param_1) break;

    iVar5 = iVar5 + 1;

    piVar3 = piVar3 + 1;

  } while (-1 < iVar5);

  if (param_3 == 0) {

    param_2 = param_2 + *(float *)(iVar1 + 0x14);

    *(float *)(iVar1 + 0x14) = param_2;

    if (param_2 < 0.0) {

      *(undefined4 *)(iVar1 + 0x14) = 0;

    }

    iVar6 = *(int *)(*(int *)(iVar2 + 4) + 0xc + iVar5 * 4);

    *(float *)(iVar6 + 0x14) = *(float *)(iVar1 + 0x2c) * *(float *)(iVar1 + 0x14) * 0.001;

    *(float *)(iVar6 + 0x18) = *(float *)(iVar1 + 0x30) * *(float *)(iVar1 + 0x14) * 0.001;

    *(float *)(iVar6 + 0x1c) = *(float *)(iVar1 + 0x34) * *(float *)(iVar1 + 0x14) * 0.001;

    if (*(float *)(iVar1 + 0x14) <= 0.0) goto LAB_00477eaf;

    uVar4 = *(undefined4 *)(iVar1 + 0x1c);

    *(undefined4 *)(iVar1 + 0x1c) = 0;

    uVar7 = 0;

  }

  else {

    param_2 = param_2 + *(float *)(iVar1 + 0x10);

    *(float *)(iVar1 + 0x10) = param_2;

    if (param_2 < 0.0) {

      *(undefined4 *)(iVar1 + 0x10) = 0;

    }

    iVar6 = *(int *)(*(int *)(iVar2 + 4) + 0xc + iVar5 * 4);

    *(float *)(iVar6 + 8) = *(float *)(iVar1 + 0x20) * *(float *)(iVar1 + 0x10) * 0.001;

    *(float *)(iVar6 + 0xc) = *(float *)(iVar1 + 0x24) * *(float *)(iVar1 + 0x10) * 0.001;

    *(float *)(iVar6 + 0x10) = *(float *)(iVar1 + 0x28) * *(float *)(iVar1 + 0x10) * 0.001;

    if (*(float *)(iVar1 + 0x10) <= 0.0) goto LAB_00477eaf;

    uVar4 = *(undefined4 *)(iVar1 + 0x18);

    *(undefined4 *)(iVar1 + 0x18) = 0;

    uVar7 = 1;

  }

  marker_spline_rotate_tangent(param_1,uVar4,uVar7);

LAB_00477eaf:

  if (iVar5 == 0) {

    iVar2 = *(int *)(*(int *)(iVar2 + 4) + 8 + *(int *)(iVar2 + 0x3c) * 4);

    *(undefined4 *)(iVar2 + 8) = *(undefined4 *)(iVar6 + 8);

    *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(iVar6 + 0xc);

    *(undefined4 *)(iVar2 + 0x10) = *(undefined4 *)(iVar6 + 0x10);

    *(undefined4 *)(iVar2 + 0x14) = *(undefined4 *)(iVar6 + 0x14);

    *(undefined4 *)(iVar2 + 0x18) = *(undefined4 *)(iVar6 + 0x18);

    *(undefined4 *)(iVar2 + 0x1c) = *(undefined4 *)(iVar6 + 0x1c);

  }

  marker_spline_adjust_buoy(*(undefined4 *)(iVar1 + 0x40));

  return;

}

/* ===== marker_spline_adjust_location @ 0x00477F00 ===== */
void marker_spline_adjust_location(int param_1)



{

  marker_create_path__FP6OBJECTi(*(undefined4 *)(*(int *)(param_1 + 0x100) + 0x40),1);

  return;

}

/* ===== marker_spline_rotate_tangent @ 0x00477F20 ===== */
/* PS2 candidate: marker_spline_rotate_tangent (conf 0.562) */



void marker_spline_rotate_tangent(int param_1,float param_2,int param_3)



{

  int iVar1;

  int iVar2;

  int *piVar3;

  int iVar4;

  int iVar5;

  undefined4 local_50;

  undefined4 uStack_4c;

  undefined4 uStack_48;

  undefined1 local_44 [68];

  

  iVar1 = *(int *)(param_1 + 0x100);

  iVar2 = *(int *)(*(int *)(iVar1 + 0x40) + 0x100);

  piVar3 = *(int **)(iVar2 + 0x44);

  iVar5 = 0;

  do {

    if (*piVar3 == param_1) break;

    iVar5 = iVar5 + 1;

    piVar3 = piVar3 + 1;

  } while (-1 < iVar5);

  if (param_3 == 0) {

    if (*(float *)(iVar1 + 0x14) == 0.0) {

      return;

    }

    iVar4 = *(int *)(*(int *)(iVar2 + 4) + 0xc + iVar5 * 4);

    *(float *)(iVar1 + 0x1c) = param_2 + *(float *)(iVar1 + 0x1c);

    GEO_MatFromQuat_2(local_44,param_2 * 0.017453292);

    (*(code *)PTR_S_GEO_Vec3Transform_00580c20)(&local_50,(undefined4 *)(iVar4 + 0x14),1,local_44);

    *(undefined4 *)(iVar4 + 0x14) = local_50;

    *(undefined4 *)(iVar4 + 0x18) = uStack_4c;

    *(undefined4 *)(iVar4 + 0x1c) = uStack_48;

  }

  else {

    if (*(float *)(iVar1 + 0x10) == 0.0) {

      return;

    }

    iVar4 = *(int *)(*(int *)(iVar2 + 4) + 0xc + iVar5 * 4);

    *(float *)(iVar1 + 0x18) = param_2 + *(float *)(iVar1 + 0x18);

    GEO_MatFromQuat_2(local_44,param_2 * 0.017453292);

    (*(code *)PTR_S_GEO_Vec3Transform_00580c20)(&local_50,(undefined4 *)(iVar4 + 8),1,local_44);

    *(undefined4 *)(iVar4 + 8) = local_50;

    *(undefined4 *)(iVar4 + 0xc) = uStack_4c;

    *(undefined4 *)(iVar4 + 0x10) = uStack_48;

  }

  if (iVar5 == 0) {

    iVar2 = *(int *)(*(int *)(iVar2 + 4) + 8 + *(int *)(iVar2 + 0x3c) * 4);

    *(undefined4 *)(iVar2 + 8) = *(undefined4 *)(iVar4 + 8);

    *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(iVar4 + 0xc);

    *(undefined4 *)(iVar2 + 0x10) = *(undefined4 *)(iVar4 + 0x10);

    *(undefined4 *)(iVar2 + 0x14) = *(undefined4 *)(iVar4 + 0x14);

    *(undefined4 *)(iVar2 + 0x18) = *(undefined4 *)(iVar4 + 0x18);

    *(undefined4 *)(iVar2 + 0x1c) = *(undefined4 *)(iVar4 + 0x1c);

  }

  marker_spline_adjust_buoy(*(undefined4 *)(iVar1 + 0x40));

  return;

}

/* ===== ai_move_ground_common @ 0x00478080 ===== */
undefined4

ai_move_ground_common(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)



{

  int iVar1;

  int iVar2;

  int iVar3;

  undefined4 *puVar4;

  int iVar5;

  undefined4 local_1c;

  undefined4 local_18;

  int local_c;

  

  iVar1 = *(int *)(param_1 + 0x100);

  if (1 < *(int *)(param_1 + 0xe4)) {

    iVar5 = *(int *)(iVar1 + 8);

    iVar2 = __ftol();

    iVar2 = iVar2 % iVar5;

    iVar3 = __ftol();

    iVar3 = iVar3 % iVar5;

    local_1c = 0;

    local_18 = *(undefined4 *)(iVar1 + 8);

    local_c = iVar2;

    ObjectUpdateSpeedDist(*(undefined4 *)(iVar1 + 4),&local_1c,param_4);

    if (iVar2 < iVar3) {

      return *(undefined4 *)(*(int *)(iVar1 + 0x44) + -4 + *(int *)(iVar1 + 0x3c) * 4);

    }

    iVar5 = 0;

    if (0 < *(int *)(iVar1 + 0x3c)) {

      puVar4 = (undefined4 *)(*(int *)(iVar1 + 4) + 0xc);

      do {

        if ((iVar3 < *(int *)*puVar4) && (*(int *)*puVar4 <= iVar2)) {

          return *(undefined4 *)(*(int *)(iVar1 + 0x44) + iVar5 * 4);

        }

        iVar5 = iVar5 + 1;

        puVar4 = puVar4 + 1;

      } while (iVar5 < *(int *)(iVar1 + 0x3c));

    }

  }

  return 0;

}

/* ===== ai_move_ground_step @ 0x00478160 ===== */
int ai_move_ground_step(int param_1,int *param_2)



{

  float *pfVar1;

  int iVar2;

  uint uVar3;

  float10 fVar4;

  undefined1 local_1c [16];

  float local_c;

  

  fVar4 = (float10)FUN_00518b70(param_1,0);

  iVar2 = param_2[2];

  pfVar1 = (float *)(param_1 + 0xa0);

  fVar4 = fVar4 * (float10)(float)param_2[3] + (float10)(float)param_2[2];

  param_2[2] = (int)(float)fVar4;

  iVar2 = ai_move_ground_common(*param_2,(float)fVar4,iVar2,pfVar1);

  ground_height_at(pfVar1,local_1c);

  if (*(int *)(*(int *)(*param_2 + 0x100) + 0x48) == 0) {

    *(float *)(param_1 + 0xa8) = local_c;

  }

  else if (*(float *)(param_1 + 0xa8) < local_c) {

    *(float *)(param_1 + 0xa8) = local_c;

  }

  if ((*(float *)(param_1 + 0xb8) != *pfVar1) ||

     (*(float *)(param_1 + 0xbc) != *(float *)(param_1 + 0xa4))) {

    fVar4 = (float10)dirfcalcp3d__FP3P3DT0(param_1 + 0xb8,pfVar1);

    *(float *)(param_1 + 200) = (float)fVar4;

  }

  if (iVar2 != 0) {

    if (*(int *)(*(int *)(iVar2 + 0x100) + 0x4c) == 0) {

      uVar3 = param_2[4] & 0xfffffffd;

    }

    else {

      uVar3 = param_2[4] | 2;

    }

    param_2[4] = uVar3;

    param_2[3] = *(int *)(iVar2 + 0xfc);

  }

  return iVar2;

}

/* ===== formation_update_info @ 0x00478260 ===== */
/* PS2 candidate: formation_update_info (conf 0.595) */



void formation_update_info(int param_1)



{

  int iVar1;

  undefined4 *puVar2;

  uint uVar3;

  

  puVar2 = DAT_00632d68;

  if (*(int *)(param_1 + 0x174) == 0) {

    for (; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {

      if ((*(int *)(puVar2[3] + 0x1e0) == 0x61) &&

         (iVar1 = *(int *)(puVar2[3] + 0x100), *(int *)(iVar1 + 0x18) == param_1)) {

        if (*(int *)(*(int *)(param_1 + 0x100) + 0x48) == 0) {

          uVar3 = *(uint *)(iVar1 + 0x28) & 0xfffffffe;

        }

        else {

          uVar3 = *(uint *)(iVar1 + 0x28) | 1;

        }

        *(uint *)(iVar1 + 0x28) = uVar3;

        *(undefined4 *)(iVar1 + 0x24) = *(undefined4 *)(param_1 + 0xfc);

      }

    }

  }

  return;

}

/* ===== formation_notify_death @ 0x004782D0 ===== */
/* PS2 candidate: formation_notify_death (conf 0.776) */



void formation_notify_death(int param_1)



{

  int *piVar1;

  

  piVar1 = (int *)(*(int *)(param_1 + 0x100) + 4);

  *piVar1 = *piVar1 + -1;

  if (*piVar1 == 0) {

    *(undefined4 *)(param_1 + 0xe4) = 3;

  }

  return;

}

/* ===== FUN_004782f0 @ 0x004782F0 ===== */
void FUN_004782f0(int param_1)



{

  int iVar1;

  int iVar2;

  undefined4 *puVar3;

  

  puVar3 = DAT_00632d68;

  do {

    if (puVar3 == (undefined4 *)0x0) {

      return;

    }

    iVar1 = puVar3[3];

    if (*(int *)(iVar1 + 0x1e0) == 0x33) {

      iVar2 = *(int *)(*(int *)(iVar1 + 0x100) + 0x134);

LAB_0047832a:

      if (iVar2 == param_1) {

        object_destroy(iVar1);

      }

    }

    else if (*(int *)(iVar1 + 0x1e0) == 0x27) {

      iVar2 = *(int *)(*(int *)(iVar1 + 0x100) + 0x14);

      goto LAB_0047832a;

    }

    puVar3 = (undefined4 *)*puVar3;

  } while( true );

}

/* ===== spawnling_ai_c97 @ 0x00478340 ===== */
void spawnling_ai_c97(int param_1)



{

  int iVar1;

  int iVar2;

  undefined4 *puVar3;

  int iVar4;

  uint uVar5;

  undefined4 uVar6;

  int iVar7;

  int iVar8;

  int *piVar9;

  int *piVar10;

  bool bVar11;

  int iStack_58;

  undefined4 uStack_50;

  undefined4 uStack_4c;

  undefined4 uStack_48;

  int aiStack_44 [17];

  

  iVar2 = param_1;

  if (DAT_00632e74 == 0) {

    iVar1 = *(int *)(param_1 + 0xe4);

    if (iVar1 == 0) {

      iVar2 = *(int *)(param_1 + 0xfc);

      iVar1 = *(int *)(param_1 + 0x100);

      *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) | 0x40000010;

      iVar7 = iVar1;

      for (puVar3 = DAT_00632d68; puVar3 != (undefined4 *)0x0; puVar3 = (undefined4 *)*puVar3) {

        iVar8 = puVar3[3];

        if (((*(int *)(iVar8 + 0x1e0) == 0x60) &&

            (*(int *)(iVar8 + 4) == (-(uint)(iVar2 != 0) & 0x6e) + 0x41c)) &&

           (-1 < (char)((uint)*(undefined4 *)(iVar8 + 0xd8) >> 8))) {

          iVar4 = __ftol();

          if ((*(int *)(iVar8 + 0xe8) == iVar4) && (*(int *)(iVar8 + 0x174) == 0)) {

            if (*(int *)(*(int *)(iVar8 + 0x100) + 0x48) == 0) {

              uVar5 = *(uint *)(iVar7 + 0x28) & 0xfffffffe;

            }

            else {

              uVar5 = *(uint *)(iVar7 + 0x28) | 1;

            }

            *(uint *)(iVar7 + 0x28) = uVar5;

            *(int *)(iVar7 + 0x18) = iVar8;

          }

          iVar4 = __ftol();

          if ((*(int *)(iVar8 + 0xe8) == iVar4) &&

             (*(int *)(iVar8 + 0x174) == *(int *)(iVar7 + 0xc))) {

            iVar7 = *(int *)(param_1 + 0x100);

            *(float *)(iVar7 + 0x20) = (float)*(int *)(*(int *)(iVar8 + 0x100) + 0x50);

            ai_move_ground_step(param_1,iVar7 + 0x18);

          }

        }

      }

      if (*(int *)(iVar1 + 0x18) != 0) {

        if (*(int *)(param_1 + 0xfc) != 0) {

          *(undefined4 *)(iVar1 + 0x24) = *(undefined4 *)(*(int *)(iVar1 + 0x18) + 0xfc);

          *(undefined4 *)(param_1 + 0xe4) = 3;

          return;

        }

        *(undefined4 *)(param_1 + 0xe4) = 1;

        return;

      }

    }

    else {

      if (iVar1 == 1) {

        iVar1 = *(int *)(param_1 + 0x100);

        piVar9 = aiStack_44;

        for (iVar7 = 0x11; iVar7 != 0; iVar7 = iVar7 + -1) {

          *piVar9 = 0;

          piVar9 = piVar9 + 1;

        }

        iVar7 = 0;

        do {

          if (*(int *)(param_1 + 0x2d8) <= iVar7) break;

          iVar8 = 0x11;

          bVar11 = true;

          piVar9 = (int *)(iVar7 * 0x44 + *(int *)(param_1 + 0x2dc));

          piVar10 = aiStack_44;

          do {

            if (iVar8 == 0) break;

            iVar8 = iVar8 + -1;

            bVar11 = *piVar9 == *piVar10;

            piVar9 = piVar9 + 1;

            piVar10 = piVar10 + 1;

          } while (bVar11);

          if (!bVar11) {

            piVar9 = (int *)(*(int *)(param_1 + 0x100) + 4);

            *piVar9 = *piVar9 + 1;

            iVar8 = object_allocate_type(0x23f,0x80000000);

            playerobj_eval_refpt(param_1,iVar7,&uStack_50);

            object_set_location(iVar8,uStack_50,uStack_4c,uStack_48);

            if ((*(uint *)(param_1 + 0xd8) & 0x400) != 0) {

              *(uint *)(iVar8 + 0xd8) = *(uint *)(iVar8 + 0xd8) | 0x400;

            }

            *(uint *)(iVar8 + 0xdc) = *(uint *)(iVar8 + 0xdc) | *(uint *)(param_1 + 0xdc) & 0xf;

            if (iVar7 < 5) {

              if (iVar7 == 4) {

                uVar6 = object_spawn_small(iVar8,2,0,0,0);

                object_change_ospec(uVar6,0);

                anim_select_check(uVar6,0xd6);

              }

            }

            else {

              uVar6 = object_spawn_small(iVar8,0x24a,1,0,0);

              uVar6 = object_spawn_small(uVar6,0x271,0,0,0);

              iVar4 = object_spawn_small(uVar6,0xd7,2,3,0);

              *(undefined4 *)(iVar4 + 0xe8) = 7;

            }

            iVar4 = *(int *)(iVar8 + 0x100);

            *(int *)(iVar4 + 0x14) = param_1;

            *(int *)(iVar4 + 0x18) = iVar7;

            *(undefined4 *)(iVar8 + 0xe8) = 2;

          }

          iVar7 = iVar7 + 1;

        } while (iVar7 < 10);

        param_1 = 0;

        iStack_58 = 10;

        iVar7 = 0x2a8;

        do {

          if (*(int *)(iVar2 + 0x2d8) <= iStack_58) break;

          iVar8 = 0x11;

          bVar11 = true;

          piVar9 = (int *)(*(int *)(iVar2 + 0x2dc) + iVar7);

          piVar10 = aiStack_44;

          do {

            if (iVar8 == 0) break;

            iVar8 = iVar8 + -1;

            bVar11 = *piVar9 == *piVar10;

            piVar9 = piVar9 + 1;

            piVar10 = piVar10 + 1;

          } while (bVar11);

          if (!bVar11) {

            func_0x00478710(iVar2,iStack_58,param_1);

            param_1 = param_1 + 1;

          }

          iStack_58 = iStack_58 + 1;

          iVar7 = iVar7 + 0x44;

        } while (iVar7 < 0x550);

        iVar7 = 0x14;

        do {

          if (*(int *)(iVar2 + 0x2d8) <= iVar7) break;

          iVar7 = iVar7 + 1;

        } while (iVar7 < 0x1e);

        iStack_58 = 0x1e;

        iVar7 = 0x7f8;

        do {

          if (*(int *)(iVar2 + 0x2d8) <= iStack_58) break;

          iVar8 = 0x11;

          bVar11 = true;

          piVar9 = (int *)(*(int *)(iVar2 + 0x2dc) + iVar7);

          piVar10 = aiStack_44;

          do {

            if (iVar8 == 0) break;

            iVar8 = iVar8 + -1;

            bVar11 = *piVar9 == *piVar10;

            piVar9 = piVar9 + 1;

            piVar10 = piVar10 + 1;

          } while (bVar11);

          if (!bVar11) {

            func_0x00478710(iVar2,iStack_58,param_1);

            param_1 = param_1 + 1;

          }

          iStack_58 = iStack_58 + 1;

          iVar7 = iVar7 + 0x44;

        } while (iVar7 < 0xaa0);

        *(undefined4 *)(iVar1 + 0x24) = *(undefined4 *)(*(int *)(iVar1 + 0x18) + 0xfc);

        *(undefined4 *)(iVar2 + 0xe4) = 2;

        return;

      }

      if (iVar1 == 2) {

        puVar3 = *(undefined4 **)(param_1 + 0x100);

        uVar6 = ai_move_ground_step(param_1,puVar3 + 6);

        *puVar3 = uVar6;

      }

    }

  }

  return;

}

/* ===== cspec_004787f0 @ 0x004787F0 ===== */
void cspec_004787f0(int param_1)



{

  int *piVar1;

  int iVar2;

  undefined4 *puVar3;

  int iVar4;

  float10 fVar5;

  

  piVar1 = *(int **)(param_1 + 0x100);

  if (DAT_00632e74 == 0) {

    if (*(int *)(param_1 + 0xe4) == 0) {

      DAT_00632e74 = 0;

      puVar3 = DAT_00632d68;

      while( true ) {

        if (puVar3 == (undefined4 *)0x0) {

          object_destroy(param_1);

          return;

        }

        iVar2 = puVar3[3];

        if ((((*(int *)(iVar2 + 0x1e0) == 0x60) && (*(int *)(iVar2 + 4) == 0x41c)) &&

            (*(int *)(iVar2 + 0x174) == 0)) && (iVar4 = __ftol(), *(int *)(iVar2 + 0xe8) == iVar4))

        break;

        puVar3 = (undefined4 *)*puVar3;

      }

      *piVar1 = iVar2;

      piVar1[1] = -1;

      piVar1[3] = *(int *)(iVar2 + 0xfc);

      *(undefined4 *)(param_1 + 0xe4) = 1;

      return;

    }

    ai_move_ground_step(param_1,piVar1);

    ObjectCalculateTransform(param_1);

    *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) | 0x20;

    fVar5 = (float10)FUN_00518b70(param_1,0);

    object_animate_process(param_1,(float)fVar5);

    *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) | 0x40;

  }

  return;

}

/* ===== cspec_004788d0 @ 0x004788D0 ===== */
undefined4 cspec_004788d0(void)



{

  return 0x14;

}

/* ===== mecc_play_weapon_select_snd @ 0x004788E0 ===== */
/* PS2 candidate: mecc_play_weapon_select_snd (conf 0.437) */



void mecc_play_weapon_select_snd(undefined4 param_1,undefined4 param_2)



{

  switch(param_2) {

  case 1:

    sound_play_player();

    return;

  default:

    return;

  case 3:

    sound_play_player();

    return;

  case 5:

    sound_play_player();

    return;

  case 6:

    sound_play_player();

    return;

  case 7:

    sound_play_player();

    return;

  case 0xe:

    sound_play_player();

    return;

  case 0xf:

    sound_play_player();

    return;

  case 0x10:

    sound_play_player();

    return;

  }

}

/* ===== getfirelockandgun__FP6OBJECTUcPP6OBJECTPi @ 0x004789E0 ===== */
/* PS2 candidate: getfirelockandgun__FP6OBJECTUcPP6OBJECTPi (conf 0.386) */



void getfirelockandgun__FP6OBJECTUcPP6OBJECTPi

               (int param_1,char param_2,int *param_3,undefined4 *param_4)



{

  int iVar1;

  undefined4 *puVar2;

  int *piVar3;

  int iVar4;

  

  iVar4 = 0;

  if ((param_2 == '\x02') || (param_2 == '\r')) {

    *param_4 = 0;

  }

  else {

    puVar2 = DAT_00632d70;

    if (param_2 == '\x18') {

      for (; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {

        iVar1 = puVar2[3];

        if ((((*(uint *)(iVar1 + 0xd8) & 0x8000) == 0) && (*(int *)(iVar1 + 4) == 0x3df)) &&

           (*(int *)(iVar1 + 0x210) == param_1)) {

          *param_4 = 2;

          iVar4 = iVar1;

          break;

        }

      }

    }

    else if ((*(uint *)(param_1 + 0xe0) & 0x100) == 0) {

      iVar4 = gun_find_right(param_1);

      *param_4 = 1;

    }

    else {

      iVar4 = gun_find_left();

      *param_4 = 1;

    }

  }

  piVar3 = (int *)PROJ_DefGet(param_2);

  if ((iVar4 != 0) && (*(int *)(iVar4 + 4) != *piVar3)) {

    *param_3 = iVar4;

    return;

  }

  *param_4 = 1;

  *param_3 = param_1;

  return;

}

/* ===== new_fire__FP6OBJECTiPfT0P3P3Df @ 0x00478AD0 ===== */
/* PS2 candidate: new_fire__FP6OBJECTiPfT0P3P3Df (conf 0.605) */



int new_fire__FP6OBJECTiPfT0P3P3Df

              (float param_1,uint param_2,float *param_3,int param_4,float *param_5,float param_6)



{

  float fVar1;

  uint uVar2;

  float *pfVar3;

  int iVar4;

  int iVar5;

  char cVar6;

  uint uVar7;

  float10 fVar8;

  undefined4 uVar9;

  float *local_4c;

  undefined4 local_48;

  int local_44;

  undefined1 local_40 [4];

  float local_3c;

  float local_38;

  float *local_34;

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

  char local_4;

  

  uVar2 = param_2;

  uVar7 = param_2 & 0xff;

  local_44 = PROJ_DefGet(uVar7);

  pfVar3 = param_3;

  fVar1 = param_1;

  if (((local_44 == 0) || (((~*(uint *)(local_44 + 4) & 1) == 0 && (param_4 == 0)))) ||

     ((param_3 != (float *)0x0 && (*param_3 < 0.0 == (*param_3 == 0.0))))) {

    return 0;

  }

  getfirelockandgun__FP6OBJECTUcPP6OBJECTPi(param_1,uVar2,&param_2,&local_48);

  cVar6 = (char)uVar2;

  if (uVar2 == 0x2d) {

    playerobj_eval_refpt(fVar1,10,&local_24);

    local_30 = *param_5;

    local_2c = param_5[1];

    local_28 = param_5[2];

  }

  else {

    playerobj_eval_refpt(param_2,local_48,&local_24);

    if (param_4 != 0) {

      local_30 = *param_5;

      local_2c = param_5[1];

      local_28 = param_5[2];

      goto LAB_00478c22;

    }

    iVar4 = project_cursor_to_ground(&local_30,param_6,local_40);

    if (*(int *)((int)fVar1 + 0x174) == 0) {

      iVar5 = camera_is_sniper();

      pfVar3 = param_3;

      if (iVar5 == 0) {

        if ((*(int *)((int)fVar1 + 0x174) != 0) || (iVar4 == 0)) goto LAB_00478d28;

      }

      else if (iVar4 == 0) {

        pfVar3 = (float *)XFGetCameraAxis(2);

        local_3c = *pfVar3;

        local_38 = pfVar3[1];

        local_34 = (float *)pfVar3[2];

        local_30 = local_3c * param_6 + local_24;

        local_2c = local_38 * param_6 + local_20;

        goto LAB_00478c12;

      }

    }

    else {

LAB_00478d28:

      param_5 = *(float **)((int)fVar1 + 0xd4);

      if (85.0 < (float)param_5) {

        param_5 = (float *)0x42aa0000;

      }

      sine_cos_lookup(*(undefined4 *)((int)fVar1 + 200),&local_3c,&local_38);

      local_38 = -local_38;

      sine_cos_lookup(param_5,&local_4c,&param_1);

      local_3c = param_1 * local_3c;

      local_34 = local_4c;

      local_38 = param_1 * local_38;

      local_30 = local_3c * param_6 + local_24;

      local_2c = local_38 * param_6 + local_20;

LAB_00478c12:

      local_28 = (float)local_34 * param_6 + local_1c;

      pfVar3 = param_3;

    }

LAB_00478c22:

    if ((cVar6 == '\x10') || (cVar6 == '\x18')) {

      fVar8 = (float10)rndfloat(0x43b40000,&local_3c,&local_38);

      sine_cos_lookup((float)fVar8);

      local_38 = -local_38;

      fVar8 = (float10)rndfloat(0x43b40000,&param_3,&param_6);

      sine_cos_lookup((float)fVar8);

      local_3c = param_6 * local_3c;

      local_38 = param_6 * local_38;

      local_34 = param_3;

      fVar8 = (float10)distance3d__FP3P3DT0(&local_24,&local_30);

      fVar8 = fVar8 * (float10)0.01;

      local_30 = (float)((float10)local_3c * fVar8 + (float10)local_30);

      local_2c = (float)((float10)local_38 * fVar8 + (float10)local_2c);

      local_28 = (float)(fVar8 * (float10)(float)local_34 + (float10)local_28);

      playerobj_eval_refpt(param_2,0,&local_18);

    }

  }

  if (uVar2 == 0x2d) {

    iVar4 = PROJ_Create2(0x2d,*(undefined4 *)((int)fVar1 + 0x18c),fVar1,10,0,&local_30);

LAB_00478e0d:

                    /* WARNING (jumptable): Sanity check requires truncation of jumptable */

                    /* WARNING: Could not find normalized switch variable to match jumptable */

    switch((&DAT_00478f30)[uVar2]) {

    case 0:

      uVar9 = 0xe;

      break;

    case 1:

      uVar9 = 0xb;

      break;

    case 2:

      uVar9 = 0xc;

      break;

    case 3:

      uVar9 = 1;

      break;

    case 4:

      uVar9 = 0xf;

      break;

    case 5:

      goto switchD_00478e15_caseD_5;

    }

  }

  else {

    iVar4 = PROJ_Create2(uVar7,*(undefined4 *)((int)fVar1 + 0x18c),param_2,local_48,param_4,

                         &local_30);

    if (uVar2 < 0x2e) goto LAB_00478e0d;

switchD_00478e15_caseD_5:

    uVar9 = 0;

  }

  ANM_DumpCluster(fVar1,uVar9);

  if (iVar4 != 0) {

    *(float *)(iVar4 + 0x274) = fVar1;

    iVar5 = reaper_0052e4a0(fVar1);

    if (iVar5 != 0) {

      local_c = 0;

      if (param_4 != 0) {

        local_c = *(undefined4 *)(param_4 + 0x188);

      }

      local_14 = local_2c;

      local_18 = local_30;

      local_8 = *(undefined4 *)(iVar4 + 0x188);

      local_10 = local_28;

      local_4 = cVar6;

      reaper_00530bd0(fVar1,3,2,1,0x10,&local_18);

    }

  }

  DAT_00632b40 = fVar1;

  DAT_00632b44 = DAT_006328e8;

  DAT_00632b48 = *(undefined4 *)((int)fVar1 + 0xa0);

  DAT_00632b4c = *(undefined4 *)((int)fVar1 + 0xa4);

  DAT_00632b50 = *(undefined4 *)((int)fVar1 + 0xa8);

  if (pfVar3 != (float *)0x0) {

    *pfVar3 = *(float *)(local_44 + 0x44) + *pfVar3;

  }

  if ((uVar2 != 2) && (uVar2 != 0xd)) {

    *(uint *)((int)fVar1 + 0xdc) = *(uint *)((int)fVar1 + 0xdc) | 0x20;

  }

  sound_player_sequence(fVar1,uVar2);

  return iVar4;

}

/* ===== sound_player_sequence @ 0x00478F60 ===== */
/* PS2 candidate: mecc_play_fire_snd__FP6OBJECTi (conf 0.515) */



void sound_player_sequence(int param_1,undefined4 param_2)



{

  int iVar1;

  undefined4 uVar2;

  int iVar3;

  

  iVar3 = *(int *)(param_1 + 0x100);

  switch(param_2) {

  case 0:

    sound_play_player(0x5e8,param_1);

    break;

  case 1:

    sound_play_player(0x5c9,param_1);

    return;

  case 2:

  case 0xd:

    sound_play_player(0x58f,param_1);

    return;

  case 3:

    sound_play_player(0x1ac,param_1);

    return;

  case 4:

    sound_play_player(0x5a4,param_1);

    return;

  case 5:

    sound_play_player(0x5d4,param_1);

    return;

  case 6:

    sound_play_player(0x5da,param_1);

    return;

  case 0x11:

  case 0x2a:

    iVar3 = crt_rand_scaled(100);

    if (iVar3 < 0x32) {

      sound_play_player(0x5f7,param_1);

      return;

    }

    sound_play_player(0x5f8,param_1);

    return;

  case 0x18:

    if (*(int *)(iVar3 + 0x1fc) == 0) {

      iVar1 = reaper_0052e4a0(param_1);

      if (iVar1 != 0) {

        reaper_00530bd0(param_1,0,0,0,0x21,0);

      }

      uVar2 = sound_get_free_sequence__Fv();

      *(undefined4 *)(iVar3 + 0x1fc) = uVar2;

      return;

    }

    break;

  case 0x2d:

    sound_play_player(0x680,param_1);

    return;

  }

  return;

}

/* ===== mecc_calculate_mass__FP6OBJECT @ 0x00479100 ===== */
/* PS2 candidate: mecc_calculate_mass__FP6OBJECT (conf 0.656) */



void mecc_calculate_mass__FP6OBJECT(int param_1)



{

  uint *puVar1;

  int iVar2;

  undefined4 uVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  

  iVar2 = param_1;

  iVar6 = 0;

  iVar7 = 0;

  do {

    uVar3 = FUN_004582d0(param_1,iVar7);

    iVar4 = IconDef_entry_ptr(uVar3);

    iVar4 = *(int *)(iVar4 + 0x18);

    uVar3 = FUN_00457fb0(param_1,iVar7);

    iVar5 = IconDef_entry_ptr(uVar3);

    iVar6 = iVar6 + iVar4 + *(int *)(iVar5 + 0x18);

    iVar7 = iVar7 + 1;

  } while (iVar7 < 3);

  iVar7 = SpecialWeaponIdGet__FP6OBJECT(param_1);

  if (0 < iVar7) {

    uVar3 = SpecialWeaponIdGet__FP6OBJECT(param_1);

    iVar7 = IconDef_entry_ptr(uVar3);

    iVar6 = iVar6 + *(int *)(iVar7 + 0x18);

  }

  iVar7 = DAT_00632ed8;

  puVar1 = (uint *)(param_1 + 0xdc);

  param_1 = iVar6;

  if ((*puVar1 & 0x800000) != 0) {

    param_1 = iVar6 + 1;

  }

  if ((*(uint *)(iVar2 + 0xe0) & 0x20000) != 0) {

    iVar6 = __ftol();

    param_1 = param_1 + iVar6;

  }

  if ((*(int *)(iVar2 + 0x104) != 0) && (*(int *)(iVar2 + 0x174) == 0)) {

    *(float *)(*(int *)(iVar2 + 0x104) + 8) = *(float *)(iVar7 + 0x678) + (float)param_1;

    *(float *)(*(int *)(iVar2 + 0x104) + 4) =

         (*(float *)(DAT_00632ed8 + 0x674) * *(float *)(*(int *)(iVar2 + 0x104) + 8)) /

         *(float *)(DAT_00632ed8 + 0x678);

  }

  return;

}

/* ===== MeccPhysicsExApplyLocation__FP6OBJECT @ 0x004791F0 ===== */
/* PS2 candidate: MeccPhysicsExApplyLocation__FP6OBJECT (conf 0.389) */



void MeccPhysicsExApplyLocation__FP6OBJECT(int param_1)



{

  uint uVar1;

  undefined4 *puVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  int local_28 [10];

  

  iVar3 = param_1;

  iVar6 = 0;

  if ((*(float *)(param_1 + 0x1c0) <= *(float *)(param_1 + 0x278)) &&

     (*(float *)(param_1 + 0xa8) < 0.0 != (*(float *)(param_1 + 0xa8) == 0.0))) {

    iVar4 = *(int *)(param_1 + 0x210);

    *(undefined4 *)(param_1 + 0x210) = 1;

    param_1 = iVar4;

  }

  iVar4 = dialog_level_is_base();

  puVar2 = DAT_00632d70;

  if (iVar4 == 0) {

    for (; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {

      iVar4 = puVar2[3];

      iVar5 = ObjIsMecc(iVar4);

      if ((iVar5 != 0) && (*(int *)(iVar4 + 0x174) != 0)) {

        uVar1 = *(uint *)(iVar4 + 0x1c8);

        local_28[iVar6] = iVar4;

        iVar6 = iVar6 + 1;

        *(uint *)(iVar4 + 0x1c8) = uVar1 | 0x800;

      }

    }

    PhysicsExApplyLocation(iVar3);

    for (; iVar6 != 0; iVar6 = iVar6 + -1) {

      *(uint *)(local_28[iVar6 + -1] + 0x1c8) = *(uint *)(local_28[iVar6 + -1] + 0x1c8) & 0xfffff7ff

      ;

    }

  }

  else {

    PhysicsExApplyLocation(iVar3);

  }

  if ((*(float *)(iVar3 + 0x1c0) <= *(float *)(iVar3 + 0x278)) &&

     (*(float *)(iVar3 + 0xa8) < 0.0 != (*(float *)(iVar3 + 0xa8) == 0.0))) {

    *(int *)(iVar3 + 0x210) = param_1;

    ObjectCalculateTransform(iVar3);

  }

  return;

}

/* ===== mecc_init__FP6OBJECT @ 0x00479300 ===== */
void mecc_init__FP6OBJECT(int param_1)



{

  int iVar1;

  

  iVar1 = *(int *)(param_1 + 0x100);

  if (*(int *)(iVar1 + 200) != DAT_00632ed0) {

    *(int *)(iVar1 + 200) = DAT_00632ed0;

    if (*(int *)(param_1 + 0x104) == 0) {

      *(int *)(param_1 + 0x104) = iVar1 + 0x80;

      PhysicsExZeroForce(param_1);

      if (**(int **)(param_1 + 8) != 0x85) {

        *(undefined4 *)(iVar1 + 400) = 0x42c80000;

      }

    }

    *(undefined4 *)(*(int *)(param_1 + 0x104) + 4) = *(undefined4 *)(DAT_00632ed8 + 0x674);

    *(undefined4 *)(*(int *)(param_1 + 0x104) + 8) = *(undefined4 *)(DAT_00632ed8 + 0x678);

    *(undefined4 *)(*(int *)(param_1 + 0x104) + 0x28) = *(undefined4 *)(DAT_00632ed8 + 0x67c);

    *(undefined4 *)(*(int *)(param_1 + 0x104) + 0xc) = *(undefined4 *)(DAT_00632ed8 + 0x680);

    *(undefined4 *)(*(int *)(param_1 + 0x104) + 0x30) = *(undefined4 *)(DAT_00632ed8 + 0x684);

    *(undefined4 *)(*(int *)(param_1 + 0x104) + 0x34) = *(undefined4 *)(DAT_00632ed8 + 0x5f0);

    *(undefined4 *)(*(int *)(param_1 + 0x104) + 0x38) = *(undefined4 *)(DAT_00632ed8 + 0x698);

    *(undefined4 *)(param_1 + 400) = *(undefined4 *)(DAT_00632ed8 + 0x688);

    *(undefined4 *)(param_1 + 0x194) = *(undefined4 *)(DAT_00632ed8 + 0x6d8);

    *(undefined4 *)(param_1 + 0x1a0) = *(undefined4 *)(DAT_00632ed8 + 0x68c);

  }

  return;

}

/* ===== mecc_ai_main @ 0x00479430 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void mecc_ai_main(int param_1)



{

  float *pfVar1;

  bool bVar2;

  undefined4 *puVar3;

  int iVar4;

  uint uVar5;

  char *pcVar6;

  undefined4 uVar7;

  int iVar8;

  undefined4 uVar9;

  int iVar10;

  int iVar11;

  float fVar12;

  char *pcVar13;

  float fVar14;

  undefined4 *puVar15;

  undefined4 *puVar16;

  char cVar17;

  float10 fVar18;

  float10 fVar19;

  undefined *puVar20;

  float fStack_1e8;

  float fStack_1e4;

  undefined4 *puStack_1e0;

  char cStack_1d9;

  float fStack_1d8;

  undefined4 uStack_1d4;

  float fStack_1d0;

  float fStack_1cc;

  float fStack_1c8;

  float fStack_1c4;

  float fStack_1c0;

  float fStack_1bc;

  undefined4 uStack_1b8;

  float fStack_1b4;

  float fStack_1b0;

  float fStack_1ac;

  undefined1 auStack_1a8 [4];

  undefined4 uStack_1a4;

  undefined4 uStack_1a0;

  float fStack_19c;

  undefined4 uStack_198;

  undefined4 uStack_194;

  int iStack_190;

  float fStack_18c;

  undefined4 uStack_188;

  undefined4 uStack_184;

  float fStack_17c;

  undefined1 auStack_164 [16];

  undefined1 auStack_154 [68];

  undefined1 auStack_110 [68];

  undefined1 auStack_cc [68];

  undefined1 auStack_88 [68];

  undefined1 auStack_44 [68];

  

  puVar3 = *(undefined4 **)(param_1 + 0x100);

  puStack_1e0 = puVar3;

  fStack_1d8 = (float)fx_create(param_1);

  if (DAT_00633124 != 0) {

    *(undefined4 *)(param_1 + 0x208) = 0;

    *(undefined4 *)(param_1 + 0x20c) = 0;

  }

  if (fStack_1d8 == 0.0) {

    fVar18 = (float10)FUN_00518b70(0,0);

    fVar14 = (float)puVar3[0x70];

    puVar3[0x70] = (float)(fVar18 + (float10)fVar14);

    if (DAT_00633210 == 0) {

      fVar19 = (float10)1.0;

    }

    else {

      fVar19 = (float10)0.5;

    }

    fVar19 = (fVar18 + (float10)fVar14) / fVar19;

    if (fVar19 < (float10)1.0 != (fVar19 == (float10)1.0)) {

      *(float *)(param_1 + 0xa0) =

           (float)(fVar19 * (float10)(float)puVar3[0x6d] + (float10)*(float *)(param_1 + 0xa0));

      *(float *)(param_1 + 0xa4) =

           (float)(fVar19 * (float10)(float)puVar3[0x6e] + (float10)*(float *)(param_1 + 0xa4));

      *(float *)(param_1 + 0xa8) =

           (float)(fVar19 * (float10)(float)puVar3[0x6f] + (float10)*(float *)(param_1 + 0xa8));

      fVar19 = (float10)1.0 - fVar19;

      puVar3[0x6d] = (float)(fVar19 * (float10)(float)puVar3[0x6d]);

      puVar3[0x6e] = (float)(fVar19 * (float10)(float)puVar3[0x6e]);

      puVar3[0x6f] = (float)(fVar19 * (float10)(float)puVar3[0x6f]);

      object_copy_posdirinfo(param_1);

    }

  }

  else {

    iVar4 = reaper_0052e4a0(param_1);

    if (iVar4 != 0) {

      fVar18 = (float10)FUN_00518b70(0,0);

      fVar18 = (float10)_DAT_0055bc44 - fVar18;

      _DAT_0055bc44 = (float)fVar18;

      if ((fVar18 < (float10)0.0 != (fVar18 == (float10)0.0)) && (*(int *)(param_1 + 0x104) != 0)) {

        puVar3 = (undefined4 *)

                 MemAllocMsg(0,0x220,s_meccweaponcheatfix_0055bce0,

                             s_C__Giants_source_main_mecc_c_0055bcf4,0x2d6);

        puVar15 = puStack_1e0;

        puVar16 = puVar3;

        for (iVar4 = 0x88; iVar4 != 0; iVar4 = iVar4 + -1) {

          *puVar16 = *puVar15;

          puVar15 = puVar15 + 1;

          puVar16 = puVar16 + 1;

        }

        puVar15 = puStack_1e0 + 0x20;

        puVar16 = puVar3 + 0x20;

        for (iVar4 = 0xf; iVar4 != 0; iVar4 = iVar4 + -1) {

          *puVar16 = *puVar15;

          puVar15 = puVar15 + 1;

          puVar16 = puVar16 + 1;

        }

        mem_free_tagged(puStack_1e0,s_C__Giants_source_main_mecc_c_0055bcf4,0x2d9);

        *(undefined4 **)(param_1 + 0x104) = puVar3 + 0x20;

        *(undefined4 **)(param_1 + 0x100) = puVar3;

        puStack_1e0 = puVar3;

        weapon_id_inventory_update();

        _DAT_0055bc44 = 20.0;

      }

    }

  }

  if (DAT_00633104 != 0) {

    if ((*(uint *)(param_1 + 0x20c) & 0x400) != 0) {

      *(uint *)(param_1 + 0x20c) = *(uint *)(param_1 + 0x20c) | 0x800;

    }

    if ((*(byte *)(param_1 + 0x20c) & 4) != 0) {

      iVar4 = player_can_use_ammo__FP6OBJECTi();

      if ((*(uint *)(param_1 + 0xe0) & 0x20000) == 0) {

        if ((iVar4 < 0x31) || (0x36 < iVar4)) {

          if (iVar4 == 0) {

            uVar5 = *(uint *)(param_1 + 0x20c) | 0x40;

          }

          else if (iVar4 == 8) {

            uVar5 = *(uint *)(param_1 + 0x20c) | 0x80;

          }

          else if (iVar4 == 9) {

            uVar5 = *(uint *)(param_1 + 0x20c) | 0x100;

          }

          else {

            if (iVar4 != 0x40) goto LAB_0047969b;

            uVar5 = *(uint *)(param_1 + 0x20c) | 0x200;

          }

        }

        else {

          uVar5 = *(uint *)(param_1 + 0x20c) | 8;

        }

      }

      else {

        uVar5 = *(uint *)(param_1 + 0x20c) | 0x80;

      }

      *(uint *)(param_1 + 0x20c) = uVar5;

    }

  }

LAB_0047969b:

  iVar4 = dialog_level_is_base();

  if ((((iVar4 != 0) && (iVar4 = FUN_0052c5c0(), iVar4 == 0)) && (DAT_00632a88 == param_1)) &&

     ((*(uint *)(param_1 + 0xe0) & 0x20000) != 0)) {

    fVar18 = (float10)FUN_00518b70(0,0);

    fVar14 = (float)puVar3[0x81];

    puVar3[0x81] = (float)((float10)fVar14 - fVar18);

    if ((float10)fVar14 - fVar18 < (float10)0.0) {

      puVar3[0x81] = 0x3f800000;

      for (puVar15 = DAT_00632d98; puVar15 != (undefined4 *)0x0; puVar15 = (undefined4 *)*puVar15) {

        iVar4 = puVar15[3];

        if (((*(int *)(iVar4 + 0xe8) == 10) &&

            (*(int *)(iVar4 + 0x18c) != *(int *)(param_1 + 0x18c))) &&

           ((*(int *)(iVar4 + 0x210) == 0 &&

            (fVar18 = (float10)FUN_0050a610(iVar4 + 0xa0,param_1 + 0xa0), fVar18 <= (float10)100.0))

           )) {

          pcVar6 = (char *)FUN_00507b00(s_FlagHintDriveGyro_0055bccc);

          pcVar13 = &DAT_00632c10;

          do {

            cVar17 = *pcVar6;

            pcVar6 = pcVar6 + 1;

            *pcVar13 = cVar17;

            pcVar13 = pcVar13 + 1;

          } while (cVar17 != '\0');

          _DAT_00632d10 = 0x3f8ccccd;

        }

      }

    }

  }

  if (*(int *)(param_1 + 0x174) == 0) {

    *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) | 0x10000000;

    fVar18 = (float10)FUN_00518b70(0,0);

    _DAT_0057a770 = (float)((float10)_DAT_0057a770 - fVar18);

  }

  fVar18 = (float10)FUN_00518b70(0,0);

  puVar3[0x80] = (float)((float10)(float)puVar3[0x80] - fVar18);

  if (((DAT_00632b90 != 0) && ((*(uint *)(param_1 + 0xd8) & 0x80000) != 0)) &&

     ((*(uint *)(param_1 + 0xe0) & 0x200000) == 0)) {

    fVar18 = (float10)world_ripple_xform(param_1 + 0xa0);

    if ((float10)*(float *)(DAT_00632ed8 + 0x1108) < fVar18 - (float10)*(float *)(param_1 + 0xa8)) {

      iVar4 = fx_create(param_1);

      if (iVar4 != 0) {

        obj_damage_apply(0x19,*(undefined4 *)(DAT_00632ed8 + 0x110c),param_1,0,param_1 + 0xa0,0);

      }

      *(undefined4 *)(param_1 + 0x130) = 0x41a00000;

      *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 0x200000;

    }

  }

  if ((DAT_00632ba8 != 0) && (param_1 == DAT_00632a88)) {

    *(uint *)(param_1 + 0x20c) = *(uint *)(param_1 + 0x20c) & 0xfffff072;

    *(undefined1 *)(param_1 + 0x209) = 0;

    *(undefined1 *)(param_1 + 0x20a) = 0;

    *(undefined1 *)(param_1 + 0x20b) = 0;

  }

  if ((*(uint *)(param_1 + 0xe0) & 0x20000) != 0) {

    *(uint *)(param_1 + 0x20c) = *(uint *)(param_1 + 0x20c) & 0xfffffff3;

  }

  mecc_init__FP6OBJECT(param_1);

  if ((*(byte *)(param_1 + 0xe0) & 0x40) != 0) {

    *(undefined1 *)(param_1 + 0x20a) = 0;

    *(undefined1 *)(param_1 + 0x20b) = 0;

    *(uint *)(param_1 + 0x20c) = *(uint *)(param_1 + 0x20c) & 0xfffffbfe;

  }

  mecc_calculate_mass__FP6OBJECT(param_1);

  fStack_1e4 = *(float *)(param_1 + 0x100);

  iVar4 = 0;

  if (((*(uint *)(param_1 + 0xdc) & 0x400000) != 0) && (*(int *)((int)fStack_1e4 + 0x18c) != 0x13))

  {

    uVar7 = IconDefWieldType(*(int *)((int)fStack_1e4 + 0x18c),1);

    iVar4 = player_find_weapon_obj_type__FP6OBJECTii(param_1,10,uVar7);

  }

  puVar15 = DAT_00632d98;

  if ((*(uint *)(param_1 + 0xdc) & 0x800000) != 0) {

    for (; puVar15 != (undefined4 *)0x0; puVar15 = (undefined4 *)*puVar15) {

      iVar8 = puVar15[3];

      iVar10 = *(int *)(iVar8 + 4);

      if (((((iVar10 == 0xb) || (iVar10 == 0x248)) || (iVar10 == 0x2e6)) || (iVar10 == 0xd8)) &&

         (((*(int *)(iVar8 + 0x210) == param_1 || (*(int *)(iVar8 + 0x274) == param_1)) &&

          (*(int *)(iVar8 + 0xe8) != 5)))) goto LAB_0047997c;

    }

  }

  iVar8 = 0;

  if (iVar4 != 0) {

LAB_0047997c:

    if ((*(uint *)(param_1 + 0xe0) & 0x20000) == 0) {

      if (iVar8 == 0) {

        if ((iVar4 != 0) && (*(int *)((int)fStack_1e4 + 0x18c) != 0x14)) {

          *(undefined4 *)(iVar4 + 0x184) = 0;

        }

        goto LAB_004799d1;

      }

      *(undefined4 *)(iVar8 + 0x184) = 0;

    }

    else if (iVar8 != 0) {

      *(undefined4 *)(iVar8 + 0x184) = 0x3f800000;

    }

    if (iVar4 != 0) {

      *(undefined4 *)(iVar4 + 0x184) = 0x3f800000;

    }

  }

LAB_004799d1:

  iVar4 = camera_is_sniper_2();

  if (((iVar4 == 0) || (iVar4 = WeaponIdGetPresent__FP6OBJECT(param_1), iVar4 != 6)) &&

     ((*(uint *)(param_1 + 0xe0) & 0x2020000) == 0)) {

    iVar4 = gun_find_left(param_1);

    if (iVar4 != 0) {

      *(uint *)(iVar4 + 0xd8) = *(uint *)(iVar4 + 0xd8) & 0xbfffffff;

    }

    iVar4 = gun_find_right(param_1);

    if (iVar4 != 0) {

      uVar5 = *(uint *)(iVar4 + 0xd8) & 0xbfffffff;

LAB_00479a50:

      *(uint *)(iVar4 + 0xd8) = uVar5;

    }

  }

  else {

    iVar4 = gun_find_left(param_1);

    if (iVar4 != 0) {

      *(uint *)(iVar4 + 0xd8) = *(uint *)(iVar4 + 0xd8) | 0x40000000;

    }

    iVar4 = gun_find_right(param_1);

    if (iVar4 != 0) {

      uVar5 = *(uint *)(iVar4 + 0xd8) | 0x40000000;

      goto LAB_00479a50;

    }

  }

  fVar18 = (float10)FUN_00518b70(param_1,0);

  puVar3[0x34] = (float)(fVar18 + (float10)(float)puVar3[0x34]);

  if (((*(int *)(param_1 + 0x174) == 0) && (fStack_1d8 != 0.0)) &&

     ((*(int *)(param_1 + 0x170) != 0 && ((DAT_00632ba8 == 0 && (DAT_00632bac == 0)))))) {

    cVar17 = '\0';

    if (DAT_00633104 == 0) {

      uVar5 = *(uint *)(param_1 + 0x20c) & 0x1000;

      puVar3[0x84] = uVar5;

      puVar3[0x85] = uVar5;

      if ((uVar5 != 0) && (iVar4 = FUN_00501090(), iVar4 == 0)) {

        uVar7 = FUN_00507b00(s_AIMeccPrefix_0055bcbc);

        FUN_00501100(uVar7);

      }

      if ((puVar3[0x84] != 0) && ((*(uint *)(param_1 + 0x20c) & 0x2000) != 0)) {

        cVar17 = '\x01';

      }

      if ((*(uint *)(param_1 + 0x20c) & 0x4000) != 0) {

        cVar17 = '\x02';

      }

      if ((puVar3[0x84] == 0) || (-1 < (char)(*(uint *)(param_1 + 0x20c) >> 8))) goto LAB_00479be6;

      cVar17 = '\x03';

    }

    else {

      puVar3[0x85] = puVar3[0x84];

      if ((*(uint *)(param_1 + 0x20c) & 0x1000) != 0) {

        puVar3[0x84] = (uint)(puVar3[0x84] == 0);

      }

      if (puVar3[0x84] != 0) {

        uVar7 = FUN_00507b00(s_AIMeccPrefix_0055bcbc);

        FUN_00501100(uVar7);

        if (puVar3[0x84] != 0) {

          cVar17 = (*(uint *)(param_1 + 0x20c) & 0x2000) != 0;

          if ((bool)cVar17) {

            puVar3[0x84] = 0;

          }

          if (puVar3[0x84] != 0) {

            if ((*(uint *)(param_1 + 0x20c) & 0x4000) != 0) {

              puVar3[0x84] = 0;

              cVar17 = '\x02';

            }

            if ((puVar3[0x84] != 0) && ((char)((uint)*(undefined4 *)(param_1 + 0x20c) >> 8) < '\0'))

            {

              puVar3[0x84] = 0;

              cVar17 = '\x03';

              goto LAB_00479bea;

            }

          }

        }

      }

LAB_00479be6:

      if (cVar17 == '\0') goto LAB_00479c1b;

    }

LAB_00479bea:

    iVar4 = reaper_0052e4a0(param_1);

    if (iVar4 != 0) {

      cStack_1d9 = cVar17;

      reaper_00530bd0(param_1,0,0,1,8,&cStack_1d9);

    }

    teammecc_set_mode(param_1,cVar17,1);

  }

LAB_00479c1b:

  iVar4 = puVar3[0x6b];

  if ((*(uint *)(param_1 + 0xd8) & 0x8000000) == 0) {

    if (iVar4 != 0) {

      fx_delete(iVar4);

    }

    puVar3[0x6b] = 0;

    fVar18 = (float10)FUN_00518b70(param_1,0);

    fVar14 = (float)puVar3[0x10];

    puVar3[0x10] = (float)((float10)fVar14 - fVar18);

    if ((float10)fVar14 - fVar18 < (float10)0.0) {

      puVar3[0x10] = 0;

    }

  }

  else {

    if (iVar4 == 0) {

      iStack_190 = param_1;

      uStack_194 = 0xffffffff;

      uStack_198 = 8;

      uVar7 = fx_get_free_effect__Fv();

      puVar3[0x6b] = uVar7;

    }

    fVar18 = (float10)FUN_00518b70(param_1,0);

    puVar3[0x10] = (float)(fVar18 + (float10)(float)puVar3[0x10]);

  }

  if (*(float *)(param_1 + 0x1c0) <= *(float *)(param_1 + 0x278)) {

    iVar4 = *(int *)(param_1 + 0x100);

    mecc_stop_looping_effects(param_1);

    *(undefined4 *)(iVar4 + 0x4c) = 0;

    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xffdfffff;

    iVar8 = fx_create(param_1);

    if (iVar8 != 0) {

      obj_swap_link(param_1);

      if ((*(byte *)(param_1 + 0xe0) & 0x20) != 0) {

        turret_exit_all_team(param_1);

        *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xffffffdf;

      }

      mecc_exit_bush(param_1);

      if (*(int *)(param_1 + 0x210) != 0) {

        *(undefined4 *)(param_1 + 0x210) = 0;

        *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) & 0xfff7ffff;

      }

      mecc_disable_personal_shield(param_1);

      mecc_disable_repair_gun(param_1);

    }

    *(undefined1 *)(param_1 + 0x20b) = 0;

    *(undefined1 *)(param_1 + 0x20a) = 0;

    if (*(int *)(param_1 + 0x174) != 0) {

      *(undefined1 *)(param_1 + 0x208) = 0;

      *(undefined1 *)(iVar4 + 0x138) = 0;

    }

    *(uint *)(param_1 + 0x20c) = *(uint *)(param_1 + 0x20c) & 0xfffffbff;

    mecc_jet(param_1);

    obj_alpha_fade_update(param_1);

    player_pitch_update(param_1);

    obj_vel_reset(param_1);

    obj_speed_sq_calc(param_1);

    MeccPhysicsExApplyLocation__FP6OBJECT(param_1);

    PhysicsExCalcControledModelSpeeds

              (param_1,*(undefined4 *)(DAT_00632ed8 + 0x660),*(undefined4 *)(DAT_00632ed8 + 0x65c));

    fVar18 = (float10)FUN_00518b70(param_1,0);

    object_animate_process(param_1,(float)fVar18);

    obj_gravity_apply(param_1,1);

    PhysicsExApplyMoveControls(param_1);

    objspec_dispatch_gate(param_1);

    object_animate_process(param_1,0);

    uVar5 = *(uint *)(param_1 + 0xd8);

    *(uint *)(param_1 + 0xd8) = uVar5 | 0x40;

    if (*(int *)(iVar4 + 0x108) != 0) {

      *(undefined4 *)(param_1 + 0x184) = 0x3f800000;

      *(uint *)(param_1 + 0xd8) = uVar5 | 0x40000040;

      fVar18 = (float10)atand2pos(*(undefined4 *)(param_1 + 300),*(undefined4 *)(param_1 + 0x128));

      uStack_1a4 = *(undefined4 *)(param_1 + 0xa0);

      uStack_1a0 = *(undefined4 *)(param_1 + 0xa4);

      fStack_19c = *(float *)(param_1 + 0xa8);

      fStack_18c = (float)((fVar18 - (float10)90.0) + (float10)180.0);

      uStack_188 = 0;

      uStack_184 = 0;

      fx_get_free_effect__Fv();

      if (*(int *)(iVar4 + 0x1a0) != 0) {

        fx_delete(*(int *)(iVar4 + 0x1a0));

        *(undefined4 *)(iVar4 + 0x1a0) = 0;

      }

      iVar8 = reaper_0052e4a0(param_1);

      if (iVar8 != 0) {

        item_drop_all_random(param_1);

        TeamMemberInitWeapons__FP6OBJECT(param_1);

      }

      *(undefined4 *)(iVar4 + 0x100) = 0;

      *(undefined4 *)(iVar4 + 0x108) = 0;

      if (*(int *)(param_1 + 0x174) != 0) {

        *(int *)(iVar4 + 0x10c) = *(int *)(iVar4 + 0x10c) + 1;

        *(undefined4 *)(param_1 + 0xf0) = 0x41700000;

        if (*(float *)(DAT_00632ed8 + 0xfb4) <= (float)*(int *)(iVar4 + 0x10c)) {

          uVar7 = TextGetPtrRandom(s_McChDead_0055bc90,5,0);

          puVar20 = (&PTR_DAT_0057a920)[*(int *)(param_1 + 0x174)];

        }

        else {

          uVar7 = TextGetPtrRandom(s_McChResting_0055bc9c,5,0);

          puVar20 = (&PTR_DAT_0057a920)[*(int *)(param_1 + 0x174)];

        }

        chat_insert_name(puVar20,uVar7);

      }

    }

    if ((**(char **)(param_1 + 0x104) < '\0') ||

       (*(float *)(param_1 + 0xa8) < 0.0 != (*(float *)(param_1 + 0xa8) == 0.0))) {

      fx_delete(*(undefined4 *)(iVar4 + 0xf4));

      *(undefined4 *)(iVar4 + 0xf4) = 0;

      if ((*(float *)(param_1 + 0xa8) < 0.0 != (*(float *)(param_1 + 0xa8) == 0.0)) ||

         ((*(int *)(param_1 + 0x10) == 0x8f && ((*(byte *)(param_1 + 0x30) & 2) != 0)))) {

        fVar18 = (float10)get_floor_z_point(param_1 + 0xa0);

        fStack_1d8 = (float)fVar18;

        fVar18 = (float10)FUN_00518b70(param_1,0);

        fVar18 = (float10)*(float *)(param_1 + 0xa8) - (fVar18 + fVar18);

        *(float *)(param_1 + 0xa8) = (float)fVar18;

        if (fVar18 < (float10)fStack_1d8) {

          *(float *)(param_1 + 0xa8) = fStack_1d8;

        }

      }

      if ((*(int *)(iVar4 + 0x104) != 0) && ((*(byte *)(param_1 + 0x30) & 2) != 0)) {

        *(undefined4 *)(param_1 + 0x184) = 0x3f800000;

        *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) | 0x40000000;

        if ((*(int *)(iVar4 + 0x100) == 0) && (iVar8 = corpse_create(param_1), iVar8 != 0)) {

          *(uint *)(iVar8 + 0xd8) = *(uint *)(iVar8 + 0xd8) | 0x10000;

          *(uint *)(iVar8 + 0xdc) = *(uint *)(iVar8 + 0xdc) | 0x1000;

          *(int *)(iVar8 + 0x210) = param_1;

          *(undefined4 *)(iVar8 + 0x218) = 0xffffffff;

          *(undefined4 *)(iVar8 + 0x214) = 0xffffffff;

        }

        *(undefined4 *)(iVar4 + 0x100) = 0;

        iVar8 = reaper_0052e4a0(param_1);

        if (iVar8 != 0) {

          item_drop_all_random(param_1);

          TeamMemberInitWeapons__FP6OBJECT(param_1);

        }

        if (*(int *)(param_1 + 0x174) != 0) {

          *(int *)(iVar4 + 0x10c) = *(int *)(iVar4 + 0x10c) + 1;

          *(undefined4 *)(param_1 + 0xf0) = 0x41700000;

          if (*(float *)(DAT_00632ed8 + 0xfb4) <= (float)*(int *)(iVar4 + 0x10c)) {

            uVar7 = TextGetPtrRandom(s_McChDead_0055bc90,5,0);

            puVar20 = (&PTR_DAT_0057a920)[*(int *)(param_1 + 0x174)];

          }

          else {

            uVar7 = TextGetPtrRandom(s_McChResting_0055bc9c,5,0);

            puVar20 = (&PTR_DAT_0057a920)[*(int *)(param_1 + 0x174)];

          }

          chat_insert_name(puVar20,uVar7);

        }

        *(undefined4 *)(iVar4 + 0x104) = 0;

      }

    }

    if (*(int *)(param_1 + 0x174) == 0) {

      iVar8 = fx_create(param_1);

      if (iVar8 == 0) {

        return;

      }

      if (DAT_00632f08 == 0) {

        voice_quota_check();

        return;

      }

      _DAT_00632b60 = _DAT_00632b60 + DAT_006328e0;

      if (_DAT_00632b60 <= 2.0) {

        return;

      }

      if ((*(byte *)(param_1 + 0x20c) & 1) == 0) {

        return;

      }

      iVar8 = reaper_0052e4a0(param_1);

      if (iVar8 != 0) {

        item_drop_all_random(param_1);

        TeamMemberInitWeapons__FP6OBJECT(param_1);

      }

      *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 0x100000;

      iVar8 = object_find(*(undefined4 *)(param_1 + 4));

      if (iVar8 != 0) {

        *(undefined4 *)(param_1 + 0xc4) = *(undefined4 *)(iVar8 + 0xc4);

      }

      cam_mode_full(param_1,*(undefined4 *)(iVar4 + 0x20c));

      return;

    }

    if (*(int *)(iVar4 + 0x108) != 0) {

      return;

    }

    if (*(int *)(iVar4 + 0x104) != 0) {

      return;

    }

    fVar18 = (float10)FUN_00518b70(0,0);

    fVar18 = (float10)*(float *)(param_1 + 0xf0) - fVar18;

    *(float *)(param_1 + 0xf0) = (float)fVar18;

    if (fVar18 < (float10)0.0 == (fVar18 == (float10)0.0)) {

      return;

    }

    if ((float)*(int *)(iVar4 + 0x10c) < *(float *)(DAT_00632ed8 + 0xfb4)) {

      iVar8 = object_find(*(undefined4 *)(param_1 + 4));

      if (iVar8 != 0) {

        *(undefined4 *)(param_1 + 0xc4) = *(undefined4 *)(iVar8 + 0xc4);

      }

      cam_mode_full(param_1,*(undefined4 *)(iVar4 + 0x20c));

      teammecc_clear_mode(param_1);

      uVar7 = TextGetPtrRandom(s_McChRevive_0055bc84,5,0);

      chat_insert_name((&PTR_DAT_0057a920)[*(int *)(param_1 + 0x174)],uVar7);

      return;

    }

    if (*(int *)(iVar4 + 0x1a0) != 0) {

      fx_delete(*(int *)(iVar4 + 0x1a0));

    }

    *(undefined4 *)(iVar4 + 0x1a0) = 0;

    return;

  }

  if (puVar3[0x3d] != 0) {

    fx_delete(puVar3[0x3d]);

    puVar3[0x3d] = 0;

  }

  uVar5 = *(uint *)(param_1 + 0xe0);

  if ((uVar5 & 0x20) != 0) {

    return;

  }

  if ((uVar5 & 0x8000000) != 0) {

    return;

  }

  if ((uVar5 & 0x2000000) != 0) {

    fStack_1d8 = *(float *)(param_1 + 400);

    uVar7 = *(undefined4 *)(param_1 + 0x1a8);

    fStack_1e4 = *(float *)(param_1 + 0x194);

    iVar4 = *(int *)(param_1 + 0x100);

    puStack_1e0 = *(undefined4 **)(param_1 + 0x1a4);

    *(float *)(param_1 + 0x194) = *(float *)(DAT_00632ed8 + 0x18) * *(float *)(param_1 + 0x194);

    *(float *)(param_1 + 400) = *(float *)(DAT_00632ed8 + 0x18) * *(float *)(param_1 + 400);

    *(float *)(param_1 + 0x1a8) = *(float *)(DAT_00632ed8 + 0x18) * *(float *)(param_1 + 0x1a8);

    *(float *)(param_1 + 0x1a4) = *(float *)(DAT_00632ed8 + 0x18) * *(float *)(param_1 + 0x1a4);

    obj_alpha_fade_update(param_1);

    player_pitch_update(param_1);

    obj_hover_update(param_1);

    obj_vel_reset(param_1);

    obj_speed_sq_calc(param_1);

    MeccPhysicsExApplyLocation__FP6OBJECT(param_1);

    PhysicsExCalcControledModelSpeeds

              (param_1,*(undefined4 *)(DAT_00632ed8 + 0x660),*(undefined4 *)(DAT_00632ed8 + 0x65c));

    fVar18 = (float10)FUN_00518b70(param_1,0);

    object_animate_process(param_1,(float)fVar18);

    mecc_do_health_grenade_mine2__FP6OBJECT(param_1);

    if ((*(char *)(param_1 + 0x20a) == '\0') && (*(char *)(param_1 + 0x20b) == '\0')) {

      uVar9 = 1;

    }

    else {

      uVar9 = 0;

    }

    obj_gravity_apply(param_1,uVar9);

    PhysicsExApplyMoveControls(param_1);

    objspec_dispatch_gate(param_1);

    object_animate_process(param_1,0);

    *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) | 0x40;

    mecc_smoking_fx_update(param_1);

    mecc_jet(param_1);

    *(float *)(param_1 + 0x194) = fStack_1e4;

    *(float *)(param_1 + 400) = fStack_1d8;

    *(undefined4 *)(param_1 + 0x1a8) = uVar7;

    *(undefined4 **)(param_1 + 0x1a4) = puStack_1e0;

    if (param_1 == DAT_00632a88) {

      fVar18 = (float10)FUN_00518b70(param_1,0);

      fVar18 = (float10)*(float *)(iVar4 + 400) - fVar18 * (float10)*(float *)(DAT_00632ed8 + 0x7f0)

      ;

      *(float *)(iVar4 + 400) = (float)fVar18;

      if (fVar18 < (float10)0.0 != (fVar18 == (float10)0.0)) {

        if (((*(uint *)(param_1 + 0xe0) & 0x2000000) != 0) &&

           ((*(uint *)(param_1 + 0xe0) & 0x4000000) == 0)) {

          iVar8 = reaper_0052e4a0(param_1);

          if (iVar8 != 0) {

            reaper_00530bd0(param_1,0,0,0,0xc,0);

          }

          *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 0x4000000;

          *(undefined4 *)(param_1 + 0x274) = 0;

          sound_play_player(0x572,param_1);

        }

        *(undefined4 *)(iVar4 + 400) = 0;

      }

    }

    iVar4 = fx_create(param_1);

    if ((((iVar4 != 0) && ((*(byte *)(param_1 + 0x20c) & 4) != 0)) &&

        ((*(uint *)(param_1 + 0xe0) & 0x2000000) != 0)) &&

       ((*(uint *)(param_1 + 0xe0) & 0x4000000) == 0)) {

      iVar4 = reaper_0052e4a0(param_1);

      if (iVar4 != 0) {

        reaper_00530bd0(param_1,0,0,0,0xc,0);

      }

      *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 0x4000000;

      *(undefined4 *)(param_1 + 0x274) = 0;

      sound_play_player(0x572,param_1);

    }

    reaper_lock_big(param_1);

    return;

  }

  if (*(int *)(param_1 + 0x210) != 0) {

    obj_alpha_fade_update(param_1);

    player_pitch_update(param_1);

    iVar4 = object_volume_sfx(param_1);

    if (iVar4 == 0) {

      mecc_fire_logic__FP6OBJECT(param_1);

    }

    obj_hover_update(param_1);

    mecc_smoking_fx_update(param_1);

    math_sincos_pair(puVar3,*(undefined4 *)(param_1 + 200),*(undefined4 *)(param_1 + 0xd4));

    mecc_do_health_grenade_mine2__FP6OBJECT(param_1);

    mecc_do_flare__FP6OBJECT(param_1);

    iVar4 = comm_send_gate_check(param_1);

    if (iVar4 == 0) {

      return;

    }

    puStack_1e0 = (undefined4 *)((uint)*(byte *)(param_1 + 0x208) << 0x10);

    comm_chat_send_2(param_1,0,0,4,3,&puStack_1e0);

    return;

  }

  if ((((*(uint *)(param_1 + 0xd8) & 0x8000000) != 0) &&

      (*(float *)(DAT_00632ed8 + 0x10) < (float)puVar3[0x10] !=

       (*(float *)(DAT_00632ed8 + 0x10) == (float)puVar3[0x10]))) && (fStack_1d8 != 0.0)) {

    puVar3[0x10] = *(float *)(DAT_00632ed8 + 0x3f8) + *(float *)(DAT_00632ed8 + 0x10);

    iVar4 = FUN_00494f90();

    if (iVar4 != 0) {

      fVar18 = (float10)FUN_00518b70(param_1,0);

      fVar18 = fVar18 + (float10)(float)puVar3[0x11];

      puVar3[0x11] = (float)fVar18;

      if ((float10)0.5 < fVar18) {

        obj_damage_apply(0x18,(float)((float10)*(float *)(DAT_00632ed8 + 0xc) * fVar18),param_1,0,

                         param_1 + 0xa0,0);

        puVar3[0x11] = 0;

      }

    }

  }

  if ((((float)puVar3[0x34] < 2.0) &&

      (((iVar4 = *(int *)(param_1 + 0x10), iVar4 == 0xb2 || (iVar4 == 0xb3)) || (iVar4 == 0xb4))))

     || ((((float)puVar3[0x34] < 1.0 &&

          (((iVar4 = *(int *)(param_1 + 0x10), iVar4 == 0xaf || (iVar4 == 0xb0)) || (iVar4 == 0xb1))

          )) || ((*(int *)(param_1 + 0x10) == 0xd9 || ((*(uint *)(param_1 + 0xe0) & 0x40000) != 0)))

         ))) {

    *(undefined1 *)(param_1 + 0x20b) = 0;

    *(undefined1 *)(param_1 + 0x20a) = 0;

    *(undefined1 *)(param_1 + 0x208) = 0;

    *(uint *)(param_1 + 0x20c) = *(uint *)(param_1 + 0x20c) & 0xfffffbfe;

  }

  if (((*(uint *)(param_1 + 0xe0) & 0x20000) != 0) && ((*(uint *)(param_1 + 0xd8) & 0x80000) != 0))

  {

    *(undefined1 *)(param_1 + 0x20b) = 0;

    *(undefined1 *)(param_1 + 0x20a) = 0;

    *(undefined1 *)(param_1 + 0x208) = 0;

  }

  iVar4 = FUN_0052c5c0();

  if ((((iVar4 != 0) && (puVar3[0x36] == 0)) && (iVar4 = base_find_closest(param_1), iVar4 != 0)) &&

     (iVar8 = object_spawn_class5(*(undefined4 *)(param_1 + 0x18c),iVar4), iVar8 != 0)) {

    puVar3[0x36] = iVar4;

  }

  ripper_control__FP6OBJECT(param_1);

  obj_alpha_fade_update(param_1);

  player_pitch_update(param_1);

  iVar4 = fx_logic(2,param_1);

  if (iVar4 == 0) {

    iVar4 = fx_logic(1,param_1);

    if (iVar4 != 0) {

      *(undefined1 *)(param_1 + 0x20b) = 0;

      *(undefined1 *)(param_1 + 0x20a) = 0;

      *(uint *)(param_1 + 0x20c) = *(uint *)(param_1 + 0x20c) & 0xfffffbfe;

    }

  }

  else {

    *(undefined4 *)(param_1 + 300) = 0;

    *(undefined4 *)(param_1 + 0x128) = 0;

  }

  if ((*(byte *)(param_1 + 0xe0) & 0x40) == 0) {

    obj_vel_reset(param_1);

    obj_speed_sq_calc(param_1);

    MeccPhysicsExApplyLocation__FP6OBJECT(param_1);

    PhysicsExCalcControledModelSpeeds

              (param_1,*(undefined4 *)(DAT_00632ed8 + 0x660),*(undefined4 *)(DAT_00632ed8 + 0x65c));

  }

  else {

    *(undefined4 *)(param_1 + 0x128) = 0;

    *(undefined4 *)(param_1 + 300) = 0;

    *(undefined4 *)(param_1 + 0x130) = 0;

  }

  math_sincos_pair(puVar3,*(undefined4 *)(param_1 + 200),*(undefined4 *)(param_1 + 0xd4));

  fVar18 = (float10)FUN_00518b70(param_1,0);

  object_animate_process(param_1,(float)fVar18);

  *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) | 0x40;

  if (((*(char *)(param_1 + 0x20a) == '\0') && (*(char *)(param_1 + 0x20b) == '\0')) &&

     ((*(uint *)(param_1 + 0x20c) & 0x400) == 0)) {

    uVar7 = 1;

  }

  else {

    uVar7 = 0;

  }

  obj_gravity_apply(param_1,uVar7);

  PhysicsExApplyMoveControls(param_1);

  iVar4 = object_volume_sfx(param_1);

  if (iVar4 == 0) {

    mecc_fire_logic__FP6OBJECT(param_1);

  }

  mecc_jet(param_1);

  iVar4 = *(int *)(param_1 + 0x100);

  if ((*(uint *)(param_1 + 0xe0) & 0x800000) != 0) {

    fVar18 = (float10)FUN_00518b70(param_1,0);

    fVar18 = (float10)*(float *)(iVar4 + 400) - fVar18 * (float10)*(float *)(DAT_00632ed8 + 0x82c);

    *(float *)(iVar4 + 400) = (float)fVar18;

    if (fVar18 < (float10)0.0 != (fVar18 == (float10)0.0)) {

      iVar8 = fx_create(param_1);

      if (iVar8 != 0) {

        mecc_disable_personal_shield(param_1);

      }

      *(undefined4 *)(iVar4 + 400) = 0;

    }

  }

  if (((*(uint *)(param_1 + 0xe0) & 0x6000000) != 0) || (iVar8 = fx_create(param_1), iVar8 == 0))

  goto LAB_0047aa16;

  if (((*(byte *)(param_1 + 0x20c) & 8) != 0) && ((*(uint *)(param_1 + 0xdc) & 0x800000) != 0)) {

    mecc_special_weapon_logic__FP6OBJECT(param_1);

  }

  if ((*(byte *)(param_1 + 0x20c) & 4) == 0) goto LAB_0047aa16;

  if (DAT_00633104 != 0) {

    uVar7 = player_can_use_ammo__FP6OBJECTi();

    iVar8 = IconDef_wield_eq3(uVar7);

    if (iVar8 == 0) goto LAB_0047aa16;

  }

  iVar8 = *(int *)(iVar4 + 0x18c);

  if (iVar8 < 0) goto LAB_0047aa16;

  if (**(char **)(param_1 + 0x104) < '\0') {

LAB_0047a9ce:

    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 0x40000;

    iVar8 = *(int *)(iVar4 + 0x18c);

    if ((iVar8 != 0x11) &&

       (((iVar8 != 0x14 && (iVar8 != 0x13)) && (iVar8 = reaper_0052e4a0(param_1), iVar8 != 0)))) {

      fStack_1e4 = *(float *)(iVar4 + 0x18c);

      reaper_00530bd0(param_1,0,1,0,0x16,&fStack_1e4);

    }

  }

  else {

    if (iVar8 != 10) {

      if ((iVar8 != 0xb) && (iVar8 != 0x14)) goto LAB_0047a9ce;

      if ((iVar8 != 10) && (iVar8 != 0xb)) goto LAB_0047aa16;

    }

    uVar7 = FUN_00507b00(s_PhErrNotOnSomething_0055bc70,1);

    chat_insert(uVar7);

  }

LAB_0047aa16:

  iVar4 = *(int *)(param_1 + 0x100);

  fVar18 = (float10)FUN_00518b70(0,0);

  fVar18 = fVar18 + (float10)*(float *)(iVar4 + 0x1d4);

  *(float *)(iVar4 + 0x1d4) = (float)fVar18;

  if ((float10)0.25 <= fVar18) {

    *(undefined4 *)(iVar4 + 0x1d4) = 0;

    for (puVar3 = DAT_00632d68; puVar3 != (undefined4 *)0x0; puVar3 = (undefined4 *)*puVar3) {

      iVar4 = puVar3[3];

      if ((((*(uint *)(iVar4 + 0xd8) & 0x8000) == 0) && (0x45c < *(int *)(iVar4 + 4))) &&

         ((*(int *)(iVar4 + 4) < 0x460 &&

          (((*(byte *)(iVar4 + 0xe0) & 1) != 0 &&

           (fVar18 = (float10)distancesq2d__FP3P3DT0(param_1 + 0xa0,iVar4 + 0xa0),

           fVar18 < (float10)100.0)))))) {

        sound_player_voice2(param_1,iVar4,*(undefined4 *)(iVar4 + 0xfc));

      }

    }

  }

  iVar4 = *(int *)(param_1 + 0x100);

  iVar8 = *(int *)(iVar4 + 0xd8);

  if (((iVar8 != 0) && (iVar10 = base_has_partyhouse(iVar8), iVar10 == 0)) &&

     (iVar10 = base_get_base_building(iVar8), iVar8 != iVar10)) {

    if (*(int *)(iVar4 + 0x54) != 0) {

      fVar14 = *(float *)(iVar4 + 0x58) * 0.33333334;

      bldg_get_refpt_worldloc(iVar10,0x53,&fStack_1b4);

      bldg_get_refpt_worldloc(iVar10,0x55,&fStack_1d0);

      fVar18 = (float10)1.0 - (float10)fVar14;

      fVar19 = (float10)fsin((float10)DAT_006328e8 * (float10)5.0);

      object_set_location(*(undefined4 *)(iVar4 + 0x54),

                          (float)((float10)fStack_1d0 * (float10)fVar14 +

                                 (float10)fStack_1b4 * fVar18),

                          (float)((float10)fStack_1cc * (float10)fVar14 +

                                 (float10)fStack_1b0 * fVar18),

                          (float)((float10)fStack_1c8 * (float10)fVar14 +

                                  (float10)fStack_1ac * fVar18 + fVar19 + (float10)3.0));

      fVar18 = (float10)FUN_00518b70(param_1,0);

      fVar18 = fVar18 + (float10)*(float *)(iVar4 + 0x58);

      *(float *)(iVar4 + 0x58) = (float)fVar18;

      if ((float10)3.0 <= fVar18) {

        object_destroy(*(undefined4 *)(iVar4 + 0x54));

        *(undefined4 *)(iVar4 + 0x54) = 0;

      }

    }

    iVar11 = fx_create(param_1);

    if ((iVar11 != 0) && (*(float *)(iVar4 + 0x4c) != 0.0)) {

      fVar18 = (float10)FUN_00518b70(param_1,0);

      fVar18 = (float10)*(float *)(iVar4 + 0x50) - fVar18;

      *(float *)(iVar4 + 0x50) = (float)fVar18;

      if (fVar18 <= (float10)0.0) {

        fVar18 = (float10)bldg_get_energy(iVar8);

        fStack_1e4 = (float)fVar18;

        fVar18 = (float10)bldg_get_max_energy(iVar8);

        if (fVar18 < (float10)fStack_1e4 == (fVar18 == (float10)fStack_1e4)) {

          bldg_get_refpt_worldlocdir(iVar10,0x53,&fStack_1c4,&fStack_1d8);

          fVar18 = (float10)distancesq2d__FP3P3DT0(&fStack_1c4,param_1 + 0xa0);

          if (fVar18 <= (float10)9.0) {

            *(undefined4 *)(iVar4 + 0x50) = *(undefined4 *)(DAT_00632ed8 + 0x620);

            fVar14 = *(float *)(iVar4 + 0x4c) - 1.0;

            *(float *)(iVar4 + 0x4c) = fVar14;

            if (fVar14 < 0.0) {

              *(undefined4 *)(iVar4 + 0x4c) = 0;

            }

            sound_play_player(0x5f6,param_1);

            iVar10 = dialog_level_is_base();

            if (iVar10 == 0) {

              fVar18 = (float10)1.0;

            }

            else {

              fVar18 = (float10)kbos_food_value__Fi(DAT_00632f40);

            }

            obj_maxspeed_lookup(iVar8,(float)((float10)*(float *)(DAT_00632ed8 + 0x61c) * fVar18));

            if (*(int *)(iVar4 + 0x54) == 0) {

              iVar8 = object_allocate_type(0x45d,0);

              *(int *)(iVar4 + 0x54) = iVar8;

              *(undefined4 *)(iVar8 + 0xc4) = 0x3f000000;

            }

            *(undefined4 *)(iVar4 + 0x58) = 0;

            iVar4 = reaper_0052e4a0(param_1);

            if (iVar4 != 0) {

              cStack_1d9 = __ftol();

              reaper_00530bd0(param_1,0,0,1,0xf,&cStack_1d9);

            }

            mission_replenish_food__Fv();

          }

        }

      }

    }

  }

  if (*(int *)(param_1 + 0x174) == 0) {

    iVar4 = *(int *)(param_1 + 0x100);

    iVar8 = fx_create(param_1);

    if ((((iVar8 != 0) &&

         ((iVar8 = dialog_level_is_base(), iVar8 == 0 ||

          (iVar8 = game_mode_set3_check(DAT_00632f18), iVar8 == 0)))) && (DAT_00632bb0 == 0)) &&

       ((((DAT_00632ba8 == 0 && (iVar4 = *(int *)(iVar4 + 0xd8), iVar4 != 0)) &&

         ((*(uint *)(param_1 + 0xe0) & 0x20000) == 0)) &&

        (iVar4 = base_slot14or1_get(iVar4), iVar4 != 0)))) {

      bldg_get_refpt_worldloc(iVar4,10,&fStack_1c4);

      fVar18 = (float10)FUN_0050a610(&fStack_1c4,param_1 + 0xa0);

      fStack_1e4 = (float)fVar18;

      fVar18 = (float10)FUN_0050a610(&fStack_1c4,param_1 + 0xac);

      if ((fStack_1e4 < 36.0 != (fStack_1e4 == 36.0)) && ((float10)36.0 < fVar18)) {

        evilreaper_award_flow(param_1);

      }

    }

    iVar4 = *(int *)(param_1 + 0x100);

    iVar8 = fx_create(param_1);

    if (((iVar8 != 0) && (DAT_00632bb0 == 0)) &&

       ((DAT_00632ba8 == 0 &&

        (((iVar4 = *(int *)(iVar4 + 0xd8), iVar4 != 0 &&

          ((*(uint *)(param_1 + 0xe0) & 0x20000) == 0)) &&

         (iVar4 = base_slot14_get(iVar4), iVar4 != 0)))))) {

      bldg_get_refpt_worldloc(iVar4,0xc,&fStack_1c4);

      fVar18 = (float10)FUN_0050a610(&fStack_1c4,param_1 + 0xa0);

      fStack_1e4 = (float)fVar18;

      fVar18 = (float10)FUN_0050a610(&fStack_1c4,param_1 + 0xac);

      if ((fStack_1e4 < 36.0 != (fStack_1e4 == 36.0)) && ((float10)36.0 < fVar18)) {

        FUN_00475350(param_1);

      }

    }

    iVar4 = *(int *)(param_1 + 0x100);

    if (((*(int *)(iVar4 + 0xd8) != 0) && ((*(uint *)(param_1 + 0xe0) & 0x20000) == 0)) &&

       (iVar8 = fx_create(param_1), iVar8 != 0)) {

      iVar4 = *(int *)(iVar4 + 0xd8);

      iVar8 = base_slot16_get(iVar4);

      if (iVar8 != 0) {

        bldg_get_refpt_worldloc(iVar8,0xb,&fStack_1c4);

        if (*(int *)(iVar8 + 4) == 0x2cc) {

          bldg_get_refpt_worldloc(iVar8,0xd,&fStack_1b4);

        }

        fVar18 = (float10)FUN_0050a610(&fStack_1c4,param_1 + 0xa0);

        fVar19 = (float10)FUN_0050a610(&fStack_1c4,param_1 + 0xac);

        if (((float)fVar18 < 36.0 == ((float)fVar18 == 36.0)) || (fVar19 <= (float10)36.0)) {

          if (*(int *)(iVar8 + 4) == 0x2cc) {

            fVar18 = (float10)FUN_0050a610(&fStack_1b4,param_1 + 0xa0);

            fVar19 = (float10)FUN_0050a610(&fStack_1b4,param_1 + 0xac);

            if (((float)fVar18 < 36.0 != ((float)fVar18 == 36.0)) && ((float10)36.0 < fVar19)) {

              iVar10 = fx_create(iVar4);

              if (iVar10 == 0) {

                iVar8 = dialog_level_is_base();

                if (iVar8 != 0) {

                  reaper_state_check_e(iVar4,param_1,1);

                }

              }

              else {

                obj_give_carried_item(iVar4,param_1,iVar8,1);

              }

            }

          }

        }

        else {

          iVar10 = fx_create(iVar4);

          if (iVar10 == 0) {

            iVar8 = dialog_level_is_base();

            if (iVar8 != 0) {

              reaper_state_check_e(iVar4,param_1,0);

            }

          }

          else {

            iVar10 = *(int *)(iVar4 + 0x100);

            iVar4 = fx_create(iVar4);

            if ((((iVar4 == 0) || (iVar11 = *(int *)(iVar10 + 0x5bc), iVar11 == 0)) ||

                (iVar11 == *(int *)(param_1 + 0x188))) ||

               (iVar11 = objanim_select_animloop(iVar11), iVar11 == 0)) {

              giftshopview_enable(iVar8,0);

              bldg_get_refpt_worldloc(iVar8,0xb,&fStack_1d0);

              object_set_location_p3d(param_1,&fStack_1d0);

              *(undefined1 *)(param_1 + 0x208) = 0;

              *(undefined1 *)(param_1 + 0x20b) = 0;

              *(undefined1 *)(param_1 + 0x20a) = 0;

              *(uint *)(param_1 + 0x20c) = *(uint *)(param_1 + 0x20c) & 0xfffffbff;

              if (iVar4 != 0) {

                *(undefined4 *)(iVar10 + 0x5bc) = *(undefined4 *)(param_1 + 0x188);

              }

            }

          }

        }

      }

    }

    iVar4 = *(int *)(param_1 + 0x100);

    if (((*(int *)(iVar4 + 0xd8) != 0) && ((*(uint *)(param_1 + 0xe0) & 0x20000) == 0)) &&

       ((iVar8 = fx_create(param_1), iVar8 != 0 &&

        ((param_1 != DAT_00632a88 || (DAT_00632bb8 == 0)))))) {

      uVar7 = *(undefined4 *)(iVar4 + 0xd8);

      iVar4 = base_slot13_get_2(uVar7);

      if (iVar4 != 0) {

        bldg_get_refpt_worldloc(iVar4,0xb,&fStack_1c4);

        fVar18 = (float10)FUN_0050a610(&fStack_1c4,param_1 + 0xa0);

        fStack_1e4 = (float)fVar18;

        fVar18 = (float10)FUN_0050a610(&fStack_1c4,param_1 + 0xac);

        if ((fStack_1e4 < 36.0 != (fStack_1e4 == 36.0)) && ((float10)36.0 < fVar18)) {

          iVar8 = fx_create(uVar7);

          if (iVar8 == 0) {

            iVar8 = dialog_level_is_base();

            if (iVar8 != 0) {

              reaper_state_check_i(uVar7,param_1,iVar4);

            }

          }

          else {

            mecc_drop_carried_object(param_1,iVar4);

          }

        }

      }

    }

    iVar4 = fx_create(param_1);

    if ((iVar4 != 0) && (puVar3 = DAT_00632d68, (*(uint *)(param_1 + 0xe0) & 0x20000) == 0)) {

      for (; puVar3 != (undefined4 *)0x0; puVar3 = (undefined4 *)*puVar3) {

        iVar4 = puVar3[3];

        if ((*(int *)(iVar4 + 0x1e0) == 0x66) &&

           (*(float *)(iVar4 + 0x278) < *(float *)(iVar4 + 0x1c0))) {

          bldg_get_refpt_worldloc(iVar4,0,&fStack_1c4);

          fVar18 = (float10)FUN_0050a610(&fStack_1c4,param_1 + 0xa0);

          fStack_1e4 = (float)fVar18;

          fVar18 = (float10)FUN_0050a610(&fStack_1c4,param_1 + 0xac);

          if ((fStack_1e4 < 25.0 != (fStack_1e4 == 25.0)) && ((float10)25.0 < fVar18)) {

            if ((*(int *)(iVar4 + 0x18c) == *(int *)(param_1 + 0x18c)) ||

               (*(int *)(iVar4 + 0x18c) == 0)) {

              iVar8 = reaper_0052e4a0(param_1);

              if (iVar8 == 0) {

                iVar8 = fx_create(param_1);

                if (iVar8 != 0) {

                  giftshopview_enable(0,iVar4);

                  fVar18 = (float10)tracer_entry_angle(iVar4,0);

                  *(float *)(param_1 + 200) = (float)fVar18;

                  playerobj_eval_refpt(param_1,0,(undefined4 *)(param_1 + 0xa0));

                  object_set_location(param_1,*(undefined4 *)(param_1 + 0xa0),

                                      *(undefined4 *)(param_1 + 0xa4),

                                      *(undefined4 *)(param_1 + 0xa8));

                  *(undefined1 *)(param_1 + 0x20a) = 0;

                  *(undefined1 *)(param_1 + 0x20b) = 0;

                  *(undefined1 *)(param_1 + 0x208) = 0;

                  *(uint *)(param_1 + 0x20c) = *(uint *)(param_1 + 0x20c) & 0xfffffbff;

                }

              }

              else {

                fStack_1d8 = *(float *)(param_1 + 0x188);

                comm_chat_send_2(iVar4,0,1,0,1,&fStack_1d8);

                reaper_spell_big(iVar4,1,4,&fStack_1d8);

              }

              break;

            }

            uVar7 = FUN_00507b00(s_NoEnemyStructures_0055bc5c,1);

            chat_insert(uVar7);

          }

        }

      }

    }

    iVar4 = *(int *)(param_1 + 0x100);

    if (((*(int *)(iVar4 + 0xd8) != 0) && ((*(uint *)(param_1 + 0xe0) & 0x20000) == 0)) &&

       (iVar8 = fx_create(param_1), iVar8 != 0)) {

      fVar14 = *(float *)(iVar4 + 0xd8);

      for (puVar3 = DAT_00632d9c; fStack_1e4 = fVar14, puVar3 != (undefined4 *)0x0;

          puVar3 = (undefined4 *)*puVar3) {

        iVar4 = puVar3[3];

        if (((*(int *)(iVar4 + 4) == 0x3da) &&

            ((*(int *)(iVar4 + 0x18c) == 1 || (*(int *)(iVar4 + 0x18c) == *(int *)(param_1 + 0x18c))

             ))) && (iVar8 = lzo_assert(iVar4), iVar8 != 0)) {

          bldg_get_refpt_worldloc(iVar4,0,&fStack_1c4);

          fVar18 = (float10)FUN_0050a610(&fStack_1c4,param_1 + 0xa0);

          fStack_1d8 = (float)fVar18;

          fVar18 = (float10)FUN_0050a610(&fStack_1c4,param_1 + 0xac);

          if ((fStack_1d8 < 36.0 != (fStack_1d8 == 36.0)) && ((float10)36.0 < fVar18)) {

            iVar8 = fx_create(fVar14);

            if (iVar8 == 0) {

              iVar8 = dialog_level_is_base();

              if (iVar8 != 0) {

                reaper_state_check_g(fVar14,param_1,iVar4);

              }

            }

            else {

              iVar8 = *(int *)(iVar4 + 0x100);

              if ((DAT_00632bbc == 0) || (iVar10 = fx_create(DAT_00632bbc), iVar10 == 0)) {

                bVar2 = false;

              }

              else {

                iVar10 = *(int *)(iVar8 + 0x10);

                bVar2 = true;

                if (((iVar10 != 0) && (iVar10 != *(int *)(param_1 + 0x188))) &&

                   (iVar10 = objanim_select_animloop(iVar10), iVar10 != 0)) goto LAB_0047b505;

              }

              giftshopview_enable(iVar4,0);

              *(undefined1 *)(param_1 + 0x208) = 0;

              *(undefined1 *)(param_1 + 0x20b) = 0;

              *(undefined1 *)(param_1 + 0x20a) = 0;

              *(uint *)(param_1 + 0x20c) = *(uint *)(param_1 + 0x20c) & 0xfffffbff;

              if (bVar2) {

                *(undefined4 *)(iVar8 + 0x10) = *(undefined4 *)(param_1 + 0x188);

              }

            }

          }

        }

LAB_0047b505:

        fVar14 = fStack_1e4;

      }

    }

    iVar4 = *(int *)(param_1 + 0x100);

    fStack_1e8 = 0.0;

    if (((*(int *)(iVar4 + 0xd8) != 0) && ((*(uint *)(param_1 + 0xe0) & 0x20000) == 0)) &&

       ((iVar8 = fx_create(param_1), iVar8 != 0 &&

        ((iVar4 = *(int *)(*(int *)(*(int *)(iVar4 + 0xd8) + 0x100) + 0x580), iVar4 != 0 &&

         (iVar8 = lzo_assert(iVar4), iVar8 != 0)))))) {

      bldg_get_refpt_worldloc(iVar4,0,&fStack_1c4);

      fVar18 = (float10)FUN_0050a610(&fStack_1c4,param_1 + 0xa0);

      fStack_1d8 = (float)fVar18;

      fVar18 = (float10)FUN_0050a610(&fStack_1c4,param_1 + 0xac);

      if ((fStack_1d8 < 36.0 == (fStack_1d8 == 36.0)) || (fVar18 <= (float10)36.0)) {

        if ((40000.0 < fStack_1d8) && (fVar18 < (float10)40000.0 != (fVar18 == (float10)40000.0))) {

          *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xfffffdff;

        }

      }

      else if (*(int *)(iVar4 + 0xe4) == 9) {

        bldg_get_refpt_worldlocdir(iVar4,2,&fStack_1b4,&fStack_1e4);

        for (puVar3 = DAT_00632d70; puVar3 != (undefined4 *)0x0; puVar3 = (undefined4 *)*puVar3) {

          iVar8 = puVar3[3];

          if ((*(int *)(iVar8 + 4) == 0x3df) &&

             (*(int *)(iVar8 + 0x18c) == *(int *)(param_1 + 0x18c))) {

            fVar18 = (float10)FUN_0050a610(iVar8 + 0xa0,&fStack_1b4);

            if (fVar18 < (float10)25.0) goto LAB_0047b706;

            fStack_1e8 = (float)((int)fStack_1e8 + 1);

          }

        }

        if ((int)fStack_1e8 < *(int *)(DAT_00632ed8 + 0x1580)) {

          iVar8 = dialog_level_is_base();

          if ((iVar8 == 0) || (iVar8 = FUN_0052c5c0(), iVar8 != 0)) {

            iVar4 = menu_fx_spawn(param_1,iVar4);

            *(undefined4 *)(iVar4 + 0x18c) = *(undefined4 *)(param_1 + 0x18c);

          }

          else if ((*(uint *)(param_1 + 0xe0) & 0x200) == 0) {

            fStack_1d8 = *(float *)(iVar4 + 0x188);

            uStack_1d4 = 0;

            reaper_00530bd0(param_1,0,2,0,0x26,&fStack_1d8);

            *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 0x200;

          }

        }

      }

    }

LAB_0047b706:

    iVar4 = *(int *)(param_1 + 0x100);

    if ((((*(int *)(iVar4 + 0xd8) != 0) && ((*(uint *)(param_1 + 0xe0) & 0x20000) == 0)) &&

        (iVar8 = fx_create(param_1), iVar8 != 0)) &&

       ((iVar4 = *(int *)(*(int *)(*(int *)(iVar4 + 0xd8) + 0x100) + 0x584), iVar4 != 0 &&

        (iVar8 = lzo_assert(iVar4), iVar8 != 0)))) {

      bldg_get_refpt_worldloc(iVar4,0,&fStack_1d0);

      fVar14 = 0.0;

LAB_0047b778:

      fVar18 = (float10)FUN_0050a610(&fStack_1d0,param_1 + 0xa0);

      fStack_1e4 = (float)fVar18;

      fVar18 = (float10)FUN_0050a610(&fStack_1d0,param_1 + 0xac);

      if ((fStack_1e4 < 36.0 != (fStack_1e4 == 36.0)) && ((float10)36.0 < fVar18)) {

        iVar8 = reaper_has_linked_smartie(param_1);

        if (iVar8 != 0) {

          pcVar6 = (char *)FUN_00507b00(s_AFlagHintTeleport_0055bc47 + 1);

          pcVar13 = &DAT_00632c10;

          do {

            cVar17 = *pcVar6;

            pcVar6 = pcVar6 + 1;

            *pcVar13 = cVar17;

            pcVar13 = pcVar13 + 1;

          } while (cVar17 != '\0');

          _DAT_00632d10 = 0x3f800000;

          goto LAB_0047b93a;

        }

        fStack_1d8 = *(float *)(param_1 + 200);

        puVar3 = DAT_00632d9c;

        goto joined_r0x0047b87c;

      }

      if (fVar14 == 0.0) goto code_r0x0047b805;

    }

LAB_0047b93a:

    projectile_logic(param_1);

  }

  mecc_smoking_fx_update(param_1);

  puVar3 = puStack_1e0;

  drip_system_init(param_1,puStack_1e0 + 0x12,0);

  reaper_lock_big(param_1);

  obj_hover_update(param_1);

  objspec_dispatch_gate(param_1);

  object_animate_process(param_1,0);

  if ((*(uint *)(param_1 + 0xe0) & 0x20000) != 0) {

    fStack_1d0 = *(float *)(*(int *)(param_1 + 0x104) + 0x18);

    fStack_1cc = *(float *)(*(int *)(param_1 + 0x104) + 0x1c);

    fStack_1d8 = 2.0;

    if (*(char *)(puVar3 + 0x4e) == '\0') {

      fStack_1d8 = 1.0;

    }

    pfVar1 = (float *)(puVar3 + 0x4a);

    if ((((float)puVar3[0x4a] == 0.0) && ((float)puVar3[0x4b] == 0.0)) &&

       ((float)puVar3[0x4c] == 0.0)) {

      puVar3[0x4c] = 0x3f800000;

    }

    fVar18 = (float10)FUN_00518b70(param_1,0);

    puStack_1e0 = (undefined4 *)(float)(fVar18 * (float10)fStack_1d8);

    if ((float10)1.0 < fVar18 * (float10)fStack_1d8) {

      puStack_1e0 = (undefined4 *)0x3f800000;

    }

    fVar14 = fStack_1d0 * fStack_1d0 + fStack_1cc * fStack_1cc + 490000.0;

    fStack_1c8 = 0.0;

    if (fVar14 != 0.0) {

      fVar14 = (float)((&DAT_005f0a18)[(uint)fVar14 >> 8 & 0xffff] |

                      ((int)fVar14 + 0xc0800000U >> 1) + 0x3f800000 & 0x7f800000);

      fStack_1c8 = 0.0;

      if (0.0 < fVar14) {

        fStack_1c8 = 1.0 / fVar14;

      }

    }

    fStack_1d0 = fStack_1d0 * fStack_1c8;

    fStack_1cc = fStack_1cc * fStack_1c8;

    fStack_1c8 = fStack_1c8 * 700.0;

    fStack_1e4 = fStack_1d0 * *pfVar1 +

                 fStack_1cc * (float)puVar3[0x4b] + fStack_1c8 * (float)puVar3[0x4c];

    fVar18 = (float10)math_cos_lut_read(fStack_1e4);

    fStack_1d8 = (float)fVar18;

    fVar18 = (float10)math_sin_lut_read_b(fStack_1d8);

    if (fVar18 <= (float10)1e-06) {

      fStack_1e8 = 1.0 - (float)puStack_1e0;

      fVar18 = (float10)(float)puStack_1e0;

    }

    else {

      fStack_1e4 = (float)((float10)1.0 / fVar18);

      fVar18 = (float10)math_sin_lut_read_b((1.0 - (float)puStack_1e0) * fStack_1d8);

      fStack_1e8 = (float)(fVar18 * (float10)fStack_1e4);

      fVar18 = (float10)math_sin_lut_read_b(fStack_1d8 * (float)puStack_1e0);

      fVar18 = fVar18 * (float10)fStack_1e4;

    }

    fStack_1c0 = 0.0;

    fStack_1c4 = 0.0;

    fStack_1bc = -5.0;

    *pfVar1 = (float)(fVar18 * (float10)fStack_1d0 + (float10)fStack_1e8 * (float10)*pfVar1);

    puVar3[0x4b] = (float)(fVar18 * (float10)fStack_1cc +

                          (float10)fStack_1e8 * (float10)(float)puVar3[0x4b]);

    puVar3[0x4c] = (float)(fVar18 * (float10)fStack_1c8 +

                          (float10)fStack_1e8 * (float10)(float)puVar3[0x4c]);

    fVar14 = *(float *)(param_1 + 0x144) * *(float *)(param_1 + 0xa0) +

             *(float *)(param_1 + 0x148) * *(float *)(param_1 + 0xa4) +

             *(float *)(param_1 + 0x14c) * *(float *)(param_1 + 0xa8) + *(float *)(param_1 + 0x150);

    if (fVar14 < 0.0) {

      fVar14 = 0.0;

    }

    puStack_1e0 = (undefined4 *)(1.0 - 1.0 / (fVar14 + 1.0));

    if (0.0 <= (float)puStack_1e0) {

      if (1.0 < (float)puStack_1e0) {

        puStack_1e0 = (undefined4 *)0x3f800000;

      }

    }

    else {

      puStack_1e0 = (undefined4 *)0x0;

    }

    fVar12 = (float)puVar3[0x4c] * (float)puVar3[0x4c] +

             (float)puVar3[0x4b] * (float)puVar3[0x4b] + *pfVar1 * *pfVar1;

    fVar14 = 0.0;

    if (fVar12 != 0.0) {

      fVar12 = (float)((&DAT_005f0a18)[(uint)fVar12 >> 8 & 0xffff] |

                      ((int)fVar12 + 0xc0800000U >> 1) + 0x3f800000 & 0x7f800000);

      fVar14 = 0.0;

      if (0.0 < fVar12) {

        fVar14 = 1.0 / fVar12;

      }

    }

    *pfVar1 = fVar14 * *pfVar1;

    puVar3[0x4b] = fVar14 * (float)puVar3[0x4b];

    puVar3[0x4c] = fVar14 * (float)puVar3[0x4c];

    GEO_MatCopy(auStack_44,auStack_1a8,param_1 + 0x294);

    fStack_1b4 = fStack_19c;

    fStack_1b0 = fStack_18c;

    fStack_1ac = fStack_17c;

    GEO_Vec3Normalize(&fStack_1b4,&fStack_1b4);

    vec_cross_normalize(auStack_164,&fStack_1b4,pfVar1,puStack_1e0);

    quat_to_matrix__FP4QUATPf(auStack_cc,auStack_164);

    FUN_0053dc10(auStack_154,&fStack_1c4);

    (*(code *)PTR_crt_matrix_mul_00580c18)(auStack_110,auStack_154,auStack_1a8);

    (*(code *)PTR_crt_matrix_mul_00580c18)(auStack_88,auStack_cc,auStack_110);

    (*(code *)PTR_crt_matrix_copy_init_00580c1c)(auStack_154,auStack_154);

    (*(code *)PTR_crt_matrix_mul_00580c18)(auStack_110,auStack_154,auStack_88);

    (*(code *)PTR_crt_matrix_mul_00580c18)(param_1 + 0x294,auStack_44,auStack_110);

  }

  mecc_do_health_grenade_mine2__FP6OBJECT(param_1);

  mecc_do_flare__FP6OBJECT(param_1);

  return;

joined_r0x0047b87c:

  if (puVar3 == (undefined4 *)0x0) goto LAB_0047b93a;

  iVar8 = puVar3[3];

  if (((*(int *)(iVar8 + 4) == 0x3d7) &&

      (((*(int *)(iVar8 + 0x18c) == 1 || (*(int *)(iVar8 + 0x18c) == *(int *)(param_1 + 0x18c))) &&

       (iVar8 != iVar4)))) && (iVar10 = lzo_assert(iVar8), iVar10 != 0)) {

    bldg_get_refpt_worldlocdir(iVar8,1,&fStack_1d0,&fStack_1d8);

    sound_play_player(0x6ef,param_1);

    object_set_location_p3d(param_1,&fStack_1d0);

    *(float *)(param_1 + 200) = fStack_1d8;

    playerobj_zap_movement(param_1);

    iVar4 = reaper_0052e4a0(param_1);

    if (iVar4 != 0) {

      uStack_1b8 = *(undefined4 *)(param_1 + 200);

      fStack_1c4 = fStack_1d0;

      fStack_1c0 = fStack_1cc;

      fStack_1bc = fStack_1c8;

      reaper_00530bd0(param_1,4,0,0,0x20,&fStack_1c4);

    }

    goto LAB_0047b93a;

  }

  puVar3 = (undefined4 *)*puVar3;

  goto joined_r0x0047b87c;

code_r0x0047b805:

  fStack_1e4 = 1.4013e-45;

  puVar3 = DAT_00632d9c;

  while( true ) {

    if (puVar3 == (undefined4 *)0x0) goto LAB_0047b93a;

    iVar8 = puVar3[3];

    if (((*(int *)(iVar8 + 4) == 0x3d7) &&

        ((*(int *)(iVar8 + 0x18c) == 1 || (*(int *)(iVar8 + 0x18c) == *(int *)(param_1 + 0x18c)))))

       && ((iVar8 != iVar4 && (iVar10 = lzo_assert(iVar8), iVar10 != 0)))) break;

    puVar3 = (undefined4 *)*puVar3;

  }

  bldg_get_refpt_worldloc(iVar8,0,&fStack_1d0);

  iVar4 = iVar8;

  fVar14 = fStack_1e4;

  goto LAB_0047b778;

}

/* ===== reset_scale__FP6OBJECT @ 0x0047BDF0 ===== */
/* PS2 candidate: reset_scale__FP6OBJECT (conf 0.698) */



void reset_scale__FP6OBJECT(int param_1)



{

  int iVar1;

  

  iVar1 = object_find(*(undefined4 *)(param_1 + 4));

  if (iVar1 != 0) {

    *(undefined4 *)(param_1 + 0xc4) = *(undefined4 *)(iVar1 + 0xc4);

  }

  return;

}

/* ===== mecc_do_death @ 0x0047BE20 ===== */
/* PS2 candidate: mecc_do_death (conf 0.461) */



void mecc_do_death(float param_1,float param_2,int param_3,int param_4,float param_5)



{

  uint *puVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  bool bVar6;

  undefined4 uVar7;

  

  iVar2 = param_3;

  iVar4 = *(int *)(param_3 + 0x100);

  iVar3 = reaper_0052e4a0(param_3);

  if (iVar3 != 0) {

    reaper_00530bd0(iVar2,0,0,0,4,0);

  }

  bVar6 = param_1 == -NAN;

  if (((*(byte *)(iVar2 + 0xe0) & 0x20) != 0) && ((iVar3 = fx_create(iVar2), iVar3 != 0 || (bVar6)))

     ) {

    turret_exit_all_team(iVar2);

  }

  if ((((*(int *)(iVar2 + 0x174) == 0) && (iVar3 = dialog_level_is_base(), iVar3 == 0)) &&

      (DAT_00632bbc != 0)) && (*(int *)(iVar4 + 0xd8) != 0)) {

    objtype_setup_kabuto(*(int *)(iVar4 + 0xd8));

  }

  sound_stop_player(0x5a5,iVar2);

  *(undefined4 *)(iVar4 + 0x1dc) = 0;

  *(undefined4 *)(iVar4 + 0x120) = 0;

  *(undefined4 *)(iVar4 + 0x11c) = 0;

  *(undefined4 *)(iVar4 + 0x110) = *(undefined4 *)(DAT_00632ed8 + 0x8f4);

  *(undefined4 *)(iVar4 + 0x114) = 0;

  if (*(int *)(iVar4 + 0x118) != 0) {

    puVar1 = (uint *)(*(int *)(iVar4 + 0x118) + 0xd8);

    *puVar1 = *puVar1 | 0x40000000;

  }

  if ((DAT_00632f08 == 0) && (*(int *)(iVar2 + 0x174) == 0)) {

    hud_feed_buffer_clear();

    DAT_00632c00 = 1;

  }

  if (!bVar6) {

    sound_play_player(0x5e2,iVar2);

    iVar3 = crt_rand_scaled(100);

    if (iVar3 < 0x14) {

      uVar7 = 0x697;

    }

    else if (iVar3 < 0x28) {

      uVar7 = 0x698;

    }

    else if (iVar3 < 0x3c) {

      uVar7 = 0x699;

    }

    else if (iVar3 < 0x50) {

      uVar7 = 0x69a;

    }

    else {

      uVar7 = 0x69b;

    }

    sound_play_player(uVar7,iVar2);

  }

  sound_stop_player(0x693,iVar2);

  sound_stop_player(0x694,iVar2);

  sound_stop_player(0x695,iVar2);

  sound_stop_player(0x696,iVar2);

  if (param_1 == 7.00649e-45) {

    iVar3 = fx_create(iVar2);

    if (iVar3 != 0) {

      *(undefined4 *)(iVar4 + 0x100) = 1;

      goto LAB_0047bfbd;

    }

  }

  else {

LAB_0047bfbd:

    if (bVar6) goto LAB_0047c03e;

  }

  if (*(float *)(iVar2 + 0x278) <= *(float *)(iVar2 + 0x1c0) * 1.15) {

    ANM_DumpCluster(iVar2,0x10);

    *(undefined4 *)(iVar4 + 0x104) = 1;

  }

  else {

    ANM_DumpCluster(iVar2,0x11);

    *(undefined4 *)(iVar4 + 0x108) = 1;

  }

  if ((((*(uint *)(iVar2 + 0xd8) & 0x80000) != 0) && (param_5 != 0.0)) && (80.0 <= param_2)) {

    uVar7 = death_pose_setup(iVar2,&DAT_0057a778,param_5);

    *(undefined4 *)(iVar4 + 0xf0) = uVar7;

  }

LAB_0047c03e:

  iVar3 = fx_create(iVar2);

  if ((iVar3 != 0) || (bVar6)) {

    *(uint *)(iVar2 + 0xe0) = *(uint *)(iVar2 + 0xe0) & 0xfffbffff;

    uVar7 = IconDefWieldType(*(undefined4 *)(iVar4 + 0x18c),1);

    iVar3 = player_find_weapon_obj_type__FP6OBJECTii(iVar2,0,uVar7);

    if (iVar3 != 0) {

      object_destroy(iVar3);

    }

    uVar7 = IconDefWieldType(*(undefined4 *)(iVar4 + 0x18c),1);

    iVar4 = player_find_weapon_obj_type__FP6OBJECTii(iVar2,1,uVar7);

    if (iVar4 != 0) {

      object_destroy(iVar4);

    }

  }

  iVar4 = reaper_0052e4a0(iVar2);

  if ((iVar4 != 0) && ((*(byte *)(iVar2 + 0x1c8) & 1) != 0)) {

    iVar4 = param_4;

    if ((param_4 != 0) && (*(int *)(param_4 + 0x274) != 0)) {

      iVar4 = *(int *)(param_4 + 0x274);

    }

    if (param_1 != 2.66247e-44) {

      if (iVar4 == 0) {

        iVar3 = 0;

      }

      else {

        iVar3 = *(int *)(iVar4 + 0x18c) + -1;

      }

      param_5 = (float)DAT_00632f24;

      if (iVar3 < 0) {

        iVar3 = 0;

      }

      iVar5 = ObjIsTurret(iVar4);

      if (iVar5 == 0) {

        comm_kill_message(iVar4,iVar2,param_1);

      }

      else {

        comm_kill_message2(*(int *)(iVar4 + 0x18c) + -1,iVar2,0x30);

        iVar4 = 0;

      }

      if (iVar3 == 3) {

        param_5 = (float)DAT_00632f24 * 0.2;

      }

      iVar5 = game_mode_set2_check(DAT_00632f18);

      if (iVar5 == 0) {

        param_1 = param_5;

      }

      else {

        param_1 = 0.0;

      }

      comm_death_packet_build

                (iVar4,iVar2,iVar3,*(int *)(iVar2 + 0x18c) + -1,param_5,param_1,0x3f800000,

                 0x3f800000);

    }

    param_3 = 0;

    comm_chat_send_2(iVar2,0,0,4,3,&param_3);

  }

  *(uint *)(iVar2 + 0xe0) = *(uint *)(iVar2 + 0xe0) & 0xffffffbf;

  return;

}

/* ===== mecc_do_flare__FP6OBJECT @ 0x0047C1D0 ===== */
/* PS2 candidate: mecc_do_flare__FP6OBJECT (conf 0.494) */



void mecc_do_flare__FP6OBJECT(int param_1)



{

  int iVar1;

  int iVar2;

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

  

  if ((*(uint *)(param_1 + 0x20c) & 0x200) != 0) {

    iVar2 = 0;

    while( true ) {

      iVar1 = FUN_004582d0(param_1,iVar2);

      if (iVar1 == 0x40) break;

      iVar2 = iVar2 + 1;

      if (2 < iVar2) {

        return;

      }

    }

    iVar2 = item_get_ammo(param_1,0x40,0);

    if (0 < iVar2) {

      iVar2 = *(int *)(param_1 + 0x100);

      local_44[0] = 0;

      GEO_MatBuildXYZ(local_44,-*(float *)(DAT_00632ed8 + 0x120c),0,*(undefined4 *)(param_1 + 200));

      playerobj_eval_refpt(param_1,10,&local_5c);

      local_50 = local_3c * -1000.0 + local_5c;

      local_4c = local_2c * -1000.0 + local_58;

      local_48 = local_1c * -1000.0 + local_54;

      iVar2 = new_fire__FP6OBJECTiPfT0P3P3Df(param_1,0x2d,iVar2 + 0x38,0,&local_50,0x447a0000);

      if (iVar2 != 0) {

        item_use_ammo(param_1,0x40);

      }

    }

  }

  return;

}

/* ===== obj_hover_update @ 0x0047C2D0 ===== */
void obj_hover_update(int param_1)



{

  float fVar1;

  int iVar2;

  int iVar3;

  uint uVar4;

  int iVar5;

  

  uVar4 = *(uint *)(param_1 + 0x20c);

  iVar2 = *(int *)(param_1 + 0x100);

  if ((uVar4 & 0x40) != 0) {

    if ((0.0 < *(float *)(param_1 + 0x278)) &&

       (*(float *)(param_1 + 0x278) < *(float *)(param_1 + 0x1c0))) {

      iVar5 = 0;

      do {

        iVar3 = FUN_004582d0(param_1,iVar5);

        if (iVar3 == 0) {

          if (*(float *)(DAT_00632ed8 + 0x1560) < *(float *)(iVar2 + 0x198) !=

              (*(float *)(DAT_00632ed8 + 0x1560) == *(float *)(iVar2 + 0x198))) {

            uVar4 = *(uint *)(iVar2 + 0xd4) | 2;

            *(undefined4 *)(iVar2 + 0x198) = 0;

            goto LAB_0047c404;

          }

          break;

        }

        iVar5 = iVar5 + 1;

      } while (iVar5 < 3);

    }

    goto LAB_0047c40a;

  }

  if (((*(uint *)(param_1 + 0xe0) & 0x20000) == 0) && ((char)uVar4 < '\0')) {

    iVar5 = 0;

    do {

      iVar3 = FUN_004582d0(param_1,iVar5);

      if (iVar3 == 8) {

        iVar5 = 8;

        goto LAB_0047c38e;

      }

      iVar5 = iVar5 + 1;

    } while (iVar5 < 3);

    iVar5 = -1;

LAB_0047c38e:

    *(int *)(iVar2 + 0x124) = iVar5;

    if (iVar5 == -1) goto LAB_0047c40a;

    fVar1 = *(float *)(DAT_00632ed8 + 0x155c);

  }

  else {

    if ((uVar4 & 0x100) == 0) goto LAB_0047c40a;

    iVar5 = 0;

    do {

      iVar3 = FUN_004582d0(param_1,iVar5);

      if (iVar3 == 9) {

        iVar5 = 9;

        goto LAB_0047c3cd;

      }

      iVar5 = iVar5 + 1;

    } while (iVar5 < 3);

    iVar5 = -1;

LAB_0047c3cd:

    *(int *)(iVar2 + 0x124) = iVar5;

    if (iVar5 == -1) goto LAB_0047c40a;

    fVar1 = *(float *)(DAT_00632ed8 + 0x155c);

  }

  if (fVar1 < *(float *)(iVar2 + 0x194) != (fVar1 == *(float *)(iVar2 + 0x194))) {

    uVar4 = *(uint *)(iVar2 + 0xd4) | 8;

    *(undefined4 *)(iVar2 + 0x194) = 0;

LAB_0047c404:

    *(uint *)(iVar2 + 0xd4) = uVar4;

  }

LAB_0047c40a:

  if ((*(uint *)(param_1 + 0xe0) & 0x2000000) != 0) {

    mecc_do_health_grenade_mine2__FP6OBJECT(param_1);

    *(uint *)(iVar2 + 0xd4) = *(uint *)(iVar2 + 0xd4) & 0xfffffff5;

  }

  return;

}

/* ===== mecc_do_health_grenade_mine2__FP6OBJECT @ 0x0047C440 ===== */
/* PS2 candidate: mecc_do_health_grenade_mine2__FP6OBJECT (conf 0.507) */



void mecc_do_health_grenade_mine2__FP6OBJECT(int param_1)



{

  int iVar1;

  float fVar2;

  int iVar3;

  int iVar4;

  undefined4 uVar5;

  undefined4 uVar6;

  int iVar7;

  float10 fVar8;

  undefined1 *local_10;

  undefined1 local_c [12];

  

  iVar3 = param_1;

  iVar1 = *(int *)(param_1 + 0x100);

  fVar8 = (float10)FUN_00518b70(param_1,0);

  fVar8 = fVar8 + (float10)*(float *)(iVar1 + 0x198);

  *(float *)(iVar1 + 0x198) = (float)fVar8;

  if (((*(byte *)(iVar1 + 0xd4) & 2) != 0) && ((float10)*(float *)(DAT_00632ed8 + 0x1564) <= fVar8))

  {

    iVar7 = 0;

    do {

      iVar4 = FUN_004582d0(param_1,iVar7);

      if (iVar4 == 0) {

        WeaponIdSetSlot__FP6OBJECTi(param_1,iVar7,0xffffffff);

        break;

      }

      iVar7 = iVar7 + 1;

    } while (iVar7 < 3);

    *(uint *)(iVar1 + 0xd4) = *(uint *)(iVar1 + 0xd4) & 0xfffffffd;

    fVar2 = *(float *)(param_1 + 0x278) - *(float *)(DAT_00632ed8 + 0x1064);

    *(float *)(param_1 + 0x278) = fVar2;

    if (fVar2 < 0.0) {

      *(undefined4 *)(param_1 + 0x278) = 0;

    }

    sound_play_player(0x5ed,param_1);

  }

  fVar8 = (float10)FUN_00518b70(param_1,0);

  fVar8 = fVar8 + (float10)*(float *)(iVar1 + 0x194);

  *(float *)(iVar1 + 0x194) = (float)fVar8;

  if (((*(uint *)(iVar1 + 0xd4) & 8) != 0) && ((float10)*(float *)(DAT_00632ed8 + 0x154c) <= fVar8))

  {

    *(uint *)(iVar1 + 0xd4) = *(uint *)(iVar1 + 0xd4) & 0xfffffff7;

    uVar5 = IconDefProjectile(*(undefined4 *)(iVar1 + 0x124));

    iVar7 = PROJ_DefGet(uVar5);

    iVar4 = PROJ_GetCustom(uVar5);

    local_10 = &LAB_0047c620;

    if (iVar4 != 0) {

      local_10 = *(undefined1 **)(iVar4 + 8);

    }

    if ((iVar7 != 0) && (iVar7 = item_get_ammo(param_1,*(undefined4 *)(iVar1 + 0x124),0), 0 < iVar7)

       ) {

      if (*(int *)(iVar1 + 0x124) == 9) {

        param_1 = *(int *)(DAT_00632ed8 + 0x1058);

      }

      else if (*(int *)(iVar1 + 0x124) == 8) {

        param_1 = *(int *)(DAT_00632ed8 + 0x1054);

      }

      uVar6 = project_cursor_to_object(local_10,*(undefined4 *)(iVar3 + 0x18c),param_1,local_c);

      iVar7 = new_fire__FP6OBJECTiPfT0P3P3Df(iVar3,uVar5,0,uVar6,local_c,param_1);

      if (iVar7 != 0) {

        item_use_ammo(iVar3,*(undefined4 *)(iVar1 + 0x124));

      }

    }

    *(undefined4 *)(iVar1 + 0x124) = 0xffffffff;

    return;

  }

  return;

}

/* ===== sound_player_voice2 @ 0x0047C680 ===== */
void sound_player_voice2(int param_1,int param_2,float param_3)



{

  int iVar1;

  int *piVar2;

  undefined4 uVar3;

  undefined4 local_8;

  undefined4 local_4;

  

  if (*(int *)(param_1 + 0x174) != 0) {

    piVar2 = DAT_00632d70;

    if (DAT_00632d70 == (int *)0x0) {

      return;

    }

    while (((iVar1 = piVar2[3], *(int *)(iVar1 + 4) != 2 ||

            (*(int *)(param_1 + 0x170) != *(int *)(iVar1 + 0x170))) ||

           (*(int *)(iVar1 + 0x174) != 0))) {

      piVar2 = (int *)*piVar2;

      if (piVar2 == (int *)0x0) {

        return;

      }

    }

    if (20.0 <= *(float *)(*(int *)(iVar1 + 0x100) + 0x4c)) {

      return;

    }

  }

  if (*(float *)(*(int *)(param_1 + 0x100) + 0x4c) < 20.0) {

    player_voice_timer_update(param_1,param_3);

    object_destroy(param_2);

    *(float *)(*(int *)(param_1 + 0x100) + 0x4c) =

         param_3 + *(float *)(*(int *)(param_1 + 0x100) + 0x4c);

    iVar1 = crt_rand_scaled(100);

    if (iVar1 < 0x32) {

      uVar3 = 0x63d;

    }

    else {

      uVar3 = 0x63e;

    }

    sound_play_player(uVar3,param_1);

    audio_speaker_user();

    iVar1 = reaper_0052e4a0(param_1);

    if (iVar1 != 0) {

      local_8 = *(undefined4 *)(*(int *)(param_1 + 0x100) + 0x4c);

      local_4 = *(undefined4 *)(param_2 + 0x188);

      reaper_00530bd0(param_1,1,1,0,0xd,&local_8);

    }

  }

  return;

}

/* ===== object_spawn_class @ 0x0047C7A0 ===== */
void object_spawn_class(int param_1,undefined4 param_2,undefined4 *param_3,int param_4)



{

  undefined4 uVar1;

  undefined4 uVar2;

  int iVar3;

  int iVar4;

  undefined4 local_14;

  undefined4 local_10;

  undefined4 local_c;

  undefined4 local_8;

  undefined4 local_4;

  

  iVar3 = object_allocate_type(param_2,0x21);

  if (param_4 != 0) {

    *(int *)(iVar3 + 0x188) = param_4;

  }

  uVar1 = *(undefined4 *)(iVar3 + 0xc4);

  *(undefined4 *)(iVar3 + 0x18c) = *(undefined4 *)(param_1 + 0x18c);

  *(uint *)(iVar3 + 0xd8) = *(uint *)(iVar3 + 0xd8) | 0x10010;

  *(undefined4 *)(iVar3 + 0xa0) = *param_3;

  *(undefined4 *)(iVar3 + 0xa4) = param_3[1];

  uVar2 = param_3[2];

  *(undefined4 *)(iVar3 + 0x2c0) = uVar1;

  *(undefined4 *)(iVar3 + 0xa8) = uVar2;

  *(undefined4 *)(iVar3 + 0x2ac) = uVar1;

  *(undefined4 *)(iVar3 + 0x298) = uVar1;

  *(undefined4 *)(iVar3 + 0x294) = 0x13;

  *(undefined4 *)(iVar3 + 0x2a0) = 0;

  *(undefined4 *)(iVar3 + 0x29c) = 0;

  *(undefined4 *)(iVar3 + 0x2b0) = 0;

  *(undefined4 *)(iVar3 + 0x2a8) = 0;

  *(undefined4 *)(iVar3 + 700) = 0;

  *(undefined4 *)(iVar3 + 0x2b8) = 0;

  *(undefined4 *)(iVar3 + 0x2a4) = *(undefined4 *)(iVar3 + 0xa0);

  *(undefined4 *)(iVar3 + 0x2b4) = *(undefined4 *)(iVar3 + 0xa4);

  *(undefined4 *)(iVar3 + 0x2c4) = *(undefined4 *)(iVar3 + 0xa8);

  iVar4 = FUN_0052c5c0();

  if (iVar4 != 0) {

    local_c = param_3[2];

    local_14 = *param_3;

    local_10 = param_3[1];

    local_8 = param_2;

    local_4 = *(undefined4 *)(iVar3 + 0x188);

    reaper_00530bd0(param_1,3,2,0,0x24,&local_14);

  }

  return;

}

/* ===== FUN_0047c8c0 @ 0x0047C8C0 ===== */
void FUN_0047c8c0(undefined4 param_1,undefined4 param_2,undefined4 *param_3)



{

  undefined4 local_10;

  undefined4 local_c;

  undefined4 local_8;

  undefined4 local_4;

  

  local_10 = *param_3;

  local_4 = param_2;

  local_c = param_3[1];

  local_8 = param_3[2];

  comm_chat_send_1(param_1,3,1,0,0x25,&local_10);

  return;

}

/* ===== reaper_lock_big @ 0x0047C900 ===== */
void reaper_lock_big(int param_1)



{

  int iVar1;

  uint uVar2;

  int iVar3;

  int iVar4;

  byte bVar5;

  undefined4 local_24;

  undefined4 local_20;

  undefined4 local_1c;

  undefined4 local_18;

  undefined4 local_14;

  undefined4 local_10;

  undefined4 local_c;

  undefined4 local_8;

  undefined4 local_4;

  

  iVar3 = param_1;

  iVar1 = *(int *)(param_1 + 0x100);

  iVar4 = reaper_0052e4a0(param_1);

  if (iVar4 != 0) {

    iVar4 = comm_send_gate_check_2(iVar3);

    if (iVar4 != 0) {

      local_24 = *(undefined4 *)(iVar3 + 0xa0);

      local_20 = *(undefined4 *)(iVar3 + 0xa4);

      local_1c = *(undefined4 *)(iVar3 + 0xa8);

      local_18 = *(undefined4 *)(iVar3 + 0x128);

      local_c = *(undefined4 *)(iVar3 + 0x114);

      local_14 = *(undefined4 *)(iVar3 + 300);

      local_10 = *(undefined4 *)(iVar3 + 0x130);

      local_8 = *(undefined4 *)(iVar3 + 200);

      local_4 = *(undefined4 *)(iVar3 + 0x278);

      comm_chat_send_2(iVar3,9,0,0,1,&local_24);

    }

    iVar4 = comm_send_gate_check(iVar3);

    if (iVar4 != 0) {

      bVar5 = (*(uint *)(iVar3 + 0xd8) & 0x2000000) != 0;

      if ((*(uint *)(iVar3 + 0xd8) & 0x1000000) != 0) {

        bVar5 = bVar5 | 2;

      }

      uVar2 = *(uint *)(iVar3 + 0x20c);

      if (bVar5 != 0) {

        if (((uVar2 & 0x400) != 0) && (*(int *)(iVar1 + 0x214) == 0)) {

          bVar5 = bVar5 | 4;

        }

        if ((uVar2 & 0x800) != 0) {

          bVar5 = bVar5 | 8;

        }

        local_20 = *(undefined4 *)(iVar3 + 0x15c);

        local_14 = CONCAT22(CONCAT11(bVar5,*(undefined1 *)(iVar3 + 0x208)),

                            *(undefined2 *)(iVar3 + 0x20a));

        local_24 = *(undefined4 *)(iVar3 + 0x158);

        local_1c = *(undefined4 *)(iVar3 + 0x160);

        local_18 = *(undefined4 *)(iVar3 + 0x164);

        comm_chat_send_2(iVar3,6,0,4,2,&local_24);

        return;

      }

      bVar5 = 0;

      if (((uVar2 & 0x400) != 0) && (*(int *)(iVar1 + 0x214) == 0)) {

        bVar5 = 4;

      }

      if ((uVar2 & 0x800) != 0) {

        bVar5 = bVar5 | 8;

      }

      param_1 = CONCAT13(bVar5,CONCAT12(*(undefined1 *)(iVar3 + 0x208),

                                        *(undefined2 *)(iVar3 + 0x20a)));

      comm_chat_send_2(iVar3,0,0,4,3,&param_1);

    }

  }

  return;

}

/* ===== kbos_move @ 0x0047CAA0 ===== */
/* WARNING: Removing unreachable block (ram,0x0047ccef) */

/* WARNING: Removing unreachable block (ram,0x0047cd01) */

/* PS2 candidate: kbos_move (conf 0.446) */



void kbos_move(int param_1,undefined4 param_2,undefined4 param_3,float *param_4)



{

  float fVar1;

  undefined4 *puVar2;

  float *pfVar3;

  undefined4 uVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  uint uVar8;

  float10 fVar9;

  float fVar10;

  undefined4 local_4c;

  float local_48;

  undefined1 local_40 [28];

  undefined4 local_24;

  undefined4 local_20;

  int local_1c;

  

  iVar7 = param_1;

  iVar5 = *(int *)(param_1 + 0x100);

  mecc_init__FP6OBJECT(param_1);

  pfVar3 = param_4;

  switch(param_2) {

  case 1:

    if ((*(uint *)(iVar7 + 0xe0) & 0x400000) == 0) {

      if (*(float *)(iVar7 + 0x1c0) <= *(float *)(iVar7 + 0x278)) {

        iVar6 = *(int *)(iVar5 + 0x208) + 1;

        *(int *)(iVar5 + 0x208) = iVar6;

        if (iVar6 != 2) {

          return;

        }

        *(undefined4 *)(iVar5 + 0x208) = 0;

        for (puVar2 = DAT_00632d68; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {

          iVar6 = puVar2[3];

          if (((*(int *)(iVar6 + 0x210) == iVar7) && (*(int *)(iVar6 + 4) != 0x24)) &&

             (*(int *)(iVar6 + 4) != 0x398)) {

            *(undefined4 *)(iVar6 + 0x184) = 0;

          }

        }

        *(undefined4 *)(iVar7 + 0x184) = 0;

        *(uint *)(iVar7 + 0xd8) = *(uint *)(iVar7 + 0xd8) & 0xbfffffff;

      }

      if (*(int *)(iVar5 + 0xf4) != 0) {

        fx_delete(*(int *)(iVar5 + 0xf4));

        *(undefined4 *)(iVar5 + 0xf4) = 0;

      }

      *(float *)(iVar5 + 0x1b4) = *param_4 - *(float *)(iVar7 + 0xa0);

      *(float *)(iVar5 + 0x1b8) = param_4[1] - *(float *)(iVar7 + 0xa4);

      fVar10 = param_4[2];

      fVar1 = *(float *)(iVar7 + 0xa8);

      *(undefined4 *)(iVar5 + 0x1c0) = 0;

      *(float *)(iVar5 + 0x1bc) = fVar10 - fVar1;

      *(float *)(iVar7 + 0x128) = param_4[3];

      *(float *)(iVar7 + 300) = param_4[4];

      *(float *)(iVar7 + 0x130) = param_4[5];

      *(float *)(iVar7 + 0x114) = param_4[6];

      *(float *)(iVar7 + 200) = param_4[7];

      *(float *)(iVar7 + 0x278) = param_4[8];

      if ((*(uint *)(iVar7 + 0xd8) & 0x4000) != 0) {

        obj_children_flag_clear(iVar7);

        return;

      }

    }

    break;

  case 2:

    *(undefined1 *)(iVar7 + 0x20a) = *(undefined1 *)(param_4 + 4);

    *(undefined1 *)(iVar7 + 0x20b) = *(undefined1 *)((int)param_4 + 0x11);

    *(undefined1 *)(iVar7 + 0x208) = *(undefined1 *)((int)param_4 + 0x12);

    *(float *)(iVar7 + 0x158) = *param_4;

    *(float *)(iVar7 + 0x15c) = param_4[1];

    *(float *)(iVar7 + 0x160) = param_4[2];

    *(float *)(iVar7 + 0x164) = param_4[3];

    *(uint *)(iVar7 + 0xd8) = *(uint *)(iVar7 + 0xd8) & 0xfcffffff;

    if ((*(byte *)((int)param_4 + 0x13) & 4) == 0) {

      uVar8 = *(uint *)(iVar7 + 0x20c) & 0xfffffbff;

    }

    else {

      uVar8 = *(uint *)(iVar7 + 0x20c) | 0x400;

    }

    *(uint *)(iVar7 + 0x20c) = uVar8;

    uVar8 = *(uint *)(iVar7 + 0x20c);

    if ((*(byte *)((int)param_4 + 0x13) & 8) != 0) {

      *(uint *)(iVar7 + 0x20c) = uVar8 | 0x800;

      return;

    }

    goto LAB_0047cdb1;

  case 3:

    *(undefined1 *)(iVar7 + 0x20a) = *(undefined1 *)param_4;

    *(undefined1 *)(iVar7 + 0x20b) = *(undefined1 *)((int)param_4 + 1);

    *(undefined1 *)(iVar7 + 0x208) = *(undefined1 *)((int)param_4 + 2);

    *(uint *)(iVar7 + 0xd8) = *(uint *)(iVar7 + 0xd8) & 0xfcffffff;

    if (((uint)*param_4 & 0x4000000) == 0) {

      uVar8 = *(uint *)(iVar7 + 0x20c) & 0xfffffbff;

    }

    else {

      uVar8 = *(uint *)(iVar7 + 0x20c) | 0x400;

    }

    *(uint *)(iVar7 + 0x20c) = uVar8;

    uVar8 = *(uint *)(iVar7 + 0x20c);

    if (((uint)*param_4 & 0x8000000) != 0) {

      *(uint *)(iVar7 + 0x20c) = uVar8 | 0x800;

      return;

    }

LAB_0047cdb1:

    *(uint *)(iVar7 + 0x20c) = uVar8 & 0xfffff7ff;

    return;

  case 4:

    *(uint *)(iVar7 + 0xe0) = *(uint *)(iVar7 + 0xe0) | 0x400000;

    if (*(float *)(iVar7 + 0x278) < *(float *)(iVar7 + 0x1c0)) {

      mecc_do_death(0xffffffff,0,iVar7,0,0,0);

      for (puVar2 = DAT_00632d68; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {

        iVar5 = puVar2[3];

        if (((*(int *)(iVar5 + 0x210) == iVar7) && (*(int *)(iVar5 + 4) != 0x24)) &&

           (*(int *)(iVar5 + 4) != 0x398)) {

          *(undefined4 *)(iVar5 + 0x184) = 0x3f800000;

        }

      }

      *(undefined4 *)(iVar7 + 0x184) = 0x3f800000;

      *(undefined4 *)(iVar7 + 0x278) = *(undefined4 *)(iVar7 + 0x1c0);

      return;

    }

    break;

  case 8:

    teammecc_set_mode(iVar7,*(undefined1 *)param_4,1);

    return;

  case 10:

    iVar5 = *(int *)(iVar7 + 0x100);

    if ((*(uint *)(iVar7 + 0xe0) & 0x1000000) != 0) {

      if (*(int *)(iVar5 + 0x144) != 0) {

        fx_delete(*(int *)(iVar5 + 0x144));

        *(undefined4 *)(iVar5 + 0x144) = 0;

        iVar6 = reaper_0052e4a0(iVar7);

        if (iVar6 != 0) {

          reaper_00530bd0(iVar7,0,0,0,0x1f,0);

        }

      }

      if (*(int *)(iVar5 + 0x1ec) != 0) {

        sound_interrupt_sequence(iVar5 + 0x1ec);

      }

      *(undefined4 *)(iVar5 + 0x140) = 0;

      if (*(int *)(iVar5 + 0x18c) == 0x13) {

        WeaponIdSetCurrent__FP6OBJECTi(iVar7,*(undefined4 *)(iVar5 + 0xfc));

        *(undefined4 *)(iVar5 + 0xfc) = 0xffffffff;

      }

      *(uint *)(iVar7 + 0xe0) = *(uint *)(iVar7 + 0xe0) & 0xfeffffff;

      iVar5 = reaper_0052e4a0(iVar7);

      if (iVar5 != 0) {

        reaper_00530bd0(iVar7,0,0,0,0x15,0);

      }

    }

    pfVar3 = param_4;

    if (*(char *)param_4 != -1) {

      *(undefined4 *)(*(int *)(iVar7 + 0x100) + 0x5c) = 0xffffffff;

    }

    WeaponIdSetCurrent__FP6OBJECTi(iVar7,(int)*(char *)param_4);

    switch(*(undefined1 *)pfVar3) {

    case 1:

      sound_play_player(0x5cd,iVar7);

      return;

    case 3:

      sound_play_player(0x5d9,iVar7);

      return;

    case 5:

      sound_play_player(0x5fc,iVar7);

      return;

    case 6:

      sound_play_player(0x5e7,iVar7);

      return;

    case 7:

      sound_play_player(0x5c8,iVar7);

      return;

    case 0xe:

      sound_play_player(0x5c4,iVar7);

      return;

    case 0xf:

      sound_play_player(0x5a3,iVar7);

      return;

    case 0x10:

      sound_play_player(0x5d3,iVar7);

      return;

    }

    break;

  case 0xb:

    mecc_to_bush(iVar7);

    return;

  case 0xc:

    if (((*(uint *)(iVar7 + 0xe0) & 0x2000000) != 0) && ((*(uint *)(iVar7 + 0xe0) & 0x4000000) == 0)

       ) {

      iVar5 = reaper_0052e4a0(iVar7);

      if (iVar5 != 0) {

        reaper_00530bd0(iVar7,0,0,0,0xc,0);

      }

      *(uint *)(iVar7 + 0xe0) = *(uint *)(iVar7 + 0xe0) | 0x4000000;

      *(undefined4 *)(iVar7 + 0x274) = 0;

      sound_play_player(0x572,iVar7);

      return;

    }

    break;

  case 0xd:

    iVar5 = objanim_select_animloop(param_4[1]);

    param_4 = (float *)*pfVar3;

    if (iVar5 != 0) {

      object_destroy(iVar5);

      iVar5 = crt_rand_scaled(100);

      if (iVar5 < 0x32) {

        uVar4 = 0x63d;

      }

      else {

        uVar4 = 0x63e;

      }

      sound_play_player(uVar4,iVar7);

    }

    *(float **)(*(int *)(iVar7 + 0x100) + 0x4c) = param_4;

    return;

  case 0xf:

    if (*(int *)(iVar5 + 0x54) == 0) {

      iVar7 = object_allocate_type(0x45d,0);

      *(int *)(iVar5 + 0x54) = iVar7;

      *(undefined4 *)(iVar7 + 0xc4) = 0x3f000000;

    }

    *(undefined4 *)(iVar5 + 0x58) = 0;

    param_4 = (float *)(uint)*(byte *)param_4;

    *(float *)(iVar5 + 0x4c) = (float)(int)param_4;

    iVar7 = dialog_level_is_base();

    if (iVar7 == 0) {

      fVar9 = (float10)1.0;

    }

    else {

      fVar9 = (float10)kbos_food_value__Fi(DAT_00632f40);

    }

    obj_maxspeed_lookup(*(undefined4 *)(iVar5 + 0xd8),

                        (float)((float10)*(float *)(DAT_00632ed8 + 0x61c) * fVar9));

    return;

  case 0x10:

    uVar4 = 0;

    if (param_4[3] != 0.0) {

      uVar4 = objanim_select_animloop(param_4[3]);

    }

    getfirelockandgun__FP6OBJECTUcPP6OBJECTPi(iVar7,*(undefined1 *)(pfVar3 + 5),&param_1,&param_4);

    iVar5 = PROJ_Create2(*(undefined1 *)(pfVar3 + 5),*(undefined4 *)(iVar7 + 0x18c),param_1,param_4,

                         uVar4,pfVar3);

    if (iVar5 != 0) {

      *(float *)(iVar5 + 0x188) = pfVar3[4];

      *(int *)(iVar5 + 0x274) = iVar7;

      sound_player_sequence(iVar7,*(undefined1 *)(pfVar3 + 5));

      return;

    }

    break;

  case 0x11:

    iVar5 = SpecialWeaponIdSet__FP6OBJECTi(iVar7,(int)*(char *)(param_4 + 1));

    if (iVar5 != 0) {

      *(float *)(iVar5 + 0x188) = *pfVar3;

      return;

    }

    break;

  case 0x12:

    mecc_enable_personal_shield(iVar7);

    return;

  case 0x13:

    mecc_disable_personal_shield(iVar7);

    return;

  case 0x14:

    iVar5 = *(int *)(iVar7 + 0x100);

    if (*(int *)(iVar5 + 0x18c) == 0x13) {

      uVar4 = WeaponIdGetPresent__FP6OBJECT(iVar7);

      *(undefined4 *)(iVar5 + 0xfc) = uVar4;

      WeaponIdSetCurrent__FP6OBJECTi(iVar7,0x13);

      *(uint *)(iVar7 + 0xe0) = *(uint *)(iVar7 + 0xe0) | 0x1000000;

      iVar5 = reaper_0052e4a0(iVar7);

      if (iVar5 != 0) {

        reaper_00530bd0(iVar7,0,0,0,0x14,0);

        return;

      }

    }

    break;

  case 0x15:

    iVar5 = *(int *)(iVar7 + 0x100);

    if ((*(uint *)(iVar7 + 0xe0) & 0x1000000) != 0) {

      if (*(int *)(iVar5 + 0x144) != 0) {

        fx_delete(*(int *)(iVar5 + 0x144));

        *(undefined4 *)(iVar5 + 0x144) = 0;

        iVar6 = reaper_0052e4a0(iVar7);

        if (iVar6 != 0) {

          reaper_00530bd0(iVar7,0,0,0,0x1f,0);

        }

      }

      if (*(int *)(iVar5 + 0x1ec) != 0) {

        sound_interrupt_sequence(iVar5 + 0x1ec);

      }

      *(undefined4 *)(iVar5 + 0x140) = 0;

      if (*(int *)(iVar5 + 0x18c) == 0x13) {

        WeaponIdSetCurrent__FP6OBJECTi(iVar7,*(undefined4 *)(iVar5 + 0xfc));

        *(undefined4 *)(iVar5 + 0xfc) = 0xffffffff;

      }

      *(uint *)(iVar7 + 0xe0) = *(uint *)(iVar7 + 0xe0) & 0xfeffffff;

      iVar5 = reaper_0052e4a0(iVar7);

      if (iVar5 != 0) {

        reaper_00530bd0(iVar7,0,0,0,0x15,0);

        return;

      }

    }

    break;

  case 0x16:

    if (*(float *)(iVar5 + 0x18c) != *param_4) {

      SpecialWeaponIdSet__FP6OBJECTi(iVar7,*param_4);

    }

    *(uint *)(iVar7 + 0xe0) = *(uint *)(iVar7 + 0xe0) | 0x40000;

    return;

  case 0x17:

    obj_swap_link(iVar7);

    return;

  case 0x18:

    iVar5 = objanim_select_animloop(*param_4);

    if (iVar5 == 0) {

      iVar5 = menu_fx_spawn(iVar7,0);

      *(undefined4 *)(iVar5 + 0x18c) = *(undefined4 *)(iVar7 + 0x18c);

      *(float *)(iVar5 + 0x188) = *pfVar3;

    }

    *(int *)(iVar5 + 0x210) = iVar7;

    *(undefined4 *)(iVar5 + 0x218) = 4;

    *(undefined4 *)(iVar5 + 0x214) = 0;

    *(uint *)(iVar7 + 0xe0) = *(uint *)(iVar7 + 0xe0) | 0x20000;

    *(uint *)(iVar7 + 0xd8) = *(uint *)(iVar7 + 0xd8) & 0xfff7ffff;

    *(uint *)(iVar5 + 0xe0) = *(uint *)(iVar5 + 0xe0) | 1;

    ObjectSetAnim(iVar7,0xd3,0x21,0,0,0);

    mecc_stop_looping_effects(iVar7);

    iVar6 = reaper_0052e4a0(iVar5);

    if (iVar6 != 0) {

      param_4 = *(float **)(iVar5 + 0x188);

      reaper_00530bd0(iVar7,0,1,0,0x18,&param_4);

    }

    mecc_disable_personal_shield(iVar7);

    iVar5 = *(int *)(iVar7 + 0x100);

    if ((*(uint *)(iVar7 + 0xe0) & 0x1000000) != 0) {

      if (*(int *)(iVar5 + 0x144) != 0) {

        fx_delete(*(int *)(iVar5 + 0x144));

        *(undefined4 *)(iVar5 + 0x144) = 0;

        iVar6 = reaper_0052e4a0(iVar7);

        if (iVar6 != 0) {

          reaper_00530bd0(iVar7,0,0,0,0x1f,0);

        }

      }

      if (*(int *)(iVar5 + 0x1ec) != 0) {

        sound_interrupt_sequence(iVar5 + 0x1ec);

      }

      *(undefined4 *)(iVar5 + 0x140) = 0;

      if (*(int *)(iVar5 + 0x18c) == 0x13) {

        WeaponIdSetCurrent__FP6OBJECTi(iVar7,*(undefined4 *)(iVar5 + 0xfc));

        *(undefined4 *)(iVar5 + 0xfc) = 0xffffffff;

      }

      *(uint *)(iVar7 + 0xe0) = *(uint *)(iVar7 + 0xe0) & 0xfeffffff;

      iVar5 = reaper_0052e4a0(iVar7);

      if (iVar5 != 0) {

        reaper_00530bd0(iVar7,0,0,0,0x15,0);

      }

    }

    if (((*(uint *)(iVar7 + 0xe0) & 0x2000000) != 0) && ((*(uint *)(iVar7 + 0xe0) & 0x4000000) == 0)

       ) {

      iVar5 = reaper_0052e4a0(iVar7);

      if (iVar5 != 0) {

        reaper_00530bd0(iVar7,0,0,0,0xc,0);

      }

      *(uint *)(iVar7 + 0xe0) = *(uint *)(iVar7 + 0xe0) | 0x4000000;

      *(undefined4 *)(iVar7 + 0x274) = 0;

      sound_play_player(0x572,iVar7);

      sound_play_player(0x598,iVar7);

      return;

    }

LAB_0047d90a:

    sound_play_player(0x598,iVar7);

    return;

  case 0x19:

    iVar5 = FUN_0052c5c0();

    pfVar3 = param_4;

    if (iVar5 == 0) {

      uVar4 = objanim_select_animloop(*param_4);

      iVar5 = objanim_select_animloop(pfVar3[1]);

      if (iVar5 == 0) {

        iVar5 = menu_fx_spawn(iVar7,uVar4);

      }

      *(undefined4 *)(iVar5 + 0x18c) = *(undefined4 *)(iVar7 + 0x18c);

      *(float *)(iVar5 + 0x188) = pfVar3[1];

      *(uint *)(iVar7 + 0xe0) = *(uint *)(iVar7 + 0xe0) & 0xfffffdff;

      return;

    }

    break;

  case 0x1a:

    iVar5 = objanim_select_animloop(*param_4);

    if (iVar5 == 0) {

      iVar5 = menu_fx_spawn(iVar7,0);

      *(undefined4 *)(iVar5 + 0x18c) = *(undefined4 *)(iVar7 + 0x18c);

      *(float *)(iVar5 + 0x188) = *pfVar3;

    }

    fVar10 = pfVar3[1];

    *(int *)(iVar7 + 0x210) = iVar5;

    *(undefined4 *)(iVar7 + 0x214) = 4;

    *(uint *)(iVar7 + 0x218) = (fVar10 != 1.4013e-45) + 3;

    *(uint *)(iVar7 + 0xdc) = *(uint *)(iVar7 + 0xdc) | 0x8000;

    *(uint *)(iVar5 + 0xe0) = *(uint *)(iVar5 + 0xe0) | (uint)(fVar10 != 1.4013e-45) * 2 + 2;

    mecc_stop_looping_effects(iVar7);

    iVar6 = reaper_0052e4a0(iVar5);

    if (iVar6 != 0) {

      local_4c = *(undefined4 *)(iVar5 + 0x188);

      local_48 = fVar10;

      reaper_00530bd0(iVar7,0,2,0,0x1a,&local_4c);

    }

    mecc_disable_personal_shield(iVar7);

    iVar5 = *(int *)(iVar7 + 0x100);

    if ((*(uint *)(iVar7 + 0xe0) & 0x1000000) == 0) goto LAB_0047d6f9;

    if (*(int *)(iVar5 + 0x144) != 0) {

      fx_delete(*(int *)(iVar5 + 0x144));

      *(undefined4 *)(iVar5 + 0x144) = 0;

      iVar6 = reaper_0052e4a0(iVar7);

      if (iVar6 != 0) {

        reaper_00530bd0(iVar7,0,0,0,0x1f,0);

      }

    }

    if (*(int *)(iVar5 + 0x1ec) != 0) {

      sound_interrupt_sequence(iVar5 + 0x1ec);

    }

    *(undefined4 *)(iVar5 + 0x140) = 0;

    if (*(int *)(iVar5 + 0x18c) == 0x13) {

      uVar4 = *(undefined4 *)(iVar5 + 0xfc);

LAB_0047d6b8:

      WeaponIdSetCurrent__FP6OBJECTi(iVar7,uVar4);

      *(undefined4 *)(iVar5 + 0xfc) = 0xffffffff;

    }

    goto LAB_0047d6cb;

  case 0x1b:

    uVar4 = objanim_select_animloop(*param_4);

    iVar5 = fx_create(iVar7);

    if (iVar5 != 0) {

      giftshopview_enable(0,uVar4);

      fVar9 = (float10)tracer_entry_angle(uVar4,0);

      *(float *)(iVar7 + 200) = (float)fVar9;

      playerobj_eval_refpt(iVar7,0,(undefined4 *)(iVar7 + 0xa0));

      object_set_location(iVar7,*(undefined4 *)(iVar7 + 0xa0),*(undefined4 *)(iVar7 + 0xa4),

                          *(undefined4 *)(iVar7 + 0xa8));

      *(undefined1 *)(iVar7 + 0x20a) = 0;

      *(undefined1 *)(iVar7 + 0x20b) = 0;

      *(undefined1 *)(iVar7 + 0x208) = 0;

      *(uint *)(iVar7 + 0x20c) = *(uint *)(iVar7 + 0x20c) & 0xfffffbff;

    }

    iVar5 = fx_create(uVar4);

    if (iVar5 == 0) {

      minishop_update_mecc_icons(uVar4,pfVar3[1]);

      return;

    }

    break;

  case 0x1c:

    if ((*(int *)(iVar5 + 0x19c) == 0) && (local_1c = gun_find_right(iVar7), local_1c != 0)) {

      local_20 = 1;

      local_24 = 8;

      uVar4 = fx_get_free_effect__Fv();

      *(undefined4 *)(iVar5 + 0x19c) = uVar4;

      return;

    }

    break;

  case 0x1d:

    if (*(int *)(iVar5 + 0x19c) != 0) {

      fx_delete(*(int *)(iVar5 + 0x19c));

      *(undefined4 *)(iVar5 + 0x19c) = 0;

      return;

    }

    break;

  case 0x1e:

    if (*(int *)(iVar5 + 0x144) == 0) {

      PROJ_DefGet(0x13);

      local_1c = gun_find_right(iVar7);

      if (local_1c != 0) {

        local_20 = 1;

        local_24 = 8;

        uVar4 = fx_get_free_effect__Fv();

        *(undefined4 *)(iVar5 + 0x144) = uVar4;

        return;

      }

    }

    break;

  case 0x1f:

    iVar5 = *(int *)(iVar7 + 0x100);

    if (*(int *)(iVar5 + 0x144) != 0) {

      fx_delete(*(int *)(iVar5 + 0x144));

      *(undefined4 *)(iVar5 + 0x144) = 0;

      iVar6 = reaper_0052e4a0(iVar7);

      if (iVar6 != 0) {

        reaper_00530bd0(iVar7,0,0,0,0x1f,0);

      }

    }

    if (*(int *)(iVar5 + 0x1ec) != 0) {

      sound_interrupt_sequence(iVar5 + 0x1ec);

    }

    *(undefined4 *)(iVar5 + 0x140) = 0;

    return;

  case 0x20:

    sound_play_3dpos(0x6ef,iVar7 + 0xa0);

    pfVar3 = param_4;

    object_set_location_p3d(iVar7,param_4);

    *(float *)(iVar7 + 200) = pfVar3[3];

    playerobj_zap_movement(iVar7);

    sound_play_3dpos(0x6ef,iVar7 + 0xa0);

    return;

  case 0x21:

    if (*(int *)(iVar5 + 0x1fc) == 0) {

      uVar4 = sound_get_free_sequence__Fv();

      *(undefined4 *)(iVar5 + 0x1fc) = uVar4;

      return;

    }

    break;

  case 0x22:

    if (*(int *)(iVar5 + 0x1fc) != 0) {

      sound_stop_sequence(iVar5 + 0x1fc);

      return;

    }

    break;

  case 0x23:

    iVar5 = FUN_0052c5c0();

    if (iVar5 == 0) {

      return;

    }

    iVar5 = objanim_select_animloop(*param_4);

    if (iVar5 == 0) {

      return;

    }

    if ((*(uint *)(iVar5 + 0xd8) & 0x8000) != 0) {

      return;

    }

    if (*(int *)(iVar5 + 4) != 0x3df) {

      return;

    }

    if (*(int *)(iVar5 + 0x18c) != *(int *)(iVar7 + 0x18c)) {

      return;

    }

    iVar6 = *(int *)(iVar5 + 0x210);

    if (iVar6 == iVar7) {

      return;

    }

    if ((*(int *)(iVar7 + 0x210) != 0) && (*(int *)(*(int *)(iVar7 + 0x210) + 0x1e0) == 0x5f)) {

      return;

    }

    if (iVar6 == 0) {

      *(int *)(iVar5 + 0x210) = iVar7;

      *(undefined4 *)(iVar5 + 0x218) = 4;

      *(undefined4 *)(iVar5 + 0x214) = 0;

      *(uint *)(iVar7 + 0xe0) = *(uint *)(iVar7 + 0xe0) | 0x20000;

      *(uint *)(iVar7 + 0xd8) = *(uint *)(iVar7 + 0xd8) & 0xfff7ffff;

      *(uint *)(iVar5 + 0xe0) = *(uint *)(iVar5 + 0xe0) | 1;

      ObjectSetAnim(iVar7,0xd3,0x21,0,0,0);

      mecc_stop_looping_effects(iVar7);

      iVar6 = reaper_0052e4a0(iVar5);

      if (iVar6 != 0) {

        param_4 = *(float **)(iVar5 + 0x188);

        reaper_00530bd0(iVar7,0,1,0,0x18,&param_4);

      }

      mecc_disable_personal_shield(iVar7);

      iVar5 = *(int *)(iVar7 + 0x100);

      if ((*(uint *)(iVar7 + 0xe0) & 0x1000000) != 0) {

        if (*(int *)(iVar5 + 0x144) != 0) {

          fx_delete(*(int *)(iVar5 + 0x144));

          *(undefined4 *)(iVar5 + 0x144) = 0;

          iVar6 = reaper_0052e4a0(iVar7);

          if (iVar6 != 0) {

            reaper_00530bd0(iVar7,0,0,0,0x1f,0);

          }

        }

        if (*(int *)(iVar5 + 0x1ec) != 0) {

          sound_interrupt_sequence(iVar5 + 0x1ec);

        }

        *(undefined4 *)(iVar5 + 0x140) = 0;

        if (*(int *)(iVar5 + 0x18c) == 0x13) {

          WeaponIdSetCurrent__FP6OBJECTi(iVar7,*(undefined4 *)(iVar5 + 0xfc));

          *(undefined4 *)(iVar5 + 0xfc) = 0xffffffff;

        }

        *(uint *)(iVar7 + 0xe0) = *(uint *)(iVar7 + 0xe0) & 0xfeffffff;

        iVar5 = reaper_0052e4a0(iVar7);

        if (iVar5 != 0) {

          reaper_00530bd0(iVar7,0,0,0,0x15,0);

        }

      }

      if (((*(uint *)(iVar7 + 0xe0) & 0x2000000) != 0) &&

         ((*(uint *)(iVar7 + 0xe0) & 0x4000000) == 0)) {

        iVar5 = reaper_0052e4a0(iVar7);

        if (iVar5 != 0) {

          reaper_00530bd0(iVar7,0,0,0,0xc,0);

        }

        *(uint *)(iVar7 + 0xe0) = *(uint *)(iVar7 + 0xe0) | 0x4000000;

        *(undefined4 *)(iVar7 + 0x274) = 0;

        sound_play_player(0x572,iVar7);

      }

      goto LAB_0047d90a;

    }

    iVar6 = ObjIsMecc(iVar6);

    if (iVar6 == 0) {

      return;

    }

    uVar8 = *(uint *)(iVar5 + 0xe0);

    if ((uVar8 & 6) == 0) {

      bldg_get_refpt_worldloc(iVar5,3,&local_4c);

      bldg_get_refpt_worldloc(iVar5,4,local_40);

      fVar9 = (float10)FUN_0050a610(iVar7 + 0xa0,&local_4c);

      param_4 = (float *)(float)fVar9;

      fVar9 = (float10)FUN_0050a610(iVar7 + 0xa0,local_40);

      if (fVar9 <= (float10)(float)param_4) {

LAB_0047d5b2:

        fVar10 = 2.8026e-45;

      }

      else {

        fVar10 = 1.4013e-45;

      }

    }

    else {

      if ((uVar8 & 2) != 0) {

        if ((uVar8 & 4) != 0) {

          return;

        }

        goto LAB_0047d5b2;

      }

      fVar10 = 1.4013e-45;

    }

    *(int *)(iVar7 + 0x210) = iVar5;

    *(undefined4 *)(iVar7 + 0x214) = 4;

    *(uint *)(iVar7 + 0x218) = (fVar10 != 1.4013e-45) + 3;

    *(uint *)(iVar7 + 0xdc) = *(uint *)(iVar7 + 0xdc) | 0x8000;

    *(uint *)(iVar5 + 0xe0) = *(uint *)(iVar5 + 0xe0) | (uint)(fVar10 != 1.4013e-45) * 2 + 2;

    mecc_stop_looping_effects(iVar7);

    iVar6 = reaper_0052e4a0(iVar5);

    if (iVar6 != 0) {

      local_4c = *(undefined4 *)(iVar5 + 0x188);

      local_48 = fVar10;

      reaper_00530bd0(iVar7,0,2,0,0x1a,&local_4c);

    }

    mecc_disable_personal_shield(iVar7);

    iVar5 = *(int *)(iVar7 + 0x100);

    if ((*(uint *)(iVar7 + 0xe0) & 0x1000000) == 0) goto LAB_0047d6f9;

    if (*(int *)(iVar5 + 0x144) != 0) {

      fx_delete(*(int *)(iVar5 + 0x144));

      *(undefined4 *)(iVar5 + 0x144) = 0;

      iVar6 = reaper_0052e4a0(iVar7);

      if (iVar6 != 0) {

        reaper_00530bd0(iVar7,0,0,0,0x1f,0);

      }

    }

    if (*(int *)(iVar5 + 0x1ec) != 0) {

      sound_interrupt_sequence(iVar5 + 0x1ec);

    }

    *(undefined4 *)(iVar5 + 0x140) = 0;

    if (*(int *)(iVar5 + 0x18c) == 0x13) {

      uVar4 = *(undefined4 *)(iVar5 + 0xfc);

      goto LAB_0047d6b8;

    }

LAB_0047d6cb:

    *(uint *)(iVar7 + 0xe0) = *(uint *)(iVar7 + 0xe0) & 0xfeffffff;

    iVar5 = reaper_0052e4a0(iVar7);

    if (iVar5 != 0) {

      reaper_00530bd0(iVar7,0,0,0,0x15,0);

    }

LAB_0047d6f9:

    if (((*(uint *)(iVar7 + 0xe0) & 0x2000000) != 0) && ((*(uint *)(iVar7 + 0xe0) & 0x4000000) == 0)

       ) {

      iVar5 = reaper_0052e4a0(iVar7);

      if (iVar5 != 0) {

        reaper_00530bd0(iVar7,0,0,0,0xc,0);

      }

      *(uint *)(iVar7 + 0xe0) = *(uint *)(iVar7 + 0xe0) | 0x4000000;

      *(undefined4 *)(iVar7 + 0x274) = 0;

      sound_play_player(0x572,iVar7);

    }

    sound_play_player(0x59d,iVar7);

    return;

  case 0x24:

    iVar5 = FUN_0052c5c0();

    if (iVar5 != 0) {

      return;

    }

    *(uint *)(iVar7 + 0xe0) = *(uint *)(iVar7 + 0xe0) & 0xefffffff;

    fVar10 = param_4[4];

    goto LAB_0047de23;

  case 0x25:

    iVar5 = FUN_0052c5c0();

    if (iVar5 == 0) {

      return;

    }

    fVar10 = 0.0;

LAB_0047de23:

    object_spawn_class(iVar7,param_4[3],param_4,fVar10);

    break;

  case 0x26:

    iVar5 = FUN_0052c5c0();

    if ((iVar5 != 0) && (iVar5 = objanim_select_animloop(*param_4), iVar5 != 0)) {

      iVar5 = menu_fx_spawn(iVar7,iVar5);

      *(undefined4 *)(iVar5 + 0x18c) = *(undefined4 *)(iVar7 + 0x18c);

      return;

    }

  }

  return;

}

/* ===== audio_listener_pan @ 0x0047DF10 ===== */
int audio_listener_pan(float param_1,float param_2,float param_3,code *param_4,undefined4 param_5)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  int iVar7;

  undefined4 *puVar8;

  float fVar9;

  float fVar10;

  float fVar11;

  float fVar12;

  float fVar13;

  float *pfVar14;

  int iVar15;

  int local_2c;

  

  pfVar14 = (float *)XFGetCameraOrigin();

  fVar1 = *pfVar14;

  fVar2 = pfVar14[1];

  fVar3 = pfVar14[2];

  pfVar14 = (float *)XFGetCameraAxis(2);

  fVar4 = *pfVar14;

  fVar5 = pfVar14[1];

  fVar6 = pfVar14[2];

  local_2c = 0;

  fVar9 = param_2 - param_1;

  param_2 = param_3;

  for (puVar8 = DAT_00632d6c; puVar8 != (undefined4 *)0x0; puVar8 = (undefined4 *)*puVar8) {

    iVar7 = puVar8[3];

    iVar15 = (*param_4)(iVar7,param_5);

    if ((iVar15 != 0) && ((*(uint *)(iVar7 + 0xd8) & 0x4000c000) == 0)) {

      fVar10 = (*(float *)(iVar7 + 0x288) + *(float *)(iVar7 + 0x27c)) * 0.5 -

               (fVar4 * param_1 + fVar1);

      fVar11 = (*(float *)(iVar7 + 0x28c) + *(float *)(iVar7 + 0x280)) * 0.5 -

               (fVar5 * param_1 + fVar2);

      fVar12 = (*(float *)(iVar7 + 0x290) + *(float *)(iVar7 + 0x284)) * 0.5 -

               (fVar6 * param_1 + fVar3);

      fVar13 = fVar10 * fVar4 + fVar11 * fVar5 + fVar12 * fVar6;

      if ((0.0 <= fVar13) &&

         ((fVar13 < fVar9 &&

          (fVar10 = (fVar10 * fVar10 + fVar11 * fVar11 + fVar12 * fVar12) - fVar13 * fVar13,

          fVar10 < param_2)))) {

        param_2 = fVar10;

        local_2c = iVar7;

      }

    }

  }

  return local_2c;

}

/* ===== mecc_fire_logic__FP6OBJECT @ 0x0047E0B0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void mecc_fire_logic__FP6OBJECT(int *param_1)



{

  uint *puVar1;

  char cVar2;

  int iVar3;

  undefined4 *puVar4;

  code *pcVar5;

  int iVar6;

  int iVar7;

  float *pfVar8;

  float fVar9;

  undefined4 uVar10;

  int iVar11;

  uint uVar12;

  char *pcVar13;

  undefined1 *puVar14;

  int *piVar15;

  float10 fVar16;

  char *pcVar17;

  undefined4 uVar18;

  float local_98;

  int *local_94;

  int *local_90;

  float local_8c;

  int local_88;

  int local_84;

  float local_80;

  float local_7c;

  float local_78;

  undefined4 local_74;

  float local_70;

  float local_6c;

  float local_68;

  float local_64;

  float local_60;

  float local_5c;

  code *local_58;

  float local_54;

  float local_50;

  float local_4c;

  float local_48;

  int local_44;

  undefined1 local_40 [16];

  undefined4 local_30;

  undefined4 local_2c;

  float local_28;

  undefined1 local_c [12];

  

  iVar3 = param_1[0x40];

  iVar6 = fx_create(param_1);

  if (iVar6 == 0) {

    uVar12 = param_1[0x37];

    if ((uVar12 & 0x20) != 0) {

      param_1[0x37] = uVar12 & 0xf7ffffdf;

      return;

    }

    if ((uVar12 & 0x8000000) == 0) {

      return;

    }

    param_1[0x37] = uVar12 | 0x20;

    return;

  }

  if (param_1 == DAT_00632a88) {

    _DAT_00632ba0 = 0;

    _DAT_00632ba4 = 0;

  }

  if (((param_1[0x38] & 0x20000U) != 0) && (puVar4 = DAT_00632d70, (char)param_1[0x83] < '\0')) {

    for (; puVar4 != (undefined4 *)0x0; puVar4 = (undefined4 *)*puVar4) {

      iVar6 = puVar4[3];

      if ((((*(uint *)(iVar6 + 0xd8) & 0x8000) == 0) && (*(int *)(iVar6 + 4) == 0x3df)) &&

         (*(int **)(iVar6 + 0x210) == param_1)) {

        if (0 < *(int *)(iVar6 + 0xf4)) {

          iVar11 = PROJ_GetCustom(1);

          puVar14 = &LAB_0047c620;

          if (iVar11 != 0) {

            puVar14 = *(undefined1 **)(iVar11 + 8);

          }

          project_cursor_to_ground(&local_80,0x44898000,&local_94);

          _DAT_00632ba4 = (uint)((float)local_94 < 1100.0);

          uVar10 = project_cursor_to_object(puVar14,param_1[99],local_94,&local_70);

          new_fire__FP6OBJECTiPfT0P3P3Df(param_1,1,0,uVar10,&local_70,0x43fa0000);

          *(int *)(iVar6 + 0xf4) = *(int *)(iVar6 + 0xf4) + -1;

          goto LAB_0047e183;

        }

        break;

      }

    }

    sound_play_player(0x5cc,param_1);

  }

LAB_0047e183:

  if (0.0 < *(float *)(iVar3 + 0x38)) {

    fVar16 = (float10)FUN_00518b70(param_1,0);

    *(float *)(iVar3 + 0x38) = (float)((float10)*(float *)(iVar3 + 0x38) - fVar16);

  }

  if (0.0 < *(float *)(iVar3 + 0x3c)) {

    fVar16 = (float10)FUN_00518b70(param_1,0);

    *(float *)(iVar3 + 0x3c) = (float)((float10)*(float *)(iVar3 + 0x3c) - fVar16);

  }

  param_1[0x37] = param_1[0x37] & 0xffffffdf;

  if ((param_1[0x38] & 0x20000U) == 0) {

    local_74 = WeaponIdGetPresent__FP6OBJECT(param_1);

    if ((*(byte *)(param_1 + 0x83) & 0x10) != 0) {

      if (*(int *)(iVar3 + 0x118) != 0) {

        puVar1 = (uint *)(*(int *)(iVar3 + 0x118) + 0xd8);

        *puVar1 = *puVar1 | 0x40000000;

      }

      sound_stop_player(0x5a5,param_1);

      iVar6 = param_1[0x40];

      if ((param_1[0x38] & 0x1000000U) != 0) {

        if (*(int *)(iVar6 + 0x144) != 0) {

          fx_delete(*(int *)(iVar6 + 0x144));

          *(undefined4 *)(iVar6 + 0x144) = 0;

          iVar11 = reaper_0052e4a0(param_1);

          if (iVar11 != 0) {

            reaper_00530bd0(param_1,0,0,0,0x1f,0);

          }

        }

        if (*(int *)(iVar6 + 0x1ec) != 0) {

          sound_interrupt_sequence(iVar6 + 0x1ec);

        }

        *(undefined4 *)(iVar6 + 0x140) = 0;

        if (*(int *)(iVar6 + 0x18c) == 0x13) {

          WeaponIdSetCurrent__FP6OBJECTi(param_1,*(undefined4 *)(iVar6 + 0xfc));

          *(undefined4 *)(iVar6 + 0xfc) = 0xffffffff;

        }

        param_1[0x38] = param_1[0x38] & 0xfeffffff;

        iVar6 = reaper_0052e4a0(param_1);

        if (iVar6 != 0) {

          reaper_00530bd0(param_1,0,0,0,0x15,0);

        }

      }

      WeaponIdCycleToNext__FP6OBJECTi(param_1,1);

      param_1[0x83] = param_1[0x83] & 0xfffffffe;

    }

    if ((*(byte *)(param_1 + 0x83) & 0x20) != 0) {

      if (*(int *)(iVar3 + 0x118) != 0) {

        puVar1 = (uint *)(*(int *)(iVar3 + 0x118) + 0xd8);

        *puVar1 = *puVar1 | 0x40000000;

      }

      sound_stop_player(0x5a5,param_1);

      iVar6 = param_1[0x40];

      if ((param_1[0x38] & 0x1000000U) != 0) {

        if (*(int *)(iVar6 + 0x144) != 0) {

          fx_delete(*(int *)(iVar6 + 0x144));

          *(undefined4 *)(iVar6 + 0x144) = 0;

          iVar11 = reaper_0052e4a0(param_1);

          if (iVar11 != 0) {

            reaper_00530bd0(param_1,0,0,0,0x1f,0);

          }

        }

        if (*(int *)(iVar6 + 0x1ec) != 0) {

          sound_interrupt_sequence(iVar6 + 0x1ec);

        }

        *(undefined4 *)(iVar6 + 0x140) = 0;

        if (*(int *)(iVar6 + 0x18c) == 0x13) {

          WeaponIdSetCurrent__FP6OBJECTi(param_1,*(undefined4 *)(iVar6 + 0xfc));

          *(undefined4 *)(iVar6 + 0xfc) = 0xffffffff;

        }

        param_1[0x38] = param_1[0x38] & 0xfeffffff;

        iVar6 = reaper_0052e4a0(param_1);

        if (iVar6 != 0) {

          reaper_00530bd0(param_1,0,0,0,0x15,0);

        }

      }

      WeaponIdCycleToNext__FP6OBJECTi(param_1,0);

      param_1[0x83] = param_1[0x83] & 0xfffffffe;

    }

    iVar6 = IconDefProjectile(local_74);

    local_88 = iVar6;

    local_84 = PROJ_DefGet(iVar6);

  }

  else {

    local_74 = 0xffffffff;

    local_88 = 0x18;

    local_84 = PROJ_DefGet(0x18);

    iVar6 = local_88;

  }

  piVar15 = (int *)0x0;

  if (param_1 == DAT_00632a88) {

    iVar7 = camera_cursor_fire();

    iVar11 = local_88;

    if ((iVar7 != 0) && ((iVar6 != 4 || (0.0 < *(float *)(iVar3 + 0x110))))) {

      iVar6 = PROJ_GetCustom(local_88);

      local_58 = (code *)&LAB_0047c620;

      if (iVar6 != 0) {

        local_58 = *(code **)(iVar6 + 8);

      }

      pcVar5 = local_58;

      project_cursor_to_ground(local_c,*(float *)(local_84 + 0x2c) * 1.2,&local_94);

      _DAT_00632ba4 = (uint)((float)local_94 < *(float *)(local_84 + 0x2c));

      if (iVar11 == 4) {

        if ((((*(byte *)(param_1 + 0x83) & 1) == 0) || (*(int *)(iVar3 + 0x214) != 0)) ||

           (((param_1[0x38] & 0x100000U) != 0 ||

            ((iVar6 = dialog_level_is_base(), iVar6 == 0 || (DAT_00633020 != 0)))))) {

          piVar15 = (int *)0x0;

        }

        else {

          local_44 = param_1[99];

          local_8c = *(float *)(DAT_00632ed8 + 0x914) * *(float *)(DAT_00632ed8 + 0x914);

          local_90 = local_94;

          local_98 = *(float *)(DAT_00632ed8 + 0x90c);

          pfVar8 = (float *)XFGetCameraOrigin();

          local_50 = *pfVar8;

          local_4c = pfVar8[1];

          local_48 = pfVar8[2];

          pfVar8 = (float *)XFGetCameraAxis(2);

          piVar15 = local_90;

          local_80 = *pfVar8;

          local_7c = pfVar8[1];

          local_78 = pfVar8[2];

          local_50 = local_80 * local_98 + local_50;

          local_4c = local_7c * local_98 + local_4c;

          local_48 = local_78 * local_98 + local_48;

          local_90 = (int *)0x0;

          local_54 = (float)piVar15 - local_98;

          piVar15 = local_90;

          for (puVar4 = DAT_00632d6c; local_90 = piVar15, puVar4 != (undefined4 *)0x0;

              puVar4 = (undefined4 *)*puVar4) {

            piVar15 = (int *)puVar4[3];

            iVar6 = (*local_58)(piVar15,local_44);

            if ((iVar6 != 0) && ((piVar15[0x36] & 0x4000c000U) == 0)) {

              local_64 = ((float)piVar15[0xa2] + (float)piVar15[0x9f]) * 0.5 - local_50;

              local_60 = ((float)piVar15[0xa3] + (float)piVar15[0xa0]) * 0.5 - local_4c;

              local_5c = ((float)piVar15[0xa4] + (float)piVar15[0xa1]) * 0.5 - local_48;

              local_98 = local_64 * local_80 + local_60 * local_7c + local_5c * local_78;

              if ((0.0 <= local_98) &&

                 ((local_98 < local_54 &&

                  (fVar9 = (local_64 * local_64 + local_60 * local_60 + local_5c * local_5c) -

                           local_98 * local_98, fVar9 < local_8c)))) {

                local_90 = piVar15;

                local_8c = fVar9;

              }

            }

            piVar15 = local_90;

          }

        }

      }

      else {

        piVar15 = (int *)project_cursor_to_object(pcVar5,param_1[99],local_94,&local_70);

      }

      if (piVar15 == param_1) {

        piVar15 = (int *)0x0;

      }

      *(int **)(iVar3 + 0x11c) = piVar15;

      *(int **)(iVar3 + 0x14) = piVar15;

      *(int **)(iVar3 + 0xdc) = piVar15;

      *(float *)(iVar3 + 0xe0) = local_70;

      *(float *)(iVar3 + 0xe4) = local_6c;

      *(float *)(iVar3 + 0xe8) = local_68;

      iVar6 = local_88;

    }

  }

  else {

    piVar15 = *(int **)(iVar3 + 0xdc);

    local_70 = *(float *)(iVar3 + 0xe0);

    local_6c = *(float *)(iVar3 + 0xe4);

    local_68 = *(float *)(iVar3 + 0xe8);

  }

  *(undefined4 *)(iVar3 + 0x120) = 0;

  if (iVar6 == 4) {

    piVar15 = *(int **)(iVar3 + 0x11c);

    *(undefined4 *)(iVar3 + 0x120) = 1;

    if (piVar15 != (int *)0x0) {

      local_70 = (float)piVar15[0x28];

      local_6c = (float)piVar15[0x29];

      local_68 = (float)piVar15[0x2a];

      goto LAB_0047e84d;

    }

    if (*(int *)(iVar3 + 0x118) == 0) goto LAB_0047e84d;

    *(undefined4 *)(iVar3 + 0x1dc) = 0;

    sound_stop_player(0x5a5,param_1);

    *(uint *)(*(int *)(iVar3 + 0x118) + 0xd8) =

         *(uint *)(*(int *)(iVar3 + 0x118) + 0xd8) | 0x40000000;

LAB_0047e8a3:

    fVar16 = (float10)*(float *)(DAT_00632ed8 + 0x8f4);

LAB_0047e8af:

    *(undefined4 *)(iVar3 + 0x114) = 0;

LAB_0047e8b9:

    *(float *)(iVar3 + 0x110) = (float)fVar16;

  }

  else {

LAB_0047e84d:

    if (piVar15 == (int *)0x0) goto LAB_0047e8a3;

    if (local_84 == 0) {

      local_98 = 1000.0;

    }

    else {

      local_98 = *(float *)(local_84 + 0x2c);

    }

    uVar10 = XFGetCameraOrigin(&local_70);

    fVar16 = (float10)FUN_0050a610(uVar10);

    if (fVar16 < (float10)local_98 * (float10)local_98) {

      if ((param_1 == DAT_00632a88) && (piVar15[0x78] != 0)) {

        _DAT_00632ba0 = 1;

      }

      if (iVar6 != 4) {

        fVar16 = (float10)*(float *)(DAT_00632ed8 + 0x8f4);

        goto LAB_0047e8af;

      }

      iVar6 = item_get_ammo(param_1,local_74,0);

      if (iVar6 < 1) {

        fVar16 = (float10)*(float *)(DAT_00632ed8 + 0x8f4);

        goto LAB_0047e8af;

      }

      fVar16 = (float10)FUN_00518b70(param_1,0);

      fVar16 = (float10)*(float *)(iVar3 + 0x110) - fVar16;

      goto LAB_0047e8b9;

    }

  }

  local_98 = (float)gun_find_right(param_1);

  if (local_98 == 0.0) {

    return;

  }

  if (((((*(byte *)(param_1 + 0x83) & 1) == 0) || (*(int *)(iVar3 + 0x214) != 0)) ||

      (iVar6 = dialog_level_is_base(), iVar6 == 0)) ||

     ((DAT_00633020 != 0 || (uVar12 = param_1[0x38], (uVar12 & 0x100000) != 0)))) {

    if (*(int *)(iVar3 + 0x19c) != 0) {

      iVar6 = reaper_0052e4a0(param_1);

      if (iVar6 != 0) {

        reaper_00530bd0(param_1,0,0,0,0x1d,0);

      }

      fx_delete(*(undefined4 *)(iVar3 + 0x19c));

      *(undefined4 *)(iVar3 + 0x19c) = 0;

      ANM_DumpCluster(param_1,1);

    }

    if (*(int *)(iVar3 + 0x1fc) != 0) {

      iVar6 = reaper_0052e4a0(param_1);

      if (iVar6 != 0) {

        reaper_00530bd0(param_1,0,0,0,0x22,0);

      }

      sound_stop_sequence(iVar3 + 0x1fc);

    }

    uVar10 = local_74;

    if (local_88 == 0x13) {

      iVar6 = param_1[0x40];

      if (*(int *)(iVar6 + 0x144) != 0) {

        fx_delete(*(int *)(iVar6 + 0x144));

        *(undefined4 *)(iVar6 + 0x144) = 0;

        iVar11 = reaper_0052e4a0(param_1);

        if (iVar11 != 0) {

          reaper_00530bd0(param_1,0,0,0,0x1f,0);

        }

      }

      if (*(int *)(iVar6 + 0x1ec) != 0) {

        sound_interrupt_sequence(iVar6 + 0x1ec);

      }

      *(undefined4 *)(iVar6 + 0x140) = 0;

    }

    else if (((local_88 == 4) &&

             (*(float *)(iVar3 + 0x110) < 0.0 != (*(float *)(iVar3 + 0x110) == 0.0))) &&

            (((*(byte *)(param_1 + 0x83) & 0x30) == 0 &&

             ((local_84 != 0 && (iVar6 = item_get_ammo(param_1,local_74,0), 0 < iVar6)))))) {

      XFGetViewportExt(&local_54,&local_44,&local_98,&local_80);

      sine_cos_lookup(local_54,&local_8c,&local_58);

      sine_cos_lookup(local_44,&local_94,&local_90);

      local_70 = (float)local_90 * local_8c * 2000.0 + local_80;

      local_6c = -((float)local_90 * (float)local_58) * 2000.0 + local_7c;

      local_68 = (float)local_94 * 2000.0 + local_78;

      iVar6 = new_fire__FP6OBJECTiPfT0P3P3Df

                        (param_1,4,iVar3 + 0x38,*(undefined4 *)(iVar3 + 0x11c),&local_70,0x43fa0000)

      ;

      if (iVar6 != 0) {

        item_use_ammo(param_1,uVar10);

      }

      if (*(int *)(iVar3 + 0x118) != 0) {

        sound_stop_player(0x5a5,param_1);

        *(undefined4 *)(iVar3 + 0x1dc) = 0;

        *(uint *)(*(int *)(iVar3 + 0x118) + 0xd8) =

             *(uint *)(*(int *)(iVar3 + 0x118) + 0xd8) | 0x40000000;

      }

    }

    uVar10 = *(undefined4 *)(DAT_00632ed8 + 0x8f4);

    *(undefined4 *)(iVar3 + 0x114) = 0;

    *(undefined4 *)(iVar3 + 0x110) = uVar10;

    goto LAB_0047f2bb;

  }

  if (*(float *)(iVar3 + 0x38) < 0.0 != (*(float *)(iVar3 + 0x38) == 0.0)) {

    if ((uVar12 & 0x100) == 0) {

      if ((param_1[0x5d] < 1) || (fVar9 = (float)gun_find_left(param_1), fVar9 == 0.0))

      goto LAB_0047ea17;

      uVar12 = param_1[0x38] | 0x100;

      local_98 = fVar9;

    }

    else {

      uVar12 = uVar12 & 0xfffffeff;

    }

    param_1[0x38] = uVar12;

  }

LAB_0047ea17:

  if (local_84 == 0) {

LAB_0047eba7:

    if (local_88 != 0x13) {

      if (local_88 == 4) {

        if (*(float *)(iVar3 + 0x110) < 0.0 != (*(float *)(iVar3 + 0x110) == 0.0)) {

          *(undefined4 *)(iVar3 + 0x114) = 1;

          iVar6 = in_fov(param_1,*(undefined4 *)(iVar3 + 0x11c),

                         *(undefined4 *)(DAT_00632ed8 + 0x8f8));

          if (iVar6 == 0) {

            sound_stop_player(0x5a5,param_1);

            *(undefined4 *)(iVar3 + 0x1dc) = 0;

            *(undefined4 *)(iVar3 + 0x11c) = 0;

            uVar10 = *(undefined4 *)(DAT_00632ed8 + 0x8f4);

            *(undefined4 *)(iVar3 + 0x114) = 0;

            *(undefined4 *)(iVar3 + 0x110) = uVar10;

          }

        }

        if (*(int *)(iVar3 + 0x11c) == 0) {

          sound_stop_player(0x5a5,param_1);

          *(undefined4 *)(iVar3 + 0x1dc) = 0;

          if (*(int *)(iVar3 + 0x118) != 0) {

            puVar1 = (uint *)(*(int *)(iVar3 + 0x118) + 0xd8);

            *puVar1 = *puVar1 | 0x40000000;

          }

        }

        else {

          if (*(int *)(iVar3 + 0x1dc) == 0) {

            sound_play_player(0x5a5,param_1);

            *(undefined4 *)(iVar3 + 0x1dc) = 1;

          }

          if (*(int *)(iVar3 + 0x118) == 0) {

            uVar10 = object_allocate_type(0x3d4,0);

            *(undefined4 *)(iVar3 + 0x118) = uVar10;

          }

          puVar1 = (uint *)(*(int *)(iVar3 + 0x118) + 0xd8);

          *puVar1 = *puVar1 & 0xbfffffff;

          puVar1 = (uint *)(*(int *)(iVar3 + 0x118) + 0xd8);

          *puVar1 = *puVar1 | 0x10000;

          GEO_MatIdentity(*(int *)(iVar3 + 0x118) + 0x294);

          SphereFitToObject(*(int *)(iVar3 + 0x118) + 0x294,piVar15,0x40000000);

        }

      }

      goto LAB_0047f2bb;

    }

  }

  else {

    iVar6 = item_get_ammo(param_1,local_74,0);

    if (iVar6 < 1) {

      if (*(int *)(iVar3 + 0x19c) != 0) {

        iVar6 = reaper_0052e4a0(param_1);

        if (iVar6 != 0) {

          reaper_00530bd0(param_1,0,0,0,0x1d,0);

        }

        fx_delete(*(undefined4 *)(iVar3 + 0x19c));

        *(undefined4 *)(iVar3 + 0x19c) = 0;

        ANM_DumpCluster(param_1,1);

      }

      if (*(int *)(iVar3 + 0x1fc) != 0) {

        iVar6 = reaper_0052e4a0(param_1);

        if (iVar6 != 0) {

          reaper_00530bd0(param_1,0,0,0,0x22,0);

        }

        sound_stop_sequence(iVar3 + 0x1fc);

      }

      if (*(float *)(iVar3 + 0x3c) < 0.0 != (*(float *)(iVar3 + 0x3c) == 0.0)) {

        sound_play_player(0x5cc,param_1);

        *(undefined4 *)(iVar3 + 0x3c) = 0x3f000000;

      }

      goto LAB_0047eba7;

    }

    *(undefined4 *)(iVar3 + 0x3c) = 0x3f000000;

    if (local_88 == 0x10) {

      if (*(int *)(iVar3 + 0x19c) == 0) {

        puVar14 = local_40;

        uVar18 = 0x24;

        pcVar17 = s_fx_nozzle_machine_0055bd14;

        local_28 = local_98;

        local_2c = 1;

        local_30 = 8;

        uVar10 = fx_get_free_effect__Fv();

        *(undefined4 *)(iVar3 + 0x19c) = uVar10;

        iVar6 = reaper_0052e4a0(param_1,pcVar17,uVar18,puVar14);

        if (iVar6 != 0) {

          reaper_00530bd0(param_1,0,0,0,0x1c,0);

        }

        ANM_DumpCluster(param_1,1);

      }

LAB_0047eacc:

      iVar6 = new_fire__FP6OBJECTiPfT0P3P3Df

                        (param_1,local_88,iVar3 + 0x38,piVar15,&local_70,0x43fa0000);

      if (iVar6 != 0) {

        item_use_ammo(param_1,local_74);

      }

      goto LAB_0047eba7;

    }

    if (local_88 == 4) goto LAB_0047eba7;

    if (local_88 != 0x13) goto LAB_0047eacc;

  }

  *(undefined4 *)(iVar3 + 0x140) = 0;

  fVar16 = (float10)FUN_00518b70(param_1,0);

  *(float *)(iVar3 + 0x13c) = (float)((float10)*(float *)(iVar3 + 0x13c) - fVar16);

  if ((*(float *)(DAT_00632ed8 + 0x69c) < *(float *)(iVar3 + 400) !=

       (*(float *)(DAT_00632ed8 + 0x69c) == *(float *)(iVar3 + 400))) ||

     ((*(int *)(iVar3 + 0x144) != 0 && (0.0 < *(float *)(iVar3 + 400))))) {

    local_80 = -(float)param_1[0xa7];

    local_7c = -(float)param_1[0xab];

    local_78 = -(float)param_1[0xaf];

    normalize__FPfN20(&local_80,&local_7c,&local_78);

    local_64 = *(float *)(DAT_00632ed8 + 0xfa8) * local_80 + (float)param_1[0x28];

    local_8c = 0.0;

    local_94 = DAT_00632d68;

    local_60 = *(float *)(DAT_00632ed8 + 0xfa8) * local_7c + (float)param_1[0x29];

    local_5c = *(float *)(DAT_00632ed8 + 0xfa8) * local_78 + (float)param_1[0x2a];

    if (DAT_00632d68 != (int *)0x0) {

      do {

        iVar6 = local_94[3];

        local_90 = (int *)(*(float *)(DAT_00632ed8 + 0xfa8) + *(float *)(iVar6 + 0x154));

        fVar16 = (float10)FUN_0050a610(iVar6 + 0xa0,&local_64);

        if ((fVar16 <= (float10)(float)local_90 * (float10)(float)local_90) &&

           (iVar11 = repairgun_target_valid__FP6OBJECTi(iVar6,param_1[99]), iVar11 != 0)) {

          iVar11 = FUN_004a6220(iVar6);

          if ((iVar11 == 0) || (3 < *(int *)(iVar6 + 0xe4))) {

            *(undefined4 *)(iVar3 + 0x140) = 1;

            if (*(float *)(iVar3 + 0x13c) < 0.0 != (*(float *)(iVar3 + 0x13c) == 0.0)) {

              iVar11 = ObjIsMecc(iVar6);

              if (iVar11 == 0) {

                fVar9 = *(float *)(DAT_00632ed8 + 0xfac);

              }

              else {

                fVar9 = *(float *)(DAT_00632ed8 + 0x137c);

              }

              obj_damage_apply(0x12,-fVar9,iVar6,0,iVar6 + 0xa0,0);

            }

          }

          else if (param_1 == DAT_00632a88) {

            local_8c = 1.4013e-45;

          }

        }

        local_94 = (int *)*local_94;

      } while (local_94 != (int *)0x0);

      local_94 = (int *)0x0;

    }

    if (*(int *)(iVar3 + 0x140) != 1) {

      if (local_8c != 0.0) {

        pcVar17 = (char *)FUN_00507b00(s_HintWaitRepair_0055bd28);

        pcVar13 = &DAT_00632c10;

        do {

          cVar2 = *pcVar17;

          pcVar17 = pcVar17 + 1;

          *pcVar13 = cVar2;

          pcVar13 = pcVar13 + 1;

        } while (cVar2 != '\0');

        _DAT_00632d10 = 0x3f800000;

      }

      goto LAB_0047ec06;

    }

    if (*(float *)(iVar3 + 0x13c) < 0.0 != (*(float *)(iVar3 + 0x13c) == 0.0)) {

      *(undefined4 *)(iVar3 + 0x13c) = *(undefined4 *)(DAT_00632ed8 + 0xfb0);

    }

  }

  else {

LAB_0047ec06:

    iVar6 = param_1[0x40];

    if (*(int *)(iVar6 + 0x144) != 0) {

      fx_delete(*(int *)(iVar6 + 0x144));

      *(undefined4 *)(iVar6 + 0x144) = 0;

      iVar11 = reaper_0052e4a0(param_1);

      if (iVar11 != 0) {

        reaper_00530bd0(param_1,0,0,0,0x1f,0);

      }

    }

    if (*(int *)(iVar6 + 0x1ec) != 0) {

      sound_interrupt_sequence(iVar6 + 0x1ec);

    }

    *(undefined4 *)(iVar6 + 0x140) = 0;

  }

  if (*(int *)(iVar3 + 0x140) != 0) {

    fVar16 = (float10)FUN_00518b70(param_1,0);

    fVar16 = (float10)*(float *)(iVar3 + 400) - fVar16 * (float10)*(float *)(DAT_00632ed8 + 0xfa4);

    *(float *)(iVar3 + 400) = (float)fVar16;

    if (fVar16 < (float10)0.0 != (fVar16 == (float10)0.0)) {

      *(undefined4 *)(iVar3 + 400) = 0;

    }

    if ((*(int *)(iVar3 + 0x144) == 0) && (local_98 != 0.0)) {

      local_28 = local_98;

      local_2c = 1;

      local_30 = 8;

      if (*(int *)(iVar3 + 0x140) == 2) {

        iVar6 = local_84 + 0x98;

      }

      else {

        iVar6 = local_84 + 0x78;

      }

      puVar14 = local_40;

      uVar18 = 0x24;

      uVar10 = fx_get_free_effect__Fv();

      *(undefined4 *)(iVar3 + 0x144) = uVar10;

      iVar6 = reaper_0052e4a0(param_1,iVar6,uVar18,puVar14);

      if (iVar6 != 0) {

        reaper_00530bd0(param_1,0,0,0,0x1e,0);

      }

    }

    if (*(int *)(iVar3 + 0x1ec) == 0) {

      uVar10 = sound_get_free_sequence__Fv();

      *(undefined4 *)(iVar3 + 0x1ec) = uVar10;

    }

  }

LAB_0047f2bb:

  if (*(float *)(iVar3 + 0x38) < 0.0) {

    *(undefined4 *)(iVar3 + 0x38) = 0;

  }

  if ((*(byte *)(param_1 + 0x83) & 1) == 0) {

    param_1[0x37] = param_1[0x37] & 0xf7ffffff;

    param_1[0x38] = param_1[0x38] & 0xffefffff;

  }

  else if (*(int *)(iVar3 + 0x214) == 0) {

    param_1[0x37] = param_1[0x37] | 0x8000000;

    return;

  }

  return;

}

/* ===== mecc_indicate_shots_fired__FP6OBJECT @ 0x0047F330 ===== */
/* PS2 candidate: mecc_indicate_shots_fired__FP6OBJECT (conf 0.342) */



void mecc_indicate_shots_fired__FP6OBJECT(int param_1)



{

  DAT_00632b40 = param_1;

  DAT_00632b44 = DAT_006328e8;

  DAT_00632b48 = *(undefined4 *)(param_1 + 0xa0);

  DAT_00632b4c = *(undefined4 *)(param_1 + 0xa4);

  DAT_00632b50 = *(undefined4 *)(param_1 + 0xa8);

  return;

}

/* ===== mecc_calc_thrust_for_height @ 0x0047F370 ===== */
/* PS2 candidate: mecc_calc_thrust_for_height (conf 0.453) */



void mecc_calc_thrust_for_height(int param_1,float param_2)



{

  float fVar1;

  int iVar2;

  float fVar3;

  undefined1 uVar4;

  float10 fVar5;

  float local_10;

  float local_c;

  float local_8;

  float local_4;

  

  iVar2 = *(int *)(param_1 + 0x100);

  fVar5 = (float10)FUN_00518b70(param_1,0);

  fVar1 = (float)fVar5;

  mecc_get_thrust__FP6OBJECTfPfT2(param_1,0x3f800000,&local_c,&local_10);

  fVar3 = local_c * fVar1 * 4.0 + *(float *)(param_1 + 0x108);

  local_8 = fVar1 * *(float *)(param_1 + 0x1b8);

  if (local_10 < fVar3 - local_8) {

    fVar3 = local_10;

  }

  fVar3 = ((fVar3 - local_8 * 4.0) + *(float *)(param_1 + 0x108)) * fVar1;

  local_4 = fVar3 + fVar3 + *(float *)(param_1 + 0xa8);

  mecc_get_thrust__FP6OBJECTfPfT2(param_1,0x3f000000,&local_c,&local_10);

  fVar3 = local_c * fVar1 * 4.0 + *(float *)(param_1 + 0x108);

  if (local_10 < fVar3) {

    fVar3 = local_10;

  }

  local_8 = fVar1 * *(float *)(param_1 + 0x1b8) * 4.0;

  fVar3 = ((fVar3 - local_8) + *(float *)(param_1 + 0x108)) * fVar1;

  local_10 = fVar3 + fVar3 + *(float *)(param_1 + 0xa8);

  fVar1 = ((*(float *)(param_1 + 0x108) - local_8) + *(float *)(param_1 + 0x108)) * fVar1;

  if (fVar1 + fVar1 + *(float *)(param_1 + 0xa8) < param_2) {

    if ((local_10 < param_2) && (local_4 < param_2)) {

      *(undefined1 *)(iVar2 + 0x138) = 0x20;

      return;

    }

    uVar4 = __ftol();

    *(undefined1 *)(iVar2 + 0x138) = uVar4;

    return;

  }

  *(undefined1 *)(iVar2 + 0x138) = 0;

  return;

}

/* ===== mecc_get_thrust__FP6OBJECTfPfT2 @ 0x0047F520 ===== */
/* PS2 candidate: mecc_get_thrust__FP6OBJECTfPfT2 (conf 0.437) */



void mecc_get_thrust__FP6OBJECTfPfT2(float param_1,float param_2,float *param_3,float *param_4)



{

  float fVar1;

  float fVar2;

  int iVar3;

  float10 fVar4;

  float10 fVar5;

  

  iVar3 = (int)param_1;

  fVar4 = (float10)obj_get_last_ground_z(param_1);

  if (((param_1 != (float)DAT_00632a88) &&

      (*(int *)((int)param_1 + 0x170) == *(int *)(DAT_00632a88 + 0x170))) &&

     (fVar4 < (float10)*(float *)(DAT_00632a88 + 0x140))) {

    fVar4 = (float10)*(float *)(DAT_00632a88 + 0x140);

  }

  fVar5 = (float10)*(float *)(DAT_00632ed8 + 0x5e0);

  if (*(int *)((int)param_1 + 0x174) == 0) {

    fVar5 = fVar5 * (float10)*(float *)(DAT_00632ed8 + 0x5dc);

  }

  if ((*(uint *)((int)param_1 + 0xe0) & 0x20000000) != 0) {

    fVar5 = fVar5 * (float10)*(float *)(DAT_00632ed8 + 0x400);

  }

  if ((*(uint *)((int)param_1 + 0xe0) & 0x40000000) != 0) {

    fVar5 = fVar5 * (float10)*(float *)(DAT_00632ed8 + 0x3fc);

  }

  fVar4 = (float10)1.0 - ((float10)1.0 / fVar5) * ((float10)*(float *)((int)param_1 + 0xa8) - fVar4)

  ;

  if ((float10)1.0 < fVar4) {

    fVar4 = (float10)1.0;

  }

  fVar1 = 1.0 - (1.0 / *(float *)((int)param_1 + 0x194)) *

                (ABS(*(float *)((int)param_1 + 0x10c)) + ABS(*(float *)((int)param_1 + 0x110)));

  if (fVar1 < *(float *)(DAT_00632ed8 + 0x5e4)) {

    fVar1 = *(float *)(DAT_00632ed8 + 0x5e4);

  }

  fVar2 = *(float *)(DAT_00632ed8 + 0x5ec);

  fVar4 = (((float10)*(float *)(DAT_00632ed8 + 0x5e8) - (float10)*(float *)((int)param_1 + 0x1b8)) *

           fVar4 + (float10)*(float *)((int)param_1 + 0x1b8)) * (float10)param_2;

  if (fVar4 < (float10)0.0) {

    fVar4 = (float10)0.0;

  }

  param_1 = (float)fVar4;

  if (((iVar3 != DAT_00632a88) || (*(int *)(iVar3 + 0x224) != 0)) ||

     ((0.64278 <= *(float *)(iVar3 + 0x14c) || (*(float *)(iVar3 + 0x14c) == 0.0)))) {

LAB_0047f6e9:

    if (fVar4 != (float10)0.0) goto LAB_0047f714;

  }

  else {

    if (*(float *)(iVar3 + 0x108) < 0.0) {

      fVar4 = (float10)FUN_00518b70(iVar3,0);

      if (fVar4 * (float10)param_1 + (float10)*(float *)(iVar3 + 0x108) < (float10)0.0) {

        fVar4 = (float10)param_1;

      }

      else {

        fVar4 = (float10)FUN_00518b70(iVar3,0);

        fVar4 = -((float10)*(float *)(iVar3 + 0x108) / fVar4);

      }

      goto LAB_0047f6e9;

    }

    fVar4 = (float10)0.0;

  }

  if ((*(uint *)(iVar3 + 0xd8) & 0x8000000) != 0) {

    fVar4 = ((float10)*(float *)(DAT_00632ed8 + 0x404) + (float10)*(float *)(iVar3 + 0x1b8)) *

            (float10)param_2;

  }

LAB_0047f714:

  *param_3 = (float)fVar4;

  *param_4 = fVar2 * fVar1;

  return;

}

/* ===== mecc_in_gyro @ 0x0047F730 ===== */
/* PS2 candidate: mecc_in_gyro (conf 0.508) */



uint mecc_in_gyro(int param_1)



{

  return *(uint *)(param_1 + 0xe0) & 0x20000;

}

/* ===== mecc_jet @ 0x0047F740 ===== */
/* PS2 candidate: mecc_jet (conf 0.525) */



void mecc_jet(float param_1)



{

  float fVar1;

  int iVar2;

  undefined4 *puVar3;

  bool bVar4;

  float fVar5;

  int iVar6;

  int iVar7;

  undefined4 uVar8;

  uint uVar9;

  bool bVar10;

  float10 fVar11;

  float local_5c;

  float local_50;

  float local_4c;

  float local_48;

  undefined1 local_44 [68];

  

  fVar5 = param_1;

  iVar2 = *(int *)((int)param_1 + 0x100);

  bVar4 = false;

  if (DAT_00632ba8 != 0) {

    *(uint *)((int)param_1 + 0x20c) = *(uint *)((int)param_1 + 0x20c) & 0xfffffbff;

  }

  if (*(int *)((int)param_1 + 0x174) == 0) {

    if (((*(uint *)((int)param_1 + 0x20c) & 0x400) == 0) || (*(int *)(iVar2 + 0x214) != 0)) {

      *(undefined1 *)(iVar2 + 0x138) = 0;

    }

    else {

      *(undefined1 *)(iVar2 + 0x138) = 0x20;

    }

  }

  else {

    *(float *)(*(int *)((int)param_1 + 0x104) + 8) = *(float *)(DAT_00632ed8 + 0x678) * 0.4;

  }

  fVar11 = (float10)FUN_00518b70(param_1,0);

  fVar11 = (float10)*(float *)(iVar2 + 0x134) - fVar11;

  *(float *)(iVar2 + 0x134) = (float)fVar11;

  if ((**(int **)((int)fVar5 + 8) == 0x85) || ((float10)0.0 < fVar11)) {

    *(uint *)((int)fVar5 + 0x20c) = *(uint *)((int)fVar5 + 0x20c) & 0xfffffbff;

  }

  if ((fVar5 == DAT_00632a88) && (iVar6 = dialog_level_is_base(), iVar6 != 0)) {

    if ((*(byte *)((int)DAT_00632a88 + 0x20c) & 2) == 0) {

      camera_override_done();

    }

    else {

      param_1 = 0.0;

      iVar6 = ref_get_anode2(local_44,&param_1,fVar5,*(undefined4 *)((int)fVar5 + 0x10),0xe,0);

      if (iVar6 == 0) {

        ref_get_anode2(local_44,&param_1,fVar5,1,0xe,0);

      }

      camera_override_begin(local_44);

      AudioSetSpeakerConfig__F14SPEAKER_SYSTEM(param_1);

    }

  }

  if ((((*(uint *)((int)fVar5 + 0xe0) & 0x2000000) != 0) || (*(char *)(iVar2 + 0x138) == '\0')) ||

     ((*(float *)(iVar2 + 400) <= *(float *)(DAT_00632ed8 + 0x69c) &&

      (((*(uint *)((int)fVar5 + 0xd8) & 0x1000) == 0 || (*(float *)(iVar2 + 400) <= 0.0)))))) {

    *(undefined4 *)(iVar2 + 0xc4) = 0;

    *(uint *)((int)fVar5 + 0xd8) = *(uint *)((int)fVar5 + 0xd8) & 0xffffefff;

    if ((**(int **)((int)fVar5 + 8) != 0x85) &&

       (((*(uint *)((int)fVar5 + 0xe0) & 0x2800000) == 0 && (*(int *)(iVar2 + 0x140) == 0)))) {

      if ((*(uint *)((int)fVar5 + 0xe0) & 0x20000) == 0) {

        fVar11 = (float10)FUN_00518b70(fVar5,0);

        fVar11 = fVar11 * (float10)*(float *)(DAT_00632ed8 + 0x6a0);

      }

      else {

        fVar11 = (float10)FUN_00518b70(fVar5,0);

        fVar11 = fVar11 * (float10)*(float *)(DAT_00632ed8 + 0xac4);

      }

      param_1 = (float)fVar11;

      iVar6 = SpecialWeaponIdGet__FP6OBJECT(fVar5);

      fVar1 = param_1;

      if (iVar6 == 0x12) {

        fVar1 = *(float *)(DAT_00632ed8 + 0x7f8) * param_1;

      }

      fVar1 = fVar1 + *(float *)(iVar2 + 400);

      *(float *)(iVar2 + 400) = fVar1;

      if (100.0 < fVar1) {

        *(undefined4 *)(iVar2 + 400) = 0x42c80000;

      }

    }

  }

  else {

    bVar4 = true;

    if ((*(uint *)((int)fVar5 + 0xe0) & 0x20000) == 0) {

      param_1 = *(float *)(DAT_00632ed8 + 0x690) / *(float *)((int)fVar5 + 0xc4);

    }

    else {

      param_1 = *(float *)(DAT_00632ed8 + 0xaac) / *(float *)((int)fVar5 + 0xc4);

    }

    param_1 = (float)(int)*(char *)(iVar2 + 0x138) * 0.03125 * param_1;

    if (((*(uint *)((int)fVar5 + 0x20c) & 0x800) != 0) && (1.0 <= *(float *)(iVar2 + 0xbc))) {

      sound_play_player(0x5b3,fVar5);

      *(undefined4 *)(iVar2 + 0xc0) = 0x40400000;

      *(undefined4 *)(iVar2 + 0xc4) = 1;

    }

    if ((*(int *)(iVar2 + 0xc4) == 0) || (*(float *)(iVar2 + 0xbc) <= 0.0)) {

      *(undefined4 *)(iVar2 + 0xc4) = 0;

    }

    else {

      if ((*(uint *)((int)fVar5 + 0xe0) & 0x20000) == 0) {

        param_1 = *(float *)(DAT_00632ed8 + 0x6ac) * param_1;

        fVar11 = (float10)FUN_00518b70(fVar5,0);

        fVar11 = fVar11 * (float10)*(float *)(DAT_00632ed8 + 0x6a8);

      }

      else {

        param_1 = *(float *)(DAT_00632ed8 + 0xab0) * param_1;

        fVar11 = (float10)FUN_00518b70(fVar5,0);

        fVar11 = fVar11 * (float10)*(float *)(DAT_00632ed8 + 0xab4);

      }

      *(float *)(iVar2 + 0xbc) = (float)((float10)*(float *)(iVar2 + 0xbc) - fVar11);

      if (*(float *)(iVar2 + 0xbc) < 0.0) {

        *(undefined4 *)(iVar2 + 0xbc) = 0;

      }

    }

    uVar9 = *(uint *)((int)fVar5 + 0xe0) & 0x20000;

    if (uVar9 == 0) {

      local_5c = (float)(int)*(char *)((int)fVar5 + 0x20a) * 0.03125 *

                 *(float *)(DAT_00632ed8 + 0x6d8);

      fVar1 = (float)(int)*(char *)((int)fVar5 + 0x20b) * 0.03125 * *(float *)(DAT_00632ed8 + 0x6d8)

      ;

    }

    else {

      local_5c = (float)(int)*(char *)((int)fVar5 + 0x20a) * 0.03125 *

                 *(float *)(DAT_00632ed8 + 0xab8);

      fVar1 = (float)(int)*(char *)((int)fVar5 + 0x20b) * 0.03125 * *(float *)(DAT_00632ed8 + 0xab8)

      ;

    }

    if ((local_5c != 0.0) && (fVar1 != 0.0)) {

      fVar1 = fVar1 * 0.7071;

      local_5c = local_5c * 0.7071;

    }

    local_50 = fVar1 * *(float *)((int)fVar5 + 0x298) + -(local_5c * *(float *)((int)fVar5 + 0x29c))

    ;

    local_4c = fVar1 * *(float *)((int)fVar5 + 0x2a8) + -(local_5c * *(float *)((int)fVar5 + 0x2ac))

    ;

    if (uVar9 == 0) {

      local_48 = *(float *)(DAT_00632ed8 + 0x6d8) * *(float *)(DAT_00632ed8 + 0x5f4);

    }

    else {

      local_48 = *(float *)(DAT_00632ed8 + 0xabc) * *(float *)(DAT_00632ed8 + 0xab8);

    }

    local_48 = local_48 +

               fVar1 * *(float *)((int)fVar5 + 0x2b8) + -(local_5c * *(float *)((int)fVar5 + 700));

    normalize__FPfN20(&local_50,&local_4c,&local_48);

    if (*(float *)(DAT_00632ed8 + 0x157c) * 0.5 < *(float *)((int)fVar5 + 0xa8)) {

      local_48 = 0.0;

    }

    *(float *)(*(int *)((int)fVar5 + 0x104) + 0x18) =

         local_50 * param_1 + *(float *)(*(int *)((int)fVar5 + 0x104) + 0x18);

    *(float *)(*(int *)((int)fVar5 + 0x104) + 0x1c) =

         local_4c * param_1 + *(float *)(*(int *)((int)fVar5 + 0x104) + 0x1c);

    *(float *)(*(int *)((int)fVar5 + 0x104) + 0x20) =

         local_48 * param_1 + *(float *)(*(int *)((int)fVar5 + 0x104) + 0x20);

    *(uint *)((int)fVar5 + 0xd8) = *(uint *)((int)fVar5 + 0xd8) | 0x1000;

    if ((fVar5 == DAT_00632a88) ||

       (*(int *)((int)fVar5 + 0x170) != *(int *)((int)DAT_00632a88 + 0x170))) {

      if ((*(uint *)((int)fVar5 + 0xe0) & 0x20000) == 0) {

        fVar11 = (float10)FUN_00518b70(fVar5,0);

        param_1 = (float)(int)*(char *)(iVar2 + 0x138);

        fVar11 = (float10)(int)param_1 * (float10)0.03125 * fVar11 *

                 (float10)*(float *)(DAT_00632ed8 + 0x6a4);

      }

      else {

        fVar11 = (float10)FUN_00518b70(fVar5,0);

        param_1 = (float)(int)*(char *)(iVar2 + 0x138);

        fVar11 = (float10)(int)param_1 * (float10)0.03125 * fVar11 *

                 (float10)*(float *)(DAT_00632ed8 + 0xac0);

      }

      *(float *)(iVar2 + 400) = (float)((float10)*(float *)(iVar2 + 400) - fVar11);

    }

    if (*(float *)(iVar2 + 400) < 0.0 != (*(float *)(iVar2 + 400) == 0.0)) {

      mecc_disable_personal_shield(fVar5);

      if (((*(uint *)((int)fVar5 + 0xe0) & 0x2000000) != 0) &&

         ((*(uint *)((int)fVar5 + 0xe0) & 0x4000000) == 0)) {

        iVar6 = reaper_0052e4a0(fVar5);

        if (iVar6 != 0) {

          reaper_00530bd0(fVar5,0,0,0,0xc,0);

        }

        *(uint *)((int)fVar5 + 0xe0) = *(uint *)((int)fVar5 + 0xe0) | 0x4000000;

        *(undefined4 *)((int)fVar5 + 0x274) = 0;

        sound_play_player(0x572,fVar5);

      }

      *(undefined4 *)(iVar2 + 400) = 0;

    }

  }

  if (*(int *)(iVar2 + 0xc4) == 0) {

    fVar11 = (float10)FUN_00518b70(fVar5,0);

    fVar1 = (float)((float10)*(float *)(iVar2 + 0xc0) - fVar11);

    *(float *)(iVar2 + 0xc0) = fVar1;

    if ((*(uint *)((int)fVar5 + 0xe0) & 0x20000) == 0) {

      param_1 = 0.0;

      if ((((char)**(uint **)((int)fVar5 + 0x104) < '\0') &&

          ((**(uint **)((int)fVar5 + 0x104) & 0x40) == 0)) && (fVar1 < 0.0 != (fVar1 == 0.0))) {

        param_1 = 1.0;

      }

    }

    else {

      fVar11 = (float10)FUN_00518b70(fVar5,0);

      param_1 = (float)(fVar11 * (float10)*(float *)(DAT_00632ed8 + 0xac8));

    }

    iVar6 = SpecialWeaponIdGet__FP6OBJECT(fVar5);

    if (iVar6 == 0x12) {

      param_1 = *(float *)(DAT_00632ed8 + 0x7f8) * param_1;

    }

    param_1 = param_1 + *(float *)(iVar2 + 0xbc);

    *(float *)(iVar2 + 0xbc) = param_1;

    if (1.0 < param_1) {

      *(undefined4 *)(iVar2 + 0xbc) = 0x3f800000;

    }

    if (*(int *)(DAT_006330e4 + 0x4e80) != 0) {

      *(undefined4 *)(iVar2 + 0xbc) = 0;

    }

  }

  if (0.0 < *(float *)(iVar2 + 0x134)) {

    *(undefined4 *)(iVar2 + 0xbc) = 0;

    *(undefined4 *)(iVar2 + 400) = 0;

  }

  param_1 = *(float *)(iVar2 + 0xc4);

  puVar3 = DAT_00632d70;

  do {

    if (puVar3 == (undefined4 *)0x0) {

      uVar9 = *(uint *)((int)fVar5 + 0xd8);

      if ((uVar9 & 0x1000) == 0) {

        uVar9 = uVar9 & 0xffffdfff;

      }

      else {

        uVar9 = uVar9 | 0x2000;

      }

      *(uint *)((int)fVar5 + 0xd8) = uVar9;

      if ((*(int *)((int)fVar5 + 0x174) == 0) && ((*(uint *)((int)fVar5 + 0xe0) & 0x20000) == 0)) {

        if ((bVar4) && (DAT_00633014 == 0)) {

          if (*(int *)(iVar2 + 0x1e4) == 0) {

            SpecialWeaponIdGet__FP6OBJECT(fVar5);

            uVar8 = sound_get_free_sequence__Fv();

            *(undefined4 *)(iVar2 + 0x1e4) = uVar8;

            ANM_DumpCluster(fVar5,2);

            return;

          }

        }

        else {

          if (*(int *)(iVar2 + 0x1e4) != 0) {

            sound_interrupt_sequence(iVar2 + 0x1e4);

          }

          ANM_DumpCluster(fVar5,2);

        }

      }

      return;

    }

    iVar6 = puVar3[3];

    if ((*(float *)(iVar6 + 0x210) == fVar5) &&

       (((iVar7 = *(int *)(iVar6 + 4), iVar7 == 0x54 || (iVar7 == 0x55)) || (iVar7 == 0x30d)))) {

      if (((*(uint *)((int)fVar5 + 0xd8) & 0x3000) == 0) ||

         (iVar7 = object_volume_sfx(fVar5), iVar7 != 0)) {

        uVar9 = *(uint *)(iVar6 + 0xd8);

LAB_0047ff01:

        uVar9 = uVar9 | 0x40000000;

      }

      else {

        if (param_1 == 0.0) {

          bVar10 = *(int *)(iVar6 + 4) == 0x30d;

        }

        else {

          bVar10 = *(int *)(iVar6 + 4) == 0x55;

        }

        uVar9 = *(uint *)(iVar6 + 0xd8);

        if (bVar10) goto LAB_0047ff01;

        uVar9 = uVar9 & 0xbfffffff;

      }

      *(uint *)(iVar6 + 0xd8) = uVar9;

    }

    puVar3 = (undefined4 *)*puVar3;

  } while( true );

}

/* ===== mecc_to_bush @ 0x0047FFF0 ===== */
/* PS2 candidate: mecc_to_bush (conf 0.603) */



void mecc_to_bush(int param_1)



{

  undefined4 *puVar1;

  int iVar2;

  undefined4 uVar3;

  int iVar4;

  

  iVar4 = *(int *)(param_1 + 0x100);

  playerobj_zap_movement(param_1);

  iVar2 = object_allocate_type(0x24,0);

  puVar1 = (undefined4 *)(param_1 + 0xa0);

  *(undefined4 *)(iVar2 + 0xa0) = *puVar1;

  *(undefined4 *)(iVar2 + 0xa4) = *(undefined4 *)(param_1 + 0xa4);

  *(undefined4 *)(iVar2 + 0xa8) = *(undefined4 *)(param_1 + 0xa8);

  *(undefined4 *)(iVar2 + 0xac) = *puVar1;

  *(undefined4 *)(iVar2 + 0xb0) = *(undefined4 *)(param_1 + 0xa4);

  *(undefined4 *)(iVar2 + 0xb4) = *(undefined4 *)(param_1 + 0xa8);

  *(undefined4 *)(iVar2 + 0xb8) = *puVar1;

  *(undefined4 *)(iVar2 + 0xbc) = *(undefined4 *)(param_1 + 0xa4);

  *(undefined4 *)(iVar2 + 0xc0) = *(undefined4 *)(param_1 + 0xa8);

  *(undefined4 *)(iVar2 + 0x18c) = *(undefined4 *)(param_1 + 0x18c);

  *(undefined4 *)(iVar2 + 200) = *(undefined4 *)(param_1 + 200);

  objanim_select_anim(param_1,0x2e);

  objanim_select_anim(iVar2,0x2e);

  *(int *)(param_1 + 0x274) = iVar2;

  *(int *)(iVar2 + 0x274) = param_1;

  *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 0x2000000;

  *(int *)(iVar2 + 0x210) = param_1;

  *(undefined4 *)(iVar2 + 0x214) = 0xffffffff;

  *(undefined4 *)(iVar2 + 0x218) = 0xffffffff;

  *(uint *)(iVar2 + 0xd8) = *(uint *)(iVar2 + 0xd8) | 0x400000;

  uVar3 = IconDefWieldType(*(undefined4 *)(iVar4 + 0x18c),1);

  iVar4 = player_find_weapon_obj_type__FP6OBJECTii(param_1,10,uVar3);

  if (iVar4 != 0) {

    *(undefined4 *)(iVar4 + 0x184) = 0x3f800000;

  }

  iVar4 = gun_find_left(param_1);

  if (iVar4 != 0) {

    *(uint *)(iVar4 + 0xd8) = *(uint *)(iVar4 + 0xd8) | 0x40000000;

  }

  iVar4 = gun_find_right(param_1);

  if (iVar4 != 0) {

    *(uint *)(iVar4 + 0xd8) = *(uint *)(iVar4 + 0xd8) | 0x40000000;

  }

  iVar4 = reaper_0052e4a0(param_1);

  if (iVar4 != 0) {

    reaper_00530bd0(param_1,0,0,0,0xb,0);

  }

  sound_play_player(0x571,param_1);

  return;

}

