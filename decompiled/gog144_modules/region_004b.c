/* Giants 1.449 — module region_004b
 * 95 functions (95 named) — decompiled, names from PS2 symbols
 * Original source: C:\Giants\source\region_004b.c(pp) (assert-string evidence)
 */

/* ===== fx_slot_free_check @ 0x004B0900 ===== */
bool fx_slot_free_check(int param_1,undefined4 param_2,int param_3)



{

  uint uVar1;

  int iVar2;

  int *piVar3;

  

  iVar2 = 0;

  piVar3 = DAT_00632d28;

  if (0 < DAT_00632d24) {

    do {

      if (*piVar3 == param_1) {

        if (DAT_00632d28 + iVar2 * 0x1439 == (int *)0x0) {

          return false;

        }

        uVar1 = (DAT_00632d28 + iVar2 * 0x1439)[2];

        if ((uVar1 & 1) == 0) {

          return false;

        }

        if (((uVar1 & 0x40) != 0) && (param_3 != 0)) {

          return false;

        }

        switch(param_2) {

        case 0:

          goto switchD_004b095c_caseD_0;

        case 1:

          if ((uVar1 & 0x24) != 0) {

            return false;

          }

          return true;

        case 2:

          return (uVar1 & 6) == 0;

        case 3:

          return (uVar1 & 0xe) == 0;

        case 4:

          return (uVar1 & 10) == 0;

        case 5:

          return (uVar1 & 0xc) == 0;

        default:

          return false;

        }

      }

      iVar2 = iVar2 + 1;

      piVar3 = piVar3 + 0x1439;

    } while (iVar2 < DAT_00632d24);

  }

  return false;

switchD_004b095c_caseD_0:

  if ((uVar1 & 0x12) != 0) {

    return false;

  }

  return true;

}

/* ===== world_get_pointer @ 0x004B09C0 ===== */
/* PS2 candidate: world_get_pointer (conf 0.691) */



int * world_get_pointer(int param_1)



{

  int iVar1;

  int *piVar2;

  

  iVar1 = 0;

  piVar2 = DAT_00632d28;

  if (0 < DAT_00632d24) {

    do {

      if (*piVar2 == param_1) {

        return DAT_00632d28 + iVar1 * 0x1439;

      }

      iVar1 = iVar1 + 1;

      piVar2 = piVar2 + 0x1439;

    } while (iVar1 < DAT_00632d24);

  }

  return (int *)0x0;

}

/* ===== session_table_lookup @ 0x004B0A00 ===== */
/* PS2 candidate: world_get_id (conf 0.529) */



undefined4 session_table_lookup(undefined4 param_1)



{

  int iVar1;

  int iVar2;

  int iVar3;

  

  iVar2 = 0;

  if (0 < DAT_00632d24) {

    iVar3 = 0;

    do {

      iVar1 = match(*(undefined4 *)(iVar3 + 4 + DAT_00632d28),param_1);

      if (iVar1 != 0) {

        return *(undefined4 *)(iVar2 * 0x50e4 + DAT_00632d28);

      }

      iVar2 = iVar2 + 1;

      iVar3 = iVar3 + 0x50e4;

    } while (iVar2 < DAT_00632d24);

  }

  return 0xffffffff;

}

/* ===== anm_dict_find @ 0x004B0A60 ===== */
int anm_dict_find(int param_1)



{

  int iVar1;

  int *piVar2;

  

  iVar1 = 0;

  piVar2 = DAT_00632d28;

  if (0 < DAT_00632d24) {

    while (*piVar2 != param_1) {

      iVar1 = iVar1 + 1;

      piVar2 = piVar2 + 0x1439;

      if (DAT_00632d24 <= iVar1) {

        return 0;

      }

    }

    if (DAT_00632d28 + iVar1 * 0x1439 != (int *)0x0) {

      return (DAT_00632d28 + iVar1 * 0x1439)[1];

    }

  }

  return 0;

}

/* ===== world_get_nicename @ 0x004B0AB0 ===== */
char * world_get_nicename(int param_1)



{

  int iVar1;

  char *pcVar2;

  int *piVar3;

  char local_40 [64];

  

  iVar1 = 0;

  piVar3 = DAT_00632d28;

  if (0 < DAT_00632d24) {

    while (*piVar3 != param_1) {

      iVar1 = iVar1 + 1;

      piVar3 = piVar3 + 0x1439;

      if (DAT_00632d24 <= iVar1) {

        return s__null__00560278;

      }

    }

    if (DAT_00632d28 + iVar1 * 0x1439 != (int *)0x0) {

      crt_sprintf(local_40,&DAT_0055bfe4,(DAT_00632d28 + iVar1 * 0x1439)[1]);

      pcVar2 = (char *)TextGetPtr(local_40);

      if (pcVar2 == local_40) {

        pcVar2 = pcVar2 + 2;

      }

      return pcVar2;

    }

  }

  return s__null__00560278;

}

/* ===== InitFxDict__Fv @ 0x004B0B40 ===== */
/* PS2 candidate: InitFxDict__Fv (conf 0.55) */



void InitFxDict__Fv(void)



{

  int iVar1;

  int *piVar2;

  int iVar3;

  

  iVar1 = -1;

  piVar2 = DAT_00632d28;

  iVar3 = DAT_00632d24;

  if (0 < DAT_00632d24) {

    do {

      if (iVar1 < *piVar2) {

        iVar1 = *piVar2;

      }

      iVar3 = iVar3 + -1;

      piVar2 = piVar2 + 0x1439;

    } while (iVar3 != 0);

  }

  return;

}

/* ===== main/readwrls_004b0d80 @ 0x004B0D80 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* PS2 candidate: mussys_init__Fv (conf 0.551) */



void main_readwrls_004b0d80(void)



{

  undefined1 local_100 [256];

  

  _DAT_005a6c24 = 0x3f800000;

  _DAT_005a6c28 = vobuf_alloc_wrap(&LAB_004b0e00);

  if (_DAT_005a6c28 == 0) {

    savegame_slot_load(s_Failed_to_load_world_read_task__00560310);

    _DAT_005a6c24 = 0x3f800000;

    crt_sprintf(local_100,s_W__s_bin_0055c160,*(undefined4 *)(DAT_006330e4 + 4));

    bin_load_1a0002e5(local_100,0x3f800000,0);

    _DAT_005a6c24 = 0;

  }

  return;

}

/* ===== config_get_double @ 0x004B0E50 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



float10 config_get_double(void)



{

  return (float10)_DAT_005a6c24;

}

/* ===== main/readwrls_004b0e60 @ 0x004B0E60 ===== */
/* PS2 candidate: tracer_draw_mecc_balls (conf 0.853) */



void main_readwrls_004b0e60(undefined4 param_1)



{

  undefined1 local_100 [256];

  

  crt_sprintf(local_100,s_W__s_bin_0055c160,param_1);

  bin_load_1a0002e5(local_100,0x3f800000,0);

  return;

}

/* ===== game_state_camera_init @ 0x004B0EA0 ===== */
/* PS2 candidate: setup_sun_flares__Fv (conf 0.771) */



void game_state_camera_init(void)



{

  int iVar1;

  

  iVar1 = DAT_006330e4;

  *(undefined4 *)(DAT_006330e4 + 0x4fa0) = 0x40000000;

  *(undefined4 *)(iVar1 + 0x4fa4) = 0x40000000;

  *(undefined4 *)(iVar1 + 0x4fe4) = 0x40000000;

  *(undefined4 *)(iVar1 + 0x4fe8) = 0x40000000;

  *(undefined4 *)(iVar1 + 0x5028) = 0x40000000;

  *(undefined4 *)(iVar1 + 0x502c) = 0x40000000;

  *(undefined4 *)(iVar1 + 0x4f74) = 0;

  *(undefined4 *)(iVar1 + 0x4f78) = 0;

  *(undefined4 *)(iVar1 + 0x4f80) = 0x3f800000;

  *(undefined4 *)(iVar1 + 0x4f7c) = 0x3f800000;

  *(undefined4 *)(iVar1 + 0x4f84) = 0x3f000000;

  *(undefined4 *)(iVar1 + 0x4f88) = 0;

  *(undefined4 *)(iVar1 + 0x4f90) = 0x40e00000;

  *(undefined4 *)(iVar1 + 0x4f98) = 0x3ecccccd;

  *(undefined4 *)(iVar1 + 0x4f8c) = 0;

  *(undefined4 *)(iVar1 + 0x4f94) = 0;

  *(undefined4 *)(iVar1 + 0x4f9c) = 0x3f800000;

  *(undefined4 *)(iVar1 + 0x4fa8) = 0x3f800000;

  *(undefined4 *)(iVar1 + 0x4fac) = 0x3f800000;

  *(undefined4 *)(iVar1 + 0x4fb0) = 0x3f800000;

  *(undefined4 *)(iVar1 + 0x4fb4) = 1;

  *(undefined4 *)(iVar1 + 0x4fb8) = 0;

  *(undefined4 *)(iVar1 + 0x4fbc) = 0;

  *(undefined4 *)(iVar1 + 0x4fcc) = 0;

  *(undefined4 *)(iVar1 + 0x4fd4) = 0x43af0000;

  *(undefined4 *)(iVar1 + 0x4fdc) = 0x3f800000;

  *(undefined4 *)(iVar1 + 0x4fd0) = 0x467a0000;

  *(undefined4 *)(iVar1 + 0x4fd8) = 0x437a0000;

  *(undefined4 *)(iVar1 + 0x4fe0) = 0x461c4000;

  *(undefined4 *)(iVar1 + 0x4fec) = 0x447a0000;

  *(undefined4 *)(iVar1 + 0x4ff0) = 0x3e2e147b;

  *(undefined4 *)(iVar1 + 0x4ff4) = 0x3ce56042;

  *(undefined4 *)(iVar1 + 0x4ff8) = 1;

  *(undefined4 *)(iVar1 + 0x4ffc) = 0;

  *(undefined4 *)(iVar1 + 0x5000) = 0;

  *(undefined4 *)(iVar1 + 0x5010) = 0;

  *(undefined4 *)(iVar1 + 0x5018) = 0x43af0000;

  *(undefined4 *)(iVar1 + 0x5020) = 0x3f800000;

  *(undefined4 *)(iVar1 + 0x5014) = 0x467a0000;

  *(undefined4 *)(iVar1 + 0x501c) = 0x43c80000;

  *(undefined4 *)(iVar1 + 0x5024) = 0x469c4000;

  *(undefined4 *)(iVar1 + 0x5030) = 0x44af0000;

  *(undefined4 *)(iVar1 + 0x5034) = 0x3e19999a;

  *(undefined4 *)(iVar1 + 0x5038) = 0x3d03126f;

  return;

}

/* ===== rpboat_lock_to_boat__FP6OBJECTT0 @ 0x004B4450 ===== */
/* PS2 candidate: rpboat_lock_to_boat__FP6OBJECTT0 (conf 0.525) */



void rpboat_lock_to_boat__FP6OBJECTT0(void)



{

  int iVar1;

  undefined4 *puVar2;

  int iVar3;

  int iVar4;

  undefined4 uVar5;

  int iVar6;

  undefined1 auStack_88 [132];

  

  puVar2 = DAT_00632d68;

  iVar6 = DAT_006330e4;

  do {

    if (puVar2 == (undefined4 *)0x0) {

      return;

    }

    iVar1 = puVar2[3];

    if (*(char *)(iVar1 + 0x1f7) != '\0') {

      iVar3 = __ftol();

      iVar4 = __ftol();

      if ((((*(int *)(iVar6 + 0x24) < iVar3) || (*(int *)(iVar6 + 0x2c) < iVar4)) ||

          (iVar3 < *(int *)(iVar6 + 0x20))) || (iVar4 < *(int *)(iVar6 + 0x28))) {

        uVar5 = objspec_get_movetype_string

                          (*(undefined4 *)(iVar1 + 0x1e0),(double)*(float *)(iVar1 + 0xa0),

                           (double)*(float *)(iVar1 + 0xa4),(double)*(float *)(iVar1 + 0xa8));

        crt_sprintf(auStack_88,s_Object_type__d__movetype__s__is_o_00560628,

                    *(undefined4 *)(iVar1 + 4),uVar5);

        error_msg_show(auStack_88);

      }

      else if (*(char *)(*(int *)(*(int *)(iVar6 + 0x10) + iVar4 * 4) + 0xe + iVar3 * 0x10) == '\0')

      goto LAB_004b454b;

      *(undefined1 *)(iVar1 + 0x1f7) = 0;

      iVar6 = DAT_006330e4;

    }

LAB_004b454b:

    puVar2 = (undefined4 *)*puVar2;

  } while( true );

}

/* ===== AudioGetSampleName__Fi_2 @ 0x004B4560 ===== */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */



char * AudioGetSampleName__Fi_2(int p0)



{

  int in_stack_00000008;

  

  return s_Extractor_00560670 + in_stack_00000008 * 0x58;

}

/* ===== reaperbase_init @ 0x004B4570 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* PS2 candidate: reaperbase_init (conf 0.413) */



void reaperbase_init(int param_1)



{

  int *piVar1;

  OBJECT *obj;

  int iVar2;

  undefined4 *puVar3;

  int iVar4;

  float *pfVar5;

  int *piVar6;

  undefined4 local_18;

  float local_14;

  float local_10;

  float local_c;

  float local_8;

  float local_4;

  

  piVar1 = *(int **)(param_1 + 0x100);

  *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 1;

  if (*piVar1 == 0) {

    error_msg_show(s_Obsolete_Base_placement_detected_00554e10);

    return;

  }

  obj = (OBJECT *)object_allocate_type(*piVar1,0);

  if (obj != (OBJECT *)0x0) {

    local_c = *(float *)(param_1 + 0xa0) - (float)piVar1[4];

    local_8 = *(float *)(param_1 + 0xa4) - (float)piVar1[5];

    local_4 = *(float *)(param_1 + 0xa8) - (float)piVar1[6];

    object_set_location_p3d(obj,&local_c);

    *(float *)&obj->field_0xc8 = *(float *)(param_1 + 200) - (float)piVar1[7];

    ObjectCalculateTransform(obj);

    ObjectSetAnim(obj);

    object_animate_process(obj);

    piVar6 = &DAT_005606c0;

    pfVar5 = (float *)(piVar1 + 9);

    do {

      if (*piVar6 < 0) {

        *pfVar5 = *(float *)(param_1 + 0xa0);

        pfVar5[1] = *(float *)(param_1 + 0xa4);

        pfVar5[2] = *(float *)(param_1 + 0xa8);

        pfVar5[3] = *(float *)(param_1 + 200);

      }

      else {

        bldg_get_refpt_worldlocdir(obj,*piVar6,pfVar5,pfVar5 + 3);

        if ((piVar6 == (int *)&DAT_00560a30) || (piVar6 == (int *)&DAT_00560770)) {

          sine_cos_lookup(pfVar5[3],&local_14,&local_10);

          *pfVar5 = local_14 * 70.0 + *pfVar5;

          pfVar5[1] = pfVar5[1] - local_10 * 70.0;

        }

      }

      piVar6 = piVar6 + 0x16;

      pfVar5 = pfVar5 + 7;

    } while ((int)piVar6 < 0x560c40);

    iVar2 = object_allocate_type(0x35a,0);

    bldg_get_refpt_worldlocdir(obj,0,&local_c,&local_18);

    object_set_location_p3d(iVar2,&local_c);

    *(undefined4 *)(iVar2 + 200) = local_18;

    *(uint *)(iVar2 + 0xd8) = *(uint *)(iVar2 + 0xd8) | 0x10;

    iVar2 = object_allocate_type(0x353,0);

    bldg_get_refpt_worldlocdir(obj,0xe,&local_c,&local_18);

    object_set_location_p3d(iVar2,&local_c);

    *(undefined4 *)(iVar2 + 200) = local_18;

    *(uint *)(iVar2 + 0xd8) = *(uint *)(iVar2 + 0xd8) | 0x10;

    iVar2 = object_allocate_type(0x353,0);

    bldg_get_refpt_worldlocdir(obj,0xf,&local_c,&local_18);

    object_set_location_p3d(iVar2,&local_c);

    *(uint *)(iVar2 + 0xd8) = *(uint *)(iVar2 + 0xd8) | 0x10;

    *(undefined4 *)(iVar2 + 200) = local_18;

    bldg_get_refpt_worldloc(obj,0x13,piVar1 + 0x171);

    bldg_get_refpt_worldloc(obj,0x14,piVar1 + 0x174);

    object_destroy(obj);

    piVar6 = piVar1 + 0xdc;

    iVar2 = 5;

    do {

      iVar4 = 0xc;

      do {

        *piVar6 = 0;

        piVar6[1] = 0;

        piVar6 = piVar6 + 2;

        iVar4 = iVar4 + -1;

      } while (iVar4 != 0);

      iVar2 = iVar2 + -1;

    } while (iVar2 != 0);

    piVar1[0xdd] = 10;

    piVar1[0xf5] = 0xb;

    piVar1[0x10d] = 0xc;

    piVar1[0x125] = 0xd;

    piVar1[0x13d] = 0xe;

    iVar2 = 1;

    piVar6 = piVar1 + 0xdf;

    do {

      *piVar6 = iVar2 + 0x14;

      iVar2 = iVar2 + 1;

      piVar6 = piVar6 + 2;

    } while (iVar2 < 0xc);

    iVar2 = 1;

    piVar6 = piVar1 + 0xf7;

    do {

      *piVar6 = iVar2 + 0x1e;

      iVar2 = iVar2 + 1;

      piVar6 = piVar6 + 2;

    } while (iVar2 < 0xc);

    iVar2 = 1;

    piVar6 = piVar1 + 0x10f;

    do {

      *piVar6 = iVar2 + 0x28;

      iVar2 = iVar2 + 1;

      piVar6 = piVar6 + 2;

    } while (iVar2 < 0xc);

    iVar2 = 1;

    piVar6 = piVar1 + 0x127;

    do {

      *piVar6 = iVar2 + 0x32;

      iVar2 = iVar2 + 1;

      piVar6 = piVar6 + 2;

    } while (iVar2 < 0xc);

    iVar2 = 1;

    piVar6 = piVar1 + 0x13f;

    do {

      *piVar6 = iVar2 + 0x3c;

      iVar2 = iVar2 + 1;

      piVar6 = piVar6 + 2;

    } while (iVar2 < 0xc);

    piVar1[0x15a] = 0;

    piVar1[0xda] = -1;

    puVar3 = &DAT_005606bc;

    piVar6 = piVar1 + 0xd;

    do {

      *piVar6 = 0;

      *puVar3 = 0x43480000;

      puVar3 = puVar3 + 0x16;

      piVar6 = piVar6 + 7;

    } while ((int)puVar3 < 0x560c3c);

    DAT_005606bc = *(undefined4 *)(DAT_00632ed8 + 0x71c);

    DAT_00560714 = *(undefined4 *)(DAT_00632ed8 + 0x750);

    _DAT_0056076c = *(undefined4 *)(DAT_00632ed8 + 0x85c);

    _DAT_005607c4 = *(undefined4 *)(DAT_00632ed8 + 0x870);

    _DAT_0056081c = *(undefined4 *)(DAT_00632ed8 + 0x874);

    _DAT_00560874 = *(undefined4 *)(DAT_00632ed8 + 0x874);

    _DAT_005608cc = *(undefined4 *)(DAT_00632ed8 + 0x874);

    _DAT_00560924 = *(undefined4 *)(DAT_00632ed8 + 0x878);

    _DAT_0056097c = *(undefined4 *)(DAT_00632ed8 + 0x87c);

    _DAT_005609d4 = *(undefined4 *)(DAT_00632ed8 + 0x880);

    _DAT_00560a2c = *(undefined4 *)(DAT_00632ed8 + 0x884);

    _DAT_00560a84 = *(undefined4 *)(DAT_00632ed8 + 0x888);

    _DAT_00560adc = *(undefined4 *)(DAT_00632ed8 + 0x88c);

    _DAT_00560b34 = *(undefined4 *)(DAT_00632ed8 + 0x88c);

    _DAT_00560b8c = *(undefined4 *)(DAT_00632ed8 + 0x88c);

    _DAT_00560be4 = *(undefined4 *)(DAT_00632ed8 + 0x890);

    _DAT_005606c4 = *(undefined4 *)(DAT_00632ed8 + 0x1114);

    _DAT_0056071c = *(undefined4 *)(DAT_00632ed8 + 0x1118);

    DAT_00560774 = *(undefined4 *)(DAT_00632ed8 + 0x111c);

    _DAT_005607cc = *(undefined4 *)(DAT_00632ed8 + 0x1120);

    DAT_00560824 = *(undefined4 *)(DAT_00632ed8 + 0x1124);

    _DAT_0056087c = *(undefined4 *)(DAT_00632ed8 + 0x1124);

    _DAT_005608d4 = *(undefined4 *)(DAT_00632ed8 + 0x1124);

    _DAT_0056092c = *(undefined4 *)(DAT_00632ed8 + 0x1128);

    _DAT_00560984 = *(undefined4 *)(DAT_00632ed8 + 0x112c);

    _DAT_005609dc = *(undefined4 *)(DAT_00632ed8 + 0x1130);

    _DAT_00560a34 = *(undefined4 *)(DAT_00632ed8 + 0x1134);

    _DAT_00560a8c = *(undefined4 *)(DAT_00632ed8 + 0x1138);

    _DAT_00560ae4 = *(undefined4 *)(DAT_00632ed8 + 0x113c);

    _DAT_00560b3c = *(undefined4 *)(DAT_00632ed8 + 0x113c);

    _DAT_00560b94 = *(undefined4 *)(DAT_00632ed8 + 0x113c);

    _DAT_00560bec = *(undefined4 *)(DAT_00632ed8 + 0x1140);

    piVar1[0x1b] = 1;

    bldg_set_energy(param_1,*(undefined4 *)(DAT_00632ed8 + 0x15a4));

  }

  return;

}

/* ===== reaperbasebldg_move @ 0x004B4CA0 ===== */
/* PS2 candidate: reaperbasebldg_move (conf 0.591) */



void reaperbasebldg_move(OBJECT *param_1)



{

  float *pfVar1;

  dword dVar2;

  OBJECT *pOVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  int *piVar7;

  float10 fVar8;

  float10 fVar9;

  

  pOVar3 = param_1;

  iVar6 = *(int *)&param_1->field_0x274;

  pfVar1 = (float *)param_1->animate_state;

  if (iVar6 == 0) {

    return;

  }

  if (**(int **)(iVar6 + 0x100) == 0) {

    return;

  }

  if (param_1->ai_state_b == 0) {

    param_1->ai_state_b = *(dword *)(iVar6 + 0x18c);

  }

  iVar4 = fx_create(param_1);

  if (iVar4 == 0) {

    if ((param_1->coll_radius & 0x2000) != 0) {

      dVar2 = param_1->animate_state;

      fVar8 = (float10)FRateGetSecsframe(0,0);

      fVar8 = (float10)*(float *)(dVar2 + 0x14) - fVar8;

      *(float *)(dVar2 + 0x14) = (float)fVar8;

      if (fVar8 < (float10)0.0 != (fVar8 == (float10)0.0)) {

        collgrid_query_obj(param_1,1);

      }

    }

    switch(param_1->pad_E4) {

    case 1:

    case 2:

      goto switchD_004b4d3a_caseD_1;

    case 3:

    case 0xd:

      param_1->pad_184 = 0;

      fVar8 = (float10)bldg_get_energy(param_1);

      fVar9 = (float10)bldg_get_max_energy_dup00418170(param_1);

      fVar9 = (float10)(float)fVar8 / fVar9;

      *(uint *)&param_1->field_0x30 = *(uint *)&param_1->field_0x30 | 0x80;

      if (((float10)0.75 <= fVar9) && (fVar9 < (float10)0.99)) {

        fVar9 = (float10)0.75;

      }

      param_1->pad_14 = (dword)(float)fVar9;

      return;

    case 4:

      if (param_1->anim != 1) {

        return;

      }

      fVar8 = (float10)bldg_get_energy(param_1);

      fVar9 = (float10)bldg_get_max_energy_dup00418170(param_1);

      fVar9 = (float10)(float)fVar8 / fVar9;

      *(uint *)&param_1->field_0x30 = *(uint *)&param_1->field_0x30 | 0x80;

      if (fVar9 < (float10)0.0 != (fVar9 == (float10)0.0)) {

        param_1->pad_14 = 0;

        return;

      }

      fVar9 = fVar9 - (float10)0.01;

      fVar8 = (float10)*(float *)(DAT_00632ed8 + 0xb7c) * (float10)0.01;

      if (fVar9 < fVar8 != (fVar9 == fVar8)) {

        param_1->pad_14 = (dword)(float)fVar8;

        return;

      }

      fVar8 = (float10)*(float *)(DAT_00632ed8 + 0xb78) * (float10)0.01;

      if (fVar9 < fVar8 == (fVar9 == fVar8)) {

        fVar8 = (float10)*(float *)(DAT_00632ed8 + 0xb74) * (float10)0.01;

        if (fVar9 < fVar8 == (fVar9 == fVar8)) {

          param_1->pad_14 = 0x3f800000;

          return;

        }

        param_1->pad_14 = (dword)(float)fVar8;

        return;

      }

      param_1->pad_14 = (dword)(float)fVar8;

      return;

    case 5:

      goto switchD_004b4d3a_caseD_5;

    default:

      return;

    case 7:

      goto switchD_004b4d3a_caseD_7;

    case 9:

      fVar8 = (float10)bldg_get_energy(param_1);

      fVar8 = fVar8 / (float10)*(float *)(DAT_00632ed8 + 0x894);

      *(uint *)&param_1->field_0x30 = *(uint *)&param_1->field_0x30 | 0x80;

      if (((float10)0.75 <= fVar8) && (fVar8 < (float10)0.99)) {

        fVar8 = (float10)0.75;

      }

      param_1->pad_14 = (dword)(float)fVar8;

      if ((param_1->coll_radius & 0x1000) == 0) {

        return;

      }

      if (param_1->ai_state_b == *(dword *)(DAT_00632a88 + 0x18c)) {

        return;

      }

      fVar8 = (float10)distance3d__FP3P3DT0(DAT_00632a88 + 0xa0,&param_1->field_0xa0);

      fVar8 = (fVar8 - (float10)*(float *)(DAT_00632ed8 + 0x1210)) /

              ((float10)*(float *)(DAT_00632ed8 + 0x1214) -

              (float10)*(float *)(DAT_00632ed8 + 0x1210));

      param_1->pad_184 = (dword)(float)fVar8;

      if ((float10)1.0 < fVar8) {

        param_1->pad_184 = 0x3f800000;

      }

      if (0.0 <= (float)param_1->pad_184) {

        return;

      }

      param_1->pad_184 = 0;

      return;

    }

  }

  switch(param_1->pad_E4) {

  case 2:

    fVar8 = (float10)bldg_get_energy(param_1);

    if ((float10)0.0 < fVar8) {

      if (*(int *)&param_1->field_0x274 != 0) {

        iVar4 = 0;

        piVar7 = (int *)(*(int *)(*(int *)&param_1->field_0x274 + 0x100) + 0x20);

        do {

          if ((OBJECT *)*piVar7 == param_1) goto LAB_004b4fe5;

          iVar4 = iVar4 + 1;

          piVar7 = piVar7 + 7;

        } while (iVar4 < 0x10);

      }

      iVar4 = -1;

LAB_004b4fe5:

      reaperbasebldg_start_building(iVar6,param_1,iVar4);

      iVar5 = reaper_0052e4a0(param_1);

      if (iVar5 != 0) {

        reaper_state_check_b(iVar6,param_1,iVar4);

      }

      fx_create_hack_logic(param_1);

      return;

    }

  case 1:

switchD_004b4d3a_caseD_1:

    if (DAT_00632bb0 == 0) {

      param_1->pad_184 = 0x3f800000;

      return;

    }

    base_bldg_pulsate(param_1);

    return;

  case 3:

  case 0xd:

    param_1->pad_184 = 0;

    iVar6 = reaperbase_bldg_from_object(param_1);

    if (iVar6 == 0) {

      if (*(int *)&param_1->field_0x274 != 0) {

        iVar6 = 0;

        piVar7 = (int *)(*(int *)(*(int *)&param_1->field_0x274 + 0x100) + 0x20);

        do {

          if ((OBJECT *)*piVar7 == param_1) {

            if (-1 < iVar6) {

              param_1 = (OBJECT *)(&DAT_005606bc)[iVar6 * 0x16];

              goto LAB_004b5098;

            }

            break;

          }

          iVar6 = iVar6 + 1;

          piVar7 = piVar7 + 7;

        } while (iVar6 < 0x10);

      }

      if (((int)param_1->pad_E4 < 9) || (0xc < (int)param_1->pad_E4)) {

        param_1 = (OBJECT *)0x42c80000;

      }

      else {

        param_1 = *(OBJECT **)(DAT_00632ed8 + 0x894);

      }

    }

    else {

      param_1 = *(OBJECT **)(DAT_00632ed8 + 0x628);

    }

LAB_004b5098:

    fVar8 = (float10)bldg_get_energy(pOVar3);

    fVar8 = fVar8 / (float10)(float)param_1;

    *(uint *)&pOVar3->field_0x30 = *(uint *)&pOVar3->field_0x30 | 0x80;

    if (((float10)0.75 <= fVar8) && (fVar8 < (float10)0.99)) {

      fVar8 = (float10)0.75;

    }

    pOVar3->pad_14 = (dword)(float)fVar8;

    iVar6 = reaperbase_bldg_from_object(pOVar3);

    if (iVar6 == 0) {

      if (*(int *)&pOVar3->field_0x274 != 0) {

        iVar6 = 0;

        piVar7 = (int *)(*(int *)(*(int *)&pOVar3->field_0x274 + 0x100) + 0x20);

        do {

          if ((OBJECT *)*piVar7 == pOVar3) {

            if (-1 < iVar6) {

              param_1 = (OBJECT *)(&DAT_005606bc)[iVar6 * 0x16];

              goto LAB_004b5148;

            }

            break;

          }

          iVar6 = iVar6 + 1;

          piVar7 = piVar7 + 7;

        } while (iVar6 < 0x10);

      }

      if (((int)pOVar3->pad_E4 < 9) || (0xc < (int)pOVar3->pad_E4)) {

        param_1 = (OBJECT *)0x42c80000;

      }

      else {

        param_1 = *(OBJECT **)(DAT_00632ed8 + 0x894);

      }

    }

    else {

      param_1 = *(OBJECT **)(DAT_00632ed8 + 0x628);

    }

LAB_004b5148:

    fVar8 = (float10)bldg_get_energy(pOVar3);

    if ((float10)(float)param_1 - (float10)1.0 < fVar8 !=

        ((float10)(float)param_1 - (float10)1.0 == fVar8)) {

      iVar6 = reaper_0052e4a0();

      if (iVar6 != 0) {

        kabutoai_select_punch_anim__FP6OBJECT(pOVar3);

      }

      reaperbasebldg_finish_building(pOVar3);

      return;

    }

    iVar6 = comm_send_gate_check(pOVar3);

    if (iVar6 == 0) {

      return;

    }

    if (*pfVar1 == pfVar1[1]) {

      return;

    }

    reaper_state_check_c(pOVar3);

    pfVar1[1] = *pfVar1;

    return;

  case 4:

    iVar6 = base_slot_active_check(iVar6,10);

    if (iVar6 == 0) {

      pfVar1[2] = 0.0;

    }

    else {

      fVar8 = (float10)FRateGetSecsframe(param_1,0);

      fVar8 = fVar8 * (float10)*(float *)(DAT_00632ed8 + 0xfb8) + (float10)pfVar1[2];

      pfVar1[2] = (float)fVar8;

      if ((float10)*(float *)(DAT_00632ed8 + 0xfbc) < fVar8) {

        pfVar1[2] = *(float *)(DAT_00632ed8 + 0xfbc);

      }

    }

    if (param_1->anim == 1) {

      fVar8 = (float10)bldg_get_energy(param_1);

      fVar9 = (float10)bldg_get_max_energy_dup00418170(param_1);

      fVar9 = (float10)(float)fVar8 / fVar9;

      *(uint *)&param_1->field_0x30 = *(uint *)&param_1->field_0x30 | 0x80;

      if (fVar9 < (float10)0.0 == (fVar9 == (float10)0.0)) {

        fVar9 = fVar9 - (float10)0.01;

        fVar8 = (float10)*(float *)(DAT_00632ed8 + 0xb7c) * (float10)0.01;

        if (fVar9 < fVar8 == (fVar9 == fVar8)) {

          fVar8 = (float10)*(float *)(DAT_00632ed8 + 0xb78) * (float10)0.01;

          if (fVar9 < fVar8 == (fVar9 == fVar8)) {

            fVar8 = (float10)*(float *)(DAT_00632ed8 + 0xb74) * (float10)0.01;

            if (fVar9 < fVar8 == (fVar9 == fVar8)) {

              param_1->pad_14 = 0x3f800000;

            }

            else {

              param_1->pad_14 = (dword)(float)fVar8;

            }

          }

          else {

            param_1->pad_14 = (dword)(float)fVar8;

          }

        }

        else {

          param_1->pad_14 = (dword)(float)fVar8;

        }

      }

      else {

        param_1->pad_14 = 0;

      }

    }

    break;

  case 5:

switchD_004b4d3a_caseD_5:

    if ((param_1->field_0x30 & 2) != 0) {

      param_1->pad_184 = 0x3f800000;

      object_destroy(param_1);

      return;

    }

    return;

  default:

    goto switchD_004b4d3a_caseD_6;

  case 7:

switchD_004b4d3a_caseD_7:

    if ((param_1->field_0x30 & 2) == 0) {

      return;

    }

    ObjectSetAnim(param_1);

    param_1->pad_14 = 0x3f800000;

    param_1->pad_E4 = 4;

    return;

  case 9:

    iVar6 = base_slot_active_check(iVar6,10);

    if (iVar6 == 0) {

      pfVar1[2] = 0.0;

    }

    else {

      fVar8 = (float10)FRateGetSecsframe(param_1,0);

      fVar8 = fVar8 * (float10)*(float *)(DAT_00632ed8 + 0x1380) + (float10)pfVar1[2];

      pfVar1[2] = (float)fVar8;

      if ((float10)*(float *)(DAT_00632ed8 + 0x1384) < fVar8) {

        pfVar1[2] = *(float *)(DAT_00632ed8 + 0x1384);

      }

    }

    fVar8 = (float10)bldg_get_energy(param_1);

    fVar8 = fVar8 / (float10)*(float *)(DAT_00632ed8 + 0x894);

    *(uint *)&param_1->field_0x30 = *(uint *)&param_1->field_0x30 | 0x80;

    if (((float10)0.75 <= fVar8) && (fVar8 < (float10)0.99)) {

      fVar8 = (float10)0.75;

    }

    param_1->pad_14 = (dword)(float)fVar8;

    if (((param_1->coll_radius & 0x1000) != 0) &&

       (param_1->ai_state_b != *(dword *)(DAT_00632a88 + 0x18c))) {

      fVar8 = (float10)distance3d__FP3P3DT0(DAT_00632a88 + 0xa0,&param_1->field_0xa0);

      fVar8 = (fVar8 - (float10)*(float *)(DAT_00632ed8 + 0x1210)) /

              ((float10)*(float *)(DAT_00632ed8 + 0x1214) -

              (float10)*(float *)(DAT_00632ed8 + 0x1210));

      param_1->pad_184 = (dword)(float)fVar8;

      if ((float10)1.0 < fVar8) {

        param_1->pad_184 = 0x3f800000;

      }

      if ((float)param_1->pad_184 < 0.0) {

        param_1->pad_184 = 0;

      }

    }

  }

  iVar6 = comm_send_gate_check_2(param_1);

  if ((iVar6 != 0) && ((*pfVar1 != pfVar1[1] || (pfVar1[2] != pfVar1[3])))) {

    reaper_state_check_c(param_1);

    pfVar1[1] = *pfVar1;

    pfVar1[3] = pfVar1[2];

  }

switchD_004b4d3a_caseD_6:

  return;

}

/* ===== reaperbasebldg_start_building @ 0x004B54C0 ===== */
/* PS2 candidate: reaperbasebldg_start_building (conf 0.503) */



void reaperbasebldg_start_building(int param_1,OBJECT *param_2,uint param_3)



{

  int iVar1;

  int iVar2;

  uint uVar3;

  int iVar4;

  int *piVar5;

  bool bVar6;

  

  iVar1 = *(int *)(param_1 + 0x100);

  param_2->pad_184 = 0;

  param_2->pad_E4 = 3;

  ObjectSetAnim(param_2);

  param_2->pad_14 = 0;

  param_2->ai_state_b = *(dword *)(param_1 + 0x18c);

  uVar3 = param_3 & 0x80000007;

  bVar6 = uVar3 == 0;

  *(uint *)&param_2->field_0x1c8 = *(uint *)&param_2->field_0x1c8 & 0xfffff7ff | 0x20000;

  param_2->flags = param_2->flags | 0x10;

  if ((int)uVar3 < 0) {

    bVar6 = (uVar3 - 1 | 0xfffffff8) == 0xffffffff;

  }

  if (bVar6) {

    piVar5 = (int *)(iVar1 + 0x370);

    param_2 = (OBJECT *)0x5;

    do {

      iVar4 = 0xc;

      do {

        iVar2 = *piVar5;

        if (iVar2 != 0) {

          *(undefined4 *)(iVar2 + 0xe4) = 0x1e;

          ai_clear_move_goal(iVar2);

          *(undefined4 *)(*(int *)(iVar2 + 0x100) + 0x28) = 0xffffffff;

          *piVar5 = 0;

        }

        piVar5 = piVar5 + 2;

        iVar4 = iVar4 + -1;

      } while (iVar4 != 0);

      param_2 = (OBJECT *)((int)param_2 + -1);

    } while (param_2 != (OBJECT *)0x0);

  }

  if (7 < (int)param_3) {

    iVar4 = *(int *)(iVar1 + -0xc0 + param_3 * 0x1c);

    piVar5 = (int *)(iVar1 + -0xc0 + param_3 * 0x1c);

    if (iVar4 != 0) {

      *(undefined4 *)(iVar4 + 0xe4) = 5;

      ObjectSetAnim((OBJECT *)*piVar5);

      if (DAT_00657678 == 0) {

        make_dust_ball(*piVar5 + 0xa0,0x40000000);

        make_dust_ball(*piVar5 + 0xa0,0x40400000);

      }

    }

    *piVar5 = 0;

  }

  *(undefined4 *)(param_1 + 0x184) = 0x3f800000;

  *(uint *)(param_1 + 0x1c8) = *(uint *)(param_1 + 0x1c8) & 0xfffdffff | 0x800;

  return;

}

/* ===== reaperbasebldg_finish_building @ 0x004B5640 ===== */
void reaperbasebldg_finish_building(int param_1)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int *piVar4;

  undefined4 uVar5;

  int iVar6;

  

  iVar6 = param_1;

  iVar1 = *(int *)(param_1 + 0x274);

  iVar2 = *(int *)(iVar1 + 0x100);

  *(undefined4 *)(param_1 + 0xe4) = 4;

  iVar3 = reaperbase_bldg_from_object(param_1);

  if (iVar3 == 0) {

    if (*(int *)(param_1 + 0x274) != 0) {

      iVar3 = 0;

      piVar4 = (int *)(*(int *)(*(int *)(param_1 + 0x274) + 0x100) + 0x20);

      do {

        if (*piVar4 == param_1) {

          if (-1 < iVar3) {

            param_1 = (&DAT_005606bc)[iVar3 * 0x16];

            goto LAB_004b56d8;

          }

          break;

        }

        iVar3 = iVar3 + 1;

        piVar4 = piVar4 + 7;

      } while (iVar3 < 0x10);

    }

    if ((*(int *)(param_1 + 0xe4) < 9) || (0xc < *(int *)(param_1 + 0xe4))) {

      param_1 = 0x42c80000;

    }

    else {

      param_1 = *(undefined4 *)(DAT_00632ed8 + 0x894);

    }

  }

  else {

    param_1 = *(undefined4 *)(DAT_00632ed8 + 0x628);

  }

LAB_004b56d8:

  bldg_set_energy(iVar6,param_1);

  *(uint *)(iVar6 + 0x1c8) = *(uint *)(iVar6 + 0x1c8) & 0xfffff7ff | 0x20000;

  if (*(int *)(iVar6 + 0x274) != 0) {

    iVar3 = 0;

    piVar4 = (int *)(*(int *)(*(int *)(iVar6 + 0x274) + 0x100) + 0x20);

    while (*piVar4 != iVar6) {

      iVar3 = iVar3 + 1;

      piVar4 = piVar4 + 7;

      if (0xf < iVar3) {

        return;

      }

    }

    if (iVar3 != -1) {

      if ((iVar3 == 3) || (iVar3 == 0xb)) {

        *(undefined4 *)(iVar6 + 0xf4) = *(undefined4 *)(DAT_00632ed8 + 0x10d4);

      }

      if (((DAT_00632a88 == 0) || (*(int *)(iVar6 + 0x18c) != *(int *)(DAT_00632a88 + 0x18c))) ||

         (iVar3 != 8)) {

        if ((iVar3 == 0) && (iVar6 = fx_create(iVar6), iVar6 != 0)) {

          item_create_base_pickup(iVar2 + 0x5c4,0x49,0xffffffff);

          item_create_base_pickup(iVar2 + 0x5d0,0x49,0xffffffff);

        }

      }

      else {

        uVar5 = TextGetPtr(s_BaseChatRpPHouseDone_00560bf0,1);

        chat_insert(uVar5);

      }

      iVar6 = *(int *)(iVar3 * 0x1c + 0x20 + *(int *)(iVar1 + 0x100));

      if (**(int **)(iVar6 + 8) != *(int *)(&DAT_005606b4 + iVar3 * 0x58)) {

        uVar5 = objectset_find(*(int *)(&DAT_005606b4 + iVar3 * 0x58));

        object_set_objectset(iVar6,uVar5);

      }

      if (*(int *)(iVar2 + 0x368) == iVar3) {

        *(undefined4 *)(iVar2 + 0x368) = 0xffffffff;

      }

      reaperbase_update_icons(iVar1);

    }

  }

  return;

}

/* ===== reaperbase_update_icons @ 0x004B5810 ===== */
/* PS2 candidate: reaperbase_update_icons (conf 0.547) */



void reaperbase_update_icons(int param_1)



{

  int iVar1;

  undefined4 *puVar2;

  int iVar3;

  int iVar4;

  

  iVar1 = *(int *)(param_1 + 0x100);

  puVar2 = (undefined4 *)(iVar1 + 0x34);

  iVar4 = 0x10;

  do {

    *puVar2 = 0;

    puVar2 = puVar2 + 7;

    iVar4 = iVar4 + -1;

  } while (iVar4 != 0);

  iVar4 = base_slot_active_check(param_1,0);

  if ((iVar4 == 0) && (iVar4 = base_slot_active_check(param_1,8), iVar4 == 0)) {

    iVar4 = base_slot_active_check(param_1,0);

    if (iVar4 != 0) {

      return;

    }

    iVar4 = base_bldg_is_alive_at_all_2(param_1,8);

    if (iVar4 == 0) {

      return;

    }

  }

  iVar4 = base_slot_active_check(param_1,8);

  if (iVar4 == 0) {

    iVar4 = base_slot_active_check(param_1,0);

    if (((((iVar4 != 0) && (iVar4 = base_slot_active_check(param_1,0xc), iVar4 != 0)) &&

         (iVar4 = base_slot_active_check(param_1,0xd), iVar4 != 0)) &&

        ((iVar4 = base_slot_active_check(param_1,0xe), iVar4 != 0 &&

         (iVar4 = base_slot_active_check(param_1,0xf), iVar4 != 0)))) &&

       ((iVar4 = base_slot_active_check(param_1,0xb), iVar4 != 0 &&

        ((iVar4 = base_slot_active_check(param_1,10), iVar4 != 0 &&

         (iVar4 = base_slot_active_check(param_1,9), iVar4 != 0)))))) {

      *(undefined4 *)(iVar1 + 0x114) = 1;

      return;

    }

  }

  else {

    *(undefined4 *)(iVar1 + 0x568) = 1;

    *(undefined4 *)(iVar1 + 0x114) = 1;

  }

  iVar4 = *(int *)(param_1 + 0x100);

  iVar3 = base_slot_active_check(param_1,10);

  if (iVar3 == 0) {

    iVar3 = base_slot_active_check(param_1,2);

    if ((iVar3 == 0) && (iVar3 = base_bldg_is_alive_at_all_2(param_1,10), iVar3 == 0)) {

      *(undefined4 *)(iVar4 + 0x6c) = 1;

    }

    else {

      *(undefined4 *)(iVar4 + 0x14c) = 1;

    }

  }

  iVar4 = base_slot_active_check(param_1,2);

  if ((iVar4 == 0) && (iVar4 = base_slot_active_check(param_1,10), iVar4 == 0)) {

    iVar4 = base_slot_active_check(param_1,2);

    if (iVar4 != 0) {

      return;

    }

    iVar4 = base_bldg_is_alive_at_all_2(param_1,10);

    if (iVar4 == 0) {

      return;

    }

  }

  iVar4 = base_slot_active_check(param_1,9);

  if (iVar4 == 0) {

    *(undefined4 *)(iVar1 + 0x130) = 1;

  }

  iVar1 = *(int *)(param_1 + 0x100);

  iVar4 = base_slot_active_check(param_1,0xc);

  if (iVar4 == 0) {

    iVar4 = base_slot_active_check(param_1,4);

    if ((iVar4 == 0) && (iVar4 = base_bldg_is_alive_at_all_2(param_1,0xc), iVar4 == 0)) {

      *(undefined4 *)(iVar1 + 0xa4) = 1;

    }

    else {

      *(undefined4 *)(iVar1 + 0x184) = 1;

    }

  }

  iVar1 = *(int *)(param_1 + 0x100);

  iVar4 = base_slot_active_check(param_1,0xd);

  if (iVar4 == 0) {

    iVar4 = base_slot_active_check(param_1,5);

    if ((iVar4 == 0) && (iVar4 = base_bldg_is_alive_at_all_2(param_1,0xd), iVar4 == 0)) {

      *(undefined4 *)(iVar1 + 0xc0) = 1;

    }

    else {

      *(undefined4 *)(iVar1 + 0x1a0) = 1;

    }

  }

  iVar1 = *(int *)(param_1 + 0x100);

  iVar4 = base_slot_active_check(param_1,0xe);

  if (iVar4 == 0) {

    iVar4 = base_slot_active_check(param_1,6);

    if ((iVar4 == 0) && (iVar4 = base_bldg_is_alive_at_all_2(param_1,0xe), iVar4 == 0)) {

      *(undefined4 *)(iVar1 + 0xdc) = 1;

    }

    else {

      *(undefined4 *)(iVar1 + 0x1bc) = 1;

    }

  }

  iVar1 = *(int *)(param_1 + 0x100);

  iVar4 = base_slot_active_check(param_1,0xf);

  if (iVar4 == 0) {

    iVar4 = base_slot_active_check(param_1,7);

    if ((iVar4 == 0) && (iVar4 = base_bldg_is_alive_at_all_2(param_1,0xf), iVar4 == 0)) {

      *(undefined4 *)(iVar1 + 0xf8) = 1;

    }

    else {

      *(undefined4 *)(iVar1 + 0x1d8) = 1;

    }

  }

  iVar1 = *(int *)(param_1 + 0x100);

  iVar4 = base_slot_active_check(param_1,0xb);

  if (iVar4 == 0) {

    iVar4 = base_slot_active_check(param_1,3);

    if ((iVar4 == 0) && (iVar4 = base_bldg_is_alive_at_all_2(param_1,0xb), iVar4 == 0)) {

      *(undefined4 *)(iVar1 + 0x88) = 1;

      return;

    }

    *(undefined4 *)(iVar1 + 0x168) = 1;

  }

  return;

}

/* ===== meccbasepit_swap_model__FP6OBJECTi13e_bldg_objset @ 0x004B5B30 ===== */
/* PS2 candidate: meccbasepit_swap_model__FP6OBJECTi13e_bldg_objset_2 (conf 0.557) */



void meccbasepit_swap_model__FP6OBJECTi13e_bldg_objset(int param_1,int param_2,int param_3)



{

  int iVar1;

  undefined4 uVar2;

  

  iVar1 = *(int *)(*(int *)(param_1 + 0x100) + 0x20 + param_2 * 0x1c);

  if (param_3 == 0) {

    if (**(int **)(iVar1 + 8) != *(int *)(&DAT_005606b4 + param_2 * 0x58)) {

      uVar2 = objectset_find(*(int *)(&DAT_005606b4 + param_2 * 0x58));

      object_set_objectset(iVar1,uVar2);

      return;

    }

  }

  else if (param_3 == 1) {

    if (**(int **)(iVar1 + 8) != *(int *)(&DAT_005606b8 + param_2 * 0x58)) {

      uVar2 = objectset_find(*(int *)(&DAT_005606b8 + param_2 * 0x58));

      object_set_objectset(iVar1,uVar2);

      return;

    }

  }

  else {

    object_set_objectset(iVar1,param_2);

  }

  return;

}

/* ===== reaperbasebldg_shot_2 @ 0x004B5D10 ===== */
/* PS2 candidate: reaperbasebldg_shot (conf 0.442) */



void reaperbasebldg_shot_2(float param_1,int param_2)



{

  float fVar1;

  int iVar2;

  int iVar3;

  int *piVar4;

  int iVar5;

  int iVar6;

  int *piVar7;

  

  iVar6 = (int)param_1;

  iVar5 = *(int *)(*(int *)((int)param_1 + 0x274) + 0x100);

  if (*(int *)((int)param_1 + 0x274) != 0) {

    iVar2 = 0;

    piVar4 = (int *)(iVar5 + 0x20);

    do {

      if ((float)*piVar4 == param_1) goto LAB_004b5d40;

      iVar2 = iVar2 + 1;

      piVar4 = piVar4 + 7;

    } while (iVar2 < 0x10);

  }

  iVar2 = -1;

LAB_004b5d40:

  iVar3 = reaperbase_bldg_from_object(param_1);

  if (iVar3 == 0) {

    if (*(int *)((int)param_1 + 0x274) != 0) {

      iVar3 = 0;

      piVar4 = (int *)(*(int *)(*(int *)((int)param_1 + 0x274) + 0x100) + 0x20);

      do {

        if ((float)*piVar4 == param_1) {

          if (-1 < iVar3) {

            param_1 = (float)(&DAT_005606bc)[iVar3 * 0x16];

            goto LAB_004b5db6;

          }

          break;

        }

        iVar3 = iVar3 + 1;

        piVar4 = piVar4 + 7;

      } while (iVar3 < 0x10);

    }

    if ((*(int *)((int)param_1 + 0xe4) < 9) || (0xc < *(int *)((int)param_1 + 0xe4))) {

      param_1 = 100.0;

    }

    else {

      param_1 = *(float *)(DAT_00632ed8 + 0x894);

    }

  }

  else {

    param_1 = *(float *)(DAT_00632ed8 + 0x628);

  }

LAB_004b5db6:

  fVar1 = *(float *)(DAT_00632ed8 + 0xb80) * param_1 * 0.01;

  bldg_set_energy(iVar6,fVar1);

  *(float *)(iVar6 + 0x278) = param_1 - fVar1;

  *(uint *)(iVar6 + 0x1cc) = *(uint *)(iVar6 + 0x1cc) | 1;

  if (iVar2 < 0) {

    piVar7 = (int *)(iVar5 + 0x574);

    iVar5 = 8;

    piVar4 = piVar7;

    do {

      if (*piVar4 == iVar6) {

        *piVar4 = 0;

      }

      piVar4 = piVar4 + 1;

      iVar5 = iVar5 + -1;

    } while (iVar5 != 0);

    object_destroy(iVar6);

    if ((*(int *)(iVar6 + 4) == 0x4a8) && (piVar4 = DAT_00632d9c, DAT_00632d9c != (int *)0x0)) {

      while (((iVar5 = piVar4[3], *(int *)(iVar5 + 4) != 0x4a8 ||

              (((*(int *)(iVar5 + 0x18c) != 1 &&

                (*(int *)(iVar5 + 0x18c) != *(int *)(iVar6 + 0x18c))) || (iVar5 == iVar6)))) ||

             ((char)((uint)*(undefined4 *)(iVar5 + 0xd8) >> 8) < '\0'))) {

        piVar4 = (int *)*piVar4;

        if (piVar4 == (int *)0x0) {

          return;

        }

      }

      iVar6 = 8;

      do {

        if (*piVar7 == iVar5) {

          *piVar7 = 0;

        }

        piVar7 = piVar7 + 1;

        iVar6 = iVar6 + -1;

      } while (iVar6 != 0);

      object_destroy(iVar5);

      if (param_2 == 0) {

        fx_get_free_effect__Fv();

        sound_play_obj(0x615);

        return;

      }

    }

  }

  else {

    comm_wincond_destroy(iVar6);

  }

  return;

}

/* ===== reaperbase_death_handler_c83 @ 0x004B5F00 ===== */
void reaperbase_death_handler_c83

               (undefined4 param_1,float param_2,int param_3,int param_4,float *param_5)



{

  float fVar1;

  float fVar2;

  float fVar3;

  bool bVar4;

  int iVar5;

  int iVar6;

  undefined4 uVar7;

  int *piVar8;

  float10 fVar9;

  float10 fVar10;

  float fStack_40;

  

  if (*(int *)(param_3 + 0x274) == 0) {

    return;

  }

  iVar5 = 0;

  piVar8 = (int *)(*(int *)(*(int *)(param_3 + 0x274) + 0x100) + 0x20);

  do {

    if (*piVar8 == param_3) {

      if (iVar5 < 0) {

        bVar4 = false;

      }

      else {

        bVar4 = true;

      }

      goto code_r0x004b5f55;

    }

    iVar5 = iVar5 + 1;

    piVar8 = piVar8 + 7;

  } while (iVar5 < 0x10);

  iVar5 = -1;

  bVar4 = false;

code_r0x004b5f55:

  if (-1 < iVar5) {

    if ((((param_4 != 0) && (*(int *)(param_4 + 0x274) != 0)) &&

        (*(int *)(*(int *)(param_4 + 0x274) + 0x18c) == *(int *)(param_3 + 0x18c))) &&

       (DAT_0063318c == 0)) {

      return;

    }

    iVar6 = dialog_level_is_base_dup0052aa70();

    if (((iVar6 != 0) && (iVar6 = game_mode_set6_check(DAT_00632f18), iVar6 == 0)) &&

       (iVar6 = game_mode_set5_check(DAT_00632f18), iVar6 == 0)) {

      return;

    }

  }

  iVar6 = dialog_level_is_base_dup0052aa70();

  if (((iVar6 != 0) && (iVar5 < 0)) &&

     ((DAT_00633250 != 0 &&

      (((param_4 != 0 && (*(int *)(param_4 + 0x274) != 0)) &&

       (*(int *)(*(int *)(param_4 + 0x274) + 0x18c) == *(int *)(param_3 + 0x18c))))))) {

    return;

  }

  if (*(int *)(param_3 + 0xe4) < 4) {

    return;

  }

  if (param_2 <= 0.0) {

    iVar6 = obj_maxspeed_lookup(param_3,-param_2);

    if ((iVar6 != 0) && (bVar4)) {

      iVar6 = *(int *)(*(int *)(*(int *)(param_3 + 0x274) + 0x100) + 0x20 + iVar5 * 0x1c);

      if (**(int **)(iVar6 + 8) != *(int *)(&DAT_005606b4 + iVar5 * 0x58)) {

        uVar7 = objectset_find(*(int *)(&DAT_005606b4 + iVar5 * 0x58));

        object_set_objectset(iVar6,uVar7);

      }

    }

    fVar9 = (float10)bldg_get_max_energy_dup00418170(param_3);

    fVar1 = *(float *)(DAT_00632ed8 + 0xb80);

    fVar10 = (float10)bldg_get_energy(param_3);

    if ((float10)(float)((float10)fVar1 * fVar9 * (float10)0.01) < fVar10) {

      *(uint *)(param_3 + 0x1c8) = *(uint *)(param_3 + 0x1c8) & 0xfffff7ff;

      *(uint *)(param_3 + 0x1cc) = *(uint *)(param_3 + 0x1cc) & 0xfffffffe;

    }

  }

  else {

    if ((0 < DAT_00632f08) && (0.0 < DAT_00632f30)) {

      return;

    }

    fVar9 = (float10)bldg_get_energy(param_3);

    fVar1 = (float)fVar9;

    fVar9 = (float10)func_0x00417c30(param_3,param_2);

    if (((param_5 != (float *)0x0) && (fVar9 == (float10)0.0)) &&

       (*(float *)(DAT_00632ed8 + 0xb80) * 0.01 < fVar1)) {

      if (param_4 == 0) {

        fStack_40 = *(float *)(param_3 + 0xa0) - *param_5;

        fVar2 = *(float *)(param_3 + 0xa4) - param_5[1];

      }

      else {

        fStack_40 = *(float *)(param_4 + 0xa0) - *(float *)(param_4 + 0xb8);

        fVar2 = *(float *)(param_4 + 0xa4) - *(float *)(param_4 + 0xbc);

      }

      atand2pos(fVar2,fStack_40);

      fx_get_free_effect__Fv();

    }

    iVar6 = reaperbase_bldg_from_object(param_3);

    if (iVar6 == 0) {

      if (*(int *)(param_3 + 0x274) != 0) {

        iVar6 = 0;

        piVar8 = (int *)(*(int *)(*(int *)(param_3 + 0x274) + 0x100) + 0x20);

        do {

          if (*piVar8 == param_3) {

            if (-1 < iVar6) {

              param_2 = (float)(&DAT_005606bc)[iVar6 * 0x16];

              goto code_r0x004b6198;

            }

            break;

          }

          iVar6 = iVar6 + 1;

          piVar8 = piVar8 + 7;

        } while (iVar6 < 0x10);

      }

      if ((*(int *)(param_3 + 0xe4) < 9) || (0xc < *(int *)(param_3 + 0xe4))) {

        param_2 = 100.0;

      }

      else {

        param_2 = *(float *)(DAT_00632ed8 + 0x894);

      }

    }

    else {

      param_2 = *(float *)(DAT_00632ed8 + 0x628);

    }

code_r0x004b6198:

    fVar3 = (1.0 / param_2) * fVar1 * 100.0;

    fVar9 = (float10)bldg_get_energy(param_3);

    fVar2 = (float)(fVar9 * (float10)(1.0 / param_2) * (float10)100.0 - (float10)0.01);

    if ((bVar4) &&

       (fVar9 = (float10)bldg_get_energy(param_3),

       fVar9 <= (float10)*(float *)(DAT_00632ed8 + 0xb84) * (float10)param_2 * (float10)0.01)) {

      iVar6 = *(int *)(*(int *)(*(int *)(param_3 + 0x274) + 0x100) + 0x20 + iVar5 * 0x1c);

      if (**(int **)(iVar6 + 8) != *(int *)(&DAT_005606b8 + iVar5 * 0x58)) {

        uVar7 = objectset_find(*(int *)(&DAT_005606b8 + iVar5 * 0x58));

        object_set_objectset(iVar6,uVar7);

      }

      if ((iVar5 == 7) || (iVar5 == 0xf)) {

        *(undefined4 *)(param_3 + 0xe4) = 4;

      }

    }

    if ((param_5 != (float *)0x0) &&

       ((((*(float *)(DAT_00632ed8 + 0xb74) < fVar3 && (fVar2 <= *(float *)(DAT_00632ed8 + 0xb74)))

         || ((*(float *)(DAT_00632ed8 + 0xb78) < fVar3 &&

             (fVar2 <= *(float *)(DAT_00632ed8 + 0xb78))))) ||

        ((*(float *)(DAT_00632ed8 + 0xb7c) < fVar3 && (fVar2 <= *(float *)(DAT_00632ed8 + 0xb7c)))))

       )) {

      fx_get_free_effect__Fv();

      sound_play_obj(0x614);

      if (*(int *)(param_3 + 0x18c) == *(int *)(DAT_00632a88 + 0x18c)) {

        func_0x00409800(param_3);

      }

      iVar6 = fx_create(param_3);

      if ((iVar6 != 0) && (iVar5 == 8)) {

        kabutoai_anim_update(param_3,2);

      }

    }

    fVar2 = *(float *)(DAT_00632ed8 + 0xb80) * param_2 * 0.01;

    if (((param_5 != (float *)0x0) && (fVar2 < fVar1)) &&

       (fVar9 = (float10)bldg_get_energy(param_3),

       fVar9 < (float10)fVar2 != (fVar9 == (float10)fVar2))) {

      fx_get_free_effect__Fv();

    }

    fVar9 = (float10)bldg_get_energy(param_3);

    if (fVar9 < (float10)fVar2 != (fVar9 == (float10)fVar2)) {

      collgrid_clear_grid(param_3);

      *(uint *)(param_3 + 0x1c8) = *(uint *)(param_3 + 0x1c8) | 0x800;

    }

    fVar9 = (float10)bldg_get_energy(param_3);

    if (fVar9 < (float10)fVar2 != (fVar9 == (float10)fVar2)) {

      if (iVar5 < 0) {

        iVar5 = fx_create(param_3);

        if (iVar5 == 0) {

          func_0x004b5bb0(param_3,1);

          goto code_r0x004b6504;

        }

        iVar5 = reaper_0052e4a0(param_3);

        if (iVar5 != 0) {

          reaper_00530bd0(param_3,0,0,0,0x27,0);

        }

      }

      reaperbasebldg_shot_2(param_3,0);

    }

  }

code_r0x004b6504:

  reaperbase_update_icons(*(undefined4 *)(param_3 + 0x274));

  return;

}

/* ===== ret_const_x5e0_c32 @ 0x004B6520 ===== */
undefined4 ret_const_x5e0_c32(void)



{

  return 0x5e0;

}

/* ===== ret_const_x18_c74 @ 0x004B6530 ===== */
undefined4 ret_const_x18_c74(void)



{

  return 0x18;

}

/* ===== base_pair_ptr_clear_c82 @ 0x004B6540 ===== */
void base_pair_ptr_clear_c82(int param_1)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  

  iVar3 = *(int *)(param_1 + 0x100);

  iVar2 = iVar3 + 0x370;

  iVar1 = 5;

  do {

    iVar4 = 0xc;

    do {

      obj_ptr_clear_if_dead(iVar2);

      iVar2 = iVar2 + 8;

      iVar4 = iVar4 + -1;

    } while (iVar4 != 0);

    iVar1 = iVar1 + -1;

  } while (iVar1 != 0);

  iVar3 = iVar3 + 0x20;

  iVar2 = 0x1e;

  do {

    obj_ptr_clear_if_dead(iVar3);

    iVar3 = iVar3 + 0x1c;

    iVar2 = iVar2 + -1;

  } while (iVar2 != 0);

  return;

}

/* ===== base_slot_state_check @ 0x004B65A0 ===== */
void base_slot_state_check(int param_1,int param_2)



{

  int iVar1;

  int iVar2;

  float10 fVar3;

  float10 fVar4;

  

  iVar1 = *(int *)(param_1 + 0x274);

  iVar2 = *(int *)(*(int *)(iVar1 + 0x100) + 0x20 + param_2 * 0x1c);

  if (iVar2 != 0) {

    if (*(int *)(iVar2 + 0xe4) == 1) {

      *(undefined4 *)(iVar2 + 0xe4) = 2;

    }

    else {

      fVar3 = (float10)bldg_get_energy(iVar2);

      if ((float10)0.0 < fVar3) {

        fVar3 = (float10)bldg_get_energy(iVar2);

        fVar4 = (float10)bldg_get_max_energy_dup00418170(iVar2);

        if ((float10)(float)fVar3 < fVar4) {

          *(undefined4 *)(iVar2 + 0xe4) = 3;

        }

      }

    }

    *(int *)(*(int *)(param_1 + 0x100) + 0x20) = param_2;

    reaperbase_update_icons(iVar1);

  }

  return;

}

/* ===== object_spawn_4b @ 0x004B6630 ===== */
undefined4 object_spawn_4b(int param_1,uint param_2)



{

  int iVar1;

  undefined4 uVar2;

  int iVar3;

  OBJECT *obj;

  int *piVar4;

  uint uVar5;

  undefined4 local_c;

  undefined4 local_8;

  undefined4 local_4;

  

  iVar3 = *(int *)(param_1 + 0x100);

  piVar4 = (int *)(iVar3 + 0x20);

  uVar5 = 0;

  do {

    if (((uVar5 != param_2) && (*piVar4 != 0)) && (*(int *)(*piVar4 + 0xe4) < 2)) {

      if ((7 < (int)uVar5) && (piVar4[-0x38] != 0)) {

        *(undefined4 *)(piVar4[-0x38] + 0x184) = 0;

      }

      object_destroy(*piVar4);

      *piVar4 = 0;

    }

    uVar5 = uVar5 + 1;

    piVar4 = piVar4 + 7;

  } while ((int)uVar5 < 0x10);

  iVar1 = param_2 * 0x1c + iVar3;

  if ((*(int *)(param_2 * 0x1c + 0x20 + iVar3) == 0) &&

     ((7 < (int)param_2 || (*(int *)(iVar1 + 0x100) == 0)))) {

    uVar5 = param_2 & 0x80000007;

    if ((int)uVar5 < 0) {

      uVar5 = (uVar5 - 1 | 0xfffffff8) + 1;

    }

    iVar3 = uVar5 * 0x1c + iVar3;

    local_c = *(undefined4 *)(iVar3 + 0x24);

    local_8 = *(undefined4 *)(iVar3 + 0x28);

    local_4 = *(undefined4 *)(iVar3 + 0x2c);

    uVar2 = *(undefined4 *)(iVar3 + 0x30);

    obj = (OBJECT *)object_allocate_type((&DAT_005606b0)[param_2 * 0x16],0x80000000);

    object_set_location_p3d(obj,&local_c);

    *(undefined4 *)&obj->field_0xc8 = uVar2;

    *(undefined4 *)&obj->field_0xcc = 0;

    *(undefined4 *)&obj->field_0xd0 = 0;

    obj->pad_E4 = 1;

    obj->flags = obj->flags | 0x10;

    if (DAT_00632bb0 == 0) {

      obj->pad_184 = 0x3f800000;

    }

    else {

      obj->pad_184 = 0x3dcccccd;

    }

    *(int *)&obj->field_0x274 = param_1;

    bldg_set_energy(obj,0);

    ObjectSetAnim(obj);

    obj->pad_14 = 0x3f800000;

    *(uint *)&obj->field_0x1c8 = *(uint *)&obj->field_0x1c8 & 0xfffdffff | 0x800;

    *(OBJECT **)(iVar1 + 0x20) = obj;

    if (DAT_00632bb0 != 0) {

      if ((7 < (int)param_2) && (*(int *)(iVar1 + -0xc0) != 0)) {

        *(undefined4 *)(*(int *)(iVar1 + -0xc0) + 0x184) = 0x3f800000;

      }

      if (uVar5 == 0) {

        *(undefined4 *)(param_1 + 0x184) = 0x3f800000;

      }

    }

    return 1;

  }

  return 0;

}

/* ===== meccbase_hide_tentatives @ 0x004B6800 ===== */
/* PS2 candidate: meccbase_hide_tentatives_2 (conf 0.64) */



void meccbase_hide_tentatives(int param_1)



{

  undefined4 uVar1;

  int *piVar2;

  int iVar3;

  

  iVar3 = 0;

  piVar2 = (int *)(*(int *)(DAT_00632bbc + 0x100) + 0x20);

  do {

    if ((*piVar2 != 0) && (*(int *)(*piVar2 + 0xe4) < 3)) {

      if ((7 < iVar3) && (piVar2[-0x38] != 0)) {

        if (param_1 == 0) {

          uVar1 = 0x3f800000;

        }

        else {

          uVar1 = 0;

        }

        *(undefined4 *)(piVar2[-0x38] + 0x184) = uVar1;

      }

      if (param_1 == 0) {

        uVar1 = 0x3dcccccd;

      }

      else {

        uVar1 = 0x3f800000;

      }

      *(undefined4 *)(*piVar2 + 0x184) = uVar1;

    }

    iVar3 = iVar3 + 1;

    piVar2 = piVar2 + 7;

  } while (iVar3 < 0x10);

  return;

}

/* ===== objtype_anim_scan_2 @ 0x004B6870 ===== */
undefined4 objtype_anim_scan_2(int param_1,int param_2,undefined4 *param_3)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int *piVar4;

  int *piVar5;

  undefined4 *puVar6;

  float10 fVar7;

  float10 fVar8;

  int local_1c;

  int local_18;

  float local_14;

  int local_10;

  undefined1 local_c [12];

  

  iVar1 = *(int *)(param_1 + 0x100);

  iVar2 = base_bldg_is_alive_at_all(param_1,8);

  if (iVar2 != 0) {

    iVar2 = 0;

    piVar4 = (int *)(iVar1 + 0x370);

    do {

      iVar3 = 0;

      piVar5 = piVar4;

      do {

        if (*piVar5 == 0) {

          *(int *)(iVar1 + 0x370 + (iVar3 + iVar2 * 0xc) * 8) = param_2;

          *param_3 = 0xffffffff;

          return 1;

        }

        iVar3 = iVar3 + 1;

        piVar5 = piVar5 + 2;

      } while (iVar3 < 0xc);

      iVar2 = iVar2 + 1;

      piVar4 = piVar4 + 0x18;

    } while (iVar2 < 5);

    return 0;

  }

  iVar2 = base_slot_active_check(param_1,0);

  if (iVar2 == 0) {

    local_18 = param_1;

    iVar2 = 1;

  }

  else {

    local_18 = *(int *)(iVar1 + 0x20);

    iVar2 = 3;

  }

  if (local_18 == 0) {

    return 0;

  }

  local_10 = 0;

  local_1c = -1;

  if (iVar2 != 0) {

    piVar4 = (int *)(iVar1 + 0x370);

    do {

      iVar3 = 0;

      piVar5 = piVar4;

      do {

        if (*piVar5 == param_2) {

          local_1c = iVar3;

          if (local_10 == -1) goto LAB_004b696a;

          goto LAB_004b69e3;

        }

        iVar3 = iVar3 + 1;

        piVar5 = piVar5 + 2;

      } while (iVar3 < 0xc);

      local_10 = local_10 + 1;

      piVar4 = piVar4 + 0x18;

    } while (local_10 < iVar2);

  }

LAB_004b696a:

  iVar3 = 0;

  local_14 = 999999.0;

  local_10 = -1;

  if (iVar2 != 0) {

    puVar6 = (undefined4 *)(iVar1 + 0x374);

    do {

      bldg_get_refpt_worldloc(local_18,*puVar6,local_c);

      fVar7 = (float10)distancesq2d__FP3P3DT0(local_c,param_2 + 0xa0);

      if (fVar7 < (float10)local_14) {

        local_14 = (float)fVar7;

        local_10 = iVar3;

      }

      iVar3 = iVar3 + 1;

      puVar6 = puVar6 + 0x18;

    } while (iVar3 < iVar2);

  }

LAB_004b69e3:

  if ((0 < local_1c) && (iVar3 = 0, iVar2 != 0)) {

    piVar4 = (int *)(iVar1 + 0x370);

    do {

      if ((iVar3 != local_10) && (*piVar4 == 0)) {

        *(undefined4 *)(iVar1 + 0x370 + (local_1c + local_10 * 0xc) * 8) = 0;

        *param_3 = *(undefined4 *)(iVar3 * 0x60 + 0x374 + iVar1);

        *(int *)(iVar3 * 0x60 + iVar1 + 0x370) = param_2;

        return 1;

      }

      iVar3 = iVar3 + 1;

      piVar4 = piVar4 + 0x18;

    } while (iVar3 < iVar2);

  }

  iVar2 = 0;

  piVar4 = (int *)(local_10 * 0x60 + 0x370 + iVar1);

  do {

    if (*piVar4 == param_2) {

      return 0;

    }

    if ((local_1c == -1) || ((local_1c != 0 && (iVar2 == local_1c + -1)))) {

      if (*piVar4 == 0) {

        iVar3 = local_10 * 0xc + iVar2;

        *param_3 = *(undefined4 *)(iVar1 + 0x374 + iVar3 * 8);

        *(int *)(iVar1 + 0x370 + iVar3 * 8) = param_2;

LAB_004b6b5e:

        if (0xb < iVar2) {

          return 0;

        }

        iVar2 = iVar2 + 1;

        if (iVar2 < 0xc) {

          piVar4 = (int *)(iVar1 + 0x370 + (local_10 * 0xc + iVar2) * 8);

          iVar2 = 0xc - iVar2;

          do {

            if (*piVar4 == param_2) {

              *piVar4 = 0;

            }

            piVar4 = piVar4 + 2;

            iVar2 = iVar2 + -1;

          } while (iVar2 != 0);

        }

        return 1;

      }

      bldg_get_refpt_worldloc(local_18,piVar4[1],local_c);

      fVar7 = (float10)distancesq2d__FP3P3DT0(local_c,param_2 + 0xa0);

      fVar8 = (float10)distancesq2d__FP3P3DT0(local_c,*piVar4 + 0xa0);

      if ((float10)(float)fVar7 < fVar8) {

        iVar3 = local_10 * 0xc + iVar2;

        *(undefined4 *)(*(int *)(iVar1 + 0x370 + iVar3 * 8) + 0xe4) = 0x1e;

        ai_clear_move_goal(*(undefined4 *)(iVar1 + 0x370 + iVar3 * 8));

        *(undefined4 *)(*(int *)(*(int *)(iVar1 + 0x370 + iVar3 * 8) + 0x100) + 0x28) = 0xffffffff;

        *param_3 = *(undefined4 *)(iVar1 + 0x374 + iVar3 * 8);

        *(int *)(iVar1 + 0x370 + iVar3 * 8) = param_2;

        goto LAB_004b6b5e;

      }

    }

    iVar2 = iVar2 + 1;

    piVar4 = piVar4 + 2;

    if (0xb < iVar2) {

      return 0;

    }

  } while( true );

}

/* ===== base_slot0_get @ 0x004B6BB0 ===== */
void base_slot0_get(int param_1,int param_2)



{

  int iVar1;

  int *piVar2;

  int iVar3;

  

  iVar3 = *(int *)(param_1 + 0x100);

  iVar1 = base_slot_active_check(param_1,0);

  iVar1 = (-(uint)(iVar1 != 0) & 2) + 1;

  if (iVar1 != 0) {

    piVar2 = (int *)(iVar3 + 0x370);

    do {

      iVar3 = 0xc;

      do {

        if (*piVar2 == param_2) {

          *piVar2 = 0;

        }

        piVar2 = piVar2 + 2;

        iVar3 = iVar3 + -1;

      } while (iVar3 != 0);

      iVar1 = iVar1 + -1;

    } while (iVar1 != 0);

  }

  return;

}

/* ===== smartie_house_scan @ 0x004B6C00 ===== */
int smartie_house_scan(int param_1,int *param_2)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int *piVar4;

  float10 fVar5;

  float local_8;

  int local_4;

  

  iVar3 = 0;

  local_8 = 9999999.0;

  if (DAT_00632d68 != (int *)0x0) {

    iVar2 = -1;

    piVar4 = DAT_00632d68;

    do {

      iVar1 = piVar4[3];

      if ((((*(int *)(iVar1 + 4) == 0x353) &&

           (iVar2 = iVar2 + 1, ((byte)*(undefined4 *)(iVar1 + 0xe0) & 0x3f) != 0x3f)) &&

          (fVar5 = (float10)distancesq2d__FP3P3DT0(iVar1 + 0xa0,param_1 + 0xa0),

          fVar5 <= (float10)250000.0)) && (fVar5 < (float10)local_8)) {

        local_8 = (float)fVar5;

        iVar3 = iVar1;

        local_4 = iVar2;

      }

      piVar4 = (int *)*piVar4;

    } while (piVar4 != (int *)0x0);

    if (iVar3 != 0) {

      iVar2 = 0;

      do {

        if ((*(uint *)(iVar3 + 0xe0) & 1 << ((byte)iVar2 & 0x1f)) == 0) {

          *(uint *)(iVar3 + 0xe0) = 1 << ((byte)iVar2 & 0x1f) | *(uint *)(iVar3 + 0xe0);

          *param_2 = iVar2;

          return local_4;

        }

        iVar2 = iVar2 + 1;

      } while (iVar2 < 6);

    }

  }

  return -1;

}

/* ===== food_object_flag_clear @ 0x004B6CD0 ===== */
void food_object_flag_clear(undefined4 param_1,int param_2,int param_3)



{

  int iVar1;

  int *piVar2;

  int iVar3;

  

  if ((param_2 != -1) && (iVar3 = 0, piVar2 = DAT_00632d68, DAT_00632d68 != (int *)0x0)) {

    do {

      iVar1 = piVar2[3];

      if (*(int *)(iVar1 + 4) == 0x353) {

        if (iVar3 == param_2) {

          if (param_3 < 0) {

            return;

          }

          *(uint *)(iVar1 + 0xe0) = *(uint *)(iVar1 + 0xe0) & ~(1 << ((byte)param_3 & 0x1f));

          return;

        }

        iVar3 = iVar3 + 1;

      }

      piVar2 = (int *)*piVar2;

    } while (piVar2 != (int *)0x0);

    return;

  }

  return;

}

/* ===== smartie_house_get @ 0x004B6D20 ===== */
int smartie_house_get(undefined4 param_1,int param_2)



{

  undefined4 *puVar1;

  int iVar2;

  

  if (param_2 != -1) {

    iVar2 = 0;

    for (puVar1 = DAT_00632d68; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {

      if (*(int *)(puVar1[3] + 4) == 0x353) {

        if (iVar2 == param_2) {

          return puVar1[3];

        }

        iVar2 = iVar2 + 1;

      }

    }

  }

  return 0;

}

/* ===== reaperbase_get_max_energy @ 0x004B6D60 ===== */
/* PS2 candidate: reaperbase_get_max_energy (conf 0.408) */



float10 reaperbase_get_max_energy(int param_1)



{

  int iVar1;

  int *piVar2;

  

  iVar1 = reaperbase_bldg_from_object(param_1);

  if (iVar1 != 0) {

    return (float10)*(float *)(DAT_00632ed8 + 0x628);

  }

  if (*(int *)(param_1 + 0x274) != 0) {

    iVar1 = 0;

    piVar2 = (int *)(*(int *)(*(int *)(param_1 + 0x274) + 0x100) + 0x20);

    do {

      if (*piVar2 == param_1) {

        if (-1 < iVar1) {

          return (float10)(float)(&DAT_005606bc)[iVar1 * 0x16];

        }

        break;

      }

      iVar1 = iVar1 + 1;

      piVar2 = piVar2 + 7;

    } while (iVar1 < 0x10);

  }

  if ((8 < *(int *)(param_1 + 0xe4)) && (*(int *)(param_1 + 0xe4) < 0xd)) {

    return (float10)*(float *)(DAT_00632ed8 + 0x894);

  }

  return (float10)100.0;

}

/* ===== base_slot11_get @ 0x004B6DE0 ===== */
undefined4 base_slot11_get(int param_1)



{

  int iVar1;

  int iVar2;

  

  iVar1 = *(int *)(param_1 + 0x100);

  iVar2 = base_slot_active_check(param_1,0xb);

  if (iVar2 != 0) {

    return *(undefined4 *)(iVar1 + 0x154);

  }

  iVar2 = base_slot_active_check(param_1,3);

  if (iVar2 != 0) {

    return *(undefined4 *)(iVar1 + 0x74);

  }

  return 0;

}

/* ===== base_slot9or1_get @ 0x004B6E20 ===== */
undefined4 base_slot9or1_get(int param_1)



{

  int iVar1;

  int iVar2;

  

  iVar1 = *(int *)(param_1 + 0x100);

  iVar2 = base_bldg_is_alive_at_all(param_1,9);

  if (iVar2 != 0) {

    return *(undefined4 *)(iVar1 + 0x11c);

  }

  iVar2 = base_bldg_is_alive_at_all(param_1,1);

  if (iVar2 != 0) {

    return *(undefined4 *)(iVar1 + 0x3c);

  }

  iVar2 = base_bldg_is_alive_at_all_2(param_1,9);

  if (iVar2 != 0) {

    return *(undefined4 *)(iVar1 + 0x11c);

  }

  return 0;

}

/* ===== base_slot9_get @ 0x004B6E80 ===== */
undefined4 base_slot9_get(int param_1)



{

  int iVar1;

  int iVar2;

  

  iVar1 = *(int *)(param_1 + 0x100);

  iVar2 = base_bldg_is_alive_at_all(param_1,9);

  if (iVar2 != 0) {

    return *(undefined4 *)(iVar1 + 0x11c);

  }

  return 0;

}

/* ===== base_slot10_get @ 0x004B6EB0 ===== */
undefined4 base_slot10_get(int param_1)



{

  int iVar1;

  int iVar2;

  

  iVar1 = *(int *)(param_1 + 0x100);

  iVar2 = base_slot_active_check(param_1,10);

  if (iVar2 != 0) {

    return *(undefined4 *)(iVar1 + 0x138);

  }

  iVar2 = base_slot_active_check(param_1,2);

  if (iVar2 != 0) {

    return *(undefined4 *)(iVar1 + 0x58);

  }

  return 0;

}

/* ===== base_slot8_get_2 @ 0x004B6EF0 ===== */
undefined4 base_slot8_get_2(int param_1)



{

  int iVar1;

  int iVar2;

  

  iVar1 = *(int *)(param_1 + 0x100);

  iVar2 = base_slot_active_check(param_1,8);

  if (iVar2 != 0) {

    return *(undefined4 *)(iVar1 + 0x100);

  }

  return 0;

}

/* ===== base_slot8_get @ 0x004B6F20 ===== */
int base_slot8_get(int param_1)



{

  int iVar1;

  int iVar2;

  

  iVar1 = *(int *)(param_1 + 0x100);

  iVar2 = base_slot_built_check(param_1,8);

  if (iVar2 != 0) {

    return *(int *)(iVar1 + 0x100);

  }

  iVar2 = base_slot_built_check(param_1,0);

  if (iVar2 != 0) {

    return *(int *)(iVar1 + 0x20);

  }

  return param_1;

}

/* ===== meccbasepit_bldg_from_object_dup004b6f60 @ 0x004B6F60 ===== */
/* PS2 candidate: meccbasepit_bldg_from_object_2 (conf 0.767) */



int meccbasepit_bldg_from_object_dup004b6f60(int param_1)



{

  int iVar1;

  int *piVar2;

  

  if (*(int *)(param_1 + 0x274) != 0) {

    iVar1 = 0;

    piVar2 = (int *)(*(int *)(*(int *)(param_1 + 0x274) + 0x100) + 0x20);

    do {

      if (*piVar2 == param_1) {

        return iVar1;

      }

      iVar1 = iVar1 + 1;

      piVar2 = piVar2 + 7;

    } while (iVar1 < 0x10);

  }

  return -1;

}

/* ===== mecc_shot @ 0x004B6FA0 ===== */
/* PS2 candidate: mecc_shot (conf 0.462) */



void mecc_shot(int param_1,undefined4 param_2,uint param_3,float param_4)



{

  byte *pbVar1;

  uint uVar2;

  int iVar3;

  int iVar4;

  uint *puVar5;

  uint *puVar6;

  uint uVar7;

  float fVar8;

  undefined4 uVar9;

  float local_38;

  

  uVar2 = param_3;

  puVar6 = *(uint **)(param_3 + 0x100);

  iVar3 = reaper_0052e4a0(param_3);

  if (iVar3 != 0) {

    reaper_00530bd0(uVar2,0,0,0,0x38,0);

  }

  iVar3 = fx_create(uVar2);

  if (((iVar3 != 0) || (param_1 == -1)) && ((*puVar6 & 0x200) != 0)) {

    turret_exit_all_team(uVar2);

    *puVar6 = *puVar6 & 0xfffffdff;

  }

  if (((param_1 == 5) || (param_1 == 7)) || ((param_1 == 6 || (param_1 == 8)))) {

    atand2pos(*(undefined4 *)(uVar2 + 300),*(undefined4 *)(uVar2 + 0x128));

    fx_get_free_effect__Fv();

    *(uint *)(uVar2 + 0xd8) = *(uint *)(uVar2 + 0xd8) | 0x40000000;

  }

  *(undefined4 *)(uVar2 + 0x278) = *(undefined4 *)(uVar2 + 0x1c0);

  *(uint *)(uVar2 + 0xe0) = *(uint *)(uVar2 + 0xe0) & 0x600ffdf;

  *puVar6 = *puVar6 & 0xffffff3f;

  uVar7 = 0;

  if (0.0 < *(float *)(DAT_00632ed8 + 0x7c4)) {

    puVar5 = puVar6 + 0x3bf;

    do {

      if (*puVar5 != 0) {

        fx_delete(*puVar5);

      }

      *puVar5 = 0;

      uVar7 = uVar7 + 1;

      puVar5 = puVar5 + 1;

      param_3 = uVar7;

    } while ((float)(int)uVar7 < *(float *)(DAT_00632ed8 + 0x7c4));

  }

  iVar3 = fx_create(uVar2);

  if (iVar3 != 0) {

    DAT_00632bc4 = 0;

  }

  sound_stop_player(0x36c,uVar2);

  puVar6[0x3fd] = 0;

  puVar6[0x3e3] = 0;

  puVar6[0x3e6] = *(uint *)(DAT_00632ed8 + 0x8dc);

  puVar6[999] = 0;

  if (puVar6[0x3e4] != 0) {

    puVar5 = (uint *)(puVar6[0x3e4] + 0xd8);

    *puVar5 = *puVar5 | 0x40000000;

  }

  iVar3 = 0;

  if (0 < (int)puVar6[0x36b]) {

    puVar5 = puVar6 + 0x3dd;

    do {

      if (*puVar5 != 0) {

        pbVar1 = (byte *)(*puVar5 + 0xdb);

        *pbVar1 = *pbVar1 | 0x40;

      }

      iVar3 = iVar3 + 1;

      puVar5 = puVar5 + 1;

    } while (iVar3 < (int)puVar6[0x36b]);

  }

  if (param_1 != -1) {

    iVar3 = crt_rand_scaled(100);

    if (iVar3 < 0x32) {

      uVar9 = 0x6a1;

    }

    else {

      uVar9 = 0x6a2;

    }

    sound_play_player(uVar9,uVar2);

  }

  sound_stop_player(0x69c,uVar2);

  sound_stop_player(0x69d,uVar2);

  sound_stop_player(0x69e,uVar2);

  sound_stop_player(0x69f,uVar2);

  if (DAT_00632f08 == 0) {

    hud_feed_buffer_clear();

    DAT_00632c00 = 1;

  }

  iVar3 = reaper_0052e4a0(uVar2);

  if ((iVar3 != 0) && ((*(byte *)(uVar2 + 0x1c8) & 1) != 0)) {

    fVar8 = param_4;

    if ((param_4 != 0.0) && (*(float *)((int)param_4 + 0x274) != 0.0)) {

      fVar8 = *(float *)((int)param_4 + 0x274);

    }

    if (param_1 != 0x13) {

      if (fVar8 == 0.0) {

        iVar3 = 0;

      }

      else {

        iVar3 = *(int *)((int)fVar8 + 0x18c) + -1;

      }

      param_4 = (float)DAT_00632f24;

      if (iVar3 < 0) {

        iVar3 = 0;

      }

      iVar4 = ObjIsTurret(fVar8);

      if (iVar4 == 0) {

        comm_kill_message(fVar8,uVar2,param_1);

      }

      else {

        comm_kill_message2(*(int *)((int)fVar8 + 0x18c) + -1,uVar2,0x30);

        fVar8 = 0.0;

      }

      if (iVar3 == 3) {

        param_4 = (float)DAT_00632f24 * 0.2;

      }

      iVar4 = game_mode_set2_check(DAT_00632f18);

      if (iVar4 == 0) {

        local_38 = param_4;

      }

      else {

        local_38 = 0.0;

      }

      comm_death_packet_build

                (fVar8,uVar2,iVar3,*(int *)(uVar2 + 0x18c) + -1,param_4,local_38,0x3f800000,

                 0x3f800000);

    }

    param_3 = param_3 & 0xff000000;

    comm_chat_send_2(uVar2,0,0,3,3,&param_3);

  }

  iVar3 = reaper_0052e4a0(uVar2);

  if (iVar3 != 0) {

    if (1 < (int)puVar6[0x36d]) {

      iVar3 = *(int *)(uVar2 + 0x100);

      item_drop_item(uVar2,*(undefined4 *)(iVar3 + 0xd70 + *(int *)(iVar3 + 0xdb4) * 8),

                     *(undefined4 *)(iVar3 + 0xd74 + *(int *)(iVar3 + 0xdb4) * 8),

                     *(float *)(uVar2 + 0x29c) * -30.0,*(float *)(uVar2 + 0x2ac) * -30.0,0x41700000,

                     0x41f00000);

      reaper_set_bow(uVar2,*(undefined4 *)(iVar3 + 0xd70 + *(int *)(iVar3 + 0xdb4) * 8),0xffffffff,0

                     ,1);

      *(uint *)(uVar2 + 0x20c) = *(uint *)(uVar2 + 0x20c) & 0xffffff3f;

    }

    puVar5 = puVar6 + 0x360;

    iVar3 = 3;

    do {

      if (*puVar5 != 0xffffffff) {

        *puVar5 = 0xffffffff;

        puVar5[1] = 0;

      }

      puVar5 = puVar5 + 2;

      iVar3 = iVar3 + -1;

    } while (iVar3 != 0);

    puVar6[0x36d] = 0;

    reaper_select_sword(uVar2);

    puVar5 = puVar6 + 0x351;

    iVar3 = 5;

    do {

      puVar5[-2] = 0xffffffff;

      *puVar5 = 0;

      puVar5 = puVar5 + 3;

      iVar3 = iVar3 + -1;

    } while (iVar3 != 0);

    puVar6[0x36c] = 0xffffffff;

    puVar6 = puVar6 + 0x367;

    iVar3 = 2;

    do {

      puVar6[-1] = 0xffffffff;

      *puVar6 = 0;

      puVar6 = puVar6 + 2;

      iVar3 = iVar3 + -1;

    } while (iVar3 != 0);

  }

  iVar3 = dialog_level_is_base_dup0052aa70();

  if ((iVar3 != 0) &&

     (((((param_1 == 5 || (param_1 == 7)) || (param_1 == 6)) || (param_1 == 8)) &&

      (iVar3 = gun_find_right(uVar2), iVar3 != 0)))) {

    *(uint *)(iVar3 + 0xd8) = *(uint *)(iVar3 + 0xd8) | 0x40000000;

  }

  return;

}

/* ===== reaper_animselect @ 0x004B7450 ===== */
/* WARNING: Removing unreachable block (ram,0x004b7a7a) */

/* WARNING: Removing unreachable block (ram,0x004b7a90) */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* PS2 candidate: reaper_animselect (conf 0.584) */



void reaper_animselect(int param_1,undefined4 param_2,undefined4 param_3,float *param_4)



{

  int *piVar1;

  float fVar2;

  uint *puVar3;

  uint uVar4;

  undefined4 uVar5;

  int *piVar6;

  int iVar7;

  int iVar8;

  int iVar9;

  OBJECT *obj;

  float fVar10;

  float *pfVar11;

  undefined4 *puVar12;

  float *pfVar13;

  float10 fVar14;

  undefined4 uVar15;

  undefined4 uVar16;

  undefined4 uVar17;

  undefined4 uVar18;

  float local_40;

  float local_3c;

  float local_38;

  float local_30;

  float local_2c;

  float local_28;

  

  iVar7 = param_1;

  if (*(int *)(param_1 + 0x104) == 0) {

    reaper_init__FP6OBJECT(param_1);

  }

  pfVar11 = param_4;

  switch(param_2) {

  case 1:

    puVar3 = *(uint **)(param_1 + 0x100);

    if ((*puVar3 & 0x400) == 0) {

      if (*(float *)(param_1 + 0x1c0) <= *(float *)(param_1 + 0x278)) {

        uVar4 = puVar3[0x3fe];

        puVar3[0x3fe] = uVar4 + 1;

        if (uVar4 + 1 != 2) {

          return;

        }

        puVar3[0x3fe] = 0;

        *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) & 0xbfffffff;

        iVar7 = gun_find_right(param_1);

        if (iVar7 != 0) {

          *(uint *)(iVar7 + 0xd8) = *(uint *)(iVar7 + 0xd8) & 0xbfffffff;

        }

      }

      puVar3[0x3f6] = (uint)(*param_4 - *(float *)(param_1 + 0xa0));

      puVar3[0x3f7] = (uint)(param_4[1] - *(float *)(param_1 + 0xa4));

      fVar10 = param_4[2];

      fVar2 = *(float *)(param_1 + 0xa8);

      puVar3[0x3f9] = 0;

      puVar3[0x3f8] = (uint)(fVar10 - fVar2);

      *(float *)(param_1 + 0x128) = param_4[3];

      *(float *)(param_1 + 300) = param_4[4];

      *(float *)(param_1 + 0x130) = param_4[5];

      *(float *)(param_1 + 200) = param_4[6];

      *(float *)(param_1 + 0x114) = param_4[7];

      *(float *)(param_1 + 0x278) = param_4[8];

      if ((*(uint *)(param_1 + 0xd8) & 0x4000) != 0) {

        obj_children_flag_clear(param_1);

        return;

      }

    }

    break;

  case 2:

    *(undefined1 *)(param_1 + 0x20a) = *(undefined1 *)(param_4 + 4);

    *(undefined1 *)(param_1 + 0x20b) = *(undefined1 *)((int)param_4 + 0x11);

    *(undefined1 *)(param_1 + 0x208) = *(undefined1 *)((int)param_4 + 0x12);

    *(float *)(param_1 + 0x158) = *param_4;

    *(float *)(param_1 + 0x15c) = param_4[1];

    *(float *)(param_1 + 0x160) = param_4[2];

    *(float *)(param_1 + 0x164) = param_4[3];

    *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) & 0xfcffffff;

    break;

  case 3:

    *(undefined1 *)(param_1 + 0x20a) = *(undefined1 *)param_4;

    *(undefined1 *)(param_1 + 0x20b) = *(undefined1 *)((int)param_4 + 1);

    *(undefined1 *)(param_1 + 0x208) = *(undefined1 *)((int)param_4 + 2);

    *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) & 0xfcffffff;

    return;

  case 4:

    *(undefined4 *)(*(int *)(param_1 + 0x100) + 0xdb4) = 0;

    reaper_select_sword(param_1);

    return;

  case 5:

    iVar7 = *(int *)(param_1 + 0x100);

    *(undefined4 *)(iVar7 + 0xdb4) = 3;

    *(float *)(iVar7 + 0xd88) = *param_4;

    reaper_select_bow(param_1);

    return;

  case 7:

    iVar7 = *(int *)(param_1 + 0x100);

    *(undefined4 *)(iVar7 + 0xf40) = 1;

    if (param_4[6] == -NAN) {

      *(undefined4 *)(iVar7 + 0xc) = 0;

    }

    else {

      uVar5 = objanim_select_animloop(param_4[6]);

      *(undefined4 *)(iVar7 + 0xc) = uVar5;

    }

    *(float *)(iVar7 + 0x1c) = *pfVar11;

    *(float *)(iVar7 + 0x20) = pfVar11[1];

    *(float *)(iVar7 + 0x24) = pfVar11[2];

    *(float *)(param_1 + 0xa0) = pfVar11[3];

    *(float *)(param_1 + 0xa4) = pfVar11[4];

    *(float *)(param_1 + 0xa8) = pfVar11[5];

    reaper_ability_sound(param_1);

    return;

  case 9:

    make_arrow__FP6OBJECTT0P3P3DPUii(param_1,0,param_4,param_4 + 3,0x2c);

    return;

  case 10:

    reaper_tornado_create(param_1,param_4,param_4[3],param_4[4]);

    return;

  case 0xb:

    reaper_summon_spawn(param_1,param_4,param_4[3]);

    return;

  case 0xd:

    iVar7 = objanim_select_animloop(param_4[1]);

    param_4 = (float *)*pfVar11;

    if (iVar7 != 0) {

      object_destroy(iVar7);

    }

    iVar7 = crt_rand_scaled(100);

    if (iVar7 < 0x32) {

      uVar5 = 0x10a;

    }

    else {

      uVar5 = 0x385;

    }

    sound_play_player(uVar5,param_1);

    *(float **)(*(int *)(param_1 + 0x100) + 0xcec) = param_4;

    player_voice_timer_update(param_1,param_4);

    return;

  case 0xe:

    iVar7 = *(int *)(param_1 + 0x100);

    if (*(int *)(iVar7 + 0xcf4) == 0) {

      iVar9 = object_allocate_type(0x45d,0);

      *(int *)(iVar7 + 0xcf4) = iVar9;

      *(undefined4 *)(iVar9 + 0xc4) = 0x3f000000;

    }

    *(undefined4 *)(iVar7 + 0xcf8) = 0;

    param_4 = (float *)(uint)*(byte *)param_4;

    *(float *)(iVar7 + 0xcec) = (float)(int)param_4;

    iVar9 = dialog_level_is_base_dup0052aa70();

    if (iVar9 == 0) {

      fVar14 = (float10)1.0;

    }

    else {

      fVar14 = (float10)kbos_food_value__Fi(DAT_00632f40);

    }

    obj_maxspeed_lookup(*(undefined4 *)(iVar7 + 0xcfc),

                        (float)((float10)*(float *)(DAT_00632ed8 + 0x61c) * fVar14));

    sound_play_player(0x3ce,param_1);

    return;

  case 0xf:

    iVar7 = *(int *)(param_1 + 0x100);

    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xffdfffff;

    iVar9 = fx_create(param_1);

    if (iVar9 != 0) {

      *(undefined4 *)(iVar7 + 0xe8c) = uRam00000000;

      *(undefined4 *)(iVar7 + 0xe90) = _DAT_00000004;

      *(undefined4 *)(iVar7 + 0xe94) = _DAT_00000008;

      iVar7 = reaper_0052e4a0(param_1);

      if (iVar7 != 0) {

        reaper_00530bd0(param_1,0,0,0,0xf,0);

      }

    }

    if (((*(uint *)(param_1 + 0xd8) & 0x80000) != 0) && ((**(byte **)(param_1 + 0x104) & 0x40) == 0)

       ) {

      sound_play_player(0x3a4,param_1);

      *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 0x200000;

      return;

    }

    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xffdfffff;

    iVar7 = fx_create(param_1);

    if (iVar7 != 0) {

      reaper_fire_spell__FP6OBJECTiP3P3DT0i(param_1,0x25,0,0,0xffffffff);

      return;

    }

    break;

  case 0x10:

    iVar7 = *(int *)(param_1 + 0x100);

    if (((*(uint *)(param_1 + 0xd8) & 0x80000) == 0) || ((**(byte **)(param_1 + 0x104) & 0x40) != 0)

       ) {

      iVar7 = fx_create(param_1);

      if (iVar7 != 0) {

        reaper_fire_spell__FP6OBJECTiP3P3DT0i(param_1,0x26,0,0,0xffffffff);

        *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xbfffffff;

        return;

      }

LAB_004b8187:

      *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xbfffffff;

      return;

    }

    sound_play_player(0x3a4,param_1);

    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 0x40000000;

    iVar9 = fx_create(param_1);

    if (iVar9 != 0) {

      *(undefined4 *)(iVar7 + 0xe40) = uRam00000000;

      *(undefined4 *)(iVar7 + 0xe44) = _DAT_00000004;

      *(undefined4 *)(iVar7 + 0xe48) = _DAT_00000008;

      iVar7 = reaper_0052e4a0(param_1);

      if (iVar7 != 0) {

        reaper_00530bd0(param_1,0,0,0,0x10,0);

        return;

      }

    }

    break;

  case 0x11:

    iVar7 = *(int *)(param_1 + 0x100);

    if (((*(uint *)(param_1 + 0xd8) & 0x80000) == 0) || ((**(byte **)(param_1 + 0x104) & 0x40) != 0)

       ) {

      *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xffefffff;

      iVar9 = fx_create(param_1);

      if (iVar9 != 0) {

        reaper_fire_spell__FP6OBJECTiP3P3DT0i(param_1,0x24,0,0,0xffffffff);

      }

    }

    else {

      sound_play_player(0x3a4,param_1);

      *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 0x100000;

    }

    iVar9 = fx_create(param_1);

    if (iVar9 != 0) {

      *(undefined4 *)(iVar7 + 0xe98) = uRam00000000;

      *(undefined4 *)(iVar7 + 0xe9c) = _DAT_00000004;

      *(undefined4 *)(iVar7 + 0xea0) = _DAT_00000008;

      iVar7 = reaper_0052e4a0(param_1);

      if (iVar7 != 0) {

        reaper_00530bd0(param_1,0,0,0,0x11,0);

        return;

      }

    }

    break;

  case 0x12:

    if (((*(uint *)(param_1 + 0xd8) & 0x80000) == 0) || ((**(byte **)(param_1 + 0x104) & 0x40) != 0)

       ) {

      fxb_cloak_create(param_1);

    }

    else {

      sound_play_player(0x39d,param_1);

      *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 0x80000000;

    }

    iVar7 = reaper_0052e4a0(param_1);

    if (iVar7 != 0) {

      reaper_00530bd0(param_1,0,0,0,0x12,0);

      return;

    }

    break;

  case 0x13:

    iVar7 = *(int *)(param_1 + 0x100);

    pfVar11 = (float *)(iVar7 + 0x30);

    *pfVar11 = *param_4;

    *(float *)(iVar7 + 0x34) = param_4[1];

    *(float *)(iVar7 + 0x38) = param_4[2];

    if (((*(uint *)(param_1 + 0xd8) & 0x80000) == 0) || ((**(byte **)(param_1 + 0x104) & 0x40) != 0)

       ) {

      iVar9 = reaper_0052e4a0(param_1);

      if (iVar9 != 0) {

        local_40 = *pfVar11;

        local_3c = *(float *)(iVar7 + 0x34);

        local_38 = *(float *)(iVar7 + 0x38);

        reaper_00530bd0(param_1,3,0,0,0x13,&local_40);

      }

      *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xff7fffff;

      reaper_create_fake_reaper__FP6OBJECTP3P3Dfi(param_1,pfVar11);

      *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 8;

      return;

    }

    sound_play_player(0x39d,param_1);

    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 0x800000;

    iVar9 = reaper_0052e4a0(param_1);

    if (iVar9 != 0) {

      local_40 = *pfVar11;

      local_3c = *(float *)(iVar7 + 0x34);

      local_38 = *(float *)(iVar7 + 0x38);

      reaper_00530bd0(param_1,3,0,0,0x13,&local_40);

      return;

    }

    break;

  case 0x14:

    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xff7fffff;

    pfVar13 = param_4 + 9;

    param_4 = (float *)0x3;

    do {

      fVar10 = *pfVar13;

      obj = (OBJECT *)object_allocate_type(*(undefined4 *)(param_1 + 4),0x80000000);

      obj->ai_state_b = *(dword *)(param_1 + 0x18c);

      object_create_child(obj,1,0x29d);

      object_change_ospec(obj,0x55);

      *(float *)&obj->field_0xf4 = fVar10;

      object_set_location_p3d(obj,pfVar11);

      *(uint *)&obj->field_0x1c8 = *(uint *)&obj->field_0x1c8 | 0x20000;

      *(int *)&obj->field_0x274 = param_1;

      if ((DAT_00560c50 != 0xfe) && (*(int *)(*(int *)(param_1 + 8) + 8 + DAT_00560c50 * 4) != 0)) {

        ObjectSetAnim(obj);

      }

      sound_play_obj(0x3c0);

      pfVar13 = pfVar13 + 1;

      pfVar11 = pfVar11 + 3;

      param_4 = (float *)((int)param_4 + -1);

    } while (param_4 != (float *)0x0);

    return;

  case 0x15:

    iVar7 = *(int *)(param_1 + 0x100);

    iVar9 = fx_create(param_1);

    if (iVar9 != 0) {

      *(undefined4 *)(iVar7 + 0xe64) = uRam00000000;

      *(undefined4 *)(iVar7 + 0xe68) = _DAT_00000004;

      *(undefined4 *)(iVar7 + 0xe6c) = _DAT_00000008;

      iVar7 = reaper_0052e4a0(param_1);

      if (iVar7 != 0) {

        reaper_00530bd0(param_1,0,0,0,0x15,0);

      }

    }

    if (((*(uint *)(param_1 + 0xd8) & 0x80000) != 0) && ((**(byte **)(param_1 + 0x104) & 0x40) == 0)

       ) {

      sound_play_player(0x3a4,param_1);

      *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 0x1000000;

      return;

    }

    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xfeffffff;

    iVar7 = fx_create(param_1);

    if (iVar7 != 0) {

      reaper_fire_spell__FP6OBJECTiP3P3DT0i(param_1,0x27,0,0,0xffffffff);

      return;

    }

    break;

  case 0x16:

    iVar9 = objanim_select_animloop(*param_4);

    iVar7 = *(int *)(param_1 + 0x100);

    iVar8 = reaper_0052e4a0(param_1);

    if (iVar8 != 0) {

      param_4 = *(float **)(iVar9 + 0x188);

      reaper_00530bd0(param_1,0,1,0,0x16,&param_4);

    }

    *(int *)(iVar7 + 0xea4) = iVar9;

    if (((*(uint *)(param_1 + 0xd8) & 0x80000) != 0) && ((**(byte **)(param_1 + 0x104) & 0x40) == 0)

       ) {

      sound_play_player(0x39c,param_1);

      *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 0x80000;

      return;

    }

    iVar7 = *(int *)(param_1 + 0x100);

    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xfff7ffff;

    iVar9 = *(int *)(iVar7 + 0xea4);

    if (iVar9 != 0) {

      if (*(int *)(iVar9 + 0x274) == 0) {

        ObjIsKabuto(*(undefined4 *)(iVar9 + 0x210));

      }

      else {

        iVar9 = ObjIsMecc(*(int *)(iVar9 + 0x274));

        if ((iVar9 != 0) ||

           (iVar9 = ObjIsReaper(*(undefined4 *)(*(int *)(iVar7 + 0xea4) + 0x274)), iVar9 != 0)) {

          smartie_unlock_from_player

                    (*(int *)(iVar7 + 0xea4),*(undefined4 *)(*(int *)(iVar7 + 0xea4) + 0x274),4);

        }

      }

      fx_reaper_bubble_create(*(undefined4 *)(iVar7 + 0xea4),param_1);

    }

    *(undefined4 *)(iVar7 + 0xea4) = 0;

    return;

  case 0x17:

    iVar7 = *(int *)(param_1 + 0x100);

    *(float *)(iVar7 + 0xea8) = param_4[0x12];

    pfVar13 = (float *)(iVar7 + 0xeac);

    for (iVar9 = 0xf; iVar9 != 0; iVar9 = iVar9 + -1) {

      *pfVar13 = *pfVar11;

      pfVar11 = pfVar11 + 1;

      pfVar13 = pfVar13 + 1;

    }

    pfVar11 = param_4 + 0x13;

    pfVar13 = (float *)(iVar7 + 0xee8);

    for (iVar9 = 5; iVar9 != 0; iVar9 = iVar9 + -1) {

      *pfVar13 = *pfVar11;

      pfVar11 = pfVar11 + 1;

      pfVar13 = pfVar13 + 1;

    }

    *(float *)(iVar7 + 0xf10) = param_4[0xf];

    *(float *)(iVar7 + 0xf14) = param_4[0x10];

    *(float *)(iVar7 + 0xf18) = param_4[0x11];

    reaper_finish_hail__FP6OBJECT(param_1);

    return;

  case 0x18:

    iVar7 = objanim_select_animloop(*param_4);

    *(int *)(*(int *)(param_1 + 0x100) + 0xf28) = iVar7;

    if (((*(uint *)(param_1 + 0xd8) & 0x80000) == 0) || ((**(byte **)(param_1 + 0x104) & 0x40) != 0)

       ) {

      iVar9 = fx_create(param_1);

      if (iVar9 != 0) {

        iVar9 = dialog_level_is_base_dup0052aa70();

        if (iVar9 != 0) {

          param_4 = *(float **)(iVar7 + 0x188);

          reaper_00530bd0(param_1,0,1,0,0x18,&param_4);

        }

        reaper_finish_slow_follow__FP6OBJECTPUi(param_1,0);

        return;

      }

    }

    else {

      *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 0x20000;

      iVar9 = reaper_0052e4a0(param_1);

      if (iVar9 != 0) {

        param_4 = *(float **)(iVar7 + 0x188);

        reaper_00530bd0(param_1,0,1,0,0x18,&param_4);

        return;

      }

    }

    break;

  case 0x19:

    iVar7 = *(int *)(param_1 + 0x100);

    *(float *)(iVar7 + 0xf2c) = *param_4;

    *(float *)(iVar7 + 0xf30) = param_4[1];

    *(float *)(iVar7 + 0xf34) = param_4[2];

    if (((*(uint *)(param_1 + 0xd8) & 0x80000) == 0) || ((**(byte **)(param_1 + 0x104) & 0x40) != 0)

       ) {

      iVar9 = fx_create(param_1);

      if (iVar9 != 0) {

        iVar9 = dialog_level_is_base_dup0052aa70();

        if (iVar9 != 0) {

          local_40 = *pfVar11;

          local_3c = pfVar11[1];

          local_38 = pfVar11[2];

          reaper_00530bd0(param_1,3,0,0,0x19,&local_40);

        }

        *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xfffeffff;

        fxb_firecircle_create(param_1,(float *)(iVar7 + 0xf2c),0xffffffff,0xffffffff);

        return;

      }

    }

    else {

      sound_play_player(0x39c,param_1);

      *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 0x10000;

      iVar7 = reaper_0052e4a0(param_1);

      if (iVar7 != 0) {

        local_40 = *pfVar11;

        local_3c = pfVar11[1];

        local_38 = pfVar11[2];

        reaper_00530bd0(param_1,3,0,0,0x19,&local_40);

        return;

      }

    }

    break;

  case 0x1a:

    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 0x40000;

    return;

  case 0x1b:

    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xfffeffff;

    fxb_firecircle_create(param_1,*(int *)(param_1 + 0x100) + 0xf2c,*param_4,param_4[1]);

    return;

  case 0x1c:

    fxb_firewall_create(param_1,*(int *)(param_1 + 0x100) + 0xe80,*(int *)(param_1 + 0x100) + 0xe84,

                        0x400000,*param_4);

    return;

  case 0x1d:

    iVar7 = *(int *)(param_1 + 0x100);

    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xfeffffff;

    reaper_cast_firewall

              (param_1,iVar7 + 0xe80,param_4,iVar7 + 0xe84,iVar7 + 0xe88,param_4[6],param_4 + 3,

               0x400000,param_4[7]);

    return;

  case 0x1e:

    reaper_finish_slow_follow__FP6OBJECTPUi(param_1,param_4);

    return;

  case 0x1f:

    uVar5 = 0x2d;

    goto LAB_004b76fe;

  case 0x20:

    iVar7 = *(int *)(param_1 + 0x100);

    uVar5 = objanim_select_animloop(param_4[3]);

    *(undefined4 *)(iVar7 + 0xf8c) = uVar5;

    *(undefined4 *)(iVar7 + 0xf98) = 0;

    make_arrow__FP6OBJECTT0P3P3DPUii(param_1,uVar5,pfVar11,pfVar11 + 4,0x2f);

    return;

  case 0x21:

    uVar5 = 0x2e;

LAB_004b76fe:

    make_arrow__FP6OBJECTT0P3P3DPUii(param_1,0,param_4,param_4 + 3,uVar5);

    return;

  case 0x22:

    iVar9 = *(int *)(param_1 + 0x100);

    param_1 = 0;

    if (0 < *(int *)(iVar9 + 0xdac)) {

      puVar12 = (undefined4 *)(iVar9 + 0xf60);

      pfVar11 = param_4 + 3;

      do {

        uVar5 = objanim_select_animloop(*pfVar11);

        *puVar12 = uVar5;

        param_1 = param_1 + 1;

        pfVar11 = pfVar11 + 1;

        puVar12 = puVar12 + 1;

      } while (param_1 < *(int *)(iVar9 + 0xdac));

    }

    make_arrow__FP6OBJECTT0P3P3DPUii(iVar7,0,param_4,param_4 + 8,0x30);

    return;

  case 0x23:

    iVar7 = objanim_select_animloop(*param_4);

    if (iVar7 != 0) {

      object_attach_target(param_1,iVar7);

      return;

    }

    break;

  case 0x24:

    switch(*(undefined4 *)

            (*(int *)(param_1 + 0x100) + 0xd70 + *(int *)(*(int *)(param_1 + 0x100) + 0xdb4) * 8)) {

    case 0x2c:

      uVar5 = 0x38c;

      break;

    case 0x2d:

      uVar5 = 0x38f;

      break;

    case 0x2e:

      uVar5 = 0x394;

      break;

    case 0x2f:

      uVar5 = 0x369;

      break;

    case 0x30:

      uVar5 = 0x388;

      break;

    default:

      uVar5 = 0;

    }

    sound_play_player(uVar5,param_1);

    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 0x40;

    return;

  case 0x25:

    switch(*(undefined4 *)

            (*(int *)(param_1 + 0x100) + 0xd70 + *(int *)(*(int *)(param_1 + 0x100) + 0xdb4) * 8)) {

    case 0x2c:

      uVar5 = 0x38c;

      break;

    case 0x2d:

      uVar5 = 0x38f;

      break;

    case 0x2e:

      uVar5 = 0x394;

      break;

    case 0x2f:

      uVar5 = 0x369;

      break;

    case 0x30:

      uVar5 = 0x388;

      break;

    default:

      uVar5 = 0;

    }

    sound_play_player(uVar5,param_1);

    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 0x80;

    return;

  case 0x26:

    puVar3 = *(uint **)(param_1 + 0x100);

    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xffffff7f;

    if (puVar3[0x38e] != 0) {

      fx_delete(puVar3[0x38e]);

      puVar3[0x38e] = 0;

    }

    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xffffffbf;

    *puVar3 = *puVar3 & 0xfffffffe;

    return;

  case 0x27:

    reaper_finish_cloak(param_1,0);

    return;

  case 0x28:

    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xffffff7f;

    return;

  case 0x29:

    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 0x200;

    *(int *)(*(int *)(param_1 + 0x100) + 4) = *(int *)(*(int *)(param_1 + 0x100) + 4) + 1;

    return;

  case 0x2a:

    reaper_fire_spell__FP6OBJECTiP3P3DT0i(param_1,0x27,param_4,0,param_4[3]);

    return;

  case 0x2b:

    reaper_fire_spell__FP6OBJECTiP3P3DT0i(param_1,0x26,param_4,0,param_4[3]);

    return;

  case 0x2c:

    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xffefffff;

    reaper_fire_spell__FP6OBJECTiP3P3DT0i(param_1,0x24,param_4,0,param_4[3]);

    return;

  case 0x2d:

    piVar1 = (int *)(*(int *)(param_1 + 0x100) + 0xdbc);

    iVar7 = 0;

    piVar6 = piVar1;

    while (*piVar6 != 0) {

      iVar7 = iVar7 + 1;

      piVar6 = piVar6 + 7;

      if (3 < iVar7) {

        return;

      }

    }

    if (iVar7 < 4) {

      uVar5 = objanim_select_animloop(*param_4);

      reaper_finish_shrinker(param_1,uVar5,piVar1,iVar7);

      return;

    }

    break;

  case 0x2f:

    local_30 = *param_4;

    local_2c = param_4[1];

    local_28 = param_4[2];

    fx_get_free_effect__Fv();

    FRateSlowTime(param_1,pfVar11,*(undefined4 *)(DAT_00632ed8 + 0x6f8),

                  *(undefined4 *)(DAT_00632ed8 + 0x6fc),*(undefined4 *)(DAT_00632ed8 + 0x700));

    uVar18 = 0;

    uVar17 = 0;

    uVar16 = 0x3bd;

    fVar10 = *(float *)(DAT_00632ed8 + 0x6f8) - 3.0;

    uVar15 = 0x3be;

    uVar5 = 0x3bf;

    pfVar13 = pfVar11;

    sound_get_free_sequence__Fv();

    iVar7 = reaper_0052e4a0(param_1,uVar5,uVar15,fVar10,uVar16,uVar17,pfVar13,uVar18);

    if (iVar7 != 0) {

      local_40 = *pfVar11;

      local_3c = pfVar11[1];

      local_38 = pfVar11[2];

      reaper_00530bd0(param_1,3,0,0,0x2f,&local_40);

      return;

    }

    break;

  case 0x30:

    uVar5 = objanim_select_animloop(*param_4);

    iVar7 = fx_create(param_1);

    if (iVar7 != 0) {

      giftshopview_enable(0,uVar5);

      fVar14 = (float10)tracer_entry_angle(uVar5,0);

      *(float *)(param_1 + 200) = (float)fVar14;

      playerobj_eval_refpt(param_1,0,(undefined4 *)(param_1 + 0xa0));

      object_set_location(param_1,*(undefined4 *)(param_1 + 0xa0),*(undefined4 *)(param_1 + 0xa4),

                          *(undefined4 *)(param_1 + 0xa8));

      *(undefined1 *)(param_1 + 0x20a) = 0;

      *(undefined1 *)(param_1 + 0x20b) = 0;

      *(undefined1 *)(param_1 + 0x208) = 0;

    }

    iVar7 = fx_create(uVar5);

    if (iVar7 == 0) {

      minishop_update_mecc_icons_2(uVar5,pfVar11[1]);

      return;

    }

    break;

  case 0x31:

    reaper_fire_spell__FP6OBJECTiP3P3DT0i(param_1,0x2c,param_4,0,param_4[3]);

    return;

  case 0x32:

    iVar7 = *(int *)(param_1 + 0x100);

    *(undefined4 *)(iVar7 + 0xdb4) = 3;

    *(float *)(iVar7 + 0xd88) = *param_4;

    reaper_change_bow__FP6OBJECT(param_1);

    return;

  case 0x33:

    iVar7 = objanim_select_animloop(*param_4);

    fVar10 = (float)objanim_select_animloop(pfVar11[1]);

    if (fVar10 == 0.0) {

      param_4 = (float *)fVar10;

      local_40 = fVar10;

      local_3c = fVar10;

      local_38 = fVar10;

      if (iVar7 != 0) {

        bldg_get_refpt_worldlocdir(iVar7,2,&local_40,&param_4);

      }

      fVar10 = (float)object_allocate_type(0x434,0x80000000);

      object_set_location_p3d(fVar10,&local_40);

      *(float **)((int)fVar10 + 200) = param_4;

      *(uint *)((int)fVar10 + 0x1d0) = *(uint *)((int)fVar10 + 0x1d0) | 0xf0f;

    }

    *(undefined4 *)((int)fVar10 + 0x18c) = *(undefined4 *)(param_1 + 0x18c);

    *(float *)((int)fVar10 + 0x188) = pfVar11[1];

    break;

  case 0x34:

    reaper_fire_spell__FP6OBJECTiP3P3DT0i(param_1,0x32,param_4,0,param_4[3]);

    return;

  case 0x35:

    iVar7 = *(int *)(param_1 + 0x100);

    if (((*(uint *)(param_1 + 0xd8) & 0x80000) == 0) || ((**(byte **)(param_1 + 0x104) & 0x40) != 0)

       ) {

      iVar7 = fx_create(param_1);

      if (iVar7 != 0) {

        reaper_fire_spell__FP6OBJECTiP3P3DT0i(param_1,0x33,0,0,0xffffffff);

      }

      goto LAB_004b8187;

    }

    sound_play_player(0x3af,param_1);

    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 0x20000000;

    iVar9 = fx_create(param_1);

    if (iVar9 != 0) {

      *(undefined4 *)(iVar7 + 0xe58) = uRam00000000;

      *(undefined4 *)(iVar7 + 0xe5c) = _DAT_00000004;

      *(undefined4 *)(iVar7 + 0xe60) = _DAT_00000008;

      iVar7 = reaper_0052e4a0(param_1);

      if (iVar7 != 0) {

        reaper_00530bd0(param_1,0,0,0,0x35,0);

        return;

      }

    }

    break;

  case 0x36:

    reaper_fire_spell__FP6OBJECTiP3P3DT0i(param_1,0x33,param_4,0,param_4[3]);

    return;

  case 0x37:

    sound_play_3dpos(0x6ea,param_1 + 0xa0);

    pfVar11 = param_4;

    object_set_location_p3d(param_1,param_4);

    *(float *)(param_1 + 200) = pfVar11[3];

    playerobj_zap_movement(param_1);

    sound_play_3dpos(0x6ea,param_1 + 0xa0);

    return;

  case 0x38:

    puVar3 = *(uint **)(param_1 + 0x100);

    if (*(float *)(param_1 + 0x278) < *(float *)(param_1 + 0x1c0)) {

      mecc_shot(0xffffffff,0,param_1,0,0,0);

      *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) | 0x40000000;

      iVar7 = gun_find_right(param_1);

      if (iVar7 != 0) {

        *(uint *)(iVar7 + 0xd8) = *(uint *)(iVar7 + 0xd8) | 0x40000000;

      }

    }

    *puVar3 = *puVar3 | 0x400;

    return;

  }

  return;

}

/* ===== camera_fov_chase @ 0x004B89D0 ===== */
/* PS2 candidate: reaper_camdist_modify (conf 0.301) */



void camera_fov_chase(int param_1,float *param_2,float *param_3)



{

  float fVar1;

  

  if ((*(uint *)(param_1 + 0xe0) & 0x100) == 0) {

    if (*param_2 != *param_3) {

      chase_value_time(0x3dcccccd,0x41200000,0x42480000,*param_2,param_3);

      *param_2 = *param_3;

    }

  }

  else {

    fVar1 = *param_2 + 5.0;

    *param_2 = fVar1;

    if (fVar1 != *param_3) {

      chase_value_time(0x3f800000,0x41200000,0x42480000,fVar1,param_3);

      *param_2 = *param_3;

      return;

    }

  }

  return;

}

/* ===== reaper_has_bow_2 @ 0x004B8A60 ===== */
/* PS2 candidate: reaper_has_bow_5 (conf 0.652) */



int reaper_has_bow_2(int param_1)



{

  int iVar1;

  int *piVar2;

  

  iVar1 = 0;

  piVar2 = (int *)(*(int *)(param_1 + 0x100) + 0xd78);

  do {

    if (*piVar2 == -1) {

      return iVar1;

    }

    iVar1 = iVar1 + 1;

    piVar2 = piVar2 + 2;

  } while (iVar1 < 4);

  return -1;

}

/* ===== reaper_has_bow_2_dup004b8a90 @ 0x004B8A90 ===== */
undefined4 reaper_has_bow_2_dup004b8a90(int param_1,int param_2)



{

  int iVar1;

  int *piVar2;

  

  iVar1 = 0;

  piVar2 = (int *)(*(int *)(param_1 + 0x100) + 0xd78);

  do {

    if (*piVar2 == param_2) {

      return 1;

    }

    iVar1 = iVar1 + 1;

    piVar2 = piVar2 + 2;

  } while (iVar1 < 4);

  return 0;

}

/* ===== reaper_needs_ammo @ 0x004B8AC0 ===== */
/* PS2 candidate: reaper_needs_ammo (conf 0.326) */



bool reaper_needs_ammo(int param_1,undefined4 param_2)



{

  int iVar1;

  int iVar2;

  int *piVar3;

  int iVar4;

  

  iVar1 = *(int *)(param_1 + 0x100);

  switch(param_2) {

  case 0x37:

    param_1 = 0x2d;

    break;

  case 0x38:

    param_1 = 0x2f;

    break;

  case 0x39:

    param_1 = 0x2e;

    break;

  case 0x3a:

    param_1 = 0x30;

    break;

  default:

    goto switchD_004b8adc_caseD_3b;

  case 0x3c:

    iVar2 = ObjIsJetski(*(undefined4 *)(param_1 + 0x210));

    if (iVar2 != 0) {

      return *(int *)(*(int *)(*(int *)(param_1 + 0x210) + 0x100) + 0x6c) <

             *(int *)(DAT_00632ed8 + 0x1090);

    }

    break;

  case 0x3d:

    iVar2 = ObjIsJetski(*(undefined4 *)(param_1 + 0x210));

    if (iVar2 != 0) {

      return *(int *)(*(int *)(*(int *)(param_1 + 0x210) + 0x100) + 0x70) <

             *(int *)(DAT_00632ed8 + 0x108c);

    }

    break;

  case 0x3e:

    iVar2 = ObjIsJetski(*(undefined4 *)(param_1 + 0x210));

    if (iVar2 != 0) {

      return *(int *)(*(int *)(*(int *)(param_1 + 0x210) + 0x100) + 0x74) <

             *(int *)(DAT_00632ed8 + 0x1088);

    }

  }

  iVar2 = 0;

  piVar3 = (int *)(iVar1 + 0xd78);

  do {

    if (*piVar3 == param_1) {

      iVar4 = IconDefMaxAmmo(param_1);

      return *(int *)(iVar1 + 0xd7c + iVar2 * 8) < iVar4;

    }

    iVar2 = iVar2 + 1;

    piVar3 = piVar3 + 2;

  } while (iVar2 < 4);

switchD_004b8adc_caseD_3b:

  return false;

}

/* ===== reaper_needs_other @ 0x004B8C20 ===== */
/* PS2 candidate: reaper_needs_other (conf 0.803) */



bool reaper_needs_other(int param_1,int param_2,int param_3)



{

  int iVar1;

  int *piVar2;

  int *piVar3;

  

  piVar2 = (int *)(*(int *)(param_1 + 0x100) + 0xd98);

  iVar1 = 0;

  piVar3 = piVar2;

  do {

    if (*piVar3 == param_2) {

      return *(int *)(*(int *)(param_1 + 0x100) + 0xd9c + iVar1 * 8) < param_3;

    }

    iVar1 = iVar1 + 1;

    piVar3 = piVar3 + 2;

  } while (iVar1 < 2);

  iVar1 = 0;

  do {

    if (*piVar2 == -1) {

      return true;

    }

    iVar1 = iVar1 + 1;

    piVar2 = piVar2 + 2;

  } while (iVar1 < 2);

  return false;

}

/* ===== reaper_can_use_other__FP6OBJECTi @ 0x004B8C90 ===== */
undefined4 reaper_can_use_other__FP6OBJECTi(int param_1,int param_2)



{

  int *piVar1;

  int iVar2;

  

  iVar2 = 0;

  piVar1 = (int *)(*(int *)(param_1 + 0x100) + 0xd9c);

  while ((piVar1[-1] != param_2 || (*piVar1 < 1))) {

    iVar2 = iVar2 + 1;

    piVar1 = piVar1 + 2;

    if (1 < iVar2) {

      return 0;

    }

  }

  return 1;

}

/* ===== reaper_has_bow_dup004b8cd0 @ 0x004B8CD0 ===== */
undefined4 reaper_has_bow_dup004b8cd0(int param_1,int param_2)



{

  int iVar1;

  int *piVar2;

  

  iVar1 = 0;

  piVar2 = (int *)(*(int *)(param_1 + 0x100) + 0xd3c);

  do {

    if (*piVar2 == param_2) {

      return 1;

    }

    iVar1 = iVar1 + 1;

    piVar2 = piVar2 + 3;

  } while (iVar1 < 5);

  return 0;

}

/* ===== reaper_has_bow_3 @ 0x004B8D00 ===== */
/* PS2 candidate: reaper_has_bow_6 (conf 0.64) */



bool reaper_has_bow_3(int param_1)



{

  int iVar1;

  int *piVar2;

  

  iVar1 = 0;

  piVar2 = (int *)(*(int *)(param_1 + 0x100) + 0xd3c);

  do {

    if (*piVar2 == -1) break;

    iVar1 = iVar1 + 1;

    piVar2 = piVar2 + 3;

  } while (iVar1 < 5);

  return iVar1 < 5;

}

/* ===== reaper_item_find_slot @ 0x004B8D30 ===== */
void reaper_item_find_slot(int param_1,int param_2,int param_3)



{

  int iVar1;

  int iVar2;

  int *piVar3;

  

  iVar1 = *(int *)(param_1 + 0x100);

  iVar2 = 0;

  piVar3 = (int *)(iVar1 + 0xd3c);

  do {

    if (*piVar3 == param_2) {

      iVar2 = 0;

      piVar3 = (int *)(iVar1 + 0xd3c);

      do {

        if (*piVar3 == param_2) {

          if (param_3 < 0) {

            param_3 = IconDefGiveAmmo(param_2);

          }

          *(float *)(iVar1 + (iVar2 * 3 + 0x351) * 4) =

               (float)param_3 * *(float *)(iVar1 + 0xd40 + iVar2 * 0xc);

          return;

        }

        iVar2 = iVar2 + 1;

        piVar3 = piVar3 + 3;

      } while (iVar2 < 5);

      return;

    }

    iVar2 = iVar2 + 1;

    piVar3 = piVar3 + 3;

  } while (iVar2 < 5);

  iVar2 = 0;

  piVar3 = (int *)(iVar1 + 0xd3c);

  while (*piVar3 != -1) {

    iVar2 = iVar2 + 1;

    piVar3 = piVar3 + 3;

    if (4 < iVar2) {

      return;

    }

  }

  if (4 < iVar2) {

    return;

  }

  obj_link_slot_clear(param_1,param_2,iVar2,param_3);

  return;

}

/* ===== reaperbase_target_slot_clear @ 0x004B8DE0 ===== */
void reaperbase_target_slot_clear(int param_1,int param_2,int param_3)



{

  int iVar1;

  int iVar2;

  int *piVar3;

  int iVar4;

  

  iVar1 = *(int *)(param_1 + 0x100);

  iVar4 = param_3;

  if (param_3 < 0) {

    iVar2 = 0;

    piVar3 = (int *)(iVar1 + 0xd98);

    do {

      iVar4 = iVar2;

      if (*piVar3 == param_2) break;

      iVar2 = iVar2 + 1;

      piVar3 = piVar3 + 2;

      iVar4 = param_3;

    } while (iVar2 < 2);

    if (iVar4 < 0) {

      return;

    }

  }

  if (iVar4 < 2) {

    *(undefined4 *)(iVar1 + 0xd98 + iVar4 * 8) = 0xffffffff;

    *(undefined4 *)(iVar1 + 0xd9c + iVar4 * 8) = 0;

  }

  return;

}

/* ===== reaper_give_other @ 0x004B8E40 ===== */
/* PS2 candidate: reaper_give_other (conf 0.504) */



void reaper_give_other(int param_1,int param_2,int param_3,int param_4,int param_5)



{

  int iVar1;

  int iVar2;

  undefined4 uVar3;

  int *piVar4;

  int *piVar5;

  int iVar6;

  bool bVar7;

  

  iVar1 = *(int *)(param_1 + 0x100);

  bVar7 = false;

  if (param_3 == -1) {

    piVar5 = (int *)(iVar1 + 0xd98);

    iVar2 = 0;

    piVar4 = piVar5;

    do {

      iVar6 = iVar2;

      if (*piVar4 == param_2) break;

      iVar2 = iVar2 + 1;

      piVar4 = piVar4 + 2;

      iVar6 = param_3;

    } while (iVar2 < 2);

    param_3 = iVar6;

    if (iVar2 == 2) {

      iVar2 = 0;

      do {

        param_3 = iVar2;

        if (*piVar5 == -1) break;

        iVar2 = iVar2 + 1;

        piVar5 = piVar5 + 2;

        param_3 = iVar6;

      } while (iVar2 < 2);

    }

    bVar7 = param_3 == -1;

  }

  if ((!bVar7 && -2 < param_3) && (param_3 < 2)) {

    if (param_5 == 0) {

      *(int *)(iVar1 + 0xd9c + param_3 * 8) = *(int *)(iVar1 + 0xd9c + param_3 * 8) + param_4;

    }

    else {

      *(int *)(iVar1 + 0xd9c + param_3 * 8) = param_4;

    }

    iVar2 = IconDefMaxAmmo(param_2);

    if (iVar2 < *(int *)(iVar1 + 0xd9c + param_3 * 8)) {

      uVar3 = IconDefMaxAmmo(param_2);

      *(undefined4 *)(iVar1 + 0xd9c + param_3 * 8) = uVar3;

    }

    *(int *)(iVar1 + 0xd98 + param_3 * 8) = param_2;

  }

  return;

}

/* ===== reaper_give_ammo @ 0x004B8F00 ===== */
/* PS2 candidate: reaper_give_ammo (conf 0.515) */



void reaper_give_ammo(int param_1,undefined4 param_2,int param_3)



{

  int iVar1;

  int iVar2;

  int *piVar3;

  undefined4 uVar4;

  int iVar5;

  

  iVar1 = *(int *)(param_1 + 0x100);

  switch(param_2) {

  case 0x37:

    param_1 = 0x2d;

    break;

  case 0x38:

    param_1 = 0x2f;

    break;

  case 0x39:

    param_1 = 0x2e;

    break;

  case 0x3a:

    param_1 = 0x30;

    break;

  default:

    goto switchD_004b8f22_caseD_3b;

  case 0x3c:

    iVar5 = *(int *)(param_1 + 0x210);

    iVar2 = ObjIsJetski(iVar5);

    if (iVar2 != 0) {

      iVar5 = *(int *)(iVar5 + 0x100);

      iVar2 = *(int *)(iVar5 + 0x6c) + param_3;

      *(int *)(iVar5 + 0x6c) = iVar2;

      if (*(int *)(DAT_00632ed8 + 0x1090) < iVar2) {

        *(int *)(iVar5 + 0x6c) = *(int *)(DAT_00632ed8 + 0x1090);

      }

    }

    break;

  case 0x3d:

    iVar5 = *(int *)(param_1 + 0x210);

    iVar2 = ObjIsJetski(iVar5);

    if (iVar2 != 0) {

      iVar5 = *(int *)(iVar5 + 0x100);

      iVar2 = *(int *)(iVar5 + 0x70) + param_3;

      *(int *)(iVar5 + 0x70) = iVar2;

      if (*(int *)(DAT_00632ed8 + 0x108c) < iVar2) {

        *(int *)(iVar5 + 0x70) = *(int *)(DAT_00632ed8 + 0x108c);

      }

    }

    break;

  case 0x3e:

    iVar5 = *(int *)(param_1 + 0x210);

    iVar2 = ObjIsJetski(iVar5);

    if (iVar2 != 0) {

      iVar5 = *(int *)(iVar5 + 0x100);

      iVar2 = *(int *)(iVar5 + 0x74) + param_3;

      *(int *)(iVar5 + 0x74) = iVar2;

      if (*(int *)(DAT_00632ed8 + 0x1088) < iVar2) {

        *(int *)(iVar5 + 0x74) = *(int *)(DAT_00632ed8 + 0x1088);

      }

    }

  }

  iVar5 = 0;

  piVar3 = (int *)(iVar1 + 0xd78);

  while (*piVar3 != param_1) {

    iVar5 = iVar5 + 1;

    piVar3 = piVar3 + 2;

    if (3 < iVar5) {

      return;

    }

  }

  *(int *)(iVar1 + 0xd7c + iVar5 * 8) = *(int *)(iVar1 + 0xd7c + iVar5 * 8) + param_3;

  iVar2 = IconDefMaxAmmo(param_1);

  if (iVar2 < *(int *)(iVar1 + 0xd7c + iVar5 * 8)) {

    uVar4 = IconDefMaxAmmo(param_1);

    *(undefined4 *)(iVar1 + 0xd7c + iVar5 * 8) = uVar4;

  }

switchD_004b8f22_caseD_3b:

  return;

}

/* ===== reaper_set_bow @ 0x004B9080 ===== */
/* PS2 candidate: reaper_set_bow (conf 0.488) */



void reaper_set_bow(int param_1,int param_2,int param_3,int param_4,int param_5)



{

  int *piVar1;

  int iVar2;

  

  iVar2 = *(int *)(param_1 + 0x100);

  if (param_3 < 0) {

    piVar1 = (int *)(iVar2 + 0xd78);

    iVar2 = 4;

    do {

      if (*piVar1 == param_2) {

        *piVar1 = -1;

        piVar1[1] = 0;

      }

      piVar1 = piVar1 + 2;

      iVar2 = iVar2 + -1;

    } while (iVar2 != 0);

    reaper_cycle_weapon__FP6OBJECTi(param_1,1);

    return;

  }

  if (param_4 == -1) {

    param_4 = IconDefGiveAmmo(param_2);

  }

  *(int *)(iVar2 + 0xd7c + param_3 * 8) = param_4;

  *(int *)(iVar2 + 0xd78 + param_3 * 8) = param_2;

  if (param_5 != 0) {

    *(int *)(iVar2 + 0xdb4) = param_3 + 1;

    reaper_select_bow(param_1);

  }

  return;

}

/* ===== reaper_cycle_weapon__FP6OBJECTi @ 0x004B9120 ===== */
/* PS2 candidate: reaper_cycle_weapon__FP6OBJECTi (conf 0.344) */



void reaper_cycle_weapon__FP6OBJECTi(int param_1,int param_2)



{

  uint *puVar1;

  int iVar2;

  int iVar3;

  

  iVar2 = *(int *)(param_1 + 0x100);

  do {

    if (param_2 == 0) {

      iVar3 = *(int *)(iVar2 + 0xdb4) + -1;

      *(int *)(iVar2 + 0xdb4) = iVar3;

      if (-1 < iVar3) goto LAB_004b914c;

      *(undefined4 *)(iVar2 + 0xdb4) = 4;

    }

    else {

      iVar3 = *(int *)(iVar2 + 0xdb4) + 1;

      *(int *)(iVar2 + 0xdb4) = iVar3;

      if (iVar3 == 5) {

        *(undefined4 *)(iVar2 + 0xdb4) = 0;

        break;

      }

LAB_004b914c:

      if (*(int *)(iVar2 + 0xdb4) == 0) break;

    }

  } while (*(int *)(iVar2 + 0xd70 + *(int *)(iVar2 + 0xdb4) * 8) < 0);

  if (*(int *)(iVar2 + 0xdb4) == 0) {

    reaper_select_sword();

  }

  else if (*(int *)(iVar2 + 0xdb4) == 1) {

    reaper_select_bow();

  }

  else {

    reaper_change_bow__FP6OBJECT(param_1);

  }

  if (*(int *)(iVar2 + 0xf90) != 0) {

    puVar1 = (uint *)(*(int *)(iVar2 + 0xf90) + 0xd8);

    *puVar1 = *puVar1 | 0x40000000;

  }

  sound_stop_player(0x36c,param_1);

  return;

}

/* ===== reaper_init_items @ 0x004B91D0 ===== */
/* PS2 candidate: reaper_init_items (conf 0.51) */



void reaper_init_items(int param_1)



{

  int iVar1;

  

  iVar1 = 0;

  do {

    *(undefined4 *)(*(int *)(param_1 + 0x100) + 0xd3c + iVar1) = 0xffffffff;

    iVar1 = iVar1 + 0xc;

  } while (iVar1 < 0x3c);

  iVar1 = 0;

  do {

    *(undefined4 *)(*(int *)(param_1 + 0x100) + 0xd78 + iVar1) = 0xffffffff;

    *(undefined4 *)(*(int *)(param_1 + 0x100) + 0xd7c + iVar1) = 0;

    iVar1 = iVar1 + 8;

  } while (iVar1 < 0x20);

  iVar1 = 0;

  do {

    *(undefined4 *)(*(int *)(param_1 + 0x100) + 0xd98 + iVar1) = 0xffffffff;

    *(undefined4 *)(*(int *)(param_1 + 0x100) + 0xd9c + iVar1) = 0;

    iVar1 = iVar1 + 8;

  } while (iVar1 < 0x10);

  *(undefined4 *)(*(int *)(param_1 + 0x100) + 0xdb0) = 0xffffffff;

  *(undefined4 *)(*(int *)(param_1 + 0x100) + 0xdb4) = 0xffffffff;

  return;

}

/* ===== reaper_get_ammo @ 0x004B9290 ===== */
/* PS2 candidate: reaper_has_bow_4 (conf 0.731) */



float10 reaper_get_ammo(int param_1,int param_2)



{

  int iVar1;

  int *piVar2;

  

  iVar1 = 0;

  piVar2 = (int *)(*(int *)(param_1 + 0x100) + 0xd3c);

  do {

    if (*piVar2 == param_2) {

      return (float10)*(float *)(*(int *)(param_1 + 0x100) + (iVar1 * 3 + 0x351) * 4);

    }

    iVar1 = iVar1 + 1;

    piVar2 = piVar2 + 3;

  } while (iVar1 < 5);

  return (float10)0.0;

}

/* ===== reaper_item_count @ 0x004B92D0 ===== */
void reaper_item_count(int param_1,int param_2,int param_3)



{

  int iVar1;

  int *piVar2;

  int iVar3;

  

  iVar1 = *(int *)(param_1 + 0x100);

  iVar3 = 0;

  piVar2 = (int *)(iVar1 + 0xd3c);

  do {

    if (*piVar2 == param_2) {

      if (param_3 < 0) {

        param_3 = IconDefGiveAmmo(param_2);

      }

      *(float *)(iVar1 + (iVar3 * 3 + 0x351) * 4) =

           (float)param_3 * *(float *)(iVar1 + 0xd40 + iVar3 * 0xc);

      return;

    }

    iVar3 = iVar3 + 1;

    piVar2 = piVar2 + 3;

  } while (iVar3 < 5);

  return;

}

/* ===== reaper_give_all_spell_energy @ 0x004B9330 ===== */
/* PS2 candidate: reaper_give_all_spell_energy (conf 0.367) */



void reaper_give_all_spell_energy(int param_1,int param_2)



{

  int iVar1;

  float *pfVar2;

  int iVar3;

  

  pfVar2 = (float *)(*(int *)(param_1 + 0x100) + 0xd40);

  iVar3 = 5;

  do {

    if (-1 < (int)pfVar2[-1]) {

      iVar1 = param_2;

      if (param_2 < 0) {

        iVar1 = IconDefGiveAmmo(pfVar2[-1]);

      }

      if (pfVar2[1] < (float)iVar1 * *pfVar2) {

        pfVar2[1] = (float)iVar1 * *pfVar2;

      }

    }

    pfVar2 = pfVar2 + 3;

    iVar3 = iVar3 + -1;

  } while (iVar3 != 0);

  return;

}

/* ===== obj_link_slot_clear @ 0x004B9390 ===== */
void obj_link_slot_clear(int param_1,int param_2,int param_3,int param_4)



{

  undefined4 uVar1;

  int iVar2;

  int iVar3;

  int *piVar4;

  int *piVar5;

  int iVar6;

  

  iVar2 = *(int *)(param_1 + 0x100);

  if (param_3 < 0) {

    piVar4 = (int *)(iVar2 + 0xd3c);

    iVar3 = 0;

    piVar5 = piVar4;

    while (*piVar5 != param_2) {

      iVar3 = iVar3 + 1;

      piVar5 = piVar5 + 3;

      if (4 < iVar3) {

        return;

      }

    }

    *(undefined4 *)(iVar2 + 0xd3c + iVar3 * 0xc) = 0xffffffff;

    if (4 < iVar3) {

      return;

    }

    if (*(int *)(iVar2 + 0xdb0) != iVar3) {

      return;

    }

    *(undefined4 *)(iVar2 + 0xdb0) = 0xffffffff;

    iVar3 = 0;

    do {

      if (-1 < *piVar4) {

        *(int *)(iVar2 + 0xdb0) = iVar3;

        break;

      }

      iVar3 = iVar3 + 1;

      piVar4 = piVar4 + 3;

    } while (iVar3 < 5);

    if (iVar3 != 5) {

      return;

    }

    *(undefined4 *)(iVar2 + 0xdb0) = 0xffffffff;

    return;

  }

  iVar3 = iVar2 + param_3 * 0xc;

  *(int *)(iVar3 + 0xd3c) = param_2;

  switch(param_2) {

  case 0x15:

    uVar1 = *(undefined4 *)(DAT_00632ed8 + 2000);

    break;

  case 0x16:

    uVar1 = *(undefined4 *)(DAT_00632ed8 + 0x7b0);

    break;

  case 0x17:

    uVar1 = *(undefined4 *)(DAT_00632ed8 + 0x77c);

    break;

  case 0x18:

    uVar1 = *(undefined4 *)(DAT_00632ed8 + 0x760);

    break;

  case 0x19:

    uVar1 = *(undefined4 *)(DAT_00632ed8 + 0x78c);

    break;

  default:

    goto switchD_004b943e_caseD_1a;

  case 0x1b:

    uVar1 = *(undefined4 *)(DAT_00632ed8 + 0x7cc);

    break;

  case 0x1c:

    *(undefined4 *)(iVar3 + 0xd40) = 0x41200000;

    goto switchD_004b943e_caseD_1a;

  case 0x1d:

    uVar1 = *(undefined4 *)(DAT_00632ed8 + 0x774);

    break;

  case 0x1e:

    uVar1 = *(undefined4 *)(DAT_00632ed8 + 0x840);

    break;

  case 0x1f:

    uVar1 = *(undefined4 *)(DAT_00632ed8 + 0x830);

    break;

  case 0x21:

    uVar1 = *(undefined4 *)(DAT_00632ed8 + 0x7b8);

    break;

  case 0x49:

    uVar1 = *(undefined4 *)(DAT_00632ed8 + 0x14c8);

  }

  *(undefined4 *)(iVar3 + 0xd40) = uVar1;

switchD_004b943e_caseD_1a:

  iVar3 = *(int *)(param_1 + 0x100);

  iVar6 = 0;

  piVar4 = (int *)(iVar3 + 0xd3c);

  do {

    if (*piVar4 == param_2) {

      if (param_4 < 0) {

        param_4 = IconDefGiveAmmo(param_2);

      }

      *(float *)(iVar3 + (iVar6 * 3 + 0x351) * 4) =

           (float)param_4 * *(float *)(iVar3 + 0xd40 + iVar6 * 0xc);

      break;

    }

    iVar6 = iVar6 + 1;

    piVar4 = piVar4 + 3;

  } while (iVar6 < 5);

  if (*(int *)(iVar2 + 0xdb0) == -1) {

    *(int *)(iVar2 + 0xdb0) = param_3;

  }

  return;

}

/* ===== reaper_can_cast_spell_specific__FP6OBJECTP13ObjSpecReaperi @ 0x004B95D0 ===== */
/* PS2 candidate: reaper_can_cast_spell_specific__FP6OBJECTP13ObjSpecReaperi (conf 0.452) */



undefined4

reaper_can_cast_spell_specific__FP6OBJECTP13ObjSpecReaperi(int param_1,int param_2,int param_3)



{

  float fVar1;

  float fVar2;

  float fVar3;

  int iVar4;

  float *pfVar5;

  int iVar6;

  int iVar7;

  int *piVar8;

  int *piVar9;

  undefined4 *puVar10;

  float10 fVar11;

  float10 fVar12;

  float local_78;

  float local_68;

  float local_64;

  float local_60;

  float local_5c;

  float local_58;

  float local_54;

  float local_50;

  float local_4c;

  float local_48;

  undefined1 local_44 [16];

  float fStack_34;

  undefined4 uStack_24;

  undefined4 uStack_14;

  

  switch(*(undefined4 *)(param_2 + 0xd3c + param_3 * 0xc)) {

  case 0x15:

    local_78 = *(float *)(DAT_00632ed8 + 0x908) * *(float *)(DAT_00632ed8 + 0x908);

    fVar1 = *(float *)(DAT_00632ed8 + 0x904);

    fVar2 = *(float *)(DAT_00632ed8 + 0x900);

    pfVar5 = (float *)XFGetCameraOrigin();

    local_5c = *pfVar5;

    local_58 = pfVar5[1];

    local_54 = pfVar5[2];

    pfVar5 = (float *)XFGetCameraAxis(2);

    local_50 = *pfVar5;

    local_4c = pfVar5[1];

    local_48 = pfVar5[2];

    local_5c = local_50 * fVar2 + local_5c;

    iVar4 = 0;

    local_58 = local_4c * fVar2 + local_58;

    local_54 = local_48 * fVar2 + local_54;

    for (puVar10 = DAT_00632d68; puVar10 != (undefined4 *)0x0; puVar10 = (undefined4 *)*puVar10) {

      iVar7 = puVar10[3];

      iVar6 = reaper_xhair_validate__FP6OBJECTPv(iVar7,param_1);

      if (((iVar6 != 0) && ((*(uint *)(iVar7 + 0xd8) & 0x4000c000) == 0)) &&

         (((*(uint *)(iVar7 + 0x1c8) & 0x400000) != 0 && (*(float *)(iVar7 + 0x184) < 1.0)))) {

        local_68 = (*(float *)(iVar7 + 0x288) + *(float *)(iVar7 + 0x27c)) * 0.5 - local_5c;

        local_64 = (*(float *)(iVar7 + 0x28c) + *(float *)(iVar7 + 0x280)) * 0.5 - local_58;

        local_60 = (*(float *)(iVar7 + 0x290) + *(float *)(iVar7 + 0x284)) * 0.5 - local_54;

        fVar3 = local_68 * local_50 + local_64 * local_4c + local_60 * local_48;

        if (((0.0 <= fVar3) && (fVar3 < fVar1 - fVar2)) &&

           (fVar3 = (local_68 * local_68 + local_64 * local_64 + local_60 * local_60) -

                    fVar3 * fVar3, fVar3 < local_78)) {

          iVar4 = iVar7;

          local_78 = fVar3;

        }

      }

    }

    *(int *)(param_2 + 0xf48) = iVar4;

    if (iVar4 == 0) {

      return 0;

    }

    if ((*(int *)(iVar4 + 4) != 0xb) || (*(int *)(iVar4 + 0xe4) == 0x37)) {

      iVar4 = ObjIsMecc(iVar4);

      puVar10 = DAT_00632d98;

      if ((iVar4 == 0) &&

         (iVar4 = ObjIsReaper(*(undefined4 *)(param_2 + 0xf48)), puVar10 = DAT_00632d98, iVar4 == 0)

         ) {

        return 0;

      }

      while( true ) {

        if (puVar10 == (undefined4 *)0x0) {

          return 0;

        }

        iVar4 = puVar10[3];

        if ((((*(uint *)(iVar4 + 0xd8) & 0x8000) == 0) && (*(int *)(iVar4 + 4) == 0xb)) &&

           ((*(int *)(iVar4 + 0x210) == *(int *)(param_2 + 0xf48) ||

            (*(int *)(iVar4 + 0x274) == *(int *)(param_2 + 0xf48))))) break;

        puVar10 = (undefined4 *)*puVar10;

      }

    }

    if (iVar4 == 0) {

      return 0;

    }

    iVar7 = ObjIsKabuto(*(undefined4 *)(iVar4 + 0x210));

    if (iVar7 != 0) {

      return 0;

    }

    *(int *)(param_2 + 0xf48) = iVar4;

    fVar1 = *(float *)(DAT_00632ed8 + 0x14d8);

    fVar11 = (float10)distancesq3d(iVar4 + 0xa0,param_1 + 0xa0);

    fVar12 = (float10)fVar1 * (float10)fVar1;

    break;

  case 0x16:

    iVar4 = PROJ_DefGet(0x26);

    fVar1 = *(float *)(iVar4 + 0x2c);

    fVar11 = (float10)distancesq3d(param_2 + 0xf4c,param_1 + 0xa0);

    fVar12 = (float10)fVar1 * (float10)fVar1;

    break;

  case 0x17:

    iVar4 = reaper_has_linked_smartie(param_1);

    if (iVar4 != 0) {

      return 0;

    }

    iVar4 = *(int *)(param_2 + 0xe2c);

    goto LAB_004ba115;

  case 0x18:

    fVar11 = (float10)distancesq2d__FP3P3DT0(param_1 + 0xa0,param_2 + 0xf4c);

    if ((float10)*(float *)(DAT_00632ed8 + 0x758) * (float10)*(float *)(DAT_00632ed8 + 0x758) <=

        fVar11) {

      return 0;

    }

    iVar4 = camera_cursor_fire();

    if (iVar4 == 0) {

      return 0;

    }

    iVar4 = project_cursor_to_object(0,param_1,SQRT((float)fVar11),&local_68);

    if (iVar4 == 0) {

      return 1;

    }

    iVar4 = gun_find_right(param_1);

    (*(code *)PTR_crt_matrix_mul_00580c18)(local_44,iVar4 + 0x294,*(undefined4 *)(iVar4 + 0x2dc));

    local_50 = -*(float *)(param_1 + 0x29c);

    local_4c = -*(float *)(param_1 + 0x2ac);

    local_48 = -*(float *)(param_1 + 700);

    normalize__FPfN20(&local_50,&local_4c,&local_48);

    local_5c = fStack_34;

    local_58 = (float)uStack_24;

    local_54 = (float)uStack_14;

    iVar4 = project_vector_to_object(0,param_1,SQRT((float)fVar11),&local_68,&local_5c,&local_50);

    if (iVar4 != 0) {

      return 0;

    }

    return 1;

  case 0x19:

    if (*(int *)(param_2 + 0xe80) != 0) {

      return 0;

    }

    iVar4 = PROJ_DefGet(0x27);

    fVar1 = *(float *)(iVar4 + 0x2c);

    fVar11 = (float10)distancesq3d(param_2 + 0xf4c,param_1 + 0xa0);

    fVar12 = (float10)fVar1 * (float10)fVar1;

    break;

  default:

    goto switchD_004b9600_caseD_1a;

  case 0x1b:

    if (DAT_00632bc4 != 0) {

      return 0;

    }

    fVar1 = *(float *)(DAT_00632ed8 + 0x14d0);

    fVar11 = (float10)distancesq3d(param_2 + 0xf4c,param_1 + 0xa0);

    fVar12 = (float10)fVar1 * (float10)fVar1;

    break;

  case 0x1c:

    iVar4 = PROJ_DefGet(0x25);

    fVar1 = *(float *)(iVar4 + 0x2c);

    fVar11 = (float10)distancesq3d(param_2 + 0xf4c,param_1 + 0xa0);

    fVar12 = (float10)fVar1 * (float10)fVar1;

    break;

  case 0x1d:

    piVar9 = (int *)(param_2 + 0xdbc);

    iVar4 = 0;

    piVar8 = piVar9;

    while (*piVar8 != 0) {

      iVar4 = iVar4 + 1;

      piVar8 = piVar8 + 7;

      if (3 < iVar4) {

        return 0;

      }

    }

    if (3 < iVar4) {

      return 0;

    }

    local_78 = *(float *)(DAT_00632ed8 + 0x908) * *(float *)(DAT_00632ed8 + 0x908);

    fVar1 = *(float *)(DAT_00632ed8 + 0x904);

    fVar2 = *(float *)(DAT_00632ed8 + 0x900);

    pfVar5 = (float *)XFGetCameraOrigin();

    local_5c = *pfVar5;

    local_58 = pfVar5[1];

    local_54 = pfVar5[2];

    pfVar5 = (float *)XFGetCameraAxis(2);

    local_50 = *pfVar5;

    local_4c = pfVar5[1];

    local_48 = pfVar5[2];

    local_5c = local_50 * fVar2 + local_5c;

    iVar4 = 0;

    local_58 = local_4c * fVar2 + local_58;

    local_54 = local_48 * fVar2 + local_54;

    if (DAT_00632d68 != (undefined4 *)0x0) {

      iVar4 = 0;

      puVar10 = DAT_00632d68;

      do {

        iVar7 = puVar10[3];

        iVar6 = reaper_xhair_validate__FP6OBJECTPv(iVar7,param_1);

        if (((iVar6 != 0) && ((*(uint *)(iVar7 + 0xd8) & 0x4000c000) == 0)) &&

           (((*(uint *)(iVar7 + 0x1c8) & 0x400000) != 0 && (*(float *)(iVar7 + 0x184) < 1.0)))) {

          local_68 = (*(float *)(iVar7 + 0x288) + *(float *)(iVar7 + 0x27c)) * 0.5 - local_5c;

          local_64 = (*(float *)(iVar7 + 0x28c) + *(float *)(iVar7 + 0x280)) * 0.5 - local_58;

          local_60 = (*(float *)(iVar7 + 0x290) + *(float *)(iVar7 + 0x284)) * 0.5 - local_54;

          fVar3 = local_68 * local_50 + local_64 * local_4c + local_60 * local_48;

          if (((0.0 <= fVar3) && (fVar3 < fVar1 - fVar2)) &&

             (fVar3 = (local_68 * local_68 + local_64 * local_64 + local_60 * local_60) -

                      fVar3 * fVar3, fVar3 < local_78)) {

            iVar4 = iVar7;

            local_78 = fVar3;

          }

        }

        puVar10 = (undefined4 *)*puVar10;

      } while (puVar10 != (undefined4 *)0x0);

    }

    *(int *)(param_2 + 0xf48) = iVar4;

    if (iVar4 == 0) {

      return 0;

    }

    iVar4 = 0;

    while (*piVar9 != 0) {

      iVar4 = iVar4 + 1;

      piVar9 = piVar9 + 7;

      if (3 < iVar4) {

        return 0;

      }

    }

    if (3 < iVar4) {

      return 0;

    }

    iVar4 = PROJ_DefGet(0x24);

    fVar1 = *(float *)(iVar4 + 0x2c);

    fVar11 = (float10)distancesq3d(*(int *)(param_2 + 0xf48) + 0xa0,param_1 + 0xa0);

    fVar12 = (float10)fVar1 * (float10)fVar1;

    break;

  case 0x1e:

    local_78 = *(float *)(DAT_00632ed8 + 0x908) * *(float *)(DAT_00632ed8 + 0x908);

    fVar1 = *(float *)(DAT_00632ed8 + 0x904);

    fVar2 = *(float *)(DAT_00632ed8 + 0x900);

    pfVar5 = (float *)XFGetCameraOrigin();

    local_68 = *pfVar5;

    local_64 = pfVar5[1];

    local_60 = pfVar5[2];

    pfVar5 = (float *)XFGetCameraAxis(2);

    local_50 = *pfVar5;

    local_4c = pfVar5[1];

    local_48 = pfVar5[2];

    local_68 = local_50 * fVar2 + local_68;

    iVar4 = 0;

    local_64 = local_4c * fVar2 + local_64;

    local_60 = local_48 * fVar2 + local_60;

    for (puVar10 = DAT_00632d68; puVar10 != (undefined4 *)0x0; puVar10 = (undefined4 *)*puVar10) {

      iVar7 = puVar10[3];

      iVar6 = reaper_xhair_validate__FP6OBJECTPv(iVar7,param_1);

      if ((((iVar6 != 0) && ((*(uint *)(iVar7 + 0xd8) & 0x4000c000) == 0)) &&

          ((*(uint *)(iVar7 + 0x1c8) & 0x400000) != 0)) && (*(float *)(iVar7 + 0x184) < 1.0)) {

        local_5c = (*(float *)(iVar7 + 0x288) + *(float *)(iVar7 + 0x27c)) * 0.5 - local_68;

        local_58 = (*(float *)(iVar7 + 0x28c) + *(float *)(iVar7 + 0x280)) * 0.5 - local_64;

        local_54 = (*(float *)(iVar7 + 0x290) + *(float *)(iVar7 + 0x284)) * 0.5 - local_60;

        fVar3 = local_5c * local_50 + local_58 * local_4c + local_54 * local_48;

        if (((0.0 <= fVar3) && (fVar3 < fVar1 - fVar2)) &&

           (fVar3 = (local_5c * local_5c + local_58 * local_58 + local_54 * local_54) -

                    fVar3 * fVar3, fVar3 < local_78)) {

          iVar4 = iVar7;

          local_78 = fVar3;

        }

      }

    }

    *(int *)(param_2 + 0xf48) = iVar4;

    if (iVar4 == 0) {

      return 0;

    }

    iVar4 = ObjIsMecc(iVar4);

    if ((iVar4 == 0) && (iVar4 = ObjIsReaper(*(undefined4 *)(param_2 + 0xf48)), iVar4 == 0)) {

      iVar4 = *(int *)(*(int *)(param_2 + 0xf48) + 4);

      if ((((iVar4 != 8) && (((iVar4 != 0x438 && (iVar4 != 0x29a)) && (iVar4 != 0x232)))) &&

          ((iVar4 != 0xb || (iVar4 = target_can_be_hurt(*(int *)(param_2 + 0xf48)), iVar4 == 0))))

         && ((*(int *)(*(int *)(param_2 + 0xf48) + 4) != 0xd7 ||

             (iVar4 = target_hurt_class_check(*(int *)(param_2 + 0xf48)), iVar4 == 0)))) {

        iVar4 = ObjIsRipper(*(undefined4 *)(param_2 + 0xf48));

        if (iVar4 == 0) {

          return 0;

        }

        iVar4 = target_not_player_check(*(undefined4 *)(param_2 + 0xf48));

        if (iVar4 == 0) {

          return 0;

        }

      }

    }

    iVar4 = PROJ_DefGet(0x14);

    fVar1 = *(float *)(iVar4 + 0x2c);

    fVar11 = (float10)distancesq3d(*(int *)(param_2 + 0xf48) + 0xa0,param_1 + 0xa0);

    fVar12 = (float10)fVar1 * (float10)fVar1;

    break;

  case 0x1f:

    fVar1 = *(float *)(DAT_00632ed8 + 0x14cc);

    fVar11 = (float10)distancesq3d(param_2 + 0xf4c,param_1 + 0xa0);

    fVar12 = (float10)fVar1 * (float10)fVar1;

    break;

  case 0x21:

    if ((*(uint *)(param_1 + 0xd8) & 0x80000) == 0) {

      return 0;

    }

    fVar1 = *(float *)(DAT_00632ed8 + 0x14d4);

    fVar11 = (float10)distancesq3d(param_2 + 0xf4c,param_1 + 0xa0);

    fVar12 = (float10)fVar1 * (float10)fVar1;

    break;

  case 0x49:

    iVar4 = PROJ_DefGet(0x33);

    fVar1 = *(float *)(iVar4 + 0x2c);

    fVar11 = (float10)distancesq3d(param_2 + 0xf4c,param_1 + 0xa0);

    fVar12 = (float10)fVar1 * (float10)fVar1;

  }

  iVar4 = (uint)(fVar12 < fVar11) << 8;

LAB_004ba115:

  if (iVar4 == 0) {

    return 1;

  }

switchD_004b9600_caseD_1a:

  return 0;

}

/* ===== reaper_xhair_validate__FP6OBJECTPv @ 0x004BA1A0 ===== */
/* PS2 candidate: reaper_xhair_validate__FP6OBJECTPv (conf 0.466) */



undefined4 reaper_xhair_validate__FP6OBJECTPv(int param_1,int param_2)



{

  int iVar1;

  uint uVar2;

  float10 fVar3;

  float local_18;

  float local_14;

  float local_10;

  float local_c;

  float local_8;

  float local_4;

  

  iVar1 = ObjIsMeccBldg(param_1);

  if ((((iVar1 == 0) && (iVar1 = meccbasepit_bldg_from_object_dup004a6200(param_1), iVar1 == 0)) &&

      (iVar1 = ObjIsReaperBldg(param_1), iVar1 == 0)) &&

     (iVar1 = reaperbase_bldg_from_object(param_1), iVar1 == 0)) {

    if ((*(uint *)(param_1 + 0xd8) & 0x4000c000) != 0) {

      return 0;

    }

    if (*(float *)(param_1 + 0x1c0) <= *(float *)(param_1 + 0x278)) {

      return 0;

    }

    if (*(char *)(param_1 + 0x1f5) != '\0') {

      return 0;

    }

    uVar2 = 0;

    if (*(int *)(param_1 + 0x18c) == *(int *)(DAT_00632a88 + 0x18c)) {

      return 0;

    }

  }

  else {

    uVar2 = *(uint *)(param_1 + 0xd8) & 0x4000c000;

    if ((~*(uint *)(param_1 + 0x1c8) >> 0x11 & 1) != 0 || uVar2 != 0) {

      return 0;

    }

    if (*(int *)(param_1 + 0x18c) == *(int *)(DAT_00632a88 + 0x18c)) {

      return 0;

    }

  }

  if ((*(int *)(param_1 + 4) == 0xb) ||

     ((~*(uint *)(param_1 + 0x1c8) >> 0x11 & 1) == 0 && uVar2 == 0)) {

    local_c = -*(float *)(param_2 + 0x29c);

    local_8 = -*(float *)(param_2 + 0x2ac);

    local_4 = -*(float *)(param_2 + 700);

    local_18 = *(float *)(param_1 + 0xa0) - *(float *)(param_2 + 0xa0);

    local_14 = *(float *)(param_1 + 0xa4) - *(float *)(param_2 + 0xa4);

    local_10 = *(float *)(param_1 + 0xa8) - *(float *)(param_2 + 0xa8);

    fVar3 = (float10)Dot__FP3P3DT0(&local_c,&local_18);

    if ((float10)0.0 <= fVar3) {

      return 1;

    }

  }

  return 0;

}

/* ===== reaperbase_dock_valid_check @ 0x004BA2F0 ===== */
undefined4 reaperbase_dock_valid_check(int param_1,int param_2,int param_3)



{

  int iVar1;

  

  if (((**(byte **)(param_1 + 0x104) & 0x40) == 0) &&

     ((iVar1 = *(int *)(param_1 + 0x210), iVar1 == 0 ||

      ((*(int *)(iVar1 + 0x1e0) != 1 && (*(int *)(iVar1 + 0x1e0) != 0x4c)))))) {

    iVar1 = ObjIsJetski(iVar1);

    if (iVar1 == 0) {

      if (((-1 < *(int *)(param_2 + 0xd3c + param_3 * 0xc)) &&

          (*(int *)(param_2 + 0xdb0) == param_3)) &&

         (*(float *)(param_2 + param_3 * 0xc + 0xd40) <=

          *(float *)(param_2 + (param_3 * 3 + 0x351) * 4))) {

        return 1;

      }

    }

  }

  return 0;

}

/* ===== reaper_ability_sound @ 0x004BA370 ===== */
/* PS2 candidate: reaper_finish_cloak (conf 0.356) */



void reaper_ability_sound(int param_1)



{

  uint *puVar1;

  uint uVar2;

  int iVar3;

  float10 fVar4;

  uint local_1c;

  uint local_18;

  uint local_14;

  undefined4 local_10;

  undefined4 local_c;

  undefined4 local_8;

  undefined4 local_4;

  

  puVar1 = *(uint **)(param_1 + 0x100);

  if (puVar1[0x3d0] != 0) {

    *(undefined4 *)(*(int *)(param_1 + 0x104) + 4) = *(undefined4 *)(DAT_00632ed8 + 0xfe4);

    *(undefined4 *)(*(int *)(param_1 + 0x104) + 8) = *(undefined4 *)(DAT_00632ed8 + 0xfe8);

    if ((*(uint *)(param_1 + 0xe0) & 0x100) == 0) {

      uVar2 = sound_get_free_sequence__Fv();

      puVar1[0x3fb] = uVar2;

    }

    puVar1[2] = puVar1[3];

    if (puVar1[3] == 0) {

      fVar4 = (float10)physics_reset_b(param_1);

    }

    else {

      fVar4 = (float10)physics_reset_b(param_1);

      fVar4 = fVar4 * (float10)0.5;

    }

    puVar1[0x13] = (uint)(float)fVar4;

    iVar3 = reaper_0052e4a0(param_1);

    if (iVar3 != 0) {

      local_1c = puVar1[7];

      local_18 = puVar1[8];

      local_14 = puVar1[9];

      local_10 = *(undefined4 *)(param_1 + 0xa0);

      local_c = *(undefined4 *)(param_1 + 0xa4);

      local_8 = *(undefined4 *)(param_1 + 0xa8);

      if (puVar1[2] == 0) {

        local_4 = 0xffffffff;

      }

      else {

        local_4 = *(undefined4 *)(puVar1[2] + 0x188);

      }

      reaper_00530bd0(param_1,6,1,0,7,&local_1c);

    }

    if (puVar1[0x38b] == 0) {

      iVar3 = gun_find_right(param_1);

      if (iVar3 != 0) {

        *(uint *)(iVar3 + 0xd8) = *(uint *)(iVar3 + 0xd8) & 0xbfffffff;

      }

    }

    sound_stop_player(0x34c,param_1);

    puVar1[0x3c7] = *(uint *)(DAT_00632ed8 + 0x828);

    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xffff3fff;

    puVar1[0x3c9] = 0;

    *puVar1 = *puVar1 & 0xfffffffd;

    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 0x100;

  }

  return;

}

/* ===== physics_reset_b @ 0x004BA4F0 ===== */
/* PS2 candidate: reaper_turbo_calculate__FP6OBJECT (conf 0.341) */



float10 physics_reset_b(int param_1)



{

  undefined4 *puVar1;

  int iVar2;

  int iVar3;

  float10 fVar4;

  undefined4 local_c;

  undefined4 local_8;

  float local_4;

  

  iVar2 = *(int *)(param_1 + 0x100);

  iVar3 = *(int *)(iVar2 + 8);

  puVar1 = (undefined4 *)(iVar2 + 0x10);

  if (iVar3 == 0) {

    *puVar1 = *(undefined4 *)(iVar2 + 0x1c);

    *(undefined4 *)(iVar2 + 0x14) = *(undefined4 *)(iVar2 + 0x20);

    *(undefined4 *)(iVar2 + 0x18) = *(undefined4 *)(iVar2 + 0x24);

  }

  else {

    *puVar1 = *(undefined4 *)(iVar3 + 0xa0);

    *(undefined4 *)(iVar2 + 0x14) = *(undefined4 *)(iVar3 + 0xa4);

    *(undefined4 *)(iVar2 + 0x18) = *(undefined4 *)(iVar3 + 0xa8);

  }

  PhysicsExZeroForce_dup004a17a0(param_1);

  distancesq3d(param_1 + 0xa0,puVar1);

  if (*(int *)(iVar2 + 8) == 0) {

    fVar4 = (float10)powf();

    fVar4 = fVar4 * (float10)*(float *)(DAT_00632ed8 + 0xfe0);

  }

  else {

    fVar4 = (float10)powf();

    fVar4 = fVar4 * (float10)*(float *)(DAT_00632ed8 + 0x748);

  }

  local_8 = 0;

  local_c = 0;

  local_4 = (*(float *)(*(int *)(param_1 + 0x104) + 4) / *(float *)(*(int *)(param_1 + 0x104) + 8))

            * -32.17405;

  trajectory_calculate(param_1 + 0x128,param_1 + 0xa0,puVar1,&local_c,(float)fVar4);

  return (float10)(float)fVar4;

}

/* ===== reaper_release_shrink @ 0x004BA5E0 ===== */
/* PS2 candidate: reaper_release_shrink (conf 0.618) */



void reaper_release_shrink(undefined4 param_1,int *param_2)



{

  int iVar1;

  

  iVar1 = 4;

  do {

    if ((param_2[5] == 0) && (*param_2 != 0)) {

      obj_shot_expire_destroy(0xe,-(float)param_2[2],*param_2,param_1,0,0);

      *(float *)(*param_2 + 0xc4) = (float)param_2[4] + *(float *)(*param_2 + 0xc4);

    }

    *param_2 = 0;

    param_2 = param_2 + 7;

    iVar1 = iVar1 + -1;

  } while (iVar1 != 0);

  return;

}

/* ===== sound_player_user @ 0x004BA640 ===== */
/* PS2 candidate: item_check (conf 0.495) */



void sound_player_user(undefined4 param_1,int *param_2)



{

  int *piVar1;

  float fVar2;

  float fVar3;

  int iVar4;

  int iVar5;

  float10 fVar6;

  int local_4;

  

  local_4 = 4;

  do {

    iVar4 = *param_2;

    if (iVar4 != 0) {

      if (*(float *)(iVar4 + 0x278) < *(float *)(iVar4 + 0x1c0)) {

        if (param_2[5] != 0) {

          if (*(int *)(iVar4 + 4) == 8) {

            piVar1 = (int *)(*(int *)(iVar4 + 0x100) + 0x60);

            *piVar1 = *piVar1 + -1;

          }

          else {

            iVar4 = ObjIsKabuto(iVar4);

            if (iVar4 != 0) {

              piVar1 = (int *)(*(int *)(*param_2 + 0x100) + 0x354);

              *piVar1 = *piVar1 + -1;

            }

          }

          iVar4 = ObjIsReaper(*param_2);

          if (iVar4 != 0) {

            *(undefined4 *)(*param_2 + 0xc4) = *(undefined4 *)(*(int *)(*param_2 + 0x100) + 0xfac);

          }

          *param_2 = 0;

          goto LAB_004ba89c;

        }

      }

      else {

        param_2[5] = 1;

      }

      fVar6 = (float10)FRateGetSecsframe(iVar4,0);

      fVar2 = (float)fVar6;

      fVar3 = (float)param_2[1] - fVar2;

      param_2[1] = (int)fVar3;

      if (fVar3 < 0.0 == (fVar3 == 0.0)) {

        if ((float)param_2[4] < (float)param_2[3]) {

          fVar2 = ((float)param_2[3] / *(float *)(DAT_00632ed8 + 0x7d4)) * fVar2;

          fVar3 = fVar2 + (float)param_2[4];

          param_2[4] = (int)fVar3;

          if ((float)param_2[3] < fVar3) {

            param_2[4] = param_2[3];

            fVar2 = fVar2 - (fVar3 - (float)param_2[3]);

          }

          *(float *)(*param_2 + 0xc4) = *(float *)(*param_2 + 0xc4) - fVar2;

        }

      }

      else {

        if (param_2[6] == 0) {

          sound_play_player(0x3ba,*param_2);

          param_2[6] = 1;

        }

        if (0.0 < (float)param_2[4]) {

          fVar2 = ((float)param_2[3] / *(float *)(DAT_00632ed8 + 0x7d4)) * fVar2;

          fVar3 = (float)param_2[4] - fVar2;

          param_2[4] = (int)fVar3;

          if (0.0 <= fVar3) {

            *(float *)(*param_2 + 0xc4) = fVar2 + *(float *)(*param_2 + 0xc4);

          }

          else {

            if (param_2[5] == 0) {

              obj_shot_expire_destroy(0xe,-(float)param_2[2],*param_2,param_1,0,0);

            }

            iVar4 = *param_2;

            param_2[2] = 0;

            if (*(int *)(iVar4 + 4) == 8) {

              piVar1 = (int *)(*(int *)(iVar4 + 0x100) + 0x60);

              *piVar1 = *piVar1 + -1;

            }

            else if (*(int *)(iVar4 + 4) == 0xb) {

              piVar1 = (int *)(*(int *)(iVar4 + 0x100) + 0x4c);

              *piVar1 = *piVar1 + -1;

            }

            else {

              iVar4 = ObjIsKabuto(iVar4);

              if (iVar4 != 0) {

                piVar1 = (int *)(*(int *)(*param_2 + 0x100) + 0x354);

                *piVar1 = *piVar1 + -1;

              }

            }

            iVar5 = ObjIsReaper(*param_2);

            iVar4 = *param_2;

            if (iVar5 == 0) {

              *(float *)(iVar4 + 0xc4) = fVar3 + fVar2 + *(float *)(iVar4 + 0xc4);

              *param_2 = 0;

            }

            else {

              *(undefined4 *)(iVar4 + 0xc4) = *(undefined4 *)(*(int *)(iVar4 + 0x100) + 0xfac);

              *param_2 = 0;

            }

          }

        }

      }

    }

LAB_004ba89c:

    param_2 = param_2 + 7;

    local_4 = local_4 + -1;

    if (local_4 == 0) {

      return;

    }

  } while( true );

}

/* ===== reaper_firewall_hit @ 0x004BA8C0 ===== */
void reaper_firewall_hit(int param_1,undefined4 *param_2,float *param_3,undefined4 param_4,

                        uint param_5)



{

  float10 fVar1;

  

  if ((*(uint *)(param_1 + 0xe0) & param_5) != 0) {

    fVar1 = (float10)FRateGetSecsframe(*param_2,0);

    fVar1 = (float10)*param_3 - fVar1;

    *param_3 = (float)fVar1;

    if (fVar1 < (float10)0.0 != (fVar1 == (float10)0.0)) {

      fxb_firewall_create(param_1,param_2,param_4,param_5,0xffffffff);

      *param_3 = *(float *)(DAT_00632ed8 + 0x784);

    }

  }

  return;

}

/* ===== reaper_stop_looping_effects @ 0x004BA920 ===== */
/* PS2 candidate: reaper_stop_looping_effects (conf 0.362) */



void reaper_stop_looping_effects(int param_1)



{

  byte *pbVar1;

  int iVar2;

  

  pbVar1 = *(byte **)(param_1 + 0x100);

  sound_interrupt_sequence(pbVar1 + 0xff0);

  fx_delete(*(undefined4 *)(pbVar1 + 0xe34));

  pbVar1[0xe34] = 0;

  pbVar1[0xe35] = 0;

  pbVar1[0xe36] = 0;

  pbVar1[0xe37] = 0;

  pbVar1[0xe2c] = 0;

  pbVar1[0xe2d] = 0;

  pbVar1[0xe2e] = 0;

  pbVar1[0xe2f] = 0;

  *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) & 0xbfffffff;

  if ((*pbVar1 & 2) == 0) {

    iVar2 = gun_find_right(param_1);

    *(uint *)(iVar2 + 0xd8) = *(uint *)(iVar2 + 0xd8) & 0xbfffffff;

  }

  return;

}

/* ===== reaperbase_enemy_scan @ 0x004BA990 ===== */
/* PS2 candidate: reaper_cloak_damage (conf 0.431) */



void reaperbase_enemy_scan(int param_1,float param_2,undefined4 param_3)



{

  int iVar1;

  undefined4 *puVar2;

  int iVar3;

  float10 fVar4;

  

  for (puVar2 = DAT_00632d6c; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {

    iVar1 = puVar2[3];

    if (((*(int *)(iVar1 + 0x18c) != *(int *)(param_1 + 0x18c)) &&

        ((((((iVar3 = ObjIsReaper(iVar1), iVar3 != 0 || (iVar3 = ObjIsMecc(iVar1), iVar3 != 0)) ||

            (iVar3 = *(int *)(iVar1 + 4), iVar3 == 0xb)) || ((iVar3 == 8 || (iVar3 == 0x438)))) ||

          ((iVar3 == 0xe5 || ((iVar3 == 0x49 || (iVar3 == 0xe6)))))) || (iVar3 == 0x29a)))) &&

       (fVar4 = (float10)distancesq3d(iVar1 + 0xa0,param_1 + 0xa0),

       fVar4 < (float10)param_2 * (float10)param_2)) {

      iVar3 = fx_create(param_1);

      if (iVar3 != 0) {

        playerobj_lookud(iVar1,param_1,0xd,param_3,0,0);

      }

      *(uint *)(iVar1 + 0xd8) = *(uint *)(iVar1 + 0xd8) | 0x800;

    }

  }

  return;

}

/* ===== reaper_init__FP6OBJECT @ 0x004BAA70 ===== */
/* PS2 candidate: reaper_init__FP6OBJECT (conf 0.494) */



void reaper_init__FP6OBJECT(int param_1)



{

  int iVar1;

  int iVar2;

  

  iVar1 = *(int *)(param_1 + 0x100);

  *(int *)(param_1 + 0x104) = iVar1 + 0xd00;

  PhysicsExZeroForce(param_1);

  *(undefined4 *)(*(int *)(param_1 + 0x104) + 4) = *(undefined4 *)(DAT_00632ed8 + 0x704);

  *(undefined4 *)(*(int *)(param_1 + 0x104) + 8) = *(undefined4 *)(DAT_00632ed8 + 0x708);

  *(undefined4 *)(*(int *)(param_1 + 0x104) + 0x28) = *(undefined4 *)(DAT_00632ed8 + 0x70c);

  *(undefined4 *)(*(int *)(param_1 + 0x104) + 0xc) = *(undefined4 *)(DAT_00632ed8 + 0x710);

  *(undefined4 *)(*(int *)(param_1 + 0x104) + 0x30) = *(undefined4 *)(DAT_00632ed8 + 0x734);

  *(undefined4 *)(*(int *)(param_1 + 0x104) + 0x34) = *(undefined4 *)(DAT_00632ed8 + 0x714);

  *(undefined4 *)(*(int *)(param_1 + 0x104) + 0x38) = *(undefined4 *)(DAT_00632ed8 + 0x718);

  *(undefined4 *)(iVar1 + 0xfac) = *(undefined4 *)(param_1 + 0xc4);

  *(undefined4 *)(param_1 + 0xe0) = 0;

  iVar2 = *(int *)(DAT_00632ed8 + 0x1670);

  *(int *)(iVar1 + 0xdac) = iVar2;

  if (5 < iVar2) {

    *(undefined4 *)(iVar1 + 0xdac) = 5;

  }

  return;

}

/* ===== reaperbase_ai_main_c3 @ 0x004BAB60 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void reaperbase_ai_main_c3(OBJECT *param_1)



{

  undefined4 *puVar1;

  char cVar2;

  dword dVar3;

  int iVar4;

  int iVar5;

  uint *puVar6;

  char *pcVar7;

  int iVar8;

  float *pfVar9;

  undefined4 uVar10;

  uint uVar11;

  OBJECT *obj;

  int *piVar12;

  char *pcVar13;

  int iVar14;

  uint uVar15;

  uint *puVar16;

  uint *puVar17;

  undefined4 *puVar18;

  bool bVar19;

  float10 fVar20;

  float10 fVar21;

  undefined4 uVar22;

  undefined1 *puVar23;

  float fVar24;

  uint *puStack_ac;

  float fStack_a8;

  float fStack_a4;

  float fStack_a0;

  float fStack_9c;

  float fStack_98;

  float fStack_94;

  float fStack_90;

  float fStack_8c;

  float fStack_88;

  float fStack_84;

  uint uStack_80;

  float fStack_7c;

  undefined1 auStack_78 [4];

  undefined4 uStack_74;

  undefined4 uStack_70;

  float fStack_6c;

  undefined4 uStack_68;

  undefined4 uStack_64;

  OBJECT *pOStack_60;

  float fStack_44;

  float fStack_40;

  float fStack_3c;

  float fStack_30;

  undefined1 auStack_c [12];

  

  puStack_ac = (uint *)param_1->animate_state;

  uStack_80 = puStack_ac[0x17];

  if (param_1->pad_104 == 0) {

    reaper_init__FP6OBJECT(param_1);

  }

  if (DAT_00633124 != 0) {

    *(undefined4 *)&param_1->field_0x208 = 0;

    *(undefined4 *)&param_1->field_0x20c = 0;

  }

  iVar5 = fx_create(param_1);

  if (iVar5 == 0) {

    fVar20 = (float10)FRateGetSecsframe(0,0);

    fVar24 = (float)puStack_ac[0x3f9];

    puStack_ac[0x3f9] = (uint)(float)(fVar20 + (float10)fVar24);

    if (DAT_00633210 == 0) {

      fVar21 = (float10)1.0;

    }

    else {

      fVar21 = (float10)0.5;

    }

    fVar21 = (fVar20 + (float10)fVar24) / fVar21;

    if (fVar21 < (float10)1.0 != (fVar21 == (float10)1.0)) {

      *(float *)&param_1->field_0xa0 =

           (float)(fVar21 * (float10)(float)puStack_ac[0x3f6] +

                  (float10)*(float *)&param_1->field_0xa0);

      *(float *)&param_1->field_0xa4 =

           (float)(fVar21 * (float10)(float)puStack_ac[0x3f7] +

                  (float10)*(float *)&param_1->field_0xa4);

      *(float *)&param_1->field_0xa8 =

           (float)(fVar21 * (float10)(float)puStack_ac[0x3f8] +

                  (float10)*(float *)&param_1->field_0xa8);

      fVar21 = (float10)1.0 - fVar21;

      puStack_ac[0x3f6] = (uint)(float)(fVar21 * (float10)(float)puStack_ac[0x3f6]);

      puStack_ac[0x3f7] = (uint)(float)(fVar21 * (float10)(float)puStack_ac[0x3f7]);

      puStack_ac[0x3f8] = (uint)(float)(fVar21 * (float10)(float)puStack_ac[0x3f8]);

    }

  }

  else {

    iVar5 = reaper_0052e4a0(param_1);

    if (iVar5 != 0) {

      fVar20 = (float10)FRateGetSecsframe(0,0);

      fVar20 = (float10)_DAT_00560f44 - fVar20;

      _DAT_00560f44 = (float)fVar20;

      if ((fVar20 < (float10)0.0 != (fVar20 == (float10)0.0)) && (param_1->pad_104 != 0)) {

        puVar6 = (uint *)MemAllocMsg(0,0x1004,s_reaperweaponcheatfix_00560fc4,

                                     s_C__Giants_source_main_reaper_c_00560fdc,0xc62);

        puVar16 = puStack_ac;

        puVar17 = puVar6;

        for (iVar5 = 0x401; iVar5 != 0; iVar5 = iVar5 + -1) {

          *puVar17 = *puVar16;

          puVar16 = puVar16 + 1;

          puVar17 = puVar17 + 1;

        }

        puVar16 = puStack_ac + 0x340;

        puVar17 = puVar6 + 0x340;

        for (iVar5 = 0xf; iVar5 != 0; iVar5 = iVar5 + -1) {

          *puVar17 = *puVar16;

          puVar16 = puVar16 + 1;

          puVar17 = puVar17 + 1;

        }

        mem_free_tagged(puStack_ac,s_C__Giants_source_main_reaper_c_00560fdc,0xc65);

        param_1->pad_104 = (dword)(puVar6 + 0x340);

        param_1->animate_state = (dword)puVar6;

        weapon_id_inventory_update();

        _DAT_00560f44 = 20.0;

        puStack_ac = puVar6;

      }

    }

  }

  iVar5 = dialog_level_is_base_dup0052aa70();

  if ((((iVar5 != 0) && (iVar5 = net_active_players_get(), iVar5 == 0)) && (DAT_00632a88 == param_1)

      ) && ((*(int *)&param_1->field_0x210 != 0 &&

            (iVar5 = ObjIsJetski(*(int *)&param_1->field_0x210), iVar5 != 0)))) {

    fVar20 = (float10)FRateGetSecsframe(0,0);

    fVar24 = (float)puStack_ac[0x3fa];

    puStack_ac[0x3fa] = (uint)(float)((float10)fVar24 - fVar20);

    if ((float10)fVar24 - fVar20 < (float10)0.0) {

      puStack_ac[0x3fa] = 0x3f800000;

      for (puVar18 = DAT_00632d98; puVar18 != (undefined4 *)0x0; puVar18 = (undefined4 *)*puVar18) {

        iVar5 = puVar18[3];

        if (((*(int *)(iVar5 + 0xe8) == 10) && (*(dword *)(iVar5 + 0x18c) != param_1->ai_state_b))

           && ((*(int *)(iVar5 + 0x210) == 0 &&

               (fVar20 = (float10)distancesq3d(iVar5 + 0xa0,&param_1->field_0xa0),

               fVar20 <= (float10)100.0)))) {

          pcVar7 = (char *)TextGetPtr(s_FlagHintDriveGyro_0055bccc);

          pcVar13 = &DAT_00632c10;

          do {

            cVar2 = *pcVar7;

            pcVar7 = pcVar7 + 1;

            *pcVar13 = cVar2;

            pcVar13 = pcVar13 + 1;

          } while (cVar2 != '\0');

          _DAT_00632d10 = 0x3f8ccccd;

        }

      }

    }

  }

  fVar20 = (float10)FRateGetSecsframe(0,0);

  _DAT_00560f40 = (float)((float10)_DAT_00560f40 - fVar20);

  param_1->flags = param_1->flags | 0x10000000;

  if (*(int *)&param_1->field_0x210 != 0) {

    iVar5 = fx_create(param_1);

    if ((iVar5 != 0) && (iVar5 = ObjIsJetski(*(undefined4 *)&param_1->field_0x210), iVar5 != 0)) {

      player_pitch_update(param_1);

      return;

    }

    obj_alpha_fade_update(param_1);

    player_pitch_update(param_1);

    reaper_fire_logic__FP6OBJECT(param_1);

    iVar5 = comm_send_gate_check(param_1);

    if (iVar5 != 0) {

      fStack_a8 = (float)((uint)CONCAT11((char)((uint)fStack_a8 >> 0x18),param_1->field_0x208) <<

                         0x10);

      comm_chat_send_2(param_1,0,0,3,3,&fStack_a8);

    }

  }

  iVar5 = dialog_level_is_base_dup0052aa70();

  if ((((iVar5 == 0) || (iVar5 = *(int *)&param_1->field_0x224, iVar5 == 0)) ||

      (*(int *)(iVar5 + 4) != 0x4a5)) ||

     ((*(dword *)(iVar5 + 0x18c) != param_1->ai_state_b ||

      (param_1->ai_state_b == DAT_00632a88->ai_state_b)))) {

LAB_004baf76:

    param_1->pad_184 = 0;

  }

  else {

    fVar20 = (float10)distance3d__FP3P3DT0(&DAT_00632a88->field_0xa0,&param_1->field_0xa0);

    fVar20 = (fVar20 - (float10)*(float *)(DAT_00632ed8 + 0x1210)) /

             ((float10)*(float *)(DAT_00632ed8 + 0x1214) -

             (float10)*(float *)(DAT_00632ed8 + 0x1210));

    param_1->pad_184 = (dword)(float)fVar20;

    if ((float10)1.0 < fVar20) {

      param_1->pad_184 = 0x3f800000;

    }

    if ((float)param_1->pad_184 < 0.0) goto LAB_004baf76;

  }

  if (((DAT_00632b90 != 0) && ((param_1->flags & 0x80000) != 0)) && ((*puStack_ac & 0x20) == 0)) {

    fVar20 = (float10)world_ripple_xform(&param_1->field_0xa0);

    if ((float10)*(float *)(DAT_00632ed8 + 0x5d0) < fVar20 - (float10)*(float *)&param_1->field_0xa8

       ) {

      iVar5 = fx_create(param_1);

      if (iVar5 != 0) {

        obj_damage_apply(0x19,*(undefined4 *)(DAT_00632ed8 + 0x5cc),param_1,0,&param_1->field_0xa0,0

                        );

      }

      param_1->loc_accum0 = 0x41a00000;

      *puStack_ac = *puStack_ac | 0x20;

    }

  }

  dVar3 = param_1->animate_state;

  iVar5 = fx_create(param_1);

  if (((iVar5 != 0) && ((*(uint *)&param_1->field_0x20c & 0x1000000) != 0)) &&

     ((param_1->pad_DC & 0x800000) != 0)) {

    *(uint *)&param_1->field_0x20c = *(uint *)&param_1->field_0x20c & 0xfeffffff;

    fStack_a4 = *(float *)(dVar3 + 0xcfc);

    puVar18 = DAT_00632d98;

    if (fStack_a4 != 0.0) {

      for (; puVar18 != (undefined4 *)0x0; puVar18 = (undefined4 *)*puVar18) {

        iVar5 = puVar18[3];

        iVar14 = *(int *)(iVar5 + 0x100);

        if (((*(OBJECT **)(iVar5 + 0x274) == param_1) && (*(int *)(iVar5 + 4) == 0xb)) &&

           ((*(int *)(iVar14 + 0x54) != 0 && ((*(uint *)(iVar5 + 0xe0) & 0x200) == 0)))) {

          if (*(int *)(iVar14 + 0x54) == 7) {

            reaper_lock_pair(param_1,iVar5);

            break;

          }

          if ((*(char *)param_1->pad_104 < '\0') || (*(int *)(iVar14 + 0x54) == 1)) {

            puVar23 = &param_1->field_0xa0;

            main_path_0049fb00(puVar23,&fStack_a0,&fStack_a8);

            if ((*(int *)(DAT_006330e4 + 0x24) < (int)fStack_a0) ||

               ((((*(int *)(DAT_006330e4 + 0x2c) < (int)fStack_a8 ||

                  ((int)fStack_a0 < *(int *)(DAT_006330e4 + 0x20))) ||

                 ((int)fStack_a8 < *(int *)(DAT_006330e4 + 0x28))) ||

                (fVar20 = (float10)get_floor_z_point(puVar23), fVar20 < (float10)-30.0)))) {

              bVar19 = true;

            }

            else {

              bVar19 = false;

            }

            iVar8 = *(int *)(iVar14 + 0x54);

            if (((((iVar8 == 5) || (iVar8 == 6)) || (iVar8 == 4)) &&

                ((*(int *)&param_1->field_0x224 != 0 &&

                 (iVar4 = *(int *)(*(int *)&param_1->field_0x224 + 4), iVar4 != 0x4a5)))) &&

               (iVar4 != 0x486)) {

              pcVar7 = s_PhErrNotTowerOrGround_00560fac;

            }

            else if (iVar8 == 3) {

              if ((bVar19) && (*(int *)&param_1->field_0x224 == 0)) {

LAB_004bb195:

                if (((iVar8 != 2) || (*(int *)&param_1->field_0x224 == 0)) &&

                   ((*(int *)&param_1->field_0x224 == 0 ||

                    (*(int *)(*(int *)&param_1->field_0x224 + 4) != 0x486)))) {

                  iVar8 = dialog_level_is_base_dup0052aa70();

                  if ((iVar8 == 0) || (iVar8 = net_active_players_get(), iVar8 != 0)) {

                    smartie_start_special_building

                              (iVar5,*(undefined4 *)(iVar14 + 0x54),fStack_a4,param_1,puVar23,

                               *(float *)&param_1->field_0xc8 + 180.0);

                  }

                  else {

                    comm_msg17_pair_send

                              (iVar5,*(undefined4 *)(iVar14 + 0x54),fStack_a4,param_1,puVar23,

                               *(float *)&param_1->field_0xc8 + 180.0);

                  }

                  sine_cos_lookup(*(undefined4 *)&param_1->field_0xc8,&fStack_7c,&fStack_90);

                  fStack_94 = *(float *)&param_1->field_0xa8;

                  fStack_9c = *(float *)puVar23 - fStack_7c * 20.0;

                  fStack_98 = *(float *)&param_1->field_0xa4 - fStack_90 * -20.0;

                  object_set_location_p3d(param_1,&fStack_9c);

                  break;

                }

                pcVar7 = s_PhErrNotGroundOrWater_0055bd54;

              }

              else {

                pcVar7 = s_PhErrNotWater_00560f9c;

              }

            }

            else {

              if ((((iVar8 != 5) && (iVar8 != 6)) || (!bVar19)) ||

                 (*(int *)&param_1->field_0x224 != 0)) goto LAB_004bb195;

              pcVar7 = s_PhErrDeepWater_00560f8c;

            }

          }

          else {

            pcVar7 = s_PhErrNotOnSomething_0055bc70;

          }

          uVar10 = TextGetPtr(pcVar7,1);

          chat_insert(uVar10);

          break;

        }

      }

    }

  }

  param_1->flags = param_1->flags & 0xfeffffff;

  iVar5 = fx_create(param_1);

  if ((iVar5 != 0) && (*(float *)&param_1->field_0x1c0 <= *(float *)&param_1->field_0x278)) {

    puVar16 = (uint *)param_1->animate_state;

    sound_player_user(param_1,puVar16 + 0x36f);

    puVar16[0x33b] = 0;

    fxb_splash_create(param_1);

    if ((*puVar16 & 0x200) != 0) {

      turret_exit_all_team(param_1);

      *puVar16 = *puVar16 & 0xfffffdff;

    }

    *puVar16 = *puVar16 & 0xffffffdf;

    if (param_1 == DAT_00632a88) {

      fVar20 = (float10)FRateGetSecsframe(0,0);

      fVar24 = (float)puVar16[0x400];

      puVar16[0x400] = (uint)(float)(fVar20 + (float10)fVar24);

      if ((((param_1->flags & 0x80000) != 0) ||

          (*(float *)&param_1->field_0xa8 < 0.0 != (*(float *)&param_1->field_0xa8 == 0.0))) ||

         ((float10)6.0 < fVar20 + (float10)fVar24)) {

        if (DAT_00632f08 == 0) {

          voice_quota_check();

        }

        else {

          _DAT_00632b60 = _DAT_00632b60 + DAT_006328e0;

          if ((2.0 < _DAT_00632b60) && ((*(uint *)&param_1->field_0x20c & 0x2000100) != 0)) {

            puVar16[0x400] = 0;

            cam_mode_full(param_1,puVar16[0x3ff]);

            iVar5 = ObjIsReaper(param_1);

            if (iVar5 == 0) {

              return;

            }

          }

        }

      }

    }

    param_1->field_0x20a = 0;

    param_1->field_0x20b = 0;

    *(undefined4 *)&param_1->field_0x20c = 0;

    player_pitch_update(param_1);

    obj_alpha_fade_update(param_1);

    reaper_walkrun_go__FP6OBJECT(param_1);

    objspec_dispatch_gate(param_1);

    FRateGetSecsframe(param_1,0);

    object_animate_process(param_1);

    return;

  }

  iVar5 = fx_create(param_1);

  if (iVar5 != 0) {

    reaper_lock_user(param_1);

  }

  if ((*puStack_ac & 0x200) != 0) {

    return;

  }

  if ((param_1->coll_radius & 0x10000000) != 0) {

    obj_alpha_fade_update(param_1);

    player_pitch_update(param_1);

    reaper_lock_user(param_1);

    return;

  }

  if (param_1 == DAT_00632a88) {

    dVar3 = param_1->animate_state;

    *(undefined4 *)(dVar3 + 0xf3c) = 0;

    *(undefined4 *)(dVar3 + 0xf38) = 0;

    *(undefined4 *)(dVar3 + 0xf40) = 0;

    *(undefined4 *)(dVar3 + 0xf58) = 0;

    *(undefined4 *)(dVar3 + 0xf44) = 0;

    *(undefined4 *)(dVar3 + 0xf48) = 0;

    _DAT_00632ba4 = 0;

    if (*(float *)(dVar3 + 0xda8) <= 0.0) {

      param_1->coll_radius = param_1->coll_radius & 0xfffffff7;

    }

    else {

      fVar20 = (float10)FRateGetSecsframe(param_1,0);

      *(float *)(dVar3 + 0xda8) = (float)((float10)*(float *)(dVar3 + 0xda8) - fVar20);

    }

    if (*(int *)(dVar3 + 0x50) != 0) {

      puVar16 = (uint *)(*(int *)(dVar3 + 0x50) + 0xd8);

      *puVar16 = *puVar16 | 0x40000000;

    }

    if ((((param_1->pad_E4 & 0x4000000) == 0) && (DAT_00632ba8 == 0)) &&

       (*(int *)(dVar3 + 0x5c) != 0x4d)) {

      fStack_a0 = 0.0;

      if (*(int *)(dVar3 + 0xdb4) < 1) {

        fStack_a4 = 9000.0;

      }

      else {

        switch(*(undefined4 *)(dVar3 + 0xd70 + *(int *)(dVar3 + 0xdb4) * 8)) {

        case 0x2c:

          iVar5 = PROJ_DefGet(0x2b);

          fStack_a4 = *(float *)(iVar5 + 0x2c);

          break;

        case 0x2d:

          iVar5 = PROJ_DefGet(0x16);

          fStack_a4 = *(float *)(iVar5 + 0x2c);

          break;

        case 0x2e:

          iVar5 = PROJ_DefGet(0x15);

          fStack_a4 = *(float *)(iVar5 + 0x2c);

          break;

        case 0x2f:

        case 0x30:

          iVar5 = PROJ_DefGet(0x17);

          fStack_a4 = *(float *)(iVar5 + 0x2c);

          break;

        default:

          fStack_a4 = *(float *)(uStack_80 + 0x2c);

        }

      }

      iVar5 = camera_cursor_fire();

      if (iVar5 == 0) {

        tracer_aim_fire(param_1,&fStack_8c,&fStack_9c);

        iVar5 = fx_shape_gen(dVar3 + 0xf4c,fStack_a4,&fStack_9c,&fStack_8c,auStack_c,&fStack_a8);

      }

      else {

        iVar5 = project_cursor_to_ground(dVar3 + 0xf4c,fStack_a4,&fStack_a8);

      }

      puVar18 = (undefined4 *)(dVar3 + 0xf4c);

      if (iVar5 != 0) {

        *(undefined4 *)(dVar3 + 0x1c) = *puVar18;

        *(undefined4 *)(dVar3 + 0x20) = *(undefined4 *)(dVar3 + 0xf50);

        *(undefined4 *)(dVar3 + 0x24) = *(undefined4 *)(dVar3 + 0xf54);

        *(undefined4 *)(dVar3 + 0xf58) = 1;

        if (0 < *(int *)(dVar3 + 0xdb4)) {

          _DAT_00632ba4 = 1;

        }

      }

      iVar5 = camera_cursor_fire();

      puVar1 = (undefined4 *)(dVar3 + 0x1c);

      if (iVar5 == 0) {

        iVar5 = obj_aim_calc(param_1,&LAB_004bc580,param_1,fStack_a8,puVar1);

      }

      else {

        iVar5 = project_cursor_to_object(&LAB_004bc580,param_1,fStack_a8);

      }

      *(int *)(dVar3 + 0xc) = iVar5;

      if ((iVar5 != 0) && (iVar5 = reaper_xhair_validate__FP6OBJECTPv(iVar5,param_1), iVar5 != 0)) {

        if ((*(uint *)(*(int *)(dVar3 + 0xc) + 0x1c8) & 0x400000) != 0) {

          *(int *)(dVar3 + 0xf44) = *(int *)(dVar3 + 0xc);

        }

        *puVar18 = *puVar1;

        *(undefined4 *)(dVar3 + 0xf50) = *(undefined4 *)(dVar3 + 0x20);

        fStack_a0 = 1.4013e-45;

        *(undefined4 *)(dVar3 + 0xf54) = *(undefined4 *)(dVar3 + 0x24);

        *(undefined4 *)(dVar3 + 0xf58) = 1;

      }

      if (*(int *)(dVar3 + 0xf58) == 0) {

        if (*(int *)(dVar3 + 0xc) != 0) goto LAB_004bb6cc;

        XFGetViewportExt(&fStack_a4,&fStack_7c,&fStack_90,&fStack_8c);

        pfVar9 = (float *)XFGetCameraAxis(2);

        fStack_9c = *pfVar9;

        fStack_98 = pfVar9[1];

        fStack_94 = pfVar9[2];

        *(float *)(dVar3 + 0xfc4) = fStack_9c * 1000.0 + fStack_8c;

        *(float *)(dVar3 + 0xfc8) = fStack_98 * 1000.0 + fStack_88;

        *(float *)(dVar3 + 0xfcc) = fStack_94 * 1000.0 + fStack_84;

      }

      else if (*(int *)(dVar3 + 0xc) == 0) {

        *(undefined4 *)(dVar3 + 0xfc4) = *puVar18;

        *(undefined4 *)(dVar3 + 0xfc8) = *(undefined4 *)(dVar3 + 0xf50);

        *(undefined4 *)(dVar3 + 0xfcc) = *(undefined4 *)(dVar3 + 0xf54);

      }

      else {

LAB_004bb6cc:

        *(undefined4 *)(dVar3 + 0xfc4) = *puVar1;

        *(undefined4 *)(dVar3 + 0xfc8) = *(undefined4 *)(dVar3 + 0x20);

        *(undefined4 *)(dVar3 + 0xfcc) = *(undefined4 *)(dVar3 + 0x24);

      }

      if (*(int *)(dVar3 + 0xd70 + *(int *)(dVar3 + 0xdb4) * 8) == 0x2f) {

        if (0.0 < *(float *)(dVar3 + 0xf98)) {

          fVar24 = fStack_a8;

          if (*(float *)(DAT_00632ed8 + 0x904) <= fStack_a8) {

            fVar24 = *(float *)(DAT_00632ed8 + 0x904);

          }

          uVar10 = audio_listener_update_dup004bc640

                             (param_1,*(undefined4 *)(DAT_00632ed8 + 0x900),fVar24,

                              *(float *)(DAT_00632ed8 + 0x908) * *(float *)(DAT_00632ed8 + 0x908));

          *(undefined4 *)(dVar3 + 0xf8c) = uVar10;

        }

      }

      else {

        *(undefined4 *)(dVar3 + 0xf8c) = 0;

      }

      if (*(int *)(dVar3 + 0xf58) == 0) {

        if (((*(float *)(dVar3 + 0xda8) < 0.0 != (*(float *)(dVar3 + 0xda8) == 0.0)) &&

            (*(int *)(dVar3 + 0xd3c + *(int *)(dVar3 + 0xdb0) * 0xc) == 0x17)) &&

           (iVar5 = reaperbase_dock_valid_check(param_1,dVar3,*(int *)(dVar3 + 0xdb0)), iVar5 != 0))

        {

          uVar10 = reaper_can_cast_spell_specific__FP6OBJECTP13ObjSpecReaperi

                             (param_1,dVar3,*(undefined4 *)(dVar3 + 0xdb0));

          *(undefined4 *)(dVar3 + 0xf38) = uVar10;

        }

        if (((*(int *)(dVar3 + 0xc) != 0) && ((param_1->coll_radius & 0xd1bf0000) == 0)) &&

           (*(float *)(dVar3 + 0xfac) == *(float *)&param_1->field_0xc4)) {

          *(undefined4 *)(dVar3 + 0xc) = 0;

          fVar20 = (float10)distancesq3d(&param_1->field_0xa0,puVar1);

          fStack_90 = (float)fVar20;

          fVar20 = (float10)powf();

          fVar20 = fVar20 * (float10)*(float *)(DAT_00632ed8 + 0xfe0);

          if (fVar20 < (float10)*(float *)(dVar3 + 0x28) !=

              (fVar20 == (float10)*(float *)(dVar3 + 0x28))) {

            *(undefined4 *)(dVar3 + 0xf40) = 1;

          }

        }

        bVar19 = *(int *)(dVar3 + 0xd70 + *(int *)(dVar3 + 0xdb4) * 8) == 0x2f;

      }

      else {

        if (((param_1->coll_radius & 0xd1bf0000) == 0) &&

           (*(float *)(dVar3 + 0xfac) == *(float *)&param_1->field_0xc4)) {

          if (*(int *)(dVar3 + 0xf44) == 0) {

            *(undefined4 *)(dVar3 + 0xc) = 0;

          }

          if ((*(int *)(dVar3 + 0xc) == 0) && (fStack_a0 == 0.0)) {

            fVar24 = fStack_a8;

            if (*(float *)(DAT_00632ed8 + 0x904) <= fStack_a8) {

              fVar24 = *(float *)(DAT_00632ed8 + 0x904);

            }

            iVar5 = audio_listener_update_dup004bc640

                              (param_1,*(undefined4 *)(DAT_00632ed8 + 0x900),fVar24,

                               *(float *)(DAT_00632ed8 + 0x908) * *(float *)(DAT_00632ed8 + 0x908));

            *(int *)(dVar3 + 0xc) = iVar5;

            if ((iVar5 == 0) ||

               (iVar5 = reaper_xhair_validate__FP6OBJECTPv(iVar5,param_1), iVar5 == 0)) {

              *(undefined4 *)(dVar3 + 0xc) = 0;

              if (-*(float *)&param_1->field_0x1e8 < *(float *)(dVar3 + 0x24)) {

                fVar20 = (float10)distancesq3d(&param_1->field_0xa0,puVar1);

                fStack_a4 = (float)fVar20;

                fVar20 = (float10)powf();

                fVar20 = fVar20 * (float10)*(float *)(DAT_00632ed8 + 0xfe0);

LAB_004bb94e:

                if (fVar20 < (float10)*(float *)(dVar3 + 0x28) !=

                    (fVar20 == (float10)*(float *)(dVar3 + 0x28))) {

                  *(undefined4 *)(dVar3 + 0xf40) = 1;

                }

              }

            }

            else {

              reaper_turbo_towards_moving_target__FP6OBJECT(param_1);

            }

          }

          else if (*(int *)(dVar3 + 0xf44) == 0) {

            if (-*(float *)&param_1->field_0x1e8 < *(float *)(dVar3 + 0x24)) {

              fVar20 = (float10)distancesq3d(&param_1->field_0xa0,puVar1);

              fStack_a4 = (float)fVar20;

              fVar20 = (float10)powf();

              fVar20 = fVar20 * (float10)*(float *)(DAT_00632ed8 + 0xfe0);

              goto LAB_004bb94e;

            }

          }

          else {

            reaper_turbo_towards_moving_target__FP6OBJECT(param_1);

          }

        }

        if ((*(float *)(dVar3 + 0xda8) < 0.0 != (*(float *)(dVar3 + 0xda8) == 0.0)) &&

           (iVar5 = reaperbase_dock_valid_check(param_1,dVar3,*(undefined4 *)(dVar3 + 0xdb0)),

           iVar5 != 0)) {

          uVar10 = reaper_can_cast_spell_specific__FP6OBJECTP13ObjSpecReaperi

                             (param_1,dVar3,*(undefined4 *)(dVar3 + 0xdb0));

          *(undefined4 *)(dVar3 + 0xf38) = uVar10;

        }

        if (((((*(byte *)param_1->pad_104 & 0x40) != 0) ||

             (iVar5 = reaper_is_water_jump__FP6OBJECT(param_1), iVar5 != 0)) ||

            (iVar5 = *(int *)(dVar3 + 0xf44), iVar5 == 0)) ||

           ((*(int *)(iVar5 + 4) == 0xb &&

            ((~*(uint *)(iVar5 + 0x1c8) >> 0x11 & 1) != 0 ||

             (*(uint *)(iVar5 + 0xd8) & 0x4000c000) != 0)))) goto LAB_004bbb8f;

        if (*(int *)(dVar3 + 0xdb4) < 1) {

          fStack_a0 = *(float *)(DAT_00632ed8 + 0xaf0);

          fVar20 = (float10)distancesq2d__FP3P3DT0(&param_1->field_0xa0,iVar5 + 0xa0);

          bVar19 = fVar20 < (float10)fStack_a0 * (float10)fStack_a0;

        }

        else {

          uVar11 = uStack_80;

          switch(*(undefined4 *)(dVar3 + 0xd70 + *(int *)(dVar3 + 0xdb4) * 8)) {

          case 0x2c:

            uVar11 = PROJ_DefGet(0x2b);

            break;

          case 0x2d:

            uVar11 = PROJ_DefGet(0x16);

            break;

          case 0x2e:

            uVar11 = PROJ_DefGet(0x15);

            break;

          case 0x2f:

          case 0x30:

            uVar11 = PROJ_DefGet(0x17);

          }

          fStack_a0 = *(float *)(uVar11 + 0x2c);

          uVar10 = XFGetCameraOrigin(*(int *)(dVar3 + 0xf44) + 0xa0);

          fVar20 = (float10)distancesq3d(uVar10);

          bVar19 = fVar20 < (float10)fStack_a0 * (float10)fStack_a0;

        }

      }

      if (bVar19) {

        *(undefined4 *)(dVar3 + 0xf3c) = 1;

      }

    }

  }

LAB_004bbb8f:

  dVar3 = param_1->animate_state;

  iVar5 = fx_create(param_1);

  if ((iVar5 != 0) && (DAT_00632e74 == 0)) {

    if ((param_1->field_0x20c & 1) == 0) {

      if (DAT_00632bc0 != 0) {

        DAT_00632bc0 = 0;

        DAT_00632bcc = 0;

      }

    }

    else {

      DAT_00632bc0 = 1;

    }

    if (((param_1->field_0x20c & 2) != 0) && (iVar5 = *(int *)(dVar3 + 0xdb0), -1 < iVar5)) {

      do {

        *(int *)(dVar3 + 0xdb0) = iVar5 + 1;

        if (4 < iVar5 + 1) {

          *(undefined4 *)(dVar3 + 0xdb0) = 0;

        }

        iVar5 = *(int *)(dVar3 + 0xdb0);

      } while (*(int *)(dVar3 + 0xd3c + iVar5 * 0xc) < 0);

    }

    if (((param_1->field_0x20c & 4) != 0) && (iVar5 = *(int *)(dVar3 + 0xdb0), -1 < iVar5)) {

      do {

        *(int *)(dVar3 + 0xdb0) = iVar5 + -1;

        if (iVar5 + -1 < 0) {

          *(undefined4 *)(dVar3 + 0xdb0) = 4;

        }

        iVar5 = *(int *)(dVar3 + 0xdb0);

      } while (*(int *)(dVar3 + 0xd3c + iVar5 * 0xc) < 0);

    }

    if (DAT_00632bc4 != 0) {

      if (_DAT_00632bc8 < *(float *)(DAT_00632ed8 + 0x7c8)) {

        fVar21 = (float10)FRateGetSecsframe(0,0);

        fVar20 = (float10)_DAT_00632bc8;

        _DAT_00632bc8 = (float)(fVar21 + fVar20);

        if ((float10)*(float *)(DAT_00632ed8 + 0x7c8) <= fVar21 + fVar20) {

          reaper_finish_hail__FP6OBJECT(param_1);

        }

      }

      if ((*(uint *)&param_1->field_0x20c & 0x100) == 0) {

        if ((*(float *)(DAT_00632ed8 + 0x7c4) < (float)*(int *)(dVar3 + 0xea8) !=

             (*(float *)(DAT_00632ed8 + 0x7c4) == (float)*(int *)(dVar3 + 0xea8))) &&

           (0.0 < *(float *)(DAT_00632ed8 + 0x7c4))) {

          reaper_finish_hail__FP6OBJECT(param_1);

        }

      }

      else {

        fStack_44 = *(float *)&param_1->field_0xa0;

        fStack_40 = *(float *)&param_1->field_0xa4;

        fStack_3c = *(float *)&param_1->field_0xa8;

        hud_screen_project4(&fStack_44);

        fStack_8c = DAT_00632abc;

        fStack_88 = DAT_00632ac0;

        fStack_84 = fStack_30;

        hud_world_to_screen_2(&fStack_8c,&fStack_9c);

        fVar20 = (float10)get_floor_z_point(&fStack_9c);

        fStack_94 = (float)fVar20;

        fStack_44 = fStack_9c;

        fStack_40 = fStack_98;

        fStack_3c = fStack_94;

        hud_screen_project4(&fStack_44);

        fStack_84 = fStack_30;

        hud_world_to_screen_2(&fStack_8c,&uStack_74);

        fVar20 = (float10)get_floor_z_point(&uStack_74);

        fStack_6c = (float)fVar20;

        puVar18 = (undefined4 *)(dVar3 + (*(int *)(dVar3 + 0xea8) + 0x139) * 0xc);

        uStack_68 = 8;

        *puVar18 = uStack_74;

        puVar18[1] = uStack_70;

        puVar23 = auStack_78;

        uVar22 = 0x28;

        pcVar7 = s_fx_ice_target_00560f7c;

        puVar18[2] = fStack_6c;

        uVar10 = fx_get_free_effect__Fv();

        *(undefined4 *)(dVar3 + 0xefc + *(int *)(dVar3 + 0xea8) * 4) = uVar10;

        *(int *)(dVar3 + 0xea8) = *(int *)(dVar3 + 0xea8) + 1;

        sound_play(0x3bc,pcVar7,uVar22,puVar23);

      }

    }

  }

  sound_player_user(param_1,dVar3 + 0xdbc);

  if (*(int *)(dVar3 + 0xe2c) != 0) {

    fVar20 = (float10)FRateGetSecsframe(param_1,0);

    fVar20 = (float10)*(float *)(dVar3 + 0xe30) - fVar20;

    *(float *)(dVar3 + 0xe30) = (float)fVar20;

    if (fVar20 < (float10)0.0 == (fVar20 == (float10)0.0)) {

      reaperbase_enemy_scan

                (param_1,*(undefined4 *)(DAT_00632ed8 + 0x8a8),*(undefined4 *)(DAT_00632ed8 + 0x8a4)

                );

    }

    else {

      reaper_stop_looping_effects(param_1);

    }

  }

  iVar5 = fx_create(param_1);

  if (iVar5 != 0) {

    reaper_firewall_hit(param_1,dVar3 + 0xe80,dVar3 + 0xe88,dVar3 + 0xe84,0x400000);

  }

  if (DAT_00632bc4 != 0) {

    reaper_lock_user(param_1);

    return;

  }

  uVar11 = puStack_ac[0x38f];

  if ((*(byte *)param_1->pad_104 & 0x40) == 0) {

    puStack_ac[0x3c8] = 0;

    if (uVar11 != 0) {

      fx_delete(uVar11);

    }

    puStack_ac[0x38f] = 0;

  }

  else {

    if (uVar11 == 0) {

      pOStack_60 = param_1;

      uStack_64 = 0xffffffff;

      uStack_68 = 8;

      uVar11 = fx_get_free_effect__Fv();

      puStack_ac[0x38f] = uVar11;

    }

    puStack_ac[0x3c8] = 1;

    fVar20 = (float10)FRateGetSecsframe(param_1,0);

    fVar20 = (float10)*(float *)&param_1->field_0x278 -

             fVar20 * (float10)*(float *)(DAT_00632ed8 + 0xba4);

    *(float *)&param_1->field_0x278 = (float)fVar20;

    if (fVar20 < (float10)0.0 != (fVar20 == (float10)0.0)) {

      *(undefined4 *)&param_1->field_0x278 = 0;

    }

  }

  if (((*(uint *)&param_1->field_0x20c & 0x200000) != 0) && (0.0 < *(float *)&param_1->field_0x278))

  {

    dVar3 = param_1->animate_state;

    iVar5 = reaper_can_use_other__FP6OBJECTi(param_1,0x3b);

    if (iVar5 != 0) {

      iVar5 = 0;

      piVar12 = (int *)(dVar3 + 0xd98);

      do {

        if (*piVar12 == 0x3b) {

          iVar14 = *(int *)(dVar3 + 0xd9c + iVar5 * 8) + -1;

          *(int *)(dVar3 + 0xd9c + iVar5 * 8) = iVar14;

          if (iVar14 < 1) {

            reaperbase_target_slot_clear(param_1,0x3b,iVar5);

          }

          sound_play_player(0x3ae,param_1);

          fVar24 = *(float *)&param_1->field_0x278 - *(float *)(DAT_00632ed8 + 0x14c4);

          *(float *)&param_1->field_0x278 = fVar24;

          if (fVar24 < 0.0) {

            *(undefined4 *)&param_1->field_0x278 = 0;

          }

          break;

        }

        iVar5 = iVar5 + 1;

        piVar12 = piVar12 + 2;

      } while (iVar5 < 2);

    }

  }

  fStack_90 = (float)(int)(char)param_1->field_0x20a;

  puStack_ac[0x3d7] = 0;

  puStack_ac[0x36e] = (uint)(float)(int)fStack_90;

  if (DAT_00632bc0 != 0) {

    param_1->field_0x208 = 0;

    param_1->field_0x209 = 0;

  }

  if (DAT_00632ba8 != 0) {

    *(uint *)&param_1->field_0x20c = *(uint *)&param_1->field_0x20c & 0xfdfffeff;

  }

  if (puStack_ac[0x17] == 0x4d) {

    *(uint *)&param_1->field_0x20c = *(uint *)&param_1->field_0x20c & 0xfd3f82cf;

  }

  uVar11 = param_1->coll_radius;

  if ((((((uVar11 & 0xd1bf0000) != 0) || ((uVar11 & 0x20) != 0)) ||

       ((uVar15 = uVar11 & 0x4000000, uVar15 != 0 && ((uStack_80 != 0x1e && (uStack_80 != 0x22))))))

      || (DAT_00632bc4 != 0)) || ((*puStack_ac & 0x24) != 0)) {

    param_1->field_0x20a = 0;

    param_1->field_0x20b = 0;

    if ((*puStack_ac & 0x20) != 0) {

      param_1->field_0x208 = 0;

    }

    *(uint *)&param_1->field_0x20c = *(uint *)&param_1->field_0x20c & 0xfd3f82cf;

    goto LAB_004bc27d;

  }

  if ((uVar11 & 0x10) == 0) {

    if ((char)*puStack_ac < '\0') {

      if (((param_1->field_0x20a == '\0') && (param_1->field_0x20b == '\0')) &&

         (((uVar11 & 0x100) == 0 &&

          ((*(float *)&param_1->field_0x278 < *(float *)&param_1->field_0x1c0 && (uVar15 == 0))))))

      goto LAB_004bc27d;

      uVar10 = IconDefWieldType(puStack_ac[puStack_ac[0x36d] * 2 + 0x35c],1);

      object_create_child(param_1,1,uVar10);

      *puStack_ac = *puStack_ac & 0xffffff7f;

      puStack_ac[0x3d7] = 1;

      obj = (OBJECT *)gun_find_right(param_1);

      ObjectSetAnim(obj);

    }

    else {

      if (((uVar11 & 0x8000000) == 0) ||

         ((((param_1->field_0x20a == '\0' && (param_1->field_0x20b == '\0')) &&

           ((uVar11 & 0x100) == 0)) &&

          ((*(float *)&param_1->field_0x278 < *(float *)&param_1->field_0x1c0 && (uVar15 == 0))))))

      goto LAB_004bc27d;

      obj = (OBJECT *)0x0;

      iVar5 = camera_is_sniper();

      if (iVar5 == 0) {

        obj = (OBJECT *)gun_find_right(param_1);

        playerobj_eval_refpt(obj,0,&uStack_74);

        fx_get_free_effect__Fv();

      }

      param_1->coll_radius = param_1->coll_radius & 0xf7ffffff;

      puStack_ac[0x3d7] = 1;

      if (obj == (OBJECT *)0x0) goto LAB_004bc27d;

    }

  }

  else {

    if ((((param_1->field_0x20a == '\0') && (param_1->field_0x20b == '\0')) &&

        ((uVar11 & 0x100) == 0)) &&

       ((*(float *)&param_1->field_0x278 < *(float *)&param_1->field_0x1c0 && (uVar15 == 0))))

    goto LAB_004bc27d;

    object_create_child(param_1,1,0x29d);

    param_1->coll_radius = param_1->coll_radius & 0xffffffef;

    puStack_ac[0x3d7] = 1;

    obj = (OBJECT *)gun_find_right(param_1);

    ObjectSetAnim(obj);

  }

  if ((*puStack_ac & 2) != 0) {

    obj->flags = obj->flags | 0x40000000;

  }

LAB_004bc27d:

  audio_anode_check(param_1);

  obj_alpha_fade_update(param_1);

  player_pitch_update(param_1);

  ai_flight_check(param_1);

  reaper_set_pitch__FP6OBJECT(param_1);

  iVar5 = fx_logic(2,param_1);

  if (iVar5 == 0) {

    iVar5 = fx_logic(1,param_1);

    if (iVar5 == 0) {

      reaper_walkrun_go__FP6OBJECT(param_1);

    }

    else {

      param_1->vel2 = 0;

      param_1->vel1 = 0;

      param_1->vel0 = 0;

      *(uint *)&param_1->field_0x20c = *(uint *)&param_1->field_0x20c & 0xfdfffeff;

    }

  }

  else {

    param_1->vel2 = 0;

    param_1->vel1 = 0;

  }

  reaper_fire_logic__FP6OBJECT(param_1);

  reaper_check_enter_jet_ski__FP6OBJECT(param_1);

  reaper_replenish_basepit_energy__FP6OBJECT(param_1);

  if (*(int *)&param_1->field_0x174 == 0) {

    reaper_fx_at_bldg_b(param_1);

    reaperbase_dock_check(param_1);

    ai_proximity_scan(param_1);

    reaper_fx_at_bldg_a(param_1);

    reaper_lock_user_2(param_1);

    lzo_checked_alloc(param_1);

    lzo_spawn_checked(param_1);

    reaper_check_enter_teleport__FP6OBJECT(param_1);

  }

  drip_system_init(param_1,puStack_ac + 0x19,0);

  iVar5 = net_active_players_get();

  if (((iVar5 != 0) && (puStack_ac[0x33f] == 0)) &&

     ((uVar11 = base_find_closest(param_1), uVar11 != 0 &&

      (iVar5 = object_spawn_class5(param_1->ai_state_b,uVar11), iVar5 != 0)))) {

    puStack_ac[0x33f] = uVar11;

  }

  reaper_lock_user(param_1);

  objspec_dispatch_gate(param_1);

  object_animate_process(param_1);

  return;

}

/* ===== reaper_lock_user @ 0x004BC3E0 ===== */
void reaper_lock_user(int param_1)



{

  int iVar1;

  int iVar2;

  byte bVar3;

  undefined4 local_24;

  undefined4 local_20;

  undefined4 local_1c;

  undefined4 local_18;

  undefined4 local_14;

  undefined4 local_10;

  undefined4 local_c;

  undefined4 local_8;

  undefined4 local_4;

  

  iVar1 = param_1;

  if ((*(int *)(param_1 + 0x210) == 0) && (iVar2 = reaper_0052e4a0(param_1), iVar2 != 0)) {

    iVar2 = comm_send_gate_check_2(iVar1);

    if (iVar2 != 0) {

      local_24 = *(undefined4 *)(iVar1 + 0xa0);

      local_20 = *(undefined4 *)(iVar1 + 0xa4);

      local_1c = *(undefined4 *)(iVar1 + 0xa8);

      local_18 = *(undefined4 *)(iVar1 + 0x128);

      local_8 = *(undefined4 *)(iVar1 + 0x114);

      local_14 = *(undefined4 *)(iVar1 + 300);

      local_10 = *(undefined4 *)(iVar1 + 0x130);

      local_c = *(undefined4 *)(iVar1 + 200);

      local_4 = *(undefined4 *)(iVar1 + 0x278);

      comm_chat_send_2(iVar1,9,0,0,1,&local_24);

    }

    iVar2 = comm_send_gate_check(iVar1);

    if (iVar2 != 0) {

      bVar3 = (*(uint *)(iVar1 + 0xd8) & 0x2000000) != 0;

      if ((*(uint *)(iVar1 + 0xd8) & 0x1000000) != 0) {

        bVar3 = bVar3 | 2;

      }

      if (bVar3 != 0) {

        local_20 = *(undefined4 *)(iVar1 + 0x15c);

        local_14 = CONCAT22(CONCAT11(bVar3,*(undefined1 *)(iVar1 + 0x208)),

                            *(undefined2 *)(iVar1 + 0x20a));

        local_24 = *(undefined4 *)(iVar1 + 0x158);

        local_1c = *(undefined4 *)(iVar1 + 0x160);

        local_18 = *(undefined4 *)(iVar1 + 0x164);

        comm_chat_send_2(iVar1,4,0,4,2,&local_24);

        return;

      }

      param_1._0_3_ = CONCAT12(*(undefined1 *)(iVar1 + 0x208),*(undefined2 *)(iVar1 + 0x20a));

      comm_chat_send_2(iVar1,0,0,3,3,&param_1);

    }

  }

  return;

}

/* ===== reaper_is_water_jump__FP6OBJECT @ 0x004BC550 ===== */
undefined4 reaper_is_water_jump__FP6OBJECT(int param_1)



{

  int iVar1;

  

  iVar1 = *(int *)(*(int *)(param_1 + 0x100) + 0x5c);

  if ((0x30 < iVar1) && ((iVar1 < 0x38 || (iVar1 == 0x4c)))) {

    return 1;

  }

  return 0;

}

/* ===== audio_listener_update_dup004bc640 @ 0x004BC640 ===== */
int audio_listener_update_dup004bc640(undefined4 param_1,float param_2,float param_3,float param_4)



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

  int iVar16;

  

  pfVar14 = (float *)XFGetCameraOrigin();

  fVar1 = *pfVar14;

  fVar2 = pfVar14[1];

  fVar3 = pfVar14[2];

  pfVar14 = (float *)XFGetCameraAxis(2);

  fVar4 = *pfVar14;

  fVar5 = pfVar14[1];

  fVar6 = pfVar14[2];

  iVar16 = 0;

  fVar9 = param_3 - param_2;

  param_3 = param_4;

  for (puVar8 = DAT_00632d68; puVar8 != (undefined4 *)0x0; puVar8 = (undefined4 *)*puVar8) {

    iVar7 = puVar8[3];

    iVar15 = reaper_xhair_validate__FP6OBJECTPv(iVar7,param_1);

    if ((((iVar15 != 0) && ((*(uint *)(iVar7 + 0xd8) & 0x4000c000) == 0)) &&

        ((*(uint *)(iVar7 + 0x1c8) & 0x400000) != 0)) && (*(float *)(iVar7 + 0x184) < 1.0)) {

      fVar10 = (*(float *)(iVar7 + 0x288) + *(float *)(iVar7 + 0x27c)) * 0.5 -

               (fVar4 * param_2 + fVar1);

      fVar11 = (*(float *)(iVar7 + 0x28c) + *(float *)(iVar7 + 0x280)) * 0.5 -

               (fVar5 * param_2 + fVar2);

      fVar12 = (*(float *)(iVar7 + 0x290) + *(float *)(iVar7 + 0x284)) * 0.5 -

               (fVar6 * param_2 + fVar3);

      fVar13 = fVar10 * fVar4 + fVar11 * fVar5 + fVar12 * fVar6;

      if (((0.0 <= fVar13) && (fVar13 < fVar9)) &&

         (fVar10 = (fVar10 * fVar10 + fVar11 * fVar11 + fVar12 * fVar12) - fVar13 * fVar13,

         fVar10 < param_3)) {

        iVar16 = iVar7;

        param_3 = fVar10;

      }

    }

  }

  return iVar16;

}

/* ===== tracer_aim_fire @ 0x004BC800 ===== */
void tracer_aim_fire(int param_1,float *param_2,undefined4 *param_3)



{

  int iVar1;

  undefined1 local_44 [16];

  undefined4 uStack_34;

  undefined4 uStack_24;

  undefined4 uStack_14;

  

  iVar1 = gun_find_right(param_1);

  (*(code *)PTR_crt_matrix_mul_00580c18)(local_44,iVar1 + 0x294,*(undefined4 *)(iVar1 + 0x2dc));

  *param_2 = -*(float *)(param_1 + 0x29c);

  param_2[1] = -*(float *)(param_1 + 0x2ac);

  param_2[2] = -*(float *)(param_1 + 700);

  normalize__FPfN20(param_2,param_2 + 1,param_2 + 2);

  *param_3 = uStack_34;

  param_3[1] = uStack_24;

  param_3[2] = uStack_14;

  return;

}

/* ===== obj_aim_calc @ 0x004BC880 ===== */
void obj_aim_calc(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,

                 undefined4 param_5)



{

  int iVar1;

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

  

  iVar1 = gun_find_right(param_1);

  (*(code *)PTR_crt_matrix_mul_00580c18)(local_44,iVar1 + 0x294,*(undefined4 *)(iVar1 + 0x2dc));

  fStack_5c = -*(float *)(param_1 + 0x29c);

  fStack_58 = -*(float *)(param_1 + 0x2ac);

  fStack_54 = -*(float *)(param_1 + 700);

  normalize__FPfN20(&fStack_5c,&fStack_58,&fStack_54);

  uStack_50 = uStack_34;

  uStack_4c = uStack_24;

  uStack_48 = uStack_14;

  project_vector_to_object(param_2,param_3,param_4,param_5,&uStack_50,&fStack_5c);

  return;

}

/* ===== reaper_turbo_towards_moving_target__FP6OBJECT @ 0x004BC930 ===== */
/* PS2 candidate: reaper_turbo_towards_moving_target__FP6OBJECT (conf 0.451) */



void reaper_turbo_towards_moving_target__FP6OBJECT(int param_1)



{

  uint *puVar1;

  int iVar2;

  int iVar3;

  undefined4 uVar4;

  float10 fVar5;

  

  iVar2 = *(int *)(param_1 + 0x100);

  distancesq3d(param_1 + 0xa0,*(int *)(iVar2 + 0xc) + 0xa0);

  iVar3 = *(int *)(iVar2 + 0xc);

  *(undefined4 *)(iVar2 + 0x1c) = *(undefined4 *)(iVar3 + 0xa0);

  *(undefined4 *)(iVar2 + 0x20) = *(undefined4 *)(iVar3 + 0xa4);

  *(undefined4 *)(iVar2 + 0x24) = *(undefined4 *)(iVar3 + 0xa8);

  fVar5 = (float10)powf();

  fVar5 = fVar5 * (float10)*(float *)(DAT_00632ed8 + 0xfe0);

  if (fVar5 < (float10)*(float *)(iVar2 + 0x28) != (fVar5 == (float10)*(float *)(iVar2 + 0x28))) {

    *(undefined4 *)(iVar2 + 0xf40) = 1;

    iVar3 = reaper_xhair_validate__FP6OBJECTPv(*(undefined4 *)(iVar2 + 0xc),param_1);

    if ((iVar3 != 0) && ((*(uint *)(*(int *)(iVar2 + 0xc) + 0x1c8) & 0x400000) != 0)) {

      iVar3 = ObjIsKabuto(*(int *)(iVar2 + 0xc));

      if (iVar3 != 0) {

        iVar3 = *(int *)(*(int *)(*(int *)(iVar2 + 0xc) + 0x100) + 0x150);

        *(int *)(iVar2 + 0xc) = iVar3;

        *(undefined4 *)(iVar2 + 0x1c) = *(undefined4 *)(iVar3 + 0xa0);

        *(undefined4 *)(iVar2 + 0x20) = *(undefined4 *)(iVar3 + 0xa4);

        *(undefined4 *)(iVar2 + 0x24) = *(undefined4 *)(iVar3 + 0xa8);

      }

      if (*(int *)(iVar2 + 0x50) == 0) {

        uVar4 = object_allocate_type(0x3d4,0);

        *(undefined4 *)(iVar2 + 0x50) = uVar4;

      }

      puVar1 = (uint *)(*(int *)(iVar2 + 0x50) + 0xd8);

      *puVar1 = *puVar1 & 0xbfffffff;

      puVar1 = (uint *)(*(int *)(iVar2 + 0x50) + 0xd8);

      *puVar1 = *puVar1 | 0x10000;

      GEO_MatIdentity(*(int *)(iVar2 + 0x50) + 0x294);

      SphereFitToObject(*(int *)(iVar2 + 0x50) + 0x294,*(undefined4 *)(iVar2 + 0xc),0x40000000);

    }

  }

  return;

}

/* ===== audio_anode_check @ 0x004BCA70 ===== */
void audio_anode_check(int param_1)



{

  int iVar1;

  int iVar2;

  undefined4 uVar3;

  undefined4 uVar4;

  undefined4 uVar5;

  undefined1 local_44 [68];

  

  iVar2 = param_1;

  if (param_1 != DAT_00632a88) {

    return;

  }

  iVar1 = dialog_level_is_base();

  if (iVar1 == 0) {

    return;

  }

  if (-1 < (char)((uint)*(undefined4 *)(iVar2 + 0x20c) >> 8)) {

    camera_override_done();

    return;

  }

  param_1 = 0;

  iVar1 = *(int *)(*(int *)(iVar2 + 0x100) + 0xfd4);

  if (iVar1 == 0) {

    iVar1 = ref_get_anode2(local_44,&param_1,iVar2,*(undefined4 *)(iVar2 + 0x10),10,

                           *(undefined4 *)(iVar2 + 0x14));

    if (iVar1 != 0) goto LAB_004bcb0b;

    uVar5 = *(undefined4 *)(iVar2 + 0x14);

    uVar4 = 10;

    uVar3 = 1;

  }

  else {

    uVar5 = *(undefined4 *)(iVar1 + 0x14);

    uVar3 = *(undefined4 *)(iVar1 + 0x10);

    uVar4 = 0;

    iVar2 = iVar1;

  }

  ref_get_anode2(local_44,&param_1,iVar2,uVar3,uVar4,uVar5);

LAB_004bcb0b:

  camera_override_begin(local_44);

  AudioSetSpeakerConfig__F14SPEAKER_SYSTEM(param_1);

  return;

}

/* ===== reaper_set_pitch__FP6OBJECT @ 0x004BCB30 ===== */
/* PS2 candidate: reaper_set_pitch__FP6OBJECT (conf 0.374) */



void reaper_set_pitch__FP6OBJECT(int param_1)



{

  int iVar1;

  float10 fVar2;

  float local_8;

  float local_4;

  

  iVar1 = *(int *)(*(int *)(param_1 + 0x100) + 0x5c);

  local_4 = 0.0;

  local_8 = 0.0;

  if ((0x30 < iVar1) &&

     (((iVar1 < 0x38 || (iVar1 == 0x4c)) &&

      ((char)((uint)*(undefined4 *)(param_1 + 0xe0) >> 8) < '\0')))) {

    iVar1 = *(int *)(*(int *)(param_1 + 0x100) + 0x5c);

    if ((iVar1 == 0x4c) || (iVar1 == 0x31)) {

      fVar2 = (float10)dirucalcp3d__FP3P3DT0(param_1 + 0xb8,param_1 + 0xa0);

      local_4 = (float)fVar2;

    }

    else if (iVar1 == 0x36) {

      fVar2 = (float10)dirucalcp3d__FP3P3DT0(param_1 + 0xb8,param_1 + 0xa0);

      local_8 = (float)fVar2;

    }

    else if (iVar1 == 0x37) {

      fVar2 = (float10)dirucalcp3d__FP3P3DT0(param_1 + 0xb8,param_1 + 0xa0);

      local_8 = (float)-fVar2;

    }

  }

  fVar2 = (float10)FRateGetSecsframe(param_1,0,0x461c4000,local_4,param_1 + 0xcc);

  chase_angle((float)(fVar2 * (float10)100.0));

  fVar2 = (float10)FRateGetSecsframe(param_1,0,0x461c4000,local_8,param_1 + 0xd0);

  chase_angle((float)(fVar2 * (float10)100.0));

  return;

}

/* ===== ai_flight_check @ 0x004BCC30 ===== */
void ai_flight_check(int param_1)



{

  undefined4 uVar1;

  int iVar2;

  uint uVar3;

  bool bVar4;

  float10 fVar5;

  

  iVar2 = *(int *)(param_1 + 0x100);

  if (((*(uint *)(param_1 + 0x20c) & 0x200) == 0) || ((*(uint *)(param_1 + 0xe0) & 0x100) != 0)) {

    bVar4 = false;

  }

  else {

    bVar4 = true;

  }

  if ((*(int *)(iVar2 + 0x5c) != 0x22) && (*(int *)(iVar2 + 0x5c) != 0x21)) {

    uVar3 = *(uint *)(param_1 + 0xd8);

    if ((uVar3 & 0x100) == 0) {

      if ((uVar3 & 0x80000) != 0) {

        if ((*(uint *)(param_1 + 0xdc) & 0x100000) == 0) {

          if ((bVar4) && (DAT_00632bc4 == 0)) {

            if ((((*(int *)(iVar2 + 0xf20) == 0) ||

                 ((*(int *)(iVar2 + 0xf24) != 0 || (*(float *)(param_1 + 0x10c) < 0.0)))) ||

                ((*(float *)(param_1 + 0x10c) == 0.0 && (*(float *)(param_1 + 0x110) == 0.0)))) &&

               ((*(float *)(param_1 + 0xcc) == 0.0 && (*(float *)(param_1 + 0xd0) == 0.0)))) {

              *(float *)(param_1 + 0x130) =

                   *(float *)(DAT_00632ed8 + 0x7fc) + *(float *)(param_1 + 0x130);

            }

            *(uint *)(param_1 + 0xd8) = uVar3 | 0x100;

            uVar1 = *(undefined4 *)(DAT_00632ed8 + 0x804);

            *(undefined4 *)(iVar2 + 0xfa4) = 0;

            *(undefined4 *)(iVar2 + 0x60) = uVar1;

            *(uint *)(param_1 + 0xdc) = *(uint *)(param_1 + 0xdc) | 0x100000;

            *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 4;

          }

        }

        else if (!bVar4) {

          *(uint *)(param_1 + 0xdc) = *(uint *)(param_1 + 0xdc) & 0xffefffff;

          return;

        }

      }

    }

    else {

      if ((bVar4) && (0.0 < *(float *)(iVar2 + 0x60))) {

        if ((*(int *)(iVar2 + 0xf20) == 0) || (*(int *)(iVar2 + 0xf24) != 0)) {

          nearest_dist_record(*(undefined4 *)(param_1 + 0x104),*(undefined4 *)(iVar2 + 0x60));

          *(float *)(*(int *)(param_1 + 0x104) + 0x20) =

               *(float *)(DAT_00632ed8 + 0x800) + *(float *)(*(int *)(param_1 + 0x104) + 0x20);

        }

        fVar5 = (float10)FRateGetSecsframe(param_1,0);

        *(float *)(iVar2 + 0x60) = (float)((float10)*(float *)(iVar2 + 0x60) - fVar5);

        return;

      }

      if (((*(byte *)(param_1 + 0xe0) & 4) != 0) &&

         (*(float *)(param_1 + 0x130) < 0.0 != (*(float *)(param_1 + 0x130) == 0.0))) {

        *(undefined4 *)(iVar2 + 0x48) = *(undefined4 *)(param_1 + 0xa8);

        *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) & 0xfffffeff;

        *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xfffffffb | 0x800;

        return;

      }

    }

  }

  return;

}

/* ===== reaper_walkrun_go__FP6OBJECT @ 0x004BCE60 ===== */
/* PS2 candidate: reaper_walkrun_go__FP6OBJECT (conf 0.484) */



void reaper_walkrun_go__FP6OBJECT(OBJECT *param_1)



{

  float *pfVar1;

  uint *puVar2;

  float fVar3;

  float fVar4;

  byte bVar5;

  uint *puVar6;

  float fVar7;

  OBJECT *obj;

  float fVar8;

  bool bVar9;

  undefined4 *puVar10;

  int iVar11;

  undefined4 uVar12;

  uint *puVar13;

  int iVar14;

  int iVar15;

  float *pfVar16;

  uint uVar17;

  dword *pdVar18;

  float *pfVar19;

  dword *pdVar20;

  float10 fVar21;

  char *pcVar22;

  undefined1 *puVar23;

  undefined1 local_34 [4];

  undefined4 local_30;

  undefined4 local_2c;

  undefined4 local_28;

  

  puVar6 = (uint *)param_1->animate_state;

  param_1->flags = param_1->flags | 0x40;

  if (DAT_00632bc4 == 0) {

    bVar5 = *(byte *)param_1->pad_104;

    fVar7 = (float)param_1->loc_accum0;

    obj_vel_reset(param_1);

    obj_speed_sq_calc(param_1);

    PhysicsExApplyLocation(param_1);

    FRateGetSecsframe(param_1,0);

    object_animate_process(param_1);

    if ((*(byte *)param_1->pad_104 & 0x40) == 0) {

      if ((param_1->coll_radius & 0x2000000) == 0) {

        if ((param_1->flags & 0x80000) == 0) {

          if ((((*puVar6 & 2) != 0) && (puVar6[0x3c9] == 0)) &&

             ((iVar11 = *(int *)(param_1->animate_state + 0x5c), iVar11 < 0x31 ||

              ((0x37 < iVar11 && (iVar11 != 0x4c)))))) {

            iVar11 = gun_find_right(param_1);

            if (iVar11 != 0) {

              iVar14 = dialog_level_is_base_dup0052aa70();

              if ((iVar14 == 0) ||

                 (*(float *)&param_1->field_0x278 < *(float *)&param_1->field_0x1c0)) {

                *(uint *)(iVar11 + 0xd8) = *(uint *)(iVar11 + 0xd8) & 0xbfffffff;

              }

              *puVar6 = *puVar6 & 0xfffffffd;

            }

            sound_stop_player(0x34c,param_1);

            puVar6[0x3c7] = *(uint *)(DAT_00632ed8 + 0x828);

            param_1->coll_radius = param_1->coll_radius & 0xffff3fff;

            puVar6[0x3c9] = 0;

          }

        }

        else {

          if ((puVar6[0x38b] == 0) &&

             (((iVar11 = dialog_level_is_base_dup0052aa70(), iVar11 == 0 ||

               (*(float *)&param_1->field_0x278 < *(float *)&param_1->field_0x1c0)) &&

              (iVar11 = gun_find_right(param_1), iVar11 != 0)))) {

            *(uint *)(iVar11 + 0xd8) = *(uint *)(iVar11 + 0xd8) & 0xbfffffff;

          }

          sound_stop_player(0x34c,param_1);

          puVar6[0x3c7] = *(uint *)(DAT_00632ed8 + 0x828);

          param_1->coll_radius = param_1->coll_radius & 0xffff3fff;

          *puVar6 = *puVar6 & 0xfffffffd;

          puVar6[0x3c9] = 0;

        }

      }

      else {

        if ((((param_1->flags & 0x100) == 0) && (puVar6[0x3c8] == 0)) &&

           ((iVar11 = *(int *)(param_1->animate_state + 0x5c), iVar11 < 0x31 ||

            ((0x37 < iVar11 && (iVar11 != 0x4c)))))) {

          if ((puVar6[0x38b] == 0) &&

             (((iVar11 = dialog_level_is_base_dup0052aa70(), iVar11 == 0 ||

               (*(float *)&param_1->field_0x278 < *(float *)&param_1->field_0x1c0)) &&

              (iVar11 = gun_find_right(param_1), iVar11 != 0)))) {

            *(uint *)(iVar11 + 0xd8) = *(uint *)(iVar11 + 0xd8) & 0xbfffffff;

          }

          sound_stop_player(0x34c,param_1);

          puVar6[0x3c7] = *(uint *)(DAT_00632ed8 + 0x828);

          *puVar6 = *puVar6 & 0xfffffffd;

          param_1->coll_radius = param_1->coll_radius & 0xffff3fff;

          puVar6[0x3c9] = 0;

        }

        param_1->coll_radius = param_1->coll_radius & 0xfdffffff;

      }

    }

    PhysicsExCalcControledModelSpeeds

              (param_1,*(undefined4 *)(DAT_00632ed8 + 0x720),*(undefined4 *)(DAT_00632ed8 + 0x724));

    if ((param_1->field_0x20a == '\0') && (param_1->field_0x20b == '\0')) {

      uVar12 = 1;

    }

    else {

      uVar12 = 0;

    }

    obj_gravity_apply(param_1,uVar12);

    if ((*(byte *)param_1->pad_104 & 0x40) != 0) {

      if (((~bVar5 & 0x40) != 0) && (fVar7 < -*(float *)(DAT_00632ed8 + 0x8e4))) {

        local_30 = *(undefined4 *)&param_1->field_0xa0;

        local_2c = *(undefined4 *)&param_1->field_0xa4;

        puVar23 = local_34;

        uVar12 = 8;

        pcVar22 = s_FXB_Splash_00560ffc;

        local_28 = 0;

        fx_get_free_effect__Fv();

        iVar11 = crt_rand_scaled(100,pcVar22,uVar12,puVar23);

        if (iVar11 < 0x32) {

          uVar12 = 0x6df;

        }

        else {

          uVar12 = 0x6e0;

        }

        sound_play_player(uVar12,param_1);

      }

      if ((char)(param_1->coll_radius >> 8) < '\0') {

        obj_bone_update(param_1,*(undefined4 *)(DAT_00632ed8 + 0x80c),

                        *(undefined4 *)(DAT_00632ed8 + 0x80c),*(undefined4 *)(DAT_00632ed8 + 0x810),

                        *(undefined4 *)(DAT_00632ed8 + 0x814),1);

      }

      else {

        obj_bone_update(param_1,*(undefined4 *)(DAT_00632ed8 + 0x818),

                        *(undefined4 *)(DAT_00632ed8 + 0x818),*(undefined4 *)(DAT_00632ed8 + 0x81c),

                        *(undefined4 *)(DAT_00632ed8 + 0x820),1);

      }

      goto LAB_004bd2e5;

    }

    if ((param_1->coll_radius & 0x100) == 0) {

      if (puVar6[0x38b] == 0) {

        obj_bone_update(param_1,*(undefined4 *)(DAT_00632ed8 + 0x728),

                        *(undefined4 *)(DAT_00632ed8 + 0x728),*(undefined4 *)(DAT_00632ed8 + 0x72c),

                        *(undefined4 *)(DAT_00632ed8 + 0x730),param_1->flags & 0x10);

      }

      else {

        obj_bone_update(param_1,*(undefined4 *)(DAT_00632ed8 + 0x740),

                        *(undefined4 *)(DAT_00632ed8 + 0x740),*(undefined4 *)(DAT_00632ed8 + 0x738),

                        *(undefined4 *)(DAT_00632ed8 + 0x73c),param_1->flags & 0x10);

      }

      goto LAB_004bd2e5;

    }

LAB_004bd2f0:

    bVar9 = true;

    if (puVar6[0x38b] != 0) goto LAB_004bd302;

  }

  else {

    FRateGetSecsframe(param_1,0);

    object_animate_process(param_1);

LAB_004bd2e5:

    if ((param_1->coll_radius & 0x100) != 0) goto LAB_004bd2f0;

LAB_004bd302:

    bVar9 = false;

  }

  if ((DAT_00632a88 == param_1) && (DAT_00632bb4 != 0)) {

    return;

  }

  if (*(float *)&param_1->field_0xc8 < 360.0) {

    if (*(float *)&param_1->field_0xc8 < 0.0) {

      fVar7 = *(float *)&param_1->field_0xc8 + 360.0;

      goto LAB_004bd35c;

    }

  }

  else {

    fVar7 = *(float *)&param_1->field_0xc8 - 360.0;

LAB_004bd35c:

    *(float *)&param_1->field_0xc8 = fVar7;

  }

  if (puVar6[0x1a] == 0xffffffff) {

    puVar6[0x1a] = 0;

    do {

      puVar13 = puVar6 + puVar6[0x1a] * 10 + 0x1b;

      *puVar13 = *(uint *)&param_1->field_0xa0;

      puVar13[1] = *(uint *)&param_1->field_0xa4;

      puVar13[2] = *(uint *)&param_1->field_0xa8;

      puVar13[3] = *(uint *)&param_1->field_0xc8;

      puVar13[4] = param_1->anim;

      puVar13[5] = param_1->pad_14;

      puVar13[6] = *(uint *)&param_1->field_0x2c;

      puVar13[7] = *(uint *)&param_1->field_0x58;

      puVar13[8] = *(uint *)&param_1->field_0x5c;

      puVar6[puVar6[0x1a] * 10 + 0x24] = (uint)((float)(int)puVar6[0x1a] * 0.025);

      uVar17 = puVar6[0x1a];

      puVar6[0x1a] = uVar17 + 1;

    } while ((int)(uVar17 + 1) < 0x50);

    puVar6[0x1a] = 0x4f;

  }

  else if (puVar6[0x1a] == 0) {

    puVar13 = puVar6 + 0x331;

    uVar17 = 0;

    goto LAB_004bd3f4;

  }

  uVar17 = puVar6[0x1a];

  puVar13 = puVar6 + uVar17 * 10 + 0x11;

LAB_004bd3f4:

  puVar2 = puVar6 + uVar17 * 10 + 0x1b;

  if ((float)puVar6[uVar17 * 10 + 0x24] - (float)puVar13[9] < 0.025) {

    *puVar2 = *(uint *)&param_1->field_0xa0;

    puVar2[1] = *(uint *)&param_1->field_0xa4;

    puVar2[2] = *(uint *)&param_1->field_0xa8;

    puVar2[3] = *(uint *)&param_1->field_0xc8;

    puVar2[4] = param_1->anim;

    puVar2[5] = param_1->pad_14;

    puVar2[6] = *(uint *)&param_1->field_0x2c;

    puVar2[7] = *(uint *)&param_1->field_0x58;

    puVar2[8] = *(uint *)&param_1->field_0x5c;

    uVar17 = puVar6[0x1a];

    fVar21 = (float10)FRateGetSecsframe(param_1,0);

    puVar6[uVar17 * 10 + 0x24] = (uint)(float)(fVar21 + (float10)(float)puVar6[uVar17 * 10 + 0x24]);

    puVar10 = DAT_00632d74;

  }

  else {

    fVar7 = (float)puVar2[9];

    puVar6[0x1a] = uVar17 + 1;

    if (0x4f < (int)(uVar17 + 1)) {

      puVar6[0x1a] = 0;

    }

    puVar13 = puVar6 + puVar6[0x1a] * 10 + 0x1b;

    *puVar13 = *(uint *)&param_1->field_0xa0;

    puVar13[1] = *(uint *)&param_1->field_0xa4;

    puVar13[2] = *(uint *)&param_1->field_0xa8;

    puVar13[3] = *(uint *)&param_1->field_0xc8;

    puVar13[4] = param_1->anim;

    puVar13[5] = param_1->pad_14;

    puVar13[6] = *(uint *)&param_1->field_0x2c;

    puVar13[7] = *(uint *)&param_1->field_0x58;

    puVar13[8] = *(uint *)&param_1->field_0x5c;

    fVar21 = (float10)FRateGetSecsframe(param_1,0);

    puVar6[puVar6[0x1a] * 10 + 0x24] = (uint)(float)(fVar21 + (float10)fVar7);

    puVar10 = DAT_00632d74;

  }

  do {

    if (puVar10 == (undefined4 *)0x0) {

      return;

    }

    obj = (OBJECT *)puVar10[3];

    if ((obj->state == 0x3e) && (*(OBJECT **)&obj->field_0x274 == param_1)) {

      iVar11 = *(int *)&obj->field_0x174;

      uVar17 = puVar6[0x1a];

      fVar7 = *(float *)(DAT_00632ed8 + 0x500);

      iVar14 = gun_find_right(obj);

      if ((bVar9) && (iVar15 = object_volume_sfx(param_1), iVar15 == 0)) {

        pfVar1 = (float *)(puVar6 + 0x1b);

        fVar7 = (float)puVar6[uVar17 * 10 + 0x24] - (float)(iVar11 + 1) * fVar7;

        pfVar19 = pfVar1 + uVar17 * 10;

        do {

          pfVar16 = pfVar19;

          pfVar19 = (float *)(puVar6 + 0x331);

          if (pfVar16 != pfVar1) {

            pfVar19 = pfVar16 + -10;

          }

          if (pfVar19 == pfVar1 + uVar17 * 10) goto LAB_004bd5ab;

        } while (fVar7 < pfVar19[9]);

        fVar7 = (fVar7 - pfVar19[9]) / (pfVar16[9] - pfVar19[9]);

        fVar8 = 1.0 - fVar7;

        *(float *)&obj->field_0xa0 = fVar8 * *pfVar19 + fVar7 * *pfVar16;

        *(float *)&obj->field_0xa4 = fVar8 * pfVar19[1] + fVar7 * pfVar16[1];

        *(float *)&obj->field_0xa8 = fVar8 * pfVar19[2] + fVar7 * pfVar16[2];

        if (ABS(pfVar19[3] - pfVar16[3]) <= 180.0) {

          *(float *)&obj->field_0xc8 = fVar8 * pfVar19[3] + fVar7 * pfVar16[3];

        }

        else {

          fVar3 = pfVar19[3];

          if (pfVar19[3] < 180.0) {

            fVar3 = fVar3 + 360.0;

          }

          fVar4 = pfVar16[3];

          if (pfVar16[3] < 180.0) {

            fVar4 = fVar4 + 360.0;

          }

          fVar3 = fVar3 * fVar8 + fVar4 * fVar7;

          *(float *)&obj->field_0xc8 = fVar3;

          if (360.0 <= fVar3) {

            *(float *)&obj->field_0xc8 = fVar3 - 360.0;

          }

        }

        if (pfVar16[4] != 3.5593e-43) {

          ObjectSetAnim(obj);

          if (pfVar19[4] == pfVar16[4]) {

            obj->pad_14 = (dword)(fVar8 * pfVar19[5] + fVar7 * pfVar16[5]);

            fVar7 = fVar8 * pfVar19[6] + fVar7 * pfVar16[6];

            *(float *)&obj->field_0x2c = fVar7;

            if (0.0 < fVar7) {

              pdVar18 = &obj->anim;

              pdVar20 = (dword *)&obj->field_0x58;

              for (iVar11 = 9; iVar11 != 0; iVar11 = iVar11 + -1) {

                *pdVar20 = *pdVar18;

                pdVar18 = pdVar18 + 1;

                pdVar20 = pdVar20 + 1;

              }

              *(float *)&obj->field_0x58 = pfVar16[7];

              *(float *)&obj->field_0x5c = pfVar16[8];

            }

          }

          else {

            obj->pad_14 = (dword)(fVar7 * pfVar16[5]);

            if (pfVar16[6] <= 0.0) {

              *(undefined4 *)&obj->field_0x2c = 0;

            }

            else {

              pdVar18 = &obj->anim;

              pdVar20 = (dword *)&obj->field_0x58;

              for (iVar11 = 9; iVar11 != 0; iVar11 = iVar11 + -1) {

                *pdVar20 = *pdVar18;

                pdVar18 = pdVar18 + 1;

                pdVar20 = pdVar20 + 1;

              }

              *(float *)&obj->field_0x58 = pfVar16[7];

              *(float *)&obj->field_0x5c = pfVar16[8];

              *(float *)&obj->field_0x2c = fVar7 * pfVar16[6] + fVar8;

            }

          }

        }

        obj->flags = obj->flags & 0xbfffffff;

      }

      else {

LAB_004bd5ab:

        obj->flags = obj->flags | 0x40000000;

        if (iVar14 != 0) {

          *(uint *)(iVar14 + 0xd8) = *(uint *)(iVar14 + 0xd8) | 0x40000000;

        }

      }

    }

    puVar10 = (undefined4 *)*puVar10;

  } while( true );

}

/* ===== reaper_change_bow__FP6OBJECT @ 0x004BD7C0 ===== */
/* PS2 candidate: reaper_change_bow__FP6OBJECT (conf 0.414) */



void reaper_change_bow__FP6OBJECT(uint param_1)



{

  uint *puVar1;

  uint *puVar2;

  uint uVar3;

  int iVar4;

  int iVar5;

  undefined4 uVar6;

  uint *puVar7;

  undefined1 local_30 [48];

  

  iVar4 = param_1;

  puVar2 = *(uint **)(param_1 + 0x100);

  if (puVar2[0x36d] == 0xffffffff) {

    return;

  }

  uVar3 = *(uint *)(param_1 + 0xe0);

  if (((uVar3 & 0x40) == 0) || ((*puVar2 & 1) != 0)) {

    if (((*(char *)(param_1 + 0x20a) != '\0') ||

        (((*(char *)(param_1 + 0x20b) != '\0' || ((uVar3 & 0x100) != 0)) ||

         (*(float *)(param_1 + 0x1c0) <= *(float *)(param_1 + 0x278))))) ||

       ((uVar3 & 0x4000000) != 0)) {

      uVar6 = gun_find_right(param_1);

      if (((*puVar2 & 2) == 0) && (iVar5 = camera_is_sniper(), iVar5 == 0)) {

        playerobj_eval_refpt(uVar6,0,local_30);

        fx_get_free_effect__Fv();

      }

      uVar6 = IconDefWieldType(puVar2[puVar2[0x36d] * 2 + 0x35c],1);

      object_create_child(iVar4,1,uVar6);

      iVar5 = gun_find_right(iVar4);

      if ((*puVar2 & 2) != 0) {

        *(uint *)(iVar5 + 0xd8) = *(uint *)(iVar5 + 0xd8) | 0x40000000;

      }

    }

    else {

      *(uint *)(param_1 + 0xe0) = uVar3 & 0xffffff7f;

      if (puVar2[0x38e] != 0) {

        fx_delete(puVar2[0x38e]);

        puVar2[0x38e] = 0;

      }

      *(uint *)(iVar4 + 0xe0) = *(uint *)(iVar4 + 0xe0) & 0xffffffbf;

      *puVar2 = *puVar2 & 0xfffffffe;

      *(uint *)(iVar4 + 0xe0) = *(uint *)(iVar4 + 0xe0) | 0x8000000;

    }

  }

  else {

    iVar5 = camera_is_sniper();

    if (iVar5 == 0) {

      uVar6 = gun_find_right(iVar4);

      playerobj_eval_refpt(uVar6,0,local_30);

      fx_get_free_effect__Fv();

    }

    puVar7 = *(uint **)(iVar4 + 0x100);

    *(uint *)(iVar4 + 0xe0) = *(uint *)(iVar4 + 0xe0) & 0xffffff7f;

    if (puVar7[0x38e] != 0) {

      fx_delete(puVar7[0x38e]);

      puVar7[0x38e] = 0;

    }

    *(uint *)(iVar4 + 0xe0) = *(uint *)(iVar4 + 0xe0) & 0xffffffbf;

    *puVar7 = *puVar7 & 0xfffffffe;

    uVar6 = IconDefWieldType(puVar2[puVar2[0x36d] * 2 + 0x35c],1);

    object_create_child(iVar4,1,uVar6);

  }

  switch(*(undefined4 *)

          (*(int *)(iVar4 + 0x100) + 0xd70 + *(int *)(*(int *)(iVar4 + 0x100) + 0xdb4) * 8)) {

  case 0x2c:

    uVar6 = 0x38e;

    break;

  case 0x2d:

    uVar6 = 0x391;

    break;

  case 0x2e:

    uVar6 = 0x396;

    break;

  case 0x2f:

    uVar6 = 0x36b;

    break;

  case 0x30:

    uVar6 = 0x38a;

    break;

  default:

    goto switchD_004bd98b_default;

  }

  sound_play_player(uVar6,iVar4);

switchD_004bd98b_default:

  *(uint *)(iVar4 + 0xe0) = *(uint *)(iVar4 + 0xe0) & 0xffffffef;

  *puVar2 = *puVar2 & 0xffffff7f;

  puVar2[1] = 0;

  if (puVar2[0x3e4] != 0) {

    sound_stop_player(0x36c,iVar4);

    puVar2[0x3fd] = 0;

    *(uint *)(puVar2[0x3e4] + 0xd8) = *(uint *)(puVar2[0x3e4] + 0xd8) | 0x40000000;

  }

  iVar5 = 0;

  if (0 < (int)puVar2[0x36b]) {

    puVar7 = puVar2 + 0x3dd;

    do {

      if (*puVar7 != 0) {

        puVar1 = (uint *)(*puVar7 + 0xd8);

        *puVar1 = *puVar1 | 0x40000000;

      }

      iVar5 = iVar5 + 1;

      puVar7 = puVar7 + 1;

    } while (iVar5 < (int)puVar2[0x36b]);

  }

  iVar5 = reaper_0052e4a0(iVar4);

  if (iVar5 != 0) {

    param_1 = puVar2[puVar2[0x36d] * 2 + 0x35c];

    reaper_00530bd0(iVar4,0,1,0,0x32,&param_1);

  }

  return;

}

/* ===== reaper_select_bow @ 0x004BDAA0 ===== */
/* PS2 candidate: reaper_select_bow (conf 0.359) */



void reaper_select_bow(uint param_1)



{

  uint *puVar1;

  uint uVar2;

  uint uVar3;

  undefined4 uVar4;

  int iVar5;

  

  uVar3 = param_1;

  puVar1 = *(uint **)(param_1 + 0x100);

  if (-1 < (int)(puVar1[0x36d] - 1)) {

    if ((((*(char *)(param_1 + 0x20a) != '\0') || (*(char *)(param_1 + 0x20b) != '\0')) ||

        (uVar2 = *(uint *)(param_1 + 0xe0), (uVar2 & 0x100) != 0)) ||

       ((*(float *)(param_1 + 0x1c0) <= *(float *)(param_1 + 0x278) || ((uVar2 & 0x4000000) != 0))))

    {

      uVar4 = IconDefWieldType(puVar1[puVar1[0x36d] * 2 + 0x35c],1);

      object_create_child(uVar3,1,uVar4);

      iVar5 = gun_find_right(uVar3);

      if ((*puVar1 & 2) != 0) {

        *(uint *)(iVar5 + 0xd8) = *(uint *)(iVar5 + 0xd8) | 0x40000000;

      }

    }

    else {

      *(uint *)(param_1 + 0xe0) = uVar2 & 0xffffffef;

      *puVar1 = *puVar1 | 0x80;

    }

    iVar5 = reaper_0052e4a0(uVar3);

    if (iVar5 != 0) {

      param_1 = puVar1[puVar1[0x36d] * 2 + 0x35c];

      reaper_00530bd0(uVar3,0,1,0,5,&param_1);

    }

    puVar1[999] = 0;

    switch(*(undefined4 *)

            (*(int *)(uVar3 + 0x100) + 0xd70 + *(int *)(*(int *)(uVar3 + 0x100) + 0xdb4) * 8)) {

    case 0x2c:

      uVar4 = 0x3c6;

      break;

    case 0x2d:

      uVar4 = 0x3c7;

      break;

    case 0x2e:

      uVar4 = 0x3c8;

      break;

    case 0x2f:

      uVar4 = 0x3c4;

      break;

    case 0x30:

      uVar4 = 0x3c5;

      break;

    default:

      goto switchD_004bdb93_default;

    }

    sound_play_player(uVar4,uVar3);

  }

switchD_004bdb93_default:

  *(uint *)(uVar3 + 0x20c) = *(uint *)(uVar3 + 0x20c) & 0xfdfffeff;

  return;

}

/* ===== reaper_select_sword @ 0x004BDBF0 ===== */
/* PS2 candidate: reaper_select_sword (conf 0.358) */



void reaper_select_sword(int param_1)



{

  uint *puVar1;

  uint *puVar2;

  uint uVar3;

  int iVar4;

  uint *puVar5;

  

  puVar2 = *(uint **)(param_1 + 0x100);

  puVar2[999] = 3;

  if ((((*(char *)(param_1 + 0x20a) != '\0') || (*(char *)(param_1 + 0x20b) != '\0')) ||

      (uVar3 = *(uint *)(param_1 + 0xe0), (uVar3 & 0x100) != 0)) ||

     ((*(float *)(param_1 + 0x1c0) <= *(float *)(param_1 + 0x278) || ((uVar3 & 0x4000000) != 0)))) {

    object_create_child(param_1,1,0x29d);

    iVar4 = gun_find_right(param_1);

    if ((*puVar2 & 2) != 0) {

      *(uint *)(iVar4 + 0xd8) = *(uint *)(iVar4 + 0xd8) | 0x40000000;

    }

  }

  else {

    *(uint *)(param_1 + 0xe0) = uVar3 | 0x10;

    *puVar2 = *puVar2 & 0xffffff7f;

    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xf7ffffff;

  }

  sound_play_player(0x334,param_1);

  puVar5 = *(uint **)(param_1 + 0x100);

  *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xffffff7f;

  if (puVar5[0x38e] != 0) {

    fx_delete(puVar5[0x38e]);

    puVar5[0x38e] = 0;

  }

  *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xffffffbf;

  *puVar5 = *puVar5 & 0xfffffffe;

  iVar4 = reaper_0052e4a0(param_1);

  if (iVar4 != 0) {

    reaper_00530bd0(param_1,0,0,0,4,0);

  }

  *(uint *)(param_1 + 0x20c) = *(uint *)(param_1 + 0x20c) & 0xfdfffeff;

  if (puVar2[0x3e4] != 0) {

    sound_stop_player(0x36c,param_1);

    puVar2[0x3fd] = 0;

    *(uint *)(puVar2[0x3e4] + 0xd8) = *(uint *)(puVar2[0x3e4] + 0xd8) | 0x40000000;

  }

  if (puVar2[0x3e4] != 0) {

    sound_stop_player(0x36c,param_1);

    puVar2[0x3fd] = 0;

    *(uint *)(puVar2[0x3e4] + 0xd8) = *(uint *)(puVar2[0x3e4] + 0xd8) | 0x40000000;

  }

  iVar4 = 0;

  if (0 < (int)puVar2[0x36b]) {

    puVar5 = puVar2 + 0x3dd;

    do {

      if (*puVar5 != 0) {

        puVar1 = (uint *)(*puVar5 + 0xd8);

        *puVar1 = *puVar1 | 0x40000000;

      }

      iVar4 = iVar4 + 1;

      puVar5 = puVar5 + 1;

    } while (iVar4 < (int)puVar2[0x36b]);

  }

  return;

}

/* ===== reaper_fire_logic__FP6OBJECT @ 0x004BDDB0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* PS2 candidate: reaper_fire_logic__FP6OBJECT (conf 0.383) */



void reaper_fire_logic__FP6OBJECT(int param_1)



{

  int iVar1;

  uint *puVar2;

  bool bVar3;

  float10 fVar4;

  

  iVar1 = *(int *)(param_1 + 0x100);

  if (param_1 == DAT_00632a88) {

    _DAT_00632ba0 = 0;

  }

  fVar4 = (float10)FRateGetSecsframe(param_1,0);

  *(float *)(iVar1 + 0xf1c) = (float)((float10)*(float *)(iVar1 + 0xf1c) - fVar4);

  if ((*(byte *)(param_1 + 0x20c) & 0x40) != 0) {

    reaper_cycle_weapon__FP6OBJECTi(param_1,1);

  }

  if (*(char *)(param_1 + 0x20c) < '\0') {

    reaper_cycle_weapon__FP6OBJECTi(param_1,0);

  }

  if ((DAT_00632bc0 != 0) || (DAT_00632bc4 != 0)) {

    puVar2 = *(uint **)(param_1 + 0x100);

    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xffffff7f;

    if (puVar2[0x38e] != 0) {

      fx_delete(puVar2[0x38e]);

      puVar2[0x38e] = 0;

    }

    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xffffffbf;

    *puVar2 = *puVar2 & 0xfffffffe;

    *(uint *)(param_1 + 0x20c) = *(uint *)(param_1 + 0x20c) & 0xfdffffff;

    if (DAT_00632bc4 != 0) {

      return;

    }

  }

  if ((**(byte **)(param_1 + 0x104) & 0x40) == 0) {

    if (0 < *(int *)(iVar1 + 0xdb4)) {

      reaper_fire_bow__FP6OBJECT(param_1);

      return;

    }

    if (DAT_00632bc0 == 0) {

      reaper_fire_sword__FP6OBJECT(param_1);

    }

  }

  else {

    puVar2 = *(uint **)(param_1 + 0x100);

    if ((*(uint *)(param_1 + 0x20c) & 0x2000000) == 0) {

      if ((char)((uint)*(undefined4 *)(param_1 + 0xe0) >> 8) < '\0') {

        sound_stop_player(0x34c,param_1);

        puVar2[0x3c7] = *(uint *)(DAT_00632ed8 + 0x828);

        *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xffff3fff;

        puVar2[0x3c9] = 0;

      }

      *puVar2 = *puVar2 & 0xfffffff7;

      return;

    }

    *puVar2 = *puVar2 | 8;

    bVar3 = *(float *)(param_1 + 0x10c) != 0.0;

    if ((*(uint *)(param_1 + 0xe0) & 0xc000) == 0) {

      if (((bVar3) || (*(float *)(param_1 + 0x110) != 0.0)) &&

         ((float)puVar2[0x3c7] < 0.0 != ((float)puVar2[0x3c7] == 0.0))) {

        sound_play_player(0x34c,param_1);

        puVar2[0x3c7] = *(uint *)(DAT_00632ed8 + 0x824);

        *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 0xc000;

        puVar2[0x3c9] = 1;

        return;

      }

    }

    else {

      if ((!bVar3) && (*(float *)(param_1 + 0x110) == 0.0)) {

        puVar2[0x3c7] = 0;

      }

      if (((float)puVar2[0x3c7] < 0.0 != ((float)puVar2[0x3c7] == 0.0)) &&

         (0.0 < *(float *)(DAT_00632ed8 + 0x824))) {

        sound_stop_player(0x34c,param_1);

        puVar2[0x3c7] = *(uint *)(DAT_00632ed8 + 0x828);

        *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xffff3fff;

        puVar2[0x3c9] = 0;

        return;

      }

    }

  }

  return;

}

/* ===== make_arrow__FP6OBJECTT0P3P3DPUii @ 0x004BE020 ===== */
/* PS2 candidate: make_arrow__FP6OBJECTT0P3P3DPUii (conf 0.489) */



void make_arrow__FP6OBJECTT0P3P3DPUii

               (int param_1,undefined4 param_2,uint *param_3,undefined4 *param_4,undefined4 param_5)



{

  uint *puVar1;

  uint *puVar2;

  uint uVar3;

  OBJECT *obj;

  int iVar4;

  int iVar5;

  int iVar6;

  float10 fVar7;

  float10 fVar8;

  undefined4 local_c0;

  undefined4 local_bc;

  undefined4 local_b8;

  uint local_b4;

  uint local_b0;

  uint local_ac;

  int local_a8;

  uint *local_a4;

  float local_a0;

  uint local_9c;

  uint local_98;

  uint local_94;

  undefined4 local_90;

  undefined4 local_8c;

  uint local_88 [4];

  undefined4 local_78;

  undefined4 local_68;

  undefined4 local_58;

  uint local_44;

  uint local_40;

  uint local_3c;

  undefined4 auStack_38 [5];

  undefined4 local_24 [4];

  undefined4 local_14;

  

  puVar2 = *(uint **)(param_1 + 0x100);

  obj = (OBJECT *)gun_find_right(param_1);

  object_lock_with_volume(obj);

  iVar6 = 0;

  object_animate_process(obj);

  local_a8 = 0;

  switch(param_5) {

  case 0x2c:

    PROJ_DefGet(0x2b);

    playerobj_eval_refpt(obj,0,&local_c0);

    local_b4 = *param_3;

    local_b0 = param_3[1];

    local_ac = param_3[2];

    fVar7 = (float10)dirucalcp3d__FP3P3DT0(&local_c0,&local_b4);

    local_a0 = (float)fVar7;

    fVar7 = (float10)dirfcalcp3d__FP3P3DT0(&local_c0,&local_b4);

    local_44 = 0;

    GEO_MatBuildXYZ(&local_44,-local_a0,0,(float)fVar7);

    auStack_38[1] = local_c0;

    local_44 = local_44 | 0x10;

    local_24[0] = local_bc;

    local_14 = local_b8;

    iVar6 = PROJ_Create3(0x2b,*(undefined4 *)(param_1 + 0x18c),param_1,0,&local_44,0);

    *(int *)(iVar6 + 0x274) = param_1;

    iVar4 = fx_create(param_1);

    if (iVar4 == 0) {

      *(undefined4 *)(iVar6 + 0x188) = *param_4;

    }

    else {

      iVar4 = reaper_0052e4a0(param_1);

      if (iVar4 != 0) {

        local_98 = local_b0;

        local_9c = local_b4;

        local_90 = *(undefined4 *)(iVar6 + 0x188);

        local_94 = local_ac;

        reaper_00530bd0(param_1,3,1,0,9,&local_9c);

      }

    }

    sound_play_player(0x38d,param_1);

    local_a8 = 0;

    break;

  case 0x2d:

    PROJ_DefGet(0x16);

    playerobj_eval_refpt(obj,0,&local_c0);

    local_b4 = *param_3;

    local_b0 = param_3[1];

    local_ac = param_3[2];

    fVar7 = (float10)dirucalcp3d__FP3P3DT0(&local_c0,&local_b4);

    fVar8 = (float10)dirfcalcp3d__FP3P3DT0(&local_c0,&local_b4);

    local_88[0] = 0;

    GEO_MatBuildXYZ(local_88,-(float)fVar7,0,(float)fVar8);

    local_78 = local_c0;

    local_68 = local_bc;

    local_58 = local_b8;

    local_88[0] = local_88[0] | 0x10;

    iVar6 = PROJ_Create3(0x16,*(undefined4 *)(param_1 + 0x18c),param_1,0,local_88,0);

    *(int *)(iVar6 + 0x274) = param_1;

    iVar4 = fx_create(param_1);

    if (iVar4 == 0) {

      *(undefined4 *)(iVar6 + 0x188) = *param_4;

    }

    else {

      iVar4 = reaper_0052e4a0(param_1);

      if (iVar4 != 0) {

        local_98 = local_b0;

        local_9c = local_b4;

        local_90 = *(undefined4 *)(iVar6 + 0x188);

        local_94 = local_ac;

        reaper_00530bd0(param_1,3,1,0,0x1f,&local_9c);

      }

    }

    sound_play_player(0x390,param_1);

    local_a8 = 1;

    break;

  case 0x2e:

    PROJ_DefGet(0x15);

    playerobj_eval_refpt(obj,0,&local_c0);

    local_b4 = *param_3;

    local_b0 = param_3[1];

    local_ac = param_3[2];

    fVar7 = (float10)dirucalcp3d__FP3P3DT0(&local_c0,&local_b4);

    fVar8 = (float10)dirfcalcp3d__FP3P3DT0(&local_c0,&local_b4);

    local_88[0] = 0;

    GEO_MatBuildXYZ(local_88,-(float)fVar7,0,(float)fVar8);

    local_78 = local_c0;

    local_88[0] = local_88[0] | 0x10;

    local_68 = local_bc;

    local_58 = local_b8;

    iVar6 = PROJ_Create3(0x15,*(undefined4 *)(param_1 + 0x18c),param_1,0,local_88,0);

    *(int *)(iVar6 + 0x274) = param_1;

    sound_play_player(0x395,param_1);

    iVar4 = fx_create(param_1);

    if (iVar4 == 0) {

      *(undefined4 *)(iVar6 + 0x188) = *param_4;

      local_a8 = 1;

    }

    else {

      iVar4 = reaper_0052e4a0(param_1);

      if (iVar4 != 0) {

        local_98 = local_b0;

        local_9c = local_b4;

        local_90 = *(undefined4 *)(iVar6 + 0x188);

        local_94 = local_ac;

        reaper_00530bd0(param_1,3,1,0,0x21,&local_9c);

      }

      local_a8 = 1;

    }

    break;

  case 0x2f:

    if (((float)puVar2[0x3e6] < 0.0 != ((float)puVar2[0x3e6] == 0.0)) && (puVar2[0x3e3] != 0)) {

      puVar2[0x3e6] = *(uint *)(DAT_00632ed8 + 0x8dc);

      puVar2[999] = 0;

      if (puVar2[0x3e4] != 0) {

        sound_stop_player(0x36c,param_1);

        puVar2[0x3fd] = 0;

        *(uint *)(puVar2[0x3e4] + 0xd8) = *(uint *)(puVar2[0x3e4] + 0xd8) | 0x40000000;

      }

      playerobj_eval_refpt(obj,0,&local_c0);

      fVar7 = (float10)dirucalcp3d__FP3P3DT0(&local_c0,param_3);

      fVar8 = (float10)dirfcalcp3d__FP3P3DT0(&local_c0,param_3);

      local_88[0] = 0;

      GEO_MatBuildXYZ(local_88,-(float)fVar7,0,(float)fVar8);

      local_78 = local_c0;

      local_58 = local_b8;

      local_68 = local_bc;

      local_88[0] = local_88[0] | 0x10;

      iVar6 = PROJ_Create3(0x17,*(undefined4 *)(param_1 + 0x18c),param_1,0,local_88,puVar2[0x3e3]);

      *(int *)(iVar6 + 0x274) = param_1;

      sound_play_player(0x36a,param_1);

      iVar4 = fx_create(param_1);

      if (iVar4 == 0) {

        *(undefined4 *)(iVar6 + 0x188) = *param_4;

        local_a8 = 1;

      }

      else {

        iVar4 = reaper_0052e4a0(param_1);

        if (iVar4 != 0) {

          local_9c = *param_3;

          local_98 = param_3[1];

          local_94 = param_3[2];

          local_8c = *(undefined4 *)(iVar6 + 0x188);

          local_90 = *(undefined4 *)(puVar2[0x3e3] + 0x188);

          reaper_00530bd0(param_1,3,2,0,0x20,&local_9c);

        }

        local_a8 = 1;

      }

    }

    break;

  case 0x30:

    local_a0 = 0.0;

    playerobj_eval_refpt(obj,0,&local_c0);

    fVar7 = (float10)dirucalcp3d__FP3P3DT0(&local_c0,param_3);

    fVar8 = (float10)dirfcalcp3d__FP3P3DT0(&local_c0,param_3);

    local_a4 = (uint *)(float)fVar8;

    local_88[0] = 0;

    GEO_MatBuildXYZ(local_88,-(float)fVar7,0,local_a4);

    local_58 = local_b8;

    local_68 = local_bc;

    local_88[0] = local_88[0] | 0x10;

    local_78 = local_c0;

    if (0 < (int)puVar2[0x36b]) {

      local_a4 = puVar2 + 0x3dd;

      do {

        uVar3 = local_a4[-5];

        if (uVar3 != 0) {

          local_a0 = (float)((int)local_a0 + 1);

          iVar4 = PROJ_Create3(0x34,*(undefined4 *)(param_1 + 0x18c),param_1,0,local_88,uVar3);

          *(int *)(iVar4 + 0x274) = param_1;

          iVar5 = fx_create(param_1);

          if (iVar5 == 0) {

            *(undefined4 *)(iVar4 + 0x188) = param_4[iVar6];

          }

          else {

            iVar5 = reaper_0052e4a0(param_1);

            if (iVar5 != 0) {

              local_44 = *param_3;

              local_40 = param_3[1];

              local_3c = param_3[2];

              local_24[iVar6] = *(undefined4 *)(iVar4 + 0x188);

              auStack_38[iVar6] = *(undefined4 *)(uVar3 + 0x188);

            }

          }

          local_a4[-5] = 0;

          local_a8 = 1;

        }

        if (*local_a4 != 0) {

          puVar1 = (uint *)(*local_a4 + 0xd8);

          *puVar1 = *puVar1 | 0x40000000;

        }

        iVar6 = iVar6 + 1;

        local_a4 = local_a4 + 1;

      } while (iVar6 < (int)puVar2[0x36b]);

    }

    sound_play_player(0x389,param_1);

    iVar6 = reaper_0052e4a0(param_1);

    if ((iVar6 != 0) && (local_a0 != 0.0)) {

      reaper_00530bd0(param_1,3,10,0,0x22,&local_44);

    }

  }

  puVar2[puVar2[0x36d] * 2 + 0x35d] = puVar2[puVar2[0x36d] * 2 + 0x35d] - local_a8;

  if (((int)puVar2[puVar2[0x36d] * 2 + 0x35d] < 0) && (0 < local_a8)) {

    puVar2[puVar2[0x36d] * 2 + 0x35d] = 0;

  }

  iVar6 = *(int *)(param_1 + 0x100);

  *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xffffff7f;

  iVar4 = *(int *)(iVar6 + 0xe38);

  if (iVar4 != 0) {

    fx_delete(iVar4);

    *(undefined4 *)(iVar6 + 0xe38) = 0;

  }

  *puVar2 = *puVar2 | 1;

  *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 0x200;

  mecc_indicate_shots_fired__FP6OBJECT(param_1);

  return;

}

/* ===== fxb_splash_create @ 0x004BE850 ===== */
/* PS2 candidate: reaper_check_turbo__FP6OBJECT (conf 0.429) */



void fxb_splash_create(int param_1)



{

  uint *puVar1;

  float10 fVar2;

  

  puVar1 = *(uint **)(param_1 + 0x100);

  fVar2 = (float10)FRateGetSecsframe(param_1,0);

  fVar2 = (float10)(float)puVar1[0xb] - fVar2;

  puVar1[0xb] = (uint)(float)fVar2;

  if ((float10)0.0 < fVar2) {

    puVar1[10] = 0;

  }

  if ((*(uint *)(param_1 + 0xe0) & 0x100) == 0) {

    if (*(int *)(DAT_006330e4 + 0x4e80) != 0) {

      puVar1[10] = 0;

      return;

    }

    if (fVar2 < (float10)0.0 == (fVar2 == (float10)0.0)) {

      return;

    }

    fVar2 = (float10)FRateGetSecsframe(param_1,0);

    fVar2 = fVar2 * (float10)*(float *)(DAT_00632ed8 + 0x86c) + (float10)(float)puVar1[10];

    puVar1[10] = (uint)(float)fVar2;

    if (fVar2 <= (float10)*(float *)(DAT_00632ed8 + 0x868)) {

      return;

    }

    puVar1[10] = *(uint *)(DAT_00632ed8 + 0x868);

    return;

  }

  if (((((**(byte **)(param_1 + 0x104) & 0x44) != 0) || (*(int *)(param_1 + 0x220) != 0)) ||

      ((float)puVar1[10] < 0.0 != ((float)puVar1[10] == 0.0))) ||

     (*(float *)(param_1 + 0x1c0) <= *(float *)(param_1 + 0x278))) {

    sound_interrupt_sequence(puVar1 + 0x3fb);

    *(undefined4 *)(*(int *)(param_1 + 0x104) + 4) = *(undefined4 *)(DAT_00632ed8 + 0x704);

    *(undefined4 *)(*(int *)(param_1 + 0x104) + 8) = *(undefined4 *)(DAT_00632ed8 + 0x708);

    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xfffffeff;

    if ((**(byte **)(param_1 + 0x104) & 0x40) == 0) {

      if (0.0 < (float)puVar1[10]) {

        *puVar1 = *puVar1 | 0x10;

      }

    }

    else {

      fx_get_free_effect__Fv();

    }

LAB_004be9ad:

    if (puVar1[2] != 0) {

      fVar2 = (float10)FRateGetSecsframe(param_1,0);

      fVar2 = ((float10)*(float *)(DAT_00632ed8 + 0xfe0) / (float10)*(float *)(DAT_00632ed8 + 0x748)

              ) * fVar2;

      goto LAB_004be9d9;

    }

  }

  else if (puVar1[2] != 0) {

    if (0.0 < (float)puVar1[0x13]) {

      physics_reset_b(param_1);

      fVar2 = (float10)FRateGetSecsframe(param_1,0);

      puVar1[0x13] = (uint)(float)((float10)(float)puVar1[0x13] - fVar2);

    }

    goto LAB_004be9ad;

  }

  fVar2 = (float10)FRateGetSecsframe(param_1,0);

LAB_004be9d9:

  puVar1[10] = (uint)(float)((float10)(float)puVar1[10] - fVar2);

  if (0.0 <= (float)puVar1[10]) {

    return;

  }

  puVar1[10] = 0;

  return;

}

/* ===== reaper_fire_spell__FP6OBJECTiP3P3DT0i @ 0x004BEA70 ===== */
/* PS2 candidate: reaper_fire_spell__FP6OBJECTiP3P3DT0i (conf 0.444) */



void reaper_fire_spell__FP6OBJECTiP3P3DT0i

               (int param_1,int param_2,undefined4 *param_3,undefined4 param_4,undefined4 param_5)



{

  int iVar1;

  int iVar2;

  int *piVar3;

  int iVar4;

  int iVar5;

  float10 fVar6;

  float10 fVar7;

  undefined4 uVar8;

  undefined4 local_60;

  undefined4 local_5c;

  undefined4 local_58;

  undefined4 local_54;

  undefined4 local_50;

  undefined4 local_4c;

  undefined4 local_48;

  uint local_44 [4];

  undefined4 local_34;

  undefined4 local_24;

  undefined4 local_14;

  

  playerobj_eval_refpt(param_1,0,&local_60);

  if (param_2 == 0x2c) {

    iVar1 = *(int *)(param_1 + 0x100);

    piVar3 = (int *)(iVar1 + 0xd9c);

    iVar4 = 0;

    do {

      if ((piVar3[-1] == 0x3f) && (0 < *piVar3)) {

        iVar4 = 0;

        piVar3 = (int *)(iVar1 + 0xd98);

        goto LAB_004beb10;

      }

      iVar4 = iVar4 + 1;

      piVar3 = piVar3 + 2;

    } while (iVar4 < 2);

    goto LAB_004beac3;

  }

  if (param_2 == 0x32) {

    iVar1 = *(int *)(param_1 + 0x100);

    iVar4 = 0;

    piVar3 = (int *)(iVar1 + 0xd9c);

    do {

      if ((piVar3[-1] == 0x48) && (0 < *piVar3)) {

        iVar4 = 0;

        piVar3 = (int *)(iVar1 + 0xd98);

        goto LAB_004bebf2;

      }

      iVar4 = iVar4 + 1;

      piVar3 = piVar3 + 2;

    } while (iVar4 < 2);

    goto LAB_004bebb4;

  }

  fVar6 = (float10)dirucalcp3d__FP3P3DT0(&local_60,param_3);

  fVar7 = (float10)dirfcalcp3d__FP3P3DT0(&local_60,param_3);

  local_44[0] = 0;

  GEO_MatBuildXYZ(local_44,-(float)fVar6,0,(float)fVar7);

  local_34 = local_60;

  local_14 = local_58;

  local_24 = local_5c;

  local_44[0] = local_44[0] | 0x10;

  iVar1 = PROJ_Create3(param_2,*(undefined4 *)(param_1 + 0x18c),param_1,0,local_44,param_4);

  switch(param_2) {

  case 0x24:

  case 0x25:

  case 0x27:

  case 0x33:

    uVar8 = 0x3ad;

    break;

  case 0x26:

    uVar8 = 0x6ee;

    break;

  default:

    goto switchD_004bed16_caseD_28;

  }

  sound_play_player(uVar8,param_1);

  goto switchD_004bed16_caseD_28;

  while( true ) {

    iVar4 = iVar4 + 1;

    piVar3 = piVar3 + 2;

    if (1 < iVar4) break;

LAB_004beb10:

    if (*piVar3 == 0x3f) {

      iVar5 = *(int *)(iVar1 + 0xd9c + iVar4 * 8) + -1;

      *(int *)(iVar1 + 0xd9c + iVar4 * 8) = iVar5;

      if (0 < iVar5) goto LAB_004bead4;

      iVar1 = *(int *)(param_1 + 0x100);

      iVar5 = iVar4;

      if (-1 < iVar4) goto LAB_004beb61;

      iVar2 = 0;

      piVar3 = (int *)(iVar1 + 0xd98);

      goto LAB_004beb48;

    }

  }

LAB_004beac3:

  iVar1 = fx_create(param_1);

  if (iVar1 != 0) {

    return;

  }

  goto LAB_004bead4;

  while( true ) {

    iVar2 = iVar2 + 1;

    piVar3 = piVar3 + 2;

    iVar5 = iVar4;

    if (1 < iVar2) break;

LAB_004beb48:

    iVar5 = iVar2;

    if (*piVar3 == 0x3f) break;

  }

  if (-1 < iVar5) {

LAB_004beb61:

    if (iVar5 < 2) {

      *(undefined4 *)(iVar1 + 0xd98 + iVar5 * 8) = 0xffffffff;

      *(undefined4 *)(iVar1 + 0xd9c + iVar5 * 8) = 0;

    }

  }

LAB_004bead4:

  iVar1 = PROJ_Create2(0x2c,*(undefined4 *)(param_1 + 0x18c),param_1,0,param_4,param_3);

  sound_play_player(0x3a1,param_1);

  goto switchD_004bed16_caseD_28;

  while( true ) {

    iVar4 = iVar4 + 1;

    piVar3 = piVar3 + 2;

    if (1 < iVar4) break;

LAB_004bebf2:

    if (*piVar3 == 0x48) {

      iVar5 = *(int *)(iVar1 + 0xd9c + iVar4 * 8) + -1;

      *(int *)(iVar1 + 0xd9c + iVar4 * 8) = iVar5;

      if (0 < iVar5) goto LAB_004bebc5;

      iVar1 = *(int *)(param_1 + 0x100);

      iVar5 = iVar4;

      if (-1 < iVar4) goto LAB_004bec45;

      iVar2 = 0;

      piVar3 = (int *)(iVar1 + 0xd98);

      goto LAB_004bec30;

    }

  }

LAB_004bebb4:

  iVar1 = fx_create(param_1);

  if (iVar1 != 0) {

    return;

  }

  goto LAB_004bebc5;

  while( true ) {

    iVar2 = iVar2 + 1;

    piVar3 = piVar3 + 2;

    iVar5 = iVar4;

    if (1 < iVar2) break;

LAB_004bec30:

    iVar5 = iVar2;

    if (*piVar3 == 0x48) break;

  }

  if (-1 < iVar5) {

LAB_004bec45:

    if (iVar5 < 2) {

      *(undefined4 *)(iVar1 + 0xd98 + iVar5 * 8) = 0xffffffff;

      *(undefined4 *)(iVar1 + 0xd9c + iVar5 * 8) = 0;

    }

  }

LAB_004bebc5:

  iVar1 = PROJ_Create2(0x32,*(undefined4 *)(param_1 + 0x18c),param_1,1,param_4,param_3);

switchD_004bed16_caseD_28:

  *(int *)(iVar1 + 0x274) = param_1;

  iVar4 = fx_create(param_1);

  if (iVar4 == 0) {

    *(undefined4 *)(iVar1 + 0x188) = param_5;

    return;

  }

  iVar4 = reaper_0052e4a0(param_1);

  if (iVar4 == 0) {

    return;

  }

  switch(param_2) {

  case 0x24:

    local_50 = param_3[1];

    local_54 = *param_3;

    local_4c = param_3[2];

    local_48 = *(undefined4 *)(iVar1 + 0x188);

    uVar8 = 0x2c;

    break;

  case 0x25:

    local_50 = param_3[1];

    uVar8 = 0x2e;

    goto LAB_004bee5d;

  case 0x26:

    local_50 = param_3[1];

    local_54 = *param_3;

    local_4c = param_3[2];

    local_48 = *(undefined4 *)(iVar1 + 0x188);

    uVar8 = 0x2b;

    break;

  case 0x27:

    local_50 = param_3[1];

    uVar8 = 0x2a;

    goto LAB_004bee5d;

  default:

    goto switchD_004bed83_caseD_28;

  case 0x2c:

    local_50 = param_3[1];

    uVar8 = 0x31;

LAB_004bee5d:

    local_54 = *param_3;

    local_4c = param_3[2];

    local_48 = *(undefined4 *)(iVar1 + 0x188);

    break;

  case 0x32:

    local_50 = param_3[1];

    local_54 = *param_3;

    local_4c = param_3[2];

    local_48 = *(undefined4 *)(iVar1 + 0x188);

    uVar8 = 0x34;

    break;

  case 0x33:

    local_50 = param_3[1];

    local_54 = *param_3;

    local_4c = param_3[2];

    local_48 = *(undefined4 *)(iVar1 + 0x188);

    uVar8 = 0x36;

  }

  reaper_00530bd0(param_1,3,1,0,uVar8,&local_54);

switchD_004bed83_caseD_28:

  return;

}

/* ===== reaper_fire_bow__FP6OBJECT @ 0x004BEEE0 ===== */
/* PS2 candidate: reaper_fire_bow__FP6OBJECT (conf 0.53) */



void reaper_fire_bow__FP6OBJECT(int param_1)



{

  uint *puVar1;

  float fVar2;

  int iVar3;

  undefined4 uVar4;

  undefined4 uVar5;

  uint uVar6;

  uint *puVar7;

  uint uVar8;

  uint *puVar9;

  float10 fVar10;

  int *local_160;

  uint local_15c;

  undefined4 local_158;

  undefined4 local_154;

  float local_150;

  undefined4 local_14c;

  undefined4 local_148;

  float local_144;

  uint local_140;

  uint local_13c;

  uint local_138;

  undefined4 local_124;

  undefined4 local_120;

  undefined4 local_11c;

  undefined1 local_100 [256];

  

  puVar9 = *(uint **)(param_1 + 0x100);

  iVar3 = fx_create(param_1);

  if (iVar3 == 0) {

    return;

  }

  if ((DAT_00632aec != '\0') && (1 < (int)puVar9[0x36d])) {

    uVar4 = TextGetPtr(s_InvChDropItem_0055a158);

    uVar5 = IconDefTextDescription(puVar9[puVar9[0x36d] * 2 + 0x35c]);

    crt_sprintf(local_100,uVar4,uVar5);

    chat_insert(local_100,1);

    iVar3 = *(int *)(param_1 + 0x100);

    item_drop_item(param_1,*(undefined4 *)(iVar3 + 0xd70 + *(int *)(iVar3 + 0xdb4) * 8),

                   *(undefined4 *)(iVar3 + 0xd74 + *(int *)(iVar3 + 0xdb4) * 8),

                   *(float *)(param_1 + 0x29c) * -30.0,*(float *)(param_1 + 0x2ac) * -30.0,

                   0x41700000,0x41f00000);

    reaper_set_bow(param_1,*(undefined4 *)(iVar3 + 0xd70 + *(int *)(iVar3 + 0xdb4) * 8),0xffffffff,0

                   ,1);

    *(uint *)(param_1 + 0x20c) = *(uint *)(param_1 + 0x20c) & 0xffffff3f;

    sound_play_player(0x337,param_1);

    return;

  }

  if ((*(uint *)(param_1 + 0x20c) & 0x2000000) == 0) {

    *puVar9 = *puVar9 & 0xfffffff7;

  }

  if ((puVar9[0x38b] != 0) || ((*puVar9 & 8) != 0)) {

    *(uint *)(param_1 + 0x20c) = *(uint *)(param_1 + 0x20c) & 0xfdfffeff;

  }

  if (puVar9[puVar9[0x36d] * 2 + 0x35d] == 0) {

    if ((*(uint *)(param_1 + 0x20c) & 0x100) != 0) {

      sound_play_player(0x5cc,param_1);

    }

    *(uint *)(param_1 + 0x20c) = *(uint *)(param_1 + 0x20c) & 0xfdffffff;

    puVar9[0x15] = 0;

  }

  uVar6 = puVar9[0x3d1];

  local_140 = puVar9[0x3f1];

  local_13c = puVar9[0x3f2];

  local_138 = puVar9[0x3f3];

  *(uint *)(param_1 + 0xdc) = *(uint *)(param_1 + 0xdc) & 0xffffffdf;

  iVar3 = *(int *)(*(int *)(param_1 + 0x100) + 0x5c);

  if ((0x30 < iVar3) && ((iVar3 < 0x38 || (iVar3 == 0x4c)))) {

    *(uint *)(param_1 + 0x20c) = *(uint *)(param_1 + 0x20c) & 0xfdfffeff;

    puVar7 = *(uint **)(param_1 + 0x100);

    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xffffff7f;

    if (puVar7[0x38e] != 0) {

      fx_delete(puVar7[0x38e]);

      puVar7[0x38e] = 0;

    }

    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xffffffbf;

    *puVar7 = *puVar7 & 0xfffffffe;

  }

  if ((*(uint *)(param_1 + 0x20c) & 0x2000000) != 0) {

    fVar10 = (float10)FRateGetSecsframe(param_1,0);

    puVar9[0x15] = *(uint *)(DAT_00632ed8 + 0x5c4);

    puVar9[0x16] = (uint)((float)puVar9[0x16] - (float)fVar10);

    uVar6 = *(uint *)(param_1 + 0xe0);

    if ((uVar6 & 0x40) == 0) {

      if ((uVar6 & 0x10) != 0) {

        return;

      }

      *(uint *)(param_1 + 0xe0) = uVar6 | 0x40;

      uVar6 = *(uint *)(DAT_00632ed8 + 0x8dc);

      puVar9[999] = 0;

      puVar9[0x3e6] = uVar6;

      puVar9[0x16] = *(uint *)(DAT_00632ed8 + 0x6b0);

      switch(*(undefined4 *)

              (*(int *)(param_1 + 0x100) + 0xd70 + *(int *)(*(int *)(param_1 + 0x100) + 0xdb4) * 8))

      {

      case 0x2c:

        uVar4 = 0x38c;

        break;

      case 0x2d:

        uVar4 = 0x38f;

        break;

      case 0x2e:

        uVar4 = 0x394;

        break;

      case 0x2f:

        uVar4 = 0x369;

        break;

      case 0x30:

        uVar4 = 0x388;

        break;

      default:

        uVar4 = 0;

      }

      sound_play_player(uVar4,param_1);

      iVar3 = reaper_0052e4a0(param_1);

      if (iVar3 == 0) {

        return;

      }

      reaper_00530bd0(param_1,0,0,0,0x24,0);

      return;

    }

    if (-1 < (char)uVar6) {

      iVar3 = reaper_0052e4a0(param_1);

      if (iVar3 != 0) {

        reaper_00530bd0(param_1,0,0,0,0x25,0);

      }

      switch(*(undefined4 *)

              (*(int *)(param_1 + 0x100) + 0xd70 + *(int *)(*(int *)(param_1 + 0x100) + 0xdb4) * 8))

      {

      case 0x2c:

        uVar4 = 0x38c;

        break;

      case 0x2d:

        uVar4 = 0x38f;

        break;

      case 0x2e:

        uVar4 = 0x394;

        break;

      case 0x2f:

        uVar4 = 0x369;

        break;

      case 0x30:

        uVar4 = 0x388;

        break;

      default:

        uVar4 = 0;

      }

      sound_play_player(uVar4,param_1);

      *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 0x80;

    }

    if ((puVar9[0x38e] == 0) && ((float)puVar9[0x16] < 0.0 != ((float)puVar9[0x16] == 0.0))) {

      local_11c = gun_find_right(param_1);

      local_120 = 0;

      local_124 = 8;

      uVar6 = fx_get_free_effect__Fv();

      puVar9[0x38e] = uVar6;

    }

    if (puVar9[puVar9[0x36d] * 2 + 0x35c] == 0x30) {

      fVar2 = (*(float *)(DAT_00632ed8 + 0x1544) / *(float *)(DAT_00632ed8 + 0x1548)) *

              (float)fVar10 + (float)puVar9[0x3e2];

      puVar9[0x3e2] = (uint)fVar2;

      if (*(float *)(DAT_00632ed8 + 0x1544) < fVar2) {

        puVar9[0x3e2] = *(uint *)(DAT_00632ed8 + 0x1544);

      }

      iVar3 = 0;

      if (0 < (int)puVar9[0x36b]) {

        puVar7 = puVar9 + 0x3dd;

        do {

          if (*puVar7 != 0) {

            puVar1 = (uint *)(*puVar7 + 0xd8);

            *puVar1 = *puVar1 | 0x40000000;

            *(uint *)(*puVar7 + 0xd8) = *(uint *)(*puVar7 + 0xd8) & 0xffbfffff;

            *(undefined4 *)(*puVar7 + 0x210) = 0;

          }

          iVar3 = iVar3 + 1;

          puVar7 = puVar7 + 1;

        } while (iVar3 < (int)puVar9[0x36b]);

      }

      puVar9[0x3d8] = 0;

      puVar9[0x3d9] = 0;

      puVar9[0x3da] = 0;

      puVar9[0x3db] = 0;

      puVar9[0x3dc] = 0;

      local_15c = 0;

      local_160 = DAT_00632d6c;

      if (DAT_00632d6c == (int *)0x0) {

        return;

      }

      puVar7 = puVar9 + 0x3dd;

      do {

        uVar6 = local_160[3];

        iVar3 = reaper_xhair_validate__FP6OBJECTPv(uVar6,param_1);

        if ((iVar3 != 0) &&

           ((((((iVar3 = ObjIsPlayer(uVar6), iVar3 != 0 ||

                (iVar3 = *(int *)(uVar6 + 4), iVar3 == 0x29a)) || (iVar3 == 8)) ||

              ((iVar3 == 0x438 || (iVar3 == 0xd7)))) ||

             ((iVar3 = ObjIsRipper(uVar6), iVar3 != 0 ||

              ((*(int *)(uVar6 + 4) == 0x23f || (*(int *)(uVar6 + 4) == 0x2e9)))))) &&

            (iVar3 = in_fov(param_1,uVar6,puVar9[0x3e2]), iVar3 != 0)))) {

          local_158 = *(undefined4 *)(param_1 + 0xa0);

          local_154 = *(undefined4 *)(param_1 + 0xa4);

          local_150 = *(float *)(param_1 + 0xa8) + *(float *)(param_1 + 0x1e8);

          local_14c = *(undefined4 *)(uVar6 + 0xa0);

          local_148 = *(undefined4 *)(uVar6 + 0xa4);

          local_144 = *(float *)(uVar6 + 0xa8) + *(float *)(uVar6 + 0x1e8);

          iVar3 = line_of_sight_grid(&local_158,&local_14c);

          if (iVar3 != 0) {

            puVar7[-5] = uVar6;

            if (*puVar7 == 0) {

              uVar8 = object_allocate_type(0x3d4,0);

              *puVar7 = uVar8;

            }

            *(uint *)(*puVar7 + 0xd8) = *(uint *)(*puVar7 + 0xd8) & 0xbfffffff;

            *(uint *)(*puVar7 + 0xd8) = *(uint *)(*puVar7 + 0xd8) | 0x10000;

            GEO_MatIdentity(*puVar7 + 0x294);

            SphereFitToObject(*puVar7 + 0x294,uVar6,0x40000000);

            local_15c = local_15c + 1;

            puVar7 = puVar7 + 1;

            if (local_15c == puVar9[0x36b]) {

              return;

            }

          }

        }

        local_160 = (int *)*local_160;

        if (local_160 == (int *)0x0) {

          return;

        }

      } while( true );

    }

    if (puVar9[puVar9[0x36d] * 2 + 0x35c] != 0x2f) {

      return;

    }

    if (puVar9[0x3e3] == 0) {

      sound_stop_player(0x36c,param_1);

      puVar9[0x3fd] = 0;

      if (puVar9[0x3e4] != 0) {

        puVar7 = (uint *)(puVar9[0x3e4] + 0xd8);

        *puVar7 = *puVar7 | 0x40000000;

      }

    }

    else {

      if (puVar9[0x3fd] == 0) {

        sound_play_player(0x36c,param_1);

        puVar9[0x3fd] = 1;

      }

      if (puVar9[0x3e4] == 0) {

        uVar6 = object_allocate_type(0x3d4,0);

        puVar9[0x3e4] = uVar6;

      }

      *(uint *)(puVar9[0x3e4] + 0xd8) = *(uint *)(puVar9[0x3e4] + 0xd8) & 0xbfffffff;

      *(uint *)(puVar9[0x3e4] + 0xd8) = *(uint *)(puVar9[0x3e4] + 0xd8) | 0x10000;

      GEO_MatIdentity(puVar9[0x3e4] + 0x294);

      SphereFitToObject(puVar9[0x3e4] + 0x294,puVar9[0x3e3],0x40000000);

    }

    if ((float)puVar9[0x3e6] <= 0.0) {

      puVar9[999] = 1;

      iVar3 = in_fov(param_1,puVar9[0x3e3],*(undefined4 *)(DAT_00632ed8 + 0x8e0));

      if (iVar3 != 0) {

        return;

      }

      sound_stop_player(0x36c,param_1);

      puVar9[0x3fd] = 0;

      puVar9[0x3e3] = 0;

      uVar6 = *(uint *)(DAT_00632ed8 + 0x8dc);

      puVar9[999] = 0;

      puVar9[0x3e6] = uVar6;

      *(uint *)(puVar9[0x3e4] + 0xd8) = *(uint *)(puVar9[0x3e4] + 0xd8) | 0x40000000;

      return;

    }

    if (puVar9[0x3e3] != 0) {

      fVar10 = (float10)FRateGetSecsframe(param_1,0);

      puVar9[0x3e6] = (uint)(float)((float10)(float)puVar9[0x3e6] - fVar10);

      return;

    }

    puVar9[0x3e6] = *(uint *)(DAT_00632ed8 + 0x8dc);

    puVar9[999] = 0;

    return;

  }

  if ((*(char *)(param_1 + 0xe0) < '\0') &&

     ((float)puVar9[0x16] < 0.0 != ((float)puVar9[0x16] == 0.0))) {

    make_arrow__FP6OBJECTT0P3P3DPUii(param_1,uVar6,&local_140,0,puVar9[puVar9[0x36d] * 2 + 0x35c]);

    puVar9[0x16] = *(uint *)(DAT_00632ed8 + 0x6b0);

    return;

  }

  if (puVar9[0x3e4] != 0) {

    sound_stop_player(0x36c,param_1);

    puVar9[0x3fd] = 0;

    *(uint *)(puVar9[0x3e4] + 0xd8) = *(uint *)(puVar9[0x3e4] + 0xd8) | 0x40000000;

  }

  puVar9[0x3e6] = *(uint *)(DAT_00632ed8 + 0x8dc);

  puVar9[999] = 0;

  uVar6 = *(uint *)(DAT_00632ed8 + 0x6b0);

  puVar9[0x3e2] = 0;

  puVar9[0x16] = uVar6;

  if ((*puVar9 & 1) == 0) {

    if ((*(byte *)(param_1 + 0xe0) & 0x40) == 0) {

      return;

    }

    switch(*(undefined4 *)

            (*(int *)(param_1 + 0x100) + 0xd70 + *(int *)(*(int *)(param_1 + 0x100) + 0xdb4) * 8)) {

    case 0x2c:

      uVar4 = 0x38c;

      break;

    case 0x2d:

      uVar4 = 0x38f;

      break;

    case 0x2e:

      uVar4 = 0x394;

      break;

    case 0x2f:

      uVar4 = 0x369;

      break;

    case 0x30:

      uVar4 = 0x388;

      break;

    default:

      uVar4 = 0;

    }

    sound_stop_player(uVar4,param_1);

    puVar9 = *(uint **)(param_1 + 0x100);

    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xffffff7f;

    if (puVar9[0x38e] != 0) {

      fx_delete(puVar9[0x38e]);

      puVar9[0x38e] = 0;

    }

  }

  else {

    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xffffff7f;

    fVar10 = (float10)FRateGetSecsframe(param_1,0);

    fVar10 = (float10)(float)puVar9[0x15] - fVar10;

    puVar9[0x15] = (uint)(float)fVar10;

    if (fVar10 < (float10)0.0 == (fVar10 == (float10)0.0)) {

      iVar3 = reaper_0052e4a0(param_1);

      if (iVar3 == 0) {

        return;

      }

      uVar4 = 0x28;

      goto LAB_004bf85c;

    }

  }

  *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xffffffbf;

  *puVar9 = *puVar9 & 0xfffffffe;

  iVar3 = reaper_0052e4a0(param_1);

  if (iVar3 == 0) {

    return;

  }

  uVar4 = 0x26;

LAB_004bf85c:

  reaper_00530bd0(param_1,0,0,0,uVar4,0);

  return;

}

/* ===== fxb_firewall_create @ 0x004BF8C0 ===== */
void fxb_firewall_create(int param_1,int *param_2,int *param_3,uint param_4,undefined4 param_5)



{

  int iVar1;

  int *piVar2;

  int *piVar3;

  int iVar4;

  int iVar5;

  char *pcVar6;

  undefined4 uVar7;

  undefined1 *puVar8;

  undefined4 local_4c;

  undefined4 local_48;

  undefined4 local_44;

  undefined1 local_40 [12];

  undefined1 local_34 [20];

  undefined4 local_20;

  int local_1c;

  

  piVar2 = param_2;

  if (*param_2 == 0) {

    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & ~param_4;

    return;

  }

  iVar4 = object_allocate_type(0x374,0);

  object_change_ospec(iVar4,0x56);

  iVar1 = param_1;

  *(undefined4 *)(iVar4 + 0x18c) = *(undefined4 *)(param_1 + 0x18c);

  *(int *)(iVar4 + 0x274) = param_1;

  iVar5 = fx_create(param_1);

  piVar3 = param_3;

  if (iVar5 == 0) {

    *(undefined4 *)(iVar4 + 0x188) = param_5;

  }

  iVar5 = *param_3 * 0x44 + *(int *)(*piVar2 + 0x2dc);

  local_4c = *(undefined4 *)(iVar5 + 0x10);

  local_48 = *(undefined4 *)(iVar5 + 0x20);

  local_44 = *(undefined4 *)(iVar5 + 0x30);

  xformobj_p3d_world(*piVar2,&local_4c,local_40);

  object_set_location_p3d(iVar4,local_40);

  *(undefined4 *)(iVar4 + 200) = *(undefined4 *)(*piVar2 + 200);

  *(undefined4 *)(iVar4 + 0xec) = *(undefined4 *)(*piVar2 + 0xec);

  *(undefined4 *)(iVar4 + 0xf4) = *(undefined4 *)(*piVar2 + 0xf4);

  *(undefined4 *)(iVar4 + 0xf8) = *(undefined4 *)(*piVar2 + 0xf8);

  puVar8 = local_34;

  *(undefined4 *)(iVar4 + 0xfc) = *(undefined4 *)(*piVar2 + 0xfc);

  uVar7 = 4;

  pcVar6 = s_FXB_firewall_00561018;

  local_20 = 0;

  local_1c = iVar4;

  fx_get_free_effect__Fv();

  iVar5 = reaper_0052e4a0(iVar1,pcVar6,uVar7,puVar8);

  if (iVar5 != 0) {

    param_1 = *(int *)(iVar4 + 0x188);

    reaper_00530bd0(iVar1,0,1,0,0x1c,&param_1);

  }

  iVar4 = *piVar3 + 1;

  *piVar3 = iVar4;

  if (iVar4 == *(int *)(DAT_00632ed8 + 0x780)) {

    object_destroy(*piVar2);

    *piVar2 = 0;

    *(uint *)(iVar1 + 0xe0) = *(uint *)(iVar1 + 0xe0) & ~param_4;

  }

  return;

}

/* ===== reaper_cast_firewall @ 0x004BFA50 ===== */
void reaper_cast_firewall

               (int param_1,int *param_2,undefined4 *param_3,undefined4 *param_4,undefined4 *param_5

               ,undefined4 param_6,undefined4 *param_7,uint param_8,undefined4 param_9)



{

  int iVar1;

  undefined4 local_20;

  undefined4 local_1c;

  undefined4 local_18;

  undefined4 local_14;

  undefined4 local_10;

  undefined4 local_c;

  undefined4 local_8;

  undefined4 local_4;

  

  *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | param_8;

  *param_4 = 0;

  iVar1 = object_allocate_type(0x378,0);

  *param_2 = iVar1;

  *(undefined4 *)(iVar1 + 0x18c) = *(undefined4 *)(param_1 + 0x18c);

  *(int *)(*param_2 + 0x274) = param_1;

  iVar1 = fx_create(param_1);

  if (iVar1 == 0) {

    *(undefined4 *)(*param_2 + 0x188) = param_9;

  }

  object_change_ospec(*param_2,0x56);

  object_set_location_p3d(*param_2,param_3);

  *(undefined4 *)(*param_2 + 200) = param_6;

  *(undefined4 *)(*param_2 + 0xec) = *(undefined4 *)(DAT_00632ed8 + 0x79c);

  *(undefined4 *)(*param_2 + 0xf4) = *param_7;

  *(undefined4 *)(*param_2 + 0xf8) = param_7[1];

  *(undefined4 *)(*param_2 + 0xfc) = param_7[2];

  *(undefined4 *)(*param_2 + 0xe0) = 1;

  *param_5 = *(undefined4 *)(DAT_00632ed8 + 0x784);

  iVar1 = fx_create(param_1);

  if (iVar1 != 0) {

    iVar1 = reaper_0052e4a0(param_1);

    if (iVar1 != 0) {

      local_20 = *param_3;

      local_1c = param_3[1];

      local_18 = param_3[2];

      local_14 = *param_7;

      local_8 = param_6;

      local_10 = param_7[1];

      local_c = param_7[2];

      local_4 = *(undefined4 *)(*param_2 + 0x188);

      reaper_00530bd0(param_1,7,1,0,0x1d,&local_20);

    }

    fxb_firewall_create(param_1,param_2,param_4,param_8,0xffffffff);

  }

  sound_get_free_sequence__Fv();

  return;

}

/* ===== fxb_cloak_create @ 0x004BFBF0 ===== */
/* PS2 candidate: reaper_finish_cloak (conf 0.397) */



void fxb_cloak_create(int param_1)



{

  int iVar1;

  undefined4 uVar2;

  int iVar3;

  

  iVar1 = *(int *)(param_1 + 0x100);

  *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0x7fffffff;

  if (*(int *)(iVar1 + 0xe34) == 0) {

    uVar2 = fx_get_free_effect__Fv();

    *(undefined4 *)(iVar1 + 0xe34) = uVar2;

  }

  *(undefined4 *)(iVar1 + 0xe2c) = 1;

  *(undefined4 *)(iVar1 + 0xe30) = *(undefined4 *)(DAT_00632ed8 + 0x778);

  *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) | 0x40000000;

  iVar3 = gun_find_right(param_1);

  *(uint *)(iVar3 + 0xd8) = *(uint *)(iVar3 + 0xd8) | 0x40000000;

  uVar2 = sound_get_free_sequence__Fv();

  *(undefined4 *)(iVar1 + 0xff0) = uVar2;

  return;

}

/* ===== reaper_finish_shrinker @ 0x004BFCC0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void reaper_finish_shrinker(undefined4 param_1,int param_2,int param_3,int param_4)



{

  int *piVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  char cVar5;

  int iVar6;

  char *pcVar7;

  int iVar8;

  char *pcVar9;

  

  iVar8 = param_2;

  if ((param_2 != 0) && ((*(uint *)(param_2 + 0x1c8) & 0x400000) != 0)) {

    iVar6 = ObjIsJetski(param_2);

    if (iVar6 == 0) {

      iVar6 = ObjIsJetski(*(undefined4 *)(iVar8 + 0x210));

      if (iVar6 == 0) {

        sound_play_player(0x3bb,iVar8);

        if (iVar8 == DAT_00632a88) {

          pcVar7 = (char *)TextGetPtr(s_SpellHintShrink_00561034);

          pcVar9 = &DAT_00632c10;

          do {

            cVar5 = *pcVar7;

            pcVar7 = pcVar7 + 1;

            *pcVar9 = cVar5;

            pcVar9 = pcVar9 + 1;

          } while (cVar5 != '\0');

          _DAT_00632d10 = 0x40800000;

        }

        piVar1 = (int *)(param_4 * 0x1c + param_3);

        piVar1[1] = *(int *)(DAT_00632ed8 + 0x768);

        piVar1[3] = (int)(*(float *)(DAT_00632ed8 + 0x76c) * *(float *)(iVar8 + 0xc4));

        fVar2 = *(float *)(iVar8 + 0x1c0);

        fVar3 = *(float *)(iVar8 + 0x278);

        fVar4 = *(float *)(DAT_00632ed8 + 0x770);

        piVar1[4] = 0;

        piVar1[5] = 0;

        piVar1[2] = (int)((fVar2 - fVar3) * fVar4);

        *piVar1 = iVar8;

        piVar1[6] = 0;

        obj_shot_expire_destroy(0xe,piVar1[2],iVar8,param_1,0,0);

        iVar6 = fx_create(param_1);

        if (iVar6 != 0) {

          iVar6 = reaper_0052e4a0(param_1);

          if (iVar6 != 0) {

            param_2 = *(int *)(iVar8 + 0x188);

            reaper_00530bd0(param_1,0,1,0,0x2d,&param_2);

          }

        }

        iVar8 = *piVar1;

        if (*(int *)(iVar8 + 4) == 8) {

          *(int *)(*(int *)(iVar8 + 0x100) + 0x60) = *(int *)(*(int *)(iVar8 + 0x100) + 0x60) + 1;

          return;

        }

        if (*(int *)(iVar8 + 4) == 0xb) {

          *(int *)(*(int *)(iVar8 + 0x100) + 0x4c) = *(int *)(*(int *)(iVar8 + 0x100) + 0x4c) + 1;

          return;

        }

        iVar8 = ObjIsKabuto(iVar8);

        if (iVar8 != 0) {

          piVar1 = (int *)(*(int *)(*piVar1 + 0x100) + 0x354);

          *piVar1 = *piVar1 + 1;

        }

      }

    }

  }

  return;

}

/* ===== reaper_finish_hail__FP6OBJECT @ 0x004BFE50 ===== */
/* PS2 candidate: reaper_finish_hail__FP6OBJECT (conf 0.335) */



void reaper_finish_hail__FP6OBJECT(int param_1)



{

  uint *puVar1;

  undefined4 uVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  undefined4 *puVar7;

  undefined4 *puVar8;

  undefined4 *local_68;

  undefined4 local_60 [15];

  undefined4 local_24;

  undefined4 local_20;

  undefined4 local_1c;

  undefined4 local_18;

  undefined4 auStack_14 [5];

  

  iVar3 = param_1;

  iVar6 = *(int *)(param_1 + 0x100);

  param_1 = 0;

  if (0.0 < *(float *)(DAT_00632ed8 + 0x7c4)) {

    local_68 = (undefined4 *)(iVar6 + 0xefc);

    puVar7 = (undefined4 *)(iVar6 + 0xeb0);

    do {

      if (param_1 < *(int *)(iVar6 + 0xea8)) {

        iVar4 = PROJ_CreateBasic(0xf,*(undefined4 *)(iVar3 + 0x18c));

        puVar1 = (uint *)(iVar4 + 0x294);

        GEO_MatIdentity(puVar1);

        *(undefined4 *)(iVar4 + 0x2a4) = puVar7[-1];

        uVar2 = *puVar7;

        *puVar1 = *puVar1 | 0x10;

        *(undefined4 *)(iVar4 + 0x2b4) = uVar2;

        *(undefined4 *)(iVar4 + 0x2c4) = 0x43610000;

        object_set_location(iVar4,*(undefined4 *)(iVar4 + 0x2a4),uVar2,0x43610000);

        *(int *)(iVar4 + 0x274) = iVar3;

        iVar5 = fx_create(iVar3);

        if (iVar5 == 0) {

          *(undefined4 *)(iVar4 + 0x188) = local_68[-5];

        }

        else {

          auStack_14[param_1] = *(undefined4 *)(iVar4 + 0x188);

        }

      }

      fx_delete(*local_68);

      param_1 = param_1 + 1;

      *local_68 = 0;

      local_68 = local_68 + 1;

      puVar7 = puVar7 + 3;

    } while ((float)param_1 < *(float *)(DAT_00632ed8 + 0x7c4));

  }

  if (((0 < *(int *)(iVar6 + 0xea8)) && (iVar6 = fx_create(iVar3), iVar6 != 0)) &&

     (iVar6 = reaper_0052e4a0(iVar3), iVar6 != 0)) {

    iVar6 = *(int *)(iVar3 + 0x100);

    local_24 = *(undefined4 *)(iVar6 + 0xf10);

    local_20 = *(undefined4 *)(iVar6 + 0xf14);

    local_1c = *(undefined4 *)(iVar6 + 0xf18);

    local_18 = *(undefined4 *)(iVar6 + 0xea8);

    puVar7 = (undefined4 *)(iVar6 + 0xeac);

    puVar8 = local_60;

    for (iVar4 = 0xf; iVar4 != 0; iVar4 = iVar4 + -1) {

      *puVar8 = *puVar7;

      puVar7 = puVar7 + 1;

      puVar8 = puVar8 + 1;

    }

    reaper_00530bd0(iVar3,0x12,0x10,0,0x17,local_60);

    DAT_00632bc4 = 0;

    return;

  }

  DAT_00632bc4 = 0;

  return;

}

