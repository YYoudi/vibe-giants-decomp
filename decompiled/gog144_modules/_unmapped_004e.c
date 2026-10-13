/* Giants 1.449 — module _unmapped_004e
 * 109 functions (96 named) — decompiled, names from PS2 symbols
 * Original source: C:\Giants\source\_unmapped_004e.c(pp) (assert-string evidence)
 */

/* ===== rpman_goto_last_loc__FP6OBJECTi @ 0x004E1030 ===== */
/* PS2 candidate: rpman_goto_last_loc__FP6OBJECTi (conf 0.354) */



void rpman_goto_last_loc__FP6OBJECTi(int param_1,int param_2)



{

  int iVar1;

  float10 fVar2;

  float local_14;

  float local_10;

  float local_c;

  float local_8;

  undefined4 local_4;

  

  iVar1 = *(int *)(param_1 + 0x100);

  fVar2 = (float10)rndfloatrange(0,0x43b40000);

  sine_cos_lookup((float)fVar2,&local_14,&local_10);

  fVar2 = (float10)rndfloatrange(0x41a00000,0x42960000);

  local_c = (float)(fVar2 * (float10)local_14 + (float10)*(float *)(iVar1 + 0x28));

  fVar2 = (float10)rndfloatrange(0x41a00000,0x42960000);

  local_8 = (float)((float10)*(float *)(iVar1 + 0x2c) - fVar2 * (float10)local_10);

  local_4 = *(undefined4 *)(iVar1 + 0x30);

  ai_clear_move_goal(param_1);

  if (param_2 != 0) {

    ai_move_force_goal(param_1,&local_c);

    return;

  }

  ai_moveonly_set_goal(param_1,&local_c);

  return;

}

/* ===== ai_death_anim @ 0x004E10E0 ===== */
/* PS2 candidate: rpman_tornado_logic__FP6OBJECT (conf 0.323) */



void ai_death_anim(int param_1)



{

  *(undefined4 *)(param_1 + 0x210) = 0;

  if (DAT_00632d8c == 0) {

    if ((*(int *)(param_1 + 0x10) != 0x3d) && (*(int *)(*(int *)(param_1 + 8) + 0xfc) != 0)) {

      ObjectSetAnim(param_1,0x3d,0x21,0,*(float *)(param_1 + 0xc4) * 0.0,0x3e2aaaab);

    }

    if (((*(uint *)(param_1 + 0xd8) & 0x80000) != 0) ||

       (*(float *)(param_1 + 0xa8) < 0.0 != (*(float *)(param_1 + 0xa8) == 0.0))) {

      obj_damage_apply(2,0x461c4000,param_1,0,param_1 + 0xa0,0);

    }

  }

  else {

    sound_stop_sequence(*(int *)(param_1 + 0x100) + 0x234);

    if ((*(int *)(param_1 + 0x10) != 0x65) && (*(int *)(*(int *)(param_1 + 8) + 0x19c) != 0)) {

      ObjectSetAnim(param_1,0x65,0x21,0,*(float *)(param_1 + 0xc4) * 0.0,0x3e2aaaab);

    }

    *(undefined4 *)(param_1 + 0x208) = 0;

    *(undefined4 *)(param_1 + 0x20c) = 0;

  }

  *(undefined4 *)(*(int *)(param_1 + 0x104) + 0x34) = *(undefined4 *)(DAT_00632ed8 + 0xd5c);

  if (*(int *)(param_1 + 0xe4) != 0x8c) {

    if (*(int *)(param_1 + 0xe8) == 0x66) {

      *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) & 0xffffffef;

      *(uint *)(param_1 + 0x1c8) = *(uint *)(param_1 + 0x1c8) & 0xfffff1ff;

      if (*(float *)(param_1 + 0x278) < *(float *)(param_1 + 0x1c0)) {

        rpman_notify_hit(param_1,0);

      }

    }

    *(undefined4 *)(param_1 + 0xe4) = 0x8c;

  }

  return;

}

/* ===== rpman_jet__FP6OBJECT @ 0x004E1240 ===== */
/* PS2 candidate: rpman_jet__FP6OBJECT (conf 0.367) */



void rpman_jet__FP6OBJECT(int param_1)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float local_c;

  float local_8;

  float local_4;

  

  if (*(float *)(*(int *)(param_1 + 0x100) + 0x148) != 0.0) {

    fVar1 = *(float *)(*(int *)(param_1 + 0x100) + 0x148) * 0.03125 *

            (*(float *)(DAT_00632ed8 + 0xd34) / *(float *)(param_1 + 0xc4));

    fVar2 = (float)(int)*(char *)(param_1 + 0x20a) * 0.03125 * *(float *)(DAT_00632ed8 + 0xd6c);

    fVar3 = (float)(int)*(char *)(param_1 + 0x20b) * 0.03125 * *(float *)(DAT_00632ed8 + 0xd6c);

    local_c = fVar3 * *(float *)(param_1 + 0x298) + -(fVar2 * *(float *)(param_1 + 0x29c));

    local_8 = fVar3 * *(float *)(param_1 + 0x2a8) + -(fVar2 * *(float *)(param_1 + 0x2ac));

    local_4 = *(float *)(DAT_00632ed8 + 0xd44) * *(float *)(DAT_00632ed8 + 0xd6c) +

              fVar3 * *(float *)(param_1 + 0x2b8) + -(fVar2 * *(float *)(param_1 + 700));

    normalize__FPfN20(&local_c,&local_8,&local_4);

    *(float *)(*(int *)(param_1 + 0x104) + 0x18) =

         local_c * fVar1 + *(float *)(*(int *)(param_1 + 0x104) + 0x18);

    *(float *)(*(int *)(param_1 + 0x104) + 0x1c) =

         local_8 * fVar1 + *(float *)(*(int *)(param_1 + 0x104) + 0x1c);

    *(float *)(*(int *)(param_1 + 0x104) + 0x20) =

         local_4 * fVar1 + *(float *)(*(int *)(param_1 + 0x104) + 0x20);

    sound_play_obj(0x565,param_1);

    return;

  }

  sound_stop_obj(0x565,param_1);

  return;

}

/* ===== rpman_init_firing__FP6OBJECT @ 0x004E13A0 ===== */
void rpman_init_firing__FP6OBJECT(int param_1)



{

  int iVar1;

  undefined1 uVar2;

  

  iVar1 = *(int *)(param_1 + 0x100);

  uVar2 = rndintrange(*(undefined4 *)(iVar1 + 0x7c),*(undefined4 *)(iVar1 + 0x80));

  *(undefined1 *)(iVar1 + 0x24) = uVar2;

  uVar2 = rndintrange(*(undefined4 *)(iVar1 + 0x74),*(undefined4 *)(iVar1 + 0x78));

  *(undefined1 *)(iVar1 + 0x25) = uVar2;

  *(undefined4 *)(iVar1 + 0x1c) = 0;

  return;

}

/* ===== rpman_setup_firing_parameters__FP6OBJECTi @ 0x004E13E0 ===== */
/* PS2 candidate: rpman_setup_firing_parameters__FP6OBJECTi (conf 0.546) */



void rpman_setup_firing_parameters__FP6OBJECTi(int param_1,int param_2)



{

  int iVar1;

  uint uVar2;

  

  iVar1 = *(int *)(param_1 + 0x100);

  if (*(int *)(iVar1 + 0x70) != 0) {

    *(undefined4 *)(iVar1 + 0x74) = *(undefined4 *)(DAT_00632ed8 + 0x124c);

    *(undefined4 *)(iVar1 + 0x78) = *(undefined4 *)(DAT_00632ed8 + 0x1250);

    *(undefined4 *)(iVar1 + 0x7c) = *(undefined4 *)(DAT_00632ed8 + 0x1254);

    *(undefined4 *)(iVar1 + 0x80) = *(undefined4 *)(DAT_00632ed8 + 0x1258);

    *(undefined4 *)(iVar1 + 0x84) = *(undefined4 *)(DAT_00632ed8 + 0x125c);

    *(undefined4 *)(iVar1 + 0x88) = *(undefined4 *)(DAT_00632ed8 + 0x1260);

    *(undefined4 *)(iVar1 + 0x8c) = *(undefined4 *)(DAT_00632ed8 + 0x1264);

    *(undefined4 *)(iVar1 + 0x90) = *(undefined4 *)(DAT_00632ed8 + 0x1268);

    *(undefined4 *)(iVar1 + 0x94) = *(undefined4 *)(DAT_00632ed8 + 0x126c);

    *(undefined4 *)(iVar1 + 0x98) = *(undefined4 *)(DAT_00632ed8 + 0x1270);

    *(undefined4 *)(iVar1 + 0xac) = *(undefined4 *)(DAT_00632ed8 + 0x1274);

    *(undefined4 *)(iVar1 + 0xa8) = *(undefined4 *)(DAT_00632ed8 + 0x1278);

    return;

  }

  if (param_2 == -1) {

    uVar2 = *(uint *)(param_1 + 0xe0);

    if ((char)uVar2 < '\0') {

LAB_004e171e:

      *(undefined4 *)(iVar1 + 0x74) = *(undefined4 *)(DAT_00632ed8 + 0xa2c);

      *(undefined4 *)(iVar1 + 0x78) = *(undefined4 *)(DAT_00632ed8 + 0xa30);

      *(undefined4 *)(iVar1 + 0x7c) = *(undefined4 *)(DAT_00632ed8 + 0xa34);

      *(undefined4 *)(iVar1 + 0x80) = *(undefined4 *)(DAT_00632ed8 + 0xa38);

      *(undefined4 *)(iVar1 + 0x84) = *(undefined4 *)(DAT_00632ed8 + 0xa3c);

      *(undefined4 *)(iVar1 + 0x88) = *(undefined4 *)(DAT_00632ed8 + 0xa40);

      *(undefined4 *)(iVar1 + 0x8c) = *(undefined4 *)(DAT_00632ed8 + 0xa44);

      *(undefined4 *)(iVar1 + 0x90) = *(undefined4 *)(DAT_00632ed8 + 0xa48);

      *(undefined4 *)(iVar1 + 0x94) = *(undefined4 *)(DAT_00632ed8 + 0xc84);

      *(undefined4 *)(iVar1 + 0x98) = *(undefined4 *)(DAT_00632ed8 + 0xd20);

      *(undefined4 *)(iVar1 + 0xac) = *(undefined4 *)(DAT_00632ed8 + 0xf68);

      *(undefined4 *)(iVar1 + 0x9c) = *(undefined4 *)(DAT_00632ed8 + 0xf6c);

      *(undefined4 *)(iVar1 + 0xa0) = *(undefined4 *)(DAT_00632ed8 + 0xf70);

      *(undefined4 *)(iVar1 + 0xa4) = *(undefined4 *)(DAT_00632ed8 + 0xf74);

      *(undefined4 *)(iVar1 + 0xa8) = *(undefined4 *)(DAT_00632ed8 + 0xf78);

      return;

    }

    if ((uVar2 & 0x100) != 0) {

LAB_004e1618:

      *(undefined4 *)(iVar1 + 0x74) = *(undefined4 *)(DAT_00632ed8 + 0xa5c);

      *(undefined4 *)(iVar1 + 0x78) = *(undefined4 *)(DAT_00632ed8 + 0xa60);

      *(undefined4 *)(iVar1 + 0x7c) = *(undefined4 *)(DAT_00632ed8 + 0xa64);

      *(undefined4 *)(iVar1 + 0x80) = *(undefined4 *)(DAT_00632ed8 + 0xa68);

      *(undefined4 *)(iVar1 + 0x84) = *(undefined4 *)(DAT_00632ed8 + 0xa6c);

      *(undefined4 *)(iVar1 + 0x88) = *(undefined4 *)(DAT_00632ed8 + 0xa74);

      *(undefined4 *)(iVar1 + 0x8c) = *(undefined4 *)(DAT_00632ed8 + 0xa78);

      *(undefined4 *)(iVar1 + 0x90) = *(undefined4 *)(DAT_00632ed8 + 0xa70);

      *(undefined4 *)(iVar1 + 0x94) = *(undefined4 *)(DAT_00632ed8 + 0xa80);

      *(undefined4 *)(iVar1 + 0x98) = *(undefined4 *)(DAT_00632ed8 + 0xaa8);

      *(undefined4 *)(iVar1 + 0xac) = *(undefined4 *)(DAT_00632ed8 + 0xa88);

      *(undefined4 *)(iVar1 + 0x9c) = *(undefined4 *)(DAT_00632ed8 + 0xf90);

      *(undefined4 *)(iVar1 + 0xa0) = *(undefined4 *)(DAT_00632ed8 + 0xf94);

      *(undefined4 *)(iVar1 + 0xa4) = *(undefined4 *)(DAT_00632ed8 + 0xf98);

      *(undefined4 *)(iVar1 + 0xa8) = *(undefined4 *)(DAT_00632ed8 + 0xf9c);

      return;

    }

    if ((uVar2 & 0x200) != 0) goto LAB_004e1824;

    if ((uVar2 & 0x40000) != 0) goto LAB_004e1942;

  }

  else {

    if (param_2 < 0x201) {

      if (param_2 == 0x200) {

LAB_004e1824:

        *(undefined4 *)(iVar1 + 0x74) = *(undefined4 *)(DAT_00632ed8 + 0xa50);

        *(undefined4 *)(iVar1 + 0x78) = *(undefined4 *)(DAT_00632ed8 + 0xaa4);

        *(undefined4 *)(iVar1 + 0x7c) = *(undefined4 *)(DAT_00632ed8 + 0xc68);

        *(undefined4 *)(iVar1 + 0x80) = *(undefined4 *)(DAT_00632ed8 + 0xc6c);

        *(undefined4 *)(iVar1 + 0x84) = *(undefined4 *)(DAT_00632ed8 + 0xc70);

        *(undefined4 *)(iVar1 + 0x88) = *(undefined4 *)(DAT_00632ed8 + 0xc74);

        *(undefined4 *)(iVar1 + 0x8c) = *(undefined4 *)(DAT_00632ed8 + 0xc78);

        *(undefined4 *)(iVar1 + 0x90) = *(undefined4 *)(DAT_00632ed8 + 0xc7c);

        *(undefined4 *)(iVar1 + 0x94) = *(undefined4 *)(DAT_00632ed8 + 0xa4c);

        *(undefined4 *)(iVar1 + 0x98) = *(undefined4 *)(DAT_00632ed8 + 0xa58);

        *(undefined4 *)(iVar1 + 0xac) = *(undefined4 *)(DAT_00632ed8 + 0xf64);

        *(undefined4 *)(iVar1 + 0x9c) = *(undefined4 *)(DAT_00632ed8 + 0xa94);

        *(undefined4 *)(iVar1 + 0xa0) = *(undefined4 *)(DAT_00632ed8 + 0xf58);

        *(undefined4 *)(iVar1 + 0xa4) = *(undefined4 *)(DAT_00632ed8 + 0xf5c);

        *(undefined4 *)(iVar1 + 0xa8) = *(undefined4 *)(DAT_00632ed8 + 0xf60);

        return;

      }

      if (param_2 != 0x80) {

        if (param_2 != 0x100) {

          return;

        }

        goto LAB_004e1618;

      }

      goto LAB_004e171e;

    }

    if (param_2 != 0x400) {

      if (param_2 != 0x40000) {

        return;

      }

LAB_004e1942:

      *(undefined4 *)(iVar1 + 0xa8) = 0x42480000;

      *(undefined4 *)(iVar1 + 0xa0) = 0x42480000;

      *(undefined4 *)(iVar1 + 0x9c) = 0x41f00000;

      *(undefined4 *)(iVar1 + 0xa4) = 0x44fa0000;

      return;

    }

  }

  *(undefined4 *)(iVar1 + 0x74) = *(undefined4 *)(DAT_00632ed8 + 0xb08);

  *(undefined4 *)(iVar1 + 0x78) = *(undefined4 *)(DAT_00632ed8 + 0xb0c);

  *(undefined4 *)(iVar1 + 0x7c) = *(undefined4 *)(DAT_00632ed8 + 0xb10);

  *(undefined4 *)(iVar1 + 0x80) = *(undefined4 *)(DAT_00632ed8 + 0xb14);

  *(undefined4 *)(iVar1 + 0x84) = *(undefined4 *)(DAT_00632ed8 + 0xb18);

  *(undefined4 *)(iVar1 + 0x88) = *(undefined4 *)(DAT_00632ed8 + 0xb1c);

  *(undefined4 *)(iVar1 + 0x8c) = *(undefined4 *)(DAT_00632ed8 + 0xb20);

  *(undefined4 *)(iVar1 + 0x90) = *(undefined4 *)(DAT_00632ed8 + 0xb24);

  *(undefined4 *)(iVar1 + 0x98) = *(undefined4 *)(DAT_00632ed8 + 0xb2c);

  *(undefined4 *)(iVar1 + 0xac) = *(undefined4 *)(DAT_00632ed8 + 0xf7c);

  *(undefined4 *)(iVar1 + 0x9c) = *(undefined4 *)(DAT_00632ed8 + 0xf80);

  *(undefined4 *)(iVar1 + 0xa0) = *(undefined4 *)(DAT_00632ed8 + 0xf84);

  *(undefined4 *)(iVar1 + 0xa4) = *(undefined4 *)(DAT_00632ed8 + 0xf88);

  *(undefined4 *)(iVar1 + 0xa8) = *(undefined4 *)(DAT_00632ed8 + 0xf8c);

  return;

}

/* ===== rpman_shot @ 0x004E1970 ===== */
/* PS2 candidate: rpman_shot (conf 0.462) */



void rpman_shot(float param_1)



{

  int *piVar1;

  uint uVar2;

  int iVar3;

  undefined1 uVar4;

  int iVar5;

  float10 fVar6;

  float local_38 [2];

  undefined4 local_30;

  undefined4 local_2c;

  undefined4 local_28;

  

  iVar3 = (int)param_1;

  piVar1 = *(int **)((int)param_1 + 0x100);

  if (*(int *)((int)param_1 + 0xe4) == 0xd8) {

    param_1 = 33.33;

  }

  else {

    param_1 = *(float *)(DAT_00632ed8 + 0xa24);

  }

  rpman_setup_firing_parameters__FP6OBJECTi(iVar3,0xffffffff);

  uVar2 = *(uint *)(iVar3 + 0xe0);

  if ((char)uVar2 < '\0') {

    if ((float)piVar1[0xd] <= *(float *)(DAT_00632ed8 + 0xb30) * *(float *)(DAT_00632ed8 + 0xb30)) {

      local_38[0] = (float)crt_rand_scaled(100);

      if (((float)(int)local_38[0] < param_1) &&

         ((float)piVar1[0xd] < (float)piVar1[0x2a] * (float)piVar1[0x2a])) {

        *(uint *)(iVar3 + 0xe0) = *(uint *)(iVar3 + 0xe0) & 0xffff7fff;

        if ((*(int *)(iVar3 + 0x10) != 0x96) && (*(int *)(*(int *)(iVar3 + 8) + 0x260) != 0)) {

          ObjectSetAnim(iVar3,0x96,0x20,0,*(float *)(iVar3 + 0xc4) * 0.0,0x3e2aaaab);

        }

        *(undefined4 *)(iVar3 + 0xe4) = 0x2d;

        return;

      }

      iVar5 = crt_rand_scaled(100);

      if ((iVar5 < 10) && (*(int *)(iVar3 + 0xe8) != 4)) {

        *(uint *)(iVar3 + 0xe0) = *(uint *)(iVar3 + 0xe0) | 0x8000;

        iVar5 = crt_rand_scaled(100);

        if ((((iVar5 < 10) && (0.98 < *(float *)(iVar3 + 0x14c))) &&

            (*(float *)(*piVar1 + 0xa8) - *(float *)(iVar3 + 0xa8) < 6.0)) &&

           ((float)piVar1[0xd] < *(float *)(DAT_00632ed8 + 0xfdc) * *(float *)(DAT_00632ed8 + 0xfdc)

           )) {

          if ((*(int *)(iVar3 + 0x10) != 0x38) && (*(int *)(*(int *)(iVar3 + 8) + 0xe8) != 0)) {

            ObjectSetAnim(iVar3,0x38,0x20,0,*(float *)(iVar3 + 0xc4) * 0.0,0x3e2aaaab);

          }

          sine_cos_lookup(*(undefined4 *)(iVar3 + 200),&param_1,local_38);

          iVar5 = *(int *)(iVar3 + 0x100);

          *(undefined4 *)(iVar3 + 0x130) = 0;

          *(float *)(iVar3 + 0x128) = param_1 * 100.0;

          *(float *)(iVar3 + 300) = local_38[0] * -100.0;

          uVar4 = rndintrange(*(undefined4 *)(iVar5 + 0x7c),*(undefined4 *)(iVar5 + 0x80));

          *(undefined1 *)(iVar5 + 0x24) = uVar4;

          uVar4 = rndintrange(*(undefined4 *)(iVar5 + 0x74),*(undefined4 *)(iVar5 + 0x78));

          *(undefined1 *)(iVar5 + 0x25) = uVar4;

          *(undefined4 *)(iVar5 + 0x1c) = 0;

          fVar6 = (float10)rndfloatrange(piVar1[0x21],piVar1[0x22]);

          piVar1[6] = (int)(float)fVar6;

          *(uint *)(iVar3 + 0xd8) = *(uint *)(iVar3 + 0xd8) & 0xfcffffff;

          *(undefined4 *)(iVar3 + 0x208) = 0;

          *(undefined4 *)(iVar3 + 0x20c) = 0;

          *(undefined4 *)(iVar3 + 0xe4) = 0x29;

          return;

        }

        if ((*(int *)(iVar3 + 0x10) != 0x32) && (*(int *)(*(int *)(iVar3 + 8) + 0xd0) != 0)) {

          ObjectSetAnim(iVar3,0x32,0x20,0,*(float *)(iVar3 + 0xc4) * 0.0,0x3e2aaaab);

        }

        iVar5 = *(int *)(iVar3 + 0x100);

        uVar4 = rndintrange(*(undefined4 *)(iVar5 + 0x7c),*(undefined4 *)(iVar5 + 0x80));

        *(undefined1 *)(iVar5 + 0x24) = uVar4;

        uVar4 = rndintrange(*(undefined4 *)(iVar5 + 0x74),*(undefined4 *)(iVar5 + 0x78));

        *(undefined1 *)(iVar5 + 0x25) = uVar4;

        *(undefined4 *)(iVar5 + 0x1c) = 0;

        fVar6 = (float10)rndfloatrange(piVar1[0x21],piVar1[0x22]);

        piVar1[6] = (int)(float)fVar6;

        *(uint *)(iVar3 + 0xd8) = *(uint *)(iVar3 + 0xd8) & 0xfcffffff;

        *(undefined4 *)(iVar3 + 0x208) = 0;

        *(undefined4 *)(iVar3 + 0x20c) = 0;

        *(undefined4 *)(iVar3 + 0xe4) = 0x2b;

        return;

      }

      if ((*(int *)(iVar3 + 0x10) != 0x4e) && (*(int *)(*(int *)(iVar3 + 8) + 0x140) != 0)) {

        ObjectSetAnim(iVar3,0x4e,0x21,0,*(float *)(iVar3 + 0xc4) * 0.0,0x3e2aaaab);

      }

      iVar5 = *(int *)(iVar3 + 0x100);

      uVar4 = rndintrange(*(undefined4 *)(iVar5 + 0x7c),*(undefined4 *)(iVar5 + 0x80));

      *(undefined1 *)(iVar5 + 0x24) = uVar4;

      uVar4 = rndintrange(*(undefined4 *)(iVar5 + 0x74),*(undefined4 *)(iVar5 + 0x78));

      *(undefined1 *)(iVar5 + 0x25) = uVar4;

      *(undefined4 *)(iVar5 + 0x1c) = 0;

      fVar6 = (float10)rndfloatrange(piVar1[0x21],piVar1[0x22]);

      piVar1[6] = (int)(float)fVar6;

      *(uint *)(iVar3 + 0xd8) = *(uint *)(iVar3 + 0xd8) & 0xfcffffff;

      *(undefined4 *)(iVar3 + 0x208) = 0;

      *(undefined4 *)(iVar3 + 0x20c) = 0;

      *(undefined4 *)(iVar3 + 0xe4) = 0x28;

      goto LAB_004e21cb;

    }

  }

  else if ((uVar2 & 0x400) == 0) {

    if ((uVar2 & 0x100) != 0) {

      iVar5 = crt_rand_scaled(100);

      if ((iVar5 < 0x32) && (*(int *)(iVar3 + 0xe8) != 4)) {

        if ((*(int *)(iVar3 + 0x10) != 0x77) && (*(int *)(*(int *)(iVar3 + 8) + 0x1e4) != 0)) {

          ObjectSetAnim(iVar3,0x77,0x21,0,*(float *)(iVar3 + 0xc4) * 0.0,0x3e2aaaab);

        }

        iVar5 = *(int *)(iVar3 + 0x100);

        uVar4 = rndintrange(*(undefined4 *)(iVar5 + 0x7c),*(undefined4 *)(iVar5 + 0x80));

        *(undefined1 *)(iVar5 + 0x24) = uVar4;

        uVar4 = rndintrange(*(undefined4 *)(iVar5 + 0x74),*(undefined4 *)(iVar5 + 0x78));

        *(undefined1 *)(iVar5 + 0x25) = uVar4;

        *(undefined4 *)(iVar5 + 0x1c) = 0;

        fVar6 = (float10)rndfloatrange(piVar1[0x21],piVar1[0x22]);

        piVar1[6] = (int)(float)fVar6;

        *(uint *)(iVar3 + 0xe0) = *(uint *)(iVar3 + 0xe0) | 0x8000;

        *(uint *)(iVar3 + 0xd8) = *(uint *)(iVar3 + 0xd8) & 0xfcffffff;

        *(undefined4 *)(iVar3 + 0x208) = 0;

        *(undefined4 *)(iVar3 + 0x20c) = 0;

        *(undefined4 *)(iVar3 + 0xe4) = 0x30;

        return;

      }

      if ((*(int *)(iVar3 + 0x10) != 0x74) && (*(int *)(*(int *)(iVar3 + 8) + 0x1d8) != 0)) {

        ObjectSetAnim(iVar3,0x74,0x21,0,*(float *)(iVar3 + 0xc4) * 0.0,0x3e2aaaab);

      }

      iVar5 = *(int *)(iVar3 + 0x100);

      uVar4 = rndintrange(*(undefined4 *)(iVar5 + 0x7c),*(undefined4 *)(iVar5 + 0x80));

      *(undefined1 *)(iVar5 + 0x24) = uVar4;

      uVar4 = rndintrange(*(undefined4 *)(iVar5 + 0x74),*(undefined4 *)(iVar5 + 0x78));

      *(undefined1 *)(iVar5 + 0x25) = uVar4;

      *(undefined4 *)(iVar5 + 0x1c) = 0;

      fVar6 = (float10)rndfloatrange(piVar1[0x21],piVar1[0x22]);

      piVar1[6] = (int)(float)fVar6;

      *(uint *)(iVar3 + 0xe0) = *(uint *)(iVar3 + 0xe0) & 0xffff7fff;

      *(uint *)(iVar3 + 0xd8) = *(uint *)(iVar3 + 0xd8) & 0xfcffffff;

      *(undefined4 *)(iVar3 + 0x208) = 0;

      *(undefined4 *)(iVar3 + 0x20c) = 0;

      *(undefined4 *)(iVar3 + 0xe4) = 0x2f;

      return;

    }

    if ((uVar2 & 0x40000) != 0) {

      local_30 = *(undefined4 *)(iVar3 + 0xa0);

      local_2c = *(undefined4 *)(iVar3 + 0xa4);

      local_28 = *(undefined4 *)(iVar3 + 0xa8);

      fx_get_free_effect__Fv();

      line_damage_with_slope

                (0x31,iVar3,0,(undefined4 *)(iVar3 + 0xa0),*(undefined4 *)(DAT_00632ed8 + 0x1094),

                 *(undefined4 *)(DAT_00632ed8 + 0x1098),*(undefined4 *)(DAT_00632ed8 + 0x109c),

                 *(undefined4 *)(DAT_00632ed8 + 0x10a0),*(undefined4 *)(iVar3 + 0x18c));

      rpman_gib__FP6OBJECTT0(iVar3,0);

      return;

    }

    iVar5 = crt_rand_scaled(100);

    if ((iVar5 < 10) && (*(int *)(iVar3 + 0xe8) != 4)) {

      if ((*(int *)(iVar3 + 0x10) != 0x94) && (*(int *)(*(int *)(iVar3 + 8) + 600) != 0)) {

        ObjectSetAnim(iVar3,0x94,0x21,0,*(float *)(iVar3 + 0xc4) * 0.0,0x3e2aaaab);

      }

      iVar5 = *(int *)(iVar3 + 0x100);

      uVar4 = rndintrange(*(undefined4 *)(iVar5 + 0x7c),*(undefined4 *)(iVar5 + 0x80));

      *(undefined1 *)(iVar5 + 0x24) = uVar4;

      uVar4 = rndintrange(*(undefined4 *)(iVar5 + 0x74),*(undefined4 *)(iVar5 + 0x78));

      *(undefined1 *)(iVar5 + 0x25) = uVar4;

      *(undefined4 *)(iVar5 + 0x1c) = 0;

      fVar6 = (float10)rndfloatrange(piVar1[0x21],piVar1[0x22]);

      piVar1[6] = (int)(float)fVar6;

      *(uint *)(iVar3 + 0xd8) = *(uint *)(iVar3 + 0xd8) & 0xfcffffff;

      *(undefined4 *)(iVar3 + 0x208) = 0;

      *(undefined4 *)(iVar3 + 0x20c) = 0;

      *(undefined4 *)(iVar3 + 0xe4) = 0x33;

      *(uint *)(iVar3 + 0xe0) = *(uint *)(iVar3 + 0xe0) | 0x8000;

      return;

    }

    if ((*(int *)(iVar3 + 0x10) != 0x8c) && (*(int *)(*(int *)(iVar3 + 8) + 0x238) != 0)) {

      ObjectSetAnim(iVar3,0x8c,0x21,0,*(float *)(iVar3 + 0xc4) * 0.0,0x3e2aaaab);

    }

    iVar5 = *(int *)(iVar3 + 0x100);

    uVar4 = rndintrange(*(undefined4 *)(iVar5 + 0x7c),*(undefined4 *)(iVar5 + 0x80));

    *(undefined1 *)(iVar5 + 0x24) = uVar4;

    uVar4 = rndintrange(*(undefined4 *)(iVar5 + 0x74),*(undefined4 *)(iVar5 + 0x78));

    *(undefined1 *)(iVar5 + 0x25) = uVar4;

    *(undefined4 *)(iVar5 + 0x1c) = 0;

    fVar6 = (float10)rndfloatrange(piVar1[0x21],piVar1[0x22]);

    piVar1[6] = (int)(float)fVar6;

    *(uint *)(iVar3 + 0xd8) = *(uint *)(iVar3 + 0xd8) & 0xfcffffff;

    *(undefined4 *)(iVar3 + 0x208) = 0;

    *(undefined4 *)(iVar3 + 0x20c) = 0;

    *(undefined4 *)(iVar3 + 0xe4) = 0x32;

    goto LAB_004e21cb;

  }

  rpman_setup_firing_parameters__FP6OBJECTi(iVar3,0x400);

  if ((*(int *)(iVar3 + 0x10) != 0x50) && (*(int *)(*(int *)(iVar3 + 8) + 0x148) != 0)) {

    ObjectSetAnim(iVar3,0x50,0x21,0,*(float *)(iVar3 + 0xc4) * 0.0,0x3e2aaaab);

  }

  iVar5 = *(int *)(iVar3 + 0x100);

  uVar4 = rndintrange(*(undefined4 *)(iVar5 + 0x7c),*(undefined4 *)(iVar5 + 0x80));

  *(undefined1 *)(iVar5 + 0x24) = uVar4;

  uVar4 = rndintrange(*(undefined4 *)(iVar5 + 0x74),*(undefined4 *)(iVar5 + 0x78));

  *(undefined1 *)(iVar5 + 0x25) = uVar4;

  *(undefined4 *)(iVar5 + 0x1c) = 0;

  fVar6 = (float10)rndfloatrange(piVar1[0x21],piVar1[0x22]);

  piVar1[6] = (int)(float)fVar6;

  *(uint *)(iVar3 + 0xd8) = *(uint *)(iVar3 + 0xd8) & 0xfcffffff;

  *(undefined4 *)(iVar3 + 0x208) = 0;

  *(undefined4 *)(iVar3 + 0x20c) = 0;

  *(undefined4 *)(iVar3 + 0xe4) = 0x35;

LAB_004e21cb:

  *(uint *)(iVar3 + 0xe0) = *(uint *)(iVar3 + 0xe0) & 0xffff7fff;

  return;

}

/* ===== FUN_004e21f0 @ 0x004E21F0 ===== */
undefined4 FUN_004e21f0(int param_1)



{

  int iVar1;

  undefined4 *puVar2;

  

  puVar2 = DAT_00632d6c;

  if ((*(uint *)(param_1 + 0xe0) & 0x2000) != 0) {

    for (; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {

      iVar1 = puVar2[3];

      if ((((*(int *)(iVar1 + 4) == 0xd7) &&

           (*(int *)(*(int *)(iVar1 + 0x100) + 0x134) == *(int *)(*(int *)(param_1 + 0x100) + 0x134)

           )) && (iVar1 != param_1)) && (*(int *)(iVar1 + 0xe4) != 0x21)) {

        return 0;

      }

    }

  }

  return 1;

}

/* ===== rpman_verify_bush__FP6OBJECT @ 0x004E2260 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* PS2 candidate: rpman_verify_bush__FP6OBJECT (conf 0.634) */



undefined4 rpman_verify_bush__FP6OBJECT(int param_1)



{

  int iVar1;

  int iVar2;

  float10 fVar3;

  

  iVar1 = DAT_00632a88;

  iVar2 = ObjIsMecc(DAT_00632a88);

  if ((iVar2 != 0) && ((*(uint *)(iVar1 + 0xe0) & 0x2000000) != 0)) {

    fVar3 = (float10)FUN_0050a610(param_1 + 0xa0,iVar1 + 0xa0);

    if (fVar3 <= (float10)57600.0) {

      return 1;

    }

  }

  DAT_005a8568 = 0;

  _DAT_005a856c = 0;

  return 0;

}

/* ===== ai_visibility_cull @ 0x004E22D0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined4 ai_visibility_cull(int param_1)



{

  int iVar1;

  undefined4 *puVar2;

  int iVar3;

  float10 fVar4;

  undefined4 uVar5;

  float fVar6;

  

  iVar3 = *(int *)(param_1 + 0x100);

  if (((_DAT_005a856c < 4.0) || (DAT_005a8568 != 0)) || (*(int *)(iVar3 + 0xd8) != 0)) {

    return 0;

  }

  iVar1 = DAT_00632a88 + 0xa0;

  puVar2 = (undefined4 *)(param_1 + 0xa0);

  fVar4 = (float10)FUN_0050a610(puVar2,iVar1);

  if ((float10)57600.0 <= fVar4) {

    return 0;

  }

  fVar4 = (float10)dirfcalcp3d__FP3P3DT0(puVar2,iVar1,*(undefined4 *)(iVar3 + 0x58));

  fVar4 = (float10)diff_angle((float)fVar4);

  if ((float10)60.0 <= fVar4) {

    return 0;

  }

  DAT_005a8568 = 1;

  if ((*(uint *)(param_1 + 0xe0) & 0x200) == 0) {

    if ((*(int *)(param_1 + 0x10) == 0x47) || (*(int *)(*(int *)(param_1 + 8) + 0x124) == 0))

    goto LAB_004e23f6;

    fVar6 = *(float *)(DAT_00632ed8 + 0xb38) * *(float *)(param_1 + 0xc4);

    uVar5 = 0x47;

  }

  else {

    if ((*(int *)(param_1 + 0x10) == 0x8e) || (*(int *)(*(int *)(param_1 + 8) + 0x240) == 0))

    goto LAB_004e23f6;

    fVar6 = *(float *)(DAT_00632ed8 + 0xb38) * *(float *)(param_1 + 0xc4);

    uVar5 = 0x8e;

  }

  ObjectSetAnim(param_1,uVar5,0x21,1,fVar6,0x3e2aaaab);

LAB_004e23f6:

  if (*(int *)(iVar3 + 0x134) == 0) {

    *(undefined4 *)(iVar3 + 8) = *puVar2;

    *(undefined4 *)(iVar3 + 0xc) = *(undefined4 *)(param_1 + 0xa4);

    *(undefined4 *)(iVar3 + 0x10) = *(undefined4 *)(param_1 + 0xa8);

    *(undefined4 *)(iVar3 + 0x14) = *(undefined4 *)(param_1 + 200);

  }

  *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 0x1000;

  *(undefined4 *)(param_1 + 0xe4) = 0x46;

  return 1;

}

/* ===== ai_move_pair_caller @ 0x004E2450 ===== */
undefined4 ai_move_pair_caller(int param_1)



{

  int iVar1;

  int iVar2;

  int iVar3;

  undefined4 *puVar4;

  float10 fVar5;

  undefined4 uVar6;

  float fVar7;

  

  iVar1 = *(int *)(param_1 + 0x100);

  if (*(int *)(iVar1 + 0xb0) != 0) {

    return 0;

  }

  fVar5 = (float10)FUN_00518b70(param_1,0);

  fVar5 = (float10)*(float *)(iVar1 + 0xd0) - fVar5;

  *(float *)(iVar1 + 0xd0) = (float)fVar5;

  if (fVar5 < (float10)0.0 == (fVar5 == (float10)0.0)) {

    return 0;

  }

  puVar4 = DAT_00632d6c;

  if (*(int *)(iVar1 + 0x134) != 0) {

    for (; puVar4 != (undefined4 *)0x0; puVar4 = (undefined4 *)*puVar4) {

      iVar2 = puVar4[3];

      if (((*(int *)(iVar2 + 4) == 0xd7) &&

          (*(int *)(*(int *)(iVar2 + 0x100) + 0x134) == *(int *)(iVar1 + 0x134))) &&

         (*(int *)(iVar2 + 0xe4) == 0x12d)) {

        fVar5 = (float10)rndfloatrange(0x40800000,0x40e00000);

        *(float *)(iVar1 + 0xd0) = (float)fVar5;

        return 0;

      }

    }

    puVar4 = DAT_00632d6c;

    if (DAT_00632d6c == (undefined4 *)0x0) {

      return 1;

    }

    do {

      iVar2 = puVar4[3];

      iVar3 = *(int *)(iVar2 + 0x100);

      if ((*(int *)(iVar2 + 4) == 0xd7) && (*(int *)(iVar3 + 0x134) == *(int *)(iVar1 + 0x134))) {

        ai_move_goals_free(iVar2,iVar3 + 8,*(undefined4 *)(iVar3 + 0x14));

        if ((*(uint *)(iVar2 + 0xe0) & 0x200) == 0) {

          if ((*(int *)(iVar2 + 0x10) != 0x47) && (*(int *)(*(int *)(iVar2 + 8) + 0x124) != 0)) {

            fVar7 = *(float *)(DAT_00632ed8 + 0xb38) * *(float *)(iVar2 + 0xc4);

            uVar6 = 0x47;

            goto LAB_004e25c8;

          }

        }

        else if ((*(int *)(iVar2 + 0x10) != 0x8e) && (*(int *)(*(int *)(iVar2 + 8) + 0x240) != 0)) {

          fVar7 = *(float *)(DAT_00632ed8 + 0xb38) * *(float *)(iVar2 + 0xc4);

          uVar6 = 0x8e;

LAB_004e25c8:

          ObjectSetAnim(iVar2,uVar6,0x21,1,fVar7,0x3e2aaaab);

        }

        *(uint *)(iVar2 + 0xe0) = *(uint *)(iVar2 + 0xe0) & 0xfffff7ff;

        *(undefined4 *)(iVar2 + 0xe4) = 0x12;

      }

      puVar4 = (undefined4 *)*puVar4;

      if (puVar4 == (undefined4 *)0x0) {

        return 1;

      }

    } while( true );

  }

  if (*(int *)(param_1 + 0xe8) != 2) {

    ai_damage_response(param_1,1,0,0);

    *(undefined4 *)(param_1 + 0xec) = 0x3f800000;

    *(undefined4 *)(param_1 + 0xe4) = 0xb;

    goto LAB_004e26cb;

  }

  main_ai_move_004014b0(param_1,iVar1 + 8,*(undefined4 *)(iVar1 + 0x14));

  if ((*(uint *)(param_1 + 0xe0) & 0x200) == 0) {

    if ((*(int *)(param_1 + 0x10) != 0x47) && (*(int *)(*(int *)(param_1 + 8) + 0x124) != 0)) {

      fVar7 = *(float *)(DAT_00632ed8 + 0xb38) * *(float *)(param_1 + 0xc4);

      uVar6 = 0x47;

      goto LAB_004e26b8;

    }

  }

  else if ((*(int *)(param_1 + 0x10) != 0x8e) && (*(int *)(*(int *)(param_1 + 8) + 0x240) != 0)) {

    fVar7 = *(float *)(DAT_00632ed8 + 0xb38) * *(float *)(param_1 + 0xc4);

    uVar6 = 0x8e;

LAB_004e26b8:

    ObjectSetAnim(param_1,uVar6,0x21,1,fVar7,0x3e2aaaab);

  }

  *(undefined4 *)(param_1 + 0xe4) = 0x12;

LAB_004e26cb:

  *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xfffff7ff;

  return 1;

}

/* ===== ai_damage_update @ 0x004E26E0 ===== */
undefined4 ai_damage_update(int param_1,int param_2)



{

  float fVar1;

  int iVar2;

  int iVar3;

  undefined4 *puVar4;

  int iVar5;

  int *piVar6;

  int iVar7;

  

  iVar5 = param_1;

  if ((param_2 != 0) && (*(float *)(param_2 + 0xf8) == 0.0)) {

    return 0;

  }

  iVar2 = *(int *)(param_1 + 0x100);

  param_1 = 0;

  piVar6 = DAT_00632d6c;

  iVar7 = param_2;

  if (DAT_00632d6c == (int *)0x0) {

LAB_004e2769:

    if (*(int *)(iVar2 + 0x6c) != 0) goto LAB_004e27e0;

    if (param_2 != 0) {

      ai_damage_response(iVar5,0,0,0);

      if (*(int *)(iVar5 + 0xe8) == 0x66) {

        if (*(int *)(*(int *)(param_2 + 0x100) + 0x5c) == 0) {

          *(undefined4 *)(iVar5 + 0xe4) = 0xcc;

        }

        else {

          *(undefined4 *)(iVar5 + 0xe4) = 0xd5;

        }

      }

      else {

        *(undefined4 *)(iVar5 + 0xe4) = 0x20;

      }

      iVar3 = *(int *)(iVar2 + 0x134);

      if ((iVar3 != 0) && (*(int *)(iVar3 + 0x1e0) == 0x61)) {

        *(undefined4 *)(iVar3 + 0xe4) = 3;

      }

      goto LAB_004e2821;

    }

  }

  else {

    do {

      iVar3 = piVar6[3];

      if (((*(int *)(iVar3 + 4) == 0xd7) &&

          (*(int *)(*(int *)(iVar3 + 0x100) + 0x134) == *(int *)(iVar2 + 0x134))) &&

         (param_1 = param_1 + 1, *(int *)(*(int *)(iVar3 + 0x100) + 0xb0) == 0)) {

        iVar7 = iVar3;

      }

      piVar6 = (int *)*piVar6;

    } while (piVar6 != (int *)0x0);

    if (param_1 < 2) goto LAB_004e2769;

LAB_004e27e0:

    if ((*(int *)(iVar7 + 0x10) != 0x51) && (*(int *)(*(int *)(iVar7 + 8) + 0x14c) != 0)) {

      ObjectSetAnim(iVar7,0x51,0x20,0,*(float *)(iVar7 + 0xc4) * 0.0,0x3e2aaaab);

    }

    *(undefined4 *)(iVar7 + 0xe4) = 0x1f;

LAB_004e2821:

    if (param_2 != 0) {

      fVar1 = *(float *)(param_2 + 0xf8);

      *(float *)(iVar2 + 0xbc) = fVar1;

      if (3600.0 <= fVar1) {

        *(undefined4 *)(iVar2 + 0xc0) = 1;

      }

      puVar4 = DAT_00632d68;

      if (*(int *)(iVar5 + 0xe8) == 0x66) {

        for (; puVar4 != (undefined4 *)0x0; puVar4 = (undefined4 *)*puVar4) {

          iVar7 = puVar4[3];

          if (((*(int *)(iVar7 + 4) == 0x48a) &&

              (*(int *)(iVar7 + 0xe8) == *(int *)(param_2 + 0xe8))) &&

             (*(int *)(iVar7 + 0x174) == *(int *)(param_2 + 0x174) + -1)) {

            *(undefined4 *)(*(int *)(iVar7 + 0x100) + 0x5c) = 1;

            *(undefined4 *)(iVar7 + 0xf8) = 0x4426aaa0;

            break;

          }

        }

      }

      goto LAB_004e28c4;

    }

  }

  *(undefined4 *)(*(int *)(iVar7 + 0x100) + 0xbc) = 0;

  *(uint *)(iVar7 + 0xe0) = *(uint *)(iVar7 + 0xe0) | 0x2000;

LAB_004e28c4:

  if ((*(int *)(iVar2 + 0xb0) == 0) || (param_1 < 2)) {

    if (param_1 == 1) {

      *(undefined4 *)(iVar2 + 0x14) = *(undefined4 *)(iVar5 + 200);

      *(undefined4 *)(iVar2 + 8) = *(undefined4 *)(iVar5 + 0xa0);

      *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(iVar5 + 0xa4);

      *(undefined4 *)(iVar2 + 0x10) = *(undefined4 *)(iVar5 + 0xa8);

    }

  }

  else {

    if (*(int *)(*(int *)(iVar5 + 0x100) + 0xd8) != 0) {

      cleaner_process(iVar5,0);

      return 1;

    }

    if ((*(uint *)(iVar5 + 0xe0) & 0x200) == 0) {

      if ((*(int *)(iVar5 + 0x10) != 0x53) && (*(int *)(*(int *)(iVar5 + 8) + 0x154) != 0)) {

        ObjectSetAnim(iVar5,0x53,0x21,1,

                      *(float *)(DAT_00632ed8 + 0xb34) * *(float *)(iVar5 + 0xc4) *

                      *(float *)(iVar5 + 0xc4),0x3e2aaaab);

        return 1;

      }

    }

    else if ((*(int *)(iVar5 + 0x10) != 0x92) && (*(int *)(*(int *)(iVar5 + 8) + 0x250) != 0)) {

      ObjectSetAnim(iVar5,0x92,0x21,1,

                    *(float *)(DAT_00632ed8 + 0xb34) * *(float *)(iVar5 + 0xc4) *

                    *(float *)(iVar5 + 0xc4),0x3e2aaaab);

      return 1;

    }

  }

  return 1;

}

/* ===== smartie_claim_targets @ 0x004E29F0 ===== */
void smartie_claim_targets(int param_1)



{

  int iVar1;

  int iVar2;

  undefined4 *puVar3;

  int iVar4;

  

  iVar1 = *(int *)(param_1 + 0x100);

  puVar3 = DAT_00632d68;

  if (*(int *)(param_1 + 0xe8) == 0xb) {

    param_1 = 0x41c;

  }

  else {

    param_1 = ((*(int *)(param_1 + 0xe8) != 0x67) - 1 & 0x6e) + 0x41c;

  }

  for (; puVar3 != (undefined4 *)0x0; puVar3 = (undefined4 *)*puVar3) {

    iVar2 = puVar3[3];

    if (*(int *)(iVar2 + 0x1e0) == 0x27) {

      if (*(int *)(*(int *)(iVar2 + 0x100) + 0x14) == *(int *)(iVar1 + 0x134)) {

        *(int *)(iVar1 + 0x6c) = iVar2;

      }

    }

    else if ((*(int *)(iVar2 + 0x1e0) == 0x60) && (*(int *)(iVar2 + 4) == param_1)) {

      if ((*(int *)(iVar1 + 0x134) == 0) &&

         ((*(int *)(iVar2 + 0x174) == 0 && (iVar4 = __ftol(), *(int *)(iVar2 + 0xe8) == iVar4)))) {

        *(int *)(iVar1 + 0x134) = iVar2;

        *(undefined4 *)(iVar1 + 0x138) = 0xffffffff;

        *(undefined4 *)(iVar1 + 0x140) = *(undefined4 *)(iVar2 + 0xfc);

      }

      if (((*(float *)(iVar1 + 0x13c) == 0.0) && (*(int *)(iVar2 + 0x174) == *(int *)(iVar1 + 0x60))

          ) && (iVar4 = __ftol(), *(int *)(iVar2 + 0xe8) == iVar4)) {

        *(float *)(iVar1 + 0x13c) = (float)*(int *)(*(int *)(iVar2 + 0x100) + 0x50);

      }

    }

  }

  return;

}

/* ===== FUN_004e2b10 @ 0x004E2B10 ===== */
/* PS2 candidate: rpman_spline_return_info__FP6OBJECT (conf 0.715) */



void FUN_004e2b10(int param_1)



{

  int iVar1;

  int iVar2;

  undefined1 local_1c [16];

  float local_c;

  

  iVar1 = *(int *)(param_1 + 0x100);

  if (-1 < *(int *)(iVar1 + 0x138)) {

    iVar2 = *(int *)(*(int *)(iVar1 + 0x134) + 0x100);

    playerobj_eval_refpt(*(int *)(iVar1 + 0x134),*(int *)(iVar1 + 0x138),iVar1 + 8);

    ground_height_at(param_1 + 0xa0,local_1c);

    if ((*(byte *)(iVar2 + 0x28) & 1) == 0) {

      *(float *)(param_1 + 0xa8) = local_c + *(float *)(param_1 + 0x1d4);

    }

    else if (*(float *)(param_1 + 0xa8) < local_c) {

      *(float *)(param_1 + 0xa8) = local_c;

    }

    *(undefined4 *)(iVar1 + 0x14) = *(undefined4 *)(*(int *)(iVar1 + 0x134) + 200);

  }

  return;

}

/* ===== ai_ground_snap @ 0x004E2BA0 ===== */
undefined4 ai_ground_snap(int param_1)



{

  float *pfVar1;

  int iVar2;

  undefined4 *puVar3;

  undefined4 uVar4;

  float10 fVar5;

  undefined4 local_20;

  undefined1 local_1c [16];

  float local_c;

  

  iVar2 = *(int *)(param_1 + 0x100);

  if (*(int *)(iVar2 + 0x138) < 0) {

    local_20 = ai_move_ground_step(param_1,iVar2 + 0x134);

    uVar4 = *(undefined4 *)(iVar2 + 0x140);

  }

  else {

    puVar3 = *(undefined4 **)(*(int *)(iVar2 + 0x134) + 0x100);

    pfVar1 = (float *)(param_1 + 0xa0);

    playerobj_eval_refpt(*(int *)(iVar2 + 0x134),*(int *)(iVar2 + 0x138),pfVar1);

    ground_height_at(pfVar1,local_1c);

    if ((*(byte *)(puVar3 + 10) & 1) == 0) {

      *(float *)(param_1 + 0xa8) = local_c + *(float *)(param_1 + 0x1d4);

    }

    else if (*(float *)(param_1 + 0xa8) < local_c) {

      *(float *)(param_1 + 0xa8) = local_c;

    }

    local_20 = *puVar3;

    if ((*(float *)(param_1 + 0xb8) != *pfVar1) ||

       (*(float *)(param_1 + 0xbc) != *(float *)(param_1 + 0xa4))) {

      fVar5 = (float10)dirfcalcp3d__FP3P3DT0(param_1 + 0xb8,pfVar1);

      fVar5 = (float10)FUN_00518b70(param_1,0,0x461c4000,(float)fVar5,param_1 + 200);

      chase_angle((float)(fVar5 * (float10)30.0));

    }

    uVar4 = puVar3[9];

    *(undefined4 *)(iVar2 + 0x144) = puVar3[10];

  }

  ObjectCalculateTransform(param_1);

  *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) | 0x20;

  *(undefined4 *)(param_1 + 0x10c) = uVar4;

  return local_20;

}

/* ===== rpman_find_hide_spot__FP6OBJECTi @ 0x004E2CE0 ===== */
/* PS2 candidate: rpman_find_hide_spot__FP6OBJECTi (conf 0.436) */



void rpman_find_hide_spot__FP6OBJECTi(int param_1,int param_2)



{

  int *piVar1;

  int iVar2;

  undefined4 *puVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  byte bVar7;

  float10 fVar8;

  float10 fVar9;

  float local_18;

  undefined4 *local_14;

  float local_10;

  int local_8;

  

  piVar1 = *(int **)(param_1 + 0x100);

  piVar1[0x11] = 0;

  if (*(int *)(param_1 + 0xe8) != 0xe) {

    local_10 = 40000.0;

    local_8 = 0;

    local_14 = DAT_00632d7c;

    if (DAT_00632d7c != (undefined4 *)0x0) {

      do {

        iVar2 = local_14[3];

        if (((*(uint *)(iVar2 + 0xd8) & 0x4000c000) == 0) &&

           ((*(char *)(iVar2 + 0x1f7) == '\x02' || (*(char *)(iVar2 + 0x1f7) == '\x03')))) {

          iVar5 = param_1 + 0xa0;

          iVar6 = iVar2 + 0xa0;

          fVar8 = (float10)distancesq2d__FP3P3DT0(iVar6,iVar5);

          local_18 = (float)fVar8;

          if (fVar8 <= (float10)local_10) {

            puVar3 = DAT_00632d7c;

            if (param_2 == 0) {

              if (*piVar1 == 0) goto joined_r0x004e2e65;

              fVar8 = (float10)distancesq2d__FP3P3DT0(*piVar1 + 0xa0,iVar6);

              if ((float10)local_18 <= fVar8) {

                fVar8 = (float10)distancesq2d__FP3P3DT0(iVar5,*piVar1 + 0xa0);

                fVar9 = (float10)distancesq2d__FP3P3DT0(*piVar1 + 0xa0,iVar6);

                puVar3 = DAT_00632d7c;

                if ((float10)(float)fVar8 <= fVar9) goto joined_r0x004e2e65;

              }

            }

            else {

              if (local_18 < 169.0) break;

              if (*piVar1 == 0) {

joined_r0x004e2e65:

                for (; puVar3 != (undefined4 *)0x0; puVar3 = (undefined4 *)*puVar3) {

                  iVar5 = puVar3[3];

                  if ((*(int *)(iVar5 + 4) == 0xd7) && (iVar5 != param_1)) {

                    if (*(int *)(*(int *)(iVar5 + 0x100) + 0x44) == iVar2) goto LAB_004e2f36;

                    fVar8 = (float10)distancesq2d__FP3P3DT0(iVar6,iVar5 + 0xa0);

                    local_18 = (float)fVar8;

                    bVar7 = fVar8 < (float10)169.0 |

                            (byte)((ushort)((ushort)(NAN(fVar8) || NAN((float10)169.0)) << 10) >> 8)

                    ;

LAB_004e2f05:

                    if ((POPCOUNT(bVar7) & 1U) != 0) goto LAB_004e2f36;

                  }

                  else {

                    iVar4 = ObjIsMecc(iVar5);

                    if ((iVar4 != 0) || (iVar4 = ObjIsReaper(iVar5), iVar4 != 0)) {

                      fVar8 = (float10)distancesq2d__FP3P3DT0(iVar6,iVar5 + 0xa0);

                      local_18 = (float)fVar8;

                      bVar7 = fVar8 < (float10)225.0 |

                              (byte)((ushort)((ushort)(NAN(fVar8) || NAN((float10)225.0)) << 10) >>

                                    8);

                      goto LAB_004e2f05;

                    }

                    iVar4 = ObjIsKabuto(iVar5);

                    if (iVar4 != 0) {

                      fVar8 = (float10)distancesq2d__FP3P3DT0(iVar6,iVar5 + 0xa0);

                      local_18 = (float)fVar8;

                      bVar7 = fVar8 < (float10)1600.0 |

                              (byte)((ushort)((ushort)(NAN(fVar8) || NAN((float10)1600.0)) << 10) >>

                                    8);

                      goto LAB_004e2f05;

                    }

                  }

                }

                fVar8 = (float10)rndfloat(0x45afc800);

                local_10 = (float)(fVar8 + (float10)local_18);

                local_8 = iVar2;

              }

              else {

                fVar8 = (float10)distancesq2d__FP3P3DT0(*piVar1 + 0xa0,iVar5);

                if ((float10)local_18 <= fVar8) {

                  fVar8 = (float10)distancesq2d__FP3P3DT0(iVar6,*piVar1 + 0xa0);

                  fVar9 = (float10)distancesq2d__FP3P3DT0(*piVar1 + 0xa0,iVar5);

                  puVar3 = DAT_00632d7c;

                  if ((float10)(float)fVar8 <= fVar9) goto joined_r0x004e2e65;

                }

              }

            }

          }

        }

LAB_004e2f36:

        local_14 = (undefined4 *)*local_14;

      } while (local_14 != (undefined4 *)0x0);

      if (local_8 != 0) {

        piVar1[0x11] = local_8;

      }

    }

  }

  return;

}

/* ===== ai_d7_pairing @ 0x004E2F60 ===== */
void ai_d7_pairing(int param_1,float param_2)



{

  int *piVar1;

  int iVar2;

  int *piVar3;

  int iVar4;

  undefined4 *puVar5;

  float10 fVar6;

  

  if ((*(int *)(param_1 + 4) != 0xd7) ||

     (((*(uint *)(param_1 + 0xe0) & 0x20) == 0 && ((*(uint *)(param_1 + 0xe0) & 0x40) != 0)))) {

    piVar1 = *(int **)(param_1 + 0x100);

    for (puVar5 = DAT_00632d6c; puVar5 != (undefined4 *)0x0; puVar5 = (undefined4 *)*puVar5) {

      iVar2 = puVar5[3];

      piVar3 = *(int **)(iVar2 + 0x100);

      if ((((*(int *)(iVar2 + 4) == 0xd7) && (iVar2 != param_1)) && (*piVar3 == 0)) &&

         ((*(int *)(iVar2 + 0xe8) != 0x66 ||

          (((piVar3[0x7c] == 0 && ((*(byte *)(piVar3 + 0x6e) & 1) != 0)) &&

           (((*(uint *)(iVar2 + 0xe0) & 0x1000000) == 0 && (piVar3[0x8a] == 0)))))))) {

        if ((((*(int *)(param_1 + 4) == 0xd7) && (iVar4 = piVar1[0x4d], iVar4 != 0)) &&

            (piVar3[0x4d] == iVar4)) && ((*(byte *)(param_1 + 0xe4) & 0x40) == 0)) {

          *(uint *)(iVar2 + 0xe0) = *(uint *)(iVar2 + 0xe0) | 0x21;

          piVar3[1] = *piVar1;

        }

        else {

          fVar6 = (float10)distancesq2d__FP3P3DT0(iVar2 + 0xa0,param_1 + 0xa0);

          if (fVar6 <= (float10)param_2 * (float10)param_2) {

            if (*(int *)(param_1 + 4) == 0xd7) {

              *(uint *)(iVar2 + 0xe0) = *(uint *)(iVar2 + 0xe0) | 1;

            }

            else {

              *(uint *)(iVar2 + 0xe0) = *(uint *)(iVar2 + 0xe0) | 0x21;

              piVar3[1] = *(int *)(param_1 + 0x274);

            }

          }

        }

      }

    }

  }

  return;

}

/* ===== rpman_verify_enemy__FP6OBJECTf @ 0x004E30B0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* PS2 candidate: rpman_verify_enemy__FP6OBJECTf (conf 0.458) */



undefined4 rpman_verify_enemy__FP6OBJECTf(int param_1,float param_2)



{

  float fVar1;

  int *piVar2;

  int iVar3;

  int iVar4;

  uint uVar5;

  float10 fVar6;

  undefined4 uVar7;

  undefined4 local_18;

  undefined4 local_14;

  float local_10;

  undefined4 local_c;

  undefined4 local_8;

  float local_4;

  

  piVar2 = *(int **)(param_1 + 0x100);

  if ((DAT_005a858c != 0) &&

     (iVar3 = rpman_smartie_consider__FP6OBJECTT0(param_1,DAT_005a858c), iVar3 != 0)) {

    return 1;

  }

  if ((float)piVar2[0x28] < (float)piVar2[0x29]) {

    param_2 = (float)piVar2[0x29];

  }

  if ((*(uint *)(param_1 + 0xe0) & 0x20) != 0) {

    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xffffffdf;

    return 0;

  }

  iVar3 = ObjIsMecc(*piVar2);

  if ((iVar3 != 0) && ((*(uint *)(*piVar2 + 0xe0) & 0x2000000) != 0)) {

    *piVar2 = 0;

  }

  iVar3 = ObjIsReaper(*piVar2);

  if (iVar3 != 0) {

    if ((*(byte *)(*piVar2 + 0xe0) & 8) == 0) {

      *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xefffffff;

    }

    else if ((*(uint *)(param_1 + 0xe0) & 0x10000000) == 0) {

      *piVar2 = 0;

      *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 0x10000000;

    }

  }

  if (*piVar2 != 0) {

    iVar3 = obj_is_pickup_4a(*piVar2);

    if ((iVar3 == 0) && (iVar3 = obj_is_pickup_53(*piVar2), iVar3 == 0)) {

      iVar3 = *piVar2;

      if (((*(uint *)(iVar3 + 0xd8) & 0x4000c000) != 0) ||

         (*(float *)(iVar3 + 0x1c0) <= *(float *)(iVar3 + 0x278))) {

LAB_004e3204:

        *piVar2 = 0;

      }

      else {

        iVar3 = ObjIsKabuto(iVar3);

        if (iVar3 != 0) {

          if (param_2 <= 0.0) goto LAB_004e3253;

          if (param_2 * param_2 < (float)piVar2[0xd] * 0.25) goto LAB_004e3204;

        }

      }

      if ((0.0 < param_2) && (param_2 * param_2 < (float)piVar2[0xd])) {

LAB_004e324d:

        *piVar2 = 0;

      }

    }

    else {

      iVar3 = ObjIsTurret(*piVar2);

      if ((iVar3 == 0) && (iVar3 = bldg_get_max_energy(*piVar2), iVar3 != 0)) goto LAB_004e324d;

    }

  }

LAB_004e3253:

  if (*(int *)(param_1 + 0xe8) != 0x66) {

    fVar6 = (float10)FUN_00518b70(param_1,0);

    fVar6 = (float10)*(float *)(param_1 + 0xec) - fVar6;

    *(float *)(param_1 + 0xec) = (float)fVar6;

    if (fVar6 < (float10)0.0) {

      iVar3 = *piVar2;

      rpman_scan_for_enemy__FP6OBJECTfii(param_1,param_2,1,0);

      iVar4 = *piVar2;

      if (iVar4 == 0) {

LAB_004e32bc:

        *piVar2 = iVar3;

      }

      else {

        if (iVar4 != iVar3) {

          fVar6 = (float10)FUN_0050a610(param_1 + 0xa0,iVar4 + 0xa0);

          piVar2[0xd] = (int)(float)fVar6;

        }

        if (*piVar2 == 0) goto LAB_004e32bc;

      }

      *(undefined4 *)(param_1 + 0xec) = 0x40a00000;

    }

  }

  if (*piVar2 == 0) {

    return 0;

  }

  fVar6 = (float10)FUN_00518b70(param_1,0);

  fVar1 = (float)piVar2[0xf];

  piVar2[0xf] = (int)(float)((float10)fVar1 - fVar6);

  if ((float10)0.0 <= (float10)fVar1 - fVar6) goto LAB_004e33f4;

  if ((*(byte *)(param_1 + 0xe0) & 8) == 0) {

    piVar2[0xf] = 0x3f800000;

  }

  else {

    piVar2[0xf] = 0x3e800000;

  }

  iVar3 = **(int **)(param_1 + 0x100);

  if (iVar3 == 0) {

LAB_004e33e5:

    uVar5 = *(uint *)(param_1 + 0xe0) | 2;

  }

  else {

    iVar4 = obj_is_pickup_4a(iVar3);

    if ((iVar4 == 0) && (iVar4 = obj_is_pickup_53(iVar3), iVar4 == 0)) {

      local_c = *(undefined4 *)(param_1 + 0xa0);

      local_8 = *(undefined4 *)(param_1 + 0xa4);

      local_4 = *(float *)(param_1 + 0x1e8) * *(float *)(param_1 + 0xc4) +

                *(float *)(param_1 + 0xa8);

      local_18 = *(undefined4 *)(iVar3 + 0xa0);

      local_14 = *(undefined4 *)(iVar3 + 0xa4);

      local_10 = *(float *)(iVar3 + 0x1e8) * *(float *)(iVar3 + 0xc4) + *(float *)(iVar3 + 0xa8);

      if (*(int *)(param_1 + 0x210) == 0) {

        uVar7 = 7;

      }

      else {

        _DAT_00561494 = *(undefined4 *)(*(int *)(param_1 + 0x210) + 4);

        uVar7 = 8;

      }

      iVar3 = ai_class_filter(&local_c,&local_18,uVar7,&DAT_00561478,0);

      if (iVar3 == 0) goto LAB_004e33e5;

    }

    uVar5 = *(uint *)(param_1 + 0xe0) & 0xfffffffd;

  }

  *(uint *)(param_1 + 0xe0) = uVar5;

LAB_004e33f4:

  if ((*(byte *)(param_1 + 0xe0) & 2) == 0) {

    piVar2[0xe] = 0;

  }

  else {

    fVar6 = (float10)FUN_00518b70(param_1,0);

    fVar1 = (float)piVar2[0xe];

    piVar2[0xe] = (int)(float)(fVar6 + (float10)fVar1);

    if ((float10)20.0 < fVar6 + (float10)fVar1) {

      *piVar2 = 0;

      return 0;

    }

  }

  return 0;

}

/* ===== rpman_smartie_consider__FP6OBJECTT0 @ 0x004E3440 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* PS2 candidate: rpman_smartie_consider__FP6OBJECTT0 (conf 0.377) */



undefined4 rpman_smartie_consider__FP6OBJECTT0(int param_1,int param_2)



{

  int *piVar1;

  int *piVar2;

  float10 fVar3;

  

  piVar2 = *(int **)(param_1 + 0x100);

  if (*piVar2 == param_2) {

    return 1;

  }

  if ((((*(int *)(param_1 + 0xe8) == 0x66) && (_DAT_005a8580 <= _DAT_005a857c)) &&

      (DAT_005a8578 == 0)) && ((*(uint *)(param_1 + 0xe0) & 0x400) == 0)) {

    piVar1 = (int *)(param_2 + 0xa0);

    fVar3 = (float10)FUN_0050a610(param_1 + 0xa0,piVar1);

    if (fVar3 < (float10)90000.0) {

      ai_moveonly_set_goal(param_1,piVar1);

      ai_goal_process(param_1);

      if (*(int *)(param_1 + 0x168) != 0) {

        *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 0x1000000;

        *piVar2 = param_2;

        DAT_005a8578 = param_1;

        piVar2[0x80] = *piVar1;

        piVar2[0x81] = *(int *)(param_2 + 0xa4);

        piVar2[0x82] = *(int *)(param_2 + 0xa8);

        piVar2[0x7f] = *(int *)(param_2 + 200);

        *(undefined4 *)(param_1 + 0xe4) = 0xdb;

        return 1;

      }

    }

  }

  return 0;

}

/* ===== rpman_check_los__FP6OBJECTT0 @ 0x004E3530 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* PS2 candidate: rpman_check_los__FP6OBJECTT0 (conf 0.507) */



undefined4 rpman_check_los__FP6OBJECTT0(int param_1,int param_2)



{

  int iVar1;

  undefined4 uVar2;

  undefined4 local_18;

  undefined4 local_14;

  float local_10;

  undefined4 local_c;

  undefined4 local_8;

  float local_4;

  

  if (param_2 == 0) {

    return 0;

  }

  iVar1 = obj_is_pickup_4a(param_2);

  if (iVar1 == 0) {

    iVar1 = obj_is_pickup_53(param_2);

    if (iVar1 == 0) {

      local_c = *(undefined4 *)(param_1 + 0xa0);

      local_8 = *(undefined4 *)(param_1 + 0xa4);

      local_4 = *(float *)(param_1 + 0x1e8) * *(float *)(param_1 + 0xc4) +

                *(float *)(param_1 + 0xa8);

      local_18 = *(undefined4 *)(param_2 + 0xa0);

      local_14 = *(undefined4 *)(param_2 + 0xa4);

      local_10 = *(float *)(param_2 + 0x1e8) * *(float *)(param_2 + 0xc4) +

                 *(float *)(param_2 + 0xa8);

      if (*(int *)(param_1 + 0x210) != 0) {

        _DAT_00561494 = *(undefined4 *)(*(int *)(param_1 + 0x210) + 4);

        uVar2 = ai_class_filter(&local_c,&local_18,8,&DAT_00561478,0);

        return uVar2;

      }

      uVar2 = ai_class_filter(&local_c,&local_18,7,&DAT_00561478,0);

      return uVar2;

    }

  }

  return 1;

}

/* ===== ai_los_clear_to_target @ 0x004E3620 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined4 ai_los_clear_to_target(float param_1,float param_2,int param_3,int param_4)



{

  int iVar1;

  undefined4 uVar2;

  float local_18;

  float local_14;

  float local_10;

  undefined4 local_c;

  undefined4 local_8;

  float local_4;

  

  if (param_4 == 0) {

    return 0;

  }

  iVar1 = obj_is_pickup_4a(param_4);

  if (iVar1 == 0) {

    iVar1 = obj_is_pickup_53(param_4);

    if (iVar1 == 0) {

      local_18 = *(float *)(param_3 + 0xa0) + param_1;

      local_14 = *(float *)(param_3 + 0xa4) + param_2;

      local_c = *(undefined4 *)(param_4 + 0xa0);

      local_8 = *(undefined4 *)(param_4 + 0xa4);

      local_10 = *(float *)(param_3 + 0x1e8) * *(float *)(param_3 + 0xc4) +

                 *(float *)(param_3 + 0xa8);

      local_4 = *(float *)(param_4 + 0x1e8) * *(float *)(param_4 + 0xc4) +

                *(float *)(param_4 + 0xa8);

      if (*(int *)(param_3 + 0x210) != 0) {

        _DAT_00561494 = *(undefined4 *)(*(int *)(param_3 + 0x210) + 4);

        uVar2 = ai_class_filter(&local_18,&local_c,8,&DAT_00561494,0);

        return uVar2;

      }

      uVar2 = ai_class_filter(&local_18,&local_c,7,&DAT_00561478,0);

      return uVar2;

    }

  }

  return 1;

}

/* ===== FUN_004e3730 @ 0x004E3730 ===== */
bool FUN_004e3730(int param_1)



{

  undefined4 *puVar1;

  int iVar2;

  float10 fVar3;

  

  if (0.0 < *(float *)(*(int *)(param_1 + 0x100) + 0x230)) {

    return false;

  }

  if (DAT_005a8588 == 0) {

    return false;

  }

  if (*(int *)(*(int *)(param_1 + 0x100) + 0xb0) != 0) {

    return false;

  }

  iVar2 = 0;

  puVar1 = &DAT_005a8500;

  do {

    if ((float)puVar1[3] < 0.0 == ((float)puVar1[3] == 0.0)) {

      fVar3 = (float10)distancesq2d__FP3P3DT0(puVar1,param_1 + 0xa0);

      if (fVar3 < (float10)40000.0) break;

    }

    puVar1 = puVar1 + 4;

    iVar2 = iVar2 + 1;

  } while ((int)puVar1 < 0x5a8550);

  return iVar2 < 5;

}

/* ===== ai_radius_scan @ 0x004E37C0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void ai_radius_scan(int param_1,float param_2)



{

  int *piVar1;

  int iVar2;

  undefined4 *puVar3;

  int iVar4;

  float10 fVar5;

  undefined4 uVar6;

  float local_20;

  undefined4 local_18;

  undefined4 local_14;

  float local_10;

  undefined4 local_c;

  undefined4 local_8;

  float local_4;

  

  piVar1 = *(int **)(param_1 + 0x100);

  if (piVar1[0x7c] != 0) {

    *piVar1 = 0;

    local_20 = param_2 * param_2;

    for (puVar3 = DAT_00632d80; puVar3 != (undefined4 *)0x0; puVar3 = (undefined4 *)*puVar3) {

      iVar2 = puVar3[3];

      if (*(int *)(iVar2 + 4) == 0x325) {

        fVar5 = (float10)distancesq2d__FP3P3DT0

                                   ((undefined4 *)(iVar2 + 0xa0),(undefined4 *)(param_1 + 0xa0));

        if (fVar5 < (float10)local_20) {

          iVar4 = obj_is_pickup_4a(iVar2);

          if ((iVar4 == 0) && (iVar4 = obj_is_pickup_53(iVar2), iVar4 == 0)) {

            local_c = *(undefined4 *)(param_1 + 0xa0);

            local_8 = *(undefined4 *)(param_1 + 0xa4);

            local_4 = *(float *)(param_1 + 0x1e8) * *(float *)(param_1 + 0xc4) +

                      *(float *)(param_1 + 0xa8);

            local_18 = *(undefined4 *)(iVar2 + 0xa0);

            local_14 = *(undefined4 *)(iVar2 + 0xa4);

            local_10 = *(float *)(iVar2 + 0x1e8) * *(float *)(iVar2 + 0xc4) +

                       *(float *)(iVar2 + 0xa8);

            if (*(int *)(param_1 + 0x210) == 0) {

              uVar6 = 7;

            }

            else {

              _DAT_00561494 = *(undefined4 *)(*(int *)(param_1 + 0x210) + 4);

              uVar6 = 8;

            }

            iVar4 = ai_class_filter(&local_c,&local_18,uVar6,&DAT_00561478,0);

            if (iVar4 == 0) goto LAB_004e3903;

          }

          *piVar1 = iVar2;

          local_20 = (float)fVar5;

        }

      }

LAB_004e3903:

    }

  }

  return;

}

/* ===== rpman_scan_for_enemy__FP6OBJECTfii @ 0x004E3920 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* PS2 candidate: rpman_scan_for_enemy__FP6OBJECTfii (conf 0.445) */



void rpman_scan_for_enemy__FP6OBJECTfii(int param_1,float param_2,int param_3,int param_4)



{

  undefined4 *puVar1;

  undefined4 *puVar2;

  int *piVar3;

  int iVar4;

  float fVar5;

  int iVar6;

  int iVar7;

  uint uVar8;

  float10 fVar9;

  undefined4 uVar10;

  float local_2c;

  uint local_28;

  int *local_20;

  undefined4 local_18;

  undefined4 local_14;

  float local_10;

  undefined4 local_c;

  undefined4 local_8;

  float local_4;

  

  piVar3 = *(int **)(param_1 + 0x100);

  local_28 = *(uint *)(param_1 + 0xe0) & 1;

  *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xfffffffe;

  if ((local_28 == 0) || (iVar4 = piVar3[1], iVar4 == 0)) {

    *piVar3 = 0;

    fVar5 = param_2 * param_2;

    local_20 = DAT_00632d6c;

    local_2c = fVar5;

    if (DAT_00632d6c != (int *)0x0) {

      do {

        iVar4 = local_20[3];

        iVar6 = ObjIsPlayer(iVar4);

        if (((iVar6 == 0) && (*(int *)(iVar4 + 0x1e0) != 0x55)) &&

           ((iVar6 = ObjIsTurret(iVar4), iVar6 == 0 || (*(int *)(iVar4 + 0x18c) == 100)))) {

LAB_004e3a00:

          if ((*(uint *)(param_1 + 0xe0) & 0x1000000) == 0) {

            if (((*(int *)(iVar4 + 0x1e0) == 0x12) && (*(int *)(iVar4 + 0xe8) == 10)) &&

               (DAT_005a858c = iVar4, iVar6 = rpman_smartie_consider__FP6OBJECTT0(param_1,iVar4),

               iVar6 != 0)) {

              return;

            }

            if (param_4 != 0) {

              iVar6 = obj_is_pickup_4a(iVar4);

              if ((iVar6 == 0) && (iVar6 = obj_is_pickup_53(iVar4), iVar6 == 0)) {

                iVar6 = ObjIsTurret(*piVar3);

                if ((iVar6 != 0) && (*(int *)(iVar4 + 0x18c) != *(int *)(param_1 + 0x18c))) {

LAB_004e3ad2:

                  if ((*(int *)(param_1 + 0xe4) == 0xde) || (*(int *)(param_1 + 0xe4) == 0x23)) {

                    fVar9 = (float10)dirfcalcp3d__FP3P3DT0(param_1 + 0xa0,iVar4 + 0xa0);

                    fVar9 = (float10)diff_angle((float)fVar9,*(undefined4 *)(param_1 + 200));

                    if (fVar9 <= (float10)*(float *)(DAT_00632ed8 + 0xa9c)) {

                      fVar9 = (float10)distancesq2d__FP3P3DT0(param_1 + 0xa0,iVar4 + 0xa0);

                      param_2 = (float)fVar9;

                      uVar8 = (uint)(ushort)((ushort)(fVar9 < (float10)local_2c) << 8 |

                                            (ushort)(fVar9 == (float10)local_2c) << 0xe);

                      goto LAB_004e3e3c;

                    }

                  }

                  else {

                    fVar9 = (float10)FUN_0050a610(param_1 + 0xa0,iVar4 + 0xa0);

                    param_2 = (float)fVar9;

                    iVar6 = ObjIsTurret(iVar4);

                    if (((iVar6 != 0) && (iVar6 = obj_is_pickup_53_model(*piVar3), iVar6 == 0)) &&

                       (iVar6 = obj_is_pickup_4a_model(*piVar3), iVar6 == 0)) {

                      param_2 = param_2 * 0.5;

                    }

                    if ((param_2 <= local_2c) || (local_2c == fVar5)) goto LAB_004e3e42;

                  }

                }

              }

              else {

                iVar6 = bldg_get_max_energy(iVar4);

                if (iVar6 == 0) goto LAB_004e3ad2;

              }

            }

          }

          else {

            iVar6 = obj_is_pickup_4a_model(iVar4);

            if (((iVar6 != 0) || (iVar6 = obj_is_pickup_53_model(iVar4), iVar6 != 0)) &&

               (iVar6 = bldg_get_max_energy(iVar4), iVar6 == 0)) {

              local_2c = param_2;

              *piVar3 = iVar4;

            }

          }

        }

        else if (param_3 == 0) {

          iVar6 = ObjIsTurret(iVar4);

          if (iVar6 != 0) goto LAB_004e3a00;

        }

        else if ((((*(uint *)(param_1 + 0xe0) & 0x40000) == 0) &&

                 ((*(uint *)(iVar4 + 0xd8) & 0x4000c000) == 0)) &&

                (*(float *)(iVar4 + 0x278) < *(float *)(iVar4 + 0x1c0))) {

          if (*(int *)(param_1 + 0xe8) == 0x66) {

            iVar6 = piVar3[0x73];

            iVar7 = crt_rand_scaled(100);

            if ((iVar6 <= iVar7) && ((*piVar3 != 0 || (iVar6 == 0)))) goto LAB_004e3e52;

          }

          puVar1 = (undefined4 *)(iVar4 + 0xa0);

          puVar2 = (undefined4 *)(param_1 + 0xa0);

          fVar9 = (float10)FUN_0050a610(puVar2,puVar1);

          param_2 = (float)fVar9;

          iVar6 = ObjIsKabuto(iVar4);

          if (iVar6 != 0) {

            param_2 = param_2 * 0.25;

          }

          if (((param_2 <= local_2c) && (param_2 <= fVar5)) &&

             ((iVar6 = ObjIsMecc(iVar4), iVar6 == 0 || ((*(uint *)(iVar4 + 0xe0) & 0x2000000) == 0))

             )) {

            if (param_2 < 144.0) {

              local_28 = 1;

            }

            iVar6 = ObjIsKabuto(iVar4);

            if ((iVar6 != 0) && (param_2 < 10000.0)) {

              local_28 = 1;

            }

            if ((DAT_006328e8 - DAT_00632b44 < 1.0 != (DAT_006328e8 - DAT_00632b44 == 1.0)) &&

               ((float)piVar3[0x1a] != DAT_00632b44)) {

              piVar3[0x1a] = (int)DAT_00632b44;

              fVar9 = (float10)distancesq2d__FP3P3DT0(puVar2,&DAT_00632b48);

              if (fVar9 < (float10)14400.0) {

                local_28 = 1;

                local_2c = param_2;

                *piVar3 = iVar4;

                goto LAB_004e3e52;

              }

            }

            if (local_28 == 0) {

              fVar9 = (float10)dirfcalcp3d__FP3P3DT0(puVar2,puVar1);

              fVar9 = (float10)diff_angle((float)fVar9,piVar3[0x16]);

              if ((float10)*(float *)(DAT_00632ed8 + 0xa9c) < fVar9) goto LAB_004e3e52;

              iVar6 = obj_is_pickup_4a(iVar4);

              if ((iVar6 != 0) || (iVar6 = obj_is_pickup_53(iVar4), iVar6 != 0)) goto LAB_004e3e42;

              local_c = *puVar2;

              local_8 = *(undefined4 *)(param_1 + 0xa4);

              local_4 = *(float *)(param_1 + 0x1e8) * *(float *)(param_1 + 0xc4) +

                        *(float *)(param_1 + 0xa8);

              local_18 = *puVar1;

              local_14 = *(undefined4 *)(iVar4 + 0xa4);

              local_10 = *(float *)(iVar4 + 0x1e8) * *(float *)(iVar4 + 0xc4) +

                         *(float *)(iVar4 + 0xa8);

              if (*(int *)(param_1 + 0x210) == 0) {

                uVar10 = 7;

              }

              else {

                _DAT_00561494 = *(undefined4 *)(*(int *)(param_1 + 0x210) + 4);

                uVar10 = 8;

              }

              uVar8 = ai_class_filter(&local_c,&local_18,uVar10,&DAT_00561478,0);

LAB_004e3e3c:

              if (uVar8 == 0) goto LAB_004e3e52;

            }

LAB_004e3e42:

            local_2c = param_2;

            *piVar3 = iVar4;

          }

        }

LAB_004e3e52:

        local_20 = (int *)*local_20;

      } while (local_20 != (int *)0x0);

      if (*piVar3 != 0) {

        *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xffffffdd | 0x40;

        fVar9 = (float10)FUN_0050a610(param_1 + 0xa0,*piVar3 + 0xa0);

        piVar3[0xd] = (int)(float)fVar9;

        return;

      }

    }

  }

  else {

    *piVar3 = iVar4;

    fVar9 = (float10)FUN_0050a610(param_1 + 0xa0,iVar4 + 0xa0);

    piVar3[0xd] = (int)(float)fVar9;

    piVar3[1] = 0;

  }

  *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xffffffbf;

  return;

}

/* ===== rpman_consider_run_chatter__FP6OBJECT @ 0x004E3EB0 ===== */
/* PS2 candidate: rpman_consider_run_chatter__FP6OBJECT (conf 0.431) */



void rpman_consider_run_chatter__FP6OBJECT(int param_1)



{

  int iVar1;

  undefined4 uVar2;

  float10 fVar3;

  

  iVar1 = *(int *)(param_1 + 0x100);

  fVar3 = (float10)FUN_00518b70(param_1,0);

  fVar3 = (float10)*(float *)(iVar1 + 0x40) - fVar3;

  *(float *)(iVar1 + 0x40) = (float)fVar3;

  if (fVar3 < (float10)0.0) {

    fVar3 = (float10)rndfloatrange(0x41a00000,0x42c80000);

    *(float *)(iVar1 + 0x40) = (float)fVar3;

    uVar2 = rndintrange(0x7d,0x81);

    sound_play_obj(uVar2,param_1);

  }

  return;

}

/* ===== rpman_set_enemy_attack_goal__FP6OBJECTi @ 0x004E3F10 ===== */
/* PS2 candidate: rpman_set_enemy_attack_goal__FP6OBJECTi (conf 0.441) */



void rpman_set_enemy_attack_goal__FP6OBJECTi(int param_1,int param_2)



{

  int *piVar1;

  int iVar2;

  float10 fVar3;

  float10 fVar4;

  undefined4 uVar5;

  int iVar6;

  float fVar7;

  float fVar8;

  float local_14;

  float local_10;

  float local_c;

  float local_8;

  undefined4 local_4;

  

  piVar1 = *(int **)(param_1 + 0x100);

  if (*piVar1 == 0) {

    return;

  }

  if (param_2 != 0) {

    fVar3 = (float10)rndfloatrange(0x41a00000,0x42480000);

    if ((*(uint *)(param_1 + 0xe0) & 0x10000) == 0) {

      fVar7 = *(float *)(param_1 + 200) - 10.0;

      uVar5 = *(undefined4 *)(param_1 + 200);

    }

    else {

      fVar7 = *(float *)(param_1 + 200) + 10.0;

      uVar5 = *(undefined4 *)(param_1 + 200);

    }

    fVar4 = (float10)rndfloatrange(uVar5,fVar7);

    sine_cos_lookup((float)fVar4,&local_14,&local_10);

    local_4 = *(undefined4 *)(param_1 + 0xa8);

    *(undefined1 **)(param_1 + 0x16c) = &LAB_004cb930;

    local_c = local_14 * (float)fVar3 + *(float *)(param_1 + 0xa0);

    local_8 = *(float *)(param_1 + 0xa4) - local_10 * (float)fVar3;

    if (piVar1[0x36] == 0) {

      ai_moveonly_set_goal(param_1,&local_c);

    }

    else {

      ai_move_force_goal(param_1,&local_c);

    }

    ai_goal_process(param_1);

    if (*(int *)(param_1 + 0x168) != 0) {

      return;

    }

    if (*(int *)(param_1 + 0xe8) != 0x66) {

      *(undefined4 *)(param_1 + 0xe4) = 0xd;

      return;

    }

    *(undefined4 *)(param_1 + 0xe4) = 0xd1;

    return;

  }

  iVar2 = obj_is_pickup_4a(*piVar1);

  if ((iVar2 == 0) && (iVar2 = obj_is_pickup_53(*piVar1), iVar2 == 0)) {

    if ((*(uint *)(param_1 + 0xe0) & 0x40000) == 0) {

      iVar2 = piVar1[0x28];

      iVar6 = piVar1[0x27];

      goto LAB_004e409b;

    }

  }

  else if ((*(uint *)(param_1 + 0xe0) & 0x40000) == 0) {

    iVar2 = 0x42c80000;

    iVar6 = 0x42700000;

    goto LAB_004e409b;

  }

  iVar2 = 0x42480000;

  iVar6 = 0x41f00000;

LAB_004e409b:

  fVar3 = (float10)rndfloatrange(iVar6,iVar2);

  fVar4 = (float10)dirfcalcp3d__FP3P3DT0(*piVar1 + 0xa0,param_1 + 0xa0);

  fVar7 = (float)fVar4;

  iVar2 = obj_is_pickup_4a_model(*piVar1);

  if ((iVar2 == 0) && (iVar2 = obj_is_pickup_53_model(*piVar1), iVar2 == 0)) {

    fVar8 = fVar7 + 70.0;

    fVar7 = fVar7 - 70.0;

  }

  else {

    fVar8 = fVar7 + 10.0;

    fVar7 = fVar7 - 10.0;

  }

  fVar4 = (float10)rndfloatrange(fVar7,fVar8);

  sine_cos_lookup((float)fVar4,&local_14,&local_10);

  local_c = local_14 * (float)fVar3 + *(float *)(*piVar1 + 0xa0);

  local_8 = *(float *)(*piVar1 + 0xa4) - local_10 * (float)fVar3;

  local_4 = *(undefined4 *)(*piVar1 + 0xa8);

  *(undefined1 **)(param_1 + 0x16c) = &LAB_004cb930;

  if (piVar1[0x36] == 0) {

    ai_moveonly_set_goal(param_1,&local_c);

  }

  else {

    ai_move_force_goal(param_1,&local_c);

  }

  iVar2 = crt_rand_scaled(100);

  if (0x31 < iVar2) {

    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xfffeffff;

    return;

  }

  *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 0x10000;

  return;

}

/* ===== obj_turn_toward_point @ 0x004E41E0 ===== */
float10 obj_turn_toward_point(int param_1,undefined4 param_2)



{

  undefined1 uVar1;

  float10 fVar2;

  float10 fVar3;

  

  fVar2 = (float10)dirfcalcp3d__FP3P3DT0(param_1 + 0xa0,param_2);

  fVar3 = (float10)playerobj_turn((float)fVar2,*(undefined4 *)(param_1 + 200));

  if (ABS(fVar3) == (float10)0.0) {

    return (float10)0.0;

  }

  *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) | 0x1000000;

  *(float *)(param_1 + 0x158) = (float)fVar2;

  uVar1 = __ftol();

  *(undefined1 *)(param_1 + 0x208) = uVar1;

  return (float10)(float)ABS(fVar3);

}

/* ===== rpman_turn_towards @ 0x004E4280 ===== */
undefined4 rpman_turn_towards(int param_1,undefined4 param_2)



{

  float fVar1;

  float fVar2;

  undefined1 uVar3;

  int iVar4;

  float10 fVar5;

  

  iVar4 = *(int *)(param_1 + 0x100);

  fVar5 = (float10)dirfcalcp3d__FP3P3DT0(param_1 + 0xa0,param_2);

  fVar1 = (float)fVar5;

  fVar5 = (float10)playerobj_turn(fVar1,*(undefined4 *)(iVar4 + 0x158));

  fVar2 = (float)fVar5;

  fVar5 = (float10)playerobj_turn(fVar1,*(undefined4 *)(param_1 + 200));

  if (ABS(fVar5) != (float10)0.0) {

    *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) | 0x1000000;

    *(float *)(param_1 + 0x158) = fVar1;

    uVar3 = __ftol();

    *(undefined1 *)(param_1 + 0x208) = uVar3;

  }

  iVar4 = *(int *)(iVar4 + 0x154) * 4;

  if ((*(float *)(&DAT_005a84e8 + iVar4) <= fVar2) &&

     (fVar2 < *(float *)(&DAT_005a8550 + iVar4) != (fVar2 == *(float *)(&DAT_005a8550 + iVar4)))) {

    return 1;

  }

  return 0;

}

/* ===== rpman_maintain_hide__FP6OBJECT @ 0x004E4360 ===== */
/* PS2 candidate: rpman_maintain_hide__FP6OBJECT (conf 0.38) */



void rpman_maintain_hide__FP6OBJECT(int param_1)



{

  float fVar1;

  int *piVar2;

  int iVar3;

  float fVar4;

  undefined1 uVar5;

  float10 fVar6;

  undefined4 uVar7;

  float local_8;

  float local_4;

  

  piVar2 = *(int **)(param_1 + 0x100);

  if (piVar2[0x11] == 0) {

    rpman_find_hide_spot__FP6OBJECTi(param_1,1);

    if (piVar2[0x11] != 0) {

      *(undefined4 *)(param_1 + 0xe4) = 0x3c;

      return;

    }

    *(undefined4 *)(param_1 + 0xe4) = 0xc;

    return;

  }

  fVar6 = (float10)dirfcalcp3d__FP3P3DT0(piVar2[0x11] + 0xa0,*piVar2 + 0xa0);

  fVar1 = (float)fVar6;

  sine_cos_lookup(fVar1 + 180.0,&local_8,&local_4);

  iVar3 = piVar2[0x11];

  fVar4 = *(float *)(iVar3 + 0x1f8) * *(float *)(iVar3 + 0xc4) + *(float *)(param_1 + 0x154);

  piVar2[0x12] = (int)(fVar4 * local_8 + *(float *)(iVar3 + 0xa0));

  piVar2[0x13] = (int)(*(float *)(iVar3 + 0xa4) - fVar4 * local_4);

  piVar2[0x14] = *(int *)(iVar3 + 0xa8);

  *(undefined4 *)(param_1 + 0x1a8) = 0x42800000;

  fVar6 = (float10)playerobj_turn(fVar1,*(undefined4 *)(param_1 + 200));

  if (ABS(fVar6) != (float10)0.0) {

    *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) | 0x1000000;

    *(float *)(param_1 + 0x158) = fVar1;

    uVar5 = __ftol();

    *(undefined1 *)(param_1 + 0x208) = uVar5;

  }

  if ((*(char *)(param_1 + 0x208) == '\0') || (*(int *)(param_1 + 0xe4) != 0x41)) {

    if (((*(byte *)(param_1 + 0x30) & 2) == 0) ||

       ((*(int *)(param_1 + 0x10) == 0x2d || (*(int *)(*(int *)(param_1 + 8) + 0xbc) == 0))))

    goto LAB_004e4520;

    fVar1 = *(float *)(param_1 + 0xc4);

    uVar7 = 0x2d;

  }

  else {

    if ((*(int *)(param_1 + 0x10) == 0x9d) || (*(int *)(*(int *)(param_1 + 8) + 0x27c) == 0))

    goto LAB_004e4520;

    fVar1 = *(float *)(param_1 + 0xc4);

    uVar7 = 0x9d;

  }

  ObjectSetAnim(param_1,uVar7,0x21,0,fVar1 * 0.0,0x3e2aaaab);

LAB_004e4520:

  obj_alpha_fade_update(param_1);

  *(int *)(param_1 + 0x1a8) = piVar2[0x6b];

  *(undefined1 *)(param_1 + 0x208) = 0;

  sine_cos_lookup(*(float *)(param_1 + 200) + 180.0,&local_8,&local_4);

  *(float *)(param_1 + 0xa0) = fVar4 * local_8 + *(float *)(piVar2[0x11] + 0xa0);

  *(float *)(param_1 + 0xa4) = *(float *)(piVar2[0x11] + 0xa4) - fVar4 * local_4;

  fVar6 = (float10)get_floor_z_point((float *)(param_1 + 0xa0));

  *(float *)(param_1 + 0xa8) = (float)fVar6;

  return;

}

/* ===== rpman_set_anim_flags @ 0x004E45A0 ===== */
void rpman_set_anim_flags(int param_1)



{

  if ((*(uint *)(param_1 + 0xe0) & 0x200) == 0) {

    if ((*(uint *)(param_1 + 0xe0) & 0x100) == 0) {

      if ((*(int *)(param_1 + 0x10) != 0x52) && (*(int *)(*(int *)(param_1 + 8) + 0x150) != 0)) {

        ObjectSetAnim(param_1,0x52,0x21,0,*(float *)(param_1 + 0xc4) * 0.0,0x3e2aaaab);

      }

    }

    else if ((*(int *)(param_1 + 0x10) != 0x9c) && (*(int *)(*(int *)(param_1 + 8) + 0x278) != 0)) {

      ObjectSetAnim(param_1,0x9c,0x21,0,*(float *)(param_1 + 0xc4) * 0.0,0x3e2aaaab);

      return;

    }

  }

  else if ((*(int *)(param_1 + 0x10) != 0x91) && (*(int *)(*(int *)(param_1 + 8) + 0x24c) != 0)) {

    ObjectSetAnim(param_1,0x91,0x21,0,*(float *)(param_1 + 0xc4) * 0.0,0x3e2aaaab);

    return;

  }

  return;

}

/* ===== ai_rand_anim_select @ 0x004E4680 ===== */
void ai_rand_anim_select(int param_1,int param_2,int param_3)



{

  int iVar1;

  undefined4 uVar2;

  float10 fVar3;

  

  iVar1 = crt_rand_scaled(100);

  if ((*(uint *)(param_1 + 0xe0) & 0x200) == 0) {

    if ((*(float *)(DAT_00632ed8 + 0xb54) <= (float)iVar1) || (param_2 == 0)) {

      if (*(int *)(param_1 + 0x10) == 0x50) {

        return;

      }

      if (*(int *)(*(int *)(param_1 + 8) + 0x148) == 0) {

        return;

      }

      if (param_3 == 0) {

        uVar2 = 0x21;

      }

      else {

        fVar3 = (float10)rndfloatrange(0,0x3f800000);

        *(float *)(param_1 + 0x14) = (float)fVar3;

        uVar2 = 0x81;

      }

      ObjectSetAnim(param_1,0x50,uVar2,0,*(float *)(param_1 + 0xc4) * 0.0,0x3e2aaaab);

      return;

    }

  }

  else if ((*(float *)(DAT_00632ed8 + 0xb54) <= (float)iVar1) || (param_2 == 0)) {

    if ((*(int *)(param_1 + 0x10) != 0x8c) && (*(int *)(*(int *)(param_1 + 8) + 0x238) != 0)) {

      if (param_3 == 0) {

        uVar2 = 0x21;

      }

      else {

        fVar3 = (float10)rndfloatrange(0,0x3f800000);

        *(float *)(param_1 + 0x14) = (float)fVar3;

        uVar2 = 0x81;

      }

      ObjectSetAnim(param_1,0x8c,uVar2,0,*(float *)(param_1 + 0xc4) * 0.0,0x3e2aaaab);

      return;

    }

    return;

  }

  ai_damage_response(param_1,0,0,param_3);

  return;

}

/* ===== ai_idle_anim_select @ 0x004E47C0 ===== */
void ai_idle_anim_select(int param_1)



{

  int iVar1;

  

  if (*(int *)(*(int *)(param_1 + 0x100) + 0xd8) != 0) {

    ai_range_check(param_1);

    return;

  }

  if ((*(uint *)(param_1 + 0xe0) & 0x200) == 0) {

    iVar1 = crt_rand_scaled(300);

    if (iVar1 < 100) {

      if ((*(int *)(param_1 + 0x10) != 0x54) && (*(int *)(*(int *)(param_1 + 8) + 0x158) != 0)) {

        ObjectSetAnim(param_1,0x54,0x20,1,

                      *(float *)(DAT_00632ed8 + 0xb34) * *(float *)(param_1 + 0xc4),0x3e2aaaab);

        return;

      }

    }

    else if (iVar1 < 200) {

      if ((*(int *)(param_1 + 0x10) != 0x55) && (*(int *)(*(int *)(param_1 + 8) + 0x15c) != 0)) {

        ObjectSetAnim(param_1,0x55,0x20,1,

                      *(float *)(DAT_00632ed8 + 0xb34) * *(float *)(param_1 + 0xc4),0x3e2aaaab);

        return;

      }

    }

    else if ((*(int *)(param_1 + 0x10) != 0x7d) && (*(int *)(*(int *)(param_1 + 8) + 0x1fc) != 0)) {

      ObjectSetAnim(param_1,0x7d,0x20,1,

                    *(float *)(DAT_00632ed8 + 0xb34) * *(float *)(param_1 + 0xc4),0x3e2aaaab);

    }

  }

  else if ((*(int *)(param_1 + 0x10) != 0x93) && (*(int *)(*(int *)(param_1 + 8) + 0x254) != 0)) {

    ObjectSetAnim(param_1,0x93,0x20,1,*(float *)(DAT_00632ed8 + 0xb34) * *(float *)(param_1 + 0xc4),

                  0x3e2aaaab);

    return;

  }

  return;

}

/* ===== ai_idle_anim_53 @ 0x004E4920 ===== */
void ai_idle_anim_53(int param_1,int param_2)



{

  float fVar1;

  float fVar2;

  undefined4 uVar3;

  float10 fVar4;

  

  if (*(int *)(*(int *)(param_1 + 0x100) + 0xd8) != 0) {

    cleaner_process(param_1,param_2);

    return;

  }

  if ((*(uint *)(param_1 + 0xe0) & 0x200) == 0) {

    fVar1 = *(float *)(DAT_00632ed8 + 0xb34);

    fVar2 = *(float *)(param_1 + 0xc4);

    if ((*(int *)(param_1 + 0x10) != 0x53) && (*(int *)(*(int *)(param_1 + 8) + 0x154) != 0)) {

      if (param_2 == 0) {

        uVar3 = 0x21;

      }

      else {

        fVar4 = (float10)rndfloatrange(0,0x3f800000);

        *(float *)(param_1 + 0x14) = (float)fVar4;

        uVar3 = 0x81;

      }

      ObjectSetAnim(param_1,0x53,uVar3,1,fVar1 * fVar2 * *(float *)(param_1 + 0xc4),0x3e2aaaab);

    }

  }

  else {

    fVar1 = *(float *)(DAT_00632ed8 + 0xb34);

    fVar2 = *(float *)(param_1 + 0xc4);

    if ((*(int *)(param_1 + 0x10) != 0x92) && (*(int *)(*(int *)(param_1 + 8) + 0x250) != 0)) {

      if (param_2 == 0) {

        uVar3 = 0x21;

      }

      else {

        fVar4 = (float10)rndfloatrange(0,0x3f800000);

        *(float *)(param_1 + 0x14) = (float)fVar4;

        uVar3 = 0x81;

      }

      ObjectSetAnim(param_1,0x92,uVar3,1,fVar1 * fVar2 * *(float *)(param_1 + 0xc4),0x3e2aaaab);

      return;

    }

  }

  return;

}

/* ===== ai_range_check @ 0x004E4A50 ===== */
void ai_range_check(int param_1)



{

  float10 fVar1;

  float10 fVar2;

  float10 fVar3;

  

  if ((*(int *)(param_1 + 0xe4) == 0x1e) || ((*(uint *)(param_1 + 0xe0) & 0x2000000) != 0)) {

    fVar3 = (float10)FUN_00518b70(param_1,0);

    fVar2 = (float10)*(float *)(param_1 + 0xa4) - (float10)*(float *)(param_1 + 0xbc);

    fVar1 = (float10)*(float *)(param_1 + 0xa0) - (float10)*(float *)(param_1 + 0xb8);

    fVar3 = SQRT(fVar2 * fVar2 + fVar1 * fVar1) / fVar3;

    fVar3 = fVar3 * fVar3;

  }

  else {

    fVar3 = (float10)*(float *)(param_1 + 300) * (float10)*(float *)(param_1 + 300) +

            (float10)*(float *)(param_1 + 0x128) * (float10)*(float *)(param_1 + 0x128);

  }

  fVar2 = (float10)*(float *)(DAT_00632ed8 + 0x1028) * (float10)*(float *)(DAT_00632ed8 + 0x1028);

  if (fVar3 < fVar2 == (fVar3 == fVar2)) {

    fVar2 = (float10)*(float *)(DAT_00632ed8 + 0x102c) * (float10)*(float *)(DAT_00632ed8 + 0x102c);

    if (fVar3 < fVar2 == (fVar3 == fVar2)) {

      if ((*(int *)(param_1 + 0x10) != 0x84) && (*(int *)(*(int *)(param_1 + 8) + 0x218) != 0)) {

        ObjectSetAnim(param_1,0x84,0x20,0,*(float *)(param_1 + 0xc4) * 0.0,0x3e2aaaab);

      }

    }

    else if ((*(int *)(param_1 + 0x10) != 0x82) && (*(int *)(*(int *)(param_1 + 8) + 0x210) != 0)) {

      ObjectSetAnim(param_1,0x82,0x21,0,*(float *)(param_1 + 0xc4) * 0.0,0x3e2aaaab);

      return;

    }

  }

  else if ((*(int *)(param_1 + 0x10) != 0x81) && (*(int *)(*(int *)(param_1 + 8) + 0x20c) != 0)) {

    ObjectSetAnim(param_1,0x81,0x20,0,*(float *)(param_1 + 0xc4) * 0.0,0x3e2aaaab);

    return;

  }

  return;

}

/* ===== cleaner_process @ 0x004E4BC0 ===== */
/* PS2 candidate: cleaner_process (conf 0.541) */



void cleaner_process(float param_1,int param_2)



{

  float fVar1;

  int iVar2;

  int iVar3;

  undefined4 uVar4;

  float10 fVar5;

  float10 fVar6;

  float10 fVar7;

  float local_c;

  float local_8;

  float local_4;

  

  iVar2 = (int)param_1;

  if ((*(int *)((int)param_1 + 0xe4) == 0x1e) || ((*(uint *)((int)param_1 + 0xe0) & 0x2000000) != 0)

     ) {

    fVar5 = (float10)FUN_00518b70(param_1,0);

    fVar6 = (float10)*(float *)((int)param_1 + 0xa4) - (float10)*(float *)((int)param_1 + 0xbc);

    fVar7 = (float10)*(float *)((int)param_1 + 0xa0) - (float10)*(float *)((int)param_1 + 0xb8);

    fVar5 = SQRT(fVar6 * fVar6 + fVar7 * fVar7) / fVar5;

    param_1 = (float)(fVar5 * fVar5);

  }

  else {

    local_c = -*(float *)((int)param_1 + 0x29c);

    local_8 = -*(float *)((int)param_1 + 0x2ac);

    local_4 = -*(float *)((int)param_1 + 700);

    fVar5 = (float10)Dot__FP3P3DT0((float *)((int)param_1 + 0x128),&local_c);

    if (fVar5 < (float10)0.0) {

      if (*(int *)((int)param_1 + 0x10) == 0xa4) {

        return;

      }

      if (*(int *)(*(int *)((int)param_1 + 8) + 0x298) == 0) {

        return;

      }

      ObjectSetAnim(param_1,0xa4,0x21,0,*(float *)((int)param_1 + 0xc4) * 0.0,0x3e2aaaab);

      return;

    }

    fVar1 = *(float *)((int)param_1 + 0x128);

    param_1 = *(float *)((int)param_1 + 300) * *(float *)((int)param_1 + 300) + fVar1 * fVar1;

  }

  iVar3 = crt_rand_scaled(100);

  if (iVar3 < 10) {

    ai_range_check(iVar2);

    return;

  }

  fVar1 = *(float *)(DAT_00632ed8 + 0x1028) * *(float *)(DAT_00632ed8 + 0x1028);

  if (param_1 < fVar1 == (param_1 == fVar1)) {

    fVar1 = *(float *)(DAT_00632ed8 + 0x102c) * *(float *)(DAT_00632ed8 + 0x102c);

    if (param_1 < fVar1 == (param_1 == fVar1)) {

      if ((*(int *)(iVar2 + 0x10) != 0x83) && (*(int *)(*(int *)(iVar2 + 8) + 0x214) != 0)) {

        if (param_2 == 0) {

          uVar4 = 0x21;

        }

        else {

          fVar5 = (float10)rndfloatrange(0,0x3f800000);

          *(float *)(iVar2 + 0x14) = (float)fVar5;

          uVar4 = 0x81;

        }

        ObjectSetAnim(iVar2,0x83,uVar4,0,*(float *)(iVar2 + 0xc4) * 0.0,0x3e2aaaab);

      }

    }

    else if ((*(int *)(iVar2 + 0x10) != 0x82) && (*(int *)(*(int *)(iVar2 + 8) + 0x210) != 0)) {

      if (param_2 == 0) {

        uVar4 = 0x21;

      }

      else {

        fVar5 = (float10)rndfloatrange(0,0x3f800000);

        *(float *)(iVar2 + 0x14) = (float)fVar5;

        uVar4 = 0x81;

      }

      ObjectSetAnim(iVar2,0x82,uVar4,0,*(float *)(iVar2 + 0xc4) * 0.0,0x3e2aaaab);

      return;

    }

  }

  else if ((*(int *)(iVar2 + 0x10) != 0x80) && (*(int *)(*(int *)(iVar2 + 8) + 0x208) != 0)) {

    if (param_2 == 0) {

      uVar4 = 0x21;

    }

    else {

      fVar5 = (float10)rndfloatrange(0,0x3f800000);

      *(float *)(iVar2 + 0x14) = (float)fVar5;

      uVar4 = 0x81;

    }

    ObjectSetAnim(iVar2,0x80,uVar4,0,*(float *)(iVar2 + 0xc4) * 0.0,0x3e2aaaab);

    return;

  }

  return;

}

/* ===== rpman_hurt_anim @ 0x004E4E70 ===== */
void rpman_hurt_anim(int param_1,int param_2)



{

  uint uVar1;

  int iVar2;

  int iVar3;

  

  if ((*(uint *)(param_1 + 0xe0) & 0x200) != 0) {

    ai_damage_response(param_1,1,0,0);

    return;

  }

  uVar1 = *(uint *)(param_1 + 0xe0) | 0x8004000;

  *(uint *)(param_1 + 0xe0) = uVar1;

  if (param_2 == 0) {

    iVar3 = *(int *)(param_1 + 0x10);

    if ((char)(uVar1 >> 8) < '\0') {

      if (iVar3 == 0x7f) {

        return;

      }

      iVar3 = *(int *)(*(int *)(param_1 + 8) + 0x204);

      goto LAB_004e4f31;

    }

  }

  else {

    iVar2 = crt_rand_scaled(100);

    iVar3 = *(int *)(param_1 + 0x10);

    if (iVar2 < 0x33) {

      *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 0x8000;

      if (iVar3 == 0x7f) {

        return;

      }

      iVar3 = *(int *)(*(int *)(param_1 + 8) + 0x204);

LAB_004e4f31:

      if (iVar3 == 0) {

        return;

      }

      ObjectSetAnim(param_1,0x7f,0x21,0,*(float *)(param_1 + 0xc4) * 0.0,0x3e2aaaab);

      return;

    }

    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xffff7fff;

  }

  if ((iVar3 != 0x7e) && (*(int *)(*(int *)(param_1 + 8) + 0x200) != 0)) {

    ObjectSetAnim(param_1,0x7e,0x21,0,*(float *)(param_1 + 0xc4) * 0.0,0x3e2aaaab);

  }

  return;

}

/* ===== rpman_sniper_anim_set @ 0x004E4F60 ===== */
void rpman_sniper_anim_set(int param_1)



{

  if ((*(uint *)(param_1 + 0xe0) & 0x200) == 0) {

    if ((*(int *)(param_1 + 0x10) != 0x47) && (*(int *)(*(int *)(param_1 + 8) + 0x124) != 0)) {

      ObjectSetAnim(param_1,0x47,0x21,1,

                    *(float *)(DAT_00632ed8 + 0xb38) * *(float *)(param_1 + 0xc4),0x3e2aaaab);

    }

  }

  else if ((*(int *)(param_1 + 0x10) != 0x8e) && (*(int *)(*(int *)(param_1 + 8) + 0x240) != 0)) {

    ObjectSetAnim(param_1,0x8e,0x21,1,*(float *)(DAT_00632ed8 + 0xb38) * *(float *)(param_1 + 0xc4),

                  0x3e2aaaab);

    return;

  }

  return;

}

/* ===== make_grenade_shot__FP6OBJECTf @ 0x004E5000 ===== */
/* PS2 candidate: make_grenade_shot__FP6OBJECTf (conf 0.599) */



void make_grenade_shot__FP6OBJECTf(int param_1,float param_2)



{

  int *piVar1;

  int iVar2;

  float10 fVar3;

  int local_c;

  int local_8;

  float local_4;

  

  piVar1 = *(int **)(param_1 + 0x100);

  iVar2 = *piVar1;

  if (iVar2 == 0) {

    local_c = piVar1[10];

    local_8 = piVar1[0xb];

    local_4 = (float)piVar1[0xc];

    if (param_2 == 0.0) goto LAB_004e50f4;

    fVar3 = (float10)rndfloatrange(-param_2,param_2);

  }

  else {

    local_c = *(int *)(iVar2 + 0xa0);

    local_8 = *(int *)(iVar2 + 0xa4);

    local_4 = *(float *)(iVar2 + 0xa8);

    iVar2 = obj_is_pickup_4a(*piVar1);

    if (iVar2 == 0) {

      iVar2 = obj_is_pickup_53(*piVar1);

      if (iVar2 != 0) goto LAB_004e5064;

      local_4 = *(float *)(*piVar1 + 0x1e8) * *(float *)(*piVar1 + 0xc4) + local_4;

    }

    else {

LAB_004e5064:

      local_4 = local_4 + 2.0;

    }

    if (param_2 == 0.0) goto LAB_004e50f4;

    iVar2 = *piVar1;

    fVar3 = (float10)rndfloatrange(-param_2,param_2);

    fVar3 = fVar3 * (float10)*(float *)(iVar2 + 0x1ec) * (float10)*(float *)(iVar2 + 0xc4) *

            (float10)0.01;

  }

  local_4 = (float)(fVar3 + (float10)local_4);

LAB_004e50f4:

  iVar2 = PROJ_Create2(0x28,*(undefined4 *)(param_1 + 0x18c),param_1,7,0,&local_c);

  *(int *)(iVar2 + 0x274) = param_1;

  return;

}

/* ===== rpman_flying_fire__FP6OBJECT @ 0x004E5120 ===== */
/* PS2 candidate: rpman_flying_fire__FP6OBJECT (conf 0.437) */



void rpman_flying_fire__FP6OBJECT(int param_1)



{

  char *pcVar1;

  int *piVar2;

  undefined1 uVar3;

  float10 fVar4;

  

  piVar2 = *(int **)(param_1 + 0x100);

  if (((float)piVar2[8] < 0.0 == ((float)piVar2[8] == 0.0)) ||

     ((float)piVar2[7] < 0.0 == ((float)piVar2[7] == 0.0))) {

    fVar4 = (float10)FUN_00518b70(param_1,0);

    piVar2[7] = (int)(float)((float10)(float)piVar2[7] - fVar4);

    return;

  }

  if ((float)piVar2[6] < 0.0 == ((float)piVar2[6] == 0.0)) {

    fVar4 = (float10)FUN_00518b70(param_1,0);

    piVar2[6] = (int)(float)((float10)(float)piVar2[6] - fVar4);

  }

  else {

    if (*piVar2 != 0) {

      fVar4 = (float10)dirfcalcp3d__FP3P3DT0(param_1 + 0xa0,*piVar2 + 0xa0);

      fVar4 = (float10)playerobj_turn((float)fVar4,*(undefined4 *)(param_1 + 200));

      if (ABS(fVar4) < (float10)60.0 == (ABS(fVar4) == (float10)60.0)) goto LAB_004e51e4;

    }

    fVar4 = (float10)rndfloatrange(piVar2[0x21],piVar2[0x22]);

    piVar2[6] = (int)(float)fVar4;

    fire_bullet_shot__FP6OBJECTT0ii(param_1,*piVar2,1,1);

    *(char *)(piVar2 + 9) = (char)piVar2[9] + -1;

  }

LAB_004e51e4:

  if ((char)piVar2[9] != '\0') {

    return;

  }

  pcVar1 = (char *)((int)piVar2 + 0x25);

  *pcVar1 = *pcVar1 + -1;

  if (*pcVar1 != '\0') {

    fVar4 = (float10)rndfloatrange(piVar2[0x23],piVar2[0x24]);

    piVar2[7] = (int)(float)fVar4;

    uVar3 = rndintrange(piVar2[0x1f],piVar2[0x20]);

    *(undefined1 *)(piVar2 + 9) = uVar3;

    fVar4 = (float10)rndfloatrange(piVar2[0x21],piVar2[0x22]);

    piVar2[6] = (int)(float)fVar4;

    return;

  }

  fVar4 = (float10)rndfloatrange(piVar2[0x25],piVar2[0x26]);

  piVar2[8] = (int)(float)fVar4;

  return;

}

/* ===== fire_bullet_shot__FP6OBJECTT0ii @ 0x004E5270 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* PS2 candidate: fire_bullet_shot__FP6OBJECTT0ii (conf 0.487) */



void fire_bullet_shot__FP6OBJECTT0ii(int param_1,int param_2,int param_3,int param_4)



{

  uint *puVar1;

  int iVar2;

  int iVar3;

  float10 fVar4;

  float local_80;

  float local_7c;

  float local_78;

  float local_74;

  float local_70;

  float local_6c;

  float local_68;

  float local_64;

  float local_60;

  undefined4 local_5c;

  undefined4 local_58;

  undefined4 local_54;

  undefined1 local_50 [12];

  uint local_44 [4];

  undefined4 local_34;

  undefined4 local_24;

  undefined4 local_14;

  

  iVar2 = *(int *)(param_1 + 0x274);

  iVar3 = *(int *)(param_1 + 0x100);

  if (iVar2 == 0) {

    return;

  }

  if (param_3 != 0) {

    playerobj_eval_refpt(iVar2,2,&local_5c);

    if (param_2 == 0) {

      local_74 = *(float *)(iVar3 + 0x28);

      local_70 = *(float *)(iVar3 + 0x2c);

      local_6c = *(float *)(iVar3 + 0x30);

    }

    else {

      local_74 = *(float *)(param_2 + 0xa0);

      local_70 = *(float *)(param_2 + 0xa4);

      local_6c = *(float *)(param_2 + 0xa8);

      iVar3 = obj_is_pickup_4a(param_2);

      if ((iVar3 != 0) || (iVar3 = obj_is_pickup_53(param_2), iVar3 != 0)) {

        iVar3 = obj_is_pickup_4a_model(param_2);

        if ((iVar3 == 0) && (iVar3 = obj_is_pickup_53_model(param_2), iVar3 == 0)) {

          local_6c = local_6c + 2.0;

        }

        else {

          fVar4 = (float10)rndfloatrange(-*(float *)(param_1 + 0x1e8),0x40000000);

          local_6c = (float)(fVar4 + (float10)*(float *)(param_1 + 0x1e8) + (float10)local_6c);

        }

      }

    }

    iVar3 = ObjIsPlayer(param_2);

    if (iVar3 != 0) {

      fVar4 = (float10)rndfloat(0x43b40000,&local_68,&local_64);

      sine_cos_lookup((float)fVar4);

      local_64 = -local_64;

      fVar4 = (float10)rndfloat(0x43b40000,&local_7c,&local_80);

      sine_cos_lookup((float)fVar4);

      local_68 = local_68 * local_80;

      local_64 = local_80 * local_64;

      local_60 = local_7c;

      fVar4 = (float10)distance3d__FP3P3DT0(&local_5c,&local_74);

      fVar4 = fVar4 * (float10)0.02;

      local_74 = (float)((float10)local_68 * fVar4 + (float10)local_74);

      local_70 = (float)((float10)local_64 * fVar4 + (float10)local_70);

      local_6c = (float)(fVar4 * (float10)local_60 + (float10)local_6c);

    }

    fVar4 = (float10)dirfcalcp3d__FP3P3DT0(&local_5c,&local_74);

    local_78 = (float)fVar4;

    fVar4 = (float10)dirucalcp3d__FP3P3DT0(&local_5c,&local_74);

    local_44[0] = 0;

    GEO_MatBuildXYZ(local_44,(float)-fVar4,0,local_78);

    local_24 = local_58;

    local_34 = local_5c;

    local_44[0] = local_44[0] | 0x10;

    local_14 = local_54;

    if (param_4 == 0) {

      iVar3 = PROJ_Create3(0x19,*(undefined4 *)(param_1 + 0x18c),param_1,0,local_44,0);

    }

    else {

      iVar3 = PROJ_Create3(0x1b,*(undefined4 *)(param_1 + 0x18c),param_1,0,local_44,0);

      sound_play_obj(0x568,param_1);

    }

    *(int *)(iVar3 + 0x274) = param_1;

  }

  if (param_4 != 0) {

    return;

  }

  playerobj_eval_refpt(iVar2,0,local_50);

  if (DAT_00632e70 != DAT_005a8594) {

    if (DAT_00632e6c - _DAT_005a8590 < 0.025) goto LAB_004e559b;

    DAT_005a8594 = DAT_00632e70;

    _DAT_005a8590 = DAT_00632e6c;

  }

  ANM_BinderDestroy(local_50,1,0x4ac,0,0x3f666666,0x3f8ccccd,0x41000000,0x40800000,0x41700000,

                    0x442f0000,0x44098000);

LAB_004e559b:

  iVar2 = *(int *)(iVar2 + 0x274);

  fVar4 = (float10)FUN_00518b70(iVar2,0);

  fVar4 = (float10)*(float *)(iVar2 + 0xf0) - fVar4;

  *(float *)(iVar2 + 0xf0) = (float)fVar4;

  if (fVar4 < (float10)0.0) {

    fVar4 = (float10)rndfloatrange(0x3dcccccd,0x3e4ccccd);

    *(float *)(iVar2 + 0xf0) = (float)fVar4;

    if (*(float *)(iVar2 + 0xec) < 0.0 != (*(float *)(iVar2 + 0xec) == 0.0)) {

      *(uint *)(iVar2 + 0xd8) = *(uint *)(iVar2 + 0xd8) & 0xbfffffff;

      *(undefined4 *)(iVar2 + 0xec) = 0x3d4ccccd;

      puVar1 = (uint *)(*(int *)(iVar2 + 0x274) + 0xd8);

      *puVar1 = *puVar1 & 0xbfffffff;

      *(undefined4 *)(*(int *)(iVar2 + 0x274) + 0xec) = 0x3d4ccccd;

    }

  }

  return;

}

/* ===== fire_sniper_shot__FP6OBJECTT0 @ 0x004E5640 ===== */
/* PS2 candidate: fire_sniper_shot__FP6OBJECTT0 (conf 0.389) */



void fire_sniper_shot__FP6OBJECTT0(int param_1,int param_2,int param_3,float param_4)



{

  char *pcVar1;

  float fVar2;

  float fVar3;

  int *piVar4;

  int iVar5;

  int *piVar6;

  undefined4 *puVar7;

  undefined1 uVar8;

  int iVar9;

  int iVar10;

  int iVar11;

  bool bVar12;

  float10 fVar13;

  float10 fVar14;

  float local_68;

  float local_64;

  float local_60;

  undefined4 local_5c;

  undefined4 local_58;

  undefined4 local_54;

  undefined1 local_50 [12];

  uint local_44 [4];

  undefined4 local_34;

  undefined4 local_24;

  undefined4 local_14;

  

  piVar4 = *(int **)(param_1 + 0x100);

  bVar12 = false;

  if (*piVar4 != 0) {

    iVar9 = *piVar4 + 0xa0;

    if (*(int *)(param_1 + 0xe8) == 4) {

      fVar13 = (float10)dirfcalcp3d__FP3P3DT0(param_1 + 0xa0,iVar9);

      fVar2 = (float)fVar13;

      fVar13 = (float10)playerobj_turn(fVar2,piVar4[0x56]);

      fVar3 = (float)fVar13;

      fVar13 = (float10)playerobj_turn(fVar2,*(undefined4 *)(param_1 + 200));

      if (ABS(fVar13) != (float10)0.0) {

        *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) | 0x1000000;

        *(float *)(param_1 + 0x158) = fVar2;

        uVar8 = __ftol();

        *(undefined1 *)(param_1 + 0x208) = uVar8;

      }

      if ((fVar3 < *(float *)(&DAT_005a84e8 + piVar4[0x55] * 4)) ||

         (fVar3 < *(float *)(&DAT_005a8550 + piVar4[0x55] * 4) ==

          (fVar3 == *(float *)(&DAT_005a8550 + piVar4[0x55] * 4)))) {

        bVar12 = true;

      }

      else {

        bVar12 = false;

      }

    }

    else {

      fVar13 = (float10)dirfcalcp3d__FP3P3DT0(param_1 + 0xa0,iVar9);

      fVar14 = (float10)playerobj_turn((float)fVar13,*(undefined4 *)(param_1 + 200));

      if (ABS(fVar14) != (float10)0.0) {

        *(float *)(param_1 + 0x158) = (float)fVar13;

        *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) | 0x1000000;

        uVar8 = __ftol();

        *(undefined1 *)(param_1 + 0x208) = uVar8;

      }

    }

  }

  if (((float)piVar4[7] < 0.0 == ((float)piVar4[7] == 0.0)) || (bVar12)) {

    fVar13 = (float10)FUN_00518b70(param_1,0);

    piVar4[7] = (int)(float)((float10)(float)piVar4[7] - fVar13);

    if (!bVar12) {

      return;

    }

  }

  else {

    if ((float)piVar4[6] < 0.0 != ((float)piVar4[6] == 0.0)) {

      if ((*(byte *)(param_1 + 0x30) & 2) == 0) {

        return;

      }

      if ((*(int *)(param_1 + 0x10) != param_2) &&

         (*(int *)(*(int *)(param_1 + 8) + 8 + param_2 * 4) != 0)) {

        ObjectSetAnim(param_1,param_2,0x20,0,*(float *)(param_1 + 0xc4) * 0.0,0x3e2aaaab);

      }

      fVar13 = (float10)rndfloatrange(piVar4[0x21],piVar4[0x22]);

      piVar4[6] = (int)(float)fVar13;

      if (param_4 == 0.0) {

        return;

      }

      iVar9 = *(int *)(param_1 + 0x274);

      iVar11 = *piVar4;

      iVar5 = *(int *)(param_1 + 0x100);

      playerobj_eval_refpt(iVar9,2,&local_5c);

      if (iVar11 == 0) {

        local_68 = *(float *)(iVar5 + 0x28);

        local_64 = *(float *)(iVar5 + 0x2c);

        local_60 = *(float *)(iVar5 + 0x30);

      }

      else {

        local_68 = *(float *)(iVar11 + 0xa0);

        local_64 = *(float *)(iVar11 + 0xa4);

        local_60 = *(float *)(iVar11 + 0xa8);

        iVar10 = obj_is_pickup_4a(iVar11);

        if ((iVar10 == 0) && (iVar10 = obj_is_pickup_53(iVar11), iVar10 == 0)) {

          iVar10 = ObjIsPlayer(iVar11);

          if (iVar10 != 0) {

            local_60 = *(float *)(iVar11 + 0x1e8) * *(float *)(iVar11 + 0xc4) + local_60;

          }

        }

        else {

          iVar10 = obj_is_pickup_4a_model(iVar11);

          if ((iVar10 == 0) && (iVar10 = obj_is_pickup_53_model(iVar11), iVar10 == 0)) {

            local_60 = local_60 + 2.0;

          }

          else {

            fVar13 = (float10)rndfloatrange(-*(float *)(param_1 + 0x1e8),0x40000000);

            local_60 = (float)(fVar13 + (float10)local_60 + (float10)*(float *)(param_1 + 0x1e8));

          }

        }

      }

      if (*(float *)(iVar5 + 0x34) <

          *(float *)(DAT_00632ed8 + 0xa84) * *(float *)(DAT_00632ed8 + 0xa84)) {

        fVar2 = *(float *)(DAT_00632ed8 + 0xa7c) * *(float *)(DAT_00632ed8 + 0xa7c);

        if (*(float *)(iVar5 + 0x34) < fVar2 == (*(float *)(iVar5 + 0x34) == fVar2)) {

          param_4 = (SQRT(*(float *)(iVar5 + 0x34)) - *(float *)(DAT_00632ed8 + 0xa7c)) /

                    (*(float *)(DAT_00632ed8 + 0xa84) - *(float *)(DAT_00632ed8 + 0xa7c));

        }

        else {

          param_4 = 0.0;

        }

      }

      else {

        param_4 = 1.0;

      }

      iVar11 = ObjIsPlayer(iVar11);

      if (iVar11 != 0) {

        fVar2 = *(float *)(DAT_00632ed8 + 0xbfc) * param_4;

        fVar13 = (float10)rndfloatrange(-fVar2,fVar2);

        local_68 = (float)(fVar13 + (float10)local_68);

        fVar2 = *(float *)(DAT_00632ed8 + 0xbfc) * param_4;

        fVar13 = (float10)rndfloatrange(-fVar2,fVar2);

        local_64 = (float)(fVar13 + (float10)local_64);

        param_4 = *(float *)(DAT_00632ed8 + 0xc80) * param_4;

        fVar13 = (float10)rndfloatrange(-param_4,param_4);

        local_60 = (float)(fVar13 + (float10)local_60);

      }

      dirfcalcp3d__FP3P3DT0(&local_5c,&local_68);

      playerobj_eval_refpt(iVar9,2,&local_5c);

      fVar13 = (float10)dirfcalcp3d__FP3P3DT0(&local_5c,&local_68);

      fVar14 = (float10)dirucalcp3d__FP3P3DT0(&local_5c,&local_68);

      local_44[0] = 0;

      GEO_MatBuildXYZ(local_44,(float)-fVar14,0,(float)fVar13);

      local_14 = local_54;

      local_24 = local_58;

      local_44[0] = local_44[0] | 0x10;

      local_34 = local_5c;

      if ((*(uint *)(param_1 + 0xe0) & 0x200) != 0) {

        sound_play_obj(0x563,param_1);

        iVar9 = PROJ_Create3(0x1c,*(undefined4 *)(param_1 + 0x18c),param_1,0,local_44,0);

        *(int *)(iVar9 + 0x274) = param_1;

        return;

      }

      sound_play_obj(0x569,param_1);

      iVar11 = PROJ_Create3(0x1a,*(undefined4 *)(param_1 + 0x18c),param_1,0,local_44,0);

      playerobj_eval_refpt(iVar9,0,local_50);

      ANM_BinderDestroy(local_50,1,0x4ac,0,0x3f666666,0x3f8ccccd,0x41000000,0x40800000,0x41700000,

                        0x442f0000,0x44098000);

      iVar9 = *(int *)(iVar9 + 0x274);

      *(uint *)(iVar9 + 0xd8) = *(uint *)(iVar9 + 0xd8) & 0xbfffffff;

      *(undefined4 *)(iVar9 + 0xec) = 0x3d4ccccd;

      *(uint *)(*(int *)(iVar9 + 0x274) + 0xd8) =

           *(uint *)(*(int *)(iVar9 + 0x274) + 0xd8) & 0xbfffffff;

      *(undefined4 *)(*(int *)(iVar9 + 0x274) + 0xec) = 0x3d4ccccd;

      *(int *)(iVar11 + 0x274) = param_1;

      return;

    }

    fVar13 = (float10)FUN_00518b70(param_1,0);

    piVar4[6] = (int)(float)((float10)(float)piVar4[6] - fVar13);

    if ((*(int *)(param_1 + 0x10) == param_2) && ((*(byte *)(param_1 + 0x30) & 2) != 0)) {

      if (param_4 == 0.0) {

        fire_bullet_shot__FP6OBJECTT0ii(param_1,*piVar4,1,1);

      }

      if ((*(int *)(param_1 + 0x10) != param_3) &&

         (*(int *)(*(int *)(param_1 + 8) + 8 + param_3 * 4) != 0)) {

        ObjectSetAnim(param_1,param_3,0x21,0,*(float *)(param_1 + 0xc4) * 0.0,0x3e2aaaab);

      }

      *(char *)(piVar4 + 9) = (char)piVar4[9] + -1;

    }

    if ((char)piVar4[9] != '\0') {

      return;

    }

    pcVar1 = (char *)((int)piVar4 + 0x25);

    *pcVar1 = *pcVar1 + -1;

    if ((*pcVar1 != '\0') && (*piVar4 != 0)) {

      if ((*(int *)(param_1 + 0x10) != param_3) &&

         (*(int *)(*(int *)(param_1 + 8) + 8 + param_3 * 4) != 0)) {

        ObjectSetAnim(param_1,param_3,0x21,0,*(float *)(param_1 + 0xc4) * 0.0,0x3e2aaaab);

      }

      fVar13 = (float10)rndfloatrange(piVar4[0x23],piVar4[0x24]);

      piVar4[7] = (int)(float)fVar13;

      uVar8 = rndintrange(piVar4[0x1f],piVar4[0x20]);

      *(undefined1 *)(piVar4 + 9) = uVar8;

      fVar13 = (float10)rndfloatrange(piVar4[0x21],piVar4[0x22]);

      piVar4[6] = (int)(float)fVar13;

      return;

    }

    fVar13 = (float10)rndfloatrange(piVar4[0x25],piVar4[0x26]);

    piVar4[8] = (int)(float)fVar13;

    *(undefined1 *)((int)piVar4 + 0x25) = 0;

  }

  iVar9 = *(int *)(param_1 + 0xe8);

  if (iVar9 == 1) {

    *(undefined4 *)(param_1 + 0xe4) = 0x6a;

    return;

  }

  if (iVar9 != 4) {

    if (iVar9 == 0x66) {

      if ((*(uint *)(param_1 + 0xe0) & 0x80000) != 0) {

        piVar6 = *(int **)(param_1 + 0x100);

        if (piVar6[0x7c] != 0) {

          *piVar6 = 0;

          param_4 = 640000.0;

          for (puVar7 = DAT_00632d80; puVar7 != (undefined4 *)0x0; puVar7 = (undefined4 *)*puVar7) {

            iVar9 = puVar7[3];

            if (*(int *)(iVar9 + 4) == 0x325) {

              fVar13 = (float10)distancesq2d__FP3P3DT0(iVar9 + 0xa0,param_1 + 0xa0);

              if ((fVar13 < (float10)param_4) &&

                 (iVar11 = rpman_check_los__FP6OBJECTT0(param_1,iVar9), iVar11 != 0)) {

                *piVar6 = iVar9;

                param_4 = (float)fVar13;

              }

            }

          }

        }

        if (*piVar4 != 0) {

          *(undefined4 *)(param_1 + 0xe4) = 0xd7;

          return;

        }

        *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xfff7ffff;

        *(undefined4 *)(param_1 + 0xe4) = 0xda;

        return;

      }

      iVar9 = obj_is_pickup_4a(*piVar4);

      if ((iVar9 != 0) || (iVar9 = obj_is_pickup_53(*piVar4), iVar9 != 0)) {

        iVar9 = crt_rand_scaled(100);

        if ((iVar9 < piVar4[0x70]) &&

           ((iVar9 = obj_is_pickup_4a_model(*piVar4), iVar9 == 0 &&

            (iVar9 = obj_is_pickup_53_model(*piVar4), iVar9 == 0)))) {

          *(undefined4 *)(param_1 + 0xe4) = 0xce;

          return;

        }

        ai_anim_play(param_1,param_3,1,0,0,0);

        *(undefined4 *)(param_1 + 0xe4) = 0xd0;

        return;

      }

      if ((piVar4[0x6e] & 8U) != 0) {

        piVar4[0x6e] = piVar4[0x6e] & 0xfffffff7;

        rpman_sniper_anim_set(param_1);

        *(undefined4 *)(param_1 + 0xe4) = 0xe2;

        return;

      }

    }

    else if (iVar9 == 0x67) {

      *(undefined4 *)(param_1 + 0xe4) = 0xea;

      return;

    }

    *(undefined4 *)(param_1 + 0xe4) = 0xc;

    return;

  }

  *(undefined4 *)(param_1 + 0xe4) = 0xad;

  return;

}

/* ===== rpman_rapid_fire__FP6OBJECTiii @ 0x004E5F70 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* PS2 candidate: rpman_rapid_fire__FP6OBJECTiii (conf 0.463) */



void rpman_rapid_fire__FP6OBJECTiii(int param_1,int param_2,int param_3,float param_4)



{

  float fVar1;

  int *piVar2;

  int *piVar3;

  undefined4 *puVar4;

  bool bVar5;

  undefined1 uVar6;

  char cVar7;

  int iVar8;

  int iVar9;

  float10 fVar10;

  float10 fVar11;

  undefined4 uVar12;

  float fVar13;

  undefined4 local_18;

  undefined4 local_14;

  float local_10;

  undefined4 local_c;

  undefined4 local_8;

  float local_4;

  

  piVar2 = *(int **)(param_1 + 0x100);

  bVar5 = false;

  if (*piVar2 != 0) {

    iVar8 = *piVar2 + 0xa0;

    if (*(int *)(param_1 + 0xe8) == 4) {

      fVar10 = (float10)dirfcalcp3d__FP3P3DT0(param_1 + 0xa0,iVar8);

      fVar13 = (float)fVar10;

      fVar10 = (float10)playerobj_turn(fVar13,piVar2[0x56]);

      fVar1 = (float)fVar10;

      fVar10 = (float10)playerobj_turn(fVar13,*(undefined4 *)(param_1 + 200));

      if (ABS(fVar10) != (float10)0.0) {

        *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) | 0x1000000;

        *(float *)(param_1 + 0x158) = fVar13;

        uVar6 = __ftol();

        *(undefined1 *)(param_1 + 0x208) = uVar6;

      }

      if ((fVar1 < *(float *)(&DAT_005a84e8 + piVar2[0x55] * 4)) ||

         (fVar1 < *(float *)(&DAT_005a8550 + piVar2[0x55] * 4) ==

          (fVar1 == *(float *)(&DAT_005a8550 + piVar2[0x55] * 4)))) {

        bVar5 = true;

      }

      else {

        bVar5 = false;

      }

    }

    else {

      fVar10 = (float10)dirfcalcp3d__FP3P3DT0(param_1 + 0xa0,iVar8);

      fVar11 = (float10)playerobj_turn((float)fVar10,*(undefined4 *)(param_1 + 200));

      if (ABS(fVar11) != (float10)0.0) {

        *(float *)(param_1 + 0x158) = (float)fVar10;

        *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) | 0x1000000;

        uVar6 = __ftol();

        *(undefined1 *)(param_1 + 0x208) = uVar6;

      }

    }

  }

  if (((float)piVar2[7] < 0.0 == ((float)piVar2[7] == 0.0)) || (bVar5)) {

    fVar10 = (float10)FUN_00518b70(param_1,0);

    piVar2[7] = (int)(float)((float10)(float)piVar2[7] - fVar10);

    if (!bVar5) {

      return;

    }

  }

  else {

    if (piVar2[0x8d] == 0) {

      iVar8 = sound_get_free_sequence__Fv();

      piVar2[0x8d] = iVar8;

    }

    if ((*(int *)(param_1 + 0x10) != param_2) &&

       (*(int *)(*(int *)(param_1 + 8) + 8 + param_2 * 4) != 0)) {

      ObjectSetAnim(param_1,param_2,0x21,0,*(float *)(param_1 + 0xc4) * 0.0,0x3e2aaaab);

    }

    if ((float)piVar2[6] < 0.0 == ((float)piVar2[6] == 0.0)) {

      fVar10 = (float10)FUN_00518b70(param_1,0);

      piVar2[6] = (int)(float)((float10)(float)piVar2[6] - fVar10);

      fire_bullet_shot__FP6OBJECTT0ii(param_1,*piVar2,0,0);

    }

    else {

      fire_bullet_shot__FP6OBJECTT0ii(param_1,*piVar2,1);

      fVar10 = (float10)rndfloatrange(piVar2[0x21],piVar2[0x22]);

      piVar2[6] = (int)(float)fVar10;

      *(char *)(piVar2 + 9) = (char)piVar2[9] + -1;

    }

    if ((char)piVar2[9] != '\0') {

      return;

    }

    sound_stop_sequence(piVar2 + 0x8d);

    cVar7 = *(char *)((int)piVar2 + 0x25) + -1;

    *(char *)((int)piVar2 + 0x25) = cVar7;

    if ((cVar7 != '\0') && (*piVar2 != 0)) {

      if ((*(int *)(param_1 + 0x10) != param_3) &&

         (*(int *)(*(int *)(param_1 + 8) + 8 + param_3 * 4) != 0)) {

        ObjectSetAnim(param_1,param_3,param_4 != 0.0 | 0x20,0,*(float *)(param_1 + 0xc4) * 0.0,

                      0x3e2aaaab);

      }

      fVar10 = (float10)rndfloatrange(piVar2[0x23],piVar2[0x24]);

      piVar2[7] = (int)(float)fVar10;

      uVar6 = rndintrange(piVar2[0x1f],piVar2[0x20]);

      *(undefined1 *)(piVar2 + 9) = uVar6;

      fVar10 = (float10)rndfloatrange(piVar2[0x21],piVar2[0x22]);

      piVar2[6] = (int)(float)fVar10;

      return;

    }

    fVar10 = (float10)rndfloatrange(piVar2[0x25],piVar2[0x26]);

    piVar2[8] = (int)(float)fVar10;

    *(undefined1 *)((int)piVar2 + 0x25) = 0;

  }

  sound_stop_sequence(piVar2 + 0x8d);

  iVar8 = *(int *)(param_1 + 0xe8);

  if (iVar8 == 1) {

    *(undefined4 *)(param_1 + 0xe4) = 0x6a;

    return;

  }

  if (iVar8 == 4) {

    *(undefined4 *)(param_1 + 0xe4) = 0xad;

    return;

  }

  if (iVar8 != 0x66) {

    if (iVar8 == 0x67) {

      *(undefined4 *)(param_1 + 0xe4) = 0xea;

      return;

    }

LAB_004e6651:

    *(undefined4 *)(param_1 + 0xe4) = 0xc;

    return;

  }

  if ((*(uint *)(param_1 + 0xe0) & 0x80000) != 0) {

    piVar3 = *(int **)(param_1 + 0x100);

    if (piVar3[0x7c] != 0) {

      *piVar3 = 0;

      param_4 = 640000.0;

      for (puVar4 = DAT_00632d80; puVar4 != (undefined4 *)0x0; puVar4 = (undefined4 *)*puVar4) {

        iVar8 = puVar4[3];

        if (*(int *)(iVar8 + 4) == 0x325) {

          fVar10 = (float10)distancesq2d__FP3P3DT0

                                      ((undefined4 *)(iVar8 + 0xa0),(undefined4 *)(param_1 + 0xa0));

          if (fVar10 < (float10)param_4) {

            iVar9 = obj_is_pickup_4a(iVar8);

            if ((iVar9 == 0) && (iVar9 = obj_is_pickup_53(iVar8), iVar9 == 0)) {

              local_c = *(undefined4 *)(param_1 + 0xa0);

              local_8 = *(undefined4 *)(param_1 + 0xa4);

              local_4 = *(float *)(param_1 + 0x1e8) * *(float *)(param_1 + 0xc4) +

                        *(float *)(param_1 + 0xa8);

              local_18 = *(undefined4 *)(iVar8 + 0xa0);

              local_10 = *(float *)(iVar8 + 0x1e8) * *(float *)(iVar8 + 0xc4) +

                         *(float *)(iVar8 + 0xa8);

              local_14 = *(undefined4 *)(iVar8 + 0xa4);

              if (*(int *)(param_1 + 0x210) == 0) {

                uVar12 = 7;

              }

              else {

                _DAT_00561494 = *(undefined4 *)(*(int *)(param_1 + 0x210) + 4);

                uVar12 = 8;

              }

              iVar9 = ai_class_filter(&local_c,&local_18,uVar12,&DAT_00561478,0);

              if (iVar9 == 0) goto LAB_004e647b;

            }

            *piVar3 = iVar8;

            param_4 = (float)fVar10;

          }

        }

LAB_004e647b:

      }

    }

    if (*piVar2 == 0) {

      *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xfff7ffff;

      *(undefined4 *)(param_1 + 0xe4) = 0xda;

      return;

    }

    *(undefined4 *)(param_1 + 0xe4) = 0xd7;

    return;

  }

  iVar8 = obj_is_pickup_4a(*piVar2);

  if ((iVar8 == 0) && (iVar8 = obj_is_pickup_53(*piVar2), iVar8 == 0)) {

    if ((piVar2[0x6e] & 8U) == 0) goto LAB_004e6651;

    piVar2[0x6e] = piVar2[0x6e] & 0xfffffff7;

    if ((*(uint *)(param_1 + 0xe0) & 0x200) == 0) {

      if ((*(int *)(param_1 + 0x10) == 0x47) || (*(int *)(*(int *)(param_1 + 8) + 0x124) == 0))

      goto LAB_004e6589;

      fVar13 = *(float *)(DAT_00632ed8 + 0xb38) * *(float *)(param_1 + 0xc4);

      uVar12 = 0x47;

    }

    else {

      if ((*(int *)(param_1 + 0x10) == 0x8e) || (*(int *)(*(int *)(param_1 + 8) + 0x240) == 0))

      goto LAB_004e6589;

      fVar13 = *(float *)(DAT_00632ed8 + 0xb38) * *(float *)(param_1 + 0xc4);

      uVar12 = 0x8e;

    }

    ObjectSetAnim(param_1,uVar12,0x21,1,fVar13,0x3e2aaaab);

LAB_004e6589:

    *(undefined4 *)(param_1 + 0xe4) = 0xe2;

    return;

  }

  iVar8 = crt_rand_scaled(100);

  if (iVar8 < piVar2[0x70]) {

    iVar8 = obj_is_pickup_4a_model(*piVar2);

    if ((iVar8 == 0) && (iVar8 = obj_is_pickup_53_model(*piVar2), iVar8 == 0)) {

      *(undefined4 *)(param_1 + 0xe4) = 0xce;

      return;

    }

    if (*(int *)(param_1 + 0x10) == param_3) goto LAB_004e6616;

    iVar8 = *(int *)(*(int *)(param_1 + 8) + 8 + param_3 * 4);

  }

  else {

    if (*(int *)(param_1 + 0x10) == param_3) goto LAB_004e6616;

    iVar8 = *(int *)(*(int *)(param_1 + 8) + 8 + param_3 * 4);

  }

  if (iVar8 != 0) {

    ObjectSetAnim(param_1,param_3,0x21,0,*(float *)(param_1 + 0xc4) * 0.0,0x3e2aaaab);

  }

LAB_004e6616:

  *(undefined4 *)(param_1 + 0xe4) = 0xd0;

  return;

}

/* ===== FUN_004e6670 @ 0x004E6670 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_004e6670(int param_1)



{

  float fVar1;

  int *piVar2;

  undefined4 *puVar3;

  int iVar4;

  int iVar5;

  uint uVar6;

  float10 fVar7;

  undefined4 uVar8;

  undefined4 local_18;

  undefined4 local_14;

  float local_10;

  undefined4 local_c;

  undefined4 local_8;

  float local_4;

  

  piVar2 = *(int **)(param_1 + 0x100);

  if (0.0 < (float)piVar2[0x3d]) {

    return;

  }

  if (*piVar2 == 0) {

    return;

  }

  if (*(float *)(DAT_00632ed8 + 4000) * *(float *)(DAT_00632ed8 + 4000) <= (float)piVar2[0xd]) {

    return;

  }

  iVar5 = *piVar2;

  if (iVar5 == 0) {

LAB_004e6792:

    uVar6 = *(uint *)(param_1 + 0xe0) | 2;

  }

  else {

    iVar4 = obj_is_pickup_4a(iVar5);

    if ((iVar4 == 0) && (iVar4 = obj_is_pickup_53(iVar5), iVar4 == 0)) {

      local_c = *(undefined4 *)(param_1 + 0xa0);

      local_8 = *(undefined4 *)(param_1 + 0xa4);

      local_4 = *(float *)(param_1 + 0x1e8) * *(float *)(param_1 + 0xc4) +

                *(float *)(param_1 + 0xa8);

      local_18 = *(undefined4 *)(iVar5 + 0xa0);

      local_14 = *(undefined4 *)(iVar5 + 0xa4);

      local_10 = *(float *)(iVar5 + 0x1e8) * *(float *)(iVar5 + 0xc4) + *(float *)(iVar5 + 0xa8);

      if (*(int *)(param_1 + 0x210) == 0) {

        uVar8 = 7;

      }

      else {

        _DAT_00561494 = *(undefined4 *)(*(int *)(param_1 + 0x210) + 4);

        uVar8 = 8;

      }

      iVar5 = ai_class_filter(&local_c,&local_18,uVar8,&DAT_00561478,0);

      if (iVar5 == 0) goto LAB_004e6792;

    }

    uVar6 = *(uint *)(param_1 + 0xe0) & 0xfffffffd;

  }

  *(uint *)(param_1 + 0xe0) = uVar6;

  if ((uVar6 & 2) == 0) {

    iVar5 = 0;

    for (puVar3 = DAT_00632d6c; puVar3 != (undefined4 *)0x0; puVar3 = (undefined4 *)*puVar3) {

      iVar4 = puVar3[3];

      if (((*(int *)(iVar4 + 4) == 0xd7) && (*(int *)(iVar4 + 0x210) == 0)) &&

         (fVar1 = *(float *)(DAT_00632ed8 + 0xc40),

         fVar7 = (float10)distancesq2d__FP3P3DT0(iVar4 + 0xa0,param_1 + 0xa0),

         fVar7 < (float10)fVar1 * (float10)fVar1)) {

        iVar5 = iVar5 + 1;

      }

    }

    if ((float)iVar5 < *(float *)(DAT_00632ed8 + 0xc30)) {

      if ((*(int *)(param_1 + 0x10) != 0x71) && (*(int *)(*(int *)(param_1 + 8) + 0x1cc) != 0)) {

        ObjectSetAnim(param_1,0x71,0x20,0,*(float *)(param_1 + 0xc4) * 0.0,0x3e2aaaab);

      }

      *(undefined4 *)(param_1 + 0xe4) = 0x7c;

    }

  }

  return;

}

/* ===== obj_proximity_update @ 0x004E6880 ===== */
void obj_proximity_update(int param_1)



{

  int iVar1;

  float fVar2;

  float10 fVar3;

  float10 fVar4;

  

  iVar1 = *(int *)(param_1 + 0x100);

  if (*(int *)(param_1 + 0x10) == 0xa6) {

    if ((*(byte *)(param_1 + 0x30) & 2) == 0) {

      fVar3 = (float10)FUN_0053c640(*(undefined4 *)(*(int *)(*(int *)(param_1 + 8) + 0x2a0) + 0x28),

                                    0x96);

      fVar3 = (float10)1.0 - (float10)*(float *)(param_1 + 0x14) / fVar3;

      if (fVar3 < (float10)0.0) {

        fVar3 = (float10)0.0;

      }

      *(float *)(iVar1 + 0x188) = (float)(fVar3 * (float10)*(float *)(iVar1 + 0x19c));

      return;

    }

    if (*(int *)(*(int *)(param_1 + 8) + 0x270) == 0) {

      return;

    }

    ObjectSetAnim(param_1,0x9a,0x21,0,*(float *)(param_1 + 0xc4) * 0.0,0x3e2aaaab);

    return;

  }

  fVar3 = (float10)distancesq2d__FP3P3DT0(param_1 + 0xa0,*(int *)(iVar1 + 400) + 0xa0);

  fVar4 = (float10)distancesq2d__FP3P3DT0(DAT_00632a88 + 0xa0,*(int *)(iVar1 + 400) + 0xa0);

  if (*(int *)(iVar1 + 0x184) == 0) {

    if ((float)fVar3 <=

        (float)fVar4 - *(float *)(DAT_00632ed8 + 0xfc8) * *(float *)(DAT_00632ed8 + 0xfc8)) {

LAB_004e6a31:

      fVar2 = SQRT((float)fVar3) - SQRT((float)fVar4);

      if (0.0 < fVar2) {

        if (fVar2 <= *(float *)(DAT_00632ed8 + 0xfcc)) {

          *(undefined4 *)(iVar1 + 0x18c) = *(undefined4 *)(DAT_00632ed8 + 0xfd0);

        }

        else {

          *(undefined4 *)(iVar1 + 0x18c) = *(undefined4 *)(DAT_00632ed8 + 0xfd4);

        }

      }

      goto LAB_004e6af2;

    }

  }

  else if (*(int *)(iVar1 + 0x184) < 1) goto LAB_004e6a31;

  if (*(float *)(iVar1 + 0x1a0) < 0.0 == (*(float *)(iVar1 + 0x1a0) == 0.0)) {

    fVar3 = (float10)FUN_00518b70(param_1,0);

    fVar3 = (float10)*(float *)(iVar1 + 0x1a0) - fVar3;

    *(float *)(iVar1 + 0x1a0) = (float)fVar3;

    if (fVar3 < (float10)0.0 != (fVar3 == (float10)0.0)) {

      fVar3 = (float10)rndfloatrange(*(undefined4 *)(DAT_00632ed8 + 0x3f4),

                                     *(undefined4 *)(DAT_00632ed8 + 0xfc4));

      *(float *)(iVar1 + 0x18c) = (float)fVar3;

      fVar3 = (float10)rndfloatrange(*(undefined4 *)(DAT_00632ed8 + 0x294),

                                     *(undefined4 *)(DAT_00632ed8 + 0x298));

      *(float *)(iVar1 + 0x1a4) = (float)fVar3;

    }

  }

  else {

    fVar3 = (float10)FUN_00518b70(param_1,0);

    fVar3 = (float10)*(float *)(iVar1 + 0x1a4) - fVar3;

    *(float *)(iVar1 + 0x1a4) = (float)fVar3;

    if (fVar3 < (float10)0.0 != (fVar3 == (float10)0.0)) {

      fVar3 = (float10)rndfloatrange(*(undefined4 *)(DAT_00632ed8 + 0x29c),

                                     *(undefined4 *)(DAT_00632ed8 + 0x2a0));

      *(float *)(iVar1 + 0x18c) = (float)fVar3;

      fVar3 = (float10)rndfloatrange(*(undefined4 *)(DAT_00632ed8 + 0x28c),

                                     *(undefined4 *)(DAT_00632ed8 + 0x290));

      *(float *)(iVar1 + 0x1a0) = (float)fVar3;

    }

  }

LAB_004e6af2:

  if (*(float *)(iVar1 + 0x188) <= *(float *)(iVar1 + 0x18c)) {

    if (*(float *)(iVar1 + 0x188) < *(float *)(iVar1 + 0x18c)) {

      fVar3 = (float10)FUN_00518b70(param_1,0);

      fVar3 = fVar3 * (float10)*(float *)(DAT_00632ed8 + 0xfd8) + (float10)*(float *)(iVar1 + 0x188)

      ;

      *(float *)(iVar1 + 0x188) = (float)fVar3;

      if ((float10)*(float *)(iVar1 + 0x18c) < fVar3) {

        *(undefined4 *)(iVar1 + 0x188) = *(undefined4 *)(iVar1 + 0x18c);

      }

    }

  }

  else {

    fVar3 = (float10)FUN_00518b70(param_1,0);

    fVar3 = (float10)*(float *)(iVar1 + 0x188) - fVar3 * (float10)*(float *)(DAT_00632ed8 + 0xfd8);

    *(float *)(iVar1 + 0x188) = (float)fVar3;

    if (fVar3 < (float10)*(float *)(iVar1 + 0x18c)) {

      *(undefined4 *)(iVar1 + 0x188) = *(undefined4 *)(iVar1 + 0x18c);

      return;

    }

  }

  return;

}

/* ===== rpboat_logic__FP6OBJECT @ 0x004E6BA0 ===== */
/* PS2 candidate: rpboat_logic__FP6OBJECT (conf 0.534) */



void rpboat_logic__FP6OBJECT(float param_1,float param_2)



{

  float *pfVar1;

  float fVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  float10 fVar6;

  float10 fVar7;

  float10 fVar8;

  undefined4 uVar9;

  undefined1 local_5c [12];

  undefined1 local_50 [16];

  float local_40;

  float local_30;

  undefined4 local_2c;

  undefined4 local_28;

  

  iVar5 = (int)param_1;

  iVar3 = *(int *)((int)param_1 + 0x100);

  uVar9 = *(undefined4 *)(iVar3 + 0x13c);

  fVar6 = (float10)FUN_00518b70(param_1,0);

  fVar6 = fVar6 * (float10)param_2 + (float10)*(float *)(iVar3 + 0x13c);

  pfVar1 = (float *)((int)param_1 + 0xa0);

  *(float *)(iVar3 + 0x13c) = (float)fVar6;

  ai_move_ground_common(*(undefined4 *)(iVar3 + 0x134),(float)fVar6,uVar9,pfVar1);

  ground_height_at(pfVar1,local_50);

  if (*(int *)(*(int *)(*(int *)(iVar3 + 0x134) + 0x100) + 0x48) == 0) {

    if (local_40 <= 0.0) {

      *(undefined4 *)((int)param_1 + 0xa8) = 0;

    }

    else {

      *(float *)((int)param_1 + 0xa8) = local_40;

    }

  }

  else if (*(float *)((int)param_1 + 0xa8) < local_40) {

    *(float *)((int)param_1 + 0xa8) = local_40;

  }

  param_1 = 0.0;

  if (0.0 < param_2) {

    if ((*(float *)(iVar5 + 0xb8) != *pfVar1) ||

       (*(float *)(iVar5 + 0xbc) != *(float *)(iVar5 + 0xa4))) {

      fVar6 = (float10)dirfcalcp3d__FP3P3DT0(iVar5 + 0xb8,pfVar1);

      fVar2 = (float)fVar6;

      fVar6 = (float10)playerobj_turn(fVar2,*(undefined4 *)(iVar5 + 0xf4));

      param_1 = (float)fVar6;

      *(float *)(iVar5 + 200) = fVar2;

      *(float *)(iVar5 + 0xf4) = fVar2;

    }

    fVar6 = (float10)FUN_00518b70(iVar5,0);

    fVar6 = (float10)*(float *)(iVar3 + 0x23c) - fVar6;

    *(float *)(iVar3 + 0x23c) = (float)fVar6;

    if (fVar6 < (float10)0.0) {

      iVar4 = crt_rand_scaled(100);

      if (iVar4 < 0x32) {

        uVar9 = 0x61d;

      }

      else {

        uVar9 = 0x61e;

      }

      sound_play_obj(uVar9,iVar5);

      fVar6 = (float10)rndfloatrange(0x41200000,0x41a00000);

      *(float *)(iVar3 + 0x23c) = (float)fVar6;

    }

  }

  fVar6 = (float10)FUN_00518b70(iVar5,0);

  *(undefined4 *)(*(int *)(iVar5 + 0x104) + 0x28) = *(undefined4 *)(DAT_00632ed8 + 0xd50);

  if (fVar6 <= (float10)0.0001) {

    *(undefined4 *)(iVar5 + 0x128) = 0;

    *(undefined4 *)(iVar5 + 300) = 0;

    *(undefined4 *)(iVar5 + 0x130) = 0;

    *(undefined4 *)(*(int *)(iVar5 + 0x104) + 0x24) = 0;

  }

  else {

    fVar6 = (float10)1.0 / fVar6;

    fVar7 = ((float10)*pfVar1 - (float10)*(float *)(iVar5 + 0xac)) * fVar6;

    *(float *)(iVar5 + 0x128) = (float)fVar7;

    fVar8 = ((float10)*(float *)(iVar5 + 0xa4) - (float10)*(float *)(iVar5 + 0xb0)) * fVar6;

    *(float *)(iVar5 + 300) = (float)fVar8;

    fVar6 = ((float10)*(float *)(iVar5 + 0xa8) - (float10)*(float *)(iVar5 + 0xb4)) * fVar6;

    *(float *)(iVar5 + 0x130) = (float)fVar6;

    fVar2 = (float)(fVar7 * fVar7 + fVar8 * fVar8 + fVar6 * fVar6);

    if (fVar2 == 0.0) {

      *(undefined4 *)(*(int *)(iVar5 + 0x104) + 0x24) = 0;

    }

    else {

      *(uint *)(*(int *)(iVar5 + 0x104) + 0x24) =

           (&DAT_005f0a18)[(uint)fVar2 >> 8 & 0xffff] |

           ((int)fVar2 + 0xc0800000U >> 1) + 0x3f800000 & 0x7f800000;

    }

  }

  ObjectCalculateTransform(iVar5);

  iVar4 = *(int *)(iVar5 + 0x100);

  *(uint *)(iVar5 + 0xd8) = *(uint *)(iVar5 + 0xd8) | 0x20;

  *(undefined4 *)(iVar4 + 0x16c) = 0;

  *(undefined4 *)(iVar4 + 0x170) = 0;

  if (*(float *)(iVar5 + 0xa8) < 0.0 == (*(float *)(iVar5 + 0xa8) == 0.0)) {

    if (local_40 < *(float *)(iVar5 + 0xa8)) {

      *(undefined4 *)(iVar4 + 0x174) = 0;

      if (*(float *)(iVar5 + 0x130) <= *(float *)(DAT_00632ed8 + 0xf10)) {

        *(float *)(iVar4 + 0x16c) = -*(float *)(DAT_00632ed8 + 0xf14);

      }

      else {

        *(undefined4 *)(iVar4 + 0x16c) = *(undefined4 *)(iVar4 + 0x164);

      }

    }

    else if (*(float *)(iVar4 + 0x174) < 0.0 == (*(float *)(iVar4 + 0x174) == 0.0)) {

      fVar6 = (float10)FUN_00518b70(0,0);

      *(float *)(iVar4 + 0x174) = (float)((float10)*(float *)(iVar4 + 0x174) - fVar6);

    }

    else {

      local_30 = *pfVar1;

      local_2c = *(undefined4 *)(iVar5 + 0xa4);

      local_28 = *(undefined4 *)(iVar5 + 0xa8);

      fx_get_free_effect__Fv();

      *(undefined4 *)(iVar4 + 0x174) = 0x3e4ccccd;

    }

  }

  else {

    *(float *)(iVar4 + 0x170) = -(*(float *)(DAT_00632ed8 + 0xd90) * param_1);

  }

  if (*(float *)(iVar4 + 0x170) <= *(float *)(DAT_00632ed8 + 0xd90)) {

    fVar2 = -*(float *)(DAT_00632ed8 + 0xd90);

    if (*(float *)(iVar4 + 0x170) < fVar2) {

      *(float *)(iVar4 + 0x170) = fVar2;

    }

  }

  else {

    *(float *)(iVar4 + 0x170) = *(float *)(DAT_00632ed8 + 0xd90);

  }

  fVar6 = (float10)FUN_00518b70(iVar5,0,0x461c4000,*(undefined4 *)(iVar4 + 0x16c),

                                (float *)(iVar4 + 0x164));

  chase_angle((float)(fVar6 * (float10)*(float *)(DAT_00632ed8 + 0xe04)));

  pfVar1 = (float *)(iVar4 + 0x168);

  fVar6 = (float10)FUN_00518b70(iVar5,0,0x461c4000,*(undefined4 *)(iVar4 + 0x170),pfVar1);

  chase_angle((float)(fVar6 * (float10)*(float *)(DAT_00632ed8 + 0xe00)));

  GEO_MatBuildXYZ(iVar5 + 0x294,-*(float *)(iVar4 + 0x164),*pfVar1,*(undefined4 *)(iVar5 + 200));

  ANM_DumpCluster(iVar5,iVar4 + 0x178);

  if ((*pfVar1 < -10.0) || (10.0 < *pfVar1)) {

    if (*(int *)(iVar4 + 0x238) == 0) {

      sound_play_obj(0x62e,iVar5);

      *(undefined4 *)(iVar4 + 0x238) = 1;

    }

  }

  else if (*(int *)(iVar4 + 0x238) != 0) {

    sound_stop_obj(0x62e,iVar5);

    *(undefined4 *)(iVar4 + 0x238) = 0;

  }

  fVar6 = (float10)FUN_00518b70(iVar5,0);

  object_animate_process(iVar5,(float)fVar6);

  *(uint *)(iVar5 + 0xd8) = *(uint *)(iVar5 + 0xd8) | 0x40;

  if (((*(int *)(iVar3 + 0x194) != 0) &&

      (iVar5 = obj_face_target(*(int *)(iVar3 + 0x194),iVar5,local_5c), iVar5 != 0)) &&

     (iVar5 = point_between_pair_test(*(undefined4 *)(iVar3 + 0x194),local_5c), iVar5 != 0)) {

    *(int *)(iVar3 + 0x184) = *(int *)(iVar3 + 0x184) + 1;

    if (*(int *)(*(int *)(iVar3 + 0x194) + 0x174) == 0) {

      *(int *)(iVar3 + 0x198) = *(int *)(iVar3 + 0x198) + 1;

    }

    uVar9 = buoy_set_lights(*(int *)(iVar3 + 0x194),0);

    *(undefined4 *)(iVar3 + 0x194) = uVar9;

  }

  if (*(int *)(iVar3 + 0x198) != 5) {

    return;

  }

  if ((DAT_00632c00 == 0) && (DAT_00632c04 == 0)) {

    sound_play_player(0x6ce,DAT_00632a88);

  }

  voice_quota_check();

  return;

}

/* ===== FUN_004e7160 @ 0x004E7160 ===== */
void FUN_004e7160(int param_1,int param_2)



{

  int iVar1;

  undefined4 uVar2;

  float fVar3;

  

  iVar1 = *(int *)(param_1 + 0x100);

  if (param_2 != 0) {

    *(undefined4 *)(param_1 + 0x1a8) = *(undefined4 *)(iVar1 + 0x1ac);

    return;

  }

  if ((*(uint *)(param_1 + 0xe0) & 0x200) == 0) {

    if ((*(uint *)(param_1 + 0xe0) & 0x100) == 0) {

      if ((*(int *)(param_1 + 0x10) == 0x52) || (*(int *)(*(int *)(param_1 + 8) + 0x150) == 0))

      goto LAB_004e723e;

      fVar3 = *(float *)(param_1 + 0xc4) * 0.0;

      uVar2 = 0x52;

    }

    else {

      if ((*(int *)(param_1 + 0x10) == 0x9c) || (*(int *)(*(int *)(param_1 + 8) + 0x278) == 0))

      goto LAB_004e723e;

      fVar3 = *(float *)(param_1 + 0xc4) * 0.0;

      uVar2 = 0x9c;

    }

  }

  else {

    if ((*(int *)(param_1 + 0x10) == 0x91) || (*(int *)(*(int *)(param_1 + 8) + 0x24c) == 0))

    goto LAB_004e723e;

    fVar3 = *(float *)(param_1 + 0xc4) * 0.0;

    uVar2 = 0x91;

  }

  ObjectSetAnim(param_1,uVar2,0x21,0,fVar3,0x3e2aaaab);

LAB_004e723e:

  fVar3 = *(float *)(iVar1 + 0x1ac);

  *(float *)(param_1 + 0x1a8) = fVar3 + fVar3;

  return;

}

/* ===== FUN_004e7250 @ 0x004E7250 ===== */
undefined4 FUN_004e7250(int param_1)



{

  int iVar1;

  int iVar2;

  int iVar3;

  

  iVar1 = DAT_006330e4;

  iVar2 = __ftol();

  iVar3 = __ftol();

  if ((((-1 < iVar2) && (-1 < iVar3)) && (iVar2 < *(int *)(iVar1 + 0x1d8))) &&

     ((iVar3 < *(int *)(iVar1 + 0x1dc) &&

      (*(char *)(*(int *)(*(int *)(iVar1 + 0x10) + iVar3 * 4) + 0xe + iVar2 * 0x10) == '\0')))) {

    iVar1 = *(int *)(param_1 + 0x100);

    *(undefined4 *)(iVar1 + 0xe0) = *(undefined4 *)(param_1 + 0xa0);

    *(undefined4 *)(iVar1 + 0xe4) = *(undefined4 *)(param_1 + 0xa4);

    *(undefined4 *)(iVar1 + 0xe8) = *(undefined4 *)(param_1 + 0xa8);

    return 1;

  }

  return 0;

}

/* ===== ObjIsMyArmySpline__FP6OBJECTi @ 0x004E7300 ===== */
/* PS2 candidate: ObjIsMyArmySpline__FP6OBJECTi (conf 0.511) */



undefined4 ObjIsMyArmySpline__FP6OBJECTi(int param_1,int param_2)



{

  if ((*(int *)(param_1 + 4) == 0x48a) && (*(int *)(param_1 + 0xe8) == param_2)) {

    return 1;

  }

  return 0;

}

/* ===== FUN_004e7330 @ 0x004E7330 ===== */
void FUN_004e7330(int param_1,int param_2)



{

  int iVar1;

  int *piVar2;

  

  piVar2 = DAT_00632d68;

  if (DAT_00632d68 != (int *)0x0) {

    while (((iVar1 = piVar2[3], *(int *)(iVar1 + 4) != 0x48a ||

            (*(int *)(iVar1 + 0xe8) != *(int *)(param_2 + 0xe8))) ||

           (*(int *)(iVar1 + 0x174) != *(int *)(param_2 + 0x174) + -1))) {

      piVar2 = (int *)*piVar2;

      if (piVar2 == (int *)0x0) {

        return;

      }

    }

    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xffefffff;

    *(undefined4 *)(iVar1 + 0xf8) = 0;

  }

  return;

}

/* ===== rpman_set_smartie_goal__FP6OBJECT @ 0x004E7390 ===== */
/* PS2 candidate: rpman_set_smartie_goal__FP6OBJECT (conf 0.346) */



void rpman_set_smartie_goal__FP6OBJECT(int param_1)



{

  int iVar1;

  float10 fVar2;

  

  iVar1 = *(int *)(param_1 + 0x100);

  if (((*(uint *)(param_1 + 0xe0) & 0x20000000) == 0) &&

     ((*(uint *)(*(int *)(iVar1 + 0x20c) + 0xe0) & 0x100) == 0)) {

    fVar2 = (float10)distancesq2d__FP3P3DT0(param_1 + 0xa0,*(int *)(iVar1 + 0x1ec) + 0xa0);

    if ((float10)100.0 <= fVar2) {

      ai_moveonly_set_goal(param_1,*(int *)(iVar1 + 0x1ec) + 0xa0);

      *(undefined4 *)(param_1 + 0xec) = 0x3fc00000;

      return;

    }

  }

  ai_moveonly_set_goal(param_1,*(int *)(*(int *)(*(int *)(iVar1 + 0x134) + 0x100) + 0x18) + 0xa0);

  *(undefined4 *)(param_1 + 0xec) = 0x40980000;

  *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 0x20000000;

  *(uint *)(*(int *)(iVar1 + 0x20c) + 0xe0) = *(uint *)(*(int *)(iVar1 + 0x20c) + 0xe0) | 0x100;

  return;

}

/* ===== rpman_army_goto_firepit__FP6OBJECT @ 0x004E7460 ===== */
/* PS2 candidate: rpman_army_goto_firepit__FP6OBJECT (conf 0.433) */



void rpman_army_goto_firepit__FP6OBJECT(int param_1)



{

  int *piVar1;

  int iVar2;

  uint uVar3;

  float10 fVar4;

  float10 fVar5;

  undefined4 uVar6;

  float fVar7;

  float local_14;

  float local_10;

  float local_c;

  float local_8;

  undefined4 local_4;

  

  piVar1 = DAT_00632d9c;

  if (DAT_00632d9c == (int *)0x0) {

    return;

  }

  while( true ) {

    iVar2 = piVar1[3];

    if ((*(int *)(iVar2 + 4) == 0x2ee) || (*(int *)(iVar2 + 4) == 0x2d9)) break;

    piVar1 = (int *)*piVar1;

    if (piVar1 == (int *)0x0) {

      return;

    }

  }

  fVar4 = (float10)rndfloatrange(0x41f00000,0x42960000);

  fVar5 = (float10)rndfloatrange(0,0x43b40000);

  sine_cos_lookup((float)fVar5,&local_14,&local_10);

  local_c = local_14 * (float)fVar4 + *(float *)(iVar2 + 0xa0);

  local_8 = *(float *)(iVar2 + 0xa4) - local_10 * (float)fVar4;

  local_4 = *(undefined4 *)(iVar2 + 0xa8);

  *(undefined1 **)(param_1 + 0x16c) = &LAB_004cb930;

  ai_moveonly_set_goal(param_1,&local_c);

  iVar2 = crt_rand_scaled(100);

  if (iVar2 < 0x32) {

    uVar3 = *(uint *)(param_1 + 0xe0) | 0x10000;

  }

  else {

    uVar3 = *(uint *)(param_1 + 0xe0) & 0xfffeffff;

  }

  *(uint *)(param_1 + 0xe0) = uVar3;

  if ((uVar3 & 0x200) == 0) {

    if ((*(int *)(param_1 + 0x10) == 0x47) || (*(int *)(*(int *)(param_1 + 8) + 0x124) == 0))

    goto LAB_004e75b4;

    fVar7 = *(float *)(DAT_00632ed8 + 0xb38) * *(float *)(param_1 + 0xc4);

    uVar6 = 0x47;

  }

  else {

    if ((*(int *)(param_1 + 0x10) == 0x8e) || (*(int *)(*(int *)(param_1 + 8) + 0x240) == 0))

    goto LAB_004e75b4;

    fVar7 = *(float *)(DAT_00632ed8 + 0xb38) * *(float *)(param_1 + 0xc4);

    uVar6 = 0x8e;

  }

  ObjectSetAnim(param_1,uVar6,0x21,1,fVar7,0x3e2aaaab);

LAB_004e75b4:

  *(undefined4 *)(param_1 + 0xe4) = 0xdf;

  return;

}

/* ===== cspec_004e75d0 @ 0x004E75D0 ===== */
undefined4 cspec_004e75d0(void)



{

  return 0x240;

}

/* ===== cspec_004e75e0 @ 0x004E75E0 ===== */
void cspec_004e75e0(int param_1)



{

  int iVar1;

  

  iVar1 = *(int *)(param_1 + 0x100);

  obj_ptr_clear_if_dead(iVar1);

  obj_ptr_clear_if_dead(iVar1 + 0x44);

  obj_ptr_clear_if_dead(iVar1 + 4);

  obj_ptr_clear_if_dead(iVar1 + 0x1ec);

  obj_ptr_clear_if_dead(iVar1 + 0x1f0);

  obj_ptr_clear_if_dead(iVar1 + 0x20c);

  obj_ptr_clear_if_dead(iVar1 + 0x224);

  obj_ptr_clear_if_dead(iVar1 + 0x228);

  obj_ptr_clear_if_dead(iVar1 + 0x22c);

  obj_ptr_clear_if_dead(iVar1 + 0x134);

  obj_ptr_clear_if_dead(&DAT_005a8578);

  if ((DAT_005a858c != 0) && ((char)((uint)*(undefined4 *)(DAT_005a858c + 0xd8) >> 8) < '\0')) {

    DAT_005a858c = 0;

  }

  return;

}

/* ===== cspec_004e7680 @ 0x004E7680 ===== */
void cspec_004e7680(int param_1)



{

  int iVar1;

  int *piVar2;

  int *piVar3;

  int *piVar4;

  

  piVar3 = (int *)(*(int *)(param_1 + 0x100) + 0x234);

  if (DAT_0059f368 == (int *)0x0) {

    *piVar3 = 0;

    return;

  }

  piVar4 = DAT_0059f368;

  while (piVar4[0x11] != *piVar3) {

    piVar4 = (int *)*piVar4;

    if (piVar4 == (int *)0x0) {

      *piVar3 = 0;

      return;

    }

  }

  iVar1 = piVar4[7];

  if (iVar1 != 0) {

    if (iVar1 != 0) {

      (*DAT_005dd2a8)(iVar1);

    }

    piVar4[7] = 0;

  }

  piVar2 = (int *)piVar4[1];

  piVar4[0x11] = 0;

  if (piVar2 == (int *)0x0) {

    DAT_0059f368 = (int *)*piVar4;

    if (DAT_0059f368 != (int *)0x0) {

      *(undefined4 *)((int)DAT_0059f368 + 4) = 0;

      *piVar4 = (int)DAT_0059f360;

      DAT_0059f360 = piVar4;

      *piVar3 = 0;

      return;

    }

    DAT_0059f36c = (int *)0x0;

    *piVar4 = (int)DAT_0059f360;

    DAT_0059f360 = piVar4;

    *piVar3 = 0;

    return;

  }

  if (*piVar4 == 0) {

    DAT_0059f36c = piVar2;

    *piVar2 = 0;

  }

  else {

    *piVar2 = *piVar4;

    *(int *)(*piVar4 + 4) = piVar4[1];

  }

  *piVar4 = (int)DAT_0059f360;

  DAT_0059f360 = piVar4;

  *piVar3 = 0;

  return;

}

/* ===== cspec_004e76a0 @ 0x004E76A0 ===== */
void cspec_004e76a0(int param_1)



{

  int iVar1;

  int iVar2;

  

  iVar1 = *(int *)(param_1 + 0x100);

  iVar2 = *(int *)(iVar1 + 0x1b4);

  if (iVar2 != 0) {

    game_water_00513eb0(iVar2);

    *(undefined4 *)(iVar1 + 0x1b4) = 0;

  }

  return;

}

/* ===== rpman_gib__FP6OBJECTT0 @ 0x004E7970 ===== */
/* PS2 candidate: rpman_gib__FP6OBJECTT0 (conf 0.6040000000000001) */



void rpman_gib__FP6OBJECTT0(int param_1,int param_2)



{

  int iVar1;

  float fVar2;

  int iVar3;

  undefined4 uVar4;

  undefined4 local_40;

  

  iVar3 = *(int *)(param_1 + 0x100);

  if (*(int *)(iVar3 + 0x234) != 0) {

    sound_stop_sequence(iVar3 + 0x234);

  }

  if (*(int *)(iVar3 + 0x238) != 0) {

    sound_stop_obj(0x62e,param_1);

    *(undefined4 *)(iVar3 + 0x238) = 0;

  }

  if (param_2 == 0) {

    local_40 = *(float *)(param_1 + 0xb8) - *(float *)(param_1 + 0xa0);

    fVar2 = *(float *)(param_1 + 0xbc) - *(float *)(param_1 + 0xa4);

  }

  else {

    local_40 = *(float *)(param_2 + 0xb8) - *(float *)(param_2 + 0xa0);

    fVar2 = *(float *)(param_2 + 0xbc) - *(float *)(param_2 + 0xa4);

  }

  atand2pos(fVar2,local_40);

  fx_get_free_effect__Fv();

  if ((*(uint *)(param_1 + 0xe0) & 0x1000000) != 0) {

    iVar3 = *(int *)(param_1 + 0x100);

    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xfeffffff;

    iVar1 = *(int *)(iVar3 + 0x20c);

    if (iVar1 != 0) {

      smartie_unlock_from_player(iVar1,param_1,0);

      *(undefined4 *)(iVar3 + 0x20c) = 0;

    }

    DAT_005a8578 = 0;

  }

  iVar3 = crt_rand_scaled(100);

  if (iVar3 < 0x32) {

    uVar4 = 0x60b;

  }

  else {

    uVar4 = 0x60c;

  }

  sound_play_3dpos(uVar4,param_1 + 0xa0);

  object_destroy(param_1);

  return;

}

/* ===== rpman_notify_hit @ 0x004E7AE0 ===== */
/* PS2 candidate: rpman_notify_hit (conf 0.439) */



void rpman_notify_hit(float param_1,int param_2)



{

  int *piVar1;

  int *piVar2;

  int iVar3;

  uint uVar4;

  int iVar5;

  int *piVar6;

  int iVar7;

  undefined4 *puVar8;

  float *pfVar9;

  int iVar10;

  float10 fVar11;

  undefined4 uVar12;

  float fVar13;

  float fVar14;

  

  iVar5 = (int)param_1;

  piVar1 = *(int **)((int)param_1 + 0x100);

  if (*(int *)((int)param_1 + 0xe4) == 0) {

    return;

  }

  if ((((param_2 != 0) && (*(int *)(param_2 + 0x1e0) == 0x4d)) && (*(int *)(param_2 + 0x274) != 0))

     && (*(int *)(*(int *)(param_2 + 0x274) + 0x18c) == *(int *)((int)param_1 + 0x18c))) {

    return;

  }

  if (*(int *)((int)param_1 + 0xe8) != 0x66) {

    if (*piVar1 != 0) {

      return;

    }

    fVar11 = (float10)FUN_0050a610(DAT_00632a88 + 0xa0,(int)param_1 + 0xa0);

    fVar13 = (float)fVar11;

    puVar8 = DAT_00632d6c;

    do {

      if (puVar8 == (undefined4 *)0x0) {

        if ((piVar1[0x1b] != 0) && (*(int *)(piVar1[0x1b] + 0xe4) != 0x65)) {

          fVar11 = (float10)rndfloatrange(0x40400000,0x41700000);

          *(float *)(piVar1[0x1b] + 0xf0) = (float)fVar11;

          *(undefined4 *)(piVar1[0x1b] + 0xe4) = 0x65;

        }

        if (piVar1[0x4d] == 0) {

          return;

        }

        *(undefined4 *)(piVar1[0x4d] + 0xe4) = 3;

        return;

      }

      iVar5 = puVar8[3];

      iVar10 = *(int *)(iVar5 + 0x100);

      if (((((*(int *)(iVar5 + 4) == 0xd7) &&

            (*(float *)(iVar5 + 0x278) < *(float *)(iVar5 + 0x1c0))) &&

           ((iVar7 = *(int *)(iVar5 + 0xe4), iVar7 == 0xb || ((0x1d < iVar7 && (iVar7 < 0x23))))))

          && ((iVar3 = *(int *)(iVar5 + 0xe8), iVar3 != 9 &&

              (((iVar3 != 1 && (iVar7 != 0x12d)) && (iVar3 != 0x66)))))) &&

         ((iVar7 = *(int *)(iVar10 + 0x134), iVar7 == piVar1[0x4d] ||

          (((iVar7 == 0 || (*(int *)(iVar7 + 0x1e0) != 0x61)) &&

           (fVar11 = (float10)distancesq2d__FP3P3DT0((int)param_1 + 0xa0,iVar5 + 0xa0),

           fVar11 < (float10)625.0)))))) {

        rpman_find_hide_spot__FP6OBJECTi(iVar5,0);

        iVar7 = *(int *)(iVar10 + 0x44);

        piVar1[10] = *(int *)(iVar5 + 0xa0);

        piVar1[0xb] = *(int *)(iVar5 + 0xa4);

        piVar1[0xc] = *(int *)(iVar5 + 0xa8);

        uVar4 = *(uint *)(iVar5 + 0xe0);

        if (iVar7 == 0) {

          if ((uVar4 & 0x200) == 0) {

            *(uint *)(iVar5 + 0xe0) = uVar4 | 0x8004000;

            iVar7 = crt_rand_scaled(100);

            if (iVar7 < 0x33) {

              *(uint *)(iVar5 + 0xe0) = *(uint *)(iVar5 + 0xe0) | 0x8000;

              if ((*(int *)(iVar5 + 0x10) != 0x7f) && (*(int *)(*(int *)(iVar5 + 8) + 0x204) != 0))

              {

                fVar14 = *(float *)(iVar5 + 0xc4);

                uVar12 = 0x7f;

                goto LAB_004e82e2;

              }

            }

            else {

              *(uint *)(iVar5 + 0xe0) = *(uint *)(iVar5 + 0xe0) & 0xffff7fff;

              if ((*(int *)(iVar5 + 0x10) != 0x7e) && (*(int *)(*(int *)(iVar5 + 8) + 0x200) != 0))

              {

                fVar14 = *(float *)(iVar5 + 0xc4);

                uVar12 = 0x7e;

LAB_004e82e2:

                ObjectSetAnim(iVar5,uVar12,0x21,0,fVar14 * 0.0,0x3e2aaaab);

              }

            }

          }

          else {

            ai_damage_response(iVar5,1,0,0);

          }

          *(undefined4 *)(iVar5 + 0xe4) = 0x51;

        }

        else {

          if ((uVar4 & 0x200) == 0) {

            if ((*(int *)(iVar5 + 0x10) != 0x47) && (*(int *)(*(int *)(iVar5 + 8) + 0x124) != 0)) {

              fVar14 = *(float *)(DAT_00632ed8 + 0xb38) * *(float *)(iVar5 + 0xc4);

              uVar12 = 0x47;

              goto LAB_004e821a;

            }

          }

          else if ((*(int *)(iVar5 + 0x10) != 0x8e) && (*(int *)(*(int *)(iVar5 + 8) + 0x240) != 0))

          {

            fVar14 = *(float *)(DAT_00632ed8 + 0xb38) * *(float *)(iVar5 + 0xc4);

            uVar12 = 0x8e;

LAB_004e821a:

            ObjectSetAnim(iVar5,uVar12,0x21,1,fVar14,0x3e2aaaab);

          }

          *(undefined4 *)(iVar5 + 0xe4) = 0x50;

        }

        fVar11 = (float10)rndfloatrange(*(undefined4 *)(DAT_00632ed8 + 0xbd4),

                                        *(undefined4 *)(DAT_00632ed8 + 0xbd8));

        *(float *)(iVar10 + 0xd0) = (float)fVar11;

        iVar7 = DAT_00632a88;

        *(undefined4 *)(iVar10 + 0xc4) = *(undefined4 *)(DAT_00632a88 + 0xa0);

        *(undefined4 *)(iVar10 + 200) = *(undefined4 *)(iVar7 + 0xa4);

        *(undefined4 *)(iVar10 + 0xcc) = *(undefined4 *)(iVar7 + 0xa8);

        *(int *)(iVar10 + 8) = *(int *)(iVar5 + 0xa0);

        *(undefined4 *)(iVar10 + 0xc) = *(undefined4 *)(iVar5 + 0xa4);

        *(undefined4 *)(iVar10 + 0x10) = *(undefined4 *)(iVar5 + 0xa8);

        *(undefined4 *)(iVar10 + 0x14) = *(undefined4 *)(iVar5 + 200);

        if (fVar13 <= *(float *)(iVar10 + 0xa4)) {

          if (*(float *)(iVar10 + 0xa8) < fVar13) {

            *(float *)(iVar10 + 0xa8) = fVar13 + 2500.0;

          }

        }

        else {

          *(float *)(iVar10 + 0xa4) = fVar13 + 2500.0;

        }

        *(float *)(iVar10 + 0x160) = fVar13 + 2500.0;

      }

      puVar8 = (undefined4 *)*puVar8;

    } while( true );

  }

  if ((param_2 != 0) && (*(int *)(param_2 + 4) == 0x325)) {

    puVar8 = (undefined4 *)((int)param_1 + 0xa0);

    iVar10 = 0;

    if (DAT_005a8588 == 0) {

LAB_004e7bdc:

      iVar7 = iVar10;

      DAT_005a8588 = DAT_005a8588 + 1;

    }

    else {

      param_1 = 301.0;

      iVar7 = 0x43968000;

      pfVar9 = (float *)&DAT_005a850c;

      do {

        if (*pfVar9 < 0.0 != (*pfVar9 == 0.0)) {

          if (iVar10 < 5) goto LAB_004e7bdc;

          break;

        }

        fVar11 = (float10)distancesq2d__FP3P3DT0(puVar8,pfVar9 + -3);

        if (fVar11 < (float10)2500.0 != (fVar11 == (float10)2500.0)) {

          (&DAT_005a850c)[iVar10 * 4] = 0x43960000;

          return;

        }

        if (*pfVar9 < param_1) {

          param_1 = *pfVar9;

          iVar7 = iVar10;

        }

        pfVar9 = pfVar9 + 4;

        iVar10 = iVar10 + 1;

      } while ((int)pfVar9 < 0x5a855c);

    }

    (&DAT_005a8500)[iVar7 * 4] = *puVar8;

    (&DAT_005a8504)[iVar7 * 4] = *(undefined4 *)(iVar5 + 0xa4);

    uVar12 = *(undefined4 *)(iVar5 + 0xa8);

    (&DAT_005a850c)[iVar7 * 4] = 0x43960000;

    (&DAT_005a8508)[iVar7 * 4] = uVar12;

    return;

  }

  if (*piVar1 == 0) {

    iVar5 = crt_rand_scaled(100);

    if (iVar5 < piVar1[0x71]) {

      rpman_scan_for_enemy__FP6OBJECTfii(param_1,piVar1[0x2b],1,0);

    }

    if (*piVar1 != 0) goto LAB_004e7ce8;

    rpman_scan_for_enemy__FP6OBJECTfii(param_1,piVar1[0x2b],0,1);

  }

  else {

    iVar5 = obj_is_pickup_4a(*piVar1);

    if (((iVar5 != 0) || (iVar5 = obj_is_pickup_53(*piVar1), iVar5 != 0)) &&

       (iVar5 = ObjIsTurret(*piVar1), iVar5 == 0)) {

      iVar5 = *piVar1;

      *piVar1 = 0;

      *(undefined4 *)((int)param_1 + 0xe8) = 2;

      iVar10 = crt_rand_scaled(100);

      if (iVar10 < piVar1[0x71]) {

        rpman_scan_for_enemy__FP6OBJECTfii(param_1,piVar1[0x2b],1,0);

      }

      *(undefined4 *)((int)param_1 + 0xe8) = 0x66;

      if (*piVar1 == 0) {

        *piVar1 = iVar5;

        return;

      }

      goto LAB_004e7ce8;

    }

  }

  if (*piVar1 == 0) {

    return;

  }

LAB_004e7ce8:

  crt_rand_scaled(100);

  if ((((*(uint *)((int)param_1 + 0xe0) & 0x3000000) == 0) && (piVar1[0x8a] == 0)) &&

     (*(int *)((int)param_1 + 0xe4) != 200)) {

    if (piVar1[0x4d] != 0) {

      *(undefined4 *)(piVar1[0x4d] + 0xe4) = 3;

    }

    iVar5 = obj_is_pickup_4a(*piVar1);

    if (((iVar5 == 0) && (iVar5 = obj_is_pickup_53(*piVar1), iVar5 == 0)) ||

       (*(int *)((int)param_1 + 0xe8) != 0x66)) {

      *(uint *)((int)param_1 + 0xe0) = *(uint *)((int)param_1 + 0xe0) | 0x40000000;

      *(undefined4 *)((int)param_1 + 0xe4) = 0xc;

    }

    else {

      *(undefined4 *)((int)param_1 + 0xe4) = 0xcd;

    }

  }

  piVar6 = DAT_00632d68;

  if (DAT_00632d68 == (int *)0x0) {

    return;

  }

  do {

    iVar5 = piVar6[3];

    if (*(int *)(iVar5 + 4) == 0xd7) {

      if (((*(int *)(iVar5 + 0xe4) != 0) && (*(float *)(iVar5 + 0x278) < *(float *)(iVar5 + 0x1c0)))

         && ((((*(int *)(iVar5 + 0xe8) == 0x66 &&

               (((*(uint *)((int)param_1 + 0xe0) & 0x3000000) == 0 &&

                ((*(uint *)(iVar5 + 0xe0) & 0x1000000) == 0)))) &&

              (piVar2 = *(int **)(iVar5 + 0x100), piVar2[0x8a] == 0)) &&

             ((*(int *)(iVar5 + 0xe4) != 0x12d && (piVar2[0x4d] == piVar1[0x4d])))))) {

        piVar2[0x6e] = piVar2[0x6e] | 1;

        *(undefined4 *)(*(int *)(piVar2[0x4d] + 0x100) + 0x10) = 1;

        if ((*(int *)(iVar5 + 0xe4) != 200) && ((float)iVar5 != param_1)) {

          iVar10 = crt_rand_scaled(100);

          if (iVar10 < piVar2[0x72]) {

            *piVar2 = *piVar1;

            if ((*(uint *)(iVar5 + 0xe0) & 0x200) == 0) {

              if ((*(int *)(iVar5 + 0x10) != 0x47) && (*(int *)(*(int *)(iVar5 + 8) + 0x124) != 0))

              {

                fVar13 = *(float *)(DAT_00632ed8 + 0xb38) * *(float *)(iVar5 + 0xc4);

                uVar12 = 0x47;

                goto LAB_004e7ee7;

              }

            }

            else if ((*(int *)(iVar5 + 0x10) != 0x8e) &&

                    (*(int *)(*(int *)(iVar5 + 8) + 0x240) != 0)) {

              fVar13 = *(float *)(DAT_00632ed8 + 0xb38) * *(float *)(iVar5 + 0xc4);

              uVar12 = 0x8e;

LAB_004e7ee7:

              ObjectSetAnim(iVar5,uVar12,0x21,1,fVar13,0x3e2aaaab);

            }

            iVar10 = obj_is_pickup_4a(*piVar1);

            if (iVar10 == 0) {

              iVar10 = *piVar1;

LAB_004e7fcb:

              iVar10 = obj_is_pickup_53(iVar10);

              if (iVar10 != 0) goto LAB_004e7fd7;

            }

            else {

LAB_004e7fd7:

              if (*(int *)((int)param_1 + 0xe8) == 0x66) {

                *(undefined4 *)(iVar5 + 0xe4) = 0xcd;

                goto LAB_004e8053;

              }

            }

            iVar10 = crt_rand_scaled(100);

            if (iVar10 < 0x32) {

              *(uint *)((int)param_1 + 0xe0) = *(uint *)((int)param_1 + 0xe0) | 0x40000000;

            }

            *(undefined4 *)(iVar5 + 0xe4) = 0xc;

          }

          else if (*piVar2 == 0) {

            rpman_scan_for_enemy__FP6OBJECTfii(iVar5,piVar1[0x2b],0,1);

            if (*piVar2 == 0) {

              *piVar2 = *piVar1;

            }

            else if ((*(uint *)(iVar5 + 0xe0) & 0x200) == 0) {

              if ((*(int *)(iVar5 + 0x10) != 0x47) && (*(int *)(*(int *)(iVar5 + 8) + 0x124) != 0))

              {

                fVar13 = *(float *)(DAT_00632ed8 + 0xb38) * *(float *)(iVar5 + 0xc4);

                uVar12 = 0x47;

                goto LAB_004e7fae;

              }

            }

            else if ((*(int *)(iVar5 + 0x10) != 0x8e) &&

                    (*(int *)(*(int *)(iVar5 + 8) + 0x240) != 0)) {

              fVar13 = *(float *)(DAT_00632ed8 + 0xb38) * *(float *)(iVar5 + 0xc4);

              uVar12 = 0x8e;

LAB_004e7fae:

              ObjectSetAnim(iVar5,uVar12,0x21,1,fVar13,0x3e2aaaab);

            }

            iVar10 = obj_is_pickup_4a(*piVar1);

            if (iVar10 == 0) {

              iVar10 = *piVar1;

              goto LAB_004e7fcb;

            }

            goto LAB_004e7fd7;

          }

        }

      }

    }

    else {

      iVar10 = piVar1[0x7c];

      if ((((iVar10 != 0) && (*(int *)(iVar5 + 4) == 0x48a)) &&

          (*(int *)(iVar5 + 0xe8) == *(int *)(iVar10 + 0xe8))) &&

         (*(int *)(iVar5 + 0x174) == *(int *)(iVar10 + 0x174) + -1)) {

        *(undefined4 *)(iVar5 + 0xf8) = 0;

      }

    }

LAB_004e8053:

    piVar6 = (int *)*piVar6;

    if (piVar6 == (int *)0x0) {

      return;

    }

  } while( true );

}

/* ===== cspec_004e8410 @ 0x004E8410 ===== */
void cspec_004e8410(float param_1,float param_2,float param_3,float param_4,int param_5)



{

  int *piVar1;

  uint uVar2;

  float fVar3;

  undefined4 *puVar4;

  float fVar5;

  int iVar6;

  undefined4 uVar7;

  int iVar8;

  int *piVar9;

  int iVar10;

  int *piVar11;

  float10 fVar12;

  float fVar13;

  float fStack_40;

  float fStack_3c;

  float fStack_38;

  undefined4 uStack_30;

  undefined4 uStack_2c;

  undefined4 uStack_28;

  

  fVar5 = param_3;

  fVar13 = param_1;

  iVar10 = *(int *)((int)param_3 + 0xe4);

  piVar11 = *(int **)((int)param_3 + 0x100);

  if ((iVar10 == 0) || (iVar10 == 0xdd)) {

    return;

  }

  if (*(int *)((int)param_3 + 0xe8) == 0xb) {

    if (*(int *)((int)param_3 + 0x10) == 0xa6) {

      return;

    }

    if (*(int *)(*(int *)((int)param_3 + 8) + 0x2a0) != 0) {

      ObjectSetAnim(param_3,0xa6,0x20,0,*(float *)((int)param_3 + 0xc4) * 0.0,0x3e2aaaab);

    }

    piVar11[0x67] = piVar11[0x62];

    sound_play_obj(0x6d7,fVar5);

    return;

  }

  if ((param_4 != 0.0) && (*(float *)((int)param_4 + 0x274) == param_3)) {

    return;

  }

  if (499 < iVar10) {

    fVar13 = param_2 + *(float *)((int)param_3 + 0x278);

    *(float *)((int)param_3 + 0x278) = fVar13;

    if (fVar13 < *(float *)(DAT_00632ed8 + 0xc50) + *(float *)((int)param_3 + 0x1c0)) {

      return;

    }

    rpman_gib__FP6OBJECTT0(param_3,param_4);

    return;

  }

  if (iVar10 == 0x3c) {

    *(uint *)((int)param_3 + 0x1c8) = *(uint *)((int)param_3 + 0x1c8) & 0xfffffbff;

  }

  if (((((param_4 == 0.0) || (*(int *)((int)param_4 + 0x274) == 0)) ||

       (*(int *)(*(int *)((int)param_4 + 0x274) + 0x18c) != *(int *)((int)param_3 + 0x18c))) &&

      ((iVar10 != 0x12d && (iVar10 != 0x23)))) &&

     ((*piVar11 == 0 ||

      (((param_1 != 2.10195e-44 && (param_1 != 1.82169e-44)) &&

       ((param_1 != 1.96182e-44 && (param_1 != 1.4013e-45)))))))) {

    if (*(float *)((int)param_3 + 0x278) < *(float *)((int)param_3 + 0x1c0)) {

      rpman_notify_hit(param_3,param_4);

    }

    ai_d7_pairing(fVar5,0x41c80000);

    *(undefined4 *)((int)fVar5 + 0xec) = 0;

  }

  iVar6 = param_5;

  iVar10 = piVar11[0x54];

  if (((iVar10 != 0) &&

      (((iVar8 = *(int *)((int)fVar5 + 0xe4), iVar8 == 0xad || (iVar8 == 0xae)) || (iVar8 == 0x28)))

      ) && ((0x30 < (int)fVar13 && ((int)fVar13 < 0x45)))) {

    if (param_5 == 0) {

      return;

    }

    fVar3 = *(float *)(iVar10 + 0xa8) + 11.0;

    if (fVar3 < *(float *)(param_5 + 8) != (fVar3 == *(float *)(param_5 + 8))) {

      return;

    }

    fVar12 = (float10)distancesq2d__FP3P3DT0(iVar10 + 0xa0,param_5);

    if ((float10)324.0 <= fVar12) {

      return;

    }

  }

  param_5 = 0;

  fVar3 = param_2;

  if (((iVar6 != 0) && (((int)fVar13 < 0x31 || (0x44 < (int)fVar13)))) &&

     (param_5 = death_pose_setup(fVar5,0x5614b8,iVar6), fVar3 = param_2, param_5 != 0)) {

    fVar3 = *(float *)(DAT_00632ed8 + 0x1100) * param_2;

  }

  *(float *)((int)fVar5 + 0x278) = fVar3 + *(float *)((int)fVar5 + 0x278);

  if (*(float *)((int)fVar5 + 0x278) < *(float *)((int)fVar5 + 0x1c0)) {

    if ((*(uint *)((int)fVar5 + 0xe0) & 0x40000) == 0) {

      fVar12 = (float10)FUN_0050a610(DAT_00632a88 + 0xa0,(int)fVar5 + 0xa0);

      if (fVar12 <= (float10)(float)piVar11[0x29]) {

        if ((float10)(float)piVar11[0x2a] < fVar12) {

          piVar11[0x2a] = (int)(float)(fVar12 + (float10)2500.0);

        }

      }

      else {

        piVar11[0x29] = (int)(float)(fVar12 + (float10)2500.0);

      }

    }

    wound_from_object_world(fVar5,iVar6);

    uVar7 = rndintrange(0x76,0x77);

    sound_play_obj(uVar7,fVar5);

    iVar10 = (int)param_4;

    uVar2 = *(uint *)((int)fVar5 + 0xe0);

    *(uint *)((int)fVar5 + 0xe0) = uVar2 | 4;

    if ((uVar2 & 0x2000000) != 0) {

      return;

    }

    iVar8 = *(int *)((int)fVar5 + 0xe4);

    if (iVar8 == 0x12d) {

      return;

    }

    if ((iVar8 == 0xdc) || (iVar8 == 0xe4)) {

      if (param_4 == 0.0) {

        return;

      }

      if (*(int *)((int)param_4 + 0x1e0) != 0x4d) {

        return;

      }

      piVar11 = piVar11 + 0x8a;

      iVar10 = 2;

      do {

        iVar6 = (int)param_4;

        if (*piVar11 != 0) {

          piVar9 = *(int **)(*piVar11 + 0x100);

          if (*piVar9 == 0) {

            *piVar9 = *(int *)((int)param_4 + 0x274);

          }

          else {

            iVar8 = ObjIsPlayer(*(undefined4 *)((int)param_4 + 0x274));

            if ((iVar8 != 0) && (*(int *)(*(int *)(iVar6 + 0x274) + 0x174) == 0)) {

              *piVar9 = *(int *)(iVar6 + 0x274);

            }

          }

        }

        piVar11 = piVar11 + 1;

        iVar10 = iVar10 + -1;

      } while (iVar10 != 0);

      return;

    }

    if (((piVar11[0x8a] != 0) && (param_4 != 0.0)) && (*(int *)((int)param_4 + 0x1e0) == 0x4d)) {

      if (*piVar11 != 0) {

        iVar6 = ObjIsPlayer(*(undefined4 *)((int)param_4 + 0x274));

        if (iVar6 == 0) {

          return;

        }

        if (*(int *)(*(int *)(iVar10 + 0x274) + 0x174) != 0) {

          return;

        }

      }

      *piVar11 = *(int *)(iVar10 + 0x274);

      return;

    }

    if ((uVar2 & 0x1000000) != 0) {

      return;

    }

    if (*(int *)((int)fVar5 + 0x210) != 0) {

      iVar10 = *(int *)(*(int *)((int)fVar5 + 0x210) + 0x1e0);

      if (iVar10 == 1) {

        return;

      }

      if (iVar10 == 0x4c) {

        return;

      }

    }

    iVar10 = *(int *)((int)fVar5 + 0xe8);

    if ((iVar10 != 0) && (iVar10 != 2)) {

      if (iVar10 != 1) {

        return;

      }

      if (0.0 <= (float)piVar11[0x19]) {

        return;

      }

    }

    if ((0x59 < iVar8) && (iVar8 < 0x5f)) {

      return;

    }

    if ((((param_4 != 0.0) && (*(int *)((int)param_4 + 0x1e0) == 0x4d)) && (iVar10 != 1)) &&

       (*(int *)((int)param_4 + 4) == 0x319)) {

      fVar12 = (float10)rndfloatrange(0x41200000,0x41700000);

      piVar11[0x19] = (int)(float)fVar12;

      if ((*(int *)((int)fVar5 + 0x10) != 0xac) && (*(int *)(*(int *)((int)fVar5 + 8) + 0x2b8) != 0)

         ) {

        ObjectSetAnim(fVar5,0xac,0x20,0,*(float *)((int)fVar5 + 0xc4) * 0.0,0x3e2aaaab);

      }

      *(undefined4 *)((int)fVar5 + 0xe4) = 0x5e;

      return;

    }

    if ((param_2 <= *(float *)(DAT_00632ed8 + 0xc48)) || (iVar10 == 1)) {

      if (param_2 <= *(float *)(DAT_00632ed8 + 0xc4c)) {

        return;

      }

      fVar12 = (float10)rndfloatrange(0x41200000,0x41700000);

      piVar11[0x19] = (int)(float)fVar12;

      if (piVar11[0x36] == 0) {

        if ((*(uint *)((int)fVar5 + 0xe0) & 0x100) == 0) {

          iVar10 = crt_rand_scaled(3);

          if (iVar10 == 0) {

            if ((*(int *)((int)fVar5 + 0x10) == 0x85) ||

               (*(int *)(*(int *)((int)fVar5 + 8) + 0x21c) == 0)) goto code_r0x004e912b;

            fVar13 = *(float *)((int)fVar5 + 0xc4) * 0.0;

            uVar7 = 0x85;

          }

          else if (iVar10 == 1) {

            if ((*(int *)((int)fVar5 + 0x10) == 0x86) ||

               (*(int *)(*(int *)((int)fVar5 + 8) + 0x220) == 0)) goto code_r0x004e912b;

            fVar13 = *(float *)((int)fVar5 + 0xc4) * 0.0;

            uVar7 = 0x86;

          }

          else {

            if ((*(int *)((int)fVar5 + 0x10) == 0x87) ||

               (*(int *)(*(int *)((int)fVar5 + 8) + 0x224) == 0)) goto code_r0x004e912b;

            fVar13 = *(float *)((int)fVar5 + 0xc4) * 0.0;

            uVar7 = 0x87;

          }

        }

        else {

          if ((*(int *)((int)fVar5 + 0x10) == 0xa9) ||

             (*(int *)(*(int *)((int)fVar5 + 8) + 0x2ac) == 0)) goto code_r0x004e912b;

          fVar13 = *(float *)((int)fVar5 + 0xc4) * 0.0;

          uVar7 = 0xa9;

        }

      }

      else {

        if ((*(int *)((int)fVar5 + 0x10) == 0x88) ||

           (*(int *)(*(int *)((int)fVar5 + 8) + 0x228) == 0)) goto code_r0x004e912b;

        fVar13 = *(float *)((int)fVar5 + 0xc4) * 0.0;

        uVar7 = 0x88;

      }

      ObjectSetAnim(fVar5,uVar7,0x20,0,fVar13,0x3e2aaaab);

code_r0x004e912b:

      *(undefined4 *)((int)fVar5 + 0xe4) = 0x5d;

      return;

    }

    fVar12 = (float10)rndfloatrange(0x41200000,0x41700000);

    piVar11[0x19] = (int)(float)fVar12;

    if (piVar11[0x36] == 0) {

      if ((*(int *)((int)fVar5 + 0x10) == 0x58) || (*(int *)(*(int *)((int)fVar5 + 8) + 0x168) == 0)

         ) goto code_r0x004e8ef4;

      fVar13 = *(float *)((int)fVar5 + 0xc4);

      uVar7 = 0x58;

    }

    else {

      if ((*(int *)((int)fVar5 + 0x10) == 0x3d) || (*(int *)(*(int *)((int)fVar5 + 8) + 0xfc) == 0))

      goto code_r0x004e8ef4;

      fVar13 = *(float *)((int)fVar5 + 0xc4);

      uVar7 = 0x3d;

    }

    ObjectSetAnim(fVar5,uVar7,0x21,0,fVar13 * 0.0,0x3e2aaaab);

code_r0x004e8ef4:

    if (iVar6 == 0) {

      if (param_4 == 0.0) {

        fVar12 = (float10)*(float *)((int)fVar5 + 200) + (float10)180.0;

      }

      else {

        fVar12 = (float10)dirfcalcp3d__FP3P3DT0((int)param_4 + 0xa0,(int)fVar5 + 0xa0);

      }

    }

    else {

      fVar12 = (float10)dirfcalcp3d__FP3P3DT0(iVar6,(int)fVar5 + 0xa0);

    }

    param_4 = (float)fVar12;

    sine_cos_lookup(param_4,&param_3,&param_1);

    *(float *)((int)fVar5 + 0x128) = *(float *)(DAT_00632ed8 + 0xc60) * param_3;

    *(float *)((int)fVar5 + 300) = -(*(float *)(DAT_00632ed8 + 0xc60) * param_1);

    fVar13 = *(float *)(DAT_00632ed8 + 0xc64);

    *(undefined4 *)((int)fVar5 + 0xe4) = 0x5a;

    *(float *)((int)fVar5 + 0x130) = fVar13 + *(float *)((int)fVar5 + 0x130);

    return;

  }

  sound_stop_obj(0x56c,fVar5);

  if (piVar11[0x8d] != 0) {

    sound_stop_sequence(piVar11 + 0x8d);

  }

  if (piVar11[0x8e] != 0) {

    sound_stop_obj(0x62e,fVar5);

    piVar11[0x8e] = 0;

  }

  *(uint *)((int)fVar5 + 0x1c8) = *(uint *)((int)fVar5 + 0x1c8) | 0x800;

  if ((*(uint *)((int)fVar5 + 0xe0) & 0x1000000) != 0) {

    *(uint *)((int)fVar5 + 0xe0) = *(uint *)((int)fVar5 + 0xe0) & 0xfeffffff;

    DAT_005a8578 = 0;

    if (piVar11[0x83] != 0) {

      smartie_unlock_from_player(piVar11[0x83],fVar5,0);

      piVar11[0x83] = 0;

      piVar9 = piVar11 + 0x8a;

      iVar10 = 2;

      do {

        if (*piVar9 != 0) {

          piVar1 = *(int **)(*piVar9 + 0x100);

          piVar1[0x8a] = 0;

          if ((param_4 != 0.0) && (*(int *)((int)param_4 + 0x1e0) == 0x4d)) {

            if (*piVar1 == 0) {

              iVar6 = *(int *)((int)param_4 + 0x274);

            }

            else {

              iVar6 = ObjIsPlayer(*(undefined4 *)((int)param_4 + 0x274));

              if ((iVar6 == 0) ||

                 (iVar6 = *(int *)((int)param_4 + 0x274), *(int *)(iVar6 + 0x174) != 0))

              goto code_r0x004e8788;

            }

            *piVar1 = iVar6;

          }

        }

code_r0x004e8788:

        piVar9 = piVar9 + 1;

        iVar10 = iVar10 + -1;

      } while (iVar10 != 0);

    }

  }

  iVar10 = *(int *)((int)fVar5 + 0x100);

  param_2 = (float)iVar10;

  iVar6 = ObjIsReaper(DAT_00632a88);

  if (iVar6 == 0) {

    *(uint *)((int)fVar5 + 0xe0) = *(uint *)((int)fVar5 + 0xe0) | 0x4000000;

  }

  if (*(int *)((int)fVar5 + 0xe4) != 0x23) {

    iVar6 = *(int *)((int)fVar5 + 0x100);

    if ((*(int *)(iVar6 + 0x134) != 0) && (puVar4 = DAT_00632d6c, *(int *)(iVar6 + 0xb0) != -1)) {

      for (; puVar4 != (undefined4 *)0x0; puVar4 = (undefined4 *)*puVar4) {

        fVar13 = (float)puVar4[3];

        if ((((fVar5 != fVar13) && (*(int *)((int)fVar13 + 4) == 0xd7)) &&

            (iVar10 = *(int *)((int)fVar13 + 0x100),

            *(int *)(iVar10 + 0x134) == *(int *)(iVar6 + 0x134))) &&

           (((*(int *)(iVar6 + 0xb0) < *(int *)(iVar10 + 0xb0) &&

             (iVar8 = *(int *)(iVar10 + 0xb0) + -1, *(int *)(iVar10 + 0xb0) = iVar8, iVar8 == 0)) &&

            (*(int *)((int)fVar13 + 0xe4) == 0x21)))) {

          *(undefined4 *)((int)fVar13 + 0xe4) = *(undefined4 *)((int)fVar5 + 0xe4);

          *(undefined4 *)(iVar10 + 0xbc) = *(undefined4 *)(iVar6 + 0xbc);

          *(undefined4 *)(iVar10 + 0xd0) = *(undefined4 *)(iVar6 + 0xd0);

        }

      }

      *(undefined4 *)(iVar6 + 0xb0) = 0xffffffff;

      iVar10 = (int)param_2;

    }

    if (((*(int *)((int)fVar5 + 0xe4) != 0xc9) && (*(int *)((int)fVar5 + 0xe4) != 200)) &&

       ((iVar6 = *(int *)(iVar10 + 0x134), iVar6 != 0 && (*(int *)(iVar6 + 0x1e0) == 0x61)))) {

      piVar9 = (int *)(*(int *)(iVar6 + 0x100) + 8);

      *piVar9 = *piVar9 + -1;

    }

    iVar10 = *(int *)(iVar10 + 0x134);

    if ((iVar10 != 0) && (*(int *)(iVar10 + 0x1e0) == 0x61)) {

      formation_notify_death(iVar10);

    }

  }

  piVar11[0x4d] = 0;

  piVar11[0x11] = 0;

  if ((*(uint *)((int)fVar5 + 0xe0) & 0x40000) != 0) {

    uStack_30 = *(undefined4 *)((int)fVar5 + 0xa0);

    uStack_2c = *(undefined4 *)((int)fVar5 + 0xa4);

    uStack_28 = *(undefined4 *)((int)fVar5 + 0xa8);

    fx_get_free_effect__Fv();

    line_damage_with_slope

              (0x31,fVar5,0,(undefined4 *)((int)fVar5 + 0xa0),*(undefined4 *)(DAT_00632ed8 + 0x1094)

               ,*(undefined4 *)(DAT_00632ed8 + 0x1098),*(undefined4 *)(DAT_00632ed8 + 0x109c),

               *(undefined4 *)(DAT_00632ed8 + 0x10a0),*(undefined4 *)((int)fVar5 + 0x18c));

    rpman_gib__FP6OBJECTT0(fVar5,0);

    *piVar11 = 0;

    return;

  }

  iVar10 = *(int *)((int)fVar5 + 0x210);

  if (*(int *)((int)fVar5 + 0xe8) == 7) {

    func_0x0050c990(iVar10,1);

    rpman_gib__FP6OBJECTT0(fVar5,param_4);

    *piVar11 = 0;

    return;

  }

  if ((iVar10 != 0) && ((*(int *)(iVar10 + 0x1e0) == 1 || (*(int *)(iVar10 + 0x1e0) == 0x4c)))) {

    rpman_gib__FP6OBJECTT0(fVar5,param_4);

    *piVar11 = 0;

    return;

  }

  uVar7 = rndintrange(0x83,0x86);

  sound_play_obj(uVar7,fVar5);

  if (param_5 == 0) {

    fVar13 = *(float *)(DAT_00632ed8 + 0xc50) + *(float *)((int)fVar5 + 0x1c0);

    if (fVar13 < *(float *)((int)fVar5 + 0x278) != (fVar13 == *(float *)((int)fVar5 + 0x278))) {

      func_0x004e76d0(fVar5);

      rpman_gib__FP6OBJECTT0(fVar5,param_4);

      *piVar11 = 0;

      return;

    }

    if (*(int *)((int)fVar5 + 0xe4) == 0x5b) {

      func_0x004e76d0(fVar5);

      *(undefined4 *)((int)fVar5 + 0xe4) = 500;

      *piVar11 = 0;

      return;

    }

    sine_cos_lookup(*(undefined4 *)((int)fVar5 + 200),&param_3,&param_1);

    fStack_40 = param_3 * 10.0 + *(float *)((int)fVar5 + 0xa0);

    fStack_3c = *(float *)((int)fVar5 + 0xa4) - param_1 * 10.0;

    fVar12 = (float10)get_floor_z_point(&fStack_40);

    fStack_38 = (float)fVar12;

    if ((12.0 < *(float *)((int)fVar5 + 0xa8) - fStack_38) && (*(int *)((int)fVar5 + 0xe8) != 7)) {

      *(undefined4 *)((int)fVar5 + 0x210) = 0;

      *(undefined4 *)((int)fVar5 + 0xe4) = 0x1f5;

      *(undefined4 *)((int)fVar5 + 0x130) = *(undefined4 *)(DAT_00632ed8 + 0x74);

      *(float *)((int)fVar5 + 0x128) = *(float *)(DAT_00632ed8 + 0x78) * param_3;

      *(float *)((int)fVar5 + 300) = -(*(float *)(DAT_00632ed8 + 0x78) * param_1);

      if ((*(int *)((int)fVar5 + 0x10) != 0x3e) && (*(int *)(*(int *)((int)fVar5 + 8) + 0x100) != 0)

         ) {

        ObjectSetAnim(fVar5,0x3e,0x20,0,*(float *)((int)fVar5 + 0xc4) * 0.0,0x3e2aaaab);

        *piVar11 = 0;

        return;

      }

      goto code_r0x004e8a31;

    }

    func_0x004e76d0(fVar5);

    uVar7 = rndintrange(0,8);

    iVar10 = (int)param_4;

    switch(uVar7) {

    case 0:

      iVar10 = 0x3a;

      break;

    case 1:

      iVar10 = 0x3c;

      break;

    case 2:

      iVar10 = 0x40;

      break;

    case 3:

      iVar10 = 0x56;

      break;

    case 4:

      iVar10 = 0x57;

      break;

    case 5:

      iVar10 = 0x59;

      break;

    case 6:

      iVar10 = 0x5a;

      break;

    case 7:

      iVar10 = 0x5b;

      break;

    case 8:

      iVar10 = 0x5c;

    }

    if ((*(int *)((int)fVar5 + 0x10) != iVar10) &&

       (*(int *)(*(int *)((int)fVar5 + 8) + 8 + iVar10 * 4) != 0)) {

      fVar13 = *(float *)((int)fVar5 + 0xc4);

      goto LAB_004e8a1e;

    }

  }

  else {

    func_0x004e76d0(fVar5);

    if ((*(int *)((int)fVar5 + 0x10) != 0xa7) && (*(int *)(*(int *)((int)fVar5 + 8) + 0x2a4) != 0))

    {

      fVar13 = *(float *)((int)fVar5 + 0xc4);

      iVar10 = 0xa7;

LAB_004e8a1e:

      ObjectSetAnim(fVar5,iVar10,0x20,0,fVar13 * 0.0,0x3e2aaaab);

    }

  }

  *(undefined4 *)((int)fVar5 + 0xe4) = 500;

code_r0x004e8a31:

  *piVar11 = 0;

  return;

}

/* ===== cspec_004e91e0 @ 0x004E91E0 ===== */
void cspec_004e91e0(int param_1)



{

  int iVar1;

  int *piVar2;

  int iVar3;

  undefined4 *puVar4;

  int iVar5;

  int iVar6;

  float10 fVar7;

  float fVar8;

  undefined4 uVar9;

  int iStack_2c;

  undefined1 auStack_24 [12];

  undefined1 auStack_18 [12];

  undefined1 auStack_c [12];

  

  iVar3 = param_1;

  if (DAT_00632e74 != 0) {

    return;

  }

  iVar6 = *(int *)(param_1 + 0xe4);

  if (iVar6 != 0) {

    if (iVar6 == 1) {

      if (*(float *)(param_1 + 0xec) < 0.0 == (*(float *)(param_1 + 0xec) == 0.0)) {

        fVar7 = (float10)FUN_00518b70(0,0);

        *(float *)(param_1 + 0xec) = (float)((float10)*(float *)(param_1 + 0xec) - fVar7);

      }

      else if ((*(int *)(DAT_00632a88 + 4) == 0) ||

              (fVar8 = *(float *)(DAT_00632ed8 + 0x1364),

              fVar7 = (float10)distancesq2d__FP3P3DT0(DAT_00632a88 + 0xa0,param_1 + 0xa0),

              (float10)fVar8 * (float10)fVar8 <= fVar7)) {

        *(undefined4 *)(param_1 + 0xec) = 0x3fb33333;

      }

      else {

        *(undefined4 *)(param_1 + 0xe4) = 2;

      }

      goto code_r0x004e9829;

    }

    if (iVar6 != 2) goto code_r0x004e9829;

    fVar7 = (float10)FUN_00518b70(param_1,0);

    if (*(int *)(param_1 + 0xf4) < 1) {

      *(undefined4 *)(param_1 + 0xf8) = 0;

    }

    if (*(int *)(param_1 + 0xf8) != 0) {

      fVar8 = *(float *)(param_1 + 0xf0) - (float)fVar7;

      *(float *)(param_1 + 0xf0) = fVar8;

      if (fVar8 < 0.0 != (fVar8 == 0.0)) {

        iVar6 = *(int *)(param_1 + 0xe8);

        if ((iVar6 == 0) || (iVar6 == 2)) {

          func_0x004e9960(param_1,0);

        }

        else if (iVar6 == 3) {

          func_0x004e9860(param_1,1);

        }

        else {

          func_0x004e9860(param_1,0);

        }

      }

    }

    fVar8 = *(float *)(param_1 + 0xec) - (float)fVar7;

    *(float *)(param_1 + 0xec) = fVar8;

    if (fVar8 < 0.0 == (fVar8 == 0.0)) goto code_r0x004e9829;

    iVar6 = *(int *)(param_1 + 0xe8);

    if ((iVar6 != 0) && (iVar6 != 2)) {

      if (iVar6 == 4) {

        iVar6 = *(int *)(param_1 + 0xf8);

        puVar4 = DAT_00632d6c;

        iVar5 = DAT_00632ed8;

        while ((puVar4 != (undefined4 *)0x0 &&

               ((((iVar1 = puVar4[3], *(int *)(iVar1 + 0x1e0) != 0x17 ||

                  (*(int *)(*(int *)(iVar1 + 0x100) + 0x44) != param_1)) ||

                 (fVar7 = (float10)distancesq2d__FP3P3DT0(iVar1 + 0xa0,param_1 + 0xa0),

                 iVar5 = DAT_00632ed8,

                 (float10)*(float *)(DAT_00632ed8 + 0xcac) *

                 (float10)*(float *)(DAT_00632ed8 + 0xcac) < fVar7)) ||

                (iVar6 = iVar6 + 1, iVar6 < *(int *)(DAT_00632ed8 + 0xca4)))))) {

          puVar4 = (undefined4 *)*puVar4;

        }

        if (((iVar6 < *(int *)(iVar5 + 0xca4)) && (0 < *(int *)(param_1 + 0xf4))) &&

           (iVar6 = *(int *)(param_1 + 0xf8) + *(int *)(iVar5 + 0xcb4),

           *(int *)(param_1 + 0xf8) = iVar6, iVar6 == *(int *)(DAT_00632ed8 + 0xcb4))) {

          if ((*(int *)(param_1 + 0x174) == 1) || (*(int *)(param_1 + 0x174) != 0)) {

            func_0x004e9860(param_1,1);

          }

          else {

            func_0x004e9860(param_1,0);

          }

        }

      }

      goto code_r0x004e9829;

    }

    iStack_2c = *(int *)(param_1 + 0xf8);

    iVar6 = 0;

    param_1 = 0;

    if (DAT_00632d6c != (undefined4 *)0x0) {

      iVar6 = 0;

      puVar4 = DAT_00632d6c;

      do {

        iVar5 = puVar4[3];

        if ((((*(int *)(iVar5 + 0x1e0) == 0x33) && (*(int *)(iVar5 + 0xe8) != 4)) &&

            (piVar2 = *(int **)(iVar5 + 0x100), piVar2[0x89] == iVar3)) &&

           (fVar7 = (float10)distancesq2d__FP3P3DT0(iVar5 + 0xa0,iVar3 + 0xa0),

           fVar7 <= (float10)*(float *)(DAT_00632ed8 + 0xcac) *

                    (float10)*(float *)(DAT_00632ed8 + 0xcac))) {

          if ((((*(uint *)(iVar5 + 0xe0) & 0x20000) != 0) && (*piVar2 == 0)) &&

             ((param_1 = param_1 + 1, iVar6 == 0 && (*(int *)(DAT_00632ed8 + 0xca4) < param_1)))) {

            iVar6 = iVar5;

          }

          iStack_2c = iStack_2c + 1;

          if ((*(int *)(DAT_00632ed8 + 0xca4) <= iStack_2c) && (iVar6 != 0)) break;

        }

        puVar4 = (undefined4 *)*puVar4;

      } while (puVar4 != (undefined4 *)0x0);

    }

    if ((iStack_2c < *(int *)(DAT_00632ed8 + 0xca4)) && (0 < *(int *)(iVar3 + 0xf4))) {

      iVar5 = *(int *)(iVar3 + 0x174);

      *(int *)(iVar3 + 0xf8) = *(int *)(iVar3 + 0xf8) + *(int *)(DAT_00632ed8 + 0xcb4);

      if (iVar5 == 3) {

        uVar9 = 0x40400000;

      }

      else if (iVar5 == 2) {

        uVar9 = 0x40000000;

      }

      else if (iVar5 == 1) {

        uVar9 = 0x3f800000;

      }

      else {

        uVar9 = 0;

      }

      func_0x004e9960(iVar3,uVar9);

    }

    if (iVar6 != 0) {

      playerobj_eval_refpt(iVar3,1,auStack_18);

      playerobj_eval_refpt(iVar3,2,auStack_c);

      FUN_0050a610(iVar6 + 0xa0,auStack_18);

      FUN_0050a610(iVar6 + 0xa0,auStack_c);

      if ((*(uint *)(iVar6 + 0xe0) & 0x200) == 0) {

        if ((*(int *)(iVar6 + 0x10) != 0x47) && (*(int *)(*(int *)(iVar6 + 8) + 0x124) != 0)) {

          fVar8 = *(float *)(DAT_00632ed8 + 0xb38) * *(float *)(iVar6 + 0xc4);

          uVar9 = 0x47;

          goto code_r0x004e95d2;

        }

      }

      else if ((*(int *)(iVar6 + 0x10) != 0x8e) && (*(int *)(*(int *)(iVar6 + 8) + 0x240) != 0)) {

        fVar8 = *(float *)(DAT_00632ed8 + 0xb38) * *(float *)(iVar6 + 0xc4);

        uVar9 = 0x8e;

code_r0x004e95d2:

        ObjectSetAnim(iVar6,uVar9,0x21,1,fVar8,0x3e2aaaab);

      }

      *(int *)(iVar6 + 0x274) = iVar3;

      ai_clear_move_goal(iVar6);

      ai_moveonly_set_goal(iVar6,auStack_24);

      *(uint *)(iVar6 + 0xe0) = *(uint *)(iVar6 + 0xe0) & 0xfffdffff;

      *(undefined4 *)(iVar6 + 0xe4) = 0x70;

    }

    *(undefined4 *)(iVar3 + 0xec) = *(undefined4 *)(DAT_00632ed8 + 0xca8);

    goto code_r0x004e9829;

  }

  *(undefined4 *)(param_1 + 0xe4) = 1;

  *(undefined4 *)(param_1 + 0x278) = 0;

  ObjectSetAnim(param_1,1,0x84,0,0,0);

  *(undefined4 *)(param_1 + 0x14) = 0x3f800000;

  switch(*(undefined4 *)(param_1 + 0xe8)) {

  case 0:

    if (*(int *)(param_1 + 4) != 0x2ae) {

      if (*(int *)(param_1 + 4) == 0x4ca) {

        *(undefined4 *)(param_1 + 0xe8) = 4;

        sound_play_obj(0x4db,param_1);

        *(undefined4 *)(param_1 + 0xf4) = 0xc;

        goto code_r0x004e9829;

      }

      goto LAB_004e97c0;

    }

    *(undefined4 *)(param_1 + 0xe8) = 2;

    break;

  case 1:

  case 3:

    uVar9 = 0x6bf;

    goto LAB_004e981b;

  case 2:

    if (*(int *)(param_1 + 4) == 0x424) {

      *(undefined4 *)(param_1 + 0xe8) = 0;

      sound_play_obj(0x6bf,param_1);

      *(undefined4 *)(param_1 + 0xf4) = *(undefined4 *)(DAT_00632ed8 + 0xca0);

      goto code_r0x004e9829;

    }

    if (*(int *)(param_1 + 4) == 0x4ca) {

      *(undefined4 *)(param_1 + 0xe8) = 4;

      goto LAB_004e9799;

    }

    break;

  case 4:

    if (*(int *)(param_1 + 4) != 0x424) {

      if (*(int *)(param_1 + 4) == 0x2ae) {

        *(undefined4 *)(param_1 + 0xe8) = 2;

        sound_play_obj(0x6bf,param_1);

        *(undefined4 *)(param_1 + 0xf4) = *(undefined4 *)(DAT_00632ed8 + 0x5c8);

        goto code_r0x004e9829;

      }

LAB_004e9799:

      sound_play_obj(0x4db,param_1);

      *(undefined4 *)(param_1 + 0xf4) = 0xc;

      goto code_r0x004e9829;

    }

    *(undefined4 *)(param_1 + 0xe8) = 0;

LAB_004e97c0:

    sound_play_obj(0x6bf,param_1);

    *(undefined4 *)(param_1 + 0xf4) = *(undefined4 *)(DAT_00632ed8 + 0xca0);

    goto code_r0x004e9829;

  case 5:

    uVar9 = 0x4db;

LAB_004e981b:

    sound_play_obj(uVar9,param_1);

    *(undefined4 *)(param_1 + 0xf4) = 0;

  default:

    goto code_r0x004e9829;

  }

  sound_play_obj(0x6bf,param_1);

  *(undefined4 *)(param_1 + 0xf4) = *(undefined4 *)(DAT_00632ed8 + 0x5c8);

code_r0x004e9829:

  iVar6 = obj_health_ratio_update(iVar3);

  if (iVar6 != 0) {

    *(undefined4 *)(iVar3 + 0xf4) = 0;

  }

  return;

}

/* ===== cspec_004e9aa0 @ 0x004E9AA0 ===== */
void cspec_004e9aa0(undefined4 param_1,float param_2,int param_3,int param_4)



{

  undefined4 *puVar1;

  float fVar2;

  int iVar3;

  int iVar4;

  float10 fVar5;

  undefined4 uVar6;

  char *pcVar7;

  undefined4 uVar8;

  undefined1 *puVar9;

  undefined1 auStack_34 [4];

  undefined4 uStack_30;

  undefined4 uStack_2c;

  undefined4 uStack_28;

  

  if (*(float *)(param_3 + 0x1c0) <= *(float *)(param_3 + 0x278)) {

    return;

  }

  if ((param_4 == 0) || (iVar4 = *(int *)(param_4 + 0x274), *(int *)(param_4 + 0x274) == 0)) {

    iVar4 = DAT_00632a88;

  }

  *(int *)(param_3 + 0x274) = iVar4;

  *(undefined4 *)(param_3 + 0xe4) = 2;

  ai_d7_pairing(param_3,*(float *)(DAT_00632ed8 + 0xc9c) + 20.0);

  for (puVar1 = DAT_00632d6c; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {

    iVar4 = puVar1[3];

    iVar3 = ObjIsRipper(iVar4);

    if (((iVar3 != 0) &&

        (fVar2 = *(float *)(DAT_00632ed8 + 0xc9c) + 20.0,

        fVar5 = (float10)distancesq2d__FP3P3DT0(param_3 + 0xa0,iVar4 + 0xa0),

        fVar5 < (float10)fVar2 * (float10)fVar2)) && (*(int *)(*(int *)(iVar4 + 0x100) + 0xc) == 0))

    {

      *(undefined4 *)(*(int *)(iVar4 + 0x100) + 0xc) = *(undefined4 *)(param_3 + 0x274);

    }

  }

  param_2 = param_2 + *(float *)(param_3 + 0x278);

  *(float *)(param_3 + 0x278) = param_2;

  iVar4 = *(int *)(param_3 + 0xe8);

  if (param_2 < *(float *)(param_3 + 0x1c0)) {

    if (((iVar4 != 0) && (iVar4 != 1)) && ((iVar4 != 2 && (iVar4 != 3)))) {

      sound_play_obj(0x67b,param_3);

      return;

    }

    sound_play_obj(0x60f,param_3);

    return;

  }

  if ((iVar4 == 0) || (iVar4 == 1)) {

    uStack_30 = *(undefined4 *)(param_3 + 0xa0);

    uStack_2c = *(undefined4 *)(param_3 + 0xa4);

    uStack_28 = *(undefined4 *)(param_3 + 0xa8);

    pcVar7 = s_fx_minibarracks_00561af4;

  }

  else {

    if ((iVar4 != 2) && (iVar4 != 3)) {

      uStack_30 = *(undefined4 *)(param_3 + 0xa0);

      uStack_2c = *(undefined4 *)(param_3 + 0xa4);

      uStack_28 = *(undefined4 *)(param_3 + 0xa8);

      puVar9 = auStack_34;

      uVar8 = 8;

      pcVar7 = s_fx_ripperbarracks_00561b10;

      fx_get_free_effect__Fv();

      uVar6 = 0x67c;

      goto code_r0x004e9c47;

    }

    uStack_30 = *(undefined4 *)(param_3 + 0xa0);

    uStack_2c = *(undefined4 *)(param_3 + 0xa4);

    uStack_28 = *(undefined4 *)(param_3 + 0xa8);

    pcVar7 = s_fx_barracks_00561b04;

  }

  puVar9 = auStack_34;

  uVar8 = 8;

  fx_get_free_effect__Fv();

  uVar6 = 0x610;

code_r0x004e9c47:

  sound_play_3dpos(uVar6,param_3 + 0xa0,pcVar7,uVar8,puVar9);

  if (((*(int *)(param_3 + 0xe8) != 4) && (*(int *)(param_3 + 0xe8) != 5)) &&

     (((byte)*(undefined4 *)(param_3 + 0xdc) & 0xf) == 2)) {

    iVar4 = *(int *)(param_3 + 0xf4);

    while (0 < iVar4) {

      voice_event_trigger(param_3);

      iVar4 = *(int *)(param_3 + 0xf4) + -1;

      *(int *)(param_3 + 0xf4) = iVar4;

    }

  }

  object_destroy(param_3);

  return;

}

/* ===== FUN_004e9ce0 @ 0x004E9CE0 ===== */
void FUN_004e9ce0(int param_1,int param_2,int param_3)



{

  if (param_1 != 0) {

    if (param_2 != 0) {

      if (*(int *)(param_1 + 0xe4) != 3) {

        ObjectSetAnim(param_1,1,0x20,0,0,0);

      }

      if ((*(int *)(param_1 + 0xf4) == 0) && (*(int *)(param_1 + 0x274) == 0)) {

        *(undefined4 *)(param_1 + 0xe4) = 3;

        return;

      }

      *(undefined4 *)(param_1 + 0xe4) = 2;

      return;

    }

    if (*(int *)(param_1 + 0x274) != 0) {

      *(int *)(*(int *)(param_1 + 0x100) + param_3 * 4) = *(int *)(param_1 + 0x274);

      *(undefined4 *)(param_1 + 0x274) = 0;

    }

    *(undefined4 *)(param_1 + 0xec) = *(undefined4 *)(DAT_00632ed8 + 0xf4c);

    ObjectSetAnim(param_1,1,0x30,0,0,0);

    *(undefined4 *)(param_1 + 0xe4) = 1;

  }

  return;

}

/* ===== cspec_004e9d90 @ 0x004E9D90 ===== */
void cspec_004e9d90(float param_1)



{

  int iVar1;

  undefined4 *puVar2;

  bool bVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  float10 fVar8;

  float fStack_10;

  undefined4 uStack_c;

  undefined4 uStack_8;

  undefined4 uStack_4;

  

  iVar4 = (int)param_1;

  iVar1 = *(int *)((int)param_1 + 0x100);

  iVar7 = 0;

  if (DAT_00632e74 != 0) {

    return;

  }

  switch(*(undefined4 *)((int)param_1 + 0xe4)) {

  case 0:

    *(undefined4 *)((int)param_1 + 0x278) = 0;

    *(undefined4 *)((int)param_1 + 0x14) = 0x3f800000;

    ObjectSetAnim(param_1,1,0x84,0,0,0);

    object_animate_process(param_1,0);

    iVar5 = __ftol();

    if (0 < iVar5) {

      do {

        *(int *)((int)param_1 + 0xf4) = *(int *)((int)param_1 + 0xf4) + 1;

        iVar6 = object_allocate_type(0xd7,0x80000000);

        iVar5 = *(int *)(iVar6 + 0x100);

        playerobj_eval_refpt(param_1,iVar7,&uStack_c);

        object_set_location(iVar6,uStack_c,uStack_8,uStack_4);

        fVar8 = (float10)tracer_entry_angle(param_1,iVar7);

        *(float *)(iVar6 + 200) = (float)fVar8;

        *(undefined4 *)(iVar6 + 0xe8) = 4;

        *(float *)(iVar5 + 0x150) = param_1;

        *(int *)(iVar5 + 0x154) = iVar7;

        *(undefined4 *)(iVar5 + 0x158) = *(undefined4 *)(iVar6 + 200);

        if ((*(uint *)((int)param_1 + 0xd8) & 0x400) != 0) {

          *(uint *)(iVar6 + 0xd8) = *(uint *)(iVar6 + 0xd8) | 0x400;

        }

        *(int *)(iVar1 + iVar7 * 4) = iVar6;

        iVar7 = iVar7 + 1;

        iVar5 = __ftol();

      } while (iVar7 < iVar5);

    }

    iVar7 = *(int *)(DAT_00632ed8 + 0xf54);

    *(int *)(iVar1 + 0x20) = iVar7;

    iVar5 = __ftol();

    if (iVar7 < iVar5) {

      *(int *)(iVar1 + 0x20) = iVar5;

    }

    if (*(int *)((int)param_1 + 0xf4) == 0) {

      ObjectSetAnim(param_1,1,0x84,0,0,0);

      *(undefined4 *)((int)param_1 + 0x14) = 0x3f800000;

      *(undefined4 *)((int)param_1 + 0xe4) = 3;

    }

    else {

      ObjectSetAnim(param_1,1,0x84,0,0,0);

      *(undefined4 *)((int)param_1 + 0x14) = 0;

      *(undefined4 *)((int)param_1 + 0xe4) = 1;

    }

    break;

  case 1:

    if (*(float *)((int)param_1 + 0xec) < 0.0 == (*(float *)((int)param_1 + 0xec) == 0.0)) {

LAB_004ea0fd:

      fVar8 = (float10)FUN_00518b70(0,0);

      *(float *)((int)param_1 + 0xec) = (float)((float10)*(float *)((int)param_1 + 0xec) - fVar8);

      break;

    }

    if (*(int *)(iVar1 + 0x18) == 0) {

      if (*(int *)(iVar1 + 0x20) < *(int *)((int)param_1 + 0xf4)) {

        ObjectSetAnim(param_1,1,0x20,0,0,0);

        if ((*(int *)((int)param_1 + 0xf4) == 0) && (*(int *)((int)param_1 + 0x274) == 0)) {

          *(undefined4 *)((int)param_1 + 0xe4) = 3;

        }

        else {

          *(undefined4 *)((int)param_1 + 0xe4) = 2;

        }

        iVar7 = 0;

        do {

          if (*(int *)(iVar1 + iVar7 * 4) != 0) {

            *(undefined4 *)((int)param_1 + 0x274) = *(undefined4 *)(iVar1 + iVar7 * 4);

            *(undefined4 *)(iVar1 + iVar7 * 4) = 0;

            break;

          }

          iVar7 = iVar7 + 1;

        } while (iVar7 < 6);

      }

      break;

    }

    goto LAB_004ea0f2;

  case 2:

    iVar7 = *(int *)((int)param_1 + 0x274);

    if (iVar7 == 0) {

      *(undefined4 *)((int)param_1 + 0xec) = *(undefined4 *)(DAT_00632ed8 + 0xf4c);

      ObjectSetAnim(param_1,1,0x30,0,0,0);

      *(undefined4 *)((int)param_1 + 0xe4) = 1;

    }

    else if ((*(int *)(iVar1 + 0x18) == 0) && ((*(byte *)((int)param_1 + 0x30) & 2) != 0)) {

      *(uint *)(iVar7 + 0x1c8) = *(uint *)(iVar7 + 0x1c8) | 0xe00;

      *(uint *)(iVar7 + 0xd8) = *(uint *)(iVar7 + 0xd8) | 0x10;

      playerobj_eval_refpt

                (*(undefined4 *)(*(int *)(iVar7 + 0x100) + 0x150),

                 *(int *)(*(int *)(iVar7 + 0x100) + 0x154) + 6,&uStack_c);

      ai_clear_move_goal(iVar7);

      ai_move_force_goal(iVar7,&uStack_c);

      if ((*(uint *)(iVar7 + 0xe0) & 0x200) == 0) {

        ai_anim_play(iVar7,0x47,1,1,*(undefined4 *)(DAT_00632ed8 + 0xb38),0);

      }

      else if ((*(int *)(iVar7 + 0x10) != 0x8e) && (*(int *)(*(int *)(iVar7 + 8) + 0x240) != 0)) {

        ObjectSetAnim(iVar7,0x8e,0x21,1,*(float *)(DAT_00632ed8 + 0xb38) * *(float *)(iVar7 + 0xc4),

                      0x3e2aaaab);

        *(undefined4 *)(iVar7 + 0xe4) = 0xaf;

        break;

      }

      *(undefined4 *)(iVar7 + 0xe4) = 0xaf;

    }

    break;

  case 3:

    if (*(float *)((int)param_1 + 0xec) < 0.0 == (*(float *)((int)param_1 + 0xec) == 0.0))

    goto LAB_004ea0fd;

LAB_004ea0f2:

    barracks_logic(param_1);

  }

  if ((*(float *)((int)param_1 + 0xf0) < 0.0 == (*(float *)((int)param_1 + 0xf0) == 0.0)) ||

     (*(int *)((int)param_1 + 0x274) != 0)) {

    fVar8 = (float10)FUN_00518b70(0,0);

    *(float *)((int)param_1 + 0xf0) = (float)((float10)*(float *)((int)param_1 + 0xf0) - fVar8);

    return;

  }

  iVar1 = *(int *)((int)param_1 + 0x100);

  *(undefined4 *)(iVar1 + 0x18) = 0;

  fStack_10 = *(float *)(DAT_00632ed8 + 0xf48) * *(float *)(DAT_00632ed8 + 0xf48);

  bVar3 = false;

  puVar2 = DAT_00632d6c;

  do {

    if (puVar2 == (undefined4 *)0x0) {

      iVar7 = 0;

      do {

        iVar5 = *(int *)(iVar1 + iVar7 * 4);

        if (iVar5 != 0) {

          **(undefined4 **)(iVar5 + 0x100) = *(undefined4 *)(iVar1 + 0x18);

        }

        iVar7 = iVar7 + 1;

      } while (iVar7 < 6);

      *(undefined4 *)(iVar4 + 0xf0) = 0x3f800000;

      return;

    }

    iVar7 = puVar2[3];

    iVar5 = ObjIsPlayer(iVar7);

    if ((((iVar5 != 0) && ((*(uint *)(iVar7 + 0xd8) & 0x4000c000) == 0)) &&

        (*(float *)(iVar7 + 0x278) < *(float *)(iVar7 + 0x1c0))) &&

       ((iVar5 = ObjIsMecc(iVar7), iVar5 == 0 || ((*(uint *)(iVar7 + 0xe0) & 0x2000000) == 0)))) {

      iVar5 = iVar4 + 0xa0;

      fVar8 = (float10)FUN_0050a610(iVar5,iVar7 + 0xa0);

      param_1 = (float)fVar8;

      iVar6 = ObjIsKabuto(iVar7);

      if (iVar6 != 0) {

        param_1 = param_1 * 0.25;

      }

      if (param_1 <= fStack_10) {

        if (param_1 < 144.0) {

          bVar3 = true;

        }

        iVar6 = ObjIsKabuto(iVar7);

        if ((iVar6 != 0) && (param_1 < 10000.0)) {

          bVar3 = true;

        }

        if ((DAT_006328e8 - DAT_00632b44 < 1.0 == (DAT_006328e8 - DAT_00632b44 == 1.0)) ||

           (*(float *)(iVar1 + 0x1c) == DAT_00632b44)) {

LAB_004ea2ad:

          if (!bVar3) {

            dirfcalcp3d__FP3P3DT0(iVar5,iVar7 + 0xa0);

            iVar5 = LineOfSight(iVar4,iVar7);

            if (iVar5 == 0) goto LAB_004ea2df;

          }

        }

        else {

          *(float *)(iVar1 + 0x1c) = DAT_00632b44;

          fVar8 = (float10)distancesq2d__FP3P3DT0(iVar5,&DAT_00632b48);

          if ((float10)14400.0 <= fVar8) goto LAB_004ea2ad;

          bVar3 = true;

        }

        fStack_10 = param_1;

        *(int *)(iVar1 + 0x18) = iVar7;

      }

    }

LAB_004ea2df:

    puVar2 = (undefined4 *)*puVar2;

  } while( true );

}

/* ===== LineOfSight @ 0x004EA350 ===== */
/* PS2 candidate: LineOfSight (conf 0.606) */



void LineOfSight(int param_1,int param_2)



{

  undefined4 local_18;

  undefined4 local_14;

  float local_10;

  undefined4 local_c;

  undefined4 local_8;

  float local_4;

  

  if (param_2 == 0) {

    return;

  }

  local_c = *(undefined4 *)(param_1 + 0xa0);

  local_8 = *(undefined4 *)(param_1 + 0xa4);

  local_4 = *(float *)(param_1 + 0x1e8) * *(float *)(param_1 + 0xc4) + *(float *)(param_1 + 0xa8);

  local_18 = *(undefined4 *)(param_2 + 0xa0);

  local_14 = *(undefined4 *)(param_2 + 0xa4);

  local_10 = *(float *)(param_2 + 0x1e8) * *(float *)(param_2 + 0xc4) + *(float *)(param_2 + 0xa8);

  ai_class_filter(&local_c,&local_18,7,&DAT_00561478,0);

  return;

}

/* ===== barracks_logic @ 0x004EA3E0 ===== */
/* PS2 candidate: barracks_logic (conf 0.477) */



void barracks_logic(float param_1)



{

  int iVar1;

  undefined4 *puVar2;

  int iVar3;

  int iVar4;

  int *piVar5;

  int iVar6;

  float10 fVar7;

  float10 fVar8;

  undefined4 uVar9;

  float fVar10;

  undefined1 local_c [12];

  

  iVar3 = (int)param_1;

  if (5 < *(int *)((int)param_1 + 0xf4)) {

    return;

  }

  iVar1 = *(int *)((int)param_1 + 0x100);

  iVar6 = *(int *)(iVar1 + 0x18);

  if (iVar6 == 0) {

    return;

  }

  fVar10 = *(float *)(DAT_00632ed8 + 0xf50);

  fVar7 = (float10)FUN_0050a610(iVar6 + 0xa0,(int)param_1 + 0xa0);

  fVar8 = (float10)fVar10 * (float10)fVar10;

  if (fVar8 < fVar7 == (fVar8 == fVar7)) {

    return;

  }

  *(undefined4 *)((int)param_1 + 0xec) = 0x3f800000;

  iVar6 = 0;

  param_1 = -1.0;

  piVar5 = DAT_00632d6c;

  if (DAT_00632d6c == (int *)0x0) {

    return;

  }

  do {

    iVar4 = piVar5[3];

    if (((*(int *)(iVar4 + 4) == 0xd7) &&

        ((((*(int *)(iVar4 + 0xe8) == 2 || (*(int *)(iVar4 + 0xe8) == 0)) &&

          (fVar10 = *(float *)(*(int *)(iVar4 + 0x100) + 0x20), fVar10 < 0.0 == (fVar10 == 0.0))) &&

         (*(int *)(*(int *)(iVar4 + 0x100) + 0x134) == 0)))) &&

       ((fVar7 = (float10)FUN_0050a610(iVar4 + 0xa0,iVar3 + 0xa0), fVar7 < (float10)param_1 ||

        (iVar6 == 0)))) {

      param_1 = (float)fVar7;

      iVar6 = iVar4;

    }

    piVar5 = (int *)*piVar5;

  } while (piVar5 != (int *)0x0);

  if (iVar6 == 0) {

    return;

  }

  if (*(float *)(DAT_00632ed8 + 0x380) * *(float *)(DAT_00632ed8 + 0x380) <= param_1) {

    return;

  }

  iVar4 = 0;

  do {

    if (*(int *)(iVar1 + iVar4 * 4) == 0) break;

    iVar4 = iVar4 + 1;

  } while (iVar4 < 6);

  puVar2 = *(undefined4 **)(iVar6 + 0x100);

  puVar2[0x55] = iVar4;

  puVar2[0x54] = iVar3;

  *puVar2 = 0;

  playerobj_eval_refpt(iVar3,iVar4 + 6,local_c);

  ai_clear_move_goal(iVar6);

  ai_moveonly_set_goal(iVar6,local_c);

  if ((*(uint *)(iVar6 + 0xe0) & 0x200) == 0) {

    if ((*(int *)(iVar6 + 0x10) == 0x47) || (*(int *)(*(int *)(iVar6 + 8) + 0x124) == 0))

    goto LAB_004ea5de;

    fVar10 = *(float *)(DAT_00632ed8 + 0xb38) * *(float *)(iVar6 + 0xc4);

    uVar9 = 0x47;

  }

  else {

    if ((*(int *)(iVar6 + 0x10) == 0x8e) || (*(int *)(*(int *)(iVar6 + 8) + 0x240) == 0))

    goto LAB_004ea5de;

    fVar10 = *(float *)(DAT_00632ed8 + 0xb38) * *(float *)(iVar6 + 0xc4);

    uVar9 = 0x8e;

  }

  ObjectSetAnim(iVar6,uVar9,0x21,1,fVar10,0x3e2aaaab);

LAB_004ea5de:

  *(undefined4 *)(iVar6 + 0xe8) = 4;

  *(undefined4 *)(iVar6 + 0xe4) = 0xab;

  *(int *)(iVar3 + 0x274) = iVar6;

  if (*(int *)(iVar3 + 0xe4) != 3) {

    ObjectSetAnim(iVar3,1,0x20,0,0,0);

  }

  if ((*(int *)(iVar3 + 0xf4) == 0) && (*(int *)(iVar3 + 0x274) == 0)) {

    *(undefined4 *)(iVar3 + 0xe4) = 3;

    return;

  }

  *(undefined4 *)(iVar3 + 0xe4) = 2;

  return;

}

/* ===== cspec_004ea650 @ 0x004EA650 ===== */
void cspec_004ea650(undefined4 param_1,float param_2,int param_3)



{

  float fVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  undefined4 uVar6;

  

  if (*(float *)(param_3 + 0x278) < *(float *)(param_3 + 0x1c0)) {

    param_2 = param_2 + *(float *)(param_3 + 0x278);

    *(float *)(param_3 + 0x278) = param_2;

    if (*(float *)(param_3 + 0x1c0) <= param_2) {

      iVar2 = *(int *)(param_3 + 0x100);

      iVar4 = object_allocate_type(0x468,0x80000000);

      *(undefined4 *)(iVar4 + 0xa0) = *(undefined4 *)(param_3 + 0xa0);

      *(undefined4 *)(iVar4 + 0xa4) = *(undefined4 *)(param_3 + 0xa4);

      *(undefined4 *)(iVar4 + 0xa8) = *(undefined4 *)(param_3 + 0xa8);

      *(undefined4 *)(iVar4 + 200) = *(undefined4 *)(param_3 + 200);

      *(undefined4 *)(iVar4 + 0xc4) = *(undefined4 *)(param_3 + 0xc4);

      fx_get_free_effect__Fv();

      iVar4 = 0;

      do {

        iVar3 = *(int *)(iVar2 + iVar4 * 4);

        if ((iVar3 != 0) && (*(float *)(iVar3 + 0x278) < *(float *)(iVar3 + 0x1c0))) {

          iVar5 = crt_rand_scaled(0);

          iVar3 = *(int *)(iVar2 + iVar4 * 4);

          if (iVar5 == 0) {

            if ((*(int *)(iVar3 + 0x10) != 0xa3) && (*(int *)(*(int *)(iVar3 + 8) + 0x294) != 0)) {

              fVar1 = *(float *)(iVar3 + 0xc4);

              uVar6 = 0xa3;

              goto code_r0x004ea7ae;

            }

          }

          else if ((*(int *)(iVar3 + 0x10) != 0xa2) && (*(int *)(*(int *)(iVar3 + 8) + 0x290) != 0))

          {

            fVar1 = *(float *)(iVar3 + 0xc4);

            uVar6 = 0xa2;

code_r0x004ea7ae:

            ObjectSetAnim(iVar3,uVar6,0x20,0,fVar1 * 0.0,0x3e2aaaab);

          }

          *(undefined4 *)(*(int *)(iVar2 + iVar4 * 4) + 0xe4) = 0xb0;

          *(undefined4 *)(iVar2 + iVar4 * 4) = 0;

        }

        iVar4 = iVar4 + 1;

        if (5 < iVar4) {

          sound_play_3dpos(0x610,(undefined4 *)(param_3 + 0xa0));

          object_destroy(param_3);

          return;

        }

      } while( true );

    }

    sound_play_obj(0x60f,param_3);

  }

  return;

}

/* ===== FUN_004ea810 @ 0x004EA810 ===== */
void FUN_004ea810(int param_1)



{

  int *piVar1;

  int iVar2;

  int *piVar3;

  

  piVar1 = *(int **)(param_1 + 0x100);

  *(undefined4 *)(param_1 + 0xf4) = 0;

  iVar2 = 6;

  piVar3 = piVar1;

  do {

    obj_ptr_clear_if_dead(piVar3);

    if (*piVar3 != 0) {

      *(int *)(param_1 + 0xf4) = *(int *)(param_1 + 0xf4) + 1;

    }

    piVar3 = piVar3 + 1;

    iVar2 = iVar2 + -1;

  } while (iVar2 != 0);

  if ((*(int *)(param_1 + 0xf4) == 0) && (*(int *)(param_1 + 0xe4) == 1)) {

    ObjectSetAnim(param_1,1,0x20,0,0,0);

    if ((*(int *)(param_1 + 0xf4) == 0) && (*(int *)(param_1 + 0x274) == 0)) {

      *(undefined4 *)(param_1 + 0xe4) = 3;

      obj_ptr_clear_if_dead(piVar1 + 6);

      return;

    }

    *(undefined4 *)(param_1 + 0xe4) = 2;

  }

  obj_ptr_clear_if_dead(piVar1 + 6);

  return;

}

/* ===== comm_packet_big @ 0x004EA8C0 ===== */
void comm_packet_big(int param_1)



{

  undefined4 *puVar1;

  int *piVar2;

  int iVar3;

  int iVar4;

  int *piVar5;

  int iVar6;

  int iVar7;

  float10 fVar8;

  float10 fVar9;

  int local_c [3];

  

  iVar3 = dialog_level_is_base();

  iVar4 = DAT_006330e4;

  if (iVar3 == 0) {

    *(undefined4 *)(param_1 + 0xa0) = *(undefined4 *)(DAT_006330e4 + 0x88);

    *(undefined4 *)(param_1 + 0xa4) = *(undefined4 *)(iVar4 + 0x8c);

    *(undefined4 *)(param_1 + 0xa8) = *(undefined4 *)(iVar4 + 0x90);

    *(undefined4 *)(param_1 + 200) = *(undefined4 *)(DAT_006330e4 + 0x94);

    return;

  }

  iVar4 = comm_0052ab50(*(uint *)(param_1 + 0x188) & 0xff);

  iVar4 = iVar4 + -1;

  switch(DAT_00632f10) {

  case 0:

    local_c[0] = 1;

    local_c[1] = 2;

    local_c[2] = 0xffffffff;

    break;

  case 1:

    local_c[0] = 3;

    local_c[1] = 4;

    local_c[2] = 0xffffffff;

    break;

  case 2:

    local_c[0] = 1;

    local_c[2] = 0xffffffff;

    goto LAB_004ea983;

  case 3:

    local_c[0] = 1;

    goto LAB_004ea97b;

  case 4:

    local_c[0] = 1;

    local_c[1] = 0xffffffff;

    local_c[2] = 0x1b;

    break;

  case 5:

    local_c[0] = -1;

LAB_004ea97b:

    local_c[2] = 0x1b;

LAB_004ea983:

    local_c[1] = 3;

  }

  iVar3 = 0;

  piVar5 = DAT_00632d68;

  if (DAT_00632d68 != (int *)0x0) {

    do {

      iVar7 = piVar5[3];

      if (((*(uint *)(iVar7 + 0x1c8) & 0x8000000) != 0) &&

         (*(int *)(iVar7 + 0xe8) == local_c[iVar4])) {

        iVar3 = iVar3 + 1;

      }

      piVar5 = (int *)*piVar5;

    } while (piVar5 != (int *)0x0);

    if (iVar3 != 0) {

      iVar6 = crt_rand_scaled(iVar3);

      iVar3 = 0;

      for (piVar5 = DAT_00632d68; puVar1 = DAT_00632d6c, piVar5 != (int *)0x0;

          piVar5 = (int *)*piVar5) {

        iVar7 = piVar5[3];

        if (((*(uint *)(iVar7 + 0x1c8) & 0x8000000) != 0) &&

           (*(int *)(iVar7 + 0xe8) == local_c[iVar4])) {

          if (iVar3 == iVar6) break;

          iVar3 = iVar3 + 1;

        }

      }

      do {

        if (puVar1 == (undefined4 *)0x0) goto LAB_004eaa73;

        iVar3 = puVar1[3];

        if (((((*(uint *)(iVar3 + 0xd8) & 0x4000c000) == 0) &&

             (*(float *)(iVar3 + 0x278) < *(float *)(iVar3 + 0x1c0))) && (iVar3 != param_1)) &&

           (fVar8 = (float10)FUN_0050a610(iVar3 + 0xa0,iVar7 + 0xa0),

           fVar9 = (float10)*(float *)(iVar3 + 0x154) + (float10)*(float *)(param_1 + 0x154),

           piVar5 = DAT_00632d68, fVar8 < fVar9 * fVar9)) goto joined_r0x004eaaaf;

        puVar1 = (undefined4 *)*puVar1;

      } while( true );

    }

  }

LAB_004eab8c:

  iVar4 = DAT_006330e4;

  *(undefined4 *)(param_1 + 0xa0) = *(undefined4 *)(DAT_006330e4 + 0x88);

  *(undefined4 *)(param_1 + 0xa4) = *(undefined4 *)(iVar4 + 0x8c);

  *(undefined4 *)(param_1 + 0xa8) = *(undefined4 *)(iVar4 + 0x90);

  *(undefined4 *)(param_1 + 200) = *(undefined4 *)(DAT_006330e4 + 0x94);

  return;

joined_r0x004eaaaf:

  for (; piVar2 = DAT_00632d68, piVar5 != (int *)0x0; piVar5 = (int *)*piVar5) {

    iVar7 = piVar5[3];

    if (((*(uint *)(iVar7 + 0x1c8) & 0x8000000) != 0) &&

       (puVar1 = DAT_00632d6c, *(int *)(iVar7 + 0xe8) == local_c[iVar4])) {

      while( true ) {

        if (puVar1 == (undefined4 *)0x0) goto LAB_004eaa73;

        iVar3 = puVar1[3];

        if ((((*(uint *)(iVar3 + 0xd8) & 0x4000c000) == 0) &&

            (*(float *)(iVar3 + 0x278) < *(float *)(iVar3 + 0x1c0))) &&

           ((iVar3 != param_1 &&

            (fVar8 = (float10)FUN_0050a610(iVar3 + 0xa0,iVar7 + 0xa0),

            fVar9 = (float10)*(float *)(iVar3 + 0x154) + (float10)*(float *)(param_1 + 0x154),

            fVar8 < fVar9 * fVar9)))) break;

        puVar1 = (undefined4 *)*puVar1;

      }

    }

  }

  for (; piVar2 != (int *)0x0; piVar2 = (int *)*piVar2) {

    iVar7 = piVar2[3];

    if (((*(uint *)(iVar7 + 0x1c8) & 0x8000000) != 0) && (*(int *)(iVar7 + 0xe8) == local_c[iVar4]))

    {

LAB_004eaa73:

      *(undefined4 *)(param_1 + 0xa0) = *(undefined4 *)(iVar7 + 0xa0);

      *(undefined4 *)(param_1 + 0xa4) = *(undefined4 *)(iVar7 + 0xa4);

      *(undefined4 *)(param_1 + 0xa8) = *(undefined4 *)(iVar7 + 0xa8);

      *(undefined4 *)(param_1 + 200) = *(undefined4 *)(iVar7 + 200);

      return;

    }

  }

  goto LAB_004eab8c;

}

/* ===== game_mode_update @ 0x004EB7C0 ===== */
void game_mode_update(void)



{

  undefined4 *puVar1;

  int *piVar2;

  int iVar3;

  int iVar4;

  int *piVar5;

  int iVar6;

  int iVar7;

  undefined4 uVar8;

  int iVar9;

  float10 fVar10;

  float10 fVar11;

  int local_c [3];

  

  switch(DAT_00632f10) {

  case 0:

    break;

  case 1:

LAB_004eac20:

    iVar6 = DAT_00632a88;

    iVar3 = object_find(3);

    if (iVar3 == 0) {

      return;

    }

    if (iVar6 == 0) {

      return;

    }

    object_destroy_specialtype(iVar6);

    object_copy_personality(iVar6,iVar3);

    *(undefined4 *)(iVar6 + 0xcc) = 0;

    camera_fov_update();

    DAT_00633108 = 1;

    object_setup_specialtype(iVar6);

    *(uint *)(iVar6 + 0x1c8) = *(uint *)(iVar6 + 0x1c8) | 1;

    comm_0052b780_user_7(iVar6);

    iVar3 = comm_0052ab50(*(uint *)(iVar6 + 0x188) & 0xff);

    *(int *)(iVar6 + 0x18c) = iVar3 + 1;

    main_linkage_004704e0(&DAT_00632d78,iVar6);

    main_linkage_004704e0(&DAT_00632d70,iVar6);

    main_linkage_004704e0(&DAT_00632d74,iVar6);

    main_linkage_00470250(&DAT_00632d74,iVar6);

    iVar3 = dialog_level_is_base();

    if (iVar3 == 0) goto LAB_004eaf80;

    iVar3 = comm_0052ab50(*(uint *)(iVar6 + 0x188) & 0xff);

    iVar3 = iVar3 + -1;

    switch(DAT_00632f10) {

    case 0:

      local_c[0] = 1;

      local_c[1] = 2;

      local_c[2] = 0xffffffff;

      break;

    case 1:

      local_c[0] = 3;

      local_c[1] = 4;

      local_c[2] = 0xffffffff;

      break;

    case 2:

      local_c[0] = 1;

      local_c[2] = 0xffffffff;

      goto LAB_004ead75;

    case 3:

      local_c[0] = 1;

      goto LAB_004ead6d;

    case 4:

      local_c[0] = 1;

      local_c[1] = 0xffffffff;

      local_c[2] = 0x1b;

      break;

    case 5:

      local_c[0] = -1;

LAB_004ead6d:

      local_c[2] = 0x1b;

LAB_004ead75:

      local_c[1] = 3;

    }

    iVar7 = 0;

    piVar5 = DAT_00632d68;

    if (DAT_00632d68 != (int *)0x0) {

      do {

        iVar9 = piVar5[3];

        if (((*(uint *)(iVar9 + 0x1c8) & 0x8000000) != 0) &&

           (*(int *)(iVar9 + 0xe8) == local_c[iVar3])) {

          iVar7 = iVar7 + 1;

        }

        piVar5 = (int *)*piVar5;

      } while (piVar5 != (int *)0x0);

      if (iVar7 != 0) {

        iVar4 = crt_rand_scaled(iVar7);

        iVar7 = 0;

        for (piVar5 = DAT_00632d68; puVar1 = DAT_00632d6c, piVar5 != (int *)0x0;

            piVar5 = (int *)*piVar5) {

          iVar9 = piVar5[3];

          if (((*(uint *)(iVar9 + 0x1c8) & 0x8000000) != 0) &&

             (*(int *)(iVar9 + 0xe8) == local_c[iVar3])) {

            if (iVar7 == iVar4) break;

            iVar7 = iVar7 + 1;

          }

        }

        do {

          if (puVar1 == (undefined4 *)0x0) goto LAB_004eae58;

          iVar7 = puVar1[3];

          if (((((*(uint *)(iVar7 + 0xd8) & 0x4000c000) == 0) &&

               (*(float *)(iVar7 + 0x278) < *(float *)(iVar7 + 0x1c0))) && (iVar7 != iVar6)) &&

             (fVar10 = (float10)FUN_0050a610(iVar7 + 0xa0,iVar9 + 0xa0),

             fVar11 = (float10)*(float *)(iVar7 + 0x154) + (float10)*(float *)(iVar6 + 0x154),

             piVar5 = DAT_00632d68, fVar10 < fVar11 * fVar11)) goto joined_r0x004eae8f;

          puVar1 = (undefined4 *)*puVar1;

        } while( true );

      }

    }

LAB_004eaf80:

    iVar3 = DAT_006330e4;

    *(undefined4 *)(iVar6 + 0xa0) = *(undefined4 *)(DAT_006330e4 + 0x88);

    *(undefined4 *)(iVar6 + 0xa4) = *(undefined4 *)(iVar3 + 0x8c);

    *(undefined4 *)(iVar6 + 0xa8) = *(undefined4 *)(iVar3 + 0x90);

    uVar8 = *(undefined4 *)(DAT_006330e4 + 0x94);

LAB_004eafad:

    *(undefined4 *)(iVar6 + 200) = uVar8;

    *(undefined4 *)(iVar6 + 0x10) = 1;

    *(undefined4 *)(iVar6 + 0xd4) = 0;

    *(uint *)(iVar6 + 0x30) = *(uint *)(iVar6 + 0x30) | 1;

    object_copy_posdirinfo(iVar6);

    return;

  case 2:

    local_c[2] = 0x4eb7d6;

    local_c[2] = comm_0052b430();

    local_c[1] = 0x4eb7dc;

    iVar6 = comm_0052ab50();

    if (iVar6 != 1) goto LAB_004eac20;

    break;

  case 3:

    local_c[2] = 0x4eb7ee;

    local_c[2] = comm_0052b430();

    local_c[1] = 0x4eb7f4;

    iVar6 = comm_0052ab50();

    if (iVar6 != 1) goto LAB_004eb827;

    goto LAB_004eb3e0;

  case 4:

    local_c[2] = 0x4eb806;

    local_c[2] = comm_0052b430();

    local_c[1] = 0x4eb80c;

    iVar6 = comm_0052ab50();

    if (iVar6 != 1) goto LAB_004eb000;

    break;

  case 5:

    local_c[2] = 0x4eb81e;

    local_c[2] = comm_0052b430();

    local_c[1] = 0x4eb824;

    iVar6 = comm_0052ab50();

LAB_004eb827:

    if (iVar6 == 2) goto LAB_004eac20;

LAB_004eb000:

    iVar6 = DAT_00632a88;

    iVar3 = object_find(1);

    if (iVar3 == 0) {

      return;

    }

    if (iVar6 == 0) {

      return;

    }

    object_destroy_specialtype(iVar6);

    object_copy_personality(iVar6,iVar3);

    *(undefined4 *)(iVar6 + 0xcc) = 0;

    camera_fov_update();

    DAT_00633108 = 1;

    object_setup_specialtype(iVar6);

    *(uint *)(iVar6 + 0x1c8) = *(uint *)(iVar6 + 0x1c8) | 1;

    comm_0052b780_user_7(iVar6);

    iVar3 = comm_0052ab50(*(uint *)(iVar6 + 0x188) & 0xff);

    *(int *)(iVar6 + 0x18c) = iVar3 + 1;

    main_linkage_004704e0(&DAT_00632d78,iVar6);

    main_linkage_004704e0(&DAT_00632d70,iVar6);

    main_linkage_004704e0(&DAT_00632d74,iVar6);

    main_linkage_00470250(&DAT_00632d78,iVar6);

    iVar3 = dialog_level_is_base();

    if (iVar3 == 0) goto LAB_004eb365;

    iVar3 = comm_0052ab50(*(uint *)(iVar6 + 0x188) & 0xff);

    iVar3 = iVar3 + -1;

    switch(DAT_00632f10) {

    case 0:

      local_c[0] = 1;

      local_c[1] = 2;

      local_c[2] = 0xffffffff;

      break;

    case 1:

      local_c[0] = 3;

      local_c[1] = 4;

      local_c[2] = 0xffffffff;

      break;

    case 2:

      local_c[0] = 1;

      local_c[2] = 0xffffffff;

      goto LAB_004eb154;

    case 3:

      local_c[0] = 1;

      goto LAB_004eb14c;

    case 4:

      local_c[0] = 1;

      local_c[1] = 0xffffffff;

      local_c[2] = 0x1b;

      break;

    case 5:

      local_c[0] = -1;

LAB_004eb14c:

      local_c[2] = 0x1b;

LAB_004eb154:

      local_c[1] = 3;

    }

    iVar7 = 0;

    piVar5 = DAT_00632d68;

    if (DAT_00632d68 != (int *)0x0) {

      do {

        iVar9 = piVar5[3];

        if (((*(uint *)(iVar9 + 0x1c8) & 0x8000000) != 0) &&

           (*(int *)(iVar9 + 0xe8) == local_c[iVar3])) {

          iVar7 = iVar7 + 1;

        }

        piVar5 = (int *)*piVar5;

      } while (piVar5 != (int *)0x0);

      if (iVar7 != 0) {

        iVar4 = crt_rand_scaled(iVar7);

        iVar7 = 0;

        for (piVar5 = DAT_00632d68; puVar1 = DAT_00632d6c, piVar5 != (int *)0x0;

            piVar5 = (int *)*piVar5) {

          iVar9 = piVar5[3];

          if (((*(uint *)(iVar9 + 0x1c8) & 0x8000000) != 0) &&

             (*(int *)(iVar9 + 0xe8) == local_c[iVar3])) {

            if (iVar7 == iVar4) break;

            iVar7 = iVar7 + 1;

          }

        }

        do {

          if (puVar1 == (undefined4 *)0x0) goto LAB_004eb241;

          iVar7 = puVar1[3];

          if (((((*(uint *)(iVar7 + 0xd8) & 0x4000c000) == 0) &&

               (*(float *)(iVar7 + 0x278) < *(float *)(iVar7 + 0x1c0))) && (iVar7 != iVar6)) &&

             (fVar10 = (float10)FUN_0050a610(iVar7 + 0xa0,iVar9 + 0xa0),

             fVar11 = (float10)*(float *)(iVar7 + 0x154) + (float10)*(float *)(iVar6 + 0x154),

             piVar5 = DAT_00632d68, fVar10 < fVar11 * fVar11)) goto joined_r0x004eb278;

          puVar1 = (undefined4 *)*puVar1;

        } while( true );

      }

    }

LAB_004eb365:

    iVar3 = DAT_006330e4;

    *(undefined4 *)(iVar6 + 0xa0) = *(undefined4 *)(DAT_006330e4 + 0x88);

    *(undefined4 *)(iVar6 + 0xa4) = *(undefined4 *)(iVar3 + 0x8c);

    *(undefined4 *)(iVar6 + 0xa8) = *(undefined4 *)(iVar3 + 0x90);

    uVar8 = *(undefined4 *)(DAT_006330e4 + 0x94);

LAB_004eb392:

    *(undefined4 *)(iVar6 + 200) = uVar8;

    *(undefined4 *)(iVar6 + 0x10) = 1;

    *(undefined4 *)(iVar6 + 0xd4) = 0;

    *(uint *)(iVar6 + 0x30) = *(uint *)(iVar6 + 0x30) | 1;

    object_copy_posdirinfo(iVar6);

    return;

  default:

    return;

  }

LAB_004eb3e0:

  iVar6 = DAT_00632a88;

  iVar3 = object_find(2);

  if (iVar3 == 0) {

    return;

  }

  if (iVar6 == 0) {

    return;

  }

  object_destroy_specialtype(iVar6);

  object_copy_personality(iVar6,iVar3);

  *(undefined4 *)(iVar6 + 0xcc) = 0;

  camera_fov_update();

  DAT_00633108 = 1;

  object_setup_specialtype(iVar6);

  *(uint *)(iVar6 + 0x1c8) = *(uint *)(iVar6 + 0x1c8) | 1;

  comm_0052b780_user_7(iVar6);

  iVar3 = comm_0052ab50(*(uint *)(iVar6 + 0x188) & 0xff);

  *(int *)(iVar6 + 0x18c) = iVar3 + 1;

  main_linkage_004704e0(&DAT_00632d78,iVar6);

  main_linkage_004704e0(&DAT_00632d70,iVar6);

  main_linkage_004704e0(&DAT_00632d74,iVar6);

  main_linkage_00470250(&DAT_00632d70,iVar6);

  iVar3 = dialog_level_is_base();

  if (iVar3 == 0) goto LAB_004eb745;

  iVar3 = comm_0052ab50(*(uint *)(iVar6 + 0x188) & 0xff);

  iVar3 = iVar3 + -1;

  switch(DAT_00632f10) {

  case 0:

    local_c[0] = 1;

    local_c[1] = 2;

    local_c[2] = 0xffffffff;

    break;

  case 1:

    local_c[0] = 3;

    local_c[1] = 4;

    local_c[2] = 0xffffffff;

    break;

  case 2:

    local_c[0] = 1;

    local_c[2] = 0xffffffff;

    goto LAB_004eb535;

  case 3:

    local_c[0] = 1;

    goto LAB_004eb52d;

  case 4:

    local_c[0] = 1;

    local_c[1] = 0xffffffff;

    local_c[2] = 0x1b;

    break;

  case 5:

    local_c[0] = -1;

LAB_004eb52d:

    local_c[2] = 0x1b;

LAB_004eb535:

    local_c[1] = 3;

  }

  iVar7 = 0;

  piVar5 = DAT_00632d68;

  if (DAT_00632d68 != (int *)0x0) {

    do {

      iVar9 = piVar5[3];

      if (((*(uint *)(iVar9 + 0x1c8) & 0x8000000) != 0) &&

         (*(int *)(iVar9 + 0xe8) == local_c[iVar3])) {

        iVar7 = iVar7 + 1;

      }

      piVar5 = (int *)*piVar5;

    } while (piVar5 != (int *)0x0);

    if (iVar7 != 0) {

      iVar4 = crt_rand_scaled(iVar7);

      iVar7 = 0;

      for (piVar5 = DAT_00632d68; puVar1 = DAT_00632d6c, piVar5 != (int *)0x0;

          piVar5 = (int *)*piVar5) {

        iVar9 = piVar5[3];

        if (((*(uint *)(iVar9 + 0x1c8) & 0x8000000) != 0) &&

           (*(int *)(iVar9 + 0xe8) == local_c[iVar3])) {

          if (iVar7 == iVar4) break;

          iVar7 = iVar7 + 1;

        }

      }

      do {

        if (puVar1 == (undefined4 *)0x0) goto LAB_004eb621;

        iVar7 = puVar1[3];

        if (((((*(uint *)(iVar7 + 0xd8) & 0x4000c000) == 0) &&

             (*(float *)(iVar7 + 0x278) < *(float *)(iVar7 + 0x1c0))) && (iVar7 != iVar6)) &&

           (fVar10 = (float10)FUN_0050a610(iVar7 + 0xa0,iVar9 + 0xa0),

           fVar11 = (float10)*(float *)(iVar7 + 0x154) + (float10)*(float *)(iVar6 + 0x154),

           piVar5 = DAT_00632d68, fVar10 < fVar11 * fVar11)) goto joined_r0x004eb658;

        puVar1 = (undefined4 *)*puVar1;

      } while( true );

    }

  }

LAB_004eb745:

  iVar3 = DAT_006330e4;

  *(undefined4 *)(iVar6 + 0xa0) = *(undefined4 *)(DAT_006330e4 + 0x88);

  *(undefined4 *)(iVar6 + 0xa4) = *(undefined4 *)(iVar3 + 0x8c);

  *(undefined4 *)(iVar6 + 0xa8) = *(undefined4 *)(iVar3 + 0x90);

  uVar8 = *(undefined4 *)(DAT_006330e4 + 0x94);

LAB_004eb772:

  *(undefined4 *)(iVar6 + 200) = uVar8;

  *(undefined4 *)(iVar6 + 0x10) = 1;

  *(undefined4 *)(iVar6 + 0xd4) = 0;

  *(uint *)(iVar6 + 0x30) = *(uint *)(iVar6 + 0x30) | 1;

  object_copy_posdirinfo(iVar6);

  return;

joined_r0x004eb278:

  for (; piVar2 = DAT_00632d68, piVar5 != (int *)0x0; piVar5 = (int *)*piVar5) {

    iVar9 = piVar5[3];

    if (((*(uint *)(iVar9 + 0x1c8) & 0x8000000) != 0) &&

       (puVar1 = DAT_00632d6c, *(int *)(iVar9 + 0xe8) == local_c[iVar3])) {

      while( true ) {

        if (puVar1 == (undefined4 *)0x0) goto LAB_004eb241;

        iVar7 = puVar1[3];

        if ((((*(uint *)(iVar7 + 0xd8) & 0x4000c000) == 0) &&

            (*(float *)(iVar7 + 0x278) < *(float *)(iVar7 + 0x1c0))) &&

           ((iVar7 != iVar6 &&

            (fVar10 = (float10)FUN_0050a610(iVar7 + 0xa0,iVar9 + 0xa0),

            fVar11 = (float10)*(float *)(iVar7 + 0x154) + (float10)*(float *)(iVar6 + 0x154),

            fVar10 < fVar11 * fVar11)))) break;

        puVar1 = (undefined4 *)*puVar1;

      }

    }

  }

  for (; piVar2 != (int *)0x0; piVar2 = (int *)*piVar2) {

    iVar9 = piVar2[3];

    if (((*(uint *)(iVar9 + 0x1c8) & 0x8000000) != 0) && (*(int *)(iVar9 + 0xe8) == local_c[iVar3]))

    goto LAB_004eb241;

  }

  goto LAB_004eb365;

LAB_004eb241:

  *(undefined4 *)(iVar6 + 0xa0) = *(undefined4 *)(iVar9 + 0xa0);

  *(undefined4 *)(iVar6 + 0xa4) = *(undefined4 *)(iVar9 + 0xa4);

  *(undefined4 *)(iVar6 + 0xa8) = *(undefined4 *)(iVar9 + 0xa8);

  uVar8 = *(undefined4 *)(iVar9 + 200);

  goto LAB_004eb392;

joined_r0x004eae8f:

  for (; piVar2 = DAT_00632d68, piVar5 != (int *)0x0; piVar5 = (int *)*piVar5) {

    iVar9 = piVar5[3];

    if (((*(uint *)(iVar9 + 0x1c8) & 0x8000000) != 0) &&

       (puVar1 = DAT_00632d6c, *(int *)(iVar9 + 0xe8) == local_c[iVar3])) {

      while( true ) {

        if (puVar1 == (undefined4 *)0x0) goto LAB_004eae58;

        iVar7 = puVar1[3];

        if ((((*(uint *)(iVar7 + 0xd8) & 0x4000c000) == 0) &&

            (*(float *)(iVar7 + 0x278) < *(float *)(iVar7 + 0x1c0))) &&

           ((iVar7 != iVar6 &&

            (fVar10 = (float10)FUN_0050a610(iVar7 + 0xa0,iVar9 + 0xa0),

            fVar11 = (float10)*(float *)(iVar7 + 0x154) + (float10)*(float *)(iVar6 + 0x154),

            fVar10 < fVar11 * fVar11)))) break;

        puVar1 = (undefined4 *)*puVar1;

      }

    }

  }

  for (; piVar2 != (int *)0x0; piVar2 = (int *)*piVar2) {

    iVar9 = piVar2[3];

    if (((*(uint *)(iVar9 + 0x1c8) & 0x8000000) != 0) && (*(int *)(iVar9 + 0xe8) == local_c[iVar3]))

    goto LAB_004eae58;

  }

  goto LAB_004eaf80;

LAB_004eae58:

  *(undefined4 *)(iVar6 + 0xa0) = *(undefined4 *)(iVar9 + 0xa0);

  *(undefined4 *)(iVar6 + 0xa4) = *(undefined4 *)(iVar9 + 0xa4);

  *(undefined4 *)(iVar6 + 0xa8) = *(undefined4 *)(iVar9 + 0xa8);

  uVar8 = *(undefined4 *)(iVar9 + 200);

  goto LAB_004eafad;

joined_r0x004eb658:

  for (; piVar2 = DAT_00632d68, piVar5 != (int *)0x0; piVar5 = (int *)*piVar5) {

    iVar9 = piVar5[3];

    if (((*(uint *)(iVar9 + 0x1c8) & 0x8000000) != 0) &&

       (puVar1 = DAT_00632d6c, *(int *)(iVar9 + 0xe8) == local_c[iVar3])) {

      while( true ) {

        if (puVar1 == (undefined4 *)0x0) goto LAB_004eb621;

        iVar7 = puVar1[3];

        if ((((*(uint *)(iVar7 + 0xd8) & 0x4000c000) == 0) &&

            (*(float *)(iVar7 + 0x278) < *(float *)(iVar7 + 0x1c0))) &&

           ((iVar7 != iVar6 &&

            (fVar10 = (float10)FUN_0050a610(iVar7 + 0xa0,iVar9 + 0xa0),

            fVar11 = (float10)*(float *)(iVar7 + 0x154) + (float10)*(float *)(iVar6 + 0x154),

            fVar10 < fVar11 * fVar11)))) break;

        puVar1 = (undefined4 *)*puVar1;

      }

    }

  }

  for (; piVar2 != (int *)0x0; piVar2 = (int *)*piVar2) {

    iVar9 = piVar2[3];

    if (((*(uint *)(iVar9 + 0x1c8) & 0x8000000) != 0) && (*(int *)(iVar9 + 0xe8) == local_c[iVar3]))

    goto LAB_004eb621;

  }

  goto LAB_004eb745;

LAB_004eb621:

  *(undefined4 *)(iVar6 + 0xa0) = *(undefined4 *)(iVar9 + 0xa0);

  *(undefined4 *)(iVar6 + 0xa4) = *(undefined4 *)(iVar9 + 0xa4);

  *(undefined4 *)(iVar6 + 0xa8) = *(undefined4 *)(iVar9 + 0xa8);

  uVar8 = *(undefined4 *)(iVar9 + 200);

  goto LAB_004eb772;

}

/* ===== match_start_entry @ 0x004EB850 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void match_start_entry(void)



{

  int iVar1;

  int iVar2;

  int iVar3;

  

  iVar3 = 0;

  DAT_00632b94 = 0;

  DAT_00632b98 = 0;

  DAT_00632b9c = 0;

  DAT_005a8598 = 0;

  DAT_005a859c = 0;

  DAT_005a85a0 = 0;

  _DAT_005a85a4 = 0;

  _DAT_005a85a8 = 0;

  iVar1 = dialog_level_is_base();

  if (iVar1 != 0) {

    _DAT_00632b58 = 0;

    return;

  }

  iVar1 = 0;

  do {

    iVar2 = match(iVar3 + 0x1210 + DAT_006330e4,s_start_00561b38);

    if (iVar2 != 0) {

      flick_file_load_state(iVar1 * 0x20 + 0x210 + DAT_006330e4);

      return;

    }

    iVar3 = iVar3 + 0x20;

    iVar1 = iVar1 + 1;

  } while (iVar3 < 0x1000);

  return;

}

/* ===== FUN_004eb8f0 @ 0x004EB8F0 ===== */
void FUN_004eb8f0(void)



{

  if (DAT_005a8598 != (code *)0x0) {

                    /* WARNING: Could not recover jumptable at 0x004eb8f9. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    (*DAT_005a8598)();

    return;

  }

  return;

}

/* ===== match_start_big @ 0x004EB900 ===== */
void match_start_big(void)



{

  int iVar1;

  byte bVar2;

  int iVar3;

  int iVar4;

  uint uVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  int local_8;

  

  bVar2 = 0;

  local_8 = 0;

  iVar4 = DAT_006330e4;

  iVar8 = DAT_00632a88;

  do {

    if ((*(char *)(local_8 + 0x1210 + iVar4) != '\0') &&

       (uVar5 = 1 << (bVar2 & 0x1f), (DAT_00632b9c & uVar5) == 0)) {

      iVar6 = 0;

      iVar3 = iVar4;

      if (0 < *(int *)(iVar4 + 0x200)) {

        iVar7 = 0;

        do {

          iVar1 = match(*(int *)(iVar3 + 0x204) + iVar7,local_8 + 0x1210 + iVar4);

          iVar3 = DAT_006330e4;

          iVar8 = DAT_00632a88;

          if (iVar1 != 0) break;

          iVar6 = iVar6 + 1;

          iVar7 = iVar7 + 0x38;

        } while (iVar6 < *(int *)(DAT_006330e4 + 0x200));

      }

      iVar4 = iVar3;

      if ((((iVar6 != *(int *)(iVar3 + 0x200)) &&

           (iVar7 = *(int *)(iVar3 + 0x204) + iVar6 * 0x38,

           *(float *)(*(int *)(iVar3 + 0x204) + 0x20 + iVar6 * 0x38) <= *(float *)(iVar8 + 0xa0)))

          && (*(float *)(iVar8 + 0xa0) < *(float *)(iVar7 + 0x2c) !=

              (*(float *)(iVar8 + 0xa0) == *(float *)(iVar7 + 0x2c)))) &&

         ((*(float *)(iVar7 + 0x24) <= *(float *)(iVar8 + 0xa4) &&

          (*(float *)(iVar8 + 0xa4) < *(float *)(iVar7 + 0x30) !=

           (*(float *)(iVar8 + 0xa4) == *(float *)(iVar7 + 0x30)))))) {

        flick_file_load_state(local_8 + 0x210 + iVar3);

        DAT_00632b9c = DAT_00632b9c | uVar5;

        iVar4 = DAT_006330e4;

        iVar8 = DAT_00632a88;

      }

    }

    local_8 = local_8 + 0x20;

    bVar2 = bVar2 + 1;

    if (0xfff < local_8) {

      if (DAT_005a859c == (code *)0x0) {

        return;

      }

                    /* WARNING: Could not recover jumptable at 0x004eba39. Too many branches */

                    /* WARNING: Treating indirect jump as call */

      (*DAT_005a859c)();

      return;

    }

  } while( true );

}

/* ===== fx_logic @ 0x004EBA40 ===== */
/* PS2 candidate: fx_logic (conf 0.335) */



undefined4 fx_logic(int param_1,undefined4 param_2)



{

  int iVar1;

  undefined4 uVar2;

  int iVar3;

  int iVar4;

  

  if ((param_1 == 3) && (DAT_00632b94 == 0)) {

    iVar4 = 0;

    iVar3 = 0;

    do {

      iVar1 = match(iVar3 + 0x1210 + DAT_006330e4,&PTR_DAT_00561b40);

      if (iVar1 != 0) {

        flick_file_load_state(iVar4 * 0x20 + 0x210 + DAT_006330e4);

        DAT_00632b94 = 1;

        DAT_00632b98 = 1;

        DAT_00632b8c = 0;

        return 0;

      }

      iVar3 = iVar3 + 0x20;

      iVar4 = iVar4 + 1;

    } while (iVar3 < 0x1000);

  }

  if (DAT_005a85a0 == (code *)0x0) {

    return 0;

  }

  uVar2 = (*DAT_005a85a0)(param_1,param_2);

  return uVar2;

}

/* ===== mission_marker_rect_check @ 0x004EBCE0 ===== */
undefined4 mission_marker_rect_check(void)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  int iStack00000008;

  

  iVar2 = DAT_006330e4;

  iStack00000008 = __ftol();

  iVar3 = __ftol();

  iVar4 = __ftol();

  iVar5 = __ftol();

  iVar6 = iVar5;

  iVar7 = iVar4;

  if (iVar4 < iStack00000008) {

    iVar6 = iVar3;

    iVar7 = iStack00000008;

    iStack00000008 = iVar4;

    iVar3 = iVar5;

  }

  iVar4 = iVar7 - iStack00000008;

  iVar5 = iVar6 - iVar3;

  if (iVar5 < iVar4) {

    iVar6 = iVar5 * 2 - iVar4;

    iVar4 = iVar6 - iVar4;

    for (; iStack00000008 <= iVar7; iStack00000008 = iStack00000008 + 1) {

      if (((iStack00000008 <= *(int *)(iVar2 + 0x24)) && (iVar3 <= *(int *)(iVar2 + 0x2c))) &&

         ((*(int *)(iVar2 + 0x20) <= iStack00000008 && (*(int *)(iVar2 + 0x28) <= iVar3)))) {

        return 1;

      }

      iVar1 = iVar5 * 2;

      if (-1 < iVar6) {

        iVar3 = iVar3 + 1;

        iVar1 = iVar4;

      }

      iVar6 = iVar6 + iVar1;

    }

  }

  else {

    iVar7 = iVar4 * 2 - iVar5;

    iVar5 = iVar7 - iVar5;

    if (iVar3 <= iVar6) {

      do {

        if ((((iStack00000008 <= *(int *)(iVar2 + 0x24)) && (iVar3 <= *(int *)(iVar2 + 0x2c))) &&

            (*(int *)(iVar2 + 0x20) <= iStack00000008)) && (*(int *)(iVar2 + 0x28) <= iVar3)) {

          return 1;

        }

        iVar1 = iVar4 * 2;

        if (-1 < iVar7) {

          iStack00000008 = iStack00000008 + 1;

          iVar1 = iVar5;

        }

        iVar7 = iVar7 + iVar1;

        iVar3 = iVar3 + 1;

      } while (iVar3 <= iVar6);

      return 0;

    }

  }

  return 0;

}

/* ===== mission_marker_clamp @ 0x004EBE10 ===== */
/* WARNING: Type propagation algorithm not settling */



undefined4 mission_marker_clamp(float *param_1,float *param_2,float *param_3)



{

  float fVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  float10 fVar5;

  float local_c;

  float local_8 [2];

  

  local_c = *param_3 - *param_1;

  local_8[1] = 0.0;

  local_8[0] = param_3[1] - param_1[1];

  normalize__FPfN20(&local_c,local_8,local_8 + 1);

  *param_3 = *(float *)(DAT_00632ed8 + 0x1574) * local_c + *param_3;

  param_3[1] = *(float *)(DAT_00632ed8 + 0x1574) * local_8[0] + param_3[1];

  fVar1 = *(float *)(DAT_00632ed8 + 0xcfc) * *(float *)(DAT_00632ed8 + 0xcf8);

  *param_2 = local_c * fVar1 + *param_3;

  param_2[1] = fVar1 * local_8[0] + param_3[1];

  fVar5 = (float10)get_floor_z_point(param_2);

  fVar1 = (float)fVar5;

  param_2[2] = fVar1;

  iVar4 = DAT_006330e4;

  iVar2 = __ftol();

  iVar3 = __ftol();

  if ((((*(int *)(iVar4 + 0x24) < iVar2) || (*(int *)(iVar4 + 0x2c) < iVar3)) ||

      (iVar2 < *(int *)(iVar4 + 0x20))) ||

     ((iVar3 < *(int *)(iVar4 + 0x28) || (fVar1 < -61.1 != (fVar1 == -61.1))))) {

    iVar4 = mission_marker_rect_check(param_2,param_3);

    if (iVar4 == 0) {

      param_2[2] = 0.0;

      return 1;

    }

  }

  return 0;

}

/* ===== mission_marker_pos_check @ 0x004EBF30 ===== */
undefined4 mission_marker_pos_check(int param_1,undefined4 param_2,float *param_3)



{

  float fVar1;

  float fVar2;

  int iVar3;

  undefined4 uVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  int iVar9;

  int iVar10;

  bool bVar11;

  int local_14;

  int local_4;

  

  uVar4 = param_1;

  iVar10 = DAT_006330e4;

  iVar5 = __ftol();

  iVar6 = __ftol();

  iVar7 = *(int *)(iVar10 + 0x24);

  if ((((iVar5 <= iVar7) && (iVar8 = *(int *)(iVar10 + 0x2c), iVar6 <= iVar8)) &&

      (*(int *)(iVar10 + 0x20) <= iVar5)) && (*(int *)(iVar10 + 0x28) <= iVar6)) {

    local_4 = 1;

    param_1 = iVar6;

    local_14 = iVar6;

    do {

      local_14 = local_14 + -1;

      param_1 = param_1 + 1;

      iVar9 = param_1 + (iVar5 - iVar6);

      if (((iVar7 < iVar9) || (iVar8 < iVar6)) ||

         ((iVar9 < *(int *)(iVar10 + 0x20) || (iVar6 < *(int *)(iVar10 + 0x28))))) {

        *param_3 = ((float)iVar9 + 0.5) * *(float *)(iVar10 + 0x1c0) + *(float *)(iVar10 + 0x1c8);

        fVar1 = *(float *)(DAT_006330e4 + 0x1c0);

        fVar2 = *(float *)(DAT_006330e4 + 0x1cc);

        param_3[2] = 0.0;

        param_3[1] = ((float)iVar6 + 0.5) * fVar1 + fVar2;

        iVar7 = mission_marker_clamp(uVar4,param_2,param_3);

        iVar10 = DAT_006330e4;

        if (iVar7 != 0) {

          return 1;

        }

      }

      iVar7 = (iVar5 - iVar6) + local_14;

      if (((*(int *)(iVar10 + 0x24) < iVar7) || (*(int *)(iVar10 + 0x2c) < iVar6)) ||

         ((iVar7 < *(int *)(iVar10 + 0x20) || (iVar6 < *(int *)(iVar10 + 0x28))))) {

        *param_3 = ((float)iVar7 + 0.5) * *(float *)(iVar10 + 0x1c0) + *(float *)(iVar10 + 0x1c8);

        fVar1 = *(float *)(DAT_006330e4 + 0x1c0);

        fVar2 = *(float *)(DAT_006330e4 + 0x1cc);

        param_3[2] = 0.0;

        param_3[1] = ((float)iVar6 + 0.5) * fVar1 + fVar2;

        iVar7 = mission_marker_clamp(uVar4,param_2,param_3);

        iVar10 = DAT_006330e4;

        if (iVar7 != 0) {

          return 1;

        }

      }

      if ((((*(int *)(iVar10 + 0x24) < iVar5) || (*(int *)(iVar10 + 0x2c) < param_1)) ||

          (iVar5 < *(int *)(iVar10 + 0x20))) || (param_1 < *(int *)(iVar10 + 0x28))) {

        *param_3 = ((float)iVar5 + 0.5) * *(float *)(iVar10 + 0x1c0) + *(float *)(iVar10 + 0x1c8);

        fVar1 = *(float *)(DAT_006330e4 + 0x1c0);

        fVar2 = *(float *)(DAT_006330e4 + 0x1cc);

        param_3[2] = 0.0;

        param_3[1] = ((float)param_1 + 0.5) * fVar1 + fVar2;

        iVar7 = mission_marker_clamp(uVar4,param_2,param_3);

        iVar10 = DAT_006330e4;

        if (iVar7 != 0) {

          return 1;

        }

      }

      if (((*(int *)(iVar10 + 0x24) < iVar5) || (*(int *)(iVar10 + 0x2c) < local_14)) ||

         ((iVar5 < *(int *)(iVar10 + 0x20) || (local_14 < *(int *)(iVar10 + 0x28))))) {

        *param_3 = ((float)iVar5 + 0.5) * *(float *)(iVar10 + 0x1c0) + *(float *)(iVar10 + 0x1c8);

        fVar1 = *(float *)(DAT_006330e4 + 0x1c0);

        fVar2 = *(float *)(DAT_006330e4 + 0x1cc);

        param_3[2] = 0.0;

        param_3[1] = ((float)local_14 + 0.5) * fVar1 + fVar2;

        iVar7 = mission_marker_clamp(uVar4,param_2,param_3);

        iVar10 = DAT_006330e4;

        if (iVar7 != 0) {

          return 1;

        }

      }

      local_4 = local_4 + 1;

      iVar8 = *(int *)(iVar10 + 0x2c);

      iVar7 = *(int *)(iVar10 + 0x24);

      if (iVar8 < iVar7) {

        iVar9 = local_4 - iVar7;

        bVar11 = local_4 == iVar7;

        iVar3 = iVar7;

      }

      else {

        iVar9 = local_4 - iVar8;

        bVar11 = iVar9 == 0;

        iVar3 = iVar8;

      }

    } while (bVar11 || SBORROW4(local_4,iVar3) != iVar9 < 0);

  }

  return 0;

}

/* ===== FUN_004ec1f0 @ 0x004EC1F0 ===== */
/* PS2 candidate: army_create_ripper__FP6OBJECTP9ArmyOrderi (conf 0.392) */



int FUN_004ec1f0(undefined4 param_1,undefined4 param_2,undefined4 param_3)



{

  undefined4 *puVar1;

  int iVar2;

  int iVar3;

  float10 fVar4;

  undefined4 local_18;

  undefined4 local_14;

  undefined4 local_10;

  undefined4 local_c;

  undefined4 local_8;

  undefined4 local_4;

  

  iVar2 = mission_marker_pos_check(param_2,&local_c,&local_18);

  if (iVar2 != 0) {

    iVar2 = object_allocate_type(0x4b,0x80000000);

    *(undefined4 *)(iVar2 + 0x274) = param_1;

    iVar3 = fx_create(param_1);

    if (iVar3 == 0) {

      *(undefined4 *)(iVar2 + 0x188) = param_3;

    }

    iVar3 = *(int *)(iVar2 + 0x100);

    *(undefined4 *)(iVar3 + 0x48) = local_18;

    *(undefined4 *)(iVar3 + 0x4c) = local_14;

    *(undefined4 *)(iVar3 + 0x50) = local_10;

    puVar1 = (undefined4 *)(iVar3 + 0x3c);

    *puVar1 = local_c;

    *(undefined4 *)(iVar3 + 0x40) = local_8;

    *(undefined4 *)(iVar3 + 0x44) = local_4;

    object_set_location(iVar2,*puVar1,*(undefined4 *)(iVar3 + 0x40),*(undefined4 *)(iVar3 + 0x44));

    fVar4 = (float10)dirfcalcp3d__FP3P3DT0(puVar1,(undefined4 *)(iVar3 + 0x48));

    *(float *)(iVar2 + 200) = (float)fVar4;

    *(undefined4 *)(iVar2 + 0xec) = *(undefined4 *)(DAT_00632ed8 + 0xcf8);

    return iVar2;

  }

  return 0;

}

/* ===== cspec_004ec440 @ 0x004EC440 ===== */
void cspec_004ec440(int param_1)



{

  int iVar1;

  int iVar2;

  float10 fVar3;

  

  iVar1 = *(int *)(param_1 + 0x100);

  if (DAT_00632e74 != 0) {

    return;

  }

  *(undefined1 *)(param_1 + 0x208) = 0;

  *(undefined1 *)(param_1 + 0x20b) = 0;

  *(undefined1 *)(param_1 + 0x20a) = 0;

  *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) & 0xfcffffff;

  if (*(int *)(param_1 + 0xe4) == 0) {

    *(int *)(param_1 + 0x104) = iVar1;

    PhysicsExZeroForce(param_1);

    *(undefined4 *)(param_1 + 0x194) = *(undefined4 *)(DAT_00632ed8 + 0xcfc);

    ai_move_force_goal(param_1,iVar1 + 0x48);

    *(undefined4 *)(param_1 + 0xe4) = 1;

  }

  iVar2 = *(int *)(param_1 + 0x274);

  if (iVar2 != 0) {

    *(undefined4 *)(iVar1 + 0x54) = *(undefined4 *)(iVar2 + 0xa0);

    *(undefined4 *)(iVar1 + 0x58) = *(undefined4 *)(iVar2 + 0xa4);

    *(undefined4 *)(iVar1 + 0x5c) = *(undefined4 *)(iVar2 + 0xa8);

  }

  switch(*(undefined4 *)(param_1 + 0xe4)) {

  case 1:

    fVar3 = (float10)FUN_00518b70(param_1,0);

    fVar3 = (float10)*(float *)(param_1 + 0xec) - fVar3;

    *(float *)(param_1 + 0xec) = (float)fVar3;

    if (fVar3 < (float10)0.0) {

      *(undefined4 *)(param_1 + 0xec) = 0;

    }

    ai_goal_process(param_1);

    if ((*(int *)(param_1 + 0x168) == 0) &&

       (*(float *)(param_1 + 0xec) < 0.0 != (*(float *)(param_1 + 0xec) == 0.0))) {

      ObjectSetAnim(param_1,10,0x20,0,0,0x3e2aaaab);

      *(undefined4 *)(param_1 + 0xe4) = 2;

      *(undefined4 *)(param_1 + 0x184) = 0;

    }

    else {

      *(float *)(param_1 + 0x184) = *(float *)(param_1 + 0xec) / *(float *)(DAT_00632ed8 + 0xcf8);

    }

    break;

  case 2:

    if ((*(byte *)(param_1 + 0x30) & 2) != 0) {

      if ((*(byte *)(param_1 + 0xe0) & 1) == 0) {

        *(undefined4 *)(param_1 + 0xe4) = 3;

      }

      else {

        ObjectSetAnim(param_1,5,1,0,0,0x3e2aaaab);

        *(undefined4 *)(param_1 + 0xf0) = *(undefined4 *)(DAT_00632ed8 + 0xcf8);

        ai_move_force_goal(param_1,iVar1 + 0x3c);

        *(undefined4 *)(param_1 + 0xe4) = 4;

      }

    }

    if (((0.7 < *(float *)(param_1 + 0x14)) &&

        (*(float *)(param_1 + 0x18) < 0.7 != (*(float *)(param_1 + 0x18) == 0.7))) &&

       (iVar2 = fx_create(param_1), iVar2 != 0)) {

      main_seamonst_004ec2c0(param_1,iVar1 + 0x54,0xffffffff);

    }

    break;

  case 3:

    if ((*(byte *)(param_1 + 0xe0) & 1) != 0) {

      ObjectSetAnim(param_1,5,1,0,0,0x3e2aaaab);

      *(undefined4 *)(param_1 + 0xf0) = *(undefined4 *)(DAT_00632ed8 + 0xcf8);

      ai_move_force_goal(param_1,iVar1 + 0x3c);

      *(undefined4 *)(param_1 + 0xe4) = 4;

    }

    break;

  case 4:

    fVar3 = (float10)FUN_00518b70(param_1,0);

    fVar3 = (float10)*(float *)(param_1 + 0xf0) - fVar3;

    *(float *)(param_1 + 0xf0) = (float)fVar3;

    if (fVar3 < (float10)0.0) {

      *(undefined4 *)(param_1 + 0xf0) = 0;

    }

    ai_goal_process(param_1);

    *(char *)(param_1 + 0x20a) = -*(char *)(param_1 + 0x20a);

    if ((*(int *)(param_1 + 0x168) != 0) ||

       (*(float *)(param_1 + 0xf0) < 0.0 == (*(float *)(param_1 + 0xf0) == 0.0))) {

      *(float *)(param_1 + 0x184) =

           1.0 - *(float *)(param_1 + 0xf0) / *(float *)(DAT_00632ed8 + 0xcf8);

      break;

    }

    goto LAB_004ec6fc;

  case 5:

    if ((*(byte *)(param_1 + 0x30) & 2) == 0) break;

LAB_004ec6fc:

    object_destroy(param_1);

  }

  if (*(int *)(param_1 + 0xe4) != 4) {

    obj_alpha_fade_update(param_1);

  }

  player_pitch_update(param_1);

  obj_vel_reset(param_1);

  PhysicsExApplyLocation(param_1);

  PhysicsExCalcControledModelSpeeds

            (param_1,*(undefined4 *)(DAT_00632ed8 + 0xd84),*(undefined4 *)(param_1 + 0x194));

  obj_gravity_apply(param_1,1);

  PhysicsExApplyMoveControls(param_1);

  fVar3 = (float10)FUN_00518b70(param_1,0);

  object_animate_process(param_1,(float)fVar3);

  *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) | 0x40;

  return;

}

/* ===== cspec_004ec7a0 @ 0x004EC7A0 ===== */
void cspec_004ec7a0(undefined4 param_1,int param_2,undefined4 param_3,int param_4)



{

  if (param_2 == 1) {

    main_seamonst_004ec2c0(param_1,param_4,*(undefined4 *)(param_4 + 0xc));

  }

  return;

}

/* ===== cspec_004ec7c0 @ 0x004EC7C0 ===== */
undefined4 cspec_004ec7c0(void)



{

  return 0x60;

}

/* ===== FUN_004ec7d0 @ 0x004EC7D0 ===== */
void FUN_004ec7d0(undefined4 *param_1)



{

  int iVar1;

  undefined4 *puVar2;

  

  puVar2 = param_1;

  for (iVar1 = 6; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar2 = 0;

    puVar2 = puVar2 + 1;

  }

  *(undefined2 *)puVar2 = 0;

  *(undefined1 *)((int)puVar2 + 2) = 0;

  *(undefined1 *)((int)param_1 + 6) = 1;

  *(undefined1 *)((int)param_1 + 7) = 2;

  *(undefined1 *)(param_1 + 2) = 0;

  *(undefined1 *)param_1 = 1;

  *(undefined1 *)((int)param_1 + 3) = 1;

  *(undefined1 *)((int)param_1 + 1) = 4;

  *(undefined1 *)(param_1 + 1) = 1;

  *(undefined1 *)((int)param_1 + 2) = 0;

  *(undefined1 *)((int)param_1 + 9) = 0x13;

  *(undefined1 *)((int)param_1 + 10) = 0xd2;

  *(undefined1 *)((int)param_1 + 0xb) = 199;

  *(undefined1 *)(param_1 + 3) = 0xc9;

  *(undefined1 *)((int)param_1 + 0xd) = 0xd3;

  *(undefined1 *)((int)param_1 + 0xe) = 0xcf;

  *(undefined1 *)((int)param_1 + 0xf) = 0xd1;

  *(undefined1 *)(param_1 + 4) = 0x32;

  *(undefined1 *)((int)param_1 + 0x11) = 0x1f;

  *(undefined1 *)((int)param_1 + 0x12) = 0x19;

  *(undefined1 *)((int)param_1 + 0x13) = 0x2f;

  *(undefined1 *)(param_1 + 5) = 0x2a;

  *(undefined1 *)((int)param_1 + 0x15) = 0x2d;

  *(undefined1 *)((int)param_1 + 0x16) = 0x2e;

  *(undefined1 *)((int)param_1 + 0x17) = 0x39;

  *(undefined1 *)(param_1 + 6) = 2;

  *(undefined1 *)((int)param_1 + 0x19) = 0x1d;

  *(undefined1 *)((int)param_1 + 0x1a) = 0x38;

  return;

}

/* ===== perf_options_menu @ 0x004ED600 ===== */
undefined4 perf_options_menu(void)



{

  undefined4 uVar1;

  undefined4 uVar2;

  undefined4 uVar3;

  bool bVar4;

  char *pcVar5;

  undefined1 local_120 [32];

  undefined1 local_100 [256];

  

  uVar1 = main_dlog_00427150();

  main_dlog_004273b0(uVar1,0,0x3f000000,0x3f800000,0xaa000000,s_SetPerfTitle_00561f64);

  main_dlog_00427bb0(uVar1,0x15,0x3e99999a,0xc0000000,0x8a000000,s_ButtonOK_00561f58);

  main_dlog_00427e80(uVar1,1,0x3f000000,0x40400000,0x88000022);

  main_dlog_004283f0(uVar1,1);

  bVar4 = DAT_0063311c == 0;

  uVar2 = FUN_00507b00(s_SetPerfShadow_00561f48);

  if (bVar4) {

    pcVar5 = s_SetOptionOn_00561f3c;

  }

  else {

    pcVar5 = s_SetOptionOff_00561f2c;

  }

  uVar3 = FUN_00507b00(pcVar5);

  crt_sprintf(local_100,uVar2,uVar3);

  main_dlog_004281f0(uVar1,1,local_100);

  crt_sprintf(local_120,s_SetPerfLOD_d_00561f1c,DAT_00633150);

  uVar2 = FUN_00507b00(local_120);

  uVar3 = FUN_00507b00(s_SetPerfLOD_00561f10);

  crt_sprintf(local_100,uVar3,uVar2);

  main_dlog_004281f0(uVar1,1,local_100);

  return uVar1;

}

/* ===== water_fx_test @ 0x004ED910 ===== */
void water_fx_test(void)



{

  byte *pbVar1;

  undefined4 *puVar2;

  int iVar3;

  undefined4 uVar4;

  int iVar5;

  undefined4 *puVar6;

  

  iVar3 = DAT_006330e4;

  if (DAT_006330e4 != 0) {

    puVar2 = (undefined4 *)(DAT_006330e4 + 0x5040);

    puVar6 = puVar2;

    for (iVar5 = 8; iVar5 != 0; iVar5 = iVar5 + -1) {

      *puVar6 = 0;

      puVar6 = puVar6 + 1;

    }

    *puVar2 = s_Water_texture_00561fa0;

    *(undefined4 *)(iVar3 + 0x5044) = 0;

    *(undefined4 *)(iVar3 + 0x5048) = 0;

    *(undefined4 *)(iVar3 + 0x504c) = 8;

    *(undefined4 *)(iVar3 + 0x5050) = 8;

    *(undefined4 *)(iVar3 + 0x5058) = 5;

    *(undefined4 *)(iVar3 + 0x5054) = 5;

    *(undefined1 *)(iVar3 + 0x505d) = 0;

    *(undefined1 *)(iVar3 + 0x505c) = 0x10;

    *(undefined2 *)(iVar3 + 0x505e) = 0x80;

    *(undefined4 *)(DAT_006330e4 + 0x503c) = 0;

    uVar4 = main_texture_00508750(s_efx_water_test_bw_00561f8c);

    *(undefined4 *)(DAT_006330e4 + 0x5080) = uVar4;

    if (*(int *)(DAT_006330e4 + 0x5080) != 0) {

      pbVar1 = (byte *)(*(int *)(DAT_006330e4 + 0x5080) + 0x1f);

      *pbVar1 = *pbVar1 | 1;

      *(undefined1 *)(*(int *)(DAT_006330e4 + 0x5080) + 0x1c) = 0x10;

    }

    uVar4 = main_texture_00508750(s_elevation_texture_00561f78);

    *(undefined4 *)(DAT_006330e4 + 0x5088) = uVar4;

    if (*(int *)(DAT_006330e4 + 0x5088) != 0) {

      texture_alloc_helper(*(int *)(DAT_006330e4 + 0x5088));

    }

  }

  return;

}

/* ===== world_reset_callback_add @ 0x004ED9E0 ===== */
/* PS2 candidate: world_reset_callback_add (conf 0.51) */



void world_reset_callback_add(int param_1)



{

  int iVar1;

  

  iVar1 = 0;

  if (0 < DAT_00632ea4) {

    do {

      if ((&DAT_00632ea8)[iVar1] == param_1) {

        return;

      }

      iVar1 = iVar1 + 1;

    } while (iVar1 < DAT_00632ea4);

    if (9 < iVar1) {

      FUN_0051ea20();

      return;

    }

  }

  (&DAT_00632ea8)[iVar1] = param_1;

  DAT_00632ea4 = DAT_00632ea4 + 1;

  return;

}

/* ===== world_make_reset_callbacks__Fi @ 0x004EDD70 ===== */
/* PS2 candidate: world_make_reset_callbacks__Fi (conf 0.58) */



void world_make_reset_callbacks__Fi(void)



{

  int iVar1;

  uint uVar2;

  int iVar3;

  undefined4 *puVar4;

  undefined4 *puVar5;

  undefined4 *puVar6;

  undefined4 *local_4;

  

  iVar3 = 0;

  if (0 < DAT_00632ea4) {

    puVar4 = &DAT_00632ea8;

    local_4 = (undefined4 *)&DAT_00632eac;

    do {

      iVar1 = (*(code *)*puVar4)(0);

      if (iVar1 == 0) {

        DAT_00632ea4 = DAT_00632ea4 + -1;

        if (iVar3 < DAT_00632ea4) {

          puVar5 = local_4;

          puVar6 = puVar4;

          for (uVar2 = DAT_00632ea4 - iVar3 & 0x3fffffff; uVar2 != 0; uVar2 = uVar2 - 1) {

            *puVar6 = *puVar5;

            puVar5 = puVar5 + 1;

            puVar6 = puVar6 + 1;

          }

          for (iVar1 = 0; iVar1 != 0; iVar1 = iVar1 + -1) {

            *(undefined1 *)puVar6 = *(undefined1 *)puVar5;

            puVar5 = (undefined4 *)((int)puVar5 + 1);

            puVar6 = (undefined4 *)((int)puVar6 + 1);

          }

        }

        iVar3 = iVar3 + -1;

        local_4 = local_4 + -1;

        puVar4 = puVar4 + -1;

      }

      iVar3 = iVar3 + 1;

      local_4 = local_4 + 1;

      puVar4 = puVar4 + 1;

    } while (iVar3 < DAT_00632ea4);

  }

  return;

}

/* ===== flk_replay_reset @ 0x004EDDF0 ===== */
void flk_replay_reset(void)



{

  int iVar1;

  undefined4 uVar2;

  

  FLK_ReplayFileNameClear();

  iVar1 = dialog_level_is_base();

  uVar2 = DAT_00632d20;

  if (iVar1 != 0) {

    uVar2 = DAT_00632ee4;

  }

  DAT_006330e4 = world_get_pointer(uVar2);

  Main_mission_00490940();

  mission_init((char *)0x0);

  main_texture_00507fa0();

  return;

}

/* ===== meccprocanimscreate_004ede30 @ 0x004EDE30 ===== */
void meccprocanimscreate_004ede30(void)



{

  undefined4 uVar1;

  int iVar2;

  int iVar3;

  

  uVar1 = objectset_find(2);

  MeccProcAnimsCreate(uVar1);

  uVar1 = objectset_find(0x85);

  MeccProcAnimsCreate(uVar1);

  uVar1 = objectset_find(0x248);

  MeccProcAnimsCreate_2(uVar1);

  uVar1 = objectset_find(0x270);

  MeccProcAnimsCreate_3(uVar1);

  uVar1 = objectset_find(0x3b);

  MeccProcAnimsCreate_4(uVar1);

  uVar1 = objectset_find(0x42f);

  MeccProcAnimsCreate_4(uVar1);

  uVar1 = objectset_find(0x42e);

  MeccProcAnimsCreate_4(uVar1);

  uVar1 = objectset_find(0x4ac);

  MeccProcAnimsCreate_4(uVar1);

  uVar1 = objectset_find(0x4ad);

  MeccProcAnimsCreate_4(uVar1);

  uVar1 = objectset_find(0x4ab);

  MeccProcAnimsCreate_4(uVar1);

  uVar1 = objectset_find(0x4aa);

  MeccProcAnimsCreate_4(uVar1);

  uVar1 = objectset_find(1);

  KabutoProcAnimsCreate(uVar1);

  uVar1 = objectset_find(0x66);

  main_procanim_004a8d40(uVar1);

  uVar1 = objectset_find(0x65);

  main_procanim_004a8d40(uVar1);

  main_drawwatr_00430f30(*(undefined4 *)(DAT_006330e4 + 0x7c));

  (**(code **)(DAT_00656420 + 0xac))

            (DAT_00656420,*(undefined4 *)(DAT_006330e4 + 0x128),*(undefined4 *)(DAT_006330e4 + 300),

             DAT_006330e4 + 0x130);

  texture_object_debug_dump_3();

  iVar3 = 0;

  if (0 < DAT_00632db8) {

    iVar2 = 0;

    do {

      if (*(int *)(DAT_00632dbc + 4 + iVar2) != 0) {

        FUN_00495060(DAT_00632dbc + iVar2);

      }

      iVar3 = iVar3 + 1;

      iVar2 = iVar2 + 0x2c;

    } while (iVar3 < DAT_00632db8);

  }

  return;

}

/* ===== object_spawn_copy @ 0x004EDF90 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void object_spawn_copy(void)



{

  int iVar1;

  int iVar2;

  undefined4 *puVar3;

  

  puVar3 = &DAT_00632b40;

  for (iVar2 = 0x77; iVar2 != 0; iVar2 = iVar2 + -1) {

    *puVar3 = 0;

    puVar3 = puVar3 + 1;

  }

  _DAT_00632b58 = *(undefined4 *)(DAT_006330e4 + 0x1f8);

  DAT_00632a88 = object_allocate_type(0,0x11);

  if ((DAT_00632a88 != 0) && (DAT_00632d58 != 0)) {

    object_copy_personality(DAT_00632a88,DAT_00632d58);

  }

  cam_mode_switch(1);

  *(undefined4 *)(DAT_00632a88 + 0x18c) = 1;

  iVar1 = DAT_006330e4;

  iVar2 = DAT_00632a88;

  DAT_00633108 = 0;

  *(undefined4 *)(DAT_00632a88 + 0xa0) = *(undefined4 *)(DAT_006330e4 + 0x88);

  *(undefined4 *)(iVar2 + 0xa4) = *(undefined4 *)(iVar1 + 0x8c);

  *(undefined4 *)(iVar2 + 0xa8) = *(undefined4 *)(iVar1 + 0x90);

  *(undefined4 *)(DAT_00632a88 + 200) = *(undefined4 *)(DAT_006330e4 + 0x94);

  iVar2 = DAT_00632a88;

  *(undefined4 *)(DAT_00632a88 + 0xac) = *(undefined4 *)(DAT_00632a88 + 0xa0);

  *(undefined4 *)(iVar2 + 0xb0) = *(undefined4 *)(iVar2 + 0xa4);

  *(undefined4 *)(iVar2 + 0xb4) = *(undefined4 *)(iVar2 + 0xa8);

  iVar2 = DAT_00632a88;

  *(undefined4 *)(DAT_00632a88 + 0xb8) = *(undefined4 *)(DAT_00632a88 + 0xac);

  *(undefined4 *)(iVar2 + 0xbc) = *(undefined4 *)(iVar2 + 0xb0);

  *(undefined4 *)(iVar2 + 0xc0) = *(undefined4 *)(iVar2 + 0xb4);

  ref_anode_user();

  return;

}

/* ===== env_water_texture @ 0x004EE080 ===== */
void env_water_texture(void)



{

  undefined4 *puVar1;

  int iVar2;

  int iVar3;

  undefined4 *puVar4;

  

  match_start_entry();

  fx_blob_shadow();

  iVar2 = DAT_006330e4;

  puVar1 = (undefined4 *)(DAT_006330e4 + 0x4ea0);

  puVar4 = puVar1;

  for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {

    *puVar4 = 0;

    puVar4 = puVar4 + 1;

  }

  *puVar1 = s_Environment_texture_00561ff8;

  *(undefined4 *)(iVar2 + 0x4ea4) = 0;

  *(undefined4 *)(iVar2 + 0x4ea8) = 0;

  *(undefined4 *)(iVar2 + 0x4eac) = 8;

  *(undefined4 *)(iVar2 + 0x4eb0) = 8;

  *(undefined4 *)(iVar2 + 0x4eb8) = 5;

  *(undefined4 *)(iVar2 + 0x4eb4) = 5;

  *(undefined1 *)(iVar2 + 0x4ebd) = 0;

  *(undefined2 *)(iVar2 + 0x4ebe) = 0xa1;

  water_fx_test();

  DAT_006328f4 = game_water_00513be0(0x50,0x50);

  return;

}

/* ===== base_spells_setup @ 0x004EE0F0 ===== */
void base_spells_setup(void)



{

  int iVar1;

  

  iVar1 = FUN_0052c5c0();

  if (iVar1 != 0) {

    iVar1 = 0;

    if (0 < *(int *)(DAT_006330e4 + 0x170)) {

      do {

        create_static_object(iVar1,0);

        iVar1 = iVar1 + 1;

      } while (iVar1 < *(int *)(DAT_006330e4 + 0x170));

    }

    DAT_00632f0c = 0;

    objtype_setup_spell(0);

  }

  FUN_004eb8f0();

  return;

}

/* ===== world_fx_release @ 0x004EE150 ===== */
void world_fx_release(void)



{

  int iVar1;

  int iVar2;

  

  if ((DAT_006330e4 != 0) && (*(int *)(DAT_006330e4 + 0x4f6c) != 0)) {

    fx_delete(*(int *)(DAT_006330e4 + 0x4f6c));

    *(undefined4 *)(DAT_006330e4 + 0x4f6c) = 0;

    iVar2 = 0;

    do {

      iVar1 = *(int *)(iVar2 + 0x4f78 + DAT_006330e4);

      if (iVar1 != 0) {

        object_destroy(iVar1);

        *(undefined4 *)(iVar2 + 0x4f78 + DAT_006330e4) = 0;

      }

      iVar2 = iVar2 + 0x44;

    } while (iVar2 < 0xcc);

  }

  return;

}

/* ===== fx_spawn_checked @ 0x004EE1C0 ===== */
void fx_spawn_checked(int param_1)



{

  float fVar1;

  float fVar2;

  int iVar3;

  undefined4 uVar4;

  int iVar5;

  int iVar6;

  

  if ((DAT_006330e4 != 0) && (*(int *)(DAT_006330e4 + 0x4f6c) != 0)) {

    fx_delete(*(int *)(DAT_006330e4 + 0x4f6c));

    *(undefined4 *)(DAT_006330e4 + 0x4f6c) = 0;

    iVar5 = 0;

    do {

      iVar6 = *(int *)(iVar5 + 0x4f78 + DAT_006330e4);

      if (iVar6 != 0) {

        object_destroy(iVar6);

        *(undefined4 *)(iVar5 + 0x4f78 + DAT_006330e4) = 0;

      }

      iVar5 = iVar5 + 0x44;

    } while (iVar5 < 0xcc);

  }

  ObjectCalculateTransform(param_1);

  fVar1 = *(float *)(param_1 + 0x2ac);

  fVar2 = *(float *)(param_1 + 700);

  *(float *)(DAT_006330e4 + 0x4f60) = *(float *)(param_1 + 0x29c) * 12000.0;

  *(float *)(DAT_006330e4 + 0x4f64) = fVar1 * 12000.0;

  *(float *)(DAT_006330e4 + 0x4f68) = fVar2 * 12000.0;

  if (*(char *)(DAT_006330e4 + 0x4f40) != '\0') {

    uVar4 = fx_get_free_effect__Fv();

    *(undefined4 *)(DAT_006330e4 + 0x4f6c) = uVar4;

  }

  iVar6 = 0;

  iVar5 = DAT_006330e4;

  do {

    iVar3 = *(int *)(iVar6 + 0x4f74 + iVar5);

    if (iVar3 != 0) {

      uVar4 = object_allocate_type(iVar3,0x80000000);

      *(undefined4 *)(iVar6 + 0x4f78 + DAT_006330e4) = uVar4;

      iVar3 = *(int *)(iVar6 + 0x4f78 + DAT_006330e4);

      iVar5 = DAT_006330e4;

      if (iVar3 != 0) {

        if (*(int *)(iVar3 + 4) == 0x46a) {

          *(uint *)(iVar3 + 0x1c8) = *(uint *)(iVar3 + 0x1c8) | 0x2000000;

        }

        object_set_location_p3d

                  (*(undefined4 *)(iVar6 + 0x4f78 + DAT_006330e4),DAT_006330e4 + 0x4f60);

        iVar5 = *(int *)(iVar6 + 0x4f78 + DAT_006330e4);

        *(uint *)(iVar5 + 0xd8) = *(uint *)(iVar5 + 0xd8) | 0x40000000;

        iVar5 = DAT_006330e4;

      }

    }

    iVar6 = iVar6 + 0x44;

  } while (iVar6 < 0xcc);

  return;

}

/* ===== editor_dump_objnames @ 0x004EE390 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



float10 editor_dump_objnames(float param_1)



{

  undefined4 *puVar1;

  int *piVar2;

  bool bVar3;

  undefined4 *puVar4;

  int iVar5;

  int *piVar6;

  int iVar7;

  int iVar8;

  int *piVar9;

  int iVar10;

  float10 fVar11;

  int *local_b4;

  int iStack_a8;

  float local_a4;

  undefined1 auStack_a0 [80];

  undefined1 auStack_50 [80];

  

  local_a4 = DAT_006328e8;

  puVar4 = DAT_005a8600;

  iVar10 = DAT_005a8604;

  if (DAT_005a8600 == (undefined4 *)0x0) {

    _DAT_005a85f4 = 1;

    DAT_005a85f8 = 0;

    for (puVar1 = DAT_00632d4c; puVar4 = DAT_00632d4c, DAT_005a8600 = DAT_00632d4c,

        puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {

      _DAT_005a85f4 = _DAT_005a85f4 + puVar1[1];

    }

  }

  do {

    if (puVar4 == (undefined4 *)0x0) {

      DAT_005a8604 = 0;

      DAT_005a8600 = (undefined4 *)0x0;

      return (float10)0.0;

    }

    if (iVar10 < (int)puVar4[1]) {

      local_b4 = puVar4 + iVar10 + 2;

      DAT_005a8604 = iVar10;

      do {

        if ((0.0 <= param_1) && (time_frame_update(), param_1 < DAT_006328e8 - local_a4)) {

          DAT_005a8600 = puVar4;

          DAT_005a8604 = iVar10;

          fVar11 = (float10)1.0 - (float10)DAT_005a85f8 / (float10)_DAT_005a85f4;

          if (fVar11 < (float10)0.001 == (fVar11 == (float10)0.001)) {

            return fVar11;

          }

          return (float10)0.001;

        }

        DAT_005a85f8 = DAT_005a85f8 + 1;

        piVar2 = (int *)*local_b4;

        if (0 < piVar2[0x1a]) {

          piVar9 = piVar2 + 0x24;

          iVar8 = 1;

          do {

            iVar5 = *piVar9;

            if (((iVar5 != 0) && (-1 < *(short *)(iVar5 + 0x1e))) &&

               (iVar5 = (**(code **)(DAT_00656420 + 0xb0))(DAT_00656420,iVar5), iVar5 == 0)) {

              iVar5 = iVar8;

              piVar6 = piVar9;

              if (iVar8 < piVar2[0x1a]) {

                do {

                  piVar6 = piVar6 + 0x14;

                  if (*piVar6 == *piVar9) {

                    *piVar6 = *(int *)(DAT_006330e4 + 0x4ec0);

                  }

                  iVar5 = iVar5 + 1;

                } while (iVar5 < piVar2[0x1a]);

              }

              *piVar9 = *(int *)(DAT_006330e4 + 0x4ec0);

              iVar5 = BinFileSeek_2(s_bld_yy_names_bld_00557054,&DAT_00557068);

              if (iVar5 != 0) {

                while (iVar7 = crt_scanf_getchar2(auStack_50,0x50,iVar5), iVar7 != 0) {

                  iStack_a8 = 0;

                  crt_scanf_entry(iVar7,s__define_ObjData_s__d_0056204c,auStack_a0,&iStack_a8);

                  if ((iStack_a8 != 0) && (*piVar2 == iStack_a8)) {

                    crt_sprintf(&DAT_00657400,s_Missing_texture__objdata___s___s_0056200c,auStack_a0

                                ,piVar9[-7],*(undefined4 *)*piVar9);

                    map_scratch_clear(&DAT_00556380,&DAT_00657400);

                  }

                }

                editor_0054384c(iVar5);

              }

            }

            piVar9 = piVar9 + 0x14;

            bVar3 = iVar8 < piVar2[0x1a];

            iVar8 = iVar8 + 1;

          } while (bVar3);

        }

        iVar10 = iVar10 + 1;

        local_b4 = local_b4 + 1;

      } while (iVar10 < (int)puVar4[1]);

    }

    DAT_005a8604 = 0;

    puVar4 = (undefined4 *)*puVar4;

    iVar10 = DAT_005a8604;

  } while( true );

}

/* ===== kabutoai_punch_user @ 0x004EE630 ===== */
void kabutoai_punch_user(void)



{

  int iVar1;

  undefined4 *puVar2;

  int iVar3;

  

  for (puVar2 = DAT_00632d68; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {

    iVar1 = puVar2[3];

    if ((*(int *)(iVar1 + 0x1e0) == 0x5c) &&

       (iVar3 = kabutoai_is_punch_anim__FP6OBJECT(iVar1), iVar3 != 0)) {

      fx_spawn_checked(iVar1);

    }

  }

  return;

}

/* ===== reaper_logic @ 0x004EE670 ===== */
/* PS2 candidate: reaper_logic (conf 0.426) */



void reaper_logic(int param_1)



{

  undefined4 *puVar1;

  int iVar2;

  undefined4 uVar3;

  int iVar4;

  float10 fVar5;

  

  DAT_00633044 = 1;

  DAT_00633048 = 1;

  if (*(char *)(DAT_006330e4 + 0x4530) != '\0') {

    fx_get_free_effect__Fv();

  }

  iVar2 = dialog_level_is_base();

  if (iVar2 == 0) {

    chat_init();

  }

  read_worlds_bin_fn_PS2();

  reaper_weapon_name_lookup();

  savegame_verify_user();

  iVar2 = dialog_level_is_base();

  puVar1 = DAT_00632d68;

  if (iVar2 == 0) {

    for (; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {

      iVar2 = puVar1[3];

      obj_velocity_commit(iVar2);

      if (DAT_00632a88 == 0) {

        return;

      }

      if (((*(uint *)(iVar2 + 0xd8) & 0xc000) == 0) && ((*(uint *)(iVar2 + 0xd8) & 0x40) == 0)) {

        objspec_dispatch_gate(iVar2);

        fVar5 = (float10)FUN_00518b70(iVar2,0);

        object_animate_process(iVar2,(float)fVar5);

        object_apply_location(iVar2);

      }

    }

  }

  else if (0 < *(int *)(DAT_006330e4 + 0x4a78)) {

    sound_play(*(int *)(DAT_006330e4 + 0x4a78));

  }

  if (DAT_00561f74 == 0) {

    if (DAT_005a85fc == 0) {

      uVar3 = AudioGetMasterVolume__Fv_8();

      render_farclip_set(uVar3);

    }

    else {

      menu_keymap_screen();

      DAT_00561f74 = 0;

      DAT_005a85fc = 0;

    }

  }

  else {

    defaults_reset_menu();

    DAT_00561f74 = 0;

    DAT_005a85fc = 0;

  }

  if (param_1 != 0) {

    editor_dump_objnames(0xbf800000);

  }

  iVar2 = FUN_0052c5c0();

  puVar1 = DAT_00632d68;

  if (iVar2 != 0) {

    for (; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {

      iVar2 = puVar1[3];

      if ((*(int *)(iVar2 + 0x1e0) == 0x5c) &&

         (iVar4 = kabutoai_is_punch_anim__FP6OBJECT(iVar2), iVar4 != 0)) {

        fx_spawn_checked(iVar2);

      }

    }

  }

  rpboat_lock_to_boat__FP6OBJECTT0();

  FUN_00494fb0();

  FUN_00494fe0();

  DAT_00632e40 = 0;

  DAT_00633014 = 0;

  time_get_ms();

  return;

}

/* ===== FUN_004EE800 @ 0x004EE800 ===== */
void FUN_004EE800(void)



{

  int iVar1;

  int iVar2;

  

  iVar1 = dialog_level_is_base();

  if (iVar1 != 0) {

    return;

  }

  FLK_FlickStop();

  iVar1 = DAT_00632d20 + 1;

  iVar2 = InitFxDict__Fv();

  if (iVar2 < iVar1) {

    gameover_menu();

    return;

  }

  AudioSetSpeakerConfig__F14SPEAKER_SYSTEM_4(iVar1);

  mission_texture_audio();

  return;

}

/* ===== game_files_check @ 0x004EE890 ===== */
undefined4 game_files_check(void)



{

  int iVar1;

  char *pcVar2;

  

  stream_00538800();

  iVar1 = FUN_00538540(s_world_gb2_005620f8);

  if (iVar1 != 0) {

    iVar1 = FUN_00539140(s_w_intro_bin_005620ec);

    if (iVar1 != 0) {

      iVar1 = FUN_00538540(s_story1_gti_005620e0);

      if (iVar1 != 0) {

        registry_volume_check();

        return 1;

      }

    }

  }

  pcVar2 = (char *)FUN_00507b00(s_ErrGameFiles_005620d0);

  if (pcVar2 == s_ErrGameFiles_005620d0) {

    pcVar2 = s_Missing_Game_Files___Corrupted_I_005620a8;

  }

  error_screen_show(pcVar2);

  return 0;

}

/* ===== intro_assets_check @ 0x004EE930 ===== */
undefined4 intro_assets_check(void)



{

  int iVar1;

  

  rndstart();

  math_sincos_table_init();

  DAT_006330e4 = 0;

  FUN_004ec7d0(&DAT_00632b20);

  iVar1 = game_files_check();

  if (iVar1 == 0) {

    return 0;

  }

  endDisplay__Fv_3();

  main_readdata_004adfa0();

  reread_globals_bin();

  worldlist_bin_load();

  main_readwrls_004b0e60(s_Intro_00562064);

  main_texture_00507f80();

  object_allocate_init();

  blood_init();

  main_blood_0040bab0();

  DAT_00632d20 = 0xffffffff;

  DAT_006330e4 = 0;

  ANM_DumpCluster();

  comm_critsec_init();

  weapondefs_load();

  return 1;

}

/* ===== shutdown_blood_cleanup @ 0x004EE9C0 ===== */
void shutdown_blood_cleanup(void)



{

  (*DAT_005dd290)();

  (*DAT_005dd31c)();

  (*DAT_005dd360)();

  gamespy_shutdown();

  FUN_0052E470();

  main_setupgam_004eda20();

  main_blood_0040bb10();

  main_blood_0040b290();

  main_object_00496b90();

  main_readgbls_004ae480();

  main_readwrls_004b42d0();

  releaseMpegBuffers__Fv();

  win95_text_0051b160();

  main_textget_005078e0();

  main_texture_00507e50();

  (*DAT_005dd310)();

  (*DAT_005dd284)();

  ANM_DumpCluster();

  main_xform_00517740();

  player_display_info();

  hash_pair_user();

  main_dedicated_00426510();

  return;

}

/* ===== anm_binder_free @ 0x004EEA40 ===== */
void anm_binder_free(undefined4 param_1,undefined1 param_2,undefined4 param_3)



{

  int iVar1;

  int iVar2;

  

  iVar2 = 6;

  do {

    switch(param_2) {

    case 1:

      iVar1 = crt_rand_scaled(4);

      iVar1 = *(int *)(&DAT_00562114 + iVar1 * 4);

      break;

    case 2:

      iVar1 = crt_rand_scaled(4);

      iVar1 = *(int *)(&DAT_00562104 + iVar1 * 4);

      break;

    case 3:

      iVar1 = crt_rand_scaled(4);

      iVar1 = *(int *)(&DAT_00562124 + iVar1 * 4);

      break;

    case 4:

      iVar1 = crt_rand_scaled(4);

      iVar1 = *(int *)(&DAT_00562134 + iVar1 * 4);

      break;

    default:

      goto switchD_004eea65_default;

    }

    if (-1 < iVar1) {

      ANM_BinderDestroy(param_1,1,iVar1,param_3,0x40a00000,0x41200000,0x41f00000,0x41400000,

                        0x41f00000,0x442f0000,0x44098000);

    }

switchD_004eea65_default:

    iVar2 = iVar2 + -1;

    if (iVar2 == 0) {

      return;

    }

  } while( true );

}

/* ===== smoke_object_spawn @ 0x004EEBD0 ===== */
void smoke_object_spawn(undefined4 param_1)



{

  undefined4 uVar1;

  int iVar2;

  

  iVar2 = object_allocate_type(0x286,0x80000000);

  object_change_ospec(iVar2,0x37);

  *(undefined4 *)(*(int *)(iVar2 + 0x100) + 8) = 0x3f000000;

  *(undefined4 *)(iVar2 + 0xc4) = 0x3f000000;

  *(undefined4 *)(*(int *)(iVar2 + 0x100) + 0xc) = 0x3fc00000;

  *(undefined4 *)(*(int *)(iVar2 + 0x100) + 0x10) = 0x3f400000;

  *(undefined4 *)(*(int *)(iVar2 + 0x100) + 4) = 0x3e4ccccd;

  **(undefined4 **)(iVar2 + 0x100) = 0x3f800000;

  object_set_location_p3d(iVar2,param_1);

  uVar1 = *(undefined4 *)(*(int *)(iVar2 + 0x100) + 0x10);

  *(uint *)(iVar2 + 0x1c8) = *(uint *)(iVar2 + 0x1c8) | 0x800000;

  *(undefined4 *)(iVar2 + 0xec) = uVar1;

  *(uint *)(*(int *)(iVar2 + 8) + 4) = *(uint *)(*(int *)(iVar2 + 8) + 4) | 4;

  main_smoke_004f9170(iVar2);

  return;

}

/* ===== calc_2pts_to_bbox__FP3P3DT0P4BBOX @ 0x004EECB0 ===== */
/* PS2 candidate: calc_2pts_to_bbox__FP3P3DT0P4BBOX (conf 0.799) */



void calc_2pts_to_bbox__FP3P3DT0P4BBOX(float *param_1,float *param_2,float *param_3)



{

  float fVar1;

  

  if (*param_2 <= *param_1) {

    *param_3 = *param_2;

    fVar1 = *param_1;

  }

  else {

    *param_3 = *param_1;

    fVar1 = *param_2;

  }

  param_3[3] = fVar1;

  if (param_2[1] <= param_1[1]) {

    param_3[1] = param_2[1];

    fVar1 = param_1[1];

  }

  else {

    param_3[1] = param_1[1];

    fVar1 = param_2[1];

  }

  param_3[4] = fVar1;

  if (param_1[2] < param_2[2]) {

    param_3[2] = param_1[2];

    param_3[5] = param_2[2];

    return;

  }

  param_3[2] = param_2[2];

  param_3[5] = param_1[2];

  return;

}

/* ===== line_of_sight_grid @ 0x004EED30 ===== */
/* PS2 candidate: line_of_sight_grid (conf 0.341) */



undefined4 line_of_sight_grid(float *param_1,float *param_2)



{

  float *pfVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int local_28;

  float local_24;

  float local_20;

  float local_1c;

  int local_18;

  undefined1 local_14 [4];

  undefined1 local_10 [4];

  float local_c;

  float local_8;

  float local_4;

  

  pfVar1 = param_1;

  local_c = *param_2;

  local_8 = param_2[1];

  local_4 = param_2[2];

  grid_coords_from_floats(param_1,&param_1,&local_28);

  grid_coords_from_floats(&local_c,local_10,local_14);

  local_24 = local_c - *pfVar1;

  iVar3 = 1;

  param_2 = (float *)0x1;

  local_20 = local_8 - pfVar1[1];

  if (local_20 < 0.0) {

    iVar3 = -1;

    local_20 = -local_20;

    param_2 = (float *)0xffffffff;

  }

  iVar4 = 1;

  local_18 = 1;

  if (local_24 < 0.0) {

    iVar4 = -1;

    local_24 = -local_24;

    local_18 = -1;

  }

  if (local_24 <= local_20) {

    local_1c = local_24 / local_20;

    param_2 = (float *)(((*pfVar1 -

                         ((float)(int)param_1 * *(float *)(DAT_006330e4 + 0x1c0) +

                         *(float *)(DAT_006330e4 + 0x1c8))) / *(float *)(DAT_006330e4 + 0x1c0) - 0.5

                        ) * (float)local_18);

    if (0.0 < local_20) {

      do {

        local_20 = local_20 - *(float *)(DAT_006330e4 + 0x1c0);

        iVar2 = collide_line_grid(pfVar1,&local_c,param_1,local_28);

        if (iVar2 != 0) {

          return 0;

        }

        iVar2 = iVar4;

        if ((float)param_2 <= 0.2) {

          if ((float)param_2 < -0.2) {

            iVar2 = -iVar4;

            goto LAB_004eefe9;

          }

        }

        else {

LAB_004eefe9:

          iVar2 = collide_line_grid(pfVar1,&local_c,iVar2 + (int)param_1,local_28);

          if (iVar2 != 0) {

            return 0;

          }

        }

        param_2 = (float *)((float)param_2 + local_1c);

        if (0.5 <= (float)param_2) {

          param_2 = (float *)((float)param_2 - 1.0);

          param_1 = (float *)((int)param_1 + iVar4);

        }

        local_28 = local_28 + iVar3;

        if (local_20 <= 0.0) {

          return 1;

        }

      } while( true );

    }

  }

  else {

    local_1c = local_20 / local_24;

    param_2 = (float *)(((pfVar1[1] -

                         ((float)local_28 * *(float *)(DAT_006330e4 + 0x1c0) +

                         *(float *)(DAT_006330e4 + 0x1cc))) / *(float *)(DAT_006330e4 + 0x1c0) - 0.5

                        ) * (float)(int)param_2);

    if (0.0 < local_24) {

      do {

        local_24 = local_24 - *(float *)(DAT_006330e4 + 0x1c0);

        iVar2 = collide_line_grid(pfVar1,&local_c,param_1,local_28);

        if (iVar2 != 0) {

          return 0;

        }

        iVar2 = iVar3;

        if ((float)param_2 <= 0.2) {

          if ((float)param_2 < -0.2) {

            iVar2 = -iVar3;

            goto LAB_004eeeb2;

          }

        }

        else {

LAB_004eeeb2:

          iVar2 = collide_line_grid(pfVar1,&local_c,param_1,iVar2 + local_28);

          if (iVar2 != 0) {

            return 0;

          }

        }

        param_2 = (float *)((float)param_2 + local_1c);

        if (0.5 <= (float)param_2) {

          param_2 = (float *)((float)param_2 - 1.0);

          local_28 = local_28 + iVar3;

        }

        param_1 = (float *)((int)param_1 + iVar4);

        if (local_24 <= 0.0) {

          return 1;

        }

      } while( true );

    }

  }

  return 1;

}

/* ===== ai_class_filter @ 0x004EF070 ===== */
undefined4

ai_class_filter(undefined4 param_1,undefined4 param_2,int param_3,int param_4,byte param_5)



{

  undefined4 *puVar1;

  int iVar2;

  int iVar3;

  undefined1 local_18 [24];

  

  iVar2 = line_of_sight_grid(param_1,param_2);

  if (iVar2 == 0) {

    return 0;

  }

  calc_2pts_to_bbox__FP3P3DT0P4BBOX(param_1,param_2,local_18);

  puVar1 = DAT_00632d7c;

  do {

    if (puVar1 == (undefined4 *)0x0) {

      return 1;

    }

    iVar2 = puVar1[3];

    if ((*(uint *)(iVar2 + 0xd8) & 0x4000c000) == 0 && (*(uint *)(iVar2 + 0x1c8) & 0x800) == 0) {

      iVar3 = 0;

      if (0 < param_3) {

        do {

          if (*(int *)(iVar2 + 4) == *(int *)(param_4 + iVar3 * 4)) {

            if (iVar3 < param_3) goto LAB_004ef171;

            break;

          }

          iVar3 = iVar3 + 1;

        } while (iVar3 < param_3);

      }

      iVar3 = collide_bbox_bbox(local_18,iVar2 + 0x27c);

      if ((iVar3 != 0) && (iVar3 = collide_line_bbox(0,param_1,param_2,iVar2 + 0x27c), iVar3 != 0))

      {

        if (((param_5 & 1) == 0) && ((*(uint *)(iVar2 + 0x1c8) & 0x1008) == 0)) {

          iVar2 = geom_point_line_dist(param_1,param_2,iVar2 + 0xa0,*(undefined4 *)(iVar2 + 0x154));

        }

        else {

          iVar2 = los_line_check(param_1,param_2,iVar2,0,0);

        }

        if (iVar2 != 0) {

          return 0;

        }

      }

    }

LAB_004ef171:

    puVar1 = (undefined4 *)*puVar1;

  } while( true );

}

/* ===== obj_health_ratio_update @ 0x004EF190 ===== */
undefined4 obj_health_ratio_update(int param_1)



{

  float fVar1;

  float fVar2;

  

  fVar1 = 1.0 - *(float *)(param_1 + 0x278) / *(float *)(param_1 + 0x1c0);

  if (fVar1 < 0.0 != (fVar1 == 0.0)) {

    *(undefined4 *)(param_1 + 0x14) = 0;

    *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) | 0x80;

    return 1;

  }

  fVar1 = fVar1 - 0.01;

  fVar2 = *(float *)(DAT_00632ed8 + 0xb7c) * 0.01;

  if (fVar1 < fVar2 != (fVar1 == fVar2)) {

    *(float *)(param_1 + 0x14) = fVar2;

    *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) | 0x80;

    return 0;

  }

  fVar2 = *(float *)(DAT_00632ed8 + 0xb78) * 0.01;

  if (fVar1 < fVar2 != (fVar1 == fVar2)) {

    *(float *)(param_1 + 0x14) = fVar2;

    *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) | 0x80;

    return 0;

  }

  fVar2 = *(float *)(DAT_00632ed8 + 0xb74) * 0.01;

  if (fVar1 < fVar2 != (fVar1 == fVar2)) {

    *(float *)(param_1 + 0x14) = fVar2;

    *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) | 0x80;

    return 0;

  }

  *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) | 0x80;

  *(undefined4 *)(param_1 + 0x14) = 0x3f800000;

  return 0;

}

/* ===== cspec_004ef280 @ 0x004EF280 ===== */
void cspec_004ef280(int param_1)



{

  if ((*(byte *)(param_1 + 0xe0) & 1) == 0) {

    *(undefined4 *)(param_1 + 0x278) = 0;

    ObjectSetAnim(param_1,1,0x84,0,0,0);

    *(undefined4 *)(param_1 + 0x14) = 0x3f800000;

    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 1;

  }

  obj_health_ratio_update(param_1);

  return;

}

/* ===== ANM_AnimGetImage @ 0x004EF2D0 ===== */
uint ANM_AnimGetImage(int param_1)



{

  return *(uint *)(param_1 + 0xe0) & 2;

}

/* ===== cspec_004ef2e0 @ 0x004EF2E0 ===== */
void cspec_004ef2e0(undefined4 param_1,float param_2,int param_3,undefined4 param_4,int param_5)



{

  float fVar1;

  float fVar2;

  float fVar3;

  

  if ((param_2 < 0.0 == (param_2 == 0.0)) &&

     (*(float *)(param_3 + 0x278) < *(float *)(param_3 + 0x1c0))) {

    fVar1 = *(float *)(param_3 + 0x278);

    param_2 = param_2 + *(float *)(param_3 + 0x278);

    *(float *)(param_3 + 0x278) = param_2;

    if (*(float *)(param_3 + 0x1c0) < param_2) {

      *(undefined4 *)(param_3 + 0x278) = *(undefined4 *)(param_3 + 0x1c0);

    }

    fVar2 = 1.0 / *(float *)(param_3 + 0x1c0);

    fVar3 = (1.0 - fVar1 * fVar2) * 100.0;

    fVar1 = (1.0 - fVar2 * *(float *)(param_3 + 0x278)) * 100.0 - 0.01;

    if ((param_5 != 0) &&

       ((((*(float *)(DAT_00632ed8 + 0xb74) < fVar3 && (fVar1 <= *(float *)(DAT_00632ed8 + 0xb74)))

         || ((*(float *)(DAT_00632ed8 + 0xb78) < fVar3 &&

             (fVar1 <= *(float *)(DAT_00632ed8 + 0xb78))))) ||

        ((*(float *)(DAT_00632ed8 + 0xb7c) < fVar3 && (fVar1 <= *(float *)(DAT_00632ed8 + 0xb7c)))))

       )) {

      fx_get_free_effect__Fv();

      if ((fVar3 <= *(float *)(DAT_00632ed8 + 0xb80)) || (*(float *)(DAT_00632ed8 + 0xb80) < fVar1))

      {

        sound_play_3dpos(0x614,param_5);

      }

    }

    if ((*(float *)(DAT_00632ed8 + 0xb80) < fVar3) && (fVar1 <= *(float *)(DAT_00632ed8 + 0xb80))) {

      if (param_5 != 0) {

        fx_get_free_effect__Fv();

      }

      if (((byte)*(undefined4 *)(param_3 + 0xdc) & 0xf) == 2) {

        voice_event_trigger(param_3);

      }

      *(uint *)(param_3 + 0x1cc) = *(uint *)(param_3 + 0x1cc) | 1;

      *(uint *)(param_3 + 0xe0) = *(uint *)(param_3 + 0xe0) | 2;

      sound_play_3dpos(0x615,param_3 + 0xa0);

      object_destroy(param_3);

    }

  }

  return;

}

/* ===== target_can_be_hurt @ 0x004EF510 ===== */
bool target_can_be_hurt(int param_1)



{

  int iVar1;

  

  if (*(float *)(param_1 + 0x1c0) <= *(float *)(param_1 + 0x278)) {

    return false;

  }

  if ((*(byte *)(param_1 + 0xe0) & 8) != 0) {

    return false;

  }

  if (*(int *)(param_1 + 0x210) != 0) {

    return false;

  }

  iVar1 = ObjIsReaper(*(undefined4 *)(param_1 + 0x274));

  return iVar1 == 0;

}

/* ===== ai_anim_select_mode @ 0x004EF560 ===== */
int ai_anim_select_mode(int param_1,int param_2)



{

  undefined4 uVar1;

  int iVar2;

  undefined4 uVar3;

  

  uVar1 = *(undefined4 *)(param_1 + 0x274);

  iVar2 = meccbasepit_bldg_from_object(uVar1);

  if (iVar2 == 0) {

    if (((param_2 == 0) && (iVar2 = bldg_anim_select(uVar1,1), iVar2 == 0)) &&

       (iVar2 = bldg_anim_select(uVar1,9), iVar2 == 0)) {

      uVar3 = 9;

LAB_004ef5b0:

      iVar2 = base_slot_built_check(uVar1,uVar3);

      return (-(uint)(iVar2 != 0) & 0xfffffffe) + 1;

    }

  }

  else if (param_2 == 0) {

    iVar2 = bldg_anim_select(uVar1,1);

    if ((iVar2 == 0) && (iVar2 = bldg_anim_select(uVar1,0xe), iVar2 == 0)) {

      uVar3 = 0xe;

      goto LAB_004ef5b0;

    }

  }

  else {

    if (param_2 == 4) {

      iVar2 = bldg_anim_select(uVar1,5);

      if (iVar2 == 0) {

        return 5;

      }

    }

    else if (param_2 != 5) {

      if (param_2 == 7) {

        iVar2 = bldg_anim_select(uVar1,8);

        if (iVar2 != 0) {

          return -1;

        }

        return 8;

      }

      if (param_2 == 9) {

        iVar2 = bldg_anim_select(uVar1,10);

        if (iVar2 == 0) {

          return 10;

        }

      }

      else if (param_2 != 10) {

        if (param_2 == 0x11) {

          iVar2 = bldg_anim_select(uVar1,0x12);

          if (iVar2 == 0) {

            return 0x12;

          }

        }

        else if (param_2 != 0x12) {

          if (param_2 == 0x14) {

            iVar2 = bldg_anim_select(uVar1,0x15);

            if (iVar2 != 0) {

              return -1;

            }

            return 0x15;

          }

          if (param_2 == 0x16) {

            iVar2 = bldg_anim_select(uVar1,0x17);

            if (iVar2 == 0) {

              return 0x17;

            }

          }

          else if (param_2 != 0x17) {

            return -1;

          }

          iVar2 = bldg_anim_select(uVar1,0x18);

          if (iVar2 != 0) {

            return -1;

          }

          return 0x18;

        }

        iVar2 = bldg_anim_select(uVar1,0x13);

        if (iVar2 != 0) {

          return -1;

        }

        return 0x13;

      }

      iVar2 = bldg_anim_select(uVar1,0xb);

      if (iVar2 != 0) {

        return -1;

      }

      return 0xb;

    }

    iVar2 = bldg_anim_select(uVar1,6);

    if (iVar2 == 0) {

      return 6;

    }

  }

  return -1;

}

/* ===== smartie_ai_main @ 0x004EF730 ===== */
void smartie_ai_main(int param_1)



{

  float *pfVar1;

  uint *puVar2;

  undefined2 uVar3;

  int iVar4;

  uint uVar5;

  int iVar6;

  undefined4 uVar7;

  undefined4 *puVar8;

  float fVar9;

  int iVar10;

  int iVar11;

  int *piVar12;

  float10 fVar13;

  float10 fVar14;

  char *pcVar15;

  undefined4 uVar16;

  undefined1 *puVar17;

  undefined4 uVar18;

  undefined4 uVar19;

  undefined4 uVar20;

  float fVar21;

  undefined4 uVar22;

  float fVar23;

  undefined4 uVar24;

  float fStack_264;

  undefined4 uStack_260;

  undefined4 uStack_25c;

  undefined4 *puStack_258;

  float fStack_254;

  float fStack_250;

  float fStack_24c;

  float fStack_248;

  float fStack_244;

  float fStack_240;

  float fStack_23c;

  undefined1 uStack_235;

  undefined1 auStack_234 [16];

  undefined4 uStack_224;

  undefined4 uStack_220;

  int iStack_21c;

  undefined1 auStack_200 [512];

  

  iVar11 = *(int *)(param_1 + 0x100);

  if (DAT_00632e74 != 0) {

    return;

  }

  if (*(int *)(param_1 + 0x210) != 0) {

    iVar6 = *(int *)(*(int *)(param_1 + 0x210) + 0x1e0);

    if (iVar6 == 1) {

      return;

    }

    if (iVar6 == 0x4c) {

      return;

    }

  }

  if (*(int *)(param_1 + 0xe4) == 0x35) {

    return;

  }

  if (*(float *)(iVar11 + 0x10) == 0.0) {

    *(undefined4 *)(iVar11 + 0x10) = *(undefined4 *)(param_1 + 0xc4);

  }

  if ((*(int *)(param_1 + 0xe4) != 0x13) && (*(int *)(param_1 + 0xe4) != 0x32)) {

    if (*(int *)(iVar11 + 0x4c) == 0) {

      *(undefined4 *)(param_1 + 0xc4) = *(undefined4 *)(iVar11 + 0x10);

    }

    if (*(int *)(iVar11 + 0x30) != 0) {

      *(undefined4 *)(*(int *)(iVar11 + 0x30) + 0xc4) = *(undefined4 *)(iVar11 + 0x14);

    }

    if (((DAT_00632bb0 != 0) && (*(int *)(param_1 + 0x274) == DAT_00632bbc)) &&

       (*(int *)(iVar11 + 0x4c) == 0)) {

      iVar6 = *(int *)(*(int *)(*(int *)(param_1 + 0x274) + 0x100) + 0x368);

      if ((-1 < iVar6) && (iVar6 == *(int *)(iVar11 + 0x1c))) {

        *(float *)(param_1 + 0xc4) = *(float *)(iVar11 + 0x10) * 6.0;

      }

      if (*(int *)(iVar11 + 0x30) != 0) {

        *(float *)(*(int *)(iVar11 + 0x30) + 0xc4) =

             (*(float *)(param_1 + 0xc4) / *(float *)(iVar11 + 0x10)) * *(float *)(iVar11 + 0x14);

      }

    }

  }

  if (*(char *)(iVar11 + 0x80) == '\0') {

    smartie_get_name__FP6OBJECT(param_1);

  }

  if (*(int *)(iVar11 + 0xa4) == 0) {

    *(undefined4 *)(iVar11 + 0xa4) = *(undefined4 *)(param_1 + 0x1d0);

  }

  if ((((*(byte *)(param_1 + 0xe0) & 8) == 0) || (*(int *)(param_1 + 0xe8) == 10)) &&

     (*(int *)(param_1 + 0xe4) != 0x41)) {

    *(undefined4 *)(param_1 + 0x1d0) = *(undefined4 *)(iVar11 + 0xa4);

  }

  else {

    *(uint *)(param_1 + 0x1d0) = *(uint *)(param_1 + 0x1d0) & 0xfffff000;

  }

  *(uint *)(param_1 + 0xdc) = *(uint *)(param_1 + 0xdc) | 0x10;

  iVar4 = fx_create(param_1);

  iVar6 = *(int *)(param_1 + 0xe4);

  if (iVar4 == 0) {

    iVar11 = *(int *)(param_1 + 0x100);

    switch(iVar6) {

    case 0x13:

      iVar6 = *(int *)(param_1 + 0x274);

      if ((iVar6 != 0) && (iVar4 = ObjIsReaper(iVar6), iVar4 != 0)) {

        fStack_254 = *(float *)(iVar6 + 0x298) * 5.0;

        pfVar1 = (float *)(param_1 + 0xa0);

        fStack_248 = fStack_254 + *(float *)(iVar6 + 0xa0);

        uStack_260 = *(float *)(iVar6 + 0x2a8) * 5.0;

        fStack_244 = uStack_260 + *(float *)(iVar6 + 0xa4);

        fStack_24c = *(float *)(iVar6 + 0xa8) + 3.0;

        fStack_254 = *(float *)(iVar6 + 0xa0) - fStack_254;

        fStack_250 = *(float *)(iVar6 + 0xa4) - uStack_260;

        fStack_240 = fStack_24c;

        fVar13 = (float10)FUN_0050a610(pfVar1,&fStack_248);

        fStack_264 = (float)fVar13;

        fVar13 = (float10)FUN_0050a610(pfVar1,&fStack_254);

        if (fVar13 < (float10)fStack_264) {

          fStack_248 = fStack_254;

          fStack_244 = fStack_250;

          fStack_240 = fStack_24c;

        }

        if (25.0 <= fStack_264) {

          fVar9 = 0.12;

        }

        else {

          fVar9 = fStack_264 * 0.0047999998;

        }

        fVar23 = 1.0 - fVar9;

        *(undefined4 *)(param_1 + 200) = *(undefined4 *)(iVar6 + 200);

        object_set_location(param_1,fVar23 * *pfVar1 + fVar9 * fStack_248,

                            fVar9 * fStack_244 + fVar23 * *(float *)(param_1 + 0xa4),

                            fVar9 * fStack_240 + fVar23 * *(float *)(param_1 + 0xa8));

      }

      if (*(int *)(param_1 + 0xe8) == 10) {

        fVar13 = (float10)FUN_00518b70(param_1,0);

        fVar13 = fVar13 + (float10)*(float *)(iVar11 + 0x9c);

        *(float *)(iVar11 + 0x9c) = (float)fVar13;

        if (((float10)*(int *)(DAT_00632ed8 + 0x1584) < fVar13) &&

           (*(int *)(param_1 + 0x18c) == *(int *)(DAT_00632a88 + 0x18c))) {

          uVar7 = TextGetPtrRandom(s_SmChStillStolen_00562240,4,1);

          chat_insert_name(iVar11 + 0x80,uVar7);

          *(undefined4 *)(iVar11 + 0x9c) = 0;

        }

      }

      break;

    default:

      if (*(int *)(param_1 + 4) == 0xb) {

        if (*(int *)(param_1 + 0x168) == 0) {

          fVar13 = (float10)distancesq2d__FP3P3DT0(param_1 + 0xa0,iVar11 + 0x58);

          if (fVar13 <= (float10)9.0) {

            object_set_location_p3d(param_1,iVar11 + 0x58);

            *(undefined1 *)(param_1 + 0x20b) = 0;

            *(undefined1 *)(param_1 + 0x20a) = 0;

            *(undefined1 *)(param_1 + 0x208) = 0;

          }

          else {

            ai_moveonly_set_goal();

          }

        }

        else {

          ai_goal_process(param_1);

        }

      }

      break;

    case 0x21:

      if (*(int *)(param_1 + 0x10) == 0x5c) {

        uVar7 = base_get_base_building(*(undefined4 *)(param_1 + 0x274));

        bldg_get_refpt_worldloc(uVar7,*(undefined4 *)(iVar11 + 0x28),&fStack_254);

        object_set_location_p3d(param_1,&fStack_254);

      }

      else if (*(int *)(param_1 + 0x10) == 0x34) {

        puStack_258 = (undefined4 *)

                      (*(float *)(param_1 + 0x14) / **(float **)(*(int *)(param_1 + 8) + 0xd8));

        bldg_get_refpt_worldloc

                  (*(undefined4 *)(param_1 + 0x274),*(undefined4 *)(iVar11 + 0x28),&fStack_254);

        fVar9 = 1.0 - (float)puStack_258;

        object_set_location(param_1,fStack_254 * (float)puStack_258 + fVar9 * *(float *)(iVar11 + 4)

                            ,fStack_250 * (float)puStack_258 + fVar9 * *(float *)(iVar11 + 8),

                            fStack_24c * (float)puStack_258 + fVar9 * *(float *)(iVar11 + 0xc));

      }

      else {

        *(undefined4 *)(param_1 + 0xe4) = 3;

      }

      break;

    case 0x27:

      fVar13 = (float10)FUN_00518b70(param_1,0);

      fVar13 = (float10)*(float *)(param_1 + 0xec) - fVar13;

      *(float *)(param_1 + 0xec) = (float)fVar13;

      if (fVar13 < (float10)0.0 != (fVar13 == (float10)0.0)) {

        *(undefined4 *)(param_1 + 0xe4) = 3;

      }

      iVar6 = meccbasepit_bldg_from_object(*(undefined4 *)(param_1 + 0x274));

      if (iVar6 == 0) {

        fStack_264 = (float)base_slot10_get(*(undefined4 *)(param_1 + 0x274));

      }

      else {

        fStack_264 = (float)base_slot15_get(*(undefined4 *)(param_1 + 0x274));

      }

      bldg_get_refpt_worldloc(fStack_264,*(undefined4 *)(iVar11 + 0x28),&fStack_254);

      puStack_258 = (undefined4 *)(*(float *)(param_1 + 0xec) * 0.5);

      fVar9 = 1.0 - (float)puStack_258;

      object_set_location(param_1,fStack_254 * fVar9 +

                                  (float)puStack_258 * *(float *)(iVar11 + 0x58),

                          fStack_250 * fVar9 + (float)puStack_258 * *(float *)(iVar11 + 0x5c),

                          fStack_24c * fVar9 + (float)puStack_258 * *(float *)(iVar11 + 0x60));

      if (((float)puStack_258 < 0.5) && (*(int *)(iVar11 + 0x30) == 0)) {

        iVar6 = *(int *)(param_1 + 0x100);

        if (*(int *)(iVar6 + 0x30) != 0) {

          *(undefined4 *)(*(int *)(iVar6 + 0x30) + 0x210) = 0;

          object_destroy(*(undefined4 *)(iVar6 + 0x30));

          *(undefined4 *)(iVar6 + 0x30) = 0;

          *(undefined4 *)(iVar6 + 0x14) = 0x41d80000;

          iVar6 = reaper_0052e4a0(param_1);

          if (iVar6 != 0) {

            reaper_00530bd0(param_1,0,0,0,0x14,0);

          }

        }

        smartie_make_held_object__FP6OBJECTi(param_1,0x2f9);

        bldg_get_refpt_worldlocdir

                  (fStack_264,*(undefined4 *)(iVar11 + 0x28),(float *)(iVar11 + 0x58),param_1 + 200)

        ;

        *(undefined4 *)(iVar11 + 0x28) = 10;

      }

      break;

    case 0x32:

      smartie_handle_reaper_grab__FP6OBJECTP14ObjSpecSmartie(param_1,iVar11);

      break;

    case 0x37:

      ai_clear_move_goal(param_1);

      *(undefined1 *)(param_1 + 0x20b) = 0;

      *(undefined1 *)(param_1 + 0x20a) = 0;

      *(undefined1 *)(param_1 + 0x208) = 0;

      *(undefined4 *)(param_1 + 0x184) = 0x3f800000;

      if (DAT_00632bb8 != 0) {

        *(undefined4 *)(param_1 + 0x184) = 0;

      }

      if (*(float *)(iVar11 + 0x18) == 0.0) {

        iVar6 = *(int *)(param_1 + 0x100);

        iVar4 = *(int *)(iVar6 + 0x48);

        if (iVar4 != 0) {

          fx_delete(iVar4);

          *(undefined4 *)(iVar6 + 0x48) = 0;

        }

      }

      *(undefined4 *)(iVar11 + 0x18) = *(undefined4 *)(DAT_00632ed8 + 0x624);

      break;

    case 0x38:

      *(undefined4 *)(param_1 + 0x184) = 0;

      *(undefined1 *)(param_1 + 0x208) = 0;

      *(undefined1 *)(param_1 + 0x20b) = 0;

      *(undefined1 *)(param_1 + 0x20a) = 0;

      fVar13 = (float10)FUN_00518b70(param_1,0);

      fVar13 = (float10)*(float *)(param_1 + 0xec) - fVar13;

      *(float *)(param_1 + 0xec) = (float)fVar13;

      if ((fVar13 < (float10)0.0 != (fVar13 == (float10)0.0)) &&

         (iVar11 = base_has_partyhouse(*(undefined4 *)(param_1 + 0x274)), iVar11 != 0)) {

        *(undefined4 *)(param_1 + 0xe4) = 0x1e;

      }

    }

    obj_alpha_fade_update(param_1);

    player_pitch_update(param_1);

    obj_scale_compute(param_1);

    FUN_004a73a0(param_1);

    FUN_004a7400(param_1);

    return;

  }

  if ((((iVar6 == 0x13) || (iVar6 == 0x14)) || (iVar6 == 0x32)) &&

     ((iVar6 = *(int *)(param_1 + 0x274), iVar6 != 0 &&

      (((char)((uint)*(undefined4 *)(iVar6 + 0xd8) >> 8) < '\0' ||

       (*(float *)(iVar6 + 0x1c0) <= *(float *)(iVar6 + 0x278))))))) {

    *(undefined4 *)(iVar11 + 0x54) = 0;

    if (*(int *)(param_1 + 0xe4) == 0x32) {

      smartie_escape_reaper_grab(param_1);

    }

    else {

      iVar6 = *(int *)(param_1 + 0x274);

      smartie_unlock_from_player(param_1,iVar6,0);

      iVar4 = reaper_0052e4a0(param_1);

      if (iVar4 != 0) {

        uStack_260 = *(float *)(iVar6 + 0x188);

        uStack_25c = 0;

        reaper_00530bd0(param_1,0,2,0,5,&uStack_260);

      }

    }

  }

  if (*(int *)(param_1 + 0xe4) != 0) goto LAB_004f015a;

  switch(*(undefined4 *)(param_1 + 0xe8)) {

  case 1:

    uVar5 = *(uint *)(param_1 + 0xe0) | 1;

    goto LAB_004f014e;

  case 2:

    uVar5 = *(uint *)(param_1 + 0xe0) | 0x11;

    goto LAB_004f014e;

  case 3:

    uVar5 = *(uint *)(param_1 + 0xe0) | 0x20;

LAB_004f014e:

    *(uint *)(param_1 + 0xe0) = uVar5;

switchD_004efef7_caseD_4:

    *(undefined4 *)(param_1 + 0xe4) = 3;

    break;

  default:

    goto switchD_004efef7_caseD_4;

  case 5:

    *(undefined4 *)(param_1 + 0xe4) = 0x50;

    fVar13 = (float10)rndfloatrange(0x41200000,0x41a00000);

    *(float *)(param_1 + 0xf0) = (float)fVar13;

    for (puVar8 = DAT_00632d68; puVar8 != (undefined4 *)0x0; puVar8 = (undefined4 *)*puVar8) {

      iVar6 = puVar8[3];

      if (*(int *)(iVar6 + 4) == 0x3e9) {

        fStack_264 = 0.0;

        goto LAB_004f00b0;

      }

    }

    goto LAB_004f0111;

  case 6:

    *(undefined4 *)(param_1 + 0xe4) = 0x3c;

    break;

  case 7:

    *(undefined4 *)(param_1 + 0xe4) = 0x25;

    *(uint *)(param_1 + 0x1c8) = *(uint *)(param_1 + 0x1c8) & 0xfffdffff;

    smartie_make_held_object__FP6OBJECTi(param_1,0x314);

    ObjectSetAnim(param_1,0x7a,0x20,0,0,0x3f2aaaab);

    break;

  case 8:

    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 1;

    *(uint *)(param_1 + 0x1c8) = *(uint *)(param_1 + 0x1c8) & 0xfffdffff | 0xe00;

    uVar7 = 0x82;

    goto LAB_004effe4;

  case 9:

    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 1;

    *(uint *)(param_1 + 0x1c8) = *(uint *)(param_1 + 0x1c8) & 0xfffdffff | 0xe00;

    uVar7 = 0x83;

LAB_004effe4:

    *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) | 0x10;

    ObjectSetAnim(param_1,uVar7,0x21,0,0,0x3f2aaaab);

    *(undefined4 *)(param_1 + 0xe4) = 0x3e;

    break;

  case 10:

    iVar6 = dialog_level_is_base();

    if (iVar6 == 0) {

      *(undefined4 *)(param_1 + 0x18c) = 1;

      *(undefined4 *)(param_1 + 0xe4) = 0x33;

      *(undefined4 *)(iVar11 + 0xb4) = *(undefined4 *)(param_1 + 200);

      puVar8 = (undefined4 *)(iVar11 + 0xa8);

      *puVar8 = *(undefined4 *)(param_1 + 0xa0);

      *(undefined4 *)(iVar11 + 0xac) = *(undefined4 *)(param_1 + 0xa4);

      *(undefined4 *)(iVar11 + 0xb0) = *(undefined4 *)(param_1 + 0xa8);

      fVar13 = (float10)get_floor_z_point(puVar8);

      *(float *)(iVar11 + 0xb0) = (float)fVar13;

      *(undefined4 *)(param_1 + 0xa0) = *puVar8;

      *(undefined4 *)(param_1 + 0xa4) = *(undefined4 *)(iVar11 + 0xac);

      *(undefined4 *)(param_1 + 0xa8) = *(undefined4 *)(iVar11 + 0xb0);

      object_copy_posdirinfo(param_1);

    }

  }

LAB_004f015a:

  if ((*(byte *)(param_1 + 0xe0) & 0x10) != 0) {

    if (0.0 <= *(float *)(param_1 + 0xec)) {

      fVar13 = (float10)FUN_00518b70(param_1,0);

      *(float *)(param_1 + 0xec) = (float)((float10)*(float *)(param_1 + 0xec) - fVar13);

    }

    else {

      iVar6 = smartie_check_follow__FP6OBJECTf(param_1,0x40e00000);

      if (iVar6 != 0) {

        smartie_board_player__FP6OBJECTT0i(param_1,iVar6,1);

      }

      if (*(int *)(param_1 + 0xe4) == 0x13) {

        *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xffffffee;

      }

    }

  }

  if ((*(byte *)(param_1 + 0xe0) & 1) != 0) {

    if ((*(int *)(param_1 + 0x10) == 0x42) && (*(int *)(param_1 + 0x274) == 0)) {

      uVar7 = object_spawn_small(param_1,0x48,0,0,0);

      *(undefined4 *)(param_1 + 0x274) = uVar7;

    }

    if (*(int *)(param_1 + 0x10) != 0x2d) {

      return;

    }

    if (*(int *)(param_1 + 0x274) != 0) {

      return;

    }

    uVar7 = object_spawn_small(param_1,0x48,0,2,0);

    *(undefined4 *)(param_1 + 0x274) = uVar7;

    return;

  }

  *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) & 0xfcffffff;

  if ((*(int *)(param_1 + 0x210) != 0) && (*(int *)(param_1 + 0xe4) == 3)) {

    return;

  }

  iVar6 = *(int *)(param_1 + 0xe4);

  if ((((iVar6 == 0x22) || (iVar6 == 0x23)) || (iVar6 == 0x26)) ||

     ((iVar6 == 0x27 || (iVar6 == 0x28)))) {

    if (*(float *)(iVar11 + 0x98) != 0.0) {

      fVar13 = (float10)FUN_00518b70(param_1,0);

      fVar13 = (float10)*(float *)(iVar11 + 0x98) - fVar13;

      *(float *)(iVar11 + 0x98) = (float)fVar13;

      if (fVar13 < (float10)0.0 == (fVar13 == (float10)0.0)) goto LAB_004f02e2;

      iVar6 = crt_rand_scaled(100);

      if (iVar6 < 0x32) {

        uVar7 = 0x6b9;

      }

      else {

        uVar7 = 0x6ba;

      }

      sound_play_obj(uVar7,param_1);

    }

    fVar13 = (float10)rndfloatrange(0x41200000,0x41a00000);

    *(float *)(iVar11 + 0x98) = (float)fVar13;

  }

LAB_004f02e2:

  iVar6 = *(int *)(param_1 + 0xe4);

  if (((((iVar6 == 3) || (iVar6 == 0x50)) || ((iVar6 == 0x51 || ((4 < iVar6 && (iVar6 < 8)))))) ||

      ((0x14 < iVar6 && (iVar6 < 0x19)))) ||

     ((((0x1d < iVar6 && (iVar6 < 0x27)) || (iVar6 == 0x36)) || (iVar6 == 0x38)))) {

    uStack_260 = 10.0;

    if (*(int *)(param_1 + 0xe8) != 4) {

      uStack_260 = 7.0;

    }

    iVar6 = smartie_check_follow__FP6OBJECTf(param_1,uStack_260);

    if (iVar6 != 0) {

      smartie_board_player__FP6OBJECTT0i(param_1,iVar6,1);

    }

  }

  ANM_DumpCluster(param_1);

  switch(*(undefined4 *)(param_1 + 0xe4)) {

  case 3:

  case 4:

    fVar13 = (float10)FUN_00518b70(param_1,0);

    *(float *)(param_1 + 0xec) = (float)((float10)*(float *)(param_1 + 0xec) - fVar13);

    if ((*(byte *)(param_1 + 0xe0) & 8) == 0) {

      iVar6 = dialog_level_is_base();

      if ((iVar6 == 0) && (iVar6 = ObjIsKabuto(DAT_00632a88), iVar6 != 0)) {

        uStack_260 = *(float *)(DAT_00632ed8 + 0x1578);

        fVar13 = (float10)distancesq2d__FP3P3DT0(DAT_00632a88 + 0xa0,param_1 + 0xa0);

        if (fVar13 < (float10)uStack_260 * (float10)uStack_260) {

          fStack_23c = *(float *)(param_1 + 0x100);

          fStack_264 = 0.0;

          for (puVar8 = DAT_00632d6c; puVar8 != (undefined4 *)0x0; puVar8 = (undefined4 *)*puVar8) {

            fVar9 = (float)puVar8[3];

            if ((((((*(uint *)((int)fVar9 + 0xd8) & 0x4000c000) == 0) &&

                  (*(float *)((int)fVar9 + 0x278) < *(float *)((int)fVar9 + 0x1c0))) &&

                 ((*(int *)((int)fVar9 + 0x1e0) == 0x3d &&

                  (((((iVar6 = *(int *)((int)fVar9 + 4), iVar6 == 0x24e || (iVar6 == 0x250)) ||

                     (iVar6 == 0x251)) || ((iVar6 == 0x3ea || (iVar6 == 0x3eb)))) &&

                   ((*(byte *)((int)fVar9 + 0xe0) & 4) == 0)))))) &&

                (iVar6 = ANM_AnimGetImage(fVar9), iVar6 == 0)) &&

               ((fVar13 = (float10)FUN_0050a610((int)fVar9 + 0xa0,param_1 + 0xa0), fStack_264 == 0.0

                || (fVar13 <= (float10)uStack_260)))) {

              uStack_260 = (float)fVar13;

              fStack_264 = fVar9;

            }

          }

          *(float *)((int)fStack_23c + 0xa0) = fStack_264;

          if (*(int *)(iVar11 + 0xa0) != 0) {

            fStack_248 = *(float *)(DAT_00632a88 + 0xa0);

            fStack_244 = *(float *)(DAT_00632a88 + 0xa4);

            fStack_240 = *(float *)(DAT_00632a88 + 0xa8);

            normalize__FPfN20(&fStack_248,&fStack_244,&fStack_240);

            iVar6 = *(int *)(iVar11 + 0xa0);

            fVar9 = fStack_248 * *(float *)(iVar6 + 0xc4) * *(float *)(iVar6 + 0x154);

            fStack_254 = fVar9 + fVar9 + *(float *)(iVar6 + 0xa0);

            fVar9 = fStack_244 * *(float *)(iVar6 + 0xc4) * *(float *)(iVar6 + 0x154);

            fStack_250 = fVar9 + fVar9 + *(float *)(iVar6 + 0xa4);

            fVar9 = fStack_240 * *(float *)(iVar6 + 0xc4) * *(float *)(iVar6 + 0x154);

            fStack_24c = fVar9 + fVar9 + *(float *)(iVar6 + 0xa8);

            ai_moveonly_set_goal(param_1,&fStack_254);

            ai_goal_process(param_1);

            if (*(int *)(param_1 + 0x168) != 0) {

              puVar2 = (uint *)(*(int *)(iVar11 + 0xa0) + 0xe0);

              *puVar2 = *puVar2 | 4;

              *(undefined4 *)(param_1 + 0xe4) = 0x3f;

              break;

            }

          }

        }

      }

      if (*(float *)(param_1 + 0xec) < 0.0 != (*(float *)(param_1 + 0xec) == 0.0)) {

        iVar6 = 0;

        do {

          iVar4 = crt_rand_scaled(100);

          uStack_260 = 1.0;

          if (0x31 < iVar4) {

            uStack_260 = -1.0;

          }

          fVar13 = (float10)rndfloatrange(0x41200000,0x42200000);

          fStack_248 = (float)(fVar13 * (float10)uStack_260 + (float10)*(float *)(param_1 + 0xa0));

          iVar4 = crt_rand_scaled(100);

          fStack_23c = 1.0;

          if (0x31 < iVar4) {

            fStack_23c = -1.0;

          }

          fVar13 = (float10)rndfloatrange(0x41200000,0x42200000);

          fStack_244 = (float)(fVar13 * (float10)fStack_23c + (float10)*(float *)(param_1 + 0xa4));

          fVar13 = (float10)distance2d__FP3P3DT0(&fStack_248,(float *)(param_1 + 0xa0));

          fStack_264 = (float)fVar13;

          fVar13 = (float10)ground_get_z(&fStack_248);

          fStack_240 = (float)fVar13;

          fVar13 = (fVar13 - (float10)*(float *)(param_1 + 0xa8)) / (float10)fStack_264;

          if ((fVar13 < (float10)0.5) && ((float10)-0.5 < fVar13)) {

            if (iVar6 < 5) {

              ai_moveonly_set_goal(param_1,&fStack_248);

              ai_goal_process(param_1);

              if (*(int *)(param_1 + 0x168) != 0) {

                *(float *)(iVar11 + 0x58) = fStack_248;

                *(float *)(iVar11 + 0x5c) = fStack_244;

                *(float *)(iVar11 + 0x60) = fStack_240;

                *(undefined4 *)(param_1 + 0xe4) = 5;

                *(undefined4 *)(param_1 + 0xec) = 0x41200000;

                goto LAB_004f12f8;

              }

              ai_clear_move_goal(param_1);

              fVar13 = (float10)rndfloatrange(0x40a00000,0x41200000);

              *(undefined4 *)(param_1 + 0xe4) = 3;

              goto LAB_004f12ed;

            }

            break;

          }

          iVar6 = iVar6 + 1;

        } while (iVar6 < 5);

        fVar13 = (float10)rndfloatrange(0x40a00000,0x41200000);

LAB_004f12ed:

        *(float *)(param_1 + 0xec) = (float)fVar13;

      }

    }

LAB_004f12f8:

    if (*(int *)(iVar11 + 0x1c) != *(int *)(iVar11 + 0x20)) {

      *(int *)(iVar11 + 0x1c) = *(int *)(iVar11 + 0x20);

    }

    if ((*(int *)(iVar11 + 0x1c) < 0) || (*(float *)(iVar11 + 0x18) <= 0.0)) break;

    uVar7 = *(undefined4 *)(param_1 + 0x274);

    iVar11 = *(int *)(param_1 + 0x100);

    iVar6 = meccbasepit_bldg_from_object(uVar7);

    if (iVar6 == 0) goto LAB_004f287f;

    if (((*(int *)(iVar11 + 0x1c) == 0xd) &&

        (iVar6 = base_bldg_is_alive_at_all(uVar7,0xd), iVar6 != 0)) &&

       (iVar6 = FUN_004184d0(uVar7,0xd), iVar6 == 0)) {

      *(undefined4 *)(iVar11 + 0x24) = 0xffffffff;

      *(undefined4 *)(iVar11 + 0x20) = 0xffffffff;

      *(undefined4 *)(iVar11 + 0x1c) = 0xffffffff;

      *(undefined4 *)(param_1 + 0xe4) = 0x1e;

      break;

    }

    goto LAB_004f2864;

  case 5:

    ai_goal_process(param_1);

    fVar13 = (float10)FUN_00518b70(param_1,0);

    fVar13 = (float10)*(float *)(param_1 + 0xec) - fVar13;

    *(float *)(param_1 + 0xec) = (float)fVar13;

    if ((*(int *)(param_1 + 0x168) == 0) || (fVar13 < (float10)0.0 != (fVar13 == (float10)0.0))) {

      fVar13 = (float10)rndfloatrange(0x40a00000,0x41200000);

      *(float *)(param_1 + 0xec) = (float)fVar13;

      *(undefined1 *)(param_1 + 0x20b) = 0;

      *(undefined1 *)(param_1 + 0x20a) = 0;

      *(undefined1 *)(param_1 + 0x208) = 0;

      *(undefined4 *)(param_1 + 0xe4) = 3;

      ai_clear_move_goal(param_1);

      *(undefined4 *)(iVar11 + 0x58) = *(undefined4 *)(param_1 + 0xa0);

      *(undefined4 *)(iVar11 + 0x5c) = *(undefined4 *)(param_1 + 0xa4);

      *(undefined4 *)(iVar11 + 0x60) = *(undefined4 *)(param_1 + 0xa8);

    }

    if (*(int *)(iVar11 + 0x1c) != *(int *)(iVar11 + 0x20)) {

      *(int *)(iVar11 + 0x1c) = *(int *)(iVar11 + 0x20);

    }

    if ((*(int *)(iVar11 + 0x1c) < 0) || (*(float *)(iVar11 + 0x18) <= 0.0)) break;

    uVar7 = *(undefined4 *)(param_1 + 0x274);

    iVar11 = *(int *)(param_1 + 0x100);

    iVar6 = meccbasepit_bldg_from_object(uVar7);

    if (iVar6 != 0) {

      if (((*(int *)(iVar11 + 0x1c) == 0xd) &&

          (iVar6 = base_bldg_is_alive_at_all(uVar7,0xd), iVar6 != 0)) &&

         (iVar6 = FUN_004184d0(uVar7,0xd), iVar6 == 0)) {

        *(undefined4 *)(iVar11 + 0x24) = 0xffffffff;

        *(undefined4 *)(iVar11 + 0x20) = 0xffffffff;

        *(undefined4 *)(iVar11 + 0x1c) = 0xffffffff;

        *(undefined4 *)(param_1 + 0xe4) = 0x1e;

        break;

      }

      goto LAB_004f2864;

    }

    goto LAB_004f287f;

  case 0x13:

    iVar6 = *(int *)(param_1 + 0x274);

    if (iVar6 == 0) {

      *(undefined4 *)(param_1 + 0xe4) = 3;

      break;

    }

    iVar4 = ObjIsReaper(iVar6);

    if (iVar4 != 0) {

      fStack_254 = *(float *)(iVar6 + 0x298) * 5.0;

      pfVar1 = (float *)(param_1 + 0xa0);

      fStack_248 = fStack_254 + *(float *)(iVar6 + 0xa0);

      uStack_260 = *(float *)(iVar6 + 0x2a8) * 5.0;

      fStack_244 = uStack_260 + *(float *)(iVar6 + 0xa4);

      fStack_24c = *(float *)(iVar6 + 0xa8) + 3.0;

      fStack_254 = *(float *)(iVar6 + 0xa0) - fStack_254;

      fStack_250 = *(float *)(iVar6 + 0xa4) - uStack_260;

      fStack_240 = fStack_24c;

      fVar13 = (float10)FUN_0050a610(pfVar1,&fStack_248);

      fStack_264 = (float)fVar13;

      fVar13 = (float10)FUN_0050a610(pfVar1,&fStack_254);

      if (fVar13 < (float10)fStack_264) {

        fStack_248 = fStack_254;

        fStack_244 = fStack_250;

        fStack_240 = fStack_24c;

      }

      if (25.0 <= fStack_264) {

        fVar9 = 0.12;

      }

      else {

        fVar9 = fStack_264 * 0.0047999998;

      }

      fVar23 = 1.0 - fVar9;

      *(undefined4 *)(param_1 + 200) = *(undefined4 *)(iVar6 + 200);

      object_set_location(param_1,fVar23 * *pfVar1 + fVar9 * fStack_248,

                          fVar9 * fStack_244 + fVar23 * *(float *)(param_1 + 0xa4),

                          fVar9 * fStack_240 + fVar23 * *(float *)(param_1 + 0xa8));

    }

    if (*(int *)(param_1 + 0xe8) == 10) {

      fVar13 = (float10)FUN_00518b70(param_1,0);

      fVar13 = fVar13 + (float10)*(float *)(iVar11 + 0x9c);

      *(float *)(iVar11 + 0x9c) = (float)fVar13;

      if (((float10)*(int *)(DAT_00632ed8 + 0x1584) < fVar13) &&

         (*(int *)(param_1 + 0x18c) == *(int *)(DAT_00632a88 + 0x18c))) {

        uVar7 = TextGetPtrRandom(s_SmChStillStolen_00562240,4,1);

        chat_insert_name(iVar11 + 0x80,uVar7);

        *(undefined4 *)(iVar11 + 0x9c) = 0;

      }

    }

    if ((*(byte *)(param_1 + 0xe0) & 0x20) != 0) break;

    iVar11 = *(int *)(param_1 + 0xe8);

    if ((((iVar11 == 4) || (iVar11 == 10)) || (iVar11 == 5)) || (iVar11 == 2)) {

      fVar13 = (float10)FUN_00518b70(param_1,0);

      *(float *)(param_1 + 0xec) = (float)(fVar13 + (float10)*(float *)(param_1 + 0xec));

      fVar9 = 0.0;

    }

    else if (((*(float *)(iVar6 + 0xa0) == *(float *)(iVar6 + 0xac)) &&

             (*(float *)(iVar6 + 0xa4) == *(float *)(iVar6 + 0xb0))) &&

            (*(float *)(iVar6 + 0xa8) == *(float *)(iVar6 + 0xb4))) {

      fVar13 = (float10)FUN_00518b70(param_1,0);

      *(float *)(param_1 + 0xec) = (float)(fVar13 + (float10)*(float *)(param_1 + 0xec));

      fVar9 = 1.0;

    }

    else {

      fVar9 = 1.0;

      *(undefined4 *)(param_1 + 0xec) = 0;

    }

    if (*(float *)(param_1 + 0xec) <= fVar9) break;

    iVar11 = *(int *)(param_1 + 0xe8);

    if ((iVar11 == 4) || (iVar11 == 2)) {

      uStack_260 = (float)smartie_find_legal_nearby_base__FP6OBJECTT0(param_1,iVar6);

      if ((uStack_260 != 0.0) && (puVar8 = DAT_00632d68, DAT_00632d68 != (undefined4 *)0x0)) {

        do {

          iVar11 = puVar8[3];

          if (((*(int *)(iVar11 + 4) == 0x342) || (*(int *)(iVar11 + 4) == 0x35a)) &&

             (fVar13 = (float10)distancesq2d__FP3P3DT0(iVar11 + 0xa0,(int)uStack_260 + 0xa0),

             fVar13 <= (float10)250000.0)) goto LAB_004f1865;

          puVar8 = (undefined4 *)*puVar8;

        } while (puVar8 != (undefined4 *)0x0);

        *(undefined4 *)(param_1 + 0xec) = 0;

        break;

      }

LAB_004f187e:

      *(undefined4 *)(param_1 + 0xec) = 0;

    }

    else {

      if (iVar11 == 10) {

        iVar11 = 0;

        uStack_260 = 999999.0;

        piVar12 = DAT_00632d98;

        if (DAT_00632d98 == (int *)0x0) break;

        do {

          iVar6 = piVar12[3];

          if (((*(int *)(iVar6 + 0xe8) == 10) && (*(int *)(iVar6 + 0xe4) == 0x33)) &&

             (fVar13 = (float10)distancesq2d__FP3P3DT0(iVar6 + 0xa0,param_1 + 0xa0),

             fVar13 < (float10)uStack_260)) {

            uStack_260 = (float)fVar13;

            iVar11 = iVar6;

          }

          piVar12 = (int *)*piVar12;

        } while (piVar12 != (int *)0x0);

        if ((iVar11 == 0) ||

           (fVar13 = (float10)FUN_0050a610(param_1 + 0xa0,iVar11 + 0xa0), (float10)144.0 < fVar13))

        break;

      }

      else if (iVar11 == 5) {

        puVar8 = DAT_00632d68;

        if (DAT_00632d68 != (undefined4 *)0x0) {

          do {

            iVar11 = puVar8[3];

            iVar6 = param_1;

            if ((*(int *)(iVar11 + 4) == 0x342) || (*(int *)(iVar11 + 4) == 0x35a))

            goto LAB_004f1865;

            puVar8 = (undefined4 *)*puVar8;

          } while (puVar8 != (undefined4 *)0x0);

          *(undefined4 *)(param_1 + 0xec) = 0;

          break;

        }

        goto LAB_004f187e;

      }

LAB_004f17e7:

      iVar11 = *(int *)(param_1 + 0xe8);

      if ((iVar11 == 4) || ((iVar11 == 5 || (iVar11 == 2)))) {

        ObjectSetAnim(param_1,0x58,0x20,0,0,0x3e2aaaab);

      }

      *(undefined4 *)(param_1 + 0xe4) = 0x14;

    }

    break;

  case 0x14:

    iVar11 = *(int *)(param_1 + 0xe8);

    iVar6 = *(int *)(param_1 + 0x274);

    if ((iVar11 == 4) || (iVar11 == 2)) {

      iVar11 = smartie_find_legal_nearby_base__FP6OBJECTT0(param_1,iVar6);

      if (iVar11 != 0) {

        iVar4 = object_spawn_class5(*(undefined4 *)(iVar6 + 0x18c),iVar11);

        if (iVar4 != 0) {

          iVar4 = ObjIsMecc(iVar6);

          if (iVar4 == 0) {

            iVar4 = ObjIsReaper(iVar6);

            if (iVar4 != 0) {

              *(int *)(*(int *)(iVar6 + 0x100) + 0xcfc) = iVar11;

            }

          }

          else {

            *(int *)(*(int *)(iVar6 + 0x100) + 0xd8) = iVar11;

          }

        }

        iVar4 = reaper_0052e4a0(param_1);

        if (iVar4 != 0) {

          uStack_260 = *(float *)(iVar6 + 0x188);

          uStack_25c = *(undefined4 *)(iVar11 + 0x188);

          reaper_00530bd0(param_1,0,2,0,4,&uStack_260);

        }

        smartie_attach_to_base(param_1,iVar6,iVar11);

      }

      break;

    }

    if (iVar11 != 10) {

      smartie_unlock_from_player(param_1,iVar6,0);

      iVar11 = reaper_0052e4a0(param_1);

      if (iVar11 != 0) {

        uStack_260 = *(float *)(iVar6 + 0x188);

        uStack_25c = 0;

        reaper_00530bd0(param_1,0,2,0,4,&uStack_260);

      }

      break;

    }

    smartie_unlock_from_player(param_1,iVar6,0);

    iVar11 = reaper_0052e4a0(param_1);

    if (iVar11 != 0) {

      uStack_260 = *(float *)(iVar6 + 0x188);

      uStack_25c = 0;

      reaper_00530bd0(param_1,0,2,0,4,&uStack_260);

    }

    iVar11 = FUN_004177a0(*(undefined4 *)(param_1 + 0x18c));

    if (iVar11 == 0) break;

    comm_death_packet_build

              (iVar6,0,*(int *)(iVar6 + 0x18c) + -1,*(int *)(iVar11 + 0x18c) + -1,

               (float)DAT_00632f28,0x3f800000,0,0);

    rpman_move(iVar6,*(int *)(iVar11 + 0x18c) + -1);

    objtype_setup_vimp(param_1,iVar11);

    iVar6 = reaper_0052e4a0(param_1);

    if (iVar6 == 0) break;

    uStack_260 = *(float *)(iVar11 + 0x188);

LAB_004f19e6:

    reaper_00530bd0(param_1,0,1,0,8,&uStack_260);

    break;

  case 0x1e:

    iVar6 = *(int *)(param_1 + 0x274);

    if ((iVar6 != 0) && ((*(uint *)(param_1 + 0xd8) & 0x80000) != 0)) {

      *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) | 0x10;

      iVar4 = meccbasepit_bldg_from_object(iVar6);

      if (iVar4 == 0) {

        iVar4 = reaperbase_bldg_from_object(iVar6);

        if (iVar4 == 0) break;

        puStack_258 = (undefined4 *)(iVar11 + 0x28);

        iVar4 = objtype_anim_scan_2(iVar6,param_1,puStack_258);

      }

      else {

        puStack_258 = (undefined4 *)(iVar11 + 0x28);

        iVar4 = objtype_anim_scan(iVar6,param_1,puStack_258);

      }

      if (iVar4 != 0) {

        fStack_264 = 999.0;

        iVar4 = base_has_partyhouse(iVar6);

        if (iVar4 == 0) {

          uVar7 = base_get_base_building(iVar6);

          pfVar1 = (float *)(iVar11 + 0x58);

          bldg_get_refpt_worldlocdir(uVar7,*puStack_258,pfVar1,&fStack_264);

          FUN_00418810(uVar7,*puStack_258,&uStack_260,&fStack_23c);

          *pfVar1 = *pfVar1 - uStack_260 * 12.0;

          *(float *)(iVar11 + 0x5c) = *(float *)(iVar11 + 0x5c) - fStack_23c * 12.0;

          *(undefined4 *)(param_1 + 0xe4) = 0x1f;

        }

        else {

          iVar4 = base_get_base_building(iVar6);

          *(undefined4 *)(iVar11 + 0x58) = *(undefined4 *)(iVar6 + 0xa0);

          *(undefined4 *)(iVar11 + 0x5c) = *(undefined4 *)(iVar6 + 0xa4);

          *(undefined4 *)(iVar11 + 0x60) = *(undefined4 *)(iVar6 + 0xa8);

          *(undefined4 *)(param_1 + 0xe4) = 0x36;

          if (iVar4 != 0) {

            *puStack_258 = 0xd;

            bldg_get_refpt_worldlocdir(iVar4,0xd,(undefined4 *)(iVar11 + 0x58),&fStack_264);

          }

        }

        if (fStack_264 == 999.0) {

          ai_moveonly_set_goal(param_1,iVar11 + 0x58);

        }

        else {

          main_ai_move_004014b0(param_1,iVar11 + 0x58,fStack_264);

        }

      }

    }

    break;

  case 0x1f:

  case 0x36:

    *(int *)(iVar11 + 0x1c) = *(int *)(iVar11 + 0x20);

    if ((*(int *)(iVar11 + 0x20) < 0) || (*(float *)(iVar11 + 0x18) <= 0.0)) {

      fStack_264 = *(float *)(param_1 + 0x100);

      iVar6 = base_get_smartie_building(param_1);

      if ((iVar6 != 0) && (iVar6 = obj_maxspeed_lookup(iVar6,0), iVar6 != 0)) {

        iVar6 = ai_anim_select_mode(param_1,*(undefined4 *)((int)fStack_264 + 0x1c));

        if (iVar6 < 0) {

          *(undefined4 *)((int)fStack_264 + 0x24) = 0xffffffff;

          *(undefined4 *)((int)fStack_264 + 0x20) = 0xffffffff;

          *(undefined4 *)((int)fStack_264 + 0x1c) = 0xffffffff;

        }

        else {

          iVar4 = base_slot_built_check(*(undefined4 *)(param_1 + 0x274),iVar6);

          if (iVar4 == 0) {

            bldg_spawn_by_type(*(undefined4 *)(param_1 + 0x274),iVar6);

          }

          reaper_lock_short(*(undefined4 *)(param_1 + 0x274),iVar6,param_1,1);

          *(int *)((int)fStack_264 + 0x20) = iVar6;

          *(int *)((int)fStack_264 + 0x1c) = iVar6;

        }

      }

      iVar6 = *(int *)(param_1 + 0x100);

      iVar4 = ai_goal_process(param_1);

      if (iVar4 == -1) {

        ai_clear_move_goal(param_1);

        ai_move_force_goal(param_1,iVar6 + 0x58);

        ai_goal_process(param_1);

      }

      puVar8 = (undefined4 *)(iVar11 + 0x58);

      fVar13 = (float10)distancesq2d__FP3P3DT0(puVar8,(undefined4 *)(param_1 + 0xa0));

      if ((fVar13 < (float10)16.0) || (*(int *)(param_1 + 0x168) == 0)) {

        ai_clear_move_goal(param_1);

        *(undefined1 *)(param_1 + 0x20b) = 0;

        *(undefined1 *)(param_1 + 0x20a) = 0;

        *(undefined1 *)(param_1 + 0x208) = 0;

        iVar6 = *(int *)(iVar11 + 0x28);

        if (*(int *)(param_1 + 0xe4) == 0x1f) {

          if ((((iVar6 == 10) || (iVar6 == 0xb)) || (iVar6 == 0xc)) ||

             ((iVar6 == 0xd || (iVar6 == 0xe)))) {

            uVar7 = *(undefined4 *)(param_1 + 0x274);

            iVar6 = meccbasepit_bldg_from_object(uVar7);

            if (iVar6 == 0) {

              uVar16 = 0x5c;

            }

            else {

              uVar16 = 0x34;

            }

            ObjectSetAnim(param_1,uVar16,0x20,0,0,0x3e2aaaab);

            iVar6 = meccbasepit_bldg_from_object(uVar7);

            if (iVar6 != 0) {

              meccbasepit_create_food(uVar7,*(undefined4 *)(iVar11 + 0x28));

            }

            uVar7 = base_get_base_building(uVar7);

            FUN_00418770(uVar7,*(undefined4 *)(iVar11 + 0x28),param_1 + 200);

            *(undefined4 *)(param_1 + 0xe4) = 0x21;

            *(undefined4 *)(iVar11 + 4) = *(undefined4 *)(param_1 + 0xa0);

            *(undefined4 *)(iVar11 + 8) = *(undefined4 *)(param_1 + 0xa4);

            *(undefined4 *)(iVar11 + 0xc) = *(undefined4 *)(param_1 + 0xa8);

            iVar6 = reaper_0052e4a0(param_1);

            if (iVar6 != 0) {

              uStack_235 = *(undefined1 *)(iVar11 + 0x28);

              reaper_00530bd0(param_1,0,0,1,0x11,&uStack_235);

            }

          }

          else {

            *(undefined4 *)(param_1 + 0xe4) = 0x1e;

          }

        }

        else if (iVar6 == 0xd) {

          iVar6 = *(int *)(param_1 + 0x274);

          iVar4 = base_get_base_building(iVar6);

          *puVar8 = *(undefined4 *)(iVar6 + 0xa0);

          *(undefined4 *)(iVar11 + 0x5c) = *(undefined4 *)(iVar6 + 0xa4);

          *(undefined4 *)(iVar11 + 0x60) = *(undefined4 *)(iVar6 + 0xa8);

          *(undefined4 *)(iVar11 + 0x28) = 0xe;

          if (iVar4 != 0) {

            bldg_get_refpt_worldloc(iVar4,0xe,puVar8);

          }

          ai_move_force_goal(param_1,puVar8);

        }

        else if (iVar6 == 0xe) {

          *(undefined4 *)(param_1 + 0xe4) = 0x37;

          smartie_make_held_object__FP6OBJECTi(param_1,0x2f2);

          ObjectSetAnim(param_1,0x41,0x20,0,0,0x3f2aaaab);

          iVar11 = reaper_0052e4a0(param_1);

          if (iVar11 != 0) {

            reaper_00530bd0(param_1,0,0,0,0xb,0);

          }

        }

      }

      break;

    }

    ai_clear_move_goal(param_1);

    bldg_slot_action_dispatch(*(undefined4 *)(param_1 + 0x274),param_1);

    *(undefined4 *)(iVar11 + 0x28) = 0xffffffff;

    uVar7 = *(undefined4 *)(param_1 + 0x274);

    iVar11 = *(int *)(param_1 + 0x100);

    iVar6 = meccbasepit_bldg_from_object(uVar7);

    goto LAB_004f2824;

  case 0x21:

    fVar9 = *(float *)(param_1 + 0x274);

    uStack_260 = 0.0;

    fStack_23c = 0.0;

    fStack_264 = fVar9;

    if (*(int *)(param_1 + 0x10) == 0x5c) {

      uVar7 = base_get_base_building(fVar9);

      bldg_get_refpt_worldloc(uVar7,*(undefined4 *)(iVar11 + 0x28),&fStack_254);

      object_set_location_p3d(param_1,&fStack_254);

      break;

    }

    if (*(int *)(param_1 + 0x10) == 0x34) {

      fStack_264 = *(float *)(param_1 + 0x14) / **(float **)(*(int *)(param_1 + 8) + 0xd8);

      bldg_get_refpt_worldloc(fVar9,*(undefined4 *)(iVar11 + 0x28),&fStack_254);

      fVar21 = 1.0 - fStack_264;

      fVar9 = fStack_24c * fStack_264 + fVar21 * *(float *)(iVar11 + 0xc);

      fVar23 = fStack_250 * fStack_264 + fVar21 * *(float *)(iVar11 + 8);

      fVar21 = fStack_254 * fStack_264 + fVar21 * *(float *)(iVar11 + 4);

      goto LAB_004f35c0;

    }

    puStack_258 = *(undefined4 **)(param_1 + 0x100);

    iVar6 = base_get_smartie_building(param_1);

    if ((iVar6 != 0) && (iVar6 = obj_maxspeed_lookup(iVar6,0), iVar6 != 0)) {

      iVar6 = ai_anim_select_mode(param_1,puStack_258[7]);

      if (iVar6 < 0) {

        puStack_258[9] = 0xffffffff;

        puStack_258[8] = 0xffffffff;

        puStack_258[7] = 0xffffffff;

        fVar9 = fStack_264;

      }

      else {

        iVar4 = base_slot_built_check(*(undefined4 *)(param_1 + 0x274),iVar6);

        if (iVar4 == 0) {

          bldg_spawn_by_type(*(undefined4 *)(param_1 + 0x274),iVar6);

        }

        reaper_lock_short(*(undefined4 *)(param_1 + 0x274),iVar6,param_1,1);

        puStack_258[8] = iVar6;

        puStack_258[7] = iVar6;

        fVar9 = fStack_264;

      }

    }

    if (*(float *)(iVar11 + 0x18) < *(float *)(DAT_00632ed8 + 0x624)) {

      fVar13 = (float10)FUN_00518b70(param_1,0);

      uStack_260 = (float)((fVar13 * (float10)*(float *)(DAT_00632ed8 + 0x624)) /

                          (float10)*(float *)(DAT_00632ed8 + 0x5bc));

      fVar13 = (float10)obj_speed_clamp(fVar9,uStack_260);

      fStack_23c = (float)fVar13;

    }

    if (*(float *)(iVar11 + 0x18) == 0.0) {

      iVar6 = *(int *)(param_1 + 0x100);

      iVar4 = *(int *)(iVar6 + 0x48);

      if (iVar4 != 0) {

        fx_delete(iVar4);

        *(undefined4 *)(iVar6 + 0x48) = 0;

      }

    }

    fVar9 = fStack_23c + *(float *)(iVar11 + 0x18);

    *(float *)(iVar11 + 0x18) = fVar9;

    if (*(float *)(DAT_00632ed8 + 0x624) < fVar9) {

      *(undefined4 *)(iVar11 + 0x18) = *(undefined4 *)(DAT_00632ed8 + 0x624);

    }

    if ((*(float *)(DAT_00632ed8 + 0x624) != *(float *)(iVar11 + 0x18)) &&

       (uStack_260 <= fStack_23c)) break;

    iVar6 = *(int *)(param_1 + 0x100);

    if (*(int *)(iVar6 + 0x30) != 0) {

      *(undefined4 *)(*(int *)(iVar6 + 0x30) + 0x210) = 0;

      object_destroy(*(undefined4 *)(iVar6 + 0x30));

      *(undefined4 *)(iVar6 + 0x30) = 0;

      *(undefined4 *)(iVar6 + 0x14) = 0x41d80000;

      iVar6 = reaper_0052e4a0(param_1);

      if (iVar6 != 0) {

        reaper_00530bd0(param_1,0,0,0,0x14,0);

      }

    }

    fVar9 = fStack_264;

    if (*(float *)(DAT_00632ed8 + 0x624) == *(float *)(iVar11 + 0x18)) {

      bldg_slot_action_dispatch(fStack_264,param_1);

      *(undefined4 *)(iVar11 + 0x28) = 0xffffffff;

      iVar11 = base_has_partyhouse(fVar9);

      *(uint *)(param_1 + 0xe4) = (-(uint)(iVar11 != 0) & 0xfffffffa) + 0x24;

      break;

    }

    *(int *)(iVar11 + 0x1c) = *(int *)(iVar11 + 0x20);

    if ((*(int *)(iVar11 + 0x20) < 0) || (*(float *)(iVar11 + 0x18) <= 0.0)) break;

    bldg_slot_action_dispatch(fStack_264,param_1);

    *(undefined4 *)(iVar11 + 0x28) = 0xffffffff;

    uVar7 = *(undefined4 *)(param_1 + 0x274);

    iVar11 = *(int *)(param_1 + 0x100);

    iVar6 = meccbasepit_bldg_from_object(uVar7);

    goto LAB_004f2824;

  case 0x22:

    if (*(int *)(iVar11 + 0x1c) != *(int *)(iVar11 + 0x20)) {

      ai_clear_move_goal(param_1);

      *(undefined1 *)(param_1 + 0x20b) = 0;

      *(undefined1 *)(param_1 + 0x20a) = 0;

      *(undefined1 *)(param_1 + 0x208) = 0;

      *(undefined4 *)(iVar11 + 0x1c) = *(undefined4 *)(iVar11 + 0x20);

    }

    iVar6 = base_get_smartie_building(param_1);

    if (iVar6 == 0) break;

    iVar4 = obj_maxspeed_lookup(iVar6,0);

    if (iVar4 == 0) {

      if (*(int *)(param_1 + 0x168) == 0) {

        iVar4 = NAM_DictionaryGetTotalNames(*(undefined4 *)(param_1 + 0x274));

        iVar10 = meccbasepit_bldg_from_object(*(undefined4 *)(param_1 + 0x274));

        if (iVar10 != 0) {

          if (iVar4 == 0) {

            uVar7 = 0x2f9;

          }

          else if (iVar4 == 1) {

            uVar7 = 0x30e;

          }

          else {

            uVar7 = 0x30f;

          }

          smartie_make_held_object__FP6OBJECTi(param_1,uVar7);

        }

        iVar4 = *(int *)(iVar6 + 0x2d8);

        if (iVar4 < 2) {

          crt_sprintf(auStack_200,s_Obj_type__d_has_no_building_ref_p_00562144,

                      *(undefined4 *)(iVar6 + 4));

          FUN_0051ea20(auStack_200);

          *(undefined4 *)(iVar11 + 0x1c) = 0xffffffff;

          *(undefined4 *)(iVar11 + 0x24) = 0xffffffff;

          *(undefined4 *)(iVar11 + 0x20) = 0xffffffff;

          *(undefined4 *)(param_1 + 0xe4) = 0x1e;

        }

        else {

          if (iVar4 < 10) {

            iVar4 = iVar4 + -1;

          }

          else {

            iVar4 = 9;

          }

          uVar7 = rndintrange(1,iVar4);

          *(undefined4 *)(iVar11 + 0x28) = uVar7;

          bldg_get_refpt_worldloc(iVar6,uVar7,iVar11 + 0x58);

          ai_moveonly_set_goal(param_1,iVar11 + 0x58);

        }

      }

      else {

        iVar4 = *(int *)(param_1 + 0x100);

        iVar10 = ai_goal_process(param_1);

        if (iVar10 == -1) {

          ai_clear_move_goal(param_1);

          ai_move_force_goal(param_1,iVar4 + 0x58);

          ai_goal_process(param_1);

        }

        if (*(int *)(param_1 + 0x168) == 0) {

          iVar4 = *(int *)(param_1 + 0x100);

          *(undefined4 *)(param_1 + 0xe4) = 0x23;

          if (*(int *)(iVar4 + 0x30) != 0) {

            *(undefined4 *)(*(int *)(iVar4 + 0x30) + 0x210) = 0;

            object_destroy(*(undefined4 *)(iVar4 + 0x30));

            *(undefined4 *)(iVar4 + 0x30) = 0;

            *(undefined4 *)(iVar4 + 0x14) = 0x41d80000;

            iVar4 = reaper_0052e4a0(param_1);

            if (iVar4 != 0) {

              reaper_00530bd0(param_1,0,0,0,0x14,0);

            }

          }

          bldg_get_refpt_worldlocdir(iVar6,*(undefined4 *)(iVar11 + 0x28),&fStack_254,param_1 + 200)

          ;

          object_set_location_p3d(param_1,&fStack_254);

          *(undefined4 *)(param_1 + 0xec) = 0x3fc00000;

          iVar6 = meccbasepit_bldg_from_object(*(undefined4 *)(param_1 + 0x274));

          if (iVar6 == 0) {

            iVar6 = reaperbase_bldg_from_object(*(undefined4 *)(param_1 + 0x274));

            if (iVar6 != 0) {

              uVar7 = sound_get_free_sequence__Fv();

              *(undefined4 *)(iVar11 + 0xb8) = uVar7;

            }

          }

          else {

            uVar24 = 1;

            uVar22 = 0;

            uVar20 = 0x576;

            uVar19 = 0;

            uVar18 = 0x575;

            uVar16 = 0x577;

            iVar6 = param_1;

            uVar7 = sound_get_free_sequence__Fv();

            *(undefined4 *)(iVar11 + 0xb8) = uVar7;

            make_dust_ball(param_1 + 0xa0,0x3f000000,uVar16,uVar18,uVar19,uVar20,iVar6,uVar22,uVar24

                          );

          }

        }

      }

      break;

    }

    ai_clear_move_goal(param_1);

    iVar6 = *(int *)(param_1 + 0x100);

    if (*(int *)(iVar6 + 0x30) != 0) {

      *(undefined4 *)(*(int *)(iVar6 + 0x30) + 0x210) = 0;

      object_destroy(*(undefined4 *)(iVar6 + 0x30));

      *(undefined4 *)(iVar6 + 0x30) = 0;

      *(undefined4 *)(iVar6 + 0x14) = 0x41d80000;

      iVar6 = reaper_0052e4a0(param_1);

      if (iVar6 != 0) {

        reaper_00530bd0(param_1,0,0,0,0x14,0);

      }

    }

    *(undefined1 *)(param_1 + 0x20b) = 0;

    *(undefined1 *)(param_1 + 0x20a) = 0;

    *(undefined1 *)(param_1 + 0x208) = 0;

    iVar6 = ai_anim_select_mode(param_1,*(undefined4 *)(iVar11 + 0x1c));

    if (iVar6 < 0) {

      *(undefined4 *)(iVar11 + 0x24) = 0xffffffff;

      *(undefined4 *)(iVar11 + 0x20) = 0xffffffff;

      *(undefined4 *)(iVar11 + 0x1c) = 0xffffffff;

    }

    else {

      iVar4 = base_slot_built_check(*(undefined4 *)(param_1 + 0x274),iVar6);

      if (iVar4 == 0) {

        bldg_spawn_by_type(*(undefined4 *)(param_1 + 0x274),iVar6);

        reaper_lock_short(*(undefined4 *)(param_1 + 0x274),iVar6,param_1,1);

      }

      *(int *)(iVar11 + 0x20) = iVar6;

      *(int *)(iVar11 + 0x1c) = iVar6;

    }

    *(undefined4 *)(iVar11 + 0x28) = 0xffffffff;

    if ((-1 < *(int *)(iVar11 + 0x1c)) && (0.0 < *(float *)(iVar11 + 0x18))) {

      *(undefined4 *)(param_1 + 0xe4) = 0x22;

      break;

    }

    if (*(float *)(DAT_00632ed8 + 0x624) == *(float *)(iVar11 + 0x18)) {

      fVar9 = *(float *)(param_1 + 0x274);

LAB_004f32da:

      iVar11 = base_has_partyhouse(fVar9);

      if (iVar11 == 0) {

        *(undefined4 *)(param_1 + 0xe4) = 0x24;

        break;

      }

    }

    goto LAB_004f2855;

  case 0x23:

    if (*(int *)(iVar11 + 0x1c) != *(int *)(iVar11 + 0x20)) {

      ai_clear_move_goal();

      iVar6 = *(int *)(param_1 + 0x100);

      *(undefined1 *)(param_1 + 0x20b) = 0;

      *(undefined1 *)(param_1 + 0x20a) = 0;

      *(undefined1 *)(param_1 + 0x208) = 0;

      if (*(int *)(iVar6 + 0x30) != 0) {

        *(undefined4 *)(*(int *)(iVar6 + 0x30) + 0x210) = 0;

        object_destroy(*(undefined4 *)(iVar6 + 0x30));

        *(undefined4 *)(iVar6 + 0x30) = 0;

        *(undefined4 *)(iVar6 + 0x14) = 0x41d80000;

        iVar6 = reaper_0052e4a0(param_1);

        if (iVar6 != 0) {

          reaper_00530bd0(param_1,0,0,0,0x14,0);

        }

      }

      *(undefined4 *)(iVar11 + 0x1c) = *(undefined4 *)(iVar11 + 0x20);

      uVar7 = *(undefined4 *)(param_1 + 0x274);

      iVar6 = *(int *)(param_1 + 0x100);

      iVar4 = meccbasepit_bldg_from_object(uVar7);

      if (iVar4 == 0) {

        iVar4 = reaperbase_bldg_from_object(uVar7);

        if ((iVar4 != 0) && (-1 < *(int *)(iVar6 + 0x1c))) {

          *(undefined4 *)(param_1 + 0xe4) = 0x22;

        }

      }

      else {

        if (((*(int *)(iVar6 + 0x1c) == 0xd) &&

            (iVar4 = base_bldg_is_alive_at_all(uVar7,0xd), iVar4 != 0)) &&

           (iVar4 = FUN_004184d0(uVar7,0xd), iVar4 == 0)) {

          *(undefined4 *)(iVar6 + 0x24) = 0xffffffff;

          *(undefined4 *)(iVar6 + 0x20) = 0xffffffff;

          *(undefined4 *)(iVar6 + 0x1c) = 0xffffffff;

          *(undefined4 *)(param_1 + 0xe4) = 0x1e;

          sound_interrupt_sequence(iVar11 + 0xb8);

          break;

        }

        if (-1 < *(int *)(iVar6 + 0x1c)) {

          *(undefined4 *)(param_1 + 0xe4) = 0x26;

          sound_interrupt_sequence(iVar11 + 0xb8);

          break;

        }

      }

      sound_interrupt_sequence(iVar11 + 0xb8);

      break;

    }

    iVar6 = base_get_smartie_building(param_1);

    if (iVar6 == 0) {

      sound_interrupt_sequence(iVar11 + 0xb8);

      break;

    }

    iVar4 = obj_maxspeed_lookup(iVar6,0);

    if (iVar4 == 0) {

      *(undefined1 *)(param_1 + 0x20b) = 0;

      *(undefined1 *)(param_1 + 0x20a) = 0;

      *(undefined1 *)(param_1 + 0x208) = 0;

      fVar13 = (float10)FUN_00518b70(param_1,0);

      fVar13 = (fVar13 * (float10)*(float *)(DAT_00632ed8 + 0x624)) /

               (float10)*(float *)(DAT_00632ed8 + 0x5c0);

      uStack_260 = (float)fVar13;

      if ((float10)*(float *)(iVar11 + 0x18) < fVar13) {

        uStack_260 = *(float *)(iVar11 + 0x18);

      }

      iVar4 = FUN_004a6220(iVar6);

      if (((iVar4 == 0) || ((*(int *)(iVar11 + 0x1c) != 0 && (*(int *)(iVar11 + 0x1c) != 1)))) &&

         ((iVar4 = ObjIsReaperBldg(iVar6), iVar4 == 0 ||

          ((*(int *)(iVar11 + 0x1c) != 0 && (*(int *)(iVar11 + 0x1c) != 1)))))) {

        *(float *)(iVar11 + 0x18) = *(float *)(iVar11 + 0x18) - uStack_260;

      }

      if ((*(float *)(iVar11 + 0x18) < 0.0 != (*(float *)(iVar11 + 0x18) == 0.0)) &&

         (((iVar4 = FUN_004a6220(iVar6), iVar4 != 0 && (*(int *)(iVar11 + 0x1c) == 0xd)) ||

          ((iVar4 = ObjIsReaperBldg(iVar6), iVar4 != 0 && (*(int *)(iVar11 + 0x1c) == 8)))))) {

        *(undefined4 *)(iVar11 + 0x18) = 0x41200000;

      }

      iVar4 = obj_maxspeed_lookup(iVar6,uStack_260);

      if (iVar4 == 0) {

        if (*(float *)(iVar11 + 0x18) != 0.0) {

          iVar4 = meccbasepit_bldg_from_object(*(undefined4 *)(param_1 + 0x274));

          if (iVar4 != 0) {

            iVar4 = crt_rand_scaled(100);

            if (iVar4 < 0x21) {

              uVar7 = 0x2f4;

            }

            else if (iVar4 < 0x42) {

              uVar7 = 0x2f3;

            }

            else {

              uVar7 = 0x2f1;

            }

            smartie_make_held_object__FP6OBJECTi(param_1,uVar7);

            fVar13 = (float10)FUN_00518b70(param_1,0);

            fVar13 = (float10)*(float *)(param_1 + 0xec) - fVar13;

            *(float *)(param_1 + 0xec) = (float)fVar13;

            if (fVar13 < (float10)0.0 != (fVar13 == (float10)0.0)) {

              sound_interrupt_sequence(iVar11 + 0xb8);

              if (*(int *)(iVar6 + 0x2d8) < 10) {

                iVar6 = *(int *)(iVar6 + 0x2d8) + -1;

              }

              else {

                iVar6 = 9;

              }

              uVar7 = rndintrange(1,iVar6);

              *(undefined4 *)(iVar11 + 0x28) = uVar7;

              *(undefined4 *)(iVar11 + 0x58) = *(undefined4 *)(param_1 + 0xa0);

              *(undefined4 *)(iVar11 + 0x5c) = *(undefined4 *)(param_1 + 0xa4);

              *(undefined4 *)(iVar11 + 0x60) = *(undefined4 *)(param_1 + 0xa8);

              *(undefined4 *)(param_1 + 0xe4) = 0x28;

              *(undefined4 *)(param_1 + 0xec) = 0;

            }

          }

          break;

        }

        sound_interrupt_sequence(iVar11 + 0xb8);

        iVar6 = *(int *)(param_1 + 0x100);

        if (*(int *)(iVar6 + 0x30) != 0) {

          *(undefined4 *)(*(int *)(iVar6 + 0x30) + 0x210) = 0;

          object_destroy(*(undefined4 *)(iVar6 + 0x30));

          *(undefined4 *)(iVar6 + 0x30) = 0;

          *(undefined4 *)(iVar6 + 0x14) = 0x41d80000;

          iVar6 = reaper_0052e4a0(param_1);

          if (iVar6 != 0) {

            reaper_00530bd0(param_1,0,0,0,0x14,0);

          }

        }

        iVar6 = *(int *)(param_1 + 0x100);

        iVar4 = *(int *)(iVar6 + 0x48);

        if (iVar4 != 0) {

          fx_delete(iVar4);

          *(undefined4 *)(iVar6 + 0x48) = 0;

        }

        *(undefined4 *)(iVar11 + 0x28) = 0xffffffff;

        goto LAB_004f338e;

      }

    }

    sound_interrupt_sequence(iVar11 + 0xb8);

    iVar6 = *(int *)(param_1 + 0x100);

    if (*(int *)(iVar6 + 0x30) != 0) {

      *(undefined4 *)(*(int *)(iVar6 + 0x30) + 0x210) = 0;

      object_destroy(*(undefined4 *)(iVar6 + 0x30));

      *(undefined4 *)(iVar6 + 0x30) = 0;

      *(undefined4 *)(iVar6 + 0x14) = 0x41d80000;

      iVar6 = reaper_0052e4a0(param_1);

      if (iVar6 != 0) {

        reaper_00530bd0(param_1,0,0,0,0x14,0);

      }

    }

    iVar6 = ai_anim_select_mode(param_1,*(undefined4 *)(iVar11 + 0x1c));

    if (iVar6 < 0) {

      *(undefined4 *)(iVar11 + 0x24) = 0xffffffff;

      *(undefined4 *)(iVar11 + 0x20) = 0xffffffff;

      *(undefined4 *)(iVar11 + 0x1c) = 0xffffffff;

    }

    else {

      iVar4 = base_slot_built_check(*(undefined4 *)(param_1 + 0x274),iVar6);

      if (iVar4 == 0) {

        bldg_spawn_by_type(*(undefined4 *)(param_1 + 0x274),iVar6);

        reaper_lock_short(*(undefined4 *)(param_1 + 0x274),iVar6,param_1,1);

      }

      *(int *)(iVar11 + 0x20) = iVar6;

      *(int *)(iVar11 + 0x1c) = iVar6;

    }

    *(undefined4 *)(iVar11 + 0x28) = 0xffffffff;

    if ((-1 < *(int *)(iVar11 + 0x1c)) && (0.0 < *(float *)(iVar11 + 0x18))) {

      *(undefined4 *)(param_1 + 0xe4) = 0x22;

      break;

    }

    if (*(float *)(DAT_00632ed8 + 0x624) == *(float *)(iVar11 + 0x18)) {

      fVar9 = *(float *)(param_1 + 0x274);

      goto LAB_004f32da;

    }

    goto LAB_004f2855;

  case 0x24:

    if ((*(uint *)(param_1 + 0xd8) & 0x80000) == 0) break;

    *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) | 0x10;

    *(int *)(iVar11 + 0x1c) = *(int *)(iVar11 + 0x20);

    if (*(int *)(iVar11 + 0x20) < 0) {

      iVar6 = base_has_partyhouse(*(undefined4 *)(param_1 + 0x274));

      if (iVar6 == 0) {

        if (*(int *)(param_1 + 0x168) == 0) {

          iVar6 = meccbasepit_bldg_from_object(*(undefined4 *)(param_1 + 0x274));

          if (iVar6 == 0) {

            iVar6 = reaperbase_bldg_from_object(*(undefined4 *)(param_1 + 0x274));

            fVar9 = uStack_260;

            if (iVar6 != 0) {

              iVar6 = FUN_004b6c00(param_1,iVar11 + 0x28);

              *(int *)(iVar11 + 0x2c) = iVar6;

              if (iVar6 == -1) break;

              fVar9 = (float)FUN_004b6d20(*(undefined4 *)(param_1 + 0x274),iVar6);

            }

          }

          else {

            iVar6 = FUN_0040abf0(param_1,iVar11 + 0x28);

            *(int *)(iVar11 + 0x2c) = iVar6;

            if (iVar6 == -1) break;

            fVar9 = (float)meccbasepit_get_table_ptr(*(undefined4 *)(param_1 + 0x274),iVar6);

          }

          bldg_get_refpt_worldloc(fVar9,*(undefined4 *)(iVar11 + 0x28),iVar11 + 0x58);

          ai_moveonly_set_goal(param_1,iVar11 + 0x58);

        }

        else {

          iVar6 = *(int *)(param_1 + 0x100);

          iVar4 = ai_goal_process(param_1);

          if (iVar4 == -1) {

            ai_clear_move_goal(param_1);

            ai_move_force_goal(param_1,iVar6 + 0x58);

            ai_goal_process(param_1);

          }

          if (*(int *)(param_1 + 0x168) == 0) {

            *(undefined4 *)(param_1 + 0xe4) = 0x25;

            *(undefined4 *)(param_1 + 0xa0) = *(undefined4 *)(iVar11 + 0x58);

            *(undefined4 *)(param_1 + 0xa4) = *(undefined4 *)(iVar11 + 0x5c);

            *(undefined4 *)(param_1 + 0xa8) = *(undefined4 *)(iVar11 + 0x60);

            *(undefined1 *)(param_1 + 0x20b) = 0;

            *(undefined1 *)(param_1 + 0x20a) = 0;

            *(undefined1 *)(param_1 + 0x208) = 0;

            iVar6 = meccbasepit_bldg_from_object(*(undefined4 *)(param_1 + 0x274));

            if (iVar6 == 0) {

              uVar7 = FUN_004b6d20(*(undefined4 *)(param_1 + 0x274),*(undefined4 *)(iVar11 + 0x2c),

                                   *(undefined4 *)(iVar11 + 0x28),param_1 + 200);

              FUN_00418770(uVar7);

              ObjectSetAnim(param_1,0x5a,0x21,0,0,0x3f2aaaab);

            }

            else {

              uVar7 = meccbasepit_get_table_ptr

                                (*(undefined4 *)(param_1 + 0x274),*(undefined4 *)(iVar11 + 0x2c),

                                 *(undefined4 *)(iVar11 + 0x28),param_1 + 200);

              FUN_00418770(uVar7);

              smartie_make_held_object__FP6OBJECTi(param_1,0x2f2);

              ObjectSetAnim(param_1,0x41,0x20,0,0,0x3f2aaaab);

            }

          }

        }

        break;

      }

      ai_clear_move_goal(param_1);

      *(undefined4 *)(iVar11 + 0x2c) = 0xffffffff;

      *(undefined4 *)(iVar11 + 0x28) = 0xffffffff;

      iVar11 = *(int *)(param_1 + 0x100);

      *(undefined4 *)(param_1 + 0xe4) = 0x1e;

      if (*(int *)(iVar11 + 0x30) == 0) break;

      *(undefined4 *)(*(int *)(iVar11 + 0x30) + 0x210) = 0;

      uVar7 = *(undefined4 *)(iVar11 + 0x30);

      goto LAB_004f26f2;

    }

    ai_clear_move_goal(param_1);

    iVar6 = *(int *)(param_1 + 0x100);

    if (*(int *)(iVar6 + 0x30) != 0) {

      *(undefined4 *)(*(int *)(iVar6 + 0x30) + 0x210) = 0;

      object_destroy(*(undefined4 *)(iVar6 + 0x30));

      *(undefined4 *)(iVar6 + 0x30) = 0;

      *(undefined4 *)(iVar6 + 0x14) = 0x41d80000;

      iVar6 = reaper_0052e4a0(param_1);

      if (iVar6 != 0) {

        reaper_00530bd0(param_1,0,0,0,0x14,0);

      }

    }

    iVar6 = meccbasepit_bldg_from_object(*(undefined4 *)(param_1 + 0x274));

    if (iVar6 == 0) {

      iVar6 = reaperbase_bldg_from_object(*(undefined4 *)(param_1 + 0x274));

      if (iVar6 != 0) {

        food_object_flag_clear

                  (param_1,*(undefined4 *)(iVar11 + 0x2c),*(undefined4 *)(iVar11 + 0x28));

      }

    }

    else {

      FUN_0040ac70(param_1,*(undefined4 *)(iVar11 + 0x2c),*(undefined4 *)(iVar11 + 0x28));

    }

    *(undefined4 *)(iVar11 + 0x2c) = 0xffffffff;

    *(undefined4 *)(iVar11 + 0x28) = 0xffffffff;

    if (*(float *)(iVar11 + 0x18) <= 0.0) goto LAB_004f338e;

LAB_004f280f:

    uVar7 = *(undefined4 *)(param_1 + 0x274);

    iVar11 = *(int *)(param_1 + 0x100);

    iVar6 = meccbasepit_bldg_from_object(uVar7);

LAB_004f2824:

    if (iVar6 == 0) {

LAB_004f287f:

      iVar6 = reaperbase_bldg_from_object(uVar7);

      if ((iVar6 != 0) && (-1 < *(int *)(iVar11 + 0x1c))) {

LAB_004f289a:

        *(undefined4 *)(param_1 + 0xe4) = 0x22;

      }

    }

    else if (((*(int *)(iVar11 + 0x1c) == 0xd) &&

             (iVar6 = base_bldg_is_alive_at_all(uVar7,0xd), iVar6 != 0)) &&

            (iVar6 = FUN_004184d0(uVar7,0xd), iVar6 == 0)) {

      *(undefined4 *)(iVar11 + 0x24) = 0xffffffff;

      *(undefined4 *)(iVar11 + 0x20) = 0xffffffff;

      *(undefined4 *)(iVar11 + 0x1c) = 0xffffffff;

LAB_004f2855:

      *(undefined4 *)(param_1 + 0xe4) = 0x1e;

    }

    else {

LAB_004f2864:

      if (-1 < *(int *)(iVar11 + 0x1c)) {

        *(undefined4 *)(param_1 + 0xe4) = 0x26;

      }

    }

    break;

  case 0x25:

    if (*(int *)(param_1 + 0xe8) == 7) break;

    *(int *)(iVar11 + 0x1c) = *(int *)(iVar11 + 0x20);

    if (-1 < *(int *)(iVar11 + 0x20)) {

      iVar6 = meccbasepit_bldg_from_object(*(undefined4 *)(param_1 + 0x274));

      if (iVar6 == 0) {

        iVar6 = reaperbase_bldg_from_object(*(undefined4 *)(param_1 + 0x274));

        if (iVar6 != 0) {

          food_object_flag_clear

                    (param_1,*(undefined4 *)(iVar11 + 0x2c),*(undefined4 *)(iVar11 + 0x28));

        }

      }

      else {

        FUN_0040ac70(param_1,*(undefined4 *)(iVar11 + 0x2c),*(undefined4 *)(iVar11 + 0x28));

      }

      iVar6 = *(int *)(param_1 + 0x100);

      if (*(int *)(iVar6 + 0x30) != 0) {

        *(undefined4 *)(*(int *)(iVar6 + 0x30) + 0x210) = 0;

        object_destroy(*(undefined4 *)(iVar6 + 0x30));

        *(undefined4 *)(iVar6 + 0x30) = 0;

        *(undefined4 *)(iVar6 + 0x14) = 0x41d80000;

        iVar6 = reaper_0052e4a0(param_1);

        if (iVar6 != 0) {

          reaper_00530bd0(param_1,0,0,0,0x14,0);

        }

      }

      *(undefined4 *)(iVar11 + 0x2c) = 0xffffffff;

      *(undefined4 *)(iVar11 + 0x28) = 0xffffffff;

      if (0.0 < *(float *)(iVar11 + 0x18)) goto LAB_004f280f;

LAB_004f338e:

      *(undefined4 *)(param_1 + 0xe4) = 0x1e;

      break;

    }

    iVar6 = base_has_partyhouse(*(undefined4 *)(param_1 + 0x274));

    if (iVar6 == 0) break;

    ai_clear_move_goal(param_1);

    *(undefined4 *)(iVar11 + 0x2c) = 0xffffffff;

    *(undefined4 *)(iVar11 + 0x28) = 0xffffffff;

    iVar11 = *(int *)(param_1 + 0x100);

    *(undefined4 *)(param_1 + 0xe4) = 0x1e;

    if (*(int *)(iVar11 + 0x30) == 0) break;

    *(undefined4 *)(*(int *)(iVar11 + 0x30) + 0x210) = 0;

    uVar7 = *(undefined4 *)(iVar11 + 0x30);

LAB_004f26f2:

    object_destroy(uVar7);

    *(undefined4 *)(iVar11 + 0x30) = 0;

    *(undefined4 *)(iVar11 + 0x14) = 0x41d80000;

    iVar11 = reaper_0052e4a0(param_1);

    if (iVar11 != 0) {

      reaper_00530bd0(param_1,0,0,0,0x14,0);

    }

    break;

  case 0x26:

    fVar9 = *(float *)(param_1 + 0x274);

    fStack_264 = fVar9;

    if (*(int *)(iVar11 + 0x1c) != *(int *)(iVar11 + 0x20)) {

      ai_clear_move_goal(param_1);

      *(undefined1 *)(param_1 + 0x20b) = 0;

      *(undefined1 *)(param_1 + 0x20a) = 0;

      *(undefined1 *)(param_1 + 0x208) = 0;

      *(undefined4 *)(iVar11 + 0x1c) = *(undefined4 *)(iVar11 + 0x20);

    }

    iVar6 = base_get_smartie_building(param_1);

    if (iVar6 == 0) break;

    iVar6 = obj_maxspeed_lookup(iVar6,0);

    if (iVar6 != 0) {

      ai_clear_move_goal(param_1);

      *(undefined1 *)(param_1 + 0x20b) = 0;

      *(undefined1 *)(param_1 + 0x20a) = 0;

      *(undefined1 *)(param_1 + 0x208) = 0;

      iVar6 = ai_anim_select_mode(param_1,*(undefined4 *)(iVar11 + 0x1c));

      if (iVar6 < 0) {

        *(undefined4 *)(iVar11 + 0x24) = 0xffffffff;

        *(undefined4 *)(iVar11 + 0x20) = 0xffffffff;

        *(undefined4 *)(iVar11 + 0x1c) = 0xffffffff;

      }

      else {

        iVar4 = base_slot_built_check(fStack_264,iVar6);

        if (iVar4 == 0) {

          bldg_spawn_by_type(fStack_264,iVar6);

          reaper_lock_short(fStack_264,iVar6,param_1,1);

        }

        *(int *)(iVar11 + 0x20) = iVar6;

        *(int *)(iVar11 + 0x1c) = iVar6;

      }

      if ((-1 < *(int *)(iVar11 + 0x1c)) && (0.0 < *(float *)(iVar11 + 0x18))) goto LAB_004f280f;

      fVar9 = fStack_264;

      if (*(float *)(DAT_00632ed8 + 0x624) == *(float *)(iVar11 + 0x18)) goto LAB_004f32da;

      goto LAB_004f2855;

    }

    if (*(int *)(param_1 + 0x168) != 0) {

      iVar6 = *(int *)(param_1 + 0x100);

      iVar4 = ai_goal_process(param_1);

      if (iVar4 == -1) {

        ai_clear_move_goal(param_1);

        ai_move_force_goal(param_1,iVar6 + 0x58);

        ai_goal_process(param_1);

      }

      if (*(int *)(param_1 + 0x168) == 0) {

        puVar8 = (undefined4 *)(iVar11 + 0x58);

        object_set_location_p3d(param_1,puVar8);

        *(undefined1 *)(param_1 + 0x20b) = 0;

        *(undefined1 *)(param_1 + 0x20a) = 0;

        *(undefined1 *)(param_1 + 0x208) = 0;

        if (0 < *(int *)(iVar11 + 0x28)) {

          iVar6 = meccbasepit_bldg_from_object(*(undefined4 *)(param_1 + 0x274));

          if (iVar6 == 0) {

            iVar6 = base_slot10_get(*(undefined4 *)(param_1 + 0x274));

          }

          else {

            iVar6 = base_slot15_get(*(undefined4 *)(param_1 + 0x274));

          }

          if (iVar6 == 0) {

            *puVar8 = *(undefined4 *)(param_1 + 0xa0);

            *(undefined4 *)(iVar11 + 0x5c) = *(undefined4 *)(param_1 + 0xa4);

            *(undefined4 *)(iVar11 + 0x60) = *(undefined4 *)(param_1 + 0xa8);

          }

          else {

            bldg_get_refpt_worldlocdir(iVar6,*(undefined4 *)(iVar11 + 0x28),puVar8,param_1 + 200);

            *(undefined4 *)(iVar11 + 0x28) = 0xb;

          }

        }

        *(undefined4 *)(param_1 + 0xe4) = 0x27;

        *(undefined4 *)(param_1 + 0xec) = 0x40000000;

        iVar11 = reaper_0052e4a0(param_1);

        if (iVar11 != 0) {

          iVar11 = meccbasepit_bldg_from_object(*(undefined4 *)(param_1 + 0x274));

          if (iVar11 == 0) {

            iVar11 = base_slot10_get(*(undefined4 *)(param_1 + 0x274));

          }

          else {

            iVar11 = base_slot15_get(*(undefined4 *)(param_1 + 0x274));

          }

          uStack_260 = 0.0;

          if (iVar11 != 0) {

            uStack_260 = *(float *)(iVar11 + 0x188);

          }

          reaper_00530bd0(param_1,0,1,0,0x12,&uStack_260);

        }

      }

      break;

    }

    iVar6 = meccbasepit_bldg_from_object(fVar9);

    if (iVar6 == 0) {

      iVar6 = base_slot10_get(fVar9);

    }

    else {

      iVar6 = base_slot15_get();

    }

    if (iVar6 != 0) {

      *(undefined4 *)(iVar11 + 0x28) = 10;

      bldg_get_refpt_worldloc(iVar6,10,iVar11 + 0x58);

      ai_moveonly_set_goal(param_1,iVar11 + 0x58);

      break;

    }

    goto LAB_004f289a;

  case 0x27:

    fVar13 = (float10)FUN_00518b70(param_1,0);

    fVar13 = (float10)*(float *)(param_1 + 0xec) - fVar13;

    *(float *)(param_1 + 0xec) = (float)fVar13;

    if (fVar13 < (float10)0.0 != (fVar13 == (float10)0.0)) {

      *(undefined4 *)(param_1 + 0xe4) = 0x22;

    }

    iVar6 = meccbasepit_bldg_from_object(*(undefined4 *)(param_1 + 0x274));

    if (iVar6 == 0) {

      uStack_260 = (float)base_slot10_get(*(undefined4 *)(param_1 + 0x274));

    }

    else {

      uStack_260 = (float)base_slot15_get(*(undefined4 *)(param_1 + 0x274));

    }

    if (uStack_260 == 0.0) {

      fStack_254 = *(float *)(param_1 + 0xa0);

      fStack_250 = *(float *)(param_1 + 0xa4);

      fStack_24c = *(float *)(param_1 + 0xa8);

    }

    else {

      bldg_get_refpt_worldloc(uStack_260,*(undefined4 *)(iVar11 + 0x28),&fStack_254);

    }

    puStack_258 = (undefined4 *)(*(float *)(param_1 + 0xec) * 0.5);

    fVar9 = 1.0 - (float)puStack_258;

    object_set_location(param_1,(float)puStack_258 * *(float *)(iVar11 + 0x58) + fStack_254 * fVar9,

                        fStack_250 * fVar9 + (float)puStack_258 * *(float *)(iVar11 + 0x5c),

                        fStack_24c * fVar9 + (float)puStack_258 * *(float *)(iVar11 + 0x60));

    if (((float)puStack_258 < 0.5) && (*(int *)(iVar11 + 0x30) == 0)) {

      iVar4 = NAM_DictionaryGetTotalNames(*(undefined4 *)(param_1 + 0x274));

      iVar6 = *(int *)(param_1 + 0x100);

      if (*(int *)(iVar6 + 0x30) != 0) {

        *(undefined4 *)(*(int *)(iVar6 + 0x30) + 0x210) = 0;

        object_destroy(*(undefined4 *)(iVar6 + 0x30));

        *(undefined4 *)(iVar6 + 0x30) = 0;

        *(undefined4 *)(iVar6 + 0x14) = 0x41d80000;

        iVar6 = reaper_0052e4a0(param_1);

        if (iVar6 != 0) {

          reaper_00530bd0(param_1,0,0,0,0x14,0);

        }

      }

      if (iVar4 == 0) {

        uVar7 = 0x2f9;

      }

      else if (iVar4 == 1) {

        uVar7 = 0x30e;

      }

      else {

        uVar7 = 0x30f;

      }

      smartie_make_held_object__FP6OBJECTi(param_1,uVar7);

      if (uStack_260 != 0.0) {

        bldg_get_refpt_worldlocdir

                  (uStack_260,*(undefined4 *)(iVar11 + 0x28),iVar11 + 0x58,param_1 + 200);

      }

      *(undefined4 *)(iVar11 + 0x28) = 10;

    }

    break;

  case 0x28:

    uVar7 = base_get_smartie_building(param_1);

    bldg_get_refpt_worldlocdir(uVar7,*(undefined4 *)(iVar11 + 0x28),&fStack_254,&uStack_260);

    if (*(float *)(param_1 + 0xec) == 0.0) {

      fVar13 = (float10)dirfcalcp3d__FP3P3DT0(iVar11 + 0x58,&fStack_254);

      *(float *)(param_1 + 200) = (float)fVar13;

    }

    fVar13 = (float10)FUN_00518b70(param_1,0);

    fVar13 = fVar13 * (float10)3.3333333 + (float10)*(float *)(param_1 + 0xec);

    *(float *)(param_1 + 0xec) = (float)fVar13;

    if ((float10)1.0 <= fVar13) {

      uVar24 = 1;

      uVar22 = 0;

      uVar20 = 0x576;

      uVar19 = 0;

      uVar18 = 0x575;

      uVar16 = 0x577;

      iVar6 = param_1;

      uVar7 = sound_get_free_sequence__Fv();

      *(undefined4 *)(iVar11 + 0xb8) = uVar7;

      *(float *)(param_1 + 200) = uStack_260;

      object_set_location_p3d(param_1,&fStack_254,uVar16,uVar18,uVar19,uVar20,iVar6,uVar22,uVar24);

      iVar11 = *(int *)(param_1 + 0x100);

      *(undefined4 *)(param_1 + 0xec) = 0x3fc00000;

      if (*(int *)(iVar11 + 0x30) != 0) {

        *(undefined4 *)(*(int *)(iVar11 + 0x30) + 0x210) = 0;

        object_destroy(*(undefined4 *)(iVar11 + 0x30));

        *(undefined4 *)(iVar11 + 0x30) = 0;

        *(undefined4 *)(iVar11 + 0x14) = 0x41d80000;

        iVar11 = reaper_0052e4a0(param_1);

        if (iVar11 != 0) {

          reaper_00530bd0(param_1,0,0,0,0x14,0);

        }

      }

      *(undefined4 *)(param_1 + 0xe4) = 0x23;

      make_dust_ball(param_1 + 0xa0,0x3f000000);

      break;

    }

    fVar14 = (float10)1.0 - fVar13;

    fVar9 = (float)((float10)fStack_24c * fVar13 + fVar14 * (float10)*(float *)(iVar11 + 0x60));

    fVar23 = (float)((float10)fStack_250 * fVar13 + fVar14 * (float10)*(float *)(iVar11 + 0x5c));

    fVar21 = (float)((float10)fStack_254 * fVar13 + fVar14 * (float10)*(float *)(iVar11 + 0x58));

LAB_004f35c0:

    object_set_location(param_1,fVar21,fVar23,fVar9);

    break;

  case 0x32:

    smartie_handle_reaper_grab__FP6OBJECTP14ObjSpecSmartie(param_1,iVar11);

    break;

  case 0x33:

  case 0x34:

    iVar11 = smartie_check_follow__FP6OBJECTf(param_1,0x41200000);

    if ((iVar11 == 0) || (*(int *)(param_1 + 0xe4) != 0x33)) {

      if (*(int *)(param_1 + 0xe4) != 0x34) break;

      uStack_260 = 1.0;

      fVar13 = (float10)FUN_00518b70(param_1,0);

      fVar13 = (float10)*(float *)(param_1 + 0xec) - fVar13;

      *(float *)(param_1 + 0xec) = (float)fVar13;

      if ((float10)0.0 < fVar13) break;

      if ((*(uint *)(param_1 + 0xd8) & 0x8000000) != 0) {

        uStack_260 = 4.0;

      }

      fVar13 = (float10)FUN_00518b70(param_1,0);

      fVar13 = (float10)*(float *)(param_1 + 0xf0) - fVar13 * (float10)uStack_260;

      *(float *)(param_1 + 0xf0) = (float)fVar13;

      if (fVar13 < (float10)0.0) {

LAB_004f0b0c:

        iVar6 = FUN_004177a0(*(undefined4 *)(param_1 + 0x18c));

        if (iVar6 == 0) break;

        iVar4 = dialog_level_is_base();

        if (iVar4 == 0) {

          iVar11 = ObjIsMecc(DAT_00632a88);

          if (iVar11 == 0) {

            uVar7 = TextGetPtrRandom(s_MPChFlagRetTime_005621e0,&DAT_0055b3bc);

          }

          else {

            uVar7 = TextGetPtrRandom(s_MPChFlagRetTime_005621e0,s_Borjoyzee_0055b3c0);

          }

          crt_sprintf(auStack_200,uVar7);

          chat_insert(auStack_200,1);

        }

        else {

          if (0.0 <= *(float *)(param_1 + 0xf0)) {

            iVar4 = base_which_team(param_1);

            pcVar15 = s_Borjoyzee_0055b3c0;

            if (iVar4 != 1) {

              pcVar15 = &DAT_0055b3bc;

            }

            uVar7 = comm_player_name4(iVar11,pcVar15);

            uVar7 = TextGetPtrRandom(s_MPChFlagRet_005621d4,uVar7);

            crt_sprintf(auStack_200,uVar7);

          }

          else {

            iVar11 = base_which_team(param_1);

            pcVar15 = s_Borjoyzee_0055b3c0;

            if (iVar11 != 1) {

              pcVar15 = &DAT_0055b3bc;

            }

            uVar7 = TextGetPtrRandom(s_MPChFlagRetTime_005621e0,pcVar15);

            crt_sprintf(auStack_200,uVar7);

          }

          comm_audio_volume_user(auStack_200,1,0,0);

        }

        if ((DAT_00632a88 != 0) && (*(int *)(DAT_00632a88 + 0x18c) == *(int *)(param_1 + 0x18c))) {

          iVar11 = dialog_level_is_base();

          if (iVar11 == 0) {

            iVar11 = ObjIsMecc(DAT_00632a88);

            if (iVar11 != 0) goto LAB_004f0cb6;

LAB_004f0c61:

            iVar11 = ObjIsMecc(DAT_00632a88);

            if (iVar11 == 0) {

              uVar7 = *(undefined4 *)(DAT_006330e4 + 0x50e0);

              pcVar15 = s_DELCT30_00562178;

            }

            else {

              iVar11 = crt_rand_scaled(100);

              if (iVar11 < 0x21) {

                uVar7 = *(undefined4 *)(DAT_006330e4 + 0x50e0);

                pcVar15 = s_BAZ_CT30_005621c8;

              }

              else if (iVar11 < 0x42) {

                uVar7 = *(undefined4 *)(DAT_006330e4 + 0x50e0);

                pcVar15 = s_GOR_CT30_0056218c;

              }

              else {

                uVar7 = *(undefined4 *)(DAT_006330e4 + 0x50e0);

                pcVar15 = s_REG_CT30_00562180;

              }

            }

          }

          else {

            iVar11 = base_which_team(param_1);

            if (iVar11 != 1) goto LAB_004f0c61;

LAB_004f0cb6:

            iVar11 = ObjIsMecc(DAT_00632a88);

            if (iVar11 == 0) {

              uVar7 = *(undefined4 *)(DAT_006330e4 + 0x50e0);

              pcVar15 = s_DELCT29_1_00562198;

            }

            else {

              iVar11 = crt_rand_scaled(100);

              if (iVar11 < 0x21) {

                uVar7 = *(undefined4 *)(DAT_006330e4 + 0x50e0);

                pcVar15 = s_BAZ_CT29_005621bc;

              }

              else if (iVar11 < 0x42) {

                uVar7 = *(undefined4 *)(DAT_006330e4 + 0x50e0);

                pcVar15 = s_GOR_CT29_005621b0;

              }

              else {

                uVar7 = *(undefined4 *)(DAT_006330e4 + 0x50e0);

                pcVar15 = s_REG_CT29_005621a4;

              }

            }

          }

          teammecc_clear_mode(pcVar15,uVar7,0);

        }

        objtype_setup_vimp(param_1,iVar6);

        iVar11 = reaper_0052e4a0(param_1);

        if (iVar11 == 0) break;

        uStack_260 = *(float *)(iVar6 + 0x188);

        goto LAB_004f19e6;

      }

      if (iVar11 == 0) break;

      if (*(int *)(iVar11 + 0x18c) == *(int *)(param_1 + 0x18c)) goto LAB_004f0b0c;

      iVar6 = dialog_level_is_base();

      if (iVar6 == 0) {

        iVar6 = ObjIsMecc(DAT_00632a88);

        pcVar15 = s_Borjoyzee_0055b3c0;

        if (iVar6 == 0) {

          pcVar15 = &DAT_0055b3bc;

        }

        uVar7 = comm_player_name4(iVar11,pcVar15);

        uVar7 = TextGetPtrRandom(s_MPChFlagTaken_0055b3ac,uVar7);

      }

      else {

        iVar6 = base_which_team(param_1);

        pcVar15 = s_Borjoyzee_0055b3c0;

        if (iVar6 != 1) {

          pcVar15 = &DAT_0055b3bc;

        }

        uVar7 = comm_player_name4(iVar11,pcVar15);

        uVar7 = TextGetPtrRandom(s_MPChFlagTaken_0055b3ac,uVar7);

      }

      crt_sprintf(auStack_200,uVar7);

      comm_audio_volume_user(auStack_200,1,0,0);

      smartie_board_player__FP6OBJECTT0i(param_1,iVar11,1);

      if ((DAT_00632a88 == 0) || (*(int *)(DAT_00632a88 + 0x18c) != *(int *)(param_1 + 0x18c)))

      break;

      iVar11 = dialog_level_is_base();

      if (iVar11 == 0) {

        iVar11 = ObjIsMecc(DAT_00632a88);

        if (iVar11 != 0) goto LAB_004f0a4f;

        goto LAB_004f0803;

      }

      iVar11 = base_which_team(param_1);

      if (iVar11 != 1) goto LAB_004f0803;

LAB_004f0a4f:

      iVar11 = ObjIsMecc(DAT_00632a88);

      if (iVar11 == 0) {

        teammecc_clear_mode(s_DELCT23_2_00562210,*(undefined4 *)(DAT_006330e4 + 0x50e0),0);

        break;

      }

      iVar11 = crt_rand_scaled(100);

      if (0x31 < iVar11) {

        teammecc_clear_mode(s_REGCT23_00562208,*(undefined4 *)(DAT_006330e4 + 0x50e0),0);

        break;

      }

LAB_004f0a71:

      teammecc_clear_mode(s_GORCT23_2_00561a90,*(undefined4 *)(DAT_006330e4 + 0x50e0),0);

    }

    else {

      iVar6 = dialog_level_is_base();

      if (iVar6 == 0) {

        iVar6 = ObjIsMecc(DAT_00632a88);

        pcVar15 = s_Borjoyzee_0055b3c0;

        if (iVar6 == 0) {

          pcVar15 = &DAT_0055b3bc;

        }

        uVar7 = comm_player_name4(iVar11,pcVar15);

        uVar7 = TextGetPtrRandom(s_MPChFlagTaken_0055b3ac,uVar7);

      }

      else {

        iVar6 = base_which_team(param_1);

        pcVar15 = s_Borjoyzee_0055b3c0;

        if (iVar6 != 1) {

          pcVar15 = &DAT_0055b3bc;

        }

        uVar7 = comm_player_name4(iVar11,pcVar15);

        uVar7 = TextGetPtrRandom(s_MPChFlagTaken_0055b3ac,uVar7);

      }

      crt_sprintf(auStack_200,uVar7);

      comm_audio_volume_user(auStack_200,1,0,0);

      smartie_board_player__FP6OBJECTT0i(param_1,iVar11,1);

      if (*(int *)(param_1 + 4) == 0x248) {

        iVar11 = crt_rand_scaled(100);

        if (iVar11 < 0x32) {

          uVar7 = 0x701;

        }

        else {

          uVar7 = 0x702;

        }

LAB_004f07c5:

        sound_play_obj(uVar7,param_1);

      }

      else if (*(int *)(param_1 + 4) == 0x2e6) {

        iVar11 = crt_rand_scaled(100);

        if (iVar11 < 0x32) {

          uVar7 = 0x70b;

        }

        else {

          uVar7 = 0x70c;

        }

        goto LAB_004f07c5;

      }

      if ((DAT_00632a88 == 0) || (*(int *)(DAT_00632a88 + 0x18c) != *(int *)(param_1 + 0x18c)))

      break;

      iVar11 = dialog_level_is_base();

      if (iVar11 == 0) {

        iVar11 = ObjIsMecc(DAT_00632a88);

        if (iVar11 != 0) goto LAB_004f0860;

      }

      else {

        iVar11 = base_which_team(param_1);

        if (iVar11 == 1) {

LAB_004f0860:

          iVar11 = ObjIsMecc(DAT_00632a88);

          if (iVar11 == 0) {

            teammecc_clear_mode(s_DELCT23_2_00562210,*(undefined4 *)(DAT_006330e4 + 0x50e0),0);

            break;

          }

          iVar11 = crt_rand_scaled(100);

          if (0x31 < iVar11) {

            teammecc_clear_mode(s_REG_CT23_00561a84,*(undefined4 *)(DAT_006330e4 + 0x50e0),0);

            break;

          }

          goto LAB_004f0a71;

        }

      }

LAB_004f0803:

      iVar11 = ObjIsMecc(DAT_00632a88);

      if (iVar11 == 0) {

        teammecc_clear_mode(s_DELCT24_2_005621f0,*(undefined4 *)(DAT_006330e4 + 0x50e0),0);

      }

      else {

        iVar11 = crt_rand_scaled(100);

        if (iVar11 < 0x32) {

          teammecc_clear_mode(s_GOR_CT24_0056221c,*(undefined4 *)(DAT_006330e4 + 0x50e0),0);

        }

        else {

          teammecc_clear_mode(s_REG_CT24_005621fc,*(undefined4 *)(DAT_006330e4 + 0x50e0),0);

        }

      }

    }

    break;

  case 0x37:

    *(undefined4 *)(param_1 + 0x184) = 0x3f800000;

    if (DAT_00632bb8 != 0) {

      *(undefined4 *)(param_1 + 0x184) = 0;

    }

    *(undefined1 *)(param_1 + 0x208) = 0;

    *(undefined1 *)(param_1 + 0x20b) = 0;

    *(undefined1 *)(param_1 + 0x20a) = 0;

    if (*(float *)(iVar11 + 0x18) == 0.0) {

      iVar6 = *(int *)(param_1 + 0x100);

      iVar4 = *(int *)(iVar6 + 0x48);

      if (iVar4 != 0) {

        fx_delete(iVar4);

        *(undefined4 *)(iVar6 + 0x48) = 0;

      }

    }

    *(undefined4 *)(iVar11 + 0x18) = *(undefined4 *)(DAT_00632ed8 + 0x624);

    break;

  case 0x38:

    *(undefined4 *)(param_1 + 0x184) = 0;

    *(undefined1 *)(param_1 + 0x208) = 0;

    *(undefined1 *)(param_1 + 0x20b) = 0;

    *(undefined1 *)(param_1 + 0x20a) = 0;

    fVar13 = (float10)FUN_00518b70(param_1,0);

    fVar13 = (float10)*(float *)(param_1 + 0xec) - fVar13;

    *(float *)(param_1 + 0xec) = (float)fVar13;

    if ((fVar13 < (float10)0.0 != (fVar13 == (float10)0.0)) &&

       (iVar11 = base_has_partyhouse(*(undefined4 *)(param_1 + 0x274)), iVar11 != 0)) {

      *(undefined4 *)(param_1 + 0xe4) = 0x1e;

    }

    break;

  case 0x3c:

  case 0x3d:

    fVar13 = (float10)FUN_00518b70(param_1,0);

    fVar13 = (float10)*(float *)(param_1 + 0xec) - fVar13;

    *(float *)(param_1 + 0xec) = (float)fVar13;

    puVar8 = DAT_00632d6c;

    if (fVar13 < (float10)0.0 != (fVar13 == (float10)0.0)) {

      for (; puVar8 != (undefined4 *)0x0; puVar8 = (undefined4 *)*puVar8) {

        iVar11 = puVar8[3];

        if (*(int *)(iVar11 + 0x1e0) == 0x17) {

          *(undefined4 *)(param_1 + 0xe4) = 0x3c;

          fVar13 = (float10)distancesq2d__FP3P3DT0(param_1 + 0xa0,iVar11 + 0xa0);

          if (fVar13 < (float10)225.0 != (fVar13 == (float10)225.0)) {

            *(undefined4 *)(param_1 + 0xe4) = 0x3d;

            break;

          }

        }

      }

    }

    break;

  case 0x3f:

    if ((*(int *)(iVar11 + 0xa0) != 0) &&

       (iVar6 = ANM_AnimGetImage(*(int *)(iVar11 + 0xa0)), iVar6 == 0)) {

      ai_goal_process(param_1);

      if (*(int *)(param_1 + 0x168) != 0) break;

      fVar13 = (float10)distancesq2d__FP3P3DT0(param_1 + 0xa0,*(int *)(iVar11 + 0xa0) + 0xa0);

      if (fVar13 < (float10)2500.0) {

        *(uint *)(param_1 + 0x1c8) = *(uint *)(param_1 + 0x1c8) | 0x600;

        ai_move_force_goal(param_1,*(int *)(iVar11 + 0xa0) + 0xa0);

        *(undefined4 *)(param_1 + 0xe4) = 0x40;

        break;

      }

      puVar2 = (uint *)(*(int *)(iVar11 + 0xa0) + 0xe0);

      *puVar2 = *puVar2 & 0xfffffffb;

      *(undefined4 *)(iVar11 + 0xa0) = 0;

    }

    goto LAB_004f0e47;

  case 0x40:

    if ((*(int *)(iVar11 + 0xa0) != 0) &&

       (iVar6 = ANM_AnimGetImage(*(int *)(iVar11 + 0xa0)), iVar6 == 0)) {

      ai_goal_process(param_1);

      if (*(int *)(param_1 + 0x168) == 0) {

        *(undefined4 *)(iVar11 + 0xa4) = *(undefined4 *)(param_1 + 0x1d0);

        *(undefined4 *)(param_1 + 0x1d0) = 0;

        fVar13 = (float10)rndfloatrange(0x41200000,0x41a00000);

        *(float *)(param_1 + 0xec) = (float)fVar13;

        *(undefined1 *)(param_1 + 0x20b) = 0;

        *(undefined1 *)(param_1 + 0x20a) = 0;

        *(undefined1 *)(param_1 + 0x208) = 0;

        *(uint *)(param_1 + 0x1c8) = *(uint *)(param_1 + 0x1c8) & 0xfffff9ff;

        *(undefined4 *)(param_1 + 0xe4) = 0x41;

      }

      break;

    }

LAB_004f0e47:

    *(undefined4 *)(param_1 + 0xe4) = 3;

    break;

  case 0x41:

    if ((*(int *)(iVar11 + 0xa0) == 0) ||

       (iVar6 = ANM_AnimGetImage(*(int *)(iVar11 + 0xa0)), iVar6 != 0)) {

      *(undefined4 *)(param_1 + 0x1d0) = *(undefined4 *)(iVar11 + 0xa4);

      fVar13 = (float10)FUN_00518b70(param_1,0);

      *(float *)(param_1 + 0xec) = (float)((float10)*(float *)(param_1 + 0xec) - fVar13);

    }

    if (*(float *)(param_1 + 0xec) < 0.0 != (*(float *)(param_1 + 0xec) == 0.0)) {

      *(undefined4 *)(param_1 + 0xe4) = 3;

    }

    break;

  case 0x50:

    fVar13 = (float10)FUN_00518b70(param_1,0);

    fVar13 = (float10)*(float *)(param_1 + 0xf0) - fVar13;

    *(float *)(param_1 + 0xf0) = (float)fVar13;

    if (fVar13 < (float10)0.0) {

      iVar11 = crt_rand_scaled(100);

      if (iVar11 < 0x32) {

        uVar7 = 0x6b1;

      }

      else {

        uVar7 = 0x6b2;

      }

      sound_play_obj(uVar7,param_1);

      fVar13 = (float10)rndfloatrange(0x41a00000,0x42200000);

      *(float *)(param_1 + 0xf0) = (float)fVar13;

    }

    fVar13 = (float10)FUN_00518b70(param_1,0);

    fVar13 = (float10)*(float *)(param_1 + 0xec) - fVar13;

    *(float *)(param_1 + 0xec) = (float)fVar13;

    if (fVar13 < (float10)0.0) {

      ObjectSetAnim(param_1,0x71,0x20,0,0,0x3f000000);

      *(undefined4 *)(param_1 + 0xe4) = 0x51;

      puVar17 = auStack_234;

      uVar16 = 0x24;

      *(undefined4 *)(param_1 + 0xec) = *(undefined4 *)(DAT_00632ed8 + 0xb04);

      pcVar15 = s_fx_smartie_hang_debri_00562228;

      iStack_21c = param_1;

      uStack_220 = 1;

      uStack_224 = 8;

      uVar7 = fx_get_free_effect__Fv();

      *(undefined4 *)(param_1 + 0xf4) = uVar7;

      sound_play_3(0x6c2,param_1 + 0xa0,param_1,pcVar15,uVar16,puVar17);

    }

    break;

  case 0x51:

    fVar13 = (float10)FUN_00518b70(param_1,0);

    fVar13 = (float10)*(float *)(param_1 + 0xf0) - fVar13;

    *(float *)(param_1 + 0xf0) = (float)fVar13;

    if (fVar13 < (float10)0.0) {

      iVar11 = crt_rand_scaled(100);

      if (iVar11 < 0x32) {

        uVar7 = 0x6b1;

      }

      else {

        uVar7 = 0x6b2;

      }

      sound_play_obj(uVar7,param_1);

      fVar13 = (float10)rndfloatrange(0x40a00000,0x41200000);

      *(float *)(param_1 + 0xf0) = (float)fVar13;

    }

    fVar13 = (float10)FUN_00518b70(param_1,0);

    fVar13 = (float10)*(float *)(param_1 + 0xec) - fVar13;

    *(float *)(param_1 + 0xec) = (float)fVar13;

    if (fVar13 < (float10)0.0) {

      iVar11 = *(int *)(param_1 + 0x210);

      if ((iVar11 != 0) && (*(int *)(iVar11 + 4) == 0x3e9)) {

        iVar6 = 0;

        do {

          if ((*(uint *)(iVar11 + 0xf4) & 1 << ((byte)iVar6 & 0x1f)) != 0) {

            *(uint *)(iVar11 + 0xf4) = ~(1 << ((byte)iVar6 & 0x1f)) & *(uint *)(iVar11 + 0xf4);

            break;

          }

          iVar6 = iVar6 + 1;

        } while (iVar6 < 8);

        if (*(int *)(*(int *)(param_1 + 0x210) + 0xf4) == 0) {

          iVar11 = 8;

          do {

            iVar6 = object_allocate_type(0xb,0x80000000);

            *(undefined4 *)(iVar6 + 0xe8) = 5;

            *(uint *)(iVar6 + 0xdc) = *(uint *)(iVar6 + 0xdc) | *(uint *)(param_1 + 0xdc) & 0xf;

            iVar11 = iVar11 + -1;

            *(uint *)(iVar6 + 0xd8) = *(uint *)(iVar6 + 0xd8) | *(uint *)(param_1 + 0xd8) & 0x400;

          } while (iVar11 != 0);

        }

      }

      *(undefined4 *)(param_1 + 0x210) = 0;

      *(undefined4 *)(param_1 + 0xe4) = 3;

      ObjectSetAnim(param_1,0x73,0x21,0,0,0x3f000000);

      *(undefined4 *)(param_1 + 0xec) = 0x49742400;

      if (*(int *)(param_1 + 0xf4) != 0) {

        fx_delete(*(int *)(param_1 + 0xf4));

      }

      *(undefined4 *)(param_1 + 0xf4) = 0;

      sound_stop_obj(0x6c2,param_1);

    }

    break;

  case 0x52:

    ai_goal_process(param_1);

  }

  obj_alpha_fade_update(param_1);

  player_pitch_update(param_1);

  obj_scale_compute(param_1);

  FUN_004a73a0(param_1);

  FUN_004a7400(param_1);

  iVar11 = reaper_0052e4a0(param_1);

  if (iVar11 != 0) {

    iVar11 = *(int *)(param_1 + 0x100);

    if ((*(int *)(param_1 + 0xe4) != 0x13) && (*(int *)(param_1 + 0xe4) != 0x27)) {

      pfVar1 = (float *)(iVar11 + 0x58);

      if ((*(float *)(iVar11 + 0x58) != *(float *)(iVar11 + 100)) ||

         ((*(float *)(iVar11 + 0x5c) != *(float *)(iVar11 + 0x68) ||

          (*(float *)(iVar11 + 0x60) != *(float *)(iVar11 + 0x6c))))) {

        if (8000.0 < *pfVar1) {

          *pfVar1 = 8000.0;

        }

        if (8000.0 < *(float *)(iVar11 + 0x5c)) {

          *(undefined4 *)(iVar11 + 0x5c) = 0x45fa0000;

        }

        if (*pfVar1 < -8000.0) {

          *pfVar1 = -8000.0;

        }

        if (*(float *)(iVar11 + 0x5c) < -8000.0) {

          *(undefined4 *)(iVar11 + 0x5c) = 0xc5fa0000;

        }

        uVar3 = __ftol();

        uStack_260 = (float)CONCAT22(uStack_260._2_2_,uVar3);

        uVar3 = __ftol();

        uStack_260 = (float)CONCAT22(uVar3,(undefined2)uStack_260);

        comm_chat_send_2(param_1,0,1,0,0x10,&uStack_260);

        *(float *)(iVar11 + 100) = *pfVar1;

        *(undefined4 *)(iVar11 + 0x68) = *(undefined4 *)(iVar11 + 0x5c);

        *(undefined4 *)(iVar11 + 0x6c) = *(undefined4 *)(iVar11 + 0x60);

        return;

      }

      fVar13 = (float10)FUN_00518b70(0,0);

      fVar13 = (float10)*(float *)(iVar11 + 0x7c) - fVar13;

      *(float *)(iVar11 + 0x7c) = (float)fVar13;

      if ((((*(float *)(param_1 + 0xa0) != *(float *)(iVar11 + 0x70)) ||

           (*(float *)(param_1 + 0xa4) != *(float *)(iVar11 + 0x74))) ||

          (*(float *)(param_1 + 0xa8) != *(float *)(iVar11 + 0x78))) &&

         (fVar13 < (float10)0.0 != (fVar13 == (float10)0.0))) {

        uVar3 = __ftol();

        uStack_260 = (float)CONCAT22(uStack_260._2_2_,uVar3);

        uVar3 = __ftol();

        uStack_260 = (float)CONCAT22(uVar3,(undefined2)uStack_260);

        uVar3 = __ftol();

        uStack_25c = CONCAT22(uStack_25c._2_2_,uVar3);

        comm_chat_send_2(param_1,0,0,6,1,&uStack_260);

        *(undefined4 *)(iVar11 + 0x7c) = 0x40400000;

        *(float *)(iVar11 + 0x70) = *(float *)(param_1 + 0xa0);

        *(undefined4 *)(iVar11 + 0x74) = *(undefined4 *)(param_1 + 0xa4);

        *(undefined4 *)(iVar11 + 0x78) = *(undefined4 *)(param_1 + 0xa8);

        return;

      }

    }

  }

  return;

  while (fStack_264 = (float)((int)fStack_264 + 1), (int)fStack_264 < 8) {

LAB_004f00b0:

    if ((*(uint *)(iVar6 + 0xf4) & 1 << (SUB41(fStack_264,0) & 0x1f)) == 0) {

      *(float *)(param_1 + 0x218) = fStack_264;

      *(int *)(param_1 + 0x210) = iVar6;

      *(undefined4 *)(param_1 + 0x214) = 1;

      *(float *)(param_1 + 0xec) =

           *(float *)(DAT_00632ed8 + 0xb00) * (float)(int)fStack_264 +

           *(float *)(DAT_00632ed8 + 0xafc);

      *(uint *)(iVar6 + 0xf4) = *(uint *)(iVar6 + 0xf4) | 1 << (SUB41(fStack_264,0) & 0x1f);

      break;

    }

  }

LAB_004f0111:

  iVar6 = crt_rand_scaled(100,0x21,0,0,0);

  ObjectSetAnim(param_1,(0x31 < iVar6) + 'o');

  goto LAB_004f015a;

LAB_004f1865:

  fVar13 = (float10)distancesq2d__FP3P3DT0(iVar11 + 0xa0,iVar6 + 0xa0);

  if ((float10)100.0 < fVar13) goto LAB_004f187e;

  goto LAB_004f17e7;

}

