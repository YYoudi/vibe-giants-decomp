/* Giants 1.449 — module Utils/hash
 * 6 functions (6 named) — decompiled, names from PS2 symbols
 * Original source: C:\Giants\source\Utils/hash.c(pp) (assert-string evidence)
 */

/* ===== utils_hash_005391c0 @ 0x005391C0 ===== */
undefined4 * utils_hash_005391c0(int param_1,int param_2,uint param_3)



{

  undefined4 *puVar1;

  uint uVar2;

  int iVar3;

  undefined4 *puVar4;

  

  uVar2 = param_1 * 4 + 0x14;

  puVar1 = (undefined4 *)

           FUN_0053a700(0x1f,uVar2,s_hashtab_00580468,s_C__Giants_source_Utils_hash_c_00580470,0x1d)

  ;

  puVar4 = puVar1;

  for (uVar2 = uVar2 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {

    *puVar4 = 0;

    puVar4 = puVar4 + 1;

  }

  for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {

    *(undefined1 *)puVar4 = 0;

    puVar4 = (undefined4 *)((int)puVar4 + 1);

  }

  puVar1[3] = param_1;

  puVar1[2] = param_2 + 4;

  puVar1[4] = param_3;

  if ((param_3 & 1) != 0) {

    puVar1[2] = param_2 + 8;

    return puVar1;

  }

  puVar1[2] = param_2 + 5;

  return puVar1;

}

/* ===== utils_hash_00539230 @ 0x00539230 ===== */
int * utils_hash_00539230(int *param_1,char *param_2)



{

  char cVar1;

  undefined4 *puVar2;

  uint uVar3;

  int iVar4;

  int *piVar5;

  int iVar6;

  uint uVar7;

  int *piVar8;

  char *pcVar9;

  uint *puVar10;

  uint local_40 [16];

  

  puVar10 = local_40;

  for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {

    *puVar10 = 0;

    puVar10 = puVar10 + 1;

  }

  _strncpy((char *)local_40,param_2,0x40);

  uVar3 = 0;

  uVar7 = 0;

  do {

    uVar3 = uVar3 + (local_40[uVar7] & 0xdfdfdfdf);

    uVar7 = uVar7 + 1;

  } while (uVar7 < 0x10);

  iVar6 = (int)((longlong)(ulonglong)(uVar3 & 0x7fffffff) % (longlong)param_1[3]);

  for (puVar2 = (undefined4 *)param_1[iVar6 + 5]; puVar2 != (undefined4 *)0x0;

      puVar2 = (undefined4 *)*puVar2) {

    if ((*(byte *)(param_1 + 4) & 1) == 0) {

      iVar4 = param_1[2] + -1 + (int)puVar2;

    }

    else {

      iVar4 = *(int *)(param_1[2] + -4 + (int)puVar2);

    }

    iVar4 = FUN_00545650(param_2,iVar4);

    if (iVar4 == 0) {

      if (puVar2 != (undefined4 *)0x0) {

        return (int *)0x0;

      }

      break;

    }

  }

  if ((*(byte *)(param_1 + 4) & 1) == 0) {

    uVar3 = 0xffffffff;

    pcVar9 = param_2;

    do {

      if (uVar3 == 0) break;

      uVar3 = uVar3 - 1;

      cVar1 = *pcVar9;

      pcVar9 = pcVar9 + 1;

    } while (cVar1 != '\0');

    uVar3 = (~uVar3 - 1) + param_1[2];

    if (param_1[1] < (int)uVar3) {

      piVar5 = (int *)FUN_0053a700(0x1f,0x1fab,&DAT_00580490,

                                   s_C__Giants_source_Utils_hash_c_00580470,0x10e);

      *piVar5 = *param_1;

      *param_1 = (int)piVar5;

      param_1[1] = 0x1fa4;

    }

    piVar8 = (int *)((*param_1 - param_1[1]) + 0x1fa8);

    param_1[1] = param_1[1] - uVar3;

    piVar5 = piVar8;

    for (uVar7 = uVar3 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {

      *piVar5 = 0;

      piVar5 = piVar5 + 1;

    }

    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {

      *(undefined1 *)piVar5 = 0;

      piVar5 = (int *)((int)piVar5 + 1);

    }

    pcVar9 = (char *)(param_1[2] + -1 + (int)piVar8);

    do {

      cVar1 = *param_2;

      param_2 = param_2 + 1;

      *pcVar9 = cVar1;

      pcVar9 = pcVar9 + 1;

    } while (cVar1 != '\0');

  }

  else {

    uVar3 = param_1[2];

    if (param_1[1] < (int)uVar3) {

      piVar5 = (int *)FUN_0053a700(0x1f,0x1fab,&DAT_00580490,

                                   s_C__Giants_source_Utils_hash_c_00580470,0x10e);

      *piVar5 = *param_1;

      *param_1 = (int)piVar5;

      param_1[1] = 0x1fa4;

    }

    piVar8 = (int *)((*param_1 - param_1[1]) + 0x1fa8);

    param_1[1] = param_1[1] - uVar3;

    piVar5 = piVar8;

    for (uVar7 = uVar3 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {

      *piVar5 = 0;

      piVar5 = piVar5 + 1;

    }

    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {

      *(undefined1 *)piVar5 = 0;

      piVar5 = (int *)((int)piVar5 + 1);

    }

    *(char **)(param_1[2] + -4 + (int)piVar8) = param_2;

  }

  *piVar8 = param_1[iVar6 + 5];

  param_1[iVar6 + 5] = (int)piVar8;

  return piVar8;

}

/* ===== utils_hash_00539470 @ 0x00539470 ===== */
void utils_hash_00539470(undefined4 *param_1)



{

  undefined4 *puVar1;

  undefined4 *puVar2;

  

  puVar2 = (undefined4 *)*param_1;

  while (puVar2 != (undefined4 *)0x0) {

    puVar1 = (undefined4 *)*puVar2;

    mem_free_tagged(puVar2,s_C__Giants_source_Utils_hash_c_00580470,0x123);

    puVar2 = puVar1;

  }

  *param_1 = 0;

  param_1[1] = 0;

  mem_free_tagged(param_1,s_C__Giants_source_Utils_hash_c_00580470,0xc0);

  return;

}

/* ===== utils_hash_005394c0 @ 0x005394C0 ===== */
void utils_hash_005394c0(int param_1)



{

  undefined4 *puVar1;

  

  puVar1 = (undefined4 *)

           FUN_0053a700(0x1f,0x10,s_linktab_00580498,s_C__Giants_source_Utils_hash_c_00580470,0xce);

  *puVar1 = 0;

  puVar1[1] = 0;

  puVar1[2] = 0;

  puVar1[3] = 0;

  puVar1[2] = param_1 + 5;

  return;

}

/* ===== utils_hash_00539500 @ 0x00539500 ===== */
int * utils_hash_00539500(int *param_1,char *param_2)



{

  char cVar1;

  int *piVar2;

  uint uVar3;

  uint uVar4;

  int iVar5;

  int *piVar6;

  char *pcVar7;

  

  uVar3 = 0xffffffff;

  pcVar7 = param_2;

  do {

    if (uVar3 == 0) break;

    uVar3 = uVar3 - 1;

    cVar1 = *pcVar7;

    pcVar7 = pcVar7 + 1;

  } while (cVar1 != '\0');

  uVar3 = (~uVar3 - 1) + param_1[2];

  if (param_1[1] < (int)uVar3) {

    piVar2 = (int *)FUN_0053a700(0x1f,0x1fab,&DAT_00580490,s_C__Giants_source_Utils_hash_c_00580470,

                                 0x10e);

    *piVar2 = *param_1;

    *param_1 = (int)piVar2;

    param_1[1] = 0x1fa4;

  }

  iVar5 = *param_1 - param_1[1];

  piVar6 = (int *)(iVar5 + 0x1fa8);

  param_1[1] = param_1[1] - uVar3;

  piVar2 = piVar6;

  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {

    *piVar2 = 0;

    piVar2 = piVar2 + 1;

  }

  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {

    *(undefined1 *)piVar2 = 0;

    piVar2 = (int *)((int)piVar2 + 1);

  }

  pcVar7 = (char *)(iVar5 + 0x1fa7 + param_1[2]);

  do {

    cVar1 = *param_2;

    param_2 = param_2 + 1;

    *pcVar7 = cVar1;

    pcVar7 = pcVar7 + 1;

  } while (cVar1 != '\0');

  *piVar6 = param_1[3];

  param_1[3] = (int)piVar6;

  return piVar6;

}

/* ===== utils_hash_005395a0 @ 0x005395A0 ===== */
void utils_hash_005395a0(undefined4 *param_1)



{

  undefined4 *puVar1;

  undefined4 *puVar2;

  

  puVar2 = (undefined4 *)*param_1;

  while (puVar2 != (undefined4 *)0x0) {

    puVar1 = (undefined4 *)*puVar2;

    mem_free_tagged(puVar2,s_C__Giants_source_Utils_hash_c_00580470,0x123);

    puVar2 = puVar1;

  }

  *param_1 = 0;

  param_1[1] = 0;

  mem_free_tagged(param_1,s_C__Giants_source_Utils_hash_c_00580470,0xef);

  return;

}

