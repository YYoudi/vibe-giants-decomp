/* Giants 1.449 — module region_004e
 * 109 functions (109 named) — decompiled, names from PS2 symbols
 * Original source: C:\Giants\source\region_004e.c(pp) (assert-string evidence)
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



void ai_death_anim(OBJECT *param_1)



{

  *(undefined4 *)&param_1->field_0x210 = 0;

  if (DAT_00632d8c == 0) {

    if ((param_1->anim != 0x3d) && (*(int *)(param_1->class_ptr + 0xfc) != 0)) {

      ObjectSetAnim(param_1);

    }

    if (((param_1->flags & 0x80000) != 0) ||

       (*(float *)&param_1->field_0xa8 < 0.0 != (*(float *)&param_1->field_0xa8 == 0.0))) {

      obj_damage_apply(2,0x461c4000,param_1,0,&param_1->field_0xa0,0);

    }

  }

  else {

    sound_stop_sequence(param_1->animate_state + 0x234);

    if ((param_1->anim != 0x65) && (*(int *)(param_1->class_ptr + 0x19c) != 0)) {

      ObjectSetAnim(param_1);

    }

    *(undefined4 *)&param_1->field_0x208 = 0;

    *(undefined4 *)&param_1->field_0x20c = 0;

  }

  *(undefined4 *)(param_1->pad_104 + 0x34) = *(undefined4 *)(DAT_00632ed8 + 0xd5c);

  if (param_1->pad_E4 != 0x8c) {

    if (*(int *)&param_1->field_0xe8 == 0x66) {

      param_1->flags = param_1->flags & 0xffffffef;

      *(uint *)&param_1->field_0x1c8 = *(uint *)&param_1->field_0x1c8 & 0xfffff1ff;

      if (*(float *)&param_1->field_0x278 < *(float *)&param_1->field_0x1c0) {

        rpman_notify_hit(param_1,0);

      }

    }

    param_1->pad_E4 = 0x8c;

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

    sound_play_obj(0x565);

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



void rpman_shot(OBJECT *param_1)



{

  int *piVar1;

  uint uVar2;

  dword dVar3;

  OBJECT *obj;

  undefined1 uVar4;

  int iVar5;

  float10 fVar6;

  float local_38 [2];

  undefined4 local_30;

  undefined4 local_2c;

  undefined4 local_28;

  

  obj = param_1;

  piVar1 = (int *)param_1->animate_state;

  if (param_1->pad_E4 == 0xd8) {

    param_1 = (OBJECT *)0x420551ec;

  }

  else {

    param_1 = *(OBJECT **)(DAT_00632ed8 + 0xa24);

  }

  rpman_setup_firing_parameters__FP6OBJECTi(obj,0xffffffff);

  uVar2 = obj->coll_radius;

  if ((char)uVar2 < '\0') {

    if ((float)piVar1[0xd] <= *(float *)(DAT_00632ed8 + 0xb30) * *(float *)(DAT_00632ed8 + 0xb30)) {

      local_38[0] = (float)crt_rand_scaled(100);

      if (((float)(int)local_38[0] < (float)param_1) &&

         ((float)piVar1[0xd] < (float)piVar1[0x2a] * (float)piVar1[0x2a])) {

        obj->coll_radius = obj->coll_radius & 0xffff7fff;

        if ((obj->anim != 0x96) && (*(int *)(obj->class_ptr + 0x260) != 0)) {

          ObjectSetAnim(obj);

        }

        obj->pad_E4 = 0x2d;

        return;

      }

      iVar5 = crt_rand_scaled(100);

      if ((iVar5 < 10) && (*(int *)&obj->field_0xe8 != 4)) {

        obj->coll_radius = obj->coll_radius | 0x8000;

        iVar5 = crt_rand_scaled(100);

        if ((((iVar5 < 10) && (0.98 < *(float *)&obj->field_0x14c)) &&

            (*(float *)(*piVar1 + 0xa8) - *(float *)&obj->field_0xa8 < 6.0)) &&

           ((float)piVar1[0xd] < *(float *)(DAT_00632ed8 + 0xfdc) * *(float *)(DAT_00632ed8 + 0xfdc)

           )) {

          if ((obj->anim != 0x38) && (*(int *)(obj->class_ptr + 0xe8) != 0)) {

            ObjectSetAnim(obj);

          }

          sine_cos_lookup(*(undefined4 *)&obj->field_0xc8,&param_1,local_38);

          dVar3 = obj->animate_state;

          obj->loc_accum0 = 0;

          obj->pad_128 = (dword)((float)param_1 * 100.0);

          *(float *)&obj->field_0x12c = local_38[0] * -100.0;

          uVar4 = rndintrange(*(undefined4 *)(dVar3 + 0x7c),*(undefined4 *)(dVar3 + 0x80));

          *(undefined1 *)(dVar3 + 0x24) = uVar4;

          uVar4 = rndintrange(*(undefined4 *)(dVar3 + 0x74),*(undefined4 *)(dVar3 + 0x78));

          *(undefined1 *)(dVar3 + 0x25) = uVar4;

          *(undefined4 *)(dVar3 + 0x1c) = 0;

          fVar6 = (float10)rndfloatrange(piVar1[0x21],piVar1[0x22]);

          piVar1[6] = (int)(float)fVar6;

          obj->flags = obj->flags & 0xfcffffff;

          *(undefined4 *)&obj->field_0x208 = 0;

          *(undefined4 *)&obj->field_0x20c = 0;

          obj->pad_E4 = 0x29;

          return;

        }

        if ((obj->anim != 0x32) && (*(int *)(obj->class_ptr + 0xd0) != 0)) {

          ObjectSetAnim(obj);

        }

        dVar3 = obj->animate_state;

        uVar4 = rndintrange(*(undefined4 *)(dVar3 + 0x7c),*(undefined4 *)(dVar3 + 0x80));

        *(undefined1 *)(dVar3 + 0x24) = uVar4;

        uVar4 = rndintrange(*(undefined4 *)(dVar3 + 0x74),*(undefined4 *)(dVar3 + 0x78));

        *(undefined1 *)(dVar3 + 0x25) = uVar4;

        *(undefined4 *)(dVar3 + 0x1c) = 0;

        fVar6 = (float10)rndfloatrange(piVar1[0x21],piVar1[0x22]);

        piVar1[6] = (int)(float)fVar6;

        obj->flags = obj->flags & 0xfcffffff;

        *(undefined4 *)&obj->field_0x208 = 0;

        *(undefined4 *)&obj->field_0x20c = 0;

        obj->pad_E4 = 0x2b;

        return;

      }

      if ((obj->anim != 0x4e) && (*(int *)(obj->class_ptr + 0x140) != 0)) {

        ObjectSetAnim(obj);

      }

      dVar3 = obj->animate_state;

      uVar4 = rndintrange(*(undefined4 *)(dVar3 + 0x7c),*(undefined4 *)(dVar3 + 0x80));

      *(undefined1 *)(dVar3 + 0x24) = uVar4;

      uVar4 = rndintrange(*(undefined4 *)(dVar3 + 0x74),*(undefined4 *)(dVar3 + 0x78));

      *(undefined1 *)(dVar3 + 0x25) = uVar4;

      *(undefined4 *)(dVar3 + 0x1c) = 0;

      fVar6 = (float10)rndfloatrange(piVar1[0x21],piVar1[0x22]);

      piVar1[6] = (int)(float)fVar6;

      obj->flags = obj->flags & 0xfcffffff;

      *(undefined4 *)&obj->field_0x208 = 0;

      *(undefined4 *)&obj->field_0x20c = 0;

      obj->pad_E4 = 0x28;

      goto LAB_004e21cb;

    }

  }

  else if ((uVar2 & 0x400) == 0) {

    if ((uVar2 & 0x100) != 0) {

      iVar5 = crt_rand_scaled(100);

      if ((iVar5 < 0x32) && (*(int *)&obj->field_0xe8 != 4)) {

        if ((obj->anim != 0x77) && (*(int *)(obj->class_ptr + 0x1e4) != 0)) {

          ObjectSetAnim(obj);

        }

        dVar3 = obj->animate_state;

        uVar4 = rndintrange(*(undefined4 *)(dVar3 + 0x7c),*(undefined4 *)(dVar3 + 0x80));

        *(undefined1 *)(dVar3 + 0x24) = uVar4;

        uVar4 = rndintrange(*(undefined4 *)(dVar3 + 0x74),*(undefined4 *)(dVar3 + 0x78));

        *(undefined1 *)(dVar3 + 0x25) = uVar4;

        *(undefined4 *)(dVar3 + 0x1c) = 0;

        fVar6 = (float10)rndfloatrange(piVar1[0x21],piVar1[0x22]);

        piVar1[6] = (int)(float)fVar6;

        obj->coll_radius = obj->coll_radius | 0x8000;

        obj->flags = obj->flags & 0xfcffffff;

        *(undefined4 *)&obj->field_0x208 = 0;

        *(undefined4 *)&obj->field_0x20c = 0;

        obj->pad_E4 = 0x30;

        return;

      }

      if ((obj->anim != 0x74) && (*(int *)(obj->class_ptr + 0x1d8) != 0)) {

        ObjectSetAnim(obj);

      }

      dVar3 = obj->animate_state;

      uVar4 = rndintrange(*(undefined4 *)(dVar3 + 0x7c),*(undefined4 *)(dVar3 + 0x80));

      *(undefined1 *)(dVar3 + 0x24) = uVar4;

      uVar4 = rndintrange(*(undefined4 *)(dVar3 + 0x74),*(undefined4 *)(dVar3 + 0x78));

      *(undefined1 *)(dVar3 + 0x25) = uVar4;

      *(undefined4 *)(dVar3 + 0x1c) = 0;

      fVar6 = (float10)rndfloatrange(piVar1[0x21],piVar1[0x22]);

      piVar1[6] = (int)(float)fVar6;

      obj->coll_radius = obj->coll_radius & 0xffff7fff;

      obj->flags = obj->flags & 0xfcffffff;

      *(undefined4 *)&obj->field_0x208 = 0;

      *(undefined4 *)&obj->field_0x20c = 0;

      obj->pad_E4 = 0x2f;

      return;

    }

    if ((uVar2 & 0x40000) != 0) {

      local_30 = *(undefined4 *)&obj->field_0xa0;

      local_2c = *(undefined4 *)&obj->field_0xa4;

      local_28 = *(undefined4 *)&obj->field_0xa8;

      fx_get_free_effect__Fv();

      line_damage_with_slope

                (0x31,obj,0,&obj->field_0xa0,*(undefined4 *)(DAT_00632ed8 + 0x1094),

                 *(undefined4 *)(DAT_00632ed8 + 0x1098),*(undefined4 *)(DAT_00632ed8 + 0x109c),

                 *(undefined4 *)(DAT_00632ed8 + 0x10a0),obj->ai_state_b);

      rpman_gib__FP6OBJECTT0(obj,0);

      return;

    }

    iVar5 = crt_rand_scaled(100);

    if ((iVar5 < 10) && (*(int *)&obj->field_0xe8 != 4)) {

      if ((obj->anim != 0x94) && (*(int *)(obj->class_ptr + 600) != 0)) {

        ObjectSetAnim(obj);

      }

      dVar3 = obj->animate_state;

      uVar4 = rndintrange(*(undefined4 *)(dVar3 + 0x7c),*(undefined4 *)(dVar3 + 0x80));

      *(undefined1 *)(dVar3 + 0x24) = uVar4;

      uVar4 = rndintrange(*(undefined4 *)(dVar3 + 0x74),*(undefined4 *)(dVar3 + 0x78));

      *(undefined1 *)(dVar3 + 0x25) = uVar4;

      *(undefined4 *)(dVar3 + 0x1c) = 0;

      fVar6 = (float10)rndfloatrange(piVar1[0x21],piVar1[0x22]);

      piVar1[6] = (int)(float)fVar6;

      obj->flags = obj->flags & 0xfcffffff;

      *(undefined4 *)&obj->field_0x208 = 0;

      *(undefined4 *)&obj->field_0x20c = 0;

      obj->pad_E4 = 0x33;

      obj->coll_radius = obj->coll_radius | 0x8000;

      return;

    }

    if ((obj->anim != 0x8c) && (*(int *)(obj->class_ptr + 0x238) != 0)) {

      ObjectSetAnim(obj);

    }

    dVar3 = obj->animate_state;

    uVar4 = rndintrange(*(undefined4 *)(dVar3 + 0x7c),*(undefined4 *)(dVar3 + 0x80));

    *(undefined1 *)(dVar3 + 0x24) = uVar4;

    uVar4 = rndintrange(*(undefined4 *)(dVar3 + 0x74),*(undefined4 *)(dVar3 + 0x78));

    *(undefined1 *)(dVar3 + 0x25) = uVar4;

    *(undefined4 *)(dVar3 + 0x1c) = 0;

    fVar6 = (float10)rndfloatrange(piVar1[0x21],piVar1[0x22]);

    piVar1[6] = (int)(float)fVar6;

    obj->flags = obj->flags & 0xfcffffff;

    *(undefined4 *)&obj->field_0x208 = 0;

    *(undefined4 *)&obj->field_0x20c = 0;

    obj->pad_E4 = 0x32;

    goto LAB_004e21cb;

  }

  rpman_setup_firing_parameters__FP6OBJECTi(obj,0x400);

  if ((obj->anim != 0x50) && (*(int *)(obj->class_ptr + 0x148) != 0)) {

    ObjectSetAnim(obj);

  }

  dVar3 = obj->animate_state;

  uVar4 = rndintrange(*(undefined4 *)(dVar3 + 0x7c),*(undefined4 *)(dVar3 + 0x80));

  *(undefined1 *)(dVar3 + 0x24) = uVar4;

  uVar4 = rndintrange(*(undefined4 *)(dVar3 + 0x74),*(undefined4 *)(dVar3 + 0x78));

  *(undefined1 *)(dVar3 + 0x25) = uVar4;

  *(undefined4 *)(dVar3 + 0x1c) = 0;

  fVar6 = (float10)rndfloatrange(piVar1[0x21],piVar1[0x22]);

  piVar1[6] = (int)(float)fVar6;

  obj->flags = obj->flags & 0xfcffffff;

  *(undefined4 *)&obj->field_0x208 = 0;

  *(undefined4 *)&obj->field_0x20c = 0;

  obj->pad_E4 = 0x35;

LAB_004e21cb:

  obj->coll_radius = obj->coll_radius & 0xffff7fff;

  return;

}

/* ===== type0d7_unique_check @ 0x004E21F0 ===== */
undefined4 type0d7_unique_check(int param_1)



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

    fVar3 = (float10)distancesq3d(param_1 + 0xa0,iVar1 + 0xa0);

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



undefined4 ai_visibility_cull(OBJECT *param_1)



{

  int iVar1;

  undefined1 *puVar2;

  dword dVar3;

  float10 fVar4;

  

  dVar3 = param_1->animate_state;

  if (((_DAT_005a856c < 4.0) || (DAT_005a8568 != 0)) || (*(int *)(dVar3 + 0xd8) != 0)) {

    return 0;

  }

  iVar1 = DAT_00632a88 + 0xa0;

  puVar2 = &param_1->field_0xa0;

  fVar4 = (float10)distancesq3d(puVar2,iVar1);

  if ((float10)57600.0 <= fVar4) {

    return 0;

  }

  fVar4 = (float10)dirfcalcp3d__FP3P3DT0(puVar2,iVar1,*(undefined4 *)(dVar3 + 0x58));

  fVar4 = (float10)diff_angle((float)fVar4);

  if ((float10)60.0 <= fVar4) {

    return 0;

  }

  DAT_005a8568 = 1;

  if ((param_1->coll_radius & 0x200) == 0) {

    if (param_1->anim == 0x47) goto LAB_004e23f6;

    iVar1 = *(int *)(param_1->class_ptr + 0x124);

  }

  else {

    if (param_1->anim == 0x8e) goto LAB_004e23f6;

    iVar1 = *(int *)(param_1->class_ptr + 0x240);

  }

  if (iVar1 != 0) {

    ObjectSetAnim(param_1);

  }

LAB_004e23f6:

  if (*(int *)(dVar3 + 0x134) == 0) {

    *(undefined4 *)(dVar3 + 8) = *(undefined4 *)puVar2;

    *(undefined4 *)(dVar3 + 0xc) = *(undefined4 *)&param_1->field_0xa4;

    *(undefined4 *)(dVar3 + 0x10) = *(undefined4 *)&param_1->field_0xa8;

    *(undefined4 *)(dVar3 + 0x14) = *(undefined4 *)&param_1->field_0xc8;

  }

  param_1->coll_radius = param_1->coll_radius | 0x1000;

  param_1->pad_E4 = 0x46;

  return 1;

}

/* ===== ai_move_pair_caller @ 0x004E2450 ===== */
undefined4 ai_move_pair_caller(OBJECT *param_1)



{

  dword dVar1;

  int iVar2;

  OBJECT *obj;

  dword dVar3;

  undefined4 *puVar4;

  float10 fVar5;

  

  dVar1 = param_1->animate_state;

  if (*(int *)(dVar1 + 0xb0) != 0) {

    return 0;

  }

  fVar5 = (float10)FRateGetSecsframe(param_1,0);

  fVar5 = (float10)*(float *)(dVar1 + 0xd0) - fVar5;

  *(float *)(dVar1 + 0xd0) = (float)fVar5;

  if (fVar5 < (float10)0.0 == (fVar5 == (float10)0.0)) {

    return 0;

  }

  puVar4 = DAT_00632d6c;

  if (*(int *)(dVar1 + 0x134) != 0) {

    for (; puVar4 != (undefined4 *)0x0; puVar4 = (undefined4 *)*puVar4) {

      iVar2 = puVar4[3];

      if (((*(int *)(iVar2 + 4) == 0xd7) &&

          (*(int *)(*(int *)(iVar2 + 0x100) + 0x134) == *(int *)(dVar1 + 0x134))) &&

         (*(int *)(iVar2 + 0xe4) == 0x12d)) {

        fVar5 = (float10)rndfloatrange(0x40800000,0x40e00000);

        *(float *)(dVar1 + 0xd0) = (float)fVar5;

        return 0;

      }

    }

    puVar4 = DAT_00632d6c;

    if (DAT_00632d6c == (undefined4 *)0x0) {

      return 1;

    }

    do {

      obj = (OBJECT *)puVar4[3];

      dVar3 = obj->animate_state;

      if ((obj->type_id == 0xd7) && (*(int *)(dVar3 + 0x134) == *(int *)(dVar1 + 0x134))) {

        ai_move_goals_free(obj,dVar3 + 8,*(undefined4 *)(dVar3 + 0x14));

        if ((obj->coll_radius & 0x200) == 0) {

          if (obj->anim != 0x47) {

            iVar2 = *(int *)(obj->class_ptr + 0x124);

            goto joined_r0x004e25a7;

          }

        }

        else if (obj->anim != 0x8e) {

          iVar2 = *(int *)(obj->class_ptr + 0x240);

joined_r0x004e25a7:

          if (iVar2 != 0) {

            ObjectSetAnim(obj);

          }

        }

        obj->coll_radius = obj->coll_radius & 0xfffff7ff;

        obj->pad_E4 = 0x12;

      }

      puVar4 = (undefined4 *)*puVar4;

      if (puVar4 == (undefined4 *)0x0) {

        return 1;

      }

    } while( true );

  }

  if (*(int *)&param_1->field_0xe8 != 2) {

    ai_damage_response(param_1,1,0,0);

    *(undefined4 *)&param_1->field_0xec = 0x3f800000;

    param_1->pad_E4 = 0xb;

    goto LAB_004e26cb;

  }

  main_ai_move_004014b0(param_1,dVar1 + 8,*(undefined4 *)(dVar1 + 0x14));

  if ((param_1->coll_radius & 0x200) == 0) {

    if (param_1->anim != 0x47) {

      iVar2 = *(int *)(param_1->class_ptr + 0x124);

      goto joined_r0x004e2696;

    }

  }

  else if (param_1->anim != 0x8e) {

    iVar2 = *(int *)(param_1->class_ptr + 0x240);

joined_r0x004e2696:

    if (iVar2 != 0) {

      ObjectSetAnim(param_1);

    }

  }

  param_1->pad_E4 = 0x12;

LAB_004e26cb:

  param_1->coll_radius = param_1->coll_radius & 0xfffff7ff;

  return 1;

}

/* ===== ai_damage_update @ 0x004E26E0 ===== */
undefined4 ai_damage_update(OBJECT *param_1,OBJECT *param_2)



{

  float fVar1;

  dword dVar2;

  OBJECT *pOVar3;

  int iVar4;

  undefined4 *puVar5;

  OBJECT *obj;

  int *piVar6;

  OBJECT *obj_00;

  

  obj = param_1;

  if ((param_2 != (OBJECT *)0x0) && (*(float *)&param_2->field_0xf8 == 0.0)) {

    return 0;

  }

  dVar2 = param_1->animate_state;

  param_1 = (OBJECT *)0x0;

  piVar6 = DAT_00632d6c;

  obj_00 = param_2;

  if (DAT_00632d6c == (int *)0x0) {

LAB_004e2769:

    if (*(int *)(dVar2 + 0x6c) != 0) goto LAB_004e27e0;

    if (param_2 != (OBJECT *)0x0) {

      ai_damage_response(obj,0,0,0);

      if (*(int *)&obj->field_0xe8 == 0x66) {

        if (*(int *)(param_2->animate_state + 0x5c) == 0) {

          obj->pad_E4 = 0xcc;

        }

        else {

          obj->pad_E4 = 0xd5;

        }

      }

      else {

        obj->pad_E4 = 0x20;

      }

      iVar4 = *(int *)(dVar2 + 0x134);

      if ((iVar4 != 0) && (*(int *)(iVar4 + 0x1e0) == 0x61)) {

        *(undefined4 *)(iVar4 + 0xe4) = 3;

      }

      goto LAB_004e2821;

    }

  }

  else {

    do {

      pOVar3 = (OBJECT *)piVar6[3];

      if (((pOVar3->type_id == 0xd7) &&

          (*(int *)(pOVar3->animate_state + 0x134) == *(int *)(dVar2 + 0x134))) &&

         (param_1 = (OBJECT *)((int)param_1 + 1), *(int *)(pOVar3->animate_state + 0xb0) == 0)) {

        obj_00 = pOVar3;

      }

      piVar6 = (int *)*piVar6;

    } while (piVar6 != (int *)0x0);

    if ((int)param_1 < 2) goto LAB_004e2769;

LAB_004e27e0:

    if ((obj_00->anim != 0x51) && (*(int *)(obj_00->class_ptr + 0x14c) != 0)) {

      ObjectSetAnim(obj_00);

    }

    obj_00->pad_E4 = 0x1f;

LAB_004e2821:

    if (param_2 != (OBJECT *)0x0) {

      fVar1 = *(float *)&param_2->field_0xf8;

      *(float *)(dVar2 + 0xbc) = fVar1;

      if (3600.0 <= fVar1) {

        *(undefined4 *)(dVar2 + 0xc0) = 1;

      }

      puVar5 = DAT_00632d68;

      if (*(int *)&obj->field_0xe8 == 0x66) {

        for (; puVar5 != (undefined4 *)0x0; puVar5 = (undefined4 *)*puVar5) {

          iVar4 = puVar5[3];

          if (((*(int *)(iVar4 + 4) == 0x48a) &&

              (*(int *)(iVar4 + 0xe8) == *(int *)&param_2->field_0xe8)) &&

             (*(int *)(iVar4 + 0x174) == *(int *)&param_2->field_0x174 + -1)) {

            *(undefined4 *)(*(int *)(iVar4 + 0x100) + 0x5c) = 1;

            *(undefined4 *)(iVar4 + 0xf8) = 0x4426aaa0;

            break;

          }

        }

      }

      goto LAB_004e28c4;

    }

  }

  *(undefined4 *)(obj_00->animate_state + 0xbc) = 0;

  obj_00->coll_radius = obj_00->coll_radius | 0x2000;

LAB_004e28c4:

  if ((*(int *)(dVar2 + 0xb0) == 0) || ((int)param_1 < 2)) {

    if (param_1 == (OBJECT *)0x1) {

      *(undefined4 *)(dVar2 + 0x14) = *(undefined4 *)&obj->field_0xc8;

      *(undefined4 *)(dVar2 + 8) = *(undefined4 *)&obj->field_0xa0;

      *(undefined4 *)(dVar2 + 0xc) = *(undefined4 *)&obj->field_0xa4;

      *(undefined4 *)(dVar2 + 0x10) = *(undefined4 *)&obj->field_0xa8;

    }

  }

  else {

    if (*(int *)(obj->animate_state + 0xd8) != 0) {

      cleaner_process(obj,0);

      return 1;

    }

    if ((obj->coll_radius & 0x200) == 0) {

      if ((obj->anim != 0x53) && (*(int *)(obj->class_ptr + 0x154) != 0)) {

        ObjectSetAnim(obj);

        return 1;

      }

    }

    else if ((obj->anim != 0x92) && (*(int *)(obj->class_ptr + 0x250) != 0)) {

      ObjectSetAnim(obj);

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

/* ===== rpman_return_refpt_eval @ 0x004E2B10 ===== */
/* PS2 candidate: rpman_spline_return_info (conf 0.7) */



void rpman_return_refpt_eval(int param_1)



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

      fVar5 = (float10)FRateGetSecsframe(param_1,0,0x461c4000,(float)fVar5,param_1 + 200);

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

    fVar6 = (float10)FRateGetSecsframe(param_1,0);

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

          fVar6 = (float10)distancesq3d(param_1 + 0xa0,iVar4 + 0xa0);

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

  fVar6 = (float10)FRateGetSecsframe(param_1,0);

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

    fVar6 = (float10)FRateGetSecsframe(param_1,0);

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

    fVar3 = (float10)distancesq3d(param_1 + 0xa0,piVar1);

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

/* ===== spawn_clearance_check @ 0x004E3730 ===== */
bool spawn_clearance_check(int param_1)



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

                    fVar9 = (float10)distancesq3d(param_1 + 0xa0,iVar4 + 0xa0);

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

          fVar9 = (float10)distancesq3d(puVar2,puVar1);

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

        fVar9 = (float10)distancesq3d(param_1 + 0xa0,*piVar3 + 0xa0);

        piVar3[0xd] = (int)(float)fVar9;

        return;

      }

    }

  }

  else {

    *piVar3 = iVar4;

    fVar9 = (float10)distancesq3d(param_1 + 0xa0,iVar4 + 0xa0);

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

  float10 fVar2;

  

  iVar1 = *(int *)(param_1 + 0x100);

  fVar2 = (float10)FRateGetSecsframe(param_1,0);

  fVar2 = (float10)*(float *)(iVar1 + 0x40) - fVar2;

  *(float *)(iVar1 + 0x40) = (float)fVar2;

  if (fVar2 < (float10)0.0) {

    fVar2 = (float10)rndfloatrange(0x41a00000,0x42c80000);

    *(float *)(iVar1 + 0x40) = (float)fVar2;

    iVar1 = rndintrange(0x7d,0x81);

    sound_play_obj(iVar1);

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



void rpman_maintain_hide__FP6OBJECT(OBJECT *param_1)



{

  float fVar1;

  int *piVar2;

  int iVar3;

  float fVar4;

  undefined1 uVar5;

  float10 fVar6;

  float local_8;

  float local_4;

  

  piVar2 = (int *)param_1->animate_state;

  if (piVar2[0x11] == 0) {

    rpman_find_hide_spot__FP6OBJECTi(param_1,1);

    if (piVar2[0x11] != 0) {

      param_1->pad_E4 = 0x3c;

      return;

    }

    param_1->pad_E4 = 0xc;

    return;

  }

  fVar6 = (float10)dirfcalcp3d__FP3P3DT0(piVar2[0x11] + 0xa0,*piVar2 + 0xa0);

  fVar1 = (float)fVar6;

  sine_cos_lookup(fVar1 + 180.0,&local_8,&local_4);

  iVar3 = piVar2[0x11];

  fVar4 = *(float *)(iVar3 + 0x1f8) * *(float *)(iVar3 + 0xc4) + (float)param_1->waypoint1;

  piVar2[0x12] = (int)(fVar4 * local_8 + *(float *)(iVar3 + 0xa0));

  piVar2[0x13] = (int)(*(float *)(iVar3 + 0xa4) - fVar4 * local_4);

  piVar2[0x14] = *(int *)(iVar3 + 0xa8);

  param_1->orders_head = 0x42800000;

  fVar6 = (float10)playerobj_turn(fVar1,*(undefined4 *)&param_1->field_0xc8);

  if (ABS(fVar6) != (float10)0.0) {

    param_1->flags = param_1->flags | 0x1000000;

    param_1->waypoint2 = (dword)fVar1;

    uVar5 = __ftol();

    param_1->field_0x208 = uVar5;

  }

  if ((param_1->field_0x208 == '\0') || (param_1->pad_E4 != 0x41)) {

    if (((param_1->field_0x30 & 2) == 0) || (param_1->anim == 0x2d)) goto LAB_004e4520;

    iVar3 = *(int *)(param_1->class_ptr + 0xbc);

  }

  else {

    if (param_1->anim == 0x9d) goto LAB_004e4520;

    iVar3 = *(int *)(param_1->class_ptr + 0x27c);

  }

  if (iVar3 != 0) {

    ObjectSetAnim(param_1);

  }

LAB_004e4520:

  obj_alpha_fade_update(param_1);

  param_1->orders_head = piVar2[0x6b];

  param_1->field_0x208 = 0;

  sine_cos_lookup(*(float *)&param_1->field_0xc8 + 180.0,&local_8,&local_4);

  *(float *)&param_1->field_0xa0 = fVar4 * local_8 + *(float *)(piVar2[0x11] + 0xa0);

  *(float *)&param_1->field_0xa4 = *(float *)(piVar2[0x11] + 0xa4) - fVar4 * local_4;

  fVar6 = (float10)get_floor_z_point(&param_1->field_0xa0);

  *(float *)&param_1->field_0xa8 = (float)fVar6;

  return;

}

/* ===== rpman_set_anim_flags @ 0x004E45A0 ===== */
void rpman_set_anim_flags(OBJECT *param_1)



{

  if ((param_1->coll_radius & 0x200) == 0) {

    if ((param_1->coll_radius & 0x100) == 0) {

      if ((param_1->anim != 0x52) && (*(int *)(param_1->class_ptr + 0x150) != 0)) {

        ObjectSetAnim(param_1);

      }

    }

    else if ((param_1->anim != 0x9c) && (*(int *)(param_1->class_ptr + 0x278) != 0)) {

      ObjectSetAnim(param_1);

      return;

    }

  }

  else if ((param_1->anim != 0x91) && (*(int *)(param_1->class_ptr + 0x24c) != 0)) {

    ObjectSetAnim(param_1);

    return;

  }

  return;

}

/* ===== ai_rand_anim_select @ 0x004E4680 ===== */
void ai_rand_anim_select(OBJECT *param_1,int param_2,int param_3)



{

  int iVar1;

  float10 fVar2;

  

  iVar1 = crt_rand_scaled(100);

  if ((param_1->coll_radius & 0x200) == 0) {

    if ((*(float *)(DAT_00632ed8 + 0xb54) <= (float)iVar1) || (param_2 == 0)) {

      if (param_1->anim == 0x50) {

        return;

      }

      if (*(int *)(param_1->class_ptr + 0x148) == 0) {

        return;

      }

      if (param_3 != 0) {

        fVar2 = (float10)rndfloatrange(0,0x3f800000);

        param_1->pad_14 = (dword)(float)fVar2;

      }

      ObjectSetAnim(param_1);

      return;

    }

  }

  else if ((*(float *)(DAT_00632ed8 + 0xb54) <= (float)iVar1) || (param_2 == 0)) {

    if ((param_1->anim != 0x8c) && (*(int *)(param_1->class_ptr + 0x238) != 0)) {

      if (param_3 != 0) {

        fVar2 = (float10)rndfloatrange(0,0x3f800000);

        param_1->pad_14 = (dword)(float)fVar2;

      }

      ObjectSetAnim(param_1);

      return;

    }

    return;

  }

  ai_damage_response(param_1,0,0,param_3);

  return;

}

/* ===== ai_idle_anim_select @ 0x004E47C0 ===== */
void ai_idle_anim_select(OBJECT *param_1)



{

  int iVar1;

  

  if (*(int *)(param_1->animate_state + 0xd8) != 0) {

    ai_range_check(param_1);

    return;

  }

  if ((param_1->coll_radius & 0x200) == 0) {

    iVar1 = crt_rand_scaled(300);

    if (iVar1 < 100) {

      if ((param_1->anim != 0x54) && (*(int *)(param_1->class_ptr + 0x158) != 0)) {

        ObjectSetAnim(param_1);

        return;

      }

    }

    else if (iVar1 < 200) {

      if ((param_1->anim != 0x55) && (*(int *)(param_1->class_ptr + 0x15c) != 0)) {

        ObjectSetAnim(param_1);

        return;

      }

    }

    else if ((param_1->anim != 0x7d) && (*(int *)(param_1->class_ptr + 0x1fc) != 0)) {

      ObjectSetAnim(param_1);

    }

  }

  else if ((param_1->anim != 0x93) && (*(int *)(param_1->class_ptr + 0x254) != 0)) {

    ObjectSetAnim(param_1);

    return;

  }

  return;

}

/* ===== ai_idle_anim_53 @ 0x004E4920 ===== */
void ai_idle_anim_53(OBJECT *param_1,int param_2)



{

  float10 fVar1;

  

  if (*(int *)(param_1->animate_state + 0xd8) != 0) {

    cleaner_process(param_1,param_2);

    return;

  }

  if ((param_1->coll_radius & 0x200) == 0) {

    if ((param_1->anim != 0x53) && (*(int *)(param_1->class_ptr + 0x154) != 0)) {

      if (param_2 != 0) {

        fVar1 = (float10)rndfloatrange(0,0x3f800000);

        param_1->pad_14 = (dword)(float)fVar1;

      }

      ObjectSetAnim(param_1);

    }

  }

  else if ((param_1->anim != 0x92) && (*(int *)(param_1->class_ptr + 0x250) != 0)) {

    if (param_2 != 0) {

      fVar1 = (float10)rndfloatrange(0,0x3f800000);

      param_1->pad_14 = (dword)(float)fVar1;

    }

    ObjectSetAnim(param_1);

    return;

  }

  return;

}

/* ===== ai_range_check @ 0x004E4A50 ===== */
void ai_range_check(OBJECT *param_1)



{

  float10 fVar1;

  float10 fVar2;

  float10 fVar3;

  

  if ((param_1->pad_E4 == 0x1e) || ((param_1->coll_radius & 0x2000000) != 0)) {

    fVar3 = (float10)FRateGetSecsframe(param_1,0);

    fVar2 = (float10)*(float *)&param_1->field_0xa4 - (float10)*(float *)&param_1->field_0xbc;

    fVar1 = (float10)*(float *)&param_1->field_0xa0 - (float10)*(float *)&param_1->field_0xb8;

    fVar3 = SQRT(fVar2 * fVar2 + fVar1 * fVar1) / fVar3;

    fVar3 = fVar3 * fVar3;

  }

  else {

    fVar3 = (float10)*(float *)&param_1->field_0x12c * (float10)*(float *)&param_1->field_0x12c +

            (float10)(float)param_1->pad_128 * (float10)(float)param_1->pad_128;

  }

  fVar2 = (float10)*(float *)(DAT_00632ed8 + 0x1028) * (float10)*(float *)(DAT_00632ed8 + 0x1028);

  if (fVar3 < fVar2 == (fVar3 == fVar2)) {

    fVar2 = (float10)*(float *)(DAT_00632ed8 + 0x102c) * (float10)*(float *)(DAT_00632ed8 + 0x102c);

    if (fVar3 < fVar2 == (fVar3 == fVar2)) {

      if ((param_1->anim != 0x84) && (*(int *)(param_1->class_ptr + 0x218) != 0)) {

        ObjectSetAnim(param_1);

      }

    }

    else if ((param_1->anim != 0x82) && (*(int *)(param_1->class_ptr + 0x210) != 0)) {

      ObjectSetAnim(param_1);

      return;

    }

  }

  else if ((param_1->anim != 0x81) && (*(int *)(param_1->class_ptr + 0x20c) != 0)) {

    ObjectSetAnim(param_1);

    return;

  }

  return;

}

/* ===== cleaner_process @ 0x004E4BC0 ===== */
/* PS2 candidate: cleaner_process (conf 0.541) */



void cleaner_process(OBJECT *param_1,int param_2)



{

  float fVar1;

  OBJECT *obj;

  int iVar2;

  float10 fVar3;

  float10 fVar4;

  float10 fVar5;

  float local_c;

  float local_8;

  float local_4;

  

  obj = param_1;

  if ((param_1->pad_E4 == 0x1e) || ((param_1->coll_radius & 0x2000000) != 0)) {

    fVar3 = (float10)FRateGetSecsframe(param_1,0);

    fVar4 = (float10)*(float *)&param_1->field_0xa4 - (float10)*(float *)&param_1->field_0xbc;

    fVar5 = (float10)*(float *)&param_1->field_0xa0 - (float10)*(float *)&param_1->field_0xb8;

    fVar3 = SQRT(fVar4 * fVar4 + fVar5 * fVar5) / fVar3;

    param_1 = (OBJECT *)(float)(fVar3 * fVar3);

  }

  else {

    local_c = -*(float *)&param_1->field_0x29c;

    local_8 = -*(float *)&param_1->field_0x2ac;

    local_4 = -*(float *)&param_1->field_0x2bc;

    fVar3 = (float10)Dot__FP3P3DT0(&param_1->pad_128,&local_c);

    if (fVar3 < (float10)0.0) {

      if (param_1->anim == 0xa4) {

        return;

      }

      if (*(int *)(param_1->class_ptr + 0x298) == 0) {

        return;

      }

      ObjectSetAnim(param_1);

      return;

    }

    fVar1 = (float)param_1->pad_128;

    param_1 = (OBJECT *)

              (*(float *)&param_1->field_0x12c * *(float *)&param_1->field_0x12c + fVar1 * fVar1);

  }

  iVar2 = crt_rand_scaled(100);

  if (iVar2 < 10) {

    ai_range_check(obj);

    return;

  }

  fVar1 = *(float *)(DAT_00632ed8 + 0x1028) * *(float *)(DAT_00632ed8 + 0x1028);

  if ((float)param_1 < fVar1 == ((float)param_1 == fVar1)) {

    fVar1 = *(float *)(DAT_00632ed8 + 0x102c) * *(float *)(DAT_00632ed8 + 0x102c);

    if ((float)param_1 < fVar1 == ((float)param_1 == fVar1)) {

      if ((obj->anim != 0x83) && (*(int *)(obj->class_ptr + 0x214) != 0)) {

        if (param_2 != 0) {

          fVar3 = (float10)rndfloatrange(0,0x3f800000);

          obj->pad_14 = (dword)(float)fVar3;

        }

        ObjectSetAnim(obj);

      }

    }

    else if ((obj->anim != 0x82) && (*(int *)(obj->class_ptr + 0x210) != 0)) {

      if (param_2 != 0) {

        fVar3 = (float10)rndfloatrange(0,0x3f800000);

        obj->pad_14 = (dword)(float)fVar3;

      }

      ObjectSetAnim(obj);

      return;

    }

  }

  else if ((obj->anim != 0x80) && (*(int *)(obj->class_ptr + 0x208) != 0)) {

    if (param_2 != 0) {

      fVar3 = (float10)rndfloatrange(0,0x3f800000);

      obj->pad_14 = (dword)(float)fVar3;

    }

    ObjectSetAnim(obj);

    return;

  }

  return;

}

/* ===== rpman_hurt_anim @ 0x004E4E70 ===== */
void rpman_hurt_anim(OBJECT *param_1,int param_2)



{

  uint uVar1;

  int iVar2;

  dword dVar3;

  

  if ((param_1->coll_radius & 0x200) != 0) {

    ai_damage_response(param_1,1,0,0);

    return;

  }

  uVar1 = param_1->coll_radius | 0x8004000;

  param_1->coll_radius = uVar1;

  if (param_2 == 0) {

    dVar3 = param_1->anim;

    if ((char)(uVar1 >> 8) < '\0') {

      if (dVar3 == 0x7f) {

        return;

      }

      iVar2 = *(int *)(param_1->class_ptr + 0x204);

      goto LAB_004e4f31;

    }

  }

  else {

    iVar2 = crt_rand_scaled(100);

    dVar3 = param_1->anim;

    if (iVar2 < 0x33) {

      param_1->coll_radius = param_1->coll_radius | 0x8000;

      if (dVar3 == 0x7f) {

        return;

      }

      iVar2 = *(int *)(param_1->class_ptr + 0x204);

LAB_004e4f31:

      if (iVar2 == 0) {

        return;

      }

      ObjectSetAnim(param_1);

      return;

    }

    param_1->coll_radius = param_1->coll_radius & 0xffff7fff;

  }

  if ((dVar3 != 0x7e) && (*(int *)(param_1->class_ptr + 0x200) != 0)) {

    ObjectSetAnim(param_1);

  }

  return;

}

/* ===== rpman_sniper_anim_set @ 0x004E4F60 ===== */
void rpman_sniper_anim_set(OBJECT *param_1)



{

  if ((param_1->coll_radius & 0x200) == 0) {

    if ((param_1->anim != 0x47) && (*(int *)(param_1->class_ptr + 0x124) != 0)) {

      ObjectSetAnim(param_1);

    }

  }

  else if ((param_1->anim != 0x8e) && (*(int *)(param_1->class_ptr + 0x240) != 0)) {

    ObjectSetAnim(param_1);

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

    fVar4 = (float10)FRateGetSecsframe(param_1,0);

    piVar2[7] = (int)(float)((float10)(float)piVar2[7] - fVar4);

    return;

  }

  if ((float)piVar2[6] < 0.0 == ((float)piVar2[6] == 0.0)) {

    fVar4 = (float10)FRateGetSecsframe(param_1,0);

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

      sound_play_obj(0x568);

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

  fVar4 = (float10)FRateGetSecsframe(iVar2,0);

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



void fire_sniper_shot__FP6OBJECTT0(OBJECT *param_1,dword param_2,dword param_3,float param_4)



{

  char *pcVar1;

  float fVar2;

  float fVar3;

  int *piVar4;

  dword dVar5;

  int *piVar6;

  undefined4 *puVar7;

  bool bVar8;

  undefined1 uVar9;

  int iVar10;

  int iVar11;

  int iVar12;

  float10 fVar13;

  float10 fVar14;

  undefined4 uVar15;

  OBJECT *pOVar16;

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

  

  piVar4 = (int *)param_1->animate_state;

  bVar8 = false;

  if (*piVar4 != 0) {

    iVar10 = *piVar4 + 0xa0;

    if (*(int *)&param_1->field_0xe8 == 4) {

      fVar13 = (float10)dirfcalcp3d__FP3P3DT0(&param_1->field_0xa0,iVar10);

      fVar2 = (float)fVar13;

      fVar13 = (float10)playerobj_turn(fVar2,piVar4[0x56]);

      fVar3 = (float)fVar13;

      fVar13 = (float10)playerobj_turn(fVar2,*(undefined4 *)&param_1->field_0xc8);

      if (ABS(fVar13) != (float10)0.0) {

        param_1->flags = param_1->flags | 0x1000000;

        param_1->waypoint2 = (dword)fVar2;

        uVar9 = __ftol();

        param_1->field_0x208 = uVar9;

      }

      if ((fVar3 < *(float *)(&DAT_005a84e8 + piVar4[0x55] * 4)) ||

         (fVar3 < *(float *)(&DAT_005a8550 + piVar4[0x55] * 4) ==

          (fVar3 == *(float *)(&DAT_005a8550 + piVar4[0x55] * 4)))) {

        bVar8 = true;

      }

      else {

        bVar8 = false;

      }

    }

    else {

      fVar13 = (float10)dirfcalcp3d__FP3P3DT0(&param_1->field_0xa0,iVar10);

      fVar14 = (float10)playerobj_turn((float)fVar13,*(undefined4 *)&param_1->field_0xc8);

      if (ABS(fVar14) != (float10)0.0) {

        param_1->waypoint2 = (dword)(float)fVar13;

        param_1->flags = param_1->flags | 0x1000000;

        uVar9 = __ftol();

        param_1->field_0x208 = uVar9;

      }

    }

  }

  if (((float)piVar4[7] < 0.0 == ((float)piVar4[7] == 0.0)) || (bVar8)) {

    fVar13 = (float10)FRateGetSecsframe(param_1,0);

    piVar4[7] = (int)(float)((float10)(float)piVar4[7] - fVar13);

    if (!bVar8) {

      return;

    }

  }

  else {

    if ((float)piVar4[6] < 0.0 != ((float)piVar4[6] == 0.0)) {

      if ((param_1->field_0x30 & 2) == 0) {

        return;

      }

      if ((param_1->anim != param_2) && (*(int *)(param_1->class_ptr + 8 + param_2 * 4) != 0)) {

        ObjectSetAnim(param_1);

      }

      fVar13 = (float10)rndfloatrange(piVar4[0x21],piVar4[0x22]);

      piVar4[6] = (int)(float)fVar13;

      if (param_4 == 0.0) {

        return;

      }

      iVar10 = *(int *)&param_1->field_0x274;

      iVar12 = *piVar4;

      dVar5 = param_1->animate_state;

      playerobj_eval_refpt(iVar10,2,&local_5c);

      if (iVar12 == 0) {

        local_68 = *(float *)(dVar5 + 0x28);

        local_64 = *(float *)(dVar5 + 0x2c);

        local_60 = *(float *)(dVar5 + 0x30);

      }

      else {

        local_68 = *(float *)(iVar12 + 0xa0);

        local_64 = *(float *)(iVar12 + 0xa4);

        local_60 = *(float *)(iVar12 + 0xa8);

        iVar11 = obj_is_pickup_4a(iVar12);

        if ((iVar11 == 0) && (iVar11 = obj_is_pickup_53(iVar12), iVar11 == 0)) {

          iVar11 = ObjIsPlayer(iVar12);

          if (iVar11 != 0) {

            local_60 = *(float *)(iVar12 + 0x1e8) * *(float *)(iVar12 + 0xc4) + local_60;

          }

        }

        else {

          iVar11 = obj_is_pickup_4a_model(iVar12);

          if ((iVar11 == 0) && (iVar11 = obj_is_pickup_53_model(iVar12), iVar11 == 0)) {

            local_60 = local_60 + 2.0;

          }

          else {

            fVar13 = (float10)rndfloatrange(-*(float *)&param_1->field_0x1e8,0x40000000);

            local_60 = (float)(fVar13 + (float10)local_60 + (float10)*(float *)&param_1->field_0x1e8

                              );

          }

        }

      }

      if (*(float *)(dVar5 + 0x34) <

          *(float *)(DAT_00632ed8 + 0xa84) * *(float *)(DAT_00632ed8 + 0xa84)) {

        fVar2 = *(float *)(DAT_00632ed8 + 0xa7c) * *(float *)(DAT_00632ed8 + 0xa7c);

        if (*(float *)(dVar5 + 0x34) < fVar2 == (*(float *)(dVar5 + 0x34) == fVar2)) {

          param_4 = (SQRT(*(float *)(dVar5 + 0x34)) - *(float *)(DAT_00632ed8 + 0xa7c)) /

                    (*(float *)(DAT_00632ed8 + 0xa84) - *(float *)(DAT_00632ed8 + 0xa7c));

        }

        else {

          param_4 = 0.0;

        }

      }

      else {

        param_4 = 1.0;

      }

      iVar12 = ObjIsPlayer(iVar12);

      if (iVar12 != 0) {

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

      playerobj_eval_refpt(iVar10,2,&local_5c);

      fVar13 = (float10)dirfcalcp3d__FP3P3DT0(&local_5c,&local_68);

      fVar14 = (float10)dirucalcp3d__FP3P3DT0(&local_5c,&local_68);

      local_44[0] = 0;

      GEO_MatBuildXYZ(local_44,(float)-fVar14,0,(float)fVar13);

      local_14 = local_54;

      local_24 = local_58;

      local_44[0] = local_44[0] | 0x10;

      local_34 = local_5c;

      if ((param_1->coll_radius & 0x200) != 0) {

        uVar15 = 0x563;

        pOVar16 = param_1;

        sound_play_obj(0x563);

        iVar10 = PROJ_Create3(0x1c,param_1->ai_state_b,param_1,0,local_44,0,uVar15,pOVar16);

        *(OBJECT **)(iVar10 + 0x274) = param_1;

        return;

      }

      uVar15 = 0x569;

      pOVar16 = param_1;

      sound_play_obj(0x569);

      iVar12 = PROJ_Create3(0x1a,param_1->ai_state_b,param_1,0,local_44,0,uVar15,pOVar16);

      playerobj_eval_refpt(iVar10,0,local_50);

      ANM_BinderDestroy(local_50,1,0x4ac,0,0x3f666666,0x3f8ccccd,0x41000000,0x40800000,0x41700000,

                        0x442f0000,0x44098000);

      iVar10 = *(int *)(iVar10 + 0x274);

      *(uint *)(iVar10 + 0xd8) = *(uint *)(iVar10 + 0xd8) & 0xbfffffff;

      *(undefined4 *)(iVar10 + 0xec) = 0x3d4ccccd;

      *(uint *)(*(int *)(iVar10 + 0x274) + 0xd8) =

           *(uint *)(*(int *)(iVar10 + 0x274) + 0xd8) & 0xbfffffff;

      *(undefined4 *)(*(int *)(iVar10 + 0x274) + 0xec) = 0x3d4ccccd;

      *(OBJECT **)(iVar12 + 0x274) = param_1;

      return;

    }

    fVar13 = (float10)FRateGetSecsframe(param_1,0);

    piVar4[6] = (int)(float)((float10)(float)piVar4[6] - fVar13);

    if ((param_1->anim == param_2) && ((param_1->field_0x30 & 2) != 0)) {

      if (param_4 == 0.0) {

        fire_bullet_shot__FP6OBJECTT0ii(param_1,*piVar4,1,1);

      }

      if ((param_1->anim != param_3) && (*(int *)(param_1->class_ptr + 8 + param_3 * 4) != 0)) {

        ObjectSetAnim(param_1);

      }

      *(char *)(piVar4 + 9) = (char)piVar4[9] + -1;

    }

    if ((char)piVar4[9] != '\0') {

      return;

    }

    pcVar1 = (char *)((int)piVar4 + 0x25);

    *pcVar1 = *pcVar1 + -1;

    if ((*pcVar1 != '\0') && (*piVar4 != 0)) {

      if ((param_1->anim != param_3) && (*(int *)(param_1->class_ptr + 8 + param_3 * 4) != 0)) {

        ObjectSetAnim(param_1);

      }

      fVar13 = (float10)rndfloatrange(piVar4[0x23],piVar4[0x24]);

      piVar4[7] = (int)(float)fVar13;

      uVar9 = rndintrange(piVar4[0x1f],piVar4[0x20]);

      *(undefined1 *)(piVar4 + 9) = uVar9;

      fVar13 = (float10)rndfloatrange(piVar4[0x21],piVar4[0x22]);

      piVar4[6] = (int)(float)fVar13;

      return;

    }

    fVar13 = (float10)rndfloatrange(piVar4[0x25],piVar4[0x26]);

    piVar4[8] = (int)(float)fVar13;

    *(undefined1 *)((int)piVar4 + 0x25) = 0;

  }

  iVar10 = *(int *)&param_1->field_0xe8;

  if (iVar10 == 1) {

    param_1->pad_E4 = 0x6a;

    return;

  }

  if (iVar10 != 4) {

    if (iVar10 == 0x66) {

      if ((param_1->coll_radius & 0x80000) != 0) {

        piVar6 = (int *)param_1->animate_state;

        if (piVar6[0x7c] != 0) {

          *piVar6 = 0;

          param_4 = 640000.0;

          for (puVar7 = DAT_00632d80; puVar7 != (undefined4 *)0x0; puVar7 = (undefined4 *)*puVar7) {

            iVar10 = puVar7[3];

            if (*(int *)(iVar10 + 4) == 0x325) {

              fVar13 = (float10)distancesq2d__FP3P3DT0(iVar10 + 0xa0,&param_1->field_0xa0);

              if ((fVar13 < (float10)param_4) &&

                 (iVar12 = rpman_check_los__FP6OBJECTT0(param_1,iVar10), iVar12 != 0)) {

                *piVar6 = iVar10;

                param_4 = (float)fVar13;

              }

            }

          }

        }

        if (*piVar4 != 0) {

          param_1->pad_E4 = 0xd7;

          return;

        }

        param_1->coll_radius = param_1->coll_radius & 0xfff7ffff;

        param_1->pad_E4 = 0xda;

        return;

      }

      iVar10 = obj_is_pickup_4a(*piVar4);

      if ((iVar10 != 0) || (iVar10 = obj_is_pickup_53(*piVar4), iVar10 != 0)) {

        iVar10 = crt_rand_scaled(100);

        if ((iVar10 < piVar4[0x70]) &&

           ((iVar10 = obj_is_pickup_4a_model(*piVar4), iVar10 == 0 &&

            (iVar10 = obj_is_pickup_53_model(*piVar4), iVar10 == 0)))) {

          param_1->pad_E4 = 0xce;

          return;

        }

        ai_anim_play(param_1,param_3,1,0,0,0);

        param_1->pad_E4 = 0xd0;

        return;

      }

      if ((piVar4[0x6e] & 8U) != 0) {

        piVar4[0x6e] = piVar4[0x6e] & 0xfffffff7;

        rpman_sniper_anim_set(param_1);

        param_1->pad_E4 = 0xe2;

        return;

      }

    }

    else if (iVar10 == 0x67) {

      param_1->pad_E4 = 0xea;

      return;

    }

    param_1->pad_E4 = 0xc;

    return;

  }

  param_1->pad_E4 = 0xad;

  return;

}

/* ===== rpman_rapid_fire__FP6OBJECTiii @ 0x004E5F70 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* PS2 candidate: rpman_rapid_fire__FP6OBJECTiii (conf 0.463) */



void rpman_rapid_fire__FP6OBJECTiii(OBJECT *param_1,dword param_2,dword param_3)



{

  float fVar1;

  float fVar2;

  int *piVar3;

  int *piVar4;

  undefined4 *puVar5;

  bool bVar6;

  undefined1 uVar7;

  char cVar8;

  int iVar9;

  int iVar10;

  float10 fVar11;

  float10 fVar12;

  float fStack00000010;

  undefined4 uVar13;

  undefined4 local_18;

  undefined4 local_14;

  float local_10;

  undefined4 local_c;

  undefined4 local_8;

  float local_4;

  

  piVar3 = (int *)param_1->animate_state;

  bVar6 = false;

  if (*piVar3 != 0) {

    iVar9 = *piVar3 + 0xa0;

    if (*(int *)&param_1->field_0xe8 == 4) {

      fVar11 = (float10)dirfcalcp3d__FP3P3DT0(&param_1->field_0xa0,iVar9);

      fVar1 = (float)fVar11;

      fVar11 = (float10)playerobj_turn(fVar1,piVar3[0x56]);

      fVar2 = (float)fVar11;

      fVar11 = (float10)playerobj_turn(fVar1,*(undefined4 *)&param_1->field_0xc8);

      if (ABS(fVar11) != (float10)0.0) {

        param_1->flags = param_1->flags | 0x1000000;

        param_1->waypoint2 = (dword)fVar1;

        uVar7 = __ftol();

        param_1->field_0x208 = uVar7;

      }

      if ((fVar2 < *(float *)(&DAT_005a84e8 + piVar3[0x55] * 4)) ||

         (fVar2 < *(float *)(&DAT_005a8550 + piVar3[0x55] * 4) ==

          (fVar2 == *(float *)(&DAT_005a8550 + piVar3[0x55] * 4)))) {

        bVar6 = true;

      }

      else {

        bVar6 = false;

      }

    }

    else {

      fVar11 = (float10)dirfcalcp3d__FP3P3DT0(&param_1->field_0xa0,iVar9);

      fVar12 = (float10)playerobj_turn((float)fVar11,*(undefined4 *)&param_1->field_0xc8);

      if (ABS(fVar12) != (float10)0.0) {

        param_1->waypoint2 = (dword)(float)fVar11;

        param_1->flags = param_1->flags | 0x1000000;

        uVar7 = __ftol();

        param_1->field_0x208 = uVar7;

      }

    }

  }

  if (((float)piVar3[7] < 0.0 == ((float)piVar3[7] == 0.0)) || (bVar6)) {

    fVar11 = (float10)FRateGetSecsframe(param_1,0);

    piVar3[7] = (int)(float)((float10)(float)piVar3[7] - fVar11);

    if (!bVar6) {

      return;

    }

  }

  else {

    if (piVar3[0x8d] == 0) {

      iVar9 = sound_get_free_sequence__Fv();

      piVar3[0x8d] = iVar9;

    }

    if ((param_1->anim != param_2) && (*(int *)(param_1->class_ptr + 8 + param_2 * 4) != 0)) {

      ObjectSetAnim(param_1);

    }

    if ((float)piVar3[6] < 0.0 == ((float)piVar3[6] == 0.0)) {

      fVar11 = (float10)FRateGetSecsframe(param_1,0);

      piVar3[6] = (int)(float)((float10)(float)piVar3[6] - fVar11);

      fire_bullet_shot__FP6OBJECTT0ii(param_1,*piVar3,0,0);

    }

    else {

      fire_bullet_shot__FP6OBJECTT0ii(param_1,*piVar3,1);

      fVar11 = (float10)rndfloatrange(piVar3[0x21],piVar3[0x22]);

      piVar3[6] = (int)(float)fVar11;

      *(char *)(piVar3 + 9) = (char)piVar3[9] + -1;

    }

    if ((char)piVar3[9] != '\0') {

      return;

    }

    sound_stop_sequence(piVar3 + 0x8d);

    cVar8 = *(char *)((int)piVar3 + 0x25) + -1;

    *(char *)((int)piVar3 + 0x25) = cVar8;

    if ((cVar8 != '\0') && (*piVar3 != 0)) {

      if ((param_1->anim != param_3) && (*(int *)(param_1->class_ptr + 8 + param_3 * 4) != 0)) {

        ObjectSetAnim(param_1);

      }

      fVar11 = (float10)rndfloatrange(piVar3[0x23],piVar3[0x24]);

      piVar3[7] = (int)(float)fVar11;

      uVar7 = rndintrange(piVar3[0x1f],piVar3[0x20]);

      *(undefined1 *)(piVar3 + 9) = uVar7;

      fVar11 = (float10)rndfloatrange(piVar3[0x21],piVar3[0x22]);

      piVar3[6] = (int)(float)fVar11;

      return;

    }

    fVar11 = (float10)rndfloatrange(piVar3[0x25],piVar3[0x26]);

    piVar3[8] = (int)(float)fVar11;

    *(undefined1 *)((int)piVar3 + 0x25) = 0;

  }

  sound_stop_sequence(piVar3 + 0x8d);

  iVar9 = *(int *)&param_1->field_0xe8;

  if (iVar9 == 1) {

    param_1->pad_E4 = 0x6a;

    return;

  }

  if (iVar9 == 4) {

    param_1->pad_E4 = 0xad;

    return;

  }

  if (iVar9 != 0x66) {

    if (iVar9 == 0x67) {

      param_1->pad_E4 = 0xea;

      return;

    }

LAB_004e6651:

    param_1->pad_E4 = 0xc;

    return;

  }

  if ((param_1->coll_radius & 0x80000) != 0) {

    piVar4 = (int *)param_1->animate_state;

    if (piVar4[0x7c] != 0) {

      *piVar4 = 0;

      fStack00000010 = 640000.0;

      for (puVar5 = DAT_00632d80; puVar5 != (undefined4 *)0x0; puVar5 = (undefined4 *)*puVar5) {

        iVar9 = puVar5[3];

        if (*(int *)(iVar9 + 4) == 0x325) {

          fVar11 = (float10)distancesq2d__FP3P3DT0

                                      ((undefined4 *)(iVar9 + 0xa0),&param_1->field_0xa0);

          if (fVar11 < (float10)fStack00000010) {

            iVar10 = obj_is_pickup_4a(iVar9);

            if ((iVar10 == 0) && (iVar10 = obj_is_pickup_53(iVar9), iVar10 == 0)) {

              local_c = *(undefined4 *)&param_1->field_0xa0;

              local_8 = *(undefined4 *)&param_1->field_0xa4;

              local_4 = *(float *)&param_1->field_0x1e8 * *(float *)&param_1->field_0xc4 +

                        *(float *)&param_1->field_0xa8;

              local_18 = *(undefined4 *)(iVar9 + 0xa0);

              local_10 = *(float *)(iVar9 + 0x1e8) * *(float *)(iVar9 + 0xc4) +

                         *(float *)(iVar9 + 0xa8);

              local_14 = *(undefined4 *)(iVar9 + 0xa4);

              if (*(int *)&param_1->field_0x210 == 0) {

                uVar13 = 7;

              }

              else {

                _DAT_00561494 = *(undefined4 *)(*(int *)&param_1->field_0x210 + 4);

                uVar13 = 8;

              }

              iVar10 = ai_class_filter(&local_c,&local_18,uVar13,&DAT_00561478,0);

              if (iVar10 == 0) goto LAB_004e647b;

            }

            *piVar4 = iVar9;

            fStack00000010 = (float)fVar11;

          }

        }

LAB_004e647b:

      }

    }

    if (*piVar3 == 0) {

      param_1->coll_radius = param_1->coll_radius & 0xfff7ffff;

      param_1->pad_E4 = 0xda;

      return;

    }

    param_1->pad_E4 = 0xd7;

    return;

  }

  iVar9 = obj_is_pickup_4a(*piVar3);

  if ((iVar9 == 0) && (iVar9 = obj_is_pickup_53(*piVar3), iVar9 == 0)) {

    if ((piVar3[0x6e] & 8U) == 0) goto LAB_004e6651;

    piVar3[0x6e] = piVar3[0x6e] & 0xfffffff7;

    if ((param_1->coll_radius & 0x200) == 0) {

      if (param_1->anim == 0x47) goto LAB_004e6589;

      iVar9 = *(int *)(param_1->class_ptr + 0x124);

    }

    else {

      if (param_1->anim == 0x8e) goto LAB_004e6589;

      iVar9 = *(int *)(param_1->class_ptr + 0x240);

    }

    if (iVar9 != 0) {

      ObjectSetAnim(param_1);

    }

LAB_004e6589:

    param_1->pad_E4 = 0xe2;

    return;

  }

  iVar9 = crt_rand_scaled(100);

  if (iVar9 < piVar3[0x70]) {

    iVar9 = obj_is_pickup_4a_model(*piVar3);

    if ((iVar9 == 0) && (iVar9 = obj_is_pickup_53_model(*piVar3), iVar9 == 0)) {

      param_1->pad_E4 = 0xce;

      return;

    }

    if (param_1->anim == param_3) goto LAB_004e6616;

    iVar9 = *(int *)(param_1->class_ptr + 8 + param_3 * 4);

  }

  else {

    if (param_1->anim == param_3) goto LAB_004e6616;

    iVar9 = *(int *)(param_1->class_ptr + 8 + param_3 * 4);

  }

  if (iVar9 != 0) {

    ObjectSetAnim(param_1);

  }

LAB_004e6616:

  param_1->pad_E4 = 0xd0;

  return;

}

/* ===== rpman_target_scan @ 0x004E6670 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* PS2 candidate: rpman_target_scan (conf 0.7) */



void rpman_target_scan(OBJECT *param_1)



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

  

  piVar2 = (int *)param_1->animate_state;

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

    uVar6 = param_1->coll_radius | 2;

  }

  else {

    iVar4 = obj_is_pickup_4a(iVar5);

    if ((iVar4 == 0) && (iVar4 = obj_is_pickup_53(iVar5), iVar4 == 0)) {

      local_c = *(undefined4 *)&param_1->field_0xa0;

      local_8 = *(undefined4 *)&param_1->field_0xa4;

      local_4 = *(float *)&param_1->field_0x1e8 * *(float *)&param_1->field_0xc4 +

                *(float *)&param_1->field_0xa8;

      local_18 = *(undefined4 *)(iVar5 + 0xa0);

      local_14 = *(undefined4 *)(iVar5 + 0xa4);

      local_10 = *(float *)(iVar5 + 0x1e8) * *(float *)(iVar5 + 0xc4) + *(float *)(iVar5 + 0xa8);

      if (*(int *)&param_1->field_0x210 == 0) {

        uVar8 = 7;

      }

      else {

        _DAT_00561494 = *(undefined4 *)(*(int *)&param_1->field_0x210 + 4);

        uVar8 = 8;

      }

      iVar5 = ai_class_filter(&local_c,&local_18,uVar8,&DAT_00561478,0);

      if (iVar5 == 0) goto LAB_004e6792;

    }

    uVar6 = param_1->coll_radius & 0xfffffffd;

  }

  param_1->coll_radius = uVar6;

  if ((uVar6 & 2) == 0) {

    iVar5 = 0;

    for (puVar3 = DAT_00632d6c; puVar3 != (undefined4 *)0x0; puVar3 = (undefined4 *)*puVar3) {

      iVar4 = puVar3[3];

      if (((*(int *)(iVar4 + 4) == 0xd7) && (*(int *)(iVar4 + 0x210) == 0)) &&

         (fVar1 = *(float *)(DAT_00632ed8 + 0xc40),

         fVar7 = (float10)distancesq2d__FP3P3DT0(iVar4 + 0xa0,&param_1->field_0xa0),

         fVar7 < (float10)fVar1 * (float10)fVar1)) {

        iVar5 = iVar5 + 1;

      }

    }

    if ((float)iVar5 < *(float *)(DAT_00632ed8 + 0xc30)) {

      if ((param_1->anim != 0x71) && (*(int *)(param_1->class_ptr + 0x1cc) != 0)) {

        ObjectSetAnim(param_1);

      }

      param_1->pad_E4 = 0x7c;

    }

  }

  return;

}

/* ===== obj_proximity_update @ 0x004E6880 ===== */
void obj_proximity_update(OBJECT *param_1)



{

  dword dVar1;

  float fVar2;

  float10 fVar3;

  float10 fVar4;

  

  dVar1 = param_1->animate_state;

  if (param_1->anim == 0xa6) {

    if ((param_1->field_0x30 & 2) == 0) {

      fVar3 = (float10)ANM_SecsFromFrames(*(undefined4 *)

                                           (*(int *)(param_1->class_ptr + 0x2a0) + 0x28),0x96);

      fVar3 = (float10)1.0 - (float10)(float)param_1->pad_14 / fVar3;

      if (fVar3 < (float10)0.0) {

        fVar3 = (float10)0.0;

      }

      *(float *)(dVar1 + 0x188) = (float)(fVar3 * (float10)*(float *)(dVar1 + 0x19c));

      return;

    }

    if (*(int *)(param_1->class_ptr + 0x270) == 0) {

      return;

    }

    ObjectSetAnim(param_1);

    return;

  }

  fVar3 = (float10)distancesq2d__FP3P3DT0(&param_1->field_0xa0,*(int *)(dVar1 + 400) + 0xa0);

  fVar4 = (float10)distancesq2d__FP3P3DT0(DAT_00632a88 + 0xa0,*(int *)(dVar1 + 400) + 0xa0);

  if (*(int *)(dVar1 + 0x184) == 0) {

    if ((float)fVar3 <=

        (float)fVar4 - *(float *)(DAT_00632ed8 + 0xfc8) * *(float *)(DAT_00632ed8 + 0xfc8)) {

LAB_004e6a31:

      fVar2 = SQRT((float)fVar3) - SQRT((float)fVar4);

      if (0.0 < fVar2) {

        if (fVar2 <= *(float *)(DAT_00632ed8 + 0xfcc)) {

          *(undefined4 *)(dVar1 + 0x18c) = *(undefined4 *)(DAT_00632ed8 + 0xfd0);

        }

        else {

          *(undefined4 *)(dVar1 + 0x18c) = *(undefined4 *)(DAT_00632ed8 + 0xfd4);

        }

      }

      goto LAB_004e6af2;

    }

  }

  else if (*(int *)(dVar1 + 0x184) < 1) goto LAB_004e6a31;

  if (*(float *)(dVar1 + 0x1a0) < 0.0 == (*(float *)(dVar1 + 0x1a0) == 0.0)) {

    fVar3 = (float10)FRateGetSecsframe(param_1,0);

    fVar3 = (float10)*(float *)(dVar1 + 0x1a0) - fVar3;

    *(float *)(dVar1 + 0x1a0) = (float)fVar3;

    if (fVar3 < (float10)0.0 != (fVar3 == (float10)0.0)) {

      fVar3 = (float10)rndfloatrange(*(undefined4 *)(DAT_00632ed8 + 0x3f4),

                                     *(undefined4 *)(DAT_00632ed8 + 0xfc4));

      *(float *)(dVar1 + 0x18c) = (float)fVar3;

      fVar3 = (float10)rndfloatrange(*(undefined4 *)(DAT_00632ed8 + 0x294),

                                     *(undefined4 *)(DAT_00632ed8 + 0x298));

      *(float *)(dVar1 + 0x1a4) = (float)fVar3;

    }

  }

  else {

    fVar3 = (float10)FRateGetSecsframe(param_1,0);

    fVar3 = (float10)*(float *)(dVar1 + 0x1a4) - fVar3;

    *(float *)(dVar1 + 0x1a4) = (float)fVar3;

    if (fVar3 < (float10)0.0 != (fVar3 == (float10)0.0)) {

      fVar3 = (float10)rndfloatrange(*(undefined4 *)(DAT_00632ed8 + 0x29c),

                                     *(undefined4 *)(DAT_00632ed8 + 0x2a0));

      *(float *)(dVar1 + 0x18c) = (float)fVar3;

      fVar3 = (float10)rndfloatrange(*(undefined4 *)(DAT_00632ed8 + 0x28c),

                                     *(undefined4 *)(DAT_00632ed8 + 0x290));

      *(float *)(dVar1 + 0x1a0) = (float)fVar3;

    }

  }

LAB_004e6af2:

  if (*(float *)(dVar1 + 0x188) <= *(float *)(dVar1 + 0x18c)) {

    if (*(float *)(dVar1 + 0x188) < *(float *)(dVar1 + 0x18c)) {

      fVar3 = (float10)FRateGetSecsframe(param_1,0);

      fVar3 = fVar3 * (float10)*(float *)(DAT_00632ed8 + 0xfd8) + (float10)*(float *)(dVar1 + 0x188)

      ;

      *(float *)(dVar1 + 0x188) = (float)fVar3;

      if ((float10)*(float *)(dVar1 + 0x18c) < fVar3) {

        *(undefined4 *)(dVar1 + 0x188) = *(undefined4 *)(dVar1 + 0x18c);

      }

    }

  }

  else {

    fVar3 = (float10)FRateGetSecsframe(param_1,0);

    fVar3 = (float10)*(float *)(dVar1 + 0x188) - fVar3 * (float10)*(float *)(DAT_00632ed8 + 0xfd8);

    *(float *)(dVar1 + 0x188) = (float)fVar3;

    if (fVar3 < (float10)*(float *)(dVar1 + 0x18c)) {

      *(undefined4 *)(dVar1 + 0x188) = *(undefined4 *)(dVar1 + 0x18c);

      return;

    }

  }

  return;

}

/* ===== rpboat_logic__FP6OBJECT @ 0x004E6BA0 ===== */
/* PS2 candidate: rpboat_logic__FP6OBJECT (conf 0.534) */



void rpboat_logic__FP6OBJECT(OBJECT *param_1,float param_2)



{

  undefined1 *puVar1;

  float *pfVar2;

  float fVar3;

  dword dVar4;

  dword dVar5;

  OBJECT *obj;

  int iVar6;

  undefined4 uVar7;

  float10 fVar8;

  float10 fVar9;

  float10 fVar10;

  undefined1 local_5c [12];

  undefined1 local_50 [16];

  float local_40;

  undefined4 local_30;

  undefined4 local_2c;

  undefined4 local_28;

  

  obj = param_1;

  dVar4 = param_1->animate_state;

  uVar7 = *(undefined4 *)(dVar4 + 0x13c);

  fVar8 = (float10)FRateGetSecsframe(param_1,0);

  fVar8 = fVar8 * (float10)param_2 + (float10)*(float *)(dVar4 + 0x13c);

  puVar1 = &param_1->field_0xa0;

  *(float *)(dVar4 + 0x13c) = (float)fVar8;

  ai_move_ground_common(*(undefined4 *)(dVar4 + 0x134),(float)fVar8,uVar7,puVar1);

  ground_height_at(puVar1,local_50);

  if (*(int *)(*(int *)(*(int *)(dVar4 + 0x134) + 0x100) + 0x48) == 0) {

    if (local_40 <= 0.0) {

      *(undefined4 *)&param_1->field_0xa8 = 0;

    }

    else {

      *(float *)&param_1->field_0xa8 = local_40;

    }

  }

  else if (*(float *)&param_1->field_0xa8 < local_40) {

    *(float *)&param_1->field_0xa8 = local_40;

  }

  param_1 = (OBJECT *)0x0;

  if (0.0 < param_2) {

    if ((*(float *)&obj->field_0xb8 != *(float *)puVar1) ||

       (*(float *)&obj->field_0xbc != *(float *)&obj->field_0xa4)) {

      fVar8 = (float10)dirfcalcp3d__FP3P3DT0(&obj->field_0xb8,puVar1);

      fVar3 = (float)fVar8;

      fVar8 = (float10)playerobj_turn(fVar3,*(undefined4 *)&obj->field_0xf4);

      param_1 = (OBJECT *)(float)fVar8;

      *(float *)&obj->field_0xc8 = fVar3;

      *(float *)&obj->field_0xf4 = fVar3;

    }

    fVar8 = (float10)FRateGetSecsframe(obj,0);

    fVar8 = (float10)*(float *)(dVar4 + 0x23c) - fVar8;

    *(float *)(dVar4 + 0x23c) = (float)fVar8;

    if (fVar8 < (float10)0.0) {

      iVar6 = crt_rand_scaled(100);

      if (iVar6 < 0x32) {

        iVar6 = 0x61d;

      }

      else {

        iVar6 = 0x61e;

      }

      sound_play_obj(iVar6);

      fVar8 = (float10)rndfloatrange(0x41200000,0x41a00000);

      *(float *)(dVar4 + 0x23c) = (float)fVar8;

    }

  }

  fVar8 = (float10)FRateGetSecsframe(obj,0);

  *(undefined4 *)(obj->pad_104 + 0x28) = *(undefined4 *)(DAT_00632ed8 + 0xd50);

  if (fVar8 <= (float10)0.0001) {

    obj->pad_128 = 0;

    *(undefined4 *)&obj->field_0x12c = 0;

    obj->loc_accum0 = 0;

    *(undefined4 *)(obj->pad_104 + 0x24) = 0;

  }

  else {

    fVar8 = (float10)1.0 / fVar8;

    fVar9 = ((float10)*(float *)puVar1 - (float10)*(float *)&obj->field_0xac) * fVar8;

    obj->pad_128 = (dword)(float)fVar9;

    fVar10 = ((float10)*(float *)&obj->field_0xa4 - (float10)*(float *)&obj->field_0xb0) * fVar8;

    *(float *)&obj->field_0x12c = (float)fVar10;

    fVar8 = ((float10)*(float *)&obj->field_0xa8 - (float10)*(float *)&obj->field_0xb4) * fVar8;

    obj->loc_accum0 = (dword)(float)fVar8;

    fVar3 = (float)(fVar9 * fVar9 + fVar10 * fVar10 + fVar8 * fVar8);

    if (fVar3 == 0.0) {

      *(undefined4 *)(obj->pad_104 + 0x24) = 0;

    }

    else {

      *(uint *)(obj->pad_104 + 0x24) =

           (&DAT_005f0a18)[(uint)fVar3 >> 8 & 0xffff] |

           ((int)fVar3 + 0xc0800000U >> 1) + 0x3f800000 & 0x7f800000;

    }

  }

  ObjectCalculateTransform(obj);

  dVar5 = obj->animate_state;

  obj->flags = obj->flags | 0x20;

  *(undefined4 *)(dVar5 + 0x16c) = 0;

  *(undefined4 *)(dVar5 + 0x170) = 0;

  if (*(float *)&obj->field_0xa8 < 0.0 == (*(float *)&obj->field_0xa8 == 0.0)) {

    if (local_40 < *(float *)&obj->field_0xa8) {

      *(undefined4 *)(dVar5 + 0x174) = 0;

      if ((float)obj->loc_accum0 <= *(float *)(DAT_00632ed8 + 0xf10)) {

        *(float *)(dVar5 + 0x16c) = -*(float *)(DAT_00632ed8 + 0xf14);

      }

      else {

        *(undefined4 *)(dVar5 + 0x16c) = *(undefined4 *)(dVar5 + 0x164);

      }

    }

    else if (*(float *)(dVar5 + 0x174) < 0.0 == (*(float *)(dVar5 + 0x174) == 0.0)) {

      fVar8 = (float10)FRateGetSecsframe(0,0);

      *(float *)(dVar5 + 0x174) = (float)((float10)*(float *)(dVar5 + 0x174) - fVar8);

    }

    else {

      local_30 = *(undefined4 *)puVar1;

      local_2c = *(undefined4 *)&obj->field_0xa4;

      local_28 = *(undefined4 *)&obj->field_0xa8;

      fx_get_free_effect__Fv();

      *(undefined4 *)(dVar5 + 0x174) = 0x3e4ccccd;

    }

  }

  else {

    *(float *)(dVar5 + 0x170) = -(*(float *)(DAT_00632ed8 + 0xd90) * (float)param_1);

  }

  if (*(float *)(dVar5 + 0x170) <= *(float *)(DAT_00632ed8 + 0xd90)) {

    fVar3 = -*(float *)(DAT_00632ed8 + 0xd90);

    if (*(float *)(dVar5 + 0x170) < fVar3) {

      *(float *)(dVar5 + 0x170) = fVar3;

    }

  }

  else {

    *(float *)(dVar5 + 0x170) = *(float *)(DAT_00632ed8 + 0xd90);

  }

  fVar8 = (float10)FRateGetSecsframe(obj,0,0x461c4000,*(undefined4 *)(dVar5 + 0x16c),

                                     (float *)(dVar5 + 0x164));

  chase_angle((float)(fVar8 * (float10)*(float *)(DAT_00632ed8 + 0xe04)));

  pfVar2 = (float *)(dVar5 + 0x168);

  fVar8 = (float10)FRateGetSecsframe(obj,0,0x461c4000,*(undefined4 *)(dVar5 + 0x170),pfVar2);

  chase_angle((float)(fVar8 * (float10)*(float *)(DAT_00632ed8 + 0xe00)));

  GEO_MatBuildXYZ(&obj->field_0x294,-*(float *)(dVar5 + 0x164),*pfVar2,

                  *(undefined4 *)&obj->field_0xc8);

  ANM_DumpCluster(obj,dVar5 + 0x178);

  if ((*pfVar2 < -10.0) || (10.0 < *pfVar2)) {

    if (*(int *)(dVar5 + 0x238) == 0) {

      sound_play_obj(0x62e);

      *(undefined4 *)(dVar5 + 0x238) = 1;

    }

  }

  else if (*(int *)(dVar5 + 0x238) != 0) {

    sound_stop_obj(0x62e,obj);

    *(undefined4 *)(dVar5 + 0x238) = 0;

  }

  FRateGetSecsframe(obj,0);

  object_animate_process(obj);

  obj->flags = obj->flags | 0x40;

  if (((*(int *)(dVar4 + 0x194) != 0) &&

      (iVar6 = obj_face_target(*(int *)(dVar4 + 0x194),obj,local_5c), iVar6 != 0)) &&

     (iVar6 = point_between_pair_test(*(undefined4 *)(dVar4 + 0x194),local_5c), iVar6 != 0)) {

    *(int *)(dVar4 + 0x184) = *(int *)(dVar4 + 0x184) + 1;

    if (*(int *)(*(int *)(dVar4 + 0x194) + 0x174) == 0) {

      *(int *)(dVar4 + 0x198) = *(int *)(dVar4 + 0x198) + 1;

    }

    uVar7 = buoy_set_lights(*(int *)(dVar4 + 0x194),0);

    *(undefined4 *)(dVar4 + 0x194) = uVar7;

  }

  if (*(int *)(dVar4 + 0x198) != 5) {

    return;

  }

  if ((DAT_00632c00 == 0) && (DAT_00632c04 == 0)) {

    sound_play_player(0x6ce,DAT_00632a88);

  }

  voice_quota_check();

  return;

}

/* ===== anim_flagid_select @ 0x004E7160 ===== */
void anim_flagid_select(OBJECT *param_1,int param_2)



{

  float fVar1;

  dword dVar2;

  int iVar3;

  

  dVar2 = param_1->animate_state;

  if (param_2 != 0) {

    param_1->orders_head = *(dword *)(dVar2 + 0x1ac);

    return;

  }

  if ((param_1->coll_radius & 0x200) == 0) {

    if ((param_1->coll_radius & 0x100) == 0) {

      if (param_1->anim == 0x52) goto LAB_004e723e;

      iVar3 = *(int *)(param_1->class_ptr + 0x150);

    }

    else {

      if (param_1->anim == 0x9c) goto LAB_004e723e;

      iVar3 = *(int *)(param_1->class_ptr + 0x278);

    }

  }

  else {

    if (param_1->anim == 0x91) goto LAB_004e723e;

    iVar3 = *(int *)(param_1->class_ptr + 0x24c);

  }

  if (iVar3 != 0) {

    ObjectSetAnim(param_1);

  }

LAB_004e723e:

  fVar1 = *(float *)(dVar2 + 0x1ac);

  param_1->orders_head = (dword)(fVar1 + fVar1);

  return;

}

/* ===== gridcell_free_check_store @ 0x004E7250 ===== */
undefined4 gridcell_free_check_store(int param_1)



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

/* ===== seq_dep_release @ 0x004E7330 ===== */
void seq_dep_release(int param_1,int param_2)



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



void rpman_army_goto_firepit__FP6OBJECT(OBJECT *param_1)



{

  int *piVar1;

  int iVar2;

  uint uVar3;

  float10 fVar4;

  float10 fVar5;

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

  param_1->anim_selector = (dword)&LAB_004cb930;

  ai_moveonly_set_goal(param_1,&local_c);

  iVar2 = crt_rand_scaled(100);

  if (iVar2 < 0x32) {

    uVar3 = param_1->coll_radius | 0x10000;

  }

  else {

    uVar3 = param_1->coll_radius & 0xfffeffff;

  }

  param_1->coll_radius = uVar3;

  if ((uVar3 & 0x200) == 0) {

    if (param_1->anim == 0x47) goto LAB_004e75b4;

    iVar2 = *(int *)(param_1->class_ptr + 0x124);

  }

  else {

    if (param_1->anim == 0x8e) goto LAB_004e75b4;

    iVar2 = *(int *)(param_1->class_ptr + 0x240);

  }

  if (iVar2 != 0) {

    ObjectSetAnim(param_1);

  }

LAB_004e75b4:

  param_1->pad_E4 = 0xdf;

  return;

}

/* ===== ret_const_x240_c51 @ 0x004E75D0 ===== */
undefined4 ret_const_x240_c51(void)



{

  return 0x240;

}

/* ===== rpman_ptr_clear_c51 @ 0x004E75E0 ===== */
void rpman_ptr_clear_c51(int param_1)



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

/* ===== tracked_node_free_c52 @ 0x004E7680 ===== */
void tracked_node_free_c52(int param_1)



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

/* ===== water_fx_free_c51 @ 0x004E76A0 ===== */
void water_fx_free_c51(int param_1)



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



void rpman_notify_hit(OBJECT *param_1,int param_2)



{

  float fVar1;

  int *piVar2;

  undefined4 uVar3;

  OBJECT *pOVar4;

  int *piVar5;

  dword dVar6;

  dword dVar7;

  uint uVar8;

  undefined4 *puVar9;

  int iVar10;

  int *piVar11;

  undefined1 *puVar12;

  float *pfVar13;

  int iVar14;

  float10 fVar15;

  

  pOVar4 = param_1;

  piVar2 = (int *)param_1->animate_state;

  if (param_1->pad_E4 == 0) {

    return;

  }

  if ((((param_2 != 0) && (*(int *)(param_2 + 0x1e0) == 0x4d)) && (*(int *)(param_2 + 0x274) != 0))

     && (*(dword *)(*(int *)(param_2 + 0x274) + 0x18c) == param_1->ai_state_b)) {

    return;

  }

  if (*(int *)&param_1->field_0xe8 != 0x66) {

    if (*piVar2 != 0) {

      return;

    }

    fVar15 = (float10)distancesq3d(DAT_00632a88 + 0xa0,&param_1->field_0xa0);

    fVar1 = (float)fVar15;

    puVar9 = DAT_00632d6c;

    do {

      if (puVar9 == (undefined4 *)0x0) {

        if ((piVar2[0x1b] != 0) && (*(int *)(piVar2[0x1b] + 0xe4) != 0x65)) {

          fVar15 = (float10)rndfloatrange(0x40400000,0x41700000);

          *(float *)(piVar2[0x1b] + 0xf0) = (float)fVar15;

          *(undefined4 *)(piVar2[0x1b] + 0xe4) = 0x65;

        }

        if (piVar2[0x4d] == 0) {

          return;

        }

        *(undefined4 *)(piVar2[0x4d] + 0xe4) = 3;

        return;

      }

      pOVar4 = (OBJECT *)puVar9[3];

      dVar6 = pOVar4->animate_state;

      if (((((pOVar4->type_id == 0xd7) &&

            (*(float *)&pOVar4->field_0x278 < *(float *)&pOVar4->field_0x1c0)) &&

           ((dVar7 = pOVar4->pad_E4, dVar7 == 0xb || ((0x1d < (int)dVar7 && ((int)dVar7 < 0x23))))))

          && ((iVar14 = *(int *)&pOVar4->field_0xe8, iVar14 != 9 &&

              (((iVar14 != 1 && (dVar7 != 0x12d)) && (iVar14 != 0x66)))))) &&

         ((iVar14 = *(int *)(dVar6 + 0x134), iVar14 == piVar2[0x4d] ||

          (((iVar14 == 0 || (*(int *)(iVar14 + 0x1e0) != 0x61)) &&

           (fVar15 = (float10)distancesq2d__FP3P3DT0(&param_1->field_0xa0,&pOVar4->field_0xa0),

           fVar15 < (float10)625.0)))))) {

        rpman_find_hide_spot__FP6OBJECTi(pOVar4,0);

        iVar14 = *(int *)(dVar6 + 0x44);

        piVar2[10] = *(int *)&pOVar4->field_0xa0;

        piVar2[0xb] = *(int *)&pOVar4->field_0xa4;

        piVar2[0xc] = *(int *)&pOVar4->field_0xa8;

        uVar8 = pOVar4->coll_radius;

        if (iVar14 == 0) {

          if ((uVar8 & 0x200) == 0) {

            pOVar4->coll_radius = uVar8 | 0x8004000;

            iVar14 = crt_rand_scaled(100);

            if (iVar14 < 0x33) {

              pOVar4->coll_radius = pOVar4->coll_radius | 0x8000;

              if (pOVar4->anim != 0x7f) {

                iVar14 = *(int *)(pOVar4->class_ptr + 0x204);

                goto joined_r0x004e82c5;

              }

            }

            else {

              pOVar4->coll_radius = pOVar4->coll_radius & 0xffff7fff;

              if (pOVar4->anim != 0x7e) {

                iVar14 = *(int *)(pOVar4->class_ptr + 0x200);

joined_r0x004e82c5:

                if (iVar14 != 0) {

                  ObjectSetAnim(pOVar4);

                }

              }

            }

          }

          else {

            ai_damage_response(pOVar4,1,0,0);

          }

          pOVar4->pad_E4 = 0x51;

        }

        else {

          if ((uVar8 & 0x200) == 0) {

            if (pOVar4->anim != 0x47) {

              iVar14 = *(int *)(pOVar4->class_ptr + 0x124);

              goto joined_r0x004e81f7;

            }

          }

          else if (pOVar4->anim != 0x8e) {

            iVar14 = *(int *)(pOVar4->class_ptr + 0x240);

joined_r0x004e81f7:

            if (iVar14 != 0) {

              ObjectSetAnim(pOVar4);

            }

          }

          pOVar4->pad_E4 = 0x50;

        }

        fVar15 = (float10)rndfloatrange(*(undefined4 *)(DAT_00632ed8 + 0xbd4),

                                        *(undefined4 *)(DAT_00632ed8 + 0xbd8));

        *(float *)(dVar6 + 0xd0) = (float)fVar15;

        iVar14 = DAT_00632a88;

        *(undefined4 *)(dVar6 + 0xc4) = *(undefined4 *)(DAT_00632a88 + 0xa0);

        *(undefined4 *)(dVar6 + 200) = *(undefined4 *)(iVar14 + 0xa4);

        *(undefined4 *)(dVar6 + 0xcc) = *(undefined4 *)(iVar14 + 0xa8);

        *(undefined4 *)(dVar6 + 8) = *(undefined4 *)&pOVar4->field_0xa0;

        *(undefined4 *)(dVar6 + 0xc) = *(undefined4 *)&pOVar4->field_0xa4;

        *(undefined4 *)(dVar6 + 0x10) = *(undefined4 *)&pOVar4->field_0xa8;

        *(undefined4 *)(dVar6 + 0x14) = *(undefined4 *)&pOVar4->field_0xc8;

        if (fVar1 <= *(float *)(dVar6 + 0xa4)) {

          if (*(float *)(dVar6 + 0xa8) < fVar1) {

            *(float *)(dVar6 + 0xa8) = fVar1 + 2500.0;

          }

        }

        else {

          *(float *)(dVar6 + 0xa4) = fVar1 + 2500.0;

        }

        *(float *)(dVar6 + 0x160) = fVar1 + 2500.0;

      }

      puVar9 = (undefined4 *)*puVar9;

    } while( true );

  }

  if ((param_2 != 0) && (*(int *)(param_2 + 4) == 0x325)) {

    puVar12 = &param_1->field_0xa0;

    iVar14 = 0;

    if (DAT_005a8588 == 0) {

LAB_004e7bdc:

      iVar10 = iVar14;

      DAT_005a8588 = DAT_005a8588 + 1;

    }

    else {

      param_1 = (OBJECT *)0x43968000;

      iVar10 = 0x43968000;

      pfVar13 = (float *)&DAT_005a850c;

      do {

        if (*pfVar13 < 0.0 != (*pfVar13 == 0.0)) {

          if (iVar14 < 5) goto LAB_004e7bdc;

          break;

        }

        fVar15 = (float10)distancesq2d__FP3P3DT0(puVar12,pfVar13 + -3);

        if (fVar15 < (float10)2500.0 != (fVar15 == (float10)2500.0)) {

          (&DAT_005a850c)[iVar14 * 4] = 0x43960000;

          return;

        }

        if (*pfVar13 < (float)param_1) {

          param_1 = (OBJECT *)*pfVar13;

          iVar10 = iVar14;

        }

        pfVar13 = pfVar13 + 4;

        iVar14 = iVar14 + 1;

      } while ((int)pfVar13 < 0x5a855c);

    }

    (&DAT_005a8500)[iVar10 * 4] = *(undefined4 *)puVar12;

    (&DAT_005a8504)[iVar10 * 4] = *(undefined4 *)&pOVar4->field_0xa4;

    uVar3 = *(undefined4 *)&pOVar4->field_0xa8;

    (&DAT_005a850c)[iVar10 * 4] = 0x43960000;

    (&DAT_005a8508)[iVar10 * 4] = uVar3;

    return;

  }

  if (*piVar2 == 0) {

    iVar14 = crt_rand_scaled(100);

    if (iVar14 < piVar2[0x71]) {

      rpman_scan_for_enemy__FP6OBJECTfii(param_1,piVar2[0x2b],1,0);

    }

    if (*piVar2 != 0) goto LAB_004e7ce8;

    rpman_scan_for_enemy__FP6OBJECTfii(param_1,piVar2[0x2b],0,1);

  }

  else {

    iVar14 = obj_is_pickup_4a(*piVar2);

    if (((iVar14 != 0) || (iVar14 = obj_is_pickup_53(*piVar2), iVar14 != 0)) &&

       (iVar14 = ObjIsTurret(*piVar2), iVar14 == 0)) {

      iVar14 = *piVar2;

      *piVar2 = 0;

      *(undefined4 *)&param_1->field_0xe8 = 2;

      iVar10 = crt_rand_scaled(100);

      if (iVar10 < piVar2[0x71]) {

        rpman_scan_for_enemy__FP6OBJECTfii(param_1,piVar2[0x2b],1,0);

      }

      *(undefined4 *)&param_1->field_0xe8 = 0x66;

      if (*piVar2 == 0) {

        *piVar2 = iVar14;

        return;

      }

      goto LAB_004e7ce8;

    }

  }

  if (*piVar2 == 0) {

    return;

  }

LAB_004e7ce8:

  crt_rand_scaled(100);

  if ((((param_1->coll_radius & 0x3000000) == 0) && (piVar2[0x8a] == 0)) && (param_1->pad_E4 != 200)

     ) {

    if (piVar2[0x4d] != 0) {

      *(undefined4 *)(piVar2[0x4d] + 0xe4) = 3;

    }

    iVar14 = obj_is_pickup_4a(*piVar2);

    if (((iVar14 == 0) && (iVar14 = obj_is_pickup_53(*piVar2), iVar14 == 0)) ||

       (*(int *)&param_1->field_0xe8 != 0x66)) {

      param_1->coll_radius = param_1->coll_radius | 0x40000000;

      param_1->pad_E4 = 0xc;

    }

    else {

      param_1->pad_E4 = 0xcd;

    }

  }

  piVar11 = DAT_00632d68;

  if (DAT_00632d68 == (int *)0x0) {

    return;

  }

  do {

    pOVar4 = (OBJECT *)piVar11[3];

    if (pOVar4->type_id == 0xd7) {

      if (((pOVar4->pad_E4 != 0) &&

          (*(float *)&pOVar4->field_0x278 < *(float *)&pOVar4->field_0x1c0)) &&

         ((((*(int *)&pOVar4->field_0xe8 == 0x66 &&

            (((param_1->coll_radius & 0x3000000) == 0 && ((pOVar4->coll_radius & 0x1000000) == 0))))

           && (piVar5 = (int *)pOVar4->animate_state, piVar5[0x8a] == 0)) &&

          ((pOVar4->pad_E4 != 0x12d && (piVar5[0x4d] == piVar2[0x4d])))))) {

        piVar5[0x6e] = piVar5[0x6e] | 1;

        *(undefined4 *)(*(int *)(piVar5[0x4d] + 0x100) + 0x10) = 1;

        if ((pOVar4->pad_E4 != 200) && (pOVar4 != param_1)) {

          iVar14 = crt_rand_scaled(100);

          if (iVar14 < piVar5[0x72]) {

            *piVar5 = *piVar2;

            if ((pOVar4->coll_radius & 0x200) == 0) {

              if (pOVar4->anim != 0x47) {

                iVar14 = *(int *)(pOVar4->class_ptr + 0x124);

                goto joined_r0x004e7ec4;

              }

            }

            else if (pOVar4->anim != 0x8e) {

              iVar14 = *(int *)(pOVar4->class_ptr + 0x240);

joined_r0x004e7ec4:

              if (iVar14 != 0) {

                ObjectSetAnim(pOVar4);

              }

            }

            iVar14 = obj_is_pickup_4a(*piVar2);

            if (iVar14 == 0) {

              iVar14 = *piVar2;

LAB_004e7fcb:

              iVar14 = obj_is_pickup_53(iVar14);

              if (iVar14 != 0) goto LAB_004e7fd7;

            }

            else {

LAB_004e7fd7:

              if (*(int *)&param_1->field_0xe8 == 0x66) {

                pOVar4->pad_E4 = 0xcd;

                goto LAB_004e8053;

              }

            }

            iVar14 = crt_rand_scaled(100);

            if (iVar14 < 0x32) {

              param_1->coll_radius = param_1->coll_radius | 0x40000000;

            }

            pOVar4->pad_E4 = 0xc;

          }

          else if (*piVar5 == 0) {

            rpman_scan_for_enemy__FP6OBJECTfii(pOVar4,piVar2[0x2b],0,1);

            if (*piVar5 == 0) {

              *piVar5 = *piVar2;

            }

            else if ((pOVar4->coll_radius & 0x200) == 0) {

              if (pOVar4->anim != 0x47) {

                iVar14 = *(int *)(pOVar4->class_ptr + 0x124);

                goto joined_r0x004e7f8b;

              }

            }

            else if (pOVar4->anim != 0x8e) {

              iVar14 = *(int *)(pOVar4->class_ptr + 0x240);

joined_r0x004e7f8b:

              if (iVar14 != 0) {

                ObjectSetAnim(pOVar4);

              }

            }

            iVar14 = obj_is_pickup_4a(*piVar2);

            if (iVar14 == 0) {

              iVar14 = *piVar2;

              goto LAB_004e7fcb;

            }

            goto LAB_004e7fd7;

          }

        }

      }

    }

    else {

      iVar14 = piVar2[0x7c];

      if ((((iVar14 != 0) && (pOVar4->type_id == 0x48a)) &&

          (*(int *)&pOVar4->field_0xe8 == *(int *)(iVar14 + 0xe8))) &&

         (*(int *)&pOVar4->field_0x174 == *(int *)(iVar14 + 0x174) + -1)) {

        *(undefined4 *)&pOVar4->field_0xf8 = 0;

      }

    }

LAB_004e8053:

    piVar11 = (int *)*piVar11;

    if (piVar11 == (int *)0x0) {

      return;

    }

  } while( true );

}

/* ===== death_handler_c51 @ 0x004E8410 ===== */
void death_handler_c51(float param_1,float param_2,OBJECT *param_3,float param_4,int param_5)



{

  float fVar1;

  int *piVar2;

  dword dVar3;

  OBJECT *pOVar4;

  uint uVar5;

  float fVar6;

  undefined4 *puVar7;

  OBJECT *obj;

  int iVar8;

  undefined4 uVar9;

  dword dVar10;

  int *piVar11;

  int iVar12;

  int *piVar13;

  float10 fVar14;

  float fStack_40;

  float fStack_3c;

  float fStack_38;

  undefined4 uStack_30;

  undefined4 uStack_2c;

  undefined4 uStack_28;

  

  obj = param_3;

  fVar1 = param_1;

  dVar10 = param_3->pad_E4;

  piVar13 = (int *)param_3->animate_state;

  if ((dVar10 == 0) || (dVar10 == 0xdd)) {

    return;

  }

  if (*(int *)&param_3->field_0xe8 == 0xb) {

    if (param_3->anim == 0xa6) {

      return;

    }

    if (*(int *)(param_3->class_ptr + 0x2a0) != 0) {

      ObjectSetAnim(param_3);

    }

    piVar13[0x67] = piVar13[0x62];

    sound_play_obj(0x6d7);

    return;

  }

  if ((param_4 != 0.0) && (*(OBJECT **)((int)param_4 + 0x274) == param_3)) {

    return;

  }

  if (499 < (int)dVar10) {

    fVar1 = param_2 + *(float *)&param_3->field_0x278;

    *(float *)&param_3->field_0x278 = fVar1;

    if (fVar1 < *(float *)(DAT_00632ed8 + 0xc50) + *(float *)&param_3->field_0x1c0) {

      return;

    }

    rpman_gib__FP6OBJECTT0(param_3,param_4);

    return;

  }

  if (dVar10 == 0x3c) {

    *(uint *)&param_3->field_0x1c8 = *(uint *)&param_3->field_0x1c8 & 0xfffffbff;

  }

  if (((((param_4 == 0.0) || (*(int *)((int)param_4 + 0x274) == 0)) ||

       (*(dword *)(*(int *)((int)param_4 + 0x274) + 0x18c) != param_3->ai_state_b)) &&

      ((dVar10 != 0x12d && (dVar10 != 0x23)))) &&

     ((*piVar13 == 0 ||

      (((param_1 != 2.10195e-44 && (param_1 != 1.82169e-44)) &&

       ((param_1 != 1.96182e-44 && (param_1 != 1.4013e-45)))))))) {

    if (*(float *)&param_3->field_0x278 < *(float *)&param_3->field_0x1c0) {

      rpman_notify_hit(param_3,param_4);

    }

    ai_d7_pairing(obj,0x41c80000);

    *(undefined4 *)&obj->field_0xec = 0;

  }

  iVar8 = param_5;

  iVar12 = piVar13[0x54];

  if (((iVar12 != 0) &&

      (((dVar10 = obj->pad_E4, dVar10 == 0xad || (dVar10 == 0xae)) || (dVar10 == 0x28)))) &&

     ((0x30 < (int)fVar1 && ((int)fVar1 < 0x45)))) {

    if (param_5 == 0) {

      return;

    }

    fVar6 = *(float *)(iVar12 + 0xa8) + 11.0;

    if (fVar6 < *(float *)(param_5 + 8) != (fVar6 == *(float *)(param_5 + 8))) {

      return;

    }

    fVar14 = (float10)distancesq2d__FP3P3DT0(iVar12 + 0xa0,param_5);

    if ((float10)324.0 <= fVar14) {

      return;

    }

  }

  param_5 = 0;

  fVar6 = param_2;

  if (((iVar8 != 0) && (((int)fVar1 < 0x31 || (0x44 < (int)fVar1)))) &&

     (param_5 = death_pose_setup(obj,0x5614b8,iVar8), fVar6 = param_2, param_5 != 0)) {

    fVar6 = *(float *)(DAT_00632ed8 + 0x1100) * param_2;

  }

  *(float *)&obj->field_0x278 = fVar6 + *(float *)&obj->field_0x278;

  if (*(float *)&obj->field_0x278 < *(float *)&obj->field_0x1c0) {

    if ((obj->coll_radius & 0x40000) == 0) {

      fVar14 = (float10)distancesq3d(DAT_00632a88 + 0xa0,&obj->field_0xa0);

      if (fVar14 <= (float10)(float)piVar13[0x29]) {

        if ((float10)(float)piVar13[0x2a] < fVar14) {

          piVar13[0x2a] = (int)(float)(fVar14 + (float10)2500.0);

        }

      }

      else {

        piVar13[0x29] = (int)(float)(fVar14 + (float10)2500.0);

      }

    }

    wound_from_object_world(obj,iVar8);

    iVar12 = rndintrange(0x76,0x77);

    sound_play_obj(iVar12);

    dVar10 = (dword)param_4;

    uVar5 = obj->coll_radius;

    obj->coll_radius = uVar5 | 4;

    if ((uVar5 & 0x2000000) != 0) {

      return;

    }

    dVar3 = obj->pad_E4;

    if (dVar3 == 0x12d) {

      return;

    }

    if ((dVar3 == 0xdc) || (dVar3 == 0xe4)) {

      if (param_4 == 0.0) {

        return;

      }

      if (*(int *)((int)param_4 + 0x1e0) != 0x4d) {

        return;

      }

      piVar13 = piVar13 + 0x8a;

      iVar12 = 2;

      do {

        dVar10 = (dword)param_4;

        if (*piVar13 != 0) {

          piVar11 = *(int **)(*piVar13 + 0x100);

          if (*piVar11 == 0) {

            *piVar11 = *(int *)((int)param_4 + 0x274);

          }

          else {

            iVar8 = ObjIsPlayer(*(undefined4 *)((int)param_4 + 0x274));

            if ((iVar8 != 0) && (*(int *)(*(int *)(dVar10 + 0x274) + 0x174) == 0)) {

              *piVar11 = *(int *)(dVar10 + 0x274);

            }

          }

        }

        piVar13 = piVar13 + 1;

        iVar12 = iVar12 + -1;

      } while (iVar12 != 0);

      return;

    }

    if (((piVar13[0x8a] != 0) && (param_4 != 0.0)) && (*(int *)((int)param_4 + 0x1e0) == 0x4d)) {

      if (*piVar13 != 0) {

        iVar12 = ObjIsPlayer(*(undefined4 *)((int)param_4 + 0x274));

        if (iVar12 == 0) {

          return;

        }

        if (*(int *)(*(int *)(dVar10 + 0x274) + 0x174) != 0) {

          return;

        }

      }

      *piVar13 = *(int *)(dVar10 + 0x274);

      return;

    }

    if ((uVar5 & 0x1000000) != 0) {

      return;

    }

    if (*(int *)&obj->field_0x210 != 0) {

      iVar12 = *(int *)(*(int *)&obj->field_0x210 + 0x1e0);

      if (iVar12 == 1) {

        return;

      }

      if (iVar12 == 0x4c) {

        return;

      }

    }

    iVar12 = *(int *)&obj->field_0xe8;

    if ((iVar12 != 0) && (iVar12 != 2)) {

      if (iVar12 != 1) {

        return;

      }

      if (0.0 <= (float)piVar13[0x19]) {

        return;

      }

    }

    if ((0x59 < (int)dVar3) && ((int)dVar3 < 0x5f)) {

      return;

    }

    if ((((param_4 != 0.0) && (*(int *)((int)param_4 + 0x1e0) == 0x4d)) && (iVar12 != 1)) &&

       (*(int *)((int)param_4 + 4) == 0x319)) {

      fVar14 = (float10)rndfloatrange(0x41200000,0x41700000);

      piVar13[0x19] = (int)(float)fVar14;

      if ((obj->anim != 0xac) && (*(int *)(obj->class_ptr + 0x2b8) != 0)) {

        ObjectSetAnim(obj);

      }

      obj->pad_E4 = 0x5e;

      return;

    }

    if ((param_2 <= *(float *)(DAT_00632ed8 + 0xc48)) || (iVar12 == 1)) {

      if (param_2 <= *(float *)(DAT_00632ed8 + 0xc4c)) {

        return;

      }

      fVar14 = (float10)rndfloatrange(0x41200000,0x41700000);

      piVar13[0x19] = (int)(float)fVar14;

      if (piVar13[0x36] == 0) {

        if ((obj->coll_radius & 0x100) == 0) {

          iVar12 = crt_rand_scaled(3);

          if (iVar12 == 0) {

            if (obj->anim == 0x85) goto code_r0x004e912b;

            iVar12 = *(int *)(obj->class_ptr + 0x21c);

          }

          else if (iVar12 == 1) {

            if (obj->anim == 0x86) goto code_r0x004e912b;

            iVar12 = *(int *)(obj->class_ptr + 0x220);

          }

          else {

            if (obj->anim == 0x87) goto code_r0x004e912b;

            iVar12 = *(int *)(obj->class_ptr + 0x224);

          }

        }

        else {

          if (obj->anim == 0xa9) goto code_r0x004e912b;

          iVar12 = *(int *)(obj->class_ptr + 0x2ac);

        }

      }

      else {

        if (obj->anim == 0x88) goto code_r0x004e912b;

        iVar12 = *(int *)(obj->class_ptr + 0x228);

      }

      if (iVar12 != 0) {

        ObjectSetAnim(obj);

      }

code_r0x004e912b:

      obj->pad_E4 = 0x5d;

      return;

    }

    fVar14 = (float10)rndfloatrange(0x41200000,0x41700000);

    piVar13[0x19] = (int)(float)fVar14;

    if (piVar13[0x36] == 0) {

      if (obj->anim == 0x58) goto code_r0x004e8ef4;

      iVar12 = *(int *)(obj->class_ptr + 0x168);

    }

    else {

      if (obj->anim == 0x3d) goto code_r0x004e8ef4;

      iVar12 = *(int *)(obj->class_ptr + 0xfc);

    }

    if (iVar12 != 0) {

      ObjectSetAnim(obj);

    }

code_r0x004e8ef4:

    if (iVar8 == 0) {

      if (param_4 == 0.0) {

        fVar14 = (float10)*(float *)&obj->field_0xc8 + (float10)180.0;

      }

      else {

        fVar14 = (float10)dirfcalcp3d__FP3P3DT0((int)param_4 + 0xa0,&obj->field_0xa0);

      }

    }

    else {

      fVar14 = (float10)dirfcalcp3d__FP3P3DT0(iVar8,&obj->field_0xa0);

    }

    param_4 = (float)fVar14;

    sine_cos_lookup(param_4,&param_3,&param_1);

    obj->pad_128 = (dword)(*(float *)(DAT_00632ed8 + 0xc60) * (float)param_3);

    *(float *)&obj->field_0x12c = -(*(float *)(DAT_00632ed8 + 0xc60) * param_1);

    fVar1 = *(float *)(DAT_00632ed8 + 0xc64);

    obj->pad_E4 = 0x5a;

    obj->loc_accum0 = (dword)(fVar1 + (float)obj->loc_accum0);

    return;

  }

  sound_stop_obj(0x56c,obj);

  if (piVar13[0x8d] != 0) {

    sound_stop_sequence(piVar13 + 0x8d);

  }

  if (piVar13[0x8e] != 0) {

    sound_stop_obj(0x62e,obj);

    piVar13[0x8e] = 0;

  }

  *(uint *)&obj->field_0x1c8 = *(uint *)&obj->field_0x1c8 | 0x800;

  if ((obj->coll_radius & 0x1000000) != 0) {

    obj->coll_radius = obj->coll_radius & 0xfeffffff;

    DAT_005a8578 = 0;

    if (piVar13[0x83] != 0) {

      smartie_unlock_from_player(piVar13[0x83],obj,0);

      piVar13[0x83] = 0;

      piVar11 = piVar13 + 0x8a;

      iVar12 = 2;

      do {

        if (*piVar11 != 0) {

          piVar2 = *(int **)(*piVar11 + 0x100);

          piVar2[0x8a] = 0;

          if ((param_4 != 0.0) && (*(int *)((int)param_4 + 0x1e0) == 0x4d)) {

            if (*piVar2 == 0) {

              iVar8 = *(int *)((int)param_4 + 0x274);

            }

            else {

              iVar8 = ObjIsPlayer(*(undefined4 *)((int)param_4 + 0x274));

              if ((iVar8 == 0) ||

                 (iVar8 = *(int *)((int)param_4 + 0x274), *(int *)(iVar8 + 0x174) != 0))

              goto code_r0x004e8788;

            }

            *piVar2 = iVar8;

          }

        }

code_r0x004e8788:

        piVar11 = piVar11 + 1;

        iVar12 = iVar12 + -1;

      } while (iVar12 != 0);

    }

  }

  dVar10 = obj->animate_state;

  param_2 = (float)dVar10;

  iVar12 = ObjIsReaper(DAT_00632a88);

  if (iVar12 == 0) {

    obj->coll_radius = obj->coll_radius | 0x4000000;

  }

  if (obj->pad_E4 != 0x23) {

    dVar3 = obj->animate_state;

    if ((*(int *)(dVar3 + 0x134) != 0) && (puVar7 = DAT_00632d6c, *(int *)(dVar3 + 0xb0) != -1)) {

      for (; puVar7 != (undefined4 *)0x0; puVar7 = (undefined4 *)*puVar7) {

        pOVar4 = (OBJECT *)puVar7[3];

        if ((((obj != pOVar4) && (pOVar4->type_id == 0xd7)) &&

            (dVar10 = pOVar4->animate_state, *(int *)(dVar10 + 0x134) == *(int *)(dVar3 + 0x134)))

           && (((*(int *)(dVar3 + 0xb0) < *(int *)(dVar10 + 0xb0) &&

                (iVar12 = *(int *)(dVar10 + 0xb0) + -1, *(int *)(dVar10 + 0xb0) = iVar12,

                iVar12 == 0)) && (pOVar4->pad_E4 == 0x21)))) {

          pOVar4->pad_E4 = obj->pad_E4;

          *(undefined4 *)(dVar10 + 0xbc) = *(undefined4 *)(dVar3 + 0xbc);

          *(undefined4 *)(dVar10 + 0xd0) = *(undefined4 *)(dVar3 + 0xd0);

        }

      }

      *(undefined4 *)(dVar3 + 0xb0) = 0xffffffff;

      dVar10 = (dword)param_2;

    }

    if (((obj->pad_E4 != 0xc9) && (obj->pad_E4 != 200)) &&

       ((iVar12 = *(int *)(dVar10 + 0x134), iVar12 != 0 && (*(int *)(iVar12 + 0x1e0) == 0x61)))) {

      piVar11 = (int *)(*(int *)(iVar12 + 0x100) + 8);

      *piVar11 = *piVar11 + -1;

    }

    iVar12 = *(int *)(dVar10 + 0x134);

    if ((iVar12 != 0) && (*(int *)(iVar12 + 0x1e0) == 0x61)) {

      formation_notify_death(iVar12);

    }

  }

  piVar13[0x4d] = 0;

  piVar13[0x11] = 0;

  if ((obj->coll_radius & 0x40000) != 0) {

    uStack_30 = *(undefined4 *)&obj->field_0xa0;

    uStack_2c = *(undefined4 *)&obj->field_0xa4;

    uStack_28 = *(undefined4 *)&obj->field_0xa8;

    fx_get_free_effect__Fv();

    line_damage_with_slope

              (0x31,obj,0,&obj->field_0xa0,*(undefined4 *)(DAT_00632ed8 + 0x1094),

               *(undefined4 *)(DAT_00632ed8 + 0x1098),*(undefined4 *)(DAT_00632ed8 + 0x109c),

               *(undefined4 *)(DAT_00632ed8 + 0x10a0),obj->ai_state_b);

    rpman_gib__FP6OBJECTT0(obj,0);

    *piVar13 = 0;

    return;

  }

  iVar12 = *(int *)&obj->field_0x210;

  if (*(int *)&obj->field_0xe8 == 7) {

    func_0x0050c990(iVar12,1);

    rpman_gib__FP6OBJECTT0(obj,param_4);

    *piVar13 = 0;

    return;

  }

  if ((iVar12 != 0) && ((*(int *)(iVar12 + 0x1e0) == 1 || (*(int *)(iVar12 + 0x1e0) == 0x4c)))) {

    rpman_gib__FP6OBJECTT0(obj,param_4);

    *piVar13 = 0;

    return;

  }

  iVar12 = rndintrange(0x83,0x86);

  sound_play_obj(iVar12);

  if (param_5 == 0) {

    fVar1 = *(float *)(DAT_00632ed8 + 0xc50) + *(float *)&obj->field_0x1c0;

    if (fVar1 < *(float *)&obj->field_0x278 != (fVar1 == *(float *)&obj->field_0x278)) {

      func_0x004e76d0(obj);

      rpman_gib__FP6OBJECTT0(obj,param_4);

      *piVar13 = 0;

      return;

    }

    if (obj->pad_E4 == 0x5b) {

      func_0x004e76d0(obj);

      obj->pad_E4 = 500;

      *piVar13 = 0;

      return;

    }

    sine_cos_lookup(*(undefined4 *)&obj->field_0xc8,&param_3,&param_1);

    fStack_40 = (float)param_3 * 10.0 + *(float *)&obj->field_0xa0;

    fStack_3c = *(float *)&obj->field_0xa4 - param_1 * 10.0;

    fVar14 = (float10)get_floor_z_point(&fStack_40);

    fStack_38 = (float)fVar14;

    if ((12.0 < *(float *)&obj->field_0xa8 - fStack_38) && (*(int *)&obj->field_0xe8 != 7)) {

      *(undefined4 *)&obj->field_0x210 = 0;

      obj->pad_E4 = 0x1f5;

      obj->loc_accum0 = *(dword *)(DAT_00632ed8 + 0x74);

      obj->pad_128 = (dword)(*(float *)(DAT_00632ed8 + 0x78) * (float)param_3);

      *(float *)&obj->field_0x12c = -(*(float *)(DAT_00632ed8 + 0x78) * param_1);

      if ((obj->anim != 0x3e) && (*(int *)(obj->class_ptr + 0x100) != 0)) {

        ObjectSetAnim(obj);

        *piVar13 = 0;

        return;

      }

      goto code_r0x004e8a31;

    }

    func_0x004e76d0(obj);

    uVar9 = rndintrange(0,8);

    dVar10 = (dword)param_4;

    switch(uVar9) {

    case 0:

      dVar10 = 0x3a;

      break;

    case 1:

      dVar10 = 0x3c;

      break;

    case 2:

      dVar10 = 0x40;

      break;

    case 3:

      dVar10 = 0x56;

      break;

    case 4:

      dVar10 = 0x57;

      break;

    case 5:

      dVar10 = 0x59;

      break;

    case 6:

      dVar10 = 0x5a;

      break;

    case 7:

      dVar10 = 0x5b;

      break;

    case 8:

      dVar10 = 0x5c;

    }

    if (obj->anim != dVar10) {

      iVar12 = *(int *)(obj->class_ptr + 8 + dVar10 * 4);

      goto joined_r0x004e8c12;

    }

  }

  else {

    func_0x004e76d0(obj);

    if (obj->anim != 0xa7) {

      iVar12 = *(int *)(obj->class_ptr + 0x2a4);

joined_r0x004e8c12:

      if (iVar12 != 0) {

        ObjectSetAnim(obj);

      }

    }

  }

  obj->pad_E4 = 500;

code_r0x004e8a31:

  *piVar13 = 0;

  return;

}

/* ===== creature_health_ai_c98 @ 0x004E91E0 ===== */
void creature_health_ai_c98(OBJECT *param_1)



{

  float fVar1;

  dword dVar2;

  int iVar3;

  OBJECT *pOVar4;

  int *piVar5;

  OBJECT *pOVar6;

  undefined4 *puVar7;

  int iVar8;

  int iVar9;

  OBJECT *obj;

  float10 fVar10;

  undefined4 uVar11;

  int iStack_2c;

  undefined1 auStack_24 [12];

  undefined1 auStack_18 [12];

  undefined1 auStack_c [12];

  

  pOVar6 = param_1;

  if (DAT_00632e74 != 0) {

    return;

  }

  dVar2 = param_1->pad_E4;

  if (dVar2 != 0) {

    if (dVar2 == 1) {

      if (*(float *)&param_1->field_0xec < 0.0 == (*(float *)&param_1->field_0xec == 0.0)) {

        fVar10 = (float10)FRateGetSecsframe(0,0);

        *(float *)&param_1->field_0xec = (float)((float10)*(float *)&param_1->field_0xec - fVar10);

      }

      else if ((*(int *)(DAT_00632a88 + 4) == 0) ||

              (fVar1 = *(float *)(DAT_00632ed8 + 0x1364),

              fVar10 = (float10)distancesq2d__FP3P3DT0(DAT_00632a88 + 0xa0,&param_1->field_0xa0),

              (float10)fVar1 * (float10)fVar1 <= fVar10)) {

        *(undefined4 *)&param_1->field_0xec = 0x3fb33333;

      }

      else {

        param_1->pad_E4 = 2;

      }

      goto code_r0x004e9829;

    }

    if (dVar2 != 2) goto code_r0x004e9829;

    fVar10 = (float10)FRateGetSecsframe(param_1,0);

    if (*(int *)&param_1->field_0xf4 < 1) {

      *(undefined4 *)&param_1->field_0xf8 = 0;

    }

    if (*(int *)&param_1->field_0xf8 != 0) {

      fVar1 = *(float *)&param_1->field_0xf0 - (float)fVar10;

      *(float *)&param_1->field_0xf0 = fVar1;

      if (fVar1 < 0.0 != (fVar1 == 0.0)) {

        iVar9 = *(int *)&param_1->field_0xe8;

        if ((iVar9 == 0) || (iVar9 == 2)) {

          func_0x004e9960(param_1,0);

        }

        else if (iVar9 == 3) {

          func_0x004e9860(param_1,1);

        }

        else {

          func_0x004e9860(param_1,0);

        }

      }

    }

    fVar1 = *(float *)&param_1->field_0xec - (float)fVar10;

    *(float *)&param_1->field_0xec = fVar1;

    if (fVar1 < 0.0 == (fVar1 == 0.0)) goto code_r0x004e9829;

    iVar9 = *(int *)&param_1->field_0xe8;

    if ((iVar9 != 0) && (iVar9 != 2)) {

      if (iVar9 == 4) {

        iVar9 = *(int *)&param_1->field_0xf8;

        puVar7 = DAT_00632d6c;

        iVar8 = DAT_00632ed8;

        while ((puVar7 != (undefined4 *)0x0 &&

               ((((iVar3 = puVar7[3], *(int *)(iVar3 + 0x1e0) != 0x17 ||

                  (*(OBJECT **)(*(int *)(iVar3 + 0x100) + 0x44) != param_1)) ||

                 (fVar10 = (float10)distancesq2d__FP3P3DT0(iVar3 + 0xa0,&param_1->field_0xa0),

                 iVar8 = DAT_00632ed8,

                 (float10)*(float *)(DAT_00632ed8 + 0xcac) *

                 (float10)*(float *)(DAT_00632ed8 + 0xcac) < fVar10)) ||

                (iVar9 = iVar9 + 1, iVar9 < *(int *)(DAT_00632ed8 + 0xca4)))))) {

          puVar7 = (undefined4 *)*puVar7;

        }

        if (((iVar9 < *(int *)(iVar8 + 0xca4)) && (0 < *(int *)&param_1->field_0xf4)) &&

           (iVar9 = *(int *)&param_1->field_0xf8 + *(int *)(iVar8 + 0xcb4),

           *(int *)&param_1->field_0xf8 = iVar9, iVar9 == *(int *)(DAT_00632ed8 + 0xcb4))) {

          if ((*(int *)&param_1->field_0x174 == 1) || (*(int *)&param_1->field_0x174 != 0)) {

            func_0x004e9860(param_1,1);

          }

          else {

            func_0x004e9860(param_1,0);

          }

        }

      }

      goto code_r0x004e9829;

    }

    iStack_2c = *(int *)&param_1->field_0xf8;

    obj = (OBJECT *)0x0;

    param_1 = (OBJECT *)0x0;

    if (DAT_00632d6c != (undefined4 *)0x0) {

      obj = (OBJECT *)0x0;

      puVar7 = DAT_00632d6c;

      do {

        pOVar4 = (OBJECT *)puVar7[3];

        if ((((pOVar4->state == 0x33) && (*(int *)&pOVar4->field_0xe8 != 4)) &&

            (piVar5 = (int *)pOVar4->animate_state, (OBJECT *)piVar5[0x89] == pOVar6)) &&

           (fVar10 = (float10)distancesq2d__FP3P3DT0(&pOVar4->field_0xa0,&pOVar6->field_0xa0),

           fVar10 <= (float10)*(float *)(DAT_00632ed8 + 0xcac) *

                     (float10)*(float *)(DAT_00632ed8 + 0xcac))) {

          if ((((pOVar4->coll_radius & 0x20000) != 0) && (*piVar5 == 0)) &&

             ((param_1 = (OBJECT *)((int)param_1 + 1), obj == (OBJECT *)0x0 &&

              (*(int *)(DAT_00632ed8 + 0xca4) < (int)param_1)))) {

            obj = pOVar4;

          }

          iStack_2c = iStack_2c + 1;

          if ((*(int *)(DAT_00632ed8 + 0xca4) <= iStack_2c) && (obj != (OBJECT *)0x0)) break;

        }

        puVar7 = (undefined4 *)*puVar7;

      } while (puVar7 != (undefined4 *)0x0);

    }

    if ((iStack_2c < *(int *)(DAT_00632ed8 + 0xca4)) && (0 < *(int *)&pOVar6->field_0xf4)) {

      iVar9 = *(int *)&pOVar6->field_0x174;

      *(int *)&pOVar6->field_0xf8 = *(int *)&pOVar6->field_0xf8 + *(int *)(DAT_00632ed8 + 0xcb4);

      if (iVar9 == 3) {

        uVar11 = 0x40400000;

      }

      else if (iVar9 == 2) {

        uVar11 = 0x40000000;

      }

      else if (iVar9 == 1) {

        uVar11 = 0x3f800000;

      }

      else {

        uVar11 = 0;

      }

      func_0x004e9960(pOVar6,uVar11);

    }

    if (obj != (OBJECT *)0x0) {

      playerobj_eval_refpt(pOVar6,1,auStack_18);

      playerobj_eval_refpt(pOVar6,2,auStack_c);

      distancesq3d(&obj->field_0xa0,auStack_18);

      distancesq3d(&obj->field_0xa0,auStack_c);

      if ((obj->coll_radius & 0x200) == 0) {

        if (obj->anim != 0x47) {

          iVar9 = *(int *)(obj->class_ptr + 0x124);

          goto joined_r0x004e95af;

        }

      }

      else if (obj->anim != 0x8e) {

        iVar9 = *(int *)(obj->class_ptr + 0x240);

joined_r0x004e95af:

        if (iVar9 != 0) {

          ObjectSetAnim(obj);

        }

      }

      *(OBJECT **)&obj->field_0x274 = pOVar6;

      ai_clear_move_goal(obj);

      ai_moveonly_set_goal(obj,auStack_24);

      obj->coll_radius = obj->coll_radius & 0xfffdffff;

      obj->pad_E4 = 0x70;

    }

    *(undefined4 *)&pOVar6->field_0xec = *(undefined4 *)(DAT_00632ed8 + 0xca8);

    goto code_r0x004e9829;

  }

  param_1->pad_E4 = 1;

  *(undefined4 *)&param_1->field_0x278 = 0;

  ObjectSetAnim(param_1);

  param_1->pad_14 = 0x3f800000;

  switch(*(undefined4 *)&param_1->field_0xe8) {

  case 0:

    if (param_1->type_id != 0x2ae) {

      if (param_1->type_id == 0x4ca) {

        *(undefined4 *)&param_1->field_0xe8 = 4;

        sound_play_obj(0x4db);

        *(undefined4 *)&param_1->field_0xf4 = 0xc;

        goto code_r0x004e9829;

      }

      goto LAB_004e97c0;

    }

    *(undefined4 *)&param_1->field_0xe8 = 2;

    break;

  case 1:

  case 3:

    iVar9 = 0x6bf;

    goto LAB_004e981b;

  case 2:

    if (param_1->type_id == 0x424) {

      *(undefined4 *)&param_1->field_0xe8 = 0;

      sound_play_obj(0x6bf);

      *(undefined4 *)&param_1->field_0xf4 = *(undefined4 *)(DAT_00632ed8 + 0xca0);

      goto code_r0x004e9829;

    }

    if (param_1->type_id == 0x4ca) {

      *(undefined4 *)&param_1->field_0xe8 = 4;

      goto LAB_004e9799;

    }

    break;

  case 4:

    if (param_1->type_id != 0x424) {

      if (param_1->type_id == 0x2ae) {

        *(undefined4 *)&param_1->field_0xe8 = 2;

        sound_play_obj(0x6bf);

        *(undefined4 *)&param_1->field_0xf4 = *(undefined4 *)(DAT_00632ed8 + 0x5c8);

        goto code_r0x004e9829;

      }

LAB_004e9799:

      sound_play_obj(0x4db);

      *(undefined4 *)&param_1->field_0xf4 = 0xc;

      goto code_r0x004e9829;

    }

    *(undefined4 *)&param_1->field_0xe8 = 0;

LAB_004e97c0:

    sound_play_obj(0x6bf);

    *(undefined4 *)&param_1->field_0xf4 = *(undefined4 *)(DAT_00632ed8 + 0xca0);

    goto code_r0x004e9829;

  case 5:

    iVar9 = 0x4db;

LAB_004e981b:

    sound_play_obj(iVar9);

    *(undefined4 *)&param_1->field_0xf4 = 0;

  default:

    goto code_r0x004e9829;

  }

  sound_play_obj(0x6bf);

  *(undefined4 *)&param_1->field_0xf4 = *(undefined4 *)(DAT_00632ed8 + 0x5c8);

code_r0x004e9829:

  iVar9 = obj_health_ratio_update(pOVar6);

  if (iVar9 != 0) {

    *(undefined4 *)&pOVar6->field_0xf4 = 0;

  }

  return;

}

/* ===== ripper_death_voices_c98 @ 0x004E9AA0 ===== */
void ripper_death_voices_c98(undefined4 param_1,float param_2,int param_3,int param_4)



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

      sound_play_obj(0x67b);

      return;

    }

    sound_play_obj(0x60f);

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

/* ===== bldg_spawn_state_tick @ 0x004E9CE0 ===== */
void bldg_spawn_state_tick(OBJECT *param_1,int param_2,int param_3)



{

  if (param_1 != (OBJECT *)0x0) {

    if (param_2 != 0) {

      if (param_1->pad_E4 != 3) {

        ObjectSetAnim(param_1);

      }

      if ((*(int *)&param_1->field_0xf4 == 0) && (*(int *)&param_1->field_0x274 == 0)) {

        param_1->pad_E4 = 3;

        return;

      }

      param_1->pad_E4 = 2;

      return;

    }

    if (*(int *)&param_1->field_0x274 != 0) {

      *(int *)(param_1->animate_state + param_3 * 4) = *(int *)&param_1->field_0x274;

      *(undefined4 *)&param_1->field_0x274 = 0;

    }

    *(undefined4 *)&param_1->field_0xec = *(undefined4 *)(DAT_00632ed8 + 0xf4c);

    ObjectSetAnim(param_1);

    param_1->pad_E4 = 1;

  }

  return;

}

/* ===== barracks_spawner_ai_c103 @ 0x004E9D90 ===== */
void barracks_spawner_ai_c103(OBJECT *param_1)



{

  undefined1 *puVar1;

  dword dVar2;

  OBJECT *obj;

  undefined4 *puVar3;

  bool bVar4;

  OBJECT *pOVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  float10 fVar9;

  float fStack_10;

  undefined4 uStack_c;

  undefined4 uStack_8;

  undefined4 uStack_4;

  

  pOVar5 = param_1;

  dVar2 = param_1->animate_state;

  iVar8 = 0;

  if (DAT_00632e74 != 0) {

    return;

  }

  switch(param_1->pad_E4) {

  case 0:

    *(undefined4 *)&param_1->field_0x278 = 0;

    param_1->pad_14 = 0x3f800000;

    ObjectSetAnim(param_1);

    object_animate_process(param_1);

    iVar7 = __ftol();

    if (0 < iVar7) {

      do {

        *(int *)&param_1->field_0xf4 = *(int *)&param_1->field_0xf4 + 1;

        iVar6 = object_allocate_type(0xd7,0x80000000);

        iVar7 = *(int *)(iVar6 + 0x100);

        playerobj_eval_refpt(param_1,iVar8,&uStack_c);

        object_set_location(iVar6,uStack_c,uStack_8,uStack_4);

        fVar9 = (float10)tracer_entry_angle(param_1,iVar8);

        *(float *)(iVar6 + 200) = (float)fVar9;

        *(undefined4 *)(iVar6 + 0xe8) = 4;

        *(OBJECT **)(iVar7 + 0x150) = param_1;

        *(int *)(iVar7 + 0x154) = iVar8;

        *(undefined4 *)(iVar7 + 0x158) = *(undefined4 *)(iVar6 + 200);

        if ((param_1->flags & 0x400) != 0) {

          *(uint *)(iVar6 + 0xd8) = *(uint *)(iVar6 + 0xd8) | 0x400;

        }

        *(int *)(dVar2 + iVar8 * 4) = iVar6;

        iVar8 = iVar8 + 1;

        iVar7 = __ftol();

      } while (iVar8 < iVar7);

    }

    iVar8 = *(int *)(DAT_00632ed8 + 0xf54);

    *(int *)(dVar2 + 0x20) = iVar8;

    iVar7 = __ftol();

    if (iVar8 < iVar7) {

      *(int *)(dVar2 + 0x20) = iVar7;

    }

    if (*(int *)&param_1->field_0xf4 == 0) {

      ObjectSetAnim(param_1);

      param_1->pad_14 = 0x3f800000;

      param_1->pad_E4 = 3;

    }

    else {

      ObjectSetAnim(param_1);

      param_1->pad_14 = 0;

      param_1->pad_E4 = 1;

    }

    break;

  case 1:

    if (*(float *)&param_1->field_0xec < 0.0 == (*(float *)&param_1->field_0xec == 0.0)) {

LAB_004ea0fd:

      fVar9 = (float10)FRateGetSecsframe(0,0);

      *(float *)&param_1->field_0xec = (float)((float10)*(float *)&param_1->field_0xec - fVar9);

      break;

    }

    if (*(int *)(dVar2 + 0x18) == 0) {

      if (*(int *)(dVar2 + 0x20) < *(int *)&param_1->field_0xf4) {

        ObjectSetAnim(param_1);

        if ((*(int *)&param_1->field_0xf4 == 0) && (*(int *)&param_1->field_0x274 == 0)) {

          param_1->pad_E4 = 3;

        }

        else {

          param_1->pad_E4 = 2;

        }

        iVar8 = 0;

        do {

          if (*(int *)(dVar2 + iVar8 * 4) != 0) {

            *(undefined4 *)&param_1->field_0x274 = *(undefined4 *)(dVar2 + iVar8 * 4);

            *(undefined4 *)(dVar2 + iVar8 * 4) = 0;

            break;

          }

          iVar8 = iVar8 + 1;

        } while (iVar8 < 6);

      }

      break;

    }

    goto LAB_004ea0f2;

  case 2:

    obj = *(OBJECT **)&param_1->field_0x274;

    if (obj == (OBJECT *)0x0) {

      *(undefined4 *)&param_1->field_0xec = *(undefined4 *)(DAT_00632ed8 + 0xf4c);

      ObjectSetAnim(param_1);

      param_1->pad_E4 = 1;

    }

    else if ((*(int *)(dVar2 + 0x18) == 0) && ((param_1->field_0x30 & 2) != 0)) {

      *(uint *)&obj->field_0x1c8 = *(uint *)&obj->field_0x1c8 | 0xe00;

      obj->flags = obj->flags | 0x10;

      playerobj_eval_refpt

                (*(undefined4 *)(obj->animate_state + 0x150),

                 *(int *)(obj->animate_state + 0x154) + 6,&uStack_c);

      ai_clear_move_goal(obj);

      ai_move_force_goal(obj,&uStack_c);

      if ((obj->coll_radius & 0x200) == 0) {

        ai_anim_play(obj,0x47,1,1,*(undefined4 *)(DAT_00632ed8 + 0xb38),0);

      }

      else if ((obj->anim != 0x8e) && (*(int *)(obj->class_ptr + 0x240) != 0)) {

        ObjectSetAnim(obj);

        obj->pad_E4 = 0xaf;

        break;

      }

      obj->pad_E4 = 0xaf;

    }

    break;

  case 3:

    if (*(float *)&param_1->field_0xec < 0.0 == (*(float *)&param_1->field_0xec == 0.0))

    goto LAB_004ea0fd;

LAB_004ea0f2:

    barracks_logic(param_1);

  }

  if ((*(float *)&param_1->field_0xf0 < 0.0 == (*(float *)&param_1->field_0xf0 == 0.0)) ||

     (*(int *)&param_1->field_0x274 != 0)) {

    fVar9 = (float10)FRateGetSecsframe(0,0);

    *(float *)&param_1->field_0xf0 = (float)((float10)*(float *)&param_1->field_0xf0 - fVar9);

    return;

  }

  dVar2 = param_1->animate_state;

  *(undefined4 *)(dVar2 + 0x18) = 0;

  fStack_10 = *(float *)(DAT_00632ed8 + 0xf48) * *(float *)(DAT_00632ed8 + 0xf48);

  bVar4 = false;

  puVar3 = DAT_00632d6c;

  do {

    if (puVar3 == (undefined4 *)0x0) {

      iVar8 = 0;

      do {

        iVar7 = *(int *)(dVar2 + iVar8 * 4);

        if (iVar7 != 0) {

          **(undefined4 **)(iVar7 + 0x100) = *(undefined4 *)(dVar2 + 0x18);

        }

        iVar8 = iVar8 + 1;

      } while (iVar8 < 6);

      *(undefined4 *)&pOVar5->field_0xf0 = 0x3f800000;

      return;

    }

    iVar8 = puVar3[3];

    iVar7 = ObjIsPlayer(iVar8);

    if ((((iVar7 != 0) && ((*(uint *)(iVar8 + 0xd8) & 0x4000c000) == 0)) &&

        (*(float *)(iVar8 + 0x278) < *(float *)(iVar8 + 0x1c0))) &&

       ((iVar7 = ObjIsMecc(iVar8), iVar7 == 0 || ((*(uint *)(iVar8 + 0xe0) & 0x2000000) == 0)))) {

      puVar1 = &pOVar5->field_0xa0;

      fVar9 = (float10)distancesq3d(puVar1,iVar8 + 0xa0);

      param_1 = (OBJECT *)(float)fVar9;

      iVar7 = ObjIsKabuto(iVar8);

      if (iVar7 != 0) {

        param_1 = (OBJECT *)((float)param_1 * 0.25);

      }

      if ((float)param_1 <= fStack_10) {

        if ((float)param_1 < 144.0) {

          bVar4 = true;

        }

        iVar7 = ObjIsKabuto(iVar8);

        if ((iVar7 != 0) && ((float)param_1 < 10000.0)) {

          bVar4 = true;

        }

        if ((DAT_006328e8 - DAT_00632b44 < 1.0 == (DAT_006328e8 - DAT_00632b44 == 1.0)) ||

           (*(float *)(dVar2 + 0x1c) == DAT_00632b44)) {

LAB_004ea2ad:

          if (!bVar4) {

            dirfcalcp3d__FP3P3DT0(puVar1,iVar8 + 0xa0);

            iVar7 = LineOfSight(pOVar5,iVar8);

            if (iVar7 == 0) goto LAB_004ea2df;

          }

        }

        else {

          *(float *)(dVar2 + 0x1c) = DAT_00632b44;

          fVar9 = (float10)distancesq2d__FP3P3DT0(puVar1,&DAT_00632b48);

          if ((float10)14400.0 <= fVar9) goto LAB_004ea2ad;

          bVar4 = true;

        }

        fStack_10 = (float)param_1;

        *(int *)(dVar2 + 0x18) = iVar8;

      }

    }

LAB_004ea2df:

    puVar3 = (undefined4 *)*puVar3;

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



void barracks_logic(OBJECT *param_1)



{

  float fVar1;

  dword dVar2;

  OBJECT *pOVar3;

  undefined4 *puVar4;

  OBJECT *obj;

  int iVar5;

  int *piVar6;

  OBJECT *obj_00;

  float10 fVar7;

  float10 fVar8;

  undefined1 local_c [12];

  

  obj = param_1;

  if (5 < *(int *)&param_1->field_0xf4) {

    return;

  }

  dVar2 = param_1->animate_state;

  iVar5 = *(int *)(dVar2 + 0x18);

  if (iVar5 == 0) {

    return;

  }

  fVar1 = *(float *)(DAT_00632ed8 + 0xf50);

  fVar7 = (float10)distancesq3d(iVar5 + 0xa0,&param_1->field_0xa0);

  fVar8 = (float10)fVar1 * (float10)fVar1;

  if (fVar8 < fVar7 == (fVar8 == fVar7)) {

    return;

  }

  *(undefined4 *)&param_1->field_0xec = 0x3f800000;

  obj_00 = (OBJECT *)0x0;

  param_1 = (OBJECT *)0xbf800000;

  piVar6 = DAT_00632d6c;

  if (DAT_00632d6c == (int *)0x0) {

    return;

  }

  do {

    pOVar3 = (OBJECT *)piVar6[3];

    if (((pOVar3->type_id == 0xd7) &&

        ((((*(int *)&pOVar3->field_0xe8 == 2 || (*(int *)&pOVar3->field_0xe8 == 0)) &&

          (fVar1 = *(float *)(pOVar3->animate_state + 0x20), fVar1 < 0.0 == (fVar1 == 0.0))) &&

         (*(int *)(pOVar3->animate_state + 0x134) == 0)))) &&

       ((fVar7 = (float10)distancesq3d(&pOVar3->field_0xa0,&obj->field_0xa0),

        fVar7 < (float10)(float)param_1 || (obj_00 == (OBJECT *)0x0)))) {

      param_1 = (OBJECT *)(float)fVar7;

      obj_00 = pOVar3;

    }

    piVar6 = (int *)*piVar6;

  } while (piVar6 != (int *)0x0);

  if (obj_00 == (OBJECT *)0x0) {

    return;

  }

  if (*(float *)(DAT_00632ed8 + 0x380) * *(float *)(DAT_00632ed8 + 0x380) <= (float)param_1) {

    return;

  }

  iVar5 = 0;

  do {

    if (*(int *)(dVar2 + iVar5 * 4) == 0) break;

    iVar5 = iVar5 + 1;

  } while (iVar5 < 6);

  puVar4 = (undefined4 *)obj_00->animate_state;

  puVar4[0x55] = iVar5;

  puVar4[0x54] = obj;

  *puVar4 = 0;

  playerobj_eval_refpt(obj,iVar5 + 6,local_c);

  ai_clear_move_goal(obj_00);

  ai_moveonly_set_goal(obj_00,local_c);

  if ((obj_00->coll_radius & 0x200) == 0) {

    if (obj_00->anim == 0x47) goto LAB_004ea5de;

    iVar5 = *(int *)(obj_00->class_ptr + 0x124);

  }

  else {

    if (obj_00->anim == 0x8e) goto LAB_004ea5de;

    iVar5 = *(int *)(obj_00->class_ptr + 0x240);

  }

  if (iVar5 != 0) {

    ObjectSetAnim(obj_00);

  }

LAB_004ea5de:

  *(undefined4 *)&obj_00->field_0xe8 = 4;

  obj_00->pad_E4 = 0xab;

  *(OBJECT **)&obj->field_0x274 = obj_00;

  if (obj->pad_E4 != 3) {

    ObjectSetAnim(obj);

  }

  if ((*(int *)&obj->field_0xf4 == 0) && (*(int *)&obj->field_0x274 == 0)) {

    obj->pad_E4 = 3;

    return;

  }

  obj->pad_E4 = 2;

  return;

}

/* ===== barracks_death_handler_c103 @ 0x004EA650 ===== */
void barracks_death_handler_c103(undefined4 param_1,float param_2,int param_3)



{

  int iVar1;

  OBJECT *obj;

  int iVar2;

  int iVar3;

  

  if (*(float *)(param_3 + 0x278) < *(float *)(param_3 + 0x1c0)) {

    param_2 = param_2 + *(float *)(param_3 + 0x278);

    *(float *)(param_3 + 0x278) = param_2;

    if (*(float *)(param_3 + 0x1c0) <= param_2) {

      iVar1 = *(int *)(param_3 + 0x100);

      iVar2 = object_allocate_type(0x468,0x80000000);

      *(undefined4 *)(iVar2 + 0xa0) = *(undefined4 *)(param_3 + 0xa0);

      *(undefined4 *)(iVar2 + 0xa4) = *(undefined4 *)(param_3 + 0xa4);

      *(undefined4 *)(iVar2 + 0xa8) = *(undefined4 *)(param_3 + 0xa8);

      *(undefined4 *)(iVar2 + 200) = *(undefined4 *)(param_3 + 200);

      *(undefined4 *)(iVar2 + 0xc4) = *(undefined4 *)(param_3 + 0xc4);

      fx_get_free_effect__Fv();

      iVar2 = 0;

      do {

        iVar3 = *(int *)(iVar1 + iVar2 * 4);

        if ((iVar3 != 0) && (*(float *)(iVar3 + 0x278) < *(float *)(iVar3 + 0x1c0))) {

          iVar3 = crt_rand_scaled(0);

          obj = *(OBJECT **)(iVar1 + iVar2 * 4);

          if (iVar3 == 0) {

            if (obj->anim != 0xa3) {

              iVar3 = *(int *)(obj->class_ptr + 0x294);

              goto joined_r0x004ea78e;

            }

          }

          else if (obj->anim != 0xa2) {

            iVar3 = *(int *)(obj->class_ptr + 0x290);

joined_r0x004ea78e:

            if (iVar3 != 0) {

              ObjectSetAnim(obj);

            }

          }

          *(undefined4 *)(*(int *)(iVar1 + iVar2 * 4) + 0xe4) = 0xb0;

          *(undefined4 *)(iVar1 + iVar2 * 4) = 0;

        }

        iVar2 = iVar2 + 1;

        if (5 < iVar2) {

          sound_play_3dpos(0x610,(undefined4 *)(param_3 + 0xa0));

          object_destroy(param_3);

          return;

        }

      } while( true );

    }

    sound_play_obj(0x60f);

  }

  return;

}

/* ===== bldg_slots_clear_tick @ 0x004EA810 ===== */
void bldg_slots_clear_tick(OBJECT *param_1)



{

  int *piVar1;

  int iVar2;

  int *piVar3;

  

  piVar1 = (int *)param_1->animate_state;

  *(undefined4 *)&param_1->field_0xf4 = 0;

  iVar2 = 6;

  piVar3 = piVar1;

  do {

    obj_ptr_clear_if_dead(piVar3);

    if (*piVar3 != 0) {

      *(int *)&param_1->field_0xf4 = *(int *)&param_1->field_0xf4 + 1;

    }

    piVar3 = piVar3 + 1;

    iVar2 = iVar2 + -1;

  } while (iVar2 != 0);

  if ((*(int *)&param_1->field_0xf4 == 0) && (param_1->pad_E4 == 1)) {

    ObjectSetAnim(param_1);

    if ((*(int *)&param_1->field_0xf4 == 0) && (*(int *)&param_1->field_0x274 == 0)) {

      param_1->pad_E4 = 3;

      obj_ptr_clear_if_dead(piVar1 + 6);

      return;

    }

    param_1->pad_E4 = 2;

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

  

  iVar3 = dialog_level_is_base_dup0052aa70();

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

           (fVar8 = (float10)distancesq3d(iVar3 + 0xa0,iVar7 + 0xa0),

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

            (fVar8 = (float10)distancesq3d(iVar3 + 0xa0,iVar7 + 0xa0),

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

    iVar3 = dialog_level_is_base_dup0052aa70();

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

             (fVar10 = (float10)distancesq3d(iVar7 + 0xa0,iVar9 + 0xa0),

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

    iVar3 = dialog_level_is_base_dup0052aa70();

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

             (fVar10 = (float10)distancesq3d(iVar7 + 0xa0,iVar9 + 0xa0),

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

  iVar3 = dialog_level_is_base_dup0052aa70();

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

           (fVar10 = (float10)distancesq3d(iVar7 + 0xa0,iVar9 + 0xa0),

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

            (fVar10 = (float10)distancesq3d(iVar7 + 0xa0,iVar9 + 0xa0),

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

            (fVar10 = (float10)distancesq3d(iVar7 + 0xa0,iVar9 + 0xa0),

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

            (fVar10 = (float10)distancesq3d(iVar7 + 0xa0,iVar9 + 0xa0),

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

  iVar1 = dialog_level_is_base_dup0052aa70();

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

/* ===== vcall_5a8598_spells_hook @ 0x004EB8F0 ===== */
void vcall_5a8598_spells_hook(void)



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

/* ===== reaper_summon_spawn @ 0x004EC1F0 ===== */
/* PS2 candidate: army_create_ripper__FP6OBJECTP9ArmyOrderi (conf 0.392) */



int reaper_summon_spawn(undefined4 param_1,undefined4 param_2,undefined4 param_3)



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

/* ===== seamonster_swimmer_c29 @ 0x004EC440 ===== */
void seamonster_swimmer_c29(OBJECT *param_1)



{

  dword dVar1;

  int iVar2;

  float10 fVar3;

  OBJECT *pOVar4;

  undefined4 uVar5;

  undefined4 uVar6;

  undefined4 uVar7;

  undefined4 uVar8;

  undefined4 uVar9;

  

  dVar1 = param_1->animate_state;

  if (DAT_00632e74 != 0) {

    return;

  }

  param_1->field_0x208 = 0;

  param_1->field_0x20b = 0;

  param_1->field_0x20a = 0;

  param_1->flags = param_1->flags & 0xfcffffff;

  if (param_1->pad_E4 == 0) {

    param_1->pad_104 = dVar1;

    PhysicsExZeroForce(param_1);

    *(undefined4 *)&param_1->field_0x194 = *(undefined4 *)(DAT_00632ed8 + 0xcfc);

    ai_move_force_goal(param_1,dVar1 + 0x48);

    param_1->pad_E4 = 1;

  }

  iVar2 = *(int *)&param_1->field_0x274;

  if (iVar2 != 0) {

    *(undefined4 *)(dVar1 + 0x54) = *(undefined4 *)(iVar2 + 0xa0);

    *(undefined4 *)(dVar1 + 0x58) = *(undefined4 *)(iVar2 + 0xa4);

    *(undefined4 *)(dVar1 + 0x5c) = *(undefined4 *)(iVar2 + 0xa8);

  }

  switch(param_1->pad_E4) {

  case 1:

    fVar3 = (float10)FRateGetSecsframe(param_1,0);

    fVar3 = (float10)*(float *)&param_1->field_0xec - fVar3;

    *(float *)&param_1->field_0xec = (float)fVar3;

    if (fVar3 < (float10)0.0) {

      *(undefined4 *)&param_1->field_0xec = 0;

    }

    ai_goal_process(param_1);

    if ((*(int *)&param_1->field_0x168 == 0) &&

       (*(float *)&param_1->field_0xec < 0.0 != (*(float *)&param_1->field_0xec == 0.0))) {

      ObjectSetAnim(param_1);

      param_1->pad_E4 = 2;

      param_1->pad_184 = 0;

    }

    else {

      param_1->pad_184 = (dword)(*(float *)&param_1->field_0xec / *(float *)(DAT_00632ed8 + 0xcf8));

    }

    break;

  case 2:

    if ((param_1->field_0x30 & 2) != 0) {

      if ((param_1->coll_radius & 1) == 0) {

        param_1->pad_E4 = 3;

      }

      else {

        uVar9 = 0x3e2aaaab;

        uVar8 = 0;

        uVar7 = 0;

        uVar6 = 1;

        uVar5 = 5;

        pOVar4 = param_1;

        ObjectSetAnim(param_1);

        *(undefined4 *)&param_1->field_0xf0 = *(undefined4 *)(DAT_00632ed8 + 0xcf8);

        ai_move_force_goal(param_1,dVar1 + 0x3c,pOVar4,uVar5,uVar6,uVar7,uVar8,uVar9);

        param_1->pad_E4 = 4;

      }

    }

    if (((0.7 < (float)param_1->pad_14) &&

        (*(float *)&param_1->field_0x18 < 0.7 != (*(float *)&param_1->field_0x18 == 0.7))) &&

       (iVar2 = fx_create(param_1), iVar2 != 0)) {

      main_seamonst_004ec2c0(param_1,dVar1 + 0x54,0xffffffff);

    }

    break;

  case 3:

    if ((param_1->coll_radius & 1) != 0) {

      uVar9 = 0x3e2aaaab;

      uVar8 = 0;

      uVar7 = 0;

      uVar6 = 1;

      uVar5 = 5;

      pOVar4 = param_1;

      ObjectSetAnim(param_1);

      *(undefined4 *)&param_1->field_0xf0 = *(undefined4 *)(DAT_00632ed8 + 0xcf8);

      ai_move_force_goal(param_1,dVar1 + 0x3c,pOVar4,uVar5,uVar6,uVar7,uVar8,uVar9);

      param_1->pad_E4 = 4;

    }

    break;

  case 4:

    fVar3 = (float10)FRateGetSecsframe(param_1,0);

    fVar3 = (float10)*(float *)&param_1->field_0xf0 - fVar3;

    *(float *)&param_1->field_0xf0 = (float)fVar3;

    if (fVar3 < (float10)0.0) {

      *(undefined4 *)&param_1->field_0xf0 = 0;

    }

    ai_goal_process(param_1);

    param_1->field_0x20a = -param_1->field_0x20a;

    if ((*(int *)&param_1->field_0x168 != 0) ||

       (*(float *)&param_1->field_0xf0 < 0.0 == (*(float *)&param_1->field_0xf0 == 0.0))) {

      param_1->pad_184 =

           (dword)(1.0 - *(float *)&param_1->field_0xf0 / *(float *)(DAT_00632ed8 + 0xcf8));

      break;

    }

    goto LAB_004ec6fc;

  case 5:

    if ((param_1->field_0x30 & 2) == 0) break;

LAB_004ec6fc:

    object_destroy(param_1);

  }

  if (param_1->pad_E4 != 4) {

    obj_alpha_fade_update(param_1);

  }

  player_pitch_update(param_1);

  obj_vel_reset(param_1);

  PhysicsExApplyLocation(param_1);

  PhysicsExCalcControledModelSpeeds

            (param_1,*(undefined4 *)(DAT_00632ed8 + 0xd84),*(undefined4 *)&param_1->field_0x194);

  obj_gravity_apply(param_1,1);

  PhysicsExApplyMoveControls(param_1);

  FRateGetSecsframe(param_1,0);

  object_animate_process(param_1);

  param_1->flags = param_1->flags | 0x40;

  return;

}

/* ===== seamonster_tick_c29 @ 0x004EC7A0 ===== */
void seamonster_tick_c29(undefined4 param_1,int param_2,undefined4 param_3,int param_4)



{

  if (param_2 == 1) {

    main_seamonst_004ec2c0(param_1,param_4,*(undefined4 *)(param_4 + 0xc));

  }

  return;

}

/* ===== ret_const_x60_c29 @ 0x004EC7C0 ===== */
undefined4 ret_const_x60_c29(void)



{

  return 0x60;

}

/* ===== defaults_bytes_init @ 0x004EC7D0 ===== */
void defaults_bytes_init(undefined4 *param_1)



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

  uVar2 = TextGetPtr(s_SetPerfShadow_00561f48);

  if (bVar4) {

    pcVar5 = s_SetOptionOn_00561f3c;

  }

  else {

    pcVar5 = s_SetOptionOff_00561f2c;

  }

  uVar3 = TextGetPtr(pcVar5);

  crt_sprintf(local_100,uVar2,uVar3);

  main_dlog_004281f0(uVar1,1,local_100);

  crt_sprintf(local_120,s_SetPerfLOD_d_00561f1c,DAT_00633150);

  uVar2 = TextGetPtr(local_120);

  uVar3 = TextGetPtr(s_SetPerfLOD_00561f10);

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

      error_msg_show();

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

  iVar1 = dialog_level_is_base_dup0052aa70();

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

        vcall_5dd298_setupgam(DAT_00632dbc + iVar2);

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

  

  iVar1 = net_active_players_get();

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

  vcall_5a8598_spells_hook();

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

  OBJECT *obj;

  undefined4 *puVar1;

  int iVar2;

  undefined4 uVar3;

  int iVar4;

  

  DAT_00633044 = 1;

  DAT_00633048 = 1;

  if (*(char *)(DAT_006330e4 + 0x4530) != '\0') {

    fx_get_free_effect__Fv();

  }

  iVar2 = dialog_level_is_base_dup0052aa70();

  if (iVar2 == 0) {

    chat_init();

  }

  read_worlds_bin_fn_PS2();

  reaper_weapon_name_lookup();

  savegame_verify_user();

  iVar2 = dialog_level_is_base_dup0052aa70();

  puVar1 = DAT_00632d68;

  if (iVar2 == 0) {

    for (; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {

      obj = (OBJECT *)puVar1[3];

      obj_velocity_commit(obj);

      if (DAT_00632a88 == 0) {

        return;

      }

      if (((obj->flags & 0xc000) == 0) && ((obj->flags & 0x40) == 0)) {

        objspec_dispatch_gate(obj);

        FRateGetSecsframe(obj,0);

        object_animate_process(obj);

        object_apply_location(obj);

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

  iVar2 = net_active_players_get();

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

  vtable_grid_5dd308_set();

  vtable_flagged_dispatch();

  DAT_00632e40 = 0;

  DAT_00633014 = 0;

  time_get_ms();

  return;

}

/* ===== world_next_enter @ 0x004EE800 ===== */
void world_next_enter(void)



{

  int iVar1;

  int iVar2;

  

  iVar1 = dialog_level_is_base_dup0052aa70();

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

  iVar1 = fx_name_exists(s_world_gb2_005620f8);

  if (iVar1 != 0) {

    iVar1 = fx_name_exists_2(s_w_intro_bin_005620ec);

    if (iVar1 != 0) {

      iVar1 = fx_name_exists(s_story1_gti_005620e0);

      if (iVar1 != 0) {

        registry_volume_check();

        return 1;

      }

    }

  }

  pcVar2 = (char *)TextGetPtr(s_ErrGameFiles_005620d0);

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

  defaults_bytes_init(&DAT_00632b20);

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

  comm_critsec_delete();

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

/* ===== reaper_health_anim_tick_c61 @ 0x004EF280 ===== */
void reaper_health_anim_tick_c61(OBJECT *param_1)



{

  if ((param_1->coll_radius & 1) == 0) {

    *(undefined4 *)&param_1->field_0x278 = 0;

    ObjectSetAnim(param_1);

    param_1->pad_14 = 0x3f800000;

    param_1->coll_radius = param_1->coll_radius | 1;

  }

  obj_health_ratio_update(param_1);

  return;

}

/* ===== ANM_AnimGetImage @ 0x004EF2D0 ===== */
uint ANM_AnimGetImage(int param_1)



{

  return *(uint *)(param_1 + 0xe0) & 2;

}

/* ===== voice_emitter_death_c61 @ 0x004EF2E0 ===== */
void voice_emitter_death_c61

               (undefined4 param_1,float param_2,int param_3,undefined4 param_4,int param_5)



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

  iVar2 = meccbasepit_bldg_from_object_dup004a6200(uVar1);

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
void smartie_ai_main(OBJECT *param_1)



{

  float *pfVar1;

  uint *puVar2;

  dword dVar3;

  undefined2 uVar4;

  int iVar5;

  int iVar6;

  uint uVar7;

  undefined4 uVar8;

  int iVar9;

  undefined4 *puVar10;

  float fVar11;

  int *piVar12;

  dword dVar13;

  float10 fVar14;

  float10 fVar15;

  char *pcVar16;

  undefined4 uVar17;

  OBJECT *pOVar18;

  undefined1 *puVar19;

  undefined4 uVar20;

  undefined4 uVar21;

  undefined4 uVar22;

  float fVar23;

  undefined4 uVar24;

  float fVar25;

  undefined4 uVar26;

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

  OBJECT *pOStack_21c;

  undefined1 auStack_200 [512];

  

  dVar13 = param_1->animate_state;

  if (DAT_00632e74 != 0) {

    return;

  }

  if (*(int *)&param_1->field_0x210 != 0) {

    iVar5 = *(int *)(*(int *)&param_1->field_0x210 + 0x1e0);

    if (iVar5 == 1) {

      return;

    }

    if (iVar5 == 0x4c) {

      return;

    }

  }

  if (param_1->pad_E4 == 0x35) {

    return;

  }

  if (*(float *)(dVar13 + 0x10) == 0.0) {

    *(undefined4 *)(dVar13 + 0x10) = *(undefined4 *)&param_1->field_0xc4;

  }

  if ((param_1->pad_E4 != 0x13) && (param_1->pad_E4 != 0x32)) {

    if (*(int *)(dVar13 + 0x4c) == 0) {

      *(undefined4 *)&param_1->field_0xc4 = *(undefined4 *)(dVar13 + 0x10);

    }

    if (*(int *)(dVar13 + 0x30) != 0) {

      *(undefined4 *)(*(int *)(dVar13 + 0x30) + 0xc4) = *(undefined4 *)(dVar13 + 0x14);

    }

    if (((DAT_00632bb0 != 0) && (*(int *)&param_1->field_0x274 == DAT_00632bbc)) &&

       (*(int *)(dVar13 + 0x4c) == 0)) {

      iVar5 = *(int *)(*(int *)(*(int *)&param_1->field_0x274 + 0x100) + 0x368);

      if ((-1 < iVar5) && (iVar5 == *(int *)(dVar13 + 0x1c))) {

        *(float *)&param_1->field_0xc4 = *(float *)(dVar13 + 0x10) * 6.0;

      }

      if (*(int *)(dVar13 + 0x30) != 0) {

        *(float *)(*(int *)(dVar13 + 0x30) + 0xc4) =

             (*(float *)&param_1->field_0xc4 / *(float *)(dVar13 + 0x10)) *

             *(float *)(dVar13 + 0x14);

      }

    }

  }

  if (*(char *)(dVar13 + 0x80) == '\0') {

    smartie_get_name__FP6OBJECT(param_1);

  }

  if (*(int *)(dVar13 + 0xa4) == 0) {

    *(undefined4 *)(dVar13 + 0xa4) = *(undefined4 *)&param_1->field_0x1d0;

  }

  if ((((param_1->coll_radius & 8) == 0) || (*(int *)&param_1->field_0xe8 == 10)) &&

     (param_1->pad_E4 != 0x41)) {

    *(undefined4 *)&param_1->field_0x1d0 = *(undefined4 *)(dVar13 + 0xa4);

  }

  else {

    *(uint *)&param_1->field_0x1d0 = *(uint *)&param_1->field_0x1d0 & 0xfffff000;

  }

  param_1->pad_DC = param_1->pad_DC | 0x10;

  iVar5 = fx_create(param_1);

  dVar3 = param_1->pad_E4;

  if (iVar5 == 0) {

    dVar13 = param_1->animate_state;

    switch(dVar3) {

    case 0x13:

      iVar5 = *(int *)&param_1->field_0x274;

      if ((iVar5 != 0) && (iVar6 = ObjIsReaper(iVar5), iVar6 != 0)) {

        fStack_254 = *(float *)(iVar5 + 0x298) * 5.0;

        puVar19 = &param_1->field_0xa0;

        fStack_248 = fStack_254 + *(float *)(iVar5 + 0xa0);

        uStack_260 = *(float *)(iVar5 + 0x2a8) * 5.0;

        fStack_244 = uStack_260 + *(float *)(iVar5 + 0xa4);

        fStack_24c = *(float *)(iVar5 + 0xa8) + 3.0;

        fStack_254 = *(float *)(iVar5 + 0xa0) - fStack_254;

        fStack_250 = *(float *)(iVar5 + 0xa4) - uStack_260;

        fStack_240 = fStack_24c;

        fVar14 = (float10)distancesq3d(puVar19,&fStack_248);

        fStack_264 = (float)fVar14;

        fVar14 = (float10)distancesq3d(puVar19,&fStack_254);

        if (fVar14 < (float10)fStack_264) {

          fStack_248 = fStack_254;

          fStack_244 = fStack_250;

          fStack_240 = fStack_24c;

        }

        if (25.0 <= fStack_264) {

          fVar11 = 0.12;

        }

        else {

          fVar11 = fStack_264 * 0.0047999998;

        }

        fVar25 = 1.0 - fVar11;

        *(undefined4 *)&param_1->field_0xc8 = *(undefined4 *)(iVar5 + 200);

        object_set_location(param_1,fVar25 * *(float *)puVar19 + fVar11 * fStack_248,

                            fVar11 * fStack_244 + fVar25 * *(float *)&param_1->field_0xa4,

                            fVar11 * fStack_240 + fVar25 * *(float *)&param_1->field_0xa8);

      }

      if (*(int *)&param_1->field_0xe8 == 10) {

        fVar14 = (float10)FRateGetSecsframe(param_1,0);

        fVar14 = fVar14 + (float10)*(float *)(dVar13 + 0x9c);

        *(float *)(dVar13 + 0x9c) = (float)fVar14;

        if (((float10)*(int *)(DAT_00632ed8 + 0x1584) < fVar14) &&

           (param_1->ai_state_b == *(dword *)(DAT_00632a88 + 0x18c))) {

          uVar8 = TextGetPtrRandom(s_SmChStillStolen_00562240,4,1);

          chat_insert_name(dVar13 + 0x80,uVar8);

          *(undefined4 *)(dVar13 + 0x9c) = 0;

        }

      }

      break;

    default:

      if (param_1->type_id == 0xb) {

        if (*(int *)&param_1->field_0x168 == 0) {

          fVar14 = (float10)distancesq2d__FP3P3DT0(&param_1->field_0xa0,dVar13 + 0x58);

          if (fVar14 <= (float10)9.0) {

            object_set_location_p3d(param_1,dVar13 + 0x58);

            param_1->field_0x20b = 0;

            param_1->field_0x20a = 0;

            param_1->field_0x208 = 0;

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

      if (param_1->anim == 0x5c) {

        uVar8 = base_get_base_building(*(undefined4 *)&param_1->field_0x274);

        bldg_get_refpt_worldloc(uVar8,*(undefined4 *)(dVar13 + 0x28),&fStack_254);

        object_set_location_p3d(param_1,&fStack_254);

      }

      else if (param_1->anim == 0x34) {

        puStack_258 = (undefined4 *)

                      ((float)param_1->pad_14 / **(float **)(param_1->class_ptr + 0xd8));

        bldg_get_refpt_worldloc

                  (*(undefined4 *)&param_1->field_0x274,*(undefined4 *)(dVar13 + 0x28),&fStack_254);

        fVar11 = 1.0 - (float)puStack_258;

        object_set_location(param_1,fStack_254 * (float)puStack_258 +

                                    fVar11 * *(float *)(dVar13 + 4),

                            fStack_250 * (float)puStack_258 + fVar11 * *(float *)(dVar13 + 8),

                            fStack_24c * (float)puStack_258 + fVar11 * *(float *)(dVar13 + 0xc));

      }

      else {

        param_1->pad_E4 = 3;

      }

      break;

    case 0x27:

      fVar14 = (float10)FRateGetSecsframe(param_1,0);

      fVar14 = (float10)*(float *)&param_1->field_0xec - fVar14;

      *(float *)&param_1->field_0xec = (float)fVar14;

      if (fVar14 < (float10)0.0 != (fVar14 == (float10)0.0)) {

        param_1->pad_E4 = 3;

      }

      iVar5 = meccbasepit_bldg_from_object_dup004a6200(*(undefined4 *)&param_1->field_0x274);

      if (iVar5 == 0) {

        fStack_264 = (float)base_slot10_get(*(undefined4 *)&param_1->field_0x274);

      }

      else {

        fStack_264 = (float)base_slot15_get(*(undefined4 *)&param_1->field_0x274);

      }

      bldg_get_refpt_worldloc(fStack_264,*(undefined4 *)(dVar13 + 0x28),&fStack_254);

      puStack_258 = (undefined4 *)(*(float *)&param_1->field_0xec * 0.5);

      fVar11 = 1.0 - (float)puStack_258;

      object_set_location(param_1,fStack_254 * fVar11 +

                                  (float)puStack_258 * *(float *)(dVar13 + 0x58),

                          fStack_250 * fVar11 + (float)puStack_258 * *(float *)(dVar13 + 0x5c),

                          fStack_24c * fVar11 + (float)puStack_258 * *(float *)(dVar13 + 0x60));

      if (((float)puStack_258 < 0.5) && (*(int *)(dVar13 + 0x30) == 0)) {

        dVar3 = param_1->animate_state;

        if (*(int *)(dVar3 + 0x30) != 0) {

          *(undefined4 *)(*(int *)(dVar3 + 0x30) + 0x210) = 0;

          object_destroy(*(undefined4 *)(dVar3 + 0x30));

          *(undefined4 *)(dVar3 + 0x30) = 0;

          *(undefined4 *)(dVar3 + 0x14) = 0x41d80000;

          iVar5 = reaper_0052e4a0(param_1);

          if (iVar5 != 0) {

            reaper_00530bd0(param_1,0,0,0,0x14,0);

          }

        }

        smartie_make_held_object__FP6OBJECTi(param_1,0x2f9);

        bldg_get_refpt_worldlocdir

                  (fStack_264,*(undefined4 *)(dVar13 + 0x28),(float *)(dVar13 + 0x58),

                   &param_1->field_0xc8);

        *(undefined4 *)(dVar13 + 0x28) = 10;

      }

      break;

    case 0x32:

      smartie_handle_reaper_grab__FP6OBJECTP14ObjSpecSmartie(param_1,dVar13);

      break;

    case 0x37:

      ai_clear_move_goal(param_1);

      param_1->field_0x20b = 0;

      param_1->field_0x20a = 0;

      param_1->field_0x208 = 0;

      param_1->pad_184 = 0x3f800000;

      if (DAT_00632bb8 != 0) {

        param_1->pad_184 = 0;

      }

      if (*(float *)(dVar13 + 0x18) == 0.0) {

        dVar3 = param_1->animate_state;

        iVar5 = *(int *)(dVar3 + 0x48);

        if (iVar5 != 0) {

          fx_delete(iVar5);

          *(undefined4 *)(dVar3 + 0x48) = 0;

        }

      }

      *(undefined4 *)(dVar13 + 0x18) = *(undefined4 *)(DAT_00632ed8 + 0x624);

      break;

    case 0x38:

      param_1->pad_184 = 0;

      param_1->field_0x208 = 0;

      param_1->field_0x20b = 0;

      param_1->field_0x20a = 0;

      fVar14 = (float10)FRateGetSecsframe(param_1,0);

      fVar14 = (float10)*(float *)&param_1->field_0xec - fVar14;

      *(float *)&param_1->field_0xec = (float)fVar14;

      if ((fVar14 < (float10)0.0 != (fVar14 == (float10)0.0)) &&

         (iVar5 = base_has_partyhouse(*(undefined4 *)&param_1->field_0x274), iVar5 != 0)) {

        param_1->pad_E4 = 0x1e;

      }

    }

    obj_alpha_fade_update(param_1);

    player_pitch_update(param_1);

    obj_scale_compute(param_1);

    vvel_decay_tick(param_1);

    smartie_vvel_avg_move(param_1);

    return;

  }

  if ((((dVar3 == 0x13) || (dVar3 == 0x14)) || (dVar3 == 0x32)) &&

     ((iVar5 = *(int *)&param_1->field_0x274, iVar5 != 0 &&

      (((char)((uint)*(undefined4 *)(iVar5 + 0xd8) >> 8) < '\0' ||

       (*(float *)(iVar5 + 0x1c0) <= *(float *)(iVar5 + 0x278))))))) {

    *(undefined4 *)(dVar13 + 0x54) = 0;

    if (param_1->pad_E4 == 0x32) {

      smartie_escape_reaper_grab(param_1);

    }

    else {

      iVar5 = *(int *)&param_1->field_0x274;

      smartie_unlock_from_player(param_1,iVar5,0);

      iVar6 = reaper_0052e4a0(param_1);

      if (iVar6 != 0) {

        uStack_260 = *(float *)(iVar5 + 0x188);

        uStack_25c = 0;

        reaper_00530bd0(param_1,0,2,0,5,&uStack_260);

      }

    }

  }

  if (param_1->pad_E4 != 0) goto LAB_004f015a;

  switch(*(undefined4 *)&param_1->field_0xe8) {

  case 1:

    uVar7 = param_1->coll_radius | 1;

    goto LAB_004f014e;

  case 2:

    uVar7 = param_1->coll_radius | 0x11;

    goto LAB_004f014e;

  case 3:

    uVar7 = param_1->coll_radius | 0x20;

LAB_004f014e:

    param_1->coll_radius = uVar7;

switchD_004efef7_caseD_4:

    param_1->pad_E4 = 3;

    break;

  default:

    goto switchD_004efef7_caseD_4;

  case 5:

    param_1->pad_E4 = 0x50;

    fVar14 = (float10)rndfloatrange(0x41200000,0x41a00000);

    *(float *)&param_1->field_0xf0 = (float)fVar14;

    for (puVar10 = DAT_00632d68; puVar10 != (undefined4 *)0x0; puVar10 = (undefined4 *)*puVar10) {

      iVar5 = puVar10[3];

      if (*(int *)(iVar5 + 4) == 0x3e9) {

        fStack_264 = 0.0;

        goto LAB_004f00b0;

      }

    }

    goto LAB_004f0111;

  case 6:

    param_1->pad_E4 = 0x3c;

    break;

  case 7:

    param_1->pad_E4 = 0x25;

    *(uint *)&param_1->field_0x1c8 = *(uint *)&param_1->field_0x1c8 & 0xfffdffff;

    smartie_make_held_object__FP6OBJECTi(param_1,0x314);

    ObjectSetAnim(param_1);

    break;

  case 8:

    param_1->coll_radius = param_1->coll_radius | 1;

    *(uint *)&param_1->field_0x1c8 = *(uint *)&param_1->field_0x1c8 & 0xfffdffff | 0xe00;

    goto LAB_004effe4;

  case 9:

    param_1->coll_radius = param_1->coll_radius | 1;

    *(uint *)&param_1->field_0x1c8 = *(uint *)&param_1->field_0x1c8 & 0xfffdffff | 0xe00;

LAB_004effe4:

    param_1->flags = param_1->flags | 0x10;

    ObjectSetAnim(param_1);

    param_1->pad_E4 = 0x3e;

    break;

  case 10:

    iVar5 = dialog_level_is_base_dup0052aa70();

    if (iVar5 == 0) {

      param_1->ai_state_b = 1;

      param_1->pad_E4 = 0x33;

      *(undefined4 *)(dVar13 + 0xb4) = *(undefined4 *)&param_1->field_0xc8;

      puVar10 = (undefined4 *)(dVar13 + 0xa8);

      *puVar10 = *(undefined4 *)&param_1->field_0xa0;

      *(undefined4 *)(dVar13 + 0xac) = *(undefined4 *)&param_1->field_0xa4;

      *(undefined4 *)(dVar13 + 0xb0) = *(undefined4 *)&param_1->field_0xa8;

      fVar14 = (float10)get_floor_z_point(puVar10);

      *(float *)(dVar13 + 0xb0) = (float)fVar14;

      *(undefined4 *)&param_1->field_0xa0 = *puVar10;

      *(undefined4 *)&param_1->field_0xa4 = *(undefined4 *)(dVar13 + 0xac);

      *(undefined4 *)&param_1->field_0xa8 = *(undefined4 *)(dVar13 + 0xb0);

      object_copy_posdirinfo(param_1);

    }

  }

LAB_004f015a:

  if ((param_1->coll_radius & 0x10) != 0) {

    if (0.0 <= *(float *)&param_1->field_0xec) {

      fVar14 = (float10)FRateGetSecsframe(param_1,0);

      *(float *)&param_1->field_0xec = (float)((float10)*(float *)&param_1->field_0xec - fVar14);

    }

    else {

      iVar5 = smartie_check_follow__FP6OBJECTf(param_1,0x40e00000);

      if (iVar5 != 0) {

        smartie_board_player__FP6OBJECTT0i(param_1,iVar5,1);

      }

      if (param_1->pad_E4 == 0x13) {

        param_1->coll_radius = param_1->coll_radius & 0xffffffee;

      }

    }

  }

  if ((param_1->coll_radius & 1) != 0) {

    if ((param_1->anim == 0x42) && (*(int *)&param_1->field_0x274 == 0)) {

      uVar8 = object_spawn_small(param_1,0x48,0,0,0);

      *(undefined4 *)&param_1->field_0x274 = uVar8;

    }

    if (param_1->anim != 0x2d) {

      return;

    }

    if (*(int *)&param_1->field_0x274 != 0) {

      return;

    }

    uVar8 = object_spawn_small(param_1,0x48,0,2,0);

    *(undefined4 *)&param_1->field_0x274 = uVar8;

    return;

  }

  param_1->flags = param_1->flags & 0xfcffffff;

  if ((*(int *)&param_1->field_0x210 != 0) && (param_1->pad_E4 == 3)) {

    return;

  }

  dVar3 = param_1->pad_E4;

  if ((((dVar3 == 0x22) || (dVar3 == 0x23)) || (dVar3 == 0x26)) ||

     ((dVar3 == 0x27 || (dVar3 == 0x28)))) {

    if (*(float *)(dVar13 + 0x98) != 0.0) {

      fVar14 = (float10)FRateGetSecsframe(param_1,0);

      fVar14 = (float10)*(float *)(dVar13 + 0x98) - fVar14;

      *(float *)(dVar13 + 0x98) = (float)fVar14;

      if (fVar14 < (float10)0.0 == (fVar14 == (float10)0.0)) goto LAB_004f02e2;

      iVar5 = crt_rand_scaled(100);

      if (iVar5 < 0x32) {

        iVar5 = 0x6b9;

      }

      else {

        iVar5 = 0x6ba;

      }

      sound_play_obj(iVar5);

    }

    fVar14 = (float10)rndfloatrange(0x41200000,0x41a00000);

    *(float *)(dVar13 + 0x98) = (float)fVar14;

  }

LAB_004f02e2:

  dVar3 = param_1->pad_E4;

  if (((((dVar3 == 3) || (dVar3 == 0x50)) ||

       ((dVar3 == 0x51 || ((4 < (int)dVar3 && ((int)dVar3 < 8)))))) ||

      ((0x14 < (int)dVar3 && ((int)dVar3 < 0x19)))) ||

     ((((0x1d < (int)dVar3 && ((int)dVar3 < 0x27)) || (dVar3 == 0x36)) || (dVar3 == 0x38)))) {

    uStack_260 = 10.0;

    if (*(int *)&param_1->field_0xe8 != 4) {

      uStack_260 = 7.0;

    }

    iVar5 = smartie_check_follow__FP6OBJECTf(param_1,uStack_260);

    if (iVar5 != 0) {

      smartie_board_player__FP6OBJECTT0i(param_1,iVar5,1);

    }

  }

  ANM_DumpCluster(param_1);

  switch(param_1->pad_E4) {

  case 3:

  case 4:

    fVar14 = (float10)FRateGetSecsframe(param_1,0);

    *(float *)&param_1->field_0xec = (float)((float10)*(float *)&param_1->field_0xec - fVar14);

    if ((param_1->coll_radius & 8) == 0) {

      iVar5 = dialog_level_is_base_dup0052aa70();

      if ((iVar5 == 0) && (iVar5 = ObjIsKabuto(DAT_00632a88), iVar5 != 0)) {

        uStack_260 = *(float *)(DAT_00632ed8 + 0x1578);

        fVar14 = (float10)distancesq2d__FP3P3DT0(DAT_00632a88 + 0xa0,&param_1->field_0xa0);

        if (fVar14 < (float10)uStack_260 * (float10)uStack_260) {

          fStack_23c = (float)param_1->animate_state;

          fStack_264 = 0.0;

          for (puVar10 = DAT_00632d6c; puVar10 != (undefined4 *)0x0;

              puVar10 = (undefined4 *)*puVar10) {

            fVar11 = (float)puVar10[3];

            if ((((((*(uint *)((int)fVar11 + 0xd8) & 0x4000c000) == 0) &&

                  (*(float *)((int)fVar11 + 0x278) < *(float *)((int)fVar11 + 0x1c0))) &&

                 ((*(int *)((int)fVar11 + 0x1e0) == 0x3d &&

                  (((((iVar5 = *(int *)((int)fVar11 + 4), iVar5 == 0x24e || (iVar5 == 0x250)) ||

                     (iVar5 == 0x251)) || ((iVar5 == 0x3ea || (iVar5 == 0x3eb)))) &&

                   ((*(byte *)((int)fVar11 + 0xe0) & 4) == 0)))))) &&

                (iVar5 = ANM_AnimGetImage(fVar11), iVar5 == 0)) &&

               ((fVar14 = (float10)distancesq3d((int)fVar11 + 0xa0,&param_1->field_0xa0),

                fStack_264 == 0.0 || (fVar14 <= (float10)uStack_260)))) {

              uStack_260 = (float)fVar14;

              fStack_264 = fVar11;

            }

          }

          *(float *)((int)fStack_23c + 0xa0) = fStack_264;

          if (*(int *)(dVar13 + 0xa0) != 0) {

            fStack_248 = *(float *)(DAT_00632a88 + 0xa0);

            fStack_244 = *(float *)(DAT_00632a88 + 0xa4);

            fStack_240 = *(float *)(DAT_00632a88 + 0xa8);

            normalize__FPfN20(&fStack_248,&fStack_244,&fStack_240);

            iVar5 = *(int *)(dVar13 + 0xa0);

            fVar11 = fStack_248 * *(float *)(iVar5 + 0xc4) * *(float *)(iVar5 + 0x154);

            fStack_254 = fVar11 + fVar11 + *(float *)(iVar5 + 0xa0);

            fVar11 = fStack_244 * *(float *)(iVar5 + 0xc4) * *(float *)(iVar5 + 0x154);

            fStack_250 = fVar11 + fVar11 + *(float *)(iVar5 + 0xa4);

            fVar11 = fStack_240 * *(float *)(iVar5 + 0xc4) * *(float *)(iVar5 + 0x154);

            fStack_24c = fVar11 + fVar11 + *(float *)(iVar5 + 0xa8);

            ai_moveonly_set_goal(param_1,&fStack_254);

            ai_goal_process(param_1);

            if (*(int *)&param_1->field_0x168 != 0) {

              puVar2 = (uint *)(*(int *)(dVar13 + 0xa0) + 0xe0);

              *puVar2 = *puVar2 | 4;

              param_1->pad_E4 = 0x3f;

              break;

            }

          }

        }

      }

      if (*(float *)&param_1->field_0xec < 0.0 != (*(float *)&param_1->field_0xec == 0.0)) {

        iVar5 = 0;

        do {

          iVar6 = crt_rand_scaled(100);

          uStack_260 = 1.0;

          if (0x31 < iVar6) {

            uStack_260 = -1.0;

          }

          fVar14 = (float10)rndfloatrange(0x41200000,0x42200000);

          fStack_248 = (float)(fVar14 * (float10)uStack_260 +

                              (float10)*(float *)&param_1->field_0xa0);

          iVar6 = crt_rand_scaled(100);

          fStack_23c = 1.0;

          if (0x31 < iVar6) {

            fStack_23c = -1.0;

          }

          fVar14 = (float10)rndfloatrange(0x41200000,0x42200000);

          fStack_244 = (float)(fVar14 * (float10)fStack_23c +

                              (float10)*(float *)&param_1->field_0xa4);

          fVar14 = (float10)distance2d__FP3P3DT0(&fStack_248,&param_1->field_0xa0);

          fStack_264 = (float)fVar14;

          fVar14 = (float10)ground_get_z(&fStack_248);

          fStack_240 = (float)fVar14;

          fVar14 = (fVar14 - (float10)*(float *)&param_1->field_0xa8) / (float10)fStack_264;

          if ((fVar14 < (float10)0.5) && ((float10)-0.5 < fVar14)) {

            if (iVar5 < 5) {

              ai_moveonly_set_goal(param_1,&fStack_248);

              ai_goal_process(param_1);

              if (*(int *)&param_1->field_0x168 != 0) {

                *(float *)(dVar13 + 0x58) = fStack_248;

                *(float *)(dVar13 + 0x5c) = fStack_244;

                *(float *)(dVar13 + 0x60) = fStack_240;

                param_1->pad_E4 = 5;

                *(undefined4 *)&param_1->field_0xec = 0x41200000;

                goto LAB_004f12f8;

              }

              ai_clear_move_goal(param_1);

              fVar14 = (float10)rndfloatrange(0x40a00000,0x41200000);

              param_1->pad_E4 = 3;

              goto LAB_004f12ed;

            }

            break;

          }

          iVar5 = iVar5 + 1;

        } while (iVar5 < 5);

        fVar14 = (float10)rndfloatrange(0x40a00000,0x41200000);

LAB_004f12ed:

        *(float *)&param_1->field_0xec = (float)fVar14;

      }

    }

LAB_004f12f8:

    if (*(int *)(dVar13 + 0x1c) != *(int *)(dVar13 + 0x20)) {

      *(int *)(dVar13 + 0x1c) = *(int *)(dVar13 + 0x20);

    }

    if ((*(int *)(dVar13 + 0x1c) < 0) || (*(float *)(dVar13 + 0x18) <= 0.0)) break;

    uVar8 = *(undefined4 *)&param_1->field_0x274;

    dVar13 = param_1->animate_state;

    iVar5 = meccbasepit_bldg_from_object_dup004a6200(uVar8);

    if (iVar5 == 0) goto LAB_004f287f;

    if (((*(int *)(dVar13 + 0x1c) == 0xd) &&

        (iVar5 = base_bldg_is_alive_at_all(uVar8,0xd), iVar5 != 0)) &&

       (iVar5 = slot_member_alive(uVar8,0xd), iVar5 == 0)) {

      *(undefined4 *)(dVar13 + 0x24) = 0xffffffff;

      *(undefined4 *)(dVar13 + 0x20) = 0xffffffff;

      *(undefined4 *)(dVar13 + 0x1c) = 0xffffffff;

      param_1->pad_E4 = 0x1e;

      break;

    }

    goto LAB_004f2864;

  case 5:

    ai_goal_process(param_1);

    fVar14 = (float10)FRateGetSecsframe(param_1,0);

    fVar14 = (float10)*(float *)&param_1->field_0xec - fVar14;

    *(float *)&param_1->field_0xec = (float)fVar14;

    if ((*(int *)&param_1->field_0x168 == 0) || (fVar14 < (float10)0.0 != (fVar14 == (float10)0.0)))

    {

      fVar14 = (float10)rndfloatrange(0x40a00000,0x41200000);

      *(float *)&param_1->field_0xec = (float)fVar14;

      param_1->field_0x20b = 0;

      param_1->field_0x20a = 0;

      param_1->field_0x208 = 0;

      param_1->pad_E4 = 3;

      ai_clear_move_goal(param_1);

      *(undefined4 *)(dVar13 + 0x58) = *(undefined4 *)&param_1->field_0xa0;

      *(undefined4 *)(dVar13 + 0x5c) = *(undefined4 *)&param_1->field_0xa4;

      *(undefined4 *)(dVar13 + 0x60) = *(undefined4 *)&param_1->field_0xa8;

    }

    if (*(int *)(dVar13 + 0x1c) != *(int *)(dVar13 + 0x20)) {

      *(int *)(dVar13 + 0x1c) = *(int *)(dVar13 + 0x20);

    }

    if ((*(int *)(dVar13 + 0x1c) < 0) || (*(float *)(dVar13 + 0x18) <= 0.0)) break;

    uVar8 = *(undefined4 *)&param_1->field_0x274;

    dVar13 = param_1->animate_state;

    iVar5 = meccbasepit_bldg_from_object_dup004a6200(uVar8);

    if (iVar5 != 0) {

      if (((*(int *)(dVar13 + 0x1c) == 0xd) &&

          (iVar5 = base_bldg_is_alive_at_all(uVar8,0xd), iVar5 != 0)) &&

         (iVar5 = slot_member_alive(uVar8,0xd), iVar5 == 0)) {

        *(undefined4 *)(dVar13 + 0x24) = 0xffffffff;

        *(undefined4 *)(dVar13 + 0x20) = 0xffffffff;

        *(undefined4 *)(dVar13 + 0x1c) = 0xffffffff;

        param_1->pad_E4 = 0x1e;

        break;

      }

      goto LAB_004f2864;

    }

    goto LAB_004f287f;

  case 0x13:

    pOVar18 = *(OBJECT **)&param_1->field_0x274;

    if (pOVar18 == (OBJECT *)0x0) {

      param_1->pad_E4 = 3;

      break;

    }

    iVar5 = ObjIsReaper(pOVar18);

    if (iVar5 != 0) {

      fStack_254 = *(float *)&pOVar18->field_0x298 * 5.0;

      puVar19 = &param_1->field_0xa0;

      fStack_248 = fStack_254 + *(float *)&pOVar18->field_0xa0;

      uStack_260 = *(float *)&pOVar18->field_0x2a8 * 5.0;

      fStack_244 = uStack_260 + *(float *)&pOVar18->field_0xa4;

      fStack_24c = *(float *)&pOVar18->field_0xa8 + 3.0;

      fStack_254 = *(float *)&pOVar18->field_0xa0 - fStack_254;

      fStack_250 = *(float *)&pOVar18->field_0xa4 - uStack_260;

      fStack_240 = fStack_24c;

      fVar14 = (float10)distancesq3d(puVar19,&fStack_248);

      fStack_264 = (float)fVar14;

      fVar14 = (float10)distancesq3d(puVar19,&fStack_254);

      if (fVar14 < (float10)fStack_264) {

        fStack_248 = fStack_254;

        fStack_244 = fStack_250;

        fStack_240 = fStack_24c;

      }

      if (25.0 <= fStack_264) {

        fVar11 = 0.12;

      }

      else {

        fVar11 = fStack_264 * 0.0047999998;

      }

      fVar25 = 1.0 - fVar11;

      *(undefined4 *)&param_1->field_0xc8 = *(undefined4 *)&pOVar18->field_0xc8;

      object_set_location(param_1,fVar25 * *(float *)puVar19 + fVar11 * fStack_248,

                          fVar11 * fStack_244 + fVar25 * *(float *)&param_1->field_0xa4,

                          fVar11 * fStack_240 + fVar25 * *(float *)&param_1->field_0xa8);

    }

    if (*(int *)&param_1->field_0xe8 == 10) {

      fVar14 = (float10)FRateGetSecsframe(param_1,0);

      fVar14 = fVar14 + (float10)*(float *)(dVar13 + 0x9c);

      *(float *)(dVar13 + 0x9c) = (float)fVar14;

      if (((float10)*(int *)(DAT_00632ed8 + 0x1584) < fVar14) &&

         (param_1->ai_state_b == *(dword *)(DAT_00632a88 + 0x18c))) {

        uVar8 = TextGetPtrRandom(s_SmChStillStolen_00562240,4,1);

        chat_insert_name(dVar13 + 0x80,uVar8);

        *(undefined4 *)(dVar13 + 0x9c) = 0;

      }

    }

    if ((param_1->coll_radius & 0x20) != 0) break;

    iVar5 = *(int *)&param_1->field_0xe8;

    if ((((iVar5 == 4) || (iVar5 == 10)) || (iVar5 == 5)) || (iVar5 == 2)) {

      fVar14 = (float10)FRateGetSecsframe(param_1,0);

      *(float *)&param_1->field_0xec = (float)(fVar14 + (float10)*(float *)&param_1->field_0xec);

      fVar11 = 0.0;

    }

    else if (((*(float *)&pOVar18->field_0xa0 == *(float *)&pOVar18->field_0xac) &&

             (*(float *)&pOVar18->field_0xa4 == *(float *)&pOVar18->field_0xb0)) &&

            (*(float *)&pOVar18->field_0xa8 == *(float *)&pOVar18->field_0xb4)) {

      fVar14 = (float10)FRateGetSecsframe(param_1,0);

      *(float *)&param_1->field_0xec = (float)(fVar14 + (float10)*(float *)&param_1->field_0xec);

      fVar11 = 1.0;

    }

    else {

      fVar11 = 1.0;

      *(undefined4 *)&param_1->field_0xec = 0;

    }

    if (*(float *)&param_1->field_0xec <= fVar11) break;

    iVar5 = *(int *)&param_1->field_0xe8;

    if ((iVar5 == 4) || (iVar5 == 2)) {

      uStack_260 = (float)smartie_find_legal_nearby_base__FP6OBJECTT0(param_1,pOVar18);

      if ((uStack_260 != 0.0) && (puVar10 = DAT_00632d68, DAT_00632d68 != (undefined4 *)0x0)) {

        do {

          iVar5 = puVar10[3];

          if (((*(int *)(iVar5 + 4) == 0x342) || (*(int *)(iVar5 + 4) == 0x35a)) &&

             (fVar14 = (float10)distancesq2d__FP3P3DT0(iVar5 + 0xa0,(int)uStack_260 + 0xa0),

             fVar14 <= (float10)250000.0)) goto LAB_004f1865;

          puVar10 = (undefined4 *)*puVar10;

        } while (puVar10 != (undefined4 *)0x0);

        *(undefined4 *)&param_1->field_0xec = 0;

        break;

      }

LAB_004f187e:

      *(undefined4 *)&param_1->field_0xec = 0;

    }

    else {

      if (iVar5 == 10) {

        iVar5 = 0;

        uStack_260 = 999999.0;

        piVar12 = DAT_00632d98;

        if (DAT_00632d98 == (int *)0x0) break;

        do {

          iVar6 = piVar12[3];

          if (((*(int *)(iVar6 + 0xe8) == 10) && (*(int *)(iVar6 + 0xe4) == 0x33)) &&

             (fVar14 = (float10)distancesq2d__FP3P3DT0(iVar6 + 0xa0,&param_1->field_0xa0),

             fVar14 < (float10)uStack_260)) {

            uStack_260 = (float)fVar14;

            iVar5 = iVar6;

          }

          piVar12 = (int *)*piVar12;

        } while (piVar12 != (int *)0x0);

        if ((iVar5 == 0) ||

           (fVar14 = (float10)distancesq3d(&param_1->field_0xa0,iVar5 + 0xa0),

           (float10)144.0 < fVar14)) break;

      }

      else if (iVar5 == 5) {

        puVar10 = DAT_00632d68;

        if (DAT_00632d68 != (undefined4 *)0x0) {

          do {

            iVar5 = puVar10[3];

            pOVar18 = param_1;

            if ((*(int *)(iVar5 + 4) == 0x342) || (*(int *)(iVar5 + 4) == 0x35a)) goto LAB_004f1865;

            puVar10 = (undefined4 *)*puVar10;

          } while (puVar10 != (undefined4 *)0x0);

          *(undefined4 *)&param_1->field_0xec = 0;

          break;

        }

        goto LAB_004f187e;

      }

LAB_004f17e7:

      iVar5 = *(int *)&param_1->field_0xe8;

      if ((iVar5 == 4) || ((iVar5 == 5 || (iVar5 == 2)))) {

        ObjectSetAnim(param_1);

      }

      param_1->pad_E4 = 0x14;

    }

    break;

  case 0x14:

    iVar5 = *(int *)&param_1->field_0xe8;

    iVar6 = *(int *)&param_1->field_0x274;

    if ((iVar5 == 4) || (iVar5 == 2)) {

      iVar5 = smartie_find_legal_nearby_base__FP6OBJECTT0(param_1,iVar6);

      if (iVar5 != 0) {

        iVar9 = object_spawn_class5(*(undefined4 *)(iVar6 + 0x18c),iVar5);

        if (iVar9 != 0) {

          iVar9 = ObjIsMecc(iVar6);

          if (iVar9 == 0) {

            iVar9 = ObjIsReaper(iVar6);

            if (iVar9 != 0) {

              *(int *)(*(int *)(iVar6 + 0x100) + 0xcfc) = iVar5;

            }

          }

          else {

            *(int *)(*(int *)(iVar6 + 0x100) + 0xd8) = iVar5;

          }

        }

        iVar9 = reaper_0052e4a0(param_1);

        if (iVar9 != 0) {

          uStack_260 = *(float *)(iVar6 + 0x188);

          uStack_25c = *(undefined4 *)(iVar5 + 0x188);

          reaper_00530bd0(param_1,0,2,0,4,&uStack_260);

        }

        smartie_attach_to_base(param_1,iVar6,iVar5);

      }

      break;

    }

    if (iVar5 != 10) {

      smartie_unlock_from_player(param_1,iVar6,0);

      iVar5 = reaper_0052e4a0(param_1);

      if (iVar5 != 0) {

        uStack_260 = *(float *)(iVar6 + 0x188);

        uStack_25c = 0;

        reaper_00530bd0(param_1,0,2,0,4,&uStack_260);

      }

      break;

    }

    smartie_unlock_from_player(param_1,iVar6,0);

    iVar5 = reaper_0052e4a0(param_1);

    if (iVar5 != 0) {

      uStack_260 = *(float *)(iVar6 + 0x188);

      uStack_25c = 0;

      reaper_00530bd0(param_1,0,2,0,4,&uStack_260);

    }

    iVar5 = team_base_find(param_1->ai_state_b);

    if (iVar5 == 0) break;

    comm_death_packet_build

              (iVar6,0,*(int *)(iVar6 + 0x18c) + -1,*(int *)(iVar5 + 0x18c) + -1,(float)DAT_00632f28

               ,0x3f800000,0,0);

    rpman_move(iVar6,*(int *)(iVar5 + 0x18c) + -1);

    objtype_setup_vimp(param_1,iVar5);

    iVar6 = reaper_0052e4a0(param_1);

    if (iVar6 == 0) break;

    uStack_260 = *(float *)(iVar5 + 0x188);

LAB_004f19e6:

    reaper_00530bd0(param_1,0,1,0,8,&uStack_260);

    break;

  case 0x1e:

    iVar5 = *(int *)&param_1->field_0x274;

    if ((iVar5 != 0) && ((param_1->flags & 0x80000) != 0)) {

      param_1->flags = param_1->flags | 0x10;

      iVar6 = meccbasepit_bldg_from_object_dup004a6200(iVar5);

      if (iVar6 == 0) {

        iVar6 = reaperbase_bldg_from_object(iVar5);

        if (iVar6 == 0) break;

        puStack_258 = (undefined4 *)(dVar13 + 0x28);

        iVar6 = objtype_anim_scan_2(iVar5,param_1,puStack_258);

      }

      else {

        puStack_258 = (undefined4 *)(dVar13 + 0x28);

        iVar6 = objtype_anim_scan(iVar5,param_1,puStack_258);

      }

      if (iVar6 != 0) {

        fStack_264 = 999.0;

        iVar6 = base_has_partyhouse(iVar5);

        if (iVar6 == 0) {

          uVar8 = base_get_base_building(iVar5);

          pfVar1 = (float *)(dVar13 + 0x58);

          bldg_get_refpt_worldlocdir(uVar8,*puStack_258,pfVar1,&fStack_264);

          slot_matrix_get(uVar8,*puStack_258,&uStack_260,&fStack_23c);

          *pfVar1 = *pfVar1 - uStack_260 * 12.0;

          *(float *)(dVar13 + 0x5c) = *(float *)(dVar13 + 0x5c) - fStack_23c * 12.0;

          param_1->pad_E4 = 0x1f;

        }

        else {

          iVar6 = base_get_base_building(iVar5);

          *(undefined4 *)(dVar13 + 0x58) = *(undefined4 *)(iVar5 + 0xa0);

          *(undefined4 *)(dVar13 + 0x5c) = *(undefined4 *)(iVar5 + 0xa4);

          *(undefined4 *)(dVar13 + 0x60) = *(undefined4 *)(iVar5 + 0xa8);

          param_1->pad_E4 = 0x36;

          if (iVar6 != 0) {

            *puStack_258 = 0xd;

            bldg_get_refpt_worldlocdir(iVar6,0xd,(undefined4 *)(dVar13 + 0x58),&fStack_264);

          }

        }

        if (fStack_264 == 999.0) {

          ai_moveonly_set_goal(param_1,dVar13 + 0x58);

        }

        else {

          main_ai_move_004014b0(param_1,dVar13 + 0x58,fStack_264);

        }

      }

    }

    break;

  case 0x1f:

  case 0x36:

    *(int *)(dVar13 + 0x1c) = *(int *)(dVar13 + 0x20);

    if ((*(int *)(dVar13 + 0x20) < 0) || (*(float *)(dVar13 + 0x18) <= 0.0)) {

      fStack_264 = (float)param_1->animate_state;

      iVar5 = base_get_smartie_building(param_1);

      if ((iVar5 != 0) && (iVar5 = obj_maxspeed_lookup(iVar5,0), iVar5 != 0)) {

        iVar5 = ai_anim_select_mode(param_1,*(undefined4 *)((int)fStack_264 + 0x1c));

        if (iVar5 < 0) {

          *(undefined4 *)((int)fStack_264 + 0x24) = 0xffffffff;

          *(undefined4 *)((int)fStack_264 + 0x20) = 0xffffffff;

          *(undefined4 *)((int)fStack_264 + 0x1c) = 0xffffffff;

        }

        else {

          iVar6 = base_slot_built_check(*(undefined4 *)&param_1->field_0x274,iVar5);

          if (iVar6 == 0) {

            bldg_spawn_by_type(*(undefined4 *)&param_1->field_0x274,iVar5);

          }

          reaper_lock_short(*(undefined4 *)&param_1->field_0x274,iVar5,param_1,1);

          *(int *)((int)fStack_264 + 0x20) = iVar5;

          *(int *)((int)fStack_264 + 0x1c) = iVar5;

        }

      }

      dVar3 = param_1->animate_state;

      iVar5 = ai_goal_process(param_1);

      if (iVar5 == -1) {

        ai_clear_move_goal(param_1);

        ai_move_force_goal(param_1,dVar3 + 0x58);

        ai_goal_process(param_1);

      }

      puVar10 = (undefined4 *)(dVar13 + 0x58);

      fVar14 = (float10)distancesq2d__FP3P3DT0(puVar10,&param_1->field_0xa0);

      if ((fVar14 < (float10)16.0) || (*(int *)&param_1->field_0x168 == 0)) {

        ai_clear_move_goal(param_1);

        param_1->field_0x20b = 0;

        param_1->field_0x20a = 0;

        param_1->field_0x208 = 0;

        iVar5 = *(int *)(dVar13 + 0x28);

        if (param_1->pad_E4 == 0x1f) {

          if ((((iVar5 == 10) || (iVar5 == 0xb)) || (iVar5 == 0xc)) ||

             ((iVar5 == 0xd || (iVar5 == 0xe)))) {

            uVar8 = *(undefined4 *)&param_1->field_0x274;

            meccbasepit_bldg_from_object_dup004a6200(uVar8);

            ObjectSetAnim(param_1);

            iVar5 = meccbasepit_bldg_from_object_dup004a6200(uVar8);

            if (iVar5 != 0) {

              meccbasepit_create_food(uVar8,*(undefined4 *)(dVar13 + 0x28));

            }

            uVar8 = base_get_base_building(uVar8);

            mat_facing_angle_get(uVar8,*(undefined4 *)(dVar13 + 0x28),&param_1->field_0xc8);

            param_1->pad_E4 = 0x21;

            *(undefined4 *)(dVar13 + 4) = *(undefined4 *)&param_1->field_0xa0;

            *(undefined4 *)(dVar13 + 8) = *(undefined4 *)&param_1->field_0xa4;

            *(undefined4 *)(dVar13 + 0xc) = *(undefined4 *)&param_1->field_0xa8;

            iVar5 = reaper_0052e4a0(param_1);

            if (iVar5 != 0) {

              uStack_235 = *(undefined1 *)(dVar13 + 0x28);

              reaper_00530bd0(param_1,0,0,1,0x11,&uStack_235);

            }

          }

          else {

            param_1->pad_E4 = 0x1e;

          }

        }

        else if (iVar5 == 0xd) {

          iVar5 = *(int *)&param_1->field_0x274;

          iVar6 = base_get_base_building(iVar5);

          *puVar10 = *(undefined4 *)(iVar5 + 0xa0);

          *(undefined4 *)(dVar13 + 0x5c) = *(undefined4 *)(iVar5 + 0xa4);

          *(undefined4 *)(dVar13 + 0x60) = *(undefined4 *)(iVar5 + 0xa8);

          *(undefined4 *)(dVar13 + 0x28) = 0xe;

          if (iVar6 != 0) {

            bldg_get_refpt_worldloc(iVar6,0xe,puVar10);

          }

          ai_move_force_goal(param_1,puVar10);

        }

        else if (iVar5 == 0xe) {

          param_1->pad_E4 = 0x37;

          smartie_make_held_object__FP6OBJECTi(param_1,0x2f2);

          uVar22 = 0x3f2aaaab;

          uVar21 = 0;

          uVar20 = 0;

          uVar17 = 0x20;

          uVar8 = 0x41;

          pOVar18 = param_1;

          ObjectSetAnim(param_1);

          iVar5 = reaper_0052e4a0(param_1,pOVar18,uVar8,uVar17,uVar20,uVar21,uVar22);

          if (iVar5 != 0) {

            reaper_00530bd0(param_1,0,0,0,0xb,0);

          }

        }

      }

      break;

    }

    ai_clear_move_goal(param_1);

    bldg_slot_action_dispatch(*(undefined4 *)&param_1->field_0x274,param_1);

    *(undefined4 *)(dVar13 + 0x28) = 0xffffffff;

    uVar8 = *(undefined4 *)&param_1->field_0x274;

    dVar13 = param_1->animate_state;

    iVar5 = meccbasepit_bldg_from_object_dup004a6200(uVar8);

    goto LAB_004f2824;

  case 0x21:

    fVar11 = *(float *)&param_1->field_0x274;

    uStack_260 = 0.0;

    fStack_23c = 0.0;

    fStack_264 = fVar11;

    if (param_1->anim == 0x5c) {

      uVar8 = base_get_base_building(fVar11);

      bldg_get_refpt_worldloc(uVar8,*(undefined4 *)(dVar13 + 0x28),&fStack_254);

      object_set_location_p3d(param_1,&fStack_254);

      break;

    }

    if (param_1->anim == 0x34) {

      fStack_264 = (float)param_1->pad_14 / **(float **)(param_1->class_ptr + 0xd8);

      bldg_get_refpt_worldloc(fVar11,*(undefined4 *)(dVar13 + 0x28),&fStack_254);

      fVar23 = 1.0 - fStack_264;

      fVar11 = fStack_24c * fStack_264 + fVar23 * *(float *)(dVar13 + 0xc);

      fVar25 = fStack_250 * fStack_264 + fVar23 * *(float *)(dVar13 + 8);

      fVar23 = fStack_254 * fStack_264 + fVar23 * *(float *)(dVar13 + 4);

      goto LAB_004f35c0;

    }

    puStack_258 = (undefined4 *)param_1->animate_state;

    iVar5 = base_get_smartie_building(param_1);

    if ((iVar5 != 0) && (iVar5 = obj_maxspeed_lookup(iVar5,0), iVar5 != 0)) {

      iVar5 = ai_anim_select_mode(param_1,puStack_258[7]);

      if (iVar5 < 0) {

        puStack_258[9] = 0xffffffff;

        puStack_258[8] = 0xffffffff;

        puStack_258[7] = 0xffffffff;

        fVar11 = fStack_264;

      }

      else {

        iVar6 = base_slot_built_check(*(undefined4 *)&param_1->field_0x274,iVar5);

        if (iVar6 == 0) {

          bldg_spawn_by_type(*(undefined4 *)&param_1->field_0x274,iVar5);

        }

        reaper_lock_short(*(undefined4 *)&param_1->field_0x274,iVar5,param_1,1);

        puStack_258[8] = iVar5;

        puStack_258[7] = iVar5;

        fVar11 = fStack_264;

      }

    }

    if (*(float *)(dVar13 + 0x18) < *(float *)(DAT_00632ed8 + 0x624)) {

      fVar14 = (float10)FRateGetSecsframe(param_1,0);

      uStack_260 = (float)((fVar14 * (float10)*(float *)(DAT_00632ed8 + 0x624)) /

                          (float10)*(float *)(DAT_00632ed8 + 0x5bc));

      fVar14 = (float10)obj_speed_clamp(fVar11,uStack_260);

      fStack_23c = (float)fVar14;

    }

    if (*(float *)(dVar13 + 0x18) == 0.0) {

      dVar3 = param_1->animate_state;

      iVar5 = *(int *)(dVar3 + 0x48);

      if (iVar5 != 0) {

        fx_delete(iVar5);

        *(undefined4 *)(dVar3 + 0x48) = 0;

      }

    }

    fVar11 = fStack_23c + *(float *)(dVar13 + 0x18);

    *(float *)(dVar13 + 0x18) = fVar11;

    if (*(float *)(DAT_00632ed8 + 0x624) < fVar11) {

      *(undefined4 *)(dVar13 + 0x18) = *(undefined4 *)(DAT_00632ed8 + 0x624);

    }

    if ((*(float *)(DAT_00632ed8 + 0x624) != *(float *)(dVar13 + 0x18)) &&

       (uStack_260 <= fStack_23c)) break;

    dVar3 = param_1->animate_state;

    if (*(int *)(dVar3 + 0x30) != 0) {

      *(undefined4 *)(*(int *)(dVar3 + 0x30) + 0x210) = 0;

      object_destroy(*(undefined4 *)(dVar3 + 0x30));

      *(undefined4 *)(dVar3 + 0x30) = 0;

      *(undefined4 *)(dVar3 + 0x14) = 0x41d80000;

      iVar5 = reaper_0052e4a0(param_1);

      if (iVar5 != 0) {

        reaper_00530bd0(param_1,0,0,0,0x14,0);

      }

    }

    fVar11 = fStack_264;

    if (*(float *)(DAT_00632ed8 + 0x624) == *(float *)(dVar13 + 0x18)) {

      bldg_slot_action_dispatch(fStack_264,param_1);

      *(undefined4 *)(dVar13 + 0x28) = 0xffffffff;

      iVar5 = base_has_partyhouse(fVar11);

      param_1->pad_E4 = (-(uint)(iVar5 != 0) & 0xfffffffa) + 0x24;

      break;

    }

    *(int *)(dVar13 + 0x1c) = *(int *)(dVar13 + 0x20);

    if ((*(int *)(dVar13 + 0x20) < 0) || (*(float *)(dVar13 + 0x18) <= 0.0)) break;

    bldg_slot_action_dispatch(fStack_264,param_1);

    *(undefined4 *)(dVar13 + 0x28) = 0xffffffff;

    uVar8 = *(undefined4 *)&param_1->field_0x274;

    dVar13 = param_1->animate_state;

    iVar5 = meccbasepit_bldg_from_object_dup004a6200(uVar8);

    goto LAB_004f2824;

  case 0x22:

    if (*(int *)(dVar13 + 0x1c) != *(int *)(dVar13 + 0x20)) {

      ai_clear_move_goal(param_1);

      param_1->field_0x20b = 0;

      param_1->field_0x20a = 0;

      param_1->field_0x208 = 0;

      *(undefined4 *)(dVar13 + 0x1c) = *(undefined4 *)(dVar13 + 0x20);

    }

    iVar5 = base_get_smartie_building(param_1);

    if (iVar5 == 0) break;

    iVar6 = obj_maxspeed_lookup(iVar5,0);

    if (iVar6 == 0) {

      if (*(int *)&param_1->field_0x168 == 0) {

        iVar6 = NAM_DictionaryGetTotalNames(*(undefined4 *)&param_1->field_0x274);

        iVar9 = meccbasepit_bldg_from_object_dup004a6200(*(undefined4 *)&param_1->field_0x274);

        if (iVar9 != 0) {

          if (iVar6 == 0) {

            uVar8 = 0x2f9;

          }

          else if (iVar6 == 1) {

            uVar8 = 0x30e;

          }

          else {

            uVar8 = 0x30f;

          }

          smartie_make_held_object__FP6OBJECTi(param_1,uVar8);

        }

        iVar6 = *(int *)(iVar5 + 0x2d8);

        if (iVar6 < 2) {

          crt_sprintf(auStack_200,s_Obj_type__d_has_no_building_ref_p_00562144,

                      *(undefined4 *)(iVar5 + 4));

          error_msg_show(auStack_200);

          *(undefined4 *)(dVar13 + 0x1c) = 0xffffffff;

          *(undefined4 *)(dVar13 + 0x24) = 0xffffffff;

          *(undefined4 *)(dVar13 + 0x20) = 0xffffffff;

          param_1->pad_E4 = 0x1e;

        }

        else {

          if (iVar6 < 10) {

            iVar6 = iVar6 + -1;

          }

          else {

            iVar6 = 9;

          }

          uVar8 = rndintrange(1,iVar6);

          *(undefined4 *)(dVar13 + 0x28) = uVar8;

          bldg_get_refpt_worldloc(iVar5,uVar8,dVar13 + 0x58);

          ai_moveonly_set_goal(param_1,dVar13 + 0x58);

        }

      }

      else {

        dVar3 = param_1->animate_state;

        iVar6 = ai_goal_process(param_1);

        if (iVar6 == -1) {

          ai_clear_move_goal(param_1);

          ai_move_force_goal(param_1,dVar3 + 0x58);

          ai_goal_process(param_1);

        }

        if (*(int *)&param_1->field_0x168 == 0) {

          dVar3 = param_1->animate_state;

          param_1->pad_E4 = 0x23;

          if (*(int *)(dVar3 + 0x30) != 0) {

            *(undefined4 *)(*(int *)(dVar3 + 0x30) + 0x210) = 0;

            object_destroy(*(undefined4 *)(dVar3 + 0x30));

            *(undefined4 *)(dVar3 + 0x30) = 0;

            *(undefined4 *)(dVar3 + 0x14) = 0x41d80000;

            iVar6 = reaper_0052e4a0(param_1);

            if (iVar6 != 0) {

              reaper_00530bd0(param_1,0,0,0,0x14,0);

            }

          }

          bldg_get_refpt_worldlocdir

                    (iVar5,*(undefined4 *)(dVar13 + 0x28),&fStack_254,&param_1->field_0xc8);

          object_set_location_p3d(param_1,&fStack_254);

          *(undefined4 *)&param_1->field_0xec = 0x3fc00000;

          iVar5 = meccbasepit_bldg_from_object_dup004a6200(*(undefined4 *)&param_1->field_0x274);

          if (iVar5 == 0) {

            iVar5 = reaperbase_bldg_from_object(*(undefined4 *)&param_1->field_0x274);

            if (iVar5 != 0) {

              uVar8 = sound_get_free_sequence__Fv();

              *(undefined4 *)(dVar13 + 0xb8) = uVar8;

            }

          }

          else {

            uVar26 = 1;

            uVar24 = 0;

            uVar22 = 0x576;

            uVar21 = 0;

            uVar20 = 0x575;

            uVar17 = 0x577;

            pOVar18 = param_1;

            uVar8 = sound_get_free_sequence__Fv();

            *(undefined4 *)(dVar13 + 0xb8) = uVar8;

            make_dust_ball(&param_1->field_0xa0,0x3f000000,uVar17,uVar20,uVar21,uVar22,pOVar18,

                           uVar24,uVar26);

          }

        }

      }

      break;

    }

    ai_clear_move_goal(param_1);

    dVar3 = param_1->animate_state;

    if (*(int *)(dVar3 + 0x30) != 0) {

      *(undefined4 *)(*(int *)(dVar3 + 0x30) + 0x210) = 0;

      object_destroy(*(undefined4 *)(dVar3 + 0x30));

      *(undefined4 *)(dVar3 + 0x30) = 0;

      *(undefined4 *)(dVar3 + 0x14) = 0x41d80000;

      iVar5 = reaper_0052e4a0(param_1);

      if (iVar5 != 0) {

        reaper_00530bd0(param_1,0,0,0,0x14,0);

      }

    }

    param_1->field_0x20b = 0;

    param_1->field_0x20a = 0;

    param_1->field_0x208 = 0;

    iVar5 = ai_anim_select_mode(param_1,*(undefined4 *)(dVar13 + 0x1c));

    if (iVar5 < 0) {

      *(undefined4 *)(dVar13 + 0x24) = 0xffffffff;

      *(undefined4 *)(dVar13 + 0x20) = 0xffffffff;

      *(undefined4 *)(dVar13 + 0x1c) = 0xffffffff;

    }

    else {

      iVar6 = base_slot_built_check(*(undefined4 *)&param_1->field_0x274,iVar5);

      if (iVar6 == 0) {

        bldg_spawn_by_type(*(undefined4 *)&param_1->field_0x274,iVar5);

        reaper_lock_short(*(undefined4 *)&param_1->field_0x274,iVar5,param_1,1);

      }

      *(int *)(dVar13 + 0x20) = iVar5;

      *(int *)(dVar13 + 0x1c) = iVar5;

    }

    *(undefined4 *)(dVar13 + 0x28) = 0xffffffff;

    if ((-1 < *(int *)(dVar13 + 0x1c)) && (0.0 < *(float *)(dVar13 + 0x18))) {

      param_1->pad_E4 = 0x22;

      break;

    }

    if (*(float *)(DAT_00632ed8 + 0x624) == *(float *)(dVar13 + 0x18)) {

      fVar11 = *(float *)&param_1->field_0x274;

LAB_004f32da:

      iVar5 = base_has_partyhouse(fVar11);

      if (iVar5 == 0) {

        param_1->pad_E4 = 0x24;

        break;

      }

    }

    goto LAB_004f2855;

  case 0x23:

    if (*(int *)(dVar13 + 0x1c) != *(int *)(dVar13 + 0x20)) {

      ai_clear_move_goal();

      dVar3 = param_1->animate_state;

      param_1->field_0x20b = 0;

      param_1->field_0x20a = 0;

      param_1->field_0x208 = 0;

      if (*(int *)(dVar3 + 0x30) != 0) {

        *(undefined4 *)(*(int *)(dVar3 + 0x30) + 0x210) = 0;

        object_destroy(*(undefined4 *)(dVar3 + 0x30));

        *(undefined4 *)(dVar3 + 0x30) = 0;

        *(undefined4 *)(dVar3 + 0x14) = 0x41d80000;

        iVar5 = reaper_0052e4a0(param_1);

        if (iVar5 != 0) {

          reaper_00530bd0(param_1,0,0,0,0x14,0);

        }

      }

      *(undefined4 *)(dVar13 + 0x1c) = *(undefined4 *)(dVar13 + 0x20);

      uVar8 = *(undefined4 *)&param_1->field_0x274;

      dVar3 = param_1->animate_state;

      iVar5 = meccbasepit_bldg_from_object_dup004a6200(uVar8);

      if (iVar5 == 0) {

        iVar5 = reaperbase_bldg_from_object(uVar8);

        if ((iVar5 != 0) && (-1 < *(int *)(dVar3 + 0x1c))) {

          param_1->pad_E4 = 0x22;

        }

      }

      else {

        if (((*(int *)(dVar3 + 0x1c) == 0xd) &&

            (iVar5 = base_bldg_is_alive_at_all(uVar8,0xd), iVar5 != 0)) &&

           (iVar5 = slot_member_alive(uVar8,0xd), iVar5 == 0)) {

          *(undefined4 *)(dVar3 + 0x24) = 0xffffffff;

          *(undefined4 *)(dVar3 + 0x20) = 0xffffffff;

          *(undefined4 *)(dVar3 + 0x1c) = 0xffffffff;

          param_1->pad_E4 = 0x1e;

          sound_interrupt_sequence(dVar13 + 0xb8);

          break;

        }

        if (-1 < *(int *)(dVar3 + 0x1c)) {

          param_1->pad_E4 = 0x26;

          sound_interrupt_sequence(dVar13 + 0xb8);

          break;

        }

      }

      sound_interrupt_sequence(dVar13 + 0xb8);

      break;

    }

    iVar5 = base_get_smartie_building(param_1);

    if (iVar5 == 0) {

      sound_interrupt_sequence(dVar13 + 0xb8);

      break;

    }

    iVar6 = obj_maxspeed_lookup(iVar5,0);

    if (iVar6 == 0) {

      param_1->field_0x20b = 0;

      param_1->field_0x20a = 0;

      param_1->field_0x208 = 0;

      fVar14 = (float10)FRateGetSecsframe(param_1,0);

      fVar14 = (fVar14 * (float10)*(float *)(DAT_00632ed8 + 0x624)) /

               (float10)*(float *)(DAT_00632ed8 + 0x5c0);

      uStack_260 = (float)fVar14;

      if ((float10)*(float *)(dVar13 + 0x18) < fVar14) {

        uStack_260 = *(float *)(dVar13 + 0x18);

      }

      iVar6 = ObjIsMeccBldg(iVar5);

      if (((iVar6 == 0) || ((*(int *)(dVar13 + 0x1c) != 0 && (*(int *)(dVar13 + 0x1c) != 1)))) &&

         ((iVar6 = ObjIsReaperBldg(iVar5), iVar6 == 0 ||

          ((*(int *)(dVar13 + 0x1c) != 0 && (*(int *)(dVar13 + 0x1c) != 1)))))) {

        *(float *)(dVar13 + 0x18) = *(float *)(dVar13 + 0x18) - uStack_260;

      }

      if ((*(float *)(dVar13 + 0x18) < 0.0 != (*(float *)(dVar13 + 0x18) == 0.0)) &&

         (((iVar6 = ObjIsMeccBldg(iVar5), iVar6 != 0 && (*(int *)(dVar13 + 0x1c) == 0xd)) ||

          ((iVar6 = ObjIsReaperBldg(iVar5), iVar6 != 0 && (*(int *)(dVar13 + 0x1c) == 8)))))) {

        *(undefined4 *)(dVar13 + 0x18) = 0x41200000;

      }

      iVar6 = obj_maxspeed_lookup(iVar5,uStack_260);

      if (iVar6 == 0) {

        if (*(float *)(dVar13 + 0x18) != 0.0) {

          iVar6 = meccbasepit_bldg_from_object_dup004a6200(*(undefined4 *)&param_1->field_0x274);

          if (iVar6 != 0) {

            iVar6 = crt_rand_scaled(100);

            if (iVar6 < 0x21) {

              uVar8 = 0x2f4;

            }

            else if (iVar6 < 0x42) {

              uVar8 = 0x2f3;

            }

            else {

              uVar8 = 0x2f1;

            }

            smartie_make_held_object__FP6OBJECTi(param_1,uVar8);

            fVar14 = (float10)FRateGetSecsframe(param_1,0);

            fVar14 = (float10)*(float *)&param_1->field_0xec - fVar14;

            *(float *)&param_1->field_0xec = (float)fVar14;

            if (fVar14 < (float10)0.0 != (fVar14 == (float10)0.0)) {

              sound_interrupt_sequence(dVar13 + 0xb8);

              if (*(int *)(iVar5 + 0x2d8) < 10) {

                iVar5 = *(int *)(iVar5 + 0x2d8) + -1;

              }

              else {

                iVar5 = 9;

              }

              uVar8 = rndintrange(1,iVar5);

              *(undefined4 *)(dVar13 + 0x28) = uVar8;

              *(undefined4 *)(dVar13 + 0x58) = *(undefined4 *)&param_1->field_0xa0;

              *(undefined4 *)(dVar13 + 0x5c) = *(undefined4 *)&param_1->field_0xa4;

              *(undefined4 *)(dVar13 + 0x60) = *(undefined4 *)&param_1->field_0xa8;

              param_1->pad_E4 = 0x28;

              *(undefined4 *)&param_1->field_0xec = 0;

            }

          }

          break;

        }

        sound_interrupt_sequence(dVar13 + 0xb8);

        dVar3 = param_1->animate_state;

        if (*(int *)(dVar3 + 0x30) != 0) {

          *(undefined4 *)(*(int *)(dVar3 + 0x30) + 0x210) = 0;

          object_destroy(*(undefined4 *)(dVar3 + 0x30));

          *(undefined4 *)(dVar3 + 0x30) = 0;

          *(undefined4 *)(dVar3 + 0x14) = 0x41d80000;

          iVar5 = reaper_0052e4a0(param_1);

          if (iVar5 != 0) {

            reaper_00530bd0(param_1,0,0,0,0x14,0);

          }

        }

        dVar3 = param_1->animate_state;

        iVar5 = *(int *)(dVar3 + 0x48);

        if (iVar5 != 0) {

          fx_delete(iVar5);

          *(undefined4 *)(dVar3 + 0x48) = 0;

        }

        *(undefined4 *)(dVar13 + 0x28) = 0xffffffff;

        goto LAB_004f338e;

      }

    }

    sound_interrupt_sequence(dVar13 + 0xb8);

    dVar3 = param_1->animate_state;

    if (*(int *)(dVar3 + 0x30) != 0) {

      *(undefined4 *)(*(int *)(dVar3 + 0x30) + 0x210) = 0;

      object_destroy(*(undefined4 *)(dVar3 + 0x30));

      *(undefined4 *)(dVar3 + 0x30) = 0;

      *(undefined4 *)(dVar3 + 0x14) = 0x41d80000;

      iVar5 = reaper_0052e4a0(param_1);

      if (iVar5 != 0) {

        reaper_00530bd0(param_1,0,0,0,0x14,0);

      }

    }

    iVar5 = ai_anim_select_mode(param_1,*(undefined4 *)(dVar13 + 0x1c));

    if (iVar5 < 0) {

      *(undefined4 *)(dVar13 + 0x24) = 0xffffffff;

      *(undefined4 *)(dVar13 + 0x20) = 0xffffffff;

      *(undefined4 *)(dVar13 + 0x1c) = 0xffffffff;

    }

    else {

      iVar6 = base_slot_built_check(*(undefined4 *)&param_1->field_0x274,iVar5);

      if (iVar6 == 0) {

        bldg_spawn_by_type(*(undefined4 *)&param_1->field_0x274,iVar5);

        reaper_lock_short(*(undefined4 *)&param_1->field_0x274,iVar5,param_1,1);

      }

      *(int *)(dVar13 + 0x20) = iVar5;

      *(int *)(dVar13 + 0x1c) = iVar5;

    }

    *(undefined4 *)(dVar13 + 0x28) = 0xffffffff;

    if ((-1 < *(int *)(dVar13 + 0x1c)) && (0.0 < *(float *)(dVar13 + 0x18))) {

      param_1->pad_E4 = 0x22;

      break;

    }

    if (*(float *)(DAT_00632ed8 + 0x624) == *(float *)(dVar13 + 0x18)) {

      fVar11 = *(float *)&param_1->field_0x274;

      goto LAB_004f32da;

    }

    goto LAB_004f2855;

  case 0x24:

    if ((param_1->flags & 0x80000) == 0) break;

    param_1->flags = param_1->flags | 0x10;

    *(int *)(dVar13 + 0x1c) = *(int *)(dVar13 + 0x20);

    if (*(int *)(dVar13 + 0x20) < 0) {

      iVar5 = base_has_partyhouse(*(undefined4 *)&param_1->field_0x274);

      if (iVar5 == 0) {

        if (*(int *)&param_1->field_0x168 == 0) {

          iVar5 = meccbasepit_bldg_from_object_dup004a6200(*(undefined4 *)&param_1->field_0x274);

          if (iVar5 == 0) {

            iVar5 = reaperbase_bldg_from_object(*(undefined4 *)&param_1->field_0x274);

            fVar11 = uStack_260;

            if (iVar5 != 0) {

              iVar5 = smartie_house_scan(param_1,dVar13 + 0x28);

              *(int *)(dVar13 + 0x2c) = iVar5;

              if (iVar5 == -1) break;

              fVar11 = (float)smartie_house_get(*(undefined4 *)&param_1->field_0x274,iVar5);

            }

          }

          else {

            iVar5 = master_flagslot_claim(param_1,dVar13 + 0x28);

            *(int *)(dVar13 + 0x2c) = iVar5;

            if (iVar5 == -1) break;

            fVar11 = (float)meccbasepit_get_table_ptr(*(undefined4 *)&param_1->field_0x274,iVar5);

          }

          bldg_get_refpt_worldloc(fVar11,*(undefined4 *)(dVar13 + 0x28),dVar13 + 0x58);

          ai_moveonly_set_goal(param_1,dVar13 + 0x58);

        }

        else {

          dVar3 = param_1->animate_state;

          iVar5 = ai_goal_process(param_1);

          if (iVar5 == -1) {

            ai_clear_move_goal(param_1);

            ai_move_force_goal(param_1,dVar3 + 0x58);

            ai_goal_process(param_1);

          }

          if (*(int *)&param_1->field_0x168 == 0) {

            param_1->pad_E4 = 0x25;

            *(undefined4 *)&param_1->field_0xa0 = *(undefined4 *)(dVar13 + 0x58);

            *(undefined4 *)&param_1->field_0xa4 = *(undefined4 *)(dVar13 + 0x5c);

            *(undefined4 *)&param_1->field_0xa8 = *(undefined4 *)(dVar13 + 0x60);

            param_1->field_0x20b = 0;

            param_1->field_0x20a = 0;

            param_1->field_0x208 = 0;

            iVar5 = meccbasepit_bldg_from_object_dup004a6200(*(undefined4 *)&param_1->field_0x274);

            if (iVar5 == 0) {

              uVar8 = smartie_house_get(*(undefined4 *)&param_1->field_0x274,

                                        *(undefined4 *)(dVar13 + 0x2c),

                                        *(undefined4 *)(dVar13 + 0x28),&param_1->field_0xc8);

              mat_facing_angle_get(uVar8);

              ObjectSetAnim(param_1);

            }

            else {

              uVar8 = meccbasepit_get_table_ptr

                                (*(undefined4 *)&param_1->field_0x274,*(undefined4 *)(dVar13 + 0x2c)

                                 ,*(undefined4 *)(dVar13 + 0x28),&param_1->field_0xc8);

              mat_facing_angle_get(uVar8);

              smartie_make_held_object__FP6OBJECTi(param_1,0x2f2);

              ObjectSetAnim(param_1);

            }

          }

        }

        break;

      }

      ai_clear_move_goal(param_1);

      *(undefined4 *)(dVar13 + 0x2c) = 0xffffffff;

      *(undefined4 *)(dVar13 + 0x28) = 0xffffffff;

      dVar13 = param_1->animate_state;

      param_1->pad_E4 = 0x1e;

      if (*(int *)(dVar13 + 0x30) == 0) break;

      *(undefined4 *)(*(int *)(dVar13 + 0x30) + 0x210) = 0;

      uVar8 = *(undefined4 *)(dVar13 + 0x30);

      goto LAB_004f26f2;

    }

    ai_clear_move_goal(param_1);

    dVar3 = param_1->animate_state;

    if (*(int *)(dVar3 + 0x30) != 0) {

      *(undefined4 *)(*(int *)(dVar3 + 0x30) + 0x210) = 0;

      object_destroy(*(undefined4 *)(dVar3 + 0x30));

      *(undefined4 *)(dVar3 + 0x30) = 0;

      *(undefined4 *)(dVar3 + 0x14) = 0x41d80000;

      iVar5 = reaper_0052e4a0(param_1);

      if (iVar5 != 0) {

        reaper_00530bd0(param_1,0,0,0,0x14,0);

      }

    }

    iVar5 = meccbasepit_bldg_from_object_dup004a6200(*(undefined4 *)&param_1->field_0x274);

    if (iVar5 == 0) {

      iVar5 = reaperbase_bldg_from_object(*(undefined4 *)&param_1->field_0x274);

      if (iVar5 != 0) {

        food_object_flag_clear

                  (param_1,*(undefined4 *)(dVar13 + 0x2c),*(undefined4 *)(dVar13 + 0x28));

      }

    }

    else {

      master_flag_bit_clear(param_1,*(undefined4 *)(dVar13 + 0x2c),*(undefined4 *)(dVar13 + 0x28));

    }

    *(undefined4 *)(dVar13 + 0x2c) = 0xffffffff;

    *(undefined4 *)(dVar13 + 0x28) = 0xffffffff;

    if (*(float *)(dVar13 + 0x18) <= 0.0) goto LAB_004f338e;

LAB_004f280f:

    uVar8 = *(undefined4 *)&param_1->field_0x274;

    dVar13 = param_1->animate_state;

    iVar5 = meccbasepit_bldg_from_object_dup004a6200(uVar8);

LAB_004f2824:

    if (iVar5 == 0) {

LAB_004f287f:

      iVar5 = reaperbase_bldg_from_object(uVar8);

      if ((iVar5 != 0) && (-1 < *(int *)(dVar13 + 0x1c))) {

LAB_004f289a:

        param_1->pad_E4 = 0x22;

      }

    }

    else if (((*(int *)(dVar13 + 0x1c) == 0xd) &&

             (iVar5 = base_bldg_is_alive_at_all(uVar8,0xd), iVar5 != 0)) &&

            (iVar5 = slot_member_alive(uVar8,0xd), iVar5 == 0)) {

      *(undefined4 *)(dVar13 + 0x24) = 0xffffffff;

      *(undefined4 *)(dVar13 + 0x20) = 0xffffffff;

      *(undefined4 *)(dVar13 + 0x1c) = 0xffffffff;

LAB_004f2855:

      param_1->pad_E4 = 0x1e;

    }

    else {

LAB_004f2864:

      if (-1 < *(int *)(dVar13 + 0x1c)) {

        param_1->pad_E4 = 0x26;

      }

    }

    break;

  case 0x25:

    if (*(int *)&param_1->field_0xe8 == 7) break;

    *(int *)(dVar13 + 0x1c) = *(int *)(dVar13 + 0x20);

    if (-1 < *(int *)(dVar13 + 0x20)) {

      iVar5 = meccbasepit_bldg_from_object_dup004a6200(*(undefined4 *)&param_1->field_0x274);

      if (iVar5 == 0) {

        iVar5 = reaperbase_bldg_from_object(*(undefined4 *)&param_1->field_0x274);

        if (iVar5 != 0) {

          food_object_flag_clear

                    (param_1,*(undefined4 *)(dVar13 + 0x2c),*(undefined4 *)(dVar13 + 0x28));

        }

      }

      else {

        master_flag_bit_clear(param_1,*(undefined4 *)(dVar13 + 0x2c),*(undefined4 *)(dVar13 + 0x28))

        ;

      }

      dVar3 = param_1->animate_state;

      if (*(int *)(dVar3 + 0x30) != 0) {

        *(undefined4 *)(*(int *)(dVar3 + 0x30) + 0x210) = 0;

        object_destroy(*(undefined4 *)(dVar3 + 0x30));

        *(undefined4 *)(dVar3 + 0x30) = 0;

        *(undefined4 *)(dVar3 + 0x14) = 0x41d80000;

        iVar5 = reaper_0052e4a0(param_1);

        if (iVar5 != 0) {

          reaper_00530bd0(param_1,0,0,0,0x14,0);

        }

      }

      *(undefined4 *)(dVar13 + 0x2c) = 0xffffffff;

      *(undefined4 *)(dVar13 + 0x28) = 0xffffffff;

      if (0.0 < *(float *)(dVar13 + 0x18)) goto LAB_004f280f;

LAB_004f338e:

      param_1->pad_E4 = 0x1e;

      break;

    }

    iVar5 = base_has_partyhouse(*(undefined4 *)&param_1->field_0x274);

    if (iVar5 == 0) break;

    ai_clear_move_goal(param_1);

    *(undefined4 *)(dVar13 + 0x2c) = 0xffffffff;

    *(undefined4 *)(dVar13 + 0x28) = 0xffffffff;

    dVar13 = param_1->animate_state;

    param_1->pad_E4 = 0x1e;

    if (*(int *)(dVar13 + 0x30) == 0) break;

    *(undefined4 *)(*(int *)(dVar13 + 0x30) + 0x210) = 0;

    uVar8 = *(undefined4 *)(dVar13 + 0x30);

LAB_004f26f2:

    object_destroy(uVar8);

    *(undefined4 *)(dVar13 + 0x30) = 0;

    *(undefined4 *)(dVar13 + 0x14) = 0x41d80000;

    iVar5 = reaper_0052e4a0(param_1);

    if (iVar5 != 0) {

      reaper_00530bd0(param_1,0,0,0,0x14,0);

    }

    break;

  case 0x26:

    fVar11 = *(float *)&param_1->field_0x274;

    fStack_264 = fVar11;

    if (*(int *)(dVar13 + 0x1c) != *(int *)(dVar13 + 0x20)) {

      ai_clear_move_goal(param_1);

      param_1->field_0x20b = 0;

      param_1->field_0x20a = 0;

      param_1->field_0x208 = 0;

      *(undefined4 *)(dVar13 + 0x1c) = *(undefined4 *)(dVar13 + 0x20);

    }

    iVar5 = base_get_smartie_building(param_1);

    if (iVar5 == 0) break;

    iVar5 = obj_maxspeed_lookup(iVar5,0);

    if (iVar5 != 0) {

      ai_clear_move_goal(param_1);

      param_1->field_0x20b = 0;

      param_1->field_0x20a = 0;

      param_1->field_0x208 = 0;

      iVar5 = ai_anim_select_mode(param_1,*(undefined4 *)(dVar13 + 0x1c));

      if (iVar5 < 0) {

        *(undefined4 *)(dVar13 + 0x24) = 0xffffffff;

        *(undefined4 *)(dVar13 + 0x20) = 0xffffffff;

        *(undefined4 *)(dVar13 + 0x1c) = 0xffffffff;

      }

      else {

        iVar6 = base_slot_built_check(fStack_264,iVar5);

        if (iVar6 == 0) {

          bldg_spawn_by_type(fStack_264,iVar5);

          reaper_lock_short(fStack_264,iVar5,param_1,1);

        }

        *(int *)(dVar13 + 0x20) = iVar5;

        *(int *)(dVar13 + 0x1c) = iVar5;

      }

      if ((-1 < *(int *)(dVar13 + 0x1c)) && (0.0 < *(float *)(dVar13 + 0x18))) goto LAB_004f280f;

      fVar11 = fStack_264;

      if (*(float *)(DAT_00632ed8 + 0x624) == *(float *)(dVar13 + 0x18)) goto LAB_004f32da;

      goto LAB_004f2855;

    }

    if (*(int *)&param_1->field_0x168 != 0) {

      dVar3 = param_1->animate_state;

      iVar5 = ai_goal_process(param_1);

      if (iVar5 == -1) {

        ai_clear_move_goal(param_1);

        ai_move_force_goal(param_1,dVar3 + 0x58);

        ai_goal_process(param_1);

      }

      if (*(int *)&param_1->field_0x168 == 0) {

        puVar10 = (undefined4 *)(dVar13 + 0x58);

        object_set_location_p3d(param_1,puVar10);

        param_1->field_0x20b = 0;

        param_1->field_0x20a = 0;

        param_1->field_0x208 = 0;

        if (0 < *(int *)(dVar13 + 0x28)) {

          iVar5 = meccbasepit_bldg_from_object_dup004a6200(*(undefined4 *)&param_1->field_0x274);

          if (iVar5 == 0) {

            iVar5 = base_slot10_get(*(undefined4 *)&param_1->field_0x274);

          }

          else {

            iVar5 = base_slot15_get(*(undefined4 *)&param_1->field_0x274);

          }

          if (iVar5 == 0) {

            *puVar10 = *(undefined4 *)&param_1->field_0xa0;

            *(undefined4 *)(dVar13 + 0x5c) = *(undefined4 *)&param_1->field_0xa4;

            *(undefined4 *)(dVar13 + 0x60) = *(undefined4 *)&param_1->field_0xa8;

          }

          else {

            bldg_get_refpt_worldlocdir

                      (iVar5,*(undefined4 *)(dVar13 + 0x28),puVar10,&param_1->field_0xc8);

            *(undefined4 *)(dVar13 + 0x28) = 0xb;

          }

        }

        param_1->pad_E4 = 0x27;

        *(undefined4 *)&param_1->field_0xec = 0x40000000;

        iVar5 = reaper_0052e4a0(param_1);

        if (iVar5 != 0) {

          iVar5 = meccbasepit_bldg_from_object_dup004a6200(*(undefined4 *)&param_1->field_0x274);

          if (iVar5 == 0) {

            iVar5 = base_slot10_get(*(undefined4 *)&param_1->field_0x274);

          }

          else {

            iVar5 = base_slot15_get(*(undefined4 *)&param_1->field_0x274);

          }

          uStack_260 = 0.0;

          if (iVar5 != 0) {

            uStack_260 = *(float *)(iVar5 + 0x188);

          }

          reaper_00530bd0(param_1,0,1,0,0x12,&uStack_260);

        }

      }

      break;

    }

    iVar5 = meccbasepit_bldg_from_object_dup004a6200(fVar11);

    if (iVar5 == 0) {

      iVar5 = base_slot10_get(fVar11);

    }

    else {

      iVar5 = base_slot15_get();

    }

    if (iVar5 != 0) {

      *(undefined4 *)(dVar13 + 0x28) = 10;

      bldg_get_refpt_worldloc(iVar5,10,dVar13 + 0x58);

      ai_moveonly_set_goal(param_1,dVar13 + 0x58);

      break;

    }

    goto LAB_004f289a;

  case 0x27:

    fVar14 = (float10)FRateGetSecsframe(param_1,0);

    fVar14 = (float10)*(float *)&param_1->field_0xec - fVar14;

    *(float *)&param_1->field_0xec = (float)fVar14;

    if (fVar14 < (float10)0.0 != (fVar14 == (float10)0.0)) {

      param_1->pad_E4 = 0x22;

    }

    iVar5 = meccbasepit_bldg_from_object_dup004a6200(*(undefined4 *)&param_1->field_0x274);

    if (iVar5 == 0) {

      uStack_260 = (float)base_slot10_get(*(undefined4 *)&param_1->field_0x274);

    }

    else {

      uStack_260 = (float)base_slot15_get(*(undefined4 *)&param_1->field_0x274);

    }

    if (uStack_260 == 0.0) {

      fStack_254 = *(float *)&param_1->field_0xa0;

      fStack_250 = *(float *)&param_1->field_0xa4;

      fStack_24c = *(float *)&param_1->field_0xa8;

    }

    else {

      bldg_get_refpt_worldloc(uStack_260,*(undefined4 *)(dVar13 + 0x28),&fStack_254);

    }

    puStack_258 = (undefined4 *)(*(float *)&param_1->field_0xec * 0.5);

    fVar11 = 1.0 - (float)puStack_258;

    object_set_location(param_1,(float)puStack_258 * *(float *)(dVar13 + 0x58) + fStack_254 * fVar11

                        ,fStack_250 * fVar11 + (float)puStack_258 * *(float *)(dVar13 + 0x5c),

                        fStack_24c * fVar11 + (float)puStack_258 * *(float *)(dVar13 + 0x60));

    if (((float)puStack_258 < 0.5) && (*(int *)(dVar13 + 0x30) == 0)) {

      iVar5 = NAM_DictionaryGetTotalNames(*(undefined4 *)&param_1->field_0x274);

      dVar3 = param_1->animate_state;

      if (*(int *)(dVar3 + 0x30) != 0) {

        *(undefined4 *)(*(int *)(dVar3 + 0x30) + 0x210) = 0;

        object_destroy(*(undefined4 *)(dVar3 + 0x30));

        *(undefined4 *)(dVar3 + 0x30) = 0;

        *(undefined4 *)(dVar3 + 0x14) = 0x41d80000;

        iVar6 = reaper_0052e4a0(param_1);

        if (iVar6 != 0) {

          reaper_00530bd0(param_1,0,0,0,0x14,0);

        }

      }

      if (iVar5 == 0) {

        uVar8 = 0x2f9;

      }

      else if (iVar5 == 1) {

        uVar8 = 0x30e;

      }

      else {

        uVar8 = 0x30f;

      }

      smartie_make_held_object__FP6OBJECTi(param_1,uVar8);

      if (uStack_260 != 0.0) {

        bldg_get_refpt_worldlocdir

                  (uStack_260,*(undefined4 *)(dVar13 + 0x28),dVar13 + 0x58,&param_1->field_0xc8);

      }

      *(undefined4 *)(dVar13 + 0x28) = 10;

    }

    break;

  case 0x28:

    uVar8 = base_get_smartie_building(param_1);

    bldg_get_refpt_worldlocdir(uVar8,*(undefined4 *)(dVar13 + 0x28),&fStack_254,&uStack_260);

    if (*(float *)&param_1->field_0xec == 0.0) {

      fVar14 = (float10)dirfcalcp3d__FP3P3DT0(dVar13 + 0x58,&fStack_254);

      *(float *)&param_1->field_0xc8 = (float)fVar14;

    }

    fVar14 = (float10)FRateGetSecsframe(param_1,0);

    fVar14 = fVar14 * (float10)3.3333333 + (float10)*(float *)&param_1->field_0xec;

    *(float *)&param_1->field_0xec = (float)fVar14;

    if ((float10)1.0 <= fVar14) {

      uVar26 = 1;

      uVar24 = 0;

      uVar22 = 0x576;

      uVar21 = 0;

      uVar20 = 0x575;

      uVar17 = 0x577;

      pOVar18 = param_1;

      uVar8 = sound_get_free_sequence__Fv();

      *(undefined4 *)(dVar13 + 0xb8) = uVar8;

      *(float *)&param_1->field_0xc8 = uStack_260;

      object_set_location_p3d(param_1,&fStack_254,uVar17,uVar20,uVar21,uVar22,pOVar18,uVar24,uVar26)

      ;

      dVar13 = param_1->animate_state;

      *(undefined4 *)&param_1->field_0xec = 0x3fc00000;

      if (*(int *)(dVar13 + 0x30) != 0) {

        *(undefined4 *)(*(int *)(dVar13 + 0x30) + 0x210) = 0;

        object_destroy(*(undefined4 *)(dVar13 + 0x30));

        *(undefined4 *)(dVar13 + 0x30) = 0;

        *(undefined4 *)(dVar13 + 0x14) = 0x41d80000;

        iVar5 = reaper_0052e4a0(param_1);

        if (iVar5 != 0) {

          reaper_00530bd0(param_1,0,0,0,0x14,0);

        }

      }

      param_1->pad_E4 = 0x23;

      make_dust_ball(&param_1->field_0xa0,0x3f000000);

      break;

    }

    fVar15 = (float10)1.0 - fVar14;

    fVar11 = (float)((float10)fStack_24c * fVar14 + fVar15 * (float10)*(float *)(dVar13 + 0x60));

    fVar25 = (float)((float10)fStack_250 * fVar14 + fVar15 * (float10)*(float *)(dVar13 + 0x5c));

    fVar23 = (float)((float10)fStack_254 * fVar14 + fVar15 * (float10)*(float *)(dVar13 + 0x58));

LAB_004f35c0:

    object_set_location(param_1,fVar23,fVar25,fVar11);

    break;

  case 0x32:

    smartie_handle_reaper_grab__FP6OBJECTP14ObjSpecSmartie(param_1,dVar13);

    break;

  case 0x33:

  case 0x34:

    iVar5 = smartie_check_follow__FP6OBJECTf(param_1,0x41200000);

    if ((iVar5 == 0) || (param_1->pad_E4 != 0x33)) {

      if (param_1->pad_E4 != 0x34) break;

      uStack_260 = 1.0;

      fVar14 = (float10)FRateGetSecsframe(param_1,0);

      fVar14 = (float10)*(float *)&param_1->field_0xec - fVar14;

      *(float *)&param_1->field_0xec = (float)fVar14;

      if ((float10)0.0 < fVar14) break;

      if ((param_1->flags & 0x8000000) != 0) {

        uStack_260 = 4.0;

      }

      fVar14 = (float10)FRateGetSecsframe(param_1,0);

      fVar14 = (float10)*(float *)&param_1->field_0xf0 - fVar14 * (float10)uStack_260;

      *(float *)&param_1->field_0xf0 = (float)fVar14;

      if (fVar14 < (float10)0.0) {

LAB_004f0b0c:

        iVar6 = team_base_find(param_1->ai_state_b);

        if (iVar6 == 0) break;

        iVar9 = dialog_level_is_base_dup0052aa70();

        if (iVar9 == 0) {

          iVar5 = ObjIsMecc(DAT_00632a88);

          if (iVar5 == 0) {

            uVar8 = TextGetPtrRandom(s_MPChFlagRetTime_005621e0,&DAT_0055b3bc);

          }

          else {

            uVar8 = TextGetPtrRandom(s_MPChFlagRetTime_005621e0,s_Borjoyzee_0055b3c0);

          }

          crt_sprintf(auStack_200,uVar8);

          chat_insert(auStack_200,1);

        }

        else {

          if (0.0 <= *(float *)&param_1->field_0xf0) {

            iVar9 = base_which_team(param_1);

            pcVar16 = s_Borjoyzee_0055b3c0;

            if (iVar9 != 1) {

              pcVar16 = &DAT_0055b3bc;

            }

            uVar8 = comm_player_name4(iVar5,pcVar16);

            uVar8 = TextGetPtrRandom(s_MPChFlagRet_005621d4,uVar8);

            crt_sprintf(auStack_200,uVar8);

          }

          else {

            iVar5 = base_which_team(param_1);

            pcVar16 = s_Borjoyzee_0055b3c0;

            if (iVar5 != 1) {

              pcVar16 = &DAT_0055b3bc;

            }

            uVar8 = TextGetPtrRandom(s_MPChFlagRetTime_005621e0,pcVar16);

            crt_sprintf(auStack_200,uVar8);

          }

          comm_audio_volume_user(auStack_200,1,0,0);

        }

        if ((DAT_00632a88 != 0) && (*(dword *)(DAT_00632a88 + 0x18c) == param_1->ai_state_b)) {

          iVar5 = dialog_level_is_base_dup0052aa70();

          if (iVar5 == 0) {

            iVar5 = ObjIsMecc(DAT_00632a88);

            if (iVar5 != 0) goto LAB_004f0cb6;

LAB_004f0c61:

            iVar5 = ObjIsMecc(DAT_00632a88);

            if (iVar5 == 0) {

              uVar8 = *(undefined4 *)(DAT_006330e4 + 0x50e0);

              pcVar16 = s_DELCT30_00562178;

            }

            else {

              iVar5 = crt_rand_scaled(100);

              if (iVar5 < 0x21) {

                uVar8 = *(undefined4 *)(DAT_006330e4 + 0x50e0);

                pcVar16 = s_BAZ_CT30_005621c8;

              }

              else if (iVar5 < 0x42) {

                uVar8 = *(undefined4 *)(DAT_006330e4 + 0x50e0);

                pcVar16 = s_GOR_CT30_0056218c;

              }

              else {

                uVar8 = *(undefined4 *)(DAT_006330e4 + 0x50e0);

                pcVar16 = s_REG_CT30_00562180;

              }

            }

          }

          else {

            iVar5 = base_which_team(param_1);

            if (iVar5 != 1) goto LAB_004f0c61;

LAB_004f0cb6:

            iVar5 = ObjIsMecc(DAT_00632a88);

            if (iVar5 == 0) {

              uVar8 = *(undefined4 *)(DAT_006330e4 + 0x50e0);

              pcVar16 = s_DELCT29_1_00562198;

            }

            else {

              iVar5 = crt_rand_scaled(100);

              if (iVar5 < 0x21) {

                uVar8 = *(undefined4 *)(DAT_006330e4 + 0x50e0);

                pcVar16 = s_BAZ_CT29_005621bc;

              }

              else if (iVar5 < 0x42) {

                uVar8 = *(undefined4 *)(DAT_006330e4 + 0x50e0);

                pcVar16 = s_GOR_CT29_005621b0;

              }

              else {

                uVar8 = *(undefined4 *)(DAT_006330e4 + 0x50e0);

                pcVar16 = s_REG_CT29_005621a4;

              }

            }

          }

          teammecc_clear_mode(pcVar16,uVar8,0);

        }

        objtype_setup_vimp(param_1,iVar6);

        iVar5 = reaper_0052e4a0(param_1);

        if (iVar5 == 0) break;

        uStack_260 = *(float *)(iVar6 + 0x188);

        goto LAB_004f19e6;

      }

      if (iVar5 == 0) break;

      if (*(dword *)(iVar5 + 0x18c) == param_1->ai_state_b) goto LAB_004f0b0c;

      iVar6 = dialog_level_is_base_dup0052aa70();

      if (iVar6 == 0) {

        iVar6 = ObjIsMecc(DAT_00632a88);

        pcVar16 = s_Borjoyzee_0055b3c0;

        if (iVar6 == 0) {

          pcVar16 = &DAT_0055b3bc;

        }

        uVar8 = comm_player_name4(iVar5,pcVar16);

        uVar8 = TextGetPtrRandom(s_MPChFlagTaken_0055b3ac,uVar8);

      }

      else {

        iVar6 = base_which_team(param_1);

        pcVar16 = s_Borjoyzee_0055b3c0;

        if (iVar6 != 1) {

          pcVar16 = &DAT_0055b3bc;

        }

        uVar8 = comm_player_name4(iVar5,pcVar16);

        uVar8 = TextGetPtrRandom(s_MPChFlagTaken_0055b3ac,uVar8);

      }

      crt_sprintf(auStack_200,uVar8);

      comm_audio_volume_user(auStack_200,1,0,0);

      smartie_board_player__FP6OBJECTT0i(param_1,iVar5,1);

      if ((DAT_00632a88 == 0) || (*(dword *)(DAT_00632a88 + 0x18c) != param_1->ai_state_b)) break;

      iVar5 = dialog_level_is_base_dup0052aa70();

      if (iVar5 == 0) {

        iVar5 = ObjIsMecc(DAT_00632a88);

        if (iVar5 != 0) goto LAB_004f0a4f;

        goto LAB_004f0803;

      }

      iVar5 = base_which_team(param_1);

      if (iVar5 != 1) goto LAB_004f0803;

LAB_004f0a4f:

      iVar5 = ObjIsMecc(DAT_00632a88);

      if (iVar5 == 0) {

        teammecc_clear_mode(s_DELCT23_2_00562210,*(undefined4 *)(DAT_006330e4 + 0x50e0),0);

        break;

      }

      iVar5 = crt_rand_scaled(100);

      if (0x31 < iVar5) {

        teammecc_clear_mode(s_REGCT23_00562208,*(undefined4 *)(DAT_006330e4 + 0x50e0),0);

        break;

      }

LAB_004f0a71:

      teammecc_clear_mode(s_GORCT23_2_00561a90,*(undefined4 *)(DAT_006330e4 + 0x50e0),0);

    }

    else {

      iVar6 = dialog_level_is_base_dup0052aa70();

      if (iVar6 == 0) {

        iVar6 = ObjIsMecc(DAT_00632a88);

        pcVar16 = s_Borjoyzee_0055b3c0;

        if (iVar6 == 0) {

          pcVar16 = &DAT_0055b3bc;

        }

        uVar8 = comm_player_name4(iVar5,pcVar16);

        uVar8 = TextGetPtrRandom(s_MPChFlagTaken_0055b3ac,uVar8);

      }

      else {

        iVar6 = base_which_team(param_1);

        pcVar16 = s_Borjoyzee_0055b3c0;

        if (iVar6 != 1) {

          pcVar16 = &DAT_0055b3bc;

        }

        uVar8 = comm_player_name4(iVar5,pcVar16);

        uVar8 = TextGetPtrRandom(s_MPChFlagTaken_0055b3ac,uVar8);

      }

      crt_sprintf(auStack_200,uVar8);

      comm_audio_volume_user(auStack_200,1,0,0);

      smartie_board_player__FP6OBJECTT0i(param_1,iVar5,1);

      if (param_1->type_id == 0x248) {

        iVar5 = crt_rand_scaled(100);

        if (iVar5 < 0x32) {

          iVar5 = 0x701;

        }

        else {

          iVar5 = 0x702;

        }

LAB_004f07c5:

        sound_play_obj(iVar5);

      }

      else if (param_1->type_id == 0x2e6) {

        iVar5 = crt_rand_scaled(100);

        if (iVar5 < 0x32) {

          iVar5 = 0x70b;

        }

        else {

          iVar5 = 0x70c;

        }

        goto LAB_004f07c5;

      }

      if ((DAT_00632a88 == 0) || (*(dword *)(DAT_00632a88 + 0x18c) != param_1->ai_state_b)) break;

      iVar5 = dialog_level_is_base_dup0052aa70();

      if (iVar5 == 0) {

        iVar5 = ObjIsMecc(DAT_00632a88);

        if (iVar5 != 0) goto LAB_004f0860;

      }

      else {

        iVar5 = base_which_team(param_1);

        if (iVar5 == 1) {

LAB_004f0860:

          iVar5 = ObjIsMecc(DAT_00632a88);

          if (iVar5 == 0) {

            teammecc_clear_mode(s_DELCT23_2_00562210,*(undefined4 *)(DAT_006330e4 + 0x50e0),0);

            break;

          }

          iVar5 = crt_rand_scaled(100);

          if (0x31 < iVar5) {

            teammecc_clear_mode(s_REG_CT23_00561a84,*(undefined4 *)(DAT_006330e4 + 0x50e0),0);

            break;

          }

          goto LAB_004f0a71;

        }

      }

LAB_004f0803:

      iVar5 = ObjIsMecc(DAT_00632a88);

      if (iVar5 == 0) {

        teammecc_clear_mode(s_DELCT24_2_005621f0,*(undefined4 *)(DAT_006330e4 + 0x50e0),0);

      }

      else {

        iVar5 = crt_rand_scaled(100);

        if (iVar5 < 0x32) {

          teammecc_clear_mode(s_GOR_CT24_0056221c,*(undefined4 *)(DAT_006330e4 + 0x50e0),0);

        }

        else {

          teammecc_clear_mode(s_REG_CT24_005621fc,*(undefined4 *)(DAT_006330e4 + 0x50e0),0);

        }

      }

    }

    break;

  case 0x37:

    param_1->pad_184 = 0x3f800000;

    if (DAT_00632bb8 != 0) {

      param_1->pad_184 = 0;

    }

    param_1->field_0x208 = 0;

    param_1->field_0x20b = 0;

    param_1->field_0x20a = 0;

    if (*(float *)(dVar13 + 0x18) == 0.0) {

      dVar3 = param_1->animate_state;

      iVar5 = *(int *)(dVar3 + 0x48);

      if (iVar5 != 0) {

        fx_delete(iVar5);

        *(undefined4 *)(dVar3 + 0x48) = 0;

      }

    }

    *(undefined4 *)(dVar13 + 0x18) = *(undefined4 *)(DAT_00632ed8 + 0x624);

    break;

  case 0x38:

    param_1->pad_184 = 0;

    param_1->field_0x208 = 0;

    param_1->field_0x20b = 0;

    param_1->field_0x20a = 0;

    fVar14 = (float10)FRateGetSecsframe(param_1,0);

    fVar14 = (float10)*(float *)&param_1->field_0xec - fVar14;

    *(float *)&param_1->field_0xec = (float)fVar14;

    if ((fVar14 < (float10)0.0 != (fVar14 == (float10)0.0)) &&

       (iVar5 = base_has_partyhouse(*(undefined4 *)&param_1->field_0x274), iVar5 != 0)) {

      param_1->pad_E4 = 0x1e;

    }

    break;

  case 0x3c:

  case 0x3d:

    fVar14 = (float10)FRateGetSecsframe(param_1,0);

    fVar14 = (float10)*(float *)&param_1->field_0xec - fVar14;

    *(float *)&param_1->field_0xec = (float)fVar14;

    puVar10 = DAT_00632d6c;

    if (fVar14 < (float10)0.0 != (fVar14 == (float10)0.0)) {

      for (; puVar10 != (undefined4 *)0x0; puVar10 = (undefined4 *)*puVar10) {

        iVar5 = puVar10[3];

        if (*(int *)(iVar5 + 0x1e0) == 0x17) {

          param_1->pad_E4 = 0x3c;

          fVar14 = (float10)distancesq2d__FP3P3DT0(&param_1->field_0xa0,iVar5 + 0xa0);

          if (fVar14 < (float10)225.0 != (fVar14 == (float10)225.0)) {

            param_1->pad_E4 = 0x3d;

            break;

          }

        }

      }

    }

    break;

  case 0x3f:

    if ((*(int *)(dVar13 + 0xa0) != 0) &&

       (iVar5 = ANM_AnimGetImage(*(int *)(dVar13 + 0xa0)), iVar5 == 0)) {

      ai_goal_process(param_1);

      if (*(int *)&param_1->field_0x168 != 0) break;

      fVar14 = (float10)distancesq2d__FP3P3DT0(&param_1->field_0xa0,*(int *)(dVar13 + 0xa0) + 0xa0);

      if (fVar14 < (float10)2500.0) {

        *(uint *)&param_1->field_0x1c8 = *(uint *)&param_1->field_0x1c8 | 0x600;

        ai_move_force_goal(param_1,*(int *)(dVar13 + 0xa0) + 0xa0);

        param_1->pad_E4 = 0x40;

        break;

      }

      puVar2 = (uint *)(*(int *)(dVar13 + 0xa0) + 0xe0);

      *puVar2 = *puVar2 & 0xfffffffb;

      *(undefined4 *)(dVar13 + 0xa0) = 0;

    }

    goto LAB_004f0e47;

  case 0x40:

    if ((*(int *)(dVar13 + 0xa0) != 0) &&

       (iVar5 = ANM_AnimGetImage(*(int *)(dVar13 + 0xa0)), iVar5 == 0)) {

      ai_goal_process(param_1);

      if (*(int *)&param_1->field_0x168 == 0) {

        *(undefined4 *)(dVar13 + 0xa4) = *(undefined4 *)&param_1->field_0x1d0;

        *(undefined4 *)&param_1->field_0x1d0 = 0;

        fVar14 = (float10)rndfloatrange(0x41200000,0x41a00000);

        *(float *)&param_1->field_0xec = (float)fVar14;

        param_1->field_0x20b = 0;

        param_1->field_0x20a = 0;

        param_1->field_0x208 = 0;

        *(uint *)&param_1->field_0x1c8 = *(uint *)&param_1->field_0x1c8 & 0xfffff9ff;

        param_1->pad_E4 = 0x41;

      }

      break;

    }

LAB_004f0e47:

    param_1->pad_E4 = 3;

    break;

  case 0x41:

    if ((*(int *)(dVar13 + 0xa0) == 0) ||

       (iVar5 = ANM_AnimGetImage(*(int *)(dVar13 + 0xa0)), iVar5 != 0)) {

      *(undefined4 *)&param_1->field_0x1d0 = *(undefined4 *)(dVar13 + 0xa4);

      fVar14 = (float10)FRateGetSecsframe(param_1,0);

      *(float *)&param_1->field_0xec = (float)((float10)*(float *)&param_1->field_0xec - fVar14);

    }

    if (*(float *)&param_1->field_0xec < 0.0 != (*(float *)&param_1->field_0xec == 0.0)) {

      param_1->pad_E4 = 3;

    }

    break;

  case 0x50:

    fVar14 = (float10)FRateGetSecsframe(param_1,0);

    fVar14 = (float10)*(float *)&param_1->field_0xf0 - fVar14;

    *(float *)&param_1->field_0xf0 = (float)fVar14;

    if (fVar14 < (float10)0.0) {

      iVar5 = crt_rand_scaled(100);

      if (iVar5 < 0x32) {

        iVar5 = 0x6b1;

      }

      else {

        iVar5 = 0x6b2;

      }

      sound_play_obj(iVar5);

      fVar14 = (float10)rndfloatrange(0x41a00000,0x42200000);

      *(float *)&param_1->field_0xf0 = (float)fVar14;

    }

    fVar14 = (float10)FRateGetSecsframe(param_1,0);

    fVar14 = (float10)*(float *)&param_1->field_0xec - fVar14;

    *(float *)&param_1->field_0xec = (float)fVar14;

    if (fVar14 < (float10)0.0) {

      uVar26 = 0x3f000000;

      uVar24 = 0;

      uVar22 = 0;

      uVar21 = 0x20;

      uVar20 = 0x71;

      pOVar18 = param_1;

      ObjectSetAnim(param_1);

      param_1->pad_E4 = 0x51;

      puVar19 = auStack_234;

      uVar17 = 0x24;

      *(undefined4 *)&param_1->field_0xec = *(undefined4 *)(DAT_00632ed8 + 0xb04);

      pcVar16 = s_fx_smartie_hang_debri_00562228;

      pOStack_21c = param_1;

      uStack_220 = 1;

      uStack_224 = 8;

      uVar8 = fx_get_free_effect__Fv();

      *(undefined4 *)&param_1->field_0xf4 = uVar8;

      sound_play_3(0x6c2,&param_1->field_0xa0,param_1,pcVar16,uVar17,puVar19,pOVar18,uVar20,uVar21,

                   uVar22,uVar24,uVar26);

    }

    break;

  case 0x51:

    fVar14 = (float10)FRateGetSecsframe(param_1,0);

    fVar14 = (float10)*(float *)&param_1->field_0xf0 - fVar14;

    *(float *)&param_1->field_0xf0 = (float)fVar14;

    if (fVar14 < (float10)0.0) {

      iVar5 = crt_rand_scaled(100);

      if (iVar5 < 0x32) {

        iVar5 = 0x6b1;

      }

      else {

        iVar5 = 0x6b2;

      }

      sound_play_obj(iVar5);

      fVar14 = (float10)rndfloatrange(0x40a00000,0x41200000);

      *(float *)&param_1->field_0xf0 = (float)fVar14;

    }

    fVar14 = (float10)FRateGetSecsframe(param_1,0);

    fVar14 = (float10)*(float *)&param_1->field_0xec - fVar14;

    *(float *)&param_1->field_0xec = (float)fVar14;

    if (fVar14 < (float10)0.0) {

      iVar5 = *(int *)&param_1->field_0x210;

      if ((iVar5 != 0) && (*(int *)(iVar5 + 4) == 0x3e9)) {

        iVar6 = 0;

        do {

          if ((*(uint *)(iVar5 + 0xf4) & 1 << ((byte)iVar6 & 0x1f)) != 0) {

            *(uint *)(iVar5 + 0xf4) = ~(1 << ((byte)iVar6 & 0x1f)) & *(uint *)(iVar5 + 0xf4);

            break;

          }

          iVar6 = iVar6 + 1;

        } while (iVar6 < 8);

        if (*(int *)(*(int *)&param_1->field_0x210 + 0xf4) == 0) {

          iVar5 = 8;

          do {

            iVar6 = object_allocate_type(0xb,0x80000000);

            *(undefined4 *)(iVar6 + 0xe8) = 5;

            *(uint *)(iVar6 + 0xdc) = *(uint *)(iVar6 + 0xdc) | param_1->pad_DC & 0xf;

            iVar5 = iVar5 + -1;

            *(uint *)(iVar6 + 0xd8) = *(uint *)(iVar6 + 0xd8) | param_1->flags & 0x400;

          } while (iVar5 != 0);

        }

      }

      *(undefined4 *)&param_1->field_0x210 = 0;

      param_1->pad_E4 = 3;

      ObjectSetAnim(param_1);

      *(undefined4 *)&param_1->field_0xec = 0x49742400;

      if (*(int *)&param_1->field_0xf4 != 0) {

        fx_delete(*(int *)&param_1->field_0xf4);

      }

      *(undefined4 *)&param_1->field_0xf4 = 0;

      sound_stop_obj(0x6c2,param_1);

    }

    break;

  case 0x52:

    ai_goal_process(param_1);

  }

  obj_alpha_fade_update(param_1);

  player_pitch_update(param_1);

  obj_scale_compute(param_1);

  vvel_decay_tick(param_1);

  smartie_vvel_avg_move(param_1);

  iVar5 = reaper_0052e4a0(param_1);

  if (iVar5 != 0) {

    dVar13 = param_1->animate_state;

    if ((param_1->pad_E4 != 0x13) && (param_1->pad_E4 != 0x27)) {

      pfVar1 = (float *)(dVar13 + 0x58);

      if ((*(float *)(dVar13 + 0x58) != *(float *)(dVar13 + 100)) ||

         ((*(float *)(dVar13 + 0x5c) != *(float *)(dVar13 + 0x68) ||

          (*(float *)(dVar13 + 0x60) != *(float *)(dVar13 + 0x6c))))) {

        if (8000.0 < *pfVar1) {

          *pfVar1 = 8000.0;

        }

        if (8000.0 < *(float *)(dVar13 + 0x5c)) {

          *(undefined4 *)(dVar13 + 0x5c) = 0x45fa0000;

        }

        if (*pfVar1 < -8000.0) {

          *pfVar1 = -8000.0;

        }

        if (*(float *)(dVar13 + 0x5c) < -8000.0) {

          *(undefined4 *)(dVar13 + 0x5c) = 0xc5fa0000;

        }

        uVar4 = __ftol();

        uStack_260 = (float)CONCAT22(uStack_260._2_2_,uVar4);

        uVar4 = __ftol();

        uStack_260 = (float)CONCAT22(uVar4,(undefined2)uStack_260);

        comm_chat_send_2(param_1,0,1,0,0x10,&uStack_260);

        *(float *)(dVar13 + 100) = *pfVar1;

        *(undefined4 *)(dVar13 + 0x68) = *(undefined4 *)(dVar13 + 0x5c);

        *(undefined4 *)(dVar13 + 0x6c) = *(undefined4 *)(dVar13 + 0x60);

        return;

      }

      fVar14 = (float10)FRateGetSecsframe(0,0);

      fVar14 = (float10)*(float *)(dVar13 + 0x7c) - fVar14;

      *(float *)(dVar13 + 0x7c) = (float)fVar14;

      if ((((*(float *)&param_1->field_0xa0 != *(float *)(dVar13 + 0x70)) ||

           (*(float *)&param_1->field_0xa4 != *(float *)(dVar13 + 0x74))) ||

          (*(float *)&param_1->field_0xa8 != *(float *)(dVar13 + 0x78))) &&

         (fVar14 < (float10)0.0 != (fVar14 == (float10)0.0))) {

        uVar4 = __ftol();

        uStack_260 = (float)CONCAT22(uStack_260._2_2_,uVar4);

        uVar4 = __ftol();

        uStack_260 = (float)CONCAT22(uVar4,(undefined2)uStack_260);

        uVar4 = __ftol();

        uStack_25c = CONCAT22(uStack_25c._2_2_,uVar4);

        comm_chat_send_2(param_1,0,0,6,1,&uStack_260);

        *(undefined4 *)(dVar13 + 0x7c) = 0x40400000;

        *(float *)(dVar13 + 0x70) = *(float *)&param_1->field_0xa0;

        *(undefined4 *)(dVar13 + 0x74) = *(undefined4 *)&param_1->field_0xa4;

        *(undefined4 *)(dVar13 + 0x78) = *(undefined4 *)&param_1->field_0xa8;

        return;

      }

    }

  }

  return;

  while (fStack_264 = (float)((int)fStack_264 + 1), (int)fStack_264 < 8) {

LAB_004f00b0:

    if ((*(uint *)(iVar5 + 0xf4) & 1 << (SUB41(fStack_264,0) & 0x1f)) == 0) {

      *(float *)&param_1->field_0x218 = fStack_264;

      *(int *)&param_1->field_0x210 = iVar5;

      *(undefined4 *)&param_1->field_0x214 = 1;

      *(float *)&param_1->field_0xec =

           *(float *)(DAT_00632ed8 + 0xb00) * (float)(int)fStack_264 +

           *(float *)(DAT_00632ed8 + 0xafc);

      *(uint *)(iVar5 + 0xf4) = *(uint *)(iVar5 + 0xf4) | 1 << (SUB41(fStack_264,0) & 0x1f);

      break;

    }

  }

LAB_004f0111:

  crt_rand_scaled(100,0x21,0,0,0);

  ObjectSetAnim(param_1);

  goto LAB_004f015a;

LAB_004f1865:

  fVar14 = (float10)distancesq2d__FP3P3DT0(iVar5 + 0xa0,&pOVar18->field_0xa0);

  if ((float10)100.0 < fVar14) goto LAB_004f187e;

  goto LAB_004f17e7;

}

