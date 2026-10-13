/* Giants 1.449 — module _unmapped_0040
 * 105 functions (71 named) — decompiled, names from PS2 symbols
 * Original source: C:\Giants\source\_unmapped_0040.c(pp) (assert-string evidence)
 */

/* ===== ai_clear_move_goal @ 0x00401000 ===== */
/* PS2 candidate: ai_clear_move_goal (conf 0.469) */



void ai_clear_move_goal(int param_1)



{

  undefined4 *puVar1;

  undefined4 *puVar2;

  

  puVar1 = *(undefined4 **)(param_1 + 0x168);

  while (puVar2 = puVar1, puVar2 != (undefined4 *)0x0) {

    puVar1 = (undefined4 *)*puVar2;

    *puVar2 = DAT_00584194;

    DAT_00584194 = puVar2;

  }

  *(undefined4 *)(param_1 + 0x168) = 0;

  *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) & 0xfcffffff;

  return;

}

/* ===== ai_fly_update_goal @ 0x004019C0 ===== */
void ai_fly_update_goal(undefined4 param_1,undefined4 param_2,undefined4 param_3)



{

  ai_do_update_goal__FUiP6OBJECTP3P3Dff(5,param_1,param_2,param_3,0);

  return;

}

/* ===== ai_do_update_goal__FUiP6OBJECTP3P3Dff @ 0x004019E0 ===== */
/* PS2 candidate: ai_do_update_goal__FUiP6OBJECTP3P3Dff (conf 0.314) */



void ai_do_update_goal__FUiP6OBJECTP3P3Dff

               (byte param_1,int param_2,float *param_3,undefined4 param_4,undefined4 param_5)



{

  float *pfVar1;

  undefined4 *puVar2;

  undefined4 *puVar3;

  float fVar4;

  float *pfVar5;

  float10 fVar6;

  float local_c;

  float local_8;

  float local_4;

  

  pfVar1 = param_3;

  puVar2 = *(undefined4 **)(param_2 + 0x168);

  if (puVar2 != (undefined4 *)0x0) {

    if (10.0 < (float)puVar2[6]) {

      while (puVar3 = puVar2, puVar3 != (undefined4 *)0x0) {

        puVar2 = (undefined4 *)*puVar3;

        *puVar3 = DAT_00584194;

        DAT_00584194 = puVar3;

      }

      *(undefined4 *)(param_2 + 0x168) = 0;

      *(uint *)(param_2 + 0xd8) = *(uint *)(param_2 + 0xd8) & 0xfcffffff;

      if ((param_1 & 2) != 0) {

        puVar2 = (undefined4 *)main_ai_move_004033d0();

        *puVar2 = *(undefined4 *)(param_2 + 0x168);

        *(undefined4 **)(param_2 + 0x168) = puVar2;

        pfVar5 = (float *)(puVar2 + 1);

        *pfVar5 = *param_3;

        puVar2[2] = param_3[1];

        fVar4 = param_3[2];

LAB_00401cd9:

        pfVar5[2] = fVar4;

        puVar2[4] = param_5;

        puVar2[5] = 0x80000080;

        return;

      }

      if ((param_1 & 4) != 0) {

        puVar2 = (undefined4 *)main_ai_move_004033d0();

        *puVar2 = *(undefined4 *)(param_2 + 0x168);

        *(undefined4 **)(param_2 + 0x168) = puVar2;

        puVar2[4] = param_4;

        puVar2[5] = 0x20;

        main_ai_move_004016d0(param_2,param_3);

        return;

      }

      goto LAB_00401f0b;

    }

    if ((float)puVar2[6] <= 10.0) {

      local_c = *param_3;

      local_8 = param_3[1];

      local_4 = param_3[2];

      param_3 = (float *)param_4;

      puVar3 = puVar2;

      do {

        if ((puVar3[5] & 0x420) == 0) {

          local_c = (float)puVar3[1];

          local_8 = (float)puVar3[2];

          local_4 = (float)puVar3[3];

        }

        if ((*(byte *)(puVar3 + 5) & 0x20) != 0) {

          param_3 = (float *)puVar3[4];

        }

        puVar3 = (undefined4 *)*puVar3;

      } while (puVar3 != (undefined4 *)0x0);

      if (((float)puVar2[6] <= 1.0) || (*(int *)(param_2 + 0x220) == 0)) {

        if ((*pfVar1 == local_c) && (pfVar1[1] == local_8)) {

          return;

        }

        fVar6 = (float10)distancesq2d__FP3P3DT0(pfVar1,&local_c);

        if ((fVar6 < (float10)2.0) ||

           ((fVar6 = (float10)distancesq2d__FP3P3DT0(pfVar1,&local_c), fVar6 < (float10)12.0 &&

            ((float)puVar2[6] <= 4.0)))) {

          do {

            if (((puVar2[5] & 0x420) == 0) &&

               (((float)puVar2[1] == local_c && ((float)puVar2[2] == local_8)))) {

              puVar2[1] = *pfVar1;

              puVar2[2] = pfVar1[1];

              puVar2[3] = pfVar1[2];

            }

            if (((puVar2[5] & 0x20) != 0) &&

               (fVar6 = (float10)FUN_0050a770(puVar2[4],param_3), fVar6 == (float10)0.0)) {

              puVar2[4] = param_4;

            }

            puVar2 = (undefined4 *)*puVar2;

          } while (puVar2 != (undefined4 *)0x0);

          return;

        }

        puVar2 = *(undefined4 **)(param_2 + 0x168);

        while (puVar3 = puVar2, puVar3 != (undefined4 *)0x0) {

          puVar2 = (undefined4 *)*puVar3;

          *puVar3 = DAT_00584194;

          DAT_00584194 = puVar3;

        }

        *(undefined4 *)(param_2 + 0x168) = 0;

        *(uint *)(param_2 + 0xd8) = *(uint *)(param_2 + 0xd8) & 0xfcffffff;

        if ((param_1 & 2) == 0) {

          if ((param_1 & 4) != 0) {

            puVar2 = (undefined4 *)main_ai_move_004033d0();

            *puVar2 = *(undefined4 *)(param_2 + 0x168);

            *(undefined4 **)(param_2 + 0x168) = puVar2;

            puVar2[4] = param_4;

            puVar2[5] = 0x20;

            puVar2 = (undefined4 *)main_ai_move_004033d0();

            *puVar2 = *(undefined4 *)(param_2 + 0x168);

            *(undefined4 **)(param_2 + 0x168) = puVar2;

            puVar2[1] = *pfVar1;

            puVar2[2] = pfVar1[1];

            puVar2[3] = pfVar1[2];

            puVar2[5] = 0x88;

            return;

          }

          if ((param_1 & 1) != 0) {

            puVar2 = (undefined4 *)main_ai_move_004033d0();

            *puVar2 = *(undefined4 *)(param_2 + 0x168);

            *(undefined4 **)(param_2 + 0x168) = puVar2;

            puVar2[4] = param_4;

            puVar2[5] = 0x20;

            puVar2 = (undefined4 *)main_ai_move_004033d0();

            *puVar2 = *(undefined4 *)(param_2 + 0x168);

            *(undefined4 **)(param_2 + 0x168) = puVar2;

            puVar2[1] = *pfVar1;

            puVar2[2] = pfVar1[1];

            puVar2[3] = pfVar1[2];

            puVar2[5] = 0x80;

            return;

          }

          goto LAB_00401da3;

        }

      }

      else {

        while (puVar3 = puVar2, puVar3 != (undefined4 *)0x0) {

          puVar2 = (undefined4 *)*puVar3;

          *puVar3 = DAT_00584194;

          DAT_00584194 = puVar3;

        }

        *(undefined4 *)(param_2 + 0x168) = 0;

        *(uint *)(param_2 + 0xd8) = *(uint *)(param_2 + 0xd8) & 0xfcffffff;

        if ((param_1 & 2) == 0) {

          if ((param_1 & 4) != 0) {

            puVar2 = (undefined4 *)main_ai_move_004033d0();

            *puVar2 = *(undefined4 *)(param_2 + 0x168);

            *(undefined4 **)(param_2 + 0x168) = puVar2;

            puVar2[4] = param_4;

            puVar2[5] = 0x20;

            main_ai_move_004016d0(param_2,pfVar1);

            return;

          }

          if ((param_1 & 1) != 0) {

            puVar2 = (undefined4 *)main_ai_move_004033d0();

            *puVar2 = *(undefined4 *)(param_2 + 0x168);

            *(undefined4 **)(param_2 + 0x168) = puVar2;

            puVar2[4] = param_4;

            puVar2[5] = 0x20;

            FUN_00401610(param_2,pfVar1);

            return;

          }

LAB_00401da3:

          puVar2 = (undefined4 *)main_ai_move_004033d0();

          *puVar2 = *(undefined4 *)(param_2 + 0x168);

          *(undefined4 **)(param_2 + 0x168) = puVar2;

          puVar2[1] = *pfVar1;

          puVar2[2] = pfVar1[1];

          puVar2[3] = pfVar1[2];

          puVar2[5] = 0x80;

          return;

        }

      }

      puVar2 = (undefined4 *)main_ai_move_004033d0();

      *puVar2 = *(undefined4 *)(param_2 + 0x168);

      *(undefined4 **)(param_2 + 0x168) = puVar2;

      pfVar5 = (float *)(puVar2 + 1);

      *pfVar5 = *pfVar1;

      puVar2[2] = pfVar1[1];

      fVar4 = pfVar1[2];

      goto LAB_00401cd9;

    }

  }

  while (puVar3 = puVar2, puVar3 != (undefined4 *)0x0) {

    puVar2 = (undefined4 *)*puVar3;

    *puVar3 = DAT_00584194;

    DAT_00584194 = puVar3;

  }

  *(undefined4 *)(param_2 + 0x168) = 0;

  *(uint *)(param_2 + 0xd8) = *(uint *)(param_2 + 0xd8) & 0xfcffffff;

  if ((param_1 & 2) != 0) {

    puVar2 = (undefined4 *)main_ai_move_004033d0();

    *puVar2 = *(undefined4 *)(param_2 + 0x168);

    *(undefined4 **)(param_2 + 0x168) = puVar2;

    puVar2[1] = *param_3;

    puVar2[2] = param_3[1];

    puVar2[3] = param_3[2];

    puVar2[4] = param_5;

    puVar2[5] = 0x80000080;

    return;

  }

  if ((param_1 & 4) != 0) {

    puVar2 = (undefined4 *)main_ai_move_004033d0();

    *puVar2 = *(undefined4 *)(param_2 + 0x168);

    *(undefined4 **)(param_2 + 0x168) = puVar2;

    puVar2[4] = param_4;

    puVar2[5] = 0x20;

    main_ai_move_004016d0(param_2,param_3);

    return;

  }

LAB_00401f0b:

  if ((param_1 & 1) == 0) {

    puVar2 = (undefined4 *)main_ai_move_004033d0();

    *puVar2 = *(undefined4 *)(param_2 + 0x168);

    *(undefined4 **)(param_2 + 0x168) = puVar2;

    puVar2[1] = *param_3;

    puVar2[2] = param_3[1];

    puVar2[3] = param_3[2];

    puVar2[5] = 0x80;

    return;

  }

  puVar2 = (undefined4 *)main_ai_move_004033d0();

  *puVar2 = *(undefined4 *)(param_2 + 0x168);

  *(undefined4 **)(param_2 + 0x168) = puVar2;

  puVar2[5] = 0x20;

  puVar2[4] = param_4;

  FUN_00401610(param_2,param_3);

  return;

}

/* ===== ai_fly_update_goal_2 @ 0x00401F80 ===== */
void ai_fly_update_goal_2(undefined4 param_1,undefined4 param_2,undefined4 param_3)



{

  ai_do_update_goal__FUiP6OBJECTP3P3Dff(1,param_1,param_2,param_3,0);

  return;

}

/* ===== ai_move_update_goal @ 0x00401FA0 ===== */
void ai_move_update_goal(undefined4 param_1,undefined4 param_2)



{

  ai_do_update_goal__FUiP6OBJECTP3P3Dff(0,param_1,param_2,0,0);

  return;

}

/* ===== ai_fly_update_goal_3 @ 0x00401FC0 ===== */
void ai_fly_update_goal_3(undefined4 param_1,undefined4 param_2,undefined4 param_3)



{

  ai_do_update_goal__FUiP6OBJECTP3P3Dff(2,param_1,param_3,0,param_2);

  return;

}

/* ===== FUN_00401fe0 @ 0x00401FE0 ===== */
/* PS2 candidate: ai_goal_complete (conf 0.353) */



undefined4 FUN_00401fe0(int param_1)



{

  int iVar1;

  uint uVar2;

  byte bVar3;

  float fVar4;

  int iVar5;

  float10 fVar6;

  

  iVar1 = *(int *)(param_1 + 0x168);

  if (iVar1 != 0) {

    uVar2 = *(uint *)(iVar1 + 0x14);

    if ((uVar2 & 0x400) == 0) {

      if ((uVar2 & 0x20) == 0) {

        if (((uVar2 & 0x800) != 0) && (iVar5 = FUN_00413880(param_1), iVar5 == 0)) {

          return 1;

        }

        if (((*(byte *)(iVar1 + 0x14) & 0x40) != 0) || (*(int *)(param_1 + 0x104) != 0)) {

          if ((ABS(*(float *)(param_1 + 0xa0) - *(float *)(iVar1 + 4)) <

               *(float *)(DAT_006330e4 + 0x1c0)) &&

             ((ABS(*(float *)(param_1 + 0xa4) - *(float *)(iVar1 + 8)) <

               *(float *)(DAT_006330e4 + 0x1c0) &&

              (fVar4 = *(float *)(DAT_006330e4 + 0x1c0) * 0.25,

              fVar6 = (float10)distancesq2d__FP3P3DT0(iVar1 + 4,param_1 + 0xa0),

              fVar6 < (float10)fVar4 * (float10)fVar4)))) {

            return 1;

          }

        }

        if (2.0 < ABS(*(float *)(iVar1 + 4) - *(float *)(param_1 + 0xa0))) {

          return 0;

        }

        if (ABS(*(float *)(iVar1 + 8) - *(float *)(param_1 + 0xa4)) <= 2.0) {

          if ((*(byte *)(iVar1 + 0x14) & 8) == 0) {

            return 1;

          }

          if (2.0 < ABS(*(float *)(iVar1 + 0xc) - *(float *)(param_1 + 0xa8))) {

            return 0;

          }

          return 1;

        }

        return 0;

      }

      fVar6 = (float10)FUN_0050a770(*(undefined4 *)(iVar1 + 0x10),*(undefined4 *)(param_1 + 200));

      bVar3 = (byte)((ushort)((ushort)(NAN(fVar6) || NAN((float10)0.0)) << 10) >> 8) |

              (byte)((ushort)((ushort)(fVar6 == (float10)0.0) << 0xe) >> 8);

    }

    else {

      bVar3 = *(float *)(iVar1 + 0x18) < 0.0 |

              (byte)((ushort)((ushort)(*(float *)(iVar1 + 0x18) == 0.0) << 0xe) >> 8);

    }

    if ((POPCOUNT(bVar3) & 1U) == 0) {

      return 0;

    }

  }

  return 1;

}

/* ===== ai_get_goal_location @ 0x00402140 ===== */
void ai_get_goal_location(int param_1,undefined4 *param_2)



{

  int iVar1;

  

  iVar1 = *(int *)(param_1 + 0x168);

  if (iVar1 != 0) {

    *param_2 = *(undefined4 *)(iVar1 + 4);

    param_2[1] = *(undefined4 *)(iVar1 + 8);

    param_2[2] = *(undefined4 *)(iVar1 + 0xc);

  }

  return;

}

/* ===== FUN_00402170 @ 0x00402170 ===== */
uint FUN_00402170(int param_1)



{

  int *piVar1;

  int iVar2;

  

  iVar2 = FUN_00401fe0(param_1);

  while (((iVar2 != 0 && (piVar1 = *(int **)(param_1 + 0x168), piVar1 != (int *)0x0)) &&

         ((*(byte *)(piVar1 + 5) & 0x10) == 0))) {

    *(int *)(param_1 + 0x168) = *piVar1;

    *piVar1 = (int)DAT_00584194;

    DAT_00584194 = piVar1;

    iVar2 = FUN_00401fe0(param_1);

  }

  if (*(int *)(param_1 + 0x168) != 0) {

    return (*(byte *)(*(int *)(param_1 + 0x168) + 0x14) & 0x20) >> 5;

  }

  return 1;

}

/* ===== FUN_004021e0 @ 0x004021E0 ===== */
bool FUN_004021e0(int param_1)



{

  int *piVar1;

  int iVar2;

  

  iVar2 = FUN_00401fe0(param_1);

  while (((iVar2 != 0 && (piVar1 = *(int **)(param_1 + 0x168), piVar1 != (int *)0x0)) &&

         ((*(byte *)(piVar1 + 5) & 0x10) == 0))) {

    *(int *)(param_1 + 0x168) = *piVar1;

    *piVar1 = (int)DAT_00584194;

    DAT_00584194 = piVar1;

    iVar2 = FUN_00401fe0(param_1);

  }

  return *(int *)(param_1 + 0x168) == 0;

}

/* ===== ai_move_goals_reinit @ 0x00402240 ===== */
/* PS2 candidate: ai_goal_process_nopath (conf 0.355) */



void ai_move_goals_reinit(undefined4 param_1)



{

  DAT_00584190 = 1;

  ai_goal_process(param_1);

  DAT_00584190 = 0;

  return;

}

/* ===== ObjectSetAnim @ 0x004034A0 ===== */
/* PS2 candidate: ObjectSetAnim (conf 0.75) */



void ObjectSetAnim(int param_1,int param_2,uint param_3,undefined4 param_4,undefined4 param_5,

                  float param_6)



{

  float fVar1;

  int iVar2;

  int *piVar3;

  undefined4 *puVar4;

  int *piVar5;

  undefined4 *puVar6;

  

  if (param_2 == 0xfe) {

    crt_sprintf(&DAT_00657400,s_Object__d_setting_AnimIdxNONE__a_00554068,

                *(undefined4 *)(param_1 + 4));

    FUN_0051ea20(&DAT_00657400);

    return;

  }

  fVar1 = param_6;

  if (DAT_00633118 == 0) {

    fVar1 = 0.0;

  }

  if (fVar1 == 0.0) {

    *(undefined4 *)(param_1 + 0x28) = 0;

    *(undefined4 *)(param_1 + 0x2c) = 0;

  }

  else {

    if (*(float *)(param_1 + 0x2c) < 0.9) {

      piVar3 = (int *)(param_1 + 0x10);

      piVar5 = (int *)(param_1 + 0x58);

      for (iVar2 = 9; iVar2 != 0; iVar2 = iVar2 + -1) {

        *piVar5 = *piVar3;

        piVar3 = piVar3 + 1;

        piVar5 = piVar5 + 1;

      }

      *(uint *)(param_1 + 0x78) = *(uint *)(param_1 + 0x78) | 0x100;

    }

    *(float *)(param_1 + 0x28) = fVar1;

    *(undefined4 *)(param_1 + 0x2c) = 0x3f800000;

  }

  *(int *)(param_1 + 0x10) = param_2;

  *(uint *)(param_1 + 0x30) = param_3 | 0x100;

  *(undefined4 *)(param_1 + 0x20) = param_4;

  *(undefined4 *)(param_1 + 0x24) = param_5;

  if (DAT_00633118 == 0) {

    param_6 = 0.0;

  }

  if (param_6 == 0.0) {

    *(undefined4 *)(param_1 + 0x4c) = 0;

    *(undefined4 *)(param_1 + 0x50) = 0;

  }

  else {

    if (*(float *)(param_1 + 0x50) < 0.9) {

      puVar4 = (undefined4 *)(param_1 + 0x34);

      puVar6 = (undefined4 *)(param_1 + 0x7c);

      for (iVar2 = 9; iVar2 != 0; iVar2 = iVar2 + -1) {

        *puVar6 = *puVar4;

        puVar4 = puVar4 + 1;

        puVar6 = puVar6 + 1;

      }

      *(uint *)(param_1 + 0x9c) = *(uint *)(param_1 + 0x9c) | 0x100;

    }

    *(float *)(param_1 + 0x4c) = param_6;

    *(undefined4 *)(param_1 + 0x50) = 0x3f800000;

  }

  *(undefined4 *)(param_1 + 0x44) = param_4;

  *(undefined4 *)(param_1 + 0x34) = 0xfe;

  *(undefined4 *)(param_1 + 0x54) = 0x100;

  *(undefined4 *)(param_1 + 0x48) = param_5;

  return;

}

/* ===== anim_select_check @ 0x004035D0 ===== */
/* PS2 candidate: ObjectSetBasicAnimLoop (conf 0.3) */



void anim_select_check(int param_1,int param_2)



{

  float fVar1;

  int iVar2;

  int *piVar3;

  undefined4 *puVar4;

  int *piVar5;

  undefined4 *puVar6;

  

  if (param_2 == 0xfe) {

    crt_sprintf(&DAT_00657400,s_Object__d_setting_AnimIdxNONE__a_00554068,

                *(undefined4 *)(param_1 + 4));

    FUN_0051ea20(&DAT_00657400);

    return;

  }

  fVar1 = 0.16666667;

  if (DAT_00633118 == 0) {

    fVar1 = 0.0;

  }

  if (fVar1 == 0.0) {

    *(undefined4 *)(param_1 + 0x28) = 0;

    *(undefined4 *)(param_1 + 0x2c) = 0;

  }

  else {

    if (*(float *)(param_1 + 0x2c) < 0.9) {

      piVar3 = (int *)(param_1 + 0x10);

      piVar5 = (int *)(param_1 + 0x58);

      for (iVar2 = 9; iVar2 != 0; iVar2 = iVar2 + -1) {

        *piVar5 = *piVar3;

        piVar3 = piVar3 + 1;

        piVar5 = piVar5 + 1;

      }

      *(uint *)(param_1 + 0x78) = *(uint *)(param_1 + 0x78) | 0x100;

    }

    *(float *)(param_1 + 0x28) = fVar1;

    *(undefined4 *)(param_1 + 0x2c) = 0x3f800000;

  }

  fVar1 = 0.16666667;

  *(int *)(param_1 + 0x10) = param_2;

  *(undefined4 *)(param_1 + 0x30) = 0x121;

  *(undefined4 *)(param_1 + 0x20) = 0;

  *(undefined4 *)(param_1 + 0x24) = 0;

  if (DAT_00633118 == 0) {

    fVar1 = 0.0;

  }

  if (fVar1 == 0.0) {

    *(undefined4 *)(param_1 + 0x4c) = 0;

    *(undefined4 *)(param_1 + 0x50) = 0;

  }

  else {

    if (*(float *)(param_1 + 0x50) < 0.9) {

      puVar4 = (undefined4 *)(param_1 + 0x34);

      puVar6 = (undefined4 *)(param_1 + 0x7c);

      for (iVar2 = 9; iVar2 != 0; iVar2 = iVar2 + -1) {

        *puVar6 = *puVar4;

        puVar4 = puVar4 + 1;

        puVar6 = puVar6 + 1;

      }

      *(uint *)(param_1 + 0x9c) = *(uint *)(param_1 + 0x9c) | 0x100;

    }

    *(float *)(param_1 + 0x4c) = fVar1;

    *(undefined4 *)(param_1 + 0x50) = 0x3f800000;

  }

  *(undefined4 *)(param_1 + 0x44) = 0;

  *(undefined4 *)(param_1 + 0x48) = 0;

  *(undefined4 *)(param_1 + 0x34) = 0xfe;

  *(undefined4 *)(param_1 + 0x54) = 0x100;

  return;

}

/* ===== anim_select_check2 @ 0x004036F0 ===== */
/* PS2 candidate: ObjectSetBasicAnimNoLoop (conf 0.301) */



void anim_select_check2(int param_1,int param_2)



{

  float fVar1;

  int iVar2;

  int *piVar3;

  undefined4 *puVar4;

  int *piVar5;

  undefined4 *puVar6;

  

  if (param_2 == 0xfe) {

    crt_sprintf(&DAT_00657400,s_Object__d_setting_AnimIdxNONE__a_00554068,

                *(undefined4 *)(param_1 + 4));

    FUN_0051ea20(&DAT_00657400);

    return;

  }

  fVar1 = 0.16666667;

  if (DAT_00633118 == 0) {

    fVar1 = 0.0;

  }

  if (fVar1 == 0.0) {

    *(undefined4 *)(param_1 + 0x28) = 0;

    *(undefined4 *)(param_1 + 0x2c) = 0;

  }

  else {

    if (*(float *)(param_1 + 0x2c) < 0.9) {

      piVar3 = (int *)(param_1 + 0x10);

      piVar5 = (int *)(param_1 + 0x58);

      for (iVar2 = 9; iVar2 != 0; iVar2 = iVar2 + -1) {

        *piVar5 = *piVar3;

        piVar3 = piVar3 + 1;

        piVar5 = piVar5 + 1;

      }

      *(uint *)(param_1 + 0x78) = *(uint *)(param_1 + 0x78) | 0x100;

    }

    *(float *)(param_1 + 0x28) = fVar1;

    *(undefined4 *)(param_1 + 0x2c) = 0x3f800000;

  }

  fVar1 = 0.16666667;

  *(int *)(param_1 + 0x10) = param_2;

  *(undefined4 *)(param_1 + 0x30) = 0x120;

  *(undefined4 *)(param_1 + 0x20) = 0;

  *(undefined4 *)(param_1 + 0x24) = 0;

  if (DAT_00633118 == 0) {

    fVar1 = 0.0;

  }

  if (fVar1 == 0.0) {

    *(undefined4 *)(param_1 + 0x4c) = 0;

    *(undefined4 *)(param_1 + 0x50) = 0;

  }

  else {

    if (*(float *)(param_1 + 0x50) < 0.9) {

      puVar4 = (undefined4 *)(param_1 + 0x34);

      puVar6 = (undefined4 *)(param_1 + 0x7c);

      for (iVar2 = 9; iVar2 != 0; iVar2 = iVar2 + -1) {

        *puVar6 = *puVar4;

        puVar4 = puVar4 + 1;

        puVar6 = puVar6 + 1;

      }

      *(uint *)(param_1 + 0x9c) = *(uint *)(param_1 + 0x9c) | 0x100;

    }

    *(float *)(param_1 + 0x4c) = fVar1;

    *(undefined4 *)(param_1 + 0x50) = 0x3f800000;

  }

  *(undefined4 *)(param_1 + 0x44) = 0;

  *(undefined4 *)(param_1 + 0x48) = 0;

  *(undefined4 *)(param_1 + 0x34) = 0xfe;

  *(undefined4 *)(param_1 + 0x54) = 0x100;

  return;

}

/* ===== ref_get_anode @ 0x00403810 ===== */
undefined4 ref_get_anode(int param_1,int param_2,int param_3)



{

  int iVar1;

  undefined4 uVar2;

  

  if (param_3 < *(int *)(param_2 + 0x450)) {

    if ((*(int *)(param_2 + 0x454) != 0) &&

       (iVar1 = *(int *)(*(int *)(param_2 + 0x454) + param_3 * 4), iVar1 != 0)) {

      if (*(int *)(*(int *)(param_1 + 0x54) + param_3 * 4) == 0) {

        if (*(int *)(param_1 + 0x28) != 0) {

          uVar2 = FUN_0053be00(*(int *)(param_1 + 0x28),0,iVar1);

          *(undefined4 *)(*(int *)(param_1 + 0x54) + param_3 * 4) = uVar2;

          return *(undefined4 *)(*(int *)(param_1 + 0x54) + param_3 * 4);

        }

        *(undefined4 *)(*(int *)(param_1 + 0x54) + param_3 * 4) = 0;

      }

      return *(undefined4 *)(*(int *)(param_1 + 0x54) + param_3 * 4);

    }

    FUN_0051ea20(s_Error__ref_get_anode____no_refna_005540a0);

  }

  return 0;

}

/* ===== ref_get_anode2 @ 0x00403890 ===== */
undefined4

ref_get_anode2(undefined4 param_1,float *param_2,int param_3,int param_4,int param_5,

              undefined4 param_6)



{

  undefined4 uVar1;

  int iVar2;

  undefined4 uVar3;

  int iVar4;

  float10 fVar5;

  float10 fVar6;

  undefined4 local_ac;

  undefined4 local_a8;

  undefined4 local_a4;

  undefined4 local_a0;

  undefined4 uStack_9c;

  undefined4 uStack_98;

  undefined4 local_94;

  undefined4 local_90;

  undefined4 local_8c;

  undefined1 local_88 [8];

  undefined4 local_80;

  undefined4 local_7c;

  undefined4 local_78;

  undefined4 local_70;

  undefined4 local_6c;

  undefined4 local_68;

  undefined4 local_60;

  undefined4 local_5c;

  undefined4 local_58;

  undefined1 auStack_44 [68];

  

  iVar2 = *(int *)(param_3 + 8);

  iVar4 = *(int *)(iVar2 + 8 + param_4 * 4);

  uVar3 = 0;

  if (*(int *)(iVar2 + 0x450) <= param_5) {

    return 0;

  }

  if ((*(int *)(iVar2 + 0x454) == 0) ||

     (iVar2 = *(int *)(*(int *)(iVar2 + 0x454) + param_5 * 4), iVar2 == 0)) {

    FUN_0051ea20(s_Error__ref_get_anode____no_refna_005540a0);

    return 0;

  }

  if (*(int *)(*(int *)(iVar4 + 0x54) + param_5 * 4) == 0) {

    if (*(int *)(iVar4 + 0x28) == 0) {

      uVar1 = 0;

    }

    else {

      uVar1 = FUN_0053be00(*(int *)(iVar4 + 0x28),0,iVar2);

    }

    *(undefined4 *)(*(int *)(iVar4 + 0x54) + param_5 * 4) = uVar1;

  }

  iVar2 = *(int *)(*(int *)(iVar4 + 0x54) + param_5 * 4);

  if (iVar2 == 0) {

    return 0;

  }

  if ((param_4 == *(int *)(param_3 + 0x10)) &&

     (*(int *)(*(int *)(*(int *)(*(int *)(param_3 + 8) + 8 + *(int *)(param_3 + 0x10) * 4) + 0x54) +

              param_5 * 4) != 0)) {

    iVar4 = param_5 * 0x44 + *(int *)(param_3 + 0x2dc);

  }

  else {

    uVar1 = FUN_0053ca70();

    iVar4 = ANM_NodeGetMat(iVar2,*(undefined4 *)(*(int *)(iVar2 + 0xc) + 0x10),uVar1);

    if (iVar4 == 0) goto LAB_00403980;

  }

  (*(code *)PTR_crt_matrix_mul_00580c18)(local_88,param_3 + 0x294,iVar4);

  uVar3 = 1;

LAB_00403980:

  local_ac = local_7c;

  local_a8 = local_6c;

  local_94 = local_80;

  local_a4 = local_5c;

  local_90 = local_70;

  local_a0 = local_78;

  local_8c = local_60;

  uStack_9c = local_68;

  uStack_98 = local_58;

  GEO_MatLookAt(local_88,&local_a0,&local_ac,&local_94);

  (*(code *)PTR_crt_matrix_copy_init_00580c1c)(auStack_44,local_88);

  FUN_0053d970(param_1,auStack_44);

  iVar2 = FUN_0053be60(iVar2);

  if (iVar2 != 0) {

    uVar1 = AddHud__4cHudP8cHudIcon_4(*(undefined4 *)(iVar2 + 0xc),param_6);

    fVar5 = (float10)FUN_0053be80(iVar2,uVar1);

    fVar5 = (float10)fptan(fVar5 * (float10)0.5);

    fVar6 = (float10)FUN_00515da0();

    fVar5 = (float10)fpatan((float10)(float)fVar5 / fVar6,(float10)1);

    *param_2 = (float)(fVar5 * (float10)114.59156);

  }

  return uVar3;

}

/* ===== FUN_00403a70 @ 0x00403A70 ===== */
int FUN_00403a70(int param_1,int param_2,int param_3)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  int *piVar4;

  int *piVar5;

  float10 fVar6;

  int local_8;

  int local_4;

  

  iVar3 = 0;

  local_8 = 0;

  local_4 = 2;

  piVar5 = (int *)(param_3 + 0x10);

  piVar4 = (int *)(param_1 + 0x10);

  do {

    if ((*piVar4 != 0xfe) && (iVar2 = *(int *)(*(int *)(param_1 + 8) + 8 + *piVar4 * 4), iVar2 != 0)

       ) {

      piVar5[-4] = iVar2;

      piVar1 = *(int **)(iVar2 + 0x28);

      *piVar1 = param_1;

      if ((*(byte *)(iVar2 + 8) & 1) == 0) {

        piVar5[-3] = *(int *)(iVar2 + 0x2c + param_2 * 4);

      }

      iVar2 = __ftol();

      *piVar5 = iVar2 + piVar1[4];

      if (iVar3 < 2) {

        piVar5[1] = 0;

        fVar6 = (float10)fcos((float10)(float)piVar4[7] * (float10)3.1415927);

        fVar6 = ((float10)1.0 - fVar6) * (float10)0.5;

        piVar5[2] = (int)(float)fVar6;

        if (fVar6 != (float10)0.0) {

          local_4 = 4;

        }

      }

      else {

        piVar5[1] = 1;

      }

      local_8 = local_8 + 1;

      piVar5 = piVar5 + 7;

    }

    iVar3 = iVar3 + 1;

    piVar4 = piVar4 + 9;

  } while (iVar3 < local_4);

  return local_8;

}

/* ===== BasicUsrAnmApply__FP9ObjectSetP14BasicUsrAnmDefPFP6OBJECTPvii_i @ 0x00403B50 ===== */
/* PS2 candidate: BasicUsrAnmApply__FP9ObjectSetP14BasicUsrAnmDefPFP6OBJECTPvii_i (conf 0.521) */



void BasicUsrAnmApply__FP9ObjectSetP14BasicUsrAnmDefPFP6OBJECTPvii_i(int param_1)



{

  int iVar1;

  int iVar2;

  int iVar3;

  undefined4 uVar4;

  undefined4 *puVar5;

  int iVar6;

  int iVar7;

  int *piVar8;

  undefined4 *puVar9;

  int local_7c;

  int local_78;

  int local_70 [3];

  undefined4 auStack_64 [25];

  

  if ((*(int *)(param_1 + 0x10) != 0xfe) && (*(int *)(param_1 + 8) != 0)) {

    iVar3 = FUN_00403a70(param_1,0,local_70);

    local_7c = *(int *)(param_1 + 0x2d8);

    if (local_7c != (*(undefined4 **)(param_1 + 8))[0x114]) {

      crt_sprintf(&DAT_00657400,s_Reference_point_mismatch__object_005540c4,

                  *(undefined4 *)(param_1 + 4),**(undefined4 **)(param_1 + 8));

      FUN_00425eb0(&DAT_00657400);

      iVar6 = *(int *)(*(int *)(param_1 + 8) + 0x450);

      if (iVar6 < local_7c) {

        local_7c = iVar6;

      }

    }

    if (iVar3 < 2) {

      if ((iVar3 != 0) && (0 < local_7c)) {

        local_78 = 0;

        iVar3 = 0;

        do {

          iVar6 = *(int *)(param_1 + 8);

          if (*(int *)(*(int *)(iVar6 + 0x454) + iVar3 * 4) != 0) {

            if (iVar3 < *(int *)(iVar6 + 0x450)) {

              if ((*(int *)(iVar6 + 0x454) == 0) ||

                 (iVar6 = *(int *)(*(int *)(iVar6 + 0x454) + iVar3 * 4), iVar6 == 0)) {

                FUN_0051ea20(s_Error__ref_get_anode____no_refna_005540a0);

                goto LAB_00403d93;

              }

              if (*(int *)(*(int *)(local_70[0] + 0x54) + iVar3 * 4) == 0) {

                if (*(int *)(local_70[0] + 0x28) == 0) {

                  *(undefined4 *)(*(int *)(local_70[0] + 0x54) + iVar3 * 4) = 0;

                  goto LAB_00403d7e;

                }

                uVar4 = FUN_0053be00(*(int *)(local_70[0] + 0x28),0,iVar6);

                *(undefined4 *)(*(int *)(local_70[0] + 0x54) + iVar3 * 4) = uVar4;

                uVar4 = *(undefined4 *)(*(int *)(local_70[0] + 0x54) + iVar3 * 4);

              }

              else {

LAB_00403d7e:

                uVar4 = *(undefined4 *)(*(int *)(local_70[0] + 0x54) + iVar3 * 4);

              }

            }

            else {

LAB_00403d93:

              uVar4 = 0;

            }

            puVar5 = (undefined4 *)

                     ANM_NodeGetMat(uVar4,auStack_64[1],*(undefined4 *)(param_1 + 0xc));

            if (puVar5 == (undefined4 *)0x0) {

              FUN_0053d9e0(*(int *)(param_1 + 0x2dc) + local_78);

            }

            else {

              puVar9 = (undefined4 *)(*(int *)(param_1 + 0x2dc) + local_78);

              for (iVar6 = 0x11; iVar6 != 0; iVar6 = iVar6 + -1) {

                *puVar9 = *puVar5;

                puVar5 = puVar5 + 1;

                puVar9 = puVar9 + 1;

              }

            }

          }

          iVar3 = iVar3 + 1;

          local_78 = local_78 + 0x44;

        } while (iVar3 < local_7c);

      }

    }

    else {

      iVar6 = 0;

      if (0 < local_7c) {

        local_78 = 0;

        do {

          if (*(int *)(*(int *)(*(int *)(param_1 + 8) + 0x454) + iVar6 * 4) != 0) {

            if (iVar3 != 0) {

              puVar5 = auStack_64 + iVar3 * 7;

              iVar7 = iVar3;

              do {

                iVar1 = puVar5[-10];

                puVar5 = puVar5 + -7;

                if (iVar6 < *(int *)(*(int *)(param_1 + 8) + 0x450)) {

                  iVar2 = *(int *)(*(int *)(param_1 + 8) + 0x454);

                  if ((iVar2 == 0) || (iVar2 = *(int *)(iVar2 + iVar6 * 4), iVar2 == 0)) {

                    FUN_0051ea20(s_Error__ref_get_anode____no_refna_005540a0);

                    goto LAB_00403c86;

                  }

                  if (*(int *)(*(int *)(iVar1 + 0x54) + iVar6 * 4) == 0) {

                    if (*(int *)(iVar1 + 0x28) == 0) {

                      *(undefined4 *)(*(int *)(iVar1 + 0x54) + iVar6 * 4) = 0;

                      goto LAB_00403c71;

                    }

                    uVar4 = FUN_0053be00(*(int *)(iVar1 + 0x28),0,iVar2);

                    *(undefined4 *)(*(int *)(iVar1 + 0x54) + iVar6 * 4) = uVar4;

                    uVar4 = *(undefined4 *)(*(int *)(iVar1 + 0x54) + iVar6 * 4);

                  }

                  else {

LAB_00403c71:

                    uVar4 = *(undefined4 *)(*(int *)(iVar1 + 0x54) + iVar6 * 4);

                  }

                }

                else {

LAB_00403c86:

                  uVar4 = 0;

                }

                iVar7 = iVar7 + -1;

                *puVar5 = uVar4;

              } while (iVar7 != 0);

            }

            puVar5 = (undefined4 *)

                     ANM_BlendedNodeGetMat(local_70,iVar3,*(undefined4 *)(param_1 + 0xc));

            if (puVar5 == (undefined4 *)0x0) {

              FUN_0053d9e0(*(int *)(param_1 + 0x2dc) + local_78);

            }

            else {

              puVar9 = (undefined4 *)(*(int *)(param_1 + 0x2dc) + local_78);

              for (iVar7 = 0x11; iVar7 != 0; iVar7 = iVar7 + -1) {

                *puVar9 = *puVar5;

                puVar5 = puVar5 + 1;

                puVar9 = puVar9 + 1;

              }

            }

          }

          iVar6 = iVar6 + 1;

          local_78 = local_78 + 0x44;

        } while (iVar6 < local_7c);

      }

    }

    piVar8 = *(int **)(*(int *)(param_1 + 8) + 0x45c);

    for (iVar3 = *(int *)(*(int *)(param_1 + 8) + 0x458); iVar3 != 0; iVar3 = iVar3 + -1) {

      iVar6 = *piVar8;

      if ((-1 < iVar6) && (iVar6 < local_7c)) {

        iVar6 = iVar6 * 0x44 + *(int *)(param_1 + 0x2dc);

        (*(code *)PTR_crt_matrix_mul_00580c18)(iVar6,iVar6,piVar8 + 1);

      }

      piVar8 = piVar8 + 0x12;

    }

  }

  return;

}

/* ===== ObjectUpdateSpeedDist @ 0x00403E40 ===== */
void ObjectUpdateSpeedDist(int param_1,undefined4 param_2)



{

  if (*(int *)(param_1 + 8) != 0) {

    *(undefined4 *)(param_1 + 0x24) = param_2;

  }

  return;

}

/* ===== object_animate_process @ 0x00403E60 ===== */
/* PS2 candidate: object_animate_process (conf 0.407) */



void object_animate_process(int *param_1,float param_2)



{

  float fVar1;

  float fVar2;

  uint uVar3;

  float *pfVar4;

  bool bVar5;

  uint uVar6;

  int iVar7;

  int *piVar8;

  undefined4 uVar9;

  uint *puVar10;

  undefined4 uVar11;

  int local_8;

  

  uVar9 = 0;

  if (param_1[2] == 0) {

    return;

  }

  bVar5 = false;

  piVar8 = param_1 + 4;

  local_8 = 4;

  do {

    if ((param_2 != 0.0) || ((piVar8[8] & 0x100U) != 0)) {

      uVar3 = piVar8[8];

      piVar8[8] = uVar3 & 0xfffffeff;

      bVar5 = true;

      if ((*piVar8 != 0xfe) &&

         (pfVar4 = *(float **)(param_1[2] + 8 + *piVar8 * 4), pfVar4 != (float *)0x0)) {

        fVar1 = 1.0;

        if ((float)piVar8[5] != 0.0) {

          fVar1 = (float)param_1[piVar8[4] + 0x42] / (float)piVar8[5];

        }

        if ((uVar3 & 0x10) != 0) {

          fVar1 = -fVar1;

        }

        if ((uVar3 & 0xc) != 0) {

          piVar8[8] = uVar3 & 0xfffffef7;

          param_2 = 0.0;

          piVar8[3] = 0;

        }

        if ((char)piVar8[8] < '\0') {

          if (0.0 <= fVar1) {

            piVar8[1] = (int)(*pfVar4 * (float)piVar8[1]);

          }

          else {

            piVar8[1] = (int)*pfVar4;

          }

          piVar8[8] = piVar8[8] & 0xffffff7f;

          param_2 = 0.0;

          piVar8[3] = 0;

        }

        if ((piVar8[8] & 0x20U) != 0) {

          if (0.0 <= fVar1) {

            piVar8[1] = piVar8[3];

          }

          else {

            piVar8[1] = (int)(*pfVar4 - (float)piVar8[3]);

          }

          piVar8[8] = piVar8[8] & 0xffffffdf;

        }

        if ((piVar8[8] & 0x40U) != 0) {

          if (fVar1 <= 0.0) {

            piVar8[1] = piVar8[3];

          }

          else {

            piVar8[1] = (int)(*pfVar4 - (float)piVar8[3]);

          }

          piVar8[8] = piVar8[8] & 0xffffffbf;

        }

        uVar3 = piVar8[8];

        uVar6 = uVar3 & 0xfffffffd;

        piVar8[2] = piVar8[1];

        fVar2 = fVar1 * param_2 + (float)piVar8[1];

        piVar8[8] = uVar6;

        piVar8[1] = (int)fVar2;

        piVar8[3] = 0;

        if (0.0 <= fVar1) {

          if (*pfVar4 <= fVar2) {

            piVar8[8] = uVar6 | 2;

            if (*pfVar4 <= fVar2) {

              do {

                fVar1 = (float)piVar8[1];

                fVar2 = *pfVar4;

                piVar8[1] = (int)(fVar1 - fVar2);

              } while (*pfVar4 <= fVar1 - fVar2);

            }

            piVar8[3] = piVar8[1];

            if ((uVar3 & 1) == 0) {

              piVar8[1] = (int)*pfVar4;

            }

          }

        }

        else if (fVar2 < 0.0) {

          piVar8[8] = uVar6 | 2;

          do {

            fVar1 = *pfVar4 + (float)piVar8[1];

            piVar8[1] = (int)fVar1;

          } while (fVar1 < 0.0);

          piVar8[3] = (int)(*pfVar4 - fVar1);

          if ((uVar3 & 1) == 0) {

            piVar8[1] = 0;

          }

        }

        if (((0.0 < (float)piVar8[7]) && ((float)piVar8[6] != 0.0)) &&

           (fVar1 = (float)piVar8[7] - param_2 / (float)piVar8[6], piVar8[7] = (int)fVar1,

           fVar1 < 0.0)) {

          piVar8[7] = 0;

        }

      }

    }

    piVar8 = piVar8 + 9;

    local_8 = local_8 + -1;

  } while (local_8 != 0);

  if (!bVar5) {

    return;

  }

  iVar7 = FUN_0053ca70();

  param_1[3] = iVar7;

  BasicUsrAnmApply__FP9ObjectSetP14BasicUsrAnmDefPFP6OBJECTPvii_i(param_1);

  if (param_1[4] == 0xfe) {

    return;

  }

  pfVar4 = *(float **)(param_1[2] + 8 + param_1[4] * 4);

  if (pfVar4 == (float *)0x0) {

    return;

  }

  puVar10 = (uint *)0x0;

  if ((param_1[0x78] == 2) && (*param_1 != 0)) {

    puVar10 = *(uint **)(param_1[0x40] + 0x7c);

  }

  piVar8 = (int *)pfVar4[9];

  if ((piVar8 == (int *)0x0) && (puVar10 == (uint *)0x0)) {

    return;

  }

  fVar1 = (float)param_1[5] - (float)param_1[6];

  if (fVar1 < 0.0) {

    if (*pfVar4 * 0.5 < -fVar1) {

      uVar11 = 0;

      uVar9 = 1;

      goto LAB_00404137;

    }

  }

  else {

    if (fVar1 <= *pfVar4 * 0.5) {

      uVar11 = 0;

      goto LAB_00404137;

    }

    uVar9 = 1;

  }

  uVar11 = 1;

LAB_00404137:

  if ((piVar8 != (int *)0x0) && (local_8 = 0, 0 < *piVar8)) {

    param_2 = 0.0;

    do {

      obj_impact_effects(param_1,pfVar4,uVar11,uVar9,(int)param_2 + 4 + (int)piVar8);

      param_2 = (float)((int)param_2 + 0x20);

      piVar8 = (int *)pfVar4[9];

      local_8 = local_8 + 1;

    } while (local_8 < *piVar8);

  }

  if (puVar10 != (uint *)0x0) {

    do {

      obj_impact_effects(param_1,pfVar4,uVar11,uVar9,puVar10);

      uVar3 = *puVar10;

      puVar10 = puVar10 + 8;

    } while ((uVar3 & 0x4000) == 0);

  }

  return;

}

/* ===== ANM_DumpCluster @ 0x004041F0 ===== */
/* PS2 candidate: dialog_level_is_base (conf 0.468) */



void ANM_DumpCluster(void)



{

  return;

}

/* ===== FUN_00404200 @ 0x00404200 ===== */
float10 FUN_00404200(int param_1)



{

  float *pfVar1;

  

  if (*(int *)(param_1 + 0x10) == 0xfe) {

    return (float10)0.0;

  }

  pfVar1 = *(float **)(*(int *)(param_1 + 8) + 8 + *(int *)(param_1 + 0x10) * 4);

  if (pfVar1 == (float *)0x0) {

    return (float10)0.0;

  }

  return (float10)*pfVar1;

}

/* ===== collgrid_collision_test @ 0x00404230 ===== */
void collgrid_collision_test(int param_1,int param_2)



{

  float *pfVar1;

  float *pfVar2;

  float *pfVar3;

  int iVar4;

  int iVar5;

  uint uVar6;

  float *pfVar7;

  int local_18;

  int local_14;

  undefined4 local_10;

  undefined4 local_c;

  undefined4 *local_8;

  int local_4;

  

  if (*(int *)(param_1 + 0x28) != 0) {

    iVar5 = *(int *)(param_1 + 0xc) + param_2 * 0x24;

    local_4 = *(int *)(iVar5 + 0x20);

    pfVar7 = (float *)(*(int *)(param_1 + 0x28) + *(int *)(iVar5 + 0x14) * 0xc);

    if (local_4 != 0) {

      local_8 = (undefined4 *)(*(int *)(iVar5 + 0x1c) * 0x50 + param_1 + 0x84);

      do {

        local_c = *local_8;

        local_10 = 0xffff;

        iVar5 = collgrid_00430e10(&local_c,&local_10,&local_14,&local_18,&param_2);

        while (iVar5 != 0) {

          iVar5 = *(int *)(param_1 + 0x34);

          iVar4 = *(int *)(param_1 + 0x14);

          uVar6 = (uint)*(ushort *)(iVar5 + param_2 * 2);

          pfVar1 = (float *)(iVar4 + (uint)*(ushort *)(iVar5 + local_14 * 2) * 0xc);

          pfVar2 = (float *)(iVar4 + (uint)*(ushort *)(iVar5 + local_18 * 2) * 0xc);

          pfVar3 = (float *)(iVar4 + uVar6 * 0xc);

          *pfVar7 = (pfVar2[1] - pfVar1[1]) * (*(float *)(iVar4 + 8 + uVar6 * 0xc) - pfVar1[2]) -

                    (pfVar2[2] - pfVar1[2]) * (pfVar3[1] - pfVar1[1]);

          pfVar7[1] = (pfVar2[2] - pfVar1[2]) * (*pfVar3 - *pfVar1) -

                      (pfVar3[2] - pfVar1[2]) * (*pfVar2 - *pfVar1);

          pfVar7[2] = (*pfVar2 - *pfVar1) * (pfVar3[1] - pfVar1[1]) -

                      (pfVar2[1] - pfVar1[1]) * (*pfVar3 - *pfVar1);

          iVar5 = collgrid_00430e10(&local_c,&local_10,&local_14,&local_18,&param_2);

          pfVar7 = pfVar7 + 3;

        }

        local_8 = local_8 + 0x14;

        local_4 = local_4 + -1;

      } while (local_4 != 0);

    }

  }

  return;

}

/* ===== FUN_004043a0 @ 0x004043A0 ===== */
void FUN_004043a0(int param_1)



{

  int iVar1;

  int iVar2;

  

  if (*(int *)(param_1 + 0x28) != 0) {

    iVar1 = *(int *)(param_1 + 8);

    iVar2 = 0;

    if (0 < iVar1) {

      do {

        (*(code *)PTR_collgrid_collision_test_00554058)(param_1,iVar2);

        iVar2 = iVar2 + 1;

      } while (iVar2 < iVar1);

    }

  }

  return;

}

/* ===== S_maxobj_create_vertex_normals @ 0x004043D0 ===== */
/* PS2 candidate: S_maxobj_create_vertex_normals (conf 0.819) */



void S_maxobj_create_vertex_normals(int param_1,int param_2,int param_3)



{

  int iVar1;

  int iVar2;

  ushort uVar3;

  float fVar4;

  ushort *puVar5;

  float *pfVar6;

  ushort *puVar7;

  int iVar8;

  uint uVar9;

  float fVar10;

  

  if ((*(int *)(param_1 + 0x2c) != 0) && (*(int *)(param_1 + 0x28) != 0)) {

    iVar1 = *(int *)(param_1 + 0xc) + param_2 * 0x24;

    iVar2 = *(int *)(param_1 + 0x28) + *(int *)(iVar1 + 0x14) * 0xc;

    pfVar6 = (float *)(*(int *)(param_1 + 0x2c) + *(int *)(iVar1 + 8) * 0xc);

    puVar5 = (ushort *)(*(int *)(param_1 + 0x20) + *(int *)(iVar1 + 0x10) * 2);

    for (iVar8 = *(int *)(iVar1 + 0xc); iVar8 != 0; iVar8 = iVar8 + -1) {

      uVar9 = (uint)*puVar5;

      puVar7 = puVar5 + 1;

      if (uVar9 != 0) {

        uVar3 = *puVar7;

        puVar7 = puVar5 + 2;

        iVar1 = iVar2 + (uint)uVar3 * 0xc;

        *pfVar6 = *(float *)(iVar2 + (uint)uVar3 * 0xc);

        pfVar6[1] = *(float *)(iVar1 + 4);

        pfVar6[2] = *(float *)(iVar1 + 8);

        while (uVar9 = uVar9 - 1, uVar9 != 0) {

          uVar3 = *puVar7;

          puVar7 = puVar7 + 1;

          iVar1 = iVar2 + (uint)uVar3 * 0xc;

          *pfVar6 = *pfVar6 + *(float *)(iVar2 + (uint)uVar3 * 0xc);

          pfVar6[1] = *(float *)(iVar1 + 4) + pfVar6[1];

          pfVar6[2] = *(float *)(iVar1 + 8) + pfVar6[2];

        }

      }

      if (param_3 != 0) {

        fVar10 = pfVar6[1] * pfVar6[1] + *pfVar6 * *pfVar6 + pfVar6[2] * pfVar6[2];

        fVar4 = 0.0;

        if (fVar10 != 0.0) {

          fVar10 = (float)((&DAT_005f0a18)[(uint)fVar10 >> 8 & 0xffff] |

                          ((int)fVar10 + 0xc0800000U >> 1) + 0x3f800000 & 0x7f800000);

          fVar4 = 0.0;

          if (0.0 < fVar10) {

            fVar4 = 1.0 / fVar10;

          }

        }

        *pfVar6 = fVar4 * *pfVar6;

        pfVar6[1] = fVar4 * pfVar6[1];

        pfVar6[2] = fVar4 * pfVar6[2];

      }

      pfVar6 = pfVar6 + 3;

      puVar5 = puVar7;

    }

  }

  return;

}

/* ===== objdata_create_vertex_normals @ 0x00404530 ===== */
/* PS2 candidate: objdata_create_vertex_normals (conf 0.577) */



void objdata_create_vertex_normals(int param_1,undefined4 param_2)



{

  int iVar1;

  int iVar2;

  

  if ((*(int *)(param_1 + 0x2c) != 0) && (*(int *)(param_1 + 0x28) != 0)) {

    iVar1 = *(int *)(param_1 + 8);

    iVar2 = 0;

    if (0 < iVar1) {

      do {

        (*(code *)PTR_S_maxobj_create_vertex_normals_0055405c)(param_1,iVar2,param_2);

        iVar2 = iVar2 + 1;

      } while (iVar2 < iVar1);

    }

  }

  return;

}

/* ===== FUN_00404570 @ 0x00404570 ===== */
/* PS2 candidate: S_TriCalcGradients (conf 0.605) */



void FUN_00404570(float *param_1,float *param_2,int param_3,int param_4,int param_5,int param_6)



{

  float *pfVar1;

  float *pfVar2;

  float *pfVar3;

  float *pfVar4;

  float *pfVar5;

  float *pfVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  int iVar11;

  int iVar12;

  float fVar13;

  float fVar14;

  float fVar15;

  

  iVar11 = *(int *)(param_3 + 0x34);

  iVar12 = *(int *)(param_3 + 0x14);

  pfVar1 = (float *)(iVar12 + (uint)*(ushort *)(iVar11 + param_4 * 2) * 0xc);

  pfVar2 = (float *)(iVar12 + (uint)*(ushort *)(iVar11 + param_5 * 2) * 0xc);

  pfVar3 = (float *)(iVar12 + (uint)*(ushort *)(iVar11 + param_6 * 2) * 0xc);

  iVar11 = *(int *)(param_3 + 0x3c);

  fVar7 = *pfVar2;

  pfVar4 = (float *)(iVar11 + 4 + param_5 * 8);

  fVar8 = *pfVar1;

  pfVar5 = (float *)(iVar11 + 4 + param_4 * 8);

  fVar14 = *(float *)(iVar11 + param_5 * 8) - *(float *)(iVar11 + param_4 * 8);

  fVar9 = *pfVar3;

  pfVar6 = (float *)(iVar11 + 4 + param_6 * 8);

  fVar10 = *pfVar1;

  fVar15 = *(float *)(iVar11 + param_6 * 8) - *(float *)(iVar11 + param_4 * 8);

  fVar13 = (*pfVar6 - *pfVar5) * fVar14 - fVar15 * (*pfVar4 - *pfVar5);

  if (1e-12 < ABS(fVar13)) {

    fVar13 = 1.0 / fVar13;

    *param_1 = -(((fVar9 - fVar10) * (*pfVar4 - *pfVar5) - (*pfVar6 - *pfVar5) * (fVar7 - fVar8)) *

                fVar13);

    *param_2 = -(fVar13 * (fVar15 * (fVar7 - fVar8) - (fVar9 - fVar10) * fVar14));

  }

  fVar7 = pfVar2[1];

  fVar8 = pfVar1[1];

  fVar14 = *(float *)(iVar11 + param_5 * 8) - *(float *)(iVar11 + param_4 * 8);

  fVar9 = pfVar3[1];

  fVar10 = pfVar1[1];

  fVar15 = *(float *)(iVar11 + param_6 * 8) - *(float *)(iVar11 + param_4 * 8);

  fVar13 = (*pfVar6 - *pfVar5) * fVar14 - fVar15 * (*pfVar4 - *pfVar5);

  if (1e-12 < ABS(fVar13)) {

    fVar13 = 1.0 / fVar13;

    param_1[1] = -(((fVar9 - fVar10) * (*pfVar4 - *pfVar5) - (*pfVar6 - *pfVar5) * (fVar7 - fVar8))

                  * fVar13);

    param_2[1] = -(fVar13 * (fVar15 * (fVar7 - fVar8) - (fVar9 - fVar10) * fVar14));

  }

  fVar7 = pfVar2[2];

  fVar8 = pfVar1[2];

  fVar14 = *(float *)(iVar11 + param_5 * 8) - *(float *)(iVar11 + param_4 * 8);

  fVar9 = pfVar3[2];

  fVar10 = pfVar1[2];

  fVar15 = *(float *)(iVar11 + param_6 * 8) - *(float *)(iVar11 + param_4 * 8);

  fVar13 = (*pfVar6 - *pfVar5) * fVar14 - fVar15 * (*pfVar4 - *pfVar5);

  if (1e-12 < ABS(fVar13)) {

    fVar13 = 1.0 / fVar13;

    param_1[2] = -(((fVar9 - fVar10) * (*pfVar4 - *pfVar5) - (*pfVar6 - *pfVar5) * (fVar7 - fVar8))

                  * fVar13);

    param_2[2] = -(fVar13 * (fVar15 * (fVar7 - fVar8) - (fVar9 - fVar10) * fVar14));

  }

  return;

}

/* ===== collgrid_collide_b @ 0x004047C0 ===== */
void collgrid_collide_b(int param_1,int param_2,int param_3,int param_4)



{

  float fVar1;

  float *pfVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  uint uVar6;

  int iVar7;

  int iVar8;

  float fVar9;

  float *pfVar10;

  undefined4 *puVar11;

  undefined4 local_24;

  undefined4 local_20;

  int local_1c;

  float local_18;

  float fStack_14;

  float fStack_10;

  float local_c;

  float fStack_8;

  float fStack_4;

  

  iVar4 = param_4;

  iVar3 = param_3;

  iVar5 = param_1;

  iVar8 = param_2 * 0x50 + 0x74 + param_1;

  puVar11 = (undefined4 *)(param_3 + *(int *)(iVar8 + 0x14) * 0xc);

  for (uVar6 = *(int *)(iVar8 + 0x18) * 3 & 0x3fffffff; uVar6 != 0; uVar6 = uVar6 - 1) {

    *puVar11 = 0;

    puVar11 = puVar11 + 1;

  }

  for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {

    *(undefined1 *)puVar11 = 0;

    puVar11 = (undefined4 *)((int)puVar11 + 1);

  }

  puVar11 = (undefined4 *)(param_4 + *(int *)(iVar8 + 0x14) * 0xc);

  for (uVar6 = *(int *)(iVar8 + 0x18) * 3 & 0x3fffffff; uVar6 != 0; uVar6 = uVar6 - 1) {

    *puVar11 = 0;

    puVar11 = puVar11 + 1;

  }

  for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {

    *(undefined1 *)puVar11 = 0;

    puVar11 = (undefined4 *)((int)puVar11 + 1);

  }

  local_20 = *(undefined4 *)(iVar8 + 0x10);

  local_24 = 0xffff;

  local_1c = iVar8;

  iVar7 = collgrid_00430e10(&local_20,&local_24,&param_3,&param_1,&param_2);

  while (iVar7 != 0) {

    (*(code *)PTR_FUN_00554060)(&local_18,&local_c,iVar5,param_3,param_1,param_2);

    *(float *)(iVar3 + param_3 * 0xc) = local_18 + *(float *)(iVar3 + param_3 * 0xc);

    *(float *)(iVar3 + 4 + param_3 * 0xc) = fStack_14 + *(float *)(iVar3 + 4 + param_3 * 0xc);

    *(float *)(iVar3 + 8 + param_3 * 0xc) = fStack_10 + *(float *)(iVar3 + 8 + param_3 * 0xc);

    *(float *)(iVar3 + param_1 * 0xc) = local_18 + *(float *)(iVar3 + param_1 * 0xc);

    *(float *)(iVar3 + 4 + param_1 * 0xc) = fStack_14 + *(float *)(iVar3 + 4 + param_1 * 0xc);

    *(float *)(iVar3 + 8 + param_1 * 0xc) = fStack_10 + *(float *)(iVar3 + 8 + param_1 * 0xc);

    *(float *)(iVar3 + param_2 * 0xc) = local_18 + *(float *)(iVar3 + param_2 * 0xc);

    *(float *)(iVar3 + 4 + param_2 * 0xc) = fStack_14 + *(float *)(iVar3 + 4 + param_2 * 0xc);

    *(float *)(iVar3 + 8 + param_2 * 0xc) = fStack_10 + *(float *)(iVar3 + 8 + param_2 * 0xc);

    *(float *)(iVar4 + param_3 * 0xc) = local_c + *(float *)(iVar4 + param_3 * 0xc);

    *(float *)(iVar4 + 4 + param_3 * 0xc) = fStack_8 + *(float *)(iVar4 + 4 + param_3 * 0xc);

    pfVar10 = (float *)(iVar4 + 8 + param_3 * 0xc);

    *pfVar10 = fStack_4 + *pfVar10;

    *(float *)(iVar4 + param_1 * 0xc) = local_c + *(float *)(iVar4 + param_1 * 0xc);

    *(float *)(iVar4 + 4 + param_1 * 0xc) = fStack_8 + *(float *)(iVar4 + 4 + param_1 * 0xc);

    *(float *)(iVar4 + 8 + param_1 * 0xc) = fStack_4 + *(float *)(iVar4 + 8 + param_1 * 0xc);

    *(float *)(iVar4 + param_2 * 0xc) = local_c + *(float *)(iVar4 + param_2 * 0xc);

    *(float *)(iVar4 + 4 + param_2 * 0xc) = fStack_8 + *(float *)(iVar4 + 4 + param_2 * 0xc);

    *(float *)(iVar4 + 8 + param_2 * 0xc) = fStack_4 + *(float *)(iVar4 + 8 + param_2 * 0xc);

    iVar7 = collgrid_00430e10(&local_20,&local_24,&param_3,&param_1,&param_2);

  }

  iVar5 = *(int *)(iVar8 + 0x14) * 0xc;

  pfVar10 = (float *)(iVar3 + iVar5);

  pfVar2 = (float *)(iVar4 + iVar5);

  for (iVar8 = *(int *)(iVar8 + 0x18); iVar8 != 0; iVar8 = iVar8 + -1) {

    fVar9 = pfVar10[1] * pfVar10[1] + pfVar10[2] * pfVar10[2] + *pfVar10 * *pfVar10;

    fVar1 = 0.0;

    if (fVar9 != 0.0) {

      fVar9 = (float)((&DAT_005f0a18)[(uint)fVar9 >> 8 & 0xffff] |

                     ((int)fVar9 + 0xc0800000U >> 1) + 0x3f800000 & 0x7f800000);

      fVar1 = 0.0;

      if (0.0 < fVar9) {

        fVar1 = 1.0 / fVar9;

      }

    }

    *pfVar10 = fVar1 * *pfVar10;

    pfVar10[1] = fVar1 * pfVar10[1];

    pfVar10[2] = fVar1 * pfVar10[2];

    fVar9 = pfVar2[1] * pfVar2[1] + pfVar2[2] * pfVar2[2] + *pfVar2 * *pfVar2;

    fVar1 = 0.0;

    if (fVar9 != 0.0) {

      fVar9 = (float)((&DAT_005f0a18)[(uint)fVar9 >> 8 & 0xffff] |

                     ((int)fVar9 + 0xc0800000U >> 1) + 0x3f800000 & 0x7f800000);

      fVar1 = 0.0;

      if (0.0 < fVar9) {

        fVar1 = 1.0 / fVar9;

      }

    }

    pfVar10 = pfVar10 + 3;

    *pfVar2 = fVar1 * *pfVar2;

    pfVar2[1] = fVar1 * pfVar2[1];

    pfVar2[2] = fVar1 * pfVar2[2];

    pfVar2 = pfVar2 + 3;

  }

  return;

}

/* ===== obj_impact_effects @ 0x00404D70 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void obj_impact_effects(int param_1,undefined4 param_2,int param_3,int param_4,uint *param_5)



{

  float fVar1;

  uint uVar2;

  float fVar3;

  undefined4 *puVar4;

  int iVar5;

  char cVar6;

  uint uVar7;

  float10 fVar8;

  undefined4 uVar9;

  undefined1 local_30 [16];

  uint local_20;

  int local_1c;

  

  uVar2 = *param_5;

  if (param_4 != 0) {

    *param_5 = uVar2 ^ 0x8000;

  }

  cVar6 = (char)(uVar2 >> 8);

  if ((uVar2 & 2) == 0) {

    if (((uVar2 & 4) != 0) && (-1 < cVar6)) {

      return;

    }

  }

  else if (cVar6 < '\0') {

    return;

  }

  fVar3 = (float)param_5[1];

  fVar1 = *(float *)(param_1 + 0x18);

  if (param_3 == 0) {

    if (param_4 == 0) {

      if (fVar3 <= fVar1) {

        return;

      }

      if (*(float *)(param_1 + 0x14) < fVar3) {

        return;

      }

    }

    else if ((fVar3 <= fVar1) && (*(float *)(param_1 + 0x14) < fVar3)) {

      return;

    }

  }

  else {

    if (param_4 == 0) {

      if (fVar1 <= fVar3) {

        return;

      }

    }

    else if (fVar3 < fVar1) goto LAB_00404e2f;

    if (*(float *)(param_1 + 0x14) < fVar3 == (*(float *)(param_1 + 0x14) == fVar3)) {

      return;

    }

  }

LAB_00404e2f:

  if ((*(uint *)(param_1 + 0xd8) & 0x100000) == 0) {

    puVar4 = (undefined4 *)obj_material_names(param_1);

    if ((puVar4 == (undefined4 *)0x0) ||

       ((((iVar5 = FUN_00545650(*puVar4,s_B_smartbrick_0055416c), iVar5 != 0 &&

          (iVar5 = FUN_00545650(*puVar4,s_D_B_smartbrick_0055415c), iVar5 != 0)) &&

         (iVar5 = FUN_00545650(*puVar4,s_s_stony2_00554150), iVar5 != 0)) &&

        (iVar5 = FUN_00545650(*puVar4,s_s_stony_00554148), iVar5 != 0)))) {

      puVar4 = (undefined4 *)obj_material_names(param_1);

      if ((puVar4 == (undefined4 *)0x0) ||

         (((iVar5 = FUN_00545650(*puVar4,s_Wood_tile_005541d4), iVar5 != 0 &&

           (iVar5 = FUN_00545650(*puVar4,s_Wood_rings_005541c8), iVar5 != 0)) &&

          (iVar5 = FUN_00545650(*puVar4,s_sm_thatch_005541bc), iVar5 != 0)))) {

        puVar4 = (undefined4 *)obj_material_names(param_1);

        if ((puVar4 == (undefined4 *)0x0) ||

           (((iVar5 = FUN_00545650(*puVar4,s_Metal_005541b4), iVar5 != 0 &&

             (iVar5 = FUN_00545650(*puVar4,s_D_metal_005541ac), iVar5 != 0)) &&

            ((iVar5 = FUN_00545650(*puVar4,s_rusted_metal_0055419c), iVar5 != 0 &&

             ((iVar5 = FUN_00545650(*puVar4,s_Rusted_metal_stripe_00554188), iVar5 != 0 &&

              (iVar5 = FUN_00545650(*puVar4,s_floor1_tile_0055417c), iVar5 != 0)))))))) {

          uVar7 = param_5[2];

        }

        else {

          uVar7 = param_5[6];

        }

      }

      else {

        uVar7 = param_5[4];

      }

    }

    else {

      uVar7 = param_5[5];

    }

  }

  else {

    uVar7 = param_5[3];

  }

  if ((uVar2 & 1) != 0) {

    sound_play_player(uVar7,param_1);

  }

  if ((uVar2 & 0x10008) != 0) {

    iVar5 = mecc_zoom_out__FRC10CntrlInputif();

    if (iVar5 != 0) {

      _DAT_00632dc0 = 0x40a00000;

      _DAT_00632dc4 = 0x40000000;

    }

    if ((uVar2 & 0x10000) == 0) {

      FUN_0042e260(param_1,0);

      fVar8 = (float10)FUN_0045d2e0(param_1);

      uVar9 = 8;

    }

    else {

      FUN_0042e260(param_1,1);

      fVar8 = (float10)FUN_0045d2e0(param_1);

      uVar9 = 9;

    }

    FootDust(param_1,uVar9,1,(float)fVar8);

    fVar8 = (float10)FUN_0050a610(DAT_00632a88 + 0xa0,param_1 + 0xa0);

    if ((fVar8 < (float10)90000.0) && (iVar5 = ObjIsMecc(DAT_00632a88), iVar5 != 0)) {

      _DAT_00632dc0 = 0x3ecccccd;

      _DAT_00632dc4 = 0x3e800000;

      ANM_DumpCluster(DAT_00632a88,0x1e);

    }

  }

  if ((uVar2 & 0x10) != 0) {

    object_create_child(param_1,0,uVar7);

  }

  if ((uVar2 & 0x20) != 0) {

    object_create_child(param_1,1,uVar7);

  }

  if ((uVar2 & 0x40) != 0) {

    playerobj_eval_refpt(param_1,param_5[7],local_30);

    fx_get_free_effect__Fv();

  }

  if ((char)uVar2 < '\0') {

    local_20 = param_5[7];

    local_1c = param_1;

    fx_get_free_effect__Fv();

  }

  return;

}

/* ===== army_create_rpman__FP6OBJECTP9ArmyOrderifi @ 0x00406BC0 ===== */
/* PS2 candidate: army_create_rpman__FP6OBJECTP9ArmyOrderifi (conf 0.491) */



int army_create_rpman__FP6OBJECTP9ArmyOrderifi

              (int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)



{

  undefined4 *puVar1;

  int iVar2;

  int iVar3;

  undefined4 uVar4;

  int iVar5;

  undefined4 uVar6;

  

  iVar3 = object_allocate_type(0xd7,0x80000000);

  iVar2 = *(int *)(iVar3 + 0x100);

  puVar1 = (undefined4 *)(iVar3 + 0xa0);

  playerobj_eval_refpt(param_1,0,puVar1);

  object_set_location(iVar3,*puVar1,*(undefined4 *)(iVar3 + 0xa4),*(undefined4 *)(iVar3 + 0xa8));

  *(undefined4 *)(iVar2 + 0x48) = *puVar1;

  *(undefined4 *)(iVar2 + 0x4c) = *(undefined4 *)(iVar3 + 0xa4);

  *(undefined4 *)(iVar2 + 0x50) = *(undefined4 *)(iVar3 + 0xa8);

  if ((*(uint *)(param_1 + 0xd8) & 0x400) != 0) {

    *(uint *)(iVar3 + 0xd8) = *(uint *)(iVar3 + 0xd8) | 0x400;

  }

  uVar4 = __ftol();

  uVar6 = param_4;

  switch(uVar4) {

  case 0:

    uVar6 = 1;

    break;

  case 1:

    iVar5 = crt_rand_scaled(*(undefined4 *)(param_2 + 0x88));

    *(float *)(iVar3 + 0xf8) = (float)*(int *)(param_2 + 0x38 + iVar5 * 4);

    uVar6 = 3;

    break;

  case 2:

    uVar6 = 5;

    break;

  case 3:

    uVar6 = 2;

    break;

  case 4:

    uVar6 = 4;

  }

  playerobj_eval_refpt(param_1,uVar6,iVar2 + 8);

  *(undefined4 *)(iVar3 + 0xe8) = param_3;

  *(undefined4 *)(iVar3 + 0xfc) = param_4;

  *(undefined4 *)(iVar2 + 0x134) = *(undefined4 *)(param_2 + 0x104);

  *(undefined4 *)(iVar2 + 0x138) = param_5;

  if ((*(uint *)(param_1 + 0xd8) & 0x400) != 0) {

    *(uint *)(iVar3 + 0xd8) = *(uint *)(iVar3 + 0xd8) | 0x400;

  }

  if ((*(byte *)(param_2 + 0xc) & 2) != 0) {

    *(undefined4 *)(iVar2 + 0x214) = *(undefined4 *)(param_2 + 0xf4);

    *(undefined4 *)(iVar2 + 0x218) = *(undefined4 *)(param_2 + 0xf8);

    *(undefined4 *)(iVar2 + 0x21c) = *(undefined4 *)(param_2 + 0xfc);

    *(undefined4 *)(iVar2 + 0x220) = *(undefined4 *)(param_2 + 0x100);

    *(uint *)(iVar3 + 0xe0) = *(uint *)(iVar3 + 0xe0) | 0x2000000;

  }

  iVar2 = *(int *)(iVar3 + 0x100);

  *(undefined4 *)(iVar2 + 0xb0) = *(undefined4 *)(param_2 + 0xd0);

  *(undefined4 *)(iVar2 + 0x1c0) = *(undefined4 *)(param_2 + 0xd8);

  *(undefined4 *)(iVar2 + 0x1c8) = *(undefined4 *)(param_2 + 0xe0);

  *(undefined4 *)(iVar2 + 0x1c4) = *(undefined4 *)(param_2 + 0xdc);

  *(undefined4 *)(iVar2 + 0x1cc) = *(undefined4 *)(param_2 + 0xe4);

  *(undefined4 *)(iVar2 + 0x1d0) = *(undefined4 *)(param_2 + 0xe8);

  *(undefined4 *)(iVar2 + 0x1d4) = *(undefined4 *)(param_2 + 0xec);

  *(undefined4 *)(iVar2 + 0x1d8) = *(undefined4 *)(param_2 + 0xf0);

  if (0.0 < *(float *)(param_2 + 0xd4)) {

    *(undefined4 *)(iVar2 + 0x1bc) = *(undefined4 *)(param_2 + 0xd4);

    *(uint *)(iVar2 + 0x1b8) = *(uint *)(iVar2 + 0x1b8) | 4;

  }

  *(int *)(param_2 + 0xd0) = *(int *)(param_2 + 0xd0) + 1;

  return iVar3;

}

/* ===== army_process_opcodes__FP6OBJECTPPUci @ 0x00406DD0 ===== */
/* PS2 candidate: army_process_opcodes__FP6OBJECTPPUci (conf 0.505) */



void army_process_opcodes__FP6OBJECTPPUci(int param_1,int *param_2,int param_3)



{

  char cVar1;

  byte bVar2;

  int iVar3;

  float fVar4;

  undefined4 uVar5;

  bool bVar6;

  uint uVar7;

  byte *pbVar8;

  int iVar9;

  uint uVar10;

  int iVar11;

  int *piVar12;

  undefined4 *puVar13;

  float *pfVar14;

  float *pfVar15;

  undefined4 *puVar16;

  float *pfVar17;

  float *pfVar18;

  uint *puVar19;

  int *piVar20;

  undefined4 *puVar21;

  int iVar22;

  bool bVar23;

  float10 fVar24;

  char *pcVar25;

  undefined4 *local_420;

  undefined1 local_400 [512];

  undefined1 local_200 [512];

  

  iVar3 = *(int *)(param_1 + 0x100);

  if ((float *)*param_2 != (float *)0x0) {

    bVar6 = false;

    uVar10 = 0xffffffff;

    DAT_005841b4 = (float *)*param_2;

    do {

      uVar7 = (uint)*(byte *)DAT_005841b4;

      pfVar14 = (float *)((int)DAT_005841b4 + 1);

      pfVar18 = pfVar14;

      pfVar15 = pfVar14;

      switch(uVar7) {

      case 1:

        break;

      case 2:

        DAT_005841b4 = pfVar14;

        *param_2 = 0;

        bVar6 = true;

        pfVar18 = DAT_005841b4;

        break;

      case 3:

        DAT_005841b4 = pfVar14;

        *(float *)(iVar3 + 0xcc) = *pfVar14;

        DAT_005841b4 = DAT_005841b4 + 1;

        pfVar18 = DAT_005841b4;

        break;

      case 4:

        DAT_005841b4 = pfVar14;

        *(uint *)(iVar3 + 0x10) = *(uint *)(iVar3 + 0x10) | 1;

        *(float *)(iVar3 + 0xc0) = *DAT_005841b4;

        DAT_005841b4 = DAT_005841b4 + 1;

        *(float *)(iVar3 + 0xc4) = *DAT_005841b4;

        DAT_005841b4 = DAT_005841b4 + 1;

        *(float *)(iVar3 + 200) = *DAT_005841b4;

        DAT_005841b4 = DAT_005841b4 + 1;

        pfVar18 = DAT_005841b4;

        break;

      case 5:

        do {

          cVar1 = *(char *)pfVar15;

          pfVar15 = (float *)((int)pfVar15 + 1);

          DAT_005841b4 = pfVar15;

        } while (cVar1 != '\0');

        do {

          cVar1 = *(char *)DAT_005841b4;

          DAT_005841b4 = (float *)((int)DAT_005841b4 + 1);

        } while (cVar1 != '\0');

        pfVar18 = DAT_005841b4;

        if (param_3 == 0) {

          puVar19 = (uint *)(iVar3 + 4);

          for (iVar11 = 0x42; iVar11 != 0; iVar11 = iVar11 + -1) {

            *puVar19 = 0;

            puVar19 = puVar19 + 1;

          }

          *(uint *)(iVar3 + 4) = uVar7;

          *(undefined4 *)(iVar3 + 0xc) = *(undefined4 *)(param_1 + 0xf0);

          *(undefined4 *)(iVar3 + 0xe8) = 100;

          *(undefined4 *)(iVar3 + 0xe0) = 100;

          *(undefined4 *)(iVar3 + 0xe4) = 0x32;

LAB_004072d1:

          army_create_platoon__FP6OBJECTPcT1(param_1,pfVar14,pfVar15);

          iVar11 = *(int *)(param_1 + 0x100);

          if (*(int *)(iVar11 + 0x164c) < 0x14) {

            piVar12 = (int *)(iVar11 + 4);

            piVar20 = (int *)(*(int *)(iVar11 + 0x164c) * 0x110 + 0x114 + iVar11);

            for (iVar22 = 0x42; iVar22 != 0; iVar22 = iVar22 + -1) {

              *piVar20 = *piVar12;

              piVar12 = piVar12 + 1;

              piVar20 = piVar20 + 1;

            }

            *(undefined4 *)(*(int *)(iVar11 + 0x164c) * 0x110 + 0x10c + iVar11) = 0;

            iVar22 = *(int *)(iVar11 + 4);

            if (iVar22 == 5) {

              *(undefined4 *)((*(int *)(iVar11 + 0x164c) + 1) * 0x110 + iVar11) = 1;

              *(int *)(iVar11 + 0x164c) = *(int *)(iVar11 + 0x164c) + 1;

            }

            else if (iVar22 == 0xe) {

              *(undefined4 *)((*(int *)(iVar11 + 0x164c) + 1) * 0x110 + iVar11) = 10;

              *(int *)(iVar11 + 0x164c) = *(int *)(iVar11 + 0x164c) + 1;

            }

            else {

              if (iVar22 != 0x12) {

                pcVar25 = s_Army_Error__invalid_order_op__or_00554454;

                goto LAB_0040737a;

              }

              *(undefined4 *)((*(int *)(iVar11 + 0x164c) + 1) * 0x110 + iVar11) = 0x14;

              *(int *)(iVar11 + 0x164c) = *(int *)(iVar11 + 0x164c) + 1;

            }

          }

          else {

            pcVar25 = s_Army_Error__too_many_active_orde_00554410;

LAB_0040737a:

            FUN_0051ea20(pcVar25);

          }

          puVar13 = *(undefined4 **)(param_1 + 0x100);

          if ((int)puVar13[0x1278] < 0x32) {

            puVar21 = puVar13 + puVar13[0x1278] * 0x42 + 0x594;

            puVar16 = puVar13;

            for (iVar11 = 0x42; puVar16 = puVar16 + 1, iVar11 != 0; iVar11 = iVar11 + -1) {

              *puVar21 = *puVar16;

              puVar21 = puVar21 + 1;

            }

            puVar13[0x1278] = puVar13[0x1278] + 1;

            pfVar18 = DAT_005841b4;

          }

          else {

            FUN_0051ea20(s_Army_Error__too_many_alive_order_005543d4);

            pfVar18 = DAT_005841b4;

          }

        }

        break;

      case 6:

        DAT_005841b4 = (float *)((int)DAT_005841b4 + 5);

        pfVar18 = DAT_005841b4;

        if (*(int *)(iVar3 + 0x8c) < 10) {

          *(float *)(iVar3 + 0x3c + *(int *)(iVar3 + 0x8c) * 4) = *pfVar14;

          *(int *)(iVar3 + 0x8c) = *(int *)(iVar3 + 0x8c) + 1;

          pfVar18 = DAT_005841b4;

        }

        break;

      case 7:

switchD_00406e2f_caseD_7:

        DAT_005841b4 = pfVar14;

        bVar6 = true;

        pfVar18 = DAT_005841b4;

        break;

      case 8:

        fVar4 = *pfVar14;

        DAT_005841b4 = (float *)((int)DAT_005841b4 + 5);

        pfVar18 = DAT_005841b4;

        if ((param_3 == 0) &&

           (*(float *)(param_1 + 0xf0) = fVar4, pfVar18 = DAT_005841b4, pfVar14 = DAT_005841b4,

           *(float *)(param_1 + 0xec) < fVar4)) goto switchD_00406e2f_caseD_7;

        break;

      case 9:

        DAT_005841b4 = pfVar14;

        do {

          cVar1 = *(char *)DAT_005841b4;

          DAT_005841b4 = (float *)((int)DAT_005841b4 + 1);

        } while (cVar1 != '\0');

        pfVar18 = DAT_005841b4;

        if (param_3 == 0) {

          iVar11 = *(int *)(param_1 + 0x100);

          iVar22 = 0;

          if (0 < *(int *)(iVar11 + 0x49e0)) {

            puVar13 = (undefined4 *)(iVar11 + 0x1654);

            do {

              pbVar8 = (byte *)*puVar13;

              pfVar15 = pfVar14;

              do {

                bVar2 = *pbVar8;

                bVar23 = bVar2 < *(byte *)pfVar15;

                if (bVar2 != *(byte *)pfVar15) {

LAB_0040744b:

                  iVar9 = (1 - (uint)bVar23) - (uint)(bVar23 != 0);

                  goto LAB_00407450;

                }

                if (bVar2 == 0) break;

                bVar2 = pbVar8[1];

                bVar23 = bVar2 < *(byte *)((int)pfVar15 + 1);

                if (bVar2 != *(byte *)((int)pfVar15 + 1)) goto LAB_0040744b;

                pbVar8 = pbVar8 + 2;

                pfVar15 = (float *)((int)pfVar15 + 2);

              } while (bVar2 != 0);

              iVar9 = 0;

LAB_00407450:

              if (iVar9 == 0) {

                iVar11 = iVar22 * 0x108 + 0x1650 + iVar11;

                puVar13 = DAT_00632d6c;

                if (iVar11 != 0) {

                  for (; pfVar18 = DAT_005841b4, puVar13 != (undefined4 *)0x0;

                      puVar13 = (undefined4 *)*puVar13) {

                    iVar22 = *(int *)(puVar13[3] + 0x100);

                    if ((*(int *)(puVar13[3] + 4) == 0xd7) &&

                       (*(int *)(iVar22 + 0x134) == *(int *)(iVar11 + 0x104))) {

                      puVar19 = (uint *)(iVar22 + 0x1b8);

                      *puVar19 = *puVar19 | 1;

                    }

                  }

                }

                break;

              }

              iVar22 = iVar22 + 1;

              puVar13 = puVar13 + 0x42;

            } while (iVar22 < *(int *)(iVar11 + 0x49e0));

          }

        }

        break;

      case 10:

        DAT_005841b4 = pfVar14;

        do {

          cVar1 = *(char *)DAT_005841b4;

          DAT_005841b4 = (float *)((int)DAT_005841b4 + 1);

        } while (cVar1 != '\0');

        pfVar18 = DAT_005841b4;

        if (param_3 == 0) {

          iVar11 = *(int *)(param_1 + 0x100);

          iVar22 = 0;

          if (0 < *(int *)(iVar11 + 0x49e0)) {

            local_420 = (undefined4 *)(iVar11 + 0x1654);

            do {

              pbVar8 = (byte *)*local_420;

              pfVar15 = pfVar14;

              do {

                bVar2 = *pbVar8;

                bVar23 = bVar2 < *(byte *)pfVar15;

                if (bVar2 != *(byte *)pfVar15) {

LAB_00407794:

                  iVar9 = (1 - (uint)bVar23) - (uint)(bVar23 != 0);

                  goto LAB_00407799;

                }

                if (bVar2 == 0) break;

                bVar2 = pbVar8[1];

                bVar23 = bVar2 < *(byte *)((int)pfVar15 + 1);

                if (bVar2 != *(byte *)((int)pfVar15 + 1)) goto LAB_00407794;

                pbVar8 = pbVar8 + 2;

                pfVar15 = (float *)((int)pfVar15 + 2);

              } while (bVar2 != 0);

              iVar9 = 0;

LAB_00407799:

              if (iVar9 == 0) {

                iVar9 = iVar22 * 0x108;

                if (iVar11 + 0x1650 + iVar9 != 0) {

                  FUN_00543270(iVar11 + 0x1650 + iVar9,iVar11 + 0x1758 + iVar9,

                               *(int *)(iVar11 + 0x49e0) * 0x108 + (iVar22 + 1) * -0x108);

                  *(int *)(iVar11 + 0x49e0) = *(int *)(iVar11 + 0x49e0) + -1;

                  pfVar18 = DAT_005841b4;

                }

                break;

              }

              iVar22 = iVar22 + 1;

              local_420 = local_420 + 0x42;

            } while (iVar22 < *(int *)(iVar11 + 0x49e0));

          }

        }

        break;

      case 0xb:

        DAT_005841b4 = pfVar14;

        *(float *)(iVar3 + 0xdc) = *pfVar14;

        DAT_005841b4 = DAT_005841b4 + 1;

        pfVar18 = DAT_005841b4;

        break;

      case 0xc:

        DAT_005841b4 = pfVar14;

        *(float *)(iVar3 + 0xe0) = *pfVar14;

        DAT_005841b4 = DAT_005841b4 + 1;

        *(float *)(iVar3 + 0xe4) = *DAT_005841b4;

        DAT_005841b4 = DAT_005841b4 + 1;

        *(float *)(iVar3 + 0xe8) = *DAT_005841b4;

        DAT_005841b4 = DAT_005841b4 + 1;

        pfVar18 = DAT_005841b4;

        break;

      case 0xd:

        if (param_3 == 0) {

          DAT_005841b4 = pfVar14;

          *(undefined4 *)(iVar3 + 0x49e4) = 1;

          pfVar18 = DAT_005841b4;

        }

        break;

      case 0xe:

        do {

          cVar1 = *(char *)pfVar15;

          pfVar15 = (float *)((int)pfVar15 + 1);

          DAT_005841b4 = pfVar15;

        } while (cVar1 != '\0');

        do {

          cVar1 = *(char *)DAT_005841b4;

          DAT_005841b4 = (float *)((int)DAT_005841b4 + 1);

        } while (cVar1 != '\0');

        pfVar18 = DAT_005841b4;

        if (param_3 == 0) {

          iVar11 = *(int *)(param_1 + 0x100);

          iVar22 = 0;

          if (0 < *(int *)(iVar11 + 0x164c)) {

            piVar12 = (int *)(iVar11 + 0x114);

            do {

              pbVar8 = (byte *)piVar12[1];

              pfVar17 = pfVar14;

              do {

                bVar2 = *pbVar8;

                bVar23 = bVar2 < *(byte *)pfVar17;

                if (bVar2 != *(byte *)pfVar17) {

LAB_0040754b:

                  iVar9 = (1 - (uint)bVar23) - (uint)(bVar23 != 0);

                  goto LAB_00407550;

                }

                if (bVar2 == 0) break;

                bVar2 = pbVar8[1];

                bVar23 = bVar2 < *(byte *)((int)pfVar17 + 1);

                if (bVar2 != *(byte *)((int)pfVar17 + 1)) goto LAB_0040754b;

                pbVar8 = pbVar8 + 2;

                pfVar17 = (float *)((int)pfVar17 + 2);

              } while (bVar2 != 0);

              iVar9 = 0;

LAB_00407550:

              if ((iVar9 == 0) && (*piVar12 == 0xe)) {

                iVar22 = iVar22 * 0x110 + 0x114 + iVar11;

                if (iVar22 != 0) {

                  if (*(int *)(iVar22 + 0xb4) < 10) {

                    *(float **)(iVar22 + 0x8c + *(int *)(iVar22 + 0xb4) * 4) = pfVar15;

                    *(int *)(iVar22 + 0xb4) = *(int *)(iVar22 + 0xb4) + 1;

                    pfVar18 = DAT_005841b4;

                  }

                  goto switchD_00406e2f_caseD_1;

                }

                break;

              }

              iVar22 = iVar22 + 1;

              piVar12 = piVar12 + 0x44;

            } while (iVar22 < *(int *)(iVar11 + 0x164c));

          }

          puVar13 = (undefined4 *)(iVar11 + 4);

          for (iVar22 = 0x42; iVar22 != 0; iVar22 = iVar22 + -1) {

            *puVar13 = 0;

            puVar13 = puVar13 + 1;

          }

          *(float **)(iVar11 + 8) = pfVar14;

          *(undefined4 *)(iVar11 + 4) = 0xe;

          *(undefined4 *)(iVar11 + 0xc) = *(undefined4 *)(param_1 + 0xf0);

          *(undefined4 *)(iVar11 + 0xb8) = 1;

          *(float **)(iVar11 + 0x90) = pfVar15;

          FUN_00407a10(param_1);

          pfVar18 = DAT_005841b4;

        }

        break;

      case 0xf:

        DAT_005841b4 = pfVar14;

        *(float *)(iVar3 + 0xec) = *pfVar14;

        DAT_005841b4 = DAT_005841b4 + 1;

        pfVar18 = DAT_005841b4;

        break;

      case 0x10:

        DAT_005841b4 = pfVar14;

        *(float *)(iVar3 + 0xf0) = *pfVar14;

        DAT_005841b4 = DAT_005841b4 + 1;

        *(float *)(iVar3 + 0xf4) = *DAT_005841b4;

        DAT_005841b4 = DAT_005841b4 + 1;

        pfVar18 = DAT_005841b4;

        break;

      case 0x11:

        DAT_005841b4 = pfVar14;

        *(float *)(iVar3 + 0xfc) = *pfVar14;

        DAT_005841b4 = DAT_005841b4 + 1;

        *(float *)(iVar3 + 0xf8) = *DAT_005841b4;

        DAT_005841b4 = DAT_005841b4 + 1;

        *(float *)(iVar3 + 0x100) = *DAT_005841b4;

        DAT_005841b4 = DAT_005841b4 + 1;

        *(float *)(iVar3 + 0x104) = *DAT_005841b4;

        DAT_005841b4 = DAT_005841b4 + 1;

        *(uint *)(iVar3 + 0x10) = *(uint *)(iVar3 + 0x10) | 2;

        *(float *)(iVar3 + 0x100) =

             ((*(float *)(iVar3 + 0xf8) + 1.0) * (1.0 / *(float *)(iVar3 + 0x100))) /

             *(float *)(iVar3 + 0x104);

        pfVar18 = DAT_005841b4;

        break;

      case 0x12:

        do {

          cVar1 = *(char *)pfVar15;

          pfVar15 = (float *)((int)pfVar15 + 1);

          DAT_005841b4 = pfVar15;

        } while (cVar1 != '\0');

        do {

          cVar1 = *(char *)DAT_005841b4;

          DAT_005841b4 = (float *)((int)DAT_005841b4 + 1);

        } while (cVar1 != '\0');

        pfVar18 = DAT_005841b4;

        if (param_3 == 0) {

          puVar19 = (uint *)(iVar3 + 4);

          for (iVar11 = 0x42; iVar11 != 0; iVar11 = iVar11 + -1) {

            *puVar19 = 0;

            puVar19 = puVar19 + 1;

          }

          *(uint *)(iVar3 + 4) = uVar7;

          *(undefined4 *)(iVar3 + 0xc) = *(undefined4 *)(param_1 + 0xf0);

          goto LAB_004072d1;

        }

        break;

      case 0x13:

        uVar5 = *(undefined4 *)((int)DAT_005841b4 + 5);

        DAT_005841b4 = (float *)((int)DAT_005841b4 + 9);

        pfVar18 = DAT_005841b4;

        if (*(int *)(iVar3 + 0x8c) < 10) {

          *(float *)(iVar3 + 0x3c + *(int *)(iVar3 + 0x8c) * 4) = *pfVar14;

          *(undefined4 *)(iVar3 + 100 + *(int *)(iVar3 + 0x8c) * 4) = uVar5;

          *(int *)(iVar3 + 0x8c) = *(int *)(iVar3 + 0x8c) + 1;

          pfVar18 = DAT_005841b4;

        }

        break;

      case 0x14:

        DAT_005841b4 = pfVar14;

        *(float *)(iVar3 + 0xd8) = *pfVar14;

        DAT_005841b4 = DAT_005841b4 + 1;

        pfVar18 = DAT_005841b4;

        break;

      case 0x15:

        DAT_005841b4 = (float *)((int)DAT_005841b4 + 5);

        pfVar18 = DAT_005841b4;

        if (param_3 == 0) {

          *(float *)(param_1 + 0xf4) = *pfVar14;

          pfVar18 = DAT_005841b4;

        }

        break;

      case 0x16:

        fVar4 = *pfVar14;

        uVar5 = *(undefined4 *)((int)DAT_005841b4 + 5);

        DAT_005841b4 = (float *)((int)DAT_005841b4 + 9);

        pfVar18 = DAT_005841b4;

        if (param_3 != 0) {

          iVar11 = *(int *)(param_1 + 0x100);

          if (*(int *)(iVar11 + 0x49e8) < 5) {

            *(float **)(iVar11 + (*(int *)(iVar11 + 0x49e8) * 3 + 0x127b) * 4) = DAT_005841b4;

            *(undefined4 *)(iVar11 + 0x49f0 + *(int *)(iVar11 + 0x49e8) * 0xc) = uVar5;

            *(float *)(iVar11 + 0x49f4 + *(int *)(iVar11 + 0x49e8) * 0xc) = fVar4;

            *(int *)(iVar11 + 0x49e8) = *(int *)(iVar11 + 0x49e8) + 1;

            pfVar18 = DAT_005841b4;

          }

          else {

            crt_sprintf(local_400,s_Army_bin_has_too_many_labels__d__00554480,5);

            FUN_0051ea20(local_400);

            pfVar18 = DAT_005841b4;

          }

        }

        break;

      case 0x17:

        fVar4 = *pfVar14;

        DAT_005841b4 = (float *)((int)DAT_005841b4 + 5);

        pfVar18 = DAT_005841b4;

        if (param_3 == 0) {

          iVar11 = *(int *)(param_1 + 0x100);

          iVar22 = 0;

          if (0 < *(int *)(iVar11 + 0x49e8)) {

            puVar13 = (undefined4 *)(iVar11 + 0x49ec);

            do {

              if ((float)puVar13[2] == fVar4) {

                DAT_005841b4 = (float *)*puVar13;

                *(undefined4 *)(param_1 + 0xec) = puVar13[1];

              }

              iVar22 = iVar22 + 1;

              puVar13 = puVar13 + 3;

              pfVar18 = DAT_005841b4;

            } while (iVar22 < *(int *)(iVar11 + 0x49e8));

          }

        }

        break;

      case 0x18:

        do {

          pfVar15 = pfVar18;

          pfVar18 = (float *)((int)pfVar15 + 1);

        } while (*(char *)pfVar15 != '\0');

        DAT_005841b4 = (float *)((int)pfVar15 + 9);

        pfVar18 = DAT_005841b4;

        if (param_3 == 0) {

          fVar24 = (float10)rndfloatrange(*(float *)((int)pfVar15 + 1),

                                          *(undefined4 *)((int)pfVar15 + 5));

          iVar11 = *(int *)(param_1 + 0x100);

          iVar22 = 0;

          if (0 < *(int *)(iVar11 + 0x164c)) {

            piVar12 = (int *)(iVar11 + 0x114);

            do {

              pbVar8 = (byte *)piVar12[1];

              pfVar18 = pfVar14;

              do {

                bVar2 = *pbVar8;

                bVar23 = bVar2 < *(byte *)pfVar18;

                if (bVar2 != *(byte *)pfVar18) {

LAB_00407694:

                  iVar9 = (1 - (uint)bVar23) - (uint)(bVar23 != 0);

                  goto LAB_00407699;

                }

                if (bVar2 == 0) break;

                bVar2 = pbVar8[1];

                bVar23 = bVar2 < *(byte *)((int)pfVar18 + 1);

                if (bVar2 != *(byte *)((int)pfVar18 + 1)) goto LAB_00407694;

                pbVar8 = pbVar8 + 2;

                pfVar18 = (float *)((int)pfVar18 + 2);

              } while (bVar2 != 0);

              iVar9 = 0;

LAB_00407699:

              if ((iVar9 == 0) && (*piVar12 == 0xe)) {

                iVar22 = iVar22 * 0x110 + 0x114 + iVar11;

                if (iVar22 != 0) {

                  *(float *)(iVar22 + 0xb8) = (float)fVar24;

                  pfVar18 = DAT_005841b4;

                  goto switchD_00406e2f_caseD_1;

                }

                break;

              }

              iVar22 = iVar22 + 1;

              piVar12 = piVar12 + 0x44;

            } while (iVar22 < *(int *)(iVar11 + 0x164c));

          }

          puVar13 = (undefined4 *)(iVar11 + 4);

          for (iVar22 = 0x42; iVar22 != 0; iVar22 = iVar22 + -1) {

            *puVar13 = 0;

            puVar13 = puVar13 + 1;

          }

          *(float **)(iVar11 + 8) = pfVar14;

          *(undefined4 *)(iVar11 + 4) = 0xe;

          uVar5 = *(undefined4 *)(param_1 + 0xf0);

          *(float *)(iVar11 + 0xbc) = (float)fVar24;

          *(undefined4 *)(iVar11 + 0xc) = uVar5;

          FUN_00407a10(param_1);

          pfVar18 = DAT_005841b4;

        }

        break;

      default:

        DAT_005841b4 = pfVar14;

        crt_sprintf(local_200,s_Army_Bld_System_got_unknown_opco_00554390,uVar10);

        FUN_0051ea20(local_200);

        pfVar18 = DAT_005841b4;

      }

switchD_00406e2f_caseD_1:

      DAT_005841b4 = pfVar18;

      uVar10 = uVar7;

    } while (!bVar6);

    if (*param_2 != 0) {

      *param_2 = (int)DAT_005841b4;

    }

  }

  return;

}

/* ===== army_create_platoon__FP6OBJECTPcT1 @ 0x004078F0 ===== */
/* PS2 candidate: army_create_platoon__FP6OBJECTPcT1 (conf 0.46699999999999997) */



void army_create_platoon__FP6OBJECTPcT1(int param_1,undefined4 param_2,undefined4 param_3)



{

  int iVar1;

  int iVar2;

  undefined4 uVar3;

  int *piVar4;

  int iVar6;

  int iVar7;

  int iVar8;

  int local_84;

  undefined1 local_80 [128];

  int *piVar5;

  

  uVar3 = DAT_005841b4;

  iVar1 = *(int *)(param_1 + 0x100);

  iVar2 = *(int *)(DAT_005841ac + DAT_005841b8);

  DAT_005841b4 = (int *)(DAT_005841ac + DAT_005841b8) + 1;

  if (0 < iVar2) {

    iVar8 = -1;

    iVar7 = 0;

    piVar4 = DAT_005841b4;

    if (0 < iVar2) {

      do {

        do {

          piVar5 = DAT_005841b4;

          DAT_005841b4 = (int *)((int)piVar5 + 1);

        } while ((char)*piVar5 != '\0');

        iVar8 = *(int *)((int)piVar5 + 1);

        DAT_005841b4 = (int *)((int)piVar5 + 5);

        iVar6 = FUN_00545650(piVar4,param_2);

      } while ((iVar6 != 0) && (iVar7 = iVar7 + 1, piVar4 = DAT_005841b4, iVar7 < iVar2));

    }

    if (iVar7 == iVar2) {

      crt_sprintf(local_80,s_Army_Bld_System_got_unknown_plat_005544b0,param_2);

      FUN_0051ea20(local_80);

      iVar8 = DAT_005841a8;

    }

    local_84 = DAT_005841b8 + iVar8;

    army_process_opcodes__FP6OBJECTPPUci(param_1,&local_84,0);

    *(undefined4 *)(iVar1 + 8) = param_3;

    DAT_005841b4 = (int *)uVar3;

    return;

  }

  crt_sprintf(local_80,s_Army_Bld_System_Has_No_Platoons___005544e0);

  FUN_0051ea20(local_80);

  return;

}

/* ===== FUN_00407a10 @ 0x00407A10 ===== */
void FUN_00407a10(int param_1)



{

  int iVar1;

  int iVar2;

  int *piVar3;

  int *piVar4;

  

  iVar1 = *(int *)(param_1 + 0x100);

  if (0x13 < *(int *)(iVar1 + 0x164c)) {

    FUN_0051ea20();

    return;

  }

  piVar3 = (int *)(iVar1 + 4);

  piVar4 = (int *)(*(int *)(iVar1 + 0x164c) * 0x110 + 0x114 + iVar1);

  for (iVar2 = 0x42; iVar2 != 0; iVar2 = iVar2 + -1) {

    *piVar4 = *piVar3;

    piVar3 = piVar3 + 1;

    piVar4 = piVar4 + 1;

  }

  *(undefined4 *)(*(int *)(iVar1 + 0x164c) * 0x110 + 0x10c + iVar1) = 0;

  iVar2 = *(int *)(iVar1 + 4);

  if (iVar2 == 5) {

    *(undefined4 *)((*(int *)(iVar1 + 0x164c) + 1) * 0x110 + iVar1) = 1;

    *(int *)(iVar1 + 0x164c) = *(int *)(iVar1 + 0x164c) + 1;

    return;

  }

  if (iVar2 == 0xe) {

    *(undefined4 *)((*(int *)(iVar1 + 0x164c) + 1) * 0x110 + iVar1) = 10;

    *(int *)(iVar1 + 0x164c) = *(int *)(iVar1 + 0x164c) + 1;

    return;

  }

  if (iVar2 != 0x12) {

    FUN_0051ea20();

    return;

  }

  *(undefined4 *)((*(int *)(iVar1 + 0x164c) + 1) * 0x110 + iVar1) = 0x14;

  *(int *)(iVar1 + 0x164c) = *(int *)(iVar1 + 0x164c) + 1;

  return;

}

/* ===== AudioGetSampleName__Fi @ 0x00407C30 ===== */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */



undefined ** AudioGetSampleName__Fi(int p0)



{

  int in_stack_00000008;

  

  return &PTR_DAT_00554520 + in_stack_00000008 * 0x16;

}

/* ===== meccbase_init @ 0x00407C40 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* PS2 candidate: meccbase_init (conf 0.412) */



void meccbase_init(int param_1)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  int *piVar4;

  undefined4 *puVar5;

  int *piVar6;

  undefined4 local_10;

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

    object_set_location_p3d(iVar2,&local_c);

    *(float *)(iVar2 + 200) = *(float *)(param_1 + 200) - (float)piVar1[7];

    ObjectCalculateTransform(iVar2);

    ObjectSetAnim(iVar2,1,0x20,0,0,0);

    object_animate_process(iVar2,0x3d4ccccd);

    piVar6 = &DAT_00554570;

    piVar4 = piVar1 + 0xc;

    do {

      if (*piVar6 < 0) {

        piVar4[-3] = *(int *)(param_1 + 0xa0);

        piVar4[-2] = *(int *)(param_1 + 0xa4);

        piVar4[-1] = *(int *)(param_1 + 0xa8);

        *piVar4 = *(int *)(param_1 + 200);

      }

      else {

        FUN_004186c0(iVar2,*piVar6,piVar4 + -3,piVar4);

      }

      piVar6 = piVar6 + 0x16;

      piVar4 = piVar4 + 7;

    } while ((int)piVar6 < 0x554e60);

    iVar3 = object_allocate_type(0x342,0);

    FUN_004186c0(iVar2,0,&local_c,&local_10);

    object_set_location_p3d(iVar3,&local_c);

    *(undefined4 *)(iVar3 + 200) = local_10;

    *(uint *)(iVar3 + 0xd8) = *(uint *)(iVar3 + 0xd8) | 0x10;

    FUN_00418630(iVar2,0x13,piVar1 + 0x171);

    FUN_00418630(iVar2,0x14,piVar1 + 0x174);

    object_destroy(iVar2);

    piVar4 = piVar1 + 0xdc;

    iVar2 = 5;

    do {

      iVar3 = 0xc;

      do {

        *piVar4 = 0;

        piVar4[1] = 0;

        piVar4 = piVar4 + 2;

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

    piVar4 = piVar1 + 0xdf;

    do {

      *piVar4 = iVar2 + 0x14;

      iVar2 = iVar2 + 1;

      piVar4 = piVar4 + 2;

    } while (iVar2 < 0xc);

    iVar2 = 1;

    piVar4 = piVar1 + 0xf7;

    do {

      *piVar4 = iVar2 + 0x1e;

      iVar2 = iVar2 + 1;

      piVar4 = piVar4 + 2;

    } while (iVar2 < 0xc);

    iVar2 = 1;

    piVar4 = piVar1 + 0x10f;

    do {

      *piVar4 = iVar2 + 0x28;

      iVar2 = iVar2 + 1;

      piVar4 = piVar4 + 2;

    } while (iVar2 < 0xc);

    iVar2 = 1;

    piVar4 = piVar1 + 0x127;

    do {

      *piVar4 = iVar2 + 0x32;

      iVar2 = iVar2 + 1;

      piVar4 = piVar4 + 2;

    } while (iVar2 < 0xc);

    iVar2 = 1;

    piVar4 = piVar1 + 0x13f;

    do {

      *piVar4 = iVar2 + 0x3c;

      iVar2 = iVar2 + 1;

      piVar4 = piVar4 + 2;

    } while (iVar2 < 0xc);

    piVar1[0x15a] = 0;

    piVar1[0xda] = -1;

    puVar5 = &DAT_0055456c;

    piVar4 = piVar1 + 0xd;

    do {

      *piVar4 = 0;

      *puVar5 = 0x43480000;

      iVar2 = DAT_00632ed8;

      puVar5 = puVar5 + 0x16;

      piVar4 = piVar4 + 7;

    } while ((int)puVar5 < 0x554e5c);

    DAT_0055456c = *(undefined4 *)(DAT_00632ed8 + 0x5d4);

    DAT_005545c4 = *(undefined4 *)(DAT_00632ed8 + 0x5d8);

    _DAT_0055461c = *(undefined4 *)(DAT_00632ed8 + 0x634);

    _DAT_00554674 = *(undefined4 *)(DAT_00632ed8 + 0x638);

    _DAT_005546cc = *(undefined4 *)(DAT_00632ed8 + 0x63c);

    _DAT_00554724 = *(undefined4 *)(DAT_00632ed8 + 0x63c);

    _DAT_0055477c = *(undefined4 *)(DAT_00632ed8 + 0x63c);

    _DAT_005547d4 = *(undefined4 *)(DAT_00632ed8 + 0x63c);

    _DAT_0055482c = *(undefined4 *)(DAT_00632ed8 + 0x63c);

    _DAT_00554884 = *(undefined4 *)(DAT_00632ed8 + 0x63c);

    _DAT_005548dc = *(undefined4 *)(DAT_00632ed8 + 0x63c);

    _DAT_00554934 = *(undefined4 *)(DAT_00632ed8 + 0x63c);

    _DAT_0055498c = *(undefined4 *)(DAT_00632ed8 + 0x640);

    _DAT_005549e4 = *(undefined4 *)(DAT_00632ed8 + 0x644);

    _DAT_00554a3c = *(undefined4 *)(DAT_00632ed8 + 0x648);

    _DAT_00554a94 = *(undefined4 *)(DAT_00632ed8 + 0x64c);

    _DAT_00554aec = *(undefined4 *)(DAT_00632ed8 + 0x650);

    _DAT_00554b44 = *(undefined4 *)(DAT_00632ed8 + 0x654);

    _DAT_00554b9c = *(undefined4 *)(DAT_00632ed8 + 0x654);

    _DAT_00554bf4 = *(undefined4 *)(DAT_00632ed8 + 0x654);

    _DAT_00554c4c = *(undefined4 *)(DAT_00632ed8 + 0x654);

    _DAT_00554ca4 = *(undefined4 *)(DAT_00632ed8 + 0x654);

    _DAT_00554cfc = *(undefined4 *)(DAT_00632ed8 + 0x654);

    _DAT_00554d54 = *(undefined4 *)(DAT_00632ed8 + 0x654);

    _DAT_00554dac = *(undefined4 *)(DAT_00632ed8 + 0x654);

    _DAT_00554e04 = *(undefined4 *)(DAT_00632ed8 + 0x658);

    _DAT_00554574 = *(undefined4 *)(DAT_00632ed8 + 0x1148);

    _DAT_005545cc = *(undefined4 *)(DAT_00632ed8 + 0x1144);

    DAT_00554624 = __ftol();

    _DAT_0055467c = __ftol();

    DAT_005546d4 = *(undefined4 *)(iVar2 + 0x114c);

    _DAT_0055472c = *(undefined4 *)(iVar2 + 0x114c);

    _DAT_00554784 = *(undefined4 *)(iVar2 + 0x114c);

    _DAT_005547dc = *(undefined4 *)(iVar2 + 0x114c);

    _DAT_00554834 = *(undefined4 *)(iVar2 + 0x114c);

    _DAT_0055488c = *(undefined4 *)(iVar2 + 0x114c);

    _DAT_005548e4 = *(undefined4 *)(iVar2 + 0x114c);

    _DAT_0055493c = *(undefined4 *)(iVar2 + 0x114c);

    _DAT_00554994 = *(undefined4 *)(iVar2 + 0x1150);

    _DAT_005549ec = *(undefined4 *)(iVar2 + 0x1154);

    _DAT_00554a44 = *(undefined4 *)(iVar2 + 0x1158);

    _DAT_00554a9c = *(undefined4 *)(iVar2 + 0x115c);

    _DAT_00554af4 = *(undefined4 *)(iVar2 + 0x1160);

    _DAT_00554b4c = *(undefined4 *)(iVar2 + 0x1164);

    _DAT_00554ba4 = *(undefined4 *)(iVar2 + 0x1164);

    _DAT_00554bfc = *(undefined4 *)(iVar2 + 0x1164);

    _DAT_00554c54 = *(undefined4 *)(iVar2 + 0x1164);

    _DAT_00554cac = *(undefined4 *)(iVar2 + 0x1164);

    _DAT_00554d04 = *(undefined4 *)(iVar2 + 0x1164);

    _DAT_00554d5c = *(undefined4 *)(iVar2 + 0x1164);

    _DAT_00554db4 = *(undefined4 *)(iVar2 + 0x1164);

    _DAT_00554e0c = *(undefined4 *)(iVar2 + 0x1168);

    piVar1[0x1b] = 1;

    bldg_set_energy(param_1,*(undefined4 *)(DAT_00632ed8 + 0x15a0));

  }

  return;

}

/* ===== meccbaseitem_move @ 0x00408530 ===== */
/* PS2 candidate: meccbaseitem_move (conf 0.591) */



void meccbaseitem_move(float param_1)



{

  float *pfVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int *piVar5;

  float10 fVar6;

  float10 fVar7;

  undefined1 local_c [12];

  

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

  iVar2 = fx_create(param_1);

  if (iVar2 != 0) {

    switch(*(undefined4 *)((int)param_1 + 0xe4)) {

    case 2:

      fVar6 = (float10)bldg_get_energy(param_1);

      if ((float10)0.0 < fVar6) {

        *(undefined4 *)((int)param_1 + 0x184) = 0;

        if (*(int *)((int)param_1 + 0x274) != 0) {

          iVar3 = 0;

          piVar5 = (int *)(*(int *)(*(int *)((int)param_1 + 0x274) + 0x100) + 0x20);

          do {

            if ((float)*piVar5 == param_1) goto LAB_00408880;

            iVar3 = iVar3 + 1;

            piVar5 = piVar5 + 7;

          } while (iVar3 < 0x1a);

        }

        iVar3 = -1;

LAB_00408880:

        meccbaseitem_start_building(iVar4,param_1,iVar3);

        iVar2 = reaper_0052e4a0(param_1);

        if (iVar2 == 0) {

          return;

        }

        reaper_state_check_a(iVar4,param_1,iVar3);

        return;

      }

    case 1:

switchD_004085cd_caseD_1:

      if (DAT_00632bb0 == 0) {

        *(undefined4 *)((int)param_1 + 0x184) = 0x3f800000;

        return;

      }

      base_bldg_pulsate(param_1);

      return;

    case 3:

    case 0xd:

      *(undefined4 *)((int)param_1 + 0x184) = 0;

      iVar4 = meccbasepit_bldg_from_object(param_1);

      if (iVar4 == 0) {

        if (*(int *)((int)param_1 + 0x274) != 0) {

          iVar4 = 0;

          piVar5 = (int *)(*(int *)(*(int *)((int)param_1 + 0x274) + 0x100) + 0x20);

          do {

            if ((float)*piVar5 == param_1) {

              if (-1 < iVar4) {

                param_1 = (float)(&DAT_0055456c)[iVar4 * 0x16];

                goto LAB_0040892e;

              }

              break;

            }

            iVar4 = iVar4 + 1;

            piVar5 = piVar5 + 7;

          } while (iVar4 < 0x1a);

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

LAB_0040892e:

      fVar6 = (float10)bldg_get_energy(iVar3);

      fVar6 = fVar6 / (float10)param_1;

      *(uint *)(iVar3 + 0x30) = *(uint *)(iVar3 + 0x30) | 0x80;

      if (((float10)0.75 <= fVar6) && (fVar6 < (float10)0.99)) {

        fVar6 = (float10)0.75;

      }

      *(float *)(iVar3 + 0x14) = (float)fVar6;

      iVar4 = meccbasepit_bldg_from_object(iVar3);

      if (iVar4 == 0) {

        if (*(int *)(iVar3 + 0x274) != 0) {

          iVar4 = 0;

          piVar5 = (int *)(*(int *)(*(int *)(iVar3 + 0x274) + 0x100) + 0x20);

          do {

            if (*piVar5 == iVar3) {

              if (-1 < iVar4) {

                param_1 = (float)(&DAT_0055456c)[iVar4 * 0x16];

                goto LAB_004089de;

              }

              break;

            }

            iVar4 = iVar4 + 1;

            piVar5 = piVar5 + 7;

          } while (iVar4 < 0x1a);

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

LAB_004089de:

      fVar6 = (float10)bldg_get_energy(iVar3);

      if ((float10)param_1 - (float10)1.0 < fVar6 != ((float10)param_1 - (float10)1.0 == fVar6)) {

        iVar4 = reaper_0052e4a0();

        if (iVar4 != 0) {

          kabutoai_select_punch_anim__FP6OBJECT(iVar3);

        }

        meccbaseitem_finish_building(iVar3);

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

      iVar4 = FUN_00418380(iVar4,0xf);

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

      iVar4 = meccbasepit_bldg_from_object(param_1);

      if (iVar4 == 0) {

        if (*(int *)((int)param_1 + 0x274) != 0) {

          iVar4 = 0;

          piVar5 = (int *)(*(int *)(*(int *)((int)param_1 + 0x274) + 0x100) + 0x20);

          do {

            if ((float)*piVar5 == param_1) {

              if (-1 < iVar4) {

                param_1 = (float)(&DAT_0055456c)[iVar4 * 0x16];

                goto LAB_00408b1e;

              }

              break;

            }

            iVar4 = iVar4 + 1;

            piVar5 = piVar5 + 7;

          } while (iVar4 < 0x1a);

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

LAB_00408b1e:

      fVar6 = (float10)bldg_get_energy(iVar3);

      fVar6 = fVar6 / (float10)param_1;

      *(uint *)(iVar3 + 0x30) = *(uint *)(iVar3 + 0x30) | 0x80;

      if (fVar6 < (float10)0.0 == (fVar6 == (float10)0.0)) {

        fVar6 = fVar6 - (float10)0.01;

        fVar7 = (float10)*(float *)(DAT_00632ed8 + 0xb7c) * (float10)0.01;

        if (fVar6 < fVar7 == (fVar6 == fVar7)) {

          fVar7 = (float10)*(float *)(DAT_00632ed8 + 0xb78) * (float10)0.01;

          if (fVar6 < fVar7 == (fVar6 == fVar7)) {

            fVar7 = (float10)*(float *)(DAT_00632ed8 + 0xb74) * (float10)0.01;

            if (fVar6 < fVar7 == (fVar6 == fVar7)) {

              *(undefined4 *)(iVar3 + 0x14) = 0x3f800000;

            }

            else {

              *(float *)(iVar3 + 0x14) = (float)fVar7;

            }

          }

          else {

            *(float *)(iVar3 + 0x14) = (float)fVar7;

          }

        }

        else {

          *(float *)(iVar3 + 0x14) = (float)fVar7;

        }

      }

      else {

        *(undefined4 *)(iVar3 + 0x14) = 0;

      }

      iVar4 = FUN_0052e4b0(iVar3);

      if (iVar4 == 0) {

        return;

      }

      if ((*pfVar1 == pfVar1[1]) && (pfVar1[2] == pfVar1[3])) {

        return;

      }

      reaper_state_check_c(iVar3);

      pfVar1[1] = *pfVar1;

      pfVar1[3] = pfVar1[2];

      return;

    case 5:

      goto switchD_004085cd_caseD_5;

    default:

      return;

    case 7:

      goto switchD_004085cd_caseD_7;

    case 9:

      iVar4 = FUN_00418380(iVar4,0xf);

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

      fVar6 = (float10)bldg_get_energy(param_1);

      fVar6 = fVar6 / (float10)*(float *)(DAT_00632ed8 + 0x894);

      *(uint *)((int)param_1 + 0x30) = *(uint *)((int)param_1 + 0x30) | 0x80;

      if (((float10)0.75 <= fVar6) && (fVar6 < (float10)0.99)) {

        fVar6 = (float10)0.75;

      }

      *(float *)((int)param_1 + 0x14) = (float)fVar6;

      iVar4 = FUN_0052e4b0(param_1);

      if (iVar4 == 0) {

        return;

      }

      if ((*pfVar1 == pfVar1[1]) && (pfVar1[2] == pfVar1[3])) {

        return;

      }

      reaper_state_check_c(param_1);

      pfVar1[1] = *pfVar1;

      pfVar1[3] = pfVar1[2];

      return;

    case 10:

      if ((*(uint *)((int)param_1 + 0x30) & 2) == 0) {

        return;

      }

      *(uint *)((int)param_1 + 0x30) = *(uint *)((int)param_1 + 0x30) | 0x80;

      *(undefined4 *)((int)param_1 + 0x14) = 0x3f800000;

      *(undefined4 *)((int)param_1 + 0xe4) = 0xc;

      piVar5 = DAT_00632d70;

      if (DAT_00632d70 == (int *)0x0) {

        return;

      }

      while ((iVar4 = piVar5[3], *(int *)(iVar4 + 4) != 0x3df ||

             ((float)*(int *)(iVar4 + 0x210) != param_1))) {

        piVar5 = (int *)*piVar5;

        if (piVar5 == (int *)0x0) {

          return;

        }

      }

LAB_0040878e:

      *(undefined4 *)(iVar4 + 0x210) = 0;

      *(undefined4 *)(iVar4 + 0x214) = 0xffffffff;

      *(undefined4 *)(iVar4 + 0x218) = 0xffffffff;

      FUN_004186c0(param_1,2,iVar4 + 0xa0,iVar4 + 200);

      return;

    case 0xb:

      goto switchD_004085cd_caseD_b;

    case 0xc:

      FUN_00418630(param_1,2,local_c);

      for (piVar5 = DAT_00632d70; piVar5 != (int *)0x0; piVar5 = (int *)*piVar5) {

        if ((*(int *)(piVar5[3] + 4) == 0x3df) &&

           (fVar6 = (float10)FUN_0050a610(local_c,piVar5[3] + 0xa0), fVar6 <= (float10)225.0)) {

          return;

        }

      }

      goto LAB_00408df5;

    }

  }

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

    goto switchD_004085cd_caseD_1;

  case 3:

  case 0xd:

    *(undefined4 *)((int)param_1 + 0x184) = 0;

    fVar7 = (float10)bldg_get_energy(param_1);

    fVar6 = (float10)bldg_get_max_energy(param_1);

    fVar6 = (float10)(float)fVar7 / fVar6;

    goto LAB_0040861c;

  case 4:

    fVar6 = (float10)bldg_get_energy(param_1);

    fVar7 = (float10)bldg_get_max_energy(param_1);

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

    if (fVar7 < fVar6 != (fVar7 == fVar6)) {

      *(float *)((int)param_1 + 0x14) = (float)fVar6;

      return;

    }

    fVar6 = (float10)*(float *)(DAT_00632ed8 + 0xb74) * (float10)0.01;

    if (fVar7 < fVar6 != (fVar7 == fVar6)) {

      *(float *)((int)param_1 + 0x14) = (float)fVar6;

      return;

    }

    goto LAB_00408e3a;

  case 5:

switchD_004085cd_caseD_5:

    if ((*(byte *)((int)param_1 + 0x30) & 2) != 0) {

      *(undefined4 *)((int)param_1 + 0x184) = 0x3f800000;

      object_destroy(param_1);

      return;

    }

    break;

  case 7:

switchD_004085cd_caseD_7:

    if ((*(byte *)((int)param_1 + 0x30) & 2) != 0) {

      ObjectSetAnim(param_1,1,0x84,0,0,0);

      *(undefined4 *)((int)param_1 + 0xe4) = 4;

      *(undefined4 *)((int)param_1 + 0x14) = 0x3f800000;

      return;

    }

    break;

  case 9:

    fVar6 = (float10)bldg_get_energy(param_1);

    fVar6 = fVar6 / (float10)*(float *)(DAT_00632ed8 + 0x894);

LAB_0040861c:

    *(uint *)((int)param_1 + 0x30) = *(uint *)((int)param_1 + 0x30) | 0x80;

    if (((float10)0.75 <= fVar6) && (fVar6 < (float10)0.99)) {

      fVar6 = (float10)0.75;

    }

    *(float *)((int)param_1 + 0x14) = (float)fVar6;

    return;

  case 10:

    if ((*(uint *)((int)param_1 + 0x30) & 2) != 0) {

      *(uint *)((int)param_1 + 0x30) = *(uint *)((int)param_1 + 0x30) | 0x80;

      *(undefined4 *)((int)param_1 + 0x14) = 0x3f800000;

      *(undefined4 *)((int)param_1 + 0xe4) = 0xc;

      piVar5 = DAT_00632d70;

      if (DAT_00632d70 != (int *)0x0) {

        while ((iVar4 = piVar5[3], *(int *)(iVar4 + 4) != 0x3df ||

               ((float)*(int *)(iVar4 + 0x210) != param_1))) {

          piVar5 = (int *)*piVar5;

          if (piVar5 == (int *)0x0) {

            return;

          }

        }

        goto LAB_0040878e;

      }

    }

    break;

  case 0xb:

switchD_004085cd_caseD_b:

    if ((*(byte *)((int)param_1 + 0x30) & 2) == 0) {

      return;

    }

    ObjectSetAnim(param_1,1,0x84,0,0,0);

    *(undefined4 *)((int)param_1 + 0xe4) = 9;

LAB_00408e3a:

    *(undefined4 *)((int)param_1 + 0x14) = 0x3f800000;

    break;

  case 0xc:

    FUN_00418630(param_1,2,local_c);

    for (piVar5 = DAT_00632d70; piVar5 != (int *)0x0; piVar5 = (int *)*piVar5) {

      if ((*(int *)(piVar5[3] + 4) == 0x3df) &&

         (fVar6 = (float10)FUN_0050a610(local_c,piVar5[3] + 0xa0), fVar6 <= (float10)225.0)) {

        return;

      }

    }

LAB_00408df5:

    ObjectSetAnim(param_1,2,0x10,0,0,0);

    *(undefined4 *)((int)param_1 + 0xe4) = 0xb;

    return;

  }

  return;

}

/* ===== meccbaseitem_start_building @ 0x00408EC0 ===== */
/* PS2 candidate: meccbaseitem_start_building (conf 0.503) */



void meccbaseitem_start_building(int param_1,int param_2,int param_3)



{

  int iVar1;

  undefined4 uVar2;

  int iVar3;

  int iVar4;

  int *piVar5;

  

  iVar1 = *(int *)(param_1 + 0x100);

  *(undefined4 *)(param_2 + 0x184) = 0;

  *(undefined4 *)(param_2 + 0xe4) = 3;

  ObjectSetAnim(param_2,1,0x84,0,0,0);

  *(undefined4 *)(param_2 + 0x14) = 0;

  uVar2 = *(undefined4 *)(param_1 + 0x18c);

  *(uint *)(param_2 + 0x1c8) = *(uint *)(param_2 + 0x1c8) & 0xfffff7ff | 0x20000;

  *(undefined4 *)(param_2 + 0x18c) = uVar2;

  *(uint *)(param_2 + 0xd8) = *(uint *)(param_2 + 0xd8) | 0x10;

  if (param_3 % 0xd == 0) {

    piVar5 = (int *)(iVar1 + 0x370);

    param_2 = 5;

    do {

      iVar4 = 0xc;

      do {

        iVar3 = *piVar5;

        if (iVar3 != 0) {

          *(undefined4 *)(iVar3 + 0xe4) = 0x1e;

          ai_clear_move_goal(iVar3);

          *(undefined4 *)(*(int *)(iVar3 + 0x100) + 0x28) = 0xffffffff;

          *piVar5 = 0;

        }

        piVar5 = piVar5 + 2;

        iVar4 = iVar4 + -1;

      } while (iVar4 != 0);

      param_2 = param_2 + -1;

    } while (param_2 != 0);

  }

  if (0xc < param_3) {

    iVar4 = *(int *)(iVar1 + -0x14c + param_3 * 0x1c);

    piVar5 = (int *)(iVar1 + -0x14c + param_3 * 0x1c);

    if (iVar4 != 0) {

      *(undefined4 *)(iVar4 + 0xe4) = 5;

      ObjectSetAnim(*piVar5,1,0x10,0,0,0);

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

/* ===== meccbaseitem_finish_building @ 0x00409030 ===== */
void meccbaseitem_finish_building(int param_1)



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

  iVar3 = meccbasepit_bldg_from_object(param_1);

  if (iVar3 == 0) {

    if (*(int *)(param_1 + 0x274) != 0) {

      iVar3 = 0;

      piVar4 = (int *)(*(int *)(*(int *)(param_1 + 0x274) + 0x100) + 0x20);

      do {

        if (*piVar4 == param_1) {

          if (-1 < iVar3) {

            param_1 = (&DAT_0055456c)[iVar3 * 0x16];

            goto LAB_004090c8;

          }

          break;

        }

        iVar3 = iVar3 + 1;

        piVar4 = piVar4 + 7;

      } while (iVar3 < 0x1a);

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

LAB_004090c8:

  bldg_set_energy(iVar6,param_1);

  *(uint *)(iVar6 + 0x1c8) = *(uint *)(iVar6 + 0x1c8) & 0xfffff7ff | 0x20000;

  if (*(int *)(iVar6 + 0x274) != 0) {

    iVar3 = 0;

    piVar4 = (int *)(*(int *)(*(int *)(iVar6 + 0x274) + 0x100) + 0x20);

    while (*piVar4 != iVar6) {

      iVar3 = iVar3 + 1;

      piVar4 = piVar4 + 7;

      if (0x19 < iVar3) {

        return;

      }

    }

    if (iVar3 != -1) {

      if ((iVar3 == 3) || (iVar3 == 0x10)) {

        *(undefined4 *)(iVar6 + 0xf4) = *(undefined4 *)(DAT_00632ed8 + 0x10d4);

      }

      if (((DAT_00632a88 == 0) || (*(int *)(iVar6 + 0x18c) != *(int *)(DAT_00632a88 + 0x18c))) ||

         (iVar3 != 0xd)) {

        if ((iVar3 == 0) && (iVar6 = fx_create(iVar6), iVar6 != 0)) {

          item_create_base_pickup(iVar2 + 0x5c4,0x13,0xffffffff);

          item_create_base_pickup(iVar2 + 0x5d0,0x13,0xffffffff);

        }

      }

      else {

        uVar5 = FUN_00507b00(s_BaseChatMCPHouseDone_00554ed4,1);

        chat_insert(uVar5);

      }

      iVar6 = *(int *)(iVar3 * 0x1c + 0x20 + *(int *)(iVar1 + 0x100));

      if (**(int **)(iVar6 + 8) != *(int *)(&DAT_00554564 + iVar3 * 0x58)) {

        uVar5 = objectset_find(*(int *)(&DAT_00554564 + iVar3 * 0x58));

        object_set_objectset(iVar6,uVar5);

      }

      if (*(int *)(iVar2 + 0x368) == iVar3) {

        *(undefined4 *)(iVar2 + 0x368) = 0xffffffff;

      }

      meccbase_update_icons(iVar1);

    }

  }

  return;

}

/* ===== meccbase_update_icons @ 0x00409200 ===== */
/* PS2 candidate: meccbase_update_icons (conf 0.788) */



void meccbase_update_icons(int param_1)



{

  int iVar1;

  undefined4 *puVar2;

  int iVar3;

  int iVar4;

  

  iVar1 = *(int *)(param_1 + 0x100);

  puVar2 = (undefined4 *)(iVar1 + 0x34);

  iVar4 = 0x1a;

  do {

    *puVar2 = 0;

    puVar2 = puVar2 + 7;

    iVar4 = iVar4 + -1;

  } while (iVar4 != 0);

  iVar4 = FUN_00418380(param_1,0);

  if ((iVar4 == 0) && (iVar4 = FUN_00418380(param_1,0xd), iVar4 == 0)) {

    iVar4 = FUN_00418380(param_1,0);

    if (iVar4 != 0) {

      return;

    }

    iVar4 = base_bldg_is_alive_at_all_2(param_1,0xd);

    if (iVar4 == 0) {

      return;

    }

  }

  iVar4 = FUN_00418380(param_1,0xd);

  if (iVar4 == 0) {

    iVar4 = FUN_00418380(param_1,0);

    if (((((((iVar4 != 0) && (iVar4 = FUN_00418380(param_1,0x11), iVar4 != 0)) &&

           (iVar4 = FUN_00418380(param_1,0x12), iVar4 != 0)) &&

          ((iVar4 = FUN_00418380(param_1,0x13), iVar4 != 0 &&

           (iVar4 = FUN_00418380(param_1,0x14), iVar4 != 0)))) &&

         (iVar4 = FUN_00418380(param_1,0x15), iVar4 != 0)) &&

        (((iVar4 = FUN_00418380(param_1,0x16), iVar4 != 0 &&

          (iVar4 = FUN_00418380(param_1,0x17), iVar4 != 0)) &&

         ((iVar4 = FUN_00418380(param_1,0x18), iVar4 != 0 &&

          (((iVar4 = FUN_00418380(param_1,0x19), iVar4 != 0 &&

            (iVar4 = FUN_00418380(param_1,0x10), iVar4 != 0)) &&

           (iVar4 = FUN_00418380(param_1,0xf), iVar4 != 0)))))))) &&

       (iVar4 = FUN_00418380(param_1,0xe), iVar4 != 0)) {

      *(undefined4 *)(iVar1 + 0x1a0) = 1;

      return;

    }

  }

  else {

    *(undefined4 *)(iVar1 + 0x568) = 1;

    *(undefined4 *)(iVar1 + 0x1a0) = 1;

  }

  iVar4 = *(int *)(param_1 + 0x100);

  iVar3 = FUN_00418380(param_1,0xf);

  if (iVar3 == 0) {

    iVar3 = FUN_00418380(param_1,2);

    if ((iVar3 == 0) && (iVar3 = base_bldg_is_alive_at_all_2(param_1,0xf), iVar3 == 0)) {

      *(undefined4 *)(iVar4 + 0x6c) = 1;

    }

    else {

      *(undefined4 *)(iVar4 + 0x1d8) = 1;

    }

  }

  iVar4 = FUN_00418380(param_1,2);

  if ((iVar4 == 0) && (iVar4 = FUN_00418380(param_1,0xf), iVar4 == 0)) {

    iVar4 = FUN_00418380(param_1,2);

    if (iVar4 != 0) {

      return;

    }

    iVar4 = base_bldg_is_alive_at_all_2(param_1,0xf);

    if (iVar4 == 0) {

      return;

    }

  }

  iVar4 = FUN_00418380(param_1,0xe);

  if (iVar4 == 0) {

    *(undefined4 *)(iVar1 + 0x1bc) = 1;

  }

  iVar4 = FUN_00418380(param_1,0x11);

  if (((iVar4 == 0) || (iVar4 = FUN_00418380(param_1,0x12), iVar4 == 0)) ||

     (iVar4 = FUN_00418380(param_1,0x13), iVar4 == 0)) {

    iVar4 = FUN_00418380(param_1,4);

    if ((((iVar4 == 0) && (iVar4 = base_bldg_is_alive_at_all_2(param_1,0x11), iVar4 == 0)) ||

        ((iVar4 = FUN_00418380(param_1,5), iVar4 == 0 &&

         (iVar4 = base_bldg_is_alive_at_all_2(param_1,0x12), iVar4 == 0)))) ||

       ((iVar4 = FUN_00418380(param_1,6), iVar4 == 0 &&

        (iVar4 = base_bldg_is_alive_at_all_2(param_1,0x13), iVar4 == 0)))) {

      iVar4 = FUN_00418380(param_1,0x11);

      if ((((iVar4 == 0) && (iVar4 = FUN_00418380(param_1,0x12), iVar4 == 0)) &&

          (iVar4 = FUN_00418380(param_1,0x13), iVar4 == 0)) &&

         (((iVar4 = FUN_00418380(param_1,4), iVar4 == 0 ||

           (iVar4 = FUN_00418380(param_1,5), iVar4 == 0)) ||

          (iVar4 = FUN_00418380(param_1,6), iVar4 == 0)))) {

        *(undefined4 *)(iVar1 + 0xa4) = 1;

        *(undefined4 *)(iVar1 + 0xc0) = 1;

        *(undefined4 *)(iVar1 + 0xdc) = 1;

      }

    }

    else {

      *(undefined4 *)(iVar1 + 0x210) = 1;

      *(undefined4 *)(iVar1 + 0x22c) = 1;

      *(undefined4 *)(iVar1 + 0x248) = 1;

    }

  }

  iVar4 = FUN_00418380(param_1,0x14);

  if ((iVar4 == 0) || (iVar4 = FUN_00418380(param_1,0x15), iVar4 == 0)) {

    iVar4 = FUN_00418380(param_1,7);

    if (((iVar4 == 0) && (iVar4 = base_bldg_is_alive_at_all_2(param_1,0x14), iVar4 == 0)) ||

       ((iVar4 = FUN_00418380(param_1,8), iVar4 == 0 &&

        (iVar4 = base_bldg_is_alive_at_all_2(param_1,0x15), iVar4 == 0)))) {

      iVar4 = FUN_00418380(param_1,0x14);

      if (((iVar4 == 0) && (iVar4 = FUN_00418380(param_1,0x15), iVar4 == 0)) &&

         ((iVar4 = FUN_00418380(param_1,7), iVar4 == 0 ||

          (iVar4 = FUN_00418380(param_1,8), iVar4 == 0)))) {

        *(undefined4 *)(iVar1 + 0xf8) = 1;

        *(undefined4 *)(iVar1 + 0x114) = 1;

      }

    }

    else {

      *(undefined4 *)(iVar1 + 0x264) = 1;

      *(undefined4 *)(iVar1 + 0x280) = 1;

    }

  }

  iVar4 = FUN_00418380(param_1,0x16);

  if (((iVar4 == 0) || (iVar4 = FUN_00418380(param_1,0x17), iVar4 == 0)) ||

     (iVar4 = FUN_00418380(param_1,0x18), iVar4 == 0)) {

    iVar4 = FUN_00418380(param_1,9);

    if ((((iVar4 == 0) && (iVar4 = base_bldg_is_alive_at_all_2(param_1,0x16), iVar4 == 0)) ||

        ((iVar4 = FUN_00418380(param_1,10), iVar4 == 0 &&

         (iVar4 = base_bldg_is_alive_at_all_2(param_1,0x17), iVar4 == 0)))) ||

       ((iVar4 = FUN_00418380(param_1,0xb), iVar4 == 0 &&

        (iVar4 = base_bldg_is_alive_at_all_2(param_1,0x18), iVar4 == 0)))) {

      iVar4 = FUN_00418380(param_1,0x16);

      if ((((iVar4 == 0) && (iVar4 = FUN_00418380(param_1,0x17), iVar4 == 0)) &&

          (iVar4 = FUN_00418380(param_1,0x18), iVar4 == 0)) &&

         (((iVar4 = FUN_00418380(param_1,9), iVar4 == 0 ||

           (iVar4 = FUN_00418380(param_1,10), iVar4 == 0)) ||

          (iVar4 = FUN_00418380(param_1,0xb), iVar4 == 0)))) {

        *(undefined4 *)(iVar1 + 0x130) = 1;

        *(undefined4 *)(iVar1 + 0x14c) = 1;

        *(undefined4 *)(iVar1 + 0x168) = 1;

      }

    }

    else {

      *(undefined4 *)(iVar1 + 0x29c) = 1;

      *(undefined4 *)(iVar1 + 0x2b8) = 1;

      *(undefined4 *)(iVar1 + 0x2d4) = 1;

    }

  }

  iVar1 = *(int *)(param_1 + 0x100);

  iVar4 = FUN_00418380(param_1,0x19);

  if (iVar4 == 0) {

    iVar4 = FUN_00418380(param_1,0xc);

    if ((iVar4 == 0) && (iVar4 = base_bldg_is_alive_at_all_2(param_1,0x19), iVar4 == 0)) {

      *(undefined4 *)(iVar1 + 0x184) = 1;

    }

    else {

      *(undefined4 *)(iVar1 + 0x2f0) = 1;

    }

  }

  iVar1 = *(int *)(param_1 + 0x100);

  iVar4 = FUN_00418380(param_1,0x10);

  if (iVar4 == 0) {

    iVar4 = FUN_00418380(param_1,3);

    if ((iVar4 == 0) && (iVar4 = base_bldg_is_alive_at_all_2(param_1,0x10), iVar4 == 0)) {

      *(undefined4 *)(iVar1 + 0x88) = 1;

      return;

    }

    *(undefined4 *)(iVar1 + 500) = 1;

  }

  return;

}

/* ===== meccbasepit_swap_model__FP6OBJECTi13e_bldg_objset_2 @ 0x00409780 ===== */
/* PS2 candidate: meccbasepit_swap_model__FP6OBJECTi13e_bldg_objset (conf 0.557) */



void meccbasepit_swap_model__FP6OBJECTi13e_bldg_objset_2(int param_1,int param_2,int param_3)



{

  int iVar1;

  undefined4 uVar2;

  

  iVar1 = *(int *)(*(int *)(param_1 + 0x100) + 0x20 + param_2 * 0x1c);

  if (param_3 == 0) {

    if (**(int **)(iVar1 + 8) != *(int *)(&DAT_00554564 + param_2 * 0x58)) {

      uVar2 = objectset_find(*(int *)(&DAT_00554564 + param_2 * 0x58));

      object_set_objectset(iVar1,uVar2);

      return;

    }

  }

  else if (param_3 == 1) {

    if (**(int **)(iVar1 + 8) != *(int *)(&DAT_00554568 + param_2 * 0x58)) {

      uVar2 = objectset_find(*(int *)(&DAT_00554568 + param_2 * 0x58));

      object_set_objectset(iVar1,uVar2);

      return;

    }

  }

  else {

    object_set_objectset(iVar1,param_2);

  }

  return;

}

/* ===== kabutoai_anim_update @ 0x00409930 ===== */
void kabutoai_anim_update(int param_1,int param_2)



{

  int iVar1;

  undefined4 *puVar2;

  int iVar3;

  float10 fVar4;

  

  puVar2 = DAT_00632d98;

  do {

    if (puVar2 == (undefined4 *)0x0) {

      return;

    }

    iVar1 = puVar2[3];

    if ((((*(int *)(iVar1 + 4) == 0xb) && (*(int *)(iVar1 + 0x274) != 0)) &&

        ((iVar3 = meccbasepit_bldg_from_object(*(int *)(iVar1 + 0x274)), iVar3 != 0 ||

         (iVar3 = reaperbase_bldg_from_object(*(undefined4 *)(iVar1 + 0x274)), iVar3 != 0)))) &&

       ((*(int *)(iVar1 + 0x274) == *(int *)(param_1 + 0x274) && (*(int *)(iVar1 + 0xe4) == 0x37))))

    {

      *(undefined4 *)(iVar1 + 0xe4) = 0x38;

      fVar4 = (float10)rndfloatrange(0x41a00000,0x42200000);

      *(undefined4 *)(iVar1 + 0xec) = 0x41200000;

      *(float *)(iVar1 + 0xa0) = (float)(fVar4 + (float10)*(float *)(iVar1 + 0xa0));

      iVar3 = reaper_0052e4a0(iVar1);

      if (iVar3 != 0) {

        kabutoai_select_punch_anim__FP6OBJECT_2(iVar1);

      }

      param_2 = param_2 + -1;

      if (param_2 < 1) {

        return;

      }

    }

    puVar2 = (undefined4 *)*puVar2;

  } while( true );

}

/* ===== FUN_00409b60 @ 0x00409B60 ===== */
/* PS2 candidate: reaperbasebldg_shot (conf 0.361) */



void FUN_00409b60(int param_1,int param_2)



{

  float fVar1;

  int iVar2;

  int *piVar3;

  int iVar4;

  int *piVar5;

  float10 fVar6;

  char *pcVar7;

  undefined4 uVar8;

  undefined1 *puVar9;

  undefined1 local_34 [4];

  undefined4 local_30;

  undefined4 local_2c;

  undefined4 local_28;

  

  iVar4 = *(int *)(*(int *)(param_1 + 0x274) + 0x100);

  fVar6 = (float10)bldg_get_max_energy(param_1);

  fVar1 = *(float *)(DAT_00632ed8 + 0xb80) * (float)fVar6 * 0.01;

  if (*(int *)(param_1 + 0x274) != 0) {

    iVar2 = 0;

    piVar3 = (int *)(*(int *)(*(int *)(param_1 + 0x274) + 0x100) + 0x20);

    do {

      if (*piVar3 == param_1) goto LAB_00409bc6;

      iVar2 = iVar2 + 1;

      piVar3 = piVar3 + 7;

    } while (iVar2 < 0x1a);

  }

  iVar2 = -1;

LAB_00409bc6:

  collgrid_clear_grid(param_1);

  *(uint *)(param_1 + 0x1c8) = *(uint *)(param_1 + 0x1c8) | 0x800;

  bldg_set_energy(param_1,fVar1);

  *(float *)(param_1 + 0x278) = (float)fVar6 - fVar1;

  *(uint *)(param_1 + 0x1cc) = *(uint *)(param_1 + 0x1cc) | 1;

  if (iVar2 < 0) {

    piVar5 = (int *)(iVar4 + 0x574);

    iVar4 = 8;

    piVar3 = piVar5;

    do {

      if (*piVar3 == param_1) {

        *piVar3 = 0;

      }

      piVar3 = piVar3 + 1;

      iVar4 = iVar4 + -1;

    } while (iVar4 != 0);

    object_destroy(param_1);

    if ((*(int *)(param_1 + 4) == 0x3d7) && (piVar3 = DAT_00632d9c, DAT_00632d9c != (int *)0x0)) {

      while (((iVar4 = piVar3[3], *(int *)(iVar4 + 4) != 0x3d7 ||

              (((*(int *)(iVar4 + 0x18c) != 1 &&

                (*(int *)(iVar4 + 0x18c) != *(int *)(param_1 + 0x18c))) || (iVar4 == param_1)))) ||

             ((char)((uint)*(undefined4 *)(iVar4 + 0xd8) >> 8) < '\0'))) {

        piVar3 = (int *)*piVar3;

        if (piVar3 == (int *)0x0) {

          return;

        }

      }

      iVar2 = 8;

      do {

        if (*piVar5 == iVar4) {

          *piVar5 = 0;

        }

        piVar5 = piVar5 + 1;

        iVar2 = iVar2 + -1;

      } while (iVar2 != 0);

      object_destroy(iVar4);

      if (param_2 == 0) {

        local_30 = *(undefined4 *)(iVar4 + 0xa0);

        local_2c = *(undefined4 *)(iVar4 + 0xa4);

        puVar9 = local_34;

        local_28 = *(undefined4 *)(iVar4 + 0xa8);

        uVar8 = 8;

        pcVar7 = s_FX_stone_explode_Large_00554f20;

        fx_get_free_effect__Fv();

        sound_play_obj(0x615,param_1,pcVar7,uVar8,puVar9);

        return;

      }

    }

  }

  else {

    comm_wincond_destroy(param_1);

  }

  return;

}

/* ===== FUN_0040a550 @ 0x0040A550 ===== */
void FUN_0040a550(int param_1,int param_2)



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

        fVar4 = (float10)bldg_get_max_energy(iVar2);

        if ((float10)(float)fVar3 < fVar4) {

          *(undefined4 *)(iVar2 + 0xe4) = 3;

        }

      }

    }

    *(int *)(*(int *)(param_1 + 0x100) + 0x20) = param_2;

    meccbase_update_icons(iVar1);

  }

  return;

}

/* ===== object_spawn_class4 @ 0x0040A5E0 ===== */
undefined4 object_spawn_class4(int param_1,int param_2)



{

  undefined4 uVar1;

  int iVar2;

  int *piVar3;

  int iVar4;

  undefined4 local_c;

  undefined4 local_8;

  undefined4 local_4;

  

  iVar2 = *(int *)(param_1 + 0x100);

  piVar3 = (int *)(iVar2 + 0x20);

  iVar4 = 0;

  do {

    if (((iVar4 != param_2) && (*piVar3 != 0)) && (*(int *)(*piVar3 + 0xe4) < 2)) {

      if ((0xc < iVar4) && (piVar3[-0x5b] != 0)) {

        *(undefined4 *)(piVar3[-0x5b] + 0x184) = 0;

      }

      object_destroy(*piVar3);

      *piVar3 = 0;

    }

    iVar4 = iVar4 + 1;

    piVar3 = piVar3 + 7;

  } while (iVar4 < 0x1a);

  iVar4 = param_2 * 0x1c + iVar2;

  if ((*(int *)(param_2 * 0x1c + 0x20 + iVar2) == 0) &&

     ((0xc < param_2 || (*(int *)(iVar4 + 0x18c) == 0)))) {

    iVar2 = (param_2 % 0xd) * 0x1c + iVar2;

    local_c = *(undefined4 *)(iVar2 + 0x24);

    local_8 = *(undefined4 *)(iVar2 + 0x28);

    local_4 = *(undefined4 *)(iVar2 + 0x2c);

    uVar1 = *(undefined4 *)(iVar2 + 0x30);

    iVar2 = object_allocate_type((&DAT_00554560)[param_2 * 0x16],0x80000000);

    object_set_location_p3d(iVar2,&local_c);

    *(undefined4 *)(iVar2 + 200) = uVar1;

    *(undefined4 *)(iVar2 + 0xcc) = 0;

    *(undefined4 *)(iVar2 + 0xd0) = 0;

    *(undefined4 *)(iVar2 + 0xe4) = 1;

    *(uint *)(iVar2 + 0xd8) = *(uint *)(iVar2 + 0xd8) | 0x10;

    if (DAT_00632bb0 == 0) {

      *(undefined4 *)(iVar2 + 0x184) = 0x3f800000;

    }

    else {

      *(undefined4 *)(iVar2 + 0x184) = 0x3dcccccd;

    }

    *(int *)(iVar2 + 0x274) = param_1;

    bldg_set_energy(iVar2,0);

    ObjectSetAnim(iVar2,1,0x84,0,0,0);

    *(undefined4 *)(iVar2 + 0x14) = 0x3f800000;

    *(uint *)(iVar2 + 0x1c8) = *(uint *)(iVar2 + 0x1c8) & 0xfffdffff | 0x800;

    *(int *)(iVar4 + 0x20) = iVar2;

    if (DAT_00632bb0 != 0) {

      if ((0xc < param_2) && (*(int *)(iVar4 + -0x14c) != 0)) {

        *(undefined4 *)(*(int *)(iVar4 + -0x14c) + 0x184) = 0x3f800000;

      }

      if (param_2 % 0xd == 0) {

        *(undefined4 *)(param_1 + 0x184) = 0x3f800000;

      }

    }

    return 1;

  }

  return 0;

}

/* ===== meccbase_hide_tentatives_2 @ 0x0040A7B0 ===== */
/* PS2 candidate: meccbase_hide_tentatives (conf 0.64) */



void meccbase_hide_tentatives_2(int param_1)



{

  undefined4 uVar1;

  int *piVar2;

  int iVar3;

  

  iVar3 = 0;

  piVar2 = (int *)(*(int *)(DAT_00632bbc + 0x100) + 0x20);

  do {

    if ((*piVar2 != 0) && (*(int *)(*piVar2 + 0xe4) < 3)) {

      if ((0xc < iVar3) && (piVar2[-0x5b] != 0)) {

        if (param_1 == 0) {

          uVar1 = 0x3f800000;

        }

        else {

          uVar1 = 0;

        }

        *(undefined4 *)(piVar2[-0x5b] + 0x184) = uVar1;

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

  } while (iVar3 < 0x1a);

  return;

}

/* ===== objtype_anim_scan @ 0x0040A820 ===== */
undefined4 objtype_anim_scan(int param_1,int param_2,undefined4 *param_3)



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

  iVar2 = base_bldg_is_alive_at_all(param_1,0xd);

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

    iVar2 = 2;

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

          if (local_10 == -1) goto LAB_0040a91a;

          goto LAB_0040a993;

        }

        iVar3 = iVar3 + 1;

        piVar5 = piVar5 + 2;

      } while (iVar3 < 0xc);

      local_10 = local_10 + 1;

      piVar4 = piVar4 + 0x18;

    } while (local_10 < iVar2);

  }

LAB_0040a91a:

  iVar3 = 0;

  local_14 = 999999.0;

  local_10 = -1;

  if (iVar2 != 0) {

    puVar6 = (undefined4 *)(iVar1 + 0x374);

    do {

      FUN_00418630(local_18,*puVar6,local_c);

      fVar7 = (float10)distancesq2d__FP3P3DT0(local_c,param_2 + 0xa0);

      if (fVar7 < (float10)local_14) {

        local_14 = (float)fVar7;

        local_10 = iVar3;

      }

      iVar3 = iVar3 + 1;

      puVar6 = puVar6 + 0x18;

    } while (iVar3 < iVar2);

  }

LAB_0040a993:

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

LAB_0040ab0e:

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

      fVar7 = (float10)distancesq2d__FP3P3DT0(local_c,param_2 + 0xa0);

      fVar8 = (float10)distancesq2d__FP3P3DT0(local_c,*piVar4 + 0xa0);

      if ((float10)(float)fVar7 < fVar8) {

        iVar3 = local_10 * 0xc + iVar2;

        *(undefined4 *)(*(int *)(iVar1 + 0x370 + iVar3 * 8) + 0xe4) = 0x1e;

        ai_clear_move_goal(*(undefined4 *)(iVar1 + 0x370 + iVar3 * 8));

        *(undefined4 *)(*(int *)(*(int *)(iVar1 + 0x370 + iVar3 * 8) + 0x100) + 0x28) = 0xffffffff;

        *param_3 = *(undefined4 *)(iVar1 + 0x374 + iVar3 * 8);

        *(int *)(iVar1 + 0x370 + iVar3 * 8) = param_2;

        goto LAB_0040ab0e;

      }

    }

    iVar2 = iVar2 + 1;

    piVar4 = piVar4 + 2;

    if (0xb < iVar2) {

      return 0;

    }

  } while( true );

}

/* ===== FUN_0040ab60 @ 0x0040AB60 ===== */
void FUN_0040ab60(int param_1,int param_2)



{

  int iVar1;

  int *piVar2;

  int iVar3;

  

  iVar3 = *(int *)(param_1 + 0x100);

  iVar1 = FUN_00418380(param_1,0);

  iVar1 = (iVar1 != 0) + 1;

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

/* ===== FUN_0040abb0 @ 0x0040ABB0 ===== */
int FUN_0040abb0(int param_1)



{

  int iVar1;

  int iVar2;

  

  iVar1 = *(int *)(param_1 + 0x100);

  iVar2 = FUN_00418510(param_1,0xd);

  if (iVar2 != 0) {

    return *(int *)(iVar1 + 0x18c);

  }

  iVar2 = FUN_00418510(param_1,0);

  if (iVar2 != 0) {

    return *(int *)(iVar1 + 0x20);

  }

  return param_1;

}

/* ===== FUN_0040abf0 @ 0x0040ABF0 ===== */
undefined4 FUN_0040abf0(int param_1,int *param_2)



{

  int iVar1;

  int iVar2;

  

  iVar1 = *(int *)(*(int *)(param_1 + 0x274) + 0x100);

  iVar2 = FUN_00418380(*(int *)(param_1 + 0x274),0);

  if ((iVar2 != 0) && (iVar1 = *(int *)(iVar1 + 0x20), (*(uint *)(iVar1 + 0xe0) & 0xfff) != 0xfff))

  {

    iVar2 = 0;

    do {

      if ((*(uint *)(iVar1 + 0xe0) & 1 << ((byte)iVar2 & 0x1f)) == 0) {

        *(uint *)(iVar1 + 0xe0) = 1 << ((byte)iVar2 & 0x1f) | *(uint *)(iVar1 + 0xe0);

        *param_2 = iVar2 + 0x47;

        return 0;

      }

      iVar2 = iVar2 + 1;

    } while (iVar2 < 0xc);

  }

  return 0xffffffff;

}

/* ===== FUN_0040ac70 @ 0x0040AC70 ===== */
void FUN_0040ac70(int param_1,int param_2,int param_3)



{

  int iVar1;

  

  if ((((param_2 != -1) && (param_2 == 0)) &&

      (iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 0x274) + 0x100) + 0x20), iVar1 != 0)) &&

     (-1 < param_3)) {

    *(uint *)(iVar1 + 0xe0) = *(uint *)(iVar1 + 0xe0) & ~(1 << ((char)param_3 + 0xb9U & 0x1f));

  }

  return;

}

/* ===== meccbasepit_get_table_ptr @ 0x0040ACC0 ===== */
/* PS2 candidate: meccbasepit_get_table_ptr (conf 0.684) */



undefined4 meccbasepit_get_table_ptr(int param_1,int param_2)



{

  if (param_2 == -1) {

    return 0;

  }

  if (param_2 != 0) {

    return 0;

  }

  return *(undefined4 *)(*(int *)(param_1 + 0x100) + 0x20);

}

/* ===== meccbasepit_bldg_from_object @ 0x0040ACF0 ===== */
/* PS2 candidate: meccbasepit_bldg_from_object (conf 0.767) */



int meccbasepit_bldg_from_object(int param_1)



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

    } while (iVar1 < 0x1a);

  }

  return -1;

}

/* ===== meccbase_get_max_energy @ 0x0040AD30 ===== */
/* PS2 candidate: meccbase_get_max_energy (conf 0.408) */



float10 meccbase_get_max_energy(int param_1)



{

  int iVar1;

  int *piVar2;

  

  iVar1 = meccbasepit_bldg_from_object(param_1);

  if (iVar1 != 0) {

    return (float10)*(float *)(DAT_00632ed8 + 0x628);

  }

  if (*(int *)(param_1 + 0x274) != 0) {

    iVar1 = 0;

    piVar2 = (int *)(*(int *)(*(int *)(param_1 + 0x274) + 0x100) + 0x20);

    do {

      if (*piVar2 == param_1) {

        if (-1 < iVar1) {

          return (float10)(float)(&DAT_0055456c)[iVar1 * 0x16];

        }

        break;

      }

      iVar1 = iVar1 + 1;

      piVar2 = piVar2 + 7;

    } while (iVar1 < 0x1a);

  }

  if ((8 < *(int *)(param_1 + 0xe4)) && (*(int *)(param_1 + 0xe4) < 0xd)) {

    return (float10)*(float *)(DAT_00632ed8 + 0x894);

  }

  return (float10)100.0;

}

/* ===== FUN_0040adb0 @ 0x0040ADB0 ===== */
undefined4 FUN_0040adb0(int param_1)



{

  int iVar1;

  int iVar2;

  

  iVar1 = *(int *)(param_1 + 0x100);

  iVar2 = base_bldg_is_alive_at_all(param_1,0xe);

  if (iVar2 != 0) {

    return *(undefined4 *)(iVar1 + 0x1a8);

  }

  iVar2 = base_bldg_is_alive_at_all(param_1,1);

  if (iVar2 != 0) {

    return *(undefined4 *)(iVar1 + 0x3c);

  }

  iVar2 = base_bldg_is_alive_at_all_2(param_1,0xe);

  if (iVar2 != 0) {

    return *(undefined4 *)(iVar1 + 0x1a8);

  }

  return 0;

}

/* ===== FUN_0040ae10 @ 0x0040AE10 ===== */
undefined4 FUN_0040ae10(int param_1)



{

  int iVar1;

  int iVar2;

  

  iVar1 = *(int *)(param_1 + 0x100);

  iVar2 = base_bldg_is_alive_at_all(param_1,0xe);

  if (iVar2 != 0) {

    return *(undefined4 *)(iVar1 + 0x1a8);

  }

  return 0;

}

/* ===== FUN_0040ae40 @ 0x0040AE40 ===== */
undefined4 FUN_0040ae40(int param_1)



{

  int iVar1;

  int iVar2;

  

  iVar1 = *(int *)(param_1 + 0x100);

  iVar2 = FUN_00418380(param_1,0xf);

  if (iVar2 != 0) {

    return *(undefined4 *)(iVar1 + 0x1c4);

  }

  iVar2 = FUN_00418380(param_1,2);

  if (iVar2 != 0) {

    return *(undefined4 *)(iVar1 + 0x58);

  }

  return 0;

}

/* ===== FUN_0040ae80 @ 0x0040AE80 ===== */
undefined4 FUN_0040ae80(int param_1)



{

  int iVar1;

  int iVar2;

  

  iVar1 = *(int *)(param_1 + 0x100);

  iVar2 = FUN_00418380(param_1,0x10);

  if (iVar2 != 0) {

    return *(undefined4 *)(iVar1 + 0x1e0);

  }

  iVar2 = FUN_00418380(param_1,3);

  if (iVar2 != 0) {

    return *(undefined4 *)(iVar1 + 0x74);

  }

  return 0;

}

/* ===== FUN_0040aec0 @ 0x0040AEC0 ===== */
undefined4 FUN_0040aec0(int param_1)



{

  int iVar1;

  int iVar2;

  

  iVar1 = *(int *)(param_1 + 0x100);

  iVar2 = FUN_00418380(param_1,0xd);

  if (iVar2 != 0) {

    return *(undefined4 *)(iVar1 + 0x18c);

  }

  return 0;

}

/* ===== meccbasepit_create_food @ 0x0040AFB0 ===== */
/* PS2 candidate: meccbasepit_create_food (conf 0.46) */



void meccbasepit_create_food(int param_1,int param_2)



{

  int iVar1;

  undefined4 uVar2;

  int iVar3;

  undefined4 uVar4;

  

  iVar1 = *(int *)(param_1 + 0x100);

  uVar2 = FUN_004188a0(param_1);

  iVar3 = *(int *)(iVar1 + 0x52c + param_2 * 4);

  if (iVar3 != 0) {

    object_destroy(iVar3);

  }

  iVar3 = crt_rand_scaled(100);

  if (iVar3 < 0x32) {

    uVar4 = 0x2f5;

  }

  else {

    uVar4 = 0x2f6;

  }

  iVar3 = object_allocate_type(uVar4,0);

  *(int *)(iVar1 + 0x52c + param_2 * 4) = iVar3;

  FUN_00418630(uVar2,0x55,iVar3 + 0xa0);

  object_copy_posdirinfo(*(undefined4 *)(iVar1 + 0x52c + param_2 * 4));

  *(undefined4 *)(*(int *)(iVar1 + 0x52c + param_2 * 4) + 0x18c) = *(undefined4 *)(param_1 + 0x18c);

  *(undefined4 *)(*(int *)(iVar1 + 0x52c + param_2 * 4) + 0xec) = 0;

  return;

}

/* ===== FUN_0040b1d0 @ 0x0040B1D0 ===== */
int FUN_0040b1d0(int param_1,int param_2)



{

  int iVar1;

  

  iVar1 = *(int *)(*(int *)(param_1 + 0x100) + 0x52c + param_2 * 4);

  if (iVar1 == 0) {

    meccbasepit_create_food(param_1,param_2);

    return 0;

  }

  if (*(float *)(iVar1 + 0xec) < 1.0) {

    return 0;

  }

  *(undefined4 *)(*(int *)(param_1 + 0x100) + 0x52c + param_2 * 4) = 0;

  return iVar1;

}

/* ===== FUN_0040b2c0 @ 0x0040B2C0 ===== */
void FUN_0040b2c0(void)



{

  int *piVar1;

  int iVar2;

  int *piVar3;

  int *piVar4;

  

  piVar3 = &DAT_00632da8;

  iVar2 = DAT_00632da8;

  while (iVar2 != 0) {

    piVar1 = (int *)*piVar3;

    piVar4 = piVar1;

    if ((*(byte *)(piVar1 + 10) & 1) != 0) {

      *piVar3 = *piVar1;

      *piVar1 = (int)DAT_00632dac;

      piVar4 = piVar3;

      DAT_00632dac = piVar1;

    }

    piVar3 = piVar4;

    iVar2 = *piVar4;

  }

  return;

}

/* ===== FUN_0040b300 @ 0x0040B300 ===== */
void FUN_0040b300(void)



{

  undefined4 *puVar1;

  undefined4 *puVar2;

  undefined4 *puVar3;

  

  for (puVar1 = DAT_00632da8; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {

    puVar1[10] = puVar1[10] | 1;

  }

  puVar2 = &DAT_00632da8;

  puVar1 = DAT_00632da8;

  while (puVar1 != (undefined4 *)0x0) {

    puVar1 = (undefined4 *)*puVar2;

    puVar3 = puVar1;

    if ((*(byte *)(puVar1 + 10) & 1) != 0) {

      *puVar2 = *puVar1;

      *puVar1 = DAT_00632dac;

      puVar3 = puVar2;

      DAT_00632dac = puVar1;

    }

    puVar2 = puVar3;

    puVar1 = (undefined4 *)*puVar3;

  }

  return;

}

/* ===== blood_from_point @ 0x0040B350 ===== */
/* PS2 candidate: blood_from_point (conf 0.41) */



void blood_from_point(int *param_1,int param_2,undefined4 param_3,undefined4 param_4,

                     undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,

                     undefined4 param_9)



{

  int *piVar1;

  int iVar2;

  int *piVar3;

  int *piVar4;

  float10 fVar5;

  float10 fVar6;

  float local_8;

  float local_4;

  

  param_2 = rndintrange(param_2,param_3);

  if (0 < param_2) {

    do {

      if (DAT_00632dac == (int *)0x0) {

        iVar2 = *(int *)*DAT_00632da8;

        piVar3 = (int *)*DAT_00632da8;

        piVar4 = DAT_00632da8;

        while (piVar1 = piVar3, iVar2 != 0) {

          piVar3 = (int *)*piVar1;

          iVar2 = *piVar3;

          piVar4 = piVar1;

        }

        piVar3 = (int *)*piVar4;

        *piVar4 = 0;

      }

      else {

        piVar3 = DAT_00632dac;

        DAT_00632dac = (int *)*DAT_00632dac;

      }

      piVar4 = piVar3;

      for (iVar2 = 0xd; iVar2 != 0; iVar2 = iVar2 + -1) {

        *piVar4 = 0;

        piVar4 = piVar4 + 1;

      }

      *piVar3 = (int)DAT_00632da8;

      DAT_00632da8 = piVar3;

      piVar3[5] = 0x3f800000;

      piVar3[1] = DAT_005841c8;

      piVar3[2] = *param_1;

      piVar3[3] = param_1[1];

      piVar3[4] = param_1[2];

      fVar5 = (float10)rndfloatrange(*(undefined4 *)(DAT_00632ed8 + 0x2b4),

                                     *(undefined4 *)(DAT_00632ed8 + 0x2b8));

      piVar3[5] = (int)(float)fVar5;

      fVar5 = (float10)rndfloatrange(param_4,param_5);

      fVar6 = (float10)rndfloatrange(param_6,param_7);

      sine_cos_lookup((float)fVar5,&local_8,&local_4);

      piVar3[8] = (int)(local_8 * (float)fVar6);

      piVar3[9] = (int)-(local_4 * (float)fVar6);

      fVar5 = (float10)rndfloatrange(param_8,param_9);

      piVar3[7] = (int)(float)fVar5;

      piVar3[0xb] = (int)(*(float *)(DAT_00632ed8 + 0x2a8) + *(float *)(DAT_00632ed8 + 0x2a4));

      fVar5 = (float10)rndfloat(0x3f800000);

      piVar3[6] = (int)(float)fVar5;

      param_2 = param_2 + -1;

      piVar3[10] = piVar3[10] | 4;

    } while (param_2 != 0);

  }

  return;

}

/* ===== blood_from_object @ 0x0040B4B0 ===== */
/* PS2 candidate: blood_from_object (conf 0.406) */



void blood_from_object(int param_1)



{

  float fVar1;

  float fVar2;

  int *piVar3;

  int iVar4;

  int iVar5;

  int *piVar6;

  int *piVar7;

  float10 fVar8;

  

  iVar4 = rndintrange(*(undefined4 *)(DAT_00632ed8 + 0x2c4),*(undefined4 *)(DAT_00632ed8 + 0x2c8));

  if (0 < iVar4) {

    do {

      if (DAT_00632dac == (int *)0x0) {

        iVar5 = *(int *)*DAT_00632da8;

        piVar6 = (int *)*DAT_00632da8;

        piVar7 = DAT_00632da8;

        while (piVar3 = piVar6, iVar5 != 0) {

          piVar6 = (int *)*piVar3;

          iVar5 = *piVar6;

          piVar7 = piVar3;

        }

        piVar6 = (int *)*piVar7;

        *piVar7 = 0;

      }

      else {

        piVar6 = DAT_00632dac;

        DAT_00632dac = (int *)*DAT_00632dac;

      }

      piVar7 = piVar6;

      for (iVar5 = 0xd; iVar5 != 0; iVar5 = iVar5 + -1) {

        *piVar7 = 0;

        piVar7 = piVar7 + 1;

      }

      *piVar6 = (int)DAT_00632da8;

      DAT_00632da8 = piVar6;

      piVar6[5] = 0x3f800000;

      fVar1 = *(float *)(param_1 + 0xc4);

      fVar2 = *(float *)(param_1 + 0x1ec);

      piVar6[1] = DAT_005841c8;

      fVar1 = fVar1 * fVar2 * 0.1;

      piVar6[2] = *(int *)(param_1 + 0xa0);

      piVar6[3] = *(int *)(param_1 + 0xa4);

      piVar6[4] = *(int *)(param_1 + 0xa8);

      piVar6[4] = (int)(*(float *)(param_1 + 0xc4) * *(float *)(param_1 + 0x1e8) + (float)piVar6[4])

      ;

      fVar8 = (float10)rndfloatrange(*(undefined4 *)(DAT_00632ed8 + 0x2b4),

                                     *(undefined4 *)(DAT_00632ed8 + 0x2b8));

      piVar6[5] = (int)(float)(fVar8 * (float10)fVar1);

      fVar8 = (float10)rndfloatrange(-*(float *)(DAT_00632ed8 + 0x3d0),

                                     *(undefined4 *)(DAT_00632ed8 + 0x3d0));

      piVar6[8] = (int)(float)(fVar8 * (float10)fVar1);

      fVar8 = (float10)rndfloatrange(-*(float *)(DAT_00632ed8 + 0x3d0),

                                     *(undefined4 *)(DAT_00632ed8 + 0x3d0));

      piVar6[9] = (int)(float)(fVar8 * (float10)fVar1);

      fVar8 = (float10)rndfloatrange(*(undefined4 *)(DAT_00632ed8 + 700),

                                     *(undefined4 *)(DAT_00632ed8 + 0x2c0));

      piVar6[7] = (int)(float)(fVar8 * (float10)fVar1);

      piVar6[0xb] = (int)(*(float *)(DAT_00632ed8 + 0x2a8) + *(float *)(DAT_00632ed8 + 0x2a4));

      fVar8 = (float10)rndfloat(0x3f800000);

      piVar6[6] = (int)(float)fVar8;

      iVar4 = iVar4 + -1;

      piVar6[10] = piVar6[10] | 4;

    } while (iVar4 != 0);

  }

  return;

}

/* ===== particles_decay_update @ 0x0040B640 ===== */
void particles_decay_update(void)



{

  float *pfVar1;

  float fVar2;

  float fVar3;

  int *piVar4;

  int *piVar5;

  int iVar6;

  int *piVar7;

  int *piVar8;

  float10 fVar9;

  

  piVar4 = DAT_00632da8;

  do {

    if (piVar4 == (int *)0x0) {

      return;

    }

    pfVar1 = (float *)(piVar4 + 2);

    fVar9 = (float10)FUN_00518b70(0,pfVar1);

    fVar2 = (float)fVar9;

    piVar4[7] = (int)((float)piVar4[7] - *(float *)(DAT_00632ed8 + 0x2ac) * fVar2);

    if ((float)piVar4[8] <= 0.0) {

      if (((float)piVar4[8] < 0.0) &&

         (fVar3 = *(float *)(DAT_00632ed8 + 0x2b0) * fVar2 + (float)piVar4[8],

         piVar4[8] = (int)fVar3, 0.0 < fVar3)) goto LAB_0040b6e3;

    }

    else {

      fVar3 = (float)piVar4[8] - *(float *)(DAT_00632ed8 + 0x2b0) * fVar2;

      piVar4[8] = (int)fVar3;

      if (fVar3 < 0.0) {

LAB_0040b6e3:

        piVar4[8] = 0;

      }

    }

    if ((float)piVar4[9] <= 0.0) {

      if (((float)piVar4[9] < 0.0) &&

         (fVar3 = *(float *)(DAT_00632ed8 + 0x2b0) * fVar2 + (float)piVar4[9],

         piVar4[9] = (int)fVar3, 0.0 < fVar3)) goto LAB_0040b74d;

    }

    else {

      fVar3 = (float)piVar4[9] - *(float *)(DAT_00632ed8 + 0x2b0) * fVar2;

      piVar4[9] = (int)fVar3;

      if (fVar3 < 0.0) {

LAB_0040b74d:

        piVar4[9] = 0;

      }

    }

    *pfVar1 = fVar2 * (float)piVar4[8] + *pfVar1;

    piVar4[3] = (int)(fVar2 * (float)piVar4[9] + (float)piVar4[3]);

    piVar4[4] = (int)(fVar2 * (float)piVar4[7] + (float)piVar4[4]);

    fVar3 = fVar2 * 0.25 + (float)piVar4[6];

    piVar4[6] = (int)fVar3;

    if (1.0 <= fVar3) {

      piVar4[6] = (int)(fVar3 - 1.0);

    }

    if (1.0 <= (float)piVar4[6]) {

      piVar4[6] = (int)((float)piVar4[6] - 1.0);

    }

    if ((*(byte *)(piVar4 + 10) & 4) != 0) {

      fVar9 = (float10)FUN_00518b70(0,pfVar1);

      fVar3 = (float)piVar4[0xc];

      piVar4[0xc] = (int)(float)((float10)fVar3 - fVar9);

      if ((float10)fVar3 - fVar9 <= (float10)0.0) {

        fVar9 = (float10)rndfloat(0x3e800000);

        piVar4[0xc] = (int)(float)fVar9;

        if (DAT_00632dac == (int *)0x0) {

          iVar6 = *(int *)*DAT_00632da8;

          piVar7 = (int *)*DAT_00632da8;

          piVar8 = DAT_00632da8;

          while (piVar5 = piVar7, iVar6 != 0) {

            piVar7 = (int *)*piVar5;

            iVar6 = *piVar7;

            piVar8 = piVar5;

          }

          piVar7 = (int *)*piVar8;

          *piVar8 = 0;

        }

        else {

          piVar7 = DAT_00632dac;

          DAT_00632dac = (int *)*DAT_00632dac;

        }

        piVar8 = piVar7;

        for (iVar6 = 0xd; iVar6 != 0; iVar6 = iVar6 + -1) {

          *piVar8 = 0;

          piVar8 = piVar8 + 1;

        }

        *piVar7 = (int)DAT_00632da8;

        DAT_00632da8 = piVar7;

        piVar7[5] = 0x3f800000;

        piVar7[1] = piVar4[1];

        piVar7[2] = (int)*pfVar1;

        piVar7[3] = piVar4[3];

        piVar7[4] = piVar4[4];

        piVar7[5] = (int)((float)piVar4[5] * 0.75);

        piVar7[8] = (int)((float)piVar4[8] * 0.9);

        piVar7[9] = (int)((float)piVar4[9] * 0.9);

        piVar7[7] = (int)((float)piVar4[7] * 0.8);

        piVar7[0xb] = piVar4[0xb];

        fVar9 = (float10)rndfloat(0x3f800000);

        piVar7[6] = (int)(float)fVar9;

      }

    }

    piVar4[0xb] = (int)((float)piVar4[0xb] - fVar2);

    fVar9 = (float10)FUN_004143f0(pfVar1);

    if (((float10)(float)piVar4[4] <= fVar9) ||

       ((float)piVar4[0xb] < 0.0 != ((float)piVar4[0xb] == 0.0))) {

      piVar4[10] = piVar4[10] | 1;

    }

    piVar4 = (int *)*piVar4;

  } while( true );

}

/* ===== particle_lifespan_render @ 0x0040B8F0 ===== */
void particle_lifespan_render(void)



{

  undefined4 *puVar1;

  undefined4 *puVar2;

  float fVar3;

  int iVar4;

  float *pfVar5;

  float afStack_e0 [11];

  undefined4 uStack_b4;

  undefined4 uStack_b0;

  float afStack_a8 [2];

  float fStack_a0;

  undefined4 uStack_7c;

  undefined4 uStack_78;

  float afStack_70 [2];

  float fStack_68;

  undefined4 uStack_44;

  undefined4 uStack_40;

  float afStack_38 [2];

  float fStack_30;

  undefined4 uStack_c;

  undefined4 uStack_8;

  

  for (puVar2 = DAT_00632da8; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {

    fVar3 = 1.0 - (float)puVar2[0xb] / *(float *)(DAT_00632ed8 + 0x2a8);

    if ((fVar3 < 0.0) || (fVar3 < 1.0)) {

      iVar4 = __ftol();

      (**(code **)(DAT_0065642c + 8))(DAT_0065642c,0x4033c,puVar2[1],iVar4 << 0x18);

      fVar3 = ((float)puVar2[6] + 1.0) * 0.8;

      if (1.2 < fVar3) {

        fVar3 = 2.4 - fVar3;

      }

      pfVar5 = afStack_e0;

      for (iVar4 = 0x38; iVar4 != 0; iVar4 = iVar4 + -1) {

        *pfVar5 = 0.0;

        pfVar5 = pfVar5 + 1;

      }

      afStack_e0[0] = fVar3 * (float)puVar2[5];

      afStack_e0[2] = (2.0 - fVar3) * (float)puVar2[5];

      puVar1 = puVar2 + 2;

      uStack_b4 = 0x3f800000;

      uStack_b0 = 0x3f800000;

      uStack_7c = 0;

      afStack_a8[0] = -afStack_e0[0];

      uStack_78 = 0x3f800000;

      uStack_44 = 0;

      uStack_40 = 0;

      uStack_c = 0x3f800000;

      uStack_8 = 0;

      fStack_68 = -afStack_e0[2];

      fStack_a0 = afStack_e0[2];

      afStack_70[0] = afStack_a8[0];

      afStack_38[0] = afStack_e0[0];

      fStack_30 = fStack_68;

      hud_screen_project(puVar1,afStack_e0);

      hud_screen_project(puVar1,afStack_a8);

      hud_screen_project(puVar1,afStack_70);

      hud_screen_project(puVar1,afStack_38);

      status_bar_update3(afStack_e0,afStack_a8,afStack_70);

      status_bar_update3(afStack_e0,afStack_70,afStack_38);

    }

  }

  return;

}

/* ===== FUN_0040bb40 @ 0x0040BB40 ===== */
/* PS2 candidate: wound_from_object_world (conf 0.318) */



void FUN_0040bb40(undefined4 param_1,int param_2)



{

  int *piVar1;

  int *piVar2;

  int *piVar3;

  int iVar4;

  undefined4 *puVar5;

  undefined4 *puVar6;

  undefined4 local_c;

  undefined4 local_8;

  undefined4 local_4;

  

  if (param_2 != 0) {

    xformobj_world_local(param_1,param_2,&local_c);

    if (DAT_00632db4 == (undefined4 *)0x0) {

      iVar4 = *(int *)*DAT_00632db0;

      piVar1 = (int *)*DAT_00632db0;

      piVar3 = DAT_00632db0;

      while (piVar2 = piVar1, iVar4 != 0) {

        piVar1 = (int *)*piVar2;

        iVar4 = *piVar1;

        piVar3 = piVar2;

      }

      puVar5 = (undefined4 *)*piVar3;

      *piVar3 = 0;

    }

    else {

      puVar5 = DAT_00632db4;

      DAT_00632db4 = (undefined4 *)*DAT_00632db4;

    }

    puVar6 = puVar5;

    for (iVar4 = 0x12; iVar4 != 0; iVar4 = iVar4 + -1) {

      *puVar6 = 0;

      puVar6 = puVar6 + 1;

    }

    *puVar5 = DAT_00632db0;

    DAT_00632db0 = puVar5;

    puVar5[0xd] = puVar5 + 1;

    puVar5[5] = local_c;

    puVar5[6] = local_8;

    puVar5[0xe] = param_1;

    puVar5[7] = local_4;

    puVar5[0x11] = *(undefined4 *)(DAT_00632ed8 + 0x560);

    return;

  }

  blood_from_object(param_1);

  return;

}

/* ===== wound_process_single__FP5WOUND @ 0x0040BC00 ===== */
/* PS2 candidate: wound_process_single__FP5WOUND (conf 0.431) */



void wound_process_single__FP5WOUND(int param_1)



{

  int iVar1;

  int iVar2;

  undefined4 uVar3;

  float10 fVar4;

  float10 extraout_ST0;

  undefined1 local_7c [12];

  undefined1 local_70 [112];

  

  fVar4 = (float10)FUN_00518b70(*(undefined4 *)(param_1 + 0x38),0);

  iVar1 = *(int *)(param_1 + 0x38);

  *(float *)(param_1 + 0x44) = (float)((float10)*(float *)(param_1 + 0x44) - fVar4);

  if ((char)((uint)*(undefined4 *)(iVar1 + 0xd8) >> 8) < '\0') {

    *(undefined4 *)(param_1 + 0x44) = 0;

    return;

  }

  if ((*(byte *)(param_1 + 0x3c) & 1) == 0) {

    fVar4 = (float10)FUN_00518b70(iVar1,0);

    fVar4 = (float10)*(float *)(param_1 + 0x40) - fVar4;

    *(float *)(param_1 + 0x40) = (float)fVar4;

    if (fVar4 < (float10)0.0) {

      fVar4 = (float10)rndfloatrange(*(undefined4 *)(DAT_00632ed8 + 0x588),

                                     *(undefined4 *)(DAT_00632ed8 + 0x58c));

      *(float *)(param_1 + 0x40) = (float)fVar4;

      *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | 1;

      return;

    }

  }

  else {

    fVar4 = (float10)FUN_00518b70(iVar1,0);

    fVar4 = (float10)*(float *)(param_1 + 0x40) - fVar4;

    *(float *)(param_1 + 0x40) = (float)fVar4;

    if ((float10)0.0 < fVar4) {

      return;

    }

    fVar4 = (float10)rndfloatrange(*(undefined4 *)(DAT_00632ed8 + 0x580),

                                   *(undefined4 *)(DAT_00632ed8 + 0x584));

    *(float *)(param_1 + 0x40) = (float)fVar4;

    *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) & 0xfffffffe;

  }

  iVar1 = FUN_00403a70(*(undefined4 *)(param_1 + 0x38),0,local_70);

  if (iVar1 != 0) {

    nam_lookup_full(local_70,iVar1,param_1 + 0x14,1,*(undefined4 *)(*(int *)(param_1 + 0x38) + 0xc))

    ;

    (*(code *)PTR_S_GEO_Vec3Transform_00580c20)

              (local_7c,param_1 + 0x14,1,*(int *)(param_1 + 0x38) + 0x294);

    dirfcalcp3d__FP3P3DT0(*(int *)(param_1 + 0x38) + 0xa0,local_7c);

    iVar1 = DAT_00632ed8;

    iVar2 = __ftol();

    uVar3 = __ftol();

    if (iVar2 < 1) {

      iVar2 = 1;

    }

    blood_from_point(local_7c,iVar2,uVar3,(float)(extraout_ST0 - (float10)*(float *)(iVar1 + 0x56c))

                     ,(float)((float10)*(float *)(iVar1 + 0x56c) + extraout_ST0),

                     *(undefined4 *)(iVar1 + 0x570),*(undefined4 *)(iVar1 + 0x574),

                     *(undefined4 *)(iVar1 + 0x578),*(undefined4 *)(iVar1 + 0x57c));

  }

  return;

}

/* ===== FUN_0040bdc0 @ 0x0040BDC0 ===== */
/* PS2 candidate: process_wound (conf 0.342) */



void FUN_0040bdc0(void)



{

  undefined4 *puVar1;

  undefined4 *puVar2;

  undefined4 *puVar3;

  

  for (puVar1 = DAT_00632db0; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {

    wound_process_single__FP5WOUND(puVar1);

  }

  puVar2 = &DAT_00632db0;

  puVar1 = DAT_00632db0;

  while (puVar1 != (undefined4 *)0x0) {

    puVar1 = (undefined4 *)*puVar2;

    puVar3 = puVar1;

    if ((float)puVar1[0x11] < 0.0 != ((float)puVar1[0x11] == 0.0)) {

      *puVar2 = *puVar1;

      *puVar1 = DAT_00632db4;

      puVar3 = puVar2;

      DAT_00632db4 = puVar1;

    }

    puVar2 = puVar3;

    puVar1 = (undefined4 *)*puVar3;

  }

  return;

}

/* ===== FUN_0040be30 @ 0x0040BE30 ===== */
void FUN_0040be30(void)



{

  undefined4 *puVar1;

  undefined4 *puVar2;

  undefined4 *puVar3;

  

  for (puVar1 = DAT_00632db0; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {

    FUN_00497dc0(puVar1 + 0xe);

    if (puVar1[0xe] == 0) {

      puVar1[0x11] = 0;

    }

  }

  puVar2 = &DAT_00632db0;

  puVar1 = DAT_00632db0;

  while (puVar1 != (undefined4 *)0x0) {

    puVar1 = (undefined4 *)*puVar2;

    puVar3 = puVar1;

    if ((float)puVar1[0x11] < 0.0 != ((float)puVar1[0x11] == 0.0)) {

      *puVar2 = *puVar1;

      *puVar1 = DAT_00632db4;

      puVar3 = puVar2;

      DAT_00632db4 = puVar1;

    }

    puVar2 = puVar3;

    puVar1 = (undefined4 *)*puVar3;

  }

  return;

}

/* ===== buoy_set_lights @ 0x0040C2D0 ===== */
int buoy_set_lights(int param_1,int param_2)



{

  undefined4 *puVar1;

  undefined4 *puVar2;

  undefined4 *puVar3;

  undefined4 uVar4;

  int iVar5;

  int local_38;

  

  iVar5 = param_2;

  for (puVar1 = DAT_00632d68; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {

    iVar5 = puVar1[3];

    if ((*(int *)(iVar5 + 0x1e0) == 0x69) && (*(int *)(iVar5 + 0xe8) == *(int *)(param_1 + 0xe8))) {

      if (*(int *)(iVar5 + 0x174) == 0) {

        local_38 = iVar5;

      }

      if ((*(int *)(iVar5 + 0x174) == *(int *)(param_1 + 0x174) + 2) && (local_38 != 0)) break;

    }

  }

  if (param_2 != 0) {

    puVar2 = *(undefined4 **)(param_1 + 0x100);

    puVar3 = *(undefined4 **)(*(int *)(param_1 + 0x274) + 0x100);

    fx_delete(*puVar2);

    fx_delete(*puVar3);

    uVar4 = fx_get_free_effect__Fv();

    *puVar2 = uVar4;

    uVar4 = fx_get_free_effect__Fv();

    *puVar3 = uVar4;

    if (puVar2[7] != 0) {

      *(int *)(DAT_006330e4 + 0x4a74) = *(int *)(DAT_006330e4 + 0x4a74) + 1;

    }

    puVar2[7] = 0;

    puVar2[6] = 0;

    *(undefined4 *)(param_1 + 0xe4) = 3;

  }

  if (puVar1 == (undefined4 *)0x0) {

    iVar5 = local_38;

  }

  if (param_2 != 0) {

    puVar1 = *(undefined4 **)(iVar5 + 0x100);

    puVar2 = *(undefined4 **)(*(int *)(iVar5 + 0x274) + 0x100);

    fx_delete(*puVar1);

    fx_delete(*puVar2);

    uVar4 = fx_get_free_effect__Fv();

    *puVar1 = uVar4;

    uVar4 = fx_get_free_effect__Fv();

    *puVar2 = uVar4;

    *(undefined4 *)(iVar5 + 0xe4) = 1;

  }

  return iVar5;

}

/* ===== FUN_0040c480 @ 0x0040C480 ===== */
undefined4 FUN_0040c480(int param_1,undefined4 param_2)



{

  int iVar1;

  float10 fVar2;

  float10 fVar3;

  float10 fVar4;

  float local_c;

  float local_8;

  float local_4;

  

  iVar1 = *(int *)(param_1 + 0x274);

  local_c = *(float *)(param_1 + 0xa0) - *(float *)(iVar1 + 0xa0);

  local_8 = *(float *)(param_1 + 0xa4) - *(float *)(iVar1 + 0xa4);

  local_4 = *(float *)(param_1 + 0xa8) - *(float *)(iVar1 + 0xa8);

  normalize__FPfN20(&local_c,&local_8,&local_4);

  fVar2 = (float10)FUN_00516290(&local_c,param_1 + 0xa0);

  fVar3 = (float10)FUN_00516290(&local_c,*(int *)(param_1 + 0x274) + 0xa0);

  fVar4 = (float10)FUN_00516290(&local_c,param_2);

  fVar3 = (float10)(float)fVar3 - fVar4;

  if (((float)((float10)(float)fVar2 - fVar4) < 0.0) && ((float10)0.0 <= fVar3)) {

    return 1;

  }

  if ((0.0 <= (float)((float10)(float)fVar2 - fVar4)) &&

     (fVar3 < (float10)0.0 != (fVar3 == (float10)0.0))) {

    return 1;

  }

  return 0;

}

/* ===== obj_face_target @ 0x0040C580 ===== */
undefined4 obj_face_target(int param_1,int param_2,float *param_3)



{

  float *pfVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  int iVar5;

  float10 fVar6;

  float local_24;

  float local_20;

  float local_1c;

  float local_18;

  float local_14;

  float local_10;

  float local_c;

  float local_8;

  float local_4;

  

  iVar5 = *(int *)(param_1 + 0x274);

  local_24 = -(*(float *)(iVar5 + 0xa4) - *(float *)(param_1 + 0xa4));

  local_20 = *(float *)(iVar5 + 0xa0) - *(float *)(param_1 + 0xa0);

  local_1c = *(float *)(iVar5 + 0xa8) - *(float *)(param_1 + 0xa8);

  normalize__FPfN20(&local_24,&local_20,&local_1c);

  fVar6 = (float10)FUN_00516290(&local_24,(float *)(param_1 + 0xa0));

  fVar2 = (float)fVar6;

  pfVar1 = (float *)(param_2 + 0xac);

  fVar6 = (float10)FUN_00516290(&local_24,pfVar1);

  fVar3 = (float)fVar6;

  fVar6 = (float10)FUN_00516290(&local_24,(float *)(param_2 + 0xa0));

  fVar4 = (float)fVar6;

  local_c = *pfVar1;

  local_18 = *pfVar1 - *(float *)(param_2 + 0xa0);

  local_8 = *(float *)(param_2 + 0xb0);

  local_4 = *(float *)(param_2 + 0xb4);

  local_14 = *(float *)(param_2 + 0xb0) - *(float *)(param_2 + 0xa4);

  local_10 = *(float *)(param_2 + 0xb4) - *(float *)(param_2 + 0xa8);

  if (((fVar2 < fVar3) || (fVar4 <= fVar2)) &&

     ((fVar2 < fVar3 == (fVar2 == fVar3) || (fVar2 < fVar4)))) {

    return 0;

  }

  fVar2 = (fVar2 - fVar3) - (fVar2 - fVar4) / (fVar2 - fVar3);

  normalize__FPfN20(&local_18,&local_14,&local_10);

  *param_3 = fVar2 * local_18 + local_c;

  param_3[1] = fVar2 * local_14 + local_8;

  param_3[2] = fVar2 * local_10 + local_4;

  return 1;

}

/* ===== FUN_0040ce50 @ 0x0040CE50 ===== */
void FUN_0040ce50(void)



{

  int iVar1;

  undefined4 *puVar2;

  undefined4 *puVar3;

  

  puVar2 = &DAT_005550b0;

  puVar3 = &DAT_00584258;

  for (iVar1 = 0x22; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar3 = *puVar2;

    puVar2 = puVar2 + 1;

    puVar3 = puVar3 + 1;

  }

  return;

}

/* ===== FUN_0040ce70 @ 0x0040CE70 ===== */
void FUN_0040ce70(void)



{

  int iVar1;

  undefined4 *puVar2;

  undefined4 *puVar3;

  

  puVar2 = &DAT_00584258;

  puVar3 = &DAT_005550b0;

  for (iVar1 = 0x22; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar3 = *puVar2;

    puVar2 = puVar2 + 1;

    puVar3 = puVar3 + 1;

  }

  return;

}

/* ===== camera_cursor_fire @ 0x0040CE90 ===== */
/* PS2 candidate: camera_cursor_fire (conf 0.551) */



undefined4 camera_cursor_fire(void)



{

  undefined4 uVar1;

  

  if (((DAT_005550b0 != 0) || (DAT_005550bc != 0)) || (uVar1 = 1, 1 < DAT_005550b8)) {

    uVar1 = 0;

  }

  return uVar1;

}

/* ===== mecc_zoom_out__FRC10CntrlInputif_2 @ 0x0040CEC0 ===== */
/* PS2 candidate: mecc_zoom_out__FRC10CntrlInputif (conf 0.545) */



undefined4 mecc_zoom_out__FRC10CntrlInputif_2(void)



{

  if (((DAT_005550b0 == 0) && (DAT_005550bc == 0)) && (DAT_005550b8 == 0)) {

    return 1;

  }

  return 0;

}

/* ===== mecc_zoom_out__FRC10CntrlInputif @ 0x0040CEF0 ===== */
/* PS2 candidate: mecc_zoom_out__FRC10CntrlInputif_2 (conf 0.545) */



undefined4 mecc_zoom_out__FRC10CntrlInputif(void)



{

  if (((DAT_005550b0 == 0) && (DAT_005550bc == 0)) && (DAT_005550b8 == 2)) {

    return 1;

  }

  return 0;

}

/* ===== camera_is_sniper_2 @ 0x0040CF20 ===== */
/* PS2 candidate: camera_is_sniper (conf 0.617) */



undefined4 camera_is_sniper_2(void)



{

  int iVar1;

  

  if (DAT_00632adf == '\0') {

    return 0;

  }

  iVar1 = ObjIsMecc(DAT_00632a88);

  if (((iVar1 == 0) && (iVar1 = ObjIsReaper(DAT_00632a88), iVar1 == 0)) &&

     (iVar1 = ObjIsKabuto(DAT_00632a88), iVar1 == 0)) {

    return 0;

  }

  return 1;

}

/* ===== camera_is_sniper @ 0x0040CF70 ===== */
/* PS2 candidate: camera_is_firstp (conf 0.492) */



undefined4 camera_is_sniper(void)



{

  int iVar1;

  

  if (DAT_005550b0 != 0) {

    return 0;

  }

  if ((DAT_005550bc != 0) || (DAT_005550b8 != 1)) {

    if (DAT_00632adf == '\0') {

      return 0;

    }

    iVar1 = ObjIsMecc(DAT_00632a88);

    if (((iVar1 == 0) && (iVar1 = ObjIsReaper(DAT_00632a88), iVar1 == 0)) &&

       (iVar1 = ObjIsKabuto(DAT_00632a88), iVar1 == 0)) {

      return 0;

    }

  }

  return 1;

}

/* ===== cam_target_get @ 0x0040CFE0 ===== */
int cam_target_get(void)



{

  int iVar1;

  int iVar2;

  int iVar3;

  

  iVar3 = 0;

  if ((DAT_005550d0 != 0) && (-1 < (char)((uint)*(undefined4 *)(DAT_005550d0 + 0xd8) >> 8))) {

    iVar3 = *(int *)(DAT_005550d0 + 4);

    if (iVar3 == 2) {

      iVar1 = mecc_in_gyro(DAT_005550d0);

      if (iVar1 != 0) {

        iVar3 = 0x3df;

      }

    }

    else if (((iVar3 == 3) && (iVar1 = *(int *)(DAT_005550d0 + 0x210), iVar1 != 0)) &&

            (*(int *)(iVar1 + 0x1e0) == 0x5a)) {

      iVar3 = *(int *)(iVar1 + 4);

    }

  }

  iVar1 = DAT_005550b8;

  if ((DAT_00632adf != '\0') &&

     (((iVar2 = ObjIsMecc(DAT_00632a88), iVar2 != 0 ||

       (iVar2 = ObjIsReaper(DAT_00632a88), iVar2 != 0)) ||

      (iVar2 = ObjIsKabuto(DAT_00632a88), iVar2 != 0)))) {

    iVar1 = 1;

  }

  if (iVar3 < 0x3e0) {

    if (iVar3 == 0x3df) {

      return iVar1 * 0x18 + 0x555180;

    }

    switch(iVar3) {

    case 1:

      return iVar1 * 0x18 + 0x5551c8;

    case 2:

      return iVar1 * 0x18 + 0x555138;

    case 3:

      return iVar1 * 0x18 + 0x555210;

    case 4:

      return iVar1 * 0x18 + 0x555330;

    case 6:

      return iVar1 * 0x18 + 0x5552e8;

    case 7:

      return iVar1 * 0x18 + 0x5552a0;

    }

  }

  else if (iVar3 == 0x434) {

    return iVar1 * 0x18 + 0x555258;

  }

  return iVar1 * 0x18 + 0x555378;

}

/* ===== cam_mode_switch @ 0x0040D130 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void cam_mode_switch(int param_1)



{

  int iVar1;

  

  if (param_1 == -1) {

    param_1 = (DAT_005550b8 != 0) + 1;

  }

  if (param_1 == 1) {

    DAT_005550bc = 0;

    DAT_005550b8 = 0;

    if ((DAT_005550d0 != 0) && (-1 < (char)((uint)*(undefined4 *)(DAT_005550d0 + 0xd8) >> 8))) {

      iVar1 = cam_target_get();

      *(undefined4 *)(DAT_005550d0 + 0xd4) = *(undefined4 *)(iVar1 + 0x14);

    }

  }

  else if (param_1 == 2) {

    DAT_005550bc = 0;

    DAT_005550b8 = 1;

    if ((DAT_005550d0 != 0) && (-1 < (char)((uint)*(undefined4 *)(DAT_005550d0 + 0xd8) >> 8))) {

      iVar1 = cam_target_get();

      *(undefined4 *)(DAT_005550d0 + 0xd4) = *(undefined4 *)(iVar1 + 0x14);

    }

  }

  else if (param_1 == 3) {

    DAT_005550bc = 2;

    DAT_005550b8 = 0;

  }

  else if (param_1 == 4) {

    DAT_005550bc = 1;

    DAT_005550b8 = 0;

  }

  else if (param_1 == 5) {

    DAT_005550bc = 0;

    DAT_005550b8 = 2;

    if ((DAT_005550d0 != 0) && (-1 < (char)((uint)*(undefined4 *)(DAT_005550d0 + 0xd8) >> 8))) {

      iVar1 = cam_target_get();

      *(undefined4 *)(DAT_005550d0 + 0xd4) = *(undefined4 *)(iVar1 + 0x14);

    }

  }

  iVar1 = cam_target_get();

  _DAT_005550c0 = 0;

  render_projection_set(*(undefined4 *)(iVar1 + 8),0,1);

  return;

}

/* ===== BinFileCreateWrite @ 0x0040D260 ===== */
void BinFileCreateWrite(undefined4 param_1)



{

  render_projection_set(param_1,0,1);

  return;

}

/* ===== sound_player_voice_smartie @ 0x0040D280 ===== */
void sound_player_voice_smartie(void)



{

  int iVar1;

  undefined4 uVar2;

  

  DAT_005550c4 = DAT_005550c4 + -1;

  if (DAT_005550c4 < 0) {

    iVar1 = ObjIsReaper(DAT_00632a88);

    if (iVar1 == 0) {

      iVar1 = ObjIsMecc(DAT_00632a88);

      if (iVar1 == 0) {

        iVar1 = ObjIsKabuto(DAT_00632a88);

        if (iVar1 == 0) {

          DAT_005550c4 = 3;

          return;

        }

        uVar2 = 0x6db;

      }

      else {

        uVar2 = 0x5e9;

      }

    }

    else {

      uVar2 = 0x397;

    }

    sound_play_player(uVar2,DAT_00632a88);

    DAT_005550c4 = 3;

    return;

  }

  iVar1 = ObjIsReaper(DAT_00632a88);

  if (iVar1 != 0) {

    sound_play_player(0x397,DAT_00632a88);

    return;

  }

  iVar1 = ObjIsMecc(DAT_00632a88);

  if (iVar1 == 0) {

    iVar1 = ObjIsKabuto(DAT_00632a88);

    if (iVar1 != 0) {

      sound_play_player(0x6db,DAT_00632a88);

    }

    return;

  }

  sound_play_player(0x5e9,DAT_00632a88);

  return;

}

/* ===== sound_player_voice_mecc @ 0x0040D370 ===== */
void sound_player_voice_mecc(void)



{

  int iVar1;

  undefined4 uVar2;

  

  iVar1 = DAT_005550c4 * 4;

  DAT_005550c4 = DAT_005550c4 + 1;

  if (*(float *)(&DAT_005553c4 + iVar1) == 0.0) {

    iVar1 = ObjIsReaper(DAT_00632a88);

    if (iVar1 == 0) {

      iVar1 = ObjIsMecc(DAT_00632a88);

      if (iVar1 == 0) {

        iVar1 = ObjIsKabuto(DAT_00632a88);

        if (iVar1 == 0) {

          DAT_005550c4 = 0;

          return;

        }

        uVar2 = 0x6db;

      }

      else {

        uVar2 = 0x5e9;

      }

    }

    else {

      uVar2 = 0x397;

    }

    sound_play_player(uVar2,DAT_00632a88);

    DAT_005550c4 = 0;

    return;

  }

  iVar1 = ObjIsReaper(DAT_00632a88);

  if (iVar1 != 0) {

    sound_play_player(0x397,DAT_00632a88);

    return;

  }

  iVar1 = ObjIsMecc(DAT_00632a88);

  if (iVar1 == 0) {

    iVar1 = ObjIsKabuto(DAT_00632a88);

    if (iVar1 != 0) {

      sound_play_player(0x6db,DAT_00632a88);

    }

    return;

  }

  sound_play_player(0x5e9,DAT_00632a88);

  return;

}

/* ===== FUN_0040d480 @ 0x0040D480 ===== */
/* PS2 candidate: camera_get_sniper_factor (conf 0.7) */



float10 FUN_0040d480(void)



{

  if (DAT_00632adf != '\0') {

    return (float10)*(float *)(&DAT_005553c0 + DAT_005550c4 * 4);

  }

  return (float10)1.0;

}

/* ===== speaker_config_apply @ 0x0040D4A0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void speaker_config_apply(void)



{

  int iVar1;

  float fVar2;

  

  iVar1 = cam_target_get();

  if (DAT_00555134 != 0.0) {

    render_projection_set(DAT_00555134,0,1,DAT_00555134);

    return;

  }

  fVar2 = *(float *)(iVar1 + 8);

  if ((DAT_00632ade == '\0') || (DAT_005550b0 != 0)) {

LAB_0040d56d:

    if ((_DAT_005550c0 <= 0.0) ||

       (_DAT_005550c0 = _DAT_005550c0 - DAT_006328e0, 0.0 <= _DAT_005550c0)) goto LAB_0040d5ab;

    _DAT_005550c0 = 0.0;

  }

  else {

    if ((DAT_005550bc != 0) || (DAT_005550b8 != 1)) {

      if (DAT_00632adf == '\0') goto LAB_0040d56d;

      iVar1 = ObjIsMecc(DAT_00632a88);

      if (iVar1 == 0) {

        iVar1 = ObjIsReaper(DAT_00632a88);

        if (iVar1 == 0) {

          iVar1 = ObjIsKabuto(DAT_00632a88);

          if (iVar1 == 0) goto LAB_0040d56d;

        }

      }

    }

    _DAT_005550c0 = _DAT_005550c0 + DAT_006328e0;

    if (_DAT_005550c0 <= 1.0) {

LAB_0040d5ab:

      if (_DAT_005550c0 == 0.0) goto LAB_0040d5e0;

    }

    else {

      _DAT_005550c0 = 1.0;

    }

    fVar2 = _DAT_005550c0 * 25.0 + (1.0 - _DAT_005550c0) * fVar2;

  }

LAB_0040d5e0:

  if (DAT_005550b0 == 0) {

    if ((DAT_005550bc != 0) || (DAT_005550b8 != 1)) {

      if (DAT_00632adf == '\0') goto LAB_0040d65a;

      iVar1 = ObjIsMecc(DAT_00632a88);

      if (iVar1 == 0) {

        iVar1 = ObjIsReaper(DAT_00632a88);

        if (iVar1 == 0) {

          iVar1 = ObjIsKabuto(DAT_00632a88);

          if (iVar1 == 0) goto LAB_0040d65a;

        }

      }

    }

    if (DAT_00632adf != '\0') {

      fVar2 = fVar2 * *(float *)(&DAT_005553c0 + DAT_005550c4 * 4);

    }

  }

LAB_0040d65a:

  render_projection_set(fVar2,0,1);

  return;

}

/* ===== camera_fov_update @ 0x0040D670 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* PS2 candidate: camera_fov_update (conf 0.303) */



void camera_fov_update(void)



{

  int iVar1;

  

  iVar1 = cam_target_get();

  _DAT_005550c0 = 0;

  render_projection_set(*(undefined4 *)(iVar1 + 8),0,1);

  return;

}

/* ===== AudioGetMasterVolume__Fv @ 0x0040D6A0 ===== */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */



undefined4 AudioGetMasterVolume__Fv(void)



{

  return DAT_005550d0;

}

/* ===== XFGetViewport @ 0x0040D6B0 ===== */
/* PS2 candidate: XFGetViewport (conf 0.86) */



void XFGetViewport(undefined4 *param_1)



{

  *param_1 = DAT_005550d4;

  param_1[1] = DAT_005550d8;

  param_1[2] = DAT_005550dc;

  return;

}

/* ===== FUN_0040d6d0 @ 0x0040D6D0 ===== */
float10 FUN_0040d6d0(void)



{

  return (float10)DAT_005550e0;

}

/* ===== FUN_0040d6e0 @ 0x0040D6E0 ===== */
float10 FUN_0040d6e0(void)



{

  return (float10)DAT_005550e4;

}

/* ===== XFGetViewportExt @ 0x0040D6F0 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* PS2 candidate: project_vec_to_ground (conf 0.563) */



void XFGetViewportExt(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,

                     undefined4 *param_4)



{

  *param_1 = DAT_005550e0;

  *param_2 = DAT_005550e4;

  *param_3 = _DAT_005550e8;

  *param_4 = DAT_005550d4;

  param_4[1] = DAT_005550d8;

  param_4[2] = DAT_005550dc;

  return;

}

/* ===== camera_override_info @ 0x0040D740 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void camera_override_info

               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)



{

  DAT_005550e0 = param_1;

  DAT_005550e4 = param_2;

  _DAT_005550e8 = param_3;

  DAT_005550d4 = *param_4;

  DAT_005550d8 = param_4[1];

  DAT_005550dc = param_4[2];

  DAT_005550b0 = 1;

  return;

}

/* ===== FUN_0040d790 @ 0x0040D790 ===== */
/* PS2 candidate: camera_override_done (conf 0.371) */



void FUN_0040d790(void)



{

  DAT_005550b0 = 0;

  DAT_005550b4 = 0xffffffff;

  DAT_005550ec = 0;

  DAT_00555134 = 0;

  return;

}

/* ===== camera_override_refpt @ 0x0040D7B0 ===== */
void camera_override_refpt(undefined4 param_1,undefined4 param_2)



{

  DAT_005550d0 = param_1;

  DAT_005550b4 = param_2;

  DAT_005550ec = 0;

  DAT_005550b0 = 1;

  return;

}

/* ===== FUN_0040d7e0 @ 0x0040D7E0 ===== */
void FUN_0040d7e0(undefined4 *param_1)



{

  int iVar1;

  undefined4 *puVar2;

  

  DAT_005550b4 = 0xffffffff;

  DAT_005550ec = 1;

  puVar2 = &DAT_005550f0;

  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar2 = *param_1;

    param_1 = param_1 + 1;

    puVar2 = puVar2 + 1;

  }

  DAT_005550b0 = 1;

  return;

}

/* ===== AudioSetSpeakerConfig__F14SPEAKER_SYSTEM @ 0x0040D810 ===== */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */



void AudioSetSpeakerConfig__F14SPEAKER_SYSTEM(undefined4 p0)



{

  DAT_00555134 = p0;

  return;

}

/* ===== ref_anode_user @ 0x0040D820 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void ref_anode_user(void)



{

  int iVar1;

  float10 fVar2;

  float local_28;

  float local_24;

  float local_20;

  float local_1c;

  float local_18;

  float local_14;

  float local_10;

  float local_c;

  float local_8;

  float local_4;

  

  if (DAT_00632a88 != 0) {

    if ((((-1 < DAT_005550b4) && (DAT_005550d0 != 0)) &&

        ((*(uint *)(DAT_005550d0 + 0xd8) & 0x8000) == 0)) ||

       ((iVar1 = DAT_00632a88, DAT_00632d60 != 0 && (DAT_005550d0 = DAT_00632d64, DAT_00632d64 != 0)

        ))) {

      iVar1 = DAT_005550d0;

    }

    DAT_005550d0 = iVar1;

    if ((-1 < DAT_005550b4) && ((*(uint *)(iVar1 + 0xd8) & 0x8000) == 0)) {

      ref_get_anode2(&DAT_005550f0,&DAT_00555134,iVar1,*(undefined4 *)(iVar1 + 0x10),DAT_005550b4,

                     *(undefined4 *)(iVar1 + 0x14));

      DAT_005550ec = 1;

    }

    speaker_config_apply();

    if (DAT_00632e48 != 0) {

      cam_target_get();

      _DAT_005550e8 = 0;

      DAT_005550e4 = -90.0;

      DAT_005550e0 = *(float *)(iVar1 + 200);

      DAT_005550d4 = *(undefined4 *)(iVar1 + 0xa0);

      DAT_005550d8 = *(undefined4 *)(iVar1 + 0xa4);

      DAT_005550dc = *(float *)(iVar1 + 0xa8) + 1500.0;

      sine_cos_lookup(DAT_005550e0,&local_20,&local_1c);

      sine_cos_lookup(DAT_005550e4,&local_28,&local_24);

      local_c = local_24 * local_20;

      local_4 = local_28;

      local_8 = -(local_24 * local_1c);

      local_10 = local_24;

      local_18 = -(local_28 * local_20);

      local_14 = local_28 * local_1c;

      view_matrix_build(&DAT_005550d4,&local_c,&local_18);

      return;

    }

    if (DAT_00632bc4 != 0) {

      FUN_0040db70(DAT_00632a88,DAT_00632a88);

      return;

    }

    if ((DAT_005550bc == 1) || (DAT_005550b0 != 0)) {

      if (DAT_005550ec != 0) {

        FUN_005162b0(&DAT_005550f4);

        return;

      }

      sine_cos_lookup(DAT_005550e0,&local_1c,&local_20);

      sine_cos_lookup(DAT_005550e4,&local_24,&local_28);

    }

    else {

      if (DAT_005550bc != 2) {

        FUN_0040db70(iVar1,iVar1);

        return;

      }

      fVar2 = (float10)FUN_0050a520(iVar1 + 0xa0,&DAT_005550d4);

      local_20 = (float)fVar2;

      fVar2 = (float10)dirfcalcp3d__FP3P3DT0(&DAT_005550d4,iVar1 + 0xa0);

      local_1c = (float)fVar2;

      fVar2 = (float10)FUN_0050a390((*(float *)(iVar1 + 0xa8) - DAT_005550dc) +

                                    *(float *)(iVar1 + 0x1e8) * *(float *)(iVar1 + 0xc4) +

                                    _DAT_005550c8,local_20);

      if ((float10)180.0 < fVar2) {

        fVar2 = fVar2 - (float10)360.0;

      }

      DAT_005550e4 = (float)fVar2;

      DAT_005550e0 = local_1c;

      _DAT_005550e8 = 0;

      if (DAT_005550ec != 0) {

        FUN_005162b0(&DAT_005550f4);

        return;

      }

      sine_cos_lookup(local_1c,&local_1c,&local_20);

      sine_cos_lookup(DAT_005550e4,&local_24,&local_28);

    }

    local_18 = local_28 * local_1c;

    local_14 = -(local_28 * local_20);

    local_c = -(local_24 * local_1c);

    local_8 = local_24 * local_20;

    view_matrix_build(&DAT_005550d4,&local_18,&local_c);

  }

  return;

}

/* ===== FUN_0040db70 @ 0x0040DB70 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* PS2 candidate: SetupCameraDataNormal__FP6OBJECTT0 (conf 0.375) */



void FUN_0040db70(undefined4 param_1,float param_2)



{

  uint *puVar1;

  float fVar2;

  int *piVar3;

  int iVar4;

  undefined4 uVar5;

  float *pfVar6;

  int iVar7;

  int iVar8;

  float10 fVar9;

  float local_4c;

  float local_48;

  float local_44;

  float local_40;

  float local_3c;

  float local_38;

  float local_34;

  undefined4 local_30;

  float local_2c;

  int local_28;

  float local_24;

  float local_20;

  float local_1c;

  float local_18;

  float local_14;

  float local_10;

  float local_c;

  float local_8;

  float local_4;

  

  iVar4 = (int)param_2;

  pfVar6 = (float *)cam_target_get();

  if (DAT_00632bc4 == 0) {

    iVar7 = ObjIsReaper(param_2);

    if ((iVar7 == 0) || (iVar7 = ObjIsJetski(*(undefined4 *)((int)param_2 + 0x210)), iVar7 == 0)) {

      local_30 = *(undefined4 *)((int)param_2 + 200);

      local_40 = *(float *)((int)param_2 + 0xd4);

    }

    else {

      local_30 = *(undefined4 *)(*(int *)((int)param_2 + 0x210) + 200);

      local_40 = *(float *)(*(int *)((int)param_2 + 0x210) + 0xd4);

    }

  }

  else {

    local_30 = 0;

    local_40 = -90.0;

  }

  local_4c = *pfVar6;

  fVar2 = pfVar6[1];

  local_48 = pfVar6[3];

  local_44 = pfVar6[4];

  if ((((*(int **)((int)param_2 + 0x170) != (int *)0x0) && (**(int **)((int)param_2 + 0x170) == 1))

      && (iVar7 = FUN_00501070(param_2), 0 < iVar7)) && (DAT_005550b8 == 0)) {

    local_28 = FUN_00501070(param_2);

    if (local_28 < 2) {

      local_28 = 2;

    }

    local_4c = local_4c * (float)local_28 * 0.5;

    fVar2 = (float)local_28 * 1.5 + fVar2;

    if (local_28 == 2) {

      fVar2 = fVar2 - 2.0;

    }

  }

  param_2 = fVar2;

  piVar3 = *(int **)(iVar4 + 0x170);

  if (((piVar3 != (int *)0x0) && (*piVar3 == 3)) &&

     ((local_28 = piVar3[1], 0 < local_28 && (DAT_005550b8 == 0)))) {

    local_4c = (float)local_28 * local_4c * 0.5;

    param_2 = (float)piVar3[1] * 1.5 + param_2;

  }

  if ((DAT_00632a88 != 0) && (*(int *)(DAT_00632a88 + 0x1e0) == 1)) {

    fVar9 = (float10)FUN_0045d2e0(DAT_00632a88);

    local_4c = (float)((float10)local_4c * fVar9);

    param_2 = (float)((float10)param_2 * fVar9 - ((float10)1.0 - fVar9) * (float10)5.0);

    local_48 = (float)((float10)local_48 * fVar9);

    local_44 = (float)(fVar9 * (float10)local_44);

  }

  uVar5 = local_30;

  if (DAT_005553d4 != 0) {

    DAT_005842e0 = local_4c;

    _DAT_005842e4 = param_2;

    _DAT_005842e8 = local_48;

    _DAT_005842ec = local_44;

    DAT_005553d4 = 0;

  }

  iVar7 = 0;

  do {

    if (DAT_00632bc4 == 0) {

      local_24 = *(float *)(iVar4 + 0xa0);

      local_20 = *(float *)(iVar4 + 0xa4);

      local_1c = *(float *)(iVar4 + 0xa8);

    }

    else {

      iVar8 = *(int *)(DAT_00632a88 + 0x100);

      local_24 = *(float *)(iVar8 + 0xf10);

      local_20 = *(float *)(iVar8 + 0xf14);

      local_1c = (*(float *)(DAT_00632ed8 + 0x7c0) + *(float *)(iVar8 + 0xf18)) -

                 *(float *)(DAT_00632ed8 + 0x854) * _DAT_00632bc8;

    }

    sine_cos_lookup(uVar5,&local_3c,&local_38);

    sine_cos_lookup(local_40,&local_34,&local_2c);

    local_18 = local_2c * local_3c;

    local_10 = local_34;

    local_4 = local_2c;

    local_14 = -(local_2c * local_38);

    local_c = -(local_34 * local_3c);

    local_8 = local_34 * local_38;

    local_24 = (local_3c * local_48 + local_38 * local_44 + local_24) - local_18 * local_4c;

    local_20 = ((local_3c * local_44 - local_38 * local_48) + local_20) - local_14 * local_4c;

    local_1c = local_1c - (local_34 * local_4c - param_2);

    if ((*(byte *)(iVar4 + 0xd8) & 0x10) != 0) break;

    iVar8 = ObjIsPlayer(iVar4);

    if (((iVar8 != 0) && (*(float *)(iVar4 + 0x1c0) <= *(float *)(iVar4 + 0x278))) &&

       (*(float *)(iVar4 + 0xa8) < 0.0)) {

      if (local_1c < 4.0) {

        local_1c = 4.0;

      }

      break;

    }

    fVar9 = (float10)get_floor_z_point(&local_24);

    if (fVar9 < (float10)0.0) {

      fVar9 = (float10)0.0;

    }

    fVar9 = fVar9 + (float10)4.0;

    if (fVar9 - (float10)local_1c <= (float10)10.0) {

      if ((float10)local_1c < fVar9) {

        local_1c = (float)fVar9;

      }

      break;

    }

    iVar7 = iVar7 + 1;

    local_40 = local_40 - 1.0;

    local_4c = local_4c * 0.95;

  } while (iVar7 < 0x32);

  if ((*(int *)(iVar4 + 4) == 3) && (DAT_005550b8 == 0)) {

    FUN_004b89d0(iVar4,&local_4c,&DAT_005842e0);

  }

  else if (local_4c != DAT_005842e0) {

    chase_value_time(0x3dcccccd,0x41200000,0x42480000,local_4c,&DAT_005842e0);

    local_4c = DAT_005842e0;

  }

  if (param_2 != _DAT_005842e4) {

    chase_value_time(0x3dcccccd,0x41200000,0x42480000,param_2,&DAT_005842e4);

  }

  if (local_48 != _DAT_005842e8) {

    chase_value_time(0x3dcccccd,0x41200000,0x42480000,local_48,&DAT_005842e8);

  }

  if (local_44 != _DAT_005842ec) {

    chase_value_time(0x3dcccccd,0x41200000,0x42480000,local_44,&DAT_005842ec);

  }

  DAT_005550e4 = local_40;

  DAT_005550e0 = local_30;

  _DAT_005550e8 = 0;

  DAT_005550d4 = local_24;

  DAT_005550d8 = local_20;

  DAT_005550dc = local_1c;

  iVar7 = ObjIsReaper(iVar4);

  if ((iVar7 != 0) && (iVar7 = ObjIsJetski(*(undefined4 *)(iVar4 + 0x210)), iVar7 != 0)) {

    puVar1 = (uint *)(*(int *)(iVar4 + 0x210) + 0x1c8);

    *puVar1 = *puVar1 | 0x800;

  }

  local_24 = *(float *)(iVar4 + 0xa0);

  local_20 = *(float *)(iVar4 + 0xa4);

  local_1c = *(float *)(iVar4 + 0x1e8) * *(float *)(iVar4 + 0xc4) + *(float *)(iVar4 + 0xa8);

  collide_camera_check_walls(&DAT_005550d4,&local_24);

  iVar7 = ObjIsReaper(iVar4);

  if ((iVar7 != 0) && (iVar7 = ObjIsJetski(*(undefined4 *)(iVar4 + 0x210)), iVar7 != 0)) {

    puVar1 = (uint *)(*(int *)(iVar4 + 0x210) + 0x1c8);

    *puVar1 = *puVar1 & 0xfffff7ff;

  }

  local_24 = DAT_005550d4;

  local_20 = DAT_005550d8;

  local_1c = DAT_005550dc;

  if (0.0 < _DAT_00632dc4) {

    local_1c = DAT_005550dc + _DAT_00632dc0;

    _DAT_00632dc0 = _DAT_00632dc0 * -0.75;

    _DAT_00632dc4 = _DAT_00632dc4 - DAT_006328e0;

  }

  view_matrix_build(&local_24,&local_18,&local_c);

  return;

}

/* ===== charger_dust_fx @ 0x0040E1C0 ===== */
void charger_dust_fx(int param_1)



{

  float fVar1;

  float fVar2;

  char *pcVar3;

  undefined4 uVar4;

  undefined1 *puVar5;

  undefined1 local_34 [4];

  undefined1 local_30 [48];

  

  fVar1 = *(float *)(param_1 + 0x14) * 30.0;

  fVar2 = *(float *)(param_1 + 0x18) * 30.0;

  switch(*(undefined4 *)(param_1 + 0x10)) {

  case 2:

    if ((fVar2 < 11.0) && (11.0 <= fVar1)) {

      playerobj_eval_refpt(param_1,2,local_30);

      puVar5 = local_34;

      uVar4 = 8;

      pcVar3 = s_fx_charger_dust_005553ec;

      fx_get_free_effect__Fv();

      sound_play_obj(0x48c,param_1,pcVar3,uVar4,puVar5);

    }

    if ((fVar2 < 15.0) && (15.0 <= fVar1)) {

      playerobj_eval_refpt(param_1,3,local_30);

      puVar5 = local_34;

      uVar4 = 8;

      pcVar3 = s_fx_charger_dust_005553ec;

      fx_get_free_effect__Fv();

      sound_play_obj(0x48c,param_1,pcVar3,uVar4,puVar5);

    }

    if ((fVar2 < 19.0) && (19.0 <= fVar1)) {

      playerobj_eval_refpt(param_1,4,local_30);

      puVar5 = local_34;

      uVar4 = 8;

      pcVar3 = s_fx_charger_dust_005553ec;

      fx_get_free_effect__Fv();

      sound_play_obj(0x48c,param_1,pcVar3,uVar4,puVar5);

    }

    if ((fVar2 < 5.0) && (5.0 <= fVar1)) {

      playerobj_eval_refpt(param_1,5,local_30);

LAB_0040e451:

      puVar5 = local_34;

      uVar4 = 8;

      pcVar3 = s_fx_charger_dust_005553ec;

      fx_get_free_effect__Fv();

      sound_play_obj(0x48c,param_1,pcVar3,uVar4,puVar5);

      return;

    }

    break;

  case 3:

  case 6:

    if ((fVar2 < 6.0) && (6.0 <= fVar1)) {

      playerobj_eval_refpt(param_1,2,local_30);

      puVar5 = local_34;

      uVar4 = 8;

      pcVar3 = s_fx_charger_dust_005553ec;

      fx_get_free_effect__Fv();

      sound_play_obj(0x48c,param_1,pcVar3,uVar4,puVar5);

    }

    if ((fVar2 < 8.0) && (8.0 <= fVar1)) {

      playerobj_eval_refpt(param_1,3,local_30);

      puVar5 = local_34;

      uVar4 = 8;

      pcVar3 = s_fx_charger_dust_005553ec;

      fx_get_free_effect__Fv();

      sound_play_obj(0x48c,param_1,pcVar3,uVar4,puVar5);

    }

    if ((fVar2 < 10.0) && (10.0 <= fVar1)) {

      playerobj_eval_refpt(param_1,4,local_30);

      puVar5 = local_34;

      uVar4 = 8;

      pcVar3 = s_fx_charger_dust_005553ec;

      fx_get_free_effect__Fv();

      sound_play_obj(0x48c,param_1,pcVar3,uVar4,puVar5);

    }

    if ((fVar2 < 3.0) && (3.0 <= fVar1)) {

      playerobj_eval_refpt(param_1,5,local_30);

      goto LAB_0040e451;

    }

    break;

  case 0xb:

    if ((fVar2 < 26.0) && (26.0 <= fVar1)) {

      playerobj_eval_refpt(param_1,2,local_30);

      fx_get_free_effect__Fv();

    }

    if ((fVar2 < 17.0) && (17.0 <= fVar1)) {

      playerobj_eval_refpt(param_1,3,local_30);

      fx_get_free_effect__Fv();

    }

    if ((fVar2 < 51.0) && (51.0 <= fVar1)) {

      playerobj_eval_refpt(param_1,4,local_30);

      fx_get_free_effect__Fv();

    }

    if ((fVar2 < 42.0) && (42.0 <= fVar1)) {

      playerobj_eval_refpt(param_1,5,local_30);

      fx_get_free_effect__Fv();

      return;

    }

    break;

  case 0xc:

    if ((fVar2 < 10.0) && (10.0 <= fVar1)) {

      playerobj_eval_refpt(param_1,6,local_30);

      fx_get_free_effect__Fv();

    }

  }

  return;

}

/* ===== charger_change_anim__FP6OBJECTii4SDKYfi @ 0x0040EE20 ===== */
/* PS2 candidate: charger_change_anim__FP6OBJECTii4SDKYfi (conf 0.49) */



void charger_change_anim__FP6OBJECTii4SDKYfi

               (int param_1,int param_2,int param_3,undefined4 param_4,float param_5,int param_6)



{

  int iVar1;

  byte bVar2;

  float10 fVar3;

  

  iVar1 = *(int *)(param_1 + 0x100);

  if ((*(int *)(param_1 + 0x10) != param_2) &&

     (*(int *)(*(int *)(param_1 + 8) + 8 + param_2 * 4) != 0)) {

    if (param_6 == 0) {

      bVar2 = param_3 != 0 | 0x20;

    }

    else {

      fVar3 = (float10)rndfloatrange(0,0x3f800000);

      *(float *)(param_1 + 0x14) = (float)fVar3;

      bVar2 = param_3 != 0 | 0x80;

    }

    ObjectSetAnim(param_1,param_2,bVar2,param_4,param_5 * *(float *)(param_1 + 0xc4),0x3e2aaaab);

    if (*(int *)(iVar1 + 0x4c) != 0) {

      fx_delete(*(int *)(iVar1 + 0x4c));

    }

    if (*(int *)(iVar1 + 0x50) != 0) {

      fx_delete(*(int *)(iVar1 + 0x50));

    }

    if (*(int *)(iVar1 + 0x54) != 0) {

      fx_delete(*(int *)(iVar1 + 0x54));

    }

    *(undefined4 *)(iVar1 + 0x4c) = 0;

    *(undefined4 *)(iVar1 + 0x50) = 0;

    *(undefined4 *)(iVar1 + 0x54) = 0;

  }

  return;

}

/* ===== ai_nearest_55_scan @ 0x0040EEF0 ===== */
void ai_nearest_55_scan(float param_1)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int *piVar4;

  float10 fVar5;

  float local_4;

  

  iVar1 = *(int *)((int)param_1 + 0x100);

  *(undefined4 *)(iVar1 + 0x3c) = 0;

  local_4 = *(float *)(DAT_00632ed8 + 0x5b0) * *(float *)(DAT_00632ed8 + 0x5b0);

  piVar4 = DAT_00632d6c;

  if (DAT_00632d6c == (int *)0x0) {

    return;

  }

  do {

    iVar2 = piVar4[3];

    iVar3 = ObjIsPlayer(iVar2);

    if (((((iVar3 != 0) || (*(int *)(iVar2 + 0x1e0) == 0x55)) &&

         ((*(uint *)(iVar2 + 0xd8) & 0x4000c000) == 0)) &&

        (*(float *)(iVar2 + 0x278) < *(float *)(iVar2 + 0x1c0))) &&

       ((iVar3 = ObjIsMecc(iVar2), iVar3 == 0 || ((*(uint *)(iVar2 + 0xe0) & 0x2000000) == 0)))) {

      fVar5 = (float10)distancesq2d__FP3P3DT0(iVar1 + 0x40,iVar2 + 0xa0);

      param_1 = (float)fVar5;

      iVar3 = ObjIsKabuto(iVar2);

      if (iVar3 != 0) {

        param_1 = param_1 * 0.25;

      }

      iVar3 = ObjIsMecc(iVar2);

      if (((iVar3 != 0) && (*(int *)(iVar2 + 0x174) == 0)) &&

         (param_1 < *(float *)(DAT_00632ed8 + 0x5b4) * *(float *)(DAT_00632ed8 + 0x5b4))) {

        *(int *)(iVar1 + 0x3c) = iVar2;

        return;

      }

      if (param_1 <= local_4) {

        local_4 = param_1;

        *(int *)(iVar1 + 0x3c) = iVar2;

      }

    }

    piVar4 = (int *)*piVar4;

    if (piVar4 == (int *)0x0) {

      return;

    }

  } while( true );

}

/* ===== charger_set_charge_location__FP6OBJECTi @ 0x0040F030 ===== */
/* PS2 candidate: charger_set_charge_location__FP6OBJECTi (conf 0.573) */



void charger_set_charge_location__FP6OBJECTi(int param_1)



{

  int iVar1;

  float fVar2;

  float local_18;

  float local_14;

  float local_10;

  float local_c;

  float local_8;

  float local_4;

  

  iVar1 = *(int *)(param_1 + 0x100);

  local_18 = *(float *)(*(int *)(iVar1 + 0x3c) + 0xa0) - *(float *)(param_1 + 0xa0);

  local_14 = *(float *)(*(int *)(iVar1 + 0x3c) + 0xa4) - *(float *)(param_1 + 0xa4);

  local_10 = *(float *)(*(int *)(iVar1 + 0x3c) + 0xa8) - *(float *)(param_1 + 0xa8);

  normalize__FPfN20(&local_18,&local_14,&local_10);

  fVar2 = *(float *)(DAT_00632ed8 + 0x5b0) * local_18;

  local_c = fVar2 + fVar2 + *(float *)(param_1 + 0xa0);

  fVar2 = *(float *)(DAT_00632ed8 + 0x5b0) * local_14;

  local_8 = fVar2 + fVar2 + *(float *)(param_1 + 0xa4);

  fVar2 = *(float *)(DAT_00632ed8 + 0x5b0) * local_10;

  local_4 = fVar2 + fVar2 + *(float *)(param_1 + 0xa8);

  FUN_00401050(param_1,&local_c);

  return;

}

/* ===== ANM_BinderDestroy @ 0x0040F380 ===== */
void ANM_BinderDestroy(undefined4 param_1,undefined4 param_2,undefined4 param_3)



{

  FUN_00497cd0(param_3);

  return;

}

