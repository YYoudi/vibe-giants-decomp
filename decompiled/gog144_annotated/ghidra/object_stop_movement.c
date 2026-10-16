
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* PS2 candidate: object_stop_movement_2 (conf 0.881) */

void object_stop_movement(OBJECT *obj)

{
  obj->team_link = 0x3e800000;
  obj->class_ptr = 0x3e800000;
  obj->pad_14 = 0x3f000000;
  obj->anim = 0x3f000000;
  obj->type_id = 0x3f000000;
  obj->pad_0 = 0x3f000000;
  *(undefined4 *)&obj->field_0x24 = 0;
  *(undefined4 *)&obj->field_0x18 = 0;
  *(undefined4 *)&obj->field_0x1c = 0x3f800000;
  *(undefined4 *)&obj->field_0x20 = 0x3f800000;
  *(undefined4 *)&obj->field_0x28 = 0;
  *(undefined4 *)&obj->field_0x2c = 0x3f800000;
  *(undefined4 *)&obj->field_0x30 = 0xffff;
  return;
}

