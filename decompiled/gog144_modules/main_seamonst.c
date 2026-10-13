/* Giants 1.449 — module main/seamonst
 * 1 functions (1 named) — decompiled, names from PS2 symbols
 * Original source: C:\Giants\source\main/seamonst.c(pp) (assert-string evidence)
 */

/* ===== main_seamonst_004ec2c0 @ 0x004EC2C0 ===== */
void main_seamonst_004ec2c0(int param_1,undefined4 *param_2,undefined4 param_3)



{

  uint *puVar1;

  int iVar2;

  int iVar3;

  undefined4 *puVar4;

  float10 fVar5;

  float local_6c;

  float local_68;

  float local_64;

  float local_60;

  float local_5c;

  float local_58;

  undefined4 local_54;

  undefined4 local_50;

  undefined4 local_4c;

  undefined4 local_48;

  undefined4 local_44 [2];

  float local_3c;

  float local_2c;

  float local_1c;

  

  fVar5 = (float10)FUN_0050a400(param_1 + 0xa0,param_2);

  local_44[0] = 0;

  FUN_0053e460(local_44,-*(float *)(DAT_00632ed8 + 0x1558),0,(float)fVar5);

  playerobj_eval_refpt(param_1,0,&local_6c);

  local_60 = -(*(float *)(DAT_00632ed8 + 0x1554) * local_3c) + local_6c;

  local_5c = -(*(float *)(DAT_00632ed8 + 0x1554) * local_2c) + local_68;

  local_58 = -(*(float *)(DAT_00632ed8 + 0x1554) * local_1c) + local_64;

  iVar2 = FUN_004aa230(0x30,*(undefined4 *)(param_1 + 0x18c),param_1,0,0,&local_60);

  *(int *)(iVar2 + 0x274) = param_1;

  iVar3 = FUN_0052e480(param_1);

  if (iVar3 == 0) {

    *(undefined4 *)(iVar2 + 0x188) = param_3;

  }

  else {

    iVar3 = reaper_0052e4a0(param_1);

    if (iVar3 != 0) {

      local_54 = *param_2;

      local_50 = param_2[1];

      local_4c = param_2[2];

      local_48 = *(undefined4 *)(iVar2 + 0x188);

      reaper_00530bd0(param_1,3,1,0,1,&local_54);

    }

  }

  *(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) | 1;

  puVar1 = *(uint **)(iVar2 + 0x100);

  puVar4 = (undefined4 *)

           FUN_0053a700(0xd,0xc,s_SM_Custom_00561ba4,s_C__Giants_source_main_seamonst_c_00561bb0,

                        0x158);

  *puVar4 = *param_2;

  puVar4[1] = param_2[1];

  puVar4[2] = param_2[2];

  puVar1[7] = (uint)puVar4;

  *puVar1 = *puVar1 | 0x40;

  return;

}

