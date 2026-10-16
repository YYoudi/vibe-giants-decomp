
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* PS2 candidate: object_apply_location (conf 0.439) */

void object_apply_location(OBJECT *obj)

{
  undefined1 *puVar1;
  dword *pdVar2;
  OBJECT *pOVar3;
  float fVar4;
  float fVar5;
  ushort uVar6;
  ushort uVar7;
  float fVar8;
  float fVar9;
  OBJECT *pOVar10;
  uint uVar11;
  ushort uVar12;
  float10 fVar13;
  float local_24;
  float local_20;
  float local_1c;
  
  pOVar10 = obj;
  local_24 = *(float *)&obj->field_0xa0 - *(float *)&obj->field_0xac;
  puVar1 = &obj->field_0xac;
  local_20 = *(float *)&obj->field_0xa4 - *(float *)&obj->field_0xb0;
  local_1c = *(float *)&obj->field_0xa8 - *(float *)&obj->field_0xb4;
  pOVar3 = obj;
  if (obj->pad_104 == 0) {
    fVar13 = (float10)FRateGetSecsframe(obj,0);
    pOVar3 = (OBJECT *)(float)fVar13;
    pdVar2 = &obj->pad_128;
    local_24 = ((float)obj->pad_128 + (float)obj->loc_accum1) * (float)pOVar3 * _DAT_005512bc +
               local_24;
    local_20 = ((float)obj->loc_accum2 + *(float *)&obj->field_0x12c) * (float)pOVar3 *
               _DAT_005512bc + local_20;
    fVar4 = (float)obj->loc_accum3;
    obj->loc_accum1 = *pdVar2;
    obj->loc_accum2 = *(dword *)&obj->field_0x12c;
    obj->loc_accum3 = obj->loc_accum0;
    local_1c = (fVar4 + (float)obj->loc_accum0) * (float)pOVar3 * _DAT_005512bc + local_1c;
    if ((_DAT_005512a0 < (float)*pdVar2) &&
       (fVar4 = (float)*pdVar2 - (float)pOVar3 * *(float *)&obj->field_0x200, *pdVar2 = (dword)fVar4
       , fVar4 < _DAT_005512a0)) {
      *pdVar2 = 0;
    }
    if (((float)*pdVar2 < _DAT_005512a0) &&
       (fVar4 = (float)pOVar3 * *(float *)&obj->field_0x200 + (float)*pdVar2, *pdVar2 = (dword)fVar4
       , _DAT_005512a0 < fVar4)) {
      *pdVar2 = 0;
    }
    if ((_DAT_005512a0 < *(float *)&obj->field_0x12c) &&
       (fVar4 = *(float *)&obj->field_0x12c - (float)pOVar3 * *(float *)&obj->field_0x200,
       *(float *)&obj->field_0x12c = fVar4, fVar4 < _DAT_005512a0)) {
      *(undefined4 *)&obj->field_0x12c = 0;
    }
    if ((*(float *)&obj->field_0x12c < _DAT_005512a0) &&
       (fVar4 = (float)pOVar3 * *(float *)&obj->field_0x200 + *(float *)&obj->field_0x12c,
       *(float *)&obj->field_0x12c = fVar4, _DAT_005512a0 < fVar4)) {
      *(undefined4 *)&obj->field_0x12c = 0;
    }
    if ((_DAT_005512a0 < (float)obj->loc_accum0) &&
       (fVar4 = (float)obj->loc_accum0 - (float)pOVar3 * *(float *)&obj->field_0x200,
       obj->loc_accum0 = (dword)fVar4, fVar4 < _DAT_005512a0)) {
      obj->loc_accum0 = 0;
    }
    if (((float)obj->loc_accum0 < _DAT_005512a0) &&
       (fVar4 = (float)pOVar3 * *(float *)&obj->field_0x200 + (float)obj->loc_accum0,
       obj->loc_accum0 = (dword)fVar4, _DAT_005512a0 < fVar4)) {
      obj->loc_accum0 = 0;
    }
  }
  obj = pOVar3;
  if ((local_24 != _DAT_005512a0) || (local_20 != _DAT_005512a0)) {
    collgrid_clear_grid(pOVar10);
  }
  fVar4 = *(float *)puVar1;
  fVar5 = *(float *)&pOVar10->field_0xb0;
  *(float *)&pOVar10->field_0xa0 = local_24 + *(float *)puVar1;
  *(float *)&pOVar10->field_0xa4 = local_20 + *(float *)&pOVar10->field_0xb0;
  local_1c = local_1c + *(float *)&pOVar10->field_0xb4;
  *(float *)&pOVar10->field_0xa8 = local_1c;
  if (*(int *)&pOVar10->field_0x210 != 0) goto LAB_004998d3;
  if ((pOVar10->type_id == 6) || (pOVar10->type_id == 7)) {
LAB_004997cf:
    pOVar10->pad_140 = (dword)local_1c;
  }
  else {
    if ((pOVar10->flags & 0x10) != 0) {
      local_1c = local_1c - *(float *)&pOVar10->field_0x1d4;
      pOVar10->vel0 = 0;
      goto LAB_004997cf;
    }
    collide_objects(pOVar10);
  }
  uVar11 = pOVar10->flags;
  if (*(float *)&pOVar10->field_0xa8 < (float)_DAT_005513d8 ==
      (*(float *)&pOVar10->field_0xa8 == (float)_DAT_005513d8)) {
    pOVar10->flags = uVar11 & 0xf7efffff;
  }
  else {
    pOVar10->flags = uVar11 | 0x100000;
    if (-(*(float *)&pOVar10->field_0x1e8 * *(float *)&pOVar10->field_0xc4) <
        *(float *)&pOVar10->field_0xa8) {
      pOVar10->flags = uVar11 & 0xf7ffffff | 0x100000;
    }
    else {
      pOVar10->flags = uVar11 | 0x8100000;
    }
  }
  fVar4 = *(float *)&pOVar10->field_0xa0 - fVar4;
  fVar5 = *(float *)&pOVar10->field_0xa4 - fVar5;
  fVar8 = ABS(local_24);
  fVar9 = ABS(local_20);
  if (fVar8 <= fVar9) {
    if ((float)obj <= fVar9) {
      if (fVar8 / fVar9 < _DAT_005514fc) {
LAB_0049990d:
        fVar5 = fVar5 / local_20;
        uVar12 = (ushort)(fVar5 < _DAT_005512bc) << 8 | (ushort)(fVar5 == _DAT_005512bc) << 0xe;
        goto LAB_0049991d;
      }
      if ((fVar4 / local_24 <= _DAT_005512bc) || (fVar5 / local_20 <= _DAT_005512bc))
      goto LAB_004998b9;
    }
LAB_00499952:
    uVar11 = pOVar10->flags & 0xfffbffff;
  }
  else {
    if (fVar8 < (float)obj) goto LAB_00499952;
    fVar4 = fVar4 / local_24;
    uVar6 = (ushort)(fVar4 < _DAT_005512bc);
    uVar7 = (ushort)(fVar4 == _DAT_005512bc);
    uVar12 = uVar6 << 8 | uVar7 << 0xe;
    if (fVar9 / fVar8 < _DAT_005514fc) {
LAB_0049991d:
      if (uVar12 == 0) goto LAB_00499952;
    }
    else if (uVar6 == 0 && uVar7 == 0) goto LAB_0049990d;
LAB_004998b9:
    uVar11 = pOVar10->flags | 0x40000;
  }
  pOVar10->flags = uVar11;
  ObjectCalculateTransform(pOVar10);
LAB_004998d3:
  pOVar10->flags = pOVar10->flags | 0x20;
  return;
}

