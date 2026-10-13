/* Giants 1.449 — module main/smoke
 * 2 functions (2 named) — decompiled, names from PS2 symbols
 * Original source: C:\Giants\source\main/smoke.c(pp) (assert-string evidence)
 */

/* ===== main_smoke_004f8e10 @ 0x004F8E10 ===== */
void main_smoke_004f8e10(int param_1,float param_2,undefined4 param_3)



{

  float fVar1;

  int iVar2;

  int iVar3;

  undefined4 *puVar4;

  int iVar5;

  int iVar6;

  float10 fVar7;

  undefined1 local_c [12];

  

  iVar6 = 0;

  iVar3 = object_allocate_type(0x4a,0);

  object_change_ospec(iVar3,0x18);

  object_set_location_p3d(iVar3,param_1 + 0xa0);

  *(uint *)(iVar3 + 0xd8) = *(uint *)(iVar3 + 0xd8) | 0x40000000;

  puVar4 = (undefined4 *)

           MemAllocMsg(0xd,0x4c,&DAT_00560428,s_C__Giants_source_main_smoke_c_00562348,0x1b3);

  *puVar4 = 0;

  puVar4[1] = 0;

  puVar4[2] = 0;

  puVar4[3] = 0;

  puVar4[4] = (1.0 / param_2) * *(float *)(DAT_00632ee0 + 0x18 + *(int *)(DAT_00632ed8 + 0x284) * 4)

  ;

  puVar4[5] = (1.0 / param_2) * *(float *)(DAT_00632ee0 + 0x1c + *(int *)(DAT_00632ed8 + 0x284) * 4)

  ;

  puVar4[6] = param_2 * *(float *)(DAT_00632ee0 + 0x20 + *(int *)(DAT_00632ed8 + 0x284) * 4);

  puVar4[7] = param_2 * *(float *)(DAT_00632ee0 + 0x24 + *(int *)(DAT_00632ed8 + 0x284) * 4);

  puVar4[8] = param_2 * *(float *)(DAT_00632ee0 + 0x28 + *(int *)(DAT_00632ed8 + 0x284) * 4);

  puVar4[9] = param_2 * *(float *)(DAT_00632ee0 + 0x2c + *(int *)(DAT_00632ed8 + 0x284) * 4);

  puVar4[10] = *(undefined4 *)(DAT_00632ee0 + 0x30 + *(int *)(DAT_00632ed8 + 0x284) * 4);

  puVar4[0xb] = *(undefined4 *)(DAT_00632ee0 + 0x34 + *(int *)(DAT_00632ed8 + 0x284) * 4);

  puVar4[0xc] = *(undefined4 *)(DAT_00632ee0 + 0x38 + *(int *)(DAT_00632ed8 + 0x284) * 4);

  puVar4[0xd] = *(undefined4 *)(DAT_00632ee0 + 0x3c + *(int *)(DAT_00632ed8 + 0x284) * 4);

  puVar4[0xe] = *(undefined4 *)(DAT_00632ee0 + 0x40 + *(int *)(DAT_00632ed8 + 0x284) * 4);

  puVar4[0xf] = param_2 * *(float *)(DAT_00632ee0 + 0x44 + *(int *)(DAT_00632ed8 + 0x284) * 4);

  puVar4[0x10] = param_2 * *(float *)(DAT_00632ee0 + 0x48 + *(int *)(DAT_00632ed8 + 0x284) * 4);

  puVar4[0x11] = param_2 * *(float *)(DAT_00632ee0 + 0x4c + *(int *)(DAT_00632ed8 + 0x284) * 4);

  puVar4[0x12] = *(undefined4 *)(DAT_00632ee0 + 0x50 + *(int *)(DAT_00632ed8 + 0x284) * 4);

  **(undefined4 **)(iVar3 + 0x100) = puVar4;

  *(undefined4 *)(iVar3 + 0xec) = param_3;

  *(uint *)(iVar3 + 0xe0) = *(uint *)(iVar3 + 0xe0) | 5;

  fVar7 = (float10)rndfloatrange(puVar4[4],puVar4[5]);

  *(float *)(*(int *)(iVar3 + 0x100) + 8) = (float)fVar7;

  *(undefined4 *)(iVar3 + 0xe4) = 1;

  FUN_0049bc50(param_1);

  param_2 = 1.96182e-44;

  do {

    tracer_calc_falloff__FP6Traceri(param_1,iVar6,local_c);

    iVar5 = make_particle__FP6OBJECT(iVar3);

    iVar2 = *(int *)(iVar5 + 0x100);

    object_set_location_p3d(iVar5,local_c);

    fVar1 = (float)puVar4[0xb];

    iVar6 = iVar6 + 1;

    *(float *)(iVar5 + 0xec) = fVar1 - (float)(int)param_2 * 0.16666667;

    fVar1 = 1.0 / fVar1;

    *(float *)(iVar2 + 8) = fVar1;

    param_2 = (float)((int)param_2 + -1);

    *(float *)(iVar5 + 0xc4) =

         ((float)puVar4[7] - (float)puVar4[6]) * (1.0 - fVar1 * *(float *)(iVar5 + 0xec)) +

         (float)puVar4[6];

  } while (0 < (int)param_2);

  return;

}

/* ===== main_smoke_004f9170 @ 0x004F9170 ===== */
void main_smoke_004f9170(int param_1)



{

  float fVar1;

  int iVar2;

  float fVar3;

  int iVar4;

  undefined4 *puVar5;

  int iVar6;

  int iVar7;

  float10 fVar8;

  int local_14;

  undefined1 local_c [12];

  

  iVar7 = 0;

  iVar4 = object_allocate_type(0x4a,0);

  object_change_ospec(iVar4,0x18);

  object_set_location_p3d(iVar4,param_1 + 0xa0);

  *(uint *)(iVar4 + 0xd8) = *(uint *)(iVar4 + 0xd8) | 0x40000000;

  puVar5 = (undefined4 *)

           MemAllocMsg(0xd,0x4c,&DAT_00560428,s_C__Giants_source_main_smoke_c_00562348,0x20c);

  puVar5[5] = 0x3c23d70a;

  puVar5[4] = 0x3c23d70a;

  *puVar5 = 0;

  puVar5[1] = 0;

  puVar5[2] = 0;

  puVar5[3] = 0;

  puVar5[6] = 0x3f000000;

  puVar5[9] = 0x40400000;

  puVar5[0xc] = 0xc2b40000;

  puVar5[0xd] = 0x42b40000;

  puVar5[0xe] = 0x41a00000;

  puVar5[0x10] = 0x40a00000;

  puVar5[0x12] = 0;

  puVar5[7] = 0x3fc00000;

  puVar5[0xb] = 0x3fc00000;

  puVar5[8] = 0x40000000;

  puVar5[0xf] = 0x40000000;

  puVar5[10] = 0x3f800000;

  puVar5[0x11] = 0x3f800000;

  **(undefined4 **)(iVar4 + 0x100) = puVar5;

  *(undefined4 *)(iVar4 + 0xec) = 0x3dcccccd;

  *(uint *)(iVar4 + 0xe0) = *(uint *)(iVar4 + 0xe0) | 5;

  fVar8 = (float10)rndfloatrange(puVar5[4],puVar5[5]);

  *(float *)(*(int *)(iVar4 + 0x100) + 8) = (float)fVar8;

  *(undefined4 *)(iVar4 + 0xe4) = 1;

  FUN_0049bc50(param_1);

  local_14 = 3;

  do {

    tracer_calc_falloff__FP6Traceri(param_1,iVar7,local_c);

    iVar6 = make_particle__FP6OBJECT(iVar4);

    iVar2 = *(int *)(iVar6 + 0x100);

    object_set_location_p3d(iVar6,local_c);

    fVar1 = (float)puVar5[0xb];

    fVar3 = (float)local_14;

    iVar7 = iVar7 + 1;

    local_14 = local_14 + -1;

    *(float *)(iVar6 + 0xec) = fVar1 - fVar3 * 0.16666667;

    fVar1 = 1.0 / fVar1;

    *(float *)(iVar2 + 8) = fVar1;

    *(float *)(iVar6 + 0xc4) =

         ((float)puVar5[7] - (float)puVar5[6]) * (1.0 - fVar1 * *(float *)(iVar6 + 0xec)) +

         (float)puVar5[6];

  } while (0 < local_14);

  return;

}

