
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* PS2 candidate: ObjectSetAnim (conf 0.75) */

void ObjectSetAnim(OBJECT *obj)

{
  float fVar1;
  int iVar2;
  dword *pdVar3;
  undefined4 *puVar4;
  dword *pdVar5;
  undefined4 *puVar6;
  dword in_stack_00000008;
  uint in_stack_0000000c;
  undefined4 in_stack_00000010;
  undefined4 in_stack_00000014;
  float in_stack_00000018;
  
  if (in_stack_00000008 == 0xfe) {
    crt_sprintf(&DAT_00657400,s_Object__d_setting_AnimIdxNONE__a_00554068,obj->type_id);
    error_msg_show(&DAT_00657400);
    return;
  }
  fVar1 = in_stack_00000018;
  if (DAT_00633118 == 0) {
    fVar1 = _DAT_005512a0;
  }
  if (fVar1 == _DAT_005512a0) {
    *(undefined4 *)&obj->field_0x28 = 0;
    *(undefined4 *)&obj->field_0x2c = 0;
  }
  else {
    if (*(float *)&obj->field_0x2c < _DAT_0055130c) {
      pdVar3 = &obj->anim;
      pdVar5 = (dword *)&obj->field_0x58;
      for (iVar2 = 9; iVar2 != 0; iVar2 = iVar2 + -1) {
        *pdVar5 = *pdVar3;
        pdVar3 = pdVar3 + 1;
        pdVar5 = pdVar5 + 1;
      }
      *(uint *)&obj->field_0x78 = *(uint *)&obj->field_0x78 | 0x100;
    }
    *(float *)&obj->field_0x28 = fVar1;
    *(undefined4 *)&obj->field_0x2c = 0x3f800000;
  }
  obj->anim = in_stack_00000008;
  *(uint *)&obj->field_0x30 = in_stack_0000000c | 0x100;
  *(undefined4 *)&obj->field_0x20 = in_stack_00000010;
  *(undefined4 *)&obj->field_0x24 = in_stack_00000014;
  if (DAT_00633118 == 0) {
    in_stack_00000018 = _DAT_005512a0;
  }
  if (in_stack_00000018 == _DAT_005512a0) {
    *(undefined4 *)&obj->field_0x4c = 0;
    *(undefined4 *)&obj->field_0x50 = 0;
  }
  else {
    if (*(float *)&obj->field_0x50 < _DAT_0055130c) {
      puVar4 = (undefined4 *)&obj->field_0x34;
      puVar6 = (undefined4 *)&obj->field_0x7c;
      for (iVar2 = 9; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar6 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar6 = puVar6 + 1;
      }
      *(uint *)&obj->field_0x9c = *(uint *)&obj->field_0x9c | 0x100;
    }
    *(float *)&obj->field_0x4c = in_stack_00000018;
    *(undefined4 *)&obj->field_0x50 = 0x3f800000;
  }
  *(undefined4 *)&obj->field_0x44 = in_stack_00000010;
  *(undefined4 *)&obj->field_0x34 = 0xfe;
  *(undefined4 *)&obj->field_0x54 = 0x100;
  *(undefined4 *)&obj->field_0x48 = in_stack_00000014;
  return;
}

