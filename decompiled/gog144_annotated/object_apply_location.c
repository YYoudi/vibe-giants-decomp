/* ANNOTATED RE-EXPORT — obj->field substitutions from docs/formats/OBJECT_LAYOUT.md (observed/derived fields only).
 * Source of truth: decompiled/gog144_full. Regenerate: scripts/annotate_corpus.py. */



/* PS2 candidate: object_apply_location (conf 0.439) */



void object_apply_location(float param_1)



{

  float *pfVar1;

  float *pfVar2;

  float fVar3;

  float fVar4;

  ushort uVar5;

  ushort uVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  uint uVar10;

  ushort uVar11;

  float10 fVar12;

  float local_24;

  float local_20;

  float local_1c;

  

  fVar9 = param_1;

  local_24 = *(float *)((int)param_1 + 0xa0) - *(float *)((int)param_1 + 0xac);

  pfVar1 = (float *)((int)param_1 + 0xac);

  local_20 = *(float *)((int)param_1 + 0xa4) - *(float *)((int)param_1 + 0xb0);

  local_1c = *(float *)((int)param_1 + 0xa8) - *(float *)((int)param_1 + 0xb4);

  fVar3 = param_1;

  if (*(int *)((int)param_1 + 0x104) == 0) {

    fVar12 = (float10)FRateGetSecsframe(param_1,0);

    fVar3 = (float)fVar12;

    pfVar2 = (float *)((int)param_1 + 0x128);

    local_24 = (*(float *)((int)param_1 + 0x128) + *(float *)((int)param_1 + 0x134)) * fVar3 * 0.5 +

               local_24;

    local_20 = (*(float *)((int)param_1 + 0x138) + *(float *)((int)param_1 + 300)) * fVar3 * 0.5 +

               local_20;

    fVar4 = *(float *)((int)param_1 + 0x13c);

    *(float *)((int)param_1 + 0x134) = *pfVar2;

    *(undefined4 *)((int)param_1 + 0x138) = *(undefined4 *)((int)param_1 + 300);

    *(undefined4 *)((int)param_1 + 0x13c) = *(undefined4 *)((int)param_1 + 0x130);

    local_1c = (fVar4 + *(float *)((int)param_1 + 0x130)) * fVar3 * 0.5 + local_1c;

    if ((0.0 < *pfVar2) &&

       (fVar4 = *pfVar2 - fVar3 * *(float *)((int)param_1 + 0x200), *pfVar2 = fVar4, fVar4 < 0.0)) {

      *pfVar2 = 0.0;

    }

    if ((*pfVar2 < 0.0) &&

       (fVar4 = fVar3 * *(float *)((int)param_1 + 0x200) + *pfVar2, *pfVar2 = fVar4, 0.0 < fVar4)) {

      *pfVar2 = 0.0;

    }

    if ((0.0 < *(float *)((int)param_1 + 300)) &&

       (fVar4 = *(float *)((int)param_1 + 300) - fVar3 * *(float *)((int)param_1 + 0x200),

       *(float *)((int)param_1 + 300) = fVar4, fVar4 < 0.0)) {

      *(undefined4 *)((int)param_1 + 300) = 0;

    }

    if ((*(float *)((int)param_1 + 300) < 0.0) &&

       (fVar4 = fVar3 * *(float *)((int)param_1 + 0x200) + *(float *)((int)param_1 + 300),

       *(float *)((int)param_1 + 300) = fVar4, 0.0 < fVar4)) {

      *(undefined4 *)((int)param_1 + 300) = 0;

    }

    if ((0.0 < *(float *)((int)param_1 + 0x130)) &&

       (fVar4 = *(float *)((int)param_1 + 0x130) - fVar3 * *(float *)((int)param_1 + 0x200),

       *(float *)((int)param_1 + 0x130) = fVar4, fVar4 < 0.0)) {

      *(undefined4 *)((int)param_1 + 0x130) = 0;

    }

    if ((*(float *)((int)param_1 + 0x130) < 0.0) &&

       (fVar4 = fVar3 * *(float *)((int)param_1 + 0x200) + *(float *)((int)param_1 + 0x130),

       *(float *)((int)param_1 + 0x130) = fVar4, 0.0 < fVar4)) {

      *(undefined4 *)((int)param_1 + 0x130) = 0;

    }

  }

  param_1 = fVar3;

  if ((local_24 != 0.0) || (local_20 != 0.0)) {

    collgrid_clear_grid(fVar9);

  }

  fVar3 = *pfVar1;

  fVar4 = *(float *)((int)fVar9 + 0xb0);

  *(float *)((int)fVar9 + 0xa0) = local_24 + *pfVar1;

  *(float *)((int)fVar9 + 0xa4) = local_20 + *(float *)((int)fVar9 + 0xb0);

  local_1c = local_1c + *(float *)((int)fVar9 + 0xb4);

  *(float *)((int)fVar9 + 0xa8) = local_1c;

  if (*(int *)((int)fVar9 + 0x210) != 0) goto LAB_004998d3;

  if ((*(int *)((int)fVar9 + 4) == 6) || (*(int *)((int)fVar9 + 4) == 7)) {

LAB_004997cf:

    *(float *)((int)fVar9 + 0x140) = local_1c;

  }

  else {

    if ((*(byte *)((int)fVar9 + 0xd8) & 0x10) != 0) {

      local_1c = local_1c - *(float *)((int)fVar9 + 0x1d4);

      *(undefined4 *)((int)fVar9 + 0x108) = 0;

      goto LAB_004997cf;

    }

    collide_objects(fVar9);

  }

  uVar10 = *(uint *)((int)fVar9 + 0xd8);

  if (*(float *)((int)fVar9 + 0xa8) < 0.0 == (*(float *)((int)fVar9 + 0xa8) == 0.0)) {

    *(uint *)((int)fVar9 + 0xd8) = uVar10 & 0xf7efffff;

  }

  else {

    *(uint *)((int)fVar9 + 0xd8) = uVar10 | 0x100000;

    if (-(*(float *)((int)fVar9 + 0x1e8) * *(float *)((int)fVar9 + 0xc4)) <

        *(float *)((int)fVar9 + 0xa8)) {

      *(uint *)((int)fVar9 + 0xd8) = uVar10 & 0xf7ffffff | 0x100000;

    }

    else {

      *(uint *)((int)fVar9 + 0xd8) = uVar10 | 0x8100000;

    }

  }

  fVar3 = *(float *)((int)fVar9 + 0xa0) - fVar3;

  fVar4 = *(float *)((int)fVar9 + 0xa4) - fVar4;

  fVar7 = ABS(local_24);

  fVar8 = ABS(local_20);

  if (fVar7 <= fVar8) {

    if (param_1 <= fVar8) {

      if (fVar7 / fVar8 < 0.35) {

LAB_0049990d:

        fVar4 = fVar4 / local_20;

        uVar11 = (ushort)(fVar4 < 0.5) << 8 | (ushort)(fVar4 == 0.5) << 0xe;

        goto LAB_0049991d;

      }

      if ((fVar3 / local_24 <= 0.5) || (fVar4 / local_20 <= 0.5)) goto LAB_004998b9;

    }

LAB_00499952:

    uVar10 = *(uint *)((int)fVar9 + 0xd8) & 0xfffbffff;

  }

  else {

    if (fVar7 < param_1) goto LAB_00499952;

    fVar3 = fVar3 / local_24;

    uVar5 = (ushort)(fVar3 < 0.5);

    uVar6 = (ushort)(fVar3 == 0.5);

    uVar11 = uVar5 << 8 | uVar6 << 0xe;

    if (fVar8 / fVar7 < 0.35) {

LAB_0049991d:

      if (uVar11 == 0) goto LAB_00499952;

    }

    else if (uVar5 == 0 && uVar6 == 0) goto LAB_0049990d;

LAB_004998b9:

    uVar10 = *(uint *)((int)fVar9 + 0xd8) | 0x40000;

  }

  *(uint *)((int)fVar9 + 0xd8) = uVar10;

  ObjectCalculateTransform(fVar9);

LAB_004998d3:

  *(uint *)((int)fVar9 + 0xd8) = *(uint *)((int)fVar9 + 0xd8) | 0x20;

  return;

}





