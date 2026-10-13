/* Giants 1.449 — module _unmapped_004b
 * 90 functions (25 named) — decompiled, names from PS2 symbols
 * Original source: C:\Giants\source\_unmapped_004b.c(pp) (assert-string evidence)
 */

/* ===== FUN_004B0900 @ 0x004B0900 ===== */
bool FUN_004B0900(int param_1,undefined4 param_2,int param_3)



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

/* ===== FUN_004B09C0 @ 0x004B09C0 ===== */
/* PS2 candidate: world_get_pointer (conf 0.691) */



int * FUN_004B09C0(int param_1)



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

/* ===== FUN_004b0a00 @ 0x004B0A00 ===== */
/* PS2 candidate: world_get_id (conf 0.529) */



undefined4 FUN_004b0a00(undefined4 param_1)



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

/* ===== FUN_004b0a60 @ 0x004B0A60 ===== */
int FUN_004b0a60(int param_1)



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

      FUN_00542f27(local_40,&DAT_0055bfe4,(DAT_00632d28 + iVar1 * 0x1439)[1]);

      pcVar2 = (char *)FUN_00507b00(local_40);

      if (pcVar2 == local_40) {

        pcVar2 = pcVar2 + 2;

      }

      return pcVar2;

    }

  }

  return s__null__00560278;

}

/* ===== FUN_004B0B40 @ 0x004B0B40 ===== */
/* PS2 candidate: InitFxDict__Fv (conf 0.55) */



void FUN_004B0B40(void)



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

  _DAT_005a6c28 = FUN_0051ad50(&LAB_004b0e00);

  if (_DAT_005a6c28 == 0) {

    FUN_00425eb0(s_Failed_to_load_world_read_task__00560310);

    _DAT_005a6c24 = 0x3f800000;

    FUN_00542f27(local_100,s_W__s_bin_0055c160,*(undefined4 *)(DAT_006330e4 + 4));

    bin_load_1a0002e5(local_100,0x3f800000,0);

    _DAT_005a6c24 = 0;

  }

  return;

}

/* ===== main/readwrls_004b0e50 @ 0x004B0E50 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



float10 main_readwrls_004b0e50(void)



{

  return (float10)_DAT_005a6c24;

}

/* ===== main/readwrls_004b0e60 @ 0x004B0E60 ===== */
/* PS2 candidate: tracer_draw_mecc_balls (conf 0.853) */



void main_readwrls_004b0e60(undefined4 param_1)



{

  undefined1 local_100 [256];

  

  FUN_00542f27(local_100,s_W__s_bin_0055c160,param_1);

  bin_load_1a0002e5(local_100,0x3f800000,0);

  return;

}

/* ===== main/readwrls_004b0ea0 @ 0x004B0EA0 ===== */
/* PS2 candidate: setup_sun_flares__Fv (conf 0.771) */



void main_readwrls_004b0ea0(void)



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

/* ===== FUN_004b4450 @ 0x004B4450 ===== */
/* PS2 candidate: rpboat_lock_to_boat__FP6OBJECTT0 (conf 0.525) */



void FUN_004b4450(void)



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

        uVar5 = FUN_0049a180(*(undefined4 *)(iVar1 + 0x1e0),(double)*(float *)(iVar1 + 0xa0),

                             (double)*(float *)(iVar1 + 0xa4),(double)*(float *)(iVar1 + 0xa8));

        FUN_00542f27(auStack_88,s_Object_type__d__movetype__s__is_o_00560628,

                     *(undefined4 *)(iVar1 + 4),uVar5);

        FUN_0051ea20(auStack_88);

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

/* ===== FUN_004b4570 @ 0x004B4570 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* PS2 candidate: reaperbase_init (conf 0.413) */



void FUN_004b4570(int param_1)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  undefined4 *puVar4;

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

    FUN_0051ea20(s_Obsolete_Base_placement_detected_00554e10);

    return;

  }

  iVar2 = object_allocate_type(*piVar1,0);

  if (iVar2 != 0) {

    local_c = *(float *)(param_1 + 0xa0) - (float)piVar1[4];

    local_8 = *(float *)(param_1 + 0xa4) - (float)piVar1[5];

    local_4 = *(float *)(param_1 + 0xa8) - (float)piVar1[6];

    FUN_004993c0(iVar2,&local_c);

    *(float *)(iVar2 + 200) = *(float *)(param_1 + 200) - (float)piVar1[7];

    FUN_004a7440(iVar2);

    FUN_004034a0(iVar2,1,0x20,0,0,0);

    FUN_00403e60(iVar2,0x3d4ccccd);

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

        FUN_004186c0(iVar2,*piVar6,pfVar5,pfVar5 + 3);

        if ((piVar6 == (int *)&DAT_00560a30) || (piVar6 == (int *)&DAT_00560770)) {

          sine_cos_lookup(pfVar5[3],&local_14,&local_10);

          *pfVar5 = local_14 * 70.0 + *pfVar5;

          pfVar5[1] = pfVar5[1] - local_10 * 70.0;

        }

      }

      piVar6 = piVar6 + 0x16;

      pfVar5 = pfVar5 + 7;

    } while ((int)piVar6 < 0x560c40);

    iVar3 = object_allocate_type(0x35a,0);

    FUN_004186c0(iVar2,0,&local_c,&local_18);

    FUN_004993c0(iVar3,&local_c);

    *(undefined4 *)(iVar3 + 200) = local_18;

    *(uint *)(iVar3 + 0xd8) = *(uint *)(iVar3 + 0xd8) | 0x10;

    iVar3 = object_allocate_type(0x353,0);

    FUN_004186c0(iVar2,0xe,&local_c,&local_18);

    FUN_004993c0(iVar3,&local_c);

    *(undefined4 *)(iVar3 + 200) = local_18;

    *(uint *)(iVar3 + 0xd8) = *(uint *)(iVar3 + 0xd8) | 0x10;

    iVar3 = object_allocate_type(0x353,0);

    FUN_004186c0(iVar2,0xf,&local_c,&local_18);

    FUN_004993c0(iVar3,&local_c);

    *(uint *)(iVar3 + 0xd8) = *(uint *)(iVar3 + 0xd8) | 0x10;

    *(undefined4 *)(iVar3 + 200) = local_18;

    FUN_00418630(iVar2,0x13,piVar1 + 0x171);

    FUN_00418630(iVar2,0x14,piVar1 + 0x174);

    FUN_00497510(iVar2);

    piVar6 = piVar1 + 0xdc;

    iVar2 = 5;

    do {

      iVar3 = 0xc;

      do {

        *piVar6 = 0;

        piVar6[1] = 0;

        piVar6 = piVar6 + 2;

        iVar3 = iVar3 + -1;

      } while (iVar3 != 0);

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

    puVar4 = &DAT_005606bc;

    piVar6 = piVar1 + 0xd;

    do {

      *piVar6 = 0;

      *puVar4 = 0x43480000;

      puVar4 = puVar4 + 0x16;

      piVar6 = piVar6 + 7;

    } while ((int)puVar4 < 0x560c3c);

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

    FUN_00418010(param_1,*(undefined4 *)(DAT_00632ed8 + 0x15a4));

  }

  return;

}

/* ===== FUN_004b4ca0 @ 0x004B4CA0 ===== */
/* PS2 candidate: reaperbasebldg_move (conf 0.591) */



void FUN_004b4ca0(float param_1)



{

  float *pfVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int *piVar5;

  float10 fVar6;

  float10 fVar7;

  

  iVar3 = (int)param_1;

  iVar4 = *(int *)((int)param_1 + 0x274);

  pfVar1 = *(float **)((int)param_1 + 0x100);

  if (iVar4 == 0) {

    return;

  }

  if (**(int **)(iVar4 + 0x100) == 0) {

    return;

  }

  if (*(int *)((int)param_1 + 0x18c) == 0) {

    *(undefined4 *)((int)param_1 + 0x18c) = *(undefined4 *)(iVar4 + 0x18c);

  }

  iVar2 = FUN_0052e480(param_1);

  if (iVar2 == 0) {

    if ((*(uint *)((int)param_1 + 0xe0) & 0x2000) != 0) {

      iVar4 = *(int *)((int)param_1 + 0x100);

      fVar6 = (float10)FUN_00518b70(0,0);

      fVar6 = (float10)*(float *)(iVar4 + 0x14) - fVar6;

      *(float *)(iVar4 + 0x14) = (float)fVar6;

      if (fVar6 < (float10)0.0 != (fVar6 == (float10)0.0)) {

        collgrid_query_obj(param_1,1);

      }

    }

    switch(*(undefined4 *)((int)param_1 + 0xe4)) {

    case 1:

    case 2:

      goto switchD_004b4d3a_caseD_1;

    case 3:

    case 0xd:

      *(undefined4 *)((int)param_1 + 0x184) = 0;

      fVar6 = (float10)FUN_00417f20(param_1);

      fVar7 = (float10)FUN_00418170(param_1);

      fVar7 = (float10)(float)fVar6 / fVar7;

      *(uint *)((int)param_1 + 0x30) = *(uint *)((int)param_1 + 0x30) | 0x80;

      if (((float10)0.75 <= fVar7) && (fVar7 < (float10)0.99)) {

        fVar7 = (float10)0.75;

      }

      *(float *)((int)param_1 + 0x14) = (float)fVar7;

      return;

    case 4:

      if (*(int *)((int)param_1 + 0x10) != 1) {

        return;

      }

      fVar6 = (float10)FUN_00417f20(param_1);

      fVar7 = (float10)FUN_00418170(param_1);

      fVar7 = (float10)(float)fVar6 / fVar7;

      *(uint *)((int)param_1 + 0x30) = *(uint *)((int)param_1 + 0x30) | 0x80;

      if (fVar7 < (float10)0.0 != (fVar7 == (float10)0.0)) {

        *(undefined4 *)((int)param_1 + 0x14) = 0;

        return;

      }

      fVar7 = fVar7 - (float10)0.01;

      fVar6 = (float10)*(float *)(DAT_00632ed8 + 0xb7c) * (float10)0.01;

      if (fVar7 < fVar6 != (fVar7 == fVar6)) {

        *(float *)((int)param_1 + 0x14) = (float)fVar6;

        return;

      }

      fVar6 = (float10)*(float *)(DAT_00632ed8 + 0xb78) * (float10)0.01;

      if (fVar7 < fVar6 == (fVar7 == fVar6)) {

        fVar6 = (float10)*(float *)(DAT_00632ed8 + 0xb74) * (float10)0.01;

        if (fVar7 < fVar6 == (fVar7 == fVar6)) {

          *(undefined4 *)((int)param_1 + 0x14) = 0x3f800000;

          return;

        }

        *(float *)((int)param_1 + 0x14) = (float)fVar6;

        return;

      }

      *(float *)((int)param_1 + 0x14) = (float)fVar6;

      return;

    case 5:

      goto switchD_004b4d3a_caseD_5;

    default:

      return;

    case 7:

      goto switchD_004b4d3a_caseD_7;

    case 9:

      fVar6 = (float10)FUN_00417f20(param_1);

      fVar6 = fVar6 / (float10)*(float *)(DAT_00632ed8 + 0x894);

      *(uint *)((int)param_1 + 0x30) = *(uint *)((int)param_1 + 0x30) | 0x80;

      if (((float10)0.75 <= fVar6) && (fVar6 < (float10)0.99)) {

        fVar6 = (float10)0.75;

      }

      *(float *)((int)param_1 + 0x14) = (float)fVar6;

      if ((*(uint *)((int)param_1 + 0xe0) & 0x1000) == 0) {

        return;

      }

      if (*(int *)((int)param_1 + 0x18c) == *(int *)(DAT_00632a88 + 0x18c)) {

        return;

      }

      fVar6 = (float10)FUN_0050a580(DAT_00632a88 + 0xa0,(int)param_1 + 0xa0);

      fVar6 = (fVar6 - (float10)*(float *)(DAT_00632ed8 + 0x1210)) /

              ((float10)*(float *)(DAT_00632ed8 + 0x1214) -

              (float10)*(float *)(DAT_00632ed8 + 0x1210));

      *(float *)((int)param_1 + 0x184) = (float)fVar6;

      if ((float10)1.0 < fVar6) {

        *(undefined4 *)((int)param_1 + 0x184) = 0x3f800000;

      }

      if (0.0 <= *(float *)((int)param_1 + 0x184)) {

        return;

      }

      *(undefined4 *)((int)param_1 + 0x184) = 0;

      return;

    }

  }

  switch(*(undefined4 *)((int)param_1 + 0xe4)) {

  case 2:

    fVar6 = (float10)FUN_00417f20(param_1);

    if ((float10)0.0 < fVar6) {

      if (*(int *)((int)param_1 + 0x274) != 0) {

        iVar3 = 0;

        piVar5 = (int *)(*(int *)(*(int *)((int)param_1 + 0x274) + 0x100) + 0x20);

        do {

          if ((float)*piVar5 == param_1) goto LAB_004b4fe5;

          iVar3 = iVar3 + 1;

          piVar5 = piVar5 + 7;

        } while (iVar3 < 0x10);

      }

      iVar3 = -1;

LAB_004b4fe5:

      FUN_004b54c0(iVar4,param_1,iVar3);

      iVar2 = reaper_0052e4a0(param_1);

      if (iVar2 != 0) {

        reaper_state_check_b(iVar4,param_1,iVar3);

      }

      fx_create_hack_logic(param_1);

      return;

    }

  case 1:

switchD_004b4d3a_caseD_1:

    if (DAT_00632bb0 == 0) {

      *(undefined4 *)((int)param_1 + 0x184) = 0x3f800000;

      return;

    }

    FUN_00418c80(param_1);

    return;

  case 3:

  case 0xd:

    *(undefined4 *)((int)param_1 + 0x184) = 0;

    iVar4 = FUN_004a6290(param_1);

    if (iVar4 == 0) {

      if (*(int *)((int)param_1 + 0x274) != 0) {

        iVar4 = 0;

        piVar5 = (int *)(*(int *)(*(int *)((int)param_1 + 0x274) + 0x100) + 0x20);

        do {

          if ((float)*piVar5 == param_1) {

            if (-1 < iVar4) {

              param_1 = (float)(&DAT_005606bc)[iVar4 * 0x16];

              goto LAB_004b5098;

            }

            break;

          }

          iVar4 = iVar4 + 1;

          piVar5 = piVar5 + 7;

        } while (iVar4 < 0x10);

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

LAB_004b5098:

    fVar6 = (float10)FUN_00417f20(iVar3);

    fVar6 = fVar6 / (float10)param_1;

    *(uint *)(iVar3 + 0x30) = *(uint *)(iVar3 + 0x30) | 0x80;

    if (((float10)0.75 <= fVar6) && (fVar6 < (float10)0.99)) {

      fVar6 = (float10)0.75;

    }

    *(float *)(iVar3 + 0x14) = (float)fVar6;

    iVar4 = FUN_004a6290(iVar3);

    if (iVar4 == 0) {

      if (*(int *)(iVar3 + 0x274) != 0) {

        iVar4 = 0;

        piVar5 = (int *)(*(int *)(*(int *)(iVar3 + 0x274) + 0x100) + 0x20);

        do {

          if (*piVar5 == iVar3) {

            if (-1 < iVar4) {

              param_1 = (float)(&DAT_005606bc)[iVar4 * 0x16];

              goto LAB_004b5148;

            }

            break;

          }

          iVar4 = iVar4 + 1;

          piVar5 = piVar5 + 7;

        } while (iVar4 < 0x10);

      }

      if ((*(int *)(iVar3 + 0xe4) < 9) || (0xc < *(int *)(iVar3 + 0xe4))) {

        param_1 = 100.0;

      }

      else {

        param_1 = *(float *)(DAT_00632ed8 + 0x894);

      }

    }

    else {

      param_1 = *(float *)(DAT_00632ed8 + 0x628);

    }

LAB_004b5148:

    fVar6 = (float10)FUN_00417f20(iVar3);

    if ((float10)param_1 - (float10)1.0 < fVar6 != ((float10)param_1 - (float10)1.0 == fVar6)) {

      iVar4 = reaper_0052e4a0();

      if (iVar4 != 0) {

        kabutoai_select_punch_anim__FP6OBJECT(iVar3);

      }

      reaperbasebldg_finish_building(iVar3);

      return;

    }

    iVar4 = FUN_0052e530(iVar3);

    if (iVar4 == 0) {

      return;

    }

    if (*pfVar1 == pfVar1[1]) {

      return;

    }

    reaper_state_check_c(iVar3);

    pfVar1[1] = *pfVar1;

    return;

  case 4:

    iVar4 = FUN_00418380(iVar4,10);

    if (iVar4 == 0) {

      pfVar1[2] = 0.0;

    }

    else {

      fVar6 = (float10)FUN_00518b70(param_1,0);

      fVar6 = fVar6 * (float10)*(float *)(DAT_00632ed8 + 0xfb8) + (float10)pfVar1[2];

      pfVar1[2] = (float)fVar6;

      if ((float10)*(float *)(DAT_00632ed8 + 0xfbc) < fVar6) {

        pfVar1[2] = *(float *)(DAT_00632ed8 + 0xfbc);

      }

    }

    if (*(int *)((int)param_1 + 0x10) == 1) {

      fVar6 = (float10)FUN_00417f20(param_1);

      fVar7 = (float10)FUN_00418170(param_1);

      fVar7 = (float10)(float)fVar6 / fVar7;

      *(uint *)((int)param_1 + 0x30) = *(uint *)((int)param_1 + 0x30) | 0x80;

      if (fVar7 < (float10)0.0 == (fVar7 == (float10)0.0)) {

        fVar7 = fVar7 - (float10)0.01;

        fVar6 = (float10)*(float *)(DAT_00632ed8 + 0xb7c) * (float10)0.01;

        if (fVar7 < fVar6 == (fVar7 == fVar6)) {

          fVar6 = (float10)*(float *)(DAT_00632ed8 + 0xb78) * (float10)0.01;

          if (fVar7 < fVar6 == (fVar7 == fVar6)) {

            fVar6 = (float10)*(float *)(DAT_00632ed8 + 0xb74) * (float10)0.01;

            if (fVar7 < fVar6 == (fVar7 == fVar6)) {

              *(undefined4 *)((int)param_1 + 0x14) = 0x3f800000;

            }

            else {

              *(float *)((int)param_1 + 0x14) = (float)fVar6;

            }

          }

          else {

            *(float *)((int)param_1 + 0x14) = (float)fVar6;

          }

        }

        else {

          *(float *)((int)param_1 + 0x14) = (float)fVar6;

        }

      }

      else {

        *(undefined4 *)((int)param_1 + 0x14) = 0;

      }

    }

    break;

  case 5:

switchD_004b4d3a_caseD_5:

    if ((*(byte *)((int)param_1 + 0x30) & 2) != 0) {

      *(undefined4 *)((int)param_1 + 0x184) = 0x3f800000;

      FUN_00497510(param_1);

      return;

    }

    return;

  default:

    goto switchD_004b4d3a_caseD_6;

  case 7:

switchD_004b4d3a_caseD_7:

    if ((*(byte *)((int)param_1 + 0x30) & 2) == 0) {

      return;

    }

    FUN_004034a0(param_1,1,0x84,0,0,0);

    *(undefined4 *)((int)param_1 + 0x14) = 0x3f800000;

    *(undefined4 *)((int)param_1 + 0xe4) = 4;

    return;

  case 9:

    iVar4 = FUN_00418380(iVar4,10);

    if (iVar4 == 0) {

      pfVar1[2] = 0.0;

    }

    else {

      fVar6 = (float10)FUN_00518b70(param_1,0);

      fVar6 = fVar6 * (float10)*(float *)(DAT_00632ed8 + 0x1380) + (float10)pfVar1[2];

      pfVar1[2] = (float)fVar6;

      if ((float10)*(float *)(DAT_00632ed8 + 0x1384) < fVar6) {

        pfVar1[2] = *(float *)(DAT_00632ed8 + 0x1384);

      }

    }

    fVar6 = (float10)FUN_00417f20(param_1);

    fVar6 = fVar6 / (float10)*(float *)(DAT_00632ed8 + 0x894);

    *(uint *)((int)param_1 + 0x30) = *(uint *)((int)param_1 + 0x30) | 0x80;

    if (((float10)0.75 <= fVar6) && (fVar6 < (float10)0.99)) {

      fVar6 = (float10)0.75;

    }

    *(float *)((int)param_1 + 0x14) = (float)fVar6;

    if (((*(uint *)((int)param_1 + 0xe0) & 0x1000) != 0) &&

       (*(int *)((int)param_1 + 0x18c) != *(int *)(DAT_00632a88 + 0x18c))) {

      fVar6 = (float10)FUN_0050a580(DAT_00632a88 + 0xa0,(int)param_1 + 0xa0);

      fVar6 = (fVar6 - (float10)*(float *)(DAT_00632ed8 + 0x1210)) /

              ((float10)*(float *)(DAT_00632ed8 + 0x1214) -

              (float10)*(float *)(DAT_00632ed8 + 0x1210));

      *(float *)((int)param_1 + 0x184) = (float)fVar6;

      if ((float10)1.0 < fVar6) {

        *(undefined4 *)((int)param_1 + 0x184) = 0x3f800000;

      }

      if (*(float *)((int)param_1 + 0x184) < 0.0) {

        *(undefined4 *)((int)param_1 + 0x184) = 0;

      }

    }

  }

  iVar4 = FUN_0052e4b0(param_1);

  if ((iVar4 != 0) && ((*pfVar1 != pfVar1[1] || (pfVar1[2] != pfVar1[3])))) {

    reaper_state_check_c(param_1);

    pfVar1[1] = *pfVar1;

    pfVar1[3] = pfVar1[2];

  }

switchD_004b4d3a_caseD_6:

  return;

}

/* ===== FUN_004b54c0 @ 0x004B54C0 ===== */
/* PS2 candidate: reaperbasebldg_start_building (conf 0.503) */



void FUN_004b54c0(int param_1,int param_2,uint param_3)



{

  int iVar1;

  int iVar2;

  uint uVar3;

  int iVar4;

  int *piVar5;

  bool bVar6;

  

  iVar1 = *(int *)(param_1 + 0x100);

  *(undefined4 *)(param_2 + 0x184) = 0;

  *(undefined4 *)(param_2 + 0xe4) = 3;

  FUN_004034a0(param_2,1,0x84,0,0,0);

  *(undefined4 *)(param_2 + 0x14) = 0;

  *(undefined4 *)(param_2 + 0x18c) = *(undefined4 *)(param_1 + 0x18c);

  uVar3 = param_3 & 0x80000007;

  bVar6 = uVar3 == 0;

  *(uint *)(param_2 + 0x1c8) = *(uint *)(param_2 + 0x1c8) & 0xfffff7ff | 0x20000;

  *(uint *)(param_2 + 0xd8) = *(uint *)(param_2 + 0xd8) | 0x10;

  if ((int)uVar3 < 0) {

    bVar6 = (uVar3 - 1 | 0xfffffff8) == 0xffffffff;

  }

  if (bVar6) {

    piVar5 = (int *)(iVar1 + 0x370);

    param_2 = 5;

    do {

      iVar4 = 0xc;

      do {

        iVar2 = *piVar5;

        if (iVar2 != 0) {

          *(undefined4 *)(iVar2 + 0xe4) = 0x1e;

          FUN_00401000(iVar2);

          *(undefined4 *)(*(int *)(iVar2 + 0x100) + 0x28) = 0xffffffff;

          *piVar5 = 0;

        }

        piVar5 = piVar5 + 2;

        iVar4 = iVar4 + -1;

      } while (iVar4 != 0);

      param_2 = param_2 + -1;

    } while (param_2 != 0);

  }

  if (7 < (int)param_3) {

    iVar4 = *(int *)(iVar1 + -0xc0 + param_3 * 0x1c);

    piVar5 = (int *)(iVar1 + -0xc0 + param_3 * 0x1c);

    if (iVar4 != 0) {

      *(undefined4 *)(iVar4 + 0xe4) = 5;

      FUN_004034a0(*piVar5,1,0x10,0,0,0);

      if (DAT_00657678 == 0) {

        FUN_00441d20(*piVar5 + 0xa0,0x40000000);

        FUN_00441d20(*piVar5 + 0xa0,0x40400000);

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

  iVar3 = FUN_004a6290(param_1);

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

  FUN_00418010(iVar6,param_1);

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

        if ((iVar3 == 0) && (iVar6 = FUN_0052e480(iVar6), iVar6 != 0)) {

          FUN_0045a740(iVar2 + 0x5c4,0x49,0xffffffff);

          FUN_0045a740(iVar2 + 0x5d0,0x49,0xffffffff);

        }

      }

      else {

        uVar5 = FUN_00507b00(s_BaseChatRpPHouseDone_00560bf0,1);

        FUN_005362d0(uVar5);

      }

      iVar6 = *(int *)(iVar3 * 0x1c + 0x20 + *(int *)(iVar1 + 0x100));

      if (**(int **)(iVar6 + 8) != *(int *)(&DAT_005606b4 + iVar3 * 0x58)) {

        uVar5 = FUN_00497d20(*(int *)(&DAT_005606b4 + iVar3 * 0x58));

        object_set_objectset(iVar6,uVar5);

      }

      if (*(int *)(iVar2 + 0x368) == iVar3) {

        *(undefined4 *)(iVar2 + 0x368) = 0xffffffff;

      }

      FUN_004b5810(iVar1);

    }

  }

  return;

}

/* ===== FUN_004b5810 @ 0x004B5810 ===== */
/* PS2 candidate: reaperbase_update_icons (conf 0.547) */



void FUN_004b5810(int param_1)



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

  iVar4 = FUN_00418380(param_1,0);

  if ((iVar4 == 0) && (iVar4 = FUN_00418380(param_1,8), iVar4 == 0)) {

    iVar4 = FUN_00418380(param_1,0);

    if (iVar4 != 0) {

      return;

    }

    iVar4 = FUN_00418470(param_1,8);

    if (iVar4 == 0) {

      return;

    }

  }

  iVar4 = FUN_00418380(param_1,8);

  if (iVar4 == 0) {

    iVar4 = FUN_00418380(param_1,0);

    if (((((iVar4 != 0) && (iVar4 = FUN_00418380(param_1,0xc), iVar4 != 0)) &&

         (iVar4 = FUN_00418380(param_1,0xd), iVar4 != 0)) &&

        ((iVar4 = FUN_00418380(param_1,0xe), iVar4 != 0 &&

         (iVar4 = FUN_00418380(param_1,0xf), iVar4 != 0)))) &&

       ((iVar4 = FUN_00418380(param_1,0xb), iVar4 != 0 &&

        ((iVar4 = FUN_00418380(param_1,10), iVar4 != 0 &&

         (iVar4 = FUN_00418380(param_1,9), iVar4 != 0)))))) {

      *(undefined4 *)(iVar1 + 0x114) = 1;

      return;

    }

  }

  else {

    *(undefined4 *)(iVar1 + 0x568) = 1;

    *(undefined4 *)(iVar1 + 0x114) = 1;

  }

  iVar4 = *(int *)(param_1 + 0x100);

  iVar3 = FUN_00418380(param_1,10);

  if (iVar3 == 0) {

    iVar3 = FUN_00418380(param_1,2);

    if ((iVar3 == 0) && (iVar3 = FUN_00418470(param_1,10), iVar3 == 0)) {

      *(undefined4 *)(iVar4 + 0x6c) = 1;

    }

    else {

      *(undefined4 *)(iVar4 + 0x14c) = 1;

    }

  }

  iVar4 = FUN_00418380(param_1,2);

  if ((iVar4 == 0) && (iVar4 = FUN_00418380(param_1,10), iVar4 == 0)) {

    iVar4 = FUN_00418380(param_1,2);

    if (iVar4 != 0) {

      return;

    }

    iVar4 = FUN_00418470(param_1,10);

    if (iVar4 == 0) {

      return;

    }

  }

  iVar4 = FUN_00418380(param_1,9);

  if (iVar4 == 0) {

    *(undefined4 *)(iVar1 + 0x130) = 1;

  }

  iVar1 = *(int *)(param_1 + 0x100);

  iVar4 = FUN_00418380(param_1,0xc);

  if (iVar4 == 0) {

    iVar4 = FUN_00418380(param_1,4);

    if ((iVar4 == 0) && (iVar4 = FUN_00418470(param_1,0xc), iVar4 == 0)) {

      *(undefined4 *)(iVar1 + 0xa4) = 1;

    }

    else {

      *(undefined4 *)(iVar1 + 0x184) = 1;

    }

  }

  iVar1 = *(int *)(param_1 + 0x100);

  iVar4 = FUN_00418380(param_1,0xd);

  if (iVar4 == 0) {

    iVar4 = FUN_00418380(param_1,5);

    if ((iVar4 == 0) && (iVar4 = FUN_00418470(param_1,0xd), iVar4 == 0)) {

      *(undefined4 *)(iVar1 + 0xc0) = 1;

    }

    else {

      *(undefined4 *)(iVar1 + 0x1a0) = 1;

    }

  }

  iVar1 = *(int *)(param_1 + 0x100);

  iVar4 = FUN_00418380(param_1,0xe);

  if (iVar4 == 0) {

    iVar4 = FUN_00418380(param_1,6);

    if ((iVar4 == 0) && (iVar4 = FUN_00418470(param_1,0xe), iVar4 == 0)) {

      *(undefined4 *)(iVar1 + 0xdc) = 1;

    }

    else {

      *(undefined4 *)(iVar1 + 0x1bc) = 1;

    }

  }

  iVar1 = *(int *)(param_1 + 0x100);

  iVar4 = FUN_00418380(param_1,0xf);

  if (iVar4 == 0) {

    iVar4 = FUN_00418380(param_1,7);

    if ((iVar4 == 0) && (iVar4 = FUN_00418470(param_1,0xf), iVar4 == 0)) {

      *(undefined4 *)(iVar1 + 0xf8) = 1;

    }

    else {

      *(undefined4 *)(iVar1 + 0x1d8) = 1;

    }

  }

  iVar1 = *(int *)(param_1 + 0x100);

  iVar4 = FUN_00418380(param_1,0xb);

  if (iVar4 == 0) {

    iVar4 = FUN_00418380(param_1,3);

    if ((iVar4 == 0) && (iVar4 = FUN_00418470(param_1,0xb), iVar4 == 0)) {

      *(undefined4 *)(iVar1 + 0x88) = 1;

      return;

    }

    *(undefined4 *)(iVar1 + 0x168) = 1;

  }

  return;

}

/* ===== FUN_004b5b30 @ 0x004B5B30 ===== */
/* PS2 candidate: meccbasepit_swap_model__FP6OBJECTi13e_bldg_objset_2 (conf 0.557) */



void FUN_004b5b30(int param_1,int param_2,int param_3)



{

  int iVar1;

  undefined4 uVar2;

  

  iVar1 = *(int *)(*(int *)(param_1 + 0x100) + 0x20 + param_2 * 0x1c);

  if (param_3 == 0) {

    if (**(int **)(iVar1 + 8) != *(int *)(&DAT_005606b4 + param_2 * 0x58)) {

      uVar2 = FUN_00497d20(*(int *)(&DAT_005606b4 + param_2 * 0x58));

      object_set_objectset(iVar1,uVar2);

      return;

    }

  }

  else if (param_3 == 1) {

    if (**(int **)(iVar1 + 8) != *(int *)(&DAT_005606b8 + param_2 * 0x58)) {

      uVar2 = FUN_00497d20(*(int *)(&DAT_005606b8 + param_2 * 0x58));

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

  int iVar4;

  int *piVar5;

  int iVar6;

  int *piVar7;

  char *pcVar8;

  undefined4 uVar9;

  undefined1 *puVar10;

  undefined1 local_34 [4];

  undefined4 local_30;

  undefined4 local_2c;

  undefined4 local_28;

  

  iVar2 = (int)param_1;

  iVar6 = *(int *)(*(int *)((int)param_1 + 0x274) + 0x100);

  if (*(int *)((int)param_1 + 0x274) != 0) {

    iVar3 = 0;

    piVar5 = (int *)(iVar6 + 0x20);

    do {

      if ((float)*piVar5 == param_1) goto LAB_004b5d40;

      iVar3 = iVar3 + 1;

      piVar5 = piVar5 + 7;

    } while (iVar3 < 0x10);

  }

  iVar3 = -1;

LAB_004b5d40:

  iVar4 = FUN_004a6290(param_1);

  if (iVar4 == 0) {

    if (*(int *)((int)param_1 + 0x274) != 0) {

      iVar4 = 0;

      piVar5 = (int *)(*(int *)(*(int *)((int)param_1 + 0x274) + 0x100) + 0x20);

      do {

        if ((float)*piVar5 == param_1) {

          if (-1 < iVar4) {

            param_1 = (float)(&DAT_005606bc)[iVar4 * 0x16];

            goto LAB_004b5db6;

          }

          break;

        }

        iVar4 = iVar4 + 1;

        piVar5 = piVar5 + 7;

      } while (iVar4 < 0x10);

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

  FUN_00418010(iVar2,fVar1);

  *(float *)(iVar2 + 0x278) = param_1 - fVar1;

  *(uint *)(iVar2 + 0x1cc) = *(uint *)(iVar2 + 0x1cc) | 1;

  if (iVar3 < 0) {

    piVar7 = (int *)(iVar6 + 0x574);

    iVar6 = 8;

    piVar5 = piVar7;

    do {

      if (*piVar5 == iVar2) {

        *piVar5 = 0;

      }

      piVar5 = piVar5 + 1;

      iVar6 = iVar6 + -1;

    } while (iVar6 != 0);

    FUN_00497510(iVar2);

    if ((*(int *)(iVar2 + 4) == 0x4a8) && (piVar5 = DAT_00632d9c, DAT_00632d9c != (int *)0x0)) {

      while (((iVar6 = piVar5[3], *(int *)(iVar6 + 4) != 0x4a8 ||

              (((*(int *)(iVar6 + 0x18c) != 1 &&

                (*(int *)(iVar6 + 0x18c) != *(int *)(iVar2 + 0x18c))) || (iVar6 == iVar2)))) ||

             ((char)((uint)*(undefined4 *)(iVar6 + 0xd8) >> 8) < '\0'))) {

        piVar5 = (int *)*piVar5;

        if (piVar5 == (int *)0x0) {

          return;

        }

      }

      iVar3 = 8;

      do {

        if (*piVar7 == iVar6) {

          *piVar7 = 0;

        }

        piVar7 = piVar7 + 1;

        iVar3 = iVar3 + -1;

      } while (iVar3 != 0);

      FUN_00497510(iVar6);

      if (param_2 == 0) {

        local_30 = *(undefined4 *)(iVar6 + 0xa0);

        local_2c = *(undefined4 *)(iVar6 + 0xa4);

        puVar10 = local_34;

        local_28 = *(undefined4 *)(iVar6 + 0xa8);

        uVar9 = 8;

        pcVar8 = s_FX_stone_explode_Large_00554f20;

        fx_get_free_effect__Fv();

        sound_play_obj(0x615,iVar2,pcVar8,uVar9,puVar10);

        return;

      }

    }

  }

  else {

    comm_wincond_destroy(iVar2);

  }

  return;

}

/* ===== FUN_004b65a0 @ 0x004B65A0 ===== */
void FUN_004b65a0(int param_1,int param_2)



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

      fVar3 = (float10)FUN_00417f20(iVar2);

      if ((float10)0.0 < fVar3) {

        fVar3 = (float10)FUN_00417f20(iVar2);

        fVar4 = (float10)FUN_00418170(iVar2);

        if ((float10)(float)fVar3 < fVar4) {

          *(undefined4 *)(iVar2 + 0xe4) = 3;

        }

      }

    }

    *(int *)(*(int *)(param_1 + 0x100) + 0x20) = param_2;

    FUN_004b5810(iVar1);

  }

  return;

}

/* ===== object_spawn_4b @ 0x004B6630 ===== */
undefined4 object_spawn_4b(int param_1,uint param_2)



{

  int iVar1;

  undefined4 uVar2;

  int iVar3;

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

      FUN_00497510(*piVar4);

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

    iVar3 = object_allocate_type((&DAT_005606b0)[param_2 * 0x16],0x80000000);

    FUN_004993c0(iVar3,&local_c);

    *(undefined4 *)(iVar3 + 200) = uVar2;

    *(undefined4 *)(iVar3 + 0xcc) = 0;

    *(undefined4 *)(iVar3 + 0xd0) = 0;

    *(undefined4 *)(iVar3 + 0xe4) = 1;

    *(uint *)(iVar3 + 0xd8) = *(uint *)(iVar3 + 0xd8) | 0x10;

    if (DAT_00632bb0 == 0) {

      *(undefined4 *)(iVar3 + 0x184) = 0x3f800000;

    }

    else {

      *(undefined4 *)(iVar3 + 0x184) = 0x3dcccccd;

    }

    *(int *)(iVar3 + 0x274) = param_1;

    FUN_00418010(iVar3,0);

    FUN_004034a0(iVar3,1,0x84,0,0,0);

    *(undefined4 *)(iVar3 + 0x14) = 0x3f800000;

    *(uint *)(iVar3 + 0x1c8) = *(uint *)(iVar3 + 0x1c8) & 0xfffdffff | 0x800;

    *(int *)(iVar1 + 0x20) = iVar3;

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

/* ===== FUN_004b6800 @ 0x004B6800 ===== */
/* PS2 candidate: meccbase_hide_tentatives_2 (conf 0.64) */



void FUN_004b6800(int param_1)



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

/* ===== FUN_004b6870 @ 0x004B6870 ===== */
undefined4 FUN_004b6870(int param_1,int param_2,undefined4 *param_3)



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

  iVar2 = FUN_004184a0(param_1,8);

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

  iVar2 = FUN_00418380(param_1,0);

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

      FUN_00418630(local_18,*puVar6,local_c);

      fVar7 = (float10)FUN_0050a5e0(local_c,param_2 + 0xa0);

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

      FUN_00418630(local_18,piVar4[1],local_c);

      fVar7 = (float10)FUN_0050a5e0(local_c,param_2 + 0xa0);

      fVar8 = (float10)FUN_0050a5e0(local_c,*piVar4 + 0xa0);

      if ((float10)(float)fVar7 < fVar8) {

        iVar3 = local_10 * 0xc + iVar2;

        *(undefined4 *)(*(int *)(iVar1 + 0x370 + iVar3 * 8) + 0xe4) = 0x1e;

        FUN_00401000(*(undefined4 *)(iVar1 + 0x370 + iVar3 * 8));

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

/* ===== FUN_004b6bb0 @ 0x004B6BB0 ===== */
void FUN_004b6bb0(int param_1,int param_2)



{

  int iVar1;

  int *piVar2;

  int iVar3;

  

  iVar3 = *(int *)(param_1 + 0x100);

  iVar1 = FUN_00418380(param_1,0);

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

/* ===== FUN_004b6c00 @ 0x004B6C00 ===== */
int FUN_004b6c00(int param_1,int *param_2)



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

          (fVar5 = (float10)FUN_0050a5e0(iVar1 + 0xa0,param_1 + 0xa0), fVar5 <= (float10)250000.0))

         && (fVar5 < (float10)local_8)) {

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

/* ===== FUN_004b6cd0 @ 0x004B6CD0 ===== */
void FUN_004b6cd0(undefined4 param_1,int param_2,int param_3)



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

/* ===== FUN_004b6d20 @ 0x004B6D20 ===== */
int FUN_004b6d20(undefined4 param_1,int param_2)



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

/* ===== FUN_004b6d60 @ 0x004B6D60 ===== */
/* PS2 candidate: reaperbase_get_max_energy (conf 0.408) */



float10 FUN_004b6d60(int param_1)



{

  int iVar1;

  int *piVar2;

  

  iVar1 = FUN_004a6290(param_1);

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

/* ===== FUN_004b6de0 @ 0x004B6DE0 ===== */
undefined4 FUN_004b6de0(int param_1)



{

  int iVar1;

  int iVar2;

  

  iVar1 = *(int *)(param_1 + 0x100);

  iVar2 = FUN_00418380(param_1,0xb);

  if (iVar2 != 0) {

    return *(undefined4 *)(iVar1 + 0x154);

  }

  iVar2 = FUN_00418380(param_1,3);

  if (iVar2 != 0) {

    return *(undefined4 *)(iVar1 + 0x74);

  }

  return 0;

}

/* ===== FUN_004b6e20 @ 0x004B6E20 ===== */
undefined4 FUN_004b6e20(int param_1)



{

  int iVar1;

  int iVar2;

  

  iVar1 = *(int *)(param_1 + 0x100);

  iVar2 = FUN_004184a0(param_1,9);

  if (iVar2 != 0) {

    return *(undefined4 *)(iVar1 + 0x11c);

  }

  iVar2 = FUN_004184a0(param_1,1);

  if (iVar2 != 0) {

    return *(undefined4 *)(iVar1 + 0x3c);

  }

  iVar2 = FUN_00418470(param_1,9);

  if (iVar2 != 0) {

    return *(undefined4 *)(iVar1 + 0x11c);

  }

  return 0;

}

/* ===== FUN_004b6e80 @ 0x004B6E80 ===== */
undefined4 FUN_004b6e80(int param_1)



{

  int iVar1;

  int iVar2;

  

  iVar1 = *(int *)(param_1 + 0x100);

  iVar2 = FUN_004184a0(param_1,9);

  if (iVar2 != 0) {

    return *(undefined4 *)(iVar1 + 0x11c);

  }

  return 0;

}

/* ===== FUN_004b6eb0 @ 0x004B6EB0 ===== */
undefined4 FUN_004b6eb0(int param_1)



{

  int iVar1;

  int iVar2;

  

  iVar1 = *(int *)(param_1 + 0x100);

  iVar2 = FUN_00418380(param_1,10);

  if (iVar2 != 0) {

    return *(undefined4 *)(iVar1 + 0x138);

  }

  iVar2 = FUN_00418380(param_1,2);

  if (iVar2 != 0) {

    return *(undefined4 *)(iVar1 + 0x58);

  }

  return 0;

}

/* ===== FUN_004b6ef0 @ 0x004B6EF0 ===== */
undefined4 FUN_004b6ef0(int param_1)



{

  int iVar1;

  int iVar2;

  

  iVar1 = *(int *)(param_1 + 0x100);

  iVar2 = FUN_00418380(param_1,8);

  if (iVar2 != 0) {

    return *(undefined4 *)(iVar1 + 0x100);

  }

  return 0;

}

/* ===== FUN_004b6f20 @ 0x004B6F20 ===== */
int FUN_004b6f20(int param_1)



{

  int iVar1;

  int iVar2;

  

  iVar1 = *(int *)(param_1 + 0x100);

  iVar2 = FUN_00418510(param_1,8);

  if (iVar2 != 0) {

    return *(int *)(iVar1 + 0x100);

  }

  iVar2 = FUN_00418510(param_1,0);

  if (iVar2 != 0) {

    return *(int *)(iVar1 + 0x20);

  }

  return param_1;

}

/* ===== FUN_004b6f60 @ 0x004B6F60 ===== */
/* PS2 candidate: meccbasepit_bldg_from_object_2 (conf 0.767) */



int FUN_004b6f60(int param_1)



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

/* ===== FUN_004b6fa0 @ 0x004B6FA0 ===== */
/* PS2 candidate: mecc_shot (conf 0.462) */



void FUN_004b6fa0(int param_1,undefined4 param_2,uint param_3,float param_4)



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

  iVar3 = FUN_0052e480(uVar2);

  if (((iVar3 != 0) || (param_1 == -1)) && ((*puVar6 & 0x200) != 0)) {

    FUN_0050c2a0(uVar2);

    *puVar6 = *puVar6 & 0xfffffdff;

  }

  if (((param_1 == 5) || (param_1 == 7)) || ((param_1 == 6 || (param_1 == 8)))) {

    FUN_0050a390(*(undefined4 *)(uVar2 + 300),*(undefined4 *)(uVar2 + 0x128));

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

        FUN_00448920(*puVar5);

      }

      *puVar5 = 0;

      uVar7 = uVar7 + 1;

      puVar5 = puVar5 + 1;

      param_3 = uVar7;

    } while ((float)(int)uVar7 < *(float *)(DAT_00632ed8 + 0x7c4));

  }

  iVar3 = FUN_0052e480(uVar2);

  if (iVar3 != 0) {

    DAT_00632bc4 = 0;

  }

  FUN_00495700(0x36c,uVar2);

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

  FUN_00495700(0x69c,uVar2);

  FUN_00495700(0x69d,uVar2);

  FUN_00495700(0x69e,uVar2);

  FUN_00495700(0x69f,uVar2);

  if (DAT_00632f08 == 0) {

    FUN_004a54a0();

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

      iVar4 = FUN_004a6140(fVar8);

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

      iVar4 = FUN_00521370(DAT_00632f18);

      if (iVar4 == 0) {

        local_38 = param_4;

      }

      else {

        local_38 = 0.0;

      }

      FUN_00530430(fVar8,uVar2,iVar3,*(int *)(uVar2 + 0x18c) + -1,param_4,local_38,0x3f800000,

                   0x3f800000);

    }

    param_3 = param_3 & 0xff000000;

    FUN_00530f10(uVar2,0,0,3,3,&param_3);

  }

  iVar3 = reaper_0052e4a0(uVar2);

  if (iVar3 != 0) {

    if (1 < (int)puVar6[0x36d]) {

      iVar3 = *(int *)(uVar2 + 0x100);

      FUN_0045a820(uVar2,*(undefined4 *)(iVar3 + 0xd70 + *(int *)(iVar3 + 0xdb4) * 8),

                   *(undefined4 *)(iVar3 + 0xd74 + *(int *)(iVar3 + 0xdb4) * 8),

                   *(float *)(uVar2 + 0x29c) * -30.0,*(float *)(uVar2 + 0x2ac) * -30.0,0x41700000,

                   0x41f00000);

      FUN_004b9080(uVar2,*(undefined4 *)(iVar3 + 0xd70 + *(int *)(iVar3 + 0xdb4) * 8),0xffffffff,0,1

                  );

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

    FUN_004bdbf0(uVar2);

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

  iVar3 = FUN_0052aa70();

  if ((iVar3 != 0) &&

     (((((param_1 == 5 || (param_1 == 7)) || (param_1 == 6)) || (param_1 == 8)) &&

      (iVar3 = FUN_00456050(uVar2), iVar3 != 0)))) {

    *(uint *)(iVar3 + 0xd8) = *(uint *)(iVar3 + 0xd8) | 0x40000000;

  }

  return;

}

/* ===== FUN_004b7450 @ 0x004B7450 ===== */
/* WARNING: Removing unreachable block (ram,0x004b7a7a) */

/* WARNING: Removing unreachable block (ram,0x004b7a90) */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* PS2 candidate: reaper_animselect (conf 0.584) */



void FUN_004b7450(int param_1,undefined4 param_2,undefined4 param_3,float *param_4)



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

    FUN_004baa70(param_1);

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

        iVar7 = FUN_00456050(param_1);

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

        FUN_00497570(param_1);

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

    FUN_004bdbf0(param_1);

    return;

  case 5:

    iVar7 = *(int *)(param_1 + 0x100);

    *(undefined4 *)(iVar7 + 0xdb4) = 3;

    *(float *)(iVar7 + 0xd88) = *param_4;

    FUN_004bdaa0(param_1);

    return;

  case 7:

    iVar7 = *(int *)(param_1 + 0x100);

    *(undefined4 *)(iVar7 + 0xf40) = 1;

    if (param_4[6] == -NAN) {

      *(undefined4 *)(iVar7 + 0xc) = 0;

    }

    else {

      uVar5 = FUN_0052e5b0(param_4[6]);

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

    FUN_004be020(param_1,0,param_4,param_4 + 3,0x2c);

    return;

  case 10:

    FUN_004c0fc0(param_1,param_4,param_4[3],param_4[4]);

    return;

  case 0xb:

    FUN_004ec1f0(param_1,param_4,param_4[3]);

    return;

  case 0xd:

    iVar7 = FUN_0052e5b0(param_4[1]);

    param_4 = (float *)*pfVar11;

    if (iVar7 != 0) {

      FUN_00497510(iVar7);

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

    FUN_00493d60(param_1,param_4);

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

    iVar9 = FUN_0052aa70();

    if (iVar9 == 0) {

      fVar14 = (float10)1.0;

    }

    else {

      fVar14 = (float10)FUN_00522130(DAT_00632f40);

    }

    FUN_00417880(*(undefined4 *)(iVar7 + 0xcfc),

                 (float)((float10)*(float *)(DAT_00632ed8 + 0x61c) * fVar14));

    sound_play_player(0x3ce,param_1);

    return;

  case 0xf:

    iVar7 = *(int *)(param_1 + 0x100);

    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xffdfffff;

    iVar9 = FUN_0052e480(param_1);

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

    iVar7 = FUN_0052e480(param_1);

    if (iVar7 != 0) {

      FUN_004bea70(param_1,0x25,0,0,0xffffffff);

      return;

    }

    break;

  case 0x10:

    iVar7 = *(int *)(param_1 + 0x100);

    if (((*(uint *)(param_1 + 0xd8) & 0x80000) == 0) || ((**(byte **)(param_1 + 0x104) & 0x40) != 0)

       ) {

      iVar7 = FUN_0052e480(param_1);

      if (iVar7 != 0) {

        FUN_004bea70(param_1,0x26,0,0,0xffffffff);

        *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xbfffffff;

        return;

      }

LAB_004b8187:

      *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xbfffffff;

      return;

    }

    sound_play_player(0x3a4,param_1);

    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 0x40000000;

    iVar9 = FUN_0052e480(param_1);

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

      iVar9 = FUN_0052e480(param_1);

      if (iVar9 != 0) {

        FUN_004bea70(param_1,0x24,0,0,0xffffffff);

      }

    }

    else {

      sound_play_player(0x3a4,param_1);

      *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 0x100000;

    }

    iVar9 = FUN_0052e480(param_1);

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

      FUN_004c0550(param_1,pfVar11);

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

      iVar7 = object_allocate_type(*(undefined4 *)(param_1 + 4),0x80000000);

      *(undefined4 *)(iVar7 + 0x18c) = *(undefined4 *)(param_1 + 0x18c);

      FUN_00455c80(iVar7,1,0x29d);

      object_change_ospec(iVar7,0x55);

      *(float *)(iVar7 + 0xf4) = fVar10;

      FUN_004993c0(iVar7,pfVar11);

      *(uint *)(iVar7 + 0x1c8) = *(uint *)(iVar7 + 0x1c8) | 0x20000;

      *(int *)(iVar7 + 0x274) = param_1;

      if ((DAT_00560c50 != 0xfe) && (*(int *)(*(int *)(param_1 + 8) + 8 + DAT_00560c50 * 4) != 0)) {

        FUN_004034a0(iVar7,DAT_00560c50,1,0,0,0x3e2aaaab);

      }

      sound_play_obj(0x3c0,iVar7);

      pfVar13 = pfVar13 + 1;

      pfVar11 = pfVar11 + 3;

      param_4 = (float *)((int)param_4 + -1);

    } while (param_4 != (float *)0x0);

    return;

  case 0x15:

    iVar7 = *(int *)(param_1 + 0x100);

    iVar9 = FUN_0052e480(param_1);

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

    iVar7 = FUN_0052e480(param_1);

    if (iVar7 != 0) {

      FUN_004bea70(param_1,0x27,0,0,0xffffffff);

      return;

    }

    break;

  case 0x16:

    iVar9 = FUN_0052e5b0(*param_4);

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

        FUN_004a61a0(*(undefined4 *)(iVar9 + 0x210));

      }

      else {

        iVar9 = FUN_004a6160(*(int *)(iVar9 + 0x274));

        if ((iVar9 != 0) ||

           (iVar9 = FUN_004a6180(*(undefined4 *)(*(int *)(iVar7 + 0xea4) + 0x274)), iVar9 != 0)) {

          smartie_unlock_from_player

                    (*(int *)(iVar7 + 0xea4),*(undefined4 *)(*(int *)(iVar7 + 0xea4) + 0x274),4);

        }

      }

      fx_reaper_bubble(*(undefined4 *)(iVar7 + 0xea4),param_1);

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

    FUN_004bfe50(param_1);

    return;

  case 0x18:

    iVar7 = FUN_0052e5b0(*param_4);

    *(int *)(*(int *)(param_1 + 0x100) + 0xf28) = iVar7;

    if (((*(uint *)(param_1 + 0xd8) & 0x80000) == 0) || ((**(byte **)(param_1 + 0x104) & 0x40) != 0)

       ) {

      iVar9 = FUN_0052e480(param_1);

      if (iVar9 != 0) {

        iVar9 = FUN_0052aa70();

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

      iVar9 = FUN_0052e480(param_1);

      if (iVar9 != 0) {

        iVar9 = FUN_0052aa70();

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

    uVar5 = FUN_0052e5b0(param_4[3]);

    *(undefined4 *)(iVar7 + 0xf8c) = uVar5;

    *(undefined4 *)(iVar7 + 0xf98) = 0;

    FUN_004be020(param_1,uVar5,pfVar11,pfVar11 + 4,0x2f);

    return;

  case 0x21:

    uVar5 = 0x2e;

LAB_004b76fe:

    FUN_004be020(param_1,0,param_4,param_4 + 3,uVar5);

    return;

  case 0x22:

    iVar9 = *(int *)(param_1 + 0x100);

    param_1 = 0;

    if (0 < *(int *)(iVar9 + 0xdac)) {

      puVar12 = (undefined4 *)(iVar9 + 0xf60);

      pfVar11 = param_4 + 3;

      do {

        uVar5 = FUN_0052e5b0(*pfVar11);

        *puVar12 = uVar5;

        param_1 = param_1 + 1;

        pfVar11 = pfVar11 + 1;

        puVar12 = puVar12 + 1;

      } while (param_1 < *(int *)(iVar9 + 0xdac));

    }

    FUN_004be020(iVar7,0,param_4,param_4 + 8,0x30);

    return;

  case 0x23:

    iVar7 = FUN_0052e5b0(*param_4);

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

      FUN_00448920(puVar3[0x38e]);

      puVar3[0x38e] = 0;

    }

    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xffffffbf;

    *puVar3 = *puVar3 & 0xfffffffe;

    return;

  case 0x27:

    FUN_004c03a0(param_1,0);

    return;

  case 0x28:

    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xffffff7f;

    return;

  case 0x29:

    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 0x200;

    *(int *)(*(int *)(param_1 + 0x100) + 4) = *(int *)(*(int *)(param_1 + 0x100) + 4) + 1;

    return;

  case 0x2a:

    FUN_004bea70(param_1,0x27,param_4,0,param_4[3]);

    return;

  case 0x2b:

    FUN_004bea70(param_1,0x26,param_4,0,param_4[3]);

    return;

  case 0x2c:

    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xffefffff;

    FUN_004bea70(param_1,0x24,param_4,0,param_4[3]);

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

      uVar5 = FUN_0052e5b0(*param_4);

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

    uVar5 = FUN_0052e5b0(*param_4);

    iVar7 = FUN_0052e480(param_1);

    if (iVar7 != 0) {

      FUN_00452490(0,uVar5);

      fVar14 = (float10)FUN_004a7630(uVar5,0);

      *(float *)(param_1 + 200) = (float)fVar14;

      FUN_004a76e0(param_1,0,(undefined4 *)(param_1 + 0xa0));

      FUN_00499310(param_1,*(undefined4 *)(param_1 + 0xa0),*(undefined4 *)(param_1 + 0xa4),

                   *(undefined4 *)(param_1 + 0xa8));

      *(undefined1 *)(param_1 + 0x20a) = 0;

      *(undefined1 *)(param_1 + 0x20b) = 0;

      *(undefined1 *)(param_1 + 0x208) = 0;

    }

    iVar7 = FUN_0052e480(uVar5);

    if (iVar7 == 0) {

      FUN_00454d80(uVar5,pfVar11[1]);

      return;

    }

    break;

  case 0x31:

    FUN_004bea70(param_1,0x2c,param_4,0,param_4[3]);

    return;

  case 0x32:

    iVar7 = *(int *)(param_1 + 0x100);

    *(undefined4 *)(iVar7 + 0xdb4) = 3;

    *(float *)(iVar7 + 0xd88) = *param_4;

    reaper_change_bow__FP6OBJECT(param_1);

    return;

  case 0x33:

    iVar7 = FUN_0052e5b0(*param_4);

    fVar10 = (float)FUN_0052e5b0(pfVar11[1]);

    if (fVar10 == 0.0) {

      param_4 = (float *)fVar10;

      local_40 = fVar10;

      local_3c = fVar10;

      local_38 = fVar10;

      if (iVar7 != 0) {

        FUN_004186c0(iVar7,2,&local_40,&param_4);

      }

      fVar10 = (float)object_allocate_type(0x434,0x80000000);

      FUN_004993c0(fVar10,&local_40);

      *(float **)((int)fVar10 + 200) = param_4;

      *(uint *)((int)fVar10 + 0x1d0) = *(uint *)((int)fVar10 + 0x1d0) | 0xf0f;

    }

    *(undefined4 *)((int)fVar10 + 0x18c) = *(undefined4 *)(param_1 + 0x18c);

    *(float *)((int)fVar10 + 0x188) = pfVar11[1];

    break;

  case 0x34:

    FUN_004bea70(param_1,0x32,param_4,0,param_4[3]);

    return;

  case 0x35:

    iVar7 = *(int *)(param_1 + 0x100);

    if (((*(uint *)(param_1 + 0xd8) & 0x80000) == 0) || ((**(byte **)(param_1 + 0x104) & 0x40) != 0)

       ) {

      iVar7 = FUN_0052e480(param_1);

      if (iVar7 != 0) {

        FUN_004bea70(param_1,0x33,0,0,0xffffffff);

      }

      goto LAB_004b8187;

    }

    sound_play_player(0x3af,param_1);

    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 0x20000000;

    iVar9 = FUN_0052e480(param_1);

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

    FUN_004bea70(param_1,0x33,param_4,0,param_4[3]);

    return;

  case 0x37:

    sound_play_3dpos(0x6ea,param_1 + 0xa0);

    pfVar11 = param_4;

    FUN_004993c0(param_1,param_4);

    *(float *)(param_1 + 200) = pfVar11[3];

    playerobj_zap_movement(param_1);

    sound_play_3dpos(0x6ea,param_1 + 0xa0);

    return;

  case 0x38:

    puVar3 = *(uint **)(param_1 + 0x100);

    if (*(float *)(param_1 + 0x278) < *(float *)(param_1 + 0x1c0)) {

      FUN_004b6fa0(0xffffffff,0,param_1,0,0,0);

      *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) | 0x40000000;

      iVar7 = FUN_00456050(param_1);

      if (iVar7 != 0) {

        *(uint *)(iVar7 + 0xd8) = *(uint *)(iVar7 + 0xd8) | 0x40000000;

      }

    }

    *puVar3 = *puVar3 | 0x400;

    return;

  }

  return;

}

/* ===== FUN_004b89d0 @ 0x004B89D0 ===== */
/* PS2 candidate: reaper_camdist_modify (conf 0.301) */



void FUN_004b89d0(int param_1,float *param_2,float *param_3)



{

  float fVar1;

  

  if ((*(uint *)(param_1 + 0xe0) & 0x100) == 0) {

    if (*param_2 != *param_3) {

      FUN_00451300(0x3dcccccd,0x41200000,0x42480000,*param_2,param_3);

      *param_2 = *param_3;

    }

  }

  else {

    fVar1 = *param_2 + 5.0;

    *param_2 = fVar1;

    if (fVar1 != *param_3) {

      FUN_00451300(0x3f800000,0x41200000,0x42480000,fVar1,param_3);

      *param_2 = *param_3;

      return;

    }

  }

  return;

}

/* ===== FUN_004b8a60 @ 0x004B8A60 ===== */
/* PS2 candidate: reaper_has_bow_5 (conf 0.652) */



int FUN_004b8a60(int param_1)



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

/* ===== reaper_has_bow_2 @ 0x004B8A90 ===== */
undefined4 reaper_has_bow_2(int param_1,int param_2)



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

/* ===== FUN_004b8ac0 @ 0x004B8AC0 ===== */
/* PS2 candidate: reaper_needs_ammo (conf 0.326) */



bool FUN_004b8ac0(int param_1,undefined4 param_2)



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

    iVar2 = FUN_004a6120(*(undefined4 *)(param_1 + 0x210));

    if (iVar2 != 0) {

      return *(int *)(*(int *)(*(int *)(param_1 + 0x210) + 0x100) + 0x6c) <

             *(int *)(DAT_00632ed8 + 0x1090);

    }

    break;

  case 0x3d:

    iVar2 = FUN_004a6120(*(undefined4 *)(param_1 + 0x210));

    if (iVar2 != 0) {

      return *(int *)(*(int *)(*(int *)(param_1 + 0x210) + 0x100) + 0x70) <

             *(int *)(DAT_00632ed8 + 0x108c);

    }

    break;

  case 0x3e:

    iVar2 = FUN_004a6120(*(undefined4 *)(param_1 + 0x210));

    if (iVar2 != 0) {

      return *(int *)(*(int *)(*(int *)(param_1 + 0x210) + 0x100) + 0x74) <

             *(int *)(DAT_00632ed8 + 0x1088);

    }

  }

  iVar2 = 0;

  piVar3 = (int *)(iVar1 + 0xd78);

  do {

    if (*piVar3 == param_1) {

      iVar4 = FUN_004a9070(param_1);

      return *(int *)(iVar1 + 0xd7c + iVar2 * 8) < iVar4;

    }

    iVar2 = iVar2 + 1;

    piVar3 = piVar3 + 2;

  } while (iVar2 < 4);

switchD_004b8adc_caseD_3b:

  return false;

}

/* ===== FUN_004b8c20 @ 0x004B8C20 ===== */
/* PS2 candidate: reaper_needs_other (conf 0.803) */



bool FUN_004b8c20(int param_1,int param_2,int param_3)



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

/* ===== reaper_has_bow @ 0x004B8CD0 ===== */
undefined4 reaper_has_bow(int param_1,int param_2)



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

/* ===== FUN_004b8d00 @ 0x004B8D00 ===== */
/* PS2 candidate: reaper_has_bow_6 (conf 0.64) */



bool FUN_004b8d00(int param_1)



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

/* ===== FUN_004b8d30 @ 0x004B8D30 ===== */
void FUN_004b8d30(int param_1,int param_2,int param_3)



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

            param_3 = FUN_004a90a0(param_2);

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

  FUN_004b9390(param_1,param_2,iVar2,param_3);

  return;

}

/* ===== FUN_004b8de0 @ 0x004B8DE0 ===== */
void FUN_004b8de0(int param_1,int param_2,int param_3)



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

/* ===== FUN_004b8e40 @ 0x004B8E40 ===== */
/* PS2 candidate: reaper_give_other (conf 0.504) */



void FUN_004b8e40(int param_1,int param_2,int param_3,int param_4,int param_5)



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

    iVar2 = FUN_004a9070(param_2);

    if (iVar2 < *(int *)(iVar1 + 0xd9c + param_3 * 8)) {

      uVar3 = FUN_004a9070(param_2);

      *(undefined4 *)(iVar1 + 0xd9c + param_3 * 8) = uVar3;

    }

    *(int *)(iVar1 + 0xd98 + param_3 * 8) = param_2;

  }

  return;

}

/* ===== FUN_004b8f00 @ 0x004B8F00 ===== */
/* PS2 candidate: reaper_give_ammo (conf 0.515) */



void FUN_004b8f00(int param_1,undefined4 param_2,int param_3)



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

    iVar2 = FUN_004a6120(iVar5);

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

    iVar2 = FUN_004a6120(iVar5);

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

    iVar2 = FUN_004a6120(iVar5);

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

  iVar2 = FUN_004a9070(param_1);

  if (iVar2 < *(int *)(iVar1 + 0xd7c + iVar5 * 8)) {

    uVar4 = FUN_004a9070(param_1);

    *(undefined4 *)(iVar1 + 0xd7c + iVar5 * 8) = uVar4;

  }

switchD_004b8f22_caseD_3b:

  return;

}

/* ===== FUN_004b9080 @ 0x004B9080 ===== */
/* PS2 candidate: reaper_set_bow (conf 0.488) */



void FUN_004b9080(int param_1,int param_2,int param_3,int param_4,int param_5)



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

    FUN_004b9120(param_1,1);

    return;

  }

  if (param_4 == -1) {

    param_4 = FUN_004a90a0(param_2);

  }

  *(int *)(iVar2 + 0xd7c + param_3 * 8) = param_4;

  *(int *)(iVar2 + 0xd78 + param_3 * 8) = param_2;

  if (param_5 != 0) {

    *(int *)(iVar2 + 0xdb4) = param_3 + 1;

    FUN_004bdaa0(param_1);

  }

  return;

}

/* ===== FUN_004b9120 @ 0x004B9120 ===== */
/* PS2 candidate: reaper_cycle_weapon__FP6OBJECTi (conf 0.344) */



void FUN_004b9120(int param_1,int param_2)



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

    FUN_004bdbf0();

  }

  else if (*(int *)(iVar2 + 0xdb4) == 1) {

    FUN_004bdaa0();

  }

  else {

    reaper_change_bow__FP6OBJECT(param_1);

  }

  if (*(int *)(iVar2 + 0xf90) != 0) {

    puVar1 = (uint *)(*(int *)(iVar2 + 0xf90) + 0xd8);

    *puVar1 = *puVar1 | 0x40000000;

  }

  FUN_00495700(0x36c,param_1);

  return;

}

/* ===== FUN_004b91d0 @ 0x004B91D0 ===== */
/* PS2 candidate: reaper_init_items (conf 0.51) */



void FUN_004b91d0(int param_1)



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

/* ===== FUN_004b9290 @ 0x004B9290 ===== */
/* PS2 candidate: reaper_has_bow_4 (conf 0.731) */



float10 FUN_004b9290(int param_1,int param_2)



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

/* ===== FUN_004b92d0 @ 0x004B92D0 ===== */
void FUN_004b92d0(int param_1,int param_2,int param_3)



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

        param_3 = FUN_004a90a0(param_2);

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

/* ===== FUN_004b9330 @ 0x004B9330 ===== */
/* PS2 candidate: reaper_give_all_spell_energy (conf 0.367) */



void FUN_004b9330(int param_1,int param_2)



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

        iVar1 = FUN_004a90a0(pfVar2[-1]);

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

/* ===== FUN_004b9390 @ 0x004B9390 ===== */
void FUN_004b9390(int param_1,int param_2,int param_3,int param_4)



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

        param_4 = FUN_004a90a0(param_2);

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

/* ===== FUN_004b95d0 @ 0x004B95D0 ===== */
/* PS2 candidate: reaper_can_cast_spell_specific__FP6OBJECTP13ObjSpecReaperi (conf 0.452) */



undefined4 FUN_004b95d0(int param_1,int param_2,int param_3)



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

    pfVar5 = (float *)FUN_00515db0();

    local_5c = *pfVar5;

    local_58 = pfVar5[1];

    local_54 = pfVar5[2];

    pfVar5 = (float *)FUN_00515dc0(2);

    local_50 = *pfVar5;

    local_4c = pfVar5[1];

    local_48 = pfVar5[2];

    local_5c = local_50 * fVar2 + local_5c;

    iVar4 = 0;

    local_58 = local_4c * fVar2 + local_58;

    local_54 = local_48 * fVar2 + local_54;

    for (puVar10 = DAT_00632d68; puVar10 != (undefined4 *)0x0; puVar10 = (undefined4 *)*puVar10) {

      iVar7 = puVar10[3];

      iVar6 = FUN_004ba1a0(iVar7,param_1);

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

      iVar4 = FUN_004a6160(iVar4);

      puVar10 = DAT_00632d98;

      if ((iVar4 == 0) &&

         (iVar4 = FUN_004a6180(*(undefined4 *)(param_2 + 0xf48)), puVar10 = DAT_00632d98, iVar4 == 0

         )) {

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

    iVar7 = FUN_004a61a0(*(undefined4 *)(iVar4 + 0x210));

    if (iVar7 != 0) {

      return 0;

    }

    *(int *)(param_2 + 0xf48) = iVar4;

    fVar1 = *(float *)(DAT_00632ed8 + 0x14d8);

    fVar11 = (float10)FUN_0050a610(iVar4 + 0xa0,param_1 + 0xa0);

    fVar12 = (float10)fVar1 * (float10)fVar1;

    break;

  case 0x16:

    iVar4 = FUN_004a8f50(0x26);

    fVar1 = *(float *)(iVar4 + 0x2c);

    fVar11 = (float10)FUN_0050a610(param_2 + 0xf4c,param_1 + 0xa0);

    fVar12 = (float10)fVar1 * (float10)fVar1;

    break;

  case 0x17:

    iVar4 = FUN_004a63a0(param_1);

    if (iVar4 != 0) {

      return 0;

    }

    iVar4 = *(int *)(param_2 + 0xe2c);

    goto LAB_004ba115;

  case 0x18:

    fVar11 = (float10)FUN_0050a5e0(param_1 + 0xa0,param_2 + 0xf4c);

    if ((float10)*(float *)(DAT_00632ed8 + 0x758) * (float10)*(float *)(DAT_00632ed8 + 0x758) <=

        fVar11) {

      return 0;

    }

    iVar4 = FUN_0040ce90();

    if (iVar4 == 0) {

      return 0;

    }

    iVar4 = FUN_00455b70(0,param_1,SQRT((float)fVar11),&local_68);

    if (iVar4 == 0) {

      return 1;

    }

    iVar4 = FUN_00456050(param_1);

    (*(code *)PTR_FUN_00580c18)(local_44,iVar4 + 0x294,*(undefined4 *)(iVar4 + 0x2dc));

    local_50 = -*(float *)(param_1 + 0x29c);

    local_4c = -*(float *)(param_1 + 0x2ac);

    local_48 = -*(float *)(param_1 + 700);

    FUN_0050a810(&local_50,&local_4c,&local_48);

    local_5c = fStack_34;

    local_58 = (float)uStack_24;

    local_54 = (float)uStack_14;

    iVar4 = FUN_00455920(0,param_1,SQRT((float)fVar11),&local_68,&local_5c,&local_50);

    if (iVar4 != 0) {

      return 0;

    }

    return 1;

  case 0x19:

    if (*(int *)(param_2 + 0xe80) != 0) {

      return 0;

    }

    iVar4 = FUN_004a8f50(0x27);

    fVar1 = *(float *)(iVar4 + 0x2c);

    fVar11 = (float10)FUN_0050a610(param_2 + 0xf4c,param_1 + 0xa0);

    fVar12 = (float10)fVar1 * (float10)fVar1;

    break;

  default:

    goto switchD_004b9600_caseD_1a;

  case 0x1b:

    if (DAT_00632bc4 != 0) {

      return 0;

    }

    fVar1 = *(float *)(DAT_00632ed8 + 0x14d0);

    fVar11 = (float10)FUN_0050a610(param_2 + 0xf4c,param_1 + 0xa0);

    fVar12 = (float10)fVar1 * (float10)fVar1;

    break;

  case 0x1c:

    iVar4 = FUN_004a8f50(0x25);

    fVar1 = *(float *)(iVar4 + 0x2c);

    fVar11 = (float10)FUN_0050a610(param_2 + 0xf4c,param_1 + 0xa0);

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

    pfVar5 = (float *)FUN_00515db0();

    local_5c = *pfVar5;

    local_58 = pfVar5[1];

    local_54 = pfVar5[2];

    pfVar5 = (float *)FUN_00515dc0(2);

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

        iVar6 = FUN_004ba1a0(iVar7,param_1);

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

    iVar4 = FUN_004a8f50(0x24);

    fVar1 = *(float *)(iVar4 + 0x2c);

    fVar11 = (float10)FUN_0050a610(*(int *)(param_2 + 0xf48) + 0xa0,param_1 + 0xa0);

    fVar12 = (float10)fVar1 * (float10)fVar1;

    break;

  case 0x1e:

    local_78 = *(float *)(DAT_00632ed8 + 0x908) * *(float *)(DAT_00632ed8 + 0x908);

    fVar1 = *(float *)(DAT_00632ed8 + 0x904);

    fVar2 = *(float *)(DAT_00632ed8 + 0x900);

    pfVar5 = (float *)FUN_00515db0();

    local_68 = *pfVar5;

    local_64 = pfVar5[1];

    local_60 = pfVar5[2];

    pfVar5 = (float *)FUN_00515dc0(2);

    local_50 = *pfVar5;

    local_4c = pfVar5[1];

    local_48 = pfVar5[2];

    local_68 = local_50 * fVar2 + local_68;

    iVar4 = 0;

    local_64 = local_4c * fVar2 + local_64;

    local_60 = local_48 * fVar2 + local_60;

    for (puVar10 = DAT_00632d68; puVar10 != (undefined4 *)0x0; puVar10 = (undefined4 *)*puVar10) {

      iVar7 = puVar10[3];

      iVar6 = FUN_004ba1a0(iVar7,param_1);

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

    iVar4 = FUN_004a6160(iVar4);

    if ((iVar4 == 0) && (iVar4 = FUN_004a6180(*(undefined4 *)(param_2 + 0xf48)), iVar4 == 0)) {

      iVar4 = *(int *)(*(int *)(param_2 + 0xf48) + 4);

      if ((((iVar4 != 8) && (((iVar4 != 0x438 && (iVar4 != 0x29a)) && (iVar4 != 0x232)))) &&

          ((iVar4 != 0xb || (iVar4 = FUN_004ef510(*(int *)(param_2 + 0xf48)), iVar4 == 0)))) &&

         ((*(int *)(*(int *)(param_2 + 0xf48) + 4) != 0xd7 ||

          (iVar4 = FUN_004d7b80(*(int *)(param_2 + 0xf48)), iVar4 == 0)))) {

        iVar4 = FUN_004a6100(*(undefined4 *)(param_2 + 0xf48));

        if (iVar4 == 0) {

          return 0;

        }

        iVar4 = FUN_004d49c0(*(undefined4 *)(param_2 + 0xf48));

        if (iVar4 == 0) {

          return 0;

        }

      }

    }

    iVar4 = FUN_004a8f50(0x14);

    fVar1 = *(float *)(iVar4 + 0x2c);

    fVar11 = (float10)FUN_0050a610(*(int *)(param_2 + 0xf48) + 0xa0,param_1 + 0xa0);

    fVar12 = (float10)fVar1 * (float10)fVar1;

    break;

  case 0x1f:

    fVar1 = *(float *)(DAT_00632ed8 + 0x14cc);

    fVar11 = (float10)FUN_0050a610(param_2 + 0xf4c,param_1 + 0xa0);

    fVar12 = (float10)fVar1 * (float10)fVar1;

    break;

  case 0x21:

    if ((*(uint *)(param_1 + 0xd8) & 0x80000) == 0) {

      return 0;

    }

    fVar1 = *(float *)(DAT_00632ed8 + 0x14d4);

    fVar11 = (float10)FUN_0050a610(param_2 + 0xf4c,param_1 + 0xa0);

    fVar12 = (float10)fVar1 * (float10)fVar1;

    break;

  case 0x49:

    iVar4 = FUN_004a8f50(0x33);

    fVar1 = *(float *)(iVar4 + 0x2c);

    fVar11 = (float10)FUN_0050a610(param_2 + 0xf4c,param_1 + 0xa0);

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

/* ===== FUN_004ba1a0 @ 0x004BA1A0 ===== */
/* PS2 candidate: reaper_xhair_validate__FP6OBJECTPv (conf 0.466) */



undefined4 FUN_004ba1a0(int param_1,int param_2)



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

  

  iVar1 = FUN_004a6220(param_1);

  if ((((iVar1 == 0) && (iVar1 = FUN_004a6200(param_1), iVar1 == 0)) &&

      (iVar1 = FUN_004a6300(param_1), iVar1 == 0)) && (iVar1 = FUN_004a6290(param_1), iVar1 == 0)) {

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

    fVar3 = (float10)FUN_00516290(&local_c,&local_18);

    if ((float10)0.0 <= fVar3) {

      return 1;

    }

  }

  return 0;

}

/* ===== FUN_004ba2f0 @ 0x004BA2F0 ===== */
undefined4 FUN_004ba2f0(int param_1,int param_2,int param_3)



{

  int iVar1;

  

  if (((**(byte **)(param_1 + 0x104) & 0x40) == 0) &&

     ((iVar1 = *(int *)(param_1 + 0x210), iVar1 == 0 ||

      ((*(int *)(iVar1 + 0x1e0) != 1 && (*(int *)(iVar1 + 0x1e0) != 0x4c)))))) {

    iVar1 = FUN_004a6120(iVar1);

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

      iVar3 = FUN_00456050(param_1);

      if (iVar3 != 0) {

        *(uint *)(iVar3 + 0xd8) = *(uint *)(iVar3 + 0xd8) & 0xbfffffff;

      }

    }

    FUN_00495700(0x34c,param_1);

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

  PhysicsExZeroForce(param_1);

  FUN_0050a610(param_1 + 0xa0,puVar1);

  if (*(int *)(iVar2 + 8) == 0) {

    fVar4 = (float10)FUN_00543e70();

    fVar4 = fVar4 * (float10)*(float *)(DAT_00632ed8 + 0xfe0);

  }

  else {

    fVar4 = (float10)FUN_00543e70();

    fVar4 = fVar4 * (float10)*(float *)(DAT_00632ed8 + 0x748);

  }

  local_8 = 0;

  local_c = 0;

  local_4 = (*(float *)(*(int *)(param_1 + 0x104) + 4) / *(float *)(*(int *)(param_1 + 0x104) + 8))

            * -32.17405;

  FUN_004a4480(param_1 + 0x128,param_1 + 0xa0,puVar1,&local_c,(float)fVar4);

  return (float10)(float)fVar4;

}

/* ===== FUN_004ba5e0 @ 0x004BA5E0 ===== */
/* PS2 candidate: reaper_release_shrink (conf 0.618) */



void FUN_004ba5e0(undefined4 param_1,int *param_2)



{

  int iVar1;

  

  iVar1 = 4;

  do {

    if ((param_2[5] == 0) && (*param_2 != 0)) {

      FUN_00457100(0xe,-(float)param_2[2],*param_2,param_1,0,0);

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

            iVar4 = FUN_004a61a0(iVar4);

            if (iVar4 != 0) {

              piVar1 = (int *)(*(int *)(*param_2 + 0x100) + 0x354);

              *piVar1 = *piVar1 + -1;

            }

          }

          iVar4 = FUN_004a6180(*param_2);

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

      fVar6 = (float10)FUN_00518b70(iVar4,0);

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

              FUN_00457100(0xe,-(float)param_2[2],*param_2,param_1,0,0);

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

              iVar4 = FUN_004a61a0(iVar4);

              if (iVar4 != 0) {

                piVar1 = (int *)(*(int *)(*param_2 + 0x100) + 0x354);

                *piVar1 = *piVar1 + -1;

              }

            }

            iVar5 = FUN_004a6180(*param_2);

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

    fVar1 = (float10)FUN_00518b70(*param_2,0);

    fVar1 = (float10)*param_3 - fVar1;

    *param_3 = (float)fVar1;

    if (fVar1 < (float10)0.0 != (fVar1 == (float10)0.0)) {

      fxb_firewall_create(param_1,param_2,param_4,param_5,0xffffffff);

      *param_3 = *(float *)(DAT_00632ed8 + 0x784);

    }

  }

  return;

}

/* ===== FUN_004ba920 @ 0x004BA920 ===== */
/* PS2 candidate: reaper_stop_looping_effects (conf 0.362) */



void FUN_004ba920(int param_1)



{

  byte *pbVar1;

  int iVar2;

  

  pbVar1 = *(byte **)(param_1 + 0x100);

  FUN_00495ee0(pbVar1 + 0xff0);

  FUN_00448920(*(undefined4 *)(pbVar1 + 0xe34));

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

    iVar2 = FUN_00456050(param_1);

    *(uint *)(iVar2 + 0xd8) = *(uint *)(iVar2 + 0xd8) & 0xbfffffff;

  }

  return;

}

/* ===== FUN_004ba990 @ 0x004BA990 ===== */
/* PS2 candidate: reaper_cloak_damage (conf 0.431) */



void FUN_004ba990(int param_1,float param_2,undefined4 param_3)



{

  int iVar1;

  undefined4 *puVar2;

  int iVar3;

  float10 fVar4;

  

  for (puVar2 = DAT_00632d6c; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {

    iVar1 = puVar2[3];

    if (((*(int *)(iVar1 + 0x18c) != *(int *)(param_1 + 0x18c)) &&

        ((((((iVar3 = FUN_004a6180(iVar1), iVar3 != 0 || (iVar3 = FUN_004a6160(iVar1), iVar3 != 0))

            || (iVar3 = *(int *)(iVar1 + 4), iVar3 == 0xb)) || ((iVar3 == 8 || (iVar3 == 0x438))))

          || ((iVar3 == 0xe5 || ((iVar3 == 0x49 || (iVar3 == 0xe6)))))) || (iVar3 == 0x29a)))) &&

       (fVar4 = (float10)FUN_0050a610(iVar1 + 0xa0,param_1 + 0xa0),

       fVar4 < (float10)param_2 * (float10)param_2)) {

      iVar3 = FUN_0052e480(param_1);

      if (iVar3 != 0) {

        FUN_00456d00(iVar1,param_1,0xd,param_3,0,0);

      }

      *(uint *)(iVar1 + 0xd8) = *(uint *)(iVar1 + 0xd8) | 0x800;

    }

  }

  return;

}

/* ===== FUN_004baa70 @ 0x004BAA70 ===== */
/* PS2 candidate: reaper_init__FP6OBJECT (conf 0.494) */



void FUN_004baa70(int param_1)



{

  int iVar1;

  int iVar2;

  

  iVar1 = *(int *)(param_1 + 0x100);

  *(int *)(param_1 + 0x104) = iVar1 + 0xd00;

  FUN_004a1740(param_1);

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

    iVar2 = FUN_0052e4b0(iVar1);

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

      FUN_00530f10(iVar1,9,0,0,1,&local_24);

    }

    iVar2 = FUN_0052e530(iVar1);

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

        FUN_00530f10(iVar1,4,0,4,2,&local_24);

        return;

      }

      param_1._0_3_ = CONCAT12(*(undefined1 *)(iVar1 + 0x208),*(undefined2 *)(iVar1 + 0x20a));

      FUN_00530f10(iVar1,0,0,3,3,&param_1);

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

/* ===== FUN_004bc640 @ 0x004BC640 ===== */
int FUN_004bc640(undefined4 param_1,float param_2,float param_3,float param_4)



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

  

  pfVar14 = (float *)FUN_00515db0();

  fVar1 = *pfVar14;

  fVar2 = pfVar14[1];

  fVar3 = pfVar14[2];

  pfVar14 = (float *)FUN_00515dc0(2);

  fVar4 = *pfVar14;

  fVar5 = pfVar14[1];

  fVar6 = pfVar14[2];

  iVar16 = 0;

  fVar9 = param_3 - param_2;

  param_3 = param_4;

  for (puVar8 = DAT_00632d68; puVar8 != (undefined4 *)0x0; puVar8 = (undefined4 *)*puVar8) {

    iVar7 = puVar8[3];

    iVar15 = FUN_004ba1a0(iVar7,param_1);

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

/* ===== FUN_004bc800 @ 0x004BC800 ===== */
void FUN_004bc800(int param_1,float *param_2,undefined4 *param_3)



{

  int iVar1;

  undefined1 local_44 [16];

  undefined4 uStack_34;

  undefined4 uStack_24;

  undefined4 uStack_14;

  

  iVar1 = FUN_00456050(param_1);

  (*(code *)PTR_FUN_00580c18)(local_44,iVar1 + 0x294,*(undefined4 *)(iVar1 + 0x2dc));

  *param_2 = -*(float *)(param_1 + 0x29c);

  param_2[1] = -*(float *)(param_1 + 0x2ac);

  param_2[2] = -*(float *)(param_1 + 700);

  FUN_0050a810(param_2,param_2 + 1,param_2 + 2);

  *param_3 = uStack_34;

  param_3[1] = uStack_24;

  param_3[2] = uStack_14;

  return;

}

/* ===== FUN_004bc880 @ 0x004BC880 ===== */
void FUN_004bc880(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,

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

  

  iVar1 = FUN_00456050(param_1);

  (*(code *)PTR_FUN_00580c18)(local_44,iVar1 + 0x294,*(undefined4 *)(iVar1 + 0x2dc));

  fStack_5c = -*(float *)(param_1 + 0x29c);

  fStack_58 = -*(float *)(param_1 + 0x2ac);

  fStack_54 = -*(float *)(param_1 + 700);

  FUN_0050a810(&fStack_5c,&fStack_58,&fStack_54);

  uStack_50 = uStack_34;

  uStack_4c = uStack_24;

  uStack_48 = uStack_14;

  FUN_00455920(param_2,param_3,param_4,param_5,&uStack_50,&fStack_5c);

  return;

}

/* ===== FUN_004bc930 @ 0x004BC930 ===== */
/* PS2 candidate: reaper_turbo_towards_moving_target__FP6OBJECT (conf 0.451) */



void FUN_004bc930(int param_1)



{

  uint *puVar1;

  int iVar2;

  int iVar3;

  undefined4 uVar4;

  float10 fVar5;

  

  iVar2 = *(int *)(param_1 + 0x100);

  FUN_0050a610(param_1 + 0xa0,*(int *)(iVar2 + 0xc) + 0xa0);

  iVar3 = *(int *)(iVar2 + 0xc);

  *(undefined4 *)(iVar2 + 0x1c) = *(undefined4 *)(iVar3 + 0xa0);

  *(undefined4 *)(iVar2 + 0x20) = *(undefined4 *)(iVar3 + 0xa4);

  *(undefined4 *)(iVar2 + 0x24) = *(undefined4 *)(iVar3 + 0xa8);

  fVar5 = (float10)FUN_00543e70();

  fVar5 = fVar5 * (float10)*(float *)(DAT_00632ed8 + 0xfe0);

  if (fVar5 < (float10)*(float *)(iVar2 + 0x28) != (fVar5 == (float10)*(float *)(iVar2 + 0x28))) {

    *(undefined4 *)(iVar2 + 0xf40) = 1;

    iVar3 = FUN_004ba1a0(*(undefined4 *)(iVar2 + 0xc),param_1);

    if ((iVar3 != 0) && ((*(uint *)(*(int *)(iVar2 + 0xc) + 0x1c8) & 0x400000) != 0)) {

      iVar3 = FUN_004a61a0(*(int *)(iVar2 + 0xc));

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

      FUN_0053d9e0(*(int *)(iVar2 + 0x50) + 0x294);

      FUN_004a2c50(*(int *)(iVar2 + 0x50) + 0x294,*(undefined4 *)(iVar2 + 0xc),0x40000000);

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

    FUN_0040d790();

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

  FUN_0040d7e0(local_44);

  AudioSetSpeakerConfig__F14SPEAKER_SYSTEM(param_1);

  return;

}

/* ===== FUN_004bcb30 @ 0x004BCB30 ===== */
/* PS2 candidate: reaper_set_pitch__FP6OBJECT (conf 0.374) */



void FUN_004bcb30(int param_1)



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

      fVar2 = (float10)FUN_0050a490(param_1 + 0xb8,param_1 + 0xa0);

      local_4 = (float)fVar2;

    }

    else if (iVar1 == 0x36) {

      fVar2 = (float10)FUN_0050a490(param_1 + 0xb8,param_1 + 0xa0);

      local_8 = (float)fVar2;

    }

    else if (iVar1 == 0x37) {

      fVar2 = (float10)FUN_0050a490(param_1 + 0xb8,param_1 + 0xa0);

      local_8 = (float)-fVar2;

    }

  }

  fVar2 = (float10)FUN_00518b70(param_1,0,0x461c4000,local_4,param_1 + 0xcc);

  FUN_004515b0((float)(fVar2 * (float10)100.0));

  fVar2 = (float10)FUN_00518b70(param_1,0,0x461c4000,local_8,param_1 + 0xd0);

  FUN_004515b0((float)(fVar2 * (float10)100.0));

  return;

}

/* ===== FUN_004bcc30 @ 0x004BCC30 ===== */
void FUN_004bcc30(int param_1)



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

          FUN_004a17c0(*(undefined4 *)(param_1 + 0x104),*(undefined4 *)(iVar2 + 0x60));

          *(float *)(*(int *)(param_1 + 0x104) + 0x20) =

               *(float *)(DAT_00632ed8 + 0x800) + *(float *)(*(int *)(param_1 + 0x104) + 0x20);

        }

        fVar5 = (float10)FUN_00518b70(param_1,0);

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

/* ===== FUN_004bce60 @ 0x004BCE60 ===== */
/* PS2 candidate: reaper_walkrun_go__FP6OBJECT (conf 0.484) */



void FUN_004bce60(int param_1)



{

  uint *puVar1;

  float fVar2;

  float fVar3;

  byte bVar4;

  uint *puVar5;

  float fVar6;

  float fVar7;

  bool bVar8;

  undefined4 *puVar9;

  int iVar10;

  undefined4 uVar11;

  uint *puVar12;

  int iVar13;

  int iVar14;

  float *pfVar15;

  int iVar16;

  uint uVar17;

  float *pfVar18;

  float *pfVar19;

  float10 fVar20;

  char *pcVar21;

  undefined1 *puVar22;

  undefined1 local_34 [4];

  undefined4 local_30;

  undefined4 local_2c;

  undefined4 local_28;

  

  puVar5 = *(uint **)(param_1 + 0x100);

  *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) | 0x40;

  if (DAT_00632bc4 == 0) {

    bVar4 = **(byte **)(param_1 + 0x104);

    fVar6 = *(float *)(param_1 + 0x130);

    FUN_004a1c50(param_1);

    FUN_004a1bd0(param_1);

    FUN_004a4360(param_1);

    fVar20 = (float10)FUN_00518b70(param_1,0);

    FUN_00403e60(param_1,(float)fVar20);

    if ((**(byte **)(param_1 + 0x104) & 0x40) == 0) {

      if ((*(uint *)(param_1 + 0xe0) & 0x2000000) == 0) {

        if ((*(uint *)(param_1 + 0xd8) & 0x80000) == 0) {

          if ((((*puVar5 & 2) != 0) && (puVar5[0x3c9] == 0)) &&

             ((iVar10 = *(int *)(*(int *)(param_1 + 0x100) + 0x5c), iVar10 < 0x31 ||

              ((0x37 < iVar10 && (iVar10 != 0x4c)))))) {

            iVar10 = FUN_00456050(param_1);

            if (iVar10 != 0) {

              iVar16 = FUN_0052aa70();

              if ((iVar16 == 0) || (*(float *)(param_1 + 0x278) < *(float *)(param_1 + 0x1c0))) {

                *(uint *)(iVar10 + 0xd8) = *(uint *)(iVar10 + 0xd8) & 0xbfffffff;

              }

              *puVar5 = *puVar5 & 0xfffffffd;

            }

            FUN_00495700(0x34c,param_1);

            puVar5[0x3c7] = *(uint *)(DAT_00632ed8 + 0x828);

            *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xffff3fff;

            puVar5[0x3c9] = 0;

          }

        }

        else {

          if ((puVar5[0x38b] == 0) &&

             (((iVar10 = FUN_0052aa70(), iVar10 == 0 ||

               (*(float *)(param_1 + 0x278) < *(float *)(param_1 + 0x1c0))) &&

              (iVar10 = FUN_00456050(param_1), iVar10 != 0)))) {

            *(uint *)(iVar10 + 0xd8) = *(uint *)(iVar10 + 0xd8) & 0xbfffffff;

          }

          FUN_00495700(0x34c,param_1);

          puVar5[0x3c7] = *(uint *)(DAT_00632ed8 + 0x828);

          *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xffff3fff;

          *puVar5 = *puVar5 & 0xfffffffd;

          puVar5[0x3c9] = 0;

        }

      }

      else {

        if ((((*(uint *)(param_1 + 0xd8) & 0x100) == 0) && (puVar5[0x3c8] == 0)) &&

           ((iVar10 = *(int *)(*(int *)(param_1 + 0x100) + 0x5c), iVar10 < 0x31 ||

            ((0x37 < iVar10 && (iVar10 != 0x4c)))))) {

          if ((puVar5[0x38b] == 0) &&

             (((iVar10 = FUN_0052aa70(), iVar10 == 0 ||

               (*(float *)(param_1 + 0x278) < *(float *)(param_1 + 0x1c0))) &&

              (iVar10 = FUN_00456050(param_1), iVar10 != 0)))) {

            *(uint *)(iVar10 + 0xd8) = *(uint *)(iVar10 + 0xd8) & 0xbfffffff;

          }

          FUN_00495700(0x34c,param_1);

          puVar5[0x3c7] = *(uint *)(DAT_00632ed8 + 0x828);

          *puVar5 = *puVar5 & 0xfffffffd;

          *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xffff3fff;

          puVar5[0x3c9] = 0;

        }

        *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xfdffffff;

      }

    }

    FUN_004a2b90(param_1,*(undefined4 *)(DAT_00632ed8 + 0x720),*(undefined4 *)(DAT_00632ed8 + 0x724)

                );

    if ((*(char *)(param_1 + 0x20a) == '\0') && (*(char *)(param_1 + 0x20b) == '\0')) {

      uVar11 = 1;

    }

    else {

      uVar11 = 0;

    }

    FUN_004a2240(param_1,uVar11);

    if ((**(byte **)(param_1 + 0x104) & 0x40) != 0) {

      if (((~bVar4 & 0x40) != 0) && (fVar6 < -*(float *)(DAT_00632ed8 + 0x8e4))) {

        local_30 = *(undefined4 *)(param_1 + 0xa0);

        local_2c = *(undefined4 *)(param_1 + 0xa4);

        puVar22 = local_34;

        uVar11 = 8;

        pcVar21 = s_FXB_Splash_00560ffc;

        local_28 = 0;

        fx_get_free_effect__Fv();

        iVar10 = crt_rand_scaled(100,pcVar21,uVar11,puVar22);

        if (iVar10 < 0x32) {

          uVar11 = 0x6df;

        }

        else {

          uVar11 = 0x6e0;

        }

        sound_play_player(uVar11,param_1);

      }

      if ((char)((uint)*(undefined4 *)(param_1 + 0xe0) >> 8) < '\0') {

        FUN_004a26f0(param_1,*(undefined4 *)(DAT_00632ed8 + 0x80c),

                     *(undefined4 *)(DAT_00632ed8 + 0x80c),*(undefined4 *)(DAT_00632ed8 + 0x810),

                     *(undefined4 *)(DAT_00632ed8 + 0x814),1);

      }

      else {

        FUN_004a26f0(param_1,*(undefined4 *)(DAT_00632ed8 + 0x818),

                     *(undefined4 *)(DAT_00632ed8 + 0x818),*(undefined4 *)(DAT_00632ed8 + 0x81c),

                     *(undefined4 *)(DAT_00632ed8 + 0x820),1);

      }

      goto LAB_004bd2e5;

    }

    if ((*(uint *)(param_1 + 0xe0) & 0x100) == 0) {

      if (puVar5[0x38b] == 0) {

        FUN_004a26f0(param_1,*(undefined4 *)(DAT_00632ed8 + 0x728),

                     *(undefined4 *)(DAT_00632ed8 + 0x728),*(undefined4 *)(DAT_00632ed8 + 0x72c),

                     *(undefined4 *)(DAT_00632ed8 + 0x730),*(uint *)(param_1 + 0xd8) & 0x10);

      }

      else {

        FUN_004a26f0(param_1,*(undefined4 *)(DAT_00632ed8 + 0x740),

                     *(undefined4 *)(DAT_00632ed8 + 0x740),*(undefined4 *)(DAT_00632ed8 + 0x738),

                     *(undefined4 *)(DAT_00632ed8 + 0x73c),*(uint *)(param_1 + 0xd8) & 0x10);

      }

      goto LAB_004bd2e5;

    }

LAB_004bd2f0:

    bVar8 = true;

    if (puVar5[0x38b] != 0) goto LAB_004bd302;

  }

  else {

    fVar20 = (float10)FUN_00518b70(param_1,0);

    FUN_00403e60(param_1,(float)fVar20);

LAB_004bd2e5:

    if ((*(uint *)(param_1 + 0xe0) & 0x100) != 0) goto LAB_004bd2f0;

LAB_004bd302:

    bVar8 = false;

  }

  if ((DAT_00632a88 == param_1) && (DAT_00632bb4 != 0)) {

    return;

  }

  if (*(float *)(param_1 + 200) < 360.0) {

    if (*(float *)(param_1 + 200) < 0.0) {

      fVar6 = *(float *)(param_1 + 200) + 360.0;

      goto LAB_004bd35c;

    }

  }

  else {

    fVar6 = *(float *)(param_1 + 200) - 360.0;

LAB_004bd35c:

    *(float *)(param_1 + 200) = fVar6;

  }

  if (puVar5[0x1a] == 0xffffffff) {

    puVar5[0x1a] = 0;

    do {

      puVar12 = puVar5 + puVar5[0x1a] * 10 + 0x1b;

      *puVar12 = *(uint *)(param_1 + 0xa0);

      puVar12[1] = *(uint *)(param_1 + 0xa4);

      puVar12[2] = *(uint *)(param_1 + 0xa8);

      puVar12[3] = *(uint *)(param_1 + 200);

      puVar12[4] = *(uint *)(param_1 + 0x10);

      puVar12[5] = *(uint *)(param_1 + 0x14);

      puVar12[6] = *(uint *)(param_1 + 0x2c);

      puVar12[7] = *(uint *)(param_1 + 0x58);

      puVar12[8] = *(uint *)(param_1 + 0x5c);

      puVar5[puVar5[0x1a] * 10 + 0x24] = (uint)((float)(int)puVar5[0x1a] * 0.025);

      uVar17 = puVar5[0x1a];

      puVar5[0x1a] = uVar17 + 1;

    } while ((int)(uVar17 + 1) < 0x50);

    puVar5[0x1a] = 0x4f;

  }

  else if (puVar5[0x1a] == 0) {

    puVar12 = puVar5 + 0x331;

    uVar17 = 0;

    goto LAB_004bd3f4;

  }

  uVar17 = puVar5[0x1a];

  puVar12 = puVar5 + uVar17 * 10 + 0x11;

LAB_004bd3f4:

  puVar1 = puVar5 + uVar17 * 10 + 0x1b;

  if ((float)puVar5[uVar17 * 10 + 0x24] - (float)puVar12[9] < 0.025) {

    *puVar1 = *(uint *)(param_1 + 0xa0);

    puVar1[1] = *(uint *)(param_1 + 0xa4);

    puVar1[2] = *(uint *)(param_1 + 0xa8);

    puVar1[3] = *(uint *)(param_1 + 200);

    puVar1[4] = *(uint *)(param_1 + 0x10);

    puVar1[5] = *(uint *)(param_1 + 0x14);

    puVar1[6] = *(uint *)(param_1 + 0x2c);

    puVar1[7] = *(uint *)(param_1 + 0x58);

    puVar1[8] = *(uint *)(param_1 + 0x5c);

    uVar17 = puVar5[0x1a];

    fVar20 = (float10)FUN_00518b70(param_1,0);

    puVar5[uVar17 * 10 + 0x24] = (uint)(float)(fVar20 + (float10)(float)puVar5[uVar17 * 10 + 0x24]);

    puVar9 = DAT_00632d74;

  }

  else {

    fVar6 = (float)puVar1[9];

    puVar5[0x1a] = uVar17 + 1;

    if (0x4f < (int)(uVar17 + 1)) {

      puVar5[0x1a] = 0;

    }

    puVar12 = puVar5 + puVar5[0x1a] * 10 + 0x1b;

    *puVar12 = *(uint *)(param_1 + 0xa0);

    puVar12[1] = *(uint *)(param_1 + 0xa4);

    puVar12[2] = *(uint *)(param_1 + 0xa8);

    puVar12[3] = *(uint *)(param_1 + 200);

    puVar12[4] = *(uint *)(param_1 + 0x10);

    puVar12[5] = *(uint *)(param_1 + 0x14);

    puVar12[6] = *(uint *)(param_1 + 0x2c);

    puVar12[7] = *(uint *)(param_1 + 0x58);

    puVar12[8] = *(uint *)(param_1 + 0x5c);

    fVar20 = (float10)FUN_00518b70(param_1,0);

    puVar5[puVar5[0x1a] * 10 + 0x24] = (uint)(float)(fVar20 + (float10)fVar6);

    puVar9 = DAT_00632d74;

  }

  do {

    if (puVar9 == (undefined4 *)0x0) {

      return;

    }

    iVar10 = puVar9[3];

    if ((*(int *)(iVar10 + 0x1e0) == 0x3e) && (*(int *)(iVar10 + 0x274) == param_1)) {

      iVar16 = *(int *)(iVar10 + 0x174);

      uVar17 = puVar5[0x1a];

      fVar6 = *(float *)(DAT_00632ed8 + 0x500);

      iVar13 = FUN_00456050(iVar10);

      if ((bVar8) && (iVar14 = object_volume_sfx(param_1), iVar14 == 0)) {

        pfVar18 = (float *)(puVar5 + 0x1b);

        fVar6 = (float)puVar5[uVar17 * 10 + 0x24] - (float)(iVar16 + 1) * fVar6;

        pfVar19 = pfVar18 + uVar17 * 10;

        do {

          pfVar15 = pfVar19;

          pfVar19 = (float *)(puVar5 + 0x331);

          if (pfVar15 != pfVar18) {

            pfVar19 = pfVar15 + -10;

          }

          if (pfVar19 == pfVar18 + uVar17 * 10) goto LAB_004bd5ab;

        } while (fVar6 < pfVar19[9]);

        fVar6 = (fVar6 - pfVar19[9]) / (pfVar15[9] - pfVar19[9]);

        fVar7 = 1.0 - fVar6;

        *(float *)(iVar10 + 0xa0) = fVar7 * *pfVar19 + fVar6 * *pfVar15;

        *(float *)(iVar10 + 0xa4) = fVar7 * pfVar19[1] + fVar6 * pfVar15[1];

        *(float *)(iVar10 + 0xa8) = fVar7 * pfVar19[2] + fVar6 * pfVar15[2];

        if (ABS(pfVar19[3] - pfVar15[3]) <= 180.0) {

          *(float *)(iVar10 + 200) = fVar7 * pfVar19[3] + fVar6 * pfVar15[3];

        }

        else {

          fVar2 = pfVar19[3];

          if (pfVar19[3] < 180.0) {

            fVar2 = fVar2 + 360.0;

          }

          fVar3 = pfVar15[3];

          if (pfVar15[3] < 180.0) {

            fVar3 = fVar3 + 360.0;

          }

          fVar2 = fVar2 * fVar7 + fVar3 * fVar6;

          *(float *)(iVar10 + 200) = fVar2;

          if (360.0 <= fVar2) {

            *(float *)(iVar10 + 200) = fVar2 - 360.0;

          }

        }

        if (pfVar15[4] != 3.5593e-43) {

          FUN_004034a0(iVar10,pfVar15[4],4,0,0,0);

          if (pfVar19[4] == pfVar15[4]) {

            *(float *)(iVar10 + 0x14) = fVar7 * pfVar19[5] + fVar6 * pfVar15[5];

            fVar6 = fVar7 * pfVar19[6] + fVar6 * pfVar15[6];

            *(float *)(iVar10 + 0x2c) = fVar6;

            if (0.0 < fVar6) {

              pfVar18 = (float *)(iVar10 + 0x10);

              pfVar19 = (float *)(iVar10 + 0x58);

              for (iVar16 = 9; iVar16 != 0; iVar16 = iVar16 + -1) {

                *pfVar19 = *pfVar18;

                pfVar18 = pfVar18 + 1;

                pfVar19 = pfVar19 + 1;

              }

              *(float *)(iVar10 + 0x58) = pfVar15[7];

              *(float *)(iVar10 + 0x5c) = pfVar15[8];

            }

          }

          else {

            *(float *)(iVar10 + 0x14) = fVar6 * pfVar15[5];

            if (pfVar15[6] <= 0.0) {

              *(undefined4 *)(iVar10 + 0x2c) = 0;

            }

            else {

              pfVar18 = (float *)(iVar10 + 0x10);

              pfVar19 = (float *)(iVar10 + 0x58);

              for (iVar16 = 9; iVar16 != 0; iVar16 = iVar16 + -1) {

                *pfVar19 = *pfVar18;

                pfVar18 = pfVar18 + 1;

                pfVar19 = pfVar19 + 1;

              }

              *(float *)(iVar10 + 0x58) = pfVar15[7];

              *(float *)(iVar10 + 0x5c) = pfVar15[8];

              *(float *)(iVar10 + 0x2c) = fVar6 * pfVar15[6] + fVar7;

            }

          }

        }

        *(uint *)(iVar10 + 0xd8) = *(uint *)(iVar10 + 0xd8) & 0xbfffffff;

      }

      else {

LAB_004bd5ab:

        *(uint *)(iVar10 + 0xd8) = *(uint *)(iVar10 + 0xd8) | 0x40000000;

        if (iVar13 != 0) {

          *(uint *)(iVar13 + 0xd8) = *(uint *)(iVar13 + 0xd8) | 0x40000000;

        }

      }

    }

    puVar9 = (undefined4 *)*puVar9;

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

      uVar6 = FUN_00456050(param_1);

      if (((*puVar2 & 2) == 0) && (iVar5 = FUN_0040cf70(), iVar5 == 0)) {

        FUN_004a76e0(uVar6,0,local_30);

        fx_get_free_effect__Fv();

      }

      uVar6 = FUN_004a8fb0(puVar2[puVar2[0x36d] * 2 + 0x35c],1);

      FUN_00455c80(iVar4,1,uVar6);

      iVar5 = FUN_00456050(iVar4);

      if ((*puVar2 & 2) != 0) {

        *(uint *)(iVar5 + 0xd8) = *(uint *)(iVar5 + 0xd8) | 0x40000000;

      }

    }

    else {

      *(uint *)(param_1 + 0xe0) = uVar3 & 0xffffff7f;

      if (puVar2[0x38e] != 0) {

        FUN_00448920(puVar2[0x38e]);

        puVar2[0x38e] = 0;

      }

      *(uint *)(iVar4 + 0xe0) = *(uint *)(iVar4 + 0xe0) & 0xffffffbf;

      *puVar2 = *puVar2 & 0xfffffffe;

      *(uint *)(iVar4 + 0xe0) = *(uint *)(iVar4 + 0xe0) | 0x8000000;

    }

  }

  else {

    iVar5 = FUN_0040cf70();

    if (iVar5 == 0) {

      uVar6 = FUN_00456050(iVar4);

      FUN_004a76e0(uVar6,0,local_30);

      fx_get_free_effect__Fv();

    }

    puVar7 = *(uint **)(iVar4 + 0x100);

    *(uint *)(iVar4 + 0xe0) = *(uint *)(iVar4 + 0xe0) & 0xffffff7f;

    if (puVar7[0x38e] != 0) {

      FUN_00448920(puVar7[0x38e]);

      puVar7[0x38e] = 0;

    }

    *(uint *)(iVar4 + 0xe0) = *(uint *)(iVar4 + 0xe0) & 0xffffffbf;

    *puVar7 = *puVar7 & 0xfffffffe;

    uVar6 = FUN_004a8fb0(puVar2[puVar2[0x36d] * 2 + 0x35c],1);

    FUN_00455c80(iVar4,1,uVar6);

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

    FUN_00495700(0x36c,iVar4);

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

/* ===== FUN_004bdaa0 @ 0x004BDAA0 ===== */
/* PS2 candidate: reaper_select_bow (conf 0.359) */



void FUN_004bdaa0(uint param_1)



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

      uVar4 = FUN_004a8fb0(puVar1[puVar1[0x36d] * 2 + 0x35c],1);

      FUN_00455c80(uVar3,1,uVar4);

      iVar5 = FUN_00456050(uVar3);

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

/* ===== FUN_004bdbf0 @ 0x004BDBF0 ===== */
/* PS2 candidate: reaper_select_sword (conf 0.358) */



void FUN_004bdbf0(int param_1)



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

    FUN_00455c80(param_1,1,0x29d);

    iVar4 = FUN_00456050(param_1);

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

    FUN_00448920(puVar5[0x38e]);

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

    FUN_00495700(0x36c,param_1);

    puVar2[0x3fd] = 0;

    *(uint *)(puVar2[0x3e4] + 0xd8) = *(uint *)(puVar2[0x3e4] + 0xd8) | 0x40000000;

  }

  if (puVar2[0x3e4] != 0) {

    FUN_00495700(0x36c,param_1);

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

/* ===== FUN_004bddb0 @ 0x004BDDB0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* PS2 candidate: reaper_fire_logic__FP6OBJECT (conf 0.383) */



void FUN_004bddb0(int param_1)



{

  int iVar1;

  uint *puVar2;

  bool bVar3;

  float10 fVar4;

  

  iVar1 = *(int *)(param_1 + 0x100);

  if (param_1 == DAT_00632a88) {

    _DAT_00632ba0 = 0;

  }

  fVar4 = (float10)FUN_00518b70(param_1,0);

  *(float *)(iVar1 + 0xf1c) = (float)((float10)*(float *)(iVar1 + 0xf1c) - fVar4);

  if ((*(byte *)(param_1 + 0x20c) & 0x40) != 0) {

    FUN_004b9120(param_1,1);

  }

  if (*(char *)(param_1 + 0x20c) < '\0') {

    FUN_004b9120(param_1,0);

  }

  if ((DAT_00632bc0 != 0) || (DAT_00632bc4 != 0)) {

    puVar2 = *(uint **)(param_1 + 0x100);

    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xffffff7f;

    if (puVar2[0x38e] != 0) {

      FUN_00448920(puVar2[0x38e]);

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

      FUN_004beee0(param_1);

      return;

    }

    if (DAT_00632bc0 == 0) {

      FUN_004c0810(param_1);

    }

  }

  else {

    puVar2 = *(uint **)(param_1 + 0x100);

    if ((*(uint *)(param_1 + 0x20c) & 0x2000000) == 0) {

      if ((char)((uint)*(undefined4 *)(param_1 + 0xe0) >> 8) < '\0') {

        FUN_00495700(0x34c,param_1);

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

        FUN_00495700(0x34c,param_1);

        puVar2[0x3c7] = *(uint *)(DAT_00632ed8 + 0x828);

        *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xffff3fff;

        puVar2[0x3c9] = 0;

        return;

      }

    }

  }

  return;

}

/* ===== FUN_004be020 @ 0x004BE020 ===== */
/* PS2 candidate: make_arrow__FP6OBJECTT0P3P3DPUii (conf 0.489) */



void FUN_004be020(int param_1,undefined4 param_2,uint *param_3,undefined4 *param_4,

                 undefined4 param_5)



{

  uint *puVar1;

  uint *puVar2;

  uint uVar3;

  undefined4 uVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  float10 fVar8;

  float10 fVar9;

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

  uVar4 = FUN_00456050(param_1);

  object_lock_with_volume(uVar4);

  iVar7 = 0;

  FUN_00403e60(uVar4,0);

  local_a8 = 0;

  switch(param_5) {

  case 0x2c:

    FUN_004a8f50(0x2b);

    FUN_004a76e0(uVar4,0,&local_c0);

    local_b4 = *param_3;

    local_b0 = param_3[1];

    local_ac = param_3[2];

    fVar8 = (float10)FUN_0050a490(&local_c0,&local_b4);

    local_a0 = (float)fVar8;

    fVar8 = (float10)FUN_0050a400(&local_c0,&local_b4);

    local_44 = 0;

    FUN_0053e460(&local_44,-local_a0,0,(float)fVar8);

    auStack_38[1] = local_c0;

    local_44 = local_44 | 0x10;

    local_24[0] = local_bc;

    local_14 = local_b8;

    iVar7 = FUN_004aa550(0x2b,*(undefined4 *)(param_1 + 0x18c),param_1,0,&local_44,0);

    *(int *)(iVar7 + 0x274) = param_1;

    iVar5 = FUN_0052e480(param_1);

    if (iVar5 == 0) {

      *(undefined4 *)(iVar7 + 0x188) = *param_4;

    }

    else {

      iVar5 = reaper_0052e4a0(param_1);

      if (iVar5 != 0) {

        local_98 = local_b0;

        local_9c = local_b4;

        local_90 = *(undefined4 *)(iVar7 + 0x188);

        local_94 = local_ac;

        reaper_00530bd0(param_1,3,1,0,9,&local_9c);

      }

    }

    sound_play_player(0x38d,param_1);

    local_a8 = 0;

    break;

  case 0x2d:

    FUN_004a8f50(0x16);

    FUN_004a76e0(uVar4,0,&local_c0);

    local_b4 = *param_3;

    local_b0 = param_3[1];

    local_ac = param_3[2];

    fVar8 = (float10)FUN_0050a490(&local_c0,&local_b4);

    fVar9 = (float10)FUN_0050a400(&local_c0,&local_b4);

    local_88[0] = 0;

    FUN_0053e460(local_88,-(float)fVar8,0,(float)fVar9);

    local_78 = local_c0;

    local_68 = local_bc;

    local_58 = local_b8;

    local_88[0] = local_88[0] | 0x10;

    iVar7 = FUN_004aa550(0x16,*(undefined4 *)(param_1 + 0x18c),param_1,0,local_88,0);

    *(int *)(iVar7 + 0x274) = param_1;

    iVar5 = FUN_0052e480(param_1);

    if (iVar5 == 0) {

      *(undefined4 *)(iVar7 + 0x188) = *param_4;

    }

    else {

      iVar5 = reaper_0052e4a0(param_1);

      if (iVar5 != 0) {

        local_98 = local_b0;

        local_9c = local_b4;

        local_90 = *(undefined4 *)(iVar7 + 0x188);

        local_94 = local_ac;

        reaper_00530bd0(param_1,3,1,0,0x1f,&local_9c);

      }

    }

    sound_play_player(0x390,param_1);

    local_a8 = 1;

    break;

  case 0x2e:

    FUN_004a8f50(0x15);

    FUN_004a76e0(uVar4,0,&local_c0);

    local_b4 = *param_3;

    local_b0 = param_3[1];

    local_ac = param_3[2];

    fVar8 = (float10)FUN_0050a490(&local_c0,&local_b4);

    fVar9 = (float10)FUN_0050a400(&local_c0,&local_b4);

    local_88[0] = 0;

    FUN_0053e460(local_88,-(float)fVar8,0,(float)fVar9);

    local_78 = local_c0;

    local_88[0] = local_88[0] | 0x10;

    local_68 = local_bc;

    local_58 = local_b8;

    iVar7 = FUN_004aa550(0x15,*(undefined4 *)(param_1 + 0x18c),param_1,0,local_88,0);

    *(int *)(iVar7 + 0x274) = param_1;

    sound_play_player(0x395,param_1);

    iVar5 = FUN_0052e480(param_1);

    if (iVar5 == 0) {

      *(undefined4 *)(iVar7 + 0x188) = *param_4;

      local_a8 = 1;

    }

    else {

      iVar5 = reaper_0052e4a0(param_1);

      if (iVar5 != 0) {

        local_98 = local_b0;

        local_9c = local_b4;

        local_90 = *(undefined4 *)(iVar7 + 0x188);

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

        FUN_00495700(0x36c,param_1);

        puVar2[0x3fd] = 0;

        *(uint *)(puVar2[0x3e4] + 0xd8) = *(uint *)(puVar2[0x3e4] + 0xd8) | 0x40000000;

      }

      FUN_004a76e0(uVar4,0,&local_c0);

      fVar8 = (float10)FUN_0050a490(&local_c0,param_3);

      fVar9 = (float10)FUN_0050a400(&local_c0,param_3);

      local_88[0] = 0;

      FUN_0053e460(local_88,-(float)fVar8,0,(float)fVar9);

      local_78 = local_c0;

      local_58 = local_b8;

      local_68 = local_bc;

      local_88[0] = local_88[0] | 0x10;

      iVar7 = FUN_004aa550(0x17,*(undefined4 *)(param_1 + 0x18c),param_1,0,local_88,puVar2[0x3e3]);

      *(int *)(iVar7 + 0x274) = param_1;

      sound_play_player(0x36a,param_1);

      iVar5 = FUN_0052e480(param_1);

      if (iVar5 == 0) {

        *(undefined4 *)(iVar7 + 0x188) = *param_4;

        local_a8 = 1;

      }

      else {

        iVar5 = reaper_0052e4a0(param_1);

        if (iVar5 != 0) {

          local_9c = *param_3;

          local_98 = param_3[1];

          local_94 = param_3[2];

          local_8c = *(undefined4 *)(iVar7 + 0x188);

          local_90 = *(undefined4 *)(puVar2[0x3e3] + 0x188);

          reaper_00530bd0(param_1,3,2,0,0x20,&local_9c);

        }

        local_a8 = 1;

      }

    }

    break;

  case 0x30:

    local_a0 = 0.0;

    FUN_004a76e0(uVar4,0,&local_c0);

    fVar8 = (float10)FUN_0050a490(&local_c0,param_3);

    fVar9 = (float10)FUN_0050a400(&local_c0,param_3);

    local_a4 = (uint *)(float)fVar9;

    local_88[0] = 0;

    FUN_0053e460(local_88,-(float)fVar8,0,local_a4);

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

          iVar5 = FUN_004aa550(0x34,*(undefined4 *)(param_1 + 0x18c),param_1,0,local_88,uVar3);

          *(int *)(iVar5 + 0x274) = param_1;

          iVar6 = FUN_0052e480(param_1);

          if (iVar6 == 0) {

            *(undefined4 *)(iVar5 + 0x188) = param_4[iVar7];

          }

          else {

            iVar6 = reaper_0052e4a0(param_1);

            if (iVar6 != 0) {

              local_44 = *param_3;

              local_40 = param_3[1];

              local_3c = param_3[2];

              local_24[iVar7] = *(undefined4 *)(iVar5 + 0x188);

              auStack_38[iVar7] = *(undefined4 *)(uVar3 + 0x188);

            }

          }

          local_a4[-5] = 0;

          local_a8 = 1;

        }

        if (*local_a4 != 0) {

          puVar1 = (uint *)(*local_a4 + 0xd8);

          *puVar1 = *puVar1 | 0x40000000;

        }

        iVar7 = iVar7 + 1;

        local_a4 = local_a4 + 1;

      } while (iVar7 < (int)puVar2[0x36b]);

    }

    sound_play_player(0x389,param_1);

    iVar7 = reaper_0052e4a0(param_1);

    if ((iVar7 != 0) && (local_a0 != 0.0)) {

      reaper_00530bd0(param_1,3,10,0,0x22,&local_44);

    }

  }

  puVar2[puVar2[0x36d] * 2 + 0x35d] = puVar2[puVar2[0x36d] * 2 + 0x35d] - local_a8;

  if (((int)puVar2[puVar2[0x36d] * 2 + 0x35d] < 0) && (0 < local_a8)) {

    puVar2[puVar2[0x36d] * 2 + 0x35d] = 0;

  }

  iVar7 = *(int *)(param_1 + 0x100);

  *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xffffff7f;

  iVar5 = *(int *)(iVar7 + 0xe38);

  if (iVar5 != 0) {

    FUN_00448920(iVar5);

    *(undefined4 *)(iVar7 + 0xe38) = 0;

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

  fVar2 = (float10)FUN_00518b70(param_1,0);

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

    fVar2 = (float10)FUN_00518b70(param_1,0);

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

    FUN_00495ee0(puVar1 + 0x3fb);

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

      fVar2 = (float10)FUN_00518b70(param_1,0);

      fVar2 = ((float10)*(float *)(DAT_00632ed8 + 0xfe0) / (float10)*(float *)(DAT_00632ed8 + 0x748)

              ) * fVar2;

      goto LAB_004be9d9;

    }

  }

  else if (puVar1[2] != 0) {

    if (0.0 < (float)puVar1[0x13]) {

      physics_reset_b(param_1);

      fVar2 = (float10)FUN_00518b70(param_1,0);

      puVar1[0x13] = (uint)(float)((float10)(float)puVar1[0x13] - fVar2);

    }

    goto LAB_004be9ad;

  }

  fVar2 = (float10)FUN_00518b70(param_1,0);

LAB_004be9d9:

  puVar1[10] = (uint)(float)((float10)(float)puVar1[10] - fVar2);

  if (0.0 <= (float)puVar1[10]) {

    return;

  }

  puVar1[10] = 0;

  return;

}

/* ===== FUN_004bea70 @ 0x004BEA70 ===== */
/* PS2 candidate: reaper_fire_spell__FP6OBJECTiP3P3DT0i (conf 0.444) */



void FUN_004bea70(int param_1,int param_2,undefined4 *param_3,undefined4 param_4,undefined4 param_5)



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

  

  FUN_004a76e0(param_1,0,&local_60);

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

  fVar6 = (float10)FUN_0050a490(&local_60,param_3);

  fVar7 = (float10)FUN_0050a400(&local_60,param_3);

  local_44[0] = 0;

  FUN_0053e460(local_44,-(float)fVar6,0,(float)fVar7);

  local_34 = local_60;

  local_14 = local_58;

  local_24 = local_5c;

  local_44[0] = local_44[0] | 0x10;

  iVar1 = FUN_004aa550(param_2,*(undefined4 *)(param_1 + 0x18c),param_1,0,local_44,param_4);

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

  iVar1 = FUN_0052e480(param_1);

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

  iVar1 = FUN_004aa230(0x2c,*(undefined4 *)(param_1 + 0x18c),param_1,0,param_4,param_3);

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

  iVar1 = FUN_0052e480(param_1);

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

  iVar1 = FUN_004aa230(0x32,*(undefined4 *)(param_1 + 0x18c),param_1,1,param_4,param_3);

switchD_004bed16_caseD_28:

  *(int *)(iVar1 + 0x274) = param_1;

  iVar4 = FUN_0052e480(param_1);

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

/* ===== FUN_004beee0 @ 0x004BEEE0 ===== */
/* PS2 candidate: reaper_fire_bow__FP6OBJECT (conf 0.53) */



void FUN_004beee0(int param_1)



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

  iVar3 = FUN_0052e480(param_1);

  if (iVar3 == 0) {

    return;

  }

  if ((DAT_00632aec != '\0') && (1 < (int)puVar9[0x36d])) {

    uVar4 = FUN_00507b00(s_InvChDropItem_0055a158);

    uVar5 = FUN_004a9130(puVar9[puVar9[0x36d] * 2 + 0x35c]);

    FUN_00542f27(local_100,uVar4,uVar5);

    FUN_005362d0(local_100,1);

    iVar3 = *(int *)(param_1 + 0x100);

    FUN_0045a820(param_1,*(undefined4 *)(iVar3 + 0xd70 + *(int *)(iVar3 + 0xdb4) * 8),

                 *(undefined4 *)(iVar3 + 0xd74 + *(int *)(iVar3 + 0xdb4) * 8),

                 *(float *)(param_1 + 0x29c) * -30.0,*(float *)(param_1 + 0x2ac) * -30.0,0x41700000,

                 0x41f00000);

    FUN_004b9080(param_1,*(undefined4 *)(iVar3 + 0xd70 + *(int *)(iVar3 + 0xdb4) * 8),0xffffffff,0,1

                );

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

      FUN_00448920(puVar7[0x38e]);

      puVar7[0x38e] = 0;

    }

    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xffffffbf;

    *puVar7 = *puVar7 & 0xfffffffe;

  }

  if ((*(uint *)(param_1 + 0x20c) & 0x2000000) != 0) {

    fVar10 = (float10)FUN_00518b70(param_1,0);

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

      local_11c = FUN_00456050(param_1);

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

        iVar3 = FUN_004ba1a0(uVar6,param_1);

        if ((iVar3 != 0) &&

           ((((((iVar3 = FUN_004a61e0(uVar6), iVar3 != 0 ||

                (iVar3 = *(int *)(uVar6 + 4), iVar3 == 0x29a)) || (iVar3 == 8)) ||

              ((iVar3 == 0x438 || (iVar3 == 0xd7)))) ||

             ((iVar3 = FUN_004a6100(uVar6), iVar3 != 0 ||

              ((*(int *)(uVar6 + 4) == 0x23f || (*(int *)(uVar6 + 4) == 0x2e9)))))) &&

            (iVar3 = FUN_00455070(param_1,uVar6,puVar9[0x3e2]), iVar3 != 0)))) {

          local_158 = *(undefined4 *)(param_1 + 0xa0);

          local_154 = *(undefined4 *)(param_1 + 0xa4);

          local_150 = *(float *)(param_1 + 0xa8) + *(float *)(param_1 + 0x1e8);

          local_14c = *(undefined4 *)(uVar6 + 0xa0);

          local_148 = *(undefined4 *)(uVar6 + 0xa4);

          local_144 = *(float *)(uVar6 + 0xa8) + *(float *)(uVar6 + 0x1e8);

          iVar3 = FUN_004eed30(&local_158,&local_14c);

          if (iVar3 != 0) {

            puVar7[-5] = uVar6;

            if (*puVar7 == 0) {

              uVar8 = object_allocate_type(0x3d4,0);

              *puVar7 = uVar8;

            }

            *(uint *)(*puVar7 + 0xd8) = *(uint *)(*puVar7 + 0xd8) & 0xbfffffff;

            *(uint *)(*puVar7 + 0xd8) = *(uint *)(*puVar7 + 0xd8) | 0x10000;

            FUN_0053d9e0(*puVar7 + 0x294);

            FUN_004a2c50(*puVar7 + 0x294,uVar6,0x40000000);

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

      FUN_00495700(0x36c,param_1);

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

      FUN_0053d9e0(puVar9[0x3e4] + 0x294);

      FUN_004a2c50(puVar9[0x3e4] + 0x294,puVar9[0x3e3],0x40000000);

    }

    if ((float)puVar9[0x3e6] <= 0.0) {

      puVar9[999] = 1;

      iVar3 = FUN_00455070(param_1,puVar9[0x3e3],*(undefined4 *)(DAT_00632ed8 + 0x8e0));

      if (iVar3 != 0) {

        return;

      }

      FUN_00495700(0x36c,param_1);

      puVar9[0x3fd] = 0;

      puVar9[0x3e3] = 0;

      uVar6 = *(uint *)(DAT_00632ed8 + 0x8dc);

      puVar9[999] = 0;

      puVar9[0x3e6] = uVar6;

      *(uint *)(puVar9[0x3e4] + 0xd8) = *(uint *)(puVar9[0x3e4] + 0xd8) | 0x40000000;

      return;

    }

    if (puVar9[0x3e3] != 0) {

      fVar10 = (float10)FUN_00518b70(param_1,0);

      puVar9[0x3e6] = (uint)(float)((float10)(float)puVar9[0x3e6] - fVar10);

      return;

    }

    puVar9[0x3e6] = *(uint *)(DAT_00632ed8 + 0x8dc);

    puVar9[999] = 0;

    return;

  }

  if ((*(char *)(param_1 + 0xe0) < '\0') &&

     ((float)puVar9[0x16] < 0.0 != ((float)puVar9[0x16] == 0.0))) {

    FUN_004be020(param_1,uVar6,&local_140,0,puVar9[puVar9[0x36d] * 2 + 0x35c]);

    puVar9[0x16] = *(uint *)(DAT_00632ed8 + 0x6b0);

    return;

  }

  if (puVar9[0x3e4] != 0) {

    FUN_00495700(0x36c,param_1);

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

    FUN_00495700(uVar4,param_1);

    puVar9 = *(uint **)(param_1 + 0x100);

    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xffffff7f;

    if (puVar9[0x38e] != 0) {

      FUN_00448920(puVar9[0x38e]);

      puVar9[0x38e] = 0;

    }

  }

  else {

    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xffffff7f;

    fVar10 = (float10)FUN_00518b70(param_1,0);

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

  iVar5 = FUN_0052e480(param_1);

  piVar3 = param_3;

  if (iVar5 == 0) {

    *(undefined4 *)(iVar4 + 0x188) = param_5;

  }

  iVar5 = *param_3 * 0x44 + *(int *)(*piVar2 + 0x2dc);

  local_4c = *(undefined4 *)(iVar5 + 0x10);

  local_48 = *(undefined4 *)(iVar5 + 0x20);

  local_44 = *(undefined4 *)(iVar5 + 0x30);

  FUN_005170f0(*piVar2,&local_4c,local_40);

  FUN_004993c0(iVar4,local_40);

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

    FUN_00497510(*piVar2);

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

  iVar1 = FUN_0052e480(param_1);

  if (iVar1 == 0) {

    *(undefined4 *)(*param_2 + 0x188) = param_9;

  }

  object_change_ospec(*param_2,0x56);

  FUN_004993c0(*param_2,param_3);

  *(undefined4 *)(*param_2 + 200) = param_6;

  *(undefined4 *)(*param_2 + 0xec) = *(undefined4 *)(DAT_00632ed8 + 0x79c);

  *(undefined4 *)(*param_2 + 0xf4) = *param_7;

  *(undefined4 *)(*param_2 + 0xf8) = param_7[1];

  *(undefined4 *)(*param_2 + 0xfc) = param_7[2];

  *(undefined4 *)(*param_2 + 0xe0) = 1;

  *param_5 = *(undefined4 *)(DAT_00632ed8 + 0x784);

  iVar1 = FUN_0052e480(param_1);

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

  iVar3 = FUN_00456050(param_1);

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

    iVar6 = FUN_004a6120(param_2);

    if (iVar6 == 0) {

      iVar6 = FUN_004a6120(*(undefined4 *)(iVar8 + 0x210));

      if (iVar6 == 0) {

        sound_play_player(0x3bb,iVar8);

        if (iVar8 == DAT_00632a88) {

          pcVar7 = (char *)FUN_00507b00(s_SpellHintShrink_00561034);

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

        FUN_00457100(0xe,piVar1[2],iVar8,param_1,0,0);

        iVar6 = FUN_0052e480(param_1);

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

        iVar8 = FUN_004a61a0(iVar8);

        if (iVar8 != 0) {

          piVar1 = (int *)(*(int *)(*piVar1 + 0x100) + 0x354);

          *piVar1 = *piVar1 + 1;

        }

      }

    }

  }

  return;

}

/* ===== FUN_004bfe50 @ 0x004BFE50 ===== */
/* PS2 candidate: reaper_finish_hail__FP6OBJECT (conf 0.335) */



void FUN_004bfe50(int param_1)



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

        iVar4 = FUN_004aa0b0(0xf,*(undefined4 *)(iVar3 + 0x18c));

        puVar1 = (uint *)(iVar4 + 0x294);

        FUN_0053d9e0(puVar1);

        *(undefined4 *)(iVar4 + 0x2a4) = puVar7[-1];

        uVar2 = *puVar7;

        *puVar1 = *puVar1 | 0x10;

        *(undefined4 *)(iVar4 + 0x2b4) = uVar2;

        *(undefined4 *)(iVar4 + 0x2c4) = 0x43610000;

        FUN_00499310(iVar4,*(undefined4 *)(iVar4 + 0x2a4),uVar2,0x43610000);

        *(int *)(iVar4 + 0x274) = iVar3;

        iVar5 = FUN_0052e480(iVar3);

        if (iVar5 == 0) {

          *(undefined4 *)(iVar4 + 0x188) = local_68[-5];

        }

        else {

          auStack_14[param_1] = *(undefined4 *)(iVar4 + 0x188);

        }

      }

      FUN_00448920(*local_68);

      param_1 = param_1 + 1;

      *local_68 = 0;

      local_68 = local_68 + 1;

      puVar7 = puVar7 + 3;

    } while ((float)param_1 < *(float *)(DAT_00632ed8 + 0x7c4));

  }

  if (((0 < *(int *)(iVar6 + 0xea8)) && (iVar6 = FUN_0052e480(iVar3), iVar6 != 0)) &&

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

