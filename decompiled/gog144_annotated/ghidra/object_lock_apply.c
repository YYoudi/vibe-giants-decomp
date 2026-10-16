
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void object_lock_apply(OBJECT *obj)

{
  OBJECT *obj_00;
  undefined4 *puVar1;
  uint uVar2;
  byte in_stack_00000008;
  
  uVar2 = 0;
  if ((in_stack_00000008 & 2) != 0) {
    uVar2 = 0x400;
  }
  puVar1 = DAT_00632d68;
  if ((in_stack_00000008 & 4) != 0) {
    uVar2 = uVar2 | 0x1000;
  }
  for (; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {
    obj_00 = (OBJECT *)puVar1[3];
    if (((obj_00->state == 0x4e) && ((obj_00->flags & 0xc000) == 0)) &&
       ((obj != (OBJECT *)0x0 || ((obj_00->pad_E4 & uVar2) != 0)))) {
      obj_00->flags = obj_00->flags & 0xffffffbf;
      obj_velocity_commit(obj_00);
      object_apply_location(obj_00);
      object_lock_logic(obj_00);
    }
  }
  return;
}

