/* Giants 1.449 — module main/ai_move
 * 15 functions (13 named) — decompiled, names from PS2 symbols
 * Original source: C:\Giants\source\main/ai_move.c(pp) (assert-string evidence)
 */

/* ===== FUN_00401050 @ 0x00401050 ===== */
/* PS2 candidate: ai_move_force_goal (conf 0.332) */



void FUN_00401050(int param_1,undefined4 *param_2)



{

  undefined4 *puVar1;

  int iVar2;

  undefined4 *puVar3;

  

  puVar1 = *(undefined4 **)(param_1 + 0x168);

  while (puVar3 = puVar1, puVar3 != (undefined4 *)0x0) {

    puVar1 = (undefined4 *)*puVar3;

    *puVar3 = DAT_00584194;

    DAT_00584194 = puVar3;

  }

  *(undefined4 *)(param_1 + 0x168) = 0;

  *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) & 0xfcffffff;

  puVar1 = DAT_00584194;

  if (DAT_00584194 == (undefined4 *)0x0) {

    puVar1 = (undefined4 *)

             MemAllocMsg(1,0x1f44,s_goals_00554030,s_C__Giants_source_main_ai_move_c_00554038,0x41b)

    ;

    *puVar1 = DAT_00584198;

    DAT_00584194 = puVar1 + 1;

    iVar2 = 0;

    DAT_00584198 = puVar1;

    do {

      *(int *)(iVar2 + (int)DAT_00584194) = iVar2 + 0x28 + (int)DAT_00584194;

      iVar2 = iVar2 + 0x28;

    } while (iVar2 < 0x1ef0);

    DAT_00584194[0x7bc] = 0;

    puVar1 = DAT_00584194;

  }

  DAT_00584194 = (undefined4 *)*puVar1;

  puVar3 = puVar1;

  for (iVar2 = 10; iVar2 != 0; iVar2 = iVar2 + -1) {

    *puVar3 = 0;

    puVar3 = puVar3 + 1;

  }

  *puVar1 = *(undefined4 *)(param_1 + 0x168);

  *(undefined4 **)(param_1 + 0x168) = puVar1;

  puVar1[1] = *param_2;

  puVar1[2] = param_2[1];

  puVar1[3] = param_2[2];

  puVar1[5] = 0x80;

  *(uint *)(*(int *)(param_1 + 0x168) + 0x14) =

       *(uint *)(*(int *)(param_1 + 0x168) + 0x14) & 0xffffff7f;

  return;

}

/* ===== ai_move_goals_free @ 0x00401160 ===== */
void ai_move_goals_free(int param_1,undefined4 *param_2,undefined4 param_3)



{

  undefined4 *puVar1;

  int iVar2;

  undefined4 *puVar3;

  

  puVar1 = *(undefined4 **)(param_1 + 0x168);

  while (puVar3 = puVar1, puVar3 != (undefined4 *)0x0) {

    puVar1 = (undefined4 *)*puVar3;

    *puVar3 = DAT_00584194;

    DAT_00584194 = puVar3;

  }

  *(undefined4 *)(param_1 + 0x168) = 0;

  *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) & 0xfcffffff;

  puVar1 = DAT_00584194;

  if (DAT_00584194 == (undefined4 *)0x0) {

    puVar1 = (undefined4 *)

             MemAllocMsg(1,0x1f44,s_goals_00554030,s_C__Giants_source_main_ai_move_c_00554038,0x41b)

    ;

    *puVar1 = DAT_00584198;

    DAT_00584194 = puVar1 + 1;

    iVar2 = 0;

    DAT_00584198 = puVar1;

    do {

      *(int *)(iVar2 + (int)DAT_00584194) = iVar2 + 0x28 + (int)DAT_00584194;

      iVar2 = iVar2 + 0x28;

    } while (iVar2 < 0x1ef0);

    DAT_00584194[0x7bc] = 0;

    puVar1 = DAT_00584194;

  }

  DAT_00584194 = (undefined4 *)*puVar1;

  puVar3 = puVar1;

  for (iVar2 = 10; iVar2 != 0; iVar2 = iVar2 + -1) {

    *puVar3 = 0;

    puVar3 = puVar3 + 1;

  }

  *puVar1 = *(undefined4 *)(param_1 + 0x168);

  *(undefined4 **)(param_1 + 0x168) = puVar1;

  puVar1[4] = param_3;

  puVar1[5] = 0x20;

  puVar1 = DAT_00584194;

  if (DAT_00584194 == (undefined4 *)0x0) {

    puVar1 = (undefined4 *)

             MemAllocMsg(1,0x1f44,s_goals_00554030,s_C__Giants_source_main_ai_move_c_00554038,0x41b)

    ;

    *puVar1 = DAT_00584198;

    DAT_00584194 = puVar1 + 1;

    iVar2 = 0;

    DAT_00584198 = puVar1;

    do {

      *(int *)(iVar2 + (int)DAT_00584194) = iVar2 + 0x28 + (int)DAT_00584194;

      iVar2 = iVar2 + 0x28;

    } while (iVar2 < 0x1ef0);

    DAT_00584194[0x7bc] = 0;

    puVar1 = DAT_00584194;

  }

  DAT_00584194 = (undefined4 *)*puVar1;

  puVar3 = puVar1;

  for (iVar2 = 10; iVar2 != 0; iVar2 = iVar2 + -1) {

    *puVar3 = 0;

    puVar3 = puVar3 + 1;

  }

  *puVar1 = *(undefined4 *)(param_1 + 0x168);

  *(undefined4 **)(param_1 + 0x168) = puVar1;

  puVar1[1] = *param_2;

  puVar1[2] = param_2[1];

  puVar1[3] = param_2[2];

  puVar1[5] = 0x80;

  *(uint *)(*(int *)(param_1 + 0x168) + 0x14) =

       *(uint *)(*(int *)(param_1 + 0x168) + 0x14) & 0xffffff7f;

  return;

}

/* ===== main_ai_move_00401310 @ 0x00401310 ===== */
void main_ai_move_00401310(int param_1,undefined4 *param_2,undefined4 param_3)



{

  undefined4 *puVar1;

  int iVar2;

  undefined4 *puVar3;

  

  puVar1 = *(undefined4 **)(param_1 + 0x168);

  while (puVar3 = puVar1, puVar3 != (undefined4 *)0x0) {

    puVar1 = (undefined4 *)*puVar3;

    *puVar3 = DAT_00584194;

    DAT_00584194 = puVar3;

  }

  *(undefined4 *)(param_1 + 0x168) = 0;

  *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) & 0xfcffffff;

  puVar1 = DAT_00584194;

  if (DAT_00584194 == (undefined4 *)0x0) {

    puVar1 = (undefined4 *)

             MemAllocMsg(1,0x1f44,s_goals_00554030,s_C__Giants_source_main_ai_move_c_00554038,0x41b)

    ;

    *puVar1 = DAT_00584198;

    DAT_00584194 = puVar1 + 1;

    iVar2 = 0;

    DAT_00584198 = puVar1;

    do {

      *(int *)(iVar2 + (int)DAT_00584194) = iVar2 + 0x28 + (int)DAT_00584194;

      iVar2 = iVar2 + 0x28;

    } while (iVar2 < 0x1ef0);

    DAT_00584194[0x7bc] = 0;

    puVar1 = DAT_00584194;

  }

  DAT_00584194 = (undefined4 *)*puVar1;

  puVar3 = puVar1;

  for (iVar2 = 10; iVar2 != 0; iVar2 = iVar2 + -1) {

    *puVar3 = 0;

    puVar3 = puVar3 + 1;

  }

  *puVar1 = *(undefined4 *)(param_1 + 0x168);

  *(undefined4 **)(param_1 + 0x168) = puVar1;

  puVar1[4] = param_3;

  puVar1[5] = 0x20;

  puVar1 = DAT_00584194;

  if (DAT_00584194 == (undefined4 *)0x0) {

    puVar1 = (undefined4 *)

             MemAllocMsg(1,0x1f44,s_goals_00554030,s_C__Giants_source_main_ai_move_c_00554038,0x41b)

    ;

    *puVar1 = DAT_00584198;

    DAT_00584194 = puVar1 + 1;

    iVar2 = 0;

    DAT_00584198 = puVar1;

    do {

      *(int *)(iVar2 + (int)DAT_00584194) = iVar2 + 0x28 + (int)DAT_00584194;

      iVar2 = iVar2 + 0x28;

    } while (iVar2 < 0x1ef0);

    DAT_00584194[0x7bc] = 0;

    puVar1 = DAT_00584194;

  }

  DAT_00584194 = (undefined4 *)*puVar1;

  puVar3 = puVar1;

  for (iVar2 = 10; iVar2 != 0; iVar2 = iVar2 + -1) {

    *puVar3 = 0;

    puVar3 = puVar3 + 1;

  }

  *puVar1 = *(undefined4 *)(param_1 + 0x168);

  *(undefined4 **)(param_1 + 0x168) = puVar1;

  puVar1[1] = *param_2;

  puVar1[2] = param_2[1];

  puVar1[3] = param_2[2];

  puVar1[5] = 0x80;

  return;

}

/* ===== main_ai_move_004014b0 @ 0x004014B0 ===== */
void main_ai_move_004014b0(int param_1,undefined4 *param_2,undefined4 param_3)



{

  undefined4 *puVar1;

  int iVar2;

  undefined4 *puVar3;

  

  puVar1 = DAT_00584194;

  if (DAT_00584194 == (undefined4 *)0x0) {

    puVar1 = (undefined4 *)

             MemAllocMsg(1,0x1f44,s_goals_00554030,s_C__Giants_source_main_ai_move_c_00554038,0x41b)

    ;

    *puVar1 = DAT_00584198;

    DAT_00584194 = puVar1 + 1;

    iVar2 = 0;

    DAT_00584198 = puVar1;

    do {

      *(int *)(iVar2 + (int)DAT_00584194) = iVar2 + 0x28 + (int)DAT_00584194;

      iVar2 = iVar2 + 0x28;

    } while (iVar2 < 0x1ef0);

    DAT_00584194[0x7bc] = 0;

    puVar1 = DAT_00584194;

  }

  DAT_00584194 = (undefined4 *)*puVar1;

  puVar3 = puVar1;

  for (iVar2 = 10; iVar2 != 0; iVar2 = iVar2 + -1) {

    *puVar3 = 0;

    puVar3 = puVar3 + 1;

  }

  *puVar1 = *(undefined4 *)(param_1 + 0x168);

  *(undefined4 **)(param_1 + 0x168) = puVar1;

  puVar1[4] = param_3;

  puVar1[5] = 0x20;

  puVar1 = DAT_00584194;

  if (DAT_00584194 == (undefined4 *)0x0) {

    puVar1 = (undefined4 *)

             MemAllocMsg(1,0x1f44,s_goals_00554030,s_C__Giants_source_main_ai_move_c_00554038,0x41b)

    ;

    *puVar1 = DAT_00584198;

    DAT_00584194 = puVar1 + 1;

    iVar2 = 0;

    DAT_00584198 = puVar1;

    do {

      *(int *)(iVar2 + (int)DAT_00584194) = iVar2 + 0x28 + (int)DAT_00584194;

      iVar2 = iVar2 + 0x28;

    } while (iVar2 < 0x1ef0);

    DAT_00584194[0x7bc] = 0;

    puVar1 = DAT_00584194;

  }

  DAT_00584194 = (undefined4 *)*puVar1;

  puVar3 = puVar1;

  for (iVar2 = 10; iVar2 != 0; iVar2 = iVar2 + -1) {

    *puVar3 = 0;

    puVar3 = puVar3 + 1;

  }

  *puVar1 = *(undefined4 *)(param_1 + 0x168);

  *(undefined4 **)(param_1 + 0x168) = puVar1;

  puVar1[1] = *param_2;

  puVar1[2] = param_2[1];

  puVar1[3] = param_2[2];

  puVar1[5] = 0x80;

  return;

}

/* ===== FUN_00401610 @ 0x00401610 ===== */
/* PS2 candidate: ai_moveonly_set_goal (conf 0.324) */



void FUN_00401610(int param_1,undefined4 *param_2)



{

  undefined4 *puVar1;

  int iVar2;

  undefined4 *puVar3;

  

  puVar1 = DAT_00584194;

  if (DAT_00584194 == (undefined4 *)0x0) {

    puVar1 = (undefined4 *)

             MemAllocMsg(1,0x1f44,s_goals_00554030,s_C__Giants_source_main_ai_move_c_00554038,0x41b)

    ;

    *puVar1 = DAT_00584198;

    DAT_00584194 = puVar1 + 1;

    iVar2 = 0;

    DAT_00584198 = puVar1;

    do {

      *(int *)(iVar2 + (int)DAT_00584194) = iVar2 + 0x28 + (int)DAT_00584194;

      iVar2 = iVar2 + 0x28;

    } while (iVar2 < 0x1ef0);

    DAT_00584194[0x7bc] = 0;

    puVar1 = DAT_00584194;

  }

  DAT_00584194 = (undefined4 *)*puVar1;

  puVar3 = puVar1;

  for (iVar2 = 10; iVar2 != 0; iVar2 = iVar2 + -1) {

    *puVar3 = 0;

    puVar3 = puVar3 + 1;

  }

  *puVar1 = *(undefined4 *)(param_1 + 0x168);

  *(undefined4 **)(param_1 + 0x168) = puVar1;

  puVar1[1] = *param_2;

  puVar1[2] = param_2[1];

  puVar1[3] = param_2[2];

  puVar1[5] = 0x80;

  return;

}

/* ===== main_ai_move_004016d0 @ 0x004016D0 ===== */
void main_ai_move_004016d0(int param_1,undefined4 *param_2)



{

  undefined4 *puVar1;

  int iVar2;

  undefined4 *puVar3;

  

  puVar1 = DAT_00584194;

  if (DAT_00584194 == (undefined4 *)0x0) {

    puVar1 = (undefined4 *)

             MemAllocMsg(1,0x1f44,s_goals_00554030,s_C__Giants_source_main_ai_move_c_00554038,0x41b)

    ;

    *puVar1 = DAT_00584198;

    DAT_00584194 = puVar1 + 1;

    iVar2 = 0;

    DAT_00584198 = puVar1;

    do {

      *(int *)(iVar2 + (int)DAT_00584194) = iVar2 + 0x28 + (int)DAT_00584194;

      iVar2 = iVar2 + 0x28;

    } while (iVar2 < 0x1ef0);

    DAT_00584194[0x7bc] = 0;

    puVar1 = DAT_00584194;

  }

  DAT_00584194 = (undefined4 *)*puVar1;

  puVar3 = puVar1;

  for (iVar2 = 10; iVar2 != 0; iVar2 = iVar2 + -1) {

    *puVar3 = 0;

    puVar3 = puVar3 + 1;

  }

  *puVar1 = *(undefined4 *)(param_1 + 0x168);

  *(undefined4 **)(param_1 + 0x168) = puVar1;

  puVar1[1] = *param_2;

  puVar1[2] = param_2[1];

  puVar1[3] = param_2[2];

  puVar1[5] = 0x88;

  return;

}

/* ===== main_ai_move_00401790 @ 0x00401790 ===== */
void main_ai_move_00401790(int param_1,undefined4 param_2,undefined4 *param_3)



{

  undefined4 *puVar1;

  int iVar2;

  undefined4 *puVar3;

  

  puVar1 = DAT_00584194;

  if (DAT_00584194 == (undefined4 *)0x0) {

    puVar1 = (undefined4 *)

             MemAllocMsg(1,0x1f44,s_goals_00554030,s_C__Giants_source_main_ai_move_c_00554038,0x41b)

    ;

    *puVar1 = DAT_00584198;

    DAT_00584194 = puVar1 + 1;

    iVar2 = 0;

    DAT_00584198 = puVar1;

    do {

      *(int *)(iVar2 + (int)DAT_00584194) = iVar2 + 0x28 + (int)DAT_00584194;

      iVar2 = iVar2 + 0x28;

    } while (iVar2 < 0x1ef0);

    DAT_00584194[0x7bc] = 0;

    puVar1 = DAT_00584194;

  }

  DAT_00584194 = (undefined4 *)*puVar1;

  puVar3 = puVar1;

  for (iVar2 = 10; iVar2 != 0; iVar2 = iVar2 + -1) {

    *puVar3 = 0;

    puVar3 = puVar3 + 1;

  }

  *puVar1 = *(undefined4 *)(param_1 + 0x168);

  *(undefined4 **)(param_1 + 0x168) = puVar1;

  puVar1[1] = *param_3;

  puVar1[2] = param_3[1];

  puVar1[3] = param_3[2];

  puVar1[4] = param_2;

  puVar1[5] = 0x80000000;

  return;

}

/* ===== main_ai_move_00401850 @ 0x00401850 ===== */
void main_ai_move_00401850(int param_1,undefined4 param_2,undefined4 *param_3)



{

  undefined4 *puVar1;

  int iVar2;

  undefined4 *puVar3;

  

  puVar1 = DAT_00584194;

  if (DAT_00584194 == (undefined4 *)0x0) {

    puVar1 = (undefined4 *)

             MemAllocMsg(1,0x1f44,s_goals_00554030,s_C__Giants_source_main_ai_move_c_00554038,0x41b)

    ;

    *puVar1 = DAT_00584198;

    DAT_00584194 = puVar1 + 1;

    iVar2 = 0;

    DAT_00584198 = puVar1;

    do {

      *(int *)(iVar2 + (int)DAT_00584194) = iVar2 + 0x28 + (int)DAT_00584194;

      iVar2 = iVar2 + 0x28;

    } while (iVar2 < 0x1ef0);

    DAT_00584194[0x7bc] = 0;

    puVar1 = DAT_00584194;

  }

  DAT_00584194 = (undefined4 *)*puVar1;

  puVar3 = puVar1;

  for (iVar2 = 10; iVar2 != 0; iVar2 = iVar2 + -1) {

    *puVar3 = 0;

    puVar3 = puVar3 + 1;

  }

  *puVar1 = *(undefined4 *)(param_1 + 0x168);

  *(undefined4 **)(param_1 + 0x168) = puVar1;

  puVar1[1] = *param_3;

  puVar1[2] = param_3[1];

  puVar1[3] = param_3[2];

  puVar1[4] = param_2;

  puVar1[5] = 0x80000080;

  return;

}

/* ===== main_ai_move_00401910 @ 0x00401910 ===== */
void main_ai_move_00401910(int param_1,undefined4 param_2)



{

  undefined4 *puVar1;

  int iVar2;

  undefined4 *puVar3;

  

  puVar1 = DAT_00584194;

  if (DAT_00584194 == (undefined4 *)0x0) {

    puVar1 = (undefined4 *)

             MemAllocMsg(1,0x1f44,s_goals_00554030,s_C__Giants_source_main_ai_move_c_00554038,0x41b)

    ;

    *puVar1 = DAT_00584198;

    DAT_00584194 = puVar1 + 1;

    iVar2 = 0;

    DAT_00584198 = puVar1;

    do {

      *(int *)(iVar2 + (int)DAT_00584194) = iVar2 + 0x28 + (int)DAT_00584194;

      iVar2 = iVar2 + 0x28;

    } while (iVar2 < 0x1ef0);

    DAT_00584194[0x7bc] = 0;

    puVar1 = DAT_00584194;

  }

  DAT_00584194 = (undefined4 *)*puVar1;

  puVar3 = puVar1;

  for (iVar2 = 10; iVar2 != 0; iVar2 = iVar2 + -1) {

    *puVar3 = 0;

    puVar3 = puVar3 + 1;

  }

  *puVar1 = *(undefined4 *)(param_1 + 0x168);

  *(undefined4 **)(param_1 + 0x168) = puVar1;

  puVar1[4] = param_2;

  puVar1[5] = 0x20;

  return;

}

/* ===== ai_goal_process @ 0x00402270 ===== */
/* PS2 candidate: ai_goal_process (conf 0.45) */



undefined4 ai_goal_process(undefined4 *param_1)



{

  undefined4 uVar1;

  bool bVar2;

  undefined1 uVar3;

  int iVar4;

  int iVar5;

  undefined4 *puVar6;

  undefined4 *puVar7;

  float fVar8;

  undefined4 *puVar9;

  float10 fVar10;

  float10 fVar11;

  float local_90;

  float local_8c;

  undefined4 local_88;

  float local_84;

  float local_80;

  float local_7c;

  undefined4 local_78 [30];

  

  if (DAT_00632e40 != 0) {

    return 0;

  }

  fVar8 = 0.0;

  if (param_1[0x5a] == 0) {

    return 1;

  }

  do {

    param_1[0x36] = param_1[0x36] & 0xfcffffff;

    bVar2 = false;

    iVar4 = FUN_00401fe0(param_1);

    if (iVar4 != 0) {

      do {

        puVar7 = (undefined4 *)param_1[0x5a];

        if ((puVar7 == (undefined4 *)0x0) || ((*(byte *)(puVar7 + 5) & 0x10) != 0)) {

          if (!bVar2) goto LAB_00402316;

          break;

        }

        param_1[0x5a] = *puVar7;

        *puVar7 = DAT_00584194;

        bVar2 = true;

        DAT_00584194 = puVar7;

        iVar4 = FUN_00401fe0(param_1);

      } while (iVar4 != 0);

      voBufReset__FP5VoBuf(param_1);

    }

LAB_00402316:

    iVar4 = param_1[0x5a];

    if (iVar4 == 0) {

      return 1;

    }

    if ((*(uint *)(iVar4 + 0x14) & 0x10) != 0) {

      return 1;

    }

    if (DAT_00584190 != 0) {

      *(uint *)(iVar4 + 0x14) = *(uint *)(iVar4 + 0x14) & 0xffffff7f;

    }

    if ((*(uint *)(iVar4 + 0x14) & 0x400) != 0) {

      local_90 = *(float *)(iVar4 + 0x10);

      *(undefined1 *)((int)param_1 + 0x20a) = 0;

      *(undefined1 *)(param_1 + 0x82) = 0;

      fVar10 = (float10)playerobj_turn(local_90,param_1[0x32]);

      if (fVar10 != (float10)0.0) {

        param_1[0x56] = local_90;

        param_1[0x36] = param_1[0x36] | 0x1000000;

        uVar3 = FUN_004a7d70((float)(fVar10 * (float10)0.05));

        *(undefined1 *)(param_1 + 0x82) = uVar3;

      }

      *(undefined1 *)((int)param_1 + 0x20a) = 0x20;

      fVar10 = (float10)FUN_00518b70(param_1,0);

      *(float *)(iVar4 + 0x18) = (float)((float10)*(float *)(iVar4 + 0x18) - fVar10);

      return 0;

    }

    if (-1 < (char)*(uint *)(iVar4 + 0x14)) {

      if ((*(byte *)(iVar4 + 0x14) & 0x20) != 0) {

        local_90 = *(float *)(iVar4 + 0x10);

        *(undefined1 *)((int)param_1 + 0x20a) = 0;

        *(undefined1 *)(param_1 + 0x82) = 0;

        fVar10 = (float10)playerobj_turn(local_90,param_1[0x32]);

        if (fVar10 == (float10)0.0) {

          return 0;

        }

        param_1[0x56] = local_90;

        param_1[0x36] = param_1[0x36] | 0x1000000;

        uVar3 = FUN_004a7d70((float)(fVar10 * (float10)0.05));

        *(undefined1 *)(param_1 + 0x82) = uVar3;

        return 0;

      }

      if (*(float *)(iVar4 + 0x18) == 0.0) {

        *(undefined4 *)(iVar4 + 0x1c) = param_1[0x28];

        *(undefined4 *)(iVar4 + 0x20) = param_1[0x29];

        *(undefined4 *)(iVar4 + 0x24) = param_1[0x2a];

      }

      fVar8 = DAT_006328e0 + *(float *)(iVar4 + 0x18);

      *(float *)(iVar4 + 0x18) = fVar8;

      if (3.0 < fVar8) {

        fVar10 = (float10)distancesq2d__FP3P3DT0(iVar4 + 0x1c,iVar4 + 4);

        local_8c = (float)fVar10;

        fVar10 = (float10)distancesq2d__FP3P3DT0(param_1 + 0x28,iVar4 + 4);

        local_90 = (float)fVar10;

        fVar10 = (float10)distancesq2d__FP3P3DT0(iVar4 + 0x1c,param_1 + 0x28);

        if ((local_8c < local_90) ||

           (fVar11 = (float10)(float)param_1[0x43] * (float10)*(float *)(iVar4 + 0x18) *

                     (float10)0.5, fVar10 < fVar11 * fVar11)) {

          puVar7 = (undefined4 *)param_1[0x5a];

          while (puVar9 = puVar7, puVar9 != (undefined4 *)0x0) {

            puVar7 = (undefined4 *)*puVar9;

            *puVar9 = DAT_00584194;

            DAT_00584194 = puVar9;

          }

          param_1[0x5a] = 0;

LAB_004026d0:

          param_1[0x36] = param_1[0x36] & 0xfcffffff;

          return 0xffffffff;

        }

        *(undefined4 *)(iVar4 + 0x18) = 0;

      }

      iVar5 = iVar4 + 4;

      if ((2.0 <= ABS(*(float *)(iVar4 + 4) - (float)param_1[0x28])) ||

         (2.0 <= ABS(*(float *)(iVar4 + 8) - (float)param_1[0x29]))) {

        bVar2 = false;

      }

      else {

        bVar2 = true;

      }

      if (bVar2) {

        if ((*(byte *)(iVar4 + 0x14) & 8) != 0) {

          if (2.0 <= ABS(*(float *)(iVar4 + 0xc) - (float)param_1[0x2a])) {

            bVar2 = false;

          }

          else {

            bVar2 = true;

          }

        }

        if (((!bVar2) &&

            (fVar10 = (float10)get_floor_z_point_plat(iVar5,&local_90),

            (float10)(float)param_1[0x2a] < fVar10)) && (local_90 != 0.0)) {

          collgrid_pos_query_dlog(local_90,iVar5,&local_88);

          puVar7 = (undefined4 *)main_ai_move_004033d0();

          *puVar7 = param_1[0x5a];

          param_1[0x5a] = puVar7;

          puVar7[1] = local_88;

          puVar7[2] = local_84;

          puVar7[3] = local_80;

          puVar7[5] = 0x80;

          puVar7 = DAT_00584194;

          if (DAT_00584194 == (undefined4 *)0x0) {

            puVar7 = (undefined4 *)

                     MemAllocMsg(1,0x1f44,s_goals_00554030,

                                 s_C__Giants_source_main_ai_move_c_00554038,0x41b);

            *puVar7 = DAT_00584198;

            DAT_00584194 = puVar7 + 1;

            iVar4 = 0;

            DAT_00584198 = puVar7;

            do {

              *(int *)(iVar4 + (int)DAT_00584194) = iVar4 + 0x28 + (int)DAT_00584194;

              iVar4 = iVar4 + 0x28;

            } while (iVar4 < 0x1ef0);

            DAT_00584194[0x7bc] = 0;

            puVar7 = DAT_00584194;

          }

          DAT_00584194 = (undefined4 *)*puVar7;

          puVar9 = puVar7;

          for (iVar4 = 10; iVar4 != 0; iVar4 = iVar4 + -1) {

            *puVar9 = 0;

            puVar9 = puVar9 + 1;

          }

          *puVar7 = param_1[0x5a];

          param_1[0x5a] = puVar7;

          puVar7[1] = local_88;

          puVar7[2] = local_84;

          puVar7[3] = local_80;

          puVar7[5] = 4;

          return 0;

        }

      }

      else {

        ai_chase_location__FP6OBJECTP3P3DUi(param_1,iVar5,*(undefined4 *)(iVar4 + 0x14));

      }

      if (*(int *)(iVar4 + 0x14) < 0) {

        local_8c = (float)param_1[0x50];

        local_90 = *(float *)(iVar4 + 0x10);

        if (local_8c < 0.0) {

          local_8c = 0.0;

        }

        local_8c = (float)param_1[0x2a] - local_8c;

        local_7c = -50.0;

        local_84 = -3.0;

        local_80 = 5.0;

        local_88 = 0x41000000;

        if ((code *)param_1[0x5b] != (code *)0x0) {

          (*(code *)param_1[0x5b])(1,param_1,&local_88);

        }

        if (local_8c < local_90) {

          param_1[0x42] = local_88;

          return 0;

        }

        if (local_8c < local_80 + local_90) {

          param_1[0x42] = 0;

          return 0;

        }

        if ((float)param_1[0x42] < local_7c) {

          param_1[0x42] = local_7c;

          return 0;

        }

        if (((float)param_1[0x42] < local_84) && (local_8c - local_90 < -local_84)) {

          param_1[0x42] = local_84;

        }

      }

      return 0;

    }

    local_8c = (float)((int)fVar8 + 1);

    if (1 < (int)fVar8) {

      return 0;

    }

    iVar4 = param_1[0x5a];

    if (iVar4 != 0) {

      if ((int)*(uint *)(iVar4 + 0x14) < 0) {

        main_ai_move_00402b90(param_1,*(undefined4 *)(iVar4 + 0x10),iVar4 + 4);

      }

      else if ((*(uint *)(iVar4 + 0x14) & 0x40) == 0) {

        if (param_1[0x89] == 0) {

          iVar5 = path_world_init__Fv();

          if ((iVar5 == -1) || (local_90 == 0.0)) {

            puVar7 = (undefined4 *)param_1[0x5a];

            while (puVar9 = puVar7, puVar9 != (undefined4 *)0x0) {

              puVar7 = (undefined4 *)*puVar9;

              *puVar9 = DAT_00584194;

              DAT_00584194 = puVar9;

            }

            param_1[0x5a] = 0;

            goto LAB_004026d0;

          }

          if ((iVar5 == 0) && ((int)local_90 < 2)) {

            main_ai_move_004029a0(param_1,iVar4 + 4);

          }

          else if (-1 < (int)local_90 + -1) {

            puVar7 = local_78 + ((int)local_90 + -1) * 6;

            fVar8 = local_90;

            do {

              puVar6 = (undefined4 *)main_ai_move_004033d0();

              *puVar6 = param_1[0x5a];

              uVar1 = *puVar7;

              param_1[0x5a] = puVar6;

              puVar6[1] = uVar1;

              puVar6[2] = puVar7[1];

              puVar9 = puVar7 + 2;

              puVar7 = puVar7 + -6;

              fVar8 = (float)((int)fVar8 + -1);

              puVar6[3] = *puVar9;

              puVar6[5] = 0xc4;

            } while (fVar8 != 0.0);

          }

        }

        else {

          local_90 = 0.0;

          main_ai_move_004029a0(param_1,iVar4 + 4);

        }

      }

      else {

        main_ai_move_004029a0(param_1,iVar4 + 4);

      }

    }

    fVar8 = local_8c;

    if (param_1[0x5a] == 0) {

      return 0xffffffff;

    }

  } while( true );

}

/* ===== main_ai_move_004029a0 @ 0x004029A0 ===== */
void main_ai_move_004029a0(int param_1,undefined4 param_2)



{

  undefined4 uVar1;

  int iVar2;

  undefined4 *puVar3;

  int iVar4;

  undefined4 *puVar5;

  undefined4 *puVar6;

  int local_7c;

  undefined4 local_78 [30];

  

  if (DAT_00584190 != 0) {

    iVar2 = *(int *)(param_1 + 0x168);

    if (iVar2 == 0) {

      return;

    }

    *(uint *)(iVar2 + 0x14) = *(uint *)(iVar2 + 0x14) & 0xffffff7f;

    return;

  }

  iVar2 = path_short_calculate

                    (param_1,*(undefined4 *)(param_1 + 0x154),param_1 + 0xa0,param_2,5,&local_7c,

                     local_78);

  if ((iVar2 == -1) || (local_7c == 0)) {

    puVar5 = *(undefined4 **)(param_1 + 0x168);

    while (puVar3 = puVar5, puVar3 != (undefined4 *)0x0) {

      puVar5 = (undefined4 *)*puVar3;

      *puVar3 = DAT_00584194;

      DAT_00584194 = puVar3;

    }

  }

  else {

    if (local_7c != 1) {

      if (local_7c + -2 < 0) {

        return;

      }

      puVar5 = local_78 + (local_7c + -2) * 6;

      iVar2 = local_7c + -1;

      do {

        puVar3 = DAT_00584194;

        if (DAT_00584194 == (undefined4 *)0x0) {

          puVar3 = (undefined4 *)

                   MemAllocMsg(1,0x1f44,s_goals_00554030,s_C__Giants_source_main_ai_move_c_00554038,

                               0x41b);

          *puVar3 = DAT_00584198;

          DAT_00584194 = puVar3 + 1;

          iVar4 = 0;

          DAT_00584198 = puVar3;

          do {

            *(int *)(iVar4 + (int)DAT_00584194) = iVar4 + 0x28 + (int)DAT_00584194;

            iVar4 = iVar4 + 0x28;

          } while (iVar4 < 0x1ef0);

          DAT_00584194[0x7bc] = 0;

          puVar3 = DAT_00584194;

        }

        DAT_00584194 = (undefined4 *)*puVar3;

        puVar6 = puVar3;

        for (iVar4 = 10; iVar4 != 0; iVar4 = iVar4 + -1) {

          *puVar6 = 0;

          puVar6 = puVar6 + 1;

        }

        *puVar3 = *(undefined4 *)(param_1 + 0x168);

        uVar1 = *puVar5;

        *(undefined4 **)(param_1 + 0x168) = puVar3;

        puVar3[1] = uVar1;

        puVar3[2] = puVar5[1];

        puVar6 = puVar5 + 2;

        puVar5 = puVar5 + -6;

        iVar2 = iVar2 + -1;

        puVar3[3] = *puVar6;

        puVar3[5] = 4;

      } while (iVar2 != 0);

      return;

    }

    if (iVar2 == 0) {

      iVar2 = *(int *)(param_1 + 0x168);

      if (iVar2 == 0) {

        return;

      }

      *(uint *)(iVar2 + 0x14) = *(uint *)(iVar2 + 0x14) & 0xffffff7f;

      return;

    }

    puVar5 = *(undefined4 **)(param_1 + 0x168);

    while (puVar3 = puVar5, puVar3 != (undefined4 *)0x0) {

      puVar5 = (undefined4 *)*puVar3;

      *puVar3 = DAT_00584194;

      DAT_00584194 = puVar3;

    }

  }

  *(undefined4 *)(param_1 + 0x168) = 0;

  *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) & 0xfcffffff;

  return;

}

/* ===== main_ai_move_00402b90 @ 0x00402B90 ===== */
void main_ai_move_00402b90(int param_1,undefined4 param_2,undefined4 param_3)



{

  uint *puVar1;

  int iVar2;

  undefined4 *puVar3;

  int iVar4;

  undefined4 *puVar5;

  undefined4 *puVar6;

  int local_7c;

  undefined4 local_78 [30];

  

  iVar2 = path_flyer_calculate

                    (param_1,*(undefined4 *)(param_1 + 0x154),param_1 + 0xa0,param_3,param_2,5,

                     &local_7c,local_78);

  if ((iVar2 == -1) || (local_7c == 0)) {

    puVar5 = *(undefined4 **)(param_1 + 0x168);

    while (puVar3 = puVar5, puVar3 != (undefined4 *)0x0) {

      puVar5 = (undefined4 *)*puVar3;

      *puVar3 = DAT_00584194;

      DAT_00584194 = puVar3;

    }

  }

  else {

    if (local_7c != 1) {

      if (local_7c + -2 < 0) {

        return;

      }

      puVar5 = local_78 + (local_7c + -2) * 6;

      iVar2 = local_7c + -1;

      do {

        puVar3 = DAT_00584194;

        if (DAT_00584194 == (undefined4 *)0x0) {

          puVar3 = (undefined4 *)

                   MemAllocMsg(1,0x1f44,s_goals_00554030,s_C__Giants_source_main_ai_move_c_00554038,

                               0x41b);

          *puVar3 = DAT_00584198;

          DAT_00584194 = puVar3 + 1;

          iVar4 = 0;

          DAT_00584198 = puVar3;

          do {

            *(int *)(iVar4 + (int)DAT_00584194) = iVar4 + 0x28 + (int)DAT_00584194;

            iVar4 = iVar4 + 0x28;

          } while (iVar4 < 0x1ef0);

          DAT_00584194[0x7bc] = 0;

          puVar3 = DAT_00584194;

        }

        DAT_00584194 = (undefined4 *)*puVar3;

        puVar6 = puVar3;

        for (iVar4 = 10; iVar4 != 0; iVar4 = iVar4 + -1) {

          *puVar6 = 0;

          puVar6 = puVar6 + 1;

        }

        *puVar3 = *(undefined4 *)(param_1 + 0x168);

        *(undefined4 **)(param_1 + 0x168) = puVar3;

        puVar3[1] = *puVar5;

        puVar3[2] = puVar5[1];

        puVar3[3] = puVar5[2];

        puVar5 = puVar5 + -6;

        iVar2 = iVar2 + -1;

        puVar3[4] = param_2;

        puVar3[5] = 0x80000004;

      } while (iVar2 != 0);

      return;

    }

    if (iVar2 == 0) {

      if (*(int *)(param_1 + 0x168) == 0) {

        return;

      }

      puVar1 = (uint *)(*(int *)(param_1 + 0x168) + 0x14);

      *puVar1 = *puVar1 & 0xffffff7f;

      return;

    }

    puVar5 = *(undefined4 **)(param_1 + 0x168);

    while (puVar3 = puVar5, puVar3 != (undefined4 *)0x0) {

      puVar5 = (undefined4 *)*puVar3;

      *puVar3 = DAT_00584194;

      DAT_00584194 = puVar3;

    }

  }

  *(undefined4 *)(param_1 + 0x168) = 0;

  *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) & 0xfcffffff;

  return;

}

/* ===== ai_chase_location__FP6OBJECTP3P3DUi @ 0x00402D60 ===== */
/* PS2 candidate: ai_chase_location__FP6OBJECTP3P3DUi (conf 0.418) */



void ai_chase_location__FP6OBJECTP3P3DUi(float param_1,undefined4 *param_2,uint param_3)



{

  float *pfVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  int iVar5;

  undefined1 uVar6;

  char cVar7;

  int iVar8;

  undefined4 *puVar9;

  int iVar10;

  float *pfVar11;

  undefined4 *puVar12;

  float10 fVar13;

  float fStack_28;

  float fStack_24;

  undefined4 uStack_20;

  float local_1c;

  int local_18;

  undefined4 local_14;

  float local_10;

  float local_c;

  float local_8;

  float local_4;

  

  puVar9 = param_2;

  iVar5 = (int)param_1;

  cVar7 = *(char *)((int)param_1 + 0x20a);

  pfVar1 = (float *)((int)param_1 + 0xa0);

  fVar4 = (float)(int)cVar7 * 0.03125;

  *(undefined1 *)((int)param_1 + 0x20a) = 0;

  *(undefined1 *)((int)param_1 + 0x208) = 0;

  *(undefined1 *)((int)param_1 + 0x20b) = 0;

  param_1 = (float)(int)cVar7;

  fVar13 = (float10)FUN_0050a520(pfVar1,param_2);

  param_2 = (undefined4 *)(float)fVar13;

  if (ABS(fVar13) < (float10)2.0) {

    return;

  }

  pfVar11 = &local_1c;

  for (iVar10 = 7; iVar10 != 0; iVar10 = iVar10 + -1) {

    *pfVar11 = 0.0;

    pfVar11 = pfVar11 + 1;

  }

  local_14 = 0x3f800000;

  local_8 = 1.0;

  local_10 = 1.0;

  local_4 = 5.0;

  local_c = 5.0;

  local_1c = (float)param_2;

  if (*(code **)(iVar5 + 0x16c) != (code *)0x0) {

    (**(code **)(iVar5 + 0x16c))(0,iVar5,&local_1c);

  }

  if (((param_3 & 4) == 0) && (local_18 == 0)) {

    *(undefined4 *)(iVar5 + 0x15c) = *puVar9;

    *(undefined4 *)(iVar5 + 0x160) = puVar9[1];

    *(undefined4 *)(iVar5 + 0x164) = puVar9[2];

    *(uint *)(iVar5 + 0xd8) = *(uint *)(iVar5 + 0xd8) | 0x2000000;

  }

  fVar13 = (float10)dirfcalcp3d__FP3P3DT0(pfVar1,puVar9);

  fVar2 = (float)fVar13;

  fVar13 = (float10)playerobj_turn(fVar2,*(undefined4 *)(iVar5 + 200));

  param_1 = (float)fVar13;

  fVar3 = (float)ABS(fVar13);

  if ((local_10 <= (float)param_2) || (fVar3 <= 180.0 - local_c)) {

    if (((float)param_2 < local_8) &&

       ((90.0 - local_4 < fVar3 != (90.0 - local_4 == fVar3) && (fVar3 <= local_4 + 90.0)))) {

      if (param_1 <= 0.0) {

        param_2 = (undefined4 *)(fVar2 + 90.0);

      }

      else {

        param_2 = (undefined4 *)(fVar2 - 90.0);

      }

      *(float *)(iVar5 + 0x158) = (float)param_2;

      FUN_00451560((float *)(iVar5 + 0x158));

      *(uint *)(iVar5 + 0xd8) = *(uint *)(iVar5 + 0xd8) | 0x1000000;

      fVar13 = (float10)playerobj_turn(param_2,*(undefined4 *)(iVar5 + 200));

      param_2 = (undefined4 *)(float)(fVar13 * (float10)0.025);

      uVar6 = FUN_004a7be0(param_2,0x3727c5ac,0x3e4ccccd);

      *(undefined1 *)(iVar5 + 0x208) = uVar6;

      uVar6 = __ftol();

      *(undefined1 *)(iVar5 + 0x20b) = uVar6;

      goto LAB_00403218;

    }

    *(float *)(iVar5 + 0x158) = fVar2;

    FUN_00451560((float *)(iVar5 + 0x158));

    *(uint *)(iVar5 + 0xd8) = *(uint *)(iVar5 + 0xd8) | 0x1000000;

    fVar13 = (float10)playerobj_turn(fVar2,*(undefined4 *)(iVar5 + 200));

    cVar7 = FUN_004a7be0((float)(fVar13 * (float10)0.025),0x3727c5ac,0x3e4ccccd);

    *(char *)(iVar5 + 0x208) = cVar7;

    fVar3 = ABS((float)(int)cVar7 * 0.03125);

    if ((fVar3 < 0.2 != (fVar3 == 0.2)) ||

       ((360.0 / (fVar3 * *(float *)(iVar5 + 0x1a8))) * *(float *)(iVar5 + 0x194) < (float)param_2))

    {

      fVar13 = (float10)FUN_00518b70(iVar5,0);

      if ((float10)(float)param_2 < fVar13 * (float10)*(float *)(iVar5 + 0x10c)) {

        FUN_00518b70(iVar5,0);

      }

    }

    else if (param_1 <= 0.0) {

      if (0.0 <= param_1) {

        *(undefined1 *)(iVar5 + 0x208) = 0;

      }

      else {

        *(undefined1 *)(iVar5 + 0x208) = 0xe0;

      }

    }

    else {

      *(undefined1 *)(iVar5 + 0x208) = 0x20;

    }

    if (((30.0 < param_1) && (param_1 < 150.0)) || ((param_1 < -30.0 && (-150.0 < param_1)))) {

      uVar6 = __ftol();

      *(undefined1 *)(iVar5 + 0x20b) = uVar6;

    }

  }

  else {

    param_1 = fVar2 + 180.0;

    *(float *)(iVar5 + 0x158) = param_1;

    FUN_00451560((float *)(iVar5 + 0x158));

    *(uint *)(iVar5 + 0xd8) = *(uint *)(iVar5 + 0xd8) | 0x1000000;

    fVar13 = (float10)playerobj_turn(param_1,*(undefined4 *)(iVar5 + 200));

    param_1 = (float)(fVar13 * (float10)0.025);

    uVar6 = FUN_004a7be0(param_1,0x3727c5ac,0x3e4ccccd);

    *(undefined1 *)(iVar5 + 0x208) = uVar6;

    if (fVar3 <= 170.0) goto LAB_00403218;

  }

  uVar6 = __ftol();

  *(undefined1 *)(iVar5 + 0x20a) = uVar6;

LAB_00403218:

  if ((local_18 != 0) &&

     (param_1 = (float)(int)*(char *)(iVar5 + 0x20a), (float)(int)param_1 * fVar4 < 0.0)) {

    if (fVar4 <= 0.0) {

      *(undefined1 *)(iVar5 + 0x20a) = 0xfd;

    }

    else {

      *(undefined1 *)(iVar5 + 0x20a) = 3;

    }

  }

  if ((-1 < (int)param_3) && (iVar10 = FUN_00413880(iVar5), iVar10 != 0)) {

    param_3 = -1;

    while( true ) {

      iVar10 = param_3;

      sine_cos_lookup((float)(int)param_3 * 90.0 + fVar2,&param_1,&param_2);

      fStack_28 = param_1 * *(float *)(DAT_006330e4 + 0x1c0) * 0.5 + *pfVar1;

      uStack_20 = *(undefined4 *)(iVar5 + 0xa8);

      fStack_24 = *(float *)(iVar5 + 0xa4) - (float)param_2 * *(float *)(DAT_006330e4 + 0x1c0) * 0.5

      ;

      iVar8 = FUN_004138c0(iVar5,&fStack_28,fVar2);

      if (iVar8 == 0) break;

      param_3 = iVar10 + 2;

      if (1 < (int)param_3) {

        return;

      }

    }

    puVar9 = DAT_00584194;

    if (DAT_00584194 == (undefined4 *)0x0) {

      puVar9 = (undefined4 *)

               MemAllocMsg(1,0x1f44,s_goals_00554030,s_C__Giants_source_main_ai_move_c_00554038,

                           0x41b);

      *puVar9 = DAT_00584198;

      DAT_00584194 = puVar9 + 1;

      iVar10 = 0;

      DAT_00584198 = puVar9;

      do {

        *(int *)(iVar10 + (int)DAT_00584194) = iVar10 + 0x28 + (int)DAT_00584194;

        iVar10 = iVar10 + 0x28;

      } while (iVar10 < 0x1ef0);

      DAT_00584194[0x7bc] = 0;

      puVar9 = DAT_00584194;

    }

    DAT_00584194 = (undefined4 *)*puVar9;

    puVar12 = puVar9;

    for (iVar10 = 10; iVar10 != 0; iVar10 = iVar10 + -1) {

      *puVar12 = 0;

      puVar12 = puVar12 + 1;

    }

    *puVar9 = *(undefined4 *)(iVar5 + 0x168);

    *(undefined4 **)(iVar5 + 0x168) = puVar9;

    puVar9[6] = 0x3f000000;

    puVar9[4] = (float)(int)param_3 * 45.0 + fVar2;

    puVar9[5] = 0xc00;

  }

  return;

}

/* ===== main_ai_move_004033d0 @ 0x004033D0 ===== */
undefined4 * main_ai_move_004033d0(void)



{

  undefined4 *puVar1;

  int iVar2;

  undefined4 *puVar3;

  

  puVar1 = DAT_00584194;

  if (DAT_00584194 == (undefined4 *)0x0) {

    puVar1 = (undefined4 *)

             MemAllocMsg(1,0x1f44,s_goals_00554030,s_C__Giants_source_main_ai_move_c_00554038,0x41b)

    ;

    *puVar1 = DAT_00584198;

    DAT_00584194 = puVar1 + 1;

    iVar2 = 0;

    DAT_00584198 = puVar1;

    do {

      *(int *)(iVar2 + (int)DAT_00584194) = iVar2 + 0x28 + (int)DAT_00584194;

      iVar2 = iVar2 + 0x28;

    } while (iVar2 < 0x1ef0);

    DAT_00584194[0x7bc] = 0;

    puVar1 = DAT_00584194;

  }

  DAT_00584194 = (undefined4 *)*puVar1;

  puVar3 = puVar1;

  for (iVar2 = 10; iVar2 != 0; iVar2 = iVar2 + -1) {

    *puVar3 = 0;

    puVar3 = puVar3 + 1;

  }

  return puVar1;

}

/* ===== main_ai_move_00403460 @ 0x00403460 ===== */
void main_ai_move_00403460(void)



{

  undefined4 *puVar1;

  undefined4 *puVar2;

  

  puVar2 = DAT_00584198;

  while (puVar2 != (undefined4 *)0x0) {

    puVar1 = (undefined4 *)*puVar2;

    mem_free_tagged(puVar2,s_C__Giants_source_main_ai_move_c_00554038,0x43d);

    puVar2 = puVar1;

  }

  DAT_00584198 = (undefined4 *)0x0;

  DAT_00584194 = 0;

  return;

}

