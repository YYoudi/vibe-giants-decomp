/* Giants 1.449 — module _unmapped_0047
 * 67 functions (16 named) — decompiled, names from PS2 symbols
 * Original source: C:\Giants\source\_unmapped_0047.c(pp) (assert-string evidence)
 */

/* ===== FUN_00470220 @ 0x00470220 ===== */
/* PS2 candidate: object_destroy_all__7PS2Game (conf 0.642) */



void FUN_00470220(undefined4 param_1)



{

  undefined4 *puVar1;

  

  for (puVar1 = DAT_00632d68; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {

    if (*(int *)(puVar1[3] + 0x1e0) == 0x5c) {

      FUN_0046ff90(puVar1[3],param_1);

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

/* ===== FUN_00470670 @ 0x00470670 ===== */
undefined4 FUN_00470670(int param_1,int *param_2)



{

  int iVar1;

  int local_c [3];

  

  local_c[0] = *param_2;

  if (local_c[0] != 0) {

    iVar1 = FUN_0053fe20(*(undefined4 *)(param_1 + 0xc),local_c,0);

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

        FUN_00542f27(local_100,s_Lock_error_d_Object__d__LObject___0055b5b0,1,

                     *(undefined4 *)(param_1 + 4),*(undefined4 *)(iVar3 + 4),

                     *(undefined4 *)(param_1 + 0x214),iVar2);

        goto LAB_00470793;

      }

      (*(code *)PTR_FUN_00580c18)(local_1cc,iVar3 + 0x294,iVar2 * 0x44 + *(int *)(iVar3 + 0x2dc));

    }

    local_1d0 = *(float *)(param_1 + 0xc4);

    if ((*(uint *)(param_1 + 0xdc) & 0x2000000) == 0) {

      local_1d0 = local_1d0 / *(float *)(iVar3 + 0xc4);

    }

    FUN_0053dc50(local_188,local_1d0);

    (*(code *)PTR_FUN_00580c18)(local_1cc,local_1cc,local_188);

    if ((char)((uint)*(undefined4 *)(param_1 + 0xdc) >> 8) < '\0') {

      FUN_004a7440(param_1);

      iVar2 = *(int *)(param_1 + 0x214);

      if ((char)iVar2 < '\0') {

        *(undefined4 *)(param_1 + 0x2a4) = uStack_1bc;

        *(undefined4 *)(param_1 + 0x2b4) = uStack_1ac;

        *(undefined4 *)(param_1 + 0x2c4) = uStack_19c;

      }

      else {

        if (*(int *)(param_1 + 0x2d8) <= iVar2) {

          FUN_00542f27(local_100,s_Lock_error_d_Object__d__LObject___0055b5b0,2,

                       *(undefined4 *)(param_1 + 4),*(undefined4 *)(iVar3 + 4),iVar2,

                       *(undefined4 *)(param_1 + 0x218));

          FUN_0051ea20(local_100);

          *(undefined4 *)(param_1 + 0x210) = 0;

          return;

        }

        (*(code *)PTR_FUN_00580c1c)(local_188,iVar2 * 0x44 + *(int *)(param_1 + 0x2dc));

        (*(code *)PTR_FUN_00580c18)(auStack_144,local_1cc,local_188);

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

          FUN_00542f27(local_100,s_Lock_error_d_Object__d__LObject___0055b5b0,3,

                       *(undefined4 *)(param_1 + 4),*(undefined4 *)(iVar3 + 4),iVar2,

                       *(undefined4 *)(param_1 + 0x218));

LAB_00470793:

          FUN_0051ea20(local_100);

          *(undefined4 *)(param_1 + 0x210) = 0;

          return;

        }

        (*(code *)PTR_FUN_00580c1c)(local_188,iVar2 * 0x44 + *(int *)(param_1 + 0x2dc));

        (*(code *)PTR_FUN_00580c18)(param_1 + 0x294,local_1cc,local_188);

      }

    }

    if ((*(uint *)(param_1 + 0xdc) & 0x1000) != 0) {

      *(undefined4 *)(param_1 + 0x210) = 0;

      *(uint *)(param_1 + 0xdc) = *(uint *)(param_1 + 0xdc) & 0xffffefff;

    }

    fVar1 = *(float *)(param_1 + 0x1d4) + *(float *)(param_1 + 0x2c4);

    *(float *)(param_1 + 0x2c4) = fVar1;

    FUN_00499310(param_1,*(undefined4 *)(param_1 + 0x2a4),*(undefined4 *)(param_1 + 0x2b4),fVar1);

  }

  return;

}

/* ===== FUN_00470e40 @ 0x00470E40 ===== */
undefined4 FUN_00470e40(undefined4 *param_1)



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

         ((fVar5 = (float10)FUN_0050a5e0(puVar2,iVar1 + 0xa0), iVar3 == 0 ||

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

/* ===== FUN_00471130 @ 0x00471130 ===== */
void FUN_00471130(void)



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

        FUN_005161c0(0,0,fVar3,fVar2);

        FUN_00516420(&local_50,&local_78,&local_6c);

        FUN_005160b0(0x42b40000,0,1);

        FUN_0053d9e0(auStack_44);

        (**(code **)(DAT_00656420 + 0x18))(DAT_00656420,auStack_40);

        (**(code **)(DAT_00656420 + 0xa0))(DAT_00656420,0,0,fVar3,fVar2,0);

        (**(code **)(DAT_00656420 + 0x14))(DAT_00656420);

        FUN_00516890();

        FUN_00451cf0();

        ai_island_init(0,0);

        dome_render_text(0,0);

        main_drawwatr_00431700();

        FUN_00451da0();

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

/* ===== FUN_00471420 @ 0x00471420 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_00471420(void)



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

      FUN_005161c0(0,0,(float)iVar11,(float)iVar5);

      FUN_00515de0(&DAT_0055b640,&DAT_0055b64c);

      FUN_0053d9e0(auStack_44);

      FUN_005162b0(auStack_40);

      FUN_00451cf0();

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

      FUN_00451da0();

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

/* ===== FUN_00471780 @ 0x00471780 ===== */
undefined4 FUN_00471780(void)



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

  FUN_004a13c0(&DAT_0055b720);

  if (DAT_00633128 == 0) {

    DAT_00632e6c = DAT_00632e6c + DAT_006328e0;

    DAT_00632e70 = DAT_00632e70 + 1;

  }

  FUN_0041f120();

  FUN_005387c0();

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

    FUN_00516260(puVar9);

    puVar8 = auStack_40;

    FUN_005163e0(puVar8);

    fVar6 = (float10)FUN_00515d90();

    fVar7 = (float10)FUN_00515da0();

    fVar10 = (float)fVar7;

    FUN_00471420(puVar8,puVar9,fVar10);

    FUN_00471130();

    FUN_00516220(auStack_50);

    FUN_005162b0(auStack_40);

    FUN_005160b0((float)fVar6,fVar10,1);

  }

  if (DAT_006330dc == 0) {

    iVar2 = FUN_004469e0();

    if (iVar2 != 0) {

      iVar2 = FUN_00446890();

      if (iVar2 == 0) {

        FUN_004a5cd0();

        return 1;

      }

      FUN_00490d40();

      if (DAT_00632b98 != 0) {

        return 1;

      }

    }

    DAT_0063302c = DAT_0063302c + 1;

    if ((DAT_00633028 == 0) || (DAT_0063302c < 4)) {

      iVar2 = FUN_00490fe0();

      if (iVar2 != 0) {

        iVar2 = FUN_004469e0();

        if (iVar2 != 0) {

          return 1;

        }

        FUN_00426ee0();

        return 1;

      }

      iVar2 = FUN_004469e0();

      if (iVar2 == 0) {

        FUN_00426ee0();

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

    FUN_00451cf0();

    FUN_00426f20();

    AddHud__4cHudP8cHudIcon_2();

    FUN_00451da0();

    (**(code **)(DAT_00656420 + 0xa8))(DAT_00656420);

    return 1;

  }

LAB_00471872:

  FUN_00426ee0();

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

  FUN_00451cf0();

  FUN_00426f20();

  AddHud__4cHudP8cHudIcon_2();

  FUN_00451da0();

  (**(code **)(DAT_00656420 + 0xa8))(DAT_00656420);

  return 1;

}

/* ===== FUN_00471a60 @ 0x00471A60 ===== */
/* PS2 candidate: game_loop_run (conf 0.48) */



void FUN_00471a60(int param_1)



{

  undefined4 *puVar1;

  undefined4 uVar2;

  int iVar3;

  float10 fVar4;

  

  if ((DAT_00633044 != 0) && ((param_1 == 0 || (DAT_00632e40 == 0)))) {

    if ((DAT_00632b98 != 0) && (iVar3 = FUN_004469e0(), iVar3 == 0)) {

      DAT_00632b8c = 1;

      DAT_00632b98 = 0;

    }

    if ((DAT_00633248 != 0) && (iVar3 = FUN_004469e0(), iVar3 == 0)) {

      FUN_00450af0();

    }

    if ((DAT_00632b8c != 0) && (FUN_004eba40(3,0), DAT_00632b8c != 0)) {

      DAT_00632b8c = 0;

      FUN_004EE800();

      return;

    }

    if ((param_1 != 0) && (DAT_00633128 != 0)) {

      FUN_004A54E0();

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

          FUN_00499280(puVar1[3]);

        }

      }

      if (DAT_00633044 != 0) {

        if (DAT_00632d60 != 0) {

          main_demo_004267a0();

        }

        if (param_1 != 0) {

          FUN_004A54E0();

        }

        if ((DAT_00632a88 != 0) && (DAT_00633044 != 0)) {

          FUN_004759a0();

          FUN_00431b80();

          FUN_00475290();

          FUN_00497de0();

          FUN_004eb900();

          for (puVar1 = DAT_00632d70; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {

            uVar2 = puVar1[3];

            FUN_00501050(uVar2);

            FUN_00501030(uVar2);

          }

          cleaner_go_obj();

          FUN_004a4550();

          FUN_004f75c0();

          win95_frate_00518c60();

          for (puVar1 = DAT_00632d68; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {

            iVar3 = puVar1[3];

            if ((*(uint *)(iVar3 + 0xd8) & 0xc000) == 0) {

              *(uint *)(iVar3 + 0xd8) = *(uint *)(iVar3 + 0xd8) & 0xffffffbf;

              FUN_004a6420(iVar3);

              if (DAT_00632a88 == 0) {

                return;

              }

              if ((*(uint *)(iVar3 + 0xd8) & 0xc000) == 0) {

                if ((*(uint *)(iVar3 + 0xd8) & 0x40) == 0) {

                  FUN_004967b0(iVar3);

                  fVar4 = (float10)FUN_00518b70(iVar3,0);

                  FUN_00403e60(iVar3,(float)fVar4);

                  FUN_00499500(iVar3);

                }

                *(uint *)(iVar3 + 0xd8) = *(uint *)(iVar3 + 0xd8) & 0xfffff7ff;

              }

            }

          }

          FUN_00515ba0(0);

          FUN_004982c0();

          FUN_0049b810();

          for (puVar1 = DAT_00632d68; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {

            if ((*(uint *)(puVar1[3] + 0xd8) & 0xc000) == 0) {

              FUN_00498c60(puVar1[3]);

            }

          }

          puVar1 = DAT_00632d68;

          if (DAT_00632a88 != 0) {

            for (; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {

              if ((*(uint *)(puVar1[3] + 0xd8) & 0x8000) == 0) {

                FUN_0049a1f0(puVar1[3]);

              }

            }

            FUN_0040bdc0();

            FUN_0040b640();

            FUN_00443110();

            FUN_0044efd0(0);

            sound_play_5(0);

            ANM_DumpCluster();

            FUN_00535390();

            if (DAT_00632a88 != 0) {

              if (DAT_00632d5c != 0) {

                FUN_00426570();

              }

              object_list_update();

              FUN_0040b2c0();

              puVar1 = DAT_00632d68;

              if (DAT_00632a88 != 0) {

                for (; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {

                  iVar3 = puVar1[3];

                  FUN_00494120(iVar3);

                  if ((*(int *)(iVar3 + 0x204) != 0) && ((*(uint *)(iVar3 + 0xd8) & 0xc000) == 0)) {

                    FUN_005137c0(iVar3);

                  }

                }

                iVar3 = FUN_0052aa70();

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

/* ===== FUN_00471dc0 @ 0x00471DC0 ===== */
/* PS2 candidate: __main_3 (conf 0.574) */



void FUN_00471dc0(void)



{

  if (DAT_00633048 != 0) {

    DAT_00633048 = 0;

    return;

  }

  if (DAT_00633044 == 0) {

    FUN_0051ba00(0xffffff,0,0x3dcccccd,0x3f000000,0x3f000000,s_Render_Error_0055b724);

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

/* ===== main/makewrld_00473e10 @ 0x00473E10 ===== */
void main_makewrld_00473e10

               (int param_1,int param_2,float *param_3,float *param_4,undefined4 param_5)



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

    main_makewrld_00473e10(param_1,param_2,local_18,local_c,*(byte *)(iVar3 + 0xc) & 7);

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

/* ===== FUN_004751d0 @ 0x004751D0 ===== */
undefined4 FUN_004751d0(float *param_1)



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

/* ===== FUN_00475290 @ 0x00475290 ===== */
void FUN_00475290(void)



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

    iVar1 = FUN_0052aa70();

    if (iVar1 != 0) {

      iVar1 = FUN_0052e480(DAT_00632bbc);

      if (iVar1 == 0) {

        FUN_0041a1c0(param_1,DAT_00632bbc);

        return;

      }

      *(undefined4 *)(*(int *)(DAT_00632bbc + 0x100) + 0x570) = *(undefined4 *)(param_1 + 0x188);

    }

    FUN_004753c0();

    DAT_00632bac = 1;

  }

  return;

}

/* ===== FUN_004753c0 @ 0x004753C0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_004753c0(void)



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

    iVar4 = FUN_0052aa70();

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

    iVar4 = FUN_004a6160(DAT_00632a88);

    if (iVar4 == 0) {

      iVar4 = FUN_004a6180(DAT_00632a88);

      if (iVar4 != 0) {

        obj_snap_variant_a(DAT_00632a88);

      }

    }

    else {

      FUN_00480a60(DAT_00632a88);

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

    FUN_0040ce50();

    FUN_0040d130(1);

    fVar9 = (float10)FUN_00515d90();

    DAT_0059dc20 = (float)fVar9;

    fVar9 = (float10)FUN_00515da0();

    DAT_0059dc24 = (float)fVar9;

    FUN_005163e0(&DAT_0059dc40);

    FUN_00515eb0(&DAT_0059dc28,&DAT_0059dc2c);

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

    FUN_00516420(&local_24,&local_c,&local_18);

    FUN_005160b0(0x42700000,0x3fa66666,1);

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

              FUN_004757c0(iVar7,iVar8);

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

/* ===== FUN_00475700 @ 0x00475700 ===== */
void FUN_00475700(int param_1)



{

  int iVar1;

  

  if (((param_1 != 0) && (DAT_00632bbc != 0)) && (DAT_00632a88 != 0)) {

    iVar1 = FUN_0052aa70();

    if ((iVar1 != 0) && (DAT_00632bac != 0)) {

      FUN_0041a1f0(DAT_00632a88,DAT_00632bbc);

      *(undefined4 *)(*(int *)(DAT_00632bbc + 0x100) + 0x570) = 0;

    }

  }

  dialog_level_pop(&LAB_00475b40);

  DAT_00632ba8 = 0;

  DAT_00632bac = 0;

  FUN_0040ce70();

  FNT_StringRender__FPcP14FNT_RenderInfo(DAT_0059dc28,DAT_0059dc2c);

  FUN_005162b0(&DAT_0059dc40);

  FUN_005160b0(DAT_0059dc20,DAT_0059dc24,1);

  FUN_00516850();

  return;

}

/* ===== FUN_004757c0 @ 0x004757C0 ===== */
void FUN_004757c0(int param_1,int param_2)



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

  FUN_004551b0(&local_28,&local_10,0,&local_3c,0);

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

              FUN_004551b0(&local_1c,&local_10,0,&local_3c,0);

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

/* ===== FUN_004759a0 @ 0x004759A0 ===== */
void FUN_004759a0(void)



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

        FUN_004757c0(iVar2,iVar3);

        return;

      }

      iVar1 = *(int *)(*(int *)(iVar1 + 0x10) + iVar3 * 4);

      *(byte *)(iVar1 + 0xf + iVar2 * 0x10) = *(byte *)(iVar1 + 0xf + iVar2 * 0x10) | 0x40;

    }

  }

  return;

}

/* ===== FUN_00475a40 @ 0x00475A40 ===== */
int FUN_00475a40(float param_1,float param_2)



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

       ((iVar5 = FUN_005168f0(iVar1 + 0xa0,&param_1,&param_2), iVar6 = DAT_00632a88, iVar5 == 0 &&

        (iVar5 = FUN_00416a70(param_1 - 6.0,param_2 - 6.0,param_1 + 6.0,param_2 + 6.0,fVar3,fVar4,

                              fVar3,fVar4), iVar6 = DAT_00632a88, iVar5 != 0)))) break;

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

    FUN_00542f27(&DAT_0059dca8,pcVar2,param_2);

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

/* ===== FUN_00476f90 @ 0x00476F90 ===== */
void FUN_00476f90(int param_1)



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

/* ===== FUN_00476ff0 @ 0x00476FF0 ===== */
void FUN_00476ff0(int param_1)



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

          FUN_0053d940(piVar1[1],&uStack_38,&fStack_88);

          pfVar8[-2] = fStack_88;

          pfVar8[-1] = fStack_84;

          FUN_00414690(&fStack_88,auStack_1c);

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

/* ===== FUN_00477340 @ 0x00477340 ===== */
/* PS2 candidate: marker_spline_adjust_buoy (conf 0.6) */



void FUN_00477340(int param_1)



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

            fVar10 = (float10)FUN_00413e40(*(int *)(iVar4 + 0x54) + 0xa0);

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

            fVar10 = (float10)FUN_00413e40(*(int *)(iVar4 + 0x58) + 0xa0);

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

            FUN_00499310(iVar3,*(undefined4 *)(iVar3 + 0xa0),*(undefined4 *)(iVar3 + 0xa4),

                         *(undefined4 *)(iVar3 + 0xa8));

            iVar3 = *(int *)(iVar4 + 0x58);

            FUN_00499310(iVar3,*(undefined4 *)(iVar3 + 0xa0),*(undefined4 *)(iVar3 + 0xa4),

                         *(undefined4 *)(iVar3 + 0xa8));

            iVar8 = iVar8 + 2;

          }

          else {

            if (iVar5 != 0) {

              FUN_00497510(iVar5);

            }

            if (*(int *)(iVar4 + 0x58) != 0) {

              FUN_00497510(*(int *)(iVar4 + 0x58));

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

/* ===== FUN_004775e0 @ 0x004775E0 ===== */
void FUN_004775e0(int param_1)



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

/* ===== FUN_00477da0 @ 0x00477DA0 ===== */
/* PS2 candidate: marker_spline_adjust_scale (conf 0.436) */



void FUN_00477da0(int param_1,float param_2,int param_3)



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

  FUN_00477f20(param_1,uVar4,uVar7);

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

  FUN_00477340(*(undefined4 *)(iVar1 + 0x40));

  return;

}

/* ===== marker_spline_adjust_location @ 0x00477F00 ===== */
void marker_spline_adjust_location(int param_1)



{

  marker_create_path__FP6OBJECTi(*(undefined4 *)(*(int *)(param_1 + 0x100) + 0x40),1);

  return;

}

/* ===== FUN_00477f20 @ 0x00477F20 ===== */
/* PS2 candidate: marker_spline_rotate_tangent (conf 0.562) */



void FUN_00477f20(int param_1,float param_2,int param_3)



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

    FUN_0053dd90(local_44,param_2 * 0.017453292);

    (*(code *)PTR_FUN_00580c20)(&local_50,(undefined4 *)(iVar4 + 0x14),1,local_44);

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

    FUN_0053dd90(local_44,param_2 * 0.017453292);

    (*(code *)PTR_FUN_00580c20)(&local_50,(undefined4 *)(iVar4 + 8),1,local_44);

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

  FUN_00477340(*(undefined4 *)(iVar1 + 0x40));

  return;

}

/* ===== FUN_00478080 @ 0x00478080 ===== */
undefined4 FUN_00478080(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)



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

    FUN_0053d940(*(undefined4 *)(iVar1 + 4),&local_1c,param_4);

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

/* ===== FUN_00478160 @ 0x00478160 ===== */
int FUN_00478160(int param_1,int *param_2)



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

  iVar2 = FUN_00478080(*param_2,(float)fVar4,iVar2,pfVar1);

  FUN_00414690(pfVar1,local_1c);

  if (*(int *)(*(int *)(*param_2 + 0x100) + 0x48) == 0) {

    *(float *)(param_1 + 0xa8) = local_c;

  }

  else if (*(float *)(param_1 + 0xa8) < local_c) {

    *(float *)(param_1 + 0xa8) = local_c;

  }

  if ((*(float *)(param_1 + 0xb8) != *pfVar1) ||

     (*(float *)(param_1 + 0xbc) != *(float *)(param_1 + 0xa4))) {

    fVar4 = (float10)FUN_0050a400(param_1 + 0xb8,pfVar1);

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

/* ===== FUN_00478260 @ 0x00478260 ===== */
/* PS2 candidate: formation_update_info (conf 0.595) */



void FUN_00478260(int param_1)



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

/* ===== FUN_004782d0 @ 0x004782D0 ===== */
/* PS2 candidate: formation_notify_death (conf 0.776) */



void FUN_004782d0(int param_1)



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

        FUN_00497510(iVar1);

      }

    }

    else if (*(int *)(iVar1 + 0x1e0) == 0x27) {

      iVar2 = *(int *)(*(int *)(iVar1 + 0x100) + 0x14);

      goto LAB_0047832a;

    }

    puVar3 = (undefined4 *)*puVar3;

  } while( true );

}

/* ===== FUN_004788e0 @ 0x004788E0 ===== */
/* PS2 candidate: mecc_play_weapon_select_snd (conf 0.437) */



void FUN_004788e0(undefined4 param_1,undefined4 param_2)



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

/* ===== FUN_004789e0 @ 0x004789E0 ===== */
/* PS2 candidate: getfirelockandgun__FP6OBJECTUcPP6OBJECTPi (conf 0.386) */



void FUN_004789e0(int param_1,char param_2,int *param_3,undefined4 *param_4)



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

      iVar4 = FUN_00456050(param_1);

      *param_4 = 1;

    }

    else {

      iVar4 = FUN_00456010();

      *param_4 = 1;

    }

  }

  piVar3 = (int *)FUN_004a8f50(param_2);

  if ((iVar4 != 0) && (*(int *)(iVar4 + 4) != *piVar3)) {

    *param_3 = iVar4;

    return;

  }

  *param_4 = 1;

  *param_3 = param_1;

  return;

}

/* ===== FUN_00478ad0 @ 0x00478AD0 ===== */
/* PS2 candidate: new_fire__FP6OBJECTiPfT0P3P3Df (conf 0.605) */



int FUN_00478ad0(float param_1,uint param_2,float *param_3,int param_4,float *param_5,float param_6)



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

  local_44 = FUN_004a8f50(uVar7);

  pfVar3 = param_3;

  fVar1 = param_1;

  if (((local_44 == 0) || (((~*(uint *)(local_44 + 4) & 1) == 0 && (param_4 == 0)))) ||

     ((param_3 != (float *)0x0 && (*param_3 < 0.0 == (*param_3 == 0.0))))) {

    return 0;

  }

  FUN_004789e0(param_1,uVar2,&param_2,&local_48);

  cVar6 = (char)uVar2;

  if (uVar2 == 0x2d) {

    FUN_004a76e0(fVar1,10,&local_24);

    local_30 = *param_5;

    local_2c = param_5[1];

    local_28 = param_5[2];

  }

  else {

    FUN_004a76e0(param_2,local_48,&local_24);

    if (param_4 != 0) {

      local_30 = *param_5;

      local_2c = param_5[1];

      local_28 = param_5[2];

      goto LAB_00478c22;

    }

    iVar4 = FUN_00455890(&local_30,param_6,local_40);

    if (*(int *)((int)fVar1 + 0x174) == 0) {

      iVar5 = FUN_0040cf70();

      pfVar3 = param_3;

      if (iVar5 == 0) {

        if ((*(int *)((int)fVar1 + 0x174) != 0) || (iVar4 == 0)) goto LAB_00478d28;

      }

      else if (iVar4 == 0) {

        pfVar3 = (float *)FUN_00515dc0(2);

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

      FUN_0050ae40(*(undefined4 *)((int)fVar1 + 200),&local_3c,&local_38);

      local_38 = -local_38;

      FUN_0050ae40(param_5,&local_4c,&param_1);

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

      fVar8 = (float10)FUN_004d5760(0x43b40000,&local_3c,&local_38);

      FUN_0050ae40((float)fVar8);

      local_38 = -local_38;

      fVar8 = (float10)FUN_004d5760(0x43b40000,&param_3,&param_6);

      FUN_0050ae40((float)fVar8);

      local_3c = param_6 * local_3c;

      local_38 = param_6 * local_38;

      local_34 = param_3;

      fVar8 = (float10)FUN_0050a580(&local_24,&local_30);

      fVar8 = fVar8 * (float10)0.01;

      local_30 = (float)((float10)local_3c * fVar8 + (float10)local_30);

      local_2c = (float)((float10)local_38 * fVar8 + (float10)local_2c);

      local_28 = (float)(fVar8 * (float10)(float)local_34 + (float10)local_28);

      FUN_004a76e0(param_2,0,&local_18);

    }

  }

  if (uVar2 == 0x2d) {

    iVar4 = FUN_004aa230(0x2d,*(undefined4 *)((int)fVar1 + 0x18c),fVar1,10,0,&local_30);

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

    iVar4 = FUN_004aa230(uVar7,*(undefined4 *)((int)fVar1 + 0x18c),param_2,local_48,param_4,

                         &local_30);

    if (uVar2 < 0x2e) goto LAB_00478e0d;

switchD_00478e15_caseD_5:

    uVar9 = 0;

  }

  ANM_DumpCluster(fVar1,uVar9);

  if (iVar4 != 0) {

    *(float *)(iVar4 + 0x274) = fVar1;

    iVar5 = main_0052e4a0(fVar1);

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

  FUN_00478f60(fVar1,uVar2);

  return iVar4;

}

/* ===== FUN_00478f60 @ 0x00478F60 ===== */
/* PS2 candidate: mecc_play_fire_snd__FP6OBJECTi (conf 0.515) */



void FUN_00478f60(int param_1,undefined4 param_2)



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

    iVar3 = FUN_004d5730(100);

    if (iVar3 < 0x32) {

      sound_play_player(0x5f7,param_1);

      return;

    }

    sound_play_player(0x5f8,param_1);

    return;

  case 0x18:

    if (*(int *)(iVar3 + 0x1fc) == 0) {

      iVar1 = main_0052e4a0(param_1);

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

/* ===== FUN_00479100 @ 0x00479100 ===== */
/* PS2 candidate: mecc_calculate_mass__FP6OBJECT (conf 0.656) */



void FUN_00479100(int param_1)



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

    iVar4 = FUN_004a8f70(uVar3);

    iVar4 = *(int *)(iVar4 + 0x18);

    uVar3 = FUN_00457fb0(param_1,iVar7);

    iVar5 = FUN_004a8f70(uVar3);

    iVar6 = iVar6 + iVar4 + *(int *)(iVar5 + 0x18);

    iVar7 = iVar7 + 1;

  } while (iVar7 < 3);

  iVar7 = FUN_004586e0(param_1);

  if (0 < iVar7) {

    uVar3 = FUN_004586e0(param_1);

    iVar7 = FUN_004a8f70(uVar3);

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

/* ===== FUN_004791f0 @ 0x004791F0 ===== */
/* PS2 candidate: MeccPhysicsExApplyLocation__FP6OBJECT (conf 0.389) */



void FUN_004791f0(int param_1)



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

  iVar4 = FUN_0052aa70();

  puVar2 = DAT_00632d70;

  if (iVar4 == 0) {

    for (; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {

      iVar4 = puVar2[3];

      iVar5 = FUN_004a6160(iVar4);

      if ((iVar5 != 0) && (*(int *)(iVar4 + 0x174) != 0)) {

        uVar1 = *(uint *)(iVar4 + 0x1c8);

        local_28[iVar6] = iVar4;

        iVar6 = iVar6 + 1;

        *(uint *)(iVar4 + 0x1c8) = uVar1 | 0x800;

      }

    }

    FUN_004a4360(iVar3);

    for (; iVar6 != 0; iVar6 = iVar6 + -1) {

      *(uint *)(local_28[iVar6 + -1] + 0x1c8) = *(uint *)(local_28[iVar6 + -1] + 0x1c8) & 0xfffff7ff

      ;

    }

  }

  else {

    FUN_004a4360(iVar3);

  }

  if ((*(float *)(iVar3 + 0x1c0) <= *(float *)(iVar3 + 0x278)) &&

     (*(float *)(iVar3 + 0xa8) < 0.0 != (*(float *)(iVar3 + 0xa8) == 0.0))) {

    *(int *)(iVar3 + 0x210) = param_1;

    FUN_004a7440(iVar3);

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

      FUN_004a1740(param_1);

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

/* ===== FUN_0047bdf0 @ 0x0047BDF0 ===== */
/* PS2 candidate: reset_scale__FP6OBJECT (conf 0.698) */



void FUN_0047bdf0(int param_1)



{

  int iVar1;

  

  iVar1 = FUN_00497d70(*(undefined4 *)(param_1 + 4));

  if (iVar1 != 0) {

    *(undefined4 *)(param_1 + 0xc4) = *(undefined4 *)(iVar1 + 0xc4);

  }

  return;

}

/* ===== FUN_0047be20 @ 0x0047BE20 ===== */
/* PS2 candidate: mecc_do_death (conf 0.461) */



void FUN_0047be20(float param_1,float param_2,int param_3,int param_4,float param_5)



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

  iVar3 = main_0052e4a0(param_3);

  if (iVar3 != 0) {

    reaper_00530bd0(iVar2,0,0,0,4,0);

  }

  bVar6 = param_1 == -NAN;

  if (((*(byte *)(iVar2 + 0xe0) & 0x20) != 0) &&

     ((iVar3 = FUN_0052e480(iVar2), iVar3 != 0 || (bVar6)))) {

    FUN_0050c2a0(iVar2);

  }

  if ((((*(int *)(iVar2 + 0x174) == 0) && (iVar3 = FUN_0052aa70(), iVar3 == 0)) &&

      (DAT_00632bbc != 0)) && (*(int *)(iVar4 + 0xd8) != 0)) {

    FUN_0041ee70(*(int *)(iVar4 + 0xd8));

  }

  FUN_00495700(0x5a5,iVar2);

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

    FUN_004a54a0();

    DAT_00632c00 = 1;

  }

  if (!bVar6) {

    sound_play_player(0x5e2,iVar2);

    iVar3 = FUN_004d5730(100);

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

  FUN_00495700(0x693,iVar2);

  FUN_00495700(0x694,iVar2);

  FUN_00495700(0x695,iVar2);

  FUN_00495700(0x696,iVar2);

  if (param_1 == 7.00649e-45) {

    iVar3 = FUN_0052e480(iVar2);

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

    uVar7 = FUN_004571a0(iVar2,&DAT_0057a778,param_5);

    *(undefined4 *)(iVar4 + 0xf0) = uVar7;

  }

LAB_0047c03e:

  iVar3 = FUN_0052e480(iVar2);

  if ((iVar3 != 0) || (bVar6)) {

    *(uint *)(iVar2 + 0xe0) = *(uint *)(iVar2 + 0xe0) & 0xfffbffff;

    uVar7 = FUN_004a8fb0(*(undefined4 *)(iVar4 + 0x18c),1);

    iVar3 = FUN_00458300(iVar2,0,uVar7);

    if (iVar3 != 0) {

      FUN_00497510(iVar3);

    }

    uVar7 = FUN_004a8fb0(*(undefined4 *)(iVar4 + 0x18c),1);

    iVar4 = FUN_00458300(iVar2,1,uVar7);

    if (iVar4 != 0) {

      FUN_00497510(iVar4);

    }

  }

  iVar4 = main_0052e4a0(iVar2);

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

      iVar5 = FUN_004a6140(iVar4);

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

      iVar5 = FUN_00521370(DAT_00632f18);

      if (iVar5 == 0) {

        param_1 = param_5;

      }

      else {

        param_1 = 0.0;

      }

      FUN_00530430(iVar4,iVar2,iVar3,*(int *)(iVar2 + 0x18c) + -1,param_5,param_1,0x3f800000,

                   0x3f800000);

    }

    param_3 = 0;

    FUN_00530f10(iVar2,0,0,4,3,&param_3);

  }

  *(uint *)(iVar2 + 0xe0) = *(uint *)(iVar2 + 0xe0) & 0xffffffbf;

  return;

}

/* ===== FUN_0047c1d0 @ 0x0047C1D0 ===== */
/* PS2 candidate: mecc_do_flare__FP6OBJECT (conf 0.494) */



void FUN_0047c1d0(int param_1)



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

    iVar2 = FUN_0045a2b0(param_1,0x40,0);

    if (0 < iVar2) {

      iVar2 = *(int *)(param_1 + 0x100);

      local_44[0] = 0;

      FUN_0053e460(local_44,-*(float *)(DAT_00632ed8 + 0x120c),0,*(undefined4 *)(param_1 + 200));

      FUN_004a76e0(param_1,10,&local_5c);

      local_50 = local_3c * -1000.0 + local_5c;

      local_4c = local_2c * -1000.0 + local_58;

      local_48 = local_1c * -1000.0 + local_54;

      iVar2 = FUN_00478ad0(param_1,0x2d,iVar2 + 0x38,0,&local_50,0x447a0000);

      if (iVar2 != 0) {

        FUN_0045a4c0(param_1,0x40);

      }

    }

  }

  return;

}

/* ===== FUN_0047c2d0 @ 0x0047C2D0 ===== */
void FUN_0047c2d0(int param_1)



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

    FUN_0047c440(param_1);

    *(uint *)(iVar2 + 0xd4) = *(uint *)(iVar2 + 0xd4) & 0xfffffff5;

  }

  return;

}

/* ===== FUN_0047c440 @ 0x0047C440 ===== */
/* PS2 candidate: mecc_do_health_grenade_mine2__FP6OBJECT (conf 0.507) */



void FUN_0047c440(int param_1)



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

        FUN_004582a0(param_1,iVar7,0xffffffff);

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

    uVar5 = FUN_004a9040(*(undefined4 *)(iVar1 + 0x124));

    iVar7 = FUN_004a8f50(uVar5);

    iVar4 = FUN_004add50(uVar5);

    local_10 = &LAB_0047c620;

    if (iVar4 != 0) {

      local_10 = *(undefined1 **)(iVar4 + 8);

    }

    if ((iVar7 != 0) && (iVar7 = FUN_0045a2b0(param_1,*(undefined4 *)(iVar1 + 0x124),0), 0 < iVar7))

    {

      if (*(int *)(iVar1 + 0x124) == 9) {

        param_1 = *(int *)(DAT_00632ed8 + 0x1058);

      }

      else if (*(int *)(iVar1 + 0x124) == 8) {

        param_1 = *(int *)(DAT_00632ed8 + 0x1054);

      }

      uVar6 = FUN_00455b70(local_10,*(undefined4 *)(iVar3 + 0x18c),param_1,local_c);

      iVar7 = FUN_00478ad0(iVar3,uVar5,0,uVar6,local_c,param_1);

      if (iVar7 != 0) {

        FUN_0045a4c0(iVar3,*(undefined4 *)(iVar1 + 0x124));

      }

    }

    *(undefined4 *)(iVar1 + 0x124) = 0xffffffff;

    return;

  }

  return;

}

/* ===== FUN_0047c680 @ 0x0047C680 ===== */
void FUN_0047c680(int param_1,int param_2,float param_3)



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

    FUN_00493d60(param_1,param_3);

    FUN_00497510(param_2);

    *(float *)(*(int *)(param_1 + 0x100) + 0x4c) =

         param_3 + *(float *)(*(int *)(param_1 + 0x100) + 0x4c);

    iVar1 = FUN_004d5730(100);

    if (iVar1 < 0x32) {

      uVar3 = 0x63d;

    }

    else {

      uVar3 = 0x63e;

    }

    sound_play_player(uVar3,param_1);

    FUN_004a5d10();

    iVar1 = main_0052e4a0(param_1);

    if (iVar1 != 0) {

      local_8 = *(undefined4 *)(*(int *)(param_1 + 0x100) + 0x4c);

      local_4 = *(undefined4 *)(param_2 + 0x188);

      reaper_00530bd0(param_1,1,1,0,0xd,&local_8);

    }

  }

  return;

}

/* ===== FUN_0047c7a0 @ 0x0047C7A0 ===== */
void FUN_0047c7a0(int param_1,undefined4 param_2,undefined4 *param_3,int param_4)



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

  FUN_00530d70(param_1,3,1,0,0x25,&local_10);

  return;

}

/* ===== FUN_0047c900 @ 0x0047C900 ===== */
void FUN_0047c900(int param_1)



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

  iVar4 = main_0052e4a0(param_1);

  if (iVar4 != 0) {

    iVar4 = FUN_0052e4b0(iVar3);

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

      FUN_00530f10(iVar3,9,0,0,1,&local_24);

    }

    iVar4 = FUN_0052e530(iVar3);

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

        FUN_00530f10(iVar3,6,0,4,2,&local_24);

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

      FUN_00530f10(iVar3,0,0,4,3,&param_1);

    }

  }

  return;

}

/* ===== FUN_0047caa0 @ 0x0047CAA0 ===== */
/* WARNING: Removing unreachable block (ram,0x0047ccef) */

/* WARNING: Removing unreachable block (ram,0x0047cd01) */

/* PS2 candidate: kbos_move (conf 0.446) */



void FUN_0047caa0(int param_1,undefined4 param_2,undefined4 param_3,float *param_4)



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

        FUN_00448920(*(int *)(iVar5 + 0xf4));

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

        FUN_00497570(iVar7);

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

      FUN_0047be20(0xffffffff,0,iVar7,0,0,0);

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

        FUN_00448920(*(int *)(iVar5 + 0x144));

        *(undefined4 *)(iVar5 + 0x144) = 0;

        iVar6 = main_0052e4a0(iVar7);

        if (iVar6 != 0) {

          reaper_00530bd0(iVar7,0,0,0,0x1f,0);

        }

      }

      if (*(int *)(iVar5 + 0x1ec) != 0) {

        FUN_00495ee0(iVar5 + 0x1ec);

      }

      *(undefined4 *)(iVar5 + 0x140) = 0;

      if (*(int *)(iVar5 + 0x18c) == 0x13) {

        FUN_00458180(iVar7,*(undefined4 *)(iVar5 + 0xfc));

        *(undefined4 *)(iVar5 + 0xfc) = 0xffffffff;

      }

      *(uint *)(iVar7 + 0xe0) = *(uint *)(iVar7 + 0xe0) & 0xfeffffff;

      iVar5 = main_0052e4a0(iVar7);

      if (iVar5 != 0) {

        reaper_00530bd0(iVar7,0,0,0,0x15,0);

      }

    }

    pfVar3 = param_4;

    if (*(char *)param_4 != -1) {

      *(undefined4 *)(*(int *)(iVar7 + 0x100) + 0x5c) = 0xffffffff;

    }

    FUN_00458180(iVar7,(int)*(char *)param_4);

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

    FUN_0047fff0(iVar7);

    return;

  case 0xc:

    if (((*(uint *)(iVar7 + 0xe0) & 0x2000000) != 0) && ((*(uint *)(iVar7 + 0xe0) & 0x4000000) == 0)

       ) {

      iVar5 = main_0052e4a0(iVar7);

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

    iVar5 = FUN_0052e5b0(param_4[1]);

    param_4 = (float *)*pfVar3;

    if (iVar5 != 0) {

      FUN_00497510(iVar5);

      iVar5 = FUN_004d5730(100);

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

    iVar7 = FUN_0052aa70();

    if (iVar7 == 0) {

      fVar9 = (float10)1.0;

    }

    else {

      fVar9 = (float10)FUN_00522130(DAT_00632f40);

    }

    FUN_00417880(*(undefined4 *)(iVar5 + 0xd8),

                 (float)((float10)*(float *)(DAT_00632ed8 + 0x61c) * fVar9));

    return;

  case 0x10:

    uVar4 = 0;

    if (param_4[3] != 0.0) {

      uVar4 = FUN_0052e5b0(param_4[3]);

    }

    FUN_004789e0(iVar7,*(undefined1 *)(pfVar3 + 5),&param_1,&param_4);

    iVar5 = FUN_004aa230(*(undefined1 *)(pfVar3 + 5),*(undefined4 *)(iVar7 + 0x18c),param_1,param_4,

                         uVar4,pfVar3);

    if (iVar5 != 0) {

      *(float *)(iVar5 + 0x188) = pfVar3[4];

      *(int *)(iVar5 + 0x274) = iVar7;

      FUN_00478f60(iVar7,*(undefined1 *)(pfVar3 + 5));

      return;

    }

    break;

  case 0x11:

    iVar5 = FUN_00458350(iVar7,(int)*(char *)(param_4 + 1));

    if (iVar5 != 0) {

      *(float *)(iVar5 + 0x188) = *pfVar3;

      return;

    }

    break;

  case 0x12:

    mecc_enable_personal_shield(iVar7);

    return;

  case 0x13:

    FUN_004802c0(iVar7);

    return;

  case 0x14:

    iVar5 = *(int *)(iVar7 + 0x100);

    if (*(int *)(iVar5 + 0x18c) == 0x13) {

      uVar4 = FUN_00458150(iVar7);

      *(undefined4 *)(iVar5 + 0xfc) = uVar4;

      FUN_00458180(iVar7,0x13);

      *(uint *)(iVar7 + 0xe0) = *(uint *)(iVar7 + 0xe0) | 0x1000000;

      iVar5 = main_0052e4a0(iVar7);

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

        FUN_00448920(*(int *)(iVar5 + 0x144));

        *(undefined4 *)(iVar5 + 0x144) = 0;

        iVar6 = main_0052e4a0(iVar7);

        if (iVar6 != 0) {

          reaper_00530bd0(iVar7,0,0,0,0x1f,0);

        }

      }

      if (*(int *)(iVar5 + 0x1ec) != 0) {

        FUN_00495ee0(iVar5 + 0x1ec);

      }

      *(undefined4 *)(iVar5 + 0x140) = 0;

      if (*(int *)(iVar5 + 0x18c) == 0x13) {

        FUN_00458180(iVar7,*(undefined4 *)(iVar5 + 0xfc));

        *(undefined4 *)(iVar5 + 0xfc) = 0xffffffff;

      }

      *(uint *)(iVar7 + 0xe0) = *(uint *)(iVar7 + 0xe0) & 0xfeffffff;

      iVar5 = main_0052e4a0(iVar7);

      if (iVar5 != 0) {

        reaper_00530bd0(iVar7,0,0,0,0x15,0);

        return;

      }

    }

    break;

  case 0x16:

    if (*(float *)(iVar5 + 0x18c) != *param_4) {

      FUN_00458350(iVar7,*param_4);

    }

    *(uint *)(iVar7 + 0xe0) = *(uint *)(iVar7 + 0xe0) | 0x40000;

    return;

  case 0x17:

    FUN_00481630(iVar7);

    return;

  case 0x18:

    iVar5 = FUN_0052e5b0(*param_4);

    if (iVar5 == 0) {

      iVar5 = FUN_00480f90(iVar7,0);

      *(undefined4 *)(iVar5 + 0x18c) = *(undefined4 *)(iVar7 + 0x18c);

      *(float *)(iVar5 + 0x188) = *pfVar3;

    }

    *(int *)(iVar5 + 0x210) = iVar7;

    *(undefined4 *)(iVar5 + 0x218) = 4;

    *(undefined4 *)(iVar5 + 0x214) = 0;

    *(uint *)(iVar7 + 0xe0) = *(uint *)(iVar7 + 0xe0) | 0x20000;

    *(uint *)(iVar7 + 0xd8) = *(uint *)(iVar7 + 0xd8) & 0xfff7ffff;

    *(uint *)(iVar5 + 0xe0) = *(uint *)(iVar5 + 0xe0) | 1;

    FUN_004034a0(iVar7,0xd3,0x21,0,0,0);

    FUN_00480a60(iVar7);

    iVar6 = main_0052e4a0(iVar5);

    if (iVar6 != 0) {

      param_4 = *(float **)(iVar5 + 0x188);

      reaper_00530bd0(iVar7,0,1,0,0x18,&param_4);

    }

    FUN_004802c0(iVar7);

    iVar5 = *(int *)(iVar7 + 0x100);

    if ((*(uint *)(iVar7 + 0xe0) & 0x1000000) != 0) {

      if (*(int *)(iVar5 + 0x144) != 0) {

        FUN_00448920(*(int *)(iVar5 + 0x144));

        *(undefined4 *)(iVar5 + 0x144) = 0;

        iVar6 = main_0052e4a0(iVar7);

        if (iVar6 != 0) {

          reaper_00530bd0(iVar7,0,0,0,0x1f,0);

        }

      }

      if (*(int *)(iVar5 + 0x1ec) != 0) {

        FUN_00495ee0(iVar5 + 0x1ec);

      }

      *(undefined4 *)(iVar5 + 0x140) = 0;

      if (*(int *)(iVar5 + 0x18c) == 0x13) {

        FUN_00458180(iVar7,*(undefined4 *)(iVar5 + 0xfc));

        *(undefined4 *)(iVar5 + 0xfc) = 0xffffffff;

      }

      *(uint *)(iVar7 + 0xe0) = *(uint *)(iVar7 + 0xe0) & 0xfeffffff;

      iVar5 = main_0052e4a0(iVar7);

      if (iVar5 != 0) {

        reaper_00530bd0(iVar7,0,0,0,0x15,0);

      }

    }

    if (((*(uint *)(iVar7 + 0xe0) & 0x2000000) != 0) && ((*(uint *)(iVar7 + 0xe0) & 0x4000000) == 0)

       ) {

      iVar5 = main_0052e4a0(iVar7);

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

      uVar4 = FUN_0052e5b0(*param_4);

      iVar5 = FUN_0052e5b0(pfVar3[1]);

      if (iVar5 == 0) {

        iVar5 = FUN_00480f90(iVar7,uVar4);

      }

      *(undefined4 *)(iVar5 + 0x18c) = *(undefined4 *)(iVar7 + 0x18c);

      *(float *)(iVar5 + 0x188) = pfVar3[1];

      *(uint *)(iVar7 + 0xe0) = *(uint *)(iVar7 + 0xe0) & 0xfffffdff;

      return;

    }

    break;

  case 0x1a:

    iVar5 = FUN_0052e5b0(*param_4);

    if (iVar5 == 0) {

      iVar5 = FUN_00480f90(iVar7,0);

      *(undefined4 *)(iVar5 + 0x18c) = *(undefined4 *)(iVar7 + 0x18c);

      *(float *)(iVar5 + 0x188) = *pfVar3;

    }

    fVar10 = pfVar3[1];

    *(int *)(iVar7 + 0x210) = iVar5;

    *(undefined4 *)(iVar7 + 0x214) = 4;

    *(uint *)(iVar7 + 0x218) = (fVar10 != 1.4013e-45) + 3;

    *(uint *)(iVar7 + 0xdc) = *(uint *)(iVar7 + 0xdc) | 0x8000;

    *(uint *)(iVar5 + 0xe0) = *(uint *)(iVar5 + 0xe0) | (uint)(fVar10 != 1.4013e-45) * 2 + 2;

    FUN_00480a60(iVar7);

    iVar6 = main_0052e4a0(iVar5);

    if (iVar6 != 0) {

      local_4c = *(undefined4 *)(iVar5 + 0x188);

      local_48 = fVar10;

      reaper_00530bd0(iVar7,0,2,0,0x1a,&local_4c);

    }

    FUN_004802c0(iVar7);

    iVar5 = *(int *)(iVar7 + 0x100);

    if ((*(uint *)(iVar7 + 0xe0) & 0x1000000) == 0) goto LAB_0047d6f9;

    if (*(int *)(iVar5 + 0x144) != 0) {

      FUN_00448920(*(int *)(iVar5 + 0x144));

      *(undefined4 *)(iVar5 + 0x144) = 0;

      iVar6 = main_0052e4a0(iVar7);

      if (iVar6 != 0) {

        reaper_00530bd0(iVar7,0,0,0,0x1f,0);

      }

    }

    if (*(int *)(iVar5 + 0x1ec) != 0) {

      FUN_00495ee0(iVar5 + 0x1ec);

    }

    *(undefined4 *)(iVar5 + 0x140) = 0;

    if (*(int *)(iVar5 + 0x18c) == 0x13) {

      uVar4 = *(undefined4 *)(iVar5 + 0xfc);

LAB_0047d6b8:

      FUN_00458180(iVar7,uVar4);

      *(undefined4 *)(iVar5 + 0xfc) = 0xffffffff;

    }

    goto LAB_0047d6cb;

  case 0x1b:

    uVar4 = FUN_0052e5b0(*param_4);

    iVar5 = FUN_0052e480(iVar7);

    if (iVar5 != 0) {

      FUN_00452490(0,uVar4);

      fVar9 = (float10)FUN_004a7630(uVar4,0);

      *(float *)(iVar7 + 200) = (float)fVar9;

      FUN_004a76e0(iVar7,0,(undefined4 *)(iVar7 + 0xa0));

      FUN_00499310(iVar7,*(undefined4 *)(iVar7 + 0xa0),*(undefined4 *)(iVar7 + 0xa4),

                   *(undefined4 *)(iVar7 + 0xa8));

      *(undefined1 *)(iVar7 + 0x20a) = 0;

      *(undefined1 *)(iVar7 + 0x20b) = 0;

      *(undefined1 *)(iVar7 + 0x208) = 0;

      *(uint *)(iVar7 + 0x20c) = *(uint *)(iVar7 + 0x20c) & 0xfffffbff;

    }

    iVar5 = FUN_0052e480(uVar4);

    if (iVar5 == 0) {

      FUN_00454dc0(uVar4,pfVar3[1]);

      return;

    }

    break;

  case 0x1c:

    if ((*(int *)(iVar5 + 0x19c) == 0) && (local_1c = FUN_00456050(iVar7), local_1c != 0)) {

      local_20 = 1;

      local_24 = 8;

      uVar4 = fx_get_free_effect__Fv();

      *(undefined4 *)(iVar5 + 0x19c) = uVar4;

      return;

    }

    break;

  case 0x1d:

    if (*(int *)(iVar5 + 0x19c) != 0) {

      FUN_00448920(*(int *)(iVar5 + 0x19c));

      *(undefined4 *)(iVar5 + 0x19c) = 0;

      return;

    }

    break;

  case 0x1e:

    if (*(int *)(iVar5 + 0x144) == 0) {

      FUN_004a8f50(0x13);

      local_1c = FUN_00456050(iVar7);

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

      FUN_00448920(*(int *)(iVar5 + 0x144));

      *(undefined4 *)(iVar5 + 0x144) = 0;

      iVar6 = main_0052e4a0(iVar7);

      if (iVar6 != 0) {

        reaper_00530bd0(iVar7,0,0,0,0x1f,0);

      }

    }

    if (*(int *)(iVar5 + 0x1ec) != 0) {

      FUN_00495ee0(iVar5 + 0x1ec);

    }

    *(undefined4 *)(iVar5 + 0x140) = 0;

    return;

  case 0x20:

    sound_play_3dpos(0x6ef,iVar7 + 0xa0);

    pfVar3 = param_4;

    FUN_004993c0(iVar7,param_4);

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

      FUN_00495e10(iVar5 + 0x1fc);

      return;

    }

    break;

  case 0x23:

    iVar5 = FUN_0052c5c0();

    if (iVar5 == 0) {

      return;

    }

    iVar5 = FUN_0052e5b0(*param_4);

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

      FUN_004034a0(iVar7,0xd3,0x21,0,0,0);

      FUN_00480a60(iVar7);

      iVar6 = main_0052e4a0(iVar5);

      if (iVar6 != 0) {

        param_4 = *(float **)(iVar5 + 0x188);

        reaper_00530bd0(iVar7,0,1,0,0x18,&param_4);

      }

      FUN_004802c0(iVar7);

      iVar5 = *(int *)(iVar7 + 0x100);

      if ((*(uint *)(iVar7 + 0xe0) & 0x1000000) != 0) {

        if (*(int *)(iVar5 + 0x144) != 0) {

          FUN_00448920(*(int *)(iVar5 + 0x144));

          *(undefined4 *)(iVar5 + 0x144) = 0;

          iVar6 = main_0052e4a0(iVar7);

          if (iVar6 != 0) {

            reaper_00530bd0(iVar7,0,0,0,0x1f,0);

          }

        }

        if (*(int *)(iVar5 + 0x1ec) != 0) {

          FUN_00495ee0(iVar5 + 0x1ec);

        }

        *(undefined4 *)(iVar5 + 0x140) = 0;

        if (*(int *)(iVar5 + 0x18c) == 0x13) {

          FUN_00458180(iVar7,*(undefined4 *)(iVar5 + 0xfc));

          *(undefined4 *)(iVar5 + 0xfc) = 0xffffffff;

        }

        *(uint *)(iVar7 + 0xe0) = *(uint *)(iVar7 + 0xe0) & 0xfeffffff;

        iVar5 = main_0052e4a0(iVar7);

        if (iVar5 != 0) {

          reaper_00530bd0(iVar7,0,0,0,0x15,0);

        }

      }

      if (((*(uint *)(iVar7 + 0xe0) & 0x2000000) != 0) &&

         ((*(uint *)(iVar7 + 0xe0) & 0x4000000) == 0)) {

        iVar5 = main_0052e4a0(iVar7);

        if (iVar5 != 0) {

          reaper_00530bd0(iVar7,0,0,0,0xc,0);

        }

        *(uint *)(iVar7 + 0xe0) = *(uint *)(iVar7 + 0xe0) | 0x4000000;

        *(undefined4 *)(iVar7 + 0x274) = 0;

        sound_play_player(0x572,iVar7);

      }

      goto LAB_0047d90a;

    }

    iVar6 = FUN_004a6160(iVar6);

    if (iVar6 == 0) {

      return;

    }

    uVar8 = *(uint *)(iVar5 + 0xe0);

    if ((uVar8 & 6) == 0) {

      FUN_00418630(iVar5,3,&local_4c);

      FUN_00418630(iVar5,4,local_40);

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

    FUN_00480a60(iVar7);

    iVar6 = main_0052e4a0(iVar5);

    if (iVar6 != 0) {

      local_4c = *(undefined4 *)(iVar5 + 0x188);

      local_48 = fVar10;

      reaper_00530bd0(iVar7,0,2,0,0x1a,&local_4c);

    }

    FUN_004802c0(iVar7);

    iVar5 = *(int *)(iVar7 + 0x100);

    if ((*(uint *)(iVar7 + 0xe0) & 0x1000000) == 0) goto LAB_0047d6f9;

    if (*(int *)(iVar5 + 0x144) != 0) {

      FUN_00448920(*(int *)(iVar5 + 0x144));

      *(undefined4 *)(iVar5 + 0x144) = 0;

      iVar6 = main_0052e4a0(iVar7);

      if (iVar6 != 0) {

        reaper_00530bd0(iVar7,0,0,0,0x1f,0);

      }

    }

    if (*(int *)(iVar5 + 0x1ec) != 0) {

      FUN_00495ee0(iVar5 + 0x1ec);

    }

    *(undefined4 *)(iVar5 + 0x140) = 0;

    if (*(int *)(iVar5 + 0x18c) == 0x13) {

      uVar4 = *(undefined4 *)(iVar5 + 0xfc);

      goto LAB_0047d6b8;

    }

LAB_0047d6cb:

    *(uint *)(iVar7 + 0xe0) = *(uint *)(iVar7 + 0xe0) & 0xfeffffff;

    iVar5 = main_0052e4a0(iVar7);

    if (iVar5 != 0) {

      reaper_00530bd0(iVar7,0,0,0,0x15,0);

    }

LAB_0047d6f9:

    if (((*(uint *)(iVar7 + 0xe0) & 0x2000000) != 0) && ((*(uint *)(iVar7 + 0xe0) & 0x4000000) == 0)

       ) {

      iVar5 = main_0052e4a0(iVar7);

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

    FUN_0047c7a0(iVar7,param_4[3],param_4,fVar10);

    break;

  case 0x26:

    iVar5 = FUN_0052c5c0();

    if ((iVar5 != 0) && (iVar5 = FUN_0052e5b0(*param_4), iVar5 != 0)) {

      iVar5 = FUN_00480f90(iVar7,iVar5);

      *(undefined4 *)(iVar5 + 0x18c) = *(undefined4 *)(iVar7 + 0x18c);

      return;

    }

  }

  return;

}

/* ===== FUN_0047df10 @ 0x0047DF10 ===== */
int FUN_0047df10(float param_1,float param_2,float param_3,code *param_4,undefined4 param_5)



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

  

  pfVar14 = (float *)FUN_00515db0();

  fVar1 = *pfVar14;

  fVar2 = pfVar14[1];

  fVar3 = pfVar14[2];

  pfVar14 = (float *)FUN_00515dc0(2);

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

  iVar6 = FUN_0052e480(param_1);

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

          iVar11 = FUN_004add50(1);

          puVar14 = &LAB_0047c620;

          if (iVar11 != 0) {

            puVar14 = *(undefined1 **)(iVar11 + 8);

          }

          FUN_00455890(&local_80,0x44898000,&local_94);

          _DAT_00632ba4 = (uint)((float)local_94 < 1100.0);

          uVar10 = FUN_00455b70(puVar14,param_1[99],local_94,&local_70);

          FUN_00478ad0(param_1,1,0,uVar10,&local_70,0x43fa0000);

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

    local_74 = FUN_00458150(param_1);

    if ((*(byte *)(param_1 + 0x83) & 0x10) != 0) {

      if (*(int *)(iVar3 + 0x118) != 0) {

        puVar1 = (uint *)(*(int *)(iVar3 + 0x118) + 0xd8);

        *puVar1 = *puVar1 | 0x40000000;

      }

      FUN_00495700(0x5a5,param_1);

      iVar6 = param_1[0x40];

      if ((param_1[0x38] & 0x1000000U) != 0) {

        if (*(int *)(iVar6 + 0x144) != 0) {

          FUN_00448920(*(int *)(iVar6 + 0x144));

          *(undefined4 *)(iVar6 + 0x144) = 0;

          iVar11 = main_0052e4a0(param_1);

          if (iVar11 != 0) {

            reaper_00530bd0(param_1,0,0,0,0x1f,0);

          }

        }

        if (*(int *)(iVar6 + 0x1ec) != 0) {

          FUN_00495ee0(iVar6 + 0x1ec);

        }

        *(undefined4 *)(iVar6 + 0x140) = 0;

        if (*(int *)(iVar6 + 0x18c) == 0x13) {

          FUN_00458180(param_1,*(undefined4 *)(iVar6 + 0xfc));

          *(undefined4 *)(iVar6 + 0xfc) = 0xffffffff;

        }

        param_1[0x38] = param_1[0x38] & 0xfeffffff;

        iVar6 = main_0052e4a0(param_1);

        if (iVar6 != 0) {

          reaper_00530bd0(param_1,0,0,0,0x15,0);

        }

      }

      FUN_00458040(param_1,1);

      param_1[0x83] = param_1[0x83] & 0xfffffffe;

    }

    if ((*(byte *)(param_1 + 0x83) & 0x20) != 0) {

      if (*(int *)(iVar3 + 0x118) != 0) {

        puVar1 = (uint *)(*(int *)(iVar3 + 0x118) + 0xd8);

        *puVar1 = *puVar1 | 0x40000000;

      }

      FUN_00495700(0x5a5,param_1);

      iVar6 = param_1[0x40];

      if ((param_1[0x38] & 0x1000000U) != 0) {

        if (*(int *)(iVar6 + 0x144) != 0) {

          FUN_00448920(*(int *)(iVar6 + 0x144));

          *(undefined4 *)(iVar6 + 0x144) = 0;

          iVar11 = main_0052e4a0(param_1);

          if (iVar11 != 0) {

            reaper_00530bd0(param_1,0,0,0,0x1f,0);

          }

        }

        if (*(int *)(iVar6 + 0x1ec) != 0) {

          FUN_00495ee0(iVar6 + 0x1ec);

        }

        *(undefined4 *)(iVar6 + 0x140) = 0;

        if (*(int *)(iVar6 + 0x18c) == 0x13) {

          FUN_00458180(param_1,*(undefined4 *)(iVar6 + 0xfc));

          *(undefined4 *)(iVar6 + 0xfc) = 0xffffffff;

        }

        param_1[0x38] = param_1[0x38] & 0xfeffffff;

        iVar6 = main_0052e4a0(param_1);

        if (iVar6 != 0) {

          reaper_00530bd0(param_1,0,0,0,0x15,0);

        }

      }

      FUN_00458040(param_1,0);

      param_1[0x83] = param_1[0x83] & 0xfffffffe;

    }

    iVar6 = FUN_004a9040(local_74);

    local_88 = iVar6;

    local_84 = FUN_004a8f50(iVar6);

  }

  else {

    local_74 = 0xffffffff;

    local_88 = 0x18;

    local_84 = FUN_004a8f50(0x18);

    iVar6 = local_88;

  }

  piVar15 = (int *)0x0;

  if (param_1 == DAT_00632a88) {

    iVar7 = FUN_0040ce90();

    iVar11 = local_88;

    if ((iVar7 != 0) && ((iVar6 != 4 || (0.0 < *(float *)(iVar3 + 0x110))))) {

      iVar6 = FUN_004add50(local_88);

      local_58 = (code *)&LAB_0047c620;

      if (iVar6 != 0) {

        local_58 = *(code **)(iVar6 + 8);

      }

      pcVar5 = local_58;

      FUN_00455890(local_c,*(float *)(local_84 + 0x2c) * 1.2,&local_94);

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

          pfVar8 = (float *)FUN_00515db0();

          local_50 = *pfVar8;

          local_4c = pfVar8[1];

          local_48 = pfVar8[2];

          pfVar8 = (float *)FUN_00515dc0(2);

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

        piVar15 = (int *)FUN_00455b70(pcVar5,param_1[99],local_94,&local_70);

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

    FUN_00495700(0x5a5,param_1);

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

    uVar10 = FUN_00515db0(&local_70);

    fVar16 = (float10)FUN_0050a610(uVar10);

    if (fVar16 < (float10)local_98 * (float10)local_98) {

      if ((param_1 == DAT_00632a88) && (piVar15[0x78] != 0)) {

        _DAT_00632ba0 = 1;

      }

      if (iVar6 != 4) {

        fVar16 = (float10)*(float *)(DAT_00632ed8 + 0x8f4);

        goto LAB_0047e8af;

      }

      iVar6 = FUN_0045a2b0(param_1,local_74,0);

      if (iVar6 < 1) {

        fVar16 = (float10)*(float *)(DAT_00632ed8 + 0x8f4);

        goto LAB_0047e8af;

      }

      fVar16 = (float10)FUN_00518b70(param_1,0);

      fVar16 = (float10)*(float *)(iVar3 + 0x110) - fVar16;

      goto LAB_0047e8b9;

    }

  }

  local_98 = (float)FUN_00456050(param_1);

  if (local_98 == 0.0) {

    return;

  }

  if (((((*(byte *)(param_1 + 0x83) & 1) == 0) || (*(int *)(iVar3 + 0x214) != 0)) ||

      (iVar6 = dialog_level_is_base(), iVar6 == 0)) ||

     ((DAT_00633020 != 0 || (uVar12 = param_1[0x38], (uVar12 & 0x100000) != 0)))) {

    if (*(int *)(iVar3 + 0x19c) != 0) {

      iVar6 = main_0052e4a0(param_1);

      if (iVar6 != 0) {

        reaper_00530bd0(param_1,0,0,0,0x1d,0);

      }

      FUN_00448920(*(undefined4 *)(iVar3 + 0x19c));

      *(undefined4 *)(iVar3 + 0x19c) = 0;

      ANM_DumpCluster(param_1,1);

    }

    if (*(int *)(iVar3 + 0x1fc) != 0) {

      iVar6 = main_0052e4a0(param_1);

      if (iVar6 != 0) {

        reaper_00530bd0(param_1,0,0,0,0x22,0);

      }

      FUN_00495e10(iVar3 + 0x1fc);

    }

    uVar10 = local_74;

    if (local_88 == 0x13) {

      iVar6 = param_1[0x40];

      if (*(int *)(iVar6 + 0x144) != 0) {

        FUN_00448920(*(int *)(iVar6 + 0x144));

        *(undefined4 *)(iVar6 + 0x144) = 0;

        iVar11 = main_0052e4a0(param_1);

        if (iVar11 != 0) {

          reaper_00530bd0(param_1,0,0,0,0x1f,0);

        }

      }

      if (*(int *)(iVar6 + 0x1ec) != 0) {

        FUN_00495ee0(iVar6 + 0x1ec);

      }

      *(undefined4 *)(iVar6 + 0x140) = 0;

    }

    else if (((local_88 == 4) &&

             (*(float *)(iVar3 + 0x110) < 0.0 != (*(float *)(iVar3 + 0x110) == 0.0))) &&

            (((*(byte *)(param_1 + 0x83) & 0x30) == 0 &&

             ((local_84 != 0 && (iVar6 = FUN_0045a2b0(param_1,local_74,0), 0 < iVar6)))))) {

      FUN_0040d6f0(&local_54,&local_44,&local_98,&local_80);

      FUN_0050ae40(local_54,&local_8c,&local_58);

      FUN_0050ae40(local_44,&local_94,&local_90);

      local_70 = (float)local_90 * local_8c * 2000.0 + local_80;

      local_6c = -((float)local_90 * (float)local_58) * 2000.0 + local_7c;

      local_68 = (float)local_94 * 2000.0 + local_78;

      iVar6 = FUN_00478ad0(param_1,4,iVar3 + 0x38,*(undefined4 *)(iVar3 + 0x11c),&local_70,

                           0x43fa0000);

      if (iVar6 != 0) {

        FUN_0045a4c0(param_1,uVar10);

      }

      if (*(int *)(iVar3 + 0x118) != 0) {

        FUN_00495700(0x5a5,param_1);

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

      if ((param_1[0x5d] < 1) || (fVar9 = (float)FUN_00456010(param_1), fVar9 == 0.0))

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

          iVar6 = FUN_00455070(param_1,*(undefined4 *)(iVar3 + 0x11c),

                               *(undefined4 *)(DAT_00632ed8 + 0x8f8));

          if (iVar6 == 0) {

            FUN_00495700(0x5a5,param_1);

            *(undefined4 *)(iVar3 + 0x1dc) = 0;

            *(undefined4 *)(iVar3 + 0x11c) = 0;

            uVar10 = *(undefined4 *)(DAT_00632ed8 + 0x8f4);

            *(undefined4 *)(iVar3 + 0x114) = 0;

            *(undefined4 *)(iVar3 + 0x110) = uVar10;

          }

        }

        if (*(int *)(iVar3 + 0x11c) == 0) {

          FUN_00495700(0x5a5,param_1);

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

          FUN_0053d9e0(*(int *)(iVar3 + 0x118) + 0x294);

          FUN_004a2c50(*(int *)(iVar3 + 0x118) + 0x294,piVar15,0x40000000);

        }

      }

      goto LAB_0047f2bb;

    }

  }

  else {

    iVar6 = FUN_0045a2b0(param_1,local_74,0);

    if (iVar6 < 1) {

      if (*(int *)(iVar3 + 0x19c) != 0) {

        iVar6 = main_0052e4a0(param_1);

        if (iVar6 != 0) {

          reaper_00530bd0(param_1,0,0,0,0x1d,0);

        }

        FUN_00448920(*(undefined4 *)(iVar3 + 0x19c));

        *(undefined4 *)(iVar3 + 0x19c) = 0;

        ANM_DumpCluster(param_1,1);

      }

      if (*(int *)(iVar3 + 0x1fc) != 0) {

        iVar6 = main_0052e4a0(param_1);

        if (iVar6 != 0) {

          reaper_00530bd0(param_1,0,0,0,0x22,0);

        }

        FUN_00495e10(iVar3 + 0x1fc);

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

        iVar6 = main_0052e4a0(param_1,pcVar17,uVar18,puVar14);

        if (iVar6 != 0) {

          reaper_00530bd0(param_1,0,0,0,0x1c,0);

        }

        ANM_DumpCluster(param_1,1);

      }

LAB_0047eacc:

      iVar6 = FUN_00478ad0(param_1,local_88,iVar3 + 0x38,piVar15,&local_70,0x43fa0000);

      if (iVar6 != 0) {

        FUN_0045a4c0(param_1,local_74);

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

    FUN_0050a810(&local_80,&local_7c,&local_78);

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

           (iVar11 = FUN_004adbf0(iVar6,param_1[99]), iVar11 != 0)) {

          iVar11 = FUN_004a6220(iVar6);

          if ((iVar11 == 0) || (3 < *(int *)(iVar6 + 0xe4))) {

            *(undefined4 *)(iVar3 + 0x140) = 1;

            if (*(float *)(iVar3 + 0x13c) < 0.0 != (*(float *)(iVar3 + 0x13c) == 0.0)) {

              iVar11 = FUN_004a6160(iVar6);

              if (iVar11 == 0) {

                fVar9 = *(float *)(DAT_00632ed8 + 0xfac);

              }

              else {

                fVar9 = *(float *)(DAT_00632ed8 + 0x137c);

              }

              FUN_00456f80(0x12,-fVar9,iVar6,0,iVar6 + 0xa0,0);

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

      FUN_00448920(*(int *)(iVar6 + 0x144));

      *(undefined4 *)(iVar6 + 0x144) = 0;

      iVar11 = main_0052e4a0(param_1);

      if (iVar11 != 0) {

        reaper_00530bd0(param_1,0,0,0,0x1f,0);

      }

    }

    if (*(int *)(iVar6 + 0x1ec) != 0) {

      FUN_00495ee0(iVar6 + 0x1ec);

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

      iVar6 = main_0052e4a0(param_1,iVar6,uVar18,puVar14);

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

/* ===== FUN_0047f370 @ 0x0047F370 ===== */
/* PS2 candidate: mecc_calc_thrust_for_height (conf 0.453) */



void FUN_0047f370(int param_1,float param_2)



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

  FUN_0047f520(param_1,0x3f800000,&local_c,&local_10);

  fVar3 = local_c * fVar1 * 4.0 + *(float *)(param_1 + 0x108);

  local_8 = fVar1 * *(float *)(param_1 + 0x1b8);

  if (local_10 < fVar3 - local_8) {

    fVar3 = local_10;

  }

  fVar3 = ((fVar3 - local_8 * 4.0) + *(float *)(param_1 + 0x108)) * fVar1;

  local_4 = fVar3 + fVar3 + *(float *)(param_1 + 0xa8);

  FUN_0047f520(param_1,0x3f000000,&local_c,&local_10);

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

/* ===== FUN_0047f520 @ 0x0047F520 ===== */
/* PS2 candidate: mecc_get_thrust__FP6OBJECTfPfT2 (conf 0.437) */



void FUN_0047f520(float param_1,float param_2,float *param_3,float *param_4)



{

  float fVar1;

  float fVar2;

  int iVar3;

  float10 fVar4;

  float10 fVar5;

  

  iVar3 = (int)param_1;

  fVar4 = (float10)FUN_00414680(param_1);

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

/* ===== FUN_0047f730 @ 0x0047F730 ===== */
/* PS2 candidate: mecc_in_gyro (conf 0.508) */



uint FUN_0047f730(int param_1)



{

  return *(uint *)(param_1 + 0xe0) & 0x20000;

}

/* ===== FUN_0047f740 @ 0x0047F740 ===== */
/* PS2 candidate: mecc_jet (conf 0.525) */



void FUN_0047f740(float param_1)



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

      FUN_0040d790();

    }

    else {

      param_1 = 0.0;

      iVar6 = ref_get_anode2(local_44,&param_1,fVar5,*(undefined4 *)((int)fVar5 + 0x10),0xe,0);

      if (iVar6 == 0) {

        ref_get_anode2(local_44,&param_1,fVar5,1,0xe,0);

      }

      FUN_0040d7e0(local_44);

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

      iVar6 = FUN_004586e0(fVar5);

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

    FUN_0050a810(&local_50,&local_4c,&local_48);

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

      FUN_004802c0(fVar5);

      if (((*(uint *)((int)fVar5 + 0xe0) & 0x2000000) != 0) &&

         ((*(uint *)((int)fVar5 + 0xe0) & 0x4000000) == 0)) {

        iVar6 = main_0052e4a0(fVar5);

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

    iVar6 = FUN_004586e0(fVar5);

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

            FUN_004586e0(fVar5);

            uVar8 = sound_get_free_sequence__Fv();

            *(undefined4 *)(iVar2 + 0x1e4) = uVar8;

            ANM_DumpCluster(fVar5,2);

            return;

          }

        }

        else {

          if (*(int *)(iVar2 + 0x1e4) != 0) {

            FUN_00495ee0(iVar2 + 0x1e4);

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

         (iVar7 = FUN_00498cd0(fVar5), iVar7 != 0)) {

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

/* ===== FUN_0047fff0 @ 0x0047FFF0 ===== */
/* PS2 candidate: mecc_to_bush (conf 0.603) */



void FUN_0047fff0(int param_1)



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

  FUN_004967e0(param_1,0x2e);

  FUN_004967e0(iVar2,0x2e);

  *(int *)(param_1 + 0x274) = iVar2;

  *(int *)(iVar2 + 0x274) = param_1;

  *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 0x2000000;

  *(int *)(iVar2 + 0x210) = param_1;

  *(undefined4 *)(iVar2 + 0x214) = 0xffffffff;

  *(undefined4 *)(iVar2 + 0x218) = 0xffffffff;

  *(uint *)(iVar2 + 0xd8) = *(uint *)(iVar2 + 0xd8) | 0x400000;

  uVar3 = FUN_004a8fb0(*(undefined4 *)(iVar4 + 0x18c),1);

  iVar4 = FUN_00458300(param_1,10,uVar3);

  if (iVar4 != 0) {

    *(undefined4 *)(iVar4 + 0x184) = 0x3f800000;

  }

  iVar4 = FUN_00456010(param_1);

  if (iVar4 != 0) {

    *(uint *)(iVar4 + 0xd8) = *(uint *)(iVar4 + 0xd8) | 0x40000000;

  }

  iVar4 = FUN_00456050(param_1);

  if (iVar4 != 0) {

    *(uint *)(iVar4 + 0xd8) = *(uint *)(iVar4 + 0xd8) | 0x40000000;

  }

  iVar4 = main_0052e4a0(param_1);

  if (iVar4 != 0) {

    reaper_00530bd0(param_1,0,0,0,0xb,0);

  }

  sound_play_player(0x571,param_1);

  return;

}

