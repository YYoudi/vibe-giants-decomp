
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* PS2 candidate: object_animate_process (conf 0.407) */

void object_animate_process(OBJECT *obj)

{
  float fVar1;
  float fVar2;
  uint uVar3;
  float *pfVar4;
  bool bVar5;
  bool bVar6;
  uint uVar7;
  dword dVar8;
  dword *pdVar9;
  int *piVar10;
  undefined4 uVar11;
  uint *puVar12;
  undefined4 uVar13;
  float in_stack_00000008;
  int local_8;
  
  uVar11 = 0;
  if (obj->class_ptr == 0) {
    return;
  }
  bVar6 = false;
  pdVar9 = &obj->anim;
  local_8 = 4;
  do {
    if ((in_stack_00000008 != _DAT_005512a0) || ((pdVar9[8] & 0x100) != 0)) {
      uVar3 = pdVar9[8];
      pdVar9[8] = uVar3 & 0xfffffeff;
      bVar6 = true;
      if ((*pdVar9 != 0xfe) &&
         (pfVar4 = *(float **)(obj->class_ptr + 8 + *pdVar9 * 4), pfVar4 != (float *)0x0)) {
        fVar1 = _DAT_005512b0;
        if ((float)pdVar9[5] != _DAT_005512a0) {
          fVar1 = (float)(&obj->vel0)[pdVar9[4]] / (float)pdVar9[5];
        }
        if ((uVar3 & 0x10) != 0) {
          fVar1 = -fVar1;
        }
        if ((uVar3 & 0xc) != 0) {
          pdVar9[8] = uVar3 & 0xfffffef7;
          in_stack_00000008 = 0.0;
          pdVar9[3] = 0;
        }
        if ((char)pdVar9[8] < '\0') {
          if (_DAT_005512a0 <= fVar1) {
            pdVar9[1] = (dword)(*pfVar4 * (float)pdVar9[1]);
          }
          else {
            pdVar9[1] = (dword)*pfVar4;
          }
          pdVar9[8] = pdVar9[8] & 0xffffff7f;
          in_stack_00000008 = 0.0;
          pdVar9[3] = 0;
        }
        if ((pdVar9[8] & 0x20) != 0) {
          if (_DAT_005512a0 <= fVar1) {
            pdVar9[1] = pdVar9[3];
          }
          else {
            pdVar9[1] = (dword)(*pfVar4 - (float)pdVar9[3]);
          }
          pdVar9[8] = pdVar9[8] & 0xffffffdf;
        }
        if ((pdVar9[8] & 0x40) != 0) {
          if (fVar1 <= _DAT_005512a0) {
            pdVar9[1] = pdVar9[3];
          }
          else {
            pdVar9[1] = (dword)(*pfVar4 - (float)pdVar9[3]);
          }
          pdVar9[8] = pdVar9[8] & 0xffffffbf;
        }
        bVar5 = _DAT_005512a0 <= fVar1;
        uVar3 = pdVar9[8];
        uVar7 = uVar3 & 0xfffffffd;
        pdVar9[2] = pdVar9[1];
        fVar1 = fVar1 * in_stack_00000008 + (float)pdVar9[1];
        pdVar9[8] = uVar7;
        pdVar9[1] = (dword)fVar1;
        pdVar9[3] = 0;
        if (bVar5) {
          if (*pfVar4 <= fVar1) {
            pdVar9[8] = uVar7 | 2;
            if (*pfVar4 <= fVar1) {
              do {
                fVar1 = (float)pdVar9[1];
                fVar2 = *pfVar4;
                pdVar9[1] = (dword)(fVar1 - fVar2);
              } while (*pfVar4 <= fVar1 - fVar2);
            }
            pdVar9[3] = pdVar9[1];
            if ((uVar3 & 1) == 0) {
              pdVar9[1] = (dword)*pfVar4;
            }
          }
        }
        else if (fVar1 < _DAT_005512a0) {
          pdVar9[8] = uVar7 | 2;
          do {
            fVar1 = *pfVar4 + (float)pdVar9[1];
            bVar5 = fVar1 < _DAT_005512a0;
            pdVar9[1] = (dword)fVar1;
          } while (bVar5);
          pdVar9[3] = (dword)(*pfVar4 - fVar1);
          if ((uVar3 & 1) == 0) {
            pdVar9[1] = 0;
          }
        }
        if (((_DAT_005512a0 < (float)pdVar9[7]) && ((float)pdVar9[6] != _DAT_005512a0)) &&
           (fVar1 = (float)pdVar9[7] - in_stack_00000008 / (float)pdVar9[6],
           pdVar9[7] = (dword)fVar1, fVar1 < _DAT_005512a0)) {
          pdVar9[7] = 0;
        }
      }
    }
    pdVar9 = pdVar9 + 9;
    local_8 = local_8 + -1;
  } while (local_8 != 0);
  if (!bVar6) {
    return;
  }
  dVar8 = handle_next_get();
  obj->team_link = dVar8;
  BasicUsrAnmApply__FP9ObjectSetP14BasicUsrAnmDefPFP6OBJECTPvii_i(obj);
  if (obj->anim == 0xfe) {
    return;
  }
  pfVar4 = *(float **)(obj->class_ptr + 8 + obj->anim * 4);
  if (pfVar4 == (float *)0x0) {
    return;
  }
  puVar12 = (uint *)0x0;
  if ((obj->state == 2) && (obj->pad_0 != 0)) {
    puVar12 = *(uint **)(obj->animate_state + 0x7c);
  }
  piVar10 = (int *)pfVar4[9];
  if ((piVar10 == (int *)0x0) && (puVar12 == (uint *)0x0)) {
    return;
  }
  fVar1 = (float)obj->pad_14 - *(float *)&obj->field_0x18;
  if (fVar1 < _DAT_005512a0) {
    if (*pfVar4 * _DAT_005512bc < -fVar1) {
      uVar13 = 0;
      uVar11 = 1;
      goto LAB_00404137;
    }
  }
  else {
    if (fVar1 <= *pfVar4 * _DAT_005512bc) {
      uVar13 = 0;
      goto LAB_00404137;
    }
    uVar11 = 1;
  }
  uVar13 = 1;
LAB_00404137:
  if ((piVar10 != (int *)0x0) && (local_8 = 0, 0 < *piVar10)) {
    in_stack_00000008 = 0.0;
    do {
      obj_impact_effects(obj,pfVar4,uVar13,uVar11,(int)in_stack_00000008 + 4 + (int)piVar10);
      in_stack_00000008 = (float)((int)in_stack_00000008 + 0x20);
      piVar10 = (int *)pfVar4[9];
      local_8 = local_8 + 1;
    } while (local_8 < *piVar10);
  }
  if (puVar12 != (uint *)0x0) {
    do {
      obj_impact_effects(obj,pfVar4,uVar13,uVar11,puVar12);
      uVar3 = *puVar12;
      puVar12 = puVar12 + 8;
    } while ((uVar3 & 0x4000) == 0);
  }
  return;
}

