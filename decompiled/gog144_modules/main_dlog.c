/* Giants 1.449 — module main/dlog
 * 19 functions (19 named) — decompiled, names from PS2 symbols
 * Original source: C:\Giants\source\main/dlog.c(pp) (assert-string evidence)
 */

/* ===== main_dlog_00427150 @ 0x00427150 ===== */
void main_dlog_00427150(void)



{

  undefined4 *puVar1;

  

  puVar1 = (undefined4 *)

           FUN_0053a700(8,0xc,&DAT_00556508,s_C__Giants_source_main_dlog_c_00556510,0x8e);

  *puVar1 = 0;

  puVar1[1] = 0;

  puVar1[2] = 0;

  puVar1[2] = 0xffffffff;

  return;

}

/* ===== main_dlog_00427180 @ 0x00427180 ===== */
void main_dlog_00427180(undefined4 *param_1)



{

  int iVar1;

  undefined4 *puVar2;

  undefined4 *puVar3;

  undefined4 *puVar4;

  undefined4 *puVar5;

  undefined4 uVar6;

  undefined4 uVar7;

  

  puVar4 = (undefined4 *)*param_1;

  do {

    if (puVar4 == (undefined4 *)0x0) {

      mem_free_tagged(param_1,s_C__Giants_source_main_dlog_c_00556510,0x9f);

      return;

    }

    iVar1 = puVar4[1];

    puVar2 = (undefined4 *)*puVar4;

    if (iVar1 == 3) {

      puVar5 = (undefined4 *)puVar4[10];

      while (puVar5 != (undefined4 *)0x0) {

        puVar3 = (undefined4 *)*puVar5;

        mem_free_tagged(puVar5,s_C__Giants_source_main_dlog_c_00556510,0xad);

        puVar5 = puVar3;

      }

    }

    else if (iVar1 == 0) {

      if ((*(byte *)(puVar4 + 3) & 1) != 0) {

        uVar6 = puVar4[10];

        uVar7 = 0xb4;

LAB_004271f3:

        mem_free_tagged(uVar6,s_C__Giants_source_main_dlog_c_00556510,uVar7);

      }

    }

    else if ((iVar1 == 2) && ((*(byte *)(puVar4 + 3) & 1) != 0)) {

      uVar6 = puVar4[0xb];

      uVar7 = 0xba;

      goto LAB_004271f3;

    }

    mem_free_tagged(puVar4,s_C__Giants_source_main_dlog_c_00556510,0x9d);

    puVar4 = puVar2;

  } while( true );

}

/* ===== main_dlog_00427230 @ 0x00427230 ===== */
void main_dlog_00427230(int *param_1,int param_2)



{

  int *piVar1;

  int iVar2;

  undefined4 *puVar3;

  int *piVar4;

  undefined4 *puVar5;

  undefined4 uVar6;

  undefined4 uVar7;

  

  if (param_1 == (int *)0x0) {

    return;

  }

  piVar1 = (int *)*param_1;

  while ((piVar4 = piVar1, piVar4 != (int *)0x0 && (piVar4[2] != param_2))) {

    param_1 = piVar4;

    piVar1 = (int *)*piVar4;

  }

  piVar1 = (int *)*param_1;

  if (piVar1 == (int *)0x0) {

    return;

  }

  *param_1 = *piVar1;

  iVar2 = piVar1[1];

  if (iVar2 == 3) {

    puVar5 = (undefined4 *)piVar1[10];

    while (puVar5 != (undefined4 *)0x0) {

      puVar3 = (undefined4 *)*puVar5;

      mem_free_tagged(puVar5,s_C__Giants_source_main_dlog_c_00556510,0xad);

      puVar5 = puVar3;

    }

  }

  else {

    if (iVar2 == 0) {

      if ((*(byte *)(piVar1 + 3) & 1) == 0) goto LAB_004272ca;

      uVar6 = piVar1[10];

      uVar7 = 0xb4;

    }

    else {

      if ((iVar2 != 2) || ((*(byte *)(piVar1 + 3) & 1) == 0)) goto LAB_004272ca;

      uVar6 = piVar1[0xb];

      uVar7 = 0xba;

    }

    mem_free_tagged(uVar6,s_C__Giants_source_main_dlog_c_00556510,uVar7);

  }

LAB_004272ca:

  mem_free_tagged(piVar1,s_C__Giants_source_main_dlog_c_00556510,0xcc);

  return;

}

/* ===== main_dlog_004273b0 @ 0x004273B0 ===== */
void main_dlog_004273b0(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4

                       ,uint param_5,undefined4 param_6)



{

  undefined4 *puVar1;

  undefined4 *puVar2;

  undefined4 *puVar3;

  undefined4 uVar4;

  int iVar5;

  undefined4 *puVar6;

  

  puVar3 = (undefined4 *)

           FUN_0053a700(8,0x38,s_dlogentry_00556530,s_C__Giants_source_main_dlog_c_00556510,0x176);

  puVar6 = puVar3;

  for (iVar5 = 0xe; iVar5 != 0; iVar5 = iVar5 + -1) {

    *puVar6 = 0;

    puVar6 = puVar6 + 1;

  }

  puVar2 = (undefined4 *)*param_1;

  puVar6 = param_1;

  while (puVar1 = puVar2, puVar1 != (undefined4 *)0x0) {

    puVar6 = puVar1;

    puVar2 = (undefined4 *)*puVar1;

  }

  *puVar6 = puVar3;

  puVar3[1] = 0;

  puVar3[2] = param_2;

  uVar4 = param_6;

  if ((param_5 & 0x2000000) != 0) {

    uVar4 = FUN_00507b00(param_6);

  }

  param_6 = 0x3ccccccd;

  if ((param_5 & 0x1000000) == 0) {

    param_6 = 0x3d000000;

  }

  if ((param_5 & 1) == 0) {

    puVar3[10] = uVar4;

  }

  else {

    MemString(8,uVar4,puVar3 + 10,s_C__Giants_source_main_dlog_c_00556510,0x17f);

  }

  puVar3[4] = param_3;

  puVar3[5] = param_4;

  puVar3[0xc] = param_6;

  puVar3[3] = param_5;

  puVar3[0xd] = 0;

  main_dlog_00427570(param_1,puVar3);

  return;

}

/* ===== main_dlog_00427490 @ 0x00427490 ===== */
void main_dlog_00427490(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4

                       ,uint param_5,undefined4 param_6,undefined4 param_7)



{

  undefined4 *puVar1;

  undefined4 *puVar2;

  undefined4 *puVar3;

  undefined4 uVar4;

  int iVar5;

  undefined4 *puVar6;

  

  puVar3 = (undefined4 *)

           FUN_0053a700(8,0x38,s_dlogentry_00556530,s_C__Giants_source_main_dlog_c_00556510,400);

  puVar6 = puVar3;

  for (iVar5 = 0xe; iVar5 != 0; iVar5 = iVar5 + -1) {

    *puVar6 = 0;

    puVar6 = puVar6 + 1;

  }

  puVar2 = (undefined4 *)*param_1;

  puVar6 = param_1;

  while (puVar1 = puVar2, puVar1 != (undefined4 *)0x0) {

    puVar6 = puVar1;

    puVar2 = (undefined4 *)*puVar1;

  }

  *puVar6 = puVar3;

  puVar3[1] = 0;

  puVar3[2] = param_2;

  uVar4 = param_6;

  if ((param_5 & 0x2000000) != 0) {

    uVar4 = FUN_00507b00(param_6);

  }

  param_6 = 0x3ccccccd;

  if ((param_5 & 0x1000000) == 0) {

    param_6 = 0x3d000000;

  }

  if ((param_5 & 1) == 0) {

    puVar3[10] = uVar4;

  }

  else {

    MemString(8,uVar4,puVar3 + 10,s_C__Giants_source_main_dlog_c_00556510,0x199);

  }

  puVar3[4] = param_3;

  puVar3[5] = param_4;

  puVar3[0xc] = param_6;

  puVar3[3] = param_5;

  puVar3[0xd] = param_7;

  main_dlog_00427570(param_1,puVar3);

  return;

}

/* ===== main_dlog_00427790 @ 0x00427790 ===== */
void main_dlog_00427790(int *param_1,int param_2,int param_3)



{

  int *piVar1;

  

  piVar1 = (int *)*param_1;

  if (piVar1 != (int *)0x0) {

    while (piVar1[2] != param_2) {

      piVar1 = (int *)*piVar1;

      if (piVar1 == (int *)0x0) {

        return;

      }

    }

    if (piVar1 != (int *)0x0) {

      if ((*(byte *)(piVar1 + 3) & 1) != 0) {

        mem_free_tagged(piVar1[10],s_C__Giants_source_main_dlog_c_00556510,0x1f0);

        piVar1[3] = piVar1[3] & 0xfffffffe;

      }

      piVar1[10] = param_3;

      main_dlog_00427570(param_1,piVar1);

    }

  }

  return;

}

/* ===== main_dlog_004277f0 @ 0x004277F0 ===== */
void main_dlog_004277f0(int *param_1,int param_2,undefined4 param_3)



{

  int *piVar1;

  

  piVar1 = (int *)*param_1;

  if (piVar1 != (int *)0x0) {

    while (piVar1[2] != param_2) {

      piVar1 = (int *)*piVar1;

      if (piVar1 == (int *)0x0) {

        return;

      }

    }

    if (piVar1 != (int *)0x0) {

      if ((*(byte *)(piVar1 + 3) & 1) != 0) {

        mem_free_tagged(piVar1[10],s_C__Giants_source_main_dlog_c_00556510,0x200);

      }

      piVar1[3] = piVar1[3] | 1;

      MemString(8,param_3,piVar1 + 10,s_C__Giants_source_main_dlog_c_00556510,0x203);

      main_dlog_00427570(param_1,piVar1);

    }

  }

  return;

}

/* ===== main_dlog_00427890 @ 0x00427890 ===== */
/* WARNING: Removing unreachable block (ram,0x00427936) */



void main_dlog_00427890(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4

                       ,uint param_5,undefined4 param_6)



{

  undefined4 *puVar1;

  undefined4 *puVar2;

  undefined4 *puVar3;

  undefined4 uVar4;

  int iVar5;

  undefined4 *puVar6;

  

  puVar3 = (undefined4 *)

           FUN_0053a700(8,0x38,s_dlogentry_00556530,s_C__Giants_source_main_dlog_c_00556510,0x176);

  puVar6 = puVar3;

  for (iVar5 = 0xe; iVar5 != 0; iVar5 = iVar5 + -1) {

    *puVar6 = 0;

    puVar6 = puVar6 + 1;

  }

  puVar2 = (undefined4 *)*param_1;

  puVar6 = param_1;

  while (puVar1 = puVar2, puVar1 != (undefined4 *)0x0) {

    puVar6 = puVar1;

    puVar2 = (undefined4 *)*puVar1;

  }

  *puVar6 = puVar3;

  puVar3[1] = 0;

  puVar3[2] = param_2;

  uVar4 = param_6;

  if ((param_5 & 0x2000000) != 0) {

    uVar4 = FUN_00507b00(param_6);

  }

  param_6 = 0x3ccccccd;

  if ((param_5 & 0x1000000) == 0) {

    param_6 = 0x3d000000;

  }

  MemString(8,uVar4,puVar3 + 10,s_C__Giants_source_main_dlog_c_00556510,0x17f);

  puVar3[4] = param_3;

  puVar3[5] = param_4;

  puVar3[0xc] = param_6;

  puVar3[3] = param_5 | 1;

  puVar3[0xd] = 0;

  main_dlog_00427570(param_1,puVar3);

  return;

}

/* ===== main_dlog_00427970 @ 0x00427970 ===== */
void main_dlog_00427970(undefined4 *param_1,float param_2,undefined4 param_3,undefined4 param_4,

                       float param_5,float param_6,undefined4 param_7)



{

  undefined4 *puVar1;

  float fVar2;

  undefined4 uVar3;

  undefined4 *puVar4;

  int iVar5;

  undefined4 *puVar6;

  float10 fVar7;

  float10 fVar8;

  

  fVar2 = param_5;

  uVar3 = param_6;

  if (((uint)param_5 & 0x2000000) != 0) {

    uVar3 = FUN_00507b00(param_6);

  }

  puVar4 = (undefined4 *)

           FUN_0053a700(8,0x38,s_dlogentry_00556530,s_C__Giants_source_main_dlog_c_00556510,0x24b);

  puVar6 = puVar4;

  for (iVar5 = 0xe; iVar5 != 0; iVar5 = iVar5 + -1) {

    *puVar6 = 0;

    puVar6 = puVar6 + 1;

  }

  puVar6 = (undefined4 *)*param_1;

  while (puVar1 = puVar6, puVar1 != (undefined4 *)0x0) {

    param_1 = puVar1;

    puVar6 = (undefined4 *)*puVar1;

  }

  *param_1 = puVar4;

  puVar4[1] = 1;

  puVar4[2] = param_2;

  puVar4[10] = uVar3;

  puVar4[4] = param_3;

  puVar4[5] = param_4;

  if (((uint)fVar2 & 0x1000000) == 0) {

    param_6 = 0.03125;

  }

  else {

    param_6 = 0.025;

  }

  puVar4[0xd] = param_6;

  puVar4[3] = fVar2;

  puVar4[0xc] = 0;

  puVar4[0xb] = param_7;

  fVar7 = (float10)FUN_0051bc00(param_6);

  fVar8 = (float10)FUN_0051BD30(puVar4[0xd],puVar4[10]);

  param_6 = (float)fVar8;

  fVar8 = (float10)FUN_0051BD30(puVar4[0xd],&DAT_005562b8);

  if ((float10)param_6 < fVar8 * (float10)(int)puVar4[0xb]) {

    param_6 = (float)(fVar8 * (float10)(int)puVar4[0xb]);

  }

  main_dlog_004276a0(puVar4[3],puVar4[4],puVar4[5],param_6,(float)fVar7,&param_2,&param_5);

  puVar4[9] = param_5 + (float)fVar7;

  puVar4[6] = param_5;

  puVar4[7] = param_2;

  puVar4[8] = param_2 + param_6;

  return;

}

/* ===== main_dlog_00427bb0 @ 0x00427BB0 ===== */
void main_dlog_00427bb0(undefined4 *param_1,float param_2,float param_3,undefined4 param_4,

                       float param_5,float param_6)



{

  undefined4 *puVar1;

  uint uVar2;

  float fVar3;

  undefined4 uVar4;

  undefined4 *puVar5;

  int iVar6;

  undefined4 *puVar7;

  float10 fVar8;

  float10 fVar9;

  

  uVar2 = (uint)param_5;

  uVar4 = param_6;

  if (((uint)param_5 & 0x2000000) != 0) {

    uVar4 = FUN_00507b00(param_6);

  }

  puVar5 = (undefined4 *)

           FUN_0053a700(8,0x30,s_dlogentry_00556530,s_C__Giants_source_main_dlog_c_00556510,0x32b);

  puVar7 = puVar5;

  for (iVar6 = 0xc; iVar6 != 0; iVar6 = iVar6 + -1) {

    *puVar7 = 0;

    puVar7 = puVar7 + 1;

  }

  puVar7 = (undefined4 *)*param_1;

  while (puVar1 = puVar7, puVar1 != (undefined4 *)0x0) {

    param_1 = puVar1;

    puVar7 = (undefined4 *)*puVar1;

  }

  *param_1 = puVar5;

  puVar5[1] = 2;

  puVar5[2] = param_2;

  puVar7 = puVar5 + 0xb;

  if ((uVar2 & 1) == 0) {

    *puVar7 = uVar4;

  }

  else {

    MemString(8,uVar4,puVar7,s_C__Giants_source_main_dlog_c_00556510,0x330);

  }

  puVar5[4] = param_3;

  puVar5[5] = param_4;

  puVar5[3] = uVar2;

  param_6 = 0.025;

  if ((uVar2 & 0x1000000) == 0) {

    param_6 = 0.03125;

  }

  fVar3 = param_6;

  param_5 = param_6 * 0.128;

  fVar8 = (float10)FUN_0051bc00(param_6);

  fVar9 = (float10)FUN_0051BD30(fVar3,*puVar7);

  param_3 = (float)((float10)param_5 + (float10)param_5 + fVar9 + (float10)0.01);

  main_dlog_004276a0(puVar5[3],puVar5[4],puVar5[5],param_3,(float)fVar8,&param_2,&param_6);

  puVar5[6] = param_6 - param_5;

  puVar5[7] = param_2;

  puVar5[9] = param_6 + (float)fVar8;

  puVar5[8] = param_2 + param_3;

  return;

}

/* ===== main_dlog_00427d00 @ 0x00427D00 ===== */
void main_dlog_00427d00(undefined4 *param_1,float param_2,undefined4 param_3,undefined4 param_4,

                       float param_5,float param_6)



{

  undefined4 *puVar1;

  float fVar2;

  undefined4 *puVar3;

  undefined4 uVar4;

  undefined4 *puVar5;

  int iVar6;

  undefined4 *puVar7;

  float10 fVar8;

  

  fVar2 = param_5;

  uVar4 = param_6;

  if (((uint)param_5 & 0x2000000) != 0) {

    uVar4 = FUN_00507b00(param_6);

  }

  puVar5 = (undefined4 *)

           FUN_0053a700(8,0x30,s_dlogentry_00556530,s_C__Giants_source_main_dlog_c_00556510,0x394);

  puVar7 = puVar5;

  for (iVar6 = 0xc; iVar6 != 0; iVar6 = iVar6 + -1) {

    *puVar7 = 0;

    puVar7 = puVar7 + 1;

  }

  puVar3 = (undefined4 *)*param_1;

  puVar7 = param_1;

  while (puVar1 = puVar3, puVar1 != (undefined4 *)0x0) {

    puVar7 = puVar1;

    puVar3 = (undefined4 *)*puVar1;

  }

  *puVar7 = puVar5;

  puVar5[1] = 4;

  puVar5[2] = param_2;

  puVar5[0xb] = uVar4;

  puVar5[4] = param_3;

  puVar5[5] = param_4;

  puVar5[3] = fVar2;

  param_6 = 0.025;

  if (((uint)fVar2 & 0x1000000) == 0) {

    param_6 = 0.03125;

  }

  uVar4 = param_6;

  fVar8 = (float10)FUN_0051bc00(param_6);

  param_6 = (float)fVar8;

  if (fVar8 < (float10)0.035) {

    param_6 = 0.035;

  }

  fVar8 = (float10)FUN_0051BD30(uVar4,puVar5[0xb]);

  param_2 = (float)(fVar8 + (float10)param_6 + (float10)0.005);

  main_dlog_004276a0(puVar5[3],puVar5[4],puVar5[5],param_2,param_6,&param_1,&param_5);

  puVar5[9] = param_5 + param_6;

  puVar5[6] = param_5;

  puVar5[7] = param_1;

  puVar5[8] = (float)param_1 + param_2;

  return;

}

/* ===== main_dlog_00427e80 @ 0x00427E80 ===== */
void main_dlog_00427e80(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4

                       ,undefined4 param_5)



{

  undefined4 *puVar1;

  undefined4 *puVar2;

  undefined4 *puVar3;

  int iVar4;

  undefined4 *puVar5;

  

  puVar3 = (undefined4 *)

           FUN_0053a700(8,0x40,s_dlogentry_00556530,s_C__Giants_source_main_dlog_c_00556510,0x3f8);

  puVar5 = puVar3;

  for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {

    *puVar5 = 0;

    puVar5 = puVar5 + 1;

  }

  puVar2 = (undefined4 *)*param_1;

  puVar5 = param_1;

  while (puVar1 = puVar2, puVar1 != (undefined4 *)0x0) {

    puVar5 = puVar1;

    puVar2 = (undefined4 *)*puVar1;

  }

  *puVar5 = puVar3;

  puVar3[2] = param_2;

  puVar3[4] = param_3;

  puVar3[1] = 3;

  puVar3[5] = param_4;

  puVar3[3] = param_5;

  puVar3[0xd] = 0;

  puVar3[0xc] = 0;

  main_dlog_00427f00(param_1,puVar3);

  return;

}

/* ===== main_dlog_00428080 @ 0x00428080 ===== */
void main_dlog_00428080(int *param_1,int param_2,int param_3,char *param_4)



{

  char cVar1;

  undefined4 uVar2;

  undefined4 *puVar3;

  undefined4 *puVar4;

  undefined4 *puVar5;

  uint uVar6;

  int iVar7;

  char *pcVar8;

  

  param_1 = (int *)*param_1;

  if (param_1 != (int *)0x0) {

    while (param_1[2] != param_2) {

      param_1 = (int *)*param_1;

      if (param_1 == (int *)0x0) {

        return;

      }

    }

    if (param_1 != (int *)0x0) {

      puVar3 = (undefined4 *)0x0;

      puVar4 = (undefined4 *)param_1[10];

      for (; param_3 != 0; param_3 = param_3 + -1) {

        puVar3 = puVar4;

        puVar4 = (undefined4 *)*puVar4;

      }

      uVar6 = 0xffffffff;

      pcVar8 = param_4;

      do {

        if (uVar6 == 0) break;

        uVar6 = uVar6 - 1;

        cVar1 = *pcVar8;

        pcVar8 = pcVar8 + 1;

      } while (cVar1 != '\0');

      puVar5 = (undefined4 *)

               FUN_0053a700(8,~uVar6 + 0x13,&DAT_0055653c,s_C__Giants_source_main_dlog_c_00556510,

                            0x448);

      if (puVar3 == (undefined4 *)0x0) {

        param_1[10] = (int)puVar5;

      }

      else {

        *puVar3 = puVar5;

      }

      *puVar5 = *puVar4;

      puVar5[1] = puVar4[1];

      uVar2 = puVar4[2];

      puVar5[3] = puVar5 + 4;

      puVar5[2] = uVar2;

      iVar7 = (int)(puVar5 + 4) - (int)param_4;

      do {

        cVar1 = *param_4;

        param_4[iVar7] = cVar1;

        param_4 = param_4 + 1;

      } while (cVar1 != '\0');

      param_1[3] = param_1[3] | 0x200;

      mem_free_tagged(puVar4,s_C__Giants_source_main_dlog_c_00556510,0x457);

    }

  }

  return;

}

/* ===== main_dlog_00428140 @ 0x00428140 ===== */
void main_dlog_00428140(int *param_1,int param_2,char *param_3,undefined4 param_4)



{

  char cVar1;

  int *piVar2;

  int *piVar3;

  int *piVar4;

  undefined4 *puVar5;

  uint uVar6;

  int iVar7;

  char *pcVar8;

  

  param_1 = (int *)*param_1;

  if (param_1 != (int *)0x0) {

    while (param_1[2] != param_2) {

      param_1 = (int *)*param_1;

      if (param_1 == (int *)0x0) {

        return;

      }

    }

    if (param_1 != (int *)0x0) {

      piVar4 = (int *)param_1[10];

      piVar3 = param_1 + 10;

      while (piVar2 = piVar4, piVar2 != (int *)0x0) {

        piVar3 = piVar2;

        piVar4 = (int *)*piVar2;

      }

      uVar6 = 0xffffffff;

      pcVar8 = param_3;

      do {

        if (uVar6 == 0) break;

        uVar6 = uVar6 - 1;

        cVar1 = *pcVar8;

        pcVar8 = pcVar8 + 1;

      } while (cVar1 != '\0');

      puVar5 = (undefined4 *)

               FUN_0053a700(8,~uVar6 + 0x13,&DAT_0055653c,s_C__Giants_source_main_dlog_c_00556510,

                            0x466);

      *piVar3 = (int)puVar5;

      puVar5[1] = param_4;

      *puVar5 = 0;

      puVar5[3] = puVar5 + 4;

      puVar5[2] = 0;

      iVar7 = (int)(puVar5 + 4) - (int)param_3;

      do {

        cVar1 = *param_3;

        param_3[iVar7] = cVar1;

        param_3 = param_3 + 1;

      } while (cVar1 != '\0');

      param_1[3] = param_1[3] | 0x200;

    }

  }

  return;

}

/* ===== main_dlog_004281f0 @ 0x004281F0 ===== */
void main_dlog_004281f0(int *param_1,int param_2,char *param_3)



{

  char cVar1;

  int *piVar2;

  int *piVar3;

  int *piVar4;

  undefined4 *puVar5;

  uint uVar6;

  int iVar7;

  char *pcVar8;

  

  param_1 = (int *)*param_1;

  if (param_1 != (int *)0x0) {

    while (param_1[2] != param_2) {

      param_1 = (int *)*param_1;

      if (param_1 == (int *)0x0) {

        return;

      }

    }

    if (param_1 != (int *)0x0) {

      piVar4 = (int *)param_1[10];

      piVar3 = param_1 + 10;

      while (piVar2 = piVar4, piVar2 != (int *)0x0) {

        piVar3 = piVar2;

        piVar4 = (int *)*piVar2;

      }

      uVar6 = 0xffffffff;

      pcVar8 = param_3;

      do {

        if (uVar6 == 0) break;

        uVar6 = uVar6 - 1;

        cVar1 = *pcVar8;

        pcVar8 = pcVar8 + 1;

      } while (cVar1 != '\0');

      puVar5 = (undefined4 *)

               FUN_0053a700(8,~uVar6 + 0x13,&DAT_0055653c,s_C__Giants_source_main_dlog_c_00556510,

                            0x466);

      *piVar3 = (int)puVar5;

      *puVar5 = 0;

      puVar5[1] = 0;

      puVar5[2] = 0;

      puVar5[3] = puVar5 + 4;

      iVar7 = (int)(puVar5 + 4) - (int)param_3;

      do {

        cVar1 = *param_3;

        param_3[iVar7] = cVar1;

        param_3 = param_3 + 1;

      } while (cVar1 != '\0');

      param_1[3] = param_1[3] | 0x200;

    }

  }

  return;

}

/* ===== main_dlog_00428290 @ 0x00428290 ===== */
void main_dlog_00428290(int *param_1,int param_2,undefined4 param_3,undefined4 param_4)



{

  char cVar1;

  int *piVar2;

  int *piVar3;

  int *piVar4;

  char *pcVar5;

  undefined4 *puVar6;

  uint uVar7;

  int iVar8;

  char *pcVar9;

  

  pcVar5 = (char *)FUN_00507b00(param_3);

  param_1 = (int *)*param_1;

  if (param_1 != (int *)0x0) {

    while (param_1[2] != param_2) {

      param_1 = (int *)*param_1;

      if (param_1 == (int *)0x0) {

        return;

      }

    }

    if (param_1 != (int *)0x0) {

      piVar4 = (int *)param_1[10];

      piVar3 = param_1 + 10;

      while (piVar2 = piVar4, piVar2 != (int *)0x0) {

        piVar3 = piVar2;

        piVar4 = (int *)*piVar2;

      }

      uVar7 = 0xffffffff;

      pcVar9 = pcVar5;

      do {

        if (uVar7 == 0) break;

        uVar7 = uVar7 - 1;

        cVar1 = *pcVar9;

        pcVar9 = pcVar9 + 1;

      } while (cVar1 != '\0');

      puVar6 = (undefined4 *)

               FUN_0053a700(8,~uVar7 + 0x13,&DAT_0055653c,s_C__Giants_source_main_dlog_c_00556510,

                            0x466);

      *piVar3 = (int)puVar6;

      puVar6[1] = param_4;

      *puVar6 = 0;

      puVar6[3] = puVar6 + 4;

      puVar6[2] = 0;

      iVar8 = (int)(puVar6 + 4) - (int)pcVar5;

      do {

        cVar1 = *pcVar5;

        pcVar5[iVar8] = cVar1;

        pcVar5 = pcVar5 + 1;

      } while (cVar1 != '\0');

      param_1[3] = param_1[3] | 0x200;

    }

  }

  return;

}

/* ===== main_dlog_00428340 @ 0x00428340 ===== */
void main_dlog_00428340(int *param_1,int param_2,undefined4 param_3)



{

  char cVar1;

  int *piVar2;

  int *piVar3;

  int *piVar4;

  char *pcVar5;

  undefined4 *puVar6;

  uint uVar7;

  int iVar8;

  char *pcVar9;

  

  pcVar5 = (char *)FUN_00507b00(param_3);

  param_1 = (int *)*param_1;

  if (param_1 != (int *)0x0) {

    while (param_1[2] != param_2) {

      param_1 = (int *)*param_1;

      if (param_1 == (int *)0x0) {

        return;

      }

    }

    if (param_1 != (int *)0x0) {

      piVar4 = (int *)param_1[10];

      piVar3 = param_1 + 10;

      while (piVar2 = piVar4, piVar2 != (int *)0x0) {

        piVar3 = piVar2;

        piVar4 = (int *)*piVar2;

      }

      uVar7 = 0xffffffff;

      pcVar9 = pcVar5;

      do {

        if (uVar7 == 0) break;

        uVar7 = uVar7 - 1;

        cVar1 = *pcVar9;

        pcVar9 = pcVar9 + 1;

      } while (cVar1 != '\0');

      puVar6 = (undefined4 *)

               FUN_0053a700(8,~uVar7 + 0x13,&DAT_0055653c,s_C__Giants_source_main_dlog_c_00556510,

                            0x466);

      *piVar3 = (int)puVar6;

      *puVar6 = 0;

      puVar6[1] = 0;

      puVar6[2] = 0;

      puVar6[3] = puVar6 + 4;

      iVar8 = (int)(puVar6 + 4) - (int)pcVar5;

      do {

        cVar1 = *pcVar5;

        pcVar5[iVar8] = cVar1;

        pcVar5 = pcVar5 + 1;

      } while (cVar1 != '\0');

      param_1[3] = param_1[3] | 0x200;

    }

  }

  return;

}

/* ===== main_dlog_004283f0 @ 0x004283F0 ===== */
void main_dlog_004283f0(int *param_1,int param_2)



{

  undefined4 *puVar1;

  undefined4 *puVar2;

  

  param_1 = (int *)*param_1;

  if (param_1 != (int *)0x0) {

    while (param_1[2] != param_2) {

      param_1 = (int *)*param_1;

      if (param_1 == (int *)0x0) {

        return;

      }

    }

    if (param_1 != (int *)0x0) {

      puVar2 = (undefined4 *)param_1[10];

      while (puVar2 != (undefined4 *)0x0) {

        puVar1 = (undefined4 *)*puVar2;

        mem_free_tagged(puVar2,s_C__Giants_source_main_dlog_c_00556510,0x48c);

        puVar2 = puVar1;

      }

      param_1[10] = 0;

      param_1[0xb] = 0;

      param_1[3] = param_1[3] | 0x200;

    }

  }

  return;

}

/* ===== main_dlog_004286c0 @ 0x004286C0 ===== */
void main_dlog_004286c0(int *param_1,int param_2,int param_3,char *param_4)



{

  char cVar1;

  int *piVar2;

  int *piVar3;

  int *piVar4;

  undefined4 *puVar5;

  int iVar6;

  uint uVar7;

  uint uVar8;

  char *pcVar9;

  undefined4 *puVar10;

  char *pcVar11;

  undefined4 *puVar12;

  

  param_1 = (int *)*param_1;

  if (param_1 != (int *)0x0) {

    while (param_1[2] != param_2) {

      param_1 = (int *)*param_1;

      if (param_1 == (int *)0x0) {

        return;

      }

    }

    if (param_1 != (int *)0x0) {

      piVar4 = (int *)param_1[10];

      piVar3 = param_1 + 10;

      for (iVar6 = 0; (piVar2 = piVar4, piVar2 != (int *)0x0 && (iVar6 != param_3));

          iVar6 = iVar6 + 1) {

        piVar4 = (int *)*piVar2;

        piVar3 = piVar2;

      }

      if (*piVar3 != 0) {

        pcVar9 = (char *)(*piVar3 + 0x10);

        uVar7 = 0xffffffff;

        pcVar11 = pcVar9;

        do {

          if (uVar7 == 0) break;

          uVar7 = uVar7 - 1;

          cVar1 = *pcVar11;

          pcVar11 = pcVar11 + 1;

        } while (cVar1 != '\0');

        uVar8 = 0xffffffff;

        pcVar11 = param_4;

        do {

          if (uVar8 == 0) break;

          uVar8 = uVar8 - 1;

          cVar1 = *pcVar11;

          pcVar11 = pcVar11 + 1;

        } while (cVar1 != '\0');

        if (~uVar8 - 1 <= ~uVar7 - 1) {

          do {

            cVar1 = *param_4;

            param_4 = param_4 + 1;

            *pcVar9 = cVar1;

            pcVar9 = pcVar9 + 1;

          } while (cVar1 != '\0');

          return;

        }

        uVar7 = 0xffffffff;

        pcVar11 = param_4;

        do {

          if (uVar7 == 0) break;

          uVar7 = uVar7 - 1;

          cVar1 = *pcVar11;

          pcVar11 = pcVar11 + 1;

        } while (cVar1 != '\0');

        puVar5 = (undefined4 *)

                 FUN_0053a700(8,~uVar7 + 0x13,&DAT_0055653c,s_C__Giants_source_main_dlog_c_00556510,

                              0x655);

        puVar10 = (undefined4 *)*piVar3;

        puVar12 = puVar5;

        for (iVar6 = 5; iVar6 != 0; iVar6 = iVar6 + -1) {

          *puVar12 = *puVar10;

          puVar10 = puVar10 + 1;

          puVar12 = puVar12 + 1;

        }

        mem_free_tagged(*piVar3,s_C__Giants_source_main_dlog_c_00556510,0x657);

        *piVar3 = (int)puVar5;

        iVar6 = (int)(puVar5 + 4) - (int)param_4;

        do {

          cVar1 = *param_4;

          param_4[iVar6] = cVar1;

          param_4 = param_4 + 1;

        } while (cVar1 != '\0');

        puVar5[3] = puVar5 + 4;

      }

    }

  }

  return;

}

