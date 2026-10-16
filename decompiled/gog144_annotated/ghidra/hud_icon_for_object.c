
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

undefined4 hud_icon_for_object(OBJECT *obj)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int in_stack_00000008;
  int in_stack_00000010;
  int in_stack_00000014;
  int in_stack_00000018;
  
  iVar6 = 0;
  iVar4 = 0;
  if (-1 < in_stack_00000008) {
    iVar5 = in_stack_00000008 * 0x310 + *(int *)&obj->field_0xa4;
    if (iVar5 != 0) {
      if (-1 < in_stack_00000014) {
        iVar6 = in_stack_00000014 * 0x874 + *(int *)&obj->field_0xa0;
        if ((((in_stack_00000018 != 0) && (*(int *)(iVar6 + 0x14) != 0)) &&
            (*(int *)(iVar6 + 0x1c) != 0xfe)) &&
           (iVar1 = *(int *)(*(int *)(*(int *)(iVar6 + 0x14) + 8 + *(int *)(iVar6 + 0x1c) * 4) +
                            0x28), iVar1 != 0)) {
          iVar4 = animGetIndexByName(iVar1,*(undefined4 *)(iVar6 + 4));
          if (iVar4 == 0) {
            map_scratch_clear(s_Flick_error___Can_t_find_fx_acto_005586c0);
          }
        }
      }
      *(int *)(iVar5 + 0x308) = iVar4;
      *(int *)(iVar5 + 0x304) = iVar6;
      *(int *)(iVar5 + 0x30c) = in_stack_00000010;
      objobj_type_lookup(0,iVar5);
      *(undefined4 *)(iVar5 + 0xc4) = 0x3f800000;
      if (*(int *)(iVar5 + 0x304) == 0) {
        GEO_MatIdentity(iVar5 + 0x294);
      }
      else {
        iVar6 = iVar5 + 0x294;
        wredit_matrix_recurse(iVar6,*(int *)(iVar5 + 0x304));
        if (*(int *)(iVar5 + 0x308) != 0) {
          uVar3 = AddHud__4cHudP8cHudIcon_4
                            (*(undefined4 *)(*(int *)(iVar5 + 0x308) + 0xc),
                             *(undefined4 *)(*(int *)(iVar5 + 0x304) + 0x20));
          piVar2 = *(int **)(iVar5 + 0x304);
          if (*piVar2 != 0) {
            piVar2[6] = *(int *)(*piVar2 + 4);
          }
          uVar3 = ANM_NodeGetMat(*(undefined4 *)(iVar5 + 0x308),uVar3,piVar2[6]);
          (*(code *)PTR_crt_matrix_mul_00580c18)(iVar6,iVar6,uVar3);
        }
      }
      object_set_location(iVar5,*(undefined4 *)(iVar5 + 0x2a4),*(undefined4 *)(iVar5 + 0x2b4),
                          *(undefined4 *)(iVar5 + 0x2c4));
      if (in_stack_00000010 != 0) {
        fx_get_free_effect__Fv();
        return 1;
      }
      fx_get_free_effect__Fv();
    }
  }
  return 1;
}

