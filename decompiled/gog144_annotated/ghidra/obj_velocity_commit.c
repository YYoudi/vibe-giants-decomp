
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void obj_velocity_commit(OBJECT *obj)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  bool bVar4;
  int local_8 [2];
  
  if ((obj != (OBJECT *)0x0) && ((obj->flags & 0xc000) == 0)) {
    if ((*(uint *)&obj->field_0x1c8 & 0x10) != 0) {
      local_8[0] = 0;
      local_8[1] = 0;
      bVar4 = true;
      iVar1 = 2;
      piVar2 = local_8;
      piVar3 = (int *)&obj->field_0x208;
      do {
        if (iVar1 == 0) break;
        iVar1 = iVar1 + -1;
        bVar4 = *piVar2 == *piVar3;
        piVar2 = piVar2 + 1;
        piVar3 = piVar3 + 1;
      } while (bVar4);
      if (bVar4) {
        return;
      }
      *(uint *)&obj->field_0x1c8 = *(uint *)&obj->field_0x1c8 & 0xffffffef;
    }
    obj->prev_vel1 = obj->vel1;
    obj->prev_vel2 = obj->vel2;
    obj->prev_vel_w = obj->vel_w;
    obj->prev_vel0 = obj->vel0;
    cspec_update_dispatch(obj);
  }
  return;
}

