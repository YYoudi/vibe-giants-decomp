/* Giants 1.449 — module _unmapped_0054
 * 351 functions (259 named) — decompiled, names from PS2 symbols
 * Original source: C:\Giants\source\_unmapped_0054.c(pp) (assert-string evidence)
 */

/* ===== map_memfree @ 0x00540020 ===== */
void map_memfree(int param_1,int param_2)



{

  undefined4 *puVar1;

  undefined4 *puVar2;

  undefined4 *puVar3;

  undefined4 unaff_ESI;

  undefined4 unaff_EDI;

  

  do {

    if (param_2 == 0) {

      return;

    }

    if (param_1 == 0) break;

    puVar1 = (undefined4 *)(param_1 + 0x10);

    puVar2 = puVar1;

    puVar3 = (undefined4 *)*puVar1;

    while( true ) {

      if (puVar3 == puVar1) {

        FUN_00540310(s_Error_MAP_MemFree__couldn_t_free_00580ca4);

        return;

      }

      if (puVar3 == (undefined4 *)(param_2 + -0xc)) break;

      puVar2 = puVar3;

      puVar3 = (undefined4 *)*puVar3;

    }

    *puVar2 = *puVar3;

    *puVar3 = puVar3;

    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) - *(int *)(param_2 + -8);

    *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -1;

    if ((*(byte *)(param_2 + -4) & 1) == 0) {

      return;

    }

    param_1 = *(int *)(param_1 + 0xc);

    param_2 = param_2 + -0x10;

  } while (param_1 != 0);

  (*(code *)PTR___get_eh_context_00580c90)(param_2,unaff_EDI,unaff_ESI);

  return;

}

/* ===== MAP_PtrFix @ 0x005400E0 ===== */
/* PS2 candidate: MAP_PtrFix (conf 0.582) */



undefined4 MAP_PtrFix(int *param_1,int *param_2)



{

  int iVar1;

  int *piVar2;

  int *piVar3;

  int *local_c [3];

  

  if (param_2[1] != 0) {

    if (*param_1 != 0) {

      *param_1 = *param_2 + *param_1;

    }

    return 1;

  }

  local_c[0] = param_1;

  iVar1 = MAP_MappingFind(*(undefined4 *)(*param_2 + 4),local_c,0);

  piVar2 = (int *)((uint)*(ushort *)(iVar1 + 2) + iVar1);

  local_c[0] = (int *)*param_1;

  piVar2 = (int *)((piVar2[1] - *piVar2) + (int)param_1);

  iVar1 = MAP_MappingFind(*(undefined4 *)(*param_2 + 4),local_c,0);

  if (iVar1 != 0) {

    piVar3 = (int *)((uint)*(ushort *)(iVar1 + 2) + iVar1);

    *piVar2 = ((piVar3[1] - *(int *)*param_2) - *piVar3) + *param_1;

    return 1;

  }

  *piVar2 = 0;

  return 0;

}

/* ===== MAP_ChunkPoolCreate @ 0x00540190 ===== */
/* PS2 candidate: MAP_ChunkPoolCreate (conf 0.721) */



void MAP_ChunkPoolCreate(undefined4 param_1,undefined2 param_2,short param_3)



{

  undefined4 *puVar1;

  undefined4 uVar2;

  undefined4 *puVar3;

  

  uVar2 = FUN_0053feb0(param_1,0);

  puVar3 = (undefined4 *)FUN_0053ffa0(uVar2,0x1c,1);

  *(undefined2 *)(puVar3 + 1) = param_2;

  puVar1 = puVar3 + 3;

  puVar3[4] = puVar1;

  *puVar1 = puVar1;

  puVar1 = puVar3 + 5;

  *puVar3 = uVar2;

  *(short *)((int)puVar3 + 6) = param_3 + 8;

  *(undefined2 *)((int)puVar3 + 10) = 0;

  *(undefined2 *)(puVar3 + 2) = 0;

  *puVar1 = puVar1;

  puVar3[6] = puVar1;

  return;

}

/* ===== FUN_005401e0 @ 0x005401E0 ===== */
int * FUN_005401e0(int param_1)



{

  uint *puVar1;

  int *piVar2;

  int *piVar3;

  

  puVar1 = (uint *)(param_1 + 0xc);

  if (((uint)*(uint **)(param_1 + 0xc) & -(uint)(*(uint **)(param_1 + 0xc) != puVar1)) == 0) {

    MAP_ChunksAlloc__FP14_MAP_ChunkPoolUi(param_1,*(undefined2 *)(param_1 + 4));

  }

  piVar3 = (int *)(-(uint)((uint *)*puVar1 != puVar1) & *puVar1);

  if (piVar3 != (int *)0x0) {

    *(int *)piVar3[1] = *piVar3;

    *(int *)(*piVar3 + 4) = piVar3[1];

    piVar2 = (int *)(param_1 + 0x14);

    piVar3[1] = (int)piVar2;

    *piVar3 = *piVar2;

    *piVar2 = (int)piVar3;

    *(int **)(*piVar3 + 4) = piVar3;

    *(short *)(param_1 + 8) = *(short *)(param_1 + 8) + -1;

    *(short *)(param_1 + 10) = *(short *)(param_1 + 10) + 1;

    return piVar3 + 2;

  }

  return (int *)0x0;

}

/* ===== MAP_ChunksAlloc__FP14_MAP_ChunkPoolUi @ 0x00540250 ===== */
/* PS2 candidate: MAP_ChunksAlloc__FP14_MAP_ChunkPoolUi (conf 0.695) */



undefined4 MAP_ChunksAlloc__FP14_MAP_ChunkPoolUi(undefined4 *param_1,int param_2)



{

  int iVar1;

  int *piVar2;

  

  piVar2 = (int *)FUN_0053ffa0(*param_1,(uint)*(ushort *)((int)param_1 + 6) * param_2,1);

  if (piVar2 == (int *)0x0) {

    return 0;

  }

  *(short *)(param_1 + 2) = *(short *)(param_1 + 2) + (short)param_2;

  for (; param_2 != 0; param_2 = param_2 + -1) {

    *piVar2 = (int)piVar2;

    piVar2[1] = (int)piVar2;

    iVar1 = param_1[4];

    *piVar2 = (int)(param_1 + 3);

    piVar2[1] = iVar1;

    param_1[4] = piVar2;

    *(int **)piVar2[1] = piVar2;

    piVar2 = (int *)((int)piVar2 + (uint)*(ushort *)((int)param_1 + 6));

  }

  return 1;

}

/* ===== MAP_ChunkDestroy @ 0x005402B0 ===== */
undefined4 MAP_ChunkDestroy(int param_1,int param_2)



{

  int *piVar1;

  int *piVar2;

  

  piVar2 = (int *)(param_1 + -8);

  **(int **)(param_1 + -4) = *piVar2;

  *(undefined4 *)(*piVar2 + 4) = *(undefined4 *)(param_1 + -4);

  piVar1 = (int *)(param_2 + 0xc);

  *(int **)(param_1 + -4) = piVar1;

  *piVar2 = *piVar1;

  *piVar1 = (int)piVar2;

  *(int **)(*piVar2 + 4) = piVar2;

  *(short *)(param_2 + 8) = *(short *)(param_2 + 8) + 1;

  *(short *)(param_2 + 10) = *(short *)(param_2 + 10) + -1;

  return 1;

}

/* ===== AudioSetSpeakerConfig__F14SPEAKER_SYSTEM_8 @ 0x005402F0 ===== */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */



void AudioSetSpeakerConfig__F14SPEAKER_SYSTEM_8(undefined4 p0)



{

  DAT_00630b40 = p0;

  return;

}

/* ===== FUN_00540310 @ 0x00540310 ===== */
void FUN_00540310(undefined4 param_1)



{

  int iVar1;

  uint uVar2;

  uint uVar3;

  undefined4 *puVar4;

  

  uVar3 = DAT_00630b30;

  if (DAT_00630b38 < 1) {

    iVar1 = (int)&DAT_00630a30 + DAT_00630b30;

    puVar4 = &DAT_00630a30;

    for (uVar2 = DAT_00630b30 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {

      *puVar4 = 0x20202020;

      puVar4 = puVar4 + 1;

    }

    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {

      *(undefined1 *)puVar4 = 0x20;

      puVar4 = (undefined4 *)((int)puVar4 + 1);

    }

    crt_flsbuf_ops(iVar1,param_1,&stack0x00000008);

    OutputDebugStringA((LPCSTR)&DAT_00630a30);

    if ((DAT_00630b40 != (code *)0x0) && (DAT_00630b3c == 0)) {

      (*DAT_00630b40)(&DAT_00630a30);

    }

    if (DAT_00630b44 != 0) {

      crt_file_free_init(DAT_00630b44,&DAT_00555df0,&DAT_00630a30);

    }

    if (DAT_00630b50 != 0) {

      crt_file_free_init(DAT_00630b48,&DAT_00555df0,&DAT_00630a30);

    }

  }

  return;

}

/* ===== LNK_DNodeInDList @ 0x005403C0 ===== */
bool LNK_DNodeInDList(int *param_1)



{

  return (int *)*param_1 != param_1;

}

/* ===== NAM_DictionaryGetTotalNames_3 @ 0x00540490 ===== */
undefined4 NAM_DictionaryGetTotalNames_3(int param_1)



{

  return *(undefined4 *)(*(int *)(param_1 + 4) + 0x1c);

}

/* ===== NAM_NameGetCustom @ 0x005404A0 ===== */
int NAM_NameGetCustom(int param_1)



{

  return (uint)*(ushort *)(param_1 + 2) + param_1;

}

/* ===== NAM_NameGetCustom @ 0x005404B0 ===== */
/* PS2 candidate: NAM_NameGetCustom_2 (conf 0.522) */



int NAM_NameGetCustom(int param_1)



{

  return *(ushort *)(param_1 + 2) + 4 + param_1;

}

/* ===== NAM_NameFindByHandleIndex @ 0x005404C0 ===== */
void NAM_NameFindByHandleIndex(int param_1,undefined4 param_2)



{

  MAP_MappingFind(*(undefined4 *)(param_1 + 4),param_2,0);

  return;

}

/* ===== NAM_NameFindByHandleIndex_2 @ 0x005404E0 ===== */
void NAM_NameFindByHandleIndex_2(int param_1,undefined4 param_2)



{

  MAP_MappingGet(*(undefined4 *)(param_1 + 4),param_2,0);

  return;

}

/* ===== NAM_NameFindByHandle @ 0x00540500 ===== */
/* PS2 candidate: NAM_NameFindByHandle (conf 0.771) */



void NAM_NameFindByHandle(int param_1)



{

  MAP_MappingFind(*(undefined4 *)(param_1 + 4),&stack0x00000008,1);

  return;

}

/* ===== FUN_00540530 @ 0x00540530 ===== */
void FUN_00540530(int param_1,code *param_2,undefined4 param_3)



{

  undefined4 *puVar1;

  int iVar2;

  int iVar3;

  

  MAP_PtrFix(param_1,param_3);

  puVar1 = (undefined4 *)(param_1 + 4);

  MAP_PtrFix(puVar1,param_3);

  PTR_LAB_00580cd0 = &LAB_00540440;

  if ((*(byte *)(param_1 + 8) & 2) == 0) {

    PTR_LAB_00580cd0 = &LAB_00540400;

  }

  FUN_0053fd40(*puVar1,&DAT_00580ccc,param_3);

  iVar3 = 0;

  iVar2 = MAP_MappingGet(*puVar1,0,0);

  while (iVar2 != 0) {

    if (param_2 != (code *)0x0) {

      (*param_2)((uint)*(ushort *)(iVar2 + 2) + iVar2,param_3);

    }

    iVar3 = iVar3 + 1;

    iVar2 = MAP_MappingGet(*puVar1,iVar3,0);

  }

  return;

}

/* ===== cpu_vendor_detect @ 0x005405C0 ===== */
/* WARNING: Removing unreachable block (ram,0x005406e8) */

/* WARNING: Removing unreachable block (ram,0x005406d2) */

/* WARNING: Removing unreachable block (ram,0x0054066d) */

/* WARNING: Removing unreachable block (ram,0x00540651) */

/* WARNING: Removing unreachable block (ram,0x0054063e) */



void cpu_vendor_detect(void)



{

  char cVar1;

  undefined4 *puVar2;

  uint *puVar3;

  int iVar4;

  int iVar5;

  char *pcVar6;

  int *piVar7;

  uint local_44;

  char local_40 [4];

  char local_3c [4];

  char local_38 [4];

  char local_34;

  int local_30;

  int local_2c;

  int local_28;

  char local_24;

  undefined4 local_20;

  undefined1 *local_1c;

  void *local_14;

  undefined1 *puStack_10;

  undefined *puStack_c;

  undefined4 local_8;

  

  puStack_c = &DAT_00551d78;

  puStack_10 = &LAB_00544c84;

  local_14 = ExceptionList;

  local_1c = &stack0xffffffb0;

  local_24 = s_UnknownVendr_00580de8[0xc];

  local_40 = (char  [4])s_AuthenticAMD_00580dd8._0_4_;

  local_3c = (char  [4])s_AuthenticAMD_00580dd8._4_4_;

  local_38 = (char  [4])s_AuthenticAMD_00580dd8._8_4_;

  local_34 = s_AuthenticAMD_00580dd8[0xc];

  cpuid_basic_info(0);

  local_8 = 0xffffffff;

  local_44 = 0;

  piVar7 = (int *)cpuid_basic_info(0);

  local_30 = piVar7[1];

  local_2c = piVar7[2];

  local_28 = piVar7[3];

  if (*piVar7 != 0) {

    puVar2 = (undefined4 *)cpuid_Version_info(1);

    local_20 = *puVar2;

    local_44 = -(uint)((puVar2[2] & 0x2000000) != 0) & 0x600;

    puVar3 = (uint *)cpuid(0x80000000);

    if (0x80000000 < *puVar3) {

      cpuid(0x80000001);

      iVar5 = 0xc;

      pcVar6 = local_40;

      piVar7 = &local_30;

      do {

        if (iVar5 == 0) break;

        iVar5 = iVar5 + -1;

        iVar4 = *piVar7;

        cVar1 = *pcVar6;

        pcVar6 = pcVar6 + 1;

        piVar7 = (int *)((int)piVar7 + 1);

      } while (cVar1 == (char)iVar4);

    }

  }

  if ((local_44 & 0x400) != 0) {

    return;

  }

  return;

}

/* ===== cpu_feature_dispatch @ 0x005407E0 ===== */
uint cpu_feature_dispatch(void)



{

  uint uVar1;

  

  uVar1 = cpu_vendor_detect();

  if ((uVar1 & 0x400) != 0) {

    return 2;

  }

  return (uVar1 & 0xff) >> 7;

}

/* ===== crt_math_dispatch_init @ 0x00540800 ===== */
void crt_math_dispatch_init(int param_1)



{

  if (param_1 == -1) {

    param_1 = cpu_feature_dispatch();

  }

  PTR_collgrid_collision_test_00554058 = (&PTR_LAB_00580cdc)[param_1];

  PTR_S_maxobj_create_vertex_normals_0055405c = (&PTR_LAB_00580ce8)[param_1];

  PTR_FUN_00554060 = (&PTR_FUN_00580cf4)[param_1];

  PTR_collgrid_collide_b_00554064 = (&PTR_LAB_00580d00)[param_1];

  PTR_mesh_build_fvf_verts_2_005565b0 = (&PTR_mesh_build_fvf_verts_00580d0c)[param_1];

  PTR_FUN_005565b4 = (&PTR_LAB_00580d18)[param_1];

  PTR_level_scene_mesh_render_005565b8 = (&PTR_LAB_00580d24)[param_1];

  PTR_crt_matrix_copy_init_00580c1c = (&PTR_crt_matrix_copy_init_00580d30)[param_1];

  PTR_crt_matrix_mul_00580c18 = (&PTR_crt_matrix_mul_00580d3c)[param_1];

  PTR_S_GEO_Vec3Transform_00580c20 = (&PTR_S_GEO_Vec3Transform_00580d48)[param_1];

  PTR_S_GEO_Vec3Transform_2_00580c24 = (&PTR_S_GEO_Vec3Transform_2_00580d54)[param_1];

  PTR_S_GEO_Vec4Transform_00580c28 = (&PTR_S_GEO_Vec4Transform_00580d60)[param_1];

  PTR_FUN_00580c30 = (&PTR_FUN_00580d6c)[param_1];

  PTR_FUN_00580c34 = (&PTR_FUN_00580d78)[param_1];

  PTR_AddHud__4cHudP8cHudIcon_5_00580c38 = (&PTR_AddHud__4cHudP8cHudIcon_5_00580d84)[param_1];

  PTR_FUN_00580c3c = (&PTR_FUN_00580d90)[param_1];

  PTR_LAB_00580c40 = (&PTR_LAB_00580d9c)[param_1];

  PTR_FUN_00580c44 = (&PTR_FUN_00580da8)[param_1];

  PTR_LAB_00580c48 = (&PTR_LAB_00580db4)[param_1];

  PTR_FUN_00580c4c = (&PTR_FUN_00580dc0)[param_1];

  PTR_ANM_ClusterApplyMatSingleVertex_0058096c =

       (&PTR_ANM_ClusterApplyMatSingleVertex_00580dcc)[param_1];

  return;

}

/* ===== FUN_00540ab0 @ 0x00540AB0 ===== */
/* PS2 candidate: S_TriCalcGradients_2 (conf 0.601) */



void FUN_00540ab0(float *param_1,float *param_2,int param_3,int param_4,int param_5,int param_6)



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

  float fVar16;

  

  iVar11 = *(int *)(param_3 + 0x34);

  iVar12 = *(int *)(param_3 + 0x14);

  pfVar1 = (float *)(iVar12 + (uint)*(ushort *)(iVar11 + param_4 * 2) * 0xc);

  pfVar2 = (float *)(iVar12 + (uint)*(ushort *)(iVar11 + param_5 * 2) * 0xc);

  pfVar3 = (float *)(iVar12 + (uint)*(ushort *)(iVar11 + param_6 * 2) * 0xc);

  iVar11 = *(int *)(param_3 + 0x3c);

  fVar7 = *pfVar2;

  fVar8 = *pfVar1;

  fVar15 = *(float *)(iVar11 + param_5 * 8) - *(float *)(iVar11 + param_4 * 8);

  fVar14 = *(float *)(iVar11 + 4 + param_5 * 8) - *(float *)(iVar11 + 4 + param_4 * 8);

  pfVar4 = (float *)(iVar11 + 4 + param_5 * 8);

  pfVar5 = (float *)(iVar11 + 4 + param_4 * 8);

  fVar9 = *pfVar3;

  fVar10 = *pfVar1;

  pfVar6 = (float *)(iVar11 + 4 + param_6 * 8);

  fVar16 = *(float *)(iVar11 + param_6 * 8) - *(float *)(iVar11 + param_4 * 8);

  fVar13 = (*pfVar6 - *pfVar5) * fVar15 - fVar16 * fVar14;

  if (1e-12 < ABS(fVar13)) {

    fVar13 = 1.0 / fVar13;

    *param_1 = -(((fVar9 - fVar10) * fVar14 - (*pfVar6 - *pfVar5) * (fVar7 - fVar8)) * fVar13);

    *param_2 = -(fVar13 * (fVar16 * (fVar7 - fVar8) - (fVar9 - fVar10) * fVar15));

  }

  fVar7 = pfVar2[1];

  fVar8 = pfVar1[1];

  fVar15 = *(float *)(iVar11 + param_5 * 8) - *(float *)(iVar11 + param_4 * 8);

  fVar14 = *pfVar4 - *pfVar5;

  fVar9 = pfVar3[1];

  fVar10 = pfVar1[1];

  fVar16 = *(float *)(iVar11 + param_6 * 8) - *(float *)(iVar11 + param_4 * 8);

  fVar13 = (*pfVar6 - *pfVar5) * fVar15 - fVar16 * fVar14;

  if (1e-12 < ABS(fVar13)) {

    fVar13 = 1.0 / fVar13;

    param_1[1] = -(((fVar9 - fVar10) * fVar14 - (*pfVar6 - *pfVar5) * (fVar7 - fVar8)) * fVar13);

    param_2[1] = -(fVar13 * (fVar16 * (fVar7 - fVar8) - (fVar9 - fVar10) * fVar15));

  }

  fVar7 = pfVar2[2];

  fVar8 = pfVar1[2];

  fVar15 = *(float *)(iVar11 + param_5 * 8) - *(float *)(iVar11 + param_4 * 8);

  fVar14 = *pfVar4 - *pfVar5;

  fVar9 = pfVar3[2];

  fVar10 = pfVar1[2];

  fVar16 = *(float *)(iVar11 + param_6 * 8) - *(float *)(iVar11 + param_4 * 8);

  fVar13 = (*pfVar6 - *pfVar5) * fVar15 - fVar16 * fVar14;

  if (1e-12 < ABS(fVar13)) {

    fVar13 = 1.0 / fVar13;

    param_1[2] = -(((fVar9 - fVar10) * fVar14 - (*pfVar6 - *pfVar5) * (fVar7 - fVar8)) * fVar13);

    param_2[2] = -(fVar13 * (fVar16 * (fVar7 - fVar8) - (fVar9 - fVar10) * fVar15));

  }

  return;

}

/* ===== ANM_ClusterApplyMatSingleVertex_2 @ 0x00541690 ===== */
/* PS2 candidate: ANM_ClusterApplyMatSingleVertex_2 (conf 0.592) */



void ANM_ClusterApplyMatSingleVertex_2(int param_1,int param_2,int param_3,int param_4,int param_5)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  float fVar11;

  float fVar12;

  float fVar13;

  float fVar14;

  float fVar15;

  float fVar16;

  float fVar17;

  float fVar18;

  float fVar19;

  float fVar20;

  float fVar21;

  float *pfVar22;

  float *pfVar23;

  float *pfVar24;

  float *pfVar25;

  float *pfVar26;

  uint uVar27;

  int iVar28;

  uint local_d0;

  

  uVar27 = *(uint *)(param_1 + 0x24);

  if ((int)uVar27 < 1) {

    if (uVar27 != 0) {

      iVar28 = -uVar27;

      pfVar22 = (float *)(param_1 + 0x28);

      do {

        pfVar23 = (float *)(((int)pfVar22[3] + param_5) * param_4 + param_3);

        iVar28 = iVar28 + -1;

        *pfVar23 = (*(float *)(param_2 + 8) * pfVar22[1] +

                    *(float *)(param_2 + 0xc) * pfVar22[2] + *pfVar22 * *(float *)(param_2 + 4) +

                   *(float *)(param_2 + 0x10)) * pfVar22[4] + *pfVar23;

        pfVar23[1] = (*(float *)(param_2 + 0x18) * pfVar22[1] +

                      *(float *)(param_2 + 0x1c) * pfVar22[2] +

                      *pfVar22 * *(float *)(param_2 + 0x14) + *(float *)(param_2 + 0x20)) *

                     pfVar22[4] + pfVar23[1];

        pfVar23[2] = (*(float *)(param_2 + 0x28) * pfVar22[1] +

                      *(float *)(param_2 + 0x2c) * pfVar22[2] +

                      *pfVar22 * *(float *)(param_2 + 0x24) + *(float *)(param_2 + 0x30)) *

                     pfVar22[4] + pfVar23[2];

        pfVar22 = pfVar22 + 5;

      } while (iVar28 != 0);

    }

  }

  else {

    pfVar22 = (float *)(param_1 + 0x28);

    if (0xc < (int)uVar27) {

      fVar1 = *(float *)(param_2 + 4);

      fVar2 = *(float *)(param_2 + 8);

      fVar3 = *(float *)(param_2 + 0xc);

      fVar4 = *(float *)(param_2 + 0x14);

      fVar5 = *(float *)(param_2 + 0x18);

      fVar6 = *(float *)(param_2 + 0x1c);

      fVar7 = *(float *)(param_2 + 0x24);

      fVar8 = *(float *)(param_2 + 0x28);

      fVar9 = *(float *)(param_2 + 0x2c);

      if (3 < (int)uVar27) {

        local_d0 = uVar27 >> 2;

        uVar27 = uVar27 + local_d0 * -4;

        do {

          fVar10 = pfVar22[4];

          fVar11 = pfVar22[5];

          fVar12 = pfVar22[6];

          pfVar23 = (float *)(((int)pfVar22[3] + param_5) * param_4 + param_3);

          pfVar24 = (float *)(((int)pfVar22[7] + param_5) * param_4 + param_3);

          pfVar25 = (float *)(((int)pfVar22[0xb] + param_5) * param_4 + param_3);

          pfVar26 = (float *)(((int)pfVar22[0xf] + param_5) * param_4 + param_3);

          fVar13 = *pfVar22;

          fVar14 = pfVar22[1];

          fVar15 = pfVar22[2];

          fVar16 = pfVar22[8];

          fVar17 = pfVar22[9];

          fVar18 = pfVar22[10];

          fVar19 = pfVar22[0xc];

          fVar20 = pfVar22[0xd];

          fVar21 = pfVar22[0xe];

          *pfVar23 = fVar1 * fVar13 + fVar2 * fVar14 + fVar3 * fVar15 + *(float *)(param_2 + 0x10);

          pfVar23[1] = fVar4 * fVar13 + fVar5 * fVar14 + fVar6 * fVar15 + *(float *)(param_2 + 0x20)

          ;

          pfVar23[2] = fVar7 * fVar13 + fVar8 * fVar14 + fVar9 * fVar15 + *(float *)(param_2 + 0x30)

          ;

          pfVar22 = pfVar22 + 0x10;

          *pfVar24 = fVar1 * fVar10 + fVar2 * fVar11 + fVar3 * fVar12 + *(float *)(param_2 + 0x10);

          pfVar24[1] = fVar4 * fVar10 + fVar5 * fVar11 + fVar6 * fVar12 + *(float *)(param_2 + 0x20)

          ;

          pfVar24[2] = fVar7 * fVar10 + fVar8 * fVar11 + fVar9 * fVar12 + *(float *)(param_2 + 0x30)

          ;

          *pfVar25 = fVar1 * fVar16 + fVar2 * fVar17 + fVar3 * fVar18 + *(float *)(param_2 + 0x10);

          pfVar25[1] = fVar4 * fVar16 + fVar5 * fVar17 + fVar6 * fVar18 + *(float *)(param_2 + 0x20)

          ;

          pfVar25[2] = fVar7 * fVar16 + fVar8 * fVar17 + fVar9 * fVar18 + *(float *)(param_2 + 0x30)

          ;

          local_d0 = local_d0 - 1;

          *pfVar26 = fVar1 * fVar19 + fVar2 * fVar20 + fVar3 * fVar21 + *(float *)(param_2 + 0x10);

          pfVar26[1] = fVar4 * fVar19 + fVar5 * fVar20 + fVar6 * fVar21 + *(float *)(param_2 + 0x20)

          ;

          pfVar26[2] = fVar7 * fVar19 + fVar8 * fVar20 + fVar9 * fVar21 + *(float *)(param_2 + 0x30)

          ;

        } while (local_d0 != 0);

      }

    }

    if (uVar27 != 0) {

      do {

        pfVar23 = (float *)(((int)pfVar22[3] + param_5) * param_4 + param_3);

        uVar27 = uVar27 - 1;

        *pfVar23 = pfVar22[1] * *(float *)(param_2 + 8) +

                   pfVar22[2] * *(float *)(param_2 + 0xc) + *pfVar22 * *(float *)(param_2 + 4) +

                   *(float *)(param_2 + 0x10);

        pfVar23[1] = pfVar22[1] * *(float *)(param_2 + 0x18) +

                     pfVar22[2] * *(float *)(param_2 + 0x1c) + *pfVar22 * *(float *)(param_2 + 0x14)

                     + *(float *)(param_2 + 0x20);

        pfVar23[2] = pfVar22[1] * *(float *)(param_2 + 0x28) +

                     pfVar22[2] * *(float *)(param_2 + 0x2c) + *pfVar22 * *(float *)(param_2 + 0x24)

                     + *(float *)(param_2 + 0x30);

        pfVar22 = pfVar22 + 4;

      } while (uVar27 != 0);

      return;

    }

  }

  return;

}

/* ===== crt_matrix_copy_init @ 0x00541A40 ===== */
void crt_matrix_copy_init(uint *param_1,uint *param_2)



{

  float fVar1;

  float fVar2;

  float *pfVar3;

  int iVar4;

  uint *puVar5;

  uint local_44 [17];

  

  puVar5 = local_44;

  if (param_1 != param_2) {

    puVar5 = param_1;

  }

  if ((*param_2 & 0xf) == 0) {

    puVar5[0xb] = 0x3f800000;

    puVar5[6] = 0x3f800000;

    puVar5[1] = 0x3f800000;

    puVar5[10] = 0;

    puVar5[9] = 0;

    puVar5[7] = 0;

    puVar5[5] = 0;

    puVar5[3] = 0;

    puVar5[2] = 0;

  }

  else if ((*param_2 & 6) == 0) {

    puVar5[1] = param_2[1];

    puVar5[2] = param_2[5];

    puVar5[3] = param_2[9];

    puVar5[5] = param_2[2];

    puVar5[6] = param_2[6];

    puVar5[7] = param_2[10];

    puVar5[9] = param_2[3];

    puVar5[10] = param_2[7];

    puVar5[0xb] = param_2[0xb];

  }

  else {

    fVar1 = (float)param_2[0xb] * (float)param_2[6] - (float)param_2[7] * (float)param_2[10];

    fVar2 = 1.0 / (((float)param_2[5] * (float)param_2[10] - (float)param_2[9] * (float)param_2[6])

                   * (float)param_2[3] +

                  (fVar1 * (float)param_2[1] -

                  ((float)param_2[0xb] * (float)param_2[5] - (float)param_2[9] * (float)param_2[7])

                  * (float)param_2[2]));

    puVar5[1] = (uint)(fVar1 * fVar2);

    puVar5[2] = (uint)(((float)param_2[10] * (float)param_2[3] -

                       (float)param_2[0xb] * (float)param_2[2]) * fVar2);

    puVar5[3] = (uint)(((float)param_2[7] * (float)param_2[2] -

                       (float)param_2[3] * (float)param_2[6]) * fVar2);

    puVar5[5] = (uint)(((float)param_2[9] * (float)param_2[7] -

                       (float)param_2[0xb] * (float)param_2[5]) * fVar2);

    puVar5[6] = (uint)(((float)param_2[0xb] * (float)param_2[1] -

                       (float)param_2[9] * (float)param_2[3]) * fVar2);

    puVar5[7] = (uint)(((float)param_2[5] * (float)param_2[3] -

                       (float)param_2[7] * (float)param_2[1]) * fVar2);

    puVar5[9] = (uint)(((float)param_2[5] * (float)param_2[10] -

                       (float)param_2[9] * (float)param_2[6]) * fVar2);

    puVar5[10] = (uint)(((float)param_2[9] * (float)param_2[2] -

                        (float)param_2[1] * (float)param_2[10]) * fVar2);

    puVar5[0xb] = (uint)(((float)param_2[1] * (float)param_2[6] -

                         (float)param_2[5] * (float)param_2[2]) * fVar2);

  }

  if ((*param_2 & 0x10) == 0) {

    puVar5[0xc] = 0;

    puVar5[8] = 0;

    puVar5[4] = 0;

  }

  else {

    iVar4 = 3;

    pfVar3 = (float *)(puVar5 + 2);

    do {

      iVar4 = iVar4 + -1;

      pfVar3[2] = -(*pfVar3 * (float)param_2[8] +

                   pfVar3[-1] * (float)param_2[4] + pfVar3[1] * (float)param_2[0xc]);

      pfVar3 = pfVar3 + 4;

    } while (iVar4 != 0);

  }

  puVar5[0xf] = 0;

  puVar5[0xe] = 0;

  puVar5[0xd] = 0;

  puVar5[0x10] = 0x3f800000;

  *puVar5 = *param_2;

  if (param_1 != puVar5) {

    for (iVar4 = 0x11; iVar4 != 0; iVar4 = iVar4 + -1) {

      *param_1 = *puVar5;

      puVar5 = puVar5 + 1;

      param_1 = param_1 + 1;

    }

  }

  return;

}

/* ===== anm_dump_a @ 0x00541C10 ===== */
float10 anm_dump_a(float param_1)



{

  ANM_DumpCluster_3();

  return (float10)param_1;

}

/* ===== anm_dump_b @ 0x00541C50 ===== */
float10 anm_dump_b(float param_1)



{

  ANM_DumpCluster_5();

  return (float10)param_1;

}

/* ===== anm_dump_c @ 0x00541C90 ===== */
float10 anm_dump_c(float param_1)



{

  ANM_DumpCluster_3();

  return (float10)1.0 / (float10)param_1;

}

/* ===== anm_dump_d @ 0x00541CD0 ===== */
float10 anm_dump_d(float param_1)



{

  ANM_DumpCluster_5();

  return (float10)1.0 / (float10)param_1;

}

/* ===== FUN_00541d10 @ 0x00541D10 ===== */
unkbyte10 FUN_00541d10(float param_1,float param_2)



{

  unkbyte10 Var1;

  

  Var1 = fpatan((float10)param_1,(float10)param_2);

  return Var1;

}

/* ===== crt_matrix_invert @ 0x00541D20 ===== */
void crt_matrix_invert(int param_1,int param_2)



{

  int iVar1;

  undefined8 *puVar2;

  undefined8 *puVar3;

  undefined8 *puVar4;

  ushort *puVar5;

  ushort *puVar6;

  ushort *puVar7;

  int iVar8;

  ushort uVar9;

  uint uVar10;

  undefined4 *puVar11;

  ushort *puVar12;

  undefined8 uVar13;

  undefined8 uVar14;

  undefined8 uVar15;

  undefined4 uVar16;

  undefined8 uVar17;

  undefined4 uVar18;

  undefined8 uVar19;

  undefined8 *local_20;

  int local_1c;

  uint local_10;

  

  FastExitMediaState();

  local_10 = 0;

  if (*(int *)(param_1 + 0x28) != 0) {

    iVar1 = *(int *)(param_1 + 0xc) + param_2 * 0x24;

    local_20 = (undefined8 *)(*(int *)(param_1 + 0x28) + *(int *)(iVar1 + 0x14) * 0xc);

    local_1c = *(int *)(iVar1 + 0x20);

    if (local_1c != 0) {

      puVar11 = (undefined4 *)(*(int *)(iVar1 + 0x1c) * 0x50 + param_1 + 0x84);

LAB_00541d75:

      puVar12 = (ushort *)*puVar11;

      uVar9 = 0;

      do {

        if (uVar9 == 0) {

          uVar9 = *puVar12;

          if (uVar9 == 0) goto LAB_00541e86;

          local_10 = 0;

        }

        uVar10 = local_10 & 0xffff;

        puVar5 = puVar12 + uVar10 + 1;

        puVar6 = puVar12 + uVar10 + 2;

        puVar7 = puVar12 + uVar10 + 3;

        uVar9 = uVar9 - 1;

        local_10 = local_10 + 3;

        if (uVar9 == 0) {

          puVar12 = puVar12 + (uint)*puVar12 * 3 + 1;

        }

        iVar1 = *(int *)(param_1 + 0x34);

        iVar8 = *(int *)(param_1 + 0x14);

        puVar2 = (undefined8 *)(iVar8 + (uint)*(ushort *)(iVar1 + (uint)*puVar5 * 2) * 0xc);

        puVar3 = (undefined8 *)(iVar8 + (uint)*(ushort *)(iVar1 + (uint)*puVar6 * 2) * 0xc);

        puVar4 = (undefined8 *)(iVar8 + (uint)*(ushort *)(iVar1 + (uint)*puVar7 * 2) * 0xc);

        uVar17 = *puVar2;

        uVar13 = PackedFloatingSUB(*puVar4,uVar17);

        uVar15 = PackedFloatingSUB(*puVar3,uVar17);

        uVar16 = *(undefined4 *)(puVar2 + 1);

        uVar17 = PackedFloatingSUB(CONCAT44(*(undefined4 *)(puVar4 + 1),*(undefined4 *)(puVar3 + 1))

                                   ,CONCAT44(uVar16,uVar16));

        uVar18 = (undefined4)((ulonglong)uVar17 >> 0x20);

        uVar14 = PackedFloatingMUL(CONCAT44(uVar18,(int)((ulonglong)uVar13 >> 0x20)),uVar15);

        uVar16 = (undefined4)uVar17;

        uVar19 = PackedFloatingMUL(uVar13,CONCAT44(uVar16,(int)((ulonglong)uVar15 >> 0x20)));

        uVar17 = PackedFloatingMUL(uVar13,CONCAT44(uVar16,uVar16));

        uVar13 = PackedFloatingSUB(uVar14,uVar19);

        *(int *)(local_20 + 1) = (int)uVar13;

        uVar14 = PackedFloatingMUL(uVar15,CONCAT44(uVar18,uVar18));

        uVar17 = PackedFloatingSUB(uVar17,uVar14);

        *local_20 = CONCAT44((int)uVar17,(int)((ulonglong)uVar13 >> 0x20));

        local_20 = (undefined8 *)((int)local_20 + 0xc);

      } while( true );

    }

  }

LAB_00541e9d:

  FastExitMediaState();

  return;

LAB_00541e86:

  puVar11 = puVar11 + 0x14;

  local_1c = local_1c + -1;

  if (local_1c == 0) goto LAB_00541e9d;

  goto LAB_00541d75;

}

/* ===== mesh_build_fvf_verts @ 0x00541EB0 ===== */
void mesh_build_fvf_verts(undefined4 *param_1,int param_2,int param_3)



{

  undefined4 *puVar1;

  ushort uVar2;

  int iVar3;

  int iVar4;

  undefined4 uVar5;

  int iVar6;

  undefined4 *puVar7;

  ushort *puVar8;

  undefined1 *puVar9;

  

  iVar3 = *(int *)(param_2 + 0x14);

  if (iVar3 != 0) {

    iVar6 = param_3 * 0x50 + param_2;

    iVar4 = *(int *)(iVar6 + 0x88);

    iVar6 = *(int *)(iVar6 + 0x8c);

    puVar8 = (ushort *)(*(int *)(param_2 + 0x34) + iVar4 * 2);

    puVar7 = (undefined4 *)(*(int *)(param_2 + 0x3c) + iVar4 * 8);

    puVar9 = (undefined1 *)(iVar4 * 3 + *(int *)(param_2 + 0x40));

    param_2 = iVar6;

    if (puVar9 == (undefined1 *)0x0) {

      if (0 < iVar6) {

        do {

          uVar2 = *puVar8;

          puVar8 = puVar8 + 1;

          puVar1 = (undefined4 *)(iVar3 + (uint)uVar2 * 0xc);

          *param_1 = *puVar1;

          param_1[1] = puVar1[1];

          uVar5 = puVar1[2];

          param_1[3] = 0xffffff;

          param_1[2] = uVar5;

          param_1[4] = *puVar7;

          param_1[5] = puVar7[1];

          param_2 = param_2 + -1;

          puVar7 = puVar7 + 2;

          param_1 = param_1 + 6;

        } while (param_2 != 0);

        return;

      }

    }

    else if (0 < iVar6) {

      do {

        uVar2 = *puVar8;

        puVar8 = puVar8 + 1;

        puVar1 = (undefined4 *)(iVar3 + (uint)uVar2 * 0xc);

        *param_1 = *puVar1;

        param_1[1] = puVar1[1];

        param_1[2] = puVar1[2];

        param_1[3] = (uint)CONCAT21(CONCAT11(*puVar9,puVar9[1]),puVar9[2]);

        param_1[4] = *puVar7;

        param_1[5] = puVar7[1];

        param_2 = param_2 + -1;

        puVar7 = puVar7 + 2;

        param_1 = param_1 + 6;

        puVar9 = puVar9 + 3;

      } while (param_2 != 0);

    }

  }

  return;

}

/* ===== crt_matrix_vec4_mul @ 0x00541FC0 ===== */
void crt_matrix_vec4_mul(int param_1,int param_2,int param_3,int param_4,int param_5)



{

  undefined8 *puVar1;

  undefined8 *puVar2;

  int iVar3;

  undefined8 uVar4;

  undefined8 uVar5;

  undefined8 uVar6;

  undefined8 uVar7;

  undefined8 uVar8;

  undefined8 uVar9;

  

  iVar3 = *(int *)(param_1 + 0x24);

  FastExitMediaState();

  if (0 < iVar3) {

    puVar1 = (undefined8 *)(param_1 + 0x28);

    do {

      uVar4 = *puVar1;

      uVar6 = PackedFloatingMUL(*(undefined8 *)(param_2 + 4),uVar4);

      uVar5 = puVar1[1];

      uVar7 = PackedFloatingMUL(*(undefined8 *)(param_2 + 0xc),uVar5);

      uVar6 = PackedFloatingAccumulate

                        (uVar6,CONCAT44((int)((ulonglong)*(undefined8 *)(param_2 + 0xc) >> 0x20),

                                        (int)uVar7));

      uVar6 = PackedFloatingAccumulate(uVar6,uVar6);

      puVar2 = (undefined8 *)((*(int *)((int)puVar1 + 0xc) + param_5) * param_4 + param_3);

      iVar3 = iVar3 + -1;

      uVar7 = PackedFloatingMUL(*(undefined8 *)(param_2 + 0x14),uVar4);

      uVar8 = PackedFloatingMUL(*(undefined8 *)(param_2 + 0x1c),uVar5);

      uVar7 = PackedFloatingAccumulate

                        (uVar7,CONCAT44((int)uVar8,

                                        (int)((ulonglong)*(undefined8 *)(param_2 + 0x1c) >> 0x20)));

      uVar7 = PackedFloatingAccumulate(uVar7,uVar7);

      *puVar2 = CONCAT44((int)uVar7,(int)uVar6);

      uVar4 = PackedFloatingMUL(uVar4,*(undefined8 *)(param_2 + 0x24));

      uVar5 = PackedFloatingMUL(uVar5,*(undefined8 *)(param_2 + 0x2c));

      uVar4 = PackedFloatingAccumulate

                        (uVar4,CONCAT44((int)uVar5,

                                        (int)((ulonglong)*(undefined8 *)(param_2 + 0x2c) >> 0x20)));

      uVar4 = PackedFloatingAccumulate(uVar4,uVar4);

      *(int *)(puVar2 + 1) = (int)uVar4;

      puVar1 = puVar1 + 2;

    } while (iVar3 != 0);

    FastExitMediaState();

    return;

  }

  if (iVar3 != 0) {

    iVar3 = -iVar3;

    puVar1 = (undefined8 *)(param_1 + 0x28);

    do {

      uVar4 = *puVar1;

      uVar6 = PackedFloatingMUL(*(undefined8 *)(param_2 + 4),uVar4);

      uVar5 = puVar1[1];

      uVar7 = PackedFloatingMUL(*(undefined8 *)(param_2 + 0xc),uVar5);

      uVar6 = PackedFloatingAccumulate

                        (uVar6,CONCAT44((int)((ulonglong)*(undefined8 *)(param_2 + 0xc) >> 0x20),

                                        (int)uVar7));

      uVar6 = PackedFloatingAccumulate(uVar6,uVar6);

      puVar2 = (undefined8 *)((*(int *)((int)puVar1 + 0xc) + param_5) * param_4 + param_3);

      iVar3 = iVar3 + -1;

      uVar9 = CONCAT44(*(undefined4 *)(puVar1 + 2),*(undefined4 *)(puVar1 + 2));

      uVar8 = PackedFloatingMUL(*(undefined8 *)(param_2 + 0x14),uVar4);

      uVar7 = PackedFloatingMUL(*(undefined8 *)(param_2 + 0x1c),uVar5);

      uVar7 = PackedFloatingAccumulate

                        (uVar8,CONCAT44((int)((ulonglong)*(undefined8 *)(param_2 + 0x1c) >> 0x20),

                                        (int)uVar7));

      uVar7 = PackedFloatingAccumulate(uVar7,uVar7);

      uVar6 = PackedFloatingMUL(CONCAT44((int)uVar7,(int)uVar6),uVar9);

      uVar6 = PackedFloatingADD(uVar6,*puVar2);

      *puVar2 = uVar6;

      uVar4 = PackedFloatingMUL(uVar4,*(undefined8 *)(param_2 + 0x24));

      uVar5 = PackedFloatingMUL(uVar5,*(undefined8 *)(param_2 + 0x2c));

      uVar4 = PackedFloatingAccumulate

                        (uVar4,CONCAT44((int)uVar5,

                                        (int)((ulonglong)*(undefined8 *)(param_2 + 0x2c) >> 0x20)));

      uVar4 = PackedFloatingAccumulate(uVar4,uVar4);

      uVar4 = PackedFloatingMUL(uVar4,uVar9);

      uVar4 = PackedFloatingADD(uVar4,(ulonglong)*(uint *)(puVar2 + 1));

      puVar2[1] = uVar4;

      puVar1 = (undefined8 *)((int)puVar1 + 0x14);

    } while (iVar3 != 0);

  }

  FastExitMediaState();

  return;

}

/* ===== S_GEO_Vec4Transform @ 0x00542130 ===== */
/* PS2 candidate: S_GEO_Vec4Transform (conf 0.766) */



void S_GEO_Vec4Transform(float *param_1,float *param_2,int param_3,uint *param_4)



{

  uint uVar1;

  

  uVar1 = *param_4;

  if ((~uVar1 & 0x20) == 0) {

    if ((uVar1 & 0xb) == 0) {

      if ((uVar1 & 0x10) == 0) {

        for (; param_3 != 0; param_3 = param_3 + -1) {

          *param_1 = *param_2;

          param_1[1] = param_2[1];

          param_1[2] = param_2[2];

          param_1[3] = param_2[3];

          param_2 = param_2 + 4;

          param_1 = param_1 + 4;

        }

      }

      else if (param_3 != 0) {

        do {

          param_3 = param_3 + -1;

          *param_1 = param_2[3] * (float)param_4[4] + *param_2;

          param_1[1] = param_2[3] * (float)param_4[8] + param_2[1];

          param_1[2] = param_2[3] * (float)param_4[0xc] + param_2[2];

          param_1[3] = *param_2 * (float)param_4[0xd] +

                       (float)param_4[0xf] * param_2[2] +

                       (float)param_4[0xe] * param_2[1] + param_2[3] * (float)param_4[0x10];

          param_2 = param_2 + 4;

          param_1 = param_1 + 4;

        } while (param_3 != 0);

        return;

      }

    }

    else if ((uVar1 & 0x10) == 0) {

      if (param_3 != 0) {

        do {

          param_3 = param_3 + -1;

          *param_1 = (float)param_4[1] * *param_2 +

                     (float)param_4[2] * param_2[1] + (float)param_4[3] * param_2[2];

          param_1[1] = param_2[1] * (float)param_4[6] +

                       (float)param_4[7] * param_2[2] + *param_2 * (float)param_4[5];

          param_1[2] = param_2[2] * (float)param_4[0xb] +

                       (float)param_4[9] * *param_2 + (float)param_4[10] * param_2[1];

          param_1[3] = *param_2 * (float)param_4[0xd] +

                       (float)param_4[0xf] * param_2[2] +

                       (float)param_4[0xe] * param_2[1] + param_2[3] * (float)param_4[0x10];

          param_2 = param_2 + 4;

          param_1 = param_1 + 4;

        } while (param_3 != 0);

        return;

      }

    }

    else if (param_3 != 0) {

      do {

        param_3 = param_3 + -1;

        *param_1 = (float)param_4[1] * *param_2 +

                   (float)param_4[2] * param_2[1] +

                   (float)param_4[3] * param_2[2] + param_2[3] * (float)param_4[4];

        param_1[1] = param_2[3] * (float)param_4[8] +

                     param_2[1] * (float)param_4[6] +

                     (float)param_4[7] * param_2[2] + *param_2 * (float)param_4[5];

        param_1[2] = param_2[2] * (float)param_4[0xb] +

                     param_2[3] * (float)param_4[0xc] +

                     (float)param_4[9] * *param_2 + (float)param_4[10] * param_2[1];

        param_1[3] = *param_2 * (float)param_4[0xd] +

                     (float)param_4[0xf] * param_2[2] +

                     (float)param_4[0xe] * param_2[1] + param_2[3] * (float)param_4[0x10];

        param_2 = param_2 + 4;

        param_1 = param_1 + 4;

      } while (param_3 != 0);

      return;

    }

  }

  else if ((uVar1 & 0xb) == 0) {

    if ((uVar1 & 0x10) == 0) {

      if (param_3 != 0) {

        do {

          param_3 = param_3 + -1;

          *param_1 = *param_2;

          param_1[1] = param_2[1];

          param_1[2] = param_2[2];

          param_1[3] = param_2[3];

          param_1 = param_1 + 4;

          param_2 = param_2 + 4;

        } while (param_3 != 0);

        return;

      }

    }

    else if (param_3 != 0) {

      do {

        param_3 = param_3 + -1;

        *param_1 = param_2[3] * (float)param_4[4] + *param_2;

        param_1[1] = param_2[3] * (float)param_4[8] + param_2[1];

        param_1[2] = param_2[3] * (float)param_4[0xc] + param_2[2];

        param_1[3] = param_2[3];

        param_2 = param_2 + 4;

        param_1 = param_1 + 4;

      } while (param_3 != 0);

      return;

    }

  }

  else if ((uVar1 & 0x10) == 0) {

    if (param_3 != 0) {

      do {

        param_3 = param_3 + -1;

        *param_1 = (float)param_4[1] * *param_2 +

                   (float)param_4[2] * param_2[1] + (float)param_4[3] * param_2[2];

        param_1[1] = param_2[1] * (float)param_4[6] +

                     (float)param_4[7] * param_2[2] + *param_2 * (float)param_4[5];

        param_1[2] = param_2[2] * (float)param_4[0xb] +

                     (float)param_4[9] * *param_2 + (float)param_4[10] * param_2[1];

        param_1[3] = param_2[3];

        param_2 = param_2 + 4;

        param_1 = param_1 + 4;

      } while (param_3 != 0);

      return;

    }

  }

  else if (param_3 != 0) {

    do {

      param_3 = param_3 + -1;

      *param_1 = (float)param_4[1] * *param_2 +

                 (float)param_4[2] * param_2[1] +

                 (float)param_4[3] * param_2[2] + param_2[3] * (float)param_4[4];

      param_1[1] = param_2[3] * (float)param_4[8] +

                   param_2[1] * (float)param_4[6] +

                   (float)param_4[7] * param_2[2] + *param_2 * (float)param_4[5];

      param_1[2] = param_2[2] * (float)param_4[0xb] +

                   param_2[3] * (float)param_4[0xc] +

                   (float)param_4[9] * *param_2 + (float)param_4[10] * param_2[1];

      param_1[3] = param_2[3];

      param_2 = param_2 + 4;

      param_1 = param_1 + 4;

    } while (param_3 != 0);

    return;

  }

  return;

}

/* ===== FUN_005424d0 @ 0x005424D0 ===== */
unkbyte10 FUN_005424d0(float param_1)



{

  unkbyte10 Var1;

  

  Var1 = fsin((float10)param_1);

  return Var1;

}

/* ===== AddHud__4cHudP8cHudIcon_5 @ 0x005424E0 ===== */
void AddHud__4cHudP8cHudIcon_5(void)



{

  FUN_005445f0();

  return;

}

/* ===== ANM_ClusterApplyMatSingleVertex @ 0x00542A90 ===== */
/* PS2 candidate: ANM_ClusterApplyMatSingleVertex (conf 0.756) */



void ANM_ClusterApplyMatSingleVertex(int param_1,int param_2,int param_3,int param_4,int param_5)



{

  float *pfVar1;

  float *pfVar2;

  int iVar3;

  

  iVar3 = *(int *)(param_1 + 0x24);

  if (0 < iVar3) {

    pfVar1 = (float *)(param_1 + 0x28);

    do {

      pfVar2 = (float *)(((int)pfVar1[3] + param_5) * param_4 + param_3);

      iVar3 = iVar3 + -1;

      *pfVar2 = *(float *)(param_2 + 0xc) * pfVar1[2] +

                *(float *)(param_2 + 8) * pfVar1[1] + *pfVar1 * *(float *)(param_2 + 4) +

                *(float *)(param_2 + 0x10);

      pfVar2[1] = *(float *)(param_2 + 0x18) * pfVar1[1] +

                  pfVar1[2] * *(float *)(param_2 + 0x1c) + *pfVar1 * *(float *)(param_2 + 0x14) +

                  *(float *)(param_2 + 0x20);

      pfVar2[2] = *(float *)(param_2 + 0x2c) * pfVar1[2] +

                  *pfVar1 * *(float *)(param_2 + 0x24) + *(float *)(param_2 + 0x28) * pfVar1[1] +

                  *(float *)(param_2 + 0x30);

      pfVar1 = pfVar1 + 4;

    } while (iVar3 != 0);

    return;

  }

  if (iVar3 != 0) {

    iVar3 = -iVar3;

    pfVar1 = (float *)(param_1 + 0x28);

    do {

      pfVar2 = (float *)(((int)pfVar1[3] + param_5) * param_4 + param_3);

      iVar3 = iVar3 + -1;

      *pfVar2 = (*pfVar1 * *(float *)(param_2 + 4) +

                 *(float *)(param_2 + 8) * pfVar1[1] + *(float *)(param_2 + 0xc) * pfVar1[2] +

                *(float *)(param_2 + 0x10)) * pfVar1[4] + *pfVar2;

      pfVar2[1] = (*(float *)(param_2 + 0x18) * pfVar1[1] +

                   *(float *)(param_2 + 0x1c) * pfVar1[2] + *(float *)(param_2 + 0x14) * *pfVar1 +

                  *(float *)(param_2 + 0x20)) * pfVar1[4] + pfVar2[1];

      pfVar2[2] = (*(float *)(param_2 + 0x24) * *pfVar1 +

                   *(float *)(param_2 + 0x28) * pfVar1[1] + *(float *)(param_2 + 0x2c) * pfVar1[2] +

                  *(float *)(param_2 + 0x30)) * pfVar1[4] + pfVar2[2];

      pfVar1 = pfVar1 + 5;

    } while (iVar3 != 0);

  }

  return;

}

/* ===== S_GEO_Vec3Transform @ 0x00542BB0 ===== */
/* PS2 candidate: S_GEO_Vec3Transform (conf 0.77) */



void S_GEO_Vec3Transform(float *param_1,float *param_2,int param_3,uint *param_4)



{

  uint uVar1;

  

  uVar1 = *param_4;

  if ((uVar1 & 0xb) == 0) {

    if ((uVar1 & 0x10) == 0) {

      for (; param_3 != 0; param_3 = param_3 + -1) {

        *param_1 = *param_2;

        param_1[1] = param_2[1];

        param_1[2] = param_2[2];

        param_2 = param_2 + 3;

        param_1 = param_1 + 3;

      }

    }

    else if (param_3 != 0) {

      do {

        param_3 = param_3 + -1;

        *param_1 = (float)param_4[4] + *param_2;

        param_1[1] = param_2[1] + (float)param_4[8];

        param_1[2] = param_2[2] + (float)param_4[0xc];

        param_2 = param_2 + 3;

        param_1 = param_1 + 3;

      } while (param_3 != 0);

      return;

    }

  }

  else if ((uVar1 & 0x10) == 0) {

    if (param_3 != 0) {

      do {

        param_3 = param_3 + -1;

        *param_1 = (float)param_4[3] * param_2[2] +

                   (float)param_4[1] * *param_2 + param_2[1] * (float)param_4[2];

        param_1[1] = param_2[2] * (float)param_4[7] +

                     param_2[1] * (float)param_4[6] + *param_2 * (float)param_4[5];

        param_1[2] = (float)param_4[9] * *param_2 +

                     param_2[1] * (float)param_4[10] + (float)param_4[0xb] * param_2[2];

        param_2 = param_2 + 3;

        param_1 = param_1 + 3;

      } while (param_3 != 0);

      return;

    }

  }

  else if (param_3 != 0) {

    do {

      param_3 = param_3 + -1;

      *param_1 = (float)param_4[3] * param_2[2] +

                 (float)param_4[1] * *param_2 + param_2[1] * (float)param_4[2] + (float)param_4[4];

      param_1[1] = param_2[2] * (float)param_4[7] +

                   param_2[1] * (float)param_4[6] + *param_2 * (float)param_4[5] + (float)param_4[8]

      ;

      param_1[2] = (float)param_4[9] * *param_2 +

                   param_2[1] * (float)param_4[10] + (float)param_4[0xb] * param_2[2] +

                   (float)param_4[0xc];

      param_2 = param_2 + 3;

      param_1 = param_1 + 3;

    } while (param_3 != 0);

    return;

  }

  return;

}

/* ===== FUN_00542d10 @ 0x00542D10 ===== */
unkbyte10 FUN_00542d10(float param_1)



{

  unkbyte10 Var1;

  

  Var1 = fcos((float10)param_1);

  return Var1;

}

/* ===== FUN_00542d20 @ 0x00542D20 ===== */
float10 FUN_00542d20(float param_1)



{

  float10 fVar1;

  

  fVar1 = (float10)fsin((float10)param_1);

  return (float10)1.0 / fVar1;

}

/* ===== FUN_00542d30 @ 0x00542D30 ===== */
float10 FUN_00542d30(float param_1)



{

  return SQRT((float10)param_1);

}

/* ===== ANM_DumpCluster_3 @ 0x00542D40 ===== */
void ANM_DumpCluster_3(void)



{

  return;

}

/* ===== ANM_DumpCluster_5 @ 0x00542E00 ===== */
void ANM_DumpCluster_5(void)



{

  return;

}

/* ===== FUN_00542eb0 @ 0x00542EB0 ===== */
/* PS2 candidate: _InitSys (conf 0.516) */



void FUN_00542eb0(void)



{

  crt_printf_hooks_init();

  DAT_00630b58 = crt_cpu_features_check();

  _GLOBAL__D_Game_2();

  return;

}

/* ===== ANM_DumpCluster_4 @ 0x00542EC7 ===== */
void ANM_DumpCluster_4(void)



{

  return;

}

/* ===== crt_printf_hooks_init @ 0x00542EC8 ===== */
/* PS2 candidate: ANM_DumpCluster_9 (conf 0.777) */



void crt_printf_hooks_init(void)



{

  PTR_FUN_0054D5A8_0058138c = &LAB_00545d9e;

  PTR_FUN_0054D5A8_00581388 = __cfltcvt;

  PTR_FUN_0054D5A8_00581390 = __fassign;

  PTR_FUN_0054D5A8_00581394 = FUN_00545d44;

  PTR_FUN_0054D5A8_00581398 = &LAB_00545dec;

  PTR_FUN_0054D5A8_0058139c = __cfltcvt;

  return;

}

/* ===== __ftol @ 0x00542F00 ===== */
/* Library Function - Single Match

    __ftol

   

   Library: Visual Studio */



longlong __ftol(void)



{

  float10 in_ST0;

  

  return (longlong)ROUND(in_ST0);

}

/* ===== crt_sprintf @ 0x00542F27 ===== */
/* PS2 candidate: memset (conf 0.689) */



undefined4 crt_sprintf(undefined1 *param_1,undefined4 param_2)



{

  undefined4 uVar1;

  undefined1 *local_24;

  int local_20;

  undefined1 *local_1c;

  undefined4 local_18;

  

  local_1c = param_1;

  local_24 = param_1;

  local_18 = 0x42;

  local_20 = 0x7fffffff;

  uVar1 = _output(&local_24,param_2,&stack0x0000000c);

  local_20 = local_20 + -1;

  if (local_20 < 0) {

    _flsbuf(0,&local_24);

  }

  else {

    *local_24 = 0;

  }

  return uVar1;

}

/* ===== __rt_error_box @ 0x00542F79 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __rt_error_box(char *param_1,char *param_2)



{

  code *pcVar1;

  DWORD DVar2;

  size_t sVar3;

  size_t sVar4;

  int iVar5;

  undefined4 uStackY_358;

  char *pcStackY_354;

  char *pcStackY_350;

  CHAR local_324 [260];

  char local_220 [540];

  

  if ((DAT_00630bac == 1) || ((DAT_00630bac == 0 && (DAT_00581384 == 1)))) {

    if ((_DAT_0058114c & 0x10c) == 0) {

      crt_flush_ops();

    }

    crt_file_free_init();

    fclose();

  }

  else {

    strcpy();

    strcpy_2();

    strcpy_2();

    DVar2 = GetModuleFileNameA((HMODULE)0x0,local_324,0x104);

    if (DVar2 == 0) {

      strcpy();

    }

    sVar3 = _strlen(local_324);

    if (0x3c < sVar3 + 0xb) {

      sVar3 = _strlen(local_324);

      _strncpy((char *)((int)&uStackY_358 + sVar3 + 3),PTR_DAT_00580e34,3);

    }

    strcpy_2();

    strcpy_2();

    strcpy_2();

    sVar3 = _strlen(param_2);

    if (sVar3 + 8 < 0x3d) {

      strcpy_2();

    }

    else {

      _strncat(local_220,param_2,0x31);

      strcpy_2();

    }

    strcpy_2();

    strcpy_2();

    _strlen(local_220);

    FUN_00544a37();

    strcpy_2();

    strcpy_2();

    sVar3 = _strlen(param_1);

    pcStackY_350 = (char *)0x543143;

    sVar4 = _strlen(local_220);

    if (sVar3 + 0xb0 + sVar4 < 0x21d) {

      strcpy_2();

    }

    else {

      sVar3 = _strlen(local_220);

      _strncat(local_220,param_1,0x169 - sVar3);

      strcpy_2();

    }

    strcpy_2();

    strcpy_2();

    strcpy_2();

    strcpy_2();

    pcStackY_354 = local_220;

    pcStackY_350 = "Microsoft Visual C++ Runtime Library";

    uStackY_358 = 0x5431fb;

    iVar5 = __crtMessageBoxA();

    if (iVar5 == 3) {

      raise();

                    /* WARNING: Subroutine does not return */

      __exit(3);

    }

    if (iVar5 == 4) {

      pcVar1 = (code *)swi(3);

      (*pcVar1)();

      return;

    }

    if (iVar5 == 5) {

      return;

    }

  }

  crt_fatal_exit();

  return;

}

/* ===== FUN_00543270 @ 0x00543270 ===== */
undefined4 * FUN_00543270(undefined4 *param_1,undefined4 *param_2,uint param_3)



{

  uint uVar1;

  undefined4 *puVar2;

  

  if ((param_2 < param_1) && (param_1 < (undefined4 *)(param_3 + (int)param_2))) {

    param_2 = (undefined4 *)((param_3 - 4) + (int)param_2);

    puVar2 = (undefined4 *)((param_3 - 4) + (int)param_1);

    if (((uint)puVar2 & 3) == 0) {

      uVar1 = param_3 >> 2;

      param_3 = param_3 & 3;

      if (7 < uVar1) {

        for (; uVar1 != 0; uVar1 = uVar1 - 1) {

          *puVar2 = *param_2;

          param_2 = param_2 + -1;

          puVar2 = puVar2 + -1;

        }

        switch(param_3) {

        case 0:

          return param_1;

        case 2:

          goto switchD_00543427_caseD_2;

        case 3:

          goto switchD_00543427_caseD_3;

        }

        goto switchD_00543427_caseD_1;

      }

    }

    else {

      switch(param_3) {

      case 0:

        goto switchD_00543427_caseD_0;

      case 1:

        goto switchD_00543427_caseD_1;

      case 2:

        goto switchD_00543427_caseD_2;

      case 3:

        goto switchD_00543427_caseD_3;

      default:

        uVar1 = param_3 - ((uint)puVar2 & 3);

        switch((uint)puVar2 & 3) {

        case 1:

          param_3 = uVar1 & 3;

          *(undefined1 *)((int)puVar2 + 3) = *(undefined1 *)((int)param_2 + 3);

          param_2 = (undefined4 *)((int)param_2 + -1);

          uVar1 = uVar1 >> 2;

          puVar2 = (undefined4 *)((int)puVar2 - 1);

          if (7 < uVar1) {

            for (; uVar1 != 0; uVar1 = uVar1 - 1) {

              *puVar2 = *param_2;

              param_2 = param_2 + -1;

              puVar2 = puVar2 + -1;

            }

            switch(param_3) {

            case 0:

              return param_1;

            case 2:

              goto switchD_00543427_caseD_2;

            case 3:

              goto switchD_00543427_caseD_3;

            }

            goto switchD_00543427_caseD_1;

          }

          break;

        case 2:

          param_3 = uVar1 & 3;

          *(undefined1 *)((int)puVar2 + 3) = *(undefined1 *)((int)param_2 + 3);

          uVar1 = uVar1 >> 2;

          *(undefined1 *)((int)puVar2 + 2) = *(undefined1 *)((int)param_2 + 2);

          param_2 = (undefined4 *)((int)param_2 + -2);

          puVar2 = (undefined4 *)((int)puVar2 - 2);

          if (7 < uVar1) {

            for (; uVar1 != 0; uVar1 = uVar1 - 1) {

              *puVar2 = *param_2;

              param_2 = param_2 + -1;

              puVar2 = puVar2 + -1;

            }

            switch(param_3) {

            case 0:

              return param_1;

            case 2:

              goto switchD_00543427_caseD_2;

            case 3:

              goto switchD_00543427_caseD_3;

            }

            goto switchD_00543427_caseD_1;

          }

          break;

        case 3:

          param_3 = uVar1 & 3;

          *(undefined1 *)((int)puVar2 + 3) = *(undefined1 *)((int)param_2 + 3);

          *(undefined1 *)((int)puVar2 + 2) = *(undefined1 *)((int)param_2 + 2);

          uVar1 = uVar1 >> 2;

          *(undefined1 *)((int)puVar2 + 1) = *(undefined1 *)((int)param_2 + 1);

          param_2 = (undefined4 *)((int)param_2 + -3);

          puVar2 = (undefined4 *)((int)puVar2 - 3);

          if (7 < uVar1) {

            for (; uVar1 != 0; uVar1 = uVar1 - 1) {

              *puVar2 = *param_2;

              param_2 = param_2 + -1;

              puVar2 = puVar2 + -1;

            }

            switch(param_3) {

            case 0:

              return param_1;

            case 2:

              goto switchD_00543427_caseD_2;

            case 3:

              goto switchD_00543427_caseD_3;

            }

            goto switchD_00543427_caseD_1;

          }

        }

      }

    }

    switch(uVar1) {

    case 7:

      puVar2[7 - uVar1] = param_2[7 - uVar1];

    case 6:

      puVar2[6 - uVar1] = param_2[6 - uVar1];

    case 5:

      puVar2[5 - uVar1] = param_2[5 - uVar1];

    case 4:

      puVar2[4 - uVar1] = param_2[4 - uVar1];

    case 3:

      puVar2[3 - uVar1] = param_2[3 - uVar1];

    case 2:

      puVar2[2 - uVar1] = param_2[2 - uVar1];

    case 1:

      puVar2[1 - uVar1] = param_2[1 - uVar1];

      param_2 = param_2 + -uVar1;

      puVar2 = puVar2 + -uVar1;

    }

    switch(param_3) {

    case 1:

switchD_00543427_caseD_1:

      *(undefined1 *)((int)puVar2 + 3) = *(undefined1 *)((int)param_2 + 3);

      return param_1;

    case 2:

switchD_00543427_caseD_2:

      *(undefined1 *)((int)puVar2 + 3) = *(undefined1 *)((int)param_2 + 3);

      *(undefined1 *)((int)puVar2 + 2) = *(undefined1 *)((int)param_2 + 2);

      return param_1;

    case 3:

switchD_00543427_caseD_3:

      *(undefined1 *)((int)puVar2 + 3) = *(undefined1 *)((int)param_2 + 3);

      *(undefined1 *)((int)puVar2 + 2) = *(undefined1 *)((int)param_2 + 2);

      *(undefined1 *)((int)puVar2 + 1) = *(undefined1 *)((int)param_2 + 1);

      return param_1;

    }

switchD_00543427_caseD_0:

    return param_1;

  }

  puVar2 = param_1;

  if (((uint)param_1 & 3) == 0) {

    uVar1 = param_3 >> 2;

    param_3 = param_3 & 3;

    if (7 < uVar1) {

      for (; uVar1 != 0; uVar1 = uVar1 - 1) {

        *puVar2 = *param_2;

        param_2 = param_2 + 1;

        puVar2 = puVar2 + 1;

      }

      switch(param_3) {

      case 0:

        return param_1;

      case 2:

        goto switchD_005432a5_caseD_2;

      case 3:

        goto switchD_005432a5_caseD_3;

      }

      goto switchD_005432a5_caseD_1;

    }

  }

  else {

    switch(param_3) {

    case 0:

      goto switchD_005432a5_caseD_0;

    case 1:

      goto switchD_005432a5_caseD_1;

    case 2:

      goto switchD_005432a5_caseD_2;

    case 3:

      goto switchD_005432a5_caseD_3;

    default:

      uVar1 = (param_3 - 4) + ((uint)param_1 & 3);

      switch((uint)param_1 & 3) {

      case 1:

        param_3 = uVar1 & 3;

        *(undefined1 *)param_1 = *(undefined1 *)param_2;

        *(undefined1 *)((int)param_1 + 1) = *(undefined1 *)((int)param_2 + 1);

        uVar1 = uVar1 >> 2;

        *(undefined1 *)((int)param_1 + 2) = *(undefined1 *)((int)param_2 + 2);

        param_2 = (undefined4 *)((int)param_2 + 3);

        puVar2 = (undefined4 *)((int)param_1 + 3);

        if (7 < uVar1) {

          for (; uVar1 != 0; uVar1 = uVar1 - 1) {

            *puVar2 = *param_2;

            param_2 = param_2 + 1;

            puVar2 = puVar2 + 1;

          }

          switch(param_3) {

          case 0:

            return param_1;

          case 2:

            goto switchD_005432a5_caseD_2;

          case 3:

            goto switchD_005432a5_caseD_3;

          }

          goto switchD_005432a5_caseD_1;

        }

        break;

      case 2:

        param_3 = uVar1 & 3;

        *(undefined1 *)param_1 = *(undefined1 *)param_2;

        uVar1 = uVar1 >> 2;

        *(undefined1 *)((int)param_1 + 1) = *(undefined1 *)((int)param_2 + 1);

        param_2 = (undefined4 *)((int)param_2 + 2);

        puVar2 = (undefined4 *)((int)param_1 + 2);

        if (7 < uVar1) {

          for (; uVar1 != 0; uVar1 = uVar1 - 1) {

            *puVar2 = *param_2;

            param_2 = param_2 + 1;

            puVar2 = puVar2 + 1;

          }

          switch(param_3) {

          case 0:

            return param_1;

          case 2:

            goto switchD_005432a5_caseD_2;

          case 3:

            goto switchD_005432a5_caseD_3;

          }

          goto switchD_005432a5_caseD_1;

        }

        break;

      case 3:

        param_3 = uVar1 & 3;

        *(undefined1 *)param_1 = *(undefined1 *)param_2;

        param_2 = (undefined4 *)((int)param_2 + 1);

        uVar1 = uVar1 >> 2;

        puVar2 = (undefined4 *)((int)param_1 + 1);

        if (7 < uVar1) {

          for (; uVar1 != 0; uVar1 = uVar1 - 1) {

            *puVar2 = *param_2;

            param_2 = param_2 + 1;

            puVar2 = puVar2 + 1;

          }

          switch(param_3) {

          case 0:

            return param_1;

          case 2:

            goto switchD_005432a5_caseD_2;

          case 3:

            goto switchD_005432a5_caseD_3;

          }

          goto switchD_005432a5_caseD_1;

        }

      }

    }

  }

  switch(uVar1) {

  case 7:

    puVar2[uVar1 - 7] = param_2[uVar1 - 7];

  case 6:

    puVar2[uVar1 - 6] = param_2[uVar1 - 6];

  case 5:

    puVar2[uVar1 - 5] = param_2[uVar1 - 5];

  case 4:

    puVar2[uVar1 - 4] = param_2[uVar1 - 4];

  case 3:

    puVar2[uVar1 - 3] = param_2[uVar1 - 3];

  case 2:

    puVar2[uVar1 - 2] = param_2[uVar1 - 2];

  case 1:

    puVar2[uVar1 - 1] = param_2[uVar1 - 1];

    param_2 = param_2 + uVar1;

    puVar2 = puVar2 + uVar1;

  }

  switch(param_3) {

  case 1:

switchD_005432a5_caseD_1:

    *(undefined1 *)puVar2 = *(undefined1 *)param_2;

    return param_1;

  case 2:

switchD_005432a5_caseD_2:

    *(undefined1 *)puVar2 = *(undefined1 *)param_2;

    *(undefined1 *)((int)puVar2 + 1) = *(undefined1 *)((int)param_2 + 1);

    return param_1;

  case 3:

switchD_005432a5_caseD_3:

    *(undefined1 *)puVar2 = *(undefined1 *)param_2;

    *(undefined1 *)((int)puVar2 + 1) = *(undefined1 *)((int)param_2 + 1);

    *(undefined1 *)((int)puVar2 + 2) = *(undefined1 *)((int)param_2 + 2);

    return param_1;

  }

switchD_005432a5_caseD_0:

  return param_1;

}

/* ===== crt_dbl_round @ 0x005435A5 ===== */
float10 crt_dbl_round(double param_1)



{

  double dVar1;

  uint uVar2;

  int iVar3;

  float10 fVar4;

  undefined4 uVar5;

  

  uVar2 = crt_fnstcw(DAT_00580e40,0xffff);

  if ((param_1._6_2_ & 0x7ff0) == 0x7ff0) {

    iVar3 = _fpclass();

    if (0 < iVar3) {

      if (iVar3 < 3) {

        crt_fnstcw(uVar2,0xffff);

        return (float10)param_1;

      }

      if (iVar3 == 3) {

        fVar4 = (float10)_ftol2();

        return fVar4;

      }

    }

    dVar1 = param_1 + 1.0;

    uVar5 = 8;

  }

  else {

    fVar4 = (float10)__frnd(SUB84(param_1,0),(int)((ulonglong)param_1 >> 0x20));

    dVar1 = (double)fVar4;

    if ((dVar1 == param_1) || ((uVar2 & 0x20) != 0)) {

      crt_fnstcw(uVar2,0xffff);

      return (float10)dVar1;

    }

    uVar5 = 0x10;

  }

  fVar4 = (float10)_ftol2_r(uVar5,0xb,param_1,dVar1,uVar2);

  return fVar4;

}

/* ===== _strncpy @ 0x00543680 ===== */
/* Library Function - Single Match

    _strncpy

   

   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */



char * __cdecl _strncpy(char *_Dest,char *_Source,size_t _Count)



{

  uint uVar1;

  uint uVar2;

  char cVar3;

  uint uVar4;

  uint *puVar5;

  

  if (_Count == 0) {

    return _Dest;

  }

  puVar5 = (uint *)_Dest;

  if (((uint)_Source & 3) != 0) {

    while( true ) {

      uVar4 = *(uint *)_Source;

      _Source = (char *)((int)_Source + 1);

      *(char *)puVar5 = (char)uVar4;

      puVar5 = (uint *)((int)puVar5 + 1);

      _Count = _Count - 1;

      if (_Count == 0) {

        return _Dest;

      }

      if ((char)uVar4 == '\0') break;

      if (((uint)_Source & 3) == 0) {

        uVar4 = _Count >> 2;

        goto joined_r0x005436be;

      }

    }

    do {

      if (((uint)puVar5 & 3) == 0) {

        uVar4 = _Count >> 2;

        cVar3 = '\0';

        if (uVar4 == 0) goto LAB_005436fb;

        goto LAB_00543769;

      }

      *(char *)puVar5 = '\0';

      puVar5 = (uint *)((int)puVar5 + 1);

      _Count = _Count - 1;

    } while (_Count != 0);

    return _Dest;

  }

  uVar4 = _Count >> 2;

  if (uVar4 != 0) {

    do {

      uVar1 = *(uint *)_Source;

      uVar2 = *(uint *)_Source;

      _Source = (char *)((int)_Source + 4);

      if (((uVar1 ^ 0xffffffff ^ uVar1 + 0x7efefeff) & 0x81010100) != 0) {

        if ((char)uVar2 == '\0') {

          *puVar5 = 0;

joined_r0x00543765:

          while( true ) {

            uVar4 = uVar4 - 1;

            puVar5 = puVar5 + 1;

            if (uVar4 == 0) break;

LAB_00543769:

            *puVar5 = 0;

          }

          cVar3 = '\0';

          _Count = _Count & 3;

          if (_Count != 0) goto LAB_005436fb;

          return _Dest;

        }

        if ((char)(uVar2 >> 8) == '\0') {

          *puVar5 = uVar2 & 0xff;

          goto joined_r0x00543765;

        }

        if ((uVar2 & 0xff0000) == 0) {

          *puVar5 = uVar2 & 0xffff;

          goto joined_r0x00543765;

        }

        if ((uVar2 & 0xff000000) == 0) {

          *puVar5 = uVar2;

          goto joined_r0x00543765;

        }

      }

      *puVar5 = uVar2;

      puVar5 = puVar5 + 1;

      uVar4 = uVar4 - 1;

joined_r0x005436be:

    } while (uVar4 != 0);

    _Count = _Count & 3;

    if (_Count == 0) {

      return _Dest;

    }

  }

  do {

    cVar3 = (char)*(uint *)_Source;

    _Source = (char *)((int)_Source + 1);

    *(char *)puVar5 = cVar3;

    puVar5 = (uint *)((int)puVar5 + 1);

    if (cVar3 == '\0') {

      while (_Count = _Count - 1, _Count != 0) {

LAB_005436fb:

        *(char *)puVar5 = cVar3;

        puVar5 = (uint *)((int)puVar5 + 1);

      }

      return _Dest;

    }

    _Count = _Count - 1;

  } while (_Count != 0);

  return _Dest;

}

/* ===== _strchr @ 0x00543790 ===== */
/* Library Function - Single Match

    _strchr

   

   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */



char * __cdecl _strchr(char *_Str,int _Val)



{

  uint uVar1;

  char cVar2;

  uint uVar3;

  uint uVar4;

  uint *puVar5;

  

  while (((uint)_Str & 3) != 0) {

    uVar1 = *(uint *)_Str;

    if ((char)uVar1 == (char)_Val) {

      return (char *)(uint *)_Str;

    }

    _Str = (char *)((int)_Str + 1);

    if ((char)uVar1 == '\0') {

      return (char *)0x0;

    }

  }

  while( true ) {

    while( true ) {

      uVar1 = *(uint *)_Str;

      uVar4 = uVar1 ^ CONCAT22(CONCAT11((char)_Val,(char)_Val),CONCAT11((char)_Val,(char)_Val));

      uVar3 = uVar1 ^ 0xffffffff ^ uVar1 + 0x7efefeff;

      puVar5 = (uint *)((int)_Str + 4);

      if (((uVar4 ^ 0xffffffff ^ uVar4 + 0x7efefeff) & 0x81010100) != 0) break;

      _Str = (char *)puVar5;

      if ((uVar3 & 0x81010100) != 0) {

        if ((uVar3 & 0x1010100) != 0) {

          return (char *)0x0;

        }

        if ((uVar1 + 0x7efefeff & 0x80000000) == 0) {

          return (char *)0x0;

        }

      }

    }

    uVar1 = *(uint *)_Str;

    if ((char)uVar1 == (char)_Val) {

      return (char *)(uint *)_Str;

    }

    if ((char)uVar1 == '\0') {

      return (char *)0x0;

    }

    cVar2 = (char)(uVar1 >> 8);

    if (cVar2 == (char)_Val) {

      return (char *)((int)_Str + 1);

    }

    if (cVar2 == '\0') {

      return (char *)0x0;

    }

    cVar2 = (char)(uVar1 >> 0x10);

    if (cVar2 == (char)_Val) {

      return (char *)((int)_Str + 2);

    }

    if (cVar2 == '\0') break;

    cVar2 = (char)(uVar1 >> 0x18);

    if (cVar2 == (char)_Val) {

      return (char *)((int)_Str + 3);

    }

    _Str = (char *)puVar5;

    if (cVar2 == '\0') {

      return (char *)0x0;

    }

  }

  return (char *)0x0;

}

/* ===== editor_0054384c @ 0x0054384C ===== */
undefined4 editor_0054384c(int param_1)



{

  undefined4 uVar1;

  

  uVar1 = 0xffffffff;

  if ((*(byte *)(param_1 + 0xc) & 0x40) == 0) {

    crt_file_lock(param_1);

    uVar1 = __fclose_lk(param_1);

    crt_file_unlock(param_1);

  }

  else {

    *(undefined4 *)(param_1 + 0xc) = 0;

  }

  return uVar1;

}

/* ===== __fclose_lk @ 0x0054387D ===== */
/* Library Function - Single Match

    __fclose_lk

   

   Library: Visual Studio 2003 Release */



undefined4 __fclose_lk(FILE *param_1)



{

  int iVar1;

  undefined4 uVar2;

  

  uVar2 = 0xffffffff;

  if ((param_1->_flag & 0x83) != 0) {

    uVar2 = _flush(param_1);

    __freebuf(param_1);

    iVar1 = _close(param_1->_file);

    if (iVar1 < 0) {

      uVar2 = 0xffffffff;

    }

    else if (param_1->_tmpfname != (char *)0x0) {

      crt_free_ext(param_1->_tmpfname);

      param_1->_tmpfname = (char *)0x0;

    }

  }

  param_1->_flag = 0;

  return uVar2;

}

/* ===== FUN_005438c9 @ 0x005438C9 ===== */
undefined4 FUN_005438c9(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)



{

  undefined4 uVar1;

  

  crt_file_lock(param_4);

  uVar1 = crt_file_read_buf(param_1,param_2,param_3,param_4);

  crt_file_unlock(param_4);

  return uVar1;

}

/* ===== crt_file_read_buf @ 0x005438F8 ===== */
uint crt_file_read_buf(undefined1 *param_1,uint param_2,uint param_3,int *param_4)



{

  int *piVar1;

  uint uVar2;

  int iVar3;

  undefined1 *puVar4;

  uint uVar5;

  uint uVar6;

  

  piVar1 = param_4;

  uVar5 = param_2 * param_3;

  if (uVar5 == 0) {

    param_3 = 0;

  }

  else {

    puVar4 = param_1;

    param_1 = (undefined1 *)uVar5;

    if ((*(ushort *)(param_4 + 3) & 0x10c) == 0) {

      param_4 = (int *)0x1000;

    }

    else {

      param_4 = (int *)param_4[6];

    }

    do {

      if (((*(ushort *)(piVar1 + 3) & 0x10c) == 0) || (uVar2 = piVar1[1], uVar2 == 0)) {

        if (param_1 < param_4) {

          iVar3 = _filbuf(piVar1);

          if (iVar3 == -1) goto LAB_005439d4;

          *puVar4 = (char)iVar3;

          param_4 = (int *)piVar1[6];

          puVar4 = puVar4 + 1;

          param_1 = (undefined1 *)((int)param_1 - 1);

        }

        else {

          uVar2 = (uint)param_1;

          if (param_4 != (int *)0x0) {

            uVar2 = (int)param_1 - (uint)param_1 % (uint)param_4;

          }

          iVar3 = _read(piVar1[4],puVar4,uVar2);

          if (iVar3 == 0) {

            piVar1[3] = piVar1[3] | 0x10;

LAB_005439d4:

            return (uVar5 - (int)param_1) / param_2;

          }

          if (iVar3 == -1) {

            piVar1[3] = piVar1[3] | 0x20;

            goto LAB_005439d4;

          }

          param_1 = (undefined1 *)((int)param_1 - iVar3);

          puVar4 = puVar4 + iVar3;

        }

      }

      else {

        uVar6 = (uint)param_1;

        if (uVar2 <= param_1) {

          uVar6 = uVar2;

        }

        memmove(puVar4,*piVar1,uVar6);

        param_1 = (undefined1 *)((int)param_1 - uVar6);

        piVar1[1] = piVar1[1] - uVar6;

        *piVar1 = *piVar1 + uVar6;

        puVar4 = puVar4 + uVar6;

      }

    } while (param_1 != (undefined1 *)0x0);

  }

  return param_3;

}

/* ===== crt_file_open_alloc @ 0x005439E0 ===== */
undefined4 crt_file_open_alloc(undefined4 param_1,undefined4 param_2,undefined4 param_3)



{

  int iVar1;

  undefined4 uVar2;

  

  iVar1 = crt_allocosfhnd();

  if (iVar1 == 0) {

    return 0;

  }

  uVar2 = _sopen(param_1,param_2,param_3,iVar1);

  crt_file_unlock(iVar1);

  return uVar2;

}

/* ===== BinFileSeek_2 @ 0x00543A11 ===== */
void BinFileSeek_2(undefined4 param_1,undefined4 param_2)



{

  crt_file_open_alloc(param_1,param_2,0x40);

  return;

}

/* ===== FUN_00543a24 @ 0x00543A24 ===== */
undefined4 FUN_00543a24(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)



{

  undefined4 uVar1;

  

  crt_file_lock(param_4);

  uVar1 = crt_file_flush_write(param_1,param_2,param_3,param_4);

  crt_file_unlock(param_4);

  return uVar1;

}

/* ===== crt_file_flush_write @ 0x00543A53 ===== */
uint crt_file_flush_write(char *param_1,uint param_2,uint param_3,int *param_4)



{

  int *piVar1;

  int iVar2;

  uint uVar3;

  uint uVar4;

  uint uVar5;

  uint uVar6;

  

  piVar1 = param_4;

  uVar5 = param_2 * param_3;

  if (uVar5 == 0) {

    param_3 = 0;

  }

  else {

    uVar4 = uVar5;

    if ((*(ushort *)(param_4 + 3) & 0x10c) == 0) {

      param_4 = (int *)0x1000;

    }

    else {

      param_4 = (int *)param_4[6];

    }

    do {

      if (((piVar1[3] & 0x108U) == 0) || (uVar6 = piVar1[1], uVar6 == 0)) {

        if (param_4 <= uVar4) {

          if (((piVar1[3] & 0x108U) != 0) && (iVar2 = _flush(piVar1), iVar2 != 0)) {

LAB_00543b54:

            return (uVar5 - uVar4) / param_2;

          }

          uVar6 = uVar4;

          if (param_4 != (int *)0x0) {

            uVar6 = uVar4 - uVar4 % (uint)param_4;

          }

          uVar3 = _write(piVar1[4],param_1,uVar6);

          if ((uVar3 == 0xffffffff) || (uVar4 = uVar4 - uVar3, uVar3 < uVar6)) {

            piVar1[3] = piVar1[3] | 0x20;

            goto LAB_00543b54;

          }

          goto LAB_00543b0b;

        }

        iVar2 = _flsbuf((int)*param_1,piVar1);

        if (iVar2 == -1) goto LAB_00543b54;

        param_1 = param_1 + 1;

        param_4 = (int *)piVar1[6];

        uVar4 = uVar4 - 1;

        if ((int)param_4 < 1) {

          param_4 = (int *)0x1;

        }

      }

      else {

        uVar3 = uVar4;

        if (uVar6 <= uVar4) {

          uVar3 = uVar6;

        }

        memmove(*piVar1,param_1,uVar3);

        piVar1[1] = piVar1[1] - uVar3;

        *piVar1 = *piVar1 + uVar3;

        uVar4 = uVar4 - uVar3;

LAB_00543b0b:

        param_1 = param_1 + uVar3;

      }

    } while (uVar4 != 0);

  }

  return param_3;

}

/* ===== crt_file_free_init @ 0x00543B5D ===== */
undefined4 crt_file_free_init(undefined4 param_1,undefined4 param_2)



{

  undefined4 uVar1;

  undefined4 uVar2;

  

  crt_file_lock(param_1);

  uVar1 = crt_initio(param_1);

  uVar2 = _output(param_1,param_2,&stack0x0000000c);

  _freebuf(uVar1,param_1);

  crt_file_unlock(param_1);

  return uVar2;

}

/* ===== crt_dosmaperr_user @ 0x00543B99 ===== */
undefined4 crt_dosmaperr_user(LPCSTR param_1)



{

  BOOL BVar1;

  DWORD DVar2;

  

  BVar1 = DeleteFileA(param_1);

  if (BVar1 == 0) {

    DVar2 = GetLastError();

  }

  else {

    DVar2 = 0;

  }

  if (DVar2 != 0) {

    _dosmaperr(DVar2);

    return 0xffffffff;

  }

  return 0;

}

/* ===== crt_qsort_helper @ 0x00543BC3 ===== */
void crt_qsort_helper(uint *param_1,uint *param_2,uint param_3,code *param_4)



{

  uint uVar1;

  uint uVar2;

  uint uVar3;

  int iVar4;

  uint uVar5;

  uint local_fc [30];

  uint local_84 [30];

  uint local_c;

  int local_8;

  

  if ((param_2 < 2) || (param_3 == 0)) {

    return;

  }

  local_8 = 0;

  iVar4 = (int)param_2 - 1;

  param_2 = local_fc;

  uVar5 = iVar4 * param_3 + (int)param_1;

  uVar3 = (uint)param_1;

  param_1 = local_84;

LAB_00543c02:

  uVar2 = (uVar5 - uVar3) / param_3 + 1;

  if (8 < uVar2) {

    FUN_00543d65((uVar2 >> 1) * param_3 + uVar3,uVar3,param_3);

    uVar2 = param_3 + uVar5;

    local_c = uVar3;

LAB_00543c59:

    local_c = local_c + param_3;

    if (local_c <= uVar5) goto code_r0x00543c66;

    goto LAB_00543c71;

  }

  FUN_00543d17(uVar3,uVar5,param_3,param_4);

  goto LAB_00543c21;

code_r0x00543c66:

  iVar4 = (*param_4)(local_c,uVar3);

  if (iVar4 < 1) goto LAB_00543c59;

LAB_00543c71:

  do {

    uVar2 = uVar2 - param_3;

    if (uVar2 <= uVar3) break;

    iVar4 = (*param_4)(uVar2,uVar3);

  } while (-1 < iVar4);

  if (local_c <= uVar2) {

    FUN_00543d65(local_c,uVar2,param_3);

    goto LAB_00543c59;

  }

  FUN_00543d65(uVar3,uVar2,param_3);

  uVar1 = local_c;

  if ((int)((uVar2 - uVar3) + -1) < (int)(uVar5 - local_c)) {

    if (local_c < uVar5) {

      local_8 = local_8 + 1;

      *param_2 = local_c;

      *param_1 = uVar5;

      param_1 = param_1 + 1;

      param_2 = param_2 + 1;

    }

    if (param_3 + uVar3 < uVar2) {

      uVar5 = uVar2 - param_3;

      goto LAB_00543c02;

    }

  }

  else {

    if (uVar3 + param_3 < uVar2) {

      local_8 = local_8 + 1;

      *param_2 = uVar3;

      *param_1 = uVar2 - param_3;

      param_1 = param_1 + 1;

      param_2 = param_2 + 1;

    }

    uVar3 = uVar1;

    if (uVar1 < uVar5) goto LAB_00543c02;

  }

LAB_00543c21:

  local_8 = local_8 + -1;

  param_2 = param_2 + -1;

  param_1 = param_1 + -1;

  if (local_8 < 0) {

    return;

  }

  uVar5 = *param_1;

  uVar3 = *param_2;

  goto LAB_00543c02;

}

/* ===== FUN_00543d17 @ 0x00543D17 ===== */
void FUN_00543d17(uint param_1,uint param_2,int param_3,code *param_4)



{

  int iVar1;

  uint uVar2;

  uint uVar3;

  

  for (; uVar2 = param_1, uVar3 = param_1, param_1 < param_2; param_2 = param_2 - param_3) {

    while (uVar3 = uVar3 + param_3, uVar3 <= param_2) {

      iVar1 = (*param_4)(uVar3,uVar2);

      if (0 < iVar1) {

        uVar2 = uVar3;

      }

    }

    FUN_00543d65(uVar2,param_2,param_3);

  }

  return;

}

/* ===== FUN_00543d65 @ 0x00543D65 ===== */
void FUN_00543d65(undefined1 *param_1,undefined1 *param_2,int param_3)



{

  undefined1 uVar1;

  

  if (param_1 != param_2) {

    for (; param_3 != 0; param_3 = param_3 + -1) {

      uVar1 = *param_1;

      *param_1 = *param_2;

      param_1 = param_1 + 1;

      *param_2 = uVar1;

      param_2 = param_2 + 1;

    }

  }

  return;

}

/* ===== _strrchr @ 0x00543DA0 ===== */
/* Library Function - Single Match

    _strrchr

   

   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */



char * __cdecl _strrchr(char *_Str,int _Ch)



{

  char cVar1;

  int iVar2;

  char *pcVar3;

  char *pcVar4;

  

  iVar2 = -1;

  do {

    pcVar4 = _Str;

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    pcVar4 = _Str + 1;

    cVar1 = *_Str;

    _Str = pcVar4;

  } while (cVar1 != '\0');

  iVar2 = -(iVar2 + 1);

  pcVar4 = pcVar4 + -1;

  do {

    pcVar3 = pcVar4;

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    pcVar3 = pcVar4 + -1;

    cVar1 = *pcVar4;

    pcVar4 = pcVar3;

  } while ((char)_Ch != cVar1);

  pcVar3 = pcVar3 + 1;

  if (*pcVar3 != (char)_Ch) {

    pcVar3 = (char *)0x0;

  }

  return pcVar3;

}

/* ===== crt_getptd_user @ 0x00543DC7 ===== */
void crt_getptd_user(undefined4 param_1)



{

  int iVar1;

  

  iVar1 = __getptd();

  *(undefined4 *)(iVar1 + 0x14) = param_1;

  return;

}

/* ===== _rand @ 0x00543DD4 ===== */
/* Library Function - Single Match

    _rand

   

   Libraries: Visual Studio 2003 Release, Visual Studio 2005 Release, Visual Studio 2008 Release */



int __cdecl _rand(void)



{

  int iVar1;

  uint uVar2;

  

  iVar1 = __getptd();

  uVar2 = *(int *)(iVar1 + 0x14) * 0x343fd + 0x269ec3;

  *(uint *)(iVar1 + 0x14) = uVar2;

  return uVar2 >> 0x10 & 0x7fff;

}

/* ===== FUN_00543e00 @ 0x00543E00 ===== */
/* WARNING: Unable to track spacebase fully for stack */



void FUN_00543e00(void)



{

  uint in_EAX;

  undefined1 *puVar1;

  undefined4 unaff_retaddr;

  

  puVar1 = &stack0x00000004;

  for (; 0xfff < in_EAX; in_EAX = in_EAX - 0x1000) {

    puVar1 = puVar1 + -0x1000;

  }

  *(undefined4 *)(puVar1 + (-4 - in_EAX)) = unaff_retaddr;

  return;

}

/* ===== AddHud__4cHudP8cHudIcon_6 @ 0x00543E3A ===== */
void AddHud__4cHudP8cHudIcon_6(int param_1,int param_2,int param_3,int param_4)



{

  AudioMusicStreamPlay__Fiiii_3(param_1,param_2,param_3,param_4);

  return;

}

/* ===== FUN_00543e70 @ 0x00543E70 ===== */
/* PS2 candidate: powf (conf 0.349) */



void FUN_00543e70(void)



{

  float10 in_ST0;

  float10 in_ST1;

  

  crt_pow_main((double)in_ST1,(double)in_ST0);

  return;

}

/* ===== crt_pow_main @ 0x00543E92 ===== */
undefined4 crt_pow_main(int param_1,uint param_2,int param_3,uint param_4)



{

  uint in_EAX;

  uint uVar1;

  undefined4 uVar2;

  byte extraout_CL;

  char extraout_CL_00;

  uint extraout_ECX;

  int extraout_ECX_00;

  int iVar3;

  int extraout_ECX_01;

  bool bVar4;

  short in_FPUControlWord;

  float10 extraout_ST0;

  float10 fVar5;

  float10 extraout_ST1;

  float10 extraout_ST1_00;

  float10 extraout_ST1_01;

  float10 fVar6;

  unkbyte10 in_ST7;

  undefined1 local_78 [20];

  undefined4 uStack_64;

  undefined1 auStack_e [10];

  short local_4;

  undefined2 uStack_2;

  

  _local_4 = CONCAT22((short)(in_EAX >> 0x10),in_FPUControlWord);

  uVar1 = in_EAX;

  if (in_FPUControlWord != 0x27f) {

    auStack_e._6_4_ = 0x543ea6;

    in_EAX = ANM_DumpCluster_7();

    uVar1 = extraout_ECX;

  }

  bVar4 = (uVar1 & 0x7ff00000) == 0x7ff00000;

  if (bVar4) {

    if ((in_EAX & 0xfffff) == 0 && param_3 == 0) {

      auStack_e._6_4_ = 0x543f6f;

      fVar5 = (float10)__fload_withFB();

      iVar3 = extraout_ECX_01;

      fVar6 = extraout_ST1_01;

      goto LAB_00543f6f;

    }

    auStack_e._6_4_ = 0x543f32;

    fVar5 = (float10)__fload_withFB();

    if ((param_4 & 0x80000) == 0) {

      iVar3 = extraout_ECX_00 + 1;

      fVar6 = extraout_ST1_00;

      goto LAB_00543f6f;

    }

LAB_00543f3c:

    uVar2 = 1;

  }

  else {

    auStack_e._6_4_ = 0x543ec1;

    uVar1 = __fload_withFB();

    if (!bVar4) {

      if (((uVar1 & 0x7ff00000) != 0) || ((param_2 & 0xfffff) != 0 || param_1 != 0)) {

        fVar5 = extraout_ST0;

        if ((param_2 & 0x80000000) != 0) {

          auStack_e._6_4_ = 0x544047;

          fVar5 = (float10)FUN_00544065();

          fVar5 = -fVar5;

          if (extraout_CL_00 == '\0') {

            uVar2 = 1;

            goto LAB_00543f0a;

          }

        }

        log2(fVar5);

        auStack_e._6_4_ = 0x543ee6;

        uVar2 = crt_exp2();

        if (DAT_00630b54 != 0) {

          return uVar2;

        }

        uVar2 = crt_frndint_user();

        return uVar2;

      }

      if ((param_4 & 0x7ff00000) == 0) {

        if ((param_4 & 0xfffff) != 0 || param_3 != 0) {

          uVar2 = ANM_DumpCluster_8();

          return uVar2;

        }

        uVar2 = ANM_DumpCluster_8();

        return uVar2;

      }

      auStack_e._6_4_ = 0x543fed;

      uVar2 = FUN_00544065();

      if ((param_4 & 0x80000000) == 0) {

        if ((param_2._3_1_ >> 7 & extraout_CL) == 0) {

          return uVar2;

        }

        uVar2 = ANM_DumpCluster_8();

        return uVar2;

      }

      uVar2 = 2;

      goto LAB_00543f0a;

    }

    iVar3 = 0;

    fVar5 = extraout_ST0;

    fVar6 = extraout_ST1;

LAB_00543f6f:

    if (((param_2 & 0x7ff00000) == 0x7ff00000) && ((param_2 & 0xfffff) != 0 || param_1 != 0)) {

      if ((param_2 & 0x80000) != 0) goto LAB_00543f3c;

    }

    else if (iVar3 == 0) {

      uStack_64 = 0x543f9d;

      auStack_e = (undefined1  [10])in_ST7;

      iVar3 = crt_pow_special((double)fVar5,(double)fVar6,local_78);

      if (iVar3 == 0) {

        return 0;

      }

      uVar2 = 1;

      goto LAB_00543f0a;

    }

    uVar2 = 7;

  }

LAB_00543f0a:

  if (DAT_00630b54 != 0) {

    return uVar2;

  }

  auStack_e._6_4_ = 0x543f27;

  uVar2 = crt_frndint();

  return uVar2;

}

/* ===== FUN_00544065 @ 0x00544065 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_00544065(void)



{

  float10 in_ST0;

  

  if (ROUND(in_ST0) == in_ST0) {

    return;

  }

  return;

}

/* ===== crt_scanf_entry @ 0x0054408D ===== */
void crt_scanf_entry(char *param_1,undefined4 param_2)



{

  char *local_24;

  size_t local_20;

  char *local_1c;

  undefined4 local_18;

  

  local_18 = 0x49;

  local_1c = param_1;

  local_24 = param_1;

  local_20 = _strlen(param_1);

  _input(&local_24,param_2,&stack0x0000000c);

  return;

}

/* ===== crt_scanf_getchar2 @ 0x005440C1 ===== */
char * crt_scanf_getchar2(char *param_1,int param_2,undefined4 *param_3)



{

  int *piVar1;

  uint uVar2;

  char *pcVar3;

  

  if (param_2 < 1) {

    param_1 = (char *)0x0;

  }

  else {

    crt_file_lock(param_3);

    pcVar3 = param_1;

    do {

      param_2 = param_2 + -1;

      if (param_2 == 0) break;

      piVar1 = param_3 + 1;

      *piVar1 = *piVar1 + -1;

      if (*piVar1 < 0) {

        uVar2 = _filbuf(param_3);

      }

      else {

        uVar2 = (uint)*(byte *)*param_3;

        *param_3 = (byte *)*param_3 + 1;

      }

      if (uVar2 == 0xffffffff) {

        if (pcVar3 == param_1) {

          param_1 = (char *)0x0;

          goto LAB_00544115;

        }

        break;

      }

      *pcVar3 = (char)uVar2;

      pcVar3 = pcVar3 + 1;

    } while ((char)uVar2 != '\n');

    *pcVar3 = '\0';

LAB_00544115:

    crt_file_unlock(param_3);

  }

  return param_1;

}

/* ===== FUN_00544123 @ 0x00544123 ===== */
uint FUN_00544123(int param_1,uint param_2)



{

  int iVar1;

  undefined4 in_ECX;

  undefined4 uVar2;

  undefined4 local_8;

  

  if (param_1 + 1U < 0x101) {

    param_1._2_2_ = *(ushort *)(PTR_DAT_00580eac + param_1 * 2);

  }

  else {

    if ((PTR_DAT_00580eac[(param_1 >> 8 & 0xffU) * 2 + 1] & 0x80) == 0) {

      local_8 = CONCAT31((int3)((uint)in_ECX >> 8),(char)param_1) & 0xffff00ff;

      uVar2 = 1;

    }

    else {

      local_8._0_2_ = CONCAT11((char)param_1,(char)((uint)param_1 >> 8));

      local_8 = CONCAT22((short)((uint)in_ECX >> 0x10),(undefined2)local_8) & 0xff00ffff;

      uVar2 = 2;

    }

    iVar1 = crt_getstringtype(1,&local_8,uVar2,(int)&param_1 + 2,0,0,1);

    if (iVar1 == 0) {

      return 0;

    }

  }

  return param_1._2_2_ & param_2;

}

/* ===== FUN_00544198 @ 0x00544198 ===== */
int FUN_00544198(byte *param_1)



{

  uint uVar1;

  uint uVar2;

  int iVar3;

  uint uVar4;

  byte *pbVar5;

  

  while( true ) {

    if (DAT_005810b8 < 2) {

      uVar1 = (byte)PTR_DAT_00580eac[(uint)*param_1 * 2] & 8;

    }

    else {

      uVar1 = FUN_00544123(*param_1,8);

    }

    if (uVar1 == 0) break;

    param_1 = param_1 + 1;

  }

  uVar1 = (uint)*param_1;

  pbVar5 = param_1 + 1;

  if ((uVar1 == 0x2d) || (uVar4 = uVar1, uVar1 == 0x2b)) {

    uVar4 = (uint)*pbVar5;

    pbVar5 = param_1 + 2;

  }

  iVar3 = 0;

  while( true ) {

    if (DAT_005810b8 < 2) {

      uVar2 = (byte)PTR_DAT_00580eac[uVar4 * 2] & 4;

    }

    else {

      uVar2 = FUN_00544123(uVar4,4);

    }

    if (uVar2 == 0) break;

    iVar3 = (uVar4 - 0x30) + iVar3 * 10;

    uVar4 = (uint)*pbVar5;

    pbVar5 = pbVar5 + 1;

  }

  if (uVar1 == 0x2d) {

    iVar3 = -iVar3;

  }

  return iVar3;

}

/* ===== ANM_BinderDestroy_3 @ 0x00544223 ===== */
void ANM_BinderDestroy_3(undefined4 param_1)



{

  FUN_00544198(param_1);

  return;

}

/* ===== crt_scanf_float2 @ 0x0054422E ===== */
float10 crt_scanf_float2(byte *param_1)



{

  uint uVar1;

  size_t sVar2;

  int iVar3;

  undefined4 uVar4;

  undefined4 uVar5;

  undefined1 local_1c [24];

  

  while( true ) {

    if (DAT_005810b8 < 2) {

      uVar1 = (byte)PTR_DAT_00580eac[(uint)*param_1 * 2] & 8;

    }

    else {

      uVar1 = FUN_00544123(*param_1,8);

    }

    if (uVar1 == 0) break;

    param_1 = param_1 + 1;

  }

  uVar5 = 0;

  uVar4 = 0;

  sVar2 = _strlen((char *)param_1);

  iVar3 = crt_scanf_float(local_1c,param_1,sVar2,uVar4,uVar5);

  return (float10)*(double *)(iVar3 + 0x10);

}

/* ===== _malloc @ 0x00544285 ===== */
/* Library Function - Single Match

    _malloc

   

   Library: Visual Studio 2003 Release */



void * __cdecl _malloc(size_t _Size)



{

  void *pvVar1;

  

  pvVar1 = __nh_malloc(_Size,DAT_00630bdc);

  return pvVar1;

}

/* ===== __nh_malloc @ 0x00544297 ===== */
/* Library Function - Single Match

    __nh_malloc

   

   Library: Visual Studio 2003 Release */



void * __cdecl __nh_malloc(size_t _Size,int _NhFlag)



{

  void *pvVar1;

  int iVar2;

  

  if (_Size < 0xffffffe1) {

    do {

      pvVar1 = (void *)crt_malloc_ext(_Size);

      if (pvVar1 != (void *)0x0) {

        return pvVar1;

      }

      if (_NhFlag == 0) {

        return (void *)0x0;

      }

      iVar2 = FUN_0054aac3(_Size);

    } while (iVar2 != 0);

  }

  return (void *)0x0;

}

/* ===== crt_malloc_ext @ 0x005442C3 ===== */
void crt_malloc_ext(uint param_1)



{

  int iVar1;

  uint dwBytes;

  void *local_14;

  undefined1 *puStack_10;

  undefined *puStack_c;

  undefined4 local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &DAT_00552320;

  puStack_10 = &LAB_00544c84;

  local_14 = ExceptionList;

  if (DAT_006579ec == 3) {

    ExceptionList = &local_14;

    if (param_1 <= DAT_006579e4) {

      ExceptionList = &local_14;

      _lock(9);

      local_8 = 0;

      iVar1 = __sbh_alloc_block(param_1);

      local_8 = 0xffffffff;

      FUN_0054432A();

      if (iVar1 != 0) {

        ExceptionList = local_14;

        return;

      }

    }

  }

  else {

    ExceptionList = &local_14;

    if (DAT_006579ec == 2) {

      if (param_1 == 0) {

        dwBytes = 0x10;

      }

      else {

        dwBytes = param_1 + 0xf & 0xfffffff0;

      }

      ExceptionList = &local_14;

      if (dwBytes <= DAT_0058386c) {

        ExceptionList = &local_14;

        _lock(9);

        local_8 = 1;

        iVar1 = crt_heap_alloc_sbh(dwBytes >> 4);

        local_8 = 0xffffffff;

        FUN_00544389();

        if (iVar1 != 0) {

          ExceptionList = local_14;

          return;

        }

      }

      goto LAB_005443a2;

    }

  }

  if (param_1 == 0) {

    param_1 = 1;

  }

  dwBytes = param_1 + 0xf & 0xfffffff0;

LAB_005443a2:

  HeapAlloc(DAT_006579e8,0,dwBytes);

  ExceptionList = local_14;

  return;

}

/* ===== FUN_0054432A @ 0x0054432A ===== */
void FUN_0054432A(void)



{

  _unlock(9);

  return;

}

/* ===== FUN_00544389 @ 0x00544389 ===== */
void FUN_00544389(void)



{

  _unlock(9);

  return;

}

/* ===== crt_free_ext @ 0x005443BF ===== */
void crt_free_ext(LPVOID param_1)



{

  int iVar1;

  undefined4 local_2c;

  int local_28;

  undefined4 local_24;

  int local_20;

  void *local_14;

  undefined1 *puStack_10;

  undefined *puStack_c;

  undefined4 local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &DAT_00552338;

  puStack_10 = &LAB_00544c84;

  local_14 = ExceptionList;

  if (param_1 == (LPVOID)0x0) {

    return;

  }

  if (DAT_006579ec == 3) {

    ExceptionList = &local_14;

    _lock(9);

    local_8 = 0;

    local_20 = __sbh_find_block(param_1);

    if (local_20 != 0) {

      __sbh_free_block(local_20,param_1);

    }

    local_8 = 0xffffffff;

    FUN_00544429();

    iVar1 = local_20;

  }

  else {

    ExceptionList = &local_14;

    if (DAT_006579ec != 2) goto LAB_0054448b;

    ExceptionList = &local_14;

    _lock(9);

    local_8 = 1;

    local_28 = crt_sbh_addr_lookup(param_1,&local_2c,&local_24);

    if (local_28 != 0) {

      crt_sbh_decommit_page(local_2c,local_24,local_28);

    }

    local_8 = 0xffffffff;

    FUN_00544481();

    iVar1 = local_28;

  }

  if (iVar1 != 0) {

    ExceptionList = local_14;

    return;

  }

LAB_0054448b:

  HeapFree(DAT_006579e8,0,param_1);

  ExceptionList = local_14;

  return;

}

/* ===== FUN_00544429 @ 0x00544429 ===== */
void FUN_00544429(void)



{

  _unlock(9);

  return;

}

/* ===== FUN_00544481 @ 0x00544481 ===== */
void FUN_00544481(void)



{

  _unlock(9);

  return;

}

/* ===== crt_lock_simple @ 0x005444A8 ===== */
int crt_lock_simple(int param_1)



{

  bool bVar1;

  

  if (DAT_00630c5c == 0) {

    if ((0x60 < param_1) && (param_1 < 0x7b)) {

      return param_1 + -0x20;

    }

  }

  else {

    InterlockedIncrement((LONG *)&DAT_006579c8);

    bVar1 = DAT_006579c4 != 0;

    if (bVar1) {

      InterlockedDecrement((LONG *)&DAT_006579c8);

      _lock(0x13);

    }

    param_1 = FUN_00544517(param_1);

    if (bVar1) {

      _unlock(0x13);

    }

    else {

      InterlockedDecrement((LONG *)&DAT_006579c8);

    }

  }

  return param_1;

}

/* ===== FUN_00544517 @ 0x00544517 ===== */
uint FUN_00544517(uint param_1)



{

  uint uVar1;

  uint uVar2;

  int iVar3;

  undefined4 uVar4;

  uint local_8;

  

  uVar1 = param_1;

  if (DAT_00630c5c == 0) {

    if ((0x60 < (int)param_1) && ((int)param_1 < 0x7b)) {

      uVar1 = param_1 - 0x20;

    }

  }

  else {

    if ((int)param_1 < 0x100) {

      if (DAT_005810b8 < 2) {

        uVar2 = (byte)PTR_DAT_00580eac[param_1 * 2] & 2;

      }

      else {

        uVar2 = FUN_00544123(param_1,2);

      }

      if (uVar2 == 0) {

        return uVar1;

      }

    }

    if ((PTR_DAT_00580eac[((int)uVar1 >> 8 & 0xffU) * 2 + 1] & 0x80) == 0) {

      param_1 = CONCAT31((int3)(param_1 >> 8),(char)uVar1) & 0xffff00ff;

      uVar4 = 1;

    }

    else {

      uVar2 = param_1 >> 0x10;

      param_1._0_2_ = CONCAT11((char)uVar1,(char)(uVar1 >> 8));

      param_1 = CONCAT22((short)uVar2,(undefined2)param_1) & 0xff00ffff;

      uVar4 = 2;

    }

    iVar3 = crt_lcmapstring(DAT_00630c5c,0x200,&param_1,uVar4,&local_8,3,0,1);

    if (iVar3 != 0) {

      if (iVar3 == 1) {

        uVar1 = local_8 & 0xff;

      }

      else {

        uVar1 = local_8 & 0xffff;

      }

    }

  }

  return uVar1;

}

/* ===== FUN_005445f0 @ 0x005445F0 ===== */
void FUN_005445f0(void)



{

  float10 in_ST0;

  

  FUN_00549b78((double)in_ST0);

  anm_dump_ext();

  return;

}

/* ===== anm_dump_ext @ 0x0054460D ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



float10 anm_dump_ext(int param_1,uint param_2)



{

  uint in_EAX;

  bool in_ZF;

  short in_FPUControlWord;

  float10 in_ST0;

  float10 extraout_ST0;

  float10 fVar1;

  

  if (in_ZF) {

    if (((in_EAX & 0xfffff) != 0) || (fVar1 = _DAT_00581640, param_1 != 0)) {

      fVar1 = (float10)FUN_00549b1c();

    }

LAB_0054469c:

    if (DAT_00630b54 == 0) {

      fVar1 = (float10)__startOneArgErrorHandling();

      return fVar1;

    }

  }

  else {

    if (in_FPUControlWord != 0x27f) {

      in_EAX = ANM_DumpCluster_7();

      in_ST0 = extraout_ST0;

    }

    if (in_EAX < 0x3ff00000) {

      fVar1 = (float10)fpatan(SQRT(((float10)1 - in_ST0) * ((float10)1 + in_ST0)),in_ST0);

    }

    else {

      fVar1 = _DAT_00581640;

      if ((0x3ff00000 < in_EAX) || ((param_2 & 0xfffff) != 0 || param_1 != 0)) goto LAB_0054469c;

      if ((param_2 & 0x80000000) == 0) {

        fVar1 = (float10)0;

      }

      else {

        fVar1 = (float10)3.141592653589793;

      }

    }

    if (DAT_00630b54 == 0) {

      fVar1 = (float10)__math_exit();

      return fVar1;

    }

  }

  return fVar1;

}

/* ===== _strncat @ 0x005446C0 ===== */
/* Library Function - Single Match

    _strncat

   

   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */



char * __cdecl _strncat(char *_Dest,char *_Source,size_t _Count)



{

  byte bVar1;

  uint uVar2;

  uint uVar3;

  uint uVar4;

  uint *puVar5;

  uint *puVar6;

  

  puVar5 = (uint *)_Dest;

  if (_Count == 0) {

    return _Dest;

  }

  do {

    if (((uint)puVar5 & 3) == 0) goto LAB_005446ea;

    uVar4 = *puVar5;

    puVar5 = (uint *)((int)puVar5 + 1);

  } while ((byte)uVar4 != 0);

  goto LAB_0054471b;

  while( true ) {

    if ((uVar4 & 0xff0000) == 0) {

      puVar6 = (uint *)((int)puVar6 + 2);

      goto LAB_0054472b;

    }

    if ((uVar4 & 0xff000000) == 0) break;

LAB_005446ea:

    do {

      puVar6 = puVar5;

      puVar5 = puVar6 + 1;

    } while (((*puVar6 ^ 0xffffffff ^ *puVar6 + 0x7efefeff) & 0x81010100) == 0);

    uVar4 = *puVar6;

    if ((char)uVar4 == '\0') goto LAB_0054472b;

    if ((char)(uVar4 >> 8) == '\0') {

      puVar6 = (uint *)((int)puVar6 + 1);

      goto LAB_0054472b;

    }

  }

LAB_0054471b:

  puVar6 = (uint *)((int)puVar5 + -1);

LAB_0054472b:

  if (((uint)_Source & 3) == 0) {

    uVar3 = _Count >> 2;

  }

  else {

    do {

      bVar1 = (byte)*(uint *)_Source;

      uVar4 = (uint)bVar1;

      _Source = (char *)((int)_Source + 1);

      if (bVar1 == 0) goto LAB_0054477a;

      *(byte *)puVar6 = bVar1;

      puVar6 = (uint *)((int)puVar6 + 1);

      _Count = _Count - 1;

      if (_Count == 0) goto LAB_00544770;

    } while (((uint)_Source & 3) != 0);

    uVar3 = _Count >> 2;

  }

  do {

    if (uVar3 == 0) {

      for (uVar4 = _Count & 3; uVar4 != 0; uVar4 = uVar4 - 1) {

        uVar3 = *(uint *)_Source;

        _Source = (char *)((int)_Source + 1);

        *(byte *)puVar6 = (byte)uVar3;

        puVar6 = (uint *)((int)puVar6 + 1);

        if ((byte)uVar3 == 0) {

          return _Dest;

        }

      }

LAB_00544770:

      *(byte *)puVar6 = 0;

      return _Dest;

    }

    uVar2 = *(uint *)_Source;

    uVar4 = *(uint *)_Source;

    _Source = (char *)((int)_Source + 4);

    if (((uVar2 ^ 0xffffffff ^ uVar2 + 0x7efefeff) & 0x81010100) != 0) {

      if ((char)uVar4 == '\0') {

LAB_0054477a:

        *(byte *)puVar6 = (byte)uVar4;

        return _Dest;

      }

      if ((char)(uVar4 >> 8) == '\0') {

        *(short *)puVar6 = (short)uVar4;

        return _Dest;

      }

      if ((uVar4 & 0xff0000) == 0) {

        *(short *)puVar6 = (short)uVar4;

        *(byte *)((int)puVar6 + 2) = 0;

        return _Dest;

      }

      if ((uVar4 & 0xff000000) == 0) {

        *puVar6 = uVar4;

        return _Dest;

      }

    }

    *puVar6 = uVar4;

    puVar6 = puVar6 + 1;

    uVar3 = uVar3 - 1;

  } while( true );

}

/* ===== crt_flsbuf_ext @ 0x005447E3 ===== */
uint crt_flsbuf_ext(uint param_1,int *param_2)



{

  int *piVar1;

  uint uVar2;

  

  crt_file_lock(param_2);

  piVar1 = param_2 + 1;

  *piVar1 = *piVar1 + -1;

  if (*piVar1 < 0) {

    uVar2 = _flsbuf(param_1,param_2);

  }

  else {

    uVar2 = param_1 & 0xff;

    *(undefined1 *)*param_2 = (undefined1)param_1;

    *param_2 = *param_2 + 1;

  }

  crt_file_unlock(param_2);

  return uVar2;

}

/* ===== crt_strcpy_ext @ 0x0054481E ===== */
HANDLE crt_strcpy_ext(LPCSTR param_1,uint *param_2)



{

  HANDLE pvVar1;

  DWORD DVar2;

  undefined4 *puVar3;

  uint uVar4;

  _WIN32_FIND_DATAA local_144;

  

  pvVar1 = FindFirstFileA(param_1,&local_144);

  if (pvVar1 != (HANDLE)0xffffffff) {

    *param_2 = -(uint)(local_144.dwFileAttributes != 0x80) & local_144.dwFileAttributes;

    uVar4 = ___timet_from_ft(&local_144.ftCreationTime);

    param_2[1] = uVar4;

    uVar4 = ___timet_from_ft(&local_144.ftLastAccessTime);

    param_2[2] = uVar4;

    uVar4 = ___timet_from_ft(&local_144.ftLastWriteTime);

    param_2[3] = uVar4;

    param_2[4] = local_144.nFileSizeLow;

    strcpy(param_2 + 5,local_144.cFileName);

    return pvVar1;

  }

  DVar2 = GetLastError();

  if (DVar2 < 2) {

LAB_0054485c:

    puVar3 = (undefined4 *)_errno();

    *puVar3 = 0x16;

  }

  else {

    if (3 < DVar2) {

      if (DVar2 == 8) {

        puVar3 = (undefined4 *)_errno();

        *puVar3 = 0xc;

        return (HANDLE)0xffffffff;

      }

      if (DVar2 != 0x12) goto LAB_0054485c;

    }

    puVar3 = (undefined4 *)_errno();

    *puVar3 = 2;

  }

  return (HANDLE)0xffffffff;

}

/* ===== crt_strcpy_errno @ 0x005448EB ===== */
undefined4 crt_strcpy_errno(HANDLE param_1,uint *param_2)



{

  BOOL BVar1;

  DWORD DVar2;

  undefined4 *puVar3;

  uint uVar4;

  _WIN32_FIND_DATAA local_144;

  

  BVar1 = FindNextFileA(param_1,&local_144);

  if (BVar1 != 0) {

    *param_2 = -(uint)(local_144.dwFileAttributes != 0x80) & local_144.dwFileAttributes;

    uVar4 = ___timet_from_ft(&local_144.ftCreationTime);

    param_2[1] = uVar4;

    uVar4 = ___timet_from_ft(&local_144.ftLastAccessTime);

    param_2[2] = uVar4;

    uVar4 = ___timet_from_ft(&local_144.ftLastWriteTime);

    param_2[3] = uVar4;

    param_2[4] = local_144.nFileSizeLow;

    strcpy(param_2 + 5,local_144.cFileName);

    return 0;

  }

  DVar2 = GetLastError();

  if (DVar2 < 2) {

LAB_00544925:

    puVar3 = (undefined4 *)_errno();

    *puVar3 = 0x16;

  }

  else {

    if (3 < DVar2) {

      if (DVar2 == 8) {

        puVar3 = (undefined4 *)_errno();

        *puVar3 = 0xc;

        return 0xffffffff;

      }

      if (DVar2 != 0x12) goto LAB_00544925;

    }

    puVar3 = (undefined4 *)_errno();

    *puVar3 = 2;

  }

  return 0xffffffff;

}

/* ===== crt_errno_user @ 0x005449B3 ===== */
undefined4 crt_errno_user(HANDLE param_1)



{

  BOOL BVar1;

  undefined4 *puVar2;

  

  BVar1 = FindClose(param_1);

  if (BVar1 == 0) {

    puVar2 = (undefined4 *)_errno();

    *puVar2 = 0x16;

    return 0xffffffff;

  }

  return 0;

}

/* ===== ___timet_from_ft @ 0x005449D3 ===== */
/* Library Function - Single Match

    ___timet_from_ft

   

   Library: Visual Studio 2003 Release */



undefined4 ___timet_from_ft(FILETIME *param_1)



{

  BOOL BVar1;

  undefined4 uVar2;

  _SYSTEMTIME local_1c;

  _FILETIME local_c;

  

  if ((param_1->dwLowDateTime != 0) || (param_1->dwHighDateTime != 0)) {

    BVar1 = FileTimeToLocalFileTime(param_1,&local_c);

    if (BVar1 != 0) {

      BVar1 = FileTimeToSystemTime(&local_c,&local_1c);

      if (BVar1 != 0) {

        uVar2 = __loctotime_t(local_1c.wYear,local_1c.wMonth,local_1c.wDay,local_1c.wHour,

                              local_1c.wMinute,local_1c.wSecond,0xffffffff);

        return uVar2;

      }

    }

  }

  return 0xffffffff;

}

/* ===== FUN_00544a37 @ 0x00544A37 ===== */
undefined4 FUN_00544a37(int param_1,undefined4 param_2,int param_3)



{

  undefined4 uVar1;

  

  if ((param_3 == 10) && (param_1 < 0)) {

    uVar1 = 1;

    param_3 = 10;

  }

  else {

    uVar1 = 0;

  }

  FUN_00544a64(param_1,param_2,param_3,uVar1);

  return param_2;

}

/* ===== FUN_00544a64 @ 0x00544A64 ===== */
void FUN_00544a64(uint param_1,char *param_2,uint param_3,int param_4)



{

  ulonglong uVar1;

  char *pcVar2;

  char *pcVar3;

  char cVar4;

  

  pcVar2 = param_2;

  if (param_4 != 0) {

    *param_2 = '-';

    param_2 = param_2 + 1;

    param_1 = -param_1;

    pcVar2 = param_2;

  }

  do {

    pcVar3 = pcVar2;

    uVar1 = (ulonglong)param_1;

    param_1 = param_1 / param_3;

    cVar4 = (char)(uVar1 % (ulonglong)param_3);

    if ((uint)(uVar1 % (ulonglong)param_3) < 10) {

      cVar4 = cVar4 + '0';

    }

    else {

      cVar4 = cVar4 + 'W';

    }

    *pcVar3 = cVar4;

    pcVar2 = pcVar3 + 1;

  } while (param_1 != 0);

  pcVar3[1] = '\0';

  do {

    cVar4 = *pcVar3;

    *pcVar3 = *param_2;

    *param_2 = cVar4;

    pcVar3 = pcVar3 + -1;

    param_2 = param_2 + 1;

  } while (param_2 < pcVar3);

  return;

}

/* ===== FUN_00544ac0 @ 0x00544AC0 ===== */
void FUN_00544ac0(void)



{

  float10 in_ST0;

  

  FUN_00549b78((double)in_ST0);

  anm_dump_544add();

  return;

}

/* ===== anm_dump_544add @ 0x00544ADD ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



float10 anm_dump_544add(int param_1,uint param_2)



{

  uint in_EAX;

  bool in_ZF;

  short in_FPUControlWord;

  float10 in_ST0;

  float10 extraout_ST0;

  float10 fVar1;

  

  if (in_ZF) {

    if (((in_EAX & 0xfffff) != 0) || (fVar1 = _DAT_00581640, param_1 != 0)) {

      fVar1 = (float10)FUN_00549b1c();

    }

LAB_00544b6c:

    if (DAT_00630b54 == 0) {

      fVar1 = (float10)__startOneArgErrorHandling();

      return fVar1;

    }

  }

  else {

    if (in_FPUControlWord != 0x27f) {

      in_EAX = ANM_DumpCluster_7();

      in_ST0 = extraout_ST0;

    }

    if (in_EAX < 0x3ff00000) {

      fVar1 = (float10)fpatan(in_ST0,SQRT(((float10)1 - in_ST0) * ((float10)1 + in_ST0)));

    }

    else {

      fVar1 = _DAT_00581640;

      if ((0x3ff00000 < in_EAX) || ((param_2 & 0xfffff) != 0 || param_1 != 0)) goto LAB_00544b6c;

      fVar1 = _DAT_0058164a;

      if ((param_2 & 0x80000000) != 0) {

        fVar1 = -_DAT_0058164a;

      }

    }

    if (DAT_00630b54 == 0) {

      fVar1 = (float10)__math_exit();

      return fVar1;

    }

  }

  return fVar1;

}

/* ===== __global_unwind2 @ 0x00544B8C ===== */
/* PS2 candidate: changeInputVolume__FUi_2 (conf 0.631) */



void __global_unwind2(PVOID param_1)



{

  RtlUnwind(param_1,(PVOID)0x544ba4,(PEXCEPTION_RECORD)0x0,(PVOID)0x0);

  return;

}

/* ===== __local_unwind2 @ 0x00544BCE ===== */
/* Library Function - Single Match

    __local_unwind2

   

   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release, Visual Studio 2003 Debug, Visual

   Studio 2003 Release */



void __local_unwind2(int param_1,int param_2)



{

  int iVar1;

  int iVar2;

  void *pvStack_1c;

  undefined1 *puStack_18;

  undefined4 local_14;

  int iStack_10;

  

  iStack_10 = param_1;

  puStack_18 = &LAB_00544bac;

  pvStack_1c = ExceptionList;

  ExceptionList = &pvStack_1c;

  while( true ) {

    iVar1 = *(int *)(param_1 + 8);

    iVar2 = *(int *)(param_1 + 0xc);

    if ((iVar2 == -1) || (iVar2 == param_2)) break;

    local_14 = *(undefined4 *)(iVar1 + iVar2 * 0xc);

    *(undefined4 *)(param_1 + 0xc) = local_14;

    if (*(int *)(iVar1 + 4 + iVar2 * 0xc) == 0) {

      __get_eh_context(0x101);

      (**(code **)(iVar1 + 8 + iVar2 * 0xc))();

    }

  }

  ExceptionList = pvStack_1c;

  return;

}

/* ===== __get_eh_context @ 0x00544C62 ===== */
/* PS2 candidate: FNT_StringRender__FPcP14FNT_RenderInfo_2 (conf 0.856) */



void __get_eh_context(void)



{

  undefined4 in_EAX;

  int unaff_EBP;

  

  DAT_005810f0 = *(undefined4 *)(unaff_EBP + 8);

  DAT_005810ec = in_EAX;

  DAT_005810f4 = unaff_EBP;

  return;

}

/* ===== FUN_00544d41 @ 0x00544D41 ===== */
/* PS2 candidate: matherr (conf 0.642) */



void FUN_00544d41(int param_1)



{

  __local_unwind2(*(undefined4 *)(param_1 + 0x18),*(undefined4 *)(param_1 + 0x1c));

  return;

}

/* ===== FUN_00544d5c @ 0x00544D5C ===== */
void FUN_00544d5c(void)



{

  if (PTR_FUN_00580e00 != (undefined *)0x0) {

    (*(code *)PTR_FUN_00580e00)();

  }

  FUN_00544e62(&DAT_00554008,&DAT_00554014);

  FUN_00544e62(&DAT_00554000,&DAT_00554004);

  return;

}

/* ===== BinFileCreateWrite_4 @ 0x00544D89 ===== */
void BinFileCreateWrite_4(undefined4 param_1)



{

  crt_lock_vector(param_1,0,0);

  return;

}

/* ===== __exit @ 0x00544D9A ===== */
/* Library Function - Single Match

    __exit

   

   Library: Visual Studio 2003 Release */



void __cdecl __exit(int _Code)



{

  crt_lock_vector(_Code,1,0);

  return;

}

/* ===== crt_lock_vector @ 0x00544DAB ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void crt_lock_vector(UINT param_1,int param_2,int param_3)



{

  HANDLE hProcess;

  undefined4 *puVar1;

  UINT uExitCode;

  

  FUN_00544E50();

  if (DAT_00630b9c == 1) {

    uExitCode = param_1;

    hProcess = GetCurrentProcess();

    TerminateProcess(hProcess,uExitCode);

  }

  _DAT_00630b98 = 1;

  DAT_00630b94 = (undefined1)param_3;

  if (param_2 == 0) {

    if ((DAT_00658a10 != (undefined4 *)0x0) &&

       (puVar1 = (undefined4 *)(DAT_00658a0c - 4), DAT_00658a10 <= puVar1)) {

      do {

        if ((code *)*puVar1 != (code *)0x0) {

          (*(code *)*puVar1)();

        }

        puVar1 = puVar1 + -1;

      } while (DAT_00658a10 <= puVar1);

    }

    FUN_00544e62(&DAT_00554018,&DAT_00554020);

  }

  FUN_00544e62(&DAT_00554024,&DAT_00554028);

  if (param_3 == 0) {

    DAT_00630b9c = 1;

                    /* WARNING: Subroutine does not return */

    ExitProcess(param_1);

  }

  FUN_00544E59();

  return;

}

/* ===== FUN_00544E50 @ 0x00544E50 ===== */
void FUN_00544E50(void)



{

  _lock(0xd);

  return;

}

/* ===== FUN_00544E59 @ 0x00544E59 ===== */
void FUN_00544E59(void)



{

  _unlock(0xd);

  return;

}

/* ===== FUN_00544e62 @ 0x00544E62 ===== */
void FUN_00544e62(undefined4 *param_1,undefined4 *param_2)



{

  for (; param_1 < param_2; param_1 = param_1 + 1) {

    if ((code *)*param_1 != (code *)0x0) {

      (*(code *)*param_1)();

    }

  }

  return;

}

/* ===== crt_vobuf_alloc @ 0x00544E7C ===== */
HANDLE crt_vobuf_alloc(LPSECURITY_ATTRIBUTES param_1,SIZE_T param_2,undefined4 param_3,

                      undefined4 param_4,DWORD param_5,LPDWORD param_6)



{

  undefined4 *p0;

  HANDLE pvVar1;

  DWORD DVar2;

  

  DVar2 = 0;

  p0 = (undefined4 *)_malloc(1,0x74);

  if (p0 != (undefined4 *)0x0) {

    voBufReset__FP5VoBuf_2(p0);

    p0[1] = 0xffffffff;

    p0[0x12] = param_3;

    p0[0x13] = param_4;

    pvVar1 = CreateThread(param_1,param_2,FUN_00544ee7,p0,param_5,param_6);

    if (pvVar1 != (HANDLE)0x0) {

      return pvVar1;

    }

    DVar2 = GetLastError();

  }

  crt_free_ext(p0);

  if (DVar2 != 0) {

    _dosmaperr(DVar2);

  }

  return (HANDLE)0x0;

}

/* ===== FUN_00544ee7 @ 0x00544EE7 ===== */
undefined4 FUN_00544ee7(DWORD *param_1)



{

  BOOL BVar1;

  DWORD DVar2;

  undefined4 uVar3;

  void *local_14;

  undefined1 *puStack_10;

  undefined *puStack_c;

  undefined4 local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &DAT_00552350;

  puStack_10 = &LAB_00544c84;

  local_14 = ExceptionList;

  ExceptionList = &local_14;

  BVar1 = TlsSetValue(DAT_00581638,param_1);

  if (BVar1 == 0) {

    __amsg_exit(0x10);

  }

  DVar2 = GetCurrentThreadId();

  *param_1 = DVar2;

  if (PTR_ANM_DumpCluster_4_00580e04 != (undefined *)0x0) {

    (*(code *)PTR_ANM_DumpCluster_4_00580e04)();

  }

  local_8 = 0;

  uVar3 = (*(code *)param_1[0x12])(param_1[0x13]);

  crt_ptd_free_alloc(uVar3);

  ExceptionList = local_14;

  return 0;

}

/* ===== crt_ptd_free_alloc @ 0x00544F83 ===== */
void crt_ptd_free_alloc(DWORD param_1)



{

  int iVar1;

  

  if (PTR_ANM_DumpCluster_4_00580e08 != (undefined *)0x0) {

    (*(code *)PTR_ANM_DumpCluster_4_00580e08)();

  }

  iVar1 = __getptd();

  if (iVar1 == 0) {

    __amsg_exit(0x10);

  }

  __freeptd(iVar1);

                    /* WARNING: Subroutine does not return */

  ExitThread(param_1);

}

/* ===== FUN_00544fb5 @ 0x00544FB5 ===== */
void FUN_00544fb5(undefined4 param_1,undefined4 param_2,undefined4 param_3)



{

  crt_errno_big(param_1,param_2,param_3,0);

  return;

}

/* ===== crt_errno_big @ 0x00544FCC ===== */
uint crt_errno_big(byte *param_1,int *param_2,uint param_3,uint param_4)



{

  byte *pbVar1;

  uint uVar2;

  uint uVar3;

  int iVar4;

  undefined4 *puVar5;

  byte bVar6;

  uint uVar7;

  uint local_c;

  byte *local_8;

  

  local_c = 0;

  bVar6 = *param_1;

  pbVar1 = param_1;

  while( true ) {

    local_8 = pbVar1 + 1;

    if (DAT_005810b8 < 2) {

      uVar2 = (byte)PTR_DAT_00580eac[(uint)bVar6 * 2] & 8;

    }

    else {

      uVar2 = FUN_00544123(bVar6,8);

    }

    if (uVar2 == 0) break;

    bVar6 = *local_8;

    pbVar1 = local_8;

  }

  if (bVar6 == 0x2d) {

    param_4 = param_4 | 2;

LAB_00545027:

    bVar6 = *local_8;

    local_8 = pbVar1 + 2;

  }

  else if (bVar6 == 0x2b) goto LAB_00545027;

  if ((((int)param_3 < 0) || (param_3 == 1)) || (0x24 < (int)param_3)) {

    if (param_2 != (int *)0x0) {

      *param_2 = (int)param_1;

    }

    return 0;

  }

  if (param_3 == 0) {

    if (bVar6 != 0x30) {

      param_3 = 10;

      goto LAB_00545091;

    }

    if ((*local_8 != 0x78) && (*local_8 != 0x58)) {

      param_3 = 8;

      goto LAB_00545091;

    }

    param_3 = 0x10;

  }

  if (((param_3 == 0x10) && (bVar6 == 0x30)) && ((*local_8 == 0x78 || (*local_8 == 0x58)))) {

    bVar6 = local_8[1];

    local_8 = local_8 + 2;

  }

LAB_00545091:

  uVar2 = (uint)(0xffffffff / (ulonglong)param_3);

  do {

    uVar7 = (uint)bVar6;

    if (DAT_005810b8 < 2) {

      uVar3 = (byte)PTR_DAT_00580eac[uVar7 * 2] & 4;

    }

    else {

      uVar3 = FUN_00544123(uVar7,4);

    }

    if (uVar3 == 0) {

      if (DAT_005810b8 < 2) {

        uVar7 = *(ushort *)(PTR_DAT_00580eac + uVar7 * 2) & 0x103;

      }

      else {

        uVar7 = FUN_00544123(uVar7,0x103);

      }

      if (uVar7 == 0) {

LAB_0054513d:

        local_8 = local_8 + -1;

        if ((param_4 & 8) == 0) {

          if (param_2 != (int *)0x0) {

            local_8 = param_1;

          }

          local_c = 0;

        }

        else if (((param_4 & 4) != 0) ||

                (((param_4 & 1) == 0 &&

                 ((((param_4 & 2) != 0 && (0x80000000 < local_c)) ||

                  (((param_4 & 2) == 0 && (0x7fffffff < local_c)))))))) {

          puVar5 = (undefined4 *)_errno();

          *puVar5 = 0x22;

          if ((param_4 & 1) == 0) {

            local_c = ((param_4 & 2) != 0) + 0x7fffffff;

          }

          else {

            local_c = 0xffffffff;

          }

        }

        if (param_2 != (int *)0x0) {

          *param_2 = (int)local_8;

        }

        if ((param_4 & 2) == 0) {

          return local_c;

        }

        return -local_c;

      }

      iVar4 = crt_lock_simple((int)(char)bVar6);

      uVar7 = iVar4 - 0x37;

    }

    else {

      uVar7 = (int)(char)bVar6 - 0x30;

    }

    if (param_3 <= uVar7) goto LAB_0054513d;

    if ((local_c < uVar2) ||

       ((local_c == uVar2 && (uVar7 <= (uint)(0xffffffff % (ulonglong)param_3))))) {

      local_c = local_c * param_3 + uVar7;

      param_4 = param_4 | 8;

    }

    else {

      param_4 = param_4 | 0xc;

    }

    bVar6 = *local_8;

    local_8 = local_8 + 1;

  } while( true );

}

/* ===== FUN_005451d1 @ 0x005451D1 ===== */
uint FUN_005451d1(int param_1)



{

  uint uVar1;

  

  if (1 < DAT_005810b8) {

    uVar1 = FUN_00544123(param_1,8);

    return uVar1;

  }

  return (byte)PTR_DAT_00580eac[param_1 * 2] & 8;

}

/* ===== FUN_005451f9 @ 0x005451F9 ===== */
int FUN_005451f9(short *param_1)



{

  short sVar1;

  short *psVar2;

  

  sVar1 = *param_1;

  psVar2 = param_1;

  while (psVar2 = psVar2 + 1, sVar1 != 0) {

    sVar1 = *psVar2;

  }

  return ((int)psVar2 - (int)param_1 >> 1) + -1;

}

/* ===== _strstr @ 0x00545220 ===== */
/* Library Function - Single Match

    _strstr

   

   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */



char * __cdecl _strstr(char *_Str,char *_SubStr)



{

  char *pcVar1;

  char *pcVar2;

  char cVar3;

  uint uVar4;

  char cVar5;

  uint uVar6;

  uint uVar7;

  char *pcVar8;

  uint *puVar9;

  char *pcVar10;

  

  cVar3 = *_SubStr;

  if (cVar3 == '\0') {

    return _Str;

  }

  if (_SubStr[1] == '\0') {

    while (((uint)_Str & 3) != 0) {

      uVar4 = *(uint *)_Str;

      if ((char)uVar4 == cVar3) {

        return (char *)(uint *)_Str;

      }

      _Str = (char *)((int)_Str + 1);

      if ((char)uVar4 == '\0') {

        return (char *)0x0;

      }

    }

    while( true ) {

      while( true ) {

        uVar4 = *(uint *)_Str;

        uVar7 = uVar4 ^ CONCAT22(CONCAT11(cVar3,cVar3),CONCAT11(cVar3,cVar3));

        uVar6 = uVar4 ^ 0xffffffff ^ uVar4 + 0x7efefeff;

        puVar9 = (uint *)((int)_Str + 4);

        if (((uVar7 ^ 0xffffffff ^ uVar7 + 0x7efefeff) & 0x81010100) != 0) break;

        _Str = (char *)puVar9;

        if ((uVar6 & 0x81010100) != 0) {

          if ((uVar6 & 0x1010100) != 0) {

            return (char *)0x0;

          }

          if ((uVar4 + 0x7efefeff & 0x80000000) == 0) {

            return (char *)0x0;

          }

        }

      }

      uVar4 = *(uint *)_Str;

      if ((char)uVar4 == cVar3) {

        return (char *)(uint *)_Str;

      }

      if ((char)uVar4 == '\0') {

        return (char *)0x0;

      }

      cVar5 = (char)(uVar4 >> 8);

      if (cVar5 == cVar3) {

        return (char *)((int)_Str + 1);

      }

      if (cVar5 == '\0') {

        return (char *)0x0;

      }

      cVar5 = (char)(uVar4 >> 0x10);

      if (cVar5 == cVar3) {

        return (char *)((int)_Str + 2);

      }

      if (cVar5 == '\0') break;

      cVar5 = (char)(uVar4 >> 0x18);

      if (cVar5 == cVar3) {

        return (char *)((int)_Str + 3);

      }

      _Str = (char *)puVar9;

      if (cVar5 == '\0') {

        return (char *)0x0;

      }

    }

    return (char *)0x0;

  }

  do {

    cVar5 = *_Str;

    do {

      while (_Str = _Str + 1, cVar5 != cVar3) {

        if (cVar5 == '\0') {

          return (char *)0x0;

        }

        cVar5 = *_Str;

      }

      cVar5 = *_Str;

      pcVar10 = _Str + 1;

      pcVar8 = _SubStr;

    } while (cVar5 != _SubStr[1]);

    do {

      if (pcVar8[2] == '\0') {

LAB_00545293:

        return _Str + -1;

      }

      if (*pcVar10 != pcVar8[2]) break;

      pcVar1 = pcVar8 + 3;

      if (*pcVar1 == '\0') goto LAB_00545293;

      pcVar2 = pcVar10 + 1;

      pcVar8 = pcVar8 + 2;

      pcVar10 = pcVar10 + 2;

    } while (*pcVar1 == *pcVar2);

  } while( true );

}

/* ===== crt_lock_5452a0 @ 0x005452A0 ===== */
int crt_lock_5452a0(int param_1)



{

  bool bVar1;

  

  if (DAT_00630c5c == 0) {

    if ((0x40 < param_1) && (param_1 < 0x5b)) {

      return param_1 + 0x20;

    }

  }

  else {

    InterlockedIncrement((LONG *)&DAT_006579c8);

    bVar1 = DAT_006579c4 != 0;

    if (bVar1) {

      InterlockedDecrement((LONG *)&DAT_006579c8);

      _lock(0x13);

    }

    param_1 = FUN_0054530f(param_1);

    if (bVar1) {

      _unlock(0x13);

    }

    else {

      InterlockedDecrement((LONG *)&DAT_006579c8);

    }

  }

  return param_1;

}

/* ===== FUN_0054530f @ 0x0054530F ===== */
uint FUN_0054530f(uint param_1)



{

  uint uVar1;

  uint uVar2;

  undefined4 uVar3;

  int iVar4;

  uint local_8;

  

  uVar1 = param_1;

  if (DAT_00630c5c == 0) {

    if ((0x40 < (int)param_1) && ((int)param_1 < 0x5b)) {

      uVar1 = param_1 + 0x20;

    }

  }

  else {

    uVar3 = 1;

    if ((int)param_1 < 0x100) {

      if (DAT_005810b8 < 2) {

        uVar2 = (byte)PTR_DAT_00580eac[param_1 * 2] & 1;

      }

      else {

        uVar2 = FUN_00544123(param_1,1);

      }

      if (uVar2 == 0) {

        return uVar1;

      }

    }

    if ((PTR_DAT_00580eac[((int)uVar1 >> 8 & 0xffU) * 2 + 1] & 0x80) == 0) {

      param_1 = CONCAT31((int3)(param_1 >> 8),(char)uVar1) & 0xffff00ff;

    }

    else {

      uVar2 = param_1 >> 0x10;

      param_1._0_2_ = CONCAT11((char)uVar1,(char)(uVar1 >> 8));

      param_1 = CONCAT22((short)uVar2,(undefined2)param_1) & 0xff00ffff;

      uVar3 = 2;

    }

    iVar4 = crt_lcmapstring(DAT_00630c5c,0x100,&param_1,uVar3,&local_8,3,0,1);

    if (iVar4 != 0) {

      if (iVar4 == 1) {

        uVar1 = local_8 & 0xff;

      }

      else {

        uVar1 = local_8 & 0xffff;

      }

    }

  }

  return uVar1;

}

/* ===== crt_file_lock @ 0x00545496 ===== */
void crt_file_lock(uint param_1)



{

  if ((0x5810ff < param_1) && (param_1 < 0x581361)) {

    _lock(((int)(param_1 - 0x581100) >> 5) + 0x1c);

    return;

  }

  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x20));

  return;

}

/* ===== crt_file_lock_2 @ 0x005454C5 ===== */
void crt_file_lock_2(int param_1,int param_2)



{

  if (param_1 < 0x14) {

    _lock(param_1 + 0x1c);

    return;

  }

  EnterCriticalSection((LPCRITICAL_SECTION)(param_2 + 0x20));

  return;

}

/* ===== crt_file_unlock @ 0x005454E8 ===== */
void crt_file_unlock(uint param_1)



{

  if ((0x5810ff < param_1) && (param_1 < 0x581361)) {

    _unlock(((int)(param_1 - 0x581100) >> 5) + 0x1c);

    return;

  }

  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x20));

  return;

}

/* ===== crt_file_unlock_2 @ 0x00545517 ===== */
void crt_file_unlock_2(int param_1,int param_2)



{

  if (param_1 < 0x14) {

    _unlock(param_1 + 0x1c);

    return;

  }

  LeaveCriticalSection((LPCRITICAL_SECTION)(param_2 + 0x20));

  return;

}

/* ===== crt_file_lock_ops @ 0x00545540 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined4 crt_file_lock_ops(byte *param_1,char *param_2,int param_3)



{

  char cVar1;

  int iVar2;

  byte bVar3;

  ushort uVar4;

  uint uVar5;

  undefined4 uVar6;

  uint uVar7;

  bool bVar8;

  uint uVar9;

  

  iVar2 = _DAT_006579c8;

  uVar6 = 0;

  if (param_3 != 0) {

    if (DAT_00630c5c == 0) {

      do {

        bVar3 = *param_1;

        cVar1 = *param_2;

        uVar4 = CONCAT11(bVar3,cVar1);

        if (bVar3 == 0) break;

        uVar4 = CONCAT11(bVar3,cVar1);

        uVar7 = (uint)uVar4;

        if (cVar1 == '\0') break;

        param_1 = param_1 + 1;

        param_2 = param_2 + 1;

        if ((0x40 < bVar3) && (bVar3 < 0x5b)) {

          uVar7 = (uint)CONCAT11(bVar3 + 0x20,cVar1);

        }

        uVar4 = (ushort)uVar7;

        bVar3 = (byte)uVar7;

        if ((0x40 < bVar3) && (bVar3 < 0x5b)) {

          uVar4 = (ushort)CONCAT31((int3)(uVar7 >> 8),bVar3 + 0x20);

        }

        bVar3 = (byte)(uVar4 >> 8);

        bVar8 = bVar3 < (byte)uVar4;

        if (bVar3 != (byte)uVar4) goto LAB_0054559f;

        param_3 = param_3 + -1;

      } while (param_3 != 0);

      uVar6 = 0;

      bVar3 = (byte)(uVar4 >> 8);

      bVar8 = bVar3 < (byte)uVar4;

      if (bVar3 != (byte)uVar4) {

LAB_0054559f:

        uVar6 = 0xffffffff;

        if (!bVar8) {

          uVar6 = 1;

        }

      }

    }

    else {

      LOCK();

      _DAT_006579c8 = _DAT_006579c8 + 1;

      UNLOCK();

      bVar8 = 0 < DAT_006579c4;

      if (bVar8) {

        LOCK();

        UNLOCK();

        _DAT_006579c8 = iVar2;

        _lock(0x13);

      }

      uVar9 = (uint)bVar8;

      uVar5 = 0;

      uVar7 = 0;

      do {

        uVar5 = CONCAT31((int3)(uVar5 >> 8),*param_1);

        uVar7 = CONCAT31((int3)(uVar7 >> 8),*param_2);

        if ((uVar5 == 0) || (uVar7 == 0)) break;

        param_1 = param_1 + 1;

        param_2 = param_2 + 1;

        uVar7 = FUN_0054530f(uVar7,uVar5);

        uVar5 = FUN_0054530f();

        bVar8 = uVar5 < uVar7;

        if (uVar5 != uVar7) goto LAB_00545615;

        param_3 = param_3 + -1;

      } while (param_3 != 0);

      uVar6 = 0;

      bVar8 = uVar5 < uVar7;

      if (uVar5 != uVar7) {

LAB_00545615:

        uVar6 = 0xffffffff;

        if (!bVar8) {

          uVar6 = 1;

        }

      }

      if (uVar9 == 0) {

        LOCK();

        _DAT_006579c8 = _DAT_006579c8 + -1;

        UNLOCK();

      }

      else {

        _unlock(0x13);

      }

    }

  }

  return uVar6;

}

/* ===== FUN_00545650 @ 0x00545650 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* PS2 candidate: fx_find (conf 0.571) */



char FUN_00545650(byte *param_1,byte *param_2)



{

  bool bVar1;

  int iVar2;

  byte bVar3;

  byte bVar4;

  byte bVar5;

  char cVar6;

  uint uVar7;

  

  iVar2 = _DAT_006579c8;

  if (DAT_00630c5c == 0) {

    bVar5 = 0xff;

    do {

      do {

        if (bVar5 == 0) {

          return '\0';

        }

        bVar5 = *param_2;

        param_2 = param_2 + 1;

        bVar4 = *param_1;

        param_1 = param_1 + 1;

      } while (bVar4 == bVar5);

      bVar3 = bVar5 + 0xbf + (-((byte)(bVar5 + 0xbf) < 0x1a) & 0x20U) + 0x41;

      bVar4 = bVar4 + 0xbf;

      bVar5 = bVar4 + (-(bVar4 < 0x1a) & 0x20U) + 0x41;

    } while (bVar5 == bVar3);

    cVar6 = (bVar5 < bVar3) * -2 + '\x01';

  }

  else {

    LOCK();

    _DAT_006579c8 = _DAT_006579c8 + 1;

    UNLOCK();

    bVar1 = 0 < DAT_006579c4;

    if (bVar1) {

      LOCK();

      UNLOCK();

      _DAT_006579c8 = iVar2;

      _lock(0x13);

    }

    uVar7 = (uint)bVar1;

    bVar5 = 0xff;

    do {

      do {

        cVar6 = '\0';

        if (bVar5 == 0) goto LAB_005456ff;

        bVar5 = *param_2;

        param_2 = param_2 + 1;

        bVar4 = *param_1;

        param_1 = param_1 + 1;

      } while (bVar5 == bVar4);

      bVar4 = FUN_0054530f(bVar4,bVar5);

      bVar5 = FUN_0054530f();

    } while (bVar4 == bVar5);

    cVar6 = (bVar4 < bVar5) * -2 + '\x01';

LAB_005456ff:

    if (uVar7 == 0) {

      LOCK();

      _DAT_006579c8 = _DAT_006579c8 + -1;

      UNLOCK();

    }

    else {

      _unlock(0x13);

    }

  }

  return cVar6;

}

/* ===== _strncmp @ 0x00545720 ===== */
/* Library Function - Single Match

    _strncmp

   

   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */



int __cdecl _strncmp(char *_Str1,char *_Str2,size_t _MaxCount)



{

  char cVar1;

  char cVar2;

  size_t sVar3;

  int iVar4;

  uint uVar5;

  char *pcVar6;

  char *pcVar7;

  

  uVar5 = 0;

  sVar3 = _MaxCount;

  pcVar6 = _Str1;

  if (_MaxCount != 0) {

    do {

      if (sVar3 == 0) break;

      sVar3 = sVar3 - 1;

      cVar1 = *pcVar6;

      pcVar6 = pcVar6 + 1;

    } while (cVar1 != '\0');

    iVar4 = _MaxCount - sVar3;

    do {

      pcVar6 = _Str2;

      pcVar7 = _Str1;

      if (iVar4 == 0) break;

      iVar4 = iVar4 + -1;

      pcVar7 = _Str1 + 1;

      pcVar6 = _Str2 + 1;

      cVar2 = *_Str1;

      cVar1 = *_Str2;

      _Str2 = pcVar6;

      _Str1 = pcVar7;

    } while (cVar1 == cVar2);

    uVar5 = 0;

    if ((byte)pcVar6[-1] <= (byte)pcVar7[-1]) {

      if (pcVar6[-1] == pcVar7[-1]) {

        return 0;

      }

      uVar5 = 0xfffffffe;

    }

    uVar5 = ~uVar5;

  }

  return uVar5;

}

/* ===== entry @ 0x00545758 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* PS2 candidate: entry (conf 0.722) */



void entry(void)



{

  DWORD DVar1;

  int iVar2;

  undefined4 uVar3;

  uint uVar4;

  HMODULE pHVar5;

  undefined4 uVar6;

  _STARTUPINFOA local_60;

  undefined1 *local_1c;

  undefined4 *local_18;

  void *pvStack_14;

  undefined1 *puStack_10;

  undefined *puStack_c;

  undefined4 local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &DAT_00552360;

  puStack_10 = &LAB_00544c84;

  pvStack_14 = ExceptionList;

  local_1c = &stack0xffffff88;

  ExceptionList = &pvStack_14;

  DVar1 = GetVersion();

  _DAT_00630b6c = DVar1 >> 8 & 0xff;

  _DAT_00630b68 = DVar1 & 0xff;

  _DAT_00630b64 = _DAT_00630b68 * 0x100 + _DAT_00630b6c;

  _DAT_00630b60 = DVar1 >> 0x10;

  iVar2 = _heap_init(1);

  if (iVar2 == 0) {

    FUN_00545885(0x1c);

  }

  iVar2 = crt_tls_init();

  if (iVar2 == 0) {

    FUN_00545885(0x10);

  }

  local_8 = 0;

  crt_io_init();

  DAT_006579f0 = GetCommandLineA();

  DAT_00630ba4 = bin_file_memmove();

  FUN_0054c968();

  bin_file_copy_str();

  FUN_00544d5c();

  local_60.dwFlags = 0;

  GetStartupInfoA(&local_60);

  uVar3 = bin_file_create_54();

  if ((local_60.dwFlags & 1) == 0) {

    uVar4 = 10;

  }

  else {

    uVar4 = (uint)local_60.wShowWindow;

  }

  uVar6 = 0;

  pHVar5 = GetModuleHandleA((LPCSTR)0x0);

  uVar3 = localization_check(pHVar5,uVar6,uVar3,uVar4);

  BinFileCreateWrite_4(uVar3);

  __initptd(*(undefined4 *)*local_18,local_18);

  return;

}

/* ===== __amsg_exit @ 0x00545860 ===== */
/* PS2 candidate: _decodeOrSkip_2 (conf 0.51) */



void __cdecl __amsg_exit(int param_1)



{

  if (DAT_00630bac == 1) {

    FUN_0054cce7();

  }

  __rt_error_box_2(param_1);

  (*(code *)PTR___exit_00581380)(0xff);

  return;

}

/* ===== FUN_00545885 @ 0x00545885 ===== */
/* PS2 candidate: _decodeOrSkip (conf 0.516) */



void FUN_00545885(undefined4 param_1)



{

  if (DAT_00630bac == 1) {

    FUN_0054cce7();

  }

  __rt_error_box_2(param_1);

                    /* WARNING: Subroutine does not return */

  ExitProcess(0xff);

}

/* ===== crt_freebuf_ops @ 0x005458A9 ===== */
undefined4 crt_freebuf_ops(undefined4 param_1)



{

  undefined4 uVar1;

  undefined4 uVar2;

  

  crt_file_lock_2(1,&DAT_00581120);

  uVar1 = crt_initio(&DAT_00581120);

  uVar2 = _output(&DAT_00581120,param_1,&stack0x00000008);

  _freebuf(uVar1,&DAT_00581120);

  crt_file_unlock_2(1,&DAT_00581120);

  return uVar2;

}

/* ===== crt_flush_ops @ 0x005458EA ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined4 crt_flush_ops(FILE *param_1,int *param_2,uint param_3,uint param_4)



{

  undefined4 local_8;

  

  local_8 = 0;

  if ((param_3 != 4) &&

     (((param_4 < 2 || (0x7fffffff < param_4)) || ((param_3 != 0 && (param_3 != 0x40)))))) {

    return 0xffffffff;

  }

  param_4 = param_4 & 0xfffffffe;

  crt_file_lock(param_1);

  _flush(param_1);

  __freebuf(param_1);

  *(ushort *)&param_1->_flag = (ushort)param_1->_flag & 0xc2f3;

  if ((param_3 & 4) == 0) {

    if (param_2 == (int *)0x0) {

      param_2 = _malloc(param_4);

      if (param_2 == (int *)0x0) {

        _DAT_00630ba0 = _DAT_00630ba0 + 1;

        local_8 = 0xffffffff;

        goto LAB_0054598a;

      }

      *(ushort *)&param_1->_flag = (ushort)param_1->_flag | 0x408;

    }

    else {

      param_1->_flag = param_1->_flag | 0x500;

    }

  }

  else {

    param_1->_flag = param_1->_flag | 4;

    param_2 = &param_1->_charbuf;

    param_4 = 2;

  }

  param_1->_cnt = 0;

  param_1->_bufsiz = param_4;

  param_1->_base = (char *)param_2;

  param_1->_ptr = (char *)param_2;

LAB_0054598a:

  crt_file_unlock(param_1);

  return local_8;

}

/* ===== crt_file_lock_2ops @ 0x00545999 ===== */
int crt_file_lock_2ops(void)



{

  undefined4 *puVar1;

  undefined4 *puVar2;

  int *piVar3;

  int iVar4;

  int local_8;

  int local_4;

  

  iVar4 = -1;

  _lock(0x12);

  local_8 = 0;

  local_4 = 0;

  piVar3 = &DAT_006578c0;

  while (puVar2 = (undefined4 *)*piVar3, puVar1 = puVar2, puVar2 != (undefined4 *)0x0) {

    for (; puVar2 < puVar1 + 0x120; puVar2 = puVar2 + 9) {

      if ((*(byte *)(puVar2 + 1) & 1) == 0) {

        if (puVar2[2] == 0) {

          _lock(0x11);

          if (puVar2[2] == 0) {

            InitializeCriticalSection((LPCRITICAL_SECTION)(puVar2 + 3));

            puVar2[2] = puVar2[2] + 1;

          }

          _unlock(0x11);

        }

        EnterCriticalSection((LPCRITICAL_SECTION)(puVar2 + 3));

        if ((*(byte *)(puVar2 + 1) & 1) == 0) {

          *puVar2 = 0xffffffff;

          iVar4 = ((int)puVar2 - *piVar3) / 0x24 + local_4;

          if (iVar4 != -1) goto LAB_00545aab;

          break;

        }

        LeaveCriticalSection((LPCRITICAL_SECTION)(puVar2 + 3));

      }

      puVar1 = (undefined4 *)*piVar3;

    }

    local_4 = local_4 + 0x20;

    piVar3 = piVar3 + 1;

    local_8 = local_8 + 1;

    if (0x6579bf < (int)piVar3) goto LAB_00545aab;

  }

  puVar2 = _malloc(0x480);

  if (puVar2 != (undefined4 *)0x0) {

    DAT_006579c0 = DAT_006579c0 + 0x20;

    (&DAT_006578c0)[local_8] = puVar2;

    puVar1 = puVar2;

    for (; puVar2 < puVar1 + 0x120; puVar2 = puVar2 + 9) {

      *(undefined1 *)(puVar2 + 1) = 0;

      *puVar2 = 0xffffffff;

      puVar2[2] = 0;

      *(undefined1 *)((int)puVar2 + 5) = 10;

      puVar1 = (undefined4 *)(&DAT_006578c0)[local_8];

    }

    iVar4 = local_8 << 5;

    crt_lock_fd(iVar4);

  }

LAB_00545aab:

  _unlock(0x12);

  return iVar4;

}

/* ===== crt_set_errno_val @ 0x00545ABC ===== */
undefined4 crt_set_errno_val(uint param_1,HANDLE param_2)



{

  undefined4 *puVar1;

  int iVar2;

  DWORD nStdHandle;

  

  if (param_1 < DAT_006579c0) {

    iVar2 = (param_1 & 0x1f) * 0x24;

    if (*(int *)((&DAT_006578c0)[(int)param_1 >> 5] + iVar2) == -1) {

      if (DAT_00581384 == 1) {

        if (param_1 == 0) {

          nStdHandle = 0xfffffff6;

        }

        else if (param_1 == 1) {

          nStdHandle = 0xfffffff5;

        }

        else {

          if (param_1 != 2) goto LAB_00545b15;

          nStdHandle = 0xfffffff4;

        }

        SetStdHandle(nStdHandle,param_2);

      }

LAB_00545b15:

      *(HANDLE *)((&DAT_006578c0)[(int)param_1 >> 5] + iVar2) = param_2;

      return 0;

    }

  }

  puVar1 = (undefined4 *)_errno();

  *puVar1 = 9;

  puVar1 = (undefined4 *)__doserrno();

  *puVar1 = 0;

  return 0xffffffff;

}

/* ===== crt_set_doserrno @ 0x00545B38 ===== */
undefined4 crt_set_doserrno(uint param_1)



{

  int *piVar1;

  undefined4 *puVar2;

  int iVar3;

  DWORD nStdHandle;

  

  if (param_1 < DAT_006579c0) {

    iVar3 = (param_1 & 0x1f) * 0x24;

    piVar1 = (int *)((&DAT_006578c0)[(int)param_1 >> 5] + iVar3);

    if (((*(byte *)(piVar1 + 1) & 1) != 0) && (*piVar1 != -1)) {

      if (DAT_00581384 == 1) {

        if (param_1 == 0) {

          nStdHandle = 0xfffffff6;

        }

        else if (param_1 == 1) {

          nStdHandle = 0xfffffff5;

        }

        else {

          if (param_1 != 2) goto LAB_00545b94;

          nStdHandle = 0xfffffff4;

        }

        SetStdHandle(nStdHandle,(HANDLE)0x0);

      }

LAB_00545b94:

      *(undefined4 *)((&DAT_006578c0)[(int)param_1 >> 5] + iVar3) = 0xffffffff;

      return 0;

    }

  }

  puVar2 = (undefined4 *)_errno();

  *puVar2 = 9;

  puVar2 = (undefined4 *)__doserrno();

  *puVar2 = 0;

  return 0xffffffff;

}

/* ===== crt_validate_osfhnd @ 0x00545BB7 ===== */
undefined4 crt_validate_osfhnd(uint param_1)



{

  undefined4 *puVar1;

  

  if ((param_1 < DAT_006579c0) &&

     ((*(byte *)((&DAT_006578c0)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 1) != 0)) {

    return *(undefined4 *)((&DAT_006578c0)[(int)param_1 >> 5] + (param_1 & 0x1f) * 0x24);

  }

  puVar1 = (undefined4 *)_errno();

  *puVar1 = 9;

  puVar1 = (undefined4 *)__doserrno();

  *puVar1 = 0;

  return 0xffffffff;

}

/* ===== crt_lock_fd @ 0x00545BF9 ===== */
void crt_lock_fd(uint param_1)



{

  int iVar1;

  int iVar2;

  

  iVar2 = (param_1 & 0x1f) * 0x24;

  iVar1 = (&DAT_006578c0)[(int)param_1 >> 5] + iVar2;

  if (*(int *)(iVar1 + 8) == 0) {

    _lock(0x11);

    if (*(int *)(iVar1 + 8) == 0) {

      InitializeCriticalSection((LPCRITICAL_SECTION)(iVar1 + 0xc));

      *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + 1;

    }

    _unlock(0x11);

  }

  EnterCriticalSection((LPCRITICAL_SECTION)((&DAT_006578c0)[(int)param_1 >> 5] + 0xc + iVar2));

  return;

}

/* ===== FUN_00545c58 @ 0x00545C58 ===== */
void FUN_00545c58(uint param_1)



{

  LeaveCriticalSection

            ((LPCRITICAL_SECTION)

             ((&DAT_006578c0)[(int)param_1 >> 5] + 0xc + (param_1 & 0x1f) * 0x24));

  return;

}

/* ===== crt_flsbuf_ops @ 0x00545C7A ===== */
undefined4 crt_flsbuf_ops(undefined1 *param_1,undefined4 param_2,undefined4 param_3)



{

  undefined4 uVar1;

  undefined1 *local_24;

  int local_20;

  undefined1 *local_1c;

  undefined4 local_18;

  

  local_1c = param_1;

  local_24 = param_1;

  local_18 = 0x42;

  local_20 = 0x7fffffff;

  uVar1 = _output(&local_24,param_2,param_3);

  local_20 = local_20 + -1;

  if (local_20 < 0) {

    _flsbuf(0,&local_24);

  }

  else {

    *local_24 = 0;

  }

  return uVar1;

}

/* ===== _GLOBAL_$D$Game_2 @ 0x00545CCB ===== */
void _GLOBAL__D_Game_2(void)



{

  FUN_0054cea8(0x10000,0x30000);

  return;

}

/* ===== AudioDataStreamStatus__Fv_7 @ 0x00545CDD ===== */
/* WARNING: Removing unreachable block (ram,0x00545d12) */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */



undefined4 AudioDataStreamStatus__Fv_7(void)



{

  return 0;

}

/* ===== crt_cpu_features_check @ 0x00545D1B ===== */
void crt_cpu_features_check(void)



{

  HMODULE hModule;

  FARPROC pFVar1;

  

  hModule = GetModuleHandleA("KERNEL32");

  if (hModule != (HMODULE)0x0) {

    pFVar1 = GetProcAddress(hModule,"IsProcessorFeaturePresent");

    if (pFVar1 != (FARPROC)0x0) {

      (*pFVar1)(0);

      return;

    }

  }

  AudioDataStreamStatus__Fv_7();

  return;

}

/* ===== FUN_00545d44 @ 0x00545D44 ===== */
void FUN_00545d44(char *param_1)



{

  char cVar1;

  char cVar2;

  int iVar3;

  uint uVar4;

  

  iVar3 = crt_lock_5452a0((int)*param_1);

  if (iVar3 != 0x65) {

    do {

      param_1 = param_1 + 1;

      if (DAT_005810b8 < 2) {

        uVar4 = (byte)PTR_DAT_00580eac[*param_1 * 2] & 4;

      }

      else {

        uVar4 = FUN_00544123((int)*param_1,4);

      }

    } while (uVar4 != 0);

  }

  cVar2 = *param_1;

  *param_1 = DAT_005810bc;

  do {

    param_1 = param_1 + 1;

    cVar1 = *param_1;

    *param_1 = cVar2;

    cVar2 = cVar1;

  } while (*param_1 != '\0');

  return;

}

/* ===== __fassign @ 0x00545E04 ===== */
/* Library Function - Single Match

    __fassign

   

   Library: Visual Studio 2003 Release */



void __cdecl __fassign(int flag,char *argument,char *number)



{

  undefined4 local_c;

  undefined4 local_8;

  

  if (flag != 0) {

    binfile_seek_strtod(&local_c);

    *(undefined4 *)argument = local_c;

    *(undefined4 *)(argument + 4) = local_8;

    return;

  }

  binfile_seek_strtod2(&number,number);

  *(char **)argument = number;

  return;

}

/* ===== FUN_00545e42 @ 0x00545E42 ===== */
int FUN_00545e42(undefined8 *param_1,int param_2,int param_3,undefined4 param_4)



{

  undefined1 local_2c [24];

  int local_14 [4];

  

  crt_mbtowc_helper(*param_1,local_14,local_2c);

  FUN_0054d3c5((uint)(0 < param_3) + param_2 + (uint)(local_14[0] == 0x2d),param_3 + 1,local_14);

  crt_printf_fmt_e(param_2,param_3,param_4,local_14,0);

  return param_2;

}

/* ===== crt_printf_fmt_e @ 0x00545EA3 ===== */
undefined1 * crt_printf_fmt_e(undefined1 *param_1,int param_2,int param_3,int *param_4,char param_5)



{

  undefined1 *puVar1;

  undefined1 *puVar2;

  int iVar3;

  

  if (param_5 != '\0') {

    crt_memmove(param_1 + (*param_4 == 0x2d),0 < param_2);

  }

  puVar2 = param_1;

  if (*param_4 == 0x2d) {

    *param_1 = 0x2d;

    puVar2 = param_1 + 1;

  }

  puVar1 = puVar2;

  if (0 < param_2) {

    puVar1 = puVar2 + 1;

    *puVar2 = puVar2[1];

    *puVar1 = DAT_005810bc;

  }

  puVar2 = (undefined1 *)strcpy(puVar1 + param_2 + (uint)(param_5 == '\0'),"e+000");

  if (param_3 != 0) {

    *puVar2 = 0x45;

  }

  if (*(char *)param_4[3] != '0') {

    iVar3 = param_4[1] + -1;

    if (iVar3 < 0) {

      iVar3 = -iVar3;

      puVar2[1] = 0x2d;

    }

    if (99 < iVar3) {

      puVar2[2] = puVar2[2] + (char)(iVar3 / 100);

      iVar3 = iVar3 % 100;

    }

    if (9 < iVar3) {

      puVar2[3] = puVar2[3] + (char)(iVar3 / 10);

      iVar3 = iVar3 % 10;

    }

    puVar2[4] = puVar2[4] + (char)iVar3;

  }

  return param_1;

}

/* ===== FUN_00545f65 @ 0x00545F65 ===== */
int FUN_00545f65(undefined8 *param_1,int param_2,int param_3)



{

  undefined1 local_2c [24];

  int local_14;

  int local_10;

  

  crt_mbtowc_helper(*param_1,&local_14,local_2c);

  FUN_0054d3c5((uint)(local_14 == 0x2d) + param_2,local_10 + param_3,&local_14);

  FUN_00545fba(param_2,param_3,&local_14,0);

  return param_2;

}

/* ===== FUN_00545fba @ 0x00545FBA ===== */
undefined1 * FUN_00545fba(undefined1 *param_1,size_t param_2,int *param_3,char param_4)



{

  int iVar1;

  int iVar2;

  undefined1 *puVar3;

  

  iVar1 = param_3[1];

  if ((param_4 != '\0') && (iVar1 - 1U == param_2)) {

    iVar2 = *param_3;

    param_1[(uint)(iVar2 == 0x2d) + (iVar1 - 1U)] = 0x30;

    (param_1 + (uint)(iVar2 == 0x2d) + (iVar1 - 1U))[1] = 0;

  }

  puVar3 = param_1;

  if (*param_3 == 0x2d) {

    *param_1 = 0x2d;

    puVar3 = param_1 + 1;

  }

  if (param_3[1] < 1) {

    crt_memmove(puVar3,1);

    *puVar3 = 0x30;

    puVar3 = puVar3 + 1;

  }

  else {

    puVar3 = puVar3 + param_3[1];

  }

  if (0 < (int)param_2) {

    crt_memmove(puVar3,1);

    *puVar3 = DAT_005810bc;

    iVar1 = param_3[1];

    if (iVar1 < 0) {

      if ((param_4 != '\0') || (-iVar1 <= (int)param_2)) {

        param_2 = -iVar1;

      }

      crt_memmove(puVar3 + 1,param_2);

      _memset(puVar3 + 1,0x30,param_2);

    }

  }

  return param_1;

}

/* ===== FUN_00546061 @ 0x00546061 ===== */
void FUN_00546061(undefined8 *param_1,int param_2,int param_3,undefined4 param_4)



{

  int iVar1;

  char *pcVar2;

  char *pcVar3;

  undefined1 local_2c [24];

  int local_14;

  int local_10;

  

  crt_mbtowc_helper(*param_1,&local_14,local_2c);

  iVar1 = local_10 + -1;

  pcVar2 = (char *)((uint)(local_14 == 0x2d) + param_2);

  FUN_0054d3c5(pcVar2,param_3,&local_14);

  local_10 = local_10 + -1;

  if ((local_10 < -4) || (param_3 <= local_10)) {

    crt_printf_fmt_e(param_2,param_3,param_4,&local_14,1);

  }

  else {

    if (iVar1 < local_10) {

      do {

        pcVar3 = pcVar2;

        pcVar2 = pcVar3 + 1;

      } while (*pcVar3 != '\0');

      pcVar3[-1] = '\0';

    }

    FUN_00545fba(param_2,param_3,&local_14,1);

  }

  return;

}

/* ===== __cfltcvt @ 0x005460F4 ===== */
/* Library Function - Single Match

    __cfltcvt

   

   Library: Visual Studio 2003 Release */



errno_t __cdecl

__cfltcvt(double *arg,char *buffer,size_t sizeInBytes,int format,int precision,int caps)



{

  errno_t eVar1;

  

  if ((sizeInBytes == 0x65) || (sizeInBytes == 0x45)) {

    eVar1 = FUN_00545e42(arg,buffer,format,precision);

  }

  else {

    if (sizeInBytes == 0x66) {

      eVar1 = FUN_00545f65(arg,buffer,format);

      return eVar1;

    }

    eVar1 = FUN_00546061(arg,buffer,format,precision);

  }

  return eVar1;

}

/* ===== crt_memmove @ 0x00546145 ===== */
/* PS2 candidate: ObjectSetAnim (conf 0.587) */



void crt_memmove(char *param_1,int param_2)



{

  size_t sVar1;

  

  if (param_2 != 0) {

    sVar1 = _strlen(param_1);

    FUN_00543270(param_1 + param_2,param_1,sVar1 + 1);

  }

  return;

}

/* ===== _flsbuf @ 0x0054616A ===== */
uint _flsbuf(uint param_1,int *param_2)



{

  uint uVar1;

  uint uVar2;

  int iVar3;

  int *piVar4;

  int iVar5;

  undefined *puVar6;

  

  piVar4 = param_2;

  uVar1 = param_2[3];

  uVar2 = param_2[4];

  if (((uVar1 & 0x82) == 0) || ((uVar1 & 0x40) != 0)) {

LAB_00546276:

    param_2[3] = uVar1 | 0x20;

  }

  else {

    if ((uVar1 & 1) != 0) {

      param_2[1] = 0;

      if ((uVar1 & 0x10) == 0) goto LAB_00546276;

      *param_2 = param_2[2];

      param_2[3] = uVar1 & 0xfffffffe;

    }

    uVar1 = param_2[3];

    param_2[1] = 0;

    param_2 = (int *)0x0;

    piVar4[3] = uVar1 & 0xffffffef | 2;

    if (((uVar1 & 0x10c) == 0) &&

       (((piVar4 != (int *)&DAT_00581120 && (piVar4 != (int *)&DAT_00581140)) ||

        (iVar5 = FUN_0054d6cd(uVar2), iVar5 == 0)))) {

      FUN_0054d689(piVar4);

    }

    if ((*(ushort *)(piVar4 + 3) & 0x108) == 0) {

      iVar5 = 1;

      param_2 = (int *)_write(uVar2,&param_1,1);

    }

    else {

      iVar3 = piVar4[2];

      iVar5 = *piVar4 - iVar3;

      *piVar4 = iVar3 + 1;

      piVar4[1] = piVar4[6] + -1;

      if (iVar5 < 1) {

        if (uVar2 == 0xffffffff) {

          puVar6 = &DAT_00583ac8;

        }

        else {

          puVar6 = (undefined *)((&DAT_006578c0)[(int)uVar2 >> 5] + (uVar2 & 0x1f) * 0x24);

        }

        if ((puVar6[4] & 0x20) != 0) {

          crt_lseek_errno(uVar2,0,2);

        }

      }

      else {

        param_2 = (int *)_write(uVar2,iVar3,iVar5);

      }

      *(undefined1 *)piVar4[2] = (undefined1)param_1;

    }

    if (param_2 == (int *)iVar5) {

      return param_1 & 0xff;

    }

    piVar4[3] = piVar4[3] | 0x20;

  }

  return 0xffffffff;

}

/* ===== _output @ 0x00546282 ===== */
int _output(undefined4 param_1,byte *param_2,undefined4 *param_3)



{

  byte *pbVar1;

  short sVar2;

  uint uVar3;

  short *psVar4;

  short *psVar5;

  undefined4 uVar6;

  int *piVar7;

  int iVar8;

  byte bVar9;

  int iVar10;

  undefined1 *puVar11;

  ulonglong uVar12;

  longlong lVar13;

  undefined1 local_24c [511];

  undefined1 local_4d;

  undefined4 local_4c;

  undefined4 local_48;

  int local_44;

  int local_40;

  undefined1 local_3c [4];

  undefined4 local_38;

  int local_34;

  int local_30;

  int local_2c;

  int local_28;

  int local_24;

  int local_20;

  undefined1 local_1a;

  char local_19;

  int local_18;

  int local_14;

  undefined1 *local_10;

  short *local_c;

  uint local_8;

  

  local_34 = 0;

  bVar9 = *param_2;

  local_10 = (undefined1 *)0x0;

  local_18 = 0;

  pbVar1 = param_2;

  do {

    if ((bVar9 == 0) || (param_2 = pbVar1 + 1, local_18 < 0)) {

      return local_18;

    }

    if (((char)bVar9 < ' ') || ('x' < (char)bVar9)) {

      uVar3 = 0;

    }

    else {

      uVar3 = (byte)"GAIsProcessorFeaturePresent"[(char)bVar9 + 0x1a] & 0xf;

    }

    local_34 = (int)(char)(&DAT_005523b8)[uVar3 * 8 + local_34] >> 4;

    switch(local_34) {

    case 0:

switchD_005462f0_caseD_0:

      local_28 = 0;

      if ((PTR_DAT_00580eac[(uint)bVar9 * 2 + 1] & 0x80) != 0) {

        _outchar((int)(char)bVar9,param_1,&local_18);

        bVar9 = *param_2;

        param_2 = pbVar1 + 2;

      }

      _outchar((int)(char)bVar9,param_1,&local_18);

      break;

    case 1:

      local_14 = -1;

      local_38 = 0;

      local_2c = 0;

      local_24 = 0;

      local_20 = 0;

      local_8 = 0;

      local_28 = 0;

      break;

    case 2:

      if (bVar9 == 0x20) {

        local_8 = local_8 | 2;

      }

      else if (bVar9 == 0x23) {

        local_8 = local_8 | 0x80;

      }

      else if (bVar9 == 0x2b) {

        local_8 = local_8 | 1;

      }

      else if (bVar9 == 0x2d) {

        local_8 = local_8 | 4;

      }

      else if (bVar9 == 0x30) {

        local_8 = local_8 | 8;

      }

      break;

    case 3:

      if (bVar9 == 0x2a) {

        local_24 = crt_va_arg4(&param_3);

        if (local_24 < 0) {

          local_8 = local_8 | 4;

          local_24 = -local_24;

        }

      }

      else {

        local_24 = (char)bVar9 + -0x30 + local_24 * 10;

      }

      break;

    case 4:

      local_14 = 0;

      break;

    case 5:

      if (bVar9 == 0x2a) {

        local_14 = crt_va_arg4(&param_3);

        if (local_14 < 0) {

          local_14 = -1;

        }

      }

      else {

        local_14 = (char)bVar9 + -0x30 + local_14 * 10;

      }

      break;

    case 6:

      if (bVar9 == 0x49) {

        if ((*param_2 != 0x36) || (pbVar1[2] != 0x34)) {

          local_34 = 0;

          goto switchD_005462f0_caseD_0;

        }

        param_2 = pbVar1 + 3;

        local_8 = local_8 | 0x8000;

      }

      else if (bVar9 == 0x68) {

        local_8 = local_8 | 0x20;

      }

      else if (bVar9 == 0x6c) {

        local_8 = local_8 | 0x10;

      }

      else if (bVar9 == 0x77) {

        local_8 = local_8 | 0x800;

      }

      break;

    case 7:

      psVar5 = local_c;

      if ((char)bVar9 < 'h') {

        if ((char)bVar9 < 'e') {

          if ((char)bVar9 < 'Y') {

            if (bVar9 == 0x58) {

LAB_00546701:

              local_30 = 7;

LAB_00546708:

              local_10 = (undefined1 *)0x10;

              if ((local_8 & 0x80) != 0) {

                local_1a = 0x30;

                local_19 = (char)local_30 + 'Q';

                local_20 = 2;

              }

              goto LAB_00546772;

            }

            if (bVar9 != 0x43) {

              if ((bVar9 != 0x45) && (bVar9 != 0x47)) {

                if (bVar9 == 0x53) {

                  if ((local_8 & 0x830) == 0) {

                    local_8 = local_8 | 0x800;

                  }

                  goto LAB_005464af;

                }

                goto LAB_0054688c;

              }

              local_38 = 1;

              bVar9 = bVar9 + 0x20;

              goto LAB_00546510;

            }

            if ((local_8 & 0x830) == 0) {

              local_8 = local_8 | 0x800;

            }

LAB_0054653d:

            if ((local_8 & 0x810) == 0) {

              local_24c[0] = crt_va_arg4(&param_3);

              local_10 = (undefined1 *)0x1;

            }

            else {

              uVar6 = crt_va_arg_w();

              local_10 = (undefined1 *)crt_wctomb_lock(local_24c,uVar6);

              if ((int)local_10 < 0) {

                local_2c = 1;

              }

            }

            psVar5 = (short *)local_24c;

          }

          else if (bVar9 == 0x5a) {

            psVar4 = (short *)crt_va_arg4(&param_3);

            if ((psVar4 == (short *)0x0) ||

               (psVar5 = *(short **)(psVar4 + 2), psVar5 == (short *)0x0)) {

              local_c = (short *)PTR_DAT_005813a0;

              psVar5 = (short *)PTR_DAT_005813a0;

              goto LAB_00546682;

            }

            if ((local_8 & 0x800) == 0) {

              local_28 = 0;

              local_10 = (undefined1 *)(int)*psVar4;

            }

            else {

              local_28 = 1;

              local_10 = (undefined1 *)((uint)(int)*psVar4 >> 1);

            }

          }

          else {

            if (bVar9 == 99) goto LAB_0054653d;

            if (bVar9 == 100) goto LAB_00546767;

          }

        }

        else {

LAB_00546510:

          local_8 = local_8 | 0x40;

          psVar5 = (short *)local_24c;

          if (local_14 < 0) {

            local_14 = 6;

          }

          else if ((local_14 == 0) && (bVar9 == 0x67)) {

            local_14 = 1;

          }

          local_4c = *param_3;

          local_48 = param_3[1];

          param_3 = param_3 + 2;

          local_c = psVar5;

          (*(code *)PTR_FUN_0054D5A8_00581388)

                    (&local_4c,local_24c,(int)(char)bVar9,local_14,local_38);

          uVar3 = local_8 & 0x80;

          if ((uVar3 != 0) && (local_14 == 0)) {

            (*(code *)PTR_FUN_0054D5A8_00581394)(local_24c);

          }

          if ((bVar9 == 0x67) && (uVar3 == 0)) {

            (*(code *)PTR_FUN_0054D5A8_0058138c)(local_24c);

          }

          if (local_24c[0] == '-') {

            local_8 = local_8 | 0x100;

            psVar5 = (short *)(local_24c + 1);

            local_c = psVar5;

          }

LAB_00546682:

          local_10 = (undefined1 *)_strlen((char *)psVar5);

          psVar5 = local_c;

        }

      }

      else {

        if (bVar9 == 0x69) {

LAB_00546767:

          local_8 = local_8 | 0x40;

        }

        else {

          if (bVar9 == 0x6e) {

            piVar7 = (int *)crt_va_arg4(&param_3);

            if ((local_8 & 0x20) == 0) {

              *piVar7 = local_18;

            }

            else {

              *(undefined2 *)piVar7 = (undefined2)local_18;

            }

            local_2c = 1;

            break;

          }

          if (bVar9 == 0x6f) {

            local_10 = (undefined1 *)0x8;

            if ((local_8 & 0x80) != 0) {

              local_8 = local_8 | 0x200;

            }

            goto LAB_00546772;

          }

          if (bVar9 == 0x70) {

            local_14 = 8;

            goto LAB_00546701;

          }

          if (bVar9 == 0x73) {

LAB_005464af:

            iVar10 = local_14;

            if (local_14 == -1) {

              iVar10 = 0x7fffffff;

            }

            psVar4 = (short *)crt_va_arg4(&param_3);

            if ((local_8 & 0x810) == 0) {

              psVar5 = psVar4;

              if (psVar4 == (short *)0x0) {

                psVar4 = (short *)PTR_DAT_005813a0;

                psVar5 = (short *)PTR_DAT_005813a0;

              }

              for (; (iVar10 != 0 && ((char)*psVar4 != '\0')); psVar4 = (short *)((int)psVar4 + 1))

              {

                iVar10 = iVar10 + -1;

              }

              local_10 = (undefined1 *)((int)psVar4 - (int)psVar5);

            }

            else {

              if (psVar4 == (short *)0x0) {

                psVar4 = (short *)PTR_DAT_005813a4;

              }

              local_28 = 1;

              for (psVar5 = psVar4; (iVar10 != 0 && (*psVar5 != 0)); psVar5 = psVar5 + 1) {

                iVar10 = iVar10 + -1;

              }

              local_10 = (undefined1 *)((int)psVar5 - (int)psVar4 >> 1);

              psVar5 = psVar4;

            }

            goto LAB_0054688c;

          }

          if (bVar9 != 0x75) {

            if (bVar9 != 0x78) goto LAB_0054688c;

            local_30 = 0x27;

            goto LAB_00546708;

          }

        }

        local_10 = (undefined1 *)0xa;

LAB_00546772:

        if ((local_8 & 0x8000) == 0) {

          if ((local_8 & 0x20) == 0) {

            if ((local_8 & 0x40) == 0) {

              uVar3 = crt_va_arg4(&param_3);

              uVar12 = (ulonglong)uVar3;

              goto LAB_005467c5;

            }

            uVar3 = crt_va_arg4(&param_3);

          }

          else if ((local_8 & 0x40) == 0) {

            uVar3 = crt_va_arg4(&param_3);

            uVar3 = uVar3 & 0xffff;

          }

          else {

            sVar2 = crt_va_arg4(&param_3);

            uVar3 = (uint)sVar2;

          }

          uVar12 = (ulonglong)(int)uVar3;

        }

        else {

          uVar12 = crt_va_arg8(&param_3);

        }

LAB_005467c5:

        if ((((local_8 & 0x40) != 0) && ((longlong)uVar12 < 0x100000000)) && ((longlong)uVar12 < 0))

        {

          uVar12 = CONCAT44(-((int)(uVar12 >> 0x20) + (uint)((int)uVar12 != 0)),-(int)uVar12);

          local_8 = local_8 | 0x100;

        }

        iVar10 = (int)(uVar12 >> 0x20);

        if ((local_8 & 0x8000) == 0) {

          iVar10 = 0;

        }

        lVar13 = CONCAT44(iVar10,(int)uVar12);

        if (local_14 < 0) {

          local_14 = 1;

        }

        else {

          local_8 = local_8 & 0xfffffff7;

        }

        if ((int)uVar12 == 0 && iVar10 == 0) {

          local_20 = 0;

        }

        local_c = (short *)&local_4d;

        while ((iVar10 = local_14 + -1, 0 < local_14 || (lVar13 != 0))) {

          local_40 = (int)local_10 >> 0x1f;

          local_44 = (int)local_10;

          local_14 = iVar10;

          iVar10 = __aullrem(lVar13,local_10,local_40);

          iVar10 = iVar10 + 0x30;

          lVar13 = __aulldiv(lVar13,local_44,local_40);

          if (0x39 < iVar10) {

            iVar10 = iVar10 + local_30;

          }

          psVar5 = (short *)((int)local_c + -1);

          *(char *)local_c = (char)iVar10;

          local_c = psVar5;

        }

        iVar8 = -(int)local_c;

        local_10 = &local_4d + iVar8;

        psVar5 = (short *)((int)local_c + 1);

        local_14 = iVar10;

        if (((local_8 & 0x200) != 0) &&

           ((*(char *)psVar5 != '0' || (local_10 == (undefined1 *)0x0)))) {

          *(char *)local_c = '0';

          local_10 = (undefined1 *)((int)&local_4c + iVar8);

          psVar5 = local_c;

        }

      }

LAB_0054688c:

      local_c = psVar5;

      uVar3 = local_8;

      if (local_2c == 0) {

        if ((local_8 & 0x40) != 0) {

          if ((local_8 & 0x100) == 0) {

            if ((local_8 & 1) == 0) {

              if ((local_8 & 2) == 0) goto LAB_005468c4;

              local_1a = 0x20;

            }

            else {

              local_1a = 0x2b;

            }

          }

          else {

            local_1a = 0x2d;

          }

          local_20 = 1;

        }

LAB_005468c4:

        iVar10 = (local_24 - local_20) - (int)local_10;

        if ((local_8 & 0xc) == 0) {

          _write_multi_char(0x20,iVar10,param_1,&local_18);

        }

        _write_string(&local_1a,local_20,param_1,&local_18);

        if (((uVar3 & 8) != 0) && ((uVar3 & 4) == 0)) {

          _write_multi_char(0x30,iVar10,param_1,&local_18);

        }

        if ((local_28 == 0) || (puVar11 = local_10, psVar5 = local_c, (int)local_10 < 1)) {

          _write_string(local_c,local_10,param_1,&local_18);

        }

        else {

          do {

            puVar11 = puVar11 + -1;

            iVar8 = crt_wctomb_lock(local_3c,*psVar5);

            if (iVar8 < 1) break;

            _write_string(local_3c,iVar8,param_1,&local_18);

            psVar5 = psVar5 + 1;

          } while (puVar11 != (undefined1 *)0x0);

        }

        if ((local_8 & 4) != 0) {

          _write_multi_char(0x20,iVar10,param_1,&local_18);

        }

      }

    }

    bVar9 = *param_2;

    pbVar1 = param_2;

  } while( true );

}

/* ===== _outchar @ 0x005469C3 ===== */
void _outchar(uint param_1,int *param_2,int *param_3)



{

  int *piVar1;

  

  piVar1 = param_2 + 1;

  *piVar1 = *piVar1 + -1;

  if (*piVar1 < 0) {

    param_1 = _flsbuf(param_1,param_2);

  }

  else {

    *(undefined1 *)*param_2 = (undefined1)param_1;

    *param_2 = *param_2 + 1;

    param_1 = param_1 & 0xff;

  }

  if (param_1 == 0xffffffff) {

    *param_3 = -1;

    return;

  }

  *param_3 = *param_3 + 1;

  return;

}

/* ===== _write_multi_char @ 0x005469F8 ===== */
void _write_multi_char(undefined4 param_1,int param_2,undefined4 param_3,int *param_4)



{

  do {

    if (param_2 < 1) {

      return;

    }

    param_2 = param_2 + -1;

    _outchar(param_1,param_3,param_4);

  } while (*param_4 != -1);

  return;

}

/* ===== _write_string @ 0x00546A29 ===== */
void _write_string(char *param_1,int param_2,undefined4 param_3,int *param_4)



{

  char cVar1;

  

  do {

    if (param_2 < 1) {

      return;

    }

    param_2 = param_2 + -1;

    cVar1 = *param_1;

    param_1 = param_1 + 1;

    _outchar((int)cVar1,param_3,param_4);

  } while (*param_4 != -1);

  return;

}

/* ===== crt_va_arg4 @ 0x00546A61 ===== */
undefined4 crt_va_arg4(int *param_1)



{

  *param_1 = *param_1 + 4;

  return *(undefined4 *)(*param_1 + -4);

}

/* ===== crt_va_arg8 @ 0x00546A6E ===== */
undefined8 crt_va_arg8(int *param_1)



{

  *param_1 = *param_1 + 8;

  return *(undefined8 *)(*param_1 + -8);

}

/* ===== crt_va_arg_w @ 0x00546A7E ===== */
undefined4 crt_va_arg_w(int *param_1)



{

  *param_1 = *param_1 + 4;

  return CONCAT22((short)((uint)*param_1 >> 0x10),*(undefined2 *)(*param_1 + -4));

}

/* ===== crt_fatal_exit @ 0x00546A8C ===== */
/* PS2 candidate: _resetGsDmaPackets__Fv (conf 0.679) */



void crt_fatal_exit(void)



{

  __rt_error_box_2(10);

  raise(0x16);

                    /* WARNING: Subroutine does not return */

  __exit(3);

}

/* ===== fclose @ 0x00546AA3 ===== */
undefined4 fclose(int param_1)



{

  undefined4 uVar1;

  

  if (param_1 == 0) {

    uVar1 = _fcloseall(0);

    return uVar1;

  }

  crt_file_lock(param_1);

  uVar1 = _fclose_lk(param_1);

  crt_file_unlock(param_1);

  return uVar1;

}

/* ===== _fclose_lk @ 0x00546AD2 ===== */
int _fclose_lk(int param_1)



{

  int iVar1;

  

  iVar1 = _flush(param_1);

  if (iVar1 != 0) {

    return -1;

  }

  if ((*(byte *)(param_1 + 0xd) & 0x40) != 0) {

    iVar1 = crt_close_osf(*(undefined4 *)(param_1 + 0x10));

    return -(uint)(iVar1 != 0);

  }

  return 0;

}

/* ===== _flush @ 0x00546B00 ===== */
undefined4 _flush(int *param_1)



{

  int iVar1;

  undefined4 uVar2;

  int iVar3;

  

  uVar2 = 0;

  if ((((byte)param_1[3] & 3) == 2) && ((param_1[3] & 0x108U) != 0)) {

    iVar3 = *param_1 - param_1[2];

    if (0 < iVar3) {

      iVar1 = _write(param_1[4],param_1[2],iVar3);

      if (iVar1 == iVar3) {

        if ((param_1[3] & 0x80U) != 0) {

          param_1[3] = param_1[3] & 0xfffffffd;

        }

      }

      else {

        param_1[3] = param_1[3] | 0x20;

        uVar2 = 0xffffffff;

      }

    }

  }

  param_1[1] = 0;

  *param_1 = param_1[2];

  return uVar2;

}

/* ===== _fcloseall @ 0x00546B65 ===== */
int _fcloseall(int param_1)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  

  iVar2 = 0;

  iVar4 = 0;

  _lock(2);

  iVar3 = 0;

  if (0 < DAT_00658a00) {

    do {

      iVar1 = *(int *)(DAT_006579f4 + iVar3 * 4);

      if ((iVar1 != 0) && ((*(byte *)(iVar1 + 0xc) & 0x83) != 0)) {

        crt_file_lock_2(iVar3,iVar1);

        iVar1 = *(int *)(DAT_006579f4 + iVar3 * 4);

        if ((*(uint *)(iVar1 + 0xc) & 0x83) != 0) {

          if (param_1 == 1) {

            iVar1 = _fclose_lk(iVar1);

            if (iVar1 != -1) {

              iVar2 = iVar2 + 1;

            }

          }

          else if ((param_1 == 0) && ((*(uint *)(iVar1 + 0xc) & 2) != 0)) {

            iVar1 = _fclose_lk(iVar1);

            if (iVar1 == -1) {

              iVar4 = -1;

            }

          }

        }

        crt_file_unlock_2(iVar3,*(undefined4 *)(DAT_006579f4 + iVar3 * 4));

      }

      iVar3 = iVar3 + 1;

    } while (iVar3 < DAT_00658a00);

  }

  _unlock(2);

  if (param_1 != 1) {

    iVar2 = iVar4;

  }

  return iVar2;

}

/* ===== raise @ 0x00546C09 ===== */
undefined4 raise(int param_1)



{

  bool bVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  code *pcVar5;

  undefined4 *puVar6;

  undefined4 local_10;

  undefined4 local_c;

  

  bVar1 = false;

  if (param_1 == 2) {

    puVar6 = &DAT_00630bb0;

    pcVar5 = DAT_00630bb0;

LAB_00546c8f:

    bVar1 = true;

    _lock(1);

    iVar2 = param_1;

  }

  else {

    if (((param_1 != 4) && (param_1 != 8)) && (param_1 != 0xb)) {

      if (param_1 == 0xf) {

        puVar6 = &DAT_00630bbc;

        pcVar5 = DAT_00630bbc;

      }

      else if (param_1 == 0x15) {

        puVar6 = &DAT_00630bb4;

        pcVar5 = DAT_00630bb4;

      }

      else {

        if (param_1 != 0x16) {

          return 0xffffffff;

        }

        puVar6 = &DAT_00630bb8;

        pcVar5 = DAT_00630bb8;

      }

      goto LAB_00546c8f;

    }

    iVar2 = __getptd();

    iVar4 = crt_siglookup(param_1,*(undefined4 *)(iVar2 + 0x50));

    puVar6 = (undefined4 *)(iVar4 + 8);

    pcVar5 = (code *)*puVar6;

  }

  if (pcVar5 == (code *)0x1) {

    if (!bVar1) {

      return 0;

    }

    _unlock(1);

    return 0;

  }

  if (pcVar5 == (code *)0x0) {

    if (bVar1) {

      _unlock(1);

    }

                    /* WARNING: Subroutine does not return */

    __exit(3);

  }

  if (((param_1 == 8) || (param_1 == 0xb)) || (param_1 == 4)) {

    local_c = *(undefined4 *)(iVar2 + 0x54);

    *(undefined4 *)(iVar2 + 0x54) = 0;

    if (param_1 == 8) {

      local_10 = *(undefined4 *)(iVar2 + 0x58);

      *(undefined4 *)(iVar2 + 0x58) = 0x8c;

      goto LAB_00546d03;

    }

  }

  else {

LAB_00546d03:

    if (param_1 == 8) {

      if (DAT_00583ab8 < DAT_00583abc + DAT_00583ab8) {

        iVar3 = DAT_00583ab8 * 0xc;

        iVar4 = DAT_00583ab8;

        do {

          iVar3 = iVar3 + 0xc;

          *(undefined4 *)(*(int *)(iVar2 + 0x50) + -4 + iVar3) = 0;

          iVar4 = iVar4 + 1;

        } while (iVar4 < DAT_00583abc + DAT_00583ab8);

      }

      goto LAB_00546d41;

    }

  }

  *puVar6 = 0;

LAB_00546d41:

  if (bVar1) {

    _unlock(1);

  }

  if (param_1 == 8) {

    (*pcVar5)(8,*(undefined4 *)(iVar2 + 0x58));

  }

  else {

    (*pcVar5)(param_1);

    if ((param_1 != 0xb) && (param_1 != 4)) {

      return 0;

    }

  }

  *(undefined4 *)(iVar2 + 0x54) = local_c;

  if (param_1 == 8) {

    *(undefined4 *)(iVar2 + 0x58) = local_10;

  }

  return 0;

}

/* ===== crt_siglookup @ 0x00546D8B ===== */
uint crt_siglookup(int param_1,uint param_2)



{

  int *piVar1;

  uint uVar2;

  uint uVar3;

  

  uVar2 = param_2;

  if (*(int *)(param_2 + 4) != param_1) {

    uVar3 = param_2;

    do {

      uVar2 = uVar3 + 0xc;

      if (param_2 + DAT_00583ac4 * 0xc <= uVar2) break;

      piVar1 = (int *)(uVar3 + 0x10);

      uVar3 = uVar2;

    } while (*piVar1 != param_1);

  }

  if ((param_2 + DAT_00583ac4 * 0xc <= uVar2) || (*(int *)(uVar2 + 4) != param_1)) {

    uVar2 = 0;

  }

  return uVar2;

}

/* ===== __crtMessageBoxA @ 0x00546DC8 ===== */
int __crtMessageBoxA(undefined4 param_1,undefined4 param_2,undefined4 param_3)



{

  HMODULE hModule;

  int iVar1;

  

  iVar1 = 0;

  if (DAT_00630bc4 == (FARPROC)0x0) {

    hModule = LoadLibraryA("user32.dll");

    if (hModule != (HMODULE)0x0) {

      DAT_00630bc4 = GetProcAddress(hModule,"MessageBoxA");

      if (DAT_00630bc4 != (FARPROC)0x0) {

        DAT_00630bc8 = GetProcAddress(hModule,"GetActiveWindow");

        DAT_00630bcc = GetProcAddress(hModule,"GetLastActivePopup");

        goto LAB_00546e17;

      }

    }

    iVar1 = 0;

  }

  else {

LAB_00546e17:

    if (DAT_00630bc8 != (FARPROC)0x0) {

      iVar1 = (*DAT_00630bc8)();

      if ((iVar1 != 0) && (DAT_00630bcc != (FARPROC)0x0)) {

        iVar1 = (*DAT_00630bcc)(iVar1);

      }

    }

    iVar1 = (*DAT_00630bc4)(iVar1,param_1,param_2,param_3);

  }

  return iVar1;

}

/* ===== _strlen @ 0x00546E60 ===== */
/* Library Function - Single Match

    _strlen

   

   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */



size_t __cdecl _strlen(char *_Str)



{

  uint uVar1;

  uint *puVar2;

  uint *puVar3;

  

  puVar2 = (uint *)_Str;

  do {

    if (((uint)puVar2 & 3) == 0) goto LAB_00546e80;

    uVar1 = *puVar2;

    puVar2 = (uint *)((int)puVar2 + 1);

  } while ((char)uVar1 != '\0');

LAB_00546eb3:

  return (size_t)((int)puVar2 + (-1 - (int)_Str));

LAB_00546e80:

  do {

    do {

      puVar3 = puVar2;

      puVar2 = puVar3 + 1;

    } while (((*puVar3 ^ 0xffffffff ^ *puVar3 + 0x7efefeff) & 0x81010100) == 0);

    uVar1 = *puVar3;

    if ((char)uVar1 == '\0') {

      return (int)puVar3 - (int)_Str;

    }

    if ((char)(uVar1 >> 8) == '\0') {

      return (size_t)((int)puVar3 + (1 - (int)_Str));

    }

    if ((uVar1 & 0xff0000) == 0) {

      return (size_t)((int)puVar3 + (2 - (int)_Str));

    }

  } while ((uVar1 & 0xff000000) != 0);

  goto LAB_00546eb3;

}

/* ===== strcpy @ 0x00546EE0 ===== */
uint * strcpy(uint *param_1,uint *param_2)



{

  byte bVar1;

  uint uVar2;

  uint uVar3;

  uint *puVar4;

  

  puVar4 = param_1;

  while (((uint)param_2 & 3) != 0) {

    bVar1 = (byte)*param_2;

    uVar3 = (uint)bVar1;

    param_2 = (uint *)((int)param_2 + 1);

    if (bVar1 == 0) goto LAB_00546fc8;

    *(byte *)puVar4 = bVar1;

    puVar4 = (uint *)((int)puVar4 + 1);

  }

  do {

    uVar2 = *param_2;

    uVar3 = *param_2;

    param_2 = param_2 + 1;

    if (((uVar2 ^ 0xffffffff ^ uVar2 + 0x7efefeff) & 0x81010100) != 0) {

      if ((char)uVar3 == '\0') {

LAB_00546fc8:

        *(byte *)puVar4 = (byte)uVar3;

        return param_1;

      }

      if ((char)(uVar3 >> 8) == '\0') {

        *(short *)puVar4 = (short)uVar3;

        return param_1;

      }

      if ((uVar3 & 0xff0000) == 0) {

        *(short *)puVar4 = (short)uVar3;

        *(byte *)((int)puVar4 + 2) = 0;

        return param_1;

      }

      if ((uVar3 & 0xff000000) == 0) {

        *puVar4 = uVar3;

        return param_1;

      }

    }

    *puVar4 = uVar3;

    puVar4 = puVar4 + 1;

  } while( true );

}

/* ===== strcpy_2 @ 0x00546EF0 ===== */
uint * strcpy_2(uint *param_1,uint *param_2)



{

  byte bVar1;

  uint uVar2;

  uint *puVar3;

  uint uVar4;

  uint *puVar5;

  

  puVar3 = param_1;

  do {

    if (((uint)puVar3 & 3) == 0) goto LAB_00546f0c;

    uVar4 = *puVar3;

    puVar3 = (uint *)((int)puVar3 + 1);

  } while ((byte)uVar4 != 0);

  goto LAB_00546f3f;

  while( true ) {

    if ((uVar4 & 0xff0000) == 0) {

      puVar5 = (uint *)((int)puVar5 + 2);

      goto joined_r0x00546f5b;

    }

    if ((uVar4 & 0xff000000) == 0) break;

LAB_00546f0c:

    do {

      puVar5 = puVar3;

      puVar3 = puVar5 + 1;

    } while (((*puVar5 ^ 0xffffffff ^ *puVar5 + 0x7efefeff) & 0x81010100) == 0);

    uVar4 = *puVar5;

    if ((char)uVar4 == '\0') goto joined_r0x00546f5b;

    if ((char)(uVar4 >> 8) == '\0') {

      puVar5 = (uint *)((int)puVar5 + 1);

      goto joined_r0x00546f5b;

    }

  }

LAB_00546f3f:

  puVar5 = (uint *)((int)puVar3 + -1);

joined_r0x00546f5b:

  do {

    if (((uint)param_2 & 3) == 0) {

      do {

        uVar2 = *param_2;

        uVar4 = *param_2;

        param_2 = param_2 + 1;

        if (((uVar2 ^ 0xffffffff ^ uVar2 + 0x7efefeff) & 0x81010100) != 0) {

          if ((char)uVar4 == '\0') {

LAB_00546fc8:

            *(byte *)puVar5 = (byte)uVar4;

            return param_1;

          }

          if ((char)(uVar4 >> 8) == '\0') {

            *(short *)puVar5 = (short)uVar4;

            return param_1;

          }

          if ((uVar4 & 0xff0000) == 0) {

            *(short *)puVar5 = (short)uVar4;

            *(byte *)((int)puVar5 + 2) = 0;

            return param_1;

          }

          if ((uVar4 & 0xff000000) == 0) {

            *puVar5 = uVar4;

            return param_1;

          }

        }

        *puVar5 = uVar4;

        puVar5 = puVar5 + 1;

      } while( true );

    }

    bVar1 = (byte)*param_2;

    uVar4 = (uint)bVar1;

    param_2 = (uint *)((int)param_2 + 1);

    if (bVar1 == 0) goto LAB_00546fc8;

    *(byte *)puVar5 = bVar1;

    puVar5 = (uint *)((int)puVar5 + 1);

  } while( true );

}

/* ===== _ftol2 @ 0x00546FD0 ===== */
float10 _ftol2(undefined4 param_1,double param_2,undefined4 param_3)



{

  undefined4 *puVar1;

  float10 fVar2;

  

  if (DAT_00583bb0 == 0) {

    fVar2 = (float10)crt_fpe_dispatch(1,param_1,param_2,0,param_2,param_3);

    return fVar2;

  }

  puVar1 = (undefined4 *)_errno();

  *puVar1 = 0x21;

  crt_fnstcw();

  return (float10)param_2;

}

/* ===== _ftol2_r @ 0x00547024 ===== */
float10 _ftol2_r(undefined4 param_1,undefined4 param_2,undefined8 param_3,double param_4,

                undefined4 param_5)



{

  int iVar1;

  float10 fVar2;

  

  iVar1 = crt_fpe_checkmask(param_1,&param_4,param_5);

  if (iVar1 == 0) {

    crt_fpe_raise();

  }

  iVar1 = crt_fpe_sigcode(param_1);

  if ((DAT_00583bb0 == 0) && (iVar1 != 0)) {

    fVar2 = (float10)crt_fpe_dispatch(iVar1,param_2,param_3,0,param_4,param_5);

    return fVar2;

  }

  crt_matherr_flag(iVar1);

  crt_fnstcw();

  return (float10)param_4;

}

/* ===== crt_fpe_raise @ 0x005470BC ===== */
void crt_fpe_raise(uint *param_1,uint *param_2,uint param_3,uint param_4,undefined8 *param_5,

                  undefined8 *param_6)



{

  uint *puVar1;

  undefined8 *puVar2;

  byte bVar3;

  uint uVar4;

  

  uVar4 = param_3;

  puVar1 = param_2;

  param_1[1] = 0;

  param_1[2] = 0;

  param_1[3] = 0;

  if ((param_3 & 0x10) != 0) {

    param_3 = 0xc000008f;

    param_1[1] = param_1[1] | 1;

  }

  if ((uVar4 & 2) != 0) {

    param_3 = 0xc0000093;

    param_1[1] = param_1[1] | 2;

  }

  if ((uVar4 & 1) != 0) {

    param_3 = 0xc0000091;

    param_1[1] = param_1[1] | 4;

  }

  if ((uVar4 & 4) != 0) {

    param_3 = 0xc000008e;

    param_1[1] = param_1[1] | 8;

  }

  if ((uVar4 & 8) != 0) {

    param_3 = 0xc0000090;

    param_1[1] = param_1[1] | 0x10;

  }

  param_1[2] = (~*param_2 & 1) << 4 | param_1[2] & 0xffffffef;

  param_1[2] = (~*param_2 & 4) << 1 | param_1[2] & 0xfffffff7;

  param_1[2] = ~*param_2 >> 1 & 4 | param_1[2] & 0xfffffffb;

  param_1[2] = ~*param_2 >> 3 & 2 | param_1[2] & 0xfffffffd;

  param_1[2] = ~*param_2 >> 5 & 1 | param_1[2] & 0xfffffffe;

  bVar3 = crt_fnstsw();

  puVar2 = param_6;

  if ((bVar3 & 1) != 0) {

    param_1[3] = param_1[3] | 0x10;

  }

  if ((bVar3 & 4) != 0) {

    param_1[3] = param_1[3] | 8;

  }

  if ((bVar3 & 8) != 0) {

    param_1[3] = param_1[3] | 4;

  }

  if ((bVar3 & 0x10) != 0) {

    param_1[3] = param_1[3] | 2;

  }

  if ((bVar3 & 0x20) != 0) {

    param_1[3] = param_1[3] | 1;

  }

  uVar4 = *puVar1 & 0xc00;

  if (uVar4 == 0) {

    *param_1 = *param_1 & 0xfffffffc;

  }

  else {

    if (uVar4 == 0x400) {

      uVar4 = *param_1 & 0xfffffffd | 1;

    }

    else {

      if (uVar4 != 0x800) {

        if (uVar4 == 0xc00) {

          *param_1 = *param_1 | 3;

        }

        goto LAB_00547231;

      }

      uVar4 = *param_1 & 0xfffffffe | 2;

    }

    *param_1 = uVar4;

  }

LAB_00547231:

  uVar4 = *puVar1 & 0x300;

  if (uVar4 == 0) {

    uVar4 = *param_1 & 0xffffffeb | 8;

LAB_00547267:

    *param_1 = uVar4;

  }

  else {

    if (uVar4 == 0x200) {

      uVar4 = *param_1 & 0xffffffe7 | 4;

      goto LAB_00547267;

    }

    if (uVar4 == 0x300) {

      *param_1 = *param_1 & 0xffffffe3;

    }

  }

  *param_1 = (param_4 & 0xfff) << 5 | *param_1 & 0xfffe001f;

  param_1[8] = param_1[8] | 1;

  param_1[8] = param_1[8] & 0xffffffe3 | 2;

  *(undefined8 *)(param_1 + 4) = *param_5;

  param_1[0x14] = param_1[0x14] | 1;

  param_1[0x14] = param_1[0x14] & 0xffffffe3 | 2;

  *(undefined8 *)(param_1 + 0x10) = *param_6;

  crt_fnstsw2();

  RaiseException(param_3,0,1,(ULONG_PTR *)&param_1);

  if ((param_1[2] & 0x10) != 0) {

    *puVar1 = *puVar1 & 0xfffffffe;

  }

  if ((param_1[2] & 8) != 0) {

    *puVar1 = *puVar1 & 0xfffffffb;

  }

  if ((param_1[2] & 4) != 0) {

    *puVar1 = *puVar1 & 0xfffffff7;

  }

  if ((param_1[2] & 2) != 0) {

    *puVar1 = *puVar1 & 0xffffffef;

  }

  if ((param_1[2] & 1) != 0) {

    *puVar1 = *puVar1 & 0xffffffdf;

  }

  uVar4 = *param_1 & 3;

  if (uVar4 == 0) {

    *puVar1 = *puVar1 & 0xfffff3ff;

  }

  else {

    if (uVar4 == 1) {

      uVar4 = *puVar1 & 0xfffff7ff | 0x400;

    }

    else {

      if (uVar4 != 2) {

        if (uVar4 == 3) {

          *(byte *)((int)puVar1 + 1) = *(byte *)((int)puVar1 + 1) | 0xc;

        }

        goto LAB_0054733c;

      }

      uVar4 = *puVar1 & 0xfffffbff | 0x800;

    }

    *puVar1 = uVar4;

  }

LAB_0054733c:

  uVar4 = *param_1 >> 2 & 7;

  if (uVar4 == 0) {

    uVar4 = *puVar1 & 0xfffff3ff | 0x300;

  }

  else {

    if (uVar4 != 1) {

      if (uVar4 == 2) {

        *puVar1 = *puVar1 & 0xfffff3ff;

      }

      goto LAB_00547365;

    }

    uVar4 = *puVar1 & 0xfffff3ff | 0x200;

  }

  *puVar1 = uVar4;

LAB_00547365:

  *puVar2 = *(undefined8 *)(param_1 + 0x10);

  return;

}

/* ===== crt_fpe_checkmask @ 0x0054736F ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



bool crt_fpe_checkmask(uint param_1,double *param_2,uint param_3)



{

  double dVar1;

  bool bVar2;

  uint uVar3;

  bool bVar4;

  float10 fVar5;

  undefined8 local_10;

  int local_8;

  

  uVar3 = param_1 & 0x1f;

  bVar2 = true;

  if (((param_1 & 8) != 0) && ((param_3 & 1) != 0)) {

    ANM_DumpCluster_6(1);

    uVar3 = param_1 & 0x17;

    goto LAB_00547564;

  }

  if (((param_1 & 4) != 0) && ((param_3 & 4) != 0)) {

    ANM_DumpCluster_6(4);

    uVar3 = param_1 & 0x1b;

    goto LAB_00547564;

  }

  if (((param_1 & 1) == 0) || ((param_3 & 8) == 0)) {

    if (((param_1 & 2) != 0) && ((param_3 & 0x10) != 0)) {

      bVar4 = (param_1 & 0x10) != 0;

      if (*param_2 != 0.0) {

        fVar5 = (float10)crt_frexp(*param_2,&local_8);

        local_8 = local_8 + -0x600;

        if (local_8 < -0x432) {

          local_10 = 0.0;

          bVar4 = bVar2;

        }

        else {

          local_10 = (double)(ulonglong)

                             (SUB87((double)fVar5,0) & 0xfffffffffffff | 0x10000000000000);

          if (local_8 < -0x3fd) {

            local_8 = -0x3fd - local_8;

            do {

              if ((((ulonglong)local_10 & 1) != 0) && (!bVar4)) {

                bVar4 = bVar2;

              }

              uVar3 = (uint)local_10 >> 1;

              if (((ulonglong)local_10 & 0x100000000) != 0) {

                local_10._3_1_ = (byte)((ulonglong)local_10 >> 0x18) >> 1;

                local_10._0_3_ = (undefined3)uVar3;

                local_10._0_4_ = CONCAT13(local_10._3_1_,(undefined3)local_10) | 0x80000000;

                uVar3 = (uint)local_10;

              }

              local_10._0_4_ = uVar3;

              local_10 = (double)CONCAT44(local_10._4_4_ >> 1,(uint)local_10);

              local_8 = local_8 + -1;

            } while (local_8 != 0);

          }

          if ((double)fVar5 < 0.0) {

            local_10 = -local_10;

          }

        }

        *param_2 = local_10;

        bVar2 = bVar4;

      }

      if (bVar2) {

        ANM_DumpCluster_6(0x10);

      }

      uVar3 = param_1 & 0x1d;

    }

    goto LAB_00547564;

  }

  ANM_DumpCluster_6(8);

  uVar3 = param_3 & 0xc00;

  dVar1 = _DAT_00581488;

  if (uVar3 == 0) {

    if (*param_2 <= 0.0) {

      dVar1 = -_DAT_00581488;

    }

LAB_00547484:

    *param_2 = dVar1;

  }

  else {

    if (uVar3 == 0x400) {

      dVar1 = _DAT_00581498;

      if (*param_2 <= 0.0) {

        dVar1 = -_DAT_00581488;

      }

      goto LAB_00547484;

    }

    if (uVar3 == 0x800) {

      if (*param_2 <= 0.0) {

        dVar1 = -_DAT_00581498;

      }

      goto LAB_00547484;

    }

    if (uVar3 == 0xc00) {

      dVar1 = _DAT_00581498;

      if (*param_2 <= 0.0) {

        dVar1 = -_DAT_00581498;

      }

      goto LAB_00547484;

    }

  }

  uVar3 = param_1 & 0x1e;

LAB_00547564:

  if (((param_1 & 0x10) != 0) && ((param_3 & 0x20) != 0)) {

    ANM_DumpCluster_6(0x20);

    uVar3 = uVar3 & 0xffffffef;

  }

  return uVar3 == 0;

}

/* ===== crt_fpe_dispatch @ 0x00547586 ===== */
float10 crt_fpe_dispatch(undefined4 param_1,undefined4 param_2)



{

  int iVar1;

  undefined4 in_stack_0000001c;

  undefined4 in_stack_00000020;

  undefined4 in_stack_00000024;

  

  iVar1 = GetOdIcon__FUi(param_2);

  if (iVar1 != 0) {

    crt_fnstcw(in_stack_00000024,0xffff);

    iVar1 = AudioDataStreamStatus__Fv_8();

    if (iVar1 == 0) {

      crt_matherr_flag(param_1);

    }

    return (float10)(double)CONCAT44(in_stack_00000020,in_stack_0000001c);

  }

  crt_fnstcw(in_stack_00000024,0xffff);

  crt_matherr_flag(param_1);

  return (float10)(double)CONCAT44(in_stack_00000020,in_stack_0000001c);

}

/* ===== crt_matherr_flag @ 0x0054760E ===== */
void crt_matherr_flag(int param_1)



{

  undefined4 *puVar1;

  

  if (param_1 == 1) {

    puVar1 = (undefined4 *)_errno();

    *puVar1 = 0x21;

  }

  else if ((1 < param_1) && (param_1 < 4)) {

    puVar1 = (undefined4 *)_errno();

    *puVar1 = 0x22;

    return;

  }

  return;

}

/* ===== GetOdIcon__FUi @ 0x00547636 ===== */
/* PS2 candidate: GetOdIcon__FUi (conf 0.804) */



undefined4 GetOdIcon__FUi(int param_1)



{

  int *piVar1;

  int iVar2;

  

  iVar2 = 0;

  piVar1 = &DAT_005813b0;

  do {

    if (*piVar1 == param_1) {

      return *(undefined4 *)(iVar2 * 8 + 0x5813b4);

    }

    piVar1 = piVar1 + 2;

    iVar2 = iVar2 + 1;

  } while ((int)piVar1 < 0x581488);

  return 0;

}

/* ===== crt_fpe_sigcode @ 0x0054765B ===== */
int crt_fpe_sigcode(byte param_1)



{

  undefined4 uStack_4;

  

  if ((param_1 & 0x20) == 0) {

    if ((param_1 & 8) == 0) {

      if ((param_1 & 4) == 0) {

        if ((param_1 & 1) == 0) {

          return (param_1 & 2) << 1;

        }

        uStack_4 = 3;

      }

      else {

        uStack_4 = 2;

      }

    }

    else {

      uStack_4 = 1;

    }

  }

  else {

    uStack_4 = 5;

  }

  return uStack_4;

}

/* ===== __frnd @ 0x00547688 ===== */
/* Library Function - Single Match

    __frnd

   

   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release, Visual Studio 2012 Release,

   Visual Studio 2019 Release */



float10 __frnd(double param_1)



{

  return (float10)ROUND(param_1);

}

/* ===== crt_ldexp10 @ 0x0054769A ===== */
float10 crt_ldexp10(undefined8 param_1,short param_2)



{

  undefined8 local_c;

  

  local_c = (double)CONCAT26((param_2 + 0x3fe) * 0x10 | param_1._6_2_ & 0x800f,(undefined6)param_1);

  return (float10)local_c;

}

/* ===== _fpclass @ 0x005476C3 ===== */
undefined4 _fpclass(int param_1,uint param_2)



{

  undefined4 uStack_8;

  

  if (param_2 == 0x7ff00000) {

    if (param_1 == 0) {

      return 1;

    }

  }

  else if ((param_2 == 0xfff00000) && (param_1 == 0)) {

    return 2;

  }

  if ((param_2._2_2_ & 0x7ff8) == 0x7ff8) {

    uStack_8 = 3;

  }

  else {

    if (((param_2._2_2_ & 0x7ff8) != 0x7ff0) || (((param_2 & 0x7ffff) == 0 && (param_1 == 0)))) {

      return 0;

    }

    uStack_8 = 4;

  }

  return uStack_8;

}

/* ===== crt_frexp @ 0x0054771D ===== */
float10 crt_frexp(uint param_1,uint param_2,int *param_3)



{

  ushort uVar1;

  int iVar2;

  bool bVar3;

  int iVar4;

  float10 fVar5;

  double local_c;

  

  if ((double)CONCAT17(param_2._3_1_,CONCAT16(param_2._2_1_,CONCAT24((ushort)param_2,param_1))) ==

      0.0) {

    iVar4 = 0;

    local_c = 0.0;

  }

  else if (((param_2 & 0x7ff00000) == 0) && (((param_2 & 0xfffff) != 0 || (param_1 != 0)))) {

    iVar4 = -0x3fd;

    if (0.0 <= (double)CONCAT17(param_2._3_1_,

                                CONCAT16(param_2._2_1_,CONCAT24((ushort)param_2,param_1)))) {

      bVar3 = false;

    }

    else {

      bVar3 = true;

    }

    while ((param_2._2_1_ & 0x10) == 0) {

      iVar2 = CONCAT13(param_2._3_1_,CONCAT12(param_2._2_1_,(ushort)param_2)) << 1;

      param_2._0_2_ = (ushort)iVar2;

      param_2._2_1_ = (byte)((uint)iVar2 >> 0x10);

      param_2._3_1_ = (byte)((uint)iVar2 >> 0x18);

      if ((param_1 & 0x80000000) != 0) {

        param_2._0_2_ = (ushort)param_2 | 1;

      }

      param_1 = param_1 << 1;

      iVar4 = iVar4 + -1;

    }

    uVar1 = CONCAT11(param_2._3_1_,param_2._2_1_) & 0xffef;

    param_2._2_1_ = (byte)uVar1;

    param_2._3_1_ = (byte)(uVar1 >> 8);

    if (bVar3) {

      param_2._3_1_ = param_2._3_1_ | 0x80;

    }

    fVar5 = (float10)crt_ldexp10(CONCAT17(param_2._3_1_,

                                          CONCAT16(param_2._2_1_,CONCAT24((ushort)param_2,param_1)))

                                 ,0);

    local_c = (double)fVar5;

  }

  else {

    fVar5 = (float10)crt_ldexp10(CONCAT17(param_2._3_1_,

                                          CONCAT16(param_2._2_1_,CONCAT24((ushort)param_2,param_1)))

                                 ,0);

    local_c = (double)fVar5;

    iVar4 = (short)((ushort)(param_2 >> 0x14) & 0x7ff) + -0x3fe;

  }

  *param_3 = iVar4;

  return (float10)local_c;

}

/* ===== crt_fnstsw @ 0x005477DE ===== */
int crt_fnstsw(void)



{

  short in_FPUStatusWord;

  

  return (int)in_FPUStatusWord;

}

/* ===== crt_fnstsw2 @ 0x005477EC ===== */
int crt_fnstsw2(void)



{

  short in_FPUStatusWord;

  

  return (int)in_FPUStatusWord;

}

/* ===== crt_fnstcw @ 0x005477FB ===== */
int crt_fnstcw(void)



{

  short in_FPUControlWord;

  

  return (int)in_FPUControlWord;

}

/* ===== ANM_DumpCluster_6 @ 0x0054781E ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void ANM_DumpCluster_6(void)



{

  return;

}

/* ===== _close @ 0x00547874 ===== */
undefined4 _close(uint param_1)



{

  undefined4 uVar1;

  undefined4 *puVar2;

  

  if ((param_1 < DAT_006579c0) &&

     ((*(byte *)((&DAT_006578c0)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 1) != 0)) {

    crt_lock_fd(param_1);

    uVar1 = _close_lk(param_1);

    FUN_00545c58(param_1);

    return uVar1;

  }

  puVar2 = (undefined4 *)_errno();

  *puVar2 = 9;

  puVar2 = (undefined4 *)__doserrno();

  *puVar2 = 0;

  return 0xffffffff;

}

/* ===== _close_lk @ 0x005478D1 ===== */
undefined4 _close_lk(uint param_1)



{

  int iVar1;

  int iVar2;

  HANDLE hObject;

  BOOL BVar3;

  DWORD DVar4;

  undefined4 uVar5;

  

  iVar1 = crt_validate_osfhnd(param_1);

  if (iVar1 != -1) {

    if ((param_1 == 1) || (param_1 == 2)) {

      iVar1 = crt_validate_osfhnd(2);

      iVar2 = crt_validate_osfhnd(1);

      if (iVar2 == iVar1) goto LAB_0054791f;

    }

    hObject = (HANDLE)crt_validate_osfhnd(param_1);

    BVar3 = CloseHandle(hObject);

    if (BVar3 == 0) {

      DVar4 = GetLastError();

      goto LAB_00547921;

    }

  }

LAB_0054791f:

  DVar4 = 0;

LAB_00547921:

  crt_set_doserrno(param_1);

  *(undefined1 *)((&DAT_006578c0)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) = 0;

  if (DVar4 == 0) {

    uVar5 = 0;

  }

  else {

    _dosmaperr(DVar4);

    uVar5 = 0xffffffff;

  }

  return uVar5;

}

/* ===== __freebuf @ 0x00547954 ===== */
/* Library Function - Single Match

    __freebuf

   

   Library: Visual Studio 2003 Release */



void __cdecl __freebuf(FILE *_File)



{

  if (((_File->_flag & 0x83U) != 0) && ((_File->_flag & 8U) != 0)) {

    crt_free_ext(_File->_base);

    *(ushort *)&_File->_flag = (ushort)_File->_flag & 0xfbf7;

    _File->_ptr = (char *)0x0;

    _File->_base = (char *)0x0;

    _File->_cnt = 0;

  }

  return;

}

/* ===== _filbuf @ 0x0054797F ===== */
uint _filbuf(undefined4 *param_1)



{

  byte bVar1;

  uint uVar2;

  int iVar3;

  undefined *puVar4;

  

  uVar2 = param_1[3];

  if (((uVar2 & 0x83) != 0) && ((uVar2 & 0x40) == 0)) {

    if ((uVar2 & 2) == 0) {

      param_1[3] = uVar2 | 1;

      if ((uVar2 & 0x10c) == 0) {

        FUN_0054d689(param_1);

      }

      else {

        *param_1 = param_1[2];

      }

      iVar3 = _read(param_1[4],param_1[2],param_1[6]);

      param_1[1] = iVar3;

      if ((iVar3 != 0) && (iVar3 != -1)) {

        if ((param_1[3] & 0x82) == 0) {

          uVar2 = param_1[4];

          if (uVar2 == 0xffffffff) {

            puVar4 = &DAT_00583ac8;

          }

          else {

            puVar4 = (undefined *)((&DAT_006578c0)[(int)uVar2 >> 5] + (uVar2 & 0x1f) * 0x24);

          }

          if ((puVar4[4] & 0x82) == 0x82) {

            param_1[3] = param_1[3] | 0x2000;

          }

        }

        if (((param_1[6] == 0x200) && ((param_1[3] & 8) != 0)) && ((param_1[3] & 0x400) == 0)) {

          param_1[6] = 0x1000;

        }

        param_1[1] = iVar3 + -1;

        bVar1 = *(byte *)*param_1;

        *param_1 = (byte *)*param_1 + 1;

        return (uint)bVar1;

      }

      param_1[3] = param_1[3] | (-(uint)(iVar3 != 0) & 0x10) + 0x10;

      param_1[1] = 0;

    }

    else {

      param_1[3] = uVar2 | 0x20;

    }

  }

  return 0xffffffff;

}

/* ===== _read @ 0x00547A5B ===== */
undefined4 _read(uint param_1,undefined4 param_2,undefined4 param_3)



{

  undefined4 uVar1;

  undefined4 *puVar2;

  

  if ((param_1 < DAT_006579c0) &&

     ((*(byte *)((&DAT_006578c0)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 1) != 0)) {

    crt_lock_fd(param_1);

    uVar1 = _read_lk(param_1,param_2,param_3);

    FUN_00545c58(param_1);

    return uVar1;

  }

  puVar2 = (undefined4 *)_errno();

  *puVar2 = 9;

  puVar2 = (undefined4 *)__doserrno();

  *puVar2 = 0;

  return 0xffffffff;

}

/* ===== _read_lk @ 0x00547AC0 ===== */
int _read_lk(uint param_1,char *param_2,char *param_3)



{

  int *piVar1;

  byte *pbVar2;

  char cVar3;

  byte bVar4;

  BOOL BVar5;

  DWORD DVar6;

  undefined4 *puVar7;

  char *pcVar8;

  int iVar9;

  DWORD local_10;

  char *local_c;

  char local_5;

  

  local_c = (char *)0x0;

  if (param_3 != (char *)0x0) {

    piVar1 = &DAT_006578c0 + ((int)param_1 >> 5);

    iVar9 = (param_1 & 0x1f) * 0x24;

    bVar4 = *(byte *)((&DAT_006578c0)[(int)param_1 >> 5] + iVar9 + 4);

    if ((bVar4 & 2) == 0) {

      pcVar8 = param_2;

      if (((bVar4 & 0x48) != 0) &&

         (cVar3 = *(char *)((&DAT_006578c0)[(int)param_1 >> 5] + iVar9 + 5), cVar3 != '\n')) {

        param_3 = (char *)((int)param_3 - 1);

        *param_2 = cVar3;

        pcVar8 = param_2 + 1;

        local_c = (char *)0x1;

        *(undefined1 *)(*piVar1 + 5 + iVar9) = 10;

      }

      BVar5 = ReadFile(*(HANDLE *)(*piVar1 + iVar9),pcVar8,(DWORD)param_3,&local_10,

                       (LPOVERLAPPED)0x0);

      if (BVar5 == 0) {

        DVar6 = GetLastError();

        if (DVar6 == 5) {

          puVar7 = (undefined4 *)_errno();

          *puVar7 = 9;

          puVar7 = (undefined4 *)__doserrno();

          *puVar7 = 5;

        }

        else {

          if (DVar6 == 0x6d) {

            return 0;

          }

          _dosmaperr(DVar6);

        }

        return -1;

      }

      bVar4 = *(byte *)(*piVar1 + 4 + iVar9);

      if ((bVar4 & 0x80) == 0) {

        return (int)local_c + local_10;

      }

      if ((local_10 == 0) || (*param_2 != '\n')) {

        bVar4 = bVar4 & 0xfb;

      }

      else {

        bVar4 = bVar4 | 4;

      }

      *(byte *)(*piVar1 + 4 + iVar9) = bVar4;

      param_3 = param_2;

      local_c = param_2 + (int)local_c + local_10;

      pcVar8 = param_2;

      if (param_2 < local_c) {

        do {

          cVar3 = *param_3;

          if (cVar3 == '\x1a') {

            pbVar2 = (byte *)(*piVar1 + 4 + iVar9);

            bVar4 = *pbVar2;

            if ((bVar4 & 0x40) == 0) {

              *pbVar2 = bVar4 | 2;

            }

            break;

          }

          if (cVar3 == '\r') {

            if (param_3 < local_c + -1) {

              if (param_3[1] == '\n') {

                param_3 = param_3 + 2;

                goto LAB_00547c4b;

              }

              *pcVar8 = '\r';

              pcVar8 = pcVar8 + 1;

              param_3 = param_3 + 1;

            }

            else {

              param_3 = param_3 + 1;

              BVar5 = ReadFile(*(HANDLE *)(*piVar1 + iVar9),&local_5,1,&local_10,(LPOVERLAPPED)0x0);

              if (((BVar5 == 0) && (DVar6 = GetLastError(), DVar6 != 0)) || (local_10 == 0)) {

LAB_00547c65:

                *pcVar8 = '\r';

LAB_00547c68:

                pcVar8 = pcVar8 + 1;

              }

              else if ((*(byte *)(*piVar1 + 4 + iVar9) & 0x48) == 0) {

                if ((pcVar8 == param_2) && (local_5 == '\n')) {

LAB_00547c4b:

                  *pcVar8 = '\n';

                  goto LAB_00547c68;

                }

                _lseek(param_1,0xffffffff,1);

                if (local_5 != '\n') goto LAB_00547c65;

              }

              else {

                if (local_5 == '\n') goto LAB_00547c4b;

                *pcVar8 = '\r';

                pcVar8 = pcVar8 + 1;

                *(char *)(*piVar1 + 5 + iVar9) = local_5;

              }

            }

          }

          else {

            *pcVar8 = cVar3;

            pcVar8 = pcVar8 + 1;

            param_3 = param_3 + 1;

          }

        } while (param_3 < local_c);

      }

      return (int)pcVar8 - (int)param_2;

    }

  }

  return 0;

}

/* ===== memmove @ 0x00547CA0 ===== */
undefined4 * memmove(undefined4 *param_1,undefined4 *param_2,uint param_3)



{

  uint uVar1;

  undefined4 *puVar2;

  

  if ((param_2 < param_1) && (param_1 < (undefined4 *)(param_3 + (int)param_2))) {

    param_2 = (undefined4 *)((param_3 - 4) + (int)param_2);

    puVar2 = (undefined4 *)((param_3 - 4) + (int)param_1);

    if (((uint)puVar2 & 3) == 0) {

      uVar1 = param_3 >> 2;

      param_3 = param_3 & 3;

      if (7 < uVar1) {

        for (; uVar1 != 0; uVar1 = uVar1 - 1) {

          *puVar2 = *param_2;

          param_2 = param_2 + -1;

          puVar2 = puVar2 + -1;

        }

        switch(param_3) {

        case 0:

          return param_1;

        case 2:

          goto switchD_00547e57_caseD_2;

        case 3:

          goto switchD_00547e57_caseD_3;

        }

        goto switchD_00547e57_caseD_1;

      }

    }

    else {

      switch(param_3) {

      case 0:

        goto switchD_00547e57_caseD_0;

      case 1:

        goto switchD_00547e57_caseD_1;

      case 2:

        goto switchD_00547e57_caseD_2;

      case 3:

        goto switchD_00547e57_caseD_3;

      default:

        uVar1 = param_3 - ((uint)puVar2 & 3);

        switch((uint)puVar2 & 3) {

        case 1:

          param_3 = uVar1 & 3;

          *(undefined1 *)((int)puVar2 + 3) = *(undefined1 *)((int)param_2 + 3);

          param_2 = (undefined4 *)((int)param_2 + -1);

          uVar1 = uVar1 >> 2;

          puVar2 = (undefined4 *)((int)puVar2 - 1);

          if (7 < uVar1) {

            for (; uVar1 != 0; uVar1 = uVar1 - 1) {

              *puVar2 = *param_2;

              param_2 = param_2 + -1;

              puVar2 = puVar2 + -1;

            }

            switch(param_3) {

            case 0:

              return param_1;

            case 2:

              goto switchD_00547e57_caseD_2;

            case 3:

              goto switchD_00547e57_caseD_3;

            }

            goto switchD_00547e57_caseD_1;

          }

          break;

        case 2:

          param_3 = uVar1 & 3;

          *(undefined1 *)((int)puVar2 + 3) = *(undefined1 *)((int)param_2 + 3);

          uVar1 = uVar1 >> 2;

          *(undefined1 *)((int)puVar2 + 2) = *(undefined1 *)((int)param_2 + 2);

          param_2 = (undefined4 *)((int)param_2 + -2);

          puVar2 = (undefined4 *)((int)puVar2 - 2);

          if (7 < uVar1) {

            for (; uVar1 != 0; uVar1 = uVar1 - 1) {

              *puVar2 = *param_2;

              param_2 = param_2 + -1;

              puVar2 = puVar2 + -1;

            }

            switch(param_3) {

            case 0:

              return param_1;

            case 2:

              goto switchD_00547e57_caseD_2;

            case 3:

              goto switchD_00547e57_caseD_3;

            }

            goto switchD_00547e57_caseD_1;

          }

          break;

        case 3:

          param_3 = uVar1 & 3;

          *(undefined1 *)((int)puVar2 + 3) = *(undefined1 *)((int)param_2 + 3);

          *(undefined1 *)((int)puVar2 + 2) = *(undefined1 *)((int)param_2 + 2);

          uVar1 = uVar1 >> 2;

          *(undefined1 *)((int)puVar2 + 1) = *(undefined1 *)((int)param_2 + 1);

          param_2 = (undefined4 *)((int)param_2 + -3);

          puVar2 = (undefined4 *)((int)puVar2 - 3);

          if (7 < uVar1) {

            for (; uVar1 != 0; uVar1 = uVar1 - 1) {

              *puVar2 = *param_2;

              param_2 = param_2 + -1;

              puVar2 = puVar2 + -1;

            }

            switch(param_3) {

            case 0:

              return param_1;

            case 2:

              goto switchD_00547e57_caseD_2;

            case 3:

              goto switchD_00547e57_caseD_3;

            }

            goto switchD_00547e57_caseD_1;

          }

        }

      }

    }

    switch(uVar1) {

    case 7:

      puVar2[7 - uVar1] = param_2[7 - uVar1];

    case 6:

      puVar2[6 - uVar1] = param_2[6 - uVar1];

    case 5:

      puVar2[5 - uVar1] = param_2[5 - uVar1];

    case 4:

      puVar2[4 - uVar1] = param_2[4 - uVar1];

    case 3:

      puVar2[3 - uVar1] = param_2[3 - uVar1];

    case 2:

      puVar2[2 - uVar1] = param_2[2 - uVar1];

    case 1:

      puVar2[1 - uVar1] = param_2[1 - uVar1];

      param_2 = param_2 + -uVar1;

      puVar2 = puVar2 + -uVar1;

    }

    switch(param_3) {

    case 1:

switchD_00547e57_caseD_1:

      *(undefined1 *)((int)puVar2 + 3) = *(undefined1 *)((int)param_2 + 3);

      return param_1;

    case 2:

switchD_00547e57_caseD_2:

      *(undefined1 *)((int)puVar2 + 3) = *(undefined1 *)((int)param_2 + 3);

      *(undefined1 *)((int)puVar2 + 2) = *(undefined1 *)((int)param_2 + 2);

      return param_1;

    case 3:

switchD_00547e57_caseD_3:

      *(undefined1 *)((int)puVar2 + 3) = *(undefined1 *)((int)param_2 + 3);

      *(undefined1 *)((int)puVar2 + 2) = *(undefined1 *)((int)param_2 + 2);

      *(undefined1 *)((int)puVar2 + 1) = *(undefined1 *)((int)param_2 + 1);

      return param_1;

    }

switchD_00547e57_caseD_0:

    return param_1;

  }

  puVar2 = param_1;

  if (((uint)param_1 & 3) == 0) {

    uVar1 = param_3 >> 2;

    param_3 = param_3 & 3;

    if (7 < uVar1) {

      for (; uVar1 != 0; uVar1 = uVar1 - 1) {

        *puVar2 = *param_2;

        param_2 = param_2 + 1;

        puVar2 = puVar2 + 1;

      }

      switch(param_3) {

      case 0:

        return param_1;

      case 2:

        goto switchD_00547cd5_caseD_2;

      case 3:

        goto switchD_00547cd5_caseD_3;

      }

      goto switchD_00547cd5_caseD_1;

    }

  }

  else {

    switch(param_3) {

    case 0:

      goto switchD_00547cd5_caseD_0;

    case 1:

      goto switchD_00547cd5_caseD_1;

    case 2:

      goto switchD_00547cd5_caseD_2;

    case 3:

      goto switchD_00547cd5_caseD_3;

    default:

      uVar1 = (param_3 - 4) + ((uint)param_1 & 3);

      switch((uint)param_1 & 3) {

      case 1:

        param_3 = uVar1 & 3;

        *(undefined1 *)param_1 = *(undefined1 *)param_2;

        *(undefined1 *)((int)param_1 + 1) = *(undefined1 *)((int)param_2 + 1);

        uVar1 = uVar1 >> 2;

        *(undefined1 *)((int)param_1 + 2) = *(undefined1 *)((int)param_2 + 2);

        param_2 = (undefined4 *)((int)param_2 + 3);

        puVar2 = (undefined4 *)((int)param_1 + 3);

        if (7 < uVar1) {

          for (; uVar1 != 0; uVar1 = uVar1 - 1) {

            *puVar2 = *param_2;

            param_2 = param_2 + 1;

            puVar2 = puVar2 + 1;

          }

          switch(param_3) {

          case 0:

            return param_1;

          case 2:

            goto switchD_00547cd5_caseD_2;

          case 3:

            goto switchD_00547cd5_caseD_3;

          }

          goto switchD_00547cd5_caseD_1;

        }

        break;

      case 2:

        param_3 = uVar1 & 3;

        *(undefined1 *)param_1 = *(undefined1 *)param_2;

        uVar1 = uVar1 >> 2;

        *(undefined1 *)((int)param_1 + 1) = *(undefined1 *)((int)param_2 + 1);

        param_2 = (undefined4 *)((int)param_2 + 2);

        puVar2 = (undefined4 *)((int)param_1 + 2);

        if (7 < uVar1) {

          for (; uVar1 != 0; uVar1 = uVar1 - 1) {

            *puVar2 = *param_2;

            param_2 = param_2 + 1;

            puVar2 = puVar2 + 1;

          }

          switch(param_3) {

          case 0:

            return param_1;

          case 2:

            goto switchD_00547cd5_caseD_2;

          case 3:

            goto switchD_00547cd5_caseD_3;

          }

          goto switchD_00547cd5_caseD_1;

        }

        break;

      case 3:

        param_3 = uVar1 & 3;

        *(undefined1 *)param_1 = *(undefined1 *)param_2;

        param_2 = (undefined4 *)((int)param_2 + 1);

        uVar1 = uVar1 >> 2;

        puVar2 = (undefined4 *)((int)param_1 + 1);

        if (7 < uVar1) {

          for (; uVar1 != 0; uVar1 = uVar1 - 1) {

            *puVar2 = *param_2;

            param_2 = param_2 + 1;

            puVar2 = puVar2 + 1;

          }

          switch(param_3) {

          case 0:

            return param_1;

          case 2:

            goto switchD_00547cd5_caseD_2;

          case 3:

            goto switchD_00547cd5_caseD_3;

          }

          goto switchD_00547cd5_caseD_1;

        }

      }

    }

  }

  switch(uVar1) {

  case 7:

    puVar2[uVar1 - 7] = param_2[uVar1 - 7];

  case 6:

    puVar2[uVar1 - 6] = param_2[uVar1 - 6];

  case 5:

    puVar2[uVar1 - 5] = param_2[uVar1 - 5];

  case 4:

    puVar2[uVar1 - 4] = param_2[uVar1 - 4];

  case 3:

    puVar2[uVar1 - 3] = param_2[uVar1 - 3];

  case 2:

    puVar2[uVar1 - 2] = param_2[uVar1 - 2];

  case 1:

    puVar2[uVar1 - 1] = param_2[uVar1 - 1];

    param_2 = param_2 + uVar1;

    puVar2 = puVar2 + uVar1;

  }

  switch(param_3) {

  case 1:

switchD_00547cd5_caseD_1:

    *(undefined1 *)puVar2 = *(undefined1 *)param_2;

    return param_1;

  case 2:

switchD_00547cd5_caseD_2:

    *(undefined1 *)puVar2 = *(undefined1 *)param_2;

    *(undefined1 *)((int)puVar2 + 1) = *(undefined1 *)((int)param_2 + 1);

    return param_1;

  case 3:

switchD_00547cd5_caseD_3:

    *(undefined1 *)puVar2 = *(undefined1 *)param_2;

    *(undefined1 *)((int)puVar2 + 1) = *(undefined1 *)((int)param_2 + 1);

    *(undefined1 *)((int)puVar2 + 2) = *(undefined1 *)((int)param_2 + 2);

    return param_1;

  }

switchD_00547cd5_caseD_0:

  return param_1;

}

/* ===== _sopen @ 0x00547FD5 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined4 * _sopen(undefined4 param_1,char *param_2,undefined4 param_3,undefined4 *param_4)



{

  char cVar1;

  bool bVar2;

  bool bVar3;

  bool bVar4;

  int iVar5;

  uint uVar6;

  uint uVar7;

  

  bVar4 = false;

  bVar3 = false;

  cVar1 = *param_2;

  if (cVar1 == 'a') {

    uVar6 = 0x109;

  }

  else {

    if (cVar1 == 'r') {

      uVar6 = 0;

      uVar7 = DAT_00630d84 | 1;

      goto LAB_00548016;

    }

    if (cVar1 != 'w') {

      return (undefined4 *)0x0;

    }

    uVar6 = 0x301;

  }

  uVar7 = DAT_00630d84 | 2;

LAB_00548016:

  bVar2 = true;

LAB_00548019:

  cVar1 = param_2[1];

  param_2 = param_2 + 1;

  if ((cVar1 == '\0') || (!bVar2)) {

    iVar5 = crt_openfile(param_1,uVar6,param_3,0x1a4);

    if (iVar5 < 0) {

      return (undefined4 *)0x0;

    }

    _DAT_00630ba0 = _DAT_00630ba0 + 1;

    param_4[3] = uVar7;

    param_4[1] = 0;

    *param_4 = 0;

    param_4[2] = 0;

    param_4[7] = 0;

    param_4[4] = iVar5;

    return param_4;

  }

  if (cVar1 < 'U') {

    if (cVar1 == 'T') {

      if ((uVar6 & 0x1000) == 0) {

        uVar6 = uVar6 | 0x1000;

        goto LAB_00548019;

      }

    }

    else if (cVar1 == '+') {

      if ((uVar6 & 2) == 0) {

        uVar6 = uVar6 & 0xfffffffe | 2;

        uVar7 = uVar7 & 0xfffffffc | 0x80;

        goto LAB_00548019;

      }

    }

    else if (cVar1 == 'D') {

      if ((uVar6 & 0x40) == 0) {

        uVar6 = uVar6 | 0x40;

        goto LAB_00548019;

      }

    }

    else if (cVar1 == 'R') {

      if (!bVar3) {

        bVar3 = true;

        uVar6 = uVar6 | 0x10;

        goto LAB_00548019;

      }

    }

    else if ((cVar1 == 'S') && (!bVar3)) {

      bVar3 = true;

      uVar6 = uVar6 | 0x20;

      goto LAB_00548019;

    }

  }

  else {

    if (cVar1 == 'b') {

      if ((uVar6 & 0xc000) != 0) goto LAB_005480f9;

      uVar6 = uVar6 | 0x8000;

      goto LAB_00548019;

    }

    if (cVar1 == 'c') {

      if (!bVar4) {

        bVar4 = true;

        uVar7 = uVar7 | 0x4000;

        goto LAB_00548019;

      }

    }

    else {

      if (cVar1 != 'n') {

        if ((cVar1 != 't') || ((uVar6 & 0xc000) != 0)) goto LAB_005480f9;

        uVar6 = uVar6 | 0x4000;

        goto LAB_00548019;

      }

      if (!bVar4) {

        bVar4 = true;

        uVar7 = uVar7 & 0xffffbfff;

        goto LAB_00548019;

      }

    }

  }

LAB_005480f9:

  bVar2 = false;

  goto LAB_00548019;

}

/* ===== crt_allocosfhnd @ 0x00548145 ===== */
undefined4 * crt_allocosfhnd(void)



{

  int iVar1;

  void *pvVar2;

  int iVar3;

  undefined4 *puVar4;

  

  puVar4 = (undefined4 *)0x0;

  _lock(2);

  iVar3 = 0;

  if (0 < DAT_00658a00) {

    do {

      iVar1 = *(int *)(DAT_006579f4 + iVar3 * 4);

      if (iVar1 == 0) {

        iVar3 = iVar3 * 4;

        pvVar2 = _malloc(0x38);

        *(void **)(iVar3 + DAT_006579f4) = pvVar2;

        if (*(int *)(iVar3 + DAT_006579f4) != 0) {

          InitializeCriticalSection((LPCRITICAL_SECTION)(*(int *)(iVar3 + DAT_006579f4) + 0x20));

          EnterCriticalSection((LPCRITICAL_SECTION)(*(int *)(iVar3 + DAT_006579f4) + 0x20));

          puVar4 = *(undefined4 **)(iVar3 + DAT_006579f4);

LAB_005481e9:

          if (puVar4 != (undefined4 *)0x0) {

            puVar4[4] = 0xffffffff;

            puVar4[1] = 0;

            puVar4[3] = 0;

            puVar4[2] = 0;

            *puVar4 = 0;

            puVar4[7] = 0;

          }

        }

        break;

      }

      if ((*(byte *)(iVar1 + 0xc) & 0x83) == 0) {

        crt_file_lock_2(iVar3,iVar1);

        iVar1 = *(int *)(DAT_006579f4 + iVar3 * 4);

        if ((*(byte *)(iVar1 + 0xc) & 0x83) == 0) {

          puVar4 = *(undefined4 **)(DAT_006579f4 + iVar3 * 4);

          goto LAB_005481e9;

        }

        crt_file_unlock_2(iVar3,iVar1);

      }

      iVar3 = iVar3 + 1;

    } while (iVar3 < DAT_00658a00);

  }

  _unlock(2);

  return puVar4;

}

/* ===== _write @ 0x0054820D ===== */
undefined4 _write(uint param_1,undefined4 param_2,undefined4 param_3)



{

  undefined4 uVar1;

  undefined4 *puVar2;

  

  if ((param_1 < DAT_006579c0) &&

     ((*(byte *)((&DAT_006578c0)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 1) != 0)) {

    crt_lock_fd(param_1);

    uVar1 = _write_lk(param_1,param_2,param_3);

    FUN_00545c58(param_1);

    return uVar1;

  }

  puVar2 = (undefined4 *)_errno();

  *puVar2 = 9;

  puVar2 = (undefined4 *)__doserrno();

  *puVar2 = 0;

  return 0xffffffff;

}

/* ===== _write_lk @ 0x00548272 ===== */
int _write_lk(DWORD param_1,char *param_2,uint param_3)



{

  int *piVar1;

  char *pcVar2;

  char cVar3;

  int iVar4;

  char *pcVar5;

  BOOL BVar6;

  undefined4 *puVar7;

  char local_418 [1028];

  int local_14;

  DWORD local_10;

  DWORD local_c;

  char *local_8;

  

  local_c = 0;

  local_14 = 0;

  if (param_3 == 0) {

LAB_0054828b:

    iVar4 = 0;

  }

  else {

    piVar1 = &DAT_006578c0 + ((int)param_1 >> 5);

    iVar4 = (param_1 & 0x1f) * 0x24;

    if ((*(byte *)(*piVar1 + 4 + iVar4) & 0x20) != 0) {

      _lseek(param_1,0,2);

    }

    if ((*(byte *)((undefined4 *)(*piVar1 + iVar4) + 1) & 0x80) == 0) {

      BVar6 = WriteFile(*(HANDLE *)(*piVar1 + iVar4),param_2,param_3,&local_10,(LPOVERLAPPED)0x0);

      if (BVar6 == 0) {

        param_1 = GetLastError();

      }

      else {

        local_c = local_10;

        param_1 = 0;

      }

LAB_0054835a:

      if (local_c != 0) {

        return local_c - local_14;

      }

      if (param_1 == 0) goto LAB_005483cc;

      if (param_1 == 5) {

        puVar7 = (undefined4 *)_errno();

        *puVar7 = 9;

        puVar7 = (undefined4 *)__doserrno();

        *puVar7 = 5;

      }

      else {

        _dosmaperr(param_1);

      }

    }

    else {

      local_8 = param_2;

      param_1 = 0;

      if (param_3 != 0) {

        do {

          pcVar5 = local_418;

          do {

            if (param_3 <= (uint)((int)local_8 - (int)param_2)) break;

            pcVar2 = local_8 + 1;

            cVar3 = *local_8;

            local_8 = pcVar2;

            if (cVar3 == '\n') {

              local_14 = local_14 + 1;

              *pcVar5 = '\r';

              pcVar5 = pcVar5 + 1;

            }

            *pcVar5 = cVar3;

            pcVar5 = pcVar5 + 1;

          } while ((int)pcVar5 - (int)local_418 < 0x400);

          BVar6 = WriteFile(*(HANDLE *)(*piVar1 + iVar4),local_418,(int)pcVar5 - (int)local_418,

                            &local_10,(LPOVERLAPPED)0x0);

          if (BVar6 == 0) {

            param_1 = GetLastError();

            goto LAB_0054835a;

          }

          local_c = local_c + local_10;

          if (((int)local_10 < (int)pcVar5 - (int)local_418) ||

             (param_3 <= (uint)((int)local_8 - (int)param_2))) goto LAB_0054835a;

        } while( true );

      }

LAB_005483cc:

      if (((*(byte *)(*piVar1 + 4 + iVar4) & 0x40) != 0) && (*param_2 == '\x1a')) goto LAB_0054828b;

      puVar7 = (undefined4 *)_errno();

      *puVar7 = 0x1c;

      puVar7 = (undefined4 *)__doserrno();

      *puVar7 = 0;

    }

    iVar4 = -1;

  }

  return iVar4;

}

/* ===== crt_initio @ 0x005483FD ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined4 crt_initio(undefined4 *param_1)



{

  undefined4 uVar1;

  int iVar2;

  void *pvVar3;

  

  iVar2 = FUN_0054d6cd(param_1[4]);

  if (iVar2 == 0) {

    return 0;

  }

  if (param_1 == (undefined4 *)&DAT_00581120) {

    iVar2 = 0;

  }

  else {

    if (param_1 != (undefined4 *)&DAT_00581140) {

      return 0;

    }

    iVar2 = 1;

  }

  _DAT_00630ba0 = _DAT_00630ba0 + 1;

  if ((*(ushort *)(param_1 + 3) & 0x10c) != 0) {

    return 0;

  }

  if ((&DAT_00630bd0)[iVar2] == 0) {

    pvVar3 = _malloc(0x1000);

    (&DAT_00630bd0)[iVar2] = pvVar3;

    if (pvVar3 == (void *)0x0) {

      param_1[2] = param_1 + 5;

      *param_1 = param_1 + 5;

      param_1[6] = 2;

      param_1[1] = 2;

      goto LAB_00548479;

    }

  }

  uVar1 = (&DAT_00630bd0)[iVar2];

  param_1[6] = 0x1000;

  param_1[2] = uVar1;

  *param_1 = uVar1;

  param_1[1] = 0x1000;

LAB_00548479:

  *(ushort *)(param_1 + 3) = *(ushort *)(param_1 + 3) | 0x1102;

  return 1;

}

/* ===== _freebuf @ 0x0054848A ===== */
void _freebuf(int param_1,undefined4 *param_2)



{

  if ((param_1 != 0) && ((*(byte *)((int)param_2 + 0xd) & 0x10) != 0)) {

    _flush(param_2);

    *(byte *)((int)param_2 + 0xd) = *(byte *)((int)param_2 + 0xd) & 0xee;

    param_2[6] = 0;

    *param_2 = 0;

    param_2[2] = 0;

  }

  return;

}

/* ===== _dosmaperr @ 0x005484B4 ===== */
void _dosmaperr(uint param_1)



{

  uint *puVar1;

  undefined4 *puVar2;

  int iVar3;

  

  puVar1 = (uint *)__doserrno();

  iVar3 = 0;

  *puVar1 = param_1;

  puVar1 = &DAT_005814d0;

  do {

    if (param_1 == *puVar1) {

      puVar2 = (undefined4 *)_errno();

      *puVar2 = *(undefined4 *)(iVar3 * 8 + 0x5814d4);

      return;

    }

    puVar1 = puVar1 + 2;

    iVar3 = iVar3 + 1;

  } while (puVar1 < &DAT_00581638);

  if ((0x12 < param_1) && (param_1 < 0x25)) {

    puVar2 = (undefined4 *)_errno();

    *puVar2 = 0xd;

    return;

  }

  if ((0xbb < param_1) && (param_1 < 0xcb)) {

    puVar2 = (undefined4 *)_errno();

    *puVar2 = 8;

    return;

  }

  puVar2 = (undefined4 *)_errno();

  *puVar2 = 0x16;

  return;

}

/* ===== _errno @ 0x00548527 ===== */
int _errno(void)



{

  int iVar1;

  

  iVar1 = __getptd();

  return iVar1 + 8;

}

/* ===== __doserrno @ 0x00548530 ===== */
int __doserrno(void)



{

  int iVar1;

  

  iVar1 = __getptd();

  return iVar1 + 0xc;

}

/* ===== crt_tls_init @ 0x00548539 ===== */
undefined4 crt_tls_init(void)



{

  DWORD *p0;

  BOOL BVar1;

  DWORD DVar2;

  

  crt_critical_sections_init();

  DAT_00581638 = TlsAlloc();

  if (DAT_00581638 != 0xffffffff) {

    p0 = (DWORD *)_malloc(1,0x74);

    if (p0 != (DWORD *)0x0) {

      BVar1 = TlsSetValue(DAT_00581638,p0);

      if (BVar1 != 0) {

        voBufReset__FP5VoBuf_2(p0);

        DVar2 = GetCurrentThreadId();

        p0[1] = 0xffffffff;

        *p0 = DVar2;

        return 1;

      }

    }

  }

  return 0;

}

/* ===== voBufReset__FP5VoBuf_2 @ 0x0054858D ===== */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */



void voBufReset__FP5VoBuf_2(undefined4 *p0)



{

  p0[0x14] = &DAT_00583a40;

  p0[5] = 1;

  return;

}

/* ===== __getptd @ 0x005485A0 ===== */
DWORD * __getptd(void)



{

  DWORD dwErrCode;

  DWORD *p0;

  BOOL BVar1;

  DWORD DVar2;

  

  dwErrCode = GetLastError();

  p0 = TlsGetValue(DAT_00581638);

  if (p0 == (DWORD *)0x0) {

    p0 = (DWORD *)_malloc(1,0x74);

    if (p0 != (DWORD *)0x0) {

      BVar1 = TlsSetValue(DAT_00581638,p0);

      if (BVar1 != 0) {

        voBufReset__FP5VoBuf_2(p0);

        DVar2 = GetCurrentThreadId();

        p0[1] = 0xffffffff;

        *p0 = DVar2;

        goto LAB_005485fb;

      }

    }

    __amsg_exit(0x10);

  }

LAB_005485fb:

  SetLastError(dwErrCode);

  return p0;

}

/* ===== __freeptd @ 0x00548607 ===== */
void __freeptd(LPVOID param_1)



{

  if (DAT_00581638 != 0xffffffff) {

    if ((param_1 != (LPVOID)0x0) || (param_1 = TlsGetValue(DAT_00581638), param_1 != (LPVOID)0x0)) {

      if (*(int *)((int)param_1 + 0x24) != 0) {

        crt_free_ext(*(int *)((int)param_1 + 0x24));

      }

      if (*(int *)((int)param_1 + 0x28) != 0) {

        crt_free_ext(*(int *)((int)param_1 + 0x28));

      }

      if (*(int *)((int)param_1 + 0x30) != 0) {

        crt_free_ext(*(int *)((int)param_1 + 0x30));

      }

      if (*(int *)((int)param_1 + 0x38) != 0) {

        crt_free_ext(*(int *)((int)param_1 + 0x38));

      }

      if (*(int *)((int)param_1 + 0x40) != 0) {

        crt_free_ext(*(int *)((int)param_1 + 0x40));

      }

      if (*(int *)((int)param_1 + 0x44) != 0) {

        crt_free_ext(*(int *)((int)param_1 + 0x44));

      }

      if (*(undefined **)((int)param_1 + 0x50) != &DAT_00583a40) {

        crt_free_ext(*(undefined **)((int)param_1 + 0x50));

      }

      crt_free_ext(param_1);

    }

    TlsSetValue(DAT_00581638,(LPVOID)0x0);

    return;

  }

  return;

}

/* ===== AudioMusicStreamPlay__Fiiii_3 @ 0x005486B0 ===== */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

/* Library Function - Single Match

    __cintrindisp2

   

   Library: Visual Studio */



void AudioMusicStreamPlay__Fiiii_3(int p0,int p1,int p2,int p3)



{

  __trandisp2();

  crt_fpe_handler2();

  return;

}

/* ===== AudioMusicStreamPlay__Fiiii_2 @ 0x005486EE ===== */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

/* Library Function - Single Match

    __cintrindisp1

   

   Library: Visual Studio */



void AudioMusicStreamPlay__Fiiii_2(int p0,int p1,int p2,int p3)



{

  __trandisp1();

  crt_fpe_handler2();

  return;

}

/* ===== __ctrandisp2 @ 0x0054872B ===== */
/* Library Function - Single Match

    __ctrandisp2

   

   Libraries: Visual Studio 1998, Visual Studio 2003, Visual Studio 2005, Visual Studio 2008 */



void __ctrandisp2(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)



{

  __fload(param_1,param_2);

  __fload(param_3,param_4);

  __trandisp2();

  crt_fpe_handler();

  return;

}

/* ===== crt_fpe_handler @ 0x00548773 ===== */
void crt_fpe_handler(void)



{

  char cVar1;

  ushort uVar2;

  int unaff_EBP;

  ushort in_FPUStatusWord;

  float10 in_ST0;

  

  *(byte *)(unaff_EBP + -0x2c8) = *(byte *)(unaff_EBP + -0x2c8) & 0xfe;

  if (DAT_00630b54 != 0) {

    return;

  }

  *(double *)(unaff_EBP + -0x2d0) = (double)in_ST0;

  cVar1 = *(char *)(unaff_EBP + -0x90);

  if (cVar1 != '\0') {

    if ((cVar1 != -1) && (cVar1 != -2)) {

      if (cVar1 == '\0') {

        return;

      }

      *(int *)(unaff_EBP + -0x8e) = (int)cVar1;

      goto LAB_00548849;

    }

    uVar2 = *(ushort *)(unaff_EBP + -0x2ca) & 0x7ff0;

    if (uVar2 == 0) {

      *(undefined4 *)(unaff_EBP + -0x8e) = 4;

      in_ST0 = (float10)fscale(in_ST0,(float10)1536.0);

      if (ABS(in_ST0) < (float10)2.2250738585072014e-308) {

        in_ST0 = in_ST0 * (float10)0.0;

      }

      goto LAB_00548849;

    }

    if (uVar2 == 0x7ff0) {

      *(undefined4 *)(unaff_EBP + -0x8e) = 3;

      in_ST0 = (float10)fscale(in_ST0,(float10)-1536.0);

      if ((float10)1.7976931348623157e+308 < ABS(in_ST0)) {

        in_ST0 = in_ST0 * (float10)INFINITY;

      }

      goto LAB_00548849;

    }

  }

  if ((*(ushort *)(unaff_EBP + -0xa4) & 0x20) != 0) {

    return;

  }

  if ((in_FPUStatusWord & 0x20) == 0) {

    return;

  }

  *(undefined4 *)(unaff_EBP + -0x8e) = 8;

LAB_00548849:

  *(int *)(unaff_EBP + -0x8a) = *(int *)(unaff_EBP + -0x94) + 1;

  if ((*(byte *)(unaff_EBP + -0x2c8) & 1) == 0) {

    *(undefined4 *)(unaff_EBP + -0x86) = *(undefined4 *)(unaff_EBP + 8);

    *(undefined4 *)(unaff_EBP + -0x82) = *(undefined4 *)(unaff_EBP + 0xc);

    if (*(char *)(*(int *)(unaff_EBP + -0x94) + 0xd) != '\x01') {

      *(undefined4 *)(unaff_EBP + -0x7e) = *(undefined4 *)(unaff_EBP + 0x10);

      *(undefined4 *)(unaff_EBP + -0x7a) = *(undefined4 *)(unaff_EBP + 0x14);

    }

  }

  *(double *)(unaff_EBP + -0x76) = (double)in_ST0;

  crt_fpe_signal((int)*(char *)(*(int *)(unaff_EBP + -0x94) + 0xe),unaff_EBP + -0x8e,

                 unaff_EBP + -0xa4);

  return;

}

/* ===== crt_fpe_handler2 @ 0x0054877A ===== */
void crt_fpe_handler2(void)



{

  char cVar1;

  ushort uVar2;

  int unaff_EBP;

  ushort in_FPUStatusWord;

  float10 in_ST0;

  

  if (DAT_00630b54 != 0) {

    return;

  }

  *(double *)(unaff_EBP + -0x2d0) = (double)in_ST0;

  cVar1 = *(char *)(unaff_EBP + -0x90);

  if (cVar1 != '\0') {

    if ((cVar1 != -1) && (cVar1 != -2)) {

      if (cVar1 == '\0') {

        return;

      }

      *(int *)(unaff_EBP + -0x8e) = (int)cVar1;

      goto LAB_00548849;

    }

    uVar2 = *(ushort *)(unaff_EBP + -0x2ca) & 0x7ff0;

    if (uVar2 == 0) {

      *(undefined4 *)(unaff_EBP + -0x8e) = 4;

      in_ST0 = (float10)fscale(in_ST0,(float10)1536.0);

      if (ABS(in_ST0) < (float10)2.2250738585072014e-308) {

        in_ST0 = in_ST0 * (float10)0.0;

      }

      goto LAB_00548849;

    }

    if (uVar2 == 0x7ff0) {

      *(undefined4 *)(unaff_EBP + -0x8e) = 3;

      in_ST0 = (float10)fscale(in_ST0,(float10)-1536.0);

      if ((float10)1.7976931348623157e+308 < ABS(in_ST0)) {

        in_ST0 = in_ST0 * (float10)INFINITY;

      }

      goto LAB_00548849;

    }

  }

  if ((*(ushort *)(unaff_EBP + -0xa4) & 0x20) != 0) {

    return;

  }

  if ((in_FPUStatusWord & 0x20) == 0) {

    return;

  }

  *(undefined4 *)(unaff_EBP + -0x8e) = 8;

LAB_00548849:

  *(int *)(unaff_EBP + -0x8a) = *(int *)(unaff_EBP + -0x94) + 1;

  if ((*(byte *)(unaff_EBP + -0x2c8) & 1) == 0) {

    *(undefined4 *)(unaff_EBP + -0x86) = *(undefined4 *)(unaff_EBP + 8);

    *(undefined4 *)(unaff_EBP + -0x82) = *(undefined4 *)(unaff_EBP + 0xc);

    if (*(char *)(*(int *)(unaff_EBP + -0x94) + 0xd) != '\x01') {

      *(undefined4 *)(unaff_EBP + -0x7e) = *(undefined4 *)(unaff_EBP + 0x10);

      *(undefined4 *)(unaff_EBP + -0x7a) = *(undefined4 *)(unaff_EBP + 0x14);

    }

  }

  *(double *)(unaff_EBP + -0x76) = (double)in_ST0;

  crt_fpe_signal((int)*(char *)(*(int *)(unaff_EBP + -0x94) + 0xe),unaff_EBP + -0x8e,

                 unaff_EBP + -0xa4);

  return;

}

/* ===== __ctrandisp1 @ 0x005488AB ===== */
/* Library Function - Single Match

    __ctrandisp1

   

   Library: Visual Studio */



void __ctrandisp1(undefined4 param_1,undefined4 param_2)



{

  __fload(param_1,param_2);

  __trandisp1();

  crt_fpe_handler();

  return;

}

/* ===== __fload @ 0x005488DE ===== */
/* Library Function - Single Match

    __fload

   

   Libraries: Visual Studio 1998, Visual Studio 2003, Visual Studio 2005, Visual Studio 2008 */



float10 __fload(uint param_1,int param_2)



{

  float10 fVar1;

  

  if ((param_2._2_2_ & 0x7ff0) == 0x7ff0) {

    fVar1 = (float10)CONCAT28(param_2._2_2_ | 0x7fff,

                              CONCAT44(param_2 << 0xb | param_1 >> 0x15,param_1));

  }

  else {

    fVar1 = (float10)(double)CONCAT26(param_2._2_2_,CONCAT24((undefined2)param_2,param_1));

  }

  return fVar1;

}

/* ===== __trandisp1 @ 0x00548920 ===== */
/* Library Function - Single Match

    __trandisp1

   

   Library: Visual Studio */



void __trandisp1(void)



{

  float10 fVar1;

  byte bVar2;

  int in_EDX;

  undefined2 uVar3;

  int unaff_EBP;

  float10 in_ST0;

  

  if (*(char *)(in_EDX + 0xe) == '\x05') {

    uVar3 = (undefined2)

            CONCAT31((uint3)((byte)((ushort)*(undefined2 *)(unaff_EBP + -0xa4) >> 8) & 0xfe | 2),

                     0x3f);

  }

  else {

    uVar3 = 0x133f;

  }

  *(undefined2 *)(unaff_EBP + -0xa2) = uVar3;

  fVar1 = (float10)0;

  *(int *)(unaff_EBP + -0x94) = in_EDX;

  *(ushort *)(unaff_EBP + -0xa0) =

       (ushort)NAN(in_ST0) << 8 | (ushort)(in_ST0 < fVar1) << 9 | (ushort)(in_ST0 != fVar1) << 10 |

       (ushort)(in_ST0 == fVar1) << 0xe;

  *(undefined1 *)(unaff_EBP + -0x90) = 0;

  bVar2 = (char)(*(char *)(unaff_EBP + -0x9f) << 1) >> 1;

                    /* WARNING: Could not recover jumptable at 0x00548985. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  (**(code **)(in_EDX + (char)(&DAT_0058165c)[(byte)((bVar2 & 7) << 1 | (char)bVar2 < '\0')] + 0x10)

  )();

  return;

}

/* ===== __trandisp2 @ 0x00548987 ===== */
/* Library Function - Single Match

    __trandisp2

   

   Libraries: Visual Studio 1998, Visual Studio 2003, Visual Studio 2005, Visual Studio 2008 */



void __trandisp2(void)



{

  float10 fVar1;

  char cVar2;

  byte bVar3;

  int in_EDX;

  undefined2 uVar4;

  int unaff_EBP;

  float10 in_ST0;

  float10 in_ST1;

  

  if (*(char *)(in_EDX + 0xe) == '\x05') {

    uVar4 = (undefined2)

            CONCAT31((uint3)((byte)((ushort)*(undefined2 *)(unaff_EBP + -0xa4) >> 8) & 0xfe | 2),

                     0x3f);

  }

  else {

    uVar4 = 0x133f;

  }

  *(undefined2 *)(unaff_EBP + -0xa2) = uVar4;

  fVar1 = (float10)0;

  *(int *)(unaff_EBP + -0x94) = in_EDX;

  *(ushort *)(unaff_EBP + -0xa0) =

       (ushort)NAN(in_ST0) << 8 | (ushort)(in_ST0 < fVar1) << 9 | (ushort)(in_ST0 != fVar1) << 10 |

       (ushort)(in_ST0 == fVar1) << 0xe;

  *(undefined1 *)(unaff_EBP + -0x90) = 0;

  fVar1 = (float10)0;

  *(ushort *)(unaff_EBP + -0xa0) =

       (ushort)NAN(in_ST1) << 8 | (ushort)(in_ST1 < fVar1) << 9 | (ushort)(in_ST1 != fVar1) << 10 |

       (ushort)(in_ST1 == fVar1) << 0xe;

  bVar3 = (char)(*(char *)(unaff_EBP + -0x9f) << 1) >> 1;

  cVar2 = (char)(*(char *)(unaff_EBP + -0x9f) << 1) >> 1;

                    /* WARNING: Could not recover jumptable at 0x00548a11. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  (**(code **)(in_EDX + (char)((&DAT_0058165c)[(byte)(cVar2 << 1 | cVar2 < '\0') & 0xf] |

                              (&DAT_0058165c)[(byte)((bVar3 & 7) << 1 | (char)bVar3 < '\0')] << 2) +

              0x10))();

  return;

}

/* ===== crt_fmod10 @ 0x005492F6 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined4 crt_fmod10(undefined4 param_1,uint param_2,ushort param_3)



{

  undefined4 in_EAX;

  int iVar1;

  float10 fVar2;

  float10 fVar3;

  undefined4 in_stack_0000001c;

  undefined2 uStack00000020;

  undefined2 uStack00000022;

  ushort in_stack_00000024;

  

  if ((((((CONCAT22(param_3,param_2._2_2_) ^ 0x700) & 0x700) == 0) &&

       ((&DAT_0058168c)[(param_2._2_2_ & 0x7800) >> 0xb] != '\0')) && ((param_3 & 0x7fff) != 0x7fff)

      ) && ((((in_stack_00000024 & 0x7fff) != 0 && ((in_stack_00000024 & 0x7fff) != 0x7fff)) &&

            (((_uStack00000020 & 0x7fffffff) == 0 && ((param_2 & 0x7fffffff) == 0)))))) {

    if ((ushort)((param_3 & 0x7fff) + 0x3f) < (in_stack_00000024 & 0x7fff)) {

      iVar1 = ((in_stack_00000024 & 0x7fff) - (param_3 & 0x7fff) & 0x3f | 0x20) + 1;

      fVar3 = ABS((float10)CONCAT28(in_stack_00000024 & 0x7fff | param_3 & 0x8000,

                                    CONCAT26(param_2._2_2_,CONCAT24((undefined2)param_2,param_1))));

      fVar2 = ABS((float10)CONCAT28(in_stack_00000024,

                                    CONCAT26(uStack00000022,

                                             CONCAT24(uStack00000020,in_stack_0000001c))));

      do {

        if (fVar3 <= fVar2) {

          fVar2 = fVar2 - fVar3;

        }

        fVar3 = fVar3 * (float10)_DAT_005816bc;

        iVar1 = iVar1 + -1;

      } while (iVar1 != 0);

    }

    else {

      while (-1 < (int)((in_stack_00000024 & 0x7fff) - ((param_3 & 0x7fff) + 10))) {

        fVar2 = (float10)CONCAT28(in_stack_00000024,

                                  CONCAT26(uStack00000022,CONCAT24(uStack00000020,in_stack_0000001c)

                                          ));

        fVar3 = (float10)CONCAT28((in_stack_00000024 & 0x7fff) -

                                  ((in_stack_00000024 & 0x7fff) - param_3 & 7 | 4) |

                                  param_3 & 0x8000,

                                  CONCAT26(param_2._2_2_,CONCAT24((undefined2)param_2,param_1)));

        fVar2 = fVar2 - (float10)(unkint10)(fVar2 / fVar3) * fVar3;

        in_stack_0000001c = SUB104(fVar2,0);

        uStack00000020 = (undefined2)((unkuint10)fVar2 >> 0x20);

        uStack00000022 = (undefined2)((unkuint10)fVar2 >> 0x30);

        in_stack_00000024 = (ushort)((unkuint10)fVar2 >> 0x40);

      }

    }

  }

  return in_EAX;

}

/* ===== fmod @ 0x005494FC ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



float10 fmod(void)



{

  float10 in_ST0;

  float10 fVar1;

  float10 in_ST1;

  

  if (((uint)((unkuint10)in_ST1 >> 0x30) & 0x7fff0000) != 0) {

    fVar1 = (float10)crt_fmod10();

    return fVar1;

  }

  if (SUB104(in_ST1,0) != 0 || (int)((unkuint10)in_ST1 >> 0x20) != 0) {

    fVar1 = (float10)crt_fmod10(in_ST1 * (float10)_DAT_005816a4);

    return fVar1;

  }

  return in_ST0 - (float10)(unkint10)(in_ST0 / in_ST1) * in_ST1;

}

/* ===== crt_frndint @ 0x00549A90 ===== */
float10 crt_frndint(void)



{

  float10 in_ST0;

  

  crt_fpe_signal();

  return (float10)(double)in_ST0;

}

/* ===== __startOneArgErrorHandling @ 0x00549AA7 ===== */
/* Library Function - Single Match

    __startOneArgErrorHandling

   

   Library: Visual Studio */



float10 __startOneArgErrorHandling(void)



{

  float10 in_ST0;

  

  crt_fpe_signal();

  return (float10)(double)in_ST0;

}

/* ===== crt_exp2 @ 0x00549AF0 ===== */
unkbyte10 crt_exp2(void)



{

  float10 in_ST0;

  float10 fVar1;

  unkbyte10 Var2;

  

  fVar1 = (float10)f2xm1(-(ROUND(in_ST0) - in_ST0));

  Var2 = fscale((float10)1 + fVar1,ROUND(in_ST0));

  return Var2;

}

/* ===== ANM_DumpCluster_7 @ 0x00549B05 ===== */
void ANM_DumpCluster_7(void)



{

  return;

}

/* ===== FUN_00549b1c @ 0x00549B1C ===== */
undefined4 FUN_00549b1c(void)



{

  uint in_EAX;

  

  if ((in_EAX & 0x80000) != 0) {

    return 7;

  }

  return 1;

}

/* ===== __fload_withFB @ 0x00549B35 ===== */
/* Library Function - Single Match

    __fload_withFB

   

   Library: Visual Studio */



uint __fload_withFB(void)



{

  uint uVar1;

  int in_EDX;

  

  uVar1 = *(uint *)(in_EDX + 4) & 0x7ff00000;

  if (uVar1 != 0x7ff00000) {

    return uVar1;

  }

  return *(uint *)(in_EDX + 4);

}

/* ===== FUN_00549b78 @ 0x00549B78 ===== */
uint FUN_00549b78(undefined4 param_1,uint param_2)



{

  if ((param_2 & 0x7ff00000) != 0x7ff00000) {

    return param_2 & 0x7ff00000;

  }

  return param_2;

}

/* ===== ANM_DumpCluster_8 @ 0x00549B8E ===== */
void ANM_DumpCluster_8(void)



{

  return;

}

/* ===== __math_exit @ 0x00549B9B ===== */
/* Library Function - Single Match

    __math_exit

   

   Library: Visual Studio */



void __math_exit(void)



{

  ushort in_FPUStatusWord;

  ushort unaff_retaddr;

  

  if (((unaff_retaddr != 0x27f) && ((unaff_retaddr & 0x20) != 0)) &&

     ((in_FPUStatusWord & 0x20) != 0)) {

    __startOneArgErrorHandling();

    return;

  }

  return;

}

/* ===== crt_frndint_user @ 0x00549BD9 ===== */
void crt_frndint_user(void)



{

  int in_EDX;

  ushort in_FPUStatusWord;

  float10 in_ST0;

  ushort unaff_retaddr;

  uint uStack_4;

  

  uStack_4 = (uint)((ulonglong)(double)in_ST0 >> 0x20);

  if (((ulonglong)(double)in_ST0 & 0x7ff0000000000000) == 0) {

    fscale(in_ST0,(float10)1536.0);

  }

  else if ((uStack_4 & 0x7ff00000) == 0x7ff00000) {

    fscale(in_ST0,(float10)-1536.0);

  }

  else if (((unaff_retaddr == 0x27f) || ((unaff_retaddr & 0x20) != 0)) ||

          ((in_FPUStatusWord & 0x20) == 0)) {

    return;

  }

  if (in_EDX == 0x1d) {

    crt_frndint();

    return;

  }

  __startOneArgErrorHandling();

  return;

}

/* ===== crt_pow_special @ 0x00549C7C ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined4 crt_pow_special(int param_1,int param_2,double param_3,double *param_4)



{

  double dVar1;

  double dVar2;

  int iVar3;

  

  dVar1 = (double)CONCAT44(param_2,param_1);

  if ((double)CONCAT44(param_2,param_1) < 0.0) {

    dVar1 = -dVar1;

  }

  dVar2 = _DAT_00581488;

  if (param_3._4_4_ == 0x7ff00000) {

    if (param_3._0_4_ != 0) {

LAB_00549d07:

      if (param_2 == 0x7ff00000) {

        if (param_1 != 0) {

          return 0;

        }

        if (0.0 < param_3) goto LAB_00549da2;

        if (param_3 < 0.0) goto LAB_00549d39;

      }

      else {

        if (param_2 != -0x100000) {

          return 0;

        }

        if (param_1 != 0) {

          return 0;

        }

        iVar3 = crt_isodd_int(param_3);

        if (0.0 < param_3) {

          dVar2 = _DAT_00581488;

          if (iVar3 == 1) {

            dVar2 = -_DAT_00581488;

          }

          goto LAB_00549da2;

        }

        if (param_3 < 0.0) {

          dVar2 = _DAT_005814a8;

          if (iVar3 != 1) {

            dVar2 = 0.0;

          }

          goto LAB_00549da2;

        }

      }

      dVar2 = 1.0;

      goto LAB_00549da2;

    }

    if (1.0 < dVar1) goto LAB_00549da2;

    if (1.0 <= dVar1) {

LAB_00549ccc:

      *param_4 = _DAT_00581490;

      return 1;

    }

  }

  else {

    if ((param_3._4_4_ != -0x100000) || (param_3._0_4_ != 0)) goto LAB_00549d07;

    if (dVar1 <= 1.0) {

      if (1.0 <= dVar1) goto LAB_00549ccc;

      goto LAB_00549da2;

    }

  }

LAB_00549d39:

  dVar2 = 0.0;

LAB_00549da2:

  *param_4 = dVar2;

  return 0;

}

/* ===== crt_isodd_int @ 0x00549DAC ===== */
undefined4 crt_isodd_int(double param_1)



{

  uint uVar1;

  float10 fVar2;

  undefined4 uVar3;

  undefined8 extraout_var;

  

  uVar1 = crt_fpclassify(param_1);

  if ((uVar1 & 0x90) == 0) {

    fVar2 = (float10)__frnd(param_1,extraout_var);

    if ((double)fVar2 == param_1) {

      fVar2 = (float10)__frnd();

      if (fVar2 == (float10)(param_1 / 2.0)) {

        uVar3 = 2;

      }

      else {

        uVar3 = 1;

      }

      return uVar3;

    }

  }

  return 0;

}

/* ===== _input @ 0x00549E11 ===== */
int _input(undefined4 param_1,byte *param_2,undefined4 *param_3)



{

  byte bVar1;

  undefined4 *puVar2;

  byte bVar3;

  uint uVar4;

  undefined4 uVar5;

  int iVar6;

  uint uVar7;

  uint uVar8;

  byte bVar9;

  byte *pbVar10;

  char *pcVar11;

  char *pcVar12;

  byte *pbVar13;

  bool bVar14;

  longlong lVar15;

  char local_1c8;

  char local_1c7 [351];

  byte local_68 [32];

  undefined4 *local_48;

  undefined2 local_42;

  uint local_40;

  byte local_3c;

  undefined1 local_3b;

  byte local_39;

  int local_38;

  byte *local_34;

  byte *local_30;

  undefined8 local_2c;

  int local_24;

  int local_20;

  byte local_1c;

  char local_1b;

  char local_1a;

  char local_19;

  uint local_18;

  char local_13;

  char local_12;

  char local_11;

  int local_10;

  char local_9;

  int local_8;

  

  local_19 = '\0';

  bVar1 = *param_2;

  local_8 = 0;

  local_38 = 0;

  pbVar10 = param_2;

  do {

    if (bVar1 == 0) {

LAB_0054a817:

      if (local_18 == 0xffffffff) {

LAB_0054a81d:

        if ((local_38 == 0) && (local_19 == '\0')) {

          local_38 = -1;

        }

      }

      return local_38;

    }

    if (DAT_005810b8 < 2) {

      uVar4 = (byte)PTR_DAT_00580eac[(uint)bVar1 * 2] & 8;

    }

    else {

      uVar4 = FUN_00544123(bVar1,8);

    }

    if (uVar4 != 0) {

      local_8 = local_8 + -1;

      uVar5 = crt_scanf_skipws(&local_8,param_1,param_1);

      MemFree(uVar5);

      iVar6 = FUN_005451d1(pbVar10[1]);

      pbVar13 = pbVar10;

      while (pbVar10 = pbVar13 + 1, iVar6 != 0) {

        iVar6 = FUN_005451d1(pbVar13[2]);

        pbVar13 = pbVar10;

      }

    }

    if (*pbVar10 == 0x25) {

      local_39 = 0;

      local_1c = 0;

      local_1b = '\0';

      local_12 = '\0';

      local_13 = '\0';

      local_1a = '\0';

      iVar6 = 0;

      local_9 = '\0';

      local_20 = 0;

      local_24 = 0;

      local_10 = 0;

      local_11 = '\x01';

      local_34 = (byte *)0x0;

      do {

        uVar4 = (uint)pbVar10[1];

        param_2 = pbVar10 + 1;

        if (DAT_005810b8 < 2) {

          uVar7 = (byte)PTR_DAT_00580eac[uVar4 * 2] & 4;

        }

        else {

          uVar7 = FUN_00544123(uVar4,4);

        }

        if (uVar7 == 0) {

          if (uVar4 < 0x4f) {

            if (uVar4 != 0x4e) {

              if (uVar4 == 0x2a) {

                local_12 = local_12 + '\x01';

              }

              else if (uVar4 != 0x46) {

                if (uVar4 == 0x49) {

                  if ((pbVar10[2] != 0x36) || (pbVar10[3] != 0x34)) goto LAB_00549f6c;

                  local_34 = local_34 + 1;

                  local_2c = 0;

                  param_2 = pbVar10 + 3;

                }

                else if (uVar4 == 0x4c) {

                  local_11 = local_11 + '\x01';

                }

                else {

LAB_00549f6c:

                  local_13 = local_13 + '\x01';

                }

              }

            }

          }

          else if (uVar4 == 0x68) {

            local_11 = local_11 + -1;

            local_9 = local_9 + -1;

          }

          else {

            if (uVar4 == 0x6c) {

              local_11 = local_11 + '\x01';

            }

            else if (uVar4 != 0x77) goto LAB_00549f6c;

            local_9 = local_9 + '\x01';

          }

        }

        else {

          local_24 = local_24 + 1;

          local_10 = (uVar4 - 0x30) + local_10 * 10;

        }

        pbVar10 = param_2;

      } while (local_13 == '\0');

      puVar2 = param_3;

      if (local_12 == '\0') {

        local_30 = (byte *)*param_3;

        puVar2 = param_3 + 1;

        local_48 = param_3;

      }

      param_3 = puVar2;

      local_13 = '\0';

      if (local_9 == '\0') {

        if ((*param_2 == 0x53) || (*param_2 == 0x43)) {

          local_9 = '\x01';

        }

        else {

          local_9 = -1;

        }

      }

      uVar4 = *param_2 | 0x20;

      local_40 = uVar4;

      if (uVar4 != 0x6e) {

        if ((uVar4 == 99) || (uVar4 == 0x7b)) {

          local_8 = local_8 + 1;

          local_18 = crt_scanf_getchar(param_1);

        }

        else {

          local_18 = crt_scanf_skipws(&local_8,param_1);

        }

      }

      if ((local_24 != 0) && (local_10 == 0)) {

LAB_0054a7f7:

        local_8 = local_8 + -1;

        MemFree(local_18,param_1);

        goto LAB_0054a817;

      }

      if (uVar4 < 0x70) {

        if (uVar4 == 0x6f) {

LAB_0054a524:

          if (local_18 == 0x2d) {

            local_1b = '\x01';

          }

          else if (local_18 != 0x2b) goto LAB_0054a559;

          local_10 = local_10 + -1;

          if ((local_10 == 0) && (local_24 != 0)) {

            local_13 = '\x01';

          }

          else {

            local_8 = local_8 + 1;

            local_18 = crt_scanf_getchar(param_1);

          }

          goto LAB_0054a559;

        }

        if (uVar4 != 99) {

          if (uVar4 == 100) goto LAB_0054a524;

          if (uVar4 < 0x65) {

LAB_0054a29c:

            if (*param_2 != local_18) goto LAB_0054a7f7;

            local_19 = local_19 + -1;

            if (local_12 == '\0') {

              param_3 = local_48;

            }

            goto LAB_0054a778;

          }

          if (0x67 < uVar4) {

            if (uVar4 == 0x69) {

              uVar4 = 100;

              goto LAB_0054a05a;

            }

            if (uVar4 != 0x6e) goto LAB_0054a29c;

            iVar6 = local_8;

            lVar15 = local_2c;

            if (local_12 != '\0') goto LAB_0054a778;

            goto LAB_0054a752;

          }

          pcVar11 = &local_1c8;

          if (local_18 == 0x2d) {

            local_1c8 = '-';

            pcVar11 = local_1c7;

LAB_0054a090:

            local_10 = local_10 + -1;

            local_8 = local_8 + 1;

            local_18 = crt_scanf_getchar(param_1);

          }

          else if (local_18 == 0x2b) goto LAB_0054a090;

          if ((local_24 == 0) || (0x15d < local_10)) {

            local_10 = 0x15d;

          }

          while( true ) {

            uVar4 = local_18;

            if (DAT_005810b8 < 2) {

              uVar7 = (byte)PTR_DAT_00580eac[local_18 * 2] & 4;

            }

            else {

              uVar7 = FUN_00544123(local_18,4);

            }

            if ((uVar7 == 0) ||

               (iVar6 = local_10 + -1, bVar14 = local_10 == 0, local_10 = iVar6, bVar14)) break;

            local_20 = local_20 + 1;

            *pcVar11 = (char)uVar4;

            pcVar11 = pcVar11 + 1;

            local_8 = local_8 + 1;

            local_18 = crt_scanf_getchar(param_1);

          }

          if ((DAT_005810bc == (char)uVar4) &&

             (iVar6 = local_10 + -1, bVar14 = local_10 != 0, local_10 = iVar6, bVar14)) {

            local_8 = local_8 + 1;

            uVar4 = crt_scanf_getchar(param_1);

            *pcVar11 = DAT_005810bc;

            while( true ) {

              pcVar11 = pcVar11 + 1;

              local_18 = uVar4;

              if (DAT_005810b8 < 2) {

                uVar7 = (byte)PTR_DAT_00580eac[uVar4 * 2] & 4;

              }

              else {

                uVar7 = FUN_00544123(uVar4,4);

              }

              if ((uVar7 == 0) ||

                 (iVar6 = local_10 + -1, bVar14 = local_10 == 0, local_10 = iVar6, bVar14)) break;

              local_20 = local_20 + 1;

              *pcVar11 = (char)uVar4;

              local_8 = local_8 + 1;

              uVar4 = crt_scanf_getchar(param_1);

            }

          }

          pcVar12 = pcVar11;

          if ((local_20 != 0) &&

             (((uVar4 == 0x65 || (uVar4 == 0x45)) &&

              (iVar6 = local_10 + -1, bVar14 = local_10 != 0, local_10 = iVar6, bVar14)))) {

            *pcVar11 = 'e';

            pcVar12 = pcVar11 + 1;

            local_8 = local_8 + 1;

            uVar4 = crt_scanf_getchar(param_1);

            local_18 = uVar4;

            if (uVar4 == 0x2d) {

              *pcVar12 = '-';

              pcVar12 = pcVar11 + 2;

LAB_0054a1b7:

              bVar14 = local_10 != 0;

              local_10 = local_10 + -1;

              if (bVar14) goto LAB_0054a1c6;

              local_10 = 0;

            }

            else if (uVar4 == 0x2b) goto LAB_0054a1b7;

            while( true ) {

              if (DAT_005810b8 < 2) {

                uVar7 = (byte)PTR_DAT_00580eac[uVar4 * 2] & 4;

              }

              else {

                uVar7 = FUN_00544123(uVar4,4);

              }

              if ((uVar7 == 0) ||

                 (iVar6 = local_10 + -1, bVar14 = local_10 == 0, local_10 = iVar6, bVar14)) break;

              local_20 = local_20 + 1;

              *pcVar12 = (char)uVar4;

              pcVar12 = pcVar12 + 1;

LAB_0054a1c6:

              local_8 = local_8 + 1;

              uVar4 = crt_scanf_getchar(param_1);

              local_18 = uVar4;

            }

          }

          local_8 = local_8 + -1;

          MemFree(uVar4,param_1);

          if (local_20 != 0) {

            if (local_12 == '\0') {

              local_38 = local_38 + 1;

              *pcVar12 = '\0';

              (*(code *)PTR_FUN_0054D5A8_00581390)(local_11 + -1,local_30,&local_1c8);

            }

            goto LAB_0054a778;

          }

          goto LAB_0054a817;

        }

        if (local_24 == 0) {

          local_10 = local_10 + 1;

          local_24 = 1;

        }

        if ('\0' < local_9) {

          local_1a = '\x01';

        }

        pcVar11 = &DAT_00581838;

LAB_0054a37d:

        local_1c = 0xff;

        pbVar10 = (byte *)pcVar11;

        pbVar13 = param_2;

LAB_0054a381:

        param_2 = pbVar13;

        _memset(local_68,0,0x20);

        if ((local_40 == 0x7b) && (*pbVar10 == 0x5d)) {

          uVar4 = 0x5d;

          local_68[0xb] = 0x20;

          pbVar10 = pbVar10 + 1;

        }

        else {

          uVar4 = (uint)local_39;

        }

        while (pbVar13 = local_30, bVar1 = *pbVar10, bVar1 != 0x5d) {

          if (((bVar1 == 0x2d) && (bVar9 = (byte)uVar4, bVar9 != 0)) &&

             (bVar3 = pbVar10[1], bVar3 != 0x5d)) {

            if (bVar3 <= bVar9) {

              uVar4 = (uint)bVar3;

              bVar3 = bVar9;

            }

            if ((byte)uVar4 <= bVar3) {

              iVar6 = (bVar3 - uVar4) + 1;

              do {

                local_68[uVar4 >> 3] = local_68[uVar4 >> 3] | '\x01' << ((byte)uVar4 & 7);

                uVar4 = uVar4 + 1;

                iVar6 = iVar6 + -1;

              } while (iVar6 != 0);

            }

            uVar4 = 0;

            pbVar10 = pbVar10 + 2;

          }

          else {

            uVar4 = (uint)bVar1;

            local_68[bVar1 >> 3] = local_68[bVar1 >> 3] | '\x01' << (bVar1 & 7);

            pbVar10 = pbVar10 + 1;

          }

        }

        if (*pbVar10 == 0) goto LAB_0054a817;

        if (local_40 == 0x7b) {

          param_2 = pbVar10;

        }

        local_8 = local_8 + -1;

        local_34 = local_30;

        MemFree(local_18,param_1);

        while( true ) {

          if ((local_24 != 0) &&

             (iVar6 = local_10 + -1, bVar14 = local_10 == 0, local_10 = iVar6, bVar14))

          goto LAB_0054a4e6;

          local_8 = local_8 + 1;

          local_18 = crt_scanf_getchar(param_1);

          if ((local_18 == 0xffffffff) ||

             (bVar1 = (byte)local_18,

             ((int)(char)(local_68[(int)local_18 >> 3] ^ local_1c) & 1 << (bVar1 & 7)) == 0)) break;

          if (local_12 == '\0') {

            if (local_1a == '\0') {

              *pbVar13 = bVar1;

              pbVar13 = pbVar13 + 1;

              local_30 = pbVar13;

            }

            else {

              local_3c = bVar1;

              if ((PTR_DAT_00580eac[(local_18 & 0xff) * 2 + 1] & 0x80) != 0) {

                local_8 = local_8 + 1;

                local_3b = crt_scanf_getchar(param_1);

              }

              crt_lock_54dc7f(&local_42,&local_3c,DAT_005810b8);

              *(undefined2 *)pbVar13 = local_42;

              pbVar13 = pbVar13 + 2;

              local_30 = pbVar13;

            }

          }

          else {

            local_34 = local_34 + 1;

          }

        }

        local_8 = local_8 + -1;

        MemFree(local_18,param_1);

LAB_0054a4e6:

        if (local_34 == pbVar13) goto LAB_0054a817;

        if ((local_12 == '\0') && (local_38 = local_38 + 1, local_40 != 99)) {

          if (local_1a == '\0') {

            *local_30 = 0;

          }

          else {

            local_30[0] = 0;

            local_30[1] = 0;

          }

        }

      }

      else {

        if (uVar4 == 0x70) {

          local_11 = '\x01';

          goto LAB_0054a524;

        }

        if (uVar4 == 0x73) {

          if ('\0' < local_9) {

            local_1a = '\x01';

          }

          pcVar11 = s_____00581830;

          goto LAB_0054a37d;

        }

        if (uVar4 == 0x75) goto LAB_0054a524;

        if (uVar4 != 0x78) {

          if (uVar4 != 0x7b) goto LAB_0054a29c;

          if ('\0' < local_9) {

            local_1a = '\x01';

          }

          pbVar10 = param_2 + 1;

          pbVar13 = pbVar10;

          if (*pbVar10 == 0x5e) {

            pcVar11 = (char *)(param_2 + 2);

            param_2 = pbVar10;

            goto LAB_0054a37d;

          }

          goto LAB_0054a381;

        }

LAB_0054a05a:

        if (local_18 == 0x2d) {

          local_1b = '\x01';

LAB_0054a2e9:

          local_10 = local_10 + -1;

          if ((local_10 == 0) && (local_24 != 0)) {

            local_13 = '\x01';

          }

          else {

            local_8 = local_8 + 1;

            local_18 = crt_scanf_getchar(param_1);

          }

        }

        else if (local_18 == 0x2b) goto LAB_0054a2e9;

        if (local_18 == 0x30) {

          local_8 = local_8 + 1;

          local_18 = crt_scanf_getchar(param_1);

          if (((char)local_18 == 'x') || ((char)local_18 == 'X')) {

            local_8 = local_8 + 1;

            local_18 = crt_scanf_getchar(param_1);

            uVar4 = 0x78;

          }

          else {

            local_20 = 1;

            if (uVar4 == 0x78) {

              local_8 = local_8 + -1;

              MemFree(local_18,param_1);

              local_18 = 0x30;

            }

            else {

              uVar4 = 0x6f;

            }

          }

        }

LAB_0054a559:

        lVar15 = local_2c;

        if (local_34 == (byte *)0x0) {

          if (local_13 == '\0') {

            while ((uVar7 = local_18, uVar4 != 0x78 && (uVar4 != 0x70))) {

              if (DAT_005810b8 < 2) {

                uVar8 = (byte)PTR_DAT_00580eac[local_18 * 2] & 4;

              }

              else {

                uVar8 = FUN_00544123(local_18,4);

              }

              if (uVar8 == 0) goto LAB_0054a720;

              if (uVar4 == 0x6f) {

                if (0x37 < (int)uVar7) goto LAB_0054a720;

                iVar6 = iVar6 << 3;

              }

              else {

                iVar6 = iVar6 * 10;

              }

LAB_0054a6f8:

              local_20 = local_20 + 1;

              iVar6 = iVar6 + -0x30 + uVar7;

              if ((local_24 != 0) && (local_10 = local_10 + -1, lVar15 = local_2c, local_10 == 0))

              goto LAB_0054a72e;

              local_8 = local_8 + 1;

              local_18 = crt_scanf_getchar(param_1);

            }

            if (DAT_005810b8 < 2) {

              uVar8 = (byte)PTR_DAT_00580eac[local_18 * 2] & 0x80;

            }

            else {

              uVar8 = FUN_00544123(local_18,0x80);

            }

            if (uVar8 != 0) {

              iVar6 = iVar6 << 4;

              uVar7 = crt_scanf_hexchar(uVar7);

              local_18 = uVar7;

              goto LAB_0054a6f8;

            }

LAB_0054a720:

            local_8 = local_8 + -1;

            MemFree(uVar7,param_1);

            lVar15 = local_2c;

          }

LAB_0054a72e:

          if (local_1b != '\0') {

            iVar6 = -iVar6;

          }

        }

        else {

          if (local_13 == '\0') {

            while (uVar7 = local_18, uVar4 != 0x78) {

              if (DAT_005810b8 < 2) {

                uVar8 = (byte)PTR_DAT_00580eac[local_18 * 2] & 4;

              }

              else {

                uVar8 = FUN_00544123(local_18,4);

              }

              if (uVar8 == 0) goto LAB_0054a642;

              if (uVar4 == 0x6f) {

                if (0x37 < (int)uVar7) goto LAB_0054a642;

                lVar15 = __allshl();

              }

              else {

                lVar15 = __allmul(local_2c,10,0);

              }

LAB_0054a614:

              local_20 = local_20 + 1;

              local_2c = lVar15 + (int)(uVar7 - 0x30);

              if ((local_24 != 0) && (local_10 = local_10 + -1, lVar15 = local_2c, local_10 == 0))

              goto LAB_0054a650;

              local_8 = local_8 + 1;

              local_18 = crt_scanf_getchar(param_1);

            }

            if (DAT_005810b8 < 2) {

              uVar8 = (byte)PTR_DAT_00580eac[local_18 * 2] & 0x80;

            }

            else {

              uVar8 = FUN_00544123(local_18,0x80);

            }

            if (uVar8 != 0) {

              lVar15 = __allshl();

              local_2c = lVar15;

              uVar7 = crt_scanf_hexchar(uVar7);

              local_18 = uVar7;

              lVar15 = local_2c;

              goto LAB_0054a614;

            }

LAB_0054a642:

            local_8 = local_8 + -1;

            MemFree(uVar7,param_1);

            lVar15 = local_2c;

          }

LAB_0054a650:

          local_2c._4_4_ = (int)((ulonglong)lVar15 >> 0x20);

          local_2c._0_4_ = (int)lVar15;

          if (local_1b != '\0') {

            lVar15 = CONCAT44(-(local_2c._4_4_ + (uint)((int)local_2c != 0)),-(int)local_2c);

          }

        }

        if (uVar4 == 0x46) {

          local_20 = 0;

        }

        if (local_20 == 0) goto LAB_0054a817;

        local_2c = lVar15;

        if (local_12 == '\0') {

          local_38 = local_38 + 1;

LAB_0054a752:

          local_2c = lVar15;

          if (local_34 == (byte *)0x0) {

            if (local_11 == '\0') {

              *(short *)local_30 = (short)iVar6;

            }

            else {

              *(int *)local_30 = iVar6;

            }

          }

          else {

            *(longlong *)local_30 = lVar15;

          }

        }

      }

LAB_0054a778:

      local_19 = local_19 + '\x01';

      param_2 = param_2 + 1;

    }

    else {

      local_8 = local_8 + 1;

      uVar4 = crt_scanf_getchar(param_1);

      param_2 = pbVar10 + 1;

      local_18 = uVar4;

      if (*pbVar10 != uVar4) goto LAB_0054a7f7;

      if ((PTR_DAT_00580eac[(uVar4 & 0xff) * 2 + 1] & 0x80) != 0) {

        local_8 = local_8 + 1;

        uVar7 = crt_scanf_getchar(param_1);

        bVar1 = *param_2;

        param_2 = pbVar10 + 2;

        if (bVar1 != uVar7) {

          local_8 = local_8 + -1;

          MemFree(uVar7,param_1);

          local_8 = local_8 + -1;

          MemFree(uVar4,param_1);

          goto LAB_0054a817;

        }

        local_8 = local_8 + -1;

      }

    }

    if ((local_18 == 0xffffffff) && ((*param_2 != 0x25 || (param_2[1] != 0x6e)))) goto LAB_0054a81d;

    bVar1 = *param_2;

    pbVar10 = param_2;

  } while( true );

}

/* ===== crt_scanf_hexchar @ 0x0054A836 ===== */
uint crt_scanf_hexchar(uint param_1)



{

  uint uVar1;

  

  if (DAT_005810b8 < 2) {

    uVar1 = (byte)PTR_DAT_00580eac[param_1 * 2] & 4;

  }

  else {

    uVar1 = FUN_00544123(param_1,4);

  }

  if (uVar1 == 0) {

    param_1 = (param_1 & 0xffffffdf) - 7;

  }

  return param_1;

}

/* ===== crt_scanf_getchar @ 0x0054A86D ===== */
uint crt_scanf_getchar(undefined4 *param_1)



{

  int *piVar1;

  byte bVar2;

  uint uVar3;

  

  piVar1 = param_1 + 1;

  *piVar1 = *piVar1 + -1;

  if (-1 < *piVar1) {

    bVar2 = *(byte *)*param_1;

    *param_1 = (byte *)*param_1 + 1;

    return (uint)bVar2;

  }

  uVar3 = _filbuf(param_1);

  return uVar3;

}

/* ===== MemFree @ 0x0054A887 ===== */
/* PS2 candidate: MemFree (conf 0.818) */



void MemFree(int param_1,undefined4 param_2)



{

  if (param_1 != -1) {

    FUN_0054ddcf(param_1,param_2);

  }

  return;

}

/* ===== crt_scanf_skipws @ 0x0054A89E ===== */
undefined4 crt_scanf_skipws(int *param_1,undefined4 param_2)



{

  undefined4 uVar1;

  int iVar2;

  

  do {

    *param_1 = *param_1 + 1;

    uVar1 = crt_scanf_getchar(param_2);

    iVar2 = FUN_005451d1(uVar1);

  } while (iVar2 != 0);

  return uVar1;

}

/* ===== crt_getstringtype @ 0x0054A8C2 ===== */
BOOL crt_getstringtype(DWORD param_1,LPCSTR param_2,int param_3,LPWORD param_4,UINT param_5,

                      LCID param_6,int param_7)



{

  undefined1 *puVar1;

  BOOL BVar2;

  int iVar3;

  WORD local_20 [2];

  undefined1 *local_1c;

  void *local_14;

  undefined1 *puStack_10;

  undefined *puStack_c;

  undefined4 local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &DAT_005525a8;

  puStack_10 = &LAB_00544c84;

  local_14 = ExceptionList;

  local_1c = &stack0xffffffc8;

  iVar3 = DAT_00630bd8;

  ExceptionList = &local_14;

  puVar1 = &stack0xffffffc8;

  if (DAT_00630bd8 == 0) {

    ExceptionList = &local_14;

    BVar2 = GetStringTypeW(1,L"",1,local_20);

    iVar3 = 1;

    puVar1 = local_1c;

    if (BVar2 == 0) {

      BVar2 = GetStringTypeA(0,1,"",1,local_20);

      if (BVar2 == 0) {

        ExceptionList = local_14;

        return 0;

      }

      iVar3 = 2;

      puVar1 = local_1c;

    }

  }

  local_1c = puVar1;

  DAT_00630bd8 = iVar3;

  if (DAT_00630bd8 != 2) {

    if (DAT_00630bd8 == 1) {

      if (param_5 == 0) {

        param_5 = DAT_00630c6c;

      }

      iVar3 = MultiByteToWideChar(param_5,(-(uint)(param_7 != 0) & 8) + 1,param_2,param_3,

                                  (LPWSTR)0x0,0);

      if (iVar3 != 0) {

        local_8 = 0;

        FUN_00543e00();

        local_1c = &stack0xffffffc8;

        _memset(&stack0xffffffc8,0,iVar3 * 2);

        local_8 = 0xffffffff;

        if ((&stack0x00000000 != (undefined1 *)0x38) &&

           (iVar3 = MultiByteToWideChar(param_5,1,param_2,param_3,(LPWSTR)&stack0xffffffc8,iVar3),

           iVar3 != 0)) {

          BVar2 = GetStringTypeW(param_1,(LPCWSTR)&stack0xffffffc8,iVar3,param_4);

          ExceptionList = local_14;

          return BVar2;

        }

      }

    }

    ExceptionList = local_14;

    return 0;

  }

  if (param_6 == 0) {

    param_6 = DAT_00630c5c;

  }

  BVar2 = GetStringTypeA(param_6,param_1,param_2,param_3,param_4);

  ExceptionList = local_14;

  return BVar2;

}

/* ===== __allmul @ 0x0054AA10 ===== */
/* Library Function - Single Match

    __allmul

   

   Library: Visual Studio */



longlong __allmul(uint param_1,int param_2,uint param_3,int param_4)



{

  if (param_4 == 0 && param_2 == 0) {

    return (ulonglong)param_1 * (ulonglong)param_3;

  }

  return CONCAT44((int)((ulonglong)param_1 * (ulonglong)param_3 >> 0x20) +

                  param_2 * param_3 + param_1 * param_4,

                  (int)((ulonglong)param_1 * (ulonglong)param_3));

}

/* ===== crt_scanf_float @ 0x0054AA44 ===== */
void crt_scanf_float(uint *param_1,int param_2)



{

  uint uVar1;

  int iVar2;

  uint uVar3;

  undefined1 local_1c [12];

  undefined4 local_10;

  undefined4 uStack_c;

  int local_8;

  

  uVar3 = 0;

  uVar1 = crt_strtod_core(local_1c,&local_8,param_2,0,0,0,0);

  if ((uVar1 & 4) == 0) {

    iVar2 = BinFileSeek_3(local_1c,&local_10);

    if (((uVar1 & 2) != 0) || (iVar2 == 1)) {

      uVar3 = 0x80;

    }

    if (((uVar1 & 1) != 0) || (iVar2 == 2)) {

      uVar3 = uVar3 | 0x100;

    }

  }

  else {

    uVar3 = 0x200;

    local_10 = 0;

    uStack_c = 0;

  }

  *param_1 = uVar3;

  *(ulonglong *)(param_1 + 4) = CONCAT44(uStack_c,local_10);

  param_1[1] = local_8 - param_2;

  return;

}

/* ===== FUN_0054aac3 @ 0x0054AAC3 ===== */
undefined4 FUN_0054aac3(undefined4 param_1)



{

  int iVar1;

  

  if (DAT_00630be0 != (code *)0x0) {

    iVar1 = (*DAT_00630be0)(param_1);

    if (iVar1 != 0) {

      return 1;

    }

  }

  return 0;

}

/* ===== crt_subsystem_ver @ 0x0054AADE ===== */
void crt_subsystem_ver(undefined4 *param_1)



{

  int iVar1;

  HMODULE pHVar2;

  

  *param_1 = 0;

  pHVar2 = GetModuleHandleA((LPCSTR)0x0);

  if (((short)pHVar2->unused == 0x5a4d) && (iVar1 = pHVar2[0xf].unused, iVar1 != 0)) {

    *(undefined1 *)param_1 = *(undefined1 *)((int)&pHVar2[6].unused + iVar1 + 2);

    *(undefined1 *)((int)param_1 + 1) = *(undefined1 *)((int)&pHVar2[6].unused + iVar1 + 3);

  }

  return;

}

/* ===== crt_heap_select @ 0x0054AB0B ===== */
int crt_heap_select(void)



{

  char cVar1;

  BOOL BVar2;

  DWORD DVar3;

  int iVar4;

  char *pcVar5;

  byte unaff_BL;

  char local_1230 [4240];

  char local_1a0 [260];

  DWORD local_9c;

  uint local_98;

  DWORD local_8c;

  CHAR aCStackY_18 [4];

  

  FUN_00543e00();

  local_9c = 0x94;

  BVar2 = GetVersionExA((LPOSVERSIONINFOA)&local_9c);

  if (((BVar2 == 0) || (local_8c != 2)) || (local_98 < 5)) {

    aCStackY_18[0] = 'e';

    aCStackY_18[1] = -0x55;

    aCStackY_18[2] = 'T';

    aCStackY_18[3] = '\0';

    DVar3 = GetEnvironmentVariableA("__MSVCRT_HEAP_SELECT",local_1230,0x1090);

    if (DVar3 != 0) {

      pcVar5 = local_1230;

      while (local_1230[0] != '\0') {

        cVar1 = *pcVar5;

        if (('`' < cVar1) && (cVar1 < '{')) {

          *pcVar5 = cVar1 + -0x20;

        }

        pcVar5 = pcVar5 + 1;

        local_1230[0] = *pcVar5;

      }

      aCStackY_18[0] = -0x5d;

      aCStackY_18[1] = -0x55;

      aCStackY_18[2] = 'T';

      aCStackY_18[3] = '\0';

      iVar4 = _strncmp("__GLOBAL_HEAP_SELECTED",local_1230,0x16);

      if (iVar4 == 0) {

        pcVar5 = local_1230;

      }

      else {

        builtin_memcpy(aCStackY_18,"ūT",4);

        GetModuleFileNameA((HMODULE)0x0,local_1a0,0x104);

        pcVar5 = local_1a0;

        while (local_1a0[0] != '\0') {

          cVar1 = *pcVar5;

          if (('`' < cVar1) && (cVar1 < '{')) {

            *pcVar5 = cVar1 + -0x20;

          }

          pcVar5 = pcVar5 + 1;

          local_1a0[0] = *pcVar5;

        }

        pcVar5 = _strstr(local_1230,local_1a0);

      }

      if ((pcVar5 != (char *)0x0) && (pcVar5 = _strchr(pcVar5,0x2c), pcVar5 != (char *)0x0)) {

        pcVar5 = pcVar5 + 1;

        cVar1 = *pcVar5;

        while (cVar1 != '\0') {

          if (*pcVar5 == ';') {

            *pcVar5 = '\0';

          }

          else {

            pcVar5 = pcVar5 + 1;

          }

          cVar1 = *pcVar5;

        }

        aCStackY_18[0] = '+';

        aCStackY_18[1] = -0x54;

        aCStackY_18[2] = 'T';

        aCStackY_18[3] = '\0';

        iVar4 = FUN_00544fb5();

        if (iVar4 == 2) {

          return 2;

        }

        if (iVar4 == 3) {

          return 3;

        }

        if (iVar4 == 1) {

          return 1;

        }

      }

    }

    crt_subsystem_ver();

    iVar4 = 3 - (uint)(unaff_BL < 6);

  }

  else {

    iVar4 = 1;

  }

  return iVar4;

}

/* ===== _heap_init @ 0x0054AC53 ===== */
undefined4 _heap_init(int param_1)



{

  int iVar1;

  

  DAT_006579e8 = HeapCreate((uint)(param_1 == 0),0x1000,0);

  if (DAT_006579e8 != (HANDLE)0x0) {

    DAT_006579ec = crt_heap_select();

    if (DAT_006579ec == 3) {

      iVar1 = crt_sbh_init(0x3f8);

    }

    else {

      if (DAT_006579ec != 2) {

        return 1;

      }

      iVar1 = crt_sbh_alloc_heap();

    }

    if (iVar1 != 0) {

      return 1;

    }

    HeapDestroy(DAT_006579e8);

  }

  return 0;

}

/* ===== crt_sbh_init @ 0x0054ACB0 ===== */
undefined4 crt_sbh_init(undefined4 param_1)



{

  DAT_006579e0 = HeapAlloc(DAT_006579e8,0,0x140);

  if (DAT_006579e0 == (LPVOID)0x0) {

    return 0;

  }

  DAT_006579d8 = 0;

  DAT_006579dc = 0;

  DAT_006579d4 = DAT_006579e0;

  DAT_006579e4 = param_1;

  DAT_006579cc = 0x10;

  return 1;

}

/* ===== __sbh_find_block @ 0x0054ACF8 ===== */
uint __sbh_find_block(int param_1)



{

  uint uVar1;

  

  uVar1 = DAT_006579e0;

  while( true ) {

    if (DAT_006579e0 + DAT_006579dc * 0x14 <= uVar1) {

      return 0;

    }

    if ((uint)(param_1 - *(int *)(uVar1 + 0xc)) < 0x100000) break;

    uVar1 = uVar1 + 0x14;

  }

  return uVar1;

}

/* ===== __sbh_free_block @ 0x0054AD23 ===== */
void __sbh_free_block(uint *param_1,int param_2)



{

  char *pcVar1;

  uint *puVar2;

  int *piVar3;

  char cVar4;

  uint uVar5;

  uint uVar6;

  uint uVar7;

  byte bVar8;

  uint uVar9;

  uint *puVar10;

  uint *puVar11;

  uint *puVar12;

  uint uVar13;

  uint uVar14;

  uint local_8;

  

  uVar5 = param_1[4];

  puVar12 = (uint *)(param_2 + -4);

  uVar14 = param_2 - param_1[3] >> 0xf;

  piVar3 = (int *)(uVar14 * 0x204 + 0x144 + uVar5);

  uVar13 = *puVar12;

  local_8 = uVar13 - 1;

  if ((local_8 & 1) == 0) {

    uVar6 = *(uint *)(local_8 + (int)puVar12);

    uVar7 = *(uint *)(param_2 + -8);

    if ((uVar6 & 1) == 0) {

      uVar9 = ((int)uVar6 >> 4) - 1;

      if (0x3f < uVar9) {

        uVar9 = 0x3f;

      }

      if (*(int *)((int)puVar12 + uVar13 + 3) == *(int *)((int)puVar12 + uVar13 + 7)) {

        if (uVar9 < 0x20) {

          pcVar1 = (char *)(uVar9 + 4 + uVar5);

          uVar9 = ~(0x80000000U >> ((byte)uVar9 & 0x1f));

          puVar10 = (uint *)(uVar5 + 0x44 + uVar14 * 4);

          *puVar10 = *puVar10 & uVar9;

          *pcVar1 = *pcVar1 + -1;

          if (*pcVar1 == '\0') {

            *param_1 = *param_1 & uVar9;

          }

        }

        else {

          pcVar1 = (char *)(uVar9 + 4 + uVar5);

          uVar9 = ~(0x80000000U >> ((byte)uVar9 - 0x20 & 0x1f));

          puVar10 = (uint *)(uVar5 + 0xc4 + uVar14 * 4);

          *puVar10 = *puVar10 & uVar9;

          *pcVar1 = *pcVar1 + -1;

          if (*pcVar1 == '\0') {

            param_1[1] = param_1[1] & uVar9;

          }

        }

      }

      local_8 = local_8 + uVar6;

      *(undefined4 *)(*(int *)((int)puVar12 + uVar13 + 7) + 4) =

           *(undefined4 *)((int)puVar12 + uVar13 + 3);

      *(undefined4 *)(*(int *)((int)puVar12 + uVar13 + 3) + 8) =

           *(undefined4 *)((int)puVar12 + uVar13 + 7);

    }

    puVar10 = (uint *)(((int)local_8 >> 4) + -1);

    if ((uint *)0x3f < puVar10) {

      puVar10 = (uint *)0x3f;

    }

    puVar11 = param_1;

    if ((uVar7 & 1) == 0) {

      puVar12 = (uint *)((int)puVar12 - uVar7);

      puVar11 = (uint *)(((int)uVar7 >> 4) + -1);

      if ((uint *)0x3f < puVar11) {

        puVar11 = (uint *)0x3f;

      }

      local_8 = local_8 + uVar7;

      puVar10 = (uint *)(((int)local_8 >> 4) + -1);

      if ((uint *)0x3f < puVar10) {

        puVar10 = (uint *)0x3f;

      }

      if (puVar11 != puVar10) {

        if (puVar12[1] == puVar12[2]) {

          if (puVar11 < (uint *)0x20) {

            uVar13 = ~(0x80000000U >> ((byte)puVar11 & 0x1f));

            puVar2 = (uint *)(uVar5 + 0x44 + uVar14 * 4);

            *puVar2 = *puVar2 & uVar13;

            pcVar1 = (char *)((int)puVar11 + uVar5 + 4);

            *pcVar1 = *pcVar1 + -1;

            if (*pcVar1 == '\0') {

              *param_1 = *param_1 & uVar13;

            }

          }

          else {

            uVar13 = ~(0x80000000U >> ((byte)puVar11 - 0x20 & 0x1f));

            puVar2 = (uint *)(uVar5 + 0xc4 + uVar14 * 4);

            *puVar2 = *puVar2 & uVar13;

            pcVar1 = (char *)((int)puVar11 + uVar5 + 4);

            *pcVar1 = *pcVar1 + -1;

            if (*pcVar1 == '\0') {

              param_1[1] = param_1[1] & uVar13;

            }

          }

        }

        *(uint *)(puVar12[2] + 4) = puVar12[1];

        *(uint *)(puVar12[1] + 8) = puVar12[2];

      }

    }

    if (((uVar7 & 1) != 0) || (puVar11 != puVar10)) {

      puVar12[1] = piVar3[(int)puVar10 * 2 + 1];

      puVar12[2] = (uint)(piVar3 + (int)puVar10 * 2);

      (piVar3 + (int)puVar10 * 2)[1] = (int)puVar12;

      *(uint **)(puVar12[1] + 8) = puVar12;

      if (puVar12[1] == puVar12[2]) {

        cVar4 = *(char *)((int)puVar10 + uVar5 + 4);

        *(char *)((int)puVar10 + uVar5 + 4) = cVar4 + '\x01';

        bVar8 = (byte)puVar10;

        if (puVar10 < (uint *)0x20) {

          if (cVar4 == '\0') {

            *param_1 = *param_1 | 0x80000000U >> (bVar8 & 0x1f);

          }

          puVar10 = (uint *)(uVar5 + 0x44 + uVar14 * 4);

          *puVar10 = *puVar10 | 0x80000000U >> (bVar8 & 0x1f);

        }

        else {

          if (cVar4 == '\0') {

            param_1[1] = param_1[1] | 0x80000000U >> (bVar8 - 0x20 & 0x1f);

          }

          puVar10 = (uint *)(uVar5 + 0xc4 + uVar14 * 4);

          *puVar10 = *puVar10 | 0x80000000U >> (bVar8 - 0x20 & 0x1f);

        }

      }

    }

    *puVar12 = local_8;

    *(uint *)((local_8 - 4) + (int)puVar12) = local_8;

    *piVar3 = *piVar3 + -1;

    if (*piVar3 == 0) {

      if (DAT_006579d8 != (uint *)0x0) {

        VirtualFree((LPVOID)(DAT_006579d0 * 0x8000 + DAT_006579d8[3]),0x8000,0x4000);

        DAT_006579d8[2] = DAT_006579d8[2] | 0x80000000U >> ((byte)DAT_006579d0 & 0x1f);

        *(undefined4 *)(DAT_006579d8[4] + 0xc4 + DAT_006579d0 * 4) = 0;

        *(char *)(DAT_006579d8[4] + 0x43) = *(char *)(DAT_006579d8[4] + 0x43) + -1;

        if (*(char *)(DAT_006579d8[4] + 0x43) == '\0') {

          DAT_006579d8[1] = DAT_006579d8[1] & 0xfffffffe;

        }

        if (DAT_006579d8[2] == 0xffffffff) {

          VirtualFree((LPVOID)DAT_006579d8[3],0,0x8000);

          HeapFree(DAT_006579e8,0,(LPVOID)DAT_006579d8[4]);

          FUN_00543270(DAT_006579d8,DAT_006579d8 + 5,

                       (DAT_006579dc * 0x14 - (int)DAT_006579d8) + -0x14 + DAT_006579e0);

          DAT_006579dc = DAT_006579dc + -1;

          if (DAT_006579d8 < param_1) {

            param_1 = param_1 + -5;

          }

          DAT_006579d4 = DAT_006579e0;

        }

      }

      DAT_006579d8 = param_1;

      DAT_006579d0 = uVar14;

    }

  }

  return;

}

/* ===== __sbh_alloc_block @ 0x0054B04C ===== */
int * __sbh_alloc_block(uint *param_1)



{

  char *pcVar1;

  int *piVar2;

  char cVar3;

  int *piVar4;

  undefined4 uVar5;

  byte bVar6;

  uint uVar7;

  int iVar8;

  uint *puVar9;

  int iVar10;

  int *piVar11;

  uint *puVar12;

  uint *puVar13;

  uint uVar14;

  int iVar15;

  uint local_10;

  uint local_c;

  int local_8;

  

  puVar9 = DAT_006579e0 + DAT_006579dc * 5;

  uVar7 = (int)param_1 + 0x17U & 0xfffffff0;

  iVar8 = ((int)((int)param_1 + 0x17U) >> 4) + -1;

  bVar6 = (byte)iVar8;

  param_1 = DAT_006579d4;

  if (iVar8 < 0x20) {

    local_10 = 0xffffffff >> (bVar6 & 0x1f);

    local_c = 0xffffffff;

  }

  else {

    local_c = 0xffffffff >> (bVar6 - 0x20 & 0x1f);

    local_10 = 0;

  }

  for (; (param_1 < puVar9 && ((param_1[1] & local_c) == 0 && (*param_1 & local_10) == 0));

      param_1 = param_1 + 5) {

  }

  puVar12 = DAT_006579e0;

  if (param_1 == puVar9) {

    for (; (puVar12 < DAT_006579d4 && ((puVar12[1] & local_c) == 0 && (*puVar12 & local_10) == 0));

        puVar12 = puVar12 + 5) {

    }

    param_1 = puVar12;

    if (puVar12 == DAT_006579d4) {

      for (; (puVar12 < puVar9 && (puVar12[2] == 0)); puVar12 = puVar12 + 5) {

      }

      puVar13 = DAT_006579e0;

      param_1 = puVar12;

      if (puVar12 == puVar9) {

        for (; (puVar13 < DAT_006579d4 && (puVar13[2] == 0)); puVar13 = puVar13 + 5) {

        }

        param_1 = puVar13;

        if ((puVar13 == DAT_006579d4) &&

           (param_1 = (uint *)__sbh_alloc_new_region(), param_1 == (uint *)0x0)) {

          return (int *)0x0;

        }

      }

      uVar5 = __sbh_alloc_new_group(param_1);

      *(undefined4 *)param_1[4] = uVar5;

      if (*(int *)param_1[4] == -1) {

        return (int *)0x0;

      }

    }

  }

  piVar4 = (int *)param_1[4];

  local_8 = *piVar4;

  if ((local_8 == -1) ||

     ((piVar4[local_8 + 0x31] & local_c) == 0 && (piVar4[local_8 + 0x11] & local_10) == 0)) {

    local_8 = 0;

    puVar9 = (uint *)(piVar4 + 0x11);

    if ((piVar4[0x31] & local_c) == 0 && (piVar4[0x11] & local_10) == 0) {

      do {

        puVar12 = puVar9 + 0x21;

        local_8 = local_8 + 1;

        puVar9 = puVar9 + 1;

      } while ((*puVar12 & local_c) == 0 && (local_10 & *puVar9) == 0);

    }

  }

  iVar8 = 0;

  piVar2 = piVar4 + local_8 * 0x81 + 0x51;

  local_10 = piVar4[local_8 + 0x11] & local_10;

  if (local_10 == 0) {

    local_10 = piVar4[local_8 + 0x31] & local_c;

    iVar8 = 0x20;

  }

  for (; -1 < (int)local_10; local_10 = local_10 << 1) {

    iVar8 = iVar8 + 1;

  }

  piVar11 = (int *)piVar2[iVar8 * 2 + 1];

  iVar10 = *piVar11 - uVar7;

  iVar15 = (iVar10 >> 4) + -1;

  if (0x3f < iVar15) {

    iVar15 = 0x3f;

  }

  DAT_006579d4 = param_1;

  if (iVar15 != iVar8) {

    if (piVar11[1] == piVar11[2]) {

      if (iVar8 < 0x20) {

        pcVar1 = (char *)((int)piVar4 + iVar8 + 4);

        uVar14 = ~(0x80000000U >> ((byte)iVar8 & 0x1f));

        piVar4[local_8 + 0x11] = uVar14 & piVar4[local_8 + 0x11];

        *pcVar1 = *pcVar1 + -1;

        if (*pcVar1 == '\0') {

          *param_1 = *param_1 & uVar14;

        }

      }

      else {

        pcVar1 = (char *)((int)piVar4 + iVar8 + 4);

        uVar14 = ~(0x80000000U >> ((byte)iVar8 - 0x20 & 0x1f));

        piVar4[local_8 + 0x31] = piVar4[local_8 + 0x31] & uVar14;

        *pcVar1 = *pcVar1 + -1;

        if (*pcVar1 == '\0') {

          param_1[1] = param_1[1] & uVar14;

        }

      }

    }

    *(int *)(piVar11[2] + 4) = piVar11[1];

    *(int *)(piVar11[1] + 8) = piVar11[2];

    if (iVar10 == 0) goto LAB_0054b312;

    piVar11[1] = piVar2[iVar15 * 2 + 1];

    piVar11[2] = (int)(piVar2 + iVar15 * 2);

    (piVar2 + iVar15 * 2)[1] = (int)piVar11;

    *(int **)(piVar11[1] + 8) = piVar11;

    if (piVar11[1] == piVar11[2]) {

      cVar3 = *(char *)(iVar15 + 4 + (int)piVar4);

      bVar6 = (byte)iVar15;

      if (iVar15 < 0x20) {

        *(char *)(iVar15 + 4 + (int)piVar4) = cVar3 + '\x01';

        if (cVar3 == '\0') {

          *param_1 = *param_1 | 0x80000000U >> (bVar6 & 0x1f);

        }

        piVar4[local_8 + 0x11] = piVar4[local_8 + 0x11] | 0x80000000U >> (bVar6 & 0x1f);

      }

      else {

        *(char *)(iVar15 + 4 + (int)piVar4) = cVar3 + '\x01';

        if (cVar3 == '\0') {

          param_1[1] = param_1[1] | 0x80000000U >> (bVar6 - 0x20 & 0x1f);

        }

        piVar4[local_8 + 0x31] = piVar4[local_8 + 0x31] | 0x80000000U >> (bVar6 - 0x20 & 0x1f);

      }

    }

  }

  if (iVar10 != 0) {

    *piVar11 = iVar10;

    *(int *)(iVar10 + -4 + (int)piVar11) = iVar10;

  }

LAB_0054b312:

  piVar11 = (int *)((int)piVar11 + iVar10);

  *piVar11 = uVar7 + 1;

  *(uint *)((int)piVar11 + (uVar7 - 4)) = uVar7 + 1;

  iVar8 = *piVar2;

  *piVar2 = iVar8 + 1;

  if (((iVar8 == 0) && (param_1 == DAT_006579d8)) && (local_8 == DAT_006579d0)) {

    DAT_006579d8 = (uint *)0x0;

  }

  *piVar4 = local_8;

  return piVar11 + 1;

}

/* ===== __sbh_alloc_new_region @ 0x0054B355 ===== */
undefined4 * __sbh_alloc_new_region(void)



{

  undefined4 *puVar1;

  LPVOID pvVar2;

  

  if (DAT_006579dc == DAT_006579cc) {

    pvVar2 = HeapReAlloc(DAT_006579e8,0,DAT_006579e0,(DAT_006579cc * 5 + 0x50) * 4);

    if (pvVar2 == (LPVOID)0x0) {

      return (undefined4 *)0x0;

    }

    DAT_006579cc = DAT_006579cc + 0x10;

    DAT_006579e0 = pvVar2;

  }

  puVar1 = (undefined4 *)((int)DAT_006579e0 + DAT_006579dc * 0x14);

  pvVar2 = HeapAlloc(DAT_006579e8,8,0x41c4);

  puVar1[4] = pvVar2;

  if (pvVar2 != (LPVOID)0x0) {

    pvVar2 = VirtualAlloc((LPVOID)0x0,0x100000,0x2000,4);

    puVar1[3] = pvVar2;

    if (pvVar2 != (LPVOID)0x0) {

      puVar1[2] = 0xffffffff;

      *puVar1 = 0;

      puVar1[1] = 0;

      DAT_006579dc = DAT_006579dc + 1;

      *(undefined4 *)puVar1[4] = 0xffffffff;

      return puVar1;

    }

    HeapFree(DAT_006579e8,0,(LPVOID)puVar1[4]);

  }

  return (undefined4 *)0x0;

}

/* ===== __sbh_alloc_new_group @ 0x0054B406 ===== */
int __sbh_alloc_new_group(int param_1)



{

  int *piVar1;

  char cVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  LPVOID pvVar6;

  int *piVar7;

  int iVar8;

  int iVar9;

  int *lpAddress;

  

  iVar3 = *(int *)(param_1 + 0x10);

  iVar9 = 0;

  for (iVar4 = *(int *)(param_1 + 8); -1 < iVar4; iVar4 = iVar4 << 1) {

    iVar9 = iVar9 + 1;

  }

  iVar8 = 0x3f;

  iVar4 = iVar9 * 0x204 + 0x144 + iVar3;

  iVar5 = iVar4;

  do {

    *(int *)(iVar5 + 8) = iVar5;

    *(int *)(iVar5 + 4) = iVar5;

    iVar5 = iVar5 + 8;

    iVar8 = iVar8 + -1;

  } while (iVar8 != 0);

  lpAddress = (int *)(iVar9 * 0x8000 + *(int *)(param_1 + 0xc));

  pvVar6 = VirtualAlloc(lpAddress,0x8000,0x1000,4);

  if (pvVar6 == (LPVOID)0x0) {

    iVar9 = -1;

  }

  else {

    if (lpAddress <= lpAddress + 0x1c00) {

      piVar7 = lpAddress + 4;

      do {

        piVar7[-2] = -1;

        piVar7[0x3fb] = -1;

        piVar7[-1] = 0xff0;

        *piVar7 = (int)(piVar7 + 0x3ff);

        piVar7[1] = (int)(piVar7 + -0x401);

        piVar7[0x3fa] = 0xff0;

        piVar1 = piVar7 + 0x3fc;

        piVar7 = piVar7 + 0x400;

      } while (piVar1 <= lpAddress + 0x1c00);

    }

    *(int **)(iVar4 + 0x1fc) = lpAddress + 3;

    lpAddress[5] = iVar4 + 0x1f8;

    *(int **)(iVar4 + 0x200) = lpAddress + 0x1c03;

    lpAddress[0x1c04] = iVar4 + 0x1f8;

    *(undefined4 *)(iVar3 + 0x44 + iVar9 * 4) = 0;

    *(undefined4 *)(iVar3 + 0xc4 + iVar9 * 4) = 1;

    cVar2 = *(char *)(iVar3 + 0x43);

    *(char *)(iVar3 + 0x43) = cVar2 + '\x01';

    if (cVar2 == '\0') {

      *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 1;

    }

    *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) & ~(0x80000000U >> ((byte)iVar9 & 0x1f));

  }

  return iVar9;

}

/* ===== __sbh_resize_block @ 0x0054B501 ===== */
undefined4 __sbh_resize_block(uint *param_1,int param_2,int param_3)



{

  char *pcVar1;

  int iVar2;

  int *piVar3;

  int iVar4;

  char cVar5;

  uint uVar6;

  int iVar7;

  uint *puVar8;

  byte bVar9;

  uint uVar10;

  uint uVar11;

  uint uVar12;

  uint uVar13;

  uint local_c;

  

  uVar6 = param_1[4];

  uVar12 = param_3 + 0x17U & 0xfffffff0;

  uVar10 = param_2 - param_1[3] >> 0xf;

  iVar4 = uVar10 * 0x204 + 0x144 + uVar6;

  iVar7 = *(int *)(param_2 + -4);

  param_3 = iVar7 + -1;

  uVar13 = *(uint *)(iVar7 + -5 + param_2);

  iVar7 = iVar7 + -5 + param_2;

  if (param_3 < (int)uVar12) {

    if (((uVar13 & 1) != 0) || ((int)(uVar13 + param_3) < (int)uVar12)) {

      return 0;

    }

    local_c = ((int)uVar13 >> 4) - 1;

    if (0x3f < local_c) {

      local_c = 0x3f;

    }

    if (*(int *)(iVar7 + 4) == *(int *)(iVar7 + 8)) {

      if (local_c < 0x20) {

        pcVar1 = (char *)(local_c + 4 + uVar6);

        uVar11 = ~(0x80000000U >> ((byte)local_c & 0x1f));

        puVar8 = (uint *)(uVar6 + 0x44 + uVar10 * 4);

        *puVar8 = *puVar8 & uVar11;

        *pcVar1 = *pcVar1 + -1;

        if (*pcVar1 == '\0') {

          *param_1 = *param_1 & uVar11;

        }

      }

      else {

        pcVar1 = (char *)(local_c + 4 + uVar6);

        uVar11 = ~(0x80000000U >> ((byte)local_c - 0x20 & 0x1f));

        puVar8 = (uint *)(uVar6 + 0xc4 + uVar10 * 4);

        *puVar8 = *puVar8 & uVar11;

        *pcVar1 = *pcVar1 + -1;

        if (*pcVar1 == '\0') {

          param_1[1] = param_1[1] & uVar11;

        }

      }

    }

    *(undefined4 *)(*(int *)(iVar7 + 8) + 4) = *(undefined4 *)(iVar7 + 4);

    *(undefined4 *)(*(int *)(iVar7 + 4) + 8) = *(undefined4 *)(iVar7 + 8);

    iVar7 = uVar13 + (param_3 - uVar12);

    if (0 < iVar7) {

      uVar13 = (iVar7 >> 4) - 1;

      iVar2 = param_2 + -4 + uVar12;

      if (0x3f < uVar13) {

        uVar13 = 0x3f;

      }

      iVar4 = iVar4 + uVar13 * 8;

      *(undefined4 *)(iVar2 + 4) = *(undefined4 *)(iVar4 + 4);

      *(int *)(iVar2 + 8) = iVar4;

      *(int *)(iVar4 + 4) = iVar2;

      *(int *)(*(int *)(iVar2 + 4) + 8) = iVar2;

      if (*(int *)(iVar2 + 4) == *(int *)(iVar2 + 8)) {

        cVar5 = *(char *)(uVar13 + 4 + uVar6);

        *(char *)(uVar13 + 4 + uVar6) = cVar5 + '\x01';

        bVar9 = (byte)uVar13;

        if (uVar13 < 0x20) {

          if (cVar5 == '\0') {

            *param_1 = *param_1 | 0x80000000U >> (bVar9 & 0x1f);

          }

          puVar8 = (uint *)(uVar6 + 0x44 + uVar10 * 4);

        }

        else {

          if (cVar5 == '\0') {

            param_1[1] = param_1[1] | 0x80000000U >> (bVar9 - 0x20 & 0x1f);

          }

          puVar8 = (uint *)(uVar6 + 0xc4 + uVar10 * 4);

          bVar9 = bVar9 - 0x20;

        }

        *puVar8 = *puVar8 | 0x80000000U >> (bVar9 & 0x1f);

      }

      piVar3 = (int *)(param_2 + -4 + uVar12);

      *piVar3 = iVar7;

      *(int *)(iVar7 + -4 + (int)piVar3) = iVar7;

    }

    *(uint *)(param_2 + -4) = uVar12 + 1;

    *(uint *)(param_2 + -8 + uVar12) = uVar12 + 1;

  }

  else if ((int)uVar12 < param_3) {

    param_3 = param_3 - uVar12;

    *(uint *)(param_2 + -4) = uVar12 + 1;

    piVar3 = (int *)(param_2 + -4 + uVar12);

    uVar11 = (param_3 >> 4) - 1;

    piVar3[-1] = uVar12 + 1;

    if (0x3f < uVar11) {

      uVar11 = 0x3f;

    }

    if ((uVar13 & 1) == 0) {

      uVar12 = ((int)uVar13 >> 4) - 1;

      if (0x3f < uVar12) {

        uVar12 = 0x3f;

      }

      if (*(int *)(iVar7 + 4) == *(int *)(iVar7 + 8)) {

        if (uVar12 < 0x20) {

          pcVar1 = (char *)(uVar12 + 4 + uVar6);

          uVar12 = ~(0x80000000U >> ((byte)uVar12 & 0x1f));

          puVar8 = (uint *)(uVar6 + 0x44 + uVar10 * 4);

          *puVar8 = *puVar8 & uVar12;

          *pcVar1 = *pcVar1 + -1;

          if (*pcVar1 == '\0') {

            *param_1 = *param_1 & uVar12;

          }

        }

        else {

          pcVar1 = (char *)(uVar12 + 4 + uVar6);

          uVar12 = ~(0x80000000U >> ((byte)uVar12 - 0x20 & 0x1f));

          puVar8 = (uint *)(uVar6 + 0xc4 + uVar10 * 4);

          *puVar8 = *puVar8 & uVar12;

          *pcVar1 = *pcVar1 + -1;

          if (*pcVar1 == '\0') {

            param_1[1] = param_1[1] & uVar12;

          }

        }

      }

      *(undefined4 *)(*(int *)(iVar7 + 8) + 4) = *(undefined4 *)(iVar7 + 4);

      *(undefined4 *)(*(int *)(iVar7 + 4) + 8) = *(undefined4 *)(iVar7 + 8);

      param_3 = param_3 + uVar13;

      uVar11 = (param_3 >> 4) - 1;

      if (0x3f < uVar11) {

        uVar11 = 0x3f;

      }

    }

    iVar7 = iVar4 + uVar11 * 8;

    piVar3[1] = *(int *)(iVar4 + 4 + uVar11 * 8);

    piVar3[2] = iVar7;

    *(int **)(iVar7 + 4) = piVar3;

    *(int **)(piVar3[1] + 8) = piVar3;

    if (piVar3[1] == piVar3[2]) {

      cVar5 = *(char *)(uVar11 + 4 + uVar6);

      *(char *)(uVar11 + 4 + uVar6) = cVar5 + '\x01';

      bVar9 = (byte)uVar11;

      if (uVar11 < 0x20) {

        if (cVar5 == '\0') {

          *param_1 = *param_1 | 0x80000000U >> (bVar9 & 0x1f);

        }

        puVar8 = (uint *)(uVar6 + 0x44 + uVar10 * 4);

      }

      else {

        if (cVar5 == '\0') {

          param_1[1] = param_1[1] | 0x80000000U >> (bVar9 - 0x20 & 0x1f);

        }

        puVar8 = (uint *)(uVar6 + 0xc4 + uVar10 * 4);

        bVar9 = bVar9 - 0x20;

      }

      *puVar8 = *puVar8 | 0x80000000U >> (bVar9 & 0x1f);

    }

    *piVar3 = param_3;

    *(int *)(param_3 + -4 + (int)piVar3) = param_3;

  }

  return 1;

}

/* ===== crt_sbh_alloc_heap @ 0x0054B7F7 ===== */
undefined ** crt_sbh_alloc_heap(void)



{

  bool bVar1;

  int *lpAddress;

  LPVOID pvVar2;

  undefined **ppuVar3;

  int iVar4;

  undefined **lpMem;

  

  if (DAT_00581858 == -1) {

    lpMem = &PTR_LOOP_00581848;

  }

  else {

    lpMem = HeapAlloc(DAT_006579e8,0,0x2020);

    if (lpMem == (undefined **)0x0) {

      return (undefined **)0x0;

    }

  }

  lpAddress = VirtualAlloc((LPVOID)0x0,0x400000,0x2000,4);

  if (lpAddress != (int *)0x0) {

    pvVar2 = VirtualAlloc(lpAddress,0x10000,0x1000,4);

    if (pvVar2 != (LPVOID)0x0) {

      if (lpMem == &PTR_LOOP_00581848) {

        if (PTR_LOOP_00581848 == (undefined *)0x0) {

          PTR_LOOP_00581848 = (undefined *)&PTR_LOOP_00581848;

        }

        if (PTR_LOOP_0058184c == (undefined *)0x0) {

          PTR_LOOP_0058184c = (undefined *)&PTR_LOOP_00581848;

        }

      }

      else {

        *lpMem = (undefined *)&PTR_LOOP_00581848;

        lpMem[1] = PTR_LOOP_0058184c;

        PTR_LOOP_0058184c = (undefined *)lpMem;

        *(undefined ***)lpMem[1] = lpMem;

      }

      lpMem[5] = (undefined *)(lpAddress + 0x100000);

      ppuVar3 = lpMem + 6;

      lpMem[3] = (undefined *)(lpMem + 0x26);

      lpMem[4] = (undefined *)lpAddress;

      lpMem[2] = (undefined *)ppuVar3;

      iVar4 = 0;

      do {

        bVar1 = 0xf < iVar4;

        iVar4 = iVar4 + 1;

        *ppuVar3 = (undefined *)((bVar1 - 1 & 0xf1) - 1);

        ppuVar3[1] = (undefined *)0xf1;

        ppuVar3 = ppuVar3 + 2;

      } while (iVar4 < 0x400);

      _memset(lpAddress,0,0x10000);

      for (; lpAddress < lpMem[4] + 0x10000; lpAddress = lpAddress + 0x400) {

        *(undefined1 *)(lpAddress + 0x3e) = 0xff;

        *lpAddress = (int)(lpAddress + 2);

        lpAddress[1] = 0xf0;

      }

      return lpMem;

    }

    VirtualFree(lpAddress,0,0x8000);

  }

  if (lpMem != &PTR_LOOP_00581848) {

    HeapFree(DAT_006579e8,0,lpMem);

  }

  return (undefined **)0x0;

}

/* ===== crt_sbh_free_heap @ 0x0054B93B ===== */
void crt_sbh_free_heap(undefined **param_1)



{

  VirtualFree(param_1[4],0,0x8000);

  if ((undefined **)PTR_LOOP_00583868 == param_1) {

    PTR_LOOP_00583868 = param_1[1];

  }

  if (param_1 != &PTR_LOOP_00581848) {

    *(undefined **)param_1[1] = *param_1;

    *(undefined **)(*param_1 + 4) = param_1[1];

    HeapFree(DAT_006579e8,0,param_1);

    return;

  }

  DAT_00581858 = 0xffffffff;

  return;

}

/* ===== crt_sbh_decommit_pages @ 0x0054B991 ===== */
void crt_sbh_decommit_pages(int param_1)



{

  BOOL BVar1;

  int *piVar2;

  int iVar3;

  undefined *puVar4;

  undefined *puVar5;

  int local_8;

  

  puVar4 = PTR_LOOP_0058184c;

  do {

    puVar5 = puVar4;

    if (*(int *)(puVar4 + 0x10) != -1) {

      local_8 = 0;

      piVar2 = (int *)(puVar4 + 0x2010);

      iVar3 = 0x3ff000;

      do {

        if (*piVar2 == 0xf0) {

          BVar1 = VirtualFree((LPVOID)(iVar3 + *(int *)(puVar4 + 0x10)),0x1000,0x4000);

          if (BVar1 != 0) {

            *piVar2 = -1;

            DAT_00630be4 = DAT_00630be4 + -1;

            if ((*(int **)(puVar4 + 0xc) == (int *)0x0) || (piVar2 < *(int **)(puVar4 + 0xc))) {

              *(int **)(puVar4 + 0xc) = piVar2;

            }

            local_8 = local_8 + 1;

            param_1 = param_1 + -1;

            if (param_1 == 0) break;

          }

        }

        iVar3 = iVar3 + -0x1000;

        piVar2 = piVar2 + -2;

      } while (-1 < iVar3);

      puVar5 = *(undefined **)(puVar4 + 4);

      if ((local_8 != 0) && (*(int *)(puVar4 + 0x18) == -1)) {

        piVar2 = (int *)(puVar4 + 0x20);

        iVar3 = 1;

        do {

          if (*piVar2 != -1) break;

          iVar3 = iVar3 + 1;

          piVar2 = piVar2 + 2;

        } while (iVar3 < 0x400);

        if (iVar3 == 0x400) {

          crt_sbh_free_heap(puVar4);

        }

      }

    }

    if ((puVar5 == PTR_LOOP_0058184c) || (puVar4 = puVar5, param_1 < 1)) {

      return;

    }

  } while( true );

}

/* ===== crt_sbh_addr_lookup @ 0x0054BA53 ===== */
int crt_sbh_addr_lookup(undefined *param_1,undefined4 *param_2,uint *param_3)



{

  undefined **ppuVar1;

  uint uVar2;

  

  ppuVar1 = &PTR_LOOP_00581848;

  while ((param_1 <= ppuVar1[4] || (ppuVar1[5] <= param_1))) {

    ppuVar1 = (undefined **)*ppuVar1;

    if (ppuVar1 == &PTR_LOOP_00581848) {

      return 0;

    }

  }

  if (((uint)param_1 & 0xf) != 0) {

    return 0;

  }

  if (((uint)param_1 & 0xfff) < 0x100) {

    return 0;

  }

  *param_2 = ppuVar1;

  uVar2 = (uint)param_1 & 0xfffff000;

  *param_3 = uVar2;

  return ((int)(param_1 + (-0x100 - uVar2)) >> 4) + 8 + uVar2;

}

/* ===== crt_sbh_decommit_page @ 0x0054BAAA ===== */
void crt_sbh_decommit_page(int param_1,int param_2,byte *param_3)



{

  int *piVar1;

  

  piVar1 = (int *)(param_1 + 0x18 + (param_2 - *(int *)(param_1 + 0x10) >> 0xc) * 8);

  *piVar1 = *piVar1 + (uint)*param_3;

  *param_3 = 0;

  piVar1[1] = 0xf1;

  if ((*piVar1 == 0xf0) && (DAT_00630be4 = DAT_00630be4 + 1, DAT_00630be4 == 0x20)) {

    crt_sbh_decommit_pages(0x10);

  }

  return;

}

/* ===== crt_heap_alloc_sbh @ 0x0054BAEF ===== */
/* WARNING: Type propagation algorithm not settling */



int * crt_heap_alloc_sbh(uint param_1)



{

  int *piVar1;

  undefined **ppuVar2;

  int iVar3;

  int *piVar4;

  int *piVar5;

  undefined *puVar6;

  undefined **ppuVar7;

  int *piVar8;

  undefined **ppuVar9;

  int local_8;

  

  piVar8 = (int *)PTR_LOOP_00583868;

  do {

    if (piVar8[4] != -1) {

      piVar5 = (int *)piVar8[2];

      iVar3 = ((int)piVar5 + (-0x18 - (int)piVar8) >> 3) * 0x1000 + piVar8[4];

      if (piVar5 < piVar8 + 0x806) {

        do {

          if (((int)param_1 <= *piVar5) && (param_1 < (uint)piVar5[1])) {

            piVar4 = (int *)crt_sbh_carve_block(iVar3,*piVar5,param_1);

            if (piVar4 != (int *)0x0) goto LAB_0054bbba;

            piVar5[1] = param_1;

          }

          piVar5 = piVar5 + 2;

          iVar3 = iVar3 + 0x1000;

        } while (piVar5 < piVar8 + 0x806);

      }

      piVar1 = (int *)piVar8[2];

      iVar3 = piVar8[4];

      for (piVar5 = piVar8 + 6; piVar5 < piVar1; piVar5 = piVar5 + 2) {

        if (((int)param_1 <= *piVar5) && (param_1 < (uint)piVar5[1])) {

          piVar4 = (int *)crt_sbh_carve_block(iVar3,*piVar5,param_1);

          if (piVar4 != (int *)0x0) {

LAB_0054bbba:

            PTR_LOOP_00583868 = (undefined *)piVar8;

            *piVar5 = *piVar5 - param_1;

            piVar8[2] = (int)piVar5;

            return piVar4;

          }

          piVar5[1] = param_1;

        }

        iVar3 = iVar3 + 0x1000;

      }

    }

    piVar8 = (int *)*piVar8;

    if (piVar8 == (int *)PTR_LOOP_00583868) {

      ppuVar9 = &PTR_LOOP_00581848;

      while ((ppuVar9[4] == (undefined *)0xffffffff || (ppuVar9[3] == (undefined *)0x0))) {

        ppuVar9 = (undefined **)*ppuVar9;

        if (ppuVar9 == &PTR_LOOP_00581848) {

          puVar6 = (undefined *)crt_sbh_alloc_heap();

          if (puVar6 == (undefined *)0x0) {

            return (int *)0x0;

          }

          piVar8 = *(int **)(puVar6 + 0x10);

          *(char *)(piVar8 + 2) = (char)param_1;

          PTR_LOOP_00583868 = puVar6;

          *piVar8 = (int)piVar8 + param_1 + 8;

          piVar8[1] = 0xf0 - param_1;

          *(uint *)(puVar6 + 0x18) = *(int *)(puVar6 + 0x18) - (param_1 & 0xff);

          return piVar8 + 0x40;

        }

      }

      ppuVar2 = (undefined **)ppuVar9[3];

      local_8 = 0;

      piVar8 = (int *)(ppuVar9[4] + ((int)ppuVar2 + (-0x18 - (int)ppuVar9) >> 3) * 0x1000);

      puVar6 = *ppuVar2;

      ppuVar7 = ppuVar2;

      for (; (puVar6 == (undefined *)0xffffffff && (local_8 < 0x10)); local_8 = local_8 + 1) {

        ppuVar7 = ppuVar7 + 2;

        puVar6 = *ppuVar7;

      }

      piVar5 = VirtualAlloc(piVar8,local_8 << 0xc,0x1000,4);

      if (piVar5 != piVar8) {

        return (int *)0x0;

      }

      _memset(piVar8,local_8 << 0xc,0);

      ppuVar7 = ppuVar2;

      if (0 < local_8) {

        piVar5 = piVar8 + 1;

        do {

          *(undefined1 *)(piVar5 + 0x3d) = 0xff;

          piVar5[-1] = (int)(piVar5 + 1);

          *piVar5 = 0xf0;

          *ppuVar7 = (undefined *)0xf0;

          ppuVar7[1] = (undefined *)0xf1;

          piVar5 = piVar5 + 0x400;

          ppuVar7 = ppuVar7 + 2;

          local_8 = local_8 + -1;

        } while (local_8 != 0);

      }

      for (; (ppuVar7 < ppuVar9 + 0x806 && (*ppuVar7 != (undefined *)0xffffffff));

          ppuVar7 = ppuVar7 + 2) {

      }

      PTR_LOOP_00583868 = (undefined *)ppuVar9;

      ppuVar9[3] = (undefined *)(-(uint)(ppuVar7 < ppuVar9 + 0x806) & (uint)ppuVar7);

      *(char *)(piVar8 + 2) = (char)param_1;

      ppuVar9[2] = (undefined *)ppuVar2;

      *ppuVar2 = *ppuVar2 + -param_1;

      piVar8[1] = piVar8[1] - param_1;

      *piVar8 = (int)piVar8 + param_1 + 8;

      return piVar8 + 0x40;

    }

  } while( true );

}

/* ===== crt_sbh_carve_block @ 0x0054BCF7 ===== */
int crt_sbh_carve_block(int *param_1,uint param_2,uint param_3)



{

  byte *pbVar1;

  byte *pbVar2;

  byte bVar3;

  byte *pbVar4;

  uint uVar5;

  byte *pbVar6;

  

  pbVar2 = (byte *)*param_1;

  pbVar1 = (byte *)(param_1 + 0x3e);

  bVar3 = (byte)param_3;

  if ((uint)param_1[1] < param_3) {

    pbVar6 = pbVar2;

    if (pbVar2[param_1[1]] != 0) {

      pbVar6 = pbVar2 + param_1[1];

    }

    while( true ) {

      while( true ) {

        if (pbVar1 <= pbVar6 + param_3) {

          pbVar6 = (byte *)(param_1 + 2);

          while( true ) {

            while( true ) {

              if (pbVar2 <= pbVar6) {

                return 0;

              }

              if (pbVar1 <= pbVar6 + param_3) {

                return 0;

              }

              if (*pbVar6 == 0) break;

              pbVar6 = pbVar6 + *pbVar6;

            }

            uVar5 = 1;

            pbVar4 = pbVar6;

            while (pbVar4 = pbVar4 + 1, *pbVar4 == 0) {

              uVar5 = uVar5 + 1;

            }

            if (param_3 <= uVar5) break;

            param_2 = param_2 - uVar5;

            pbVar6 = pbVar4;

            if (param_2 < param_3) {

              return 0;

            }

          }

          if (pbVar6 + param_3 < pbVar1) {

            *param_1 = (int)(pbVar6 + param_3);

            param_1[1] = uVar5 - param_3;

          }

          else {

            param_1[1] = 0;

            *param_1 = (int)(param_1 + 2);

          }

          *pbVar6 = bVar3;

          pbVar2 = pbVar6 + 8;

          goto LAB_0054be0a;

        }

        if (*pbVar6 == 0) break;

        pbVar6 = pbVar6 + *pbVar6;

      }

      uVar5 = 1;

      pbVar4 = pbVar6;

      while (pbVar4 = pbVar4 + 1, *pbVar4 == 0) {

        uVar5 = uVar5 + 1;

      }

      if (param_3 <= uVar5) break;

      if (pbVar6 == pbVar2) {

        param_1[1] = uVar5;

        pbVar6 = pbVar4;

      }

      else {

        param_2 = param_2 - uVar5;

        pbVar6 = pbVar4;

        if (param_2 < param_3) {

          return 0;

        }

      }

    }

    if (pbVar6 + param_3 < pbVar1) {

      *param_1 = (int)(pbVar6 + param_3);

      param_1[1] = uVar5 - param_3;

    }

    else {

      param_1[1] = 0;

      *param_1 = (int)(param_1 + 2);

    }

    *pbVar6 = bVar3;

    pbVar2 = pbVar6 + 8;

  }

  else {

    *pbVar2 = bVar3;

    if (pbVar2 + param_3 < pbVar1) {

      *param_1 = *param_1 + param_3;

      param_1[1] = param_1[1] - param_3;

    }

    else {

      param_1[1] = 0;

      *param_1 = (int)(param_1 + 2);

    }

    pbVar2 = pbVar2 + 8;

  }

LAB_0054be0a:

  return (int)pbVar2 * 0x10 + (int)param_1 * -0xf;

}

/* ===== crt_sbh_adjust_block @ 0x0054BE1B ===== */
undefined4 crt_sbh_adjust_block(int param_1,int *param_2,byte *param_3,uint param_4)



{

  byte *pbVar1;

  int *piVar2;

  byte bVar3;

  byte *pbVar4;

  int iVar5;

  uint uVar6;

  

  uVar6 = (uint)*param_3;

  piVar2 = (int *)(param_1 + 0x18 + ((int)param_2 - *(int *)(param_1 + 0x10) >> 0xc) * 8);

  if (param_4 < uVar6) {

    *param_3 = (byte)param_4;

    *piVar2 = *piVar2 + (uVar6 - param_4);

    piVar2[1] = 0xf1;

  }

  else {

    if (param_4 <= uVar6) {

      return 0;

    }

    pbVar1 = param_3 + param_4;

    if (param_2 + 0x3e < pbVar1) {

      return 0;

    }

    for (pbVar4 = param_3 + uVar6; (pbVar4 < pbVar1 && (*pbVar4 == 0)); pbVar4 = pbVar4 + 1) {

    }

    if (pbVar4 != pbVar1) {

      return 0;

    }

    *param_3 = (byte)param_4;

    if ((param_3 <= (byte *)*param_2) && ((byte *)*param_2 < pbVar1)) {

      if (pbVar1 < param_2 + 0x3e) {

        iVar5 = 0;

        *param_2 = (int)pbVar1;

        bVar3 = *pbVar1;

        while (bVar3 == 0) {

          iVar5 = iVar5 + 1;

          bVar3 = pbVar1[iVar5];

        }

        param_2[1] = iVar5;

      }

      else {

        param_2[1] = 0;

        *param_2 = (int)(param_2 + 2);

      }

    }

    *piVar2 = *piVar2 + (uVar6 - param_4);

  }

  return 1;

}

/* ===== crt_critical_sections_init @ 0x0054BEC4 ===== */
/* PS2 candidate: ANM_Uninit__Fv (conf 0.77) */



void crt_critical_sections_init(void)



{

  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_005838b4);

  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_005838a4);

  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_00583894);

  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_00583874);

  return;

}

/* ===== _lock @ 0x0054BEED ===== */
void _lock(int param_1)



{

  int *piVar1;

  LPCRITICAL_SECTION lpCriticalSection;

  

  piVar1 = (int *)(&DAT_00583870 + param_1 * 4);

  if (*(int *)(&DAT_00583870 + param_1 * 4) == 0) {

    lpCriticalSection = _malloc(0x18);

    if (lpCriticalSection == (LPCRITICAL_SECTION)0x0) {

      __amsg_exit(0x11);

    }

    _lock(0x11);

    if (*piVar1 == 0) {

      InitializeCriticalSection(lpCriticalSection);

      *piVar1 = (int)lpCriticalSection;

    }

    else {

      crt_free_ext();

    }

    _unlock(0x11);

  }

  EnterCriticalSection((LPCRITICAL_SECTION)*piVar1);

  return;

}

/* ===== _unlock @ 0x0054BF4E ===== */
void _unlock(int param_1)



{

  LeaveCriticalSection(*(LPCRITICAL_SECTION *)(&DAT_00583870 + param_1 * 4));

  return;

}

/* ===== crt_lcmapstring @ 0x0054BF63 ===== */
int crt_lcmapstring(LCID param_1,uint param_2,LPCSTR param_3,int param_4,LPWSTR param_5,int param_6,

                   UINT param_7,int param_8)



{

  int iVar1;

  int iVar2;

  void *local_14;

  undefined1 *puStack_10;

  undefined *puStack_c;

  undefined4 local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &DAT_005525e8;

  puStack_10 = &LAB_00544c84;

  local_14 = ExceptionList;

  ExceptionList = &local_14;

  if (DAT_00630c74 == 0) {

    ExceptionList = &local_14;

    iVar1 = LCMapStringW(0,0x100,L"",1,(LPWSTR)0x0,0);

    if (iVar1 == 0) {

      iVar1 = LCMapStringA(0,0x100,"",1,(LPSTR)0x0,0);

      if (iVar1 == 0) {

        ExceptionList = local_14;

        return 0;

      }

      DAT_00630c74 = 2;

    }

    else {

      DAT_00630c74 = 1;

    }

  }

  if (0 < param_4) {

    param_4 = crt_strnlen(param_3,param_4);

  }

  if (DAT_00630c74 == 2) {

    iVar1 = LCMapStringA(param_1,param_2,param_3,param_4,(LPSTR)param_5,param_6);

    ExceptionList = local_14;

    return iVar1;

  }

  if (DAT_00630c74 == 1) {

    if (param_7 == 0) {

      param_7 = DAT_00630c6c;

    }

    iVar1 = MultiByteToWideChar(param_7,(-(uint)(param_8 != 0) & 8) + 1,param_3,param_4,(LPWSTR)0x0,

                                0);

    if (iVar1 != 0) {

      local_8 = 0;

      FUN_00543e00();

      local_8 = 0xffffffff;

      if ((&stack0x00000000 != (undefined1 *)0x3c) &&

         (iVar2 = MultiByteToWideChar(param_7,1,param_3,param_4,(LPWSTR)&stack0xffffffc4,iVar1),

         iVar2 != 0)) {

        iVar2 = LCMapStringW(param_1,param_2,(LPCWSTR)&stack0xffffffc4,iVar1,(LPWSTR)0x0,0);

        if (iVar2 != 0) {

          if ((param_2 & 0x400) == 0) {

            local_8 = 1;

            FUN_00543e00();

            local_8 = 0xffffffff;

            if (&stack0x00000000 == (undefined1 *)0x3c) {

              ExceptionList = local_14;

              return 0;

            }

            iVar1 = LCMapStringW(param_1,param_2,(LPCWSTR)&stack0xffffffc4,iVar1,

                                 (LPWSTR)&stack0xffffffc4,iVar2);

            if (iVar1 == 0) {

              ExceptionList = local_14;

              return 0;

            }

            if (param_6 == 0) {

              param_6 = 0;

              param_5 = (LPWSTR)0x0;

            }

            iVar2 = WideCharToMultiByte(param_7,0x220,(LPCWSTR)&stack0xffffffc4,iVar2,(LPSTR)param_5

                                        ,param_6,(LPCSTR)0x0,(LPBOOL)0x0);

            iVar1 = iVar2;

          }

          else {

            if (param_6 == 0) {

              ExceptionList = local_14;

              return iVar2;

            }

            if (param_6 < iVar2) {

              ExceptionList = local_14;

              return 0;

            }

            iVar1 = LCMapStringW(param_1,param_2,(LPCWSTR)&stack0xffffffc4,iVar1,param_5,param_6);

          }

          if (iVar1 != 0) {

            ExceptionList = local_14;

            return iVar2;

          }

        }

      }

    }

  }

  ExceptionList = local_14;

  return 0;

}

/* ===== crt_strnlen @ 0x0054C187 ===== */
int crt_strnlen(char *param_1,int param_2)



{

  char *pcVar1;

  int iVar2;

  

  iVar2 = param_2;

  for (pcVar1 = param_1; (iVar2 != 0 && (iVar2 = iVar2 + -1, *pcVar1 != '\0')); pcVar1 = pcVar1 + 1)

  {

  }

  if (*pcVar1 != '\0') {

    return param_2;

  }

  return (int)pcVar1 - (int)param_1;

}

/* ===== __loctotime_t @ 0x0054C1B2 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



int __loctotime_t(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,

                 int param_7)



{

  int iVar1;

  uint uVar2;

  undefined1 local_28 [8];

  int local_20;

  int local_18;

  uint local_14;

  int local_c;

  

  uVar2 = param_1 - 0x76c;

  if (((int)uVar2 < 0x46) || (0x8a < (int)uVar2)) {

    param_6 = -1;

  }

  else {

    param_3 = *(int *)(&DAT_00583ca4 + param_2 * 4) + param_3;

    if (((uVar2 & 3) == 0) && (2 < param_2)) {

      param_3 = param_3 + 1;

    }

    crt_lock_54e41a();

    local_20 = param_4;

    local_18 = param_2 + -1;

    param_6 = ((param_4 + (uVar2 * 0x16d + param_3 + (param_1 + -0x76d >> 2)) * 0x18) * 0x3c +

              param_5) * 0x3c + DAT_00583bc0 + 0x7c558180 + param_6;

    if ((param_7 == 1) ||

       (((param_7 == -1 && (DAT_00583bc4 != 0)) &&

        (local_14 = uVar2, local_c = param_3, iVar1 = crt_lock_54e6cf(local_28), iVar1 != 0)))) {

      param_6 = param_6 + _DAT_00583bc8;

    }

  }

  return param_6;

}

/* ===== __aulldiv @ 0x0054C280 ===== */
/* Library Function - Single Match

    __aulldiv

   

   Library: Visual Studio */



undefined8 __aulldiv(uint param_1,uint param_2,uint param_3,uint param_4)



{

  ulonglong uVar1;

  longlong lVar2;

  uint uVar3;

  int iVar4;

  uint uVar5;

  uint uVar6;

  uint uVar7;

  uint uVar8;

  uint uVar9;

  

  uVar3 = param_1;

  uVar8 = param_4;

  uVar6 = param_2;

  uVar9 = param_3;

  if (param_4 == 0) {

    uVar3 = param_2 / param_3;

    iVar4 = (int)(((ulonglong)param_2 % (ulonglong)param_3 << 0x20 | (ulonglong)param_1) /

                 (ulonglong)param_3);

  }

  else {

    do {

      uVar5 = uVar8 >> 1;

      uVar9 = uVar9 >> 1 | (uint)((uVar8 & 1) != 0) << 0x1f;

      uVar7 = uVar6 >> 1;

      uVar3 = uVar3 >> 1 | (uint)((uVar6 & 1) != 0) << 0x1f;

      uVar8 = uVar5;

      uVar6 = uVar7;

    } while (uVar5 != 0);

    uVar1 = CONCAT44(uVar7,uVar3) / (ulonglong)uVar9;

    iVar4 = (int)uVar1;

    lVar2 = (ulonglong)param_3 * (uVar1 & 0xffffffff);

    uVar3 = (uint)((ulonglong)lVar2 >> 0x20);

    uVar8 = uVar3 + iVar4 * param_4;

    if (((CARRY4(uVar3,iVar4 * param_4)) || (param_2 < uVar8)) ||

       ((param_2 <= uVar8 && (param_1 < (uint)lVar2)))) {

      iVar4 = iVar4 + -1;

    }

    uVar3 = 0;

  }

  return CONCAT44(uVar3,iVar4);

}

/* ===== __aullrem @ 0x0054C2F0 ===== */
/* Library Function - Single Match

    __aullrem

   

   Library: Visual Studio */



undefined8 __aullrem(uint param_1,uint param_2,uint param_3,uint param_4)



{

  ulonglong uVar1;

  longlong lVar2;

  uint uVar3;

  uint uVar4;

  uint uVar5;

  int iVar6;

  int iVar7;

  uint uVar8;

  uint uVar9;

  uint uVar10;

  bool bVar11;

  

  uVar3 = param_1;

  uVar4 = param_4;

  uVar9 = param_2;

  uVar10 = param_3;

  if (param_4 == 0) {

    iVar6 = (int)(((ulonglong)param_2 % (ulonglong)param_3 << 0x20 | (ulonglong)param_1) %

                 (ulonglong)param_3);

    iVar7 = 0;

  }

  else {

    do {

      uVar5 = uVar4 >> 1;

      uVar10 = uVar10 >> 1 | (uint)((uVar4 & 1) != 0) << 0x1f;

      uVar8 = uVar9 >> 1;

      uVar3 = uVar3 >> 1 | (uint)((uVar9 & 1) != 0) << 0x1f;

      uVar4 = uVar5;

      uVar9 = uVar8;

    } while (uVar5 != 0);

    uVar1 = CONCAT44(uVar8,uVar3) / (ulonglong)uVar10;

    uVar3 = (int)uVar1 * param_4;

    lVar2 = (uVar1 & 0xffffffff) * (ulonglong)param_3;

    uVar9 = (uint)((ulonglong)lVar2 >> 0x20);

    uVar4 = (uint)lVar2;

    uVar10 = uVar9 + uVar3;

    if (((CARRY4(uVar9,uVar3)) || (param_2 < uVar10)) || ((param_2 <= uVar10 && (param_1 < uVar4))))

    {

      bVar11 = uVar4 < param_3;

      uVar4 = uVar4 - param_3;

      uVar10 = (uVar10 - param_4) - (uint)bVar11;

    }

    iVar6 = -(uVar4 - param_1);

    iVar7 = -(uint)(uVar4 - param_1 != 0) - ((uVar10 - param_2) - (uint)(uVar4 < param_1));

  }

  return CONCAT44(iVar7,iVar6);

}

/* ===== _malloc @ 0x0054C365 ===== */
LPVOID _malloc(int param_1,int param_2)



{

  int iVar1;

  uint uVar2;

  uint uVar3;

  uint _Size;

  LPVOID local_24;

  void *local_14;

  undefined1 *puStack_10;

  undefined *puStack_c;

  undefined4 local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &DAT_00552600;

  puStack_10 = &LAB_00544c84;

  local_14 = ExceptionList;

  uVar2 = param_1 * param_2;

  uVar3 = uVar2;

  ExceptionList = &local_14;

  if (uVar2 < 0xffffffe1) {

    if (uVar2 == 0) {

      uVar3 = 1;

    }

    uVar3 = uVar3 + 0xf & 0xfffffff0;

    ExceptionList = &local_14;

  }

  do {

    local_24 = (LPVOID)0x0;

    if (uVar3 < 0xffffffe1) {

      if (DAT_006579ec == 3) {

        if (uVar2 <= DAT_006579e4) {

          _lock(9);

          local_8 = 0;

          local_24 = (LPVOID)__sbh_alloc_block(uVar2);

          local_8 = 0xffffffff;

          FUN_0054C3FE();

          _Size = uVar2;

          if (local_24 == (void *)0x0) goto LAB_0054c452;

LAB_0054c441:

          _memset(local_24,0,_Size);

        }

LAB_0054c44d:

        if (local_24 != (LPVOID)0x0) {

          ExceptionList = local_14;

          return local_24;

        }

      }

      else {

        if ((DAT_006579ec != 2) || (DAT_0058386c < uVar3)) goto LAB_0054c44d;

        _lock(9);

        local_8 = 1;

        local_24 = (LPVOID)crt_heap_alloc_sbh(uVar3 >> 4);

        local_8 = 0xffffffff;

        FUN_0054C487();

        _Size = uVar3;

        if (local_24 != (void *)0x0) goto LAB_0054c441;

      }

LAB_0054c452:

      local_24 = HeapAlloc(DAT_006579e8,8,uVar3);

    }

    if (local_24 != (LPVOID)0x0) {

      ExceptionList = local_14;

      return local_24;

    }

    if (DAT_00630bdc == 0) {

      ExceptionList = local_14;

      return (LPVOID)0x0;

    }

    iVar1 = FUN_0054aac3(uVar3);

    if (iVar1 == 0) {

      ExceptionList = local_14;

      return (LPVOID)0x0;

    }

  } while( true );

}

/* ===== FUN_0054C3FE @ 0x0054C3FE ===== */
void FUN_0054C3FE(void)



{

  _unlock(9);

  return;

}

/* ===== FUN_0054C487 @ 0x0054C487 ===== */
void FUN_0054C487(void)



{

  _unlock(9);

  return;

}

/* ===== __initptd @ 0x0054C4A2 ===== */
LONG __initptd(undefined4 param_1,_EXCEPTION_POINTERS *param_2)



{

  code *pcVar1;

  undefined4 uVar2;

  undefined4 uVar3;

  int iVar4;

  int *piVar5;

  LONG LVar6;

  int iVar7;

  int iVar8;

  

  iVar4 = __getptd();

  piVar5 = (int *)FUN_0054c5e0(param_1,*(undefined4 *)(iVar4 + 0x50));

  if ((piVar5 == (int *)0x0) || (pcVar1 = (code *)piVar5[2], pcVar1 == (code *)0x0)) {

    LVar6 = UnhandledExceptionFilter(param_2);

  }

  else if (pcVar1 == (code *)0x5) {

    piVar5[2] = 0;

    LVar6 = 1;

  }

  else {

    if (pcVar1 != (code *)0x1) {

      uVar2 = *(undefined4 *)(iVar4 + 0x54);

      *(_EXCEPTION_POINTERS **)(iVar4 + 0x54) = param_2;

      if (piVar5[1] == 8) {

        if (DAT_00583ab8 < DAT_00583abc + DAT_00583ab8) {

          iVar7 = DAT_00583ab8 * 0xc;

          iVar8 = DAT_00583ab8;

          do {

            *(undefined4 *)(iVar7 + 8 + *(int *)(iVar4 + 0x50)) = 0;

            iVar8 = iVar8 + 1;

            iVar7 = iVar7 + 0xc;

          } while (iVar8 < DAT_00583abc + DAT_00583ab8);

        }

        iVar7 = *piVar5;

        uVar3 = *(undefined4 *)(iVar4 + 0x58);

        if (iVar7 == -0x3fffff72) {

          *(undefined4 *)(iVar4 + 0x58) = 0x83;

        }

        else if (iVar7 == -0x3fffff70) {

          *(undefined4 *)(iVar4 + 0x58) = 0x81;

        }

        else if (iVar7 == -0x3fffff6f) {

          *(undefined4 *)(iVar4 + 0x58) = 0x84;

        }

        else if (iVar7 == -0x3fffff6d) {

          *(undefined4 *)(iVar4 + 0x58) = 0x85;

        }

        else if (iVar7 == -0x3fffff73) {

          *(undefined4 *)(iVar4 + 0x58) = 0x82;

        }

        else if (iVar7 == -0x3fffff71) {

          *(undefined4 *)(iVar4 + 0x58) = 0x86;

        }

        else if (iVar7 == -0x3fffff6e) {

          *(undefined4 *)(iVar4 + 0x58) = 0x8a;

        }

        (*pcVar1)(8,*(undefined4 *)(iVar4 + 0x58));

        *(undefined4 *)(iVar4 + 0x58) = uVar3;

      }

      else {

        piVar5[2] = 0;

        (*pcVar1)(piVar5[1]);

      }

      *(undefined4 *)(iVar4 + 0x54) = uVar2;

    }

    LVar6 = -1;

  }

  return LVar6;

}

/* ===== FUN_0054c5e0 @ 0x0054C5E0 ===== */
int * FUN_0054c5e0(int param_1,int *param_2)



{

  int *piVar1;

  

  piVar1 = param_2;

  if (*param_2 != param_1) {

    do {

      piVar1 = piVar1 + 3;

      if (param_2 + DAT_00583ac4 * 3 <= piVar1) break;

    } while (*piVar1 != param_1);

  }

  if ((param_2 + DAT_00583ac4 * 3 <= piVar1) || (*piVar1 != param_1)) {

    piVar1 = (int *)0x0;

  }

  return piVar1;

}

/* ===== crt_io_init @ 0x0054C61A ===== */
void crt_io_init(void)



{

  undefined4 *puVar1;

  undefined4 *puVar2;

  undefined4 *puVar3;

  DWORD DVar4;

  HANDLE hFile;

  UINT *pUVar5;

  int iVar6;

  uint uVar7;

  UINT UVar8;

  UINT UVar9;

  _STARTUPINFOA local_4c;

  byte *local_8;

  

  puVar2 = _malloc(0x480);

  if (puVar2 == (undefined4 *)0x0) {

    __amsg_exit(0x1b);

  }

  DAT_006579c0 = 0x20;

  DAT_006578c0 = puVar2;

  for (; puVar2 < DAT_006578c0 + 0x120; puVar2 = puVar2 + 9) {

    *(undefined1 *)(puVar2 + 1) = 0;

    *puVar2 = 0xffffffff;

    puVar2[2] = 0;

    *(undefined1 *)((int)puVar2 + 5) = 10;

  }

  GetStartupInfoA(&local_4c);

  if ((local_4c.cbReserved2 != 0) && ((UINT *)local_4c.lpReserved2 != (UINT *)0x0)) {

    UVar8 = *(UINT *)local_4c.lpReserved2;

    pUVar5 = (UINT *)((int)local_4c.lpReserved2 + 4);

    local_8 = (byte *)((int)pUVar5 + UVar8);

    if (0x7ff < (int)UVar8) {

      UVar8 = 0x800;

    }

    UVar9 = UVar8;

    if ((int)DAT_006579c0 < (int)UVar8) {

      puVar2 = &DAT_006578c4;

      do {

        puVar3 = _malloc(0x480);

        UVar9 = DAT_006579c0;

        if (puVar3 == (undefined4 *)0x0) break;

        DAT_006579c0 = DAT_006579c0 + 0x20;

        *puVar2 = puVar3;

        puVar1 = puVar3;

        for (; puVar3 < puVar1 + 0x120; puVar3 = puVar3 + 9) {

          *(undefined1 *)(puVar3 + 1) = 0;

          *puVar3 = 0xffffffff;

          puVar3[2] = 0;

          *(undefined1 *)((int)puVar3 + 5) = 10;

          puVar1 = (undefined4 *)*puVar2;

        }

        puVar2 = puVar2 + 1;

        UVar9 = UVar8;

      } while ((int)DAT_006579c0 < (int)UVar8);

    }

    uVar7 = 0;

    if (0 < (int)UVar9) {

      do {

        if (((*(HANDLE *)local_8 != (HANDLE)0xffffffff) && ((*pUVar5 & 1) != 0)) &&

           (((*pUVar5 & 8) != 0 || (DVar4 = GetFileType(*(HANDLE *)local_8), DVar4 != 0)))) {

          puVar2 = (undefined4 *)((int)(&DAT_006578c0)[(int)uVar7 >> 5] + (uVar7 & 0x1f) * 0x24);

          *puVar2 = *(undefined4 *)local_8;

          *(byte *)(puVar2 + 1) = (byte)*pUVar5;

        }

        local_8 = local_8 + 4;

        uVar7 = uVar7 + 1;

        pUVar5 = (UINT *)((int)pUVar5 + 1);

      } while ((int)uVar7 < (int)UVar9);

    }

  }

  iVar6 = 0;

  do {

    puVar2 = DAT_006578c0 + iVar6 * 9;

    if (DAT_006578c0[iVar6 * 9] == -1) {

      *(undefined1 *)(puVar2 + 1) = 0x81;

      if (iVar6 == 0) {

        DVar4 = 0xfffffff6;

      }

      else {

        DVar4 = 0xfffffff5 - (iVar6 != 1);

      }

      hFile = GetStdHandle(DVar4);

      if ((hFile != (HANDLE)0xffffffff) && (DVar4 = GetFileType(hFile), DVar4 != 0)) {

        *puVar2 = hFile;

        if ((DVar4 & 0xff) != 2) {

          if ((DVar4 & 0xff) == 3) {

            *(byte *)(puVar2 + 1) = *(byte *)(puVar2 + 1) | 8;

          }

          goto LAB_0054c7bf;

        }

      }

      *(byte *)(puVar2 + 1) = *(byte *)(puVar2 + 1) | 0x40;

    }

    else {

      *(byte *)(puVar2 + 1) = *(byte *)(puVar2 + 1) | 0x80;

    }

LAB_0054c7bf:

    iVar6 = iVar6 + 1;

    if (2 < iVar6) {

      SetHandleCount(DAT_006579c0);

      return;

    }

  } while( true );

}

/* ===== bin_file_create_54 @ 0x0054C857 ===== */
byte * bin_file_create_54(void)



{

  byte bVar1;

  int iVar2;

  byte *pbVar3;

  byte *pbVar4;

  

  if (DAT_00658a08 == 0) {

    FUN_0054edf6();

  }

  bVar1 = *DAT_006579f0;

  pbVar4 = DAT_006579f0;

  if (bVar1 == 0x22) {

    while( true ) {

      pbVar3 = pbVar4;

      bVar1 = pbVar3[1];

      pbVar4 = pbVar3 + 1;

      if ((bVar1 == 0x22) || (bVar1 == 0)) break;

      iVar2 = BinFileCreateWrite_5(bVar1);

      if (iVar2 != 0) {

        pbVar4 = pbVar3 + 2;

      }

    }

    if (*pbVar4 == 0x22) goto LAB_0054c894;

  }

  else {

    while (0x20 < bVar1) {

      bVar1 = pbVar4[1];

      pbVar4 = pbVar4 + 1;

    }

  }

  for (; (*pbVar4 != 0 && (*pbVar4 < 0x21)); pbVar4 = pbVar4 + 1) {

LAB_0054c894:

  }

  return pbVar4;

}

/* ===== bin_file_copy_str @ 0x0054C8AF ===== */
void bin_file_copy_str(void)



{

  char cVar1;

  size_t sVar2;

  undefined4 *puVar3;

  void *pvVar4;

  int iVar5;

  char *pcVar6;

  

  if (DAT_00658a08 == 0) {

    FUN_0054edf6();

  }

  iVar5 = 0;

  for (pcVar6 = DAT_00630ba4; *pcVar6 != '\0'; pcVar6 = pcVar6 + sVar2 + 1) {

    if (*pcVar6 != '=') {

      iVar5 = iVar5 + 1;

    }

    sVar2 = _strlen(pcVar6);

  }

  puVar3 = _malloc(iVar5 * 4 + 4);

  DAT_00630b7c = puVar3;

  if (puVar3 == (undefined4 *)0x0) {

    __amsg_exit(9);

  }

  cVar1 = *DAT_00630ba4;

  pcVar6 = DAT_00630ba4;

  while (cVar1 != '\0') {

    sVar2 = _strlen(pcVar6);

    if (*pcVar6 != '=') {

      pvVar4 = _malloc(sVar2 + 1);

      *puVar3 = pvVar4;

      if (pvVar4 == (void *)0x0) {

        __amsg_exit(9);

      }

      strcpy(*puVar3,pcVar6);

      puVar3 = puVar3 + 1;

    }

    pcVar6 = pcVar6 + sVar2 + 1;

    cVar1 = *pcVar6;

  }

  crt_free_ext(DAT_00630ba4);

  DAT_00630ba4 = (char *)0x0;

  *puVar3 = 0;

  DAT_00658a04 = 1;

  return;

}

/* ===== FUN_0054c968 @ 0x0054C968 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_0054c968(void)



{

  void *pvVar1;

  char *pcVar2;

  int local_c;

  int local_8;

  

  if (DAT_00658a08 == 0) {

    FUN_0054edf6();

  }

  GetModuleFileNameA((HMODULE)0x0,&DAT_00630c78,0x104);

  _DAT_00630b8c = &DAT_00630c78;

  pcVar2 = &DAT_00630c78;

  if (*DAT_006579f0 != '\0') {

    pcVar2 = DAT_006579f0;

  }

  crt_env_parse(pcVar2,0,0,&local_8,&local_c);

  pvVar1 = _malloc(local_c + local_8 * 4);

  if (pvVar1 == (void *)0x0) {

    __amsg_exit(8);

  }

  crt_env_parse(pcVar2,pvVar1,(void *)((int)pvVar1 + local_8 * 4),&local_8,&local_c);

  _DAT_00630b74 = pvVar1;

  _DAT_00630b70 = local_8 + -1;

  return;

}

/* ===== crt_env_parse @ 0x0054CA01 ===== */
void crt_env_parse(byte *param_1,undefined4 *param_2,byte *param_3,int *param_4,int *param_5)



{

  byte bVar1;

  bool bVar2;

  bool bVar3;

  byte *pbVar4;

  byte *pbVar5;

  uint uVar6;

  undefined4 *puVar7;

  

  *param_5 = 0;

  *param_4 = 1;

  if (param_2 != (undefined4 *)0x0) {

    *param_2 = param_3;

    param_2 = param_2 + 1;

  }

  if (*param_1 == 0x22) {

    while( true ) {

      bVar1 = param_1[1];

      pbVar4 = param_1 + 1;

      if ((bVar1 == 0x22) || (bVar1 == 0)) break;

      if (((*(byte *)((int)&DAT_006577a0 + bVar1 + 1) & 4) != 0) &&

         (*param_5 = *param_5 + 1, param_3 != (byte *)0x0)) {

        *param_3 = *pbVar4;

        param_3 = param_3 + 1;

        pbVar4 = param_1 + 2;

      }

      *param_5 = *param_5 + 1;

      param_1 = pbVar4;

      if (param_3 != (byte *)0x0) {

        *param_3 = *pbVar4;

        param_3 = param_3 + 1;

      }

    }

    *param_5 = *param_5 + 1;

    if (param_3 != (byte *)0x0) {

      *param_3 = 0;

      param_3 = param_3 + 1;

    }

    if (*pbVar4 == 0x22) {

      pbVar4 = param_1 + 2;

    }

  }

  else {

    do {

      *param_5 = *param_5 + 1;

      if (param_3 != (byte *)0x0) {

        *param_3 = *param_1;

        param_3 = param_3 + 1;

      }

      bVar1 = *param_1;

      pbVar4 = param_1 + 1;

      if ((*(byte *)((int)&DAT_006577a0 + bVar1 + 1) & 4) != 0) {

        *param_5 = *param_5 + 1;

        if (param_3 != (byte *)0x0) {

          *param_3 = *pbVar4;

          param_3 = param_3 + 1;

        }

        pbVar4 = param_1 + 2;

      }

      if (bVar1 == 0x20) break;

      if (bVar1 == 0) goto LAB_0054caac;

      param_1 = pbVar4;

    } while (bVar1 != 9);

    if (bVar1 == 0) {

LAB_0054caac:

      pbVar4 = pbVar4 + -1;

    }

    else if (param_3 != (byte *)0x0) {

      param_3[-1] = 0;

    }

  }

  bVar2 = false;

  puVar7 = param_2;

  while (*pbVar4 != 0) {

    for (; (*pbVar4 == 0x20 || (*pbVar4 == 9)); pbVar4 = pbVar4 + 1) {

    }

    if (*pbVar4 == 0) break;

    if (puVar7 != (undefined4 *)0x0) {

      *puVar7 = param_3;

      puVar7 = puVar7 + 1;

      param_2 = puVar7;

    }

    *param_4 = *param_4 + 1;

    while( true ) {

      bVar3 = true;

      uVar6 = 0;

      for (; *pbVar4 == 0x5c; pbVar4 = pbVar4 + 1) {

        uVar6 = uVar6 + 1;

      }

      if (*pbVar4 == 0x22) {

        pbVar5 = pbVar4;

        if ((uVar6 & 1) == 0) {

          if ((!bVar2) || (pbVar5 = pbVar4 + 1, pbVar4[1] != 0x22)) {

            bVar3 = false;

            pbVar5 = pbVar4;

          }

          bVar2 = !bVar2;

          puVar7 = param_2;

        }

        uVar6 = uVar6 >> 1;

        pbVar4 = pbVar5;

      }

      for (; uVar6 != 0; uVar6 = uVar6 - 1) {

        if (param_3 != (byte *)0x0) {

          *param_3 = 0x5c;

          param_3 = param_3 + 1;

        }

        *param_5 = *param_5 + 1;

      }

      bVar1 = *pbVar4;

      if ((bVar1 == 0) || ((!bVar2 && ((bVar1 == 0x20 || (bVar1 == 9)))))) break;

      if (bVar3) {

        if (param_3 == (byte *)0x0) {

          if ((*(byte *)((int)&DAT_006577a0 + bVar1 + 1) & 4) != 0) {

            pbVar4 = pbVar4 + 1;

            *param_5 = *param_5 + 1;

          }

        }

        else {

          if ((*(byte *)((int)&DAT_006577a0 + bVar1 + 1) & 4) != 0) {

            *param_3 = bVar1;

            param_3 = param_3 + 1;

            pbVar4 = pbVar4 + 1;

            *param_5 = *param_5 + 1;

          }

          *param_3 = *pbVar4;

          param_3 = param_3 + 1;

        }

        *param_5 = *param_5 + 1;

      }

      pbVar4 = pbVar4 + 1;

    }

    if (param_3 != (byte *)0x0) {

      *param_3 = 0;

      param_3 = param_3 + 1;

    }

    *param_5 = *param_5 + 1;

  }

  if (puVar7 != (undefined4 *)0x0) {

    *puVar7 = 0;

  }

  *param_4 = *param_4 + 1;

  return;

}

/* ===== bin_file_memmove @ 0x0054CBB5 ===== */
LPSTR bin_file_memmove(void)



{

  char cVar1;

  WCHAR WVar2;

  WCHAR *pWVar3;

  WCHAR *pWVar4;

  int iVar5;

  size_t _Size;

  LPSTR pCVar6;

  char *pcVar7;

  LPWCH lpWideCharStr;

  LPCH pCVar9;

  LPSTR local_8;

  char *pcVar8;

  

  lpWideCharStr = (LPWCH)0x0;

  pCVar9 = (LPCH)0x0;

  if (DAT_00630d7c == 0) {

    lpWideCharStr = GetEnvironmentStringsW();

    if (lpWideCharStr != (LPWCH)0x0) {

      DAT_00630d7c = 1;

LAB_0054cc0c:

      if ((lpWideCharStr == (LPWCH)0x0) &&

         (lpWideCharStr = GetEnvironmentStringsW(), lpWideCharStr == (LPWCH)0x0)) {

        return (LPSTR)0x0;

      }

      WVar2 = *lpWideCharStr;

      pWVar4 = lpWideCharStr;

      while (WVar2 != L'\0') {

        do {

          pWVar3 = pWVar4;

          pWVar4 = pWVar3 + 1;

        } while (*pWVar4 != L'\0');

        pWVar4 = pWVar3 + 2;

        WVar2 = *pWVar4;

      }

      iVar5 = ((int)pWVar4 - (int)lpWideCharStr >> 1) + 1;

      _Size = WideCharToMultiByte(0,0,lpWideCharStr,iVar5,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0);

      local_8 = (LPSTR)0x0;

      if (((_Size != 0) && (pCVar6 = _malloc(_Size), pCVar6 != (LPSTR)0x0)) &&

         (iVar5 = WideCharToMultiByte(0,0,lpWideCharStr,iVar5,pCVar6,_Size,(LPCSTR)0x0,(LPBOOL)0x0),

         local_8 = pCVar6, iVar5 == 0)) {

        crt_free_ext(pCVar6);

        local_8 = (LPSTR)0x0;

      }

      FreeEnvironmentStringsW(lpWideCharStr);

      return local_8;

    }

    pCVar9 = GetEnvironmentStrings();

    if (pCVar9 == (LPCH)0x0) {

      return (LPSTR)0x0;

    }

    DAT_00630d7c = 2;

  }

  else {

    if (DAT_00630d7c == 1) goto LAB_0054cc0c;

    if (DAT_00630d7c != 2) {

      return (LPSTR)0x0;

    }

  }

  if ((pCVar9 == (LPCH)0x0) && (pCVar9 = GetEnvironmentStrings(), pCVar9 == (LPCH)0x0)) {

    return (LPSTR)0x0;

  }

  cVar1 = *pCVar9;

  pcVar7 = pCVar9;

  while (cVar1 != '\0') {

    do {

      pcVar8 = pcVar7;

      pcVar7 = pcVar8 + 1;

    } while (*pcVar7 != '\0');

    pcVar7 = pcVar8 + 2;

    cVar1 = *pcVar7;

  }

  pCVar6 = _malloc((size_t)(pcVar7 + (1 - (int)pCVar9)));

  if (pCVar6 == (LPSTR)0x0) {

    pCVar6 = (LPSTR)0x0;

  }

  else {

    memmove(pCVar6,pCVar9,pcVar7 + (1 - (int)pCVar9));

  }

  FreeEnvironmentStringsA(pCVar9);

  return pCVar6;

}

/* ===== FUN_0054cce7 @ 0x0054CCE7 ===== */
void FUN_0054cce7(void)



{

  if ((DAT_00630bac == 1) || ((DAT_00630bac == 0 && (DAT_00581384 == 1)))) {

    __rt_error_box_2(0xfc);

    if (DAT_00630d80 != (code *)0x0) {

      (*DAT_00630d80)();

    }

    __rt_error_box_2(0xff);

  }

  return;

}

/* ===== __rt_error_box_2 @ 0x0054CD20 ===== */
void __rt_error_box_2(DWORD param_1)



{

  undefined4 *puVar1;

  DWORD *pDVar2;

  DWORD DVar3;

  size_t sVar4;

  HANDLE hFile;

  int iVar5;

  char acStackY_1e3 [7];

  undefined1 *puStackY_1dc;

  char *pcStackY_1d8;

  undefined4 uStackY_1d4;

  undefined1 *puStackY_1d0;

  undefined4 uStackY_1cc;

  undefined1 *puStackY_1c8;

  undefined *puStackY_1c4;

  LPCVOID lpBuffer;

  LPDWORD lpNumberOfBytesWritten;

  LPOVERLAPPED lpOverlapped;

  CHAR local_1a8 [260];

  undefined1 local_a4 [160];

  

  iVar5 = 0;

  pDVar2 = &DAT_00583af0;

  do {

    if (param_1 == *pDVar2) break;

    pDVar2 = pDVar2 + 2;

    iVar5 = iVar5 + 1;

  } while (pDVar2 < &DAT_00583b80);

  if (param_1 == (&DAT_00583af0)[iVar5 * 2]) {

    if ((DAT_00630bac == 1) || ((DAT_00630bac == 0 && (DAT_00581384 == 1)))) {

      lpNumberOfBytesWritten = &param_1;

      puVar1 = (undefined4 *)(iVar5 * 8 + 0x583af4);

      lpOverlapped = (LPOVERLAPPED)0x0;

      sVar4 = _strlen((char *)*puVar1);

      lpBuffer = (LPCVOID)*puVar1;

      puStackY_1c4 = (undefined *)0x54ce69;

      hFile = GetStdHandle(0xfffffff4);

      puStackY_1c4 = (undefined *)0x54ce70;

      WriteFile(hFile,lpBuffer,sVar4,lpNumberOfBytesWritten,lpOverlapped);

    }

    else if (param_1 != 0xfc) {

      DVar3 = GetModuleFileNameA((HMODULE)0x0,local_1a8,0x104);

      if (DVar3 == 0) {

        strcpy();

      }

      sVar4 = _strlen(local_1a8);

      if (0x3c < sVar4 + 1) {

        sVar4 = _strlen(local_1a8);

        puStackY_1c4 = (undefined *)0x54cdea;

        _strncpy(acStackY_1e3 + sVar4,"...",3);

      }

      strcpy();

      puStackY_1c4 = (undefined *)0x54ce0b;

      strcpy_2();

      puStackY_1c8 = local_a4;

      puStackY_1c4 = &DAT_005521e0;

      uStackY_1cc = 0x54ce1c;

      strcpy_2();

      uStackY_1cc = *(undefined4 *)(iVar5 * 8 + 0x583af4);

      puStackY_1d0 = local_a4;

      uStackY_1d4 = 0x54ce2e;

      strcpy_2();

      uStackY_1d4 = 0x12010;

      puStackY_1dc = local_a4;

      pcStackY_1d8 = "Microsoft Visual C++ Runtime Library";

      acStackY_1e3[3] = 'D';

      acStackY_1e3[4] = -0x32;

      acStackY_1e3[5] = 'T';

      acStackY_1e3[6] = '\0';

      __crtMessageBoxA();

    }

  }

  return;

}

/* ===== FUN_0054ce73 @ 0x0054CE73 ===== */
uint FUN_0054ce73(uint param_1,uint param_2)



{

  uint uVar1;

  

  uVar1 = FUN_0054cebe();

  uVar1 = uVar1 & ~param_2 | param_1 & param_2;

  FUN_0054cf50(uVar1);

  return uVar1;

}

/* ===== FUN_0054cea8 @ 0x0054CEA8 ===== */
void FUN_0054cea8(undefined4 param_1,uint param_2)



{

  FUN_0054ce73(param_1,param_2 & 0xfff7ffff);

  return;

}

/* ===== FUN_0054cebe @ 0x0054CEBE ===== */
uint FUN_0054cebe(uint param_1)



{

  uint uVar1;

  uint uVar2;

  

  uVar1 = 0;

  if ((param_1 & 1) != 0) {

    uVar1 = 0x10;

  }

  if ((param_1 & 4) != 0) {

    uVar1 = uVar1 | 8;

  }

  if ((param_1 & 8) != 0) {

    uVar1 = uVar1 | 4;

  }

  if ((param_1 & 0x10) != 0) {

    uVar1 = uVar1 | 2;

  }

  if ((param_1 & 0x20) != 0) {

    uVar1 = uVar1 | 1;

  }

  if ((param_1 & 2) != 0) {

    uVar1 = uVar1 | 0x80000;

  }

  uVar2 = param_1 & 0xc00;

  if (uVar2 != 0) {

    if (uVar2 == 0x400) {

      uVar1 = uVar1 | 0x100;

    }

    else if (uVar2 == 0x800) {

      uVar1 = uVar1 | 0x200;

    }

    else if (uVar2 == 0xc00) {

      uVar1 = uVar1 | 0x300;

    }

  }

  if ((param_1 & 0x300) == 0) {

    uVar1 = uVar1 | 0x20000;

  }

  else if ((param_1 & 0x300) == 0x200) {

    uVar1 = uVar1 | 0x10000;

  }

  if ((param_1 & 0x1000) != 0) {

    uVar1 = uVar1 | 0x40000;

  }

  return uVar1;

}

/* ===== FUN_0054cf50 @ 0x0054CF50 ===== */
uint FUN_0054cf50(uint param_1)



{

  uint uVar1;

  uint uVar2;

  

  uVar1 = (uint)((param_1 & 0x10) != 0);

  if ((param_1 & 8) != 0) {

    uVar1 = uVar1 | 4;

  }

  if ((param_1 & 4) != 0) {

    uVar1 = uVar1 | 8;

  }

  if ((param_1 & 2) != 0) {

    uVar1 = uVar1 | 0x10;

  }

  if ((param_1 & 1) != 0) {

    uVar1 = uVar1 | 0x20;

  }

  if ((param_1 & 0x80000) != 0) {

    uVar1 = uVar1 | 2;

  }

  uVar2 = param_1 & 0x300;

  if (uVar2 != 0) {

    if (uVar2 == 0x100) {

      uVar1 = uVar1 | 0x400;

    }

    else if (uVar2 == 0x200) {

      uVar1 = uVar1 | 0x800;

    }

    else if (uVar2 == 0x300) {

      uVar1 = uVar1 | 0xc00;

    }

  }

  if ((param_1 & 0x30000) == 0) {

    uVar1 = uVar1 | 0x300;

  }

  else if ((param_1 & 0x30000) == 0x10000) {

    uVar1 = uVar1 | 0x200;

  }

  if ((param_1 & 0x40000) != 0) {

    uVar1 = uVar1 | 0x1000;

  }

  return uVar1;

}

/* ===== FUN_0054cfd9 @ 0x0054CFD9 ===== */
undefined4 FUN_0054cfd9(int param_1,int param_2)



{

  int *piVar1;

  int iVar2;

  

  if ((*(uint *)(param_1 + (param_2 / 0x20) * 4) & ~(-1 << (0x1fU - (char)(param_2 % 0x20) & 0x1f)))

      != 0) {

    return 0;

  }

  iVar2 = param_2 / 0x20 + 1;

  if (iVar2 < 3) {

    piVar1 = (int *)(param_1 + iVar2 * 4);

    do {

      if (*piVar1 != 0) {

        return 0;

      }

      iVar2 = iVar2 + 1;

      piVar1 = piVar1 + 1;

    } while (iVar2 < 3);

  }

  return 1;

}

/* ===== FUN_0054d022 @ 0x0054D022 ===== */
void FUN_0054d022(int param_1,int param_2)



{

  int iVar1;

  int iVar2;

  undefined4 *puVar3;

  

  puVar3 = (undefined4 *)(param_1 + (param_2 / 0x20) * 4);

  iVar1 = FUN_0054ee12(*puVar3,1 << (0x1fU - (char)(param_2 % 0x20) & 0x1f),puVar3);

  iVar2 = param_2 / 0x20 + -1;

  if (-1 < iVar2) {

    puVar3 = (undefined4 *)(param_1 + iVar2 * 4);

    do {

      if (iVar1 == 0) {

        return;

      }

      iVar1 = FUN_0054ee12(*puVar3,1,puVar3);

      iVar2 = iVar2 + -1;

      puVar3 = puVar3 + -1;

    } while (-1 < iVar2);

  }

  return;

}

/* ===== FUN_0054d078 @ 0x0054D078 ===== */
undefined4 FUN_0054d078(int param_1,int param_2)



{

  uint *puVar1;

  int iVar2;

  byte bVar3;

  int iVar4;

  undefined4 *puVar5;

  undefined4 local_8;

  

  local_8 = 0;

  puVar1 = (uint *)(param_1 + (param_2 / 0x20) * 4);

  bVar3 = 0x1f - (char)(param_2 % 0x20);

  if (((*puVar1 & 1 << (bVar3 & 0x1f)) != 0) &&

     (iVar2 = FUN_0054cfd9(param_1,param_2 + 1), iVar2 == 0)) {

    local_8 = FUN_0054d022(param_1,param_2 + -1);

  }

  *puVar1 = *puVar1 & -1 << (bVar3 & 0x1f);

  iVar2 = param_2 / 0x20 + 1;

  if (iVar2 < 3) {

    puVar5 = (undefined4 *)(param_1 + iVar2 * 4);

    for (iVar4 = 3 - iVar2; iVar4 != 0; iVar4 = iVar4 + -1) {

      *puVar5 = 0;

      puVar5 = puVar5 + 1;

    }

  }

  return local_8;

}

/* ===== FUN_0054d104 @ 0x0054D104 ===== */
/* PS2 candidate: DestroyHuds__11cHudManager (conf 0.53) */



void FUN_0054d104(int param_1,undefined4 *param_2)



{

  int iVar1;

  

  param_1 = param_1 - (int)param_2;

  iVar1 = 3;

  do {

    *(undefined4 *)(param_1 + (int)param_2) = *param_2;

    param_2 = param_2 + 1;

    iVar1 = iVar1 + -1;

  } while (iVar1 != 0);

  return;

}

/* ===== Reset__4List @ 0x0054D11F ===== */
void Reset__4List(undefined4 *param_1)



{

  *param_1 = 0;

  param_1[1] = 0;

  param_1[2] = 0;

  return;

}

/* ===== FUN_0054d12b @ 0x0054D12B ===== */
undefined4 FUN_0054d12b(int *param_1)



{

  int iVar1;

  

  iVar1 = 0;

  do {

    if (*param_1 != 0) {

      return 0;

    }

    iVar1 = iVar1 + 1;

    param_1 = param_1 + 1;

  } while (iVar1 < 3);

  return 1;

}

/* ===== FUN_0054d146 @ 0x0054D146 ===== */
void FUN_0054d146(uint *param_1,uint param_2)



{

  uint uVar1;

  int iVar2;

  byte bVar3;

  int iVar4;

  int iVar5;

  uint *puVar6;

  int local_8;

  

  local_8 = 3;

  iVar2 = (int)param_2 / 0x20;

  iVar5 = (int)param_2 % 0x20;

  param_2 = 0;

  bVar3 = (byte)iVar5;

  puVar6 = param_1;

  do {

    uVar1 = *puVar6;

    *puVar6 = uVar1 >> (bVar3 & 0x1f) | param_2;

    puVar6 = puVar6 + 1;

    param_2 = (uVar1 & ~(-1 << (bVar3 & 0x1f))) << (0x20 - bVar3 & 0x1f);

    local_8 = local_8 + -1;

  } while (local_8 != 0);

  iVar5 = 2;

  iVar4 = 8;

  do {

    if (iVar5 < iVar2) {

      *(undefined4 *)(iVar4 + (int)param_1) = 0;

    }

    else {

      *(undefined4 *)(iVar4 + (int)param_1) = *(undefined4 *)(iVar4 + iVar2 * -4 + (int)param_1);

    }

    iVar5 = iVar5 + -1;

    iVar4 = iVar4 + -4;

  } while (-1 < iVar4);

  return;

}

/* ===== list_reset_54 @ 0x0054D1D3 ===== */
undefined4 list_reset_54(ushort *param_1,uint *param_2,int *param_3)



{

  ushort uVar1;

  int iVar2;

  uint uVar3;

  int iVar4;

  undefined4 uVar5;

  undefined1 local_1c [12];

  uint local_10;

  uint local_c;

  int local_8;

  

  uVar1 = param_1[5];

  local_10 = *(uint *)(param_1 + 3);

  local_c = *(uint *)(param_1 + 1);

  uVar3 = uVar1 & 0x7fff;

  iVar4 = uVar3 - 0x3fff;

  local_8 = (uint)*param_1 << 0x10;

  if (iVar4 == -0x3fff) {

    iVar4 = 0;

    iVar2 = FUN_0054d12b(&local_10);

    if (iVar2 != 0) {

LAB_0054d2ff:

      uVar5 = 0;

      goto LAB_0054d301;

    }

    Reset__4List(&local_10);

  }

  else {

    FUN_0054d104(local_1c,&local_10);

    iVar2 = FUN_0054d078(&local_10,param_3[2]);

    if (iVar2 != 0) {

      iVar4 = uVar3 - 0x3ffe;

    }

    iVar2 = param_3[1];

    if (iVar4 < iVar2 - param_3[2]) {

      Reset__4List(&local_10);

    }

    else {

      if (iVar2 < iVar4) {

        if (*param_3 <= iVar4) {

          Reset__4List(&local_10);

          local_10 = local_10 | 0x80000000;

          FUN_0054d146(&local_10,param_3[3]);

          iVar4 = param_3[5] + *param_3;

          uVar5 = 1;

          goto LAB_0054d301;

        }

        local_10 = local_10 & 0x7fffffff;

        iVar4 = param_3[5] + iVar4;

        FUN_0054d146(&local_10,param_3[3]);

        goto LAB_0054d2ff;

      }

      FUN_0054d104(&local_10,local_1c);

      FUN_0054d146(&local_10,iVar2 - iVar4);

      FUN_0054d078(&local_10,param_3[2]);

      FUN_0054d146(&local_10,param_3[3] + 1);

    }

  }

  iVar4 = 0;

  uVar5 = 2;

LAB_0054d301:

  local_10 = iVar4 << (0x1fU - (char)param_3[3] & 0x1f) |

             -(uint)((uVar1 & 0x8000) != 0) & 0x80000000 | local_10;

  if (param_3[4] == 0x40) {

    param_2[1] = local_10;

    *param_2 = local_c;

  }

  else if (param_3[4] == 0x20) {

    *param_2 = local_10;

  }

  return uVar5;

}

/* ===== BinFileSeek_3 @ 0x0054D33F ===== */
void BinFileSeek_3(undefined4 param_1,undefined4 param_2)



{

  list_reset_54(param_1,param_2,&DAT_00583b80);

  return;

}

/* ===== BinFileSeek_4 @ 0x0054D355 ===== */
void BinFileSeek_4(undefined4 param_1,undefined4 param_2)



{

  list_reset_54(param_1,param_2,&DAT_00583b98);

  return;

}

/* ===== binfile_seek_strtod @ 0x0054D36B ===== */
void binfile_seek_strtod(undefined4 param_1,undefined4 param_2)



{

  undefined1 local_10 [12];

  

  crt_strtod_core(local_10,&param_2,param_2,0,0,0,0);

  BinFileSeek_3(local_10,param_1);

  return;

}

/* ===== binfile_seek_strtod2 @ 0x0054D398 ===== */
void binfile_seek_strtod2(undefined4 param_1,undefined4 param_2)



{

  undefined1 local_10 [12];

  

  crt_strtod_core(local_10,&param_2,param_2,0,0,0,0);

  BinFileSeek_4(local_10,param_1);

  return;

}

/* ===== FUN_0054d3c5 @ 0x0054D3C5 ===== */
void FUN_0054d3c5(char *param_1,int param_2,int param_3)



{

  char *_Str;

  char *pcVar1;

  char *pcVar2;

  size_t sVar3;

  char *pcVar4;

  char cVar5;

  

  pcVar1 = param_1;

  pcVar4 = *(char **)(param_3 + 0xc);

  _Str = param_1 + 1;

  *param_1 = '0';

  pcVar2 = _Str;

  if (0 < param_2) {

    param_1 = (char *)param_2;

    param_2 = 0;

    do {

      cVar5 = *pcVar4;

      if (cVar5 == '\0') {

        cVar5 = '0';

      }

      else {

        pcVar4 = pcVar4 + 1;

      }

      *pcVar2 = cVar5;

      pcVar2 = pcVar2 + 1;

      param_1 = (char *)((int)param_1 + -1);

    } while (param_1 != (char *)0x0);

  }

  *pcVar2 = '\0';

  if ((-1 < param_2) && ('4' < *pcVar4)) {

    while (pcVar2 = pcVar2 + -1, *pcVar2 == '9') {

      *pcVar2 = '0';

    }

    *pcVar2 = *pcVar2 + '\x01';

  }

  if (*pcVar1 == '1') {

    *(int *)(param_3 + 4) = *(int *)(param_3 + 4) + 1;

  }

  else {

    sVar3 = _strlen(_Str);

    FUN_00543270(pcVar1,_Str,sVar3 + 1);

  }

  return;

}

/* ===== crt_mbtowc_helper @ 0x0054D43C ===== */
int * crt_mbtowc_helper(undefined4 param_1,undefined4 param_2,int *param_3,int param_4)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  short local_2c;

  char local_2a;

  undefined1 local_28 [24];

  undefined4 local_10;

  undefined4 uStack_c;

  undefined2 uStack_8;

  

  FUN_0054d498(&local_10,&param_1);

  iVar3 = crt_fltout(local_10,uStack_c,uStack_8,0x11,0,&local_2c);

  iVar2 = param_4;

  piVar1 = param_3;

  param_3[2] = iVar3;

  *param_3 = (int)local_2a;

  param_3[1] = (int)local_2c;

  strcpy(param_4,local_28);

  piVar1[3] = iVar2;

  return piVar1;

}

/* ===== FUN_0054d498 @ 0x0054D498 ===== */
void FUN_0054d498(uint *param_1,uint *param_2)



{

  ushort uVar1;

  uint uVar2;

  uint uVar3;

  int iVar4;

  uint local_8;

  

  uVar1 = *(ushort *)((int)param_2 + 6);

  uVar3 = (uVar1 & 0x7ff0) >> 4;

  uVar2 = *param_2;

  local_8 = 0x80000000;

  if (uVar3 == 0) {

    if (((param_2[1] & 0xfffff) == 0) && (uVar2 == 0)) {

      param_1[1] = 0;

      *param_1 = 0;

      *(undefined2 *)(param_1 + 2) = 0;

      return;

    }

    iVar4 = 0x3c01;

    local_8 = 0;

  }

  else if (uVar3 == 0x7ff) {

    iVar4 = 0x7fff;

  }

  else {

    iVar4 = uVar3 + 0x3c00;

  }

  local_8 = uVar2 >> 0x15 | (param_2[1] & 0xfffff) << 0xb | local_8;

  param_1[1] = local_8;

  *param_1 = uVar2 << 0xb;

  while ((local_8 & 0x80000000) == 0) {

    local_8 = *param_1 >> 0x1f | local_8 * 2;

    *param_1 = *param_1 * 2;

    param_1[1] = local_8;

    iVar4 = iVar4 + 0xffff;

  }

  *(ushort *)(param_1 + 2) = uVar1 & 0x8000 | (ushort)iVar4;

  return;

}

/* ===== _memset @ 0x0054D550 ===== */
/* Library Function - Single Match

    _memset

   

   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */



void * __cdecl _memset(void *_Dst,int _Val,size_t _Size)



{

  uint uVar1;

  uint uVar2;

  size_t sVar3;

  uint *puVar4;

  

  if (_Size == 0) {

    return _Dst;

  }

  uVar1 = _Val & 0xff;

  puVar4 = _Dst;

  if (3 < _Size) {

    uVar2 = -(int)_Dst & 3;

    sVar3 = _Size;

    if (uVar2 != 0) {

      sVar3 = _Size - uVar2;

      do {

        *(undefined1 *)puVar4 = (undefined1)_Val;

        puVar4 = (uint *)((int)puVar4 + 1);

        uVar2 = uVar2 - 1;

      } while (uVar2 != 0);

    }

    uVar1 = uVar1 * 0x1010101;

    _Size = sVar3 & 3;

    uVar2 = sVar3 >> 2;

    if (uVar2 != 0) {

      for (; uVar2 != 0; uVar2 = uVar2 - 1) {

        *puVar4 = uVar1;

        puVar4 = puVar4 + 1;

      }

      if (_Size == 0) {

        return _Dst;

      }

    }

  }

  do {

    *(char *)puVar4 = (char)uVar1;

    puVar4 = (uint *)((int)puVar4 + 1);

    _Size = _Size - 1;

  } while (_Size != 0);

  return _Dst;

}

/* ===== FUN_0054D5A8 @ 0x0054D5A8 ===== */
void FUN_0054D5A8(void)



{

  __amsg_exit(2);

  return;

}

/* ===== crt_lseek_errno @ 0x0054D5B1 ===== */
undefined4 crt_lseek_errno(uint param_1,undefined4 param_2,undefined4 param_3)



{

  undefined4 uVar1;

  undefined4 *puVar2;

  

  if ((param_1 < DAT_006579c0) &&

     ((*(byte *)((&DAT_006578c0)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 1) != 0)) {

    crt_lock_fd(param_1);

    uVar1 = _lseek(param_1,param_2,param_3);

    FUN_00545c58(param_1);

    return uVar1;

  }

  puVar2 = (undefined4 *)_errno();

  *puVar2 = 9;

  puVar2 = (undefined4 *)__doserrno();

  *puVar2 = 0;

  return 0xffffffff;

}

/* ===== _lseek @ 0x0054D616 ===== */
DWORD _lseek(uint param_1,LONG param_2,DWORD param_3)



{

  byte *pbVar1;

  HANDLE hFile;

  undefined4 *puVar2;

  DWORD DVar3;

  DWORD DVar4;

  

  hFile = (HANDLE)crt_validate_osfhnd(param_1);

  if (hFile == (HANDLE)0xffffffff) {

    puVar2 = (undefined4 *)_errno();

    *puVar2 = 9;

  }

  else {

    DVar3 = SetFilePointer(hFile,param_2,(PLONG)0x0,param_3);

    if (DVar3 == 0xffffffff) {

      DVar4 = GetLastError();

    }

    else {

      DVar4 = 0;

    }

    if (DVar4 == 0) {

      pbVar1 = (byte *)((&DAT_006578c0)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24);

      *pbVar1 = *pbVar1 & 0xfd;

      return DVar3;

    }

    _dosmaperr(DVar4);

  }

  return 0xffffffff;

}

/* ===== FUN_0054d689 @ 0x0054D689 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_0054d689(undefined4 *param_1)



{

  void *pvVar1;

  

  _DAT_00630ba0 = _DAT_00630ba0 + 1;

  pvVar1 = _malloc(0x1000);

  param_1[2] = pvVar1;

  if (pvVar1 == (void *)0x0) {

    param_1[3] = param_1[3] | 4;

    param_1[2] = param_1 + 5;

    param_1[6] = 2;

  }

  else {

    param_1[3] = param_1[3] | 8;

    param_1[6] = 0x1000;

  }

  param_1[1] = 0;

  *param_1 = param_1[2];

  return;

}

/* ===== FUN_0054d6cd @ 0x0054D6CD ===== */
byte FUN_0054d6cd(uint param_1)



{

  if (DAT_006579c0 <= param_1) {

    return 0;

  }

  return *(byte *)((&DAT_006578c0)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 0x40;

}

/* ===== crt_wctomb_lock @ 0x0054D6F6 ===== */
undefined4 crt_wctomb_lock(undefined4 param_1,undefined4 param_2)



{

  undefined4 uVar1;

  bool bVar2;

  

  InterlockedIncrement((LONG *)&DAT_006579c8);

  bVar2 = DAT_006579c4 != 0;

  if (bVar2) {

    InterlockedDecrement((LONG *)&DAT_006579c8);

    _lock(0x13);

  }

  uVar1 = crt_errno_read(param_1,param_2);

  if (bVar2) {

    _unlock(0x13);

  }

  else {

    InterlockedDecrement((LONG *)&DAT_006579c8);

  }

  return uVar1;

}

/* ===== crt_errno_read @ 0x0054D74F ===== */
int crt_errno_read(LPSTR param_1,WCHAR param_2)



{

  LPSTR lpMultiByteStr;

  int iVar1;

  undefined4 *puVar2;

  

  lpMultiByteStr = param_1;

  if (param_1 == (LPSTR)0x0) {

    return 0;

  }

  if (DAT_00630c5c == 0) {

    if ((ushort)param_2 < 0x100) {

      *param_1 = (CHAR)param_2;

      return 1;

    }

  }

  else {

    param_1 = (LPSTR)0x0;

    iVar1 = WideCharToMultiByte(DAT_00630c6c,0x220,&param_2,1,lpMultiByteStr,DAT_005810b8,

                                (LPCSTR)0x0,(LPBOOL)&param_1);

    if ((iVar1 != 0) && (param_1 == (LPSTR)0x0)) {

      return iVar1;

    }

  }

  puVar2 = (undefined4 *)_errno();

  *puVar2 = 0x2a;

  return -1;

}

/* ===== crt_close_osf @ 0x0054D7B8 ===== */
undefined4 crt_close_osf(uint param_1)



{

  HANDLE hFile;

  BOOL BVar1;

  DWORD DVar2;

  DWORD *pDVar3;

  undefined4 *puVar4;

  int iVar5;

  undefined4 uVar6;

  

  if (DAT_006579c0 <= param_1) {

LAB_0054d839:

    puVar4 = (undefined4 *)_errno();

    *puVar4 = 9;

    return 0xffffffff;

  }

  iVar5 = (param_1 & 0x1f) * 0x24;

  if ((*(byte *)((&DAT_006578c0)[(int)param_1 >> 5] + 4 + iVar5) & 1) == 0) goto LAB_0054d839;

  crt_lock_fd(param_1);

  if ((*(byte *)((&DAT_006578c0)[(int)param_1 >> 5] + 4 + iVar5) & 1) != 0) {

    hFile = (HANDLE)crt_validate_osfhnd(param_1);

    BVar1 = FlushFileBuffers(hFile);

    if (BVar1 == 0) {

      DVar2 = GetLastError();

    }

    else {

      DVar2 = 0;

    }

    uVar6 = 0;

    if (DVar2 == 0) goto LAB_0054d82e;

    pDVar3 = (DWORD *)__doserrno();

    *pDVar3 = DVar2;

  }

  puVar4 = (undefined4 *)_errno();

  *puVar4 = 9;

  uVar6 = 0xffffffff;

LAB_0054d82e:

  FUN_00545c58(param_1);

  return uVar6;

}

/* ===== AudioDataStreamStatus__Fv_8 @ 0x0054D84B ===== */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */



undefined4 AudioDataStreamStatus__Fv_8(void)



{

  return 0;

}

/* ===== crt_openfile @ 0x0054D84E ===== */
uint crt_openfile(LPCSTR param_1,uint param_2,uint param_3,uint param_4)



{

  byte *pbVar1;

  uint uVar2;

  uint uVar3;

  undefined4 *puVar4;

  HANDLE hFile;

  DWORD DVar5;

  int *piVar6;

  int iVar7;

  int iVar8;

  bool bVar9;

  _SECURITY_ATTRIBUTES local_20;

  DWORD local_14;

  DWORD local_10;

  DWORD local_c;

  byte local_5;

  

  bVar9 = (param_2 & 0x80) == 0;

  local_20.nLength = 0xc;

  local_20.lpSecurityDescriptor = (LPVOID)0x0;

  if (bVar9) {

    local_5 = 0;

  }

  else {

    local_5 = 0x10;

  }

  local_20.bInheritHandle = (BOOL)bVar9;

  if (((param_2 & 0x8000) == 0) && (((param_2 & 0x4000) != 0 || (DAT_00630eb0 != 0x8000)))) {

    local_5 = local_5 | 0x80;

  }

  uVar2 = param_2 & 3;

  if (uVar2 == 0) {

    local_10 = 0x80000000;

  }

  else if (uVar2 == 1) {

    local_10 = 0x40000000;

  }

  else {

    if (uVar2 != 2) goto LAB_0054d952;

    local_10 = 0xc0000000;

  }

  if (param_3 == 0x10) {

    local_14 = 0;

  }

  else if (param_3 == 0x20) {

    local_14 = 1;

  }

  else if (param_3 == 0x30) {

    local_14 = 2;

  }

  else {

    if (param_3 != 0x40) goto LAB_0054d952;

    local_14 = 3;

  }

  uVar2 = param_2 & 0x700;

  if (uVar2 < 0x401) {

    if ((uVar2 == 0x400) || (uVar2 == 0)) {

      local_c = 3;

    }

    else if (uVar2 == 0x100) {

      local_c = 4;

    }

    else {

      if (uVar2 == 0x200) goto LAB_0054d96c;

      if (uVar2 != 0x300) goto LAB_0054d952;

      local_c = 2;

    }

  }

  else {

    if (uVar2 != 0x500) {

      if (uVar2 == 0x600) {

LAB_0054d96c:

        local_c = 5;

        goto LAB_0054d97c;

      }

      if (uVar2 != 0x700) {

LAB_0054d952:

        puVar4 = (undefined4 *)_errno();

        *puVar4 = 0x16;

        puVar4 = (undefined4 *)__doserrno();

        *puVar4 = 0;

        return 0xffffffff;

      }

    }

    local_c = 1;

  }

LAB_0054d97c:

  uVar2 = 0x80;

  if (((param_2 & 0x100) != 0) && ((~DAT_00630b5c & param_4 & 0x80) == 0)) {

    uVar2 = 1;

  }

  if ((param_2 & 0x40) != 0) {

    uVar2 = uVar2 | 0x4000000;

    local_10 = CONCAT13(local_10._3_1_,0x10000);

  }

  if ((param_2 & 0x1000) != 0) {

    uVar2 = uVar2 | 0x100;

  }

  if ((param_2 & 0x20) == 0) {

    if ((param_2 & 0x10) != 0) {

      uVar2 = uVar2 | 0x10000000;

    }

  }

  else {

    uVar2 = uVar2 | 0x8000000;

  }

  uVar3 = crt_file_lock_2ops();

  if (uVar3 == 0xffffffff) {

    puVar4 = (undefined4 *)_errno();

    *puVar4 = 0x18;

    puVar4 = (undefined4 *)__doserrno();

    *puVar4 = 0;

    return 0xffffffff;

  }

  hFile = CreateFileA(param_1,local_10,local_14,&local_20,local_c,uVar2,(HANDLE)0x0);

  if (hFile != (HANDLE)0xffffffff) {

    DVar5 = GetFileType(hFile);

    if (DVar5 != 0) {

      if (DVar5 == 2) {

        local_5 = local_5 | 0x40;

      }

      else if (DVar5 == 3) {

        local_5 = local_5 | 8;

      }

      crt_set_errno_val(uVar3,hFile);

      iVar8 = (uVar3 & 0x1f) * 0x24;

      param_1._3_1_ = local_5 & 0x48;

      *(byte *)((&DAT_006578c0)[(int)uVar3 >> 5] + 4 + iVar8) = local_5 | 1;

      if ((((local_5 & 0x48) == 0) && ((local_5 & 0x80) != 0)) && ((param_2 & 2) != 0)) {

        local_14 = _lseek(uVar3,0xffffffff,2);

        if (local_14 == 0xffffffff) {

          piVar6 = (int *)__doserrno();

          if (*piVar6 == 0x83) goto LAB_0054daf6;

        }

        else {

          param_3 = param_3 & 0xffffff;

          iVar7 = _read_lk(uVar3,(int)&param_3 + 3,1);

          if ((((iVar7 != 0) || (param_3._3_1_ != '\x1a')) ||

              (iVar7 = FUN_0054f246(uVar3,local_14), iVar7 != -1)) &&

             (iVar7 = _lseek(uVar3,0,0), iVar7 != -1)) goto LAB_0054daf6;

        }

        _close(uVar3);

        uVar2 = 0xffffffff;

      }

      else {

LAB_0054daf6:

        uVar2 = uVar3;

        if ((param_1._3_1_ == 0) && ((param_2 & 8) != 0)) {

          pbVar1 = (byte *)((&DAT_006578c0)[(int)uVar3 >> 5] + 4 + iVar8);

          *pbVar1 = *pbVar1 | 0x20;

        }

      }

      goto LAB_0054db0f;

    }

    CloseHandle(hFile);

  }

  DVar5 = GetLastError();

  _dosmaperr(DVar5);

  uVar2 = 0xffffffff;

LAB_0054db0f:

  FUN_00545c58(uVar3);

  return uVar2;

}

/* ===== crt_fpe_signal @ 0x0054DB1D ===== */
void crt_fpe_signal(int param_1,int *param_2,ushort *param_3)



{

  int iVar1;

  undefined4 uVar2;

  undefined1 local_5c [40];

  undefined8 local_34;

  uint local_24;

  

  param_3 = (ushort *)(uint)*param_3;

  iVar1 = *param_2;

  if (iVar1 == 1) {

LAB_0054db62:

    uVar2 = 8;

  }

  else if (iVar1 == 2) {

    uVar2 = 4;

  }

  else if (iVar1 == 3) {

    uVar2 = 0x11;

  }

  else if (iVar1 == 4) {

    uVar2 = 0x12;

  }

  else {

    if (iVar1 == 5) goto LAB_0054db62;

    if (iVar1 == 7) {

      *param_2 = 1;

      goto LAB_0054dbb8;

    }

    if (iVar1 != 8) goto LAB_0054dbb8;

    uVar2 = 0x10;

  }

  iVar1 = crt_fpe_checkmask(uVar2,param_2 + 6,param_3);

  if (iVar1 == 0) {

    if (((param_1 == 0x10) || (param_1 == 0x16)) || (param_1 == 0x1d)) {

      local_34 = *(undefined8 *)(param_2 + 4);

      local_24 = local_24 & 0xffffffe3 | 3;

    }

    else {

      local_24 = local_24 & 0xfffffffe;

    }

    crt_fpe_raise(local_5c,&param_3,uVar2,param_1,param_2 + 2,param_2 + 6);

  }

LAB_0054dbb8:

  crt_fnstcw(param_3,0xffff);

  if (((*param_2 != 8) && (DAT_00583bb0 == 0)) &&

     (iVar1 = AudioDataStreamStatus__Fv_8(), iVar1 != 0)) {

    return;

  }

  crt_matherr_flag(*param_2);

  return;

}

/* ===== crt_fpclassify @ 0x0054DBED ===== */
int crt_fpclassify(int param_1,uint param_2)



{

  int iVar1;

  int iStack_8;

  

  if ((param_2._2_2_ & 0x7ff0) == 0x7ff0) {

    iVar1 = _fpclass();

    if (iVar1 != 1) {

      if (iVar1 == 2) {

        iStack_8 = 4;

      }

      else if (iVar1 == 3) {

        iStack_8 = 2;

      }

      else {

        iStack_8 = 1;

      }

      return iStack_8;

    }

    return 0x200;

  }

  if (((param_2 & 0x7ff00000) == 0) && (((param_2 & 0xfffff) != 0 || (param_1 != 0)))) {

    return (-(uint)((param_2 & 0x80000000) != 0) & 0xffffff90) + 0x80;

  }

  if ((double)CONCAT26(param_2._2_2_,CONCAT24((undefined2)param_2,param_1)) == 0.0) {

    return (-(uint)((param_2 & 0x80000000) != 0) & 0xffffffe0) + 0x40;

  }

  return (-(uint)((param_2 & 0x80000000) != 0) & 0xffffff08) + 0x100;

}

/* ===== crt_lock_54dc7f @ 0x0054DC7F ===== */
undefined4 crt_lock_54dc7f(undefined4 param_1,undefined4 param_2,undefined4 param_3)



{

  undefined4 uVar1;

  bool bVar2;

  

  InterlockedIncrement((LONG *)&DAT_006579c8);

  bVar2 = DAT_006579c4 != 0;

  if (bVar2) {

    InterlockedDecrement((LONG *)&DAT_006579c8);

    _lock(0x13);

  }

  uVar1 = crt_errno_big2(param_1,param_2,param_3);

  if (bVar2) {

    _unlock(0x13);

  }

  else {

    InterlockedDecrement((LONG *)&DAT_006579c8);

  }

  return uVar1;

}

/* ===== crt_errno_big2 @ 0x0054DCDC ===== */
uint crt_errno_big2(LPWSTR param_1,byte *param_2,uint param_3)



{

  byte bVar1;

  int iVar2;

  undefined4 *puVar3;

  

  if ((param_2 != (byte *)0x0) && (param_3 != 0)) {

    bVar1 = *param_2;

    if (bVar1 != 0) {

      if (DAT_00630c5c == 0) {

        if (param_1 != (LPWSTR)0x0) {

          *param_1 = (ushort)bVar1;

        }

        return 1;

      }

      if ((PTR_DAT_00580eac[(uint)bVar1 * 2 + 1] & 0x80) == 0) {

        iVar2 = MultiByteToWideChar(DAT_00630c6c,9,(LPCSTR)param_2,1,param_1,

                                    (uint)(param_1 != (LPWSTR)0x0));

        if (iVar2 != 0) {

          return 1;

        }

      }

      else {

        if (1 < (int)DAT_005810b8) {

          if ((int)param_3 < (int)DAT_005810b8) goto LAB_0054dd6e;

          iVar2 = MultiByteToWideChar(DAT_00630c6c,9,(LPCSTR)param_2,DAT_005810b8,param_1,

                                      (uint)(param_1 != (LPWSTR)0x0));

          if (iVar2 != 0) {

            return DAT_005810b8;

          }

        }

        if ((DAT_005810b8 <= param_3) && (param_2[1] != 0)) {

          return DAT_005810b8;

        }

      }

LAB_0054dd6e:

      puVar3 = (undefined4 *)_errno();

      *puVar3 = 0x2a;

      return 0xffffffff;

    }

    if (param_1 != (LPWSTR)0x0) {

      *param_1 = L'\0';

    }

  }

  return 0;

}

/* ===== __allshl @ 0x0054DDB0 ===== */
/* Library Function - Single Match

    __allshl

   

   Library: Visual Studio */



longlong __allshl(void)



{

  uint in_EAX;

  byte in_CL;

  int in_EDX;

  

  if (0x3f < in_CL) {

    return 0;

  }

  if (in_CL < 0x20) {

    return CONCAT44(in_EDX << (in_CL & 0x1f) | in_EAX >> 0x20 - (in_CL & 0x1f),

                    in_EAX << (in_CL & 0x1f));

  }

  return (ulonglong)(in_EAX << (in_CL & 0x1f)) << 0x20;

}

/* ===== FUN_0054ddcf @ 0x0054DDCF ===== */
uint FUN_0054ddcf(uint param_1,int *param_2)



{

  uint uVar1;

  

  if ((param_1 != 0xffffffff) &&

     ((uVar1 = param_2[3], (uVar1 & 1) != 0 || (((uVar1 & 0x80) != 0 && ((uVar1 & 2) == 0)))))) {

    if (param_2[2] == 0) {

      FUN_0054d689(param_2);

    }

    if (*param_2 == param_2[2]) {

      if (param_2[1] != 0) {

        return 0xffffffff;

      }

      *param_2 = *param_2 + 1;

    }

    if ((*(byte *)(param_2 + 3) & 0x40) == 0) {

      *param_2 = *param_2 + -1;

      *(char *)*param_2 = (char)param_1;

    }

    else {

      *param_2 = *param_2 + -1;

      if (*(char *)*param_2 != (char)param_1) {

        *param_2 = (int)((char *)*param_2 + 1);

        return 0xffffffff;

      }

    }

    param_2[1] = param_2[1] + 1;

    param_2[3] = param_2[3] & 0xffffffefU | 1;

    return param_1 & 0xff;

  }

  return 0xffffffff;

}

/* ===== crt_strtod_core @ 0x0054DE3D ===== */
undefined4

crt_strtod_core(ushort *param_1,int *param_2,byte *param_3,undefined4 param_4,int param_5,

               int param_6,int param_7)



{

  int iVar1;

  uint uVar2;

  char *pcVar3;

  int iVar4;

  int iVar5;

  byte bVar6;

  byte *pbVar7;

  byte *pbVar8;

  byte *pbVar9;

  int iVar10;

  char local_60 [23];

  char local_49;

  ushort local_44;

  undefined2 uStack_42;

  undefined2 uStack_40;

  byte *local_3e;

  ushort local_3a;

  int local_34;

  int local_30;

  undefined4 local_2c;

  int local_28;

  int local_24;

  int local_20;

  int local_1c;

  undefined4 local_18;

  int local_14;

  char *local_10;

  int local_c;

  uint local_8;

  

  local_10 = local_60;

  local_2c = 0;

  local_1c = 1;

  local_8 = 0;

  local_14 = 0;

  local_28 = 0;

  local_24 = 0;

  local_30 = 0;

  local_34 = 0;

  local_20 = 0;

  local_c = 0;

  local_18 = 0;

  for (pbVar7 = param_3;

      (((bVar6 = *pbVar7, bVar6 == 0x20 || (bVar6 == 9)) || (bVar6 == 10)) || (bVar6 == 0xd));

      pbVar7 = pbVar7 + 1) {

  }

  iVar4 = 4;

  iVar10 = 0;

  iVar5 = local_14;

LAB_0054de94:

  local_14 = iVar5;

  iVar5 = 1;

  bVar6 = *pbVar7;

  pbVar8 = pbVar7 + 1;

  pbVar9 = param_3;

  iVar1 = local_14;

  switch(iVar10) {

  case 0:

    if (('0' < (char)bVar6) && ((char)bVar6 < ':')) {

LAB_0054deb1:

      local_14 = iVar1;

      iVar10 = 3;

      goto LAB_0054e0d6;

    }

    if (bVar6 == DAT_005810bc) goto LAB_0054dec0;

    if (bVar6 == 0x2b) {

      local_2c = 0;

      iVar10 = 2;

      pbVar7 = pbVar8;

      iVar5 = local_14;

    }

    else if (bVar6 == 0x2d) {

      local_2c = 0x8000;

      iVar10 = 2;

      pbVar7 = pbVar8;

      iVar5 = local_14;

    }

    else {

      iVar10 = iVar5;

      pbVar7 = pbVar8;

      iVar5 = local_14;

      if (bVar6 != 0x30) goto LAB_0054e1b0;

    }

    goto LAB_0054de94;

  case 1:

    local_14 = 1;

    if (('0' < (char)bVar6) && (iVar1 = iVar5, (char)bVar6 < ':')) goto LAB_0054deb1;

    iVar10 = iVar4;

    pbVar7 = pbVar8;

    if (bVar6 != DAT_005810bc) {

      iVar10 = iVar5;

      if ((bVar6 == 0x2b) || (iVar10 = local_14, bVar6 == 0x2d)) goto LAB_0054df45;

      iVar10 = iVar5;

      local_14 = iVar5;

      if (bVar6 != 0x30) goto LAB_0054df1e;

    }

    goto LAB_0054de94;

  case 2:

    if (('0' < (char)bVar6) && ((char)bVar6 < ':')) goto LAB_0054deb1;

    if (bVar6 == DAT_005810bc) {

LAB_0054dec0:

      iVar10 = 5;

      pbVar7 = pbVar8;

      iVar5 = local_14;

    }

    else {

      iVar10 = iVar5;

      pbVar7 = pbVar8;

      iVar5 = local_14;

      if (bVar6 != 0x30) goto LAB_0054e1b5;

    }

    goto LAB_0054de94;

  case 3:

    local_14 = iVar5;

    while( true ) {

      if (DAT_005810b8 < 2) {

        uVar2 = (byte)PTR_DAT_00580eac[(uint)bVar6 * 2] & 4;

      }

      else {

        uVar2 = FUN_00544123(bVar6,4);

      }

      if (uVar2 == 0) break;

      if (local_8 < 0x19) {

        local_8 = local_8 + 1;

        pcVar3 = local_10 + 1;

        *local_10 = bVar6 - 0x30;

        local_10 = pcVar3;

      }

      else {

        local_c = local_c + 1;

      }

      bVar6 = *pbVar8;

      pbVar8 = pbVar8 + 1;

    }

    iVar10 = iVar4;

    pbVar7 = pbVar8;

    iVar5 = local_14;

    if (bVar6 != DAT_005810bc) goto LAB_0054e032;

    goto LAB_0054de94;

  case 4:

    local_14 = 1;

    local_28 = 1;

    iVar10 = iVar5;

    if (local_8 == 0) {

      while (iVar5 = local_28, iVar10 = local_14, bVar6 == 0x30) {

        local_c = local_c + -1;

        bVar6 = *pbVar8;

        pbVar8 = pbVar8 + 1;

      }

    }

    while( true ) {

      local_14 = iVar10;

      local_28 = iVar5;

      if (DAT_005810b8 < 2) {

        uVar2 = (byte)PTR_DAT_00580eac[(uint)bVar6 * 2] & 4;

      }

      else {

        uVar2 = FUN_00544123(bVar6,4);

      }

      if (uVar2 == 0) break;

      if (local_8 < 0x19) {

        local_8 = local_8 + 1;

        local_c = local_c + -1;

        pcVar3 = local_10 + 1;

        *local_10 = bVar6 - 0x30;

        local_10 = pcVar3;

      }

      bVar6 = *pbVar8;

      pbVar8 = pbVar8 + 1;

      iVar5 = local_28;

      iVar10 = local_14;

    }

LAB_0054e032:

    iVar10 = local_14;

    if ((bVar6 == 0x2b) || (bVar6 == 0x2d)) {

LAB_0054df45:

      local_14 = iVar10;

      iVar10 = 0xb;

      pbVar7 = pbVar8 + -1;

      iVar5 = local_14;

    }

    else {

LAB_0054df1e:

      if (((char)bVar6 < 'D') ||

         (('E' < (char)bVar6 && (((char)bVar6 < 'd' || ('e' < (char)bVar6)))))) goto LAB_0054e1b0;

      iVar10 = 6;

      pbVar7 = pbVar8;

      iVar5 = local_14;

    }

    goto LAB_0054de94;

  case 5:

    local_28 = iVar5;

    if (DAT_005810b8 < 2) {

      uVar2 = (byte)PTR_DAT_00580eac[(uint)bVar6 * 2] & 4;

    }

    else {

      uVar2 = FUN_00544123(bVar6,4);

    }

    iVar10 = iVar4;

    if (uVar2 != 0) goto LAB_0054e0d6;

    goto LAB_0054e1b5;

  case 6:

    param_3 = pbVar7 + -1;

    if (((char)bVar6 < '1') || ('9' < (char)bVar6)) {

      if (bVar6 == 0x2b) goto LAB_0054e10b;

      if (bVar6 == 0x2d) goto LAB_0054e0ff;

      pbVar9 = param_3;

      if (bVar6 != 0x30) goto LAB_0054e1b5;

LAB_0054e0a4:

      iVar10 = 8;

      pbVar7 = pbVar8;

      iVar5 = local_14;

      goto LAB_0054de94;

    }

    break;

  case 7:

    if (((char)bVar6 < '1') || ('9' < (char)bVar6)) {

      if (bVar6 == 0x30) goto LAB_0054e0a4;

      goto LAB_0054e1b5;

    }

    break;

  case 8:

    local_24 = 1;

    while (bVar6 == 0x30) {

      bVar6 = *pbVar8;

      pbVar8 = pbVar8 + 1;

    }

    if (((char)bVar6 < '1') || ('9' < (char)bVar6)) goto LAB_0054e1b0;

    break;

  case 9:

    local_24 = 1;

    iVar4 = 0;

    goto LAB_0054e136;

  default:

    goto switchD_0054dea0_caseD_a;

  case 0xb:

    if (param_7 != 0) {

      param_3 = pbVar7;

      if (bVar6 == 0x2b) {

LAB_0054e10b:

        iVar10 = 7;

        pbVar7 = pbVar8;

        iVar5 = local_14;

      }

      else {

        pbVar9 = pbVar7;

        if (bVar6 != 0x2d) goto LAB_0054e1b5;

LAB_0054e0ff:

        local_1c = -1;

        iVar10 = 7;

        pbVar7 = pbVar8;

        iVar5 = local_14;

      }

      goto LAB_0054de94;

    }

    iVar10 = 10;

    pbVar8 = pbVar7;

switchD_0054dea0_caseD_a:

    pbVar7 = pbVar8;

    pbVar9 = pbVar8;

    iVar5 = local_14;

    if (iVar10 != 10) goto LAB_0054de94;

    goto LAB_0054e1b5;

  }

  iVar10 = 9;

LAB_0054e0d6:

  pbVar7 = pbVar8 + -1;

  iVar5 = local_14;

  goto LAB_0054de94;

LAB_0054e136:

  if (DAT_005810b8 < 2) {

    uVar2 = (byte)PTR_DAT_00580eac[(uint)bVar6 * 2] & 4;

  }

  else {

    uVar2 = FUN_00544123(bVar6,4);

  }

  if (uVar2 == 0) goto LAB_0054e180;

  iVar4 = (char)bVar6 + -0x30 + iVar4 * 10;

  if (0x1450 < iVar4) goto LAB_0054e178;

  bVar6 = *pbVar8;

  pbVar8 = pbVar8 + 1;

  goto LAB_0054e136;

LAB_0054e178:

  iVar4 = 0x1451;

LAB_0054e180:

  while( true ) {

    local_20 = iVar4;

    if (DAT_005810b8 < 2) {

      uVar2 = (byte)PTR_DAT_00580eac[(uint)bVar6 * 2] & 4;

    }

    else {

      uVar2 = FUN_00544123(bVar6,4);

    }

    if (uVar2 == 0) break;

    bVar6 = *pbVar8;

    pbVar8 = pbVar8 + 1;

    iVar4 = local_20;

  }

LAB_0054e1b0:

  pbVar9 = pbVar8 + -1;

LAB_0054e1b5:

  *param_2 = (int)pbVar9;

  if (local_14 == 0) {

    local_44 = 0;

    local_3a = 0;

    local_3e = (byte *)0x0;

    param_3 = (byte *)0x0;

    local_18 = 4;

    goto LAB_0054e2c3;

  }

  pcVar3 = local_10;

  if (0x18 < local_8) {

    if ('\x04' < local_49) {

      local_49 = local_49 + '\x01';

    }

    local_8 = 0x18;

    local_c = local_c + 1;

    pcVar3 = local_10 + -1;

  }

  if (local_8 == 0) {

    local_44 = 0;

    local_3a = 0;

    local_3e = (byte *)0x0;

    param_3 = (byte *)0x0;

  }

  else {

    while (pcVar3 = pcVar3 + -1, *pcVar3 == '\0') {

      local_8 = local_8 - 1;

      local_c = local_c + 1;

    }

    FUN_0054eeec(local_60,local_8,&local_44);

    iVar4 = local_20;

    if (local_1c < 0) {

      iVar4 = -local_20;

    }

    iVar4 = iVar4 + local_c;

    if (local_24 == 0) {

      iVar4 = iVar4 + param_5;

    }

    if (local_28 == 0) {

      iVar4 = iVar4 - param_6;

    }

    if (iVar4 < 0x1451) {

      if (-0x1451 < iVar4) {

        FUN_0054f58b(&local_44,iVar4,param_4);

        param_3 = (byte *)CONCAT22(uStack_40,uStack_42);

        goto LAB_0054e248;

      }

      local_34 = 1;

    }

    else {

      local_30 = 1;

    }

    local_3a = (ushort)param_3;

    local_3e = param_3;

    local_44 = local_3a;

  }

LAB_0054e248:

  if (local_30 == 0) {

    if (local_34 != 0) {

      local_44 = 0;

      local_3a = 0;

      local_3e = (byte *)0x0;

      param_3 = (byte *)0x0;

      local_18 = 1;

    }

  }

  else {

    param_3 = (byte *)0x0;

    local_3a = 0x7fff;

    local_3e = (byte *)0x80000000;

    local_44 = 0;

    local_18 = 2;

  }

LAB_0054e2c3:

  *(byte **)(param_1 + 3) = local_3e;

  *(byte **)(param_1 + 1) = param_3;

  param_1[5] = local_3a | (ushort)local_2c;

  *param_1 = local_44;

  return local_18;

}

/* ===== _strcmp @ 0x0054E310 ===== */
/* Library Function - Single Match

    _strcmp

   

   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */



int __cdecl _strcmp(char *_Str1,char *_Str2)



{

  undefined2 uVar1;

  undefined4 uVar2;

  byte bVar3;

  byte bVar4;

  bool bVar5;

  

  if (((uint)_Str1 & 3) != 0) {

    if (((uint)_Str1 & 1) != 0) {

      bVar4 = *_Str1;

      _Str1 = _Str1 + 1;

      bVar5 = bVar4 < (byte)*_Str2;

      if (bVar4 != *_Str2) goto LAB_0054e354;

      _Str2 = _Str2 + 1;

      if (bVar4 == 0) {

        return 0;

      }

      if (((uint)_Str1 & 2) == 0) goto LAB_0054e320;

    }

    uVar1 = *(undefined2 *)_Str1;

    _Str1 = _Str1 + 2;

    bVar4 = (byte)uVar1;

    bVar5 = bVar4 < (byte)*_Str2;

    if (bVar4 != *_Str2) goto LAB_0054e354;

    if (bVar4 == 0) {

      return 0;

    }

    bVar4 = (byte)((ushort)uVar1 >> 8);

    bVar5 = bVar4 < (byte)_Str2[1];

    if (bVar4 != _Str2[1]) goto LAB_0054e354;

    if (bVar4 == 0) {

      return 0;

    }

    _Str2 = _Str2 + 2;

  }

LAB_0054e320:

  while( true ) {

    uVar2 = *(undefined4 *)_Str1;

    bVar4 = (byte)uVar2;

    bVar5 = bVar4 < (byte)*_Str2;

    if (bVar4 != *_Str2) break;

    if (bVar4 == 0) {

      return 0;

    }

    bVar4 = (byte)((uint)uVar2 >> 8);

    bVar5 = bVar4 < (byte)_Str2[1];

    if (bVar4 != _Str2[1]) break;

    if (bVar4 == 0) {

      return 0;

    }

    bVar4 = (byte)((uint)uVar2 >> 0x10);

    bVar5 = bVar4 < (byte)_Str2[2];

    if (bVar4 != _Str2[2]) break;

    bVar3 = (byte)((uint)uVar2 >> 0x18);

    if (bVar4 == 0) {

      return 0;

    }

    bVar5 = bVar3 < (byte)_Str2[3];

    if (bVar3 != _Str2[3]) break;

    _Str2 = _Str2 + 4;

    _Str1 = _Str1 + 4;

    if (bVar3 == 0) {

      return 0;

    }

  }

LAB_0054e354:

  return (uint)bVar5 * -2 + 1;

}

/* ===== FUN_0054e3a0 @ 0x0054E3A0 ===== */
int FUN_0054e3a0(byte *param_1,byte *param_2)



{

  byte bVar1;

  int iVar2;

  byte abStack_28 [32];

  

  abStack_28[0x1c] = 0;

  abStack_28[0x1d] = 0;

  abStack_28[0x1e] = 0;

  abStack_28[0x1f] = 0;

  abStack_28[0x18] = 0;

  abStack_28[0x19] = 0;

  abStack_28[0x1a] = 0;

  abStack_28[0x1b] = 0;

  abStack_28[0x14] = 0;

  abStack_28[0x15] = 0;

  abStack_28[0x16] = 0;

  abStack_28[0x17] = 0;

  abStack_28[0x10] = 0;

  abStack_28[0x11] = 0;

  abStack_28[0x12] = 0;

  abStack_28[0x13] = 0;

  abStack_28[0xc] = 0;

  abStack_28[0xd] = 0;

  abStack_28[0xe] = 0;

  abStack_28[0xf] = 0;

  abStack_28[8] = 0;

  abStack_28[9] = 0;

  abStack_28[10] = 0;

  abStack_28[0xb] = 0;

  abStack_28[4] = 0;

  abStack_28[5] = 0;

  abStack_28[6] = 0;

  abStack_28[7] = 0;

  abStack_28[0] = 0;

  abStack_28[1] = 0;

  abStack_28[2] = 0;

  abStack_28[3] = 0;

  while( true ) {

    bVar1 = *param_2;

    if (bVar1 == 0) break;

    param_2 = param_2 + 1;

    abStack_28[(int)(uint)bVar1 >> 3] = abStack_28[(int)(uint)bVar1 >> 3] | '\x01' << (bVar1 & 7);

  }

  iVar2 = -1;

  do {

    iVar2 = iVar2 + 1;

    bVar1 = *param_1;

    if (bVar1 == 0) {

      return iVar2;

    }

    param_1 = param_1 + 1;

  } while ((abStack_28[(int)(uint)bVar1 >> 3] >> (bVar1 & 7) & 1) == 0);

  return iVar2;

}

/* ===== FUN_0054e3e0 @ 0x0054E3E0 ===== */
byte * FUN_0054e3e0(byte *param_1,byte *param_2)



{

  byte bVar1;

  byte *pbVar2;

  byte abStack_28 [32];

  

  abStack_28[0x1c] = 0;

  abStack_28[0x1d] = 0;

  abStack_28[0x1e] = 0;

  abStack_28[0x1f] = 0;

  abStack_28[0x18] = 0;

  abStack_28[0x19] = 0;

  abStack_28[0x1a] = 0;

  abStack_28[0x1b] = 0;

  abStack_28[0x14] = 0;

  abStack_28[0x15] = 0;

  abStack_28[0x16] = 0;

  abStack_28[0x17] = 0;

  abStack_28[0x10] = 0;

  abStack_28[0x11] = 0;

  abStack_28[0x12] = 0;

  abStack_28[0x13] = 0;

  abStack_28[0xc] = 0;

  abStack_28[0xd] = 0;

  abStack_28[0xe] = 0;

  abStack_28[0xf] = 0;

  abStack_28[8] = 0;

  abStack_28[9] = 0;

  abStack_28[10] = 0;

  abStack_28[0xb] = 0;

  abStack_28[4] = 0;

  abStack_28[5] = 0;

  abStack_28[6] = 0;

  abStack_28[7] = 0;

  abStack_28[0] = 0;

  abStack_28[1] = 0;

  abStack_28[2] = 0;

  abStack_28[3] = 0;

  while( true ) {

    bVar1 = *param_2;

    if (bVar1 == 0) break;

    param_2 = param_2 + 1;

    abStack_28[(int)(uint)bVar1 >> 3] = abStack_28[(int)(uint)bVar1 >> 3] | '\x01' << (bVar1 & 7);

  }

  do {

    pbVar2 = param_1;

    bVar1 = *pbVar2;

    if (bVar1 == 0) {

      return (byte *)0x0;

    }

    param_1 = pbVar2 + 1;

  } while ((abStack_28[(int)(uint)bVar1 >> 3] >> (bVar1 & 7) & 1) == 0);

  return pbVar2;

}

/* ===== crt_lock_54e41a @ 0x0054E41A ===== */
void crt_lock_54e41a(void)



{

  if (DAT_00630ea8 == 0) {

    _lock(0xb);

    if (DAT_00630ea8 == 0) {

      crt_strcpy_lock();

      DAT_00630ea8 = DAT_00630ea8 + 1;

    }

    _unlock(0xb);

  }

  return;

}

/* ===== crt_strcpy_lock @ 0x0054E448 ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void crt_strcpy_lock(void)



{

  char cVar1;

  char cVar2;

  char *_Str1;

  DWORD DVar3;

  int iVar4;

  size_t sVar5;

  char *_Source;

  int local_8;

  

  _lock(0xc);

  DAT_00583c68 = 0xffffffff;

  DAT_00583c58 = 0xffffffff;

  DAT_00630df0 = 0;

  _Str1 = (char *)FUN_0054f607(&DAT_005528fc);

  if (_Str1 == (char *)0x0) {

    _unlock(0xc);

    DVar3 = GetTimeZoneInformation((LPTIME_ZONE_INFORMATION)&DAT_00630df8);

    if (DVar3 == 0xffffffff) {

      return;

    }

    DAT_00583bc0 = DAT_00630df8 * 0x3c;

    DAT_00630df0 = 1;

    if (DAT_00630e3e != 0) {

      DAT_00583bc0 = DAT_00583bc0 + DAT_00630e4c * 0x3c;

    }

    if ((DAT_00630e92 == 0) || (DAT_00630ea0 == 0)) {

      DAT_00583bc4 = 0;

      _DAT_00583bc8 = 0;

    }

    else {

      DAT_00583bc4 = 1;

      _DAT_00583bc8 = (DAT_00630ea0 - DAT_00630e4c) * 0x3c;

    }

    iVar4 = WideCharToMultiByte(DAT_00630c6c,0x220,(LPCWSTR)&DAT_00630dfc,-1,PTR_DAT_00583c4c,0x3f,

                                (LPCSTR)0x0,&local_8);

    if ((iVar4 == 0) || (local_8 != 0)) {

      *PTR_DAT_00583c4c = 0;

    }

    else {

      PTR_DAT_00583c4c[0x3f] = 0;

    }

    iVar4 = WideCharToMultiByte(DAT_00630c6c,0x220,(LPCWSTR)&DAT_00630e50,-1,PTR_DAT_00583c50,0x3f,

                                (LPCSTR)0x0,&local_8);

    if ((iVar4 != 0) && (local_8 == 0)) {

      PTR_DAT_00583c50[0x3f] = 0;

      return;

    }

LAB_0054e6b9:

    *PTR_DAT_00583c50 = 0;

  }

  else {

    if ((*_Str1 != '\0') &&

       ((DAT_00630ea4 == (char *)0x0 || (iVar4 = _strcmp(_Str1,DAT_00630ea4), iVar4 != 0)))) {

      crt_free_ext(DAT_00630ea4);

      sVar5 = _strlen(_Str1);

      DAT_00630ea4 = _malloc(sVar5 + 1);

      if (DAT_00630ea4 != (char *)0x0) {

        strcpy(DAT_00630ea4,_Str1);

        _unlock(0xc);

        _strncpy(PTR_DAT_00583c4c,_Str1,3);

        _Source = _Str1 + 3;

        PTR_DAT_00583c4c[3] = 0;

        cVar1 = *_Source;

        if (cVar1 == '-') {

          _Source = _Str1 + 4;

        }

        iVar4 = FUN_00544198(_Source);

        DAT_00583bc0 = iVar4 * 0xe10;

        for (; (cVar2 = *_Source, cVar2 == '+' || (('/' < cVar2 && (cVar2 < ':'))));

            _Source = _Source + 1) {

        }

        if (*_Source == ':') {

          _Source = _Source + 1;

          iVar4 = FUN_00544198(_Source);

          DAT_00583bc0 = DAT_00583bc0 + iVar4 * 0x3c;

          for (; ('/' < *_Source && (*_Source < ':')); _Source = _Source + 1) {

          }

          if (*_Source == ':') {

            _Source = _Source + 1;

            iVar4 = FUN_00544198(_Source);

            DAT_00583bc0 = DAT_00583bc0 + iVar4;

            for (; ('/' < *_Source && (*_Source < ':')); _Source = _Source + 1) {

            }

          }

        }

        if (cVar1 == '-') {

          DAT_00583bc0 = -DAT_00583bc0;

        }

        DAT_00583bc4 = (int)*_Source;

        if (DAT_00583bc4 != 0) {

          _strncpy(PTR_DAT_00583c50,_Source,3);

          PTR_DAT_00583c50[3] = 0;

          return;

        }

        goto LAB_0054e6b9;

      }

    }

    _unlock(0xc);

  }

  return;

}

/* ===== crt_lock_54e6cf @ 0x0054E6CF ===== */
undefined4 crt_lock_54e6cf(undefined4 param_1)



{

  undefined4 uVar1;

  

  _lock(0xb);

  uVar1 = crt_tzset_dst(param_1);

  _unlock(0xb);

  return uVar1;

}

/* ===== crt_tzset_dst @ 0x0054E6F0 ===== */
bool crt_tzset_dst(int *param_1)



{

  int iVar1;

  int iVar2;

  undefined2 uVar3;

  undefined2 uVar4;

  undefined2 uVar5;

  

  if (DAT_00583bc4 != 0) {

    iVar2 = param_1[5];

    if ((iVar2 != DAT_00583c58) || (iVar2 != DAT_00583c68)) {

      if (DAT_00630df0 == 0) {

        crt_tz_rule_eval(1,1,iVar2,4,1,0,0,2,0,0,0);

        crt_tz_rule_eval(0,1,param_1[5],10,5,0,0,2,0,0,0);

      }

      else {

        if (DAT_00630e90 != 0) {

          uVar4 = 0;

          uVar3 = 0;

          uVar5 = DAT_00630e96;

        }

        else {

          uVar4 = DAT_00630e94;

          uVar3 = DAT_00630e96;

          uVar5 = 0;

        }

        crt_tz_rule_eval(1,DAT_00630e90 == 0,iVar2,DAT_00630e92,uVar3,uVar4,uVar5,DAT_00630e98,

                         DAT_00630e9a,DAT_00630e9c,DAT_00630e9e);

        if (DAT_00630e3c != 0) {

          uVar4 = 0;

          uVar3 = 0;

          iVar2 = param_1[5];

          uVar5 = DAT_00630e42;

        }

        else {

          iVar2 = param_1[5];

          uVar4 = DAT_00630e40;

          uVar3 = DAT_00630e42;

          uVar5 = 0;

        }

        crt_tz_rule_eval(0,DAT_00630e3c == 0,iVar2,DAT_00630e3e,uVar3,uVar4,uVar5,DAT_00630e44,

                         DAT_00630e46,DAT_00630e48,DAT_00630e4a);

      }

    }

    iVar2 = param_1[7];

    if (DAT_00583c5c < DAT_00583c6c) {

      if ((DAT_00583c5c <= iVar2) && (iVar2 <= DAT_00583c6c)) {

        if ((DAT_00583c5c < iVar2) && (iVar2 < DAT_00583c6c)) {

          return true;

        }

LAB_0054e868:

        iVar1 = ((param_1[2] * 0x3c + param_1[1]) * 0x3c + *param_1) * 1000;

        if (iVar2 == DAT_00583c5c) {

          return DAT_00583c60 <= iVar1;

        }

        return iVar1 < DAT_00583c70;

      }

    }

    else {

      if (iVar2 < DAT_00583c6c) {

        return true;

      }

      if (DAT_00583c5c < iVar2) {

        return true;

      }

      if ((iVar2 <= DAT_00583c6c) || (DAT_00583c5c <= iVar2)) goto LAB_0054e868;

    }

  }

  return false;

}

/* ===== crt_tz_rule_eval @ 0x0054E89C ===== */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void crt_tz_rule_eval(int param_1,int param_2,uint param_3,int param_4,int param_5,int param_6,

                     int param_7,int param_8,int param_9,int param_10,int param_11)



{

  int iVar1;

  int iVar2;

  

  if (param_2 == 1) {

    if ((param_3 & 3) == 0) {

      iVar1 = (&DAT_00583c70)[param_4];

    }

    else {

      iVar1 = *(int *)(&DAT_00583ca4 + param_4 * 4);

    }

    iVar2 = (int)(param_3 * 0x16d + -0x63db + iVar1 + 1 + ((int)(param_3 - 1) >> 2)) % 7;

    if (param_6 < iVar2) {

      iVar1 = iVar1 + 1 + (param_5 * 7 - iVar2) + param_6;

    }

    else {

      iVar1 = iVar1 + -6 + (param_5 * 7 - iVar2) + param_6;

    }

    if (param_5 == 5) {

      if ((param_3 & 3) == 0) {

        iVar2 = *(int *)(&DAT_00583c74 + param_4 * 4);

      }

      else {

        iVar2 = *(int *)(&DAT_00583ca8 + param_4 * 4);

      }

      if (iVar2 < iVar1) {

        iVar1 = iVar1 + -7;

      }

    }

  }

  else {

    if ((param_3 & 3) == 0) {

      iVar1 = (&DAT_00583c70)[param_4];

    }

    else {

      iVar1 = *(int *)(&DAT_00583ca4 + param_4 * 4);

    }

    iVar1 = iVar1 + param_7;

  }

  if (param_1 == 1) {

    DAT_00583c58 = param_3;

    DAT_00583c60 = ((param_8 * 0x3c + param_9) * 0x3c + param_10) * 1000 + param_11;

    DAT_00583c5c = iVar1;

  }

  else {

    DAT_00583c70 = ((param_8 * 0x3c + param_9) * 0x3c + _DAT_00583bc8 + param_10) * 1000 + param_11;

    if (DAT_00583c70 < 0) {

      DAT_00583c70 = DAT_00583c70 + 86400000;

      DAT_00583c6c = iVar1 + -1;

    }

    else {

      DAT_00583c6c = iVar1;

      if (86399999 < DAT_00583c70) {

        DAT_00583c70 = DAT_00583c70 + -86400000;

        DAT_00583c6c = iVar1 + 1;

      }

    }

    DAT_00583c68 = param_3;

  }

  return;

}

/* ===== BinFileCreateWrite_5 @ 0x0054E9DC ===== */
void BinFileCreateWrite_5(undefined4 param_1)



{

  FUN_0054e9ed(param_1,0,4);

  return;

}

/* ===== FUN_0054e9ed @ 0x0054E9ED ===== */
undefined4 FUN_0054e9ed(byte param_1,uint param_2,byte param_3)



{

  if ((*(byte *)((int)&DAT_006577a0 + param_1 + 1) & param_3) == 0) {

    if (param_2 == 0) {

      param_2 = 0;

    }

    else {

      param_2 = *(ushort *)(&DAT_00580eb6 + (uint)param_1 * 2) & param_2;

    }

    if (param_2 == 0) {

      return 0;

    }

  }

  return 1;

}

/* ===== crt_lock_54ea1e @ 0x0054EA1E ===== */
undefined4 crt_lock_54ea1e(undefined4 param_1)



{

  BYTE *pBVar1;

  byte *pbVar2;

  byte bVar3;

  byte bVar4;

  UINT CodePage;

  UINT *pUVar5;

  BOOL BVar6;

  uint uVar7;

  uint uVar8;

  BYTE *pBVar9;

  int iVar10;

  byte *pbVar11;

  int iVar12;

  byte *pbVar13;

  undefined4 uVar14;

  undefined4 *puVar15;

  _cpinfo local_1c;

  uint local_8;

  

  _lock(0x19);

  CodePage = FUN_0054ebcb(param_1);

  if (CodePage != DAT_0065767c) {

    if (CodePage != 0) {

      iVar12 = 0;

      pUVar5 = &DAT_00583ce8;

LAB_0054ea5b:

      if (*pUVar5 != CodePage) goto code_r0x0054ea5f;

      local_8 = 0;

      puVar15 = &DAT_006577a0;

      for (iVar10 = 0x40; iVar10 != 0; iVar10 = iVar10 + -1) {

        *puVar15 = 0;

        puVar15 = puVar15 + 1;

      }

      iVar12 = iVar12 * 0x30;

      *(undefined1 *)puVar15 = 0;

      pbVar13 = (byte *)(iVar12 + 0x583cf8);

      do {

        bVar3 = *pbVar13;

        pbVar11 = pbVar13;

        while ((bVar3 != 0 && (bVar3 = pbVar11[1], bVar3 != 0))) {

          uVar8 = (uint)*pbVar11;

          if (uVar8 <= bVar3) {

            bVar4 = (&DAT_00583ce0)[local_8];

            do {

              pbVar2 = (byte *)((int)&DAT_006577a0 + uVar8 + 1);

              *pbVar2 = *pbVar2 | bVar4;

              uVar8 = uVar8 + 1;

            } while (uVar8 <= bVar3);

          }

          pbVar11 = pbVar11 + 2;

          bVar3 = *pbVar11;

        }

        local_8 = local_8 + 1;

        pbVar13 = pbVar13 + 8;

      } while (local_8 < 4);

      DAT_0065768c = 1;

      DAT_0065767c = CodePage;

      DAT_006578a4 = FUN_0054ec15(CodePage);

      DAT_00657680 = *(undefined4 *)(iVar12 + 0x583cec);

      DAT_00657684 = *(undefined4 *)(iVar12 + 0x583cf0);

      DAT_00657688 = *(undefined4 *)(iVar12 + 0x583cf4);

      goto LAB_0054ebaf;

    }

    goto LAB_0054ebaa;

  }

  goto LAB_0054ea45;

code_r0x0054ea5f:

  pUVar5 = pUVar5 + 0xc;

  iVar12 = iVar12 + 1;

  if ((UINT *)0x583dd7 < pUVar5) goto code_r0x0054ea6a;

  goto LAB_0054ea5b;

code_r0x0054ea6a:

  BVar6 = GetCPInfo(CodePage,&local_1c);

  uVar8 = 1;

  if (BVar6 == 1) {

    DAT_006578a4 = 0;

    puVar15 = &DAT_006577a0;

    for (iVar12 = 0x40; iVar12 != 0; iVar12 = iVar12 + -1) {

      *puVar15 = 0;

      puVar15 = puVar15 + 1;

    }

    *(undefined1 *)puVar15 = 0;

    if (local_1c.MaxCharSize < 2) {

      DAT_0065768c = 0;

      DAT_0065767c = CodePage;

    }

    else {

      DAT_0065767c = CodePage;

      if (local_1c.LeadByte[0] != '\0') {

        pBVar9 = local_1c.LeadByte + 1;

        do {

          bVar3 = *pBVar9;

          if (bVar3 == 0) break;

          for (uVar7 = (uint)pBVar9[-1]; uVar7 <= bVar3; uVar7 = uVar7 + 1) {

            pbVar13 = (byte *)((int)&DAT_006577a0 + uVar7 + 1);

            *pbVar13 = *pbVar13 | 4;

          }

          pBVar1 = pBVar9 + 1;

          pBVar9 = pBVar9 + 2;

        } while (*pBVar1 != 0);

      }

      do {

        pbVar13 = (byte *)((int)&DAT_006577a0 + uVar8 + 1);

        *pbVar13 = *pbVar13 | 8;

        uVar8 = uVar8 + 1;

      } while (uVar8 < 0xff);

      DAT_006578a4 = FUN_0054ec15(CodePage);

      DAT_0065768c = 1;

    }

    DAT_00657680 = 0;

    DAT_00657684 = 0;

    DAT_00657688 = 0;

  }

  else {

    if (DAT_00630eac == 0) {

      uVar14 = 0xffffffff;

      goto LAB_0054ebbc;

    }

LAB_0054ebaa:

    FUN_0054ec48();

  }

LAB_0054ebaf:

  crt_getstringtype_full();

LAB_0054ea45:

  uVar14 = 0;

LAB_0054ebbc:

  _unlock(0x19);

  return uVar14;

}

/* ===== FUN_0054ebcb @ 0x0054EBCB ===== */
int FUN_0054ebcb(int param_1)



{

  int iVar1;

  bool bVar2;

  

  if (param_1 == -2) {

    DAT_00630eac = 1;

                    /* WARNING: Could not recover jumptable at 0x0054ebe5. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    iVar1 = GetOEMCP();

    return iVar1;

  }

  if (param_1 == -3) {

    DAT_00630eac = 1;

                    /* WARNING: Could not recover jumptable at 0x0054ebfa. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    iVar1 = GetACP();

    return iVar1;

  }

  bVar2 = param_1 == -4;

  if (bVar2) {

    param_1 = DAT_00630c6c;

  }

  DAT_00630eac = (uint)bVar2;

  return param_1;

}

/* ===== FUN_0054ec15 @ 0x0054EC15 ===== */
undefined4 FUN_0054ec15(int param_1)



{

  if (param_1 == 0x3a4) {

    return 0x411;

  }

  if (param_1 == 0x3a8) {

    return 0x804;

  }

  if (param_1 == 0x3b5) {

    return 0x412;

  }

  if (param_1 != 0x3b6) {

    return 0;

  }

  return 0x404;

}

/* ===== FUN_0054ec48 @ 0x0054EC48 ===== */
void FUN_0054ec48(void)



{

  int iVar1;

  undefined4 *puVar2;

  

  puVar2 = &DAT_006577a0;

  for (iVar1 = 0x40; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar2 = 0;

    puVar2 = puVar2 + 1;

  }

  *(undefined1 *)puVar2 = 0;

  DAT_0065767c = 0;

  DAT_0065768c = 0;

  DAT_006578a4 = 0;

  DAT_00657680 = 0;

  DAT_00657684 = 0;

  DAT_00657688 = 0;

  return;

}

/* ===== crt_getstringtype_full @ 0x0054EC71 ===== */
void crt_getstringtype_full(void)



{

  byte *pbVar1;

  BOOL BVar2;

  uint uVar3;

  char cVar4;

  uint uVar5;

  uint uVar6;

  ushort *puVar7;

  undefined1 uVar8;

  BYTE *pBVar9;

  undefined4 *puVar10;

  ushort local_518 [256];

  undefined1 local_318 [256];

  undefined1 local_218 [256];

  undefined4 local_118 [64];

  _cpinfo local_18;

  

  BVar2 = GetCPInfo(DAT_0065767c,&local_18);

  if (BVar2 == 1) {

    uVar3 = 0;

    do {

      *(char *)((int)local_118 + uVar3) = (char)uVar3;

      uVar3 = uVar3 + 1;

    } while (uVar3 < 0x100);

    local_118[0]._0_1_ = 0x20;

    if (local_18.LeadByte[0] != 0) {

      pBVar9 = local_18.LeadByte + 1;

      do {

        uVar3 = (uint)local_18.LeadByte[0];

        if (uVar3 <= *pBVar9) {

          uVar5 = (*pBVar9 - uVar3) + 1;

          puVar10 = (undefined4 *)((int)local_118 + uVar3);

          for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {

            *puVar10 = 0x20202020;

            puVar10 = puVar10 + 1;

          }

          for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {

            *(undefined1 *)puVar10 = 0x20;

            puVar10 = (undefined4 *)((int)puVar10 + 1);

          }

        }

        local_18.LeadByte[0] = pBVar9[1];

        pBVar9 = pBVar9 + 2;

      } while (local_18.LeadByte[0] != 0);

    }

    crt_getstringtype(1,local_118,0x100,local_518,DAT_0065767c,DAT_006578a4,0);

    crt_lcmapstring(DAT_006578a4,0x100,local_118,0x100,local_218,0x100,DAT_0065767c,0);

    crt_lcmapstring(DAT_006578a4,0x200,local_118,0x100,local_318,0x100,DAT_0065767c,0);

    uVar3 = 0;

    puVar7 = local_518;

    do {

      if ((*puVar7 & 1) == 0) {

        if ((*puVar7 & 2) != 0) {

          pbVar1 = (byte *)((int)&DAT_006577a0 + uVar3 + 1);

          *pbVar1 = *pbVar1 | 0x20;

          uVar8 = local_318[uVar3];

          goto LAB_0054ed7d;

        }

        (&DAT_006576a0)[uVar3] = 0;

      }

      else {

        pbVar1 = (byte *)((int)&DAT_006577a0 + uVar3 + 1);

        *pbVar1 = *pbVar1 | 0x10;

        uVar8 = local_218[uVar3];

LAB_0054ed7d:

        (&DAT_006576a0)[uVar3] = uVar8;

      }

      uVar3 = uVar3 + 1;

      puVar7 = puVar7 + 1;

    } while (uVar3 < 0x100);

  }

  else {

    uVar3 = 0;

    do {

      if ((uVar3 < 0x41) || (0x5a < uVar3)) {

        if ((0x60 < uVar3) && (uVar3 < 0x7b)) {

          pbVar1 = (byte *)((int)&DAT_006577a0 + uVar3 + 1);

          *pbVar1 = *pbVar1 | 0x20;

          cVar4 = (char)uVar3 + -0x20;

          goto LAB_0054edc7;

        }

        (&DAT_006576a0)[uVar3] = 0;

      }

      else {

        pbVar1 = (byte *)((int)&DAT_006577a0 + uVar3 + 1);

        *pbVar1 = *pbVar1 | 0x10;

        cVar4 = (char)uVar3 + ' ';

LAB_0054edc7:

        (&DAT_006576a0)[uVar3] = cVar4;

      }

      uVar3 = uVar3 + 1;

    } while (uVar3 < 0x100);

  }

  return;

}

/* ===== FUN_0054edf6 @ 0x0054EDF6 ===== */
void FUN_0054edf6(void)



{

  if (DAT_00658a08 == 0) {

    crt_lock_54ea1e(0xfffffffd);

    DAT_00658a08 = 1;

  }

  return;

}

/* ===== FUN_0054ee12 @ 0x0054EE12 ===== */
undefined4 FUN_0054ee12(uint param_1,uint param_2,uint *param_3)



{

  uint uVar1;

  undefined4 uVar2;

  

  uVar2 = 0;

  uVar1 = param_1 + param_2;

  if ((uVar1 < param_1) || (uVar1 < param_2)) {

    uVar2 = 1;

  }

  *param_3 = uVar1;

  return uVar2;

}

/* ===== ___add_12 @ 0x0054EE33 ===== */
/* Library Function - Single Match

    ___add_12

   

   Library: Visual Studio 2003 Release */



void ___add_12(undefined4 *param_1,undefined4 *param_2)



{

  int iVar1;

  

  iVar1 = FUN_0054ee12(*param_1,*param_2,param_1);

  if (iVar1 != 0) {

    iVar1 = FUN_0054ee12(param_1[1],1,param_1 + 1);

    if (iVar1 != 0) {

      param_1[2] = param_1[2] + 1;

    }

  }

  iVar1 = FUN_0054ee12(param_1[1],param_2[1],param_1 + 1);

  if (iVar1 != 0) {

    param_1[2] = param_1[2] + 1;

  }

  FUN_0054ee12(param_1[2],param_2[2],param_1 + 2);

  return;

}

/* ===== FUN_0054ee91 @ 0x0054EE91 ===== */
void FUN_0054ee91(uint *param_1)



{

  uint uVar1;

  uint uVar2;

  

  uVar1 = *param_1;

  uVar2 = param_1[1];

  *param_1 = uVar1 * 2;

  param_1[1] = uVar2 * 2 | uVar1 >> 0x1f;

  param_1[2] = param_1[2] << 1 | uVar2 >> 0x1f;

  return;

}

/* ===== FUN_0054eebf @ 0x0054EEBF ===== */
void FUN_0054eebf(uint *param_1)



{

  uint uVar1;

  

  uVar1 = param_1[1];

  param_1[1] = uVar1 >> 1 | param_1[2] << 0x1f;

  param_1[2] = param_1[2] >> 1;

  *param_1 = *param_1 >> 1 | uVar1 << 0x1f;

  return;

}

/* ===== FUN_0054eeec @ 0x0054EEEC ===== */
void FUN_0054eeec(char *param_1,int param_2,uint *param_3)



{

  uint *puVar1;

  uint local_14;

  uint local_10;

  uint local_c;

  int local_8;

  

  puVar1 = param_3;

  local_8 = 0x404e;

  *param_3 = 0;

  param_3[1] = 0;

  param_3[2] = 0;

  if (param_2 != 0) {

    param_3 = (uint *)param_2;

    do {

      local_14 = *puVar1;

      local_10 = puVar1[1];

      local_c = puVar1[2];

      FUN_0054ee91(puVar1);

      FUN_0054ee91(puVar1);

      ___add_12(puVar1,&local_14);

      FUN_0054ee91(puVar1);

      local_10 = 0;

      local_c = 0;

      local_14 = (uint)*param_1;

      ___add_12(puVar1,&local_14);

      param_1 = param_1 + 1;

      param_3 = (uint *)((int)param_3 + -1);

    } while (param_3 != (uint *)0x0);

  }

  while (puVar1[2] == 0) {

    puVar1[2] = puVar1[1] >> 0x10;

    local_8 = local_8 + 0xfff0;

    puVar1[1] = *puVar1 >> 0x10 | puVar1[1] << 0x10;

    *puVar1 = *puVar1 << 0x10;

  }

  while ((puVar1[2] & 0x8000) == 0) {

    FUN_0054ee91(puVar1);

    local_8 = local_8 + 0xffff;

  }

  *(undefined2 *)((int)puVar1 + 10) = (undefined2)local_8;

  return;

}

/* ===== crt_fltout @ 0x0054EFB3 ===== */
undefined4 crt_fltout(int param_1,uint param_2,uint param_3,int param_4,byte param_5,short *param_6)



{

  short *psVar1;

  short *psVar2;

  char cVar3;

  uint uVar4;

  short *psVar5;

  short *psVar6;

  short sVar7;

  int iVar8;

  int iVar9;

  char *pcVar10;

  undefined1 local_20;

  undefined1 local_1f;

  undefined1 local_1e;

  undefined1 local_1d;

  undefined1 local_1c;

  undefined1 local_1b;

  undefined1 local_1a;

  undefined1 local_19;

  undefined1 local_18;

  undefined1 local_17;

  undefined1 local_16;

  undefined1 local_15;

  undefined2 local_14;

  undefined2 local_12;

  undefined2 uStack_10;

  undefined2 local_e;

  undefined2 uStack_c;

  undefined1 local_a;

  char cStack_9;

  undefined4 local_8;

  

  psVar2 = param_6;

  uVar4 = param_3 & 0x7fff;

  local_20 = 0xcc;

  local_1f = 0xcc;

  local_1e = 0xcc;

  local_1d = 0xcc;

  local_1c = 0xcc;

  local_1b = 0xcc;

  local_1a = 0xcc;

  local_19 = 0xcc;

  local_18 = 0xcc;

  local_17 = 0xcc;

  local_16 = 0xfb;

  local_15 = 0x3f;

  local_8 = 1;

  if ((param_3 & 0x8000) == 0) {

    *(undefined1 *)(param_6 + 1) = 0x20;

  }

  else {

    *(undefined1 *)(param_6 + 1) = 0x2d;

  }

  if ((((short)uVar4 != 0) || (param_2 != 0)) || (param_1 != 0)) {

    if ((short)uVar4 == 0x7fff) {

      *param_6 = 1;

      if (((param_2 == 0x80000000) && (param_1 == 0)) || ((param_2 & 0x40000000) != 0)) {

        if (((param_3 & 0x8000) == 0) || (param_2 != 0xc0000000)) {

          if ((param_2 != 0x80000000) || (param_1 != 0)) goto LAB_0054f0a8;

          pcVar10 = "1#INF";

        }

        else {

          if (param_1 != 0) {

LAB_0054f0a8:

            pcVar10 = "1#QNAN";

            goto LAB_0054f0ad;

          }

          pcVar10 = "1#IND";

        }

        strcpy(param_6 + 2,pcVar10);

        *(undefined1 *)((int)psVar2 + 3) = 5;

      }

      else {

        pcVar10 = "1#SNAN";

LAB_0054f0ad:

        strcpy(param_6 + 2,pcVar10);

        *(undefined1 *)((int)psVar2 + 3) = 6;

      }

      return 0;

    }

    local_14 = 0;

    local_a = (undefined1)uVar4;

    cStack_9 = (char)(uVar4 >> 8);

    local_e = (undefined2)param_2;

    uStack_c = (undefined2)(param_2 >> 0x10);

    local_12 = (undefined2)param_1;

    uStack_10 = (undefined2)((uint)param_1 >> 0x10);

    sVar7 = (short)(((uVar4 >> 8) + (param_2 >> 0x18) * 2) * 0x4d + -0x134312f4 + uVar4 * 0x4d10 >>

                   0x10);

    FUN_0054f58b(&local_14,-(int)sVar7,1);

    if (0x3ffe < CONCAT11(cStack_9,local_a)) {

      sVar7 = sVar7 + 1;

      FUN_0054f36b(&local_14,&local_20);

    }

    *psVar2 = sVar7;

    iVar9 = param_4;

    if (((param_5 & 1) == 0) || (iVar9 = param_4 + sVar7, 0 < param_4 + sVar7)) {

      if (0x15 < iVar9) {

        iVar9 = 0x15;

      }

      iVar8 = CONCAT11(cStack_9,local_a) - 0x3ffe;

      local_a = 0;

      cStack_9 = '\0';

      param_6 = (short *)0x8;

      do {

        FUN_0054ee91(&local_14);

        param_6 = (short *)((int)param_6 + -1);

      } while (param_6 != (short *)0x0);

      if (iVar8 < 0) {

        param_6 = (short *)0x0;

        for (uVar4 = -iVar8 & 0xff; uVar4 != 0; uVar4 = uVar4 - 1) {

          FUN_0054eebf(&local_14);

        }

      }

      param_4 = iVar9 + 1;

      psVar5 = psVar2 + 2;

      param_6 = psVar5;

      if (0 < param_4) {

        do {

          param_1 = CONCAT22(local_12,local_14);

          param_2 = CONCAT22(local_e,uStack_10);

          param_3 = CONCAT13(cStack_9,CONCAT12(local_a,uStack_c));

          FUN_0054ee91(&local_14);

          FUN_0054ee91(&local_14);

          ___add_12(&local_14,&param_1);

          FUN_0054ee91(&local_14);

          cVar3 = cStack_9;

          cStack_9 = '\0';

          psVar5 = (short *)((int)param_6 + 1);

          param_4 = param_4 + -1;

          *(char *)param_6 = cVar3 + '0';

          param_6 = psVar5;

        } while (param_4 != 0);

      }

      psVar6 = psVar5 + -1;

      psVar1 = psVar2 + 2;

      if ('4' < *(char *)((int)psVar5 + -1)) {

        for (; psVar1 <= psVar6; psVar6 = (short *)((int)psVar6 + -1)) {

          if ((char)*psVar6 != '9') {

            if (psVar1 <= psVar6) goto LAB_0054f205;

            break;

          }

          *(char *)psVar6 = '0';

        }

        psVar6 = (short *)((int)psVar6 + 1);

        *psVar2 = *psVar2 + 1;

LAB_0054f205:

        *(char *)psVar6 = (char)*psVar6 + '\x01';

LAB_0054f207:

        cVar3 = ((char)psVar6 - (char)psVar2) + -3;

        *(char *)((int)psVar2 + 3) = cVar3;

        *(undefined1 *)(cVar3 + 4 + (int)psVar2) = 0;

        return local_8;

      }

      for (; psVar1 <= psVar6; psVar6 = (short *)((int)psVar6 + -1)) {

        if ((char)*psVar6 != '0') {

          if (psVar1 <= psVar6) goto LAB_0054f207;

          break;

        }

      }

      *psVar2 = 0;

      *(undefined1 *)(psVar2 + 1) = 0x20;

      *(undefined1 *)((int)psVar2 + 3) = 1;

      *(char *)psVar1 = '0';

      goto LAB_0054f23d;

    }

  }

  *psVar2 = 0;

  *(undefined1 *)(psVar2 + 1) = 0x20;

  *(undefined1 *)((int)psVar2 + 3) = 1;

  *(undefined1 *)(psVar2 + 2) = 0x30;

LAB_0054f23d:

  *(undefined1 *)((int)psVar2 + 5) = 0;

  return 1;

}

/* ===== FUN_0054f246 @ 0x0054F246 ===== */
int FUN_0054f246(undefined4 param_1,int param_2)



{

  int iVar1;

  int *piVar2;

  undefined4 *puVar3;

  HANDLE hFile;

  BOOL BVar4;

  DWORD DVar5;

  DWORD *pDVar6;

  int iVar7;

  undefined1 local_1008 [4064];

  undefined4 uStackY_28;

  undefined4 uStackY_24;

  undefined4 uStackY_20;

  

  FUN_00543e00();

  iVar7 = 0;

  iVar1 = _lseek();

  if ((iVar1 == -1) || (iVar1 = _lseek(), iVar1 == -1)) {

    iVar7 = -1;

  }

  else {

    param_2 = param_2 - iVar1;

    if (param_2 < 1) {

      if (param_2 < 0) {

        uStackY_20 = 0x54f317;

        _lseek();

        uStackY_20 = param_1;

        uStackY_24 = 0x54f31f;

        hFile = (HANDLE)crt_validate_osfhnd();

        BVar4 = SetEndOfFile(hFile);

        iVar7 = (BVar4 != 0) - 1;

        if (iVar7 == -1) {

          puVar3 = (undefined4 *)_errno();

          *puVar3 = 0xd;

          DVar5 = GetLastError();

          pDVar6 = (DWORD *)__doserrno();

          *pDVar6 = DVar5;

        }

      }

    }

    else {

      uStackY_20 = 0x54f2a6;

      _memset(local_1008,0,0x1000);

      uStackY_20 = 0x8000;

      uStackY_24 = param_1;

      uStackY_28 = 0x54f2b3;

      crt_errno_user2();

      do {

        uStackY_20 = 0x54f2d1;

        iVar1 = _write_lk();

        if (iVar1 == -1) {

          piVar2 = (int *)__doserrno();

          if (*piVar2 == 5) {

            puVar3 = (undefined4 *)_errno();

            *puVar3 = 0xd;

          }

          iVar7 = -1;

          break;

        }

        param_2 = param_2 - iVar1;

      } while (0 < param_2);

      crt_errno_user2();

    }

    uStackY_20 = 0x54f35d;

    _lseek();

  }

  return iVar7;

}

/* ===== FUN_0054f36b @ 0x0054F36B ===== */
void FUN_0054f36b(int *param_1,int *param_2)



{

  short sVar1;

  int iVar2;

  ushort uVar3;

  int *piVar4;

  int *piVar5;

  ushort uVar6;

  int iVar7;

  ushort uVar8;

  ushort uVar9;

  byte local_28;

  undefined1 uStack_27;

  undefined2 uStack_26;

  short local_24;

  undefined2 uStack_22;

  undefined2 local_20;

  undefined1 uStack_1e;

  byte bStack_1d;

  int local_1c;

  int local_18;

  int local_14;

  ushort *local_10;

  ushort *local_c;

  short *local_8;

  

  piVar5 = param_2;

  piVar4 = param_1;

  local_18 = 0;

  local_28 = 0;

  uStack_27 = 0;

  uStack_26 = 0;

  local_24 = 0;

  uStack_22 = 0;

  local_20 = 0;

  uStack_1e = 0;

  bStack_1d = 0;

  uVar6 = *(ushort *)((int)param_1 + 10) & 0x7fff;

  uVar8 = *(ushort *)((int)param_2 + 10) & 0x7fff;

  uVar9 = (*(ushort *)((int)param_2 + 10) ^ *(ushort *)((int)param_1 + 10)) & 0x8000;

  uVar3 = uVar8 + uVar6;

  if (((uVar6 < 0x7fff) && (uVar8 < 0x7fff)) && (uVar3 < 0xbffe)) {

    if (uVar3 < 0x3fc0) {

LAB_0054f40e:

      param_1[2] = 0;

      param_1[1] = 0;

      *param_1 = 0;

      return;

    }

    if (((uVar6 != 0) || (uVar3 = uVar3 + 1, (param_1[2] & 0x7fffffffU) != 0)) ||

       ((uVar6 = 0, param_1[1] != 0 || (*param_1 != 0)))) {

      if (((uVar8 == 0) && (uVar3 = uVar3 + 1, (param_2[2] & 0x7fffffffU) == 0)) &&

         ((param_2[1] == 0 && (*param_2 == 0)))) goto LAB_0054f40e;

      local_14 = 0;

      local_8 = &local_24;

      param_2 = (int *)0x5;

      do {

        if (0 < (int)param_2) {

          local_c = (ushort *)(local_14 * 2 + (int)param_1);

          local_10 = (ushort *)(piVar5 + 2);

          local_1c = (int)param_2;

          do {

            iVar7 = FUN_0054ee12(*(undefined4 *)(local_8 + -2),(uint)*local_c * (uint)*local_10,

                                 local_8 + -2);

            if (iVar7 != 0) {

              *local_8 = *local_8 + 1;

            }

            local_c = local_c + 1;

            local_10 = local_10 + -1;

            local_1c = local_1c + -1;

          } while (local_1c != 0);

        }

        local_8 = local_8 + 1;

        local_14 = local_14 + 1;

        param_2 = (int *)((int)param_2 + -1);

      } while (0 < (int)param_2);

      param_1._0_2_ = uVar3 + 0xc002;

      if ((short)(ushort)param_1 < 1) {

LAB_0054f4c2:

        param_1._0_2_ = (ushort)param_1 - 1;

        if ((short)(ushort)param_1 < 0) {

          iVar7 = -(int)(short)(ushort)param_1;

          param_1._0_2_ = (ushort)param_1 + (short)iVar7;

          do {

            if ((local_28 & 1) != 0) {

              local_18 = local_18 + 1;

            }

            FUN_0054eebf(&local_28);

            iVar7 = iVar7 + -1;

          } while (iVar7 != 0);

          if (local_18 != 0) {

            local_28 = local_28 | 1;

          }

        }

      }

      else {

        do {

          if ((bStack_1d & 0x80) != 0) break;

          FUN_0054ee91(&local_28);

          param_1._0_2_ = (ushort)param_1 - 1;

        } while (0 < (short)(ushort)param_1);

        if ((short)(ushort)param_1 < 1) goto LAB_0054f4c2;

      }

      if ((0x8000 < CONCAT11(uStack_27,local_28)) ||

         (sVar1 = CONCAT11(bStack_1d,uStack_1e), iVar2 = CONCAT22(local_20,uStack_22),

         iVar7 = CONCAT22(local_24,uStack_26),

         (CONCAT22(uStack_26,CONCAT11(uStack_27,local_28)) & 0x1ffff) == 0x18000)) {

        if (CONCAT22(local_24,uStack_26) == -1) {

          iVar7 = 0;

          if (CONCAT22(local_20,uStack_22) == -1) {

            if (CONCAT11(bStack_1d,uStack_1e) == -1) {

              param_1._0_2_ = (ushort)param_1 + 1;

              sVar1 = -0x8000;

              iVar2 = 0;

              iVar7 = 0;

            }

            else {

              sVar1 = CONCAT11(bStack_1d,uStack_1e) + 1;

              iVar2 = 0;

              iVar7 = 0;

            }

          }

          else {

            sVar1 = CONCAT11(bStack_1d,uStack_1e);

            iVar2 = CONCAT22(local_20,uStack_22) + 1;

          }

        }

        else {

          iVar7 = CONCAT22(local_24,uStack_26) + 1;

          sVar1 = CONCAT11(bStack_1d,uStack_1e);

          iVar2 = CONCAT22(local_20,uStack_22);

        }

      }

      local_24 = (short)((uint)iVar7 >> 0x10);

      uStack_26 = (undefined2)iVar7;

      local_20 = (undefined2)((uint)iVar2 >> 0x10);

      uStack_22 = (undefined2)iVar2;

      bStack_1d = (byte)((ushort)sVar1 >> 8);

      uStack_1e = (undefined1)sVar1;

      if (0x7ffe < (ushort)param_1) goto LAB_0054f56b;

      uVar6 = (ushort)param_1 | uVar9;

      *(undefined2 *)piVar4 = uStack_26;

      *(uint *)((int)piVar4 + 2) = CONCAT22(uStack_22,local_24);

      *(uint *)((int)piVar4 + 6) = CONCAT13(bStack_1d,CONCAT12(uStack_1e,local_20));

    }

    *(ushort *)((int)piVar4 + 10) = uVar6;

  }

  else {

LAB_0054f56b:

    piVar4[1] = 0;

    *piVar4 = 0;

    piVar4[2] = (-(uint)(uVar9 != 0) & 0x80000000) + 0x7fff8000;

  }

  return;

}

/* ===== FUN_0054f58b @ 0x0054F58B ===== */
void FUN_0054f58b(undefined2 *param_1,uint param_2,int param_3)



{

  uint uVar1;

  uint uVar2;

  undefined **ppuVar3;

  undefined **ppuVar4;

  undefined2 local_10;

  undefined4 local_e;

  undefined2 uStack_a;

  undefined *puStack_8;

  

  ppuVar3 = &PTR_s_November_00583e70;

  if (param_2 != 0) {

    if ((int)param_2 < 0) {

      param_2 = -param_2;

      ppuVar3 = (undefined **)0x583fd0;

    }

    if (param_3 == 0) {

      *param_1 = 0;

    }

    while (param_2 != 0) {

      ppuVar3 = ppuVar3 + 0x15;

      uVar1 = (int)param_2 >> 3;

      uVar2 = param_2 & 7;

      param_2 = uVar1;

      if (uVar2 != 0) {

        ppuVar4 = ppuVar3 + uVar2 * 3;

        if (0x7fff < *(ushort *)(ppuVar3 + uVar2 * 3)) {

          local_10 = SUB42(*ppuVar4,0);

          local_e._0_2_ = (undefined2)((uint)*ppuVar4 >> 0x10);

          local_e._2_2_ = SUB42(ppuVar4[1],0);

          uStack_a = (undefined2)((uint)ppuVar4[1] >> 0x10);

          puStack_8 = ppuVar4[2];

          local_e = CONCAT22(local_e._2_2_,(undefined2)local_e) + -1;

          ppuVar4 = (undefined **)&local_10;

        }

        FUN_0054f36b(param_1,ppuVar4);

      }

    }

  }

  return;

}

/* ===== FUN_0054f607 @ 0x0054F607 ===== */
int FUN_0054f607(uchar *param_1)



{

  int iVar1;

  size_t _MaxCount;

  size_t sVar2;

  int *piVar3;

  

  if (((DAT_00658a04 != 0) &&

      ((DAT_00630b7c != (int *)0x0 ||

       (((DAT_00630b84 != 0 && (iVar1 = FUN_0054f724(), iVar1 == 0)) && (DAT_00630b7c != (int *)0x0)

        ))))) && (piVar3 = DAT_00630b7c, param_1 != (uchar *)0x0)) {

    _MaxCount = _strlen((char *)param_1);

    for (; (char *)*piVar3 != (char *)0x0; piVar3 = piVar3 + 1) {

      sVar2 = _strlen((char *)*piVar3);

      if (((_MaxCount < sVar2) && (((uchar *)*piVar3)[_MaxCount] == '=')) &&

         (iVar1 = crt_comparestring_user((uchar *)*piVar3,param_1,_MaxCount), iVar1 == 0)) {

        return *piVar3 + 1 + _MaxCount;

      }

    }

  }

  return 0;

}

/* ===== crt_errno_user2 @ 0x0054F684 ===== */
int crt_errno_user2(uint param_1,int param_2)



{

  byte bVar1;

  undefined4 *puVar2;

  byte bVar3;

  

  bVar1 = *(byte *)((&DAT_006578c0)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24);

  if (param_2 == 0x8000) {

    bVar3 = bVar1 & 0x7f;

  }

  else {

    if (param_2 != 0x4000) {

      puVar2 = (undefined4 *)_errno();

      *puVar2 = 0x16;

      return -1;

    }

    bVar3 = bVar1 | 0x80;

  }

  *(byte *)((&DAT_006578c0)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) = bVar3;

  return (-(uint)((bVar1 & 0x80) != 0) & 0xffffc000) + 0x8000;

}

/* ===== crt_comparestring_user @ 0x0054F6E5 ===== */
/* Library Function - Single Match

    __mbsnbicoll

   

   Library: Visual Studio 2003 Release */



int __cdecl crt_comparestring_user(uchar *_Str1,uchar *_Str2,size_t _MaxCount)



{

  int iVar1;

  

  if (_MaxCount == 0) {

    return 0;

  }

  iVar1 = crt_comparestring(DAT_006578a4,1,_Str1,_MaxCount,_Str2,_MaxCount,DAT_0065767c);

  if (iVar1 == 0) {

    return 0x7fffffff;

  }

  return iVar1 + -2;

}

/* ===== FUN_0054f724 @ 0x0054F724 ===== */
undefined4 FUN_0054f724(void)



{

  LPCWSTR lpWideCharStr;

  size_t _Size;

  LPSTR lpMultiByteStr;

  int iVar1;

  undefined4 *puVar2;

  

  lpWideCharStr = (LPCWSTR)*DAT_00630b84;

  puVar2 = DAT_00630b84;

  while( true ) {

    if (lpWideCharStr == (LPCWSTR)0x0) {

      return 0;

    }

    _Size = WideCharToMultiByte(1,0,lpWideCharStr,-1,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0);

    if (((_Size == 0) || (lpMultiByteStr = _malloc(_Size), lpMultiByteStr == (LPSTR)0x0)) ||

       (iVar1 = WideCharToMultiByte(1,0,(LPCWSTR)*puVar2,-1,lpMultiByteStr,_Size,(LPCSTR)0x0,

                                    (LPBOOL)0x0), iVar1 == 0)) break;

    crt_realloc_strcpy(lpMultiByteStr,0);

    lpWideCharStr = (LPCWSTR)puVar2[1];

    puVar2 = puVar2 + 1;

  }

  return 0xffffffff;

}

/* ===== crt_comparestring @ 0x0054F792 ===== */
int crt_comparestring(LCID param_1,DWORD param_2,byte *param_3,int param_4,byte *param_5,int param_6

                     ,UINT param_7)



{

  undefined1 *puVar1;

  int iVar2;

  BOOL BVar3;

  BYTE *pBVar4;

  int iVar5;

  _cpinfo local_40;

  undefined1 *local_2c;

  PCNZWCH local_28;

  int local_24;

  int local_20;

  undefined1 *local_1c;

  void *local_14;

  undefined1 *puStack_10;

  undefined *puStack_c;

  undefined4 local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &DAT_00552a48;

  puStack_10 = &LAB_00544c84;

  local_14 = ExceptionList;

  local_1c = &stack0xffffffb0;

  ExceptionList = &local_14;

  puVar1 = &stack0xffffffb0;

  if (DAT_00630ecc == 0) {

    ExceptionList = &local_14;

    iVar2 = CompareStringW(0,0,L"",1,L"",1);

    if (iVar2 == 0) {

      iVar2 = CompareStringA(0,0,"",1,"",1);

      if (iVar2 == 0) {

        ExceptionList = local_14;

        return 0;

      }

      DAT_00630ecc = 2;

      puVar1 = local_1c;

    }

    else {

      DAT_00630ecc = 1;

      puVar1 = local_1c;

    }

  }

  local_1c = puVar1;

  if (0 < param_4) {

    param_4 = crt_strnlen(param_3,param_4);

  }

  if (0 < param_6) {

    param_6 = crt_strnlen(param_5,param_6);

  }

  if (DAT_00630ecc == 2) {

    iVar2 = CompareStringA(param_1,param_2,(PCNZCH)param_3,param_4,(PCNZCH)param_5,param_6);

    ExceptionList = local_14;

    return iVar2;

  }

  if (DAT_00630ecc == 1) {

    if (param_7 == 0) {

      param_7 = DAT_00630c6c;

    }

    if ((param_4 == 0) || (param_6 == 0)) {

      if (param_4 == param_6) {

        ExceptionList = local_14;

        return 2;

      }

      if (1 < param_6) {

        ExceptionList = local_14;

        return 1;

      }

      if (1 < param_4) {

        ExceptionList = local_14;

        return 3;

      }

      BVar3 = GetCPInfo(param_7,&local_40);

      if (BVar3 == 0) {

        ExceptionList = local_14;

        return 0;

      }

      if (0 < param_4) {

        if (local_40.MaxCharSize < 2) {

          ExceptionList = local_14;

          return 3;

        }

        pBVar4 = local_40.LeadByte;

        while( true ) {

          if (local_40.LeadByte[0] == 0) {

            ExceptionList = local_14;

            return 3;

          }

          if (pBVar4[1] == 0) break;

          if ((*pBVar4 <= *param_3) && (*param_3 <= pBVar4[1])) {

            ExceptionList = local_14;

            return 2;

          }

          pBVar4 = pBVar4 + 2;

          local_40.LeadByte[0] = *pBVar4;

        }

        ExceptionList = local_14;

        return 3;

      }

      if (0 < param_6) {

        if (local_40.MaxCharSize < 2) {

          ExceptionList = local_14;

          return 1;

        }

        pBVar4 = local_40.LeadByte;

        while( true ) {

          if (local_40.LeadByte[0] == 0) {

            ExceptionList = local_14;

            return 1;

          }

          if (pBVar4[1] == 0) break;

          if ((*pBVar4 <= *param_5) && (*param_5 <= pBVar4[1])) {

            ExceptionList = local_14;

            return 2;

          }

          pBVar4 = pBVar4 + 2;

          local_40.LeadByte[0] = *pBVar4;

        }

        ExceptionList = local_14;

        return 1;

      }

    }

    local_20 = MultiByteToWideChar(param_7,9,(LPCSTR)param_3,param_4,(LPWSTR)0x0,0);

    if (local_20 != 0) {

      local_8 = 0;

      FUN_00543e00();

      local_8 = 0xffffffff;

      if ((&stack0x00000000 != (undefined1 *)0x50) &&

         (local_28 = (PCNZWCH)&stack0xffffffb0, local_1c = &stack0xffffffb0,

         iVar2 = MultiByteToWideChar(param_7,1,(LPCSTR)param_3,param_4,(LPWSTR)&stack0xffffffb0,

                                     local_20), iVar2 != 0)) {

        iVar2 = MultiByteToWideChar(param_7,9,(LPCSTR)param_5,param_6,(LPWSTR)0x0,0);

        if (iVar2 != 0) {

          local_8 = 1;

          local_24 = iVar2;

          FUN_00543e00();

          local_8 = 0xffffffff;

          if ((&stack0x00000000 != (undefined1 *)0x50) &&

             (local_2c = &stack0xffffffb0, local_1c = &stack0xffffffb0,

             iVar5 = MultiByteToWideChar(param_7,1,(LPCSTR)param_5,param_6,(LPWSTR)&stack0xffffffb0,

                                         iVar2), iVar5 != 0)) {

            iVar2 = CompareStringW(param_1,param_2,local_28,local_20,(PCNZWCH)&stack0xffffffb0,iVar2

                                  );

            ExceptionList = local_14;

            return iVar2;

          }

        }

      }

    }

  }

  ExceptionList = local_14;

  return 0;

}

/* ===== crt_realloc_strcpy @ 0x0054FA0F ===== */
undefined4 crt_realloc_strcpy(char *param_1,int param_2)



{

  char *pcVar1;

  int iVar2;

  int *piVar3;

  size_t sVar4;

  LPCSTR lpName;

  int *piVar5;

  bool bVar6;

  

  if (param_1 == (char *)0x0) {

    return 0xffffffff;

  }

  pcVar1 = (char *)FUN_0054ff84(param_1,0x3d);

  if (pcVar1 == (char *)0x0) {

    return 0xffffffff;

  }

  if (param_1 == pcVar1) {

    return 0xffffffff;

  }

  bVar6 = pcVar1[1] == '\0';

  if (DAT_00630b7c == DAT_00630b80) {

    DAT_00630b7c = (int *)FUN_0054fbee(DAT_00630b7c);

  }

  if (DAT_00630b7c == (int *)0x0) {

    if ((param_2 == 0) || (DAT_00630b84 == (undefined4 *)0x0)) {

      if (bVar6) {

        return 0;

      }

      DAT_00630b7c = _malloc(4);

      if (DAT_00630b7c == (int *)0x0) {

        return 0xffffffff;

      }

      *DAT_00630b7c = 0;

      if (DAT_00630b84 == (undefined4 *)0x0) {

        DAT_00630b84 = _malloc(4);

        if (DAT_00630b84 == (undefined4 *)0x0) {

          return 0xffffffff;

        }

        *DAT_00630b84 = 0;

      }

    }

    else {

      iVar2 = FUN_0054f724();

      if (iVar2 != 0) {

        return 0xffffffff;

      }

    }

  }

  piVar3 = DAT_00630b7c;

  iVar2 = FUN_0054fb96(param_1,(int)pcVar1 - (int)param_1);

  if ((iVar2 < 0) || (*piVar3 == 0)) {

    if (bVar6) {

      return 0;

    }

    if (iVar2 < 0) {

      iVar2 = -iVar2;

    }

    piVar3 = (int *)realloc(piVar3,iVar2 * 4 + 8);

    if (piVar3 == (int *)0x0) {

      return 0xffffffff;

    }

    piVar3[iVar2] = (int)param_1;

    piVar3[iVar2 + 1] = 0;

  }

  else {

    if (!bVar6) {

      piVar3[iVar2] = (int)param_1;

      goto LAB_0054fb43;

    }

    piVar5 = piVar3 + iVar2;

    crt_free_ext(piVar3[iVar2]);

    for (; *piVar5 != 0; piVar5 = piVar5 + 1) {

      iVar2 = iVar2 + 1;

      *piVar5 = piVar5[1];

    }

    piVar3 = (int *)realloc(piVar3,iVar2 << 2);

    if (piVar3 == (int *)0x0) goto LAB_0054fb43;

  }

  DAT_00630b7c = piVar3;

LAB_0054fb43:

  if (param_2 != 0) {

    sVar4 = _strlen(param_1);

    lpName = _malloc(sVar4 + 2);

    if (lpName != (LPCSTR)0x0) {

      strcpy(lpName,param_1);

      pcVar1[(int)lpName - (int)param_1] = '\0';

      SetEnvironmentVariableA

                (lpName,(LPCSTR)(~-(uint)bVar6 & (uint)(pcVar1 + ((int)lpName - (int)param_1) + 1)))

      ;

      crt_free_ext(lpName);

    }

  }

  return 0;

}

/* ===== FUN_0054fb96 @ 0x0054FB96 ===== */
int FUN_0054fb96(uchar *param_1,size_t param_2)



{

  uchar *_Str2;

  int iVar1;

  int *piVar2;

  

  _Str2 = (uchar *)*DAT_00630b7c;

  piVar2 = DAT_00630b7c;

  while( true ) {

    if (_Str2 == (uchar *)0x0) {

      return -((int)piVar2 - (int)DAT_00630b7c >> 2);

    }

    iVar1 = crt_comparestring_user(param_1,_Str2,param_2);

    if ((iVar1 == 0) &&

       ((*(char *)(*piVar2 + param_2) == '=' || (*(char *)(*piVar2 + param_2) == '\0')))) break;

    _Str2 = (uchar *)piVar2[1];

    piVar2 = piVar2 + 1;

  }

  return (int)piVar2 - (int)DAT_00630b7c >> 2;

}

/* ===== FUN_0054fbee @ 0x0054FBEE ===== */
undefined4 * FUN_0054fbee(int *param_1)



{

  int iVar1;

  int *piVar2;

  undefined4 *puVar3;

  undefined4 uVar4;

  int iVar5;

  undefined4 *puVar6;

  

  iVar5 = 0;

  if (param_1 != (int *)0x0) {

    iVar1 = *param_1;

    piVar2 = param_1;

    while (iVar1 != 0) {

      piVar2 = piVar2 + 1;

      iVar5 = iVar5 + 1;

      iVar1 = *piVar2;

    }

    puVar3 = _malloc(iVar5 * 4 + 4);

    if (puVar3 == (undefined4 *)0x0) {

      __amsg_exit(9);

    }

    iVar5 = *param_1;

    puVar6 = puVar3;

    while (iVar5 != 0) {

      param_1 = param_1 + 1;

      uVar4 = FUN_0055001b(iVar5);

      *puVar6 = uVar4;

      puVar6 = puVar6 + 1;

      iVar5 = *param_1;

    }

    *puVar6 = 0;

    return puVar3;

  }

  return (undefined4 *)0x0;

}

/* ===== realloc @ 0x0054FC55 ===== */
byte * realloc(byte *param_1,uint param_2)



{

  int iVar1;

  uint uVar2;

  byte *pbVar3;

  undefined4 local_3c;

  uint local_38;

  byte *local_34;

  undefined4 local_30;

  int local_2c;

  byte *local_28;

  uint local_24;

  void *local_14;

  undefined1 *puStack_10;

  undefined *puStack_c;

  undefined4 local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &DAT_00552a60;

  puStack_10 = &LAB_00544c84;

  local_14 = ExceptionList;

  pbVar3 = (byte *)0x0;

  if (param_1 == (byte *)0x0) {

    ExceptionList = &local_14;

    pbVar3 = _malloc(param_2);

  }

  else {

    if (param_2 == 0) {

      ExceptionList = &local_14;

      crt_free_ext(param_1);

    }

    else {

      ExceptionList = &local_14;

      if (DAT_006579ec == 3) {

        do {

          local_28 = (byte *)0x0;

          if (param_2 < 0xffffffe1) {

            _lock(9);

            local_8 = 0;

            local_2c = __sbh_find_block(param_1);

            if (local_2c != 0) {

              if (param_2 <= DAT_006579e4) {

                iVar1 = __sbh_resize_block(local_2c,param_1,param_2);

                if (iVar1 == 0) {

                  local_28 = (byte *)__sbh_alloc_block(param_2);

                  if (local_28 != (byte *)0x0) {

                    local_24 = *(int *)(param_1 + -4) - 1;

                    uVar2 = local_24;

                    if (param_2 <= local_24) {

                      uVar2 = param_2;

                    }

                    memmove(local_28,param_1,uVar2);

                    local_2c = __sbh_find_block(param_1);

                    __sbh_free_block(local_2c,param_1);

                  }

                }

                else {

                  local_28 = param_1;

                }

              }

              if (local_28 == (byte *)0x0) {

                if (param_2 == 0) {

                  param_2 = 1;

                }

                param_2 = param_2 + 0xf & 0xfffffff0;

                local_28 = HeapAlloc(DAT_006579e8,0,param_2);

                if (local_28 != (byte *)0x0) {

                  local_24 = *(int *)(param_1 + -4) - 1;

                  uVar2 = local_24;

                  if (param_2 <= local_24) {

                    uVar2 = param_2;

                  }

                  memmove(local_28,param_1,uVar2);

                  __sbh_free_block(local_2c,param_1);

                }

              }

            }

            local_8 = 0xffffffff;

            FUN_0054FDE0();

            if (local_2c == 0) {

              if (param_2 == 0) {

                param_2 = 1;

              }

              param_2 = param_2 + 0xf & 0xfffffff0;

              local_28 = HeapReAlloc(DAT_006579e8,0,param_1,param_2);

            }

          }

          if (local_28 != (byte *)0x0) {

            ExceptionList = local_14;

            return local_28;

          }

          if (DAT_00630bdc == (byte *)0x0) {

            ExceptionList = local_14;

            return (byte *)0x0;

          }

          iVar1 = FUN_0054aac3(param_2);

        } while (iVar1 != 0);

      }

      else {

        ExceptionList = &local_14;

        if (DAT_006579ec == 2) {

          ExceptionList = &local_14;

          if (param_2 < 0xffffffe1) {

            if (param_2 == 0) {

              param_2 = 0x10;

              ExceptionList = &local_14;

            }

            else {

              param_2 = param_2 + 0xf & 0xfffffff0;

              ExceptionList = &local_14;

            }

          }

          do {

            local_28 = pbVar3;

            if (param_2 < 0xffffffe1) {

              _lock(9);

              local_8 = 1;

              pbVar3 = (byte *)crt_sbh_addr_lookup(param_1,&local_3c,&local_30);

              local_34 = pbVar3;

              if (pbVar3 == (byte *)0x0) {

                local_28 = HeapReAlloc(DAT_006579e8,0,param_1,param_2);

              }

              else {

                if (param_2 < DAT_0058386c) {

                  iVar1 = crt_sbh_adjust_block(local_3c,local_30,pbVar3,param_2 >> 4);

                  if (iVar1 == 0) {

                    local_28 = (byte *)crt_heap_alloc_sbh(param_2 >> 4);

                    if (local_28 != (byte *)0x0) {

                      local_38 = (uint)*pbVar3 << 4;

                      uVar2 = local_38;

                      if (param_2 <= local_38) {

                        uVar2 = param_2;

                      }

                      memmove(local_28,param_1,uVar2);

                      crt_sbh_decommit_page(local_3c,local_30,pbVar3);

                    }

                  }

                  else {

                    local_28 = param_1;

                  }

                }

                if ((local_28 == (byte *)0x0) &&

                   (local_28 = HeapAlloc(DAT_006579e8,0,param_2), local_28 != (byte *)0x0)) {

                  local_38 = (uint)*pbVar3 << 4;

                  uVar2 = local_38;

                  if (param_2 <= local_38) {

                    uVar2 = param_2;

                  }

                  memmove(local_28,param_1,uVar2);

                  crt_sbh_decommit_page(local_3c,local_30,pbVar3);

                }

              }

              local_8 = 0xffffffff;

              FUN_0054FF2E();

            }

            if (local_28 != pbVar3) {

              ExceptionList = local_14;

              return local_28;

            }

            if (DAT_00630bdc == pbVar3) {

              ExceptionList = local_14;

              return local_28;

            }

            iVar1 = FUN_0054aac3(param_2);

          } while (iVar1 != 0);

        }

        else {

          do {

            pbVar3 = (byte *)0x0;

            if (param_2 < 0xffffffe1) {

              if (param_2 == 0) {

                param_2 = 1;

              }

              param_2 = param_2 + 0xf & 0xfffffff0;

              pbVar3 = HeapReAlloc(DAT_006579e8,0,param_1,param_2);

            }

            if (pbVar3 != (byte *)0x0) {

              ExceptionList = local_14;

              return pbVar3;

            }

            if (DAT_00630bdc == (byte *)0x0) {

              ExceptionList = local_14;

              return (byte *)0x0;

            }

            iVar1 = FUN_0054aac3(param_2);

          } while (iVar1 != 0);

        }

      }

    }

    pbVar3 = (byte *)0x0;

  }

  ExceptionList = local_14;

  return pbVar3;

}

/* ===== FUN_0054FDE0 @ 0x0054FDE0 ===== */
void FUN_0054FDE0(void)



{

  _unlock(9);

  return;

}

/* ===== FUN_0054FF2E @ 0x0054FF2E ===== */
void FUN_0054FF2E(void)



{

  _unlock(9);

  return;

}

/* ===== FUN_0054ff84 @ 0x0054FF84 ===== */
/* PS2 candidate: kbos_move (conf 0.324) */



byte * FUN_0054ff84(byte *param_1,uint param_2)



{

  byte bVar1;

  uint uVar2;

  byte *pbVar3;

  

  if (DAT_0065768c == 0) {

    param_1 = (byte *)_strchr((char *)param_1,param_2);

  }

  else {

    _lock(0x19);

    while( true ) {

      bVar1 = *param_1;

      uVar2 = (uint)bVar1;

      if (bVar1 == 0) break;

      if ((*(byte *)((int)&DAT_006577a0 + uVar2 + 1) & 4) == 0) {

        pbVar3 = param_1;

        if (param_2 == uVar2) break;

      }

      else {

        pbVar3 = param_1 + 1;

        if (param_1[1] == 0) {

          _unlock(0x19);

          return (byte *)0x0;

        }

        if (param_2 == CONCAT11(bVar1,param_1[1])) {

          _unlock(0x19);

          return param_1;

        }

      }

      param_1 = pbVar3 + 1;

    }

    _unlock(0x19);

    param_1 = (byte *)(~-(uint)(param_2 != uVar2) & (uint)param_1);

  }

  return param_1;

}

