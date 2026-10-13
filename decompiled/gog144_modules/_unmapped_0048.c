/* Giants 1.449 — module _unmapped_0048
 * 74 functions (25 named) — decompiled, names from PS2 symbols
 * Original source: C:\Giants\source\_unmapped_0048.c(pp) (assert-string evidence)
 */

/* ===== FUN_00480150 @ 0x00480150 ===== */
/* PS2 candidate: mecc_exit_bush (conf 0.499) */



void FUN_00480150(int param_1)



{

  int iVar1;

  

  if (((*(uint *)(param_1 + 0xe0) & 0x2000000) != 0) &&

     ((*(uint *)(param_1 + 0xe0) & 0x4000000) == 0)) {

    iVar1 = reaper_0052e4a0(param_1);

    if (iVar1 != 0) {

      reaper_00530bd0(param_1,0,0,0,0xc,0);

    }

    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 0x4000000;

    *(undefined4 *)(param_1 + 0x274) = 0;

    sound_play_player(0x572,param_1);

  }

  return;

}

/* ===== mecc_enable_personal_shield @ 0x004801C0 ===== */
/* PS2 candidate: mecc_enable_personal_shield (conf 0.5880000000000001) */



void mecc_enable_personal_shield(int param_1)



{

  int iVar1;

  int iVar2;

  undefined4 uVar3;

  char *pcVar4;

  undefined4 uVar5;

  undefined1 *puVar6;

  undefined1 local_34 [16];

  undefined4 local_24;

  undefined4 local_20;

  int local_1c;

  

  iVar1 = *(int *)(param_1 + 0x100);

  iVar2 = FUN_0052e480(param_1);

  if (iVar2 == 0) {

    if (*(int *)(iVar1 + 0x18c) == 0x11) goto LAB_00480200;

    FUN_00458350(param_1,0x11);

  }

  if (*(int *)(iVar1 + 0x18c) != 0x11) {

    return;

  }

LAB_00480200:

  uVar3 = FUN_004a8fb0(0x11,1);

  iVar2 = FUN_00458300(param_1,10,uVar3);

  if (iVar2 != 0) {

    puVar6 = local_34;

    uVar5 = 0x24;

    pcVar4 = s_fxb_shield_0055bd38;

    local_20 = 1;

    local_24 = 8;

    local_1c = iVar2;

    uVar3 = fx_get_free_effect__Fv();

    *(undefined4 *)(iVar1 + 0xf8) = uVar3;

    FUN_004034a0(iVar2,1,0x20,0,0,0,pcVar4,uVar5,puVar6);

  }

  *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 0x800000;

  ANM_DumpCluster(param_1,0x1d);

  iVar2 = reaper_0052e4a0(param_1);

  if (iVar2 != 0) {

    reaper_00530bd0(param_1,0,0,0,0x12,0);

  }

  uVar3 = sound_get_free_sequence__Fv();

  *(undefined4 *)(iVar1 + 0x1e8) = uVar3;

  return;

}

/* ===== FUN_004802c0 @ 0x004802C0 ===== */
/* PS2 candidate: mecc_disable_personal_shield (conf 0.543) */



void FUN_004802c0(int param_1)



{

  int iVar1;

  undefined4 uVar2;

  int iVar3;

  

  iVar3 = *(int *)(param_1 + 0x100);

  if ((*(uint *)(param_1 + 0xe0) & 0x800000) == 0) {

    return;

  }

  iVar1 = FUN_0052e480(param_1);

  if (iVar1 == 0) {

    if (*(int *)(iVar3 + 0x18c) != 0x11) {

      FUN_00458350(param_1,0x11);

      goto LAB_004802fd;

    }

  }

  else {

LAB_004802fd:

    if (*(int *)(iVar3 + 0x18c) != 0x11) goto LAB_00480357;

  }

  uVar2 = FUN_004a8fb0(0x11,1);

  iVar1 = FUN_00458300(param_1,10,uVar2);

  if (iVar1 != 0) {

    FUN_004034a0(iVar1,1,0x10,0,0,0);

    FUN_00448920(*(undefined4 *)(iVar3 + 0xf8));

    *(undefined4 *)(iVar3 + 0xf8) = 0;

  }

  FUN_00495ee0(iVar3 + 0x1e8);

LAB_00480357:

  *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xff7fffff;

  ANM_DumpCluster(param_1,0x1d);

  iVar3 = reaper_0052e4a0(param_1);

  if (iVar3 != 0) {

    reaper_00530bd0(param_1,0,0,0,0x13,0);

  }

  return;

}

/* ===== FUN_004803a0 @ 0x004803A0 ===== */
/* PS2 candidate: mecc_enable_repair_gun (conf 0.579) */



void FUN_004803a0(int param_1)



{

  undefined4 uVar1;

  int iVar2;

  

  iVar2 = *(int *)(param_1 + 0x100);

  if (*(int *)(iVar2 + 0x18c) == 0x13) {

    uVar1 = FUN_00458150(param_1);

    *(undefined4 *)(iVar2 + 0xfc) = uVar1;

    FUN_00458180(param_1,0x13);

    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 0x1000000;

    iVar2 = reaper_0052e4a0(param_1);

    if (iVar2 != 0) {

      reaper_00530bd0(param_1,0,0,0,0x14,0);

    }

  }

  return;

}

/* ===== FUN_00480400 @ 0x00480400 ===== */
/* PS2 candidate: mecc_disable_repair_gun (conf 0.63) */



void FUN_00480400(int param_1)



{

  int iVar1;

  int iVar2;

  

  iVar2 = *(int *)(param_1 + 0x100);

  if ((*(uint *)(param_1 + 0xe0) & 0x1000000) != 0) {

    if (*(int *)(iVar2 + 0x144) != 0) {

      FUN_00448920(*(int *)(iVar2 + 0x144));

      *(undefined4 *)(iVar2 + 0x144) = 0;

      iVar1 = reaper_0052e4a0(param_1);

      if (iVar1 != 0) {

        reaper_00530bd0(param_1,0,0,0,0x1f,0);

      }

    }

    if (*(int *)(iVar2 + 0x1ec) != 0) {

      FUN_00495ee0(iVar2 + 0x1ec);

    }

    *(undefined4 *)(iVar2 + 0x140) = 0;

    if (*(int *)(iVar2 + 0x18c) == 0x13) {

      FUN_00458180(param_1,*(undefined4 *)(iVar2 + 0xfc));

      *(undefined4 *)(iVar2 + 0xfc) = 0xffffffff;

    }

    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xfeffffff;

    iVar2 = reaper_0052e4a0(param_1);

    if (iVar2 != 0) {

      reaper_00530bd0(param_1,0,0,0,0x15,0);

    }

  }

  return;

}

/* ===== FUN_004804d0 @ 0x004804D0 ===== */
/* PS2 candidate: mecc_repairwand_off (conf 0.371) */



void FUN_004804d0(int param_1)



{

  int iVar1;

  int iVar2;

  

  iVar1 = *(int *)(param_1 + 0x100);

  if (*(int *)(iVar1 + 0x144) != 0) {

    FUN_00448920(*(int *)(iVar1 + 0x144));

    *(undefined4 *)(iVar1 + 0x144) = 0;

    iVar2 = reaper_0052e4a0(param_1);

    if (iVar2 != 0) {

      reaper_00530bd0(param_1,0,0,0,0x1f,0);

    }

  }

  if (*(int *)(iVar1 + 0x1ec) != 0) {

    FUN_00495ee0(iVar1 + 0x1ec);

  }

  *(undefined4 *)(iVar1 + 0x140) = 0;

  return;

}

/* ===== FUN_00480540 @ 0x00480540 ===== */
/* PS2 candidate: mecc_special_weapon_logic__FP6OBJECT (conf 0.417) */



void FUN_00480540(int param_1)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int *piVar4;

  undefined4 uVar5;

  int iVar6;

  char *pcVar7;

  float local_14;

  float local_10;

  float local_c;

  float local_8;

  undefined4 local_4;

  

  *(uint *)(param_1 + 0x20c) = *(uint *)(param_1 + 0x20c) & 0xfffffff7;

  iVar1 = *(int *)(*(int *)(param_1 + 0x100) + 0xd8);

  if ((iVar1 == 0) || (piVar4 = DAT_00632d98, DAT_00632d98 == (int *)0x0)) {

    return;

  }

  while( true ) {

    iVar2 = piVar4[3];

    iVar3 = *(int *)(iVar2 + 0x100);

    if ((((*(int *)(iVar2 + 0x274) == param_1) && (*(int *)(iVar2 + 4) == 0xb)) &&

        (*(int *)(iVar3 + 0x54) != 0)) && ((*(uint *)(iVar2 + 0xe0) & 0x200) == 0)) break;

    piVar4 = (int *)*piVar4;

    if (piVar4 == (int *)0x0) {

      return;

    }

  }

  if (((**(char **)(param_1 + 0x104) < '\0') || (*(int *)(iVar3 + 0x54) == 1)) ||

     (*(int *)(iVar3 + 0x54) == 3)) {

    if ((*(int *)(param_1 + 0x224) == 0) ||

       ((*(int *)(iVar3 + 0x54) != 2 && (*(int *)(iVar3 + 0x54) != 4)))) {

      if ((0.0 <= *(float *)(param_1 + 0xa8)) ||

         ((*(int *)(iVar3 + 0x54) == 1 || (*(int *)(iVar3 + 0x54) == 3)))) {

        iVar6 = FUN_0052aa70();

        if ((iVar6 == 0) || (iVar6 = FUN_0052c5c0(), iVar6 != 0)) {

          FUN_004f3de0(iVar2,*(undefined4 *)(iVar3 + 0x54),iVar1,param_1,param_1 + 0xa0,

                       *(float *)(param_1 + 200) + 180.0);

        }

        else {

          FUN_004f4020(iVar2,*(undefined4 *)(iVar3 + 0x54),iVar1,param_1,param_1 + 0xa0,

                       *(float *)(param_1 + 200) + 180.0);

        }

        FUN_0050ae40(*(undefined4 *)(param_1 + 200),&local_14,&local_10);

        local_4 = *(undefined4 *)(param_1 + 0xa8);

        local_c = *(float *)(param_1 + 0xa0) - local_14 * 20.0;

        local_8 = *(float *)(param_1 + 0xa4) - local_10 * -20.0;

        FUN_004993c0(param_1,&local_c);

        return;

      }

      pcVar7 = s_PhErrNotGround_0055bd44;

    }

    else {

      pcVar7 = s_PhErrNotGroundOrWater_0055bd54;

    }

  }

  else {

    pcVar7 = s_PhErrNotOnSomething_0055bc70;

  }

  uVar5 = FUN_00507b00(pcVar7,1);

  FUN_005362d0(uVar5);

  return;

}

/* ===== FUN_00480730 @ 0x00480730 ===== */
/* PS2 candidate: mecc_bush_logic (conf 0.461) */



void FUN_00480730(int param_1)



{

  int iVar1;

  undefined4 *puVar2;

  int iVar3;

  undefined4 uVar4;

  bool bVar5;

  float10 fVar6;

  float10 fVar7;

  

  iVar3 = FUN_0052aa70();

  if (iVar3 == 0) {

    bVar5 = false;

  }

  else {

    bVar5 = *(int *)(param_1 + 0x18c) != *(int *)(DAT_00632a88 + 0x18c);

  }

  iVar3 = *(int *)(param_1 + 0x10);

  if (iVar3 == 0x2f) {

    if (0.0 < *(float *)(param_1 + 0x184)) {

      fVar6 = (float10)FUN_00518b70(param_1,0);

      fVar6 = (float10)*(float *)(param_1 + 0x184) - (fVar6 + fVar6);

      *(float *)(param_1 + 0x184) = (float)fVar6;

      if (fVar6 < (float10)0.0) {

        *(undefined4 *)(param_1 + 0x184) = 0;

      }

    }

    if (((*(byte *)(param_1 + 0x30) & 2) != 0) &&

       (FUN_00497510(param_1), *(int *)(param_1 + 0x274) != 0)) {

      uVar4 = FUN_004a8fb0(0x14,1);

      iVar3 = FUN_00458300(*(undefined4 *)(param_1 + 0x274),10,uVar4);

      if (iVar3 != 0) {

        *(undefined4 *)(iVar3 + 0x184) = 0;

      }

    }

    goto LAB_00480988;

  }

  iVar1 = *(int *)(param_1 + 0x274);

  if (iVar1 == 0) {

LAB_0048097d:

    uVar4 = 0x2f;

  }

  else {

    if ((((*(uint *)(iVar1 + 0xe0) & 0x2000000) == 0) ||

        ((*(uint *)(iVar1 + 0xe0) & 0x4000000) != 0)) ||

       (*(float *)(iVar1 + 0x1c0) <= *(float *)(iVar1 + 0x278))) {

      puVar2 = DAT_00632d68;

      if (iVar1 != 0) {

        for (; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {

          iVar3 = puVar2[3];

          if (((*(int *)(iVar3 + 0x210) == iVar1) && (*(int *)(iVar3 + 4) != 0x24)) &&

             (*(int *)(iVar3 + 4) != 0x398)) {

            *(undefined4 *)(iVar3 + 0x184) = 0;

          }

        }

        *(undefined4 *)(iVar1 + 0x184) = 0;

      }

      goto LAB_0048097d;

    }

    if (iVar3 == 0x2e) {

      if ((((*(byte *)(param_1 + 0x30) & 2) != 0) && (FUN_00496840(param_1,1), bVar5)) &&

         (iVar3 = *(int *)(param_1 + 0x274), puVar2 = DAT_00632d68, iVar3 != 0)) {

        for (; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {

          iVar1 = puVar2[3];

          if (((*(int *)(iVar1 + 0x210) == iVar3) && (*(int *)(iVar1 + 4) != 0x24)) &&

             (*(int *)(iVar1 + 4) != 0x398)) {

            *(undefined4 *)(iVar1 + 0x184) = 0x3f800000;

          }

        }

        *(undefined4 *)(iVar3 + 0x184) = 0x3f800000;

      }

      goto LAB_00480988;

    }

    if (iVar3 == 0) {

      if ((*(byte *)(param_1 + 0x30) & 2) != 0) {

        FUN_00496840(param_1,1);

      }

      goto LAB_00480988;

    }

    if (iVar3 != 1) {

      if (bVar5) {

        *(undefined4 *)(param_1 + 0x184) = 0x3f4ccccd;

      }

      goto LAB_00480988;

    }

    if (((*(float *)(iVar1 + 0x10c) == 0.0) && (*(float *)(iVar1 + 0x110) == 0.0)) &&

       (*(float *)(iVar1 + 0x114) == 0.0)) {

      if (((*(byte *)(param_1 + 0x30) & 2) == 0) || (iVar3 = FUN_004d5730(100), iVar3 < 0x42))

      goto LAB_00480988;

      uVar4 = 0;

    }

    else {

      uVar4 = 0;

    }

  }

  FUN_004967e0(param_1,uVar4);

LAB_00480988:

  if ((*(int *)(param_1 + 0x10) != 0x2f) && (*(int *)(param_1 + 0x10) != 0x2e)) {

    fVar6 = (float10)FUN_00518b70(param_1,0);

    fVar6 = fVar6 * (float10)0.5 + (float10)*(float *)(param_1 + 0x184);

    *(float *)(param_1 + 0x184) = (float)fVar6;

    if (bVar5) {

      fVar7 = (float10)0.95;

    }

    else {

      fVar7 = (float10)0.6;

    }

    if (fVar7 < fVar6) {

      if (bVar5) {

        *(undefined4 *)(param_1 + 0x184) = 0x3f733333;

        return;

      }

      *(undefined4 *)(param_1 + 0x184) = 0x3f19999a;

    }

  }

  return;

}

/* ===== FUN_00480a60 @ 0x00480A60 ===== */
/* PS2 candidate: mecc_stop_looping_effects (conf 0.576) */



void FUN_00480a60(int param_1)



{

  int iVar1;

  int iVar2;

  

  iVar1 = *(int *)(param_1 + 0x100);

  if (*(int *)(iVar1 + 0x19c) != 0) {

    iVar2 = reaper_0052e4a0(param_1);

    if (iVar2 != 0) {

      reaper_00530bd0(param_1,0,0,0,0x1d,0);

    }

    FUN_00448920(*(undefined4 *)(iVar1 + 0x19c));

    *(undefined4 *)(iVar1 + 0x19c) = 0;

  }

  ANM_DumpCluster(param_1,1);

  if (*(int *)(iVar1 + 0x1fc) != 0) {

    iVar2 = reaper_0052e4a0(param_1);

    if (iVar2 != 0) {

      reaper_00530bd0(param_1,0,0,0,0x22,0);

    }

    FUN_00495e10(iVar1 + 0x1fc);

  }

  ANM_DumpCluster(param_1,10);

  if (*(int *)(iVar1 + 0x1e4) != 0) {

    FUN_00495e10(iVar1 + 0x1e4);

  }

  ANM_DumpCluster(param_1,2);

  if (*(int *)(iVar1 + 0x1e0) != 0) {

    FUN_00495700(0x574,param_1);

    *(undefined4 *)(iVar1 + 0x1e0) = 0;

  }

  if (*(int *)(iVar1 + 0x1dc) != 0) {

    FUN_00495700(0x5a5,param_1);

    *(undefined4 *)(iVar1 + 0x1dc) = 0;

  }

  if (*(int *)(iVar1 + 0x1ec) != 0) {

    FUN_00495e10(iVar1 + 0x1ec);

  }

  if (*(int *)(iVar1 + 0x1e8) != 0) {

    FUN_00495e10(iVar1 + 0x1e8);

  }

  ANM_DumpCluster(param_1,0x1d);

  return;

}

/* ===== FUN_00480d10 @ 0x00480D10 ===== */
void FUN_00480d10(int param_1,int param_2,undefined4 param_3,int param_4)



{

  int iVar1;

  int iVar2;

  int iVar3;

  undefined1 local_c [12];

  

  iVar1 = *(int *)(param_1 + 0x100);

  iVar2 = FUN_0052e480(param_1);

  if ((((iVar2 != 0) && (iVar3 = *(int *)(iVar1 + 0x5bc + param_4 * 4), iVar3 != 0)) &&

      (iVar3 != *(int *)(param_2 + 0x188))) && (iVar3 = FUN_0052e5b0(iVar3), iVar3 != 0)) {

    return;

  }

  FUN_00452490(param_3,0);

  FUN_00418630(param_3,param_4 * 2 + 0xb,local_c);

  FUN_004993c0(param_2,local_c);

  *(undefined1 *)(param_2 + 0x208) = 0;

  *(undefined1 *)(param_2 + 0x20b) = 0;

  *(undefined1 *)(param_2 + 0x20a) = 0;

  *(uint *)(param_2 + 0x20c) = *(uint *)(param_2 + 0x20c) & 0xfffffbff;

  if (iVar2 != 0) {

    *(undefined4 *)(iVar1 + 0x5bc + param_4 * 4) = *(undefined4 *)(param_2 + 0x188);

  }

  return;

}

/* ===== FUN_00480dd0 @ 0x00480DD0 ===== */
void FUN_00480dd0(int param_1,int param_2)



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

    *(uint *)(param_1 + 0x20c) = *(uint *)(param_1 + 0x20c) & 0xfffffbff;

    if (iVar4 != 0) {

      puVar3 = DAT_00632d98;

      if ((*(uint *)(param_1 + 0xdc) & 0x800000) != 0) {

        for (; puVar3 != (undefined4 *)0x0; puVar3 = (undefined4 *)*puVar3) {

          iVar4 = puVar3[3];

          if ((((*(uint *)(iVar4 + 0xd8) & 0x8000) == 0) && (*(int *)(iVar4 + 4) == 0xb)) &&

             ((*(int *)(iVar4 + 0x210) == param_1 || (*(int *)(iVar4 + 0x274) == param_1)))) {

            *(undefined4 *)(*(int *)(iVar4 + 0x100) + 0x54) = 0;

            FUN_004f40a0(iVar4,param_1,*(undefined4 *)(iVar2 + 0xd8),param_2);

            break;

          }

        }

      }

      *(undefined4 *)(iVar1 + 0x10) = *(undefined4 *)(param_1 + 0x188);

    }

  }

  return;

}

/* ===== FUN_00480ef0 @ 0x00480EF0 ===== */
void FUN_00480ef0(int param_1,int param_2)



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

  *(uint *)(param_1 + 0x20c) = *(uint *)(param_1 + 0x20c) & 0xfffffbff;

  if (bVar2) {

    *(undefined4 *)(iVar1 + 0x10) = *(undefined4 *)(param_1 + 0x188);

  }

  return;

}

/* ===== FUN_00480f90 @ 0x00480F90 ===== */
/* PS2 candidate: object_setup_specialtype (conf 0.411) */



int FUN_00480f90(undefined4 param_1,int param_2)



{

  int iVar1;

  undefined4 uVar2;

  int iVar3;

  undefined4 local_18;

  undefined4 local_14;

  undefined4 local_10;

  undefined4 local_c;

  undefined4 local_8;

  undefined4 local_4;

  

  local_c = 0;

  local_8 = 0;

  local_4 = 0;

  local_18 = 0;

  if (param_2 != 0) {

    FUN_004186c0(param_2,2,&local_c,&local_18);

  }

  iVar1 = object_allocate_type(0x3df,3);

  *(uint *)(iVar1 + 0x1d0) = *(uint *)(iVar1 + 0x1d0) | 0xf0f;

  FUN_004993c0(iVar1,&local_c);

  *(undefined4 *)(iVar1 + 200) = local_18;

  uVar2 = __ftol();

  *(undefined4 *)(iVar1 + 0xf4) = uVar2;

  *(undefined4 *)(iVar1 + 0xe8) = 0x96;

  sound_play_obj(0x59a,iVar1);

  if (param_2 != 0) {

    *(int *)(iVar1 + 0x210) = param_2;

    *(undefined4 *)(iVar1 + 0x218) = 1;

    *(undefined4 *)(iVar1 + 0x214) = 0xffffffff;

    *(undefined4 *)(param_2 + 0xe4) = 10;

    FUN_004034a0(param_2,2,0x20,0,0,0);

    sound_play_obj(0x6f1,param_2);

  }

  iVar3 = FUN_0052c5c0();

  if (iVar3 != 0) {

    local_10 = *(undefined4 *)(iVar1 + 0x188);

    if (param_2 == 0) {

      local_14 = 0;

    }

    else {

      local_14 = *(undefined4 *)(param_2 + 0x188);

    }

    reaper_00530bd0(param_1,0,2,0,0x19,&local_14);

  }

  return iVar1;

}

/* ===== FUN_004810d0 @ 0x004810D0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* PS2 candidate: projectile_logic (conf 0.495) */



void FUN_004810d0(int param_1)



{

  char cVar1;

  uint uVar2;

  undefined4 *puVar3;

  int iVar4;

  int iVar5;

  char *pcVar6;

  char *pcVar7;

  int iVar8;

  float10 fVar9;

  undefined4 uVar10;

  float local_24;

  undefined4 local_20;

  int local_1c;

  undefined1 local_18 [12];

  undefined1 local_c [12];

  

  iVar4 = FUN_0052e480(param_1);

  if ((((iVar4 != 0) && (*(int *)(param_1 + 0x1e0) == 2)) &&

      ((*(uint *)(param_1 + 0xe0) & 0x20000) == 0)) && (*(int *)(param_1 + 0x210) == 0)) {

    iVar4 = *(int *)(param_1 + 0x100);

    fVar9 = (float10)FUN_00518b70(0,0);

    fVar9 = (float10)*(float *)(iVar4 + 0x1d8) - fVar9;

    *(float *)(iVar4 + 0x1d8) = (float)fVar9;

    if (fVar9 <= (float10)0.0) {

      *(undefined4 *)(iVar4 + 0x1d8) = 0x3f000000;

      for (puVar3 = DAT_00632d70; puVar3 != (undefined4 *)0x0; puVar3 = (undefined4 *)*puVar3) {

        iVar4 = puVar3[3];

        if ((((-1 < (char)((uint)*(undefined4 *)(iVar4 + 0xd8) >> 8)) &&

             (*(int *)(iVar4 + 4) == 0x3df)) &&

            ((*(int *)(iVar4 + 0x18c) == *(int *)(param_1 + 0x18c) &&

             (*(int *)(iVar4 + 0x210) != param_1)))) &&

           ((*(int *)(param_1 + 0x210) == 0 || (*(int *)(*(int *)(param_1 + 0x210) + 0x1e0) != 0x5f)

            ))) {

          iVar8 = param_1 + 0xa0;

          fVar9 = (float10)FUN_0050a610(iVar8,iVar4 + 0xa0);

          if (fVar9 <= (float10)49.0) {

            if (*(int *)(iVar4 + 0x210) == 0) {

              iVar8 = FUN_004a63a0(param_1);

              if (iVar8 == 0) {

                iVar8 = FUN_0052aa70();

                if ((iVar8 == 0) || (iVar8 = FUN_0052c5c0(), iVar8 != 0)) {

                  *(int *)(iVar4 + 0x210) = param_1;

                  *(undefined4 *)(iVar4 + 0x218) = 4;

                  *(undefined4 *)(iVar4 + 0x214) = 0;

                  *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 0x20000;

                  *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) & 0xfff7ffff;

                  *(uint *)(iVar4 + 0xe0) = *(uint *)(iVar4 + 0xe0) | 1;

                  FUN_004034a0(param_1,0xd3,0x21,0,0,0);

                  FUN_00480a60(param_1);

                  iVar8 = reaper_0052e4a0(iVar4);

                  if (iVar8 != 0) {

                    local_24 = *(float *)(iVar4 + 0x188);

                    reaper_00530bd0(param_1,0,1,0,0x18,&local_24);

                  }

                  FUN_004802c0(param_1);

                  iVar4 = *(int *)(param_1 + 0x100);

                  if ((*(uint *)(param_1 + 0xe0) & 0x1000000) != 0) {

                    FUN_004804d0(param_1);

                    if (*(int *)(iVar4 + 0x18c) == 0x13) {

                      FUN_00458180(param_1,*(undefined4 *)(iVar4 + 0xfc));

                      *(undefined4 *)(iVar4 + 0xfc) = 0xffffffff;

                    }

                    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xfeffffff;

                    iVar4 = reaper_0052e4a0(param_1);

                    if (iVar4 != 0) {

                      reaper_00530bd0(param_1,0,0,0,0x15,0);

                    }

                  }

                  if (((*(uint *)(param_1 + 0xe0) & 0x2000000) != 0) &&

                     ((*(uint *)(param_1 + 0xe0) & 0x4000000) == 0)) {

                    iVar4 = reaper_0052e4a0(param_1);

                    if (iVar4 != 0) {

                      reaper_00530bd0(param_1,0,0,0,0xc,0);

                    }

                    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 0x4000000;

                    *(undefined4 *)(param_1 + 0x274) = 0;

                    sound_play_player(0x572,param_1);

                  }

                  uVar10 = 0x598;

                  goto LAB_0048160d;

                }

                local_24 = *(float *)(iVar4 + 0x188);

                FUN_00530d70(param_1,0,1,0,0x23,&local_24);

              }

              else {

                pcVar6 = (char *)FUN_00507b00(s_FlagHintDriveGyro_0055bccc);

                pcVar7 = &DAT_00632c10;

                do {

                  cVar1 = *pcVar6;

                  pcVar6 = pcVar6 + 1;

                  *pcVar7 = cVar1;

                  pcVar7 = pcVar7 + 1;

                } while (cVar1 != '\0');

                _DAT_00632d10 = 0x3f800000;

              }

            }

            else {

              iVar5 = FUN_004a6160(*(int *)(iVar4 + 0x210));

              if (iVar5 != 0) {

                uVar2 = *(uint *)(iVar4 + 0xe0);

                if ((uVar2 & 6) == 0) {

                  FUN_00418630(iVar4,3,local_18);

                  FUN_00418630(iVar4,4,local_c);

                  fVar9 = (float10)FUN_0050a610(iVar8,local_18);

                  local_24 = (float)fVar9;

                  fVar9 = (float10)FUN_0050a610(iVar8,local_c);

                  if (fVar9 <= (float10)local_24) {

LAB_00481264:

                    iVar8 = 2;

                  }

                  else {

                    iVar8 = 1;

                  }

                }

                else {

                  if ((uVar2 & 2) != 0) {

                    if ((uVar2 & 4) == 0) goto LAB_00481264;

                    goto LAB_00481615;

                  }

                  iVar8 = 1;

                }

                iVar5 = FUN_0052aa70();

                if ((iVar5 == 0) || (iVar5 = FUN_0052c5c0(), iVar5 != 0)) {

                  *(int *)(param_1 + 0x210) = iVar4;

                  *(undefined4 *)(param_1 + 0x214) = 4;

                  *(uint *)(param_1 + 0x218) = (iVar8 != 1) + 3;

                  *(uint *)(param_1 + 0xdc) = *(uint *)(param_1 + 0xdc) | 0x8000;

                  *(uint *)(iVar4 + 0xe0) = *(uint *)(iVar4 + 0xe0) | (uint)(iVar8 != 1) * 2 + 2;

                  FUN_00480a60(param_1);

                  iVar5 = reaper_0052e4a0(iVar4);

                  if (iVar5 != 0) {

                    local_20 = *(undefined4 *)(iVar4 + 0x188);

                    local_1c = iVar8;

                    reaper_00530bd0(param_1,0,2,0,0x1a,&local_20);

                  }

                  FUN_004802c0(param_1);

                  iVar4 = *(int *)(param_1 + 0x100);

                  if ((*(uint *)(param_1 + 0xe0) & 0x1000000) != 0) {

                    if (*(int *)(iVar4 + 0x144) != 0) {

                      FUN_00448920(*(int *)(iVar4 + 0x144));

                      *(undefined4 *)(iVar4 + 0x144) = 0;

                      iVar8 = reaper_0052e4a0(param_1);

                      if (iVar8 != 0) {

                        reaper_00530bd0(param_1,0,0,0,0x1f,0);

                      }

                    }

                    if (*(int *)(iVar4 + 0x1ec) != 0) {

                      FUN_00495ee0(iVar4 + 0x1ec);

                    }

                    *(undefined4 *)(iVar4 + 0x140) = 0;

                    if (*(int *)(iVar4 + 0x18c) == 0x13) {

                      FUN_00458180(param_1,*(undefined4 *)(iVar4 + 0xfc));

                      *(undefined4 *)(iVar4 + 0xfc) = 0xffffffff;

                    }

                    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xfeffffff;

                    iVar4 = reaper_0052e4a0(param_1);

                    if (iVar4 != 0) {

                      reaper_00530bd0(param_1,0,0,0,0x15,0);

                    }

                  }

                  if (((*(uint *)(param_1 + 0xe0) & 0x2000000) != 0) &&

                     ((*(uint *)(param_1 + 0xe0) & 0x4000000) == 0)) {

                    iVar4 = reaper_0052e4a0(param_1);

                    if (iVar4 != 0) {

                      reaper_00530bd0(param_1,0,0,0,0xc,0);

                    }

                    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 0x4000000;

                    *(undefined4 *)(param_1 + 0x274) = 0;

                    sound_play_player(0x572,param_1);

                  }

                  uVar10 = 0x59d;

LAB_0048160d:

                  sound_play_player(uVar10,param_1);

                }

                else {

                  local_24 = *(float *)(iVar4 + 0x188);

                  FUN_00530d70(param_1,0,1,0,0x23,&local_24);

                }

              }

            }

          }

        }

LAB_00481615:

      }

    }

  }

  return;

}

/* ===== FUN_00481630 @ 0x00481630 ===== */
void FUN_00481630(int param_1)



{

  float fVar1;

  int iVar2;

  uint uVar3;

  int *piVar4;

  

  iVar2 = *(int *)(param_1 + 0x210);

  if ((iVar2 == 0) || (*(int *)(iVar2 + 0x1e0) != 0x5f)) {

    if (((*(uint *)(param_1 + 0xe0) & 0x20000) != 0) &&

       (piVar4 = DAT_00632d70, DAT_00632d70 != (int *)0x0)) {

      while (((iVar2 = piVar4[3], (*(uint *)(iVar2 + 0xd8) & 0x8000) != 0 ||

              (*(int *)(iVar2 + 4) != 0x3df)) || (*(int *)(iVar2 + 0x210) != param_1))) {

        piVar4 = (int *)*piVar4;

        if (piVar4 == (int *)0x0) {

          return;

        }

      }

      *(undefined4 *)(iVar2 + 0x210) = 0;

      *(undefined4 *)(iVar2 + 0x214) = 0xffffffff;

      *(undefined4 *)(iVar2 + 0x218) = 0xffffffff;

      *(undefined4 *)(iVar2 + 200) = *(undefined4 *)(param_1 + 200);

      *(undefined4 *)(iVar2 + 0x10c) = *(undefined4 *)(param_1 + 0x10c);

      *(undefined4 *)(iVar2 + 0x110) = *(undefined4 *)(param_1 + 0x110);

      *(undefined4 *)(iVar2 + 0x108) = 0xbf800000;

      *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xfffdffff;

      fVar1 = *(float *)(iVar2 + 0xa8);

      *(undefined4 *)(param_1 + 0x130) = 0x42480000;

      *(float *)(param_1 + 0xa8) = fVar1 + 7.5;

      *(float *)(param_1 + 0x128) = *(float *)(param_1 + 0x29c) * 50.0;

      *(float *)(param_1 + 300) = *(float *)(param_1 + 0x2ac) * 50.0;

      iVar2 = reaper_0052e4a0(param_1);

      if (iVar2 != 0) {

        reaper_00530bd0(param_1,0,0,0,0x17,0);

      }

      sound_play_player(0x59e,param_1);

    }

    return;

  }

  if (*(int *)(param_1 + 0x218) == 3) {

    uVar3 = *(uint *)(iVar2 + 0xe0) & 0xfffffffd;

  }

  else {

    if (*(int *)(param_1 + 0x218) != 4) goto LAB_0048167a;

    uVar3 = *(uint *)(iVar2 + 0xe0) & 0xfffffffb;

  }

  *(uint *)(iVar2 + 0xe0) = uVar3;

LAB_0048167a:

  fVar1 = *(float *)(*(int *)(param_1 + 0x210) + 0xa8);

  *(undefined4 *)(param_1 + 0x218) = 0xffffffff;

  *(undefined4 *)(param_1 + 0x214) = 0xffffffff;

  *(float *)(param_1 + 0xa8) = fVar1 + 7.5;

  *(undefined4 *)(param_1 + 0x130) = 0x42480000;

  *(undefined4 *)(param_1 + 0x210) = 0;

  *(uint *)(param_1 + 0xdc) = *(uint *)(param_1 + 0xdc) & 0xffff7fff;

  *(float *)(param_1 + 0x128) = *(float *)(param_1 + 0x29c) * 50.0;

  *(float *)(param_1 + 300) = *(float *)(param_1 + 0x2ac) * 50.0;

  iVar2 = reaper_0052e4a0(param_1);

  if (iVar2 != 0) {

    reaper_00530bd0(param_1,0,0,0,0x17,0);

  }

  sound_play_player(0x59d,param_1);

  return;

}

/* ===== FUN_00481830 @ 0x00481830 ===== */
void FUN_00481830(int param_1,int param_2)



{

  int iVar1;

  int iVar2;

  int iVar3;

  

  iVar3 = param_2;

  iVar1 = param_1;

  *(int *)(param_2 + 0x210) = param_1;

  *(undefined4 *)(param_2 + 0x218) = 4;

  *(undefined4 *)(param_2 + 0x214) = 0;

  *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 0x20000;

  *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) & 0xfff7ffff;

  *(uint *)(param_2 + 0xe0) = *(uint *)(param_2 + 0xe0) | 1;

  FUN_004034a0(param_1,0xd3,0x21,0,0,0);

  FUN_00480a60(iVar1);

  iVar2 = reaper_0052e4a0(iVar3);

  if (iVar2 != 0) {

    param_1 = *(int *)(iVar3 + 0x188);

    reaper_00530bd0(iVar1,0,1,0,0x18,&param_1);

  }

  FUN_004802c0(iVar1);

  iVar3 = *(int *)(iVar1 + 0x100);

  if ((*(uint *)(iVar1 + 0xe0) & 0x1000000) != 0) {

    if (*(int *)(iVar3 + 0x144) != 0) {

      FUN_00448920(*(int *)(iVar3 + 0x144));

      *(undefined4 *)(iVar3 + 0x144) = 0;

      iVar2 = reaper_0052e4a0(iVar1);

      if (iVar2 != 0) {

        reaper_00530bd0(iVar1,0,0,0,0x1f,0);

      }

    }

    if (*(int *)(iVar3 + 0x1ec) != 0) {

      FUN_00495ee0(iVar3 + 0x1ec);

    }

    *(undefined4 *)(iVar3 + 0x140) = 0;

    if (*(int *)(iVar3 + 0x18c) == 0x13) {

      FUN_00458180(iVar1,*(undefined4 *)(iVar3 + 0xfc));

      *(undefined4 *)(iVar3 + 0xfc) = 0xffffffff;

    }

    *(uint *)(iVar1 + 0xe0) = *(uint *)(iVar1 + 0xe0) & 0xfeffffff;

    iVar3 = reaper_0052e4a0(iVar1);

    if (iVar3 != 0) {

      reaper_00530bd0(iVar1,0,0,0,0x15,0);

    }

  }

  if (((*(uint *)(iVar1 + 0xe0) & 0x2000000) != 0) && ((*(uint *)(iVar1 + 0xe0) & 0x4000000) == 0))

  {

    iVar3 = reaper_0052e4a0(iVar1);

    if (iVar3 != 0) {

      reaper_00530bd0(iVar1,0,0,0,0xc,0);

    }

    *(uint *)(iVar1 + 0xe0) = *(uint *)(iVar1 + 0xe0) | 0x4000000;

    *(undefined4 *)(iVar1 + 0x274) = 0;

    sound_play_player(0x572,iVar1);

  }

  sound_play_player(0x598,iVar1);

  return;

}

/* ===== FUN_004819f0 @ 0x004819F0 ===== */
void FUN_004819f0(int param_1,int param_2,int param_3)



{

  int iVar1;

  int iVar2;

  undefined4 local_8;

  int local_4;

  

  *(int *)(param_1 + 0x210) = param_2;

  *(uint *)(param_1 + 0x218) = (param_3 != 1) + 3;

  *(uint *)(param_1 + 0xdc) = *(uint *)(param_1 + 0xdc) | 0x8000;

  *(undefined4 *)(param_1 + 0x214) = 4;

  *(uint *)(param_2 + 0xe0) = *(uint *)(param_2 + 0xe0) | (uint)(param_3 != 1) * 2 + 2;

  FUN_00480a60(param_1);

  iVar1 = reaper_0052e4a0(param_2);

  if (iVar1 != 0) {

    local_8 = *(undefined4 *)(param_2 + 0x188);

    local_4 = param_3;

    reaper_00530bd0(param_1,0,2,0,0x1a,&local_8);

  }

  FUN_004802c0(param_1);

  iVar1 = *(int *)(param_1 + 0x100);

  if ((*(uint *)(param_1 + 0xe0) & 0x1000000) != 0) {

    if (*(int *)(iVar1 + 0x144) != 0) {

      FUN_00448920(*(int *)(iVar1 + 0x144));

      *(undefined4 *)(iVar1 + 0x144) = 0;

      iVar2 = reaper_0052e4a0(param_1);

      if (iVar2 != 0) {

        reaper_00530bd0(param_1,0,0,0,0x1f,0);

      }

    }

    if (*(int *)(iVar1 + 0x1ec) != 0) {

      FUN_00495ee0(iVar1 + 0x1ec);

    }

    *(undefined4 *)(iVar1 + 0x140) = 0;

    if (*(int *)(iVar1 + 0x18c) == 0x13) {

      FUN_00458180(param_1,*(undefined4 *)(iVar1 + 0xfc));

      *(undefined4 *)(iVar1 + 0xfc) = 0xffffffff;

    }

    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) & 0xfeffffff;

    iVar1 = reaper_0052e4a0(param_1);

    if (iVar1 != 0) {

      reaper_00530bd0(param_1,0,0,0,0x15,0);

    }

  }

  if (((*(uint *)(param_1 + 0xe0) & 0x2000000) != 0) &&

     ((*(uint *)(param_1 + 0xe0) & 0x4000000) == 0)) {

    iVar1 = reaper_0052e4a0(param_1);

    if (iVar1 != 0) {

      reaper_00530bd0(param_1,0,0,0,0xc,0);

    }

    *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 0x4000000;

    *(undefined4 *)(param_1 + 0x274) = 0;

    sound_play_player(0x572,param_1);

  }

  sound_play_player(0x59d,param_1);

  return;

}

/* ===== FUN_00482310 @ 0x00482310 ===== */
int FUN_00482310(int param_1)



{

  int iVar1;

  undefined4 *puVar2;

  

  puVar2 = DAT_00632d70;

  while( true ) {

    if (puVar2 == (undefined4 *)0x0) {

      return 0;

    }

    iVar1 = puVar2[3];

    if (((-1 < (char)((uint)*(undefined4 *)(iVar1 + 0xd8) >> 8)) && (*(int *)(iVar1 + 4) == 0x3df))

       && (*(int *)(iVar1 + 0x210) == param_1)) break;

    puVar2 = (undefined4 *)*puVar2;

  }

  return iVar1;

}

/* ===== FUN_00482350 @ 0x00482350 ===== */
void FUN_00482350(void)



{

  if (((DAT_00633104 == 0) && (DAT_00632c0c != 0)) && (DAT_0059e8e0 != '\0')) {

    FUN_0051b970(0xffffff,0,0x3d088889,0x3c23d70a,0x3f75c28f,&DAT_0059e8e0);

  }

  return;

}

/* ===== FUN_00482390 @ 0x00482390 ===== */
void FUN_00482390(int param_1)



{

  bool bVar1;

  undefined4 uVar2;

  

  if (((param_1 == 0) || (param_1 == 2)) && (DAT_005dd2d4 != (code *)0x0)) {

    (*DAT_005dd2d4)(1,1);

    (*DAT_005dd2d4)(2,1);

    (*DAT_005dd32c)(0x3f400000);

    (*DAT_005dd2cc)(0x3f400000);

  }

  if ((param_1 == 1) || (param_1 == 2)) {

    DAT_006331d4 = 0;

    DAT_006331c8 = 0;

    DAT_006331cc = 0;

    DAT_006331d0 = 0;

    if (DAT_00656420 != 0) {

      DAT_00632e94 = (**(code **)(DAT_00656420 + 0xc4))(DAT_00656420,7);

      FUN_00452070((~DAT_00632e94 & 2) == 0);

      FUN_004520b0((~DAT_00632e94 & 4) == 0);

      if (((~DAT_00632e94 & 2) == 0) && (-1 < (char)(~DAT_00632e94 >> 8))) {

        uVar2 = 1;

      }

      else {

        uVar2 = 0;

      }

      FUN_00452090(uVar2);

      FUN_004520d0((~DAT_00632e94 & 0x40) == 0);

      FUN_00452050(1);

      FUN_00452110(1);

      FUN_004520f0(1);

      FUN_0051c8a0(1);

      bVar1 = (~DAT_00632e94 & 0x4000) == 0;

      if (bVar1) {

        FUN_004520d0(1);

      }

      else {

        FUN_004520d0(0);

      }

      DAT_006331c0 = (uint)!bVar1;

    }

  }

  DAT_0063322c = 0;

  FUN_004257c0();

  return;

}

/* ===== game_options_load @ 0x004824E0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void game_options_load(void)



{

  uint uVar1;

  int iVar2;

  undefined4 uVar3;

  float10 fVar4;

  undefined1 auStack_20 [16];

  undefined1 auStack_10 [16];

  

  uVar1 = comm_00426540();

  if (uVar1 == 0) {

    _DAT_0059eeb4 = uVar1;

    iVar2 = FUN_0051c870();

    if (iVar2 == 2) {

      _DAT_0059eeb4 = _DAT_0059eeb4 | 1;

    }

    else {

      iVar2 = FUN_0051c870();

      if (iVar2 == 1) {

        _DAT_0059eeb4 = _DAT_0059eeb4 | 0x2000;

      }

    }

    iVar2 = dialog_level_is_base_5();

    if (iVar2 != 0) {

      _DAT_0059eeb4 = _DAT_0059eeb4 | 2;

    }

    iVar2 = dialog_level_is_base_2();

    if (iVar2 != 0) {

      _DAT_0059eeb4 = _DAT_0059eeb4 | 4;

    }

    iVar2 = dialog_level_is_base_3();

    if (iVar2 != 0) {

      _DAT_0059eeb4 = _DAT_0059eeb4 | 8;

    }

    iVar2 = dialog_level_is_base_4();

    if (iVar2 != 0) {

      _DAT_0059eeb4 = _DAT_0059eeb4 | 0x10;

    }

    iVar2 = dialog_level_is_base_6();

    if (iVar2 != 0) {

      _DAT_0059eeb4 = _DAT_0059eeb4 | 0x20;

    }

    iVar2 = dialog_level_is_base_7();

    if (iVar2 != 0) {

      _DAT_0059eeb4 = _DAT_0059eeb4 | 0x80;

    }

    iVar2 = FUN_0051c6c0();

    if (iVar2 == 2) {

      _DAT_0059eeb4 = _DAT_0059eeb4 | 0x40;

    }

    else {

      iVar2 = FUN_0051c6c0();

      if (iVar2 == 1) {

        _DAT_0059eeb4 = _DAT_0059eeb4 | 0x4000;

      }

    }

    if (DAT_00633150 == 1) {

      _DAT_0059eeb4 = _DAT_0059eeb4 | 0x400;

    }

    else if (DAT_00633150 == 0) {

      _DAT_0059eeb4 = _DAT_0059eeb4 | 0x800;

    }

    iVar2 = (*DAT_005dd2e0)(2);

    if (iVar2 != 0) {

      _DAT_0059eeb4 = _DAT_0059eeb4 | 0x200;

    }

    iVar2 = (*DAT_005dd2e0)(1);

    if (iVar2 != 0) {

      _DAT_0059eeb4 = _DAT_0059eeb4 | 0x100;

    }

    if (DAT_0063322c != 0) {

      _DAT_0059eeb4 = _DAT_0059eeb4 | 0x1000;

    }

    comm_0051a130(s_GameOptions_0055be30,_DAT_0059eeb4);

    fVar4 = (float10)(*DAT_005dd338)();

    comm_0051a130(s_MusicVolume_0055be24,(float)fVar4);

    fVar4 = (float10)(*DAT_005dd2d8)();

    comm_0051a130(s_SoundVolume_0055be18,(float)fVar4);

    uVar3 = (**(code **)(DAT_00656420 + 0xc4))(DAT_00656420,1);

    comm_0051a130(s_VideoWidth_0055be0c,uVar3);

    uVar3 = (**(code **)(DAT_00656420 + 0xc4))(DAT_00656420,2);

    comm_0051a130(s_VideoHeight_0055be00,uVar3);

    uVar3 = (**(code **)(DAT_00656420 + 0xc4))(DAT_00656420,5);

    comm_0051a130(s_VideoDepth_0055bdf4,uVar3);

    (**(code **)(DAT_00656420 + 0x6c))(DAT_00656420,auStack_10,auStack_20);

    FUN_0051a190(s_VideoDevGuid_0055bde4,auStack_20,0x10);

    FUN_0051a190(s_VideoDrvGuid_0055bdd4,auStack_10,0x10);

    comm_0051a130(s_GameOptionsVersion_0055bdc0,1);

  }

  return;

}

/* ===== game_options_verify @ 0x00482700 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void game_options_verify(void)



{

  int iVar1;

  float10 fVar2;

  undefined4 uVar3;

  float fStack_c;

  float fStack_8;

  int local_4;

  

  mission_0051a0c0(s_GameOptionsVersion_0055bdc0,&local_4);

  if (local_4 != 1) {

    FUN_00482390(2);

    return;

  }

  _DAT_0059eeb4 = 0;

  iVar1 = comm_00426540();

  if (iVar1 == 0) {

    mission_0051a0c0(s_GameOptions_0055be30,&DAT_0059eeb4);

    if (DAT_00656420 != 0) {

      if ((_DAT_0059eeb4 & 1) == 0) {

        if ((_DAT_0059eeb4 & 0x2000) == 0) {

          uVar3 = 0;

        }

        else {

          uVar3 = 1;

        }

      }

      else {

        uVar3 = 2;

      }

      FUN_0051c810(uVar3);

      FUN_0051c770((_DAT_0059eeb4 & 2) != 0);

      FUN_0051c590((_DAT_0059eeb4 & 4) != 0);

      FUN_0051c610((_DAT_0059eeb4 & 8) != 0);

      FUN_0051c700((_DAT_0059eeb4 & 0x10) != 0);

      FUN_0051c7b0((_DAT_0059eeb4 & 0x20) != 0);

      FUN_0051c8a0(DAT_0059eeb4 < '\0');

      if ((_DAT_0059eeb4 & 0x40) == 0) {

        if ((_DAT_0059eeb4 & 0x4000) == 0) {

          uVar3 = 0;

        }

        else {

          uVar3 = 1;

        }

      }

      else {

        uVar3 = 2;

      }

      FUN_0051c660(uVar3);

      if ((_DAT_0059eeb4 & 0x800) == 0) {

        DAT_00633150 = 2 - (uint)((_DAT_0059eeb4 & 0x400) != 0);

      }

      else {

        DAT_00633150 = 0;

      }

      (*DAT_005dd2d4)(1,_DAT_0059eeb4 & 0x100);

      (*DAT_005dd2d4)(2,_DAT_0059eeb4 & 0x200);

      fStack_8 = 0.75;

      fStack_c = 0.75;

      keymap_0051a100(s_MusicVolume_0055be24,&fStack_c);

      (*DAT_005dd32c)(fStack_c);

      fStack_8 = 0.75;

      fStack_c = 0.75;

      keymap_0051a100(s_SoundVolume_0055be18,&fStack_c);

      (*DAT_005dd2cc)(fStack_c);

    }

    mission_0051a0c0(s_VideoWidth_0055be0c,&DAT_006331c8);

    mission_0051a0c0(s_VideoHeight_0055be00,&DAT_006331cc);

    mission_0051a0c0(s_VideoDepth_0055bdf4,&DAT_006331d0);

    FUN_0051a160(s_VideoDevGuid_0055bde4,&DAT_006331e8,0x10);

    FUN_0051a160(s_VideoDrvGuid_0055bdd4,&DAT_006331d8,0x10);

    DAT_0063322c = _DAT_0059eeb4 & 0x1000;

    if (DAT_0058c5d0 == 0) {

      fVar2 = (float10)FUN_00425840();

      fStack_c = (float)fVar2;

      fStack_8 = fStack_c;

      keymap_0051a100(s_MSpeed_0055be3c,&fStack_c);

      FUN_004257c0(fStack_c);

    }

  }

  else if (DAT_00656420 != 0) {

    FUN_0051c810(0);

    FUN_0051c770(0);

    FUN_0051c590(0);

    FUN_0051c610(0);

    FUN_0051c700(0);

    FUN_0051c7b0(0);

    FUN_0051c8a0(0);

    FUN_0051c660(0);

    DAT_00633150 = 0;

    return;

  }

  return;

}

/* ===== FUN_004829d0 @ 0x004829D0 ===== */
/* PS2 candidate: reaper_camera_logic__FP6OBJECT (conf 0.313) */



void FUN_004829d0(void)



{

  if (DAT_00633248 == 0) {

    if (DAT_0059eeb0 == 0) {

      camera_override_refpt(DAT_0059ee98,0);

      ref_anode_user();

      FUN_00516890();

      main_drawobj_0042d490();

      if (DAT_0059eed4 == 0) {

        if (DAT_0059eed8 == 0) {

          alpha_queue_push_3(0,2);

        }

        else {

          FUN_00428810(DAT_0059eed8);

        }

      }

      else {

        FUN_00428810(DAT_0059eed4);

      }

      DAT_0063291c = DAT_0055bdb8;

      FUN_004fa720(&DAT_00632900,DAT_0055bdb8,0xffffffff);

      FUN_00500890(&DAT_00632900);

      render_view_xform();

      FUN_0040d790();

      FUN_004a14b0();

      if (((DAT_00633104 == 0) && (DAT_00632c0c != 0)) && (DAT_0059e8e0 != '\0')) {

        FUN_0051b970(0xffffff,0,0x3d088889,0x3c23d70a,0x3f75c28f,&DAT_0059e8e0);

      }

      ANM_DumpCluster();

      fps_display();

      return;

    }

    if (DAT_0059eeac == 0) {

      ref_anode_user();

      if (DAT_0059eed4 == 0) {

        if (DAT_0059eed8 == 0) {

          alpha_queue_push_3(0,2);

        }

        else {

          FUN_00428810(DAT_0059eed8);

        }

      }

      else {

        FUN_00428810(DAT_0059eed4);

      }

      FUN_004fa720(&DAT_00632900,DAT_0063291c,0xffffffff);

      FUN_00500890(&DAT_00632900);

      if (((DAT_00633104 == 0) && (DAT_00632c0c != 0)) && (DAT_0059e8e0 != '\0')) {

        FUN_0051b970(0xffffff,0,0x3d088889,0x3c23d70a,0x3f75c28f,&DAT_0059e8e0);

        return;

      }

    }

    else {

      DAT_0059eeac = 0;

    }

  }

  return;

}

/* ===== menu_mission_launch @ 0x00482B60 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void menu_mission_launch(void)



{

  int iVar1;

  uint uVar2;

  int iVar3;

  undefined4 *puVar4;

  undefined4 uVar5;

  code *pcVar6;

  int local_4;

  

  iVar1 = FUN_004469e0();

  if (iVar1 == 0) {

    if ((DAT_006330e4 == 0) ||

       (iVar1 = match(s_intro_island_0055be84,*(undefined4 *)(DAT_006330e4 + 4)), iVar1 == 0)) {

      DAT_0059eeb0 = 0;

    }

    else {

      iVar1 = flk_file_open2(s_intro_island_1_0055be74);

      DAT_0059eeb0 = (uint)(iVar1 == 0);

      DAT_0059eeac = (uint)(iVar1 == 0);

    }

    if ((DAT_006330e4 != 0) && (DAT_0059eedc < 1)) {

      DAT_0059eedc = teammecc_clear_mode(s_intro_island_0055be84,

                                         *(undefined4 *)(DAT_006330e4 + 0x50e0),1);

    }

  }

  if (DAT_00633104 == 0) {

    pcVar6 = menu_handlers_exec;

  }

  else {

    pcVar6 = menu_handlers_lookup;

  }

  dlog_push_level(pcVar6,FUN_004829d0);

  FUN_00426FA0();

  iVar1 = main_status_00500520(&DAT_00632900);

  if (iVar1 != 0) {

    DAT_0055bdb8 = 0x2a;

    if (DAT_00633104 == 0) {

      DAT_0055bdb8 = 0x12;

    }

    DAT_00632924 = DAT_00632e84;

    DAT_00632920 = 0xffffffff;

    DAT_00632928 = DAT_00632e88;

    DAT_0063291c = DAT_0055bdb8;

    if (DAT_0059ee98 != 0) {

      FUN_00497510(DAT_0059ee98);

    }

    DAT_0059ee98 = 0;

    DAT_0059ee98 = object_allocate_type(0x3fb,0x80000000);

    *(uint *)(DAT_0059ee98 + 0xd8) = *(uint *)(DAT_0059ee98 + 0xd8) | 0x40000000;

    camera_override_refpt(DAT_0059ee98,0);

    keymap_load();

    savegame_load();

    local_4 = 0;

    mission_0051a0c0(s_MissionCheat_0055be64,&local_4);

    mission_0051a0c0(s_DevNoMissionLoad_0055be50,&DAT_006331f8);

    uVar2 = -(uint)(DAT_00633104 != 0) & 0xfffffffd;

    iVar1 = uVar2 + 7;

    _DAT_0059eea4 = uVar2 + 6;

    DAT_00632c0c = 1;

    DAT_0059e8e0 = 0;

    DAT_0059ee9c = 0;

    _DAT_0059eea0 = 0;

    _DAT_0059eea8 = 0;

    DAT_0059eec4 = 0;

    _DAT_0059eec8 = (undefined1 *)0x0;

    _DAT_0059eecc = &LAB_004829c0;

    _DAT_0059eed0 = 0;

    puVar4 = &DAT_0059dcd0;

    _DAT_0059ebe8 = iVar1;

    for (iVar3 = 300; iVar3 != 0; iVar3 = iVar3 + -1) {

      *puVar4 = 0;

      puVar4 = puVar4 + 1;

    }

    iVar3 = dialog_level_is_base_8();

    if (iVar3 != 0) {

      main_fx_004470b0(&DAT_0055a0f8);

    }

    DAT_0059eec0 = (uint)(iVar3 != 0);

    DAT_0055bdb4 = 0;

    _DAT_0059eec8 = &LAB_00483990;

    if ((DAT_00633380 != 0) || (DAT_0059ee9c = 0, local_4 != 0)) {

      DAT_0059ee9c = 4;

    }

    if (DAT_00633104 != 0) {

      DAT_0059ee9c = 1;

    }

    DAT_0055bdb0 = iVar1;

    keymap_0051a100(s_MpSelect_0055be44,&DAT_0059ee9c);

    iVar1 = DAT_0059ee9c;

    (&DAT_0059dcd0)[DAT_0059ee9c * 3] = 1;

    if (DAT_00633104 == 0) {

      uVar5 = *(undefined4 *)(*(int *)(DAT_00632918 + 0x288) + iVar1 * 4);

    }

    else {

      if (3 < iVar1) {

        iVar1 = 0;

        DAT_0059ee9c = 0;

      }

      uVar5 = *(undefined4 *)(*(int *)(DAT_00632918 + 0x5e8) + iVar1 * 4);

    }

    mission_004fe2d0(&DAT_00632900,uVar5,0x3f000000,0x3f000000,&DAT_00632abc,&DAT_00632ac0);

    DAT_00632abc = (float)DAT_00632924 * DAT_00632abc;

    DAT_00632ac0 = (float)DAT_00632928 * DAT_00632ac0;

    _DAT_00632ac4 = DAT_00632abc;

    _DAT_00632ac8 = DAT_00632ac0;

    return;

  }

  if (DAT_00633104 == 0) {

    dialog_level_pop(menu_handlers_exec);

    return;

  }

  dialog_level_pop(menu_handlers_lookup);

  return;

}

/* ===== menu_handlers_lookup @ 0x00482E90 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void menu_handlers_lookup(void)



{

  int iVar1;

  int *piVar2;

  int iVar3;

  undefined4 *puVar4;

  char *pcVar5;

  undefined4 uVar6;

  

  FUN_004a5cd0();

  main_menu_004832f0();

  if (DAT_00632aa4._3_1_ != '\0') {

    dialog_level_pop(menu_handlers_lookup);

    FUN_0040d790();

    FUN_00497510(DAT_0059ee98);

    DAT_0059ee98 = 0;

    DAT_00632c0c = 0;

    iVar3 = 0;

    piVar2 = &DAT_0059dcd4;

    do {

      if (*piVar2 != 0) {

        main_menu_00483200(iVar3,0);

      }

      piVar2 = piVar2 + 3;

      iVar3 = iVar3 + 1;

      iVar1 = DAT_0059eec4;

    } while ((int)piVar2 < 0x59e184);

    for (; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x50)) {

      if (*(int *)(iVar1 + 0x48) != 0) {

        main_menu_00483200(0xffffffff,iVar1);

      }

    }

    mission_00447fd0(0,2);

    if (DAT_0059eec0 != 0) {

      main_fx_004471a0();

    }

    puVar4 = &DAT_00632aa0;

    for (iVar3 = 0x1f; iVar3 != 0; iVar3 = iVar3 + -1) {

      *puVar4 = 0;

      puVar4 = puVar4 + 1;

    }

    _DAT_00632ac4 = DAT_00632abc;

    DAT_0059eeb8 = 1;

    _DAT_00632ac8 = DAT_00632ac0;

    FUN_0048EA50();

    if (DAT_0063315c != 0) {

      return;

    }

    if (DAT_00633160 != 0) {

      return;

    }

    if (DAT_0063317c != 0) {

      return;

    }

    sound_play(0x657);

    return;

  }

  if (DAT_00632aa0._1_1_ == '\0') {

    if (DAT_00632aa0._2_1_ != '\0') {

      iVar3 = DAT_0059ee9c + 1;

      goto LAB_00482fd8;

    }

  }

  else {

    iVar3 = DAT_0059ee9c + -1;

LAB_00482fd8:

    FUN_004834d0(iVar3,0,1,0);

  }

  FUN_00500120(&DAT_0063292c,DAT_00632924,DAT_00632928);

  iVar3 = FUN_004fff10(&DAT_00632900,DAT_0063291c,0xffffffff);

  if (-1 < iVar3) {

    FUN_004834d0(iVar3,1,1,0);

  }

  if ((DAT_00632aa8 == '\0') && ((DAT_00632aaa == '\0' || (iVar3 < 0)))) {

    switch(DAT_0059ee9c) {

    case 0:

      pcVar5 = s_MH_StartSingle_0055bec4;

      break;

    case 1:

      pcVar5 = s_MH_HostMulti_0055beb4;

      break;

    case 2:

      pcVar5 = s_MH_GameOptions_0055bea4;

      break;

    case 3:

      pcVar5 = s_MH_LoadSingle_0055be94;

      break;

    default:

      goto switchD_00483043_default;

    }

    uVar6 = FUN_00507b00(pcVar5);

    FUN_00542f27(&DAT_0059e8e0,&DAT_00555df0,uVar6);

    return;

  }

  if ((DAT_00633238 == 0) && (DAT_00633248 == 0)) {

    comm_0051a130(s_MpSelect_0055be44,DAT_0059ee9c);

  }

  dialog_level_pop(menu_handlers_lookup);

  FUN_0040d790();

  FUN_00497510(DAT_0059ee98);

  DAT_0059ee98 = 0;

  DAT_00632c0c = 0;

  iVar3 = 0;

  piVar2 = &DAT_0059dcd4;

  do {

    if (*piVar2 != 0) {

      main_menu_00483200(iVar3,0);

    }

    piVar2 = piVar2 + 3;

    iVar3 = iVar3 + 1;

    iVar1 = DAT_0059eec4;

  } while ((int)piVar2 < 0x59e184);

  for (; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x50)) {

    if (*(int *)(iVar1 + 0x48) != 0) {

      main_menu_00483200(0xffffffff,iVar1);

    }

  }

  mission_00447fd0(0,2);

  if (DAT_0059eec0 != 0) {

    main_fx_004471a0();

  }

  puVar4 = &DAT_00632aa0;

  for (iVar3 = 0x1f; iVar3 != 0; iVar3 = iVar3 + -1) {

    *puVar4 = 0;

    puVar4 = puVar4 + 1;

  }

  _DAT_00632ac4 = DAT_00632abc;

  _DAT_00632ac8 = DAT_00632ac0;

  if ((DAT_0059ee9c != 3) && (DAT_0059ee9c != 2)) {

    DAT_0059eeb0 = 0;

    FUN_00446620();

    (*DAT_005dd354)(DAT_0059eedc);

    DAT_0059eedc = 0;

  }

  if (DAT_0059ee9c == 0) {

    uVar6 = 0xb;

LAB_004831b4:

    mission_load_full(uVar6);

  }

  else {

    if (DAT_0059ee9c == 1) {

      uVar6 = 0xd;

      goto LAB_004831b4;

    }

    if (DAT_0059ee9c == 2) {

      uVar6 = 0xe;

      goto LAB_004831b4;

    }

    if (DAT_0059ee9c == 3) {

      uVar6 = 0xf;

      goto LAB_004831b4;

    }

  }

  if (((DAT_0063315c == 0) && (DAT_00633160 == 0)) && (DAT_0063317c == 0)) {

    sound_play(0x659);

  }

switchD_00483043_default:

  return;

}

/* ===== FUN_004834d0 @ 0x004834D0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_004834d0(int param_1,int param_2,int param_3,int param_4)



{

  int iVar1;

  int iVar2;

  

  iVar2 = DAT_0059ee9c;

  if (param_1 < DAT_0055bdb4) {

    param_1 = DAT_0059ee9c;

    if (param_2 == 0) {

      param_1 = DAT_0055bdb0 + -1;

    }

  }

  else if ((DAT_0055bdb0 + -1 < param_1) && (param_1 = DAT_0059ee9c, param_2 == 0)) {

    param_1 = DAT_0055bdb4;

  }

  iVar1 = DAT_0059ee9c * 3;

  DAT_0059ee9c = param_1;

  (&DAT_0059dcd0)[iVar1] = 0;

  (&DAT_0059dcd0)[param_1 * 3] = 1;

  if ((((DAT_0063315c == 0) && (DAT_00633160 == 0)) && (DAT_0063317c == 0)) &&

     ((param_1 != iVar2 && (param_3 != 0)))) {

    sound_play(0x65a);

    param_1 = DAT_0059ee9c;

  }

  if (param_2 == 0) {

    mission_004fe2d0(&DAT_00632900,

                     *(undefined4 *)

                      (*(int *)(DAT_00632918 + DAT_0063291c * 0x24) + (param_1 + param_4) * 4),

                     0x3f000000,0x3f000000,&DAT_00632abc,&DAT_00632ac0);

    DAT_00632abc = (float)DAT_00632924 * DAT_00632abc;

    DAT_00632ac0 = (float)DAT_00632928 * DAT_00632ac0;

    _DAT_00632ac4 = DAT_00632abc;

    _DAT_00632ac8 = DAT_00632ac0;

  }

  return;

}

/* ===== menu_handlers_exec @ 0x004835F0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void menu_handlers_exec(void)



{

  int iVar1;

  undefined4 uVar2;

  int *piVar3;

  int iVar4;

  undefined4 *puVar5;

  char *pcVar6;

  

  FUN_004a5cd0();

  main_menu_004832f0();

  if (DAT_00632aa4._3_1_ != '\0') {

    dialog_level_pop(menu_handlers_exec);

    FUN_0040d790();

    FUN_00497510(DAT_0059ee98);

    DAT_0059ee98 = 0;

    DAT_00632c0c = 0;

    iVar4 = 0;

    piVar3 = &DAT_0059dcd4;

    do {

      if (*piVar3 != 0) {

        main_menu_00483200(iVar4,0);

      }

      piVar3 = piVar3 + 3;

      iVar4 = iVar4 + 1;

      iVar1 = DAT_0059eec4;

    } while ((int)piVar3 < 0x59e184);

    for (; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x50)) {

      if (*(int *)(iVar1 + 0x48) != 0) {

        main_menu_00483200(0xffffffff,iVar1);

      }

    }

    mission_00447fd0(0,2);

    if (DAT_0059eec0 != 0) {

      main_fx_004471a0();

    }

    puVar5 = &DAT_00632aa0;

    for (iVar4 = 0x1f; iVar4 != 0; iVar4 = iVar4 + -1) {

      *puVar5 = 0;

      puVar5 = puVar5 + 1;

    }

    _DAT_00632ac4 = DAT_00632abc;

    DAT_0059eeb8 = 1;

    _DAT_00632ac8 = DAT_00632ac0;

    FUN_0048EA50();

    if (DAT_0063315c != 0) {

      return;

    }

    if (DAT_00633160 != 0) {

      return;

    }

    if (DAT_0063317c != 0) {

      return;

    }

    sound_play(0x657);

    return;

  }

  if (DAT_00632aa0._1_1_ == '\0') {

    if (DAT_00632aa0._2_1_ != '\0') {

      iVar4 = DAT_0059ee9c + 1;

      goto LAB_00483738;

    }

  }

  else {

    iVar4 = DAT_0059ee9c + -1;

LAB_00483738:

    FUN_004834d0(iVar4,0,1,0);

  }

  FUN_00500120(&DAT_0063292c,DAT_00632924,DAT_00632928);

  iVar4 = FUN_004fff10(&DAT_00632900,DAT_0063291c,0xffffffff);

  if (-1 < iVar4) {

    FUN_004834d0(iVar4,1,1,0);

  }

  if ((DAT_00632aa8 == '\0') && ((DAT_00632aaa == '\0' || (iVar4 < 0)))) {

    switch(DAT_0059ee9c) {

    case 0:

      pcVar6 = s_MH_StartSingle_0055bec4;

      break;

    case 1:

      pcVar6 = s_MH_JoinMulti_0055bf1c;

      break;

    case 2:

      pcVar6 = s_MH_HostMulti_0055beb4;

      break;

    case 3:

      pcVar6 = s_MH_GameOptions_0055bea4;

      break;

    case 4:

      pcVar6 = s_MH_LoadSingle_0055be94;

      break;

    case 5:

      pcVar6 = s_MH_ChangeID_0055bf10;

      break;

    case 6:

      pcVar6 = s_MH_ExitGame_0055bf04;

      break;

    default:

      goto switchD_004837a3_default;

    }

    uVar2 = FUN_00507b00(pcVar6);

    FUN_00542f27(&DAT_0059e8e0,&DAT_00555df0,uVar2);

    return;

  }

  if (((DAT_00633238 == 0) && (DAT_00633248 == 0)) && (DAT_0059ee9c != 6)) {

    comm_0051a130(s_MpSelect_0055be44,DAT_0059ee9c);

  }

  dialog_level_pop(menu_handlers_exec);

  FUN_0040d790();

  FUN_00497510(DAT_0059ee98);

  DAT_0059ee98 = 0;

  DAT_00632c0c = 0;

  iVar4 = 0;

  piVar3 = &DAT_0059dcd4;

  do {

    if (*piVar3 != 0) {

      main_menu_00483200(iVar4,0);

    }

    piVar3 = piVar3 + 3;

    iVar4 = iVar4 + 1;

    iVar1 = DAT_0059eec4;

  } while ((int)piVar3 < 0x59e184);

  for (; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x50)) {

    if (*(int *)(iVar1 + 0x48) != 0) {

      main_menu_00483200(0xffffffff,iVar1);

    }

  }

  mission_00447fd0(0,2);

  if (DAT_0059eec0 != 0) {

    main_fx_004471a0();

  }

  puVar5 = &DAT_00632aa0;

  for (iVar4 = 0x1f; iVar4 != 0; iVar4 = iVar4 + -1) {

    *puVar5 = 0;

    puVar5 = puVar5 + 1;

  }

  _DAT_00632ac4 = DAT_00632abc;

  _DAT_00632ac8 = DAT_00632ac0;

  if ((DAT_0059ee9c < 3) && (DAT_0059ee9c != 1)) {

    DAT_0059eeb0 = 0;

    FUN_00446620();

    (*DAT_005dd354)(DAT_0059eedc);

    DAT_0059eedc = 0;

  }

  if (DAT_0059ee9c == 5) {

    options_defplayer();

  }

  else if (DAT_0059ee9c == 6) {

    DAT_0059eeb8 = 1;

    FUN_0048EA50();

  }

  else {

    mission_load_full(DAT_0059ee9c + 0xb);

  }

  if (((DAT_0063315c == 0) && (DAT_00633160 == 0)) && (DAT_0063317c == 0)) {

    sound_play(0x659);

  }

switchD_004837a3_default:

  return;

}

/* ===== mission_intro_load @ 0x00483BA0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void mission_intro_load(void)



{

  int iVar1;

  int iVar2;

  undefined4 *puVar3;

  undefined4 local_24;

  undefined1 local_20 [32];

  

  DAT_0063306c = 0;

  iVar1 = FUN_004469e0();

  if (iVar1 == 0) {

    if ((DAT_006330e4 == 0) ||

       (iVar1 = match(s_intro_island_0055be84,*(undefined4 *)(DAT_006330e4 + 4)), iVar1 == 0)) {

      DAT_0059eeb0 = 0;

    }

    else {

      iVar1 = flk_file_open2(s_intro_island_1_0055be74);

      DAT_0059eeb0 = (uint)(iVar1 == 0);

      DAT_0059eeac = (uint)(iVar1 == 0);

    }

    if ((DAT_006330e4 != 0) && (DAT_0059eedc < 1)) {

      DAT_0059eedc = teammecc_clear_mode(s_intro_island_0055be84,

                                         *(undefined4 *)(DAT_006330e4 + 0x50e0),1);

    }

  }

  dlog_push_level(&LAB_00483fd0,FUN_004829d0);

  FUN_00426FA0();

  iVar1 = main_status_00500520(&DAT_00632900);

  if (iVar1 == 0) {

    dialog_level_pop(&LAB_00483fd0);

    return;

  }

  DAT_0055bdb8 = 0x13;

  DAT_0063291c = 0x13;

  DAT_00632924 = DAT_00632e84;

  DAT_00632920 = 0xffffffff;

  DAT_00632928 = DAT_00632e88;

  if (DAT_0059ee98 != 0) {

    FUN_00497510(DAT_0059ee98);

  }

  DAT_0059ee98 = 0;

  DAT_0059ee98 = object_allocate_type(0x401,0x80000000);

  *(uint *)(DAT_0059ee98 + 0xd8) = *(uint *)(DAT_0059ee98 + 0xd8) | 0x40000000;

  camera_override_refpt(DAT_0059ee98,0);

  iVar1 = 6;

  DAT_00632c0c = 1;

  DAT_0059e8e0 = 0;

  DAT_0059ee9c = 0;

  _DAT_0059eea0 = 0;

  _DAT_0059eea8 = 0;

  _DAT_0059eea4 = 6;

  DAT_0059eec4 = 0;

  _DAT_0059eec8 = 0;

  _DAT_0059eecc = &LAB_004829c0;

  _DAT_0059eed0 = 0;

  puVar3 = &DAT_0059dcd0;

  for (iVar2 = 300; iVar2 != 0; iVar2 = iVar2 + -1) {

    *puVar3 = 0;

    puVar3 = puVar3 + 1;

  }

  iVar2 = dialog_level_is_base_8();

  if (iVar2 != 0) {

    main_fx_004470b0(&DAT_0055a0f8);

  }

  DAT_0059eec0 = (uint)(iVar2 != 0);

  DAT_0055bdb0 = 7;

  DAT_0055bdb4 = 0;

  local_24 = 0;

  DAT_0055bdbc = 0;

  do {

    iVar2 = FUN_00519F20(&local_24,0x20,local_20);

    if (0 < iVar2) break;

    if (iVar2 == 0) {

      iVar2 = match(local_20,&DAT_0063304c);

      if (iVar2 != 0) {

        iVar1 = DAT_0055bdbc + 1;

      }

      DAT_0055bdbc = DAT_0055bdbc + 1;

    }

  } while (DAT_0055bdbc < 5);

  iVar2 = DAT_00632918;

  DAT_0059ee9c = iVar1;

  (&DAT_0059dcd0)[iVar1 * 3] = 1;

  mission_004fe2d0(&DAT_00632900,*(undefined4 *)(*(int *)(iVar2 + 0x2ac) + iVar1 * 4),0x3f000000,

                   0x3f000000,&DAT_00632abc,&DAT_00632ac0);

  DAT_00632abc = (float)DAT_00632924 * DAT_00632abc;

  DAT_00632ac0 = (float)DAT_00632928 * DAT_00632ac0;

  _DAT_00632ac4 = DAT_00632abc;

  _DAT_00632ac8 = DAT_00632ac0;

  sound_play(0x6e6);

  return;

}

/* ===== FUN_00483e50 @ 0x00483E50 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_00483e50(void)



{

  char cVar1;

  byte bVar2;

  uint uVar3;

  char *pcVar4;

  byte *pbVar5;

  int iVar6;

  byte *pbVar7;

  bool bVar8;

  byte local_40 [64];

  

  DAT_0063306c = 1;

  if (DAT_0063304c != '\0') goto LAB_00483e92;

  _DAT_0063304c = s_Player_0055bf98._0_4_;

  _DAT_00633050 = s_Player_0055bf98._4_2_;

  DAT_00633052 = s_Player_0055bf98[6];

  while( true ) {

LAB_00483e92:

    if (DAT_005810b8 < 2) {

      uVar3 = (byte)PTR_DAT_00580eac[DAT_0063304c * 2] & 8;

    }

    else {

      uVar3 = FUN_00544123((int)DAT_0063304c,8);

    }

    if (uVar3 == 0) break;

    pcVar4 = &DAT_0063304d;

    do {

      cVar1 = *pcVar4;

      pcVar4[-1] = cVar1;

      pcVar4 = pcVar4 + 1;

    } while (cVar1 != '\0');

  }

  uVar3 = 0xffffffff;

  pcVar4 = &DAT_0063304c;

  do {

    if (uVar3 == 0) break;

    uVar3 = uVar3 - 1;

    cVar1 = *pcVar4;

    pcVar4 = pcVar4 + 1;

  } while (cVar1 != '\0');

  for (pcVar4 = (char *)((int)&DAT_00633048 + ~uVar3 + 2); (char *)((int)&DAT_00633048 + 3) < pcVar4

      ; pcVar4 = pcVar4 + -1) {

    if (DAT_005810b8 < 2) {

      uVar3 = (byte)PTR_DAT_00580eac[*pcVar4 * 2] & 8;

    }

    else {

      uVar3 = FUN_00544123((int)*pcVar4,8);

    }

    if (uVar3 == 0) break;

    *pcVar4 = '\0';

  }

  FUN_0051a1c0(s_DefPlayer_0055a07c,local_40,0x40);

  FUN_00519fe0(&DAT_0063304c);

  comm_0051a130(s_Deleted_0055bf90,0);

  if (local_40[0] != 0) {

    pbVar7 = (byte *)&DAT_0063304c;

    pbVar5 = local_40;

    do {

      bVar2 = *pbVar5;

      bVar8 = bVar2 < *pbVar7;

      if (bVar2 != *pbVar7) {

LAB_00483f8d:

        iVar6 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);

        goto LAB_00483f92;

      }

      if (bVar2 == 0) break;

      bVar2 = pbVar5[1];

      bVar8 = bVar2 < pbVar7[1];

      if (bVar2 != pbVar7[1]) goto LAB_00483f8d;

      pbVar5 = pbVar5 + 2;

      pbVar7 = pbVar7 + 2;

    } while (bVar2 != 0);

    iVar6 = 0;

LAB_00483f92:

    if (iVar6 != 0) {

      game_options_load();

    }

  }

  FUN_0051a1f0(s_DefPlayer_0055a07c,&DAT_0063304c);

  level_config_load();

  menu_keymap_screen();

  keymap_slot_load();

  return;

}

/* ===== savegame_cam_section @ 0x00484340 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void savegame_cam_section(void)



{

  int iVar1;

  int *piVar2;

  int iVar3;

  undefined4 *puVar4;

  int local_4;

  

  if (DAT_0059eed4 == 0) {

    if (DAT_0059ee9c == 6) {

      DAT_0059eed4 = main_dlog_00427150();

      main_dlog_00427970(DAT_0059eed4,0,0x3f000000,0x40400000,0x88000002,&DAT_0063304c,0x20);

      DAT_0063304c = 0;

      return;

    }

    dialog_level_pop(&LAB_00483fd0);

    FUN_0040d790();

    FUN_00497510(DAT_0059ee98);

    DAT_0059ee98 = 0;

    DAT_00632c0c = 0;

    iVar3 = 0;

    piVar2 = &DAT_0059dcd4;

    do {

      if (*piVar2 != 0) {

        main_menu_00483200(iVar3,0);

      }

      piVar2 = piVar2 + 3;

      iVar3 = iVar3 + 1;

      iVar1 = DAT_0059eec4;

    } while ((int)piVar2 < 0x59e184);

    for (; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x50)) {

      if (*(int *)(iVar1 + 0x48) != 0) {

        main_menu_00483200(0xffffffff,iVar1);

      }

    }

    mission_00447fd0(0,2);

    if (DAT_0059eec0 != 0) {

      main_fx_004471a0();

    }

    puVar4 = &DAT_00632aa0;

    for (iVar3 = 0x1f; iVar3 != 0; iVar3 = iVar3 + -1) {

      *puVar4 = 0;

      puVar4 = puVar4 + 1;

    }

    _DAT_00632ac4 = DAT_00632abc;

    iVar3 = 0;

    _DAT_00632ac8 = DAT_00632ac0;

    local_4 = 0;

    do {

      iVar1 = FUN_00519F20(&local_4,0x20,&DAT_0063304c);

      if (0 < iVar1) break;

      if (iVar1 == 0) {

        if (DAT_0059ee9c + -1 == iVar3) break;

        iVar3 = iVar3 + 1;

      }

    } while (iVar3 < 5);

    FUN_00483e50();

  }

  else {

    if (DAT_0063304c == '\0') {

      return;

    }

    dialog_level_pop(&LAB_00483fd0);

    FUN_0040d790();

    FUN_00497510(DAT_0059ee98);

    DAT_0059ee98 = 0;

    DAT_00632c0c = 0;

    iVar3 = 0;

    piVar2 = &DAT_0059dcd4;

    do {

      if (*piVar2 != 0) {

        main_menu_00483200(iVar3,0);

      }

      piVar2 = piVar2 + 3;

      iVar3 = iVar3 + 1;

      iVar1 = DAT_0059eec4;

    } while ((int)piVar2 < 0x59e184);

    for (; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x50)) {

      if (*(int *)(iVar1 + 0x48) != 0) {

        main_menu_00483200(0xffffffff,iVar1);

      }

    }

    mission_00447fd0(0,2);

    if (DAT_0059eec0 != 0) {

      main_fx_004471a0();

    }

    puVar4 = &DAT_00632aa0;

    for (iVar3 = 0x1f; iVar3 != 0; iVar3 = iVar3 + -1) {

      *puVar4 = 0;

      puVar4 = puVar4 + 1;

    }

    _DAT_00632ac4 = DAT_00632abc;

    _DAT_00632ac8 = DAT_00632ac0;

    main_dlog_00427180(DAT_0059eed4);

    DAT_0059eed4 = 0;

    FUN_00483e50();

    comm_0051a130(s_CamMode_00555a28,1);

    FUN_0040d130(1);

    local_4 = 0;

    FUN_0051a220(s_SaveIdx_00555edc,&local_4);

    comm_0051a130(s_SaveIdx_00555edc,local_4);

    local_4 = local_4 + 1;

    FUN_0051a250(s_SaveIdx_00555edc,local_4);

  }

  if (((DAT_0063315c == 0) && (DAT_00633160 == 0)) && (DAT_0063317c == 0)) {

    sound_play(0x659);

  }

  return;

}

/* ===== FUN_004845e0 @ 0x004845E0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_004845e0(int param_1,int param_2)



{

  int iVar1;

  int iVar2;

  

  iVar1 = DAT_0059ee9c;

  DAT_0059ee9c = param_1;

  if (param_1 < 1) {

    iVar2 = DAT_0055bdbc;

    if (DAT_0055bdbc < 1) {

      iVar2 = 6;

    }

  }

  else {

    iVar2 = DAT_0059ee9c;

    if (DAT_0055bdbc < param_1) {

      if (param_2 == 0) {

        iVar2 = ((DAT_0055bdbc < 1) - 1 & 0xfffffffb) + 6;

      }

      else {

        iVar2 = iVar1;

        if ((param_1 == 6) && (iVar2 = DAT_0059ee9c, DAT_0055bdbc == 5)) {

          iVar2 = 1;

        }

      }

    }

  }

  DAT_0059ee9c = iVar2;

  iVar2 = DAT_0059ee9c;

  (&DAT_0059dcd0)[iVar1 * 3] = 0;

  (&DAT_0059dcd0)[iVar2 * 3] = 1;

  if ((((DAT_0063315c == 0) && (DAT_00633160 == 0)) && (DAT_0063317c == 0)) && (iVar1 != iVar2)) {

    sound_play(0x65a);

    iVar2 = DAT_0059ee9c;

  }

  if (param_2 == 0) {

    mission_004fe2d0(&DAT_00632900,

                     *(undefined4 *)(*(int *)(DAT_00632918 + DAT_0063291c * 0x24) + iVar2 * 4),

                     0x3f000000,0x3f000000,&DAT_00632abc,&DAT_00632ac0);

    DAT_00632abc = (float)DAT_00632924 * DAT_00632abc;

    DAT_00632ac0 = (float)DAT_00632928 * DAT_00632ac0;

    _DAT_00632ac4 = DAT_00632abc;

    _DAT_00632ac8 = DAT_00632ac0;

  }

  return;

}

/* ===== mission_cheat_check @ 0x00484870 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void mission_cheat_check(void)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  undefined4 *puVar6;

  int local_4;

  

  dlog_push_level(&LAB_00484ce0,FUN_004829d0);

  FUN_00426FA0();

  iVar1 = main_status_00500520(&DAT_00632900);

  if (iVar1 == 0) {

    dialog_level_pop(&LAB_00484ce0);

    return;

  }

  DAT_0055bdb8 = 0x21;

  DAT_0063291c = 0x21;

  DAT_00632924 = DAT_00632e84;

  DAT_00632920 = 0xffffffff;

  DAT_00632928 = DAT_00632e88;

  if (DAT_0059ee98 != 0) {

    FUN_00497510(DAT_0059ee98);

  }

  DAT_0059ee98 = 0;

  DAT_0059ee98 = object_allocate_type(0x402,0x80000000);

  *(uint *)(DAT_0059ee98 + 0xd8) = *(uint *)(DAT_0059ee98 + 0xd8) | 0x40000000;

  camera_override_refpt(DAT_0059ee98,0);

  local_4 = 0;

  mission_0051a0c0(s_MissionCheat_0055be64,&local_4);

  iVar4 = 0;

  iVar1 = FUN_004B0B40();

  iVar5 = 0;

  if (-1 < iVar1) {

    do {

      iVar2 = FUN_004B09C0(iVar5);

      if ((iVar2 != 0) && (((*(byte *)(iVar2 + 8) & 1) == 0 || (local_4 != 0)))) {

        iVar4 = iVar4 + 1;

      }

      iVar5 = iVar5 + 1;

    } while (iVar5 <= iVar1);

    if (0x27 < iVar4) {

      iVar4 = 0x27;

    }

  }

  iVar1 = iVar4 + 1;

  DAT_00632c0c = 1;

  DAT_0059e8e0 = 0;

  DAT_0059ee9c = 0;

  _DAT_0059eea0 = 0;

  _DAT_0059eea8 = 0;

  DAT_0059eec4 = 0;

  _DAT_0059eec8 = (code *)0x0;

  _DAT_0059eecc = &LAB_004829c0;

  _DAT_0059eed0 = 0;

  puVar6 = &DAT_0059dcd0;

  _DAT_0059eea4 = iVar4;

  for (iVar5 = 300; iVar5 != 0; iVar5 = iVar5 + -1) {

    *puVar6 = 0;

    puVar6 = puVar6 + 1;

  }

  iVar4 = dialog_level_is_base_8();

  if (iVar4 != 0) {

    main_fx_004470b0(&DAT_0055a0f8);

  }

  DAT_0059eec0 = (uint)(iVar4 != 0);

  DAT_0055bdb4 = 1;

  _DAT_0059eec8 = mission_load_world;

  DAT_0055bdb0 = iVar1;

  if (DAT_00632f08 < 0xe) {

    iVar5 = 0;

    iVar4 = FUN_004B0B40();

    iVar2 = 0;

    iVar1 = DAT_0059ee9c;

    if (-1 < iVar4) {

      do {

        iVar1 = FUN_004B09C0(iVar2);

        if (iVar1 != 0) {

          if (((*(byte *)(iVar1 + 8) & 1) == 0) || (local_4 != 0)) {

            iVar5 = iVar5 + 1;

          }

          iVar3 = match(&DAT_00633070,*(undefined4 *)(iVar1 + 4));

          iVar1 = iVar5;

          if (iVar3 != 0) break;

        }

        iVar2 = iVar2 + 1;

        iVar1 = DAT_0059ee9c;

      } while (iVar2 <= iVar4);

    }

    DAT_0059ee9c = iVar1;

    if (0x27 < DAT_0059ee9c) {

      DAT_0059ee9c = 0x27;

    }

  }

  else {

    DAT_0059ee9c = DAT_00632d20;

    if (DAT_00632d20 < 1) {

      DAT_0059ee9c = 1;

    }

  }

  iVar1 = DAT_0059ee9c;

  (&DAT_0059dcd0)[DAT_0059ee9c * 3] = 1;

  if (DAT_00633158 != 0) {

    mission_load_cheat();

    iVar1 = DAT_0059ee9c;

  }

  mission_004fe2d0(&DAT_00632900,*(undefined4 *)(*(int *)(DAT_00632918 + 0x4a4) + iVar1 * 4),

                   0x3f000000,0x3f000000,&DAT_00632abc,&DAT_00632ac0);

  DAT_00632abc = (float)DAT_00632924 * DAT_00632abc;

  DAT_00632ac0 = (float)DAT_00632928 * DAT_00632ac0;

  _DAT_00632ac4 = DAT_00632abc;

  _DAT_00632ac8 = DAT_00632ac0;

  return;

}

/* ===== mission_load_cheat @ 0x00484B00 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void mission_load_cheat(void)



{

  char cVar1;

  int iVar2;

  char *pcVar3;

  char *pcVar4;

  int iVar5;

  int *piVar6;

  int iVar7;

  int iVar8;

  undefined4 *puVar9;

  int local_4;

  

  dialog_level_pop(&LAB_00484ce0);

  FUN_0040d790();

  FUN_00497510(DAT_0059ee98);

  iVar5 = 0;

  DAT_0059ee98 = 0;

  DAT_00632c0c = 0;

  iVar8 = 0;

  piVar6 = &DAT_0059dcd4;

  do {

    if (*piVar6 != 0) {

      main_menu_00483200(iVar8,0);

    }

    piVar6 = piVar6 + 3;

    iVar8 = iVar8 + 1;

    iVar7 = DAT_0059eec4;

  } while ((int)piVar6 < 0x59e184);

  for (; iVar7 != 0; iVar7 = *(int *)(iVar7 + 0x50)) {

    if (*(int *)(iVar7 + 0x48) != 0) {

      main_menu_00483200(0xffffffff,iVar7);

    }

  }

  mission_00447fd0(0,2);

  if (DAT_0059eec0 != 0) {

    main_fx_004471a0();

  }

  puVar9 = &DAT_00632aa0;

  for (iVar8 = 0x1f; iVar8 != 0; iVar8 = iVar8 + -1) {

    *puVar9 = 0;

    puVar9 = puVar9 + 1;

  }

  _DAT_00632ac4 = DAT_00632abc;

  _DAT_00632ac8 = DAT_00632ac0;

  local_4 = 0;

  mission_0051a0c0(s_MissionCheat_0055be64,&local_4);

  iVar8 = FUN_004B0B40();

  iVar7 = 0;

  if (-1 < iVar8) {

    do {

      iVar2 = FUN_004B09C0(iVar7);

      if (iVar2 != 0) {

        if (((*(byte *)(iVar2 + 8) & 1) == 0) || (local_4 != 0)) {

          iVar5 = iVar5 + 1;

        }

        if (iVar5 == DAT_0059ee9c) {

          pcVar3 = *(char **)(iVar2 + 4);

          pcVar4 = &DAT_00633070;

          do {

            cVar1 = *pcVar3;

            pcVar3 = pcVar3 + 1;

            *pcVar4 = cVar1;

            pcVar4 = pcVar4 + 1;

          } while (cVar1 != '\0');

          FUN_0051a090(s_WorldName_0055a068,&DAT_00633070);

          if (DAT_00632bd0 == 0) {

            DAT_00632d20 = iVar7;

            if (DAT_006331f8 == 0) {

              mission_menu_load();

            }

            else {

              DAT_0059eeb0 = 0;

              FUN_00446620();

              (*DAT_005dd354)(DAT_0059eedc);

              DAT_0059eedc = 0;

              AudioSetSpeakerConfig__F14SPEAKER_SYSTEM_4(DAT_00632d20);

              mission_004576e0();

              FUN_00495990(0x6e6);

            }

          }

          else {

            mission_level_load(iVar7);

          }

          break;

        }

      }

      iVar7 = iVar7 + 1;

    } while (iVar7 <= iVar8);

  }

  if (((DAT_0063315c == 0) && (DAT_00633160 == 0)) && (DAT_0063317c == 0)) {

    sound_play(0x659);

  }

  return;

}

/* ===== mission_load_world @ 0x00485020 ===== */
undefined4 mission_load_world(int param_1)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int local_4;

  

  iVar4 = 0;

  if (param_1 == 0) {

    DAT_0059e498 = FUN_00507b00(s_LoadWorld_0055bfec);

    return DAT_0059e498;

  }

  local_4 = 0;

  mission_0051a0c0(s_MissionCheat_0055be64,&local_4);

  iVar1 = FUN_004B0B40();

  if (-1 < iVar1) {

    iVar3 = 0;

    do {

      iVar2 = FUN_004B09C0(iVar4);

      if (iVar2 != 0) {

        if (((*(byte *)(iVar2 + 8) & 1) == 0) || (local_4 != 0)) {

          iVar3 = iVar3 + 1;

        }

        if (iVar3 == param_1) {

          FUN_00542f27(&DAT_0059e188,&DAT_0055bfe4,*(undefined4 *)(iVar2 + 4));

          DAT_0059e498 = FUN_00507b00(&DAT_0059e188);

          iVar4 = FUN_00545650(&DAT_0059e188,DAT_0059e498);

          if (iVar4 == 0) {

            return *(undefined4 *)(iVar2 + 4);

          }

          return DAT_0059e498;

        }

      }

      iVar4 = iVar4 + 1;

    } while (iVar4 <= iVar1);

  }

  return 0;

}

/* ===== FUN_004850F0 @ 0x004850F0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_004850F0(void)



{

  int iVar1;

  int iVar2;

  int iVar3;

  undefined4 *puVar4;

  

  dlog_push_level(&LAB_004855a0,FUN_004829d0);

  FUN_00426FA0();

  iVar2 = main_status_00500520(&DAT_00632900);

  if (iVar2 != 0) {

    DAT_0055bdb8 = 0x15;

    DAT_0063291c = 0x15;

    DAT_00632924 = DAT_00632e84;

    DAT_00632920 = 0xffffffff;

    DAT_00632928 = DAT_00632e88;

    if (DAT_0059ee98 != 0) {

      FUN_00497510(DAT_0059ee98);

    }

    DAT_0059ee98 = 0;

    DAT_0059ee98 = object_allocate_type(0x402,0x80000000);

    *(uint *)(DAT_0059ee98 + 0xd8) = *(uint *)(DAT_0059ee98 + 0xd8) | 0x40000000;

    camera_override_refpt(DAT_0059ee98,0);

    DAT_00632c0c = 1;

    DAT_0059e8e0 = 0;

    DAT_0059ee9c = 0;

    _DAT_0059eea0 = 0;

    _DAT_0059eea8 = 0;

    _DAT_0059eea4 = 9;

    DAT_0059eec4 = 0;

    _DAT_0059eec8 = (undefined1 *)0x0;

    _DAT_0059eecc = &LAB_004829c0;

    _DAT_0059eed0 = 0;

    puVar4 = &DAT_0059dcd0;

    for (iVar2 = 300; iVar2 != 0; iVar2 = iVar2 + -1) {

      *puVar4 = 0;

      puVar4 = puVar4 + 1;

    }

    iVar2 = dialog_level_is_base_8();

    if (iVar2 != 0) {

      main_fx_004470b0(&DAT_0055a0f8);

    }

    iVar1 = DAT_00632918;

    DAT_0059eec0 = (uint)(iVar2 != 0);

    DAT_0055bdb0 = 10;

    DAT_0055bdb4 = 1;

    _DAT_0059eec8 = &LAB_00485780;

    if (DAT_00632f18 == 6) {

      iVar2 = 4;

    }

    else if (DAT_00632f18 == 7) {

      iVar2 = 5;

    }

    else if (DAT_00632f18 == 4) {

      iVar2 = 6;

    }

    else {

      iVar2 = DAT_00632f18;

      if (DAT_00632f18 == 5) {

        iVar2 = 7;

      }

    }

    iVar3 = iVar2 + 1;

    if (5 < iVar2) {

      iVar3 = iVar2 + 2;

    }

    DAT_0059ee9c = iVar3;

    (&DAT_0059dcd0)[iVar3 * 3] = 1;

    mission_004fe2d0(&DAT_00632900,*(undefined4 *)(*(int *)(iVar1 + 0x2f4) + iVar3 * 4),0x3f000000,

                     0x3f000000,&DAT_00632abc,&DAT_00632ac0);

    DAT_00632abc = (float)DAT_00632924 * DAT_00632abc;

    DAT_00632ac0 = (float)DAT_00632928 * DAT_00632ac0;

    _DAT_00632ac4 = DAT_00632abc;

    _DAT_00632ac8 = DAT_00632ac0;

    return;

  }

  dialog_level_pop(&LAB_004855a0);

  return;

}

/* ===== comm_00485300 @ 0x00485300 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void comm_00485300(void)



{

  int iVar1;

  undefined4 uVar2;

  int *piVar3;

  int iVar4;

  undefined4 *puVar5;

  

  dialog_level_pop(&LAB_004855a0);

  FUN_0040d790();

  FUN_00497510(DAT_0059ee98);

  DAT_0059ee98 = 0;

  DAT_00632c0c = 0;

  iVar4 = 0;

  piVar3 = &DAT_0059dcd4;

  do {

    if (*piVar3 != 0) {

      main_menu_00483200(iVar4,0);

    }

    piVar3 = piVar3 + 3;

    iVar4 = iVar4 + 1;

    iVar1 = DAT_0059eec4;

  } while ((int)piVar3 < 0x59e184);

  for (; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x50)) {

    if (*(int *)(iVar1 + 0x48) != 0) {

      main_menu_00483200(0xffffffff,iVar1);

    }

  }

  mission_00447fd0(0,2);

  if (DAT_0059eec0 != 0) {

    main_fx_004471a0();

  }

  puVar5 = &DAT_00632aa0;

  for (iVar4 = 0x1f; iVar4 != 0; iVar4 = iVar4 + -1) {

    *puVar5 = 0;

    puVar5 = puVar5 + 1;

  }

  _DAT_00632ac4 = DAT_00632abc;

  _DAT_00632ac8 = DAT_00632ac0;

  DAT_00632f18 = DAT_0059ee9c + -1;

  if (7 < DAT_0059ee9c) {

    DAT_00632f18 = DAT_0059ee9c + -2;

  }

  if (DAT_00632f18 == 6) {

    DAT_00632f18 = 4;

  }

  else if (DAT_00632f18 == 7) {

    DAT_00632f18 = 5;

  }

  else if (DAT_00632f18 == 4) {

    DAT_00632f18 = 6;

  }

  else if (DAT_00632f18 == 5) {

    DAT_00632f18 = 7;

  }

  comm_gametype_menu(DAT_00632f18);

  iVar4 = FUN_005213a0(DAT_00632f18);

  if (((iVar4 != 0) && (iVar4 = FUN_00525120(DAT_00632f10), iVar4 != 0)) &&

     (iVar4 = FUN_00521310(DAT_00632f18), iVar4 == 0)) {

    DAT_00632f10 = 0;

    comm_00521620(0);

    iVar4 = FUN_004B09C0(DAT_00632ee4);

    if ((iVar4 != 0) && (iVar4 = FUN_004B0900(DAT_00632ee4,DAT_00632f10,DAT_00632f44), iVar4 == 0))

    {

      FUN_00521980(&DAT_00632ee4);

      comm_worldname_menu2(DAT_00632ee4);

    }

  }

  DAT_00632f1c = FUN_00521350(DAT_00632f18);

  uVar2 = FUN_00521350(DAT_00632f18);

  comm_allowjoiners_menu(DAT_00632f1c,uVar2);

  iVar4 = FUN_00521330(DAT_00632f18);

  if ((iVar4 == 0) && (iVar4 = FUN_00521310(DAT_00632f18), iVar4 == 0)) {

    DAT_00632ff0 = 0;

  }

  iVar4 = FUN_00521330(DAT_00632f18);

  if (iVar4 == 0) {

    iVar4 = FUN_00521310(DAT_00632f18);

    uVar2 = 0;

    if (iVar4 == 0) goto LAB_00485528;

  }

  uVar2 = 1;

LAB_00485528:

  comm_base_status_menu(DAT_00632ff0,uVar2);

  comm_capture_time_menu(DAT_00632f2c,1);

  uVar2 = FUN_00521370(DAT_00632f18);

  comm_capture_points_menu(DAT_00632f28,uVar2);

  comm_comm_00529e00();

  gamespy_statechange3();

  if (((DAT_0063315c == 0) && (DAT_00633160 == 0)) && (DAT_0063317c == 0)) {

    sound_play(0x659);

  }

  return;

}

/* ===== FUN_00485840 @ 0x00485840 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_00485840(void)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  undefined4 *puVar6;

  

  dlog_push_level(&LAB_00485c90,FUN_004829d0);

  FUN_00426FA0();

  iVar1 = main_status_00500520(&DAT_00632900);

  if (iVar1 == 0) {

    dialog_level_pop(&LAB_00485c90);

    return;

  }

  if ((float)DAT_00632e88 < 480.0 != ((float)DAT_00632e88 == 480.0)) {

    win95_text_0051b160();

    win95_text_0051adb0(0x18);

  }

  DAT_0055bdb8 = 0x14;

  DAT_0063291c = 0x14;

  DAT_00632924 = DAT_00632e84;

  iVar1 = 0;

  DAT_00632920 = 0xffffffff;

  DAT_00632928 = DAT_00632e88;

  if (DAT_0059ee98 != 0) {

    FUN_00497510(DAT_0059ee98);

  }

  DAT_0059ee98 = 0;

  DAT_0059ee98 = object_allocate_type(0x402,0x80000000);

  *(uint *)(DAT_0059ee98 + 0xd8) = *(uint *)(DAT_0059ee98 + 0xd8) | 0x40000000;

  camera_override_refpt(DAT_0059ee98,0);

  iVar4 = 0;

  iVar2 = FUN_004B0B40();

  iVar5 = 0;

  if (-1 < iVar2) {

    do {

      iVar3 = FUN_004B0900(iVar5,DAT_00632f10,1);

      if (iVar3 != 0) {

        iVar4 = iVar4 + 1;

      }

      iVar5 = iVar5 + 1;

    } while (iVar5 <= iVar2);

    if (0x12 < iVar4) {

      iVar4 = 0x12;

    }

  }

  DAT_00632c0c = 1;

  DAT_0059e8e0 = 0;

  DAT_0059ee9c = 0;

  _DAT_0059eea0 = 0;

  _DAT_0059eea8 = 0;

  DAT_0059eec4 = 0;

  _DAT_0059eec8 = (undefined1 *)0x0;

  _DAT_0059eecc = &LAB_004829c0;

  _DAT_0059eed0 = 0;

  puVar6 = &DAT_0059dcd0;

  _DAT_0059eea4 = iVar4;

  for (iVar2 = 300; iVar2 != 0; iVar2 = iVar2 + -1) {

    *puVar6 = 0;

    puVar6 = puVar6 + 1;

  }

  iVar2 = dialog_level_is_base_8();

  if (iVar2 != 0) {

    main_fx_004470b0(&DAT_0055a0f8);

  }

  DAT_0059eec0 = (uint)(iVar2 != 0);

  DAT_0055bdb4 = 1;

  _DAT_0059eec8 = &LAB_00485e60;

  DAT_0055bdb0 = iVar4 + 1;

  if (DAT_00632f08 < 0xe) {

    iVar4 = FUN_004B0B40();

    iVar5 = 0;

    iVar2 = DAT_0059ee9c;

    if (-1 < iVar4) {

      do {

        iVar2 = FUN_004B09C0(iVar5);

        if (iVar2 != 0) {

          iVar3 = FUN_004B0900(iVar5,DAT_00632f10,1);

          if (iVar3 != 0) {

            iVar1 = iVar1 + 1;

          }

          iVar3 = match(&DAT_00632ee8,*(undefined4 *)(iVar2 + 4));

          iVar2 = iVar1;

          if (iVar3 != 0) break;

          if (0x12 < DAT_0059ee9c) {

            DAT_0059ee9c = 0x12;

          }

        }

        iVar5 = iVar5 + 1;

        iVar2 = DAT_0059ee9c;

      } while (iVar5 <= iVar4);

    }

    DAT_0059ee9c = iVar2;

    if (DAT_0059ee9c != 0) goto LAB_00485a62;

  }

  DAT_0059ee9c = 1;

LAB_00485a62:

  iVar1 = DAT_00633158;

  (&DAT_0059dcd0)[DAT_0059ee9c * 3] = 1;

  if (iVar1 != 0) {

    mission_mpworld_load();

  }

  mission_004fe2d0(&DAT_00632900,*(undefined4 *)(*(int *)(DAT_00632918 + 0x2d0) + DAT_0059ee9c * 4),

                   0x3f000000,0x3f000000,&DAT_00632abc,&DAT_00632ac0);

  DAT_00632abc = (float)DAT_00632924 * DAT_00632abc;

  DAT_00632ac0 = (float)DAT_00632928 * DAT_00632ac0;

  _DAT_00632ac4 = DAT_00632abc;

  _DAT_00632ac8 = DAT_00632ac0;

  return;

}

/* ===== mission_mpworld_load @ 0x00485B00 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void mission_mpworld_load(void)



{

  char cVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  char *pcVar5;

  char *pcVar6;

  int *piVar7;

  int iVar8;

  int iVar9;

  undefined4 *puVar10;

  

  dialog_level_pop(&LAB_00485c90);

  FUN_0040d790();

  FUN_00497510(DAT_0059ee98);

  DAT_0059ee98 = 0;

  DAT_00632c0c = 0;

  iVar9 = 0;

  piVar7 = &DAT_0059dcd4;

  do {

    if (*piVar7 != 0) {

      main_menu_00483200(iVar9,0);

    }

    piVar7 = piVar7 + 3;

    iVar9 = iVar9 + 1;

    iVar4 = DAT_0059eec4;

  } while ((int)piVar7 < 0x59e184);

  for (; iVar4 != 0; iVar4 = *(int *)(iVar4 + 0x50)) {

    if (*(int *)(iVar4 + 0x48) != 0) {

      main_menu_00483200(0xffffffff,iVar4);

    }

  }

  iVar9 = 0;

  mission_00447fd0(0,2);

  if (DAT_0059eec0 != 0) {

    main_fx_004471a0();

  }

  puVar10 = &DAT_00632aa0;

  for (iVar4 = 0x1f; iVar4 != 0; iVar4 = iVar4 + -1) {

    *puVar10 = 0;

    puVar10 = puVar10 + 1;

  }

  _DAT_00632ac4 = DAT_00632abc;

  _DAT_00632ac8 = DAT_00632ac0;

  iVar4 = FUN_004B0B40();

  iVar8 = 0;

  if (-1 < iVar4) {

    do {

      iVar2 = FUN_004B09C0(iVar8);

      if (iVar2 != 0) {

        iVar3 = FUN_004B0900(iVar8,DAT_00632f10,1);

        if (iVar3 != 0) {

          iVar9 = iVar9 + 1;

        }

        if (iVar9 == DAT_0059ee9c) {

          pcVar5 = *(char **)(iVar2 + 4);

          pcVar6 = &DAT_00632ee8;

          do {

            cVar1 = *pcVar5;

            pcVar5 = pcVar5 + 1;

            *pcVar6 = cVar1;

            pcVar6 = pcVar6 + 1;

          } while (cVar1 != '\0');

          FUN_0051a090(s_MPWorldName_0055a05c,&DAT_00632ee8);

          DAT_00632ee4 = iVar8;

          comm_worldname_menu2(iVar8);

          comm_comm_00529e00();

          gamespy_statechange3();

          break;

        }

      }

      iVar8 = iVar8 + 1;

    } while (iVar8 <= iVar4);

  }

  if ((float)DAT_00632e88 < 480.0 != ((float)DAT_00632e88 == 480.0)) {

    win95_text_0051b160();

    win95_text_0051adb0(0xc);

  }

  if (((DAT_0063315c == 0) && (DAT_00633160 == 0)) && (DAT_0063317c == 0)) {

    sound_play(0x659);

  }

  return;

}

/* ===== dlog_00485f10 @ 0x00485F10 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void dlog_00485f10(void)



{

  int iVar1;

  undefined4 *puVar2;

  

  dlog_push_level(&LAB_00486250,FUN_004829d0);

  FUN_00426FA0();

  iVar1 = main_status_00500520(&DAT_00632900);

  if (iVar1 != 0) {

    DAT_0055bdb8 = 0x16;

    DAT_0063291c = 0x16;

    DAT_00632924 = DAT_00632e84;

    DAT_00632920 = 0xffffffff;

    DAT_00632928 = DAT_00632e88;

    if (DAT_0059ee98 != 0) {

      FUN_00497510(DAT_0059ee98);

    }

    DAT_0059ee98 = 0;

    DAT_0059ee98 = object_allocate_type(0x403,0x80000000);

    *(uint *)(DAT_0059ee98 + 0xd8) = *(uint *)(DAT_0059ee98 + 0xd8) | 0x40000000;

    camera_override_refpt(DAT_0059ee98,0);

    DAT_00632c0c = 1;

    DAT_0059e8e0 = 0;

    DAT_0059ee9c = 0;

    _DAT_0059eea0 = 0;

    _DAT_0059eea8 = 0;

    _DAT_0059eea4 = 4;

    DAT_0059eec4 = 0;

    _DAT_0059eec8 = (undefined1 *)0x0;

    _DAT_0059eecc = &LAB_004829c0;

    _DAT_0059eed0 = (undefined1 *)0x0;

    puVar2 = &DAT_0059dcd0;

    for (iVar1 = 300; iVar1 != 0; iVar1 = iVar1 + -1) {

      *puVar2 = 0;

      puVar2 = puVar2 + 1;

    }

    iVar1 = dialog_level_is_base_8();

    if (iVar1 != 0) {

      main_fx_004470b0(&DAT_0055a0f8);

    }

    DAT_0059eec0 = (uint)(iVar1 != 0);

    DAT_0055bdb0 = 5;

    DAT_0055bdb4 = 1;

    _DAT_0059eec8 = &LAB_004862b0;

    _DAT_0059eed0 = &LAB_004862d0;

    DAT_0059eed8 = main_dlog_00427150();

    main_dlog_00427970(DAT_0059eed8,0,0x3f000000,0x40400000,0x88000002,&DAT_00632f48,0x20);

    if (DAT_0063315c != 0) {

      menu_dialog_teardown();

    }

    mission_004fe2d0(&DAT_00632900,

                     *(undefined4 *)(*(int *)(DAT_00632918 + 0x318) + DAT_0059ee9c * 4),0x3f000000,

                     0x3f000000,&DAT_00632abc,&DAT_00632ac0);

    DAT_00632abc = (float)DAT_00632924 * DAT_00632abc;

    DAT_00632ac0 = (float)DAT_00632928 * DAT_00632ac0;

    _DAT_00632ac4 = DAT_00632abc;

    _DAT_00632ac8 = DAT_00632ac0;

    return;

  }

  dialog_level_pop(&LAB_00486250);

  return;

}

/* ===== menu_dialog_teardown @ 0x00486110 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void menu_dialog_teardown(void)



{

  int iVar1;

  int *piVar2;

  int iVar3;

  undefined4 *puVar4;

  

  if (DAT_00632f48 != '\0') {

    dialog_level_pop(&LAB_00486250);

    FUN_0040d790();

    FUN_00497510(DAT_0059ee98);

    DAT_0059ee98 = 0;

    DAT_00632c0c = 0;

    iVar3 = 0;

    piVar2 = &DAT_0059dcd4;

    do {

      if (*piVar2 != 0) {

        main_menu_00483200(iVar3,0);

      }

      piVar2 = piVar2 + 3;

      iVar3 = iVar3 + 1;

      iVar1 = DAT_0059eec4;

    } while ((int)piVar2 < 0x59e184);

    for (; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x50)) {

      if (*(int *)(iVar1 + 0x48) != 0) {

        main_menu_00483200(0xffffffff,iVar1);

      }

    }

    mission_00447fd0(0,2);

    if (DAT_0059eec0 != 0) {

      main_fx_004471a0();

    }

    puVar4 = &DAT_00632aa0;

    for (iVar3 = 0x1f; iVar3 != 0; iVar3 = iVar3 + -1) {

      *puVar4 = 0;

      puVar4 = puVar4 + 1;

    }

    _DAT_00632ac4 = DAT_00632abc;

    _DAT_00632ac8 = DAT_00632ac0;

    main_dlog_00427180(DAT_0059eed8);

    DAT_0059eed8 = 0;

    comm_session_menu(&DAT_00632f48,1);

    comm_comm_00529e00();

    gamespy_statechange3();

    if (((DAT_0063315c == 0) && (DAT_00633160 == 0)) && (DAT_0063317c == 0)) {

      sound_play(0x659);

    }

  }

  return;

}

/* ===== FUN_004862E0 @ 0x004862E0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_004862E0(void)



{

  int iVar1;

  undefined4 *puVar2;

  code *pcVar3;

  

  iVar1 = FUN_004469e0();

  if (iVar1 == 0) {

    pcVar3 = FUN_00471dc0;

  }

  else {

    pcVar3 = FUN_004829d0;

  }

  dlog_push_level(&LAB_004864d0,pcVar3);

  FUN_00426FA0();

  iVar1 = main_status_00500520(&DAT_00632900);

  if (iVar1 != 0) {

    DAT_0055bdb8 = 0x18;

    DAT_0063291c = 0x18;

    DAT_00632924 = DAT_00632e84;

    DAT_00632920 = 0xffffffff;

    DAT_00632928 = DAT_00632e88;

    if (DAT_0059ee98 != 0) {

      FUN_00497510(DAT_0059ee98);

    }

    DAT_0059ee98 = 0;

    DAT_0059ee98 = object_allocate_type(0x402,0x80000000);

    *(uint *)(DAT_0059ee98 + 0xd8) = *(uint *)(DAT_0059ee98 + 0xd8) | 0x40000000;

    iVar1 = FUN_004469e0();

    if (iVar1 != 0) {

      camera_override_refpt(DAT_0059ee98,0);

    }

    DAT_00632c0c = 1;

    DAT_0059e8e0 = 0;

    DAT_0059ee9c = 0;

    _DAT_0059eea0 = 0;

    _DAT_0059eea8 = 0;

    _DAT_0059eea4 = 0x52;

    DAT_0059eec4 = 0;

    _DAT_0059eec8 = 0;

    _DAT_0059eecc = &LAB_004829c0;

    _DAT_0059eed0 = 0;

    puVar2 = &DAT_0059dcd0;

    for (iVar1 = 300; iVar1 != 0; iVar1 = iVar1 + -1) {

      *puVar2 = 0;

      puVar2 = puVar2 + 1;

    }

    iVar1 = dialog_level_is_base_8();

    if (iVar1 != 0) {

      main_fx_004470b0(&DAT_0055a0f8);

    }

    DAT_0059eec0 = (uint)(iVar1 != 0);

    DAT_0055bdb0 = 0x53;

    DAT_0055bdb4 = 1;

    DAT_0059ee9c = 0x53;

    _DAT_0059e0b4 = 1;

    DAT_0059eee0 = 0;

    FUN_00518FA0();

    mission_004fe2d0(&DAT_00632900,

                     *(undefined4 *)(*(int *)(DAT_00632918 + 0x360) + DAT_0059ee9c * 4),0x3f000000,

                     0x3f000000,&DAT_00632abc,&DAT_00632ac0);

    DAT_00632abc = (float)DAT_00632924 * DAT_00632abc;

    DAT_00632ac0 = (float)DAT_00632928 * DAT_00632ac0;

    _DAT_00632ac4 = DAT_00632abc;

    _DAT_00632ac8 = DAT_00632ac0;

    return;

  }

  dialog_level_pop(&LAB_004864d0);

  return;

}

/* ===== FUN_00486c40 @ 0x00486C40 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_00486c40(int param_1,int param_2,int param_3)



{

  int iVar1;

  int iVar2;

  

  iVar2 = DAT_0059ee9c;

  if (param_1 < DAT_0055bdb4) {

    param_1 = DAT_0059ee9c;

    if (param_2 == 0) {

      param_1 = DAT_0055bdb0 + -1;

    }

  }

  else if ((DAT_0055bdb0 + -1 < param_1) && (param_1 = DAT_0059ee9c, param_2 == 0)) {

    param_1 = DAT_0055bdb4;

  }

  iVar1 = DAT_0059ee9c * 3;

  DAT_0059ee9c = param_1;

  (&DAT_0059dcd0)[iVar1] = 0;

  (&DAT_0059dcd0)[param_1 * 3] = 1;

  if ((((DAT_0063315c == 0) && (DAT_00633160 == 0)) && (DAT_0063317c == 0)) &&

     ((param_1 != iVar2 && (param_3 != 0)))) {

    sound_play(0x65a);

    param_1 = DAT_0059ee9c;

  }

  if (param_2 == 0) {

    mission_004fe2d0(&DAT_00632900,

                     *(undefined4 *)(*(int *)(DAT_00632918 + DAT_0063291c * 0x24) + 4 + param_1 * 4)

                     ,0x3f000000,0x3f000000,&DAT_00632abc,&DAT_00632ac0);

    DAT_00632abc = (float)DAT_00632924 * DAT_00632abc;

    DAT_00632ac0 = (float)DAT_00632928 * DAT_00632ac0;

    _DAT_00632ac4 = DAT_00632abc;

    _DAT_00632ac8 = DAT_00632ac0;

  }

  return;

}

/* ===== FUN_00486FC0 @ 0x00486FC0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_00486FC0(void)



{

  int iVar1;

  undefined4 *puVar2;

  code *pcVar3;

  

  iVar1 = FUN_004469e0();

  if (iVar1 == 0) {

    pcVar3 = FUN_00471dc0;

  }

  else {

    pcVar3 = FUN_004829d0;

  }

  dlog_push_level(&LAB_004871b0,pcVar3);

  FUN_00426FA0();

  iVar1 = main_status_00500520(&DAT_00632900);

  if (iVar1 != 0) {

    DAT_0055bdb8 = 0x19;

    DAT_0063291c = 0x19;

    DAT_00632924 = DAT_00632e84;

    DAT_00632920 = 0xffffffff;

    DAT_00632928 = DAT_00632e88;

    if (DAT_0059ee98 != 0) {

      FUN_00497510(DAT_0059ee98);

    }

    DAT_0059ee98 = 0;

    DAT_0059ee98 = object_allocate_type(0x402,0x80000000);

    *(uint *)(DAT_0059ee98 + 0xd8) = *(uint *)(DAT_0059ee98 + 0xd8) | 0x40000000;

    iVar1 = FUN_004469e0();

    if (iVar1 != 0) {

      camera_override_refpt(DAT_0059ee98,0);

    }

    DAT_00632c0c = 1;

    DAT_0059e8e0 = 0;

    DAT_0059ee9c = 0;

    _DAT_0059eea0 = 0;

    _DAT_0059eea8 = 0;

    _DAT_0059eea4 = 0x40;

    DAT_0059eec4 = 0;

    _DAT_0059eec8 = 0;

    _DAT_0059eecc = &LAB_004829c0;

    _DAT_0059eed0 = 0;

    puVar2 = &DAT_0059dcd0;

    for (iVar1 = 300; iVar1 != 0; iVar1 = iVar1 + -1) {

      *puVar2 = 0;

      puVar2 = puVar2 + 1;

    }

    iVar1 = dialog_level_is_base_8();

    if (iVar1 != 0) {

      main_fx_004470b0(&DAT_0055a0f8);

    }

    DAT_0059eec0 = (uint)(iVar1 != 0);

    DAT_0055bdb0 = 0x41;

    DAT_0055bdb4 = 1;

    DAT_0059ee9c = 0x41;

    _DAT_0059dfdc = 1;

    DAT_0059eee0 = 0;

    FUN_00518FA0();

    mission_004fe2d0(&DAT_00632900,*(undefined4 *)(*(int *)(DAT_00632918 + 900) + DAT_0059ee9c * 4),

                     0x3f000000,0x3f000000,&DAT_00632abc,&DAT_00632ac0);

    DAT_00632abc = (float)DAT_00632924 * DAT_00632abc;

    DAT_00632ac0 = (float)DAT_00632928 * DAT_00632ac0;

    _DAT_00632ac4 = DAT_00632abc;

    _DAT_00632ac8 = DAT_00632ac0;

    return;

  }

  dialog_level_pop(&LAB_004871b0);

  return;

}

/* ===== FUN_00487B70 @ 0x00487B70 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_00487B70(void)



{

  int iVar1;

  undefined4 *puVar2;

  code *pcVar3;

  

  iVar1 = FUN_004469e0();

  if (iVar1 == 0) {

    pcVar3 = FUN_00471dc0;

  }

  else {

    pcVar3 = FUN_004829d0;

  }

  dlog_push_level(&LAB_00487d60,pcVar3);

  FUN_00426FA0();

  iVar1 = main_status_00500520(&DAT_00632900);

  if (iVar1 != 0) {

    DAT_0055bdb8 = 0x1a;

    DAT_0063291c = 0x1a;

    DAT_00632924 = DAT_00632e84;

    DAT_00632920 = 0xffffffff;

    DAT_00632928 = DAT_00632e88;

    if (DAT_0059ee98 != 0) {

      FUN_00497510(DAT_0059ee98);

    }

    DAT_0059ee98 = 0;

    DAT_0059ee98 = object_allocate_type(0x402,0x80000000);

    *(uint *)(DAT_0059ee98 + 0xd8) = *(uint *)(DAT_0059ee98 + 0xd8) | 0x40000000;

    iVar1 = FUN_004469e0();

    if (iVar1 != 0) {

      camera_override_refpt(DAT_0059ee98,0);

    }

    DAT_00632c0c = 1;

    DAT_0059e8e0 = 0;

    DAT_0059ee9c = 0;

    _DAT_0059eea0 = 0;

    _DAT_0059eea8 = 0;

    _DAT_0059eea4 = 0x38;

    DAT_0059eec4 = 0;

    _DAT_0059eec8 = 0;

    _DAT_0059eecc = &LAB_004829c0;

    _DAT_0059eed0 = 0;

    puVar2 = &DAT_0059dcd0;

    for (iVar1 = 300; iVar1 != 0; iVar1 = iVar1 + -1) {

      *puVar2 = 0;

      puVar2 = puVar2 + 1;

    }

    iVar1 = dialog_level_is_base_8();

    if (iVar1 != 0) {

      main_fx_004470b0(&DAT_0055a0f8);

    }

    DAT_0059eec0 = (uint)(iVar1 != 0);

    DAT_0055bdb0 = 0x39;

    DAT_0055bdb4 = 1;

    DAT_0059ee9c = 0x39;

    _DAT_0059df7c = 1;

    DAT_0059eee0 = 0;

    FUN_00518FA0();

    mission_004fe2d0(&DAT_00632900,

                     *(undefined4 *)(*(int *)(DAT_00632918 + 0x3a8) + DAT_0059ee9c * 4),0x3f000000,

                     0x3f000000,&DAT_00632abc,&DAT_00632ac0);

    DAT_00632abc = (float)DAT_00632924 * DAT_00632abc;

    DAT_00632ac0 = (float)DAT_00632928 * DAT_00632ac0;

    _DAT_00632ac4 = DAT_00632abc;

    _DAT_00632ac8 = DAT_00632ac0;

    return;

  }

  dialog_level_pop(&LAB_00487d60);

  return;

}

/* ===== FUN_00488740 @ 0x00488740 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_00488740(void)



{

  int iVar1;

  undefined4 *puVar2;

  

  dlog_push_level(&LAB_004889f0,FUN_004829d0);

  FUN_00426FA0();

  iVar1 = main_status_00500520(&DAT_00632900);

  if (iVar1 != 0) {

    DAT_0055bdb8 = 0x26;

    DAT_0063291c = 0x26;

    DAT_00632924 = DAT_00632e84;

    DAT_00632920 = 0xffffffff;

    DAT_00632928 = DAT_00632e88;

    if (DAT_0059ee98 != 0) {

      FUN_00497510(DAT_0059ee98);

    }

    DAT_0059ee98 = 0;

    DAT_0059ee98 = object_allocate_type(0x402,0x80000000);

    *(uint *)(DAT_0059ee98 + 0xd8) = *(uint *)(DAT_0059ee98 + 0xd8) | 0x40000000;

    camera_override_refpt(DAT_0059ee98,0);

    DAT_00632c0c = 1;

    DAT_0059e8e0 = 0;

    DAT_0059ee9c = 0;

    _DAT_0059eea0 = 0;

    _DAT_0059eea8 = 0;

    _DAT_0059eea4 = 2;

    DAT_0059eec4 = 0;

    _DAT_0059eec8 = 0;

    _DAT_0059eecc = &LAB_004829c0;

    _DAT_0059eed0 = 0;

    puVar2 = &DAT_0059dcd0;

    for (iVar1 = 300; iVar1 != 0; iVar1 = iVar1 + -1) {

      *puVar2 = 0;

      puVar2 = puVar2 + 1;

    }

    iVar1 = dialog_level_is_base_8();

    if (iVar1 != 0) {

      main_fx_004470b0(&DAT_0055a0f8);

    }

    DAT_0059eec0 = (uint)(iVar1 != 0);

    DAT_0055bdb0 = 3;

    DAT_0055bdb4 = 1;

    DAT_0059ee9c = 1;

    DAT_0059dcdc = 1;

    mission_004fe2d0(&DAT_00632900,*(undefined4 *)(*(int *)(DAT_00632918 + 0x558) + 4),0x3f000000,

                     0x3f000000,&DAT_00632abc,&DAT_00632ac0);

    DAT_00632abc = (float)DAT_00632924 * DAT_00632abc;

    DAT_00632ac0 = (float)DAT_00632928 * DAT_00632ac0;

    _DAT_00632ac4 = DAT_00632abc;

    _DAT_00632ac8 = DAT_00632ac0;

    return;

  }

  dialog_level_pop(&LAB_004889f0);

  return;

}

/* ===== FUN_004888f0 @ 0x004888F0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_004888f0(void)



{

  int iVar1;

  int *piVar2;

  int iVar3;

  undefined4 *puVar4;

  

  dialog_level_pop(&LAB_004889f0);

  FUN_0040d790();

  FUN_00497510(DAT_0059ee98);

  DAT_0059ee98 = 0;

  DAT_00632c0c = 0;

  iVar3 = 0;

  piVar2 = &DAT_0059dcd4;

  do {

    if (*piVar2 != 0) {

      main_menu_00483200(iVar3,0);

    }

    piVar2 = piVar2 + 3;

    iVar3 = iVar3 + 1;

    iVar1 = DAT_0059eec4;

  } while ((int)piVar2 < 0x59e184);

  for (; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x50)) {

    if (*(int *)(iVar1 + 0x48) != 0) {

      main_menu_00483200(0xffffffff,iVar1);

    }

  }

  mission_00447fd0(0,2);

  if (DAT_0059eec0 != 0) {

    main_fx_004471a0();

  }

  puVar4 = &DAT_00632aa0;

  for (iVar3 = 0x1f; iVar3 != 0; iVar3 = iVar3 + -1) {

    *puVar4 = 0;

    puVar4 = puVar4 + 1;

  }

  _DAT_00632ac4 = DAT_00632abc;

  _DAT_00632ac8 = DAT_00632ac0;

  menu_mission_launch();

  if (((DAT_0063315c == 0) && (DAT_00633160 == 0)) && (DAT_0063317c == 0)) {

    sound_play(0x659);

  }

  return;

}

/* ===== mission_load_world2 @ 0x00488A80 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void mission_load_world2(void)



{

  int iVar1;

  int iVar2;

  undefined4 *puVar3;

  int local_4;

  

  if (DAT_00633248 != 0) {

    dlog_push_level(&LAB_00488e60,FUN_004829d0);

    return;

  }

  local_4 = 0;

  mission_0051a0c0(s_MissionCheat_0055be64,&local_4);

  if (local_4 == 0) {

    if (DAT_00633380 == 0) {

      FUN_00488740();

      return;

    }

    iVar2 = 0;

    DAT_0059e28c = 0;

    iVar1 = DAT_00633380;

    if (DAT_00633380 != 0) {

      do {

        iVar1 = iVar1 >> 1;

        iVar2 = iVar2 + 1;

      } while (iVar1 != 0);

      DAT_0059e28c = iVar2;

      if (iVar2 != 0) {

        if (0x12 < iVar2) {

          DAT_0059e28c = 0x12;

        }

        dlog_push_level(&LAB_00488e60,FUN_004829d0);

        FUN_00426FA0();

        iVar1 = main_status_00500520(&DAT_00632900);

        if (iVar1 != 0) {

          DAT_0055bdb8 = 0x14;

          DAT_0063291c = 0x14;

          DAT_00632920 = 0xffffffff;

          DAT_00632924 = DAT_00632e84;

          DAT_00632928 = DAT_00632e88;

          if (DAT_0059ee98 != 0) {

            FUN_00497510(DAT_0059ee98);

          }

          DAT_0059ee98 = 0;

          DAT_0059ee98 = object_allocate_type(0x402,0x80000000);

          *(uint *)(DAT_0059ee98 + 0xd8) = *(uint *)(DAT_0059ee98 + 0xd8) | 0x40000000;

          camera_override_refpt(DAT_0059ee98,0);

          iVar1 = DAT_0059e28c + 1;

          DAT_00632c0c = 1;

          DAT_0059e8e0 = 0;

          DAT_0059ee9c = 0;

          _DAT_0059eea0 = 0;

          _DAT_0059eea8 = 0;

          _DAT_0059eea4 = DAT_0059e28c;

          DAT_0059eec4 = 0;

          _DAT_0059eec8 = (undefined1 *)0x0;

          _DAT_0059eecc = &LAB_004829c0;

          _DAT_0059eed0 = 0;

          puVar3 = &DAT_0059dcd0;

          for (iVar2 = 300; iVar2 != 0; iVar2 = iVar2 + -1) {

            *puVar3 = 0;

            puVar3 = puVar3 + 1;

          }

          iVar2 = dialog_level_is_base_8();

          if (iVar2 != 0) {

            main_fx_004470b0(&DAT_0055a0f8);

          }

          DAT_0059eec0 = (uint)(iVar2 != 0);

          DAT_0055bdb4 = 1;

          _DAT_0059eec8 = &LAB_004890a0;

          DAT_0059ee9c = 1;

          DAT_0055bdb0 = iVar1;

          mission_0051a0c0(s_LoadWorld_0055bfec,&DAT_0059ee9c);

          iVar1 = DAT_00632918;

          if ((DAT_0059ee9c < 1) || (DAT_0059e28c < DAT_0059ee9c)) {

            DAT_0059ee9c = 1;

          }

          iVar2 = DAT_0059ee9c;

          (&DAT_0059dcd0)[DAT_0059ee9c * 3] = 1;

          mission_004fe2d0(&DAT_00632900,*(undefined4 *)(*(int *)(iVar1 + 0x2d0) + iVar2 * 4),

                           0x3f000000,0x3f000000,&DAT_00632abc,&DAT_00632ac0);

          DAT_00632abc = (float)DAT_00632924 * DAT_00632abc;

          DAT_00632ac0 = (float)DAT_00632928 * DAT_00632ac0;

          _DAT_00632ac4 = DAT_00632abc;

          _DAT_00632ac8 = DAT_00632ac0;

          return;

        }

        dialog_level_pop(&LAB_00488e60);

        return;

      }

    }

    menu_keymap_screen();

    return;

  }

  mission_cheat_check();

  return;

}

/* ===== mission_load_world3 @ 0x00488D00 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void mission_load_world3(void)



{

  char cVar1;

  int iVar2;

  char *pcVar3;

  char *pcVar4;

  int *piVar5;

  int iVar6;

  undefined4 *puVar7;

  

  dialog_level_pop(&LAB_00488e60);

  FUN_0040d790();

  FUN_00497510(DAT_0059ee98);

  DAT_0059ee98 = 0;

  DAT_00632c0c = 0;

  iVar6 = 0;

  piVar5 = &DAT_0059dcd4;

  do {

    if (*piVar5 != 0) {

      main_menu_00483200(iVar6,0);

    }

    piVar5 = piVar5 + 3;

    iVar6 = iVar6 + 1;

    iVar2 = DAT_0059eec4;

  } while ((int)piVar5 < 0x59e184);

  for (; iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x50)) {

    if (*(int *)(iVar2 + 0x48) != 0) {

      main_menu_00483200(0xffffffff,iVar2);

    }

  }

  mission_00447fd0(0,2);

  if (DAT_0059eec0 != 0) {

    main_fx_004471a0();

  }

  puVar7 = &DAT_00632aa0;

  for (iVar6 = 0x1f; iVar6 != 0; iVar6 = iVar6 + -1) {

    *puVar7 = 0;

    puVar7 = puVar7 + 1;

  }

  _DAT_00632ac4 = DAT_00632abc;

  _DAT_00632ac8 = DAT_00632ac0;

  iVar6 = FUN_004B09C0(DAT_0059ee9c + -1);

  pcVar3 = *(char **)(iVar6 + 4);

  pcVar4 = &DAT_00633070;

  do {

    cVar1 = *pcVar3;

    pcVar3 = pcVar3 + 1;

    *pcVar4 = cVar1;

    pcVar4 = pcVar4 + 1;

  } while (cVar1 != '\0');

  DAT_00632d20 = DAT_0059ee9c + -1;

  if ((DAT_00633238 == 0) && (DAT_00633248 == 0)) {

    comm_0051a130(s_LoadWorld_0055bfec,DAT_0059ee9c);

  }

  mission_menu_load();

  if (((DAT_0063315c == 0) && (DAT_00633160 == 0)) && (DAT_0063317c == 0)) {

    sound_play(0x659);

  }

  return;

}

/* ===== mission_menu_load @ 0x00489120 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void mission_menu_load(void)



{

  int iVar1;

  int iVar2;

  int *piVar3;

  undefined4 *puVar4;

  code *pcVar5;

  

  iVar1 = FUN_004469e0();

  if (iVar1 == 0) {

    pcVar5 = FUN_00471dc0;

  }

  else {

    pcVar5 = FUN_004829d0;

  }

  dlog_push_level(mission_menu_load2,pcVar5);

  FUN_00426FA0();

  iVar1 = main_status_00500520(&DAT_00632900);

  if (iVar1 != 0) {

    DAT_0055bdb8 = 0x14;

    DAT_0063291c = 0x14;

    DAT_00632924 = DAT_00632e84;

    DAT_00632920 = 0xffffffff;

    DAT_00632928 = DAT_00632e88;

    if (DAT_0059ee98 != 0) {

      FUN_00497510(DAT_0059ee98);

    }

    DAT_0059ee98 = 0;

    DAT_0059ee98 = object_allocate_type(0x3fb,0x80000000);

    *(uint *)(DAT_0059ee98 + 0xd8) = *(uint *)(DAT_0059ee98 + 0xd8) | 0x40000000;

    iVar1 = FUN_004469e0();

    if (iVar1 != 0) {

      camera_override_refpt(DAT_0059ee98,0);

    }

    DAT_0059eae0 = texture_add_file(0);

    if ((DAT_0059eae0 == 0) || (DAT_006331f8 != 0)) {

      dialog_level_pop(mission_menu_load2);

      FUN_0040d790();

      FUN_00497510(DAT_0059ee98);

      DAT_0059ee98 = 0;

      DAT_00632c0c = 0;

      iVar1 = 0;

      piVar3 = &DAT_0059dcd4;

      do {

        if (*piVar3 != 0) {

          main_menu_00483200(iVar1,0);

        }

        piVar3 = piVar3 + 3;

        iVar1 = iVar1 + 1;

        iVar2 = DAT_0059eec4;

      } while ((int)piVar3 < 0x59e184);

      for (; iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x50)) {

        if (*(int *)(iVar2 + 0x48) != 0) {

          main_menu_00483200(0xffffffff,iVar2);

        }

      }

      mission_00447fd0(0,2);

      if (DAT_0059eec0 != 0) {

        main_fx_004471a0();

      }

      puVar4 = &DAT_00632aa0;

      for (iVar1 = 0x1f; iVar1 != 0; iVar1 = iVar1 + -1) {

        *puVar4 = 0;

        puVar4 = puVar4 + 1;

      }

      _DAT_00632ac4 = DAT_00632abc;

      _DAT_00632ac8 = DAT_00632ac0;

      if ((DAT_00633238 == 0) && (DAT_00633248 == 0)) {

        comm_0051a130(s_LoadMission_0055c12c,DAT_0059ee9c);

      }

      DAT_0059eeb0 = 0;

      FUN_00446620();

      (*DAT_005dd354)(DAT_0059eedc);

      DAT_0059eedc = 0;

      DAT_0059eee4 = 0;

      AudioSetSpeakerConfig__F14SPEAKER_SYSTEM_4(DAT_00632d20);

      mission_004576e0();

      FUN_00495990(0x6e6);

    }

    else if (DAT_0059eae0 < 2) {

      DAT_0059ee9c = 1;

      dialog_level_pop(mission_menu_load2);

      FUN_0040d790();

      FUN_00497510(DAT_0059ee98);

      DAT_0059ee98 = 0;

      DAT_00632c0c = 0;

      iVar1 = 0;

      piVar3 = &DAT_0059dcd4;

      do {

        if (*piVar3 != 0) {

          main_menu_00483200(iVar1,0);

        }

        piVar3 = piVar3 + 3;

        iVar1 = iVar1 + 1;

        iVar2 = DAT_0059eec4;

      } while ((int)piVar3 < 0x59e184);

      for (; iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x50)) {

        if (*(int *)(iVar2 + 0x48) != 0) {

          main_menu_00483200(0xffffffff,iVar2);

        }

      }

      mission_00447fd0(0,2);

      if (DAT_0059eec0 != 0) {

        main_fx_004471a0();

      }

      puVar4 = &DAT_00632aa0;

      for (iVar1 = 0x1f; iVar1 != 0; iVar1 = iVar1 + -1) {

        *puVar4 = 0;

        puVar4 = puVar4 + 1;

      }

      _DAT_00632ac4 = DAT_00632abc;

      _DAT_00632ac8 = DAT_00632ac0;

      if ((DAT_00633238 == 0) && (DAT_00633248 == 0)) {

        comm_0051a130(s_LoadMission_0055c12c,DAT_0059ee9c);

      }

      DAT_0059eeb0 = 0;

      FUN_00446620();

      (*DAT_005dd354)(DAT_0059eedc);

      DAT_0059eedc = 0;

      if ((DAT_00633238 == 0) && (DAT_00633248 == 0)) {

        comm_0051a130(s_LoadMission_0055c12c,DAT_0059ee9c);

      }

      DAT_006329d8 = DAT_0059ee9c + -1;

      DAT_0059eee4 = 1;

      AudioSetSpeakerConfig__F14SPEAKER_SYSTEM_4(DAT_00632d20);

      mission_004576e0();

      FUN_00495990(0x6e6);

    }

    iVar1 = DAT_0059eae0 + 1;

    DAT_00632c0c = 1;

    DAT_0059e8e0 = 0;

    DAT_0059ee9c = 0;

    _DAT_0059eea0 = 0;

    _DAT_0059eea8 = 0;

    DAT_0059eec4 = 0;

    _DAT_0059eec8 = (undefined1 *)0x0;

    _DAT_0059eecc = &LAB_004829c0;

    _DAT_0059eed0 = 0;

    puVar4 = &DAT_0059dcd0;

    _DAT_0059eea4 = DAT_0059eae0;

    for (iVar2 = 300; iVar2 != 0; iVar2 = iVar2 + -1) {

      *puVar4 = 0;

      puVar4 = puVar4 + 1;

    }

    iVar2 = dialog_level_is_base_8();

    if (iVar2 != 0) {

      main_fx_004470b0(&DAT_0055a0f8);

    }

    DAT_0059eec0 = (uint)(iVar2 != 0);

    DAT_0055bdb4 = 1;

    _DAT_0059eec8 = &LAB_00489c50;

    DAT_0059ee9c = 1;

    DAT_0055bdb0 = iVar1;

    mission_0051a0c0(s_LoadMission_0055c12c,&DAT_0059ee9c);

    iVar1 = DAT_00632918;

    iVar2 = DAT_0059eae0;

    if ((DAT_0059ee9c <= DAT_0059eae0) && (iVar2 = DAT_0059ee9c, DAT_0059ee9c == 0)) {

      iVar2 = 1;

    }

    DAT_0059ee9c = iVar2;

    iVar2 = DAT_0059ee9c;

    (&DAT_0059dcd0)[DAT_0059ee9c * 3] = 1;

    mission_004fe2d0(&DAT_00632900,*(undefined4 *)(*(int *)(iVar1 + 0x2d0) + iVar2 * 4),0x3f000000,

                     0x3f000000,&DAT_00632abc,&DAT_00632ac0);

    DAT_00632abc = (float)DAT_00632924 * DAT_00632abc;

    DAT_00632ac0 = (float)DAT_00632928 * DAT_00632ac0;

    _DAT_00632ac4 = DAT_00632abc;

    _DAT_00632ac8 = DAT_00632ac0;

    return;

  }

  dialog_level_pop(mission_menu_load2);

  return;

}

/* ===== texture_add_file @ 0x004895F0 ===== */
int texture_add_file(int *param_1)



{

  uint uVar1;

  int iVar2;

  uint uVar3;

  int iVar4;

  int iVar5;

  undefined *puVar6;

  undefined *puVar7;

  int local_130;

  int local_12c;

  uint local_128;

  int local_124;

  int local_120;

  undefined1 local_11c [20];

  undefined4 local_108;

  undefined1 local_100 [256];

  

  iVar5 = 0;

  if (param_1 != (int *)0x0) {

    *param_1 = 0;

  }

  FUN_00542f27(local_100,s_W__s_bin_0055c160,&DAT_00633070);

  iVar2 = main_005380e0(local_100);

  if (iVar2 == 0) {

    FUN_00542f27(&DAT_00657400,s_Failed_to_open__s_0055c14c,local_100);

    error_screen_show(&DAT_00657400);

    return 0;

  }

  FUN_005178d0(iVar2,&local_120,4);

  if ((((local_120 != 0x1a0002e1) && (local_120 != 0x1a0002e2)) && (local_120 != 0x1a0002e3)) &&

     (local_120 != 0x1a0002e5)) {

    FUN_00542f27(&DAT_00657400,s_Bad_version_for__s_0055c138,local_100);

    error_screen_show(&DAT_00657400);

    ANM_BinderDestroy_2(iVar2);

    return 0;

  }

  FUN_005178d0(iVar2,local_11c,0x1c);

  sceSifLoadElf(iVar2,local_108);

  FUN_005178d0(iVar2,&local_12c,4);

  if (param_1 != (int *)0x0) {

    *param_1 = local_12c;

  }

  local_124 = 0;

  mission_0051a0c0(s_MissionCheat_0055be64,&local_124);

  uVar3 = (&DAT_00633384)[DAT_00632d20];

  local_130 = 0;

  local_128 = uVar3;

  if (0 < local_12c) {

    puVar6 = &DAT_0059e620;

    puVar7 = &DAT_0059e888;

    iVar4 = local_124;

    do {

      if ((uVar3 != 0) || (iVar4 != 0)) {

        if ((int)puVar7 < 0x59e8d4) {

          FUN_005178d0(iVar2,puVar7,1);

          FUN_005178d0(iVar2,puVar6,0x20);

          uVar3 = local_128;

          iVar4 = local_124;

        }

        do {

          if (iVar4 != 0) break;

          uVar1 = uVar3 & 1;

          uVar3 = (int)uVar3 >> 1;

        } while (uVar1 == 0);

        local_130 = local_130 + 1;

        local_128 = uVar3;

      }

      iVar5 = iVar5 + 1;

      puVar7 = puVar7 + 4;

      puVar6 = puVar6 + 0x20;

    } while (iVar5 < local_12c);

  }

  ANM_BinderDestroy_2(iVar2);

  if (0x12 < local_130) {

    local_130 = 0x12;

  }

  if ((local_12c != 0) && (local_130 == 0)) {

    local_130 = 1;

  }

  return local_130;

}

/* ===== mission_menu_load2 @ 0x004897D0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void mission_menu_load2(void)



{

  int iVar1;

  undefined4 uVar2;

  int *piVar3;

  int iVar4;

  undefined4 *puVar5;

  

  FUN_004a5cd0();

  main_menu_004832f0();

  if (DAT_00632aa4._3_1_ != '\0') {

    dialog_level_pop(mission_menu_load2);

    FUN_0040d790();

    FUN_00497510(DAT_0059ee98);

    DAT_0059ee98 = 0;

    DAT_00632c0c = 0;

    iVar4 = 0;

    piVar3 = &DAT_0059dcd4;

    do {

      if (*piVar3 != 0) {

        main_menu_00483200(iVar4,0);

      }

      piVar3 = piVar3 + 3;

      iVar4 = iVar4 + 1;

      iVar1 = DAT_0059eec4;

    } while ((int)piVar3 < 0x59e184);

    for (; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x50)) {

      if (*(int *)(iVar1 + 0x48) != 0) {

        main_menu_00483200(0xffffffff,iVar1);

      }

    }

    mission_00447fd0(0,2);

    if (DAT_0059eec0 != 0) {

      main_fx_004471a0();

    }

    puVar5 = &DAT_00632aa0;

    for (iVar4 = 0x1f; iVar4 != 0; iVar4 = iVar4 + -1) {

      *puVar5 = 0;

      puVar5 = puVar5 + 1;

    }

    _DAT_00632ac4 = DAT_00632abc;

    _DAT_00632ac8 = DAT_00632ac0;

    menu_keymap_screen();

    if (DAT_0063315c != 0) {

      return;

    }

    if (DAT_00633160 != 0) {

      return;

    }

    if (DAT_0063317c != 0) {

      return;

    }

    sound_play(0x657);

    return;

  }

  if (DAT_00632aa0._1_1_ == '\0') {

    if (DAT_00632aa0._2_1_ == '\0') goto LAB_00489916;

    iVar4 = DAT_0059ee9c + 1;

  }

  else {

    iVar4 = DAT_0059ee9c + -1;

  }

  FUN_004834d0(iVar4,0,1,0);

LAB_00489916:

  FUN_00500120(&DAT_0063292c,DAT_00632924,DAT_00632928);

  iVar4 = FUN_004fff10(&DAT_00632900,DAT_0063291c,0xffffffff);

  if ((-1 < iVar4) && (FUN_004834d0(iVar4,1,1,0), DAT_00632aaa != '\0')) {

    dialog_level_pop(mission_menu_load2);

    FUN_0040d790();

    FUN_00497510(DAT_0059ee98);

    DAT_0059ee98 = 0;

    DAT_00632c0c = 0;

    iVar4 = 0;

    piVar3 = &DAT_0059dcd4;

    do {

      if (*piVar3 != 0) {

        main_menu_00483200(iVar4,0);

      }

      piVar3 = piVar3 + 3;

      iVar4 = iVar4 + 1;

      iVar1 = DAT_0059eec4;

    } while ((int)piVar3 < 0x59e184);

    for (; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x50)) {

      if (*(int *)(iVar1 + 0x48) != 0) {

        main_menu_00483200(0xffffffff,iVar1);

      }

    }

    mission_00447fd0(0,2);

    if (DAT_0059eec0 != 0) {

      main_fx_004471a0();

    }

    puVar5 = &DAT_00632aa0;

    for (iVar4 = 0x1f; iVar4 != 0; iVar4 = iVar4 + -1) {

      *puVar5 = 0;

      puVar5 = puVar5 + 1;

    }

    _DAT_00632ac4 = DAT_00632abc;

    _DAT_00632ac8 = DAT_00632ac0;

    if ((DAT_00633238 == 0) && (DAT_00633248 == 0)) {

      comm_0051a130(s_LoadMission_0055c12c,DAT_0059ee9c);

    }

    DAT_0059eeb0 = 0;

    FUN_00446620();

    (*DAT_005dd354)(DAT_0059eedc);

    DAT_0059eedc = 0;

    if ((DAT_00633238 == 0) && (DAT_00633248 == 0)) {

      comm_0051a130(s_LoadMission_0055c12c,DAT_0059ee9c);

    }

    DAT_006329d8 = DAT_0059ee9c + -1;

    DAT_0059eee4 = 1;

    AudioSetSpeakerConfig__F14SPEAKER_SYSTEM_4(DAT_00632d20);

    mission_004576e0();

    FUN_00495990(0x6e6);

  }

  if (DAT_00632aa8 == '\0') {

    uVar2 = FUN_00507b00(s_MH_MissionLoad_0055c16c);

    FUN_00542f27(&DAT_0059e8e0,&DAT_00555df0,uVar2);

    return;

  }

  dialog_level_pop(mission_menu_load2);

  FUN_0040d790();

  FUN_00497510(DAT_0059ee98);

  DAT_0059ee98 = 0;

  DAT_00632c0c = 0;

  iVar4 = 0;

  piVar3 = &DAT_0059dcd4;

  do {

    if (*piVar3 != 0) {

      main_menu_00483200(iVar4,0);

    }

    piVar3 = piVar3 + 3;

    iVar4 = iVar4 + 1;

    iVar1 = DAT_0059eec4;

  } while ((int)piVar3 < 0x59e184);

  for (; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x50)) {

    if (*(int *)(iVar1 + 0x48) != 0) {

      main_menu_00483200(0xffffffff,iVar1);

    }

  }

  mission_00447fd0(0,2);

  if (DAT_0059eec0 != 0) {

    main_fx_004471a0();

  }

  puVar5 = &DAT_00632aa0;

  for (iVar4 = 0x1f; iVar4 != 0; iVar4 = iVar4 + -1) {

    *puVar5 = 0;

    puVar5 = puVar5 + 1;

  }

  _DAT_00632ac4 = DAT_00632abc;

  _DAT_00632ac8 = DAT_00632ac0;

  if ((DAT_00633238 == 0) && (DAT_00633248 == 0)) {

    comm_0051a130(s_LoadMission_0055c12c,DAT_0059ee9c);

  }

  DAT_0059eeb0 = 0;

  FUN_00446620();

  (*DAT_005dd354)(DAT_0059eedc);

  DAT_0059eedc = 0;

  if ((DAT_00633238 == 0) && (DAT_00633248 == 0)) {

    comm_0051a130(s_LoadMission_0055c12c,DAT_0059ee9c);

  }

  DAT_006329d8 = DAT_0059ee9c + -1;

  DAT_0059eee4 = 1;

  AudioSetSpeakerConfig__F14SPEAKER_SYSTEM_4(DAT_00632d20);

  mission_004576e0();

  FUN_00495990(0x6e6);

  return;

}

/* ===== FUN_00489ca0 @ 0x00489CA0 ===== */
void FUN_00489ca0(void)



{

  int iVar1;

  int iVar2;

  int iVar3;

  

  if (DAT_0059eee4 != 0) {

    iVar3 = 0;

    iVar2 = 0;

    do {

      iVar1 = FUN_00545650(DAT_006329d8 * 0x118 + 0x2210 + DAT_006330e4,

                           iVar2 + 0x4558 + DAT_006330e4);

      if (iVar1 == 0) break;

      iVar2 = iVar2 + 0x30;

      iVar3 = iVar3 + 1;

    } while (iVar2 < 0x510);

    DAT_006329d8 = iVar3;

    FUN_00492150(DAT_00632d20,iVar3);

    FUN_00492430(DAT_00632d20,DAT_006329d8);

    scenerio_start_index__Fi(DAT_006329d8);

    FUN_00491d30(*(undefined4 *)(DAT_00632a88 + 4));

    DAT_0059eee4 = 0;

  }

  return;

}

/* ===== FUN_00489D40 @ 0x00489D40 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_00489D40(void)



{

  int iVar1;

  undefined4 *puVar2;

  code *pcVar3;

  

  iVar1 = FUN_004469e0();

  if (iVar1 == 0) {

    pcVar3 = FUN_00471dc0;

  }

  else {

    pcVar3 = FUN_004829d0;

  }

  dlog_push_level(&LAB_0048a140,pcVar3);

  FUN_00426FA0();

  iVar1 = main_status_00500520(&DAT_00632900);

  if (iVar1 != 0) {

    DAT_0055bdb8 = 0x1b;

    DAT_0063291c = 0x1b;

    DAT_00632924 = DAT_00632e84;

    DAT_00632920 = 0xffffffff;

    DAT_00632928 = DAT_00632e88;

    if (DAT_0059ee98 != 0) {

      FUN_00497510(DAT_0059ee98);

    }

    DAT_0059ee98 = 0;

    DAT_0059ee98 = object_allocate_type(0x3fb,0x80000000);

    *(uint *)(DAT_0059ee98 + 0xd8) = *(uint *)(DAT_0059ee98 + 0xd8) | 0x40000000;

    iVar1 = FUN_004469e0();

    if (iVar1 != 0) {

      camera_override_refpt(DAT_0059ee98,0);

    }

    DAT_00632c0c = 1;

    DAT_0059e8e0 = 0;

    DAT_0059ee9c = 0;

    _DAT_0059eea0 = 0;

    _DAT_0059eea8 = 0;

    _DAT_0059eea4 = 10;

    DAT_0059eec4 = 0;

    _DAT_0059eec8 = 0;

    _DAT_0059eecc = &LAB_004829c0;

    _DAT_0059eed0 = 0;

    puVar2 = &DAT_0059dcd0;

    for (iVar1 = 300; iVar1 != 0; iVar1 = iVar1 + -1) {

      *puVar2 = 0;

      puVar2 = puVar2 + 1;

    }

    iVar1 = dialog_level_is_base_8();

    if (iVar1 != 0) {

      main_fx_004470b0(&DAT_0055a0f8);

    }

    DAT_0059eec0 = (uint)(iVar1 != 0);

    DAT_0055bdb0 = 0xb;

    DAT_0055bdb4 = 1;

    DAT_0059ee9c = 10;

    DAT_0059dd48 = 1;

    iVar1 = FUN_004469e0();

    if (iVar1 == 0) {

      (*DAT_005dd288)();

      iVar1 = FUN_0052aa70();

      if (iVar1 == 0) {

        DAT_00632e40 = 1;

      }

      sound_play(0x6e6);

    }

    mission_004fe2d0(&DAT_00632900,

                     *(undefined4 *)(*(int *)(DAT_00632918 + 0x3cc) + 4 + DAT_0059ee9c * 4),

                     0x3f000000,0x3f000000,&DAT_00632abc,&DAT_00632ac0);

    DAT_00632abc = (float)DAT_00632924 * DAT_00632abc;

    DAT_00632ac0 = (float)DAT_00632928 * DAT_00632ac0;

    _DAT_00632ac4 = DAT_00632abc;

    _DAT_00632ac8 = DAT_00632ac0;

    return;

  }

  dialog_level_pop(&LAB_0048a140);

  return;

}

/* ===== FUN_00489F50 @ 0x00489F50 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_00489F50(void)



{

  int iVar1;

  int *piVar2;

  int iVar3;

  undefined4 *puVar4;

  

  dialog_level_pop(&LAB_0048a140);

  FUN_0040d790();

  FUN_00497510(DAT_0059ee98);

  DAT_0059ee98 = 0;

  DAT_00632c0c = 0;

  iVar3 = 0;

  piVar2 = &DAT_0059dcd4;

  do {

    if (*piVar2 != 0) {

      main_menu_00483200(iVar3,0);

    }

    piVar2 = piVar2 + 3;

    iVar3 = iVar3 + 1;

    iVar1 = DAT_0059eec4;

  } while ((int)piVar2 < 0x59e184);

  for (; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x50)) {

    if (*(int *)(iVar1 + 0x48) != 0) {

      main_menu_00483200(0xffffffff,iVar1);

    }

  }

  mission_00447fd0(0,2);

  if (DAT_0059eec0 != 0) {

    main_fx_004471a0();

  }

  puVar4 = &DAT_00632aa0;

  for (iVar3 = 0x1f; iVar3 != 0; iVar3 = iVar3 + -1) {

    *puVar4 = 0;

    puVar4 = puVar4 + 1;

  }

  _DAT_00632ac4 = DAT_00632abc;

  _DAT_00632ac8 = DAT_00632ac0;

  switch(DAT_0059ee9c) {

  case 1:

    if (DAT_00633104 == 0) {

      FUN_0048C830();

    }

    else {

      FUN_0048A7D0();

    }

    break;

  case 2:

    FUN_0048D4B0();

    break;

  case 3:

    FUN_00486FC0();

    break;

  case 4:

    FUN_004862E0();

    break;

  case 5:

    FUN_00487B70();

    break;

  case 6:

    if ((DAT_00632c00 == 0) && (_DAT_00632b60 < 0.0 != (_DAT_00632b60 == 0.0))) {

      DAT_0059eeb8 = 1;

      FUN_0048DE30();

    }

    break;

  case 7:

    FUN_0048E430();

    break;

  case 8:

    DAT_0059eeb8 = 0;

    FUN_0048DE30();

    break;

  case 9:

    DAT_0059eeb8 = 2;

    FUN_0048EA50();

    break;

  case 10:

    iVar3 = FUN_004469e0();

    if (iVar3 == 0) {

      (*DAT_005dd28c)();

      DAT_00632e40 = 0;

      FUN_00495990(0x6e6);

    }

    else {

      menu_mission_launch();

    }

  }

  if (((DAT_0063315c == 0) && (DAT_00633160 == 0)) && (DAT_0063317c == 0)) {

    sound_play(0x659);

  }

  return;

}

/* ===== FUN_0048A7D0 @ 0x0048A7D0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_0048A7D0(void)



{

  int iVar1;

  undefined4 *puVar2;

  int iVar3;

  int iVar4;

  int *piVar5;

  int *piVar6;

  bool bVar7;

  code *pcVar8;

  

  iVar1 = FUN_004469e0();

  if (iVar1 == 0) {

    pcVar8 = FUN_00471dc0;

  }

  else {

    pcVar8 = FUN_004829d0;

  }

  dlog_push_level(&LAB_0048b7b0,pcVar8);

  FUN_00426FA0();

  iVar1 = main_status_00500520(&DAT_00632900);

  if (iVar1 == 0) {

    dialog_level_pop(&LAB_0048b7b0);

    return;

  }

  DAT_0055bdb8 = 0x23;

  DAT_0063291c = 0x23;

  DAT_00632924 = DAT_00632e84;

  DAT_00632920 = 0xffffffff;

  DAT_00632928 = DAT_00632e88;

  if (DAT_0059ee98 != 0) {

    FUN_00497510(DAT_0059ee98);

  }

  DAT_0059ee98 = 0;

  DAT_0059ee98 = object_allocate_type(0x402,0x80000000);

  *(uint *)(DAT_0059ee98 + 0xd8) = *(uint *)(DAT_0059ee98 + 0xd8) | 0x40000000;

  iVar1 = FUN_004469e0();

  if (iVar1 != 0) {

    camera_override_refpt(DAT_0059ee98,0);

  }

  DAT_00632c0c = 1;

  DAT_0059e8e0 = 0;

  DAT_0059ee9c = 0;

  _DAT_0059eea0 = 0;

  _DAT_0059eea8 = 0;

  _DAT_0059eea4 = 0x1f;

  DAT_0059eec4 = 0;

  _DAT_0059eec8 = 0;

  _DAT_0059eecc = &LAB_004829c0;

  _DAT_0059eed0 = 0;

  puVar2 = &DAT_0059dcd0;

  for (iVar1 = 300; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar2 = 0;

    puVar2 = puVar2 + 1;

  }

  iVar1 = dialog_level_is_base_8();

  if (iVar1 != 0) {

    main_fx_004470b0(&DAT_0055a0f8);

  }

  DAT_0059eec0 = (uint)(iVar1 != 0);

  DAT_0055bdb0 = 0x20;

  DAT_0055bdb4 = 0;

  DAT_0059ee9c = 0xb;

  DAT_0059dd54 = 1;

  DAT_0059eef0 = (**(code **)(DAT_00656420 + 0x70))(DAT_00656420,&DAT_0059eee8);

  DAT_0059eef4 = (**(code **)(DAT_00656420 + 0x78))

                           (DAT_00656420,&DAT_0059eeec,&DAT_005ddb5c,&DAT_005ddb6c);

  DAT_0059eef8 = 0;

  if (0 < DAT_0059eef0) {

    puVar2 = (undefined4 *)(DAT_0059eee8 + 0xc);

    do {

      iVar1 = 4;

      bVar7 = true;

      piVar5 = &DAT_005ddb5c;

      piVar6 = (int *)puVar2[-1];

      do {

        if (iVar1 == 0) break;

        iVar1 = iVar1 + -1;

        bVar7 = *piVar5 == *piVar6;

        piVar5 = piVar5 + 1;

        piVar6 = piVar6 + 1;

      } while (bVar7);

      if (bVar7) {

        iVar1 = 4;

        bVar7 = true;

        piVar5 = &DAT_005ddb6c;

        piVar6 = (int *)*puVar2;

        do {

          if (iVar1 == 0) break;

          iVar1 = iVar1 + -1;

          bVar7 = *piVar5 == *piVar6;

          piVar5 = piVar5 + 1;

          piVar6 = piVar6 + 1;

        } while (bVar7);

        if (bVar7) goto LAB_0048a9bd;

      }

      DAT_0059eef8 = DAT_0059eef8 + 1;

      puVar2 = puVar2 + 4;

    } while (DAT_0059eef8 < DAT_0059eef0);

  }

  DAT_0059eef8 = -1;

LAB_0048a9bd:

  iVar1 = (**(code **)(DAT_00656420 + 0xc4))(DAT_00656420,2);

  iVar3 = (**(code **)(DAT_00656420 + 0xc4))(DAT_00656420,1);

  iVar4 = (**(code **)(DAT_00656420 + 0xc4))(DAT_00656420,5);

  DAT_0059eefc = 0;

  if (0 < DAT_0059eef4) {

    piVar5 = (int *)(DAT_0059eeec + 8);

    do {

      if (((piVar5[-2] == iVar3) && (piVar5[-1] == iVar1)) && (*piVar5 == iVar4)) goto LAB_0048aa28;

      DAT_0059eefc = DAT_0059eefc + 1;

      piVar5 = piVar5 + 3;

    } while (DAT_0059eefc < DAT_0059eef4);

  }

  DAT_0059eefc = 0;

LAB_0048aa28:

  if (DAT_0059eef4 < 8) {

    DAT_0059ef00 = (7 - DAT_0059eef4) / 2;

  }

  else if (DAT_0059eefc < 3) {

    DAT_0059ef00 = 0;

  }

  else if (DAT_0059eefc < DAT_0059eef4 + -3) {

    DAT_0059ef00 = DAT_0059eefc + -3;

  }

  else {

    DAT_0059ef00 = DAT_0059eef4 + -7;

  }

  if (DAT_0059eef0 < 8) {

    DAT_0059ef04 = (7 - DAT_0059eef0) / 2;

  }

  else if (DAT_0059eef8 < 3) {

    DAT_0059ef04 = 0;

  }

  else if (DAT_0059eef8 < DAT_0059eef0 + -3) {

    DAT_0059ef04 = DAT_0059eef8 + -3;

  }

  else {

    DAT_0059ef04 = DAT_0059eef4 + -7;

  }

  mission_004fe2d0(&DAT_00632900,*(undefined4 *)(*(int *)(DAT_00632918 + 0x4ec) + DAT_0059ee9c * 4),

                   0x3f000000,0x3f000000,&DAT_00632abc,&DAT_00632ac0);

  DAT_00632abc = (float)DAT_00632924 * DAT_00632abc;

  DAT_00632ac0 = (float)DAT_00632928 * DAT_00632ac0;

  _DAT_00632ac4 = DAT_00632abc;

  _DAT_00632ac8 = DAT_00632ac0;

  return;

}

/* ===== FUN_0048ab30 @ 0x0048AB30 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_0048ab30(void)



{

  int iVar1;

  int iVar2;

  int iVar3;

  undefined4 *puVar4;

  int iVar5;

  int *piVar6;

  int *piVar7;

  bool bVar8;

  

  iVar1 = DAT_0059eefc;

  iVar5 = DAT_0059eef8;

  iVar2 = DAT_0059eef4;

  iVar3 = DAT_0059eef0;

  if (DAT_0059ee9c < 0xc) {

    if (DAT_0059eef0 < 8) {

      iVar2 = (7 - DAT_0059eef0) / 2;

    }

    else if (DAT_0059eef8 < 3) {

      iVar2 = 0;

    }

    else if (DAT_0059eef8 < DAT_0059eef0 + -3) {

      iVar2 = DAT_0059eef8 + -3;

    }

    else {

      iVar2 = DAT_0059eef4 + -7;

    }

    DAT_0059ef04 = iVar2;

    (&DAT_0059dcd0)[DAT_0059ee9c * 3] = 0;

    if (iVar3 < 8) {

      DAT_0059ee9c = iVar5 + 0xc + iVar2;

      (&DAT_0059dcd0)[DAT_0059ee9c * 3] = 1;

      goto LAB_0048ad0f;

    }

    DAT_0059ee9c = (iVar5 - iVar2) + 0xc;

  }

  else {

    if (0x12 < DAT_0059ee9c) {

      iVar2 = 0;

      (&DAT_0059dcd0)[DAT_0059ee9c * 3] = 0;

      if (iVar3 < 1) {

LAB_0048acf3:

        DAT_0059ee9c = 10;

      }

      else {

        puVar4 = (undefined4 *)(DAT_0059eee8 + 0xc);

        do {

          iVar5 = 4;

          bVar8 = true;

          piVar6 = &DAT_005ddb5c;

          piVar7 = (int *)puVar4[-1];

          do {

            if (iVar5 == 0) break;

            iVar5 = iVar5 + -1;

            bVar8 = *piVar6 == *piVar7;

            piVar6 = piVar6 + 1;

            piVar7 = piVar7 + 1;

          } while (bVar8);

          if (bVar8) {

            iVar5 = 4;

            bVar8 = true;

            piVar6 = &DAT_005ddb6c;

            piVar7 = (int *)*puVar4;

            do {

              if (iVar5 == 0) break;

              iVar5 = iVar5 + -1;

              bVar8 = *piVar6 == *piVar7;

              piVar6 = piVar6 + 1;

              piVar7 = piVar7 + 1;

            } while (bVar8);

            if (bVar8) {

              if ((iVar2 < 0) || (iVar2 != DAT_0059eef8)) goto LAB_0048acf3;

              iVar3 = (**(code **)(DAT_00656420 + 0xc4))(DAT_00656420,1);

              iVar2 = (**(code **)(DAT_00656420 + 0xc4))(DAT_00656420,2);

              iVar5 = (**(code **)(DAT_00656420 + 0xc4))(DAT_00656420,5);

              piVar6 = (int *)(DAT_0059eeec + DAT_0059eefc * 0xc);

              if ((iVar3 != *piVar6) || ((iVar2 != piVar6[1] || (iVar5 != piVar6[2]))))

              goto LAB_0048acf3;

              DAT_0059ee9c = 0xb;

              goto LAB_0048acff;

            }

          }

          iVar2 = iVar2 + 1;

          puVar4 = puVar4 + 4;

        } while (iVar2 < iVar3);

        DAT_0059ee9c = 10;

      }

LAB_0048acff:

      (&DAT_0059dcd0)[DAT_0059ee9c * 3] = 1;

      goto LAB_0048ad0f;

    }

    if (DAT_0059eef4 < 8) {

      iVar3 = (7 - DAT_0059eef4) / 2;

    }

    else if (DAT_0059eefc < 3) {

      iVar3 = 0;

    }

    else {

      iVar3 = DAT_0059eef4 + -7;

      if (DAT_0059eefc < DAT_0059eef4 + -3) {

        iVar3 = DAT_0059eefc + -3;

      }

    }

    DAT_0059ef00 = iVar3;

    (&DAT_0059dcd0)[DAT_0059ee9c * 3] = 0;

    if (iVar2 < 8) {

      DAT_0059ee9c = iVar1 + 0x13 + iVar3;

      (&DAT_0059dcd0)[DAT_0059ee9c * 3] = 1;

      goto LAB_0048ad0f;

    }

    DAT_0059ee9c = (iVar1 - iVar3) + 0x13;

  }

  (&DAT_0059dcd0)[DAT_0059ee9c * 3] = 1;

LAB_0048ad0f:

  mission_004fe2d0(&DAT_00632900,

                   *(undefined4 *)

                    (*(int *)(DAT_00632918 + DAT_0063291c * 0x24) + 0x10 + DAT_0059ee9c * 4),

                   0x3f000000,0x3f000000,&DAT_00632abc,&DAT_00632ac0);

  DAT_00632abc = (float)DAT_00632924 * DAT_00632abc;

  DAT_00632ac0 = (float)DAT_00632928 * DAT_00632ac0;

  _DAT_00632ac4 = DAT_00632abc;

  _DAT_00632ac8 = DAT_00632ac0;

  if (((DAT_0063315c == 0) && (DAT_00633160 == 0)) && (DAT_0063317c == 0)) {

    sound_play(0x65a);

  }

  return;

}

/* ===== mission_state_dispatch @ 0x0048ADB0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void mission_state_dispatch(int param_1)



{

  undefined4 *puVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int *piVar5;

  int *piVar6;

  bool bVar7;

  

  switch(param_1) {

  case 9:

    iVar3 = DAT_0059eef8 * 0x10 + DAT_0059eee8;

    DAT_006331c8 = 0;

    DAT_006331cc = 0;

    DAT_006331d0 = 0;

    puVar1 = *(undefined4 **)(iVar3 + 8);

    DAT_006331d8 = *puVar1;

    DAT_006331dc = puVar1[1];

    _DAT_006331e0 = puVar1[2];

    _DAT_006331e4 = puVar1[3];

    puVar1 = *(undefined4 **)(iVar3 + 0xc);

    DAT_006331e8 = *puVar1;

    DAT_006331ec = puVar1[1];

    _DAT_006331f0 = puVar1[2];

    _DAT_006331f4 = puVar1[3];

    options_menu_apply(DAT_006331d4);

    iVar4 = DAT_0063291c;

    iVar3 = DAT_00632918;

    (&DAT_0059dcd0)[DAT_0059ee9c * 3] = 0;

    DAT_0059ee9c = 0xb;

    DAT_0059dd54 = 1;

    mission_004fe2d0(&DAT_00632900,*(undefined4 *)(*(int *)(iVar3 + iVar4 * 0x24) + 0x3c),0x3f000000

                     ,0x3f000000,&DAT_00632abc,&DAT_00632ac0);

    DAT_00632abc = (float)DAT_00632924 * DAT_00632abc;

    DAT_00632ac0 = (float)DAT_00632928 * DAT_00632ac0;

    _DAT_00632ac4 = DAT_00632abc;

    _DAT_00632ac8 = DAT_00632ac0;

    if (((DAT_0063315c == 0) && (DAT_00633160 == 0)) && (DAT_0063317c == 0)) {

      sound_play();

      return;

    }

    break;

  case 10:

    iVar3 = 0;

    if (0 < DAT_0059eef0) {

      puVar1 = (undefined4 *)(DAT_0059eee8 + 0xc);

      do {

        iVar4 = 4;

        bVar7 = true;

        piVar5 = &DAT_005ddb5c;

        piVar6 = (int *)puVar1[-1];

        do {

          if (iVar4 == 0) break;

          iVar4 = iVar4 + -1;

          bVar7 = *piVar5 == *piVar6;

          piVar5 = piVar5 + 1;

          piVar6 = piVar6 + 1;

        } while (bVar7);

        if (bVar7) {

          iVar4 = 4;

          bVar7 = true;

          piVar5 = &DAT_005ddb6c;

          piVar6 = (int *)*puVar1;

          do {

            if (iVar4 == 0) break;

            iVar4 = iVar4 + -1;

            bVar7 = *piVar5 == *piVar6;

            piVar5 = piVar5 + 1;

            piVar6 = piVar6 + 1;

          } while (bVar7);

          if (bVar7) {

            if ((-1 < iVar3) && (iVar3 == DAT_0059eef8)) {

              iVar3 = (**(code **)(DAT_00656420 + 0xc4))(DAT_00656420,1);

              iVar4 = (**(code **)(DAT_00656420 + 0xc4))(DAT_00656420,2);

              iVar2 = (**(code **)(DAT_00656420 + 0xc4))(DAT_00656420,5);

              piVar5 = (int *)(DAT_0059eeec + DAT_0059eefc * 0xc);

              if ((iVar3 == *piVar5) && ((iVar4 == piVar5[1] && (iVar2 == piVar5[2]))))

              goto LAB_0048b04f;

            }

            break;

          }

        }

        iVar3 = iVar3 + 1;

        puVar1 = puVar1 + 4;

      } while (iVar3 < DAT_0059eef0);

    }

    DAT_006331c8 = *(undefined4 *)(DAT_0059eeec + DAT_0059eefc * 0xc);

    iVar3 = DAT_0059eeec + DAT_0059eefc * 0xc;

    DAT_006331cc = *(undefined4 *)(iVar3 + 4);

    DAT_006331d0 = *(undefined4 *)(iVar3 + 8);

    puVar1 = *(undefined4 **)(DAT_0059eef8 * 0x10 + 8 + DAT_0059eee8);

    DAT_006331d8 = *puVar1;

    DAT_006331dc = puVar1[1];

    _DAT_006331e0 = puVar1[2];

    _DAT_006331e4 = puVar1[3];

    puVar1 = *(undefined4 **)(DAT_0059eef8 * 0x10 + DAT_0059eee8 + 0xc);

    DAT_006331e8 = *puVar1;

    DAT_006331ec = puVar1[1];

    _DAT_006331f0 = puVar1[2];

    _DAT_006331f4 = puVar1[3];

    options_menu_apply(DAT_006331d4);

LAB_0048b04f:

    iVar4 = DAT_0063291c;

    iVar3 = DAT_00632918;

    (&DAT_0059dcd0)[DAT_0059ee9c * 3] = 0;

    DAT_0059ee9c = 0xb;

    DAT_0059dd54 = 1;

    mission_004fe2d0(&DAT_00632900,*(undefined4 *)(*(int *)(iVar3 + iVar4 * 0x24) + 0x3c),0x3f000000

                     ,0x3f000000,&DAT_00632abc,&DAT_00632ac0);

    DAT_00632abc = (float)DAT_00632924 * DAT_00632abc;

    DAT_00632ac0 = (float)DAT_00632928 * DAT_00632ac0;

    _DAT_00632ac4 = DAT_00632abc;

    _DAT_00632ac8 = DAT_00632ac0;

    if (((DAT_0063315c == 0) && (DAT_00633160 == 0)) && (DAT_0063317c == 0)) {

      sound_play();

      return;

    }

    break;

  case 0xb:

    dialog_level_pop(&LAB_0048b7b0);

    FUN_0040d790();

    FUN_00497510(DAT_0059ee98);

    DAT_0059ee98 = 0;

    DAT_00632c0c = 0;

    iVar3 = 0;

    piVar5 = &DAT_0059dcd4;

    do {

      if (*piVar5 != 0) {

        main_menu_00483200(iVar3,0);

      }

      piVar5 = piVar5 + 3;

      iVar3 = iVar3 + 1;

      iVar4 = DAT_0059eec4;

    } while ((int)piVar5 < 0x59e184);

    for (; iVar4 != 0; iVar4 = *(int *)(iVar4 + 0x50)) {

      if (*(int *)(iVar4 + 0x48) != 0) {

        main_menu_00483200(0xffffffff,iVar4);

      }

    }

    mission_00447fd0(0,2);

    if (DAT_0059eec0 != 0) {

      main_fx_004471a0();

    }

    puVar1 = &DAT_00632aa0;

    for (iVar3 = 0x1f; iVar3 != 0; iVar3 = iVar3 + -1) {

      *puVar1 = 0;

      puVar1 = puVar1 + 1;

    }

    _DAT_00632ac4 = DAT_00632abc;

    _DAT_00632ac8 = DAT_00632ac0;

    (**(code **)(DAT_00656420 + 0x7c))(DAT_00656420,DAT_0059eeec);

    (**(code **)(DAT_00656420 + 0x74))(DAT_00656420,DAT_0059eee8);

    DAT_0059eef0 = 0;

    DAT_0059eef4 = 0;

    if (DAT_00633104 == 0) {

      FUN_0048C830();

    }

    else {

      FUN_00489D40();

    }

    if (((DAT_0063315c == 0) && (DAT_00633160 == 0)) && (DAT_0063317c == 0)) {

      sound_play();

      return;

    }

    break;

  case 0x1a:

    if (DAT_0059eef0 < 8) {

      return;

    }

    if ((DAT_0059ee9c < 0xc) || (0x12 < DAT_0059ee9c)) {

      if (DAT_0059ef04 < DAT_0059eef0 + -7) {

        DAT_0059ef04 = DAT_0059ef04 + 1;

      }

    }

    else if (DAT_0059ef04 < DAT_0059eef0 + -7) {

      DAT_0059ef04 = DAT_0059ef04 + 1;

      main_menu_00483200(DAT_0059ee9c,0);

      iVar3 = DAT_0059ee9c;

      if (DAT_0059ee9c != 0xc) {

        iVar3 = DAT_0059ee9c + -1;

        (&DAT_0059dcd0)[DAT_0059ee9c * 3] = 0;

        DAT_0059ee9c = iVar3;

        (&DAT_0059dcd0)[iVar3 * 3] = 1;

      }

      if (DAT_0059eef0 < 8) {

        DAT_0059eef8 = (iVar3 - DAT_0059ef04) + -0xc;

      }

      else {

        DAT_0059eef8 = DAT_0059ef04 + -0xc + iVar3;

      }

    }

    goto LAB_0048b72c;

  case 0x1b:

    if (7 < DAT_0059eef0) {

      if ((0xb < DAT_0059ee9c) && (DAT_0059ee9c < 0x13)) {

        FUN_00500100(&DAT_00632900,DAT_0063291c,param_1 + 4);

        DAT_0059ef04 = __ftol();

        main_menu_00483200(DAT_0059ee9c,0);

        if (DAT_0059eef0 < 8) {

          DAT_0059eef8 = (DAT_0059ee9c - DAT_0059ef04) + -0xc;

          return;

        }

        DAT_0059eef8 = DAT_0059ef04 + -0xc + DAT_0059ee9c;

        return;

      }

      FUN_00500100(&DAT_00632900,DAT_0063291c,param_1 + 4);

      DAT_0059ef04 = __ftol();

      return;

    }

    break;

  case 0x1c:

    if (7 < DAT_0059eef0) {

      if ((DAT_0059ee9c < 0xc) || (0x12 < DAT_0059ee9c)) {

        if (0 < DAT_0059ef04) {

          DAT_0059ef04 = DAT_0059ef04 + -1;

        }

      }

      else if (0 < DAT_0059ef04) {

        DAT_0059ef04 = DAT_0059ef04 + -1;

        main_menu_00483200(DAT_0059ee9c,0);

        iVar3 = DAT_0059ee9c;

        if (DAT_0059ee9c != 0x12) {

          iVar3 = DAT_0059ee9c + 1;

          (&DAT_0059dcd0)[DAT_0059ee9c * 3] = 0;

          DAT_0059ee9c = iVar3;

          (&DAT_0059dcd0)[iVar3 * 3] = 1;

        }

        if (DAT_0059eef0 < 8) {

          DAT_0059eef8 = (iVar3 - DAT_0059ef04) + -0xc;

        }

        else {

          DAT_0059eef8 = DAT_0059ef04 + -0xc + iVar3;

        }

      }

      if (((DAT_0063315c == 0) && (DAT_00633160 == 0)) && (DAT_0063317c == 0)) {

        sound_play();

        return;

      }

    }

    break;

  case 0x1d:

    if (DAT_0059eef4 < 8) {

      return;

    }

    if ((DAT_0059ee9c < 0x13) || (0x19 < DAT_0059ee9c)) {

      if (DAT_0059ef00 < DAT_0059eef4 + -7) {

        DAT_0059ef00 = DAT_0059ef00 + 1;

      }

    }

    else if (DAT_0059ef00 < DAT_0059eef4 + -7) {

      DAT_0059ef00 = DAT_0059ef00 + 1;

      main_menu_00483200(DAT_0059ee9c,0);

      iVar3 = DAT_0059ee9c;

      if (DAT_0059ee9c != 0x13) {

        iVar3 = DAT_0059ee9c + -1;

LAB_0048b372:

        (&DAT_0059dcd0)[DAT_0059ee9c * 3] = 0;

        DAT_0059ee9c = iVar3;

        (&DAT_0059dcd0)[iVar3 * 3] = 1;

      }

LAB_0048b390:

      if (DAT_0059eef4 < 8) {

        DAT_0059eefc = (iVar3 - DAT_0059ef00) + -0x13;

      }

      else {

        DAT_0059eefc = DAT_0059ef00 + -0x13 + iVar3;

      }

    }

    goto LAB_0048b72c;

  case 0x1e:

    if (7 < DAT_0059eef4) {

      if ((DAT_0059ee9c < 0x13) || (0x19 < DAT_0059ee9c)) {

        FUN_00500100(&DAT_00632900,DAT_0063291c,param_1 + 4);

        DAT_0059ef00 = __ftol();

        return;

      }

      FUN_00500100(&DAT_00632900,DAT_0063291c,param_1 + 4);

      DAT_0059ef00 = __ftol();

      main_menu_00483200(DAT_0059ee9c,0);

      if (7 < DAT_0059eef4) {

        DAT_0059eefc = DAT_0059ef00 + -0x13 + DAT_0059ee9c;

        return;

      }

      DAT_0059eefc = (DAT_0059ee9c - DAT_0059ef00) + -0x13;

    }

    break;

  case 0x1f:

    if (DAT_0059eef4 < 8) {

      return;

    }

    if ((DAT_0059ee9c < 0x13) || (0x19 < DAT_0059ee9c)) {

      if (0 < DAT_0059ef00) {

        DAT_0059ef00 = DAT_0059ef00 + -1;

      }

    }

    else if (0 < DAT_0059ef00) {

      DAT_0059ef00 = DAT_0059ef00 + -1;

      main_menu_00483200(DAT_0059ee9c,0);

      iVar3 = DAT_0059ee9c;

      if (DAT_0059ee9c != 0x17) {

        iVar3 = DAT_0059ee9c + 1;

        goto LAB_0048b372;

      }

      goto LAB_0048b390;

    }

LAB_0048b72c:

    if (((DAT_0063315c == 0) && (DAT_00633160 == 0)) && (DAT_0063317c == 0)) {

      sound_play();

      return;

    }

  }

  return;

}

/* ===== FUN_0048bed0 @ 0x0048BED0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_0048bed0(undefined4 param_1,int param_2,int param_3)



{

  param_3 = DAT_0059ee9c + param_3;

  (&DAT_0059dcd0)[DAT_0059ee9c * 3] = 0;

  if (param_3 < 0xc) {

    if (param_3 < 9) {

      param_3 = 0xb;

    }

  }

  else {

    param_3 = 9;

  }

  DAT_0059ee9c = param_3;

  (&DAT_0059dcd0)[param_3 * 3] = 1;

  if (param_2 == 0) {

    mission_004fe2d0(&DAT_00632900,

                     *(undefined4 *)

                      (*(int *)(DAT_00632918 + DAT_0063291c * 0x24) + 0x10 + param_3 * 4),0x3f000000

                     ,0x3f000000,&DAT_00632abc,&DAT_00632ac0);

    DAT_00632abc = (float)DAT_00632924 * DAT_00632abc;

    DAT_00632ac0 = (float)DAT_00632928 * DAT_00632ac0;

    _DAT_00632ac4 = DAT_00632abc;

    _DAT_00632ac8 = DAT_00632ac0;

  }

  if (((DAT_0063315c == 0) && (DAT_00633160 == 0)) && (DAT_0063317c == 0)) {

    sound_play(0x65a);

  }

  return;

}

/* ===== FUN_0048bfb0 @ 0x0048BFB0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_0048bfb0(int param_1,int param_2,int param_3)



{

  bool bVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  int *piVar8;

  bool bVar9;

  undefined4 uVar10;

  

  iVar3 = DAT_0059ef04;

  iVar5 = DAT_0059ef00;

  iVar7 = DAT_0059eef4;

  iVar6 = DAT_0059eef0;

  iVar2 = DAT_0059ee9c;

  bVar1 = true;

  if ((param_2 != 0) &&

     ((((0x12 < DAT_0059ee9c && (DAT_0059ee9c < 0x1a)) ||

       ((0xb < DAT_0059ee9c && (DAT_0059ee9c < 0x13)))) &&

      ((DAT_0055bdb4 <= param_1 + param_3 && (param_1 + param_3 <= DAT_0055bdb0 + -1)))))) {

    return;

  }

  DAT_0059ee9c = param_1;

  if ((((param_2 == 0) && (DAT_0055bdb0 <= param_1 + param_3)) &&

      ((param_1 < 0x13 || (0x19 < param_1)))) && ((param_1 < 0xc || (0x12 < param_1)))) {

    DAT_0059ee9c = DAT_0055bdb4;

    param_3 = 0;

  }

  if ((((0x12 < DAT_0059ee9c) && (DAT_0059ee9c < 0x1a)) ||

      ((0xb < DAT_0059ee9c && (DAT_0059ee9c < 0x13)))) && (param_2 == 0)) {

    if (((DAT_0059ee9c == 0xc) || (DAT_0059ee9c == 0x13)) && (param_3 < 0)) {

      if (DAT_0059ee9c == 0xc) {

        uVar10 = 0x1c;

      }

      else {

        uVar10 = 0x1f;

      }

    }

    else {

      if (((DAT_0059ee9c != 0x12) && (DAT_0059ee9c != 0x19)) || (param_3 < 1)) {

        DAT_0059ee9c = DAT_0059ee9c + param_3;

        if ((DAT_0059ee9c < 0x13) || (0x19 < DAT_0059ee9c)) {

          if ((DAT_0059eef0 < 8) &&

             ((DAT_0059ef04 + 0xc + DAT_0059eef0 <= DAT_0059ee9c ||

              (DAT_0059ee9c < DAT_0059ef04 + 0xc)))) {

            DAT_0059ee9c = iVar2;

            return;

          }

        }

        else if ((DAT_0059eef4 < 8) &&

                ((DAT_0059ef00 + 0x13 + DAT_0059eef4 <= DAT_0059ee9c ||

                 (DAT_0059ee9c < DAT_0059ef00 + 0x13)))) {

          DAT_0059ee9c = iVar2;

          return;

        }

        goto LAB_0048c241;

      }

      if (DAT_0059ee9c == 0x12) {

        uVar10 = 0x1a;

      }

      else {

        uVar10 = 0x1d;

      }

    }

    mission_state_dispatch(uVar10);

    bVar1 = false;

    iVar4 = DAT_0059ee9c;

    iVar5 = DAT_0059ef00;

    iVar7 = DAT_0059eef4;

    iVar3 = DAT_0059ef04;

    iVar6 = DAT_0059eef0;

    goto LAB_0048c25e;

  }

  DAT_0059ee9c = DAT_0059ee9c + param_3;

  if (((DAT_0059ee9c < 0x13) || (0x19 < DAT_0059ee9c)) &&

     ((DAT_0059ee9c < 0xc || (0x12 < DAT_0059ee9c)))) {

LAB_0048c209:

    if (DAT_0059ee9c < DAT_0055bdb4) {

      DAT_0059ee9c = iVar2;

      if (param_2 == 0) {

        DAT_0059ee9c = DAT_0055bdb0 + -1;

      }

    }

    else if ((DAT_0055bdb0 + -1 < DAT_0059ee9c) && (DAT_0059ee9c = iVar2, param_2 == 0)) {

      DAT_0059ee9c = DAT_0055bdb4;

    }

  }

  else if ((DAT_0059ee9c < 0x13) || (0x19 < DAT_0059ee9c)) {

    if ((DAT_0059eef0 < 8) &&

       ((DAT_0059ef04 + 0xc + DAT_0059eef0 <= DAT_0059ee9c || (DAT_0059ee9c <= DAT_0059ef04 + 0xb)))

       ) {

      DAT_0059ee9c = iVar2;

      return;

    }

    if (((param_2 == 0) || (iVar2 < 0xc)) || (0x12 < iVar2)) goto LAB_0048c209;

  }

  else {

    if ((DAT_0059eef4 < 8) &&

       ((DAT_0059ef00 + 0x13 + DAT_0059eef4 <= DAT_0059ee9c || (DAT_0059ee9c <= DAT_0059ef00 + 0x12)

        ))) {

      DAT_0059ee9c = iVar2;

      return;

    }

    if (((param_2 == 0) || (iVar2 < 0x13)) || (0x19 < iVar2)) goto LAB_0048c209;

  }

LAB_0048c241:

  iVar4 = DAT_0059ee9c;

  (&DAT_0059dcd0)[iVar2 * 3] = 0;

  (&DAT_0059dcd0)[iVar4 * 3] = 1;

LAB_0048c25e:

  if (((0x12 < iVar4) && (iVar4 < 0x1a)) || ((0xb < iVar4 && (iVar4 < 0x13)))) {

    if ((iVar4 < 0x13) || (0x19 < iVar4)) {

      if (iVar6 < 8) {

        iVar6 = (iVar4 - iVar3) + -0xc;

      }

      else {

        iVar6 = iVar3 + -0xc + iVar4;

      }

      bVar9 = DAT_0059eef8 != iVar6;

      DAT_0059eef8 = iVar6;

      if (bVar9) {

        iVar6 = *(int *)(DAT_0059eeec + DAT_0059eefc * 0xc);

        iVar7 = *(int *)(DAT_0059eeec + 4 + DAT_0059eefc * 0xc);

        iVar5 = *(int *)(DAT_0059eeec + 8 + DAT_0059eefc * 0xc);

        (**(code **)(DAT_00656420 + 0x7c))(DAT_00656420,DAT_0059eeec);

        iVar3 = DAT_0059eef8 * 0x10 + DAT_0059eee8;

        DAT_0059eeec = 0;

        DAT_0059eef4 = (**(code **)(DAT_00656420 + 0x78))

                                 (DAT_00656420,&DAT_0059eeec,*(undefined4 *)(iVar3 + 8),

                                  *(undefined4 *)(iVar3 + 0xc));

        DAT_0059eefc = 0;

        if (0 < DAT_0059eef4) {

          piVar8 = (int *)(DAT_0059eeec + 8);

          do {

            if (((piVar8[-2] == iVar6) && (piVar8[-1] == iVar7)) && (*piVar8 == iVar5))

            goto LAB_0048c368;

            DAT_0059eefc = DAT_0059eefc + 1;

            piVar8 = piVar8 + 3;

          } while (DAT_0059eefc < DAT_0059eef4);

        }

        DAT_0059eefc = 0;

LAB_0048c368:

        iVar4 = DAT_0059ee9c;

        if (DAT_0059eef4 < 8) {

          DAT_0059ef00 = (7 - DAT_0059eef4) / 2;

        }

        else if (DAT_0059eefc < 3) {

          DAT_0059ef00 = 0;

        }

        else if (DAT_0059eefc < DAT_0059eef4 + -3) {

          DAT_0059ef00 = DAT_0059eefc + -3;

        }

        else {

          DAT_0059ef00 = DAT_0059eef4 + -7;

        }

      }

    }

    else if (iVar7 < 8) {

      DAT_0059eefc = (iVar4 - iVar5) + -0x13;

    }

    else {

      DAT_0059eefc = iVar5 + -0x13 + iVar4;

    }

  }

  if (((DAT_0063315c == 0) && (DAT_00633160 == 0)) &&

     ((DAT_0063317c == 0 && ((bVar1 && (iVar4 != iVar2)))))) {

    sound_play(0x65a);

    iVar4 = DAT_0059ee9c;

  }

  if (param_2 == 0) {

    mission_004fe2d0(&DAT_00632900,

                     *(undefined4 *)

                      (*(int *)(DAT_00632918 + DAT_0063291c * 0x24) + 0x10 + iVar4 * 4),0x3f000000,

                     0x3f000000,&DAT_00632abc,&DAT_00632ac0);

    DAT_00632abc = (float)DAT_00632924 * DAT_00632abc;

    DAT_00632ac0 = (float)DAT_00632928 * DAT_00632ac0;

    _DAT_00632ac4 = DAT_00632abc;

    _DAT_00632ac8 = DAT_00632ac0;

  }

  return;

}

/* ===== FUN_0048C830 @ 0x0048C830 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_0048C830(void)



{

  int iVar1;

  undefined4 *puVar2;

  code *pcVar3;

  

  iVar1 = FUN_004469e0();

  if (iVar1 == 0) {

    pcVar3 = FUN_00471dc0;

  }

  else {

    pcVar3 = FUN_004829d0;

  }

  dlog_push_level(&LAB_0048cda0,pcVar3);

  FUN_00426FA0();

  iVar1 = main_status_00500520(&DAT_00632900);

  if (iVar1 != 0) {

    DAT_0055bdb8 = 0x1c;

    DAT_0063291c = 0x1c;

    DAT_00632924 = DAT_00632e84;

    DAT_00632920 = 0xffffffff;

    DAT_00632928 = DAT_00632e88;

    if (DAT_0059ee98 != 0) {

      FUN_00497510(DAT_0059ee98);

    }

    DAT_0059ee98 = 0;

    DAT_0059ee98 = object_allocate_type(0x402,0x80000000);

    *(uint *)(DAT_0059ee98 + 0xd8) = *(uint *)(DAT_0059ee98 + 0xd8) | 0x40000000;

    iVar1 = FUN_004469e0();

    if (iVar1 != 0) {

      camera_override_refpt(DAT_0059ee98,0);

    }

    DAT_00632c0c = 1;

    DAT_0059e8e0 = 0;

    DAT_0059ee9c = 0;

    _DAT_0059eea0 = 0;

    _DAT_0059eea8 = 0;

    _DAT_0059eea4 = 0xd;

    DAT_0059eec4 = 0;

    _DAT_0059eec8 = 0;

    _DAT_0059eecc = &LAB_004829c0;

    _DAT_0059eed0 = 0;

    puVar2 = &DAT_0059dcd0;

    for (iVar1 = 300; iVar1 != 0; iVar1 = iVar1 + -1) {

      *puVar2 = 0;

      puVar2 = puVar2 + 1;

    }

    iVar1 = dialog_level_is_base_8();

    if (iVar1 != 0) {

      main_fx_004470b0(&DAT_0055a0f8);

    }

    DAT_0059eec0 = (uint)(iVar1 != 0);

    DAT_0055bdb0 = 0xe;

    DAT_0055bdb4 = 1;

    DAT_0059ee9c = 0xd;

    _DAT_0059dd6c = 1;

    mission_004fe2d0(&DAT_00632900,*(undefined4 *)(*(int *)(DAT_00632918 + 0x3f0) + 0x38),0x3f000000

                     ,0x3f000000,&DAT_00632abc,&DAT_00632ac0);

    DAT_00632abc = (float)DAT_00632924 * DAT_00632abc;

    DAT_00632ac0 = (float)DAT_00632928 * DAT_00632ac0;

    _DAT_00632ac4 = DAT_00632abc;

    _DAT_00632ac8 = DAT_00632ac0;

    return;

  }

  dialog_level_pop(&LAB_0048cda0);

  return;

}

/* ===== dialog_0048ca10 @ 0x0048CA10 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void dialog_0048ca10(void)



{

  int iVar1;

  int *piVar2;

  int iVar3;

  undefined4 *puVar4;

  

  switch(DAT_0059ee9c) {

  case 1:

    FUN_00452030();

    break;

  case 2:

    iVar3 = dialog_level_is_base_6();

    FUN_0051c7b0(iVar3 == 0);

    break;

  case 3:

    iVar3 = dialog_level_is_base_4();

    FUN_0051c700(iVar3 == 0);

    break;

  case 4:

    iVar3 = FUN_0051c870();

    iVar3 = iVar3 + 1;

    iVar1 = FUN_0051c7e0();

    if (iVar1 < iVar3) {

      iVar3 = 0;

    }

    FUN_0051c810(iVar3);

    break;

  case 5:

    iVar3 = FUN_0051c6c0();

    iVar3 = iVar3 + 1;

    iVar1 = FUN_0051c7e0();

    if (iVar1 < iVar3) {

      iVar3 = 0;

    }

    FUN_0051c660(iVar3);

    break;

  case 6:

    iVar3 = dialog_level_is_base_7();

    FUN_0051c8a0(iVar3 == 0);

    break;

  case 7:

    iVar3 = dialog_level_is_base_5();

    FUN_0051c770(iVar3 == 0);

    break;

  case 8:

    iVar3 = dialog_level_is_base_2();

    FUN_0051c590(iVar3 == 0);

    break;

  case 9:

    iVar3 = dialog_level_is_base_3();

    FUN_0051c610(iVar3 == 0);

    break;

  case 0xb:

    FUN_0051c8d0();

    break;

  case 0xc:

    dialog_level_pop(&LAB_0048cda0);

    FUN_0040d790();

    FUN_00497510(DAT_0059ee98);

    DAT_0059ee98 = 0;

    DAT_00632c0c = 0;

    iVar3 = 0;

    piVar2 = &DAT_0059dcd4;

    do {

      if (*piVar2 != 0) {

        main_menu_00483200(iVar3,0);

      }

      piVar2 = piVar2 + 3;

      iVar3 = iVar3 + 1;

      iVar1 = DAT_0059eec4;

    } while ((int)piVar2 < 0x59e184);

    for (; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x50)) {

      if (*(int *)(iVar1 + 0x48) != 0) {

        main_menu_00483200(0xffffffff,iVar1);

      }

    }

    mission_00447fd0(0,2);

    if (DAT_0059eec0 != 0) {

      main_fx_004471a0();

    }

    puVar4 = &DAT_00632aa0;

    for (iVar3 = 0x1f; iVar3 != 0; iVar3 = iVar3 + -1) {

      *puVar4 = 0;

      puVar4 = puVar4 + 1;

    }

    _DAT_00632ac4 = DAT_00632abc;

    _DAT_00632ac8 = DAT_00632ac0;

    game_options_load();

    FUN_0048A7D0();

    break;

  case 0xd:

    dialog_level_pop(&LAB_0048cda0);

    FUN_0040d790();

    FUN_00497510(DAT_0059ee98);

    DAT_0059ee98 = 0;

    DAT_00632c0c = 0;

    iVar3 = 0;

    piVar2 = &DAT_0059dcd4;

    do {

      if (*piVar2 != 0) {

        main_menu_00483200(iVar3,0);

      }

      piVar2 = piVar2 + 3;

      iVar3 = iVar3 + 1;

      iVar1 = DAT_0059eec4;

    } while ((int)piVar2 < 0x59e184);

    for (; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x50)) {

      if (*(int *)(iVar1 + 0x48) != 0) {

        main_menu_00483200(0xffffffff,iVar1);

      }

    }

    mission_00447fd0(0,2);

    if (DAT_0059eec0 != 0) {

      main_fx_004471a0();

    }

    puVar4 = &DAT_00632aa0;

    for (iVar3 = 0x1f; iVar3 != 0; iVar3 = iVar3 + -1) {

      *puVar4 = 0;

      puVar4 = puVar4 + 1;

    }

    _DAT_00632ac4 = DAT_00632abc;

    _DAT_00632ac8 = DAT_00632ac0;

    game_options_load();

    FUN_00489D40();

  }

  if (((DAT_0063315c == 0) && (DAT_00633160 == 0)) && (DAT_0063317c == 0)) {

    sound_play(0x659);

  }

  return;

}

/* ===== FUN_0048D4B0 @ 0x0048D4B0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_0048D4B0(void)



{

  int iVar1;

  undefined4 *puVar2;

  code *pcVar3;

  

  iVar1 = FUN_004469e0();

  if (iVar1 == 0) {

    pcVar3 = FUN_00471dc0;

  }

  else {

    pcVar3 = FUN_004829d0;

  }

  dlog_push_level(&LAB_0048d830,pcVar3);

  FUN_00426FA0();

  iVar1 = main_status_00500520(&DAT_00632900);

  if (iVar1 != 0) {

    DAT_0055bdb8 = 0x1d;

    DAT_0063291c = 0x1d;

    DAT_00632924 = DAT_00632e84;

    DAT_00632920 = 0xffffffff;

    DAT_00632928 = DAT_00632e88;

    if (DAT_0059ee98 != 0) {

      FUN_00497510(DAT_0059ee98);

    }

    DAT_0059ee98 = 0;

    DAT_0059ee98 = object_allocate_type(0x402,0x80000000);

    *(uint *)(DAT_0059ee98 + 0xd8) = *(uint *)(DAT_0059ee98 + 0xd8) | 0x40000000;

    iVar1 = FUN_004469e0();

    if (iVar1 != 0) {

      camera_override_refpt(DAT_0059ee98,0);

    }

    DAT_00632c0c = 1;

    DAT_0059e8e0 = 0;

    DAT_0059ee9c = 0;

    _DAT_0059eea0 = 0;

    _DAT_0059eea8 = 0;

    _DAT_0059eea4 = 6;

    DAT_0059eec4 = 0;

    _DAT_0059eec8 = 0;

    _DAT_0059eecc = &LAB_004829c0;

    _DAT_0059eed0 = 0;

    puVar2 = &DAT_0059dcd0;

    for (iVar1 = 300; iVar1 != 0; iVar1 = iVar1 + -1) {

      *puVar2 = 0;

      puVar2 = puVar2 + 1;

    }

    iVar1 = dialog_level_is_base_8();

    if (iVar1 != 0) {

      main_fx_004470b0(&DAT_0055a0f8);

    }

    DAT_0059eec0 = (uint)(iVar1 != 0);

    DAT_0055bdb0 = 7;

    DAT_0055bdb4 = 1;

    DAT_0059ee9c = 6;

    DAT_0059dd18 = 1;

    mission_004fe2d0(&DAT_00632900,*(undefined4 *)(*(int *)(DAT_00632918 + 0x414) + 0x1c),0x3f000000

                     ,0x3f000000,&DAT_00632abc,&DAT_00632ac0);

    DAT_00632abc = (float)DAT_00632924 * DAT_00632abc;

    DAT_00632ac0 = (float)DAT_00632928 * DAT_00632ac0;

    _DAT_00632ac4 = DAT_00632abc;

    _DAT_00632ac8 = DAT_00632ac0;

    return;

  }

  dialog_level_pop(&LAB_0048d830);

  return;

}

/* ===== FUN_0048d690 @ 0x0048D690 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_0048d690(void)



{

  int iVar1;

  int *piVar2;

  int iVar3;

  undefined4 *puVar4;

  

  switch(DAT_0059ee9c) {

  case 1:

    iVar3 = (*DAT_005dd2e0)(1);

    (*DAT_005dd2d4)(1,iVar3 == 0);

    FUN_00494fb0();

    break;

  case 2:

    iVar3 = (*DAT_005dd2e0)(2);

    (*DAT_005dd2d4)(2,iVar3 == 0);

    FUN_00494fe0();

    break;

  case 5:

    FUN_00482390(0);

    break;

  case 6:

    dialog_level_pop(&LAB_0048d830);

    FUN_0040d790();

    FUN_00497510(DAT_0059ee98);

    DAT_0059ee98 = 0;

    DAT_00632c0c = 0;

    iVar3 = 0;

    piVar2 = &DAT_0059dcd4;

    do {

      if (*piVar2 != 0) {

        main_menu_00483200(iVar3,0);

      }

      piVar2 = piVar2 + 3;

      iVar3 = iVar3 + 1;

      iVar1 = DAT_0059eec4;

    } while ((int)piVar2 < 0x59e184);

    for (; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x50)) {

      if (*(int *)(iVar1 + 0x48) != 0) {

        main_menu_00483200(0xffffffff,iVar1);

      }

    }

    mission_00447fd0(0,2);

    if (DAT_0059eec0 != 0) {

      main_fx_004471a0();

    }

    puVar4 = &DAT_00632aa0;

    for (iVar3 = 0x1f; iVar3 != 0; iVar3 = iVar3 + -1) {

      *puVar4 = 0;

      puVar4 = puVar4 + 1;

    }

    _DAT_00632ac4 = DAT_00632abc;

    _DAT_00632ac8 = DAT_00632ac0;

    game_options_load();

    FUN_00489D40();

  }

  if (((DAT_0063315c == 0) && (DAT_00633160 == 0)) && (DAT_0063317c == 0)) {

    sound_play(0x659);

  }

  return;

}

/* ===== FUN_0048DE30 @ 0x0048DE30 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_0048DE30(void)



{

  int iVar1;

  undefined4 *puVar2;

  code *pcVar3;

  

  iVar1 = FUN_004469e0();

  if (iVar1 == 0) {

    pcVar3 = FUN_00471dc0;

  }

  else {

    pcVar3 = FUN_004829d0;

  }

  dlog_push_level(menu_dlog_callback_a,pcVar3);

  FUN_00426FA0();

  iVar1 = main_status_00500520(&DAT_00632900);

  if (iVar1 != 0) {

    DAT_0055bdb8 = 0x29;

    DAT_0063291c = 0x29;

    DAT_00632924 = DAT_00632e84;

    DAT_00632920 = 0xffffffff;

    DAT_00632928 = DAT_00632e88;

    if (DAT_0059ee98 != 0) {

      FUN_00497510(DAT_0059ee98);

    }

    DAT_0059ee98 = 0;

    DAT_0059ee98 = object_allocate_type(0x402,0x80000000);

    *(uint *)(DAT_0059ee98 + 0xd8) = *(uint *)(DAT_0059ee98 + 0xd8) | 0x40000000;

    iVar1 = FUN_004469e0();

    if (iVar1 != 0) {

      camera_override_refpt(DAT_0059ee98,0);

    }

    DAT_00632c0c = 1;

    DAT_0059e8e0 = 0;

    DAT_0059ee9c = 0;

    _DAT_0059eea0 = 0;

    _DAT_0059eea8 = 0;

    _DAT_0059eea4 = 2;

    DAT_0059eec4 = 0;

    _DAT_0059eec8 = 0;

    _DAT_0059eecc = &LAB_004829c0;

    _DAT_0059eed0 = 0;

    puVar2 = &DAT_0059dcd0;

    for (iVar1 = 300; iVar1 != 0; iVar1 = iVar1 + -1) {

      *puVar2 = 0;

      puVar2 = puVar2 + 1;

    }

    iVar1 = dialog_level_is_base_8();

    if (iVar1 != 0) {

      main_fx_004470b0(&DAT_0055a0f8);

    }

    DAT_0059eec0 = (uint)(iVar1 != 0);

    DAT_0055bdb0 = 3;

    DAT_0055bdb4 = 1;

    DAT_0059ee9c = 2;

    _DAT_0059dce8 = 1;

    mission_004fe2d0(&DAT_00632900,*(undefined4 *)(*(int *)(DAT_00632918 + 0x5c4) + 8),0x3f000000,

                     0x3f000000,&DAT_00632abc,&DAT_00632ac0);

    DAT_00632abc = (float)DAT_00632924 * DAT_00632abc;

    DAT_00632ac0 = (float)DAT_00632928 * DAT_00632ac0;

    _DAT_00632ac4 = DAT_00632abc;

    _DAT_00632ac8 = DAT_00632ac0;

    return;

  }

  dialog_level_pop(menu_dlog_callback_a);

  return;

}

/* ===== menu_dlog_callback_a @ 0x0048E010 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void menu_dlog_callback_a(void)



{

  int iVar1;

  int *piVar2;

  int iVar3;

  undefined4 *puVar4;

  

  FUN_004a5cd0();

  main_menu_004832f0();

  DAT_0059e8e0 = 0;

  if (DAT_00632aa4._3_1_ != '\0') {

    DAT_0059ee9c = 0;

    dialog_level_pop(menu_dlog_callback_a);

    FUN_0040d790();

    FUN_00497510(DAT_0059ee98);

    DAT_0059ee98 = 0;

    DAT_00632c0c = 0;

    iVar3 = 0;

    piVar2 = &DAT_0059dcd4;

    do {

      if (*piVar2 != 0) {

        main_menu_00483200(iVar3,0);

      }

      piVar2 = piVar2 + 3;

      iVar3 = iVar3 + 1;

      iVar1 = DAT_0059eec4;

    } while ((int)piVar2 < 0x59e184);

    for (; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x50)) {

      if (*(int *)(iVar1 + 0x48) != 0) {

        main_menu_00483200(0xffffffff,iVar1);

      }

    }

    mission_00447fd0(0,2);

    if (DAT_0059eec0 != 0) {

      main_fx_004471a0();

    }

    puVar4 = &DAT_00632aa0;

    for (iVar3 = 0x1f; iVar3 != 0; iVar3 = iVar3 + -1) {

      *puVar4 = 0;

      puVar4 = puVar4 + 1;

    }

    _DAT_00632ac4 = DAT_00632abc;

    _DAT_00632ac8 = DAT_00632ac0;

    if (DAT_0059ee9c == 1) {

      if (DAT_0059eeb8 == 0) {

        FUN_004907e0();

      }

      else {

        FUN_0048F460();

      }

    }

    else {

      FUN_00489D40();

    }

    if (DAT_0063315c != 0) {

      return;

    }

    if (DAT_00633160 != 0) {

      return;

    }

    if (DAT_0063317c != 0) {

      return;

    }

    sound_play(0x659);

    if (DAT_0063315c != 0) {

      return;

    }

    if (DAT_00633160 != 0) {

      return;

    }

    if (DAT_0063317c != 0) {

      return;

    }

    sound_play(0x657);

    return;

  }

  if (DAT_00632aa0._1_1_ == '\0') {

    if (DAT_00632aa0._2_1_ == '\0') goto LAB_0048e1b4;

    iVar3 = DAT_0059ee9c + 1;

  }

  else {

    iVar3 = DAT_0059ee9c + -1;

  }

  FUN_004834d0(iVar3,0,1,0);

LAB_0048e1b4:

  FUN_00500120(&DAT_0063292c,DAT_00632924,DAT_00632928);

  iVar3 = FUN_004fff10(&DAT_00632900,DAT_0063291c,0xffffffff);

  if ((-1 < iVar3) && (FUN_004834d0(iVar3,1,1,0), DAT_00632aaa != '\0')) {

    dialog_level_pop(menu_dlog_callback_a);

    FUN_0040d790();

    FUN_00497510(DAT_0059ee98);

    DAT_0059ee98 = 0;

    DAT_00632c0c = 0;

    iVar3 = 0;

    piVar2 = &DAT_0059dcd4;

    do {

      if (*piVar2 != 0) {

        main_menu_00483200(iVar3,0);

      }

      piVar2 = piVar2 + 3;

      iVar3 = iVar3 + 1;

      iVar1 = DAT_0059eec4;

    } while ((int)piVar2 < 0x59e184);

    for (; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x50)) {

      if (*(int *)(iVar1 + 0x48) != 0) {

        main_menu_00483200(0xffffffff,iVar1);

      }

    }

    mission_00447fd0(0,2);

    if (DAT_0059eec0 != 0) {

      main_fx_004471a0();

    }

    puVar4 = &DAT_00632aa0;

    for (iVar3 = 0x1f; iVar3 != 0; iVar3 = iVar3 + -1) {

      *puVar4 = 0;

      puVar4 = puVar4 + 1;

    }

    _DAT_00632ac4 = DAT_00632abc;

    _DAT_00632ac8 = DAT_00632ac0;

    if (DAT_0059ee9c == 1) {

      if (DAT_0059eeb8 == 0) {

        FUN_004907e0();

      }

      else {

        FUN_0048F460();

      }

    }

    else {

      FUN_00489D40();

    }

    if (((DAT_0063315c == 0) && (DAT_00633160 == 0)) && (DAT_0063317c == 0)) {

      sound_play(0x659);

    }

  }

  if (DAT_00632aa8 != '\0') {

    dialog_level_pop(menu_dlog_callback_a);

    FUN_0040d790();

    FUN_00497510(DAT_0059ee98);

    DAT_0059ee98 = 0;

    DAT_00632c0c = 0;

    iVar3 = 0;

    piVar2 = &DAT_0059dcd4;

    do {

      if (*piVar2 != 0) {

        main_menu_00483200(iVar3,0);

      }

      piVar2 = piVar2 + 3;

      iVar3 = iVar3 + 1;

      iVar1 = DAT_0059eec4;

    } while ((int)piVar2 < 0x59e184);

    for (; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x50)) {

      if (*(int *)(iVar1 + 0x48) != 0) {

        main_menu_00483200(0xffffffff,iVar1);

      }

    }

    mission_00447fd0(0,2);

    if (DAT_0059eec0 != 0) {

      main_fx_004471a0();

    }

    puVar4 = &DAT_00632aa0;

    for (iVar3 = 0x1f; iVar3 != 0; iVar3 = iVar3 + -1) {

      *puVar4 = 0;

      puVar4 = puVar4 + 1;

    }

    _DAT_00632ac4 = DAT_00632abc;

    _DAT_00632ac8 = DAT_00632ac0;

    if (DAT_0059ee9c == 1) {

      if (DAT_0059eeb8 == 0) {

        FUN_004907e0();

      }

      else {

        FUN_0048F460();

      }

    }

    else {

      FUN_00489D40();

    }

    if (((DAT_0063315c == 0) && (DAT_00633160 == 0)) && (DAT_0063317c == 0)) {

      sound_play(0x659);

    }

  }

  return;

}

/* ===== FUN_0048E430 @ 0x0048E430 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_0048E430(void)



{

  int iVar1;

  undefined4 *puVar2;

  code *pcVar3;

  

  iVar1 = FUN_004469e0();

  if (iVar1 == 0) {

    pcVar3 = FUN_00471dc0;

  }

  else {

    pcVar3 = FUN_004829d0;

  }

  dlog_push_level(menu_dlog_callback_b,pcVar3);

  FUN_00426FA0();

  iVar1 = main_status_00500520(&DAT_00632900);

  if (iVar1 != 0) {

    DAT_0055bdb8 = 0x28;

    DAT_0063291c = 0x28;

    DAT_00632924 = DAT_00632e84;

    DAT_00632920 = 0xffffffff;

    DAT_00632928 = DAT_00632e88;

    if (DAT_0059ee98 != 0) {

      FUN_00497510(DAT_0059ee98);

    }

    DAT_0059ee98 = 0;

    DAT_0059ee98 = object_allocate_type(0x402,0x80000000);

    *(uint *)(DAT_0059ee98 + 0xd8) = *(uint *)(DAT_0059ee98 + 0xd8) | 0x40000000;

    iVar1 = FUN_004469e0();

    if (iVar1 != 0) {

      camera_override_refpt(DAT_0059ee98,0);

    }

    DAT_00632c0c = 1;

    DAT_0059e8e0 = 0;

    DAT_0059ee9c = 0;

    _DAT_0059eea0 = 0;

    _DAT_0059eea8 = 0;

    _DAT_0059eea4 = 2;

    DAT_0059eec4 = 0;

    _DAT_0059eec8 = 0;

    _DAT_0059eecc = &LAB_004829c0;

    _DAT_0059eed0 = 0;

    puVar2 = &DAT_0059dcd0;

    for (iVar1 = 300; iVar1 != 0; iVar1 = iVar1 + -1) {

      *puVar2 = 0;

      puVar2 = puVar2 + 1;

    }

    iVar1 = dialog_level_is_base_8();

    if (iVar1 != 0) {

      main_fx_004470b0(&DAT_0055a0f8);

    }

    DAT_0059eec0 = (uint)(iVar1 != 0);

    DAT_0055bdb0 = 3;

    DAT_0055bdb4 = 1;

    DAT_0059ee9c = 2;

    _DAT_0059dce8 = 1;

    mission_004fe2d0(&DAT_00632900,*(undefined4 *)(*(int *)(DAT_00632918 + 0x5a0) + 8),0x3f000000,

                     0x3f000000,&DAT_00632abc,&DAT_00632ac0);

    DAT_00632abc = (float)DAT_00632924 * DAT_00632abc;

    DAT_00632ac0 = (float)DAT_00632928 * DAT_00632ac0;

    _DAT_00632ac4 = DAT_00632abc;

    _DAT_00632ac8 = DAT_00632ac0;

    return;

  }

  dialog_level_pop(menu_dlog_callback_b);

  return;

}

/* ===== menu_dlog_callback_b @ 0x0048E610 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void menu_dlog_callback_b(void)



{

  int iVar1;

  int *piVar2;

  int iVar3;

  undefined4 *puVar4;

  

  FUN_004a5cd0();

  main_menu_004832f0();

  DAT_0059e8e0 = 0;

  if (DAT_00632aa4._3_1_ != '\0') {

    DAT_0059ee9c = 0;

    dialog_level_pop(menu_dlog_callback_b);

    FUN_0040d790();

    FUN_00497510(DAT_0059ee98);

    DAT_0059ee98 = 0;

    DAT_00632c0c = 0;

    iVar3 = 0;

    piVar2 = &DAT_0059dcd4;

    do {

      if (*piVar2 != 0) {

        main_menu_00483200(iVar3,0);

      }

      piVar2 = piVar2 + 3;

      iVar3 = iVar3 + 1;

      iVar1 = DAT_0059eec4;

    } while ((int)piVar2 < 0x59e184);

    for (; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x50)) {

      if (*(int *)(iVar1 + 0x48) != 0) {

        main_menu_00483200(0xffffffff,iVar1);

      }

    }

    mission_00447fd0(0,2);

    if (DAT_0059eec0 != 0) {

      main_fx_004471a0();

    }

    puVar4 = &DAT_00632aa0;

    for (iVar3 = 0x1f; iVar3 != 0; iVar3 = iVar3 + -1) {

      *puVar4 = 0;

      puVar4 = puVar4 + 1;

    }

    _DAT_00632ac4 = DAT_00632abc;

    _DAT_00632ac8 = DAT_00632ac0;

    if (DAT_0059ee9c == 1) {

      FUN_004946a0();

      (*DAT_005dd28c)();

      DAT_00632e40 = 0;

      FUN_00495990(0x6e6);

    }

    else {

      FUN_00489D40();

    }

    if (DAT_0063315c != 0) {

      return;

    }

    if (DAT_00633160 != 0) {

      return;

    }

    if (DAT_0063317c != 0) {

      return;

    }

    sound_play(0x659);

    if (DAT_0063315c != 0) {

      return;

    }

    if (DAT_00633160 != 0) {

      return;

    }

    if (DAT_0063317c != 0) {

      return;

    }

    sound_play(0x657);

    return;

  }

  if (DAT_00632aa0._1_1_ == '\0') {

    if (DAT_00632aa0._2_1_ == '\0') goto LAB_0048e7be;

    iVar3 = DAT_0059ee9c + 1;

  }

  else {

    iVar3 = DAT_0059ee9c + -1;

  }

  FUN_004834d0(iVar3,0,1,0);

LAB_0048e7be:

  FUN_00500120(&DAT_0063292c,DAT_00632924,DAT_00632928);

  iVar3 = FUN_004fff10(&DAT_00632900,DAT_0063291c,0xffffffff);

  if ((-1 < iVar3) && (FUN_004834d0(iVar3,1,1,0), DAT_00632aaa != '\0')) {

    dialog_level_pop(menu_dlog_callback_b);

    FUN_0040d790();

    FUN_00497510(DAT_0059ee98);

    DAT_0059ee98 = 0;

    DAT_00632c0c = 0;

    piVar2 = &DAT_0059dcd4;

    iVar3 = 0;

    do {

      if (*piVar2 != 0) {

        main_menu_00483200(iVar3,0);

      }

      piVar2 = piVar2 + 3;

      iVar3 = iVar3 + 1;

      iVar1 = DAT_0059eec4;

    } while ((int)piVar2 < 0x59e184);

    for (; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x50)) {

      if (*(int *)(iVar1 + 0x48) != 0) {

        main_menu_00483200(0xffffffff,iVar1);

      }

    }

    mission_00447fd0(0,2);

    if (DAT_0059eec0 != 0) {

      main_fx_004471a0();

    }

    puVar4 = &DAT_00632aa0;

    for (iVar3 = 0x1f; iVar3 != 0; iVar3 = iVar3 + -1) {

      *puVar4 = 0;

      puVar4 = puVar4 + 1;

    }

    _DAT_00632ac4 = DAT_00632abc;

    _DAT_00632ac8 = DAT_00632ac0;

    if (DAT_0059ee9c == 1) {

      FUN_004946a0();

      (*DAT_005dd28c)();

      DAT_00632e40 = 0;

      FUN_00495990(0x6e6);

    }

    else {

      FUN_00489D40();

    }

    if (((DAT_0063315c == 0) && (DAT_00633160 == 0)) && (DAT_0063317c == 0)) {

      sound_play(0x659);

    }

  }

  if (DAT_00632aa8 != '\0') {

    dialog_level_pop(menu_dlog_callback_b);

    FUN_0040d790();

    FUN_00497510(DAT_0059ee98);

    DAT_0059ee98 = 0;

    DAT_00632c0c = 0;

    iVar3 = 0;

    piVar2 = &DAT_0059dcd4;

    do {

      if (*piVar2 != 0) {

        main_menu_00483200(iVar3,0);

      }

      piVar2 = piVar2 + 3;

      iVar3 = iVar3 + 1;

      iVar1 = DAT_0059eec4;

    } while ((int)piVar2 < 0x59e184);

    for (; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x50)) {

      if (*(int *)(iVar1 + 0x48) != 0) {

        main_menu_00483200(0xffffffff,iVar1);

      }

    }

    mission_00447fd0(0,2);

    if (DAT_0059eec0 != 0) {

      main_fx_004471a0();

    }

    puVar4 = &DAT_00632aa0;

    for (iVar3 = 0x1f; iVar3 != 0; iVar3 = iVar3 + -1) {

      *puVar4 = 0;

      puVar4 = puVar4 + 1;

    }

    _DAT_00632ac4 = DAT_00632abc;

    _DAT_00632ac8 = DAT_00632ac0;

    if (DAT_0059ee9c == 1) {

      FUN_004946a0();

      (*DAT_005dd28c)();

      DAT_00632e40 = 0;

      FUN_00495990(0x6e6);

    }

    else {

      FUN_00489D40();

    }

    if (((DAT_0063315c == 0) && (DAT_00633160 == 0)) && (DAT_0063317c == 0)) {

      sound_play(0x659);

    }

  }

  return;

}

/* ===== FUN_0048EA50 @ 0x0048EA50 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_0048EA50(void)



{

  int iVar1;

  undefined4 *puVar2;

  code *pcVar3;

  

  iVar1 = FUN_004469e0();

  if (iVar1 == 0) {

    pcVar3 = FUN_00471dc0;

  }

  else {

    pcVar3 = FUN_004829d0;

  }

  dlog_push_level(&LAB_0048ed70,pcVar3);

  FUN_00426FA0();

  iVar1 = main_status_00500520(&DAT_00632900);

  if (iVar1 != 0) {

    DAT_0055bdb8 = 0x1e;

    DAT_0063291c = 0x1e;

    DAT_00632924 = DAT_00632e84;

    DAT_00632920 = 0xffffffff;

    DAT_00632928 = DAT_00632e88;

    if (DAT_0059ee98 != 0) {

      FUN_00497510(DAT_0059ee98);

    }

    DAT_0059ee98 = 0;

    DAT_0059ee98 = object_allocate_type(0x402,0x80000000);

    *(uint *)(DAT_0059ee98 + 0xd8) = *(uint *)(DAT_0059ee98 + 0xd8) | 0x40000000;

    iVar1 = FUN_004469e0();

    if (iVar1 != 0) {

      camera_override_refpt(DAT_0059ee98,0);

    }

    DAT_00632c0c = 1;

    DAT_0059e8e0 = 0;

    DAT_0059ee9c = 0;

    _DAT_0059eea0 = 0;

    _DAT_0059eea8 = 0;

    _DAT_0059eea4 = 2;

    DAT_0059eec4 = 0;

    _DAT_0059eec8 = 0;

    _DAT_0059eecc = &LAB_004829c0;

    _DAT_0059eed0 = 0;

    puVar2 = &DAT_0059dcd0;

    for (iVar1 = 300; iVar1 != 0; iVar1 = iVar1 + -1) {

      *puVar2 = 0;

      puVar2 = puVar2 + 1;

    }

    iVar1 = dialog_level_is_base_8();

    if (iVar1 != 0) {

      main_fx_004470b0(&DAT_0055a0f8);

    }

    DAT_0059eec0 = (uint)(iVar1 != 0);

    DAT_0055bdb0 = 3;

    DAT_0055bdb4 = 1;

    DAT_0059ee9c = 2;

    _DAT_0059dce8 = 1;

    mission_004fe2d0(&DAT_00632900,*(undefined4 *)(*(int *)(DAT_00632918 + 0x438) + 8),0x3f000000,

                     0x3f000000,&DAT_00632abc,&DAT_00632ac0);

    DAT_00632abc = (float)DAT_00632924 * DAT_00632abc;

    DAT_00632ac0 = (float)DAT_00632928 * DAT_00632ac0;

    _DAT_00632ac4 = DAT_00632abc;

    _DAT_00632ac8 = DAT_00632ac0;

    return;

  }

  dialog_level_pop(&LAB_0048ed70);

  return;

}

/* ===== FUN_0048EC30 @ 0x0048EC30 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_0048EC30(void)



{

  int iVar1;

  int *piVar2;

  int iVar3;

  undefined4 *puVar4;

  

  dialog_level_pop(&LAB_0048ed70);

  FUN_0040d790();

  FUN_00497510(DAT_0059ee98);

  DAT_0059ee98 = 0;

  DAT_00632c0c = 0;

  iVar3 = 0;

  piVar2 = &DAT_0059dcd4;

  do {

    if (*piVar2 != 0) {

      main_menu_00483200(iVar3,0);

    }

    piVar2 = piVar2 + 3;

    iVar3 = iVar3 + 1;

    iVar1 = DAT_0059eec4;

  } while ((int)piVar2 < 0x59e184);

  for (; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x50)) {

    if (*(int *)(iVar1 + 0x48) != 0) {

      main_menu_00483200(0xffffffff,iVar1);

    }

  }

  mission_00447fd0(0,2);

  if (DAT_0059eec0 != 0) {

    main_fx_004471a0();

  }

  puVar4 = &DAT_00632aa0;

  for (iVar3 = 0x1f; iVar3 != 0; iVar3 = iVar3 + -1) {

    *puVar4 = 0;

    puVar4 = puVar4 + 1;

  }

  _DAT_00632ac4 = DAT_00632abc;

  _DAT_00632ac8 = DAT_00632ac0;

  if (DAT_0059ee9c == 1) {

    if (DAT_0059eeb8 == 0) {

      DAT_00633048 = 1;

    }

    Audio3DTestToneUpdate__Fv_4();

  }

  else if (DAT_0059eeb8 == 0) {

    options_defplayer();

  }

  else if (DAT_0059eeb8 == 1) {

    menu_mission_launch();

  }

  else if (DAT_0059eeb8 == 2) {

    FUN_00489D40();

  }

  if (((DAT_0063315c == 0) && (DAT_00633160 == 0)) && (DAT_0063317c == 0)) {

    sound_play(0x659);

  }

  return;

}

/* ===== FUN_0048EE60 @ 0x0048EE60 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_0048EE60(void)



{

  int iVar1;

  undefined4 *puVar2;

  code *pcVar3;

  

  iVar1 = FUN_004469e0();

  if (iVar1 == 0) {

    pcVar3 = FUN_00471dc0;

  }

  else {

    pcVar3 = FUN_004829d0;

  }

  dlog_push_level(&LAB_0048f160,pcVar3);

  FUN_00426FA0();

  iVar1 = main_status_00500520(&DAT_00632900);

  if (iVar1 != 0) {

    DAT_0055bdb8 = 0x1f;

    DAT_0063291c = 0x1f;

    DAT_00632924 = DAT_00632e84;

    DAT_00632920 = 0xffffffff;

    DAT_00632928 = DAT_00632e88;

    if (DAT_0059ee98 != 0) {

      FUN_00497510(DAT_0059ee98);

    }

    DAT_0059ee98 = 0;

    DAT_0059ee98 = object_allocate_type(0x402,0x80000000);

    *(uint *)(DAT_0059ee98 + 0xd8) = *(uint *)(DAT_0059ee98 + 0xd8) | 0x40000000;

    iVar1 = FUN_004469e0();

    if (iVar1 != 0) {

      camera_override_refpt(DAT_0059ee98,0);

    }

    DAT_00632c0c = 1;

    DAT_0059e8e0 = 0;

    DAT_0059ee9c = 0;

    _DAT_0059eea0 = 0;

    _DAT_0059eea8 = 0;

    _DAT_0059eea4 = 2;

    DAT_0059eec4 = 0;

    _DAT_0059eec8 = 0;

    _DAT_0059eecc = &LAB_004829c0;

    _DAT_0059eed0 = 0;

    puVar2 = &DAT_0059dcd0;

    for (iVar1 = 300; iVar1 != 0; iVar1 = iVar1 + -1) {

      *puVar2 = 0;

      puVar2 = puVar2 + 1;

    }

    iVar1 = dialog_level_is_base_8();

    if (iVar1 != 0) {

      main_fx_004470b0(&DAT_0055a0f8);

    }

    DAT_0059eec0 = (uint)(iVar1 != 0);

    DAT_0055bdb0 = 3;

    DAT_0055bdb4 = 1;

    DAT_0059ee9c = 2;

    _DAT_0059dce8 = 1;

    mission_004fe2d0(&DAT_00632900,*(undefined4 *)(*(int *)(DAT_00632918 + 0x45c) + 8),0x3f000000,

                     0x3f000000,&DAT_00632abc,&DAT_00632ac0);

    DAT_00632abc = (float)DAT_00632924 * DAT_00632abc;

    DAT_00632ac0 = (float)DAT_00632928 * DAT_00632ac0;

    _DAT_00632ac4 = DAT_00632abc;

    _DAT_00632ac8 = DAT_00632ac0;

    return;

  }

  dialog_level_pop(&LAB_0048f160);

  return;

}

/* ===== FUN_0048f040 @ 0x0048F040 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_0048f040(void)



{

  int iVar1;

  int *piVar2;

  int iVar3;

  undefined4 *puVar4;

  

  dialog_level_pop(&LAB_0048f160);

  FUN_0040d790();

  FUN_00497510(DAT_0059ee98);

  DAT_0059ee98 = 0;

  DAT_00632c0c = 0;

  iVar3 = 0;

  piVar2 = &DAT_0059dcd4;

  do {

    if (*piVar2 != 0) {

      main_menu_00483200(iVar3,0);

    }

    piVar2 = piVar2 + 3;

    iVar3 = iVar3 + 1;

    iVar1 = DAT_0059eec4;

  } while ((int)piVar2 < 0x59e184);

  for (; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x50)) {

    if (*(int *)(iVar1 + 0x48) != 0) {

      main_menu_00483200(0xffffffff,iVar1);

    }

  }

  mission_00447fd0(0,2);

  if (DAT_0059eec0 != 0) {

    main_fx_004471a0();

  }

  puVar4 = &DAT_00632aa0;

  for (iVar3 = 0x1f; iVar3 != 0; iVar3 = iVar3 + -1) {

    *puVar4 = 0;

    puVar4 = puVar4 + 1;

  }

  _DAT_00632ac4 = DAT_00632abc;

  _DAT_00632ac8 = DAT_00632ac0;

  if (DAT_0059ee9c == 1) {

    FUN_00519fe0(&DAT_006329e0);

    comm_0051a130(s_Deleted_0055bf90,1);

  }

  mission_intro_load();

  if (((DAT_0063315c == 0) && (DAT_00633160 == 0)) && (DAT_0063317c == 0)) {

    sound_play(0x659);

  }

  return;

}

/* ===== story_script_scan @ 0x0048F310 ===== */
void story_script_scan(void)



{

  char *pcVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  int local_10;

  int local_c;

  int local_8;

  int local_4;

  

  iVar2 = texture_add_file(&local_8);

  iVar4 = 0;

  iVar6 = 0;

  DAT_0059e390 = 0;

  iVar5 = 0;

  do {

    pcVar1 = (char *)(iVar4 + 0x2210 + DAT_006330e4);

    if (*pcVar1 != '\0') {

      mission_flick_load(pcVar1,&local_10,&local_4,&local_c);

      if ((local_10 != 0) && (iVar3 = FUN_00545650(local_10,s_kstory1b_0055c46c), iVar3 != 0)) {

        (&DAT_0059ed48)[DAT_0059e390] = local_10;

        (&DAT_0059ecf8)[DAT_0059e390] = iVar5;

        DAT_0059e390 = DAT_0059e390 + 1;

      }

      if (local_c != 0) {

        (&DAT_0059ed48)[DAT_0059e390] = local_c;

        (&DAT_0059ecf8)[DAT_0059e390] = iVar5;

        DAT_0059e390 = DAT_0059e390 + 1;

      }

      if ((DAT_00632d20 == 4) && (iVar6 == iVar2 + -1)) {

        (&DAT_0059ed48)[DAT_0059e390] = s_story5_Pad_0055c460;

        (&DAT_0059ecf8)[DAT_0059e390] = iVar5;

        (&DAT_0059ed48)[DAT_0059e390 + 1] = s_story5_get_food_1_0055c44c;

        (&DAT_0059ecf8)[DAT_0059e390 + 1] = iVar5;

        (&DAT_0059ed48)[DAT_0059e390 + 2] = s_story5_rp_are_coming_1_0055c434;

        (&DAT_0059ecf8)[DAT_0059e390 + 2] = iVar5;

        DAT_0059e390 = DAT_0059e390 + 3;

      }

      iVar6 = iVar6 + 1;

      if (((iVar6 != iVar2) || (iVar2 == local_8)) && (local_4 != 0)) {

        (&DAT_0059ed48)[DAT_0059e390] = local_4;

        (&DAT_0059ecf8)[DAT_0059e390] = iVar5;

        DAT_0059e390 = DAT_0059e390 + 1;

      }

      if (iVar6 == iVar2) {

        return;

      }

    }

    iVar4 = iVar4 + 0x118;

    iVar5 = iVar5 + 1;

    if (0x22ff < iVar4) {

      return;

    }

  } while( true );

}

/* ===== FUN_0048F460 @ 0x0048F460 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_0048F460(void)



{

  int iVar1;

  undefined4 *puVar2;

  

  dlog_push_level(&LAB_0048f840,FUN_00471dc0);

  FUN_00426FA0();

  iVar1 = main_status_00500520(&DAT_00632900);

  if (iVar1 != 0) {

    DAT_0055bdb8 = 0x27;

    DAT_0063291c = 0x27;

    DAT_00632924 = DAT_00632e84;

    DAT_00632920 = 0xffffffff;

    DAT_00632928 = DAT_00632e88;

    if (DAT_0059ee98 != 0) {

      FUN_00497510(DAT_0059ee98);

    }

    DAT_0059ee98 = 0;

    DAT_0059ee98 = object_allocate_type(0x3fb,0x80000000);

    *(uint *)(DAT_0059ee98 + 0xd8) = *(uint *)(DAT_0059ee98 + 0xd8) | 0x40000000;

    story_script_scan();

    camera_override_refpt(DAT_0059ee98,0);

    DAT_00632c0c = 1;

    DAT_0059e8e0 = 0;

    DAT_0059ee9c = 0;

    _DAT_0059eea0 = 0;

    _DAT_0059eea8 = 0;

    _DAT_0059eea4 = 0x15;

    DAT_0059eec4 = 0;

    _DAT_0059eec8 = 0;

    _DAT_0059eecc = &LAB_004829c0;

    _DAT_0059eed0 = 0;

    puVar2 = &DAT_0059dcd0;

    for (iVar1 = 300; iVar1 != 0; iVar1 = iVar1 + -1) {

      *puVar2 = 0;

      puVar2 = puVar2 + 1;

    }

    iVar1 = dialog_level_is_base_8();

    if (iVar1 != 0) {

      main_fx_004470b0(&DAT_0055a0f8);

    }

    DAT_0059eec0 = (uint)(iVar1 != 0);

    DAT_0055bdb0 = 0x16;

    DAT_0055bdb4 = 1;

    DAT_0059ee9c = 0x15;

    _DAT_0059ddcc = 1;

    mission_004fe2d0(&DAT_00632900,*(undefined4 *)(*(int *)(DAT_00632918 + 0x57c) + 0x58),0x3f000000

                     ,0x3f000000,&DAT_00632abc,&DAT_00632ac0);

    DAT_00632abc = (float)DAT_00632924 * DAT_00632abc;

    DAT_00632ac0 = (float)DAT_00632928 * DAT_00632ac0;

    _DAT_00632ac4 = DAT_00632abc;

    _DAT_00632ac8 = DAT_00632ac0;

    return;

  }

  dialog_level_pop(&LAB_0048f840);

  return;

}

/* ===== FUN_0048f620 @ 0x0048F620 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_0048f620(int param_1)



{

  byte *pbVar1;

  byte bVar2;

  undefined4 uVar3;

  byte *pbVar4;

  int iVar5;

  byte *pbVar6;

  int *piVar7;

  byte *pbVar8;

  int iVar9;

  undefined4 *puVar10;

  bool bVar11;

  float10 fVar12;

  

  dialog_level_pop(&LAB_0048f840);

  FUN_0040d790();

  FUN_00497510(DAT_0059ee98);

  DAT_0059ee98 = 0;

  DAT_00632c0c = 0;

  iVar9 = 0;

  piVar7 = &DAT_0059dcd4;

  do {

    if (*piVar7 != 0) {

      main_menu_00483200(iVar9,0);

    }

    piVar7 = piVar7 + 3;

    iVar9 = iVar9 + 1;

    iVar5 = DAT_0059eec4;

  } while ((int)piVar7 < 0x59e184);

  for (; iVar5 != 0; iVar5 = *(int *)(iVar5 + 0x50)) {

    if (*(int *)(iVar5 + 0x48) != 0) {

      main_menu_00483200(0xffffffff,iVar5);

    }

  }

  mission_00447fd0(0,2);

  if (DAT_0059eec0 != 0) {

    main_fx_004471a0();

  }

  puVar10 = &DAT_00632aa0;

  for (iVar9 = 0x1f; iVar9 != 0; iVar9 = iVar9 + -1) {

    *puVar10 = 0;

    puVar10 = puVar10 + 1;

  }

  _DAT_00632ac4 = DAT_00632abc;

  _DAT_00632ac8 = DAT_00632ac0;

  if ((DAT_0059ee9c == 0x15) || (param_1 != 0)) {

    FUN_00489D40();

    return;

  }

  (*DAT_005dd28c)();

  DAT_00632e40 = 0;

  FUN_00495990(0x6e6);

  iVar9 = 0;

  pbVar1 = (byte *)(*(int *)(&DAT_0059ecf4 + DAT_0059ee9c * 4) * 0x118 + 0x2210 + DAT_006330e4);

  pbVar4 = (byte *)(DAT_006330e4 + 0x4558);

  pbVar8 = pbVar1;

  pbVar6 = pbVar4;

LAB_0048f744:

  do {

    bVar2 = *pbVar4;

    bVar11 = bVar2 < *pbVar8;

    if (bVar2 == *pbVar8) {

      if (bVar2 != 0) {

        bVar2 = pbVar4[1];

        bVar11 = bVar2 < pbVar8[1];

        if (bVar2 != pbVar8[1]) goto LAB_0048f768;

        pbVar4 = pbVar4 + 2;

        pbVar8 = pbVar8 + 2;

        if (bVar2 != 0) goto LAB_0048f744;

      }

      iVar5 = 0;

    }

    else {

LAB_0048f768:

      iVar5 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);

    }

    if (iVar5 == 0) break;

    iVar9 = iVar9 + 1;

    pbVar4 = pbVar6 + 0x30;

    pbVar8 = pbVar1;

    pbVar6 = pbVar4;

  } while (iVar9 < 0x1b);

  if (iVar9 == 0x1b) {

    return;

  }

  FUN_00492150(DAT_00632d20,iVar9);

  FUN_00492430(DAT_00632d20,iVar9);

  uVar3 = DAT_006331f8;

  DAT_006331f8 = 0;

  scenerio_start_index__Fi(iVar9);

  DAT_006331f8 = uVar3;

  for (puVar10 = DAT_00632d68; puVar10 != (undefined4 *)0x0; puVar10 = (undefined4 *)*puVar10) {

    iVar9 = puVar10[3];

    FUN_004a6420(iVar9);

    if (DAT_00632a88 == 0) break;

    if (((*(uint *)(iVar9 + 0xd8) & 0xc000) == 0) && ((*(uint *)(iVar9 + 0xd8) & 0x40) == 0)) {

      FUN_004967b0(iVar9);

      fVar12 = (float10)FUN_00518b70(iVar9,0);

      FUN_00403e60(iVar9,(float)fVar12);

      FUN_00499500(iVar9);

    }

  }

  flk_file_open2();

  return;

}

