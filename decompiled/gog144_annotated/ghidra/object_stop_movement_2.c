
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* PS2 candidate: object_stop_movement_3 (conf 0.565) */

void object_stop_movement_2(OBJECT *obj)

{
  int iVar1;
  dword *pdVar2;
  
  pdVar2 = &obj->pad_190;
  for (iVar1 = 0x1e; iVar1 != 0; iVar1 = iVar1 + -1) {
    *pdVar2 = 0;
    pdVar2 = pdVar2 + 1;
  }
  *(undefined4 *)&obj->field_0x1a0 = 0x42000000;
  obj->pad_1AC = 0x42000000;
  *(undefined4 *)&obj->field_0x1b8 = 0x42000000;
  *(undefined4 *)&obj->field_0x1bc = 0x42c80000;
  *(undefined4 *)&obj->field_0x19c = 0x3f800000;
  *(undefined4 *)&obj->field_0x1b0 = 0x3f800000;
  *(undefined4 *)&obj->field_0x198 = 0x3f800000;
  *(undefined4 *)&obj->field_0x1b4 = 0x3f800000;
  *(undefined4 *)&obj->field_0x1e8 = 0x3f800000;
  obj->pad_1E4 = 0x3f800000;
  *(undefined4 *)&obj->field_0x1ec = 0x3f800000;
  *(undefined4 *)&obj->field_0x1f0 = 0x41f00000;
  *(undefined4 *)&obj->field_0x200 = 0x42c80000;
  *(undefined4 *)&obj->field_0x1c0 = 0x42c80000;
  *(undefined4 *)&obj->field_0x1c4 = 100;
  return;
}

