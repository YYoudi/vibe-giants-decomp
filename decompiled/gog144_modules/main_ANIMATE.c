/* Giants 1.449 — module main/ANIMATE
 * 8 functions (0 named) — decompiled, names from PS2 symbols
 * Original source: C:\Giants\source\main/ANIMATE.c(pp) (assert-string evidence)
 */

/* ===== FUN_00404b60 @ 0x00404B60 ===== */
void FUN_00404b60(int param_1,int param_2)



{

  int iVar1;

  undefined4 uVar2;

  int iVar3;

  int iVar4;

  int local_70;

  undefined4 local_6c;

  undefined4 local_60;

  

  if (*(int *)(param_1 + 8) == 0) {

    return;

  }

  iVar1 = *(int *)(*(int *)(param_1 + 8) + 0x400);

  if (*(int *)(iVar1 + 0x34) == 0) {

    return;

  }

  if (*(int *)(iVar1 + 0x6c) == 0) {

    return;

  }

  if (param_2 < 0) {

    param_2 = FUN_0042b160(param_1);

  }

  iVar1 = *(int *)(*(int *)(param_1 + 8) + 0x400 + param_2 * 4);

  if (iVar1 == 0) {

    __rt_error_box(s_this_had_better_not_be_null____N_00554100,

                   s_C__Giants_source_main_ANIMATE_CP_00554124,0x3d8);

  }

  uVar2 = *(undefined4 *)(iVar1 + 0x14);

  iVar3 = FUN_00403a70(param_1,param_2,&local_70);

  iVar4 = FUN_004469e0();

  if (iVar4 == 0) {

    if (*(int *)(param_1 + 0xc) == *(int *)(iVar1 + 100)) {

      return;

    }

    *(int *)(iVar1 + 100) = *(int *)(param_1 + 0xc);

    if ((iVar3 == 1) && ((~*(uint *)(local_70 + 8) & 2) != 0)) {

      if ((*(float *)(iVar1 + 0x5c) == *(float *)(param_1 + 0x14)) &&

         (*(int *)(iVar1 + 0x60) == *(int *)(param_1 + 0x10))) {

        return;

      }

      *(undefined4 *)(iVar1 + 0x5c) = *(undefined4 *)(param_1 + 0x14);

      *(undefined4 *)(iVar1 + 0x60) = *(undefined4 *)(param_1 + 0x10);

      goto LAB_00404c65;

    }

  }

  else {

    *(undefined4 *)(iVar1 + 100) = 0;

  }

  *(undefined4 *)(iVar1 + 0x5c) = 0xbf800000;

  if (1 < iVar3) {

    FUN_0053d330(&local_70,iVar3,uVar2,0xc,*(undefined4 *)(param_1 + 0xc));

    return;

  }

  if (iVar3 == 0) {

    return;

  }

LAB_00404c65:

  FUN_0053d2d0(local_6c,local_60,uVar2,0xc,*(undefined4 *)(param_1 + 0xc));

  return;

}

/* ===== FUN_004050d0 @ 0x004050D0 ===== */
float * FUN_004050d0(float param_1)



{

  int iVar1;

  float *pfVar2;

  int iVar3;

  float *pfVar4;

  

  pfVar2 = (float *)FUN_0053a700(2,0x58,&DAT_005541e0,s_C__Giants_source_main_ANIMATE_CP_00554124,

                                 0x517);

  pfVar4 = pfVar2;

  for (iVar3 = 0x16; iVar3 != 0; iVar3 = iVar3 + -1) {

    *pfVar4 = 0.0;

    pfVar4 = pfVar4 + 1;

  }

  pfVar2[10] = param_1;

  iVar3 = *(int *)((int)param_1 + 0x1c);

  iVar1 = *(int *)((int)param_1 + 0x18);

  pfVar2[1] = *(float *)((int)param_1 + 0x10);

  *pfVar2 = (float)(*(int *)((int)param_1 + 0x14) - *(int *)((int)param_1 + 0x10)) *

            ((1.0 / (float)iVar3) / (float)iVar1);

  return pfVar2;

}

/* ===== FUN_00405130 @ 0x00405130 ===== */
void FUN_00405130(undefined4 *param_1,int *param_2)



{

  int iVar1;

  int *piVar2;

  int iVar3;

  int iVar4;

  undefined4 uVar5;

  int iVar6;

  undefined1 local_4 [4];

  

  piVar2 = param_2;

  iVar3 = FUN_00538540(param_2);

  if (iVar3 != 0) {

    vfs_fileread_load(piVar2,&param_2,local_4);

    piVar2 = param_2;

    DAT_005841a0 = DAT_005841a0 + *param_2;

    iVar3 = FUN_0053bc90(0,0,param_2);

    param_1[0x1b] = iVar3;

    param_1[0x1c] = piVar2;

    if (iVar3 != 0) {

      iVar6 = 0;

      iVar4 = FUN_0053bda0(iVar3,0,0);

      iVar1 = 1;

      while (iVar4 != 0) {

        iVar6 = iVar6 + *(int *)(iVar4 + 0xc);

        iVar4 = FUN_0053bda0(iVar3,0,iVar1);

        iVar1 = iVar1 + 1;

      }

      if (iVar6 != param_1[4]) {

        FUN_00542f27(&DAT_00657400,s_GTS_Skin_Mismatch__type__d_gtsv___00554230,*param_1,param_1[4],

                     iVar6,iVar3 + 0x28);

        FUN_00425eb0(&DAT_00657400);

        FUN_0051ea20(&DAT_00657400);

        if ((int)param_1[4] < iVar6) {

          param_1[4] = iVar6;

          uVar5 = FUN_0053a700(2,iVar6 * 0xc,s_newverts_00554224,

                               s_C__Giants_source_main_ANIMATE_CP_00554124,0x55e);

          mem_free_tagged(param_1[5],s_C__Giants_source_main_ANIMATE_CP_00554124,0x55f);

          param_1[5] = uVar5;

        }

      }

    }

  }

  return;

}

/* ===== FUN_00405240 @ 0x00405240 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_00405240(char *param_1)



{

  int iVar1;

  char cVar2;

  char *pcVar3;

  int iVar4;

  float fVar5;

  undefined4 *puVar6;

  int *piVar7;

  float *pfVar8;

  uint uVar9;

  char *pcVar10;

  float *pfVar11;

  undefined4 local_4;

  

  pcVar3 = param_1;

  for (puVar6 = DAT_005841a4; puVar6 != (undefined4 *)0x0; puVar6 = (undefined4 *)*puVar6) {

    iVar4 = FUN_0053a860(pcVar3,puVar6 + 3);

    if (iVar4 != 0) {

      puVar6[2] = puVar6[2] + 1;

      fVar5 = (float)puVar6[1];

      if (fVar5 != 0.0) goto LAB_0040534a;

      break;

    }

  }

  vfs_fileread_load(pcVar3,&local_4,&param_1);

  if (param_1 != (char *)0x0) {

    fVar5 = (float)FUN_0053ba50(0,0,local_4);

    uVar9 = 0xffffffff;

    pcVar10 = pcVar3;

    do {

      if (uVar9 == 0) break;

      uVar9 = uVar9 - 1;

      cVar2 = *pcVar10;

      pcVar10 = pcVar10 + 1;

    } while (cVar2 != '\0');

    puVar6 = (undefined4 *)

             FUN_0053a700(2,~uVar9 + 0xf,&PTR_DAT_00554220,

                          s_C__Giants_source_main_ANIMATE_CP_00554124,0x5d3);

    *puVar6 = DAT_005841a4;

    DAT_005841a4 = puVar6;

    puVar6[1] = fVar5;

    pcVar10 = pcVar3;

    do {

      cVar2 = *pcVar10;

      pcVar10[(int)puVar6 + (0xc - (int)pcVar3)] = cVar2;

      pcVar10 = pcVar10 + 1;

    } while (cVar2 != '\0');

    puVar6[2] = 1;

    piVar7 = (int *)FUN_0053bb30(fVar5);

    DAT_0058419c = DAT_0058419c + *piVar7;

    if (fVar5 != 0.0) {

LAB_0040534a:

      pfVar8 = (float *)FUN_0053a700(2,0x58,&DAT_005541e0,

                                     s_C__Giants_source_main_ANIMATE_CP_00554124,0x517);

      pfVar11 = pfVar8;

      for (iVar4 = 0x16; iVar4 != 0; iVar4 = iVar4 + -1) {

        *pfVar11 = 0.0;

        pfVar11 = pfVar11 + 1;

      }

      pfVar8[10] = fVar5;

      iVar4 = *(int *)((int)fVar5 + 0x1c);

      iVar1 = *(int *)((int)fVar5 + 0x18);

      pfVar8[1] = *(float *)((int)fVar5 + 0x10);

      *pfVar8 = (float)(*(int *)((int)fVar5 + 0x14) - *(int *)((int)fVar5 + 0x10)) *

                ((1.0 / (float)iVar4) / (float)iVar1);

      pfVar8[2] = (float)((uint)pfVar8[2] | 1);

      return;

    }

  }

  FUN_00542f27(&DAT_00657400,s_AnimationCreateF_read_animdata_z_005541e8,pcVar3);

  FUN_00425eb0(&DAT_00657400);

  FUN_0051ea20(&DAT_00657400);

  _DAT_00000008 = _DAT_00000008 | 1;

  return;

}

/* ===== FUN_004053b0 @ 0x004053B0 ===== */
void FUN_004053b0(undefined4 *param_1,int param_2,char *param_3)



{

  int iVar1;

  char cVar2;

  undefined4 *puVar3;

  int iVar4;

  float fVar5;

  undefined4 *puVar6;

  int *piVar7;

  uint uVar8;

  char *pcVar9;

  float *pfVar10;

  char *pcVar11;

  float *pfVar12;

  int local_c;

  int local_8;

  int *local_4;

  

  pcVar11 = param_3;

  puVar3 = param_1;

  local_4 = param_1 + 0x100;

  if (*local_4 == 0) {

    FUN_00542f27(&DAT_00657400,s_LOD_not_defined_for_ObjSet__d_fo_005542f0,*param_1,param_2);

    FUN_0051ea20(&DAT_00657400);

    return;

  }

  puVar6 = DAT_005841a4;

  if (*(int *)(*local_4 + 0x6c) != 0) {

    for (; pcVar9 = param_3, param_3 = pcVar9, puVar6 != (undefined4 *)0x0;

        puVar6 = (undefined4 *)*puVar6) {

      iVar4 = FUN_0053a860(pcVar9,puVar6 + 3);

      pcVar11 = pcVar9;

      if (iVar4 != 0) {

        puVar6[2] = puVar6[2] + 1;

        fVar5 = (float)puVar6[1];

        if (fVar5 != 0.0) goto LAB_0040552c;

        break;

      }

    }

    vfs_fileread_load(pcVar11,&local_8,&local_c);

    if (local_c != 0) {

      fVar5 = (float)FUN_0053ba50(0,0,local_8);

      uVar8 = 0xffffffff;

      pcVar9 = pcVar11;

      do {

        if (uVar8 == 0) break;

        uVar8 = uVar8 - 1;

        cVar2 = *pcVar9;

        pcVar9 = pcVar9 + 1;

      } while (cVar2 != '\0');

      puVar6 = (undefined4 *)

               FUN_0053a700(2,~uVar8 + 0xf,&PTR_DAT_00554220,

                            s_C__Giants_source_main_ANIMATE_CP_00554124,0x5d3);

      *puVar6 = DAT_005841a4;

      DAT_005841a4 = puVar6;

      puVar6[1] = fVar5;

      pcVar9 = pcVar11;

      do {

        cVar2 = *pcVar9;

        pcVar9[(int)puVar6 + (0xc - (int)pcVar11)] = cVar2;

        pcVar9 = pcVar9 + 1;

      } while (cVar2 != '\0');

      puVar6[2] = 1;

      piVar7 = (int *)FUN_0053bb30(fVar5);

      DAT_0058419c = DAT_0058419c + *piVar7;

      if (fVar5 != 0.0) {

LAB_0040552c:

        pfVar10 = (float *)FUN_0053a700(2,0x58,&DAT_005541e0,

                                        s_C__Giants_source_main_ANIMATE_CP_00554124,0x517);

        pfVar12 = pfVar10;

        for (iVar4 = 0x16; iVar4 != 0; iVar4 = iVar4 + -1) {

          *pfVar12 = 0.0;

          pfVar12 = pfVar12 + 1;

        }

        pfVar10[10] = fVar5;

        iVar4 = *(int *)((int)fVar5 + 0x1c);

        iVar1 = *(int *)((int)fVar5 + 0x18);

        pfVar10[1] = *(float *)((int)fVar5 + 0x10);

        local_8 = *(int *)((int)fVar5 + 0x14) - *(int *)((int)fVar5 + 0x10);

        *pfVar10 = (float)local_8 * ((1.0 / (float)iVar4) / (float)iVar1);

        iVar4 = 0;

        pfVar12 = pfVar10 + 0xb;

        piVar7 = local_4;

        do {

          if (*piVar7 == 0) {

LAB_004056ea:

            param_1[param_2 + 2] = pfVar10;

            return;

          }

          iVar1 = *(int *)(*piVar7 + 0x6c);

          if (iVar1 == 0) {

            FUN_00542f27(&DAT_00657400,s_Failed_to_create_animation__miss_00554270,param_3,*param_1,

                         iVar4);

            FUN_00425eb0(&DAT_00657400);

            goto LAB_004056ea;

          }

          fVar5 = (float)FUN_0053d1c0(pfVar10[10],0,iVar1,0);

          *pfVar12 = fVar5;

          iVar4 = iVar4 + 1;

          piVar7 = piVar7 + 1;

          pfVar12 = pfVar12 + 1;

          if (9 < iVar4) {

            param_1[param_2 + 2] = pfVar10;

            return;

          }

        } while( true );

      }

    }

    FUN_00542f27(&DAT_00657400,s_AnimationCreateF_read_animdata_z_005541e8,pcVar11);

    FUN_00425eb0(&DAT_00657400);

    FUN_0051ea20(&DAT_00657400);

    FUN_00542f27(&DAT_00657400,s_Failed_to_create_animation___s___005542c0,pcVar11,*puVar3);

    FUN_00425eb0(&DAT_00657400);

    return;

  }

  for (; puVar6 != (undefined4 *)0x0; puVar6 = (undefined4 *)*puVar6) {

    iVar4 = FUN_0053a860(pcVar11,puVar6 + 3);

    if (iVar4 != 0) {

      puVar6[2] = puVar6[2] + 1;

      fVar5 = (float)puVar6[1];

      if (fVar5 != 0.0) goto LAB_00405497;

      break;

    }

  }

  vfs_fileread_load(pcVar11,&param_1,&param_3);

  if (param_3 != (char *)0x0) {

    fVar5 = (float)FUN_0053ba50(0,0,param_1);

    FUN_00405700(pcVar11,fVar5);

    if (fVar5 != 0.0) {

LAB_00405497:

      pfVar10 = (float *)FUN_0053a700(2,0x58,&DAT_005541e0,

                                      s_C__Giants_source_main_ANIMATE_CP_00554124,0x517);

      pfVar12 = pfVar10;

      for (iVar4 = 0x16; iVar4 != 0; iVar4 = iVar4 + -1) {

        *pfVar12 = 0.0;

        pfVar12 = pfVar12 + 1;

      }

      pfVar10[10] = fVar5;

      iVar4 = *(int *)((int)fVar5 + 0x1c);

      iVar1 = *(int *)((int)fVar5 + 0x18);

      pfVar10[1] = *(float *)((int)fVar5 + 0x10);

      *pfVar10 = (float)(*(int *)((int)fVar5 + 0x14) - *(int *)((int)fVar5 + 0x10)) *

                 ((1.0 / (float)iVar4) / (float)iVar1);

      goto LAB_004054e8;

    }

  }

  FUN_00542f27(&DAT_00657400,s_AnimationCreateF_read_animdata_z_005541e8,pcVar11);

  FUN_00425eb0(&DAT_00657400);

  FUN_0051ea20(&DAT_00657400);

  pfVar10 = (float *)0x0;

LAB_004054e8:

  pfVar10[2] = (float)((uint)pfVar10[2] | 1);

  puVar3[param_2 + 2] = pfVar10;

  return;

}

/* ===== FUN_00405700 @ 0x00405700 ===== */
void FUN_00405700(char *param_1,undefined4 param_2)



{

  char cVar1;

  int iVar2;

  undefined4 *puVar3;

  int *piVar4;

  uint uVar5;

  char *pcVar6;

  

  uVar5 = 0xffffffff;

  pcVar6 = param_1;

  do {

    if (uVar5 == 0) break;

    uVar5 = uVar5 - 1;

    cVar1 = *pcVar6;

    pcVar6 = pcVar6 + 1;

  } while (cVar1 != '\0');

  puVar3 = (undefined4 *)

           FUN_0053a700(2,~uVar5 + 0xf,&PTR_DAT_00554220,s_C__Giants_source_main_ANIMATE_CP_00554124

                        ,0x5d3);

  *puVar3 = DAT_005841a4;

  DAT_005841a4 = puVar3;

  puVar3[1] = param_2;

  iVar2 = 0xc - (int)param_1;

  do {

    cVar1 = *param_1;

    param_1[(int)puVar3 + iVar2] = cVar1;

    param_1 = param_1 + 1;

  } while (cVar1 != '\0');

  puVar3[2] = 1;

  piVar4 = (int *)FUN_0053bb30(param_2);

  DAT_0058419c = DAT_0058419c + *piVar4;

  return;

}

/* ===== FUN_00405780 @ 0x00405780 ===== */
void FUN_00405780(int param_1)



{

  if (*(int **)(param_1 + 0x70) != (int *)0x0) {

    DAT_005841a0 = DAT_005841a0 - **(int **)(param_1 + 0x70);

  }

  if (*(int *)(param_1 + 0x6c) != 0) {

    FUN_0053bd70(*(int *)(param_1 + 0x6c));

  }

  if (*(int *)(param_1 + 0x70) != 0) {

    mem_free_tagged(*(int *)(param_1 + 0x70),s_C__Giants_source_main_ANIMATE_CP_00554124,0x615);

  }

  *(undefined4 *)(param_1 + 0x70) = 0;

  *(undefined4 *)(param_1 + 0x6c) = 0;

  return;

}

/* ===== FUN_004057d0 @ 0x004057D0 ===== */
void FUN_004057d0(int param_1)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  int *piVar4;

  int *piVar5;

  int iVar6;

  undefined4 *puVar7;

  int *local_c;

  int local_4;

  

  local_c = (int *)(param_1 + 8);

  local_4 = 0xfe;

  do {

    iVar2 = *local_c;

    if (iVar2 != 0) {

      piVar5 = (int *)(param_1 + 0x400);

      if (*(int *)(*(int *)(param_1 + 0x400) + 0x6c) == 0) {

        iVar3 = *(int *)(iVar2 + 0x28);

        piVar5 = (int *)&DAT_005841a4;

        for (piVar1 = DAT_005841a4; piVar1 != (int *)0x0; piVar1 = (int *)*piVar1) {

          if (piVar1[1] == iVar3) {

            piVar4 = (int *)*piVar5;

            piVar1 = piVar4 + 2;

            *piVar1 = *piVar1 + -1;

            if (*piVar1 == 0) {

              *piVar5 = *piVar4;

              piVar5 = (int *)FUN_0053bb30(iVar3);

              DAT_0058419c = DAT_0058419c - *piVar5;

              FUN_0053bd70(iVar3);

              mem_free_tagged(piVar5,s_C__Giants_source_main_ANIMATE_CP_00554124,0x5f3);

              mem_free_tagged(piVar4,s_C__Giants_source_main_ANIMATE_CP_00554124,0x5f4);

            }

            break;

          }

          piVar5 = piVar1;

        }

        mem_free_tagged(iVar2,s_C__Giants_source_main_ANIMATE_CP_00554124,0x628);

        *local_c = 0;

      }

      else {

        iVar3 = *(int *)(iVar2 + 0x28);

        iVar6 = 0;

        puVar7 = (undefined4 *)(iVar2 + 0x2c);

        do {

          if (*piVar5 == 0) break;

          FUN_0053d2a0(*puVar7);

          iVar6 = iVar6 + 1;

          piVar5 = piVar5 + 1;

          puVar7 = puVar7 + 1;

        } while (iVar6 < 10);

        piVar5 = (int *)&DAT_005841a4;

        for (piVar1 = DAT_005841a4; piVar1 != (int *)0x0; piVar1 = (int *)*piVar1) {

          if (piVar1[1] == iVar3) {

            piVar4 = (int *)*piVar5;

            piVar1 = piVar4 + 2;

            *piVar1 = *piVar1 + -1;

            if (*piVar1 == 0) {

              *piVar5 = *piVar4;

              piVar5 = (int *)FUN_0053bb30(iVar3);

              DAT_0058419c = DAT_0058419c - *piVar5;

              FUN_0053bd70(iVar3);

              mem_free_tagged(piVar5,s_C__Giants_source_main_ANIMATE_CP_00554124,0x5f3);

              mem_free_tagged(piVar4,s_C__Giants_source_main_ANIMATE_CP_00554124,0x5f4);

            }

            break;

          }

          piVar5 = piVar1;

        }

        mem_free_tagged(iVar2,s_C__Giants_source_main_ANIMATE_CP_00554124,0x634);

        *local_c = 0;

      }

    }

    local_c = local_c + 1;

    local_4 = local_4 + -1;

    if (local_4 == 0) {

      return;

    }

  } while( true );

}

